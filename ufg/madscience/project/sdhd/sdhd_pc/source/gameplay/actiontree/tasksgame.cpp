// File Line: 236
// RVA: 0x149EEB0
__int64 dynamic_initializer_for__uEffectPropertyUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("EffectProperty", -1);
  uEffectPropertyUID = result;
  return result;
}

// File Line: 258
// RVA: 0x2F3570
void __fastcall SetBittenTask::Begin(SetBittenTask *this, ActionContext *__formal)
{
  *((_BYTE *)UFG::LocalPlayerIsInCombatManager::s_pInstance + 120) ^= (*((_BYTE *)UFG::LocalPlayerIsInCombatManager::s_pInstance
                                                                       + 120) ^ (LOBYTE(this->m_Track[1].vfptr) != 0)) & 1;
}

// File Line: 263
// RVA: 0x2FA4A0
void __fastcall UpdateStatAwardWithIntegerTask::Begin(UpdateStatAwardWithIntegerTask *this, ActionContext *__formal)
{
  ITrack *m_Track; // rbx
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  m_Track = this->m_Track;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v4,
                                          (UFG::qSymbol *)&m_Track[1]);
  if ( LeaderboardDataUsingLeaderboardName )
  {
    if ( LeaderboardDataUsingLeaderboardName->mCategory == LeaderboardCategory_StatAward )
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(
        LeaderboardDataUsingLeaderboardName,
        HIDWORD(this->m_Track[1].vfptr));
  }
}

// File Line: 272
// RVA: 0x2FA450
void __fastcall UpdateStatAwardWithFloatTask::Begin(UpdateStatAwardWithFloatTask *this, ActionContext *__formal)
{
  ITrack *m_Track; // rbx
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  m_Track = this->m_Track;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v4,
                                          (UFG::qSymbol *)&m_Track[1]);
  if ( LeaderboardDataUsingLeaderboardName )
  {
    if ( LeaderboardDataUsingLeaderboardName->mCategory == LeaderboardCategory_StatAward )
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(
        LeaderboardDataUsingLeaderboardName,
        *((float *)&this->m_Track[1].vfptr + 1));
  }
}

// File Line: 281
// RVA: 0x2EE000
void __fastcall EndStatGameTask::Begin(EndStatGameTask *this, ActionContext *__formal)
{
  ITrack *m_Track; // rbx
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  m_Track = this->m_Track;
  v3 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v3,
                                          (UFG::qSymbol *)&m_Track[1]);
  if ( LeaderboardDataUsingLeaderboardName )
  {
    if ( LeaderboardDataUsingLeaderboardName->mCategory == LeaderboardCategory_StatGame )
      UFG::StatGameManager::EndStatGame(LeaderboardDataUsingLeaderboardName);
  }
}

// File Line: 290
// RVA: 0x2FA550
void __fastcall UpdateStatGameWithIntegerTask::Begin(UpdateStatGameWithIntegerTask *this, ActionContext *__formal)
{
  ITrack *m_Track; // rbx
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  m_Track = this->m_Track;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v4,
                                          (UFG::qSymbol *)&m_Track[1]);
  if ( LeaderboardDataUsingLeaderboardName )
  {
    if ( LeaderboardDataUsingLeaderboardName->mCategory == LeaderboardCategory_StatGame )
      UFG::StatGameManager::UpdateScore(
        LeaderboardDataUsingLeaderboardName,
        HIDWORD(this->m_Track[1].vfptr),
        LOBYTE(this->m_Track[1].mResourceOwner) != 0);
  }
}

// File Line: 299
// RVA: 0x2FA4F0
void __fastcall UpdateStatGameWithFloatTask::Begin(UpdateStatGameWithFloatTask *this, ActionContext *__formal)
{
  ITrack *m_Track; // rbx
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  m_Track = this->m_Track;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v4,
                                          (UFG::qSymbol *)&m_Track[1]);
  if ( LeaderboardDataUsingLeaderboardName )
  {
    if ( LeaderboardDataUsingLeaderboardName->mCategory == LeaderboardCategory_StatGame )
      UFG::StatGameManager::UpdateScore(
        LeaderboardDataUsingLeaderboardName,
        *((float *)&this->m_Track[1].vfptr + 1),
        LOBYTE(this->m_Track[1].mResourceOwner) != 0);
  }
}

// File Line: 308
// RVA: 0x2FA5A0
void __fastcall UpdateStatGameWithUpdateTimeTask::Begin(
        UpdateStatGameWithUpdateTimeTask *this,
        ActionContext *__formal)
{
  ITrack *m_Track; // rbx
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  m_Track = this->m_Track;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                          v4,
                                          (UFG::qSymbol *)&m_Track[1]);
  this->m_pLBD = LeaderboardDataUsingLeaderboardName;
  if ( LeaderboardDataUsingLeaderboardName )
  {
    if ( LeaderboardDataUsingLeaderboardName->mCategory != LeaderboardCategory_StatGame )
      this->m_pLBD = 0i64;
  }
}

// File Line: 317
// RVA: 0x30B6E0
UpdateStatGameWithUpdateTimeTask *__fastcall UpdateStatGameWithUpdateTimeTask::Update(
        UpdateStatGameWithUpdateTimeTask *this,
        float deltaTime)
{
  UFG::OSuiteLeaderboardData *m_pLBD; // rcx

  m_pLBD = this->m_pLBD;
  if ( !m_pLBD )
    return 0;
  UFG::StatGameManager::UpdateScore(m_pLBD, deltaTime, 1);
  return (UpdateStatGameWithUpdateTimeTask *)1;
}

// File Line: 352
// RVA: 0x149EE30
__int64 dynamic_initializer_for__symBip01Neck__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Neck", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symBip01Neck, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symBip01Neck__);
}

// File Line: 354
// RVA: 0x1496B50
__int64 dynamic_initializer_for__AudioAttackMaterialProperty__()
{
  AudioAttackMaterialProperty.mUID = UFG::qWiseSymbolUIDFromString("AudioAttackMaterialProperty", 0x811C9DC5);
  _((AMD_HD3D *)AudioAttackMaterialProperty.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AudioAttackMaterialProperty__);
}

