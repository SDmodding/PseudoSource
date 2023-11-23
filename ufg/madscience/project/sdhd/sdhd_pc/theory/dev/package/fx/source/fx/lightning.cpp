// File Line: 53
// RVA: 0x146B730
__int64 Render::_dynamic_initializer_for__gLightningManager__()
{
  Render::LightningManager::LightningManager(&Render::gLightningManager);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gLightningManager__);
}

// File Line: 93
// RVA: 0x1CBEE0
Illusion::Buffer *__fastcall Render::LightningManager::FrameMallocBuffer(
        Render::LightningManager *this,
        Illusion::Buffer::BufferType bufferType)
{
  char v2; // r14
  unsigned int v3; // ebx
  unsigned int v4; // edi
  char *v5; // rsi
  Illusion::Buffer *result; // rax
  unsigned int v7; // edx

  v2 = bufferType;
  if ( bufferType == TYPE_OCCLUSION )
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
  if ( (_S5_5 & 1) != 0 )
  {
    v7 = lightningBufferUID;
  }
  else
  {
    _S5_5 |= 1u;
    v7 = UFG::qStringHashUpper32("Electricity Buffer", -1);
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
  UFG::qArray<LightningJoint *,0> *mLMJoints; // rbx
  __int64 v3; // rdi

  UFG::qResourceHandle::qResourceHandle(&this->mLightningMat);
  mLMJoints = this->mLMJoints;
  v3 = 4i64;
  `eh vector constructor iterator(
    this->mLMJoints,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  this->mElectrifiedObjects.mNode.mPrev = &this->mElectrifiedObjects.mNode;
  this->mElectrifiedObjects.mNode.mNext = &this->mElectrifiedObjects.mNode;
  this->mMaterialTable = 0i64;
  this->mNumQuads = 0;
  this->mTask = 0i64;
  this->mCurrentBuffer = 0;
  this->mTaskOutputParam = 0i64;
  this->mDebugDrawsEnabled = 0;
  this->mNumBolts = 0;
  this->mBoltArray = 0i64;
  do
  {
    *(_QWORD *)&mLMJoints->size = 0i64;
    mLMJoints->p = 0i64;
    ++mLMJoints;
    --v3;
  }
  while ( v3 );
}

// File Line: 135
// RVA: 0x1C41D0
void __fastcall Render::LightningManager::~LightningManager(Render::LightningManager *this)
{
  UFG::qList<Render::ElectrifiedObject,Render::ElectrifiedObject,1,0> *p_mElectrifiedObjects; // rbx
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *mPrev; // rcx
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *mNext; // rax
  Illusion::MaterialHandle *p_mLightningMat; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax

  p_mElectrifiedObjects = &this->mElectrifiedObjects;
  UFG::qList<Render::ElectrifiedObject,Render::ElectrifiedObject,1,0>::DeleteNodes(&this->mElectrifiedObjects);
  mPrev = p_mElectrifiedObjects->mNode.mPrev;
  mNext = p_mElectrifiedObjects->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mElectrifiedObjects->mNode.mPrev = &p_mElectrifiedObjects->mNode;
  p_mElectrifiedObjects->mNode.mNext = &p_mElectrifiedObjects->mNode;
  `eh vector destructor iterator(
    this->mLMJoints,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>);
  p_mLightningMat = &this->mLightningMat;
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mLightningMat, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mLightningMat);
}

