// File Line: 44
// RVA: 0x363410
__int64 __fastcall UFG::AICharacterControllerBaseComponent::GetTypeSize(UFG::AICharacterControllerBaseComponent *this)
{
  return 1080i64;
}

// File Line: 51
// RVA: 0x32A960
void __fastcall UFG::AICharacterControllerBaseComponent::AICharacterControllerBaseComponent(
        UFG::AICharacterControllerBaseComponent *this,
        unsigned int name_uid)
{
  UFG::CharacterControllerInterface::CharacterControllerInterface(this, name_uid);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerBaseComponent::`vftable;
  Intention::Intention(&this->m_Intention);
  this->m_ActionRequestMask.mBits[0] = 0i64;
  this->m_ActionRequestMask.mBits[1] = 0i64;
  this->m_ActionRequestMask.mBits[2] = 0i64;
  this->m_ActionRequestMask.mBits[3] = 0i64;
  this->m_ActionRequestMask.mBits[4] = 0i64;
  this->m_ActionRequestMask.mBits[5] = 0i64;
  this->m_ActionRequestMask.mBits[6] = 0i64;
  this->m_ActionRequestMask.mBits[7] = 0i64;
  this->m_ActionRequestMask.mBits[8] = 0i64;
  this->m_HoldMotionIntention = 0;
  UFG::SimComponent::AddType(
    this,
    UFG::AICharacterControllerBaseComponent::_AICharacterControllerBaseComponentTypeUID,
    "AICharacterControllerBaseComponent");
  this->m_ActionRequestMask.mBits[0] = -1i64;
  this->m_ActionRequestMask.mBits[1] = -1i64;
  this->m_ActionRequestMask.mBits[2] = -1i64;
  this->m_ActionRequestMask.mBits[3] = -1i64;
  this->m_ActionRequestMask.mBits[4] = -1i64;
  this->m_ActionRequestMask.mBits[5] = -1i64;
  this->m_ActionRequestMask.mBits[6] = -1i64;
  this->m_ActionRequestMask.mBits[7] = -1i64;
  this->m_ActionRequestMask.mBits[8] = -1i64;
}

// File Line: 57
// RVA: 0x333AA0
void __fastcall UFG::AICharacterControllerBaseComponent::~AICharacterControllerBaseComponent(
        UFG::AICharacterControllerBaseComponent *this)
{
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerBaseComponent::`vftable;
  UFG::CharacterControllerInterface::~CharacterControllerInterface(this);
}

