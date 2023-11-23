// File Line: 142
// RVA: 0x22F810
void __fastcall UFG::SectionChooser::SectionInfo::SectionInfo(UFG::SectionChooser::SectionInfo *this)
{
  *(_WORD *)&this->meLoadStateMID.mValue = 0;
  *(_DWORD *)&this->meLODLevelCurrent.mValue = 0;
  this->mhStreamHandleGAM.mPrev = &this->mhStreamHandleGAM;
  this->mhStreamHandleGAM.mNext = &this->mhStreamHandleGAM;
  this->mhStreamHandleGAM.mCallback = 0i64;
  this->mhStreamHandleGAM.mCallbackParam = 0i64;
  this->mhStreamHandleGAM.mImpl = 0i64;
  *(_DWORD *)&this->mhStreamHandleGAM.mFlags = 536870915;
  this->mhStreamHandleGAM._mTargetState.mValue = 1;
  this->mhStreamHandleMID.mPrev = &this->mhStreamHandleMID;
  this->mhStreamHandleMID.mNext = &this->mhStreamHandleMID;
  this->mhStreamHandleMID.mCallback = 0i64;
  this->mhStreamHandleMID.mCallbackParam = 0i64;
  this->mhStreamHandleMID.mImpl = 0i64;
  *(_DWORD *)&this->mhStreamHandleMID.mFlags = 536870915;
  this->mhStreamHandleMID._mTargetState.mValue = 1;
  this->mhStreamHandleSTD.mPrev = &this->mhStreamHandleSTD;
  this->mhStreamHandleSTD.mNext = &this->mhStreamHandleSTD;
  this->mhStreamHandleSTD.mCallback = 0i64;
  this->mhStreamHandleSTD.mCallbackParam = 0i64;
  this->mhStreamHandleSTD.mImpl = 0i64;
  *(_DWORD *)&this->mhStreamHandleSTD.mFlags = 536870915;
  this->mhStreamHandleSTD._mTargetState.mValue = 1;
  ++UFG::SectionChooser::SectionInfo::smStateCount[2][0];
  ++UFG::SectionChooser::SectionInfo::smStateCount[1][0];
  *(_QWORD *)this->mChangedStateFrameStamp = 0i64;
  *(_QWORD *)&this->mChangedStateFrameStamp[2] = 0i64;
  *(_QWORD *)&this->mChangedStateFrameStamp[4] = 0i64;
}

// File Line: 237
// RVA: 0x22FA30
void __fastcall UFG::SectionChooser::ZoneInfo::ZoneInfo(UFG::SectionChooser::ZoneInfo *this)
{
  *(_QWORD *)&this->meLODLevelCurrent = 0i64;
  this->mbStdLODLoaded = 0;
  this->mhStreamHandleStdLOD.mPrev = &this->mhStreamHandleStdLOD;
  this->mhStreamHandleStdLOD.mNext = &this->mhStreamHandleStdLOD;
  this->mhStreamHandleStdLOD.mCallback = 0i64;
  this->mhStreamHandleStdLOD.mCallbackParam = 0i64;
  this->mhStreamHandleStdLOD.mImpl = 0i64;
  *(_DWORD *)&this->mhStreamHandleStdLOD.mFlags = 536870915;
  this->mhStreamHandleStdLOD._mTargetState.mValue = 1;
}

// File Line: 283
// RVA: 0x1470580
__int64 UFG::SectionChooser::_dynamic_initializer_for__mWorldName__()
{
  UFG::qString::qString(&UFG::SectionChooser::mWorldName);
  return atexit((int (__fastcall *)())UFG::SectionChooser::_dynamic_atexit_destructor_for__mWorldName__);
}

// File Line: 297
// RVA: 0x14704E0
__int64 UFG::SectionChooser::_dynamic_initializer_for__mStreamBSPDebugData__()
{
  UFG::SectionChooser::mStreamBSPDebugData.mCallback = 0i64;
  UFG::SectionChooser::mStreamBSPDebugData.mCallbackParam = 0i64;
  UFG::SectionChooser::mStreamBSPDebugData.mImpl = 0i64;
  *(_DWORD *)&UFG::SectionChooser::mStreamBSPDebugData.mFlags = 536870915;
  UFG::SectionChooser::mStreamBSPDebugData._mTargetState.mValue = 1;
  return atexit((int (__fastcall *)())UFG::SectionChooser::_dynamic_atexit_destructor_for__mStreamBSPDebugData__);
}

// File Line: 298
// RVA: 0x1470530
__int64 UFG::SectionChooser::_dynamic_initializer_for__mStreamHandleWorldCommon__()
{
  UFG::SectionChooser::mStreamHandleWorldCommon.mCallback = 0i64;
  UFG::SectionChooser::mStreamHandleWorldCommon.mCallbackParam = 0i64;
  UFG::SectionChooser::mStreamHandleWorldCommon.mImpl = 0i64;
  *(_DWORD *)&UFG::SectionChooser::mStreamHandleWorldCommon.mFlags = 0x20000003;
  UFG::SectionChooser::mStreamHandleWorldCommon._mTargetState.mValue = 1;
  return atexit((int (__fastcall *)())UFG::SectionChooser::_dynamic_atexit_destructor_for__mStreamHandleWorldCommon__);
}

// File Line: 312
// RVA: 0x235160
void __fastcall UFG::SectionChooser::SetOnZoneLayoutLoadCallback(
        void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *))
{
  UFG::SectionChooser::mOnZoneLayoutLoadCallback = callback;
}

// File Line: 316
// RVA: 0x235150
void __fastcall UFG::SectionChooser::SetLookahead(UFG::SectionChooser::Lookahead *look_ahead)
{
  UFG::SectionChooser::mLookahead = look_ahead;
}

// File Line: 335
// RVA: 0x233810
void __fastcall UFG::SectionChooser::LoadGlobalCell(bool enabled)
{
  __int64 mOffset; // rcx
  const char *v2; // rax
  const char *v3; // r9
  UFG::qString *v4; // rax
  UFG::SectionChooser::SectionInfo *v5; // rcx
  UFG::SectionChooser::SectionInfo *v6; // rcx
  UFG::qString v7; // [rsp+48h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+70h] [rbp-38h] BYREF

  if ( UFG::SectionChooser::mSectionInfo )
  {
    if ( enabled )
    {
      UFG::qString::qString(&v7);
      mOffset = UFG::gSectionLayout->mSections.mOffset;
      if ( mOffset )
        v2 = (char *)&UFG::gSectionLayout->mSections + mOffset;
      else
        v2 = 0i64;
      if ( v2 )
        v2 += 16;
      if ( !gIsHDWorldTextures || (v3 = "HD", gForceLowRes) )
        v3 = "SD";
      v4 = UFG::qString::FormatEx(
             &result,
             "Data\\World\\%s\\Section\\%s\\%s\\%sSTD.perm.bin",
             UFG::SectionChooser::mWorldName.mData,
             v3,
             v2,
             v2);
      UFG::qString::Set(&v7, v4->mData, v4->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      UFG::DataStreamer::QueueStream(
        &UFG::SectionChooser::mSectionInfo->mhStreamHandleSTD,
        v7.mData,
        DATA_WORLD_INIT,
        DEFAULT_PRIORITY,
        1u,
        (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))UFG::SectionChooser::OnSectionLoadCallback,
        UFG::SectionChooser::mSectionInfo);
      v5 = UFG::SectionChooser::mSectionInfo;
      UFG::SectionChooser::mSectionInfo->mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
      --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v5->meLoadStateSTD.mValue];
      ++UFG::SectionChooser::SectionInfo::smStateCount[2][1];
      v5->meLoadStateSTD.mValue = 1;
      v5->mUnloadCountStd = 5;
      UFG::qString::~qString(&v7);
    }
    else
    {
      UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo->mhStreamHandleSTD);
      v6 = UFG::SectionChooser::mSectionInfo;
      UFG::SectionChooser::mSectionInfo->mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
      --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v6->meLoadStateSTD.mValue];
      ++UFG::SectionChooser::SectionInfo::smStateCount[2][0];
      v6->meLoadStateSTD.mValue = 0;
      v6->mUnloadCountStd = 5;
    }
  }
}

// File Line: 361
// RVA: 0x2344F0
void __fastcall UFG::SectionChooser::OnZoneLayoutLoadCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::qResourceInventoryVtbl *vfptr; // rbx
  unsigned int v5; // eax
  UFG::BSP *v6; // rax
  UFG::qResourceInventoryVtbl *v7; // rbx
  unsigned int v8; // eax
  UFG::BSP *v9; // rax
  unsigned __int64 mSectionCount; // rcx
  int v11; // esi
  __int64 v12; // rax
  bool v13; // cf
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::SectionChooser::SectionInfo *v16; // rbx
  unsigned __int64 mZoneCount; // rcx
  int v18; // esi
  __int64 v19; // rax
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::SectionChooser::ZoneInfo *v22; // rbx
  unsigned int i; // r8d
  __int64 mOffset; // rcx
  char *v25; // r9
  __int64 v26; // rcx
  char *v27; // rax
  const char *v28; // r9
  const char *v29; // rax
  UFG::qString *v30; // rax
  UFG::qString v31; // [rsp+48h] [rbp-70h] BYREF
  UFG::qString result; // [rsp+70h] [rbp-48h] BYREF

  vfptr = UFG::gBSPInventory.vfptr;
  v5 = UFG::qStringHash32("World", 0xFFFFFFFF);
  v6 = (UFG::BSP *)vfptr->Get(&UFG::gBSPInventory, v5);
  if ( !v6 || !v6->mNodeCount )
  {
    UFG::SectionChooser::mBSP = 0i64;
LABEL_29:
    UFG::SectionChooser::mSectionCount = 0;
    UFG::SectionChooser::mZoneCount = 0;
    goto LABEL_30;
  }
  UFG::SectionChooser::mBSP = v6;
  v7 = UFG::gBSPInventory.vfptr;
  v8 = UFG::qStringHash32("World", 0xFFFFFFFF);
  v9 = (UFG::BSP *)v7->Get(&UFG::gBSPInventory, v8);
  if ( v9 && v9->mNodeCount )
    UFG::SectionChooser::mBSP = v9;
  else
    v9 = UFG::SectionChooser::mBSP;
  if ( !v9 )
    goto LABEL_29;
  UFG::qMemSet(UFG::SectionChooser::SectionInfo::smStateCount, 0, 0x60u);
  mSectionCount = UFG::gSectionLayout->mSectionCount;
  UFG::SectionChooser::mSectionCount = mSectionCount;
  v11 = mSectionCount;
  v12 = 184 * mSectionCount;
  if ( !is_mul_ok(mSectionCount, 0xB8ui64) )
    v12 = -1i64;
  v13 = __CFADD__(v12, 8i64);
  v14 = v12 + 8;
  if ( v13 )
    v14 = -1i64;
  v15 = UFG::qMalloc(v14, "DataStream::SectionInfo", 0i64);
  if ( v15 )
  {
    LODWORD(v15->mNext) = v11;
    v16 = (UFG::SectionChooser::SectionInfo *)&v15[1];
    `eh vector constructor iterator(
      &v15[1],
      0xB8ui64,
      v11,
      (void (__fastcall *)(void *))UFG::SectionChooser::SectionInfo::SectionInfo);
  }
  else
  {
    v16 = 0i64;
  }
  UFG::SectionChooser::mSectionInfo = v16;
  mZoneCount = UFG::gZoneLayout->mZoneCount;
  UFG::SectionChooser::mZoneCount = mZoneCount;
  v18 = mZoneCount;
  v19 = mZoneCount << 6;
  if ( !is_mul_ok(mZoneCount, 0x40ui64) )
    v19 = -1i64;
  v13 = __CFADD__(v19, 8i64);
  v20 = v19 + 8;
  if ( v13 )
    v20 = -1i64;
  v21 = UFG::qMalloc(v20, "DataStream::ZoneInfo", 0i64);
  if ( v21 )
  {
    LODWORD(v21->mNext) = v18;
    v22 = (UFG::SectionChooser::ZoneInfo *)&v21[1];
    `eh vector constructor iterator(
      &v21[1],
      0x40ui64,
      v18,
      (void (__fastcall *)(void *))UFG::SectionChooser::ZoneInfo::ZoneInfo);
  }
  else
  {
    v22 = 0i64;
  }
  UFG::SectionChooser::mZoneInfo = v22;
  for ( i = 0; i < UFG::SectionChooser::mSectionCount; ++i )
  {
    mOffset = UFG::gSectionLayout->mSections.mOffset;
    if ( mOffset )
      v25 = (char *)&UFG::gSectionLayout->mSections + mOffset;
    else
      v25 = 0i64;
    UFG::SectionChooser::mSectionInfo[i].mSection = (UFG::Section *)&v25[48 * i];
  }
