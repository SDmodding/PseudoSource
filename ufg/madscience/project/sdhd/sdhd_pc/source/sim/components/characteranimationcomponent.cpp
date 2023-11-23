// File Line: 70
// RVA: 0x154DA00
__int64 dynamic_initializer_for__UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList__);
}

// File Line: 71
// RVA: 0x5825E0
UFG::ComponentIDDesc *__fastcall UFG::CharacterAnimationComponent::GetDesc(UFG::CharacterAnimationComponent *this)
{
  return &UFG::CharacterAnimationComponent::_TypeIDesc;
}

// File Line: 77
// RVA: 0x57C820
void __fastcall UFG::CharacterAnimationComponent::CharacterAnimationComponent(
        UFG::CharacterAnimationComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_CharacterAnimation *dataPtr)
{
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *mPrev; // rax

  UFG::BaseAnimationComponent::BaseAnimationComponent(this, pSceneObj, dataPtr);
  this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mPrev = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mNext = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterAnimationComponent::`vftable;
  this->mEnableUpdateTransforms = 1;
  this->mDamageRig = 0i64;
  mPrev = UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev;
  UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mNext = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList;
  UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CharacterAnimationComponent::_CharacterAnimationComponentTypeUID,
    "CharacterAnimationComponent");
}

// File Line: 86
// RVA: 0x57C740
void __fastcall UFG::CharacterAnimationComponent::CharacterAnimationComponent(
        UFG::CharacterAnimationComponent *this,
        UFG::RigResource *rig)
{
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *mPrev; // rax
  unsigned int mUID; // esi
  UFG::qResourceInventory *inventory; // rax
  UFG::qResourceWarehouse *v7; // rax

  UFG::BaseAnimationComponent::BaseAnimationComponent(this, rig);
  this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mPrev = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mNext = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterAnimationComponent::`vftable;
  this->mEnableUpdateTransforms = 1;
  this->mDamageRig = 0i64;
  mPrev = UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev;
  UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mNext = (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList;
  UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CharacterAnimationComponent::_CharacterAnimationComponentTypeUID,
    "CharacterAnimationComponent");
  mUID = rig->mNode.mUID;
  inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = inventory;
  }
  UFG::qResourceHandle::Init(&this->mRigHandle, 0x39BC0A7Eu, mUID, rig, inventory);
}

// File Line: 94
// RVA: 0x57D790
void __fastcall UFG::CharacterAnimationComponent::~CharacterAnimationComponent(UFG::CharacterAnimationComponent *this)
{
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v2; // rdi
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *mPrev; // rcx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *mNext; // rax
  CharacterDamageRig *mDamageRig; // rsi
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v6; // rcx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v7; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterAnimationComponent::`vftable;
  if ( this == UFG::CharacterAnimationComponent::s_CharacterAnimationComponentpCurrentIterator )
    UFG::CharacterAnimationComponent::s_CharacterAnimationComponentpCurrentIterator = (UFG::CharacterAnimationComponent *)&this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mPrev[-13].mNext;
  v2 = &this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>;
  mPrev = this->UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( this->mDamageRig )
  {
    --gNumberofCharacterDamageRigsAllocated;
    gCharacterDamageRigAllocated -= 784;
    mDamageRig = this->mDamageRig;
    if ( mDamageRig )
    {
      CharacterDamageRig::~CharacterDamageRig(this->mDamageRig);
      operator delete[](mDamageRig);
    }
  }
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BaseAnimationComponent::~BaseAnimationComponent(this);
}

// File Line: 108
// RVA: 0x5863A0
void __fastcall UFG::CharacterAnimationComponent::OnAttach(
        UFG::CharacterAnimationComponent *this,
        UFG::SimObjectGame *object)
{
  Creature *mCreature; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  UFG::BaseAnimationComponent::OnAttach(this, object);
  mCreature = this->mCreature;
  if ( mCreature )
  {
    if ( object )
      m_pTransformNodeComponent = object->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    Creature::SetTransformNodeComponentRoot(mCreature, m_pTransformNodeComponent);
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      Creature::SetTransform(this->mCreature, &m_pTransformNodeComponent->mWorldTransform);
    }
    if ( object )
    {
      m_Flags = object->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = object->m_Components.p[27].m_pComponent;
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(object, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      if ( m_pComponent )
        UFG::CharacterAnimationComponent::CreateDamageRig(this);
    }
  }
}

