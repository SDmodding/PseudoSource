// File Line: 21
// RVA: 0x146B590
__int64 Render::_dynamic_initializer_for__gFlareManager__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&Render::gFlareManager.mFlareMat.mPrev);
  `eh vector constructor iterator'(
    Render::gFlareManager.mFlares,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  return atexit(Render::_dynamic_atexit_destructor_for__gFlareManager__);
}

// File Line: 25
// RVA: 0x1C15F0
void __fastcall Render::Flare::Flare(Render::Flare *this)
{
  Render::Flare *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4

  v1 = this;
  this->mTarget = 0i64;
  *(_QWORD *)&this->mHardwareOcclusionQuery.mQueryID = -1i64;
  this->mHardwareOcclusionQuery.mTarget = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettings.mPrev);
  v2 = UFG::qMatrix44::msIdentity.v0.y;
  v3 = UFG::qMatrix44::msIdentity.v0.z;
  v4 = UFG::qMatrix44::msIdentity.v0.w;
  v1->mTransform.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  v1->mTransform.v0.y = v2;
  v1->mTransform.v0.z = v3;
  v1->mTransform.v0.w = v4;
  v5 = UFG::qMatrix44::msIdentity.v1.y;
  v6 = UFG::qMatrix44::msIdentity.v1.z;
  v7 = UFG::qMatrix44::msIdentity.v1.w;
  v1->mTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  v1->mTransform.v1.y = v5;
  v1->mTransform.v1.z = v6;
  v1->mTransform.v1.w = v7;
  v8 = UFG::qMatrix44::msIdentity.v2.y;
  v9 = UFG::qMatrix44::msIdentity.v2.z;
  v10 = UFG::qMatrix44::msIdentity.v2.w;
  v1->mTransform.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  v1->mTransform.v2.y = v8;
  v1->mTransform.v2.z = v9;
  v1->mTransform.v2.w = v10;
  v11 = UFG::qMatrix44::msIdentity.v3.y;
  v12 = UFG::qMatrix44::msIdentity.v3.z;
  v13 = UFG::qMatrix44::msIdentity.v3.w;
  v1->mTransform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  v1->mTransform.v3.y = v11;
  v1->mTransform.v3.z = v12;
  v1->mTransform.v3.w = v13;
  *(_QWORD *)&v1->mProbeIssueCounter = 0i64;
  v1->mSplitScreenViewMask = -1;
  v1->mFXOverridePointer.m_pPointer = 0i64;
}

// File Line: 30
// RVA: 0x1C3B90
void __fastcall Render::Flare::~Flare(Render::Flare *this)
{
  Render::Flare *v1; // rbx
  Render::FXOverride *v2; // rax
  Render::FXOverride *v3; // rdi
  Render::FXOverride::PrecalculatedTriangle *v4; // rdx
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  Illusion::IOcclusion *v7; // rax
  Illusion::IOcclusion *v8; // rdi
  __int64 v9; // rdx
  __int64 v10; // rdx

  v1 = this;
  v2 = this->mFXOverridePointer.m_pPointer;
  if ( v2 )
  {
    --v2->mReferenceCount;
    v3 = this->mFXOverridePointer.m_pPointer;
    if ( v3->mReferenceCount <= 0 )
    {
      if ( v3 )
      {
        v4 = v3->mTriangleInfo;
        if ( v4 )
          UFG::qMemoryPool::Free(v3->mMemoryPool, v4);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v3);
      }
      v1->mFXOverridePointer.m_pPointer = 0i64;
    }
  }
  v5 = `UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xA6535FBB);
    `UFG::qGetResourceInventory<Render::FlareSettings>'::`2'::result = v5;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettings.mPrev, v5);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettings.mPrev);
  v7 = Render::GetOcclusionSystem();
  v8 = v7;
  v9 = v1->mHardwareOcclusionQuery.mQueryID;
  if ( (_DWORD)v9 != -1 )
  {
    v7->vfptr->ReleaseQueryHandle(v7, v9, v1->mHardwareOcclusionQuery.mTarget);
    v1->mHardwareOcclusionQuery.mQueryID = -1;
  }
  v10 = v1->mHardwareOcclusionQuery.mUnculledQueryID;
  if ( (_DWORD)v10 != -1 )
  {
    v8->vfptr->ReleaseQueryHandle(v8, v10, v1->mHardwareOcclusionQuery.mTarget);
    v1->mHardwareOcclusionQuery.mUnculledQueryID = -1;
  }
}

