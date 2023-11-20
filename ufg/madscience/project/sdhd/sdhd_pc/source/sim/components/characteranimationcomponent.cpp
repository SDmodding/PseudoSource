// File Line: 70
// RVA: 0x154DA00
__int64 dynamic_initializer_for__UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList__);
}

// File Line: 71
// RVA: 0x5825E0
UFG::ComponentIDDesc *__fastcall UFG::CharacterAnimationComponent::GetDesc(UFG::CharacterAnimationComponent *this)
{
  return &UFG::CharacterAnimationComponent::_TypeIDesc;
}

// File Line: 77
// RVA: 0x57C820
void __fastcall UFG::CharacterAnimationComponent::CharacterAnimationComponent(UFG::CharacterAnimationComponent *this, UFG::SceneObjectProperties *pSceneObj, component_CharacterAnimation *dataPtr)
{
  UFG::CharacterAnimationComponent *v3; // rbx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v4; // rdx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v5; // rax

  v3 = this;
  UFG::BaseAnimationComponent::BaseAnimationComponent(
    (UFG::BaseAnimationComponent *)&this->vfptr,
    pSceneObj,
    (component_BaseAnimation *)&dataPtr->DestroyAttachedCharacters);
  v4 = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterAnimationComponent::`vftable';
  v3->mEnableUpdateTransforms = 1;
  v3->mDamageRig = 0i64;
  v5 = UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev;
  UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList;
  UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::CharacterAnimationComponent::_CharacterAnimationComponentTypeUID,
    "CharacterAnimationComponent");
}

// File Line: 86
// RVA: 0x57C740
void __fastcall UFG::CharacterAnimationComponent::CharacterAnimationComponent(UFG::CharacterAnimationComponent *this, UFG::RigResource *rig)
{
  UFG::RigResource *v2; // rdi
  UFG::CharacterAnimationComponent *v3; // rbx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v4; // r8
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v5; // rax
  unsigned int v6; // esi
  UFG::qResourceInventory *inventory; // rax
  UFG::qResourceWarehouse *v8; // rax

  v2 = rig;
  v3 = this;
  UFG::BaseAnimationComponent::BaseAnimationComponent((UFG::BaseAnimationComponent *)&this->vfptr, rig);
  v4 = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterAnimationComponent::`vftable';
  v3->mEnableUpdateTransforms = 1;
  v3->mDamageRig = 0i64;
  v5 = UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev;
  UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList;
  UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::CharacterAnimationComponent::_CharacterAnimationComponentTypeUID,
    "CharacterAnimationComponent");
  v6 = v2->mNode.mUID;
  inventory = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = inventory;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mRigHandle.mPrev,
    0x39BC0A7Eu,
    v6,
    (UFG::qResourceData *)&v2->mNode,
    inventory);
}

// File Line: 94
// RVA: 0x57D790
void __fastcall UFG::CharacterAnimationComponent::~CharacterAnimationComponent(UFG::CharacterAnimationComponent *this)
{
  UFG::CharacterAnimationComponent *v1; // rbx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v2; // rdi
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v3; // rcx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v4; // rax
  CharacterDamageRig *v5; // rsi
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v6; // rcx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v7; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterAnimationComponent::`vftable';
  if ( this == UFG::CharacterAnimationComponent::s_CharacterAnimationComponentpCurrentIterator )
    UFG::CharacterAnimationComponent::s_CharacterAnimationComponentpCurrentIterator = (UFG::CharacterAnimationComponent *)&this->mPrev[-13].mNext;
  v2 = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( v1->mDamageRig )
  {
    --gNumberofCharacterDamageRigsAllocated;
    gCharacterDamageRigAllocated -= 784;
    v5 = v1->mDamageRig;
    if ( v5 )
    {
      CharacterDamageRig::~CharacterDamageRig(v1->mDamageRig);
      operator delete[](v5);
    }
  }
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BaseAnimationComponent::~BaseAnimationComponent((UFG::BaseAnimationComponent *)&v1->vfptr);
}

// File Line: 108
// RVA: 0x5863A0
void __fastcall UFG::CharacterAnimationComponent::OnAttach(UFG::CharacterAnimationComponent *this, UFG::SimObject *object)
{
  UFG::SimObjectGame *v2; // rbx
  UFG::CharacterAnimationComponent *v3; // rsi
  Creature *v4; // rcx
  UFG::TransformNodeComponent *v5; // rdi
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax

  v2 = (UFG::SimObjectGame *)object;
  v3 = this;
  UFG::BaseAnimationComponent::OnAttach((UFG::BaseAnimationComponent *)&this->vfptr, object);
  v4 = v3->mCreature;
  if ( v4 )
  {
    if ( v2 )
      v5 = v2->m_pTransformNodeComponent;
    else
      v5 = 0i64;
    Creature::SetTransformNodeComponentRoot(v4, v5);
    if ( v5 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v5);
      Creature::SetTransform(v3->mCreature, &v5->mWorldTransform);
    }
    if ( v2 )
    {
      v6 = v2->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v2->m_Components.p[27].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v2->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      if ( v7 )
        UFG::CharacterAnimationComponent::CreateDamageRig(v3);
    }
  }
}

