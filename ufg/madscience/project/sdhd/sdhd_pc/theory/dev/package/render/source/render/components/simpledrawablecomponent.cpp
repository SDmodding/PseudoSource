// File Line: 28
// RVA: 0x1452490
__int64 dynamic_initializer_for__Render::SimpleDrawableComponent::s_SimpleDrawableComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::SimpleDrawableComponent::s_SimpleDrawableComponentList__);
}

// File Line: 29
// RVA: 0x1A00
const char *__fastcall Render::SimpleDrawableComponent::GetTypeName(Render::SimpleDrawableComponent *this)
{
  return "SimpleDrawableComponent";
}

// File Line: 36
// RVA: 0x1100
void __fastcall Render::SimpleDrawableComponent::SimpleDrawableComponent(
        Render::SimpleDrawableComponent *this,
        unsigned __int64 model_data_uid)
{
  UFG::qList<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper,1,0> *p_mModelWrappers; // r14
  UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *v5; // rcx
  const char *TypeName; // rax
  unsigned __int64 v7; // rax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *mPrev; // rax
  UFG::qReflectObject *mData; // rdi
  unsigned int i; // ebx
  char *v11; // rax
  __int64 v12; // rcx
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v13; // rcx

  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable;
  this->mAttachedDecals.mNode.Render::IDecalScenery::mPrev = &this->mAttachedDecals.mNode;
  this->mAttachedDecals.mNode.mNext = &this->mAttachedDecals.mNode;
  UFG::SimComponent::SimComponent(&this->UFG::SimComponent, 0);
  this->mPrev = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  this->mNext = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::SimpleDrawableComponent::`vftable{for `Render::IDecalScenery};
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::SimpleDrawableComponent::`vftable{for `UFG::SimComponent};
  p_mModelWrappers = &this->mModelWrappers;
  this->mModelWrappers.mNode.mPrev = &this->mModelWrappers.mNode;
  this->mModelWrappers.mNode.mNext = &this->mModelWrappers.mNode;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mModelDataHandle);
  TypeName = UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName(v5);
  v7 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&this->mModelDataHandle, v7, model_data_uid);
  mPrev = Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev;
  Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev->mNext = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList;
  Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  UFG::SimComponent::AddType(
    &this->UFG::SimComponent,
    Render::SimpleDrawableComponent::_SimpleDrawableComponentTypeUID,
    "SimpleDrawableComponent");
  this->mCullInfo = 0i64;
  this->mOcclusionCullInfo = 0i64;
  this->mCullResults = 0i64;
  *((_DWORD *)this + 30) &= ~1u;
  *((_DWORD *)this + 30) |= 4u;
  *(UFG::qColour *)this->mSceneryInstance.ColourTint = UFG::qColour::White;
  *(UFG::qColour *)this->mSceneryInstance.SIColourTint = UFG::qColour::White;
  mData = this->mModelDataHandle.mData;
  for ( i = 0; i < LODWORD(mData[1].mBaseNode.mUID); ++i )
  {
    v11 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
    if ( v11 )
    {
      v12 = (__int64)&mData[1].vfptr[7 * i];
      *(_QWORD *)v11 = v11;
      *((_QWORD *)v11 + 1) = v11;
      *((_QWORD *)v11 + 2) = v12;
      *((_WORD *)v11 + 12) = 1;
    }
    else
    {
      v11 = 0i64;
    }
    v13 = p_mModelWrappers->mNode.mPrev;
    v13->mNext = (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)v11;
    *(_QWORD *)v11 = v13;
    *((_QWORD *)v11 + 1) = p_mModelWrappers;
    p_mModelWrappers->mNode.mPrev = (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)v11;
  }
  if ( Render::SimpleDrawableComponent::mDefaultCullLayer )
    Render::SimpleDrawableComponent::SetLayer(this, Render::SimpleDrawableComponent::mDefaultCullLayer);
}