// File Line: 44
// RVA: 0x1CE860
void __fastcall Render::FlareManager::Init(Render::FlareManager *this)
{
  Render::FlareManager *v1; // rbp
  _WORD *v2; // rdi
  unsigned int v3; // er14
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
  __int64 v14; // rax
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  unsigned int v17; // eax
  unsigned int v18; // eax

  v1 = this;
  v2 = 0i64;
  v3 = UFG::qStringHashUpper32("FlareMat", 0xFFFFFFFF);
  v4 = Illusion::Factory::NewMaterial("FlareMat", v3, 4u, 0i64, 0i64, 0i64);
  v5 = UFG::qStringHash32("FLARE", 0xFFFFFFFF);
  LOWORD(v4[1].mNode.mChild[0]) = 0;
  v6 = v5;
  HIDWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4[1].mTypeUID = -1957338719;
  LODWORD(v4[1].mResourceHandles.mNode.mNext) = v6;
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
  LODWORD(v4[2].mResourceHandles.mNode.mPrev) = 315097330;
  v4[2].mNode.mUID = 662883558;
  v4[1].mNumParams = v11;
  LOWORD(v4[2].mTypeUID) = 0;
  HIDWORD(v4[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v4[2].0 + 22) = 1002903008;
  LODWORD(v4[2].mResourceHandles.mNode.mNext) = v12;
  *(_DWORD *)&v4[2].mDebugName[28] = 1660426324;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, (UFG::qResourceData *)&v4->mNode);
  if ( *(_DWORD *)&v4[2].mDebugName[28] != 1660426324 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[2].mDebugName[4], *((_DWORD *)&v4[2].0 + 22), 0x62F81854u);
    v14 = v4->mMaterialUser.mOffset;
    if ( v14 )
      v2 = (_WORD *)((char *)&v4->mMaterialUser + v14);
    *v2 |= 0x20u;
  }
  v15 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v15;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mFlareMat.mPrev, 0xB4C26312, v3, v15);
  v17 = UFG::qStringHash32("cbFlareSettings", 0xFFFFFFFF);
  v1->mSettingsStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                     &Illusion::gStateSystem,
                                                     v17,
                                                     "cbFlareSettings",
                                                     0);
  v18 = UFG::qStringHash32("cbDynamicFlareInfo", 0xFFFFFFFF);
  v1->mDynamicInfoStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                        &Illusion::gStateSystem,
                                                        v18,
                                                        "cbDynamicFlareInfo",
                                                        0);
}

// File Line: 75
// RVA: 0x1D26D0
void __fastcall Render::FlareManager::RemoveFlare(Render::FlareManager *this, Render::Flare *pFlare)
{
  Render::Flare *v2; // rdi
  Render::FlareManager *v3; // rsi
  UFG::qResourceData *v4; // rax
  __int64 v5; // rcx
  signed __int64 v6; // rbx
  __int64 v7; // r8
  __int64 v8; // rdi
  signed __int64 v9; // rbp
  Illusion::IOcclusion *v10; // rax
  __int64 v11; // rdx
  Illusion::IOcclusion *v12; // rsi
  __int64 v13; // rdx

  v2 = pFlare;
  v3 = this;
  Render::GetOcclusionSystem();
  v4 = v2->mSettings.mData;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = (signed __int64)v3 + 16 * (v4[15].mTypeUID + 2i64);
    if ( *(_DWORD *)v6 )
    {
      v7 = *(_QWORD *)(v6 + 8);
      while ( *(Render::Flare **)(v7 + 8 * v5) != v2 )
      {
        v5 = (unsigned int)(v5 + 1);
        if ( (unsigned int)v5 >= *(_DWORD *)v6 )
          return;
      }
      v8 = *(_QWORD *)(v7 + 8 * v5);
      v9 = 8 * v5;
      v10 = Render::GetOcclusionSystem();
      v11 = *(unsigned int *)(v8 + 8);
      v12 = v10;
      if ( (_DWORD)v11 != -1 )
      {
        v10->vfptr->ReleaseQueryHandle(v10, v11, *(Illusion::Target **)(v8 + 16));
        *(_DWORD *)(v8 + 8) = -1;
      }
      v13 = *(unsigned int *)(v8 + 12);
      if ( (_DWORD)v13 != -1 )
      {
        v12->vfptr->ReleaseQueryHandle(v12, v13, *(Illusion::Target **)(v8 + 16));
        *(_DWORD *)(v8 + 12) = -1;
      }
      if ( *(_DWORD *)v6 > 1u )
        *(_QWORD *)(*(_QWORD *)(v6 + 8) + v9) = *(_QWORD *)(*(_QWORD *)(v6 + 8)
                                                          + 8i64 * (unsigned int)(*(_DWORD *)v6 - 1));
      if ( *(_DWORD *)v6 > 1u )
        --*(_DWORD *)v6;
      else
        *(_DWORD *)v6 = 0;
    }
  }
}