// File Line: 129
// RVA: 0x586A90
void __fastcall UFG::CharacterAnimationComponent::OnDetach(UFG::CharacterAnimationComponent *this)
{
  UFG::CharacterAnimationComponent *v1; // rbx
  Creature *v2; // rcx
  CharacterDamageRig *v3; // rdi

  v1 = this;
  UFG::PhysicsSystem::RemovePhysicsComponents(
    (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
    this->m_pSimObject);
  v2 = v1->mCreature;
  if ( v2 )
  {
    Creature::DestroyAllAttachments(v2, v1->m_pSimObject, v1->mDestroyAttachedCharacters == 0);
    Creature::KillBlendTree(v1->mCreature);
  }
  UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks((UFG::BaseAnimationComponent *)&v1->vfptr);
  if ( v1->mDamageRig )
  {
    --gNumberofCharacterDamageRigsAllocated;
    gCharacterDamageRigAllocated -= 784;
    v3 = v1->mDamageRig;
    if ( v3 )
    {
      CharacterDamageRig::~CharacterDamageRig(v1->mDamageRig);
      operator delete[](v3);
    }
    v1->mDamageRig = 0i64;
  }
}

// File Line: 142
// RVA: 0x58D560
void __fastcall UFG::CharacterAnimationComponent::Update(UFG::CharacterAnimationComponent *this, float delta_sec)
{
  UFG::CharacterAnimationComponent *v2; // rbx
  __int64 v3; // rdx
  __int64 v4; // r8
  CharacterDamageRig *v5; // rcx
  Creature *v6; // rcx

  v2 = this;
  UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature((UFG::BaseAnimationComponent *)&this->vfptr);
  v5 = v2->mDamageRig;
  if ( v5 )
    CharacterDamageRig::Update(v5, delta_sec);
  if ( !v2->mUpdatedFromNIS )
  {
    if ( !v2->mUpdatedWithResources )
    {
      if ( !UFG::BaseAnimationComponent::AreResourcesAvailable((UFG::BaseAnimationComponent *)&v2->vfptr) )
        return;
      v2->mUpdatedWithResources = 1;
    }
    v6 = v2->mCreature;
    if ( v6 && v2->mRigHandle.mData )
    {
      Creature::Update(v6, delta_sec, v3, v4);
      if ( v2->mEnableUpdateTransforms )
        Creature::SubmitPoseTask(v2->mCreature);
    }
    v2->mTransformsUpdated = 0;
  }
}

// File Line: 181
// RVA: 0x591910
void __fastcall UFG::CharacterAnimationComponent::UpdateTransforms(UFG::CharacterAnimationComponent *this)
{
  UFG::CharacterAnimationComponent *v1; // rbx
  Creature *v2; // rcx

  v1 = this;
  if ( (this->m_Flags & 3) == 1 )
  {
    v2 = this->mCreature;
    if ( v2 )
    {
      if ( v1->mRigHandle.mData )
      {
        if ( v1->mEnableUpdateTransforms )
        {
          if ( !v1->mTransformsUpdated )
          {
            Creature::UpdateTransforms(v2);
            v1->mTransformsUpdated = 1;
          }
        }
        else
        {
          Creature::WaitOnPoseTask(v2);
        }
      }
    }
  }
}

// File Line: 220
// RVA: 0x58A5A0
UFG::SimComponent *__fastcall UFG::CharacterAnimationComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  component_CharacterAnimation *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rdx
  unsigned __int16 v13; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_CharacterAnimation::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::CharacterAnimationComponent::CharacterAnimationComponent((UFG::CharacterAnimationComponent *)v10, v3, v7);
    v6 = v11;
  }
  v12 = v3->m_pSimObject;
  v13 = v12->m_Flags;
  if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
  {
    v14 = 9;
  }
  else if ( (v13 >> 13) & 1 )
  {
    v14 = 8;
  }
  else
  {
    v14 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v15, v12, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return v6;
}

// File Line: 238
// RVA: 0x58B320
void __fastcall UFG::CharacterAnimationComponent::Reset(UFG::CharacterAnimationComponent *this)
{
  UFG::CharacterAnimationComponent *v1; // rbx

  v1 = this;
  UFG::BaseAnimationComponent::Reset((UFG::BaseAnimationComponent *)&this->vfptr);
  UFG::CharacterAnimationComponent::CreateDamageRig(v1);
}

// File Line: 245
// RVA: 0x58C910
void __fastcall UFG::CharacterAnimationComponent::Suspend(UFG::CharacterAnimationComponent *this)
{
  Creature *v1; // rax
  UFG::SimObject *v2; // rsi
  UFG::CharacterAnimationComponent *v3; // rdi
  signed __int64 v4; // rbx
  UFG::SimObject *v5; // rcx
  unsigned __int16 v6; // cx

  v1 = this->mCreature;
  v2 = this->m_pSimObject;
  v3 = this;
  v4 = (signed __int64)&v1->mAttachments.mNode.mNext[-1].mNext;
  if ( (Creature *)v4 != (Creature *)&v1->mGroundNormal.z )
  {
    do
    {
      v5 = *(UFG::SimObject **)(v4 + 104);
      if ( v5 && v2 != v5 && (v5->m_Flags >> 13) & 1 )
        UFG::SimObject::Suspend(v5);
      v4 = *(_QWORD *)(v4 + 16) - 8i64;
    }
    while ( (Creature *)v4 != (Creature *)&v3->mCreature->mGroundNormal.z );
  }
  v6 = v3->m_Flags;
  if ( !(((unsigned __int8)v6 >> 1) & 1) )
    v3->m_Flags = v6 | 2;
}

// File Line: 261
// RVA: 0x58B510
void __fastcall UFG::CharacterAnimationComponent::Restore(UFG::CharacterAnimationComponent *this)
{
  Creature *v1; // rax
  UFG::SimObject *v2; // rsi
  UFG::CharacterAnimationComponent *v3; // rdi
  signed __int64 v4; // rbx
  UFG::SimObject *v5; // rcx
  unsigned __int16 v6; // cx

  v1 = this->mCreature;
  v2 = this->m_pSimObject;
  v3 = this;
  v4 = (signed __int64)&v1->mAttachments.mNode.mNext[-1].mNext;
  if ( (Creature *)v4 != (Creature *)&v1->mGroundNormal.z )
  {
    do
    {
      v5 = *(UFG::SimObject **)(v4 + 104);
      if ( v5 && v2 != v5 && (v5->m_Flags >> 13) & 1 )
        UFG::SimObject::Restore(v5);
      v4 = *(_QWORD *)(v4 + 16) - 8i64;
    }
    while ( (Creature *)v4 != (Creature *)&v3->mCreature->mGroundNormal.z );
  }
  v6 = v3->m_Flags;
  if ( ((unsigned __int8)v6 >> 1) & 1 )
    v3->m_Flags = v6 & 0xFFFD;
}