// File Line: 129
// RVA: 0x586A90
void __fastcall UFG::CharacterAnimationComponent::OnDetach(UFG::CharacterAnimationComponent *this)
{
  Creature *mCreature; // rcx
  CharacterDamageRig *mDamageRig; // rdi

  UFG::PhysicsSystem::RemovePhysicsComponents(
    (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
    this->m_pSimObject);
  mCreature = this->mCreature;
  if ( mCreature )
  {
    Creature::DestroyAllAttachments(mCreature, this->m_pSimObject, !this->mDestroyAttachedCharacters);
    Creature::KillBlendTree(this->mCreature);
  }
  UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks(this);
  if ( this->mDamageRig )
  {
    --gNumberofCharacterDamageRigsAllocated;
    gCharacterDamageRigAllocated -= 784;
    mDamageRig = this->mDamageRig;
    if ( mDamageRig )
    {
      CharacterDamageRig::~CharacterDamageRig(this->mDamageRig);
      operator delete[](mDamageRig);
    }
    this->mDamageRig = 0i64;
  }
}

// File Line: 142
// RVA: 0x58D560
void __fastcall UFG::CharacterAnimationComponent::Update(UFG::CharacterAnimationComponent *this, float delta_sec)
{
  __int64 v3; // r8
  CharacterDamageRig *mDamageRig; // rcx
  Creature *mCreature; // rcx

  UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(this);
  mDamageRig = this->mDamageRig;
  if ( mDamageRig )
    CharacterDamageRig::Update(mDamageRig, delta_sec);
  if ( !this->mUpdatedFromNIS )
  {
    if ( !this->mUpdatedWithResources )
    {
      if ( !UFG::BaseAnimationComponent::AreResourcesAvailable(this) )
        return;
      this->mUpdatedWithResources = 1;
    }
    mCreature = this->mCreature;
    if ( mCreature && this->mRigHandle.mData )
    {
      Creature::Update(mCreature, delta_sec, v3);
      if ( this->mEnableUpdateTransforms )
        Creature::SubmitPoseTask(this->mCreature);
    }
    this->mTransformsUpdated = 0;
  }
}

// File Line: 181
// RVA: 0x591910
void __fastcall UFG::CharacterAnimationComponent::UpdateTransforms(UFG::CharacterAnimationComponent *this)
{
  Creature *mCreature; // rcx

  if ( (this->m_Flags & 3) == 1 )
  {
    mCreature = this->mCreature;
    if ( mCreature )
    {
      if ( this->mRigHandle.mData )
      {
        if ( this->mEnableUpdateTransforms )
        {
          if ( !this->mTransformsUpdated )
          {
            Creature::UpdateTransforms(mCreature);
            this->mTransformsUpdated = 1;
          }
        }
        else
        {
          Creature::WaitOnPoseTask(mCreature);
        }
      }
    }
  }
}

// File Line: 220
// RVA: 0x58A5A0
UFG::SimComponent *__fastcall UFG::CharacterAnimationComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  component_CharacterAnimation *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CharacterAnimation::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = (component_CharacterAnimation *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::CharacterAnimationComponent::CharacterAnimationComponent(
      (UFG::CharacterAnimationComponent *)v10,
      pSceneObj,
      MemImagePtr);
    v6 = v11;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v14 = 9;
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v14 = 8;
  }
  else
  {
    v14 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v15, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return v6;
}

// File Line: 238
// RVA: 0x58B320
void __fastcall UFG::CharacterAnimationComponent::Reset(UFG::CharacterAnimationComponent *this)
{
  UFG::BaseAnimationComponent::Reset(this);
  UFG::CharacterAnimationComponent::CreateDamageRig(this);
}

// File Line: 245
// RVA: 0x58C910
void __fastcall UFG::CharacterAnimationComponent::Suspend(UFG::CharacterAnimationComponent *this)
{
  Creature *mCreature; // rax
  UFG::SimObject *m_pSimObject; // rsi
  Creature *p_mNext; // rbx
  UFG::SimObject *v5; // rcx
  unsigned __int16 m_Flags; // cx

  mCreature = this->mCreature;
  m_pSimObject = this->m_pSimObject;
  p_mNext = (Creature *)&mCreature->mAttachments.mNode.mNext[-1].mNext;
  if ( p_mNext != (Creature *)&mCreature->mGroundNormal.z )
  {
    do
    {
      v5 = (UFG::SimObject *)p_mNext->mPrevMotion.m_scale.m_quad.m128_u64[1];
      if ( v5 && m_pSimObject != v5 && (v5->m_Flags & 0x2000) != 0 )
        UFG::SimObject::Suspend(v5);
      p_mNext = (Creature *)&p_mNext->m_SafePointerList.mNode.mNext[-1].mNext;
    }
    while ( p_mNext != (Creature *)&this->mCreature->mGroundNormal.z );
  }
  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0 )
    this->m_Flags = m_Flags | 2;
}

// File Line: 261
// RVA: 0x58B510
void __fastcall UFG::CharacterAnimationComponent::Restore(UFG::CharacterAnimationComponent *this)
{
  Creature *mCreature; // rax
  UFG::SimObject *m_pSimObject; // rsi
  Creature *p_mNext; // rbx
  UFG::SimObject *v5; // rcx
  unsigned __int16 m_Flags; // cx

  mCreature = this->mCreature;
  m_pSimObject = this->m_pSimObject;
  p_mNext = (Creature *)&mCreature->mAttachments.mNode.mNext[-1].mNext;
  if ( p_mNext != (Creature *)&mCreature->mGroundNormal.z )
  {
    do
    {
      v5 = (UFG::SimObject *)p_mNext->mPrevMotion.m_scale.m_quad.m128_u64[1];
      if ( v5 && m_pSimObject != v5 && (v5->m_Flags & 0x2000) != 0 )
        UFG::SimObject::Restore(v5);
      p_mNext = (Creature *)&p_mNext->m_SafePointerList.mNode.mNext[-1].mNext;
    }
    while ( p_mNext != (Creature *)&this->mCreature->mGroundNormal.z );
  }
  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) != 0 )
    this->m_Flags = m_Flags & 0xFFFD;
}