// File Line: 368
// RVA: 0x2DF320
void __fastcall DoorStateTask::DoorStateTask(DoorStateTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DoorStateTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DoorStateTask::`vftable;
}

// File Line: 377
// RVA: 0x2EDE80
void __fastcall DoorStateTask::Begin(DoorStateTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  bool v4; // bl
  __int16 m_Flags; // dx
  UFG::DoorComponent *ComponentOfTypeHK; // rax

  m_Track = this->m_Track;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = LOBYTE(m_Track[1].vfptr) != 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  m_pPointer,
                                                  UFG::DoorComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::DoorComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::DoorComponent::SetOpen(ComponentOfTypeHK, v4);
  }
}

// File Line: 409
// RVA: 0x30D0F0
__int64 __fastcall findAttackMaterialUIDForAttacker(
        ActionContext *pContext,
        UFG::SimObject *pAttacker,
        const unsigned int uSourceAttackMaterialUID)
{
  UFG::SimObjectGame *Target; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v6; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  __int64 v9; // rdx
  char *Name; // rax
  unsigned int v11; // ebx
  UFG::qReflectHandleBase v13; // [rsp+28h] [rbp-30h] BYREF

  if ( uSourceAttackMaterialUID == gAttackMaterialNone.m_EnumSymbol.mUID )
    return 0i64;
  if ( uSourceAttackMaterialUID != gAttackMaterialWeaponEquipped.m_EnumSymbol.mUID )
    return uSourceAttackMaterialUID;
  if ( !pAttacker )
    return 0i64;
  Target = (UFG::SimObjectGame *)UFG::getTarget(pAttacker, eTARGET_TYPE_EQUIPPED);
  if ( !Target )
    return 0i64;
  m_Flags = Target->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::RigidBodyComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(Target, UFG::RigidBodyComponent::_TypeUID);
  v6 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0i64;
  UFG::qReflectHandleBase::qReflectHandleBase(&v13);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
  v13.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  v9 = *(_QWORD *)&v6[2].m_Flags;
  if ( v9 )
    UFG::qReflectHandleBase::operator=(&v13, (UFG::qReflectHandleBase *)(v9 + 224));
  Name = UFG::qReflectObject::GetName(v13.mData);
  v11 = UFG::qStringHashUpper32(Name, -1);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v13);
  return v11;
}

// File Line: 499
// RVA: 0x305950
char __fastcall MotionIntentionCOMTask::Update(MotionIntentionCOMTask *this, float timeDelta)
{
  Render::DebugDrawManager *Context; // rax
  UFG::SimObjectCVBase *m_pPointer; // rbx
  Render::DebugDrawContext *v5; // rsi
  UFG::CharacterAnimationComponent *v6; // rdi
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 v10; // cx
  float *mPrev; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  __int16 v14; // cx
  UFG::AICharacterControllerBaseComponent *v15; // rax
  UFG::AICharacterControllerBaseComponent *v16; // rbx
  Creature *mCreature; // rcx
  float v18; // xmm6_4
  __m128 y_low; // xmm7
  __m128 v20; // xmm1
  float v21; // xmm2_4
  UFG::qVector3 centre; // [rsp+40h] [rbp-39h] BYREF
  UFG::qVector3 p1; // [rsp+50h] [rbp-29h] BYREF
  UFG::qVector3 p0; // [rsp+5Ch] [rbp-1Dh] BYREF
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-9h] BYREF

  Context = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  v5 = (Render::DebugDrawContext *)Context;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    v10 = m_pPointer->m_Flags;
    v6 = ComponentOfTypeHK;
    if ( (v10 & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
    }
    else if ( v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
    }
  }
  else
  {
    v6 = 0i64;
    m_pComponent = 0i64;
  }
  if ( !sMoveMotionIntention || !v6 || !m_pComponent )
    return 1;
  mPrev = (float *)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
  v12 = mPrev[17];
  v13 = mPrev[18];
  centre.x = mPrev[16];
  centre.y = v12;
  centre.z = v13;
  if ( sDebugDrawCOM )
  {
    Render::DebugDrawContext::DrawSphere(
      v5,
      &centre,
      0.5,
      &UFG::qColour::ForestGreen,
      &UFG::qMatrix44::msIdentity,
      0i64);
    p1.x = centre.x;
    p1.y = centre.y;
    p1.z = centre.z - 2.0;
    Render::DebugDrawContext::DrawLine(
      v5,
      &centre,
      &p1,
      &UFG::qColour::ForestGreen,
      &UFG::qMatrix44::msIdentity,
      0i64,
      0);
  }
  if ( !m_pPointer )
    return 1;
  v14 = m_pPointer->m_Flags;
  if ( (v14 & 0x4000) != 0 || v14 < 0 )
    v15 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
  else
    v15 = (UFG::AICharacterControllerBaseComponent *)((v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AICharacterControllerBaseComponent::_TypeUID));
  v16 = v15;
  if ( !v15 )
    return 1;
  mCreature = v6->mCreature;
  if ( !mCreature )
    return 1;
  Creature::GetTransform(mCreature, 0, &transform);
  y_low = (__m128)LODWORD(centre.y);
  v18 = centre.x - transform.v3.x;
  y_low.m128_f32[0] = centre.y - transform.v3.y;
  if ( sDebugDrawCOM )
  {
    p1.x = v18 + transform.v3.x;
    p1.y = y_low.m128_f32[0] + transform.v3.y;
    p1.z = transform.v3.z;
    p0.x = transform.v3.x;
    p0.y = transform.v3.y;
    p0.z = transform.v3.z;
    Render::DebugDrawContext::DrawArrow(v5, &p0, &p1, &UFG::qColour::ForestGreen, &UFG::qMatrix44::msIdentity, 0i64);
  }
  v20 = y_low;
  v20.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v18 * v18);
  if ( _mm_sqrt_ps(v20).m128_f32[0] > sIntentionLength )
  {
    if ( v20.m128_f32[0] == 0.0 )
      v21 = 0.0;
    else
      v21 = 1.0 / _mm_sqrt_ps(v20).m128_f32[0];
    v16->m_Intention.mMotionIntentionDirection.z = v21 * 0.0;
    v16->m_Intention.mMotionIntentionDirection.x = v18 * v21;
    v16->m_Intention.mMotionIntentionDirection.y = y_low.m128_f32[0] * v21;
    v16->m_Intention.mMotionIntentionSpeed = 1.0;
    Intention::Set(&v16->m_Intention, gActionRequest_Walk.m_EnumValue, 0.0);
    v16->m_IntentionUpdated = 1;
  }
  return 1;
}

// File Line: 573
// RVA: 0x2FF250
void __fastcall UFG::OSuiteDBLogger::Init(MinimumDistanceTask *this)
{
  this->mContext = 0i64;
}

// File Line: 579
// RVA: 0x3055A0
char __fastcall MinimumDistanceTask::Update(MinimumDistanceTask *this, float timeDelta)
{
  ActionContext *mContext; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int64 v6; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __int64 vfptr_low; // rbp
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rcx
  float *m_Track; // rax
  float v18; // xmm8_4
  __m128 y_low; // xmm2
  __m128 v20; // xmm9
  float v21; // xmm10_4
  float v22; // xmm11_4
  float v23; // xmm13_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm12_4
  float v27; // xmm7_4
  float v28; // xmm8_4
  float v29; // xmm10_4
  __m128 v30; // xmm3
  float v31; // xmm8_4
  float v32; // xmm9_4
  float distanceToAdjust; // xmm11_4
  float v34; // xmm10_4
  UFG::qVector3 normalizeDistance; // [rsp+30h] [rbp-98h] BYREF

  mContext = this->mContext;
  if ( !mContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)mContext->mSimObject.m_pPointer;
  v6 = 0i64;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  vfptr_low = LODWORD(this->m_Track[1].vfptr);
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v11 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
      if ( v11 )
      {
        v13 = v11->m_Flags;
        if ( (v13 & 0x4000) != 0 )
        {
          v12 = v11->m_Components.p[20].m_pComponent;
        }
        else if ( v13 >= 0 )
        {
          v14 = (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
          v12 = v14;
        }
        else
        {
          v12 = v11->m_Components.p[20].m_pComponent;
        }
      }
      else
      {
        v12 = 0i64;
      }
      v15 = ((__int64 (__fastcall *)(UFG::SimComponent *))v12->vfptr[15].__vecDelDtor)(v12);
      if ( v15 )
      {
        v16 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v15 + 96) + vfptr_low + 8)
                        + *(_QWORD *)(v15 + 88)
                        + 40);
        if ( v16 )
          v6 = *(_QWORD *)(v16 + 88);
      }
    }
  }
  if ( !m_pTransformNodeComponent || !v6 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
  m_Track = (float *)this->m_Track;
  v18 = *(float *)(v6 + 176);
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
  v20 = (__m128)*(unsigned int *)(v6 + 180);
  v21 = *(float *)(v6 + 184);
  v22 = m_Track[15];
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v20.m128_f32[0])
                                    * (float)(y_low.m128_f32[0] - v20.m128_f32[0]))
                            + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v18)
                                    * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v18)))
                    + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v21)
                            * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v21));
  v23 = _mm_sqrt_ps(y_low).m128_f32[0];
  if ( v23 < v22 )
  {
    v24 = m_Track[16];
    v25 = 0.0;
    v26 = m_Track[17];
    if ( v24 == 0.0 || (v27 = timeDelta / v24, (float)(timeDelta / v24) > 1.0) )
      v27 = *(float *)&FLOAT_1_0;
    v28 = v18 - m_pTransformNodeComponent->mWorldTransform.v3.x;
    v20.m128_f32[0] = v20.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y;
    v29 = v21 - m_pTransformNodeComponent->mWorldTransform.v3.z;
    v30 = v20;
    v30.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v28 * v28)) + (float)(v29 * v29);
    if ( v30.m128_f32[0] != 0.0 )
      v25 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
    v31 = v28 * v25;
    v32 = v20.m128_f32[0] * v25;
    distanceToAdjust = v22 - v23;
    normalizeDistance.x = v31;
    normalizeDistance.y = v32;
    v34 = v29 * v25;
    normalizeDistance.z = v34;
    MinimumDistanceTask::AdjustDistance(
      this,
      (UFG::TransformNodeComponent *)v6,
      &normalizeDistance,
      v27 * v26,
      distanceToAdjust);
    normalizeDistance.x = v31 * -1.0;
    normalizeDistance.y = v32 * -1.0;
    normalizeDistance.z = v34 * -1.0;
    MinimumDistanceTask::AdjustDistance(
      this,
      m_pTransformNodeComponent,
      &normalizeDistance,
      (float)(1.0 - v26) * v27,
      distanceToAdjust);
  }
  return 1;
}

// File Line: 629
// RVA: 0x2E7AE0
void __fastcall MinimumDistanceTask::AdjustDistance(
        MinimumDistanceTask *this,
        UFG::TransformNodeComponent *transformNodeComponent,
        UFG::qVector3 *normalizeDistance,
        float ratio,
        float distanceToAdjust)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float x; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm6_4
  UFG::SimObjectCVBase *v23; // rcx
  __int16 v24; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rbx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-68h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)transformNodeComponent->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pSimObject->m_Components.p[27].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CharacterPhysicsComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterPhysicsComponent::_TypeUID);
    if ( m_pComponent )
    {
      if ( ratio != 0.0 && distanceToAdjust != 0.0 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(transformNodeComponent);
        y = transformNodeComponent->mWorldTransform.v0.y;
        m.v0.x = transformNodeComponent->mWorldTransform.v0.x;
        z = transformNodeComponent->mWorldTransform.v0.z;
        m.v0.y = y;
        w = transformNodeComponent->mWorldTransform.v0.w;
        m.v0.z = z;
        m.v1.x = transformNodeComponent->mWorldTransform.v1.x;
        v13 = transformNodeComponent->mWorldTransform.v1.z;
        m.v0.w = w;
        v14 = transformNodeComponent->mWorldTransform.v1.y;
        m.v1.z = v13;
        x = transformNodeComponent->mWorldTransform.v2.x;
        m.v1.y = v14;
        v16 = transformNodeComponent->mWorldTransform.v1.w;
        m.v2.x = x;
        v17 = transformNodeComponent->mWorldTransform.v2.z;
        m.v1.w = v16;
        v18 = transformNodeComponent->mWorldTransform.v2.y;
        m.v2.z = v17;
        m.v2.y = v18;
        v19 = ratio * normalizeDistance->y;
        m.v2.w = transformNodeComponent->mWorldTransform.v2.w;
        v20 = ratio * normalizeDistance->x;
        v21 = ratio * normalizeDistance->z;
        m.v3.y = (float)(v19 * distanceToAdjust) + transformNodeComponent->mWorldTransform.v3.y;
        LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
        v22 = (float)(v21 * distanceToAdjust) + transformNodeComponent->mWorldTransform.v3.z;
        m.v3.x = (float)(v20 * distanceToAdjust) + transformNodeComponent->mWorldTransform.v3.x;
        m.v3.z = v22;
        UFG::TransformNodeComponent::SetWorldTransform(transformNodeComponent, &m);
        v23 = (UFG::SimObjectCVBase *)transformNodeComponent->m_pSimObject;
        if ( v23 )
        {
          v24 = v23->m_Flags;
          if ( (v24 & 0x4000) != 0 || v24 < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v23);
          }
          else if ( (v24 & 0x2000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v23);
          }
          else if ( (v24 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v23,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v23,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
          }
          if ( ComponentOfTypeHK )
          {
            mCreature = ComponentOfTypeHK->mCreature;
            if ( mCreature )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(transformNodeComponent);
              Creature::SetTransform(mCreature, &transformNodeComponent->mWorldTransform);
            }
          }
        }
      }
    }
  }
}

// File Line: 669
// RVA: 0x2DDB00
void __fastcall AttackCollisionTask::AttackCollisionTask(AttackCollisionTask *this)
{
  UFG::SimObject **mHitDudes; // rax
  __int64 v2; // rcx

  this->Task<AttackCollisionTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AttackCollisionTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->Task<AttackCollisionTrack>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->Task<AttackCollisionTrack>::ITask::vfptr = (ITaskVtbl *)&Task<AttackCollisionTrack>::`vftable;
  this->PostAnimUpdateTask::UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>::mPrev = &this->UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>;
  this->PostAnimUpdateTask::UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>::mNext = &this->UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>;
  this->PostAnimUpdateTask::vfptr = (PostAnimUpdateTaskVtbl *)&PostAnimUpdateTask::`vftable;
  this->Task<AttackCollisionTrack>::ITask::vfptr = (ITaskVtbl *)&AttackCollisionTask::`vftable{for `Task<AttackCollisionTrack>};
  this->PostAnimUpdateTask::vfptr = (PostAnimUpdateTaskVtbl *)&AttackCollisionTask::`vftable{for `PostAnimUpdateTask};
  this->mAttackBoneIndex = -1;
  *(_DWORD *)&this->mHitPhysical = 0;
  *(_WORD *)&this->mBlockedLastFrame = 0;
  this->mHitCount = 0;
  mHitDudes = this->mHitDudes;
  v2 = 4i64;
  do
  {
    *mHitDudes = 0i64;
    mHitDudes[1] = 0i64;
    mHitDudes[2] = 0i64;
    mHitDudes += 8;
    *(mHitDudes - 5) = 0i64;
    *(mHitDudes - 4) = 0i64;
    *(mHitDudes - 3) = 0i64;
    *(mHitDudes - 2) = 0i64;
    *(mHitDudes - 1) = 0i64;
    --v2;
  }
  while ( v2 );
}

// File Line: 677
// RVA: 0x2E8C40
void __fastcall AttackCollisionTask::Begin(AttackCollisionTask *this, ActionContext *context)
{
  UFG::CharacterAnimationComponent *CharacterAnimationComponent; // rax
  Creature *mCreature; // rdi
  int BoneID; // eax
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::GameStatTracker *v12; // rax
  float Stat; // xmm0_4
  char v14; // al
  UFG::SimObjectGame *v15; // rcx
  __int16 v16; // dx
  UFG::ActionTreeComponent *v17; // rcx
  UFG::ActionTreeComponent *ComponentOfTypeHK; // rax
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h] BYREF

  this->mContext = context;
  CharacterAnimationComponent = AttackCollisionTask::GetCharacterAnimationComponent(this);
  if ( CharacterAnimationComponent )
  {
    mCreature = CharacterAnimationComponent->mCreature;
    if ( !mCreature )
      return;
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(
                 mCreature->mPose.mRigHandle.mUFGSkeleton,
                 this->m_Track[2].mMasterRate.expression.mOffset);
    else
      BoneID = -1;
    if ( BoneID < 0 )
      BoneID = 0;
    this->mAttackBoneIndex = BoneID;
    Creature::GetTransform(mCreature, BoneID, &transform);
    x = transform.v3.x;
    y = transform.v3.y;
    z = transform.v3.z;
    this->mAttackPosition0.x = transform.v3.x;
    this->mAttackPosition0.y = y;
    this->mAttackPosition0.z = z;
    this->mAttackPosition1.x = x;
    this->mAttackPosition1.y = y;
    this->mAttackPosition1.z = z;
  }
  if ( LOBYTE(this->m_Track[3].mMasterRate.text.mOffset) )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                     ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                     : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      if ( m_pComponent )
      {
        *(_QWORD *)&m_pComponent[1].m_TypeUID = 0i64;
        if ( UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
        {
          v12 = UFG::GameStatTracker::Instance();
          Stat = UFG::GameStatTracker::GetStat(v12, Berserk_Activated);
          v14 = UFG::HitReactionComponent::msBerserkAttackValidFlag;
          if ( Stat > 0.0 )
            v14 = 1;
          UFG::HitReactionComponent::msBerserkAttackValidFlag = v14;
        }
      }
    }
  }
  v15 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v15 )
  {
    v16 = v15->m_Flags;
    if ( (v16 & 0x4000) != 0 )
    {
      v17 = (UFG::ActionTreeComponent *)v15->m_Components.p[7].m_pComponent;
    }
    else if ( v16 >= 0 )
    {
      if ( (v16 & 0x2000) != 0 )
      {
        v17 = (UFG::ActionTreeComponent *)v15->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v16 & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::ActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v15,
                                                            UFG::ActionTreeComponent::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                            v15,
                                                            UFG::ActionTreeComponent::_TypeUID);
        v17 = ComponentOfTypeHK;
      }
    }
    else
    {
      v17 = (UFG::ActionTreeComponent *)v15->m_Components.p[7].m_pComponent;
    }
    if ( v17 )
      v17->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor(
        v17,
        (unsigned int)&this->PostAnimUpdateTask);
  }
}

// File Line: 755
// RVA: 0x30E1C0
void __fastcall AttackCollisionTask::setupHitRecord(
        AttackCollisionTask *this,
        UFG::HitRecord *outHitRecord,
        UFG::TransformNodeComponent *pOpponentsTransformNodeC,
        UFG::eSimObjectTypeEnum eOpponentSimObjectType,
        float fTime)
{
  UFG::SimObject *m_pPointer; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float y; // xmm2_4
  float x; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  bool v14; // r15
  int mTimeEnd_low; // edi
  float z; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  __m128 y_low; // xmm5
  float v20; // xmm1_4
  float v21; // xmm11_4
  __m128 v22; // xmm14
  float v23; // xmm15_4
  __m128 v24; // xmm2
  float v25; // xmm1_4
  float v26; // xmm13_4
  float v27; // xmm12_4
  float v28; // xmm11_4
  __m128 v29; // xmm2
  float v30; // xmm8_4
  __m128 v31; // xmm1
  float v32; // xmm1_4
  float v33; // xmm8_4
  int v34; // r14d
  UFG::SimObjectGame *m_pSimObject; // rbx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // cx
  Creature *v38; // rcx
  __int16 v39; // cx
  UFG::SimComponent *ComponentOfType; // rax
  ExpressionParameterInt *p_expression; // rcx
  int v42; // ebx
  UFG::SimObjectGame *v43; // rcx
  __int16 v44; // dx
  UFG::SimComponent *v45; // rax
  UFG::SimObjectGame *v46; // rcx
  UFG::SimComponent *v47; // rcx
  __int16 v48; // dx
  UFG::SimComponent *v49; // rax
  __int64 v50; // rax
  UFG::SimObjectProp *v51; // rcx
  __int16 v52; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v54; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mAttacker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v58; // rax
  ITrack *m_Track; // rdx
  unsigned int v60; // r14d
  __int64 v61; // rax
  unsigned int v62; // ebx
  __int64 v63; // rcx
  unsigned int v64; // eax
  int vfptr; // edx
  UFG::qVector3 vHitPosition; // [rsp+38h] [rbp-140h] BYREF
  UFG::qVector3 outBoneOffset; // [rsp+48h] [rbp-130h] BYREF
  ActionPath result; // [rsp+58h] [rbp-120h] BYREF
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-108h] BYREF
  float v70; // [rsp+180h] [rbp+8h]

  UFG::TransformNodeComponent::UpdateWorldTransform(pOpponentsTransformNodeC);
  UFG::TransformNodeComponent::UpdateWorldTransform(pOpponentsTransformNodeC);
  m_pPointer = this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = pOpponentsTransformNodeC->mWorldTransform.v0.y;
  x = pOpponentsTransformNodeC->mWorldTransform.v0.x;
  v12 = pOpponentsTransformNodeC->mWorldTransform.v3.y - m_pTransformNodeComponent->mWorldTransform.v3.y;
  v13 = pOpponentsTransformNodeC->mWorldTransform.v3.x - m_pTransformNodeComponent->mWorldTransform.v3.x;
  v14 = 0;
  mTimeEnd_low = LODWORD(this->m_Track[2].mTimeEnd);
  if ( (float)((float)(x * x) + (float)(y * y)) > 0.001
    && (float)((float)(v12 * v12) + (float)(v13 * v13)) > 0.001
    && (float)((float)((float)(y * v12) + (float)(v13 * x))
             + (float)(pOpponentsTransformNodeC->mWorldTransform.v0.z * 0.0)) > 0.0 )
  {
    if ( mTimeEnd_low )
    {
      switch ( mTimeEnd_low )
      {
        case 1:
          mTimeEnd_low = 2;
          break;
        case 2:
          mTimeEnd_low = 1;
          break;
        case 3:
          mTimeEnd_low = 0;
          break;
      }
    }
    else
    {
      mTimeEnd_low = 3;
    }
    v14 = 1;
  }
  z = this->mAttackPosition0.z;
  v17 = this->mAttackPosition1.z - z;
  v18 = this->mAttackPosition0.y;
  y_low = (__m128)LODWORD(this->mAttackPosition1.y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - v18;
  v20 = this->mAttackPosition0.x;
  v21 = this->mAttackPosition1.x - v20;
  v22 = y_low;
  v70 = (float)(v17 * fTime) + z;
  v22.m128_f32[0] = (float)(y_low.m128_f32[0] * fTime) + v18;
  v23 = (float)(v21 * fTime) + v20;
  vHitPosition.x = v23;
  vHitPosition.y = v22.m128_f32[0];
  vHitPosition.z = v70;
  v24 = y_low;
  v24.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v21 * v21)) + (float)(v17 * v17);
  if ( v24.m128_f32[0] == 0.0 )
    v25 = 0.0;
  else
    v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
  v26 = v25 * v17;
  v27 = v25 * y_low.m128_f32[0];
  v28 = v21 * v25;
  UFG::TransformNodeComponent::UpdateWorldTransform(pOpponentsTransformNodeC);
  v29 = v22;
  v29.m128_f32[0] = v22.m128_f32[0] - pOpponentsTransformNodeC->mWorldTransform.v3.y;
  v30 = v23 - pOpponentsTransformNodeC->mWorldTransform.v3.x;
  v31 = v29;
  v31.m128_f32[0] = (float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v30 * v30);
  if ( v31.m128_f32[0] == 0.0 )
    v32 = 0.0;
  else
    v32 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
  v33 = v30 * v32;
  v34 = 0;
  fTime = 0.0;
  if ( (float)(int)ExpressionParameterInt::operator long((ExpressionParameterInt *)&this->m_Track[1].mResourceOwner) > 0.0 )
  {
    AttackCollisionTask::projectHitPositionOntoSkeleton(
      this,
      &vHitPosition,
      pOpponentsTransformNodeC,
      (int *)&fTime,
      &outBoneOffset);
    v34 = LODWORD(fTime);
  }
  m_pSimObject = (UFG::SimObjectGame *)pOpponentsTransformNodeC->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[8].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v38 = *(Creature **)&m_pComponent[2].m_TypeUID;
  if ( v38 )
    Creature::GetTransform(v38, v34, &transform);
  if ( m_pSimObject
    && ((v39 = m_pSimObject->m_Flags, (v39 & 0x4000) == 0) && v39 >= 0 && (v39 & 0x2000) == 0 && (v39 & 0x1000) == 0
      ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RigidBodyComponent::_TypeUID))
      : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::RigidBodyComponent::_TypeUID)),
        ComponentOfType) )
  {
    p_expression = (ExpressionParameterInt *)&this->m_Track[1].mMasterRate.expression;
  }
  else
  {
    p_expression = (ExpressionParameterInt *)&this->m_Track[1].mResourceOwner;
  }
  v42 = ExpressionParameterInt::operator long(p_expression);
  v43 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v43 )
  {
    v44 = v43->m_Flags;
    if ( (v44 & 0x4000) != 0 )
    {
      v45 = v43->m_Components.p[20].m_pComponent;
    }
    else if ( v44 >= 0 )
    {
      v45 = (v44 & 0x2000) != 0 || (v44 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(v43, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(v43, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v45 = v43->m_Components.p[20].m_pComponent;
    }
    if ( v45 )
    {
      v46 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
      if ( v46 )
      {
        v48 = v46->m_Flags;
        if ( (v48 & 0x4000) != 0 )
        {
          v47 = v46->m_Components.p[20].m_pComponent;
        }
        else if ( v48 >= 0 )
        {
          v49 = (v48 & 0x2000) != 0 || (v48 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v46, UFG::TargetingSystemBaseComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v46, UFG::TargetingSystemBaseComponent::_TypeUID);
          v47 = v49;
        }
        else
        {
          v47 = v46->m_Components.p[20].m_pComponent;
        }
      }
      else
      {
        v47 = 0i64;
      }
      v50 = ((__int64 (__fastcall *)(UFG::SimComponent *))v47->vfptr[15].__vecDelDtor)(v47);
      if ( v50 )
      {
        v51 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v50 + 96) + 25i64)
                                     + *(_QWORD *)(v50 + 88)
                                     + 40);
        if ( v51 )
        {
          v52 = v51->m_Flags;
          if ( (v52 & 0x4000) != 0 || v52 < 0 )
            goto LABEL_77;
          if ( (v52 & 0x2000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v51);
            goto LABEL_79;
          }
          if ( (v52 & 0x1000) != 0 )
LABEL_77:
            ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             v51,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          else
            ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                             v51,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_79:
          if ( ComponentOfTypeHK )
            v42 = (int)(float)((float)v42
                             * ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mDamageMultiplier);
        }
      }
    }
  }
  if ( UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
    v42 = (int)(float)((float)v42 * (float)(UFG::PlayerBuffTracker::GetMeleeDamageMultiplier() + 1.0));
  ActionController::GetPlayingFullPath(this->mContext->mActionController, &result);
  v54 = this->mContext->mSimObject.m_pPointer;
  outHitRecord->mAttackTypeID = LODWORD(this->m_Track[2].mTimeBegin);
  outHitRecord->mDamage = v42;
  p_mAttacker = &outHitRecord->mAttacker;
  if ( outHitRecord->mAttacker.m_pPointer )
  {
    mPrev = p_mAttacker->mPrev;
    mNext = outHitRecord->mAttacker.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttacker->mPrev = p_mAttacker;
    outHitRecord->mAttacker.mNext = &outHitRecord->mAttacker;
  }
  outHitRecord->mAttacker.m_pPointer = v54;
  if ( v54 )
  {
    v58 = v54->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v58->mNext = p_mAttacker;
    p_mAttacker->mPrev = v58;
    outHitRecord->mAttacker.mNext = &v54->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v54->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mAttacker;
  }
  *(_QWORD *)&outHitRecord->mTimeSinceHit = 0i64;
  outHitRecord->mEffectBone = v34;
  outHitRecord->mEffectOffset = outBoneOffset;
  m_Track = this->m_Track;
  v60 = *((_DWORD *)&m_Track[2].mMasterRate.value + 1);
  if ( (int)audioEnum.m_enumLists.size <= 0 )
    v61 = 0i64;
  else
    v61 = *((_QWORD *)audioEnum.m_enumLists.p + 4);
  v62 = *(_DWORD *)(*(_QWORD *)(v61 + 48) + 4i64 * *(unsigned int *)&m_Track[3].mBreakPoint);
  if ( (int)gAttackCollisionEnum.m_enumLists.size <= 0 )
    v63 = 0i64;
  else
    v63 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 5);
  v64 = UFG::qStringHash32(*(const char **)(*(_QWORD *)(v63 + 16) + 8i64 * m_Track[3].m_TrackClassNameUID), 0xFFFFFFFF);
  vfptr = (int)this->m_Track[3].vfptr;
  outHitRecord->mMeleeInfo.mAttackLocationLateralID = mTimeEnd_low;
  outHitRecord->mMeleeInfo.mAttackLocationHorizontalID = vfptr;
  outHitRecord->mMeleeInfo.mAttackFromBehind = v14;
  outHitRecord->mMeleeInfo.mAttackMaterialUID = v64;
  outHitRecord->mMeleeInfo.mAudioIntensityUID = v62;
  outHitRecord->mMeleeInfo.mAttackIntensityUID = v60;
  outHitRecord->mMeleeInfo.mHitPosition.x = v23;
  LODWORD(outHitRecord->mMeleeInfo.mHitPosition.y) = v22.m128_i32[0];
  outHitRecord->mMeleeInfo.mHitPosition.z = v70;
  outHitRecord->mMeleeInfo.mHitDirection.x = v28;
  outHitRecord->mMeleeInfo.mHitDirection.y = v27;
  outHitRecord->mMeleeInfo.mHitDirection.z = v26;
  outHitRecord->mMeleeInfo.mHitNormal.x = v33;
  outHitRecord->mMeleeInfo.mHitNormal.y = v32 * v29.m128_f32[0];
  outHitRecord->mMeleeInfo.mHitNormal.z = v32 * 0.0;
  BinArray<ActionID,0>::Clone(&result.mPath, &outHitRecord->mMeleeInfo.mActionPath.mPath);
  if ( result.mPath.mCount >= 0 && result.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&result.mPath.mData + result.mPath.mData.mOffset) )
      operator delete[]((char *)&result.mPath.mData + result.mPath.mData.mOffset);
  }
}

// File Line: 893
// RVA: 0x30DDB0
char __fastcall AttackCollisionTask::projectHitPositionOntoSkeleton(
        AttackCollisionTask *this,
        UFG::qVector3 *vHitPosition,
        UFG::TransformNodeComponent *pOpponentsTransformNodeC,
        int *outBoneID,
        UFG::qVector3 *outBoneOffset)
{
  UFG::SimObjectCVBase *m_pSimObject; // rbx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::CharacterAnimationComponent *v9; // r15
  __int16 m_Flags; // cx
  bool v11; // zf
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v14; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *v16; // rsi
  float v18; // xmm6_4
  unsigned int *v19; // rbx
  int BoneID; // eax
  int v21; // edi
  __int128 x_low; // xmm4
  float y; // xmm0_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  __m128 v26; // xmm2
  float v27; // xmm0_4
  float v28; // xmm5_4
  float x; // xmm4_4
  float z; // xmm2_4
  float v31; // xmm3_4
  UFG::qVector4 hitPositionWS; // [rsp+30h] [rbp-81h] BYREF
  UFG::qVector4 invHitNormal; // [rsp+40h] [rbp-71h] BYREF
  UFG::qMatrix44 d; // [rsp+50h] [rbp-61h] BYREF
  UFG::qMatrix44 transform; // [rsp+90h] [rbp-21h] BYREF

  m_pSimObject = (UFG::SimObjectCVBase *)pOpponentsTransformNodeC->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[8].m_pComponent;
      }
      else
      {
        v11 = (m_Flags & 0x1000) == 0;
        v12 = (UFG::SimObjectGame *)pOpponentsTransformNodeC->m_pSimObject;
        if ( v11 )
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::BaseAnimationComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::BaseAnimationComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
    }
    v14 = m_pSimObject->m_Flags;
    if ( (v14 & 0x4000) != 0 || v14 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
    }
    else if ( (v14 & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pSimObject);
    }
    else if ( (v14 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pSimObject,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pSimObject,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    v9 = ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = 0i64;
    v9 = 0i64;
  }
  v16 = *(Creature **)&m_pComponent[2].m_TypeUID;
  if ( !v16 )
    return 0;
  v18 = FLOAT_3_4028235e38;
  *outBoneID = 0;
  v19 = BoneUIDs;
  do
  {
    if ( v16->mPose.mRigHandle.mData )
    {
      BoneID = Skeleton::GetBoneID(v16->mPose.mRigHandle.mUFGSkeleton, *v19);
      v21 = BoneID;
      if ( BoneID >= 0 )
      {
        Creature::GetTransform(v16, BoneID, &transform);
        if ( (float)((float)((float)((float)(transform.v3.y - vHitPosition->y)
                                   * (float)(transform.v3.y - vHitPosition->y))
                           + (float)((float)(transform.v3.x - vHitPosition->x)
                                   * (float)(transform.v3.x - vHitPosition->x)))
                   + (float)((float)(transform.v3.z - vHitPosition->z) * (float)(transform.v3.z - vHitPosition->z))) < v18 )
        {
          v18 = (float)((float)((float)(transform.v3.y - vHitPosition->y) * (float)(transform.v3.y - vHitPosition->y))
                      + (float)((float)(transform.v3.x - vHitPosition->x) * (float)(transform.v3.x - vHitPosition->x)))
              + (float)((float)(transform.v3.z - vHitPosition->z) * (float)(transform.v3.z - vHitPosition->z));
          *outBoneID = v21;
        }
      }
    }
    ++v19;
  }
  while ( (__int64)v19 < (__int64)&fDesiredDist );
  Creature::GetTransform(v16, *outBoneID, &transform);
  UFG::qInverse(&d, &transform);
  x_low = LODWORD(vHitPosition->x);
  y = vHitPosition->y;
  v24 = (float)((float)(vHitPosition->x * d.v0.x) + (float)(y * d.v1.x)) + (float)(vHitPosition->z * d.v2.x);
  v25 = (float)((float)(vHitPosition->x * d.v0.z) + (float)(y * d.v1.z)) + (float)(vHitPosition->z * d.v2.z);
  *(float *)&x_low = (float)((float)(*(float *)&x_low * d.v0.y) + (float)(y * d.v1.y))
                   + (float)(vHitPosition->z * d.v2.y);
  v26 = (__m128)x_low;
  v26.m128_f32[0] = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(v24 * v24)) + (float)(v25 * v25);
  v27 = _mm_sqrt_ps(v26).m128_f32[0];
  v28 = v24 * (float)(fDesiredDist / v27);
  *(float *)&x_low = *(float *)&x_low * (float)(fDesiredDist / v27);
  outBoneOffset->z = v25 * (float)(fDesiredDist / v27);
  outBoneOffset->x = v28;
  LODWORD(outBoneOffset->y) = x_low;
  if ( v9 )
  {
    x = vHitPosition->x;
    z = vHitPosition->z;
    hitPositionWS.w = 1.0;
    v31 = vHitPosition->y;
    invHitNormal.x = transform.v3.x - x;
    invHitNormal.y = transform.v3.y - v31;
    hitPositionWS.x = x;
    invHitNormal.z = transform.v3.z - z;
    hitPositionWS.y = v31;
    hitPositionWS.z = z;
    invHitNormal.w = 0.0;
    UFG::CharacterAnimationComponent::ApplyBluntForceDamage(v9, v16, &hitPositionWS, &invHitNormal, 1.0);
  }
  return 1;
}

// File Line: 965
// RVA: 0x30D5D0
char __fastcall AttackCollisionTask::handleHit(
        AttackCollisionTask *this,
        UFG::HitReactionComponent *opponentHitComp,
        bool foundBlocker,
        float blockDist2)
{
  UFG::SimObjectGame *m_pSimObject; // rbx
  int mHitCount; // r9d
  __int64 v9; // rcx
  UFG::SimObject **mHitDudes; // rax
  UFG::CharacterPhysicsComponent *m_pComponent; // rsi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  float y; // xmm2_4
  float z; // xmm3_4
  char v17; // si
  UFG::eSimObjectTypeEnum mNext; // r15d
  __int16 v19; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::GameStatTracker *v21; // rax
  int Faction; // eax
  UFG::eStimulusType v23; // edx
  ITrack *m_Track; // rcx
  UFG::eStimulusType value_low; // edx
  UFG::SimObject *m_pPointer; // r9
  UFG::StimulusParameters stimulus_parameters; // [rsp+40h] [rbp-88h] BYREF
  float x; // [rsp+58h] [rbp-70h]
  float v30; // [rsp+5Ch] [rbp-6Ch]
  float v31; // [rsp+60h] [rbp-68h]
  UFG::qVector3 v32; // [rsp+68h] [rbp-60h] BYREF
  __int64 v33; // [rsp+78h] [rbp-50h]
  float fTime; // [rsp+1D8h] [rbp+110h]
  char v35; // [rsp+1E8h] [rbp+120h]

  v33 = -2i64;
  m_pSimObject = (UFG::SimObjectGame *)opponentHitComp->m_pSimObject;
  mHitCount = 32;
  if ( this->mHitCount < 32 )
    mHitCount = this->mHitCount;
  v9 = 0i64;
  if ( mHitCount > 0 )
  {
    mHitDudes = this->mHitDudes;
    while ( m_pSimObject != *mHitDudes )
    {
      ++v9;
      ++mHitDudes;
      if ( v9 >= mHitCount )
        goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pSimObject->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pSimObject,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = (UFG::CharacterPhysicsComponent *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  if ( !m_pComponent )
    return 0;
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::CharacterPhysicsComponent::GetRadius(m_pComponent);
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v32.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  v32.y = y;
  v32.z = z;
  x = v32.x;
  v30 = y;
  v31 = z;
  v31 = z + UFG::CharacterPhysicsComponent::GetHeight(m_pComponent, m_pComponent->mCollisionModelType);
  v17 = UFG::SweptSphereCapsuleQuery(
          *((float *)&this->m_Track[2].mMasterRate.expression.mOffset + 1),
          &this->mAttackPosition0,
          &this->mAttackPosition1,
          &v32);
  if ( v35 )
  {
    if ( (float)((float)((float)((float)((float)(this->mAttackPosition1.y - this->mAttackPosition0.y) * fTime)
                               * (float)((float)(this->mAttackPosition1.y - this->mAttackPosition0.y) * fTime))
                       + (float)((float)((float)(this->mAttackPosition1.x - this->mAttackPosition0.x) * fTime)
                               * (float)((float)(this->mAttackPosition1.x - this->mAttackPosition0.x) * fTime)))
               + (float)((float)((float)(this->mAttackPosition1.z - this->mAttackPosition0.z) * fTime)
                       * (float)((float)(this->mAttackPosition1.z - this->mAttackPosition0.z) * fTime))) > blockDist2 )
      return 0;
  }
  if ( v17 )
  {
    this->mHitDudes[this->mHitCount++ % 32] = m_pSimObject;
    mNext = eSIM_OBJ_TYPE_INVALID;
    v19 = m_pSimObject->m_Flags;
    if ( (v19 & 0x4000) != 0 )
    {
      ComponentOfType = m_pSimObject->m_Components.p[3].m_pComponent;
    }
    else if ( v19 >= 0 )
    {
      if ( (v19 & 0x2000) != 0 )
      {
        ComponentOfType = m_pSimObject->m_Components.p[4].m_pComponent;
      }
      else if ( (v19 & 0x1000) != 0 )
      {
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                            m_pSimObject,
                            UFG::SimObjectPropertiesComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = m_pSimObject->m_Components.p[3].m_pComponent;
    }
    if ( ComponentOfType )
      mNext = (UFG::eSimObjectTypeEnum)ComponentOfType[1].m_SafePointerList.mNode.mNext;
    UFG::HitRecord::HitRecord((UFG::HitRecord *)&stimulus_parameters.m_StimulusProducerOffset.z);
    AttackCollisionTask::setupHitRecord(
      this,
      (UFG::HitRecord *)&stimulus_parameters.m_StimulusProducerOffset.z,
      m_pTransformNodeComponent,
      mNext,
      fTime);
    UFG::HitReactionComponent::HandleHitReaction(
      opponentHitComp,
      (UFG::HitRecord *)&stimulus_parameters.m_StimulusProducerOffset.z);
    if ( LOBYTE(this->m_Track[3].mMasterRate.text.mOffset) )
    {
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_MELEE_ATTACK,
        &stimulus_parameters,
        this->mContext->mSimObject.m_pPointer,
        m_pSimObject);
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_MELEE_ATTACK_NEAR_YOU,
        &stimulus_parameters,
        this->mContext->mSimObject.m_pPointer,
        eTARGET_TYPE_INVALID);
      v21 = UFG::FactionInterface::Get();
      Faction = UFG::FactionInterface::GetFaction(&v21->mFactionInterface, m_pSimObject);
      v23 = eSTIMULUS_MELEE_FIGHT_VS_INNOCENT;
      if ( Faction != 17 )
        v23 = eSTIMULUS_MELEE_FIGHT_VS_COMBATANT;
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        v23,
        &stimulus_parameters,
        this->mContext->mSimObject.m_pPointer,
        eTARGET_TYPE_INVALID);
    }
    m_Track = this->m_Track;
    if ( LODWORD(m_Track[2].mMasterRate.value) )
    {
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      value_low = LODWORD(m_Track[2].mMasterRate.value);
      m_pPointer = this->mContext->mSimObject.m_pPointer;
      if ( BYTE5(m_Track[3].mMasterRate.text.mOffset) )
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          value_low,
          &stimulus_parameters,
          m_pPointer,
          m_pSimObject);
      else
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          value_low,
          &stimulus_parameters,
          m_pPointer,
          eTARGET_TYPE_INVALID);
    }
    UFG::HitRecord::~HitRecord((UFG::HitRecord *)&stimulus_parameters.m_StimulusProducerOffset.z);
  }
  return v17;
}

// File Line: 1104
// RVA: 0x30DA50
char __fastcall AttackCollisionTask::handleIncomingAttack(
        AttackCollisionTask *this,
        UFG::eAttackPhaseEnum eAttackPhase,
        UFG::SimObjectGame *pClosePedSimObject)
{
  UFG::SimObject *m_pPointer; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::TransformNodeComponent *v8; // rdi
  signed __int16 m_Flags; // cx
  UFG::HitReactionComponent *m_pComponent; // r8
  UFG::SimComponent *v11; // rax
  ITrack *m_Track; // rcx
  int vfptr; // r9d
  int mTimeEnd_low; // r10d
  UFG::SimObject *v15; // rdx
  int mTimeBegin_low; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::IncomingAttackInfo incomingAttackInfo; // [rsp+28h] [rbp-38h] BYREF

  if ( (_S16 & 1) == 0 )
  {
    _S16 |= 1u;
    s_fMaxHorizontalDistanceSquared = FLOAT_9_0;
  }
  m_pPointer = this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  v8 = 0i64;
  if ( pClosePedSimObject )
    v8 = pClosePedSimObject->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  if ( !v8 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  if ( (float)((float)((float)((float)(v8->mWorldTransform.v3.x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                             * (float)(v8->mWorldTransform.v3.x - m_pTransformNodeComponent->mWorldTransform.v3.x))
                     + (float)((float)(v8->mWorldTransform.v3.y - m_pTransformNodeComponent->mWorldTransform.v3.y)
                             * (float)(v8->mWorldTransform.v3.y - m_pTransformNodeComponent->mWorldTransform.v3.y)))
             + (float)((float)(v8->mWorldTransform.v3.z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                     * (float)(v8->mWorldTransform.v3.z - m_pTransformNodeComponent->mWorldTransform.v3.z))) >= s_fMaxHorizontalDistanceSquared
    || !pClosePedSimObject )
  {
    return 0;
  }
  m_Flags = pClosePedSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::HitReactionComponent *)pClosePedSimObject->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v11 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(pClosePedSimObject, UFG::HitReactionComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(pClosePedSimObject, UFG::HitReactionComponent::_TypeUID);
    m_pComponent = (UFG::HitReactionComponent *)v11;
  }
  else
  {
    m_pComponent = (UFG::HitReactionComponent *)pClosePedSimObject->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  *(_QWORD *)&incomingAttackInfo.mAttackPhaseEnum = 0i64;
  incomingAttackInfo.mAttacker.mPrev = &incomingAttackInfo.mAttacker;
  incomingAttackInfo.mAttacker.mNext = &incomingAttackInfo.mAttacker;
  incomingAttackInfo.mAttacker.m_pPointer = 0i64;
  *(_QWORD *)&incomingAttackInfo.mAttackLocationLateralID = 0i64;
  incomingAttackInfo.mTimeSinceUpdated = 1000;
  m_Track = this->m_Track;
  vfptr = (int)m_Track[3].vfptr;
  mTimeEnd_low = LODWORD(m_Track[2].mTimeEnd);
  v15 = this->mContext->mSimObject.m_pPointer;
  mTimeBegin_low = LODWORD(m_Track[2].mTimeBegin);
  incomingAttackInfo.mAttackPhaseEnum = eAttackPhase;
  incomingAttackInfo.mAttackTypeID = mTimeBegin_low;
  incomingAttackInfo.mAttacker.m_pPointer = v15;
  if ( v15 )
  {
    mPrev = v15->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    mPrev->mNext = &incomingAttackInfo.mAttacker;
    incomingAttackInfo.mAttacker.mPrev = mPrev;
    incomingAttackInfo.mAttacker.mNext = &v15->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v15->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &incomingAttackInfo.mAttacker;
  }
  incomingAttackInfo.mAttackLocationLateralID = mTimeEnd_low;
  incomingAttackInfo.mAttackLocationHorizontalID = vfptr;
  incomingAttackInfo.mTimeSinceUpdated = 0;
  UFG::HitReactionComponent::HandleIncomingAttack(m_pComponent, &incomingAttackInfo);
  if ( incomingAttackInfo.mAttacker.m_pPointer )
  {
    v18 = incomingAttackInfo.mAttacker.mPrev;
    mNext = incomingAttackInfo.mAttacker.mNext;
    incomingAttackInfo.mAttacker.mPrev->mNext = incomingAttackInfo.mAttacker.mNext;
    mNext->mPrev = v18;
    incomingAttackInfo.mAttacker.mPrev = &incomingAttackInfo.mAttacker;
    incomingAttackInfo.mAttacker.mNext = &incomingAttackInfo.mAttacker;
  }
  incomingAttackInfo.mAttacker.m_pPointer = 0i64;
  v20 = incomingAttackInfo.mAttacker.mPrev;
  v21 = incomingAttackInfo.mAttacker.mNext;
  incomingAttackInfo.mAttacker.mPrev->mNext = incomingAttackInfo.mAttacker.mNext;
  v21->mPrev = v20;
  incomingAttackInfo.mAttacker.mPrev = &incomingAttackInfo.mAttacker;
  incomingAttackInfo.mAttacker.mNext = &incomingAttackInfo.mAttacker;
  return 1;
}

// File Line: 1138
// RVA: 0x30BB20
void __fastcall AttackCollisionTask::applyAttackDamage(
        AttackCollisionTask *this,
        UFG::ShapeCasterCollector *caster,
        UFG::qVector3 *startPosition,
        UFG::qVector3 *dir)
{
  Render::DebugDrawContext *Context; // r15
  __int64 v8; // rax
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v11; // rcx
  const char *TypeName; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v13; // rcx
  const char *v14; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mNext; // r14
  float v16; // xmm10_4
  bool v17; // bl
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  char v21; // si
  unsigned __int64 v22; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v23; // rcx
  const char *v24; // rax
  unsigned __int64 mPrev; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v26; // rcx
  const char *v27; // rax
  ITrack *m_Track; // rbx
  __int64 v29; // rax
  char *v30; // rcx
  int x_low; // eax
  float v32; // xmm6_4
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v36; // rcx
  UFG::SimComponent *v37; // rcx
  __int16 v38; // dx
  UFG::SimComponent *v39; // rax
  __int64 v40; // rax
  UFG::SimObjectProp *v41; // rcx
  __int16 v42; // dx
  UFG::SimObjectWeaponPropertiesComponent *v43; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v44; // rdi
  UFG::SimComponent *v45; // rdi
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObject *m_pSimObject; // rdx
  bool v48; // zf
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v49; // rcx
  const char *v50; // rax
  unsigned __int64 DnaUid; // rbx
  const char *StaticTypeName; // rax
  unsigned __int64 v53; // rax
  UFG::StateMachineComponent *vfptr; // rcx
  UFG::SimObjectGame *v55; // rcx
  UFG::VehicleEffectsComponent *v56; // rdi
  __int16 v57; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v59; // xmm1_4
  float v60; // xmm2_4
  UFG::CopSystem *v61; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v62; // r8
  __int16 v63; // cx
  UFG::HitReactionComponent *v64; // rbx
  UFG::SimComponent *v65; // rax
  UFG::SimObjectGame *v66; // rcx
  UFG::SimObject *v67; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v68; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v69; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v70; // rax
  UFG::SimObjectGame *v71; // rcx
  __int16 v72; // dx
  hkSimpleLocalFrame *v73; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *Texture; // rbx
  UFG::GameStatTracker *v76; // rax
  int Faction; // eax
  UFG::eStimulusType v78; // edx
  __int64 v79; // rcx
  unsigned int v80; // eax
  unsigned int AttackMaterialUIDForAttacker; // r12d
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v82; // rcx
  const char *v83; // rax
  unsigned int v84; // esi
  unsigned int v85; // r15d
  unsigned __int64 v86; // r8
  UFG::qReflectObject *mData; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v88; // rcx
  const char *v89; // rax
  unsigned __int64 v90; // r8
  float v91; // ebx
  UFG::SimObjectCharacter *v92; // rcx
  __int16 v93; // dx
  UFG::ActorAudioComponent *v94; // rax
  UFG::ActorAudioComponent *v95; // rdi
  unsigned int AudioIntensityUID; // r14d
  float v97; // xmm2_4
  float v98; // xmm1_4
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v99; // [rsp+48h] [rbp-80h]
  UFG::StimulusParameters stimulus_parameters; // [rsp+50h] [rbp-78h] BYREF
  float v101; // [rsp+68h] [rbp-60h]
  UFG::qVector3 centre; // [rsp+70h] [rbp-58h] BYREF
  UFG::qReflectHandleBase v103; // [rsp+80h] [rbp-48h] BYREF
  UFG::qReflectHandleBase v104; // [rsp+A8h] [rbp-20h] BYREF
  UFG::qReflectHandleBase v105; // [rsp+D0h] [rbp+8h] BYREF
  UFG::qReflectHandleBase v106; // [rsp+F8h] [rbp+30h] BYREF
  UFG::qReflectHandleBase v107; // [rsp+120h] [rbp+58h] BYREF
  UFG::qReflectHandleBase v108; // [rsp+148h] [rbp+80h] BYREF
  UFG::qReflectHandleBase v109; // [rsp+170h] [rbp+A8h] BYREF
  __int64 v110; // [rsp+198h] [rbp+D0h]
  UFG::qReflectHandleBase v111; // [rsp+1A0h] [rbp+D8h] BYREF
  UFG::HitRecord hitrecord; // [rsp+1C8h] [rbp+100h] BYREF
  char v113; // [rsp+3A0h] [rbp+2D8h]
  UFG::qVector3 *v114; // [rsp+3A8h] [rbp+2E0h]
  char v115; // [rsp+3B8h] [rbp+2F0h]
  float vars0; // [rsp+3C0h] [rbp+2F8h]
  void *retaddr; // [rsp+3C8h] [rbp+300h]

  v110 = -2i64;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  *(_QWORD *)&centre.x = Context;
  if ( gAttackCollisionDebug )
  {
    v8 = ((__int64 (__fastcall *)(hkpShapePhantom *))caster->mPhantom->vfptr[2].__first_virtual_table_function__)(caster->mPhantom);
    v9 = *(float *)(v8 + 52);
    v10 = *(float *)(v8 + 56);
    centre.x = *(float *)(v8 + 48);
    centre.y = v9;
    centre.z = v10;
    Render::DebugDrawContext::DrawSphere(
      Context,
      &centre,
      caster->mRadius,
      &UFG::qColour::Red,
      &UFG::qMatrix44::msIdentity,
      0i64);
  }
  UFG::qReflectHandleBase::qReflectHandleBase(&v103);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v11);
  v103.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::qReflectHandleBase(&v107);
  v14 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v13);
  v107.mTypeUID = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
  mNext = caster->mHitList.mNode.mNext;
  v99 = mNext;
  *(_QWORD *)&centre.x = &caster->mHitList;
  if ( mNext != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)&caster->mHitList )
  {
    v16 = vars0;
    do
    {
      v17 = 0;
      if ( v115 )
      {
        v18 = (float)((float)(*(float *)&retaddr * *((float *)&mNext[2].mPrev + 1)) + *(float *)&mNext[1].mNext)
            - startPosition->z;
        v19 = (float)((float)(*(float *)&retaddr * *(float *)&mNext[2].mPrev) + *((float *)&mNext[1].mPrev + 1))
            - startPosition->y;
        v20 = (float)((float)(*(float *)&retaddr * *((float *)&mNext[1].mNext + 1)) + *(float *)&mNext[1].mPrev)
            - startPosition->x;
        v17 = (float)((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v18 * v18)) > v16;
      }
      v21 = 0;
      if ( BYTE4(this->m_Track[3].mMasterRate.text.mOffset) )
      {
        v17 = 1;
        v22 = (unsigned __int64)mNext[5].mNext;
        if ( v22 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v108);
          v24 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v23);
          v108.mTypeUID = UFG::qStringHash64(v24, 0xFFFFFFFFFFFFFFFFui64);
          UFG::qReflectHandleBase::Init(&v108, v108.mTypeUID, v22);
          if ( v108.mData )
            v17 = LOBYTE(v108.mData[2].vfptr) == 0;
          UFG::qReflectHandleBase::~qReflectHandleBase(&v108);
        }
        mPrev = (unsigned __int64)mNext[6].mPrev;
        if ( !v17 )
        {
LABEL_19:
          m_Track = this->m_Track;
          v29 = *(_QWORD *)&m_Track[1].mMasterRate.value;
          if ( v29
            && (v30 = (char *)&m_Track[1].mMasterRate.value + v29) != 0i64
            && ((*(void (__fastcall **)(char *, UFG::StimulusParameters *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v30 + 24i64))(
                  v30,
                  &stimulus_parameters,
                  UEL::gCurrentParameters,
                  0i64,
                  UEL::gCurrentStringBuilder),
                LOWORD(stimulus_parameters.m_EmitUntilSpeedLessThan)) )
          {
            if ( LOWORD(stimulus_parameters.m_EmitUntilSpeedLessThan) == 1 )
              x_low = LODWORD(stimulus_parameters.m_StimulusProducerOffset.x);
            else
              x_low = (int)stimulus_parameters.m_StimulusProducerOffset.x;
          }
          else
          {
            x_low = LODWORD(m_Track[1].mTimeBegin);
          }
          v32 = (float)x_low * 0.0099999998;
          m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
          if ( !m_pPointer )
            goto LABEL_59;
          m_Flags = m_pPointer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                             m_pPointer,
                             UFG::TargetingSystemBaseComponent::_TypeUID)
                         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
          }
          if ( !m_pComponent )
            goto LABEL_59;
          v36 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
          if ( v36 )
          {
            v38 = v36->m_Flags;
            if ( (v38 & 0x4000) != 0 )
            {
              v37 = v36->m_Components.p[20].m_pComponent;
            }
            else if ( v38 >= 0 )
            {
              v39 = (v38 & 0x2000) != 0 || (v38 & 0x1000) != 0
                  ? UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::TargetingSystemBaseComponent::_TypeUID)
                  : UFG::SimObject::GetComponentOfType(v36, UFG::TargetingSystemBaseComponent::_TypeUID);
              v37 = v39;
            }
            else
            {
              v37 = v36->m_Components.p[20].m_pComponent;
            }
          }
          else
          {
            v37 = 0i64;
          }
          v40 = ((__int64 (__fastcall *)(UFG::SimComponent *))v37->vfptr[15].__vecDelDtor)(v37);
          if ( !v40 )
            goto LABEL_59;
          v41 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v40 + 96) + 25i64)
                                       + *(_QWORD *)(v40 + 88)
                                       + 40);
          if ( !v41 )
            goto LABEL_59;
          v42 = v41->m_Flags;
          if ( (v42 & 0x4000) == 0 && v42 >= 0 )
          {
            if ( (v42 & 0x2000) != 0 )
            {
              v43 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v41);
LABEL_57:
              if ( v43 )
                v32 = v32 * v43->mWeaponTypeInfo->mFireModes[v43->mFireMode]->mDamageMultiplier;
LABEL_59:
              v113 = 0;
              v44 = mNext[2].mNext[1].mNext;
              if ( !v21 )
              {
                if ( v44 )
                {
                  v45 = (UFG::SimComponent *)v44[1].mNext;
                  if ( v45 )
                  {
                    LocalPlayer = UFG::GetLocalPlayer();
                    m_pSimObject = v45->m_pSimObject;
                    if ( LocalPlayer == m_pSimObject
                      || (v48 = LocalPlayer == this->mContext->mSimObject.m_pPointer, v113 = 0, v48) )
                    {
                      v113 = 1;
                    }
                    if ( m_pSimObject == this->mContext->mSimObject.m_pPointer )
                      goto LABEL_167;
                    if ( UFG::SimComponent::IsType(v45, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID) )
                    {
                      UFG::qReflectHandleBase::qReflectHandleBase(&v106);
                      v50 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v49);
                      v106.mTypeUID = UFG::qStringHash64(v50, 0xFFFFFFFFFFFFFFFFui64);
                      UFG::qReflectHandleBase::Init(&v106, v106.mTypeUID, (unsigned __int64)mNext[5].mNext);
                      if ( v106.mData )
                      {
                        DnaUid = UFG::StateMachineDefinition::GetDnaUid(HIDWORD(v106.mData[4].mBaseNode.mParent));
                        UFG::qReflectHandleBase::qReflectHandleBase(&v111);
                        StaticTypeName = UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::GetStaticTypeName();
                        v53 = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
                        UFG::qReflectHandleBase::Init(&v111, v53, DnaUid);
                        if ( v111.mData )
                        {
                          if ( *((float *)&v111.mData[1].mBaseNode.mChildren[1] + 1) > 0.0 )
                          {
                            vfptr = (UFG::StateMachineComponent *)v45[6].vfptr;
                            if ( vfptr )
                              UFG::StateMachineComponent::ApplyDamage(
                                vfptr,
                                v32,
                                ATTACK_DAMAGE,
                                this->mContext->mSimObject.m_pPointer);
                          }
                        }
                        UFG::qReflectHandleBase::~qReflectHandleBase(&v111);
                      }
                      UFG::qReflectHandleBase::~qReflectHandleBase(&v106);
                    }
                  }
                }
              }
              if ( gAttackCollisionDebug )
                Render::DebugDrawContext::DrawSphere(
                  Context,
                  (UFG::qVector3 *)&mNext[1],
                  0.0099999998,
                  &UFG::qColour::Red,
                  &UFG::qMatrix44::msIdentity,
                  0i64);
              v55 = (UFG::SimObjectGame *)mNext[5].mPrev;
              if ( !v55 )
              {
                v56 = 0i64;
                goto LABEL_87;
              }
              v57 = v55->m_Flags;
              if ( (v57 & 0x4000) != 0 )
              {
LABEL_84:
                ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v55,
                                      UFG::VehicleEffectsComponent::_TypeUID);
                goto LABEL_86;
              }
              if ( v57 >= 0 )
              {
                if ( (v57 & 0x2000) != 0 || (v57 & 0x1000) != 0 )
                  goto LABEL_84;
                ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v55, UFG::VehicleEffectsComponent::_TypeUID);
LABEL_86:
                v56 = (UFG::VehicleEffectsComponent *)ComponentOfTypeHK;
              }
              else
              {
                v56 = (UFG::VehicleEffectsComponent *)v55->m_Components.p[32].m_pComponent;
              }
LABEL_87:
              if ( !v21 )
              {
                if ( v56 )
                {
                  stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
                  stimulus_parameters.m_MaxStimulusDuration = -1.0;
                  stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
                  stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
                  UFG::StimulusManager::BeginStimulus(
                    UFG::StimulusManager::s_pInstance,
                    eSTIMULUS_VEHICLE_DAMAGED_BY_MELEE,
                    &stimulus_parameters,
                    (UFG::SimObject *)mNext[5].mPrev);
                  v59 = *((float *)&mNext[1].mPrev + 1);
                  v60 = *(float *)&mNext[1].mNext;
                  stimulus_parameters.m_StimulusProducerOffset.x = *(float *)&mNext[1].mPrev;
                  stimulus_parameters.m_StimulusProducerOffset.y = v59;
                  stimulus_parameters.m_StimulusProducerOffset.z = v60;
                  UFG::VehicleEffectsComponent::MeleeBasedDamage(
                    v56,
                    &stimulus_parameters.m_StimulusProducerOffset,
                    v32 * 5.0,
                    v32);
                  v61 = UFG::CopSystem::Instance();
                  ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *))v61->vfptr[96].__vecDelDtor)(
                    v61,
                    this->mContext->mSimObject.m_pPointer,
                    mNext[5].mPrev);
                  v62 = mNext[5].mPrev;
                  if ( v62 )
                  {
                    v63 = WORD2(v62[4].mNext);
                    if ( (v63 & 0x4000) != 0 )
                    {
                      v64 = (UFG::HitReactionComponent *)v62[6].mNext[15].mPrev;
                    }
                    else if ( v63 >= 0 )
                    {
                      if ( (v63 & 0x2000) != 0 )
                      {
                        v65 = UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)mNext[5].mPrev,
                                UFG::HitReactionComponent::_TypeUID);
                      }
                      else
                      {
                        v48 = (v63 & 0x1000) == 0;
                        v66 = (UFG::SimObjectGame *)mNext[5].mPrev;
                        v65 = v48
                            ? UFG::SimObject::GetComponentOfType(v66, UFG::HitReactionComponent::_TypeUID)
                            : UFG::SimObjectGame::GetComponentOfTypeHK(v66, UFG::HitReactionComponent::_TypeUID);
                      }
                      v64 = (UFG::HitReactionComponent *)v65;
                    }
                    else
                    {
                      v64 = (UFG::HitReactionComponent *)v62[6].mNext[15].mPrev;
                    }
                    if ( v64 )
                    {
                      UFG::HitRecord::HitRecord(&hitrecord);
                      v67 = this->mContext->mSimObject.m_pPointer;
                      if ( hitrecord.mAttacker.m_pPointer )
                      {
                        v68 = hitrecord.mAttacker.mPrev;
                        v69 = hitrecord.mAttacker.mNext;
                        hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
                        v69->mPrev = v68;
                        hitrecord.mAttacker.mPrev = &hitrecord.mAttacker;
                        hitrecord.mAttacker.mNext = &hitrecord.mAttacker;
                      }
                      hitrecord.mAttacker.m_pPointer = v67;
                      if ( v67 )
                      {
                        v70 = v67->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                        v70->mNext = &hitrecord.mAttacker;
                        hitrecord.mAttacker.mPrev = v70;
                        hitrecord.mAttacker.mNext = &v67->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                        v67->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &hitrecord.mAttacker;
                      }
                      UFG::HitReactionComponent::SetHitRecord(v64, &hitrecord);
                      UFG::HitRecord::~HitRecord(&hitrecord);
                    }
                  }
                }
              }
              if ( LOBYTE(this->m_Track[3].mMasterRate.text.mOffset) )
              {
                v71 = (UFG::SimObjectGame *)mNext[5].mPrev;
                if ( v71 )
                {
                  v72 = v71->m_Flags;
                  if ( (v72 & 0x4000) != 0 )
                    goto LABEL_114;
                  if ( v72 >= 0 )
                  {
                    if ( (v72 & 0x2000) != 0 || (v72 & 0x1000) != 0 )
LABEL_114:
                      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v71,
                                          UFG::VehicleOccupantComponent::_TypeUID);
                    else
                      ComponentOfType = UFG::SimObject::GetComponentOfType(v71, UFG::VehicleOccupantComponent::_TypeUID);
                    v73 = (hkSimpleLocalFrame *)ComponentOfType;
                  }
                  else
                  {
                    v73 = (hkSimpleLocalFrame *)v71->m_Components.p[30].m_pComponent;
                  }
                  if ( v73 )
                  {
                    stimulus_parameters.m_MaxStimulusDuration = -1.0;
                    stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
                    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
                    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
                    UFG::StimulusManager::BeginStimulus(
                      UFG::StimulusManager::s_pInstance,
                      eSTIMULUS_MELEE_ATTACK_NEAR_YOU,
                      &stimulus_parameters,
                      this->mContext->mSimObject.m_pPointer,
                      eTARGET_TYPE_INVALID);
                    Texture = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v73);
                    if ( Texture )
                    {
                      v76 = UFG::FactionInterface::Get();
                      Faction = UFG::FactionInterface::GetFaction(&v76->mFactionInterface, Texture);
                      v78 = eSTIMULUS_MELEE_FIGHT_VS_INNOCENT;
                      if ( Faction != 17 )
                        v78 = eSTIMULUS_MELEE_FIGHT_VS_COMBATANT;
                      UFG::StimulusManager::BeginStimulus(
                        UFG::StimulusManager::s_pInstance,
                        v78,
                        &stimulus_parameters,
                        this->mContext->mSimObject.m_pPointer,
                        eTARGET_TYPE_INVALID);
                    }
                  }
                }
              }
              if ( (int)gAttackCollisionEnum.m_enumLists.size <= 0 )
                v79 = 0i64;
              else
                v79 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 5);
              v80 = UFG::qStringHash32(
                      *(const char **)(*(_QWORD *)(v79 + 16) + 8i64 * this->m_Track[3].m_TrackClassNameUID),
                      0xFFFFFFFF);
              AttackMaterialUIDForAttacker = findAttackMaterialUIDForAttacker(
                                               this->mContext,
                                               this->mContext->mSimObject.m_pPointer,
                                               v80);
              if ( !AttackMaterialUIDForAttacker )
                goto LABEL_167;
              UFG::qReflectHandleBase::qReflectHandleBase(&v104);
              v83 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v82);
              v104.mTypeUID = UFG::qStringHash64(v83, 0xFFFFFFFFFFFFFFFFui64);
              UFG::PhysicsPropertyManager::GetObjectProperties(
                (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v104,
                AttackMaterialUIDForAttacker,
                1);
              if ( !v104.mData )
                goto LABEL_166;
              v84 = -1;
              v85 = -1;
              v86 = (unsigned __int64)mNext[6].mPrev;
              if ( !v86 )
                goto LABEL_142;
              mData = v103.mData;
              if ( v103.mData
                || (UFG::qReflectHandleBase::Init(&v103, v103.mTypeUID, v86), (mData = v103.mData) != 0i64) )
              {
                v84 = (unsigned int)mData[1].mBaseNode.mChildren[0];
                v85 = HIDWORD(mData[1].mBaseNode.mChildren[0]);
              }
              if ( (_S17_0 & 1) == 0 )
              {
                _S17_0 |= 1u;
                glassUid = UFG::qStringHashUpper32("Glass_Vehicle", -1);
              }
              UFG::qReflectHandleBase::qReflectHandleBase(&v105);
              v89 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v88);
              v105.mTypeUID = UFG::qStringHash64(v89, 0xFFFFFFFFFFFFFFFFui64);
              UFG::qReflectHandleBase::Init(&v105, v105.mTypeUID, (unsigned __int64)mNext[6].mPrev);
              if ( v56 && v105.mData && HIDWORD(v105.mData[4].mBaseNode.mParent) == glassUid )
              {
                if ( !UFG::VehicleEffectsComponent::IsGlassBroken(v56, (UFG::qVector3 *)&mNext[1]) )
                {
                  UFG::VehicleEffectsComponent::BreakGlass(v56, (UFG::qVector3 *)&mNext[1]);
                  goto LABEL_140;
                }
                if ( !BYTE4(this->m_Track[3].mMasterRate.text.mOffset) )
                  goto LABEL_140;
                UFG::qReflectHandleBase::~qReflectHandleBase(&v105);
LABEL_166:
                UFG::qReflectHandleBase::~qReflectHandleBase(&v104);
                goto LABEL_167;
              }
LABEL_140:
              UFG::qReflectHandleBase::~qReflectHandleBase(&v105);
              if ( v84 == -1 || v85 == -1 )
              {
LABEL_142:
                v90 = (unsigned __int64)mNext[5].mNext;
                if ( v90 )
                {
                  UFG::qReflectHandleBase::Init(&v107, v107.mTypeUID, v90);
                  if ( v107.mData )
                  {
                    if ( v84 == -1 )
                      v84 = *(_DWORD *)(v107.mData[4].mBaseNode.mUID + 104);
                    if ( v85 == -1 )
                      v85 = *(_DWORD *)(v107.mData[4].mBaseNode.mUID + 108);
                  }
                }
              }
              if ( v84 != -1 )
              {
                v91 = *(float *)&UFG::PhysicsObjectProperties::GetAudioProperty(
                                   (UFG::PhysicsObjectProperties *)v104.mData,
                                   &AudioAttackMaterialProperty)->mUID;
                centre.z = v91;
                _((AMD_HD3D *)LODWORD(v91));
                if ( v91 != 0.0 )
                {
                  v92 = (UFG::SimObjectCharacter *)this->mContext->mSimObject.m_pPointer;
                  if ( v92 )
                  {
                    v93 = v92->m_Flags;
                    if ( (v93 & 0x4000) != 0 )
                      v94 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v92);
                    else
                      v94 = (UFG::ActorAudioComponent *)(v93 < 0 || (v93 & 0x2000) != 0 || (v93 & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v92,
                                                           UFG::ActorAudioComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           v92,
                                                           UFG::ActorAudioComponent::_TypeUID));
                    v95 = v94;
                    if ( v94 )
                    {
                      AudioIntensityUID = AttackCollisionTrack::GetAudioIntensityUID((AttackCollisionTrack *)this->m_Track);
                      UFG::ActorAudioComponent::PlayFightImpact(v95, LODWORD(v91), v84, AudioIntensityUID);
                      if ( v113 )
                        UFG::ActorAudioComponent::PlayFightRumble(v95, LODWORD(v91), v84, AudioIntensityUID);
                      mNext = v99;
                    }
                  }
                }
                _((AMD_HD3D *)LODWORD(v91));
              }
              if ( v85 != -1 )
              {
                v97 = this->mAttackPosition0.z - this->mAttackPosition1.z;
                v98 = this->mAttackPosition0.y - this->mAttackPosition1.y;
                stimulus_parameters.m_MaxStimulusDuration = this->mAttackPosition0.x - this->mAttackPosition1.x;
                stimulus_parameters.m_EmitUntilSpeedLessThan = v98;
                v101 = v97;
                Render::ImpactManager::HandleImpactEvent(
                  &Render::gImpactManager,
                  AttackMaterialUIDForAttacker,
                  v85,
                  (UFG::qVector3 *)&mNext[1],
                  (UFG::qVector3 *)&stimulus_parameters.m_MaxStimulusDuration,
                  (UFG::qVector3 *)((char *)&mNext[1].mNext + 4),
                  0i64,
                  0,
                  0i64);
              }
              goto LABEL_166;
            }
            if ( (v42 & 0x1000) == 0 )
            {
              v43 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                 v41,
                                                                 UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
              goto LABEL_57;
            }
          }
          v43 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v41,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          goto LABEL_57;
        }
        if ( mPrev )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v109);
          v27 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v26);
          v109.mTypeUID = UFG::qStringHash64(v27, 0xFFFFFFFFFFFFFFFFui64);
          UFG::qReflectHandleBase::Init(&v109, v109.mTypeUID, mPrev);
          if ( v103.mData && BYTE2(v103.mData[1].mBaseNode.mParent) )
          {
            v21 = 1;
            v17 = 0;
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v109);
        }
      }
      if ( !v17 )
        goto LABEL_19;
LABEL_167:
      mNext = mNext->mNext;
      v99 = mNext;
      Context = *(Render::DebugDrawContext **)&centre.x;
      startPosition = v114;
    }
    while ( mNext != *(UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> **)&centre.x );
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v107);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v103);
}

// File Line: 1428
// RVA: 0x30C890
void __fastcall AttackCollisionTask::applyWeaponDamage(AttackCollisionTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::StateMachineComponent *vfptr; // rsi
  UFG::SimObject *v11; // rbx
  float v12; // xmm0_4

  if ( !this->mIsWeaponDamageApplied )
  {
    this->mIsWeaponDamageApplied = 1;
    if ( ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&this->m_Track[2]) > 0.0 )
    {
      m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
        else
        {
          m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
        {
          v6 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent);
          if ( v6 )
          {
            v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v6 + 96) + 25i64)
                                        + *(_QWORD *)(v6 + 88)
                                        + 40);
            if ( v7 )
            {
              v8 = v7->m_Flags;
              if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
                ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
              else
                ComponentOfType = UFG::SimObject::GetComponentOfType(v7, UFG::RigidBodyComponent::_TypeUID);
              if ( ComponentOfType )
              {
                vfptr = (UFG::StateMachineComponent *)ComponentOfType[6].vfptr;
                if ( vfptr )
                {
                  v11 = this->mContext->mSimObject.m_pPointer;
                  v12 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&this->m_Track[2]);
                  UFG::StateMachineComponent::ApplyDamage(vfptr, v12, ABSOLUTE_DAMAGE, v11);
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1457
// RVA: 0x302BE0
char __fastcall AttackCollisionTask::PostAnimUpdate(AttackCollisionTask *this, float timeDelta)
{
  __int64 v3; // rdx
  float v4; // xmm6_4
  float v5; // xmm0_4
  bool v6; // r15
  bool v7; // r12
  __int64 v8; // r13
  UFG::SimObjectGame *v9; // rcx
  char *v10; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v14; // r14
  bool v15; // si
  __int64 v16; // r15
  UFG::TransformNodeComponent *v17; // r15
  float y; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  UFG::eAttackPhaseEnum v21; // r12d
  UFG::CharacterAnimationComponent *CharacterAnimationComponent; // rax
  float *v23; // rsi
  int v24; // xmm1_4
  int v25; // xmm2_4
  int m_TimeBegin_low; // edx
  float v27; // xmm9_4
  float v28; // xmm10_4
  float v29; // xmm11_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  __m128 v32; // xmm1
  float v33; // xmm8_4
  UFG::allocator::free_link *v34; // rax
  UFG::ShapeCasterCollector *v35; // rax
  UFG::ShapeCasterCollector *v36; // r12
  __int64 v37; // rcx
  UFG::TransformNodeComponent *v38; // r15
  UFG::allocator::free_link *v39; // rax
  UFG::ShapeCasterCollector *v40; // rax
  bool v41; // al
  int v42; // ecx
  _BYTE *v43; // rax
  bool v44; // zf
  __int64 v45; // rax
  UFG::SimObjectGame *v46; // rcx
  __int16 v47; // dx
  UFG::HitReactionComponent *v48; // rax
  AttackCollisionTask *v49; // r14
  char v50; // si
  __int64 v51; // rcx
  __int64 v52; // rax
  __int64 v53; // rax
  unsigned int v54; // r13d
  unsigned int v55; // r15d
  UFG::SimObjectGame **v56; // rsi
  char v57; // di
  UFG::SimObjectGame *v58; // rcx
  __int16 v59; // dx
  UFG::HitReactionComponent *ComponentOfType; // rax
  _QWORD *v61; // rax
  __int64 v62; // rax
  ActionNode *v63; // rdx
  UFG::SimObjectCVBase *v64; // rcx
  __int16 v65; // dx
  UFG::TargetingSystemPedBaseComponent *v66; // rax
  unsigned int size; // r14d
  UFG::SimObject **p_m_pPointer; // rsi
  UFG::CharacterAnimationComponent *v69; // rax
  int v70; // xmm2_4
  int v71; // xmm1_4
  float x; // xmm0_4
  UFG::SimObjectGame *v73; // rcx
  __int16 v74; // dx
  UFG::SimComponent *v75; // rax
  UFG::qVector3 rayStart; // [rsp+40h] [rbp-88h] BYREF
  UFG::qVector3 rayEnd; // [rsp+50h] [rbp-78h] BYREF
  __int64 v79; // [rsp+60h] [rbp-68h]
  int v80; // [rsp+68h] [rbp-60h]
  int v81; // [rsp+6Ch] [rbp-5Ch]
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-58h] BYREF
  int v83; // [rsp+B8h] [rbp-10h]
  int v84; // [rsp+BCh] [rbp-Ch]
  int v85; // [rsp+C8h] [rbp+0h]
  int v86; // [rsp+E8h] [rbp+20h]
  __int64 v87; // [rsp+F8h] [rbp+30h]
  const char *v88; // [rsp+108h] [rbp+40h]
  int v89; // [rsp+110h] [rbp+48h]
  char v90; // [rsp+1F8h] [rbp+130h]
  int v91; // [rsp+208h] [rbp+140h]
  __int64 v92; // [rsp+210h] [rbp+148h]

  v79 = -2i64;
  v90 = 0;
  v3 = *(_QWORD *)&this[-1].mAttackPosition0.z;
  v4 = *(float *)(v3 + 136);
  v5 = *(float *)(v3 + 140);
  v6 = v4 >= 0.0 && v4 <= *(float *)(this->m_Track->mMasterRate.expression.mOffset + 32);
  v7 = v5 >= 0.0 && v5 <= *(float *)(this->m_Track->mMasterRate.expression.mOffset + 32);
  v8 = *(unsigned int *)(v3 + 172);
  v9 = *(UFG::SimObjectGame **)&this->m_Track->m_TrackClassNameUID;
  v10 = 0i64;
  if ( v9
    && ((m_Flags = v9->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = v9->m_Components.p[20].m_pComponent))
      : (m_pComponent = v9->m_Components.p[20].m_pComponent),
        m_pComponent) )
  {
    v14 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent);
  }
  else
  {
    v14 = 0i64;
  }
  v15 = 0;
  if ( v6 )
  {
    v16 = *(_QWORD *)&this->m_Track->m_TrackClassNameUID;
    if ( v16 )
    {
      v17 = *(UFG::TransformNodeComponent **)(v16 + 88);
      if ( v17 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v17);
        y = v17->mWorldTransform.v3.y;
        rayStart.x = v17->mWorldTransform.v3.x;
        rayStart.y = y;
        v19 = *((float *)&this->mHitDudes[28] + 1);
        v20 = *(float *)&this->mHitDudes[29];
        rayEnd.x = *(float *)&this->mHitDudes[28];
        rayEnd.y = v19;
        rayEnd.z = v20;
        rayStart.z = v20;
        LOBYTE(transform.v2.z) = 0;
        transform.v2.w = 0.0;
        *(_QWORD *)&transform.v3.x = 0i64;
        v83 = (int)FLOAT_1_0;
        v84 = -1;
        v86 = 0;
        v85 = -1;
        v87 = 0i64;
        v88 = "AttackCollisionTask";
        v89 = -1;
        UFG::RayCastData::Init((UFG::RayCastData *)&transform.v0.z, &rayStart, &rayEnd, 0x10u);
        v15 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, (UFG::RayCastData *)&transform.v0.z) != 0;
      }
    }
    if ( !v7 && !v15 )
    {
      v21 = eATTACK_PHASE_COLLISION;
      CharacterAnimationComponent = AttackCollisionTask::GetCharacterAnimationComponent((AttackCollisionTask *)((char *)this - 40));
      if ( !CharacterAnimationComponent )
        goto LABEL_118;
      v23 = (float *)&this->mHitDudes[29] + 1;
      v24 = (int)this->mHitDudes[30];
      v25 = HIDWORD(this->mHitDudes[30]);
      LODWORD(this->mHitDudes[28]) = HIDWORD(this->mHitDudes[29]);
      HIDWORD(this->mHitDudes[28]) = v24;
      LODWORD(this->mHitDudes[29]) = v25;
      m_TimeBegin_low = LODWORD(this->m_TimeBegin);
      if ( m_TimeBegin_low != -1 )
      {
        Creature::GetTransform(CharacterAnimationComponent->mCreature, m_TimeBegin_low, &transform);
        *(_DWORD *)v23 = v80;
        LODWORD(this->mHitDudes[30]) = v81;
        HIDWORD(this->mHitDudes[30]) = LODWORD(transform.v0.x);
      }
      v27 = 0.0;
      v28 = 0.0;
      v29 = 0.0;
      LOBYTE(v91) = 0;
      v30 = *(float *)(*(_QWORD *)&this[-1].mAttackPosition0.z + 148i64);
      v31 = *((float *)&this->mHitDudes[28] + 1) - *(float *)&this->mHitDudes[30];
      v32 = (__m128)LODWORD(this->mHitDudes[28]);
      v32.m128_f32[0] = (float)((float)((float)(v32.m128_f32[0] - *v23) * (float)(v32.m128_f32[0] - *v23))
                              + (float)(v31 * v31))
                      + (float)((float)(*(float *)&this->mHitDudes[29] - *((float *)&this->mHitDudes[30] + 1))
                              * (float)(*(float *)&this->mHitDudes[29] - *((float *)&this->mHitDudes[30] + 1)));
      if ( notMovingHackDist <= _mm_sqrt_ps(v32).m128_f32[0] )
      {
        v39 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
        v92 = (__int64)v39;
        if ( v39 )
        {
          UFG::ShapeCasterCollector::ShapeCasterCollector(
            (UFG::ShapeCasterCollector *)v39,
            v30,
            0x10u,
            PhantomBehaviour_Simple);
          v36 = v40;
        }
        else
        {
          v36 = 0i64;
        }
        v41 = UFG::BasePhysicsSystem::CastShape(
                UFG::BasePhysicsSystem::mInstance,
                v36,
                (UFG::qVector3 *)&this->mHitDudes[28],
                (UFG::qVector3 *)((char *)&this->mHitDudes[29] + 4));
        v42 = (unsigned __int8)v91;
        if ( v41 )
          v42 = 1;
        v91 = v42;
      }
      else
      {
        v33 = *(float *)(*(_QWORD *)&this[-1].mAttackPosition0.z + 148i64) * 0.5;
        v34 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
        v92 = (__int64)v34;
        if ( v34 )
        {
          UFG::ShapeCasterCollector::ShapeCasterCollector(
            (UFG::ShapeCasterCollector *)v34,
            v33,
            0x10u,
            PhantomBehaviour_Simple);
          v36 = v35;
        }
        else
        {
          v36 = 0i64;
        }
        v37 = *(_QWORD *)&this->m_Track->m_TrackClassNameUID;
        v38 = 0i64;
        if ( v37 )
          v38 = *(UFG::TransformNodeComponent **)(v37 + 88);
        UFG::TransformNodeComponent::UpdateWorldTransform(v38);
        v27 = v30 * v38->mWorldTransform.v0.x;
        v28 = v30 * v38->mWorldTransform.v0.y;
        v29 = v30 * v38->mWorldTransform.v0.z;
        rayStart.x = v27 + *v23;
        rayStart.y = v28 + *(float *)&this->mHitDudes[30];
        rayStart.z = v29 + *((float *)&this->mHitDudes[30] + 1);
        rayEnd.x = *(float *)&this->mHitDudes[28] - v27;
        rayEnd.y = *((float *)&this->mHitDudes[28] + 1) - v28;
        rayEnd.z = *(float *)&this->mHitDudes[29] - v29;
        if ( UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, v36, &rayEnd, &rayStart) )
          LOBYTE(v91) = 1;
      }
      v43 = *(_BYTE **)&this[-1].mAttackPosition0.z;
      if ( !v43[196] && v14 && (!BYTE2(this->m_TimeEnd) || !v43[195]) )
      {
        v44 = v43[193] == 0;
        v45 = *(_QWORD *)(v14 + 96);
        if ( v44 )
        {
          v51 = 56i64 * *(unsigned __int8 *)(v45 + 31);
          v52 = *(_QWORD *)(v14 + 88);
          if ( *(_QWORD *)(v51 + v52 + 40) && *(_BYTE *)(v51 + v52 + 49) )
            v53 = *(_QWORD *)(v51 + v52 + 40);
          else
            v53 = 0i64;
          v92 = v53;
          v54 = *(_DWORD *)(v14 + 584);
          v55 = 0;
          if ( v54 )
          {
            v56 = (UFG::SimObjectGame **)(v14 + 608);
            v57 = 0;
            v49 = (AttackCollisionTask *)((char *)this - 40);
            while ( 1 )
            {
              v58 = *v56;
              if ( *v56 != (UFG::SimObjectGame *)v53 && v58 )
              {
                v59 = v58->m_Flags;
                if ( (v59 & 0x4000) != 0 )
                {
                  ComponentOfType = (UFG::HitReactionComponent *)v58->m_Components.p[15].m_pComponent;
                }
                else if ( v59 >= 0 )
                {
                  if ( (v59 & 0x2000) != 0 || (v59 & 0x1000) != 0 )
                    ComponentOfType = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v58,
                                                                     UFG::HitReactionComponent::_TypeUID);
                  else
                    ComponentOfType = (UFG::HitReactionComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v58,
                                                                     UFG::HitReactionComponent::_TypeUID);
                }
                else
                {
                  ComponentOfType = (UFG::HitReactionComponent *)v58->m_Components.p[15].m_pComponent;
                }
                if ( ComponentOfType )
                {
                  v57 |= AttackCollisionTask::handleHit(
                           (AttackCollisionTask *)((char *)this - 40),
                           ComponentOfType,
                           0,
                           100000000.0);
                  v90 = v57;
                  if ( v57 )
                  {
                    if ( *(_BYTE *)(*(_QWORD *)&this[-1].mAttackPosition0.z + 195i64) )
                    {
LABEL_82:
                      v10 = 0i64;
                      v50 = v90;
                      goto LABEL_85;
                    }
                  }
                }
                v53 = v92;
              }
              ++v55;
              v56 += 3;
              if ( v55 >= v54 )
                goto LABEL_82;
            }
          }
        }
        else
        {
          v46 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v45 + v8 + 8) + *(_QWORD *)(v14 + 88) + 40);
          if ( v46 )
          {
            v47 = v46->m_Flags;
            if ( (v47 & 0x4000) != 0 )
            {
              v48 = (UFG::HitReactionComponent *)v46->m_Components.p[15].m_pComponent;
            }
            else if ( v47 >= 0 )
            {
              if ( (v47 & 0x2000) != 0 || (v47 & 0x1000) != 0 )
                v48 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v46,
                                                     UFG::HitReactionComponent::_TypeUID);
              else
                v48 = (UFG::HitReactionComponent *)UFG::SimObject::GetComponentOfType(
                                                     v46,
                                                     UFG::HitReactionComponent::_TypeUID);
            }
            else
            {
              v48 = (UFG::HitReactionComponent *)v46->m_Components.p[15].m_pComponent;
            }
            v49 = (AttackCollisionTask *)((char *)this - 40);
            if ( v48 )
            {
              v50 = AttackCollisionTask::handleHit((AttackCollisionTask *)((char *)this - 40), v48, 0, 100000000.0);
              goto LABEL_85;
            }
            goto LABEL_84;
          }
        }
      }
      v49 = (AttackCollisionTask *)((char *)this - 40);
LABEL_84:
      v50 = 0;
LABEL_85:
      if ( *(_BYTE *)(*(_QWORD *)&this[-1].mAttackPosition0.z + 194i64) )
      {
        if ( LOBYTE(this->m_TimeEnd) )
          goto LABEL_90;
        LOBYTE(this->m_TimeEnd) = v91;
        rayStart.x = *(float *)&this->mHitDudes[28] - v27;
        rayStart.y = *((float *)&this->mHitDudes[28] + 1) - v28;
        rayStart.z = *(float *)&this->mHitDudes[29] - v29;
        AttackCollisionTask::applyAttackDamage(v49, v36, &rayStart, &rayEnd);
      }
      if ( !LOBYTE(this->m_TimeEnd) && !v50 )
      {
LABEL_97:
        if ( v36 )
          v36->vfptr->__vecDelDtor(v36, 1u);
        v21 = eATTACK_PHASE_COLLISION;
        goto LABEL_118;
      }
LABEL_90:
      BYTE2(this->m_TimeEnd) = 1;
      AttackCollisionTask::applyWeaponDamage(v49);
      if ( v50 && !HIBYTE(this->m_TimeEnd) )
      {
        v61 = (_QWORD *)(*(_QWORD *)&this[-1].mAttackPosition0.z + 56i64);
        if ( *v61 )
          v10 = (char *)v61 + *v61;
        v62 = *((_QWORD *)v10 + 9);
        if ( v62 )
        {
          v63 = (ActionNode *)&v10[v62 + 72];
          if ( v63 )
          {
            ActionController::PlayTracks((ActionController *)this->m_Track->mMasterRate.expression.mOffset, v63, 0, 0.0);
            HIBYTE(this->m_TimeEnd) = 1;
          }
        }
      }
      goto LABEL_97;
    }
  }
  if ( v4 < 0.0 || (v21 = eATTACK_PHASE_EXECUTION, v4 <= *(float *)(this->m_Track->mMasterRate.expression.mOffset + 32)) )
    v21 = eATTACK_PHASE_RECOVERY;
  v64 = *(UFG::SimObjectCVBase **)&this->m_Track->m_TrackClassNameUID;
  if ( v64 )
  {
    v65 = v64->m_Flags;
    if ( (v65 & 0x4000) != 0 || v65 < 0 )
      v66 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v64);
    else
      v66 = (UFG::TargetingSystemPedBaseComponent *)((v65 & 0x2000) != 0 || (v65 & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v64,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       v64,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID));
    if ( v66 )
    {
      size = v66->m_CachedPedsList.size;
      if ( size )
      {
        p_m_pPointer = &v66->m_CachedPedsList.p[0].m_pPointer;
        do
        {
          if ( !AttackCollisionTask::handleIncomingAttack(
                  (AttackCollisionTask *)((char *)this - 40),
                  v21,
                  *p_m_pPointer) )
            break;
          LODWORD(v10) = (_DWORD)v10 + 1;
          p_m_pPointer += 3;
        }
        while ( (unsigned int)v10 < size );
      }
    }
  }
  v69 = AttackCollisionTask::GetCharacterAnimationComponent((AttackCollisionTask *)((char *)this - 40));
  if ( v69 )
  {
    Creature::GetTransform(v69->mCreature, LODWORD(this->m_TimeBegin), &transform);
    v70 = v80;
    LODWORD(this->mHitDudes[28]) = v80;
    v71 = v81;
    HIDWORD(this->mHitDudes[28]) = v81;
    x = transform.v0.x;
    *(float *)&this->mHitDudes[29] = transform.v0.x;
    HIDWORD(this->mHitDudes[29]) = v70;
    LODWORD(this->mHitDudes[30]) = v71;
    *((float *)&this->mHitDudes[30] + 1) = x;
  }
LABEL_118:
  v73 = *(UFG::SimObjectGame **)&this->m_Track->m_TrackClassNameUID;
  if ( v73 )
  {
    v74 = v73->m_Flags;
    if ( (v74 & 0x4000) != 0 )
    {
      v75 = v73->m_Components.p[15].m_pComponent;
    }
    else if ( v74 >= 0 )
    {
      if ( (v74 & 0x2000) != 0 || (v74 & 0x1000) != 0 )
        v75 = UFG::SimObjectGame::GetComponentOfTypeHK(v73, UFG::HitReactionComponent::_TypeUID);
      else
        v75 = UFG::SimObject::GetComponentOfType(v73, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      v75 = v73->m_Components.p[15].m_pComponent;
    }
    if ( v75 )
      v75[1].m_NameUID = v21;
  }
  return 1;
}

// File Line: 1755
// RVA: 0x2FDE10
void __fastcall AttackCollisionTask::End(AttackCollisionTask *this)
{
  UFG::SimObject *m_pPointer; // r9
  bool v3; // al
  UFG::SimObjectGame *v4; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *mPrev; // rcx
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *mNext; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h] BYREF

  m_pPointer = this->mContext->mSimObject.m_pPointer;
  v3 = m_pPointer && (m_pPointer->m_Flags & 2) != 0;
  if ( !this->mHasHitAnyTarget && !v3 && LODWORD(this->m_Track[2].mMasterRate.value) != 43 )
  {
    stimulus_parameters.m_MaxStimulusDuration = -1.0;
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
    UFG::StimulusManager::BeginStimulus(
      UFG::StimulusManager::s_pInstance,
      eSTIMULUS_MELEE_ATTACK_NO_HIT,
      &stimulus_parameters,
      m_pPointer,
      eTARGET_TYPE_INVALID);
  }
  v4 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v4 )
  {
    m_Flags = v4->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v4->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HitReactionComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(v4, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = v4->m_Components.p[15].m_pComponent;
    }
    if ( m_pComponent )
      m_pComponent[1].m_NameUID = 0;
  }
  mPrev = this->PostAnimUpdateTask::UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>::mPrev;
  mNext = this->PostAnimUpdateTask::UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->PostAnimUpdateTask::UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>::mPrev = &this->UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>;
  this->PostAnimUpdateTask::UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>::mNext = &this->UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList>;
}

// File Line: 1778
// RVA: 0x301D00
UFG::CharacterAnimationComponent *__fastcall AttackCollisionTask::GetCharacterAnimationComponent(
        AttackCollisionTask *this)
{
  ITrack *m_Track; // rax
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  __int16 v6; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v8; // rax
  __int64 v9; // rax

  m_Track = this->m_Track;
  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( !LODWORD(m_Track[3].mResourceOwner) )
  {
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        return UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      goto LABEL_5;
    }
    return 0i64;
  }
  if ( !m_pPointer )
    return 0i64;
  v6 = m_pPointer->m_Flags;
  if ( (v6 & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( v6 >= 0 )
  {
    v8 = (v6 & 0x2000) != 0 || (v6 & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v8;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0i64;
  v9 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent);
  if ( !v9 )
    return 0i64;
  m_pPointer = *(UFG::SimObjectCVBase **)(56i64
                                        * *(unsigned __int8 *)(LODWORD(this->m_Track[3].mResourceOwner)
                                                             + *(_QWORD *)(v9 + 96)
                                                             + 8i64)
                                        + *(_QWORD *)(v9 + 88)
                                        + 40);
  if ( !m_pPointer )
    return 0i64;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
LABEL_5:
  if ( m_Flags < 0 )
    return UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
  if ( (m_Flags & 0x2000) != 0 )
    return UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
  if ( (m_Flags & 0x1000) != 0 )
    return (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
  return (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                               m_pPointer,
                                               UFG::CharacterAnimationComponent::_TypeUID);
}

// File Line: 1802
// RVA: 0x2E9020
void __fastcall AttackTimerTask::Begin(AttackTimerTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    if ( m_pComponent )
      m_pComponent[1].m_TypeUID = 0;
    this->mContext = context;
  }
  else
  {
    this->mContext = context;
  }
}

// File Line: 1814
// RVA: 0x303A80
char __fastcall AttackTimerTask::Update(AttackTimerTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  if ( LOBYTE(this->m_Track[1].vfptr) )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        else
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      if ( m_pComponent )
        m_pComponent[1].m_TypeUID = 0;
    }
  }
  return 1;
}

// File Line: 1832
// RVA: 0x2F36B0
void __fastcall SetEngineDamageTask::Begin(SetEngineDamageTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = (UFG::PhysicsMoverInterface *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
        UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(m_pComponent, *(float *)&this->m_Track[1].vfptr);
    }
  }
}

// File Line: 1845
// RVA: 0x2F0E70
void __fastcall OverrideDesiredFocusModeTask::Begin(OverrideDesiredFocusModeTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TargetingSystemPedPlayerComponent *v7; // rax

  this->m_pContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = (UFG::TargetingSystemPedPlayerComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[19].__vecDelDtor)(m_pComponent);
      if ( v7 )
        UFG::TargetingSystemPedPlayerComponent::SetOverrideDesiredFocusMode(
          v7,
          (UFG::eFocusModeEnum)this->m_Track[1].vfptr);
    }
  }
}

// File Line: 1864
// RVA: 0x2FF270
void __fastcall OverrideDesiredFocusModeTask::End(OverrideDesiredFocusModeTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v5; // rax

  if ( BYTE4(this->m_Track[1].vfptr) )
  {
    m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
      {
        v5 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[19].__vecDelDtor)(m_pComponent);
        if ( v5 )
        {
          *(_DWORD *)(v5 + 3424) = 0;
          UFG::TargetingSystemPedPlayerComponent::SetFocusMode(
            (UFG::TargetingSystemPedPlayerComponent *)v5,
            eFOCUS_MODE_NONE);
        }
      }
    }
  }
}

// File Line: 1883
// RVA: 0x2F1CE0
void __fastcall ParkourSyncPositionTask::Begin(ParkourSyncPositionTask *this, ActionContext *context)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mParkourSimObject; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rax

  this->mSyncStarted = 0;
  this->mContext = context;
  p_mParkourSimObject = &this->mParkourSimObject;
  if ( p_mParkourSimObject->m_pPointer )
  {
    mPrev = p_mParkourSimObject->mPrev;
    mNext = p_mParkourSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParkourSimObject->mPrev = p_mParkourSimObject;
    p_mParkourSimObject->mNext = p_mParkourSimObject;
  }
  p_mParkourSimObject->m_pPointer = 0i64;
  this->mSyncBoneIndex = 0;
  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)m_pPointer->m_Components.p[28].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::WorldContextComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::WorldContextComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::WorldContextComponent::LatchFocusParkourHandle(m_pComponent);
  }
  ((void (__fastcall *)(ParkourSyncPositionTask *))this->vfptr->Update)(this);
}

// File Line: 1905
// RVA: 0x30E9A0
void __fastcall ParkourSyncPositionTask::startSync(ParkourSyncPositionTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rdi
  UFG::SimComponent *v5; // rax
  Creature *mCreature; // rsi
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::CharacterAnimationComponent *v9; // rax
  int BoneID; // eax
  ITrack *m_Track; // r11
  UFG::ParkourHandle *v12; // rbp
  UFG::SimObject *v13; // rdi
  __int16 v14; // cx
  UFG::SimComponent *ComponentOfType; // rax
  bool v16; // zf
  UFG::SimObjectGame *v17; // rcx

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)m_pPointer->m_Components.p[28].m_pComponent;
    }
    else
    {
      v5 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::WorldContextComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID);
      m_pComponent = (UFG::WorldContextComponent *)v5;
    }
    if ( m_pComponent )
    {
      mCreature = 0i64;
      v7 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
        }
        else if ( (v8 & 0x2000) != 0 )
        {
          v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v7);
        }
        else
        {
          v9 = (UFG::CharacterAnimationComponent *)((v8 & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v7,
                                                      UFG::CharacterAnimationComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      v7,
                                                      UFG::CharacterAnimationComponent::_TypeUID));
        }
        if ( v9 )
        {
          mCreature = v9->mCreature;
          if ( mCreature->mPose.mRigHandle.mData )
            BoneID = Skeleton::GetBoneID(
                       mCreature->mPose.mRigHandle.mUFGSkeleton,
                       HIDWORD(this->m_Track[1].mResourceOwner));
          else
            BoneID = -1;
          this->mSyncBoneIndex = BoneID;
        }
      }
      m_Track = this->m_Track;
      UFG::WorldContextComponent::StartSyncHandle(
        m_pComponent,
        this->mSyncBoneIndex,
        LOBYTE(m_Track[1].m_TrackClassNameUID) != 0,
        HIBYTE(m_Track[1].m_TrackClassNameUID) != 0,
        BYTE1(m_Track[1].m_TrackClassNameUID) != 0,
        BYTE2(m_Track[1].m_TrackClassNameUID) != 0,
        m_Track[1].mDisable != 0,
        m_Track[1].mMaster != 0,
        *(float *)&m_Track[1].mMasterRate.text.mOffset,
        *(float *)&m_Track[1].mResourceOwner);
      if ( this->m_Track[1].mBreakPoint )
      {
        if ( mCreature )
        {
          v12 = m_pComponent->mParkourHandle.m_pPointer;
          if ( v12 )
          {
            v13 = v12->mSimObject.m_pPointer;
            if ( v13 )
            {
              v14 = v13->m_Flags;
              if ( (v14 & 0x4000) != 0 )
              {
                ComponentOfType = v13->m_Components.p[9].m_pComponent;
              }
              else if ( v14 >= 0 )
              {
                if ( (v14 & 0x2000) != 0 )
                {
                  ComponentOfType = v13->m_Components.p[8].m_pComponent;
                }
                else
                {
                  v16 = (v14 & 0x1000) == 0;
                  v17 = (UFG::SimObjectGame *)v12->mSimObject.m_pPointer;
                  if ( v16 )
                    ComponentOfType = UFG::SimObject::GetComponentOfType(v17, UFG::BaseAnimationComponent::_TypeUID);
                  else
                    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v17,
                                        UFG::BaseAnimationComponent::_TypeUID);
                }
              }
              else
              {
                ComponentOfType = v13->m_Components.p[9].m_pComponent;
              }
              if ( ComponentOfType && *(_QWORD *)&ComponentOfType[2].m_TypeUID )
              {
                UFG::qSafePointer<Creature,Creature>::operator=(
                  (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mParkourSimObject,
                  (UFG::SimComponent *)v13);
                Creature::AddAttachmentParkour(
                  mCreature,
                  this->mParkourSimObject.m_pPointer,
                  this->mSyncBoneIndex,
                  this->mContext->mSimObject.m_pPointer,
                  v12,
                  *(float *)&this->m_Track[1].mResourceOwner);
              }
            }
          }
        }
      }
    }
  }
  this->mSyncStarted = 1;
}

// File Line: 1957
// RVA: 0x305F60
_BOOL8 __fastcall ParkourSyncPositionTask::Update(ParkourSyncPositionTask *this, float timeDelta)
{
  float m_ActionNodePlayTime; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm0_4

  m_ActionNodePlayTime = this->mContext->mActionController->m_ActionNodePlayTime;
  if ( !this->mSyncStarted )
  {
    v4 = *(float *)&this->m_Track[1].vfptr;
    if ( v4 >= 0.0 && m_ActionNodePlayTime >= v4 )
      ParkourSyncPositionTask::startSync(this);
  }
  if ( this->mSyncStarted && (v5 = *((float *)&this->m_Track[1].vfptr + 1), v5 >= 0.0) )
    return m_ActionNodePlayTime < v5;
  else
    return 1i64;
}

// File Line: 1995
// RVA: 0x2FF8A0
void __fastcall ParkourSyncPositionTask::End(ParkourSyncPositionTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *v5; // rcx
  __int16 v6; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::WorldContextComponent *)m_pPointer->m_Components.p[28].m_pComponent;
    else
      m_pComponent = (UFG::WorldContextComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::WorldContextComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::WorldContextComponent::_TypeUID));
    if ( m_pComponent )
      UFG::WorldContextComponent::StopSync(m_pComponent);
  }
  if ( this->m_Track[1].mBreakPoint )
  {
    if ( this->mParkourSimObject.m_pPointer )
    {
      v5 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
      if ( v5 )
      {
        v6 = v5->m_Flags;
        if ( (v6 & 0x4000) != 0 || v6 < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
        }
        else if ( (v6 & 0x2000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
        }
        else if ( (v6 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v5,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                    v5,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
        }
        if ( ComponentOfTypeHK )
        {
          mCreature = ComponentOfTypeHK->mCreature;
          if ( mCreature )
            Creature::RemoveAttachment(
              mCreature,
              this->mParkourSimObject.m_pPointer,
              this->mSyncBoneIndex,
              this->mContext->mSimObject.m_pPointer);
        }
      }
    }
  }
}

// File Line: 2022
// RVA: 0x2F1C40
void __fastcall ParkourNeighborAdvanceTask::Begin(ParkourNeighborAdvanceTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)m_pPointer->m_Components.p[28].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::WorldContextComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID);
      m_pComponent = (UFG::WorldContextComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
      UFG::WorldContextComponent::AdvanceParkourNeighbor(m_pComponent, LOBYTE(this->m_Track[1].vfptr) != 0);
  }
}

// File Line: 2046
// RVA: 0x2F1750
void __fastcall ParkourConstrainTask::Begin(ParkourConstrainTask *this, ActionContext *context)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mParkourSimObject; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::RagdollComponent *ComponentOfType; // rsi
  ActionContext *mContext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rdi
  UFG::SimComponent *v11; // rax
  UFG::SimObjectCVBase *v12; // rcx
  __int16 v13; // dx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *mCreature; // r14
  int BoneID; // eax
  UFG::SimObject *v17; // rcx
  UFG::ParkourHandle *v18; // rdi
  UFG::Ragdoll *mRagdoll; // rcx
  hkpRigidBody *RigidBody; // r15
  UFG::qVector3 *Axis; // rax
  float y; // xmm9_4
  __m128 x_low; // xmm8
  float z; // xmm10_4
  __m128 v25; // xmm2
  float v26; // xmm1_4
  float v27; // xmm8_4
  float v28; // xmm9_4
  float v29; // xmm10_4
  float HalfLength; // xmm4_4
  float v31; // xmm6_4
  UFG::Constraint *v32; // rax
  UFG::qVector3 v33; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 result; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qVector3 vHandleAxis; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector4 vHandleOrigin; // [rsp+7Ch] [rbp-84h] BYREF
  UFG::qVector4 vSyncPosition; // [rsp+8Ch] [rbp-74h] BYREF
  UFG::qVector4 v38; // [rsp+A0h] [rbp-60h] BYREF
  float fRightConstraint; // [rsp+130h] [rbp+30h] BYREF
  float fLeftConstraint; // [rsp+138h] [rbp+38h] BYREF

  this->mSyncSuccess = 0;
  this->mContext = context;
  p_mParkourSimObject = &this->mParkourSimObject;
  if ( p_mParkourSimObject->m_pPointer )
  {
    mPrev = p_mParkourSimObject->mPrev;
    mNext = p_mParkourSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParkourSimObject->mPrev = p_mParkourSimObject;
    p_mParkourSimObject->mNext = p_mParkourSimObject;
  }
  ComponentOfType = 0i64;
  p_mParkourSimObject->m_pPointer = 0i64;
  mContext = this->mContext;
  this->mSyncBoneIndex = 0;
  m_pPointer = (UFG::SimObjectGame *)mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)m_pPointer->m_Components.p[28].m_pComponent;
    }
    else
    {
      v11 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::WorldContextComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID);
      m_pComponent = (UFG::WorldContextComponent *)v11;
    }
    if ( m_pComponent )
    {
      UFG::WorldContextComponent::LatchFocusParkourHandle(m_pComponent);
      v12 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 & 0x4000) != 0 || v13 < 0 )
        {
          v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12);
        }
        else if ( (v13 & 0x2000) != 0 )
        {
          v14 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v12);
        }
        else
        {
          v14 = (UFG::CharacterAnimationComponent *)((v13 & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v12,
                                                       UFG::CharacterAnimationComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       v12,
                                                       UFG::CharacterAnimationComponent::_TypeUID));
        }
        if ( v14 )
        {
          mCreature = v14->mCreature;
          if ( mCreature->mPose.mRigHandle.mData )
            BoneID = Skeleton::GetBoneID(
                       mCreature->mPose.mRigHandle.mUFGSkeleton,
                       HIDWORD(this->m_Track[1].mResourceOwner));
          else
            BoneID = -1;
          this->mSyncBoneIndex = BoneID;
          v17 = this->mContext->mSimObject.m_pPointer;
          if ( v17 )
            ComponentOfType = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                         v17,
                                                         UFG::RagdollComponent::_TypeUID);
          v18 = m_pComponent->mParkourHandle.m_pPointer;
          if ( ComponentOfType )
          {
            if ( v18 )
            {
              mRagdoll = ComponentOfType->mRagdoll;
              if ( mRagdoll )
              {
                RigidBody = UFG::Ragdoll::GetRigidBody(mRagdoll, this->mSyncBoneIndex);
                if ( RigidBody )
                {
                  Creature::GetTranslation(mCreature, &result, this->mSyncBoneIndex);
                  UFG::ParkourHandle::GetPosition(v18, &v33);
                  Axis = UFG::ParkourHandle::GetAxis(v18, &vHandleAxis);
                  y = Axis->y;
                  x_low = (__m128)LODWORD(Axis->x);
                  z = Axis->z;
                  v25 = x_low;
                  v25.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y))
                                  + (float)(z * z);
                  if ( v25.m128_f32[0] == 0.0 )
                    v26 = 0.0;
                  else
                    v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
                  v27 = x_low.m128_f32[0] * v26;
                  v28 = y * v26;
                  v29 = z * v26;
                  HalfLength = UFG::ParkourHandle::GetHalfLength(v18);
                  v33.x = v33.x + (float)(v27 * HalfLength);
                  v33.y = v33.y + (float)(v28 * HalfLength);
                  v33.z = v33.z + (float)(HalfLength * v29);
                  v31 = UFG::ParkourHandle::GetHalfLength(v18) * 2.0;
                  fLeftConstraint = 0.0;
                  fRightConstraint = 0.0;
                  getParkourEdgeConstraints(v18, 1, 1, 0.0, 0.0, &fLeftConstraint, &fRightConstraint);
                  vHandleOrigin.x = v33.x;
                  vHandleOrigin.y = v33.y;
                  vHandleOrigin.z = v33.z;
                  vHandleOrigin.w = 1.0;
                  vSyncPosition.y = result.y;
                  vSyncPosition.x = result.x;
                  vSyncPosition.w = 1.0;
                  LODWORD(vHandleAxis.x) = LODWORD(v27) ^ _xmm[0];
                  vSyncPosition.z = result.z;
                  LODWORD(vHandleAxis.y) = LODWORD(v28) ^ _xmm[0];
                  LODWORD(vHandleAxis.z) = LODWORD(v29) ^ _xmm[0];
                  UFG::WorldContextComponent::GetClosestAnchorOnLine(
                    &v38,
                    &vSyncPosition,
                    &vHandleOrigin,
                    &vHandleAxis,
                    v31,
                    fLeftConstraint,
                    fRightConstraint,
                    0,
                    0);
                  v32 = UFG::CreateConstraint_Util(RigidBody, 0i64, &result);
                  UFG::RagdollComponent::AddConstraint(ComponentOfType, v32);
                  this->mSyncSuccess = 1;
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 2107
// RVA: 0x305F50
_BOOL8 __fastcall ParkourConstrainTask::Update(ParkourConstrainTask *this, float timeDelta)
{
  return this->mSyncSuccess;
}

// File Line: 2112
// RVA: 0x2FF810
void __fastcall ParkourConstrainTask::End(ParkourConstrainTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)m_pPointer->m_Components.p[28].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::WorldContextComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::WorldContextComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::WorldContextComponent::LatchParkourHandle(m_pComponent, 0i64);
  }
}

// File Line: 2124
// RVA: 0x2EB490
void __fastcall CoverSyncPositionTask::Begin(CoverSyncPositionTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // rax
  int BoneID; // edi
  UFG::SimObjectCVBase *v8; // rcx
  __int16 v9; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  ITrack *m_Track; // rax
  bool v13; // cl
  bool v14; // zf
  float blendIn; // [rsp+48h] [rbp-10h]

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)m_pPointer->m_Components.p[28].m_pComponent;
    }
    else
    {
      v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::WorldContextComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID);
      m_pComponent = (UFG::WorldContextComponent *)v6;
    }
    if ( m_pComponent )
    {
      BoneID = 0;
      v8 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 & 0x4000) != 0 || v9 < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
        }
        else if ( (v9 & 0x2000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
        }
        else if ( (v9 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v8,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                    v8,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
        }
        if ( ComponentOfTypeHK )
        {
          mCreature = ComponentOfTypeHK->mCreature;
          if ( mCreature->mPose.mRigHandle.mData )
            BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, HIDWORD(this->m_Track[1].vfptr));
          else
            BoneID = -1;
        }
      }
      m_Track = this->m_Track;
      blendIn = *(float *)&m_Track[1].vfptr;
      v13 = BYTE1(m_Track[1].mResourceOwner) != 0;
      v14 = LOBYTE(m_Track[1].mResourceOwner) == 0;
      m_pComponent->mbSyncingCoverRCorner = BYTE2(m_Track[1].mResourceOwner) != 0;
      m_pComponent->mbSyncingCoverLCorner = v13;
      m_pComponent->mbSyncingCoverParkour = !v14;
      UFG::WorldContextComponent::StartSync(m_pComponent, BoneID, 0, 0, 1, 0, 0, 0, 0.0, blendIn);
    }
  }
}

// File Line: 2153
// RVA: 0x2FE830
void __fastcall CoverSyncPositionTask::End(CoverSyncPositionTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)m_pPointer->m_Components.p[28].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::WorldContextComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::WorldContextComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::WorldContextComponent::StopSync(m_pComponent);
  }
}

// File Line: 2167
// RVA: 0x2EB350
void __fastcall CoverHoldPositionTask::Begin(CoverHoldPositionTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *v4; // rdx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    v4 = ComponentOfTypeHK;
  }
  else
  {
    v4 = 0i64;
  }
  ++LODWORD(v4[2].m_BoundComponentHandles.mNode.mNext);
  if ( LOBYTE(this->m_Track[1].vfptr) )
    ++HIDWORD(v4[2].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 2187
// RVA: 0x2FE670
void __fastcall CoverHoldPositionTask::End(CoverHoldPositionTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *v3; // rdx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    v3 = ComponentOfTypeHK;
  }
  else
  {
    v3 = 0i64;
  }
  --LODWORD(v3[2].m_BoundComponentHandles.mNode.mNext);
  if ( LOBYTE(this->m_Track[1].vfptr) )
    --HIDWORD(v3[2].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 2237
// RVA: 0x2FE7A0
void __fastcall CoverProbeForwardAndLatchTask::End(CoverProbeForwardAndLatchTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( this->m_bLatched )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        --LODWORD(ComponentOfTypeHK[2].m_BoundComponentHandles.mNode.mNext);
    }
  }
}

// File Line: 2254
// RVA: 0x2EB3F0
void __fastcall CoverProbeForwardAndLatchTask::Begin(CoverProbeForwardAndLatchTask *this, ActionContext *context)
{
  this->mContext = context;
  this->m_bLatched = 0;
}

// File Line: 2261
// RVA: 0x303EA0
bool __fastcall CoverProbeAndLatchTask::Update(CoverProbeForwardAndLatchTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObject *v7; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  ITrack *m_Track; // rax
  __int64 v10; // r8
  float v11; // xmm0_4
  float v12; // xmm2_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm2_4
  bool v19; // zf
  bool result; // al
  int v21[6]; // [rsp+20h] [rbp-18h] BYREF

  if ( this->m_bLatched )
    return 1;
  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 1;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
  v6 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 1;
  v7 = this->mContext->mSimObject.m_pPointer;
  if ( v7 )
    m_pTransformNodeComponent = v7->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  m_Track = this->m_Track;
  LOBYTE(v10) = 1;
  v11 = *((float *)&m_Track[1].vfptr + 1);
  v12 = *(float *)&m_Track[1].vfptr;
  vfptr = v6->vfptr;
  v14 = UFG::qVector3::msAxisZ.y * v11;
  v15 = UFG::qVector3::msAxisZ.z * v11;
  v16 = (float)((float)(v12 * m_pTransformNodeComponent->mWorldTransform.v0.x)
              + m_pTransformNodeComponent->mWorldTransform.v3.x)
      + (float)(UFG::qVector3::msAxisZ.x * v11);
  *(float *)&v17 = (float)((float)(v12 * m_pTransformNodeComponent->mWorldTransform.v0.y)
                         + m_pTransformNodeComponent->mWorldTransform.v3.y)
                 + v14;
  *(float *)&v18 = (float)((float)(v12 * m_pTransformNodeComponent->mWorldTransform.v0.z)
                         + m_pTransformNodeComponent->mWorldTransform.v3.z)
                 + v15;
  *(float *)v21 = v16;
  v21[1] = v17;
  v21[2] = v18;
  v19 = ((unsigned __int8 (__fastcall *)(UFG::SimComponent *, int *, __int64, _QWORD))vfptr[17].__vecDelDtor)(
          v6,
          v21,
          v10,
          0i64) == 0;
  result = 1;
  if ( !v19 )
  {
    this->m_bLatched = 1;
    ++LODWORD(v6[2].m_BoundComponentHandles.mNode.mNext);
  }
  return result;
}

// File Line: 2289
// RVA: 0x2FE710
void __fastcall CoverProbeAndLatchTask::End(CoverProbeAndLatchTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      --LODWORD(ComponentOfTypeHK[2].m_BoundComponentHandles.mNode.mNext);
  }
}

// File Line: 2302
// RVA: 0x2EB400
void __fastcall CoverSetPopoutSideTask::Begin(CoverSetPopoutSideTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  UFG::SimComponent *ComponentOfType; // rax
  bool v7; // zf

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
  {
    MEMORY[0x80] = this->m_Track[1].vfptr;
    return;
  }
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::AICoverComponent::_TypeUID;
  }
  else
  {
    v7 = (m_Flags & 0x1000) == 0;
    v5 = UFG::AICoverComponent::_TypeUID;
    if ( v7 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
      goto LABEL_10;
    }
  }
  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5);
LABEL_10:
  LODWORD(ComponentOfType[2].vfptr) = this->m_Track[1].vfptr;
}

// File Line: 2320
// RVA: 0x2EDF20
void __fastcall DynamicWallHandleTask::Begin(DynamicWallHandleTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SensorComponent *m_pComponent; // rax
  UFG::WallRunningRequest *v6; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::SensorComponent::_TypeUID);
      else
        m_pComponent = (UFG::SensorComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::SensorComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
    if ( m_pComponent )
    {
      v6 = UFG::SensorComponent::BeginWallRunningTest(m_pComponent);
      this->mWallRunningRequest = v6;
      if ( v6 )
      {
        v6->relativeAngle = *(float *)&this->m_Track[1].vfptr;
        this->mWallRunningRequest->firstRayHeight = *((float *)&this->m_Track[1].vfptr + 1);
        this->mWallRunningRequest->raySpacing = *(float *)&this->m_Track[1].mResourceOwner;
        this->mWallRunningRequest->rayLength = *((float *)&this->m_Track[1].mResourceOwner + 1);
      }
    }
  }
}

// File Line: 2340
// RVA: 0x2FEBA0
void __fastcall DynamicWallHandleTask::End(DynamicWallHandleTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SensorComponent *m_pComponent; // rax
  UFG::WallRunningRequest *mWallRunningRequest; // rdx

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::SensorComponent::_TypeUID);
      else
        m_pComponent = (UFG::SensorComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::SensorComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
    if ( m_pComponent )
    {
      mWallRunningRequest = this->mWallRunningRequest;
      if ( mWallRunningRequest )
      {
        UFG::SensorComponent::EndWallRunningTest(m_pComponent, mWallRunningRequest);
        this->mWallRunningRequest = 0i64;
      }
    }
  }
}

// File Line: 2353
// RVA: 0x2EE040
void __fastcall EventTask::Begin(EventTask *this, ActionContext *context)
{
  UFG::allocator::free_link *v4; // rax
  ITrack *v5; // rdx
  const char *v6; // rdx

  v4 = UFG::qMalloc(0x50ui64, "EventTask::Begin", 0i64);
  if ( v4 )
  {
    v5 = this->m_Track + 1;
    if ( ((unsigned __int64)v5->vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      v6 = (char *)v5 + ((unsigned __int64)v5->vfptr & 0xFFFFFFFFFFFFFFFEui64);
    else
      v6 = BinString::sEmptyString;
    UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v4, v6, &context->mSimObject);
  }
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
}

// File Line: 2364
// RVA: 0x2E8950
void __fastcall ApplyStimulusEmitterToTargetTask::Begin(ApplyStimulusEmitterToTargetTask *this, ActionContext *context)
{
  ITrack *m_Track; // r9
  char v3; // bl
  int vfptr; // r8d
  UFG::SimObjectGame *m_pPointer; // r8
  float v7; // xmm1_4
  __int64 vfptr_high; // rsi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v12; // r8
  UFG::eStimulusType mOffset; // edx
  char *String_DBG; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-48h] BYREF
  UFG::qString v16; // [rsp+48h] [rbp-30h] BYREF

  m_Track = this->m_Track;
  v3 = 0;
  vfptr = (int)m_Track[1].vfptr;
  stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_NONE;
  stimulus_parameters.m_MaxStimulusDuration = -1.0;
  stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
  stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
  if ( !vfptr )
  {
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
    goto LABEL_5;
  }
  if ( vfptr == 1 )
  {
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
LABEL_5:
    v3 = 1;
  }
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  stimulus_parameters.m_MaxStimulusDuration = *(float *)&m_Track[1].mResourceOwner;
  v7 = *((float *)&m_Track[1].mResourceOwner + 1);
  stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
  stimulus_parameters.m_EmitUntilSpeedLessThan = v7;
  vfptr_high = SHIDWORD(m_Track[1].vfptr);
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
      : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
        m_pComponent
     && (v12 = *(UFG::SimObject **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                       + (unsigned int)vfptr_high
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40)) != 0i64) )
  {
    mOffset = this->m_Track[1].mMasterRate.expression.mOffset;
    if ( v3 )
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        mOffset,
        &stimulus_parameters,
        v12,
        eTARGET_TYPE_INVALID);
    else
      UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, mOffset, v12);
  }
  else
  {
    String_DBG = ActionPath::GetString_DBG((ActionPath *)&this->m_Track[1].m_TrackClassNameUID);
    UFG::qString::qString(
      &v16,
      "ERROR: ApplyStimulusEmitterToTargetTrack in %s: invalid target %s",
      String_DBG,
      UFG::TargetTypeEnumNames[vfptr_high]);
    UFG::qString::~qString(&v16);
  }
}

// File Line: 2474
// RVA: 0x2DDD00
void __fastcall AttackRightsTask::AttackRightsTask(AttackRightsTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsTask::`vftable;
  this->mAttackRightsComponent.mPrev = &this->mAttackRightsComponent;
  this->mAttackRightsComponent.mNext = &this->mAttackRightsComponent;
  this->mAttackRightsComponent.m_pPointer = 0i64;
  this->mPreviousAttackRights = 0;
  this->mpContext = 0i64;
}

// File Line: 2496
// RVA: 0x2E8E60
void __fastcall AttackRightsTask::Begin(AttackRightsTask *this, ActionContext *context)
{
  char v4; // bp
  UFG::SimObjectGame *m_pPointer; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_mAttackRightsComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  char v14; // al
  const char *v15; // r8
  int v16; // eax
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF

  v4 = LOBYTE(this->m_Track[1].vfptr) != 0;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[46].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AttackRightsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AttackRightsComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_mAttackRightsComponent = &this->mAttackRightsComponent;
  if ( this->mAttackRightsComponent.m_pPointer )
  {
    mPrev = p_mAttackRightsComponent->mPrev;
    mNext = this->mAttackRightsComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttackRightsComponent->mPrev = p_mAttackRightsComponent;
    this->mAttackRightsComponent.mNext = &this->mAttackRightsComponent;
  }
  this->mAttackRightsComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v13 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v13->mNext = p_mAttackRightsComponent;
    p_mAttackRightsComponent->mPrev = v13;
    this->mAttackRightsComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_mAttackRightsComponent;
  }
  this->mpContext = context;
  if ( m_pComponent )
  {
    v14 = LOBYTE(m_pComponent[149].vfptr) && BYTE1(m_pComponent[149].vfptr) && BYTE2(m_pComponent[149].vfptr);
    this->mPreviousAttackRights = v14;
    if ( v14 == v4 )
    {
      if ( m_pPointer )
        m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
      v15 = "false";
      if ( v4 )
        v15 = "true";
      v16 = (unsigned int)UFG::qString::FormatEx(&result, "AttackRightsTrack: Already set attacking enabled to %s", v15);
      UFG::DrawDebugText(m_pTransformNodeComponent, &UFG::qColour::White, result.mData, v16, -2i64);
    }
    else
    {
      UFG::qString::qString(&result);
      LOBYTE(m_pComponent[149].vfptr) = v4;
      BYTE1(m_pComponent[149].vfptr) = v4;
      BYTE2(m_pComponent[149].vfptr) = v4;
      UFG::qString::Set((UFG::qString *)&m_pComponent[161].m_TypeUID, result.mData);
    }
    UFG::qString::~qString(&result);
  }
}

// File Line: 2530
// RVA: 0x2FDF50
void __fastcall AttackRightsTask::End(AttackRightsTask *this)
{
  UFG::SimComponent *m_pPointer; // rax
  bool v3; // al
  char *mData; // rdx
  UFG::SimComponent *v5; // rcx
  bool mPreviousAttackRights; // al
  UFG::qString v7; // [rsp+28h] [rbp-30h] BYREF

  if ( BYTE1(this->m_Track[1].vfptr) )
  {
    m_pPointer = this->mAttackRightsComponent.m_pPointer;
    if ( m_pPointer )
    {
      v3 = LOBYTE(m_pPointer[149].vfptr) && BYTE1(m_pPointer[149].vfptr) && BYTE2(m_pPointer[149].vfptr);
      if ( this->mPreviousAttackRights != v3 )
      {
        UFG::qString::qString(&v7);
        mData = v7.mData;
        v5 = this->mAttackRightsComponent.m_pPointer;
        mPreviousAttackRights = this->mPreviousAttackRights;
        LOBYTE(v5[149].vfptr) = mPreviousAttackRights;
        BYTE1(v5[149].vfptr) = mPreviousAttackRights;
        BYTE2(v5[149].vfptr) = mPreviousAttackRights;
        UFG::qString::Set((UFG::qString *)&v5[161].m_TypeUID, mData);
        UFG::qString::~qString(&v7);
      }
    }
  }
}

// File Line: 2572
// RVA: 0x2F4350
void __fastcall SkookumTask::Begin(SkookumTask *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // rax
  SSCode *ScriptCode; // rbp
  UFG::SimObject *v6; // r8
  __int16 m_Flags; // dx
  UFG::TSActorComponent *ComponentOfType; // rax
  UFG::TSActor *Actor; // rax

  this->mMethodFinished = 0;
  this->mpMethodWrapper = 0i64;
  if ( pContext )
  {
    m_pPointer = pContext->mSimObject.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 2) == 0 )
    {
      ScriptCode = UFG::ScriptCache::GetScriptCode(*(UFG::ScriptCache::Script **)&this->m_Track[1].m_TrackClassNameUID);
      if ( ScriptCode )
      {
        v6 = pContext->mSimObject.m_pPointer;
        if ( v6
          && ((m_Flags = v6->m_Flags, (m_Flags & 0x4000) == 0)
            ? (m_Flags >= 0
             ? ((m_Flags & 0x2000) == 0
              ? ((m_Flags & 0x1000) == 0
               ? (ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                               pContext->mSimObject.m_pPointer,
                                                               UFG::TSActorComponent::_TypeUID))
               : (ComponentOfType = (UFG::TSActorComponent *)v6->m_Components.p[2].m_pComponent))
              : (ComponentOfType = (UFG::TSActorComponent *)v6->m_Components.p[3].m_pComponent))
             : (ComponentOfType = (UFG::TSActorComponent *)v6->m_Components.p[4].m_pComponent))
            : (ComponentOfType = (UFG::TSActorComponent *)v6->m_Components.p[4].m_pComponent),
              ComponentOfType) )
        {
          Actor = UFG::TSActorComponent::GetActor(ComponentOfType);
        }
        else
        {
          Actor = (UFG::TSActor *)SkookumScript::c_world_p;
        }
        this->mpMethodWrapper = (SSIExternalMethodCallWrapper *)UFG::SkookumMgr::RunExternalCodeBlock(
                                                                  ScriptCode,
                                                                  Actor->i_class_p,
                                                                  Actor,
                                                                  &this->mMethodFinished,
                                                                  0i64);
      }
    }
  }
}