// File Line: 280
// RVA: 0x580570
void __fastcall UFG::CharacterAnimationComponent::CreateDamageRig(UFG::CharacterAnimationComponent *this)
{
  UFG::CharacterAnimationComponent *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rax
  UFG::qResourceData *v6; // rax
  CharacterDamageRig *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  unsigned int v9; // edi
  CharacterDamageRig *v10; // rax
  __int64 v11; // r8
  __int64 v12; // r9
  __int64 v13; // r10
  __m128 v14; // xmm1
  CharacterDamageRig *v15; // rax
  __m128 v16; // xmm1
  CharacterDamageRig *v17; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 & 0x8000u) == 0 || !v2->m_Components.p[32].m_pComponent )
    {
      if ( (v3 >> 14) & 1 )
      {
        v4 = v2->m_Components.p[14].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = v2->m_Components.p[9].m_pComponent;
        }
        else
        {
          if ( (v3 >> 12) & 1 )
            v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CompositeDrawableComponent::_TypeUID);
          else
            v5 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v2->vfptr,
                   UFG::CompositeDrawableComponent::_TypeUID);
          v4 = v5;
        }
      }
      else
      {
        v4 = v2->m_Components.p[14].m_pComponent;
      }
      v6 = v1->mRigHandle.mData;
      if ( v6 && v6[1].mNode.mChild[0] && SLODWORD(v6[1].mNode.mChild[0][1].mChild[1]) > 20 && v4 )
      {
        v7 = v1->mDamageRig;
        if ( v7 )
        {
          CharacterDamageRig::ResetDamage(v7);
          return;
        }
        v8 = UFG::qMalloc(0x310ui64, "CharacterDamageRig", 0i64);
        v9 = 0;
        if ( v8 )
          CharacterDamageRig::CharacterDamageRig((CharacterDamageRig *)v8);
        else
          v10 = 0i64;
        v1->mDamageRig = v10;
        gCharacterDamageRigAllocated += 784;
        v11 = 0i64;
        v12 = 0i64;
        v13 = 0i64;
        do
        {
          v1->mDamageRig->mCharacterMarkers[v11].mBoneIndex = v9;
          v14 = *(__m128 *)(v13 + *(_QWORD *)&v1->mRigHandle.mData[1].mNode.mChild[0][1].mUID);
          v15 = v1->mDamageRig;
          LODWORD(v15->mCharacterMarkers[v11].mPosition.x) = v14.m128_i32[0];
          LODWORD(v15->mCharacterMarkers[v11].mPosition.y) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 85);
          LODWORD(v15->mCharacterMarkers[v11].mPosition.z) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 170);
          v1->mDamageRig->mCharacterMarkers[v11].mNameUID = *(_DWORD *)(v12
                                                                      + *(_QWORD *)&v1->mRigHandle.mData[1].mNode.mUID);
          v1->mDamageRig->mCharacterMarkers[v11 + 1].mBoneIndex = v9 + 1;
          v16 = *(__m128 *)(*(_QWORD *)&v1->mRigHandle.mData[1].mNode.mChild[0][1].mUID + v13 + 48);
          v17 = v1->mDamageRig;
          LODWORD(v17->mCharacterMarkers[v11 + 1].mPosition.x) = v16.m128_i32[0];
          LODWORD(v17->mCharacterMarkers[v11 + 1].mPosition.y) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 85);
          LODWORD(v17->mCharacterMarkers[v11 + 1].mPosition.z) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 170);
          v1->mDamageRig->mCharacterMarkers[v11 + 1].mNameUID = *(_DWORD *)(*(_QWORD *)&v1->mRigHandle.mData[1].mNode.mUID
                                                                          + v12
                                                                          + 4);
          v9 += 2;
          v13 += 96i64;
          v12 += 8i64;
          v11 += 2i64;
        }
        while ( v9 < 0x1A );
        CharacterDamageRig::InitCharacterBoneNormals(v1->mDamageRig);
      }
      ++gNumberofCharacterDamageRigsAllocated;
    }
  }
}

// File Line: 337
// RVA: 0x57F150
void __fastcall UFG::CharacterAnimationComponent::ApplyBulletDamage(UFG::CharacterAnimationComponent *this, UFG::RayCastData *bulletRay)
{
  CharacterDamageRig *v2; // rax
  float v3; // xmm0_4
  float v4; // xmm4_4
  __m128 v5; // xmm3
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  __m128 v9; // xmm2
  float v10; // xmm1_4
  Creature *v11; // rdx
  float v12; // [rsp+30h] [rbp-48h]
  float v13; // [rsp+34h] [rbp-44h]
  float v14; // [rsp+38h] [rbp-40h]
  int v15; // [rsp+3Ch] [rbp-3Ch]
  float v16; // [rsp+40h] [rbp-38h]
  float v17; // [rsp+44h] [rbp-34h]
  float v18; // [rsp+48h] [rbp-30h]
  int v19; // [rsp+4Ch] [rbp-2Ch]

  v2 = this->mDamageRig;
  if ( v2 )
  {
    v3 = bulletRay->point.x;
    v4 = bulletRay->normal.y;
    v5 = (__m128)LODWORD(bulletRay->normal.x);
    v19 = 1065353216;
    v9 = v5;
    v6 = bulletRay->point.y;
    v7 = bulletRay->normal.z;
    v16 = v3;
    v8 = bulletRay->point.z;
    v17 = v6;
    v18 = v8;
    v9.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v4 * v4)) + (float)(v7 * v7);
    if ( v9.m128_f32[0] == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
    v11 = this->mCreature;
    v12 = (float)(v5.m128_f32[0] * v10) * -1.0;
    v15 = 1065353216;
    v13 = (float)(v4 * v10) * -1.0;
    v14 = (float)(v7 * v10) * -1.0;
    CharacterDamageRig::ApplyDamageVector(v2, v11, (UFG::qVector4 *)&v16, (UFG::qVector4 *)&v12, 1.0, 0.0);
  }
}

