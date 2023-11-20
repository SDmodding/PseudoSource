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
  return atexit(dynamic_atexit_destructor_for__Render::FXSimComponent::s_FXSimComponentList__);
}

// File Line: 20
// RVA: 0x1C1550
void __fastcall Render::FXSimComponent::FXSimComponent(Render::FXSimComponent *this)
{
  Render::FXSimComponent *v1; // rdi
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v2; // rbx
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v3; // rax
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v2 = (UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::FXSimComponent::`vftable';
  v4 = &v1->mEffects;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v1->mPose = 0i64;
  v1->mXform = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    Render::FXSimComponent::_FXSimComponentTypeUID,
    "FXSimComponent");
  v3 = Render::FXSimComponent::s_FXSimComponentList.mNode.mPrev;
  Render::FXSimComponent::s_FXSimComponentList.mNode.mPrev->mNext = (UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *)&v1->mPrev;
  v2->mPrev = v3;
  v1->mNext = (UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *)&Render::FXSimComponent::s_FXSimComponentList;
  Render::FXSimComponent::s_FXSimComponentList.mNode.mPrev = (UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *)&v1->mPrev;
}

// File Line: 26
// RVA: 0x1C3AE0
void __fastcall Render::FXSimComponent::~FXSimComponent(Render::FXSimComponent *this)
{
  Render::FXSimComponent *v1; // rsi
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v2; // rdi
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v3; // rcx
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v4; // rax
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v5; // rcx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v6; // rax
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v7; // rcx
  UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::FXSimComponent::`vftable';
  if ( this == Render::FXSimComponent::s_FXSimComponentpCurrentIterator )
    Render::FXSimComponent::s_FXSimComponentpCurrentIterator = (Render::FXSimComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<Render::FXSimComponent,Render::FXSimComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0>::DeleteNodes(&v1->mEffects);
  v5 = v1->mEffects.mNode.mPrev;
  v6 = v1->mEffects.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mEffects.mNode.mPrev = &v1->mEffects.mNode;
  v1->mEffects.mNode.mNext = &v1->mEffects.mNode;
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 31
// RVA: 0x1C3CF0
void __fastcall Render::FXSimComponent::FxBinding::~FxBinding(Render::FXSimComponent::FxBinding *this)
{
  Render::FXSimComponent::FxBinding *v1; // rbx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v2; // rdx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v3; // rax
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  int v6; // edx
  hkGeometryUtils::IVertices *v7; // rcx
  int v8; // er8
  Render::FXInstance *v9; // rdi
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v10; // rdx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v11; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v12; // rax
  __int64 v13; // r8
  UFG::TransformNodeComponent *v14; // rcx
  UFG::qMatrix44 *v15; // rcx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v16; // rcx
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v17; // rax

  v1 = this;
  v2 = this->mPrev;
  v3 = this->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  this->mPrev = (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&this->mPrev;
  v4 = this->mEffectHandle;
  if ( v4 != -1 )
  {
    if ( v4 )
    {
      v5 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, v4);
      v9 = (Render::FXInstance *)v5;
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
        v10 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&v9->mPrev;
        v11 = v9->mPrev;
        v12 = v9->mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v10->mPrev = v10;
        v10->mNext = v10;
        Render::FXInstance::~FXInstance(v9, (_DWORD)v9 + 48, v13);
        operator delete[](v9);
      }
    }
    v1->mEffectHandle = -1;
  }
  v14 = v1->mAttachTransform;
  if ( v14 )
  {
    v14->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v14->vfptr, 1u);
    v1->mAttachTransform = 0i64;
  }
  v15 = v1->mAttachTransformOffset;
  if ( v15 )
  {
    operator delete[](v15);
    v1->mAttachTransformOffset = 0i64;
  }
  v16 = v1->mPrev;
  v17 = v1->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v1->mPrev = (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&v1->mPrev;
}

// File Line: 54
// RVA: 0x1D8520
void __fastcall Render::FXSimComponent::Suspend(Render::FXSimComponent *this)
{
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v1; // rbx
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *v2; // rsi
  Render::FXSimComponent *v3; // rdi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseNodeRB *v6; // rcx
  signed __int64 v7; // rax
  signed __int64 i; // rcx

  v1 = this->mEffects.mNode.mNext;
  v2 = &this->mEffects;
  v3 = this;
  if ( v1 == (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&this->mEffects )
  {
    this->m_Flags |= 2u;
  }
  else
  {
    do
    {
      v4 = (unsigned int)v1[2].mNext;
      if ( v4 != -1 )
      {
        if ( v4 )
        {
          v5 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, v4);
          if ( v5 )
          {
            v6 = v5[1].mNULL.mParent;
            v7 = (signed __int64)&v5[1].mRoot.mChild[1];
            for ( i = (signed __int64)&v6[-1].mUID; i != v7; i = *(_QWORD *)(i + 16) - 8i64 )
              *(_DWORD *)(i + 48) = 2;
          }
        }
      }
      v1 = v1->mNext;
    }
    while ( v1 != (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)v2 );
    v3->m_Flags |= 2u;
  }
}

// File Line: 63
// RVA: 0x1D5CA0
void __fastcall Render::FXSimComponent::Restore(Render::FXSimComponent *this)
{
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v1; // rbx
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *v2; // rdi
  Render::FXSimComponent *v3; // rsi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseNodeRB *v6; // rcx
  signed __int64 v7; // rax
  signed __int64 i; // rcx

  v1 = this->mEffects.mNode.mNext;
  v2 = &this->mEffects;
  v3 = this;
  if ( v1 != (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&this->mEffects )
  {
    do
    {
      v4 = (unsigned int)v1[2].mNext;
      if ( v4 != -1 )
      {
        if ( v4 )
        {
          v5 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, v4);
          if ( v5 )
          {
            v6 = v5[1].mNULL.mParent;
            v7 = (signed __int64)&v5[1].mRoot.mChild[1];
            for ( i = (signed __int64)&v6[-1].mUID; i != v7; i = *(_QWORD *)(i + 16) - 8i64 )
              *(_DWORD *)(i + 48) = 3;
          }
        }
      }
      v1 = v1->mNext;
    }
    while ( v1 != (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)v2 );
  }
  v3->m_Flags &= 0xFFFDu;
}

// File Line: 72
// RVA: 0x1C78F0
signed __int64 __fastcall Render::FXSimComponent::AttachEffect(Render::FXSimComponent *this, unsigned int effectId, int jointID, UFG::qMatrix44 *offset)
{
  UFG::qMatrix44 *v4; // r14
  int v5; // esi
  unsigned int v6; // er15
  Render::FXSimComponent *v7; // r13
  UFG::allocator::free_link *v8; // rax
  Render::FXSimComponent::FxBinding *v9; // rbx
  UFG::TransformNodeComponent *v10; // rdi
  SkeletalPose *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::qMatrix44 *v13; // rax
  UFG::qMatrix44 *v14; // rax
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm0
  UFG::qMemoryPool *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::TransformNodeComponent *v20; // rax
  UFG::TransformNodeComponent *v21; // rdi
  UFG::qMatrix44 *v22; // r8
  unsigned int v23; // eax
  UFG::qBaseTreeRB *v25; // rax
  float v26; // xmm0_4
  UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *v27; // rax
  UFG::qMatrix44 matrixWS; // [rsp+38h] [rbp-61h]
  __int64 v29; // [rsp+78h] [rbp-21h]
  UFG::qMatrix44 result; // [rsp+80h] [rbp-19h]

  v29 = -2i64;
  v4 = offset;
  v5 = jointID;
  v6 = effectId;
  v7 = this;
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
  v11 = v7->mPose;
  if ( v11 && v5 != -1 )
    SkeletalPose::GetPositionWS(v11, v5, &matrixWS);
  if ( v4 )
  {
    v12 = UFG::qMalloc(0x40ui64, "[qMatrix44]FXSimComponent::Attach()", 0i64);
    if ( v12 )
      UFG::qMatrix44::qMatrix44((UFG::qMatrix44 *)v12, v4);
    else
      v13 = 0i64;
    v9->mAttachTransformOffset = v13;
    v14 = UFG::qMatrix44::operator*(v4, &result, &matrixWS);
    v15 = v14->v1;
    v16 = v14->v2;
    v17 = v14->v3;
    matrixWS.v0 = v14->v0;
    matrixWS.v1 = v15;
    matrixWS.v2 = v16;
    matrixWS.v3 = v17;
  }
  v9->mAttachJoint = v5;
  v18 = UFG::GetSimulationMemoryPool();
  v19 = UFG::qMemoryPool::Allocate(v18, 0x110ui64, "[TransformNodeComponent]FXSimComponent::Attach()", 0i64, 1u);
  if ( v19 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v19, 0, 0i64, 0);
    v10 = v20;
  }
  v9->mAttachTransform = v10;
  UFG::TransformNodeComponent::SetLocalTransform(v10, &matrixWS);
  v21 = v9->mAttachTransform;
  if ( v21 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v9->mAttachTransform);
    v22 = &v21->mWorldTransform;
  }
  else
  {
    v22 = &UFG::qMatrix44::msIdentity;
  }
  v23 = Render::FXManager::CreateEffect(&Render::gFXManager, v6, v22, v21);
  v9->mEffectHandle = v23;
  v9->mFXSettingsId = v6;
  if ( v23 == -1 )
  {
    Render::FXSimComponent::FxBinding::~FxBinding(v9);
    operator delete[](v9);
    return 0xFFFFFFFFi64;
  }
  if ( v23 && (v25 = UFG::qBaseTreeRB::Get(&Render::gFXManager.mEffectsTree.mTree, v23)) != 0i64 )
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
  v27 = v7->mEffects.mNode.mPrev;
  v27->mNext = (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&v9->mPrev;
  v9->mPrev = v27;
  v9->mNext = &v7->mEffects.mNode;
  v7->mEffects.mNode.mPrev = (UFG::qNode<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding> *)&v9->mPrev;
  return v9->mEffectHandle;
}

// File Line: 119
// RVA: 0x1CB150
void __fastcall Render::FXSimComponent::DetachEffect(Render::FXSimComponent *this, unsigned int fxHandle, Render::eFXKillOption killOption)
{
  Render::eFXKillOption v3; // esi
  Render::FXSimComponent::FxBinding *v4; // rbx
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *v5; // rcx
  char *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  float v10; // xmm1_4
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceHandle v13; // [rsp+28h] [rbp-30h]

  v3 = killOption;
  v4 = (Render::FXSimComponent::FxBinding *)this->mEffects.mNode.mNext;
  v5 = &this->mEffects;
  if ( v4 != (Render::FXSimComponent::FxBinding *)v5 )
  {
    while ( 1 )
    {
      v6 = (char *)v4->mNext;
      if ( v4->mEffectHandle == fxHandle )
        break;
      v4 = (Render::FXSimComponent::FxBinding *)v4->mNext;
      if ( v6 == (char *)v5 )
        return;
    }
    UFG::qResourceHandle::qResourceHandle(&v13);
    v7 = v4->mFXSettingsId;
    v8 = `UFG::qGetResourceInventory<Render::FXSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>'::`2'::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>'::`2'::result = v8;
    }
    UFG::qResourceHandle::Init(&v13, 0xED341A8D, v7, v8);
    v10 = *((float *)&v13.mData[1].mNode.mUID + 1);
    if ( v10 <= 0.0 )
    {
      Render::FXSimComponent::FxBinding::~FxBinding(v4);
      operator delete[](v4);
    }
    else
    {
      v4->mEndTime = UFG::Metrics::msInstance.mSimTime_Temp + v10;
      Render::FXManager::KillEffect(&Render::gFXManager, v4->mEffectHandle, v3);
      v4->mEffectHandle = -1;
    }
    v11 = `UFG::qGetResourceInventory<Render::FXSettings>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>'::`2'::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>'::`2'::result = v11;
    }
    UFG::qResourceHandle::Close(&v13, v11);
    UFG::qResourceHandle::~qResourceHandle(&v13);
  }
}