// File Line: 2600
// RVA: 0x30A050
_BOOL8 __fastcall SkookumTask::Update(SkookumTask *this, float timeDelta)
{
  return !this->mMethodFinished;
}

// File Line: 2607
// RVA: 0x300250
void __fastcall SkookumTask::End(SkookumTask *this)
{
  SSIExternalMethodCallWrapper *mpMethodWrapper; // rdx

  if ( !this->mMethodFinished )
  {
    mpMethodWrapper = this->mpMethodWrapper;
    if ( mpMethodWrapper )
      mpMethodWrapper->i_finished_p = 0i64;
  }
  this->mpMethodWrapper = 0i64;
  this->mMethodFinished = 0;
}

// File Line: 2613
// RVA: 0x2F3A20
void __fastcall ShootTask::Begin(ShootTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SubTargetingLocation *pSubTargetingLocation; // r12
  int v6; // r14d
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::GunComponent *v9; // rbp
  UFG::SimObjectGame *v10; // r8
  __int16 v11; // cx
  UFG::InventoryItemComponent *m_pComponent; // rbx
  UFG::SimComponent *v13; // rax
  UFG::SimObjectGame *OwnerSimObject; // rdi
  UFG::SimComponent *v15; // rax
  bool v16; // bl
  __int16 v17; // cx
  UFG::SimComponent *v18; // rbx
  UFG::SimComponent *v19; // rax
  __int16 v20; // cx
  UFG::AimingBaseComponent *v21; // rsi
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v23; // cx
  UFG::SimComponent *v24; // rax
  __int64 v25; // rax
  ITrack *m_Track; // rax
  unsigned __int64 v27; // rcx
  const char *v28; // rdx
  UFG::SimObject *pShootOriginSimObject; // rbx
  UFG::qSymbolUC *originBoneId; // rax
  UFG::SimObjectGame *v31; // rcx
  __int16 v32; // dx
  UFG::SimComponent *v33; // rdx
  UFG::SimComponent *v34; // rax
  UFG::SimObject *v35; // rdi
  ITrack *v36; // rax
  unsigned __int64 v37; // rcx
  const char *v38; // rdx
  UFG::SimObject *v39; // rbx
  UFG::qSymbolUC *v40; // rax
  UFG::qSymbolUC result; // [rsp+78h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( (m_pPointer->m_Flags & 0x400) == 0 )
  {
    pSubTargetingLocation = 0i64;
    v6 = (LOBYTE(this->m_Track[1].mResourceOwner) != 0 ? 2 : 0) | (BYTE1(this->m_Track[1].mResourceOwner) != 0);
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GunComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
      v9 = (UFG::GunComponent *)ComponentOfTypeHK;
      if ( ComponentOfTypeHK )
      {
        v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
        if ( !v10 )
          goto LABEL_63;
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) != 0 || v11 < 0 )
          goto LABEL_63;
        if ( (v11 & 0x2000) != 0 )
        {
          m_pComponent = (UFG::InventoryItemComponent *)v10->m_Components.p[11].m_pComponent;
        }
        else
        {
          v13 = (v11 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::InventoryItemComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v10, UFG::InventoryItemComponent::_TypeUID);
          m_pComponent = (UFG::InventoryItemComponent *)v13;
        }
        if ( !m_pComponent )
          goto LABEL_63;
        OwnerSimObject = (UFG::SimObjectGame *)UFG::InventoryItemComponent::GetOwnerSimObject(m_pComponent);
        if ( !OwnerSimObject )
          goto LABEL_63;
        v15 = m_pComponent->m_pOwnerInventoryComponent.m_pPointer;
        v16 = v15 && BYTE1(v15[14].m_pSimObject);
        if ( UFG::IsAnyLocalPlayer(OwnerSimObject) && v16 )
          v6 &= ~1u;
        v17 = OwnerSimObject->m_Flags;
        if ( (v17 & 0x4000) != 0 )
        {
          v18 = OwnerSimObject->m_Components.p[20].m_pComponent;
        }
        else if ( v17 >= 0 )
        {
          v19 = (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(OwnerSimObject, UFG::TargetingSystemBaseComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(OwnerSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
          v18 = v19;
        }
        else
        {
          v18 = OwnerSimObject->m_Components.p[20].m_pComponent;
        }
        if ( v18 )
        {
          v20 = OwnerSimObject->m_Flags;
          if ( (v20 & 0x4000) != 0 )
          {
            v21 = (UFG::AimingBaseComponent *)OwnerSimObject->m_Components.p[47].m_pComponent;
          }
          else
          {
            if ( v20 < 0 || (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0 )
              ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  OwnerSimObject,
                                  UFG::AimingBaseComponent::_TypeUID);
            else
              ComponentOfType = UFG::SimObject::GetComponentOfType(OwnerSimObject, UFG::AimingBaseComponent::_TypeUID);
            v21 = (UFG::AimingBaseComponent *)ComponentOfType;
          }
          v23 = OwnerSimObject->m_Flags;
          if ( (v23 & 0x4000) != 0 )
          {
            v24 = OwnerSimObject->m_Components.p[15].m_pComponent;
          }
          else if ( v23 >= 0 )
          {
            if ( (v23 & 0x2000) != 0 || (v23 & 0x1000) != 0 )
              v24 = UFG::SimObjectGame::GetComponentOfTypeHK(OwnerSimObject, UFG::HitReactionComponent::_TypeUID);
            else
              v24 = UFG::SimObject::GetComponentOfType(OwnerSimObject, UFG::HitReactionComponent::_TypeUID);
          }
          else
          {
            v24 = OwnerSimObject->m_Components.p[15].m_pComponent;
          }
          if ( v24 )
            v24[1].m_TypeUID = 0;
          v25 = ((__int64 (__fastcall *)(UFG::SimComponent *))v18->vfptr[19].__vecDelDtor)(v18);
          if ( v25 )
            pSubTargetingLocation = *(UFG::SubTargetingLocation **)(v25 + 2736);
          m_Track = this->m_Track;
          v27 = (unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
          v28 = (char *)&m_Track[1] + v27;
          if ( !v27 )
            v28 = BinString::sEmptyString;
          pShootOriginSimObject = context->mSimObject.m_pPointer;
          originBoneId = UFG::qSymbolUC::create_from_string(&result, v28);
          UFG::GunComponent::Shoot(
            v9,
            OwnerSimObject,
            v21,
            v6,
            pSubTargetingLocation,
            pShootOriginSimObject,
            originBoneId);
        }
        else
        {
LABEL_63:
          v31 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
          if ( v31
            && ((v32 = v31->m_Flags, (v32 & 0x4000) == 0)
              ? (v32 >= 0
               ? ((v32 & 0x2000) != 0 || (v32 & 0x1000) != 0
                ? (v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::TargetingSystemBaseComponent::_TypeUID))
                : (v34 = UFG::SimObject::GetComponentOfType(v31, UFG::TargetingSystemBaseComponent::_TypeUID)),
                  v33 = v34)
               : (v33 = v31->m_Components.p[20].m_pComponent))
              : (v33 = v31->m_Components.p[20].m_pComponent),
                v33
             && (v35 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v33[1].m_Flags + 62i64)
                                          + *(_QWORD *)&v33[1].m_TypeUID
                                          + 40)) != 0i64) )
          {
            v36 = this->m_Track;
            v37 = (unsigned __int64)v36[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
            v38 = (char *)&v36[1] + v37;
            if ( !v37 )
              v38 = BinString::sEmptyString;
            v39 = context->mSimObject.m_pPointer;
            v40 = UFG::qSymbolUC::create_from_string(&result, v38);
            UFG::GunComponent::Shoot(v9, v35, 0i64, v6, 0i64, v39, v40);
          }
          else
          {
            UFG::GunComponent::Shoot(v9, v6);
          }
        }
      }
    }
  }
}