// File Line: 347
// RVA: 0x57F060
void __fastcall UFG::CharacterAnimationComponent::ApplyBluntForceDamage(UFG::CharacterAnimationComponent *this, Creature *creature, UFG::qVector4 *hitPositionWS, UFG::qVector4 *invHitNormal, float damage)
{
  UFG::CharacterAnimationComponent *v5; // rbx
  UFG::SimObjectGame *v6; // rcx
  UFG::qVector4 *v7; // rdi
  UFG::qVector4 *v8; // rsi
  Creature *v9; // rbp
  unsigned __int16 v10; // r10
  UFG::SimComponent *v11; // rax

  v5 = this;
  v6 = (UFG::SimObjectGame *)this->m_pSimObject;
  v7 = invHitNormal;
  v8 = hitPositionWS;
  v9 = creature;
  if ( v6 && v5->mDamageRig )
  {
    v10 = v6->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = v6->m_Components.p[6].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::HealthComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::HealthComponent::_TypeUID);
      }
    }
    else
    {
      v11 = v6->m_Components.p[6].m_pComponent;
    }
    if ( v11 )
      CharacterDamageRig::ApplyBluntForceDamageToBone(
        v5->mDamageRig,
        v9,
        v8,
        v7,
        damage,
        *((float *)&v11[1].m_SafePointerList.mNode.mNext + 1) / *(float *)&v11[1].m_NameUID);
  }
}

// File Line: 363
// RVA: 0x58BBC0
void __fastcall UFG::CharacterAnimationComponent::SetVisualDamage(UFG::CharacterAnimationComponent *this, const unsigned int bone_uid, const float damageAmount, const float duration)
{
  JUMPOUT(this->mDamageRig, 0i64, CharacterDamageRig::SetVisualDamage);
}

// File Line: 371
// RVA: 0x57F280
void __fastcall UFG::CharacterAnimationComponent::ApplyPaintEffect(UFG::CharacterAnimationComponent *this, bool enable, float r, float g, float b)
{
  CharacterDamageRig::ApplyPaintEffect(this->mDamageRig, enable, r, g, b);
}

// File Line: 376
// RVA: 0x57F270
void __fastcall UFG::CharacterAnimationComponent::ApplyCharredEffect(UFG::CharacterAnimationComponent *this, float amt)
{
  CharacterDamageRig::ApplyCharredEffect(this->mDamageRig, amt);
}

// File Line: 381
// RVA: 0x57F7B0
void __fastcall UFG::CharacterAnimationComponent::Clone(UFG::CharacterAnimationComponent *this, UFG::CharacterAnimationComponent *source)
{
  CharacterDamageRig *v2; // rcx

  v2 = this->mDamageRig;
  if ( v2 )
    CharacterDamageRig::Clone(v2, source->mDamageRig);
}

// File Line: 395
// RVA: 0x154D9E0
__int64 dynamic_initializer_for__UFG::CameraAnimationComponent::s_CameraAnimationComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CameraAnimationComponent::s_CameraAnimationComponentList__);
}

// File Line: 396
// RVA: 0x5829A0
const char *__fastcall UFG::CameraAnimationComponent::GetTypeName(UFG::CameraAnimationComponent *this)
{
  return "CameraAnimationComponent";
}

// File Line: 400
// RVA: 0x57C6C0
void __fastcall UFG::CameraAnimationComponent::CameraAnimationComponent(UFG::CameraAnimationComponent *this, UFG::SceneObjectProperties *pSceneObj, component_CameraAnimation *dataPtr)
{
  UFG::CameraAnimationComponent *v3; // rbx
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v4; // rdx
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v5; // rax

  v3 = this;
  UFG::BaseAnimationComponent::BaseAnimationComponent(
    (UFG::BaseAnimationComponent *)&this->vfptr,
    pSceneObj,
    (component_BaseAnimation *)&dataPtr->DestroyAttachedCharacters);
  v4 = (UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraAnimationComponent::`vftable';
  v5 = UFG::CameraAnimationComponent::s_CameraAnimationComponentList.mNode.mPrev;
  UFG::CameraAnimationComponent::s_CameraAnimationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *)&UFG::CameraAnimationComponent::s_CameraAnimationComponentList;
  UFG::CameraAnimationComponent::s_CameraAnimationComponentList.mNode.mPrev = (UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::CameraAnimationComponent::_CameraAnimationComponentTypeUID,
    "CameraAnimationComponent");
}

// File Line: 409
// RVA: 0x57D710
void __fastcall UFG::CameraAnimationComponent::~CameraAnimationComponent(UFG::CameraAnimationComponent *this)
{
  UFG::CameraAnimationComponent *v1; // r8
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v2; // rdx
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v3; // rcx
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v4; // rax
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v5; // rcx
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraAnimationComponent::`vftable';
  if ( this == UFG::CameraAnimationComponent::s_CameraAnimationComponentpCurrentIterator )
    UFG::CameraAnimationComponent::s_CameraAnimationComponentpCurrentIterator = (UFG::CameraAnimationComponent *)&this->mPrev[-13].mNext;
  v2 = (UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BaseAnimationComponent::~BaseAnimationComponent((UFG::BaseAnimationComponent *)&v1->vfptr);
}

// File Line: 415
// RVA: 0x58A4A0
UFG::SimComponent *__fastcall UFG::CameraAnimationComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *scene_object_properties, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  component_CameraAnimation *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = scene_object_properties;
  v4 = scene_object_properties->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_CameraAnimation::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = (component_CameraAnimation *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0xD8ui64, "CameraAnimationComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::CameraAnimationComponent::CameraAnimationComponent((UFG::CameraAnimationComponent *)v10, v3, v7);
    v6 = v11;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v12, v3->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
  return v6;
}

// File Line: 443
// RVA: 0x154DA60
__int64 dynamic_initializer_for__UFG::LightGroupComponent::s_LightGroupComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::LightGroupComponent::s_LightGroupComponentList__);
}