LABEL_30:
  UFG::SectionChooser::QueueZoneLoad(0);
  UFG::SectionChooser::LoadGlobalCell(1);
  UFG::qString::qString(&v31);
  v26 = UFG::gSectionLayout->mSections.mOffset;
  if ( v26 )
    v27 = (char *)&UFG::gSectionLayout->mSections + v26;
  else
    v27 = 0i64;
  v28 = v27 + 16;
  if ( !v27 )
    v28 = 0i64;
  if ( !gIsHDWorldTextures || (v29 = "HD", gForceLowRes) )
    v29 = "SD";
  if ( mbStreamGameplayFromWorldBigFile )
    v30 = UFG::qString::FormatEx(
            &result,
            "Data\\World\\%s\\Section\\%s\\%s\\%sXXX.perm.bin",
            UFG::SectionChooser::mWorldName.mData,
            v29,
            v28,
            v28);
  else
    v30 = UFG::qString::FormatEx(&result, "Data\\Gameplay\\%s\\%s.bin", UFG::SectionChooser::mWorldName.mData, v28);
  UFG::qString::Set(&v31, v30->mData, v30->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::DataStreamer::QueueStream(
    &UFG::SectionChooser::mSectionInfo->mhStreamHandleGAM,
    v31.mData,
    DATA_GAMEPLAY_GLOBAL,
    DEFAULT_PRIORITY,
    1u,
    (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))UFG::SectionChooser::OnSectionLoadCallback,
    UFG::SectionChooser::mSectionInfo);
  if ( UFG::SectionChooser::mOnZoneLayoutLoadCallback )
    UFG::SectionChooser::mOnZoneLayoutLoadCallback(handle, param);
  UFG::qString::~qString(&v31);
}

// File Line: 548
// RVA: 0x2330D0
__int64 __fastcall UFG::SectionChooser::Initialize(const char *worldName)
{
  UFG::SectionChooser::Lookahead *v1; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SectionChooser::Lookahead *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::SectionChooser::Lookahead *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm2_4
  unsigned __int8 v10; // bl
  UFG::qString result; // [rsp+48h] [rbp-30h] BYREF

  v1 = UFG::SectionChooser::mLookahead;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  UFG::SectionChooser::mLookahead->mViewerPosition.x = UFG::qVector3::msZero.x;
  v1->mViewerPosition.y = y;
  v1->mViewerPosition.z = z;
  v4 = UFG::SectionChooser::mLookahead;
  v5 = UFG::qVector3::msDirFront.y;
  v6 = UFG::qVector3::msDirFront.z;
  UFG::SectionChooser::mLookahead->mViewerDirection.x = UFG::qVector3::msDirFront.x;
  v4->mViewerDirection.y = v5;
  v4->mViewerDirection.z = v6;
  v7 = UFG::SectionChooser::mLookahead;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  UFG::SectionChooser::mLookahead->mViewerVelocity.x = UFG::qVector3::msZero.x;
  v7->mViewerVelocity.y = v8;
  v7->mViewerVelocity.z = v9;
  UFG::qString::Set(&UFG::SectionChooser::mWorldName, worldName);
  UFG::qString::FormatEx(&result, "Data\\World\\%s\\Region.perm.bin", UFG::SectionChooser::mWorldName.mData);
  if ( UFG::StreamFileWrapper::FileExists(result.mData) )
  {
    UFG::DataStreamer::QueueStream(
      &UFG::SectionChooser::mStreamHandleWorldCommon,
      result.mData,
      DATA_WORLD_INIT,
      DEFAULT_PRIORITY,
      0x83u,
      UFG::SectionChooser::OnZoneLayoutLoadCallback,
      0i64);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  UFG::qString::~qString(&result);
  return v10;
}

// File Line: 594
// RVA: 0x230ED0
void __fastcall UFG::SectionChooser::Destroy(UFG::SectionChooser *this)
{
  unsigned __int16 *p_mFlags; // rbx
  UFG::Section **p_mSection; // rbx

  mSTDSectionCount = 0;
  mLOWSectionCount = 0;
  UFG::SectionChooser::mSTDZoneCount = 0;
  UFG::SectionChooser::UpdateStreams(0);
  if ( UFG::SectionChooser::mZoneInfo )
    UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mZoneInfo->mhStreamHandleStdLOD);
  UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mStreamHandleWorldCommon);
  UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mStreamBSPDebugData);
  UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo->mhStreamHandleGAM);
  UFG::DataStreamer::Service(0.017000001);
  UFG::DataStreamer::Service(0.017000001);
  Render::StreamingLoopProcessQueuedOperations(1, 0);
  if ( UFG::SectionChooser::mZoneInfo )
  {
    p_mFlags = &UFG::SectionChooser::mZoneInfo[-1].mhStreamHandleStdLOD.mFlags;
    `eh vector destructor iterator(
      UFG::SectionChooser::mZoneInfo,
      0x40ui64,
      *(_DWORD *)&UFG::SectionChooser::mZoneInfo[-1].mhStreamHandleStdLOD.mFlags,
      (void (__fastcall *)(void *))UFG::SectionChooser::ZoneInfo::~ZoneInfo);
    operator delete[](p_mFlags);
    UFG::SectionChooser::mZoneInfo = 0i64;
  }
  if ( UFG::SectionChooser::mSectionInfo )
  {
    p_mSection = &UFG::SectionChooser::mSectionInfo[-1].mSection;
    `eh vector destructor iterator(
      UFG::SectionChooser::mSectionInfo,
      0xB8ui64,
      (int)UFG::SectionChooser::mSectionInfo[-1].mSection,
      (void (__fastcall *)(void *))UFG::SectionChooser::SectionInfo::~SectionInfo);
    operator delete[](p_mSection);
    UFG::SectionChooser::mSectionInfo = 0i64;
  }
  UFG::SectionChooser::mBSP = 0i64;
  UFG::SectionChooser::mSectionCount = 0;
  UFG::SectionChooser::mZoneCount = 0;
}

// File Line: 641
// RVA: 0x232E80
UFG::qVector3 *__fastcall UFG::SectionChooser::GetViewerPosition()
{
  return &UFG::SectionChooser::mLookahead->mViewerPosition;
}

// File Line: 645
// RVA: 0x232390
UFG::BSP *__fastcall UFG::SectionChooser::GetBSP()
{
  return UFG::SectionChooser::mBSP;
}

// File Line: 657
// RVA: 0x2309A0
void __fastcall UFG::SectionChooser::BeginFlush(bool emptyCache)
{
  UFG::SectionChooser::ZoneInfo *v1; // rbx
  UFG::SectionChooser::SectionInfo *v2; // rcx

  v1 = UFG::SectionChooser::mZoneInfo;
  UFG::SectionChooser::meFlushState = emptyCache + 1;
  if ( UFG::SectionChooser::mZoneInfo )
  {
    UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mZoneInfo->mhStreamHandleStdLOD);
    v1->mbStdLODLoaded = 0;
  }
  if ( UFG::SectionChooser::mSectionInfo )
  {
    UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo->mhStreamHandleSTD);
    v2 = UFG::SectionChooser::mSectionInfo;
    UFG::SectionChooser::mSectionInfo->mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
    --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v2->meLoadStateSTD.mValue];
    ++UFG::SectionChooser::SectionInfo::smStateCount[2][0];
    v2->meLoadStateSTD.mValue = 0;
    v2->mUnloadCountStd = 5;
  }
}

// File Line: 674
// RVA: 0x2324A0
__int64 __fastcall UFG::SectionChooser::GetCellToLoadFromVisIndex(
        unsigned int vis_index,
        bool keep_currently_loaded_alt_layers)
{
  UFG::SectionLayout *v2; // rbx
  __int64 mOffset; // rax
  char *v5; // r8
  __int64 v6; // rdx
  __int64 v7; // rax
  char *v8; // rcx
  unsigned int v9; // r11d
  int *v10; // rdx
  __int64 v11; // r8
  int v12; // eax
  unsigned int v13; // edx
  int v14; // r8d
  char *i; // r10
  __int64 v16; // rax
  char *v17; // rcx
  __int64 v18; // rcx
  __int64 v19; // rax
  char *v20; // r9
  int v22; // [rsp+0h] [rbp-28h] BYREF
  char v23; // [rsp+4h] [rbp-24h] BYREF

  v2 = UFG::gSectionLayout;
  mOffset = UFG::gSectionLayout->mSectionVis.mOffset;
  if ( mOffset )
    v5 = (char *)&UFG::gSectionLayout->mSectionVis + mOffset;
  else
    v5 = 0i64;
  v6 = 96i64 * vis_index;
  v7 = *(_QWORD *)&v5[v6 + 32];
  if ( v7 )
    v8 = &v5[v6 + 32 + v7];
  else
    v8 = 0i64;
  v9 = *(unsigned __int16 *)&v5[v6 + 24];
  if ( *(_WORD *)&v5[v6 + 24] )
  {
    v10 = &v22;
    v11 = v9;
    do
    {
      v12 = *(_DWORD *)v8;
      ++v10;
      v8 += 8;
      *(v10 - 1) = v12;
      --v11;
    }
    while ( v11 );
  }
  v13 = 0;
  if ( (!keep_currently_loaded_alt_layers
     || (unsigned int)(unsigned __int8)UFG::SectionChooser::mSectionInfo[v22].meLoadStateSTD.mValue - 1 > 1)
    && v9 > 1 )
  {
    v14 = 1;
    for ( i = &v23;
          (unsigned int)(unsigned __int8)UFG::SectionChooser::mSectionInfo[*(unsigned int *)i].meLoadStateSTD.mValue - 1 > 1;
          i += 4 )
    {
      v16 = v2->mSections.mOffset;
      if ( v16 )
        v17 = (char *)&v2->mSections + v16;
      else
        v17 = 0i64;
      v18 = *(unsigned __int16 *)&v17[48 * *(unsigned int *)i + 10];
      v19 = v2->mLayers.mOffset;
      if ( v19 )
        v20 = (char *)&v2->mLayers + v19;
      else
        v20 = 0i64;
      if ( *(_DWORD *)&v20[48 * v18 + 8] )
      {
        if ( !v13 )
          v13 = v14;
      }
      if ( ++v14 >= v9 )
        return (unsigned int)*(&v22 + v13);
    }
    v13 = v14;
  }
  return (unsigned int)*(&v22 + v13);
}