// File Line: 2704
// RVA: 0x2F3E90
void __fastcall ShootTaskTU::Begin(ShootTaskTU *this, ActionContext *context)
{
  UFG::SimObjectGame *pShootOriginSimObject; // r15
  ITrack *m_Track; // r8
  UFG::AimingBaseComponent *v6; // rbp
  bool v7; // zf
  char v8; // al
  int vfptr; // r14d
  UFG::SimObjectGame *OwnerSimObject; // rbx
  int v11; // r12d
  UFG::SimComponent *m_pComponent; // rsi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v15; // rdx
  __int64 v16; // r8
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 v18; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::GunComponent *v20; // r14
  UFG::SimObject *v21; // r8
  __int16 v22; // cx
  UFG::InventoryItemComponent *v23; // rdi
  UFG::SimObjectGame *v24; // rcx
  UFG::SimComponent *v25; // rax
  UFG::SimComponent *v26; // rax
  bool v27; // di
  __int16 v28; // cx
  UFG::SimComponent *v29; // rax
  __int64 v30; // rax
  __int16 v31; // cx
  UFG::SimComponent *v32; // rax
  ITrack *v33; // rax
  unsigned __int64 v34; // rcx
  const char *v35; // rdx
  UFG::qSymbolUC *originBoneId; // rax
  UFG::qSymbolUC result; // [rsp+88h] [rbp+10h] BYREF
  UFG::SubTargetingLocation *pSubTargetingLocation; // [rsp+90h] [rbp+18h]

  pShootOriginSimObject = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( (pShootOriginSimObject->m_Flags & 0x400) == 0 )
  {
    m_Track = this->m_Track;
    v6 = 0i64;
    v7 = BYTE1(m_Track[1].m_TrackClassNameUID) == 0;
    v8 = -LOBYTE(m_Track[1].m_TrackClassNameUID);
    vfptr = (int)m_Track[1].vfptr;
    OwnerSimObject = 0i64;
    pSubTargetingLocation = 0i64;
    v11 = (v8 != 0 ? 2 : 0) | !v7;
    if ( pShootOriginSimObject )
    {
      m_Flags = pShootOriginSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = pShootOriginSimObject->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                pShootOriginSimObject,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                pShootOriginSimObject,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = pShootOriginSimObject->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    if ( vfptr && m_pComponent )
    {
      v15 = *(_QWORD *)&m_pComponent[1].m_Flags;
      v16 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
      pShootOriginSimObject = *(UFG::SimObjectGame **)(56i64
                                                     * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr) + v15 + 8)
                                                     + v16
                                                     + 40);
      OwnerSimObject = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v15 + 62) + v16 + 40);
    }
    m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      v18 = m_pPointer->m_Flags;
      if ( (v18 & 0x4000) != 0 || v18 < 0 || (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GunComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GunComponent::_TypeUID);
      v20 = (UFG::GunComponent *)ComponentOfType;
      if ( ComponentOfType )
      {
        v21 = context->mSimObject.m_pPointer;
        if ( v21 )
        {
          v22 = v21->m_Flags;
          if ( (v22 & 0x4000) == 0 && v22 >= 0 )
          {
            if ( (v22 & 0x2000) != 0 )
            {
              v23 = (UFG::InventoryItemComponent *)v21->m_Components.p[11].m_pComponent;
            }
            else
            {
              v7 = (v22 & 0x1000) == 0;
              v24 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
              v25 = v7
                  ? UFG::SimObject::GetComponentOfType(v24, UFG::InventoryItemComponent::_TypeUID)
                  : UFG::SimObjectGame::GetComponentOfTypeHK(v24, UFG::InventoryItemComponent::_TypeUID);
              v23 = (UFG::InventoryItemComponent *)v25;
            }
            if ( v23 )
            {
              OwnerSimObject = (UFG::SimObjectGame *)UFG::InventoryItemComponent::GetOwnerSimObject(v23);
              if ( !OwnerSimObject )
                goto LABEL_70;
              v26 = v23->m_pOwnerInventoryComponent.m_pPointer;
              v27 = v26 && BYTE1(v26[14].m_pSimObject);
              if ( UFG::IsAnyLocalPlayer(OwnerSimObject) && v27 )
                v11 &= ~1u;
              v28 = OwnerSimObject->m_Flags;
              if ( (v28 & 0x4000) != 0 )
              {
                v29 = OwnerSimObject->m_Components.p[15].m_pComponent;
              }
              else if ( v28 >= 0 )
              {
                if ( (v28 & 0x2000) != 0 || (v28 & 0x1000) != 0 )
                  v29 = UFG::SimObjectGame::GetComponentOfTypeHK(OwnerSimObject, UFG::HitReactionComponent::_TypeUID);
                else
                  v29 = UFG::SimObject::GetComponentOfType(OwnerSimObject, UFG::HitReactionComponent::_TypeUID);
              }
              else
              {
                v29 = OwnerSimObject->m_Components.p[15].m_pComponent;
              }
              if ( v29 )
                v29[1].m_TypeUID = 0;
              if ( BYTE2(this->m_Track[1].m_TrackClassNameUID) )
              {
                if ( m_pComponent )
                {
                  v30 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[19].__vecDelDtor)(m_pComponent);
                  if ( v30 )
                    pSubTargetingLocation = *(UFG::SubTargetingLocation **)(v30 + 2736);
                }
                v31 = OwnerSimObject->m_Flags;
                if ( (v31 & 0x4000) != 0 )
                {
                  v6 = (UFG::AimingBaseComponent *)OwnerSimObject->m_Components.p[47].m_pComponent;
                }
                else
                {
                  if ( v31 < 0 || (v31 & 0x2000) != 0 || (v31 & 0x1000) != 0 )
                    v32 = UFG::SimObjectGame::GetComponentOfTypeHK(OwnerSimObject, UFG::AimingBaseComponent::_TypeUID);
                  else
                    v32 = UFG::SimObject::GetComponentOfType(OwnerSimObject, UFG::AimingBaseComponent::_TypeUID);
                  v6 = (UFG::AimingBaseComponent *)v32;
                }
              }
            }
          }
        }
        if ( OwnerSimObject )
        {
          v33 = this->m_Track;
          v34 = (unsigned __int64)v33[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64;
          v35 = (char *)&v33[1].mResourceOwner + v34;
          if ( !v34 )
            v35 = BinString::sEmptyString;
          originBoneId = UFG::qSymbolUC::create_from_string(&result, v35);
          UFG::GunComponent::Shoot(
            v20,
            OwnerSimObject,
            v6,
            v11,
            pSubTargetingLocation,
            pShootOriginSimObject,
            originBoneId);
          return;
        }
LABEL_70:
        UFG::GunComponent::Shoot(v20, v11);
      }
    }
  }
}

// File Line: 2786
// RVA: 0x2EA8E0
void __fastcall CharacterSetVisualDamageTask::Begin(CharacterSetVisualDamageTask *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v5; // rax
  UFG::CharacterAnimationComponent *v6; // rdi
  ITrack *m_Track; // rax
  unsigned int v8; // ebx
  float v9; // xmm6_4

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      v5 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else
    {
      v5 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  m_pPointer,
                                                  UFG::CharacterAnimationComponent::_TypeUID)
                                              : UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::CharacterAnimationComponent::_TypeUID));
    }
    v6 = v5;
    if ( v5 )
    {
      m_Track = this->m_Track;
      v8 = 0;
      v9 = *(float *)&m_Track[1].vfptr;
      do
      {
        UFG::CharacterAnimationComponent::SetVisualDamage(v6, v8, v9, 0.0);
        if ( v9 < 0.0099999998 )
          UFG::CharacterAnimationComponent::ApplyCharredEffect(v6, 0.0);
        ++v8;
      }
      while ( v8 < 0x1A );
    }
  }
}

// File Line: 2816
// RVA: 0x2F3170
void __fastcall ReloadGunTask::Begin(ReloadGunTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::GunComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rcx
  int vfptr_high; // edx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( (m_pPointer->m_Flags & 0x400) == 0 && m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      m_Track = this->m_Track;
      vfptr_high = -1;
      if ( LOBYTE(m_Track[1].vfptr) )
        vfptr_high = HIDWORD(m_Track[1].vfptr);
      UFG::GunComponent::Reload(ComponentOfTypeHK, vfptr_high);
    }
  }
}

// File Line: 2838
// RVA: 0x2F0060
void __fastcall MissionFailTriggerTask::Begin(MissionFailTriggerTask *this, ActionContext *pContext)
{
  ITrack *m_Track; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v9; // rdi
  UFG::CopSystem *v10; // rax

  m_Track = this->m_Track;
  this->m_pContext = pContext;
  if ( !HIDWORD(m_Track[1].vfptr) )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
      {
        v9 = *(_QWORD *)(56i64
                       * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr)
                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                            + 8i64)
                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                       + 40);
        if ( v9 )
        {
          v10 = UFG::CopSystem::Instance();
          ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, __int64))v10->vfptr[94].__vecDelDtor)(
            v10,
            pContext->mSimObject.m_pPointer,
            v9);
        }
      }
    }
  }
}

// File Line: 2863
// RVA: 0x2E8760
void __fastcall AimingFreeAimIntentionResetTask::Begin(AimingFreeAimIntentionResetTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::AimingPlayerComponent *v6; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      v6 = (UFG::AimingPlayerComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[16].__vecDelDtor)(m_pComponent);
      if ( v6 )
        UFG::AimingPlayerComponent::ResetFreeAimIntention(v6);
    }
  }
}

// File Line: 2878
// RVA: 0x2DD8B0
void __fastcall AimingSoftLockTask::AimingSoftLockTask(AimingSoftLockTask *this)
{
  this->Task<AimingSoftLockTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AimingSoftLockTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AimingSoftLockTrack>::`vftable;
  this->UFG::qNode<AimingSoftLockTask,AimingSoftLockList>::mPrev = &this->UFG::qNode<AimingSoftLockTask,AimingSoftLockList>;
  this->UFG::qNode<AimingSoftLockTask,AimingSoftLockList>::mNext = &this->UFG::qNode<AimingSoftLockTask,AimingSoftLockList>;
  this->vfptr = (ITaskVtbl *)&AimingSoftLockTask::`vftable;
}

// File Line: 2888
// RVA: 0x2E88A0
void __fastcall AimingSoftLockTask::Begin(AimingSoftLockTask *this, ActionContext *pActionContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::AimingPlayerComponent *v6; // rax

  this->m_pActionContext = pActionContext;
  m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pPointer = (UFG::SimObjectGame *)m_pPointer->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
      m_pPointer = (UFG::SimObjectGame *)ComponentOfTypeHK;
    }
  }
  v6 = (UFG::AimingPlayerComponent *)((__int64 (__fastcall *)(UFG::SimObjectGame *))m_pPointer->vfptr[16].__vecDelDtor)(m_pPointer);
  if ( v6 )
    UFG::AimingPlayerComponent::AddAimingSoftLockTask(v6, this);
}

// File Line: 2911
// RVA: 0x2DD820
void __fastcall AimingSoftLockDisableTask::AimingSoftLockDisableTask(AimingSoftLockDisableTask *this)
{
  this->Task<AimingSoftLockDisableTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AimingSoftLockDisableTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AimingSoftLockDisableTrack>::`vftable;
  this->UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList>::mPrev = &this->UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList>;
  this->UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList>::mNext = &this->UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList>;
  this->vfptr = (ITaskVtbl *)&AimingSoftLockDisableTask::`vftable;
}

// File Line: 2921
// RVA: 0x2E8800
void __fastcall AimingSoftLockDisableTask::Begin(AimingSoftLockDisableTask *this, ActionContext *pActionContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AimingBaseComponent *m_pComponent; // rax

  this->m_pActionContext = pActionContext;
  m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::AimingBaseComponent *)m_pPointer->m_Components.p[47].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::AimingBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::AimingBaseComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::AimingBaseComponent::AddAimingSoftLockDisableTask(m_pComponent, this);
  }
}

// File Line: 2943
// RVA: 0x2DD750
void __fastcall AimingFreeAimConeClampTask::AimingFreeAimConeClampTask(AimingFreeAimConeClampTask *this)
{
  this->Task<AimingFreeAimConeClampTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AimingFreeAimConeClampTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AimingFreeAimConeClampTrack>::`vftable;
  this->UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList>::mPrev = &this->UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList>;
  this->UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList>::mNext = &this->UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList>;
  this->vfptr = (ITaskVtbl *)&AimingFreeAimConeClampTask::`vftable;
}

// File Line: 2953
// RVA: 0x2E86B0
void __fastcall AimingFreeAimConeClampTask::Begin(AimingFreeAimConeClampTask *this, ActionContext *pActionContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::AimingPlayerComponent *v6; // rax

  this->m_pActionContext = pActionContext;
  m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pPointer = (UFG::SimObjectGame *)m_pPointer->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
      m_pPointer = (UFG::SimObjectGame *)ComponentOfTypeHK;
    }
  }
  v6 = (UFG::AimingPlayerComponent *)((__int64 (__fastcall *)(UFG::SimObjectGame *))m_pPointer->vfptr[16].__vecDelDtor)(m_pPointer);
  if ( v6 )
    UFG::AimingPlayerComponent::AddAimingFreeAimConeClampTask(v6, this);
}