// File Line: 444
// RVA: 0x582640
UFG::ComponentIDDesc *__fastcall UFG::LightGroupComponent::GetDesc(UFG::LightGroupComponent *this)
{
  return &UFG::LightGroupComponent::_TypeIDesc;
}

// File Line: 450
// RVA: 0x57CE70
void __fastcall UFG::LightGroupComponent::LightGroupComponent(UFG::LightGroupComponent *this)
{
  UFG::LightGroupComponent *v1; // rbx
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v2; // rdx
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v3; // rax

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v2 = (UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::LightGroupComponent::`vftable';
  v1->mData = 0i64;
  v1->mDisabled = 0;
  v3 = UFG::LightGroupComponent::s_LightGroupComponentList.mNode.mPrev;
  UFG::LightGroupComponent::s_LightGroupComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *)&v1->mPrev;
  v2->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *)&UFG::LightGroupComponent::s_LightGroupComponentList;
  UFG::LightGroupComponent::s_LightGroupComponentList.mNode.mPrev = (UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *)&v1->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::LightGroupComponent::_LightGroupComponentTypeUID,
    "LightGroupComponent");
}

// File Line: 456
// RVA: 0x57DC30
void __fastcall UFG::LightGroupComponent::~LightGroupComponent(UFG::LightGroupComponent *this)
{
  UFG::LightGroupComponent *v1; // rdi
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v2; // rbx
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v3; // rcx
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v4; // rax
  UFG::LightGroupData *v5; // rbp
  __int64 v6; // rsi
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v7; // rcx
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::LightGroupComponent::`vftable';
  if ( this == UFG::LightGroupComponent::s_LightGroupComponentpCurrentIterator )
    UFG::LightGroupComponent::s_LightGroupComponentpCurrentIterator = (UFG::LightGroupComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mData;
  if ( v5 )
  {
    v6 = 0i64;
    if ( v5->mLightCount )
    {
      do
      {
        Render::DynamicLightManager::RemoveLight(&Render::gDynamicLightManager, &v5->mLightGroup[v6]);
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < v5->mLightCount );
    }
    v1->mData = 0i64;
  }
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 469
// RVA: 0x582D10
UFG::LightGroupComponent *__fastcall UFG::LightGroupComponent::Init(const char *lightGroupFile)
{
  const char *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::LightGroupComponent *v4; // rax
  UFG::LightGroupComponent *v5; // rbx

  v1 = lightGroupFile;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x60ui64, "LightGroupComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::LightGroupComponent::LightGroupComponent((UFG::LightGroupComponent *)v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::LightGroupComponent::InitLights(v5, v1);
  return v5;
}

// File Line: 500
// RVA: 0x57F730
void __fastcall UFG::LightGroupData::Clear(UFG::LightGroupData *this)
{
  __int64 v1; // rdi
  UFG::LightGroupData *v2; // rbx
  UFG::qVector3 *v3; // rcx
  Render::Light *v4; // rcx

  v1 = 0i64;
  v2 = this;
  if ( this->mLightCount )
  {
    do
    {
      Render::DynamicLightManager::RemoveLight(&Render::gDynamicLightManager, &v2->mLightGroup[v1]);
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->mLightCount );
  }
  v3 = v2->mLightGroupColorBackup;
  v2->mLightCount = 0;
  if ( v3 )
  {
    operator delete[](v3);
    v2->mLightGroupColorBackup = 0i64;
  }
  v4 = v2->mLightGroup;
  if ( v4 )
  {
    operator delete[](v4);
    v2->mLightGroup = 0i64;
  }
}

// File Line: 519
// RVA: 0x585AF0
void __fastcall UFG::LightGroupData::LoadFromXML(UFG::LightGroupData *this, const char *lightGroupFile)
{
  const char *v2; // rbx
  UFG::LightGroupData *v3; // rbp
  SimpleXML::XMLDocument *v4; // rax
  SimpleXML::XMLDocument *v5; // rsi
  SimpleXML::XMLNode *v6; // r12
  char v7; // r15
  __int64 v8; // rdi
  signed __int64 v9; // r14
  SimpleXML::XMLNode *v10; // rax
  SimpleXML::XMLNode *v11; // rbx
  unsigned __int64 v12; // rax

  v2 = lightGroupFile;
  v3 = this;
  UFG::LightGroupData::Clear(this);
  v4 = SimpleXML::XMLDocument::Open(v2, 1ui64, 0i64);
  v5 = v4;
  if ( v4 )
  {
    v6 = SimpleXML::XMLDocument::GetNode(v4, "LightGroup", 0i64);
    if ( v6 )
    {
      v7 = 1;
      v8 = 0i64;
      v9 = 2i64;
      do
      {
        v10 = SimpleXML::XMLDocument::GetChildNode(v5, "Light", v6);
        v11 = v10;
        if ( v7 )
        {
          if ( v10 )
          {
            do
            {
              LODWORD(v8) = v8 + 1;
              v11 = SimpleXML::XMLDocument::GetNode(v5, "Light", v11);
            }
            while ( v11 );
          }
          v7 = 0;
          v12 = 160i64 * (unsigned int)v8;
          if ( !is_mul_ok((unsigned int)v8, 0xA0ui64) )
            v12 = -1i64;
          v3->mLightGroup = (Render::Light *)UFG::qMalloc(v12, "LoadLightGroup.mLightGroup", 0i64);
          v3->mLightCount = v8;
          v8 = 0i64;
        }
        else if ( v10 )
        {
          do
          {
            Render::ParseLightFromXML(v11, &v3->mLightGroup[v8]);
            v11 = SimpleXML::XMLDocument::GetNode(v5, "Light", v11);
            v8 = (unsigned int)(v8 + 1);
          }
          while ( v11 );
        }
        --v9;
      }
      while ( v9 );
    }
    SimpleXML::XMLDocument::~XMLDocument(v5);
    operator delete[](v5);
  }
}

// File Line: 579
// RVA: 0x15522F0
__int64 UFG::_dynamic_initializer_for__gLightGroupDataCache__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::gLightGroupDataCache.mTree);
  return atexit(UFG::_dynamic_atexit_destructor_for__gLightGroupDataCache__);
}

// File Line: 582
// RVA: 0x585C60
void UFG::LightGroupComponent::LoadLightGroupCache(void)
{
  UFG::qString *i; // rdi
  UFG::LightGroupData *v1; // rbx
  unsigned int v2; // eax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  __int64 *v6; // rcx
  UFG::qString *v7; // rax
  __int64 *v8; // [rsp+38h] [rbp-40h]
  UFG::qString *v9; // [rsp+40h] [rbp-38h]
  UFG::qString result; // [rsp+48h] [rbp-30h]

  if ( once_6 )
  {
    v8 = (__int64 *)&v8;
    v9 = (UFG::qString *)&v8;
    UFG::ReadGenericXMLList(
      "data\\nis\\nislightingmanifest.xml",
      (UFG::qList<UFG::qString,UFG::qString,1,0> *)&v8,
      "Manifest",
      "XMLFile",
      0i64,
      0i64);
    for ( i = v9; i != (UFG::qString *)&v8; i = (UFG::qString *)i->mNext )
    {
      UFG::qString::GetFilenameWithoutExtension(i, &result);
      v1 = (UFG::LightGroupData *)UFG::qMalloc(0x38ui64, "LightGroupData", 0i64);
      if ( v1 )
      {
        v2 = UFG::qStringHashUpper32(result.mData, 0xFFFFFFFF);
        v1->mNode.mParent = 0i64;
        v1->mNode.mChild[0] = 0i64;
        v1->mNode.mChild[1] = 0i64;
        v1->mNode.mUID = v2;
        v1->mEnabled = 0;
        v1->mLightCount = 0;
        v1->mLightGroupColorBackup = 0i64;
        v1->mLightGroup = 0i64;
      }
      else
      {
        v1 = 0i64;
      }
      UFG::LightGroupData::LoadFromXML(v1, i->mData);
      UFG::qBaseTreeRB::Add(&UFG::gLightGroupDataCache.mTree, &v1->mNode);
      UFG::qString::~qString(&result);
    }
    once_6 = 0;
    for ( j = v9; v9 != (UFG::qString *)&v8; j = v9 )
    {
      v4 = j->mPrev;
      v5 = j->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
      j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
      UFG::qString::~qString(j);
      operator delete[](j);
    }
    v6 = v8;
    v7 = v9;
    v8[1] = (__int64)v9;
    v7->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v6;
  }
}

// File Line: 606
// RVA: 0x582A90
_BOOL8 __fastcall UFG::LightGroupComponent::GroupExists(const char *groupFilename)
{
  UFG::qString *v1; // rax
  int v2; // edx
  unsigned int v3; // eax
  UFG::qBaseTreeRB *v4; // rax
  bool v5; // bl
  UFG::qString result; // [rsp+28h] [rbp-60h]
  UFG::qString v8; // [rsp+50h] [rbp-38h]

  UFG::qString::qString(&v8, groupFilename);
  UFG::qString::GetFilenameWithoutExtension(v1, &result);
  UFG::qString::~qString(&v8);
  v3 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    v3 = UFG::qStringHashUpper32(result.mData, result.mStringHashUpper32 | v2);
    result.mStringHashUpper32 = v3;
  }
  if ( v3 )
    v4 = UFG::qBaseTreeRB::Get(&UFG::gLightGroupDataCache.mTree, v3);
  else
    v4 = 0i64;
  v5 = v4 != 0i64;
  UFG::qString::~qString(&result);
  return v5;
}