// File Line: 280
// RVA: 0x580570
void __fastcall UFG::CharacterAnimationComponent::CreateDamageRig(UFG::CharacterAnimationComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qResourceData *mData; // rax
  CharacterDamageRig *mDamageRig; // rcx
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

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( m_Flags >= 0 || !m_pSimObject->m_Components.p[32].m_pComponent )
    {
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[14].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
        }
        else
        {
          if ( (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pSimObject,
                                  UFG::CompositeDrawableComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  m_pSimObject,
                                  UFG::CompositeDrawableComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
      }
      else
      {
        m_pComponent = m_pSimObject->m_Components.p[14].m_pComponent;
      }
      mData = this->mRigHandle.mData;
      if ( mData && mData[1].mNode.mChild[0] && SLODWORD(mData[1].mNode.mChild[0][1].mChild[1]) > 20 && m_pComponent )
      {
        mDamageRig = this->mDamageRig;
        if ( mDamageRig )
        {
          CharacterDamageRig::ResetDamage(mDamageRig);
          return;
        }
        v8 = UFG::qMalloc(0x310ui64, "CharacterDamageRig", 0i64);
        v9 = 0;
        if ( v8 )
          CharacterDamageRig::CharacterDamageRig((CharacterDamageRig *)v8);
        else
          v10 = 0i64;
        this->mDamageRig = v10;
        gCharacterDamageRigAllocated += 784;
        v11 = 0i64;
        v12 = 0i64;
        v13 = 0i64;
        do
        {
          this->mDamageRig->mCharacterMarkers[v11].mBoneIndex = v9;
          v14 = *(__m128 *)(v13 + *(_QWORD *)&this->mRigHandle.mData[1].mNode.mChild[0][1].mUID);
          v15 = this->mDamageRig;
          LODWORD(v15->mCharacterMarkers[v11].mPosition.x) = v14.m128_i32[0];
          LODWORD(v15->mCharacterMarkers[v11].mPosition.y) = _mm_shuffle_ps(v14, v14, 85).m128_u32[0];
          LODWORD(v15->mCharacterMarkers[v11].mPosition.z) = _mm_shuffle_ps(v14, v14, 170).m128_u32[0];
          this->mDamageRig->mCharacterMarkers[v11].mNameUID = *(_DWORD *)(v12
                                                                        + *(_QWORD *)&this->mRigHandle.mData[1].mNode.mUID);
          this->mDamageRig->mCharacterMarkers[v11 + 1].mBoneIndex = v9 + 1;
          v16 = *(__m128 *)(*(_QWORD *)&this->mRigHandle.mData[1].mNode.mChild[0][1].mUID + v13 + 48);
          v17 = this->mDamageRig;
          LODWORD(v17->mCharacterMarkers[v11 + 1].mPosition.x) = v16.m128_i32[0];
          LODWORD(v17->mCharacterMarkers[v11 + 1].mPosition.y) = _mm_shuffle_ps(v16, v16, 85).m128_u32[0];
          LODWORD(v17->mCharacterMarkers[v11 + 1].mPosition.z) = _mm_shuffle_ps(v16, v16, 170).m128_u32[0];
          this->mDamageRig->mCharacterMarkers[v11 + 1].mNameUID = *(_DWORD *)(*(_QWORD *)&this->mRigHandle.mData[1].mNode.mUID
                                                                            + v12
                                                                            + 4);
          v9 += 2;
          v13 += 96i64;
          v12 += 8i64;
          v11 += 2i64;
        }
        while ( v9 < 0x1A );
        CharacterDamageRig::InitCharacterBoneNormals(this->mDamageRig);
      }
      ++gNumberofCharacterDamageRigsAllocated;
    }
  }
}

// File Line: 337
// RVA: 0x57F150
void __fastcall UFG::CharacterAnimationComponent::ApplyBulletDamage(
        UFG::CharacterAnimationComponent *this,
        UFG::RayCastData *bulletRay)
{
  CharacterDamageRig *mDamageRig; // rax
  float x; // xmm0_4
  float y; // xmm4_4
  __m128 x_low; // xmm3
  float v6; // xmm1_4
  float z; // xmm5_4
  float v8; // xmm0_4
  __m128 v9; // xmm2
  float v10; // xmm1_4
  Creature *mCreature; // rdx
  UFG::qVector4 v12; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector4 v13; // [rsp+40h] [rbp-38h] BYREF

  mDamageRig = this->mDamageRig;
  if ( mDamageRig )
  {
    x = bulletRay->point.x;
    y = bulletRay->normal.y;
    x_low = (__m128)LODWORD(bulletRay->normal.x);
    v13.w = 1.0;
    v9 = x_low;
    v6 = bulletRay->point.y;
    z = bulletRay->normal.z;
    v13.x = x;
    v8 = bulletRay->point.z;
    v13.y = v6;
    v13.z = v8;
    v9.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
    if ( v9.m128_f32[0] == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
    mCreature = this->mCreature;
    v12.x = (float)(x_low.m128_f32[0] * v10) * -1.0;
    v12.w = 1.0;
    v12.y = (float)(y * v10) * -1.0;
    v12.z = (float)(z * v10) * -1.0;
    CharacterDamageRig::ApplyDamageVector(mDamageRig, mCreature, &v13, &v12, 1.0, 0.0);
  }
}

// File Line: 347
// RVA: 0x57F060
void __fastcall UFG::CharacterAnimationComponent::ApplyBluntForceDamage(
        UFG::CharacterAnimationComponent *this,
        Creature *creature,
        UFG::qVector4 *hitPositionWS,
        UFG::qVector4 *invHitNormal,
        float damage)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // r10
  UFG::SimComponent *m_pComponent; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject && this->mDamageRig )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HealthComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    if ( m_pComponent )
      CharacterDamageRig::ApplyBluntForceDamageToBone(
        this->mDamageRig,
        creature,
        hitPositionWS,
        invHitNormal,
        damage,
        *((float *)&m_pComponent[1].m_SafePointerList.mNode.mNext + 1) / *(float *)&m_pComponent[1].m_NameUID);
  }
}

