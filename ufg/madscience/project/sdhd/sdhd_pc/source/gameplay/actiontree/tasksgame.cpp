// File Line: 236
// RVA: 0x149EEB0
__int64 dynamic_initializer_for__uEffectPropertyUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("EffectProperty", 0xFFFFFFFF);
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
  ITrack *v2; // rbx
  UpdateStatAwardWithIntegerTask *v3; // rdi
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *v5; // rax

  v2 = this->m_Track;
  v3 = this;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  v5 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v4, (UFG::qSymbol *)&v2[1]);
  if ( v5 )
  {
    if ( v5->mCategory == LeaderboardCategory_StatAward )
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v5, HIDWORD(v3->m_Track[1].vfptr));
  }
}

// File Line: 272
// RVA: 0x2FA450
void __fastcall UpdateStatAwardWithFloatTask::Begin(UpdateStatAwardWithFloatTask *this, ActionContext *__formal)
{
  ITrack *v2; // rbx
  UpdateStatAwardWithFloatTask *v3; // rdi
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *v5; // rax

  v2 = this->m_Track;
  v3 = this;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  v5 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v4, (UFG::qSymbol *)&v2[1]);
  if ( v5 )
  {
    if ( v5->mCategory == LeaderboardCategory_StatAward )
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v5, *((float *)&v3->m_Track[1].vfptr + 1));
  }
}

// File Line: 281
// RVA: 0x2EE000
void __fastcall EndStatGameTask::Begin(EndStatGameTask *this, ActionContext *__formal)
{
  ITrack *v2; // rbx
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *v4; // rax

  v2 = this->m_Track;
  v3 = UFG::OSuiteLeaderboardManager::Instance();
  v4 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v3, (UFG::qSymbol *)&v2[1]);
  if ( v4 )
  {
    if ( v4->mCategory == 1 )
      UFG::StatGameManager::EndStatGame(v4);
  }
}

// File Line: 290
// RVA: 0x2FA550
void __fastcall UpdateStatGameWithIntegerTask::Begin(UpdateStatGameWithIntegerTask *this, ActionContext *__formal)
{
  ITrack *v2; // rbx
  UpdateStatGameWithIntegerTask *v3; // rdi
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *v5; // rax

  v2 = this->m_Track;
  v3 = this;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  v5 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v4, (UFG::qSymbol *)&v2[1]);
  if ( v5 )
  {
    if ( v5->mCategory == 1 )
      UFG::StatGameManager::UpdateScore(v5, HIDWORD(v3->m_Track[1].vfptr), LOBYTE(v3->m_Track[1].mResourceOwner) != 0);
  }
}

// File Line: 299
// RVA: 0x2FA4F0
void __fastcall UpdateStatGameWithFloatTask::Begin(UpdateStatGameWithFloatTask *this, ActionContext *__formal)
{
  ITrack *v2; // rbx
  UpdateStatGameWithFloatTask *v3; // rdi
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *v5; // rax

  v2 = this->m_Track;
  v3 = this;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  v5 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v4, (UFG::qSymbol *)&v2[1]);
  if ( v5 )
  {
    if ( v5->mCategory == 1 )
      UFG::StatGameManager::UpdateScore(
        v5,
        *((float *)&v3->m_Track[1].vfptr + 1),
        LOBYTE(v3->m_Track[1].mResourceOwner) != 0);
  }
}

// File Line: 308
// RVA: 0x2FA5A0
void __fastcall UpdateStatGameWithUpdateTimeTask::Begin(UpdateStatGameWithUpdateTimeTask *this, ActionContext *__formal)
{
  ITrack *v2; // rbx
  UpdateStatGameWithUpdateTimeTask *v3; // rdi
  UFG::OSuiteLeaderboardManager *v4; // rax
  UFG::OSuiteLeaderboardData *v5; // rax

  v2 = this->m_Track;
  v3 = this;
  v4 = UFG::OSuiteLeaderboardManager::Instance();
  v5 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v4, (UFG::qSymbol *)&v2[1]);
  v3->m_pLBD = v5;
  if ( v5 )
  {
    if ( v5->mCategory != 1 )
      v3->m_pLBD = 0i64;
  }
}

// File Line: 317
// RVA: 0x30B6E0
char __fastcall UpdateStatGameWithUpdateTimeTask::Update(UpdateStatGameWithUpdateTimeTask *this, float deltaTime)
{
  UFG::OSuiteLeaderboardData *v2; // rcx

  v2 = this->m_pLBD;
  if ( !v2 )
    return 0;
  UFG::StatGameManager::UpdateScore(v2, deltaTime, 1);
  return 1;
}

// File Line: 352
// RVA: 0x149EE30
__int64 dynamic_initializer_for__symBip01Neck__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Neck", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symBip01Neck, v0);
  return atexit(dynamic_atexit_destructor_for__symBip01Neck__);
}

// File Line: 354
// RVA: 0x1496B50
__int64 dynamic_initializer_for__AudioAttackMaterialProperty__()
{
  AudioAttackMaterialProperty.mUID = UFG::qWiseSymbolUIDFromString("AudioAttackMaterialProperty", 0x811C9DC5);
  _((AMD_HD3D *)AudioAttackMaterialProperty.mUID);
  return atexit(dynamic_atexit_destructor_for__AudioAttackMaterialProperty__);
}

// File Line: 368
// RVA: 0x2DF320
void __fastcall DoorStateTask::DoorStateTask(DoorStateTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DoorStateTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&DoorStateTask::`vftable';
}

// File Line: 377
// RVA: 0x2EDE80
void __fastcall DoorStateTask::Begin(DoorStateTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  UFG::SimObjectGame *v3; // rcx
  bool v4; // bl
  unsigned __int16 v5; // dx
  UFG::DoorComponent *v6; // rax

  v2 = this->m_Track;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = LOBYTE(v2[1].vfptr) != 0;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DoorComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DoorComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DoorComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType(
                                     (UFG::SimObject *)&v3->vfptr,
                                     UFG::DoorComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::DoorComponent::_TypeUID);
    }
    if ( v6 )
      UFG::DoorComponent::SetOpen(v6, v4);
  }
}

// File Line: 409
// RVA: 0x30D0F0
__int64 __fastcall findAttackMaterialUIDForAttacker(ActionContext *pContext, UFG::SimObject *pAttacker, const unsigned int uSourceAttackMaterialUID)
{
  UFG::SimObjectGame *v3; // rax
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  __int64 v9; // rdx
  char *v10; // rax
  unsigned int v11; // ebx
  UFG::qReflectHandleBase v13; // [rsp+28h] [rbp-30h]

  if ( uSourceAttackMaterialUID == gAttackMaterialNone.m_EnumSymbol.mUID )
    return 0i64;
  if ( uSourceAttackMaterialUID != gAttackMaterialWeaponEquipped.m_EnumSymbol.mUID )
    return uSourceAttackMaterialUID;
  if ( !pAttacker )
    return 0i64;
  v3 = (UFG::SimObjectGame *)UFG::getTarget(pAttacker, eTARGET_TYPE_EQUIPPED);
  if ( !v3 )
    return 0i64;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RigidBodyComponent::_TypeUID);
  }
  else
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
  }
  v6 = v5;
  if ( !v5 )
    return 0i64;
  UFG::qReflectHandleBase::qReflectHandleBase(&v13);
  v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
  v13.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
  v9 = *(_QWORD *)&v6[2].m_Flags;
  if ( v9 )
    UFG::qReflectHandleBase::operator=(&v13, (UFG::qReflectHandleBase *)(v9 + 224));
  v10 = UFG::qReflectObject::GetName(v13.mData);
  v11 = UFG::qStringHashUpper32(v10, 0xFFFFFFFF);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v13);
  return v11;
}

// File Line: 499
// RVA: 0x305950
char __fastcall MotionIntentionCOMTask::Update(MotionIntentionCOMTask *this, float timeDelta)
{
  MotionIntentionCOMTask *v2; // rbx
  Render::DebugDrawManager *v3; // rax
  UFG::SimObjectCVBase *v4; // rbx
  Render::DebugDrawContext *v5; // rsi
  UFG::CharacterAnimationComponent *v6; // rdi
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::CharacterAnimationComponent *v9; // rax
  unsigned __int16 v10; // cx
  float *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  unsigned __int16 v14; // cx
  UFG::AICharacterControllerBaseComponent *v15; // rax
  UFG::AICharacterControllerBaseComponent *v16; // rbx
  Creature *v17; // rcx
  float v18; // xmm6_4
  __m128 v19; // xmm7
  __m128 v20; // xmm1
  float v21; // xmm2_4
  UFG::qVector3 centre; // [rsp+40h] [rbp-39h]
  UFG::qVector3 p1; // [rsp+50h] [rbp-29h]
  UFG::qVector3 p0; // [rsp+5Ch] [rbp-1Dh]
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-9h]

  v2 = this;
  v3 = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v4 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
  v5 = (Render::DebugDrawContext *)v3;
  if ( v4 )
  {
    v8 = v4->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v4);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v4->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
    }
    v10 = v4->m_Flags;
    v6 = v9;
    if ( (v10 >> 14) & 1 )
    {
      v7 = v4->m_Components.p[42].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v4->vfptr, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v4->vfptr, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v4->vfptr, UFG::RagdollComponent::_TypeUID);
    }
  }
  else
  {
    v6 = 0i64;
    v7 = 0i64;
  }
  if ( !sMoveMotionIntention || !v6 || !v7 )
    return 1;
  v11 = (float *)v7[1].m_BoundComponentHandles.mNode.mPrev;
  v12 = v11[17];
  v13 = v11[18];
  centre.x = v11[16];
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
  if ( !v4 )
    return 1;
  v14 = v4->m_Flags;
  if ( (v14 >> 14) & 1 )
  {
    v15 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
  }
  else if ( (v14 & 0x8000u) == 0 )
  {
    if ( (v14 >> 13) & 1 )
      v15 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v4->vfptr,
                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
    else
      v15 = (UFG::AICharacterControllerBaseComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            (UFG::SimObjectGame *)&v4->vfptr,
                                                                            UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
  }
  else
  {
    v15 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
  }
  v16 = v15;
  if ( !v15 )
    return 1;
  v17 = v6->mCreature;
  if ( !v17 )
    return 1;
  Creature::GetTransform(v17, 0, &transform);
  v19 = (__m128)LODWORD(centre.y);
  v18 = centre.x - transform.v3.x;
  v19.m128_f32[0] = centre.y - transform.v3.y;
  if ( sDebugDrawCOM )
  {
    p1.x = v18 + transform.v3.x;
    p1.y = v19.m128_f32[0] + transform.v3.y;
    p1.z = transform.v3.z;
    p0 = *(UFG::qVector3 *)&transform.v3.x;
    Render::DebugDrawContext::DrawArrow(v5, &p0, &p1, &UFG::qColour::ForestGreen, &UFG::qMatrix44::msIdentity, 0i64);
  }
  v20 = v19;
  v20.m128_f32[0] = (float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v20)) > sIntentionLength )
  {
    if ( v20.m128_f32[0] == 0.0 )
      v21 = 0.0;
    else
      v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
    v16->m_Intention.mMotionIntentionDirection.z = v21 * 0.0;
    v16->m_Intention.mMotionIntentionDirection.x = v18 * v21;
    v16->m_Intention.mMotionIntentionDirection.y = v19.m128_f32[0] * v21;
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
  MinimumDistanceTask *v2; // rsi
  ActionContext *v3; // rcx
  UFG::SimObjectGame *v5; // rcx
  __int64 v6; // rbx
  UFG::TransformNodeComponent *v7; // rdi
  __int64 v8; // rbp
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rcx
  float *v17; // rax
  float v18; // xmm8_4
  __m128 v19; // xmm2
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
  UFG::qVector3 normalizeDistance; // [rsp+30h] [rbp-98h]

  v2 = this;
  v3 = this->mContext;
  if ( !v3 )
    return 0;
  v5 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  v6 = 0i64;
  v7 = 0i64;
  if ( v5 )
    v7 = v5->m_pTransformNodeComponent;
  v8 = LODWORD(v2->m_Track[1].vfptr);
  if ( v5 )
  {
    v9 = v5->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v10 = v5->m_Components.p[20].m_pComponent;
    }
    if ( v10 )
    {
      v11 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
      if ( v11 )
      {
        v13 = v11->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v12 = v11->m_Components.p[20].m_pComponent;
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v14 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v11,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v11->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
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
      v15 = ((__int64 (*)(void))v12->vfptr[15].__vecDelDtor)();
      if ( v15 )
      {
        v16 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v15 + 96) + v8 + 8) + *(_QWORD *)(v15 + 88) + 40);
        if ( v16 )
          v6 = *(_QWORD *)(v16 + 88);
      }
    }
  }
  if ( !v7 || !v6 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v7);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
  v17 = (float *)v2->m_Track;
  v18 = *(float *)(v6 + 176);
  v19 = (__m128)LODWORD(v7->mWorldTransform.v3.y);
  v20 = (__m128)*(unsigned int *)(v6 + 180);
  v21 = *(float *)(v6 + 184);
  v22 = v17[15];
  v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - v20.m128_f32[0])
                                  * (float)(v19.m128_f32[0] - v20.m128_f32[0]))
                          + (float)((float)(v7->mWorldTransform.v3.x - v18) * (float)(v7->mWorldTransform.v3.x - v18)))
                  + (float)((float)(v7->mWorldTransform.v3.z - v21) * (float)(v7->mWorldTransform.v3.z - v21));
  LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v19);
  if ( v23 < v22 )
  {
    v24 = v17[16];
    v25 = 0.0;
    v26 = v17[17];
    if ( v24 == 0.0 || (v27 = timeDelta / v24, (float)(timeDelta / v24) > 1.0) )
      v27 = *(float *)&FLOAT_1_0;
    v28 = v18 - v7->mWorldTransform.v3.x;
    v20.m128_f32[0] = v20.m128_f32[0] - v7->mWorldTransform.v3.y;
    v29 = v21 - v7->mWorldTransform.v3.z;
    v30 = v20;
    v30.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v28 * v28)) + (float)(v29 * v29);
    if ( v30.m128_f32[0] != 0.0 )
      v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
    v31 = v28 * v25;
    v32 = v20.m128_f32[0] * v25;
    distanceToAdjust = v22 - v23;
    normalizeDistance.x = v31;
    normalizeDistance.y = v32;
    v34 = v29 * v25;
    normalizeDistance.z = v34;
    MinimumDistanceTask::AdjustDistance(
      v2,
      (UFG::TransformNodeComponent *)v6,
      &normalizeDistance,
      v27 * v26,
      distanceToAdjust);
    normalizeDistance.x = v31 * -1.0;
    normalizeDistance.y = v32 * -1.0;
    normalizeDistance.z = v34 * -1.0;
    MinimumDistanceTask::AdjustDistance(v2, v7, &normalizeDistance, (float)(1.0 - v26) * v27, distanceToAdjust);
  }
  return 1;
}

// File Line: 629
// RVA: 0x2E7AE0
void __fastcall MinimumDistanceTask::AdjustDistance(MinimumDistanceTask *this, UFG::TransformNodeComponent *transformNodeComponent, UFG::qVector3 *normalizeDistance, float ratio, float distanceToAdjust)
{
  UFG::SimObjectGame *v5; // rcx
  UFG::qVector3 *v6; // rbx
  UFG::TransformNodeComponent *v7; // rdi
  unsigned __int16 v8; // r9
  UFG::SimComponent *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm6_4
  UFG::SimObjectCVBase *v23; // rcx
  unsigned __int16 v24; // dx
  UFG::CharacterAnimationComponent *v25; // rax
  Creature *v26; // rbx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-68h]

  v5 = (UFG::SimObjectGame *)transformNodeComponent->m_pSimObject;
  v6 = normalizeDistance;
  v7 = transformNodeComponent;
  if ( v5 )
  {
    v8 = v5->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = v5->m_Components.p[27].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterPhysicsComponent::_TypeUID);
      else
        v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v9 )
    {
      if ( ratio != 0.0 && distanceToAdjust != 0.0 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v7);
        v10 = v7->mWorldTransform.v0.y;
        m.v0.x = v7->mWorldTransform.v0.x;
        v11 = v7->mWorldTransform.v0.z;
        m.v0.y = v10;
        v12 = v7->mWorldTransform.v0.w;
        m.v0.z = v11;
        m.v1.x = v7->mWorldTransform.v1.x;
        v13 = v7->mWorldTransform.v1.z;
        m.v0.w = v12;
        v14 = v7->mWorldTransform.v1.y;
        m.v1.z = v13;
        v15 = v7->mWorldTransform.v2.x;
        m.v1.y = v14;
        v16 = v7->mWorldTransform.v1.w;
        m.v2.x = v15;
        v17 = v7->mWorldTransform.v2.z;
        m.v1.w = v16;
        v18 = v7->mWorldTransform.v2.y;
        m.v2.z = v17;
        m.v2.y = v18;
        v19 = ratio * v6->y;
        m.v2.w = v7->mWorldTransform.v2.w;
        v20 = ratio * v6->x;
        v21 = ratio * v6->z;
        m.v3.y = (float)(v19 * distanceToAdjust) + v7->mWorldTransform.v3.y;
        LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
        v22 = (float)(v21 * distanceToAdjust) + v7->mWorldTransform.v3.z;
        m.v3.x = (float)(v20 * distanceToAdjust) + v7->mWorldTransform.v3.x;
        m.v3.z = v22;
        UFG::TransformNodeComponent::SetWorldTransform(v7, &m);
        v23 = (UFG::SimObjectCVBase *)v7->m_pSimObject;
        if ( v23 )
        {
          v24 = v23->m_Flags;
          if ( (v24 >> 14) & 1 )
          {
            v25 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v23);
          }
          else if ( (v24 & 0x8000u) == 0 )
          {
            if ( (v24 >> 13) & 1 )
            {
              v25 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v23);
            }
            else if ( (v24 >> 12) & 1 )
            {
              v25 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v23->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
            else
            {
              v25 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v23->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
          }
          else
          {
            v25 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v23);
          }
          if ( v25 )
          {
            v26 = v25->mCreature;
            if ( v26 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v7);
              Creature::SetTransform(v26, &v7->mWorldTransform);
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
  AttackCollisionTask *v1; // rdx
  UFG::qNode<ITask,ITask> *v2; // rax
  PostAnimUpdateTask *v3; // rcx
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *v4; // rax
  UFG::SimObject **v5; // rax
  signed __int64 v6; // rcx

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AttackCollisionTrack>::`vftable';
  v3 = (PostAnimUpdateTask *)&this->vfptr;
  v4 = (UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (PostAnimUpdateTaskVtbl *)&PostAnimUpdateTask::`vftable';
  v1->vfptr = (ITaskVtbl *)&AttackCollisionTask::`vftable'{for `Task<AttackCollisionTrack>'};
  v3->vfptr = (PostAnimUpdateTaskVtbl *)&AttackCollisionTask::`vftable'{for `PostAnimUpdateTask'};
  v1->mAttackBoneIndex = -1;
  *(_DWORD *)&v1->mHitPhysical = 0;
  *(_WORD *)&v1->mBlockedLastFrame = 0;
  v1->mHitCount = 0;
  v5 = v1->mHitDudes;
  v6 = 4i64;
  do
  {
    *v5 = 0i64;
    v5[1] = 0i64;
    v5[2] = 0i64;
    v5 += 8;
    *(v5 - 5) = 0i64;
    *(v5 - 4) = 0i64;
    *(v5 - 3) = 0i64;
    *(v5 - 2) = 0i64;
    *(v5 - 1) = 0i64;
    --v6;
  }
  while ( v6 );
}

// File Line: 677
// RVA: 0x2E8C40
void __fastcall AttackCollisionTask::Begin(AttackCollisionTask *this, ActionContext *context)
{
  AttackCollisionTask *v2; // rbx
  UFG::CharacterAnimationComponent *v3; // rax
  Creature *v4; // rdi
  int v5; // eax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  UFG::GameStatTracker *v12; // rax
  float v13; // xmm0_4
  char v14; // al
  UFG::SimObjectGame *v15; // rcx
  unsigned __int16 v16; // dx
  UFG::ActionTreeComponent *v17; // rcx
  UFG::ActionTreeComponent *v18; // rax
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h]

  v2 = this;
  this->mContext = context;
  v3 = AttackCollisionTask::GetCharacterAnimationComponent(this);
  if ( v3 )
  {
    v4 = v3->mCreature;
    if ( !v4 )
      return;
    if ( v4->mPose.mRigHandle.mData )
      v5 = Skeleton::GetBoneID(v4->mPose.mRigHandle.mUFGSkeleton, v2->m_Track[2].mMasterRate.expression.mOffset);
    else
      v5 = -1;
    if ( v5 < 0 )
      v5 = 0;
    v2->mAttackBoneIndex = v5;
    Creature::GetTransform(v4, v5, &transform);
    v6 = transform.v3.x;
    v7 = transform.v3.y;
    v8 = transform.v3.z;
    v2->mAttackPosition0.x = transform.v3.x;
    v2->mAttackPosition0.y = v7;
    v2->mAttackPosition0.z = v8;
    v2->mAttackPosition1.x = v6;
    v2->mAttackPosition1.y = v7;
    v2->mAttackPosition1.z = v8;
  }
  if ( LOBYTE(v2->m_Track[3].mMasterRate.text.mOffset) )
  {
    v9 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
    if ( v9 )
    {
      v10 = v9->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v11 = v9->m_Components.p[15].m_pComponent;
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HitReactionComponent::_TypeUID);
        else
          v11 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::HitReactionComponent::_TypeUID);
      }
      else
      {
        v11 = v9->m_Components.p[15].m_pComponent;
      }
      if ( v11 )
      {
        *(_QWORD *)&v11[1].m_TypeUID = 0i64;
        if ( UFG::IsAnyLocalPlayer(v2->mContext->mSimObject.m_pPointer) )
        {
          v12 = UFG::GameStatTracker::Instance();
          v13 = UFG::GameStatTracker::GetStat(v12, Berserk_Activated);
          v14 = UFG::HitReactionComponent::msBerserkAttackValidFlag;
          if ( v13 > 0.0 )
            v14 = 1;
          UFG::HitReactionComponent::msBerserkAttackValidFlag = v14;
        }
      }
    }
  }
  v15 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
  if ( v15 )
  {
    v16 = v15->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v17 = (UFG::ActionTreeComponent *)v15->m_Components.p[7].m_pComponent;
    }
    else if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
      {
        v17 = (UFG::ActionTreeComponent *)v15->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v16 >> 12) & 1 )
          v18 = (UFG::ActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v15,
                                              UFG::ActionTreeComponent::_TypeUID);
        else
          v18 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v15->vfptr,
                                              UFG::ActionTreeComponent::_TypeUID);
        v17 = v18;
      }
    }
    else
    {
      v17 = (UFG::ActionTreeComponent *)v15->m_Components.p[7].m_pComponent;
    }
    if ( v17 )
      v17->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)v17, (unsigned int)&v2->vfptr);
  }
}

// File Line: 755
// RVA: 0x30E1C0
void __fastcall AttackCollisionTask::setupHitRecord(AttackCollisionTask *this, UFG::HitRecord *outHitRecord, UFG::TransformNodeComponent *pOpponentsTransformNodeC, UFG::eSimObjectTypeEnum eOpponentSimObjectType, const float fTime)
{
  UFG::TransformNodeComponent *v5; // rbx
  UFG::HitRecord *v6; // rbp
  AttackCollisionTask *v7; // rsi
  UFG::SimObject *v8; // rdi
  UFG::TransformNodeComponent *v9; // rdi
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  char v14; // r15
  signed int v15; // edi
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  __m128 v19; // xmm5
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
  int v34; // er14
  UFG::SimObjectGame *v35; // rbx
  UFG::SimComponent *v36; // rax
  unsigned __int16 v37; // cx
  Creature *v38; // rcx
  unsigned __int16 v39; // cx
  UFG::SimComponent *v40; // rax
  ExpressionParameterInt *v41; // rcx
  signed int v42; // ebx
  UFG::SimObjectGame *v43; // rcx
  unsigned __int16 v44; // dx
  UFG::SimComponent *v45; // rax
  UFG::SimObjectGame *v46; // rcx
  UFG::SimComponent *v47; // rcx
  unsigned __int16 v48; // dx
  UFG::SimComponent *v49; // rax
  __int64 v50; // rax
  UFG::SimObjectProp *v51; // rcx
  unsigned __int16 v52; // dx
  UFG::SimObjectWeaponPropertiesComponent *v53; // rax
  UFG::SimObject *v54; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v55; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v56; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v57; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v58; // rax
  ITrack *v59; // rdx
  unsigned int v60; // er14
  __int64 v61; // rax
  unsigned int v62; // ebx
  __int64 v63; // rcx
  unsigned int v64; // eax
  int v65; // edx
  UFG::qVector3 vHitPosition; // [rsp+38h] [rbp-140h]
  UFG::qVector3 outBoneOffset; // [rsp+48h] [rbp-130h]
  ActionPath result; // [rsp+58h] [rbp-120h]
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-108h]
  float v70; // [rsp+180h] [rbp+8h]

  v5 = pOpponentsTransformNodeC;
  v6 = outHitRecord;
  v7 = this;
  UFG::TransformNodeComponent::UpdateWorldTransform(pOpponentsTransformNodeC);
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v8 = v7->mContext->mSimObject.m_pPointer;
  if ( v8 )
    v9 = v8->m_pTransformNodeComponent;
  else
    v9 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v10 = v5->mWorldTransform.v0.y;
  v11 = v5->mWorldTransform.v0.x;
  v12 = v5->mWorldTransform.v3.y - v9->mWorldTransform.v3.y;
  v13 = v5->mWorldTransform.v3.x - v9->mWorldTransform.v3.x;
  v14 = 0;
  v15 = LODWORD(v7->m_Track[2].mTimeEnd);
  if ( (float)((float)(v11 * v11) + (float)(v10 * v10)) > 0.001
    && (float)((float)(v12 * v12) + (float)(v13 * v13)) > 0.001
    && (float)((float)((float)(v10 * v12) + (float)(v13 * v11)) + (float)(v5->mWorldTransform.v0.z * 0.0)) > 0.0 )
  {
    if ( v15 )
    {
      switch ( v15 )
      {
        case 1:
          v15 = 2;
          break;
        case 2:
          v15 = 1;
          break;
        case 3:
          v15 = 0;
          break;
      }
    }
    else
    {
      v15 = 3;
    }
    v14 = 1;
  }
  v16 = v7->mAttackPosition0.z;
  v17 = v7->mAttackPosition1.z - v16;
  v18 = v7->mAttackPosition0.y;
  v19 = (__m128)LODWORD(v7->mAttackPosition1.y);
  v19.m128_f32[0] = v19.m128_f32[0] - v18;
  v20 = v7->mAttackPosition0.x;
  v21 = v7->mAttackPosition1.x - v20;
  v22 = v19;
  v70 = (float)(v17 * fTime) + v16;
  v22.m128_f32[0] = (float)(v19.m128_f32[0] * fTime) + v18;
  v23 = (float)(v21 * fTime) + v20;
  vHitPosition.x = (float)(v21 * fTime) + v20;
  vHitPosition.y = (float)(v19.m128_f32[0] * fTime) + v18;
  vHitPosition.z = (float)(v17 * fTime) + v16;
  v24 = v19;
  v24.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v21 * v21)) + (float)(v17 * v17);
  if ( v24.m128_f32[0] == 0.0 )
    v25 = 0.0;
  else
    v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
  v26 = v25 * v17;
  v27 = v25 * v19.m128_f32[0];
  v28 = v21 * v25;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v29 = v22;
  v29.m128_f32[0] = v22.m128_f32[0] - v5->mWorldTransform.v3.y;
  v30 = v23 - v5->mWorldTransform.v3.x;
  v31 = v29;
  v31.m128_f32[0] = (float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v30 * v30);
  if ( v31.m128_f32[0] == 0.0 )
    v32 = 0.0;
  else
    v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
  v33 = v30 * v32;
  v34 = 0;
  fTime = 0.0;
  if ( (float)(signed int)ExpressionParameterInt::operator long((ExpressionParameterInt *)&v7->m_Track[1].mResourceOwner) > 0.0 )
  {
    AttackCollisionTask::projectHitPositionOntoSkeleton(v7, &vHitPosition, v5, (int *)&fTime, &outBoneOffset);
    v34 = LODWORD(fTime);
  }
  v35 = (UFG::SimObjectGame *)v5->m_pSimObject;
  if ( v35 )
  {
    v37 = v35->m_Flags;
    if ( (v37 >> 14) & 1 )
    {
      v36 = v35->m_Components.p[9].m_pComponent;
    }
    else if ( (v37 & 0x8000u) == 0 )
    {
      if ( (v37 >> 13) & 1 )
      {
        v36 = v35->m_Components.p[8].m_pComponent;
      }
      else if ( (v37 >> 12) & 1 )
      {
        v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        v36 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v35->vfptr, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v36 = v35->m_Components.p[9].m_pComponent;
    }
  }
  else
  {
    v36 = 0i64;
  }
  v38 = *(Creature **)&v36[2].m_TypeUID;
  if ( v38 )
    Creature::GetTransform(v38, v34, &transform);
  if ( v35
    && ((v39 = v35->m_Flags, !((v39 >> 14) & 1)) ? ((v39 & 0x8000u) == 0 ? (!((v39 >> 13) & 1) ? (!((v39 >> 12) & 1) ? (v40 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v35->vfptr, UFG::RigidBodyComponent::_TypeUID)) : (v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::RigidBodyComponent::_TypeUID))) : (v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::RigidBodyComponent::_TypeUID))) : (v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::RigidBodyComponent::_TypeUID))) : (v40 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::RigidBodyComponent::_TypeUID)),
        v40) )
  {
    v41 = (ExpressionParameterInt *)&v7->m_Track[1].mMasterRate.expression;
  }
  else
  {
    v41 = (ExpressionParameterInt *)&v7->m_Track[1].mResourceOwner;
  }
  v42 = ExpressionParameterInt::operator long(v41);
  v43 = (UFG::SimObjectGame *)v7->mContext->mSimObject.m_pPointer;
  if ( v43 )
  {
    v44 = v43->m_Flags;
    if ( (v44 >> 14) & 1 )
    {
      v45 = v43->m_Components.p[20].m_pComponent;
    }
    else if ( (v44 & 0x8000u) == 0 )
    {
      if ( (v44 >> 13) & 1 )
        v45 = UFG::SimObjectGame::GetComponentOfTypeHK(v43, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v45 = (v44 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v43,
                                  UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v43->vfptr,
                                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v45 = v43->m_Components.p[20].m_pComponent;
    }
    if ( v45 )
    {
      v46 = (UFG::SimObjectGame *)v7->mContext->mSimObject.m_pPointer;
      if ( v46 )
      {
        v48 = v46->m_Flags;
        if ( (v48 >> 14) & 1 )
        {
          v47 = v46->m_Components.p[20].m_pComponent;
        }
        else if ( (v48 & 0x8000u) == 0 )
        {
          if ( (v48 >> 13) & 1 )
            v49 = UFG::SimObjectGame::GetComponentOfTypeHK(v46, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v49 = (v48 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v46,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v46->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
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
      v50 = ((__int64 (*)(void))v47->vfptr[15].__vecDelDtor)();
      if ( v50 )
      {
        v51 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v50 + 96) + 25i64)
                                     + *(_QWORD *)(v50 + 88)
                                     + 40);
        if ( v51 )
        {
          v52 = v51->m_Flags;
          if ( (v52 >> 14) & 1 )
          {
            v53 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v51->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
          else if ( (v52 & 0x8000u) == 0 )
          {
            if ( (v52 >> 13) & 1 )
              v53 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v51);
            else
              v53 = (UFG::SimObjectWeaponPropertiesComponent *)((v52 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                    (UFG::SimObjectGame *)&v51->vfptr,
                                                                                    UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v51->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
          }
          else
          {
            v53 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v51->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
          if ( v53 )
            v42 = (signed int)(float)((float)v42 * v53->mWeaponTypeInfo->mFireModes[v53->mFireMode]->mDamageMultiplier);
        }
      }
    }
  }
  if ( UFG::IsAnyLocalPlayer(v7->mContext->mSimObject.m_pPointer) )
    v42 = (signed int)(float)((float)v42 * (float)(UFG::PlayerBuffTracker::GetMeleeDamageMultiplier() + 1.0));
  ActionController::GetPlayingFullPath(v7->mContext->mActionController, &result);
  v54 = v7->mContext->mSimObject.m_pPointer;
  v6->mAttackTypeID = LODWORD(v7->m_Track[2].mTimeBegin);
  v6->mDamage = v42;
  v55 = &v6->mAttacker;
  if ( v6->mAttacker.m_pPointer )
  {
    v56 = v55->mPrev;
    v57 = v6->mAttacker.mNext;
    v56->mNext = v57;
    v57->mPrev = v56;
    v55->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v55->mPrev;
    v6->mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mAttacker.mPrev;
  }
  v6->mAttacker.m_pPointer = v54;
  if ( v54 )
  {
    v58 = v54->m_SafePointerList.mNode.mPrev;
    v58->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v55->mPrev;
    v55->mPrev = v58;
    v6->mAttacker.mNext = &v54->m_SafePointerList.mNode;
    v54->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v55->mPrev;
  }
  *(_QWORD *)&v6->mTimeSinceHit = 0i64;
  v6->mEffectBone = v34;
  v6->mEffectOffset.x = outBoneOffset.x;
  v6->mEffectOffset.y = outBoneOffset.y;
  v6->mEffectOffset.z = outBoneOffset.z;
  v59 = v7->m_Track;
  v60 = *((_DWORD *)&v59[2].mMasterRate.value + 1);
  if ( (signed int)audioEnum.m_enumLists.size <= 0 )
    v61 = 0i64;
  else
    v61 = *((_QWORD *)audioEnum.m_enumLists.p + 4);
  v62 = *(_DWORD *)(*(_QWORD *)(v61 + 48) + 4i64 * *(unsigned int *)&v59[3].mBreakPoint);
  if ( (signed int)gAttackCollisionEnum.m_enumLists.size <= 0 )
    v63 = 0i64;
  else
    v63 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 5);
  v64 = UFG::qStringHash32(*(const char **)(*(_QWORD *)(v63 + 16) + 8i64 * v59[3].m_TrackClassNameUID), 0xFFFFFFFF);
  v65 = (int)v7->m_Track[3].vfptr;
  v6->mMeleeInfo.mAttackLocationLateralID = v15;
  v6->mMeleeInfo.mAttackLocationHorizontalID = v65;
  v6->mMeleeInfo.mAttackFromBehind = v14;
  v6->mMeleeInfo.mAttackMaterialUID = v64;
  v6->mMeleeInfo.mAudioIntensityUID = v62;
  v6->mMeleeInfo.mAttackIntensityUID = v60;
  v6->mMeleeInfo.mHitPosition.x = v23;
  LODWORD(v6->mMeleeInfo.mHitPosition.y) = v22.m128_i32[0];
  v6->mMeleeInfo.mHitPosition.z = v70;
  v6->mMeleeInfo.mHitDirection.x = v28;
  v6->mMeleeInfo.mHitDirection.y = v27;
  v6->mMeleeInfo.mHitDirection.z = v26;
  v6->mMeleeInfo.mHitNormal.x = v33;
  v6->mMeleeInfo.mHitNormal.y = v32 * v29.m128_f32[0];
  v6->mMeleeInfo.mHitNormal.z = v32 * 0.0;
  BinArray<ActionID,0>::Clone(&result.mPath, &v6->mMeleeInfo.mActionPath.mPath);
  if ( result.mPath.mCount >= 0 && result.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&result.mPath.mData + result.mPath.mData.mOffset) )
      operator delete[]((char *)&result.mPath.mData + result.mPath.mData.mOffset);
  }
}

// File Line: 893
// RVA: 0x30DDB0
char __fastcall AttackCollisionTask::projectHitPositionOntoSkeleton(AttackCollisionTask *this, UFG::qVector3 *vHitPosition, UFG::TransformNodeComponent *pOpponentsTransformNodeC, int *outBoneID, UFG::qVector3 *outBoneOffset)
{
  UFG::SimObjectCVBase *v5; // rbx
  int *v6; // r12
  UFG::qVector3 *v7; // r14
  UFG::SimComponent *v8; // rsi
  UFG::CharacterAnimationComponent *v9; // r15
  unsigned __int16 v10; // cx
  bool v11; // zf
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // rax
  unsigned __int16 v14; // cx
  UFG::CharacterAnimationComponent *v15; // rax
  Creature *v16; // rsi
  float v18; // xmm6_4
  const unsigned int *v19; // rbx
  int v20; // eax
  int v21; // edi
  float v22; // xmm2_4
  __int128 v23; // xmm4
  float v24; // xmm5_4
  float v25; // xmm6_4
  __m128 v26; // xmm2
  float v27; // xmm0_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  UFG::qVector4 hitPositionWS; // [rsp+30h] [rbp-81h]
  UFG::qVector4 invHitNormal; // [rsp+40h] [rbp-71h]
  UFG::qMatrix44 d; // [rsp+50h] [rbp-61h]
  UFG::qMatrix44 transform; // [rsp+90h] [rbp-21h]

  v5 = (UFG::SimObjectCVBase *)pOpponentsTransformNodeC->m_pSimObject;
  v6 = outBoneID;
  v7 = vHitPosition;
  if ( v5 )
  {
    v10 = v5->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v8 = v5->m_Components.p[9].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v8 = v5->m_Components.p[8].m_pComponent;
      }
      else
      {
        v11 = ((v10 >> 12) & 1) == 0;
        v12 = (UFG::SimObjectGame *)pOpponentsTransformNodeC->m_pSimObject;
        if ( v11 )
          v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::BaseAnimationComponent::_TypeUID);
        else
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::BaseAnimationComponent::_TypeUID);
        v8 = v13;
      }
    }
    else
    {
      v8 = v5->m_Components.p[9].m_pComponent;
    }
    v14 = v5->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v5->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v15 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v5->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v15 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
    }
    v9 = v15;
  }
  else
  {
    v8 = 0i64;
    v9 = 0i64;
  }
  v16 = *(Creature **)&v8[2].m_TypeUID;
  if ( !v16 )
    return 0;
  v18 = FLOAT_3_4028235e38;
  *v6 = 0;
  v19 = BoneUIDs;
  do
  {
    if ( v16->mPose.mRigHandle.mData )
    {
      v20 = Skeleton::GetBoneID(v16->mPose.mRigHandle.mUFGSkeleton, *v19);
      v21 = v20;
      if ( v20 >= 0 )
      {
        Creature::GetTransform(v16, v20, &transform);
        if ( (float)((float)((float)((float)(transform.v3.y - v7->y) * (float)(transform.v3.y - v7->y))
                           + (float)((float)(transform.v3.x - v7->x) * (float)(transform.v3.x - v7->x)))
                   + (float)((float)(transform.v3.z - v7->z) * (float)(transform.v3.z - v7->z))) < v18 )
        {
          v18 = (float)((float)((float)(transform.v3.y - v7->y) * (float)(transform.v3.y - v7->y))
                      + (float)((float)(transform.v3.x - v7->x) * (float)(transform.v3.x - v7->x)))
              + (float)((float)(transform.v3.z - v7->z) * (float)(transform.v3.z - v7->z));
          *v6 = v21;
        }
      }
    }
    ++v19;
  }
  while ( (signed __int64)v19 < (signed __int64)&fDesiredDist );
  Creature::GetTransform(v16, *v6, &transform);
  UFG::qInverse(&d, &transform);
  v22 = v7->y;
  v23 = LODWORD(v7->x);
  v24 = (float)((float)(v7->x * d.v0.x) + (float)(v7->y * d.v1.x)) + (float)(v7->z * d.v2.x);
  v25 = (float)((float)(v7->x * d.v0.z) + (float)(v22 * d.v1.z)) + (float)(v7->z * d.v2.z);
  *(float *)&v23 = (float)((float)(*(float *)&v23 * d.v0.y) + (float)(v22 * d.v1.y)) + (float)(v7->z * d.v2.y);
  v26 = (__m128)v23;
  v26.m128_f32[0] = (float)((float)(*(float *)&v23 * *(float *)&v23) + (float)(v24 * v24)) + (float)(v25 * v25);
  LODWORD(v27) = (unsigned __int128)_mm_sqrt_ps(v26);
  v28 = v24 * (float)(fDesiredDist / v27);
  *(float *)&v23 = *(float *)&v23 * (float)(fDesiredDist / v27);
  outBoneOffset->z = v25 * (float)(fDesiredDist / v27);
  outBoneOffset->x = v28;
  LODWORD(outBoneOffset->y) = v23;
  if ( v9 )
  {
    v29 = v7->x;
    v30 = v7->z;
    hitPositionWS.w = 1.0;
    v31 = v7->y;
    invHitNormal.x = transform.v3.x - v29;
    invHitNormal.y = transform.v3.y - v31;
    hitPositionWS.x = v29;
    invHitNormal.z = transform.v3.z - v30;
    hitPositionWS.y = v31;
    hitPositionWS.z = v30;
    invHitNormal.w = 0.0;
    UFG::CharacterAnimationComponent::ApplyBluntForceDamage(v9, v16, &hitPositionWS, &invHitNormal, 1.0);
  }
  return 1;
}

