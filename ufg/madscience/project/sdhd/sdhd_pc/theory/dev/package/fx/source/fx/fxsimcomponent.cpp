// File Line: 12
// RVA: 0x1CC340
UFG::ComponentIDDesc *__fastcall Render::FXSimComponent::GetDesc(Render::FXSimComponent *this)
{
  return &Render::FXSimComponent::_TypeIDesc;
}

// File Line: 13
// RVA: 0x146AFA0
__int64 dynamic_initializer_for__Render::FXSimComponent::s_FXSimComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::FXSimComponent::s_FXSimComponentList__);
}

// File Line: 20
// RVA: 0x1C1550
void __fastcall Render::FXSimComponent::FXSimComponent(Render::FXSimComponent *this)
{
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->mPrev = &this->UFG::qNode<Render::FXSimComponent,Render::FXSimComponent>;
  this->mNext = &this->UFG::qNode<Render::FXSimComponent,Render::FXSimComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::FXSimComponent::`vftable;
  this->mEffects.mNode.mPrev = &this->mEffects.mNode;
  this->mEffects.mNode.mNext = &this->mEffects.mNode;
  this->mPose = 0i64;
  this->mXform = 0i64;
  UFG::SimComponent::AddType(this, Render::FXSimComponent::_FXSimComponentTypeUID, "FXSimComponent");
  mPrev = Render::FXSimComponent::s_FXSimComponentList.mNode.mPrev;
  Render::FXSimComponent::s_FXSimComponentList.mNode.mPrev->mNext = &this->UFG::qNode<Render::FXSimComponent,Render::FXSimComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *)&Render::FXSimComponent::s_FXSimComponentList;
  Render::FXSimComponent::s_FXSimComponentList.mNode.mPrev = &this->UFG::qNode<Render::FXSimComponent,Render::FXSimComponent>;
}

// File Line: 26
// RVA: 0x1C3AE0
void __fastcall Render::FXSimComponent::~FXSimComponent(Render::FXSimComponent *this)
{
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v2; // rdi
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *mPrev; // rcx
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *mNext; // rax
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v5; // rcx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v6; // rax
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v7; // rcx
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v8; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::FXSimComponent::`vftable;
  if ( this == Render::FXSimComponent::s_FXSimComponentpCurrentIterator )
    Render::FXSimComponent::s_FXSimComponentpCurrentIterator = (Render::FXSimComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<Render::FXSimComponent,Render::FXSimComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0>::DeleteNodes(&this->mEffects);
  v5 = this->mEffects.mNode.mPrev;
  v6 = this->mEffects.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mEffects.mNode.mPrev = &this->mEffects.mNode;
  this->mEffects.mNode.mNext = &this->mEffects.mNode;
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 31
// RVA: 0x1C3CF0
void __fastcall Render::FXSimComponent::FxBinding::~FxBinding(Render::FXSimComponent::FxBinding *this)
{
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *mPrev; // rdx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *mNext; // rax
  unsigned int mEffectHandle; // edx
  UFG::qBaseTreeRB *v5; // rax
  int v6; // edx
  hkGeometryUtils::IVertices *v7; // rcx
  int v8; // r8d
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v9; // rdi
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v10; // rcx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v11; // rax
  int v12; // r8d
  UFG::TransformNodeComponent *mAttachTransform; // rcx
  UFG::qMatrix44 *mAttachTransformOffset; // rcx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v15; // rcx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v16; // rax

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
  mEffectHandle = this->mEffectHandle;
  if ( mEffectHandle != -1 )
  {
    if ( mEffectHandle )
    {
      v5 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, mEffectHandle);
      v9 = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)v5;
      if ( v5 )
      {
        if ( *(_QWORD *)&v5[1].mNULL.mUID
          && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v7, v6, v8) )
        {
          UFG::AudioVFXManager::Remove(v9);
        }
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&Render::gFXManager,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v9);
        v10 = v9[3].mPrev;
        v11 = v9[3].mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        v9[3].mPrev = v9 + 3;
        v9[3].mNext = v9 + 3;
        Render::FXInstance::~FXInstance((Render::FXInstance *)v9, (_DWORD)v9 + 48, v12);
        operator delete[](v9);
      }
    }
    this->mEffectHandle = -1;
  }
  mAttachTransform = this->mAttachTransform;
  if ( mAttachTransform )
  {
    mAttachTransform->vfptr->__vecDelDtor(mAttachTransform, 1u);
    this->mAttachTransform = 0i64;
  }
  mAttachTransformOffset = this->mAttachTransformOffset;
  if ( mAttachTransformOffset )
  {
    operator delete[](mAttachTransformOffset);
    this->mAttachTransformOffset = 0i64;
  }
  v15 = this->mPrev;
  v16 = this->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 54