// File Line: 100
// RVA: 0x1C6D20
void __fastcall Render::FlareManager::AddFlare(Render::FlareManager *this, Render::Flare *pFlare)
{
  Render::Flare *v2; // rsi
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v3; // rdi
  __int64 v4; // rbp
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **v8; // rax

  v2 = pFlare;
  if ( pFlare->mSettings.mData )
  {
    pFlare->mProbeIssueCounter = 0;
    *(_QWORD *)&pFlare->mHardwareOcclusionQuery.mQueryID = -1i64;
    pFlare->mHardwareOcclusionQuery.mTarget = 0i64;
    v3 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)(&this->mFlareMat.mPrev
                                                       + 2 * ((signed int)pFlare->mSettings.mData[15].mTypeUID + 2i64));
    v4 = v3->size;
    v5 = v3->capacity;
    v6 = v4 + 1;
    if ( (signed int)v4 + 1 > v5 )
    {
      if ( v5 )
        v7 = 2 * v5;
      else
        v7 = 1;
      for ( ; v7 < v6; v7 *= 2 )
        ;
      if ( v7 <= 2 )
        v7 = 2;
      if ( v7 - v6 > 0x10000 )
        v7 = v4 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v3, v7, "qArray.Add");
    }
    v8 = v3->p;
    v3->size = v6;
    v8[v4] = (UFG::qReflectInventoryBase *)v2;
  }
}