// File Line: 965
// RVA: 0x30D5D0
char __fastcall AttackCollisionTask::handleHit(AttackCollisionTask *this, UFG::HitReactionComponent *opponentHitComp, bool foundBlocker, float blockDist2)
{
  float v4; // xmm7_4
  UFG::HitReactionComponent *v5; // r13
  AttackCollisionTask *v6; // rdi
  UFG::SimObjectGame *v7; // rbx
  int v8; // er9
  signed __int64 v9; // rcx
  UFG::SimObject **v10; // rax
  UFG::CharacterPhysicsComponent *v11; // rsi
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax
  UFG::TransformNodeComponent *v14; // r14
  int v15; // xmm2_4
  int v16; // xmm3_4
  char v17; // si
  UFG::eSimObjectTypeEnum v18; // er15
  unsigned __int16 v19; // cx
  UFG::SimComponent *v20; // rax
  UFG::GameStatTracker *v21; // rax
  int v22; // eax
  UFG::eStimulusType v23; // edx
  ITrack *v24; // rcx
  UFG::eStimulusType v25; // edx
  UFG::SimObject *v26; // r9
  UFG::StimulusParameters stimulus_parameters; // [rsp+40h] [rbp-88h]
  float v29; // [rsp+58h] [rbp-70h]
  int v30; // [rsp+5Ch] [rbp-6Ch]
  float v31; // [rsp+60h] [rbp-68h]
  float v32; // [rsp+68h] [rbp-60h]
  int v33; // [rsp+6Ch] [rbp-5Ch]
  int v34; // [rsp+70h] [rbp-58h]
  __int64 v35; // [rsp+78h] [rbp-50h]
  float fTime; // [rsp+1D8h] [rbp+110h]
  char v37; // [rsp+1E8h] [rbp+120h]

  v35 = -2i64;
  v4 = blockDist2;
  v5 = opponentHitComp;
  v6 = this;
  v7 = (UFG::SimObjectGame *)opponentHitComp->m_pSimObject;
  v8 = 32;
  if ( this->mHitCount < 32 )
    v8 = this->mHitCount;
  v9 = 0i64;
  if ( v8 > 0 )
  {
    v10 = v6->mHitDudes;
    while ( v7 != (UFG::SimObjectGame *)*v10 )
    {
      ++v9;
      ++v10;
      if ( v9 >= v8 )
        goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  if ( v7 )
  {
    v12 = v7->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v11 = (UFG::CharacterPhysicsComponent *)v7->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v12 >> 12) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v13 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v7->vfptr,
                  UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v11 = (UFG::CharacterPhysicsComponent *)v13;
    }
  }
  else
  {
    v11 = 0i64;
  }
  v14 = v7->m_pTransformNodeComponent;
  if ( !v11 )
    return 0;
  if ( !v14 )
    return 0;
  UFG::CharacterPhysicsComponent::GetRadius(v11);
  UFG::TransformNodeComponent::UpdateWorldTransform(v14);
  v15 = LODWORD(v14->mWorldTransform.v3.y);
  v16 = SLODWORD(v14->mWorldTransform.v3.z);
  v32 = v14->mWorldTransform.v3.x;
  v33 = v15;
  v34 = v16;
  v29 = v32;
  v30 = v15;
  v31 = *(float *)&v16;
  v31 = *(float *)&v16 + UFG::CharacterPhysicsComponent::GetHeight(v11, v11->mCollisionModelType);
  v17 = UFG::SweptSphereCapsuleQuery(
          *((float *)&v6->m_Track[2].mMasterRate.expression.mOffset + 1),
          &v6->mAttackPosition0,
          &v6->mAttackPosition1,
          (UFG::qVector3 *)&v32);
  if ( v37 )
  {
    if ( (float)((float)((float)((float)((float)(v6->mAttackPosition1.y - v6->mAttackPosition0.y) * fTime)
                               * (float)((float)(v6->mAttackPosition1.y - v6->mAttackPosition0.y) * fTime))
                       + (float)((float)((float)(v6->mAttackPosition1.x - v6->mAttackPosition0.x) * fTime)
                               * (float)((float)(v6->mAttackPosition1.x - v6->mAttackPosition0.x) * fTime)))
               + (float)((float)((float)(v6->mAttackPosition1.z - v6->mAttackPosition0.z) * fTime)
                       * (float)((float)(v6->mAttackPosition1.z - v6->mAttackPosition0.z) * fTime))) > v4 )
      return 0;
  }
  if ( v17 )
  {
    v6->mHitDudes[v6->mHitCount++ % 32] = (UFG::SimObject *)&v7->vfptr;
    v18 = 0;
    v19 = v7->m_Flags;
    if ( (v19 >> 14) & 1 )
    {
      v20 = v7->m_Components.p[3].m_pComponent;
    }
    else if ( (v19 & 0x8000u) == 0 )
    {
      if ( (v19 >> 13) & 1 )
      {
        v20 = v7->m_Components.p[4].m_pComponent;
      }
      else if ( (v19 >> 12) & 1 )
      {
        v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
      else
      {
        v20 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v7->vfptr,
                UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v20 = v7->m_Components.p[3].m_pComponent;
    }
    if ( v20 )
      v18 = (UFG::eSimObjectTypeEnum)v20[1].m_SafePointerList.mNode.mNext;
    UFG::HitRecord::HitRecord((UFG::HitRecord *)&stimulus_parameters.m_StimulusProducerOffset.z);
    AttackCollisionTask::setupHitRecord(
      v6,
      (UFG::HitRecord *)&stimulus_parameters.m_StimulusProducerOffset.z,
      v14,
      v18,
      fTime);
    UFG::HitReactionComponent::HandleHitReaction(v5, (UFG::HitRecord *)&stimulus_parameters.m_StimulusProducerOffset.z);
    if ( LOBYTE(v6->m_Track[3].mMasterRate.text.mOffset) )
    {
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 0;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_MELEE_ATTACK,
        &stimulus_parameters,
        v6->mContext->mSimObject.m_pPointer,
        (UFG::SimObject *)&v7->vfptr);
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_MELEE_ATTACK_NEAR_YOU,
        &stimulus_parameters,
        v6->mContext->mSimObject.m_pPointer,
        0);
      v21 = UFG::FactionInterface::Get();
      v22 = UFG::FactionInterface::GetFaction(&v21->mFactionInterface, (UFG::SimObject *)&v7->vfptr);
      v23 = 10;
      if ( v22 != 17 )
        v23 = 9;
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        v23,
        &stimulus_parameters,
        v6->mContext->mSimObject.m_pPointer,
        0);
    }
    v24 = v6->m_Track;
    if ( LODWORD(v24[2].mMasterRate.value) )
    {
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 0;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      v25 = LODWORD(v24[2].mMasterRate.value);
      v26 = v6->mContext->mSimObject.m_pPointer;
      if ( BYTE5(v24[3].mMasterRate.text.mOffset) )
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          v25,
          &stimulus_parameters,
          v26,
          (UFG::SimObject *)&v7->vfptr);
      else
        UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, v25, &stimulus_parameters, v26, 0);
    }
    UFG::HitRecord::~HitRecord((UFG::HitRecord *)&stimulus_parameters.m_StimulusProducerOffset.z);
  }
  return v17;
}

// File Line: 1104
// RVA: 0x30DA50
char __fastcall AttackCollisionTask::handleIncomingAttack(AttackCollisionTask *this, UFG::eAttackPhaseEnum eAttackPhase, UFG::SimObject *pClosePedSimObject)
{
  UFG::SimObjectGame *v3; // rbx
  UFG::eAttackPhaseEnum v4; // er15
  AttackCollisionTask *v5; // r14
  UFG::SimObject *v6; // rsi
  UFG::TransformNodeComponent *v7; // rsi
  UFG::TransformNodeComponent *v8; // rdi
  unsigned __int16 v9; // cx
  UFG::HitReactionComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  ITrack *v12; // rcx
  int v13; // er9
  int v14; // er10
  UFG::SimObject *v15; // rdx
  int v16; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::IncomingAttackInfo incomingAttackInfo; // [rsp+28h] [rbp-38h]

  v3 = (UFG::SimObjectGame *)pClosePedSimObject;
  v4 = eAttackPhase;
  v5 = this;
  if ( !(_S16 & 1) )
  {
    _S16 |= 1u;
    s_fMaxHorizontalDistanceSquared = FLOAT_9_0;
  }
  v6 = this->mContext->mSimObject.m_pPointer;
  if ( v6 )
    v7 = v6->m_pTransformNodeComponent;
  else
    v7 = 0i64;
  v8 = 0i64;
  if ( pClosePedSimObject )
    v8 = pClosePedSimObject->m_pTransformNodeComponent;
  if ( !v7 )
    return 0;
  if ( !v8 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  UFG::TransformNodeComponent::UpdateWorldTransform(v7);
  if ( (float)((float)((float)((float)(v8->mWorldTransform.v3.x - v7->mWorldTransform.v3.x)
                             * (float)(v8->mWorldTransform.v3.x - v7->mWorldTransform.v3.x))
                     + (float)((float)(v8->mWorldTransform.v3.y - v7->mWorldTransform.v3.y)
                             * (float)(v8->mWorldTransform.v3.y - v7->mWorldTransform.v3.y)))
             + (float)((float)(v8->mWorldTransform.v3.z - v7->mWorldTransform.v3.z)
                     * (float)(v8->mWorldTransform.v3.z - v7->mWorldTransform.v3.z))) >= s_fMaxHorizontalDistanceSquared
    || !v3 )
  {
    return 0;
  }
  v9 = v3->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::HitReactionComponent *)v3->m_Components.p[15].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
    else
      v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
    v10 = (UFG::HitReactionComponent *)v11;
  }
  else
  {
    v10 = (UFG::HitReactionComponent *)v3->m_Components.p[15].m_pComponent;
  }
  if ( !v10 )
    return 0;
  *(_QWORD *)&incomingAttackInfo.mAttackPhaseEnum = 0i64;
  incomingAttackInfo.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&incomingAttackInfo.mAttacker.mPrev;
  incomingAttackInfo.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&incomingAttackInfo.mAttacker.mPrev;
  incomingAttackInfo.mAttacker.m_pPointer = 0i64;
  *(_QWORD *)&incomingAttackInfo.mAttackLocationLateralID = 0i64;
  incomingAttackInfo.mTimeSinceUpdated = 1000;
  v12 = v5->m_Track;
  v13 = (int)v12[3].vfptr;
  v14 = LODWORD(v12[2].mTimeEnd);
  v15 = v5->mContext->mSimObject.m_pPointer;
  v16 = LODWORD(v12[2].mTimeBegin);
  incomingAttackInfo.mAttackPhaseEnum = v4;
  incomingAttackInfo.mAttackTypeID = v16;
  incomingAttackInfo.mAttacker.m_pPointer = v15;
  if ( v15 )
  {
    v19 = v15->m_SafePointerList.mNode.mPrev;
    v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&incomingAttackInfo.mAttacker.mPrev;
    incomingAttackInfo.mAttacker.mPrev = v19;
    incomingAttackInfo.mAttacker.mNext = &v15->m_SafePointerList.mNode;
    v15->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&incomingAttackInfo.mAttacker.mPrev;
  }
  incomingAttackInfo.mAttackLocationLateralID = v14;
  incomingAttackInfo.mAttackLocationHorizontalID = v13;
  incomingAttackInfo.mTimeSinceUpdated = 0;
  UFG::HitReactionComponent::HandleIncomingAttack(v10, &incomingAttackInfo);
  if ( incomingAttackInfo.mAttacker.m_pPointer )
  {
    v20 = incomingAttackInfo.mAttacker.mPrev;
    v21 = incomingAttackInfo.mAttacker.mNext;
    incomingAttackInfo.mAttacker.mPrev->mNext = incomingAttackInfo.mAttacker.mNext;
    v21->mPrev = v20;
    incomingAttackInfo.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&incomingAttackInfo.mAttacker.mPrev;
    incomingAttackInfo.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&incomingAttackInfo.mAttacker.mPrev;
  }
  incomingAttackInfo.mAttacker.m_pPointer = 0i64;
  v22 = incomingAttackInfo.mAttacker.mPrev;
  v23 = incomingAttackInfo.mAttacker.mNext;
  incomingAttackInfo.mAttacker.mPrev->mNext = incomingAttackInfo.mAttacker.mNext;
  v23->mPrev = v22;
  incomingAttackInfo.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&incomingAttackInfo.mAttacker.mPrev;
  incomingAttackInfo.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&incomingAttackInfo.mAttacker.mPrev;
  return 1;
}

// File Line: 1138
// RVA: 0x30BB20
void __fastcall AttackCollisionTask::applyAttackDamage(AttackCollisionTask *this, UFG::ShapeCasterCollector *caster, UFG::qVector3 *startPosition, UFG::qVector3 *dir)
{
  UFG::qVector3 *v4; // rdi
  UFG::ShapeCasterCollector *v5; // rbx
  AttackCollisionTask *v6; // r13
  Render::DebugDrawContext *v7; // r15
  __int64 v8; // rax
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v13; // rcx
  const char *v14; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v15; // r14
  float v16; // xmm10_4
  bool v17; // bl
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  char v21; // si
  unsigned __int64 v22; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v23; // rcx
  const char *v24; // rax
  unsigned __int64 v25; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v26; // rcx
  const char *v27; // rax
  ITrack *v28; // rbx
  __int64 v29; // rax
  signed __int64 v30; // rcx
  signed int v31; // eax
  float v32; // xmm6_4
  UFG::SimObjectGame *v33; // rcx
  unsigned __int16 v34; // dx
  UFG::SimComponent *v35; // rax
  UFG::SimObjectGame *v36; // rcx
  UFG::SimComponent *v37; // rcx
  unsigned __int16 v38; // dx
  UFG::SimComponent *v39; // rax
  __int64 v40; // rax
  UFG::SimObjectProp *v41; // rcx
  unsigned __int16 v42; // dx
  UFG::SimObjectWeaponPropertiesComponent *v43; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v44; // rdi
  UFG::SimComponent *v45; // rdi
  UFG::SimObjectCharacter *v46; // rax
  UFG::SimObjectCharacter *v47; // rdx
  bool v48; // zf
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v49; // rcx
  const char *v50; // rax
  unsigned __int64 v51; // rbx
  const char *v52; // rax
  unsigned __int64 v53; // rax
  UFG::StateMachineComponent *v54; // rcx
  UFG::SimObjectGame *v55; // rcx
  UFG::VehicleEffectsComponent *v56; // rdi
  unsigned __int16 v57; // dx
  UFG::SimComponent *v58; // rax
  float v59; // xmm1_4
  float v60; // xmm2_4
  UFG::CopSystem *v61; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v62; // r8
  unsigned __int16 v63; // cx
  UFG::HitReactionComponent *v64; // rbx
  UFG::SimComponent *v65; // rax
  UFG::SimObjectGame *v66; // rcx
  UFG::SimObject *v67; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v68; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v69; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v70; // rax
  UFG::SimObjectGame *v71; // rcx
  unsigned __int16 v72; // dx
  UFG::SimComponent *v73; // rax
  hkSimpleLocalFrame *v74; // rbx
  UFG::SimObject *v75; // rbx
  UFG::GameStatTracker *v76; // rax
  int v77; // eax
  UFG::eStimulusType v78; // edx
  __int64 v79; // rcx
  unsigned int v80; // eax
  unsigned int v81; // er12
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v82; // rcx
  const char *v83; // rax
  unsigned int v84; // esi
  unsigned int v85; // er15
  unsigned __int64 v86; // r8
  UFG::qReflectObject *v87; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v88; // rcx
  const char *v89; // rax
  unsigned __int64 v90; // r8
  float v91; // ebx
  UFG::SimObjectCharacter *v92; // rcx
  unsigned __int16 v93; // dx
  UFG::ActorAudioComponent *v94; // rax
  UFG::ActorAudioComponent *v95; // rdi
  unsigned int v96; // er14
  float v97; // xmm2_4
  float v98; // xmm1_4
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v99; // [rsp+48h] [rbp-80h]
  UFG::StimulusParameters stimulus_parameters; // [rsp+50h] [rbp-78h]
  float v101; // [rsp+68h] [rbp-60h]
  UFG::qVector3 centre; // [rsp+70h] [rbp-58h]
  UFG::qReflectHandleBase v103; // [rsp+80h] [rbp-48h]
  UFG::qReflectHandleBase v104; // [rsp+A8h] [rbp-20h]
  UFG::qReflectHandleBase v105; // [rsp+D0h] [rbp+8h]
  UFG::qReflectHandleBase v106; // [rsp+F8h] [rbp+30h]
  UFG::qReflectHandleBase v107; // [rsp+120h] [rbp+58h]
  UFG::qReflectHandleBase v108; // [rsp+148h] [rbp+80h]
  UFG::qReflectHandleBase v109; // [rsp+170h] [rbp+A8h]
  __int64 v110; // [rsp+198h] [rbp+D0h]
  UFG::qReflectHandleBase v111; // [rsp+1A0h] [rbp+D8h]
  UFG::HitRecord hitrecord; // [rsp+1C8h] [rbp+100h]
  char v113; // [rsp+3A0h] [rbp+2D8h]
  UFG::qVector3 *v114; // [rsp+3A8h] [rbp+2E0h]
  char v115; // [rsp+3B8h] [rbp+2F0h]
  float vars0; // [rsp+3C0h] [rbp+2F8h]
  void *retaddr; // [rsp+3C8h] [rbp+300h]

  v110 = -2i64;
  v4 = startPosition;
  v5 = caster;
  v6 = this;
  v7 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  *(_QWORD *)&centre.x = v7;
  if ( gAttackCollisionDebug )
  {
    v8 = ((__int64 (*)(void))v5->mPhantom->vfptr[2].__first_virtual_table_function__)();
    v9 = *(float *)(v8 + 52);
    v10 = *(float *)(v8 + 56);
    centre.x = *(float *)(v8 + 48);
    centre.y = v9;
    centre.z = v10;
    Render::DebugDrawContext::DrawSphere(
      v7,
      &centre,
      v5->mRadius,
      &UFG::qColour::Red,
      &UFG::qMatrix44::msIdentity,
      0i64);
  }
  UFG::qReflectHandleBase::qReflectHandleBase(&v103);
  v12 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v11);
  v103.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::qReflectHandleBase(&v107);
  v14 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v13);
  v107.mTypeUID = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
  v15 = v5->mHitList.mNode.mNext;
  v99 = v15;
  *(_QWORD *)&centre.x = (char *)v5 + 8;
  if ( v15 != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)&v5->mHitList )
  {
    v16 = vars0;
    do
    {
      v17 = 0;
      if ( v115 )
      {
        v18 = (float)((float)(*(float *)&retaddr * *((float *)&v15[2].mPrev + 1)) + *(float *)&v15[1].mNext) - v4->z;
        v19 = (float)((float)(*(float *)&retaddr * *(float *)&v15[2].mPrev) + *((float *)&v15[1].mPrev + 1)) - v4->y;
        v20 = (float)((float)(*(float *)&retaddr * *((float *)&v15[1].mNext + 1)) + *(float *)&v15[1].mPrev) - v4->x;
        v17 = (float)((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v18 * v18)) > v16;
      }
      v21 = 0;
      if ( BYTE4(v6->m_Track[3].mMasterRate.text.mOffset) )
      {
        v17 = 1;
        v22 = (unsigned __int64)v15[5].mNext;
        if ( v22 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v108);
          v24 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v23);
          v108.mTypeUID = UFG::qStringHash64(v24, 0xFFFFFFFFFFFFFFFFui64);
          UFG::qReflectHandleBase::Init(&v108, v108.mTypeUID, v22);
          if ( v108.mData )
          {
            v17 = 1;
            if ( LOBYTE(v108.mData[2].vfptr) )
              v17 = 0;
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v108);
        }
        v25 = (unsigned __int64)v15[6].mPrev;
        if ( !v17 )
        {
LABEL_20:
          v28 = v6->m_Track;
          v29 = *(_QWORD *)&v28[1].mMasterRate.value;
          if ( v29
            && (v30 = (signed __int64)&v28[1].mMasterRate.value + v29) != 0
            && ((*(void (__fastcall **)(signed __int64, UFG::StimulusParameters *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v30 + 24i64))(
                  v30,
                  &stimulus_parameters,
                  UEL::gCurrentParameters,
                  0i64,
                  UEL::gCurrentStringBuilder),
                LOWORD(stimulus_parameters.m_EmitUntilSpeedLessThan)) )
          {
            if ( LOWORD(stimulus_parameters.m_EmitUntilSpeedLessThan) == 1 )
              v31 = LODWORD(stimulus_parameters.m_StimulusProducerOffset.x);
            else
              v31 = (signed int)stimulus_parameters.m_StimulusProducerOffset.x;
          }
          else
          {
            v31 = LODWORD(v28[1].mTimeBegin);
          }
          v32 = (float)v31 * 0.0099999998;
          v33 = (UFG::SimObjectGame *)v6->mContext->mSimObject.m_pPointer;
          if ( v33 )
          {
            v34 = v33->m_Flags;
            if ( (v34 >> 14) & 1 )
            {
              v35 = v33->m_Components.p[20].m_pComponent;
            }
            else if ( (v34 & 0x8000u) == 0 )
            {
              if ( (v34 >> 13) & 1 )
                v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::TargetingSystemBaseComponent::_TypeUID);
              else
                v35 = (v34 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v33,
                                          UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                           (UFG::SimObject *)&v33->vfptr,
                                                                                           UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else
            {
              v35 = v33->m_Components.p[20].m_pComponent;
            }
            if ( v35 )
            {
              v36 = (UFG::SimObjectGame *)v6->mContext->mSimObject.m_pPointer;
              if ( v36 )
              {
                v38 = v36->m_Flags;
                if ( (v38 >> 14) & 1 )
                {
                  v37 = v36->m_Components.p[20].m_pComponent;
                }
                else if ( (v38 & 0x8000u) == 0 )
                {
                  if ( (v38 >> 13) & 1 )
                    v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::TargetingSystemBaseComponent::_TypeUID);
                  else
                    v39 = (v38 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v36,
                                              UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v36->vfptr,
                                                                                               UFG::TargetingSystemBaseComponent::_TypeUID);
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
              v40 = ((__int64 (*)(void))v37->vfptr[15].__vecDelDtor)();
              if ( v40 )
              {
                v41 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v40 + 96) + 25i64)
                                             + *(_QWORD *)(v40 + 88)
                                             + 40);
                if ( v41 )
                {
                  v42 = v41->m_Flags;
                  if ( (v42 >> 14) & 1 )
                  {
                    v43 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v41->vfptr,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                  }
                  else if ( (v42 & 0x8000u) == 0 )
                  {
                    if ( (v42 >> 13) & 1 )
                      v43 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v41);
                    else
                      v43 = (UFG::SimObjectWeaponPropertiesComponent *)((v42 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                            (UFG::SimObjectGame *)&v41->vfptr,
                                                                                            UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v41->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
                  }
                  else
                  {
                    v43 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v41->vfptr,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                  }
                  if ( v43 )
                    v32 = v32 * v43->mWeaponTypeInfo->mFireModes[v43->mFireMode]->mDamageMultiplier;
                }
              }
            }
          }
          v113 = 0;
          v44 = v15[2].mNext[1].mNext;
          if ( !v21 )
          {
            if ( v44 )
            {
              v45 = (UFG::SimComponent *)v44[1].mNext;
              if ( v45 )
              {
                v46 = UFG::GetLocalPlayer();
                v47 = (UFG::SimObjectCharacter *)v45->m_pSimObject;
                if ( v46 == v47
                  || (v48 = v46 == (UFG::SimObjectCharacter *)v6->mContext->mSimObject.m_pPointer, v113 = 0, v48) )
                {
                  v113 = 1;
                }
                if ( v47 == (UFG::SimObjectCharacter *)v6->mContext->mSimObject.m_pPointer )
                  goto LABEL_174;
                if ( UFG::SimComponent::IsType(v45, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID) )
                {
                  UFG::qReflectHandleBase::qReflectHandleBase(&v106);
                  v50 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v49);
                  v106.mTypeUID = UFG::qStringHash64(v50, 0xFFFFFFFFFFFFFFFFui64);
                  UFG::qReflectHandleBase::Init(&v106, v106.mTypeUID, (unsigned __int64)v15[5].mNext);
                  if ( v106.mData )
                  {
                    v51 = UFG::StateMachineDefinition::GetDnaUid(HIDWORD(v106.mData[4].mBaseNode.mParent));
                    UFG::qReflectHandleBase::qReflectHandleBase(&v111);
                    v52 = UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::GetStaticTypeName();
                    v53 = UFG::qStringHash64(v52, 0xFFFFFFFFFFFFFFFFui64);
                    UFG::qReflectHandleBase::Init(&v111, v53, v51);
                    if ( v111.mData )
                    {
                      if ( *((float *)&v111.mData[1].mBaseNode.mChildren[1] + 1) > 0.0 )
                      {
                        v54 = (UFG::StateMachineComponent *)v45[6].vfptr;
                        if ( v54 )
                          UFG::StateMachineComponent::ApplyDamage(
                            v54,
                            v32,
                            ATTACK_DAMAGE,
                            v6->mContext->mSimObject.m_pPointer);
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
              v7,
              (UFG::qVector3 *)&v15[1],
              0.0099999998,
              &UFG::qColour::Red,
              &UFG::qMatrix44::msIdentity,
              0i64);
          v55 = (UFG::SimObjectGame *)v15[5].mPrev;
          if ( !v55 )
          {
            v56 = 0i64;
            goto LABEL_92;
          }
          v57 = v55->m_Flags;
          if ( (v57 >> 14) & 1 )
          {
            v58 = UFG::SimObjectGame::GetComponentOfTypeHK(v55, UFG::VehicleEffectsComponent::_TypeUID);
            goto LABEL_91;
          }
          if ( (v57 & 0x8000u) == 0 )
          {
            if ( (v57 >> 13) & 1 )
            {
              v58 = UFG::SimObjectGame::GetComponentOfTypeHK(v55, UFG::VehicleEffectsComponent::_TypeUID);
            }
            else if ( (v57 >> 12) & 1 )
            {
              v58 = UFG::SimObjectGame::GetComponentOfTypeHK(v55, UFG::VehicleEffectsComponent::_TypeUID);
            }
            else
            {
              v58 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v55->vfptr,
                      UFG::VehicleEffectsComponent::_TypeUID);
            }
LABEL_91:
            v56 = (UFG::VehicleEffectsComponent *)v58;
          }
          else
          {
            v56 = (UFG::VehicleEffectsComponent *)v55->m_Components.p[32].m_pComponent;
          }
LABEL_92:
          if ( !v21 )
          {
            if ( v56 )
            {
              stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
              stimulus_parameters.m_MaxStimulusDuration = -1.0;
              stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
              stimulus_parameters.m_StimulusEmissionType = 0;
              UFG::StimulusManager::BeginStimulus(
                UFG::StimulusManager::s_pInstance,
                eSTIMULUS_VEHICLE_DAMAGED_BY_MELEE,
                &stimulus_parameters,
                (UFG::SimObject *)v15[5].mPrev);
              v59 = *((float *)&v15[1].mPrev + 1);
              v60 = *(float *)&v15[1].mNext;
              stimulus_parameters.m_StimulusProducerOffset.x = *(float *)&v15[1].mPrev;
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
                v6->mContext->mSimObject.m_pPointer,
                v15[5].mPrev);
              v62 = v15[5].mPrev;
              if ( v62 )
              {
                v63 = WORD2(v62[4].mNext);
                if ( (v63 >> 14) & 1 )
                {
                  v64 = (UFG::HitReactionComponent *)v62[6].mNext[15].mPrev;
                }
                else if ( (v63 & 0x8000u) == 0 )
                {
                  if ( (v63 >> 13) & 1 )
                  {
                    v65 = UFG::SimObjectGame::GetComponentOfTypeHK(
                            (UFG::SimObjectGame *)v15[5].mPrev,
                            UFG::HitReactionComponent::_TypeUID);
                  }
                  else
                  {
                    v48 = ((v63 >> 12) & 1) == 0;
                    v66 = (UFG::SimObjectGame *)v15[5].mPrev;
                    v65 = v48 ? UFG::SimObject::GetComponentOfType(
                                  (UFG::SimObject *)&v66->vfptr,
                                  UFG::HitReactionComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v66,
                                                                           UFG::HitReactionComponent::_TypeUID);
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
                  v67 = v6->mContext->mSimObject.m_pPointer;
                  if ( hitrecord.mAttacker.m_pPointer )
                  {
                    v68 = hitrecord.mAttacker.mPrev;
                    v69 = hitrecord.mAttacker.mNext;
                    hitrecord.mAttacker.mPrev->mNext = hitrecord.mAttacker.mNext;
                    v69->mPrev = v68;
                    hitrecord.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                    hitrecord.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                  }
                  hitrecord.mAttacker.m_pPointer = v67;
                  if ( v67 )
                  {
                    v70 = v67->m_SafePointerList.mNode.mPrev;
                    v70->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                    hitrecord.mAttacker.mPrev = v70;
                    hitrecord.mAttacker.mNext = &v67->m_SafePointerList.mNode;
                    v67->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&hitrecord.mAttacker.mPrev;
                  }
                  UFG::HitReactionComponent::SetHitRecord(v64, &hitrecord);
                  UFG::HitRecord::~HitRecord(&hitrecord);
                }
              }
            }
          }
          if ( LOBYTE(v6->m_Track[3].mMasterRate.text.mOffset) )
          {
            v71 = (UFG::SimObjectGame *)v15[5].mPrev;
            if ( v71 )
            {
              v72 = v71->m_Flags;
              if ( (v72 >> 14) & 1 )
              {
                v73 = UFG::SimObjectGame::GetComponentOfTypeHK(v71, UFG::VehicleOccupantComponent::_TypeUID);
                goto LABEL_122;
              }
              if ( (v72 & 0x8000u) == 0 )
              {
                if ( (v72 >> 13) & 1 )
                {
                  v73 = UFG::SimObjectGame::GetComponentOfTypeHK(v71, UFG::VehicleOccupantComponent::_TypeUID);
                }
                else if ( (v72 >> 12) & 1 )
                {
                  v73 = UFG::SimObjectGame::GetComponentOfTypeHK(v71, UFG::VehicleOccupantComponent::_TypeUID);
                }
                else
                {
                  v73 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v71->vfptr,
                          UFG::VehicleOccupantComponent::_TypeUID);
                }
LABEL_122:
                v74 = (hkSimpleLocalFrame *)v73;
              }
              else
              {
                v74 = (hkSimpleLocalFrame *)v71->m_Components.p[30].m_pComponent;
              }
              if ( v74 )
              {
                stimulus_parameters.m_MaxStimulusDuration = -1.0;
                stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
                stimulus_parameters.m_StimulusEmissionType = 0;
                stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
                UFG::StimulusManager::BeginStimulus(
                  UFG::StimulusManager::s_pInstance,
                  eSTIMULUS_MELEE_ATTACK_NEAR_YOU,
                  &stimulus_parameters,
                  v6->mContext->mSimObject.m_pPointer,
                  0);
                v75 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v74);
                if ( v75 )
                {
                  v76 = UFG::FactionInterface::Get();
                  v77 = UFG::FactionInterface::GetFaction(&v76->mFactionInterface, v75);
                  v78 = 10;
                  if ( v77 != 17 )
                    v78 = 9;
                  UFG::StimulusManager::BeginStimulus(
                    UFG::StimulusManager::s_pInstance,
                    v78,
                    &stimulus_parameters,
                    v6->mContext->mSimObject.m_pPointer,
                    0);
                }
              }
            }
          }
          if ( (signed int)gAttackCollisionEnum.m_enumLists.size <= 0 )
            v79 = 0i64;
          else
            v79 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 5);
          v80 = UFG::qStringHash32(
                  *(const char **)(*(_QWORD *)(v79 + 16) + 8i64 * v6->m_Track[3].m_TrackClassNameUID),
                  0xFFFFFFFF);
          v81 = findAttackMaterialUIDForAttacker(v6->mContext, v6->mContext->mSimObject.m_pPointer, v80);
          if ( !v81 )
            goto LABEL_174;
          UFG::qReflectHandleBase::qReflectHandleBase(&v104);
          v83 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v82);
          v104.mTypeUID = UFG::qStringHash64(v83, 0xFFFFFFFFFFFFFFFFui64);
          UFG::PhysicsPropertyManager::GetObjectProperties(
            (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v104,
            v81,
            1);
          if ( !v104.mData )
            goto LABEL_173;
          v84 = -1;
          v85 = -1;
          v86 = (unsigned __int64)v15[6].mPrev;
          if ( !v86 )
            goto LABEL_178;
          v87 = v103.mData;
          if ( v103.mData || (UFG::qReflectHandleBase::Init(&v103, v103.mTypeUID, v86), (v87 = v103.mData) != 0i64) )
          {
            v84 = (unsigned int)v87[1].mBaseNode.mChildren[0];
            v85 = HIDWORD(v87[1].mBaseNode.mChildren[0]);
          }
          if ( !(_S17_0 & 1) )
          {
            _S17_0 |= 1u;
            glassUid = UFG::qStringHashUpper32("Glass_Vehicle", 0xFFFFFFFF);
          }
          UFG::qReflectHandleBase::qReflectHandleBase(&v105);
          v89 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v88);
          v105.mTypeUID = UFG::qStringHash64(v89, 0xFFFFFFFFFFFFFFFFui64);
          UFG::qReflectHandleBase::Init(&v105, v105.mTypeUID, (unsigned __int64)v15[6].mPrev);
          if ( v56 && v105.mData && HIDWORD(v105.mData[4].mBaseNode.mParent) == glassUid )
          {
            if ( !UFG::VehicleEffectsComponent::IsGlassBroken(v56, (UFG::qVector3 *)&v15[1]) )
            {
              UFG::VehicleEffectsComponent::BreakGlass(v56, (UFG::qVector3 *)&v15[1]);
              goto LABEL_146;
            }
            if ( !BYTE4(v6->m_Track[3].mMasterRate.text.mOffset) )
              goto LABEL_146;
            UFG::qReflectHandleBase::~qReflectHandleBase(&v105);
LABEL_173:
            UFG::qReflectHandleBase::~qReflectHandleBase(&v104);
            goto LABEL_174;
          }
LABEL_146:
          UFG::qReflectHandleBase::~qReflectHandleBase(&v105);
          if ( v84 == -1 || v85 == -1 )
          {
LABEL_178:
            v90 = (unsigned __int64)v15[5].mNext;
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
                               (UFG::qWiseSymbol *)&AudioAttackMaterialProperty.mUID)->mUID;
            centre.z = v91;
            _((AMD_HD3D *)LODWORD(v91));
            if ( v91 != 0.0 )
            {
              v92 = (UFG::SimObjectCharacter *)v6->mContext->mSimObject.m_pPointer;
              if ( v92 )
              {
                v93 = v92->m_Flags;
                if ( (v93 >> 14) & 1 )
                {
                  v94 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v92);
                }
                else if ( (v93 & 0x8000u) == 0 )
                {
                  if ( (v93 >> 13) & 1 )
                    v94 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v92->vfptr,
                                                        UFG::ActorAudioComponent::_TypeUID);
                  else
                    v94 = (UFG::ActorAudioComponent *)((v93 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v92->vfptr,
                                                                           UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v92->vfptr, UFG::ActorAudioComponent::_TypeUID));
                }
                else
                {
                  v94 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v92->vfptr,
                                                      UFG::ActorAudioComponent::_TypeUID);
                }
                v95 = v94;
                if ( v94 )
                {
                  v96 = AttackCollisionTrack::GetAudioIntensityUID((AttackCollisionTrack *)v6->m_Track);
                  UFG::ActorAudioComponent::PlayFightImpact(v95, LODWORD(v91), v84, v96);
                  if ( v113 )
                    UFG::ActorAudioComponent::PlayFightRumble(v95, LODWORD(v91), v84, v96);
                  v15 = v99;
                }
              }
            }
            _((AMD_HD3D *)LODWORD(v91));
          }
          if ( v85 != -1 )
          {
            v97 = v6->mAttackPosition0.z - v6->mAttackPosition1.z;
            v98 = v6->mAttackPosition0.y - v6->mAttackPosition1.y;
            stimulus_parameters.m_MaxStimulusDuration = v6->mAttackPosition0.x - v6->mAttackPosition1.x;
            stimulus_parameters.m_EmitUntilSpeedLessThan = v98;
            v101 = v97;
            Render::ImpactManager::HandleImpactEvent(
              &Render::gImpactManager,
              v81,
              v85,
              (UFG::qVector3 *)&v15[1],
              (UFG::qVector3 *)&stimulus_parameters.m_MaxStimulusDuration,
              (UFG::qVector3 *)((char *)&v15[1].mNext + 4),
              0i64,
              0,
              0i64);
          }
          goto LABEL_173;
        }
        if ( v25 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v109);
          v27 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v26);
          v109.mTypeUID = UFG::qStringHash64(v27, 0xFFFFFFFFFFFFFFFFui64);
          UFG::qReflectHandleBase::Init(&v109, v109.mTypeUID, v25);
          if ( v103.mData && BYTE2(v103.mData[1].mBaseNode.mParent) )
          {
            v21 = 1;
            v17 = 0;
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v109);
        }
      }
      if ( !v17 )
        goto LABEL_20;
