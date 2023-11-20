// File Line: 53
// RVA: 0x146B730
__int64 Render::_dynamic_initializer_for__gLightningManager__()
{
  Render::LightningManager::LightningManager(&Render::gLightningManager);
  return atexit(Render::_dynamic_atexit_destructor_for__gLightningManager__);
}

// File Line: 93
// RVA: 0x1CBEE0
Illusion::Buffer *__fastcall Render::LightningManager::FrameMallocBuffer(Render::LightningManager *this, Illusion::Buffer::BufferType bufferType)
{
  char v2; // r14
  unsigned int v3; // ebx
  unsigned int v4; // edi
  char *v5; // rsi
  Illusion::Buffer *result; // rax
  unsigned int v7; // edx

  v2 = bufferType;
  if ( bufferType == 1 )
  {
    v3 = 2;
    v4 = 28000;
  }
  else
  {
    v3 = 32;
    v4 = 10000;
  }
  v5 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameWriteMemory, v3 * v4, 0x10u);
  if ( !v5 )
    return 0i64;
  if ( _S5_5 & 1 )
  {
    v7 = lightningBufferUID;
  }
  else
  {
    _S5_5 |= 1u;
    v7 = UFG::qStringHashUpper32("Electricity Buffer", 0xFFFFFFFF);
    lightningBufferUID = v7;
  }
  result = Illusion::Factory::NewBuffer(
             "ParticleBuffer.AttributeBuffer",
             v7,
             0,
             0i64,
             "ParticleBuffer::AttributeBuffer",
             Illusion::gEngine.FrameMemory,
             0i64);
  if ( !result )
    return 0i64;
  result->mData.mOffset = v5 - (char *)&result->mData;
  result->mDataByteSize = v3 * v4;
  result->mBufferType = v2;
  result->mElementByteSize = v3;
  result->mNumElements = v4;
  result->mFlags |= 4u;
  return result;
}

// File Line: 122
// RVA: 0x1C1900
void __fastcall Render::LightningManager::LightningManager(Render::LightningManager *this)
{
  Render::LightningManager *v1; // rsi
  UFG::qArray<LightningJoint *,0> *v2; // rbx
  signed __int64 v3; // rdi
  UFG::qList<Render::ElectrifiedObject,Render::ElectrifiedObject,1,0> *v4; // [rsp+68h] [rbp+10h]

  v1 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mLightningMat.mPrev);
  v2 = v1->mLMJoints;
  v3 = 4i64;
  `eh vector constructor iterator'(
    v1->mLMJoints,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  v4 = &v1->mElectrifiedObjects;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v1->mMaterialTable = 0i64;
  v1->mNumQuads = 0;
  v1->mTask = 0i64;
  v1->mCurrentBuffer = 0;
  v1->mTaskOutputParam = 0i64;
  v1->mDebugDrawsEnabled = 0;
  v1->mNumBolts = 0;
  v1->mBoltArray = 0i64;
  do
  {
    *(_QWORD *)&v2->size = 0i64;
    v2->p = 0i64;
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 135
// RVA: 0x1C41D0
void __fastcall Render::LightningManager::~LightningManager(Render::LightningManager *this)
{
  Render::LightningManager *v1; // rdi
  UFG::qList<Render::ElectrifiedObject,Render::ElectrifiedObject,1,0> *v2; // rbx
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v3; // rcx
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v4; // rax
  UFG::qResourceHandle *v5; // rdi
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax

  v1 = this;
  v2 = &this->mElectrifiedObjects;
  UFG::qList<Render::ElectrifiedObject,Render::ElectrifiedObject,1,0>::DeleteNodes(&this->mElectrifiedObjects);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  `eh vector destructor iterator'(
    v1->mLMJoints,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
  v5 = (UFG::qResourceHandle *)&v1->mLightningMat.mPrev;
  v6 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Close(v5, v6);
  UFG::qResourceHandle::~qResourceHandle(v5);
}