// File Line: 64
// RVA: 0x1300
void __fastcall Render::SimpleDrawableComponent::SimpleDrawableComponent(
        Render::SimpleDrawableComponent *this,
        unsigned __int64 model_data_uid,
        UFG::qArray<unsigned long,0> *nameUidFilter)
{
  UFG::qList<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper,1,0> *p_mModelWrappers; // r14
  UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *v7; // rcx
  const char *TypeName; // rax
  unsigned __int64 v9; // rax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *mPrev; // rax
  UFG::qReflectObject *mData; // rsi
  unsigned int i; // edi
  __int64 v13; // rbx
  UFG::qReflectObjectVtbl *vfptr; // rax
  const char *vecDelDtor; // rcx
  int v16; // eax
  int v17; // ecx
  char *v18; // rax
  char *v19; // r8
  UFG::qReflectObjectVtbl *v20; // rdx
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v21; // rax

  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable;
  this->mAttachedDecals.mNode.Render::IDecalScenery::mPrev = &this->mAttachedDecals.mNode;
  this->mAttachedDecals.mNode.mNext = &this->mAttachedDecals.mNode;
  UFG::SimComponent::SimComponent(&this->UFG::SimComponent, 0);
  this->mPrev = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  this->mNext = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::SimpleDrawableComponent::`vftable{for `Render::IDecalScenery};
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::SimpleDrawableComponent::`vftable{for `UFG::SimComponent};
  p_mModelWrappers = &this->mModelWrappers;
  this->mModelWrappers.mNode.mPrev = &this->mModelWrappers.mNode;
  this->mModelWrappers.mNode.mNext = &this->mModelWrappers.mNode;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mModelDataHandle);
  TypeName = UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName(v7);
  v9 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&this->mModelDataHandle, v9, model_data_uid);
  mPrev = Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev;
  Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev->mNext = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList;
  Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  UFG::SimComponent::AddType(
    &this->UFG::SimComponent,
    Render::SimpleDrawableComponent::_SimpleDrawableComponentTypeUID,
    "SimpleDrawableComponent");
  this->mCullInfo = 0i64;
  this->mOcclusionCullInfo = 0i64;
  this->mCullResults = 0i64;
  *((_DWORD *)this + 30) &= ~1u;
  *((_DWORD *)this + 30) |= 4u;
  *(UFG::qColour *)this->mSceneryInstance.ColourTint = UFG::qColour::White;
  *(UFG::qColour *)this->mSceneryInstance.SIColourTint = UFG::qColour::White;
  mData = this->mModelDataHandle.mData;
  for ( i = 0; i < LODWORD(mData[1].mBaseNode.mUID); ++i )
  {
    v13 = 7i64 * i;
    vfptr = mData[1].vfptr;
    if ( LODWORD(vfptr[v13].GetTypeName) )
      vecDelDtor = (const char *)vfptr[v13].__vecDelDtor;
    else
      vecDelDtor = &customCaption;
    v16 = UFG::qStringHashUpper32(vecDelDtor, 0xFFFFFFFF);
    v17 = 0;
    if ( nameUidFilter->size )
    {
      while ( v16 != nameUidFilter->p[v17] )
      {
        if ( ++v17 >= nameUidFilter->size )
          goto LABEL_13;
      }
      v18 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
      v19 = v18;
      if ( v18 )
      {
        v20 = &mData[1].vfptr[v13];
        *(_QWORD *)v18 = v18;
        *((_QWORD *)v18 + 1) = v18;
        *((_QWORD *)v18 + 2) = v20;
        *((_WORD *)v18 + 12) = 1;
      }
      else
      {
        v19 = 0i64;
      }
      v21 = p_mModelWrappers->mNode.mPrev;
      v21->mNext = (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)v19;
      *(_QWORD *)v19 = v21;
      *((_QWORD *)v19 + 1) = p_mModelWrappers;
      p_mModelWrappers->mNode.mPrev = (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)v19;
    }
LABEL_13:
    ;
  }
  if ( Render::SimpleDrawableComponent::mDefaultCullLayer )
    Render::SimpleDrawableComponent::SetLayer(this, Render::SimpleDrawableComponent::mDefaultCullLayer);
}

