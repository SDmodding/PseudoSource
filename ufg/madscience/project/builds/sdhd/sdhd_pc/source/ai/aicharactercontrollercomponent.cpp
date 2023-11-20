// File Line: 44
// RVA: 0x363410
signed __int64 __fastcall UFG::AICharacterControllerBaseComponent::GetTypeSize(UFG::AICharacterControllerBaseComponent *this)
{
  return 1080i64;
}

// File Line: 51
// RVA: 0x32A960
void __fastcall UFG::AICharacterControllerBaseComponent::AICharacterControllerBaseComponent(UFG::AICharacterControllerBaseComponent *this, unsigned int name_uid)
{
  UFG::AICharacterControllerBaseComponent *v2; // rbx

  v2 = this;
  UFG::CharacterControllerInterface::CharacterControllerInterface(
    (UFG::CharacterControllerInterface *)&this->vfptr,
    name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerBaseComponent::`vftable';
  Intention::Intention(&v2->m_Intention);
  v2->m_ActionRequestMask.mBits[0] = 0i64;
  v2->m_ActionRequestMask.mBits[1] = 0i64;
  v2->m_ActionRequestMask.mBits[2] = 0i64;
  v2->m_ActionRequestMask.mBits[3] = 0i64;
  v2->m_ActionRequestMask.mBits[4] = 0i64;
  v2->m_ActionRequestMask.mBits[5] = 0i64;
  v2->m_ActionRequestMask.mBits[6] = 0i64;
  v2->m_ActionRequestMask.mBits[7] = 0i64;
  v2->m_ActionRequestMask.mBits[8] = 0i64;
  v2->m_HoldMotionIntention = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AICharacterControllerBaseComponent::_AICharacterControllerBaseComponentTypeUID,
    "AICharacterControllerBaseComponent");
  v2->m_ActionRequestMask.mBits[0] = -1i64;
  v2->m_ActionRequestMask.mBits[1] = -1i64;
  v2->m_ActionRequestMask.mBits[2] = -1i64;
  v2->m_ActionRequestMask.mBits[3] = -1i64;
  v2->m_ActionRequestMask.mBits[4] = -1i64;
  v2->m_ActionRequestMask.mBits[5] = -1i64;
  v2->m_ActionRequestMask.mBits[6] = -1i64;
  v2->m_ActionRequestMask.mBits[7] = -1i64;
  v2->m_ActionRequestMask.mBits[8] = -1i64;
}

// File Line: 57
// RVA: 0x333AA0
void __fastcall UFG::AICharacterControllerBaseComponent::~AICharacterControllerBaseComponent(UFG::AICharacterControllerBaseComponent *this)
{
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerBaseComponent::`vftable';
  UFG::CharacterControllerInterface::~CharacterControllerInterface((UFG::CharacterControllerInterface *)&this->vfptr);
}

// File Line: 71
// RVA: 0x378220
void __fastcall UFG::AICharacterControllerBaseComponent::OnAttach(UFG::AICharacterControllerBaseComponent *this, UFG::SimObject *object)
{
  UFG::AICharacterControllerBaseComponent *v2; // rdi
  UFG::SimObject *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = this;
  UFG::CharacterControllerInterface::OnAttach((UFG::CharacterControllerInterface *)&this->vfptr, object);
  v3 = v2->m_pSimObject;
  if ( v3 )
    v3 = (UFG::SimObject *)v3->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
  v4 = *((float *)&v3[1].vfptr + 1);
  v5 = *(float *)&v3[1].m_SafePointerList.mNode.mPrev;
  v2->m_Intention.mMotionIntentionDirection.x = *(float *)&v3[1].vfptr;
  v2->m_Intention.mMotionIntentionDirection.y = v4;
  v2->m_Intention.mMotionIntentionDirection.z = v5;
}

// File Line: 78
// RVA: 0x379880
void __fastcall UFG::AICharacterControllerComponent::OnDetach(UFG::AICharacterControllerComponent *this)
{
  UFG::CharacterControllerInterface::OnDetach((UFG::PropInteractComponent *)this);
}

// File Line: 83
// RVA: 0x349BB0
void __fastcall UFG::AICharacterControllerBaseComponent::BeginFrame(UFG::AICharacterControllerBaseComponent *this)
{
  UFG::AICharacterControllerBaseComponent *v1; // rbx

  v1 = this;
  UFG::AICharacterControllerBaseComponent::ClearIntention(this);
  _((AMD_HD3D *)v1);
}

// File Line: 90
// RVA: 0x34F4F0
void __fastcall UFG::AICharacterControllerBaseComponent::ClearIntention(UFG::AICharacterControllerBaseComponent *this)
{
  _QWORD *v1; // rbx
  UFG::AICharacterControllerBaseComponent *v2; // rdi

  v1 = (_QWORD *)&this->m_Intention.mMotionIntentionSpeedRaw;
  v2 = this;
  Intention::Clear(&this->m_Intention);
  if ( LocalPlayer == (UFG::SimObjectCharacter *)v2->m_pSimObject )
  {
    UFG::UIScreenTextureManager::Instance();
    v1[22] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[0];
    v1[23] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[1];
    v1[24] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[2];
    v1[25] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[3];
    v1[26] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[4];
    v1[27] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[5];
    v1[28] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[6];
    v1[29] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[7];
    v1[30] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[8];
    v1[21] = v1[22] | v1[23] | v1[24] | v1[25] | v1[26] | v1[27] | v1[28] | v1[29] | v1[30];
    UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[0] = 0i64;
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[1] = 0i64;
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[2] = 0i64;
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[3] = 0i64;
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[4] = 0i64;
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[5] = 0i64;
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[6] = 0i64;
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[7] = 0i64;
    UFG::UIScreenTextureManager::m_ActionRequests.mBits[8] = 0i64;
  }
  v2->m_IntentionUpdated = 0;
}

// File Line: 104
// RVA: 0x3899A0
void __fastcall UFG::AICharacterControllerBaseComponent::TeleportEventHandler(UFG::AICharacterControllerBaseComponent *this, UFG::Event *this_event)
{
  UFG::TransformNodeComponent *v2; // rbx
  UFG::AICharacterControllerBaseComponent *v3; // rdi
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v3 = this;
  if ( v2 )
    v2 = (UFG::TransformNodeComponent *)v2->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v2);
  v4 = v2->mWorldTransform.v0.y;
  v5 = v2->mWorldTransform.v0.z;
  v3->m_Intention.mMotionIntentionDirection.x = v2->mWorldTransform.v0.x;
  v3->m_Intention.mMotionIntentionDirection.y = v4;
  v3->m_Intention.mMotionIntentionDirection.z = v5;
}

