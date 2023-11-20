// File Line: 142
// RVA: 0x22F810
void __fastcall UFG::SectionChooser::SectionInfo::SectionInfo(UFG::SectionChooser::SectionInfo *this)
{
  UFG::DataStreamer::Handle *v1; // [rsp+28h] [rbp+10h]
  UFG::DataStreamer::Handle *v2; // [rsp+28h] [rbp+10h]
  UFG::DataStreamer::Handle *v3; // [rsp+28h] [rbp+10h]

  *(_WORD *)&this->meLoadStateMID.mValue = 0;
  *(_DWORD *)&this->meLODLevelCurrent.mValue = 0;
  v1 = &this->mhStreamHandleGAM;
  v1->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mPrev;
  this->mhStreamHandleGAM.mCallback = 0i64;
  this->mhStreamHandleGAM.mCallbackParam = 0i64;
  this->mhStreamHandleGAM.mImpl = 0i64;
  *(_DWORD *)&this->mhStreamHandleGAM.mFlags = 536870915;
  this->mhStreamHandleGAM._mTargetState.mValue = 1;
  v2 = &this->mhStreamHandleMID;
  v2->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v2->mPrev;
  this->mhStreamHandleMID.mCallback = 0i64;
  this->mhStreamHandleMID.mCallbackParam = 0i64;
  this->mhStreamHandleMID.mImpl = 0i64;
  *(_DWORD *)&this->mhStreamHandleMID.mFlags = 536870915;
  this->mhStreamHandleMID._mTargetState.mValue = 1;
  v3 = &this->mhStreamHandleSTD;
  v3->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v3->mPrev;
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
  UFG::DataStreamer::Handle *v1; // [rsp+28h] [rbp+10h]

  *(_QWORD *)&this->meLODLevelCurrent = 0i64;
  this->mbStdLODLoaded = 0;
  v1 = &this->mhStreamHandleStdLOD;
  v1->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mPrev;
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
  return atexit(UFG::SectionChooser::_dynamic_atexit_destructor_for__mWorldName__);
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
  return atexit(UFG::SectionChooser::_dynamic_atexit_destructor_for__mStreamBSPDebugData__);
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
  return atexit(UFG::SectionChooser::_dynamic_atexit_destructor_for__mStreamHandleWorldCommon__);
}

// File Line: 312
// RVA: 0x235160
void __fastcall UFG::SectionChooser::SetOnZoneLayoutLoadCallback(void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *))
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
  __int64 v1; // rcx
  char *v2; // rax
  const char *v3; // r9
  UFG::qString *v4; // rax
  UFG::SectionChooser::SectionInfo *v5; // rcx
  UFG::SectionChooser::SectionInfo *v6; // rcx
  UFG::qString v7; // [rsp+48h] [rbp-60h]
  UFG::qString result; // [rsp+70h] [rbp-38h]

  if ( UFG::SectionChooser::mSectionInfo )
  {
    if ( enabled )
    {
      UFG::qString::qString(&v7);
      v1 = UFG::gSectionLayout->mSections.mOffset;
      if ( v1 )
        v2 = (char *)&UFG::gSectionLayout->mSections + v1;
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
  void *v2; // rbp
  UFG::DataStreamer::Handle *v3; // r14
  UFG::qResourceInventoryVtbl *v4; // rbx
  unsigned int v5; // eax
  UFG::BSP *v6; // rax
  UFG::qResourceInventoryVtbl *v7; // rbx
  unsigned int v8; // eax
  UFG::BSP *v9; // rax
  unsigned __int64 v10; // rcx
  int v11; // esi
  signed __int64 v12; // rax
  unsigned __int8 v13; // cf
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::SectionChooser::SectionInfo *v16; // rbx
  unsigned __int64 v17; // rcx
  int v18; // esi
  signed __int64 v19; // rax
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::SectionChooser::ZoneInfo *v22; // rbx
  unsigned int i; // er8
  __int64 v24; // rcx
  char *v25; // r9
  __int64 v26; // rcx
  char *v27; // rax
  signed __int64 v28; // r9
  const char *v29; // rax
  UFG::qString *v30; // rax
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-98h]
  UFG::qString v32; // [rsp+48h] [rbp-70h]
  UFG::qString result; // [rsp+70h] [rbp-48h]

  v2 = param;
  v3 = handle;
  v4 = UFG::gBSPInventory.vfptr;
  v5 = UFG::qStringHash32("World", 0xFFFFFFFF);
  v6 = (UFG::BSP *)v4->Get((UFG::qResourceInventory *)&UFG::gBSPInventory.vfptr, v5);
  if ( !v6 || v6->mNodeCount <= 0 )
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
  v9 = (UFG::BSP *)v7->Get((UFG::qResourceInventory *)&UFG::gBSPInventory.vfptr, v8);
  if ( v9 && v9->mNodeCount > 0 )
    UFG::SectionChooser::mBSP = v9;
  else
    v9 = UFG::SectionChooser::mBSP;
  if ( !v9 )
    goto LABEL_29;
  UFG::qMemSet(UFG::SectionChooser::SectionInfo::smStateCount, 0, 0x60u);
  v10 = UFG::gSectionLayout->mSectionCount;
  UFG::SectionChooser::mSectionCount = v10;
  v11 = v10;
  v12 = 184 * v10;
  if ( !is_mul_ok(v10, 0xB8ui64) )
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
    pDtor = (void (__fastcall *)(void *))UFG::SectionChooser::SectionInfo::~SectionInfo;
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
  v17 = UFG::gZoneLayout->mZoneCount;
  UFG::SectionChooser::mZoneCount = v17;
  v18 = v17;
  v19 = v17 << 6;
  if ( !is_mul_ok(v17, 0x40ui64) )
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
    pDtor = (void (__fastcall *)(void *))UFG::SectionChooser::ZoneInfo::~ZoneInfo;
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
    v24 = UFG::gSectionLayout->mSections.mOffset;
    if ( v24 )
      v25 = (char *)&UFG::gSectionLayout->mSections + v24;
    else
      v25 = 0i64;
    UFG::SectionChooser::mSectionInfo[i].mSection = (UFG::Section *)&v25[48 * i];
  }
LABEL_30:
  UFG::SectionChooser::QueueZoneLoad(0);
  UFG::SectionChooser::LoadGlobalCell(1);
  UFG::qString::qString(&v32);
  v26 = UFG::gSectionLayout->mSections.mOffset;
  if ( v26 )
    v27 = (char *)&UFG::gSectionLayout->mSections + v26;
  else
    v27 = 0i64;
  v28 = (signed __int64)(v27 + 16);
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
    v30 = UFG::qString::FormatEx(
            &result,
            "Data\\Gameplay\\%s\\%s.bin",
            UFG::SectionChooser::mWorldName.mData,
            v28,
            pDtor);
  UFG::qString::Set(&v32, v30->mData, v30->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::DataStreamer::QueueStream(
    &UFG::SectionChooser::mSectionInfo->mhStreamHandleGAM,
    v32.mData,
    DATA_GAMEPLAY_GLOBAL,
    DEFAULT_PRIORITY,
    1u,
    (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))UFG::SectionChooser::OnSectionLoadCallback,
    UFG::SectionChooser::mSectionInfo);
  if ( UFG::SectionChooser::mOnZoneLayoutLoadCallback )
    UFG::SectionChooser::mOnZoneLayoutLoadCallback(v3, v2);
  UFG::qString::~qString(&v32);
}