// File Line: 100
// RVA: 0x15F0
void __fastcall Render::SimpleDrawableComponent::~SimpleDrawableComponent(Render::SimpleDrawableComponent *this)
{
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v2; // rdi
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *mPrev; // rcx
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *mNext; // rax
  CullManager *v5; // rax
  CullManager *v6; // rax
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v7; // rdx
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v8; // rax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v9; // rdx
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v10; // rax

  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::SimpleDrawableComponent::`vftable{for `Render::IDecalScenery};
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::SimpleDrawableComponent::`vftable{for `UFG::SimComponent};
  if ( this == Render::SimpleDrawableComponent::s_SimpleDrawableComponentpCurrentIterator )
    Render::SimpleDrawableComponent::s_SimpleDrawableComponentpCurrentIterator = (Render::SimpleDrawableComponent *)&this->mPrev[-6].mNext;
  v2 = &this->UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  Render::IDecalScenery::RemoveAttachedDecals(this, 0xFFFFFFFF);
  v5 = CullManager::Instance();
  CullManager::FreePersistentCullInfo(v5, this->mCullResults, this->mCullInfo);
  v6 = CullManager::Instance();
  CullManager::FreePersistentOcclusionInfo(v6, this->mOcclusionCullInfo);
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mModelDataHandle);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mModelWrappers);
  v7 = this->mModelWrappers.mNode.mPrev;
  v8 = this->mModelWrappers.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mModelWrappers.mNode.mPrev = &this->mModelWrappers.mNode;
  this->mModelWrappers.mNode.mNext = &this->mModelWrappers.mNode;
  v9 = v2->mPrev;
  v10 = v2->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(&this->UFG::SimComponent);
  Render::IDecalScenery::~IDecalScenery(this);
}

// File Line: 110
// RVA: 0x1A70
void __fastcall Render::SimpleDrawableComponent::SetLayer(Render::SimpleDrawableComponent *this, CullLayer *cull_layer)
{
  CullInfo *mCullInfo; // rbx
  CullManager *v5; // rax
  CullManager *v6; // rax
  Render::SimpleDrawableComponent *mNext; // rbx
  int mPrev; // ecx
  CullManager *v9; // rax
  CullManager *v10; // rax

  mCullInfo = this->mCullInfo;
  if ( mCullInfo )
  {
    if ( mCullInfo->mCullLayer == cull_layer )
      return;
    v5 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v5, 0i64, mCullInfo);
  }
  v6 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v6, &this->mCullResults, &this->mCullInfo, cull_layer, this, this);
  mNext = (Render::SimpleDrawableComponent *)this->mModelWrappers.mNode.mNext;
  if ( mNext != (Render::SimpleDrawableComponent *)&this->mModelWrappers )
  {
    while ( 1 )
    {
      mPrev = (int)mNext->mAttachedDecals.mNode.mNext[2].mPrev;
      if ( mPrev == 5 || mPrev == 6 )
        break;
      if ( mPrev == 4 )
      {
        v9 = CullManager::Instance();
        CullManager::AllocPersistentOcclusionInfo(v9, &this->mOcclusionCullInfo, 0i64);
        goto LABEL_12;
      }
      mNext = (Render::SimpleDrawableComponent *)mNext->mAttachedDecals.mNode.Render::IDecalScenery::mPrev;
      if ( mNext == (Render::SimpleDrawableComponent *)&this->mModelWrappers )
        goto LABEL_12;
    }
    v10 = CullManager::Instance();
    CullManager::AllocPersistentOcclusionInfo(v10, &this->mOcclusionCullInfo, 0i64);
    this->mOcclusionCullInfo->mParam1 = (void *)((__int64)mNext->mAttachedDecals.mNode.mNext | (LODWORD(mNext->mAttachedDecals.mNode.mNext[2].mPrev) == 6));
  }
LABEL_12:
  *((_DWORD *)this + 30) |= 4u;
}