// RVA: 0x1D8520
void __fastcall Render::FXSimComponent::Suspend(Render::FXSimComponent *this)
{
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *mNext; // rbx
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *p_mEffects; // rsi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseNodeRB *mParent; // rcx
  char *v7; // rax
  __int64 i; // rcx

  mNext = this->mEffects.mNode.mNext;
  p_mEffects = &this->mEffects;
  if ( mNext == (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&this->mEffects )
  {
    this->m_Flags |= 2u;
  }
  else
  {
    do
    {
      v4 = (unsigned int)mNext[2].mNext;
      if ( v4 != -1 )
      {
        if ( v4 )
        {
          v5 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, v4);
          if ( v5 )
          {
            mParent = v5[1].mNULL.mParent;
            v7 = (char *)&v5[1].mRoot.mChild[1];
            for ( i = (__int64)&mParent[-1].mUID; (char *)i != v7; i = *(_QWORD *)(i + 16) - 8i64 )
              *(_DWORD *)(i + 48) = 2;
          }
        }
      }
      mNext = mNext->mNext;
    }
    while ( mNext != (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)p_mEffects );
    this->m_Flags |= 2u;
  }
}

// File Line: 63
// RVA: 0x1D5CA0
void __fastcall Render::FXSimComponent::Restore(Render::FXSimComponent *this)
{
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *mNext; // rbx
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *i; // rdi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseNodeRB *mParent; // rcx
  char *v7; // rax
  __int64 j; // rcx

  mNext = this->mEffects.mNode.mNext;
  for ( i = &this->mEffects;
        mNext != (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)i;
        mNext = mNext->mNext )
  {
    v4 = (unsigned int)mNext[2].mNext;
    if ( v4 != -1 )
    {
      if ( v4 )
      {
        v5 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, v4);
        if ( v5 )
        {
          mParent = v5[1].mNULL.mParent;
          v7 = (char *)&v5[1].mRoot.mChild[1];
          for ( j = (__int64)&mParent[-1].mUID; (char *)j != v7; j = *(_QWORD *)(j + 16) - 8i64 )
            *(_DWORD *)(j + 48) = 3;
        }
      }
    }
  }
  this->m_Flags &= ~2u;
}