LABEL_174:
      v15 = v15->mNext;
      v99 = v15;
      v7 = *(Render::DebugDrawContext **)&centre.x;
      v4 = v114;
    }
    while ( v15 != *(UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> **)&centre.x );
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v107);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v103);
}andleBase(&v107);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v103);
}

// File Line: 1428
// RVA: 0x30C890
void __fastcall AttackCollisionTask::applyWeaponDamage(AttackCollisionTask *this)
{
  AttackCollisionTask *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rax
  __int64 v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::StateMachineComponent *v10; // rsi
  UFG::SimObject *v11; // rbx
  float v12; // xmm0_4

  v1 = this;
  if ( !this->mIsWeaponDamageApplied )
  {
    this->mIsWeaponDamageApplied = 1;
    if ( ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&this->m_Track[2]) > 0.0 )
    {
      v2 = (UFG::SimObjectGame *)v1->mContext->mSimObject.m_pPointer;
      if ( v2 )
      {
        v3 = v2->m_Flags;
        if ( (v3 >> 14) & 1 )
        {
          v4 = v2->m_Components.p[20].m_pComponent;
        }
        else if ( (v3 & 0x8000u) == 0 )
        {
          if ( (v3 >> 13) & 1 )
          {
            v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v3 >> 12) & 1 )
          {
            v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v5 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v2->vfptr,
                   UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v4 = v5;
        }
        else
        {
          v4 = v2->m_Components.p[20].m_pComponent;
        }
        if ( v4 )
        {
          v6 = ((__int64 (*)(void))v4->vfptr[15].__vecDelDtor)();
          if ( v6 )
          {
            v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v6 + 96) + 25i64)
                                        + *(_QWORD *)(v6 + 88)
                                        + 40);
            if ( v7 )
            {
              v8 = v7->m_Flags;
              if ( (v8 >> 14) & 1 )
              {
                v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
              }
              else if ( (v8 & 0x8000u) == 0 )
              {
                if ( (v8 >> 13) & 1 )
                {
                  v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
                }
                else if ( (v8 >> 12) & 1 )
                {
                  v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
                }
                else
                {
                  v9 = UFG::SimObject::GetComponentOfType(
                         (UFG::SimObject *)&v7->vfptr,
                         UFG::RigidBodyComponent::_TypeUID);
                }
              }
              else
              {
                v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
              }
              if ( v9 )
              {
                v10 = (UFG::StateMachineComponent *)v9[6].vfptr;
                if ( v10 )
                {
                  v11 = v1->mContext->mSimObject.m_pPointer;
                  v12 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&v1->m_Track[2]);
                  UFG::StateMachineComponent::ApplyDamage(v10, v12, ABSOLUTE_DAMAGE, v11);
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
  AttackCollisionTask *v2; // rbx
  __int64 v3; // rdx
  float v4; // xmm6_4
  float v5; // xmm0_4
  bool v6; // r15
  bool v7; // r12
  __int64 v8; // r13
  UFG::SimObjectGame *v9; // rcx
  char *v10; // rdi
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rcx
  UFG::SimComponent *v13; // rax
  __int64 v14; // r14
  char v15; // si
  __int64 v16; // r15
  UFG::TransformNodeComponent *v17; // r15
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  UFG::eAttackPhaseEnum v21; // er12
  UFG::CharacterAnimationComponent *v22; // rax
  float *v23; // rsi
  UFG::SimObject **v24; // r15
  unsigned int v25; // xmm1_4
  unsigned int v26; // xmm2_4
  int v27; // edx
  float v28; // xmm9_4
  float v29; // xmm10_4
  float v30; // xmm11_4
  __int64 v31; // rax
  float v32; // xmm6_4
  float v33; // xmm0_4
  __m128 v34; // xmm1
  float v35; // xmm8_4
  UFG::allocator::free_link *v36; // rax
  UFG::ShapeCasterCollector *v37; // rax
  UFG::ShapeCasterCollector *v38; // r12
  __int64 v39; // rcx
  UFG::TransformNodeComponent *v40; // r15
  UFG::allocator::free_link *v41; // rax
  UFG::ShapeCasterCollector *v42; // rax
  bool v43; // al
  signed int v44; // ecx
  _BYTE *v45; // rax
  bool v46; // zf
  __int64 v47; // rax
  UFG::SimObjectGame *v48; // rcx
  unsigned __int16 v49; // dx
  UFG::HitReactionComponent *v50; // rax
  AttackCollisionTask *v51; // r14
  char v52; // si
  signed __int64 v53; // rcx
  __int64 v54; // rax
  __int64 v55; // rax
  unsigned int v56; // er13
  unsigned int v57; // er15
  UFG::SimObjectGame **v58; // rsi
  char v59; // di
  UFG::SimObjectGame *v60; // rcx
  unsigned __int16 v61; // dx
  UFG::HitReactionComponent *v62; // rax
  _QWORD *v63; // rax
  __int64 v64; // rax
  ActionNode *v65; // rdx
  UFG::SimObjectCVBase *v66; // rcx
  unsigned __int16 v67; // dx
  UFG::TargetingSystemPedBaseComponent *v68; // rax
  unsigned int v69; // er14
  UFG::SimObject **v70; // rsi
  UFG::CharacterAnimationComponent *v71; // rax
  int v72; // xmm2_4
  int v73; // xmm1_4
  float v74; // xmm0_4
  UFG::SimObjectGame *v75; // rcx
  unsigned __int16 v76; // dx
  UFG::SimComponent *v77; // rax
  UFG::qVector3 rayStart; // [rsp+40h] [rbp-88h]
  UFG::qVector3 rayEnd; // [rsp+50h] [rbp-78h]
  __int64 v81; // [rsp+60h] [rbp-68h]
  int v82; // [rsp+68h] [rbp-60h]
  int v83; // [rsp+6Ch] [rbp-5Ch]
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-58h]
  int v85; // [rsp+B8h] [rbp-10h]
  int v86; // [rsp+BCh] [rbp-Ch]
  int v87; // [rsp+C8h] [rbp+0h]
  int v88; // [rsp+E8h] [rbp+20h]
  __int64 v89; // [rsp+F8h] [rbp+30h]
  const char *v90; // [rsp+108h] [rbp+40h]
  int v91; // [rsp+110h] [rbp+48h]
  char v92; // [rsp+1F8h] [rbp+130h]
  int v93; // [rsp+208h] [rbp+140h]
  __int64 v94; // [rsp+210h] [rbp+148h]

  v81 = -2i64;
  v2 = this;
  v92 = 0;
  v3 = *(_QWORD *)&this[-1].mAttackPosition0.z;
  v4 = *(float *)(v3 + 136);
  v5 = *(float *)(v3 + 140);
  v6 = v4 >= 0.0 && v4 <= *(float *)(this->m_Track->mMasterRate.expression.mOffset + 32);
  v7 = v5 >= 0.0 && v5 <= *(float *)(this->m_Track->mMasterRate.expression.mOffset + 32);
  v8 = *(unsigned int *)(v3 + 172);
  v9 = *(UFG::SimObjectGame **)&this->m_Track->m_TrackClassNameUID;
  v10 = 0i64;
  if ( v9
    && ((v11 = v9->m_Flags, !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                           v12 = v13) : (v12 = v9->m_Components.p[20].m_pComponent)) : (v12 = v9->m_Components.p[20].m_pComponent),
        v12) )
  {
    v14 = ((__int64 (*)(void))v12->vfptr[15].__vecDelDtor)();
  }
  else
  {
    v14 = 0i64;
  }
  v15 = 0;
  if ( v6 )
  {
    v16 = *(_QWORD *)&v2->m_Track->m_TrackClassNameUID;
    if ( v16 )
    {
      v17 = *(UFG::TransformNodeComponent **)(v16 + 88);
      if ( v17 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v17);
        v18 = v17->mWorldTransform.v3.y;
        rayStart.x = v17->mWorldTransform.v3.x;
        rayStart.y = v18;
        v19 = *((float *)&v2->mHitDudes[28] + 1);
        v20 = *(float *)&v2->mHitDudes[29];
        rayEnd.x = *(float *)&v2->mHitDudes[28];
        rayEnd.y = v19;
        rayEnd.z = v20;
        rayStart.z = v20;
        LOBYTE(transform.v2.z) = 0;
        transform.v2.w = 0.0;
        *(_QWORD *)&transform.v3.x = 0i64;
        v85 = (signed int)FLOAT_1_0;
        v86 = -1;
        v88 = 0;
        v87 = -1;
        v89 = 0i64;
        v90 = "AttackCollisionTask";
        v91 = -1;
        UFG::RayCastData::Init((UFG::RayCastData *)&transform.v0.z, &rayStart, &rayEnd, 0x10u);
        v15 = 0;
        if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, (UFG::RayCastData *)&transform.v0.z) )
          v15 = 1;
      }
    }
    if ( !v7 && !v15 )
    {
      v21 = 2;
      v22 = AttackCollisionTask::GetCharacterAnimationComponent((AttackCollisionTask *)((char *)v2 - 40));
      if ( !v22 )
        goto LABEL_124;
      v23 = (float *)((char *)&v2->mHitDudes[29] + 4);
      v24 = &v2->mHitDudes[28];
      v25 = (unsigned int)v2->mHitDudes[30];
      v26 = HIDWORD(v2->mHitDudes[30]);
      *(_DWORD *)v24 = HIDWORD(v2->mHitDudes[29]);
      *((_DWORD *)v24 + 1) = v25;
      *((_DWORD *)v24 + 2) = v26;
      v27 = LODWORD(v2->m_TimeBegin);
      if ( v27 != -1 )
      {
        Creature::GetTransform(v22->mCreature, v27, &transform);
        *(_DWORD *)v23 = v82;
        LODWORD(v2->mHitDudes[30]) = v83;
        HIDWORD(v2->mHitDudes[30]) = LODWORD(transform.v0.x);
      }
      v28 = 0.0;
      v29 = 0.0;
      v30 = 0.0;
      LOBYTE(v93) = 0;
      v31 = *(_QWORD *)&v2[-1].mAttackPosition0.z;
      v32 = *(float *)(v31 + 148);
      v33 = *((float *)&v2->mHitDudes[28] + 1) - *(float *)&v2->mHitDudes[30];
      v34 = (__m128)*(unsigned int *)v24;
      v34.m128_f32[0] = (float)((float)((float)(v34.m128_f32[0] - *v23) * (float)(v34.m128_f32[0] - *v23))
                              + (float)(v33 * v33))
                      + (float)((float)(*(float *)&v2->mHitDudes[29] - *((float *)&v2->mHitDudes[30] + 1))
                              * (float)(*(float *)&v2->mHitDudes[29] - *((float *)&v2->mHitDudes[30] + 1)));
      if ( notMovingHackDist <= COERCE_FLOAT(_mm_sqrt_ps(v34)) )
      {
        v41 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
        v94 = (__int64)v41;
        if ( v41 )
        {
          UFG::ShapeCasterCollector::ShapeCasterCollector((UFG::ShapeCasterCollector *)v41, v32, 0x10u, 0);
          v38 = v42;
        }
        else
        {
          v38 = 0i64;
        }
        v43 = UFG::BasePhysicsSystem::CastShape(
                UFG::BasePhysicsSystem::mInstance,
                v38,
                (UFG::qVector3 *)&v2->mHitDudes[28],
                (UFG::qVector3 *)((char *)&v2->mHitDudes[29] + 4));
        v44 = (unsigned __int8)v93;
        if ( v43 )
          v44 = 1;
        v93 = v44;
      }
      else
      {
        v35 = *(float *)(v31 + 148) * 0.5;
        v36 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
        v94 = (__int64)v36;
        if ( v36 )
        {
          UFG::ShapeCasterCollector::ShapeCasterCollector((UFG::ShapeCasterCollector *)v36, v35, 0x10u, 0);
          v38 = v37;
        }
        else
        {
          v38 = 0i64;
        }
        v39 = *(_QWORD *)&v2->m_Track->m_TrackClassNameUID;
        v40 = 0i64;
        if ( v39 )
          v40 = *(UFG::TransformNodeComponent **)(v39 + 88);
        UFG::TransformNodeComponent::UpdateWorldTransform(v40);
        v28 = v32 * v40->mWorldTransform.v0.x;
        v29 = v32 * v40->mWorldTransform.v0.y;
        v30 = v32 * v40->mWorldTransform.v0.z;
        rayStart.x = (float)(v32 * v40->mWorldTransform.v0.x) + *v23;
        rayStart.y = v29 + *(float *)&v2->mHitDudes[30];
        rayStart.z = v30 + *((float *)&v2->mHitDudes[30] + 1);
        rayEnd.x = *(float *)&v2->mHitDudes[28] - v28;
        rayEnd.y = *((float *)&v2->mHitDudes[28] + 1) - v29;
        rayEnd.z = *(float *)&v2->mHitDudes[29] - v30;
        if ( UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, v38, &rayEnd, &rayStart) )
          LOBYTE(v93) = 1;
      }
      v45 = *(_BYTE **)&v2[-1].mAttackPosition0.z;
      if ( !v45[196] && v14 && (!BYTE2(v2->m_TimeEnd) || !v45[195]) )
      {
        v46 = v45[193] == 0;
        v47 = *(_QWORD *)(v14 + 96);
        if ( v46 )
        {
          v53 = 56i64 * *(unsigned __int8 *)(v47 + 31);
          v54 = *(_QWORD *)(v14 + 88);
          if ( *(_QWORD *)(v53 + v54 + 40) && *(_BYTE *)(v53 + v54 + 49) )
            v55 = *(_QWORD *)(v53 + v54 + 40);
          else
            v55 = 0i64;
          v94 = v55;
          v56 = *(_DWORD *)(v14 + 584);
          v57 = 0;
          if ( v56 )
          {
            v58 = (UFG::SimObjectGame **)(v14 + 608);
            v59 = 0;
            v51 = (AttackCollisionTask *)((char *)v2 - 40);
            while ( 1 )
            {
              v60 = *v58;
              if ( *v58 != (UFG::SimObjectGame *)v55 && v60 )
              {
                v61 = v60->m_Flags;
                if ( (v61 >> 14) & 1 )
                {
                  v62 = (UFG::HitReactionComponent *)v60->m_Components.p[15].m_pComponent;
                }
                else if ( (v61 & 0x8000u) == 0 )
                {
                  if ( (v61 >> 13) & 1 )
                  {
                    v62 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v60,
                                                         UFG::HitReactionComponent::_TypeUID);
                  }
                  else if ( (v61 >> 12) & 1 )
                  {
                    v62 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v60,
                                                         UFG::HitReactionComponent::_TypeUID);
                  }
                  else
                  {
                    v62 = (UFG::HitReactionComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v60->vfptr,
                                                         UFG::HitReactionComponent::_TypeUID);
                  }
                }
                else
                {
                  v62 = (UFG::HitReactionComponent *)v60->m_Components.p[15].m_pComponent;
                }
                if ( v62 )
                {
                  v59 |= AttackCollisionTask::handleHit((AttackCollisionTask *)((char *)v2 - 40), v62, 0, 100000000.0);
                  v92 = v59;
                  if ( v59 )
                  {
                    if ( *(_BYTE *)(*(_QWORD *)&v2[-1].mAttackPosition0.z + 195i64) )
                    {
LABEL_86:
                      v10 = 0i64;
                      v52 = v92;
                      goto LABEL_89;
                    }
                  }
                }
                v55 = v94;
              }
              ++v57;
              v58 += 3;
              if ( v57 >= v56 )
                goto LABEL_86;
            }
          }
        }
        else
        {
          v48 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v47 + v8 + 8) + *(_QWORD *)(v14 + 88) + 40);
          if ( v48 )
          {
            v49 = v48->m_Flags;
            if ( (v49 >> 14) & 1 )
            {
              v50 = (UFG::HitReactionComponent *)v48->m_Components.p[15].m_pComponent;
            }
            else if ( (v49 & 0x8000u) == 0 )
            {
              if ( (v49 >> 13) & 1 )
              {
                v50 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v48,
                                                     UFG::HitReactionComponent::_TypeUID);
              }
              else if ( (v49 >> 12) & 1 )
              {
                v50 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v48,
                                                     UFG::HitReactionComponent::_TypeUID);
              }
              else
              {
                v50 = (UFG::HitReactionComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v48->vfptr,
                                                     UFG::HitReactionComponent::_TypeUID);
              }
            }
            else
            {
              v50 = (UFG::HitReactionComponent *)v48->m_Components.p[15].m_pComponent;
            }
            v51 = (AttackCollisionTask *)((char *)v2 - 40);
            if ( v50 )
            {
              v52 = AttackCollisionTask::handleHit((AttackCollisionTask *)((char *)v2 - 40), v50, 0, 100000000.0);
              goto LABEL_89;
            }
            goto LABEL_88;
          }
        }
      }
      v51 = (AttackCollisionTask *)((char *)v2 - 40);
LABEL_88:
      v52 = 0;
LABEL_89:
      if ( *(_BYTE *)(*(_QWORD *)&v2[-1].mAttackPosition0.z + 194i64) )
      {
        if ( LOBYTE(v2->m_TimeEnd) )
          goto LABEL_94;
        LOBYTE(v2->m_TimeEnd) = v93;
        rayStart.x = *(float *)&v2->mHitDudes[28] - v28;
        rayStart.y = *((float *)&v2->mHitDudes[28] + 1) - v29;
        rayStart.z = *(float *)&v2->mHitDudes[29] - v30;
        AttackCollisionTask::applyAttackDamage(v51, v38, &rayStart, &rayEnd);
      }
      if ( !LOBYTE(v2->m_TimeEnd) && !v52 )
      {
LABEL_101:
        if ( v38 )
          v38->vfptr->__vecDelDtor(v38, 1u);
        v21 = 2;
        goto LABEL_124;
      }
LABEL_94:
      BYTE2(v2->m_TimeEnd) = 1;
      AttackCollisionTask::applyWeaponDamage(v51);
      if ( v52 && !HIBYTE(v2->m_TimeEnd) )
      {
        v63 = (_QWORD *)(*(_QWORD *)&v2[-1].mAttackPosition0.z + 56i64);
        if ( *v63 )
          v10 = (char *)v63 + *v63;
        v64 = *((_QWORD *)v10 + 9);
        if ( v64 )
        {
          v65 = (ActionNode *)&v10[v64 + 72];
          if ( v65 )
          {
            ActionController::PlayTracks((ActionController *)v2->m_Track->mMasterRate.expression.mOffset, v65, 0, 0.0);
            HIBYTE(v2->m_TimeEnd) = 1;
          }
        }
      }
      goto LABEL_101;
    }
  }
  if ( v4 < 0.0 || (v21 = 1, v4 <= *(float *)(v2->m_Track->mMasterRate.expression.mOffset + 32)) )
    v21 = 3;
  v66 = *(UFG::SimObjectCVBase **)&v2->m_Track->m_TrackClassNameUID;
  if ( v66 )
  {
    v67 = v66->m_Flags;
    if ( (v67 >> 14) & 1 )
    {
      v68 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v66);
    }
    else if ( (v67 & 0x8000u) == 0 )
    {
      if ( (v67 >> 13) & 1 )
        v68 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v66->vfptr,
                                                        UFG::TargetingSystemPedBaseComponent::_TypeUID);
      else
        v68 = (UFG::TargetingSystemPedBaseComponent *)((v67 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v66->vfptr,
                                                                           UFG::TargetingSystemPedBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v66->vfptr, UFG::TargetingSystemPedBaseComponent::_TypeUID));
    }
    else
    {
      v68 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v66);
    }
    if ( v68 )
    {
      v69 = v68->m_CachedPedsList.size;
      if ( v69 )
      {
        v70 = &v68->m_CachedPedsList.p[0].m_pPointer;
        do
        {
          if ( !AttackCollisionTask::handleIncomingAttack((AttackCollisionTask *)((char *)v2 - 40), v21, *v70) )
            break;
          LODWORD(v10) = (_DWORD)v10 + 1;
          v70 += 3;
        }
        while ( (unsigned int)v10 < v69 );
      }
    }
  }
  v71 = AttackCollisionTask::GetCharacterAnimationComponent((AttackCollisionTask *)((char *)v2 - 40));
  if ( v71 )
  {
    Creature::GetTransform(v71->mCreature, LODWORD(v2->m_TimeBegin), &transform);
    v72 = v82;
    LODWORD(v2->mHitDudes[28]) = v82;
    v73 = v83;
    HIDWORD(v2->mHitDudes[28]) = v83;
    v74 = transform.v0.x;
    *(float *)&v2->mHitDudes[29] = transform.v0.x;
    HIDWORD(v2->mHitDudes[29]) = v72;
    LODWORD(v2->mHitDudes[30]) = v73;
    *((float *)&v2->mHitDudes[30] + 1) = v74;
  }
LABEL_124:
  v75 = *(UFG::SimObjectGame **)&v2->m_Track->m_TrackClassNameUID;
  if ( v75 )
  {
    v76 = v75->m_Flags;
    if ( (v76 >> 14) & 1 )
    {
      v77 = v75->m_Components.p[15].m_pComponent;
    }
    else if ( (v76 & 0x8000u) == 0 )
    {
      if ( (v76 >> 13) & 1 )
      {
        v77 = UFG::SimObjectGame::GetComponentOfTypeHK(v75, UFG::HitReactionComponent::_TypeUID);
      }
      else if ( (v76 >> 12) & 1 )
      {
        v77 = UFG::SimObjectGame::GetComponentOfTypeHK(v75, UFG::HitReactionComponent::_TypeUID);
      }
      else
      {
        v77 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v75->vfptr, UFG::HitReactionComponent::_TypeUID);
      }
    }
    else
    {
      v77 = v75->m_Components.p[15].m_pComponent;
    }
    if ( v77 )
      v77[1].m_NameUID = v21;
  }
  return 1;
}

// File Line: 1755
// RVA: 0x2FDE10
void __fastcall AttackCollisionTask::End(AttackCollisionTask *this)
{
  AttackCollisionTask *v1; // rbx
  UFG::SimObject *v2; // r9
  bool v3; // al
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *v7; // rcx
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *v8; // rax
  UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *v9; // rdx
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h]

  v1 = this;
  v2 = this->mContext->mSimObject.m_pPointer;
  v3 = v2 && (LOBYTE(v2->m_Flags) >> 1) & 1;
  if ( !this->mHasHitAnyTarget && !v3 && LODWORD(this->m_Track[2].mMasterRate.value) != 43 )
  {
    stimulus_parameters.m_MaxStimulusDuration = -1.0;
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
    stimulus_parameters.m_StimulusEmissionType = 0;
    UFG::StimulusManager::BeginStimulus(
      UFG::StimulusManager::s_pInstance,
      eSTIMULUS_MELEE_ATTACK_NO_HIT,
      &stimulus_parameters,
      v2,
      0);
  }
  v4 = (UFG::SimObjectGame *)v1->mContext->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[15].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HitReactionComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HitReactionComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::HitReactionComponent::_TypeUID);
      }
    }
    else
    {
      v6 = v4->m_Components.p[15].m_pComponent;
    }
    if ( v6 )
      v6[1].m_NameUID = 0;
  }
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v9 = (UFG::qNode<PostAnimUpdateTask,PostAnimUpdateTaskList> *)&v1->mPrev;
  v7->mNext = v8;
  v8->mPrev = v7;
  v9->mPrev = v9;
  v9->mNext = v9;
}

// File Line: 1778
// RVA: 0x301D00
UFG::CharacterAnimationComponent *__fastcall AttackCollisionTask::GetCharacterAnimationComponent(AttackCollisionTask *this)
{
  ITrack *v1; // rax
  AttackCollisionTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rcx
  UFG::SimComponent *v8; // rax
  __int64 v9; // rax

  v1 = this->m_Track;
  v2 = this;
  v3 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( !LODWORD(v1[3].mResourceOwner) )
  {
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
        return UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
      goto LABEL_5;
    }
    return 0i64;
  }
  if ( !v3 )
    return 0i64;
  v6 = v3->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)&v3->vfptr,
             UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)&v3->vfptr,
                              UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                               (UFG::SimObject *)&v3->vfptr,
                                                                               UFG::TargetingSystemBaseComponent::_TypeUID);
    v7 = v8;
  }
  else
  {
    v7 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v7 )
    return 0i64;
  v9 = ((__int64 (*)(void))v7->vfptr[15].__vecDelDtor)();
  if ( !v9 )
    return 0i64;
  v3 = *(UFG::SimObjectCVBase **)(56i64
                                * *(unsigned __int8 *)(LODWORD(v2->m_Track[3].mResourceOwner)
                                                     + *(_QWORD *)(v9 + 96)
                                                     + 8i64)
                                + *(_QWORD *)(v9 + 88)
                                + 40);
  if ( !v3 )
    return 0i64;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
    return UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
LABEL_5:
  if ( (v4 & 0x8000u) != 0 )
    return UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
  if ( (v4 >> 13) & 1 )
    return UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
  if ( (v4 >> 12) & 1 )
    return (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
  return (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::CharacterAnimationComponent::_TypeUID);
}

// File Line: 1802
// RVA: 0x2E9020
void __fastcall AttackTimerTask::Begin(AttackTimerTask *this, ActionContext *context)
{
  AttackTimerTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[15].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
      }
    }
    else
    {
      v6 = v3->m_Components.p[15].m_pComponent;
    }
    if ( v6 )
      v6[1].m_TypeUID = 0;
    v2->mContext = v4;
  }
  else
  {
    v2->mContext = context;
  }
}

// File Line: 1814
// RVA: 0x303A80
char __fastcall AttackTimerTask::Update(AttackTimerTask *this, float timeDelta)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  if ( LOBYTE(this->m_Track[1].vfptr) )
  {
    v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = v2->m_Components.p[15].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID);
        }
        else
        {
          v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID);
        }
      }
      else
      {
        v4 = v2->m_Components.p[15].m_pComponent;
      }
      if ( v4 )
        v4[1].m_TypeUID = 0;
    }
  }
  return 1;
}

// File Line: 1832
// RVA: 0x2F36B0
void __fastcall SetEngineDamageTask::Begin(SetEngineDamageTask *this, ActionContext *context)
{
  SetEngineDamageTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rcx
  UFG::SimComponent *v6; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          return;
        if ( (v4 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v5 = (UFG::PhysicsMoverInterface *)v6;
      }
      else
      {
        v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
      }
      if ( v5 )
        UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(v5, *(float *)&v2->m_Track[1].vfptr);
    }
  }
}

// File Line: 1845
// RVA: 0x2F0E70
void __fastcall OverrideDesiredFocusModeTask::Begin(OverrideDesiredFocusModeTask *this, ActionContext *pContext)
{
  OverrideDesiredFocusModeTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  UFG::TargetingSystemPedPlayerComponent *v7; // rax

  v2 = this;
  this->m_pContext = pContext;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = (UFG::TargetingSystemPedPlayerComponent *)((__int64 (*)(void))v5->vfptr[19].__vecDelDtor)();
      if ( v7 )
        UFG::TargetingSystemPedPlayerComponent::SetOverrideDesiredFocusMode(
          v7,
          (UFG::eFocusModeEnum)v2->m_Track[1].vfptr);
    }
  }
}

// File Line: 1864
// RVA: 0x2FF270
void __fastcall OverrideDesiredFocusModeTask::End(OverrideDesiredFocusModeTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rcx
  UFG::SimComponent *v4; // rax
  __int64 v5; // rax

  if ( BYTE4(this->m_Track[1].vfptr) )
  {
    v1 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( v1 )
    {
      v2 = v1->m_Flags;
      if ( (v2 >> 14) & 1 )
      {
        v3 = v1->m_Components.p[20].m_pComponent;
      }
      else if ( (v2 & 0x8000u) == 0 )
      {
        if ( (v2 >> 13) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v2 >> 12) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v4 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v1->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v3 = v4;
      }
      else
      {
        v3 = v1->m_Components.p[20].m_pComponent;
      }
      if ( v3 )
      {
        v5 = ((__int64 (*)(void))v3->vfptr[19].__vecDelDtor)();
        if ( v5 )
        {
          *(_DWORD *)(v5 + 3424) = 0;
          UFG::TargetingSystemPedPlayerComponent::SetFocusMode((UFG::TargetingSystemPedPlayerComponent *)v5, 0);
        }
      }
    }
  }
}

// File Line: 1883
// RVA: 0x2F1CE0
void __fastcall ParkourSyncPositionTask::Begin(ParkourSyncPositionTask *this, ActionContext *context)
{
  ParkourSyncPositionTask *v2; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::WorldContextComponent *v8; // rax

  this->mSyncStarted = 0;
  this->mContext = context;
  v2 = this;
  v3 = &this->mParkourSimObject;
  if ( v3->m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  v2->mSyncBoneIndex = 0;
  v6 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::WorldContextComponent *)v6->m_Components.p[28].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v6,
                                             UFG::WorldContextComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v6,
                                             UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v6->vfptr,
                                             UFG::WorldContextComponent::_TypeUID);
      }
    }
    else
    {
      v8 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v6,
                                           UFG::WorldContextComponent::_TypeUID);
    }
    if ( v8 )
      UFG::WorldContextComponent::LatchFocusParkourHandle(v8);
  }
  ((void (__fastcall *)(ParkourSyncPositionTask *))v2->vfptr->Update)(v2);
}

// File Line: 1905
// RVA: 0x30E9A0
void __fastcall ParkourSyncPositionTask::startSync(ParkourSyncPositionTask *this)
{
  ParkourSyncPositionTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::WorldContextComponent *v4; // rdi
  UFG::SimComponent *v5; // rax
  Creature *v6; // rsi
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::CharacterAnimationComponent *v9; // rax
  signed int v10; // eax
  ITrack *v11; // r11
  UFG::ParkourHandle *v12; // rbp
  UFG::SimObject *v13; // rdi
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rax
  bool v16; // zf
  UFG::SimObjectGame *v17; // rcx

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::WorldContextComponent *)v2->m_Components.p[28].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::WorldContextComponent::_TypeUID);
        else
          v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::WorldContextComponent::_TypeUID);
      }
      v4 = (UFG::WorldContextComponent *)v5;
    }
    if ( v4 )
    {
      v6 = 0i64;
      v7 = (UFG::SimObjectCVBase *)v1->mContext->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v7);
          else
            v9 = (UFG::CharacterAnimationComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v7->vfptr,
                                                                         UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
        }
        else
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
        }
        if ( v9 )
        {
          v6 = v9->mCreature;
          if ( v6->mPose.mRigHandle.mData )
            v10 = Skeleton::GetBoneID(v6->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v1->m_Track[1].mResourceOwner));
          else
            v10 = -1;
          v1->mSyncBoneIndex = v10;
        }
      }
      v11 = v1->m_Track;
      UFG::WorldContextComponent::StartSyncHandle(
        v4,
        v1->mSyncBoneIndex,
        LOBYTE(v11[1].m_TrackClassNameUID) != 0,
        HIBYTE(v11[1].m_TrackClassNameUID) != 0,
        BYTE1(v11[1].m_TrackClassNameUID) != 0,
        BYTE2(v11[1].m_TrackClassNameUID) != 0,
        v11[1].mDisable != 0,
        v11[1].mMaster != 0,
        *(float *)&v11[1].mMasterRate.text.mOffset,
        *(float *)&v11[1].mResourceOwner);
      if ( v1->m_Track[1].mBreakPoint )
      {
        if ( v6 )
        {
          v12 = v4->mParkourHandle.m_pPointer;
          if ( v12 )
          {
            v13 = v12->mSimObject.m_pPointer;
            if ( v13 )
            {
              v14 = v13->m_Flags;
              if ( (v14 >> 14) & 1 )
              {
                v15 = v13->m_Components.p[9].m_pComponent;
              }
              else if ( (v14 & 0x8000u) == 0 )
              {
                if ( (v14 >> 13) & 1 )
                {
                  v15 = v13->m_Components.p[8].m_pComponent;
                }
                else
                {
                  v16 = ((v14 >> 12) & 1) == 0;
                  v17 = (UFG::SimObjectGame *)v12->mSimObject.m_pPointer;
                  if ( v16 )
                    v15 = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v17->vfptr,
                            UFG::BaseAnimationComponent::_TypeUID);
                  else
                    v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::BaseAnimationComponent::_TypeUID);
                }
              }
              else
              {
                v15 = v13->m_Components.p[9].m_pComponent;
              }
              if ( v15 && *(_QWORD *)&v15[2].m_TypeUID )
              {
                UFG::qSafePointer<Creature,Creature>::operator=(
                  (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v1->mParkourSimObject,
                  (UFG::SimComponent *)v13);
                Creature::AddAttachmentParkour(
                  v6,
                  v1->mParkourSimObject.m_pPointer,
                  v1->mSyncBoneIndex,
                  v1->mContext->mSimObject.m_pPointer,
                  v12,
                  *(float *)&v1->m_Track[1].mResourceOwner);
              }
            }
          }
        }
      }
    }
  }
  v1->mSyncStarted = 1;
}

// File Line: 1957
// RVA: 0x305F60
signed __int64 __fastcall ParkourSyncPositionTask::Update(ParkourSyncPositionTask *this, float timeDelta)
{
  ParkourSyncPositionTask *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  signed __int64 result; // rax

  v2 = this;
  v3 = this->mContext->mActionController->m_ActionNodePlayTime;
  if ( !this->mSyncStarted )
  {
    v4 = *(float *)&this->m_Track[1].vfptr;
    if ( v4 >= 0.0 && v3 >= v4 )
      ParkourSyncPositionTask::startSync(this);
  }
  if ( v2->mSyncStarted != 1 )
    return 1i64;
  v5 = *((float *)&v2->m_Track[1].vfptr + 1);
  if ( v5 < 0.0 )
    return 1i64;
  result = 1i64;
  if ( v3 >= v5 )
    result = 0i64;
  return result;
}

// File Line: 1995
// RVA: 0x2FF8A0
void __fastcall ParkourSyncPositionTask::End(ParkourSyncPositionTask *this)
{
  ParkourSyncPositionTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::WorldContextComponent *v4; // rax
  UFG::SimObjectCVBase *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::CharacterAnimationComponent *v7; // rax
  Creature *v8; // rcx

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::WorldContextComponent *)v2->m_Components.p[28].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v2,
                                             UFG::WorldContextComponent::_TypeUID);
      else
        v4 = (UFG::WorldContextComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v2,
                                                               UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::WorldContextComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v2,
                                           UFG::WorldContextComponent::_TypeUID);
    }
    if ( v4 )
      UFG::WorldContextComponent::StopSync(v4);
  }
  if ( v1->m_Track[1].mBreakPoint )
  {
    if ( v1->mParkourSimObject.m_pPointer )
    {
      v5 = (UFG::SimObjectCVBase *)v1->mContext->mSimObject.m_pPointer;
      if ( v5 )
      {
        v6 = v5->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
          {
            v7 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
          }
          else if ( (v6 >> 12) & 1 )
          {
            v7 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v5->vfptr,
                                                       UFG::CharacterAnimationComponent::_TypeUID);
          }
          else
          {
            v7 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v5->vfptr,
                                                       UFG::CharacterAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
        }
        if ( v7 )
        {
          v8 = v7->mCreature;
          if ( v8 )
            Creature::RemoveAttachment(
              v8,
              v1->mParkourSimObject.m_pPointer,
              v1->mSyncBoneIndex,
              v1->mContext->mSimObject.m_pPointer);
        }
      }
    }
  }
}

// File Line: 2022
// RVA: 0x2F1C40
void __fastcall ParkourNeighborAdvanceTask::Begin(ParkourNeighborAdvanceTask *this, ActionContext *context)
{
  ParkourNeighborAdvanceTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::WorldContextComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::WorldContextComponent *)v3->m_Components.p[28].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::WorldContextComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
      }
      v5 = (UFG::WorldContextComponent *)v6;
    }
    if ( v5 )
      UFG::WorldContextComponent::AdvanceParkourNeighbor(v5, LOBYTE(v2->m_Track[1].vfptr) != 0);
  }
}

// File Line: 2046
// RVA: 0x2F1750
void __fastcall ParkourConstrainTask::Begin(ParkourConstrainTask *this, ActionContext *context)
{
  ParkourConstrainTask *v2; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::RagdollComponent *v6; // rsi
  ActionContext *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::WorldContextComponent *v10; // rdi
  UFG::SimComponent *v11; // rax
  UFG::SimObjectCVBase *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *v15; // r14
  signed int v16; // eax
  UFG::SimObject *v17; // rcx
  UFG::ParkourHandle *v18; // rdi
  UFG::Ragdoll *v19; // rcx
  hkpRigidBody *v20; // r15
  UFG::qVector3 *v21; // rax
  float v22; // xmm9_4
  __m128 v23; // xmm8
  float v24; // xmm10_4
  __m128 v25; // xmm2
  float v26; // xmm1_4
  float v27; // xmm8_4
  float v28; // xmm9_4
  float v29; // xmm10_4
  float v30; // xmm4_4
  float v31; // xmm6_4
  UFG::Constraint *v32; // rax
  UFG::qVector3 v33; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 result; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 vHandleAxis; // [rsp+70h] [rbp-90h]
  UFG::qVector4 vHandleOrigin; // [rsp+7Ch] [rbp-84h]
  UFG::qVector4 vSyncPosition; // [rsp+8Ch] [rbp-74h]
  UFG::qVector4 v38; // [rsp+A0h] [rbp-60h]
  float fRightConstraint; // [rsp+130h] [rbp+30h]
  float fLeftConstraint; // [rsp+138h] [rbp+38h]

  this->mSyncSuccess = 0;
  this->mContext = context;
  v2 = this;
  v3 = &this->mParkourSimObject;
  if ( v3->m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v6 = 0i64;
  v3->m_pPointer = 0i64;
  v7 = v2->mContext;
  v2->mSyncBoneIndex = 0;
  v8 = (UFG::SimObjectGame *)v7->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = (UFG::WorldContextComponent *)v8->m_Components.p[28].m_pComponent;
    }
    else
    {
      if ( (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID);
        else
          v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID);
      }
      v10 = (UFG::WorldContextComponent *)v11;
    }
    if ( v10 )
    {
      UFG::WorldContextComponent::LatchFocusParkourHandle(v10);
      v12 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12);
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
            v14 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v12);
          else
            v14 = (UFG::CharacterAnimationComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v12->vfptr,
                                                                           UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
        }
        else
        {
          v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12);
        }
        if ( v14 )
        {
          v15 = v14->mCreature;
          if ( v15->mPose.mRigHandle.mData )
            v16 = Skeleton::GetBoneID(v15->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v2->m_Track[1].mResourceOwner));
          else
            v16 = -1;
          v2->mSyncBoneIndex = v16;
          v17 = v2->mContext->mSimObject.m_pPointer;
          if ( v17 )
            v6 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(v17, UFG::RagdollComponent::_TypeUID);
          v18 = v10->mParkourHandle.m_pPointer;
          if ( v6 )
          {
            if ( v18 )
            {
              v19 = v6->mRagdoll;
              if ( v19 )
              {
                v20 = UFG::Ragdoll::GetRigidBody(v19, v2->mSyncBoneIndex);
                if ( v20 )
                {
                  Creature::GetTranslation(v15, &result, v2->mSyncBoneIndex);
                  UFG::ParkourHandle::GetPosition(v18, &v33);
                  v21 = UFG::ParkourHandle::GetAxis(v18, &vHandleAxis);
                  v22 = v21->y;
                  v23 = (__m128)LODWORD(v21->x);
                  v24 = v21->z;
                  v25 = v23;
                  v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22))
                                  + (float)(v24 * v24);
                  if ( v25.m128_f32[0] == 0.0 )
                    v26 = 0.0;
                  else
                    v26 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25));
                  v27 = v23.m128_f32[0] * v26;
                  v28 = v22 * v26;
                  v29 = v24 * v26;
                  v30 = UFG::ParkourHandle::GetHalfLength(v18);
                  v33.x = v33.x + (float)(v27 * v30);
                  v33.y = v33.y + (float)(v28 * v30);
                  v33.z = v33.z + (float)(v30 * v29);
                  v31 = UFG::ParkourHandle::GetHalfLength(v18) * 2.0;
                  fLeftConstraint = 0.0;
                  fRightConstraint = 0.0;
                  getParkourEdgeConstraints(v18, 1, 1, 0.0, 0.0, &fLeftConstraint, &fRightConstraint);
                  *(UFG::qVector3 *)&vHandleOrigin.x = v33;
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
                  v32 = UFG::CreateConstraint_Util(v20, 0i64, &result);
                  UFG::RagdollComponent::AddConstraint(v6, v32);
                  v2->mSyncSuccess = 1;
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
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::WorldContextComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::WorldContextComponent *)v1->m_Components.p[28].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v1,
                                             UFG::WorldContextComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v1,
                                             UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v1->vfptr,
                                             UFG::WorldContextComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v1,
                                           UFG::WorldContextComponent::_TypeUID);
    }
    if ( v3 )
      UFG::WorldContextComponent::LatchParkourHandle(v3, 0i64);
  }
}