// File Line: 725
// RVA: 0x232E90
__int64 __fastcall UFG::SectionChooser::GetVisIndexAtPosition(UFG::qVector3 *position, bool dbg_print_serials)
{
  if ( UFG::SectionChooser::mBSP )
    return UFG::BSP::GetSpaceFromPoint(UFG::SectionChooser::mBSP, position, 1, dbg_print_serials)->mSectionIndex;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 739
// RVA: 0x232460
__int64 __fastcall UFG::SectionChooser::GetCellIndexAtPosition(UFG::qVector3 *position, bool dbg_print_serials)
{
  UFG::BSPSpace *SpaceFromPoint; // rax

  if ( !UFG::SectionChooser::mBSP )
    return 0xFFFFFFFFi64;
  SpaceFromPoint = UFG::BSP::GetSpaceFromPoint(UFG::SectionChooser::mBSP, position, 1, dbg_print_serials);
  return UFG::SectionChooser::GetCellToLoadFromVisIndex(SpaceFromPoint->mSectionIndex, 1);
}

// File Line: 755
// RVA: 0x235190
void __fastcall UFG::SectionChooser::SetToStreamGameplayFromWorldBigFile(bool streamGameplayFromWorldBigFile)
{
  mbStreamGameplayFromWorldBigFile = streamGameplayFromWorldBigFile;
}

// File Line: 760
// RVA: 0x2326B0
void __fastcall UFG::SectionChooser::GetFilenameForSectionIndex(
        unsigned int sectionIndex,
        UFG::qString *fileName,
        UFG::SCENERY_LAYER eLODLevel)
{
  __int64 mOffset; // r9
  char *v5; // r9
  __int64 v6; // rcx
  bool v7; // zf
  const char *v8; // r9
  const char *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString *v11; // rax
  UFG::qString *v12; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  mOffset = UFG::gSectionLayout->mSections.mOffset;
  if ( mOffset )
    v5 = (char *)&UFG::gSectionLayout->mSections + mOffset;
  else
    v5 = 0i64;
  v6 = 48i64 * sectionIndex;
  v7 = &v5[v6] == 0i64;
  v8 = &v5[v6 + 16];
  if ( v7 )
    v8 = 0i64;
  if ( !gIsHDWorldTextures || (v9 = "HD", gForceLowRes) )
    v9 = "SD";
  switch ( eLODLevel )
  {
    case LOD_SETTING_HIGH:
      v10 = UFG::qString::FormatEx(
              &result,
              "Data\\World\\%s\\Section\\%s\\%s\\%sSTD.perm.bin",
              UFG::SectionChooser::mWorldName.mData,
              v9,
              v8,
              v8);
      UFG::qString::Set(fileName, v10->mData, v10->mLength, 0i64, 0);
      break;
    case LOD_SETTING_NORMAL:
      v11 = UFG::qString::FormatEx(
              &result,
              "Data\\World\\%s\\Section\\%s\\%s\\%sLOD.perm.bin",
              UFG::SectionChooser::mWorldName.mData,
              v9,
              v8,
              v8);
      UFG::qString::Set(fileName, v11->mData, v11->mLength, 0i64, 0);
      break;
    case NUM_LOD_SETTING|LOD_SETTING_NORMAL:
      if ( mbStreamGameplayFromWorldBigFile )
        v12 = UFG::qString::FormatEx(
                &result,
                "Data\\World\\%s\\Section\\%s\\%s\\%sXXX.perm.bin",
                UFG::SectionChooser::mWorldName.mData,
                v9,
                v8,
                v8);
      else
        v12 = UFG::qString::FormatEx(&result, "Data\\Gameplay\\%s\\%s.bin", UFG::SectionChooser::mWorldName.mData, v8);
      UFG::qString::Set(fileName, v12->mData, v12->mLength, 0i64, 0);
      break;
    default:
      return;
  }
  UFG::qString::~qString(&result);
}

// File Line: 823
// RVA: 0x233340
bool __fastcall UFG::SectionChooser::IsSectionVisible_VisIndex(
        unsigned int visIndex,
        UFG::SCENERY_LAYER eLodLevel,
        bool bConsiderVisibleOnlyAfterDelay)
{
  unsigned int CellToLoadFromVisIndex; // eax

  CellToLoadFromVisIndex = UFG::SectionChooser::GetCellToLoadFromVisIndex(visIndex, 1);
  return UFG::SectionChooser::IsSectionVisible_CellIndex(
           CellToLoadFromVisIndex,
           eLodLevel,
           bConsiderVisibleOnlyAfterDelay);
}

// File Line: 856
// RVA: 0x2332A0
bool __fastcall UFG::SectionChooser::IsSectionVisible_CellIndex(
        unsigned int sectionIndex,
        UFG::SCENERY_LAYER eLodLevel,
        bool bConsiderVisibleOnlyAfterDelay)
{
  UFG::SectionChooser::SectionInfo *v4; // rcx

  if ( !sectionIndex )
    return 1;
  if ( !UFG::SectionChooser::mSectionInfo )
    return 0;
  v4 = &UFG::SectionChooser::mSectionInfo[sectionIndex];
  if ( eLodLevel == SCENERY_LAYER_STD )
  {
    if ( v4->meLODLevelCurrent.mValue == 2 )
      return v4->meLoadStateSTD.mValue == 2
          && (!bConsiderVisibleOnlyAfterDelay || v4->mChangedStateFrameStamp[2] < UFG::Metrics::msFrameCount - 2);
    return 0;
  }
  if ( eLodLevel != SCENERY_LAYER_LOW
    || v4->meLODLevelCurrent.mValue == 2
    && v4->meLoadStateSTD.mValue == 2
    && v4->mChangedStateFrameStamp[2] < UFG::Metrics::msFrameCount - 2
    || UFG::SectionChooser::meSuppressLOD == SUPRESS_ISLAND )
  {
    return 0;
  }
  if ( v4->meLoadStateMID.mValue != 2 )
    return 0;
  if ( !bConsiderVisibleOnlyAfterDelay )
    return 1;
  return v4->mChangedStateFrameStamp[1] < UFG::Metrics::msFrameCount - 2;
}

// File Line: 911
// RVA: 0x230920
char __fastcall UFG::SectionChooser::AreAnyLoadsPending()
{
  int v0; // ebx
  UFG::SectionChooser::SectionInfo *v1; // rdi
  int StreamState; // eax

  v0 = 0;
  if ( !UFG::SectionChooser::mSectionCount )
    return 0;
  while ( 1 )
  {
    v1 = &UFG::SectionChooser::mSectionInfo[v0];
    StreamState = UFG::DataStreamer::GetStreamState(&v1->mhStreamHandleSTD);
    if ( StreamState == 2
      || StreamState == 3
      || (unsigned int)UFG::DataStreamer::GetStreamState(&v1->mhStreamHandleMID) - 2 <= 1 )
    {
      break;
    }
    if ( ++v0 >= UFG::SectionChooser::mSectionCount )
      return 0;
  }
  return 1;
}

// File Line: 951
// RVA: 0x234470
void __fastcall UFG::SectionChooser::OnSectionLoadCallback(
        UFG::DataStreamer::Handle *handle,
        UFG::SectionChooser::SectionInfo *param)
{
  if ( handle == &param->mhStreamHandleSTD )
  {
    if ( param->meLoadStateSTD.mValue == 1 )
    {
      param->mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
      --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)param->meLoadStateSTD.mValue];
      ++UFG::SectionChooser::SectionInfo::smStateCount[2][2];
      param->meLoadStateSTD.mValue = 2;
      param->mUnloadCountStd = 5;
    }
  }
  else if ( handle == &param->mhStreamHandleGAM )
  {
    param->mbLoadedGAM = 1;
  }
  else if ( handle == &param->mhStreamHandleMID && param->meLoadStateMID.mValue == 1 )
  {
    param->mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
    --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)param->meLoadStateMID.mValue];
    ++UFG::SectionChooser::SectionInfo::smStateCount[1][2];
    param->meLoadStateMID.mValue = 2;
    param->mUnloadCountLow = 5;
  }
}

// File Line: 993
// RVA: 0x234890
_BOOL8 __fastcall UFG::SectionChooser::QueueSectionLoad(unsigned int globalSectionIndex, UFG::SCENERY_LAYER eLODLevel)
{
  unsigned __int8 v4; // si
  __int64 v5; // r14
  UFG::SectionChooser::SectionInfo *callbackParam; // rdi
  unsigned int flags; // edx
  int v8; // eax
  UFG::DataStreamer::Handle *p_mhStreamHandleMID; // r10
  UFG::DataStreamer::PRIORITY v10; // ebx
  UFG::StreamingMemory::DATA_TYPE v11; // r8d
  int mValue; // eax
  __int64 mOffset; // rcx
  __int64 v14; // rax
  const char *v15; // r9
  const char *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString v19; // [rsp+40h] [rbp-98h] BYREF
  __int64 v20; // [rsp+68h] [rbp-70h]
  UFG::qString fileName; // [rsp+70h] [rbp-68h] BYREF
  UFG::qString result; // [rsp+98h] [rbp-40h] BYREF

  v20 = -2i64;
  v4 = 0;
  v5 = globalSectionIndex;
  callbackParam = &UFG::SectionChooser::mSectionInfo[globalSectionIndex];
  UFG::qString::qString(&fileName);
  UFG::SectionChooser::GetFilenameForSectionIndex(globalSectionIndex, &fileName, eLODLevel);
  flags = 0;
  if ( eLODLevel == SCENERY_LAYER_LOW )
  {
    mValue = (unsigned __int8)callbackParam->meLoadStateMID.mValue;
    if ( mValue == 3 )
    {
      callbackParam->mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
      --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)callbackParam->meLoadStateMID.mValue];
      ++UFG::SectionChooser::SectionInfo::smStateCount[1][2];
      callbackParam->meLoadStateMID.mValue = 2;
      callbackParam->mUnloadCountLow = 5;
      goto LABEL_10;
    }
    if ( mValue == 2 )
      goto LABEL_10;
    p_mhStreamHandleMID = &callbackParam->mhStreamHandleMID;
    callbackParam->mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
    --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)callbackParam->meLoadStateMID.mValue];
    ++UFG::SectionChooser::SectionInfo::smStateCount[1][1];
    callbackParam->meLoadStateMID.mValue = 1;
    callbackParam->mUnloadCountLow = 5;
    v10 = HIGH_PRIORITY;
    v11 = DATA_SECTION_LOD;
  }
  else
  {
    if ( eLODLevel != SCENERY_LAYER_STD )
      goto LABEL_26;
    v8 = (unsigned __int8)callbackParam->meLoadStateSTD.mValue;
    if ( v8 == 3 )
    {
      callbackParam->mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
      --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)callbackParam->meLoadStateSTD.mValue];
      ++UFG::SectionChooser::SectionInfo::smStateCount[2][2];
      callbackParam->meLoadStateSTD.mValue = 2;
      callbackParam->mUnloadCountStd = 5;
LABEL_10:
      v4 = 1;
      goto LABEL_26;
    }
    if ( v8 == 2 )
      goto LABEL_10;
    p_mhStreamHandleMID = &callbackParam->mhStreamHandleSTD;
    callbackParam->mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
    --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)callbackParam->meLoadStateSTD.mValue];
    ++UFG::SectionChooser::SectionInfo::smStateCount[2][1];
    callbackParam->meLoadStateSTD.mValue = 1;
    callbackParam->mUnloadCountStd = 5;
    v10 = VERY_HIGH_PRIORITY;
    flags = 128;
    v11 = DATA_SECTION_STD;
  }
  if ( p_mhStreamHandleMID )
  {
    v4 = UFG::DataStreamer::QueueStream(
           p_mhStreamHandleMID,
           fileName.mData,
           v11,
           v10,
           flags,
           (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))UFG::SectionChooser::OnSectionLoadCallback,
           callbackParam);
    if ( eLODLevel == SCENERY_LAYER_STD )
    {
      UFG::qString::qString(&v19);
      mOffset = UFG::gSectionLayout->mSections.mOffset;
      if ( mOffset )
        mOffset += (__int64)&UFG::gSectionLayout->mSections;
      v14 = mOffset + 48 * v5;
      if ( v14 )
        v15 = (const char *)(v14 + 16);
      else
        v15 = 0i64;
      if ( !gIsHDWorldTextures || (v16 = "HD", gForceLowRes) )
        v16 = "SD";
      if ( mbStreamGameplayFromWorldBigFile )
        v17 = UFG::qString::FormatEx(
                &result,
                "Data\\World\\%s\\Section\\%s\\%s\\%sXXX.perm.bin",
                UFG::SectionChooser::mWorldName.mData,
                v16,
                v15,
                v15);
      else
        v17 = UFG::qString::FormatEx(&result, "Data\\Gameplay\\%s\\%s.bin", UFG::SectionChooser::mWorldName.mData, v15);
      UFG::qString::Set(&v19, v17->mData, v17->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      v4 = UFG::DataStreamer::QueueStream(
             &callbackParam->mhStreamHandleGAM,
             v19.mData,
             DATA_GAMEPLAY_CELL,
             v10,
             0x83u,
             (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))UFG::SectionChooser::OnSectionLoadCallback,
             callbackParam);
      UFG::qString::~qString(&v19);
    }
  }
LABEL_26:
  UFG::qString::~qString(&fileName);
  return v4;
}

// File Line: 1144
// RVA: 0x234880
void __fastcall UFG::SectionChooser::OnZoneLoadCallback(UFG::DataStreamer::Handle *handle, _BYTE *param)
{
  if ( handle == (UFG::DataStreamer::Handle *)(param + 16) )
    param[8] = 1;
}

// File Line: 1166
// RVA: 0x234B70
__int64 __fastcall UFG::SectionChooser::QueueZoneLoad(unsigned int globalZoneIndex)
{
  unsigned __int64 v2; // rbx
  UFG::Zone *callbackParam; // rsi
  __int64 mOffset; // rdx
  UFG::Zone *v5; // rax
  const char *v6; // r9
  UFG::qString *v7; // rax
  UFG::StreamingMemory::DATA_TYPE v8; // r8d
  unsigned __int8 v9; // bl
  UFG::qString v11; // [rsp+48h] [rbp-60h] BYREF
  UFG::qString v12; // [rsp+70h] [rbp-38h] BYREF

  v2 = (unsigned __int64)globalZoneIndex << 6;
  callbackParam = (UFG::Zone *)((char *)UFG::SectionChooser::mZoneInfo + v2);
  UFG::qString::qString(&v11);
  mOffset = UFG::gZoneLayout->mZones.mOffset;
  if ( mOffset )
    v5 = (UFG::Zone *)((char *)&UFG::gZoneLayout->mZones + mOffset);
  else
    v5 = 0i64;
  if ( !gIsHDWorldTextures || (v6 = "HD", gForceLowRes) )
    v6 = "SD";
  v7 = UFG::qString::FormatEx(
         &v12,
         "Data\\World\\%s\\Zone\\%s\\%s\\%s.perm.bin",
         UFG::SectionChooser::mWorldName.mData,
         v6,
         &v5->mName[v2],
         &v5->mName[v2]);
  UFG::qString::Set(&v11, v7->mData, v7->mLength, 0i64, 0);
  UFG::qString::~qString(&v12);
  v8 = DATA_ZONE_LOC;
  if ( !globalZoneIndex )
    v8 = DATA_GLOBAL_LOC;
  v9 = UFG::DataStreamer::QueueStream(
         (UFG::DataStreamer::Handle *)&callbackParam->mUIDZoneUC,
         v11.mData,
         v8,
         VERY_HIGH_PRIORITY,
         0x81u,
         (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))UFG::SectionChooser::OnZoneLoadCallback,
         callbackParam);
  UFG::qString::~qString(&v11);
  return v9;
}