// File Line: 2976
// RVA: 0x2E0390
void __fastcall PowerManagementSuspendPermanentlyTask::PowerManagementSuspendPermanentlyTask(
        PowerManagementSuspendPermanentlyTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<PowerManagementSuspendPermanentlyTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&PowerManagementSuspendPermanentlyTask::`vftable;
}

// File Line: 2986
// RVA: 0x2F2190
void __fastcall PowerManagementSuspendPermanentlyTask::Begin(
        PowerManagementSuspendPermanentlyTask *this,
        ActionContext *pActionContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::PowerManagementComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::PowerManagementComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::PowerManagementComponent::PermanentlySuspend(ComponentOfTypeHK);
  }
}

// File Line: 3000
// RVA: 0x2F0560
void __fastcall MotionIntentionHoldTask::Begin(MotionIntentionHoldTask *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      UFG::AICharacterControllerBaseComponent::HoldCurrentMotionIntention(ComponentOfTypeHK);
  }
}

// File Line: 3013
// RVA: 0x2E8B30
void __fastcall AttachmentTransferTask::Begin(AttachmentTransferTask *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // rbx
  int v7; // edi
  int BoneID; // esi

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer))
      : (m_Flags & 0x2000) == 0
      ? ((m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  m_pPointer,
                                                                  UFG::CharacterAnimationComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  m_pPointer,
                                                                  UFG::CharacterAnimationComponent::_TypeUID)))
      : (ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer)),
        ComponentOfType) )
  {
    mCreature = ComponentOfType->mCreature;
  }
  else
  {
    mCreature = 0i64;
  }
  if ( mCreature )
  {
    v7 = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, (unsigned int)this->m_Track[1].vfptr);
    else
      BoneID = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      v7 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, HIDWORD(this->m_Track[1].vfptr));
    if ( BoneID >= 0 && v7 >= 0 )
      Creature::TransferAttachment(mCreature, BoneID, v7, (UFG::qSymbolUC *)&this->m_Track[1].mResourceOwner);
  }
}

// File Line: 3038
// RVA: 0x2F1F10
void __fastcall PlaybackSpeedModifierEnabledTask::Begin(
        PlaybackSpeedModifierEnabledTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax

  this->mContext = pContext;
  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->mCreature->mPlaybackSpeedEnabled = 1;
  }
}

// File Line: 3050
// RVA: 0x2FF9E0
void __fastcall PlaybackSpeedModifierEnabledTask::End(PlaybackSpeedModifierEnabledTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->mCreature->mPlaybackSpeedEnabled = 0;
  }
}

// File Line: 3063
// RVA: 0x2EF480
void __fastcall HealthSetPercentageTask::Begin(HealthSetPercentageTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::HealthComponent *m_pComponent; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v12; // rsi
  UFG::CopSystem *v13; // rax
  __int16 v14; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::FaceMeterComponent *v16; // rcx
  bool v17; // zf
  UFG::SimObject *v18; // rax
  char v19; // [rsp+28h] [rbp-30h]
  UFG::FaceEventParameters parameters; // [rsp+30h] [rbp-28h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::HealthComponent *)m_pPointer->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID);
      m_pComponent = (UFG::HealthComponent *)v7;
    }
    else
    {
      m_pComponent = (UFG::HealthComponent *)m_pPointer->m_Components.p[6].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( UFG::HealthComponent::SetHealth(
             m_pComponent,
             (int)(float)((float)(*(float *)&this->m_Track[1].vfptr * 0.0099999998)
                        * (float)(int)m_pComponent->m_fMaxHealth),
             0i64) )
      {
        v8 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
        if ( v8 )
        {
          v9 = v8->m_Flags;
          if ( (v9 & 0x4000) != 0 )
          {
            v10 = v8->m_Components.p[15].m_pComponent;
          }
          else if ( v9 >= 0 )
          {
            if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::HitReactionComponent::_TypeUID);
            v10 = ComponentOfTypeHK;
          }
          else
          {
            v10 = v8->m_Components.p[15].m_pComponent;
          }
          if ( v10 )
          {
            v12 = *(UFG::SimObjectGame **)&v10[3].m_TypeUID;
            v13 = UFG::CopSystem::Instance();
            v19 = 1;
            ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObjectGame *, UFG::SimObject *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **, UFG::HealthComponent *, char))v13->vfptr[95].__vecDelDtor)(
              v13,
              v12,
              pContext->mSimObject.m_pPointer,
              &v10[2].m_BoundComponentHandles.mNode.mNext,
              m_pComponent,
              v19);
            if ( v12 )
            {
              v14 = v12->m_Flags;
              if ( (v14 & 0x4000) != 0 || v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
                ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::FaceMeterComponent::_TypeUID);
              else
                ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::FaceMeterComponent::_TypeUID);
              v16 = (UFG::FaceMeterComponent *)ComponentOfType;
              if ( ComponentOfType )
              {
                v17 = !m_pComponent->m_bIsKnockedOut;
                v18 = pContext->mSimObject.m_pPointer;
                parameters.mpPropertySet = 0i64;
                parameters.mpSimObject = v18;
                parameters.mIsApply = 1;
                parameters.mType = 109;
                if ( v17 )
                  parameters.mType = 108;
                UFG::FaceMeterComponent::ApplyEvent(v16, &parameters);
              }
            }
          }
        }
      }
    }
  }
}yEvent(v16, &parameters);
              }
          

// File Line: 3111
// RVA: 0x2EA9C0
void __fastcall CharacterStatModifyTask::Begin(CharacterStatModifyTask *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax

  this->m_pContext = pContext;
  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_CharacterStats[SLODWORD(this->m_Track[1].vfptr)].m_fStat = *((float *)&this->m_Track[1].vfptr
                                                                                      + 1)
                                                                                    + ComponentOfTypeHK->m_CharacterStats[SLODWORD(this->m_Track[1].vfptr)].m_fStat;
  }
}

// File Line: 3127
// RVA: 0x2FE5A0
void __fastcall CharacterStatModifyTask::End(CharacterStatModifyTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_CharacterStats[SLODWORD(this->m_Track[1].vfptr)].m_fStat = ComponentOfTypeHK->m_CharacterStats[SLODWORD(this->m_Track[1].vfptr)].m_fStat
                                                                                    - *((float *)&this->m_Track[1].vfptr
                                                                                      + 1);
  }
}

// File Line: 3144
// RVA: 0x2F0D60
void __fastcall ObjectReferenceTask::Begin(ObjectReferenceTask *this, ActionContext *pContext)
{
  UFG::qPropertySet *PropertySet; // rbp
  unsigned int mUID; // ebx
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  UFG::SimObjectGame *v9; // rcx
  UFG::qSymbol priority; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol *p_priority; // [rsp+60h] [rbp+18h]

  PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&this->m_Track[1]);
  if ( PropertySet )
  {
    mUID = qSymbol_Critical.mUID;
    m_pPointer = pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[7].m_pComponent;
        }
        else
        {
          v9 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
          if ( (m_Flags & 0x1000) != 0 )
            m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v9,
                                                               UFG::StreamedResourceComponent::_TypeUID);
          else
            m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                               v9,
                                                               UFG::StreamedResourceComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
      }
      if ( m_pComponent )
        mUID = UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64)->mUID;
    }
    p_priority = &priority;
    priority.mUID = mUID;
    UFG::MeshResourceLoader::Init(&this->mMeshLoader, PropertySet, (UFG::qSymbol)&priority, 0);
    UFG::MeshResourceLoader::PopulateTrueCrowdInstanceFromPropertySet(&this->mMeshLoader, 1);
    UFG::MeshResourceLoader::QueueLoad(&this->mMeshLoader);
  }
}

// File Line: 3173
// RVA: 0x2FF260
void __fastcall ObjectReferenceTask::End(ObjectReferenceTask *this)
{
  UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
}

// File Line: 3183
// RVA: 0x2F3790
void __fastcall SetOutOfFightTask::Begin(SetOutOfFightTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::ObjectiveTracker *p_mObjectiveTracker; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::AIScriptInterfaceComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
    }
    if ( m_pComponent )
    {
      LOBYTE(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev) ^= (LOBYTE(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev) ^ (32 * (LOBYTE(this->m_Track[1].vfptr) != 0))) & 0x20;
      if ( LOBYTE(this->m_Track[1].vfptr) )
      {
        UFG::SimObjectUtility::DetachHudSymbol(pContext->mSimObject.m_pPointer);
        p_mObjectiveTracker = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
        if ( p_mObjectiveTracker )
          UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
            p_mObjectiveTracker,
            &pContext->mSimObject.m_pPointer->m_Name,
            0);
      }
    }
  }
}

// File Line: 3210
// RVA: 0x2F20A0
void __fastcall PlayerGrappleTask::Begin(PlayerGrappleTask *this, ActionContext *pContext)
{
  UFG::RadarSystem *v2; // rax

  this->mContext = pContext;
  if ( UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer) )
  {
    v2 = UFG::RadarSystem::Instance();
    UFG::RadarSystem::SetInGrappleMode(v2, 1);
  }
}

// File Line: 3218
// RVA: 0x2FFA60
void __fastcall PlayerGrappleTask::End(PlayerGrappleTask *this)
{
  UFG::RadarSystem *v1; // rax

  if ( UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
  {
    v1 = UFG::RadarSystem::Instance();
    UFG::RadarSystem::SetInGrappleMode(v1, 0);
  }
}

// File Line: 3227
// RVA: 0x2F4CA0
void __fastcall StruggleTask::Begin(StruggleTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            m_pPointer,
                            UFG::SimObjectSignalMemoryComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK[1].m_TypeUID = 1056964608;
  }
}

// File Line: 3240
// RVA: 0x30A3D0
char __fastcall StruggleTask::Update(StruggleTask *this, float timeDelta)
{
  bool v3; // zf
  UFG::SimObjectGame *m_pPointer; // rcx
  bool v5; // si
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v8; // rbx
  UFG::SimObjectCVBase *v9; // rcx
  __int16 v10; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfType; // rax
  UFG::AICharacterControllerBaseComponent *v12; // rdx
  unsigned __int64 v13; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4

  v3 = BYTE4(this->m_Track[1].vfptr) == 0;
  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  v5 = !v3;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            m_pPointer,
                            UFG::SimObjectSignalMemoryComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    v8 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      v9 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
      if ( v9
        && ((v10 = v9->m_Flags, (v10 & 0x4000) != 0) || v10 < 0
          ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v9))
          : (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0
          ? (ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            v9,
                                                                            UFG::AICharacterControllerBaseComponent::_TypeUID))
          : (ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                            v9,
                                                                            UFG::AICharacterControllerBaseComponent::_TypeUID)),
            (v12 = ComponentOfType) != 0i64
         && (v13 = ComponentOfType->m_Intention.mActionRequests.mBits[(__int64)(int)gActionRequest_Action.m_EnumValue >> 6],
             _bittest64((const __int64 *)&v13, gActionRequest_Action.m_EnumValue & 0x3F))
         && !v12->m_Intention.mActionRequestChargeTimes[gActionRequest_Action.m_EnumValue]) )
      {
        v14 = sStruggleIncFact * *(float *)&this->m_Track[1].vfptr;
        if ( !v5 )
        {
          *(float *)&v8[1].m_TypeUID = v14 + *(float *)&v8[1].m_TypeUID;
          goto LABEL_26;
        }
      }
      else
      {
        v14 = sStruggleDecFact * *(float *)&this->m_Track[1].vfptr;
        if ( v5 )
        {
          *(float *)&v8[1].m_TypeUID = v14 + *(float *)&v8[1].m_TypeUID;
          goto LABEL_26;
        }
      }
      *(float *)&v8[1].m_TypeUID = *(float *)&v8[1].m_TypeUID - v14;
LABEL_26:
      v15 = *(float *)&v8[1].m_TypeUID;
      if ( v15 <= 0.0 )
      {
        v15 = 0.0;
      }
      else
      {
        v16 = *(float *)&FLOAT_1_0;
        if ( v15 >= 1.0 )
          goto LABEL_31;
      }
      v16 = v15;
LABEL_31:
      *(float *)&v8[1].m_TypeUID = v16;
    }
  }
  return 1;
}

// File Line: 3296
// RVA: 0x2F4C60
void __fastcall Struggle2Task::Begin(Struggle2Task *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  float v3; // xmm0_4
  ITaskVtbl *vfptr; // rax

  m_Track = this->m_Track;
  this->mContext = context;
  this->mValueCurrentTime = -1.0;
  this->mValueLastTime = -1.0;
  v3 = (float)(*(float *)&m_Track[1].mResourceOwner * 0.5) + *((float *)&m_Track[1].vfptr + 1);
  vfptr = this->vfptr;
  this->mCurrentStruggle = v3;
  ((void (*)(void))vfptr->Update)();
}

// File Line: 3315
// RVA: 0x30A190
char __fastcall Struggle2Task::Update(Struggle2Task *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObjectCVBase *v8; // rcx
  __int16 v9; // dx
  UFG::AICharacterControllerBaseComponent *v10; // rax
  UFG::AICharacterControllerBaseComponent *v11; // rdx
  ITrack *m_Track; // r9
  unsigned __int64 v13; // rax
  float v14; // eax
  float mValueCurrentTime; // xmm0_4
  float v16; // xmm1_4
  float mValueLastTime; // xmm0_4
  float mCurrentStruggle; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm1_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            m_pPointer,
                            UFG::SimObjectSignalMemoryComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    v7 = ComponentOfTypeHK;
    if ( !ComponentOfTypeHK )
      return 1;
    v8 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    if ( !v8 )
      return 1;
    v9 = v8->m_Flags;
    if ( (v9 & 0x4000) != 0 || v9 < 0 )
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
    else
      v10 = (UFG::AICharacterControllerBaseComponent *)((v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
                                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v8,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                      : UFG::SimObject::GetComponentOfType(
                                                          v8,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID));
    v11 = v10;
    if ( !v10 )
      return 1;
    m_Track = this->m_Track;
    v13 = v10->m_Intention.mActionRequests.mBits[(__int64)SLOWORD(m_Track[1].vfptr) >> 6];
    if ( !_bittest64((const __int64 *)&v13, (__int64)m_Track[1].vfptr & 0x3F)
      || v11->m_Intention.mActionRequestChargeTimes[SLOWORD(m_Track[1].vfptr)] )
    {
      mValueCurrentTime = this->mValueCurrentTime;
      if ( mValueCurrentTime >= 0.0 )
        this->mValueCurrentTime = mValueCurrentTime + timeDelta;
    }
    else
    {
      v14 = this->mValueCurrentTime;
      this->mValueCurrentTime = timeDelta;
      this->mValueLastTime = v14;
    }
    v16 = this->mValueCurrentTime;
    if ( v16 > 0.0 )
    {
      mValueLastTime = this->mValueLastTime;
      if ( mValueLastTime > 0.0 )
      {
        this->mCurrentStruggle = (float)(mValueLastTime + v16) * 0.5;
LABEL_30:
        mCurrentStruggle = this->mCurrentStruggle;
        if ( mCurrentStruggle <= 0.0
          || ((v19 = *(float *)&m_Track[1].mResourceOwner,
               v20 = *((float *)&m_Track[1].vfptr + 1),
               v21 = *(float *)&FLOAT_1_0,
               v19 <= 0.0)
            ? (v22 = v20 / mCurrentStruggle)
            : (v22 = (float)((float)(v19 + v20) * (float)(1.0 / v19)) - (float)((float)(1.0 / v19) * mCurrentStruggle)),
              v22 <= 0.0) )
        {
          v22 = 0.0;
        }
        else if ( v22 >= 1.0 )
        {
          goto LABEL_39;
        }
        v21 = v22;
LABEL_39:
        *(float *)&v7[1].m_TypeUID = (float)(v21 - 0.5) * 2.0;
        return 1;
      }
      if ( v16 > 0.0 )
      {
        this->mCurrentStruggle = v16;
        goto LABEL_30;
      }
    }
    this->mCurrentStruggle = timeDelta + this->mCurrentStruggle;
    goto LABEL_30;
  }
  return 1;
}

// File Line: 3404
// RVA: 0x2DD6B0
void __fastcall ActorStateCounterTask::ActorStateCounterTask(ActorStateCounterTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ActorStateCounterTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ActorStateCounterTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 3414
// RVA: 0x2E8080
void __fastcall ActorStateCounterTask::Begin(ActorStateCounterTask *this, ActionContext *action_context)
{
  ITrack *m_Track; // rax

  m_Track = this->m_Track;
  this->m_pActionContext = action_context;
  UFG::AudioGameState::sm_counters[LOBYTE(m_Track[1].vfptr)] = UFG::AudioGameState::sm_counters[LOBYTE(m_Track[1].vfptr)]
                                                             + 1.0;
}

// File Line: 3426
// RVA: 0x2FDDE0
void __fastcall ActorStateCounterTask::End(ActorStateCounterTask *this)
{
  __int64 vfptr_low; // rax

  vfptr_low = LOBYTE(this->m_Track[1].vfptr);
  UFG::AudioGameState::sm_counters[vfptr_low] = UFG::AudioGameState::sm_counters[vfptr_low] - 1.0;
}

// File Line: 3436
// RVA: 0x2DF560
void __fastcall GameStatEventTask::GameStatEventTask(GameStatEventTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<GameStatEventTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&GameStatEventTask::`vftable;
}

// File Line: 3444
// RVA: 0x2EE3B0
void __fastcall GameStatEventTask::Begin(GameStatEventTask *this, ActionContext *action_context)
{
  ITrack *m_Track; // rdx
  int vfptr; // edi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // r9
  UFG::SimObject *m_pPointer; // r8
  const char *mName; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v10; // rax

  m_Track = this->m_Track;
  if ( !BYTE4(m_Track[1].vfptr) || LocalPlayer == action_context->mSimObject.m_pPointer )
  {
    vfptr = (int)m_Track[1].vfptr;
    v5 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
    v6 = v5;
    if ( v5 )
    {
      m_pPointer = action_context->mSimObject.m_pPointer;
      mName = UFG::gGameStatEventChannel.mName;
      mUID = UFG::gGameStatEventChannel.mUID;
      v10 = v5 + 1;
      v10->mNext = v10;
      v10[1].mNext = v10;
      v6->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
      LODWORD(v6[3].mNext) = mUID;
      v6[4].mNext = (UFG::allocator::free_link *)mName;
      v6->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
      LODWORD(v6[7].mNext) = vfptr;
      v6[8].mNext = (UFG::allocator::free_link *)m_pPointer;
    }
    else
    {
      v6 = 0i64;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v6);
  }
}

// File Line: 3462
// RVA: 0x304590
char __fastcall GameStatDistanceTask::Update(GameStatDistanceTask *this, float timestep)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 y_low; // xmm1
  UFG::GameStatTracker *v7; // rax

  if ( LOBYTE(this->m_Track[1].vfptr) && LocalPlayer != this->m_pActionContext->mSimObject.m_pPointer )
    return 0;
  m_pPointer = this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldVelocity.y);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                    + (float)(m_pTransformNodeComponent->mWorldVelocity.x * m_pTransformNodeComponent->mWorldVelocity.x);
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v7, TotalDistanceWalked, (float)(_mm_sqrt_ps(y_low).m128_f32[0] * timestep) * 0.001);
  return 1;
}

// File Line: 3481
// RVA: 0x2EE460
void __fastcall GameStatSpecialMoveTask::Begin(GameStatSpecialMoveTask *this, ActionContext *action_context)
{
  ActionNodePlayable *m_currentNode; // rcx
  __int64 v4; // rax
  UFG::OSuiteLeaderboardManager *v5; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::SimObjectGame *Target; // rbx
  __int16 m_Flags; // cx
  UFG::HealthComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // r9
  UFG::SimObject *v13; // r8
  const char *v14; // rdx
  unsigned int v15; // ecx
  UFG::allocator::free_link *v16; // rax
  UFG::CopSystem *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // r9
  UFG::SimObject *m_pPointer; // r8
  const char *mName; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v23; // rax
  UFG::CopSystem *v24; // rax
  UFG::CopSystem *v25; // rax
  UFG::qSymbol path; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol *pIsCop; // [rsp+60h] [rbp+18h] BYREF
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+20h] BYREF

  if ( !LOBYTE(this->m_Track[1].vfptr) || LocalPlayer == action_context->mSimObject.m_pPointer )
  {
    m_currentNode = action_context->mActionController->m_currentNode;
    if ( m_currentNode )
    {
      v4 = ((__int64 (__fastcall *)(ActionNodePlayable *))m_currentNode->vfptr[1].SetResourceOwner)(m_currentNode);
      if ( v4 )
      {
        if ( action_context->mSimObject.m_pPointer != LocalPlayer )
        {
          UFG::qSymbol::qSymbol(&result, *(_DWORD *)(v4 + 40));
          pIsCop = &path;
          path.mUID = result.mUID;
          UFG::GameStatAction::Player::RecordSpecialMove((UFG::qSymbol)&path);
          v5 = UFG::OSuiteLeaderboardManager::Instance();
          LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                  v5,
                                                  "StatAwardsEnvironmentalist");
          UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, 1);
          Target = (UFG::SimObjectGame *)UFG::getTarget(LocalPlayer, eTARGET_TYPE_LAST_GRAPPLE);
          if ( Target || (Target = (UFG::SimObjectGame *)UFG::getTarget(LocalPlayer, eTARGET_TYPE_GRAPPLE)) != 0i64 )
          {
            m_Flags = Target->m_Flags;
            if ( (m_Flags & 0x4000) != 0 )
            {
              m_pComponent = (UFG::HealthComponent *)Target->m_Components.p[6].m_pComponent;
            }
            else if ( m_Flags >= 0 )
            {
              if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::HealthComponent::_TypeUID);
              else
                ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(Target, UFG::HealthComponent::_TypeUID);
              m_pComponent = (UFG::HealthComponent *)ComponentOfTypeHK;
            }
            else
            {
              m_pComponent = (UFG::HealthComponent *)Target->m_Components.p[6].m_pComponent;
            }
            LOBYTE(pIsCop) = 0;
            LOBYTE(path.mUID) = 0;
            UFG::GameStatAction::MissionScoring::DeduceFaction(Target, (bool *)&pIsCop, (bool *)&path);
            if ( LOBYTE(path.mUID) )
            {
              if ( m_pComponent )
              {
                if ( m_pComponent->m_bIsKnockedOut || UFG::HealthComponent::GetIsKilled(m_pComponent) )
                {
                  v18 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
                  v19 = v18;
                  if ( v18 )
                  {
                    m_pPointer = action_context->mSimObject.m_pPointer;
                    mName = UFG::gGameStatEventChannel.mName;
                    mUID = UFG::gGameStatEventChannel.mUID;
                    v23 = v18 + 1;
                    v23->mNext = v23;
                    v23[1].mNext = v23;
                    v19->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
                    LODWORD(v19[3].mNext) = mUID;
                    v19[4].mNext = (UFG::allocator::free_link *)mName;
                    v19->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
                    LODWORD(v19[7].mNext) = 59;
                    v19[8].mNext = (UFG::allocator::free_link *)m_pPointer;
                  }
                  else
                  {
                    v19 = 0i64;
                  }
                  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v19);
                  UFG::GameStatAction::MissionScoring::LogCopEvent(COP_PEDESTRIAN_KILL, 0, &customCaption);
                  v24 = UFG::CopSystem::Instance();
                  v24->vfptr[111].__vecDelDtor(v24, 6u);
                }
                else
                {
                  v11 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
                  v12 = v11;
                  if ( v11 )
                  {
                    v13 = action_context->mSimObject.m_pPointer;
                    v14 = UFG::gGameStatEventChannel.mName;
                    v15 = UFG::gGameStatEventChannel.mUID;
                    v16 = v11 + 1;
                    v16->mNext = v16;
                    v16[1].mNext = v16;
                    v12->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
                    LODWORD(v12[3].mNext) = v15;
                    v12[4].mNext = (UFG::allocator::free_link *)v14;
                    v12->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
                    LODWORD(v12[7].mNext) = 28;
                    v12[8].mNext = (UFG::allocator::free_link *)v13;
                  }
                  else
                  {
                    v12 = 0i64;
                  }
                  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v12);
                  UFG::GameStatAction::MissionScoring::LogCopEvent(COP_PEDESTRIAN_HIT, 0, &customCaption);
                  v17 = UFG::CopSystem::Instance();
                  v17->vfptr[111].__vecDelDtor(v17, 2u);
                }
              }
            }
            else if ( (_BYTE)pIsCop )
            {
              UFG::GameStatAction::MissionScoring::LogCopEvent(COP_KILL, 0, &customCaption);
              v25 = UFG::CopSystem::Instance();
              v25->vfptr[111].__vecDelDtor(v25, 7u);
            }
            else
            {
              UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_KILL_ENVIRONMENTAL, 0, &customCaption);
            }
          }
        }
      }
    }
  }
}

// File Line: 3565
// RVA: 0x2F2B80
void __fastcall CarOccupantsActionTask::Begin(TargetFocusOverrideTask *this, ActionContext *pContext)
{
  ITaskVtbl *vfptr; // rax

  vfptr = this->vfptr;
  this->m_pContext = pContext;
  ((void (*)(void))vfptr->Update)();
}

// File Line: 3573
// RVA: 0x3039C0
char __fastcall AccuracyOverrideTask::Update(AccuracyOverrideTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v6; // rax
  ITrack *m_Track; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[47].m_pComponent;
    }
    else
    {
      v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AimingBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      if ( BYTE4(m_Track[1].vfptr) )
      {
        HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mPrev) = 1056964608;
        return 1;
      }
      HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mPrev) = m_Track[1].vfptr;
    }
  }
  return 1;
}

// File Line: 3593
// RVA: 0x2FDD50
void __fastcall AccuracyOverrideTask::End(AccuracyOverrideTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[47].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( m_pComponent )
      HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mPrev) = -1082130432;
  }
}

// File Line: 3606
// RVA: 0x2E7F50
void __fastcall AccuracyEnsureMissTask::Begin(AccuracyEnsureMissTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  this->m_pContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[47].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( m_pComponent )
      LOBYTE(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) = 1;
  }
}

// File Line: 3618
// RVA: 0x2FDCC0
void __fastcall AccuracyEnsureMissTask::End(AccuracyEnsureMissTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[47].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( m_pComponent )
      LOBYTE(m_pComponent[2].m_BoundComponentHandles.mNode.mNext) = 0;
  }
}

// File Line: 3631
// RVA: 0x2F3320
void __fastcall ReticleSizeOverrideTask::Begin(ReticleSizeOverrideTask *this, ActionContext *pContext)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::AimingPlayerComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AimingPlayerComponent> *p_m_AimingPlayerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rdx

  m_pPointer = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(m_pPointer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::AimingPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::AimingPlayerComponent::_TypeUID);
    }
    v4 = ComponentOfTypeHK;
  }
  else
  {
    v4 = 0i64;
  }
  p_m_AimingPlayerComponent = &this->m_AimingPlayerComponent;
  if ( this->m_AimingPlayerComponent.m_pPointer )
  {
    mPrev = p_m_AimingPlayerComponent->mPrev;
    mNext = this->m_AimingPlayerComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_AimingPlayerComponent->mPrev = p_m_AimingPlayerComponent;
    this->m_AimingPlayerComponent.mNext = &this->m_AimingPlayerComponent;
  }
  this->m_AimingPlayerComponent.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_m_AimingPlayerComponent;
    p_m_AimingPlayerComponent->mPrev = v10;
    this->m_AimingPlayerComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = p_m_AimingPlayerComponent;
  }
  v11 = this->m_AimingPlayerComponent.m_pPointer;
  if ( v11 )
    LODWORD(v11[7].m_BoundComponentHandles.mNode.mPrev) = this->m_Track[1].vfptr;
}

// File Line: 3640
// RVA: 0x300100
void __fastcall ReticleSizeOverrideTask::End(ReticleSizeOverrideTask *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->m_AimingPlayerComponent.m_pPointer;
  if ( m_pPointer )
    LODWORD(m_pPointer[7].m_BoundComponentHandles.mNode.mPrev) = -1082130432;
}

// File Line: 3662
// RVA: 0x2FE4A0
void __fastcall CharacterStatModifyIntTask::End(CharacterStatModifyIntTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  int *m_Track; // rdx
  int v6; // r8d
  int v7; // r8d

  m_pPointer = (UFG::SimObjectCVBase *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
    {
      m_Track = (int *)this->m_Track;
      v6 = m_Track[15];
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( v7 )
        {
          if ( v7 == 1 )
            ComponentOfTypeHK->m_CharacterStats[m_Track[14]].m_fStat = (float)m_Track[16];
        }
        else
        {
          ComponentOfTypeHK->m_CharacterStats[m_Track[14]].m_fStat = (float)m_Track[16]
                                                                   * ComponentOfTypeHK->m_CharacterStats[m_Track[14]].m_fStat;
        }
      }
      else
      {
        ComponentOfTypeHK->m_CharacterStats[m_Track[14]].m_fStat = (float)m_Track[16]
                                                                 + ComponentOfTypeHK->m_CharacterStats[m_Track[14]].m_fStat;
      }
    }
  }
}

// File Line: 3693
// RVA: 0x2F05E0
void __fastcall MotionIntentionSetRelativeToPlayerTask::Begin(
        MotionIntentionSetRelativeToPlayerTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   m_pPointer,
                                                                   UFG::AICharacterControllerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::AICharacterControllerComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_PlayerRelativeMotionIntention = LOBYTE(this->m_Track[1].vfptr) != 0;
  }
}

// File Line: 3704
// RVA: 0x2EE860
void __fastcall GunConsumeAmmoTask::Begin(GunConsumeAmmoTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::GunComponent *ComponentOfTypeHK; // rax
  UFG::GunComponent *v6; // rbx
  int ClipAmmo; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::GunComponent::_TypeUID);
    v6 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      ClipAmmo = UFG::GunComponent::GetClipAmmo(ComponentOfTypeHK);
      UFG::GunComponent::SetClipAmmo(v6, ClipAmmo - LODWORD(this->m_Track[1].vfptr));
    }
  }
}

// File Line: 3723
// RVA: 0x2F3900
void __fastcall SetStateFlagTask::Begin(SetStateFlagTask *this, ActionContext *context)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *p_m_pSOCPC; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimComponent *v14; // rdx

  p_m_pSOCPC = &this->m_pSOCPC;
  if ( this->m_pSOCPC.m_pPointer )
  {
    mPrev = p_m_pSOCPC->mPrev;
    mNext = this->m_pSOCPC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pSOCPC->mPrev = p_m_pSOCPC;
    this->m_pSOCPC.mNext = &this->m_pSOCPC;
  }
  this->m_pSOCPC.m_pPointer = 0i64;
  this->m_pContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[3].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[4].m_pComponent;
      }
      else
      {
        v10 = (m_Flags & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::SimObjectPropertiesComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SimObjectPropertiesComponent::_TypeUID);
        m_pComponent = v10;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[3].m_pComponent;
    }
    if ( m_pComponent && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 1 )
    {
      if ( p_m_pSOCPC->m_pPointer )
      {
        v11 = p_m_pSOCPC->mPrev;
        v12 = p_m_pSOCPC->mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        p_m_pSOCPC->mPrev = p_m_pSOCPC;
        p_m_pSOCPC->mNext = p_m_pSOCPC;
      }
      p_m_pSOCPC->m_pPointer = m_pComponent;
      v13 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v13->mNext = p_m_pSOCPC;
      p_m_pSOCPC->mPrev = v13;
      p_m_pSOCPC->mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pSOCPC;
      v14 = this->m_pSOCPC.m_pPointer;
      if ( v14 )
      {
        if ( context->mActionController )
          *((_BYTE *)&v14[2].m_BoundComponentHandles.mNode.mPrev + SLODWORD(this->m_Track[1].vfptr) + 1) = 1;
      }
    }
  }
}

// File Line: 3739
// RVA: 0x300230
void __fastcall SetStateFlagTask::End(SetStateFlagTask *this)
{
  UFG::SimComponent *m_pPointer; // rdx

  m_pPointer = this->m_pSOCPC.m_pPointer;
  if ( m_pPointer )
    *((_BYTE *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + SLODWORD(this->m_Track[1].vfptr) + 1) = 0;
}

// File Line: 3776
// RVA: 0x30CE80
void __fastcall drawStickDValue(float *values, int valueCount, UFG::qColour *colour)
{
  __int64 v5; // rbx
  float v6; // xmm6_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  __int64 v9; // rsi
  float i; // xmm9_4
  float v11; // xmm1_4
  Render::DebugDrawContext *Context; // rax
  UFG::qVector3 p1; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 p0; // [rsp+50h] [rbp-58h] BYREF

  v5 = 0i64;
  v6 = sDrawDebugH * 0.5;
  v7 = sDrawDebugOrgX;
  v8 = sDrawDebugOrgY + (float)(sDrawDebugH * 0.5);
  v9 = valueCount - 1;
  for ( i = sDrawDebugW * 0.0099999998; v5 < v9; ++v5 )
  {
    p0.x = v7;
    p0.z = 0.0;
    p1.z = 0.0;
    v11 = (float)(v6 * values[v5 + 1]) + v8;
    p0.y = (float)(v6 * values[v5]) + v8;
    p1.y = v11;
    v7 = i + v7;
    p1.x = v7;
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawLine(Context, &p0, &p1, colour, 0i64, 0i64, 0);
  }
}

// File Line: 3797
// RVA: 0x30CFC0
void drawStickValues(void)
{
  UFG::qColour v0; // [rsp+30h] [rbp-78h] BYREF
  UFG::qColour v1; // [rsp+40h] [rbp-68h] BYREF
  UFG::qColour v2; // [rsp+50h] [rbp-58h] BYREF
  UFG::qColour v3; // [rsp+60h] [rbp-48h] BYREF
  UFG::qColour v4; // [rsp+70h] [rbp-38h] BYREF
  UFG::qColour v5; // [rsp+80h] [rbp-28h] BYREF
  UFG::qColour v6; // [rsp+90h] [rbp-18h] BYREF

  if ( sDrawDebug )
  {
    v0 = UFG::qColour::Green;
    UFG::DrawBoxScreenSpace(sDrawDebugOrgX, sDrawDebugOrgY, sDrawDebugH, sDrawDebugW, &v0);
    v1 = UFG::qColour::Blue;
    drawStickDValue(gValues0, 100, &v1);
    v2 = UFG::qColour::Red;
    drawStickDValue(gValues1, 100, &v2);
    v3 = UFG::qColour::Grey;
    drawStickDValue(gValues2, 100, &v3);
    v4 = UFG::qColour::Yellow;
    drawStickDValue(gValues3, 100, &v4);
    v5 = UFG::qColour::Green;
    drawStickDValue(gValues4, 100, &v5);
    v6 = UFG::qColour::White;
    drawStickDValue(gValues5, 100, &v6);
  }
}

// File Line: 3814
// RVA: 0x149ED90
__int64 dynamic_initializer_for__sJogActionReq__()
{
  __int64 result; // rax

  result = gActionRequest_Jog.m_EnumValue;
  sJogActionReq = gActionRequest_Jog.m_EnumValue;
  return result;
}

// File Line: 3815
// RVA: 0x149EDA0
__int64 dynamic_initializer_for__sWalkActionReq__()
{
  __int64 result; // rax

  result = gActionRequest_Walk.m_EnumValue;
  sWalkActionReq = gActionRequest_Walk.m_EnumValue;
  return result;
}

// File Line: 3818
// RVA: 0x2E0B80
void __fastcall ReadControllerInputTask::ReadControllerInputTask(ReadControllerInputTask *this)
{
  float y; // xmm1_4

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ReadControllerInputTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ReadControllerInputTask::`vftable;
  this->m_pAICharacterControllerComponent.mPrev = &this->m_pAICharacterControllerComponent;
  this->m_pAICharacterControllerComponent.mNext = &this->m_pAICharacterControllerComponent;
  this->m_pAICharacterControllerComponent.m_pPointer = 0i64;
  this->m_pAimingBaseComponent.mPrev = &this->m_pAimingBaseComponent;
  this->m_pAimingBaseComponent.mNext = &this->m_pAimingBaseComponent;
  this->m_pAimingBaseComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemPedPlayerComponent.mPrev = &this->m_pTargetingSystemPedPlayerComponent;
  this->m_pTargetingSystemPedPlayerComponent.mNext = &this->m_pTargetingSystemPedPlayerComponent;
  this->m_pTargetingSystemPedPlayerComponent.m_pPointer = 0i64;
  this->m_pContext = 0i64;
  y = UFG::qVector2::msZero.y;
  this->mLockedPadModified.x = UFG::qVector2::msZero.x;
  this->mLockedPadModified.y = y;
}

// File Line: 3824
// RVA: 0x2E4C90
void __fastcall ReadControllerInputTask::~ReadControllerInputTask(ReadControllerInputTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedPlayerComponent> *p_m_pTargetingSystemPedPlayerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AimingBaseComponent> *p_m_pAimingBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerComponent> *p_m_pAICharacterControllerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&ReadControllerInputTask::`vftable;
  p_m_pTargetingSystemPedPlayerComponent = &this->m_pTargetingSystemPedPlayerComponent;
  if ( this->m_pTargetingSystemPedPlayerComponent.m_pPointer )
  {
    mPrev = p_m_pTargetingSystemPedPlayerComponent->mPrev;
    mNext = p_m_pTargetingSystemPedPlayerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemPedPlayerComponent->mPrev = p_m_pTargetingSystemPedPlayerComponent;
    p_m_pTargetingSystemPedPlayerComponent->mNext = p_m_pTargetingSystemPedPlayerComponent;
  }
  p_m_pTargetingSystemPedPlayerComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetingSystemPedPlayerComponent->mPrev;
  v6 = p_m_pTargetingSystemPedPlayerComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetingSystemPedPlayerComponent->mPrev = p_m_pTargetingSystemPedPlayerComponent;
  p_m_pTargetingSystemPedPlayerComponent->mNext = p_m_pTargetingSystemPedPlayerComponent;
  p_m_pAimingBaseComponent = &this->m_pAimingBaseComponent;
  if ( this->m_pAimingBaseComponent.m_pPointer )
  {
    v8 = p_m_pAimingBaseComponent->mPrev;
    v9 = this->m_pAimingBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pAimingBaseComponent->mPrev = p_m_pAimingBaseComponent;
    this->m_pAimingBaseComponent.mNext = &this->m_pAimingBaseComponent;
  }
  this->m_pAimingBaseComponent.m_pPointer = 0i64;
  v10 = p_m_pAimingBaseComponent->mPrev;
  v11 = this->m_pAimingBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pAimingBaseComponent->mPrev = p_m_pAimingBaseComponent;
  this->m_pAimingBaseComponent.mNext = &this->m_pAimingBaseComponent;
  p_m_pAICharacterControllerComponent = &this->m_pAICharacterControllerComponent;
  if ( this->m_pAICharacterControllerComponent.m_pPointer )
  {
    v13 = p_m_pAICharacterControllerComponent->mPrev;
    v14 = this->m_pAICharacterControllerComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pAICharacterControllerComponent->mPrev = p_m_pAICharacterControllerComponent;
    this->m_pAICharacterControllerComponent.mNext = &this->m_pAICharacterControllerComponent;
  }
  this->m_pAICharacterControllerComponent.m_pPointer = 0i64;
  v15 = p_m_pAICharacterControllerComponent->mPrev;
  v16 = this->m_pAICharacterControllerComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pAICharacterControllerComponent->mPrev = p_m_pAICharacterControllerComponent;
  this->m_pAICharacterControllerComponent.mNext = &this->m_pAICharacterControllerComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 3829
// RVA: 0x2F2F30
void __fastcall ReadControllerInputTask::Begin(ReadControllerInputTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // r8
  __int16 m_Flags; // dx
  UFG::AICharacterControllerComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerComponent> *p_m_pAICharacterControllerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectCVBase *v13; // rcx
  UFG::SimComponent *v14; // r8
  __int16 v15; // dx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedPlayerComponent> *p_m_pTargetingSystemPedPlayerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AimingBaseComponent> *p_m_pAimingBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax

  this->m_pContext = context;
  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  m_pComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   m_pPointer,
                                                                   UFG::AICharacterControllerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::AICharacterControllerComponent::_TypeUID);
    }
    v6 = ComponentOfTypeHK;
  }
  else
  {
    v6 = 0i64;
  }
  p_m_pAICharacterControllerComponent = &this->m_pAICharacterControllerComponent;
  if ( this->m_pAICharacterControllerComponent.m_pPointer )
  {
    mPrev = p_m_pAICharacterControllerComponent->mPrev;
    mNext = this->m_pAICharacterControllerComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAICharacterControllerComponent->mPrev = p_m_pAICharacterControllerComponent;
    this->m_pAICharacterControllerComponent.mNext = &this->m_pAICharacterControllerComponent;
  }
  this->m_pAICharacterControllerComponent.m_pPointer = v6;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = p_m_pAICharacterControllerComponent;
    p_m_pAICharacterControllerComponent->mPrev = v12;
    this->m_pAICharacterControllerComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = p_m_pAICharacterControllerComponent;
  }
  v13 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v13 )
  {
    v15 = v13->m_Flags;
    if ( (v15 & 0x4000) != 0 || v15 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v13);
    }
    else if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v13,
                                                                    UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                    v13,
                                                                    UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
    v14 = ComponentOfType;
  }
  else
  {
    v14 = 0i64;
  }
  p_m_pTargetingSystemPedPlayerComponent = &this->m_pTargetingSystemPedPlayerComponent;
  if ( this->m_pTargetingSystemPedPlayerComponent.m_pPointer )
  {
    v18 = p_m_pTargetingSystemPedPlayerComponent->mPrev;
    v19 = this->m_pTargetingSystemPedPlayerComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pTargetingSystemPedPlayerComponent->mPrev = p_m_pTargetingSystemPedPlayerComponent;
    this->m_pTargetingSystemPedPlayerComponent.mNext = &this->m_pTargetingSystemPedPlayerComponent;
  }
  this->m_pTargetingSystemPedPlayerComponent.m_pPointer = v14;
  if ( v14 )
  {
    v20 = v14->m_SafePointerList.mNode.mPrev;
    v20->mNext = p_m_pTargetingSystemPedPlayerComponent;
    p_m_pTargetingSystemPedPlayerComponent->mPrev = v20;
    this->m_pTargetingSystemPedPlayerComponent.mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemPedPlayerComponent;
  }
  v21 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v21 )
  {
    v22 = v21->m_Flags;
    if ( (v22 & 0x4000) != 0 )
    {
      m_pComponent = v21->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AimingBaseComponent::_TypeUID);
      else
        v23 = UFG::SimObject::GetComponentOfType(v21, UFG::AimingBaseComponent::_TypeUID);
      m_pComponent = v23;
    }
  }
  p_m_pAimingBaseComponent = &this->m_pAimingBaseComponent;
  if ( this->m_pAimingBaseComponent.m_pPointer )
  {
    v25 = p_m_pAimingBaseComponent->mPrev;
    v26 = this->m_pAimingBaseComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    p_m_pAimingBaseComponent->mPrev = p_m_pAimingBaseComponent;
    this->m_pAimingBaseComponent.mNext = &this->m_pAimingBaseComponent;
  }
  this->m_pAimingBaseComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v27 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v27->mNext = p_m_pAimingBaseComponent;
    p_m_pAimingBaseComponent->mPrev = v27;
    this->m_pAimingBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pAimingBaseComponent;
  }
}