// File Line: 156
// RVA: 0x1D3D40
void __fastcall Render::FlareManager::Render(Render::FlareManager *this, Render::View *view, float fTime, Render::eFlareQueue queue, unsigned int flare_flags)
{
  __int64 v5; // r14
  Render::View *v6; // r12
  Render::FlareManager *v7; // r15
  float v8; // xmm8_4
  char v9; // si
  unsigned int v10; // eax
  int v11; // xmm6_4
  int v12; // xmm11_4
  float v13; // xmm9_4
  float v14; // xmm1_4
  float v15; // xmm12_4
  float v16; // xmm7_4
  int v17; // xmm9_4
  int v18; // xmm12_4
  float v19; // xmm7_4
  float v20; // xmm10_4
  signed __int64 v21; // rdx
  Render::Flare *v22; // r13
  UFG::qResourceData *v23; // rbx
  char *v24; // rax
  float v25; // ecx
  __m128 v26; // xmm3
  float v27; // xmm0_4
  float v28; // xmm9_4
  float v29; // xmm14_4
  float *v30; // rcx
  __int64 v31; // rdx
  float *v32; // rax
  float *v33; // rax
  float v34; // xmm1_4
  char v35; // si
  bool v36; // al
  Illusion::IOcclusion *v37; // rax
  __int64 v38; // rdx
  __int64 v39; // r8
  float v40; // xmm2_4
  float v41; // xmm2_4
  __int128 v42; // xmm3
  float v43; // xmm4_4
  float v44; // xmm5_4
  float v45; // xmm0_4
  float v46; // xmm6_4
  float v47; // xmm7_4
  float v48; // xmm8_4
  float v49; // xmm9_4
  float v50; // xmm10_4
  float v51; // xmm11_4
  float v52; // xmm12_4
  float v53; // xmm13_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  __int128 v57; // xmm1
  float v58; // xmm0_4
  float v59; // ST50_4
  __int128 v60; // xmm2
  float v61; // xmm2_4
  float v62; // xmm3_4
  __m128 v63; // xmm7
  float v64; // xmm4_4
  __m128 v65; // xmm2
  float v66; // xmm1_4
  float v67; // xmm7_4
  signed __int64 v68; // rax
  float *v69; // rbx
  float v70; // xmm2_4
  float v71; // xmm6_4
  float v72; // xmm2_4
  float v73; // xmm4_4
  float v74; // xmm3_4
  float scale; // xmm6_4
  UFG::qResourceData *v76; // rdi
  unsigned int v77; // er8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v78; // rax
  UFG::qResourceData *v79; // rdi
  unsigned int v80; // er8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v81; // rax
  UFG::qResourceData *v82; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v83; // rax
  unsigned int v84; // eax
  unsigned int v85; // er8
  bool v86; // zf
  signed int v87; // eax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v88; // rax
  char *v89; // rax
  char *v90; // rdi
  unsigned int v91; // er14
  Illusion::StateValues *v92; // rax
  unsigned int v93; // edi
  Illusion::StateValues *v94; // rax
  int v95; // [rsp+30h] [rbp-A8h]
  float v96; // [rsp+34h] [rbp-A4h]
  float v97; // [rsp+38h] [rbp-A0h]
  signed __int64 v98; // [rsp+40h] [rbp-98h]
  float v99; // [rsp+48h] [rbp-90h]
  unsigned int v100; // [rsp+4Ch] [rbp-8Ch]
  signed __int64 v101; // [rsp+50h] [rbp-88h]
  float v102; // [rsp+58h] [rbp-80h]
  float v103; // [rsp+5Ch] [rbp-7Ch]
  UFG::qMatrix44 probeTransform; // [rsp+60h] [rbp-78h]
  char v105; // [rsp+1B8h] [rbp+E0h]
  char v106; // [rsp+1C0h] [rbp+E8h]
  int vars0; // [rsp+1D0h] [rbp+F8h]
  void *retaddr; // [rsp+1D8h] [rbp+100h]

  v5 = queue;
  v6 = view;
  v7 = this;
  Render::GetOcclusionSystem();
  v8 = *(float *)&FLOAT_1_0;
  v9 = (unsigned __int8)retaddr & 1;
  v105 = (unsigned __int8)retaddr & 1;
  if ( (unsigned __int8)retaddr & 1 )
    v99 = FLOAT_1_2;
  else
    v99 = *(float *)&FLOAT_1_0;
  Render::View::GetStateValues(v6);
  v10 = 0;
  v11 = _xmm[0];
  v100 = 0;
  v12 = LODWORD(v6->mViewWorld.v2.y) ^ _xmm[0];
  v13 = v6->mViewWorld.v2.x;
  v14 = v6->mViewWorld.v3.x;
  v15 = v6->mViewWorld.v2.z;
  v16 = *(float *)&v12 * COERCE_FLOAT(LODWORD(v6->mViewWorld.v3.y) ^ _xmm[0]);
  *(_QWORD *)&probeTransform.v2.z = 16 * (v5 + 2);
  v17 = LODWORD(v13) ^ _xmm[0];
  v18 = LODWORD(v15) ^ _xmm[0];
  v102 = *(float *)&v12;
  v95 = v17;
  v103 = *(float *)&v18;
  v19 = (float)(v16 + (float)(*(float *)&v17 * COERCE_FLOAT(LODWORD(v14) ^ _xmm[0])))
      + (float)(*(float *)&v18 * COERCE_FLOAT(LODWORD(v6->mViewWorld.v3.z) ^ _xmm[0]));
  v97 = v19;
  if ( *(_DWORD *)((char *)&v7->mFlareMat.mPrev + *(_QWORD *)&probeTransform.v2.z) )
  {
    v20 = FLOAT_N0_5;
    v21 = 16 * v5;
    v98 = 16 * v5;
    do
    {
      v22 = (*(Render::Flare ***)((char *)&v7->mFlares[0].p + v21))[v10];
      v23 = v22->mSettings.mData;
      if ( !v23 )
        goto LABEL_96;
      if ( v9 && !*(_DWORD *)&v23[15].mDebugName[8] )
        goto LABEL_93;
      v24 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      *(_QWORD *)&probeTransform.v2.x = v24;
      if ( !v24 )
        return;
      v25 = v22->mLifeTime;
      *((_DWORD *)v24 + 1) = 1065353216;
      *(float *)v24 = v25;
      v26 = (__m128)LODWORD(v22->mTransform.v3.y);
      v27 = v22->mTransform.v3.x * *(float *)&v17;
      if ( (float)((float)((float)((float)(v22->mTransform.v3.y * *(float *)&v12) + v27)
                         + (float)(v22->mTransform.v3.z * *(float *)&v18))
                 + v19) >= 0.0 )
      {
        v28 = v8;
        v96 = v8;
        v26.m128_f32[0] = (float)((float)((float)(v26.m128_f32[0] - v6->mViewWorld.v3.y)
                                        * (float)(v26.m128_f32[0] - v6->mViewWorld.v3.y))
                                + (float)((float)(v22->mTransform.v3.x - v6->mViewWorld.v3.x)
                                        * (float)(v22->mTransform.v3.x - v6->mViewWorld.v3.x)))
                        + (float)((float)(v22->mTransform.v3.z - v6->mViewWorld.v3.z)
                                * (float)(v22->mTransform.v3.z - v6->mViewWorld.v3.z));
        LODWORD(v29) = (unsigned __int128)_mm_sqrt_ps(v26);
        if ( *(_DWORD *)&v23[15].mDebugName[12] )
        {
          v30 = (float *)&v23[15].mDebugName[16];
          v31 = 0i64;
          v32 = (float *)&v23[15].mDebugName[16];
          do
          {
            if ( v29 < *v32 )
              break;
            v31 = (unsigned int)(v31 + 1);
            v32 += 2;
          }
          while ( (unsigned int)v31 < 5 );
          if ( (_DWORD)v31 && (v30 = (float *)&v23[15].mDebugName[8 * (unsigned int)(v31 - 1) + 16], (_DWORD)v31 == 5) )
            v33 = (float *)((char *)v23[16].mNode.mChild + 4);
          else
            v33 = (float *)&v23[15].mDebugName[8 * v31 + 16];
          v34 = 0.0;
          v27 = *v30 - *v33;
          if ( v27 < 0.0 )
            LODWORD(v27) ^= v11;
          if ( v27 >= 0.001 )
            v34 = (float)(v29 - *v30) / (float)(*v33 - *v30);
          v96 = (float)((float)(v33[1] - v30[1]) * v34) + v30[1];
        }
        v35 = !v9 && *(float *)v23[15].mDebugName > 0.0;
        v106 = v35;
        v36 = v35 == 0;
        if ( v35 )
        {
          if ( v22->mProbeIssueCounter < 2
            || (v37 = Render::GetOcclusionSystem(), v38 = v22->mHardwareOcclusionQuery.mQueryID, (_DWORD)v38 == -1)
            || (v39 = v22->mHardwareOcclusionQuery.mUnculledQueryID, (_DWORD)v39 == -1) )
          {
            v40 = 0.0;
          }
          else
          {
            v37->vfptr->GetPercentVisible(v37, v38, v39, v22->mHardwareOcclusionQuery.mTarget);
            v40 = v27;
          }
          if ( v40 >= sFlareBias )
            v41 = v40 - sFlareBias;
          else
            v41 = 0.0;
          v42 = LODWORD(v22->mTransform.v0.y);
          v43 = v22->mTransform.v0.z;
          v44 = v22->mTransform.v0.w;
          v45 = v8;
          v46 = v22->mTransform.v1.x;
          v47 = v22->mTransform.v1.y;
          v48 = v22->mTransform.v1.z;
          v49 = v22->mTransform.v1.w;
          v50 = v22->mTransform.v2.x;
          v51 = v22->mTransform.v2.y;
          v52 = v22->mTransform.v2.z;
          v53 = v22->mTransform.v2.w;
          v54 = v41 / (float)(v45 - sFlareBias);
          v55 = v22->mTransform.v3.y;
          probeTransform.v0.z = v22->mTransform.v3.x;
          v56 = v22->mTransform.v3.z;
          probeTransform.v0.w = v55;
          v57 = LODWORD(v22->mTransform.v3.w);
          probeTransform.v1.x = v56;
          v58 = v96 * *(float *)v23[15].mDebugName;
          v59 = v54;
          v60 = LODWORD(v22->mTransform.v0.x);
          probeTransform.v0.z = v43 * v58;
          probeTransform.v0.w = v44 * v58;
          probeTransform.v1.x = v46 * v58;
          probeTransform.v1.y = v47 * v58;
          probeTransform.v1.z = v48 * v58;
          probeTransform.v1.w = v49 * v58;
          v102 = v50 * v58;
          v103 = v51 * v58;
          probeTransform.v0.x = v52 * v58;
          probeTransform.v0.y = v53 * v58;
          FX::HardwareOcclusionQuery::DrawSphere(&v22->mHardwareOcclusionQuery, v6, &probeTransform);
          ++v22->mProbeIssueCounter;
          v28 = v59;
          v11 = _xmm[0];
          if ( v59 > 0.0 )
          {
            v8 = *(float *)&FLOAT_1_0;
            v20 = FLOAT_N0_5;
            goto LABEL_44;
          }
LABEL_91:
          v19 = v97;
LABEL_92:
          v21 = v98;
          v9 = v105;
          v17 = v95;
          goto LABEL_93;
        }
        v61 = *(float *)v23[15].mDebugName;
        if ( v61 >= 0.0 )
          v36 = IntersectSphereFrustum(v6->mFrustumPlanes, (UFG::qVector3 *)&v22->mTransform.v3, v61) != 2;
        if ( !v36 )
          goto LABEL_92;
LABEL_44:
        v63 = (__m128)LODWORD(v22->mTransform.v3.y);
        v62 = v22->mTransform.v3.x - v6->mViewWorld.v3.x;
        v63.m128_f32[0] = v63.m128_f32[0] - v6->mViewWorld.v3.y;
        v64 = v22->mTransform.v3.z - v6->mViewWorld.v3.z;
        v65 = v63;
        v65.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v62 * v62)) + (float)(v64 * v64);
        if ( v65.m128_f32[0] == 0.0 )
          v66 = 0.0;
        else
          v66 = v8 / COERCE_FLOAT(_mm_sqrt_ps(v65));
        LODWORD(v67) = COERCE_UNSIGNED_INT(
                         (float)((float)((float)(v63.m128_f32[0] * v66) * v22->mTransform.v2.y)
                               + (float)((float)(v62 * v66) * v22->mTransform.v2.x))
                       + (float)((float)(v64 * v66) * v22->mTransform.v2.z)) ^ v11;
        Render::Flare::BuildFlareTransform(v22, &probeTransform, v6);
        v68 = *(unsigned int *)&v23[15].mDebugName[4];
        if ( (unsigned __int8)retaddr & 1 && (unsigned int)v68 > 1 )
          v68 = 1i64;
        if ( !(_DWORD)v68 )
          goto LABEL_91;
        v69 = (float *)v23[2].mDebugName;
        v101 = v68;
        while ( 2 )
        {
          v70 = v69[1];
          v71 = v28;
          if ( v67 >= v70 )
          {
            if ( v67 < *v69 )
              v71 = (float)(v8 - (float)((float)(*v69 - v67) / (float)(*v69 - v70))) * v28;
            v72 = *(v69 - 3);
            if ( v29 <= v72 )
            {
              v73 = *(v69 - 4);
              if ( v29 > v73 )
              {
                v74 = *(v69 - 2);
                v71 = v71 * (float)(v8 - (float)((float)((float)(v29 - v73) / (float)(*(v69 - 2) - v73)) * *(v69 - 1)));
                if ( v29 > v74 )
                  v71 = v71 * (float)(v8 - (float)((float)(v29 - v74) / (float)(v72 - v74)));
              }
              scale = (float)(v71 * v96) * v99;
              if ( scale < 0.0 )
                scale = 0.0;
              v76 = v7->mFlareMat.mData;
              v77 = *((_DWORD *)v69 - 7);
              if ( v76[2].mTypeUID != v77 )
              {
                UFG::qResourceHandle::Init(
                  (UFG::qResourceHandle *)&v76[2].mNode.mUID,
                  *(_DWORD *)&v76[2].mDebugName[4],
                  v77);
                v78 = v76[1].mResourceHandles.mNode.mPrev;
                if ( v78 )
                  v78 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v78 + (_QWORD)v76 + 120);
                LOWORD(v78->mPrev) |= 0x20u;
              }
              v79 = v7->mFlareMat.mData;
              v80 = 543723269;
              if ( v35 )
                v80 = 1660426324;
              if ( *(_DWORD *)&v79[3].mDebugName[20] != v80 )
              {
                UFG::qResourceHandle::Init(
                  (UFG::qResourceHandle *)&v79[3].mTypeUID,
                  *(_DWORD *)&v79[3].mDebugName[28],
                  v80);
                v81 = v79[1].mResourceHandles.mNode.mPrev;
                if ( v81 )
                  v81 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v81 + (_QWORD)v79 + 120);
                LOWORD(v81->mPrev) |= 0x20u;
              }
              v82 = v7->mFlareMat.mData;
              v83 = v82[2].mResourceHandles.mNode.mNext;
              if ( v83 )
              {
                v84 = HIDWORD(v83[6].mNext);
                if ( (_DWORD)v5 )
                {
                  v85 = v84;
                  v86 = v84 == 0;
                  v87 = -1551679522;
                  goto LABEL_76;
                }
                v85 = -2074035010;
                if ( v84 )
                {
                  v86 = v84 == 1775952593;
                  v87 = -630453795;
LABEL_76:
                  if ( v86 )
                    v85 = v87;
                }
                if ( LODWORD(v82[3].mNode.mChild[1]) != v85 )
                {
                  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v82[2].mDebugName[28], v82[3].mNode.mUID, v85);
                  v88 = v82[1].mResourceHandles.mNode.mPrev;
                  if ( v88 )
                    v88 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v88 + (_QWORD)v82 + 120);
                  LOWORD(v88->mPrev) |= 0x20u;
                }
              }
              v89 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x70u, 0x10u);
              v90 = v89;
              *(float *)v89 = *(v69 - 35);
              *((float *)v89 + 1) = *(v69 - 34);
              *((float *)v89 + 2) = *(v69 - 33);
              *((float *)v89 + 3) = *(v69 - 32);
              *((float *)v89 + 4) = *(v69 - 31);
              *((float *)v89 + 5) = *(v69 - 30);
              *((float *)v89 + 6) = *(v69 - 29);
              *((float *)v89 + 7) = *(v69 - 28);
              *((float *)v89 + 8) = *(v69 - 27);
              *((float *)v89 + 9) = *(v69 - 26);
              *((float *)v89 + 10) = *(v69 - 25);
              *((float *)v89 + 11) = *(v69 - 24);
              *((float *)v89 + 12) = *(v69 - 23);
              *((float *)v89 + 13) = *(v69 - 22);
              *((float *)v89 + 14) = *(v69 - 21);
              *((float *)v89 + 15) = *(v69 - 20);
              *((float *)v89 + 16) = *(v69 - 19);
              *((float *)v89 + 17) = *(v69 - 18);
              *((float *)v89 + 18) = *(v69 - 17);
              *((float *)v89 + 19) = *(v69 - 16);
              *((float *)v89 + 20) = *(v69 - 15);
              *((float *)v89 + 21) = *(v69 - 14);
              *((float *)v89 + 22) = *(v69 - 13);
              *((float *)v89 + 23) = *(v69 - 12);
              *((float *)v89 + 24) = *(v69 - 11);
              *((float *)v89 + 25) = *(v69 - 10);
              *((float *)v89 + 26) = *(v69 - 9);
              *((float *)v89 + 27) = *(v69 - 8);
              v91 = SLOWORD(v7->mSettingsStateBlockIndex);
              v92 = Render::View::GetStateValues(v6);
              if ( v91 >= 0x40 )
                v92->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v91 - 64);
              else
                v92->mSetValueMask.mFlags[0] |= 1i64 << v91;
              v92->mParamValues[(signed __int16)v91] = v90;
              v93 = SLOWORD(v7->mDynamicInfoStateBlockIndex);
              v94 = Render::View::GetStateValues(v6);
              if ( v93 >= 0x40 )
                v94->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v93 - 64);
              else
                v94->mSetValueMask.mFlags[0] |= 1i64 << v93;
              v94->mParamValues[(signed __int16)v93] = *(void **)&probeTransform.v2.x;
              Render::FlareManager::BuildReflectionTransform(
                v7,
                (UFG::qMatrix44 *)((char *)&probeTransform + 56),
                (Render::FlareSettings::Reflection *)(v69 - 35),
                &probeTransform,
                scale);
              Render::Flare::SetFXOverride(v22, v6);
              Render::Poly::Poly((Render::Poly *)&probeTransform.v1.z, v20, v20, v8, v8, 0.0);
              Render::View::Draw(
                v6,
                (Render::Poly *)&probeTransform.v1.z,
                (Illusion::Material *)v7->mFlareMat.mData,
                (UFG::qMatrix44 *)((char *)&probeTransform + 56));
              v68 = v101;
              v35 = v106;
              LODWORD(v5) = vars0;
            }
          }
          v69 += 40;
          v101 = --v68;
          if ( !v68 )
          {
            v11 = _xmm[0];
            goto LABEL_91;
          }
          continue;
        }
      }
      v21 = v98;
      if ( !v9 )
