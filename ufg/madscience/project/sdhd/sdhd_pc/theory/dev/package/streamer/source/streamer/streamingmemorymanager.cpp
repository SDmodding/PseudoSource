// File Line: 49
// RVA: 0x146FA80
__int64 dynamic_initializer_for__gpc_Streaming_CPU_Pools_1__()
{
  UFG::qMemoryPool::qMemoryPool(&gpc_Streaming_CPU_Pools_1);
  return atexit(dynamic_atexit_destructor_for__gpc_Streaming_CPU_Pools_1__);
}

// File Line: 50
// RVA: 0x146FAA0
__int64 dynamic_initializer_for__gpc_Streaming_CPU_Pools_2__()
{
  UFG::qMemoryPool::qMemoryPool(&gpc_Streaming_CPU_Pools_2);
  return atexit(dynamic_atexit_destructor_for__gpc_Streaming_CPU_Pools_2__);
}

// File Line: 341
// RVA: 0x22A3B0
void __fastcall UFG::StreamingMemory::InitPcCPUPools(UFG::StreamingMemory *this)
{
  if ( UFG::gPageBasedStompDetector )
    UFG::qMemoryPool::EnablePageBasedStompDetection(&gpc_Streaming_CPU_Pools_1);
  UFG::qMemoryPool::Init(&gpc_Streaming_CPU_Pools_1, "StreamingCPUPools_1", 171966464i64, 0, 0, 0, 0i64, 1, 1);
  if ( UFG::gPageBasedStompDetector )
    UFG::qMemoryPool::EnablePageBasedStompDetection(&gpc_Streaming_CPU_Pools_2);
  UFG::qMemoryPool::Init(&gpc_Streaming_CPU_Pools_2, "StreamingCPUPools_2", 130023424i64, 0, 0, 0, 0i64, 1, 1);
}

