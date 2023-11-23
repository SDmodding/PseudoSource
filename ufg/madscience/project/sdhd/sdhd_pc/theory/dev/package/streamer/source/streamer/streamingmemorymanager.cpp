// File Line: 49
// RVA: 0x146FA80
__int64 dynamic_initializer_for__gpc_Streaming_CPU_Pools_1__()
{
  UFG::qMemoryPool::qMemoryPool(&gpc_Streaming_CPU_Pools_1);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gpc_Streaming_CPU_Pools_1__);
}

// File Line: 50
// RVA: 0x146FAA0
__int64 dynamic_initializer_for__gpc_Streaming_CPU_Pools_2__()
{
  UFG::qMemoryPool::qMemoryPool(&gpc_Streaming_CPU_Pools_2);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gpc_Streaming_CPU_Pools_2__);
}

// File Line: 341
// RVA: 0x22A3B0
void __fastcall UFG::StreamingMemory::InitPcCPUPools(UFG::StreamingMemory *this)
{
  if ( UFG::gPageBasedStompDetector )
    UFG::qMemoryPool::EnablePageBasedStompDetection(&gpc_Streaming_CPU_Pools_1);
  UFG::qMemoryPool::Init(&gpc_Streaming_CPU_Pools_1, "StreamingCPUPools_1", 171966464ui64, 0, 0, 0, 0i64, 1, 1);
  if ( UFG::gPageBasedStompDetector )
    UFG::qMemoryPool::EnablePageBasedStompDetection(&gpc_Streaming_CPU_Pools_2);
  UFG::qMemoryPool::Init(&gpc_Streaming_CPU_Pools_2, "StreamingCPUPools_2", 130023424ui64, 0, 0, 0, 0i64, 1, 1);
}