// File Line: 363
// RVA: 0x58BBC0
void __fastcall UFG::CharacterAnimationComponent::SetVisualDamage(
        UFG::CharacterAnimationComponent *this,
        unsigned int bone_uid,
        float damageAmount,
        float duration)
{
  CharacterDamageRig *mDamageRig; // rcx

  mDamageRig = this->mDamageRig;
  if ( mDamageRig )
    CharacterDamageRig::SetVisualDamage(mDamageRig, bone_uid, damageAmount, duration);
}

// File Line: 371
// RVA: 0x57F280
void __fastcall UFG::CharacterAnimationComponent::ApplyPaintEffect(
        UFG::CharacterAnimationComponent *this,
        bool enable,
        float r,
        float g,
        float b)
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
void __fastcall UFG::CharacterAnimationComponent::Clone(
        UFG::CharacterAnimationComponent *this,
        UFG::CharacterAnimationComponent *source)
{
  CharacterDamageRig *mDamageRig; // rcx

  mDamageRig = this->mDamageRig;
  if ( mDamageRig )
    CharacterDamageRig::Clone(mDamageRig, source->mDamageRig);
}

// File Line: 395
// RVA: 0x154D9E0
__int64 dynamic_initializer_for__UFG::CameraAnimationComponent::s_CameraAnimationComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CameraAnimationComponent::s_CameraAnimationComponentList__);
}

// File Line: 396
// RVA: 0x5829A0
const char *__fastcall UFG::CameraAnimationComponent::GetTypeName(UFG::CameraAnimationComponent *this)
{
  return "CameraAnimationComponent";
}

// File Line: 400
// RVA: 0x57C6C0
void __fastcall UFG::CameraAnimationComponent::CameraAnimationComponent(
        UFG::CameraAnimationComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_CameraAnimation *dataPtr)
{
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *mPrev; // rax

  UFG::BaseAnimationComponent::BaseAnimationComponent(this, pSceneObj, dataPtr);
  this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>::mPrev = &this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>;
  this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>::mNext = &this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraAnimationComponent::`vftable;
  mPrev = UFG::CameraAnimationComponent::s_CameraAnimationComponentList.mNode.mPrev;
  UFG::CameraAnimationComponent::s_CameraAnimationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>;
  this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>::mNext = (UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *)&UFG::CameraAnimationComponent::s_CameraAnimationComponentList;
  UFG::CameraAnimationComponent::s_CameraAnimationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CameraAnimationComponent::_CameraAnimationComponentTypeUID,
    "CameraAnimationComponent");
}

// File Line: 409
// RVA: 0x57D710
void __fastcall UFG::CameraAnimationComponent::~CameraAnimationComponent(UFG::CameraAnimationComponent *this)
{
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v2; // rdx
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *mPrev; // rcx
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *mNext; // rax
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v5; // rcx
  UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraAnimationComponent::`vftable;
  if ( this == UFG::CameraAnimationComponent::s_CameraAnimationComponentpCurrentIterator )
    UFG::CameraAnimationComponent::s_CameraAnimationComponentpCurrentIterator = (UFG::CameraAnimationComponent *)&this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>::mPrev[-13].mNext;
  v2 = &this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>;
  mPrev = this->UFG::qNode<UFG::CameraAnimationComponent,UFG::CameraAnimationComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BaseAnimationComponent::~BaseAnimationComponent(this);
}

// File Line: 415
// RVA: 0x58A4A0
UFG::CameraAnimationComponent *__fastcall UFG::CameraAnimationComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *scene_object_properties,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  component_CameraAnimation *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = scene_object_properties->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = scene_object_properties->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CameraAnimation::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = (component_CameraAnimation *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xD8ui64, "CameraAnimationComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::CameraAnimationComponent::CameraAnimationComponent(
      (UFG::CameraAnimationComponent *)v10,
      scene_object_properties,
      MemImagePtr);
    v6 = v11;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v12, scene_object_properties->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
  return (UFG::CameraAnimationComponent *)v6;
}