// File Line: 71
// RVA: 0x378220
void __fastcall UFG::AICharacterControllerBaseComponent::OnAttach(
        UFG::AICharacterControllerBaseComponent *this,
        UFG::SimObject *object)
{
  UFG::SimObject *m_pSimObject; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4

  UFG::CharacterControllerInterface::OnAttach(this, object);
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  v4 = *((float *)&m_pSimObject[1].vfptr + 1);
  v5 = *(float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
  this->m_Intention.mMotionIntentionDirection.x = *(float *)&m_pSimObject[1].vfptr;
  this->m_Intention.mMotionIntentionDirection.y = v4;
  this->m_Intention.mMotionIntentionDirection.z = v5;
}

// File Line: 78
// RVA: 0x379880
// attributes: thunk
void __fastcall UFG::AICharacterControllerComponent::OnDetach(UFG::AICharacterControllerComponent *this)
{
  UFG::CharacterControllerInterface::OnDetach((UFG::PropInteractComponent *)this);
}

// File Line: 83
// RVA: 0x349BB0
void __fastcall UFG::AICharacterControllerBaseComponent::BeginFrame(UFG::AICharacterControllerBaseComponent *this)
{
  UFG::AICharacterControllerBaseComponent::ClearIntention(this);
  _((AMD_HD3D *)this);
}

// File Line: 90
// RVA: 0x34F4F0
void __fastcall UFG::AICharacterControllerBaseComponent::ClearIntention(UFG::AICharacterControllerBaseComponent *this)
{
  Intention *p_m_Intention; // rbx

  p_m_Intention = &this->m_Intention;
  Intention::Clear(&this->m_Intention);
  if ( LocalPlayer == this->m_pSimObject )
  {
    UFG::UIScreenTextureManager::Instance();
    p_m_Intention->mActionRequests.mBits[0] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[0];
    p_m_Intention->mActionRequests.mBits[1] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[1];
    p_m_Intention->mActionRequests.mBits[2] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[2];
    p_m_Intention->mActionRequests.mBits[3] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[3];
    p_m_Intention->mActionRequests.mBits[4] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[4];
    p_m_Intention->mActionRequests.mBits[5] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[5];
    p_m_Intention->mActionRequests.mBits[6] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[6];
    p_m_Intention->mActionRequests.mBits[7] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[7];
    p_m_Intention->mActionRequests.mBits[8] |= UFG::UIScreenTextureManager::m_ActionRequests.mBits[8];
    p_m_Intention->mSignals = p_m_Intention->mActionRequests.mBits[0] | p_m_Intention->mActionRequests.mBits[1] | p_m_Intention->mActionRequests.mBits[2] | p_m_Intention->mActionRequests.mBits[3] | p_m_Intention->mActionRequests.mBits[4] | p_m_Intention->mActionRequests.mBits[5] | p_m_Intention->mActionRequests.mBits[6] | p_m_Intention->mActionRequests.mBits[7] | p_m_Intention->mActionRequests.mBits[8];
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
  this->m_IntentionUpdated = 0;
}

// File Line: 104
// RVA: 0x3899A0
void __fastcall UFG::AICharacterControllerBaseComponent::TeleportEventHandler(
        UFG::AICharacterControllerBaseComponent *this,
        UFG::Event *this_event)
{
  UFG::TransformNodeComponent *m_pSimObject; // rbx
  float y; // xmm0_4
  float z; // xmm1_4

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  y = m_pSimObject->mWorldTransform.v0.y;
  z = m_pSimObject->mWorldTransform.v0.z;
  this->m_Intention.mMotionIntentionDirection.x = m_pSimObject->mWorldTransform.v0.x;
  this->m_Intention.mMotionIntentionDirection.y = y;
  this->m_Intention.mMotionIntentionDirection.z = z;
}

// File Line: 110
// RVA: 0x36B970
unsigned __int8 __fastcall UFG::AICharacterControllerBaseComponent::IsPerformingAction(
        UFG::AICharacterControllerBaseComponent *this,
        const char *actionNode)
{
  unsigned int v3; // eax
  ActionController *v4; // rcx
  ActionID node_id; // [rsp+30h] [rbp+8h] BYREF

  v3 = UFG::qStringHashUpper32(actionNode, -1);
  v4 = (ActionController *)&this->m_pActionTreeComponent.m_pSimComponent[3];
  node_id.mUID = v3;
  return ActionController::IsPlaying(v4, &node_id, 0xFFFFFFFF, 0);
}

// File Line: 122
// RVA: 0x352DE0
void __fastcall UFG::AICharacterControllerBaseComponent::DoParkour(
        UFG::AICharacterControllerBaseComponent *this,
        UFG::qVector3 *direction,
        const char *vaultingActionNode,
        unsigned int check,
        Intention *intention,
        bool cleanVault)
{
  char v6; // di
  UFG::SimObject *m_pSimObject; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimObjectGame *v12; // rcx
  UFG::SensorComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  UFG::ParkourHandle *ClosestParkourHandle; // rax
  UFG::SimObjectGame *v16; // rcx
  UFG::ParkourHandle *v17; // rbx
  __int16 v18; // r8
  float y; // xmm4_4
  __m128 x_low; // xmm5
  float z; // xmm7_4
  __m128 v22; // xmm2
  float v23; // xmm3_4
  float v24; // xmm4_4
  __m128 v25; // xmm5
  float v26; // xmm7_4
  __m128 v27; // xmm2
  float v28; // xmm3_4
  __int64 m_EnumValue; // r8
  __int64 v30; // rdx
  float mMotionIntentionSpeed; // xmm0_4
  __int64 v32; // rcx
  float v33; // xmm2_4
  __int64 v34; // r8
  __int64 v35; // rdx
  __int64 v36; // rcx
  float v37; // xmm2_4
  __int64 v38; // r8
  __int64 v39; // rdx
  __int64 v40; // rcx
  float v41; // xmm2_4
  __int64 v42; // r9
  __int64 v43; // r8
  float v44; // xmm2_4
  UFG::TransformNodeComponent *mNext; // rbx
  float v46; // xmm3_4
  __m128 v47; // xmm4
  float v48; // xmm5_4
  __m128 v49; // xmm2
  float v50; // xmm8_4
  float v51; // xmm7_4
  float v52; // xmm6_4
  float v53; // xmm8_4
  float v54; // xmm7_4
  float v55; // xmm7_4
  float v56; // xmm6_4
  float v57; // xmm8_4
  float v58; // xmm1_4
  float v59; // xmm0_4
  Render::DebugDrawContext *Context; // rax
  UFG::qVector3 contactPosition; // [rsp+58h] [rbp-80h] BYREF
  UFG::qColour colour; // [rsp+68h] [rbp-70h] BYREF
  Intention other; // [rsp+78h] [rbp-60h] BYREF
  int vars0; // [rsp+440h] [rbp+368h]
  Intention *retaddr; // [rsp+448h] [rbp+370h]
  char v66; // [rsp+450h] [rbp+378h]

  if ( check )
  {
    v66 = v6;
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v12 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v12 )
    {
      m_Flags = v12->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::SensorComponent *)v12->m_Components.p[26].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::SensorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v12,
                                                   UFG::SensorComponent::_TypeUID);
        else
          m_pComponent = (UFG::SensorComponent *)UFG::SimObject::GetComponentOfType(v12, UFG::SensorComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::SensorComponent *)v12->m_Components.p[26].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    ClosestParkourHandle = ParkourHandleCondition::FindClosestParkourHandle(
                             m_pComponent,
                             (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                             (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform,
                             0.78539819,
                             0.0,
                             0.0,
                             3.0,
                             -0.5,
                             3.0,
                             eSIM_OBJ_VEHICLE_TYPE_INVALID,
                             check,
                             0i64,
                             0);
    v16 = (UFG::SimObjectGame *)this->m_pSimObject;
    v17 = ClosestParkourHandle;
    if ( v16 )
    {
      v18 = v16->m_Flags;
      if ( (v18 & 0x4000) == 0 )
      {
        if ( v18 < 0 || (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
          UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::WorldContextComponent::_TypeUID);
        else
          UFG::SimObject::GetComponentOfType(v16, UFG::WorldContextComponent::_TypeUID);
      }
    }
    if ( v17 )
    {
      Intention::Clear(retaddr);
      y = direction->y;
      x_low = (__m128)LODWORD(direction->x);
      z = direction->z;
      v22 = x_low;
      v22.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
      if ( v22.m128_f32[0] == 0.0 )
        v23 = 0.0;
      else
        v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
      retaddr->mMotionIntentionDirection.z = v23 * z;
      retaddr->mMotionIntentionDirection.x = v23 * x_low.m128_f32[0];
      retaddr->mMotionIntentionDirection.y = v23 * y;
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
    v24 = direction->y;
    v25 = (__m128)LODWORD(direction->x);
    v26 = direction->z;
    v27 = v25;
    v27.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24)) + (float)(v26 * v26);
    if ( v27.m128_f32[0] == 0.0 )
      v28 = 0.0;
    else
      v28 = 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
    m_EnumValue = gActionRequest_Walk.m_EnumValue;
    v30 = 1i64 << (gActionRequest_Walk.m_EnumValue & 0x3F);
    other.mMotionIntentionDirection.y = v28 * v24;
    mMotionIntentionSpeed = retaddr->mMotionIntentionSpeed;
    other.mMotionIntentionDirection.z = v28 * v26;
    v32 = (__int64)(int)gActionRequest_Walk.m_EnumValue >> 6;
    other.mMotionIntentionDirection.x = v28 * v25.m128_f32[0];
    other.mMotionIntentionSpeed = mMotionIntentionSpeed;
    if ( (v30 & retaddr->mActionRequests.mBits[v32]) != 0 )
    {
      other.mActionRequests.mBits[v32] |= v30;
      vars0 = 1180424192;
      v33 = (float)(int)14070.0;
      if ( v33 >= 255.0 )
        v33 = FLOAT_255_0;
      other.mActionRequestChargeTimes[m_EnumValue] = (int)v33;
      other.mSignals |= v30;
    }
    v34 = gActionRequest_Jog.m_EnumValue;
    v35 = 1i64 << (gActionRequest_Jog.m_EnumValue & 0x3F);
    v36 = (__int64)(int)gActionRequest_Jog.m_EnumValue >> 6;
    if ( (v35 & retaddr->mActionRequests.mBits[v36]) != 0 )
    {
      other.mActionRequests.mBits[v36] |= v35;
      vars0 = 1180424192;
      v37 = (float)(int)14070.0;
      if ( v37 >= 255.0 )
        v37 = FLOAT_255_0;
      other.mActionRequestChargeTimes[v34] = (int)v37;
      other.mSignals |= v35;
    }
    v38 = gActionRequest_Sprint.m_EnumValue;
    v39 = 1i64 << (gActionRequest_Sprint.m_EnumValue & 0x3F);
    v40 = (__int64)(int)gActionRequest_Sprint.m_EnumValue >> 6;
    if ( (v39 & retaddr->mActionRequests.mBits[v40]) != 0 )
    {
      other.mActionRequests.mBits[v40] |= v39;
      vars0 = 1180424192;
      v41 = (float)(int)14070.0;
      if ( v41 >= 255.0 )
        v41 = FLOAT_255_0;
      other.mActionRequestChargeTimes[v38] = (int)v41;
      other.mSignals |= v39;
    }
    v42 = gActionRequest_Jump.m_EnumValue;
    vars0 = 0;
    v43 = 1i64 << (gActionRequest_Jump.m_EnumValue & 0x3F);
    other.mActionRequests.mBits[(__int64)(int)gActionRequest_Jump.m_EnumValue >> 6] |= v43;
    v44 = (float)(int)0.0;
    if ( v44 >= 255.0 )
      v44 = FLOAT_255_0;
    other.mActionRequestChargeTimes[v42] = (int)v44;
    other.mSignals |= v43;
    Intention::operator=(retaddr, &other);
    mNext = (UFG::TransformNodeComponent *)this->m_pSimObject;
    if ( mNext )
      mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
    v46 = direction->y;
    v47 = (__m128)LODWORD(direction->x);
    v49 = v47;
    colour = UFG::qColour::Blue;
    v48 = direction->z;
    v49.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v46 * v46)) + (float)(v48 * v48);
    if ( v49.m128_f32[0] == 0.0 )
      v50 = 0.0;
    else
      v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
    v51 = v50;
    v52 = v50;
    v53 = v50 * v48;
    v54 = v51 * v47.m128_f32[0];
    UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
    v55 = v54 + mNext->mWorldTransform.v3.x;
    v56 = (float)(v52 * v46) + mNext->mWorldTransform.v3.y;
    v57 = v53 + mNext->mWorldTransform.v3.z;
    UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
    v58 = mNext->mWorldTransform.v3.y;
    colour.b = mNext->mWorldTransform.v3.x;
    v59 = mNext->mWorldTransform.v3.z;
    colour.a = v58;
    contactPosition.x = v55;
    contactPosition.y = v56;
    other.mMotionIntentionSpeedRaw = v59 + 0.1;
    contactPosition.z = v57 + 0.1;
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawLine(
      Context,
      (UFG::qVector3 *)&colour.b,
      &contactPosition,
      &colour,
      &UFG::qMatrix44::msIdentity,
      (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
      0);
  }
}

// File Line: 191
// RVA: 0x364FA0
void __fastcall UFG::AICharacterControllerBaseComponent::HoldCurrentMotionIntention(
        UFG::AICharacterControllerBaseComponent *this)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v3; // xmm0_4
  float mMotionIntentionSpeed; // eax

  y = this->m_Intention.mMotionIntentionDirection.y;
  z = this->m_Intention.mMotionIntentionDirection.z;
  this->m_HoldMotionIntentionDirection.x = this->m_Intention.mMotionIntentionDirection.x;
  this->m_HoldMotionIntentionDirection.y = y;
  v3 = s_fHoldBlendDelay;
  this->m_HoldMotionIntentionDirection.z = z;
  mMotionIntentionSpeed = this->m_Intention.mMotionIntentionSpeed;
  this->m_HoldBlend = 0.0;
  this->m_HoldMotionIntention = 1;
  this->m_HoldMotionIntentionSpeed = mMotionIntentionSpeed;
  this->m_HoldBlendDelay = v3;
}