// File Line: 1202
// RVA: 0x232ED0
void __fastcall UFG::SectionChooser::HandleFlush(UFG::SectionChooser *this)
{
  unsigned int v1; // esi
  unsigned __int64 v2; // rdi
  UFG::SectionChooser::SectionInfo *v3; // rbx
  UFG::SectionChooser::SectionInfo *v4; // rbx
  unsigned int i; // edi
  unsigned __int64 v6; // rbx
  UFG::SectionChooser::ZoneInfo *v7; // rsi
  UFG *v8; // rcx

  if ( UFG::SectionChooser::meFlushState )
  {
    v1 = 1;
    mSTDSectionCount = 0;
    mLOWSectionCount = 0;
    for ( UFG::SectionChooser::mSTDZoneCount = 0; v1 < UFG::gSectionLayout->mSectionCount; ++v1 )
    {
      v2 = v1;
      if ( (unsigned int)UFG::DataStreamer::GetStreamState(&UFG::SectionChooser::mSectionInfo[v2].mhStreamHandleSTD) > 1 )
      {
        v3 = UFG::SectionChooser::mSectionInfo;
        UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo[v2].mhStreamHandleSTD);
        UFG::DataStreamer::ReleaseStream(&v3[v2].mhStreamHandleGAM);
        v3[v2].mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
        --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v3[v2].meLoadStateSTD.mValue];
        ++UFG::SectionChooser::SectionInfo::smStateCount[2][0];
        v3[v2].meLoadStateSTD.mValue = 0;
        v3[v2].mUnloadCountStd = 5;
        *(_WORD *)&v3[v2].mbLoadedGAM = 0;
      }
      if ( (unsigned int)UFG::DataStreamer::GetStreamState(&UFG::SectionChooser::mSectionInfo[v2].mhStreamHandleMID) > 1 )
      {
        v4 = UFG::SectionChooser::mSectionInfo;
        UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo[v2].mhStreamHandleMID);
        v4[v2].mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
        --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)v4[v2].meLoadStateMID.mValue];
        ++UFG::SectionChooser::SectionInfo::smStateCount[1][0];
        v4[v2].meLoadStateMID.mValue = 0;
        v4[v2].mUnloadCountLow = 5;
        v4[v2].mbFlushing = 0;
      }
    }
    for ( i = 0; i < UFG::gZoneLayout->mZoneCount; ++i )
    {
      v6 = (unsigned __int64)i << 6;
      if ( (unsigned int)UFG::DataStreamer::GetStreamState((UFG::DataStreamer::Handle *)((char *)&UFG::SectionChooser::mZoneInfo->mhStreamHandleStdLOD
                                                                                       + v6)) > 1 )
      {
        v7 = UFG::SectionChooser::mZoneInfo;
        if ( UFG::SectionChooser::mZoneInfo )
        {
          UFG::DataStreamer::ReleaseStream((UFG::DataStreamer::Handle *)((char *)&UFG::SectionChooser::mZoneInfo->mhStreamHandleStdLOD
                                                                       + v6));
          *(&v7->mbStdLODLoaded + v6) = 0;
        }
      }
    }
    UFG::DataStreamer::Service(0.1);
    Render::StreamingLoopProcessQueuedOperations(1, 0);
    if ( UFG::SectionChooser::meFlushState == FLUSH_AND_EMPTY_CACHE )
      UFG::StreamPool_ClearAllCachedData(v8);
    UFG::SectionChooser::QueueZoneLoad(0);
    UFG::SectionChooser::LoadGlobalCell(1);
    UFG::SectionChooser::meFlushState = FLUSH_NONE;
  }
}

// File Line: 1307
// RVA: 0x235B90
// bad sp value at call has been detected, the output may be wrong!
void __fastcall UFG::SectionChooser::UpdateStreams(char bFadeout)
{
  unsigned int i; // edx
  unsigned int j; // edx
  unsigned int k; // edx
  unsigned int m; // edx
  unsigned int n; // edx
  UFG::SectionChooser::SectionLoad *v7; // r12
  unsigned int v8; // r14d
  unsigned int v9; // r15d
  unsigned int v10; // r13d
  unsigned int v11; // eax
  unsigned __int64 v12; // rbx
  UFG::SectionChooser::SectionInfo *v13; // rdi
  unsigned __int8 mValue; // cl
  int v15; // edx
  int v16; // ecx
  UFG::SectionChooser::SectionInfo *v17; // rsi
  unsigned int v18; // ecx
  unsigned int v19; // r13d
  unsigned int v20; // esi
  unsigned __int64 v21; // rax
  UFG::allocator::free_link *v22; // rax
  __int64 v23; // r15
  UFG::allocator::free_link *v24; // rdx
  signed __int64 v25; // r8
  __int64 v26; // rcx
  __int64 v27; // rcx
  unsigned int v28; // ecx
  unsigned int v29; // r13d
  unsigned int v30; // esi
  unsigned __int64 v31; // rax
  UFG::allocator::free_link *v32; // rax
  __int64 v33; // r15
  UFG::allocator::free_link *v34; // rcx
  signed __int64 v35; // rdx
  __int64 v36; // r8
  __int64 v37; // rcx
  unsigned int v38; // esi
  unsigned __int64 v39; // rax
  UFG::allocator::free_link *v40; // rax
  __int64 v41; // r15
  UFG::allocator::free_link *v42; // rcx
  signed __int64 v43; // rdx
  __int64 v44; // r8
  unsigned int v45; // ecx
  unsigned int v46; // r13d
  unsigned int v47; // esi
  unsigned __int64 v48; // rax
  UFG::allocator::free_link *v49; // rax
  __int64 v50; // r15
  UFG::allocator::free_link *v51; // rcx
  signed __int64 v52; // rdx
  __int64 v53; // r8
  _DWORD *v54; // rdx
  unsigned int v55; // r13d
  unsigned int v56; // ecx
  unsigned int v57; // r9d
  unsigned int v58; // r10d
  UFG::SectionChooser::ZoneInfo *v59; // r15
  unsigned __int64 v60; // rsi
  int v61; // r8d
  int v62; // eax
  unsigned int v63; // r8d
  unsigned int v64; // edi
  unsigned int v65; // ebx
  unsigned __int64 v66; // rax
  UFG::allocator::free_link *v67; // rax
  void *v68; // rcx
  UFG::allocator::free_link *v69; // rdx
  char *v70; // r9
  __int64 v71; // r8
  float *p_mScore; // rbx
  __int64 v73; // rdi
  __int64 mOffset; // rcx
  char *v75; // rdx
  char *v76; // rcx
  __int64 v77; // rdx
  char *v78; // r8
  __int64 v79; // rcx
  float v80; // xmm3_4
  float v81; // xmm2_4
  __m128 x_low; // xmm0
  float v83; // xmm6_4
  float y; // xmm1_4
  float v85; // xmm3_4
  float v86; // xmm6_4
  UFG::SectionChooser::SectionLoad *v87; // rbx
  __int64 v88; // rdi
  __int64 mGlobalIndex; // r9
  __int64 v90; // rcx
  char *v91; // r8
  void *v92; // rdi
  unsigned int *v93; // rbx
  __int64 v94; // rsi
  UFG::qVector3 v2; // [rsp+8h] [rbp-61h] BYREF
  UFG::qVector3 v1; // [rsp+18h] [rbp-51h] BYREF
  __int64 v97; // [rsp+28h] [rbp-41h]
  __int64 v98; // [rsp+30h] [rbp-39h]
  __int64 v99; // [rsp+38h] [rbp-31h]
  void *mem; // [rsp+40h] [rbp-29h]
  char v101; // [rsp+D0h] [rbp+67h]
  unsigned int v102; // [rsp+D8h] [rbp+6Fh]
  unsigned int v103; // [rsp+E0h] [rbp+77h]
  UFG::allocator::free_link *v104; // [rsp+E8h] [rbp+7Fh]

  if ( UFG::SectionChooser::mStreamsUpdateEnabled )
  {
    ++UFG::Zone::smCurrentMagic0;
    ++UFG::Zone::smCurrentMagic1;
    for ( i = 0; i < UFG::SectionChooser::mZoneCount; ++i )
      UFG::SectionChooser::mZoneInfo[(unsigned __int64)i].meLODLevelNew = SCENERY_LAYER_NONE;
    for ( j = 0; j < UFG::SectionChooser::mSectionCount; ++j )
      UFG::SectionChooser::mSectionInfo[j].meLODLevelNew.mValue = 0;
    if ( UFG::SectionChooser::meSuppressLOD != SUPRESS_ISLAND_AND_LOW )
    {
      for ( k = 0; k < mLOWSectionCount; ++k )
        UFG::SectionChooser::mSectionInfo[mLOWSectionCellIndices[k]].meLODLevelNew.mValue = 1;
    }
    for ( m = 0; m < mSTDSectionCount; ++m )
      UFG::SectionChooser::mSectionInfo[mSTDSectionCellIndices[m]].meLODLevelNew.mValue = 2;
    for ( n = 0; n < UFG::SectionChooser::mSTDZoneCount; ++n )
      UFG::SectionChooser::mZoneInfo[(unsigned __int64)UFG::SectionChooser::mSTDZoneIndices[n]].meLODLevelNew = SCENERY_LAYER_STD;
    v7 = 0i64;
    v98 = 0i64;
    v8 = 0;
    v97 = 0i64;
    v9 = 0;
    v10 = 0;
    v102 = 0;
    v11 = UFG::SectionChooser::mSectionCount;
    while ( v10 < v11 )
    {
      v12 = v10;
      v13 = UFG::SectionChooser::mSectionInfo;
      mValue = UFG::SectionChooser::mSectionInfo[v12].meLODLevelCurrent.mValue;
      LOBYTE(v15) = UFG::SectionChooser::mSectionInfo[v12].meLODLevelNew.mValue;
      if ( mValue == (_BYTE)v15 && !UFG::SectionChooser::mSectionInfo[v12].mbFlushing )
        goto LABEL_124;
      v15 = (unsigned __int8)v15;
      if ( UFG::SectionChooser::mSectionInfo[v12].mbFlushing )
        v15 = 0;
      LODWORD(v104) = v15;
      if ( mValue )
      {
        v16 = mValue - 1;
        if ( v16 )
        {
          if ( v16 == 1 )
          {
            if ( v15 )
            {
              if ( v15 == 1 )
              {
                if ( bFadeout
                  && !UFG::SectionChooser::mCaptureFarGroundImposters
                  && UFG::SectionChooser::mSectionInfo[v12].meLoadStateSTD.mValue )
                {
                  UFG::SectionChooser::mSectionInfo[v12].mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
                  --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v13[v12].meLoadStateSTD.mValue];
                  ++UFG::SectionChooser::SectionInfo::smStateCount[2][3];
                  v13[v12].meLoadStateSTD.mValue = 3;
                  v13[v12].mUnloadCountStd = 5;
                }
                else
                {
                  UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo[v12].mhStreamHandleSTD);
                  UFG::DataStreamer::ReleaseStream(&v13[v12].mhStreamHandleGAM);
                  v13[v12].mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
                  --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v13[v12].meLoadStateSTD.mValue];
                  ++UFG::SectionChooser::SectionInfo::smStateCount[2][0];
                  v13[v12].meLoadStateSTD.mValue = 0;
                  v13[v12].mUnloadCountStd = 5;
                  *(_WORD *)&v13[v12].mbLoadedGAM = 0;
                }
              }
            }
            else
            {
              if ( (UFG::SectionChooser::mSectionInfo[v12].mSection->mFlags & 0x10) == 0 )
              {
                if ( bFadeout
                  && !UFG::SectionChooser::mCaptureFarGroundImposters
                  && UFG::SectionChooser::mSectionInfo[v12].meLoadStateMID.mValue )
                {
                  UFG::SectionChooser::mSectionInfo[v12].mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
                  --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)v13[v12].meLoadStateMID.mValue];
                  ++UFG::SectionChooser::SectionInfo::smStateCount[1][3];
                  v13[v12].meLoadStateMID.mValue = 3;
                }
                else
                {
                  UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo[v12].mhStreamHandleMID);
                  v13[v12].mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
                  --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)v13[v12].meLoadStateMID.mValue];
                  ++UFG::SectionChooser::SectionInfo::smStateCount[1][0];
                  v13[v12].meLoadStateMID.mValue = 0;
                  v13[v12].mbFlushing = 0;
                  bFadeout = v101;
                }
                v13[v12].mUnloadCountLow = 5;
              }
              v17 = UFG::SectionChooser::mSectionInfo;
              if ( bFadeout
                && !UFG::SectionChooser::mCaptureFarGroundImposters
                && UFG::SectionChooser::mSectionInfo[v12].meLoadStateSTD.mValue )
              {
                UFG::SectionChooser::mSectionInfo[v12].mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
                --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v17[v12].meLoadStateSTD.mValue];
                ++UFG::SectionChooser::SectionInfo::smStateCount[2][3];
                v17[v12].meLoadStateSTD.mValue = 3;
                v17[v12].mUnloadCountStd = 5;
              }
              else
              {
                UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo[v12].mhStreamHandleSTD);
                UFG::DataStreamer::ReleaseStream(&v17[v12].mhStreamHandleGAM);
                v17[v12].mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
                --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v17[v12].meLoadStateSTD.mValue];
                ++UFG::SectionChooser::SectionInfo::smStateCount[2][0];
                v17[v12].meLoadStateSTD.mValue = 0;
                v17[v12].mUnloadCountStd = 5;
                *(_WORD *)&v17[v12].mbLoadedGAM = 0;
              }
            }
          }
          goto LABEL_123;
        }
        if ( !v15 )
        {
          if ( (UFG::SectionChooser::mSectionInfo[v12].mSection->mFlags & 0x10) == 0 )
          {
            if ( bFadeout
              && !UFG::SectionChooser::mCaptureFarGroundImposters
              && UFG::SectionChooser::mSectionInfo[v12].meLoadStateMID.mValue )
            {
              UFG::SectionChooser::mSectionInfo[v12].mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
              --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)v13[v12].meLoadStateMID.mValue];
              ++UFG::SectionChooser::SectionInfo::smStateCount[1][3];
              v13[v12].meLoadStateMID.mValue = 3;
              v13[v12].mUnloadCountLow = 5;
            }
            else
            {
              UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo[v12].mhStreamHandleMID);
              v13[v12].mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
              --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)v13[v12].meLoadStateMID.mValue];
              ++UFG::SectionChooser::SectionInfo::smStateCount[1][0];
              v13[v12].meLoadStateMID.mValue = 0;
              v13[v12].mUnloadCountLow = 5;
              v13[v12].mbFlushing = 0;
            }
          }
          goto LABEL_123;
        }
        if ( v15 == 2 )
        {
          v18 = v8;
          v103 = v8;
          v19 = v8 + 1;
          if ( v8 + 1 > v9 )
          {
            v20 = 1;
            if ( v9 )
              v20 = 2 * v9;
            for ( ; v20 < v19; v20 *= 2 )
              ;
            if ( v20 - v19 > 0x10000 )
              v20 = v8 + 65537;
            if ( v20 != v8 )
            {
              v21 = 12i64 * v20;
              if ( !is_mul_ok(v20, 0xCui64) )
                v21 = -1i64;
              v22 = UFG::qMalloc(v21, "qArray.Add", 0i64);
              v23 = (__int64)v22;
              *(_QWORD *)&v2.x = v22;
              if ( v7 )
              {
                if ( v8 )
                {
                  v24 = v22;
                  v25 = (char *)v7 - (char *)v22;
                  v26 = v8;
                  do
                  {
                    LODWORD(v24->mNext) = *(_DWORD *)((char *)&v24->mNext + v25);
                    HIDWORD(v24->mNext) = *(_DWORD *)((char *)&v24->mNext + v25 + 4);
                    LODWORD(v24[1].mNext) = *(_DWORD *)((char *)&v24[1].mNext + v25);
                    v24 = (UFG::allocator::free_link *)((char *)v24 + 12);
                    --v26;
                  }
                  while ( v26 );
                }
                operator delete[](v7);
              }
              v7 = (UFG::SectionChooser::SectionLoad *)v23;
              v98 = v23;
              v9 = v20;
              HIDWORD(v97) = v20;
              v18 = v103;
            }
          }
          goto LABEL_58;
        }
      }
      else
      {
        if ( v15 == 1 )
        {
          if ( (UFG::SectionChooser::mSectionInfo[v12].mSection->mFlags & 0x10) != 0
            || UFG::SectionChooser::meSuppressLOD == SUPRESS_ISLAND_AND_LOW )
          {
            goto LABEL_123;
          }
          v45 = v8;
          v103 = v8;
          v46 = v8 + 1;
          if ( v8 + 1 > v9 )
          {
            v47 = 1;
            if ( v9 )
              v47 = 2 * v9;
            for ( ; v47 < v46; v47 *= 2 )
              ;
            if ( v47 - v46 > 0x10000 )
              v47 = v8 + 65537;
            if ( v47 != v8 )
            {
              v48 = 12i64 * v47;
              if ( !is_mul_ok(v47, 0xCui64) )
                v48 = -1i64;
              v49 = UFG::qMalloc(v48, "qArray.Add", 0i64);
              v50 = (__int64)v49;
              *(_QWORD *)&v2.x = v49;
              if ( v7 )
              {
                if ( v8 )
                {
                  v51 = v49;
                  v52 = (char *)v7 - (char *)v49;
                  v53 = v8;
                  do
                  {
                    LODWORD(v51->mNext) = *(_DWORD *)((char *)&v51->mNext + v52);
                    HIDWORD(v51->mNext) = *(_DWORD *)((char *)&v51->mNext + v52 + 4);
                    LODWORD(v51[1].mNext) = *(_DWORD *)((char *)&v51[1].mNext + v52);
                    v51 = (UFG::allocator::free_link *)((char *)v51 + 12);
                    --v53;
                  }
                  while ( v53 );
                }
                operator delete[](v7);
              }
              v7 = (UFG::SectionChooser::SectionLoad *)v50;
              v98 = v50;
              v9 = v47;
              HIDWORD(v97) = v47;
              v45 = v103;
            }
          }
          ++v8;
          LODWORD(v97) = v46;
          v27 = v45;
          v10 = v102;
          v7[v27].mGlobalIndex = v102;
          v7[v27].mLodLevel = SCENERY_LAYER_LOW;
          goto LABEL_122;
        }
        if ( v15 == 2 )
        {
          if ( (UFG::SectionChooser::mSectionInfo[v12].mSection->mFlags & 0x10) == 0
            && UFG::SectionChooser::meSuppressLOD != SUPRESS_ISLAND_AND_LOW )
          {
            v28 = v8;
            v103 = v8;
            v29 = v8 + 1;
            if ( v8 + 1 > v9 )
            {
              v30 = 1;
              if ( v9 )
                v30 = 2 * v9;
              for ( ; v30 < v29; v30 *= 2 )
                ;
              if ( v30 - v29 > 0x10000 )
                v30 = v8 + 65537;
              if ( v30 != v8 )
              {
                v31 = 12i64 * v30;
                if ( !is_mul_ok(v30, 0xCui64) )
                  v31 = -1i64;
                v32 = UFG::qMalloc(v31, "qArray.Add", 0i64);
                v33 = (__int64)v32;
                *(_QWORD *)&v2.x = v32;
                if ( v7 )
                {
                  if ( v8 )
                  {
                    v34 = v32;
                    v35 = (char *)v7 - (char *)v32;
                    v36 = v8;
                    do
                    {
                      LODWORD(v34->mNext) = *(_DWORD *)((char *)&v34->mNext + v35);
                      HIDWORD(v34->mNext) = *(_DWORD *)((char *)&v34->mNext + v35 + 4);
                      LODWORD(v34[1].mNext) = *(_DWORD *)((char *)&v34[1].mNext + v35);
                      v34 = (UFG::allocator::free_link *)((char *)v34 + 12);
                      --v36;
                    }
                    while ( v36 );
                  }
                  operator delete[](v7);
                }
                v7 = (UFG::SectionChooser::SectionLoad *)v33;
                v98 = v33;
                v9 = v30;
                HIDWORD(v97) = v30;
                v28 = v103;
              }
            }
            ++v8;
            LODWORD(v97) = v29;
            v37 = v28;
            v7[v37].mGlobalIndex = v102;
            v7[v37].mLodLevel = SCENERY_LAYER_LOW;
            v7[v37].mScore = v1.z;
          }
          v18 = v8;
          v103 = v8;
          v19 = v8 + 1;
          if ( v8 + 1 > v9 )
          {
            v38 = 1;
            if ( v9 )
              v38 = 2 * v9;
            for ( ; v38 < v19; v38 *= 2 )
              ;
            if ( v38 - v19 > 0x10000 )
              v38 = v8 + 65537;
            if ( v38 != v8 )
            {
              v39 = 12i64 * v38;
              if ( !is_mul_ok(v38, 0xCui64) )
                v39 = -1i64;
              v40 = UFG::qMalloc(v39, "qArray.Add", 0i64);
              v41 = (__int64)v40;
              *(_QWORD *)&v2.x = v40;
              if ( v7 )
              {
                if ( v8 )
                {
                  v42 = v40;
                  v43 = (char *)v7 - (char *)v40;
                  v44 = v8;
                  do
                  {
                    LODWORD(v42->mNext) = *(_DWORD *)((char *)&v42->mNext + v43);
                    HIDWORD(v42->mNext) = *(_DWORD *)((char *)&v42->mNext + v43 + 4);
                    LODWORD(v42[1].mNext) = *(_DWORD *)((char *)&v42[1].mNext + v43);
                    v42 = (UFG::allocator::free_link *)((char *)v42 + 12);
                    --v44;
                  }
                  while ( v44 );
                }
                operator delete[](v7);
              }
              v7 = (UFG::SectionChooser::SectionLoad *)v41;
              v98 = v41;
              v9 = v38;
              HIDWORD(v97) = v38;
              v18 = v103;
            }
          }
LABEL_58:
          v8 = v19;
          LODWORD(v97) = v19;
          v27 = v18;
          v10 = v102;
          v7[v27].mGlobalIndex = v102;
          v7[v27].mLodLevel = SCENERY_LAYER_STD;
LABEL_122:
          v7[v27].mScore = v1.z;
        }
      }