// File Line: 3837
// RVA: 0x307EC0
char __fastcall ReadControllerInputTask::Update(ReadControllerInputTask *this, float timeDelta)
{
  ActionContext *m_pContext; // rax
  float v4; // xmm12_4
  UFG::ActiveAIEntityComponent *v5; // r13
  Intention *p_m_Intention; // r15
  UFG::AICharacterControllerComponent *m_pPointer; // rax
  int m_ControllerID; // ebx
  UFG::Controller *v9; // rax
  bool m_IsKeyboardController; // r12
  UFG::InputActionData *v11; // rax
  float mOnSeconds; // xmm0_4
  __int64 m_EnumValue; // r8
  __int64 v14; // rdx
  float v15; // xmm1_4
  UFG::InputActionData *v16; // rax
  float v17; // xmm0_4
  __int64 v18; // r8
  __int64 v19; // rdx
  float v20; // xmm1_4
  UFG::InputActionData *v21; // rax
  UFG::InputActionDef *v22; // rdi
  __int64 v23; // r8
  __int64 v24; // rdx
  float v25; // xmm1_4
  UFG::InputActionData *v26; // rcx
  float AxisVelX; // xmm7_4
  UFG::InputActionData *v28; // rcx
  float AxisVelY; // xmm0_4
  UFG::InputActionData *v30; // rax
  float v31; // xmm8_4
  float mAxisPositionY; // xmm10_4
  float v33; // xmm10_4
  __int128 mAxisPositionX_low; // xmm11
  float v35; // xmm15_4
  float v36; // xmm7_4
  float x; // xmm4_4
  __m128 y_low; // xmm3
  float v39; // xmm2_4
  float v40; // xmm5_4
  float v41; // xmm1_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm5_4
  __m128 v45; // xmm1
  float v46; // xmm1_4
  __m128 v47; // xmm1
  int v48; // r8d
  _DWORD *v49; // rcx
  int v50; // eax
  _DWORD *v51; // rdx
  float y; // xmm2_4
  float v53; // xmm3_4
  _DWORD *v54; // rcx
  int v55; // eax
  _DWORD *v56; // rdx
  _DWORD *v57; // rcx
  int v58; // eax
  _DWORD *v59; // rdx
  _DWORD *v60; // rcx
  int v61; // eax
  _DWORD *v62; // rdx
  float v63; // xmm1_4
  __int64 v64; // r8
  __int64 v65; // rdx
  float v66; // xmm2_4
  __int64 v67; // r8
  __int64 v68; // rdx
  float v69; // xmm1_4
  UFG::InputActionData *v70; // rax
  float v71; // xmm0_4
  __int64 v72; // r8
  __int64 v73; // rdx
  float v74; // xmm1_4
  UFG::InputActionData *v75; // rdx
  __int64 v76; // r9
  char v77; // cl
  float v78; // xmm0_4
  float v79; // xmm1_4
  __int64 v80; // r8
  __int64 v81; // rdx
  float v82; // xmm1_4
  UFG::InputActionData *v83; // rax
  float v84; // xmm0_4
  __int64 v85; // r8
  __int64 v86; // rdx
  float v87; // xmm1_4
  UFG::InputActionData *v88; // rax
  float v89; // xmm0_4
  __int64 v90; // r8
  __int64 v91; // rdx
  float v92; // xmm1_4
  UFG::InputActionData *v93; // rax
  UFG::SimObjectGame *v94; // rcx
  UFG::TargetingSystemBaseComponent *ComponentOfTypeHK; // rax
  __int16 v96; // dx
  bool v97; // zf
  UFG::InputActionData *v98; // rax
  float v99; // xmm0_4
  __int64 v100; // rdx
  __int64 v101; // r8
  float v102; // xmm1_4
  UFG::SimObjectGame *v103; // rcx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  float v106; // xmm0_4
  __int64 v107; // r8
  __int64 v108; // rdx
  float v109; // xmm1_4
  UFG::InputActionData *v110; // rax
  float v111; // xmm0_4
  __int64 v112; // r9
  __int64 v113; // r8
  float v114; // xmm1_4
  UFG::InputActionData *v115; // rax
  float v116; // xmm0_4
  __int64 v117; // r9
  __int64 v118; // r8
  float v119; // xmm1_4
  UFG::InputActionData *v120; // rax
  float mAxisPositionX; // xmm0_4
  __int64 v122; // r9
  UFG::InputActionData *v123; // rax
  UFG::InputActionData *v124; // rax
  __int64 v125; // r8
  float v126; // xmm1_4
  UFG::InputActionData *v127; // rax
  float v128; // xmm0_4
  UFG::InputActionData *v129; // rax
  UFG::InputActionData *v130; // rax
  UFG::SimObjectGame *v131; // rcx
  UFG::TargetingSystemBaseComponent *ComponentOfType; // rax
  __int16 v133; // dx
  UFG::InputActionData *v134; // rax
  float v135; // xmm1_4
  UFG::InputActionData *v136; // rax
  float v137; // xmm0_4
  __int64 v138; // r8
  float v139; // xmm1_4
  UFG::InputActionData *v140; // rax
  __int64 v141; // r8
  __int64 v142; // rdx
  float v143; // xmm1_4
  UFG::InputActionData *v144; // rax
  float v145; // xmm0_4
  __int64 v146; // r8
  __int64 v147; // rdx
  float v148; // xmm1_4
  UFG::InputActionData *v149; // rax
  UFG::InputActionData *v150; // rcx
  UFG::InputActionData *v151; // rcx
  float v152; // xmm0_4
  __int64 v153; // r8
  __int64 v154; // rdx
  float v155; // xmm1_4
  UFG::InputActionData *v156; // rax
  UFG::InputActionData *v157; // rax
  UFG::InputActionData *v158; // rax
  __int64 v159; // r8
  __int64 v160; // rdx
  float v161; // xmm1_4
  UFG::InputActionData *v162; // rax
  float v163; // xmm0_4
  __int64 v164; // r8
  __int64 v165; // rdx
  float v166; // xmm1_4
  UFG::InputActionData *v167; // rax
  float v168; // xmm0_4
  __int64 v169; // r8
  __int64 v170; // rdx
  float v171; // xmm1_4
  UFG::InputActionData *v172; // rdx
  __int64 v173; // r9
  char v174; // cl
  float v175; // xmm0_4
  float v176; // xmm1_4
  __int64 v177; // r8
  __int64 v178; // rdx
  float v179; // xmm1_4
  UFG::InputActionData *v180; // rax
  UFG::InputActionData *v181; // rax
  UFG::InputActionData *v182; // rax
  float v183; // xmm0_4
  float v184; // xmm1_4
  UFG::InputActionData *v185; // rax
  float v186; // xmm0_4
  __int64 v187; // r8
  __int64 v188; // rdx
  float v189; // xmm1_4
  UFG::InputActionData *v190; // rax
  UFG::InputActionData *v191; // rax
  UFG::InputActionData *v192; // rax
  UFG::InputActionData *v193; // rax
  __int64 v194; // r8
  __int64 v195; // rdx
  float v196; // xmm1_4
  UFG::InputActionData *v197; // rax
  __int64 v198; // r8
  __int64 v199; // rdx
  float v200; // xmm1_4
  UFG::InputActionData *v201; // rax
  float v202; // xmm0_4
  __int64 v203; // r8
  __int64 v204; // rdx
  float v205; // xmm1_4
  UFG::InputActionData *v206; // rax
  UFG::InputActionData *v207; // rax
  __int64 v208; // r8
  __int64 v209; // rdx
  float v210; // xmm1_4
  UFG::InputActionData *v211; // rax
  UFG::InputActionData *v212; // rax
  __int64 v213; // r8
  __int64 v214; // rdx
  float v215; // xmm1_4
  UFG::InputActionData *v216; // rax
  __int64 v217; // r8
  __int64 v218; // rdx
  float v219; // xmm1_4
  UFG::InputActionData *v220; // rax
  float v221; // xmm0_4
  __int64 v222; // r8
  __int64 v223; // rdx
  float v224; // xmm1_4
  UFG::InputActionData *v225; // rax
  __int64 v226; // rdx
  float v227; // xmm0_4
  __int64 v228; // rsi
  float v229; // xmm1_4
  UFG::InputActionData *v230; // rax
  UFG::InputActionData *v231; // rax
  UFG::InputActionData *v232; // rax
  float v233; // xmm13_4
  float v234; // xmm14_4
  float v235; // xmm7_4
  float v236; // xmm11_4
  float v237; // xmm9_4
  float v238; // xmm8_4
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  UFG::GameCameraComponent *v241; // rdi
  UFG::Camera *p_mCamera; // rcx
  UFG::BaseCameraComponent *v243; // rcx
  int x_low; // xmm9_4
  int v245; // xmm10_4
  int z_low; // xmm8_4
  float v247; // xmm13_4
  float v248; // xmm14_4
  float z; // xmm15_4
  double v250; // xmm0_8
  float v251; // xmm11_4
  char v252; // di
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **ActiveView; // rax
  UFG::qVector3 *DirForward; // rax
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v255; // rax
  UFG::qVector3 *Position; // rax
  UFG::SimComponent *v257; // rax
  UFG::SimObject *v258; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  int v260; // xmm4_4
  float v261; // xmm7_4
  int v262; // xmm6_4
  UFG::SimObject *v263; // rdi
  UFG::TransformNodeComponent *v264; // rdi
  float v265; // xmm3_4
  float v266; // xmm6_4
  float v267; // xmm1_4
  float v268; // xmm2_4
  float v269; // xmm8_4
  float v270; // xmm2_4
  float v271; // xmm8_4
  float v272; // xmm9_4
  UFG::SimObjectCVBase *v273; // rcx
  __int16 v274; // dx
  UFG::ActiveAIEntityComponent *v275; // rax
  char v276; // cl
  float v277; // xmm1_4
  float v278; // xmm2_4
  float v279; // xmm1_4
  float v280; // xmm2_4
  float v281; // xmm1_4
  float v282; // xmm6_4
  float v283; // xmm6_4
  float v284; // xmm2_4
  UFG::SimObjectCVBase *v285; // rcx
  __int16 v286; // dx
  UFG::CharacterAnimationComponent *v287; // rax
  UFG::CharacterAnimationComponent *v288; // rdi
  Creature *mCreature; // rcx
  int BoneID; // eax
  UFG::qVector3 *Translation; // rax
  float v292; // xmm1_4
  float v293; // xmm2_4
  float v294; // xmm0_4
  UFG::SimComponent *v295; // rax
  UFG::SimObject *v296; // rdi
  UFG::TransformNodeComponent *v297; // rdi
  float v298; // xmm1_4
  float v299; // xmm2_4
  float v300; // xmm0_4
  float v301; // xmm1_4
  float v302; // xmm7_4
  float v303; // xmm2_4
  float v304; // xmm1_4
  float v305; // xmm0_4
  float v306; // xmm2_4
  UFG::SimObjectGame *v307; // rcx
  __int16 v308; // dx
  UFG::SimComponent *v309; // rax
  float v310; // xmm1_4
  float v311; // xmm0_4
  float v312; // xmm15_4
  UFG::InputActionData *v313; // rax
  UFG::AICharacterControllerComponent *v314; // rbx
  float v316; // [rsp+20h] [rbp-E0h]
  float v317; // [rsp+20h] [rbp-E0h]
  float v318; // [rsp+24h] [rbp-DCh]
  float v319; // [rsp+28h] [rbp-D8h]
  float v320; // [rsp+2Ch] [rbp-D4h]
  Intention other; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 v322; // [rsp+380h] [rbp+280h] BYREF
  UFG::qMatrix44 dest; // [rsp+390h] [rbp+290h] BYREF
  float v324; // [rsp+4C0h] [rbp+3C0h]
  float v326; // [rsp+4D0h] [rbp+3D0h]
  float v327; // [rsp+4D8h] [rbp+3D8h]

  m_pContext = this->m_pContext;
  if ( m_pContext && (m_pContext->mSimObject.m_pPointer->m_Flags & 0x400) != 0 )
    return 1;
  v4 = 0.0;
  v326 = 0.0;
  v324 = 0.0;
  Intention::Intention(&other);
  v5 = 0i64;
  p_m_Intention = 0i64;
  Intention::Clear(&other);
  m_pPointer = (UFG::AICharacterControllerComponent *)this->m_pAICharacterControllerComponent.m_pPointer;
  m_ControllerID = 0;
  if ( m_pPointer )
  {
    m_ControllerID = m_pPointer->m_ControllerID;
    p_m_Intention = &m_pPointer->m_Intention;
  }
  v9 = UFG::InputSystem::AcquireController(UFG::gInputSystem, m_ControllerID);
  m_IsKeyboardController = 0;
  if ( v9 )
    m_IsKeyboardController = v9->m_IsKeyboardController;
  v11 = UFG::ActionDef_UIAcceptPressed.mDataPerController[m_ControllerID];
  if ( v11 && v11->mActionTrue )
  {
    mOnSeconds = v11->mOnSeconds;
    m_EnumValue = gActionRequest_Accept.m_EnumValue;
    v14 = 1i64 << (gActionRequest_Accept.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Accept.m_EnumValue >> 6] |= v14;
    v15 = (float)(int)(float)(mOnSeconds * 60.0);
    if ( v15 >= 255.0 )
      v15 = FLOAT_255_0;
    other.mActionRequestChargeTimes[m_EnumValue] = (int)v15;
    other.mSignals |= v14;
  }
  v16 = UFG::ActionDef_UIBackPressed.mDataPerController[m_ControllerID];
  if ( v16 && v16->mActionTrue )
  {
    v17 = v16->mOnSeconds;
    v18 = gActionRequest_Cancel.m_EnumValue;
    v19 = 1i64 << (gActionRequest_Cancel.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Cancel.m_EnumValue >> 6] |= v19;
    v20 = (float)(int)(float)(v17 * 60.0);
    if ( v20 >= 255.0 )
      v20 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v18] = (int)v20;
    other.mSignals |= v19;
  }
  v21 = UFG::ActionDef_VehicleRamReload.mDataPerController[m_ControllerID];
  v22 = &UFG::ActionDef_MoveFwdBack;
  if ( v21 && v21->mActionTrue )
  {
    v23 = gActionRequest_VehicleRam.m_EnumValue;
    v24 = 1i64 << (gActionRequest_VehicleRam.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_VehicleRam.m_EnumValue >> 6] |= v24;
    v25 = (float)(int)0.0;
    if ( v25 >= 255.0 )
      v25 = FLOAT_255_0;
    v22 = &UFG::ActionDef_Steer;
    other.mActionRequestChargeTimes[v23] = (int)v25;
    other.mSignals |= v24;
  }
  v26 = v22->mDataPerController[m_ControllerID];
  if ( v26 )
    AxisVelX = UFG::InputActionData::GetAxisVelX(v26);
  else
    AxisVelX = 0.0;
  v28 = v22->mDataPerController[m_ControllerID];
  if ( v28 )
    AxisVelY = UFG::InputActionData::GetAxisVelY(v28);
  else
    AxisVelY = 0.0;
  v30 = v22->mDataPerController[m_ControllerID];
  v31 = fsqrt((float)(AxisVelY * AxisVelY) + (float)(AxisVelX * AxisVelX));
  if ( v30 )
    mAxisPositionY = v30->mAxisPositionY;
  else
    mAxisPositionY = 0.0;
  LODWORD(v33) = LODWORD(mAxisPositionY) ^ _xmm[0];
  v319 = v33;
  if ( v30 )
    mAxisPositionX_low = LODWORD(v30->mAxisPositionX);
  else
    mAxisPositionX_low = 0i64;
  v35 = *(float *)&FLOAT_1_0;
  v327 = *(float *)&mAxisPositionX_low;
  v36 = 0.0;
  if ( v31 > sSettleVel )
  {
    x = this->mLockedPadModified.x;
    y_low = (__m128)LODWORD(this->mLockedPadModified.y);
    v36 = FLOAT_0_89999998;
    v39 = *(float *)&mAxisPositionX_low - x;
    v40 = v33 - y_low.m128_f32[0];
    v41 = (float)(v40 * v40) + (float)(v39 * v39);
    if ( v41 == 0.0 )
      v42 = 0.0;
    else
      v42 = 1.0 / fsqrt(v41);
    v43 = v39 * v42;
    v44 = v40 * v42;
    v45 = (__m128)LODWORD(this->mLockedPadModified.y);
    v45.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
    if ( v45.m128_f32[0] == 0.0 )
      v46 = 0.0;
    else
      v46 = 1.0 / _mm_sqrt_ps(v45).m128_f32[0];
    if ( (float)((float)((float)(v46 * y_low.m128_f32[0]) * v44) + (float)((float)(v46 * x) * v43)) < sStickDirChangeThreshold )
    {
      v47 = (__m128)mAxisPositionX_low;
      v47.m128_f32[0] = (float)(*(float *)&mAxisPositionX_low * *(float *)&mAxisPositionX_low) + (float)(v33 * v33);
      y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
      if ( _mm_sqrt_ps(v47).m128_f32[0] < _mm_sqrt_ps(y_low).m128_f32[0] )
        goto LABEL_46;
      v36 = FLOAT_0_60000002;
    }
    else
    {
      v36 = FLOAT_0_40000001;
    }
  }
  LODWORD(this->mLockedPadModified.x) = mAxisPositionX_low;
  this->mLockedPadModified.y = v33;
LABEL_46:
  v48 = sDrawDebug;
  if ( sDrawDebug )
  {
    v49 = &unk_1423B6334;
    do
    {
      v50 = v49[1];
      v49 -= 4;
      v49[6] = v50;
      v49[5] = v49[4];
      v49[4] = v49[3];
      v49[3] = v49[2];
    }
    while ( (__int64)v49 > (__int64)&unk_1423B61B4 );
    v51 = &unk_1423B61BC;
    do
    {
      *v51 = *(v51 - 1);
      --v51;
    }
    while ( (__int64)v51 > (__int64)gValues5 );
    gValues5[0] = v36;
  }
  y = this->mLockedPadModified.y;
  v53 = this->mLockedPadModified.x;
  v320 = y;
  v318 = v53;
  if ( v48 )
  {
    v54 = &unk_1423B5B64;
    do
    {
      v55 = v54[1];
      v54 -= 4;
      v54[6] = v55;
      v54[5] = v54[4];
      v54[4] = v54[3];
      v54[3] = v54[2];
    }
    while ( (__int64)v54 > (__int64)&unk_1423B59E4 );
    v56 = &unk_1423B59EC;
    do
    {
      *v56 = *(v56 - 1);
      --v56;
    }
    while ( (__int64)v56 > (__int64)gValues0 );
    gValues0[0] = v31;
    v57 = &unk_1423B5CF4;
    do
    {
      v58 = v57[1];
      v57 -= 4;
      v57[6] = v58;
      v57[5] = v57[4];
      v57[4] = v57[3];
      v57[3] = v57[2];
    }
    while ( (__int64)v57 > (__int64)&unk_1423B5B74 );
    v59 = &unk_1423B5B7C;
    do
    {
      *v59 = *(v59 - 1);
      --v59;
    }
    while ( (__int64)v59 > (__int64)gValues1 );
    gValues1[0] = v33;
    v60 = &unk_1423B5E84;
    do
    {
      v61 = v60[1];
      v60 -= 4;
      v60[6] = v61;
      v60[5] = v60[4];
      v60[4] = v60[3];
      v60[3] = v60[2];
    }
    while ( (__int64)v60 > (__int64)&unk_1423B5D04 );
    v62 = &unk_1423B5D0C;
    do
    {
      *v62 = *(v62 - 1);
      --v62;
    }
    while ( (__int64)v62 > (__int64)gValues2 );
    LODWORD(gValues2[0]) = mAxisPositionX_low;
  }
  v63 = digitalMoveThreshold;
  if ( y <= digitalMoveThreshold )
  {
    if ( y >= COERCE_FLOAT(LODWORD(digitalMoveThreshold) ^ _xmm[0]) )
      goto LABEL_73;
    v64 = gActionRequest_MoveBackward.m_EnumValue;
  }
  else
  {
    v64 = gActionRequest_MoveForward.m_EnumValue;
  }
  v65 = 1i64 << (v64 & 0x3F);
  other.mActionRequests.mBits[(__int64)(int)v64 >> 6] |= v65;
  v66 = (float)(int)0.0;
  if ( v66 >= 255.0 )
    v66 = FLOAT_255_0;
  other.mActionRequestChargeTimes[v64] = (int)v66;
  other.mSignals |= v65;
LABEL_73:
  if ( v53 <= v63 )
  {
    if ( v53 >= COERCE_FLOAT(LODWORD(v63) ^ _xmm[0]) )
      goto LABEL_80;
    v67 = gActionRequest_MoveLeft.m_EnumValue;
  }
  else
  {
    v67 = gActionRequest_MoveRight.m_EnumValue;
  }
  v68 = 1i64 << (v67 & 0x3F);
  other.mActionRequests.mBits[(__int64)(int)v67 >> 6] |= v68;
  v69 = (float)(int)0.0;
  if ( v69 >= 255.0 )
    v69 = FLOAT_255_0;
  other.mActionRequestChargeTimes[v67] = (int)v69;
  other.mSignals |= v68;
LABEL_80:
  v70 = UFG::ActionDef_Jump.mDataPerController[m_ControllerID];
  if ( v70 && v70->mActionTrue )
  {
    v71 = v70->mOnSeconds;
    v72 = gActionRequest_Jump.m_EnumValue;
    v73 = 1i64 << (gActionRequest_Jump.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Jump.m_EnumValue >> 6] |= v73;
    v74 = (float)(int)(float)(v71 * 60.0);
    if ( v74 >= 255.0 )
      v74 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v72] = (int)v74;
    other.mSignals |= v73;
  }
  v75 = UFG::ActionDef_Action.mDataPerController[m_ControllerID];
  if ( v75 && v75->mActionTrue )
  {
    v76 = gActionRequest_Action.m_EnumValue;
    v77 = gActionRequest_Action.m_EnumValue & 0x3F;
    v78 = v75->mOnSeconds * 60.0;
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Action.m_EnumValue >> 6] |= 1i64 << (gActionRequest_Action.m_EnumValue & 0x3F);
    v79 = (float)(int)v78;
    if ( v79 >= 255.0 )
      v79 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v76] = (int)v79;
    other.mSignals |= 1i64 << v77;
    v80 = gActionRequest_POI_Use.m_EnumValue;
    v316 = v75->mOnSeconds * 60.0;
    v81 = 1i64 << (gActionRequest_POI_Use.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_POI_Use.m_EnumValue >> 6] |= v81;
    v82 = (float)(int)v316;
    if ( v82 >= 255.0 )
      v82 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v80] = (int)v82;
    other.mSignals |= v81;
  }
  v83 = UFG::ActionDef_Grab.mDataPerController[m_ControllerID];
  if ( v83 && v83->mActionTrue )
  {
    v84 = v83->mOnSeconds;
    v85 = gActionRequest_Grab.m_EnumValue;
    v86 = 1i64 << (gActionRequest_Grab.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Grab.m_EnumValue >> 6] |= v86;
    v87 = (float)(int)(float)(v84 * 60.0);
    if ( v87 >= 255.0 )
      v87 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v85] = (int)v87;
    other.mSignals |= v86;
  }
  v88 = UFG::ActionDef_Weapon.mDataPerController[m_ControllerID];
  if ( v88 && v88->mActionTrue )
  {
    v89 = v88->mOnSeconds;
    v90 = gActionRequest_Weapon.m_EnumValue;
    v91 = 1i64 << (gActionRequest_Weapon.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Weapon.m_EnumValue >> 6] |= v91;
    v92 = (float)(int)(float)(v89 * 60.0);
    if ( v92 >= 255.0 )
      v92 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v90] = (int)v92;
    other.mSignals |= v91;
  }
  v93 = UFG::ActionDef_MeleeAttack.mDataPerController[m_ControllerID];
  if ( !v93 || !v93->mActionTrue )
  {
    v98 = UFG::ActionDef_Attack.mDataPerController[m_ControllerID];
    if ( !v98 || !v98->mActionTrue )
      goto LABEL_142;
    if ( !m_IsKeyboardController )
      goto LABEL_138;
    v103 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( v103 )
    {
      m_Flags = v103->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)v103->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v103,
                                                               UFG::TargetingSystemBaseComponent::_TypeUID)
                                                           : UFG::SimObject::GetComponentOfType(
                                                               v103,
                                                               UFG::TargetingSystemBaseComponent::_TypeUID));
      }
      else
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)v103->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    if ( UFG::HasRangedWeaponEquippedWithAmmo(m_pComponent) )
    {
LABEL_142:
      LODWORD(v100) = gActionRequest_Fire.m_EnumValue;
      goto LABEL_143;
    }
    v98 = UFG::ActionDef_Attack.mDataPerController[m_ControllerID];
LABEL_136:
    if ( !v98 )
    {
      v106 = 0.0;
LABEL_139:
      v107 = gActionRequest_Attack.m_EnumValue;
      v108 = 1i64 << (gActionRequest_Attack.m_EnumValue & 0x3F);
      other.mActionRequests.mBits[(__int64)(int)gActionRequest_Attack.m_EnumValue >> 6] |= v108;
      v109 = (float)(int)(float)(v106 * 60.0);
      if ( v109 >= 255.0 )
        v109 = FLOAT_255_0;
      other.mActionRequestChargeTimes[v107] = (int)v109;
      other.mSignals |= v108;
      goto LABEL_142;
    }
LABEL_138:
    v106 = v98->mOnSeconds;
    goto LABEL_139;
  }
  v94 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v94 )
  {
    v96 = v94->m_Flags;
    if ( (v96 & 0x4000) != 0 )
    {
      ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)v94->m_Components.p[20].m_pComponent;
    }
    else if ( v96 >= 0 )
    {
      if ( (v96 & 0x2000) != 0 || (v96 & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v94,
                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                   v94,
                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)v94->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  v97 = !UFG::HasRangedWeapon(ComponentOfTypeHK);
  v98 = UFG::ActionDef_MeleeAttack.mDataPerController[m_ControllerID];
  if ( !v97 )
    goto LABEL_136;
  if ( v98 )
    v99 = v98->mOnSeconds;
  else
    v99 = 0.0;
  v100 = gActionRequest_Fire.m_EnumValue;
  v101 = 1i64 << (gActionRequest_Fire.m_EnumValue & 0x3F);
  other.mActionRequests.mBits[(__int64)(int)gActionRequest_Fire.m_EnumValue >> 6] |= v101;
  v102 = (float)(int)(float)(v99 * 60.0);
  if ( v102 >= 255.0 )
    v102 = FLOAT_255_0;
  other.mActionRequestChargeTimes[v100] = (int)v102;
  other.mSignals |= v101;
LABEL_143:
  v110 = UFG::ActionDef_Sprint.mDataPerController[m_ControllerID];
  if ( v110 && v110->mActionTrue )
  {
    v111 = v110->mOnSeconds;
    v112 = gActionRequest_Sprint.m_EnumValue;
    v113 = 1i64 << (gActionRequest_Sprint.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Sprint.m_EnumValue >> 6] |= v113;
    v114 = (float)(int)(float)(v111 * 60.0);
    if ( v114 >= 255.0 )
      v114 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v112] = (int)v114;
    other.mSignals |= v113;
  }
  v115 = UFG::ActionDef_CoverToggle.mDataPerController[m_ControllerID];
  if ( v115 && v115->mActionTrue )
  {
    v116 = v115->mOnSeconds;
    v117 = gActionRequest_CoverToggle.m_EnumValue;
    v118 = 1i64 << (gActionRequest_CoverToggle.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_CoverToggle.m_EnumValue >> 6] |= v118;
    v119 = (float)(int)(float)(v116 * 60.0);
    if ( v119 >= 255.0 )
      v119 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v117] = (int)v119;
    other.mSignals |= v118;
  }
  v120 = UFG::ActionDef_Steer.mDataPerController[m_ControllerID];
  if ( v120 && v120->mActionTrue )
  {
    mAxisPositionX = v120->mAxisPositionX;
    if ( mAxisPositionX >= -0.5 )
    {
      if ( mAxisPositionX <= 0.5 )
        goto LABEL_168;
      v122 = gActionRequest_SteerRight.m_EnumValue;
    }
    else
    {
      v122 = gActionRequest_SteerLeft.m_EnumValue;
    }
  }
  else
  {
    v123 = UFG::ActionDef_Left.mDataPerController[m_ControllerID];
    if ( v123 && v123->mActionTrue )
    {
      v122 = gActionRequest_SteerLeft.m_EnumValue;
    }
    else
    {
      v124 = UFG::ActionDef_Right.mDataPerController[m_ControllerID];
      if ( !v124 || (v122 = gActionRequest_SteerRight.m_EnumValue, !v124->mActionTrue) )
        v122 = gActionRequest_SteerNeutral.m_EnumValue;
    }
  }
  v125 = 1i64 << (v122 & 0x3F);
  other.mActionRequests.mBits[(__int64)(int)v122 >> 6] |= v125;
  v126 = (float)(int)0.0;
  if ( v126 >= 255.0 )
    v126 = FLOAT_255_0;
  other.mActionRequestChargeTimes[v122] = (int)v126;
  other.mSignals |= v125;
LABEL_168:
  if ( UFG::TargetingSystemPedPlayerComponent::ms_eTargetCycleAndLocationTargetingModeEnum == TCALTM_SLIGHTLY_PRESS_FIRE )
  {
    v127 = UFG::ActionDef_FireFull.mDataPerController[m_ControllerID];
    if ( !v127 || !v127->mActionTrue )
      goto LABEL_199;
    v128 = v127->mOnSeconds;
  }
  else
  {
    v129 = UFG::ActionDef_Fire.mDataPerController[m_ControllerID];
    if ( !v129 || !v129->mActionTrue )
    {
      v130 = UFG::ActionDef_VehicleFire.mDataPerController[m_ControllerID];
      if ( !v130 || !v130->mActionTrue )
        goto LABEL_199;
    }
    if ( m_IsKeyboardController )
    {
      v131 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
      if ( v131 )
      {
        v133 = v131->m_Flags;
        if ( (v133 & 0x4000) != 0 )
        {
          ComponentOfType = (UFG::TargetingSystemBaseComponent *)v131->m_Components.p[20].m_pComponent;
        }
        else if ( v133 >= 0 )
        {
          if ( (v133 & 0x2000) != 0 || (v133 & 0x1000) != 0 )
            ComponentOfType = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v131,
                                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfType = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v131,
                                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = (UFG::TargetingSystemBaseComponent *)v131->m_Components.p[20].m_pComponent;
        }
      }
      else
      {
        ComponentOfType = 0i64;
      }
      if ( !UFG::HasRangedWeapon(ComponentOfType) )
        goto LABEL_199;
      LODWORD(v100) = gActionRequest_Fire.m_EnumValue;
    }
    v134 = UFG::ActionDef_Fire.mDataPerController[m_ControllerID];
    if ( v134 )
      v135 = v134->mOnSeconds;
    else
      v135 = 0.0;
    v136 = UFG::ActionDef_VehicleFire.mDataPerController[m_ControllerID];
    if ( v136 )
      v137 = v136->mOnSeconds;
    else
      v137 = 0.0;
    v128 = v137 + v135;
  }
  v138 = 1i64 << (v100 & 0x3F);
  other.mActionRequests.mBits[(__int64)(int)v100 >> 6] |= v138;
  v139 = (float)(int)(float)(v128 * 60.0);
  if ( v139 >= 255.0 )
    v139 = FLOAT_255_0;
  other.mActionRequestChargeTimes[(unsigned int)v100] = (int)v139;
  other.mSignals |= v138;