LABEL_96:
        v22->mProbeIssueCounter = 0;
LABEL_93:
      v8 = *(float *)&FLOAT_1_0;
      v20 = FLOAT_N0_5;
      *(float *)&v12 = v102;
      *(float *)&v18 = v103;
      v10 = v100 + 1;
      v100 = v10;
    }
    while ( v10 < *(_DWORD *)((char *)&v7->mFlareMat.mPrev + *(_QWORD *)&probeTransform.v2.z) );
  }
}

// File Line: 349
// RVA: 0x1D64A0
void __fastcall Render::Flare::SetFXOverride(Render::Flare *this, Render::View *view)
{
  Render::FXOverride *v2; // rdi
  Render::View *v3; // rsi
  char *v4; // rax
  char *v5; // rbx
  float v6; // eax
  Render::FXOverride *v7; // rcx
  unsigned int v8; // edi
  Illusion::StateValues *v9; // rax

  v2 = this->mFXOverridePointer.m_pPointer;
  v3 = view;
  v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  v5 = v4;
  if ( v2 )
  {
    *(float *)v4 = v2->stateBlock.ColorTint[0];
    *((_DWORD *)v4 + 1) = LODWORD(v2->stateBlock.ColorTint[1]);
    *((_DWORD *)v4 + 2) = LODWORD(v2->stateBlock.ColorTint[2]);
    *((_DWORD *)v4 + 3) = LODWORD(v2->stateBlock.ColorTint[3]);
    *((_DWORD *)v4 + 4) = LODWORD(v2->stateBlock.Params1[0]);
    *((_DWORD *)v4 + 5) = LODWORD(v2->stateBlock.Params1[1]);
    *((_DWORD *)v4 + 6) = LODWORD(v2->stateBlock.Params1[2]);
    v6 = v2->stateBlock.Params1[3];
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
  v8 = Render::gFXManager.mFXOverrideStateParamIndex;
  v9 = Render::View::GetStateValues(v3);
  if ( v8 >= 0x40 )
    v9->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v8 - 64);
  else
    v9->mSetValueMask.mFlags[0] |= 1i64 << v8;
  v9->mParamValues[(signed __int16)v8] = v5;
}