// File Line: 443
// RVA: 0x154DA60
__int64 dynamic_initializer_for__UFG::LightGroupComponent::s_LightGroupComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::LightGroupComponent::s_LightGroupComponentList__);
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
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->mPrev = &this->UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent>;
  this->mNext = &this->UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::LightGroupComponent::`vftable;
  this->mData = 0i64;
  this->mDisabled = 0;
  mPrev = UFG::LightGroupComponent::s_LightGroupComponentList.mNode.mPrev;
  UFG::LightGroupComponent::s_LightGroupComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *)&UFG::LightGroupComponent::s_LightGroupComponentList;
  UFG::LightGroupComponent::s_LightGroupComponentList.mNode.mPrev = &this->UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent>;
  UFG::SimComponent::AddType(this, UFG::LightGroupComponent::_LightGroupComponentTypeUID, "LightGroupComponent");
}

// File Line: 456
// RVA: 0x57DC30
void __fastcall UFG::LightGroupComponent::~LightGroupComponent(UFG::LightGroupComponent *this)
{
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v2; // rbx
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *mPrev; // rcx
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *mNext; // rax
  UFG::LightGroupData *mData; // rbp
  __int64 i; // rsi
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v7; // rcx
  UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent> *v8; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::LightGroupComponent::`vftable;
  if ( this == UFG::LightGroupComponent::s_LightGroupComponentpCurrentIterator )
    UFG::LightGroupComponent::s_LightGroupComponentpCurrentIterator = (UFG::LightGroupComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::LightGroupComponent,UFG::LightGroupComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mData = this->mData;
  if ( mData )
  {
    for ( i = 0i64; (unsigned int)i < mData->mLightCount; i = (unsigned int)(i + 1) )
      Render::DynamicLightManager::RemoveLight(&Render::gDynamicLightManager, &mData->mLightGroup[i]);
    this->mData = 0i64;
  }
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 469
// RVA: 0x582D10
UFG::LightGroupComponent *__fastcall UFG::LightGroupComponent::Init(const char *lightGroupFile)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::LightGroupComponent *v4; // rax
  UFG::LightGroupComponent *v5; // rbx

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x60ui64, "LightGroupComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::LightGroupComponent::LightGroupComponent((UFG::LightGroupComponent *)v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::LightGroupComponent::InitLights(v5, lightGroupFile);
  return v5;
}

// File Line: 500
// RVA: 0x57F730
void __fastcall UFG::LightGroupData::Clear(UFG::LightGroupData *this)
{
  __int64 i; // rdi
  UFG::qVector3 *mLightGroupColorBackup; // rcx
  Render::Light *mLightGroup; // rcx

  for ( i = 0i64; (unsigned int)i < this->mLightCount; i = (unsigned int)(i + 1) )
    Render::DynamicLightManager::RemoveLight(&Render::gDynamicLightManager, &this->mLightGroup[i]);
  mLightGroupColorBackup = this->mLightGroupColorBackup;
  this->mLightCount = 0;
  if ( mLightGroupColorBackup )
  {
    operator delete[](mLightGroupColorBackup);
    this->mLightGroupColorBackup = 0i64;
  }
  mLightGroup = this->mLightGroup;
  if ( mLightGroup )
  {
    operator delete[](mLightGroup);
    this->mLightGroup = 0i64;
  }
}

