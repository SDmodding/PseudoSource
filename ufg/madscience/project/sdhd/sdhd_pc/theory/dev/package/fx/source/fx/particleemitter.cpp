// File Line: 91
// RVA: 0x1CF1A0
void __fastcall Render::ParticleEmitterBuffer::Init(Render::ParticleEmitterBuffer *this, unsigned int numElements)
{
  Render::ParticleRaycaster *v3; // rbp
  unsigned int v4; // ebx
  unsigned int mStringHashUpper32; // eax
  unsigned int mStringHash32; // eax
  int v7; // edi
  Illusion::Material *mParticleMaterial; // rbx
  int v9; // edi
  Illusion::Material *v10; // rbx
  unsigned int v11; // edi
  Illusion::Material *v12; // rbx
  int v13; // edi
  Illusion::Material *v14; // rbx
  Illusion::Material *v15; // rbx
  Illusion::Material *v16; // rbx
  UFG::qResourceWarehouse *v17; // rax
  UFG::allocator::free_link *v18; // rax
  Render::ParticleRaycaster *v19; // rax
  UFG::qString result; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString v21; // [rsp+60h] [rbp-38h] BYREF

  v3 = 0i64;
  this->mCount = 0;
  this->mCapacity = numElements;
  this->mSettingsId = -1;
  v4 = 84 * numElements;
  UFG::qString::FormatEx(&v21, "ParticleBuffer%p.AttributeBuffer", this);
  mStringHashUpper32 = v21.mStringHashUpper32;
  if ( v21.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(v21.mData, -1);
    v21.mStringHashUpper32 = mStringHashUpper32;
  }
  this->mAttributeBufferUID = mStringHashUpper32;
  this->mCPUAttributes = (Render::EmitterParticleAttribute *)UFG::qMalloc(
                                                               v4,
                                                               "ParticleEmitterBuffer::mCPUAttributes",
                                                               0x1000ui64);
  UFG::qString::FormatEx(&result, "ParticleSystem_%p.Material", this);
  mStringHash32 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(result.mData, 0xFFFFFFFF);
    result.mStringHash32 = mStringHash32;
  }
  this->mParticleMaterial = Illusion::Factory::NewMaterial(result.mData, mStringHash32, 6u, 0i64, 0i64, 0i64);
  v7 = UFG::qStringHash32("PARTICLE", 0xFFFFFFFF);
  mParticleMaterial = this->mParticleMaterial;
  LOWORD(mParticleMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mParticleMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mParticleMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mParticleMaterial[1].mTypeUID = -1957338719;
  LODWORD(mParticleMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v7;
  v9 = UFG::qStringHash32("TEST_SPRITE", 0xFFFFFFFF);
  v10 = this->mParticleMaterial;
  *(_WORD *)&v10[1].mDebugName[12] = 0;
  *(_DWORD *)&v10[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v10[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v10[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v10[1].mStateBlockMask.mFlags[0]) = v9;
  v11 = UFG::qStringHash32("DEFAULTNORMALMAP", 0xFFFFFFFF);
  v12 = this->mParticleMaterial;
  LOWORD(v12[1].mMaterialUser.mOffset) = 0;
  *(&v12[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v12[1].mNumParams = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
  v12[2].mNode.mUID = v11;
  v13 = UFG::qStringHash32("DEFAULTBUMPMAP", 0xFFFFFFFF);
  v14 = this->mParticleMaterial;
  LOWORD(v14[2].mTypeUID) = 0;
  HIDWORD(v14[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v14[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texReflection", 0xFFFFFFFF);
  *((_DWORD *)&v14[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v14[2].mDebugName[28] = v13;
  v15 = this->mParticleMaterial;
  LOWORD(v15[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v15[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v15[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v15[3].mNode.mChild[1]) = 315097330;
  LODWORD(v15[3].mNode.mChild[0]) = 0;
  v16 = this->mParticleMaterial;
  LOWORD(v16[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v16[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v16[3].mNode.mUID = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v16[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v16[3].mDebugName[12] = 1099738947;
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, this->mParticleMaterial);
  UFG::qString::~qString(&result);
  v18 = UFG::qMalloc(0x20ui64, "ParticleEmitterBuffer::Raycaster", 0i64);
  if ( v18 )
  {
    Render::ParticleRaycaster::ParticleRaycaster((Render::ParticleRaycaster *)v18);
    v3 = v19;
  }
  this->mRaycaster = v3;
  UFG::qString::~qString(&v21);
}

// File Line: 142
// RVA: 0x1CB4B0
void __fastcall Render::ParticleEmitterBuffer::Draw(
        Render::ParticleEmitterBuffer *this,
        Render::View *view,
        Illusion::Material *materialOverride)
{
  Illusion::Mesh *v5; // rsi
  UFG::qBaseNodeRB **mChild; // rax
  _QWORD *v7; // rcx
  char *v8; // rax
  Render::FXOverride *m_pPointer; // rdx
  char *v10; // r14
  unsigned int mFXOverrideStateParamIndex; // r12d
  Illusion::StateValues *StateValues; // rax
  char *v13; // rax
  Render::FXOverride *v14; // rdx
  char *v15; // rdi
  unsigned int v16; // esi
  Illusion::StateValues *v17; // rax
  UFG::qMatrix44 v18; // [rsp+40h] [rbp-58h] BYREF

  if ( this->mRenderAttributeBuffer )
  {
    Render::ParticleEmitterBuffer::GetRenderMatrix(this, &v18);
    v5 = 0i64;
    mChild = this->mModel.mData[2].mNode.mChild;
    if ( *mChild )
      v7 = (UFG::qBaseNodeRB **)((char *)&(*mChild)->mParent + (_QWORD)mChild);
    else
      v7 = 0i64;
    if ( *v7 )
      v5 = (Illusion::Mesh *)((char *)v7 + *v7);
    if ( this->mFXOverridePointer.m_pPointer )
    {
      v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
      m_pPointer = this->mFXOverridePointer.m_pPointer;
      v10 = v8;
      *(float *)v8 = m_pPointer->stateBlock.ColorTint[0];
      *((_DWORD *)v8 + 1) = LODWORD(m_pPointer->stateBlock.ColorTint[1]);
      *((_DWORD *)v8 + 2) = LODWORD(m_pPointer->stateBlock.ColorTint[2]);
      *((_DWORD *)v8 + 3) = LODWORD(m_pPointer->stateBlock.ColorTint[3]);
      *((_DWORD *)v8 + 4) = LODWORD(m_pPointer->stateBlock.Params1[0]);
      *((_DWORD *)v8 + 5) = LODWORD(m_pPointer->stateBlock.Params1[1]);
      *((_DWORD *)v8 + 6) = LODWORD(m_pPointer->stateBlock.Params1[2]);
      *((_DWORD *)v8 + 7) = LODWORD(m_pPointer->stateBlock.Params1[3]);
      mFXOverrideStateParamIndex = Render::gFXManager.mFXOverrideStateParamIndex;
      StateValues = Render::View::GetStateValues(view);
      if ( mFXOverrideStateParamIndex >= 0x40 )
        StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mFXOverrideStateParamIndex - 64);
      else
        StateValues->mSetValueMask.mFlags[0] |= 1i64 << mFXOverrideStateParamIndex;
      StateValues->mParamValues[(__int16)mFXOverrideStateParamIndex] = v10;
    }
    Render::View::DrawInstanced(view, v5, this->mRenderAttributeBuffer, this->mCount);
    if ( this->mFXOverridePointer.m_pPointer )
    {
      v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
      v14 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer;
      v15 = v13;
      *(float *)v13 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer->stateBlock.ColorTint[0];
      *((_DWORD *)v13 + 1) = LODWORD(v14->stateBlock.ColorTint[1]);
      *((_DWORD *)v13 + 2) = LODWORD(v14->stateBlock.ColorTint[2]);
      *((_DWORD *)v13 + 3) = LODWORD(v14->stateBlock.ColorTint[3]);
      *((_DWORD *)v13 + 4) = LODWORD(v14->stateBlock.Params1[0]);
      *((_DWORD *)v13 + 5) = LODWORD(v14->stateBlock.Params1[1]);
      *((_DWORD *)v13 + 6) = LODWORD(v14->stateBlock.Params1[2]);
      *((_DWORD *)v13 + 7) = LODWORD(v14->stateBlock.Params1[3]);
      v16 = Render::gFXManager.mFXOverrideStateParamIndex;
      v17 = Render::View::GetStateValues(view);
      if ( v16 >= 0x40 )
        v17->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v16 - 64);
      else
        v17->mSetValueMask.mFlags[0] |= 1i64 << v16;
      v17->mParamValues[(__int16)v16] = v15;
    }
  }
}

// File Line: 168
// RVA: 0x1CBDF0
Illusion::Buffer *__fastcall Render::ParticleEmitterBuffer::FrameMallocAttributeBuffer(
        Render::ParticleEmitterBuffer *this)
{
  char *v2; // rdi
  Illusion::Buffer *v4; // rax

  v2 = UFG::qLinearAllocator::Malloc(
         Illusion::gEngine.FrameWriteMemory,
         (84 * this->mCapacity + 127) & 0xFFFFFF7F,
         0x10u);
  if ( !v2 )
    return 0i64;
  v4 = Illusion::Factory::NewBuffer(
         "ParticleBuffer.AttributeBuffer",
         this->mAttributeBufferUID,
         0,
         0i64,
         "ParticleBuffer::AttributeBuffer",
         Illusion::gEngine.FrameMemory,
         0i64);
  this->mRenderAttributeBuffer = v4;
  if ( !v4 )
    return 0i64;
  v4->mData.mOffset = v2 - (char *)&v4->mData;
  this->mRenderAttributeBuffer->mDataByteSize = 84 * this->mCapacity;
  this->mRenderAttributeBuffer->mBufferType = 2;
  this->mRenderAttributeBuffer->mElementByteSize = 84;
  this->mRenderAttributeBuffer->mNumElements = this->mCapacity;
  this->mRenderAttributeBuffer->mFlags |= 4u;
  return this->mRenderAttributeBuffer;
}

// File Line: 260
// RVA: 0x1CAB90
void __fastcall Render::ParticleEmitterBuffer::Deactivate(Render::ParticleEmitterBuffer *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *mParent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  Render::ParticleEmitterInstance *mOwner; // rax
  Render::ParticleEmitterBuffer *mCurrentBuffer; // rcx
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v10; // rdi
  char *mTriangleInfo; // rdx

  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mModelToEmitFrom, Inventory);
  mParent = this->mParent;
  if ( mParent->m_pPointer )
  {
    mPrev = mParent->mPrev;
    mNext = mParent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mParent->mPrev = mParent;
    mParent->mNext = mParent;
  }
  mParent->m_pPointer = 0i64;
  mOwner = this->mOwner;
  if ( mOwner )
  {
    mCurrentBuffer = mOwner->mCurrentBuffer;
    if ( mCurrentBuffer )
    {
      mCurrentBuffer->mOwner = 0i64;
      mOwner->mCurrentBuffer = 0i64;
    }
    this->mOwner = 0i64;
  }
  m_pPointer = this->mFXOverridePointer.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v10 = this->mFXOverridePointer.m_pPointer;
    if ( v10->mReferenceCount <= 0 )
    {
      if ( v10 )
      {
        mTriangleInfo = (char *)v10->mTriangleInfo;
        if ( mTriangleInfo )
          UFG::qMemoryPool::Free(v10->mMemoryPool, mTriangleInfo);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v10);
      }
      this->mFXOverridePointer.m_pPointer = 0i64;
    }
    this->mFXOverridePointer.m_pPointer = 0i64;
  }
}

// File Line: 307
// RVA: 0x1C5DE0
void __fastcall Render::ParticleEmitterBuffer::Activate(
        Render::ParticleEmitterBuffer *this,
        float in_creationTime,
        Render::ParticleEmitterInstance *owner,
        Render::ParticleEmitterSettings *pfx,
        Render::FXInstance *container,
        UFG::qMatrix44 *prevBasis)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *mParent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  unsigned int mModelToEmitFromUID; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v14; // rax
  Render::FXOverride *m_pPointer; // rax
  unsigned int modelToEmitFromUID; // esi
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceInventory *v19; // rax
  unsigned int mNameUID; // esi
  UFG::qResourceWarehouse *v21; // rax
  Illusion::Material *mParticleMaterial; // rsi
  unsigned int mShaderID; // r8d
  __int64 mOffset; // rax
  _WORD *v25; // rax
  Illusion::Material *v26; // rsi
  unsigned int mTextureID; // r8d
  __int64 v28; // rax
  _WORD *v29; // rax
  Illusion::Material *v30; // rsi
  unsigned int mNormalTextureID; // r8d
  __int64 v32; // rax
  _WORD *v33; // rax
  Illusion::Material *v34; // rsi
  unsigned int mReflectionMapTextureID; // r8d
  __int64 v36; // rax
  _WORD *v37; // rax
  Illusion::Material *v38; // rsi
  int v39; // ecx
  unsigned int v40; // r8d
  int v41; // eax
  bool v42; // zf
  __int64 v43; // rax
  _WORD *v44; // rax
  Illusion::Material *v45; // rsi
  unsigned int v46; // r8d
  __int64 v47; // rax
  _WORD *v48; // rax
  UFG::SimComponent *v49; // rsi
  UFG::qMatrix44 *p_mBasis; // rsi
  UFG::qVector4 v51; // xmm3
  UFG::qVector4 v52; // xmm2
  UFG::qVector4 v53; // xmm1
  UFG::qVector4 v54; // xmm0
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v55; // rdx
  UFG::SimComponent *v56; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v57; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v58; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v59; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qResourceInventory *v62; // rax
  unsigned int mUID; // esi
  UFG::qResourceWarehouse *v64; // rax
  bool v65; // bl
  Render::ParticleRaycaster *mRaycaster; // rax
  float v67; // xmm1_4
  float v68; // xmm2_4
  UFG::qMatrix44 out_mat; // [rsp+20h] [rbp-68h] BYREF

  FX::SharedPointer<Render::FXOverride>::Set(&this->mFXOverridePointer, container->mStateBlockOverride.m_pPointer);
  this->mExpiry = 0.0;
  *(_QWORD *)&this->mCreationTime = LODWORD(in_creationTime);
  this->mSplitScreenViewMask = owner->mContainer->mSplitScreenViewMask;
  mParent = this->mParent;
  if ( mParent->m_pPointer )
  {
    mPrev = mParent->mPrev;
    mNext = mParent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mParent->mPrev = mParent;
    mParent->mNext = mParent;
  }
  mParent->m_pPointer = 0i64;
  UFG::qMemSet(this->mTaskInfo.inputParam, 0, 0x270u);
  UFG::qMemSet(this->mTaskInfo.outputParam, 0, 8u);
  this->mTaskInfo.instance = 0i64;
  this->mTaskInfo.task = 0i64;
  this->mOwner = owner;
  this->mDescription = pfx->mDebugName;
  mModelToEmitFromUID = pfx->mModelToEmitFromUID;
  if ( mModelToEmitFromUID )
  {
    Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v14 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v14, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mModelToEmitFrom, 0xA2ADCD77, mModelToEmitFromUID, Inventory);
  }
  m_pPointer = this->mFXOverridePointer.m_pPointer;
  if ( m_pPointer )
  {
    modelToEmitFromUID = m_pPointer->modelToEmitFromUID;
    if ( modelToEmitFromUID != -1 )
    {
      v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v18 = UFG::qResourceWarehouse::Instance();
        v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
      }
      UFG::qResourceHandle::Init(&this->mModelToEmitFrom, 0xA2ADCD77, modelToEmitFromUID, v17);
    }
  }
  v19 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  mNameUID = pfx->mModel.mNameUID;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v21 = UFG::qResourceWarehouse::Instance();
    v19 = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v19;
  }
  UFG::qResourceHandle::Init(&this->mModel, 0xA2ADCD77, mNameUID, v19);
  if ( pfx->mType != 2 )
  {
    mParticleMaterial = this->mParticleMaterial;
    mShaderID = pfx->mShaderID;
    if ( LODWORD(mParticleMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != mShaderID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mParticleMaterial[1].mNode.mChild[1],
        mParticleMaterial[1].mTypeUID,
        mShaderID);
      mOffset = mParticleMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v25 = (_WORD *)((char *)&mParticleMaterial->mMaterialUser + mOffset);
      else
        v25 = 0i64;
      *v25 |= 0x20u;
    }
    v26 = this->mParticleMaterial;
    mTextureID = pfx->mTextureID;
    if ( LODWORD(v26[1].mStateBlockMask.mFlags[0]) != mTextureID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v26[1].mDebugName[20],
        v26[1].mStateBlockMask.mFlags[1],
        mTextureID);
      v28 = v26->mMaterialUser.mOffset;
      if ( v28 )
        v29 = (_WORD *)((char *)&v26->mMaterialUser + v28);
      else
        v29 = 0i64;
      *v29 |= 0x20u;
    }
    v30 = this->mParticleMaterial;
    mNormalTextureID = pfx->mNormalTextureID;
    if ( v30[2].mNode.mUID != mNormalTextureID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v30[2],
        (unsigned int)v30[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
        mNormalTextureID);
      v32 = v30->mMaterialUser.mOffset;
      if ( v32 )
        v33 = (_WORD *)((char *)&v30->mMaterialUser + v32);
      else
        v33 = 0i64;
      *v33 |= 0x20u;
    }
    v34 = this->mParticleMaterial;
    mReflectionMapTextureID = pfx->mReflectionMapTextureID;
    if ( *(_DWORD *)&v34[2].mDebugName[28] != mReflectionMapTextureID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v34[2].mDebugName[4],
        *((_DWORD *)&v34[2].UFG::qResourceData + 22),
        mReflectionMapTextureID);
      v36 = v34->mMaterialUser.mOffset;
      if ( v36 )
        v37 = (_WORD *)((char *)&v34->mMaterialUser + v36);
      else
        v37 = 0i64;
      *v37 |= 0x20u;
    }
    v38 = this->mParticleMaterial;
    v39 = *(_DWORD *)(*((_QWORD *)&v38[1].UFG::qResourceData + 11) + 108i64);
    if ( pfx->mDrawType == 1 )
    {
      v40 = -2074035010;
      if ( !v39 )
      {
LABEL_41:
        if ( LODWORD(v38[3].mNode.mChild[0]) != v40 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v38[2].mNumParams,
            (unsigned int)v38[3].mNode.mChild[1],
            v40);
          v43 = v38->mMaterialUser.mOffset;
          if ( v43 )
            v44 = (_WORD *)((char *)&v38->mMaterialUser + v43);
          else
            v44 = 0i64;
          *v44 |= 0x20u;
        }
        v45 = this->mParticleMaterial;
        v46 = 1099738947;
        if ( !pfx->mDrawType )
          v46 = -1810908948;
        if ( *(_DWORD *)&v45[3].mDebugName[12] != v46 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v45[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
            *(_DWORD *)&v45[3].mDebugName[20],
            v46);
          v47 = v45->mMaterialUser.mOffset;
          if ( v47 )
            v48 = (_WORD *)((char *)&v45->mMaterialUser + v47);
          else
            v48 = 0i64;
          *v48 |= 0x20u;
        }
        goto LABEL_53;
      }
      v41 = -630453795;
      v42 = v39 == 1775952593;
    }
    else
    {
      v40 = *(_DWORD *)(*((_QWORD *)&v38[1].UFG::qResourceData + 11) + 108i64);
      v41 = -1551679522;
      v42 = v39 == 0;
    }
    if ( v42 )
      v40 = v41;
    goto LABEL_41;
  }
LABEL_53:
  v49 = container->mParentNode.m_pPointer;
  if ( !v49 || container->mBasisRelativeToParent )
  {
    p_mBasis = &container->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)container->mParentNode.m_pPointer);
    p_mBasis = (UFG::qMatrix44 *)&v49[2];
  }
  if ( pfx->mSpace == 1 )
  {
    this->mCalcBasis = Render::FXInstance::CalcBasisHelper;
    v51 = prevBasis->v1;
    v52 = prevBasis->v2;
    v53 = prevBasis->v3;
    v54 = prevBasis->v0;
  }
  else
  {
    this->mCalcBasis = 0i64;
    v51 = p_mBasis->v1;
    v52 = p_mBasis->v2;
    v53 = p_mBasis->v3;
    v54 = p_mBasis->v0;
  }
  this->mLastKnownGoodBasis.v0 = v54;
  this->mLastKnownGoodBasis.v1 = v51;
  this->mLastKnownGoodBasis.v2 = v52;
  this->mLastKnownGoodBasis.v3 = v53;
  v55 = this->mParent;
  this->mStartTime = owner->mStartTime;
  v56 = container->mParentNode.m_pPointer;
  if ( v55->m_pPointer )
  {
    v57 = v55->mPrev;
    v58 = v55->mNext;
    v57->mNext = v58;
    v58->mPrev = v57;
    v55->mPrev = v55;
    v55->mNext = v55;
  }
  v55->m_pPointer = v56;
  if ( v56 )
  {
    v59 = v56->m_SafePointerList.mNode.mPrev;
    v59->mNext = v55;
    v55->mPrev = v59;
    v55->mNext = &v56->m_SafePointerList.mNode;
    v56->m_SafePointerList.mNode.mPrev = v55;
  }
  this->mComponentIndex = owner->mComponentIndex;
  UFG::qResourceHandle::Init(&this->mContainerHandle, 0xED341A8D, container->mSettings.mNameUID);
  this->mSettingsId = pfx->mNode.mUID;
  this->mParentFXId = container->mId;
  y = p_mBasis->v3.y;
  z = p_mBasis->v3.z;
  this->mLastKnownEffectPos.x = p_mBasis->v3.x;
  this->mLastKnownEffectPos.y = y;
  this->mLastKnownEffectPos.z = z;
  v62 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
  mUID = pfx->mNode.mUID;
  if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
  {
    v64 = UFG::qResourceWarehouse::Instance();
    v62 = UFG::qResourceWarehouse::GetInventory(v64, 0x3BEE21DCu);
    `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = v62;
  }
  UFG::qResourceHandle::Init(&this->mCreatorSettings, 0x3BEE21DCu, mUID, v62);
  if ( pfx->mPhysicsType == 1203368722 )
  {
    v65 = (pfx->mBitFields[0] & 4) != 0;
    Render::ParticleEmitterBuffer::GetRenderMatrix(this, &out_mat);
    mRaycaster = this->mRaycaster;
    v67 = out_mat.v3.y;
    v68 = out_mat.v3.z;
    mRaycaster->mPosition.x = out_mat.v3.x;
    mRaycaster->mPosition.y = v67;
    mRaycaster->mPosition.z = v68;
    this->mRaycaster->mMode = 3 - v65;
  }
}

// File Line: 414
// RVA: 0x1C1EC0
void __fastcall Render::ParticleEmitterBuffer::TaskInfo::TaskInfo(Render::ParticleEmitterBuffer::TaskInfo *this)
{
  UFG::allocator::free_link *v2; // rax
  Render::ParticleRenderUpdateTaskParam *inputParam; // rcx

  this->inputParam = (Render::ParticleRenderUpdateTaskParam *)UFG::qMalloc(
                                                                0x270ui64,
                                                                "ParticleEmitterBuffer::ParticleRenderUpdateTaskParam",
                                                                0x1000ui64);
  v2 = UFG::qMalloc(8ui64, "ParticleEmitterBuffer::ParticleRenderUpdateTaskOutputParam", 0x1000ui64);
  inputParam = this->inputParam;
  this->outputParam = (Render::ParticleRenderUpdateTaskOutputParam *)v2;
  UFG::qMemSet(inputParam, 0, 0x270u);
  UFG::qMemSet(this->outputParam, 0, 8u);
  this->instance = 0i64;
  this->task = 0i64;
}

// File Line: 428
// RVA: 0x1C4840
void __fastcall Render::ParticleEmitterBuffer::TaskInfo::~TaskInfo(Render::ParticleEmitterBuffer::TaskInfo *this)
{
  operator delete[](this->inputParam);
  operator delete[](this->outputParam);
}

// File Line: 436
// RVA: 0x1D75C0
void __fastcall Render::ParticleEmitterBuffer::TaskInfo::Start(
        Render::ParticleEmitterBuffer::TaskInfo *this,
        Render::ParticleEmitterSettings *pfx,
        Render::ParticleEmitterBuffer *buffer,
        void *frameMemoryInstanceBuffer,
        UFG::qVector3 *cameraPos,
        float simTime,
        float deltaTime,
        Render::FXManagerLights *lightList)
{
  Render::ParticleEmitterInstance *mOwner; // rcx
  Render::ParticleRenderUpdateTaskParam *inputParam; // rax
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  Render::ParticleEmitterInstance *v17; // rax
  Render::ParticleRenderUpdateTaskParam *v18; // rcx
  UFG::qVector4 v19; // xmm2
  UFG::qVector4 v20; // xmm1
  UFG::qVector4 v21; // xmm0
  UFG::TransformNodeComponent *m_pPointer; // rsi
  Render::ParticleRenderUpdateTaskParam *v23; // rax
  UFG::qVector4 v24; // xmm2
  UFG::qVector4 v25; // xmm1
  UFG::qVector4 v26; // xmm0
  UFG::qVector4 v27; // xmm2
  UFG::qVector4 v28; // xmm1
  UFG::qVector4 v29; // xmm0
  Render::ParticleRenderUpdateTaskParam *v30; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  Render::ParticleRenderUpdateTaskOutputParam *outputParam; // rbx
  Render::ParticleRenderUpdateTaskParam *v34; // rsi
  char *v35; // rax
  UFG::qTask *v36; // rdx
  _QWORD *v37; // rax
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rax

  Render::ParticleEmitterBuffer::GetRenderMatrix(buffer, &this->inputParam->renderMatrix);
  mOwner = buffer->mOwner;
  if ( mOwner )
  {
    inputParam = this->inputParam;
    v14 = mOwner->mCurrentBasis.v1;
    v15 = mOwner->mCurrentBasis.v2;
    v16 = mOwner->mCurrentBasis.v3;
    inputParam->curBasis.v0 = mOwner->mCurrentBasis.v0;
    inputParam->curBasis.v1 = v14;
    inputParam->curBasis.v2 = v15;
    inputParam->curBasis.v3 = v16;
    v17 = buffer->mOwner;
    v18 = this->inputParam;
    v19 = v17->mPrevBasis.v1;
    v20 = v17->mPrevBasis.v2;
    v21 = v17->mPrevBasis.v3;
    v18->oldBasis.v0 = v17->mPrevBasis.v0;
    v18->oldBasis.v1 = v19;
    v18->oldBasis.v2 = v20;
    v18->oldBasis.v3 = v21;
  }
  else
  {
    m_pPointer = (UFG::TransformNodeComponent *)buffer->mParent->m_pPointer;
    v23 = this->inputParam;
    if ( m_pPointer )
    {
      v24 = v23->curBasis.v1;
      v25 = v23->curBasis.v2;
      v26 = v23->curBasis.v3;
      v23->oldBasis.v0 = v23->curBasis.v0;
      v23->oldBasis.v1 = v24;
      v23->oldBasis.v2 = v25;
      v23->oldBasis.v3 = v26;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer);
      Render::FXInstance::CalcBasisHelper(
        &this->inputParam->curBasis,
        &m_pPointer->mWorldTransform,
        &buffer->mContainerHandle,
        buffer->mComponentIndex,
        buffer->mCreationTime);
    }
    else
    {
      v27 = buffer->mLastKnownGoodBasis.v1;
      v28 = buffer->mLastKnownGoodBasis.v2;
      v29 = buffer->mLastKnownGoodBasis.v3;
      v23->curBasis.v0 = buffer->mLastKnownGoodBasis.v0;
      v23->curBasis.v1 = v27;
      v23->curBasis.v2 = v28;
      v23->curBasis.v3 = v29;
    }
  }
  this->inputParam->simTime = simTime;
  this->inputParam->deltaTime = deltaTime;
  this->inputParam->seed = UFG::qDefaultSeed;
  UFG::qDefaultSeed ^= 0x1D872B41 ^ UFG::qDefaultSeed ^ 0x1D872B41 ^ ((UFG::qDefaultSeed ^ 0x1D872B41u) >> 5) ^ ((UFG::qDefaultSeed ^ 0x1D872B41 ^ ((UFG::qDefaultSeed ^ 0x1D872B41u) >> 5)) << 27);
  this->inputParam->pSettings = pfx;
  this->inputParam->numParticlesInBuffer = buffer->mCount;
  this->inputParam->cpuAttributeBuffer = buffer->mCPUAttributes;
  this->inputParam->renderAttributeBuffer = frameMemoryInstanceBuffer;
  v30 = this->inputParam;
  y = cameraPos->y;
  z = cameraPos->z;
  v30->cameraPos.x = cameraPos->x;
  v30->cameraPos.y = y;
  v30->cameraPos.z = z;
  v30->bufferCapacity = buffer->mCapacity;
  this->inputParam->lastExpiry = buffer->mExpiry;
  *(Render::FXForceManager *)&this->inputParam->forceList = Render::gFXForceManager;
  this->inputParam->numBouncePlanes = Render::ParticleRaycaster::GetHitPlanes(
                                        buffer->mRaycaster,
                                        0xAu,
                                        this->inputParam->bouncePlaneList);
  this->inputParam->modelToEmitFrom = buffer->mModelToEmitFrom.mData;
  this->inputParam->fxOverride = buffer->mFXOverridePointer.m_pPointer;
  this->inputParam->lights = *lightList;
  outputParam = this->outputParam;
  v34 = this->inputParam;
  v35 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v36 = (UFG::qTask *)v35;
  if ( v35 )
  {
    *(_QWORD *)v35 = v35;
    *((_QWORD *)v35 + 1) = v35;
    v37 = v35 + 16;
    *v37 = v37;
    v37[1] = v37;
    mSpuElf = Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mSpuElf;
    mTaskFunctionSPU = Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mTaskFunctionSPU;
    mTaskFunctionPPU = Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mTaskFunctionPPU;
    mTaskFunctionOffload = Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mTaskFunctionOffload;
    if ( !Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mCurrentSPUEnabled )
    {
      mSpuElf = 0i64;
      mTaskFunctionSPU = 0i64;
      mTaskFunctionOffload = 0i64;
    }
    v36->mTaskGroup = 0i64;
    v36->mFlags = 2;
    v36->mSyncVars.i64 = 0i64;
    v36->mSyncVars.v.mDependents = 0i64;
    v36->mFunctionDeclData = &Render::gTaskFunctionDeclData_ParticleRenderUpdateTask;
    if ( mSpuElf )
      mAddress = mSpuElf->mAddress;
    else
      mAddress = 0i64;
    v36->mSPUElfAddress = mAddress;
    v36->mSPUFunction = mTaskFunctionSPU;
    v36->mPPUFunction = mTaskFunctionPPU;
    v36->mParam0 = v34;
    v36->mParam1 = outputParam;
    v36->mParam2 = 0i64;
    v36->mParam3 = 0i64;
    if ( mTaskFunctionOffload )
    {
      v36->mFlags = 130;
      v36->mOffloadThread = 0;
    }
  }
  mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
  mPrev = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  mPrev->mNext = v36;
  v36->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = mPrev;
  v36->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
  mSingleFrameTasks->mNode.mPrev = v36;
  this->task = v36;
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v36);
}

// File Line: 554
// RVA: 0x1CCE30
void __fastcall Render::ParticleEmitterBuffer::GetRenderMatrix(
        Render::ParticleEmitterBuffer *this,
        UFG::qMatrix44 *out_mat)
{
  UFG::qVector4 v2; // xmm1
  UFG::qVector4 v3; // xmm2
  UFG::qVector4 v6; // xmm3
  void (__fastcall *mCalcBasis)(UFG::qMatrix44 *, UFG::qMatrix44 *, UFG::qResourceHandle *, unsigned int, float); // r10
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *mParent; // rax
  UFG::SimComponent *m_pPointer; // rdi

  v2 = UFG::qMatrix44::msIdentity.v1;
  v3 = UFG::qMatrix44::msIdentity.v2;
  v6 = UFG::qMatrix44::msIdentity.v3;
  out_mat->v0 = UFG::qMatrix44::msIdentity.v0;
  out_mat->v1 = v2;
  out_mat->v2 = v3;
  out_mat->v3 = v6;
  mCalcBasis = this->mCalcBasis;
  if ( mCalcBasis )
  {
    mParent = this->mParent;
    m_pPointer = mParent->m_pPointer;
    if ( m_pPointer )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mParent->m_pPointer);
      ((void (__fastcall *)(UFG::qMatrix44 *, UFG::SimComponent *, UFG::qResourceHandle *, _QWORD, _DWORD))this->mCalcBasis)(
        out_mat,
        &m_pPointer[2],
        &this->mContainerHandle,
        this->mComponentIndex,
        LODWORD(this->mStartTime));
    }
    else
    {
      ((void (__fastcall *)(UFG::qMatrix44 *, UFG::qMatrix44 *, UFG::qResourceHandle *, _QWORD, _DWORD))mCalcBasis)(
        out_mat,
        &this->mLastKnownGoodBasis,
        &this->mContainerHandle,
        this->mComponentIndex,
        LODWORD(this->mStartTime));
    }
  }
}

// File Line: 607
// RVA: 0x1C1A50
void __fastcall Render::ParticleEmitterBuffer::ParticleEmitterBuffer(Render::ParticleEmitterBuffer *this)
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
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v16; // rax

  Render::ParticleEmitterBuffer::TaskInfo::TaskInfo(&this->mTaskInfo);
  *(_QWORD *)&this->mExpiry = 0i64;
  *(_QWORD *)&this->mCount = 0i64;
  this->mParticleMaterial = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mCreatorSettings);
  UFG::qResourceHandle::qResourceHandle(&this->mModel);
  this->mDescription = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mContainerHandle);
  this->mComponentIndex = -1;
  this->mStartTime = 0.0;
  this->mCalcBasis = 0i64;
  y = UFG::qMatrix44::msIdentity.v0.y;
  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  this->mLastKnownGoodBasis.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->mLastKnownGoodBasis.v0.y = y;
  this->mLastKnownGoodBasis.v0.z = z;
  this->mLastKnownGoodBasis.v0.w = w;
  v5 = UFG::qMatrix44::msIdentity.v1.y;
  v6 = UFG::qMatrix44::msIdentity.v1.z;
  v7 = UFG::qMatrix44::msIdentity.v1.w;
  this->mLastKnownGoodBasis.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mLastKnownGoodBasis.v1.y = v5;
  this->mLastKnownGoodBasis.v1.z = v6;
  this->mLastKnownGoodBasis.v1.w = v7;
  v8 = UFG::qMatrix44::msIdentity.v2.y;
  v9 = UFG::qMatrix44::msIdentity.v2.z;
  v10 = UFG::qMatrix44::msIdentity.v2.w;
  this->mLastKnownGoodBasis.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->mLastKnownGoodBasis.v2.y = v8;
  this->mLastKnownGoodBasis.v2.z = v9;
  this->mLastKnownGoodBasis.v2.w = v10;
  v11 = UFG::qMatrix44::msIdentity.v3.y;
  v12 = UFG::qMatrix44::msIdentity.v3.z;
  v13 = UFG::qMatrix44::msIdentity.v3.w;
  this->mLastKnownGoodBasis.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->mLastKnownGoodBasis.v3.y = v11;
  this->mLastKnownGoodBasis.v3.z = v12;
  this->mLastKnownGoodBasis.v3.w = v13;
  v14 = UFG::qVector3::msZero.y;
  v15 = UFG::qVector3::msZero.z;
  this->mLastKnownEffectPos.x = UFG::qVector3::msZero.x;
  this->mLastKnownEffectPos.y = v14;
  this->mLastKnownEffectPos.z = v15;
  *(_QWORD *)&this->mParentFXId = -1i64;
  this->mRenderAttributeBuffer = 0i64;
  this->mRaycaster = 0i64;
  this->mOwner = 0i64;
  this->mCPUAttributes = 0i64;
  this->mFXOverridePointer.m_pPointer = 0i64;
  this->mSplitScreenViewMask = -1;
  UFG::qResourceHandle::qResourceHandle(&this->mModelToEmitFrom);
  v16 = (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)UFG::qMalloc(
                                                                              0x18ui64,
                                                                              "ParticleEmitterBuffer::Parent",
                                                                              0i64);
  if ( v16 )
  {
    v16->mPrev = v16;
    v16->mNext = v16;
    v16->m_pPointer = 0i64;
  }
  else
  {
    v16 = 0i64;
  }
  this->mParent = v16;
}

// File Line: 615
// RVA: 0x1C42E0
void __fastcall Render::ParticleEmitterBuffer::~ParticleEmitterBuffer(Render::ParticleEmitterBuffer *this)
{
  Illusion::Material *mParticleMaterial; // rdi
  UFG::qResourceWarehouse *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *mParent; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  Render::ParticleRaycaster *mRaycaster; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v13; // rdi
  char *mTriangleInfo; // rdx
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax

  operator delete[](this->mCPUAttributes);
  mParticleMaterial = this->mParticleMaterial;
  if ( mParticleMaterial )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v3, mParticleMaterial);
    UFG::LibCurlFree(this->mParticleMaterial);
  }
  mParent = this->mParent;
  if ( mParent )
  {
    if ( mParent->m_pPointer )
    {
      mPrev = mParent->mPrev;
      mNext = mParent->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      mParent->mPrev = mParent;
      mParent->mNext = mParent;
    }
    mParent->m_pPointer = 0i64;
    v7 = mParent->mPrev;
    v8 = mParent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    mParent->mPrev = mParent;
    mParent->mNext = mParent;
    operator delete[](mParent);
  }
  mRaycaster = this->mRaycaster;
  if ( mRaycaster )
  {
    operator delete[](mRaycaster->mRaycastResultList);
    operator delete[](mRaycaster);
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mModelToEmitFrom, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mModelToEmitFrom);
  m_pPointer = this->mFXOverridePointer.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v13 = this->mFXOverridePointer.m_pPointer;
    if ( v13->mReferenceCount <= 0 )
    {
      if ( v13 )
      {
        mTriangleInfo = (char *)v13->mTriangleInfo;
        if ( mTriangleInfo )
          UFG::qMemoryPool::Free(v13->mMemoryPool, mTriangleInfo);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v13);
      }
      this->mFXOverridePointer.m_pPointer = 0i64;
    }
  }
  UFG::qResourceHandle::~qResourceHandle(&this->mContainerHandle);
  v15 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v15;
  }
  UFG::qResourceHandle::Close(&this->mModel, v15);
  UFG::qResourceHandle::~qResourceHandle(&this->mModel);
  v17 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
  {
    v18 = UFG::qResourceWarehouse::Instance();
    v17 = UFG::qResourceWarehouse::GetInventory(v18, 0x3BEE21DCu);
    `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = v17;
  }
  UFG::qResourceHandle::Close(&this->mCreatorSettings, v17);
  UFG::qResourceHandle::~qResourceHandle(&this->mCreatorSettings);
  operator delete[](this->mTaskInfo.inputParam);
  operator delete[](this->mTaskInfo.outputParam);
}
  operator

// File Line: 635
// RVA: 0x146B750
__int64 Render::_dynamic_initializer_for__gParticleEmitterManager__()
{
  Render::gParticleEmitterManager.freeBuffersSmall.p = 0i64;
  *(_QWORD *)&Render::gParticleEmitterManager.freeBuffersSmall.size = 0i64;
  `eh vector constructor iterator(
    (char *)Render::gParticleEmitterManager.activeBuffers,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  *(_QWORD *)&Render::gParticleEmitterManager.mNumActiveTasks = 0i64;
  Render::gParticleEmitterManager.mDebugMeshEmitterNormalLength = 0.0;
  Render::gParticleEmitterManager.mIsParticleBufferDebugDrawsEnabled = 0;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gParticleEmitterManager__);
}

// File Line: 661
// RVA: 0x1D09E0
void __fastcall Render::ParticleEmitterManager::InitTrailModel(
        Render::ParticleEmitterManager *this,
        unsigned int num_instances)
{
  unsigned int v3; // edi
  int v4; // ebx
  UFG::qResourceData *v5; // r15
  UFG::qBaseNodeRB *v6; // rax
  _QWORD *v7; // rcx
  char *v8; // rsi
  unsigned int mStringHash32; // r14d
  Illusion::Buffer *v10; // rbp
  __int64 mOffset; // rax
  char *v12; // rcx
  char *v13; // rax
  float v14; // xmm2_4
  float v15; // xmm1_4
  UFG::qResourceWarehouse *v16; // rax
  unsigned int v17; // r14d
  int v18; // r13d
  Illusion::Buffer *v19; // rbp
  unsigned int v20; // r11d
  __int64 v21; // rax
  char *v22; // rbx
  UFG::qResourceWarehouse *v23; // rax
  UFG::qResourceWarehouse *v24; // rax
  UFG::qString v25; // [rsp+48h] [rbp-50h] BYREF

  v3 = 0;
  v4 = 1;
  v5 = Illusion::Factory::NewModel("ParticleManager.TrailModel", 0x62AD0667u, 1u, 0i64, 0i64, 0i64);
  v6 = v5[2].mNode.mChild[0];
  if ( v6 )
    v7 = (UFG::qBaseNodeRB **)((char *)&v6[5].mChild[2] + (_QWORD)v5);
  else
    v7 = 0i64;
  v8 = (char *)v7 + *v7;
  if ( !*v7 )
    v8 = 0i64;
  *((_DWORD *)v8 + 57) = 0;
  *((_DWORD *)v8 + 58) = 14;
  *((_DWORD *)v8 + 56) = 3;
  UFG::qString::qString(&v25, "ParticleManager.Trail.VertexBuffer");
  mStringHash32 = v25.mStringHash32;
  if ( v25.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(v25.mData, 0xFFFFFFFF);
    v25.mStringHash32 = mStringHash32;
  }
  v10 = Illusion::Factory::NewBuffer(v25.mData, mStringHash32, 0x100u, 0i64, "Particle.Trail.VertexBuffer", 0i64, 0i64);
  v10->mBufferType = 0;
  v10->mElementByteSize = 16;
  v10->mNumElements = 16;
  mOffset = v10->mData.mOffset;
  if ( mOffset )
    v12 = (char *)&v10->mData + mOffset;
  else
    v12 = 0i64;
  *(_DWORD *)v12 = 0;
  *((_DWORD *)v12 + 1) = -1090519040;
  *((_DWORD *)v12 + 2) = 1056964608;
  *((_DWORD *)v12 + 3) = 1065353216;
  v13 = v12 + 40;
  do
  {
    v14 = (float)((float)v4 * 0.071428575) - 0.5;
    *((_DWORD *)v13 - 6) = -1090519040;
    *((float *)v13 - 5) = v14;
    *((_DWORD *)v13 - 4) = 0;
    v15 = 1.0 - (float)(v14 + 0.5);
    *((float *)v13 - 3) = v15;
    *((_DWORD *)v13 - 2) = 1056964608;
    *((float *)v13 - 1) = v14;
    *(_DWORD *)v13 = 1065353216;
    *((float *)v13 + 1) = v15;
    v4 += 2;
    v13 += 32;
  }
  while ( v4 < 14 );
  *((_DWORD *)v12 + 60) = 0;
  *((_DWORD *)v12 + 61) = 1056964608;
  *((_QWORD *)v12 + 31) = 1056964608i64;
  v16 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v16, &v10->UFG::qResourceData);
  *((_QWORD *)v8 + 30) = "ParticleManager.TrailModel";
  *((_DWORD *)v8 + 30) = mStringHash32;
  *((_DWORD *)v8 + 14) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gParticleDescriptor);
  UFG::qString::~qString(&v25);
  UFG::qString::qString(&v25, "ParticleManager.Trail.IndexBuffer");
  v17 = v25.mStringHash32;
  if ( v25.mStringHash32 == -1 )
  {
    v17 = UFG::qStringHash32(v25.mData, 0xFFFFFFFF);
    v25.mStringHash32 = v17;
  }
  v18 = 3 * *((_DWORD *)v8 + 58);
  v19 = Illusion::Factory::NewBuffer(
          v25.mData,
          v17,
          2 * num_instances * v18,
          0i64,
          "Particle.Trail.IndexBuffer",
          0i64,
          0i64);
  v19->mBufferType = 1;
  v20 = 2;
  v19->mElementByteSize = 2;
  v19->mNumElements = num_instances * v18;
  v21 = v19->mData.mOffset;
  if ( v21 )
    v22 = (char *)&v19->mData + v21;
  else
    v22 = 0i64;
  if ( num_instances )
  {
    do
    {
      *(_WORD *)&v22[2 * v20 - 4] = 16 * v3;
      *(_WORD *)&v22[2 * v20 - 2] = 16 * v3 + 2;
      *(_WORD *)&v22[2 * v20] = 16 * v3 + 1;
      *(_WORD *)&v22[2 * v20 + 2] = 16 * v3 + 1;
      *(_WORD *)&v22[2 * v20 + 4] = 16 * v3 + 2;
      *(_WORD *)&v22[2 * v20 + 6] = 16 * v3 + 3;
      *(_WORD *)&v22[2 * v20 + 8] = 16 * v3 + 3;
      *(_WORD *)&v22[2 * v20 + 10] = 16 * v3 + 2;
      *(_WORD *)&v22[2 * v20 + 12] = 16 * v3 + 4;
      *(_WORD *)&v22[2 * v20 + 14] = 16 * v3 + 3;
      *(_WORD *)&v22[2 * v20 + 16] = 16 * v3 + 4;
      *(_WORD *)&v22[2 * v20 + 18] = 16 * v3 + 5;
      *(_WORD *)&v22[2 * v20 + 20] = 16 * v3 + 5;
      *(_WORD *)&v22[2 * v20 + 22] = 16 * v3 + 4;
      *(_WORD *)&v22[2 * v20 + 24] = 16 * v3 + 6;
      *(_WORD *)&v22[2 * v20 + 26] = 16 * v3 + 5;
      *(_WORD *)&v22[2 * v20 + 28] = 16 * v3 + 6;
      *(_WORD *)&v22[2 * v20 + 30] = 16 * v3 + 7;
      *(_WORD *)&v22[2 * v20 + 32] = 16 * v3 + 7;
      *(_WORD *)&v22[2 * v20 + 34] = 16 * v3 + 6;
      *(_WORD *)&v22[2 * v20 + 36] = 16 * v3 + 8;
      *(_WORD *)&v22[2 * v20 + 38] = 16 * v3 + 7;
      *(_WORD *)&v22[2 * v20 + 40] = 16 * v3 + 8;
      *(_WORD *)&v22[2 * v20 + 42] = 16 * v3 + 9;
      *(_WORD *)&v22[2 * v20 + 44] = 16 * v3 + 9;
      *(_WORD *)&v22[2 * v20 + 46] = 16 * v3 + 8;
      *(_WORD *)&v22[2 * v20 + 48] = 16 * v3 + 10;
      *(_WORD *)&v22[2 * v20 + 50] = 16 * v3 + 9;
      *(_WORD *)&v22[2 * v20 + 52] = 16 * v3 + 10;
      *(_WORD *)&v22[2 * v20 + 54] = 16 * v3 + 11;
      *(_WORD *)&v22[2 * v20 + 56] = 16 * v3 + 11;
      *(_WORD *)&v22[2 * v20 + 58] = 16 * v3 + 10;
      *(_WORD *)&v22[2 * v20 + 60] = 16 * v3 + 12;
      *(_WORD *)&v22[2 * v20 + 62] = 16 * v3 + 11;
      *(_WORD *)&v22[2 * v20 + 64] = 16 * v3 + 12;
      *(_WORD *)&v22[2 * v20 + 66] = 16 * v3 + 13;
      *(_WORD *)&v22[2 * v20 + 68] = 16 * v3 + 13;
      *(_WORD *)&v22[2 * v20 + 70] = 16 * v3 + 12;
      *(_WORD *)&v22[2 * v20 + 72] = 16 * v3 + 14;
      *(_WORD *)&v22[2 * v20 + 74] = 16 * v3 + 13;
      *(_WORD *)&v22[2 * v20 + 76] = 16 * v3 + 14;
      *(_WORD *)&v22[2 * v20 + 78] = 16 * v3++ + 15;
      v20 += v18;
    }
    while ( v3 < num_instances );
  }
  v23 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v23, &v19->UFG::qResourceData);
  *((_DWORD *)v8 + 22) = v17;
  UFG::qString::~qString(&v25);
  v24 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v24, v5);
}

// File Line: 822
// RVA: 0x1D0380
void __fastcall Render::ParticleEmitterManager::InitQuadModel(
        Render::ParticleEmitterManager *this,
        unsigned int num_instances)
{
  UFG::qResourceData *v2; // rax
  UFG::qResourceData *v3; // rbp
  UFG::qBaseNodeRB *v4; // rcx
  _QWORD *v5; // rcx
  char *v6; // rdi
  unsigned int mStringHash32; // ebx
  Illusion::Buffer *v8; // rsi
  __int64 mOffset; // rax
  char *v10; // rcx
  UFG::qResourceWarehouse *v11; // rax
  unsigned int v12; // esi
  Illusion::Buffer *v13; // rbx
  __int64 v14; // rax
  _DWORD *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::qString v18; // [rsp+48h] [rbp-50h] BYREF

  v2 = Illusion::Factory::NewModel("ParticleManager.QuadModel", 0xA8A40548, 1u, 0i64, 0i64, 0i64);
  v3 = v2;
  v4 = v2[2].mNode.mChild[0];
  if ( v4 )
    v5 = (UFG::qBaseNodeRB **)((char *)&v4[5].mChild[2] + (_QWORD)v2);
  else
    v5 = 0i64;
  v6 = (char *)v5 + *v5;
  if ( !*v5 )
    v6 = 0i64;
  UFG::qString::qString(&v18, "ParticleManager.Quad.VertexBuffer");
  mStringHash32 = v18.mStringHash32;
  if ( v18.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(v18.mData, 0xFFFFFFFF);
    v18.mStringHash32 = mStringHash32;
  }
  *((_QWORD *)v6 + 28) = 3i64;
  *((_DWORD *)v6 + 58) = 2;
  v8 = Illusion::Factory::NewBuffer(v18.mData, mStringHash32, 0x40u, 0i64, "Particle.Quad.VertexBuffer", 0i64, 0i64);
  v8->mBufferType = 0;
  v8->mElementByteSize = 16;
  v8->mNumElements = 4;
  mOffset = v8->mData.mOffset;
  if ( mOffset )
    v10 = (char *)&v8->mData + mOffset;
  else
    v10 = 0i64;
  *(_DWORD *)v10 = -1090519040;
  *((_DWORD *)v10 + 1) = -1090519040;
  *((_DWORD *)v10 + 2) = 0;
  *((_DWORD *)v10 + 3) = 1065353216;
  *((_DWORD *)v10 + 4) = 1056964608;
  *((_DWORD *)v10 + 5) = -1090519040;
  *((_DWORD *)v10 + 6) = 1065353216;
  *((_DWORD *)v10 + 7) = 1065353216;
  *((_DWORD *)v10 + 8) = 1056964608;
  *((_DWORD *)v10 + 9) = 1056964608;
  *((_QWORD *)v10 + 5) = 1065353216i64;
  *((_DWORD *)v10 + 12) = -1090519040;
  *(_QWORD *)(v10 + 52) = 1056964608i64;
  *((_DWORD *)v10 + 15) = 0;
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, &v8->UFG::qResourceData);
  *((_QWORD *)v6 + 30) = "ParticleManager.QuadModel";
  *((_DWORD *)v6 + 30) = mStringHash32;
  *((_DWORD *)v6 + 14) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gParticleDescriptor);
  UFG::qString::~qString(&v18);
  UFG::qString::qString(&v18, "ParticleManager.Quad.IndexBuffer");
  v12 = v18.mStringHash32;
  if ( v18.mStringHash32 == -1 )
  {
    v12 = UFG::qStringHash32(v18.mData, 0xFFFFFFFF);
    v18.mStringHash32 = v12;
  }
  v13 = Illusion::Factory::NewBuffer(v18.mData, v12, 0xCu, 0i64, "Particle.Quad.IndexBuffer", 0i64, 0i64);
  v13->mBufferType = 1;
  v13->mElementByteSize = 2;
  v13->mNumElements = 6;
  v14 = v13->mData.mOffset;
  if ( v14 )
    v15 = (_DWORD *)((char *)&v13->mData + v14);
  else
    v15 = 0i64;
  *v15 = 0x10000;
  v15[1] = 196611;
  v15[2] = 131073;
  v16 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v16, &v13->UFG::qResourceData);
  *((_DWORD *)v6 + 22) = v12;
  UFG::qString::~qString(&v18);
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, v3);
}

// File Line: 914
// RVA: 0x1CF600
void __fastcall Render::ParticleEmitterManager::Init(Render::ParticleEmitterManager *this)
{
  __int64 v2; // r12
  UFG::allocator::free_link *v3; // rax
  Render::ParticleEmitterBuffer *v4; // rax
  Render::ParticleEmitterBuffer *v5; // rbp
  __int64 size; // r15
  unsigned int v7; // esi
  unsigned int capacity; // edi
  unsigned int v9; // edi
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  Render::ParticleEmitterBuffer **v12; // r14
  __int64 i; // r9
  __int64 v14; // r12
  UFG::allocator::free_link *v15; // rax
  Render::ParticleEmitterBuffer *v16; // rax
  Render::ParticleEmitterBuffer *v17; // rbp
  __int64 v18; // r15
  unsigned int v19; // esi
  unsigned int v20; // edi
  unsigned int v21; // edi
  unsigned __int64 v22; // rax
  UFG::allocator::free_link *v23; // rax
  Render::ParticleEmitterBuffer **v24; // r14
  __int64 j; // r9
  hkResourceHandle *v26; // rax

  Render::ParticleEmitterManager::InitStateSystemParams(this);
  *(_QWORD *)&this->mOverdrawIntensity = 1028443341i64;
  this->mOverdrawToggle = 0;
  Render::ParticleEmitterManager::InitQuadModel(this, 0x20u);
  Render::ParticleEmitterManager::InitTrailModel(this, 0x20u);
  v2 = 224i64;
  do
  {
    v3 = UFG::qMalloc(0x168ui64, "ParticleEmitterBuffer", 0x800ui64);
    if ( v3 )
    {
      Render::ParticleEmitterBuffer::ParticleEmitterBuffer((Render::ParticleEmitterBuffer *)v3);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    Render::ParticleEmitterBuffer::Init(v5, 0x20u);
    size = this->freeBuffersLarge.size;
    v7 = size + 1;
    capacity = this->freeBuffersLarge.capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v9 = 2 * capacity;
      else
        v9 = 1;
      for ( ; v9 < v7; v9 *= 2 )
        ;
      if ( v9 <= 2 )
        v9 = 2;
      if ( v9 - v7 > 0x10000 )
        v9 = size + 65537;
      if ( v9 != (_DWORD)size )
      {
        v10 = 8i64 * v9;
        if ( !is_mul_ok(v9, 8ui64) )
          v10 = -1i64;
        v11 = UFG::qMalloc(v10, "qArray.Add", 0i64);
        v12 = (Render::ParticleEmitterBuffer **)v11;
        if ( this->freeBuffersLarge.p )
        {
          for ( i = 0i64; (unsigned int)i < this->freeBuffersLarge.size; i = (unsigned int)(i + 1) )
            v11[i] = (UFG::allocator::free_link)this->freeBuffersLarge.p[i];
          operator delete[](this->freeBuffersLarge.p);
        }
        this->freeBuffersLarge.p = v12;
        this->freeBuffersLarge.capacity = v9;
      }
    }
    this->freeBuffersLarge.size = v7;
    this->freeBuffersLarge.p[size] = v5;
    --v2;
  }
  while ( v2 );
  v14 = 256i64;
  do
  {
    v15 = UFG::qMalloc(0x168ui64, "ParticleEmitterBuffer", 0x800ui64);
    if ( v15 )
    {
      Render::ParticleEmitterBuffer::ParticleEmitterBuffer((Render::ParticleEmitterBuffer *)v15);
      v17 = v16;
    }
    else
    {
      v17 = 0i64;
    }
    Render::ParticleEmitterBuffer::Init(v17, 4u);
    v18 = this->freeBuffersSmall.size;
    v19 = v18 + 1;
    v20 = this->freeBuffersSmall.capacity;
    if ( (int)v18 + 1 > v20 )
    {
      if ( v20 )
        v21 = 2 * v20;
      else
        v21 = 1;
      for ( ; v21 < v19; v21 *= 2 )
        ;
      if ( v21 <= 2 )
        v21 = 2;
      if ( v21 - v19 > 0x10000 )
        v21 = v18 + 65537;
      if ( v21 != (_DWORD)v18 )
      {
        v22 = 8i64 * v21;
        if ( !is_mul_ok(v21, 8ui64) )
          v22 = -1i64;
        v23 = UFG::qMalloc(v22, "qArray.Add", 0i64);
        v24 = (Render::ParticleEmitterBuffer **)v23;
        if ( this->freeBuffersSmall.p )
        {
          for ( j = 0i64; (unsigned int)j < this->freeBuffersSmall.size; j = (unsigned int)(j + 1) )
            v23[j] = (UFG::allocator::free_link)this->freeBuffersSmall.p[j];
          operator delete[](this->freeBuffersSmall.p);
        }
        this->freeBuffersSmall.p = v24;
        this->freeBuffersSmall.capacity = v21;
      }
    }
    this->freeBuffersSmall.size = v19;
    this->freeBuffersSmall.p[v18] = v17;
    --v14;
  }
  while ( v14 );
  this->mShaderParticleLitShadowUID = UFG::qStringHashUpper32("ParticleLitShadow", -1);
  this->mShaderParticleLitUID = UFG::qStringHashUpper32("ParticleLit", -1);
  this->mShaderParticleSoftLitShadowUID = UFG::qStringHashUpper32("ParticleSoftLitShadow", -1);
  this->mShaderParticleSoftLitUID = UFG::qStringHashUpper32("ParticleSoftLit", -1);
  if ( Render::gRunParticleTaskOnPPU )
  {
    Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mSpuElf = 0i64;
  }
  else
  {
    v26 = (hkResourceHandle *)UFG::qSpuManager::Instance();
    Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mSpuElf = (UFG::qSpuElf *)TargetVisibleInAIDataCondition::CreateClone(v26);
  }
}

// File Line: 959
// RVA: 0x1CB030
void __fastcall Render::ParticleEmitterManager::DestroyBuffers(
        Render::ParticleEmitterManager *this,
        UFG::qArray<Render::ParticleEmitterBuffer *,0> *bufferArray)
{
  __int64 i; // rbx
  Render::ParticleEmitterBuffer **p; // rax
  Render::ParticleEmitterBuffer *v5; // rsi
  Render::ParticleEmitterBuffer **v6; // rcx

  for ( i = 0i64; (unsigned int)i < bufferArray->size; i = (unsigned int)(i + 1) )
  {
    p = bufferArray->p;
    v5 = p[i];
    if ( v5 )
    {
      Render::ParticleEmitterBuffer::~ParticleEmitterBuffer(p[i]);
      operator delete[](v5);
    }
  }
  v6 = bufferArray->p;
  if ( v6 )
    operator delete[](v6);
  bufferArray->p = 0i64;
  *(_QWORD *)&bufferArray->size = 0i64;
}

// File Line: 969
// RVA: 0x1C7140
void __fastcall Render::ParticleEmitterManager::AddToFreeBufferList(
        Render::ParticleEmitterManager *this,
        unsigned int queue,
        unsigned int batchIndex)
{
  __int64 v4; // r8
  Render::ParticleEmitterBuffer *v5; // rsi
  Render::ParticleRaycaster *mRaycaster; // rax
  unsigned int size; // eax
  Render::ParticleRaycaster *v8; // rax
  __int64 v9; // rbp
  unsigned int capacity; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  Render::ParticleEmitterBuffer **p; // rax
  unsigned int v14; // edx
  unsigned int v15; // ebx
  unsigned int v16; // edx

  v4 = batchIndex;
  v5 = this->activeBuffers[queue].p[v4];
  mRaycaster = v5->mRaycaster;
  if ( mRaycaster )
    mRaycaster->mMode = 4;
  this->activeBuffers[queue].p[v4] = this->activeBuffers[queue].p[this->activeBuffers[queue].size - 1];
  size = this->activeBuffers[queue].size;
  if ( size > 1 )
    this->activeBuffers[queue].size = size - 1;
  else
    this->activeBuffers[queue].size = 0;
  v8 = v5->mRaycaster;
  if ( v8 )
    v8->mMode = 4;
  Render::ParticleEmitterBuffer::Deactivate(v5);
  if ( v5->mCapacity == 32 )
  {
    v9 = this->freeBuffersLarge.size;
    capacity = this->freeBuffersLarge.capacity;
    v11 = v9 + 1;
    if ( (int)v9 + 1 > capacity )
    {
      if ( capacity )
        v12 = 2 * capacity;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 <= 2 )
        v12 = 2;
      if ( v12 - v11 > 0x10000 )
        v12 = v9 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->freeBuffersLarge,
        v12,
        "qArray.Add");
    }
    p = this->freeBuffersLarge.p;
    this->freeBuffersLarge.size = v11;
  }
  else
  {
    v9 = this->freeBuffersSmall.size;
    v14 = this->freeBuffersSmall.capacity;
    v15 = v9 + 1;
    if ( (int)v9 + 1 > v14 )
    {
      if ( v14 )
        v16 = 2 * v14;
      else
        v16 = 1;
      for ( ; v16 < v15; v16 *= 2 )
        ;
      if ( v16 <= 2 )
        v16 = 2;
      if ( v16 - v15 > 0x10000 )
        v16 = v9 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->freeBuffersSmall,
        v16,
        "qArray.Add");
    }
    p = this->freeBuffersSmall.p;
    this->freeBuffersSmall.size = v15;
  }
  p[v9] = v5;
}

// File Line: 994
// RVA: 0x1C8460
void __fastcall Render::ParticleEmitterManager::Close(Render::ParticleEmitterManager *this)
{
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *activeBuffers; // rdi
  __int64 v3; // rbp
  unsigned int i; // ebx
  Render::ParticleEmitterBuffer **p; // rax
  Render::ParticleEmitterBuffer *v6; // rsi
  Render::ParticleEmitterBuffer **v7; // rcx

  Render::ParticleEmitterManager::DestroyBuffers(this, &this->freeBuffersLarge);
  Render::ParticleEmitterManager::DestroyBuffers(this, &this->freeBuffersSmall);
  activeBuffers = this->activeBuffers;
  v3 = 3i64;
  do
  {
    for ( i = 0; i < activeBuffers->size; ++i )
    {
      p = activeBuffers->p;
      v6 = p[i];
      if ( v6 )
      {
        Render::ParticleEmitterBuffer::~ParticleEmitterBuffer(p[i]);
        operator delete[](v6);
      }
    }
    v7 = activeBuffers->p;
    if ( v7 )
      operator delete[](v7);
    activeBuffers->p = 0i64;
    *(_QWORD *)&activeBuffers->size = 0i64;
    ++activeBuffers;
    --v3;
  }
  while ( v3 );
}

// File Line: 1004
// RVA: 0x1CC6E0
Render::ParticleEmitterBuffer *__fastcall Render::ParticleEmitterManager::GetParticleBuffer(
        Render::ParticleEmitterManager *this,
        Render::ParticleEmitterSettings *settings,
        float creationTime,
        bool canStealBuffer)
{
  bool v7; // al
  char mType; // cl
  char v9; // al
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *p_freeBuffersSmall; // rbx
  void ***v11; // rdi
  __int64 *v12; // rdx
  __int64 v13; // rcx
  _QWORD *v14; // rax
  void **v15; // rbx
  int v17; // ebx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rsi
  unsigned __int8 mPriority; // r10
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *activeBuffers; // rax
  __int64 v22; // r14
  unsigned int v23; // r11d
  float v24; // xmm4_4
  int v25; // edi
  unsigned int v26; // r9d
  unsigned int size; // r13d
  unsigned int v28; // edx
  __int64 v29; // r15
  int v30; // r8d
  _QWORD *v31; // rcx
  __int64 v32; // rax
  __m128 y_low; // xmm2
  float v34; // xmm1_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  __int64 v39; // rax
  __m128 v40; // xmm2
  float v41; // xmm1_4
  float v42; // xmm3_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  __int64 v46; // rax
  __m128 v47; // xmm2
  float v48; // xmm1_4
  float v49; // xmm3_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  __int64 v53; // rax
  __m128 v54; // xmm2
  float v55; // xmm1_4
  float v56; // xmm3_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  __int64 v60; // rcx
  __int64 v61; // rax
  __m128 v62; // xmm2
  float v63; // xmm1_4
  float v64; // xmm3_4
  float v65; // xmm1_4
  float v66; // xmm2_4
  float v67; // xmm1_4
  unsigned int v68; // eax
  char *v69; // rdi
  __int64 v70; // rsi
  unsigned int v71; // edx
  unsigned int v72; // ebx
  unsigned int v73; // edx
  __int64 v74; // rax
  __int64 v75; // rcx
  __int64 *v76; // rdx
  __int64 v77; // rcx
  _QWORD *v78; // rax
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *v79; // [rsp+20h] [rbp-88h]
  int mDrawType; // [rsp+B8h] [rbp+10h]

  mDrawType = (unsigned __int8)settings->mDrawType;
  v7 = settings->mEmissionRate == 0.0 && settings->mEmissionInit <= 4;
  mType = settings->mType;
  if ( mType == 2 || v7 && mType != 1 )
  {
    v9 = 1;
    p_freeBuffersSmall = &this->freeBuffersSmall;
  }
  else
  {
    v9 = 0;
    p_freeBuffersSmall = &this->freeBuffersLarge;
  }
  if ( p_freeBuffersSmall->size && p_freeBuffersSmall )
  {
    v11 = (void ***)UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
                      (UFG::qArray<UFG::qPropertySet *,0> *)&this->activeBuffers[(unsigned __int8)settings->mDrawType],
                      (UFG::qPropertySet *const *)&p_freeBuffersSmall->p[p_freeBuffersSmall->size - 1],
                      "qArray.Add");
    if ( p_freeBuffersSmall->size > 1 )
      --p_freeBuffersSmall->size;
    else
      p_freeBuffersSmall->size = 0;
    *((_DWORD *)*v11 + 10) = 0;
    *((float *)*v11 + 11) = creationTime;
    *((_DWORD *)*v11 + 12) = 0;
    v12 = (__int64 *)(*v11)[4];
    if ( v12[2] )
    {
      v13 = *v12;
      v14 = (_QWORD *)v12[1];
      *(_QWORD *)(v13 + 8) = v14;
      *v14 = v13;
      *v12 = (__int64)v12;
      v12[1] = (__int64)v12;
    }
    v12[2] = 0i64;
    v15 = *v11;
    UFG::qMemSet(**v11, 0, 0x270u);
    UFG::qMemSet(v15[1], 0, 8u);
    v15[2] = 0i64;
    v15[3] = 0i64;
    return (Render::ParticleEmitterBuffer *)*v11;
  }
  else
  {
    if ( !canStealBuffer )
      return 0i64;
    v17 = 32;
    if ( v9 )
      v17 = 4;
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    p_mCamera = &mCurrentCamera->mCamera;
    if ( !mCurrentCamera )
      p_mCamera = 0i64;
    mPriority = settings->mPriority;
    activeBuffers = this->activeBuffers;
    v22 = 0i64;
    v23 = 0;
    v24 = 0.0;
    v25 = 0;
    v26 = 0;
    v79 = this->activeBuffers;
    do
    {
      size = activeBuffers->size;
      v28 = 0;
      v29 = 0i64;
      if ( (int)activeBuffers->size >= 4 )
      {
        v30 = 2;
        v31 = activeBuffers->p + 2;
        v29 = 4i64 * (((size - 4) >> 2) + 1);
        do
        {
          v32 = *(v31 - 2);
          if ( *(_DWORD *)(v32 + 52) == v17 && *(_BYTE *)(v32 + 268) >= mPriority )
          {
            y_low = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
            v34 = p_mCamera->mTransformation.v3.x - *(float *)(v32 + 248);
            v35 = *(float *)(v32 + 40);
            y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - *(float *)(v32 + 252))
                                              * (float)(y_low.m128_f32[0] - *(float *)(v32 + 252)))
                                      + (float)(v34 * v34))
                              + (float)((float)(p_mCamera->mTransformation.v3.z - *(float *)(v32 + 256))
                                      * (float)(p_mCamera->mTransformation.v3.z - *(float *)(v32 + 256)));
            LODWORD(v36) = _mm_sqrt_ps(y_low).m128_u32[0];
            if ( v35 == 0.0 )
              v37 = 0.0;
            else
              v37 = (float)(creationTime - *(float *)(v32 + 44)) / (float)(v35 - *(float *)(v32 + 44));
            v38 = (float)((float)(v36 * 37.0) * v37) * 0.25;
            if ( !*(_QWORD *)(v32 + 288) )
              v38 = v38 * 2.0;
            if ( v38 > v24 )
            {
              v22 = *(v31 - 2);
              v23 = v26;
              v25 = v28;
              v24 = v38;
            }
          }
          v39 = *(v31 - 1);
          if ( *(_DWORD *)(v39 + 52) == v17 && *(_BYTE *)(v39 + 268) >= mPriority )
          {
            v40 = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
            v41 = p_mCamera->mTransformation.v3.x - *(float *)(v39 + 248);
            v42 = *(float *)(v39 + 40);
            v40.m128_f32[0] = (float)((float)((float)(v40.m128_f32[0] - *(float *)(v39 + 252))
                                            * (float)(v40.m128_f32[0] - *(float *)(v39 + 252)))
                                    + (float)(v41 * v41))
                            + (float)((float)(p_mCamera->mTransformation.v3.z - *(float *)(v39 + 256))
                                    * (float)(p_mCamera->mTransformation.v3.z - *(float *)(v39 + 256)));
            LODWORD(v43) = _mm_sqrt_ps(v40).m128_u32[0];
            if ( v42 == 0.0 )
              v44 = 0.0;
            else
              v44 = (float)(creationTime - *(float *)(v39 + 44)) / (float)(v42 - *(float *)(v39 + 44));
            v45 = (float)((float)(v43 * 37.0) * v44) * 0.25;
            if ( !*(_QWORD *)(v39 + 288) )
              v45 = v45 * 2.0;
            if ( v45 > v24 )
            {
              v22 = *(v31 - 1);
              v23 = v26;
              v25 = v30 - 1;
              v24 = v45;
            }
          }
          v46 = *v31;
          if ( *(_DWORD *)(*v31 + 52i64) == v17 && *(_BYTE *)(v46 + 268) >= mPriority )
          {
            v47 = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
            v48 = p_mCamera->mTransformation.v3.x - *(float *)(v46 + 248);
            v49 = *(float *)(v46 + 40);
            v47.m128_f32[0] = (float)((float)((float)(v47.m128_f32[0] - *(float *)(v46 + 252))
                                            * (float)(v47.m128_f32[0] - *(float *)(v46 + 252)))
                                    + (float)(v48 * v48))
                            + (float)((float)(p_mCamera->mTransformation.v3.z - *(float *)(v46 + 256))
                                    * (float)(p_mCamera->mTransformation.v3.z - *(float *)(v46 + 256)));
            LODWORD(v50) = _mm_sqrt_ps(v47).m128_u32[0];
            if ( v49 == 0.0 )
              v51 = 0.0;
            else
              v51 = (float)(creationTime - *(float *)(v46 + 44)) / (float)(v49 - *(float *)(v46 + 44));
            v52 = (float)((float)(v50 * 37.0) * v51) * 0.25;
            if ( !*(_QWORD *)(v46 + 288) )
              v52 = v52 * 2.0;
            if ( v52 > v24 )
            {
              v22 = *v31;
              v23 = v26;
              v25 = v30;
              v24 = v52;
            }
          }
          v53 = v31[1];
          if ( *(_DWORD *)(v53 + 52) == v17 && *(_BYTE *)(v53 + 268) >= mPriority )
          {
            v54 = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
            v55 = p_mCamera->mTransformation.v3.x - *(float *)(v53 + 248);
            v56 = *(float *)(v53 + 40);
            v54.m128_f32[0] = (float)((float)((float)(v54.m128_f32[0] - *(float *)(v53 + 252))
                                            * (float)(v54.m128_f32[0] - *(float *)(v53 + 252)))
                                    + (float)(v55 * v55))
                            + (float)((float)(p_mCamera->mTransformation.v3.z - *(float *)(v53 + 256))
                                    * (float)(p_mCamera->mTransformation.v3.z - *(float *)(v53 + 256)));
            LODWORD(v57) = _mm_sqrt_ps(v54).m128_u32[0];
            if ( v56 == 0.0 )
              v58 = 0.0;
            else
              v58 = (float)(creationTime - *(float *)(v53 + 44)) / (float)(v56 - *(float *)(v53 + 44));
            v59 = (float)((float)(v57 * 37.0) * v58) * 0.25;
            if ( !*(_QWORD *)(v53 + 288) )
              v59 = v59 * 2.0;
            if ( v59 > v24 )
            {
              v22 = v31[1];
              v23 = v26;
              v25 = v30 + 1;
              v24 = v59;
            }
          }
          v28 += 4;
          v31 += 4;
          v30 += 4;
        }
        while ( v28 < size - 3 );
        activeBuffers = v79;
      }
      if ( v28 < size )
      {
        v60 = (__int64)&activeBuffers->p[v29];
        do
        {
          v61 = *(_QWORD *)v60;
          if ( *(_DWORD *)(*(_QWORD *)v60 + 52i64) == v17 && *(_BYTE *)(v61 + 268) >= mPriority )
          {
            v62 = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
            v63 = p_mCamera->mTransformation.v3.x - *(float *)(v61 + 248);
            v64 = *(float *)(v61 + 40);
            v62.m128_f32[0] = (float)((float)((float)(v62.m128_f32[0] - *(float *)(v61 + 252))
                                            * (float)(v62.m128_f32[0] - *(float *)(v61 + 252)))
                                    + (float)(v63 * v63))
                            + (float)((float)(p_mCamera->mTransformation.v3.z - *(float *)(v61 + 256))
                                    * (float)(p_mCamera->mTransformation.v3.z - *(float *)(v61 + 256)));
            LODWORD(v65) = _mm_sqrt_ps(v62).m128_u32[0];
            if ( v64 == 0.0 )
              v66 = 0.0;
            else
              v66 = (float)(creationTime - *(float *)(v61 + 44)) / (float)(v64 - *(float *)(v61 + 44));
            v67 = (float)((float)(v65 * 37.0) * v66) * 0.25;
            if ( !*(_QWORD *)(v61 + 288) )
              v67 = v67 * 2.0;
            if ( v67 > v24 )
            {
              v22 = *(_QWORD *)v60;
              v23 = v26;
              v25 = v28;
              v24 = v67;
            }
          }
          ++v28;
          v60 += 8i64;
        }
        while ( v28 < size );
        activeBuffers = v79;
      }
      ++activeBuffers;
      ++v26;
      v79 = activeBuffers;
    }
    while ( v26 < 3 );
    if ( v22 )
    {
      if ( v23 != mDrawType )
      {
        this->activeBuffers[v23].p[v25] = this->activeBuffers[v23].p[this->activeBuffers[v23].size - 1];
        v68 = this->activeBuffers[v23].size;
        if ( v68 > 1 )
          this->activeBuffers[v23].size = v68 - 1;
        else
          this->activeBuffers[v23].size = 0;
        v69 = (char *)this + 16 * mDrawType;
        v70 = *((unsigned int *)v69 + 10);
        v71 = *((_DWORD *)v69 + 11);
        v72 = v70 + 1;
        if ( (int)v70 + 1 > v71 )
        {
          if ( v71 )
            v73 = 2 * v71;
          else
            v73 = 1;
          for ( ; v73 < v72; v73 *= 2 )
            ;
          if ( v73 <= 2 )
            v73 = 2;
          if ( v73 - v72 > 0x10000 )
            v73 = v70 + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
            (UFG::qArray<UFG::qReflectInventoryBase *,0> *)(v69 + 40),
            v73,
            "qArray.Add");
        }
        v74 = *((_QWORD *)v69 + 6);
        *((_DWORD *)v69 + 10) = v72;
        *(_QWORD *)(v74 + 8 * v70) = v22;
      }
      v75 = *(_QWORD *)(v22 + 288);
      if ( v75 )
      {
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v75 + 48i64))(v75);
        *(_QWORD *)(v22 + 288) = 0i64;
      }
      v76 = *(__int64 **)(v22 + 32);
      if ( v76[2] )
      {
        v77 = *v76;
        v78 = (_QWORD *)v76[1];
        *(_QWORD *)(v77 + 8) = v78;
        *v78 = v77;
        *v76 = (__int64)v76;
        v76[1] = (__int64)v76;
      }
      v76[2] = 0i64;
      *(float *)(v22 + 44) = creationTime;
      *(_DWORD *)(v22 + 40) = 0;
      *(_DWORD *)(v22 + 48) = 0;
      UFG::qMemSet(*(void **)v22, 0, 0x270u);
      UFG::qMemSet(*(void **)(v22 + 8), 0, 8u);
      *(_QWORD *)(v22 + 16) = 0i64;
      *(_QWORD *)(v22 + 24) = 0i64;
      return (Render::ParticleEmitterBuffer *)v22;
    }
    else
    {
      return 0i64;
    }
  }
}

// File Line: 1139
// RVA: 0x1D1940
void __fastcall Render::MapGeoMaterialState(Illusion::Material *mat, Render::eParticleQueue queue)
{
  unsigned int v4; // eax
  unsigned int v5; // edx
  Illusion::Material *v6; // rax
  _WORD *v7; // rbx
  __int64 v8; // rax
  _WORD *v9; // rax
  Illusion::Material *v10; // rax
  __int64 mOffset; // rax
  Illusion::Material *ParamByNameUID; // rax

  v4 = _S7_5;
  if ( (_S7_5 & 1) == 0 )
  {
    _S7_5 |= 1u;
    alphaStateUID = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    v4 = _S7_5;
  }
  if ( (v4 & 2) != 0 )
  {
    v5 = rasterStateUID;
  }
  else
  {
    _S7_5 = v4 | 2;
    v5 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    rasterStateUID = v5;
  }
  if ( queue )
  {
    if ( !Illusion::Material::GetParamByNameUID(mat, v5)->mResourceHandles.UFG::qResourceData::mNode.mPrev )
    {
      ParamByNameUID = Illusion::Material::GetParamByNameUID(mat, rasterStateUID);
      if ( ParamByNameUID )
      {
        if ( LODWORD(ParamByNameUID->mResourceHandles.UFG::qResourceData::mNode.mNext) != -262489691 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&ParamByNameUID->mNode.mChild[1],
            ParamByNameUID->mTypeUID,
            0xF05AB9A5);
          mOffset = mat->mMaterialUser.mOffset;
          if ( !mOffset )
          {
            v7 = 0i64;
            goto LABEL_22;
          }
          goto LABEL_16;
        }
      }
    }
  }
  else
  {
    v6 = Illusion::Material::GetParamByNameUID(mat, alphaStateUID);
    v7 = 0i64;
    if ( v6 && LODWORD(v6->mResourceHandles.UFG::qResourceData::mNode.mNext) != 662883558 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mNode.mChild[1], v6->mTypeUID, 0x2782CCE6u);
      v8 = mat->mMaterialUser.mOffset;
      if ( v8 )
        v9 = (_WORD *)((char *)&mat->mMaterialUser + v8);
      else
        v9 = 0i64;
      *v9 |= 0x20u;
    }
    v10 = Illusion::Material::GetParamByNameUID(mat, rasterStateUID);
    if ( v10 && LODWORD(v10->mResourceHandles.UFG::qResourceData::mNode.mNext) != 543723269 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v10->mNode.mChild[1], v10->mTypeUID, 0x20688F05u);
      mOffset = mat->mMaterialUser.mOffset;
      if ( !mOffset )
      {
LABEL_22:
        *v7 |= 0x20u;
        return;
      }
LABEL_16:
      v7 = (_WORD *)((char *)&mat->mMaterialUser + mOffset);
      goto LABEL_22;
    }
  }
}

// File Line: 1169
// RVA: 0x1DBB90
void __fastcall Render::ParticleEmitterManager::UpdateRaycasts(Render::ParticleEmitterManager *this)
{
  Render::ParticleEmitterBuffer ***p_p; // rax
  unsigned int v2; // esi
  unsigned int i; // r15d
  Render::ParticleEmitterBuffer ***v4; // r12
  __int64 v5; // r13
  unsigned int v6; // eax
  __int64 v7; // r14
  __int64 j; // rbp
  Render::ParticleEmitterBuffer *v9; // rcx
  Render::ParticleRaycaster *mRaycaster; // rbx
  float y; // xmm0_4
  float z; // xmm1_4
  Render::ParticleRaycaster::Mode mMode; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  Render::ParticleEmitterBuffer ***v17; // [rsp+58h] [rbp+10h]

  p_p = &this->activeBuffers[0].p;
  v2 = 36;
  v17 = &this->activeBuffers[0].p;
  for ( i = 0; i < 2; ++i )
  {
    v4 = p_p;
    v5 = 3i64;
    do
    {
      v6 = *((_DWORD *)v4 - 2);
      if ( v6 )
      {
        v7 = 0i64;
        for ( j = v6; j; --j )
        {
          v9 = (*v4)[v7];
          if ( i )
          {
            mRaycaster = v9->mRaycaster;
            if ( (unsigned int)(mRaycaster->mMode - 1) > 1 )
            {
LABEL_9:
              y = v9->mLastKnownGoodBasis.v3.y;
              z = v9->mLastKnownGoodBasis.v3.z;
              mRaycaster->mPosition.x = v9->mLastKnownGoodBasis.v3.x;
              mRaycaster->mPosition.y = y;
              mRaycaster->mPosition.z = z;
              mMode = mRaycaster->mMode;
              if ( mMode == (Mode_Continuous|Mode_Deferred) )
              {
                v14 = Render::ParticleRaycaster::IssueQueries(mRaycaster, v2);
                ++mRaycaster->mRaycastComboIndex;
                v15 = v14;
                if ( mRaycaster->mRaycastComboIndex >= 2 )
                  mRaycaster->mRaycastComboIndex = 0;
              }
              else
              {
                if ( mMode == Mode_Continuous )
                {
                  if ( v2 > 0xC )
                  {
                    v15 = 0;
                    mRaycaster->mRaycastComboIndex = 0;
                    do
                    {
                      v16 = Render::ParticleRaycaster::IssueQueries(mRaycaster, v2);
                      ++mRaycaster->mRaycastComboIndex;
                      v15 += v16;
                    }
                    while ( mRaycaster->mRaycastComboIndex < 2 );
                    *(_QWORD *)&mRaycaster->mMode = 1i64;
                    goto LABEL_20;
                  }
                }
                else if ( mMode == 4 )
                {
                  mRaycaster->mMode = Mode_Immediate;
                }
                v15 = 0;
              }
LABEL_20:
              v2 -= v15;
            }
          }
          else
          {
            mRaycaster = v9->mRaycaster;
            if ( (unsigned int)(mRaycaster->mMode - 1) <= 1 )
              goto LABEL_9;
          }
          ++v7;
        }
      }
      v4 += 2;
      --v5;
    }
    while ( v5 );
    p_p = v17;
  }
}

// File Line: 1194
// RVA: 0x1D6300
void __fastcall Render::ParticleEmitterManager::SetAuxBuffers(
        Render::ParticleEmitterManager *this,
        Render::View *view,
        Render::eParticleQueue queue,
        Render::FXManagerAuxBuffers *auxBuffers)
{
  Illusion::Texture *scrDepth; // rsi
  unsigned int mTexDepthStateIndex_low; // ebp
  Illusion::StateValues *StateValues; // rax
  Illusion::Texture *scrDiffuse; // rsi
  unsigned int mTexDiffuse2StateIndex_low; // ebp
  Illusion::StateValues *v12; // rax
  Illusion::Texture *texShadowAtlas; // rsi
  unsigned int mTexShadowAtlasStateIndex_low; // ebp
  Illusion::StateValues *v15; // rax
  Illusion::Texture *texHeightmap; // rsi
  unsigned int mTexHeightmapStateIndex_low; // ebp
  Illusion::StateValues *v18; // rax
  Illusion::Texture *texHeightmapShadow; // rdi
  unsigned int mTexHeightmapShadowStateIndex_low; // esi
  Illusion::StateValues *v21; // rax

  if ( (unsigned int)(queue - 1) <= 1 )
  {
    scrDepth = auxBuffers->scrDepth;
    if ( auxBuffers->scrDepth )
    {
      mTexDepthStateIndex_low = SLOWORD(this->mTexDepthStateIndex);
      StateValues = Render::View::GetStateValues(view);
      if ( mTexDepthStateIndex_low >= 0x40 )
        StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mTexDepthStateIndex_low - 64);
      else
        StateValues->mSetValueMask.mFlags[0] |= 1i64 << mTexDepthStateIndex_low;
      StateValues->mParamValues[(__int16)mTexDepthStateIndex_low] = scrDepth;
    }
    scrDiffuse = auxBuffers->scrDiffuse;
    if ( scrDiffuse )
    {
      mTexDiffuse2StateIndex_low = SLOWORD(this->mTexDiffuse2StateIndex);
      v12 = Render::View::GetStateValues(view);
      if ( mTexDiffuse2StateIndex_low >= 0x40 )
        v12->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mTexDiffuse2StateIndex_low - 64);
      else
        v12->mSetValueMask.mFlags[0] |= 1i64 << mTexDiffuse2StateIndex_low;
      v12->mParamValues[(__int16)mTexDiffuse2StateIndex_low] = scrDiffuse;
    }
    texShadowAtlas = auxBuffers->texShadowAtlas;
    if ( texShadowAtlas )
    {
      mTexShadowAtlasStateIndex_low = SLOWORD(this->mTexShadowAtlasStateIndex);
      v15 = Render::View::GetStateValues(view);
      if ( mTexShadowAtlasStateIndex_low >= 0x40 )
        v15->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mTexShadowAtlasStateIndex_low - 64);
      else
        v15->mSetValueMask.mFlags[0] |= 1i64 << mTexShadowAtlasStateIndex_low;
      v15->mParamValues[(__int16)mTexShadowAtlasStateIndex_low] = texShadowAtlas;
    }
    texHeightmap = auxBuffers->texHeightmap;
    if ( texHeightmap )
    {
      mTexHeightmapStateIndex_low = SLOWORD(this->mTexHeightmapStateIndex);
      v18 = Render::View::GetStateValues(view);
      if ( mTexHeightmapStateIndex_low >= 0x40 )
        v18->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mTexHeightmapStateIndex_low - 64);
      else
        v18->mSetValueMask.mFlags[0] |= 1i64 << mTexHeightmapStateIndex_low;
      v18->mParamValues[(__int16)mTexHeightmapStateIndex_low] = texHeightmap;
    }
    texHeightmapShadow = auxBuffers->texHeightmapShadow;
    if ( texHeightmapShadow )
    {
      mTexHeightmapShadowStateIndex_low = SLOWORD(this->mTexHeightmapShadowStateIndex);
      v21 = Render::View::GetStateValues(view);
      if ( mTexHeightmapShadowStateIndex_low >= 0x40 )
        v21->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mTexHeightmapShadowStateIndex_low - 64);
      else
        v21->mSetValueMask.mFlags[0] |= 1i64 << mTexHeightmapShadowStateIndex_low;
      v21->mParamValues[(__int16)mTexHeightmapShadowStateIndex_low] = texHeightmapShadow;
    }
  }
}

// File Line: 1222
// RVA: 0x1D6A80
__int64 __fastcall Render::ParticleEmitterManager::SetTexShadowAtlas(
        Render::ParticleEmitterManager *this,
        Illusion::Material *material,
        Render::FXManagerAuxBuffers *auxBuffers)
{
  unsigned int mNext; // ebx
  unsigned int mShaderParticleSoftLitUID; // r8d
  __int64 mOffset; // rax

  mNext = (unsigned int)material[1].mResourceHandles.UFG::qResourceData::mNode.mNext;
  if ( auxBuffers->texShadowAtlas )
    return 0xFFFFFFFFi64;
  if ( mNext != this->mShaderParticleLitShadowUID )
  {
    if ( mNext == this->mShaderParticleSoftLitShadowUID )
    {
      mShaderParticleSoftLitUID = this->mShaderParticleSoftLitUID;
      goto LABEL_4;
    }
    return 0xFFFFFFFFi64;
  }
  mShaderParticleSoftLitUID = this->mShaderParticleLitUID;
LABEL_4:
  if ( mNext != mShaderParticleSoftLitUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&material[1].mNode.mChild[1],
      material[1].mTypeUID,
      mShaderParticleSoftLitUID);
    mOffset = material->mMaterialUser.mOffset;
    if ( mOffset )
    {
      *(_WORD *)((char *)&material->mMaterialUser.mOffset + mOffset) |= 0x20u;
      return mNext;
    }
    LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
  }
  return mNext;
}

// File Line: 1244
// RVA: 0x1D0800
void __fastcall Render::ParticleEmitterManager::InitStateSystemParams(Render::ParticleEmitterManager *this)
{
  unsigned int v2; // eax

  v2 = UFG::qStringHash32("cbInstancing", 0xFFFFFFFF);
  this->mInstanceStateBlockIndex = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v2, "cbInstancing", 0);
  this->mParticleSoftSettingsStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                              &Illusion::gStateSystem,
                                                              "cbParticleSoftSettings",
                                                              0);
  this->mParticleDynamicLightSettingsStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                                      &Illusion::gStateSystem,
                                                                      "cbParticleDynamicLightSettings",
                                                                      0);
  this->mParticleSettingsStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                          &Illusion::gStateSystem,
                                                          "cbParticleSettings",
                                                          0);
  this->mFXSizeModuleStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                      &Illusion::gStateSystem,
                                                      "cbFXSizeModule",
                                                      0);
  this->mTexDepthStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDepth", 1);
  this->mTexDiffuse2StateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                     &Illusion::gStateSystem,
                                                     "texDiffuse2",
                                                     1);
  this->mTexShadowAtlasStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                        &Illusion::gStateSystem,
                                                        "texShadowAtlas",
                                                        1);
  this->mTexHeightmapStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                      &Illusion::gStateSystem,
                                                      "texHeightmap",
                                                      1);
  this->mTexHeightmapShadowStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                            &Illusion::gStateSystem,
                                                            "texShadow",
                                                            1);
  this->mParticleFlowMapStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                         &Illusion::gStateSystem,
                                                         "cbFXFlowmapSettings",
                                                         1);
}

// File Line: 1259
// RVA: 0x1D71A0
void __fastcall Render::ParticleEmitterManager::SetupLighting(
        Render::ParticleEmitterManager *this,
        Render::View *view,
        Render::ParticleEmitterSettings *pfxSettings)
{
  Illusion::ShaderSelector *mShaderSelector; // r8
  unsigned int mParticleDynamicLightSettingsStateIndex; // ecx

  Render::View::GetStateValues(view);
  mShaderSelector = view->mSubmitContext->mShaderSelector;
  mParticleDynamicLightSettingsStateIndex = this->mParticleDynamicLightSettingsStateIndex;
  if ( pfxSettings->mSettings.LightInfo[1] <= 0.0 )
  {
    mShaderSelector->mAddState.mFlags[mParticleDynamicLightSettingsStateIndex >> 6] &= ~(1i64 << (mParticleDynamicLightSettingsStateIndex & 0x3F));
  }
  else if ( mParticleDynamicLightSettingsStateIndex >= 0x40 )
  {
    mShaderSelector->mAddState.mFlags[1] |= 1i64 << ((unsigned __int8)mParticleDynamicLightSettingsStateIndex - 64);
  }
  else
  {
    mShaderSelector->mAddState.mFlags[0] |= 1i64 << mParticleDynamicLightSettingsStateIndex;
  }
}

// File Line: 1275
// RVA: 0x1D6740
void __fastcall Render::ParticleEmitterManager::SetSoftSettings(
        Render::ParticleEmitterManager *this,
        Render::View *view,
        Render::ParticleEmitterSettings *pfxSettings)
{
  Illusion::ShaderSelector *mShaderSelector; // rdi
  float *v7; // rax
  float *v8; // rsi
  float *v9; // rbx
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float *p_mFOVOffset; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  UFG::BaseCameraComponent *v15; // rax
  float *v16; // rax
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm6_4
  UFG::BaseCameraComponent *v20; // rax
  float *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  UFG::BaseCameraComponent *v24; // rax
  float *v25; // rax
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm6_4
  UFG::BaseCameraComponent *v29; // rax
  float *v30; // rax
  float v31; // xmm1_4
  float v32; // xmm0_4
  UFG::BaseCameraComponent *v33; // rcx
  float v34; // xmm1_4
  float v35; // xmm0_4
  unsigned int mParticleSoftSettingsStateIndex_low; // ebx
  Illusion::StateValues *StateValues; // rax
  bool v38; // zf
  unsigned int mParticleSoftSettingsStateIndex; // ecx
  float v40; // [rsp+60h] [rbp+8h]

  Render::View::GetStateValues(view);
  mShaderSelector = view->mSubmitContext->mShaderSelector;
  v7 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  *v7 = pfxSettings->mSoftContrast;
  v8 = v7;
  v7[1] = pfxSettings->mSoftScale;
  v7[2] = 1.0 / (float)((float)(int)Render::View::GetTargetWidth(view) * 0.5);
  v8[3] = 1.0 / (float)((float)(int)Render::View::GetTargetHeight(view) * 0.5);
  v9 = 0i64;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
  else
    p_mFOVOffset = 0i64;
  v12 = p_mFOVOffset[58];
  v13 = p_mFOVOffset[59];
  if ( v12 == 0.0 || v12 == v13 )
    v14 = v40;
  else
    v14 = (float)(p_mFOVOffset[62] - p_mFOVOffset[63]) / (float)(v12 - v13);
  v8[4] = v14;
  v15 = UFG::Director::Get()->mCurrentCamera;
  if ( v15 )
    v16 = &v15->mCamera.mFOVOffset;
  else
    v16 = 0i64;
  v17 = v16[58];
  v18 = v16[59];
  if ( v17 == 0.0 || v17 == v18 )
    v19 = v40;
  else
    v19 = (float)(v16[62] - v16[63]) / (float)(v17 - v18);
  v20 = UFG::Director::Get()->mCurrentCamera;
  if ( v20 )
    v21 = &v20->mCamera.mFOVOffset;
  else
    v21 = 0i64;
  v22 = v21[58];
  if ( v22 == 0.0 || v22 == v21[59] )
    v23 = v40;
  else
    v23 = v21[62] / v22;
  v8[5] = v23 * v19;
  v24 = UFG::Director::Get()->mCurrentCamera;
  if ( v24 )
    v25 = &v24->mCamera.mFOVOffset;
  else
    v25 = 0i64;
  v26 = v25[58];
  v27 = v25[59];
  if ( v26 == 0.0 || v26 == v27 )
    v28 = v40;
  else
    v28 = (float)(v25[62] - v25[63]) / (float)(v26 - v27);
  v29 = UFG::Director::Get()->mCurrentCamera;
  if ( v29 )
    v30 = &v29->mCamera.mFOVOffset;
  else
    v30 = 0i64;
  v31 = v30[58];
  if ( v31 == 0.0 || v31 == v30[59] )
    v32 = v40;
  else
    v32 = v30[62] / v31;
  v8[6] = v28 - v32;
  v33 = UFG::Director::Get()->mCurrentCamera;
  if ( v33 )
    v9 = &v33->mCamera.mFOVOffset;
  v34 = v9[58];
  if ( v34 == 0.0 || v34 == v9[59] )
    v35 = v40;
  else
    v35 = v9[62] / v34;
  v8[7] = v35;
  mParticleSoftSettingsStateIndex_low = SLOWORD(this->mParticleSoftSettingsStateIndex);
  StateValues = Render::View::GetStateValues(view);
  if ( mParticleSoftSettingsStateIndex_low >= 0x40 )
    StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mParticleSoftSettingsStateIndex_low - 64);
  else
    StateValues->mSetValueMask.mFlags[0] |= 1i64 << mParticleSoftSettingsStateIndex_low;
  v38 = pfxSettings->mSoftScale == 0.0;
  StateValues->mParamValues[(__int16)mParticleSoftSettingsStateIndex_low] = v8;
  if ( v38 || pfxSettings->mSoftContrast == 0.0 )
  {
    mShaderSelector->mAddState.mFlags[this->mParticleSoftSettingsStateIndex >> 6] &= ~(1i64 << (this->mParticleSoftSettingsStateIndex & 0x3F));
  }
  else
  {
    mParticleSoftSettingsStateIndex = this->mParticleSoftSettingsStateIndex;
    if ( mParticleSoftSettingsStateIndex >= 0x40 )
      mShaderSelector->mAddState.mFlags[1] |= 1i64 << ((unsigned __int8)mParticleSoftSettingsStateIndex - 64);
    else
      mShaderSelector->mAddState.mFlags[0] |= 1i64 << mParticleSoftSettingsStateIndex;
  }
}

// File Line: 1306
// RVA: 0x1D6FE0
void __fastcall Render::ParticleEmitterManager::SetupFlowmap(
        Render::ParticleEmitterManager *this,
        Render::View *view,
        Render::ParticleEmitterSettings *pfxSettings)
{
  UFG::qResourceWarehouse *v6; // rax
  Illusion::ShaderSelector *mShaderSelector; // rdi
  __int64 v8; // rbx
  Illusion::StateValues *StateValues; // rax
  float *v10; // rbx
  unsigned int mParticleFlowMapStateIndex_low; // esi
  Illusion::StateValues *v12; // rax
  unsigned int mParticleFlowMapStateIndex; // ecx

  if ( (_S8_5 & 1) == 0 )
  {
    _S8_5 |= 1u;
    v6 = UFG::qResourceWarehouse::Instance();
    texInventory_2 = UFG::qResourceWarehouse::GetInventory(v6, 0x8B43FABF);
  }
  Render::View::GetStateValues(view);
  mShaderSelector = view->mSubmitContext->mShaderSelector;
  if ( pfxSettings->mFlowmapTextureID )
  {
    v8 = ((__int64 (__fastcall *)(UFG::qResourceInventory *))texInventory_2->vfptr->Get)(texInventory_2);
    StateValues = Render::View::GetStateValues(view);
    StateValues->mSetValueMask.mFlags[1] |= 0x80ui64;
    StateValues->mParamValues[71] = (void *)v8;
    v10 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    *v10 = pfxSettings->mFlowmapSettings.FlowmapConstants[0];
    v10[1] = pfxSettings->mFlowmapSettings.FlowmapConstants[1];
    v10[2] = pfxSettings->mFlowmapSettings.FlowmapConstants[2];
    v10[3] = pfxSettings->mFlowmapSettings.FlowmapConstants[3];
    v10[4] = pfxSettings->mFlowmapSettings.FlowmapDistortOverTimeKeys[0];
    v10[5] = pfxSettings->mFlowmapSettings.FlowmapDistortOverTimeKeys[1];
    v10[6] = pfxSettings->mFlowmapSettings.FlowmapDistortOverTimeKeys[2];
    v10[7] = pfxSettings->mFlowmapSettings.FlowmapDistortOverTimeKeys[3];
    v10[8] = pfxSettings->mFlowmapSettings.FlowmapDistortOverTimeKeyPos[0];
    v10[9] = pfxSettings->mFlowmapSettings.FlowmapDistortOverTimeKeyPos[1];
    v10[10] = pfxSettings->mFlowmapSettings.FlowmapDistortOverTimeKeyPos[2];
    v10[11] = pfxSettings->mFlowmapSettings.FlowmapDistortOverTimeKeyPos[3];
    mParticleFlowMapStateIndex_low = SLOWORD(this->mParticleFlowMapStateIndex);
    v12 = Render::View::GetStateValues(view);
    if ( mParticleFlowMapStateIndex_low >= 0x40 )
      v12->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mParticleFlowMapStateIndex_low - 64);
    else
      v12->mSetValueMask.mFlags[0] |= 1i64 << mParticleFlowMapStateIndex_low;
    v12->mParamValues[(__int16)mParticleFlowMapStateIndex_low] = v10;
    mParticleFlowMapStateIndex = this->mParticleFlowMapStateIndex;
    if ( mParticleFlowMapStateIndex >= 0x40 )
      mShaderSelector->mAddState.mFlags[1] |= 1i64 << ((unsigned __int8)mParticleFlowMapStateIndex - 64);
    else
      mShaderSelector->mAddState.mFlags[0] |= 1i64 << mParticleFlowMapStateIndex;
  }
  else
  {
    mShaderSelector->mAddState.mFlags[this->mParticleFlowMapStateIndex >> 6] &= ~(1i64 << (this->mParticleFlowMapStateIndex & 0x3F));
  }
}

// File Line: 1412
// RVA: 0x1D4AE0
void __fastcall Render::ParticleEmitterManager::Render(
        Render::ParticleEmitterManager *this,
        Render::View *view,
        float fTime,
        Render::eParticleQueue queue,
        Render::FXManagerAuxBuffers *auxBuffers)
{
  char *v7; // r14
  char *v8; // rax
  Render::FXOverride *m_pPointer; // r10
  char *v10; // rbx
  unsigned int mFXOverrideStateParamIndex; // esi
  Illusion::StateValues *StateValues; // rax
  int v13; // ebx
  unsigned int size; // edx
  __int64 v15; // rax
  __int64 v16; // r13
  __int64 v17; // r12
  Render::ParticleEmitterBuffer *v18; // rbx
  UFG::qResourceData *mData; // rsi
  char *v20; // rax
  UFG::qResourceData *v21; // rdx
  char *v22; // r14
  char *v23; // r8
  __int64 v24; // rcx
  __int128 v25; // xmm0
  unsigned int mParticleSettingsStateIndex_low; // ebp
  Illusion::StateValues *v27; // rax
  char *v28; // rax
  unsigned int mFXSizeModuleStateIndex_low; // ebp
  Illusion::StateValues *v30; // rax
  unsigned int mTexHeightmapStateIndex; // ecx
  Illusion::ShaderSelector *mShaderSelector; // r8
  unsigned int v33; // eax
  Illusion::Material *mParticleMaterial; // rsi
  UFG::qBaseNodeRB **mChild; // rcx
  unsigned int v36; // ebp
  __int64 *v37; // rdx
  __int64 v38; // rax
  Illusion::Material *v39; // rcx
  Illusion::Material *v40; // rbx
  _WORD *mOffset; // rax
  __int64 v42; // [rsp+20h] [rbp-58h]
  int v43; // [rsp+80h] [rbp+8h]

  v7 = (char *)(unsigned int)queue;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  m_pPointer = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer;
  v10 = v8;
  *(float *)v8 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer->stateBlock.ColorTint[0];
  *((_DWORD *)v8 + 1) = LODWORD(m_pPointer->stateBlock.ColorTint[1]);
  *((_DWORD *)v8 + 2) = LODWORD(m_pPointer->stateBlock.ColorTint[2]);
  *((_DWORD *)v8 + 3) = LODWORD(m_pPointer->stateBlock.ColorTint[3]);
  *((_DWORD *)v8 + 4) = LODWORD(m_pPointer->stateBlock.Params1[0]);
  *((_DWORD *)v8 + 5) = LODWORD(m_pPointer->stateBlock.Params1[1]);
  *((_DWORD *)v8 + 6) = LODWORD(m_pPointer->stateBlock.Params1[2]);
  *((_DWORD *)v8 + 7) = LODWORD(m_pPointer->stateBlock.Params1[3]);
  mFXOverrideStateParamIndex = Render::gFXManager.mFXOverrideStateParamIndex;
  StateValues = Render::View::GetStateValues(view);
  if ( mFXOverrideStateParamIndex >= 0x40 )
    StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mFXOverrideStateParamIndex - 64);
  else
    StateValues->mSetValueMask.mFlags[0] |= 1i64 << mFXOverrideStateParamIndex;
  StateValues->mParamValues[(__int16)mFXOverrideStateParamIndex] = v10;
  Render::ParticleEmitterManager::KillExpiredBuffers(this, (int)v7, fTime);
  Render::ParticleEmitterManager::DistanceSort(this, view, (Render::eParticleQueue)v7);
  v13 = 0;
  v43 = 0;
  size = this->activeBuffers[(_QWORD)v7].size;
  if ( size )
  {
    v15 = 16i64 * (_QWORD)(v7 + 3);
    v16 = size;
    v42 = v15;
    v17 = 0i64;
    do
    {
      v18 = *(Render::ParticleEmitterBuffer **)(v17 + *(_QWORD *)((char *)&this->mInstanceStateBlockIndex + v15));
      if ( v18->mModel.mData && v18->mCount )
      {
        mData = v18->mCreatorSettings.mData;
        if ( mData )
        {
          v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
          v21 = mData + 1;
          v22 = v20;
          v23 = v20;
          if ( (((unsigned __int8)v20 | (unsigned __int8)((_BYTE)mData + 88)) & 0xF) != 0 )
          {
            memmove(v20, v21, 0xC0ui64);
          }
          else
          {
            v24 = 1i64;
            do
            {
              v25 = *(_OWORD *)&v21->mNode.mParent;
              v23 += 128;
              v21 = (UFG::qResourceData *)((char *)v21 + 128);
              *((_OWORD *)v23 - 8) = v25;
              *((_OWORD *)v23 - 7) = *(_OWORD *)&v21[-2].mDebugName[12];
              *((_OWORD *)v23 - 6) = *(_OWORD *)&v21[-2].mDebugName[28];
              *((_OWORD *)v23 - 5) = *(_OWORD *)v21[-1].mNode.mChild;
              *((_OWORD *)v23 - 4) = *(_OWORD *)&v21[-1].mNode.mUID;
              *((_OWORD *)v23 - 3) = *(_OWORD *)&v21[-1].mResourceHandles.mNode.mNext;
              *((_OWORD *)v23 - 2) = *(_OWORD *)&v21[-1].mDebugName[4];
              *((_OWORD *)v23 - 1) = *(_OWORD *)&v21[-1].mDebugName[20];
              --v24;
            }
            while ( v24 );
            *(_OWORD *)v23 = *(_OWORD *)&v21->mNode.mParent;
            *((_OWORD *)v23 + 1) = *(_OWORD *)&v21->mNode.mChild[1];
            *((_OWORD *)v23 + 2) = v21->mResourceHandles;
            *((_OWORD *)v23 + 3) = *(_OWORD *)&v21->mTypeUID;
          }
          mParticleSettingsStateIndex_low = SLOWORD(this->mParticleSettingsStateIndex);
          v27 = Render::View::GetStateValues(view);
          if ( mParticleSettingsStateIndex_low >= 0x40 )
            v27->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mParticleSettingsStateIndex_low - 64);
          else
            v27->mSetValueMask.mFlags[0] |= 1i64 << mParticleSettingsStateIndex_low;
          v27->mParamValues[(__int16)mParticleSettingsStateIndex_low] = v22;
          v28 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
          *(_DWORD *)v28 = mData[3].mNode.mChild[1];
          v7 = v28;
          *((_DWORD *)v28 + 1) = HIDWORD(mData[3].mNode.mChild[1]);
          *((_DWORD *)v28 + 2) = mData[3].mNode.mUID;
          *((_DWORD *)v28 + 3) = *(&mData[3].mNode.mUID + 1);
          *((_DWORD *)v28 + 4) = mData[3].mResourceHandles.mNode.mPrev;
          *((_DWORD *)v28 + 5) = HIDWORD(mData[3].mResourceHandles.mNode.mPrev);
          *((_DWORD *)v28 + 6) = mData[3].mResourceHandles.mNode.mNext;
          *((_DWORD *)v28 + 7) = HIDWORD(mData[3].mResourceHandles.mNode.mNext);
          *((_DWORD *)v28 + 8) = mData[3].mTypeUID;
          *((_DWORD *)v28 + 9) = *(_DWORD *)mData[3].mDebugName;
          *((_DWORD *)v28 + 10) = *(_DWORD *)&mData[3].mDebugName[4];
          *((_DWORD *)v28 + 11) = *(_DWORD *)&mData[3].mDebugName[8];
          *((_DWORD *)v28 + 12) = *(_DWORD *)&mData[3].mDebugName[12];
          *((_DWORD *)v28 + 13) = *(_DWORD *)&mData[3].mDebugName[16];
          *((_DWORD *)v28 + 14) = *(_DWORD *)&mData[3].mDebugName[20];
          *((_DWORD *)v28 + 15) = *(_DWORD *)&mData[3].mDebugName[24];
          mFXSizeModuleStateIndex_low = SLOWORD(this->mFXSizeModuleStateIndex);
          v30 = Render::View::GetStateValues(view);
          if ( mFXSizeModuleStateIndex_low >= 0x40 )
            v30->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mFXSizeModuleStateIndex_low - 64);
          else
            v30->mSetValueMask.mFlags[0] |= 1i64 << mFXSizeModuleStateIndex_low;
          v30->mParamValues[(__int16)mFXSizeModuleStateIndex_low] = v7;
          LODWORD(v7) = queue;
          Render::ParticleEmitterManager::SetAuxBuffers(this, view, queue, auxBuffers);
          Render::ParticleEmitterManager::SetSoftSettings(this, view, (Render::ParticleEmitterSettings *)mData);
          Render::ParticleEmitterManager::SetupLighting(this, view, (Render::ParticleEmitterSettings *)mData);
          Render::ParticleEmitterManager::SetupFlowmap(this, view, (Render::ParticleEmitterSettings *)mData);
          mTexHeightmapStateIndex = this->mTexHeightmapStateIndex;
          mShaderSelector = view->mSubmitContext->mShaderSelector;
          if ( mData[4].mDebugName[20] >= 0 )
          {
            mShaderSelector->mAddState.mFlags[mTexHeightmapStateIndex >> 6] &= ~(1i64 << (mTexHeightmapStateIndex & 0x3F));
          }
          else if ( mTexHeightmapStateIndex >= 0x40 )
          {
            mShaderSelector->mAddState.mFlags[1] |= 1i64 << ((unsigned __int8)mTexHeightmapStateIndex - 64);
          }
          else
          {
            mShaderSelector->mAddState.mFlags[0] |= 1i64 << mTexHeightmapStateIndex;
          }
        }
        v43 += v18->mCount;
        v33 = Render::ParticleEmitterManager::SetTexShadowAtlas(this, v18->mParticleMaterial, auxBuffers);
        mParticleMaterial = v18->mParticleMaterial;
        mChild = v18->mModel.mData[2].mNode.mChild;
        v36 = v33;
        if ( *mChild )
          v37 = (__int64 *)((char *)mChild + (_QWORD)*mChild);
        else
          v37 = 0i64;
        v38 = *v37;
        if ( *v37 )
          v38 += (__int64)v37;
        if ( *(_DWORD *)(v38 + 224) == 3 )
        {
          v39 = *(Illusion::Material **)(v38 + 16);
          if ( v39 )
          {
            mParticleMaterial = *(Illusion::Material **)(v38 + 16);
            Render::MapGeoMaterialState(v39, (Render::eParticleQueue)v7);
          }
        }
        Render::ParticleEmitterBuffer::Draw(v18, view, mParticleMaterial);
        if ( v36 != -1 )
        {
          v40 = v18->mParticleMaterial;
          if ( LODWORD(v40[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != v36 )
          {
            UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v40[1].mNode.mChild[1], v40[1].mTypeUID, v36);
            mOffset = (_WORD *)v40->mMaterialUser.mOffset;
            if ( mOffset )
              mOffset = (_WORD *)((char *)mOffset + (_QWORD)v40 + 120);
            *mOffset |= 0x20u;
          }
        }
      }
      v15 = v42;
      v17 += 8i64;
      --v16;
    }
    while ( v16 );
    v13 = v43;
  }
  Render::View::AddMetric_NumParticles(view, v13);
  this->mRunningParticleCount += v13;
}

// File Line: 1514
// RVA: 0x1CB280
bool __fastcall Render::ParticleEmitterManager::DistanceCompare(
        Render::ParticleEmitterBuffer *const *a,
        Render::ParticleEmitterBuffer *const *b)
{
  __int64 v2; // r8
  __int64 v3; // r9
  unsigned int mParentFXId; // ecx
  unsigned int v5; // edx
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  unsigned int v10; // ecx
  unsigned int v11; // edx
  bool v12; // cf

  v2 = (__int64)*a;
  v3 = (__int64)*b;
  mParentFXId = (*a)->mParentFXId;
  v5 = (*b)->mParentFXId;
  v6 = (float)((float)((float)(*(float *)(v2 + 252) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y)
                     * (float)(*(float *)(v2 + 252) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y))
             + (float)((float)(*(float *)(v2 + 248) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x)
                     * (float)(*(float *)(v2 + 248) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x)))
     + (float)((float)(*(float *)(v2 + 256) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z)
             * (float)(*(float *)(v2 + 256) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z));
  v7 = (float)((float)((float)(*(float *)(v3 + 252) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y)
                     * (float)(*(float *)(v3 + 252) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y))
             + (float)((float)(*(float *)(v3 + 248) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x)
                     * (float)(*(float *)(v3 + 248) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x)))
     + (float)((float)(*(float *)(v3 + 256) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z)
             * (float)(*(float *)(v3 + 256) - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z));
  if ( mParentFXId == v5 )
  {
    v10 = *(_DWORD *)(v2 + 168);
    v11 = *(_DWORD *)(v3 + 168);
    v12 = v10 < v11;
    if ( v10 == v11 )
      return *(float *)(v3 + 44) < *(float *)(v2 + 44);
  }
  else
  {
    v8 = v7 - v6;
    if ( (float)(v7 - v6) < 0.0 )
      LODWORD(v8) ^= _xmm[0];
    if ( v8 >= 0.1 )
      return v6 > v7;
    return mParentFXId < v5;
  }
  return v12;
}

// File Line: 1553
// RVA: 0x1D15D0
void __fastcall Render::ParticleEmitterManager::KillExpiredBuffers(
        Render::ParticleEmitterManager *this,
        int queue_index,
        float fTime)
{
  __int64 v4; // rbp
  unsigned int size; // r12d
  __int64 v6; // r13
  Render::ParticleEmitterBuffer *v7; // r14
  Render::ParticleRaycaster *mRaycaster; // rax
  unsigned int v9; // eax
  Render::ParticleRaycaster *v10; // rax
  __int64 v11; // r15
  unsigned int capacity; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  Render::ParticleEmitterBuffer **p; // rax
  unsigned int v16; // edx
  unsigned int v17; // ebx
  unsigned int v18; // edx
  int v19; // [rsp+68h] [rbp+10h]

  v19 = queue_index;
  v4 = 0i64;
  size = this->activeBuffers[queue_index].size;
  if ( size )
  {
    v6 = 2 * (queue_index + 3i64);
    do
    {
      if ( fTime > *(float *)(*(_QWORD *)(*((_QWORD *)&this->mInstanceStateBlockIndex + v6) + 8 * v4) + 40i64) )
      {
        v7 = this->activeBuffers[queue_index].p[v4];
        mRaycaster = v7->mRaycaster;
        if ( mRaycaster )
          mRaycaster->mMode = 4;
        this->activeBuffers[queue_index].p[v4] = this->activeBuffers[queue_index].p[this->activeBuffers[queue_index].size
                                                                                  - 1];
        v9 = this->activeBuffers[queue_index].size;
        if ( v9 > 1 )
          this->activeBuffers[queue_index].size = v9 - 1;
        else
          this->activeBuffers[queue_index].size = 0;
        v10 = v7->mRaycaster;
        if ( v10 )
          v10->mMode = 4;
        Render::ParticleEmitterBuffer::Deactivate(v7);
        if ( v7->mCapacity == 32 )
        {
          v11 = this->freeBuffersLarge.size;
          capacity = this->freeBuffersLarge.capacity;
          v13 = v11 + 1;
          if ( (int)v11 + 1 > capacity )
          {
            if ( capacity )
              v14 = 2 * capacity;
            else
              v14 = 1;
            for ( ; v14 < v13; v14 *= 2 )
              ;
            if ( v14 <= 2 )
              v14 = 2;
            if ( v14 - v13 > 0x10000 )
              v14 = v11 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->freeBuffersLarge,
              v14,
              "qArray.Add");
          }
          p = this->freeBuffersLarge.p;
          this->freeBuffersLarge.size = v13;
        }
        else
        {
          v11 = this->freeBuffersSmall.size;
          v16 = this->freeBuffersSmall.capacity;
          v17 = v11 + 1;
          if ( (int)v11 + 1 > v16 )
          {
            if ( v16 )
              v18 = 2 * v16;
            else
              v18 = 1;
            for ( ; v18 < v17; v18 *= 2 )
              ;
            if ( v18 <= 2 )
              v18 = 2;
            if ( v18 - v17 > 0x10000 )
              v18 = v11 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->freeBuffersSmall,
              v18,
              "qArray.Add");
          }
          p = this->freeBuffersSmall.p;
          this->freeBuffersSmall.size = v17;
        }
        queue_index = v19;
        LODWORD(v4) = v4 - 1;
        p[v11] = v7;
        --size;
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < size );
  }
}

// File Line: 1571
// RVA: 0x1D1430
void __fastcall Render::ParticleEmitterManager::KillBuffersWithParent(
        Render::ParticleEmitterManager *this,
        unsigned int parentFXId)
{
  Render::ParticleEmitterBuffer ***p_p; // r14
  unsigned int i; // ebp
  unsigned int v6; // esi
  unsigned int j; // ebx
  Render::ParticleEmitterBuffer *v8; // rdi
  UFG::qTask *task; // rdx
  float mExpiry; // xmm6_4
  Render::ParticleRenderUpdateTaskOutputParam *outputParam; // rax
  Render::ParticleRenderUpdateTaskParam *inputParam; // rax

  p_p = &this->activeBuffers[0].p;
  for ( i = 0; i < 3; ++i )
  {
    v6 = *((_DWORD *)p_p - 2);
    for ( j = 0; j < v6; ++j )
    {
      v8 = (*p_p)[j];
      if ( v8->mParentFXId == parentFXId )
      {
        task = v8->mTaskInfo.task;
        if ( task )
        {
          mExpiry = v8->mExpiry;
          UFG::qTaskManager::Sync(&UFG::gTaskManager, task);
          outputParam = v8->mTaskInfo.outputParam;
          if ( mExpiry < outputParam->lastExpiry )
            mExpiry = outputParam->lastExpiry;
          v8->mCount = outputParam->numParticlesInBuffer;
          inputParam = v8->mTaskInfo.inputParam;
          v8->mTaskInfo.instance = 0i64;
          v8->mTaskInfo.task = 0i64;
          inputParam->currentAddCount = 0;
          UFG::qMemSet(v8->mTaskInfo.outputParam, 0, 8u);
          v8->mExpiry = mExpiry;
        }
        Render::ParticleEmitterManager::AddToFreeBufferList(this, i, j--);
        --v6;
      }
    }
    p_p += 2;
  }
}

// File Line: 1716
// RVA: 0x1CB380
void __fastcall Render::ParticleEmitterManager::DistanceSort(
        Render::ParticleEmitterManager *this,
        Render::View *view,
        Render::eParticleQueue queue)
{
  float y; // xmm1_4
  float z; // xmm2_4
  signed int size; // edx
  Render::ParticleEmitterBuffer **p; // rsi
  __int64 v7; // rax
  __int64 v8; // r15
  Render::ParticleEmitterBuffer **v9; // r12
  int v10; // ebp
  Render::ParticleEmitterBuffer *v11; // r13
  int v12; // edi
  __int64 v13; // rbx
  Render::ParticleEmitterBuffer *v14; // rax
  __int64 v15; // [rsp+60h] [rbp+8h]
  Render::ParticleEmitterBuffer *a; // [rsp+68h] [rbp+10h] BYREF

  y = view->mViewWorld.v3.y;
  z = view->mViewWorld.v3.z;
  Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x = view->mViewWorld.v3.x;
  Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y = y;
  Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z = z;
  size = this->activeBuffers[queue].size;
  if ( size )
  {
    p = this->activeBuffers[queue].p;
    if ( size > 1 )
    {
      v7 = (unsigned int)(size - 1);
      v8 = 0i64;
      v9 = p + 1;
      v15 = v7;
      v10 = 0;
      do
      {
        v11 = *v9;
        v12 = v10;
        v13 = v8;
        a = *v9;
        if ( v10 >= 0 )
        {
          do
          {
            if ( !Render::ParticleEmitterManager::DistanceCompare(&a, &p[v12]) )
              break;
            v14 = p[v13--];
            --v12;
            p[v13 + 2] = v14;
          }
          while ( v12 >= 0 );
          v7 = v15;
        }
        ++v10;
        ++v9;
        ++v8;
        --v7;
        p[v13 + 1] = v11;
        v15 = v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 1746
// RVA: 0x1D8390
void __fastcall Render::ParticleEmitterManager::StartTasks(
        Render::ParticleEmitterManager *this,
        float simTime,
        float deltaTime,
        Render::FXManagerLights *lightList)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::qVector3 *cameraPos; // r12
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *activeBuffers; // rsi
  __int64 v9; // r15
  __int64 i; // rbx
  Render::ParticleEmitterBuffer *v11; // rbp
  Illusion::Buffer *v12; // rax
  Illusion::Buffer *v13; // rdi
  __int64 mOffset; // rax
  char *v15; // r9

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
  cameraPos = (UFG::qVector3 *)&mCurrentCamera->mCamera.mView.v2;
  activeBuffers = this->activeBuffers;
  v9 = 3i64;
  do
  {
    for ( i = 0i64; (unsigned int)i < activeBuffers->size; i = (unsigned int)(i + 1) )
    {
      v11 = activeBuffers->p[i];
      v12 = Render::ParticleEmitterBuffer::FrameMallocAttributeBuffer(v11);
      v13 = v12;
      if ( v12 )
      {
        Illusion::Buffer::OnLoad(v12);
        mOffset = v13->mData.mOffset;
        if ( mOffset )
          v15 = (char *)&v13->mData + mOffset;
        else
          v15 = 0i64;
        Render::ParticleEmitterBuffer::TaskInfo::Start(
          &v11->mTaskInfo,
          (Render::ParticleEmitterSettings *)v11->mCreatorSettings.mData,
          v11,
          v15,
          cameraPos,
          simTime,
          deltaTime,
          lightList);
      }
      ++this->mNumActiveTasks;
    }
    ++activeBuffers;
    --v9;
  }
  while ( v9 );
}

// File Line: 1784
// RVA: 0x1D86D0
void __fastcall Render::ParticleEmitterManager::SyncTasks(Render::ParticleEmitterManager *this)
{
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *activeBuffers; // rdi
  __int64 v3; // r14
  unsigned int i; // esi
  Render::ParticleEmitterBuffer *v5; // rbx
  float mExpiry; // xmm6_4
  Render::ParticleRenderUpdateTaskOutputParam *outputParam; // rax
  Render::ParticleRenderUpdateTaskParam *inputParam; // rax

  activeBuffers = this->activeBuffers;
  v3 = 3i64;
  do
  {
    for ( i = 0; i < activeBuffers->size; --this->mNumActiveTasks )
    {
      v5 = activeBuffers->p[i];
      mExpiry = v5->mExpiry;
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v5->mTaskInfo.task);
      outputParam = v5->mTaskInfo.outputParam;
      if ( mExpiry < outputParam->lastExpiry )
        mExpiry = outputParam->lastExpiry;
      v5->mCount = outputParam->numParticlesInBuffer;
      inputParam = v5->mTaskInfo.inputParam;
      v5->mTaskInfo.instance = 0i64;
      v5->mTaskInfo.task = 0i64;
      inputParam->currentAddCount = 0;
      UFG::qMemSet(v5->mTaskInfo.outputParam, 0, 8u);
      ++i;
      v5->mExpiry = mExpiry;
    }
    ++activeBuffers;
    --v3;
  }
  while ( v3 );
}