// File Line: 2124
// RVA: 0x2EB490
void __fastcall CoverSyncPositionTask::Begin(CoverSyncPositionTask *this, ActionContext *context)
{
  CoverSyncPositionTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::WorldContextComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  int v7; // edi
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  Creature *v11; // rcx
  ITrack *v12; // rax
  float blendIn; // ST48_4
  bool v14; // cl
  bool v15; // zf

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::WorldContextComponent *)v3->m_Components.p[28].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
        else
          v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
      }
      v5 = (UFG::WorldContextComponent *)v6;
    }
    if ( v5 )
    {
      v7 = 0;
      v8 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
          }
          else if ( (v9 >> 12) & 1 )
          {
            v10 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v8->vfptr,
                                                        UFG::CharacterAnimationComponent::_TypeUID);
          }
          else
          {
            v10 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                        (UFG::SimObject *)&v8->vfptr,
                                                        UFG::CharacterAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
        }
        if ( v10 )
        {
          v11 = v10->mCreature;
          if ( v11->mPose.mRigHandle.mData )
            v7 = Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v2->m_Track[1].vfptr));
          else
            v7 = -1;
        }
      }
      v12 = v2->m_Track;
      blendIn = *(float *)&v12[1].vfptr;
      v14 = BYTE1(v12[1].mResourceOwner) != 0;
      v15 = LOBYTE(v12[1].mResourceOwner) == 0;
      v5->mbSyncingCoverRCorner = BYTE2(v12[1].mResourceOwner) != 0;
      v5->mbSyncingCoverLCorner = v14;
      v5->mbSyncingCoverParkour = !v15;
      UFG::WorldContextComponent::StartSync(v5, v7, 0, 0, 1, 0, 0, 0, 0.0, blendIn);
    }
  }
}

// File Line: 2153
// RVA: 0x2FE830
void __fastcall CoverSyncPositionTask::End(CoverSyncPositionTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::WorldContextComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::WorldContextComponent *)v1->m_Components.p[28].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v1,
                                             UFG::WorldContextComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v1,
                                             UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v1->vfptr,
                                             UFG::WorldContextComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v1,
                                           UFG::WorldContextComponent::_TypeUID);
    }
    if ( v3 )
      UFG::WorldContextComponent::StopSync(v3);
  }
}

// File Line: 2167
// RVA: 0x2EB350
void __fastcall CoverHoldPositionTask::Begin(CoverHoldPositionTask *this, ActionContext *context)
{
  CoverHoldPositionTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rdx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    v4 = v6;
  }
  else
  {
    v4 = 0i64;
  }
  ++LODWORD(v4[2].m_BoundComponentHandles.mNode.mNext);
  if ( LOBYTE(v2->m_Track[1].vfptr) )
    ++HIDWORD(v4[2].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 2187
// RVA: 0x2FE670
void __fastcall CoverHoldPositionTask::End(CoverHoldPositionTask *this)
{
  CoverHoldPositionTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  UFG::SimComponent *v3; // rdx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
    }
    v3 = v5;
  }
  else
  {
    v3 = 0i64;
  }
  --LODWORD(v3[2].m_BoundComponentHandles.mNode.mNext);
  if ( LOBYTE(v1->m_Track[1].vfptr) )
    --HIDWORD(v3[2].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 2237
// RVA: 0x2FE7A0
void __fastcall CoverProbeForwardAndLatchTask::End(CoverProbeForwardAndLatchTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  if ( this->m_bLatched )
  {
    v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v1 )
    {
      v2 = v1->m_Flags;
      if ( (v2 >> 14) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v2 & 0x8000u) == 0 )
      {
        if ( (v2 >> 13) & 1 )
        {
          v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
        }
        else if ( (v2 >> 12) & 1 )
        {
          v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
        }
        else
        {
          v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::AICoverComponent::_TypeUID);
        }
      }
      else
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
      }
      if ( v3 )
        --LODWORD(v3[2].m_BoundComponentHandles.mNode.mNext);
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
  CoverProbeForwardAndLatchTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObject *v7; // rcx
  UFG::TransformNodeComponent *v8; // rsi
  ITrack *v9; // rax
  __int64 v10; // r8
  float v11; // xmm0_4
  float v12; // xmm2_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v13; // rax
  float v14; // xmm4_4
  float v15; // xmm5_4
  unsigned int v16; // xmm0_4
  unsigned int v17; // xmm1_4
  float v18; // xmm2_4
  bool v19; // zf
  bool result; // al
  unsigned __int64 v21; // [rsp+20h] [rbp-18h]
  float v22; // [rsp+28h] [rbp-10h]

  v2 = this;
  if ( this->m_bLatched )
    return 1;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 1;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
    }
  }
  else
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
  }
  v6 = v5;
  if ( !v5 )
    return 1;
  v7 = v2->mContext->mSimObject.m_pPointer;
  if ( v7 )
    v8 = v7->m_pTransformNodeComponent;
  else
    v8 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v9 = v2->m_Track;
  LOBYTE(v10) = 1;
  v11 = *((float *)&v9[1].vfptr + 1);
  v12 = *(float *)&v9[1].vfptr;
  v13 = v6->vfptr;
  v14 = UFG::qVector3::msAxisZ.y * v11;
  v15 = UFG::qVector3::msAxisZ.z * v11;
  *(float *)&v16 = (float)((float)(v12 * v8->mWorldTransform.v0.x) + v8->mWorldTransform.v3.x)
                 + (float)(UFG::qVector3::msAxisZ.x * v11);
  *(float *)&v17 = (float)((float)(v12 * v8->mWorldTransform.v0.y) + v8->mWorldTransform.v3.y) + v14;
  v18 = (float)((float)(v12 * v8->mWorldTransform.v0.z) + v8->mWorldTransform.v3.z) + v15;
  v21 = __PAIR__(v17, v16);
  v22 = v18;
  v19 = ((unsigned __int8 (__fastcall *)(UFG::SimComponent *, unsigned __int64 *, __int64, _QWORD, unsigned __int64, _QWORD))v13[17].__vecDelDtor)(
          v6,
          &v21,
          v10,
          0i64,
          __PAIR__(v17, v16),
          *(_QWORD *)&v22) == 0;
  result = 1;
  if ( !v19 )
  {
    v2->m_bLatched = 1;
    ++LODWORD(v6[2].m_BoundComponentHandles.mNode.mNext);
  }
  return result;
}

// File Line: 2289
// RVA: 0x2FE710
void __fastcall CoverProbeAndLatchTask::End(CoverProbeAndLatchTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
    }
    if ( v3 )
      --LODWORD(v3[2].m_BoundComponentHandles.mNode.mNext);
  }
}

// File Line: 2302
// RVA: 0x2EB400
void __fastcall CoverSetPopoutSideTask::Begin(CoverSetPopoutSideTask *this, ActionContext *context)
{
  CoverSetPopoutSideTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  unsigned int v5; // edx
  UFG::SimComponent *v6; // rax
  bool v7; // zf

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
  {
    MEMORY[0x80] = v2->m_Track[1].vfptr;
    return;
  }
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 || (v4 & 0x8000u) != 0 || (v4 >> 13) & 1 )
  {
    v5 = UFG::AICoverComponent::_TypeUID;
  }
  else
  {
    v7 = ((v4 >> 12) & 1) == 0;
    v5 = UFG::AICoverComponent::_TypeUID;
    if ( v7 )
    {
      v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
      goto LABEL_10;
    }
  }
  v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, v5);
LABEL_10:
  LODWORD(v6[2].vfptr) = v2->m_Track[1].vfptr;
}

// File Line: 2320
// RVA: 0x2EDF20
void __fastcall DynamicWallHandleTask::Begin(DynamicWallHandleTask *this, ActionContext *context)
{
  DynamicWallHandleTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SensorComponent *v5; // rax
  UFG::WallRunningRequest *v6; // rax

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::SensorComponent *)v3->m_Components.p[26].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SensorComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SensorComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::SensorComponent *)UFG::SimObject::GetComponentOfType(
                                       (UFG::SimObject *)&v3->vfptr,
                                       UFG::SensorComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::SensorComponent *)v3->m_Components.p[26].m_pComponent;
    }
    if ( v5 )
    {
      v6 = UFG::SensorComponent::BeginWallRunningTest(v5);
      v2->mWallRunningRequest = v6;
      if ( v6 )
      {
        v6->relativeAngle = *(float *)&v2->m_Track[1].vfptr;
        v2->mWallRunningRequest->firstRayHeight = *((float *)&v2->m_Track[1].vfptr + 1);
        v2->mWallRunningRequest->raySpacing = *(float *)&v2->m_Track[1].mResourceOwner;
        v2->mWallRunningRequest->rayLength = *((float *)&v2->m_Track[1].mResourceOwner + 1);
      }
    }
  }
}

// File Line: 2340
// RVA: 0x2FEBA0
void __fastcall DynamicWallHandleTask::End(DynamicWallHandleTask *this)
{
  DynamicWallHandleTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SensorComponent *v4; // rax
  UFG::WallRunningRequest *v5; // rdx

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::SensorComponent *)v2->m_Components.p[26].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::SensorComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::SensorComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::SensorComponent *)UFG::SimObject::GetComponentOfType(
                                       (UFG::SimObject *)&v2->vfptr,
                                       UFG::SensorComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::SensorComponent *)v2->m_Components.p[26].m_pComponent;
    }
    if ( v4 )
    {
      v5 = v1->mWallRunningRequest;
      if ( v5 )
      {
        UFG::SensorComponent::EndWallRunningTest(v4, v5);
        v1->mWallRunningRequest = 0i64;
      }
    }
  }
}

// File Line: 2353
// RVA: 0x2EE040
void __fastcall EventTask::Begin(EventTask *this, ActionContext *context)
{
  ActionContext *v2; // rdi
  EventTask *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  ITrack *v5; // rdx
  const char *v6; // rdx

  v2 = context;
  v3 = this;
  v4 = UFG::qMalloc(0x50ui64, "EventTask::Begin", 0i64);
  if ( v4 )
  {
    v5 = v3->m_Track + 1;
    if ( (_QWORD)v5->vfptr & 0xFFFFFFFFFFFFFFFEui64 )
      v6 = (char *)v5 + ((_QWORD)v5->vfptr & 0xFFFFFFFFFFFFFFFEui64);
    else
      v6 = BinString::sEmptyString;
    UFG::AnimatedEvent::AnimatedEvent((UFG::AnimatedEvent *)v4, v6, &v2->mSimObject);
  }
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
}

// File Line: 2364
// RVA: 0x2E8950
void __fastcall ApplyStimulusEmitterToTargetTask::Begin(ApplyStimulusEmitterToTargetTask *this, ActionContext *context)
{
  ITrack *v2; // r9
  char v3; // bl
  ApplyStimulusEmitterToTargetTask *v4; // rdi
  int v5; // er8
  UFG::SimObjectGame *v6; // r8
  float v7; // xmm1_4
  __int64 v8; // rsi
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // r8
  UFG::eStimulusType v13; // edx
  char *v14; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-48h]
  UFG::qString v16; // [rsp+48h] [rbp-30h]

  v2 = this->m_Track;
  v3 = 0;
  v4 = this;
  v5 = (int)v2[1].vfptr;
  stimulus_parameters.m_StimulusEmissionType = -1;
  stimulus_parameters.m_MaxStimulusDuration = -1.0;
  stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
  stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
  if ( !v5 )
  {
    stimulus_parameters.m_StimulusEmissionType = 1;
    goto LABEL_5;
  }
  if ( v5 == 1 )
  {
    stimulus_parameters.m_StimulusEmissionType = 0;
LABEL_5:
    v3 = 1;
  }
  v6 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  stimulus_parameters.m_MaxStimulusDuration = *(float *)&v2[1].mResourceOwner;
  v7 = *((float *)&v2[1].mResourceOwner + 1);
  stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
  stimulus_parameters.m_EmitUntilSpeedLessThan = v7;
  v8 = SHIDWORD(v2[1].vfptr);
  if ( v6
    && ((v9 = v6->m_Flags, !((v9 >> 14) & 1)) ? ((v9 & 0x8000u) == 0 ? (!((v9 >> 13) & 1) ? (!((v9 >> 12) & 1) ? (v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v10 = v11) : (v10 = v6->m_Components.p[20].m_pComponent)) : (v10 = v6->m_Components.p[20].m_pComponent),
        v10
     && (v12 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + (unsigned int)v8 + 8i64)
                                  + *(_QWORD *)&v10[1].m_TypeUID
                                  + 40)) != 0i64) )
  {
    v13 = v4->m_Track[1].mMasterRate.expression.mOffset;
    if ( v3 )
      UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, v13, &stimulus_parameters, v12, 0);
    else
      UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, v13, v12);
  }
  else
  {
    v14 = ActionPath::GetString_DBG((ActionPath *)&v4->m_Track[1].m_TrackClassNameUID);
    UFG::qString::qString(
      &v16,
      "ERROR: ApplyStimulusEmitterToTargetTrack in %s: invalid target %s",
      v14,
      UFG::TargetTypeEnumNames[v8]);
    UFG::qString::~qString(&v16);
  }
}

// File Line: 2474
// RVA: 0x2DDD00
void __fastcall AttackRightsTask::AttackRightsTask(AttackRightsTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&AttackRightsTask::`vftable';
  v2 = &this->mAttackRightsComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mAttackRightsComponent.m_pPointer = 0i64;
  this->mPreviousAttackRights = 0;
  this->mpContext = 0i64;
}

// File Line: 2496
// RVA: 0x2E8E60
void __fastcall AttackRightsTask::Begin(AttackRightsTask *this, ActionContext *context)
{
  ActionContext *v2; // r15
  AttackRightsTask *v3; // rsi
  bool v4; // bp
  UFG::SimObjectGame *v5; // rdi
  UFG::TransformNodeComponent *v6; // r14
  UFG::SimComponent *v7; // rbx
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  bool v14; // al
  const char *v15; // r8
  int v16; // eax
  UFG::qString result; // [rsp+28h] [rbp-40h]

  v2 = context;
  v3 = this;
  v4 = LOBYTE(this->m_Track[1].vfptr) != 0;
  v5 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v6 = 0i64;
  if ( v5 )
  {
    v8 = v5->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[46].m_pComponent;
    }
    else
    {
      if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::AttackRightsComponent::_TypeUID);
        }
        else if ( (v8 >> 12) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::AttackRightsComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::AttackRightsComponent::_TypeUID);
        }
      }
      else
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::AttackRightsComponent::_TypeUID);
      }
      v7 = v9;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v10 = &v3->mAttackRightsComponent;
  if ( v3->mAttackRightsComponent.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v3->mAttackRightsComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v3->mAttackRightsComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mAttackRightsComponent.mPrev;
  }
  v3->mAttackRightsComponent.m_pPointer = v7;
  if ( v7 )
  {
    v13 = v7->m_SafePointerList.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v10->mPrev = v13;
    v3->mAttackRightsComponent.mNext = &v7->m_SafePointerList.mNode;
    v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  }
  v3->mpContext = v2;
  if ( v7 )
  {
    v14 = LOBYTE(v7[149].vfptr) && BYTE1(v7[149].vfptr) && BYTE2(v7[149].vfptr);
    v3->mPreviousAttackRights = v14;
    if ( v14 == v4 )
    {
      if ( v5 )
        v6 = v5->m_pTransformNodeComponent;
      v15 = "false";
      if ( v4 )
        v15 = "true";
      v16 = (unsigned __int64)UFG::qString::FormatEx(
                                &result,
                                "AttackRightsTrack: Already set attacking enabled to %s",
                                v15);
      UFG::DrawDebugText(v6, &UFG::qColour::White, result.mData, v16, -2i64);
    }
    else
    {
      UFG::qString::qString(&result);
      LOBYTE(v7[149].vfptr) = v4;
      BYTE1(v7[149].vfptr) = v4;
      BYTE2(v7[149].vfptr) = v4;
      UFG::qString::Set((UFG::qString *)&v7[161].m_TypeUID, result.mData);
    }
    UFG::qString::~qString(&result);
  }
}

// File Line: 2530
// RVA: 0x2FDF50
void __fastcall AttackRightsTask::End(AttackRightsTask *this)
{
  AttackRightsTask *v1; // rbx
  UFG::SimComponent *v2; // rax
  bool v3; // al
  char *v4; // rdx
  UFG::SimComponent *v5; // rcx
  bool v6; // al
  UFG::qString v7; // [rsp+28h] [rbp-30h]

  v1 = this;
  if ( BYTE1(this->m_Track[1].vfptr) )
  {
    v2 = this->mAttackRightsComponent.m_pPointer;
    if ( v2 )
    {
      v3 = LOBYTE(v2[149].vfptr) && BYTE1(v2[149].vfptr) && BYTE2(v2[149].vfptr);
      if ( this->mPreviousAttackRights != v3 )
      {
        UFG::qString::qString(&v7);
        v4 = v7.mData;
        v5 = v1->mAttackRightsComponent.m_pPointer;
        v6 = v1->mPreviousAttackRights;
        LOBYTE(v5[149].vfptr) = v6;
        BYTE1(v5[149].vfptr) = v6;
        BYTE2(v5[149].vfptr) = v6;
        UFG::qString::Set((UFG::qString *)&v5[161].m_TypeUID, v4);
        UFG::qString::~qString(&v7);
      }
    }
  }
}

// File Line: 2572
// RVA: 0x2F4350
void __fastcall SkookumTask::Begin(SkookumTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rbx
  SkookumTask *v3; // rdi
  UFG::SimObject *v4; // rax
  SSCode *v5; // rbp
  UFG::SimObject *v6; // r8
  unsigned __int16 v7; // dx
  UFG::TSActorComponent *v8; // rax
  UFG::TSActor *v9; // rax

  v2 = pContext;
  v3 = this;
  this->mMethodFinished = 0;
  this->mpMethodWrapper = 0i64;
  if ( pContext )
  {
    v4 = pContext->mSimObject.m_pPointer;
    if ( !v4 || !((LOBYTE(v4->m_Flags) >> 1) & 1) )
    {
      v5 = UFG::ScriptCache::GetScriptCode(*(UFG::ScriptCache::Script **)&this->m_Track[1].m_TrackClassNameUID);
      if ( v5 )
      {
        v6 = v2->mSimObject.m_pPointer;
        if ( v6
          && ((v7 = v6->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v2->mSimObject.m_pPointer, UFG::TSActorComponent::_TypeUID)) : (v8 = (UFG::TSActorComponent *)v6->m_Components.p[2].m_pComponent)) : (v8 = (UFG::TSActorComponent *)v6->m_Components.p[3].m_pComponent)) : (v8 = (UFG::TSActorComponent *)v6->m_Components.p[4].m_pComponent)) : (v8 = (UFG::TSActorComponent *)v6->m_Components.p[4].m_pComponent),
              v8) )
        {
          v9 = UFG::TSActorComponent::GetActor(v8);
        }
        else
        {
          v9 = (UFG::TSActor *)SkookumScript::c_world_p;
        }
        v3->mpMethodWrapper = (SSIExternalMethodCallWrapper *)UFG::SkookumMgr::RunExternalCodeBlock(
                                                                v5,
                                                                v9->i_class_p,
                                                                (SSInstance *)&v9->vfptr,
                                                                &v3->mMethodFinished,
                                                                0i64);
      }
    }
  }
}

// File Line: 2600
// RVA: 0x30A050
_BOOL8 __fastcall SkookumTask::Update(SkookumTask *this, float timeDelta)
{
  return this->mMethodFinished == 0;
}

// File Line: 2607
// RVA: 0x300250
void __fastcall SkookumTask::End(SkookumTask *this)
{
  SSIExternalMethodCallWrapper *v1; // rdx

  if ( !this->mMethodFinished )
  {
    v1 = this->mpMethodWrapper;
    if ( v1 )
      v1->i_finished_p = 0i64;
  }
  this->mpMethodWrapper = 0i64;
  this->mMethodFinished = 0;
}

// File Line: 2613
// RVA: 0x2F3A20
void __fastcall ShootTask::Begin(ShootTask *this, ActionContext *context)
{
  ShootTask *v2; // r13
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // r15
  UFG::SubTargetingLocation *pSubTargetingLocation; // r12
  int v6; // er14
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::GunComponent *v9; // rbp
  UFG::SimObjectGame *v10; // r8
  unsigned __int16 v11; // cx
  UFG::InventoryItemComponent *v12; // rbx
  UFG::SimComponent *v13; // rax
  UFG::SimObjectGame *v14; // rdi
  UFG::SimComponent *v15; // rax
  bool v16; // bl
  unsigned __int16 v17; // cx
  UFG::SimComponent *v18; // rbx
  UFG::SimComponent *v19; // rax
  unsigned __int16 v20; // cx
  UFG::AimingBaseComponent *v21; // rsi
  UFG::SimComponent *v22; // rax
  unsigned __int16 v23; // cx
  UFG::SimComponent *v24; // rax
  __int64 v25; // rax
  ITrack *v26; // rax
  unsigned __int64 v27; // rcx
  const char *v28; // rdx
  UFG::SimObject *pShootOriginSimObject; // rbx
  UFG::qSymbolUC *originBoneId; // rax
  UFG::SimObjectGame *v31; // rcx
  unsigned __int16 v32; // dx
  UFG::SimComponent *v33; // rdx
  UFG::SimComponent *v34; // rax
  UFG::SimObject *v35; // rdi
  ITrack *v36; // rax
  unsigned __int64 v37; // rcx
  const char *v38; // rdx
  UFG::SimObject *v39; // rbx
  UFG::qSymbolUC *v40; // rax
  UFG::qSymbolUC result; // [rsp+78h] [rbp+10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !((v3->m_Flags >> 10) & 1) )
  {
    pSubTargetingLocation = 0i64;
    v6 = (LOBYTE(v2->m_Track[1].mResourceOwner) != 0 ? 2 : 0) | (BYTE1(v2->m_Track[1].mResourceOwner) != 0);
    if ( v3 )
    {
      v7 = v3->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
        else
          v8 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
      }
      v9 = (UFG::GunComponent *)v8;
      if ( v8 )
      {
        v10 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
        if ( !v10 )
          goto LABEL_87;
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 || (v11 & 0x8000u) != 0 )
          goto LABEL_87;
        if ( (v11 >> 13) & 1 )
        {
          v12 = (UFG::InventoryItemComponent *)v10->m_Components.p[11].m_pComponent;
        }
        else
        {
          v13 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::InventoryItemComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::InventoryItemComponent::_TypeUID);
          v12 = (UFG::InventoryItemComponent *)v13;
        }
        if ( !v12 )
          goto LABEL_87;
        v14 = (UFG::SimObjectGame *)UFG::InventoryItemComponent::GetOwnerSimObject(v12);
        if ( !v14 )
          goto LABEL_87;
        v15 = v12->m_pOwnerInventoryComponent.m_pPointer;
        v16 = v15 && BYTE1(v15[14].m_pSimObject);
        if ( UFG::IsAnyLocalPlayer((UFG::SimObject *)&v14->vfptr) && v16 )
          v6 &= 0xFFFFFFFE;
        v17 = v14->m_Flags;
        if ( (v17 >> 14) & 1 )
        {
          v18 = v14->m_Components.p[20].m_pComponent;
        }
        else if ( (v17 & 0x8000u) == 0 )
        {
          if ( (v17 >> 13) & 1 )
            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v19 = (v17 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v14,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v14->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
          v18 = v19;
        }
        else
        {
          v18 = v14->m_Components.p[20].m_pComponent;
        }
        if ( v18 )
        {
          v20 = v14->m_Flags;
          if ( (v20 >> 14) & 1 )
          {
            v21 = (UFG::AimingBaseComponent *)v14->m_Components.p[47].m_pComponent;
          }
          else
          {
            if ( (v20 & 0x8000u) == 0 )
            {
              if ( (v20 >> 13) & 1 )
              {
                v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::AimingBaseComponent::_TypeUID);
              }
              else if ( (v20 >> 12) & 1 )
              {
                v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::AimingBaseComponent::_TypeUID);
              }
              else
              {
                v22 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v14->vfptr,
                        UFG::AimingBaseComponent::_TypeUID);
              }
            }
            else
            {
              v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::AimingBaseComponent::_TypeUID);
            }
            v21 = (UFG::AimingBaseComponent *)v22;
          }
          v23 = v14->m_Flags;
          if ( (v23 >> 14) & 1 )
          {
            v24 = v14->m_Components.p[15].m_pComponent;
          }
          else if ( (v23 & 0x8000u) == 0 )
          {
            if ( (v23 >> 13) & 1 )
            {
              v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::HitReactionComponent::_TypeUID);
            }
            else if ( (v23 >> 12) & 1 )
            {
              v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::HitReactionComponent::_TypeUID);
            }
            else
            {
              v24 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v14->vfptr,
                      UFG::HitReactionComponent::_TypeUID);
            }
          }
          else
          {
            v24 = v14->m_Components.p[15].m_pComponent;
          }
          if ( v24 )
            v24[1].m_TypeUID = 0;
          v25 = ((__int64 (__fastcall *)(UFG::SimComponent *))v18->vfptr[19].__vecDelDtor)(v18);
          if ( v25 )
            pSubTargetingLocation = *(UFG::SubTargetingLocation **)(v25 + 2736);
          v26 = v2->m_Track;
          v27 = (_QWORD)v26[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
          v28 = (char *)&v26[1] + v27;
          if ( !v27 )
            v28 = BinString::sEmptyString;
          pShootOriginSimObject = v4->mSimObject.m_pPointer;
          originBoneId = UFG::qSymbolUC::create_from_string(&result, v28);
          UFG::GunComponent::Shoot(
            v9,
            (UFG::SimObject *)&v14->vfptr,
            v21,
            v6,
            pSubTargetingLocation,
            pShootOriginSimObject,
            originBoneId);
        }
        else
        {
LABEL_87:
          v31 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
          if ( v31
            && ((v32 = v31->m_Flags, !((v32 >> 14) & 1)) ? ((v32 & 0x8000u) == 0 ? (!((v32 >> 13) & 1) ? (!((v32 >> 12) & 1) ? (v34 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v31->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                                    v33 = v34) : (v33 = v31->m_Components.p[20].m_pComponent)) : (v33 = v31->m_Components.p[20].m_pComponent),
                v33
             && (v35 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v33[1].m_Flags + 62i64)
                                          + *(_QWORD *)&v33[1].m_TypeUID
                                          + 40)) != 0i64) )
          {
            v36 = v2->m_Track;
            v37 = (_QWORD)v36[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
            v38 = (char *)&v36[1] + v37;
            if ( !v37 )
              v38 = BinString::sEmptyString;
            v39 = v4->mSimObject.m_pPointer;
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
  ActionContext *v3; // rdi
  ShootTaskTU *v4; // r13
  ITrack *v5; // r8
  UFG::AimingBaseComponent *v6; // rbp
  bool v7; // zf
  char v8; // al
  int v9; // er14
  UFG::SimObjectGame *v10; // rbx
  int v11; // er12
  UFG::SimComponent *v12; // rsi
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // r8
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  UFG::GunComponent *v20; // r14
  UFG::SimObject *v21; // r8
  unsigned __int16 v22; // cx
  UFG::InventoryItemComponent *v23; // rdi
  UFG::SimObjectGame *v24; // rcx
  UFG::SimComponent *v25; // rax
  UFG::SimComponent *v26; // rax
  bool v27; // di
  unsigned __int16 v28; // cx
  UFG::SimComponent *v29; // rax
  __int64 v30; // rax
  unsigned __int16 v31; // cx
  UFG::SimComponent *v32; // rax
  ITrack *v33; // rax
  unsigned __int64 v34; // rcx
  const char *v35; // rdx
  UFG::qSymbolUC *originBoneId; // rax
  UFG::qSymbolUC result; // [rsp+88h] [rbp+10h]
  UFG::SubTargetingLocation *pSubTargetingLocation; // [rsp+90h] [rbp+18h]

  pShootOriginSimObject = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = context;
  v4 = this;
  if ( !((pShootOriginSimObject->m_Flags >> 10) & 1) )
  {
    v5 = this->m_Track;
    v6 = 0i64;
    v7 = BYTE1(v5[1].m_TrackClassNameUID) == 0;
    v8 = -LOBYTE(v5[1].m_TrackClassNameUID);
    v9 = (int)v5[1].vfptr;
    v10 = 0i64;
    pSubTargetingLocation = 0i64;
    v11 = (v8 != 0 ? 2 : 0) | !v7;
    if ( pShootOriginSimObject )
    {
      v13 = pShootOriginSimObject->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v12 = pShootOriginSimObject->m_Components.p[20].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  pShootOriginSimObject,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  pShootOriginSimObject,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&pShootOriginSimObject->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v12 = v14;
      }
      else
      {
        v12 = pShootOriginSimObject->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v12 = 0i64;
    }
    if ( v9 && v12 )
    {
      v15 = *(_QWORD *)&v12[1].m_Flags;
      v16 = *(_QWORD *)&v12[1].m_TypeUID;
      pShootOriginSimObject = *(UFG::SimObjectGame **)(56i64
                                                     * *(unsigned __int8 *)(LODWORD(v4->m_Track[1].vfptr) + v15 + 8)
                                                     + v16
                                                     + 40);
      v10 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v15 + 62) + v16 + 40);
    }
    v17 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
    if ( v17 )
    {
      v18 = v17->m_Flags;
      if ( (v18 >> 14) & 1 )
      {
        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::GunComponent::_TypeUID);
      }
      else if ( (v18 & 0x8000u) == 0 )
      {
        if ( (v18 >> 13) & 1 )
          v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::GunComponent::_TypeUID);
        else
          v19 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::GunComponent::_TypeUID);
      }
      v20 = (UFG::GunComponent *)v19;
      if ( v19 )
      {
        v21 = v3->mSimObject.m_pPointer;
        if ( v21 )
        {
          v22 = v21->m_Flags;
          if ( !((v22 >> 14) & 1) && (v22 & 0x8000u) == 0 )
          {
            if ( (v22 >> 13) & 1 )
            {
              v23 = (UFG::InventoryItemComponent *)v21->m_Components.p[11].m_pComponent;
            }
            else
            {
              v7 = ((v22 >> 12) & 1) == 0;
              v24 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
              v25 = v7 ? UFG::SimObject::GetComponentOfType(
                           (UFG::SimObject *)&v24->vfptr,
                           UFG::InventoryItemComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v24,
                                                                      UFG::InventoryItemComponent::_TypeUID);
              v23 = (UFG::InventoryItemComponent *)v25;
            }
            if ( v23 )
            {
              v10 = (UFG::SimObjectGame *)UFG::InventoryItemComponent::GetOwnerSimObject(v23);
              if ( !v10 )
                goto LABEL_75;
              v26 = v23->m_pOwnerInventoryComponent.m_pPointer;
              v27 = v26 && BYTE1(v26[14].m_pSimObject);
              if ( UFG::IsAnyLocalPlayer((UFG::SimObject *)&v10->vfptr) && v27 )
                v11 &= 0xFFFFFFFE;
              v28 = v10->m_Flags;
              if ( (v28 >> 14) & 1 )
              {
                v29 = v10->m_Components.p[15].m_pComponent;
              }
              else if ( (v28 & 0x8000u) == 0 )
              {
                if ( (v28 >> 13) & 1 )
                {
                  v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HitReactionComponent::_TypeUID);
                }
                else if ( (v28 >> 12) & 1 )
                {
                  v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HitReactionComponent::_TypeUID);
                }
                else
                {
                  v29 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v10->vfptr,
                          UFG::HitReactionComponent::_TypeUID);
                }
              }
              else
              {
                v29 = v10->m_Components.p[15].m_pComponent;
              }
              if ( v29 )
                v29[1].m_TypeUID = 0;
              if ( BYTE2(v4->m_Track[1].m_TrackClassNameUID) )
              {
                if ( v12 )
                {
                  v30 = ((__int64 (__fastcall *)(UFG::SimComponent *))v12->vfptr[19].__vecDelDtor)(v12);
                  if ( v30 )
                    pSubTargetingLocation = *(UFG::SubTargetingLocation **)(v30 + 2736);
                }
                v31 = v10->m_Flags;
                if ( (v31 >> 14) & 1 )
                {
                  v6 = (UFG::AimingBaseComponent *)v10->m_Components.p[47].m_pComponent;
                }
                else
                {
                  if ( (v31 & 0x8000u) == 0 )
                  {
                    if ( (v31 >> 13) & 1 )
                    {
                      v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::AimingBaseComponent::_TypeUID);
                    }
                    else if ( (v31 >> 12) & 1 )
                    {
                      v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::AimingBaseComponent::_TypeUID);
                    }
                    else
                    {
                      v32 = UFG::SimObject::GetComponentOfType(
                              (UFG::SimObject *)&v10->vfptr,
                              UFG::AimingBaseComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::AimingBaseComponent::_TypeUID);
                  }
                  v6 = (UFG::AimingBaseComponent *)v32;
                }
              }
            }
          }
        }
        if ( v10 )
        {
          v33 = v4->m_Track;
          v34 = (_QWORD)v33[1].mResourceOwner & 0xFFFFFFFFFFFFFFFEui64;
          v35 = (char *)&v33[1].mResourceOwner + v34;
          if ( !v34 )
            v35 = BinString::sEmptyString;
          originBoneId = UFG::qSymbolUC::create_from_string(&result, v35);
          UFG::GunComponent::Shoot(
            v20,
            (UFG::SimObject *)&v10->vfptr,
            v6,
            v11,
            pSubTargetingLocation,
            (UFG::SimObject *)&pShootOriginSimObject->vfptr,
            originBoneId);
          return;
        }
LABEL_75:
        UFG::GunComponent::Shoot(v20, v11);
        return;
      }
    }
  }
}

// File Line: 2786
// RVA: 0x2EA8E0
void __fastcall CharacterSetVisualDamageTask::Begin(CharacterSetVisualDamageTask *this, ActionContext *pContext)
{
  CharacterSetVisualDamageTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterAnimationComponent *v5; // rax
  UFG::CharacterAnimationComponent *v6; // rdi
  ITrack *v7; // rax
  unsigned int v8; // ebx
  float v9; // xmm6_4

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
      else
        v5 = (UFG::CharacterAnimationComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v3->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    v6 = v5;
    if ( v5 )
    {
      v7 = v2->m_Track;
      v8 = 0;
      v9 = *(float *)&v7[1].vfptr;
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
  ReloadGunTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::GunComponent *v5; // rax
  ITrack *v6; // rcx
  int v7; // edx

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !((v3->m_Flags >> 10) & 1) && v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
      else
        v5 = (UFG::GunComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v3,
                                                      UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v3->vfptr,
                                                                                       UFG::GunComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = v2->m_Track;
      v7 = -1;
      if ( LOBYTE(v6[1].vfptr) )
        v7 = HIDWORD(v6[1].vfptr);
      UFG::GunComponent::Reload(v5, v7);
    }
  }
}

// File Line: 2838
// RVA: 0x2F0060
void __fastcall MissionFailTriggerTask::Begin(MissionFailTriggerTask *this, ActionContext *pContext)
{
  ITrack *v2; // rax
  ActionContext *v3; // rbx
  MissionFailTriggerTask *v4; // rdi
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // r8
  UFG::SimComponent *v7; // r8
  UFG::SimComponent *v8; // rax
  __int64 v9; // rdi
  UFG::CopSystem *v10; // rax

  v2 = this->m_Track;
  this->m_pContext = pContext;
  v3 = pContext;
  v4 = this;
  if ( !HIDWORD(v2[1].vfptr) )
  {
    v5 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v5->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v5->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v7 = v8;
      }
      else
      {
        v7 = v5->m_Components.p[20].m_pComponent;
      }
      if ( v7 )
      {
        v9 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LODWORD(v4->m_Track[1].vfptr) + *(_QWORD *)&v7[1].m_Flags + 8i64)
                       + *(_QWORD *)&v7[1].m_TypeUID
                       + 40);
        if ( v9 )
        {
          v10 = UFG::CopSystem::Instance();
          ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, __int64))v10->vfptr[94].__vecDelDtor)(
            v10,
            v3->mSimObject.m_pPointer,
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rax
  UFG::AimingPlayerComponent *v6; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AimingBaseComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
      }
      v4 = v5;
    }
    if ( v4 )
    {
      v6 = (UFG::AimingPlayerComponent *)((__int64 (*)(void))v4->vfptr[16].__vecDelDtor)();
      if ( v6 )
        UFG::AimingPlayerComponent::ResetFreeAimIntention(v6);
    }
  }
}

// File Line: 2878
// RVA: 0x2DD8B0
void __fastcall AimingSoftLockTask::AimingSoftLockTask(AimingSoftLockTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<AimingSoftLockTask,AimingSoftLockList> *v2; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AimingSoftLockTrack>::`vftable';
  v2 = (UFG::qNode<AimingSoftLockTask,AimingSoftLockList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&AimingSoftLockTask::`vftable';
}

// File Line: 2888
// RVA: 0x2E88A0
void __fastcall AimingSoftLockTask::Begin(AimingSoftLockTask *this, ActionContext *pActionContext)
{
  AimingSoftLockTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::AimingPlayerComponent *v6; // rax

  v2 = this;
  this->m_pActionContext = pActionContext;
  v3 = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = (UFG::SimObjectGame *)v3->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AimingBaseComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
      }
      v3 = (UFG::SimObjectGame *)v5;
    }
  }
  v6 = (UFG::AimingPlayerComponent *)((__int64 (*)(void))v3->vfptr[16].__vecDelDtor)();
  if ( v6 )
    UFG::AimingPlayerComponent::AddAimingSoftLockTask(v6, v2);
}

// File Line: 2911
// RVA: 0x2DD820
void __fastcall AimingSoftLockDisableTask::AimingSoftLockDisableTask(AimingSoftLockDisableTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList> *v2; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AimingSoftLockDisableTrack>::`vftable';
  v2 = (UFG::qNode<AimingSoftLockDisableTask,AimingSoftLockDisableList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&AimingSoftLockDisableTask::`vftable';
}

// File Line: 2921
// RVA: 0x2E8800
void __fastcall AimingSoftLockDisableTask::Begin(AimingSoftLockDisableTask *this, ActionContext *pActionContext)
{
  AimingSoftLockDisableTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AimingBaseComponent *v5; // rax

  v2 = this;
  this->m_pActionContext = pActionContext;
  v3 = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::AimingBaseComponent *)v3->m_Components.p[47].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::AimingBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::AimingBaseComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( v5 )
      UFG::AimingBaseComponent::AddAimingSoftLockDisableTask(v5, v2);
  }
}

// File Line: 2943
// RVA: 0x2DD750
void __fastcall AimingFreeAimConeClampTask::AimingFreeAimConeClampTask(AimingFreeAimConeClampTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> *v2; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AimingFreeAimConeClampTrack>::`vftable';
  v2 = (UFG::qNode<AimingFreeAimConeClampTask,AimingFreeAimConeClampList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&AimingFreeAimConeClampTask::`vftable';
}

// File Line: 2953
// RVA: 0x2E86B0
void __fastcall AimingFreeAimConeClampTask::Begin(AimingFreeAimConeClampTask *this, ActionContext *pActionContext)
{
  AimingFreeAimConeClampTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::AimingPlayerComponent *v6; // rax

  v2 = this;
  this->m_pActionContext = pActionContext;
  v3 = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = (UFG::SimObjectGame *)v3->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AimingBaseComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
      }
      v3 = (UFG::SimObjectGame *)v5;
    }
  }
  v6 = (UFG::AimingPlayerComponent *)((__int64 (*)(void))v3->vfptr[16].__vecDelDtor)();
  if ( v6 )
    UFG::AimingPlayerComponent::AddAimingFreeAimConeClampTask(v6, v2);
}

// File Line: 2976
// RVA: 0x2E0390
void __fastcall PowerManagementSuspendPermanentlyTask::PowerManagementSuspendPermanentlyTask(PowerManagementSuspendPermanentlyTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<PowerManagementSuspendPermanentlyTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&PowerManagementSuspendPermanentlyTask::`vftable';
}

// File Line: 2986
// RVA: 0x2F2190
void __fastcall PowerManagementSuspendPermanentlyTask::Begin(PowerManagementSuspendPermanentlyTask *this, ActionContext *pActionContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::PowerManagementComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v2,
                                              UFG::PowerManagementComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v2,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v2,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v2->vfptr,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v2,
                                              UFG::PowerManagementComponent::_TypeUID);
    }
    if ( v4 )
      UFG::PowerManagementComponent::PermanentlySuspend(v4);
  }
}