LABEL_199:
  v140 = UFG::ActionDef_FirePartial.mDataPerController[m_ControllerID];
  if ( v140 && v140->mActionTrue )
  {
    v141 = gActionRequest_FirePartial.m_EnumValue;
    v142 = 1i64 << (gActionRequest_FirePartial.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_FirePartial.m_EnumValue >> 6] |= v142;
    v143 = (float)(int)0.0;
    if ( v143 >= 255.0 )
      v143 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v141] = (int)v143;
    other.mSignals |= v142;
  }
  v144 = UFG::ActionDef_Reload.mDataPerController[m_ControllerID];
  if ( v144 && v144->mActionTrue )
  {
    v145 = v144->mOnSeconds;
    v146 = gActionRequest_Reload.m_EnumValue;
    v147 = 1i64 << (gActionRequest_Reload.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Reload.m_EnumValue >> 6] |= v147;
    v148 = (float)(int)(float)(v145 * 60.0);
    if ( v148 >= 255.0 )
      v148 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v146] = (int)v148;
    other.mSignals |= v147;
  }
  v149 = UFG::ActionDef_Inventory.mDataPerController[m_ControllerID];
  if ( v149 )
  {
    if ( v149->mActionTrue )
    {
      v150 = UFG::ActionDef_PrevRadioStationHold.mDataPerController[m_ControllerID];
      if ( !v150 || !v150->mActionTrue )
      {
        v151 = UFG::ActionDef_NextRadioStationHold.mDataPerController[m_ControllerID];
        if ( !v151 || !v151->mActionTrue )
        {
          v152 = v149->mOnSeconds;
          v153 = gActionRequest_Inventory.m_EnumValue;
          v154 = 1i64 << (gActionRequest_Inventory.m_EnumValue & 0x3F);
          other.mActionRequests.mBits[(__int64)(int)gActionRequest_Inventory.m_EnumValue >> 6] |= v154;
          v155 = (float)(int)(float)(v152 * 60.0);
          if ( v155 >= 255.0 )
            v155 = FLOAT_255_0;
          other.mActionRequestChargeTimes[v153] = (int)v155;
          other.mSignals |= v154;
        }
      }
    }
  }
  v156 = UFG::ActionDef_EquipUP.mDataPerController[m_ControllerID];
  if ( v156 )
  {
    if ( v156->mActionTrue )
    {
      v157 = UFG::ActionDef_PrevRadioStationHold.mDataPerController[m_ControllerID];
      if ( !v157 || !v157->mActionTrue )
      {
        v158 = UFG::ActionDef_NextRadioStationHold.mDataPerController[m_ControllerID];
        if ( !v158 || !v158->mActionTrue )
        {
          v159 = gActionRequest_EquipUP.m_EnumValue;
          v160 = 1i64 << (gActionRequest_EquipUP.m_EnumValue & 0x3F);
          other.mActionRequests.mBits[(__int64)(int)gActionRequest_EquipUP.m_EnumValue >> 6] |= v160;
          v161 = (float)(int)0.0;
          if ( v161 >= 255.0 )
            v161 = FLOAT_255_0;
          other.mActionRequestChargeTimes[v159] = (int)v161;
          other.mSignals |= v160;
        }
      }
    }
  }
  v162 = UFG::ActionDef_Raw_Focus.mDataPerController[m_ControllerID];
  if ( v162 && v162->mActionTrue )
  {
    v163 = v162->mOnSeconds;
    v164 = gActionRequest_Raw_Focus.m_EnumValue;
    v165 = 1i64 << (gActionRequest_Raw_Focus.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Raw_Focus.m_EnumValue >> 6] |= v165;
    v166 = (float)(int)(float)(v163 * 60.0);
    if ( v166 >= 255.0 )
      v166 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v164] = (int)v166;
    other.mSignals |= v165;
  }
  v167 = UFG::ActionDef_Raw_Focus_Full.mDataPerController[m_ControllerID];
  if ( v167 && v167->mActionTrue )
  {
    v168 = v167->mOnSeconds;
    v169 = gActionRequest_Raw_Focus_Full.m_EnumValue;
    v170 = 1i64 << (gActionRequest_Raw_Focus_Full.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Raw_Focus_Full.m_EnumValue >> 6] |= v170;
    v171 = (float)(int)(float)(v168 * 60.0);
    if ( v171 >= 255.0 )
      v171 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v169] = (int)v171;
    other.mSignals |= v170;
  }
  v172 = UFG::ActionDef_Raw_Focus_Lock.mDataPerController[m_ControllerID];
  if ( v172 && v172->mActionTrue )
  {
    v173 = gActionRequest_Raw_Focus_Lock.m_EnumValue;
    v174 = gActionRequest_Raw_Focus_Lock.m_EnumValue & 0x3F;
    v175 = v172->mOnSeconds * 60.0;
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Raw_Focus_Lock.m_EnumValue >> 6] |= 1i64 << (gActionRequest_Raw_Focus_Lock.m_EnumValue & 0x3F);
    v176 = (float)(int)v175;
    if ( v176 >= 255.0 )
      v176 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v173] = (int)v176;
    other.mSignals |= 1i64 << v174;
    v177 = gActionRequest_WeaponMode.m_EnumValue;
    v317 = v172->mOnSeconds * 60.0;
    v178 = 1i64 << (gActionRequest_WeaponMode.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_WeaponMode.m_EnumValue >> 6] |= v178;
    v179 = (float)(int)v317;
    if ( v179 >= 255.0 )
      v179 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v177] = (int)v179;
    other.mSignals |= v178;
  }
  v180 = UFG::ActionDef_Focus.mDataPerController[m_ControllerID];
  if ( v180 && v180->mActionTrue )
  {
    if ( m_IsKeyboardController )
    {
      v182 = UFG::ActionDef_Mouse.mDataPerController[m_ControllerID];
      if ( v182 )
      {
        v183 = v182->mAxisPositionX;
        v184 = v182->mAxisPositionY;
      }
      else
      {
        v183 = 0.0;
        v184 = 0.0;
      }
      v324 = UFG::FollowCameraComponent::rMouseSpeedScaleVMin * v184;
      v326 = UFG::FollowCameraComponent::rMouseSpeedScaleHMin * v183;
    }
    else
    {
      v181 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[m_ControllerID];
      if ( v181 && v181->mActionTrue )
      {
        v326 = v181->mAxisPositionX;
        LODWORD(v324) = LODWORD(v181->mAxisPositionY) ^ _xmm[0];
      }
    }
  }
  v185 = UFG::ActionDef_Freerun.mDataPerController[m_ControllerID];
  if ( v185 && v185->mActionTrue || lock_freerun_button )
  {
    if ( v185 )
      v186 = v185->mOnSeconds;
    else
      v186 = 0.0;
    v187 = gActionRequest_Freerun.m_EnumValue;
    v188 = 1i64 << (gActionRequest_Freerun.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Freerun.m_EnumValue >> 6] |= v188;
    v189 = (float)(int)(float)(v186 * 60.0);
    if ( v189 >= 255.0 )
      v189 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v187] = (int)v189;
    other.mSignals |= v188;
  }
  v190 = UFG::MultiAction_ForwardKeyDoubleTap.mDataPerController[m_ControllerID];
  if ( v190 && v190->mActionTrue )
  {
    lock_freerun_button = 1;
  }
  else
  {
    v191 = UFG::ActionDef_ForwardKey.mDataPerController[m_ControllerID];
    if ( !v191 || !v191->mActionTrue )
      lock_freerun_button = 0;
  }
  v192 = UFG::ActionDef_VehicleFocus.mDataPerController[m_ControllerID];
  if ( v192 && v192->mActionTrue
    || (v193 = UFG::ActionDef_VehicleFocus_Alt.mDataPerController[m_ControllerID]) != 0i64 && v193->mActionTrue )
  {
    v194 = gActionRequest_VehicleFocus.m_EnumValue;
    v195 = 1i64 << (gActionRequest_VehicleFocus.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_VehicleFocus.m_EnumValue >> 6] |= v195;
    v196 = (float)(int)0.0;
    if ( v196 >= 255.0 )
      v196 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v194] = (int)v196;
    other.mSignals |= v195;
  }
  v197 = UFG::ActionDef_VehicleActionHijack.mDataPerController[m_ControllerID];
  if ( v197 && v197->mActionTrue )
  {
    v198 = gActionRequest_VehicleActionHijackDesired.m_EnumValue;
    v199 = 1i64 << (gActionRequest_VehicleActionHijackDesired.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_VehicleActionHijackDesired.m_EnumValue >> 6] |= v199;
    v200 = (float)(int)0.0;
    if ( v200 >= 255.0 )
      v200 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v198] = (int)v200;
    other.mSignals |= v199;
  }
  v201 = UFG::ActionDef_Accelerate.mDataPerController[m_ControllerID];
  if ( v201 && v201->mActionTrue )
  {
    v202 = v201->mOnSeconds;
    v203 = gActionRequest_VehicleGas.m_EnumValue;
    v204 = 1i64 << (gActionRequest_VehicleGas.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_VehicleGas.m_EnumValue >> 6] |= v204;
    v205 = (float)(int)(float)(v202 * 60.0);
    if ( v205 >= 255.0 )
      v205 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v203] = (int)v205;
    other.mSignals |= v204;
  }
  else
  {
    v206 = UFG::ActionDef_AccelerateButton.mDataPerController[m_ControllerID];
    if ( v206 && v206->mActionTrue )
      Intention::Set(&other, gActionRequest_VehicleGas.m_EnumValue, v206->mOnSeconds);
  }
  v207 = UFG::ActionDef_Brake.mDataPerController[m_ControllerID];
  if ( v207 && v207->mActionTrue )
  {
    v208 = gActionRequest_VehicleReverse.m_EnumValue;
    v209 = 1i64 << (gActionRequest_VehicleReverse.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_VehicleReverse.m_EnumValue >> 6] |= v209;
    v210 = (float)(int)0.0;
    if ( v210 >= 255.0 )
      v210 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v208] = (int)v210;
    other.mSignals |= v209;
  }
  else
  {
    v211 = UFG::ActionDef_BrakeButton.mDataPerController[m_ControllerID];
    if ( v211 && v211->mActionTrue )
      Intention::Set(&other, gActionRequest_VehicleReverse.m_EnumValue, 0.0);
  }
  v212 = UFG::ActionDef_HandBrake.mDataPerController[m_ControllerID];
  if ( v212 && v212->mActionTrue )
  {
    v213 = gActionRequest_VehicleHandBrake.m_EnumValue;
    v214 = 1i64 << (gActionRequest_VehicleHandBrake.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_VehicleHandBrake.m_EnumValue >> 6] |= v214;
    v215 = (float)(int)0.0;
    if ( v215 >= 255.0 )
      v215 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v213] = (int)v215;
    other.mSignals |= v214;
  }
  v216 = UFG::ActionDef_LookBack.mDataPerController[m_ControllerID];
  if ( v216 && v216->mActionTrue )
  {
    v217 = gActionRequest_VehicleLookBack.m_EnumValue;
    v218 = 1i64 << (gActionRequest_VehicleLookBack.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_VehicleLookBack.m_EnumValue >> 6] |= v218;
    v219 = (float)(int)0.0;
    if ( v219 >= 255.0 )
      v219 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v217] = (int)v219;
    other.mSignals |= v218;
  }
  v220 = UFG::ActionDef_Pickup.mDataPerController[m_ControllerID];
  if ( v220 && v220->mActionTrue )
  {
    v221 = v220->mOnSeconds;
    v222 = gActionRequest_Pickup.m_EnumValue;
    v223 = 1i64 << (gActionRequest_Pickup.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Pickup.m_EnumValue >> 6] |= v223;
    v224 = (float)(int)(float)(v221 * 60.0);
    if ( v224 >= 255.0 )
      v224 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v222] = (int)v224;
    other.mSignals |= v223;
  }
  v225 = UFG::ActionDef_UIL1Repeat.mDataPerController[m_ControllerID];
  v226 = gActionRequest_RotateLeft.m_EnumValue;
  if ( v225 && v225->mActionTrue )
  {
    v227 = v225->mOnSeconds;
    v228 = 1i64 << (gActionRequest_RotateLeft.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_RotateLeft.m_EnumValue >> 6] |= v228;
    v229 = (float)(int)(float)(v227 * 60.0);
    if ( v229 >= 255.0 )
      v229 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v226] = (int)v229;
    other.mSignals |= v228;
  }
  v230 = UFG::ActionDef_UILeftRepeat.mDataPerController[m_ControllerID];
  if ( v230 && v230->mActionTrue )
    Intention::Set(&other, v226, v230->mOnSeconds);
  v231 = UFG::ActionDef_UIR1Repeat.mDataPerController[m_ControllerID];
  if ( v231 && v231->mActionTrue )
    Intention::Set(&other, gActionRequest_RotateRight.m_EnumValue, v231->mOnSeconds);
  v232 = UFG::ActionDef_UIRightRepeat.mDataPerController[m_ControllerID];
  if ( v232 && v232->mActionTrue )
    Intention::Set(&other, gActionRequest_RotateRight.m_EnumValue, v232->mOnSeconds);
  v233 = 0.0;
  v234 = 0.0;
  v235 = 0.0;
  v236 = 0.0;
  v237 = 0.0;
  v238 = 0.0;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && mCurrentCamera->m_pSimObject )
  {
    CurrentGameCamera = UFG::GetCurrentGameCamera();
    v241 = CurrentGameCamera;
    if ( CurrentGameCamera )
    {
      p_mCamera = &CurrentGameCamera->mCamera;
    }
    else
    {
      if ( !UFG::bCameraSecondController )
        goto LABEL_357;
      v243 = UFG::Director::Get()->mCurrentCamera;
      if ( !v243 )
        goto LABEL_357;
      p_mCamera = &v243->mCamera;
    }
    if ( !p_mCamera )
      goto LABEL_357;
    x_low = SLODWORD(p_mCamera->mTransformation.v2.x);
    v245 = SLODWORD(p_mCamera->mTransformation.v2.y);
    z_low = SLODWORD(p_mCamera->mTransformation.v2.z);
    v247 = p_mCamera->mTransformation.v3.x;
    v248 = p_mCamera->mTransformation.v3.y;
    z = p_mCamera->mTransformation.v3.z;
    if ( v241 )
    {
      v250 = ((double (__fastcall *)(UFG::GameCameraComponent *))v241->vfptr[39].__vecDelDtor)(v241);
      v251 = *(float *)&v250;
      v252 = ((__int64 (__fastcall *)(UFG::GameCameraComponent *))v241->vfptr[38].__vecDelDtor)(v241);
    }
    else
    {
      v251 = 0.0;
      v252 = 0;
    }
    if ( UFG::Editor::IsActive() )
    {
      ActiveView = UFG::Editor::GetActiveView();
      DirForward = UFG::Editor::Camera::GetDirForward((UFG::Editor::Camera *)ActiveView[10], &v322);
      x_low = LODWORD(DirForward->x) ^ _xmm[0];
      v245 = LODWORD(DirForward->y) ^ _xmm[0];
      z_low = LODWORD(DirForward->z) ^ _xmm[0];
      v255 = UFG::Editor::GetActiveView();
      Position = UFG::Editor::Camera::GetPosition((UFG::Editor::Camera *)v255[10], &v322);
      v247 = Position->x;
      v248 = Position->y;
      z = Position->z;
    }
    v257 = this->m_pAICharacterControllerComponent.m_pPointer;
    if ( v257 && BYTE6(v257[17].m_SafePointerList.mNode.mPrev) )
    {
      v258 = this->m_pContext->mSimObject.m_pPointer;
      if ( v258 )
      {
        m_pTransformNodeComponent = v258->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          v260 = _xmm[0];
          LODWORD(v261) = LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.x) ^ _xmm[0];
          v262 = LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y) ^ _xmm[0];
LABEL_353:
          v35 = *(float *)&FLOAT_1_0;
          v267 = (float)((float)(*(float *)&v262 * *(float *)&v262) + (float)(v261 * v261)) + 0.0000000099999991;
          if ( v267 == 0.0 )
            v268 = 0.0;
          else
            v268 = 1.0 / fsqrt(v267);
          v269 = v268;
          v270 = v268 * *(float *)&v262;
          v271 = v269 * v261;
          v272 = v271 * v324;
          v233 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v271 * v319) ^ v260) - (float)(v270 * v327);
          v234 = (float)(v271 * v327) - (float)(v270 * v319);
          v235 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v271 * v320) ^ v260) - (float)(v270 * v318);
          v236 = (float)(v271 * v318) - (float)(v270 * v320);
          v238 = (float)(v271 * v326) - (float)(v270 * v324);
          v237 = COERCE_FLOAT(LODWORD(v272) ^ v260) - (float)(v270 * v326);
          goto LABEL_357;
        }
      }
    }
    else
    {
      v261 = *(float *)&x_low;
      v262 = v245;
      if ( !v252 )
      {
LABEL_352:
        v260 = _xmm[0];
        goto LABEL_353;
      }
      v263 = this->m_pContext->mSimObject.m_pPointer;
      if ( v263 )
      {
        v264 = v263->m_pTransformNodeComponent;
        if ( v264 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v264);
          v261 = v247 - v264->mWorldTransform.v3.x;
          *(float *)&v262 = v248 - v264->mWorldTransform.v3.y;
          *(float *)&z_low = z - v264->mWorldTransform.v3.z;
        }
      }
      if ( fsqrt((float)(*(float *)&v262 * *(float *)&v262) + (float)(v261 * v261)) >= 0.0099999998 )
      {
        if ( v251 != 0.0 )
        {
          UFG::qRotationMatrixZ(&dest, v251 * timeDelta);
          v265 = (float)((float)(dest.v1.x * *(float *)&v262) + (float)(dest.v0.x * v261))
               + (float)(dest.v2.x * *(float *)&z_low);
          v266 = (float)(dest.v1.y * *(float *)&v262) + (float)(dest.v0.y * v261);
          v261 = v265;
          *(float *)&v262 = v266 + (float)(dest.v2.y * *(float *)&z_low);
        }
        goto LABEL_352;
      }
    }
    v261 = *(float *)&x_low;
    v262 = v245;
    goto LABEL_352;
  }
LABEL_357:
  v273 = (UFG::SimObjectCVBase *)this->m_pContext->mSimObject.m_pPointer;
  if ( v273 )
  {
    v274 = v273->m_Flags;
    if ( (v274 & 0x4000) != 0 || v274 < 0 )
    {
      v275 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v273);
    }
    else if ( (v274 & 0x2000) != 0 || (v274 & 0x1000) != 0 )
    {
      v275 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v273,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      v275 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               v273,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v5 = v275;
  }
  if ( p_m_Intention
    && this->m_pAICharacterControllerComponent.m_pPointer
    && v5
    && v5->m_HeadTrackingTarget.m_Type != eHEAD_TRACK_TYPE_NONE )
  {
    v276 = 1;
    other.mDesireToLookAtPoint = p_m_Intention->mDesireToLookAtPoint;
    v277 = p_m_Intention->mDesiredLookAtPoint.y;
    v278 = p_m_Intention->mDesiredLookAtPoint.z;
    other.mDesiredLookAtPoint.x = p_m_Intention->mDesiredLookAtPoint.x;
    other.mDesiredLookAtPoint.y = v277;
    other.mDesiredLookAtPoint.z = v278;
    other.mDesireToLookAtPointEye = p_m_Intention->mDesireToLookAtPointEye;
    v279 = p_m_Intention->mDesiredLookAtPointEye.y;
    v280 = p_m_Intention->mDesiredLookAtPointEye.z;
    other.mDesiredLookAtPointEye.x = p_m_Intention->mDesiredLookAtPointEye.x;
    other.mDesiredLookAtPointEye.y = v279;
    other.mDesiredLookAtPointEye.z = v280;
  }
  else
  {
    v276 = 0;
  }
  other.mAwarenessIntention = p_m_Intention->mAwarenessIntention;
  v281 = (float)(v236 * v236) + (float)(v235 * v235);
  v282 = fsqrt(v281) - motionIntentionSpeedDeadZone;
  if ( v282 < 0.0 )
    v282 = 0.0;
  v283 = v282 / (float)(v35 - motionIntentionSpeedDeadZone);
  if ( v283 <= 0.001 )
  {
    v295 = this->m_pAICharacterControllerComponent.m_pPointer;
    if ( !v295 )
      goto LABEL_399;
    if ( BYTE5(v295[17].m_SafePointerList.mNode.mPrev) )
    {
      v296 = this->m_pContext->mSimObject.m_pPointer;
      if ( !v296 )
        goto LABEL_399;
      v297 = v296->m_pTransformNodeComponent;
      if ( !v297 )
        goto LABEL_399;
      UFG::TransformNodeComponent::UpdateWorldTransform(v297);
      v298 = v297->mWorldTransform.v0.y;
      v299 = v297->mWorldTransform.v0.z;
      v300 = v297->mWorldTransform.v0.x;
    }
    else
    {
      v298 = p_m_Intention->mMotionIntentionDirection.y;
      v299 = p_m_Intention->mMotionIntentionDirection.z;
      v300 = p_m_Intention->mMotionIntentionDirection.x;
    }
    other.mMotionIntentionDirection.z = v299;
    other.mMotionIntentionDirection.y = v298;
    other.mMotionIntentionDirection.x = v300;
    goto LABEL_399;
  }
  if ( v281 == 0.0 )
    v284 = 0.0;
  else
    v284 = v35 / fsqrt(v281);
  other.mMotionIntentionDirection.z = v284 * 0.0;
  other.mMotionIntentionDirection.x = v284 * v235;
  other.mMotionIntentionDirection.y = v284 * v236;
  if ( !v276 )
  {
    v285 = (UFG::SimObjectCVBase *)this->m_pContext->mSimObject.m_pPointer;
    if ( v285 )
    {
      v286 = v285->m_Flags;
      if ( (v286 & 0x4000) != 0 || v286 < 0 )
      {
        v287 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v285);
      }
      else if ( (v286 & 0x2000) != 0 )
      {
        v287 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v285);
      }
      else
      {
        v287 = (UFG::CharacterAnimationComponent *)((v286 & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v285,
                                                      UFG::CharacterAnimationComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      v285,
                                                      UFG::CharacterAnimationComponent::_TypeUID));
      }
      v288 = v287;
      if ( v287 )
      {
        mCreature = v287->mCreature;
        if ( mCreature->mPose.mRigHandle.mData )
        {
          BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, symBip01Neck.mUID);
          if ( BoneID >= 0 )
          {
            Translation = Creature::GetTranslation(v288->mCreature, &v322, BoneID);
            v292 = Translation->y;
            v293 = Translation->z;
            other.mDesiredLookAtPoint.x = other.mMotionIntentionDirection.x;
            v294 = other.mMotionIntentionDirection.x + Translation->x;
            other.mDesireToLookAtPoint = 1;
            other.mDesiredLookAtPoint.x = v294;
            other.mDesiredLookAtPoint.y = other.mMotionIntentionDirection.y + v292;
            other.mDesiredLookAtPoint.z = other.mMotionIntentionDirection.z + v293;
          }
        }
      }
    }
  }
LABEL_399:
  other.mMotionIntentionSpeed = v283;
  v301 = (float)(v234 * v234) + (float)(v233 * v233);
  v302 = fsqrt(v301);
  if ( v302 <= 0.001 )
  {
    v307 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( !v307 )
      goto LABEL_417;
    v308 = v307->m_Flags;
    if ( (v308 & 0x4000) != 0 )
    {
      v309 = v307->m_Components.p[7].m_pComponent;
    }
    else if ( v308 >= 0 )
    {
      if ( (v308 & 0x2000) != 0 )
        v309 = v307->m_Components.p[6].m_pComponent;
      else
        v309 = (v308 & 0x1000) != 0
             ? UFG::SimObjectGame::GetComponentOfTypeHK(v307, UFG::ActionTreeComponent::_TypeUID)
             : UFG::SimObject::GetComponentOfType(v307, UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v309 = v307->m_Components.p[7].m_pComponent;
    }
    if ( !v309 )
      goto LABEL_417;
    v310 = p_m_Intention->mMotionIntentionDirectionRaw.y;
    v306 = p_m_Intention->mMotionIntentionDirectionRaw.z;
    other.mMotionIntentionDirectionRaw.x = p_m_Intention->mMotionIntentionDirectionRaw.x;
    other.mMotionIntentionDirectionRaw.y = v310;
  }
  else
  {
    if ( v301 == 0.0 )
      v303 = 0.0;
    else
      v303 = v35 / fsqrt(v301);
    v304 = v303;
    v305 = v303;
    v306 = v303 * 0.0;
    other.mMotionIntentionDirectionRaw.x = v304 * v233;
    other.mMotionIntentionDirectionRaw.y = v305 * v234;
  }
  other.mMotionIntentionDirectionRaw.z = v306;
LABEL_417:
  other.mMotionIntentionSpeedRaw = v302;
  v311 = fsqrt((float)(v238 * v238) + (float)(v237 * v237));
  if ( v311 == 0.0 )
  {
    *(_QWORD *)&other.mFacingIntentionDirection.x = 0i64;
    other.mFacingIntentionDirection.z = 0.0;
  }
  else
  {
    v312 = v35 / v311;
    other.mFacingIntentionDirection.x = other.mFacingIntentionDirection.x * v312;
    other.mFacingIntentionDirection.y = other.mFacingIntentionDirection.y * v312;
    other.mFacingIntentionDirection.z = other.mFacingIntentionDirection.z * v312;
  }
  if ( v283 > 0.0 )
  {
    v313 = UFG::ActionDef_Jog.mDataPerController[m_ControllerID];
    if ( v313 )
      v4 = v313->mOnSeconds;
    Intention::Set(&other, gActionRequest_Jog.m_EnumValue, v4);
  }
  drawStickValues();
  v314 = (UFG::AICharacterControllerComponent *)this->m_pAICharacterControllerComponent.m_pPointer;
  if ( v314 )
  {
    Intention::Set(&other, &v314->m_Intention.mActionRequests);
    Intention::operator=(&v314->m_Intention, &other);
    UFG::AICharacterControllerBaseComponent::UpdateHoldMotionIntention(
      (UFG::AICharacterControllerBaseComponent *)this->m_pAICharacterControllerComponent.m_pPointer,
      timeDelta);
    LOBYTE(this->m_pAICharacterControllerComponent.m_pPointer[15].m_SafePointerList.mNode.mPrev) = 1;
  }
  return 1;
}s->m_pAICharacterControllerComponent.m_pPointer[15].m_SafePointerList.mNode.mPrev) = 1;
  }
  return 1;
}

// File Line: 4551
// RVA: 0x2EF750
void __fastcall HitRecordSetBerserkAttackFlagTask::Begin(
        HitRecordSetBerserkAttackFlagTask *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  unsigned int v5; // edx
  UFG::SimComponent *ComponentOfType; // rax
  bool v7; // zf
  char v8; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      v5 = UFG::HitReactionComponent::_TypeUID;
    }
    else
    {
      v7 = (m_Flags & 0x1000) == 0;
      v5 = UFG::HitReactionComponent::_TypeUID;
      if ( v7 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        goto LABEL_10;
      }
    }
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5);
LABEL_10:
    m_pComponent = ComponentOfType;
    goto LABEL_11;
  }
  m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
LABEL_11:
  v8 = UFG::HitReactionComponent::msBerserkAttackValidFlag;
  if ( m_pComponent )
    v8 = 1;
  UFG::HitReactionComponent::msBerserkAttackValidFlag = v8;
}

// File Line: 4564
// RVA: 0x149ECD0
__int64 dynamic_initializer_for__qwsFaceMeterImpact__()
{
  UFG::qWiseSymbol::create_from_string(&qwsFaceMeterImpact, "Play_face_meter_impact");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__qwsFaceMeterImpact__);
}

// File Line: 4568
// RVA: 0x2F1F90
void __fastcall PlayerBuffActivateTask::Begin(PlayerBuffActivateTask *this, ActionContext *context)
{
  UFG::ePlayerBuffEnum vfptr; // ebx

  vfptr = (UFG::ePlayerBuffEnum)this->m_Track[1].vfptr;
  if ( UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer) )
    UFG::PlayerBuffTracker::ActivateBuff(vfptr);
}

// File Line: 4581
// RVA: 0x2F0150
void __fastcall MoneyDropTask::Begin(MoneyDropTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SceneObjectProperties *m_pSceneObj; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  char m_pSimObject; // cl
  int m_pSimObject_high; // esi
  UFG::qSymbol *v10; // rbx
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SimObjectGame *v13; // rax
  __int16 v14; // dx
  UFG::InventoryItemComponent *ComponentOfTypeHK; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-60h] BYREF
  UFG::qVector3 position; // [rsp+30h] [rbp-50h] BYREF
  UFG::qMatrix44 xform; // [rsp+40h] [rbp-40h] BYREF
  UFG::SpawnInfoInterface::SpawnPriority pOverridePriority; // [rsp+A8h] [rbp+28h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
    m_pSceneObj = m_pPointer->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( m_pSceneObj && m_pTransformNodeComponent && m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[39].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InventoryComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InventoryComponent::_TypeUID);
    if ( m_pComponent )
    {
      if ( (m_pSimObject = (char)m_pComponent[14].m_pSimObject) != 0 && *(_DWORD *)&m_pComponent[14].m_Flags == 68
        || SHIDWORD(m_pComponent[5].m_pSimObject) > 0 )
      {
        if ( !m_pSimObject || (m_pSimObject_high = 1, *(_DWORD *)&m_pComponent[14].m_Flags != 68) )
          m_pSimObject_high = HIDWORD(m_pComponent[5].m_pSimObject);
        HIDWORD(m_pComponent[5].m_pSimObject) = 0;
        UFG::InventoryComponent::UpdateGameStat((UFG::InventoryComponent *)m_pComponent, eINVENTORY_ITEM_MONEY);
        v10 = (UFG::qSymbol *)PropertyUtils::Get<UFG::qSymbol>(
                                m_pSceneObj,
                                (UFG::qArray<unsigned long,0> *)&qSymbol_DropMoney);
        if ( v10 )
        {
          pOverridePriority = High;
          xform = UFG::qMatrix44::msIdentity;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          y = m_pTransformNodeComponent->mWorldTransform.v3.y;
          z = m_pTransformNodeComponent->mWorldTransform.v3.z;
          position.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
          out.x = position.x;
          position.y = y;
          position.z = z;
          out.y = y;
          out.z = z;
          if ( UFG::PlaceOnGround(&out, &position, 0.0, 0.0) )
          {
            xform.v3.x = out.x;
            xform.v3.y = out.y;
            xform.v3.z = out.z;
            LODWORD(xform.v3.w) = (_DWORD)FLOAT_1_0;
            v13 = (UFG::SimObjectGame *)UFG::CreateObject(context, v10, &xform, &pOverridePriority);
            if ( v13 )
            {
              v14 = v13->m_Flags;
              if ( (v14 & 0x4000) == 0 && v14 >= 0 )
              {
                if ( (v14 & 0x2000) != 0 )
                {
                  ComponentOfTypeHK = (UFG::InventoryItemComponent *)v13->m_Components.p[11].m_pComponent;
                }
                else if ( (v14 & 0x1000) != 0 )
                {
                  ComponentOfTypeHK = (UFG::InventoryItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v13,
                                                                       UFG::InventoryItemComponent::_TypeUID);
                }
                else
                {
                  ComponentOfTypeHK = (UFG::InventoryItemComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v13,
                                                                       UFG::InventoryItemComponent::_TypeUID);
                }
                if ( ComponentOfTypeHK )
                  UFG::InventoryItemComponent::SetQuantity(ComponentOfTypeHK, m_pSimObject_high);
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 4627
// RVA: 0x2F03E0
void __fastcall MoneyPickupTask::Begin(MoneyPickupTask *this, ActionContext *context)
{
  UFG::SimObjectGame *Target; // rax
  UFG::SimObject *v3; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *v6; // rax
  int mPrev; // ebx
  UFG::GameStatTracker *v8; // rax
  int v9; // ebx
  UFG::GameStatTracker *v10; // rax
  int v11; // ebx
  UFG::OSuiteLeaderboardManager *v12; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v16; // rax
  int v17; // ebx
  UFG::OSuiteLeaderboardManager *v18; // rax
  UFG::OSuiteLeaderboardData *v19; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+20h] BYREF

  Target = (UFG::SimObjectGame *)UFG::getTarget(context, eTARGET_TYPE_PICKUP_ITEM);
  v3 = Target;
  if ( Target )
  {
    m_Flags = Target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      goto LABEL_20;
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = Target->m_Components.p[11].m_pComponent;
    }
    else
    {
      v6 = (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::InventoryItemComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(Target, UFG::InventoryItemComponent::_TypeUID);
      m_pComponent = v6;
    }
    if ( !m_pComponent || LODWORD(m_pComponent[1].m_pSimObject) != 68 )
      goto LABEL_20;
    mPrev = (int)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v8, Money, mPrev);
    v9 = (int)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
    v10 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v10, TotalCashEarned, v9);
    v11 = (int)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
    v12 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                            v12,
                                            "StatAwardsMogul");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, v11);
    UFG::qSymbol::create_from_string(&result, "ParkingMeterDrop");
    m_pSceneObj = v3->m_pSceneObj;
    if ( m_pSceneObj )
    {
      mpWritableProperties = m_pSceneObj->mpWritableProperties;
      if ( mpWritableProperties )
        goto LABEL_17;
      mpWritableProperties = m_pSceneObj->mpConstProperties;
    }
    else
    {
      mpWritableProperties = 0i64;
    }
    if ( !mpWritableProperties )
    {
LABEL_20:
      UFG::SimObject::Destroy(v3);
      return;
    }
LABEL_17:
    v16 = UFG::qPropertySet::Get<bool>(mpWritableProperties, (UFG::qArray<unsigned long,0> *)&result, DEPTH_RECURSE);
    if ( v16 )
    {
      if ( *v16 )
      {
        v17 = (int)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
        v18 = UFG::OSuiteLeaderboardManager::Instance();
        v19 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v18, "StatGamesCoinsCollected");
        UFG::StatGameManager::UpdateScore(v19, v17, 1);
      }
    }
    goto LABEL_20;
  }
}

// File Line: 4658
// RVA: 0x2EFBE0
void __fastcall ItemPickupTask::Begin(ItemPickupTask *this, ActionContext *context)
{
  UFG::SimObjectGame *Target; // rax
  UFG::SimObject *v3; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v6; // rax
  UFG::ProgressionTracker *v7; // rax
  UFG::GameSlice *ActiveMaster; // rax
  UFG::GameSlice *v9; // rsi
  SSInstance *v10; // rax
  unsigned __int64 mPrev_low; // rdx
  SSInstance *v12; // rax
  __int64 v13; // rcx
  __int64 v14[3]; // [rsp+30h] [rbp-18h] BYREF

  Target = (UFG::SimObjectGame *)UFG::getTarget(context, eTARGET_TYPE_PICKUP_ITEM);
  v3 = Target;
  if ( Target )
  {
    m_Flags = Target->m_Flags;
    if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = Target->m_Components.p[11].m_pComponent;
      }
      else
      {
        v6 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::InventoryItemComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(Target, UFG::InventoryItemComponent::_TypeUID);
        m_pComponent = v6;
      }
      if ( m_pComponent )
      {
        v7 = UFG::ProgressionTracker::Instance();
        ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v7);
        v9 = ActiveMaster;
        if ( ActiveMaster )
        {
          if ( ActiveMaster->mState == STATE_STARTED )
          {
            v10 = SSSymbol::as_instance((ASymbol *)&UFG::InventoryItemEnumSymbols[SLODWORD(m_pComponent[1].m_pSimObject)]);
            mPrev_low = LODWORD(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev);
            v14[0] = (__int64)v10;
            v12 = SSInstance::pool_new(SSBrain::c_integer_class_p, mPrev_low);
            v13 = (__int64)&v9->mScript->SSActor;
            v14[1] = (__int64)v12;
            (*(void (__fastcall **)(__int64, UFG::qStaticSymbol *, __int64 *, __int64, _QWORD, _QWORD))(*(_QWORD *)v13 + 104i64))(
              v13,
              &qSymbol_on_pickup,
              v14,
              2i64,
              0i64,
              0i64);
          }
        }
        UFG::SimObject::Destroy(v3);
      }
    }
  }
}

// File Line: 4694
// RVA: 0x2EE320
void __fastcall FaceMeterActivateTask::Begin(FaceMeterActivateTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceMeterComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::FaceMeterComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::FaceMeterComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::FaceMeterComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::FaceMeterComponent::SetFaceMeterActivated(ComponentOfTypeHK, 1);
  }
}

// File Line: 4708
// RVA: 0x2EE270
void __fastcall FaceInteractionResultSetTask::Begin(FaceInteractionResultSetTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      if ( LOBYTE(m_pComponent[1].m_SafePointerList.mNode.mNext) )
        ((void (__fastcall *)(Expression::IMemberMap *))this->m_Track[1].mResourceOwner->Expression::IMemberMap::vfptr[1].__vecDelDtor)(this->m_Track[1].mResourceOwner);
    }
  }
}

// File Line: 4726
// RVA: 0x2EF250
void __fastcall HealthRegenRateTask::Begin(HealthRegenRateTask *this, ActionContext *pContext)
{
  ITrack *m_Track; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_Track = this->m_Track;
  this->m_pContext = pContext;
  this->m_fPreviousRate = -1.0;
  if ( !LOBYTE(m_Track[1].vfptr) || UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer) )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      if ( m_pComponent )
      {
        this->m_fPreviousRate = *((float *)&m_pComponent[1].m_BoundComponentHandles.mNode.mNext + 1);
        HIDWORD(m_pComponent[1].m_BoundComponentHandles.mNode.mNext) = HIDWORD(this->m_Track[1].vfptr);
      }
    }
  }
}

// File Line: 4744
// RVA: 0x304640
bool __fastcall HealthRegenRateTask::Update(HealthRegenRateTask *this, float timeDelta)
{
  return this->m_fPreviousRate >= 0.0;
}

// File Line: 4757
// RVA: 0x2FEC50
void __fastcall HealthRegenRateTask::End(HealthRegenRateTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( this->m_fPreviousRate >= 0.0 )
  {
    m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      if ( m_pComponent )
        HIDWORD(m_pComponent[1].m_BoundComponentHandles.mNode.mNext) = LODWORD(this->m_fPreviousRate);
    }
  }
}

// File Line: 4773
// RVA: 0x2EF320
void __fastcall HealthRegenerateTask::Begin(HealthRegenerateTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::HealthComponent *m_pComponent; // rax

  if ( !LOBYTE(this->m_Track[1].vfptr) || UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer) )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::HealthComponent *)m_pPointer->m_Components.p[6].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::HealthComponent::_TypeUID);
        else
          m_pComponent = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::HealthComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::HealthComponent *)m_pPointer->m_Components.p[6].m_pComponent;
      }
      if ( m_pComponent )
        UFG::HealthComponent::AddHealthRegenerateTask(m_pComponent, this);
    }
  }
}

// File Line: 4797
// RVA: 0x2EF3D0
void __fastcall HealthReplenishInstantTask::Begin(HealthReplenishInstantTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::HealthComponent *m_pComponent; // rax

  if ( !LOBYTE(this->m_Track[1].vfptr) || UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer) )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::HealthComponent *)m_pPointer->m_Components.p[6].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::HealthComponent::_TypeUID);
        else
          m_pComponent = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::HealthComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::HealthComponent *)m_pPointer->m_Components.p[6].m_pComponent;
      }
      if ( m_pComponent )
        UFG::HealthComponent::ReplenishHealth(m_pComponent);
    }
  }
}

// File Line: 4819
// RVA: 0x2F1BA0
void __fastcall ParkourHandleTask::Begin(ParkourHandleTask *this, ActionContext *pContext)
{
  ITrack *m_Track; // rax
  int vfptr_high; // ebx
  bool v4; // di
  UFG::TransformNodeComponent *i; // r10
  UFG::SimObject *m_pSimObject; // rax

  m_Track = this->m_Track;
  vfptr_high = HIDWORD(m_Track[1].vfptr);
  v4 = LOBYTE(m_Track[1].vfptr) != 0;
  for ( i = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                             pContext->mSimObject.m_pPointer,
                                             UFG::RigidBodyComponent::_TypeUID);
        i;
        i = UFG::SimObject::GetComponentOfType(
              i->m_pSimObject,
              UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
              0,
              i) )
  {
    if ( vfptr_high == -1 || *(_DWORD *)(*(_QWORD *)&i->mWorldTransform.v2.x + 216i64) == vfptr_high )
    {
      m_pSimObject = i[1].m_pSimObject;
      if ( m_pSimObject )
      {
        if ( v4 )
          LODWORD(m_pSimObject[1].mNode.mChild[1]) &= ~8u;
        else
          LODWORD(m_pSimObject[1].mNode.mChild[1]) |= 8u;
      }
    }
  }
}

// File Line: 4857
// RVA: 0x2EFB50
void __fastcall InvulnerableTask::Begin(InvulnerableTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  if ( pContext )
  {
    this->m_pContext = pContext;
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID);
        else
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      if ( m_pComponent )
        BYTE5(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = 1;
    }
  }
}