// File Line: 151
// RVA: 0x1EA0
void __fastcall Render::SimpleDrawableComponent::UpdateCullInfo(Render::SimpleDrawableComponent *this)
{
  UFG::qReflectObject *mData; // rax
  UFG::qReflectObject *v3; // rax
  CullInfo *mCullInfo; // rcx
  float v5; // xmm0_4
  float v6; // xmm1_4
  UFG::qReflectObject *v7; // rax
  CullInfo *v8; // rcx
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::qMatrix44 *p_mWorldTransform; // rcx
  CullInfoFull *mOcclusionCullInfo; // rdx
  UFG::qReflectObject *v15; // rax
  CullInfoFull *v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm1_4
  UFG::qReflectObject *v19; // rax
  CullInfoFull *v20; // rcx
  float v21; // xmm0_4
  float v22; // xmm1_4

  if ( this->mCullInfo )
  {
    mData = this->mModelDataHandle.mData;
    if ( mData )
    {
      this->mCullInfo->mViewsCulled = Illusion::eCastShadow::GetCastShadowViewsCulled(SHIDWORD(mData[1].mBaseNode.mNeighbours[0]));
      if ( (*((_BYTE *)this + 120) & 4) != 0 )
      {
        v3 = this->mModelDataHandle.mData;
        mCullInfo = this->mCullInfo;
        v5 = *((float *)&v3[1].mBaseNode.mParent + 1);
        v6 = *(float *)v3[1].mBaseNode.mChildren;
        mCullInfo->mAABBMin[0] = *(float *)&v3[1].mBaseNode.mParent;
        mCullInfo->mAABBMin[1] = v5;
        mCullInfo->mAABBMin[2] = v6;
        v7 = this->mModelDataHandle.mData;
        v8 = this->mCullInfo;
        v9 = *((float *)&v7[1].mBaseNode.mChildren[1] + 1);
        v10 = *(float *)v7[1].mBaseNode.mNeighbours;
        v8->mAABBMax[0] = *(float *)&v7[1].mBaseNode.mChildren[1];
        v8->mAABBMax[1] = v9;
        v8->mAABBMax[2] = v10;
        m_pSimObject = this->m_pSimObject;
        m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject->m_pTransformNodeComponent);
          p_mWorldTransform = &m_pTransformNodeComponent->mWorldTransform;
        }
        else
        {
          p_mWorldTransform = &UFG::qMatrix44::msIdentity;
        }
        this->mCullInfo->mpLocalWorld = &p_mWorldTransform->v0.x;
        mOcclusionCullInfo = this->mOcclusionCullInfo;
        if ( mOcclusionCullInfo )
        {
          mOcclusionCullInfo->mpLocalWorld = this->mCullInfo->mpLocalWorld;
          v15 = this->mModelDataHandle.mData;
          v16 = this->mOcclusionCullInfo;
          v17 = *((float *)&v15[1].mBaseNode.mParent + 1);
          v18 = *(float *)v15[1].mBaseNode.mChildren;
          v16->mAABBMin[0] = *(float *)&v15[1].mBaseNode.mParent;
          v16->mAABBMin[1] = v17;
          v16->mAABBMin[2] = v18;
          v19 = this->mModelDataHandle.mData;
          v20 = this->mOcclusionCullInfo;
          v21 = *((float *)&v19[1].mBaseNode.mChildren[1] + 1);
          v22 = *(float *)v19[1].mBaseNode.mNeighbours;
          v20->mAABBMax[0] = *(float *)&v19[1].mBaseNode.mChildren[1];
          v20->mAABBMax[1] = v21;
          v20->mAABBMax[2] = v22;
        }
        *((_DWORD *)this + 30) &= ~4u;
      }
    }
  }
}