// File Line: 72
// RVA: 0x1C78F0
signed __int64 __fastcall Render::FXSimComponent::AttachEffect(
        Render::FXSimComponent *this,
        unsigned int effectId,
        int jointID,
        UFG::qMatrix44 *offset)
{
  UFG::allocator::free_link *v8; // rax
  Render::FXSimComponent::FxBinding *v9; // rbx
  UFG::TransformNodeComponent *v10; // rdi
  SkeletalPose *mPose; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::qMatrix44 *v13; // rax
  UFG::qMatrix44 *v14; // rax
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm0
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::TransformNodeComponent *v20; // rax
  UFG::TransformNodeComponent *mAttachTransform; // rdi
  UFG::qMatrix44 *p_mWorldTransform; // r8
  unsigned int Effect; // eax
  UFG::qBaseTreeRB *v25; // rax
  float v26; // xmm0_4
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *mPrev; // rax
  UFG::qMatrix44 matrixWS; // [rsp+38h] [rbp-61h] BYREF
  __int64 v29; // [rsp+78h] [rbp-21h]
  UFG::qMatrix44 result; // [rsp+80h] [rbp-19h] BYREF

  v29 = -2i64;
  if ( effectId == -1 )
    return 0xFFFFFFFFi64;
  v8 = UFG::qMalloc(0x38ui64, "[FxBinding]FXSimComponent::Attach()", 0i64);
  v9 = (Render::FXSimComponent::FxBinding *)v8;
  if ( v8 )
  {
    v8->mNext = v8;
    v8[1].mNext = v8;
    v10 = 0i64;
    v8[3].mNext = 0i64;
    v8[4].mNext = 0i64;
    v8[5].mNext = (UFG::allocator::free_link *)-1i64;
  }
  else
  {
    v10 = 0i64;
    v9 = 0i64;
  }
  matrixWS = UFG::qMatrix44::msIdentity;
  mPose = this->mPose;
  if ( mPose && jointID != -1 )
    SkeletalPose::GetPositionWS(mPose, jointID, &matrixWS);
  if ( offset )
  {
    v12 = UFG::qMalloc(0x40ui64, "[qMatrix44]FXSimComponent::Attach()", 0i64);
    if ( v12 )
      UFG::qMatrix44::qMatrix44((UFG::qMatrix44 *)v12, offset);
    else
      v13 = 0i64;
    v9->mAttachTransformOffset = v13;
    v14 = UFG::qMatrix44::operator*(offset, &result, &matrixWS);
    v15 = v14->v1;
    v16 = v14->v2;
    v17 = v14->v3;
    matrixWS.v0 = v14->v0;
    matrixWS.v1 = v15;
    matrixWS.v2 = v16;
    matrixWS.v3 = v17;
  }
  v9->mAttachJoint = jointID;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v19 = UFG::qMemoryPool::Allocate(
          SimulationMemoryPool,
          0x110ui64,
          "[TransformNodeComponent]FXSimComponent::Attach()",
          0i64,
          1u);
  if ( v19 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v19, 0, 0i64, 0);
    v10 = v20;
  }
  v9->mAttachTransform = v10;
  UFG::TransformNodeComponent::SetLocalTransform(v10, &matrixWS);
  mAttachTransform = v9->mAttachTransform;
  if ( mAttachTransform )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v9->mAttachTransform);
    p_mWorldTransform = &mAttachTransform->mWorldTransform;
  }
  else
  {
    p_mWorldTransform = &UFG::qMatrix44::msIdentity;
  }
  Effect = Render::FXManager::CreateEffect(&Render::gFXManager, effectId, p_mWorldTransform, mAttachTransform);
  v9->mEffectHandle = Effect;
  v9->mFXSettingsId = effectId;
  if ( Effect == -1 )
  {
    Render::FXSimComponent::FxBinding::~FxBinding(v9);
    operator delete[](v9);
    return 0xFFFFFFFFi64;
  }
  if ( Effect && (v25 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, Effect)) != 0i64 )
  {
    if ( *((_BYTE *)&v25[1].mCount + 4) )
      v26 = FLOAT_3_4028235e38;
    else
      v26 = *((float *)v25[1].mNULL.mChild + 1);
  }
  else
  {
    v26 = 0.0;
  }
  v9->mEndTime = v26;
  mPrev = this->mEffects.mNode.mPrev;
  mPrev->mNext = v9;
  v9->mPrev = mPrev;
  v9->mNext = &this->mEffects.mNode;
  this->mEffects.mNode.mPrev = v9;
  return v9->mEffectHandle;
}

// File Line: 119
// RVA: 0x1CB150
void __fastcall Render::FXSimComponent::DetachEffect(
        Render::FXSimComponent *this,
        unsigned int fxHandle,
        Render::eFXKillOption killOption)
{
  Render::FXSimComponent::FxBinding *mNext; // rbx
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *p_mEffects; // rcx
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *v6; // rax
  unsigned int mFXSettingsId; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v9; // rax
  float v10; // xmm1_4
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceHandle v13; // [rsp+28h] [rbp-30h] BYREF

  mNext = (Render::FXSimComponent::FxBinding *)this->mEffects.mNode.mNext;
  p_mEffects = &this->mEffects;
  if ( mNext != (Render::FXSimComponent::FxBinding *)p_mEffects )
  {
    while ( 1 )
    {
      v6 = (UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *)mNext->mNext;
      if ( mNext->mEffectHandle == fxHandle )
        break;
      mNext = (Render::FXSimComponent::FxBinding *)mNext->mNext;
      if ( v6 == p_mEffects )
        return;
    }
    UFG::qResourceHandle::qResourceHandle(&v13);
    mFXSettingsId = mNext->mFXSettingsId;
    Inventory = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&v13, 0xED341A8D, mFXSettingsId, Inventory);
    v10 = *((float *)&v13.mData[1].mNode.mUID + 1);
    if ( v10 <= 0.0 )
    {
      Render::FXSimComponent::FxBinding::~FxBinding(mNext);
      operator delete[](mNext);
    }
    else
    {
      mNext->mEndTime = UFG::Metrics::msInstance.mSimTime_Temp + v10;
      Render::FXManager::KillEffect(&Render::gFXManager, mNext->mEffectHandle, killOption);
      mNext->mEffectHandle = -1;
    }
    v11 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v11;
    }
    UFG::qResourceHandle::Close(&v13, v11);
    UFG::qResourceHandle::~qResourceHandle(&v13);
  }
}