// File Line: 361
// RVA: 0x229EE0
void __fastcall UFG::StreamingMemory::Init(UFG::StreamingMemory::InitParams *initParams)
{
  UFG::StreamingMemory::InitParams *v1; // rdi
  unsigned __int64 v2; // r14
  unsigned __int64 v3; // r15
  unsigned __int64 v4; // r12
  unsigned int v5; // esi
  unsigned __int64 v6; // rbp
  unsigned int v7; // er9
  unsigned __int64 v8; // r13
  signed __int64 v9; // rax
  signed __int64 v10; // rbx
  int v11; // ecx

  v1 = initParams;
  UFG::qMemSet(UFG::StreamingMemory::mVRAMDefs, 0, 0xD0u);
  UFG::qMemSet(UFG::StreamingMemory::mMainRAMDefs, 0, 0x44u);
  v2 = v1->stdSectionElementSize;
  v3 = v1->lodcSectionElementSize;
  v4 = v1->zoneElementSize;
  v5 = v1->terrainElementCount;
  v6 = v1->terrainElementSize;
  v7 = 5529600;
  if ( v1->globalLocationOverrideSize )
    v7 = v1->globalLocationOverrideSize;
  v8 = v7;
  v9 = v1->locationMiscOverrideMemoryPoolSize;
  v10 = v1->locationMemoryPoolSize
      - (unsigned __int64)(unsigned int)(2 * v4)
      - 41 * v1->lodcSectionElementSize
      - 7 * v1->stdSectionElementSize
      - v7;
  if ( (_DWORD)v9 && v9 <= v10 )
    v10 = v1->locationMiscOverrideMemoryPoolSize;
  dword_14236FB64 = v1->zoneElementSize;
  dword_14236FB68 = v2;
  dword_14236FB6C = v3;
  dword_14236FB70 = v7;
  qword_14236FB9C = 1024i64;
  UFG::StreamingMemory::mMainRAMDefs[0].mBlockSize = 0;
  dword_14236FB74 = 0;
  dword_14236FB98 = 0;
  qword_14236FB8C = 0i64;
  dword_14236FB88 = 0;
  dword_14236FB94 = v6;
  v1->streamedMemoryPoolSize += 0x180000;
  v1->turfMemoryPoolSize += 0x180000;
  UFG::qMemoryPool::GetTotalFreeBytes(&gpc_Streaming_CPU_Pools_1);
  UFG::qMemoryPool::GetTotalFreeBytes(&gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(0u, v10, 0x1000u, 1, "LocMisc", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(2u, v2, 7u, 0x1000u, 0, "LocSTD", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(3u, v3, 41u, 0x1000u, 0, "LocLODC", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(1u, v4, 2u, 0x1000u, 0, "LocRegion", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(4u, v8, 0x1000u, 0, "LocGlobal", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(5u, v1->animationMemoryPoolSize, 0x1000u, 1, "Animation", &gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(14u, v1->streamedMemoryPoolSize, 0x1000u, 1, "Streamed", &gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(
    15u,
    v1->streamedTextureHeaderPoolSize,
    0x400u,
    1,
    "Streamed_TexHeader",
    &gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(6u, v1->uiMemoryPoolSize, 0x1000u, 1, "UI", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(7u, v1->localizationMemoryPoolSize, 0x1000u, 1, "Local", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(8u, v1->globalGameplayPoolSize, 0x1000u, 0, "GlobalGameplay", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(9u, v1->cellGameplayPoolSize, 7u, 0x1000u, 0, "CellRegion", &gpc_Streaming_CPU_Pools_1);
  UFG::StreamPool_CreatePool(10u, 0x4000ui64, 0x1000u, 0, "Clouds", &gpc_Streaming_CPU_Pools_2);
  if ( (_DWORD)v6 && v5 )
    UFG::StreamPool_CreatePool(13u, v6, v5, 0x1000u, 0, "Terrain", &gpc_Streaming_CPU_Pools_2);
  UFG::StreamPool_CreatePool(16u, v1->turfMemoryPoolSize, 0x1000u, 1, "Turf", &gpc_Streaming_CPU_Pools_2);
  *(_BYTE *)(qword_14236FBF8 + 50) = 0;
  *(_DWORD *)(qword_14236FBF8 + 24) = 0x80000;
  *(_DWORD *)(qword_14236FBF8 + 28) = 200704;
  *(_DWORD *)(qword_14236FC40 + 24) = 1572864;
  *(_DWORD *)(qword_14236FC40 + 28) = 0x40000;
  *(_DWORD *)(qword_14236FC50 + 24) = 1572864;
  *(_DWORD *)(qword_14236FC50 + 28) = 0x40000;
  v11 = v1->terrainElementCount * v1->terrainVRAMElementSize;
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
  if ( v1->turfTexturePoolSize )
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
char __fastcall UFG::StreamingMemory::Allocate(UFG::StreamingMemory::DATA_TYPE eDataType, unsigned int streamPoolFlags_MainMemory, unsigned int mainRAMSize_Alloc, unsigned int mainRAMSize_Data, unsigned int VRAMsize, unsigned __int64 *phMainRAM, UFG::qVRAMemoryHandle *phVRAM, const char *name, const char *tag_name, unsigned int *CPURAMRestoredSizeBytes, unsigned int *VRAMRestoredSizeBytes, unsigned int *paddedSizeAllocatedMainRAM, unsigned int *paddedSizeAllocatedVRAM, unsigned int *error_flags)
{
  unsigned int v14; // er10
  __int64 v15; // rdx
  UFG::qVRAMemoryPool *v16; // r15
  unsigned int v17; // esi
  unsigned int v18; // edi
  unsigned int flags; // edx
  UFG::StreamPool *v20; // rcx
  unsigned __int64 user_data_64; // rbp
  char v22; // bl
  char result; // al
  UFG::qVRAMemoryHandle handle; // [rsp+58h] [rbp-40h]

  v14 = streamPoolFlags_MainMemory;
  if ( error_flags )
    *error_flags = 0;
  v15 = UFG::StreamingMemory::dataTypeDefs[eDataType].mStreamPoolIndex;
  v16 = 0i64;
  v17 = 0;
  v18 = VRAMsize;
  if ( VRAMsize )
  {
    v16 = UFG::StreamingMemory::mVRAMDefs[dword_1420432B4[2 * eDataType]].mVRAMPool;
    v17 = UFG::StreamingMemory::mVRAMDefs[dword_1420432B4[2 * eDataType]].mBlockSize;
  }
  if ( UFG::StreamingMemory::smbFinalBandwidthEmu == 1 )
  {
    if ( paddedSizeAllocatedMainRAM )
      *paddedSizeAllocatedMainRAM = UFG::StreamingMemory::mMainRAMDefs[v15].mBlockSize;
    if ( paddedSizeAllocatedVRAM )
      *paddedSizeAllocatedVRAM = v17;
  }
  flags = v14 | v15 & 0x1F;
  v20 = UFG::gStreamPools[flags & 0x1F];
  if ( v20
    && (user_data_64 = UFG::StreamPool::Allocate(
                         v20,
                         mainRAMSize_Alloc,
                         mainRAMSize_Data,
                         name,
                         tag_name,
                         flags,
                         CPURAMRestoredSizeBytes),
        user_data_64 != -1i64) )
  {
    UFG::qVRAMemoryHandle::qVRAMemoryHandle(&handle);
    if ( !VRAMsize )
      goto LABEL_26;
    if ( v17 )
      v18 = v17 * ((v17 + VRAMsize - 1) / v17);
    UFG::qVRAMemoryPool::Allocate(
      v16,
      &handle,
      v18,
      0xAu,
      name,
      UFG::VRAMInterface::TEXTURE_ALIGNMENT,
      13,
      0i64,
      user_data_64,
      0);
    if ( handle.mData )
    {
LABEL_26:
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
    result = v22;
  }
  else
  {
    if ( error_flags )
      *error_flags |= 1u;
    *phMainRAM = -1i64;
    UFG::qVRAMemoryHandle::Close(phVRAM);
    result = 0;
  }
  return result;
}

