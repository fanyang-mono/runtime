// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;
using Internal.Cryptography;

namespace System.Security.Cryptography
{
    //
    // This class provides the common functionality for HMACSHA1, HMACSHA256, HMACMD5, etc.
    // Ideally, this would be encapsulated in a common base class but the preexisting contract
    // locks these public classes into deriving directly from HMAC so we have to use encapsulation
    // and delegation to HMACCommon instead.
    //
    // This wrapper adds the ability to change the Key on the fly for compat with the desktop.
    //
    internal sealed class HMACCommon
    {
        public HMACCommon(string hashAlgorithmId, byte[] key, int blockSize) :
            this(hashAlgorithmId, (ReadOnlySpan<byte>)key, blockSize)
        {
            // If the key is smaller than the block size, the delegated ctor won't have initialized ActualKey,
            // so set it here as would ChangeKey.
            ActualKey ??= key;
        }

        internal HMACCommon(string hashAlgorithmId, ReadOnlySpan<byte> key, int blockSize)
        {
            Debug.Assert(!string.IsNullOrEmpty(hashAlgorithmId));
            Debug.Assert(blockSize > 0 || blockSize == -1);

            _hashAlgorithmId = hashAlgorithmId;
            _blockSize = blockSize;

            // note: will not set ActualKey if key size is smaller or equal than blockSize
            //       this is to avoid extra allocation. ActualKey can still be used if key is generated.
            //       Otherwise the ReadOnlySpan overload would actually be slower than byte array overload.
            ActualKey = ChangeKeyImpl(key);
        }

        private HMACCommon(string hashAlgorithmId, HashProvider hmacProvider, int blockSize, byte[]? actualKey)
        {
            Debug.Assert(!string.IsNullOrEmpty(hashAlgorithmId));
            Debug.Assert(blockSize is > 0 or -1);

            _hashAlgorithmId = hashAlgorithmId;
            _hMacProvider = hmacProvider;
            _blockSize = blockSize;
            ActualKey = Helpers.CloneByteArray(actualKey);
        }

        public int HashSizeInBits => _hMacProvider.HashSizeInBytes * 8;
        public int HashSizeInBytes => _hMacProvider.HashSizeInBytes;

        public void ChangeKey(byte[] key)
        {
            ActualKey = ChangeKeyImpl(key) ?? key;
        }

        [MemberNotNull(nameof(_hMacProvider))]
        private byte[]? ChangeKeyImpl(ReadOnlySpan<byte> key)
        {
            byte[]? modifiedKey = null;

            // If _blockSize is -1 the key isn't going to be extractable by the object holder,
            // so there's no point in recalculating it in managed code.
            if (key.Length > _blockSize && _blockSize > 0)
            {
                // Perform RFC 2104, section 2 key adjustment.
                switch (_hashAlgorithmId)
                {
                    case HashAlgorithmNames.SHA256:
                        modifiedKey = SHA256.HashData(key);
                        break;
                    case HashAlgorithmNames.SHA384:
                        modifiedKey = SHA384.HashData(key);
                        break;
                    case HashAlgorithmNames.SHA512:
                        modifiedKey = SHA512.HashData(key);
                        break;
                    case HashAlgorithmNames.SHA3_256:
                        Debug.Assert(SHA3_256.IsSupported);
                        modifiedKey = SHA3_256.HashData(key);
                        break;
                    case HashAlgorithmNames.SHA3_384:
                        Debug.Assert(SHA3_384.IsSupported);
                        modifiedKey = SHA3_384.HashData(key);
                        break;
                    case HashAlgorithmNames.SHA3_512:
                        Debug.Assert(SHA3_512.IsSupported);
                        modifiedKey = SHA3_512.HashData(key);
                        break;
                    case HashAlgorithmNames.SHA1:
                        modifiedKey = SHA1.HashData(key);
                        break;
                    case HashAlgorithmNames.MD5 when Helpers.HasMD5:
                        modifiedKey = MD5.HashData(key);
                        break;
                    default:
                        throw new CryptographicException(SR.Format(SR.Cryptography_UnknownHashAlgorithm, _hashAlgorithmId));
                };
            }

            HashProvider? oldHashProvider = _hMacProvider;
            _hMacProvider = null!;
            oldHashProvider?.Dispose(true);
            _hMacProvider = HashProviderDispenser.CreateMacProvider(_hashAlgorithmId, key);

            return modifiedKey;
        }

        // The actual key used for hashing. This will not be the same as the original key passed to ChangeKey() if the original key exceeded the
        // hash algorithm's block size. (See RFC 2104, section 2)
        public byte[]? ActualKey { get; private set; }

        // Adds new data to be hashed. This can be called repeatedly in order to hash data from noncontiguous sources.
        public void AppendHashData(byte[] data, int offset, int count) =>
            _hMacProvider.AppendHashData(data, offset, count);

        public void AppendHashData(ReadOnlySpan<byte> source) =>
            _hMacProvider.AppendHashData(source);

        // Compute the hash based on the appended data and resets the HashProvider for more hashing.
        public byte[] FinalizeHashAndReset() =>
            _hMacProvider.FinalizeHashAndReset();

        public int FinalizeHashAndReset(Span<byte> destination) =>
            _hMacProvider.FinalizeHashAndReset(destination);

        public bool TryFinalizeHashAndReset(Span<byte> destination, out int bytesWritten) =>
            _hMacProvider.TryFinalizeHashAndReset(destination, out bytesWritten);

        public int GetCurrentHash(Span<byte> destination) =>
            _hMacProvider.GetCurrentHash(destination);

        public void Reset() => _hMacProvider.Reset();

        public HMACCommon Clone()
        {
            return new HMACCommon(_hashAlgorithmId, _hMacProvider.Clone(), _blockSize, ActualKey);
        }

        public void Dispose(bool disposing)
        {
            if (disposing)
            {
                _hMacProvider?.Dispose(true);
                _hMacProvider = null!;
            }
        }

        private readonly string _hashAlgorithmId;
        private HashProvider _hMacProvider;
        private readonly int _blockSize;
    }
}