// File Line: 3000
// RVA: 0x2F0560
void __fastcall MotionIntentionHoldTask::Begin(MotionIntentionHoldTask *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AICharacterControllerBaseComponent *v4; // rax

  v2 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
    }
    if ( v4 )
      UFG::AICharacterControllerBaseComponent::HoldCurrentMotionIntention(v4);
  }
}

// File Line: 3013
// RVA: 0x2E8B30
void __fastcall AttachmentTransferTask::Begin(AttachmentTransferTask *this, ActionContext *pContext)
{
  AttachmentTransferTask *v2; // rbp
  UFG::SimObjectProp *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterAnimationComponent *v5; // rax
  Creature *v6; // rbx
  int v7; // edi
  int v8; // esi

  v2 = this;
  v3 = (UFG::SimObjectProp *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterAnimationComponent::_TypeUID)) : (v5 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::CharacterAnimationComponent::_TypeUID))) : (v5 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v3)),
        v5) )
  {
    v6 = v5->mCreature;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    v7 = -1;
    if ( v6->mPose.mRigHandle.mData )
      v8 = Skeleton::GetBoneID(v6->mPose.mRigHandle.mUFGSkeleton, (const unsigned int)v2->m_Track[1].vfptr);
    else
      v8 = -1;
    if ( v6->mPose.mRigHandle.mData )
      v7 = Skeleton::GetBoneID(v6->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v2->m_Track[1].vfptr));
    if ( v8 >= 0 && v7 >= 0 )
      Creature::TransferAttachment(v6, v8, v7, (UFG::qSymbolUC *)&v2->m_Track[1].mResourceOwner);
  }
}

// File Line: 3038
// RVA: 0x2F1F10
void __fastcall PlaybackSpeedModifierEnabledTask::Begin(PlaybackSpeedModifierEnabledTask *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CharacterAnimationComponent *v4; // rax

  this->mContext = pContext;
  v2 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v2);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v2->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v2->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
    }
    if ( v4 )
      v4->mCreature->mPlaybackSpeedEnabled = 1;
  }
}

// File Line: 3050
// RVA: 0x2FF9E0
void __fastcall PlaybackSpeedModifierEnabledTask::End(PlaybackSpeedModifierEnabledTask *this)
{
  UFG::SimObjectCVBase *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::CharacterAnimationComponent *v3; // rax

  v1 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v1);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v1);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v1->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v1->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v1);
    }
    if ( v3 )
      v3->mCreature->mPlaybackSpeedEnabled = 0;
  }
}

// File Line: 3063
// RVA: 0x2EF480
void __fastcall HealthSetPercentageTask::Begin(HealthSetPercentageTask *this, ActionContext *pContext)
{
  HealthSetPercentageTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbp
  unsigned __int16 v5; // r8
  UFG::HealthComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rdi
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // rsi
  UFG::CopSystem *v13; // rax
  char v14; // ST28_1
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  UFG::FaceMeterComponent *v17; // rcx
  bool v18; // zf
  UFG::SimObject *v19; // rax
  UFG::FaceEventParameters parameters; // [rsp+30h] [rbp-28h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::HealthComponent *)v3->m_Components.p[6].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HealthComponent::_TypeUID);
      v6 = (UFG::HealthComponent *)v7;
    }
    else
    {
      v6 = (UFG::HealthComponent *)v3->m_Components.p[6].m_pComponent;
    }
    if ( v6 )
    {
      if ( UFG::HealthComponent::SetHealth(
             v6,
             (signed int)(float)((float)(*(float *)&v2->m_Track[1].vfptr * 0.0099999998)
                               * (float)(signed int)v6->m_fMaxHealth),
             0i64) )
      {
        v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
        if ( v8 )
        {
          v9 = v8->m_Flags;
          if ( (v9 >> 14) & 1 )
          {
            v10 = v8->m_Components.p[15].m_pComponent;
          }
          else if ( (v9 & 0x8000u) == 0 )
          {
            if ( (v9 >> 13) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID);
            }
            else if ( (v9 >> 12) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID);
            }
            else
            {
              v11 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v8->vfptr,
                      UFG::HitReactionComponent::_TypeUID);
            }
            v10 = v11;
          }
          else
          {
            v10 = v8->m_Components.p[15].m_pComponent;
          }
          if ( v10 )
          {
            v12 = *(UFG::SimObjectGame **)&v10[3].m_TypeUID;
            v13 = UFG::CopSystem::Instance();
            v14 = 1;
            ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObjectGame *, UFG::SimObject *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **, UFG::HealthComponent *, char))v13->vfptr[95].__vecDelDtor)(
              v13,
              v12,
              v4->mSimObject.m_pPointer,
              &v10[2].m_BoundComponentHandles.mNode.mNext,
              v6,
              v14);
            if ( v12 )
            {
              v15 = v12->m_Flags;
              if ( (v15 >> 14) & 1 )
              {
                v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::FaceMeterComponent::_TypeUID);
              }
              else if ( (v15 & 0x8000u) == 0 )
              {
                if ( (v15 >> 13) & 1 )
                  v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::FaceMeterComponent::_TypeUID);
                else
                  v16 = (v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v12,
                                            UFG::FaceMeterComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v12->vfptr,
                                                                                   UFG::FaceMeterComponent::_TypeUID);
              }
              else
              {
                v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::FaceMeterComponent::_TypeUID);
              }
              v17 = (UFG::FaceMeterComponent *)v16;
              if ( v16 )
              {
                v18 = v6->m_bIsKnockedOut == 0;
                v19 = v4->mSimObject.m_pPointer;
                parameters.mpPropertySet = 0i64;
                parameters.mpSimObject = v19;
                parameters.mIsApply = 1;
                parameters.mType = 109;
                if ( v18 )
                  parameters.mType = 108;
                UFG::FaceMeterComponent::ApplyEvent(v17, &parameters);
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 3111
// RVA: 0x2EA9C0
void __fastcall CharacterStatModifyTask::Begin(CharacterStatModifyTask *this, ActionContext *pContext)
{
  CharacterStatModifyTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v2 = this;
  this->m_pContext = pContext;
  v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
    }
    if ( v5 )
      v5->m_CharacterStats[SLODWORD(v2->m_Track[1].vfptr)].m_fStat = *((float *)&v2->m_Track[1].vfptr + 1)
                                                                   + v5->m_CharacterStats[SLODWORD(v2->m_Track[1].vfptr)].m_fStat;
  }
}

// File Line: 3127
// RVA: 0x2FE5A0
void __fastcall CharacterStatModifyTask::End(CharacterStatModifyTask *this)
{
  CharacterStatModifyTask *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimObjectCharacterPropertiesComponent *v4; // rax

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)this->m_pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2);
    }
    if ( v4 )
      v4->m_CharacterStats[SLODWORD(v1->m_Track[1].vfptr)].m_fStat = v4->m_CharacterStats[SLODWORD(v1->m_Track[1].vfptr)].m_fStat
                                                                   - *((float *)&v1->m_Track[1].vfptr + 1);
  }
}

// File Line: 3144
// RVA: 0x2F0D60
void __fastcall ObjectReferenceTask::Begin(ObjectReferenceTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rdi
  ObjectReferenceTask *v3; // rsi
  UFG::qPropertySet *v4; // rbp
  unsigned int v5; // ebx
  UFG::SimObject *v6; // r8
  unsigned __int16 v7; // dx
  UFG::StreamedResourceComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  UFG::qSymbol priority; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *v11; // [rsp+60h] [rbp+18h]

  v2 = pContext;
  v3 = this;
  v4 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&this->m_Track[1]);
  if ( v4 )
  {
    v5 = qSymbol_Critical.mUID;
    v6 = v2->mSimObject.m_pPointer;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::StreamedResourceComponent *)v6->m_Components.p[10].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::StreamedResourceComponent *)v6->m_Components.p[7].m_pComponent;
        }
        else
        {
          v9 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
          if ( (v7 >> 12) & 1 )
            v8 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v9,
                                                     UFG::StreamedResourceComponent::_TypeUID);
          else
            v8 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v9->vfptr,
                                                     UFG::StreamedResourceComponent::_TypeUID);
        }
      }
      else
      {
        v8 = (UFG::StreamedResourceComponent *)v6->m_Components.p[10].m_pComponent;
      }
      if ( v8 )
        v5 = UFG::StreamedResourceComponent::GetSpawnPriority(v8, 0i64)->mUID;
    }
    v11 = &priority;
    priority.mUID = v5;
    UFG::MeshResourceLoader::Init(&v3->mMeshLoader, v4, (UFG::qSymbol)&priority, 0);
    UFG::MeshResourceLoader::PopulateTrueCrowdInstanceFromPropertySet(&v3->mMeshLoader, 1);
    UFG::MeshResourceLoader::QueueLoad(&v3->mMeshLoader);
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
  SetOutOfFightTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rcx
  UFG::SimComponent *v7; // rax
  UFG::ObjectiveTracker *v8; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[5].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      v6 = v7;
    }
    else
    {
      v6 = v3->m_Components.p[5].m_pComponent;
    }
    if ( v6 )
    {
      LOBYTE(v6[32].m_BoundComponentHandles.mNode.mPrev) ^= (LOBYTE(v6[32].m_BoundComponentHandles.mNode.mPrev) ^ 32 * (LOBYTE(v2->m_Track[1].vfptr) != 0)) & 0x20;
      if ( LOBYTE(v2->m_Track[1].vfptr) )
      {
        UFG::SimObjectUtility::DetachHudSymbol(v4->mSimObject.m_pPointer);
        v8 = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
        if ( v8 )
          UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(v8, &v4->mSimObject.m_pPointer->m_Name, 0);
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  this->mContext = context;
  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v2->vfptr,
               UFG::SimObjectSignalMemoryComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    }
    if ( v4 )
      v4[1].m_TypeUID = 1056964608;
  }
}

// File Line: 3240
// RVA: 0x30A3D0
char __fastcall StruggleTask::Update(StruggleTask *this, float timeDelta)
{
  StruggleTask *v2; // rdi
  bool v3; // zf
  UFG::SimObjectGame *v4; // rcx
  bool v5; // si
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rbx
  UFG::SimObjectCVBase *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::AICharacterControllerBaseComponent *v11; // rax
  UFG::AICharacterControllerBaseComponent *v12; // rdx
  unsigned __int64 v13; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4

  v2 = this;
  v3 = BYTE4(this->m_Track[1].vfptr) == 0;
  v4 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  v5 = !v3;
  if ( v4 )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      else
        v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                v4,
                                UFG::SimObjectSignalMemoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v4->vfptr,
                                                                                   UFG::SimObjectSignalMemoryComponent::_TypeUID);
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    }
    v8 = v7;
    if ( v7 )
    {
      v9 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
      if ( v9
        && ((v10 = v9->m_Flags, !((v10 >> 14) & 1)) ? ((v10 & 0x8000u) == 0 ? (!((v10 >> 13) & 1) ? (!((v10 >> 12) & 1) ? (v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID)) : (v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v9->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v9->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v9))) : (v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v9)),
            (v12 = v11) != 0i64
         && (v13 = v11->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Action.m_EnumValue >> 6],
             _bittest64((const signed __int64 *)&v13, gActionRequest_Action.m_EnumValue & 0x3F))
         && !v12->m_Intention.mActionRequestChargeTimes[gActionRequest_Action.m_EnumValue]) )
      {
        v14 = sStruggleIncFact * *(float *)&v2->m_Track[1].vfptr;
        if ( !v5 )
        {
          *(float *)&v8[1].m_TypeUID = v14 + *(float *)&v8[1].m_TypeUID;
          goto LABEL_30;
        }
      }
      else
      {
        v14 = sStruggleDecFact * *(float *)&v2->m_Track[1].vfptr;
        if ( v5 )
        {
          *(float *)&v8[1].m_TypeUID = v14 + *(float *)&v8[1].m_TypeUID;
          goto LABEL_30;
        }
      }
      *(float *)&v8[1].m_TypeUID = *(float *)&v8[1].m_TypeUID - v14;
LABEL_30:
      v15 = *(float *)&v8[1].m_TypeUID;
      if ( v15 <= 0.0 )
      {
        v15 = 0.0;
      }
      else
      {
        v16 = *(float *)&FLOAT_1_0;
        if ( v15 >= 1.0 )
          goto LABEL_35;
      }
      v16 = v15;
LABEL_35:
      *(float *)&v8[1].m_TypeUID = v16;
      return 1;
    }
  }
  return 1;
}

// File Line: 3296
// RVA: 0x2F4C60
void __fastcall Struggle2Task::Begin(Struggle2Task *this, ActionContext *context)
{
  ITrack *v2; // rax
  float v3; // xmm0_4
  ITaskVtbl *v4; // rax

  v2 = this->m_Track;
  this->mContext = context;
  this->mValueCurrentTime = -1.0;
  this->mValueLastTime = -1.0;
  v3 = (float)(*(float *)&v2[1].mResourceOwner * 0.5) + *((float *)&v2[1].vfptr + 1);
  v4 = this->vfptr;
  this->mCurrentStruggle = v3;
  ((void (*)(void))v4->Update)();
}

// File Line: 3315
// RVA: 0x30A190
char __fastcall Struggle2Task::Update(Struggle2Task *this, float timeDelta)
{
  Struggle2Task *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  float v4; // xmm6_4
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::AICharacterControllerBaseComponent *v10; // rax
  UFG::AICharacterControllerBaseComponent *v11; // rdx
  ITrack *v12; // r9
  unsigned __int64 v13; // rax
  float v14; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm1_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  v4 = timeDelta;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::SimObjectSignalMemoryComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID);
    }
    v7 = v6;
    if ( !v6 )
      return 1;
    v8 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
    if ( !v8 )
      return 1;
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v10 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v8->vfptr,
                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
      else
        v10 = (UFG::AICharacterControllerBaseComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v8->vfptr,
                                                                             UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
    }
    else
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
    }
    v11 = v10;
    if ( !v10 )
      return 1;
    v12 = v2->m_Track;
    v13 = v10->m_Intention.mActionRequests.mBits[(signed __int64)SLOWORD(v12[1].vfptr) >> 6];
    if ( !_bittest64((const signed __int64 *)&v13, (_QWORD)v12[1].vfptr & 0x3F)
      || v11->m_Intention.mActionRequestChargeTimes[SLOWORD(v12[1].vfptr)] )
    {
      v15 = v2->mValueCurrentTime;
      if ( v15 >= 0.0 )
        v2->mValueCurrentTime = v15 + timeDelta;
    }
    else
    {
      v14 = v2->mValueCurrentTime;
      v2->mValueCurrentTime = timeDelta;
      v2->mValueLastTime = v14;
    }
    v16 = v2->mValueCurrentTime;
    if ( v16 > 0.0 )
    {
      v17 = v2->mValueLastTime;
      if ( v17 > 0.0 )
      {
        v2->mCurrentStruggle = (float)(v17 + v16) * 0.5;
LABEL_34:
        v18 = v2->mCurrentStruggle;
        if ( v18 <= 0.0
          || ((v19 = *(float *)&v12[1].mResourceOwner,
               v20 = *((float *)&v12[1].vfptr + 1),
               v21 = *(float *)&FLOAT_1_0,
               v19 <= 0.0) ? (v22 = v20 / v18) : (v22 = (float)((float)(v19 + v20) * (float)(1.0 / v19))
                                                      - (float)((float)(1.0 / v19) * v18)),
              v22 <= 0.0) )
        {
          v22 = 0.0;
        }
        else if ( v22 >= 1.0 )
        {
          goto LABEL_43;
        }
        v21 = v22;
LABEL_43:
        *(float *)&v7[1].m_TypeUID = (float)(v21 - 0.5) * 2.0;
        return 1;
      }
      if ( v16 > 0.0 )
      {
        v2->mCurrentStruggle = v16;
        goto LABEL_34;
      }
    }
    v2->mCurrentStruggle = v4 + v2->mCurrentStruggle;
    goto LABEL_34;
  }
  return 1;
}

// File Line: 3404
// RVA: 0x2DD6B0
void __fastcall ActorStateCounterTask::ActorStateCounterTask(ActorStateCounterTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<ActorStateCounterTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&ActorStateCounterTask::`vftable';
  this->m_pActionContext = 0i64;
}

// File Line: 3414
// RVA: 0x2E8080
void __fastcall ActorStateCounterTask::Begin(ActorStateCounterTask *this, ActionContext *action_context)
{
  ITrack *v2; // rax

  v2 = this->m_Track;
  this->m_pActionContext = action_context;
  UFG::AudioGameState::sm_counters[LOBYTE(v2[1].vfptr)] = UFG::AudioGameState::sm_counters[LOBYTE(v2[1].vfptr)] + 1.0;
}

// File Line: 3426
// RVA: 0x2FDDE0
void __fastcall ActorStateCounterTask::End(ActorStateCounterTask *this)
{
  __int64 v1; // rax

  v1 = LOBYTE(this->m_Track[1].vfptr);
  UFG::AudioGameState::sm_counters[v1] = UFG::AudioGameState::sm_counters[v1] - 1.0;
}

// File Line: 3436
// RVA: 0x2DF560
void __fastcall GameStatEventTask::GameStatEventTask(GameStatEventTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<GameStatEventTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&GameStatEventTask::`vftable';
}

// File Line: 3444
// RVA: 0x2EE3B0
void __fastcall GameStatEventTask::Begin(GameStatEventTask *this, ActionContext *action_context)
{
  ActionContext *v2; // rbx
  ITrack *v3; // rdx
  int v4; // edi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // r9
  UFG::SimObject *v7; // r8
  const char *v8; // rdx
  unsigned int v9; // ecx
  UFG::allocator::free_link *v10; // rax

  v2 = action_context;
  v3 = this->m_Track;
  if ( !BYTE4(v3[1].vfptr) || LocalPlayer == (UFG::SimObjectCharacter *)v2->mSimObject.m_pPointer )
  {
    v4 = (int)v3[1].vfptr;
    v5 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
    v6 = v5;
    if ( v5 )
    {
      v7 = v2->mSimObject.m_pPointer;
      v8 = UFG::gGameStatEventChannel.mName;
      v9 = UFG::gGameStatEventChannel.mUID;
      v10 = v5 + 1;
      v10->mNext = v10;
      v10[1].mNext = v10;
      v6->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable';
      LODWORD(v6[3].mNext) = v9;
      v6[4].mNext = (UFG::allocator::free_link *)v8;
      v6->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable';
      LODWORD(v6[7].mNext) = v4;
      v6[8].mNext = (UFG::allocator::free_link *)v7;
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
  float v2; // xmm7_4
  UFG::SimObject *v4; // rcx
  UFG::TransformNodeComponent *v5; // rbx
  __m128 v6; // xmm1
  UFG::GameStatTracker *v7; // rax

  v2 = timestep;
  if ( LOBYTE(this->m_Track[1].vfptr)
    && LocalPlayer != (UFG::SimObjectCharacter *)this->m_pActionContext->mSimObject.m_pPointer )
  {
    return 0;
  }
  v4 = this->m_pActionContext->mSimObject.m_pPointer;
  if ( v4 )
    v5 = v4->m_pTransformNodeComponent;
  else
    v5 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v6 = (__m128)LODWORD(v5->mWorldVelocity.y);
  v6.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5->mWorldVelocity.x * v5->mWorldVelocity.x);
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplyDelta(v7, TotalDistanceWalked, (float)(COERCE_FLOAT(_mm_sqrt_ps(v6)) * v2) * 0.001);
  return 1;
}

// File Line: 3481
// RVA: 0x2EE460
void __fastcall GameStatSpecialMoveTask::Begin(GameStatSpecialMoveTask *this, ActionContext *action_context)
{
  ActionContext *v2; // rsi
  ActionNodePlayable *v3; // rcx
  __int64 v4; // rax
  UFG::OSuiteLeaderboardManager *v5; // rax
  UFG::OSuiteLeaderboardData *v6; // rax
  UFG::SimObjectGame *v7; // rbx
  unsigned __int16 v8; // cx
  UFG::HealthComponent *v9; // rdi
  UFG::SimComponent *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // r9
  UFG::SimObject *v13; // r8
  const char *v14; // rdx
  unsigned int v15; // ecx
  UFG::allocator::free_link *v16; // rax
  UFG::CopSystem *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // r9
  UFG::SimObject *v20; // r8
  const char *v21; // rdx
  unsigned int v22; // ecx
  UFG::allocator::free_link *v23; // rax
  UFG::CopSystem *v24; // rax
  UFG::CopSystem *v25; // rax
  UFG::qSymbol path; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *pIsCop; // [rsp+60h] [rbp+18h]
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+20h]

  v2 = action_context;
  if ( !LOBYTE(this->m_Track[1].vfptr)
    || LocalPlayer == (UFG::SimObjectCharacter *)action_context->mSimObject.m_pPointer )
  {
    v3 = action_context->mActionController->m_currentNode;
    if ( v3 )
    {
      v4 = ((__int64 (__cdecl *)(ActionNodePlayable *))v3->vfptr[1].SetResourceOwner)(v3);
      if ( v4 )
      {
        if ( (UFG::SimObjectCharacter *)v2->mSimObject.m_pPointer != LocalPlayer )
        {
          UFG::qSymbol::qSymbol(&result, *(_DWORD *)(v4 + 40));
          pIsCop = &path;
          path.mUID = result.mUID;
          UFG::GameStatAction::Player::RecordSpecialMove((UFG::qSymbol)&path);
          v5 = UFG::OSuiteLeaderboardManager::Instance();
          v6 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v5, "StatAwardsEnvironmentalist");
          UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v6, 1);
          v7 = (UFG::SimObjectGame *)UFG::getTarget((UFG::SimObject *)&LocalPlayer->vfptr, eTARGET_TYPE_LAST_GRAPPLE);
          if ( v7
            || (v7 = (UFG::SimObjectGame *)UFG::getTarget((UFG::SimObject *)&LocalPlayer->vfptr, eTARGET_TYPE_GRAPPLE)) != 0i64 )
          {
            v8 = v7->m_Flags;
            if ( (v8 >> 14) & 1 )
            {
              v9 = (UFG::HealthComponent *)v7->m_Components.p[6].m_pComponent;
            }
            else if ( (v8 & 0x8000u) == 0 )
            {
              if ( (v8 >> 13) & 1 )
              {
                v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HealthComponent::_TypeUID);
              }
              else if ( (v8 >> 12) & 1 )
              {
                v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HealthComponent::_TypeUID);
              }
              else
              {
                v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::HealthComponent::_TypeUID);
              }
              v9 = (UFG::HealthComponent *)v10;
            }
            else
            {
              v9 = (UFG::HealthComponent *)v7->m_Components.p[6].m_pComponent;
            }
            LOBYTE(pIsCop) = 0;
            LOBYTE(path.mUID) = 0;
            UFG::GameStatAction::MissionScoring::DeduceFaction(
              (UFG::SimObject *)&v7->vfptr,
              (bool *)&pIsCop,
              (bool *)&path);
            if ( LOBYTE(path.mUID) )
            {
              if ( v9 )
              {
                if ( v9->m_bIsKnockedOut || UFG::HealthComponent::GetIsKilled(v9) )
                {
                  v18 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
                  v19 = v18;
                  if ( v18 )
                  {
                    v20 = v2->mSimObject.m_pPointer;
                    v21 = UFG::gGameStatEventChannel.mName;
                    v22 = UFG::gGameStatEventChannel.mUID;
                    v23 = v18 + 1;
                    v23->mNext = v23;
                    v23[1].mNext = v23;
                    v19->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable';
                    LODWORD(v19[3].mNext) = v22;
                    v19[4].mNext = (UFG::allocator::free_link *)v21;
                    v19->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable';
                    LODWORD(v19[7].mNext) = 59;
                    v19[8].mNext = (UFG::allocator::free_link *)v20;
                  }
                  else
                  {
                    v19 = 0i64;
                  }
                  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v19);
                  UFG::GameStatAction::MissionScoring::LogCopEvent(COP_PEDESTRIAN_KILL, 0, &customWorldMapCaption);
                  v24 = UFG::CopSystem::Instance();
                  v24->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v24->vfptr, 6u);
                }
                else
                {
                  v11 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
                  v12 = v11;
                  if ( v11 )
                  {
                    v13 = v2->mSimObject.m_pPointer;
                    v14 = UFG::gGameStatEventChannel.mName;
                    v15 = UFG::gGameStatEventChannel.mUID;
                    v16 = v11 + 1;
                    v16->mNext = v16;
                    v16[1].mNext = v16;
                    v12->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable';
                    LODWORD(v12[3].mNext) = v15;
                    v12[4].mNext = (UFG::allocator::free_link *)v14;
                    v12->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable';
                    LODWORD(v12[7].mNext) = 28;
                    v12[8].mNext = (UFG::allocator::free_link *)v13;
                  }
                  else
                  {
                    v12 = 0i64;
                  }
                  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v12);
                  UFG::GameStatAction::MissionScoring::LogCopEvent(COP_PEDESTRIAN_HIT, 0, &customWorldMapCaption);
                  v17 = UFG::CopSystem::Instance();
                  v17->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v17->vfptr, 2u);
                }
              }
            }
            else if ( (_BYTE)pIsCop )
            {
              UFG::GameStatAction::MissionScoring::LogCopEvent(0, 0, &customWorldMapCaption);
              v25 = UFG::CopSystem::Instance();
              v25->vfptr[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v25->vfptr, 7u);
            }
            else
            {
              UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_KILL_ENVIRONMENTAL, 0, &customWorldMapCaption);
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
  ITaskVtbl *v2; // rax

  v2 = this->vfptr;
  this->m_pContext = pContext;
  ((void (*)(void))v2->Update)();
}

// File Line: 3573
// RVA: 0x3039C0
char __fastcall AccuracyOverrideTask::Update(AccuracyOverrideTask *this, float timeDelta)
{
  AccuracyOverrideTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  ITrack *v7; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
        else
          v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = v2->m_Track;
      if ( BYTE4(v7[1].vfptr) )
      {
        HIDWORD(v5[2].m_BoundComponentHandles.mNode.mPrev) = 1056964608;
        return 1;
      }
      HIDWORD(v5[2].m_BoundComponentHandles.mNode.mPrev) = v7[1].vfptr;
    }
  }
  return 1;
}

// File Line: 3593
// RVA: 0x2FDD50
void __fastcall AccuracyOverrideTask::End(AccuracyOverrideTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[47].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AimingBaseComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::AimingBaseComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( v3 )
      HIDWORD(v3[2].m_BoundComponentHandles.mNode.mPrev) = -1082130432;
  }
}

// File Line: 3606
// RVA: 0x2E7F50
void __fastcall AccuracyEnsureMissTask::Begin(AccuracyEnsureMissTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax

  this->m_pContext = pContext;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[47].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AimingBaseComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( v4 )
      LOBYTE(v4[2].m_BoundComponentHandles.mNode.mNext) = 1;
  }
}

// File Line: 3618
// RVA: 0x2FDCC0
void __fastcall AccuracyEnsureMissTask::End(AccuracyEnsureMissTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[47].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AimingBaseComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::AimingBaseComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( v3 )
      LOBYTE(v3[2].m_BoundComponentHandles.mNode.mNext) = 0;
  }
}

// File Line: 3631
// RVA: 0x2F3320
void __fastcall ReticleSizeOverrideTask::Begin(ReticleSizeOverrideTask *this, ActionContext *pContext)
{
  ReticleSizeOverrideTask *v2; // rbx
  UFG::SimObjectCharacter *v3; // rcx
  UFG::AimingPlayerComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::AimingPlayerComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AimingPlayerComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rdx

  v2 = this;
  v3 = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::AimingPlayerComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::AimingPlayerComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v3->vfptr,
                                             UFG::AimingPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AimingPlayerComponent::_TypeUID);
    }
    v4 = v6;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v2->m_AimingPlayerComponent;
  if ( v2->m_AimingPlayerComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->m_AimingPlayerComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->m_AimingPlayerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_AimingPlayerComponent.mPrev;
  }
  v2->m_AimingPlayerComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v2->m_AimingPlayerComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = v2->m_AimingPlayerComponent.m_pPointer;
  if ( v11 )
    LODWORD(v11[7].m_BoundComponentHandles.mNode.mPrev) = v2->m_Track[1].vfptr;
}

// File Line: 3640
// RVA: 0x300100
void __fastcall ReticleSizeOverrideTask::End(ReticleSizeOverrideTask *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->m_AimingPlayerComponent.m_pPointer;
  if ( v1 )
    LODWORD(v1[7].m_BoundComponentHandles.mNode.mPrev) = -1082130432;
}

// File Line: 3662
// RVA: 0x2FE4A0
void __fastcall CharacterStatModifyIntTask::End(CharacterStatModifyIntTask *this)
{
  CharacterStatModifyIntTask *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimObjectCharacterPropertiesComponent *v4; // rax
  signed int *v5; // rdx
  signed int v6; // er8
  int v7; // er8

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)this->m_pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2);
    }
    if ( v4 )
    {
      v5 = (signed int *)v1->m_Track;
      v6 = v5[15];
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( v7 )
        {
          if ( v7 == 1 )
            v4->m_CharacterStats[v5[14]].m_fStat = (float)v5[16];
        }
        else
        {
          v4->m_CharacterStats[v5[14]].m_fStat = (float)v5[16] * v4->m_CharacterStats[v5[14]].m_fStat;
        }
      }
      else
      {
        v4->m_CharacterStats[v5[14]].m_fStat = (float)v5[16] + v4->m_CharacterStats[v5[14]].m_fStat;
      }
    }
  }
}

// File Line: 3693
// RVA: 0x2F05E0
void __fastcall MotionIntentionSetRelativeToPlayerTask::Begin(MotionIntentionSetRelativeToPlayerTask *this, ActionContext *action_context)
{
  MotionIntentionSetRelativeToPlayerTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerComponent *v5; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::AICharacterControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v3->vfptr,
                                                      UFG::AICharacterControllerComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::AICharacterControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v3->vfptr,
                                                      UFG::AICharacterControllerComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AICharacterControllerComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v3->vfptr,
                                                      UFG::AICharacterControllerComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(v3);
    }
    if ( v5 )
      v5->m_PlayerRelativeMotionIntention = LOBYTE(v2->m_Track[1].vfptr) != 0;
  }
}

// File Line: 3704
// RVA: 0x2EE860
void __fastcall GunConsumeAmmoTask::Begin(GunConsumeAmmoTask *this, ActionContext *context)
{
  GunConsumeAmmoTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::GunComponent *v5; // rax
  UFG::GunComponent *v6; // rbx
  int v7; // eax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v3->vfptr,
                                    UFG::GunComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::GunComponent::_TypeUID);
    }
    v6 = v5;
    if ( v5 )
    {
      v7 = UFG::GunComponent::GetClipAmmo(v5);
      UFG::GunComponent::SetClipAmmo(v6, v7 - LODWORD(v2->m_Track[1].vfptr));
    }
  }
}

// File Line: 3723
// RVA: 0x2F3900
void __fastcall SetStateFlagTask::Begin(SetStateFlagTask *this, ActionContext *context)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *v2; // rbx
  ActionContext *v3; // rsi
  SetStateFlagTask *v4; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rdx
  UFG::SimComponent *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimComponent *v14; // rdx

  v2 = &this->m_pSOCPC;
  v3 = context;
  v4 = this;
  if ( this->m_pSOCPC.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = this->m_pSOCPC.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    this->m_pSOCPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pSOCPC.mPrev;
  }
  this->m_pSOCPC.m_pPointer = 0i64;
  this->m_pContext = context;
  v7 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = v7->m_Components.p[3].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = v7->m_Components.p[4].m_pComponent;
      }
      else
      {
        v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::SimObjectPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::SimObjectPropertiesComponent::_TypeUID);
        v9 = v10;
      }
    }
    else
    {
      v9 = v7->m_Components.p[3].m_pComponent;
    }
    if ( v9 && LODWORD(v9[1].m_SafePointerList.mNode.mNext) == 1 )
    {
      if ( v2->m_pPointer )
      {
        v11 = v2->mPrev;
        v12 = v2->mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
      }
      v2->m_pPointer = v9;
      v13 = v9->m_SafePointerList.mNode.mPrev;
      v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
      v2->mPrev = v13;
      v2->mNext = &v9->m_SafePointerList.mNode;
      v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
      v14 = v4->m_pSOCPC.m_pPointer;
      if ( v14 )
      {
        if ( v3->mActionController )
          *((_BYTE *)&v14[2].m_BoundComponentHandles.mNode.mPrev + SLODWORD(v4->m_Track[1].vfptr) + 1) = 1;
      }
    }
  }
}

// File Line: 3739
// RVA: 0x300230
void __fastcall SetStateFlagTask::End(SetStateFlagTask *this)
{
  UFG::SimComponent *v1; // rdx

  v1 = this->m_pSOCPC.m_pPointer;
  if ( v1 )
    *((_BYTE *)&v1[2].m_BoundComponentHandles.mNode.mPrev + SLODWORD(this->m_Track[1].vfptr) + 1) = 0;
}

// File Line: 3776
// RVA: 0x30CE80
void __fastcall drawStickDValue(float *values, int valueCount, UFG::qColour *colour)
{
  UFG::qColour *v3; // rbp
  float *v4; // rdi
  __int64 v5; // rbx
  float v6; // xmm6_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  __int64 v9; // rsi
  float v10; // xmm9_4
  float v11; // xmm1_4
  Render::DebugDrawContext *v12; // rax
  UFG::qVector3 p1; // [rsp+40h] [rbp-68h]
  UFG::qVector3 p0; // [rsp+50h] [rbp-58h]

  v3 = colour;
  v4 = values;
  v5 = 0i64;
  v6 = sDrawDebugH * 0.5;
  v7 = sDrawDebugOrgX;
  v8 = sDrawDebugOrgY + (float)(sDrawDebugH * 0.5);
  v9 = valueCount - 1;
  v10 = sDrawDebugW * 0.0099999998;
  if ( valueCount - 1 > 0 )
  {
    do
    {
      p0.x = v7;
      p0.z = 0.0;
      p1.z = 0.0;
      v11 = (float)(v6 * v4[v5 + 1]) + v8;
      p0.y = (float)(v6 * v4[v5]) + v8;
      p1.y = v11;
      v7 = v10 + v7;
      p1.x = v7;
      v12 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawLine(v12, &p0, &p1, v3, 0i64, 0i64, 0);
      ++v5;
    }
    while ( v5 < v9 );
  }
}