LABEL_123:
      v13[v12].meLODLevelCurrent.mValue = (char)v104;
      v11 = UFG::SectionChooser::mSectionCount;
      bFadeout = v101;
LABEL_124:
      v102 = ++v10;
    }
    v54 = 0i64;
    mem = 0i64;
    v55 = 0;
    v99 = 0i64;
    v56 = 0;
    v57 = 0;
    v102 = 0;
    v58 = UFG::SectionChooser::mZoneCount;
    if ( UFG::SectionChooser::mZoneCount )
    {
      v59 = UFG::SectionChooser::mZoneInfo;
      do
      {
        v60 = (unsigned __int64)v57 << 6;
        v61 = *(UFG::SCENERY_LAYER *)((char *)&v59->meLODLevelCurrent + v60);
        v62 = *(UFG::SCENERY_LAYER *)((char *)&v59->meLODLevelNew + v60);
        if ( v61 != v62 )
        {
          if ( v61 )
          {
            if ( v61 == 2 && !v62 && v59 )
            {
              UFG::DataStreamer::ReleaseStream((UFG::DataStreamer::Handle *)((char *)&v59->mhStreamHandleStdLOD + v60));
              *(&v59->mbStdLODLoaded + v60) = 0;
              v54 = mem;
              v57 = v102;
            }
          }
          else if ( v62 == 2 )
          {
            v63 = v55;
            v103 = v55;
            v64 = v55 + 1;
            if ( v55 + 1 > v56 )
            {
              v65 = 1;
              if ( v56 )
                v65 = 2 * v56;
              for ( ; v65 < v64; v65 *= 2 )
                ;
              if ( v65 <= 4 )
                v65 = 4;
              if ( v65 - v64 > 0x10000 )
                v65 = v55 + 65537;
              if ( v65 != v55 )
              {
                v66 = 4i64 * v65;
                if ( !is_mul_ok(v65, 4ui64) )
                  v66 = -1i64;
                v67 = UFG::qMalloc(v66, "qArray.Add", 0i64);
                v104 = v67;
                v68 = mem;
                if ( mem )
                {
                  if ( v55 )
                  {
                    v69 = v67;
                    v70 = (char *)((_BYTE *)mem - (_BYTE *)v67);
                    v71 = v55;
                    do
                    {
                      LODWORD(v69->mNext) = *(_DWORD *)((char *)&v69->mNext + (_QWORD)v70);
                      v69 = (UFG::allocator::free_link *)((char *)v69 + 4);
                      --v71;
                    }
                    while ( v71 );
                  }
                  operator delete[](v68);
                  v67 = v104;
                }
                v54 = v67;
                mem = v67;
                HIDWORD(v99) = v65;
                v57 = v102;
                v63 = v103;
              }
            }
            ++v55;
            LODWORD(v99) = v64;
            v54[v63] = v57;
          }
          *(UFG::SCENERY_LAYER *)((char *)&v59->meLODLevelCurrent + v60) = *(UFG::SCENERY_LAYER *)((char *)&v59->meLODLevelNew
                                                                                                 + v60);
          v58 = UFG::SectionChooser::mZoneCount;
          v59 = UFG::SectionChooser::mZoneInfo;
          v56 = HIDWORD(v99);
        }
        v102 = ++v57;
      }
      while ( v57 < v58 );
      v8 = v97;
    }
    if ( v8 )
    {
      p_mScore = &v7->mScore;
      v73 = v8;
      do
      {
        mOffset = UFG::gSectionLayout->mSections.mOffset;
        if ( mOffset )
          v75 = (char *)&UFG::gSectionLayout->mSections + mOffset;
        else
          v75 = 0i64;
        v76 = &v75[48 * *((unsigned int *)p_mScore - 2)];
        v77 = UFG::SectionChooser::mBSP->mSpaces.mOffset;
        if ( v77 )
          v78 = (char *)&UFG::SectionChooser::mBSP->mSpaces + v77;
        else
          v78 = 0i64;
        v79 = 10i64 * *((unsigned __int16 *)v76 + 3);
        v80 = *(float *)&v78[8 * v79 + 24];
        v81 = *(float *)&v78[8 * v79 + 20];
        x_low = (__m128)LODWORD(UFG::SectionChooser::mLookahead->mViewerPosition.x);
        x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] - v81) * (float)(x_low.m128_f32[0] - v81))
                          + (float)((float)(UFG::SectionChooser::mLookahead->mViewerPosition.y - v80)
                                  * (float)(UFG::SectionChooser::mLookahead->mViewerPosition.y - v80));
        v83 = _mm_sqrt_ps(x_low).m128_f32[0];
        y = UFG::SectionChooser::mLookahead->mViewerDirection.y;
        v1.x = UFG::SectionChooser::mLookahead->mViewerDirection.x;
        v1.y = y;
        v1.z = 0.0;
        v85 = v80 - UFG::SectionChooser::mLookahead->mViewerPosition.y;
        v2.x = v81 - UFG::SectionChooser::mLookahead->mViewerPosition.x;
        v2.y = v85;
        v2.z = 0.0;
        v86 = v83 + (float)((float)(UFG::qAngleBetween(&v1, &v2) * 0.31830987) * v83);
        if ( *((_DWORD *)p_mScore - 1) == 1 )
          v86 = v86 * 2.0;
        *p_mScore = v86;
        p_mScore += 3;
        --v73;
      }
      while ( v73 );
    }
    UFG::qQuickSortImpl<UFG::SectionChooser::SectionLoad,bool (*)(UFG::SectionChooser::SectionLoad const &,UFG::SectionChooser::SectionLoad const &)>(
      v7,
      &v7[(int)v8 - 1],
      UFG::SectionChooser::fnSectionStreamPriority);
    if ( v8 )
    {
      v87 = v7;
      v88 = v8;
      do
      {
        mGlobalIndex = v87->mGlobalIndex;
        v90 = UFG::gSectionLayout->mSections.mOffset;
        if ( v90 )
          v91 = (char *)&UFG::gSectionLayout->mSections + v90;
        else
          v91 = 0i64;
        if ( (v91[48 * mGlobalIndex + 4] & 4) != 0 )
          UFG::SectionChooser::QueueSectionLoad(mGlobalIndex, v87->mLodLevel);
        ++v87;
        --v88;
      }
      while ( v88 );
    }
    v92 = mem;
    if ( v55 )
    {
      v93 = (unsigned int *)mem;
      v94 = v55;
      do
      {
        UFG::SectionChooser::QueueZoneLoad(*v93++);
        --v94;
      }
      while ( v94 );
    }
    if ( v92 )
      operator delete[](v92);
    mem = 0i64;
    v99 = 0i64;
    if ( v7 )
      operator delete[](v7);
  }
}operator delete[](v92);
    mem = 0i64;
    v99 = 0i64;
    if ( v7 )
      operator delete[](v7);
  }
}