// File Line: 202
// RVA: 0x396CA0
void __fastcall UFG::AICharacterControllerBaseComponent::UpdateHoldMotionIntention(
        UFG::AICharacterControllerBaseComponent *this,
        const float fDeltaS)
{
  float v3; // xmm8_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm6_4
  float y; // xmm11_4
  float v9; // xmm15_4
  float x; // xmm13_4
  float v11; // xmm14_4
  float z; // xmm12_4
  double v13; // xmm0_8
  double v14; // xmm0_8
  float v15; // xmm0_4
  float m_HoldBlend; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float v19; // xmm14_4
  float v20; // xmm15_4
  float v21; // xmm0_4
  float v22; // xmm11_4
  float v23; // xmm12_4
  float v24; // xmm0_4
  float v25; // [rsp+E0h] [rbp+8h]

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
        if ( (_S4_6 & 1) != 0 )
        {
          v7 = s_fFinishedThreshold;
        }
        else
        {
          _S4_6 |= 1u;
          v7 = FLOAT_0_52359879;
          s_fFinishedThreshold = FLOAT_0_52359879;
        }
        y = this->m_HoldMotionIntentionDirection.y;
        v9 = this->m_Intention.mMotionIntentionDirection.y;
        x = this->m_HoldMotionIntentionDirection.x;
        v11 = this->m_Intention.mMotionIntentionDirection.x;
        z = this->m_HoldMotionIntentionDirection.z;
        *(_QWORD *)&v13 = LODWORD(v11);
        *(float *)&v13 = (float)((float)(v11 * x) + (float)(v9 * y))
                       + (float)(this->m_Intention.mMotionIntentionDirection.z * z);
        if ( *(float *)&v13 <= 1.0 && *(float *)&v13 >= -1.0 )
        {
          v14 = UFG::qACos(v13);
          v3 = *(float *)&v14;
        }
        if ( COERCE_FLOAT(LODWORD(v3) & _xmm) <= v7 )
        {
          this->m_HoldMotionIntention = 0;
        }
        else
        {
          v15 = sinf(v3);
          m_HoldBlend = this->m_HoldBlend;
          v17 = 1.0 / v15;
          v18 = sinf(m_HoldBlend * v3) * (float)(1.0 / v15);
          v19 = v11 * v18;
          v20 = v9 * v18;
          v25 = this->m_Intention.mMotionIntentionDirection.z * v18;
          v21 = sinf((float)(1.0 - m_HoldBlend) * v3) * v17;
          v22 = (float)(y * v21) + v20;
          v23 = (float)(z * v21) + v25;
          this->m_Intention.mMotionIntentionDirection.x = (float)(x * v21) + v19;
          this->m_Intention.mMotionIntentionDirection.y = v22;
          this->m_Intention.mMotionIntentionDirection.z = v23;
          this->m_HoldMotionIntentionDirection.x = this->m_Intention.mMotionIntentionDirection.x;
          this->m_HoldMotionIntentionDirection.y = v22;
          this->m_HoldMotionIntentionDirection.z = v23;
          this->m_HoldMotionIntentionSpeed = this->m_Intention.mMotionIntentionSpeed;
        }
        v24 = (float)((float)((float)(3.1415927 - COERCE_FLOAT(LODWORD(v3) & _xmm)) * 0.31830987)
                    * s_fTransitionBlendRate)
            + this->m_HoldBlend;
        this->m_HoldBlend = v24;
        if ( v24 >= 1.0 )
          this->m_HoldMotionIntention = 0;
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList__);
}