// File Line: 110
// RVA: 0x36B970
unsigned __int8 __fastcall UFG::AICharacterControllerBaseComponent::IsPerformingAction(UFG::AICharacterControllerBaseComponent *this, const char *actionNode)
{
  UFG::AICharacterControllerBaseComponent *v2; // rbx
  unsigned int v3; // eax
  ActionController *v4; // rcx
  ActionID node_id; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = UFG::qStringHashUpper32(actionNode, 0xFFFFFFFF);
  v4 = (ActionController *)&v2->m_pActionTreeComponent.m_pSimComponent[3];
  node_id.mUID = v3;
  return ActionController::IsPlaying(v4, &node_id, 0xFFFFFFFF, 0);
}

// File Line: 122
// RVA: 0x352DE0
void __fastcall UFG::AICharacterControllerBaseComponent::DoParkour(UFG::AICharacterControllerBaseComponent *this, UFG::qVector3 *direction, const char *vaultingActionNode, unsigned int check, Intention *intention, bool cleanVault)
{
  unsigned int v6; // er15
  UFG::qVector3 *v7; // rsi
  UFG::AICharacterControllerBaseComponent *v8; // r14
  UFG::SimObject *v9; // rdi
  UFG::TransformNodeComponent *v10; // rdi
  UFG::SimObjectGame *v11; // rcx
  UFG::SensorComponent *v12; // rax
  unsigned __int16 v13; // dx
  UFG::ParkourHandle *v14; // rax
  UFG::SimObjectGame *v15; // rcx
  UFG::ParkourHandle *v16; // rbx
  unsigned __int16 v17; // r8
  float v18; // xmm4_4
  __m128 v19; // xmm5
  float v20; // xmm7_4
  __m128 v21; // xmm2
  float v22; // xmm3_4
  float v23; // xmm4_4
  __m128 v24; // xmm5
  float v25; // xmm7_4
  __m128 v26; // xmm2
  float v27; // xmm3_4
  __int64 v28; // r8
  signed __int64 v29; // rdx
  float v30; // xmm0_4
  signed __int64 v31; // rcx
  float v32; // xmm2_4
  __int64 v33; // r8
  signed __int64 v34; // rdx
  signed __int64 v35; // rcx
  float v36; // xmm2_4
  __int64 v37; // r8
  signed __int64 v38; // rdx
  signed __int64 v39; // rcx
  float v40; // xmm2_4
  __int64 v41; // r9
  signed __int64 v42; // r8
  float v43; // xmm2_4
  UFG::TransformNodeComponent *v44; // rbx
  float v45; // xmm3_4
  __m128 v46; // xmm4
  float v47; // xmm5_4
  __m128 v48; // xmm2
  float v49; // xmm8_4
  float v50; // xmm7_4
  float v51; // xmm6_4
  float v52; // xmm8_4
  float v53; // xmm7_4
  unsigned int v54; // xmm7_4
  unsigned int v55; // xmm6_4
  float v56; // xmm8_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  Render::DebugDrawContext *v59; // rax
  UFG::qVector3 *contactPosition; // [rsp+58h] [rbp-80h]
  bool debugMessageActive[4]; // [rsp+60h] [rbp-78h]
  UFG::qColour colour; // [rsp+68h] [rbp-70h]
  Intention other; // [rsp+78h] [rbp-60h]
  int vars0; // [rsp+440h] [rbp+368h]
  Intention *retaddr; // [rsp+448h] [rbp+370h]
  char v66; // [rsp+450h] [rbp+378h]

  v6 = check;
  v7 = direction;
  v8 = this;
  if ( check )
  {
    v9 = this->m_pSimObject;
    if ( v9 )
      v10 = v9->m_pTransformNodeComponent;
    else
      v10 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    v11 = (UFG::SimObjectGame *)v8->m_pSimObject;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v12 = (UFG::SensorComponent *)v11->m_Components.p[26].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v12 = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::SensorComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v12 = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::SensorComponent::_TypeUID);
        }
        else
        {
          v12 = (UFG::SensorComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v11->vfptr,
                                          UFG::SensorComponent::_TypeUID);
        }
      }
      else
      {
        v12 = (UFG::SensorComponent *)v11->m_Components.p[26].m_pComponent;
      }
    }
    else
    {
      v12 = 0i64;
    }
    v14 = ParkourHandleCondition::FindClosestParkourHandle(
            v12,
            (UFG::qVector3 *)&v10->mWorldTransform.v3,
            (UFG::qVector3 *)&v10->mWorldTransform,
            0.78539819,
            0.0,
            0.0,
            3.0,
            -0.5,
            3.0,
            0,
            v6,
            0i64,
            0);
    v15 = (UFG::SimObjectGame *)v8->m_pSimObject;
    v16 = v14;
    if ( v15 )
    {
      v17 = v15->m_Flags;
      if ( !((v17 >> 14) & 1) )
      {
        if ( (v17 & 0x8000u) == 0 )
        {
          if ( (v17 >> 13) & 1 )
          {
            UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::WorldContextComponent::_TypeUID);
          }
          else if ( (v17 >> 12) & 1 )
          {
            UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::WorldContextComponent::_TypeUID);
          }
          else
          {
            UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::WorldContextComponent::_TypeUID);
          }
        }
        else
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::WorldContextComponent::_TypeUID);
        }
      }
    }
    if ( v16 )
    {
      Intention::Clear(retaddr);
      v18 = v7->y;
      v19 = (__m128)LODWORD(v7->x);
      v20 = v7->z;
      v21 = v19;
      v21.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18)) + (float)(v20 * v20);
      if ( v21.m128_f32[0] == 0.0 )
        v22 = 0.0;
      else
        v22 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v21));
      retaddr->mMotionIntentionDirection.z = v22 * v20;
      retaddr->mMotionIntentionDirection.x = v22 * v19.m128_f32[0];
      retaddr->mMotionIntentionDirection.y = v22 * v18;
      retaddr->mMotionIntentionSpeed = 1.6;
      Intention::Set(retaddr, gActionRequest_Jog.m_EnumValue, 234.5);
      Intention::Set(retaddr, gActionRequest_Sprint.m_EnumValue, 234.5);
      if ( v66 )
      {
        Intention::Set(retaddr, gActionRequest_VaultSuccess.m_EnumValue, 0.0);
      }
      else
      {
        Intention::Set(retaddr, gActionRequest_VaultFail.m_EnumValue, 0.0);
        Intention::Set(retaddr, gActionRequest_Freerun.m_EnumValue, 234.5);
      }
    }
  }
  else
  {
    Intention::Intention(&other);
    v23 = v7->y;
    v24 = (__m128)LODWORD(v7->x);
    v25 = v7->z;
    v26 = v24;
    v26.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23)) + (float)(v25 * v25);
    if ( v26.m128_f32[0] == 0.0 )
      v27 = 0.0;
    else
      v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
    v28 = gActionRequest_Walk.m_EnumValue;
    v29 = 1i64 << (gActionRequest_Walk.m_EnumValue & 0x3F);
    other.mMotionIntentionDirection.y = v27 * v23;
    v30 = retaddr->mMotionIntentionSpeed;
    other.mMotionIntentionDirection.z = v27 * v25;
    v31 = (signed __int64)(signed int)gActionRequest_Walk.m_EnumValue >> 6;
    other.mMotionIntentionDirection.x = v27 * v24.m128_f32[0];
    other.mMotionIntentionSpeed = v30;
    if ( v29 & retaddr->mActionRequests.mBits[v31] )
    {
      other.mActionRequests.mBits[v31] |= v29;
      vars0 = 1180424192;
      v32 = (float)(signed int)14070.0;
      if ( v32 >= 255.0 )
        v32 = FLOAT_255_0;
      other.mActionRequestChargeTimes[v28] = (signed int)v32;
      other.mSignals |= v29;
    }
    v33 = gActionRequest_Jog.m_EnumValue;
    v34 = 1i64 << (gActionRequest_Jog.m_EnumValue & 0x3F);
    v35 = (signed __int64)(signed int)gActionRequest_Jog.m_EnumValue >> 6;
    if ( v34 & retaddr->mActionRequests.mBits[v35] )
    {
      other.mActionRequests.mBits[v35] |= v34;
      vars0 = 1180424192;
      v36 = (float)(signed int)14070.0;
      if ( v36 >= 255.0 )
        v36 = FLOAT_255_0;
      other.mActionRequestChargeTimes[v33] = (signed int)v36;
      other.mSignals |= v34;
    }
    v37 = gActionRequest_Sprint.m_EnumValue;
    v38 = 1i64 << (gActionRequest_Sprint.m_EnumValue & 0x3F);
    v39 = (signed __int64)(signed int)gActionRequest_Sprint.m_EnumValue >> 6;
    if ( v38 & retaddr->mActionRequests.mBits[v39] )
    {
      other.mActionRequests.mBits[v39] |= v38;
      vars0 = 1180424192;
      v40 = (float)(signed int)14070.0;
      if ( v40 >= 255.0 )
        v40 = FLOAT_255_0;
      other.mActionRequestChargeTimes[v37] = (signed int)v40;
      other.mSignals |= v38;
    }
    v41 = gActionRequest_Jump.m_EnumValue;
    vars0 = 0;
    v42 = 1i64 << (gActionRequest_Jump.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Jump.m_EnumValue >> 6] |= v42;
    v43 = (float)(signed int)0.0;
    if ( v43 >= 255.0 )
      v43 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v41] = (signed int)v43;
    other.mSignals |= v42;
    Intention::operator=(retaddr, &other);
    v44 = (UFG::TransformNodeComponent *)v8->m_pSimObject;
    if ( v44 )
      v44 = (UFG::TransformNodeComponent *)v44->mChildren.mNode.mNext;
    v45 = v7->y;
    v46 = (__m128)LODWORD(v7->x);
    v48 = v46;
    colour = UFG::qColour::Blue;
    v47 = v7->z;
    v48.m128_f32[0] = (float)((float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v45 * v45)) + (float)(v47 * v47);
    if ( v48.m128_f32[0] == 0.0 )
      v49 = 0.0;
    else
      v49 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v48));
    v50 = v49;
    v51 = v49;
    v52 = v49 * v47;
    v53 = v50 * v46.m128_f32[0];
    UFG::TransformNodeComponent::UpdateWorldTransform(v44);
    *(float *)&v54 = v53 + v44->mWorldTransform.v3.x;
    *(float *)&v55 = (float)(v51 * v45) + v44->mWorldTransform.v3.y;
    v56 = v52 + v44->mWorldTransform.v3.z;
    UFG::TransformNodeComponent::UpdateWorldTransform(v44);
    v57 = v44->mWorldTransform.v3.y;
    colour.b = v44->mWorldTransform.v3.x;
    v58 = v44->mWorldTransform.v3.z;
    colour.a = v57;
    contactPosition = (UFG::qVector3 *)__PAIR__(v55, v54);
    other.mMotionIntentionSpeedRaw = v58 + 0.1;
    *(float *)debugMessageActive = v56 + 0.1;
    v59 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawLine(
      v59,
      (UFG::qVector3 *)&colour.b,
      (UFG::qVector3 *)&contactPosition,
      &colour,
      &UFG::qMatrix44::msIdentity,
      (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
      0);
  }
}