// File Line: 519
// RVA: 0x585AF0
void __fastcall UFG::LightGroupData::LoadFromXML(UFG::LightGroupData *this, const char *lightGroupFile)
{
  SimpleXML::XMLDocument *v4; // rax
  SimpleXML::XMLDocument *v5; // rsi
  SimpleXML::XMLNode *Node; // r12
  char v7; // r15
  __int64 v8; // rdi
  __int64 v9; // r14
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *v11; // rbx
  unsigned __int64 v12; // rax

  UFG::LightGroupData::Clear(this);
  v4 = SimpleXML::XMLDocument::Open(lightGroupFile, 1ui64, 0i64);
  v5 = v4;
  if ( v4 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v4, "LightGroup", 0i64);
    if ( Node )
    {
      v7 = 1;
      v8 = 0i64;
      v9 = 2i64;
      do
      {
        ChildNode = SimpleXML::XMLDocument::GetChildNode(v5, "Light", Node);
        v11 = ChildNode;
        if ( v7 )
        {
          if ( ChildNode )
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
          this->mLightGroup = (Render::Light *)UFG::qMalloc(v12, "LoadLightGroup.mLightGroup", 0i64);
          this->mLightCount = v8;
          v8 = 0i64;
        }
        else if ( ChildNode )
        {
          do
          {
            Render::ParseLightFromXML(v11, &this->mLightGroup[v8]);
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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gLightGroupDataCache__);
}

// File Line: 582
// RVA: 0x585C60
void UFG::LightGroupComponent::LoadLightGroupCache(void)
{
  UFG::qString *i; // rdi
  UFG::LightGroupData *v1; // rbx
  unsigned int v2; // eax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> v8; // [rsp+38h] [rbp-40h] BYREF
  UFG::qString result; // [rsp+48h] [rbp-30h] BYREF

  if ( once_6 )
  {
    v8.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v8;
    v8.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v8;
    UFG::ReadGenericXMLList("data\\nis\\nislightingmanifest.xml", &v8, "Manifest", "XMLFile", 0i64, 0i64);
    for ( i = (UFG::qString *)v8.mNode.mNext; i != (UFG::qString *)&v8; i = (UFG::qString *)i->mNext )
    {
      UFG::qString::GetFilenameWithoutExtension(i, &result);
      v1 = (UFG::LightGroupData *)UFG::qMalloc(0x38ui64, "LightGroupData", 0i64);
      if ( v1 )
      {
        v2 = UFG::qStringHashUpper32(result.mData, -1);
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
    for ( j = (UFG::qString *)v8.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)v8.mNode.mNext != &v8;
          j = (UFG::qString *)v8.mNode.mNext )
    {
      mPrev = j->mPrev;
      mNext = j->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      j->mPrev = j;
      j->mNext = j;
      UFG::qString::~qString(j);
      operator delete[](j);
    }
    v6 = v8.mNode.mPrev;
    v7 = v8.mNode.mNext;
    v8.mNode.mPrev->mNext = v8.mNode.mNext;
    v7->mPrev = v6;
  }
}

// File Line: 606
// RVA: 0x582A90
_BOOL8 __fastcall UFG::LightGroupComponent::GroupExists(const char *groupFilename)
{
  UFG::qString *v1; // rax
  unsigned int mStringHashUpper32; // eax
  UFG::qBaseTreeRB *v3; // rax
  bool v4; // bl
  UFG::qString result; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v7; // [rsp+50h] [rbp-38h] BYREF

  UFG::qString::qString(&v7, groupFilename);
  UFG::qString::GetFilenameWithoutExtension(v1, &result);
  UFG::qString::~qString(&v7);
  mStringHashUpper32 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(result.mData, -1);
    result.mStringHashUpper32 = mStringHashUpper32;
  }
  if ( mStringHashUpper32 )
    v3 = UFG::qBaseTreeRB::Get(&UFG::gLightGroupDataCache.mTree, mStringHashUpper32);
  else
    v3 = 0i64;
  v4 = v3 != 0i64;
  UFG::qString::~qString(&result);
  return v4;
}

// File Line: 613
// RVA: 0x5837F0
void __fastcall UFG::LightGroupComponent::InitLights(UFG::LightGroupComponent *this, const char *lightGroupFile)
{
  UFG::qString *v3; // rax
  unsigned int mStringHashUpper32; // eax
  UFG::qBaseTreeRB *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v7; // [rsp+50h] [rbp-38h] BYREF

  UFG::qString::qString(&v7, lightGroupFile);
  UFG::qString::GetFilenameWithoutExtension(v3, &result);
  UFG::qString::~qString(&v7);
  mStringHashUpper32 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(result.mData, -1);
    result.mStringHashUpper32 = mStringHashUpper32;
  }
  if ( mStringHashUpper32 )
    v5 = UFG::qBaseTreeRB::Get(&UFG::gLightGroupDataCache.mTree, mStringHashUpper32);
  else
    v5 = 0i64;
  this->mData = (UFG::LightGroupData *)v5;
  UFG::qString::~qString(&result);
}

// File Line: 622
// RVA: 0x57F380
void __fastcall UFG::LightGroupComponent::AttachLights(UFG::LightGroupComponent *this)
{
  UFG::LightGroupData *mData; // rax
  __int64 v3; // rbx
  float i; // xmm8_4
  Render::Light *v5; // rdx
  float mOnTime; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  mData = this->mData;
  if ( mData )
  {
    if ( mData->mLightGroup )
    {
      v3 = 0i64;
      for ( i = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
            (unsigned int)v3 < this->mData->mLightCount;
            v3 = (unsigned int)(v3 + 1) )
      {
        v5 = &this->mData->mLightGroup[v3];
        mOnTime = v5->mOnTime;
        v7 = v5->mOffTime - mOnTime;
        if ( v7 < 0.0 )
          v7 = v7 + 86400.0;
        v8 = i - mOnTime;
        if ( (float)(i - mOnTime) < 0.0 )
          v8 = v8 + 86400.0;
        if ( v8 <= v7 )
          UFG::DaemonManager::RegisterDaemon(
            (UFG::RoadNetworkVisibleAreaEdgeManager *)&Render::gDynamicLightManager,
            (UFG::RoadNetworkVisibleAreaEdge *)v5);
      }
    }
  }
}

// File Line: 707
// RVA: 0x154DA40
__int64 dynamic_initializer_for__UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList__);
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
void __fastcall UFG::LightGroupAnimationComponent::LightGroupAnimationComponent(
        UFG::LightGroupAnimationComponent *this,
        UFG::RigResource *rig)
{
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *mPrev; // rax

  UFG::BaseAnimationComponent::BaseAnimationComponent(this, rig);
  this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>::mPrev = &this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>;
  this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>::mNext = &this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::LightGroupAnimationComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::LightGroupComponent,0>::RebindingComponentHandle<UFG::LightGroupComponent,0>(&this->mLightGroupComponent);
  this->mLightInfo = 0i64;
  mPrev = UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList.mNode.mPrev;
  UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>;
  this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>::mNext = (UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *)&UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList;
  UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::LightGroupAnimationComponent::_LightGroupAnimationComponentTypeUID,
    "LightGroupAnimationComponent");
}