// File Line: 548
// RVA: 0x2330D0
__int64 __fastcall UFG::SectionChooser::Initialize(const char *worldName)
{
  UFG::SectionChooser::Lookahead *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4
  UFG::SectionChooser::Lookahead *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::SectionChooser::Lookahead *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm2_4
  unsigned __int8 v10; // bl
  UFG::qString result; // [rsp+48h] [rbp-30h]

  v1 = UFG::SectionChooser::mLookahead;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  UFG::SectionChooser::mLookahead->mViewerPosition.x = UFG::qVector3::msZero.x;
  v1->mViewerPosition.y = v2;
  v1->mViewerPosition.z = v3;
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
  unsigned __int16 *v1; // rbx
  UFG::Section **v2; // rbx

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
    v1 = &UFG::SectionChooser::mZoneInfo[-1].mhStreamHandleStdLOD.mFlags;
    `eh vector destructor iterator(
      UFG::SectionChooser::mZoneInfo,
      0x40ui64,
      *(_DWORD *)&UFG::SectionChooser::mZoneInfo[-1].mhStreamHandleStdLOD.mFlags,
      (void (__fastcall *)(void *))UFG::SectionChooser::ZoneInfo::~ZoneInfo);
    operator delete[](v1);
    UFG::SectionChooser::mZoneInfo = 0i64;
  }
  if ( UFG::SectionChooser::mSectionInfo )
  {
    v2 = &UFG::SectionChooser::mSectionInfo[-1].mSection;
    `eh vector destructor iterator(
      UFG::SectionChooser::mSectionInfo,
      0xB8ui64,
      (int)UFG::SectionChooser::mSectionInfo[-1].mSection,
      (void (__fastcall *)(void *))UFG::SectionChooser::SectionInfo::~SectionInfo);
    operator delete[](v2);
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
  UFG::SectionChooser::meFlushState = (emptyCache != 0) + 1;
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
__int64 __fastcall UFG::SectionChooser::GetCellToLoadFromVisIndex(unsigned int vis_index, bool keep_currently_loaded_alt_layers)
{
  UFG::SectionLayout *v2; // rbx
  bool v3; // r9
  __int64 v4; // rax
  char *v5; // r8
  signed __int64 v6; // rdx
  __int64 v7; // rax
  char *v8; // rcx
  unsigned int v9; // er11
  int *v10; // rdx
  __int64 v11; // r8
  int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // er8
  char *v15; // r10
  __int64 v16; // rax
  signed __int64 v17; // rcx
  __int64 v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // r9
  int v22; // [rsp+0h] [rbp-28h]
  char v23; // [rsp+4h] [rbp-24h]

  v2 = UFG::gSectionLayout;
  v3 = keep_currently_loaded_alt_layers;
  v4 = UFG::gSectionLayout->mSectionVis.mOffset;
  if ( v4 )
    v5 = (char *)&UFG::gSectionLayout->mSectionVis + v4;
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
  if ( (!v3 || (unsigned int)(unsigned __int8)UFG::SectionChooser::mSectionInfo[v22].meLoadStateSTD.mValue - 1 > 1)
    && v9 > 1 )
  {
    v14 = 1;
    if ( v9 > 1 )
    {
      v15 = &v23;
      while ( (unsigned int)(unsigned __int8)UFG::SectionChooser::mSectionInfo[*(unsigned int *)v15].meLoadStateSTD.mValue
            - 1 > 1 )
      {
        v16 = v2->mSections.mOffset;
        if ( v16 )
          v17 = (signed __int64)&v2->mSections + v16;
        else
          v17 = 0i64;
        v18 = *(unsigned __int16 *)(v17 + 48i64 * *(unsigned int *)v15 + 10);
        v19 = v2->mLayers.mOffset;
        if ( v19 )
          v20 = (signed __int64)&v2->mLayers + v19;
        else
          v20 = 0i64;
        if ( *(_DWORD *)(v20 + 48 * v18 + 8) )
        {
          if ( !v13 )
            v13 = v14;
        }
        ++v14;
        v15 += 4;
        if ( v14 >= v9 )
          return (unsigned int)*(&v22 + v13);
      }
      v13 = v14;
    }
  }
  return (unsigned int)*(&v22 + v13);
}

// File Line: 725
// RVA: 0x232E90
signed __int64 __fastcall UFG::SectionChooser::GetVisIndexAtPosition(UFG::qVector3 *position, bool dbg_print_serials)
{
  signed __int64 result; // rax

  if ( UFG::SectionChooser::mBSP )
    result = UFG::BSP::GetSpaceFromPoint(UFG::SectionChooser::mBSP, position, 1, dbg_print_serials)->mSectionIndex;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 739
// RVA: 0x232460
__int64 __fastcall UFG::SectionChooser::GetCellIndexAtPosition(UFG::qVector3 *position, bool dbg_print_serials)
{
  UFG::BSPSpace *v2; // rax

  if ( !UFG::SectionChooser::mBSP )
    return 0xFFFFFFFFi64;
  v2 = UFG::BSP::GetSpaceFromPoint(UFG::SectionChooser::mBSP, position, 1, dbg_print_serials);
  return UFG::SectionChooser::GetCellToLoadFromVisIndex(v2->mSectionIndex, 1);
}

// File Line: 755
// RVA: 0x235190
void __fastcall UFG::SectionChooser::SetToStreamGameplayFromWorldBigFile(bool streamGameplayFromWorldBigFile)
{
  mbStreamGameplayFromWorldBigFile = streamGameplayFromWorldBigFile;
}

// File Line: 760
// RVA: 0x2326B0
void __fastcall UFG::SectionChooser::GetFilenameForSectionIndex(unsigned int sectionIndex, UFG::qString *fileName, UFG::SCENERY_LAYER eLODLevel)
{
  UFG::qString *v3; // rbx
  __int64 v4; // r9
  char *v5; // r9
  signed __int64 v6; // rcx
  bool v7; // zf
  signed __int64 v8; // r9
  const char *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString *v11; // rax
  UFG::qString *v12; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v3 = fileName;
  v4 = UFG::gSectionLayout->mSections.mOffset;
  if ( v4 )
    v5 = (char *)&UFG::gSectionLayout->mSections + v4;
  else
    v5 = 0i64;
  v6 = 48i64 * sectionIndex;
  v7 = &v5[v6] == 0i64;
  v8 = (signed __int64)&v5[v6 + 16];
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
              v8,
              -2i64);
      UFG::qString::Set(v3, v10->mData, v10->mLength, 0i64, 0);
      break;
    case LOD_SETTING_NORMAL:
      v11 = UFG::qString::FormatEx(
              &result,
              "Data\\World\\%s\\Section\\%s\\%s\\%sLOD.perm.bin",
              UFG::SectionChooser::mWorldName.mData,
              v9,
              v8,
              v8,
              -2i64);
      UFG::qString::Set(v3, v11->mData, v11->mLength, 0i64, 0);
      break;
    case NUM_LOD_SETTING|LOD_SETTING_NORMAL:
      if ( mbStreamGameplayFromWorldBigFile )
        v12 = UFG::qString::FormatEx(
                &result,
                "Data\\World\\%s\\Section\\%s\\%s\\%sXXX.perm.bin",
                UFG::SectionChooser::mWorldName.mData,
                v9,
                v8,
                v8,
                -2i64);
      else
        v12 = UFG::qString::FormatEx(&result, "Data\\Gameplay\\%s\\%s.bin", UFG::SectionChooser::mWorldName.mData, v8);
      UFG::qString::Set(v3, v12->mData, v12->mLength, 0i64, 0);
      break;
    default:
      return;
  }
  UFG::qString::~qString(&result);
}

// File Line: 823
// RVA: 0x233340
char __fastcall UFG::SectionChooser::IsSectionVisible_VisIndex(unsigned int visIndex, UFG::SCENERY_LAYER eLodLevel, bool bConsiderVisibleOnlyAfterDelay)
{
  UFG::SCENERY_LAYER v3; // edi
  bool v4; // bl
  unsigned int v5; // eax

  v3 = eLodLevel;
  v4 = bConsiderVisibleOnlyAfterDelay;
  v5 = UFG::SectionChooser::GetCellToLoadFromVisIndex(visIndex, 1);
  return UFG::SectionChooser::IsSectionVisible_CellIndex(v5, v3, v4);
}

// File Line: 856
// RVA: 0x2332A0
char __fastcall UFG::SectionChooser::IsSectionVisible_CellIndex(unsigned int sectionIndex, UFG::SCENERY_LAYER eLodLevel, bool bConsiderVisibleOnlyAfterDelay)
{
  UFG::SectionChooser::SectionInfo *v4; // rcx

  if ( sectionIndex < 1 )
    return 1;
  if ( !UFG::SectionChooser::mSectionInfo )
    return 0;
  v4 = &UFG::SectionChooser::mSectionInfo[sectionIndex];
  if ( eLodLevel == 2 )
  {
    if ( v4->meLODLevelCurrent.mValue == 2 )
    {
      if ( v4->meLoadStateSTD.mValue == 2
        && (!bConsiderVisibleOnlyAfterDelay || v4->mChangedStateFrameStamp[2] < UFG::Metrics::msFrameCount - 2) )
      {
        return 1;
      }
      return 0;
    }
    return 0;
  }
  if ( eLodLevel != 1
    || v4->meLODLevelCurrent.mValue == 2
    && v4->meLoadStateSTD.mValue == 2
    && v4->mChangedStateFrameStamp[2] < UFG::Metrics::msFrameCount - 2
    || UFG::SectionChooser::meSuppressLOD == 1 )
  {
    return 0;
  }
  if ( v4->meLoadStateMID.mValue != 2 )
    return 0;
  if ( !bConsiderVisibleOnlyAfterDelay )
    return 1;
  if ( v4->mChangedStateFrameStamp[1] >= UFG::Metrics::msFrameCount - 2 )
    return 0;
  return 1;
}

// File Line: 911
// RVA: 0x230920
char __fastcall UFG::SectionChooser::AreAnyLoadsPending()
{
  int v0; // ebx
  UFG::SectionChooser::SectionInfo *v1; // rdi
  int v2; // eax

  v0 = 0;
  if ( !UFG::SectionChooser::mSectionCount )
    return 0;
  while ( 1 )
  {
    v1 = &UFG::SectionChooser::mSectionInfo[v0];
    v2 = UFG::DataStreamer::GetStreamState(&v1->mhStreamHandleSTD);
    if ( v2 == 2 || v2 == 3 || (unsigned int)UFG::DataStreamer::GetStreamState(&v1->mhStreamHandleMID) - 2 <= 1 )
      break;
    if ( ++v0 >= UFG::SectionChooser::mSectionCount )
      return 0;
  }
  return 1;
}

