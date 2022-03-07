// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System.Runtime.InteropServices;

internal static partial class Interop
{
    internal static partial class Kernel32
    {
        [GeneratedDllImport(Libraries.Kernel32, EntryPoint = "ExpandEnvironmentStringsW", SetLastError = true, StringMarshalling = StringMarshalling.Utf16)]
        internal static partial uint ExpandEnvironmentStrings(string lpSrc, ref char lpDst, uint nSize);
    }
}