// File Line: 1568
// RVA: 0x233410
char __fastcall UFG::SectionChooser::LineInsideTriggerHull(
        UFG::CellTrigger *trigger,
        UFG::qVector3 *_start_position,
        UFG::qVector3 *_end_position,
        UFG::qVector3 *clippedPos)
{
  float z; // xmm0_4
  UFG::qVector3 *v6; // rax
  char v8; // r9
  float x; // xmm14_4
  float v10; // xmm12_4
  float y; // xmm13_4
  float v12; // xmm15_4
  __m128 x_low; // xmm7
  __m128 v14; // xmm1
  float v15; // xmm8_4
  float v16; // xmm2_4
  float v17; // xmm9_4
  float v18; // xmm10_4
  unsigned int mEdgeCount; // r13d
  char v20; // r15
  unsigned int v21; // r10d
  __int64 mOffset; // rbx
  __int64 v23; // rdi
  char *v24; // r11
  unsigned int v25; // ecx
  char *v26; // rax
  float v27; // xmm6_4
  float v28; // xmm5_4
  int v29; // r8d
  int v30; // r9d
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm4_4
  float v34; // xmm3_4
  bool v36; // zf
  float v37; // xmm0_4
  float v38; // [rsp+E0h] [rbp+8h]
  float v39; // [rsp+E4h] [rbp+Ch]

  z = _start_position->z;
  v6 = _end_position;
  if ( z < trigger->mMinHeight || z > trigger->mMaxHeight )
    return 0;
  v8 = 0;
  LOBYTE(v38) = 0;
  x = _end_position->x;
  v10 = _start_position->x;
  y = _start_position->y;
  x_low = (__m128)LODWORD(_end_position->x);
  v12 = _end_position->y;
  x_low.m128_f32[0] = x_low.m128_f32[0] - _start_position->x;
  v14 = x_low;
  v15 = v12 - y;
  v14.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v15 * v15);
  v16 = _mm_sqrt_ps(v14).m128_f32[0];
  if ( v16 <= 0.001 )
  {
    v17 = v39;
    v18 = v38;
  }
  else
  {
    v8 = 1;
    LOBYTE(v38) = 1;
    v17 = (float)(1.0 / v16) * x_low.m128_f32[0];
    LODWORD(v18) = COERCE_UNSIGNED_INT((float)(1.0 / v16) * v15) ^ _xmm[0];
  }
  mEdgeCount = trigger->mEdgeCount;
  v20 = 0;
  v21 = 0;
  if ( mEdgeCount )
  {
    mOffset = trigger->mEdges.mOffset;
    v23 = 0i64;
    while ( 1 )
    {
      if ( mOffset )
        v24 = (char *)&trigger->mEdges + mOffset;
      else
        v24 = 0i64;
      v25 = 0;
      if ( v21 != mEdgeCount - 1 )
        v25 = v21 + 1;
      v26 = mOffset ? (char *)&trigger->mEdges + mOffset : 0i64;
      v27 = *(float *)&v24[v23];
      v28 = *(float *)&v24[v23 + 4];
      v29 = 0;
      LOBYTE(v29) = (float)((float)(*(float *)&v24[v23 + 8] * (float)(v10 - v27))
                          + (float)(*(float *)&v24[v23 + 12] * (float)(y - v28))) <= 0.0;
      if ( v8 )
      {
        v30 = 0;
        LOBYTE(v30) = (float)((float)(*(float *)&v24[v23 + 8] * (float)(x - v27))
                            + (float)(*(float *)&v24[v23 + 12] * (float)(v12 - v28))) <= 0.0;
      }
      else
      {
        v30 = v29;
      }
      if ( v29 == v30 )
      {
        if ( v29 != 1 )
          return 0;
      }
      else if ( (float)((float)((float)(v28 - y) * v17) + (float)((float)(v27 - v10) * v18)) <= 0.0 == (float)((float)((float)(*(float *)&v26[16 * v25 + 4] - y) * v17) + (float)((float)(*(float *)&v26[16 * v25] - v10) * v18)) <= 0.0 )
      {
        v20 = 1;
      }
      else
      {
        if ( !clippedPos )
          return 1;
        if ( v29 == 1 && !v30 )
        {
          v31 = *(float *)&v24[v23 + 8];
          v32 = *(float *)&v24[v23 + 12];
          v33 = (float)(v31 * x_low.m128_f32[0]) + (float)(v32 * v15);
          v34 = (float)(v31 * (float)(*(float *)&v24[v23] - v10)) + (float)(v32 * (float)(*(float *)&v24[v23 + 4] - y));
          clippedPos->z = _start_position->z;
          clippedPos->x = (float)((float)(x_low.m128_f32[0] * v34) * (float)(1.0 / v33)) + v10;
          clippedPos->y = (float)((float)(v15 * v34) * (float)(1.0 / v33)) + y;
          return 1;
        }
      }
      ++v21;
      v23 += 16i64;
      if ( v21 >= mEdgeCount )
        break;
      v8 = LOBYTE(v38);
    }
    v36 = v20 == 0;
    if ( v20 )
      return v36;
    v6 = _end_position;
  }
  if ( clippedPos )
  {
    v37 = v6->z;
    clippedPos->x = x;
    clippedPos->y = v12;
    clippedPos->z = v37;
  }
  return 1;
}  }
  if ( clippedPos )
  {
    v37 = v6->z;
    clippedPos->x = x;
    clippedPos->y = v12;
    clipp

// File Line: 1715
// RVA: 0x233BD0
void __fastcall UFG::SectionChooser::ModifyVisibliltyFromTriggersForPosition(
        UFG::qVector3 *pov_position,
        UFG::qVector3 *lookahead_position,
        int _pov_section_index,
        int _lookahead_section_index,
        unsigned int *STDSectionCount,
        unsigned int *STDVisIndices,
        unsigned int *LODSectionCount,
        unsigned int *LODVisIndices)
{
  UFG::qVector3 *v8; // r10
  unsigned int v9; // r13d
  int *v11; // rcx
  UFG::SectionLayout *v12; // rdx
  __int64 mOffset; // rax
  __int64 v14; // r8
  __int64 v15; // rax
  __int64 v16; // rcx
  __int64 v17; // r8
  __int64 v18; // rcx
  __int64 v19; // rax
  __int64 v20; // rdi
  __int64 v21; // r12
  __int64 v22; // rbx
  float x; // xmm3_4
  float y; // xmm2_4
  float z; // xmm0_4
  unsigned int v26; // r9d
  unsigned int v27; // edx
  __int64 v28; // r8
  __int64 v29; // rcx
  __int64 v30; // rax
  __int64 v31; // rdx
  __int64 v32; // rcx
  unsigned int v33; // eax
  unsigned int *v34; // rdx
  unsigned int v35; // ecx
  bool v36; // zf
  unsigned int v37; // edx
  int v38[2]; // [rsp+20h] [rbp-58h] BYREF
  int *v39; // [rsp+28h] [rbp-50h]
  __int64 v40; // [rsp+30h] [rbp-48h]

  v8 = lookahead_position;
  v9 = ++sVisitMagic;
  if ( _pov_section_index == _lookahead_section_index )
  {
    v38[0] = _pov_section_index;
  }
  else
  {
    v38[0] = _lookahead_section_index;
    v38[1] = _pov_section_index;
  }
  if ( (_pov_section_index != _lookahead_section_index) != -1 )
  {
    v11 = v38;
    v40 = (unsigned int)(_pov_section_index != _lookahead_section_index) + 1;
    v12 = UFG::gSectionLayout;
    v39 = v38;
    while ( 1 )
    {
      mOffset = v12->mSections.mOffset;
      v14 = mOffset ? (__int64)&v12->mSections + mOffset : 0i64;
      v15 = v12->mSectionVis.mOffset;
      v16 = v14 + 48i64 * (unsigned int)*v11;
      v17 = v15 ? (__int64)&v12->mSectionVis + v15 : 0i64;
      v18 = 96i64 * *(unsigned __int16 *)(v16 + 6);
      v19 = *(_QWORD *)(v18 + v17 + 40);
      v20 = v19 ? v19 + v18 + v17 + 40 : 0i64;
      if ( *(_WORD *)(v18 + v17 + 26) )
        break;
LABEL_55:
      v11 = v39 + 1;
      v36 = v40-- == 1;
      ++v39;
      if ( v36 )
        return;
    }
    v21 = *(unsigned __int16 *)(v18 + v17 + 26);
    while ( 1 )
    {
      if ( *(_QWORD *)v20 )
        v22 = *(_QWORD *)v20 + v20;
      else
        v22 = 0i64;
      if ( *(_DWORD *)(v22 + 76) != v9 )
      {
        v36 = *(_DWORD *)(v22 + 96) == 0;
        *(_DWORD *)(v22 + 76) = v9;
        if ( v36 )
        {
          if ( UFG::SectionChooser::LineInsideTriggerHull((UFG::CellTrigger *)v22, pov_position, v8, 0i64) )
            goto LABEL_37;
        }
        else
        {
          x = pov_position->x;
          y = pov_position->y;
          if ( pov_position->x >= *(float *)(v22 + 8)
            && x <= *(float *)(v22 + 16)
            && y >= *(float *)(v22 + 12)
            && y <= *(float *)(v22 + 20) )
          {
            z = pov_position->z;
            if ( z > *(float *)(v22 + 84) && z < *(float *)(v22 + 88) )
            {
              v26 = *(_DWORD *)(v22 + 24);
              v27 = 0;
              if ( v26 )
              {
                v28 = *(_QWORD *)(v22 + 32);
                v29 = 0i64;
                do
                {
                  v30 = v28 ? v28 + v22 + 32 : 0i64;
                  if ( (float)((float)((float)(y - *(float *)(v29 + v30 + 4)) * *(float *)(v29 + v30 + 12))
                             + (float)((float)(x - *(float *)(v29 + v30)) * *(float *)(v29 + v30 + 8))) > 0.0 )
                    goto LABEL_53;
                  ++v27;
                  v29 += 16i64;
                }
                while ( v27 < v26 );
              }
LABEL_37:
              v31 = *STDSectionCount;
              v32 = 0i64;
              if ( (_DWORD)v31 )
              {
                while ( STDVisIndices[v32] != *(_DWORD *)(v20 + 8) )
                {
                  v32 = (unsigned int)(v32 + 1);
                  if ( (unsigned int)v32 >= (unsigned int)v31 )
                    goto LABEL_40;
                }
                v37 = *(_DWORD *)(v22 + 72);
                if ( *STDVisIndices != v37 )
                  STDVisIndices[v32] = v37;
              }
              else
              {
LABEL_40:
                if ( (unsigned int)v31 < 7 )
                {
                  STDVisIndices[v31] = *(_DWORD *)(v22 + 72);
                  ++*STDSectionCount;
                }
              }
              v33 = 0;
              if ( *LODSectionCount )
              {
                v34 = LODVisIndices;
                while ( 1 )
                {
                  v35 = *v34;
                  v36 = gExtendedMidground ? v35 == *(_DWORD *)(v20 + 16) : v35 == *(_DWORD *)(v20 + 12);
                  if ( v36 )
                    break;
                  ++v33;
                  ++v34;
                  if ( v33 >= *LODSectionCount )
                    goto LABEL_53;
                }
                LODVisIndices[v33] = *(_DWORD *)(v20 + 8);
              }
            }
          }
        }
      }
LABEL_53:
      v8 = lookahead_position;
      v20 += 32i64;
      if ( !--v21 )
      {
        v12 = UFG::gSectionLayout;
        goto LABEL_55;
      }
    }
  }
}

// File Line: 1823
// RVA: 0x233AA0
void __fastcall UFG::SectionChooser::ModifyLookaheadForStickyTriggers(
        int _vis_index_current_section,
        int _vis_index_lookahead_section,
        UFG::qVector3 *viewerPosition,
        UFG::qVector3 *currentLookaheadPos)
{
  unsigned int v5; // ebp
  int *v7; // r14
  __int64 v8; // r15
  __int64 mOffset; // rcx
  char *v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // rax
  char *v13; // rbx
  __int64 v14; // rsi
  UFG::CellTrigger *v15; // rcx
  float y; // xmm1_4
  float z; // xmm0_4
  int v18[2]; // [rsp+20h] [rbp-38h] BYREF
  UFG::qVector3 clippedPos; // [rsp+28h] [rbp-30h] BYREF

  v5 = sVisitMagic_0 + 1;
  v18[0] = _vis_index_current_section;
  v18[1] = _vis_index_lookahead_section;
  ++sVisitMagic_0;
  if ( (_vis_index_current_section != _vis_index_lookahead_section) != -1 )
  {
    v7 = v18;
    v8 = (unsigned int)(_vis_index_current_section != _vis_index_lookahead_section) + 1;
    do
    {
      mOffset = UFG::gSectionLayout->mSectionVis.mOffset;
      if ( mOffset )
        v10 = (char *)&UFG::gSectionLayout->mSectionVis + mOffset;
      else
        v10 = 0i64;
      v11 = 96i64 * (unsigned int)*v7;
      v12 = *(_QWORD *)&v10[v11 + 40];
      if ( v12 )
        v13 = &v10[v11 + 40 + v12];
      else
        v13 = 0i64;
      if ( *(_WORD *)&v10[v11 + 26] )
      {
        v14 = *(unsigned __int16 *)&v10[v11 + 26];
        do
        {
          if ( *(_QWORD *)v13 )
            v15 = (UFG::CellTrigger *)&v13[*(_QWORD *)v13];
          else
            v15 = 0i64;
          if ( v15->mIsSticky && v15->mMagic1 != v5 )
          {
            v15->mMagic1 = v5;
            if ( UFG::SectionChooser::LineInsideTriggerHull(v15, viewerPosition, currentLookaheadPos, &clippedPos) )
            {
              y = clippedPos.y;
              currentLookaheadPos->x = clippedPos.x;
              z = clippedPos.z;
              currentLookaheadPos->y = y;
              currentLookaheadPos->z = z;
            }
          }
          v13 += 32;
          --v14;
        }
        while ( v14 );
      }
      ++v7;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 1868
// RVA: 0x233EC0
__int64 __fastcall UFG::SectionChooser::ModifyZonesFromTriggersForPosition(
        UFG::qVector3 *position,
        unsigned int vis_index_chooser_section,
        unsigned int zoneCount,
        unsigned int *mZoneIndices)
{
  __int64 mOffset; // r8
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 *v10; // rbx
  unsigned int v11; // eax
  __int64 v12; // rdi
  __int64 v13; // rax
  float x; // xmm3_4
  float y; // xmm2_4
  unsigned int v16; // r11d
  unsigned int v17; // r8d
  __int64 v18; // r9
  __int64 v19; // rdx
  __int64 v20; // rcx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int *v23; // rax

  mOffset = UFG::gSectionLayout->mSectionVis.mOffset;
  if ( mOffset )
    mOffset += (__int64)&UFG::gSectionLayout->mSectionVis;
  v8 = 96i64 * vis_index_chooser_section;
  v9 = *(_QWORD *)(v8 + mOffset + 56);
  if ( v9 )
    v10 = (__int64 *)(v9 + mOffset + v8 + 56);
  else
    v10 = 0i64;
  v11 = *(_DWORD *)(v8 + mOffset + 64);
  if ( v11 )
  {
    v12 = v11;
    do
    {
      v13 = *v10;
      if ( *v10 )
        v13 += (__int64)v10;
      x = position->x;
      y = position->y;
      if ( position->x >= *(float *)(v13 + 8)
        && x <= *(float *)(v13 + 16)
        && y >= *(float *)(v13 + 12)
        && y <= *(float *)(v13 + 20) )
      {
        v16 = *(_DWORD *)(v13 + 24);
        v17 = 0;
        if ( v16 )
        {
          v18 = *(_QWORD *)(v13 + 32);
          v19 = 0i64;
          while ( 1 )
          {
            v20 = v18 ? v18 + v13 + 32 : 0i64;
            if ( (float)((float)((float)(y - *(float *)(v19 + v20 + 4)) * *(float *)(v19 + v20 + 12))
                       + (float)((float)(x - *(float *)(v19 + v20)) * *(float *)(v19 + v20 + 8))) > 0.0 )
              break;
            ++v17;
            v19 += 16i64;
            if ( v17 >= v16 )
              goto LABEL_21;
          }
        }
        else
        {
LABEL_21:
          v21 = *(_DWORD *)(v13 + 72);
          if ( v21 != -1 )
          {
            v22 = 0;
            if ( zoneCount )
            {
              v23 = mZoneIndices;
              while ( *v23 != v21 )
              {
                ++v22;
                ++v23;
                if ( v22 >= zoneCount )
                  goto LABEL_26;
              }
            }
            else
            {
LABEL_26:
              mZoneIndices[1] = v21;
              zoneCount = 2;
            }
          }
        }
      }
      ++v10;
      --v12;
    }
    while ( v12 );
  }
  return zoneCount;
}

// File Line: 1931
// RVA: 0x230320
void __fastcall UFG::SectionChooser::AddPOV(
        UFG::qVector3 *position,
        UFG::qVector3 *direction,
        UFG::qVector3 *camera_direction,
        UFG::qVector3 *velocity,
        float deltaTime,
        UFG::SimObject *simObject,
        char flags,
        bool is_ingame)
{
  bool v9; // bl
  char v10; // r13
  bool v11; // al
  int v12; // ebp
  unsigned int v13; // r15d
  unsigned int v14; // r14d
  UFG::SectionChooser::SectionInfo *v15; // rsi
  unsigned __int64 v16; // rdi
  bool v17; // zf
  UFG::SectionChooser::SectionInfo *v18; // rbx
  UFG::SectionChooser::SectionInfo *v19; // rbx
  UFG::BSP *v20; // r14
  unsigned int mSectionIndex; // esi
  unsigned int CellToLoadFromVisIndex; // eax
  UFG::SectionLayout *v23; // rbp
  __int64 mOffset; // rcx
  char *v25; // rcx
  char *v26; // rbx
  __int64 v27; // r13
  float v28; // xmm2_4
  float mCurrentLookaheadDistance; // xmm6_4
  float x; // xmm10_4
  float y; // xmm11_4
  float z; // xmm12_4
  float v33; // xmm7_4
  __m128 y_low; // xmm8
  float v35; // xmm9_4
  __m128 v36; // xmm3
  float v37; // xmm7_4
  float v38; // xmm8_4
  float v39; // xmm9_4
  float v40; // xmm0_4
  int v41; // r12d
  int v42; // edi
  float v43; // xmm6_4
  unsigned int v44; // ebx
  bool v45; // di
  unsigned int v46; // eax
  UFG::SectionChooser *v47; // rcx
  __int64 v48; // rcx
  char *v49; // rdx
  int v50; // eax
  __int64 v51; // rcx
  char *v52; // rdx
  __int64 v53; // rax
  __int64 v54; // rcx
  unsigned int v55; // edx
  __int64 v56; // r8
  __int64 v57; // r9
  __int64 v58; // rcx
  __int64 v59; // rax
  char *v60; // rcx
  unsigned int baseSectionIndex; // [rsp+40h] [rbp-C8h]
  bool v62; // [rsp+44h] [rbp-C4h]
  UFG::qVector3 positiona; // [rsp+48h] [rbp-C0h] BYREF
  UFG::qVector3 *v64; // [rsp+118h] [rbp+10h]
  UFG::qVector3 *v65; // [rsp+120h] [rbp+18h]
  UFG::qVector3 *v66; // [rsp+128h] [rbp+20h]
  bool flagsa[8]; // [rsp+140h] [rbp+38h]

  v66 = velocity;
  v65 = camera_direction;
  v64 = direction;
  v9 = (flags & 4) != 0;
  v10 = flags & 1;
  v11 = (flags & 2) != 0;
  flagsa[0] = v9;
  v62 = v11;
  if ( UFG::SectionChooser::mBSP )
  {
    v12 = UFG::SectionChooser::SectionInfo::smStateCount[2][3] + UFG::SectionChooser::SectionInfo::smStateCount[1][3];
    v13 = 0;
    v14 = 0;
    if ( UFG::SectionChooser::mSectionCount )
    {
      do
      {
        if ( v12 <= 0 )
          break;
        v15 = UFG::SectionChooser::mSectionInfo;
        v16 = v14;
        if ( UFG::SectionChooser::mSectionInfo[v16].meLoadStateMID.mValue == 3 )
        {
          v17 = UFG::SectionChooser::mSectionInfo[v16].mUnloadCountLow-- == 1;
          if ( v17 )
          {
            v18 = UFG::SectionChooser::mSectionInfo;
            UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo[v16].mhStreamHandleMID);
            v18[v16].mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
            --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)v18[v16].meLoadStateMID.mValue];
            ++UFG::SectionChooser::SectionInfo::smStateCount[1][0];
            v18[v16].meLoadStateMID.mValue = 0;
            v18[v16].mUnloadCountLow = 5;
            v18[v16].mbFlushing = 0;
          }
          --v12;
        }
        if ( v15[v16].meLoadStateSTD.mValue == 3 )
        {
          v17 = v15[v16].mUnloadCountStd-- == 1;
          if ( v17 )
          {
            v19 = UFG::SectionChooser::mSectionInfo;
            UFG::DataStreamer::ReleaseStream(&UFG::SectionChooser::mSectionInfo[v16].mhStreamHandleSTD);
            UFG::DataStreamer::ReleaseStream(&v19[v16].mhStreamHandleGAM);
            v19[v16].mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
            --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v19[v16].meLoadStateSTD.mValue];
            ++UFG::SectionChooser::SectionInfo::smStateCount[2][0];
            v19[v16].meLoadStateSTD.mValue = 0;
            v19[v16].mUnloadCountStd = 5;
            *(_WORD *)&v19[v16].mbLoadedGAM = 0;
          }
          --v12;
        }
        ++v14;
      }
      while ( v14 < UFG::SectionChooser::mSectionCount );
      v9 = flagsa[0];
      velocity = v66;
      camera_direction = v65;
      direction = v64;
    }
    ((void (__fastcall *)(UFG::SectionChooser::Lookahead *, UFG::qVector3 *, UFG::qVector3 *, UFG::qVector3 *, UFG::qVector3 *, _DWORD, char))UFG::SectionChooser::mLookahead->vfptr->Process)(
      UFG::SectionChooser::mLookahead,
      position,
      direction,
      camera_direction,
      velocity,
      LODWORD(deltaTime),
      v10);
    v20 = UFG::SectionChooser::mBSP;
    if ( UFG::SectionChooser::mBSP )
      mSectionIndex = UFG::BSP::GetSpaceFromPoint(UFG::SectionChooser::mBSP, position, 1, 1)->mSectionIndex;
    else
      mSectionIndex = -1;
    CellToLoadFromVisIndex = UFG::SectionChooser::GetCellToLoadFromVisIndex(mSectionIndex, v9);
    v23 = UFG::gSectionLayout;
    mCurrentCellIndex = CellToLoadFromVisIndex;
    mOffset = UFG::gSectionLayout->mSections.mOffset;
    baseSectionIndex = CellToLoadFromVisIndex;
    if ( mOffset )
      v25 = (char *)&UFG::gSectionLayout->mSections + mOffset;
    else
      v25 = 0i64;
    v26 = &v25[48 * CellToLoadFromVisIndex];
    if ( is_ingame )
    {
      UFG::ZoneTag::Update(mSectionIndex);
      v20 = UFG::SectionChooser::mBSP;
      v23 = UFG::gSectionLayout;
    }
    v27 = mSectionIndex;
    if ( (v26[4] & 2) != 0 )
    {
      v45 = flagsa[0];
    }
    else
    {
      v28 = 0.0;
      mCurrentLookaheadDistance = UFG::SectionChooser::mLookahead->mCurrentLookaheadDistance;
      y_low = (__m128)LODWORD(UFG::SectionChooser::mLookahead->mCurrentLookaheadPos.y);
      x = position->x;
      y = position->y;
      z = position->z;
      v33 = UFG::SectionChooser::mLookahead->mCurrentLookaheadPos.x - position->x;
      y_low.m128_f32[0] = y_low.m128_f32[0] - y;
      v35 = UFG::SectionChooser::mLookahead->mCurrentLookaheadPos.z - z;
      v36 = y_low;
      v36.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v33 * v33))
                      + (float)(v35 * v35);
      if ( v36.m128_f32[0] != 0.0 )
        v28 = 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
      v37 = v33 * v28;
      v38 = y_low.m128_f32[0] * v28;
      v39 = v35 * v28;
      v40 = FLOAT_5_0;
      if ( (float)(int)(float)(mCurrentLookaheadDistance * 0.1) <= 5.0 )
        v40 = (float)(int)(float)(mCurrentLookaheadDistance * 0.1);
      v41 = (int)v40;
      v42 = 1;
      if ( (int)v40 )
      {
        v43 = mCurrentLookaheadDistance / (float)v41;
        while ( 1 )
        {
          positiona.x = (float)((float)(v37 * (float)v42) * v43) + x;
          positiona.y = (float)((float)(v38 * (float)v42) * v43) + y;
          positiona.z = (float)((float)(v39 * (float)v42) * v43) + z;
          v44 = v20 ? UFG::BSP::GetSpaceFromPoint(v20, &positiona, 1, 0)->mSectionIndex : -1;
          if ( v44 != mSectionIndex )
            break;
          if ( ++v42 > (unsigned int)v41 )
          {
            v45 = flagsa[0];
            goto LABEL_35;
          }
        }
        v45 = flagsa[0];
        v50 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v44, flagsa[0]);
        v51 = v23->mSections.mOffset;
        if ( v51 )
          v52 = (char *)&v23->mSections + v51;
        else
          v52 = 0i64;
        if ( (v52[48 * v50 + 4] & 2) == 0 )
        {
          v53 = v23->mSectionVis.mOffset;
          v54 = v53 ? (__int64)&v23->mSectionVis + v53 : 0i64;
          v55 = 0;
          v56 = v54 + 96i64 * v44;
          if ( *(_WORD *)(v56 + 4) )
          {
            v57 = *(_QWORD *)(v56 + 8);
            v58 = 0i64;
            while ( 1 )
            {
              v59 = v57 ? v57 + v56 + 8 : 0i64;
              if ( *(unsigned __int16 *)(v58 + v59) == mSectionIndex )
                break;
              ++v55;
              v58 += 2i64;
              if ( v55 >= *(unsigned __int16 *)(v56 + 4) )
                goto LABEL_35;
            }
            v27 = v44;
          }
        }
      }
      else
      {
        v45 = flagsa[0];
      }
    }