// File Line: 613
// RVA: 0x5837F0
void __fastcall UFG::LightGroupComponent::InitLights(UFG::LightGroupComponent *this, const char *lightGroupFile)
{
  UFG::LightGroupComponent *v2; // rbx
  UFG::qString *v3; // rax
  int v4; // edx
  unsigned int v5; // eax
  UFG::qBaseTreeRB *v6; // rax
  UFG::qString result; // [rsp+28h] [rbp-60h]
  UFG::qString v8; // [rsp+50h] [rbp-38h]

  v2 = this;
  UFG::qString::qString(&v8, lightGroupFile);
  UFG::qString::GetFilenameWithoutExtension(v3, &result);
  UFG::qString::~qString(&v8);
  v5 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    v5 = UFG::qStringHashUpper32(result.mData, result.mStringHashUpper32 | v4);
    result.mStringHashUpper32 = v5;
  }
  if ( v5 )
    v6 = UFG::qBaseTreeRB::Get(&UFG::gLightGroupDataCache.mTree, v5);
  else
    v6 = 0i64;
  v2->mData = (UFG::LightGroupData *)v6;
  UFG::qString::~qString(&result);
}

// File Line: 622
// RVA: 0x57F380
void __fastcall UFG::LightGroupComponent::AttachLights(UFG::LightGroupComponent *this)
{
  UFG::LightGroupData *v1; // rax
  UFG::LightGroupComponent *v2; // rdi
  __int64 v3; // rbx
  __int128 v4; // xmm8
  signed __int64 v5; // rdx
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  v1 = this->mData;
  v2 = this;
  if ( v1 )
  {
    if ( v1->mLightGroup )
    {
      v3 = 0i64;
      v4 = LODWORD(UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight);
      if ( v2->mData->mLightCount )
      {
        do
        {
          v5 = (signed __int64)&v2->mData->mLightGroup[v3];
          v6 = *(float *)(v5 + 96);
          v7 = *(float *)(v5 + 100) - v6;
          if ( v7 < 0.0 )
            v7 = v7 + 86400.0;
          v8 = *(float *)&v4 - v6;
          if ( (float)(*(float *)&v4 - v6) < 0.0 )
            v8 = v8 + 86400.0;
          if ( v8 <= v7 )
            UFG::DaemonManager::RegisterDaemon(
              (UFG::RoadNetworkVisibleAreaEdgeManager *)&Render::gDynamicLightManager,
              (UFG::RoadNetworkVisibleAreaEdge *)v5);
          v3 = (unsigned int)(v3 + 1);
        }
        while ( (unsigned int)v3 < v2->mData->mLightCount );
      }
    }
  }
}