// File Line: 172
// RVA: 0x1D2040
Render::FXSimComponent *__fastcall Render::FXSimComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *v4; // rax
  unsigned int *v5; // rdi
  UFG::SimObject *v6; // rsi
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  Render::FXSimComponent *v9; // rax
  Render::FXSimComponent *v10; // rbx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h]

  v2 = sceneObject;
  v3 = sceneObject->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v3,
         (UFG::qSymbol *)&component_FXSimComponent::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( !v4 )
    return 0i64;
  v5 = (unsigned int *)UFG::qPropertySet::GetMemImagePtr(v4);
  if ( !v5 )
    return 0i64;
  v6 = v2->m_pSimObject;
  v7 = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(v7, 0x70ui64, "[FXSimComponent]FXSimComponent::PropertiesOnActivateNew()", 0i64, 1u);
  if ( v8 )
  {
    Render::FXSimComponent::FXSimComponent((Render::FXSimComponent *)v8);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v12, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, (UFG::SimComponent *)&v10->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
  v10->mXform = v6->m_pTransformNodeComponent;
  if ( *v5 != -1 )
    Render::FXSimComponent::AttachEffect(v10, *v5, -1, 0i64);
  return v10;
}

// File Line: 195
// RVA: 0x1D95E0
void __fastcall Render::FXSimComponent::Update(Render::FXSimComponent *this)
{
  Render::FXSimComponent::FxBinding *v1; // rdi
  UFG::qList<Render::FXSimComponent::FxBinding,Render::FXSimComponent::FxBinding,1,0> *v2; // r14
  Render::FXSimComponent *v3; // r15
  Render::FXSimComponent::FxBinding *v4; // rsi
  SkeletalPose *v5; // rcx
  UFG::TransformNodeComponent *v6; // rbx
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  UFG::qMatrix44 *v10; // rcx
  UFG::qMatrix44 *v11; // rax
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::qMatrix44 matrixWS; // [rsp+8h] [rbp-39h]
  UFG::qMatrix44 result; // [rsp+48h] [rbp+7h]

  v1 = (Render::FXSimComponent::FxBinding *)this->mEffects.mNode.mNext;
  v2 = &this->mEffects;
  v3 = this;
  if ( v1 != (Render::FXSimComponent::FxBinding *)&this->mEffects )
  {
    do
    {
      v4 = (Render::FXSimComponent::FxBinding *)v1->mNext;
      if ( UFG::Metrics::msInstance.mSimTime_Temp <= v1->mEndTime )
      {
        v5 = v3->mPose;
        matrixWS = UFG::qMatrix44::msIdentity;
        if ( v5 )
        {
          SkeletalPose::GetPositionWS(v5, v1->mAttachJoint, &matrixWS);
        }
        else
        {
          v6 = v3->mXform;
          UFG::TransformNodeComponent::UpdateWorldTransform(v3->mXform);
          v7 = v6->mWorldTransform.v2;
          v8 = v6->mWorldTransform.v3;
          v9 = v6->mWorldTransform.v0;
          matrixWS.v1 = v6->mWorldTransform.v1;
          matrixWS.v2 = v7;
          matrixWS.v0 = v9;
          matrixWS.v3 = v8;
        }
        v10 = v1->mAttachTransformOffset;
        if ( v10 )
        {
          v11 = UFG::qMatrix44::operator*(v10, &result, &matrixWS);
          v12 = v11->v2;
          v13 = v11->v3;
          v14 = v11->v0;
          matrixWS.v1 = v11->v1;
          matrixWS.v2 = v12;
          matrixWS.v0 = v14;
          matrixWS.v3 = v13;
        }
        UFG::TransformNodeComponent::SetLocalTransform(v1->mAttachTransform, &matrixWS);
      }
      else
      {
        Render::FXSimComponent::FxBinding::~FxBinding(v1);
        operator delete[](v1);
      }
      v1 = v4;
    }
    while ( v4 != (Render::FXSimComponent::FxBinding *)v2 );
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