// File Line: 140
// RVA: 0x1CEC30
void __fastcall Render::LightningManager::Init(Render::LightningManager *this, UFG::qMemoryPool *memoryPool)
{
  Render::LightningManager *v2; // r14
  hkResourceHandle *v3; // rax
  unsigned int v4; // er15
  Illusion::Material *v5; // rdi
  int v6; // ebx
  int v7; // ebx
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceData *v11; // rbx
  unsigned int v12; // er8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v13; // rax
  _WORD *v14; // rax
  int v15; // edx
  unsigned int v16; // eax
  UFG::qResourceData *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  void **v19; // rdi
  signed __int64 v20; // r15
  unsigned int v21; // er12
  __int64 v22; // r13
  unsigned int v23; // esi
  unsigned int v24; // ebx
  unsigned int v25; // ebx
  unsigned __int64 v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // r15
  unsigned int i; // er9
  signed __int64 v30; // rbx
  LightningJoint ***v31; // r12
  signed __int64 v32; // rbp
  unsigned int v33; // eax
  __int64 v34; // rdi
  Render::Bolt *v35; // rax
  UFG::qHalfVector3 *v36; // rbx
  UFG::qString v37; // [rsp+38h] [rbp-70h]
  UFG::allocator::free_link *numSubdivisions; // [rsp+B8h] [rbp+10h]
  signed __int64 v39; // [rsp+C0h] [rbp+18h]

  v2 = this;
  this->mMemoryPool = memoryPool;
  if ( !memoryPool )
    memoryPool = UFG::gMainMemoryPool;
  this->mMemoryPool = memoryPool;
  v3 = (hkResourceHandle *)UFG::qSpuManager::Instance();
  v2->mSPUElf = (UFG::qSpuElf *)TargetVisibleInAIDataCondition::CreateClone(v3);
  v2->mNumQuads = 0;
  v2->mTaskInputParam = (Render::LightningTaskParam *)UFG::qMemoryPool::Allocate(
                                                        v2->mMemoryPool,
                                                        0x228ui64,
                                                        "Render::LightningTaskParam",
                                                        0x1000ui64,
                                                        1u);
  v2->mTaskOutputParam = (Render::LightningTaskOutputParam *)UFG::qMemoryPool::Allocate(
                                                               v2->mMemoryPool,
                                                               0x18ui64,
                                                               "Render::LightningTaskOutputParam",
                                                               0x1000ui64,
                                                               1u);
  v4 = UFG::qStringHashUpper32("LightningMat", 0xFFFFFFFF);
  v5 = Illusion::Factory::NewMaterial("LightningMat", v4, 4u, 0i64, 0i64, 0i64);
  v6 = UFG::qStringHash32("LIGHTNING", 0xFFFFFFFF);
  LOWORD(v5[1].mNode.mChild[0]) = 0;
  HIDWORD(v5[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v5[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v5[1].mTypeUID = -1957338719;
  LODWORD(v5[1].mResourceHandles.mNode.mNext) = v6;
  v7 = UFG::qStringHashUpper32("FX_Lightning001", 0xFFFFFFFF);
  *(_WORD *)&v5[1].mDebugName[12] = 0;
  *(_DWORD *)&v5[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v5[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v5[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v5[1].mStateBlockMask.mFlags[0]) = v7;
  LOWORD(v5[1].mMaterialUser.mOffset) = 0;
  *(&v5[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v5[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v5[2].mResourceHandles.mNode.mPrev) = 315097330;
  v5[2].mNode.mUID = 1775952593;
  LOWORD(v5[2].mTypeUID) = 0;
  HIDWORD(v5[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v5[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v5[2].0 + 22) = 1002903008;
  *(_DWORD *)&v5[2].mDebugName[28] = 1099738947;
  v8 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v8, (UFG::qResourceData *)&v5->mNode);
  v9 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v9;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mLightningMat.mPrev, 0xB4C26312, v4, v9);
  v11 = v2->mLightningMat.mData;
  v12 = HIDWORD(v11[2].mResourceHandles.mNode.mNext[6].mNext);
  if ( LODWORD(v11[3].mNode.mChild[1]) != v12 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v11[2].mDebugName[28], v11[3].mNode.mUID, v12);
    v13 = v11[1].mResourceHandles.mNode.mPrev;
    if ( v13 )
      v14 = (_WORD *)((char *)&v13[7].mNext + (_QWORD)v11);
    else
      v14 = 0i64;
    *v14 |= 0x20u;
  }
  UFG::qString::qString(&v37, "LightningMaterialTable");
  v16 = v37.mStringHash32;
  if ( v37.mStringHash32 == -1 )
  {
    v16 = UFG::qStringHash32(v37.mData, v37.mStringHash32 | v15);
    v37.mStringHash32 = v16;
  }
  v17 = Illusion::Factory::NewMaterialTable(v37.mData, v16, 1i64, 0i64, 0i64, 0i64);
  v2->mMaterialTable = (Illusion::MaterialTable *)v17;
  LODWORD(v17[1].mResourceHandles.mNode.mNext) = v4;
  v18 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v18, (UFG::qResourceData *)&v2->mMaterialTable->mNode);
  UFG::qString::~qString(&v37);
  v19 = (void **)&v2->mLMJoints[0].p;
  v20 = 4i64;
  v39 = 4i64;
  v21 = 2;
  do
  {
    numSubdivisions = Render::LightningManager::GenerateJointChain(v2, v21);
    v22 = *((unsigned int *)v19 - 2);
    v23 = v22 + 1;
    v24 = *((_DWORD *)v19 - 1);
    if ( (signed int)v22 + 1 > v24 )
    {
      if ( v24 )
        v25 = 2 * v24;
      else
        v25 = 1;
      for ( ; v25 < v23; v25 *= 2 )
        ;
      if ( v25 <= 2 )
        v25 = 2;
      if ( v25 - v23 > 0x10000 )
        v25 = v22 + 65537;
      if ( v25 != (_DWORD)v22 )
      {
        v26 = 8i64 * v25;
        if ( !is_mul_ok(v25, 8ui64) )
          v26 = -1i64;
        v27 = UFG::qMalloc(v26, "qArray.Add", 0i64);
        v28 = v27;
        if ( *v19 )
        {
          for ( i = 0; i < *((_DWORD *)v19 - 2); ++i )
            v27[i] = *(UFG::allocator::free_link *)((char *)*v19 + 8 * i);
          operator delete[](*v19);
        }
        *v19 = v28;
        *((_DWORD *)v19 - 1) = v25;
        v20 = v39;
      }
    }
    *((_DWORD *)v19 - 2) = v23;
    *((_QWORD *)*v19 + v22) = numSubdivisions;
    ++v21;
    v19 += 2;
    v39 = --v20;
  }
  while ( v20 );
  v30 = 504i64;
  v31 = &v2->mLMJoints[0].p;
  v32 = 4i64;
  do
  {
    *(_QWORD *)((char *)&v2->mTaskInputParam->frustumPlanes[0][0].x + v30) = (*v31)[(unsigned int)UFG::qRandom(
                                                                                                    *((_DWORD *)v31 - 2),
                                                                                                    &UFG::qDefaultSeed)];
    v30 += 8i64;
    v31 += 2;
    --v32;
  }
  while ( v32 );
  v33 = UFG::qStringHash32("cbLightningSettings", 0xFFFFFFFF);
  v2->mStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                             &Illusion::gStateSystem,
                                             v33,
                                             "cbLightningSettings",
                                             0);
  v2->mBoltArray = (Render::Bolt *)UFG::qMemoryPool::Allocate(
                                     v2->mMemoryPool,
                                     0xE100ui64,
                                     "LightningManager::BoltArray",
                                     0x1000ui64,
                                     1u);
  v34 = 0i64;
  do
  {
    v35 = v2->mBoltArray;
    v36 = &v35[(unsigned int)v32].headOffset;
    if ( v36 )
    {
      UFG::qHalfVector3::qHalfVector3(&v35[(unsigned int)v32].headOffset);
      UFG::qHalfVector3::qHalfVector3(v36 + 1);
    }
    v2->mBoltArray[v34].jointChain = v2->mLMJoints[3].p[(unsigned int)UFG::qRandom(
                                                                        v2->mLMJoints[3].size,
                                                                        &UFG::qDefaultSeed)];
    LODWORD(v32) = v32 + 1;
    ++v34;
  }
  while ( (unsigned int)v32 < 0x320 );
}

// File Line: 270
// RVA: 0x1C6C60
Render::ElectrifiedObject *__fastcall Render::LightningManager::AddElectrifiedObject(Render::LightningManager *this, Render::ElectrifiedObject *object)
{
  Render::ElectrifiedObject *v2; // rsi
  Render::LightningManager *v3; // rbp
  UFG::allocator::free_link *v4; // rax
  Render::ElectrifiedObject *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v7; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v9; // [rsp+68h] [rbp+20h]

  v2 = object;
  v3 = this;
  v4 = UFG::qMalloc(0x78ui64, "Electrified Object", 0i64);
  v5 = (Render::ElectrifiedObject *)v4;
  if ( v4 )
  {
    v4->mNext = v4;
    v4[1].mNext = v4;
    v6 = v4 + 2;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v6[2].mNext = 0i64;
    v9 = &v5->tailTransformNodeComponent;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v5->tailTransformNodeComponent.m_pPointer = 0i64;
    v5->headLightWeightPosition.m_pPointer = 0i64;
    v5->tailLightWeightPosition.m_pPointer = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  if ( v5 )
  {
    Render::ElectrifiedObject::operator=(v5, v2);
    v5->framesElapsed = 0;
    v7 = v3->mElectrifiedObjects.mNode.mPrev;
    v7->mNext = (UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *)&v5->mPrev;
    v5->mPrev = v7;
    v5->mNext = &v3->mElectrifiedObjects.mNode;
    v3->mElectrifiedObjects.mNode.mPrev = (UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *)&v5->mPrev;
  }
  return v5;
}

// File Line: 282
// RVA: 0x1D7B00
void __fastcall Render::LightningManager::StartSPUTasks(Render::LightningManager *this, Render::ViewSettings *view_settings, float fTime, float deltaTime, bool is_splitscreen)
{
  Render::ViewSettings *v5; // r13
  Render::LightningManager *v6; // rsi
  Illusion::Buffer *v7; // r15
  Illusion::Buffer *v8; // rax
  Illusion::Buffer *v9; // r14
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v10; // rbx
  signed __int64 v11; // rbp
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v12; // rdi
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *v13; // rax
  float *v14; // rax
  float v15; // xmm14_4
  float v16; // xmm12_4
  float v17; // xmm10_4
  float v18; // xmm7_4
  float v19; // xmm15_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm13_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm11_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm9_4
  float v29; // xmm4_4
  float v30; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm6_4
  float v33; // xmm1_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  int v36; // xmm2_4
  int v37; // xmm1_4
  int v38; // xmm0_4
  int v39; // xmm2_4
  int v40; // xmm1_4
  int v41; // xmm0_4
  int v42; // xmm2_4
  int v43; // xmm1_4
  int v44; // xmm0_4
  int v45; // xmm2_4
  int v46; // xmm1_4
  int v47; // xmm0_4
  int v48; // xmm2_4
  int v49; // xmm1_4
  int v50; // xmm0_4
  int v51; // xmm3_4
  int v52; // xmm2_4
  int v53; // xmm1_4
  float v54; // xmm5_4
  __m128 v55; // xmm4
  float v56; // xmm3_4
  __m128 v57; // xmm2
  float v58; // xmm0_4
  float v59; // xmm1_4
  __m128 v60; // xmm6
  float v61; // xmm3_4
  float v62; // xmm5_4
  __m128 v63; // xmm2
  float v64; // xmm0_4
  __m128 v65; // xmm6
  float v66; // xmm3_4
  float v67; // xmm5_4
  __m128 v68; // xmm2
  float v69; // xmm0_4
  __m128 v70; // xmm6
  float v71; // xmm3_4
  float v72; // xmm5_4
  __m128 v73; // xmm2
  float v74; // xmm0_4
  __m128 v75; // xmm6
  float v76; // xmm3_4
  float v77; // xmm5_4
  __m128 v78; // xmm2
  float v79; // xmm0_4
  __m128 v80; // xmm5
  float v81; // xmm3_4
  __m128 v82; // xmm2
  float v83; // xmm7_4
  float v84; // xmm1_4
  float v85; // xmm7_4
  Render::LightningTaskParam *v86; // rax
  float v87; // xmm1_4
  __int64 v88; // rax
  signed __int64 v89; // rcx
  __int64 v90; // rax
  signed __int64 v91; // rcx
  Render::LightningTaskOutputParam *v92; // rbx
  Render::LightningTaskParam *v93; // rdi
  char *v94; // rax
  UFG::qTask *v95; // rdx
  _QWORD *v96; // rcx
  UFG::qSpuElf *v97; // rax
  void (__fastcall *v98)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v99)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v100)(void *, void *, void *, void *); // r9
  char *v101; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v102; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v103; // rax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-158h]
  char *v105; // [rsp+60h] [rbp-118h]
  char *v106; // [rsp+68h] [rbp-110h]
  __int64 v107; // [rsp+70h] [rbp-108h]
  UFG::qMatrix44 d; // [rsp+80h] [rbp-F8h]

  v107 = -2i64;
  v5 = view_settings;
  v6 = this;
  v7 = Render::LightningManager::FrameMallocBuffer(this, TYPE_OCCLUSION);
  v8 = Render::LightningManager::FrameMallocBuffer(v6, 0);
  v9 = v8;
  if ( v7 && v8 )
  {
    UFG::qGetTicks();
    v6->mCurrentBuffer = v6->mCurrentBuffer == 0;
    v6->mTaskInputParam->boltArray = v6->mBoltArray;
    v6->mTaskInputParam->numBolts = v6->mNumBolts;
    v6->mTaskInputParam->isSplitscreen = is_splitscreen;
    v10 = v6->mElectrifiedObjects.mNode.mNext;
    v11 = (signed __int64)&v6->mElectrifiedObjects;
    if ( v10 != (UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *)&v6->mElectrifiedObjects )
    {
      do
      {
        v12 = v10->mNext;
        if ( LODWORD(v10[7].mPrev) != 2 || fTime <= *(float *)&v10[6].mNext )
        {
          ++HIDWORD(v10[6].mNext);
        }
        else
        {
          v13 = v10->mPrev;
          v13->mNext = v12;
          v12->mPrev = v13;
          v10->mPrev = v10;
          v10->mNext = v10;
          Render::ElectrifiedObject::~ElectrifiedObject((Render::ElectrifiedObject *)v10);
          operator delete[](v10);
        }
        v10 = v12;
      }
      while ( v12 != (UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *)v11 );
    }
    v6->mTaskInputParam->electrifiedObjectListStart = v6->mElectrifiedObjects.mNode.mNext;
    v6->mTaskInputParam->electrifiedObjectListEnd = (void *)v11;
    v6->mTaskInputParam->seed = UFG::qDefaultSeed;
    v6->mTaskInputParam->time = fTime;
    v6->mTaskInputParam->deltaTime = deltaTime;
    v6->mTaskInputParam->numFrustums = 1;
    UFG::qMatrix44::operator*(&v5->mWorldView, &result, &v5->mProjection);
    v14 = (float *)v6->mTaskInputParam;
    *v14 = result.v0.z;
    v15 = result.v1.z;
    v14[1] = result.v1.z;
    v16 = result.v2.z;
    v14[2] = result.v2.z;
    v17 = result.v3.z;
    v14[3] = result.v3.z;
    v18 = result.v3.x;
    v19 = result.v3.w;
    v20 = result.v3.x + result.v3.w;
    v21 = result.v2.x;
    v22 = result.v2.w;
    v23 = result.v2.x + result.v2.w;
    v24 = result.v1.x;
    v25 = result.v1.w;
    v26 = result.v1.x + result.v1.w;
    v27 = result.v0.x;
    v28 = result.v0.w;
    v14[4] = result.v0.x + result.v0.w;
    v14[5] = v26;
    v14[6] = v23;
    v14[7] = v20;
    v14[8] = v28 - v27;
    v14[9] = v25 - v24;
    v14[10] = v22 - v21;
    v14[11] = v19 - v18;
    v29 = result.v3.y + v19;
    v30 = result.v2.y;
    v31 = result.v2.y + v22;
    v32 = result.v1.y;
    v33 = result.v1.y + v25;
    v34 = result.v0.y;
    v14[12] = result.v0.y + v28;
    v14[13] = v33;
    v14[14] = v31;
    v14[15] = v29;
    v35 = v19 - result.v3.y;
    v14[16] = v28 - v34;
    v14[17] = v25 - v32;
    v14[18] = v22 - v30;
    v14[19] = v35;
    v14[20] = v28 - result.v0.z;
    v14[21] = v25 - v15;
    v14[22] = v22 - v16;
    v14[23] = v19 - v17;
    v36 = *((_DWORD *)v14 + 1) ^ _xmm[0];
    v37 = *((_DWORD *)v14 + 2) ^ _xmm[0];
    v38 = *((_DWORD *)v14 + 3) ^ _xmm[0];
    *(_DWORD *)v14 ^= _xmm[0];
    *((_DWORD *)v14 + 1) = v36;
    *((_DWORD *)v14 + 2) = v37;
    *((_DWORD *)v14 + 3) = v38;
    v39 = *((_DWORD *)v14 + 5) ^ _xmm[0];
    v40 = *((_DWORD *)v14 + 6) ^ _xmm[0];
    v41 = *((_DWORD *)v14 + 7) ^ _xmm[0];
    *((_DWORD *)v14 + 4) ^= _xmm[0];
    *((_DWORD *)v14 + 5) = v39;
    *((_DWORD *)v14 + 6) = v40;
    *((_DWORD *)v14 + 7) = v41;
    v42 = *((_DWORD *)v14 + 9) ^ _xmm[0];
    v43 = *((_DWORD *)v14 + 10) ^ _xmm[0];
    v44 = *((_DWORD *)v14 + 11) ^ _xmm[0];
    *((_DWORD *)v14 + 8) ^= _xmm[0];
    *((_DWORD *)v14 + 9) = v42;
    *((_DWORD *)v14 + 10) = v43;
    *((_DWORD *)v14 + 11) = v44;
    v45 = *((_DWORD *)v14 + 13) ^ _xmm[0];
    v46 = *((_DWORD *)v14 + 14) ^ _xmm[0];
    v47 = *((_DWORD *)v14 + 15) ^ _xmm[0];
    *((_DWORD *)v14 + 12) ^= _xmm[0];
    *((_DWORD *)v14 + 13) = v45;
    *((_DWORD *)v14 + 14) = v46;
    *((_DWORD *)v14 + 15) = v47;
    v48 = *((_DWORD *)v14 + 17) ^ _xmm[0];
    v49 = *((_DWORD *)v14 + 18) ^ _xmm[0];
    v50 = *((_DWORD *)v14 + 19) ^ _xmm[0];
    *((_DWORD *)v14 + 16) ^= _xmm[0];
    *((_DWORD *)v14 + 17) = v48;
    *((_DWORD *)v14 + 18) = v49;
    *((_DWORD *)v14 + 19) = v50;
    v51 = *((_DWORD *)v14 + 23) ^ _xmm[0];
    v52 = *((_DWORD *)v14 + 22) ^ _xmm[0];
    v53 = *((_DWORD *)v14 + 21) ^ _xmm[0];
    *((_DWORD *)v14 + 20) ^= _xmm[0];
    *((_DWORD *)v14 + 21) = v53;
    *((_DWORD *)v14 + 22) = v52;
    *((_DWORD *)v14 + 23) = v51;
    v54 = v14[1];
    v55 = (__m128)*(unsigned int *)v14;
    v56 = v14[2];
    v57 = v55;
    v57.m128_f32[0] = (float)((float)(v55.m128_f32[0] * v55.m128_f32[0]) + (float)(v54 * v54)) + (float)(v56 * v56);
    LODWORD(v58) = (unsigned __int128)_mm_sqrt_ps(v57);
    v59 = (float)(1.0 / v58) * v14[3];
    *v14 = v55.m128_f32[0] * (float)(1.0 / v58);
    v14[1] = v54 * (float)(1.0 / v58);
    v14[2] = v56 * (float)(1.0 / v58);
    v14[3] = v59;
    v60 = (__m128)*((unsigned int *)v14 + 5);
    v61 = v14[4];
    v62 = v14[6];
    v63 = v60;
    v63.m128_f32[0] = (float)((float)(v60.m128_f32[0] * v60.m128_f32[0]) + (float)(v61 * v61)) + (float)(v62 * v62);
    LODWORD(v64) = (unsigned __int128)_mm_sqrt_ps(v63);
    v55.m128_f32[0] = (float)(1.0 / v64) * v14[7];
    v14[4] = (float)(1.0 / v64) * v61;
    v14[5] = v60.m128_f32[0] * (float)(1.0 / v64);
    v14[6] = v62 * (float)(1.0 / v64);
    v14[7] = v55.m128_f32[0];
    v65 = (__m128)*((unsigned int *)v14 + 9);
    v66 = v14[8];
    v67 = v14[10];
    v68 = v65;
    v68.m128_f32[0] = (float)((float)(v65.m128_f32[0] * v65.m128_f32[0]) + (float)(v66 * v66)) + (float)(v67 * v67);
    LODWORD(v69) = (unsigned __int128)_mm_sqrt_ps(v68);
    v55.m128_f32[0] = (float)(1.0 / v69) * v14[11];
    v14[8] = (float)(1.0 / v69) * v66;
    v14[9] = v65.m128_f32[0] * (float)(1.0 / v69);
    v14[10] = v67 * (float)(1.0 / v69);
    v14[11] = v55.m128_f32[0];
    v70 = (__m128)*((unsigned int *)v14 + 13);
    v71 = v14[12];
    v72 = v14[14];
    v73 = v70;
    v73.m128_f32[0] = (float)((float)(v70.m128_f32[0] * v70.m128_f32[0]) + (float)(v71 * v71)) + (float)(v72 * v72);
    LODWORD(v74) = (unsigned __int128)_mm_sqrt_ps(v73);
    v55.m128_f32[0] = (float)(1.0 / v74) * v14[15];
    v14[12] = (float)(1.0 / v74) * v71;
    v14[13] = v70.m128_f32[0] * (float)(1.0 / v74);
    v14[14] = v72 * (float)(1.0 / v74);
    v14[15] = v55.m128_f32[0];
    v75 = (__m128)*((unsigned int *)v14 + 17);
    v76 = v14[16];
    v77 = v14[18];
    v78 = v75;
    v78.m128_f32[0] = (float)((float)(v75.m128_f32[0] * v75.m128_f32[0]) + (float)(v76 * v76)) + (float)(v77 * v77);
    LODWORD(v79) = (unsigned __int128)_mm_sqrt_ps(v78);
    v55.m128_f32[0] = (float)(1.0 / v79) * v14[19];
    v14[16] = (float)(1.0 / v79) * v76;
    v14[17] = v75.m128_f32[0] * (float)(1.0 / v79);
    v14[18] = v77 * (float)(1.0 / v79);
    v14[19] = v55.m128_f32[0];
    v80 = (__m128)*((unsigned int *)v14 + 21);
    v81 = v14[20];
    v55.m128_f32[0] = v14[22];
    v82 = v80;
    v82.m128_f32[0] = (float)((float)(v80.m128_f32[0] * v80.m128_f32[0]) + (float)(v81 * v81))
                    + (float)(v55.m128_f32[0] * v55.m128_f32[0]);
    v83 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v82));
    v84 = v83 * v81;
    v80.m128_f32[0] = v80.m128_f32[0] * v83;
    v55.m128_f32[0] = v55.m128_f32[0] * v83;
    v85 = v83 * v14[23];
    v14[20] = v84;
    v14[21] = v80.m128_f32[0];
    v14[22] = v55.m128_f32[0];
    v14[23] = v85;
    UFG::qInverseAffine(&d, &v5->mWorldView);
    v86 = v6->mTaskInputParam;
    v87 = d.v3.y;
    v82.m128_i32[0] = LODWORD(d.v3.z);
    v86->cameraPositions[0].x = d.v3.x;
    v86->cameraPositions[0].y = v87;
    LODWORD(v86->cameraPositions[0].z) = v82.m128_i32[0];
    v88 = v7->mData.mOffset;
    if ( v88 )
      v89 = (signed __int64)&v7->mData + v88;
    else
      v89 = 0i64;
    v6->mTaskInputParam->indexBuffer = (void *)v89;
    v90 = v9->mData.mOffset;
    if ( v90 )
      v91 = (signed __int64)&v9->mData + v90;
    else
      v91 = 0i64;
    v6->mTaskInputParam->vertexBuffer = (void *)v91;
    v92 = v6->mTaskOutputParam;
    v93 = v6->mTaskInputParam;
    v94 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v95 = (UFG::qTask *)v94;
    v106 = v94;
    v105 = v94;
    if ( v94 )
    {
      *(_QWORD *)v94 = v94;
      *((_QWORD *)v94 + 1) = v94;
      v96 = v94 + 16;
      *v96 = v96;
      v96[1] = v96;
      v97 = Render::gTaskFunctionDeclData_LightningTask.mSpuElf;
      v98 = Render::gTaskFunctionDeclData_LightningTask.mTaskFunctionSPU;
      v99 = Render::gTaskFunctionDeclData_LightningTask.mTaskFunctionPPU;
      v100 = Render::gTaskFunctionDeclData_LightningTask.mTaskFunctionOffload;
      if ( !Render::gTaskFunctionDeclData_LightningTask.mCurrentSPUEnabled )
      {
        v97 = 0i64;
        v98 = 0i64;
        v100 = 0i64;
      }
      v95->mTaskGroup = 0i64;
      v95->mFlags = 2;
      v95->mSyncVars.i64 = 0i64;
      v95->mSyncVars.v.mDependents = 0i64;
      v95->mFunctionDeclData = &Render::gTaskFunctionDeclData_LightningTask;
      if ( v97 )
        v101 = v97->mAddress;
      else
        v101 = 0i64;
      v95->mSPUElfAddress = v101;
      v95->mSPUFunction = v98;
      v95->mPPUFunction = v99;
      v95->mParam0 = v93;
      v95->mParam1 = v92;
      v95->mParam2 = 0i64;
      v95->mParam3 = 0i64;
      if ( v100 )
      {
        v95->mFlags = 130;
        v95->mOffloadThread = 0;
      }
    }
    v102 = UFG::gTaskManager.mSingleFrameTasks;
    v103 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
    v103->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v95->mPrev;
    v95->mPrev = v103;
    v95->mNext = &v102->mNode;
    v102->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v95->mPrev;
    v6->mTask = v95;
    v95->mFlags &= 0xFFFFFFF1;
    v95->mFlags |= 1u;
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v6->mTask);
  }
}