// File Line: 707
// RVA: 0x154DA40
__int64 dynamic_initializer_for__UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList__);
}

// File Line: 708
// RVA: 0x154D610
__int64 dynamic_initializer_for__UFG::LightGroupAnimationComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::LightGroupAnimationComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::LightGroupAnimationComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::LightGroupAnimationComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::LightGroupAnimationComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 713
// RVA: 0x57CDD0
void __fastcall UFG::LightGroupAnimationComponent::LightGroupAnimationComponent(UFG::LightGroupAnimationComponent *this, UFG::RigResource *rig)
{
  UFG::LightGroupAnimationComponent *v2; // rdi
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v3; // rbx
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v4; // rax

  v2 = this;
  UFG::BaseAnimationComponent::BaseAnimationComponent((UFG::BaseAnimationComponent *)&this->vfptr, rig);
  v3 = (UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::LightGroupAnimationComponent::`vftable';
  UFG::RebindingComponentHandle<UFG::LightGroupComponent,0>::RebindingComponentHandle<UFG::LightGroupComponent,0>(&v2->mLightGroupComponent);
  v2->mLightInfo = 0i64;
  v4 = UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList.mNode.mPrev;
  UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *)&UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList;
  UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList.mNode.mPrev = (UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::LightGroupAnimationComponent::_LightGroupAnimationComponentTypeUID,
    "LightGroupAnimationComponent");
}

// File Line: 719
// RVA: 0x57DB90
void __fastcall UFG::LightGroupAnimationComponent::~LightGroupAnimationComponent(UFG::LightGroupAnimationComponent *this)
{
  UFG::LightGroupAnimationComponent *v1; // rdi
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v2; // rbx
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v3; // rcx
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v4; // rax
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v5; // rcx
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::LightGroupAnimationComponent::`vftable';
  if ( this == UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentpCurrentIterator )
    UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentpCurrentIterator = (UFG::LightGroupAnimationComponent *)&this->mPrev[-13].mNext;
  v2 = (UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mLightGroupComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BaseAnimationComponent::~BaseAnimationComponent((UFG::BaseAnimationComponent *)&v1->vfptr);
}

// File Line: 726
// RVA: 0x582CB0
void __fastcall UFG::LightGroupAnimationComponent::Init(UFG::RigResource *rig)
{
  UFG::RigResource *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax

  v1 = rig;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x110ui64, "LightGroupAnimationComponent", 0i64, 1u);
  if ( v3 )
    UFG::LightGroupAnimationComponent::LightGroupAnimationComponent((UFG::LightGroupAnimationComponent *)v3, v1);
}

// File Line: 733
// RVA: 0x5865E0
void __fastcall UFG::LightGroupAnimationComponent::OnAttach(UFG::LightGroupAnimationComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rbp
  UFG::LightGroupAnimationComponent *v3; // rdi
  UFG::RebindingComponentHandle<UFG::LightGroupComponent,0> *v4; // rbx
  unsigned int v5; // esi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::SimComponent *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rbp
  int v13; // ebx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // kr00_8
  UFG::allocator::free_link *v16; // rax
  int v17; // edx
  UFG::allocator::free_link *v18; // rcx
  UFG::LightGroupAnimationComponent::LightBoneInfo *v19; // r14
  unsigned int v20; // ebx
  Creature *v21; // rcx
  signed int v22; // eax
  unsigned int v23; // eax
  Creature *v24; // rcx
  signed int v25; // eax
  unsigned int v26; // eax
  Creature *v27; // rcx
  signed int v28; // eax

  v2 = object;
  v3 = this;
  UFG::BaseAnimationComponent::OnAttach((UFG::BaseAnimationComponent *)&this->vfptr, object);
  v4 = &v3->mLightGroupComponent;
  v5 = 0;
  if ( v3->mLightGroupComponent.m_pSimComponent )
  {
    v6 = v4->mPrev;
    v7 = v3->mLightGroupComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v3->mLightGroupComponent.m_pSimComponent = 0i64;
LABEL_7:
    v3->mLightGroupComponent.m_pSimObject = 0i64;
    v3->mLightGroupComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mLightGroupComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->mLightGroupComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::LightGroupComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::LightGroupComponent,0> *)v3->mLightGroupComponent.mNext != &v3->mLightGroupComponent) )
  {
    v8 = v4->mPrev;
    v9 = v3->mLightGroupComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v3->mLightGroupComponent.m_Changed = 1;
  v3->mLightGroupComponent.m_pSimObject = v2;
  v3->mLightGroupComponent.m_TypeUID = UFG::LightGroupComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::LightGroupComponent,0>::BindInternal<UFG::SimObject>(&v3->mLightGroupComponent, v2);
  if ( v3->mLightGroupComponent.m_pSimComponent )
  {
    v10 = v3->mLightGroupComponent.m_pSimComponent;
    if ( v10[1].m_SafePointerList.mNode.mNext )
    {
      if ( !v3->mLightInfo )
      {
        v11 = v10[1].m_SafePointerList.mNode.mNext;
        v12 = v11[3].mPrev;
        v13 = HIDWORD(v11[2].mPrev);
        v15 = HIDWORD(v11[2].mPrev);
        v14 = 12 * v15;
        if ( !is_mul_ok(v15, 0xCui64) )
          v14 = -1i64;
        v16 = UFG::qMalloc(v14, "LightGroupAnimationComponent", 0i64);
        if ( v16 )
        {
          v17 = v13 - 1;
          if ( v13 - 1 >= 0 )
          {
            v18 = v16 + 1;
            do
            {
              v18[-1].mNext = (UFG::allocator::free_link *)-1i64;
              LODWORD(v18->mNext) = -1;
              v18 = (UFG::allocator::free_link *)((char *)v18 + 12);
              --v17;
            }
            while ( v17 >= 0 );
          }
        }
        else
        {
          v16 = 0i64;
        }
        v3->mLightInfo = (UFG::LightGroupAnimationComponent::LightBoneInfo *)v16;
        if ( HIDWORD(v3->mLightGroupComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext[2].mPrev) )
        {
          do
          {
            v19 = &v3->mLightInfo[v5];
            v20 = HIDWORD(v12[10 * v5 + 7].mNext);
            v21 = v3->mCreature;
            if ( v21->mPose.mRigHandle.mData )
              v22 = Skeleton::GetBoneID(v21->mPose.mRigHandle.mUFGSkeleton, v20);
            else
              v22 = -1;
            v19->mMainBoneId = v22;
            v23 = UFG::qStringHashUpper32("_datapoint0", v20);
            v24 = v3->mCreature;
            if ( v24->mPose.mRigHandle.mData )
              v25 = Skeleton::GetBoneID(v24->mPose.mRigHandle.mUFGSkeleton, v23);
            else
              v25 = -1;
            v19->mData0BoneId = v25;
            v26 = UFG::qStringHashUpper32("_datapoint1", v20);
            v27 = v3->mCreature;
            if ( v27->mPose.mRigHandle.mData )
              v28 = Skeleton::GetBoneID(v27->mPose.mRigHandle.mUFGSkeleton, v26);
            else
              v28 = -1;
            v19->mData1BoneId = v28;
            ++v5;
          }
          while ( v5 < HIDWORD(v3->mLightGroupComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext[2].mPrev) );
        }
      }
    }
  }
}

