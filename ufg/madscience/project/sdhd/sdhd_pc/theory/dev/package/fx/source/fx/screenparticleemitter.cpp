// File Line: 27
// RVA: 0x146B870
__int64 Render::_dynamic_initializer_for__gScreenParticleEmitterManager__()
{
  UFG::qResourceHandle::qResourceHandle(&Render::gScreenParticleEmitterManager.mVertexDeclHandle);
  Render::gScreenParticleEmitterManager.mActiveList.mNode.mPrev = &Render::gScreenParticleEmitterManager.mActiveList.mNode;
  Render::gScreenParticleEmitterManager.mActiveList.mNode.mNext = &Render::gScreenParticleEmitterManager.mActiveList.mNode;
  Render::gScreenParticleEmitterManager.mInactiveList.mNode.mPrev = &Render::gScreenParticleEmitterManager.mInactiveList.mNode;
  Render::gScreenParticleEmitterManager.mInactiveList.mNode.mNext = &Render::gScreenParticleEmitterManager.mInactiveList.mNode;
  `eh vector constructor iterator(
    (char *)Render::gScreenParticleEmitterManager.mBuffer,
    0x58ui64,
    128,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gScreenParticleEmitterManager__);
}

// File Line: 35
// RVA: 0x1CFBE0
void __fastcall Render::ScreenParticleEmitterManager::Init(Render::ScreenParticleEmitterManager *this)
{
  UFG::qList<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle,1,0> *p_mInactiveList; // r9
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> **p_mNext; // rax
  __int64 v4; // r10
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *mPrev; // rdx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v6; // rcx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v7; // rdx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v8; // r8
  unsigned int v9; // eax
  Illusion::Material *v10; // rdi
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  UFG::qResourceWarehouse *v19; // rax
  unsigned int v20; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v22; // rax

  p_mInactiveList = &this->mInactiveList;
  p_mNext = &this->mBuffer[1].mNext;
  v4 = 32i64;
  do
  {
    mPrev = p_mInactiveList->mNode.mPrev;
    v6 = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)(p_mNext + 21);
    mPrev->mNext = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)(p_mNext - 12);
    *(p_mNext - 12) = mPrev;
    *(p_mNext - 1) = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)(p_mNext - 12);
    v7 = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)(p_mNext - 1);
    v8 = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)(p_mNext + 10);
    p_mNext += 44;
    *(p_mNext - 55) = v7;
    *(p_mNext - 44) = v8;
    v8->mPrev = v7;
    *(p_mNext - 33) = v6;
    v6->mPrev = v8;
    *(p_mNext - 22) = &p_mInactiveList->mNode;
    p_mInactiveList->mNode.mPrev = v6;
    --v4;
  }
  while ( v4 );
  v9 = UFG::qStringHashUpper32("ScreenParticleMaterial", -1);
  v10 = Illusion::Factory::NewMaterial("ScreenParticleMaterial", v9, 7u, 0i64, 0i64, 0i64);
  v11 = UFG::qStringHash32("PARTICLESCREEN", 0xFFFFFFFF);
  LOWORD(v10[1].mNode.mChild[0]) = 0;
  HIDWORD(v10[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v10[1].mTypeUID = -1957338719;
  LODWORD(v10[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v11;
  LODWORD(v10[1].mNode.mParent) = v12;
  *(_WORD *)&v10[1].mDebugName[12] = 0;
  *(_DWORD *)&v10[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v13 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v10[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v10[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v10[1].mDebugName[4] = v13;
  LOWORD(v10[1].mMaterialUser.mOffset) = 0;
  *(&v10[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("texDitherMask", 0xFFFFFFFF);
  LODWORD(v10[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v10[2].mNode.mUID = 0;
  v10[1].mNumParams = v14;
  LOWORD(v10[2].mTypeUID) = 0;
  HIDWORD(v10[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texDiffuseWorld", 0xFFFFFFFF);
  *((_DWORD *)&v10[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v10[2].mDebugName[28] = 0;
  LODWORD(v10[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v15;
  LOWORD(v10[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v10[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v16 = UFG::qStringHash32("texHDRBloom", 0xFFFFFFFF);
  LODWORD(v10[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v10[3].mNode.mChild[0]) = 0;
  LODWORD(v10[2].mStateBlockMask.mFlags[0]) = v16;
  LOWORD(v10[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v10[3].mNode.mUID + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v17 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v10[3].mDebugName[20] = 315097330;
  v10[3].mNode.mUID = v17;
  *(_DWORD *)&v10[3].mDebugName[12] = -1551679522;
  *((_WORD *)&v10[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v10[3].mDebugName[32] = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v10[4].mNode.mParent) = 1002903008;
  LODWORD(v10[3].mMaterialUser.mOffset) = 1660426324;
  *(_DWORD *)&v10[3].mDebugName[28] = v18;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, v10);
  this->mMaterial = v10;
  if ( !this->mVertexDeclHandle.mData )
  {
    v20 = UFG::qStringHash32("VertexDecl.ScreenParticle", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v22 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v22, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mVertexDeclHandle, 0x3E5FDA3Eu, v20, Inventory);
  }
}

// File Line: 98
// RVA: 0x1C6EE0
void __fastcall Render::ScreenParticleEmitterManager::AddParticle(
        Render::ScreenParticleEmitterManager *this,
        Render::ScreenParticleEmitterSettings *settings,
        float simTime)
{
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *mNext; // rbx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v6; // rax
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *mPrev; // r8
  float v8; // xmm6_4
  float v9; // xmm6_4
  float v10; // xmm6_4
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v11; // rcx

  if ( (UFG::qList<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle,1,0> *)this->mInactiveList.mNode.mNext != &this->mInactiveList )
  {
    mNext = this->mInactiveList.mNode.mNext;
    v6 = mNext->mNext;
    mPrev = mNext->mPrev;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    *((float *)&mNext[4].mPrev + 1) = simTime;
    *(float *)&mNext[4].mNext = simTime;
    HIDWORD(mNext[4].mNext) = settings->mNode.mUID;
    v8 = settings->mRegionMaxY - settings->mRegionMinY;
    *(float *)&mNext[3].mNext = UFG::qRandom(
                                  settings->mRegionMaxX - settings->mRegionMinX,
                                  (unsigned int *)&UFG::qDefaultSeed)
                              + settings->mRegionMinX;
    *((float *)&mNext[3].mNext + 1) = UFG::qRandom(v8, (unsigned int *)&UFG::qDefaultSeed) + settings->mRegionMinY;
    *(float *)&mNext[1].mNext = UFG::qRandom(
                                  settings->mInitScaleMax - settings->mInitScaleMin,
                                  (unsigned int *)&UFG::qDefaultSeed)
                              + settings->mInitScaleMin;
    *(float *)&mNext[1].mPrev = UFG::qRandom(
                                  settings->mLifeTimeMax - settings->mLifeTimeMin,
                                  (unsigned int *)&UFG::qDefaultSeed)
                              + settings->mLifeTimeMin;
    *((float *)&mNext[1].mPrev + 1) = (float)(UFG::qRandom(
                                                settings->mGravityMax - settings->mGravityMin,
                                                (unsigned int *)&UFG::qDefaultSeed)
                                            + settings->mGravityMin)
                                    * 0.10204081;
    HIDWORD(mNext[1].mNext) = settings->mScreenMotionPercentage;
    v9 = settings->mScreenMotionMaxY - settings->mScreenMotionMinY;
    *(float *)&mNext[2].mPrev = UFG::qRandom(
                                  settings->mScreenMotionMaxX - settings->mScreenMotionMinX,
                                  (unsigned int *)&UFG::qDefaultSeed)
                              + settings->mScreenMotionMinX;
    *(float *)&mNext[2].mPrev = UFG::qRandom(v9, (unsigned int *)&UFG::qDefaultSeed) + settings->mScreenMotionMinY;
    LODWORD(mNext[2].mNext) = settings->mScreenJitterPercentage;
    v10 = settings->mScreenJitterMaxY - settings->mScreenJitterMinY;
    *((float *)&mNext[2].mNext + 1) = UFG::qRandom(
                                        settings->mScreenJitterMaxX - settings->mScreenJitterMinX,
                                        (unsigned int *)&UFG::qDefaultSeed)
                                    + settings->mScreenJitterMinX;
    *(float *)&mNext[3].mPrev = UFG::qRandom(v10, (unsigned int *)&UFG::qDefaultSeed) + settings->mScreenJitterMinY;
    if ( settings->mParticleSettings.AnimExtras[1] == 0.0 )
      HIDWORD(mNext[3].mPrev) = LODWORD(settings->mParticleSettings.AnimExtras[2]);
    else
      *((float *)&mNext[3].mPrev + 1) = (float)(int)(UFG::qRandom(
                                                       (int)(float)(settings->mParticleSettings.AnimUVScaleOffset[1]
                                                                  * settings->mParticleSettings.AnimUVScaleOffset[0])
                                                     - 1,
                                                       (unsigned int *)&UFG::qDefaultSeed)
                                                   + 1);
    LODWORD(mNext[5].mPrev) = -1;
    v11 = this->mActiveList.mNode.mNext;
    this->mActiveList.mNode.mNext = mNext;
    mNext->mNext = v11;
    mNext->mPrev = &this->mActiveList.mNode;
    v11->mPrev = mNext;
  }
}

// File Line: 161
// RVA: 0x1D9CF0
void __fastcall Render::ScreenParticleEmitterManager::Update(Render::ScreenParticleEmitterManager *this, float simTime)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rbx
  float *p_mFOVOffset; // rbx
  UFG::BaseCameraComponent *v5; // rcx
  UFG::Camera *p_mCamera; // rcx
  UFG::qMatrix44 *WorldView; // rax
  float v8; // xmm2_4
  float v9; // xmm9_4
  float v10; // xmm3_4
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *mNext; // rbx
  float v12; // xmm10_4
  float v13; // xmm9_4
  Render::ScreenParticleEmitterManager *v14; // rsi
  float v15; // xmm6_4
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v17; // rax
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  unsigned int mNext_high; // r8d
  __int64 v22; // rax
  unsigned int (*mRenderTable)[2]; // rcx

  *(_QWORD *)&this->mRenderTable[0][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[1][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[2][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[3][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[4][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[5][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[6][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[7][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[8][0] = 0i64;
  *(_QWORD *)&this->mRenderTable[9][0] = 0i64;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
  else
    p_mFOVOffset = 0i64;
  v5 = UFG::Director::Get()->mCurrentCamera;
  if ( v5 )
    p_mCamera = &v5->mCamera;
  else
    p_mCamera = 0i64;
  WorldView = UFG::Camera::GetWorldView(p_mCamera);
  v8 = p_mFOVOffset[149];
  v9 = p_mFOVOffset[148];
  v10 = p_mFOVOffset[150];
  mNext = this->mActiveList.mNode.mNext;
  v12 = (float)((float)(v8 * WorldView->v1.x) + (float)(v9 * WorldView->v0.x)) + (float)(v10 * WorldView->v2.x);
  v13 = (float)((float)(v9 * WorldView->v0.y) + (float)(v8 * WorldView->v1.y)) + (float)(v10 * WorldView->v2.y);
  if ( mNext != (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)&this->mActiveList )
  {
    do
    {
      v14 = (Render::ScreenParticleEmitterManager *)mNext->mNext;
      v15 = simTime - *((float *)&mNext[4].mPrev + 1);
      if ( v15 <= *(float *)&mNext[1].mPrev )
      {
        v18 = simTime - *(float *)&mNext[4].mNext;
        *(float *)&mNext[4].mNext = simTime;
        *((float *)&mNext[3].mNext + 1) = (float)(v18 * *((float *)&mNext[1].mPrev + 1))
                                        + *((float *)&mNext[3].mNext + 1);
        if ( (unsigned int)UFG::qRandom(0x64u, (unsigned int *)&UFG::qDefaultSeed) < HIDWORD(mNext[1].mNext) )
        {
          v19 = (float)((float)(v13 * v18) * 0.033333335) * *(float *)&mNext[2].mPrev;
          *(float *)&mNext[3].mNext = *(float *)&mNext[3].mNext
                                    - (float)((float)((float)(v12 * v18) * 0.033333335) * *(float *)&mNext[2].mPrev);
          *((float *)&mNext[3].mNext + 1) = *((float *)&mNext[3].mNext + 1) - v19;
        }
        if ( (unsigned int)UFG::qRandom(0x64u, (unsigned int *)&UFG::qDefaultSeed) < LODWORD(mNext[2].mNext) )
        {
          *(float *)&mNext[3].mNext = (float)((float)((float)(UFG::qRandom(
                                                                0.0049999999,
                                                                (unsigned int *)&UFG::qDefaultSeed)
                                                            - 0.0024999999)
                                                    * 0.5)
                                            * *((float *)&mNext[2].mNext + 1))
                                    + *(float *)&mNext[3].mNext;
          *((float *)&mNext[3].mNext + 1) = (float)((float)((float)(UFG::qRandom(
                                                                      0.0049999999,
                                                                      (unsigned int *)&UFG::qDefaultSeed)
                                                                  - 0.0024999999)
                                                          * 0.5)
                                                  * *(float *)&mNext[3].mPrev)
                                          + *((float *)&mNext[3].mNext + 1);
        }
        v20 = v15 / *(float *)&mNext[1].mPrev;
        mNext_high = HIDWORD(mNext[4].mNext);
        LODWORD(mNext[5].mPrev) = -1;
        v22 = 0i64;
        mRenderTable = this->mRenderTable;
        *(float *)&mNext[4].mPrev = v20;
        while ( *(_DWORD *)mRenderTable != mNext_high )
        {
          if ( !*(_DWORD *)mRenderTable )
          {
            LODWORD(mNext[5].mPrev) = v22;
            this->mRenderTable[v22][0] = mNext_high;
            this->mRenderTable[v22][1] = 1;
            goto LABEL_21;
          }
          v22 = (unsigned int)(v22 + 1);
          ++mRenderTable;
          if ( (unsigned int)v22 >= 0xA )
            goto LABEL_21;
        }
        LODWORD(mNext[5].mPrev) = v22;
        ++this->mRenderTable[v22][1];
      }
      else
      {
        mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)mNext->mPrev;
        mPrev->mNext = &v14->mVertexDeclHandle;
        v14->mVertexDeclHandle.mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        v17 = this->mInactiveList.mNode.mPrev;
        v17->mNext = mNext;
        mNext->mPrev = v17;
        mNext->mNext = &this->mInactiveList.mNode;
        this->mInactiveList.mNode.mPrev = mNext;
      }
LABEL_21:
      mNext = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)v14;
    }
    while ( v14 != (Render::ScreenParticleEmitterManager *)&this->mActiveList );
  }
}

// File Line: 235
// RVA: 0x1D51C0
void __fastcall Render::ScreenParticleEmitterManager::Render(
        Render::ScreenParticleEmitterManager *this,
        Render::View *view,
        unsigned int compositeTextureUID,
        unsigned int hdrBloomTextureUID)
{
  unsigned int v7; // r10d
  unsigned int v8; // edx
  unsigned int v9; // r8d
  unsigned __int16 v10; // r8
  unsigned int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebp
  unsigned int *v16; // rbx
  __int64 v17; // rdi
  unsigned int v18; // eax
  float TargetHeight; // xmm6_4
  float v20; // xmm6_4
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *mNext; // r10
  unsigned __int16 v22; // di
  unsigned __int16 v23; // r14
  Render::ScreenParticleEmitterManager *v24; // r11
  __int64 mPrev_low; // rax
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm5_4
  unsigned int v29; // r8d
  __int64 v30; // rdx
  __int64 v31; // rcx
  __int64 v32; // rcx
  float v33; // xmm4_4
  __int64 v34; // rcx
  __int64 v35; // rcx
  __int64 v36; // rcx
  __int64 v37; // rcx
  Illusion::Material **p_mMaterial; // r15
  Illusion::Material *mMaterial; // rbx
  _WORD *mOffset; // rax
  Illusion::Material *v41; // rbx
  _WORD *v42; // rax
  __int64 *v43; // r14
  int *v44; // r12
  signed __int64 v45; // r13
  unsigned int v46; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v48; // rax
  UFG::qResourceData *mData; // rbx
  unsigned int v50; // r8d
  Illusion::Material *v51; // rdi
  __int64 v52; // rax
  _WORD *v53; // rax
  unsigned int v54; // r8d
  Illusion::Material *v55; // rdi
  __int64 v56; // rax
  _WORD *v57; // rax
  char *v58; // rdi
  unsigned int v59; // ebp
  Illusion::StateValues *StateValues; // rax
  char *v61; // rax
  char *v62; // rdi
  UFG::qResourceData *v63; // rdx
  char *v64; // r8
  __int64 v65; // rcx
  unsigned int v66; // ebp
  Illusion::StateValues *v67; // rax
  char *v68; // rdi
  unsigned int v69; // ebx
  Illusion::StateValues *v70; // rax
  Illusion::Primitive *v71; // rbx
  unsigned int v72; // ebx
  Illusion::StateValues *v73; // rax
  unsigned int v74; // ebx
  Illusion::StateValues *v75; // rax
  unsigned int v76; // ebx
  Illusion::StateValues *v77; // rax
  UFG::qResourceInventory *v78; // rax
  UFG::qResourceWarehouse *v79; // rax
  __int64 v80; // [rsp+40h] [rbp-138h]
  UFG::qResourceData **p_mData; // [rsp+48h] [rbp-130h]
  UFG::qResourceHandle v82; // [rsp+50h] [rbp-128h] BYREF
  __int64 v83; // [rsp+70h] [rbp-108h]
  int v84[10]; // [rsp+78h] [rbp-100h]
  int v85[12]; // [rsp+A0h] [rbp-D8h] BYREF
  __int64 v86[16]; // [rsp+D0h] [rbp-A8h] BYREF

  v83 = -2i64;
  v7 = _S9_3;
  if ( (_S9_3 & 1) == 0 )
  {
    v7 = _S9_3 | 1;
    _S9_3 |= 1u;
    zero_float16 = 0;
  }
  if ( (v7 & 2) == 0 )
  {
    v7 |= 2u;
    _S9_3 = v7;
    v8 = (unsigned int)FLOAT_1_0 & 0x7FFFFFFF;
    v9 = ((unsigned int)FLOAT_1_0 >> 16) & 0x8000;
    if ( ((unsigned int)FLOAT_1_0 & 0x7FFFFFFF) <= 0x47FFEFFF )
    {
      if ( v8 >= 0x38800000 )
        v11 = v8 - 939524096;
      else
        v11 = ((unsigned int)FLOAT_1_0 & 0x7FFFFF | 0x800000) >> (113 - (v8 >> 23));
      v10 = ((((v11 >> 13) & 1) + v11 + 4095) >> 13) | v9;
    }
    else
    {
      v10 = v9 | 0x7FFF;
    }
    one_float16 = v10;
  }
  if ( (v7 & 4) == 0 )
  {
    _S9_3 = v7 | 4;
    v12 = UFG::qStringHash32("cbViewGenericInfo", 0xFFFFFFFF);
    viewGenericInfoIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                               &Illusion::gStateSystem,
                                               v12,
                                               "cbViewGenericInfo",
                                               0);
    v7 = _S9_3;
  }
  if ( (v7 & 8) == 0 )
  {
    _S9_3 = v7 | 8;
    v13 = UFG::qStringHash32("cbParticleSettings", 0xFFFFFFFF);
    particleSettingsIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                &Illusion::gStateSystem,
                                                v13,
                                                "cbParticleSettings",
                                                0);
    v7 = _S9_3;
  }
  if ( (v7 & 0x10) == 0 )
  {
    _S9_3 = v7 | 0x10;
    v14 = UFG::qStringHash32("cbFXSizeModule", 0xFFFFFFFF);
    fxSizeModuleStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                 &Illusion::gStateSystem,
                                                 v14,
                                                 "cbFXSizeModule",
                                                 0);
  }
  v15 = 0;
  v16 = &this->mRenderTable[0][1];
  v17 = 0i64;
  do
  {
    if ( !*(v16 - 1) )
      break;
    v84[v17] = 0;
    v18 = *v16;
    v85[v17] = 6 * *v16;
    *(_QWORD *)((char *)v16 + (char *)v86 - (char *)this - 11340) = UFG::qLinearAllocator::Malloc(
                                                                      Illusion::gEngine.FrameMemory,
                                                                      192 * v18,
                                                                      0x10u);
    ++v15;
    ++v17;
    v16 += 2;
  }
  while ( v15 < 0xA );
  if ( v15 )
  {
    TargetHeight = (float)(int)Render::View::GetTargetHeight(view);
    v20 = TargetHeight / (float)(int)Render::View::GetTargetWidth(view);
    mNext = this->mActiveList.mNode.mNext;
    if ( mNext != (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)&this->mActiveList )
    {
      v22 = zero_float16;
      v23 = one_float16;
      do
      {
        v24 = (Render::ScreenParticleEmitterManager *)mNext->mNext;
        mPrev_low = LODWORD(mNext[5].mPrev);
        if ( (_DWORD)mPrev_low != -1 )
        {
          v26 = *(float *)&mNext[1].mNext * 0.1;
          v27 = *(float *)&mNext[3].mNext - (float)((float)(v26 * 0.5) * v20);
          v28 = *((float *)&mNext[3].mNext + 1) - (float)(v26 * 0.5);
          v29 = v84[mPrev_low];
          v30 = v86[mPrev_low];
          v31 = 32i64 * v29;
          *(float *)(v31 + v30) = v27;
          *(float *)(v31 + v30 + 4) = v28;
          *(_DWORD *)(v31 + v30 + 8) = 0;
          *(_WORD *)(v31 + v30 + 12) = v22;
          *(_WORD *)(v31 + v30 + 14) = v22;
          *(_DWORD *)(v31 + v30 + 16) = mNext[3].mNext;
          *(_DWORD *)(v31 + v30 + 20) = HIDWORD(mNext[3].mNext);
          *(_DWORD *)(v31 + v30 + 24) = mNext[4].mPrev;
          *(_DWORD *)(v31 + v30 + 28) = HIDWORD(mNext[3].mPrev);
          v32 = 32i64 * (v29 + 1);
          v33 = (float)(v26 * v20) + v27;
          *(float *)(v32 + v30) = v33;
          *(float *)(v32 + v30 + 4) = v28;
          *(_DWORD *)(v32 + v30 + 8) = 0;
          *(_WORD *)(v32 + v30 + 12) = v23;
          *(_WORD *)(v32 + v30 + 14) = v22;
          *(_DWORD *)(v32 + v30 + 16) = mNext[3].mNext;
          *(_DWORD *)(v32 + v30 + 20) = HIDWORD(mNext[3].mNext);
          *(_DWORD *)(v32 + v30 + 24) = mNext[4].mPrev;
          *(_DWORD *)(v32 + v30 + 28) = HIDWORD(mNext[3].mPrev);
          v34 = 32i64 * (v29 + 2);
          *(float *)(v34 + v30) = v27;
          *(float *)(v34 + v30 + 4) = v28 + v26;
          *(_DWORD *)(v34 + v30 + 8) = 0;
          *(_WORD *)(v34 + v30 + 12) = v22;
          *(_WORD *)(v34 + v30 + 14) = v23;
          *(_DWORD *)(v34 + v30 + 16) = mNext[3].mNext;
          *(_DWORD *)(v34 + v30 + 20) = HIDWORD(mNext[3].mNext);
          *(_DWORD *)(v34 + v30 + 24) = mNext[4].mPrev;
          *(_DWORD *)(v34 + v30 + 28) = HIDWORD(mNext[3].mPrev);
          v35 = 32i64 * (v29 + 3);
          *(float *)(v35 + v30) = v33;
          *(float *)(v35 + v30 + 4) = v28 + v26;
          *(_DWORD *)(v35 + v30 + 8) = 0;
          *(_WORD *)(v35 + v30 + 12) = v23;
          *(_WORD *)(v35 + v30 + 14) = v23;
          *(_DWORD *)(v35 + v30 + 16) = mNext[3].mNext;
          *(_DWORD *)(v35 + v30 + 20) = HIDWORD(mNext[3].mNext);
          *(_DWORD *)(v35 + v30 + 24) = mNext[4].mPrev;
          *(_DWORD *)(v35 + v30 + 28) = HIDWORD(mNext[3].mPrev);
          v36 = 32i64 * (v29 + 4);
          *(float *)(v36 + v30) = v27;
          *(float *)(v36 + v30 + 4) = v28 + v26;
          *(_DWORD *)(v36 + v30 + 8) = 0;
          *(_WORD *)(v36 + v30 + 12) = v22;
          *(_WORD *)(v36 + v30 + 14) = v23;
          *(_DWORD *)(v36 + v30 + 16) = mNext[3].mNext;
          *(_DWORD *)(v36 + v30 + 20) = HIDWORD(mNext[3].mNext);
          *(_DWORD *)(v36 + v30 + 24) = mNext[4].mPrev;
          *(_DWORD *)(v36 + v30 + 28) = HIDWORD(mNext[3].mPrev);
          v37 = 32i64 * (v29 + 5);
          *(float *)(v37 + v30) = v33;
          *(float *)(v37 + v30 + 4) = v28;
          *(_DWORD *)(v37 + v30 + 8) = 0;
          *(_WORD *)(v37 + v30 + 12) = v23;
          *(_WORD *)(v37 + v30 + 14) = v22;
          *(_DWORD *)(v37 + v30 + 16) = mNext[3].mNext;
          *(_DWORD *)(v37 + v30 + 20) = HIDWORD(mNext[3].mNext);
          *(_DWORD *)(v37 + v30 + 24) = mNext[4].mPrev;
          *(_DWORD *)(v37 + v30 + 28) = HIDWORD(mNext[3].mPrev);
          v84[(unsigned int)mPrev_low] = v29 + 6;
        }
        mNext = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)v24;
      }
      while ( v24 != (Render::ScreenParticleEmitterManager *)&this->mActiveList );
    }
    UFG::qResourceHandle::qResourceHandle(&v82);
    p_mMaterial = &this->mMaterial;
    mMaterial = this->mMaterial;
    if ( *(_DWORD *)&mMaterial[2].mDebugName[28] != compositeTextureUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mMaterial[2].mDebugName[4],
        *((_DWORD *)&mMaterial[2].UFG::qResourceData + 22),
        compositeTextureUID);
      mOffset = (_WORD *)mMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        mOffset = (_WORD *)((char *)mOffset + (_QWORD)mMaterial + 120);
      *mOffset |= 0x20u;
    }
    v41 = *p_mMaterial;
    if ( LODWORD((*p_mMaterial)[3].mNode.mChild[0]) != hdrBloomTextureUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v41[2].mNumParams,
        (unsigned int)v41[3].mNode.mChild[1],
        hdrBloomTextureUID);
      v42 = (_WORD *)v41->mMaterialUser.mOffset;
      if ( v42 )
        v42 = (_WORD *)((char *)v42 + (_QWORD)v41 + 120);
      *v42 |= 0x20u;
    }
    p_mData = &this->mVertexDeclHandle.mData;
    v43 = v86;
    v44 = v85;
    v45 = (char *)this - (char *)v86;
    v80 = v15;
    do
    {
      v46 = *(_DWORD *)((char *)v43 + v45 + 11336);
      Inventory = `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result )
      {
        v48 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v48, 0x354C3CDCu);
        `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&v82, 0x354C3CDCu, v46, Inventory);
      mData = v82.mData;
      v50 = *(_DWORD *)&v82.mData[3].mDebugName[28];
      v51 = *p_mMaterial;
      if ( LODWORD((*p_mMaterial)[1].mStateBlockMask.mFlags[0]) != v50 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v51[1].mDebugName[20],
          v51[1].mStateBlockMask.mFlags[1],
          v50);
        v52 = v51->mMaterialUser.mOffset;
        if ( v52 )
          v53 = (_WORD *)((char *)&v51->mMaterialUser + v52);
        else
          v53 = 0i64;
        *v53 |= 0x20u;
      }
      v54 = *(_DWORD *)&mData[3].mDebugName[32];
      v55 = *p_mMaterial;
      if ( (*p_mMaterial)[2].mNode.mUID != v54 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v55[2],
          (unsigned int)v55[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
          v54);
        v56 = v55->mMaterialUser.mOffset;
        if ( v56 )
          v57 = (_WORD *)((char *)&v55->mMaterialUser + v56);
        else
          v57 = 0i64;
        *v57 |= 0x20u;
      }
      v58 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
      *(_DWORD *)v58 = 0;
      *((_DWORD *)v58 + 1) = mData[4].mNode.mParent;
      *((_DWORD *)v58 + 2) = 0;
      *((float *)v58 + 3) = (float)LOBYTE(mData[5].mNode.mChild[0]);
      v59 = (__int16)viewGenericInfoIndex;
      StateValues = Render::View::GetStateValues(view);
      if ( v59 >= 0x40 )
        StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v59 - 64);
      else
        StateValues->mSetValueMask.mFlags[0] |= 1i64 << v59;
      StateValues->mParamValues[(__int16)v59] = v58;
      v61 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
      v62 = v61;
      v63 = mData + 1;
      v64 = v61;
      if ( (((unsigned __int8)v61 | (unsigned __int8)((_BYTE)mData + 88)) & 0xF) != 0 )
      {
        memmove(v61, v63, 0xC0ui64);
      }
      else
      {
        v65 = 1i64;
        do
        {
          *(_OWORD *)v64 = *(_OWORD *)&v63->mNode.mParent;
          *((_OWORD *)v64 + 1) = *(_OWORD *)&v63->mNode.mChild[1];
          *((_OWORD *)v64 + 2) = v63->mResourceHandles;
          *((_OWORD *)v64 + 3) = *(_OWORD *)&v63->mTypeUID;
          *((_OWORD *)v64 + 4) = *(_OWORD *)&v63->mDebugName[12];
          *((_OWORD *)v64 + 5) = *(_OWORD *)&v63->mDebugName[28];
          *((_OWORD *)v64 + 6) = *(_OWORD *)v63[1].mNode.mChild;
          v64 += 128;
          *((_OWORD *)v64 - 1) = *(_OWORD *)&v63[1].mNode.mUID;
          v63 = (UFG::qResourceData *)((char *)v63 + 128);
          --v65;
        }
        while ( v65 );
        *(_OWORD *)v64 = *(_OWORD *)&v63->mNode.mParent;
        *((_OWORD *)v64 + 1) = *(_OWORD *)&v63->mNode.mChild[1];
        *((_OWORD *)v64 + 2) = v63->mResourceHandles;
        *((_OWORD *)v64 + 3) = *(_OWORD *)&v63->mTypeUID;
      }
      v66 = (__int16)particleSettingsIndex;
      v67 = Render::View::GetStateValues(view);
      if ( v66 >= 0x40 )
        v67->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v66 - 64);
      else
        v67->mSetValueMask.mFlags[0] |= 1i64 << v66;
      v67->mParamValues[(__int16)v66] = v62;
      v68 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
      *(_DWORD *)v68 = mData[3].mNode.mChild[1];
      *((_DWORD *)v68 + 1) = HIDWORD(mData[3].mNode.mChild[1]);
      *((_DWORD *)v68 + 2) = mData[3].mNode.mUID;
      *((_DWORD *)v68 + 3) = *(&mData[3].mNode.mUID + 1);
      *((_DWORD *)v68 + 4) = mData[3].mResourceHandles.mNode.mPrev;
      *((_DWORD *)v68 + 5) = HIDWORD(mData[3].mResourceHandles.mNode.mPrev);
      *((_DWORD *)v68 + 6) = mData[3].mResourceHandles.mNode.mNext;
      *((_DWORD *)v68 + 7) = HIDWORD(mData[3].mResourceHandles.mNode.mNext);
      *((_DWORD *)v68 + 8) = mData[3].mTypeUID;
      *((_DWORD *)v68 + 9) = *(_DWORD *)mData[3].mDebugName;
      *((_DWORD *)v68 + 10) = *(_DWORD *)&mData[3].mDebugName[4];
      *((_DWORD *)v68 + 11) = *(_DWORD *)&mData[3].mDebugName[8];
      *((_DWORD *)v68 + 12) = *(_DWORD *)&mData[3].mDebugName[12];
      *((_DWORD *)v68 + 13) = *(_DWORD *)&mData[3].mDebugName[16];
      *((_DWORD *)v68 + 14) = *(_DWORD *)&mData[3].mDebugName[20];
      *((_DWORD *)v68 + 15) = *(_DWORD *)&mData[3].mDebugName[24];
      v69 = (__int16)fxSizeModuleStateIndex;
      v70 = Render::View::GetStateValues(view);
      if ( v69 >= 0x40 )
        v70->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v69 - 64);
      else
        v70->mSetValueMask.mFlags[0] |= 1i64 << v69;
      v70->mParamValues[(__int16)v69] = v68;
      v71 = Illusion::Primitive::Create("ScreenParticles");
      Illusion::Primitive::SetBuffers(
        v71,
        TRIANGLELIST,
        (const void *)*v43,
        *v44,
        (Illusion::VertexDecl *)*p_mData,
        0i64,
        0,
        1);
      Render::View::Draw(view, v71, *p_mMaterial, 0i64);
      v72 = (__int16)viewGenericInfoIndex;
      v73 = Render::View::GetStateValues(view);
      if ( v72 >= 0x40 )
        v73->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v72 - 64);
      else
        v73->mSetValueMask.mFlags[0] |= 1i64 << v72;
      v73->mParamValues[(__int16)v72] = 0i64;
      v74 = (__int16)particleSettingsIndex;
      v75 = Render::View::GetStateValues(view);
      if ( v74 >= 0x40 )
        v75->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v74 - 64);
      else
        v75->mSetValueMask.mFlags[0] |= 1i64 << v74;
      v75->mParamValues[(__int16)v74] = 0i64;
      v76 = (__int16)fxSizeModuleStateIndex;
      v77 = Render::View::GetStateValues(view);
      if ( v76 >= 0x40 )
        v77->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v76 - 64);
      else
        v77->mSetValueMask.mFlags[0] |= 1i64 << v76;
      v77->mParamValues[(__int16)v76] = 0i64;
      ++v44;
      ++v43;
      --v80;
    }
    while ( v80 );
    v78 = `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result )
    {
      v79 = UFG::qResourceWarehouse::Instance();
      v78 = UFG::qResourceWarehouse::GetInventory(v79, 0x354C3CDCu);
      `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>::`2::result = v78;
    }
    UFG::qResourceHandle::Close(&v82, v78);
    UFG::qResourceHandle::~qResourceHandle(&v82);
  }
}

