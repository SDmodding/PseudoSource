// File Line: 91
// RVA: 0x1CF1A0
void __fastcall Render::ParticleEmitterBuffer::Init(Render::ParticleEmitterBuffer *this, unsigned int numElements)
{
  Render::ParticleEmitterBuffer *v2; // rsi
  Render::ParticleRaycaster *v3; // rbp
  unsigned int v4; // ebx
  int v5; // edx
  unsigned int v6; // eax
  int v7; // edx
  unsigned int v8; // eax
  int v9; // edi
  Illusion::Material *v10; // rbx
  int v11; // edi
  Illusion::Material *v12; // rbx
  unsigned int v13; // edi
  Illusion::Material *v14; // rbx
  int v15; // edi
  Illusion::Material *v16; // rbx
  Illusion::Material *v17; // rbx
  Illusion::Material *v18; // rbx
  UFG::qResourceWarehouse *v19; // rax
  UFG::allocator::free_link *v20; // rax
  Render::ParticleRaycaster *v21; // rax
  UFG::qString result; // [rsp+38h] [rbp-60h]
  UFG::qString v23; // [rsp+60h] [rbp-38h]

  v2 = this;
  v3 = 0i64;
  this->mCount = 0;
  this->mCapacity = numElements;
  this->mSettingsId = -1;
  v4 = 84 * numElements;
  UFG::qString::FormatEx(&v23, "ParticleBuffer%p.AttributeBuffer", this);
  v6 = v23.mStringHashUpper32;
  if ( v23.mStringHashUpper32 == -1 )
  {
    v6 = UFG::qStringHashUpper32(v23.mData, v23.mStringHashUpper32 | v5);
    v23.mStringHashUpper32 = v6;
  }
  v2->mAttributeBufferUID = v6;
  v2->mCPUAttributes = (Render::EmitterParticleAttribute *)UFG::qMalloc(
                                                             v4,
                                                             "ParticleEmitterBuffer::mCPUAttributes",
                                                             0x1000ui64);
  UFG::qString::FormatEx(&result, "ParticleSystem_%p.Material", v2);
  v8 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    v8 = UFG::qStringHash32(result.mData, result.mStringHash32 | v7);
    result.mStringHash32 = v8;
  }
  v2->mParticleMaterial = Illusion::Factory::NewMaterial(result.mData, v8, 6u, 0i64, 0i64, 0i64);
  v9 = UFG::qStringHash32("PARTICLE", 0xFFFFFFFF);
  v10 = v2->mParticleMaterial;
  LOWORD(v10[1].mNode.mChild[0]) = 0;
  HIDWORD(v10[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v10[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v10[1].mTypeUID = -1957338719;
  LODWORD(v10[1].mResourceHandles.mNode.mNext) = v9;
  v11 = UFG::qStringHash32("TEST_SPRITE", 0xFFFFFFFF);
  v12 = v2->mParticleMaterial;
  *(_WORD *)&v12[1].mDebugName[12] = 0;
  *(_DWORD *)&v12[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v12[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v12[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v12[1].mStateBlockMask.mFlags[0]) = v11;
  v13 = UFG::qStringHash32("DEFAULTNORMALMAP", 0xFFFFFFFF);
  v14 = v2->mParticleMaterial;
  LOWORD(v14[1].mMaterialUser.mOffset) = 0;
  *(&v14[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v14[1].mNumParams = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v14[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v14[2].mNode.mUID = v13;
  v15 = UFG::qStringHash32("DEFAULTBUMPMAP", 0xFFFFFFFF);
  v16 = v2->mParticleMaterial;
  LOWORD(v16[2].mTypeUID) = 0;
  HIDWORD(v16[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v16[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texReflection", 0xFFFFFFFF);
  *((_DWORD *)&v16[2].0 + 22) = -1958479169;
  *(_DWORD *)&v16[2].mDebugName[28] = v15;
  v17 = v2->mParticleMaterial;
  LOWORD(v17[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v17[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v17[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v17[3].mNode.mChild[1]) = 315097330;
  LODWORD(v17[3].mNode.mChild[0]) = 0;
  v18 = v2->mParticleMaterial;
  LOWORD(v18[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v18[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v18[3].mNode.mUID = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v18[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v18[3].mDebugName[12] = 1099738947;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, (UFG::qResourceData *)&v2->mParticleMaterial->mNode);
  UFG::qString::~qString(&result);
  v20 = UFG::qMalloc(0x20ui64, "ParticleEmitterBuffer::Raycaster", 0i64);
  if ( v20 )
  {
    Render::ParticleRaycaster::ParticleRaycaster((Render::ParticleRaycaster *)v20);
    v3 = v21;
  }
  v2->mRaycaster = v3;
  UFG::qString::~qString(&v23);
}

// File Line: 142
// RVA: 0x1CB4B0
void __fastcall Render::ParticleEmitterBuffer::Draw(Render::ParticleEmitterBuffer *this, Render::View *view, Illusion::Material *materialOverride)
{
  Render::View *v3; // rbp
  Render::ParticleEmitterBuffer *v4; // rdi
  Illusion::Mesh *v5; // rsi
  UFG::qBaseNodeRB **v6; // rax
  _QWORD *v7; // rcx
  char *v8; // rax
  Render::FXOverride *v9; // rdx
  char *v10; // r14
  unsigned int v11; // er12
  Illusion::StateValues *v12; // rax
  char *debug_name; // ST30_8
  char *v14; // rax
  Render::FXOverride *v15; // rdx
  char *v16; // rdi
  unsigned int v17; // esi
  Illusion::StateValues *v18; // rax
  UFG::qMatrix44 v19; // [rsp+40h] [rbp-58h]

  v3 = view;
  v4 = this;
  if ( this->mRenderAttributeBuffer )
  {
    Render::ParticleEmitterBuffer::GetRenderMatrix(this, &v19);
    v5 = 0i64;
    v6 = v4->mModel.mData[2].mNode.mChild;
    if ( *v6 )
      v7 = (UFG::qBaseNodeRB **)((char *)&(*v6)->mParent + (_QWORD)v6);
    else
      v7 = 0i64;
    if ( *v7 )
      v5 = (Illusion::Mesh *)((char *)v7 + *v7);
    if ( v4->mFXOverridePointer.m_pPointer )
    {
      v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
      v9 = v4->mFXOverridePointer.m_pPointer;
      v10 = v8;
      *(float *)v8 = v9->stateBlock.ColorTint[0];
      *((_DWORD *)v8 + 1) = LODWORD(v9->stateBlock.ColorTint[1]);
      *((_DWORD *)v8 + 2) = LODWORD(v9->stateBlock.ColorTint[2]);
      *((_DWORD *)v8 + 3) = LODWORD(v9->stateBlock.ColorTint[3]);
      *((_DWORD *)v8 + 4) = LODWORD(v9->stateBlock.Params1[0]);
      *((_DWORD *)v8 + 5) = LODWORD(v9->stateBlock.Params1[1]);
      *((_DWORD *)v8 + 6) = LODWORD(v9->stateBlock.Params1[2]);
      *((_DWORD *)v8 + 7) = LODWORD(v9->stateBlock.Params1[3]);
      v11 = Render::gFXManager.mFXOverrideStateParamIndex;
      v12 = Render::View::GetStateValues(v3);
      if ( v11 >= 0x40 )
        v12->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v11 - 64);
      else
        v12->mSetValueMask.mFlags[0] |= 1i64 << v11;
      v12->mParamValues[(signed __int16)v11] = v10;
    }
    debug_name = (char *)v4->mDescription;
    Render::View::DrawInstanced(v3, v5, v4->mRenderAttributeBuffer, v4->mCount);
    if ( v4->mFXOverridePointer.m_pPointer )
    {
      v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
      v15 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer;
      v16 = v14;
      *(float *)v14 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer->stateBlock.ColorTint[0];
      *((_DWORD *)v14 + 1) = LODWORD(v15->stateBlock.ColorTint[1]);
      *((_DWORD *)v14 + 2) = LODWORD(v15->stateBlock.ColorTint[2]);
      *((_DWORD *)v14 + 3) = LODWORD(v15->stateBlock.ColorTint[3]);
      *((_DWORD *)v14 + 4) = LODWORD(v15->stateBlock.Params1[0]);
      *((_DWORD *)v14 + 5) = LODWORD(v15->stateBlock.Params1[1]);
      *((_DWORD *)v14 + 6) = LODWORD(v15->stateBlock.Params1[2]);
      *((_DWORD *)v14 + 7) = LODWORD(v15->stateBlock.Params1[3]);
      v17 = Render::gFXManager.mFXOverrideStateParamIndex;
      v18 = Render::View::GetStateValues(v3);
      if ( v17 >= 0x40 )
        v18->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v17 - 64);
      else
        v18->mSetValueMask.mFlags[0] |= 1i64 << v17;
      v18->mParamValues[(signed __int16)v17] = v16;
    }
  }
}

// File Line: 168
// RVA: 0x1CBDF0
Illusion::Buffer *__fastcall Render::ParticleEmitterBuffer::FrameMallocAttributeBuffer(Render::ParticleEmitterBuffer *this)
{
  Render::ParticleEmitterBuffer *v1; // rbx
  char *v2; // rdi
  Illusion::Buffer *v4; // rax

  v1 = this;
  v2 = UFG::qLinearAllocator::Malloc(
         Illusion::gEngine.FrameWriteMemory,
         (84 * this->mCapacity + 127) & 0xFFFFFF7F,
         0x10u);
  if ( !v2 )
    return 0i64;
  v4 = Illusion::Factory::NewBuffer(
         "ParticleBuffer.AttributeBuffer",
         v1->mAttributeBufferUID,
         0,
         0i64,
         "ParticleBuffer::AttributeBuffer",
         Illusion::gEngine.FrameMemory,
         0i64);
  v1->mRenderAttributeBuffer = v4;
  if ( !v4 )
    return 0i64;
  v4->mData.mOffset = v2 - (char *)&v4->mData;
  v1->mRenderAttributeBuffer->mDataByteSize = 84 * v1->mCapacity;
  v1->mRenderAttributeBuffer->mBufferType = 2;
  v1->mRenderAttributeBuffer->mElementByteSize = 84;
  v1->mRenderAttributeBuffer->mNumElements = v1->mCapacity;
  v1->mRenderAttributeBuffer->mFlags |= 4u;
  return v1->mRenderAttributeBuffer;
}

// File Line: 260
// RVA: 0x1CAB90
void __fastcall Render::ParticleEmitterBuffer::Deactivate(Render::ParticleEmitterBuffer *this)
{
  UFG::qResourceInventory *v1; // rax
  Render::ParticleEmitterBuffer *v2; // rbx
  UFG::qResourceWarehouse *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  Render::ParticleEmitterInstance *v7; // rax
  Render::ParticleEmitterBuffer *v8; // rcx
  Render::FXOverride *v9; // rax
  Render::FXOverride *v10; // rdi
  Render::FXOverride::PrecalculatedTriangle *v11; // rdx

  v1 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  v2 = this;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v3, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v1;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mModelToEmitFrom.mPrev, v1);
  v4 = v2->mParent;
  if ( v4->m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
  v7 = v2->mOwner;
  if ( v7 )
  {
    v8 = v7->mCurrentBuffer;
    if ( v8 )
    {
      v8->mOwner = 0i64;
      v7->mCurrentBuffer = 0i64;
    }
    v2->mOwner = 0i64;
  }
  v9 = v2->mFXOverridePointer.m_pPointer;
  if ( v9 )
  {
    --v9->mReferenceCount;
    v10 = v2->mFXOverridePointer.m_pPointer;
    if ( v10->mReferenceCount <= 0 )
    {
      if ( v10 )
      {
        v11 = v10->mTriangleInfo;
        if ( v11 )
          UFG::qMemoryPool::Free(v10->mMemoryPool, v11);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v10);
      }
      v2->mFXOverridePointer.m_pPointer = 0i64;
    }
    v2->mFXOverridePointer.m_pPointer = 0i64;
  }
}

// File Line: 307
// RVA: 0x1C5DE0
void __fastcall Render::ParticleEmitterBuffer::Activate(Render::ParticleEmitterBuffer *this, float in_creationTime, Render::ParticleEmitterInstance *owner, Render::ParticleEmitterSettings *pfx, Render::FXInstance *container, UFG::qMatrix44 *prevBasis)
{
  Render::ParticleEmitterBuffer *v6; // rdi
  Render::ParticleEmitterSettings *v7; // rbx
  Render::ParticleEmitterInstance *v8; // r15
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  unsigned int v12; // esi
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax
  Render::FXOverride *v15; // rax
  unsigned int v16; // esi
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceInventory *v19; // rax
  unsigned int v20; // esi
  UFG::qResourceWarehouse *v21; // rax
  Illusion::Material *v22; // rsi
  unsigned int v23; // er8
  __int64 v24; // rax
  _WORD *v25; // rax
  Illusion::Material *v26; // rsi
  unsigned int v27; // er8
  __int64 v28; // rax
  _WORD *v29; // rax
  Illusion::Material *v30; // rsi
  unsigned int v31; // er8
  __int64 v32; // rax
  _WORD *v33; // rax
  Illusion::Material *v34; // rsi
  unsigned int v35; // er8
  __int64 v36; // rax
  _WORD *v37; // rax
  Illusion::Material *v38; // rsi
  int v39; // ecx
  unsigned int v40; // er8
  signed int v41; // eax
  bool v42; // zf
  __int64 v43; // rax
  _WORD *v44; // rax
  Illusion::Material *v45; // rsi
  unsigned int v46; // er8
  __int64 v47; // rax
  _WORD *v48; // rax
  UFG::SimComponent *v49; // rsi
  UFG::qMatrix44 *v50; // rsi
  UFG::qVector4 v51; // xmm3
  UFG::qVector4 v52; // xmm2
  UFG::qVector4 v53; // xmm1
  UFG::qVector4 v54; // xmm0
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v55; // rdx
  UFG::SimComponent *v56; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v57; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v58; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v59; // rax
  float v60; // xmm0_4
  float v61; // xmm1_4
  UFG::qResourceInventory *v62; // rax
  unsigned int v63; // esi
  UFG::qResourceWarehouse *v64; // rax
  char v65; // bl
  Render::ParticleRaycaster *v66; // rax
  float v67; // xmm1_4
  float v68; // xmm2_4
  UFG::qMatrix44 out_mat; // [rsp+20h] [rbp-68h]

  v6 = this;
  v7 = pfx;
  v8 = owner;
  FX::SharedPointer<Render::FXOverride>::Set(&this->mFXOverridePointer, container->mStateBlockOverride.m_pPointer);
  v6->mExpiry = 0.0;
  *(_QWORD *)&v6->mCreationTime = LODWORD(in_creationTime);
  v6->mSplitScreenViewMask = v8->mContainer->mSplitScreenViewMask;
  v9 = v6->mParent;
  if ( v9->m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v9->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v9->m_pPointer = 0i64;
  UFG::qMemSet(v6->mTaskInfo.inputParam, 0, 0x270u);
  UFG::qMemSet(v6->mTaskInfo.outputParam, 0, 8u);
  v6->mTaskInfo.instance = 0i64;
  v6->mTaskInfo.task = 0i64;
  v6->mOwner = v8;
  v6->mDescription = v7->mDebugName;
  v12 = v7->mModelToEmitFromUID;
  if ( v12 )
  {
    v13 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v14 = UFG::qResourceWarehouse::Instance();
      v13 = UFG::qResourceWarehouse::GetInventory(v14, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v13;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mModelToEmitFrom.mPrev, 0xA2ADCD77, v12, v13);
  }
  v15 = v6->mFXOverridePointer.m_pPointer;
  if ( v15 )
  {
    v16 = v15->modelToEmitFromUID;
    if ( v16 != -1 )
    {
      v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v18 = UFG::qResourceWarehouse::Instance();
        v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mModelToEmitFrom.mPrev, 0xA2ADCD77, v16, v17);
    }
  }
  v19 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  v20 = v7->mModel.mNameUID;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v21 = UFG::qResourceWarehouse::Instance();
    v19 = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v19;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mModel.mPrev, 0xA2ADCD77, v20, v19);
  if ( v7->mType != 2 )
  {
    v22 = v6->mParticleMaterial;
    v23 = v7->mShaderID;
    if ( LODWORD(v22[1].mResourceHandles.mNode.mNext) != v23 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v22[1].mNode.mChild[1], v22[1].mTypeUID, v23);
      v24 = v22->mMaterialUser.mOffset;
      if ( v24 )
        v25 = (_WORD *)((char *)&v22->mMaterialUser + v24);
      else
        v25 = 0i64;
      *v25 |= 0x20u;
    }
    v26 = v6->mParticleMaterial;
    v27 = v7->mTextureID;
    if ( LODWORD(v26[1].mStateBlockMask.mFlags[0]) != v27 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v26[1].mDebugName[20], v26[1].mStateBlockMask.mFlags[1], v27);
      v28 = v26->mMaterialUser.mOffset;
      if ( v28 )
        v29 = (_WORD *)((char *)&v26->mMaterialUser + v28);
      else
        v29 = 0i64;
      *v29 |= 0x20u;
    }
    v30 = v6->mParticleMaterial;
    v31 = v7->mNormalTextureID;
    if ( v30[2].mNode.mUID != v31 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v30[2],
        (unsigned int)v30[2].mResourceHandles.mNode.mPrev,
        v31);
      v32 = v30->mMaterialUser.mOffset;
      if ( v32 )
        v33 = (_WORD *)((char *)&v30->mMaterialUser + v32);
      else
        v33 = 0i64;
      *v33 |= 0x20u;
    }
    v34 = v6->mParticleMaterial;
    v35 = v7->mReflectionMapTextureID;
    if ( *(_DWORD *)&v34[2].mDebugName[28] != v35 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v34[2].mDebugName[4], *((_DWORD *)&v34[2].0 + 22), v35);
      v36 = v34->mMaterialUser.mOffset;
      if ( v36 )
        v37 = (_WORD *)((char *)&v34->mMaterialUser + v36);
      else
        v37 = 0i64;
      *v37 |= 0x20u;
    }
    v38 = v6->mParticleMaterial;
    v39 = *(_DWORD *)(*((_QWORD *)&v38[1].0 + 11) + 108i64);
    if ( v7->mDrawType == 1 )
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
        v45 = v6->mParticleMaterial;
        v46 = 1099738947;
        if ( !v7->mDrawType )
          v46 = -1810908948;
        if ( *(_DWORD *)&v45[3].mDebugName[12] != v46 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v45[3].mResourceHandles.mNode.mNext,
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
      v40 = *(_DWORD *)(*((_QWORD *)&v38[1].0 + 11) + 108i64);
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
    v50 = &container->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)container->mParentNode.m_pPointer);
    v50 = (UFG::qMatrix44 *)&v49[2];
  }
  if ( v7->mSpace == 1 )
  {
    v6->mCalcBasis = Render::FXInstance::CalcBasisHelper;
    v51 = prevBasis->v1;
    v52 = prevBasis->v2;
    v53 = prevBasis->v3;
    v54 = prevBasis->v0;
  }
  else
  {
    v6->mCalcBasis = 0i64;
    v51 = v50->v1;
    v52 = v50->v2;
    v53 = v50->v3;
    v54 = v50->v0;
  }
  v6->mLastKnownGoodBasis.v0 = v54;
  v6->mLastKnownGoodBasis.v1 = v51;
  v6->mLastKnownGoodBasis.v2 = v52;
  v6->mLastKnownGoodBasis.v3 = v53;
  v55 = v6->mParent;
  v6->mStartTime = v8->mStartTime;
  v56 = container->mParentNode.m_pPointer;
  if ( v55->m_pPointer )
  {
    v57 = v55->mPrev;
    v58 = v55->mNext;
    v57->mNext = v58;
    v58->mPrev = v57;
    v55->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v55->mPrev;
    v55->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v55->mPrev;
  }
  v55->m_pPointer = v56;
  if ( v56 )
  {
    v59 = v56->m_SafePointerList.mNode.mPrev;
    v59->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v55->mPrev;
    v55->mPrev = v59;
    v55->mNext = &v56->m_SafePointerList.mNode;
    v56->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v55->mPrev;
  }
  v6->mComponentIndex = v8->mComponentIndex;
  UFG::qResourceHandle::Init(&v6->mContainerHandle, 0xED341A8D, container->mSettings.mNameUID);
  v6->mSettingsId = v7->mNode.mUID;
  v6->mParentFXId = container->mId;
  v60 = v50->v3.y;
  v61 = v50->v3.z;
  v6->mLastKnownEffectPos.x = v50->v3.x;
  v6->mLastKnownEffectPos.y = v60;
  v6->mLastKnownEffectPos.z = v61;
  v62 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
  v63 = v7->mNode.mUID;
  if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
  {
    v64 = UFG::qResourceWarehouse::Instance();
    v62 = UFG::qResourceWarehouse::GetInventory(v64, 0x3BEE21DCu);
    `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = v62;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mCreatorSettings.mPrev, 0x3BEE21DCu, v63, v62);
  if ( v7->mPhysicsType == 1203368722 )
  {
    v65 = (LOBYTE(v7->mBitFields[0]) >> 2) & 1;
    Render::ParticleEmitterBuffer::GetRenderMatrix(v6, &out_mat);
    v66 = v6->mRaycaster;
    v67 = out_mat.v3.y;
    v68 = out_mat.v3.z;
    v66->mPosition.x = out_mat.v3.x;
    v66->mPosition.y = v67;
    v66->mPosition.z = v68;
    v6->mRaycaster->mMode = 3 - (v65 != 0);
  }
}

// File Line: 414
// RVA: 0x1C1EC0
void __fastcall Render::ParticleEmitterBuffer::TaskInfo::TaskInfo(Render::ParticleEmitterBuffer::TaskInfo *this)
{
  Render::ParticleEmitterBuffer::TaskInfo *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  Render::ParticleRenderUpdateTaskParam *v3; // rcx

  v1 = this;
  this->inputParam = (Render::ParticleRenderUpdateTaskParam *)UFG::qMalloc(
                                                                0x270ui64,
                                                                "ParticleEmitterBuffer::ParticleRenderUpdateTaskParam",
                                                                0x1000ui64);
  v2 = UFG::qMalloc(8ui64, "ParticleEmitterBuffer::ParticleRenderUpdateTaskOutputParam", 0x1000ui64);
  v3 = v1->inputParam;
  v1->outputParam = (Render::ParticleRenderUpdateTaskOutputParam *)v2;
  UFG::qMemSet(v3, 0, 0x270u);
  UFG::qMemSet(v1->outputParam, 0, 8u);
  v1->instance = 0i64;
  v1->task = 0i64;
}

// File Line: 428
// RVA: 0x1C4840
void __fastcall Render::ParticleEmitterBuffer::TaskInfo::~TaskInfo(Render::ParticleEmitterBuffer::TaskInfo *this)
{
  Render::ParticleEmitterBuffer::TaskInfo *v1; // rbx

  v1 = this;
  operator delete[](this->inputParam);
  operator delete[](v1->outputParam);
}

// File Line: 436
// RVA: 0x1D75C0
void __fastcall Render::ParticleEmitterBuffer::TaskInfo::Start(Render::ParticleEmitterBuffer::TaskInfo *this, Render::ParticleEmitterSettings *pfx, Render::ParticleEmitterBuffer *buffer, void *frameMemoryInstanceBuffer, UFG::qVector3 *cameraPos, float simTime, float deltaTime, Render::FXManagerLights *lightList)
{
  void *v8; // rbp
  Render::ParticleEmitterBuffer *v9; // rbx
  Render::ParticleEmitterSettings *v10; // r14
  Render::ParticleEmitterBuffer::TaskInfo *v11; // rdi
  Render::ParticleEmitterInstance *v12; // rcx
  UFG::qMatrix44 *v13; // rax
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  Render::ParticleEmitterInstance *v17; // rax
  _OWORD *v18; // rcx
  UFG::qVector4 v19; // xmm2
  UFG::qVector4 v20; // xmm1
  UFG::qVector4 v21; // xmm0
  UFG::TransformNodeComponent *v22; // rsi
  _OWORD *v23; // rax
  __int128 v24; // xmm2
  __int128 v25; // xmm1
  __int128 v26; // xmm0
  UFG::qVector4 v27; // xmm2
  UFG::qVector4 v28; // xmm1
  UFG::qVector4 v29; // xmm0
  UFG::qMatrix44 *v30; // rcx
  float v31; // xmm1_4
  float v32; // xmm2_4
  Render::ParticleRenderUpdateTaskOutputParam *v33; // rbx
  UFG::qMatrix44 *v34; // rsi
  char *v35; // rax
  UFG::qTask *v36; // rdx
  _QWORD *v37; // rax
  UFG::qSpuElf *v38; // rax
  void (__fastcall *v39)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v40)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v41)(void *, void *, void *, void *); // r9
  char *v42; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v43; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v44; // rax

  v8 = frameMemoryInstanceBuffer;
  v9 = buffer;
  v10 = pfx;
  v11 = this;
  Render::ParticleEmitterBuffer::GetRenderMatrix(buffer, &this->inputParam->renderMatrix);
  v12 = v9->mOwner;
  if ( v12 )
  {
    v13 = &v11->inputParam->renderMatrix;
    v14 = v12->mCurrentBasis.v1;
    v15 = v12->mCurrentBasis.v2;
    v16 = v12->mCurrentBasis.v3;
    v13[1].v0 = v12->mCurrentBasis.v0;
    v13[1].v1 = v14;
    v13[1].v2 = v15;
    v13[1].v3 = v16;
    v17 = v9->mOwner;
    v18 = (_OWORD *)&v11->inputParam->renderMatrix.v0.x;
    v19 = v17->mPrevBasis.v1;
    v20 = v17->mPrevBasis.v2;
    v21 = v17->mPrevBasis.v3;
    v18[8] = v17->mPrevBasis.v0;
    v18[9] = v19;
    v18[10] = v20;
    v18[11] = v21;
  }
  else
  {
    v22 = (UFG::TransformNodeComponent *)v9->mParent->m_pPointer;
    v23 = (_OWORD *)&v11->inputParam->renderMatrix.v0.x;
    if ( v22 )
    {
      v24 = v23[5];
      v25 = v23[6];
      v26 = v23[7];
      v23[8] = v23[4];
      v23[9] = v24;
      v23[10] = v25;
      v23[11] = v26;
      UFG::TransformNodeComponent::UpdateWorldTransform(v22);
      Render::FXInstance::CalcBasisHelper(
        &v11->inputParam->curBasis,
        &v22->mWorldTransform,
        &v9->mContainerHandle,
        v9->mComponentIndex,
        v9->mCreationTime);
    }
    else
    {
      v27 = v9->mLastKnownGoodBasis.v1;
      v28 = v9->mLastKnownGoodBasis.v2;
      v29 = v9->mLastKnownGoodBasis.v3;
      v23[4] = v9->mLastKnownGoodBasis.v0;
      v23[5] = v27;
      v23[6] = v28;
      v23[7] = v29;
    }
  }
  v11->inputParam->simTime = simTime;
  v11->inputParam->deltaTime = deltaTime;
  v11->inputParam->seed = UFG::qDefaultSeed;
  UFG::qDefaultSeed ^= 0x1D872B41 ^ UFG::qDefaultSeed ^ 0x1D872B41 ^ ((UFG::qDefaultSeed ^ 0x1D872B41u) >> 5) ^ ((UFG::qDefaultSeed ^ 0x1D872B41 ^ ((UFG::qDefaultSeed ^ 0x1D872B41u) >> 5)) << 27);
  v11->inputParam->pSettings = v10;
  v11->inputParam->numParticlesInBuffer = v9->mCount;
  v11->inputParam->cpuAttributeBuffer = v9->mCPUAttributes;
  v11->inputParam->renderAttributeBuffer = v8;
  v30 = &v11->inputParam->renderMatrix;
  v31 = cameraPos->y;
  v32 = cameraPos->z;
  v30[3].v0.x = cameraPos->x;
  v30[3].v0.y = v31;
  v30[3].v0.z = v32;
  LODWORD(v30[8].v2.y) = v9->mCapacity;
  v11->inputParam->lastExpiry = v9->mExpiry;
  v11->inputParam->forceList = Render::gFXForceManager.mForceList;
  v11->inputParam->numForces = Render::gFXForceManager.mNumForces;
  v11->inputParam->numBouncePlanes = Render::ParticleRaycaster::GetHitPlanes(
                                       v9->mRaycaster,
                                       0xAu,
                                       v11->inputParam->bouncePlaneList);
  v11->inputParam->modelToEmitFrom = v9->mModelToEmitFrom.mData;
  v11->inputParam->fxOverride = v9->mFXOverridePointer.m_pPointer;
  v11->inputParam->lights = *lightList;
  v33 = v11->outputParam;
  v34 = &v11->inputParam->renderMatrix;
  v35 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v36 = (UFG::qTask *)v35;
  if ( v35 )
  {
    *(_QWORD *)v35 = v35;
    *((_QWORD *)v35 + 1) = v35;
    v37 = v35 + 16;
    *v37 = v37;
    v37[1] = v37;
    v38 = Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mSpuElf;
    v39 = Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mTaskFunctionSPU;
    v40 = Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mTaskFunctionPPU;
    v41 = Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mTaskFunctionOffload;
    if ( !Render::gTaskFunctionDeclData_ParticleRenderUpdateTask.mCurrentSPUEnabled )
    {
      v38 = 0i64;
      v39 = 0i64;
      v41 = 0i64;
    }
    v36->mTaskGroup = 0i64;
    v36->mFlags = 2;
    v36->mSyncVars.i64 = 0i64;
    v36->mSyncVars.v.mDependents = 0i64;
    v36->mFunctionDeclData = &Render::gTaskFunctionDeclData_ParticleRenderUpdateTask;
    if ( v38 )
      v42 = v38->mAddress;
    else
      v42 = 0i64;
    v36->mSPUElfAddress = v42;
    v36->mSPUFunction = v39;
    v36->mPPUFunction = v40;
    v36->mParam0 = v34;
    v36->mParam1 = v33;
    v36->mParam2 = 0i64;
    v36->mParam3 = 0i64;
    if ( v41 )
    {
      v36->mFlags = 130;
      v36->mOffloadThread = 0;
    }
  }
  v43 = UFG::gTaskManager.mSingleFrameTasks;
  v44 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  v44->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v36->mPrev;
  v36->mPrev = v44;
  v36->mNext = &v43->mNode;
  v43->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v36->mPrev;
  v11->task = v36;
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v36);
}

// File Line: 554
// RVA: 0x1CCE30
void __fastcall Render::ParticleEmitterBuffer::GetRenderMatrix(Render::ParticleEmitterBuffer *this, UFG::qMatrix44 *out_mat)
{
  UFG::qVector4 v2; // xmm1
  UFG::qVector4 v3; // xmm2
  UFG::qMatrix44 *v4; // rsi
  Render::ParticleEmitterBuffer *v5; // rbx
  UFG::qVector4 v6; // xmm3
  void (__fastcall *v7)(UFG::qMatrix44 *, UFG::qMatrix44 *, UFG::qResourceHandle *, unsigned int, float); // r10
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v8; // rax
  UFG::SimComponent *v9; // rdi

  v2 = UFG::qMatrix44::msIdentity.v1;
  v3 = UFG::qMatrix44::msIdentity.v2;
  v4 = out_mat;
  v5 = this;
  v6 = UFG::qMatrix44::msIdentity.v3;
  out_mat->v0 = UFG::qMatrix44::msIdentity.v0;
  out_mat->v1 = v2;
  out_mat->v2 = v3;
  out_mat->v3 = v6;
  v7 = this->mCalcBasis;
  if ( v7 )
  {
    v8 = this->mParent;
    v9 = v8->m_pPointer;
    if ( v9 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8->m_pPointer);
      ((void (__fastcall *)(UFG::qMatrix44 *, UFG::SimComponent *, UFG::qResourceHandle *, _QWORD, _DWORD))v5->mCalcBasis)(
        v4,
        &v9[2],
        &v5->mContainerHandle,
        v5->mComponentIndex,
        LODWORD(v5->mStartTime));
    }
    else
    {
      ((void (__fastcall *)(UFG::qMatrix44 *, UFG::qMatrix44 *, UFG::qResourceHandle *, _QWORD, _DWORD))v7)(
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
  Render::ParticleEmitterBuffer *v1; // rbx
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
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::allocator::free_link *v16; // rax

  v1 = this;
  Render::ParticleEmitterBuffer::TaskInfo::TaskInfo(&this->mTaskInfo);
  *(_QWORD *)&v1->mExpiry = 0i64;
  *(_QWORD *)&v1->mCount = 0i64;
  v1->mParticleMaterial = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mCreatorSettings.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mModel.mPrev);
  v1->mDescription = 0i64;
  UFG::qResourceHandle::qResourceHandle(&v1->mContainerHandle);
  v1->mComponentIndex = -1;
  v1->mStartTime = 0.0;
  v1->mCalcBasis = 0i64;
  v2 = UFG::qMatrix44::msIdentity.v0.y;
  v3 = UFG::qMatrix44::msIdentity.v0.z;
  v4 = UFG::qMatrix44::msIdentity.v0.w;
  v1->mLastKnownGoodBasis.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  v1->mLastKnownGoodBasis.v0.y = v2;
  v1->mLastKnownGoodBasis.v0.z = v3;
  v1->mLastKnownGoodBasis.v0.w = v4;
  v5 = UFG::qMatrix44::msIdentity.v1.y;
  v6 = UFG::qMatrix44::msIdentity.v1.z;
  v7 = UFG::qMatrix44::msIdentity.v1.w;
  v1->mLastKnownGoodBasis.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  v1->mLastKnownGoodBasis.v1.y = v5;
  v1->mLastKnownGoodBasis.v1.z = v6;
  v1->mLastKnownGoodBasis.v1.w = v7;
  v8 = UFG::qMatrix44::msIdentity.v2.y;
  v9 = UFG::qMatrix44::msIdentity.v2.z;
  v10 = UFG::qMatrix44::msIdentity.v2.w;
  v1->mLastKnownGoodBasis.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  v1->mLastKnownGoodBasis.v2.y = v8;
  v1->mLastKnownGoodBasis.v2.z = v9;
  v1->mLastKnownGoodBasis.v2.w = v10;
  v11 = UFG::qMatrix44::msIdentity.v3.y;
  v12 = UFG::qMatrix44::msIdentity.v3.z;
  v13 = UFG::qMatrix44::msIdentity.v3.w;
  v1->mLastKnownGoodBasis.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  v1->mLastKnownGoodBasis.v3.y = v11;
  v1->mLastKnownGoodBasis.v3.z = v12;
  v1->mLastKnownGoodBasis.v3.w = v13;
  v14 = UFG::qVector3::msZero.y;
  v15 = UFG::qVector3::msZero.z;
  v1->mLastKnownEffectPos.x = UFG::qVector3::msZero.x;
  v1->mLastKnownEffectPos.y = v14;
  v1->mLastKnownEffectPos.z = v15;
  *(_QWORD *)&v1->mParentFXId = -1i64;
  v1->mRenderAttributeBuffer = 0i64;
  v1->mRaycaster = 0i64;
  v1->mOwner = 0i64;
  v1->mCPUAttributes = 0i64;
  v1->mFXOverridePointer.m_pPointer = 0i64;
  v1->mSplitScreenViewMask = -1;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mModelToEmitFrom.mPrev);
  v16 = UFG::qMalloc(0x18ui64, "ParticleEmitterBuffer::Parent", 0i64);
  if ( v16 )
  {
    v16->mNext = v16;
    v16[1].mNext = v16;
    v16[2].mNext = 0i64;
  }
  else
  {
    v16 = 0i64;
  }
  v1->mParent = (UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *)v16;
}

// File Line: 615
// RVA: 0x1C42E0
void __fastcall Render::ParticleEmitterBuffer::~ParticleEmitterBuffer(Render::ParticleEmitterBuffer *this)
{
  Render::ParticleEmitterBuffer *v1; // rbx
  UFG::qResourceData *v2; // rdi
  UFG::qResourceWarehouse *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  void **v9; // rdi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  Render::FXOverride *v12; // rax
  Render::FXOverride *v13; // rdi
  Render::FXOverride::PrecalculatedTriangle *v14; // rdx
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax

  v1 = this;
  operator delete[](this->mCPUAttributes);
  v2 = (UFG::qResourceData *)&v1->mParticleMaterial->mNode;
  if ( v2 )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v3, v2);
    UFG::LibCurlFree(v1->mParticleMaterial);
  }
  v4 = v1->mParent;
  if ( v4 )
  {
    if ( v4->m_pPointer )
    {
      v5 = v4->mPrev;
      v6 = v4->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    }
    v4->m_pPointer = 0i64;
    v7 = v4->mPrev;
    v8 = v4->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    operator delete[](v4);
  }
  v9 = (void **)&v1->mRaycaster->mRaycastResultList;
  if ( v9 )
  {
    operator delete[](*v9);
    operator delete[](v9);
  }
  v10 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v10;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mModelToEmitFrom.mPrev, v10);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mModelToEmitFrom.mPrev);
  v12 = v1->mFXOverridePointer.m_pPointer;
  if ( v12 )
  {
    --v12->mReferenceCount;
    v13 = v1->mFXOverridePointer.m_pPointer;
    if ( v13->mReferenceCount <= 0 )
    {
      if ( v13 )
      {
        v14 = v13->mTriangleInfo;
        if ( v14 )
          UFG::qMemoryPool::Free(v13->mMemoryPool, v14);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v13);
      }
      v1->mFXOverridePointer.m_pPointer = 0i64;
    }
  }
  UFG::qResourceHandle::~qResourceHandle(&v1->mContainerHandle);
  v15 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v15;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mModel.mPrev, v15);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mModel.mPrev);
  v17 = `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result )
  {
    v18 = UFG::qResourceWarehouse::Instance();
    v17 = UFG::qResourceWarehouse::GetInventory(v18, 0x3BEE21DCu);
    `UFG::qGetResourceInventory<Render::ParticleEmitterSettings>::`2::result = v17;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mCreatorSettings.mPrev, v17);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mCreatorSettings.mPrev);
  operator delete[](v1->mTaskInfo.inputParam);
  operator delete[](v1->mTaskInfo.outputParam);
}

// File Line: 635
// RVA: 0x146B750
__int64 Render::_dynamic_initializer_for__gParticleEmitterManager__()
{
  Render::gParticleEmitterManager.freeBuffersSmall.p = 0i64;
  *(_QWORD *)&Render::gParticleEmitterManager.freeBuffersSmall.size = 0i64;
  `eh vector constructor iterator(
    Render::gParticleEmitterManager.activeBuffers,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  *(_QWORD *)&Render::gParticleEmitterManager.mNumActiveTasks = 0i64;
  Render::gParticleEmitterManager.mDebugMeshEmitterNormalLength = 0.0;
  Render::gParticleEmitterManager.mIsParticleBufferDebugDrawsEnabled = 0;
  return atexit(Render::_dynamic_atexit_destructor_for__gParticleEmitterManager__);
}

// File Line: 661
// RVA: 0x1D09E0
void __fastcall Render::ParticleEmitterManager::InitTrailModel(Render::ParticleEmitterManager *this, unsigned int num_instances)
{
  unsigned int v2; // er12
  unsigned int v3; // edi
  signed int v4; // ebx
  UFG::qResourceData *v5; // rax
  UFG::qResourceData *v6; // r15
  UFG::qBaseNodeRB *v7; // rax
  _QWORD *v8; // rcx
  char *v9; // rsi
  int v10; // edx
  unsigned int v11; // er14
  Illusion::Buffer *v12; // rax
  UFG::qResourceData *v13; // rbp
  __int64 v14; // rax
  signed __int64 v15; // rcx
  signed __int64 v16; // rax
  float v17; // xmm2_4
  float v18; // xmm1_4
  UFG::qResourceWarehouse *v19; // rax
  int v20; // edx
  unsigned int v21; // er14
  int v22; // er13
  int v23; // ebx
  Illusion::Buffer *v24; // rax
  UFG::qResourceData *v25; // rbp
  unsigned int v26; // er11
  __int64 v27; // rax
  signed __int64 v28; // rbx
  UFG::qResourceWarehouse *v29; // rax
  UFG::qResourceWarehouse *v30; // rax
  UFG::qString v31; // [rsp+48h] [rbp-50h]

  v2 = num_instances;
  v3 = 0;
  v4 = 1;
  v5 = Illusion::Factory::NewModel("ParticleManager.TrailModel", 0x62AD0667u, 1u, 0i64, 0i64, 0i64);
  v6 = v5;
  v7 = v5[2].mNode.mChild[0];
  if ( v7 )
    v8 = (_QWORD *)((char *)&v7[5].mUID + (_QWORD)v6);
  else
    v8 = 0i64;
  v9 = (char *)v8 + *v8;
  if ( !*v8 )
    v9 = 0i64;
  *((_DWORD *)v9 + 57) = 0;
  *((_DWORD *)v9 + 58) = 14;
  *((_DWORD *)v9 + 56) = 3;
  UFG::qString::qString(&v31, "ParticleManager.Trail.VertexBuffer");
  v11 = v31.mStringHash32;
  if ( v31.mStringHash32 == -1 )
  {
    v11 = UFG::qStringHash32(v31.mData, v31.mStringHash32 | v10);
    v31.mStringHash32 = v11;
  }
  v12 = Illusion::Factory::NewBuffer(v31.mData, v11, 0x100u, 0i64, "Particle.Trail.VertexBuffer", 0i64, 0i64);
  v13 = (UFG::qResourceData *)v12;
  v12->mBufferType = 0;
  v12->mElementByteSize = 16;
  v12->mNumElements = 16;
  v14 = v12->mData.mOffset;
  if ( v14 )
    v15 = (signed __int64)v13[1].mNode.mChild + v14;
  else
    v15 = 0i64;
  *(_DWORD *)v15 = 0;
  *(_DWORD *)(v15 + 4) = -1090519040;
  *(_DWORD *)(v15 + 8) = 1056964608;
  *(_DWORD *)(v15 + 12) = 1065353216;
  v16 = v15 + 40;
  do
  {
    v17 = (float)((float)v4 * 0.071428575) - 0.5;
    *(_DWORD *)(v16 - 24) = -1090519040;
    *(float *)(v16 - 20) = v17;
    *(_DWORD *)(v16 - 16) = 0;
    v18 = 1.0 - (float)(v17 + 0.5);
    *(float *)(v16 - 12) = v18;
    *(_DWORD *)(v16 - 8) = 1056964608;
    *(float *)(v16 - 4) = v17;
    *(_DWORD *)v16 = 1065353216;
    *(float *)(v16 + 4) = v18;
    v4 += 2;
    v16 += 32i64;
  }
  while ( v4 < 14 );
  *(_DWORD *)(v15 + 240) = 0;
  *(_DWORD *)(v15 + 244) = 1056964608;
  *(_QWORD *)(v15 + 248) = 1056964608i64;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, v13);
  *((_QWORD *)v9 + 30) = "ParticleManager.TrailModel";
  *((_DWORD *)v9 + 30) = v11;
  *((_DWORD *)v9 + 14) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gParticleDescriptor);
  UFG::qString::~qString(&v31);
  UFG::qString::qString(&v31, "ParticleManager.Trail.IndexBuffer");
  v21 = v31.mStringHash32;
  if ( v31.mStringHash32 == -1 )
  {
    v21 = UFG::qStringHash32(v31.mData, v31.mStringHash32 | v20);
    v31.mStringHash32 = v21;
  }
  v22 = 3 * *((_DWORD *)v9 + 58);
  v23 = v2 * 3 * *((_DWORD *)v9 + 58);
  v24 = Illusion::Factory::NewBuffer(v31.mData, v21, 2 * v23, 0i64, "Particle.Trail.IndexBuffer", 0i64, 0i64);
  v25 = (UFG::qResourceData *)v24;
  v24->mBufferType = 1;
  v26 = 2;
  v24->mElementByteSize = 2;
  v24->mNumElements = v23;
  v27 = v24->mData.mOffset;
  if ( v27 )
    v28 = (signed __int64)v25[1].mNode.mChild + v27;
  else
    v28 = 0i64;
  if ( v2 )
  {
    do
    {
      *(_WORD *)(v28 + 2i64 * (v26 - 2)) = 16 * v3;
      *(_WORD *)(v28 + 2i64 * (v26 - 1)) = 16 * v3 + 2;
      *(_WORD *)(v28 + 2i64 * v26) = 16 * v3 + 1;
      *(_WORD *)(v28 + 2i64 * (v26 + 1)) = 16 * v3 + 1;
      *(_WORD *)(v28 + 2i64 * (v26 + 2)) = 16 * v3 + 2;
      *(_WORD *)(v28 + 2i64 * (v26 + 3)) = 16 * v3 + 3;
      *(_WORD *)(v28 + 2i64 * (v26 + 4)) = 16 * v3 + 3;
      *(_WORD *)(v28 + 2i64 * (v26 + 5)) = 16 * v3 + 2;
      *(_WORD *)(v28 + 2i64 * (v26 + 6)) = 16 * v3 + 4;
      *(_WORD *)(v28 + 2i64 * (v26 + 7)) = 16 * v3 + 3;
      *(_WORD *)(v28 + 2i64 * (v26 + 8)) = 16 * v3 + 4;
      *(_WORD *)(v28 + 2i64 * (v26 + 9)) = 16 * v3 + 5;
      *(_WORD *)(v28 + 2i64 * (v26 + 10)) = 16 * v3 + 5;
      *(_WORD *)(v28 + 2i64 * (v26 + 11)) = 16 * v3 + 4;
      *(_WORD *)(v28 + 2i64 * (v26 + 12)) = 16 * v3 + 6;
      *(_WORD *)(v28 + 2i64 * (v26 + 13)) = 16 * v3 + 5;
      *(_WORD *)(v28 + 2i64 * (v26 + 14)) = 16 * v3 + 6;
      *(_WORD *)(v28 + 2i64 * (v26 + 15)) = 16 * v3 + 7;
      *(_WORD *)(v28 + 2i64 * (v26 + 16)) = 16 * v3 + 7;
      *(_WORD *)(v28 + 2i64 * (v26 + 17)) = 16 * v3 + 6;
      *(_WORD *)(v28 + 2i64 * (v26 + 18)) = 16 * v3 + 8;
      *(_WORD *)(v28 + 2i64 * (v26 + 19)) = 16 * v3 + 7;
      *(_WORD *)(v28 + 2i64 * (v26 + 20)) = 16 * v3 + 8;
      *(_WORD *)(v28 + 2i64 * (v26 + 21)) = 16 * v3 + 9;
      *(_WORD *)(v28 + 2i64 * (v26 + 22)) = 16 * v3 + 9;
      *(_WORD *)(v28 + 2i64 * (v26 + 23)) = 16 * v3 + 8;
      *(_WORD *)(v28 + 2i64 * (v26 + 24)) = 16 * v3 + 10;
      *(_WORD *)(v28 + 2i64 * (v26 + 25)) = 16 * v3 + 9;
      *(_WORD *)(v28 + 2i64 * (v26 + 26)) = 16 * v3 + 10;
      *(_WORD *)(v28 + 2i64 * (v26 + 27)) = 16 * v3 + 11;
      *(_WORD *)(v28 + 2i64 * (v26 + 28)) = 16 * v3 + 11;
      *(_WORD *)(v28 + 2i64 * (v26 + 29)) = 16 * v3 + 10;
      *(_WORD *)(v28 + 2i64 * (v26 + 30)) = 16 * v3 + 12;
      *(_WORD *)(v28 + 2i64 * (v26 + 31)) = 16 * v3 + 11;
      *(_WORD *)(v28 + 2i64 * (v26 + 32)) = 16 * v3 + 12;
      *(_WORD *)(v28 + 2i64 * (v26 + 33)) = 16 * v3 + 13;
      *(_WORD *)(v28 + 2i64 * (v26 + 34)) = 16 * v3 + 13;
      *(_WORD *)(v28 + 2i64 * (v26 + 35)) = 16 * v3 + 12;
      *(_WORD *)(v28 + 2i64 * (v26 + 36)) = 16 * v3 + 14;
      *(_WORD *)(v28 + 2i64 * (v26 + 37)) = 16 * v3 + 13;
      *(_WORD *)(v28 + 2i64 * (v26 + 38)) = 16 * v3 + 14;
      *(_WORD *)(v28 + 2i64 * (v26 + 39)) = 16 * v3++ + 15;
      v26 += v22;
    }
    while ( v3 < v2 );
  }
  v29 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v29, v25);
  *((_DWORD *)v9 + 22) = v21;
  UFG::qString::~qString(&v31);
  v30 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v30, v6);
}

// File Line: 822
// RVA: 0x1D0380
void __fastcall Render::ParticleEmitterManager::InitQuadModel(Render::ParticleEmitterManager *this, unsigned int num_instances)
{
  UFG::qResourceData *v2; // rax
  UFG::qResourceData *v3; // rbp
  UFG::qBaseNodeRB *v4; // rcx
  _QWORD *v5; // rcx
  char *v6; // rdi
  int v7; // edx
  unsigned int v8; // ebx
  Illusion::Buffer *v9; // rax
  UFG::qResourceData *v10; // rsi
  __int64 v11; // rax
  signed __int64 v12; // rcx
  UFG::qResourceWarehouse *v13; // rax
  int v14; // edx
  unsigned int v15; // esi
  Illusion::Buffer *v16; // rax
  UFG::qResourceData *v17; // rbx
  __int64 v18; // rax
  _DWORD *v19; // rax
  UFG::qResourceWarehouse *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qString v22; // [rsp+48h] [rbp-50h]

  v2 = Illusion::Factory::NewModel("ParticleManager.QuadModel", 0xA8A40548, 1u, 0i64, 0i64, 0i64);
  v3 = v2;
  v4 = v2[2].mNode.mChild[0];
  if ( v4 )
    v5 = (_QWORD *)((char *)&v4[5].mUID + (_QWORD)v2);
  else
    v5 = 0i64;
  v6 = (char *)v5 + *v5;
  if ( !*v5 )
    v6 = 0i64;
  UFG::qString::qString(&v22, "ParticleManager.Quad.VertexBuffer");
  v8 = v22.mStringHash32;
  if ( v22.mStringHash32 == -1 )
  {
    v8 = UFG::qStringHash32(v22.mData, v22.mStringHash32 | v7);
    v22.mStringHash32 = v8;
  }
  *((_QWORD *)v6 + 28) = 3i64;
  *((_DWORD *)v6 + 58) = 2;
  v9 = Illusion::Factory::NewBuffer(v22.mData, v8, 0x40u, 0i64, "Particle.Quad.VertexBuffer", 0i64, 0i64);
  v10 = (UFG::qResourceData *)v9;
  v9->mBufferType = 0;
  v9->mElementByteSize = 16;
  v9->mNumElements = 4;
  v11 = v9->mData.mOffset;
  if ( v11 )
    v12 = (signed __int64)v10[1].mNode.mChild + v11;
  else
    v12 = 0i64;
  *(_DWORD *)v12 = -1090519040;
  *(_DWORD *)(v12 + 4) = -1090519040;
  *(_DWORD *)(v12 + 8) = 0;
  *(_DWORD *)(v12 + 12) = 1065353216;
  *(_DWORD *)(v12 + 16) = 1056964608;
  *(_DWORD *)(v12 + 20) = -1090519040;
  *(_DWORD *)(v12 + 24) = 1065353216;
  *(_DWORD *)(v12 + 28) = 1065353216;
  *(_DWORD *)(v12 + 32) = 1056964608;
  *(_DWORD *)(v12 + 36) = 1056964608;
  *(_QWORD *)(v12 + 40) = 1065353216i64;
  *(_DWORD *)(v12 + 48) = -1090519040;
  *(_QWORD *)(v12 + 52) = 1056964608i64;
  *(_DWORD *)(v12 + 60) = 0;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, v10);
  *((_QWORD *)v6 + 30) = "ParticleManager.QuadModel";
  *((_DWORD *)v6 + 30) = v8;
  *((_DWORD *)v6 + 14) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gParticleDescriptor);
  UFG::qString::~qString(&v22);
  UFG::qString::qString(&v22, "ParticleManager.Quad.IndexBuffer");
  v15 = v22.mStringHash32;
  if ( v22.mStringHash32 == -1 )
  {
    v15 = UFG::qStringHash32(v22.mData, v22.mStringHash32 | v14);
    v22.mStringHash32 = v15;
  }
  v16 = Illusion::Factory::NewBuffer(v22.mData, v15, 0xCu, 0i64, "Particle.Quad.IndexBuffer", 0i64, 0i64);
  v17 = (UFG::qResourceData *)v16;
  v16->mBufferType = 1;
  v16->mElementByteSize = 2;
  v16->mNumElements = 6;
  v18 = v16->mData.mOffset;
  if ( v18 )
    v19 = (_DWORD *)((char *)v17[1].mNode.mChild + v18);
  else
    v19 = 0i64;
  *v19 = 0x10000;
  v19[1] = 196611;
  v19[2] = 131073;
  v20 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v20, v17);
  *((_DWORD *)v6 + 22) = v15;
  UFG::qString::~qString(&v22);
  v21 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v21, v3);
}

// File Line: 914
// RVA: 0x1CF600
void __fastcall Render::ParticleEmitterManager::Init(Render::ParticleEmitterManager *this)
{
  Render::ParticleEmitterManager *v1; // rbx
  signed __int64 v2; // r12
  UFG::allocator::free_link *v3; // rax
  Render::ParticleEmitterBuffer *v4; // rax
  Render::ParticleEmitterBuffer *v5; // rbp
  __int64 v6; // r15
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // edi
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  Render::ParticleEmitterBuffer **v12; // r14
  __int64 v13; // r9
  signed __int64 v14; // r12
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
  __int64 v25; // r9
  hkResourceHandle *v26; // rax

  v1 = this;
  Render::ParticleEmitterManager::InitStateSystemParams(this);
  *(_QWORD *)&v1->mOverdrawIntensity = 1028443341i64;
  v1->mOverdrawToggle = 0;
  Render::ParticleEmitterManager::InitQuadModel(v1, 0x20u);
  Render::ParticleEmitterManager::InitTrailModel(v1, 0x20u);
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
    v6 = v1->freeBuffersLarge.size;
    v7 = v6 + 1;
    v8 = v1->freeBuffersLarge.capacity;
    if ( (signed int)v6 + 1 > v8 )
    {
      if ( v8 )
        v9 = 2 * v8;
      else
        v9 = 1;
      for ( ; v9 < v7; v9 *= 2 )
        ;
      if ( v9 <= 2 )
        v9 = 2;
      if ( v9 - v7 > 0x10000 )
        v9 = v6 + 65537;
      if ( v9 != (_DWORD)v6 )
      {
        v10 = 8i64 * v9;
        if ( !is_mul_ok(v9, 8ui64) )
          v10 = -1i64;
        v11 = UFG::qMalloc(v10, "qArray.Add", 0i64);
        v12 = (Render::ParticleEmitterBuffer **)v11;
        if ( v1->freeBuffersLarge.p )
        {
          v13 = 0i64;
          if ( v1->freeBuffersLarge.size )
          {
            do
            {
              v11[v13] = (UFG::allocator::free_link)v1->freeBuffersLarge.p[v13];
              v13 = (unsigned int)(v13 + 1);
            }
            while ( (unsigned int)v13 < v1->freeBuffersLarge.size );
          }
          operator delete[](v1->freeBuffersLarge.p);
        }
        v1->freeBuffersLarge.p = v12;
        v1->freeBuffersLarge.capacity = v9;
      }
    }
    v1->freeBuffersLarge.size = v7;
    v1->freeBuffersLarge.p[v6] = v5;
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
    v18 = v1->freeBuffersSmall.size;
    v19 = v18 + 1;
    v20 = v1->freeBuffersSmall.capacity;
    if ( (signed int)v18 + 1 > v20 )
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
        if ( v1->freeBuffersSmall.p )
        {
          v25 = 0i64;
          if ( v1->freeBuffersSmall.size )
          {
            do
            {
              v23[v25] = (UFG::allocator::free_link)v1->freeBuffersSmall.p[v25];
              v25 = (unsigned int)(v25 + 1);
            }
            while ( (unsigned int)v25 < v1->freeBuffersSmall.size );
          }
          operator delete[](v1->freeBuffersSmall.p);
        }
        v1->freeBuffersSmall.p = v24;
        v1->freeBuffersSmall.capacity = v21;
      }
    }
    v1->freeBuffersSmall.size = v19;
    v1->freeBuffersSmall.p[v18] = v17;
    --v14;
  }
  while ( v14 );
  v1->mShaderParticleLitShadowUID = UFG::qStringHashUpper32("ParticleLitShadow", 0xFFFFFFFF);
  v1->mShaderParticleLitUID = UFG::qStringHashUpper32("ParticleLit", 0xFFFFFFFF);
  v1->mShaderParticleSoftLitShadowUID = UFG::qStringHashUpper32("ParticleSoftLitShadow", 0xFFFFFFFF);
  v1->mShaderParticleSoftLitUID = UFG::qStringHashUpper32("ParticleSoftLit", 0xFFFFFFFF);
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
void __fastcall Render::ParticleEmitterManager::DestroyBuffers(Render::ParticleEmitterManager *this, UFG::qArray<Render::ParticleEmitterBuffer *,0> *bufferArray)
{
  __int64 v2; // rbx
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *v3; // rdi
  Render::ParticleEmitterBuffer **v4; // rax
  Render::ParticleEmitterBuffer *v5; // rsi
  Render::ParticleEmitterBuffer **v6; // rcx

  v2 = 0i64;
  v3 = bufferArray;
  if ( bufferArray->size )
  {
    do
    {
      v4 = v3->p;
      v5 = v4[v2];
      if ( v5 )
      {
        Render::ParticleEmitterBuffer::~ParticleEmitterBuffer(v4[v2]);
        operator delete[](v5);
      }
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v3->size );
  }
  v6 = v3->p;
  if ( v6 )
    operator delete[](v6);
  v3->p = 0i64;
  *(_QWORD *)&v3->size = 0i64;
}

// File Line: 969
// RVA: 0x1C7140
void __fastcall Render::ParticleEmitterManager::AddToFreeBufferList(Render::ParticleEmitterManager *this, unsigned int queue, unsigned int batchIndex)
{
  Render::ParticleEmitterManager *v3; // rdi
  signed __int64 v4; // r8
  Render::ParticleEmitterBuffer *v5; // rsi
  Render::ParticleRaycaster *v6; // rax
  unsigned int v7; // eax
  Render::ParticleRaycaster *v8; // rax
  __int64 v9; // rbp
  unsigned int v10; // edx
  unsigned int v11; // ebx
  unsigned int v12; // edx
  Render::ParticleEmitterBuffer **v13; // rax
  unsigned int v14; // edx
  unsigned int v15; // ebx
  unsigned int v16; // edx

  v3 = this;
  v4 = 8i64 * batchIndex;
  v5 = *(Render::ParticleEmitterBuffer **)(v4 + *((_QWORD *)&this->mInstanceStateBlockIndex + 2 * (queue + 3i64)));
  v6 = v5->mRaycaster;
  if ( v6 )
    v6->mMode = 4;
  *(_QWORD *)(v4 + *((_QWORD *)&this->mInstanceStateBlockIndex + 2 * (queue + 3i64))) = this->activeBuffers[queue].p[this->activeBuffers[queue].size - 1];
  v7 = this->activeBuffers[queue].size;
  if ( v7 > 1 )
    this->activeBuffers[queue].size = v7 - 1;
  else
    this->activeBuffers[queue].size = 0;
  v8 = v5->mRaycaster;
  if ( v8 )
    v8->mMode = 4;
  Render::ParticleEmitterBuffer::Deactivate(v5);
  if ( v5->mCapacity == 32 )
  {
    v9 = v3->freeBuffersLarge.size;
    v10 = v3->freeBuffersLarge.capacity;
    v11 = v9 + 1;
    if ( (signed int)v9 + 1 > v10 )
    {
      if ( v10 )
        v12 = 2 * v10;
      else
        v12 = 1;
      for ( ; v12 < v11; v12 *= 2 )
        ;
      if ( v12 <= 2 )
        v12 = 2;
      if ( v12 - v11 > 0x10000 )
        v12 = v9 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v3->freeBuffersLarge,
        v12,
        "qArray.Add");
    }
    v13 = v3->freeBuffersLarge.p;
    v3->freeBuffersLarge.size = v11;
  }
  else
  {
    v9 = v3->freeBuffersSmall.size;
    v14 = v3->freeBuffersSmall.capacity;
    v15 = v9 + 1;
    if ( (signed int)v9 + 1 > v14 )
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
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v3->freeBuffersSmall,
        v16,
        "qArray.Add");
    }
    v13 = v3->freeBuffersSmall.p;
    v3->freeBuffersSmall.size = v15;
  }
  v13[v9] = v5;
}

// File Line: 994
// RVA: 0x1C8460
void __fastcall Render::ParticleEmitterManager::Close(Render::ParticleEmitterManager *this)
{
  Render::ParticleEmitterManager *v1; // rbx
  signed __int64 v2; // rdi
  signed __int64 v3; // rbp
  unsigned int i; // ebx
  __int64 v5; // rax
  void *v6; // rsi
  void *v7; // rcx

  v1 = this;
  Render::ParticleEmitterManager::DestroyBuffers(this, &this->freeBuffersLarge);
  Render::ParticleEmitterManager::DestroyBuffers(v1, &v1->freeBuffersSmall);
  v2 = (signed __int64)v1->activeBuffers;
  v3 = 3i64;
  do
  {
    for ( i = 0; i < *(_DWORD *)v2; ++i )
    {
      v5 = *(_QWORD *)(v2 + 8);
      v6 = *(void **)(v5 + 8i64 * i);
      if ( v6 )
      {
        Render::ParticleEmitterBuffer::~ParticleEmitterBuffer(*(Render::ParticleEmitterBuffer **)(v5 + 8i64 * i));
        operator delete[](v6);
      }
    }
    v7 = *(void **)(v2 + 8);
    if ( v7 )
      operator delete[](v7);
    *(_QWORD *)(v2 + 8) = 0i64;
    *(_QWORD *)v2 = 0i64;
    v2 += 16i64;
    --v3;
  }
  while ( v3 );
}

// File Line: 1004
// RVA: 0x1CC6E0
Render::ParticleEmitterBuffer *__fastcall Render::ParticleEmitterManager::GetParticleBuffer(Render::ParticleEmitterManager *this, Render::ParticleEmitterSettings *settings, float creationTime, bool canStealBuffer)
{
  Render::ParticleEmitterSettings *v4; // rdi
  Render::ParticleEmitterManager *v5; // rbp
  float v6; // xmm9_4
  bool v7; // al
  char v8; // cl
  char v9; // al
  signed __int64 v10; // rbx
  void ***v11; // rdi
  __int64 *v12; // rdx
  __int64 v13; // rcx
  _QWORD *v14; // rax
  void **v15; // rbx
  Render::ParticleEmitterBuffer *result; // rax
  signed int v17; // ebx
  UFG::BaseCameraComponent *v18; // rcx
  signed __int64 v19; // rsi
  unsigned __int8 v20; // r10
  signed __int64 v21; // rax
  __int64 v22; // r14
  unsigned int v23; // er11
  float v24; // xmm4_4
  unsigned int v25; // edi
  unsigned int v26; // er9
  unsigned int v27; // er13
  unsigned int v28; // edx
  signed __int64 v29; // r15
  signed int v30; // er8
  _QWORD *v31; // rcx
  __int64 v32; // rax
  __m128 v33; // xmm2
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
  signed __int64 v60; // rcx
  __int64 v61; // rax
  __m128 v62; // xmm2
  float v63; // xmm1_4
  float v64; // xmm3_4
  float v65; // xmm1_4
  float v66; // xmm2_4
  float v67; // xmm1_4
  unsigned int v68; // eax
  signed __int64 v69; // rdi
  __int64 v70; // rsi
  unsigned int v71; // edx
  unsigned int v72; // ebx
  unsigned int v73; // edx
  __int64 v74; // rax
  __int64 v75; // rcx
  __int64 *v76; // rdx
  __int64 v77; // rcx
  _QWORD *v78; // rax
  signed __int64 v79; // [rsp+20h] [rbp-88h]
  Render::ParticleEmitterManager *v80; // [rsp+B0h] [rbp+8h]
  int v81; // [rsp+B8h] [rbp+10h]

  v80 = this;
  v4 = settings;
  v5 = this;
  v81 = (unsigned __int8)settings->mDrawType;
  v6 = creationTime;
  v7 = settings->mEmissionRate == 0.0 && settings->mEmissionInit <= 4;
  v8 = settings->mType;
  if ( v8 == 2 || v7 && v8 != 1 )
  {
    v9 = 1;
    v10 = (signed __int64)&v5->freeBuffersSmall;
  }
  else
  {
    v9 = 0;
    v10 = (signed __int64)&v5->freeBuffersLarge;
  }
  if ( *(_DWORD *)v10 && v10 )
  {
    v11 = (void ***)UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
                      (UFG::qArray<UFG::qPropertySet *,0> *)&v5->activeBuffers[(unsigned __int8)settings->mDrawType],
                      (UFG::qPropertySet *const *)(*(_QWORD *)(v10 + 8) + 8i64 * (unsigned int)(*(_DWORD *)v10 - 1)),
                      "qArray.Add");
    if ( *(_DWORD *)v10 > 1u )
      --*(_DWORD *)v10;
    else
      *(_DWORD *)v10 = 0;
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
    result = (Render::ParticleEmitterBuffer *)*v11;
  }
  else
  {
    if ( !canStealBuffer )
      goto LABEL_103;
    v17 = 32;
    if ( v9 )
      v17 = 4;
    v18 = UFG::Director::Get()->mCurrentCamera;
    v19 = (signed __int64)&v18->mCamera;
    if ( !v18 )
      v19 = 0i64;
    v20 = v4->mPriority;
    v21 = (signed __int64)v5->activeBuffers;
    v22 = 0i64;
    v23 = 0;
    v24 = 0.0;
    v25 = 0;
    v26 = 0;
    v79 = (signed __int64)v5->activeBuffers;
    do
    {
      v27 = *(_DWORD *)v21;
      v28 = 0;
      v29 = 0i64;
      if ( *(_DWORD *)v21 >= 4 )
      {
        v30 = 2;
        v31 = (_QWORD *)(*(_QWORD *)(v21 + 8) + 16i64);
        v29 = 4i64 * (((v27 - 4) >> 2) + 1);
        do
        {
          v32 = *(v31 - 2);
          if ( *(_DWORD *)(v32 + 52) == v17 && *(_BYTE *)(v32 + 268) >= v20 )
          {
            v33 = (__m128)*(unsigned int *)(v19 + 180);
            v34 = *(float *)(v19 + 176) - *(float *)(v32 + 248);
            v35 = *(float *)(v32 + 40);
            v33.m128_f32[0] = (float)((float)((float)(v33.m128_f32[0] - *(float *)(v32 + 252))
                                            * (float)(v33.m128_f32[0] - *(float *)(v32 + 252)))
                                    + (float)(v34 * v34))
                            + (float)((float)(*(float *)(v19 + 184) - *(float *)(v32 + 256))
                                    * (float)(*(float *)(v19 + 184) - *(float *)(v32 + 256)));
            LODWORD(v36) = (unsigned __int128)_mm_sqrt_ps(v33);
            if ( v35 == 0.0 )
              v37 = 0.0;
            else
              v37 = (float)(v6 - *(float *)(v32 + 44)) / (float)(v35 - *(float *)(v32 + 44));
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
          if ( *(_DWORD *)(v39 + 52) == v17 && *(_BYTE *)(v39 + 268) >= v20 )
          {
            v40 = (__m128)*(unsigned int *)(v19 + 180);
            v41 = *(float *)(v19 + 176) - *(float *)(v39 + 248);
            v42 = *(float *)(v39 + 40);
            v40.m128_f32[0] = (float)((float)((float)(v40.m128_f32[0] - *(float *)(v39 + 252))
                                            * (float)(v40.m128_f32[0] - *(float *)(v39 + 252)))
                                    + (float)(v41 * v41))
                            + (float)((float)(*(float *)(v19 + 184) - *(float *)(v39 + 256))
                                    * (float)(*(float *)(v19 + 184) - *(float *)(v39 + 256)));
            LODWORD(v43) = (unsigned __int128)_mm_sqrt_ps(v40);
            if ( v42 == 0.0 )
              v44 = 0.0;
            else
              v44 = (float)(v6 - *(float *)(v39 + 44)) / (float)(v42 - *(float *)(v39 + 44));
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
          if ( *(_DWORD *)(*v31 + 52i64) == v17 && *(_BYTE *)(v46 + 268) >= v20 )
          {
            v47 = (__m128)*(unsigned int *)(v19 + 180);
            v48 = *(float *)(v19 + 176) - *(float *)(v46 + 248);
            v49 = *(float *)(v46 + 40);
            v47.m128_f32[0] = (float)((float)((float)(v47.m128_f32[0] - *(float *)(v46 + 252))
                                            * (float)(v47.m128_f32[0] - *(float *)(v46 + 252)))
                                    + (float)(v48 * v48))
                            + (float)((float)(*(float *)(v19 + 184) - *(float *)(v46 + 256))
                                    * (float)(*(float *)(v19 + 184) - *(float *)(v46 + 256)));
            LODWORD(v50) = (unsigned __int128)_mm_sqrt_ps(v47);
            if ( v49 == 0.0 )
              v51 = 0.0;
            else
              v51 = (float)(v6 - *(float *)(v46 + 44)) / (float)(v49 - *(float *)(v46 + 44));
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
          if ( *(_DWORD *)(v53 + 52) == v17 && *(_BYTE *)(v53 + 268) >= v20 )
          {
            v54 = (__m128)*(unsigned int *)(v19 + 180);
            v55 = *(float *)(v19 + 176) - *(float *)(v53 + 248);
            v56 = *(float *)(v53 + 40);
            v54.m128_f32[0] = (float)((float)((float)(v54.m128_f32[0] - *(float *)(v53 + 252))
                                            * (float)(v54.m128_f32[0] - *(float *)(v53 + 252)))
                                    + (float)(v55 * v55))
                            + (float)((float)(*(float *)(v19 + 184) - *(float *)(v53 + 256))
                                    * (float)(*(float *)(v19 + 184) - *(float *)(v53 + 256)));
            LODWORD(v57) = (unsigned __int128)_mm_sqrt_ps(v54);
            if ( v56 == 0.0 )
              v58 = 0.0;
            else
              v58 = (float)(v6 - *(float *)(v53 + 44)) / (float)(v56 - *(float *)(v53 + 44));
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
        while ( v28 < v27 - 3 );
        v21 = v79;
      }
      if ( v28 < v27 )
      {
        v60 = *(_QWORD *)(v21 + 8) + 8 * v29;
        do
        {
          v61 = *(_QWORD *)v60;
          if ( *(_DWORD *)(*(_QWORD *)v60 + 52i64) == v17 && *(_BYTE *)(v61 + 268) >= v20 )
          {
            v62 = (__m128)*(unsigned int *)(v19 + 180);
            v63 = *(float *)(v19 + 176) - *(float *)(v61 + 248);
            v64 = *(float *)(v61 + 40);
            v62.m128_f32[0] = (float)((float)((float)(v62.m128_f32[0] - *(float *)(v61 + 252))
                                            * (float)(v62.m128_f32[0] - *(float *)(v61 + 252)))
                                    + (float)(v63 * v63))
                            + (float)((float)(*(float *)(v19 + 184) - *(float *)(v61 + 256))
                                    * (float)(*(float *)(v19 + 184) - *(float *)(v61 + 256)));
            LODWORD(v65) = (unsigned __int128)_mm_sqrt_ps(v62);
            if ( v64 == 0.0 )
              v66 = 0.0;
            else
              v66 = (float)(v6 - *(float *)(v61 + 44)) / (float)(v64 - *(float *)(v61 + 44));
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
        while ( v28 < v27 );
        v21 = v79;
      }
      v21 += 16i64;
      ++v26;
      v79 = v21;
    }
    while ( v26 < 3 );
    if ( v22 )
    {
      if ( v23 != v81 )
      {
        *(_QWORD *)(*((_QWORD *)&v80->mInstanceStateBlockIndex + 2 * (v23 + 3i64)) + 8i64 * v25) = v80->activeBuffers[v23].p[v80->activeBuffers[v23].size - 1];
        v68 = v80->activeBuffers[v23].size;
        if ( v68 > 1 )
          v80->activeBuffers[v23].size = v68 - 1;
        else
          v80->activeBuffers[v23].size = 0;
        v69 = (signed __int64)v80 + 16 * v81;
        v70 = *(unsigned int *)(v69 + 40);
        v71 = *(_DWORD *)(v69 + 44);
        v72 = v70 + 1;
        if ( (signed int)v70 + 1 > v71 )
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
        v74 = *(_QWORD *)(v69 + 48);
        *(_DWORD *)(v69 + 40) = v72;
        *(_QWORD *)(v74 + 8 * v70) = v22;
      }
      v75 = *(_QWORD *)(v22 + 288);
      if ( v75 )
      {
        (*(void (**)(void))(*(_QWORD *)v75 + 48i64))();
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
      *(float *)(v22 + 44) = v6;
      *(_DWORD *)(v22 + 40) = 0;
      *(_DWORD *)(v22 + 48) = 0;
      UFG::qMemSet(*(void **)v22, 0, 0x270u);
      UFG::qMemSet(*(void **)(v22 + 8), 0, 8u);
      *(_QWORD *)(v22 + 16) = 0i64;
      *(_QWORD *)(v22 + 24) = 0i64;
      result = (Render::ParticleEmitterBuffer *)v22;
    }
    else
    {
LABEL_103:
      result = 0i64;
    }
  }
  return result;
}

// File Line: 1139
// RVA: 0x1D1940
void __fastcall Render::MapGeoMaterialState(Illusion::Material *mat, Render::eParticleQueue queue)
{
  Render::eParticleQueue v2; // ebx
  Illusion::Material *v3; // rdi
  unsigned int v4; // eax
  unsigned int v5; // edx
  Illusion::Material *v6; // rax
  _WORD *v7; // rbx
  __int64 v8; // rax
  _WORD *v9; // rax
  Illusion::Material *v10; // rax
  __int64 v11; // rax
  Illusion::Material *v12; // rax

  v2 = queue;
  v3 = mat;
  v4 = _S7_5;
  if ( !(_S7_5 & 1) )
  {
    _S7_5 |= 1u;
    alphaStateUID = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    v4 = _S7_5;
  }
  if ( v4 & 2 )
  {
    v5 = rasterStateUID;
  }
  else
  {
    _S7_5 = v4 | 2;
    v5 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    rasterStateUID = v5;
  }
  if ( v2 )
  {
    if ( !Illusion::Material::GetParamByNameUID(v3, v5)->mResourceHandles.mNode.mPrev )
    {
      v12 = Illusion::Material::GetParamByNameUID(v3, rasterStateUID);
      if ( v12 )
      {
        if ( LODWORD(v12->mResourceHandles.mNode.mNext) != -262489691 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v12->mNode.mChild[1], v12->mTypeUID, 0xF05AB9A5);
          v11 = v3->mMaterialUser.mOffset;
          if ( !v11 )
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
    v6 = Illusion::Material::GetParamByNameUID(v3, alphaStateUID);
    v7 = 0i64;
    if ( v6 && LODWORD(v6->mResourceHandles.mNode.mNext) != 662883558 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mNode.mChild[1], v6->mTypeUID, 0x2782CCE6u);
      v8 = v3->mMaterialUser.mOffset;
      if ( v8 )
        v9 = (_WORD *)((char *)&v3->mMaterialUser + v8);
      else
        v9 = 0i64;
      *v9 |= 0x20u;
    }
    v10 = Illusion::Material::GetParamByNameUID(v3, rasterStateUID);
    if ( v10 && LODWORD(v10->mResourceHandles.mNode.mNext) != 543723269 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v10->mNode.mChild[1], v10->mTypeUID, 0x20688F05u);
      v11 = v3->mMaterialUser.mOffset;
      if ( !v11 )
      {
LABEL_22:
        *v7 |= 0x20u;
        return;
      }
LABEL_16:
      v7 = (_WORD *)((char *)&v3->mMaterialUser + v11);
      goto LABEL_22;
    }
  }
}

// File Line: 1169
// RVA: 0x1DBB90
void __fastcall Render::ParticleEmitterManager::UpdateRaycasts(Render::ParticleEmitterManager *this)
{
  Render::ParticleEmitterBuffer ***v1; // rax
  unsigned int v2; // esi
  unsigned int v3; // er15
  Render::ParticleEmitterBuffer ***v4; // r12
  signed __int64 v5; // r13
  unsigned int v6; // eax
  __int64 v7; // r14
  __int64 v8; // rbp
  Render::ParticleEmitterBuffer *v9; // rcx
  Render::ParticleRaycaster *v10; // rbx
  float v11; // xmm0_4
  float v12; // xmm1_4
  Render::ParticleRaycaster::Mode v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  Render::ParticleEmitterBuffer ***v17; // [rsp+58h] [rbp+10h]

  v1 = &this->activeBuffers[0].p;
  v2 = 36;
  v17 = &this->activeBuffers[0].p;
  v3 = 0;
  do
  {
    v4 = v1;
    v5 = 3i64;
    do
    {
      v6 = *((_DWORD *)v4 - 2);
      if ( v6 )
      {
        v7 = 0i64;
        v8 = v6;
        while ( 1 )
        {
          v9 = (*v4)[v7];
          if ( v3 )
            break;
          v10 = v9->mRaycaster;
          if ( (unsigned int)(v10->mMode - 1) <= 1 )
            goto LABEL_10;
LABEL_22:
          ++v7;
          if ( !--v8 )
            goto LABEL_23;
        }
        if ( v3 != 1 )
          goto LABEL_22;
        v10 = v9->mRaycaster;
        if ( (unsigned int)(v10->mMode - 1) <= 1 )
          goto LABEL_22;
LABEL_10:
        v11 = v9->mLastKnownGoodBasis.v3.y;
        v12 = v9->mLastKnownGoodBasis.v3.z;
        v10->mPosition.x = v9->mLastKnownGoodBasis.v3.x;
        v10->mPosition.y = v11;
        v10->mPosition.z = v12;
        v13 = v10->mMode;
        if ( v13 == 3 )
        {
          v14 = Render::ParticleRaycaster::IssueQueries(v10, v2);
          ++v10->mRaycastComboIndex;
          v15 = v14;
          if ( v10->mRaycastComboIndex >= 2 )
            v10->mRaycastComboIndex = 0;
        }
        else
        {
          if ( v13 == 2 )
          {
            if ( v2 > 0xC )
            {
              v15 = 0;
              v10->mRaycastComboIndex = 0;
              do
              {
                v16 = Render::ParticleRaycaster::IssueQueries(v10, v2);
                ++v10->mRaycastComboIndex;
                v15 += v16;
              }
              while ( v10->mRaycastComboIndex < 2 );
              *(_QWORD *)&v10->mMode = 1i64;
              goto LABEL_21;
            }
          }
          else if ( v13 == 4 )
          {
            v10->mMode = 0;
          }
          v15 = 0;
        }
LABEL_21:
        v2 -= v15;
        goto LABEL_22;
      }
LABEL_23:
      v4 += 2;
      --v5;
    }
    while ( v5 );
    v1 = v17;
    ++v3;
  }
  while ( v3 < 2 );
}

// File Line: 1194
// RVA: 0x1D6300
void __fastcall Render::ParticleEmitterManager::SetAuxBuffers(Render::ParticleEmitterManager *this, Render::View *view, Render::eParticleQueue queue, Render::FXManagerAuxBuffers *auxBuffers)
{
  Render::FXManagerAuxBuffers *v4; // rdi
  Render::View *v5; // r14
  signed __int16 *v6; // r15
  Illusion::Texture *v7; // rsi
  unsigned int v8; // ebp
  Illusion::StateValues *v9; // rax
  Illusion::Texture *v10; // rsi
  unsigned int v11; // ebp
  Illusion::StateValues *v12; // rax
  Illusion::Texture *v13; // rsi
  unsigned int v14; // ebp
  Illusion::StateValues *v15; // rax
  Illusion::Texture *v16; // rsi
  unsigned int v17; // ebp
  Illusion::StateValues *v18; // rax
  Illusion::Texture *v19; // rdi
  unsigned int v20; // esi
  Illusion::StateValues *v21; // rax

  v4 = auxBuffers;
  v5 = view;
  v6 = &this->mInstanceStateBlockIndex;
  if ( (unsigned int)(queue - 1) <= 1 )
  {
    v7 = auxBuffers->scrDepth;
    if ( auxBuffers->scrDepth )
    {
      v8 = SLOWORD(this->mTexDepthStateIndex);
      v9 = Render::View::GetStateValues(view);
      if ( v8 >= 0x40 )
        v9->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v8 - 64);
      else
        v9->mSetValueMask.mFlags[0] |= 1i64 << v8;
      v9->mParamValues[(signed __int16)v8] = v7;
    }
    v10 = v4->scrDiffuse;
    if ( v10 )
    {
      v11 = v6[64];
      v12 = Render::View::GetStateValues(v5);
      if ( v11 >= 0x40 )
        v12->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v11 - 64);
      else
        v12->mSetValueMask.mFlags[0] |= 1i64 << v11;
      v12->mParamValues[(signed __int16)v11] = v10;
    }
    v13 = v4->texShadowAtlas;
    if ( v13 )
    {
      v14 = v6[66];
      v15 = Render::View::GetStateValues(v5);
      if ( v14 >= 0x40 )
        v15->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v14 - 64);
      else
        v15->mSetValueMask.mFlags[0] |= 1i64 << v14;
      v15->mParamValues[(signed __int16)v14] = v13;
    }
    v16 = v4->texHeightmap;
    if ( v16 )
    {
      v17 = v6[68];
      v18 = Render::View::GetStateValues(v5);
      if ( v17 >= 0x40 )
        v18->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v17 - 64);
      else
        v18->mSetValueMask.mFlags[0] |= 1i64 << v17;
      v18->mParamValues[(signed __int16)v17] = v16;
    }
    v19 = v4->texHeightmapShadow;
    if ( v19 )
    {
      v20 = v6[70];
      v21 = Render::View::GetStateValues(v5);
      if ( v20 >= 0x40 )
        v21->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v20 - 64);
      else
        v21->mSetValueMask.mFlags[0] |= 1i64 << v20;
      v21->mParamValues[(signed __int16)v20] = v19;
    }
  }
}

// File Line: 1222
// RVA: 0x1D6A80
signed __int64 __fastcall Render::ParticleEmitterManager::SetTexShadowAtlas(Render::ParticleEmitterManager *this, Illusion::Material *material, Render::FXManagerAuxBuffers *auxBuffers)
{
  unsigned int v3; // ebx
  Illusion::Material *v4; // rdi
  unsigned int v5; // er8
  __int64 v6; // rax

  v3 = (unsigned int)material[1].mResourceHandles.mNode.mNext;
  v4 = material;
  if ( auxBuffers->texShadowAtlas )
    return 0xFFFFFFFFi64;
  if ( v3 != this->mShaderParticleLitShadowUID )
  {
    if ( v3 == this->mShaderParticleSoftLitShadowUID )
    {
      v5 = this->mShaderParticleSoftLitUID;
      goto LABEL_4;
    }
    return 0xFFFFFFFFi64;
  }
  v5 = this->mShaderParticleLitUID;
LABEL_4:
  if ( v3 != v5 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&material[1].mNode.mChild[1], material[1].mTypeUID, v5);
    v6 = v4->mMaterialUser.mOffset;
    if ( v6 )
    {
      *(_WORD *)((char *)&v4->mMaterialUser.mOffset + v6) |= 0x20u;
      return v3;
    }
    LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
  }
  return v3;
}

// File Line: 1244
// RVA: 0x1D0800
void __fastcall Render::ParticleEmitterManager::InitStateSystemParams(Render::ParticleEmitterManager *this)
{
  Render::ParticleEmitterManager *v1; // rbx
  unsigned int v2; // eax

  v1 = this;
  v2 = UFG::qStringHash32("cbInstancing", 0xFFFFFFFF);
  v1->mInstanceStateBlockIndex = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v2, "cbInstancing", 0);
  v1->mParticleSoftSettingsStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                            &Illusion::gStateSystem,
                                                            "cbParticleSoftSettings",
                                                            0);
  v1->mParticleDynamicLightSettingsStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                                    &Illusion::gStateSystem,
                                                                    "cbParticleDynamicLightSettings",
                                                                    0);
  v1->mParticleSettingsStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                        &Illusion::gStateSystem,
                                                        "cbParticleSettings",
                                                        0);
  v1->mFXSizeModuleStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                    &Illusion::gStateSystem,
                                                    "cbFXSizeModule",
                                                    0);
  v1->mTexDepthStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "texDepth", 1);
  v1->mTexDiffuse2StateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                   &Illusion::gStateSystem,
                                                   "texDiffuse2",
                                                   1);
  v1->mTexShadowAtlasStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                      &Illusion::gStateSystem,
                                                      "texShadowAtlas",
                                                      1);
  v1->mTexHeightmapStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                    &Illusion::gStateSystem,
                                                    "texHeightmap",
                                                    1);
  v1->mTexHeightmapShadowStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                          &Illusion::gStateSystem,
                                                          "texShadow",
                                                          1);
  v1->mParticleFlowMapStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                       &Illusion::gStateSystem,
                                                       "cbFXFlowmapSettings",
                                                       1);
}

// File Line: 1259
// RVA: 0x1D71A0
void __fastcall Render::ParticleEmitterManager::SetupLighting(Render::ParticleEmitterManager *this, Render::View *view, Render::ParticleEmitterSettings *pfxSettings)
{
  Render::ParticleEmitterManager *v3; // rsi
  Render::ParticleEmitterSettings *v4; // rdi
  Render::View *v5; // rbx
  Illusion::ShaderSelector *v6; // r8
  unsigned int v7; // ecx

  v3 = this;
  v4 = pfxSettings;
  v5 = view;
  Render::View::GetStateValues(view);
  v6 = v5->mSubmitContext->mShaderSelector;
  v7 = v3->mParticleDynamicLightSettingsStateIndex;
  if ( v4->mSettings.LightInfo[1] <= 0.0 )
  {
    v6->mAddState.mFlags[v7 >> 6] &= ~(1i64 << (v7 & 0x3F));
  }
  else if ( v7 >= 0x40 )
  {
    v6->mAddState.mFlags[1] |= 1i64 << ((unsigned __int8)v7 - 64);
  }
  else
  {
    v6->mAddState.mFlags[0] |= 1i64 << v7;
  }
}

// File Line: 1275
// RVA: 0x1D6740
void __fastcall Render::ParticleEmitterManager::SetSoftSettings(Render::ParticleEmitterManager *this, Render::View *view, Render::ParticleEmitterSettings *pfxSettings)
{
  Render::ParticleEmitterManager *v3; // rbp
  Render::ParticleEmitterSettings *v4; // r14
  Render::View *v5; // r15
  Illusion::ShaderSelector *v6; // rdi
  char *v7; // rax
  float *v8; // rsi
  float *v9; // rbx
  UFG::BaseCameraComponent *v10; // rax
  float *v11; // rax
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
  unsigned int v36; // ebx
  Illusion::StateValues *v37; // rax
  bool v38; // zf
  unsigned int v39; // ecx
  float v40; // [rsp+60h] [rbp+8h]

  v3 = this;
  v4 = pfxSettings;
  v5 = view;
  Render::View::GetStateValues(view);
  v6 = v5->mSubmitContext->mShaderSelector;
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  *(float *)v7 = v4->mSoftContrast;
  v8 = (float *)v7;
  *((_DWORD *)v7 + 1) = LODWORD(v4->mSoftScale);
  *((float *)v7 + 2) = 1.0 / (float)((float)(signed int)Render::View::GetTargetWidth(v5) * 0.5);
  v8[3] = 1.0 / (float)((float)(signed int)Render::View::GetTargetHeight(v5) * 0.5);
  v9 = 0i64;
  v10 = UFG::Director::Get()->mCurrentCamera;
  if ( v10 )
    v11 = &v10->mCamera.mFOVOffset;
  else
    v11 = 0i64;
  v12 = v11[58];
  v13 = v11[59];
  if ( v12 == 0.0 || v12 == v13 )
    v14 = v40;
  else
    v14 = (float)(v11[62] - v11[63]) / (float)(v12 - v13);
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
  v36 = SLOWORD(v3->mParticleSoftSettingsStateIndex);
  v37 = Render::View::GetStateValues(v5);
  if ( v36 >= 0x40 )
    v37->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v36 - 64);
  else
    v37->mSetValueMask.mFlags[0] |= 1i64 << v36;
  v38 = v4->mSoftScale == 0.0;
  v37->mParamValues[(signed __int16)v36] = v8;
  if ( v38 || 0.0 == v4->mSoftContrast )
  {
    v6->mAddState.mFlags[v3->mParticleSoftSettingsStateIndex >> 6] &= ~(1i64 << (v3->mParticleSoftSettingsStateIndex & 0x3F));
  }
  else
  {
    v39 = v3->mParticleSoftSettingsStateIndex;
    if ( v39 >= 0x40 )
      v6->mAddState.mFlags[1] |= 1i64 << ((unsigned __int8)v39 - 64);
    else
      v6->mAddState.mFlags[0] |= 1i64 << v39;
  }
}

// File Line: 1306
// RVA: 0x1D6FE0
void __fastcall Render::ParticleEmitterManager::SetupFlowmap(Render::ParticleEmitterManager *this, Render::View *view, Render::ParticleEmitterSettings *pfxSettings)
{
  Render::ParticleEmitterSettings *v3; // rsi
  Render::View *v4; // rbp
  Render::ParticleEmitterManager *v5; // r14
  UFG::qResourceWarehouse *v6; // rax
  Illusion::ShaderSelector *v7; // rdi
  __int64 v8; // rbx
  Illusion::StateValues *v9; // rax
  char *v10; // rax
  char *v11; // rbx
  unsigned int v12; // esi
  Illusion::StateValues *v13; // rax
  unsigned int v14; // ecx

  v3 = pfxSettings;
  v4 = view;
  v5 = this;
  if ( !(_S8_5 & 1) )
  {
    _S8_5 |= 1u;
    v6 = UFG::qResourceWarehouse::Instance();
    texInventory_2 = UFG::qResourceWarehouse::GetInventory(v6, 0x8B43FABF);
  }
  Render::View::GetStateValues(v4);
  v7 = v4->mSubmitContext->mShaderSelector;
  if ( v3->mFlowmapTextureID )
  {
    v8 = ((__int64 (__cdecl *)(UFG::qResourceInventory *))texInventory_2->vfptr->Get)(texInventory_2);
    v9 = Render::View::GetStateValues(v4);
    v9->mSetValueMask.mFlags[1] |= 0x80ui64;
    v9->mParamValues[71] = (void *)v8;
    v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    v11 = v10;
    *(float *)v10 = v3->mFlowmapSettings.FlowmapConstants[0];
    *((_DWORD *)v10 + 1) = LODWORD(v3->mFlowmapSettings.FlowmapConstants[1]);
    *((_DWORD *)v10 + 2) = LODWORD(v3->mFlowmapSettings.FlowmapConstants[2]);
    *((_DWORD *)v10 + 3) = LODWORD(v3->mFlowmapSettings.FlowmapConstants[3]);
    *((_DWORD *)v10 + 4) = LODWORD(v3->mFlowmapSettings.FlowmapDistortOverTimeKeys[0]);
    *((_DWORD *)v10 + 5) = LODWORD(v3->mFlowmapSettings.FlowmapDistortOverTimeKeys[1]);
    *((_DWORD *)v10 + 6) = LODWORD(v3->mFlowmapSettings.FlowmapDistortOverTimeKeys[2]);
    *((_DWORD *)v10 + 7) = LODWORD(v3->mFlowmapSettings.FlowmapDistortOverTimeKeys[3]);
    *((_DWORD *)v10 + 8) = LODWORD(v3->mFlowmapSettings.FlowmapDistortOverTimeKeyPos[0]);
    *((_DWORD *)v10 + 9) = LODWORD(v3->mFlowmapSettings.FlowmapDistortOverTimeKeyPos[1]);
    *((_DWORD *)v10 + 10) = LODWORD(v3->mFlowmapSettings.FlowmapDistortOverTimeKeyPos[2]);
    *((_DWORD *)v10 + 11) = LODWORD(v3->mFlowmapSettings.FlowmapDistortOverTimeKeyPos[3]);
    v12 = SLOWORD(v5->mParticleFlowMapStateIndex);
    v13 = Render::View::GetStateValues(v4);
    if ( v12 >= 0x40 )
      v13->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v12 - 64);
    else
      v13->mSetValueMask.mFlags[0] |= 1i64 << v12;
    v13->mParamValues[(signed __int16)v12] = v11;
    v14 = v5->mParticleFlowMapStateIndex;
    if ( v14 >= 0x40 )
      v7->mAddState.mFlags[1] |= 1i64 << ((unsigned __int8)v14 - 64);
    else
      v7->mAddState.mFlags[0] |= 1i64 << v14;
  }
  else
  {
    v7->mAddState.mFlags[v5->mParticleFlowMapStateIndex >> 6] &= ~(1i64 << (v5->mParticleFlowMapStateIndex & 0x3F));
  }
}

// File Line: 1412
// RVA: 0x1D4AE0
void __fastcall Render::ParticleEmitterManager::Render(Render::ParticleEmitterManager *this, Render::View *view, float fTime, Render::eParticleQueue queue, Render::FXManagerAuxBuffers *auxBuffers)
{
  Render::View *v5; // r15
  Render::ParticleEmitterManager *v6; // rdi
  char *v7; // r14
  char *v8; // rax
  Render::FXOverride *v9; // r10
  char *v10; // rbx
  unsigned int v11; // esi
  Illusion::StateValues *v12; // rax
  int v13; // ebx
  unsigned int v14; // edx
  signed __int64 v15; // rax
  __int64 v16; // r13
  __int64 v17; // r12
  Render::ParticleEmitterBuffer *v18; // rbx
  UFG::qResourceData *v19; // rsi
  char *v20; // rax
  UFG::qResourceData *v21; // rdx
  char *v22; // r14
  char *v23; // r8
  signed __int64 v24; // rcx
  __int128 v25; // xmm0
  unsigned int v26; // ebp
  Illusion::StateValues *v27; // rax
  char *v28; // rax
  unsigned int v29; // ebp
  Illusion::StateValues *v30; // rax
  unsigned int v31; // ecx
  Illusion::ShaderSelector *v32; // r8
  unsigned int v33; // eax
  Illusion::Material *v34; // rsi
  UFG::qBaseNodeRB **v35; // rcx
  unsigned int v36; // ebp
  __int64 *v37; // rdx
  __int64 v38; // rax
  Illusion::Material *v39; // rcx
  Illusion::Material *v40; // rbx
  _WORD *v41; // rax
  signed __int64 v42; // [rsp+20h] [rbp-58h]
  int v43; // [rsp+80h] [rbp+8h]
  Render::eParticleQueue queuea; // [rsp+98h] [rbp+20h]

  queuea = queue;
  v5 = view;
  v6 = this;
  v7 = (char *)(unsigned int)queue;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  v9 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer;
  v10 = v8;
  *(float *)v8 = Render::gFXManager.mStateBlockDefaultOverride.m_pPointer->stateBlock.ColorTint[0];
  *((_DWORD *)v8 + 1) = LODWORD(v9->stateBlock.ColorTint[1]);
  *((_DWORD *)v8 + 2) = LODWORD(v9->stateBlock.ColorTint[2]);
  *((_DWORD *)v8 + 3) = LODWORD(v9->stateBlock.ColorTint[3]);
  *((_DWORD *)v8 + 4) = LODWORD(v9->stateBlock.Params1[0]);
  *((_DWORD *)v8 + 5) = LODWORD(v9->stateBlock.Params1[1]);
  *((_DWORD *)v8 + 6) = LODWORD(v9->stateBlock.Params1[2]);
  *((_DWORD *)v8 + 7) = LODWORD(v9->stateBlock.Params1[3]);
  v11 = Render::gFXManager.mFXOverrideStateParamIndex;
  v12 = Render::View::GetStateValues(v5);
  if ( v11 >= 0x40 )
    v12->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v11 - 64);
  else
    v12->mSetValueMask.mFlags[0] |= 1i64 << v11;
  v12->mParamValues[(signed __int16)v11] = v10;
  Render::ParticleEmitterManager::KillExpiredBuffers(v6, (Render::eParticleQueue)v7, fTime);
  Render::ParticleEmitterManager::DistanceSort(v6, v5, (Render::eParticleQueue)v7);
  v13 = 0;
  v43 = 0;
  v14 = v6->activeBuffers[(_QWORD)v7].size;
  if ( v14 )
  {
    v15 = 16i64 * (_QWORD)(v7 + 3);
    v16 = v14;
    v42 = 16i64 * (_QWORD)(v7 + 3);
    v17 = 0i64;
    do
    {
      v18 = *(Render::ParticleEmitterBuffer **)(v17 + *(_QWORD *)((char *)&v6->mInstanceStateBlockIndex + v15));
      if ( v18->mModel.mData && v18->mCount )
      {
        v19 = v18->mCreatorSettings.mData;
        if ( v19 )
        {
          v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
          v21 = v19 + 1;
          v22 = v20;
          v23 = v20;
          if ( ((unsigned __int8)v20 | (unsigned __int8)((_BYTE)v19 + 88)) & 0xF )
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
          v26 = SLOWORD(v6->mParticleSettingsStateIndex);
          v27 = Render::View::GetStateValues(v5);
          if ( v26 >= 0x40 )
            v27->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v26 - 64);
          else
            v27->mSetValueMask.mFlags[0] |= 1i64 << v26;
          v27->mParamValues[(signed __int16)v26] = v22;
          v28 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
          *(_DWORD *)v28 = v19[3].mNode.mChild[1];
          v7 = v28;
          *((_DWORD *)v28 + 1) = HIDWORD(v19[3].mNode.mChild[1]);
          *((_DWORD *)v28 + 2) = v19[3].mNode.mUID;
          *((_DWORD *)v28 + 3) = *(&v19[3].mNode.mUID + 1);
          *((_DWORD *)v28 + 4) = v19[3].mResourceHandles.mNode.mPrev;
          *((_DWORD *)v28 + 5) = HIDWORD(v19[3].mResourceHandles.mNode.mPrev);
          *((_DWORD *)v28 + 6) = v19[3].mResourceHandles.mNode.mNext;
          *((_DWORD *)v28 + 7) = HIDWORD(v19[3].mResourceHandles.mNode.mNext);
          *((_DWORD *)v28 + 8) = v19[3].mTypeUID;
          *((_DWORD *)v28 + 9) = *(_DWORD *)v19[3].mDebugName;
          *((_DWORD *)v28 + 10) = *(_DWORD *)&v19[3].mDebugName[4];
          *((_DWORD *)v28 + 11) = *(_DWORD *)&v19[3].mDebugName[8];
          *((_DWORD *)v28 + 12) = *(_DWORD *)&v19[3].mDebugName[12];
          *((_DWORD *)v28 + 13) = *(_DWORD *)&v19[3].mDebugName[16];
          *((_DWORD *)v28 + 14) = *(_DWORD *)&v19[3].mDebugName[20];
          *((_DWORD *)v28 + 15) = *(_DWORD *)&v19[3].mDebugName[24];
          v29 = SLOWORD(v6->mFXSizeModuleStateIndex);
          v30 = Render::View::GetStateValues(v5);
          if ( v29 >= 0x40 )
            v30->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v29 - 64);
          else
            v30->mSetValueMask.mFlags[0] |= 1i64 << v29;
          v30->mParamValues[(signed __int16)v29] = v7;
          LODWORD(v7) = queuea;
          Render::ParticleEmitterManager::SetAuxBuffers(v6, v5, queuea, auxBuffers);
          Render::ParticleEmitterManager::SetSoftSettings(v6, v5, (Render::ParticleEmitterSettings *)v19);
          Render::ParticleEmitterManager::SetupLighting(v6, v5, (Render::ParticleEmitterSettings *)v19);
          Render::ParticleEmitterManager::SetupFlowmap(v6, v5, (Render::ParticleEmitterSettings *)v19);
          v31 = v6->mTexHeightmapStateIndex;
          v32 = v5->mSubmitContext->mShaderSelector;
          if ( v19[4].mDebugName[20] >= 0 )
          {
            v32->mAddState.mFlags[v31 >> 6] &= ~(1i64 << (v31 & 0x3F));
          }
          else if ( v31 >= 0x40 )
          {
            v32->mAddState.mFlags[1] |= 1i64 << ((unsigned __int8)v31 - 64);
          }
          else
          {
            v32->mAddState.mFlags[0] |= 1i64 << v31;
          }
        }
        v43 += v18->mCount;
        v33 = Render::ParticleEmitterManager::SetTexShadowAtlas(v6, v18->mParticleMaterial, auxBuffers);
        v34 = v18->mParticleMaterial;
        v35 = v18->mModel.mData[2].mNode.mChild;
        v36 = v33;
        if ( *v35 )
          v37 = (__int64 *)((char *)v35 + (_QWORD)*v35);
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
            v34 = *(Illusion::Material **)(v38 + 16);
            Render::MapGeoMaterialState(v39, (Render::eParticleQueue)v7);
          }
        }
        Render::ParticleEmitterBuffer::Draw(v18, v5, v34);
        if ( v36 != -1 )
        {
          v40 = v18->mParticleMaterial;
          if ( LODWORD(v40[1].mResourceHandles.mNode.mNext) != v36 )
          {
            UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v40[1].mNode.mChild[1], v40[1].mTypeUID, v36);
            v41 = (_WORD *)v40->mMaterialUser.mOffset;
            if ( v41 )
              v41 = (_WORD *)((char *)v41 + (_QWORD)v40 + 120);
            *v41 |= 0x20u;
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
  Render::View::AddMetric_NumParticles(v5, v13);
  v6->mRunningParticleCount += v13;
}

// File Line: 1514
// RVA: 0x1CB280
bool __fastcall Render::ParticleEmitterManager::DistanceCompare(Render::ParticleEmitterBuffer *const *a, Render::ParticleEmitterBuffer *const *b)
{
  Render::ParticleEmitterBuffer *v2; // r8
  Render::ParticleEmitterBuffer *v3; // r9
  unsigned int v4; // ecx
  unsigned int v5; // edx
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  unsigned int v10; // ecx
  unsigned int v11; // edx
  bool v12; // cf

  v2 = *a;
  v3 = *b;
  v4 = (*a)->mParentFXId;
  v5 = (*b)->mParentFXId;
  v6 = (float)((float)((float)(v2->mLastKnownEffectPos.y
                             - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y)
                     * (float)(v2->mLastKnownEffectPos.y
                             - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y))
             + (float)((float)(v2->mLastKnownEffectPos.x
                             - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x)
                     * (float)(v2->mLastKnownEffectPos.x
                             - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x)))
     + (float)((float)(v2->mLastKnownEffectPos.z - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z)
             * (float)(v2->mLastKnownEffectPos.z - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z));
  v7 = (float)((float)((float)(v3->mLastKnownEffectPos.y
                             - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y)
                     * (float)(v3->mLastKnownEffectPos.y
                             - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y))
             + (float)((float)(v3->mLastKnownEffectPos.x
                             - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x)
                     * (float)(v3->mLastKnownEffectPos.x
                             - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x)))
     + (float)((float)(v3->mLastKnownEffectPos.z - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z)
             * (float)(v3->mLastKnownEffectPos.z - Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z));
  if ( v4 == v5 )
  {
    v10 = v2->mComponentIndex;
    v11 = v3->mComponentIndex;
    v12 = v10 < v11;
    if ( v10 == v11 )
      return v3->mCreationTime < v2->mCreationTime;
  }
  else
  {
    v8 = v7 - v6;
    if ( (float)(v7 - v6) < 0.0 )
      LODWORD(v8) ^= _xmm[0];
    if ( v8 >= 0.1 )
      return v6 > v7;
    v12 = v4 < v5;
  }
  return v12;
}

// File Line: 1553
// RVA: 0x1D15D0
void __fastcall Render::ParticleEmitterManager::KillExpiredBuffers(Render::ParticleEmitterManager *this, Render::eParticleQueue queue_index, float fTime)
{
  Render::ParticleEmitterManager *v3; // rsi
  __int64 v4; // rbp
  unsigned int v5; // er12
  signed __int64 v6; // r13
  Render::ParticleEmitterBuffer *v7; // r14
  Render::ParticleRaycaster *v8; // rax
  unsigned int v9; // eax
  Render::ParticleRaycaster *v10; // rax
  __int64 v11; // r15
  unsigned int v12; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  Render::ParticleEmitterBuffer **v15; // rax
  unsigned int v16; // edx
  unsigned int v17; // ebx
  unsigned int v18; // edx
  Render::eParticleQueue v19; // [rsp+68h] [rbp+10h]

  v19 = queue_index;
  v3 = this;
  v4 = 0i64;
  v5 = this->activeBuffers[queue_index].size;
  if ( v5 )
  {
    v6 = 2 * ((signed int)queue_index + 3i64);
    do
    {
      if ( fTime > *(float *)(*(_QWORD *)(*((_QWORD *)&v3->mInstanceStateBlockIndex + v6) + 8 * v4) + 40i64) )
      {
        v7 = *(Render::ParticleEmitterBuffer **)(*((_QWORD *)&v3->mInstanceStateBlockIndex
                                                 + 2 * ((unsigned int)queue_index + 3i64))
                                               + 8 * v4);
        v8 = v7->mRaycaster;
        if ( v8 )
          v8->mMode = 4;
        *(_QWORD *)(*((_QWORD *)&v3->mInstanceStateBlockIndex + 2 * ((unsigned int)queue_index + 3i64)) + 8 * v4) = v3->activeBuffers[queue_index].p[v3->activeBuffers[queue_index].size - 1];
        v9 = v3->activeBuffers[queue_index].size;
        if ( v9 > 1 )
          v3->activeBuffers[queue_index].size = v9 - 1;
        else
          v3->activeBuffers[queue_index].size = 0;
        v10 = v7->mRaycaster;
        if ( v10 )
          v10->mMode = 4;
        Render::ParticleEmitterBuffer::Deactivate(v7);
        if ( v7->mCapacity == 32 )
        {
          v11 = v3->freeBuffersLarge.size;
          v12 = v3->freeBuffersLarge.capacity;
          v13 = v11 + 1;
          if ( (signed int)v11 + 1 > v12 )
          {
            if ( v12 )
              v14 = 2 * v12;
            else
              v14 = 1;
            for ( ; v14 < v13; v14 *= 2 )
              ;
            if ( v14 <= 2 )
              v14 = 2;
            if ( v14 - v13 > 0x10000 )
              v14 = v11 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v3->freeBuffersLarge,
              v14,
              "qArray.Add");
          }
          v15 = v3->freeBuffersLarge.p;
          v3->freeBuffersLarge.size = v13;
        }
        else
        {
          v11 = v3->freeBuffersSmall.size;
          v16 = v3->freeBuffersSmall.capacity;
          v17 = v11 + 1;
          if ( (signed int)v11 + 1 > v16 )
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
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v3->freeBuffersSmall,
              v18,
              "qArray.Add");
          }
          v15 = v3->freeBuffersSmall.p;
          v3->freeBuffersSmall.size = v17;
        }
        queue_index = v19;
        LODWORD(v4) = v4 - 1;
        v15[v11] = v7;
        --v5;
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v5 );
  }
}

// File Line: 1571
// RVA: 0x1D1430
void __fastcall Render::ParticleEmitterManager::KillBuffersWithParent(Render::ParticleEmitterManager *this, unsigned int parentFXId)
{
  unsigned int v2; // er12
  Render::ParticleEmitterManager *v3; // r15
  Render::ParticleEmitterBuffer ***v4; // r14
  unsigned int v5; // ebp
  unsigned int v6; // esi
  unsigned int v7; // ebx
  Render::ParticleEmitterBuffer *v8; // rdi
  UFG::qTask *v9; // rdx
  float v10; // xmm6_4
  Render::ParticleRenderUpdateTaskOutputParam *v11; // rax
  Render::ParticleRenderUpdateTaskParam *v12; // rax

  v2 = parentFXId;
  v3 = this;
  v4 = &this->activeBuffers[0].p;
  v5 = 0;
  do
  {
    v6 = *((_DWORD *)v4 - 2);
    v7 = 0;
    if ( v6 )
    {
      do
      {
        v8 = (*v4)[v7];
        if ( v8->mParentFXId == v2 )
        {
          v9 = v8->mTaskInfo.task;
          if ( v9 )
          {
            v10 = v8->mExpiry;
            UFG::qTaskManager::Sync(&UFG::gTaskManager, v9);
            v11 = v8->mTaskInfo.outputParam;
            if ( v10 < v11->lastExpiry )
              v10 = v11->lastExpiry;
            v8->mCount = v11->numParticlesInBuffer;
            v12 = v8->mTaskInfo.inputParam;
            v8->mTaskInfo.instance = 0i64;
            v8->mTaskInfo.task = 0i64;
            v12->currentAddCount = 0;
            UFG::qMemSet(v8->mTaskInfo.outputParam, 0, 8u);
            v8->mExpiry = v10;
          }
          Render::ParticleEmitterManager::AddToFreeBufferList(v3, v5, v7--);
          --v6;
        }
        ++v7;
      }
      while ( v7 < v6 );
    }
    ++v5;
    v4 += 2;
  }
  while ( v5 < 3 );
}

// File Line: 1716
// RVA: 0x1CB380
void __fastcall Render::ParticleEmitterManager::DistanceSort(Render::ParticleEmitterManager *this, Render::View *view, Render::eParticleQueue queue)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  signed int v5; // edx
  __int64 v6; // rsi
  __int64 v7; // rax
  __int64 v8; // r15
  Render::ParticleEmitterBuffer **v9; // r12
  int v10; // ebp
  Render::ParticleEmitterBuffer *v11; // r13
  int v12; // edi
  __int64 v13; // rbx
  __int64 v14; // rax
  __int64 v15; // [rsp+60h] [rbp+8h]
  Render::ParticleEmitterBuffer *a; // [rsp+68h] [rbp+10h]

  v3 = view->mViewWorld.v3.y;
  v4 = view->mViewWorld.v3.z;
  Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.x = view->mViewWorld.v3.x;
  Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.y = v3;
  Render::ParticleEmitterManager::mCameraPositionForDistanceCompare.z = v4;
  v5 = this->activeBuffers[queue].size;
  if ( v5 )
  {
    v6 = *((_QWORD *)&this->mInstanceStateBlockIndex + 2 * ((signed int)queue + 3i64));
    if ( v5 > 1 )
    {
      v7 = (unsigned int)(v5 - 1);
      v8 = 0i64;
      v9 = (Render::ParticleEmitterBuffer **)(v6 + 8);
      v15 = (unsigned int)(v5 - 1);
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
            if ( !Render::ParticleEmitterManager::DistanceCompare(
                    &a,
                    (Render::ParticleEmitterBuffer *const *)(v6 + 8i64 * v12)) )
              break;
            v14 = *(_QWORD *)(v6 + 8 * v13--);
            --v12;
            *(_QWORD *)(v6 + 8 * v13 + 16) = v14;
          }
          while ( v12 >= 0 );
          v7 = v15;
        }
        ++v10;
        ++v9;
        ++v8;
        --v7;
        *(_QWORD *)(v6 + 8 * v13 + 8) = v11;
        v15 = v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 1746
// RVA: 0x1D8390
void __fastcall Render::ParticleEmitterManager::StartTasks(Render::ParticleEmitterManager *this, float simTime, float deltaTime, Render::FXManagerLights *lightList)
{
  Render::FXManagerLights *v4; // r13
  Render::ParticleEmitterManager *v5; // r14
  UFG::BaseCameraComponent *v6; // rax
  UFG::qVector3 *cameraPos; // r12
  signed __int64 v8; // rsi
  signed __int64 v9; // r15
  __int64 v10; // rbx
  __int64 v11; // rbp
  Illusion::Buffer *v12; // rax
  Illusion::Buffer *v13; // rdi
  __int64 v14; // rax
  char *v15; // r9

  v4 = lightList;
  v5 = this;
  v6 = UFG::Director::Get()->mCurrentCamera;
  if ( v6 )
    v6 = (UFG::BaseCameraComponent *)((char *)v6 + 80);
  cameraPos = (UFG::qVector3 *)&v6->mCamera.mView.v2;
  v8 = (signed __int64)v5->activeBuffers;
  v9 = 3i64;
  do
  {
    v10 = 0i64;
    if ( *(_DWORD *)v8 )
    {
      do
      {
        v11 = *(_QWORD *)(*(_QWORD *)(v8 + 8) + 8 * v10);
        v12 = Render::ParticleEmitterBuffer::FrameMallocAttributeBuffer((Render::ParticleEmitterBuffer *)v11);
        v13 = v12;
        if ( v12 )
        {
          Illusion::Buffer::OnLoad(v12);
          v14 = v13->mData.mOffset;
          if ( v14 )
            v15 = (char *)&v13->mData + v14;
          else
            v15 = 0i64;
          Render::ParticleEmitterBuffer::TaskInfo::Start(
            (Render::ParticleEmitterBuffer::TaskInfo *)v11,
            *(Render::ParticleEmitterSettings **)(v11 + 80),
            (Render::ParticleEmitterBuffer *)v11,
            v15,
            cameraPos,
            simTime,
            deltaTime,
            v4);
        }
        ++v5->mNumActiveTasks;
        v10 = (unsigned int)(v10 + 1);
      }
      while ( (unsigned int)v10 < *(_DWORD *)v8 );
    }
    v8 += 16i64;
    --v9;
  }
  while ( v9 );
}

// File Line: 1784
// RVA: 0x1D86D0
void __fastcall Render::ParticleEmitterManager::SyncTasks(Render::ParticleEmitterManager *this)
{
  Render::ParticleEmitterManager *v1; // rbp
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *v2; // rdi
  signed __int64 v3; // r14
  unsigned int i; // esi
  Render::ParticleEmitterBuffer *v5; // rbx
  float v6; // xmm6_4
  Render::ParticleRenderUpdateTaskOutputParam *v7; // rax
  Render::ParticleRenderUpdateTaskParam *v8; // rax

  v1 = this;
  v2 = this->activeBuffers;
  v3 = 3i64;
  do
  {
    for ( i = 0; i < v2->size; --v1->mNumActiveTasks )
    {
      v5 = v2->p[i];
      v6 = v5->mExpiry;
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v5->mTaskInfo.task);
      v7 = v5->mTaskInfo.outputParam;
      if ( v6 < v7->lastExpiry )
        v6 = v7->lastExpiry;
      v5->mCount = v7->numParticlesInBuffer;
      v8 = v5->mTaskInfo.inputParam;
      v5->mTaskInfo.instance = 0i64;
      v5->mTaskInfo.task = 0i64;
      v8->currentAddCount = 0;
      UFG::qMemSet(v5->mTaskInfo.outputParam, 0, 8u);
      ++i;
      v5->mExpiry = v6;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
}