// File Line: 951
// RVA: 0x234470
void __fastcall UFG::SectionChooser::OnSectionLoadCallback(UFG::DataStreamer::Handle *handle, UFG::SectionChooser::SectionInfo *param)
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
  UFG::SCENERY_LAYER v2; // ebp
  unsigned int v3; // ebx
  unsigned __int8 v4; // si
  __int64 v5; // r14
  UFG::SectionChooser::SectionInfo *callbackParam; // rdi
  unsigned int flags; // edx
  int v8; // eax
  UFG::DataStreamer::Handle *v9; // r10
  UFG::DataStreamer::PRIORITY v10; // ebx
  UFG::StreamingMemory::DATA_TYPE v11; // er8
  int v12; // eax
  __int64 v13; // rcx
  signed __int64 v14; // rax
  signed __int64 v15; // r9
  const char *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString v19; // [rsp+40h] [rbp-98h]
  __int64 v20; // [rsp+68h] [rbp-70h]
  UFG::qString fileName; // [rsp+70h] [rbp-68h]
  UFG::qString result; // [rsp+98h] [rbp-40h]

  v20 = -2i64;
  v2 = eLODLevel;
  v3 = globalSectionIndex;
  v4 = 0;
  v5 = globalSectionIndex;
  callbackParam = &UFG::SectionChooser::mSectionInfo[globalSectionIndex];
  UFG::qString::qString(&fileName);
  UFG::SectionChooser::GetFilenameForSectionIndex(v3, &fileName, v2);
  flags = 0;
  if ( v2 == 1 )
  {
    v12 = (unsigned __int8)callbackParam->meLoadStateMID.mValue;
    if ( v12 == 3 )
    {
      callbackParam->mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
      --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)callbackParam->meLoadStateMID.mValue];
      ++UFG::SectionChooser::SectionInfo::smStateCount[1][2];
      callbackParam->meLoadStateMID.mValue = 2;
      callbackParam->mUnloadCountLow = 5;
      goto LABEL_10;
    }
    if ( v12 == 2 )
      goto LABEL_10;
    v9 = &callbackParam->mhStreamHandleMID;
    callbackParam->mChangedStateFrameStamp[1] = UFG::Metrics::msFrameCount;
    --UFG::SectionChooser::SectionInfo::smStateCount[1][(unsigned __int8)callbackParam->meLoadStateMID.mValue];
    ++UFG::SectionChooser::SectionInfo::smStateCount[1][1];
    callbackParam->meLoadStateMID.mValue = 1;
    callbackParam->mUnloadCountLow = 5;
    v10 = 12288;
    v11 = 3;
  }
  else
  {
    if ( v2 != 2 )
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
    v9 = &callbackParam->mhStreamHandleSTD;
    callbackParam->mChangedStateFrameStamp[2] = UFG::Metrics::msFrameCount;
    --UFG::SectionChooser::SectionInfo::smStateCount[2][(unsigned __int8)callbackParam->meLoadStateSTD.mValue];
    ++UFG::SectionChooser::SectionInfo::smStateCount[2][1];
    callbackParam->meLoadStateSTD.mValue = 1;
    callbackParam->mUnloadCountStd = 5;
    v10 = 0x4000;
    flags = 128;
    v11 = DATA_SECTION_STD;
  }
  if ( v9 )
  {
    v4 = UFG::DataStreamer::QueueStream(
           v9,
           fileName.mData,
           v11,
           v10,
           flags,
           (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))UFG::SectionChooser::OnSectionLoadCallback,
           callbackParam);
    if ( v2 == 2 )
    {
      UFG::qString::qString(&v19);
      v13 = UFG::gSectionLayout->mSections.mOffset;
      if ( v13 )
        v13 += (__int64)&UFG::gSectionLayout->mSections;
      v14 = v13 + 48 * v5;
      if ( v14 )
        v15 = v14 + 16;
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
void __fastcall UFG::SectionChooser::OnZoneLoadCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  if ( handle == (UFG::DataStreamer::Handle *)((char *)param + 16) )
    *((_BYTE *)param + 8) = 1;
}