// File Line: 761
// RVA: 0x586D60
void __fastcall UFG::LightGroupAnimationComponent::OnDetach(UFG::LightGroupAnimationComponent *this)
{
  UFG::RebindingComponentHandle<UFG::LightGroupComponent,0> *v1; // r8
  UFG::LightGroupAnimationComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax

  v1 = &this->mLightGroupComponent;
  v2 = this;
  if ( this->mLightGroupComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->mLightGroupComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->mLightGroupComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mLightGroupComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::LightGroupComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::LightGroupComponent,0> *)this->mLightGroupComponent.mNext != &this->mLightGroupComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v1->m_Changed = 1;
  operator delete[](v2->mLightInfo);
  v2->mLightInfo = 0i64;
}

// File Line: 768
// RVA: 0x591970
void __fastcall UFG::LightGroupAnimationComponent::UpdateTransforms(UFG::LightGroupAnimationComponent *this)
{
  UFG::SimComponent *v1; // rax
  UFG::LightGroupAnimationComponent *v2; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rbx
  unsigned int v5; // eax
  Creature *v6; // r14
  __int64 v7; // rdi
  __int64 v8; // r15
  signed __int64 v9; // rbx
  UFG::LightGroupAnimationComponent::LightBoneInfo *v10; // rbp
  int v11; // edx
  UFG::qVector4 v12; // xmm1
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm3
  int v15; // edx
  float v16; // xmm1_4
  float v17; // xmm2_4
  int v18; // edx
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-E8h]
  UFG::qMatrix44 matrixLS; // [rsp+60h] [rbp-A8h]
  UFG::qMatrix44 v21; // [rsp+A0h] [rbp-68h]

  v1 = this->mLightGroupComponent.m_pSimComponent;
  v2 = this;
  if ( v1 && v1[1].m_SafePointerList.mNode.mNext && !LOBYTE(v1[1].m_TypeUID) )
  {
    if ( (this->m_Flags & 3) == 1 && !this->mTransformsUpdated )
    {
      Creature::UpdateTransforms(this->mCreature);
      v2->mTransformsUpdated = 1;
    }
    v3 = v2->mLightGroupComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext;
    v4 = v3[3].mPrev;
    if ( v4 )
    {
      v5 = HIDWORD(v3[2].mPrev);
      v6 = v2->mCreature;
      if ( v5 )
      {
        v7 = 0i64;
        v8 = v5;
        v9 = (signed __int64)&v4[4].mNext;
        do
        {
          v10 = v2->mLightInfo;
          v11 = v10[v7].mMainBoneId;
          if ( *(_BYTE *)(v9 + 50) == 0 && v11 != -1 )
          {
            Creature::GetTransform(v2->mCreature, v11, &transform);
            v12 = transform.v1;
            v13 = transform.v2;
            v14 = transform.v3;
            *(UFG::qVector4 *)(v9 - 72) = transform.v0;
            *(UFG::qVector4 *)(v9 - 56) = v12;
            *(UFG::qVector4 *)(v9 - 40) = v13;
            *(UFG::qVector4 *)(v9 - 24) = v14;
            v15 = v10[v7].mData0BoneId;
            if ( v15 != -1 )
            {
              SkeletalPose::GetPositionLS(&v6->mPose, v15, &matrixLS);
              v16 = matrixLS.v3.y;
              v17 = matrixLS.v3.z;
              *(float *)(v9 - 8) = matrixLS.v3.x;
              *(float *)(v9 - 4) = v16;
              *(float *)v9 = v17;
            }
            v18 = v10[v7].mData1BoneId;
            if ( v18 != -1 )
            {
              SkeletalPose::GetPositionLS(&v6->mPose, v18, &v21);
              *(_BYTE *)(v9 + 33) = v21.v3.x < 0.5;
            }
          }
          ++v7;
          v9 += 160i64;
          --v8;
        }
        while ( v8 );
      }
    }
  }
}