// File Line: 4870
// RVA: 0x2FEF20
void __fastcall InvulnerableTask::End(InvulnerableTask *this)
{
  ActionContext *m_pContext; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pContext = this->m_pContext;
  if ( m_pContext )
  {
    m_pPointer = (UFG::SimObjectGame *)m_pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID);
        else
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      if ( m_pComponent )
        BYTE5(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 4886
// RVA: 0x2F46C0
void __fastcall SocialSetEnabledTask::Begin(SocialSetEnabledTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( pContext )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      if ( m_pComponent )
        *((_BYTE *)&m_pComponent[3].m_SimObjIndex + 4) = LOBYTE(this->m_Track[1].vfptr) == 0;
    }
  }
}

// File Line: 4901
// RVA: 0x2F4770
void __fastcall SocialSetFaceActionStateTask::Begin(SocialSetFaceActionStateTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceActionComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( pContext )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
        m_pComponent = (UFG::FaceActionComponent *)ComponentOfTypeHK;
      }
      if ( m_pComponent )
        UFG::FaceActionComponent::SetState(m_pComponent, (UFG::eFaceActionState)LOBYTE(this->m_Track[1].vfptr));
    }
  }
}

// File Line: 4914
// RVA: 0x2F4810
void __fastcall SocialSetFastTalkSuccessTask::Begin(SocialSetFastTalkSuccessTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rax
  bool v11; // dl
  UFG::allocator::free_link *v12; // rsi
  const char *mName; // rdi
  unsigned int mUID; // ebx
  UFG::SimObjectCharacter *LocalPlayer; // rax

  if ( pContext )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    v8 = pContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 & 0x4000) != 0 )
      {
        v8 = (UFG::SimObject *)v8->m_Components.p[5].m_pComponent;
      }
      else if ( v9 >= 0 )
      {
        if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)v8,
                              UFG::AIScriptInterfaceComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::AIScriptInterfaceComponent::_TypeUID);
        v8 = (UFG::SimObject *)ComponentOfType;
      }
      else
      {
        v8 = (UFG::SimObject *)v8->m_Components.p[5].m_pComponent;
      }
    }
    v11 = LOBYTE(this->m_Track[1].vfptr) != 0;
    if ( m_pComponent )
    {
      BYTE5(m_pComponent[3].m_SafePointerList.mNode.mPrev) = (LOBYTE(this->m_Track[1].vfptr) != 0) | BYTE5(m_pComponent[3].m_SafePointerList.mNode.mPrev) & 0xFE | 2;
    }
    else if ( v8 )
    {
      BYTE2(v8[16].mNode.mChild[0]) &= ~2u;
      BYTE2(v8[16].mNode.mChild[0]) |= 2 * v11;
    }
    if ( v11 )
    {
      v12 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
      if ( v12 )
      {
        mName = UFG::gGameStatEventChannel.mName;
        mUID = UFG::gGameStatEventChannel.mUID;
        LocalPlayer = UFG::GetLocalPlayer();
        v12[1].mNext = v12 + 1;
        v12[2].mNext = v12 + 1;
        v12->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
        LODWORD(v12[3].mNext) = mUID;
        v12[4].mNext = (UFG::allocator::free_link *)mName;
        v12->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable;
        LODWORD(v12[7].mNext) = 41;
        v12[8].mNext = (UFG::allocator::free_link *)LocalPlayer;
      }
      else
      {
        v12 = 0i64;
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v12);
    }
  }
}

// File Line: 4944
// RVA: 0x2F45A0
void __fastcall SocialFaceActionDisplayConfirmationDialogTask::Begin(
        SocialFaceActionDisplayConfirmationDialogTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v6; // r8
  __int16 v7; // cx
  UFG::FaceActionComponent *ComponentOfType; // rax

  if ( pContext )
  {
    this->m_pContext = pContext;
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    v6 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 58i64)
                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                + 40);
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 & 0x4000) != 0 )
      {
        ComponentOfType = (UFG::FaceActionComponent *)v6->m_Components.p[45].m_pComponent;
      }
      else if ( v7 < 0 || (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v6,
                                                        UFG::FaceActionComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                        v6,
                                                        UFG::FaceActionComponent::_TypeUID);
      }
      if ( ComponentOfType )
        UFG::FaceActionComponent::OpenConfirmationDialog(ComponentOfType);
    }
  }
}

// File Line: 4960
// RVA: 0x30A060
bool __fastcall SocialFaceActionDisplayConfirmationDialogTask::Update(
        SocialFaceActionDisplayConfirmationDialogTask *this,
        float __formal)
{
  ActionContext *m_pContext; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::FaceActionComponent *ComponentOfType; // rax
  bool result; // al

  m_pContext = this->m_pContext;
  result = !m_pContext
        || ((m_pPointer = (UFG::SimObjectGame *)m_pContext->mSimObject.m_pPointer) != 0i64
          ? ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
           ? (m_Flags >= 0
            ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
             ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      m_pPointer,
                                      UFG::TargetingSystemBaseComponent::_TypeUID))
             : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                      m_pPointer,
                                      UFG::TargetingSystemBaseComponent::_TypeUID)),
               m_pComponent = ComponentOfTypeHK)
            : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = 0i64),
            (v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 58i64)
                                         + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                         + 40)) == 0i64
         || ((v8 = v7->m_Flags, (v8 & 0x4000) == 0)
           ? (v8 >= 0 && (v8 & 0x2000) == 0 && (v8 & 0x1000) == 0
            ? (ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                               v7,
                                                               UFG::FaceActionComponent::_TypeUID))
            : (ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v7,
                                                               UFG::FaceActionComponent::_TypeUID)))
           : (ComponentOfType = (UFG::FaceActionComponent *)v7->m_Components.p[45].m_pComponent),
             !ComponentOfType))
        || !UFG::FaceActionComponent::IsConfirmationDialogComplete(ComponentOfType);
  return result;
}

// File Line: 4980
// RVA: 0x2F9F50
void __fastcall TriggerRecoilPostEffectTask::Begin(TriggerRecoilPostEffectTask *this, ActionContext *context)
{
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  __int64 v5; // rax
  ITrack *m_Track; // rax
  float v7; // xmm6_4
  float v8; // xmm0_4

  if ( context )
  {
    CurrentGameCamera = UFG::GetCurrentGameCamera();
    if ( CurrentGameCamera )
    {
      v5 = ((__int64 (__fastcall *)(UFG::GameCameraComponent *))CurrentGameCamera->vfptr[41].__vecDelDtor)(CurrentGameCamera);
      if ( v5 )
      {
        if ( *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v5 + 96) + 25i64) + *(_QWORD *)(v5 + 88) + 40) == context->mSimObject.m_pPointer )
        {
          m_Track = this->m_Track;
          v7 = *(float *)&m_Track[1].vfptr;
          v8 = *((float *)&m_Track[1].vfptr + 1);
          if ( v8 >= v7 )
            v7 = UFG::qRandom(v8 - v7, (unsigned int *)&UFG::qDefaultSeed) + v7;
          UFG::RenderWorld::GunRecoilPostEffect_TriggerRecoil(v7, *(float *)&this->m_Track[1].mResourceOwner);
        }
      }
    }
  }
}

// File Line: 5008
// RVA: 0x2DD570
void __fastcall AccuracyModifierTask::AccuracyModifierTask(AccuracyModifierTask *this)
{
  this->Task<AccuracyModifierTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AccuracyModifierTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AccuracyModifierTrack>::`vftable;
  this->UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList>::mPrev = &this->UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList>;
  this->UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList>::mNext = &this->UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList>;
  this->vfptr = (ITaskVtbl *)&AccuracyModifierTask::`vftable;
  *((_BYTE *)this + 64) = *((_BYTE *)this + 64) & 0xFC | 1;
}

// File Line: 5018
// RVA: 0x2E7FE0
void __fastcall AccuracyModifierTask::Begin(AccuracyModifierTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AimingBaseComponent *m_pComponent; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::AimingBaseComponent *)m_pPointer->m_Components.p[47].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::AimingBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::AimingBaseComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::AimingBaseComponent::AddAccuracyModifierTask(m_pComponent, this);
  }
}

// File Line: 5029
// RVA: 0x3039A0
char __fastcall AccuracyModifierTask::Update(AccuracyModifierTask *this, float timestep)
{
  char v2; // al

  if ( LOBYTE(this->m_Track[1].mMasterRate.text.mOffset) )
    return 1;
  v2 = *((_BYTE *)this + 64);
  if ( (v2 & 2) == 0 )
    return 1;
  *((_BYTE *)this + 64) = v2 & 0xFE;
  return 0;
}

// File Line: 5044
// RVA: 0x2FECF0
void __fastcall AimingSoftLockTask::End(TargetSteerToTask *this)
{
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *mNext; // rax
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *v2; // rdx
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *mPrev; // rcx

  mNext = this->UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList>::mNext;
  v2 = &this->UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList>;
  mPrev = this->UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList>::mPrev;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
}

// File Line: 5053
// RVA: 0x2DE670
void __fastcall CollectibleCollectTask::CollectibleCollectTask(CollectibleCollectTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CollectibleCollectTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CollectibleCollectTask::`vftable;
}

// File Line: 5062
// RVA: 0x2EAA70
void __fastcall CollectibleCollectTask::Begin(CollectibleCollectTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int64 vfptr_high; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v15; // rdx

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  vfptr_high = HIDWORD(this->m_Track[1].vfptr);
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
        }
        else if ( v8 >= 0 )
        {
          if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v7,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
          v7 = (UFG::SimObjectGame *)ComponentOfTypeHK;
        }
        else
        {
          v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
        }
      }
      v10 = ((__int64 (__fastcall *)(UFG::SimObjectGame *))v7->vfptr[15].__vecDelDtor)(v7);
      if ( v10 )
      {
        v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v10 + 96) + vfptr_high + 8)
                        + *(_QWORD *)(v10 + 88)
                        + 40);
        if ( v11 )
        {
          v12 = *(UFG::SimObjectGame **)(*(_QWORD *)(v11 + 80) + 96i64);
          if ( v12 )
          {
            v13 = v12->m_Flags;
            if ( (v13 & 0x4000) != 0 || v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
              ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID);
            else
              ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::CollectibleComponent::_TypeUID);
            if ( ComponentOfType )
            {
              LOBYTE(v15) = 1;
              ComponentOfType->vfptr[24].__vecDelDtor(ComponentOfType, v15);
            }
          }
        }
      }
    }
  }
}

// File Line: 5104
// RVA: 0x2E7EA0
void __fastcall AIOutlineActivateTask::Begin(AIOutlineActivateTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AIOutlineComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::AIOutlineComponent *)m_pPointer->m_Components.p[27].m_pComponent;
    goto LABEL_11;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIOutlineComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIOutlineComponent::_TypeUID);
  m_pComponent = (UFG::AIOutlineComponent *)ComponentOfTypeHK;
LABEL_11:
  if ( m_pComponent )
  {
    if ( LOBYTE(this->m_Track[1].vfptr) )
      UFG::AIOutlineComponent::ActivateOutline(m_pComponent);
    else
      UFG::AIOutlineComponent::DeactivateOutline(m_pComponent);
  }
}

// File Line: 5128
// RVA: 0x2E0F20
void __fastcall SimObjectFlagSetTask::SimObjectFlagSetTask(SimObjectFlagSetTask *this)
{
  this->Task<SimObjectFlagSetTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<SimObjectFlagSetTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SimObjectFlagSetTrack>::`vftable;
  this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>::mPrev = &this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>;
  this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>::mNext = &this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>;
  this->vfptr = (ITaskVtbl *)&SimObjectFlagSetTask::`vftable;
  this->m_SimObjectPropertiesComponent.mPrev = &this->m_SimObjectPropertiesComponent;
  this->m_SimObjectPropertiesComponent.mNext = &this->m_SimObjectPropertiesComponent;
  this->m_SimObjectPropertiesComponent.m_pPointer = 0i64;
}

// File Line: 5133
// RVA: 0x2E4F20
void __fastcall SimObjectFlagSetTask::~SimObjectFlagSetTask(SimObjectFlagSetTask *this)
{
  UFG::SimObjectPropertiesComponent *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectPropertiesComponent> *p_m_SimObjectPropertiesComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v8; // rcx
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v9; // rax
  UFG::qNode<ITask,ITask> *v10; // rcx
  UFG::qNode<ITask,ITask> *v11; // rax

  this->vfptr = (ITaskVtbl *)&SimObjectFlagSetTask::`vftable;
  m_pPointer = (UFG::SimObjectPropertiesComponent *)this->m_SimObjectPropertiesComponent.m_pPointer;
  if ( m_pPointer )
    UFG::SimObjectPropertiesComponent::UpdateCachedValues(m_pPointer);
  p_m_SimObjectPropertiesComponent = &this->m_SimObjectPropertiesComponent;
  if ( this->m_SimObjectPropertiesComponent.m_pPointer )
  {
    mPrev = p_m_SimObjectPropertiesComponent->mPrev;
    mNext = this->m_SimObjectPropertiesComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_SimObjectPropertiesComponent->mPrev = p_m_SimObjectPropertiesComponent;
    this->m_SimObjectPropertiesComponent.mNext = &this->m_SimObjectPropertiesComponent;
  }
  this->m_SimObjectPropertiesComponent.m_pPointer = 0i64;
  v6 = p_m_SimObjectPropertiesComponent->mPrev;
  v7 = this->m_SimObjectPropertiesComponent.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_m_SimObjectPropertiesComponent->mPrev = p_m_SimObjectPropertiesComponent;
  this->m_SimObjectPropertiesComponent.mNext = &this->m_SimObjectPropertiesComponent;
  v8 = this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>::mPrev;
  v9 = this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>::mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>::mPrev = &this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>;
  this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>::mNext = &this->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v10 = this->Task<SimObjectFlagSetTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev;
  v11 = this->Task<SimObjectFlagSetTrack>::ITask::UFG::qNode<ITask,ITask>::mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->Task<SimObjectFlagSetTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<SimObjectFlagSetTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 5142
// RVA: 0x2F4270
void __fastcall SimObjectFlagSetTask::Begin(SimObjectFlagSetTask *this, ActionContext *pActionContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectPropertiesComponent *m_pComponent; // r9
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectPropertiesComponent> *p_m_SimObjectPropertiesComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  this->m_pActionContext = pActionContext;
  m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::SimObjectPropertiesComponent *)m_pPointer->m_Components.p[3].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::SimObjectPropertiesComponent *)m_pPointer->m_Components.p[4].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::SimObjectPropertiesComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::SimObjectPropertiesComponent::_TypeUID);
        m_pComponent = (UFG::SimObjectPropertiesComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::SimObjectPropertiesComponent *)m_pPointer->m_Components.p[3].m_pComponent;
    }
    if ( m_pComponent )
    {
      p_m_SimObjectPropertiesComponent = &this->m_SimObjectPropertiesComponent;
      if ( this->m_SimObjectPropertiesComponent.m_pPointer )
      {
        mPrev = p_m_SimObjectPropertiesComponent->mPrev;
        mNext = this->m_SimObjectPropertiesComponent.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_SimObjectPropertiesComponent->mPrev = p_m_SimObjectPropertiesComponent;
        this->m_SimObjectPropertiesComponent.mNext = &this->m_SimObjectPropertiesComponent;
      }
      this->m_SimObjectPropertiesComponent.m_pPointer = m_pComponent;
      v10 = m_pComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v10->mNext = p_m_SimObjectPropertiesComponent;
      this->m_SimObjectPropertiesComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      p_m_SimObjectPropertiesComponent->mPrev = v10;
      m_pComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_SimObjectPropertiesComponent;
      UFG::SimObjectPropertiesComponent::AddSimObjectFlagSetTask(
        m_pComponent,
        (UFG::eSimObjectFlagEnum)this->m_Track[1].vfptr,
        this);
    }
  }
}

// File Line: 5162
// RVA: 0x2F3870
void __fastcall SetRollStabilityTask::Begin(SetRollStabilityTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
      {
        mPrev = ComponentOfTypeHK[10].m_SafePointerList.mNode.mPrev;
        if ( mPrev )
        {
          if ( (HIDWORD(mPrev[37].mNext) & 7) == 4 )
            LODWORD(mPrev[36].mNext) = this->m_Track[1].vfptr;
        }
      }
    }
  }
}

// File Line: 5185
// RVA: 0x2F3620
void __fastcall SetCharacterOnFireTask::Begin(SetCharacterOnFireTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterEffectsComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterEffectsComponent *)m_pPointer->m_Components.p[38].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::CharacterEffectsComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::CharacterEffectsComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::CharacterEffectsComponent::ForceIgniteFire(m_pComponent);
  }
}

// File Line: 5198
// RVA: 0x2F3590
void __fastcall SetCharacterInvulnerableToFireTask::Begin(
        SetCharacterInvulnerableToFireTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::CharacterEffectsComponent *m_pComponent; // rax
  __int16 m_Flags; // dx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterEffectsComponent *)m_pPointer->m_Components.p[38].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::CharacterEffectsComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::CharacterEffectsComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  this->mCharacterEffectsComponent = m_pComponent;
  if ( m_pComponent )
    m_pComponent->InvulnerableToFire = 1;
}

// File Line: 5208
// RVA: 0x300220
void __fastcall SetCharacterInvulnerableToFireTask::End(SetCharacterInvulnerableToFireTask *this)
{
  UFG::CharacterEffectsComponent *mCharacterEffectsComponent; // rax

  mCharacterEffectsComponent = this->mCharacterEffectsComponent;
  if ( mCharacterEffectsComponent )
    mCharacterEffectsComponent->InvulnerableToFire = 0;
}

// File Line: 5220
// RVA: 0x2EDD40
void __fastcall DisableSelfIlluminationTask::Begin(DisableSelfIlluminationTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::CharacterLookComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::SimObjectGame *v7; // rcx
  UFG::CompositeLookComponent *ComponentOfType; // rax
  __int16 v9; // dx
  UFG::CharacterLookComponent *mCharacterLookComponent; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::CharacterLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::CharacterLookComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::CharacterLookComponent *)UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::CharacterLookComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  this->mCharacterLookComponent = ComponentOfTypeHK;
  v7 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
      ComponentOfType = (UFG::CompositeLookComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v7,
                                                         UFG::CompositeLookComponent::_TypeUID);
    else
      ComponentOfType = (UFG::CompositeLookComponent *)UFG::SimObject::GetComponentOfType(
                                                         v7,
                                                         UFG::CompositeLookComponent::_TypeUID);
  }
  else
  {
    ComponentOfType = 0i64;
  }
  mCharacterLookComponent = this->mCharacterLookComponent;
  this->mCompositeLookComponent = ComponentOfType;
  if ( mCharacterLookComponent )
  {
    mCharacterLookComponent->mSceneryInstance->SIColourTint[3] = 0.0;
  }
  else if ( ComponentOfType )
  {
    ComponentOfType->mSceneryInstance->SIColourTint[3] = 0.0;
  }
}

// File Line: 5236
// RVA: 0x2FEB80
void __fastcall DisableSelfIlluminationTask::End(DisableSelfIlluminationTask *this)
{
  UFG::CharacterLookComponent *mCharacterLookComponent; // rax

  mCharacterLookComponent = this->mCharacterLookComponent;
  if ( mCharacterLookComponent
    || (mCharacterLookComponent = (UFG::CharacterLookComponent *)this->mCompositeLookComponent) != 0i64 )
  {
    mCharacterLookComponent->mSceneryInstance->SIColourTint[3] = 1.0;
  }
}

// File Line: 5252
// RVA: 0x2F1FC0
void __fastcall PlayerGainHealthBasedOnActiveBuffTask::Begin(
        PlayerGainHealthBasedOnActiveBuffTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::HealthComponent *m_pComponent; // rsi
  UFG::SimComponent *v5; // rax
  int m_fHealth; // ebx
  int m_fMaxHealth; // edi
  UFG::GameStatTracker *v8; // rax
  int v9; // ebx
  int v10; // eax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::HealthComponent *)m_pPointer->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID);
      m_pComponent = (UFG::HealthComponent *)v5;
    }
    else
    {
      m_pComponent = (UFG::HealthComponent *)m_pPointer->m_Components.p[6].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_fHealth = (int)m_pComponent->m_fHealth;
      m_fMaxHealth = (int)m_pComponent->m_fMaxHealth;
      v8 = UFG::GameStatTracker::Instance();
      v9 = (int)UFG::GameStatTracker::GetStat(v8, PlayerFaceMeterBuff_HealthPerHitGainedAtLevel2) + m_fHealth;
      v10 = 0;
      if ( v9 > 0 )
        v10 = v9;
      if ( v10 < m_fMaxHealth )
        m_fMaxHealth = v10;
      UFG::HealthComponent::SetHealth(m_pComponent, m_fMaxHealth, 0i64);
    }
  }
}

// File Line: 5280
// RVA: 0x2E0CB0
void __fastcall ResourceOpportunityTask::ResourceOpportunityTask(ResourceOpportunityTask *this)
{
  UFG::PowerManagedResource *v2; // rcx

  this->Task<ResourceOpportunityTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<ResourceOpportunityTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->Task<ResourceOpportunityTrack>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->Task<ResourceOpportunityTrack>::ITask::vfptr = (ITaskVtbl *)&Task<ResourceOpportunityTrack>::`vftable;
  v2 = &this->UFG::PowerManagedResource;
  v2->mPrev = &v2->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  v2->mNext = &v2->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  v2->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::PowerManagedResource::`vftable;
  this->Task<ResourceOpportunityTrack>::ITask::vfptr = (ITaskVtbl *)&ResourceOpportunityTask::`vftable{for `Task<ResourceOpportunityTrack>};
  v2->vfptr = (UFG::PowerManagedResourceVtbl *)&ResourceOpportunityTask::`vftable{for `UFG::PowerManagedResource};
  this->mContext = 0i64;
  this->mLatchedNode = 0i64;
  this->mNameUID = 0;
  this->mLatchedNodeResourcesGathered = 0;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  this->mAnimationGroupHandleContainer.m_bHasBeenBound = 0;
}

// File Line: 5285
// RVA: 0x2F3230
void __fastcall ResourceOpportunityTask::Begin(ResourceOpportunityTask *this, ActionContext *context)
{
  UFG::SimObject *m_pPointer; // rax
  ResourceOpportunityTrack *m_Track; // rdx
  ActionNode *m_OpeningBranch; // rdi
  __int64 mOffset; // rax
  char *v8; // rax
  __int64 v9; // rcx
  ActionPath *ActionPath; // rax
  Expression::IMemberMap *v11; // rbp
  ActionNodeRoot *v12; // rax
  __int64 mValue; // r8
  ActionNodeRoot *v14; // rdi
  UFG::ActionTreeComponentBase *v15; // rcx

  this->mContext = context;
  m_pPointer = context->mSimObject.m_pPointer;
  if ( m_pPointer )
    this->mNameUID = m_pPointer->mNode.mUID;
  m_Track = (ResourceOpportunityTrack *)this->m_Track;
  m_OpeningBranch = 0i64;
  mOffset = m_Track->mActionNodeReference.mOffset;
  if ( mOffset )
    v8 = (char *)&m_Track->mActionNodeReference + mOffset;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 9);
  if ( v9 )
    m_OpeningBranch = (ActionNode *)&v8[v9 + 72];
  ActionPath = ResourceOpportunityTrack::GetActionPath(m_Track);
  if ( !m_OpeningBranch && (ActionPath->mPath.mCount & 0x7FFFFFFF) == 0 )
    m_OpeningBranch = this->mContext->m_OpeningBranch;
  v11 = context->m_OpeningBranch->vfptr[1].GetResourceOwner(context->m_OpeningBranch);
  v12 = (ActionNodeRoot *)m_OpeningBranch->vfptr[1].GetResourceOwner(m_OpeningBranch);
  mValue = v12->mActionTreeType.mValue;
  v14 = v12;
  if ( (context->mActionTreeComponentBase[mValue] || context->mActionTreeComponentBase[1]) && v11 != v12 )
  {
    v15 = context->mActionTreeComponentBase[mValue];
    if ( !v15 )
      v15 = context->mActionTreeComponentBase[1];
    if ( UFG::ActionTreeComponentBase::AllocateFor(v15, v12) )
      ActionNodeRoot::Init(v14, this->mContext);
  }
}

// File Line: 5316
// RVA: 0x309F00
bool __fastcall ResourceOpportunityTask::Update(ResourceOpportunityTask *this, float timeDelta)
{
  ResourceOpportunityTrack *m_Track; // rcx
  ActionNode *m_OpeningBranch; // rdi
  __int64 mOffset; // rax
  char *v7; // rax
  __int64 v8; // rdx
  ActionPath *ActionPath; // rax
  __int64 v10; // rax
  ActionNodePlayable *v11; // rax
  float v12; // xmm1_4
  bool v13; // di
  bool v14; // al

  if ( !this->mLatchedNode
    && (UFG::Metrics::msInstance.mSimFrameCount + this->mNameUID) % SHIWORD(this->m_Track[1].m_TrackClassNameUID) )
  {
    return 1;
  }
  m_Track = (ResourceOpportunityTrack *)this->m_Track;
  m_OpeningBranch = 0i64;
  mOffset = m_Track->mActionNodeReference.mOffset;
  if ( mOffset )
    v7 = (char *)&m_Track->mActionNodeReference + mOffset;
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 9);
  if ( v8 )
    m_OpeningBranch = (ActionNode *)&v7[v8 + 72];
  ActionPath = ResourceOpportunityTrack::GetActionPath(m_Track);
  if ( !m_OpeningBranch )
  {
    if ( (ActionPath->mPath.mCount & 0x7FFFFFFF) != 0 )
      return 0;
    m_OpeningBranch = this->mContext->m_OpeningBranch;
    if ( !m_OpeningBranch )
      return 0;
  }
  if ( !this->mLatchedNode )
  {
    v10 = ((__int64 (__fastcall *)(ITrack *))this->m_Track->Task<ResourceOpportunityTrack>::ITask::vfptr[2].__vecDelDtor)(this->m_Track);
    if ( !v10
      || (*(unsigned __int8 (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v10 + 80i64))(v10, this->mContext) )
    {
      v11 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))m_OpeningBranch->vfptr[2].GetClassNameUID)(
                                    m_OpeningBranch,
                                    this->mContext);
      if ( v11 )
      {
        if ( BYTE1(this->m_Track[1].m_TrackClassNameUID) )
        {
          this->mLatchedNode = v11;
        }
        else if ( this->mContext->mActionController->m_currentNode != v11 )
        {
          this->mLatchedNode = v11;
        }
      }
    }
    if ( !this->mLatchedNode )
      return 1;
  }
  v12 = *(float *)&this->m_Track[1].mBreakPoint;
  v13 = v12 >= 0.0 && v12 <= this->mContext->mActionController->m_ActionNodePlayTime;
  v14 = ResourceOpportunityTask::areResourcesStreamedIn(this);
  return !v13 || !v14;
}

// File Line: 5411
// RVA: 0x303940
void __fastcall ResourceOpportunityTask::UnbindResources(ResourceOpportunityTask *this)
{
  float *p_m_TimeBegin; // rsi
  AnimationGroupHandle *v3; // rbx

  p_m_TimeBegin = &this->m_TimeBegin;
  v3 = (AnimationGroupHandle *)&this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext[-1];
  if ( v3 == (AnimationGroupHandle *)&this->m_TimeBegin )
  {
    LOBYTE(this->mContext) = 0;
  }
  else
  {
    do
    {
      AnimationGroupHandle::Unbind(v3);
      v3 = (AnimationGroupHandle *)&v3->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v3 != (AnimationGroupHandle *)p_m_TimeBegin );
    LOBYTE(this->mContext) = 0;
  }
}

// File Line: 5418
// RVA: 0x3035B0
void __fastcall ResourceOpportunityTask::RebindResources(ResourceOpportunityTask *this)
{
  float *p_m_TimeBegin; // rdi
  AnimationGroupHandle *v2; // rbx

  p_m_TimeBegin = &this->m_TimeBegin;
  v2 = (AnimationGroupHandle *)&this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext[-1];
  if ( v2 != (AnimationGroupHandle *)&this->m_TimeBegin )
  {
    do
    {
      if ( !v2->m_AnimationGroup.m_pPointer )
        AnimationGroupHandle::Bind(v2);
      v2 = (AnimationGroupHandle *)&v2->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v2 != (AnimationGroupHandle *)p_m_TimeBegin );
  }
}

// File Line: 5425
// RVA: 0x2E7D30
char __fastcall ResourceOpportunityTask::AreResourcesAvailable(ResourceOpportunityTask *this)
{
  float *p_m_TimeBegin; // rdi
  ResourceOpportunityTask *p_value; // rbx
  AnimationGroup *mNext; // rcx

  p_m_TimeBegin = &this->m_TimeBegin;
  p_value = (ResourceOpportunityTask *)&this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext[-1];
  if ( p_value == (ResourceOpportunityTask *)&this->m_TimeBegin )
    return 1;
  while ( 1 )
  {
    mNext = (AnimationGroup *)p_value->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext;
    if ( !mNext || !AnimationGroup::IsStreamedIn(mNext) )
      break;
    p_value = (ResourceOpportunityTask *)&p_value->m_Track[-1].mMasterRate.value;
    if ( p_value == (ResourceOpportunityTask *)p_m_TimeBegin )
      return 1;
  }
  return 0;
}

// File Line: 5454
// RVA: 0x30BAB0
void __fastcall ResourceOpportunityVisitor::Visit(ResourceOpportunityVisitor *this, AnimationNode *node)
{
  SkeletalAnimation *m_pPointer; // rdi
  ResourceOpportunityTask *m_pResourceOpportunityTask; // rbx
  bool v4; // zf
  ITrack *m_Track; // rax
  UFG::eAnimationPriorityEnum v6; // r8d
  __int64 mOffset; // rax
  UFG::qSymbolUC *v8; // rdx

  m_pPointer = node->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  m_pResourceOpportunityTask = this->m_pResourceOpportunityTask;
  if ( m_pPointer )
  {
    v4 = !UFG::IsAnyLocalPlayer(m_pResourceOpportunityTask->mContext->mSimObject.m_pPointer);
    m_Track = m_pResourceOpportunityTask->m_Track;
    if ( v4 )
      v6 = BYTE5(m_Track[1].mMasterRate.text.mOffset);
    else
      v6 = BYTE4(m_Track[1].mMasterRate.text.mOffset);
    mOffset = m_pPointer->m_pAnimationGroup.mOffset;
    if ( mOffset )
      v8 = (UFG::qSymbolUC *)((char *)&m_pPointer->m_pAnimationGroup + mOffset);
    else
      v8 = 0i64;
    AnimationGroupHandleContainer::Add(&m_pResourceOpportunityTask->mAnimationGroupHandleContainer, v8 + 43, v6);
  }
}

// File Line: 5462
// RVA: 0x2E7A70
void __fastcall ResourceOpportunityTask::AddAnimation(ResourceOpportunityTask *this, SkeletalAnimation *pSA)
{
  bool v4; // zf
  ITrack *m_Track; // rax
  UFG::eAnimationPriorityEnum v6; // r8d
  __int64 mOffset; // rax
  UFG::qSymbolUC *v8; // rdx

  if ( pSA )
  {
    v4 = !UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer);
    m_Track = this->m_Track;
    if ( v4 )
      v6 = BYTE5(m_Track[1].mMasterRate.text.mOffset);
    else
      v6 = BYTE4(m_Track[1].mMasterRate.text.mOffset);
    mOffset = pSA->m_pAnimationGroup.mOffset;
    if ( mOffset )
      v8 = (UFG::qSymbolUC *)((char *)&pSA->m_pAnimationGroup + mOffset);
    else
      v8 = 0i64;
    AnimationGroupHandleContainer::Add(&this->mAnimationGroupHandleContainer, v8 + 43, v6);
  }
}

// File Line: 5481
// RVA: 0x30D230
void __fastcall ResourceOpportunityTask::gatherResources(ResourceOpportunityTask *this)
{
  ActionNodePlayable *mLatchedNode; // rcx
  __int64 v3; // rax
  __int64 v4; // rbp
  __int64 v5; // r15
  __int64 v6; // rsi
  UFG::qSymbolUC *v7; // rbx
  bool v8; // zf
  __int64 v9; // rax
  SkeletalAnimation *v10; // rax
  BlendTreeDataBase *Instance; // rax
  PoseNode *BlendTree; // rax
  Expression::IMemberMapVtbl *vfptr; // r8
  void **v14; // [rsp+20h] [rbp-38h] BYREF
  char v15; // [rsp+28h] [rbp-30h]
  UFG::qSymbolUC *v16; // [rsp+30h] [rbp-28h]
  ResourceOpportunityTask *v17; // [rsp+38h] [rbp-20h]

  mLatchedNode = this->mLatchedNode;
  if ( mLatchedNode )
  {
    v3 = ((__int64 (*)(void))mLatchedNode->vfptr[3].GetClassNameUID)();
    v4 = v3;
    if ( v3 )
    {
      v5 = *(_QWORD *)(v3 + 24) + v3 + 24;
      v6 = 0i64;
      if ( (*(_DWORD *)(v3 + 16) & 0x7FFFFFFF) != 0 )
      {
        do
        {
          v7 = (UFG::qSymbolUC *)(v5 + 8 * v6 + *(_QWORD *)(v5 + 8 * v6));
          v8 = (*(unsigned int (__fastcall **)(UFG::qSymbolUC *))(*(_QWORD *)&v7->mUID + 40i64))(v7) == AnimationTrack::sClassNameUID;
          v9 = *(_QWORD *)&v7->mUID;
          if ( v8 )
          {
            v10 = (SkeletalAnimation *)(*(__int64 (__fastcall **)(UFG::qSymbolUC *))(v9 + 128))(v7);
            ResourceOpportunityTask::AddAnimation(this, v10);
          }
          else if ( (*(unsigned int (__fastcall **)(UFG::qSymbolUC *))(v9 + 40))(v7) == BlendTreeTrack::sClassNameUID )
          {
            Instance = BlendTreeDataBase::GetInstance();
            BlendTree = BlendTreeDataBase::FindBlendTree(Instance, v7 + 16);
            if ( BlendTree )
            {
              vfptr = BlendTree->Expression::IMemberMap::vfptr;
              v15 = 1;
              v14 = &ResourceOpportunityVisitor::`vftable;
              v16 = v7;
              v17 = this;
              vfptr[1].FindWithOldPath(BlendTree, (const char *)&v14);
            }
          }
          v6 = (unsigned int)(v6 + 1);
        }
        while ( (unsigned int)v6 < (*(_DWORD *)(v4 + 16) & 0x7FFFFFFFu) );
      }
    }
  }
}

// File Line: 5516
// RVA: 0x30CA30
char __fastcall ResourceOpportunityTask::areResourcesStreamedIn(ResourceOpportunityTask *this)
{
  ActionContext *mContext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mNext; // rax
  ActionNodePlayable **p_mLatchedNode; // rdi
  __int64 v8; // rbx
  AnimationGroup *v9; // rcx

  if ( !this->mLatchedNodeResourcesGathered )
  {
    ResourceOpportunityTask::gatherResources(this);
    AnimationGroupHandleContainer::Bind(&this->mAnimationGroupHandleContainer);
    mContext = this->mContext;
    this->mLatchedNodeResourcesGathered = 1;
    m_pPointer = (UFG::SimObjectGame *)mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               m_pPointer,
                                                               UFG::PowerManagementComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pPointer,
                                                               UFG::PowerManagementComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        UFG::PowerManagementComponent::AddPowerManagedResource(ComponentOfTypeHK, &this->UFG::PowerManagedResource);
    }
  }
  mNext = this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext;
  p_mLatchedNode = &this->mLatchedNode;
  v8 = (__int64)&mNext[-1];
  if ( &mNext[-1] == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)p_mLatchedNode )
    return 1;
  while ( 1 )
  {
    v9 = *(AnimationGroup **)(v8 + 56);
    if ( !v9 || !AnimationGroup::IsStreamedIn(v9) )
      break;
    v8 = *(_QWORD *)(v8 + 24) - 16i64;
    if ( (ActionNodePlayable **)v8 == p_mLatchedNode )
      return 1;
  }
  return 0;
}

// File Line: 5584
// RVA: 0x2FFF00
void __fastcall ResourceOpportunityTask::End(ResourceOpportunityTask *this)
{
  bool v2; // zf
  ITrack *m_Track; // rax
  UFG::eAnimationPriorityEnum priority; // r14d
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mPrev; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mNext; // rax
  ActionContext *mContext; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActionTreeResourcesComponent *m_pComponent; // rsi
  UFG::SimComponent *v11; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *i; // rbx
  int mCount; // edx
  ActionPath pathToPopulate; // [rsp+48h] [rbp-30h] BYREF

  v2 = !UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer);
  m_Track = this->m_Track;
  if ( v2 )
    priority = BYTE5(m_Track[1].mMasterRate.text.mOffset);
  else
    priority = BYTE4(m_Track[1].mMasterRate.text.mOffset);
  mPrev = this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mPrev;
  mNext = this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mPrev = &this->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext = &this->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  if ( this->mLatchedNode )
  {
    if ( ResourceOpportunityTask::areResourcesStreamedIn(this) )
    {
      mContext = this->mContext;
      if ( mContext )
      {
        m_pPointer = (UFG::SimObjectGame *)mContext->mSimObject.m_pPointer;
        if ( m_pPointer )
        {
          m_Flags = m_pPointer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::ActionTreeResourcesComponent *)m_pPointer->m_Components.p[30].m_pComponent;
          }
          else
          {
            v11 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeResourcesComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeResourcesComponent::_TypeUID);
            m_pComponent = (UFG::ActionTreeResourcesComponent *)v11;
          }
          if ( m_pComponent )
          {
            for ( i = this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext - 1;
                  i != (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&this->mLatchedNode;
                  i = i[1].mNext - 1 )
            {
              pathToPopulate.mPath.mCount = 0;
              pathToPopulate.mPath.mData.mOffset = 0i64;
              ActionNode::GetNameFullPath(this->mLatchedNode, &pathToPopulate);
              UFG::ActionTreeResourcesComponent::RequestAnimationBank(
                m_pComponent,
                &pathToPopulate,
                this->mLatchedNode,
                1,
                (UFG::qSymbolUC *)&i[2],
                priority);
              mCount = pathToPopulate.mPath.mCount;
              if ( pathToPopulate.mPath.mCount >= 0 )
              {
                if ( pathToPopulate.mPath.mData.mOffset )
                {
                  if ( (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData
                                                    + pathToPopulate.mPath.mData.mOffset) )
                  {
                    operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
                    mCount = pathToPopulate.mPath.mCount;
                  }
                }
                pathToPopulate.mPath.mData.mOffset = 0i64;
                pathToPopulate.mPath.mCount = mCount & 0x80000000;
              }
            }
          }
        }
        ActionController::Sequence(
          this->mContext->mActionController,
          this->mLatchedNode,
          SLOBYTE(this->m_Track[1].m_TrackClassNameUID),
          1);
      }
    }
  }
}