// File Line: 188
// RVA: 0x1810
void __fastcall Render::SimpleDrawableComponent::Draw(Render::SimpleDrawableComponent *this, Render::View *view)
{
  float *v4; // rax
  float *v5; // rbx
  Illusion::StateValues *StateValues; // rax
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *i; // rbx
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *mPrev; // rdx
  UFG::qMatrix44 *mpLocalWorld; // r8

  if ( (this->m_Flags & 3) == 1 )
  {
    v4 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
    *v4 = this->mSceneryInstance.ColourTint[0];
    v5 = v4;
    v4[1] = this->mSceneryInstance.ColourTint[1];
    v4[2] = this->mSceneryInstance.ColourTint[2];
    v4[3] = this->mSceneryInstance.ColourTint[3];
    v4[4] = this->mSceneryInstance.SIColourTint[0];
    v4[5] = this->mSceneryInstance.SIColourTint[1];
    v4[6] = this->mSceneryInstance.SIColourTint[2];
    v4[7] = this->mSceneryInstance.SIColourTint[3];
    v4[8] = this->mSceneryInstance.Mask[0];
    v4[9] = this->mSceneryInstance.Mask[1];
    v4[10] = this->mSceneryInstance.Mask[2];
    v4[11] = this->mSceneryInstance.Mask[3];
    v4[12] = this->mSceneryInstance.Value0[0];
    v4[13] = this->mSceneryInstance.Value0[1];
    v4[14] = this->mSceneryInstance.Value0[2];
    v4[15] = this->mSceneryInstance.Value0[3];
    StateValues = Render::View::GetStateValues(view);
    StateValues->mSetValueMask.mFlags[0] |= 0x400000000ui64;
    StateValues->mParamValues[34] = v5;
    for ( i = this->mModelWrappers.mNode.mNext;
          i != (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)&this->mModelWrappers;
          i = i->mNext )
    {
      if ( LOWORD(i[1].mNext) )
      {
        mPrev = i[1].mPrev;
        if ( !LODWORD(mPrev[2].mPrev) )
        {
          mpLocalWorld = &UFG::qMatrix44::msIdentity;
          if ( this->mCullInfo->mpLocalWorld )
            mpLocalWorld = (UFG::qMatrix44 *)this->mCullInfo->mpLocalWorld;
          Render::View::Draw(view, (Illusion::rModel *)mPrev, mpLocalWorld, 0);
        }
      }
    }
  }
}

// File Line: 226
// RVA: 0x1B80
void __fastcall Render::SimpleDrawableComponent::SetVisibility(
        Render::SimpleDrawableComponent *this,
        unsigned int modelGuid,
        bool visible)
{
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *mNext; // rbx
  UFG::qList<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper,1,0> *p_mModelWrappers; // rdi
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *mPrev; // rax
  const char *v8; // rcx

  mNext = this->mModelWrappers.mNode.mNext;
  p_mModelWrappers = &this->mModelWrappers;
  if ( mNext != (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)&this->mModelWrappers )
  {
    while ( 1 )
    {
      mPrev = mNext[1].mPrev;
      v8 = LODWORD(mPrev->mNext) ? (const char *)mPrev->mPrev : &customCaption;
      if ( (unsigned int)UFG::qStringHashUpper32(v8, 0xFFFFFFFF) == modelGuid )
        break;
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)p_mModelWrappers )
        return;
    }
    LOWORD(mNext[1].mNext) = visible;
  }
}

// File Line: 248
// RVA: 0x19B0
bool __fastcall Render::SimpleDrawableComponent::GetTransform(
        Render::SimpleDrawableComponent *this,
        Render::Decal *decal,
        UFG::qMatrix44 *mat)
{
  bool result; // al
  float *mpLocalWorld; // rcx
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1

  if ( (*((_BYTE *)this + 120) & 1) != 0 )
    return 0;
  mpLocalWorld = this->mCullInfo->mpLocalWorld;
  v5 = &UFG::qMatrix44::msIdentity;
  if ( mpLocalWorld )
    v5 = (UFG::qMatrix44 *)mpLocalWorld;
  v6 = v5->v1;
  v7 = v5->v2;
  v8 = v5->v3;
  mat->v0 = v5->v0;
  mat->v1 = v6;
  result = 1;
  mat->v2 = v7;
  mat->v3 = v8;
  return result;
}