// File Line: 191
// RVA: 0x364FA0
void __fastcall UFG::AICharacterControllerBaseComponent::HoldCurrentMotionIntention(UFG::AICharacterControllerBaseComponent *this)
{
  float v1; // xmm0_4
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // eax

  v1 = this->m_Intention.mMotionIntentionDirection.y;
  v2 = this->m_Intention.mMotionIntentionDirection.z;
  this->m_HoldMotionIntentionDirection.x = this->m_Intention.mMotionIntentionDirection.x;
  this->m_HoldMotionIntentionDirection.y = v1;
  v3 = s_fHoldBlendDelay;
  this->m_HoldMotionIntentionDirection.z = v2;
  v4 = this->m_Intention.mMotionIntentionSpeed;
  this->m_HoldBlend = 0.0;
  this->m_HoldMotionIntention = 1;
  this->m_HoldMotionIntentionSpeed = v4;
  this->m_HoldBlendDelay = v3;
}

// File Line: 202
// RVA: 0x396CA0
void __fastcall UFG::AICharacterControllerBaseComponent::UpdateHoldMotionIntention(UFG::AICharacterControllerBaseComponent *this, const float fDeltaS)
{
  UFG::AICharacterControllerBaseComponent *v2; // rbx
  float v3; // xmm8_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm6_4
  float v8; // xmm11_4
  float v9; // xmm15_4
  float v10; // xmm13_4
  float v11; // xmm14_4
  float v12; // xmm12_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm14_4
  float v19; // xmm15_4
  float v20; // xmm0_4
  float v21; // xmm11_4
  float v22; // xmm12_4
  float v23; // xmm0_4
  float v24; // [rsp+E0h] [rbp+8h]

  v2 = this;
  if ( this->m_HoldMotionIntention )
  {
    v3 = 0.0;
    if ( this->m_Intention.mMotionIntentionSpeed > 0.0 )
    {
      v4 = this->m_HoldBlendDelay - fDeltaS;
      if ( v4 < 0.0 )
        v4 = 0.0;
      this->m_HoldBlendDelay = v4;
      if ( v4 <= 0.0 )
      {
        if ( _S4_6 & 1 )
        {
          v7 = s_fFinishedThreshold;
        }
        else
        {
          _S4_6 |= 1u;
          v7 = FLOAT_0_52359879;
          s_fFinishedThreshold = FLOAT_0_52359879;
        }
        v8 = this->m_HoldMotionIntentionDirection.y;
        v9 = this->m_Intention.mMotionIntentionDirection.y;
        v10 = this->m_HoldMotionIntentionDirection.x;
        v11 = this->m_Intention.mMotionIntentionDirection.x;
        v12 = this->m_HoldMotionIntentionDirection.z;
        v13 = (float)((float)(this->m_Intention.mMotionIntentionDirection.x * v10)
                    + (float)(this->m_Intention.mMotionIntentionDirection.y * v8))
            + (float)(this->m_Intention.mMotionIntentionDirection.z * v12);
        if ( v13 <= 1.0 && v13 >= -1.0 )
        {
          UFG::qACos(v13);
          v3 = v13;
        }
        if ( COERCE_FLOAT(LODWORD(v3) & _xmm) <= v7 )
        {
          v2->m_HoldMotionIntention = 0;
        }
        else
        {
          v14 = sinf(v3);
          v15 = v2->m_HoldBlend;
          v16 = 1.0 / v14;
          v17 = sinf(v2->m_HoldBlend * v3) * (float)(1.0 / v14);
          v18 = v11 * v17;
          v19 = v9 * v17;
          v24 = v2->m_Intention.mMotionIntentionDirection.z * v17;
          v20 = sinf((float)(1.0 - v15) * v3) * v16;
          v21 = (float)(v8 * v20) + v19;
          v22 = (float)(v12 * v20) + v24;
          v2->m_Intention.mMotionIntentionDirection.x = (float)(v10 * v20) + v18;
          v2->m_Intention.mMotionIntentionDirection.y = v21;
          v2->m_Intention.mMotionIntentionDirection.z = v22;
          v2->m_HoldMotionIntentionDirection.x = v2->m_Intention.mMotionIntentionDirection.x;
          v2->m_HoldMotionIntentionDirection.y = v21;
          v2->m_HoldMotionIntentionDirection.z = v22;
          v2->m_HoldMotionIntentionSpeed = v2->m_Intention.mMotionIntentionSpeed;
        }
        v23 = (float)((float)((float)(3.1415927 - COERCE_FLOAT(LODWORD(v3) & _xmm)) * 0.31830987)
                    * s_fTransitionBlendRate)
            + v2->m_HoldBlend;
        v2->m_HoldBlend = v23;
        if ( v23 >= 1.0 )
          v2->m_HoldMotionIntention = 0;
      }
      else
      {
        v5 = this->m_HoldMotionIntentionDirection.y;
        v6 = this->m_HoldMotionIntentionDirection.z;
        this->m_Intention.mMotionIntentionDirection.x = this->m_HoldMotionIntentionDirection.x;
        this->m_Intention.mMotionIntentionDirection.y = v5;
        this->m_Intention.mMotionIntentionDirection.z = v6;
        this->m_Intention.mMotionIntentionSpeed = this->m_HoldMotionIntentionSpeed;
      }
    }
    else
    {
      this->m_HoldMotionIntention = 0;
    }
  }
}