// File Line: 1166
// RVA: 0x234B70
__int64 __fastcall UFG::SectionChooser::QueueZoneLoad(unsigned int globalZoneIndex)
{
  unsigned int v1; // edi
  unsigned __int64 v2; // rbx
  UFG::Zone *callbackParam; // rsi
  __int64 v4; // rdx
  UFG::Zone *v5; // rax
  const char *v6; // r9
  UFG::qString *v7; // rax
  UFG::StreamingMemory::DATA_TYPE v8; // er8
  unsigned __int8 v9; // bl
  UFG::qString v11; // [rsp+48h] [rbp-60h]
  UFG::qString result; // [rsp+70h] [rbp-38h]

  v1 = globalZoneIndex;
  v2 = (unsigned __int64)globalZoneIndex << 6;
  callbackParam = (UFG::Zone *)((char *)UFG::SectionChooser::mZoneInfo + v2);
  UFG::qString::qString(&v11);
  v4 = UFG::gZoneLayout->mZones.mOffset;
  if ( v4 )
    v5 = (UFG::Zone *)((char *)&UFG::gZoneLayout->mZones + v4);
  else
    v5 = 0i64;
  if ( !gIsHDWorldTextures || (v6 = "HD", gForceLowRes) )
    v6 = "SD";
  v7 = UFG::qString::FormatEx(
         &result,
         "Data\\World\\%s\\Zone\\%s\\%s\\%s.perm.bin",
         UFG::SectionChooser::mWorldName.mData,
         v6,
         &v5->mName[v2],
         &v5->mName[v2]);
  UFG::qString::Set(&v11, v7->mData, v7->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v8 = DATA_ZONE_LOC;
  if ( !v1 )
    v8 = DATA_GLOBAL_LOC;
  v9 = UFG::DataStreamer::QueueStream(
         (UFG::DataStreamer::Handle *)&callbackParam->mUIDZoneUC,
         v11.mData,
         v8,
         VERY_HIGH_PRIORITY,
         0x81u,
         UFG::SectionChooser::OnZoneLoadCallback,
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
    if ( UFG::SectionChooser::meFlushState == 2 )
      UFG::StreamPool_ClearAllCachedData(v8);
    UFG::SectionChooser::QueueZoneLoad(0);
    UFG::SectionChooser::LoadGlobalCell(1);
    UFG::SectionChooser::meFlushState = 0;
  }
}

// File Line: 1307
// RVA: 0x235B90
void __fastcall UFG::SectionChooser::UpdateStreams(bool bFadeout)
{
  char r8_1; // r8
  unsigned int edx2; // edx
  unsigned int i; // edx
  unsigned int j; // edx
  unsigned int k; // edx
  unsigned int l; // edx
  UFG::SectionChooser::SectionLoad *v7; // r12
  unsigned int v8; // er14
  unsigned int v9; // er15
  unsigned int v10; // er13
  unsigned int v11; // eax
  unsigned __int64 v12; // rbx
  UFG::SectionChooser::SectionInfo *v13; // rdi
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  UFG::SectionChooser::SectionInfo *v17; // rsi
  unsigned int v18; // ecx
  unsigned int v19; // er13
  unsigned int v20; // esi
  unsigned __int64 v21; // rax
  UFG::allocator::free_link *v22; // rax
  __int64 v23; // r15
  UFG::allocator::free_link *v24; // rdx
  signed __int64 v25; // r8
  __int64 v26; // rcx
  signed __int64 v27; // rcx
  unsigned int v28; // ecx
  unsigned int v29; // er13
  unsigned int v30; // esi
  unsigned __int64 v31; // rax
  UFG::allocator::free_link *v32; // rax
  __int64 v33; // r15
  UFG::allocator::free_link *v34; // rcx
  signed __int64 v35; // rdx
  __int64 v36; // r8
  signed __int64 v37; // rcx
  unsigned int v38; // ecx
  unsigned int v39; // er13
  unsigned int v40; // esi
  unsigned __int64 v41; // rax
  UFG::allocator::free_link *v42; // rax
  __int64 v43; // r15
  UFG::allocator::free_link *v44; // rcx
  signed __int64 v45; // rdx
  __int64 v46; // r8
  unsigned int v47; // ecx
  unsigned int v48; // er13
  unsigned int v49; // esi
  unsigned __int64 v50; // rax
  UFG::allocator::free_link *v51; // rax
  __int64 v52; // r15
  UFG::allocator::free_link *v53; // rcx
  signed __int64 v54; // rdx
  __int64 v55; // r8
  _DWORD *v56; // rdx
  unsigned int v57; // er13
  unsigned int v58; // ecx
  unsigned int v59; // er9
  unsigned int v60; // er10
  UFG::SectionChooser::ZoneInfo *v61; // r15
  unsigned __int64 v62; // rsi
  int v63; // er8
  int v64; // eax
  unsigned int v65; // er8
  unsigned int v66; // edi
  unsigned int v67; // ebx
  unsigned __int64 v68; // rax
  UFG::allocator::free_link *v69; // rax
  void *v70; // rcx
  UFG::allocator::free_link *v71; // rdx
  char *v72; // r9
  __int64 v73; // r8
  float *v74; // rbx
  __int64 v75; // rdi
  __int64 v76; // rcx
  char *v77; // rdx
  signed __int64 v78; // rcx
  __int64 v79; // rdx
  char *v80; // r8
  signed __int64 v81; // rcx
  float v82; // xmm3_4
  float v83; // xmm2_4
  __m128 v84; // xmm0
  float v85; // xmm6_4
  float v86; // xmm1_4
  float v87; // xmm3_4
  float v88; // xmm6_4
  UFG::SectionChooser::SectionLoad *v89; // rbx
  __int64 v90; // rdi
  __int64 v91; // r9
  __int64 v92; // rcx
  char *v93; // r8
  void *v94; // rdi
  unsigned int *v95; // rbx
  __int64 v96; // rsi
  UFG::qVector3 v2; // [rsp+8h] [rbp-61h]
  UFG::qVector3 v1; // [rsp+18h] [rbp-51h]
  __int64 v99; // [rsp+28h] [rbp-41h]
  __int64 v100; // [rsp+30h] [rbp-39h]
  __int64 v101; // [rsp+38h] [rbp-31h]
  void *mem; // [rsp+40h] [rbp-29h]
  char v103; // [rsp+D0h] [rbp+67h]
  unsigned int v104; // [rsp+D8h] [rbp+6Fh]
  unsigned int v105; // [rsp+E0h] [rbp+77h]
  UFG::allocator::free_link *v106; // [rsp+E8h] [rbp+7Fh]

  r8_1 = bFadeout;
  if ( UFG::SectionChooser::mStreamsUpdateEnabled )
  {
    ++UFG::Zone::smCurrentMagic0;
    ++UFG::Zone::smCurrentMagic1;
    edx2 = 0;
    if ( UFG::SectionChooser::mZoneCount )
    {
      do
        UFG::SectionChooser::mZoneInfo[(unsigned __int64)edx2++].meLODLevelNew = 0;
      while ( edx2 < UFG::SectionChooser::mZoneCount );
    }
    for ( i = 0; i < UFG::SectionChooser::mSectionCount; ++i )
      UFG::SectionChooser::mSectionInfo[i].meLODLevelNew.mValue = 0;
    if ( UFG::SectionChooser::meSuppressLOD != 2 )
    {
      for ( j = 0; j < mLOWSectionCount; ++j )
        UFG::SectionChooser::mSectionInfo[mLOWSectionCellIndices[j]].meLODLevelNew.mValue = 1;
    }
    for ( k = 0; k < mSTDSectionCount; ++k )
      UFG::SectionChooser::mSectionInfo[mSTDSectionCellIndices[k]].meLODLevelNew.mValue = 2;
    for ( l = 0; l < UFG::SectionChooser::mSTDZoneCount; ++l )
      UFG::SectionChooser::mZoneInfo[(unsigned __int64)UFG::SectionChooser::mSTDZoneIndices[l]].meLODLevelNew = 2;
    v7 = 0i64;
    v100 = 0i64;
    v8 = 0;
    v99 = 0i64;
    v9 = 0;
    v10 = 0;
    v104 = 0;
    v11 = UFG::SectionChooser::mSectionCount;
    if ( UFG::SectionChooser::mSectionCount )
    {
      do
      {
        v12 = v10;
        v13 = UFG::SectionChooser::mSectionInfo;
        LOBYTE(v14) = UFG::SectionChooser::mSectionInfo[v12].meLODLevelCurrent.mValue;
        LOBYTE(v15) = UFG::SectionChooser::mSectionInfo[v12].meLODLevelNew.mValue;
        if ( (_BYTE)v14 == (_BYTE)v15 && !UFG::SectionChooser::mSectionInfo[v12].mbFlushing )
          goto LABEL_124;
        v15 = (unsigned __int8)v15;
        if ( UFG::SectionChooser::mSectionInfo[v12].mbFlushing )
          v15 = 0;
        LODWORD(v106) = v15;
        v14 = (unsigned __int8)v14;
        if ( (_BYTE)v14 )
        {
          v16 = v14 - 1;
          if ( v16 )
          {
            if ( v16 == 1 )
            {
              if ( v15 )
              {
                if ( v15 == 1 )
                {
                  if ( r8_1
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
                if ( !(UFG::SectionChooser::mSectionInfo[v12].mSection->mFlags & 0x10) )
                {
                  if ( r8_1
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
                    r8_1 = v103;
                  }
                  v13[v12].mUnloadCountLow = 5;
                }
                v17 = UFG::SectionChooser::mSectionInfo;
                if ( r8_1
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
            if ( !(UFG::SectionChooser::mSectionInfo[v12].mSection->mFlags & 0x10) )
            {
              if ( r8_1
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
            v105 = v8;
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
                v100 = v23;
                v9 = v20;
                HIDWORD(v99) = v20;
                v18 = v105;
              }
            }
            ++v8;
            LODWORD(v99) = v19;
            v27 = v18;
            v10 = v104;
            v7[v27].mGlobalIndex = v104;
            v7[v27].mLodLevel = SCENERY_LAYER_STD;
LABEL_122:
            v7[v27].mScore = v1.z;
            goto LABEL_123;
          }
        }
        else
        {
          if ( v15 == 1 )
          {
            if ( UFG::SectionChooser::mSectionInfo[v12].mSection->mFlags & 0x10
              || UFG::SectionChooser::meSuppressLOD == 2 )
            {
              goto LABEL_123;
            }
            v47 = v8;
            v105 = v8;
            v48 = v8 + 1;
            if ( v8 + 1 > v9 )
            {
              v49 = 1;
              if ( v9 )
                v49 = 2 * v9;
              for ( ; v49 < v48; v49 *= 2 )
                ;
              if ( v49 - v48 > 0x10000 )
                v49 = v8 + 65537;
              if ( v49 != v8 )
              {
                v50 = 12i64 * v49;
                if ( !is_mul_ok(v49, 0xCui64) )
                  v50 = -1i64;
                v51 = UFG::qMalloc(v50, "qArray.Add", 0i64);
                v52 = (__int64)v51;
                *(_QWORD *)&v2.x = v51;
                if ( v7 )
                {
                  if ( v8 )
                  {
                    v53 = v51;
                    v54 = (char *)v7 - (char *)v51;
                    v55 = v8;
                    do
                    {
                      LODWORD(v53->mNext) = *(_DWORD *)((char *)&v53->mNext + v54);
                      HIDWORD(v53->mNext) = *(_DWORD *)((char *)&v53->mNext + v54 + 4);
                      LODWORD(v53[1].mNext) = *(_DWORD *)((char *)&v53[1].mNext + v54);
                      v53 = (UFG::allocator::free_link *)((char *)v53 + 12);
                      --v55;
                    }
                    while ( v55 );
                  }
                  operator delete[](v7);
                }
                v7 = (UFG::SectionChooser::SectionLoad *)v52;
                v100 = v52;
                v9 = v49;
                HIDWORD(v99) = v49;
                v47 = v105;
              }
            }
            ++v8;
            LODWORD(v99) = v48;
            v27 = v47;
            v10 = v104;
            v7[v27].mGlobalIndex = v104;
            v7[v27].mLodLevel = 1;
            goto LABEL_122;
          }
          if ( v15 == 2 )
          {
            if ( !(UFG::SectionChooser::mSectionInfo[v12].mSection->mFlags & 0x10)
              && UFG::SectionChooser::meSuppressLOD != 2 )
            {
              v28 = v8;
              v105 = v8;
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
                  v100 = v33;
                  v9 = v30;
                  HIDWORD(v99) = v30;
                  v28 = v105;
                }
              }
              ++v8;
              LODWORD(v99) = v29;
              v37 = v28;
              v7[v37].mGlobalIndex = v104;
              v7[v37].mLodLevel = 1;
              v7[v37].mScore = v1.z;
            }
            v38 = v8;
            v105 = v8;
            v39 = v8 + 1;
            if ( v8 + 1 > v9 )
            {
              v40 = 1;
              if ( v9 )
                v40 = 2 * v9;
              for ( ; v40 < v39; v40 *= 2 )
                ;
              if ( v40 - v39 > 0x10000 )
                v40 = v8 + 65537;
              if ( v40 != v8 )
              {
                v41 = 12i64 * v40;
                if ( !is_mul_ok(v40, 0xCui64) )
                  v41 = -1i64;
                v42 = UFG::qMalloc(v41, "qArray.Add", 0i64);
                v43 = (__int64)v42;
                *(_QWORD *)&v2.x = v42;
                if ( v7 )
                {
                  if ( v8 )
                  {
                    v44 = v42;
                    v45 = (char *)v7 - (char *)v42;
                    v46 = v8;
                    do
                    {
                      LODWORD(v44->mNext) = *(_DWORD *)((char *)&v44->mNext + v45);
                      HIDWORD(v44->mNext) = *(_DWORD *)((char *)&v44->mNext + v45 + 4);
                      LODWORD(v44[1].mNext) = *(_DWORD *)((char *)&v44[1].mNext + v45);
                      v44 = (UFG::allocator::free_link *)((char *)v44 + 12);
                      --v46;
                    }
                    while ( v46 );
                  }
                  operator delete[](v7);
                }
                v7 = (UFG::SectionChooser::SectionLoad *)v43;
                v100 = v43;
                v9 = v40;
                HIDWORD(v99) = v40;
                v38 = v105;
              }
            }
            ++v8;
            LODWORD(v99) = v39;
            v27 = v38;
            v10 = v104;
            v7[v27].mGlobalIndex = v104;
            v7[v27].mLodLevel = 2;
            goto LABEL_122;
          }
        }
LABEL_123:
        v13[v12].meLODLevelCurrent.mValue = (char)v106;
        v11 = UFG::SectionChooser::mSectionCount;
        r8_1 = v103;
LABEL_124:
        v104 = ++v10;
      }
      while ( v10 < v11 );
    }
    v56 = 0i64;
    mem = 0i64;
    v57 = 0;
    v101 = 0i64;
    v58 = 0;
    v59 = 0;
    v104 = 0;
    v60 = UFG::SectionChooser::mZoneCount;
    if ( UFG::SectionChooser::mZoneCount )
    {
      v61 = UFG::SectionChooser::mZoneInfo;
      do
      {
        v62 = (unsigned __int64)v59 << 6;
        v63 = *(UFG::SCENERY_LAYER *)((char *)&v61->meLODLevelCurrent + v62);
        v64 = *(UFG::SCENERY_LAYER *)((char *)&v61->meLODLevelNew + v62);
        if ( v63 != v64 )
        {
          if ( v63 )
          {
            if ( v63 == 2 && !v64 && v61 )
            {
              UFG::DataStreamer::ReleaseStream((UFG::DataStreamer::Handle *)((char *)&v61->mhStreamHandleStdLOD + v62));
              *(&v61->mbStdLODLoaded + v62) = 0;
              v56 = mem;
              v59 = v104;
            }
          }
          else if ( v64 == 2 )
          {
            v65 = v57;
            v105 = v57;
            v66 = v57 + 1;
            if ( v57 + 1 > v58 )
            {
              v67 = 1;
              if ( v58 )
                v67 = 2 * v58;
              for ( ; v67 < v66; v67 *= 2 )
                ;
              if ( v67 <= 4 )
                v67 = 4;
              if ( v67 - v66 > 0x10000 )
                v67 = v57 + 65537;
              if ( v67 != v57 )
              {
                v68 = 4i64 * v67;
                if ( !is_mul_ok(v67, 4ui64) )
                  v68 = -1i64;
                v69 = UFG::qMalloc(v68, "qArray.Add", 0i64);
                v106 = v69;
                v70 = mem;
                if ( mem )
                {
                  if ( v57 )
                  {
                    v71 = v69;
                    v72 = (char *)((_BYTE *)mem - (_BYTE *)v69);
                    v73 = v57;
                    do
                    {
                      LODWORD(v71->mNext) = *(_DWORD *)((char *)&v71->mNext + (_QWORD)v72);
                      v71 = (UFG::allocator::free_link *)((char *)v71 + 4);
                      --v73;
                    }
                    while ( v73 );
                  }
                  operator delete[](v70);
                  v69 = v106;
                }
                v56 = v69;
                mem = v69;
                HIDWORD(v101) = v67;
                v59 = v104;
                v65 = v105;
              }
            }
            ++v57;
            LODWORD(v101) = v66;
            v56[v65] = v59;
          }
          *(UFG::SCENERY_LAYER *)((char *)&v61->meLODLevelCurrent + v62) = *(UFG::SCENERY_LAYER *)((char *)&v61->meLODLevelNew
                                                                                                 + v62);
          v60 = UFG::SectionChooser::mZoneCount;
          v61 = UFG::SectionChooser::mZoneInfo;
          v58 = HIDWORD(v101);
        }
        v104 = ++v59;
      }
      while ( v59 < v60 );
      v8 = v99;
    }
    if ( v8 )
    {
      v74 = &v7->mScore;
      v75 = v8;
      do
      {
        v76 = UFG::gSectionLayout->mSections.mOffset;
        if ( v76 )
          v77 = (char *)&UFG::gSectionLayout->mSections + v76;
        else
          v77 = 0i64;
        v78 = (signed __int64)&v77[48 * *((unsigned int *)v74 - 2)];
        v79 = UFG::SectionChooser::mBSP->mSpaces.mOffset;
        if ( v79 )
          v80 = (char *)&UFG::SectionChooser::mBSP->mSpaces + v79;
        else
          v80 = 0i64;
        v81 = 10i64 * *(unsigned __int16 *)(v78 + 6);
        v82 = *(float *)&v80[8 * v81 + 24];
        v83 = *(float *)&v80[8 * v81 + 20];
        v84 = (__m128)LODWORD(UFG::SectionChooser::mLookahead->mViewerPosition.x);
        v84.m128_f32[0] = (float)((float)(v84.m128_f32[0] - v83) * (float)(v84.m128_f32[0] - v83))
                        + (float)((float)(UFG::SectionChooser::mLookahead->mViewerPosition.y - v82)
                                * (float)(UFG::SectionChooser::mLookahead->mViewerPosition.y - v82));
        LODWORD(v85) = (unsigned __int128)_mm_sqrt_ps(v84);
        v86 = UFG::SectionChooser::mLookahead->mViewerDirection.y;
        v1.x = UFG::SectionChooser::mLookahead->mViewerDirection.x;
        v1.y = v86;
        v1.z = 0.0;
        v87 = v82 - UFG::SectionChooser::mLookahead->mViewerPosition.y;
        v2.x = v83 - UFG::SectionChooser::mLookahead->mViewerPosition.x;
        v2.y = v87;
        v2.z = 0.0;
        v88 = v85 + (float)((float)(UFG::qAngleBetween(&v1, &v2) * 0.31830987) * v85);
        if ( *((_DWORD *)v74 - 1) == 1 )
          v88 = v88 * 2.0;
        *v74 = v88;
        v74 += 3;
        --v75;
      }
      while ( v75 );
    }
    UFG::qQuickSortImpl<UFG::SectionChooser::SectionLoad,bool (*)(UFG::SectionChooser::SectionLoad const &,UFG::SectionChooser::SectionLoad const &)>(
      v7,
      &v7[(signed int)v8 - 1i64],
      UFG::SectionChooser::fnSectionStreamPriority);
    if ( v8 )
    {
      v89 = v7;
      v90 = v8;
      do
      {
        v91 = v89->mGlobalIndex;
        v92 = UFG::gSectionLayout->mSections.mOffset;
        if ( v92 )
          v93 = (char *)&UFG::gSectionLayout->mSections + v92;
        else
          v93 = 0i64;
        if ( v93[48 * v91 + 4] & 4 )
          UFG::SectionChooser::QueueSectionLoad(v91, v89->mLodLevel);
        ++v89;
        --v90;
      }
      while ( v90 );
    }
    v94 = mem;
    if ( v57 )
    {
      v95 = (unsigned int *)mem;
      v96 = v57;
      do
      {
        UFG::SectionChooser::QueueZoneLoad(*v95);
        ++v95;
        --v96;
      }
      while ( v96 );
    }
    if ( v94 )
      operator delete[](v94);
    mem = 0i64;
    v101 = 0i64;
    if ( v7 )
      operator delete[](v7);
  }
}ut->mSections.mOffset;
        if ( v92 )
          v93 = (char *)&UFG::gSectionLayout->mSections + v92;
        else
          v93 = 0i64;
        if ( v93[

// File Line: 1568
// RVA: 0x233410
char __fastcall UFG::SectionChooser::LineInsideTriggerHull(UFG::CellTrigger *trigger, UFG::qVector3 *_start_position, UFG::qVector3 *_end_position, UFG::qVector3 *clippedPos)
{
  float v4; // xmm0_4
  UFG::qVector3 *v5; // r14
  UFG::qVector3 *v6; // rax
  UFG::CellTrigger *v7; // rbp
  char v8; // r9
  float v9; // xmm14_4
  float v10; // xmm12_4
  float v11; // xmm13_4
  float v12; // xmm15_4
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  float v15; // xmm8_4
  float v16; // xmm2_4
  float v17; // xmm9_4
  float v18; // xmm10_4
  unsigned int v19; // er13
  char v20; // r15
  unsigned int v21; // er10
  __int64 v22; // rbx
  __int64 v23; // rdi
  signed __int64 v24; // r11
  unsigned int v25; // ecx
  signed __int64 v26; // rax
  float v27; // xmm6_4
  float v28; // xmm5_4
  int v29; // er8
  int v30; // er9
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm3_4
  bool v37; // zf
  float v38; // xmm0_4
  float v39; // [rsp+E0h] [rbp+8h]
  float v40; // [rsp+E4h] [rbp+Ch]
  UFG::qVector3 *v41; // [rsp+F0h] [rbp+18h]

  v41 = _end_position;
  v4 = _start_position->z;
  v5 = clippedPos;
  v6 = _end_position;
  v7 = trigger;
  if ( v4 < trigger->mMinHeight || v4 > trigger->mMaxHeight )
    return 0;
  v8 = 0;
  LOBYTE(v39) = 0;
  v9 = _end_position->x;
  v10 = _start_position->x;
  v11 = _start_position->y;
  v13 = (__m128)LODWORD(_end_position->x);
  v12 = _end_position->y;
  v13.m128_f32[0] = v13.m128_f32[0] - _start_position->x;
  v14 = v13;
  v15 = _end_position->y - v11;
  v14.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v15 * v15);
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v14);
  if ( v16 <= 0.001 )
  {
    v17 = v40;
    v18 = v39;
  }
  else
  {
    v8 = 1;
    LOBYTE(v39) = 1;
    v17 = (float)(1.0 / v16) * v13.m128_f32[0];
    LODWORD(v18) = COERCE_UNSIGNED_INT((float)(1.0 / v16) * v15) ^ _xmm[0];
  }
  v19 = trigger->mEdgeCount;
  v20 = 0;
  v21 = 0;
  if ( v19 )
  {
    v22 = trigger->mEdges.mOffset;
    v23 = 0i64;
    while ( 1 )
    {
      if ( v22 )
        v24 = (signed __int64)&v7->mEdges + v22;
      else
        v24 = 0i64;
      v25 = 0;
      if ( v21 != v19 - 1 )
        v25 = v21 + 1;
      v26 = (signed __int64)(v22 ? (UFG::qOffset64<UFG::TriggerEdge *> *)((char *)&v7->mEdges + v22) : 0i64);
      v27 = *(float *)(v23 + v24);
      v28 = *(float *)(v23 + v24 + 4);
      v29 = 0;
      LOBYTE(v29) = (float)((float)(*(float *)(v23 + v24 + 8) * (float)(v10 - v27))
                          + (float)(*(float *)(v23 + v24 + 12) * (float)(v11 - v28))) <= 0.0;
      if ( v8 )
      {
        v30 = 0;
        LOBYTE(v30) = (float)((float)(*(float *)(v23 + v24 + 8) * (float)(v9 - v27))
                            + (float)(*(float *)(v23 + v24 + 12) * (float)(v12 - v28))) <= 0.0;
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
      else if ( (float)((float)((float)(v28 - v11) * v17) + (float)((float)(v27 - v10) * v18)) <= 0.0 == (float)((float)((float)(*(float *)(v26 + 16i64 * v25 + 4) - v11) * v17) + (float)((float)(*(float *)(v26 + 16i64 * v25) - v10) * v18)) <= 0.0 )
      {
        v20 = 1;
      }
      else
      {
        if ( !v5 )
          return 1;
        if ( v29 == 1 && !v30 )
        {
          v31 = *(float *)(v23 + v24 + 8);
          v32 = *(float *)(v23 + v24 + 12);
          v33 = v31;
          v34 = (float)(v31 * v13.m128_f32[0]) + (float)(v32 * v15);
          v35 = (float)(v33 * (float)(*(float *)(v23 + v24) - v10))
              + (float)(v32 * (float)(*(float *)(v23 + v24 + 4) - v11));
          v5->z = _start_position->z;
          v5->x = (float)((float)(v13.m128_f32[0] * v35) * (float)(1.0 / v34)) + v10;
          v5->y = (float)((float)(v15 * v35) * (float)(1.0 / v34)) + v11;
          return 1;
        }
      }
      ++v21;
      v23 += 16i64;
      if ( v21 >= v19 )
        break;
      v8 = LOBYTE(v39);
    }
    v37 = v20 == 0;
    if ( v20 )
      return v37;
    v6 = v41;
  }
  if ( v5 )
  {
    v38 = v6->z;
    v5->x = v9;
    v5->y = v12;
    v5->z = v38;
  }
  return 1;
}

// File Line: 1715
// RVA: 0x233BD0
void __fastcall UFG::SectionChooser::ModifyVisibliltyFromTriggersForPosition(UFG::qVector3 *pov_position, UFG::qVector3 *lookahead_position, unsigned int _pov_section_index, unsigned int _lookahead_section_index, unsigned int *STDSectionCount, unsigned int *STDVisIndices, unsigned int *LODSectionCount, unsigned int *LODVisIndices)
{
  UFG::qVector3 *v8; // r10
  unsigned int v9; // er13
  UFG::qVector3 *v10; // rbp
  unsigned int v11; // eax
  unsigned int *v12; // rcx
  UFG::SectionLayout *v13; // rdx
  __int64 v14; // rax
  signed __int64 v15; // r8
  __int64 v16; // rax
  signed __int64 v17; // rcx
  signed __int64 v18; // r8
  signed __int64 v19; // rcx
  __int64 v20; // rax
  signed __int64 v21; // rdi
  __int64 v22; // r12
  signed __int64 v23; // rbx
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  unsigned int v27; // er9
  unsigned int v28; // edx
  __int64 v29; // r8
  __int64 v30; // rcx
  signed __int64 v31; // rax
  __int64 v32; // rdx
  __int64 v33; // rcx
  unsigned int v34; // eax
  unsigned int *v35; // rdx
  unsigned int v36; // ecx
  bool v37; // zf
  unsigned int v38; // edx
  unsigned int v39; // [rsp+20h] [rbp-58h]
  unsigned int v40; // [rsp+24h] [rbp-54h]
  unsigned int *v41; // [rsp+28h] [rbp-50h]
  __int64 v42; // [rsp+30h] [rbp-48h]
  UFG::qVector3 *v43; // [rsp+88h] [rbp+10h]

  v43 = lookahead_position;
  v8 = lookahead_position;
  v9 = sVisitMagic + 1;
  v10 = pov_position;
  ++sVisitMagic;
  v11 = (_pov_section_index != _lookahead_section_index) + 1;
  if ( v11 == 1 )
  {
    v39 = _pov_section_index;
  }
  else
  {
    v39 = _lookahead_section_index;
    v40 = _pov_section_index;
  }
  if ( (_pov_section_index != _lookahead_section_index) != -1 )
  {
    v12 = &v39;
    v42 = v11;
    v13 = UFG::gSectionLayout;
    v41 = &v39;
    while ( 1 )
    {
      v14 = v13->mSections.mOffset;
      v15 = (signed __int64)(v14 ? (UFG::qOffset64<UFG::Section *> *)((char *)&v13->mSections + v14) : 0i64);
      v16 = v13->mSectionVis.mOffset;
      v17 = v15 + 48i64 * *v12;
      v18 = (signed __int64)(v16 ? (UFG::qOffset64<UFG::SectionVis *> *)((char *)&v13->mSectionVis + v16) : 0i64);
      v19 = 96i64 * *(unsigned __int16 *)(v17 + 6);
      v20 = *(_QWORD *)(v19 + v18 + 40);
      v21 = v20 ? v20 + v19 + v18 + 40 : 0i64;
      if ( *(_WORD *)(v19 + v18 + 26) )
        break;
LABEL_55:
      v12 = v41 + 1;
      v37 = v42-- == 1;
      ++v41;
      if ( v37 )
        return;
    }
    v22 = *(unsigned __int16 *)(v19 + v18 + 26);
    while ( 1 )
    {
      if ( *(_QWORD *)v21 )
        v23 = *(_QWORD *)v21 + v21;
      else
        v23 = 0i64;
      if ( *(_DWORD *)(v23 + 76) != v9 )
      {
        v37 = *(_DWORD *)(v23 + 96) == 0;
        *(_DWORD *)(v23 + 76) = v9;
        if ( v37 )
        {
          if ( UFG::SectionChooser::LineInsideTriggerHull((UFG::CellTrigger *)v23, v10, v8, 0i64) )
            goto LABEL_37;
        }
        else
        {
          v24 = v10->x;
          v25 = v10->y;
          if ( v10->x >= *(float *)(v23 + 8)
            && v24 <= *(float *)(v23 + 16)
            && v25 >= *(float *)(v23 + 12)
            && v25 <= *(float *)(v23 + 20) )
          {
            v26 = v10->z;
            if ( v26 > *(float *)(v23 + 84) && v26 < *(float *)(v23 + 88) )
            {
              v27 = *(_DWORD *)(v23 + 24);
              v28 = 0;
              if ( v27 )
              {
                v29 = *(_QWORD *)(v23 + 32);
                v30 = 0i64;
                do
                {
                  v31 = v29 ? v29 + v23 + 32 : 0i64;
                  if ( (float)((float)((float)(v25 - *(float *)(v30 + v31 + 4)) * *(float *)(v30 + v31 + 12))
                             + (float)((float)(v24 - *(float *)(v30 + v31)) * *(float *)(v30 + v31 + 8))) > 0.0 )
                    goto LABEL_53;
                  ++v28;
                  v30 += 16i64;
                }
                while ( v28 < v27 );
              }
LABEL_37:
              v32 = *STDSectionCount;
              v33 = 0i64;
              if ( (_DWORD)v32 )
              {
                while ( STDVisIndices[v33] != *(_DWORD *)(v21 + 8) )
                {
                  v33 = (unsigned int)(v33 + 1);
                  if ( (unsigned int)v33 >= (unsigned int)v32 )
                    goto LABEL_40;
                }
                v38 = *(_DWORD *)(v23 + 72);
                if ( *STDVisIndices != v38 )
                  STDVisIndices[v33] = v38;
              }
              else
              {
LABEL_40:
                if ( (unsigned int)v32 < 7 )
                {
                  STDVisIndices[v32] = *(_DWORD *)(v23 + 72);
                  ++*STDSectionCount;
                }
              }
              v34 = 0;
              if ( *LODSectionCount )
              {
                v35 = LODVisIndices;
                while ( 1 )
                {
                  v36 = *v35;
                  v37 = gExtendedMidground ? v36 == *(_DWORD *)(v21 + 16) : v36 == *(_DWORD *)(v21 + 12);
                  if ( v37 )
                    break;
                  ++v34;
                  ++v35;
                  if ( v34 >= *LODSectionCount )
                    goto LABEL_53;
                }
                LODVisIndices[v34] = *(_DWORD *)(v21 + 8);
              }
              goto LABEL_53;
            }
          }
        }
      }
LABEL_53:
      v8 = v43;
      v21 += 32i64;
      if ( !--v22 )
      {
        v13 = UFG::gSectionLayout;
        goto LABEL_55;
      }
    }
  }
}

// File Line: 1823
// RVA: 0x233AA0
void __fastcall UFG::SectionChooser::ModifyLookaheadForStickyTriggers(unsigned int _vis_index_current_section, unsigned int _vis_index_lookahead_section, UFG::qVector3 *viewerPosition, UFG::qVector3 *currentLookaheadPos)
{
  UFG::qVector3 *v4; // rdi
  unsigned int v5; // ebp
  UFG::qVector3 *v6; // r12
  unsigned int *v7; // r14
  __int64 v8; // r15
  __int64 v9; // rcx
  char *v10; // rdx
  signed __int64 v11; // rcx
  __int64 v12; // rax
  char *v13; // rbx
  __int64 v14; // rsi
  UFG::CellTrigger *v15; // rcx
  float v16; // xmm1_4
  float v17; // xmm0_4
  unsigned int v18; // [rsp+20h] [rbp-38h]
  unsigned int v19; // [rsp+24h] [rbp-34h]
  UFG::qVector3 clippedPos; // [rsp+28h] [rbp-30h]

  v4 = currentLookaheadPos;
  v5 = sVisitMagic_0 + 1;
  v6 = viewerPosition;
  v18 = _vis_index_current_section;
  v19 = _vis_index_lookahead_section;
  ++sVisitMagic_0;
  if ( (_vis_index_current_section != _vis_index_lookahead_section) != -1 )
  {
    v7 = &v18;
    v8 = (unsigned int)(_vis_index_current_section != _vis_index_lookahead_section) + 1;
    do
    {
      v9 = UFG::gSectionLayout->mSectionVis.mOffset;
      if ( v9 )
        v10 = (char *)&UFG::gSectionLayout->mSectionVis + v9;
      else
        v10 = 0i64;
      v11 = 96i64 * *v7;
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
            if ( UFG::SectionChooser::LineInsideTriggerHull(v15, v6, v4, &clippedPos) )
            {
              v16 = clippedPos.y;
              v4->x = clippedPos.x;
              v17 = clippedPos.z;
              v4->y = v16;
              v4->z = v17;
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
__int64 __fastcall UFG::SectionChooser::ModifyZonesFromTriggersForPosition(UFG::qVector3 *position, unsigned int vis_index_chooser_section, unsigned int zoneCount, unsigned int *mZoneIndices)
{
  unsigned int v4; // er10
  unsigned int *v5; // rsi
  __int64 v6; // r8
  UFG::qVector3 *v7; // rbp
  signed __int64 v8; // rcx
  __int64 v9; // rax
  signed __int64 v10; // rbx
  unsigned int v11; // eax
  __int64 v12; // rdi
  __int64 v13; // rax
  float v14; // xmm3_4
  float v15; // xmm2_4
  unsigned int v16; // er11
  unsigned int v17; // er8
  __int64 v18; // r9
  __int64 v19; // rdx
  signed __int64 v20; // rcx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int *v23; // rax

  v4 = zoneCount;
  v5 = mZoneIndices;
  v6 = UFG::gSectionLayout->mSectionVis.mOffset;
  v7 = position;
  if ( v6 )
    v6 += (__int64)&UFG::gSectionLayout->mSectionVis;
  v8 = 96i64 * vis_index_chooser_section;
  v9 = *(_QWORD *)(v8 + v6 + 56);
  if ( v9 )
    v10 = v9 + v6 + v8 + 56;
  else
    v10 = 0i64;
  v11 = *(_DWORD *)(v8 + v6 + 64);
  if ( v11 )
  {
    v12 = v11;
    do
    {
      v13 = *(_QWORD *)v10;
      if ( *(_QWORD *)v10 )
        v13 += v10;
      v14 = v7->x;
      v15 = v7->y;
      if ( v7->x >= *(float *)(v13 + 8)
        && v14 <= *(float *)(v13 + 16)
        && v15 >= *(float *)(v13 + 12)
        && v15 <= *(float *)(v13 + 20) )
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
            if ( (float)((float)((float)(v15 - *(float *)(v19 + v20 + 4)) * *(float *)(v19 + v20 + 12))
                       + (float)((float)(v14 - *(float *)(v19 + v20)) * *(float *)(v19 + v20 + 8))) > 0.0 )
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
            if ( v4 )
            {
              v23 = v5;
              while ( *v23 != v21 )
              {
                ++v22;
                ++v23;
                if ( v22 >= v4 )
                  goto LABEL_26;
              }
            }
            else
            {
LABEL_26:
              v5[1] = v21;
              v4 = 2;
            }
          }
        }
      }
      v10 += 8i64;
      --v12;
    }
    while ( v12 );
  }
  return v4;
}

// File Line: 1931
// RVA: 0x230320
void __fastcall UFG::SectionChooser::AddPOV(UFG::qVector3 *position, UFG::qVector3 *direction, UFG::qVector3 *camera_direction, UFG::qVector3 *velocity, float deltaTime, UFG::SimObject *simObject, unsigned int flags, bool is_ingame)
{
  UFG::qVector3 *v8; // r12
  unsigned int v9; // ebx
  char v10; // r13
  bool v11; // al
  int v12; // ebp
  unsigned int v13; // er15
  unsigned int v14; // er14
  UFG::SectionChooser::SectionInfo *v15; // rsi
  unsigned __int64 v16; // rdi
  bool v17; // zf
  UFG::SectionChooser::SectionInfo *v18; // rbx
  UFG::SectionChooser::SectionInfo *v19; // rbx
  UFG::BSP *v20; // r14
  unsigned int v21; // esi
  unsigned int v22; // eax
  UFG::SectionLayout *v23; // rbp
  __int64 v24; // rcx
  char *v25; // rcx
  signed __int64 v26; // rbx
  __int64 v27; // r13
  float v28; // xmm2_4
  float v29; // xmm6_4
  float v30; // xmm10_4
  float v31; // xmm11_4
  float v32; // xmm12_4
  float v33; // xmm7_4
  __m128 v34; // xmm8
  float v35; // xmm9_4
  __m128 v36; // xmm3
  float v37; // xmm7_4
  float v38; // xmm8_4
  float v39; // xmm9_4
  float v40; // xmm0_4
  signed int v41; // er12
  signed int v42; // edi
  float v43; // xmm6_4
  unsigned int v44; // ebx
  bool v45; // di
  unsigned int v46; // eax
  UFG::SectionChooser *v47; // rcx
  __int64 v48; // rcx
  char *v49; // rdx
  unsigned int v50; // eax
  __int64 v51; // rcx
  signed __int64 v52; // rdx
  __int64 v53; // rax
  signed __int64 v54; // rcx
  unsigned int v55; // edx
  signed __int64 v56; // r8
  __int64 v57; // r9
  __int64 v58; // rcx
  signed __int64 v59; // rax
  signed __int64 v60; // rcx
  unsigned int baseSectionIndex; // [rsp+40h] [rbp-C8h]
  bool v62; // [rsp+44h] [rbp-C4h]
  UFG::qVector3 positiona; // [rsp+48h] [rbp-C0h]
  UFG::qVector3 *v64; // [rsp+118h] [rbp+10h]
  UFG::qVector3 *v65; // [rsp+120h] [rbp+18h]
  UFG::qVector3 *v66; // [rsp+128h] [rbp+20h]
  BOOL flagsa; // [rsp+140h] [rbp+38h]

  v66 = velocity;
  v65 = camera_direction;
  v64 = direction;
  v8 = position;
  v9 = flags >> 2;
  LOBYTE(v9) = (flags >> 2) & 1;
  v10 = flags & 1;
  v11 = (flags >> 1) & 1;
  flagsa = v9;
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
      LOBYTE(v9) = flagsa;
      velocity = v66;
      camera_direction = v65;
      direction = v64;
    }
    ((void (__fastcall *)(UFG::SectionChooser::Lookahead *, UFG::qVector3 *, UFG::qVector3 *, UFG::qVector3 *, UFG::qVector3 *, _DWORD, char))UFG::SectionChooser::mLookahead->vfptr->Process)(
      UFG::SectionChooser::mLookahead,
      v8,
      direction,
      camera_direction,
      velocity,
      LODWORD(deltaTime),
      v10);
    v20 = UFG::SectionChooser::mBSP;
    if ( UFG::SectionChooser::mBSP )
      v21 = UFG::BSP::GetSpaceFromPoint(UFG::SectionChooser::mBSP, v8, 1, 1)->mSectionIndex;
    else
      v21 = -1;
    v22 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v21, v9);
    v23 = UFG::gSectionLayout;
    mCurrentCellIndex = v22;
    v24 = UFG::gSectionLayout->mSections.mOffset;
    baseSectionIndex = v22;
    if ( v24 )
      v25 = (char *)&UFG::gSectionLayout->mSections + v24;
    else
      v25 = 0i64;
    v26 = (signed __int64)&v25[48 * v22];
    if ( is_ingame )
    {
      UFG::ZoneTag::Update(v21);
      v20 = UFG::SectionChooser::mBSP;
      v23 = UFG::gSectionLayout;
    }
    v27 = v21;
    if ( (*(_BYTE *)(v26 + 4) >> 1) & 1 )
    {
      v45 = flagsa;
    }
    else
    {
      v28 = 0.0;
      v29 = UFG::SectionChooser::mLookahead->mCurrentLookaheadDistance;
      v34 = (__m128)LODWORD(UFG::SectionChooser::mLookahead->mCurrentLookaheadPos.y);
      v30 = v8->x;
      v31 = v8->y;
      v32 = v8->z;
      v33 = UFG::SectionChooser::mLookahead->mCurrentLookaheadPos.x - v8->x;
      v34.m128_f32[0] = v34.m128_f32[0] - v31;
      v35 = UFG::SectionChooser::mLookahead->mCurrentLookaheadPos.z - v32;
      v36 = v34;
      v36.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v33 * v33)) + (float)(v35 * v35);
      if ( v36.m128_f32[0] != 0.0 )
        v28 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v36));
      v37 = v33 * v28;
      v38 = v34.m128_f32[0] * v28;
      v39 = v35 * v28;
      v40 = FLOAT_5_0;
      if ( (float)(signed int)(float)(v29 * 0.1) <= 5.0 )
        v40 = (float)(signed int)(float)(v29 * 0.1);
      v41 = (signed int)v40;
      v42 = 1;
      if ( (unsigned int)(signed int)v40 < 1 )
      {
        v45 = flagsa;
      }
      else
      {
        v43 = v29 / (float)v41;
        while ( 1 )
        {
          positiona.x = (float)((float)(v37 * (float)v42) * v43) + v30;
          positiona.y = (float)((float)(v38 * (float)v42) * v43) + v31;
          positiona.z = (float)((float)(v39 * (float)v42) * v43) + v32;
          v44 = v20 ? UFG::BSP::GetSpaceFromPoint(v20, &positiona, 1, 0)->mSectionIndex : -1;
          if ( v44 != v21 )
            break;
          if ( ++v42 > (unsigned int)v41 )
          {
            v45 = flagsa;
            goto LABEL_35;
          }
        }
        v45 = flagsa;
        v50 = UFG::SectionChooser::GetCellToLoadFromVisIndex(v44, flagsa);
        v51 = v23->mSections.mOffset;
        if ( v51 )
          v52 = (signed __int64)&v23->mSections + v51;
        else
          v52 = 0i64;
        if ( !((*(_BYTE *)(v52 + 48i64 * v50 + 4) >> 1) & 1) )
        {
          v53 = v23->mSectionVis.mOffset;
          v54 = (signed __int64)(v53 ? (UFG::qOffset64<UFG::SectionVis *> *)((char *)&v23->mSectionVis + v53) : 0i64);
          v55 = 0;
          v56 = v54 + 96i64 * v44;
          if ( *(_WORD *)(v56 + 4) )
          {
            v57 = *(_QWORD *)(v56 + 8);
            v58 = 0i64;
            while ( 1 )
            {
              v59 = v57 ? v57 + v56 + 8 : 0i64;
              if ( *(unsigned __int16 *)(v58 + v59) == v21 )
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
    }
LABEL_35:
    UFG::SectionChooser::ModifyLookaheadForStickyTriggers(
      v21,
      v27,
      &UFG::SectionChooser::mLookahead->mViewerPosition,
      &UFG::SectionChooser::mLookahead->mCurrentLookaheadPos);
    if ( !UFG::SectionLayout::IsLookaheadAllowed(v21, v27) )
      v27 = v21;
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
      v60 = (signed __int64)&v49[96 * v27];
      UFG::SectionChooser::mSTDZoneIndices[0] = *(unsigned __int16 *)(v60 + 52);
      if ( *(_WORD *)(v60 + 52) != -1 )
        v13 = 1;
      dword_1423A8D94 = *(unsigned __int16 *)(v60 + 54);
      if ( *(_WORD *)(v60 + 54) != -1 )
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
void __fastcall UFG::SectionChooser::CalculateVisibleSectionIndices(unsigned int baseSectionIndex, unsigned int currentSectionIndex, bool keepCurrentlyLoadedAltLayers)
{
  __int64 v3; // rbx
  bool v4; // r14
  __int64 v5; // rsi
  unsigned int v6; // ebp
  __int64 v7; // r8
  char *v8; // rdx
  unsigned int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // er10
  unsigned int v13; // esi
  UFG::SectionChooser::SectionInfo *v14; // r11
  unsigned int *v15; // rdx
  signed __int64 v16; // r9
  __int64 v17; // r8
  __int64 v18; // rax
  __int64 v19; // rdi
  __int64 v20; // rbp
  int v21; // eax
  __int64 v22; // rdi
  int v23; // eax

  v3 = 0i64;
  v4 = keepCurrentlyLoadedAltLayers;
  v5 = currentSectionIndex;
  v6 = baseSectionIndex;
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
        v18 = *(unsigned int *)((char *)v15 + v16);
        ++v15;
        *(v15 - 1) = v14[v18].mSection->mVisIndex;
        --v17;
      }
      while ( v17 );
    }
  }
  else
  {
    v7 = UFG::gSectionLayout->mSections.mOffset;
    if ( v7 )
      v8 = (char *)&UFG::gSectionLayout->mSections + v7;
    else
      v8 = 0i64;
    v9 = *(unsigned __int16 *)&v8[48 * v5 + 6];
    v10 = UFG::SectionLayout::GetHighLODSectionVisIndices(v9, mSTDSectionVisIndices, 0x40u);
    mLOWSectionCount = 0;
    mSTDSectionCount = v10;
    if ( gExtendedMidground )
      v11 = UFG::SectionLayout::GetLowLODSectionVisIndices_HD(v9, mLOWSectionVisIndices, 64u);
    else
      v11 = UFG::SectionLayout::GetLowLODSectionVisIndices(v9, mLOWSectionVisIndices, 64u);
    mLOWSectionCount = v11;
    UFG::SectionChooser::ModifyVisibliltyFromTriggersForPosition(
      &UFG::SectionChooser::mLookahead->mViewerPosition,
      &UFG::SectionChooser::mLookahead->mCurrentLookaheadPos,
      v6,
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
      v21 = UFG::SectionChooser::GetCellToLoadFromVisIndex(mSTDSectionVisIndices[v19], v4);
      ++v19;
      *(_DWORD *)(v19 * 4 + 5406101260i64) = v21;
      --v20;
    }
    while ( v20 );
  }
  if ( v13 )
  {
    v22 = v13;
    do
    {
      v23 = UFG::SectionChooser::GetCellToLoadFromVisIndex(mLOWSectionVisIndices[v3], v4);
      ++v3;
      *(_DWORD *)(v3 * 4 + 5406101532i64) = v23;
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
  bool v2; // si
  unsigned int v3; // edi
  UFG::SectionLayout *v4; // rbp
  __int64 v5; // r15
  char *v6; // r14
  __int64 v7; // rax
  signed __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // r8
  signed __int64 v11; // rdx
  signed __int64 v12; // rcx
  __int64 v13; // rax
  const void *v14; // rdx
  __int64 v15; // rbx
  unsigned int v16; // ecx
  char *v17; // rax
  char *v18; // rdx
  __int64 v19; // r10
  UFG::SectionChooser::SectionInfo *v20; // rax
  __int64 v21; // r8
  int v22; // er9
  char Dst; // [rsp+20h] [rbp-118h]
  char v24; // [rsp+24h] [rbp-114h]
  char dest; // [rsp+A0h] [rbp-98h]

  v2 = layer_enabled;
  v3 = UFG::SectionLayout::GetLayerIndex(layer_name);
  if ( v3 != -1 )
  {
    UFG::qMemCopy(&dest, mSTDSectionCellIndices, 4 * mSTDSectionCount);
    if ( mSTDSectionCount )
    {
      v4 = UFG::gSectionLayout;
      v5 = mSTDSectionCount;
      v6 = &dest;
      do
      {
        v7 = v4->mSections.mOffset;
        if ( v7 )
          v8 = (signed __int64)&v4->mSections + v7;
        else
          v8 = 0i64;
        v9 = v4->mSectionVis.mOffset;
        v10 = *(unsigned __int16 *)(v8 + 48i64 * *(unsigned int *)v6 + 6);
        if ( v9 )
          v11 = (signed __int64)&v4->mSectionVis + v9;
        else
          v11 = 0i64;
        v12 = v11 + 96 * v10;
        v13 = *(_QWORD *)(v12 + 32);
        if ( v13 )
          v14 = (const void *)(v12 + v13 + 32);
        else
          v14 = 0i64;
        v15 = *(unsigned __int16 *)(v12 + 24);
        if ( *(_WORD *)(v12 + 24) )
          memmove(&Dst, v14, 8i64 * *(unsigned __int16 *)(v12 + 24));
        v16 = 0;
        if ( (_DWORD)v15 )
        {
          v17 = &v24;
          while ( *(_DWORD *)v17 != v3 )
          {
            ++v16;
            v17 += 8;
            if ( v16 >= (unsigned int)v15 )
              goto LABEL_33;
          }
          v18 = &v24;
          v19 = v15;
          do
          {
            v20 = UFG::SectionChooser::mSectionInfo;
            v21 = *((unsigned int *)v18 - 1);
            v22 = (unsigned __int8)UFG::SectionChooser::mSectionInfo[v21].meLoadStateSTD.mValue;
            if ( (unsigned int)(v22 - 1) <= 1 )
            {
              if ( v2 )
                UFG::SectionChooser::mSectionInfo[v21].mbFlushing = *(_DWORD *)v18 != v3;
              else
                UFG::SectionChooser::mSectionInfo[v21].mbFlushing = 1;
            }
            else if ( v22 == 3 )
            {
              if ( v2 )
              {
                if ( *(_DWORD *)v18 == v3 )
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
  if ( UFG::SectionChooser::meSuppressLOD != 2 )
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
  unsigned int v1; // edi
  UFG::SectionChooser::SectionInfo *v2; // rsi

  v0 = 0;
  v1 = 0;
  if ( UFG::SectionChooser::mSectionCount )
  {
    do
    {
      v2 = &UFG::SectionChooser::mSectionInfo[v1];
      if ( (unsigned int)UFG::DataStreamer::GetStreamState(&v2->mhStreamHandleSTD) - 2 <= 1 )
        v0 += UFG::DataStreamer::GetReadBytes(&v2->mhStreamHandleSTD);
      if ( (unsigned int)UFG::DataStreamer::GetStreamState(&v2->mhStreamHandleMID) - 2 <= 1 )
        v0 += UFG::DataStreamer::GetReadBytes(&v2->mhStreamHandleMID);
      if ( (unsigned int)UFG::DataStreamer::GetStreamState(&v2->mhStreamHandleGAM) - 2 <= 1 )
        v0 += UFG::DataStreamer::GetReadBytes(&v2->mhStreamHandleGAM);
      ++v1;
    }
    while ( v1 < UFG::SectionChooser::mSectionCount );
  }
  return v0;
}

