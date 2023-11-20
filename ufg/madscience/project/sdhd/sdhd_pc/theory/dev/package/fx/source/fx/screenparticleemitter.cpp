// File Line: 27
// RVA: 0x146B870
__int64 Render::_dynamic_initializer_for__gScreenParticleEmitterManager__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&Render::gScreenParticleEmitterManager.mVertexDeclHandle.mPrev);
  Render::gScreenParticleEmitterManager.mActiveList.mNode.mPrev = &Render::gScreenParticleEmitterManager.mActiveList.mNode;
  Render::gScreenParticleEmitterManager.mActiveList.mNode.mNext = &Render::gScreenParticleEmitterManager.mActiveList.mNode;
  Render::gScreenParticleEmitterManager.mInactiveList.mNode.mPrev = &Render::gScreenParticleEmitterManager.mInactiveList.mNode;
  Render::gScreenParticleEmitterManager.mInactiveList.mNode.mNext = &Render::gScreenParticleEmitterManager.mInactiveList.mNode;
  `eh vector constructor iterator'(
    Render::gScreenParticleEmitterManager.mBuffer,
    0x58ui64,
    128,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  return atexit(Render::_dynamic_atexit_destructor_for__gScreenParticleEmitterManager__);
}

// File Line: 35
// RVA: 0x1CFBE0
void __fastcall Render::ScreenParticleEmitterManager::Init(Render::ScreenParticleEmitterManager *this)
{
  Render::ScreenParticleEmitterManager *v1; // rsi
  UFG::qList<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle,1,0> *v2; // r9
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> **v3; // rax
  signed __int64 v4; // r10
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v5; // rdx
  signed __int64 **v6; // rcx
  signed __int64 v7; // rdx
  signed __int64 *v8; // r8
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
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax

  v1 = this;
  v2 = &this->mInactiveList;
  v3 = &this->mBuffer[1].mNext;
  v4 = 32i64;
  do
  {
    v5 = v2->mNode.mPrev;
    v6 = (signed __int64 **)(v3 + 21);
    v5->mNext = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)(v3 - 12);
    *(v3 - 12) = v5;
    *(v3 - 1) = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)(v3 - 12);
    v7 = (signed __int64)(v3 - 1);
    v8 = (signed __int64 *)(v3 + 10);
    v3 += 44;
    *(v3 - 55) = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)v7;
    *(v3 - 44) = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)v8;
    *v8 = v7;
    *(v3 - 33) = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)v6;
    *v6 = v8;
    *(v3 - 22) = &v2->mNode;
    v2->mNode.mPrev = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)v6;
    --v4;
  }
  while ( v4 );
  v9 = UFG::qStringHashUpper32("ScreenParticleMaterial", 0xFFFFFFFF);
  v10 = Illusion::Factory::NewMaterial("ScreenParticleMaterial", v9, 7u, 0i64, 0i64, 0i64);
  v11 = UFG::qStringHash32("PARTICLESCREEN", 0xFFFFFFFF);
  LOWORD(v10[1].mNode.mChild[0]) = 0;
  HIDWORD(v10[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v10[1].mTypeUID = -1957338719;
  LODWORD(v10[1].mResourceHandles.mNode.mNext) = v11;
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
  LODWORD(v10[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v10[2].mNode.mUID = 0;
  v10[1].mNumParams = v14;
  LOWORD(v10[2].mTypeUID) = 0;
  HIDWORD(v10[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texDiffuseWorld", 0xFFFFFFFF);
  *((_DWORD *)&v10[2].0 + 22) = -1958479169;
  *(_DWORD *)&v10[2].mDebugName[28] = 0;
  LODWORD(v10[2].mResourceHandles.mNode.mNext) = v15;
  LOWORD(v10[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v10[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v16 = UFG::qStringHash32("texHDRBloom", 0xFFFFFFFF);
  LODWORD(v10[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v10[3].mNode.mChild[0]) = 0;
  LODWORD(v10[2].mStateBlockMask.mFlags[0]) = v16;
  LOWORD(v10[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v10[3].mNode.mUID + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v17 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v10[3].mDebugName[20] = 315097330;
  v10[3].mNode.mUID = v17;
  *(_DWORD *)&v10[3].mDebugName[12] = -1551679522;
  *((_WORD *)&v10[3].0 + 44) = 0;
  *(_DWORD *)&v10[3].mDebugName[32] = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v10[4].mNode.mParent) = 1002903008;
  LODWORD(v10[3].mMaterialUser.mOffset) = 1660426324;
  *(_DWORD *)&v10[3].mDebugName[28] = v18;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, (UFG::qResourceData *)&v10->mNode);
  v1->mMaterial = v10;
  if ( !v1->mVertexDeclHandle.mData )
  {
    v20 = UFG::qStringHash32("VertexDecl.ScreenParticle", 0xFFFFFFFF);
    v21 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
    {
      v22 = UFG::qResourceWarehouse::Instance();
      v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v21;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev, 0x3E5FDA3Eu, v20, v21);
  }
}

// File Line: 98
// RVA: 0x1C6EE0
void __fastcall Render::ScreenParticleEmitterManager::AddParticle(Render::ScreenParticleEmitterManager *this, Render::ScreenParticleEmitterSettings *settings, float simTime)
{
  Render::ScreenParticleEmitterSettings *v3; // rdi
  Render::ScreenParticleEmitterManager *v4; // rsi
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v5; // rbx
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v6; // rax
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v7; // r8
  float v8; // xmm6_4
  float v9; // xmm6_4
  float v10; // xmm6_4
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v11; // rcx

  v3 = settings;
  v4 = this;
  if ( (UFG::qList<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle,1,0> *)this->mInactiveList.mNode.mNext != &this->mInactiveList )
  {
    v5 = this->mInactiveList.mNode.mNext;
    v6 = v5->mNext;
    v7 = v5->mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    v5->mPrev = v5;
    v5->mNext = v5;
    *((float *)&v5[4].mPrev + 1) = simTime;
    *(float *)&v5[4].mNext = simTime;
    HIDWORD(v5[4].mNext) = settings->mNode.mUID;
    v8 = settings->mRegionMaxY - settings->mRegionMinY;
    *(float *)&v5[3].mNext = UFG::qRandom(settings->mRegionMaxX - settings->mRegionMinX, &UFG::qDefaultSeed)
                           + settings->mRegionMinX;
    *((float *)&v5[3].mNext + 1) = UFG::qRandom(v8, &UFG::qDefaultSeed) + v3->mRegionMinY;
    *(float *)&v5[1].mNext = UFG::qRandom(v3->mInitScaleMax - v3->mInitScaleMin, &UFG::qDefaultSeed) + v3->mInitScaleMin;
    *(float *)&v5[1].mPrev = UFG::qRandom(v3->mLifeTimeMax - v3->mLifeTimeMin, &UFG::qDefaultSeed) + v3->mLifeTimeMin;
    *((float *)&v5[1].mPrev + 1) = (float)(UFG::qRandom(v3->mGravityMax - v3->mGravityMin, &UFG::qDefaultSeed)
                                         + v3->mGravityMin)
                                 * 0.10204081;
    HIDWORD(v5[1].mNext) = v3->mScreenMotionPercentage;
    v9 = v3->mScreenMotionMaxY - v3->mScreenMotionMinY;
    *(float *)&v5[2].mPrev = UFG::qRandom(v3->mScreenMotionMaxX - v3->mScreenMotionMinX, &UFG::qDefaultSeed)
                           + v3->mScreenMotionMinX;
    *(float *)&v5[2].mPrev = UFG::qRandom(v9, &UFG::qDefaultSeed) + v3->mScreenMotionMinY;
    LODWORD(v5[2].mNext) = v3->mScreenJitterPercentage;
    v10 = v3->mScreenJitterMaxY - v3->mScreenJitterMinY;
    *((float *)&v5[2].mNext + 1) = UFG::qRandom(v3->mScreenJitterMaxX - v3->mScreenJitterMinX, &UFG::qDefaultSeed)
                                 + v3->mScreenJitterMinX;
    *(float *)&v5[3].mPrev = UFG::qRandom(v10, &UFG::qDefaultSeed) + v3->mScreenJitterMinY;
    if ( v3->mParticleSettings.AnimExtras[1] == 0.0 )
      HIDWORD(v5[3].mPrev) = LODWORD(v3->mParticleSettings.AnimExtras[2]);
    else
      *((float *)&v5[3].mPrev + 1) = (float)(signed int)((unsigned __int64)UFG::qRandom(
                                                                             (signed int)(float)(v3->mParticleSettings.AnimUVScaleOffset[1]
                                                                                               * v3->mParticleSettings.AnimUVScaleOffset[0])
                                                                           - 1,
                                                                             &UFG::qDefaultSeed)
                                                       + 1);
    LODWORD(v5[5].mPrev) = -1;
    v11 = v4->mActiveList.mNode.mNext;
    v4->mActiveList.mNode.mNext = v5;
    v5->mNext = v11;
    v5->mPrev = &v4->mActiveList.mNode;
    v11->mPrev = v5;
  }
}

// File Line: 161
// RVA: 0x1D9CF0
void __fastcall Render::ScreenParticleEmitterManager::Update(Render::ScreenParticleEmitterManager *this, float simTime)
{
  Render::ScreenParticleEmitterManager *v2; // rdi
  UFG::BaseCameraComponent *v3; // rbx
  float *v4; // rbx
  UFG::BaseCameraComponent *v5; // rcx
  UFG::Camera *v6; // rcx
  UFG::qMatrix44 *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm9_4
  float v10; // xmm3_4
  UFG::qList<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle,1,0> *v11; // rbx
  float v12; // xmm10_4
  float v13; // xmm9_4
  UFG::qList<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle,1,0> *v14; // rsi
  float v15; // xmm6_4
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v16; // rax
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v17; // rax
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  unsigned int v21; // er8
  __int64 v22; // rax
  unsigned int (*v23)[2]; // rcx

  v2 = this;
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
  v3 = UFG::Director::Get()->mCurrentCamera;
  if ( v3 )
    v4 = &v3->mCamera.mFOVOffset;
  else
    v4 = 0i64;
  v5 = UFG::Director::Get()->mCurrentCamera;
  if ( v5 )
    v6 = &v5->mCamera;
  else
    v6 = 0i64;
  v7 = UFG::Camera::GetWorldView(v6);
  v8 = v4[149];
  v9 = v4[148];
  v10 = v4[150];
  v11 = (UFG::qList<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle,1,0> *)v2->mActiveList.mNode.mNext;
  v12 = (float)((float)(v8 * v7->v1.x) + (float)(v9 * v7->v0.x)) + (float)(v10 * v7->v2.x);
  v13 = (float)((float)(v9 * v7->v0.y) + (float)(v8 * v7->v1.y)) + (float)(v10 * v7->v2.y);
  if ( v11 != &v2->mActiveList )
  {
    do
    {
      v14 = (UFG::qList<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle,1,0> *)v11->mNode.mNext;
      v15 = simTime - *((float *)&v11[4].mNode.mPrev + 1);
      if ( v15 <= *(float *)&v11[1].mNode.mPrev )
      {
        v18 = simTime - *(float *)&v11[4].mNode.mNext;
        *(float *)&v11[4].mNode.mNext = simTime;
        *((float *)&v11[3].mNode.mNext + 1) = (float)(v18 * *((float *)&v11[1].mNode.mPrev + 1))
                                            + *((float *)&v11[3].mNode.mNext + 1);
        if ( (unsigned int)UFG::qRandom(100, &UFG::qDefaultSeed) < HIDWORD(v11[1].mNode.mNext) )
        {
          v19 = (float)((float)(v13 * v18) * 0.033333335) * *(float *)&v11[2].mNode.mPrev;
          *(float *)&v11[3].mNode.mNext = *(float *)&v11[3].mNode.mNext
                                        - (float)((float)((float)(v12 * v18) * 0.033333335)
                                                * *(float *)&v11[2].mNode.mPrev);
          *((float *)&v11[3].mNode.mNext + 1) = *((float *)&v11[3].mNode.mNext + 1) - v19;
        }
        if ( (unsigned int)UFG::qRandom(100, &UFG::qDefaultSeed) < LODWORD(v11[2].mNode.mNext) )
        {
          *(float *)&v11[3].mNode.mNext = (float)((float)((float)(UFG::qRandom(0.0049999999, &UFG::qDefaultSeed)
                                                                - 0.0024999999)
                                                        * 0.5)
                                                * *((float *)&v11[2].mNode.mNext + 1))
                                        + *(float *)&v11[3].mNode.mNext;
          *((float *)&v11[3].mNode.mNext + 1) = (float)((float)((float)(UFG::qRandom(0.0049999999, &UFG::qDefaultSeed)
                                                                      - 0.0024999999)
                                                              * 0.5)
                                                      * *(float *)&v11[3].mNode.mPrev)
                                              + *((float *)&v11[3].mNode.mNext + 1);
        }
        v20 = v15 / *(float *)&v11[1].mNode.mPrev;
        v21 = HIDWORD(v11[4].mNode.mNext);
        LODWORD(v11[5].mNode.mPrev) = -1;
        v22 = 0i64;
        v23 = v2->mRenderTable;
        *(float *)&v11[4].mNode.mPrev = v20;
        while ( *(_DWORD *)v23 != v21 )
        {
          if ( !*(_DWORD *)v23 )
          {
            LODWORD(v11[5].mNode.mPrev) = v22;
            v2->mRenderTable[v22][0] = v21;
            v2->mRenderTable[v22][1] = 1;
            goto LABEL_21;
          }
          v22 = (unsigned int)(v22 + 1);
          ++v23;
          if ( (unsigned int)v22 >= 0xA )
            goto LABEL_21;
        }
        LODWORD(v11[5].mNode.mPrev) = v22;
        ++v2->mRenderTable[v22][1];
      }
      else
      {
        v16 = v11->mNode.mPrev;
        v16->mNext = &v14->mNode;
        v14->mNode.mPrev = v16;
        v11->mNode.mPrev = &v11->mNode;
        v11->mNode.mNext = &v11->mNode;
        v17 = v2->mInactiveList.mNode.mPrev;
        v17->mNext = &v11->mNode;
        v11->mNode.mPrev = v17;
        v11->mNode.mNext = &v2->mInactiveList.mNode;
        v2->mInactiveList.mNode.mPrev = &v11->mNode;
      }
LABEL_21:
      v11 = v14;
    }
    while ( v14 != &v2->mActiveList );
  }
}

// File Line: 235
// RVA: 0x1D51C0
void __fastcall Render::ScreenParticleEmitterManager::Render(Render::ScreenParticleEmitterManager *this, Render::View *view, const unsigned int compositeTextureUID, const unsigned int hdrBloomTextureUID)
{
  unsigned int v4; // er12
  Render::View *v5; // rsi
  Render::ScreenParticleEmitterManager *v6; // r13
  unsigned int v7; // er10
  unsigned int v8; // edx
  unsigned int v9; // er8
  unsigned __int16 v10; // r8
  unsigned int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebp
  unsigned int *v16; // rbx
  __int64 v17; // rdi
  unsigned int v18; // eax
  float v19; // xmm6_4
  float v20; // xmm6_4
  UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *v21; // r10
  unsigned __int16 v22; // di
  unsigned __int16 v23; // r14
  Render::ScreenParticleEmitterManager *v24; // r11
  __int64 v25; // rax
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm5_4
  int v29; // er8
  __int64 v30; // rdx
  signed __int64 v31; // rcx
  signed __int64 v32; // rcx
  float v33; // xmm4_4
  signed __int64 v34; // rcx
  signed __int64 v35; // rcx
  signed __int64 v36; // rcx
  signed __int64 v37; // rcx
  Illusion::Material **v38; // r15
  Illusion::Material *v39; // rbx
  _WORD *v40; // rax
  Illusion::Material *v41; // rbx
  _WORD *v42; // rax
  __int64 *v43; // r14
  int *v44; // r12
  signed __int64 v45; // r13
  unsigned int v46; // ebx
  UFG::qResourceInventory *v47; // rax
  UFG::qResourceWarehouse *v48; // rax
  UFG::qResourceData *v49; // rbx
  unsigned int v50; // er8
  Illusion::Material *v51; // rdi
  __int64 v52; // rax
  _WORD *v53; // rax
  unsigned int v54; // er8
  Illusion::Material *v55; // rdi
  __int64 v56; // rax
  _WORD *v57; // rax
  char *v58; // rax
  char *v59; // rdi
  unsigned int v60; // ebp
  Illusion::StateValues *v61; // rax
  char *v62; // rax
  char *v63; // rdi
  UFG::qResourceData *v64; // rdx
  char *v65; // r8
  signed __int64 v66; // rcx
  unsigned int v67; // ebp
  Illusion::StateValues *v68; // rax
  char *v69; // rax
  char *v70; // rdi
  unsigned int v71; // ebx
  Illusion::StateValues *v72; // rax
  Illusion::Primitive *v73; // rbx
  unsigned int v74; // ebx
  Illusion::StateValues *v75; // rax
  unsigned int v76; // ebx
  Illusion::StateValues *v77; // rax
  unsigned int v78; // ebx
  Illusion::StateValues *v79; // rax
  UFG::qResourceInventory *v80; // rax
  UFG::qResourceWarehouse *v81; // rax
  __int64 v82; // [rsp+40h] [rbp-138h]
  Illusion::VertexDecl **v83; // [rsp+48h] [rbp-130h]
  UFG::qResourceHandle v84; // [rsp+50h] [rbp-128h]
  __int64 v85; // [rsp+70h] [rbp-108h]
  int v86[10]; // [rsp+78h] [rbp-100h]
  int v87[12]; // [rsp+A0h] [rbp-D8h]
  __int64 v88[16]; // [rsp+D0h] [rbp-A8h]
  unsigned int name_uid; // [rsp+198h] [rbp+20h]

  name_uid = hdrBloomTextureUID;
  v85 = -2i64;
  v4 = compositeTextureUID;
  v5 = view;
  v6 = this;
  v7 = _S9_3;
  if ( !(_S9_3 & 1) )
  {
    v7 = _S9_3 | 1;
    _S9_3 |= 1u;
    zero_float16 = 0;
  }
  if ( !(v7 & 2) )
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
  if ( !(v7 & 4) )
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
  if ( !(v7 & 8) )
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
  if ( !(v7 & 0x10) )
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
  v16 = &v6->mRenderTable[0][1];
  v17 = 0i64;
  do
  {
    if ( !*(v16 - 1) )
      break;
    v86[v17] = 0;
    v18 = *v16;
    v87[v17] = 6 * *v16;
    *(_QWORD *)((char *)v16 + (char *)v88 - (char *)v6 - 11340) = UFG::qLinearAllocator::Malloc(
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
    v19 = (float)(signed int)Render::View::GetTargetHeight(v5);
    v20 = v19 / (float)(signed int)Render::View::GetTargetWidth(v5);
    v21 = v6->mActiveList.mNode.mNext;
    if ( v21 != (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)&v6->mActiveList )
    {
      v22 = zero_float16;
      v23 = one_float16;
      do
      {
        v24 = (Render::ScreenParticleEmitterManager *)v21->mNext;
        v25 = LODWORD(v21[5].mPrev);
        if ( (_DWORD)v25 != -1 )
        {
          v26 = *(float *)&v21[1].mNext * 0.1;
          v27 = *(float *)&v21[3].mNext - (float)((float)(v26 * 0.5) * v20);
          v28 = *((float *)&v21[3].mNext + 1) - (float)(v26 * 0.5);
          v29 = v86[v25];
          v30 = v88[v25];
          v31 = 32i64 * (unsigned int)v86[v25];
          *(float *)(v31 + v30) = v27;
          *(float *)(v31 + v30 + 4) = v28;
          *(_DWORD *)(v31 + v30 + 8) = 0;
          *(_WORD *)(v31 + v30 + 12) = v22;
          *(_WORD *)(v31 + v30 + 14) = v22;
          *(_DWORD *)(v31 + v30 + 16) = v21[3].mNext;
          *(_DWORD *)(v31 + v30 + 20) = HIDWORD(v21[3].mNext);
          *(_DWORD *)(v31 + v30 + 24) = v21[4].mPrev;
          *(_DWORD *)(v31 + v30 + 28) = HIDWORD(v21[3].mPrev);
          v32 = 32i64 * (unsigned int)(v29 + 1);
          v33 = (float)(v26 * v20) + v27;
          *(float *)(v32 + v30) = v33;
          *(float *)(v32 + v30 + 4) = v28;
          *(_DWORD *)(v32 + v30 + 8) = 0;
          *(_WORD *)(v32 + v30 + 12) = v23;
          *(_WORD *)(v32 + v30 + 14) = v22;
          *(_DWORD *)(v32 + v30 + 16) = v21[3].mNext;
          *(_DWORD *)(v32 + v30 + 20) = HIDWORD(v21[3].mNext);
          *(_DWORD *)(v32 + v30 + 24) = v21[4].mPrev;
          *(_DWORD *)(v32 + v30 + 28) = HIDWORD(v21[3].mPrev);
          v34 = 32i64 * (unsigned int)(v29 + 2);
          *(float *)(v34 + v30) = v27;
          *(float *)(v34 + v30 + 4) = v28 + v26;
          *(_DWORD *)(v34 + v30 + 8) = 0;
          *(_WORD *)(v34 + v30 + 12) = v22;
          *(_WORD *)(v34 + v30 + 14) = v23;
          *(_DWORD *)(v34 + v30 + 16) = v21[3].mNext;
          *(_DWORD *)(v34 + v30 + 20) = HIDWORD(v21[3].mNext);
          *(_DWORD *)(v34 + v30 + 24) = v21[4].mPrev;
          *(_DWORD *)(v34 + v30 + 28) = HIDWORD(v21[3].mPrev);
          v35 = 32i64 * (unsigned int)(v29 + 3);
          *(float *)(v35 + v30) = v33;
          *(float *)(v35 + v30 + 4) = v28 + v26;
          *(_DWORD *)(v35 + v30 + 8) = 0;
          *(_WORD *)(v35 + v30 + 12) = v23;
          *(_WORD *)(v35 + v30 + 14) = v23;
          *(_DWORD *)(v35 + v30 + 16) = v21[3].mNext;
          *(_DWORD *)(v35 + v30 + 20) = HIDWORD(v21[3].mNext);
          *(_DWORD *)(v35 + v30 + 24) = v21[4].mPrev;
          *(_DWORD *)(v35 + v30 + 28) = HIDWORD(v21[3].mPrev);
          v36 = 32i64 * (unsigned int)(v29 + 4);
          *(float *)(v36 + v30) = v27;
          *(float *)(v36 + v30 + 4) = v28 + v26;
          *(_DWORD *)(v36 + v30 + 8) = 0;
          *(_WORD *)(v36 + v30 + 12) = v22;
          *(_WORD *)(v36 + v30 + 14) = v23;
          *(_DWORD *)(v36 + v30 + 16) = v21[3].mNext;
          *(_DWORD *)(v36 + v30 + 20) = HIDWORD(v21[3].mNext);
          *(_DWORD *)(v36 + v30 + 24) = v21[4].mPrev;
          *(_DWORD *)(v36 + v30 + 28) = HIDWORD(v21[3].mPrev);
          v37 = 32i64 * (unsigned int)(v29 + 5);
          *(float *)(v37 + v30) = v33;
          *(float *)(v37 + v30 + 4) = v28;
          *(_DWORD *)(v37 + v30 + 8) = 0;
          *(_WORD *)(v37 + v30 + 12) = v23;
          *(_WORD *)(v37 + v30 + 14) = v22;
          *(_DWORD *)(v37 + v30 + 16) = v21[3].mNext;
          *(_DWORD *)(v37 + v30 + 20) = HIDWORD(v21[3].mNext);
          *(_DWORD *)(v37 + v30 + 24) = v21[4].mPrev;
          *(_DWORD *)(v37 + v30 + 28) = HIDWORD(v21[3].mPrev);
          v86[(unsigned int)v25] = v29 + 6;
        }
        v21 = (UFG::qNode<Render::ScreenParticleEmitterManager::ScreenParticle,Render::ScreenParticleEmitterManager::ScreenParticle> *)v24;
      }
      while ( v24 != (Render::ScreenParticleEmitterManager *)&v6->mActiveList );
    }
    UFG::qResourceHandle::qResourceHandle(&v84);
    v38 = &v6->mMaterial;
    v39 = v6->mMaterial;
    if ( *(_DWORD *)&v39[2].mDebugName[28] != v4 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v39[2].mDebugName[4], *((_DWORD *)&v39[2].0 + 22), v4);
      v40 = (_WORD *)v39->mMaterialUser.mOffset;
      if ( v40 )
        v40 = (_WORD *)((char *)v40 + (_QWORD)v39 + 120);
      *v40 |= 0x20u;
    }
    v41 = *v38;
    if ( LODWORD((*v38)[3].mNode.mChild[0]) != name_uid )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v41[2].mNumParams,
        (unsigned int)v41[3].mNode.mChild[1],
        name_uid);
      v42 = (_WORD *)v41->mMaterialUser.mOffset;
      if ( v42 )
        v42 = (_WORD *)((char *)v42 + (_QWORD)v41 + 120);
      *v42 |= 0x20u;
    }
    if ( v15 )
    {
      v83 = (Illusion::VertexDecl **)&v6->mVertexDeclHandle.mData;
      v43 = v88;
      v44 = v87;
      v45 = (char *)v6 - (char *)v88;
      v82 = v15;
      do
      {
        v46 = *(_DWORD *)((char *)v43 + v45 + 11336);
        v47 = `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result )
        {
          v48 = UFG::qResourceWarehouse::Instance();
          v47 = UFG::qResourceWarehouse::GetInventory(v48, 0x354C3CDCu);
          `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result = v47;
        }
        UFG::qResourceHandle::Init(&v84, 0x354C3CDCu, v46, v47);
        v49 = v84.mData;
        v50 = *(_DWORD *)&v84.mData[3].mDebugName[28];
        v51 = *v38;
        if ( LODWORD((*v38)[1].mStateBlockMask.mFlags[0]) != v50 )
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
        v54 = *(_DWORD *)&v49[3].mDebugName[32];
        v55 = *v38;
        if ( (*v38)[2].mNode.mUID != v54 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v55[2],
            (unsigned int)v55[2].mResourceHandles.mNode.mPrev,
            v54);
          v56 = v55->mMaterialUser.mOffset;
          if ( v56 )
            v57 = (_WORD *)((char *)&v55->mMaterialUser + v56);
          else
            v57 = 0i64;
          *v57 |= 0x20u;
        }
        v58 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
        v59 = v58;
        *(_DWORD *)v58 = 0;
        *((_DWORD *)v58 + 1) = v49[4].mNode.mParent;
        *((_DWORD *)v58 + 2) = 0;
        *((float *)v58 + 3) = (float)LOBYTE(v49[5].mNode.mChild[0]);
        v60 = (signed __int16)viewGenericInfoIndex;
        v61 = Render::View::GetStateValues(v5);
        if ( v60 >= 0x40 )
          v61->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v60 - 64);
        else
          v61->mSetValueMask.mFlags[0] |= 1i64 << v60;
        v61->mParamValues[(signed __int16)v60] = v59;
        v62 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
        v63 = v62;
        v64 = v49 + 1;
        v65 = v62;
        if ( ((unsigned __int8)v62 | (unsigned __int8)((_BYTE)v49 + 88)) & 0xF )
        {
          memmove(v62, v64, 0xC0ui64);
        }
        else
        {
          v66 = 1i64;
          do
          {
            *(_OWORD *)v65 = *(_OWORD *)&v64->mNode.mParent;
            *((_OWORD *)v65 + 1) = *(_OWORD *)&v64->mNode.mChild[1];
            *((_OWORD *)v65 + 2) = v64->mResourceHandles;
            *((_OWORD *)v65 + 3) = *(_OWORD *)&v64->mTypeUID;
            *((_OWORD *)v65 + 4) = *(_OWORD *)&v64->mDebugName[12];
            *((_OWORD *)v65 + 5) = *(_OWORD *)&v64->mDebugName[28];
            *((_OWORD *)v65 + 6) = *(_OWORD *)v64[1].mNode.mChild;
            v65 += 128;
            *((_OWORD *)v65 - 1) = *(_OWORD *)&v64[1].mNode.mUID;
            v64 = (UFG::qResourceData *)((char *)v64 + 128);
            --v66;
          }
          while ( v66 );
          *(_OWORD *)v65 = *(_OWORD *)&v64->mNode.mParent;
          *((_OWORD *)v65 + 1) = *(_OWORD *)&v64->mNode.mChild[1];
          *((_OWORD *)v65 + 2) = v64->mResourceHandles;
          *((_OWORD *)v65 + 3) = *(_OWORD *)&v64->mTypeUID;
        }
        v67 = (signed __int16)particleSettingsIndex;
        v68 = Render::View::GetStateValues(v5);
        if ( v67 >= 0x40 )
          v68->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v67 - 64);
        else
          v68->mSetValueMask.mFlags[0] |= 1i64 << v67;
        v68->mParamValues[(signed __int16)v67] = v63;
        v69 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
        v70 = v69;
        *(_DWORD *)v69 = v49[3].mNode.mChild[1];
        *((_DWORD *)v69 + 1) = HIDWORD(v49[3].mNode.mChild[1]);
        *((_DWORD *)v69 + 2) = v49[3].mNode.mUID;
        *((_DWORD *)v69 + 3) = *(&v49[3].mNode.mUID + 1);
        *((_DWORD *)v69 + 4) = v49[3].mResourceHandles.mNode.mPrev;
        *((_DWORD *)v69 + 5) = HIDWORD(v49[3].mResourceHandles.mNode.mPrev);
        *((_DWORD *)v69 + 6) = v49[3].mResourceHandles.mNode.mNext;
        *((_DWORD *)v69 + 7) = HIDWORD(v49[3].mResourceHandles.mNode.mNext);
        *((_DWORD *)v69 + 8) = v49[3].mTypeUID;
        *((_DWORD *)v69 + 9) = *(_DWORD *)v49[3].mDebugName;
        *((_DWORD *)v69 + 10) = *(_DWORD *)&v49[3].mDebugName[4];
        *((_DWORD *)v69 + 11) = *(_DWORD *)&v49[3].mDebugName[8];
        *((_DWORD *)v69 + 12) = *(_DWORD *)&v49[3].mDebugName[12];
        *((_DWORD *)v69 + 13) = *(_DWORD *)&v49[3].mDebugName[16];
        *((_DWORD *)v69 + 14) = *(_DWORD *)&v49[3].mDebugName[20];
        *((_DWORD *)v69 + 15) = *(_DWORD *)&v49[3].mDebugName[24];
        v71 = (signed __int16)fxSizeModuleStateIndex;
        v72 = Render::View::GetStateValues(v5);
        if ( v71 >= 0x40 )
          v72->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v71 - 64);
        else
          v72->mSetValueMask.mFlags[0] |= 1i64 << v71;
        v72->mParamValues[(signed __int16)v71] = v70;
        v73 = Illusion::Primitive::Create("ScreenParticles");
        Illusion::Primitive::SetBuffers(v73, TRIANGLELIST, (const void *)*v43, *v44, *v83, 0i64, 0, 1);
        Render::View::Draw(v5, v73, *v38, 0i64);
        v74 = (signed __int16)viewGenericInfoIndex;
        v75 = Render::View::GetStateValues(v5);
        if ( v74 >= 0x40 )
          v75->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v74 - 64);
        else
          v75->mSetValueMask.mFlags[0] |= 1i64 << v74;
        v75->mParamValues[(signed __int16)v74] = 0i64;
        v76 = (signed __int16)particleSettingsIndex;
        v77 = Render::View::GetStateValues(v5);
        if ( v76 >= 0x40 )
          v77->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v76 - 64);
        else
          v77->mSetValueMask.mFlags[0] |= 1i64 << v76;
        v77->mParamValues[(signed __int16)v76] = 0i64;
        v78 = (signed __int16)fxSizeModuleStateIndex;
        v79 = Render::View::GetStateValues(v5);
        if ( v78 >= 0x40 )
          v79->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v78 - 64);
        else
          v79->mSetValueMask.mFlags[0] |= 1i64 << v78;
        v79->mParamValues[(signed __int16)v78] = 0i64;
        ++v44;
        ++v43;
        --v82;
      }
      while ( v82 );
    }
    v80 = `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result )
    {
      v81 = UFG::qResourceWarehouse::Instance();
      v80 = UFG::qResourceWarehouse::GetInventory(v81, 0x354C3CDCu);
      `UFG::qGetResourceInventory<Render::ScreenParticleEmitterSettings>'::`2'::result = v80;
    }
    UFG::qResourceHandle::Close(&v84, v80);
    UFG::qResourceHandle::~qResourceHandle(&v84);
  }
}