// File Line: 3797
// RVA: 0x30CFC0
void drawStickValues(void)
{
  UFG::qColour v0; // [rsp+30h] [rbp-78h]
  UFG::qColour v1; // [rsp+40h] [rbp-68h]
  UFG::qColour v2; // [rsp+50h] [rbp-58h]
  UFG::qColour v3; // [rsp+60h] [rbp-48h]
  UFG::qColour v4; // [rsp+70h] [rbp-38h]
  UFG::qColour v5; // [rsp+80h] [rbp-28h]
  UFG::qColour v6; // [rsp+90h] [rbp-18h]

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
  UFG::qNode<ITask,ITask> *v1; // rax
  float v2; // xmm1_4
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerComponent> *v3; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::AimingBaseComponent> *v4; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedPlayerComponent> *v5; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<ReadControllerInputTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&ReadControllerInputTask::`vftable';
  v3 = &this->m_pAICharacterControllerComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pAICharacterControllerComponent.m_pPointer = 0i64;
  v4 = &this->m_pAimingBaseComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pAimingBaseComponent.m_pPointer = 0i64;
  v5 = &this->m_pTargetingSystemPedPlayerComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pTargetingSystemPedPlayerComponent.m_pPointer = 0i64;
  this->m_pContext = 0i64;
  v2 = UFG::qVector2::msZero.y;
  this->mLockedPadModified.x = UFG::qVector2::msZero.x;
  this->mLockedPadModified.y = v2;
}

// File Line: 3824
// RVA: 0x2E4C90
void __fastcall ReadControllerInputTask::~ReadControllerInputTask(ReadControllerInputTask *this)
{
  ReadControllerInputTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedPlayerComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AimingBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rdx
  UFG::qNode<ITask,ITask> *v18; // rcx
  UFG::qNode<ITask,ITask> *v19; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&ReadControllerInputTask::`vftable';
  v2 = &this->m_pTargetingSystemPedPlayerComponent;
  if ( this->m_pTargetingSystemPedPlayerComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->m_pAimingBaseComponent;
  if ( v1->m_pAimingBaseComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pAimingBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pAimingBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAimingBaseComponent.mPrev;
  }
  v1->m_pAimingBaseComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pAimingBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pAimingBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAimingBaseComponent.mPrev;
  v12 = &v1->m_pAICharacterControllerComponent;
  if ( v1->m_pAICharacterControllerComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pAICharacterControllerComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pAICharacterControllerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAICharacterControllerComponent.mPrev;
  }
  v1->m_pAICharacterControllerComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pAICharacterControllerComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pAICharacterControllerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAICharacterControllerComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v17 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

// File Line: 3829
// RVA: 0x2F2F30
void __fastcall ReadControllerInputTask::Begin(ReadControllerInputTask *this, ActionContext *context)
{
  ReadControllerInputTask *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  ActionContext *v5; // rdi
  UFG::AICharacterControllerComponent *v6; // r8
  unsigned __int16 v7; // dx
  UFG::AICharacterControllerComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectCVBase *v13; // rcx
  UFG::TargetingSystemPedPlayerComponent *v14; // r8
  unsigned __int16 v15; // dx
  UFG::TargetingSystemPedPlayerComponent *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedPlayerComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AimingBaseComponent> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax

  v2 = this;
  this->m_pContext = context;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = context;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(v3);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::AICharacterControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v3->vfptr,
                                                      UFG::AICharacterControllerComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::AICharacterControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v3->vfptr,
                                                      UFG::AICharacterControllerComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::AICharacterControllerComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v3->vfptr,
                                                      UFG::AICharacterControllerComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(v3);
    }
    v6 = v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = &v2->m_pAICharacterControllerComponent;
  if ( v2->m_pAICharacterControllerComponent.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pAICharacterControllerComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v2->m_pAICharacterControllerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAICharacterControllerComponent.mPrev;
  }
  v2->m_pAICharacterControllerComponent.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v2->m_pAICharacterControllerComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v13 = (UFG::SimObjectCVBase *)v5->mSimObject.m_pPointer;
  if ( v13 )
  {
    v15 = v13->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v16 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v13);
    }
    else if ( (v15 & 0x8000u) == 0 )
    {
      if ( (v15 >> 13) & 1 )
      {
        v16 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v13->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else if ( (v15 >> 12) & 1 )
      {
        v16 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v13->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else
      {
        v16 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v13->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v16 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v13);
    }
    v14 = v16;
  }
  else
  {
    v14 = 0i64;
  }
  v17 = &v2->m_pTargetingSystemPedPlayerComponent;
  if ( v2->m_pTargetingSystemPedPlayerComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pTargetingSystemPedPlayerComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v2->m_pTargetingSystemPedPlayerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemPedPlayerComponent.mPrev;
  }
  v2->m_pTargetingSystemPedPlayerComponent.m_pPointer = (UFG::SimComponent *)&v14->vfptr;
  if ( v14 )
  {
    v20 = v14->m_SafePointerList.mNode.mPrev;
    v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v17->mPrev = v20;
    v2->m_pTargetingSystemPedPlayerComponent.mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  }
  v21 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v21 )
  {
    v22 = v21->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v4 = v21->m_Components.p[47].m_pComponent;
    }
    else
    {
      if ( (v22 & 0x8000u) == 0 )
      {
        if ( (v22 >> 13) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AimingBaseComponent::_TypeUID);
        }
        else if ( (v22 >> 12) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v23 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v21->vfptr, UFG::AimingBaseComponent::_TypeUID);
        }
      }
      else
      {
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AimingBaseComponent::_TypeUID);
      }
      v4 = v23;
    }
  }
  v24 = &v2->m_pAimingBaseComponent;
  if ( v2->m_pAimingBaseComponent.m_pPointer )
  {
    v25 = v24->mPrev;
    v26 = v2->m_pAimingBaseComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v2->m_pAimingBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAimingBaseComponent.mPrev;
  }
  v2->m_pAimingBaseComponent.m_pPointer = v4;
  if ( v4 )
  {
    v27 = v4->m_SafePointerList.mNode.mPrev;
    v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v24->mPrev = v27;
    v2->m_pAimingBaseComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
  }
}

// File Line: 3837
// RVA: 0x307EC0
char __fastcall ReadControllerInputTask::Update(ReadControllerInputTask *this, float timeDelta)
{
  ActionContext *v2; // rax
  ReadControllerInputTask *v3; // r14
  float v4; // xmm12_4
  UFG::ActiveAIEntityComponent *v5; // r13
  Intention *v6; // r15
  UFG::AICharacterControllerComponent *v7; // rax
  __int64 v8; // rbx
  UFG::Controller *v9; // rax
  char v10; // r12
  UFG::InputActionData *v11; // rax
  float v12; // xmm0_4
  __int64 v13; // r8
  signed __int64 v14; // rdx
  float v15; // xmm1_4
  UFG::InputActionData *v16; // rax
  float v17; // xmm0_4
  __int64 v18; // r8
  signed __int64 v19; // rdx
  float v20; // xmm1_4
  UFG::InputActionData *v21; // rax
  UFG::InputActionDef *v22; // rdi
  __int64 v23; // r8
  signed __int64 v24; // rdx
  float v25; // xmm1_4
  UFG::InputActionData *v26; // rcx
  float v27; // xmm7_4
  UFG::InputActionData *v28; // rcx
  float v29; // xmm0_4
  UFG::InputActionData *v30; // rax
  float v31; // xmm8_4
  float v32; // xmm10_4
  float v33; // xmm10_4
  __int128 v34; // xmm11
  float v35; // xmm15_4
  float v36; // xmm7_4
  float v37; // xmm4_4
  __m128 v38; // xmm3
  float v39; // xmm2_4
  float v40; // xmm5_4
  float v41; // xmm1_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm5_4
  __m128 v45; // xmm1
  float v46; // xmm1_4
  __m128 v47; // xmm1
  int v48; // er8
  _DWORD *v49; // rcx
  int v50; // eax
  _DWORD *v51; // rdx
  float v52; // xmm2_4
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
  signed __int64 v65; // rdx
  float v66; // xmm2_4
  __int64 v67; // r8
  signed __int64 v68; // rdx
  float v69; // xmm1_4
  UFG::InputActionData *v70; // rax
  float v71; // xmm0_4
  __int64 v72; // r8
  signed __int64 v73; // rdx
  float v74; // xmm1_4
  UFG::InputActionData *v75; // rdx
  __int64 v76; // r9
  char v77; // cl
  float v78; // xmm0_4
  float v79; // xmm1_4
  __int64 v80; // r8
  float v81; // ST20_4
  signed __int64 v82; // rdx
  float v83; // xmm1_4
  UFG::InputActionData *v84; // rax
  float v85; // xmm0_4
  __int64 v86; // r8
  signed __int64 v87; // rdx
  float v88; // xmm1_4
  UFG::InputActionData *v89; // rax
  float v90; // xmm0_4
  __int64 v91; // r8
  signed __int64 v92; // rdx
  float v93; // xmm1_4
  UFG::InputActionData *v94; // rax
  UFG::SimObjectGame *v95; // rcx
  UFG::TargetingSystemBaseComponent *v96; // rax
  unsigned __int16 v97; // dx
  bool v98; // zf
  UFG::InputActionData *v99; // rax
  float v100; // xmm0_4
  __int64 v101; // rdx
  signed __int64 v102; // r8
  float v103; // xmm1_4
  UFG::SimObjectGame *v104; // rcx
  UFG::TargetingSystemBaseComponent *v105; // rax
  unsigned __int16 v106; // dx
  float v107; // xmm0_4
  __int64 v108; // r8
  signed __int64 v109; // rdx
  float v110; // xmm1_4
  UFG::InputActionData *v111; // rax
  float v112; // xmm0_4
  __int64 v113; // r9
  signed __int64 v114; // r8
  float v115; // xmm1_4
  UFG::InputActionData *v116; // rax
  float v117; // xmm0_4
  __int64 v118; // r9
  signed __int64 v119; // r8
  float v120; // xmm1_4
  UFG::InputActionData *v121; // rax
  float v122; // xmm0_4
  __int64 v123; // r9
  UFG::InputActionData *v124; // rax
  UFG::InputActionData *v125; // rax
  signed __int64 v126; // r8
  float v127; // xmm1_4
  UFG::InputActionData *v128; // rax
  float v129; // xmm0_4
  UFG::InputActionData *v130; // rax
  UFG::InputActionData *v131; // rax
  UFG::SimObjectGame *v132; // rcx
  UFG::TargetingSystemBaseComponent *v133; // rax
  unsigned __int16 v134; // dx
  UFG::InputActionData *v135; // rax
  float v136; // xmm1_4
  UFG::InputActionData *v137; // rax
  float v138; // xmm0_4
  signed __int64 v139; // r8
  float v140; // xmm1_4
  UFG::InputActionData *v141; // rax
  __int64 v142; // r8
  signed __int64 v143; // rdx
  float v144; // xmm1_4
  UFG::InputActionData *v145; // rax
  float v146; // xmm0_4
  __int64 v147; // r8
  signed __int64 v148; // rdx
  float v149; // xmm1_4
  UFG::InputActionData *v150; // rax
  UFG::InputActionData *v151; // rcx
  UFG::InputActionData *v152; // rcx
  float v153; // xmm0_4
  __int64 v154; // r8
  signed __int64 v155; // rdx
  float v156; // xmm1_4
  UFG::InputActionData *v157; // rax
  UFG::InputActionData *v158; // rax
  UFG::InputActionData *v159; // rax
  __int64 v160; // r8
  signed __int64 v161; // rdx
  float v162; // xmm1_4
  UFG::InputActionData *v163; // rax
  float v164; // xmm0_4
  __int64 v165; // r8
  signed __int64 v166; // rdx
  float v167; // xmm1_4
  UFG::InputActionData *v168; // rax
  float v169; // xmm0_4
  __int64 v170; // r8
  signed __int64 v171; // rdx
  float v172; // xmm1_4
  UFG::InputActionData *v173; // rdx
  __int64 v174; // r9
  char v175; // cl
  float v176; // xmm0_4
  float v177; // xmm1_4
  __int64 v178; // r8
  signed __int64 v179; // rdx
  float v180; // xmm1_4
  UFG::InputActionData *v181; // rax
  UFG::InputActionData *v182; // rax
  UFG::InputActionData *v183; // rax
  float v184; // xmm1_4
  UFG::InputActionData *v185; // rax
  float v186; // xmm0_4
  __int64 v187; // r8
  signed __int64 v188; // rdx
  float v189; // xmm1_4
  UFG::InputActionData *v190; // rax
  UFG::InputActionData *v191; // rax
  UFG::InputActionData *v192; // rax
  UFG::InputActionData *v193; // rax
  __int64 v194; // r8
  signed __int64 v195; // rdx
  float v196; // xmm1_4
  UFG::InputActionData *v197; // rax
  __int64 v198; // r8
  signed __int64 v199; // rdx
  float v200; // xmm1_4
  UFG::InputActionData *v201; // rax
  float v202; // xmm0_4
  __int64 v203; // r8
  signed __int64 v204; // rdx
  float v205; // xmm1_4
  UFG::InputActionData *v206; // rax
  UFG::InputActionData *v207; // rax
  __int64 v208; // r8
  signed __int64 v209; // rdx
  float v210; // xmm1_4
  UFG::InputActionData *v211; // rax
  UFG::InputActionData *v212; // rax
  __int64 v213; // r8
  signed __int64 v214; // rdx
  float v215; // xmm1_4
  UFG::InputActionData *v216; // rax
  __int64 v217; // r8
  signed __int64 v218; // rdx
  float v219; // xmm1_4
  UFG::InputActionData *v220; // rax
  float v221; // xmm0_4
  __int64 v222; // r8
  signed __int64 v223; // rdx
  float v224; // xmm1_4
  UFG::InputActionData *v225; // rax
  __int64 v226; // rdx
  float v227; // xmm0_4
  signed __int64 v228; // rsi
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
  UFG::BaseCameraComponent *v239; // rcx
  UFG::GameCameraComponent *v240; // rax
  UFG::GameCameraComponent *v241; // rdi
  signed __int64 v242; // rcx
  UFG::BaseCameraComponent *v243; // rcx
  int v244; // xmm9_4
  int v245; // xmm10_4
  int v246; // xmm8_4
  float v247; // xmm13_4
  float v248; // xmm14_4
  float v249; // xmm15_4
  float v250; // xmm11_4
  char v251; // di
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v252; // rax
  UFG::qVector3 *v253; // rax
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v254; // rax
  UFG::qVector3 *v255; // rax
  UFG::SimComponent *v256; // rax
  UFG::SimObject *v257; // rdi
  UFG::TransformNodeComponent *v258; // rdi
  int v259; // xmm4_4
  float v260; // xmm7_4
  int v261; // xmm6_4
  UFG::SimObject *v262; // rdi
  UFG::TransformNodeComponent *v263; // rdi
  float v264; // xmm3_4
  float v265; // xmm6_4
  float v266; // xmm1_4
  float v267; // xmm2_4
  float v268; // xmm8_4
  float v269; // xmm2_4
  float v270; // xmm8_4
  float v271; // xmm9_4
  UFG::SimObjectCVBase *v272; // rcx
  unsigned __int16 v273; // dx
  UFG::ActiveAIEntityComponent *v274; // rax
  char v275; // cl
  float v276; // xmm1_4
  float v277; // xmm2_4
  float v278; // xmm1_4
  float v279; // xmm2_4
  float v280; // xmm1_4
  float v281; // xmm6_4
  float v282; // xmm6_4
  float v283; // xmm2_4
  UFG::SimObjectCVBase *v284; // rcx
  unsigned __int16 v285; // dx
  UFG::CharacterAnimationComponent *v286; // rax
  UFG::CharacterAnimationComponent *v287; // rdi
  Creature *v288; // rcx
  int v289; // eax
  UFG::qVector3 *v290; // rax
  float v291; // xmm1_4
  float v292; // xmm2_4
  float v293; // xmm0_4
  UFG::SimComponent *v294; // rax
  UFG::SimObject *v295; // rdi
  UFG::TransformNodeComponent *v296; // rdi
  float v297; // xmm1_4
  float v298; // xmm2_4
  float v299; // xmm0_4
  float v300; // xmm1_4
  float v301; // xmm7_4
  float v302; // xmm2_4
  float v303; // xmm1_4
  float v304; // xmm0_4
  float v305; // xmm2_4
  UFG::SimObjectGame *v306; // rcx
  unsigned __int16 v307; // dx
  UFG::SimComponent *v308; // rax
  float v309; // xmm1_4
  float v310; // xmm0_4
  float v311; // xmm15_4
  UFG::InputActionData *v312; // rax
  UFG::AICharacterControllerComponent *v313; // rbx
  float v315; // [rsp+24h] [rbp-DCh]
  float v316; // [rsp+28h] [rbp-D8h]
  float v317; // [rsp+2Ch] [rbp-D4h]
  Intention other; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 result; // [rsp+380h] [rbp+280h]
  UFG::qMatrix44 dest; // [rsp+390h] [rbp+290h]
  float v321; // [rsp+4C0h] [rbp+3C0h]
  float fDeltaS; // [rsp+4C8h] [rbp+3C8h]
  float v323; // [rsp+4D0h] [rbp+3D0h]
  float v324; // [rsp+4D8h] [rbp+3D8h]

  fDeltaS = timeDelta;
  v2 = this->m_pContext;
  v3 = this;
  if ( v2 && (v2->mSimObject.m_pPointer->m_Flags >> 10) & 1 )
    return 1;
  v4 = 0.0;
  v323 = 0.0;
  v321 = 0.0;
  Intention::Intention(&other);
  v5 = 0i64;
  v6 = 0i64;
  Intention::Clear(&other);
  v7 = (UFG::AICharacterControllerComponent *)v3->m_pAICharacterControllerComponent.m_pPointer;
  LODWORD(v8) = 0;
  if ( v7 )
  {
    LODWORD(v8) = v7->m_ControllerID;
    v6 = &v7->m_Intention;
  }
  v9 = UFG::InputSystem::AcquireController(UFG::gInputSystem, v8);
  v10 = 0;
  if ( v9 )
  {
    v10 = 0;
    if ( v9->m_IsKeyboardController )
      v10 = 1;
  }
  v8 = (signed int)v8;
  v11 = UFG::ActionDef_UIAcceptPressed.mDataPerController[(signed int)v8];
  if ( v11 && v11->mActionTrue )
  {
    v12 = v11->mOnSeconds;
    v13 = gActionRequest_Accept.m_EnumValue;
    v14 = 1i64 << (gActionRequest_Accept.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Accept.m_EnumValue >> 6] |= v14;
    v15 = (float)(signed int)(float)(v12 * 60.0);
    if ( v15 >= 255.0 )
      v15 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v13] = (signed int)v15;
    other.mSignals |= v14;
  }
  v16 = UFG::ActionDef_UIBackPressed.mDataPerController[v8];
  if ( v16 && v16->mActionTrue )
  {
    v17 = v16->mOnSeconds;
    v18 = gActionRequest_Cancel.m_EnumValue;
    v19 = 1i64 << (gActionRequest_Cancel.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Cancel.m_EnumValue >> 6] |= v19;
    v20 = (float)(signed int)(float)(v17 * 60.0);
    if ( v20 >= 255.0 )
      v20 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v18] = (signed int)v20;
    other.mSignals |= v19;
  }
  v21 = UFG::ActionDef_VehicleRamReload.mDataPerController[v8];
  v22 = &UFG::ActionDef_MoveFwdBack;
  if ( v21 && v21->mActionTrue )
  {
    v23 = gActionRequest_VehicleRam.m_EnumValue;
    v24 = 1i64 << (gActionRequest_VehicleRam.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_VehicleRam.m_EnumValue >> 6] |= v24;
    v25 = (float)(signed int)0.0;
    if ( v25 >= 255.0 )
      v25 = FLOAT_255_0;
    v22 = &UFG::ActionDef_Steer;
    other.mActionRequestChargeTimes[v23] = (signed int)v25;
    other.mSignals |= v24;
  }
  v26 = v22->mDataPerController[v8];
  if ( v26 )
    v27 = UFG::InputActionData::GetAxisVelX(v26);
  else
    v27 = 0.0;
  v28 = v22->mDataPerController[v8];
  if ( v28 )
    v29 = UFG::InputActionData::GetAxisVelY(v28);
  else
    v29 = 0.0;
  v30 = v22->mDataPerController[v8];
  v31 = fsqrt((float)(v29 * v29) + (float)(v27 * v27));
  if ( v30 )
    v32 = v30->mAxisPositionY;
  else
    v32 = 0.0;
  LODWORD(v33) = LODWORD(v32) ^ _xmm[0];
  v316 = v33;
  if ( v30 )
    v34 = LODWORD(v30->mAxisPositionX);
  else
    v34 = 0i64;
  v35 = *(float *)&FLOAT_1_0;
  v324 = *(float *)&v34;
  v36 = 0.0;
  if ( v31 > sSettleVel )
  {
    v37 = v3->mLockedPadModified.x;
    v38 = (__m128)LODWORD(v3->mLockedPadModified.y);
    v36 = FLOAT_0_89999998;
    v39 = *(float *)&v34 - v37;
    v40 = v33 - v38.m128_f32[0];
    v41 = (float)(v40 * v40) + (float)(v39 * v39);
    if ( v41 == 0.0 )
      v42 = 0.0;
    else
      v42 = 1.0 / fsqrt(v41);
    v43 = v39 * v42;
    v44 = v40 * v42;
    v45 = (__m128)LODWORD(v3->mLockedPadModified.y);
    v45.m128_f32[0] = (float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v37 * v37);
    if ( v45.m128_f32[0] == 0.0 )
      v46 = 0.0;
    else
      v46 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v45));
    if ( (float)((float)((float)(v46 * v38.m128_f32[0]) * v44) + (float)((float)(v46 * v37) * v43)) < sStickDirChangeThreshold )
    {
      v47 = (__m128)v34;
      v47.m128_f32[0] = (float)(*(float *)&v34 * *(float *)&v34) + (float)(v33 * v33);
      v38.m128_f32[0] = (float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v37 * v37);
      if ( COERCE_FLOAT(_mm_sqrt_ps(v47)) < COERCE_FLOAT(_mm_sqrt_ps(v38)) )
        goto LABEL_47;
      v36 = FLOAT_0_60000002;
    }
    else
    {
      v36 = FLOAT_0_40000001;
    }
  }
  LODWORD(v3->mLockedPadModified.x) = v34;
  v3->mLockedPadModified.y = v33;
LABEL_47:
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
    while ( (signed __int64)v49 > (signed __int64)&unk_1423B61B4 );
    v51 = &unk_1423B61BC;
    do
    {
      *v51 = *(v51 - 1);
      --v51;
    }
    while ( (signed __int64)v51 > (signed __int64)gValues5 );
    gValues5[0] = v36;
  }
  v52 = v3->mLockedPadModified.y;
  v53 = v3->mLockedPadModified.x;
  v317 = v3->mLockedPadModified.y;
  v315 = v3->mLockedPadModified.x;
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
    while ( (signed __int64)v54 > (signed __int64)&unk_1423B59E4 );
    v56 = &unk_1423B59EC;
    do
    {
      *v56 = *(v56 - 1);
      --v56;
    }
    while ( (signed __int64)v56 > (signed __int64)gValues0 );
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
    while ( (signed __int64)v57 > (signed __int64)&unk_1423B5B74 );
    v59 = &unk_1423B5B7C;
    do
    {
      *v59 = *(v59 - 1);
      --v59;
    }
    while ( (signed __int64)v59 > (signed __int64)gValues1 );
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
    while ( (signed __int64)v60 > (signed __int64)&unk_1423B5D04 );
    v62 = &unk_1423B5D0C;
    do
    {
      *v62 = *(v62 - 1);
      --v62;
    }
    while ( (signed __int64)v62 > (signed __int64)gValues2 );
    LODWORD(gValues2[0]) = v34;
  }
  v63 = digitalMoveThreshold;
  if ( v52 <= digitalMoveThreshold )
  {
    if ( v52 >= COERCE_FLOAT(LODWORD(digitalMoveThreshold) ^ _xmm[0]) )
      goto LABEL_74;
    v64 = gActionRequest_MoveBackward.m_EnumValue;
  }
  else
  {
    v64 = gActionRequest_MoveForward.m_EnumValue;
  }
  v65 = 1i64 << (v64 & 0x3F);
  other.mActionRequests.mBits[(signed __int64)(signed int)v64 >> 6] |= v65;
  v66 = (float)(signed int)0.0;
  if ( v66 >= 255.0 )
    v66 = FLOAT_255_0;
  other.mActionRequestChargeTimes[v64] = (signed int)v66;
  other.mSignals |= v65;
LABEL_74:
  if ( v53 <= v63 )
  {
    if ( v53 >= COERCE_FLOAT(LODWORD(v63) ^ _xmm[0]) )
      goto LABEL_81;
    v67 = gActionRequest_MoveLeft.m_EnumValue;
  }
  else
  {
    v67 = gActionRequest_MoveRight.m_EnumValue;
  }
  v68 = 1i64 << (v67 & 0x3F);
  other.mActionRequests.mBits[(signed __int64)(signed int)v67 >> 6] |= v68;
  v69 = (float)(signed int)0.0;
  if ( v69 >= 255.0 )
    v69 = FLOAT_255_0;
  other.mActionRequestChargeTimes[v67] = (signed int)v69;
  other.mSignals |= v68;
LABEL_81:
  v70 = UFG::ActionDef_Jump.mDataPerController[v8];
  if ( v70 && v70->mActionTrue )
  {
    v71 = v70->mOnSeconds;
    v72 = gActionRequest_Jump.m_EnumValue;
    v73 = 1i64 << (gActionRequest_Jump.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Jump.m_EnumValue >> 6] |= v73;
    v74 = (float)(signed int)(float)(v71 * 60.0);
    if ( v74 >= 255.0 )
      v74 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v72] = (signed int)v74;
    other.mSignals |= v73;
  }
  v75 = UFG::ActionDef_Action.mDataPerController[v8];
  if ( v75 && v75->mActionTrue )
  {
    v76 = gActionRequest_Action.m_EnumValue;
    v77 = gActionRequest_Action.m_EnumValue & 0x3F;
    v78 = v75->mOnSeconds * 60.0;
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Action.m_EnumValue >> 6] |= 1i64 << (gActionRequest_Action.m_EnumValue & 0x3F);
    v79 = (float)(signed int)v78;
    if ( v79 >= 255.0 )
      v79 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v76] = (signed int)v79;
    other.mSignals |= 1i64 << v77;
    v80 = gActionRequest_POI_Use.m_EnumValue;
    v81 = v75->mOnSeconds * 60.0;
    v82 = 1i64 << (gActionRequest_POI_Use.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_POI_Use.m_EnumValue >> 6] |= v82;
    v83 = (float)(signed int)v81;
    if ( v83 >= 255.0 )
      v83 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v80] = (signed int)v83;
    other.mSignals |= v82;
  }
  v84 = UFG::ActionDef_Grab.mDataPerController[v8];
  if ( v84 && v84->mActionTrue )
  {
    v85 = v84->mOnSeconds;
    v86 = gActionRequest_Grab.m_EnumValue;
    v87 = 1i64 << (gActionRequest_Grab.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Grab.m_EnumValue >> 6] |= v87;
    v88 = (float)(signed int)(float)(v85 * 60.0);
    if ( v88 >= 255.0 )
      v88 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v86] = (signed int)v88;
    other.mSignals |= v87;
  }
  v89 = UFG::ActionDef_Weapon.mDataPerController[v8];
  if ( v89 && v89->mActionTrue )
  {
    v90 = v89->mOnSeconds;
    v91 = gActionRequest_Weapon.m_EnumValue;
    v92 = 1i64 << (gActionRequest_Weapon.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Weapon.m_EnumValue >> 6] |= v92;
    v93 = (float)(signed int)(float)(v90 * 60.0);
    if ( v93 >= 255.0 )
      v93 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v91] = (signed int)v93;
    other.mSignals |= v92;
  }
  v94 = UFG::ActionDef_MeleeAttack.mDataPerController[v8];
  if ( !v94 || !v94->mActionTrue )
  {
    v99 = UFG::ActionDef_Attack.mDataPerController[v8];
    if ( !v99 || !v99->mActionTrue )
      goto LABEL_145;
    if ( v10 != 1 )
      goto LABEL_141;
    v104 = (UFG::SimObjectGame *)v3->m_pContext->mSimObject.m_pPointer;
    if ( v104 )
    {
      v106 = v104->m_Flags;
      if ( (v106 >> 14) & 1 )
      {
        v105 = (UFG::TargetingSystemBaseComponent *)v104->m_Components.p[20].m_pComponent;
      }
      else if ( (v106 & 0x8000u) == 0 )
      {
        if ( (v106 >> 13) & 1 )
          v105 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v104,
                                                        UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v105 = (UFG::TargetingSystemBaseComponent *)((v106 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            v104,
                                                                            UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v104->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID));
      }
      else
      {
        v105 = (UFG::TargetingSystemBaseComponent *)v104->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v105 = 0i64;
    }
    if ( UFG::HasRangedWeaponEquippedWithAmmo(v105) )
    {
LABEL_145:
      LODWORD(v101) = gActionRequest_Fire.m_EnumValue;
      goto LABEL_146;
    }
    v99 = UFG::ActionDef_Attack.mDataPerController[v8];
LABEL_139:
    if ( !v99 )
    {
      v107 = 0.0;
LABEL_142:
      v108 = gActionRequest_Attack.m_EnumValue;
      v109 = 1i64 << (gActionRequest_Attack.m_EnumValue & 0x3F);
      other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Attack.m_EnumValue >> 6] |= v109;
      v110 = (float)(signed int)(float)(v107 * 60.0);
      if ( v110 >= 255.0 )
        v110 = FLOAT_255_0;
      other.mActionRequestChargeTimes[v108] = (signed int)v110;
      other.mSignals |= v109;
      goto LABEL_145;
    }
LABEL_141:
    v107 = v99->mOnSeconds;
    goto LABEL_142;
  }
  v95 = (UFG::SimObjectGame *)v3->m_pContext->mSimObject.m_pPointer;
  if ( v95 )
  {
    v97 = v95->m_Flags;
    if ( (v97 >> 14) & 1 )
    {
      v96 = (UFG::TargetingSystemBaseComponent *)v95->m_Components.p[20].m_pComponent;
    }
    else if ( (v97 & 0x8000u) == 0 )
    {
      if ( (v97 >> 13) & 1 )
      {
        v96 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v95,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v97 >> 12) & 1 )
      {
        v96 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v95,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v96 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v95->vfptr,
                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
      }
    }
    else
    {
      v96 = (UFG::TargetingSystemBaseComponent *)v95->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v96 = 0i64;
  }
  v98 = UFG::HasRangedWeapon(v96) == 0;
  v99 = UFG::ActionDef_MeleeAttack.mDataPerController[v8];
  if ( !v98 )
    goto LABEL_139;
  if ( v99 )
    v100 = v99->mOnSeconds;
  else
    v100 = 0.0;
  v101 = gActionRequest_Fire.m_EnumValue;
  v102 = 1i64 << (gActionRequest_Fire.m_EnumValue & 0x3F);
  other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Fire.m_EnumValue >> 6] |= v102;
  v103 = (float)(signed int)(float)(v100 * 60.0);
  if ( v103 >= 255.0 )
    v103 = FLOAT_255_0;
  other.mActionRequestChargeTimes[v101] = (signed int)v103;
  other.mSignals |= v102;
LABEL_146:
  v111 = UFG::ActionDef_Sprint.mDataPerController[v8];
  if ( v111 && v111->mActionTrue )
  {
    v112 = v111->mOnSeconds;
    v113 = gActionRequest_Sprint.m_EnumValue;
    v114 = 1i64 << (gActionRequest_Sprint.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Sprint.m_EnumValue >> 6] |= v114;
    v115 = (float)(signed int)(float)(v112 * 60.0);
    if ( v115 >= 255.0 )
      v115 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v113] = (signed int)v115;
    other.mSignals |= v114;
  }
  v116 = UFG::ActionDef_CoverToggle.mDataPerController[v8];
  if ( v116 && v116->mActionTrue )
  {
    v117 = v116->mOnSeconds;
    v118 = gActionRequest_CoverToggle.m_EnumValue;
    v119 = 1i64 << (gActionRequest_CoverToggle.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_CoverToggle.m_EnumValue >> 6] |= v119;
    v120 = (float)(signed int)(float)(v117 * 60.0);
    if ( v120 >= 255.0 )
      v120 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v118] = (signed int)v120;
    other.mSignals |= v119;
  }
  v121 = UFG::ActionDef_Steer.mDataPerController[v8];
  if ( v121 && v121->mActionTrue )
  {
    v122 = v121->mAxisPositionX;
    if ( v122 >= -0.5 )
    {
      if ( v122 <= 0.5 )
        goto LABEL_171;
      v123 = gActionRequest_SteerRight.m_EnumValue;
    }
    else
    {
      v123 = gActionRequest_SteerLeft.m_EnumValue;
    }
  }
  else
  {
    v124 = UFG::ActionDef_Left.mDataPerController[v8];
    if ( v124 && v124->mActionTrue )
    {
      v123 = gActionRequest_SteerLeft.m_EnumValue;
    }
    else
    {
      v125 = UFG::ActionDef_Right.mDataPerController[v8];
      if ( !v125 || (v123 = gActionRequest_SteerRight.m_EnumValue, !v125->mActionTrue) )
        v123 = gActionRequest_SteerNeutral.m_EnumValue;
    }
  }
  v126 = 1i64 << (v123 & 0x3F);
  v122 = 0.0;
  other.mActionRequests.mBits[(signed __int64)(signed int)v123 >> 6] |= v126;
  v127 = (float)(signed int)0.0;
  if ( v127 >= 255.0 )
    v127 = FLOAT_255_0;
  other.mActionRequestChargeTimes[v123] = (signed int)v127;
  other.mSignals |= v126;
LABEL_171:
  if ( UFG::TargetingSystemPedPlayerComponent::ms_eTargetCycleAndLocationTargetingModeEnum == 2 )
  {
    v128 = UFG::ActionDef_FireFull.mDataPerController[v8];
    if ( !v128 || !v128->mActionTrue )
      goto LABEL_203;
    v129 = v128->mOnSeconds;
  }
  else
  {
    v130 = UFG::ActionDef_Fire.mDataPerController[v8];
    if ( !v130 || !v130->mActionTrue )
    {
      v131 = UFG::ActionDef_VehicleFire.mDataPerController[v8];
      if ( !v131 || !v131->mActionTrue )
        goto LABEL_203;
    }
    if ( v10 )
    {
      v132 = (UFG::SimObjectGame *)v3->m_pContext->mSimObject.m_pPointer;
      if ( v132 )
      {
        v134 = v132->m_Flags;
        if ( (v134 >> 14) & 1 )
        {
          v133 = (UFG::TargetingSystemBaseComponent *)v132->m_Components.p[20].m_pComponent;
        }
        else if ( (v134 & 0x8000u) == 0 )
        {
          if ( (v134 >> 13) & 1 )
          {
            v133 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v132,
                                                          UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v134 >> 12) & 1 )
          {
            v133 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v132,
                                                          UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v133 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v132->vfptr,
                                                          UFG::TargetingSystemBaseComponent::_TypeUID);
          }
        }
        else
        {
          v133 = (UFG::TargetingSystemBaseComponent *)v132->m_Components.p[20].m_pComponent;
        }
      }
      else
      {
        v133 = 0i64;
      }
      if ( !UFG::HasRangedWeapon(v133) )
        goto LABEL_203;
      LODWORD(v101) = gActionRequest_Fire.m_EnumValue;
    }
    v135 = UFG::ActionDef_Fire.mDataPerController[v8];
    if ( v135 )
      v136 = v135->mOnSeconds;
    else
      v136 = 0.0;
    v137 = UFG::ActionDef_VehicleFire.mDataPerController[v8];
    if ( v137 )
      v138 = v137->mOnSeconds;
    else
      v138 = 0.0;
    v129 = v138 + v136;
  }
  v139 = 1i64 << (v101 & 0x3F);
  other.mActionRequests.mBits[(signed __int64)(signed int)v101 >> 6] |= v139;
  v122 = v129 * 60.0;
  v140 = (float)(signed int)v122;
  if ( v140 >= 255.0 )
    v140 = FLOAT_255_0;
  other.mActionRequestChargeTimes[(unsigned int)v101] = (signed int)v140;
  other.mSignals |= v139;