// File Line: 140
// RVA: 0x1CEC30
void __fastcall Render::LightningManager::Init(Render::LightningManager *this, UFG::qMemoryPool *memoryPool)
{
  hkResourceHandle *v3; // rax
  unsigned int v4; // r15d
  Illusion::Material *v5; // rdi
  int v6; // ebx
  int v7; // ebx
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceData *mData; // rbx
  unsigned int mNext_high; // r8d
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  _WORD *v14; // rax
  unsigned int mStringHash32; // eax
  Illusion::MaterialTable *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  void **p_p; // rdi
  __int64 v19; // r15
  unsigned int v20; // r12d
  __int64 v21; // r13
  unsigned int v22; // esi
  unsigned int v23; // ebx
  unsigned int v24; // ebx
  unsigned __int64 v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // r15
  unsigned int i; // r9d
  __int64 v29; // rbx
  LightningJoint ***v30; // r12
  __int64 v31; // rbp
  unsigned int v32; // eax
  __int64 v33; // rdi
  Render::Bolt *mBoltArray; // rax
  UFG::qHalfVector3 *p_headOffset; // rbx
  UFG::qString v36; // [rsp+38h] [rbp-70h] BYREF
  UFG::allocator::free_link *numSubdivisions; // [rsp+B8h] [rbp+10h]
  __int64 v38; // [rsp+C0h] [rbp+18h]

  this->mMemoryPool = memoryPool;
  if ( !memoryPool )
    memoryPool = UFG::gMainMemoryPool;
  this->mMemoryPool = memoryPool;
  v3 = (hkResourceHandle *)UFG::qSpuManager::Instance();
  this->mSPUElf = (UFG::qSpuElf *)TargetVisibleInAIDataCondition::CreateClone(v3);
  this->mNumQuads = 0;
  this->mTaskInputParam = (Render::LightningTaskParam *)UFG::qMemoryPool::Allocate(
                                                          this->mMemoryPool,
                                                          0x228ui64,
                                                          "Render::LightningTaskParam",
                                                          0x1000ui64,
                                                          1u);
  this->mTaskOutputParam = (Render::LightningTaskOutputParam *)UFG::qMemoryPool::Allocate(
                                                                 this->mMemoryPool,
                                                                 0x18ui64,
                                                                 "Render::LightningTaskOutputParam",
                                                                 0x1000ui64,
                                                                 1u);
  v4 = UFG::qStringHashUpper32("LightningMat", -1);
  v5 = Illusion::Factory::NewMaterial("LightningMat", v4, 4u, 0i64, 0i64, 0i64);
  v6 = UFG::qStringHash32("LIGHTNING", 0xFFFFFFFF);
  LOWORD(v5[1].mNode.mChild[0]) = 0;
  HIDWORD(v5[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v5[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v5[1].mTypeUID = -1957338719;
  LODWORD(v5[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v6;
  v7 = UFG::qStringHashUpper32("FX_Lightning001", -1);
  *(_WORD *)&v5[1].mDebugName[12] = 0;
  *(_DWORD *)&v5[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v5[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v5[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v5[1].mStateBlockMask.mFlags[0]) = v7;
  LOWORD(v5[1].mMaterialUser.mOffset) = 0;
  *(&v5[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v5[1].mNumParams = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v5[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v5[2].mNode.mUID = 1775952593;
  LOWORD(v5[2].mTypeUID) = 0;
  HIDWORD(v5[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v5[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v5[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v5[2].mDebugName[28] = 1099738947;
  v8 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v8, v5);
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v10, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mLightningMat, 0xB4C26312, v4, Inventory);
  mData = this->mLightningMat.mData;
  mNext_high = HIDWORD(mData[2].mResourceHandles.mNode.mNext[6].mNext);
  if ( LODWORD(mData[3].mNode.mChild[1]) != mNext_high )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&mData[2].mDebugName[28], mData[3].mNode.mUID, mNext_high);
    mPrev = mData[1].mResourceHandles.mNode.mPrev;
    if ( mPrev )
      v14 = (_WORD *)((char *)&mPrev[7].mNext + (_QWORD)mData);
    else
      v14 = 0i64;
    *v14 |= 0x20u;
  }
  UFG::qString::qString(&v36, "LightningMaterialTable");
  mStringHash32 = v36.mStringHash32;
  if ( v36.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(v36.mData, 0xFFFFFFFF);
    v36.mStringHash32 = mStringHash32;
  }
  v16 = Illusion::Factory::NewMaterialTable(v36.mData, mStringHash32, 1i64, 0i64, 0i64, 0i64);
  this->mMaterialTable = v16;
  v16[1].mNode.mUID = v4;
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, this->mMaterialTable);
  UFG::qString::~qString(&v36);
  p_p = (void **)&this->mLMJoints[0].p;
  v19 = 4i64;
  v38 = 4i64;
  v20 = 2;
  do
  {
    numSubdivisions = Render::LightningManager::GenerateJointChain(this, v20);
    v21 = *((unsigned int *)p_p - 2);
    v22 = v21 + 1;
    v23 = *((_DWORD *)p_p - 1);
    if ( (int)v21 + 1 > v23 )
    {
      if ( v23 )
        v24 = 2 * v23;
      else
        v24 = 1;
      for ( ; v24 < v22; v24 *= 2 )
        ;
      if ( v24 <= 2 )
        v24 = 2;
      if ( v24 - v22 > 0x10000 )
        v24 = v21 + 65537;
      if ( v24 != (_DWORD)v21 )
      {
        v25 = 8i64 * v24;
        if ( !is_mul_ok(v24, 8ui64) )
          v25 = -1i64;
        v26 = UFG::qMalloc(v25, "qArray.Add", 0i64);
        v27 = v26;
        if ( *p_p )
        {
          for ( i = 0; i < *((_DWORD *)p_p - 2); ++i )
            v26[i] = *(UFG::allocator::free_link *)((char *)*p_p + 8 * i);
          operator delete[](*p_p);
        }
        *p_p = v27;
        *((_DWORD *)p_p - 1) = v24;
        v19 = v38;
      }
    }
    *((_DWORD *)p_p - 2) = v22;
    *((_QWORD *)*p_p + v21) = numSubdivisions;
    ++v20;
    p_p += 2;
    v38 = --v19;
  }
  while ( v19 );
  v29 = 504i64;
  v30 = &this->mLMJoints[0].p;
  v31 = 4i64;
  do
  {
    *(_QWORD *)((char *)&this->mTaskInputParam->frustumPlanes[0][0].x + v29) = (*v30)[(unsigned int)UFG::qRandom(*((_DWORD *)v30 - 2), (unsigned int *)&UFG::qDefaultSeed)];
    v29 += 8i64;
    v30 += 2;
    --v31;
  }
  while ( v31 );
  v32 = UFG::qStringHash32("cbLightningSettings", 0xFFFFFFFF);
  this->mStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                               &Illusion::gStateSystem,
                                               v32,
                                               "cbLightningSettings",
                                               0);
  this->mBoltArray = (Render::Bolt *)UFG::qMemoryPool::Allocate(
                                       this->mMemoryPool,
                                       0xE100ui64,
                                       "LightningManager::BoltArray",
                                       0x1000ui64,
                                       1u);
  v33 = 0i64;
  do
  {
    mBoltArray = this->mBoltArray;
    p_headOffset = &mBoltArray[(unsigned int)v31].headOffset;
    if ( p_headOffset )
    {
      UFG::qHalfVector3::qHalfVector3(&mBoltArray[(unsigned int)v31].headOffset);
      UFG::qHalfVector3::qHalfVector3(p_headOffset + 1);
    }
    this->mBoltArray[v33].jointChain = this->mLMJoints[3].p[(unsigned int)UFG::qRandom(
                                                                            this->mLMJoints[3].size,
                                                                            (unsigned int *)&UFG::qDefaultSeed)];
    LODWORD(v31) = v31 + 1;
    ++v33;
  }
  while ( (unsigned int)v31 < 0x320 );
}

// File Line: 270
// RVA: 0x1C6C60
Render::ElectrifiedObject *__fastcall Render::LightningManager::AddElectrifiedObject(
        Render::LightningManager *this,
        Render::ElectrifiedObject *object)
{
  UFG::allocator::free_link *v4; // rax
  Render::ElectrifiedObject *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *mPrev; // rcx

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
    v5->tailTransformNodeComponent.mPrev = &v5->tailTransformNodeComponent;
    v5->tailTransformNodeComponent.mNext = &v5->tailTransformNodeComponent;
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
    Render::ElectrifiedObject::operator=(v5, object);
    v5->framesElapsed = 0;
    mPrev = this->mElectrifiedObjects.mNode.mPrev;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    v5->mNext = &this->mElectrifiedObjects.mNode;
    this->mElectrifiedObjects.mNode.mPrev = v5;
  }
  return v5;
}

// File Line: 282
// RVA: 0x1D7B00
void __fastcall Render::LightningManager::StartSPUTasks(
        Render::LightningManager *this,
        Render::ViewSettings *view_settings,
        float fTime,
        float deltaTime,
        bool is_splitscreen)
{
  Illusion::Buffer *v7; // r15
  Illusion::Buffer *v8; // rax
  Illusion::Buffer *v9; // r14
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *mNext; // rbx
  UFG::qList<Render::ElectrifiedObject,Render::ElectrifiedObject,1,0> *p_mElectrifiedObjects; // rbp
  UFG::qList<Render::ElectrifiedObject,Render::ElectrifiedObject,1,0> *v12; // rdi
  UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *mPrev; // rax
  float *mTaskInputParam; // rax
  float z; // xmm14_4
  float v16; // xmm12_4
  float v17; // xmm10_4
  float x; // xmm7_4
  float w; // xmm15_4
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
  float y; // xmm7_4
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
  __int64 mOffset; // rax
  char *v89; // rcx
  __int64 v90; // rax
  char *v91; // rcx
  Render::LightningTaskOutputParam *mTaskOutputParam; // rbx
  Render::LightningTaskParam *v93; // rdi
  char *v94; // rax
  UFG::qTask *v95; // rdx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v102; // rax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-158h] BYREF
  char *v104; // [rsp+60h] [rbp-118h]
  char *v105; // [rsp+68h] [rbp-110h]
  __int64 v106; // [rsp+70h] [rbp-108h]
  UFG::qMatrix44 d; // [rsp+80h] [rbp-F8h] BYREF

  v106 = -2i64;
  v7 = Render::LightningManager::FrameMallocBuffer(this, TYPE_OCCLUSION);
  v8 = Render::LightningManager::FrameMallocBuffer(this, TYPE_CULL);
  v9 = v8;
  if ( v7 && v8 )
  {
    UFG::qGetTicks();
    this->mCurrentBuffer = this->mCurrentBuffer == 0;
    this->mTaskInputParam->boltArray = this->mBoltArray;
    this->mTaskInputParam->numBolts = this->mNumBolts;
    this->mTaskInputParam->isSplitscreen = is_splitscreen;
    mNext = this->mElectrifiedObjects.mNode.mNext;
    p_mElectrifiedObjects = &this->mElectrifiedObjects;
    if ( mNext != (UFG::qNode<Render::ElectrifiedObject,Render::ElectrifiedObject> *)&this->mElectrifiedObjects )
    {
      do
      {
        v12 = (UFG::qList<Render::ElectrifiedObject,Render::ElectrifiedObject,1,0> *)mNext->mNext;
        if ( LODWORD(mNext[7].mPrev) == 2 && fTime > *(float *)&mNext[6].mNext )
        {
          mPrev = mNext->mPrev;
          mPrev->mNext = &v12->mNode;
          v12->mNode.mPrev = mPrev;
          mNext->mPrev = mNext;
          mNext->mNext = mNext;
          Render::ElectrifiedObject::~ElectrifiedObject((Render::ElectrifiedObject *)mNext);
          operator delete[](mNext);
        }
        else
        {
          ++HIDWORD(mNext[6].mNext);
        }
        mNext = &v12->mNode;
      }
      while ( v12 != p_mElectrifiedObjects );
    }
    this->mTaskInputParam->electrifiedObjectListStart = this->mElectrifiedObjects.mNode.mNext;
    this->mTaskInputParam->electrifiedObjectListEnd = p_mElectrifiedObjects;
    this->mTaskInputParam->seed = UFG::qDefaultSeed;
    this->mTaskInputParam->time = fTime;
    this->mTaskInputParam->deltaTime = deltaTime;
    this->mTaskInputParam->numFrustums = 1;
    UFG::qMatrix44::operator*(&view_settings->mWorldView, &result, &view_settings->mProjection);
    mTaskInputParam = (float *)this->mTaskInputParam;
    *mTaskInputParam = result.v0.z;
    z = result.v1.z;
    mTaskInputParam[1] = result.v1.z;
    v16 = result.v2.z;
    mTaskInputParam[2] = result.v2.z;
    v17 = result.v3.z;
    mTaskInputParam[3] = result.v3.z;
    x = result.v3.x;
    w = result.v3.w;
    v20 = result.v3.x + result.v3.w;
    v21 = result.v2.x;
    v22 = result.v2.w;
    v23 = result.v2.x + result.v2.w;
    v24 = result.v1.x;
    v25 = result.v1.w;
    v26 = result.v1.x + result.v1.w;
    v27 = result.v0.x;
    v28 = result.v0.w;
    mTaskInputParam[4] = result.v0.x + result.v0.w;
    mTaskInputParam[5] = v26;
    mTaskInputParam[6] = v23;
    mTaskInputParam[7] = v20;
    mTaskInputParam[8] = v28 - v27;
    mTaskInputParam[9] = v25 - v24;
    mTaskInputParam[10] = v22 - v21;
    mTaskInputParam[11] = w - x;
    v29 = result.v3.y + w;
    y = result.v2.y;
    v31 = result.v2.y + v22;
    v32 = result.v1.y;
    v33 = result.v1.y + v25;
    v34 = result.v0.y;
    mTaskInputParam[12] = result.v0.y + v28;
    mTaskInputParam[13] = v33;
    mTaskInputParam[14] = v31;
    mTaskInputParam[15] = v29;
    v35 = w - result.v3.y;
    mTaskInputParam[16] = v28 - v34;
    mTaskInputParam[17] = v25 - v32;
    mTaskInputParam[18] = v22 - y;
    mTaskInputParam[19] = v35;
    mTaskInputParam[20] = v28 - result.v0.z;
    mTaskInputParam[21] = v25 - z;
    mTaskInputParam[22] = v22 - v16;
    mTaskInputParam[23] = w - v17;
    v36 = *((_DWORD *)mTaskInputParam + 1) ^ _xmm[0];
    v37 = *((_DWORD *)mTaskInputParam + 2) ^ _xmm[0];
    v38 = *((_DWORD *)mTaskInputParam + 3) ^ _xmm[0];
    *(_DWORD *)mTaskInputParam ^= _xmm[0];
    *((_DWORD *)mTaskInputParam + 1) = v36;
    *((_DWORD *)mTaskInputParam + 2) = v37;
    *((_DWORD *)mTaskInputParam + 3) = v38;
    v39 = *((_DWORD *)mTaskInputParam + 5) ^ _xmm[0];
    v40 = *((_DWORD *)mTaskInputParam + 6) ^ _xmm[0];
    v41 = *((_DWORD *)mTaskInputParam + 7) ^ _xmm[0];
    *((_DWORD *)mTaskInputParam + 4) ^= _xmm[0];
    *((_DWORD *)mTaskInputParam + 5) = v39;
    *((_DWORD *)mTaskInputParam + 6) = v40;
    *((_DWORD *)mTaskInputParam + 7) = v41;
    v42 = *((_DWORD *)mTaskInputParam + 9) ^ _xmm[0];
    v43 = *((_DWORD *)mTaskInputParam + 10) ^ _xmm[0];
    v44 = *((_DWORD *)mTaskInputParam + 11) ^ _xmm[0];
    *((_DWORD *)mTaskInputParam + 8) ^= _xmm[0];
    *((_DWORD *)mTaskInputParam + 9) = v42;
    *((_DWORD *)mTaskInputParam + 10) = v43;
    *((_DWORD *)mTaskInputParam + 11) = v44;
    v45 = *((_DWORD *)mTaskInputParam + 13) ^ _xmm[0];
    v46 = *((_DWORD *)mTaskInputParam + 14) ^ _xmm[0];
    v47 = *((_DWORD *)mTaskInputParam + 15) ^ _xmm[0];
    *((_DWORD *)mTaskInputParam + 12) ^= _xmm[0];
    *((_DWORD *)mTaskInputParam + 13) = v45;
    *((_DWORD *)mTaskInputParam + 14) = v46;
    *((_DWORD *)mTaskInputParam + 15) = v47;
    v48 = *((_DWORD *)mTaskInputParam + 17) ^ _xmm[0];
    v49 = *((_DWORD *)mTaskInputParam + 18) ^ _xmm[0];
    v50 = *((_DWORD *)mTaskInputParam + 19) ^ _xmm[0];
    *((_DWORD *)mTaskInputParam + 16) ^= _xmm[0];
    *((_DWORD *)mTaskInputParam + 17) = v48;
    *((_DWORD *)mTaskInputParam + 18) = v49;
    *((_DWORD *)mTaskInputParam + 19) = v50;
    v51 = *((_DWORD *)mTaskInputParam + 23) ^ _xmm[0];
    v52 = *((_DWORD *)mTaskInputParam + 22) ^ _xmm[0];
    v53 = *((_DWORD *)mTaskInputParam + 21) ^ _xmm[0];
    *((_DWORD *)mTaskInputParam + 20) ^= _xmm[0];
    *((_DWORD *)mTaskInputParam + 21) = v53;
    *((_DWORD *)mTaskInputParam + 22) = v52;
    *((_DWORD *)mTaskInputParam + 23) = v51;
    v54 = mTaskInputParam[1];
    v55 = (__m128)*(unsigned int *)mTaskInputParam;
    v56 = mTaskInputParam[2];
    v57 = v55;
    v57.m128_f32[0] = (float)((float)(v55.m128_f32[0] * v55.m128_f32[0]) + (float)(v54 * v54)) + (float)(v56 * v56);
    v58 = _mm_sqrt_ps(v57).m128_f32[0];
    v59 = (float)(1.0 / v58) * mTaskInputParam[3];
    *mTaskInputParam = v55.m128_f32[0] * (float)(1.0 / v58);
    mTaskInputParam[1] = v54 * (float)(1.0 / v58);
    mTaskInputParam[2] = v56 * (float)(1.0 / v58);
    mTaskInputParam[3] = v59;
    v60 = (__m128)*((unsigned int *)mTaskInputParam + 5);
    v61 = mTaskInputParam[4];
    v62 = mTaskInputParam[6];
    v63 = v60;
    v63.m128_f32[0] = (float)((float)(v60.m128_f32[0] * v60.m128_f32[0]) + (float)(v61 * v61)) + (float)(v62 * v62);
    v64 = _mm_sqrt_ps(v63).m128_f32[0];
    v55.m128_f32[0] = (float)(1.0 / v64) * mTaskInputParam[7];
    mTaskInputParam[4] = (float)(1.0 / v64) * v61;
    mTaskInputParam[5] = v60.m128_f32[0] * (float)(1.0 / v64);
    mTaskInputParam[6] = v62 * (float)(1.0 / v64);
    mTaskInputParam[7] = v55.m128_f32[0];
    v65 = (__m128)*((unsigned int *)mTaskInputParam + 9);
    v66 = mTaskInputParam[8];
    v67 = mTaskInputParam[10];
    v68 = v65;
    v68.m128_f32[0] = (float)((float)(v65.m128_f32[0] * v65.m128_f32[0]) + (float)(v66 * v66)) + (float)(v67 * v67);
    v69 = _mm_sqrt_ps(v68).m128_f32[0];
    v55.m128_f32[0] = (float)(1.0 / v69) * mTaskInputParam[11];
    mTaskInputParam[8] = (float)(1.0 / v69) * v66;
    mTaskInputParam[9] = v65.m128_f32[0] * (float)(1.0 / v69);
    mTaskInputParam[10] = v67 * (float)(1.0 / v69);
    mTaskInputParam[11] = v55.m128_f32[0];
    v70 = (__m128)*((unsigned int *)mTaskInputParam + 13);
    v71 = mTaskInputParam[12];
    v72 = mTaskInputParam[14];
    v73 = v70;
    v73.m128_f32[0] = (float)((float)(v70.m128_f32[0] * v70.m128_f32[0]) + (float)(v71 * v71)) + (float)(v72 * v72);
    v74 = _mm_sqrt_ps(v73).m128_f32[0];
    v55.m128_f32[0] = (float)(1.0 / v74) * mTaskInputParam[15];
    mTaskInputParam[12] = (float)(1.0 / v74) * v71;
    mTaskInputParam[13] = v70.m128_f32[0] * (float)(1.0 / v74);
    mTaskInputParam[14] = v72 * (float)(1.0 / v74);
    mTaskInputParam[15] = v55.m128_f32[0];
    v75 = (__m128)*((unsigned int *)mTaskInputParam + 17);
    v76 = mTaskInputParam[16];
    v77 = mTaskInputParam[18];
    v78 = v75;
    v78.m128_f32[0] = (float)((float)(v75.m128_f32[0] * v75.m128_f32[0]) + (float)(v76 * v76)) + (float)(v77 * v77);
    v79 = _mm_sqrt_ps(v78).m128_f32[0];
    v55.m128_f32[0] = (float)(1.0 / v79) * mTaskInputParam[19];
    mTaskInputParam[16] = (float)(1.0 / v79) * v76;
    mTaskInputParam[17] = v75.m128_f32[0] * (float)(1.0 / v79);
    mTaskInputParam[18] = v77 * (float)(1.0 / v79);
    mTaskInputParam[19] = v55.m128_f32[0];
    v80 = (__m128)*((unsigned int *)mTaskInputParam + 21);
    v81 = mTaskInputParam[20];
    v55.m128_f32[0] = mTaskInputParam[22];
    v82 = v80;
    v82.m128_f32[0] = (float)((float)(v80.m128_f32[0] * v80.m128_f32[0]) + (float)(v81 * v81))
                    + (float)(v55.m128_f32[0] * v55.m128_f32[0]);
    v83 = 1.0 / _mm_sqrt_ps(v82).m128_f32[0];
    v84 = v83 * v81;
    v80.m128_f32[0] = v80.m128_f32[0] * v83;
    v55.m128_f32[0] = v55.m128_f32[0] * v83;
    v85 = v83 * mTaskInputParam[23];
    mTaskInputParam[20] = v84;
    mTaskInputParam[21] = v80.m128_f32[0];
    mTaskInputParam[22] = v55.m128_f32[0];
    mTaskInputParam[23] = v85;
    UFG::qInverseAffine(&d, &view_settings->mWorldView);
    v86 = this->mTaskInputParam;
    v87 = d.v3.y;
    v82.m128_i32[0] = LODWORD(d.v3.z);
    v86->cameraPositions[0].x = d.v3.x;
    v86->cameraPositions[0].y = v87;
    LODWORD(v86->cameraPositions[0].z) = v82.m128_i32[0];
    mOffset = v7->mData.mOffset;
    if ( mOffset )
      v89 = (char *)&v7->mData + mOffset;
    else
      v89 = 0i64;
    this->mTaskInputParam->indexBuffer = v89;
    v90 = v9->mData.mOffset;
    if ( v90 )
      v91 = (char *)&v9->mData + v90;
    else
      v91 = 0i64;
    this->mTaskInputParam->vertexBuffer = v91;
    mTaskOutputParam = this->mTaskOutputParam;
    v93 = this->mTaskInputParam;
    v94 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v95 = (UFG::qTask *)v94;
    v105 = v94;
    v104 = v94;
    if ( v94 )
    {
      *(_QWORD *)v94 = v94;
      *((_QWORD *)v94 + 1) = v94;
      *((_QWORD *)v94 + 2) = v94 + 16;
      *((_QWORD *)v94 + 3) = v94 + 16;
      mSpuElf = Render::gTaskFunctionDeclData_LightningTask.mSpuElf;
      mTaskFunctionSPU = Render::gTaskFunctionDeclData_LightningTask.mTaskFunctionSPU;
      mTaskFunctionPPU = Render::gTaskFunctionDeclData_LightningTask.mTaskFunctionPPU;
      mTaskFunctionOffload = Render::gTaskFunctionDeclData_LightningTask.mTaskFunctionOffload;
      if ( !Render::gTaskFunctionDeclData_LightningTask.mCurrentSPUEnabled )
      {
        mSpuElf = 0i64;
        mTaskFunctionSPU = 0i64;
        mTaskFunctionOffload = 0i64;
      }
      v95->mTaskGroup = 0i64;
      v95->mFlags = 2;
      v95->mSyncVars.i64 = 0i64;
      v95->mSyncVars.v.mDependents = 0i64;
      v95->mFunctionDeclData = &Render::gTaskFunctionDeclData_LightningTask;
      if ( mSpuElf )
        mAddress = mSpuElf->mAddress;
      else
        mAddress = 0i64;
      v95->mSPUElfAddress = mAddress;
      v95->mSPUFunction = mTaskFunctionSPU;
      v95->mPPUFunction = mTaskFunctionPPU;
      v95->mParam0 = v93;
      v95->mParam1 = mTaskOutputParam;
      v95->mParam2 = 0i64;
      v95->mParam3 = 0i64;
      if ( mTaskFunctionOffload )
      {
        v95->mFlags = 130;
        v95->mOffloadThread = 0;
      }
    }
    mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
    v102 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
    v102->mNext = v95;
    v95->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v102;
    v95->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
    mSingleFrameTasks->mNode.mPrev = v95;
    this->mTask = v95;
    v95->mFlags &= 0xFFFFFFF1;
    v95->mFlags |= 1u;
    UFG::qTaskManager::Queue(&UFG::gTaskManager, this->mTask);
  }
}

// File Line: 387
// RVA: 0x1D8660
void __fastcall Render::LightningManager::SyncTasks(Render::LightningManager *this)
{
  unsigned __int64 Ticks; // rbx
  unsigned __int64 v3; // rax

  if ( this->mTask )
  {
    Ticks = UFG::qGetTicks();
    UFG::qTaskManager::Sync(&UFG::gTaskManager, this->mTask);
    this->mNumBolts = this->mTaskOutputParam->numBolts;
    v3 = UFG::qGetTicks();
    UFG::qGetTickTime(Ticks, v3);
    this->mTask = 0i64;
  }
}

// File Line: 414
// RVA: 0x1D4880
void __fastcall Render::LightningManager::Render(
        Render::LightningManager *this,
        Render::View *view,
        Illusion::Target *target,
        unsigned int alphaState)
{
  unsigned __int16 Param; // ax
  char *v7; // rax
  Illusion::StateArgs *StateArgs; // rax
  Illusion::Primitive *v9; // r14
  unsigned int v10; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v12; // rax
  Illusion::StateArgs *v13; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  Render::cbLightningGlobalSettings arg; // [rsp+48h] [rbp-28h] BYREF

  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbLightningGlobalSettings::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbLightningGlobalSettings::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLightningGlobalSettings");
    Render::cbLightningGlobalSettings::sStateParamIndex = Param;
    arg.mStateParamIndex = Param;
  }
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  arg.mSettings = (CB_LightningGlobalSettings *)v7;
  if ( v7 )
  {
    if ( this->mTaskOutputParam->numQuads )
    {
      *(float *)v7 = Render::lightningWidthScale;
      arg.mSettings->LightningConstants[1] = 1.0;
      StateArgs = Render::View::GetStateArgs(view);
      Illusion::StateArgs::Set<Render::cbLightningGlobalSettings>(StateArgs, &arg);
      v9 = Illusion::Primitive::Create("ElectricityPrimitive");
      if ( (_S6_5 & 1) == 0 )
      {
        _S6_5 |= 1u;
        UFG::qResourceHandle::qResourceHandle(&declHandle);
        atexit(declHandle::LightningManager::Render_::_9_::_dynamic_atexit_destructor_for__declHandle__);
      }
      v10 = UFG::qStringHash32("VertexDecl.Lightning", 0xFFFFFFFF);
      Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0x3E5FDA3Eu);
        `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&declHandle, 0x3E5FDA3Eu, v10, Inventory);
      Illusion::Primitive::SetBuffers(
        v9,
        TRIANGLELIST,
        this->mTaskInputParam->vertexBuffer,
        this->mTaskOutputParam->numVertices,
        (Illusion::VertexDecl *)declHandle.mData,
        this->mTaskInputParam->indexBuffer,
        this->mTaskOutputParam->numIndices,
        1);
      Render::View::Draw(view, v9, (Illusion::Material *)this->mLightningMat.mData, &UFG::qMatrix44::msIdentity);
    }
    v13 = Render::View::GetStateArgs(view);
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)v13->mStateArgs[arg.mStateParamIndex].mNode.mNext == &v13->mStateArgs[arg.mStateParamIndex] )
      v13->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  v16 = arg.mPrev;
  v17 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v17->mPrev = v16;
}

// File Line: 454
// RVA: 0x1D10D0
void __fastcall Render::LightningManager::JitterBolt(
        Render::LightningManager *this,
        LightningJoint *jointArray,
        int startIndex,
        int endIndex,
        float level,
        int numSubdivisions)
{
  LightningJoint *v8; // rbp
  LightningJoint *v9; // rdi
  UFG::qVector2 *v10; // rbx
  float v11; // xmm7_4
  float v12; // xmm0_4
  float z; // xmm1_4
  float x; // xmm3_4
  float y; // xmm5_4
  float v16; // xmm2_4
  __int64 v17; // rbp
  LightningJoint *v18; // rbx
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // ecx
  float v22; // xmm1_4
  UFG::qVector2 range; // [rsp+30h] [rbp-B8h] BYREF
  LightningJoint *i; // [rsp+38h] [rbp-B0h]
  UFG::qVector2 result; // [rsp+40h] [rbp-A8h] BYREF
  LightningJoint *jointArraya; // [rsp+F8h] [rbp+10h]

  jointArraya = jointArray;
  v8 = &jointArray[endIndex];
  for ( i = v8; ; v8 = i )
  {
    range = (UFG::qVector2)1056964608i64;
    v9 = &jointArray[startIndex];
    v10 = UFG::qRandom(&result, &range, (unsigned int *)&UFG::qDefaultSeed);
    v11 = expf(level * -0.5) * v10->x;
    v12 = UFG::qRandom(0.1, (unsigned int *)&UFG::qDefaultSeed);
    z = v8->pos.z;
    x = v8->pos.x;
    y = v9->pos.y;
    v16 = v8->pos.y;
    v17 = (startIndex + endIndex) / 2;
    v18 = &jointArraya[v17];
    v19 = v12 + 0.44999999;
    v20 = v9->pos.z + (float)((float)(z - v9->pos.z) * v19);
    v18->pos.x = v9->pos.x + (float)((float)(x - v9->pos.x) * v19);
    v18->pos.z = v20;
    v18->pos.y = y + (float)((float)(v16 - y) * v19);
    v18->jitter = v11;
    v21 = v9->right.x;
    v22 = v9->right.z;
    v18->right.y = v9->right.y;
    v18->right.x = v21;
    v18->right.z = v22;
    v18->width = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    if ( level >= (float)numSubdivisions )
      break;
    level = level + 1.0;
    Render::LightningManager::JitterBolt(this, jointArraya, startIndex, v17, level, numSubdivisions);
    jointArray = jointArraya;
    startIndex = (startIndex + endIndex) / 2;
  }
}

// File Line: 485
// RVA: 0x1CBFF0
UFG::allocator::free_link *__fastcall Render::LightningManager::GenerateJointChain(
        Render::LightningManager *this,
        unsigned int numSubdivisions)
{
  unsigned int v4; // ebx
  UFG::allocator::free_link *v5; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::allocator::free_link *v8; // rdi
  UFG::qVector3 *v9; // rax
  float x; // xmm5_4
  __m128 y_low; // xmm3
  float v12; // xmm4_4
  __m128 v13; // xmm2
  float v14; // xmm1_4
  int v15; // esi
  UFG::allocator::free_link *v16; // rbx
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm4_4
  __m128 v21; // xmm2
  float v22; // xmm3_4
  __m128 v23; // xmm5
  float v24; // xmm6_4
  UFG::qVector3 range; // [rsp+30h] [rbp-78h] BYREF
  UFG::qVector3 result; // [rsp+3Ch] [rbp-6Ch] BYREF

  v4 = (int)(float)(powf(2.0, (float)(int)(numSubdivisions - 1)) + 1.0);
  v5 = UFG::qMemoryPool::Allocate(
         this->mMemoryPool,
         32i64 * v4,
         "Lightning::GenerateJointChain::mJoints",
         0x1000ui64,
         1u);
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  range.x = 0.0;
  range.y = 1.0;
  *(float *)&v5->mNext = UFG::qVector3::msZero.x;
  *((float *)&v5->mNext + 1) = y;
  *(float *)&v5[1].mNext = z;
  v8 = v5;
  range.z = 1.0;
  v9 = UFG::qRandom(&result, &range, (unsigned int *)&UFG::qDefaultSeed);
  y_low = (__m128)LODWORD(v9->y);
  x = v9->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - 0.5;
  v12 = v9->z - 0.5;
  HIDWORD(v8[1].mNext) = LODWORD(v9->x);
  v13 = y_low;
  LODWORD(v8[2].mNext) = y_low.m128_i32[0];
  *((float *)&v8[2].mNext + 1) = v12;
  v13.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(v12 * v12);
  if ( v13.m128_f32[0] == 0.0 )
    v14 = 0.0;
  else
    v14 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
  v15 = v4 - 1;
  *((float *)&v8[1].mNext + 1) = x * v14;
  *(float *)&v8[2].mNext = y_low.m128_f32[0] * v14;
  v16 = &v8[4 * v4 - 4];
  range.x = 0.0;
  range.y = 1.0;
  *((float *)&v8[2].mNext + 1) = v12 * v14;
  v8[3].mNext = 0i64;
  range.z = 1.0;
  v17 = UFG::qVector3::msAxisX.y;
  v18 = UFG::qVector3::msAxisX.z;
  *(float *)&v16->mNext = UFG::qVector3::msAxisX.x;
  *((float *)&v16->mNext + 1) = v17;
  *(float *)&v16[1].mNext = v18;
  v19 = UFG::qRandom(&result, &range, (unsigned int *)&UFG::qDefaultSeed);
  v21 = (__m128)LODWORD(v19->y);
  v20 = v19->x;
  v21.m128_f32[0] = v21.m128_f32[0] - 0.5;
  v22 = v19->z - 0.5;
  HIDWORD(v16[1].mNext) = LODWORD(v19->x);
  v23 = v21;
  LODWORD(v16[2].mNext) = v21.m128_i32[0];
  *((float *)&v16[2].mNext + 1) = v22;
  v23.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22);
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
  *((float *)&v16[1].mNext + 1) = v20 * v24;
  *(float *)&v16[2].mNext = v21.m128_f32[0] * v24;
  *((float *)&v16[2].mNext + 1) = v22 * v24;
  v16[3].mNext = 0i64;
  Render::LightningManager::JitterBolt(this, (LightningJoint *)v8, 0, v15, 2.0, numSubdivisions);
  return v8;
}

