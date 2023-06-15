// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

/******************************************************************

DO NOT MODIFY. AUTOGENERATED FILE.
This file is generated using the logic from <root>/src/scripts/genEventPipe.py

******************************************************************/

#include <common.h>
#include "eventpipeadapter.h"
#include "gcheaputilities.h"

#ifndef ERROR_WRITE_FAULT
#define ERROR_WRITE_FAULT 29L
#endif

ULONG EventPipeWriteEventDestroyGCHandle(
    const void*  HandleID,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId)
{
    return 0;
}

ULONG EventPipeWriteEventExceptionThrown_V1(
    const WCHAR* ExceptionType,
    const WCHAR* ExceptionMessage,
    const void*  ExceptionEIP,
    const unsigned int  ExceptionHRESULT,
    const unsigned short  ExceptionFlags,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCAllocationTick_V1(
    const unsigned int  AllocationAmount,
    const unsigned int  AllocationKind,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}


ULONG EventPipeWriteEventGCAllocationTick_V2(
    const unsigned int  AllocationAmount,
    const unsigned int  AllocationKind,
    const unsigned short  ClrInstanceID,
    const unsigned __int64  AllocationAmount64,
    const void*  TypeID,
    const WCHAR*  TypeName,
    const unsigned int  HeapIndex,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCAllocationTick_V3(
    const unsigned int  AllocationAmount,
    const unsigned int  AllocationKind,
    const unsigned short  ClrInstanceID,
    const unsigned __int64  AllocationAmount64,
    const void*  TypeID,
    const WCHAR*  TypeName,
    const unsigned int  HeapIndex,
    const void*  Address,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCBulkEdge(
    const unsigned int  Index,
    const unsigned int  Count,
    const unsigned short  ClrInstanceID,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCBulkMovedObjectRanges(
    const unsigned int  Index,
    const unsigned int  Count,
    const unsigned short  ClrInstanceID,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCBulkNode(
    const unsigned int  Index,
    const unsigned int  Count,
    const unsigned short  ClrInstanceID,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCBulkRCW(
    const unsigned int  Count,
    const unsigned short  ClrInstanceID,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCBulkRootCCW(
    const unsigned int  Count,
    const unsigned short  ClrInstanceID,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCBulkRootConditionalWeakTableElementEdge(
    const unsigned int  Index,
    const unsigned int  Count,
    const unsigned short  ClrInstanceID,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCBulkRootEdge(
    const unsigned int  Index,
    const unsigned int  Count,
    const unsigned short  ClrInstanceID,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCBulkSurvivingObjectRanges(
    const unsigned int  Index,
    const unsigned int  Count,
    const unsigned short  ClrInstanceID,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCCreateConcurrentThread_V1(
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCCreateSegment_V1(
    const unsigned __int64  Address,
    const unsigned __int64  Size,
    const unsigned int  Type,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCEnd_V1(
    const unsigned int  Count,
    const unsigned int  Depth,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCFreeSegment_V1(
    const unsigned __int64  Address,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCGenerationRange(
    const unsigned char  Generation,
    const void*  RangeStart,
    const unsigned __int64  RangeUsedLength,
    const unsigned __int64  RangeReservedLength,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCGlobalHeapHistory_V2(
    const unsigned __int64  FinalYoungestDesired,
    const signed int  NumHeaps,
    const unsigned int  CondemnedGeneration,
    const unsigned int  Gen0ReductionCount,
    const unsigned int  Reason,
    const unsigned int  GlobalMechanisms,
    const unsigned short  ClrInstanceID,
    const unsigned int  PauseMode,
    const unsigned int  MemoryPressure,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCHeapStats_V1(
    const unsigned __int64  GenerationSize0,
    const unsigned __int64  TotalPromotedSize0,
    const unsigned __int64  GenerationSize1,
    const unsigned __int64  TotalPromotedSize1,
    const unsigned __int64  GenerationSize2,
    const unsigned __int64  TotalPromotedSize2,
    const unsigned __int64  GenerationSize3,
    const unsigned __int64  TotalPromotedSize3,
    const unsigned __int64  FinalizationPromotedSize,
    const unsigned __int64  FinalizationPromotedCount,
    const unsigned int  PinnedObjectCount,
    const unsigned int  SinkBlockCount,
    const unsigned int  GCHandleCount,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCJoin_V2(
    const unsigned int  Heap,
    const unsigned int  JoinTime,
    const unsigned int  JoinType,
    const unsigned short  ClrInstanceID,
    const unsigned int  JoinID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCMarkFinalizeQueueRoots(
    const unsigned int  HeapNum,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCMarkHandles(
    const unsigned int  HeapNum,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCMarkOlderGenerationRoots(
    const unsigned int  HeapNum,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCMarkStackRoots(
    const unsigned int  HeapNum,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCMarkWithType(
    const unsigned int  HeapNum,
    const unsigned short  ClrInstanceID,
    const unsigned int  Type,
    const unsigned __int64  Bytes,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCPerHeapHistory_V3(
    const unsigned short  ClrInstanceID,
    const void*  FreeListAllocated,
    const void*  FreeListRejected,
    const void*  EndOfSegAllocated,
    const void*  CondemnedAllocated,
    const void*  PinnedAllocated,
    const void*  PinnedAllocatedAdvance,
    const unsigned int  RunningFreeListEfficiency,
    const unsigned int  CondemnReasons0,
    const unsigned int  CondemnReasons1,
    const unsigned int  CompactMechanisms,
    const unsigned int  ExpandMechanisms,
    const unsigned int  HeapIndex,
    const void*  ExtraGen0Commit,
    const unsigned int  Count,
    int Values_ElementSize,
    const void* Values,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCTerminateConcurrentThread_V1(
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCTriggered(
    const unsigned int  Reason,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventModuleLoad_V2(
    const unsigned __int64  ModuleID,
    const unsigned __int64  AssemblyID,
    const unsigned int  ModuleFlags,
    const unsigned int  Reserved1,
    const WCHAR*  ModuleILPath,
    const WCHAR*  ModuleNativePath,
    const unsigned short  ClrInstanceID,
    const GUID* ManagedPdbSignature,
    const unsigned int  ManagedPdbAge,
    const WCHAR*  ManagedPdbBuildPath,
    const GUID* NativePdbSignature,
    const unsigned int  NativePdbAge,
    const WCHAR*  NativePdbBuildPath,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventSetGCHandle(
    const void*  HandleID,
    const void*  ObjectID,
    const unsigned int  Kind,
    const unsigned int  Generation,
    const unsigned __int64  AppDomainID,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCStart_V1(
    const unsigned int  Count,
    const unsigned int  Depth,
    const unsigned int  Reason,
    const unsigned int  Type,
    const unsigned short  ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId
)
{
    return 0;
}

ULONG EventPipeWriteEventGCStart_V2(
    const unsigned int Count,
    const unsigned int Depth,
    const unsigned int Reason,
    const unsigned int Type,
    const unsigned short ClrInstanceID,
    const unsigned __int64 ClientSequenceNumber,
    const GUID * ActivityId,
    const GUID * RelatedActivityId)
{
    return 0;
}

ULONG EventPipeWriteEventGCSuspendEEBegin_V1(
    const unsigned int Reason,
    const unsigned int Count,
    const unsigned short ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId)
{
    return 0;
}

ULONG EventPipeWriteEventGCSuspendEEEnd_V1(
    const unsigned short ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId)
{
    return 0;
}

ULONG EventPipeWriteEventGCRestartEEBegin_V1(
    const unsigned short ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId)
{
    return 0;
}

ULONG EventPipeWriteEventGCRestartEEEnd_V1(
    const unsigned short ClrInstanceID,
    const GUID * ActivityId,
    const GUID * RelatedActivityId)
{
    return 0;
}
