// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System.Runtime.InteropServices;

internal static partial class Interop
{
    internal static partial class Advapi32
    {
        [StructLayout(LayoutKind.Sequential)]
        internal struct TRUSTED_POSIX_OFFSET_INFO
        {
            internal int Offset;
        }
    }
}