// File Line: 172
// RVA: 0x1D2040
Render::FXSimComponent *__fastcall Render::FXSimComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v4; // rax
  unsigned int *MemImagePtr; // rdi
  UFG::SimObject *m_pSimObject; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  Render::FXSimComponent *v9; // rax
  Render::FXSimComponent *v10; // rbx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         &component_FXSimComponent::sPropertyName,
         DEPTH_RECURSE);
  if ( !v4 )
    return 0i64;
  MemImagePtr = (unsigned int *)UFG::qPropertySet::GetMemImagePtr(v4);
  if ( !MemImagePtr )
    return 0i64;
  m_pSimObject = sceneObject->m_pSimObject;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(
         SimulationMemoryPool,
         0x70ui64,
         "[FXSimComponent]FXSimComponent::PropertiesOnActivateNew()",
         0i64,
         1u);
  if ( v8 )
  {
    Render::FXSimComponent::FXSimComponent((Render::FXSimComponent *)v8);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v12, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v10, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
  v10->mXform = m_pSimObject->m_pTransformNodeComponent;
  if ( *MemImagePtr != -1 )
    Render::FXSimComponent::AttachEffect(v10, *MemImagePtr, -1, 0i64);
  return v10;
}

// File Line: 195
// RVA: 0x1D95E0
void __fastcall Render::FXSimComponent::Update(Render::FXSimComponent *this)
{
  Render::FXSimComponent::FxBinding *mNext; // rdi
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *p_mEffects; // r14
  Render::FXSimComponent::FxBinding *v4; // rsi
  SkeletalPose *mPose; // rcx
  UFG::TransformNodeComponent *mXform; // rbx
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  UFG::qMatrix44 *mAttachTransformOffset; // rcx
  UFG::qMatrix44 *v11; // rax
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::qMatrix44 matrixWS; // [rsp+8h] [rbp-39h] BYREF
  UFG::qMatrix44 result; // [rsp+48h] [rbp+7h] BYREF

  mNext = (Render::FXSimComponent::FxBinding *)this->mEffects.mNode.mNext;
  p_mEffects = &this->mEffects;
  if ( mNext != (Render::FXSimComponent::FxBinding *)&this->mEffects )
  {
    do
    {
      v4 = (Render::FXSimComponent::FxBinding *)mNext->mNext;
      if ( UFG::Metrics::msInstance.mSimTime_Temp <= mNext->mEndTime )
      {
        mPose = this->mPose;
        matrixWS = UFG::qMatrix44::msIdentity;
        if ( mPose )
        {
          SkeletalPose::GetPositionWS(mPose, mNext->mAttachJoint, &matrixWS);
        }
        else
        {
          mXform = this->mXform;
          UFG::TransformNodeComponent::UpdateWorldTransform(mXform);
          v7 = mXform->mWorldTransform.v2;
          v8 = mXform->mWorldTransform.v3;
          v9 = mXform->mWorldTransform.v0;
          matrixWS.v1 = mXform->mWorldTransform.v1;
          matrixWS.v2 = v7;
          matrixWS.v0 = v9;
          matrixWS.v3 = v8;
        }
        mAttachTransformOffset = mNext->mAttachTransformOffset;
        if ( mAttachTransformOffset )
        {
          v11 = UFG::qMatrix44::operator*(mAttachTransformOffset, &result, &matrixWS);
          v12 = v11->v2;
          v13 = v11->v3;
          v14 = v11->v0;
          matrixWS.v1 = v11->v1;
          matrixWS.v2 = v12;
          matrixWS.v0 = v14;
          matrixWS.v3 = v13;
        }
        UFG::TransformNodeComponent::SetLocalTransform(mNext->mAttachTransform, &matrixWS);
      }
      else
      {
        Render::FXSimComponent::FxBinding::~FxBinding(mNext);
        operator delete[](mNext);
      }
      mNext = v4;
    }
    while ( v4 != (Render::FXSimComponent::FxBinding *)p_mEffects );
  }
}

// File Line: 236
// RVA: 0x1DB200
void Render::FXSimComponent::UpdateComponents(void)
{
  Render::FXSimComponent *v0; // rcx
  UFG::qList<Render::FXSimComponent,Render::FXSimComponent,1,0> *v1; // rbx

  v0 = (Render::FXSimComponent *)&Render::FXSimComponent::s_FXSimComponentList.mNode.mNext[-4];
  if ( (UFG::qList<Render::FXSimComponent,Render::FXSimComponent,1,0> *)&Render::FXSimComponent::s_FXSimComponentList.mNode.mNext[-4] != &Render::FXSimComponent::s_FXSimComponentList - 4 )
  {
    do
    {
      v1 = (UFG::qList<Render::FXSimComponent,Render::FXSimComponent,1,0> *)&v0->mNext[-4];
      Render::FXSimComponent::Update(v0);
      v0 = (Render::FXSimComponent *)v1;
    }
    while ( v1 != &Render::FXSimComponent::s_FXSimComponentList - 4 );
  }
}