LABEL_203:
  v141 = UFG::ActionDef_FirePartial.mDataPerController[v8];
  if ( v141 && v141->mActionTrue )
  {
    v142 = gActionRequest_FirePartial.m_EnumValue;
    v122 = 0.0;
    v143 = 1i64 << (gActionRequest_FirePartial.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_FirePartial.m_EnumValue >> 6] |= v143;
    v144 = (float)(signed int)0.0;
    if ( v144 >= 255.0 )
      v144 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v142] = (signed int)v144;
    other.mSignals |= v143;
  }
  v145 = UFG::ActionDef_Reload.mDataPerController[v8];
  if ( v145 && v145->mActionTrue )
  {
    v146 = v145->mOnSeconds;
    v147 = gActionRequest_Reload.m_EnumValue;
    v148 = 1i64 << (gActionRequest_Reload.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Reload.m_EnumValue >> 6] |= v148;
    v122 = v146 * 60.0;
    v149 = (float)(signed int)v122;
    if ( v149 >= 255.0 )
      v149 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v147] = (signed int)v149;
    other.mSignals |= v148;
  }
  v150 = UFG::ActionDef_Inventory.mDataPerController[v8];
  if ( v150 )
  {
    if ( v150->mActionTrue )
    {
      v151 = UFG::ActionDef_PrevRadioStationHold.mDataPerController[v8];
      if ( !v151 || !v151->mActionTrue )
      {
        v152 = UFG::ActionDef_NextRadioStationHold.mDataPerController[v8];
        if ( !v152 || !v152->mActionTrue )
        {
          v153 = v150->mOnSeconds;
          v154 = gActionRequest_Inventory.m_EnumValue;
          v155 = 1i64 << (gActionRequest_Inventory.m_EnumValue & 0x3F);
          other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Inventory.m_EnumValue >> 6] |= v155;
          v122 = v153 * 60.0;
          v156 = (float)(signed int)v122;
          if ( v156 >= 255.0 )
            v156 = FLOAT_255_0;
          other.mActionRequestChargeTimes[v154] = (signed int)v156;
          other.mSignals |= v155;
        }
      }
    }
  }
  v157 = UFG::ActionDef_EquipUP.mDataPerController[v8];
  if ( v157 )
  {
    if ( v157->mActionTrue )
    {
      v158 = UFG::ActionDef_PrevRadioStationHold.mDataPerController[v8];
      if ( !v158 || !v158->mActionTrue )
      {
        v159 = UFG::ActionDef_NextRadioStationHold.mDataPerController[v8];
        if ( !v159 || !v159->mActionTrue )
        {
          v160 = gActionRequest_EquipUP.m_EnumValue;
          v122 = 0.0;
          v161 = 1i64 << (gActionRequest_EquipUP.m_EnumValue & 0x3F);
          other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_EquipUP.m_EnumValue >> 6] |= v161;
          v162 = (float)(signed int)0.0;
          if ( v162 >= 255.0 )
            v162 = FLOAT_255_0;
          other.mActionRequestChargeTimes[v160] = (signed int)v162;
          other.mSignals |= v161;
        }
      }
    }
  }
  v163 = UFG::ActionDef_Raw_Focus.mDataPerController[v8];
  if ( v163 && v163->mActionTrue )
  {
    v164 = v163->mOnSeconds;
    v165 = gActionRequest_Raw_Focus.m_EnumValue;
    v166 = 1i64 << (gActionRequest_Raw_Focus.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Raw_Focus.m_EnumValue >> 6] |= v166;
    v122 = v164 * 60.0;
    v167 = (float)(signed int)v122;
    if ( v167 >= 255.0 )
      v167 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v165] = (signed int)v167;
    other.mSignals |= v166;
  }
  v168 = UFG::ActionDef_Raw_Focus_Full.mDataPerController[v8];
  if ( v168 && v168->mActionTrue )
  {
    v169 = v168->mOnSeconds;
    v170 = gActionRequest_Raw_Focus_Full.m_EnumValue;
    v171 = 1i64 << (gActionRequest_Raw_Focus_Full.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Raw_Focus_Full.m_EnumValue >> 6] |= v171;
    v122 = v169 * 60.0;
    v172 = (float)(signed int)v122;
    if ( v172 >= 255.0 )
      v172 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v170] = (signed int)v172;
    other.mSignals |= v171;
  }
  v173 = UFG::ActionDef_Raw_Focus_Lock.mDataPerController[v8];
  if ( v173 && v173->mActionTrue )
  {
    v174 = gActionRequest_Raw_Focus_Lock.m_EnumValue;
    v175 = gActionRequest_Raw_Focus_Lock.m_EnumValue & 0x3F;
    v176 = v173->mOnSeconds * 60.0;
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Raw_Focus_Lock.m_EnumValue >> 6] |= 1i64 << (gActionRequest_Raw_Focus_Lock.m_EnumValue & 0x3F);
    v177 = (float)(signed int)v176;
    if ( v177 >= 255.0 )
      v177 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v174] = (signed int)v177;
    other.mSignals |= 1i64 << v175;
    v178 = gActionRequest_WeaponMode.m_EnumValue;
    v122 = v173->mOnSeconds * 60.0;
    v179 = 1i64 << (gActionRequest_WeaponMode.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_WeaponMode.m_EnumValue >> 6] |= v179;
    v180 = (float)(signed int)v122;
    if ( v180 >= 255.0 )
      v180 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v178] = (signed int)v180;
    other.mSignals |= v179;
  }
  v181 = UFG::ActionDef_Focus.mDataPerController[v8];
  if ( v181 && v181->mActionTrue )
  {
    if ( v10 )
    {
      v183 = UFG::ActionDef_Mouse.mDataPerController[v8];
      if ( v183 )
      {
        v122 = v183->mAxisPositionX;
        v184 = v183->mAxisPositionY;
      }
      else
      {
        v122 = 0.0;
        v184 = 0.0;
      }
      v321 = UFG::FollowCameraComponent::rMouseSpeedScaleVMin * v184;
      v323 = UFG::FollowCameraComponent::rMouseSpeedScaleHMin * v122;
    }
    else
    {
      v182 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v8];
      if ( v182 && v182->mActionTrue )
      {
        v122 = v182->mAxisPositionX;
        v323 = v182->mAxisPositionX;
        LODWORD(v321) = LODWORD(v182->mAxisPositionY) ^ _xmm[0];
      }
    }
  }
  v185 = UFG::ActionDef_Freerun.mDataPerController[v8];
  if ( v185 && v185->mActionTrue || lock_freerun_button )
  {
    if ( v185 )
      v186 = v185->mOnSeconds;
    else
      v186 = 0.0;
    v187 = gActionRequest_Freerun.m_EnumValue;
    v122 = v186 * 60.0;
    v188 = 1i64 << (gActionRequest_Freerun.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Freerun.m_EnumValue >> 6] |= v188;
    v189 = (float)(signed int)v122;
    if ( v189 >= 255.0 )
      v189 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v187] = (signed int)v189;
    other.mSignals |= v188;
  }
  v190 = UFG::MultiAction_ForwardKeyDoubleTap.mDataPerController[v8];
  if ( v190 && v190->mActionTrue )
  {
    lock_freerun_button = 1;
  }
  else
  {
    v191 = UFG::ActionDef_ForwardKey.mDataPerController[v8];
    if ( !v191 || !v191->mActionTrue )
      lock_freerun_button = 0;
  }
  v192 = UFG::ActionDef_VehicleFocus.mDataPerController[v8];
  if ( v192 && v192->mActionTrue
    || (v193 = UFG::ActionDef_VehicleFocus_Alt.mDataPerController[v8]) != 0i64 && v193->mActionTrue )
  {
    v194 = gActionRequest_VehicleFocus.m_EnumValue;
    v122 = 0.0;
    v195 = 1i64 << (gActionRequest_VehicleFocus.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_VehicleFocus.m_EnumValue >> 6] |= v195;
    v196 = (float)(signed int)0.0;
    if ( v196 >= 255.0 )
      v196 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v194] = (signed int)v196;
    other.mSignals |= v195;
  }
  v197 = UFG::ActionDef_VehicleActionHijack.mDataPerController[v8];
  if ( v197 && v197->mActionTrue )
  {
    v198 = gActionRequest_VehicleActionHijackDesired.m_EnumValue;
    v122 = 0.0;
    v199 = 1i64 << (gActionRequest_VehicleActionHijackDesired.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_VehicleActionHijackDesired.m_EnumValue >> 6] |= v199;
    v200 = (float)(signed int)0.0;
    if ( v200 >= 255.0 )
      v200 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v198] = (signed int)v200;
    other.mSignals |= v199;
  }
  v201 = UFG::ActionDef_Accelerate.mDataPerController[v8];
  if ( v201 && v201->mActionTrue )
  {
    v202 = v201->mOnSeconds;
    v203 = gActionRequest_VehicleGas.m_EnumValue;
    v204 = 1i64 << (gActionRequest_VehicleGas.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_VehicleGas.m_EnumValue >> 6] |= v204;
    v122 = v202 * 60.0;
    v205 = (float)(signed int)v122;
    if ( v205 >= 255.0 )
      v205 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v203] = (signed int)v205;
    other.mSignals |= v204;
  }
  else
  {
    v206 = UFG::ActionDef_AccelerateButton.mDataPerController[v8];
    if ( v206 && v206->mActionTrue )
      Intention::Set(&other, gActionRequest_VehicleGas.m_EnumValue, v206->mOnSeconds);
  }
  v207 = UFG::ActionDef_Brake.mDataPerController[v8];
  if ( v207 && v207->mActionTrue )
  {
    v208 = gActionRequest_VehicleReverse.m_EnumValue;
    v122 = 0.0;
    v209 = 1i64 << (gActionRequest_VehicleReverse.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_VehicleReverse.m_EnumValue >> 6] |= v209;
    v210 = (float)(signed int)0.0;
    if ( v210 >= 255.0 )
      v210 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v208] = (signed int)v210;
    other.mSignals |= v209;
  }
  else
  {
    v211 = UFG::ActionDef_BrakeButton.mDataPerController[v8];
    if ( v211 && v211->mActionTrue )
      Intention::Set(&other, gActionRequest_VehicleReverse.m_EnumValue, 0.0);
  }
  v212 = UFG::ActionDef_HandBrake.mDataPerController[v8];
  if ( v212 && v212->mActionTrue )
  {
    v213 = gActionRequest_VehicleHandBrake.m_EnumValue;
    v122 = 0.0;
    v214 = 1i64 << (gActionRequest_VehicleHandBrake.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_VehicleHandBrake.m_EnumValue >> 6] |= v214;
    v215 = (float)(signed int)0.0;
    if ( v215 >= 255.0 )
      v215 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v213] = (signed int)v215;
    other.mSignals |= v214;
  }
  v216 = UFG::ActionDef_LookBack.mDataPerController[v8];
  if ( v216 && v216->mActionTrue )
  {
    v217 = gActionRequest_VehicleLookBack.m_EnumValue;
    v122 = 0.0;
    v218 = 1i64 << (gActionRequest_VehicleLookBack.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_VehicleLookBack.m_EnumValue >> 6] |= v218;
    v219 = (float)(signed int)0.0;
    if ( v219 >= 255.0 )
      v219 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v217] = (signed int)v219;
    other.mSignals |= v218;
  }
  v220 = UFG::ActionDef_Pickup.mDataPerController[v8];
  if ( v220 && v220->mActionTrue )
  {
    v221 = v220->mOnSeconds;
    v222 = gActionRequest_Pickup.m_EnumValue;
    v223 = 1i64 << (gActionRequest_Pickup.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Pickup.m_EnumValue >> 6] |= v223;
    v122 = v221 * 60.0;
    v224 = (float)(signed int)v122;
    if ( v224 >= 255.0 )
      v224 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v222] = (signed int)v224;
    other.mSignals |= v223;
  }
  v225 = UFG::ActionDef_UIL1Repeat.mDataPerController[v8];
  v226 = gActionRequest_RotateLeft.m_EnumValue;
  if ( v225 && v225->mActionTrue )
  {
    v227 = v225->mOnSeconds;
    v228 = 1i64 << (gActionRequest_RotateLeft.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_RotateLeft.m_EnumValue >> 6] |= v228;
    v122 = v227 * 60.0;
    v229 = (float)(signed int)v122;
    if ( v229 >= 255.0 )
      v229 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v226] = (signed int)v229;
    other.mSignals |= v228;
  }
  v230 = UFG::ActionDef_UILeftRepeat.mDataPerController[v8];
  if ( v230 && v230->mActionTrue )
    Intention::Set(&other, v226, v230->mOnSeconds);
  v231 = UFG::ActionDef_UIR1Repeat.mDataPerController[v8];
  if ( v231 && v231->mActionTrue )
    Intention::Set(&other, gActionRequest_RotateRight.m_EnumValue, v231->mOnSeconds);
  v232 = UFG::ActionDef_UIRightRepeat.mDataPerController[v8];
  if ( v232 && v232->mActionTrue )
    Intention::Set(&other, gActionRequest_RotateRight.m_EnumValue, v232->mOnSeconds);
  v233 = 0.0;
  v234 = 0.0;
  v235 = 0.0;
  v236 = 0.0;
  v237 = 0.0;
  v238 = 0.0;
  v239 = UFG::Director::Get()->mCurrentCamera;
  if ( v239 && v239->m_pSimObject )
  {
    v240 = UFG::GetCurrentGameCamera();
    v241 = v240;
    if ( v240 )
    {
      v242 = (signed __int64)&v240->mCamera;
    }
    else
    {
      if ( !UFG::bCameraSecondController )
        goto LABEL_361;
      v243 = UFG::Director::Get()->mCurrentCamera;
      if ( !v243 )
        goto LABEL_361;
      v242 = (signed __int64)&v243->mCamera;
    }
    if ( !v242 )
      goto LABEL_361;
    v244 = *(int *)(v242 + 160);
    v245 = *(int *)(v242 + 164);
    v246 = *(int *)(v242 + 168);
    v247 = *(float *)(v242 + 176);
    v248 = *(float *)(v242 + 180);
    v249 = *(float *)(v242 + 184);
    if ( v241 )
    {
      ((void (__fastcall *)(UFG::GameCameraComponent *))v241->vfptr[39].__vecDelDtor)(v241);
      v250 = v122;
      v251 = ((__int64 (__fastcall *)(UFG::GameCameraComponent *))v241->vfptr[38].__vecDelDtor)(v241);
    }
    else
    {
      v250 = 0.0;
      v251 = 0;
    }
    if ( (unsigned __int8)UFG::Editor::IsActive() )
    {
      v252 = UFG::Editor::GetActiveView();
      v253 = UFG::Editor::Camera::GetDirForward((UFG::Editor::Camera *)v252[10], &result);
      v244 = LODWORD(v253->x) ^ _xmm[0];
      v245 = LODWORD(v253->y) ^ _xmm[0];
      v246 = LODWORD(v253->z) ^ _xmm[0];
      v254 = UFG::Editor::GetActiveView();
      v255 = UFG::Editor::Camera::GetPosition((UFG::Editor::Camera *)v254[10], &result);
      v247 = v255->x;
      v248 = v255->y;
      v249 = v255->z;
    }
    v256 = v3->m_pAICharacterControllerComponent.m_pPointer;
    if ( v256 && BYTE6(v256[17].m_SafePointerList.mNode.mPrev) )
    {
      v257 = v3->m_pContext->mSimObject.m_pPointer;
      if ( v257 )
      {
        v258 = v257->m_pTransformNodeComponent;
        if ( v258 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v258);
          v259 = _xmm[0];
          LODWORD(v260) = LODWORD(v258->mWorldTransform.v0.x) ^ _xmm[0];
          v261 = LODWORD(v258->mWorldTransform.v0.y) ^ _xmm[0];
LABEL_357:
          v35 = *(float *)&FLOAT_1_0;
          v266 = (float)((float)(*(float *)&v261 * *(float *)&v261) + (float)(v260 * v260)) + 0.0000000099999991;
          if ( v266 == 0.0 )
            v267 = 0.0;
          else
            v267 = 1.0 / fsqrt(v266);
          v268 = v267;
          v269 = v267 * *(float *)&v261;
          v270 = v268 * v260;
          v271 = v270 * v321;
          v233 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v270 * v316) ^ v259) - (float)(v269 * v324);
          v234 = (float)(v270 * v324) - (float)(v269 * v316);
          v235 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v270 * v317) ^ v259) - (float)(v269 * v315);
          v236 = (float)(v270 * v315) - (float)(v269 * v317);
          v238 = (float)(v270 * v323) - (float)(v269 * v321);
          v237 = COERCE_FLOAT(LODWORD(v271) ^ v259) - (float)(v269 * v323);
          goto LABEL_361;
        }
      }
    }
    else
    {
      v260 = *(float *)&v244;
      v261 = v245;
      if ( !v251 )
      {
LABEL_356:
        v259 = _xmm[0];
        goto LABEL_357;
      }
      v262 = v3->m_pContext->mSimObject.m_pPointer;
      if ( v262 )
      {
        v263 = v262->m_pTransformNodeComponent;
        if ( v263 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v263);
          v260 = v247 - v263->mWorldTransform.v3.x;
          *(float *)&v261 = v248 - v263->mWorldTransform.v3.y;
          *(float *)&v246 = v249 - v263->mWorldTransform.v3.z;
        }
      }
      if ( fsqrt((float)(*(float *)&v261 * *(float *)&v261) + (float)(v260 * v260)) >= 0.0099999998 )
      {
        if ( v250 != 0.0 )
        {
          UFG::qRotationMatrixZ(&dest, v250 * fDeltaS);
          v264 = (float)((float)(dest.v1.x * *(float *)&v261) + (float)(dest.v0.x * v260))
               + (float)(dest.v2.x * *(float *)&v246);
          v265 = (float)(dest.v1.y * *(float *)&v261) + (float)(dest.v0.y * v260);
          v260 = v264;
          *(float *)&v261 = v265 + (float)(dest.v2.y * *(float *)&v246);
        }
        goto LABEL_356;
      }
    }
    v260 = *(float *)&v244;
    v261 = v245;
    goto LABEL_356;
  }
LABEL_361:
  v272 = (UFG::SimObjectCVBase *)v3->m_pContext->mSimObject.m_pPointer;
  if ( v272 )
  {
    v273 = v272->m_Flags;
    if ( (v273 >> 14) & 1 )
    {
      v274 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v272);
    }
    else if ( (v273 & 0x8000u) == 0 )
    {
      if ( (v273 >> 13) & 1 )
      {
        v274 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v272->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v273 >> 12) & 1 )
      {
        v274 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v272->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v274 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v272->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v274 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v272);
    }
    v5 = v274;
  }
  if ( v6 && v3->m_pAICharacterControllerComponent.m_pPointer && v5 && v5->m_HeadTrackingTarget.m_Type != -1 )
  {
    v275 = 1;
    other.mDesireToLookAtPoint = v6->mDesireToLookAtPoint;
    v276 = v6->mDesiredLookAtPoint.y;
    v277 = v6->mDesiredLookAtPoint.z;
    other.mDesiredLookAtPoint.x = v6->mDesiredLookAtPoint.x;
    other.mDesiredLookAtPoint.y = v276;
    other.mDesiredLookAtPoint.z = v277;
    other.mDesireToLookAtPointEye = v6->mDesireToLookAtPointEye;
    v278 = v6->mDesiredLookAtPointEye.y;
    v279 = v6->mDesiredLookAtPointEye.z;
    other.mDesiredLookAtPointEye.x = v6->mDesiredLookAtPointEye.x;
    other.mDesiredLookAtPointEye.y = v278;
    other.mDesiredLookAtPointEye.z = v279;
  }
  else
  {
    v275 = 0;
  }
  *(_DWORD *)&other.mAwarenessIntention.mEnableHeadTrack = *(_DWORD *)&v6->mAwarenessIntention.mEnableHeadTrack;
  other.mAwarenessIntention.mHeadTrackLimitX = v6->mAwarenessIntention.mHeadTrackLimitX;
  other.mAwarenessIntention.mHeadTrackLimitY = v6->mAwarenessIntention.mHeadTrackLimitY;
  other.mAwarenessIntention.mHeadTrackLimitZ = v6->mAwarenessIntention.mHeadTrackLimitZ;
  other.mAwarenessIntention.mEyeTrackLimitX = v6->mAwarenessIntention.mEyeTrackLimitX;
  other.mAwarenessIntention.mEyeTrackLimitY = v6->mAwarenessIntention.mEyeTrackLimitY;
  other.mAwarenessIntention.mEyeTrackLimitZ = v6->mAwarenessIntention.mEyeTrackLimitZ;
  other.mAwarenessIntention.mSpineTrackLimitX = v6->mAwarenessIntention.mSpineTrackLimitX;
  other.mAwarenessIntention.mSpineTrackLimitY = v6->mAwarenessIntention.mSpineTrackLimitY;
  other.mAwarenessIntention.mSpineTrackLimitZ = v6->mAwarenessIntention.mSpineTrackLimitZ;
  other.mAwarenessIntention.mHeadTrackGain = v6->mAwarenessIntention.mHeadTrackGain;
  other.mAwarenessIntention.mEyeTrackGain = v6->mAwarenessIntention.mEyeTrackGain;
  other.mAwarenessIntention.mSpineTrackGain = v6->mAwarenessIntention.mSpineTrackGain;
  v280 = (float)(v236 * v236) + (float)(v235 * v235);
  v281 = fsqrt(v280) - motionIntentionSpeedDeadZone;
  if ( v281 < 0.0 )
    v281 = 0.0;
  v282 = v281 / (float)(v35 - motionIntentionSpeedDeadZone);
  if ( v282 <= 0.001 )
  {
    v294 = v3->m_pAICharacterControllerComponent.m_pPointer;
    if ( !v294 )
      goto LABEL_406;
    if ( BYTE5(v294[17].m_SafePointerList.mNode.mPrev) )
    {
      v295 = v3->m_pContext->mSimObject.m_pPointer;
      if ( !v295 )
        goto LABEL_406;
      v296 = v295->m_pTransformNodeComponent;
      if ( !v296 )
        goto LABEL_406;
      UFG::TransformNodeComponent::UpdateWorldTransform(v296);
      v297 = v296->mWorldTransform.v0.y;
      v298 = v296->mWorldTransform.v0.z;
      v299 = v296->mWorldTransform.v0.x;
    }
    else
    {
      v297 = v6->mMotionIntentionDirection.y;
      v298 = v6->mMotionIntentionDirection.z;
      v299 = v6->mMotionIntentionDirection.x;
    }
    other.mMotionIntentionDirection.z = v298;
    other.mMotionIntentionDirection.y = v297;
    other.mMotionIntentionDirection.x = v299;
    goto LABEL_406;
  }
  if ( v280 == 0.0 )
    v283 = 0.0;
  else
    v283 = v35 / fsqrt(v280);
  other.mMotionIntentionDirection.z = v283 * 0.0;
  other.mMotionIntentionDirection.x = v283 * v235;
  other.mMotionIntentionDirection.y = v283 * v236;
  if ( !v275 )
  {
    v284 = (UFG::SimObjectCVBase *)v3->m_pContext->mSimObject.m_pPointer;
    if ( v284 )
    {
      v285 = v284->m_Flags;
      if ( (v285 >> 14) & 1 )
      {
        v286 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v284);
      }
      else if ( (v285 & 0x8000u) == 0 )
      {
        if ( (v285 >> 13) & 1 )
          v286 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v284);
        else
          v286 = (UFG::CharacterAnimationComponent *)((v285 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v284->vfptr,
                                                                           UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v284->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
      }
      else
      {
        v286 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v284);
      }
      v287 = v286;
      if ( v286 )
      {
        v288 = v286->mCreature;
        if ( v288->mPose.mRigHandle.mData )
        {
          v289 = Skeleton::GetBoneID(v288->mPose.mRigHandle.mUFGSkeleton, symBip01Neck.mUID);
          if ( v289 >= 0 )
          {
            v290 = Creature::GetTranslation(v287->mCreature, &result, v289);
            v291 = v290->y;
            v292 = v290->z;
            other.mDesiredLookAtPoint.x = other.mMotionIntentionDirection.x;
            v293 = other.mMotionIntentionDirection.x + v290->x;
            other.mDesireToLookAtPoint = 1;
            other.mDesiredLookAtPoint.x = v293;
            other.mDesiredLookAtPoint.y = other.mMotionIntentionDirection.y + v291;
            other.mDesiredLookAtPoint.z = other.mMotionIntentionDirection.z + v292;
          }
        }
      }
    }
  }
LABEL_406:
  other.mMotionIntentionSpeed = v282;
  v300 = (float)(v234 * v234) + (float)(v233 * v233);
  v301 = fsqrt(v300);
  if ( v301 <= 0.001 )
  {
    v306 = (UFG::SimObjectGame *)v3->m_pContext->mSimObject.m_pPointer;
    if ( !v306 )
      goto LABEL_424;
    v307 = v306->m_Flags;
    if ( (v307 >> 14) & 1 )
    {
      v308 = v306->m_Components.p[7].m_pComponent;
    }
    else if ( (v307 & 0x8000u) == 0 )
    {
      if ( (v307 >> 13) & 1 )
        v308 = v306->m_Components.p[6].m_pComponent;
      else
        v308 = (v307 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v306, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v306->vfptr, UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v308 = v306->m_Components.p[7].m_pComponent;
    }
    if ( !v308 )
      goto LABEL_424;
    v309 = v6->mMotionIntentionDirectionRaw.y;
    v305 = v6->mMotionIntentionDirectionRaw.z;
    other.mMotionIntentionDirectionRaw.x = v6->mMotionIntentionDirectionRaw.x;
    other.mMotionIntentionDirectionRaw.y = v309;
  }
  else
  {
    if ( v300 == 0.0 )
      v302 = 0.0;
    else
      v302 = v35 / fsqrt(v300);
    v303 = v302;
    v304 = v302;
    v305 = v302 * 0.0;
    other.mMotionIntentionDirectionRaw.x = v303 * v233;
    other.mMotionIntentionDirectionRaw.y = v304 * v234;
  }
  other.mMotionIntentionDirectionRaw.z = v305;
LABEL_424:
  other.mMotionIntentionSpeedRaw = v301;
  v310 = fsqrt((float)(v238 * v238) + (float)(v237 * v237));
  if ( v310 == 0.0 )
  {
    *(_QWORD *)&other.mFacingIntentionDirection.x = 0i64;
    other.mFacingIntentionDirection.z = 0.0;
  }
  else
  {
    v311 = v35 / v310;
    other.mFacingIntentionDirection.x = other.mFacingIntentionDirection.x * v311;
    other.mFacingIntentionDirection.y = other.mFacingIntentionDirection.y * v311;
    other.mFacingIntentionDirection.z = other.mFacingIntentionDirection.z * v311;
  }
  if ( v282 > 0.0 )
  {
    v312 = UFG::ActionDef_Jog.mDataPerController[v8];
    if ( v312 )
      v4 = v312->mOnSeconds;
    Intention::Set(&other, gActionRequest_Jog.m_EnumValue, v4);
  }
  drawStickValues();
  v313 = (UFG::AICharacterControllerComponent *)v3->m_pAICharacterControllerComponent.m_pPointer;
  if ( v313 )
  {
    Intention::Set(&other, &v313->m_Intention.mActionRequests);
    Intention::operator=(&v313->m_Intention, &other);
    UFG::AICharacterControllerBaseComponent::UpdateHoldMotionIntention(
      (UFG::AICharacterControllerBaseComponent *)v3->m_pAICharacterControllerComponent.m_pPointer,
      fDeltaS);
    LOBYTE(v3->m_pAICharacterControllerComponent.m_pPointer[15].m_SafePointerList.mNode.mPrev) = 1;
  }
  return 1;
}

// File Line: 4551
// RVA: 0x2EF750
void __fastcall HitRecordSetBerserkAttackFlagTask::Begin(HitRecordSetBerserkAttackFlagTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rcx
  unsigned int v5; // edx
  UFG::SimComponent *v6; // rax
  bool v7; // zf
  char v8; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return;
  v3 = v2->m_Flags;
  if ( !((v3 >> 14) & 1) && (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
    {
      v5 = UFG::HitReactionComponent::_TypeUID;
    }
    else
    {
      v7 = ((v3 >> 12) & 1) == 0;
      v5 = UFG::HitReactionComponent::_TypeUID;
      if ( v7 )
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID);
        goto LABEL_10;
      }
    }
    v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, v5);
LABEL_10:
    v4 = v6;
    goto LABEL_11;
  }
  v4 = v2->m_Components.p[15].m_pComponent;
LABEL_11:
  v8 = UFG::HitReactionComponent::msBerserkAttackValidFlag;
  if ( v4 )
    v8 = 1;
  UFG::HitReactionComponent::msBerserkAttackValidFlag = v8;
}

// File Line: 4564
// RVA: 0x149ECD0
__int64 dynamic_initializer_for__qwsFaceMeterImpact__()
{
  UFG::qWiseSymbol::create_from_string(&qwsFaceMeterImpact, "Play_face_meter_impact");
  return atexit(dynamic_atexit_destructor_for__qwsFaceMeterImpact__);
}

// File Line: 4568
// RVA: 0x2F1F90
void __fastcall PlayerBuffActivateTask::Begin(PlayerBuffActivateTask *this, ActionContext *context)
{
  UFG::ePlayerBuffEnum v2; // ebx

  v2 = (UFG::ePlayerBuffEnum)this->m_Track[1].vfptr;
  if ( UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer) )
    UFG::PlayerBuffTracker::ActivateBuff(v2);
}

// File Line: 4581
// RVA: 0x2F0150
void __fastcall MoneyDropTask::Begin(MoneyDropTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // r14
  UFG::SceneObjectProperties *v4; // rbx
  UFG::TransformNodeComponent *v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  char v8; // cl
  int v9; // esi
  UFG::qSymbol *v10; // rbx
  float v11; // xmm1_4
  float v12; // xmm0_4
  UFG::SimObjectGame *v13; // rax
  unsigned __int16 v14; // dx
  UFG::InventoryItemComponent *v15; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-60h]
  UFG::qVector3 position; // [rsp+30h] [rbp-50h]
  UFG::qMatrix44 xform; // [rsp+40h] [rbp-40h]
  UFG::SpawnInfoInterface::SpawnPriority pOverridePriority; // [rsp+A8h] [rbp+28h]

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = context;
  if ( v2 )
    v4 = v2->m_pSceneObj;
  else
    v4 = 0i64;
  if ( v2 )
    v5 = v2->m_pTransformNodeComponent;
  else
    v5 = 0i64;
  if ( v4 && v5 && v2 )
  {
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v2->m_Components.p[39].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InventoryComponent::_TypeUID);
      else
        v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InventoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::InventoryComponent::_TypeUID);
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InventoryComponent::_TypeUID);
    }
    if ( v7 )
    {
      if ( (v8 = (char)v7[14].m_pSimObject) != 0 && *(_DWORD *)&v7[14].m_Flags == 68 || SHIDWORD(v7[5].m_pSimObject) > 0 )
      {
        if ( !v8 || (v9 = 1, *(_DWORD *)&v7[14].m_Flags != 68) )
          v9 = HIDWORD(v7[5].m_pSimObject);
        HIDWORD(v7[5].m_pSimObject) = 0;
        UFG::InventoryComponent::UpdateGameStat((UFG::InventoryComponent *)v7, eINVENTORY_ITEM_MONEY);
        v10 = (UFG::qSymbol *)PropertyUtils::Get<UFG::qSymbol>(v4, (UFG::qSymbol *)&qSymbol_DropMoney.mUID);
        if ( v10 )
        {
          pOverridePriority = 3;
          xform = UFG::qMatrix44::msIdentity;
          UFG::TransformNodeComponent::UpdateWorldTransform(v5);
          v11 = v5->mWorldTransform.v3.y;
          v12 = v5->mWorldTransform.v3.z;
          position.x = v5->mWorldTransform.v3.x;
          out.x = position.x;
          position.y = v11;
          position.z = v12;
          out.y = v11;
          out.z = v12;
          if ( UFG::PlaceOnGround(&out, &position, 0.0, 0.0) )
          {
            *(UFG::qVector3 *)&xform.v3.x = out;
            LODWORD(xform.v3.w) = (_DWORD)FLOAT_1_0;
            v13 = (UFG::SimObjectGame *)UFG::CreateObject(v3, v10, &xform, &pOverridePriority);
            if ( v13 )
            {
              v14 = v13->m_Flags;
              if ( !((v14 >> 14) & 1) && (v14 & 0x8000u) == 0 )
              {
                if ( (v14 >> 13) & 1 )
                {
                  v15 = (UFG::InventoryItemComponent *)v13->m_Components.p[11].m_pComponent;
                }
                else if ( (v14 >> 12) & 1 )
                {
                  v15 = (UFG::InventoryItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v13,
                                                         UFG::InventoryItemComponent::_TypeUID);
                }
                else
                {
                  v15 = (UFG::InventoryItemComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v13->vfptr,
                                                         UFG::InventoryItemComponent::_TypeUID);
                }
                if ( v15 )
                  UFG::InventoryItemComponent::SetQuantity(v15, v9);
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
  UFG::SimObjectGame *v2; // rax
  UFG::SimObject *v3; // rdi
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rsi
  UFG::SimComponent *v6; // rax
  int v7; // ebx
  UFG::GameStatTracker *v8; // rax
  int v9; // ebx
  UFG::GameStatTracker *v10; // rax
  int v11; // ebx
  UFG::OSuiteLeaderboardManager *v12; // rax
  UFG::OSuiteLeaderboardData *v13; // rax
  UFG::SceneObjectProperties *v14; // rax
  UFG::qPropertySet *v15; // rcx
  bool *v16; // rax
  int v17; // ebx
  UFG::OSuiteLeaderboardManager *v18; // rax
  UFG::OSuiteLeaderboardData *v19; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+20h]

  v2 = (UFG::SimObjectGame *)UFG::getTarget(context, eTARGET_TYPE_PICKUP_ITEM);
  v3 = (UFG::SimObject *)&v2->vfptr;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 || (v4 & 0x8000u) != 0 )
      goto LABEL_20;
    if ( (v4 >> 13) & 1 )
    {
      v5 = v2->m_Components.p[11].m_pComponent;
    }
    else
    {
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InventoryItemComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::InventoryItemComponent::_TypeUID);
      v5 = v6;
    }
    if ( !v5 || LODWORD(v5[1].m_pSimObject) != 68 )
      goto LABEL_20;
    v7 = (int)v5[1].m_BoundComponentHandles.mNode.mPrev;
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v8, Money, v7);
    v9 = (int)v5[1].m_BoundComponentHandles.mNode.mPrev;
    v10 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v10, TotalCashEarned, v9);
    v11 = (int)v5[1].m_BoundComponentHandles.mNode.mPrev;
    v12 = UFG::OSuiteLeaderboardManager::Instance();
    v13 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v12, "StatAwardsMogul");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v13, v11);
    UFG::qSymbol::create_from_string(&result, "ParkingMeterDrop");
    v14 = v3->m_pSceneObj;
    if ( v14 )
    {
      v15 = v14->mpWritableProperties;
      if ( v15 )
        goto LABEL_17;
      v15 = v14->mpConstProperties;
    }
    else
    {
      v15 = 0i64;
    }
    if ( !v15 )
    {
LABEL_20:
      UFG::SimObject::Destroy(v3);
      return;
    }
LABEL_17:
    v16 = UFG::qPropertySet::Get<bool>(v15, &result, DEPTH_RECURSE);
    if ( v16 )
    {
      if ( *v16 )
      {
        v17 = (int)v5[1].m_BoundComponentHandles.mNode.mPrev;
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
  UFG::SimObjectGame *v2; // rax
  UFG::SimObject *v3; // rbx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdi
  UFG::SimComponent *v6; // rax
  UFG::ProgressionTracker *v7; // rax
  UFG::GameSlice *v8; // rax
  UFG::GameSlice *v9; // rsi
  SSInstance *v10; // rax
  unsigned __int64 v11; // rdx
  SSInstance *v12; // rax
  signed __int64 v13; // rcx
  SSInstance *v14; // [rsp+30h] [rbp-18h]
  SSInstance *v15; // [rsp+38h] [rbp-10h]

  v2 = (UFG::SimObjectGame *)UFG::getTarget(context, eTARGET_TYPE_PICKUP_ITEM);
  v3 = (UFG::SimObject *)&v2->vfptr;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( !((v4 >> 14) & 1) && (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = v2->m_Components.p[11].m_pComponent;
      }
      else
      {
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InventoryItemComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::InventoryItemComponent::_TypeUID);
        v5 = v6;
      }
      if ( v5 )
      {
        v7 = UFG::ProgressionTracker::Instance();
        v8 = UFG::ProgressionTracker::GetActiveMaster(v7);
        v9 = v8;
        if ( v8 )
        {
          if ( v8->mState == 4 )
          {
            v10 = SSSymbol::as_instance((ASymbol *)&UFG::InventoryItemEnumSymbols[SLODWORD(v5[1].m_pSimObject)]);
            v11 = LODWORD(v5[1].m_BoundComponentHandles.mNode.mPrev);
            v14 = v10;
            v12 = SSInstance::pool_new(SSBrain::c_integer_class_p, v11);
            v13 = (signed __int64)&v9->mScript->vfptr;
            v15 = v12;
            (*(void (__fastcall **)(signed __int64, UFG::qStaticSymbol *, SSInstance **, signed __int64, _QWORD, _QWORD, SSInstance *, SSInstance *))(*(_QWORD *)v13 + 104i64))(
              v13,
              &qSymbol_on_pickup,
              &v14,
              2i64,
              0i64,
              0i64,
              v14,
              v12);
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::FaceMeterComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceMeterComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceMeterComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceMeterComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::FaceMeterComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v2->vfptr,
                                          UFG::FaceMeterComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceMeterComponent::_TypeUID);
    }
    if ( v4 )
      UFG::FaceMeterComponent::SetFaceMeterActivated(v4, 1);
  }
}

// File Line: 4708
// RVA: 0x2EE270
void __fastcall FaceInteractionResultSetTask::Begin(FaceInteractionResultSetTask *this, ActionContext *context)
{
  FaceInteractionResultSetTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[45].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::FaceActionComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v5 )
    {
      if ( LOBYTE(v5[1].m_SafePointerList.mNode.mNext) )
        ((void (*)(void))v2->m_Track[1].mResourceOwner->vfptr[1].__vecDelDtor)();
    }
  }
}

// File Line: 4726
// RVA: 0x2EF250
void __fastcall HealthRegenRateTask::Begin(HealthRegenRateTask *this, ActionContext *pContext)
{
  ITrack *v2; // rax
  ActionContext *v3; // rbx
  HealthRegenRateTask *v4; // rdi
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rdx
  UFG::SimComponent *v8; // rax

  v2 = this->m_Track;
  this->m_pContext = pContext;
  this->m_fPreviousRate = -1.0;
  v3 = pContext;
  v4 = this;
  if ( !LOBYTE(v2[1].vfptr) || UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer) )
  {
    v5 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v5->m_Components.p[6].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::HealthComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::HealthComponent::_TypeUID);
        }
        v7 = v8;
      }
      else
      {
        v7 = v5->m_Components.p[6].m_pComponent;
      }
      if ( v7 )
      {
        v4->m_fPreviousRate = *((float *)&v7[1].m_BoundComponentHandles.mNode.mNext + 1);
        HIDWORD(v7[1].m_BoundComponentHandles.mNode.mNext) = HIDWORD(v4->m_Track[1].vfptr);
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
  HealthRegenRateTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v1 = this;
  if ( this->m_fPreviousRate >= 0.0 )
  {
    v2 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
        }
        v4 = v5;
      }
      else
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      if ( v4 )
        HIDWORD(v4[1].m_BoundComponentHandles.mNode.mNext) = LODWORD(v1->m_fPreviousRate);
    }
  }
}

// File Line: 4773
// RVA: 0x2EF320
void __fastcall HealthRegenerateTask::Begin(HealthRegenerateTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rbx
  HealthRegenerateTask *v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::HealthComponent *v6; // rax

  v2 = pContext;
  v3 = this;
  if ( !LOBYTE(this->m_Track[1].vfptr) || UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer) )
  {
    v4 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v4->vfptr,
                                         UFG::HealthComponent::_TypeUID);
        }
      }
      else
      {
        v6 = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
      }
      if ( v6 )
        UFG::HealthComponent::AddHealthRegenerateTask(v6, v3);
    }
  }
}

// File Line: 4797
// RVA: 0x2EF3D0
void __fastcall HealthReplenishInstantTask::Begin(HealthReplenishInstantTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::HealthComponent *v5; // rax

  v2 = pContext;
  if ( !LOBYTE(this->m_Track[1].vfptr) || UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer) )
  {
    v3 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = (UFG::HealthComponent *)v3->m_Components.p[6].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v5 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v3->vfptr,
                                         UFG::HealthComponent::_TypeUID);
        }
      }
      else
      {
        v5 = (UFG::HealthComponent *)v3->m_Components.p[6].m_pComponent;
      }
      if ( v5 )
        UFG::HealthComponent::ReplenishHealth(v5);
    }
  }
}

// File Line: 4819
// RVA: 0x2F1BA0
void __fastcall ParkourHandleTask::Begin(ParkourHandleTask *this, ActionContext *pContext)
{
  ITrack *v2; // rax
  int v3; // ebx
  bool v4; // di
  UFG::TransformNodeComponent *i; // r10
  UFG::SimObject *v6; // rax

  v2 = this->m_Track;
  v3 = HIDWORD(v2[1].vfptr);
  v4 = LOBYTE(v2[1].vfptr) != 0;
  for ( i = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                             pContext->mSimObject.m_pPointer,
                                             UFG::RigidBodyComponent::_TypeUID);
        i;
        i = UFG::SimObject::GetComponentOfType(
              i->m_pSimObject,
              UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
              0,
              (UFG::SimComponent *)&i->vfptr) )
  {
    if ( v3 == -1 || *(_DWORD *)(*(_QWORD *)&i->mWorldTransform.v2.x + 216i64) == v3 )
    {
      v6 = i[1].m_pSimObject;
      if ( v6 )
      {
        if ( v4 == 1 )
          LODWORD(v6[1].mNode.mChild[1]) &= 0xFFFFFFF7;
        else
          LODWORD(v6[1].mNode.mChild[1]) |= 8u;
      }
    }
  }
}

// File Line: 4857
// RVA: 0x2EFB50
void __fastcall InvulnerableTask::Begin(InvulnerableTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  if ( pContext )
  {
    this->m_pContext = pContext;
    v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
        }
      }
      else
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      if ( v4 )
        BYTE5(v4[1].m_BoundComponentHandles.mNode.mPrev) = 1;
    }
  }
}

// File Line: 4870
// RVA: 0x2FEF20
void __fastcall InvulnerableTask::End(InvulnerableTask *this)
{
  ActionContext *v1; // rcx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  v1 = this->m_pContext;
  if ( v1 )
  {
    v2 = (UFG::SimObjectGame *)v1->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
        }
      }
      else
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      if ( v4 )
        BYTE5(v4[1].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 4886
// RVA: 0x2F46C0
void __fastcall SocialSetEnabledTask::Begin(SocialSetEnabledTask *this, ActionContext *pContext)
{
  SocialSetEnabledTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  if ( pContext )
  {
    v2 = this;
    v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = v3->m_Components.p[45].m_pComponent;
      }
      else
      {
        if ( (v4 & 0x8000u) == 0 )
        {
          if ( (v4 >> 13) & 1 )
          {
            v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
          }
          else if ( (v4 >> 12) & 1 )
          {
            v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
          }
          else
          {
            v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::FaceActionComponent::_TypeUID);
          }
        }
        else
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
        }
        v5 = v6;
      }
      if ( v5 )
        *((_BYTE *)&v5[3].m_SimObjIndex + 4) = LOBYTE(v2->m_Track[1].vfptr) == 0;
    }
  }
}

