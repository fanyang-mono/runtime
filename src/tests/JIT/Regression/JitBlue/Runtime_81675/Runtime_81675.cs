// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using Xunit;
// Generated by Fuzzlyn v1.5 on 2023-02-06 00:41:34
// Run on X86 Windows
// Seed: 12611629827253727687
// Reduced from 444.9 KiB to 1.1 KiB in 00:13:23
// Hits JIT assert in Release:
// Assertion failed '!"Jump into the middle of handler region"' in 'Program:Main(Fuzzlyn.ExecutionServer.IRuntime)' during 'Unroll loops' (IL size 131; hash 0xade6b36b; FullOpts)
// 
//     File: D:\a\_work\1\s\src\coreclr\jit\fgdiagnostic.cpp Line: 2609
// 
public interface I0
{
}

public class C0 : I0
{
    public sbyte F3;
}

public class Runtime_81675
{
    public static ushort s_11;
    public static bool[][] s_18;
    public static C0 s_26;
    public static short[] s_42;
    [Fact]
    public static void TestEntryPoint()
    {
        short vr7 = default(short);
        for (int vr8 = 0; vr8 < 0; vr8++)
        {
            try
            {
                System.Console.WriteLine(32767);
            }
            finally
            {
                I0 vr9 = new C0();
            }
        }

        for (int vr10 = 0; vr10 < 0; vr10++)
        {
            if (s_18[0][0])
            {
                var vr11 = s_26.F3;
            }
            else
            {
                System.Console.WriteLine(0);
            }

            if (!((ushort)(-s_11++) >= 0))
            {
                vr7 = vr7;
                try
                {
                    vr7 = 0;
                }
                finally
                {
                    vr7 = s_42[0];
                }
            }
        }
    }
}