// File Line: 361
// RVA: 0x229EE0
void __fastcall UFG::StreamingMemory::Init(UFG::StreamingMemory::InitParams *initParams)
{
  unsigned __int64 stdSectionElementSize; // r14
  unsigned __int64 lodcSectionElementSize; // r15
  unsigned __int64 zoneElementSize; // r12
  unsigned int terrainElementCount; // esi
  unsigned __int64 terrainElementSize; // rbp
  unsigned int globalLocationOverrideSize; // r9d
  unsigned __int64 v8; // r13
  signed __int64 locationMiscOverrideMemoryPoolSize; // rax
  signed __int64 v10; // rbx
  signed int v11; // ecx

  UFG::qMemSet(UFG::StreamingMemory::mVRAMDefs, 0, 0xD0u);
  UFG::qMemSet(UFG::StreamingMemory::mMainRAMDefs, 0, 0x44u);
  stdSectionElementSize = initParams->stdSectionElementSize;
  lodcSectionElementSize = initParams->lodcSectionElementSize;
  zoneElementSize = initParams->zoneElementSize;
  terrainElementCount = initParams->terrainElementCount;
  terrainElementSize = initParams->terrainElementSize;
  globalLocationOverrideSize = 5529600;
  if ( initParams->globalLocationOverrideSize )
    globalLocationOverrideSize = initParams->globalLocationOverrideSize;
  v8 = globalLocationOverrideSize;
  locationMiscOverrideMemoryPoolSize = initParams->locationMiscOverrideMemoryPoolSize;
  v10 = initParams->locationMemoryPoolSize
      - (unsigned __int64)(unsigned int)(2 * zoneElementSize)
      - 41 * initParams->lodcSectionElementSize
      - 7 * initParams->stdSectionElementSize
      - globalLocationOverrideSize;
  if ( (_DWORD)locationMiscOverrideMemoryPoolSize && locationMiscOverrideMemoryPoolSize <= v10 )
    v10 = initParams->locationMiscOverrideMemoryPoolSize;
  dword_14236FB64 = initParams->zoneElementSize;
  dword_14236FB68 = stdSectionElementSize;
  dword_14236FB6C = lodcSectionElementSize;
  dword_14236FB70 = globalLocationOverrideSize;
  qword_14236FB9C = 1024i64;
  UFG::StreamingMemory::mMainRAMDefs[0].mBlockSize = 0;
  dword_14236FB74 = 0;
  dword_14236FB98 = 0;
  qword_14236FB8C = 0i64;
  dword_14236FB88 = 0;
  dword_14236FB94 = terrainElementSize;
  initParams->streamedMemoryPoolSize += 0x180000;
  initParams->turfMemoryPoolSize += 0x180000;
  UFG::qMemoryPool::GetTotalFreeBytes(&gpc_Streaming_CPU_Pools_1);
  UFG::qMemoryPool::GetTotalFreeBytes(&gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(0u, v10, 0x1000u, 1, "LocMisc", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(2u, stdSectionElementSize, 7u, 0x1000u, 0, "LocSTD", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(3u, lodcSectionElementSize, 41u, 0x1000u, 0, "LocLODC", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(1u, zoneElementSize, 2u, 0x1000u, 0, "LocRegion", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(4u, v8, 0x1000u, 0, "LocGlobal", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(
    5u,
    initParams->animationMemoryPoolSize,
    0x1000u,
    1,
    "Animation",
    &gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(
    14u,
    initParams->streamedMemoryPoolSize,
    0x1000u,
    1,
    "Streamed",
    &gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(
    15u,
    initParams->streamedTextureHeaderPoolSize,
    0x400u,
    1,
    "Streamed_TexHeader",
    &gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(6u, initParams->uiMemoryPoolSize, 0x1000u, 1, "UI", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(
    7u,
    initParams->localizationMemoryPoolSize,
    0x1000u,
    1,
    "Local",
    &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(
    8u,
    initParams->globalGameplayPoolSize,
    0x1000u,
    0,
    "GlobalGameplay",
    &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(
    9u,
    initParams->cellGameplayPoolSize,
    7u,
    0x1000u,
    0,
    "CellRegion",
    &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(0xAu, 0x4000ui64, 0x1000u, 0, "Clouds", &gpc_Streaming_CPU_Pools_2);
  if ( (_DWORD)terrainElementSize && terrainElementCount )
    UFG::StreamPool_CreatePool(
      13u,
      terrainElementSize,
      terrainElementCount,
      0x1000u,
      0,
      "Terrain",
      &gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(16u, initParams->turfMemoryPoolSize, 0x1000u, 1, "Turf", &gpc_Streaming_CPU_Pools_2);
  *(_BYTE *)(qword_14236FBF8 + 50) = 0;
  *(_DWORD *)(qword_14236FBF8 + 24) = 0x80000;
  *(_DWORD *)(qword_14236FBF8 + 28) = 200704;
  *(_DWORD *)(qword_14236FC40 + 24) = 1572864;
  *(_DWORD *)(qword_14236FC40 + 28) = 0x40000;
  *(_DWORD *)(qword_14236FC50 + 24) = 1572864;
  *(_DWORD *)(qword_14236FC50 + 28) = 0x40000;
  v11 = initParams->terrainElementCount * initParams->terrainVRAMElementSize;
  UFG::StreamingMemory::mVRAMDefs[0].mVRAMPool = UFG::gMainVRAMemoryPool;
  dword_14236FA98 = 0;
  qword_14236FAF0 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FAF8 = 0;
  qword_14236FAA0 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FAA8 = 0;
  qword_14236FAE0 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FAE8 = 0;
  qword_14236FAC0 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FAC8 = 0;
  qword_14236FAD0 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FAD8 = 0;
  qword_14236FAB0 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FAB8 = 0;
  qword_14236FB40 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FB48 = 0;
  qword_14236FB00 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FB08 = 0;
  qword_14236FB10 = (__int64)UFG::gMainVRAMemoryPool;
  dword_14236FB18 = 0;
  if ( initParams->turfTexturePoolSize )
  {
    qword_14236FB50 = (__int64)UFG::gMainVRAMemoryPool;
    dword_14236FB58 = 0;
  }
  if ( v11 > 0 )
  {
    qword_14236FB30 = (__int64)UFG::gMainVRAMemoryPool;
    dword_14236FB38 = 0;
  }
}

// File Line: 662
// RVA: 0x227C90
char __fastcall UFG::StreamingMemory::Allocate(
        UFG::StreamingMemory::DATA_TYPE eDataType,
        __int16 streamPoolFlags_MainMemory,
        unsigned int mainRAMSize_Alloc,
        unsigned int mainRAMSize_Data,
        unsigned int VRAMsize,
        unsigned __int64 *phMainRAM,
        UFG::qVRAMemoryHandle *phVRAM,
        const char *name,
        const char *tag_name,
        unsigned int *CPURAMRestoredSizeBytes,
        unsigned int *VRAMRestoredSizeBytes,
        unsigned int *paddedSizeAllocatedMainRAM,
        unsigned int *paddedSizeAllocatedVRAM,
        unsigned int *error_flags)
{
  __int64 mStreamPoolIndex; // rdx
  UFG::qVRAMemoryPool *mVRAMPool; // r15
  unsigned int mBlockSize; // esi
  unsigned int v18; // edi
  unsigned __int16 flags; // dx
  UFG::StreamPool *v20; // rcx
  unsigned __int64 user_data_64; // rbp
  char v22; // bl
  UFG::qVRAMemoryHandle handle; // [rsp+58h] [rbp-40h] BYREF

  if ( error_flags )
    *error_flags = 0;
  mStreamPoolIndex = UFG::StreamingMemory::dataTypeDefs[eDataType].mStreamPoolIndex;
  mVRAMPool = 0i64;
  mBlockSize = 0;
  v18 = VRAMsize;
  if ( VRAMsize )
  {
    mVRAMPool = UFG::StreamingMemory::mVRAMDefs[dword_1420432B4[2 * eDataType]].mVRAMPool;
    mBlockSize = UFG::StreamingMemory::mVRAMDefs[dword_1420432B4[2 * eDataType]].mBlockSize;
  }
  if ( UFG::StreamingMemory::smbFinalBandwidthEmu )
  {
    if ( paddedSizeAllocatedMainRAM )
      *paddedSizeAllocatedMainRAM = UFG::StreamingMemory::mMainRAMDefs[mStreamPoolIndex].mBlockSize;
    if ( paddedSizeAllocatedVRAM )
      *paddedSizeAllocatedVRAM = mBlockSize;
  }
  flags = streamPoolFlags_MainMemory | mStreamPoolIndex & 0x1F;
  v20 = UFG::gStreamPools[flags & 0x1F];
  if ( !v20
    || (user_data_64 = UFG::StreamPool::Allocate(
                         v20,
                         mainRAMSize_Alloc,
                         mainRAMSize_Data,
                         name,
                         tag_name,
                         flags,
                         CPURAMRestoredSizeBytes),
        user_data_64 == -1i64) )
  {
    if ( error_flags )
      *error_flags |= 1u;
    *phMainRAM = -1i64;
    UFG::qVRAMemoryHandle::Close(phVRAM);
    return 0;
  }
  else
  {
    UFG::qVRAMemoryHandle::qVRAMemoryHandle(&handle);
    if ( !VRAMsize )
      goto LABEL_19;
    if ( mBlockSize )
      v18 = mBlockSize * ((mBlockSize + VRAMsize - 1) / mBlockSize);
    UFG::qVRAMemoryPool::Allocate(
      mVRAMPool,
      &handle,
      v18,
      0xAu,
      name,
      UFG::VRAMInterface::TEXTURE_ALIGNMENT,
      0xDu,
      0i64,
      user_data_64,
      0);
    if ( handle.mData )
    {
LABEL_19:
      UFG::qVRAMemoryHandle::operator=(phVRAM, &handle);
      *phMainRAM = user_data_64;
      v22 = 1;
    }
    else
    {
      if ( error_flags )
        *error_flags |= 2u;
      UFG::StreamPool_FreeNoCache(user_data_64);
      *phMainRAM = -1i64;
      UFG::qVRAMemoryHandle::Close(phVRAM);
      v22 = 0;
    }
    UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&handle);
    return v22;
  }
}