// File Line: 719
// RVA: 0x57DB90
void __fastcall UFG::LightGroupAnimationComponent::~LightGroupAnimationComponent(
        UFG::LightGroupAnimationComponent *this)
{
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v2; // rbx
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *mPrev; // rcx
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *mNext; // rax
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v5; // rcx
  UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::LightGroupAnimationComponent::`vftable;
  if ( this == UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentpCurrentIterator )
    UFG::LightGroupAnimationComponent::s_LightGroupAnimationComponentpCurrentIterator = (UFG::LightGroupAnimationComponent *)&this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>::mPrev[-13].mNext;
  v2 = &this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>;
  mPrev = this->UFG::qNode<UFG::LightGroupAnimationComponent,UFG::LightGroupAnimationComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mLightGroupComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BaseAnimationComponent::~BaseAnimationComponent(this);
}

// File Line: 726
// RVA: 0x582CB0
void __fastcall UFG::LightGroupAnimationComponent::Init(UFG::RigResource *rig)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "LightGroupAnimationComponent", 0i64, 1u);
  if ( v3 )
    UFG::LightGroupAnimationComponent::LightGroupAnimationComponent((UFG::LightGroupAnimationComponent *)v3, rig);
}

// File Line: 733
// RVA: 0x5865E0
void __fastcall UFG::LightGroupAnimationComponent::OnAttach(
        UFG::LightGroupAnimationComponent *this,
        UFG::SimObjectGame *object)
{
  UFG::RebindingComponentHandle<UFG::LightGroupComponent,0> *p_mLightGroupComponent; // rbx
  unsigned int v5; // esi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::SimComponent *m_pSimComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rbp
  unsigned int mPrev_high; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  int v16; // edx
  UFG::allocator::free_link *v17; // rcx
  UFG::LightGroupAnimationComponent::LightBoneInfo *v18; // r14
  unsigned int mNext_high; // ebx
  Creature *mCreature; // rcx
  int BoneID; // eax
  unsigned int v22; // eax
  Creature *v23; // rcx
  int v24; // eax
  unsigned int v25; // eax
  Creature *v26; // rcx
  int v27; // eax

  UFG::BaseAnimationComponent::OnAttach(this, object);
  p_mLightGroupComponent = &this->mLightGroupComponent;
  v5 = 0;
  if ( this->mLightGroupComponent.m_pSimComponent )
  {
    mPrev = p_mLightGroupComponent->mPrev;
    mNext = this->mLightGroupComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mLightGroupComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->mLightGroupComponent.m_pSimObject = 0i64;
    this->mLightGroupComponent.mNext = &this->mLightGroupComponent;
    p_mLightGroupComponent->mPrev = p_mLightGroupComponent;
    goto LABEL_8;
  }
  if ( this->mLightGroupComponent.m_pSimObject
    && (p_mLightGroupComponent->mPrev != p_mLightGroupComponent
     || this->mLightGroupComponent.mNext != &this->mLightGroupComponent) )
  {
    v8 = p_mLightGroupComponent->mPrev;
    v9 = this->mLightGroupComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  this->mLightGroupComponent.m_Changed = 1;
  this->mLightGroupComponent.m_pSimObject = object;
  this->mLightGroupComponent.m_TypeUID = UFG::LightGroupComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::LightGroupComponent,0>::BindInternal<UFG::SimObject>(
    &this->mLightGroupComponent,
    object);
  if ( this->mLightGroupComponent.m_pSimComponent )
  {
    m_pSimComponent = this->mLightGroupComponent.m_pSimComponent;
    if ( m_pSimComponent[1].m_SafePointerList.mNode.mNext )
    {
      if ( !this->mLightInfo )
      {
        v11 = m_pSimComponent[1].m_SafePointerList.mNode.mNext;
        v12 = v11[3].mPrev;
        mPrev_high = HIDWORD(v11[2].mPrev);
        v14 = 12i64 * mPrev_high;
        if ( !is_mul_ok(mPrev_high, 0xCui64) )
          v14 = -1i64;
        v15 = UFG::qMalloc(v14, "LightGroupAnimationComponent", 0i64);
        if ( v15 )
        {
          v16 = mPrev_high - 1;
          if ( (int)(mPrev_high - 1) >= 0 )
          {
            v17 = v15 + 1;
            do
            {
              v17[-1].mNext = (UFG::allocator::free_link *)-1i64;
              LODWORD(v17->mNext) = -1;
              v17 = (UFG::allocator::free_link *)((char *)v17 + 12);
              --v16;
            }
            while ( v16 >= 0 );
          }
        }
        else
        {
          v15 = 0i64;
        }
        this->mLightInfo = (UFG::LightGroupAnimationComponent::LightBoneInfo *)v15;
        if ( HIDWORD(this->mLightGroupComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext[2].mPrev) )
        {
          do
          {
            v18 = &this->mLightInfo[v5];
            mNext_high = HIDWORD(v12[10 * v5 + 7].mNext);
            mCreature = this->mCreature;
            if ( mCreature->mPose.mRigHandle.mData )
              BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, mNext_high);
            else
              BoneID = -1;
            v18->mMainBoneId = BoneID;
            v22 = UFG::qStringHashUpper32("_datapoint0", mNext_high);
            v23 = this->mCreature;
            if ( v23->mPose.mRigHandle.mData )
              v24 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v22);
            else
              v24 = -1;
            v18->mData0BoneId = v24;
            v25 = UFG::qStringHashUpper32("_datapoint1", mNext_high);
            v26 = this->mCreature;
            if ( v26->mPose.mRigHandle.mData )
              v27 = Skeleton::GetBoneID(v26->mPose.mRigHandle.mUFGSkeleton, v25);
            else
              v27 = -1;
            v18->mData1BoneId = v27;
            ++v5;
          }
          while ( v5 < HIDWORD(this->mLightGroupComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext[2].mPrev) );
        }
      }
    }
  }
}

// File Line: 761
// RVA: 0x586D60
void __fastcall UFG::LightGroupAnimationComponent::OnDetach(UFG::LightGroupAnimationComponent *this)
{
  UFG::RebindingComponentHandle<UFG::LightGroupComponent,0> *p_mLightGroupComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax

  p_mLightGroupComponent = &this->mLightGroupComponent;
  if ( this->mLightGroupComponent.m_pSimComponent )
  {
    mPrev = p_mLightGroupComponent->mPrev;
    mNext = this->mLightGroupComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mLightGroupComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mLightGroupComponent->m_pSimObject = 0i64;
    p_mLightGroupComponent->mNext = p_mLightGroupComponent;
    p_mLightGroupComponent->mPrev = p_mLightGroupComponent;
    goto LABEL_8;
  }
  if ( this->mLightGroupComponent.m_pSimObject
    && (p_mLightGroupComponent->mPrev != p_mLightGroupComponent
     || this->mLightGroupComponent.mNext != &this->mLightGroupComponent) )
  {
    v5 = p_mLightGroupComponent->mPrev;
    v6 = p_mLightGroupComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_mLightGroupComponent->m_Changed = 1;
  operator delete[](this->mLightInfo);
  this->mLightInfo = 0i64;
}

// File Line: 768
// RVA: 0x591970
void __fastcall UFG::LightGroupAnimationComponent::UpdateTransforms(UFG::LightGroupAnimationComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rbx
  unsigned int mPrev_high; // eax
  Creature *mCreature; // r14
  __int64 v7; // rdi
  __int64 v8; // r15
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **p_mNext; // rbx
  UFG::LightGroupAnimationComponent::LightBoneInfo *mLightInfo; // rbp
  int mMainBoneId; // edx
  UFG::qVector4 v12; // xmm1
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm3
  int mData0BoneId; // edx
  float y; // xmm1_4
  float z; // xmm2_4
  int mData1BoneId; // edx
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-E8h] BYREF
  UFG::qMatrix44 matrixLS; // [rsp+60h] [rbp-A8h] BYREF
  UFG::qMatrix44 v21; // [rsp+A0h] [rbp-68h] BYREF

  m_pSimComponent = this->mLightGroupComponent.m_pSimComponent;
  if ( m_pSimComponent && m_pSimComponent[1].m_SafePointerList.mNode.mNext && !LOBYTE(m_pSimComponent[1].m_TypeUID) )
  {
    if ( (this->m_Flags & 3) == 1 && !this->mTransformsUpdated )
    {
      Creature::UpdateTransforms(this->mCreature);
      this->mTransformsUpdated = 1;
    }
    mNext = this->mLightGroupComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext;
    mPrev = mNext[3].mPrev;
    if ( mPrev )
    {
      mPrev_high = HIDWORD(mNext[2].mPrev);
      mCreature = this->mCreature;
      if ( mPrev_high )
      {
        v7 = 0i64;
        v8 = mPrev_high;
        p_mNext = &mPrev[4].mNext;
        do
        {
          mLightInfo = this->mLightInfo;
          mMainBoneId = mLightInfo[v7].mMainBoneId;
          if ( *((_BYTE *)p_mNext + 50) == 0 && mMainBoneId != -1 )
          {
            Creature::GetTransform(this->mCreature, mMainBoneId, &transform);
            v12 = transform.v1;
            v13 = transform.v2;
            v14 = transform.v3;
            *(UFG::qVector4 *)(p_mNext - 9) = transform.v0;
            *(UFG::qVector4 *)(p_mNext - 7) = v12;
            *(UFG::qVector4 *)(p_mNext - 5) = v13;
            *(UFG::qVector4 *)(p_mNext - 3) = v14;
            mData0BoneId = mLightInfo[v7].mData0BoneId;
            if ( mData0BoneId != -1 )
            {
              SkeletalPose::GetPositionLS(&mCreature->mPose, mData0BoneId, &matrixLS);
              y = matrixLS.v3.y;
              z = matrixLS.v3.z;
              *((_DWORD *)p_mNext - 2) = LODWORD(matrixLS.v3.x);
              *((float *)p_mNext - 1) = y;
              *(float *)p_mNext = z;
            }
            mData1BoneId = mLightInfo[v7].mData1BoneId;
            if ( mData1BoneId != -1 )
            {
              SkeletalPose::GetPositionLS(&mCreature->mPose, mData1BoneId, &v21);
              *((_BYTE *)p_mNext + 33) = v21.v3.x < 0.5;
            }
          }
          ++v7;
          p_mNext += 20;
          --v8;
        }
        while ( v8 );
      }
    }
  }
}

