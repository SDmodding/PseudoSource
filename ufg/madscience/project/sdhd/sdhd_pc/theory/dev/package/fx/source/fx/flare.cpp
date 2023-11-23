// File Line: 21
// RVA: 0x146B590
__int64 Render::_dynamic_initializer_for__gFlareManager__()
{
  UFG::qResourceHandle::qResourceHandle(&Render::gFlareManager.mFlareMat);
  `eh vector constructor iterator(
    (char *)Render::gFlareManager.mFlares,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFlareManager__);
}

// File Line: 25
// RVA: 0x1C15F0
void __fastcall Render::Flare::Flare(Render::Flare *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4

  this->mTarget = 0i64;
  *(_QWORD *)&this->mHardwareOcclusionQuery.mQueryID = -1i64;
  this->mHardwareOcclusionQuery.mTarget = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mSettings);
  y = UFG::qMatrix44::msIdentity.v0.y;
  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  this->mTransform.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->mTransform.v0.y = y;
  this->mTransform.v0.z = z;
  this->mTransform.v0.w = w;
  v5 = UFG::qMatrix44::msIdentity.v1.y;
  v6 = UFG::qMatrix44::msIdentity.v1.z;
  v7 = UFG::qMatrix44::msIdentity.v1.w;
  this->mTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mTransform.v1.y = v5;
  this->mTransform.v1.z = v6;
  this->mTransform.v1.w = v7;
  v8 = UFG::qMatrix44::msIdentity.v2.y;
  v9 = UFG::qMatrix44::msIdentity.v2.z;
  v10 = UFG::qMatrix44::msIdentity.v2.w;
  this->mTransform.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->mTransform.v2.y = v8;
  this->mTransform.v2.z = v9;
  this->mTransform.v2.w = v10;
  v11 = UFG::qMatrix44::msIdentity.v3.y;
  v12 = UFG::qMatrix44::msIdentity.v3.z;
  v13 = UFG::qMatrix44::msIdentity.v3.w;
  this->mTransform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->mTransform.v3.y = v11;
  this->mTransform.v3.z = v12;
  this->mTransform.v3.w = v13;
  *(_QWORD *)&this->mProbeIssueCounter = 0i64;
  this->mSplitScreenViewMask = -1;
  this->mFXOverridePointer.m_pPointer = 0i64;
}

// File Line: 30
// RVA: 0x1C3B90
void __fastcall Render::Flare::~Flare(Render::Flare *this)
{
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v3; // rdi
  char *mTriangleInfo; // rdx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  Illusion::IOcclusion *OcclusionSystem; // rax
  Illusion::IOcclusion *v8; // rdi
  __int64 mQueryID; // rdx
  __int64 mUnculledQueryID; // rdx

  m_pPointer = this->mFXOverridePointer.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v3 = this->mFXOverridePointer.m_pPointer;
    if ( v3->mReferenceCount <= 0 )
    {
      if ( v3 )
      {
        mTriangleInfo = (char *)v3->mTriangleInfo;
        if ( mTriangleInfo )
          UFG::qMemoryPool::Free(v3->mMemoryPool, mTriangleInfo);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v3);
      }
      this->mFXOverridePointer.m_pPointer = 0i64;
    }
  }
  Inventory = `UFG::qGetResourceInventory<Render::FlareSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FlareSettings>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xA6535FBB);
    `UFG::qGetResourceInventory<Render::FlareSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSettings, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettings);
  OcclusionSystem = Render::GetOcclusionSystem();
  v8 = OcclusionSystem;
  mQueryID = this->mHardwareOcclusionQuery.mQueryID;
  if ( (_DWORD)mQueryID != -1 )
  {
    OcclusionSystem->vfptr->ReleaseQueryHandle(OcclusionSystem, mQueryID, this->mHardwareOcclusionQuery.mTarget);
    this->mHardwareOcclusionQuery.mQueryID = -1;
  }
  mUnculledQueryID = this->mHardwareOcclusionQuery.mUnculledQueryID;
  if ( (_DWORD)mUnculledQueryID != -1 )
  {
    v8->vfptr->ReleaseQueryHandle(v8, mUnculledQueryID, this->mHardwareOcclusionQuery.mTarget);
    this->mHardwareOcclusionQuery.mUnculledQueryID = -1;
  }
}

// File Line: 44
// RVA: 0x1CE860
void __fastcall Render::FlareManager::Init(Render::FlareManager *this)
{
  _WORD *v2; // rdi
  unsigned int v3; // r14d
  Illusion::Material *v4; // rsi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  UFG::qResourceWarehouse *v13; // rax
  __int64 mOffset; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v16; // rax
  unsigned int v17; // eax
  unsigned int v18; // eax

  v2 = 0i64;
  v3 = UFG::qStringHashUpper32("FlareMat", -1);
  v4 = Illusion::Factory::NewMaterial("FlareMat", v3, 4u, 0i64, 0i64, 0i64);
  v5 = UFG::qStringHash32("FLARE", 0xFFFFFFFF);
  LOWORD(v4[1].mNode.mChild[0]) = 0;
  v6 = v5;
  HIDWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4[1].mTypeUID = -1957338719;
  LODWORD(v4[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v6;
  LODWORD(v4[1].mNode.mParent) = v7;
  v8 = UFG::qStringHash32("DEFAULT", 0xFFFFFFFF);
  *(_WORD *)&v4[1].mDebugName[12] = 0;
  v9 = v8;
  *(_DWORD *)&v4[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v4[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v4[1].mStateBlockMask.mFlags[0]) = v9;
  *(_DWORD *)&v4[1].mDebugName[4] = v10;
  LOWORD(v4[1].mMaterialUser.mOffset) = 0;
  *(&v4[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v4[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v4[2].mNode.mUID = 662883558;
  v4[1].mNumParams = v11;
  LOWORD(v4[2].mTypeUID) = 0;
  HIDWORD(v4[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v4[2].UFG::qResourceData + 22) = 1002903008;
  LODWORD(v4[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v12;
  *(_DWORD *)&v4[2].mDebugName[28] = 1660426324;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, v4);
  if ( *(_DWORD *)&v4[2].mDebugName[28] != 1660426324 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v4[2].mDebugName[4],
      *((_DWORD *)&v4[2].UFG::qResourceData + 22),
      0x62F81854u);
    mOffset = v4->mMaterialUser.mOffset;
    if ( mOffset )
      v2 = (_WORD *)((char *)&v4->mMaterialUser + mOffset);
    *v2 |= 0x20u;
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v16, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mFlareMat, 0xB4C26312, v3, Inventory);
  v17 = UFG::qStringHash32("cbFlareSettings", 0xFFFFFFFF);
  this->mSettingsStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                       &Illusion::gStateSystem,
                                                       v17,
                                                       "cbFlareSettings",
                                                       0);
  v18 = UFG::qStringHash32("cbDynamicFlareInfo", 0xFFFFFFFF);
  this->mDynamicInfoStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                          &Illusion::gStateSystem,
                                                          v18,
                                                          "cbDynamicFlareInfo",
                                                          0);
}

// File Line: 75
// RVA: 0x1D26D0
void __fastcall Render::FlareManager::RemoveFlare(Render::FlareManager *this, Render::Flare *pFlare)
{
  UFG::qResourceData *mData; // rax
  __int64 v5; // rcx
  UFG::qArray<Render::Flare *,0> *v6; // rbx
  Render::Flare **p; // r8
  Render::Flare *v8; // rdi
  __int64 v9; // rbp
  Illusion::IOcclusion *OcclusionSystem; // rax
  __int64 mQueryID; // rdx
  Illusion::IOcclusion *v12; // rsi
  __int64 mUnculledQueryID; // rdx

  Render::GetOcclusionSystem();
  mData = pFlare->mSettings.mData;
  if ( mData )
  {
    v5 = 0i64;
    v6 = &this->mFlares[mData[15].mTypeUID];
    if ( v6->size )
    {
      p = v6->p;
      while ( p[v5] != pFlare )
      {
        v5 = (unsigned int)(v5 + 1);
        if ( (unsigned int)v5 >= v6->size )
          return;
      }
      v8 = p[v5];
      v9 = v5;
      OcclusionSystem = Render::GetOcclusionSystem();
      mQueryID = v8->mHardwareOcclusionQuery.mQueryID;
      v12 = OcclusionSystem;
      if ( (_DWORD)mQueryID != -1 )
      {
        OcclusionSystem->vfptr->ReleaseQueryHandle(OcclusionSystem, mQueryID, v8->mHardwareOcclusionQuery.mTarget);
        v8->mHardwareOcclusionQuery.mQueryID = -1;
      }
      mUnculledQueryID = v8->mHardwareOcclusionQuery.mUnculledQueryID;
      if ( (_DWORD)mUnculledQueryID != -1 )
      {
        v12->vfptr->ReleaseQueryHandle(v12, mUnculledQueryID, v8->mHardwareOcclusionQuery.mTarget);
        v8->mHardwareOcclusionQuery.mUnculledQueryID = -1;
      }
      if ( v6->size > 1 )
        v6->p[v9] = v6->p[v6->size - 1];
      if ( v6->size > 1 )
        --v6->size;
      else
        v6->size = 0;
    }
  }
}

// File Line: 100
// RVA: 0x1C6D20
void __fastcall Render::FlareManager::AddFlare(Render::FlareManager *this, UFG::qReflectInventoryBase *pFlare)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v3; // rdi
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **p; // rax

  if ( pFlare->mBaseNode.mNeighbours[1] )
  {
    LODWORD(pFlare->mNameLookups.mTree.mHead.mParent) = 0;
    pFlare->mBaseNode.mUID = -1i64;
    pFlare->mBaseNode.mParent = 0i64;
    v3 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mFlares[SLODWORD(pFlare->mBaseNode.mNeighbours[1][28].mChildren[1])];
    size = v3->size;
    capacity = v3->capacity;
    v6 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v7 = 2 * capacity;
      else
        v7 = 1;
      for ( ; v7 < v6; v7 *= 2 )
        ;
      if ( v7 <= 2 )
        v7 = 2;
      if ( v7 - v6 > 0x10000 )
        v7 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v3, v7, "qArray.Add");
    }
    p = v3->p;
    v3->size = v6;
    p[size] = pFlare;
  }
}

// File Line: 156
// RVA: 0x1D3D40
void __fastcall Render::FlareManager::Render(
        Render::FlareManager *this,
        Render::View *view,
        float fTime,
        Render::eFlareQueue queue,
        unsigned int flare_flags)
{
  __int64 v5; // r14
  float v8; // xmm8_4
  char v9; // si
  unsigned int v10; // eax
  int v11; // xmm6_4
  int v12; // xmm11_4
  float x; // xmm9_4
  float v14; // xmm1_4
  float z; // xmm12_4
  float v16; // xmm7_4
  int v17; // xmm9_4
  int v18; // xmm12_4
  float v19; // xmm7_4
  float v20; // xmm10_4
  __int64 v21; // rdx
  Render::Flare *v22; // r13
  UFG::qResourceData *mData; // rbx
  char *v24; // rax
  float mLifeTime; // ecx
  __m128 y_low; // xmm3
  float v27; // xmm9_4
  float v28; // xmm14_4
  float *v29; // rcx
  __int64 v30; // rdx
  float *v31; // rax
  float *v32; // rax
  float v33; // xmm1_4
  float v34; // xmm0_4
  char v35; // si
  bool v36; // al
  Illusion::IOcclusion *OcclusionSystem; // rax
  __int64 mQueryID; // rdx
  __int64 mUnculledQueryID; // r8
  double v40; // xmm0_8
  float v41; // xmm2_4
  float v42; // xmm2_4
  float v43; // xmm4_4
  float w; // xmm5_4
  float v45; // xmm0_4
  float v46; // xmm6_4
  float y; // xmm7_4
  float v48; // xmm8_4
  float v49; // xmm9_4
  float v50; // xmm10_4
  float v51; // xmm11_4
  float v52; // xmm12_4
  float v53; // xmm13_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  __m128 v60; // xmm7
  float v61; // xmm4_4
  __m128 v62; // xmm2
  float v63; // xmm1_4
  float v64; // xmm7_4
  __int64 v65; // rax
  float *mDebugName; // rbx
  float v67; // xmm2_4
  float v68; // xmm6_4
  float v69; // xmm2_4
  float v70; // xmm4_4
  float v71; // xmm3_4
  float scale; // xmm6_4
  UFG::qResourceData *v73; // rdi
  unsigned int v74; // r8d
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  UFG::qResourceData *v76; // rdi
  unsigned int v77; // r8d
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v78; // rax
  UFG::qResourceData *v79; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  unsigned int mNext_high; // eax
  unsigned int v82; // r8d
  bool v83; // zf
  int v84; // eax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v85; // rax
  char *v86; // rdi
  unsigned int mSettingsStateBlockIndex_low; // r14d
  Illusion::StateValues *StateValues; // rax
  unsigned int mDynamicInfoStateBlockIndex_low; // edi
  Illusion::StateValues *v90; // rax
  int v91; // [rsp+30h] [rbp-A8h]
  float v92; // [rsp+34h] [rbp-A4h]
  float v93; // [rsp+38h] [rbp-A0h]
  __int64 v94; // [rsp+40h] [rbp-98h]
  float v95; // [rsp+48h] [rbp-90h]
  unsigned int v96; // [rsp+4Ch] [rbp-8Ch]
  __int64 v97; // [rsp+50h] [rbp-88h]
  float v98; // [rsp+58h] [rbp-80h]
  float v99; // [rsp+5Ch] [rbp-7Ch]
  UFG::qMatrix44 probeTransform; // [rsp+60h] [rbp-78h] BYREF
  char v101; // [rsp+1B8h] [rbp+E0h]
  char v102; // [rsp+1C0h] [rbp+E8h]
  int vars0; // [rsp+1D0h] [rbp+F8h]
  void *retaddr; // [rsp+1D8h] [rbp+100h]

  v5 = queue;
  Render::GetOcclusionSystem();
  v8 = *(float *)&FLOAT_1_0;
  v9 = (unsigned __int8)retaddr & 1;
  v101 = (unsigned __int8)retaddr & 1;
  if ( ((unsigned __int8)retaddr & 1) != 0 )
    v95 = FLOAT_1_2;
  else
    v95 = *(float *)&FLOAT_1_0;
  Render::View::GetStateValues(view);
  v10 = 0;
  v11 = _xmm[0];
  v96 = 0;
  v12 = LODWORD(view->mViewWorld.v2.y) ^ _xmm[0];
  x = view->mViewWorld.v2.x;
  v14 = view->mViewWorld.v3.x;
  z = view->mViewWorld.v2.z;
  v16 = *(float *)&v12 * COERCE_FLOAT(LODWORD(view->mViewWorld.v3.y) ^ _xmm[0]);
  *(_QWORD *)&probeTransform.v2.z = 16 * (v5 + 2);
  v17 = LODWORD(x) ^ _xmm[0];
  v18 = LODWORD(z) ^ _xmm[0];
  v98 = *(float *)&v12;
  v91 = v17;
  v99 = *(float *)&v18;
  v19 = (float)(v16 + (float)(*(float *)&v17 * COERCE_FLOAT(LODWORD(v14) ^ _xmm[0])))
      + (float)(*(float *)&v18 * COERCE_FLOAT(LODWORD(view->mViewWorld.v3.z) ^ _xmm[0]));
  v93 = v19;
  if ( *(_DWORD *)((char *)&this->mFlareMat.mPrev + *(_QWORD *)&probeTransform.v2.z) )
  {
    v20 = FLOAT_N0_5;
    v21 = 16 * v5;
    v94 = 16 * v5;
    do
    {
      v22 = (*(Render::Flare ***)((char *)&this->mFlares[0].p + v21))[v10];
      mData = v22->mSettings.mData;
      if ( !mData )
        goto LABEL_12;
      if ( v9 && !*(_DWORD *)&mData[15].mDebugName[8] )
        goto LABEL_93;
      v24 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      *(_QWORD *)&probeTransform.v2.x = v24;
      if ( !v24 )
        return;
      mLifeTime = v22->mLifeTime;
      *((_DWORD *)v24 + 1) = 1065353216;
      *(float *)v24 = mLifeTime;
      y_low = (__m128)LODWORD(v22->mTransform.v3.y);
      if ( (float)((float)((float)((float)(v22->mTransform.v3.y * *(float *)&v12)
                                 + (float)(v22->mTransform.v3.x * *(float *)&v17))
                         + (float)(v22->mTransform.v3.z * *(float *)&v18))
                 + v19) >= 0.0 )
      {
        v27 = v8;
        v92 = v8;
        y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - view->mViewWorld.v3.y)
                                          * (float)(y_low.m128_f32[0] - view->mViewWorld.v3.y))
                                  + (float)((float)(v22->mTransform.v3.x - view->mViewWorld.v3.x)
                                          * (float)(v22->mTransform.v3.x - view->mViewWorld.v3.x)))
                          + (float)((float)(v22->mTransform.v3.z - view->mViewWorld.v3.z)
                                  * (float)(v22->mTransform.v3.z - view->mViewWorld.v3.z));
        LODWORD(v28) = _mm_sqrt_ps(y_low).m128_u32[0];
        if ( *(_DWORD *)&mData[15].mDebugName[12] )
        {
          v29 = (float *)&mData[15].mDebugName[16];
          v30 = 0i64;
          v31 = (float *)&mData[15].mDebugName[16];
          do
          {
            if ( v28 < *v31 )
              break;
            v30 = (unsigned int)(v30 + 1);
            v31 += 2;
          }
          while ( (unsigned int)v30 < 5 );
          if ( (_DWORD)v30 && (v29 = (float *)&mData[15].mDebugName[8 * (unsigned int)(v30 - 1) + 16], (_DWORD)v30 == 5) )
            v32 = (float *)mData[16].mNode.mChild + 1;
          else
            v32 = (float *)&mData[15].mDebugName[8 * v30 + 16];
          v33 = 0.0;
          v34 = *v29 - *v32;
          if ( v34 < 0.0 )
            LODWORD(v34) ^= v11;
          if ( v34 >= 0.001 )
            v33 = (float)(v28 - *v29) / (float)(*v32 - *v29);
          v92 = (float)((float)(v32[1] - v29[1]) * v33) + v29[1];
        }
        v35 = !v9 && *(float *)mData[15].mDebugName > 0.0;
        v102 = v35;
        v36 = v35 == 0;
        if ( v35 )
        {
          if ( v22->mProbeIssueCounter < 2
            || (OcclusionSystem = Render::GetOcclusionSystem(),
                mQueryID = v22->mHardwareOcclusionQuery.mQueryID,
                (_DWORD)mQueryID == -1)
            || (mUnculledQueryID = v22->mHardwareOcclusionQuery.mUnculledQueryID, (_DWORD)mUnculledQueryID == -1) )
          {
            v41 = 0.0;
          }
          else
          {
            v40 = ((double (__fastcall *)(Illusion::IOcclusion *, __int64, __int64, Illusion::Target *))OcclusionSystem->vfptr->GetPercentVisible)(
                    OcclusionSystem,
                    mQueryID,
                    mUnculledQueryID,
                    v22->mHardwareOcclusionQuery.mTarget);
            v41 = *(float *)&v40;
          }
          if ( v41 >= sFlareBias )
            v42 = v41 - sFlareBias;
          else
            v42 = 0.0;
          v43 = v22->mTransform.v0.z;
          w = v22->mTransform.v0.w;
          v45 = v8;
          v46 = v22->mTransform.v1.x;
          y = v22->mTransform.v1.y;
          v48 = v22->mTransform.v1.z;
          v49 = v22->mTransform.v1.w;
          v50 = v22->mTransform.v2.x;
          v51 = v22->mTransform.v2.y;
          v52 = v22->mTransform.v2.z;
          v53 = v22->mTransform.v2.w;
          v54 = v42 / (float)(v45 - sFlareBias);
          v55 = v22->mTransform.v3.y;
          probeTransform.v0.z = v22->mTransform.v3.x;
          v56 = v22->mTransform.v3.z;
          probeTransform.v0.w = v55;
          probeTransform.v1.x = v56;
          v57 = v92 * *(float *)mData[15].mDebugName;
          probeTransform.v0.z = v43 * v57;
          probeTransform.v0.w = w * v57;
          probeTransform.v1.x = v46 * v57;
          probeTransform.v1.y = y * v57;
          probeTransform.v1.z = v48 * v57;
          probeTransform.v1.w = v49 * v57;
          v98 = v50 * v57;
          v99 = v51 * v57;
          probeTransform.v0.x = v52 * v57;
          probeTransform.v0.y = v53 * v57;
          FX::HardwareOcclusionQuery::DrawSphere(&v22->mHardwareOcclusionQuery, view, &probeTransform);
          ++v22->mProbeIssueCounter;
          v27 = v54;
          v11 = _xmm[0];
          if ( v54 > 0.0 )
          {
            v8 = *(float *)&FLOAT_1_0;
            v20 = FLOAT_N0_5;
            goto LABEL_44;
          }
LABEL_91:
          v19 = v93;
LABEL_92:
          v21 = v94;
          v9 = v101;
          v17 = v91;
          goto LABEL_93;
        }
        v58 = *(float *)mData[15].mDebugName;
        if ( v58 >= 0.0 )
          v36 = IntersectSphereFrustum(view->mFrustumPlanes, (UFG::qVector3 *)&v22->mTransform.v3, v58) != 2;
        if ( !v36 )
          goto LABEL_92;
LABEL_44:
        v60 = (__m128)LODWORD(v22->mTransform.v3.y);
        v59 = v22->mTransform.v3.x - view->mViewWorld.v3.x;
        v60.m128_f32[0] = v60.m128_f32[0] - view->mViewWorld.v3.y;
        v61 = v22->mTransform.v3.z - view->mViewWorld.v3.z;
        v62 = v60;
        v62.m128_f32[0] = (float)((float)(v60.m128_f32[0] * v60.m128_f32[0]) + (float)(v59 * v59)) + (float)(v61 * v61);
        if ( v62.m128_f32[0] == 0.0 )
          v63 = 0.0;
        else
          v63 = v8 / _mm_sqrt_ps(v62).m128_f32[0];
        LODWORD(v64) = COERCE_UNSIGNED_INT(
                         (float)((float)((float)(v60.m128_f32[0] * v63) * v22->mTransform.v2.y)
                               + (float)((float)(v59 * v63) * v22->mTransform.v2.x))
                       + (float)((float)(v61 * v63) * v22->mTransform.v2.z)) ^ v11;
        Render::Flare::BuildFlareTransform(v22, &probeTransform, view);
        v65 = *(unsigned int *)&mData[15].mDebugName[4];
        if ( ((unsigned __int8)retaddr & 1) != 0 && (unsigned int)v65 > 1 )
          v65 = 1i64;
        if ( !(_DWORD)v65 )
          goto LABEL_91;
        mDebugName = (float *)mData[2].mDebugName;
        v97 = v65;
        while ( 2 )
        {
          v67 = mDebugName[1];
          v68 = v27;
          if ( v64 >= v67 )
          {
            if ( v64 < *mDebugName )
              v68 = (float)(v8 - (float)((float)(*mDebugName - v64) / (float)(*mDebugName - v67))) * v27;
            v69 = *(mDebugName - 3);
            if ( v28 <= v69 )
            {
              v70 = *(mDebugName - 4);
              if ( v28 > v70 )
              {
                v71 = *(mDebugName - 2);
                v68 = v68 * (float)(v8 - (float)((float)((float)(v28 - v70) / (float)(v71 - v70)) * *(mDebugName - 1)));
                if ( v28 > v71 )
                  v68 = v68 * (float)(v8 - (float)((float)(v28 - v71) / (float)(v69 - v71)));
              }
              scale = (float)(v68 * v92) * v95;
              if ( scale < 0.0 )
                scale = 0.0;
              v73 = this->mFlareMat.mData;
              v74 = *((_DWORD *)mDebugName - 7);
              if ( v73[2].mTypeUID != v74 )
              {
                UFG::qResourceHandle::Init(
                  (UFG::qResourceHandle *)&v73[2].mNode.mUID,
                  *(_DWORD *)&v73[2].mDebugName[4],
                  v74);
                mPrev = v73[1].mResourceHandles.mNode.mPrev;
                if ( mPrev )
                  mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)mPrev + (_QWORD)v73 + 120);
                LOWORD(mPrev->mPrev) |= 0x20u;
              }
              v76 = this->mFlareMat.mData;
              v77 = 543723269;
              if ( v35 )
                v77 = 1660426324;
              if ( *(_DWORD *)&v76[3].mDebugName[20] != v77 )
              {
                UFG::qResourceHandle::Init(
                  (UFG::qResourceHandle *)&v76[3].mTypeUID,
                  *(_DWORD *)&v76[3].mDebugName[28],
                  v77);
                v78 = v76[1].mResourceHandles.mNode.mPrev;
                if ( v78 )
                  v78 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v78 + (_QWORD)v76 + 120);
                LOWORD(v78->mPrev) |= 0x20u;
              }
              v79 = this->mFlareMat.mData;
              mNext = v79[2].mResourceHandles.mNode.mNext;
              if ( mNext )
              {
                mNext_high = HIDWORD(mNext[6].mNext);
                if ( (_DWORD)v5 )
                {
                  v82 = mNext_high;
                  v83 = mNext_high == 0;
                  v84 = -1551679522;
                  goto LABEL_76;
                }
                v82 = -2074035010;
                if ( mNext_high )
                {
                  v83 = mNext_high == 1775952593;
                  v84 = -630453795;
LABEL_76:
                  if ( v83 )
                    v82 = v84;
                }
                if ( LODWORD(v79[3].mNode.mChild[1]) != v82 )
                {
                  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v79[2].mDebugName[28], v79[3].mNode.mUID, v82);
                  v85 = v79[1].mResourceHandles.mNode.mPrev;
                  if ( v85 )
                    v85 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v85 + (_QWORD)v79 + 120);
                  LOWORD(v85->mPrev) |= 0x20u;
                }
              }
              v86 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x70u, 0x10u);
              *(float *)v86 = *(mDebugName - 35);
              *((float *)v86 + 1) = *(mDebugName - 34);
              *((float *)v86 + 2) = *(mDebugName - 33);
              *((float *)v86 + 3) = *(mDebugName - 32);
              *((float *)v86 + 4) = *(mDebugName - 31);
              *((float *)v86 + 5) = *(mDebugName - 30);
              *((float *)v86 + 6) = *(mDebugName - 29);
              *((float *)v86 + 7) = *(mDebugName - 28);
              *((float *)v86 + 8) = *(mDebugName - 27);
              *((float *)v86 + 9) = *(mDebugName - 26);
              *((float *)v86 + 10) = *(mDebugName - 25);
              *((float *)v86 + 11) = *(mDebugName - 24);
              *((float *)v86 + 12) = *(mDebugName - 23);
              *((float *)v86 + 13) = *(mDebugName - 22);
              *((float *)v86 + 14) = *(mDebugName - 21);
              *((float *)v86 + 15) = *(mDebugName - 20);
              *((float *)v86 + 16) = *(mDebugName - 19);
              *((float *)v86 + 17) = *(mDebugName - 18);
              *((float *)v86 + 18) = *(mDebugName - 17);
              *((float *)v86 + 19) = *(mDebugName - 16);
              *((float *)v86 + 20) = *(mDebugName - 15);
              *((float *)v86 + 21) = *(mDebugName - 14);
              *((float *)v86 + 22) = *(mDebugName - 13);
              *((float *)v86 + 23) = *(mDebugName - 12);
              *((float *)v86 + 24) = *(mDebugName - 11);
              *((float *)v86 + 25) = *(mDebugName - 10);
              *((float *)v86 + 26) = *(mDebugName - 9);
              *((float *)v86 + 27) = *(mDebugName - 8);
              mSettingsStateBlockIndex_low = SLOWORD(this->mSettingsStateBlockIndex);
              StateValues = Render::View::GetStateValues(view);
              if ( mSettingsStateBlockIndex_low >= 0x40 )
                StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mSettingsStateBlockIndex_low - 64);
              else
                StateValues->mSetValueMask.mFlags[0] |= 1i64 << mSettingsStateBlockIndex_low;
              StateValues->mParamValues[(__int16)mSettingsStateBlockIndex_low] = v86;
              mDynamicInfoStateBlockIndex_low = SLOWORD(this->mDynamicInfoStateBlockIndex);
              v90 = Render::View::GetStateValues(view);
              if ( mDynamicInfoStateBlockIndex_low >= 0x40 )
                v90->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mDynamicInfoStateBlockIndex_low - 64);
              else
                v90->mSetValueMask.mFlags[0] |= 1i64 << mDynamicInfoStateBlockIndex_low;
              v90->mParamValues[(__int16)mDynamicInfoStateBlockIndex_low] = *(void **)&probeTransform.v2.x;
              Render::FlareManager::BuildReflectionTransform(
                this,
                (UFG::qMatrix44 *)&probeTransform.v3.z,
                (Render::FlareSettings::Reflection *)(mDebugName - 35),
                &probeTransform,
                scale);
              Render::Flare::SetFXOverride(v22, view);
              Render::Poly::Poly((Render::Poly *)&probeTransform.v1.z, v20, v20, v8, v8, 0.0);
              Render::View::Draw(
                view,
                (Render::Poly *)&probeTransform.v1.z,
                (Illusion::Material *)this->mFlareMat.mData,
                (UFG::qMatrix44 *)&probeTransform.v3.z);
              v65 = v97;
              v35 = v102;
              LODWORD(v5) = vars0;
            }
          }
          mDebugName += 40;
          v97 = --v65;
          if ( !v65 )
          {
            v11 = _xmm[0];
            goto LABEL_91;
          }
          continue;
        }
      }
      v21 = v94;
      if ( !v9 )
LABEL_12:
        v22->mProbeIssueCounter = 0;
LABEL_93:
      v8 = *(float *)&FLOAT_1_0;
      v20 = FLOAT_N0_5;
      *(float *)&v12 = v98;
      *(float *)&v18 = v99;
      v10 = v96 + 1;
      v96 = v10;
    }
    while ( v10 < *(_DWORD *)((char *)&this->mFlareMat.mPrev + *(_QWORD *)&probeTransform.v2.z) );
  }
}

// File Line: 349
// RVA: 0x1D64A0
void __fastcall Render::Flare::SetFXOverride(Render::Flare *this, Render::View *view)
{
  Render::FXOverride *m_pPointer; // rdi
  char *v4; // rax
  char *v5; // rbx
  float v6; // eax
  Render::FXOverride *v7; // rcx
  unsigned int mFXOverrideStateParamIndex; // edi
  Illusion::StateValues *StateValues; // rax

  m_pPointer = this->mFXOverridePointer.m_pPointer;
  v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  v5 = v4;
  if ( m_pPointer )
  {
    *(float *)v4 = m_pPointer->stateBlock.ColorTint[0];
    *((_DWORD *)v4 + 1) = LODWORD(m_pPointer->stateBlock.ColorTint[1]);
    *((_DWORD *)v4 + 2) = LODWORD(m_pPointer->stateBlock.ColorTint[2]);
    *((_DWORD *)v4 + 3) = LODWORD(m_pPointer->stateBlock.ColorTint[3]);
    *((_DWORD *)v4 + 4) = LODWORD(m_pPointer->stateBlock.Params1[0]);
    *((_DWORD *)v4 + 5) = LODWORD(m_pPointer->stateBlock.Params1[1]);
    *((_DWORD *)v4 + 6) = LODWORD(m_pPointer->stateBlock.Params1[2]);
    v6 = m_pPointer->stateBlock.Params1[3];
  }
  else
  {
    v7 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer;
    *(float *)v4 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer->stateBlock.ColorTint[0];
    *((_DWORD *)v4 + 1) = LODWORD(v7->stateBlock.ColorTint[1]);
    *((_DWORD *)v4 + 2) = LODWORD(v7->stateBlock.ColorTint[2]);
    *((_DWORD *)v4 + 3) = LODWORD(v7->stateBlock.ColorTint[3]);
    *((_DWORD *)v4 + 4) = LODWORD(v7->stateBlock.Params1[0]);
    *((_DWORD *)v4 + 5) = LODWORD(v7->stateBlock.Params1[1]);
    *((_DWORD *)v4 + 6) = LODWORD(v7->stateBlock.Params1[2]);
    v6 = v7->stateBlock.Params1[3];
  }
  *((float *)v5 + 7) = v6;
  mFXOverrideStateParamIndex = Render::gFXManager.mFXOverrideStateParamIndex;
  StateValues = Render::View::GetStateValues(view);
  if ( mFXOverrideStateParamIndex >= 0x40 )
    StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mFXOverrideStateParamIndex - 64);
  else
    StateValues->mSetValueMask.mFlags[0] |= 1i64 << mFXOverrideStateParamIndex;
  StateValues->mParamValues[(__int16)mFXOverrideStateParamIndex] = v5;
}

// File Line: 365
// RVA: 0x1C7B60
UFG::qMatrix44 *__fastcall Render::Flare::BuildFlareTransform(
        Render::Flare *this,
        UFG::qMatrix44 *result,
        Render::View *view)
{
  float y; // xmm2_4
  float x; // xmm4_4
  float v5; // xmm3_4
  float z; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  int v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  int v13; // xmm6_4
  float v14; // xmm5_4
  int v15; // xmm0_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // eax
  float v22; // xmm1_4
  float w; // xmm2_4
  UFG::qMatrix44 *v24; // rax

  y = view->mViewWorld.v1.y;
  x = view->mViewWorld.v2.x;
  v5 = view->mViewWorld.v2.y;
  z = view->mViewWorld.v1.z;
  v7 = view->mViewWorld.v1.x;
  v8 = view->mViewWorld.v2.z;
  result->v2.w = 0.0;
  v9 = LODWORD(y) ^ _xmm[0];
  LODWORD(v10) = LODWORD(x) ^ _xmm[0];
  LODWORD(v11) = LODWORD(v5) ^ _xmm[0];
  result->v2.x = v10;
  result->v2.y = v11;
  LODWORD(v12) = LODWORD(v8) ^ _xmm[0];
  v13 = LODWORD(z) ^ _xmm[0];
  result->v2.z = v12;
  result->v0.w = 0.0;
  v14 = (float)(*(float *)&v9 * v12) - (float)(*(float *)&v13 * v11);
  v15 = LODWORD(v7) ^ _xmm[0];
  result->v0.x = v14;
  v16 = (float)(COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]) * v11) - (float)(*(float *)&v9 * v10);
  result->v0.z = v16;
  v17 = (float)(*(float *)&v13 * v10) - (float)(*(float *)&v15 * v12);
  result->v0.y = v17;
  v18 = result->v2.z;
  v19 = result->v2.y;
  v20 = result->v2.x;
  result->v1.w = 0.0;
  result->v1.x = (float)(v19 * v16) - (float)(v18 * v17);
  result->v1.y = (float)(v18 * v14) - (float)(v20 * v16);
  result->v1.z = (float)(v20 * v17) - (float)(v19 * v14);
  v21 = this->mTransform.v3.x;
  v22 = this->mTransform.v3.z;
  w = this->mTransform.v3.w;
  result->v3.y = this->mTransform.v3.y;
  result->v3.x = v21;
  v24 = result;
  result->v3.z = v22;
  result->v3.w = w;
  return v24;
}

// File Line: 378
// RVA: 0x1C7CA0
UFG::qMatrix44 *__fastcall Render::FlareManager::BuildReflectionTransform(
        Render::FlareManager *this,
        UFG::qMatrix44 *result,
        Render::FlareSettings::Reflection *reflection,
        UFG::qMatrix44 *curTransform,
        float scale)
{
  float mFlareAspect; // xmm0_4
  float mFlareScale; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float x; // eax
  float z; // xmm1_4
  float w; // xmm2_4
  UFG::qMatrix44 *v22; // rax

  mFlareAspect = reflection->mFlareAspect;
  mFlareScale = reflection->mFlareScale;
  v7 = mFlareScale * curTransform->v0.w;
  v8 = mFlareScale * curTransform->v0.y;
  v9 = (float)((float)(mFlareScale * curTransform->v0.z) * scale) * mFlareAspect;
  v10 = (float)((float)(mFlareScale * curTransform->v0.x) * scale) * mFlareAspect;
  result->v0.y = (float)(v8 * scale) * mFlareAspect;
  result->v0.z = v9;
  result->v0.x = v10;
  result->v0.w = (float)(v7 * scale) * mFlareAspect;
  v11 = reflection->mFlareScale;
  v12 = v11 * curTransform->v1.w;
  v13 = (float)(v11 * curTransform->v1.y) * scale;
  v14 = (float)(v11 * curTransform->v1.z) * scale;
  result->v1.x = (float)(v11 * curTransform->v1.x) * scale;
  result->v1.y = v13;
  result->v1.z = v14;
  result->v1.w = v12 * scale;
  v15 = reflection->mFlareScale;
  v16 = v15 * curTransform->v2.w;
  v17 = (float)(v15 * curTransform->v2.y) * scale;
  v18 = (float)(v15 * curTransform->v2.z) * scale;
  result->v2.x = (float)(v15 * curTransform->v2.x) * scale;
  result->v2.y = v17;
  result->v2.z = v18;
  result->v2.w = v16 * scale;
  x = curTransform->v3.x;
  z = curTransform->v3.z;
  w = curTransform->v3.w;
  result->v3.y = curTransform->v3.y;
  result->v3.x = x;
  v22 = result;
  result->v3.z = z;
  result->v3.w = w;
  return v22;
}