LABEL_35:
    UFG::SectionChooser::ModifyLookaheadForStickyTriggers(
      mSectionIndex,
      v27,
      &UFG::SectionChooser::mLookahead->mViewerPosition,
      &UFG::SectionChooser::mLookahead->mCurrentLookaheadPos);
    if ( !UFG::SectionLayout::IsLookaheadAllowed(mSectionIndex, v27) )
      v27 = mSectionIndex;
    v46 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v27, v45);
    UFG::SectionChooser::CalculateVisibleSectionIndices(baseSectionIndex, v46, v45);
    if ( UFG::SectionChooser::mCaptureFarGroundImposters )
    {
      UFG::SectionChooser::mSTDZoneCount = 0;
    }
    else
    {
      v48 = UFG::gSectionLayout->mSectionVis.mOffset;
      if ( v48 )
        v49 = (char *)&UFG::gSectionLayout->mSectionVis + v48;
      else
        v49 = 0i64;
      v60 = &v49[96 * v27];
      UFG::SectionChooser::mSTDZoneIndices[0] = *((unsigned __int16 *)v60 + 26);
      if ( *((_WORD *)v60 + 26) != 0xFFFF )
        v13 = 1;
      dword_1423A8D94 = *((unsigned __int16 *)v60 + 27);
      if ( *((_WORD *)v60 + 27) != 0xFFFF )
        ++v13;
      UFG::SectionChooser::mSTDZoneCount = v13;
      UFG::SectionChooser::mSTDZoneCount = UFG::SectionChooser::ModifyZonesFromTriggersForPosition(
                                             &UFG::SectionChooser::mLookahead->mCurrentLookaheadPos,
                                             v27,
                                             v13,
                                             UFG::SectionChooser::mSTDZoneIndices);
    }
    UFG::SectionChooser::HandleFlush(v47);
    UFG::SectionChooser::UpdateStreams(v62);
  }
}