// File Line: 4901
// RVA: 0x2F4770
void __fastcall SocialSetFaceActionStateTask::Begin(SocialSetFaceActionStateTask *this, ActionContext *pContext)
{
  SocialSetFaceActionStateTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::FaceActionComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  if ( pContext )
  {
    v2 = this;
    v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
      }
      else
      {
        if ( (v4 & 0x8000u) == 0 )
        {
          if ( (v4 >> 13) & 1 )
          {
            v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
          }
          else if ( (v4 >> 12) & 1 )
          {
            v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
          }
          else
          {
            v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::FaceActionComponent::_TypeUID);
          }
        }
        else
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
        }
        v5 = (UFG::FaceActionComponent *)v6;
      }
      if ( v5 )
        UFG::FaceActionComponent::SetState(v5, (UFG::eFaceActionState)LOBYTE(v2->m_Track[1].vfptr));
    }
  }
}

// File Line: 4914
// RVA: 0x2F4810
void __fastcall SocialSetFastTalkSuccessTask::Begin(SocialSetFastTalkSuccessTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rdi
  SocialSetFastTalkSuccessTask *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  UFG::SimComponent *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  bool v11; // dl
  UFG::allocator::free_link *v12; // rsi
  const char *v13; // rdi
  unsigned int v14; // ebx
  UFG::SimObjectCharacter *v15; // rax
  UFG::allocator::free_link *v16; // rcx

  if ( pContext )
  {
    v2 = pContext;
    v3 = this;
    v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v5 = v4->m_Components.p[45].m_pComponent;
      }
      else
      {
        if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
          {
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FaceActionComponent::_TypeUID);
          }
          else if ( (v6 >> 12) & 1 )
          {
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FaceActionComponent::_TypeUID);
          }
          else
          {
            v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::FaceActionComponent::_TypeUID);
          }
        }
        else
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FaceActionComponent::_TypeUID);
        }
        v5 = v7;
      }
    }
    else
    {
      v5 = 0i64;
    }
    v8 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 >> 14) & 1 )
      {
        v8 = (UFG::SimObjectGame *)v8->m_Components.p[5].m_pComponent;
      }
      else if ( (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else if ( (v9 >> 12) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else
        {
          v10 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v8->vfptr,
                  UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        v8 = (UFG::SimObjectGame *)v10;
      }
      else
      {
        v8 = (UFG::SimObjectGame *)v8->m_Components.p[5].m_pComponent;
      }
    }
    v11 = LOBYTE(v3->m_Track[1].vfptr) != 0;
    if ( v5 )
    {
      BYTE5(v5[3].m_SafePointerList.mNode.mPrev) = (LOBYTE(v3->m_Track[1].vfptr) != 0) | BYTE5(v5[3].m_SafePointerList.mNode.mPrev) & 0xFE | 2;
    }
    else if ( v8 )
    {
      BYTE2(v8[14].m_pSceneObj) &= 0xFDu;
      BYTE2(v8[14].m_pSceneObj) |= 2 * v11;
    }
    if ( v11 )
    {
      v12 = UFG::qMalloc(0x48ui64, "GameStatEventTask", 0i64);
      if ( v12 )
      {
        v13 = UFG::gGameStatEventChannel.mName;
        v14 = UFG::gGameStatEventChannel.mUID;
        v15 = UFG::GetLocalPlayer();
        v16 = v12 + 1;
        v16->mNext = v16;
        v16[1].mNext = v16;
        v12->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable';
        LODWORD(v12[3].mNext) = v14;
        v12[4].mNext = (UFG::allocator::free_link *)v13;
        v12->mNext = (UFG::allocator::free_link *)&UFG::GameStatEvent::`vftable';
        LODWORD(v12[7].mNext) = 41;
        v12[8].mNext = (UFG::allocator::free_link *)v15;
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
void __fastcall SocialFaceActionDisplayConfirmationDialogTask::Begin(SocialFaceActionDisplayConfirmationDialogTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  UFG::SimComponent *v3; // rdx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // r8
  unsigned __int16 v7; // cx
  UFG::FaceActionComponent *v8; // rax

  if ( pContext )
  {
    this->m_pContext = pContext;
    v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v4 = v2->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v3 = v2->m_Components.p[20].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v2->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v3 = v5;
      }
      else
      {
        v3 = v2->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v3 = 0i64;
    }
    v6 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v3[1].m_Flags + 58i64)
                                + *(_QWORD *)&v3[1].m_TypeUID
                                + 40);
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::FaceActionComponent *)v6->m_Components.p[45].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v6,
                                             UFG::FaceActionComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v6,
                                             UFG::FaceActionComponent::_TypeUID);
        }
        else
        {
          v8 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v6->vfptr,
                                             UFG::FaceActionComponent::_TypeUID);
        }
      }
      else
      {
        v8 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v6,
                                           UFG::FaceActionComponent::_TypeUID);
      }
      if ( v8 )
        UFG::FaceActionComponent::OpenConfirmationDialog(v8);
    }
  }
}

// File Line: 4960
// RVA: 0x30A060
bool __fastcall SocialFaceActionDisplayConfirmationDialogTask::Update(SocialFaceActionDisplayConfirmationDialogTask *this, float __formal)
{
  ActionContext *v2; // rcx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rdx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::FaceActionComponent *v9; // rax
  bool result; // al

  v2 = this->m_pContext;
  if ( v2
    && ((v3 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer) != 0i64 ? ((v5 = v3->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)), v4 = v6) : (v4 = v3->m_Components.p[20].m_pComponent)) : (v4 = v3->m_Components.p[20].m_pComponent)) : (v4 = 0i64),
        (v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 58i64)
                                     + *(_QWORD *)&v4[1].m_TypeUID
                                     + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::FaceActionComponent::_TypeUID)) : (v9 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FaceActionComponent::_TypeUID))) : (v9 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FaceActionComponent::_TypeUID))) : (v9 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FaceActionComponent::_TypeUID))) : (v9 = (UFG::FaceActionComponent *)v7->m_Components.p[45].m_pComponent),
         v9)) )
  {
    result = UFG::FaceActionComponent::IsConfirmationDialogComplete(v9) == 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

// File Line: 4980
// RVA: 0x2F9F50
void __fastcall TriggerRecoilPostEffectTask::Begin(TriggerRecoilPostEffectTask *this, ActionContext *context)
{
  ActionContext *v2; // rbx
  TriggerRecoilPostEffectTask *v3; // rdi
  UFG::GameCameraComponent *v4; // rax
  __int64 v5; // rax
  ITrack *v6; // rax
  float v7; // xmm6_4
  float v8; // xmm0_4

  if ( context )
  {
    v2 = context;
    v3 = this;
    v4 = UFG::GetCurrentGameCamera();
    if ( v4 )
    {
      v5 = ((__int64 (__fastcall *)(UFG::GameCameraComponent *))v4->vfptr[41].__vecDelDtor)(v4);
      if ( v5 )
      {
        if ( *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v5 + 96) + 25i64) + *(_QWORD *)(v5 + 88) + 40) == v2->mSimObject.m_pPointer )
        {
          v6 = v3->m_Track;
          v7 = *(float *)&v6[1].vfptr;
          v8 = *((float *)&v6[1].vfptr + 1);
          if ( v8 >= v7 )
            v7 = UFG::qRandom(v8 - v7, &UFG::qDefaultSeed) + v7;
          UFG::RenderWorld::GunRecoilPostEffect_TriggerRecoil(v7, *(float *)&v3->m_Track[1].mResourceOwner);
        }
      }
    }
  }
}

// File Line: 5008
// RVA: 0x2DD570
void __fastcall AccuracyModifierTask::AccuracyModifierTask(AccuracyModifierTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *v2; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AccuracyModifierTrack>::`vftable';
  v2 = (UFG::qNode<AccuracyModifierTask,AimingSystemAccuracyModifierList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&AccuracyModifierTask::`vftable';
  *((_BYTE *)this + 64) = *((_BYTE *)this + 64) & 0xFD | 1;
}

// File Line: 5018
// RVA: 0x2E7FE0
void __fastcall AccuracyModifierTask::Begin(AccuracyModifierTask *this, ActionContext *action_context)
{
  AccuracyModifierTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AimingBaseComponent *v5; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::AimingBaseComponent *)v3->m_Components.p[47].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::AimingBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::AimingBaseComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( v5 )
      UFG::AimingBaseComponent::AddAccuracyModifierTask(v5, v2);
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
  if ( !(v2 & 2) )
    return 1;
  *((_BYTE *)this + 64) = v2 & 0xFE;
  return 0;
}

// File Line: 5044
// RVA: 0x2FECF0
void __fastcall AimingSoftLockTask::End(TargetSteerToTask *this)
{
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *v1; // rax
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *v2; // rdx
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *v3; // rcx

  v1 = this->mNext;
  v2 = (UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *)&this->mPrev;
  v3 = this->mPrev;
  v3->mNext = v1;
  v1->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
}

// File Line: 5053
// RVA: 0x2DE670
void __fastcall CollectibleCollectTask::CollectibleCollectTask(CollectibleCollectTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<CollectibleCollectTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&CollectibleCollectTask::`vftable';
}

// File Line: 5062
// RVA: 0x2EAA70
void __fastcall CollectibleCollectTask::Begin(CollectibleCollectTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // r8
  ActionContext *v3; // rbx
  __int64 v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  __int64 v15; // rdx

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v3 = action_context;
  v4 = HIDWORD(this->m_Track[1].vfptr);
  if ( v2 )
  {
    v5 = v2->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v6 = v2->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      v7 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v9 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v7->vfptr,
                   UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v7 = (UFG::SimObjectGame *)v9;
        }
        else
        {
          v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
        }
      }
      v10 = ((__int64 (*)(void))v7->vfptr[15].__vecDelDtor)();
      if ( v10 )
      {
        v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v10 + 96) + v4 + 8) + *(_QWORD *)(v10 + 88) + 40);
        if ( v11 )
        {
          v12 = *(UFG::SimObjectGame **)(*(_QWORD *)(v11 + 80) + 96i64);
          if ( v12 )
          {
            v13 = v12->m_Flags;
            if ( (v13 >> 14) & 1 )
            {
              v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID);
            }
            else if ( (v13 & 0x8000u) == 0 )
            {
              if ( (v13 >> 13) & 1 )
              {
                v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID);
              }
              else if ( (v13 >> 12) & 1 )
              {
                v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID);
              }
              else
              {
                v14 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v12->vfptr,
                        UFG::CollectibleComponent::_TypeUID);
              }
            }
            else
            {
              v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID);
            }
            if ( v14 )
            {
              LOBYTE(v15) = 1;
              v14->vfptr[24].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v14->vfptr, v15);
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
  AIOutlineActivateTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::AIOutlineComponent *v6; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !v3 )
    return;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIOutlineComponent::_TypeUID);
  }
  else
  {
    if ( (v4 & 0x8000u) != 0 )
    {
      v6 = (UFG::AIOutlineComponent *)v3->m_Components.p[27].m_pComponent;
      goto LABEL_12;
    }
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIOutlineComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIOutlineComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIOutlineComponent::_TypeUID);
    }
  }
  v6 = (UFG::AIOutlineComponent *)v5;
LABEL_12:
  if ( v6 )
  {
    if ( LOBYTE(v2->m_Track[1].vfptr) )
      UFG::AIOutlineComponent::ActivateOutline(v6);
    else
      UFG::AIOutlineComponent::DeactivateOutline(v6);
  }
}

// File Line: 5128
// RVA: 0x2E0F20
void __fastcall SimObjectFlagSetTask::SimObjectFlagSetTask(SimObjectFlagSetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectPropertiesComponent> *v3; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<SimObjectFlagSetTrack>::`vftable';
  v2 = (UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&SimObjectFlagSetTask::`vftable';
  v3 = &this->m_SimObjectPropertiesComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_SimObjectPropertiesComponent.m_pPointer = 0i64;
}

// File Line: 5133
// RVA: 0x2E4F20
void __fastcall SimObjectFlagSetTask::~SimObjectFlagSetTask(SimObjectFlagSetTask *this)
{
  SimObjectFlagSetTask *v1; // rbx
  UFG::SimObjectPropertiesComponent *v2; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectPropertiesComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v8; // rdx
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v9; // rcx
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v10; // rax
  UFG::qNode<ITask,ITask> *v11; // rdx
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&SimObjectFlagSetTask::`vftable';
  v2 = (UFG::SimObjectPropertiesComponent *)this->m_SimObjectPropertiesComponent.m_pPointer;
  if ( v2 )
    UFG::SimObjectPropertiesComponent::UpdateCachedValues(v2);
  v3 = &v1->m_SimObjectPropertiesComponent;
  if ( v1->m_SimObjectPropertiesComponent.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v1->m_SimObjectPropertiesComponent.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v1->m_SimObjectPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_SimObjectPropertiesComponent.mPrev;
  }
  v1->m_SimObjectPropertiesComponent.m_pPointer = 0i64;
  v6 = v3->mPrev;
  v7 = v1->m_SimObjectPropertiesComponent.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->m_SimObjectPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_SimObjectPropertiesComponent.mPrev;
  v8 = (UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v11 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v12 = v1->mPrev;
  v13 = v1->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v11->mPrev = v11;
  v11->mNext = v11;
}

// File Line: 5142
// RVA: 0x2F4270
void __fastcall SimObjectFlagSetTask::Begin(SimObjectFlagSetTask *this, ActionContext *pActionContext)
{
  SimObjectFlagSetTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectPropertiesComponent *v5; // r9
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectPropertiesComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  v2 = this;
  this->m_pActionContext = pActionContext;
  v3 = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::SimObjectPropertiesComponent *)v3->m_Components.p[3].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::SimObjectPropertiesComponent *)v3->m_Components.p[4].m_pComponent;
      }
      else
      {
        if ( (v4 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectPropertiesComponent::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::SimObjectPropertiesComponent::_TypeUID);
        v5 = (UFG::SimObjectPropertiesComponent *)v6;
      }
    }
    else
    {
      v5 = (UFG::SimObjectPropertiesComponent *)v3->m_Components.p[3].m_pComponent;
    }
    if ( v5 )
    {
      v7 = &v2->m_SimObjectPropertiesComponent;
      if ( v2->m_SimObjectPropertiesComponent.m_pPointer )
      {
        v8 = v7->mPrev;
        v9 = v2->m_SimObjectPropertiesComponent.mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
        v2->m_SimObjectPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_SimObjectPropertiesComponent.mPrev;
      }
      v2->m_SimObjectPropertiesComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
      v10 = v5->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_SimObjectPropertiesComponent.mNext = &v5->m_SafePointerList.mNode;
      v7->mPrev = v10;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      UFG::SimObjectPropertiesComponent::AddSimObjectFlagSetTask(v5, (UFG::eSimObjectFlagEnum)v2->m_Track[1].vfptr, v2);
    }
  }
}

// File Line: 5162
// RVA: 0x2F3870
void __fastcall SetRollStabilityTask::Begin(SetRollStabilityTask *this, ActionContext *pContext)
{
  SetRollStabilityTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rdx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          return;
        if ( (v4 >> 12) & 1 )
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v5 = v3->m_Components.p[34].m_pComponent;
      }
      if ( v5 )
      {
        v6 = v5[10].m_SafePointerList.mNode.mPrev;
        if ( v6 )
        {
          if ( (HIDWORD(v6[37].mNext) & 7) == 4 )
            LODWORD(v6[36].mNext) = v2->m_Track[1].vfptr;
        }
      }
    }
  }
}

// File Line: 5185
// RVA: 0x2F3620
void __fastcall SetCharacterOnFireTask::Begin(SetCharacterOnFireTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CharacterEffectsComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CharacterEffectsComponent *)v2->m_Components.p[38].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::CharacterEffectsComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v2,
                                                 UFG::CharacterEffectsComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v2->vfptr,
                                                 UFG::CharacterEffectsComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::CharacterEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v2,
                                               UFG::CharacterEffectsComponent::_TypeUID);
    }
    if ( v4 )
      UFG::CharacterEffectsComponent::ForceIgniteFire(v4);
  }
}

// File Line: 5198
// RVA: 0x2F3590
void __fastcall SetCharacterInvulnerableToFireTask::Begin(SetCharacterInvulnerableToFireTask *this, ActionContext *pContext)
{
  SetCharacterInvulnerableToFireTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // dx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[38].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterEffectsComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterEffectsComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterEffectsComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterEffectsComponent::_TypeUID);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v2->mCharacterEffectsComponent = (UFG::CharacterEffectsComponent *)v4;
  if ( v4 )
    LOBYTE(v4[1].m_SafePointerList.mNode.mNext) = 1;
}

// File Line: 5208
// RVA: 0x300220
void __fastcall SetCharacterInvulnerableToFireTask::End(SetCharacterInvulnerableToFireTask *this)
{
  UFG::CharacterEffectsComponent *v1; // rax

  v1 = this->mCharacterEffectsComponent;
  if ( v1 )
    v1->InvulnerableToFire = 0;
}

// File Line: 5220
// RVA: 0x2EDD40
void __fastcall DisableSelfIlluminationTask::Begin(DisableSelfIlluminationTask *this, ActionContext *pContext)
{
  DisableSelfIlluminationTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  UFG::SimComponent *v5; // rax
  unsigned __int16 v6; // dx
  UFG::SimObjectGame *v7; // rcx
  UFG::SimComponent *v8; // rax
  unsigned __int16 v9; // dx
  UFG::CharacterLookComponent *v10; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterLookComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterLookComponent::_TypeUID);
    }
  }
  else
  {
    v5 = 0i64;
  }
  v2->mCharacterLookComponent = (UFG::CharacterLookComponent *)v5;
  v7 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CompositeLookComponent::_TypeUID);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CompositeLookComponent::_TypeUID);
      }
      else if ( (v9 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CompositeLookComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::CompositeLookComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::CompositeLookComponent::_TypeUID);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v10 = v2->mCharacterLookComponent;
  v2->mCompositeLookComponent = (UFG::CompositeLookComponent *)v8;
  if ( v10 )
  {
    v10->mSceneryInstance->SIColourTint[3] = 0.0;
  }
  else if ( v8 )
  {
    HIDWORD(v8[1].m_BoundComponentHandles.mNode.mNext[1].mNext) = 0;
  }
}

// File Line: 5236
// RVA: 0x2FEB80
void __fastcall DisableSelfIlluminationTask::End(DisableSelfIlluminationTask *this)
{
  UFG::CharacterLookComponent *v1; // rax

  v1 = this->mCharacterLookComponent;
  if ( v1 || (v1 = (UFG::CharacterLookComponent *)this->mCompositeLookComponent) != 0i64 )
    v1->mSceneryInstance->SIColourTint[3] = 1.0;
}

// File Line: 5252
// RVA: 0x2F1FC0
void __fastcall PlayerGainHealthBasedOnActiveBuffTask::Begin(PlayerGainHealthBasedOnActiveBuffTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::HealthComponent *v4; // rsi
  UFG::SimComponent *v5; // rax
  signed int v6; // ebx
  int v7; // edi
  UFG::GameStatTracker *v8; // rax
  int v9; // ebx
  int v10; // eax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::HealthComponent *)v2->m_Components.p[6].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID);
      else
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
      v4 = (UFG::HealthComponent *)v5;
    }
    else
    {
      v4 = (UFG::HealthComponent *)v2->m_Components.p[6].m_pComponent;
    }
    if ( v4 )
    {
      v6 = (signed int)v4->m_fHealth;
      v7 = (signed int)v4->m_fMaxHealth;
      v8 = UFG::GameStatTracker::Instance();
      v9 = (signed int)UFG::GameStatTracker::GetStat(v8, PlayerFaceMeterBuff_HealthPerHitGainedAtLevel2) + v6;
      v10 = 0;
      if ( v9 > 0 )
        v10 = v9;
      if ( v10 < v7 )
        v7 = v10;
      UFG::HealthComponent::SetHealth(v4, v7, 0i64);
    }
  }
}

// File Line: 5280
// RVA: 0x2E0CB0
void __fastcall ResourceOpportunityTask::ResourceOpportunityTask(ResourceOpportunityTask *this)
{
  ResourceOpportunityTask *v1; // rdx
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::PowerManagedResource *v3; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v4; // rax
  AnimationGroupHandleContainer *v5; // [rsp+28h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<ResourceOpportunityTrack>::`vftable';
  v3 = (UFG::PowerManagedResource *)&this->vfptr;
  v4 = (UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::PowerManagedResource::`vftable';
  v1->vfptr = (ITaskVtbl *)&ResourceOpportunityTask::`vftable'{for `Task<ResourceOpportunityTrack>'};
  v3->vfptr = (UFG::PowerManagedResourceVtbl *)&ResourceOpportunityTask::`vftable'{for `UFG::PowerManagedResource'};
  v1->mContext = 0i64;
  v1->mLatchedNode = 0i64;
  v1->mNameUID = 0;
  v1->mLatchedNodeResourcesGathered = 0;
  v5 = &v1->mAnimationGroupHandleContainer;
  v5->m_AnimationGroupHandleList.mNode.mPrev = &v5->m_AnimationGroupHandleList.mNode;
  v5->m_AnimationGroupHandleList.mNode.mNext = &v5->m_AnimationGroupHandleList.mNode;
  v1->mAnimationGroupHandleContainer.m_bHasBeenBound = 0;
}

// File Line: 5285
// RVA: 0x2F3230
void __fastcall ResourceOpportunityTask::Begin(ResourceOpportunityTask *this, ActionContext *context)
{
  UFG::SimObject *v2; // rax
  ActionContext *v3; // rbx
  ResourceOpportunityTask *v4; // rsi
  ResourceOpportunityTrack *v5; // rdx
  signed __int64 v6; // rdi
  __int64 v7; // rax
  signed __int64 v8; // rax
  __int64 v9; // rcx
  ActionPath *v10; // rax
  __int64 v11; // rbp
  ActionNodeRoot *v12; // rax
  __int64 v13; // r8
  ActionNodeRoot *v14; // rdi
  UFG::ActionTreeComponentBase *v15; // rcx

  this->mContext = context;
  v2 = context->mSimObject.m_pPointer;
  v3 = context;
  v4 = this;
  if ( v2 )
    this->mNameUID = v2->mNode.mUID;
  v5 = (ResourceOpportunityTrack *)this->m_Track;
  v6 = 0i64;
  v7 = v5->mActionNodeReference.mOffset;
  if ( v7 )
    v8 = (signed __int64)&v5->mActionNodeReference + v7;
  else
    v8 = 0i64;
  v9 = *(_QWORD *)(v8 + 72);
  if ( v9 )
    v6 = v9 + v8 + 72;
  v10 = ResourceOpportunityTrack::GetActionPath(v5);
  if ( !v6 && !(v10->mPath.mCount & 0x7FFFFFFF) )
    v6 = (signed __int64)v4->mContext->m_OpeningBranch;
  v11 = ((__int64 (*)(void))v3->m_OpeningBranch->vfptr[1].GetResourceOwner)();
  v12 = (ActionNodeRoot *)(*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v6 + 152i64))(v6);
  v13 = v12->mActionTreeType.mValue;
  v14 = v12;
  if ( (v3->mActionTreeComponentBase[v13] || v3->mActionTreeComponentBase[1]) && (ActionNodeRoot *)v11 != v12 )
  {
    v15 = v3->mActionTreeComponentBase[v13];
    if ( !v15 )
      v15 = v3->mActionTreeComponentBase[1];
    if ( UFG::ActionTreeComponentBase::AllocateFor(v15, v12) )
      ActionNodeRoot::Init(v14, v4->mContext);
  }
}

// File Line: 5316
// RVA: 0x309F00
bool __fastcall ResourceOpportunityTask::Update(ResourceOpportunityTask *this, float timeDelta)
{
  ResourceOpportunityTask *v2; // rbx
  bool result; // al
  ResourceOpportunityTrack *v4; // rcx
  signed __int64 v5; // rdi
  __int64 v6; // rax
  signed __int64 v7; // rax
  __int64 v8; // rdx
  ActionPath *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  float v12; // xmm1_4
  bool v13; // di
  bool v14; // al

  v2 = this;
  if ( !this->mLatchedNode
    && (UFG::Metrics::msInstance.mSimFrameCount + this->mNameUID) % SHIWORD(this->m_Track[1].m_TrackClassNameUID) )
  {
    return 1;
  }
  v4 = (ResourceOpportunityTrack *)this->m_Track;
  v5 = 0i64;
  v6 = v4->mActionNodeReference.mOffset;
  if ( v6 )
    v7 = (signed __int64)&v4->mActionNodeReference + v6;
  else
    v7 = 0i64;
  v8 = *(_QWORD *)(v7 + 72);
  if ( v8 )
    v5 = v8 + v7 + 72;
  v9 = ResourceOpportunityTrack::GetActionPath(v4);
  if ( !v5 )
  {
    if ( v9->mPath.mCount & 0x7FFFFFFF )
      goto LABEL_31;
    v5 = (signed __int64)v2->mContext->m_OpeningBranch;
    if ( !v5 )
      goto LABEL_31;
  }
  if ( !v2->mLatchedNode )
  {
    v10 = ((__int64 (*)(void))v2->m_Track->vfptr[2].__vecDelDtor)();
    if ( !v10
      || (*(unsigned __int8 (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v10 + 80i64))(v10, v2->mContext) )
    {
      v11 = (*(__int64 (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v5 + 200i64))(v5, v2->mContext);
      if ( v11 )
      {
        if ( BYTE1(v2->m_Track[1].m_TrackClassNameUID) )
        {
          v2->mLatchedNode = (ActionNodePlayable *)v11;
        }
        else if ( v2->mContext->mActionController->m_currentNode != (ActionNodePlayable *)v11 )
        {
          v2->mLatchedNode = (ActionNodePlayable *)v11;
        }
      }
    }
    if ( !v2->mLatchedNode )
      goto LABEL_32;
  }
  v12 = *(float *)&v2->m_Track[1].mBreakPoint;
  v13 = v12 >= 0.0 && v12 <= v2->mContext->mActionController->m_ActionNodePlayTime;
  v14 = ResourceOpportunityTask::areResourcesStreamedIn(v2);
  if ( v13 && v14 )
LABEL_31:
    result = 0;
  else
LABEL_32:
    result = 1;
  return result;
}

// File Line: 5411
// RVA: 0x303940
void __fastcall ResourceOpportunityTask::UnbindResources(ResourceOpportunityTask *this)
{
  AnimationGroupHandle *v1; // rsi
  ResourceOpportunityTask *v2; // rdi
  AnimationGroupHandle *v3; // rbx

  v1 = (AnimationGroupHandle *)&this->m_TimeBegin;
  v2 = this;
  v3 = (AnimationGroupHandle *)&this->mNext[-1];
  if ( v3 == (AnimationGroupHandle *)&this->m_TimeBegin )
  {
    LOBYTE(this->mContext) = 0;
  }
  else
  {
    do
    {
      AnimationGroupHandle::Unbind(v3);
      v3 = (AnimationGroupHandle *)&v3->mNext[-1];
    }
    while ( v3 != v1 );
    LOBYTE(v2->mContext) = 0;
  }
}

// File Line: 5418
// RVA: 0x3035B0
void __fastcall ResourceOpportunityTask::RebindResources(ResourceOpportunityTask *this)
{
  AnimationGroupHandle *v1; // rdi
  AnimationGroupHandle *v2; // rbx

  v1 = (AnimationGroupHandle *)&this->m_TimeBegin;
  v2 = (AnimationGroupHandle *)&this->mNext[-1];
  if ( v2 != (AnimationGroupHandle *)&this->m_TimeBegin )
  {
    do
    {
      if ( !v2->m_AnimationGroup.m_pPointer )
        AnimationGroupHandle::Bind(v2);
      v2 = (AnimationGroupHandle *)&v2->mNext[-1];
    }
    while ( v2 != v1 );
  }
}

// File Line: 5425
// RVA: 0x2E7D30
char __fastcall ResourceOpportunityTask::AreResourcesAvailable(ResourceOpportunityTask *this)
{
  ResourceOpportunityTask *v1; // rdi
  ResourceOpportunityTask *v2; // rbx
  AnimationGroup *v3; // rcx

  v1 = (ResourceOpportunityTask *)((char *)this + 32);
  v2 = (ResourceOpportunityTask *)&this->mNext[-1];
  if ( v2 == (ResourceOpportunityTask *)&this->m_TimeBegin )
    return 1;
  while ( 1 )
  {
    v3 = (AnimationGroup *)v2->mNext;
    if ( !v3 || !AnimationGroup::IsStreamedIn(v3) )
      break;
    v2 = (ResourceOpportunityTask *)&v2->m_Track[-1].mMasterRate.value;
    if ( v2 == v1 )
      return 1;
  }
  return 0;
}

// File Line: 5454
// RVA: 0x30BAB0
void __fastcall ResourceOpportunityVisitor::Visit(ResourceOpportunityVisitor *this, AnimationNode *node)
{
  SkeletalAnimation *v2; // rdi
  ResourceOpportunityTask *v3; // rbx
  bool v4; // zf
  ITrack *v5; // rax
  UFG::eAnimationPriorityEnum v6; // er8
  __int64 v7; // rax
  UFG::qSymbolUC *v8; // rdx

  v2 = node->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  v3 = this->m_pResourceOpportunityTask;
  if ( v2 )
  {
    v4 = UFG::IsAnyLocalPlayer(v3->mContext->mSimObject.m_pPointer) == 0;
    v5 = v3->m_Track;
    if ( v4 )
      v6 = BYTE5(v5[1].mMasterRate.text.mOffset);
    else
      v6 = BYTE4(v5[1].mMasterRate.text.mOffset);
    v7 = v2->m_pAnimationGroup.mOffset;
    if ( v7 )
      v8 = (UFG::qSymbolUC *)((char *)&v2->m_pAnimationGroup + v7);
    else
      v8 = 0i64;
    AnimationGroupHandleContainer::Add(&v3->mAnimationGroupHandleContainer, v8 + 43, v6);
  }
}

// File Line: 5462
// RVA: 0x2E7A70
void __fastcall ResourceOpportunityTask::AddAnimation(ResourceOpportunityTask *this, SkeletalAnimation *pSA)
{
  ResourceOpportunityTask *v2; // rbx
  SkeletalAnimation *v3; // rdi
  bool v4; // zf
  ITrack *v5; // rax
  UFG::eAnimationPriorityEnum v6; // er8
  __int64 v7; // rax
  UFG::qSymbolUC *v8; // rdx

  if ( pSA )
  {
    v2 = this;
    v3 = pSA;
    v4 = UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) == 0;
    v5 = v2->m_Track;
    if ( v4 )
      v6 = BYTE5(v5[1].mMasterRate.text.mOffset);
    else
      v6 = BYTE4(v5[1].mMasterRate.text.mOffset);
    v7 = v3->m_pAnimationGroup.mOffset;
    if ( v7 )
      v8 = (UFG::qSymbolUC *)((char *)&v3->m_pAnimationGroup + v7);
    else
      v8 = 0i64;
    AnimationGroupHandleContainer::Add(&v2->mAnimationGroupHandleContainer, v8 + 43, v6);
  }
}

// File Line: 5481
// RVA: 0x30D230
void __fastcall ResourceOpportunityTask::gatherResources(ResourceOpportunityTask *this)
{
  ResourceOpportunityTask *v1; // r14
  ActionNodePlayable *v2; // rcx
  __int64 v3; // rax
  __int64 v4; // rbp
  signed __int64 v5; // r15
  __int64 v6; // rsi
  UFG::qSymbolUC *v7; // rbx
  bool v8; // zf
  __int64 v9; // rax
  SkeletalAnimation *v10; // rax
  BlendTreeDataBase *v11; // rax
  PoseNode *v12; // rax
  Expression::IMemberMapVtbl *v13; // r8
  void **v14; // [rsp+20h] [rbp-38h]
  char v15; // [rsp+28h] [rbp-30h]
  UFG::qSymbolUC *v16; // [rsp+30h] [rbp-28h]
  ResourceOpportunityTask *v17; // [rsp+38h] [rbp-20h]

  v1 = this;
  v2 = this->mLatchedNode;
  if ( v2 )
  {
    v3 = ((__int64 (*)(void))v2->vfptr[3].GetClassNameUID)();
    v4 = v3;
    if ( v3 )
    {
      v5 = *(_QWORD *)(v3 + 24) + v3 + 24;
      v6 = 0i64;
      if ( *(_DWORD *)(v3 + 16) & 0x7FFFFFFF )
      {
        do
        {
          v7 = (UFG::qSymbolUC *)(v5 + 8 * v6 + *(_QWORD *)(v5 + 8 * v6));
          v8 = (*(unsigned int (__fastcall **)(UFG::qSymbolUC *))(*(_QWORD *)&v7->mUID + 40i64))(v7) == AnimationTrack::sClassNameUID;
          v9 = *(_QWORD *)&v7->mUID;
          if ( v8 )
          {
            v10 = (SkeletalAnimation *)(*(__int64 (__fastcall **)(UFG::qSymbolUC *))(v9 + 128))(v7);
            ResourceOpportunityTask::AddAnimation(v1, v10);
          }
          else if ( (*(unsigned int (__fastcall **)(UFG::qSymbolUC *))(v9 + 40))(v7) == BlendTreeTrack::sClassNameUID )
          {
            v11 = BlendTreeDataBase::GetInstance();
            v12 = BlendTreeDataBase::FindBlendTree(v11, v7 + 16);
            if ( v12 )
            {
              v13 = v12->vfptr;
              v15 = 1;
              v14 = &ResourceOpportunityVisitor::`vftable';
              v16 = v7;
              v17 = v1;
              v13[1].FindWithOldPath((Expression::IMemberMap *)&v12->vfptr, (const char *)&v14);
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
  ResourceOpportunityTask *v1; // rdi
  ActionContext *v2; // rax
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PowerManagementComponent *v5; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v6; // rax
  signed __int64 v7; // rdi
  signed __int64 v8; // rbx
  AnimationGroup *v9; // rcx

  v1 = this;
  if ( !this->mLatchedNodeResourcesGathered )
  {
    ResourceOpportunityTask::gatherResources(this);
    AnimationGroupHandleContainer::Bind(&v1->mAnimationGroupHandleContainer);
    v2 = v1->mContext;
    v1->mLatchedNodeResourcesGathered = 1;
    v3 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v3,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v3,
                                                  UFG::PowerManagementComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v3,
                                                  UFG::PowerManagementComponent::_TypeUID);
        }
        else
        {
          v5 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v3->vfptr,
                                                  UFG::PowerManagementComponent::_TypeUID);
        }
      }
      else
      {
        v5 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v3,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      if ( v5 )
        UFG::PowerManagementComponent::AddPowerManagedResource(v5, (UFG::PowerManagedResource *)&v1->vfptr);
    }
  }
  v6 = v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext;
  v7 = (signed __int64)&v1->mLatchedNode;
  v8 = (signed __int64)&v6[-1];
  if ( &v6[-1] == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v7 )
    return 1;
  while ( 1 )
  {
    v9 = *(AnimationGroup **)(v8 + 56);
    if ( !v9 || !AnimationGroup::IsStreamedIn(v9) )
      break;
    v8 = *(_QWORD *)(v8 + 24) - 16i64;
    if ( v8 == v7 )
      return 1;
  }
  return 0;
}

// File Line: 5584
// RVA: 0x2FFF00
void __fastcall ResourceOpportunityTask::End(ResourceOpportunityTask *this)
{
  ResourceOpportunityTask *v1; // rdi
  bool v2; // zf
  ITrack *v3; // rax
  UFG::eAnimationPriorityEnum priority; // er14
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v5; // rdx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v6; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v7; // rax
  ActionContext *v8; // rcx
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::ActionTreeResourcesComponent *v11; // rsi
  UFG::SimComponent *v12; // rax
  signed __int64 i; // rbx
  int v14; // edx
  ActionPath pathToPopulate; // [rsp+48h] [rbp-30h]

  v1 = this;
  v2 = UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) == 0;
  v3 = v1->m_Track;
  if ( v2 )
    priority = BYTE5(v3[1].mMasterRate.text.mOffset);
  else
    priority = BYTE4(v3[1].mMasterRate.text.mOffset);
  v5 = (UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
  if ( v1->mLatchedNode )
  {
    if ( ResourceOpportunityTask::areResourcesStreamedIn(v1) )
    {
      v8 = v1->mContext;
      if ( v8 )
      {
        v9 = (UFG::SimObjectGame *)v8->mSimObject.m_pPointer;
        if ( v9 )
        {
          v10 = v9->m_Flags;
          if ( (v10 >> 14) & 1 )
          {
            v11 = (UFG::ActionTreeResourcesComponent *)v9->m_Components.p[30].m_pComponent;
          }
          else
          {
            if ( (v10 & 0x8000u) == 0 )
            {
              if ( (v10 >> 13) & 1 )
                v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::ActionTreeResourcesComponent::_TypeUID);
              else
                v12 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v9,
                                          UFG::ActionTreeResourcesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                           (UFG::SimObject *)&v9->vfptr,
                                                                                           UFG::ActionTreeResourcesComponent::_TypeUID);
            }
            else
            {
              v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::ActionTreeResourcesComponent::_TypeUID);
            }
            v11 = (UFG::ActionTreeResourcesComponent *)v12;
          }
          if ( v11 )
          {
            for ( i = (signed __int64)&v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext[-1];
                  (ActionNodePlayable **)i != &v1->mLatchedNode;
                  i = *(_QWORD *)(i + 24) - 16i64 )
            {
              pathToPopulate.mPath.mCount = 0;
              pathToPopulate.mPath.mData.mOffset = 0i64;
              ActionNode::GetNameFullPath((ActionNode *)&v1->mLatchedNode->vfptr, &pathToPopulate);
              UFG::ActionTreeResourcesComponent::RequestAnimationBank(
                v11,
                &pathToPopulate,
                (ActionNode *)&v1->mLatchedNode->vfptr,
                1,
                (UFG::qSymbolUC *)(i + 32),
                priority);
              v14 = pathToPopulate.mPath.mCount;
              if ( pathToPopulate.mPath.mCount >= 0 )
              {
                if ( pathToPopulate.mPath.mData.mOffset )
                {
                  if ( (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData
                                                    + pathToPopulate.mPath.mData.mOffset) )
                  {
                    operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
                    v14 = pathToPopulate.mPath.mCount;
                  }
                }
                pathToPopulate.mPath.mData.mOffset = 0i64;
                pathToPopulate.mPath.mCount = v14 & 0x80000000;
              }
            }
          }
        }
        ActionController::Sequence(
          v1->mContext->mActionController,
          v1->mLatchedNode,
          SLOBYTE(v1->m_Track[1].m_TrackClassNameUID),
          1);
      }
    }
  }
}

