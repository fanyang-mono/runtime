// Generated by Fuzzlyn v1.5 on 2023-02-24 23:07:39
// Run on X86 Windows
// Seed: 10843127860637099968
// Reduced from 209.2 KiB to 0.3 KiB in 00:04:55
// Hits JIT assert in Release:
// Assertion failed '!op1->IsRegOptional() && !op2->IsRegOptional()' in 'Program:Main(Fuzzlyn.ExecutionServer.IRuntime)' during 'Lowering nodeinfo' (IL size 45; hash 0xade6b36b; FullOpts)
// 
//     File: D:\a\_work\1\s\src\coreclr\jit\lowerxarch.cpp Line: 5118
// 
using Xunit;
public class Program
{
    public static bool s_26;
    [Fact]
    public static int TestEntryPoint()
    {
        var vr2 = new uint[,] { { 0 } };
        int vr7 = default(int);
        uint vr5 = (uint)vr7;
        if (s_26)
        {
            vr5 = 1;
        }

        vr2[0, 0] = (uint)(vr5 & (sbyte)~(vr2[0, 0] % 1));
        return 100;
    }
}