// File Line: 2079
// RVA: 0x230AA0
void __fastcall UFG::SectionChooser::CalculateVisibleSectionIndices(
        unsigned int baseSectionIndex,
        unsigned int currentSectionIndex,
        bool keepCurrentlyLoadedAltLayers)
{
  __int64 v3; // rbx
  __int64 v5; // rsi
  __int64 mOffset; // r8
  char *v8; // rdx
  unsigned int v9; // edi
  unsigned int HighLODSectionVisIndices; // eax
  unsigned int LowLODSectionVisIndices_HD; // eax
  unsigned int v12; // r10d
  unsigned int v13; // esi
  UFG::SectionChooser::SectionInfo *v14; // r11
  unsigned int *v15; // rdx
  signed __int64 v16; // r9
  __int64 v17; // r8
  __int64 v18; // rax
  __int64 v19; // rdi
  __int64 v20; // rbp
  unsigned int CellToLoadFromVisIndex; // eax
  __int64 v22; // rdi
  int v23; // eax

  v3 = 0i64;
  v5 = currentSectionIndex;
  mSTDSectionCount = 0;
  if ( UFG::SectionChooser::mCaptureFarGroundImposters )
  {
    v13 = UFG::SectionChooser::mNumCaptureSectionIndices;
    v12 = 0;
    mLOWSectionCount = UFG::SectionChooser::mNumCaptureSectionIndices;
    if ( UFG::SectionChooser::mNumCaptureSectionIndices )
    {
      v14 = UFG::SectionChooser::mSectionInfo;
      v15 = mLOWSectionVisIndices;
      v16 = (char *)UFG::SectionChooser::mCaptureSectionIndices - (char *)mLOWSectionVisIndices;
      v17 = UFG::SectionChooser::mNumCaptureSectionIndices;
      do
      {
        v18 = *(unsigned int *)((char *)v15++ + v16);
        *(v15 - 1) = v14[v18].mSection->mVisIndex;
        --v17;
      }
      while ( v17 );
    }
  }
  else
  {
    mOffset = UFG::gSectionLayout->mSections.mOffset;
    if ( mOffset )
      v8 = (char *)&UFG::gSectionLayout->mSections + mOffset;
    else
      v8 = 0i64;
    v9 = *(unsigned __int16 *)&v8[48 * v5 + 6];
    HighLODSectionVisIndices = UFG::SectionLayout::GetHighLODSectionVisIndices(v9, mSTDSectionVisIndices, 0x40u);
    mLOWSectionCount = 0;
    mSTDSectionCount = HighLODSectionVisIndices;
    if ( gExtendedMidground )
      LowLODSectionVisIndices_HD = UFG::SectionLayout::GetLowLODSectionVisIndices_HD(v9, mLOWSectionVisIndices, 64u);
    else
      LowLODSectionVisIndices_HD = UFG::SectionLayout::GetLowLODSectionVisIndices(v9, mLOWSectionVisIndices, 64u);
    mLOWSectionCount = LowLODSectionVisIndices_HD;
    UFG::SectionChooser::ModifyVisibliltyFromTriggersForPosition(
      &UFG::SectionChooser::mLookahead->mViewerPosition,
      &UFG::SectionChooser::mLookahead->mCurrentLookaheadPos,
      baseSectionIndex,
      v5,
      &mSTDSectionCount,
      mSTDSectionVisIndices,
      &mLOWSectionCount,
      mLOWSectionVisIndices);
    v12 = mSTDSectionCount;
    v13 = mLOWSectionCount;
  }
  if ( v12 )
  {
    v19 = 0i64;
    v20 = v12;
    do
    {
      CellToLoadFromVisIndex = UFG::SectionChooser::GetCellToLoadFromVisIndex(
                                 mSTDSectionVisIndices[v19++],
                                 keepCurrentlyLoadedAltLayers);
      mSTDSectionVisIndices[v19 + 63] = CellToLoadFromVisIndex;
      --v20;
    }
    while ( v20 );
  }
  if ( v13 )
  {
    v22 = v13;
    do
    {
      v23 = UFG::SectionChooser::GetCellToLoadFromVisIndex(mLOWSectionVisIndices[v3++], keepCurrentlyLoadedAltLayers);
      *(_DWORD *)(&UFG::SectionEditor::mUsePlayerAsSectionPOV + v3 * 4) = v23;
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 2136
// RVA: 0x232600
__int64 __fastcall UFG::SectionChooser::GetCurrentSectionIndex()
{
  return mCurrentCellIndex;
}

// File Line: 2178
// RVA: 0x2316D0
void __fastcall UFG::SectionChooser::FlushAltLayer(const char *layer_name, bool layer_enabled)
{
  unsigned int LayerIndex; // edi
  UFG::SectionLayout *v4; // rbp
  __int64 v5; // r15
  char *v6; // r14
  __int64 mOffset; // rax
  char *v8; // rdx
  __int64 v9; // rax
  __int64 v10; // r8
  char *v11; // rdx
  char *v12; // rcx
  __int64 v13; // rax
  char *v14; // rdx
  __int64 v15; // rbx
  unsigned int v16; // ecx
  char *v17; // rax
  char *v18; // rdx
  __int64 v19; // r10
  UFG::SectionChooser::SectionInfo *v20; // rax
  __int64 v21; // r8
  int mValue; // r9d
  char Dst[4]; // [rsp+20h] [rbp-118h] BYREF
  char v24[124]; // [rsp+24h] [rbp-114h] BYREF
  char dest[128]; // [rsp+A0h] [rbp-98h] BYREF

  LayerIndex = UFG::SectionLayout::GetLayerIndex(layer_name);
  if ( LayerIndex != -1 )
  {
    UFG::qMemCopy(dest, mSTDSectionCellIndices, 4 * mSTDSectionCount);
    if ( mSTDSectionCount )
    {
      v4 = UFG::gSectionLayout;
      v5 = mSTDSectionCount;
      v6 = dest;
      do
      {
        mOffset = v4->mSections.mOffset;
        if ( mOffset )
          v8 = (char *)&v4->mSections + mOffset;
        else
          v8 = 0i64;
        v9 = v4->mSectionVis.mOffset;
        v10 = *(unsigned __int16 *)&v8[48 * *(unsigned int *)v6 + 6];
        if ( v9 )
          v11 = (char *)&v4->mSectionVis + v9;
        else
          v11 = 0i64;
        v12 = &v11[96 * v10];
        v13 = *((_QWORD *)v12 + 4);
        if ( v13 )
          v14 = &v12[v13 + 32];
        else
          v14 = 0i64;
        v15 = *((unsigned __int16 *)v12 + 12);
        if ( *((_WORD *)v12 + 12) )
          memmove(Dst, v14, 8i64 * *((unsigned __int16 *)v12 + 12));
        v16 = 0;
        if ( (_DWORD)v15 )
        {
          v17 = v24;
          while ( *(_DWORD *)v17 != LayerIndex )
          {
            ++v16;
            v17 += 8;
            if ( v16 >= (unsigned int)v15 )
              goto LABEL_33;
          }
          v18 = v24;
          v19 = v15;
          do
          {
            v20 = UFG::SectionChooser::mSectionInfo;
            v21 = *((unsigned int *)v18 - 1);
            mValue = (unsigned __int8)UFG::SectionChooser::mSectionInfo[v21].meLoadStateSTD.mValue;
            if ( (unsigned int)(mValue - 1) <= 1 )
            {
              UFG::SectionChooser::mSectionInfo[v21].mbFlushing = !layer_enabled || *(_DWORD *)v18 != LayerIndex;
            }
            else if ( mValue == 3 )
            {
              if ( layer_enabled )
              {
                if ( *(_DWORD *)v18 == LayerIndex )
                {
                  UFG::SectionChooser::mSectionInfo[v21].mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
                  --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)v20[v21].meLoadStateSTD.mValue];
                  ++UFG::SectionChooser::SectionInfo::smStateCount[2][2];
                  v20[v21].meLoadStateSTD.mValue = 2;
                  v20[v21].mUnloadCountStd = 5;
                  UFG::SectionChooser::mSectionInfo[v21].mbFlushing = 0;
                }
                else
                {
                  UFG::SectionChooser::mSectionInfo[v21].mbFlushing = 1;
                }
              }
              else
              {
                UFG::SectionChooser::mSectionInfo[v21].mbFlushing = 1;
              }
            }
            v18 += 8;
            --v19;
          }
          while ( v19 );
          v4 = UFG::gSectionLayout;
        }
LABEL_33:
        v6 += 4;
        --v5;
      }
      while ( v5 );
    }
  }
}

// File Line: 2275
// RVA: 0x235170
void __fastcall UFG::SectionChooser::SetSuppressLOD(UFG::SectionChooser::LOD_SUPRESSION eSuppressLOD)
{
  UFG::SectionChooser::LOD_SUPRESSION v1; // eax

  v1 = UFG::SectionChooser::meSuppressLOD;
  if ( UFG::SectionChooser::meSuppressLOD != SUPRESS_ISLAND_AND_LOW )
    v1 = eSuppressLOD;
  UFG::SectionChooser::meSuppressLOD = v1;
}

// File Line: 2311
// RVA: 0x2315B0
void __fastcall UFG::SectionChooser::EnableStreamsUpdate(bool enable)
{
  UFG::SectionChooser::mStreamsUpdateEnabled = enable;
}

// File Line: 2316
// RVA: 0x2315A0
void __fastcall UFG::SectionChooser::EnableStreamingLookahead(bool enable)
{
  UFG::SectionChooser::mLookahead->mEnabled = enable;
}

// File Line: 2321
// RVA: 0x232B40
bool __fastcall UFG::SectionChooser::GetSTDStreamingStateForSectionIndex(unsigned int section_index)
{
  UFG::SectionChooser::SectionInfo *v1; // rdx

  v1 = &UFG::SectionChooser::mSectionInfo[section_index];
  return v1->meLoadStateSTD.mValue == 2 && v1->mChangedStateFrameStamp[2] < UFG::Metrics::msFrameCount - 2;
}

// File Line: 2332
// RVA: 0x232AF0
bool __fastcall UFG::SectionChooser::GetMIDStreamingStateForSectionIndex(unsigned int section_index)
{
  UFG::SectionChooser::SectionInfo *v1; // rdx

  v1 = &UFG::SectionChooser::mSectionInfo[section_index];
  return v1->meLoadStateMID.mValue == 2 && v1->mChangedStateFrameStamp[1] < UFG::Metrics::msFrameCount - 2;
}

// File Line: 2343
// RVA: 0x2323A0
__int64 __fastcall UFG::SectionChooser::GetBytesRemainingToLoad()
{
  unsigned int v0; // ebx
  unsigned int i; // edi
  UFG::SectionChooser::SectionInfo *v2; // rsi

  v0 = 0;
  for ( i = 0; i < UFG::SectionChooser::mSectionCount; ++i )
  {
    v2 = &UFG::SectionChooser::mSectionInfo[i];
    if ( (unsigned int)UFG::DataStreamer::GetStreamState(&v2->mhStreamHandleSTD) - 2 <= 1 )
      v0 += UFG::DataStreamer::GetReadBytes(&v2->mhStreamHandleSTD);
    if ( (unsigned int)UFG::DataStreamer::GetStreamState(&v2->mhStreamHandleMID) - 2 <= 1 )
      v0 += UFG::DataStreamer::GetReadBytes(&v2->mhStreamHandleMID);
    if ( (unsigned int)UFG::DataStreamer::GetStreamState(&v2->mhStreamHandleGAM) - 2 <= 1 )
      v0 += UFG::DataStreamer::GetReadBytes(&v2->mhStreamHandleGAM);
  }
  return v0;
}