// File Line: 264
// RVA: 0x35D890
UFG::ComponentIDDesc *__fastcall UFG::AICharacterControllerComponent::GetDesc(
        UFG::AICharacterControllerComponent *this)
{
  return &UFG::AICharacterControllerComponent::_TypeIDesc;
}

// File Line: 270
// RVA: 0x32AA60
void __fastcall UFG::AICharacterControllerComponent::AICharacterControllerComponent(
        UFG::AICharacterControllerComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *mPrev; // rax
  char v4; // cl

  UFG::AICharacterControllerBaseComponent::AICharacterControllerBaseComponent(this, name_uid);
  this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>::mPrev = &this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>;
  this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>::mNext = &this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerComponent::`vftable;
  this->m_ControllerID = 0;
  this->m_ControllerID_Init = 0;
  mPrev = UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList.mNode.mPrev;
  UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>;
  this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>::mNext = (UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *)&UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList;
  UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::AICharacterControllerComponent::_AICharacterControllerComponentTypeUID,
    "AICharacterControllerComponent");
  *(_WORD *)&this->m_ResetMotionIntention = 0;
  v4 = isRegistered;
  if ( !isRegistered )
    v4 = 1;
  isRegistered = v4;
}

// File Line: 291
// RVA: 0x37E850
UFG::qPropertySet *__fastcall UFG::AICharacterControllerComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *result; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v11; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  if ( required )
    goto LABEL_5;
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  result = UFG::qPropertySet::GetParentFromName(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAICharacterController,
             DEPTH_RECURSE);
  if ( result )
  {
LABEL_5:
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x450ui64, "AICharacterControllerComponent", 0i64, 1u);
    if ( v6 )
    {
      UFG::AICharacterControllerComponent::AICharacterControllerComponent(
        (UFG::AICharacterControllerComponent *)v6,
        pSceneObj->m_NameUID);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    m_pSimObject = pSceneObj->m_pSimObject;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v11 = 21;
    else
      v11 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v12, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v12, v8, v11);
    UFG::SimObjectModifier::Close(&v12);
    UFG::SimObjectModifier::~SimObjectModifier(&v12);
    return (UFG::qPropertySet *)v8;
  }
  return result;
}

// File Line: 306
// RVA: 0x333AD0
void __fastcall UFG::AICharacterControllerComponent::~AICharacterControllerComponent(
        UFG::AICharacterControllerComponent *this)
{
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v2; // rdx
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *mPrev; // rcx
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *mNext; // rax
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v5; // rcx
  UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerComponent::`vftable;
  if ( this == UFG::AICharacterControllerComponent::s_AICharacterControllerComponentpCurrentIterator )
    UFG::AICharacterControllerComponent::s_AICharacterControllerComponentpCurrentIterator = (UFG::AICharacterControllerComponent *)&this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>::mPrev[-68].mNext;
  v2 = &this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>;
  mPrev = this->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>::mPrev;
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
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICharacterControllerBaseComponent::`vftable;
  UFG::CharacterControllerInterface::~CharacterControllerInterface(this);
}

// File Line: 311
// RVA: 0x378280
void __fastcall UFG::AICharacterControllerComponent::OnAttach(
        UFG::AICharacterControllerComponent *this,
        UFG::SimObject *object)
{
  UFG::SimObject *m_pSimObject; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4

  UFG::CharacterControllerInterface::OnAttach(this, object);
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  v4 = *((float *)&m_pSimObject[1].vfptr + 1);
  v5 = *(float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
  this->m_Intention.mMotionIntentionDirection.x = *(float *)&m_pSimObject[1].vfptr;
  this->m_Intention.mMotionIntentionDirection.y = v4;
  this->m_Intention.mMotionIntentionDirection.z = v5;
  this->m_ControllerID_Init = 1;
}

// File Line: 337
// RVA: 0x38B040
void __fastcall UFG::AICharacterControllerComponent::Update(UFG::AICharacterControllerComponent *this, float delta_sec)
{
  UFG::SimObjectCharacter *m_pSimObject; // rax
  Intention *p_m_Intention; // rbx
  UFG::SimObject *v5; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r9
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v9; // zf
  UFG::SimObjectGame *v10; // rcx
  __int64 v11; // r8
  unsigned int v12; // r10d
  __int64 v13; // rdx
  __int64 v14; // rax
  float v15; // xmm1_4
  Intention intention; // [rsp+20h] [rbp-358h] BYREF

  if ( !UFG::AICharacterControllerComponent::s_AIEnabled )
  {
    m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
    if ( !m_pSimObject || m_pSimObject != LocalPlayer )
    {
      Intention::Intention(&intention);
      *(__m128 *)&intention.mMotionIntentionSpeed = _xmm;
      UFG::CharacterControllerInterface::SetIntentionOnActionTreeComponent(this, &intention);
    }
  }
  this->m_IntentionUpdated = 1;
  p_m_Intention = &this->m_Intention;
  this->m_Intention.mActionRequests.mBits[0] &= this->m_ActionRequestMask.mBits[0];
  this->m_Intention.mActionRequests.mBits[1] &= this->m_ActionRequestMask.mBits[1];
  this->m_Intention.mActionRequests.mBits[2] &= this->m_ActionRequestMask.mBits[2];
  this->m_Intention.mActionRequests.mBits[3] &= this->m_ActionRequestMask.mBits[3];
  this->m_Intention.mActionRequests.mBits[4] &= this->m_ActionRequestMask.mBits[4];
  this->m_Intention.mActionRequests.mBits[5] &= this->m_ActionRequestMask.mBits[5];
  this->m_Intention.mActionRequests.mBits[6] &= this->m_ActionRequestMask.mBits[6];
  this->m_Intention.mActionRequests.mBits[7] &= this->m_ActionRequestMask.mBits[7];
  this->m_Intention.mActionRequests.mBits[8] &= this->m_ActionRequestMask.mBits[8];
  this->m_Intention.mSignals = this->m_Intention.mActionRequests.mBits[0] | this->m_Intention.mActionRequests.mBits[1] | this->m_Intention.mActionRequests.mBits[2] | this->m_Intention.mActionRequests.mBits[3] | this->m_Intention.mActionRequests.mBits[4] | this->m_Intention.mActionRequests.mBits[5] | this->m_Intention.mActionRequests.mBits[6] | this->m_Intention.mActionRequests.mBits[7] | this->m_Intention.mActionRequests.mBits[8];
  v5 = this->m_pSimObject;
  if ( v5 )
  {
    m_Flags = v5->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v5->m_Components.p[5].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)this->m_pSimObject,
                              UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else
      {
        v9 = (m_Flags & 0x1000) == 0;
        v10 = (UFG::SimObjectGame *)this->m_pSimObject;
        ComponentOfTypeHK = v9
                          ? UFG::SimObject::GetComponentOfType(v10, UFG::AIScriptInterfaceComponent::_TypeUID)
                          : UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = v5->m_Components.p[5].m_pComponent;
    }
    if ( m_pComponent && ((__int64)m_pComponent[32].m_BoundComponentHandles.mNode.mPrev & 8) != 0 )
    {
      v11 = 0i64;
      v12 = (gActionRequestEnum.m_enumLists.size & 0x80000000) != 0
          ? 0
          : (*gActionRequestEnum.m_enumLists.p)->m_enumName.size;
      v13 = 1i64;
      if ( v12 )
      {
        do
        {
          v14 = (__int64)(int)v11 >> 6;
          if ( (v13 & (__int64)*(&m_pComponent[9].m_BoundComponentHandles.mNode.mPrev + v14)) != 0 )
          {
            p_m_Intention->mActionRequests.mBits[v14] |= v13;
            v15 = (float)(int)0.0;
            if ( v15 >= 255.0 )
              v15 = FLOAT_255_0;
            p_m_Intention->mActionRequestChargeTimes[v11] = (int)v15;
            this->m_Intention.mSignals |= v13;
          }
          v13 = __ROL8__(v13, 1);
          v11 = (unsigned int)(v11 + 1);
        }
        while ( (unsigned int)v11 < v12 );
      }
    }
  }
  UFG::CharacterControllerInterface::SetIntentionOnActionTreeComponent(this, &this->m_Intention);
}