// File Line: 387
// RVA: 0x1D8660
void __fastcall Render::LightningManager::SyncTasks(Render::LightningManager *this)
{
  Render::LightningManager *v1; // rdi
  unsigned __int64 v2; // rbx
  unsigned __int64 v3; // rax

  v1 = this;
  if ( this->mTask )
  {
    v2 = UFG::qGetTicks();
    UFG::qTaskManager::Sync(&UFG::gTaskManager, v1->mTask);
    v1->mNumBolts = v1->mTaskOutputParam->numBolts;
    v3 = UFG::qGetTicks();
    UFG::qGetTickTime(v2, v3);
    v1->mTask = 0i64;
  }
}

// File Line: 414
// RVA: 0x1D4880
void __fastcall Render::LightningManager::Render(Render::LightningManager *this, Render::View *view, Illusion::Target *target, unsigned int alphaState)
{
  Render::View *v4; // rdi
  Render::LightningManager *v5; // rbx
  unsigned __int16 v6; // ax
  char *v7; // rax
  Illusion::StateArgs *v8; // rax
  Illusion::Primitive *v9; // r14
  unsigned int v10; // esi
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  Illusion::StateArgs *v13; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  Render::cbLightningGlobalSettings arg; // [rsp+48h] [rbp-28h]

  v4 = view;
  v5 = this;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbLightningGlobalSettings::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbLightningGlobalSettings::sStateParamIndex == -1 )
  {
    v6 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLightningGlobalSettings");
    Render::cbLightningGlobalSettings::sStateParamIndex = v6;
    arg.mStateParamIndex = v6;
  }
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  arg.mSettings = (CB_LightningGlobalSettings *)v7;
  if ( v7 )
  {
    if ( v5->mTaskOutputParam->numQuads )
    {
      *(float *)v7 = Render::lightningWidthScale;
      arg.mSettings->LightningConstants[1] = 1.0;
      v8 = Render::View::GetStateArgs(v4);
      Illusion::StateArgs::Set<Render::cbLightningGlobalSettings>(v8, &arg);
      v9 = Illusion::Primitive::Create("ElectricityPrimitive");
      if ( !(_S6_5 & 1) )
      {
        _S6_5 |= 1u;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&declHandle.mPrev);
        atexit(declHandle::LightningManager::Render_::_9_::_dynamic_atexit_destructor_for__declHandle__);
      }
      v10 = UFG::qStringHash32("VertexDecl.Lightning", 0xFFFFFFFF);
      v11 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x3E5FDA3Eu);
        `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v11;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&declHandle.mPrev, 0x3E5FDA3Eu, v10, v11);
      Illusion::Primitive::SetBuffers(
        v9,
        TRIANGLELIST,
        v5->mTaskInputParam->vertexBuffer,
        v5->mTaskOutputParam->numVertices,
        (Illusion::VertexDecl *)declHandle.mData,
        v5->mTaskInputParam->indexBuffer,
        v5->mTaskOutputParam->numIndices,
        1);
      Render::View::Draw(v4, v9, (Illusion::Material *)v5->mLightningMat.mData, &UFG::qMatrix44::msIdentity);
    }
    v13 = Render::View::GetStateArgs(v4);
    v14 = arg.mPrev;
    v15 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v15->mPrev = v14;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v13->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v13 + 16 * (arg.mStateParamIndex + 3i64)) )
      v13->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  v16 = arg.mPrev;
  v17 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v17->mPrev = v16;
}

// File Line: 454
// RVA: 0x1D10D0
void __fastcall Render::LightningManager::JitterBolt(Render::LightningManager *this, LightningJoint *jointArray, int startIndex, int endIndex, float level, unsigned int numSubdivisions)
{
  float v6; // xmm8_4
  int v7; // esi
  LightningJoint *v8; // rbp
  LightningJoint *v9; // rdi
  UFG::qVector2 *v10; // rbx
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  float v16; // xmm2_4
  int v17; // ebp
  signed __int64 v18; // rbx
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // ecx
  float v22; // xmm1_4
  UFG::qVector2 range; // [rsp+30h] [rbp-B8h]
  LightningJoint *i; // [rsp+38h] [rbp-B0h]
  UFG::qVector2 result; // [rsp+40h] [rbp-A8h]
  Render::LightningManager *v26; // [rsp+F0h] [rbp+8h]
  LightningJoint *jointArraya; // [rsp+F8h] [rbp+10h]
  int v28; // [rsp+108h] [rbp+20h]

  v28 = endIndex;
  jointArraya = jointArray;
  v26 = this;
  v6 = level;
  v7 = startIndex;
  v8 = &jointArray[endIndex];
  for ( i = &jointArray[endIndex]; ; v8 = i )
  {
    range = (UFG::qVector2)1056964608i64;
    v9 = &jointArray[v7];
    v10 = UFG::qRandom(&result, &range, &UFG::qDefaultSeed);
    v11 = expf(v6 * -0.5) * v10->x;
    v12 = UFG::qRandom(0.1, &UFG::qDefaultSeed);
    v13 = v8->pos.z;
    v14 = v8->pos.x;
    v15 = v9->pos.y;
    v16 = v8->pos.y;
    v17 = (v7 + v28) / 2;
    v18 = (signed __int64)&jointArraya[v17];
    v19 = v12 + 0.44999999;
    v20 = v9->pos.z + (float)((float)(v13 - v9->pos.z) * v19);
    *(float *)v18 = v9->pos.x + (float)((float)(v14 - v9->pos.x) * v19);
    *(float *)(v18 + 8) = v20;
    *(float *)(v18 + 4) = v15 + (float)((float)(v16 - v15) * v19);
    *(float *)(v18 + 28) = v11;
    v21 = v9->right.x;
    v22 = v9->right.z;
    *(float *)(v18 + 16) = v9->right.y;
    *(float *)(v18 + 12) = v21;
    *(float *)(v18 + 20) = v22;
    *(float *)(v18 + 24) = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    if ( v6 >= (float)(signed int)numSubdivisions )
      break;
    v6 = v6 + 1.0;
    Render::LightningManager::JitterBolt(v26, jointArraya, v7, v17, v6, numSubdivisions);
    jointArray = jointArraya;
    v7 = (v7 + v28) / 2;
  }
}

// File Line: 485
// RVA: 0x1CBFF0
UFG::allocator::free_link *__fastcall Render::LightningManager::GenerateJointChain(Render::LightningManager *this, unsigned int numSubdivisions)
{
  unsigned int v2; // ebp
  Render::LightningManager *v3; // r14
  __int64 v4; // rbx
  UFG::allocator::free_link *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::allocator::free_link *v8; // rdi
  UFG::qVector3 *v9; // rax
  float v10; // xmm5_4
  __m128 v11; // xmm3
  float v12; // xmm4_4
  __m128 v13; // xmm2
  float v14; // xmm1_4
  int v15; // esi
  signed __int64 v16; // rbx
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm4_4
  __m128 v21; // xmm2
  float v22; // xmm3_4
  __m128 v23; // xmm5
  float v24; // xmm6_4
  UFG::qVector3 range; // [rsp+30h] [rbp-78h]
  UFG::qVector3 result; // [rsp+3Ch] [rbp-6Ch]

  v2 = numSubdivisions;
  v3 = this;
  v4 = (unsigned int)(signed int)(float)(powf(2.0, (float)(signed int)(numSubdivisions - 1)) + 1.0);
  v5 = UFG::qMemoryPool::Allocate(v3->mMemoryPool, 32 * v4, "Lightning::GenerateJointChain::mJoints", 0x1000ui64, 1u);
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  range.x = 0.0;
  range.y = 1.0;
  *(float *)&v5->mNext = UFG::qVector3::msZero.x;
  *((float *)&v5->mNext + 1) = v6;
  *(float *)&v5[1].mNext = v7;
  v8 = v5;
  range.z = 1.0;
  v9 = UFG::qRandom(&result, &range, &UFG::qDefaultSeed);
  v11 = (__m128)LODWORD(v9->y);
  v10 = v9->x;
  v11.m128_f32[0] = v11.m128_f32[0] - 0.5;
  v12 = v9->z - 0.5;
  HIDWORD(v8[1].mNext) = LODWORD(v9->x);
  v13 = v11;
  LODWORD(v8[2].mNext) = v11.m128_i32[0];
  *((float *)&v8[2].mNext + 1) = v12;
  v13.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10)) + (float)(v12 * v12);
  if ( v13.m128_f32[0] == 0.0 )
    v14 = 0.0;
  else
    v14 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
  v15 = v4 - 1;
  *((float *)&v8[1].mNext + 1) = v10 * v14;
  *(float *)&v8[2].mNext = v11.m128_f32[0] * v14;
  v16 = (signed __int64)&v8[4 * (unsigned int)(v4 - 1)];
  range.x = 0.0;
  range.y = 1.0;
  *((float *)&v8[2].mNext + 1) = v12 * v14;
  v8[3].mNext = 0i64;
  range.z = 1.0;
  v17 = UFG::qVector3::msAxisX.y;
  v18 = UFG::qVector3::msAxisX.z;
  *(float *)v16 = UFG::qVector3::msAxisX.x;
  *(float *)(v16 + 4) = v17;
  *(float *)(v16 + 8) = v18;
  v19 = UFG::qRandom(&result, &range, &UFG::qDefaultSeed);
  v21 = (__m128)LODWORD(v19->y);
  v20 = v19->x;
  v21.m128_f32[0] = v21.m128_f32[0] - 0.5;
  v22 = v19->z - 0.5;
  *(float *)(v16 + 12) = v19->x;
  v23 = v21;
  *(_DWORD *)(v16 + 16) = v21.m128_i32[0];
  *(float *)(v16 + 20) = v22;
  v23.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22);
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  *(float *)(v16 + 12) = v20 * v24;
  *(float *)(v16 + 16) = v21.m128_f32[0] * v24;
  *(float *)(v16 + 20) = v22 * v24;
  *(_QWORD *)(v16 + 24) = 0i64;
  Render::LightningManager::JitterBolt(v3, (LightningJoint *)v8, 0, v15, 2.0, v2);
  return v8;
}