// File Line: 258
// RVA: 0x1C10
void __fastcall Render::TestSimpleDrawableForDecals(Render::DecalClipRequest *request, UFG::qBox *projBox)
{
  UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *p_mNext; // rdi
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *mNext; // rsi
  UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *v6; // r14
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *mPrev; // rax
  const char *v8; // rcx
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v9; // r15
  UFG::qMatrix44 *v10; // rcx
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  unsigned int v15; // edx
  Illusion::rModel *v16; // rbx
  unsigned int v17; // eax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v18; // r8
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v19; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mComponentPtr; // rdx
  UFG::qMatrix44 *v23; // rcx
  UFG::qVector4 v24; // xmm3
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qVector3 min; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 max; // [rsp+30h] [rbp-38h] BYREF

  p_mNext = (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mNext[-6].mNext;
  if ( &Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> **)((char *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList - 88) )
  {
    do
    {
      mNext = p_mNext[11].mNode.mNext;
      v6 = (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)&p_mNext[6].mNode.mPrev[-6].mNext;
      if ( mNext && ((__int64)p_mNext[7].mNode.mNext & 1) == 0 )
      {
        mPrev = mNext[5].mPrev;
        if ( LODWORD(mPrev->mNext) )
          v8 = (const char *)mPrev->mPrev;
        else
          v8 = &customCaption;
        UFG::qStringFindInsensitive(v8, "Cube");
        v9 = p_mNext[8].mNode.mPrev;
        v10 = &UFG::qMatrix44::msIdentity;
        v11 = *((float *)&v9->mPrev + 1);
        v12 = *(float *)&v9->mNext;
        min.x = *(float *)&v9->mPrev;
        min.y = v11;
        min.z = v12;
        v13 = *((float *)&v9[1].mPrev + 1);
        v14 = *(float *)&v9[1].mNext;
        max.x = *(float *)&v9[1].mPrev;
        max.y = v13;
        max.z = v14;
        if ( v9[3].mNext )
          v10 = (UFG::qMatrix44 *)v9[3].mNext;
        TransformAABB(v10, &min, &max);
        if ( min.x <= projBox->mMax.x
          && max.x >= projBox->mMin.x
          && min.y <= projBox->mMax.y
          && max.y >= projBox->mMin.y
          && min.z <= projBox->mMax.z
          && max.z >= projBox->mMin.z )
        {
          v15 = (unsigned int)mNext[5].mNext;
          v16 = 0i64;
          v17 = 0;
          if ( v15 )
          {
            v18 = mNext[5].mPrev;
            v19 = v18 + 2;
            while ( LODWORD(v19->mPrev) )
            {
              ++v17;
              v19 += 7;
              if ( v17 >= v15 )
                goto LABEL_21;
            }
            v16 = (Illusion::rModel *)&v18[7 * v17];
          }
LABEL_21:
          Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
          if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
          {
            v21 = UFG::qResourceWarehouse::Instance();
            Inventory = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
            `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
          }
          UFG::qResourceHandle::Init(&request->mModelProxy.mModelHandle, 0xA2ADCD77, 0, Inventory);
          request->mModelProxy.mRModel = v16;
          p_mComponentPtr = &request->mComponentPtr;
          v23 = &UFG::qMatrix44::msIdentity;
          if ( v9[3].mNext )
            v23 = (UFG::qMatrix44 *)v9[3].mNext;
          v24 = v23->v1;
          v25 = v23->v2;
          v26 = v23->v3;
          request->mLocalToWorld.v0 = v23->v0;
          request->mLocalToWorld.v1 = v24;
          request->mLocalToWorld.v2 = v25;
          request->mLocalToWorld.v3 = v26;
          if ( request->mComponentPtr.m_pPointer )
          {
            v27 = p_mComponentPtr->mPrev;
            v28 = request->mComponentPtr.mNext;
            v27->mNext = v28;
            v28->mPrev = v27;
            p_mComponentPtr->mPrev = p_mComponentPtr;
            request->mComponentPtr.mNext = &request->mComponentPtr;
          }
          request->mComponentPtr.m_pPointer = (UFG::SimComponent *)&p_mNext[1].mNode.mNext;
          if ( p_mNext != (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)-24i64 )
          {
            v29 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)p_mNext[2].mNode.mPrev;
            v29->mNext = p_mComponentPtr;
            p_mComponentPtr->mPrev = v29;
            request->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&p_mNext[2];
            p_mNext[2].mNode.mPrev = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)p_mComponentPtr;
          }
          request->mScenery = (Render::IDecalScenery *)p_mNext;
          Render::DecalManager::AddClipQueue(&Render::gDecalManager, request);
        }
      }
      p_mNext = v6;
    }
    while ( v6 != (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)((char *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList - 88) );
  }
}

