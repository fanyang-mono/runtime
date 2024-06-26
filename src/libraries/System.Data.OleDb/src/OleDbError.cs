// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System.Data.Common;
using System.Runtime.InteropServices;

namespace System.Data.OleDb
{
    public sealed class OleDbError
    {
        private readonly string? message;
        private readonly string? source;
        private readonly string? sqlState;
        private readonly int nativeError;

        internal OleDbError(UnsafeNativeMethods.IErrorRecords errorRecords, int index)
        {
            OleDbHResult hr;
            int lcid = System.Globalization.CultureInfo.CurrentCulture.LCID;
            UnsafeNativeMethods.IErrorInfo errorInfo = errorRecords.GetErrorInfo(index, lcid);
            if (null != errorInfo)
            {
                hr = errorInfo.GetDescription(out this.message);

                if (OleDbHResult.DB_E_NOLOCALE == hr)
                {
                    Marshal.ReleaseComObject(errorInfo);
                    lcid = Interop.Kernel32.GetUserDefaultLCID();
                    errorInfo = errorRecords.GetErrorInfo(index, lcid);

                    if (null != errorInfo)
                    {
                        hr = errorInfo.GetDescription(out this.message);
                    }
                }
                if ((hr < 0) && ADP.IsEmpty(this.message))
                {
                    this.message = ODB.FailedGetDescription(hr);
                }
                if (null != errorInfo)
                {
                    hr = errorInfo.GetSource(out this.source);

                    if (OleDbHResult.DB_E_NOLOCALE == hr)
                    {
                        Marshal.ReleaseComObject(errorInfo);
                        lcid = Interop.Kernel32.GetUserDefaultLCID();
                        errorInfo = errorRecords.GetErrorInfo(index, lcid);

                        if (null != errorInfo)
                        {
                            hr = errorInfo.GetSource(out this.source);
                        }
                    }
                    if ((hr < 0) && ADP.IsEmpty(this.source))
                    {
                        this.source = ODB.FailedGetSource(hr);
                    }
                    Marshal.ReleaseComObject(errorInfo!);
                }
            }

            UnsafeNativeMethods.ISQLErrorInfo sqlErrorInfo;
            errorRecords.GetCustomErrorObject(index, in ODB.IID_ISQLErrorInfo, out sqlErrorInfo);

            if (null != sqlErrorInfo)
            {
                this.nativeError = sqlErrorInfo.GetSQLInfo(out this.sqlState);
                Marshal.ReleaseComObject(sqlErrorInfo);
            }
        }

        public string Message
        {
            get
            {
                return this.message ?? string.Empty;
            }
        }

        public int NativeError
        {
            get
            {
                return this.nativeError;
            }
        }

        public string Source
        {
            get
            {
                return this.source ?? string.Empty;
            }
        }

        public string SQLState
        {
            get
            {
                return this.sqlState ?? string.Empty;
            }
        }

        public override string ToString()
        {
            return Message;
        }
    }
}