// File Line: 365
// RVA: 0x1C7B60
UFG::qMatrix44 *__fastcall Render::Flare::BuildFlareTransform(Render::Flare *this, UFG::qMatrix44 *result, Render::View *view)
{
  float v3; // xmm2_4
  float v4; // xmm4_4
  float v5; // xmm3_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  int v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  int v13; // xmm6_4
  int v14; // xmm7_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm4_4
  float v24; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  UFG::qMatrix44 *v27; // rax

  v3 = view->mViewWorld.v1.y;
  v4 = view->mViewWorld.v2.x;
  v5 = view->mViewWorld.v2.y;
  v6 = view->mViewWorld.v1.z;
  v7 = view->mViewWorld.v1.x;
  v8 = view->mViewWorld.v2.z;
  result->v2.w = 0.0;
  v9 = LODWORD(v3) ^ _xmm[0];
  LODWORD(v10) = LODWORD(v4) ^ _xmm[0];
  LODWORD(v11) = LODWORD(v5) ^ _xmm[0];
  result->v2.x = v10;
  result->v2.y = v11;
  LODWORD(v12) = LODWORD(v8) ^ _xmm[0];
  v13 = LODWORD(v6) ^ _xmm[0];
  v14 = LODWORD(v7) ^ _xmm[0];
  result->v2.z = v12;
  result->v0.w = 0.0;
  v15 = (float)(*(float *)&v9 * v12) - (float)(*(float *)&v13 * v11);
  v16 = *(float *)&v14;
  result->v0.x = v15;
  v17 = (float)(*(float *)&v14 * v11) - (float)(*(float *)&v9 * v10);
  result->v0.z = v17;
  v18 = (float)(*(float *)&v13 * v10) - (float)(v16 * v12);
  result->v0.y = v18;
  v19 = result->v2.y;
  v20 = result->v2.z;
  v21 = result->v2.y;
  v22 = result->v2.z * v18;
  v23 = result->v2.x;
  result->v1.w = 0.0;
  result->v1.x = (float)(v21 * v17) - v22;
  result->v1.y = (float)(v20 * v15) - (float)(v23 * v17);
  result->v1.z = (float)(v23 * v18) - (float)(v19 * v15);
  v24 = this->mTransform.v3.x;
  v25 = this->mTransform.v3.z;
  v26 = this->mTransform.v3.w;
  result->v3.y = this->mTransform.v3.y;
  result->v3.x = v24;
  v27 = result;
  result->v3.z = v25;
  result->v3.w = v26;
  return v27;
}