// File Line: 263
// RVA: 0x14AE9E0
__int64 dynamic_initializer_for__UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList__);
}

// File Line: 264
// RVA: 0x35D890
UFG::ComponentIDDesc *__fastcall UFG::AICharacterControllerComponent::GetDesc(UFG::AICharacterControllerComponent *this)
{
  return &UFG::AICharacterControllerComponent::_TypeIDesc;
}

// File Line: 270
// RVA: 0x32AA60
void __fastcall UFG::AICharacterControllerComponent::AICharacterControllerComponent(UFG::AICharacterControllerComponent *this, unsigned int name_uid)
{
  UFG::AICharacterControllerComponent *v2; // rbx
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v3; // rdx
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v4; // rax
  char v5; // cl

  v2 = this;
  UFG::AICharacterControllerBaseComponent::AICharacterControllerBaseComponent(
    (UFG::AICharacterControllerBaseComponent *)&this->vfptr,
    name_uid);
  v3 = (UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerComponent::`vftable';
  v2->m_ControllerID = 0;
  v2->m_ControllerID_Init = 0;
  v4 = UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList.mNode.mPrev;
  UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *)&UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList;
  UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList.mNode.mPrev = (UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AICharacterControllerComponent::_AICharacterControllerComponentTypeUID,
    "AICharacterControllerComponent");
  *(_WORD *)&v2->m_ResetMotionIntention = 0;
  v5 = isRegistered;
  if ( !isRegistered )
    v5 = 1;
  isRegistered = v5;
}

// File Line: 291
// RVA: 0x37E850
UFG::qPropertySet *__fastcall UFG::AICharacterControllerComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *result; // rax
  UFG::qMemoryPool *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObject *v9; // rdx
  unsigned __int16 v10; // cx
  unsigned int v11; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  if ( required )
    goto LABEL_15;
  v3 = pSceneObj->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  result = UFG::qPropertySet::GetParentFromName(
             v3,
             (UFG::qSymbol *)&SimSymX_propset_componentAICharacterController.mUID,
             DEPTH_RECURSE);
  if ( result )
  {
LABEL_15:
    v5 = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(v5, 0x450ui64, "AICharacterControllerComponent", 0i64, 1u);
    if ( v6 )
    {
      UFG::AICharacterControllerComponent::AICharacterControllerComponent(
        (UFG::AICharacterControllerComponent *)v6,
        v2->m_NameUID);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v9 = v2->m_pSimObject;
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 || (v10 & 0x8000u) != 0 )
      v11 = 21;
    else
      v11 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v12, v9, 1);
    UFG::SimObjectModifier::AttachComponent(&v12, v8, v11);
    UFG::SimObjectModifier::Close(&v12);
    UFG::SimObjectModifier::~SimObjectModifier(&v12);
    result = (UFG::qPropertySet *)v8;
  }
  return result;
}

// File Line: 306
// RVA: 0x333AD0
void __fastcall UFG::AICharacterControllerComponent::~AICharacterControllerComponent(UFG::AICharacterControllerComponent *this)
{
  UFG::AICharacterControllerComponent *v1; // r8
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v2; // rdx
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v3; // rcx
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v4; // rax
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v5; // rcx
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerComponent::`vftable';
  if ( this == UFG::AICharacterControllerComponent::s_AICharacterControllerComponentpCurrentIterator )
    UFG::AICharacterControllerComponent::s_AICharacterControllerComponentpCurrentIterator = (UFG::AICharacterControllerComponent *)&this->mPrev[-68].mNext;
  v2 = (UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *)&this->mPrev;
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
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerBaseComponent::`vftable';
  UFG::CharacterControllerInterface::~CharacterControllerInterface((UFG::CharacterControllerInterface *)&v1->vfptr);
}

// File Line: 311
// RVA: 0x378280
void __fastcall UFG::AICharacterControllerComponent::OnAttach(UFG::AICharacterControllerComponent *this, UFG::SimObject *object)
{
  UFG::AICharacterControllerComponent *v2; // rdi
  UFG::SimObject *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = this;
  UFG::CharacterControllerInterface::OnAttach((UFG::CharacterControllerInterface *)&this->vfptr, object);
  v3 = v2->m_pSimObject;
  if ( v3 )
    v3 = (UFG::SimObject *)v3->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
  v4 = *((float *)&v3[1].vfptr + 1);
  v5 = *(float *)&v3[1].m_SafePointerList.mNode.mPrev;
  v2->m_Intention.mMotionIntentionDirection.x = *(float *)&v3[1].vfptr;
  v2->m_Intention.mMotionIntentionDirection.y = v4;
  v2->m_Intention.mMotionIntentionDirection.z = v5;
  v2->m_ControllerID_Init = 1;
}

// File Line: 337
// RVA: 0x38B040
void __fastcall UFG::AICharacterControllerComponent::Update(UFG::AICharacterControllerComponent *this, float delta_sec)
{
  UFG::AICharacterControllerComponent *v2; // rdi
  UFG::SimObjectCharacter *v3; // rax
  _QWORD *v4; // rbx
  UFG::SimObject *v5; // r8
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // r9
  UFG::SimComponent *v8; // rax
  bool v9; // zf
  UFG::SimObjectGame *v10; // rcx
  __int64 v11; // r8
  unsigned int v12; // er10
  signed __int64 v13; // rdx
  signed __int64 v14; // rax
  float v15; // xmm1_4
  Intention intention; // [rsp+20h] [rbp-358h]

  v2 = this;
  if ( !UFG::AICharacterControllerComponent::s_AIEnabled )
  {
    v3 = (UFG::SimObjectCharacter *)this->m_pSimObject;
    if ( !v3 || v3 != LocalPlayer )
    {
      Intention::Intention(&intention);
      *(__m128 *)&intention.mMotionIntentionSpeed = _xmm;
      UFG::CharacterControllerInterface::SetIntentionOnActionTreeComponent(
        (UFG::CharacterControllerInterface *)&v2->vfptr,
        &intention);
    }
  }
  v2->m_IntentionUpdated = 1;
  v4 = (_QWORD *)&v2->m_Intention.mMotionIntentionSpeedRaw;
  v4[22] &= v2->m_ActionRequestMask.mBits[0];
  v4[23] &= v2->m_ActionRequestMask.mBits[1];
  v4[24] &= v2->m_ActionRequestMask.mBits[2];
  v4[25] &= v2->m_ActionRequestMask.mBits[3];
  v4[26] &= v2->m_ActionRequestMask.mBits[4];
  v4[27] &= v2->m_ActionRequestMask.mBits[5];
  v4[28] &= v2->m_ActionRequestMask.mBits[6];
  v4[29] &= v2->m_ActionRequestMask.mBits[7];
  v4[30] &= v2->m_ActionRequestMask.mBits[8];
  v4[21] = v2->m_Intention.mActionRequests.mBits[0] | v2->m_Intention.mActionRequests.mBits[1] | v2->m_Intention.mActionRequests.mBits[2] | v2->m_Intention.mActionRequests.mBits[3] | v2->m_Intention.mActionRequests.mBits[4] | v2->m_Intention.mActionRequests.mBits[5] | v2->m_Intention.mActionRequests.mBits[6] | v2->m_Intention.mActionRequests.mBits[7] | v2->m_Intention.mActionRequests.mBits[8];
  v5 = v2->m_pSimObject;
  if ( v5 )
  {
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[5].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)v2->m_pSimObject,
               UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else
      {
        v9 = ((v6 >> 12) & 1) == 0;
        v10 = (UFG::SimObjectGame *)v2->m_pSimObject;
        v8 = v9 ? UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v10->vfptr,
                    UFG::AIScriptInterfaceComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v10,
                                                                   UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      v7 = v8;
    }
    else
    {
      v7 = v5->m_Components.p[5].m_pComponent;
    }
    if ( v7 && (_QWORD)v7[32].m_BoundComponentHandles.mNode.mPrev & 8 )
    {
      v11 = 0i64;
      v12 = (gActionRequestEnum.m_enumLists.size & 0x80000000) != 0 ? 0 : (*gActionRequestEnum.m_enumLists.p)->m_enumName.size;
      v13 = 1i64;
      if ( v12 )
      {
        do
        {
          v14 = (signed __int64)(signed int)v11 >> 6;
          if ( v13 & (_QWORD)*(&v7[9].m_BoundComponentHandles.mNode.mPrev + v14) )
          {
            v4[v14 + 22] |= v13;
            v15 = (float)(signed int)0.0;
            if ( v15 >= 255.0 )
              v15 = FLOAT_255_0;
            *((_BYTE *)v4 + v11 + 248) = (signed int)v15;
            v2->m_Intention.mSignals |= v13;
          }
          v13 = __ROL8__(v13, 1);
          v11 = (unsigned int)(v11 + 1);
        }
        while ( (unsigned int)v11 < v12 );
      }
    }
  }
  UFG::CharacterControllerInterface::SetIntentionOnActionTreeComponent(
    (UFG::CharacterControllerInterface *)&v2->vfptr,
    &v2->m_Intention);
}

