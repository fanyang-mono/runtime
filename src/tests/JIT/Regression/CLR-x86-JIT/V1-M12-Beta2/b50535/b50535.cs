// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
//

using Xunit;
namespace Test
{
    using System;
    using System.Collections;

    public class App
    {
        [Fact]
        public static int TestEntryPoint()
        {
            "hello".CompareTo(null);
            return 100;
        }
    }
}