// File Line: 378
// RVA: 0x1C7CA0
UFG::qMatrix44 *__fastcall Render::FlareManager::BuildReflectionTransform(Render::FlareManager *this, UFG::qMatrix44 *result, Render::FlareSettings::Reflection *reflection, UFG::qMatrix44 *curTransform, float scale)
{
  float v5; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  UFG::qMatrix44 *v24; // rax

  v5 = reflection->mFlareScale;
  v6 = reflection->mFlareAspect;
  v7 = v5;
  v8 = v5 * curTransform->v0.w;
  v9 = (float)((float)(reflection->mFlareScale * curTransform->v0.z) * scale) * v6;
  v10 = (float)((float)(v7 * curTransform->v0.x) * scale) * v6;
  result->v0.y = (float)((float)(reflection->mFlareScale * curTransform->v0.y) * scale) * v6;
  result->v0.z = v9;
  result->v0.x = v10;
  result->v0.w = (float)(v8 * scale) * v6;
  v11 = reflection->mFlareScale;
  v12 = v11;
  v13 = v11 * curTransform->v1.w;
  v14 = (float)(reflection->mFlareScale * curTransform->v1.y) * scale;
  v15 = (float)(reflection->mFlareScale * curTransform->v1.z) * scale;
  result->v1.x = (float)(v12 * curTransform->v1.x) * scale;
  result->v1.y = v14;
  result->v1.z = v15;
  result->v1.w = v13 * scale;
  v16 = reflection->mFlareScale;
  v17 = v16;
  v18 = v16 * curTransform->v2.w;
  v19 = (float)(reflection->mFlareScale * curTransform->v2.y) * scale;
  v20 = (float)(reflection->mFlareScale * curTransform->v2.z) * scale;
  result->v2.x = (float)(v17 * curTransform->v2.x) * scale;
  result->v2.y = v19;
  result->v2.z = v20;
  result->v2.w = v18 * scale;
  v21 = curTransform->v3.x;
  v22 = curTransform->v3.z;
  v23 = curTransform->v3.w;
  result->v3.y = curTransform->v3.y;
  result->v3.x = v21;
  v24 = result;
  result->v3.z = v22;
  result->v3.w = v23;
  return v24;
}

