// File Line: 71
// RVA: 0x2FD840
UFG::qPropertySet *__fastcall UFG::CreateObject(
        ActionContext *pContext,
        UFG::qSymbol *propertySet,
        UFG::qMatrix44 *xform,
        UFG::SpawnInfoInterface::SpawnPriority *pOverridePriority)
{
  UFG::qPropertySet *v8; // rax
  UFG::qPropertySet *v9; // rdi
  char *v10; // rbx
  char *v11; // rax
  UFG::SpawnInfoInterface::SpawnPriority v12; // r9d
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+30h] [rbp-118h] BYREF
  UFG::qSymbol result; // [rsp+34h] [rbp-114h] BYREF
  char dest[256]; // [rsp+40h] [rbp-108h] BYREF

  v8 = UFG::PropertySetManager::GetPropertySet(propertySet);
  v9 = v8;
  if ( v8 )
  {
    v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pContext->mSimObject.m_pPointer->m_Name);
    v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)propertySet);
    UFG::qSPrintf(dest, "%s_CreatedItem_%s", v10, v11);
    UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, dest);
    if ( pOverridePriority )
    {
      v12 = *pOverridePriority;
      pPriority = *pOverridePriority;
    }
    else
    {
      UFG::SpawnInfoInterface::GetSpawnPriority(v9, &pPriority);
      v12 = pPriority;
    }
    return (UFG::qPropertySet *)UFG::SpawnInfoInterface::SpawnObject(&result, v9, xform, v12, 0i64, 0i64);
  }
  return v8;
}

// File Line: 114
// RVA: 0x30D350
float __fastcall getRotationDelta(
        float timeDelta,
        float turnRate,
        UFG::qVector3 *currentFacing,
        UFG::qVector3 *leftFacing,
        UFG::qVector3 *motionIntention)
{
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm2_4

  v7 = UFG::qAngleBetween(motionIntention, currentFacing);
  v8 = v7;
  if ( sNewTurn )
  {
    v9 = (float)(timeDelta * turnRate) * sTurnGain;
    if ( v9 <= 0.0 )
    {
      v9 = 0.0;
    }
    else
    {
      v10 = FLOAT_3_1415927;
      if ( v9 >= 3.1415927 )
      {
LABEL_7:
        if ( v7 <= 0.0 )
          v8 = 0.0;
        if ( v8 >= v10 )
          v8 = v10;
        v8 = v8 * (float)(v8 / v10);
        if ( v8 <= 0.0 )
          v8 = 0.0;
        if ( v8 >= v10 )
          v8 = v10;
        goto LABEL_20;
      }
    }
    v10 = v9;
    if ( v9 <= 0.0 )
    {
      v8 = 0.0;
      goto LABEL_20;
    }
    goto LABEL_7;
  }
  if ( v7 <= 0.0 )
    v8 = 0.0;
  if ( v8 >= turnRate )
    v8 = turnRate;
LABEL_20:
  if ( (float)((float)((float)(leftFacing->y * motionIntention->y) + (float)(leftFacing->x * motionIntention->x))
             + (float)(leftFacing->z * motionIntention->z)) < 0.0 )
    LODWORD(v8) ^= _xmm[0];
  return v8;
}

// File Line: 152
// RVA: 0x2EFFC0
void __fastcall LocomotionTask::Begin(LocomotionTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // dx
  unsigned int v6; // edx
  UFG::SimComponent *ComponentOfType; // rax
  bool v8; // zf

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
      goto LABEL_12;
    }
    if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
    {
      v6 = UFG::NavComponent::_TypeUID;
    }
    else
    {
      v8 = (m_Flags & 0x1000) == 0;
      v6 = UFG::NavComponent::_TypeUID;
      if ( v8 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
        goto LABEL_11;
      }
    }
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v6);
LABEL_11:
    m_pComponent = ComponentOfType;
    goto LABEL_12;
  }
  m_pComponent = 0i64;
LABEL_12:
  ++LOBYTE(m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
  *((float *)&m_pComponent[2].m_BoundComponentHandles.mNode.mPrev + 1) = sTurnGain * *(float *)&this->m_Track[1].vfptr;
}

// File Line: 163
// RVA: 0x305040
char __fastcall LocomotionTask::Update(LocomotionTask *this, float timeDelta)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  float x; // xmm8_4
  __m128 y_low; // xmm9
  float v8; // xmm6_4
  __m128 v9; // xmm1
  float z; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm10_4
  __m128 v13; // xmm2
  float v14; // xmm8_4
  float v15; // xmm9_4
  UFG::SimObject *v16; // rbx
  float v17; // xmm6_4
  float v18; // xmm12_4
  float v19; // xmm13_4
  float v20; // xmm14_4
  float v21; // xmm15_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  ITrack *m_Track; // rax
  float v25; // xmm1_4
  float RotationDelta; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm15_4
  float v37; // xmm14_4
  UFG::qMatrix44 m; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 v40; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector3 v41; // [rsp+80h] [rbp-80h] BYREF
  UFG::qVector3 v42; // [rsp+90h] [rbp-70h] BYREF
  UFG::qMatrix44 dest; // [rsp+A0h] [rbp-60h] BYREF
  float v44; // [rsp+1A0h] [rbp+A0h]
  float v45; // [rsp+1A0h] [rbp+A0h]
  float v47; // [rsp+1B0h] [rbp+B0h]
  float v48; // [rsp+1B0h] [rbp+B0h]

  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    else
      v5 = (UFG::AICharacterControllerBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::AICharacterControllerBaseComponent::_TypeUID));
    if ( v5 )
    {
      x = v5->m_Intention.mMotionIntentionDirection.x;
      y_low = (__m128)LODWORD(v5->m_Intention.mMotionIntentionDirection.y);
      v8 = 0.0;
      v9 = y_low;
      z = 0.0;
      v9.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
      v11 = _mm_sqrt_ps(v9).m128_f32[0];
      if ( v11 < 0.0 )
        LODWORD(v11) ^= _xmm[0];
      if ( v11 < 0.001 )
      {
        x = UFG::qVector3::msAxisX.x;
        y_low = (__m128)LODWORD(UFG::qVector3::msAxisX.y);
        z = UFG::qVector3::msAxisX.z;
      }
      v12 = *(float *)&FLOAT_1_0;
      v13 = y_low;
      v13.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(z * z);
      if ( v13.m128_f32[0] != 0.0 )
        v8 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
      v14 = x * v8;
      v15 = y_low.m128_f32[0] * v8;
      v16 = this->mContext->mSimObject.m_pPointer;
      v17 = v8 * z;
      if ( v16 )
        v16 = (UFG::SimObject *)v16->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
      v18 = *(float *)&v16[1].vfptr;
      v19 = *((float *)&v16[1].vfptr + 1);
      v20 = *(float *)&v16[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
      v21 = *(float *)&v16[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
      v44 = *((float *)&v16[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext
            + 1);
      v47 = *(float *)&v16[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
      v22 = (float)((float)(v18 * v14) + (float)(v19 * v15)) + (float)(v20 * v17);
      if ( v22 <= -1.0 )
      {
        v22 = FLOAT_N1_0;
      }
      else if ( v22 >= 1.0 )
      {
        v22 = *(float *)&FLOAT_1_0;
      }
      v23 = cosf(*((float *)&this->m_Track[1].vfptr + 1));
      if ( v23 <= -1.0 )
      {
        v23 = FLOAT_N1_0;
      }
      else if ( v23 >= 1.0 )
      {
        goto LABEL_27;
      }
      v12 = v23;
LABEL_27:
      if ( v22 >= v12 || !UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
      {
        m_Track = this->m_Track;
        v42.x = v14;
        v42.y = v15;
        v42.z = v17;
        v41.y = v44;
        v41.z = v47;
        v40.x = v18;
        v40.y = v19;
        v40.z = v20;
        v25 = *(float *)&m_Track[1].vfptr;
        v41.x = v21;
        RotationDelta = getRotationDelta(timeDelta, v25, &v40, &v41, &v42);
        UFG::qRotationMatrixZ(&dest, RotationDelta);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
        v27 = *(float *)&v16[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v28 = *((float *)&v16[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev
              + 1);
        v29 = *(float *)&v16[1].vfptr;
        m.v0.y = *((float *)&v16[1].vfptr + 1);
        m.v0.x = v29;
        m.v0.w = v28;
        m.v0.z = v27;
        v30 = *(float *)&v16[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
        v31 = *((float *)&v16[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev
              + 1);
        v32 = *(float *)&v16[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
        m.v1.y = *((float *)&v16[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext
                 + 1);
        m.v1.w = v31;
        m.v1.x = v32;
        m.v1.z = v30;
        v33 = *((float *)&v16[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext
              + 1);
        v34 = *(float *)&v16[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
        v35 = *(float *)&v16[1].mNode.mParent;
        m.v2.w = *((float *)&v16[1].mNode.mParent + 1);
        m.v2.x = v34;
        m.v2.y = v33;
        m.v2.z = v35;
        v36 = *((float *)v16[1].mNode.mChild + 1);
        v37 = *(float *)v16[1].mNode.mChild;
        v45 = *(float *)&v16[1].mNode.mChild[1];
        v48 = *((float *)&v16[1].mNode.mChild[1] + 1);
        m.v0 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)m.v0, (__m128)m.v0, 0), (__m128)dest.v0),
                                      (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)m.v0, (__m128)m.v0, 85), (__m128)dest.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)m.v0, (__m128)m.v0, 170), (__m128)dest.v2)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)m.v0, (__m128)m.v0, 255), (__m128)dest.v3));
        m.v1 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)m.v1, (__m128)m.v1, 0), (__m128)dest.v0),
                                      (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)m.v1, (__m128)m.v1, 85), (__m128)dest.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)m.v1, (__m128)m.v1, 170), (__m128)dest.v2)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)m.v1, (__m128)m.v1, 255), (__m128)dest.v3));
        m.v2 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)m.v2, (__m128)m.v2, 0), (__m128)dest.v0),
                                      (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)m.v2, (__m128)m.v2, 85), (__m128)dest.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)m.v2, (__m128)m.v2, 170), (__m128)dest.v2)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)m.v2, (__m128)m.v2, 255), (__m128)dest.v3));
        m.v3.x = v37;
        m.v3.z = v45;
        m.v3.y = v36;
        m.v3.w = v48;
        UFG::TransformNodeComponent::SetWorldTransform((UFG::TransformNodeComponent *)v16, &m);
      }
    }
  }
  return 1;
}

// File Line: 211
// RVA: 0x2FF1C0
void __fastcall LocomotionTask::End(LocomotionTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v3; // edx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v5; // zf
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
  {
    --MEMORY[0xB8];
    return;
  }
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    --LOBYTE(m_pPointer->m_Components.p[36].m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
    return;
  }
  if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v3 = UFG::NavComponent::_TypeUID;
LABEL_7:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v3);
    --LOBYTE(ComponentOfTypeHK[2].m_BoundComponentHandles.mNode.mNext);
    return;
  }
  v5 = (m_Flags & 0x1000) == 0;
  v3 = UFG::NavComponent::_TypeUID;
  if ( !v5 )
    goto LABEL_7;
  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
  --LOBYTE(ComponentOfType[2].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 220
// RVA: 0x2EFE50
void __fastcall Locomotion2Task::Begin(Locomotion2Task *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdi
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  float mCurrentRotationInput; // xmm1_4
  float v8; // ecx
  float mAngularVel; // xmm0_4
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  unsigned int v12; // edx
  UFG::SimComponent *ComponentOfType; // rax
  bool v14; // zf

  this->mContext = context;
  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  m_pComponent = 0i64;
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
    {
      mCurrentRotationInput = ComponentOfTypeHK->m_Intention.mCurrentRotationInput;
      if ( mCurrentRotationInput < 0.0 )
      {
        v8 = *((float *)&this->m_Track[1].vfptr + 1);
        *(_QWORD *)&this->mAccel = 0i64;
        this->mCurrentRotation = v8;
      }
      else
      {
        this->mCurrentRotation = mCurrentRotationInput;
        this->mAccel = ComponentOfTypeHK->m_Intention.mCurrentRotationAccel;
        this->mAngularVel = ComponentOfTypeHK->m_Intention.mCurrentRotationAngularVel;
      }
      mAngularVel = this->mAngularVel;
      this->mValueBuff[3] = mAngularVel;
      this->mValueBuff[2] = mAngularVel;
      this->mValueBuff[1] = mAngularVel;
      this->mValueBuff[0] = mAngularVel;
    }
  }
  v10 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      m_pComponent = v10->m_Components.p[36].m_pComponent;
      goto LABEL_24;
    }
    if ( v11 < 0 || (v11 & 0x2000) != 0 )
    {
      v12 = UFG::NavComponent::_TypeUID;
    }
    else
    {
      v14 = (v11 & 0x1000) == 0;
      v12 = UFG::NavComponent::_TypeUID;
      if ( v14 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v10, UFG::NavComponent::_TypeUID);
        goto LABEL_23;
      }
    }
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v10, v12);
LABEL_23:
    m_pComponent = ComponentOfType;
  }
LABEL_24:
  ++LOBYTE(m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
  HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mPrev) = HIDWORD(this->m_Track[1].vfptr);
}

// File Line: 260
// RVA: 0x3049E0
char __fastcall Locomotion2Task::Update(Locomotion2Task *this, float timeDelta)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::AICharacterControllerBaseComponent *v6; // rdi
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v9; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  __int16 v12; // dx
  UFG::SimComponent *m_pComponent; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm6_4
  float *m_Track; // rax
  float mAngularVel; // xmm1_4
  float v26; // xmm6_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float x; // xmm14_4
  float v34; // xmm15_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C8h] BYREF
  float v1[2]; // [rsp+70h] [rbp-88h] BYREF
  __int64 v1_8; // [rsp+78h] [rbp-80h]
  UFG::qMatrix44 dest; // [rsp+88h] [rbp-70h] BYREF

  v1_8 = -2i64;
  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
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
    v6 = ComponentOfTypeHK;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v9 )
    m_pTransformNodeComponent = v9->m_pTransformNodeComponent;
  if ( v6 && m_pTransformNodeComponent )
  {
    y = v6->m_Intention.mMotionIntentionDirection.y;
    z = v6->m_Intention.mMotionIntentionDirection.z;
    v2.x = v6->m_Intention.mMotionIntentionDirection.x;
    v2.y = y;
    v2.z = z;
    if ( BYTE1(this->m_Track[1].m_TrackClassNameUID) && v9 )
    {
      v12 = v9->m_Flags;
      if ( (v12 & 0x4000) != 0 )
        m_pComponent = v9->m_Components.p[47].m_pComponent;
      else
        m_pComponent = v12 < 0 || (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
                     ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::AimingBaseComponent::_TypeUID)
                     : UFG::SimObject::GetComponentOfType(v9, UFG::AimingBaseComponent::_TypeUID);
      if ( m_pComponent )
      {
        v14 = *(float *)&m_pComponent[2].m_SafePointerList.mNode.mNext;
        v15 = *((float *)&m_pComponent[2].m_SafePointerList.mNode.mNext + 1);
        v2.x = *((float *)&m_pComponent[2].m_SafePointerList.mNode.mPrev + 1);
        v2.y = v14;
        v2.z = v15;
      }
    }
    v16 = *((float *)&this->m_Track[1].vfptr + 1);
    v17 = (float)((float)(v16 - this->mCurrentRotation) * sRateGain) + this->mCurrentRotation;
    this->mCurrentRotation = v17;
    if ( v17 <= 0.0 )
      v17 = 0.0;
    if ( v17 >= v16 )
      v17 = v16;
    this->mCurrentRotation = v17;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v18 = m_pTransformNodeComponent->mWorldTransform.v0.y;
    v19 = m_pTransformNodeComponent->mWorldTransform.v0.z;
    v1[0] = m_pTransformNodeComponent->mWorldTransform.v0.x;
    v1[1] = v18;
    *(float *)&v1_8 = v19;
    v20 = (float)((float)(v2.y * v18) + (float)(v2.x * v1[0])) + (float)(v2.z * v19);
    v21 = *(float *)&FLOAT_1_0;
    if ( v20 <= -1.0 )
    {
      v20 = FLOAT_N1_0;
    }
    else if ( v20 >= 1.0 )
    {
      v20 = *(float *)&FLOAT_1_0;
    }
    v22 = cosf(*(float *)&this->m_Track[1].vfptr);
    if ( v22 <= -1.0 )
    {
      v22 = FLOAT_N1_0;
    }
    else if ( v22 >= 1.0 )
    {
      v22 = *(float *)&FLOAT_1_0;
    }
    if ( v20 >= v22 || !UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
    {
      v23 = UFG::qHeadingDifference2D((UFG::qVector3 *)v1, &v2);
      if ( !UFG::IsAnyLocalPlayer(this->mContext->mSimObject.m_pPointer) )
        v21 = FLOAT_2_0;
      m_Track = (float *)this->m_Track;
      mAngularVel = this->mAngularVel;
      v26 = (float)((float)(v23 * m_Track[16]) * v21) - (float)(mAngularVel * m_Track[17]);
      this->mAccel = v26;
      v27 = (float)(v26 * timeDelta) + mAngularVel;
      this->mAngularVel = v27;
      v28 = m_Track[15];
      if ( v27 <= COERCE_FLOAT(LODWORD(v28) ^ _xmm[0]) )
        LODWORD(v27) = *((_DWORD *)m_Track + 15) ^ _xmm[0];
      if ( v27 >= v28 )
        v27 = m_Track[15];
      this->mAngularVel = v27;
      v29 = v27 * timeDelta;
      this->mValueBuff[3] = this->mValueBuff[2];
      this->mValueBuff[2] = this->mValueBuff[1];
      this->mValueBuff[1] = this->mValueBuff[0];
      v30 = this->mAngularVel;
      this->mValueBuff[0] = v30;
      v31 = (float)((float)((float)(v30 + this->mValueBuff[1]) + this->mValueBuff[2]) + this->mValueBuff[3]) * 0.25;
      if ( (_S11_1 & 1) != 0 )
      {
        v32 = sMaxLeanAngle;
      }
      else
      {
        _S11_1 |= 1u;
        v32 = FLOAT_0_52359879;
        sMaxLeanAngle = FLOAT_0_52359879;
      }
      v6->m_Intention.mCurrentRotationSignal = (float)(v31 / v28) * v32;
      v6->m_Intention.mCurrentRotationAccel = this->mAccel;
      v6->m_Intention.mCurrentRotationAngularVel = this->mAngularVel;
      v6->m_IntentionUpdated = 1;
      UFG::qRotationMatrixZ(&dest, v29);
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      m.v0.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
      m.v0.y = m_pTransformNodeComponent->mWorldTransform.v0.y;
      m.v0.z = m_pTransformNodeComponent->mWorldTransform.v0.z;
      m.v0.w = m_pTransformNodeComponent->mWorldTransform.v0.w;
      m.v1 = m_pTransformNodeComponent->mWorldTransform.v1;
      m.v2 = m_pTransformNodeComponent->mWorldTransform.v2;
      x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      v34 = m_pTransformNodeComponent->mWorldTransform.v3.y;
      m.v0 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)m.v0, (__m128)m.v0, 0), (__m128)dest.v0),
                                    (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)m.v0, (__m128)m.v0, 85), (__m128)dest.v1)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)m.v0, (__m128)m.v0, 170), (__m128)dest.v2)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)m.v0, (__m128)m.v0, 255), (__m128)dest.v3));
      m.v1 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)m.v1, (__m128)m.v1, 0), (__m128)dest.v0),
                                    (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)m.v1, (__m128)m.v1, 85), (__m128)dest.v1)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)m.v1, (__m128)m.v1, 170), (__m128)dest.v2)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)m.v1, (__m128)m.v1, 255), (__m128)dest.v3));
      m.v2 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)m.v2, (__m128)m.v2, 0), (__m128)dest.v0),
                                    (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)m.v2, (__m128)m.v2, 85), (__m128)dest.v1)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)m.v2, (__m128)m.v2, 170), (__m128)dest.v2)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)m.v2, (__m128)m.v2, 255), (__m128)dest.v3));
      *(_QWORD *)&m.v3.z = *(unsigned __int128 *)&_mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 85),
                                                          (__m128)dest.v1),
                                                        _mm_add_ps(
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 0),
                                                            (__m128)dest.v0),
                                                          (__m128)0i64)),
                                                      _mm_mul_ps(
                                                        _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 170),
                                                        (__m128)dest.v2)),
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 255),
                                                      (__m128)dest.v3)) >> 64;
      m.v3.x = x;
      m.v3.y = v34;
      m.v3.z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      m.v3.w = m_pTransformNodeComponent->mWorldTransform.v3.w;
      UFG::TransformNodeComponent::SetWorldTransform(m_pTransformNodeComponent, &m);
    }
  }
  return 1;
}

// File Line: 335
// RVA: 0x2FF070
void __fastcall Locomotion2Task::End(Locomotion2Task *this)
{
  UFG::SimComponent *v2; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  __int16 v7; // dx
  unsigned int v8; // edx
  UFG::SimComponent *ComponentOfType; // rax
  bool v10; // zf

  v2 = 0i64;
  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    else
      v5 = (UFG::AICharacterControllerBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::AICharacterControllerBaseComponent::_TypeUID));
    if ( v5 )
    {
      v5->m_Intention.mCurrentRotationInput = this->mCurrentRotation;
      if ( !LOBYTE(this->m_Track[1].m_TrackClassNameUID) )
        v5->m_Intention.mCurrentRotationSignal = 0.0;
      v5->m_Intention.mCurrentRotationAccel = this->mAccel;
      v5->m_Intention.mCurrentRotationAngularVel = this->mAngularVel;
      v5->m_IntentionUpdated = 1;
    }
  }
  v6 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( !v6 )
    goto LABEL_23;
  v7 = v6->m_Flags;
  if ( (v7 & 0x4000) != 0 )
  {
    --LOBYTE(v6->m_Components.p[36].m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
    return;
  }
  if ( v7 < 0 || (v7 & 0x2000) != 0 )
  {
    v8 = UFG::NavComponent::_TypeUID;
  }
  else
  {
    v10 = (v7 & 0x1000) == 0;
    v8 = UFG::NavComponent::_TypeUID;
    if ( v10 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(v6, UFG::NavComponent::_TypeUID);
      goto LABEL_22;
    }
  }
  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v6, v8);
LABEL_22:
  v2 = ComponentOfType;
LABEL_23:
  --LOBYTE(v2[2].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 364
// RVA: 0x2EFFB0
void __fastcall LocomotionParamTask::Begin(LocomotionParamTask *this, ActionContext *context)
{
  this->mContext = context;
  LocomotionParamTask::setParameters(this);
}

// File Line: 371
// RVA: 0x305030
char __fastcall LocomotionParamTask::Update(LocomotionParamTask *this, float timeDelta)
{
  LocomotionParamTask::setParameters(this);
  return 1;
}

// File Line: 377
// RVA: 0x2FF1B0
// attributes: thunk
void __fastcall LocomotionParamTask::End(LocomotionParamTask *this)
{
  LocomotionParamTask::setParameters(this);
}

// File Line: 382
// RVA: 0x30E100
void __fastcall LocomotionParamTask::setParameters(LocomotionParamTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rcx

  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
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
    {
      m_Track = this->m_Track;
      ComponentOfTypeHK->m_Intention.mCurrentRotationInput = *(float *)&m_Track[1].vfptr;
      ComponentOfTypeHK->m_Intention.mCurrentRotationSignal = *((float *)&m_Track[1].vfptr + 1);
      ComponentOfTypeHK->m_Intention.mCurrentRotationAccel = *(float *)&m_Track[1].mResourceOwner;
      ComponentOfTypeHK->m_Intention.mCurrentRotationAngularVel = *((float *)&m_Track[1].mResourceOwner + 1);
      ComponentOfTypeHK->m_IntentionUpdated = 1;
    }
  }
}

// File Line: 402
// RVA: 0x2EFD00
void __fastcall JumpTask::Begin(JumpTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v7; // rdi
  float v8; // xmm4_4
  __m128 vfptr_high; // xmm5
  float v10; // xmm2_4
  __m128 v11; // xmm3
  ITrack *m_Track; // rax
  float v13; // xmm4_4
  float v14; // xmm5_4

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v7 = this->mContext->mSimObject.m_pPointer;
  if ( v7 )
    v7 = (UFG::SimObject *)v7->m_pTransformNodeComponent;
  if ( m_pComponent && v7 )
  {
    HIDWORD(m_pComponent[9].vfptr) = this->m_Track[1].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
    v8 = *(float *)&v7[1].vfptr;
    vfptr_high = (__m128)HIDWORD(v7[1].vfptr);
    v10 = 0.0;
    v11 = vfptr_high;
    v11.m128_f32[0] = (float)((float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0]) + (float)(v8 * v8))
                    + (float)(*(float *)&v7[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev
                            * *(float *)&v7[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev);
    if ( v11.m128_f32[0] != 0.0 )
      v10 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
    m_Track = this->m_Track;
    v13 = (float)(v8 * v10) * *((float *)&m_Track[1].vfptr + 1);
    v14 = (float)(vfptr_high.m128_f32[0] * v10) * *((float *)&m_Track[1].vfptr + 1);
    LODWORD(m_pComponent[6].m_pSimObject) = 0;
    *(float *)&m_pComponent[6].m_Flags = v13;
    *(float *)(&m_pComponent[6].m_SimObjIndex + 1) = v14;
  }
}

// File Line: 428
// RVA: 0x2FEFB0
void __fastcall JumpTask::End(JumpTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      y = UFG::qVector3::msZero.y;
      z = UFG::qVector3::msZero.z;
      *(float *)&m_pComponent[6].m_Flags = UFG::qVector3::msZero.x;
      *(float *)(&m_pComponent[6].m_SimObjIndex + 1) = y;
      *(float *)&m_pComponent[6].m_pSimObject = z;
    }
  }
}

// File Line: 441
// RVA: 0x149ED00
__int64 dynamic_initializer_for__qwsPlayTimeDilate__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayTimeDilate, "PLAY_TIME_DILATE");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__qwsPlayTimeDilate__);
}

// File Line: 442
// RVA: 0x149ED30
__int64 dynamic_initializer_for__qwsStopTimeDilate__()
{
  UFG::qWiseSymbol::create_from_string(&qwsStopTimeDilate, "STOP_TIME_DILATE");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__qwsStopTimeDilate__);
}

// File Line: 446
// RVA: 0x2F9D20
void __fastcall TimeWarpTask::Begin(TimeWarpTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCharacter *mNext; // rbx
  float *m_Track; // rax
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float mSimTimeScaleMax; // xmm0_4
  unsigned int v16; // edx

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[23].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleDriverInterface::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleDriverInterface::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[23].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !BYTE4(this->m_Track[1].vfptr)
    || UFG::GetLocalPlayer() == this->mContext->mSimObject.m_pPointer
    || m_pComponent
    && (mNext = (UFG::SimObjectCharacter *)m_pComponent[3].m_BoundComponentHandles.mNode.mNext,
        mNext == UFG::GetLocalPlayer()) )
  {
    m_Track = (float *)this->m_Track;
    v9 = m_Track[13];
    v10 = m_Track[12];
    v11 = m_Track[14];
    this->mCurrentStrength = UFG::Metrics::msInstance.mSimTimeScaleInGame;
    v12 = m_Track[16];
    if ( v10 >= 0.0 && v9 >= 0.0 && v12 > (float)((float)(v9 - v10) * 0.5) )
      v12 = (float)(v9 - v10) * 0.5;
    v13 = v11 - this->mCurrentStrength;
    if ( v12 <= 0.0 )
      v14 = v13 * 3.4028233e32;
    else
      v14 = v13 / v12;
    this->mDeltaStrength = v14;
    this->mActivated = 1;
    if ( v12 == 0.0 )
    {
      if ( !bRestrictSimTimeScaleChange )
      {
        if ( v11 <= 0.0 )
          mSimTimeScaleMax = 0.0;
        else
          mSimTimeScaleMax = v11;
        if ( mSimTimeScaleMax >= UFG::Metrics::msInstance.mSimTimeScaleMax )
          mSimTimeScaleMax = UFG::Metrics::msInstance.mSimTimeScaleMax;
        UFG::Metrics::msInstance.mSimTimeScaleInGame = mSimTimeScaleMax;
        UFG::Metrics::msInstance.mSimPausedInGame = mSimTimeScaleMax == 0.0;
        UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      }
      this->mDeltaStrength = 0.0;
      this->mCurrentStrength = v11;
    }
    v16 = *(_DWORD *)&this->m_Track[1].mBreakPoint;
    if ( v16 && (v9 < 0.0 || (float)(v9 - v10) >= UFG::TidoGame::sm_timeWarpAudioLength) )
    {
      if ( UFG::AmbienceAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, v16, 0i64, 0, 0i64);
      if ( (_S12_0 & 1) == 0 )
      {
        _S12_0 |= 1u;
        UFG::qWiseSymbol::create_from_string(&time_dilate, "time_dilate");
        atexit(TimeWarpTask::Begin_::_25_::_dynamic_atexit_destructor_for__time_dilate__);
      }
      UFG::TiDo::SetWwiseRtpcValue(UFG::TiDo::m_pInstance, time_dilate.mUID, 1.0, 0xFFFFFFFFFFFFFFFFui64);
    }
  }
}

// File Line: 520
// RVA: 0x30B5A0
bool __fastcall TimeWarpTask::Update(TimeWarpTask *this, float timeDelta)
{
  float *m_Track; // r8
  float v3; // xmm0_4
  float mSimTimeScaleMax; // xmm2_4
  bool result; // al

  if ( this->mActivated )
  {
    m_Track = (float *)this->m_Track;
    if ( m_Track[13] >= 0.0 )
    {
      v3 = m_Track[12];
      if ( v3 >= 0.0
        && (float)(this->mContext->mActionController->m_ActionNodePlayTime - v3) > (float)((float)(m_Track[13]
                                                                                                 - m_Track[12])
                                                                                         * 0.5) )
      {
        LODWORD(this->mDeltaStrength) &= _xmm;
      }
    }
    mSimTimeScaleMax = (float)(timeDelta * this->mDeltaStrength) + this->mCurrentStrength;
    this->mCurrentStrength = mSimTimeScaleMax;
    if ( mSimTimeScaleMax < m_Track[14] )
      mSimTimeScaleMax = m_Track[14];
    if ( mSimTimeScaleMax > 1.0 )
      mSimTimeScaleMax = *(float *)&FLOAT_1_0;
    if ( !bRestrictSimTimeScaleChange )
    {
      if ( mSimTimeScaleMax <= 0.0 )
        mSimTimeScaleMax = 0.0;
      if ( mSimTimeScaleMax >= UFG::Metrics::msInstance.mSimTimeScaleMax )
        mSimTimeScaleMax = UFG::Metrics::msInstance.mSimTimeScaleMax;
      UFG::Metrics::msInstance.mSimTimeScaleInGame = mSimTimeScaleMax;
      if ( mSimTimeScaleMax == 0.0 )
      {
        result = 1;
        UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
        UFG::Metrics::msInstance.mSimPausedInGame = 1;
        return result;
      }
      UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      UFG::Metrics::msInstance.mSimPausedInGame = 0;
    }
  }
  return 1;
}

// File Line: 557
// RVA: 0x301340
void __fastcall TimeWarpTask::End(TimeWarpTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  bool v4; // al
  ITrack *m_Track; // rax
  unsigned int mOffset; // edx
  float mTimeEnd; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleDriverInterface::_TypeUID);
      else
        UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleDriverInterface::_TypeUID);
    }
  }
  if ( this->mActivated )
  {
    if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
      {
        v4 = 1;
LABEL_14:
        UFG::Metrics::msInstance.mSimPausedInGame = v4;
        UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
        m_Track = this->m_Track;
        mOffset = m_Track[1].mMasterRate.text.mOffset;
        if ( mOffset )
        {
          mTimeEnd = m_Track->mTimeEnd;
          if ( mTimeEnd < 0.0 || (float)(mTimeEnd - m_Track->mTimeBegin) >= UFG::TidoGame::sm_timeWarpAudioLength )
          {
            if ( UFG::AmbienceAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, mOffset, 0i64, 0, 0i64);
            if ( (_S13_1 & 1) == 0 )
            {
              _S13_1 |= 1u;
              UFG::qWiseSymbol::create_from_string(&time_dilate_0, "time_dilate");
              atexit(TimeWarpTask::End_::_13_::_dynamic_atexit_destructor_for__time_dilate__);
            }
            UFG::TiDo::SetWwiseRtpcValue(UFG::TiDo::m_pInstance, time_dilate_0.mUID, 0.0, 0xFFFFFFFFFFFFFFFFui64);
          }
        }
        return;
      }
    }
    else
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
    }
    v4 = 0;
    goto LABEL_14;
  }
}

// File Line: 598
// RVA: 0x2EB640
void __fastcall DamageTask::Begin(DamageTask *this, ActionContext *context)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSource; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax

  p_mpSource = &this->mpSource;
  this->mContext = context;
  if ( this->mpSource.m_pPointer )
  {
    mPrev = p_mpSource->mPrev;
    mNext = this->mpSource.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpSource->mPrev = p_mpSource;
    this->mpSource.mNext = &this->mpSource;
  }
  this->mpSource.m_pPointer = 0i64;
  if ( LODWORD(this->m_Track[1].mMasterRate.text.mOffset) )
  {
    m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
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
        v10 = *(UFG::SimObject **)(56i64
                                 * *(unsigned __int8 *)(LODWORD(this->m_Track[1].mMasterRate.text.mOffset)
                                                      + *(_QWORD *)&m_pComponent[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                 + 40);
        if ( p_mpSource->m_pPointer )
        {
          v11 = p_mpSource->mPrev;
          v12 = p_mpSource->mNext;
          v11->mNext = v12;
          v12->mPrev = v11;
          p_mpSource->mPrev = p_mpSource;
          p_mpSource->mNext = p_mpSource;
        }
        p_mpSource->m_pPointer = v10;
        if ( v10 )
        {
          v13 = v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
          v13->mNext = p_mpSource;
          p_mpSource->mPrev = v13;
          p_mpSource->mNext = &v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
          v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpSource;
        }
      }
    }
  }
}

// File Line: 616
// RVA: 0x2FE8C0
void __fastcall DamageTask::End(DamageTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  __int16 m_Flags; // dx
  UFG::HealthComponent *m_pComponent; // rsi
  UFG::SimComponent *v5; // rax
  __int16 v6; // cx
  UFG::SimComponent *v7; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v9; // rbp
  UFG::HitRecord *p_mNext; // r14
  int v11; // r15d
  bool v12; // r14
  UFG::CopSystem *v13; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
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
      v6 = m_pPointer->m_Flags;
      if ( (v6 & 0x4000) != 0 )
      {
        v7 = m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( v6 >= 0 )
      {
        if ( (v6 & 0x2000) != 0 || (v6 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
        v7 = ComponentOfTypeHK;
      }
      else
      {
        v7 = m_pPointer->m_Components.p[15].m_pComponent;
      }
      if ( v7 )
      {
        v9 = *(UFG::SimObject **)&v7[3].m_TypeUID;
        p_mNext = (UFG::HitRecord *)&v7[2].m_BoundComponentHandles.mNode.mNext;
      }
      else
      {
        p_mNext = 0i64;
        v9 = 0i64;
      }
      if ( this->mpSource.m_pPointer )
        v9 = this->mpSource.m_pPointer;
      v11 = ExpressionParameterInt::operator long((ExpressionParameterInt *)&this->m_Track[1]);
      if ( UFG::IsAnyLocalPlayer(v9) )
        v11 = (int)(float)((float)(UFG::PlayerBuffTracker::GetGrappleDamageMultiplier() + 1.0) * (float)v11);
      v12 = UFG::HealthComponent::ApplyHealthDamage(m_pComponent, v11, v9, p_mNext, 0);
      if ( v12 )
      {
        if ( v7 )
        {
          v13 = UFG::CopSystem::Instance();
          ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, UFG::SimObjectGame *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **, UFG::HealthComponent *, bool))v13->vfptr[95].__vecDelDtor)(
            v13,
            v9,
            m_pPointer,
            &v7[2].m_BoundComponentHandles.mNode.mNext,
            m_pComponent,
            v12);
        }
      }
    }
  }
}

// File Line: 658
// RVA: 0x2EE9E0
void __fastcall HandleDamageTask::Begin(HandleDamageTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::HitReactionComponent *m_pComponent; // rbp
  UFG::HitReactionComponent *v7; // rax
  UFG::SimObjectGame *v8; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimObject *v10; // rax
  UFG::TransformNodeComponent *v11; // rbx
  int v12; // xmm5_4
  int v13; // xmm4_4
  UFG::SimObjectGame *v14; // rcx
  __int16 v15; // dx
  UFG::HealthComponent *v16; // r14
  UFG::SimComponent *v17; // rax
  float v18; // xmm6_4
  bool v19; // si
  bool v20; // r15
  UFG::GameStatTracker *v21; // rax
  int v22; // ebx
  UFG::HitRecord *v23; // rax
  float v24; // xmm1_4
  int m_fHealth; // esi
  bool v26; // cc
  __int16 v27; // cx
  UFG::SimComponent *v28; // rax
  __int16 v29; // cx
  UFG::SimComponent *v30; // rax
  UFG::SimObjectGame *v31; // rcx
  __int16 v32; // dx
  UFG::CharacterOccupantComponent *v33; // rax
  UFG::VehicleOccupantComponent *CurrentVehicle; // rax
  bool v35; // r12
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObject *v37; // r8
  bool v38; // bl
  int mAttackTypeID; // ecx
  bool v40; // r15
  UFG::SimComponent *v41; // rbp
  __int16 v42; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v44; // zf
  UFG::SimObjectGame *v45; // rcx
  unsigned int v46; // eax
  float v47; // xmm2_4
  UFG::CopSystem *v48; // rax
  __int16 v49; // cx
  UFG::FaceMeterComponent *ComponentOfType; // rax
  int fOffsetRadians; // [rsp+28h] [rbp-C0h]
  bool bSteerWithNoTarget; // [rsp+30h] [rbp-B8h]
  bool bSteerUsingAimPosition; // [rsp+38h] [rbp-B0h]
  UFG::qVector3 *pOverrideTargetPosition; // [rsp+40h] [rbp-A8h]
  int v55[4]; // [rsp+58h] [rbp-90h] BYREF
  UFG::FaceEventParameters parameters; // [rsp+68h] [rbp-80h] BYREF
  UFG::HitRecord *p_mHitRecord; // [rsp+F8h] [rbp+10h]

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::HitReactionComponent *)m_pPointer->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (UFG::HitReactionComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                         m_pPointer,
                                         UFG::HitReactionComponent::_TypeUID)
                                     : UFG::SimObject::GetComponentOfType(
                                         m_pPointer,
                                         UFG::HitReactionComponent::_TypeUID));
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = (UFG::HitReactionComponent *)m_pPointer->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return;
  v8 = (UFG::SimObjectGame *)m_pComponent->mHitRecord.mAttacker.m_pPointer;
  if ( LOBYTE(this->m_Track[1].mMasterRate.text.mOffset) && v8 )
  {
    if ( m_pComponent->mHitRecord.mMeleeInfo.mAttackFromBehind )
    {
      m_pTransformNodeComponent = v8->m_pTransformNodeComponent;
      if ( !m_pTransformNodeComponent )
        goto LABEL_22;
      v10 = context->mSimObject.m_pPointer;
      if ( v10 )
        v11 = v10->m_pTransformNodeComponent;
      else
        v11 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      *(float *)&v12 = v11->mWorldTransform.v3.z
                     + (float)(v11->mWorldTransform.v3.z - m_pTransformNodeComponent->mWorldTransform.v3.z);
      *(float *)&v13 = v11->mWorldTransform.v3.y
                     + (float)(v11->mWorldTransform.v3.y - m_pTransformNodeComponent->mWorldTransform.v3.y);
      *(float *)v55 = v11->mWorldTransform.v3.x
                    + (float)(v11->mWorldTransform.v3.x - m_pTransformNodeComponent->mWorldTransform.v3.x);
      v55[1] = v13;
      v55[2] = v12;
      pOverrideTargetPosition = (UFG::qVector3 *)v55;
      bSteerUsingAimPosition = 0;
    }
    else
    {
      pOverrideTargetPosition = 0i64;
      bSteerUsingAimPosition = 1;
    }
    bSteerWithNoTarget = 0;
    fOffsetRadians = 0;
    UFG::SteerToTarget(context->mSimObject.m_pPointer, v8, &UFG::gNullQSymbolUC, 6.0);
  }
LABEL_22:
  if ( !m_pComponent->mHitRecord.mDamageHandled )
  {
    v14 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v14 )
    {
      v15 = v14->m_Flags;
      if ( (v15 & 0x4000) != 0 )
      {
        v16 = (UFG::HealthComponent *)v14->m_Components.p[6].m_pComponent;
      }
      else if ( v15 >= 0 )
      {
        v17 = (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::HealthComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v14, UFG::HealthComponent::_TypeUID);
        v16 = (UFG::HealthComponent *)v17;
      }
      else
      {
        v16 = (UFG::HealthComponent *)v14->m_Components.p[6].m_pComponent;
      }
      if ( v16 )
      {
        p_mHitRecord = &m_pComponent->mHitRecord;
        v18 = (float)(int)ExpressionParameterInt::operator long((ExpressionParameterInt *)&this->m_Track[1])
            * 0.0099999998;
        v19 = ::LocalPlayer == context->mSimObject.m_pPointer;
        v20 = m_pComponent->mHitRecord.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue;
        if ( ::LocalPlayer == m_pComponent->mHitRecord.mAttacker.m_pPointer )
        {
          v21 = UFG::GameStatTracker::Instance();
          if ( (int)UFG::GameStatTracker::GetStat(v21, GunplayUpgradeStage) >= UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_iRequiredLevelForGunplayUpgradeDamage
            && UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fGunplayUpgradeDamageMultiplier > 0.0 )
          {
            v18 = v18 * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fGunplayUpgradeDamageMultiplier;
          }
        }
        v22 = 0;
        v23 = &m_pComponent->mHitRecord;
        do
        {
          v22 += v23->mDamage;
          v23 = v23->mNext;
        }
        while ( v23 );
        if ( v20 )
        {
          if ( !v19 )
          {
            v24 = (float)((float)v22 * 0.0099999998) * (float)(int)v16->m_fMaxHealth;
            if ( v24 > 0.0 && v18 > 0.0 )
            {
              m_fHealth = (int)(float)(v24 * v18);
              v26 = m_fHealth < 1;
              goto LABEL_59;
            }
            goto LABEL_62;
          }
        }
        else if ( v8 )
        {
          v27 = v8->m_Flags;
          if ( (v27 & 0x4000) != 0 )
          {
            v28 = v8->m_Components.p[15].m_pComponent;
          }
          else if ( v27 >= 0 )
          {
            v28 = (v27 & 0x2000) != 0 || (v27 & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(v8, UFG::HitReactionComponent::_TypeUID);
          }
          else
          {
            v28 = v8->m_Components.p[15].m_pComponent;
          }
          if ( v28 )
            v18 = v18 * (float)((float)*(int *)(&v28[1].m_SimObjIndex + 1) * 0.0099999998);
        }
        if ( v22 > 0 && v18 > 0.0 )
        {
          m_fHealth = (int)(float)((float)v22 * v18);
          v26 = m_fHealth < 1;
LABEL_59:
          if ( v26 )
            m_fHealth = 1;
LABEL_63:
          if ( v8 )
          {
            v29 = v8->m_Flags;
            if ( (v29 & 0x4000) != 0 )
            {
              v30 = v8->m_Components.p[6].m_pComponent;
            }
            else if ( v29 >= 0 )
            {
              v30 = (v29 & 0x2000) != 0 || (v29 & 0x1000) != 0
                  ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HealthComponent::_TypeUID)
                  : UFG::SimObject::GetComponentOfType(v8, UFG::HealthComponent::_TypeUID);
            }
            else
            {
              v30 = v8->m_Components.p[6].m_pComponent;
            }
            if ( v30 && LOBYTE(v30[1].m_BoundComponentHandles.mNode.mNext) )
              m_fHealth = (int)v16->m_fHealth;
          }
          if ( m_pComponent->mHitRecord.mAttackTypeID == gAttackCollisionExplosion.m_EnumValue )
          {
            v31 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
            if ( v31 )
            {
              v32 = v31->m_Flags;
              if ( (v32 & 0x4000) != 0 )
                v33 = (UFG::CharacterOccupantComponent *)v31->m_Components.p[44].m_pComponent;
              else
                v33 = (UFG::CharacterOccupantComponent *)(v32 < 0 || (v32 & 0x2000) != 0 || (v32 & 0x1000) != 0
                                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v31,
                                                            UFG::CharacterOccupantComponent::_TypeUID)
                                                        : UFG::SimObject::GetComponentOfType(
                                                            v31,
                                                            UFG::CharacterOccupantComponent::_TypeUID));
              if ( v33 )
              {
                CurrentVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(v33);
                if ( CurrentVehicle )
                {
                  if ( v8 == (UFG::SimObjectGame *)CurrentVehicle )
                    m_fHealth = (int)v16->m_fMaxHealth;
                }
              }
            }
          }
          v35 = UFG::HealthComponent::ApplyHealthDamage(
                  v16,
                  m_fHealth,
                  m_pComponent->mHitRecord.mAttacker.m_pPointer,
                  &m_pComponent->mHitRecord,
                  v20);
          m_pComponent->mHitRecord.mDamageHandled = 1;
          LocalPlayer = UFG::GetLocalPlayer();
          v37 = context->mSimObject.m_pPointer;
          if ( LocalPlayer != v37 )
            goto LABEL_122;
          v38 = 0;
          mAttackTypeID = m_pComponent->mHitRecord.mAttackTypeID;
          v40 = mAttackTypeID == gAttackCollisionExplosion.m_EnumValue;
          if ( mAttackTypeID == gAttackCollisionHeavy.m_EnumValue )
            v38 = m_pComponent->mHitRecord.mMeleeInfo.mAttackLocationHorizontalID == 0;
          if ( mAttackTypeID != gAttackCollisionExplosion.m_EnumValue && !v38 || !v35 || m_fHealth <= 0 )
            goto LABEL_122;
          if ( v37 )
          {
            v42 = v37->m_Flags;
            if ( (v42 & 0x4000) != 0 )
            {
              v41 = v37->m_Components.p[40].m_pComponent;
            }
            else if ( v42 >= 0 )
            {
              if ( (v42 & 0x2000) != 0 )
              {
                ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)context->mSimObject.m_pPointer,
                                      UFG::HkAudioEntityComponent::_TypeUID);
              }
              else
              {
                v44 = (v42 & 0x1000) == 0;
                v45 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
                if ( v44 )
                  ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v45, UFG::HkAudioEntityComponent::_TypeUID);
                else
                  ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v45,
                                        UFG::HkAudioEntityComponent::_TypeUID);
              }
              v41 = ComponentOfTypeHK;
            }
            else
            {
              v41 = v37->m_Components.p[28].m_pComponent;
            }
          }
          else
          {
            v41 = 0i64;
          }
          v46 = _S14_0;
          if ( (_S14_0 & 1) == 0 )
          {
            _S14_0 |= 1u;
            play_ears_ringing.mUID = UFG::qWiseSymbolUIDFromString("play_ears_ringing", 0x811C9DC5);
            _((AMD_HD3D *)play_ears_ringing.mUID);
            atexit(HandleDamageTask::Begin_::_81_::_dynamic_atexit_destructor_for__play_ears_ringing__);
            v46 = _S14_0;
          }
          if ( (v46 & 2) == 0 )
          {
            _S14_0 = v46 | 2;
            explosion_damage.mUID = UFG::qWiseSymbolUIDFromString("explosion_damage", 0x811C9DC5);
            _((AMD_HD3D *)explosion_damage.mUID);
            atexit(HandleDamageTask::Begin_::_81_::_dynamic_atexit_destructor_for__explosion_damage__);
            v46 = _S14_0;
          }
          if ( (v46 & 4) == 0 )
          {
            _S14_0 = v46 | 4;
            melee_damage.mUID = UFG::qWiseSymbolUIDFromString("melee_damage", 0x811C9DC5);
            _((AMD_HD3D *)melee_damage.mUID);
            atexit(HandleDamageTask::Begin_::_81_::_dynamic_atexit_destructor_for__melee_damage__);
          }
          if ( !v41 )
            goto LABEL_122;
          if ( v38 )
          {
            if ( !v40 )
            {
              UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v41[1], explosion_damage.mUID, 200.0);
              v47 = (float)m_fHealth;
LABEL_120:
              UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v41[1], melee_damage.mUID, v47);
              goto LABEL_121;
            }
          }
          else if ( !v40 )
          {
LABEL_121:
            UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v41[1], play_ears_ringing.mUID, 0i64, 0, 0i64);
LABEL_122:
            v48 = UFG::CopSystem::Instance();
            LOBYTE(fOffsetRadians) = v35;
            ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObjectGame *, UFG::SimObject *, UFG::HitRecord *, UFG::HealthComponent *, int, bool, bool, UFG::qVector3 *))v48->vfptr[95].__vecDelDtor)(
              v48,
              v8,
              context->mSimObject.m_pPointer,
              p_mHitRecord,
              v16,
              fOffsetRadians,
              bSteerWithNoTarget,
              bSteerUsingAimPosition,
              pOverrideTargetPosition);
            if ( v35 && v8 )
            {
              v49 = v8->m_Flags;
              if ( (v49 & 0x4000) != 0 || v49 < 0 || (v49 & 0x2000) != 0 || (v49 & 0x1000) != 0 )
                ComponentOfType = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v8,
                                                               UFG::FaceMeterComponent::_TypeUID);
              else
                ComponentOfType = (UFG::FaceMeterComponent *)UFG::SimObject::GetComponentOfType(
                                                               v8,
                                                               UFG::FaceMeterComponent::_TypeUID);
              if ( ComponentOfType )
              {
                parameters.mpPropertySet = 0i64;
                parameters.mIsApply = 1;
                parameters.mpSimObject = context->mSimObject.m_pPointer;
                v44 = !v16->m_bIsKnockedOut;
                parameters.mType = 109;
                if ( v44 )
                  parameters.mType = 108;
                UFG::FaceMeterComponent::ApplyEvent(ComponentOfType, &parameters);
              }
            }
            return;
          }
          UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v41[1], explosion_damage.mUID, (float)m_fHealth);
          v47 = FLOAT_200_0;
          goto LABEL_120;
        }
LABEL_62:
        m_fHealth = 0;
        goto LABEL_63;
      }
    }
  }
}

// File Line: 906
// RVA: 0x2F49F0
void __fastcall StimulusTask::Begin(StimulusTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  __int64 vfptr_high; // rbp
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v8; // rax
  ITrack *m_Track; // rcx
  char v10; // r8
  int vfptr; // edx
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  __int64 mResourceOwner_high; // rbp
  UFG::SimObjectGame *v16; // rcx
  __int16 v17; // dx
  UFG::SimComponent *v18; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
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
      v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v8;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
      m_pPointer = *(UFG::SimObjectGame **)(56i64
                                          * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + vfptr_high + 8)
                                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                          + 40);
  }
  m_Track = this->m_Track;
  v10 = 0;
  vfptr = (int)m_Track[1].vfptr;
  stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_NONE;
  stimulus_parameters.m_MaxStimulusDuration = -1.0;
  stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
  stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
  if ( vfptr )
  {
    if ( vfptr != 1 )
      goto LABEL_18;
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
  }
  else
  {
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
  }
  v10 = 1;
LABEL_18:
  v12 = *(float *)&m_Track[1].mResourceOwner;
  stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
  stimulus_parameters.m_MaxStimulusDuration = v12;
  v13 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
  v14 = *(float *)&m_Track[1].m_TrackClassNameUID;
  stimulus_parameters.m_StimulusProducerOffset.y = *(float *)&m_Track[1].mBreakPoint;
  stimulus_parameters.m_StimulusProducerOffset.z = v13;
  stimulus_parameters.m_StimulusProducerOffset.x = v14;
  if ( v10 )
  {
    if ( LOBYTE(m_Track[1].mMasterRate.expression.mOffset)
      && (mResourceOwner_high = HIDWORD(m_Track[1].mResourceOwner),
          (v16 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer) != 0i64)
      && ((v17 = v16->m_Flags, (v17 & 0x4000) == 0)
        ? (v17 >= 0
         ? ((v17 & 0x2000) != 0 || (v17 & 0x1000) != 0
          ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                   v16,
                                   UFG::TargetingSystemBaseComponent::_TypeUID))
          : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v16, UFG::TargetingSystemBaseComponent::_TypeUID)),
            v18 = ComponentOfTypeHK)
         : (v18 = v16->m_Components.p[20].m_pComponent))
        : (v18 = v16->m_Components.p[20].m_pComponent),
          v18) )
    {
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        SHIDWORD(this->m_Track[1].mMasterRate.text.mOffset),
        &stimulus_parameters,
        m_pPointer,
        *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v18[1].m_Flags + mResourceOwner_high + 8)
                           + *(_QWORD *)&v18[1].m_TypeUID
                           + 40));
    }
    else
    {
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        SHIDWORD(this->m_Track[1].mMasterRate.text.mOffset),
        &stimulus_parameters,
        m_pPointer,
        eTARGET_TYPE_INVALID);
    }
  }
  else
  {
    UFG::StimulusManager::EndStimulus(
      UFG::StimulusManager::s_pInstance,
      SHIDWORD(m_Track[1].mMasterRate.text.mOffset),
      m_pPointer);
  }
}

// File Line: 989
// RVA: 0x2F0B20
void __fastcall ObjectCreateTask::Begin(ObjectCreateTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimComponent *v6; // rbx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v11; // rsi
  UFG::SimObject *v12; // r8
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v15; // rcx
  UFG::SimObjectGame *v16; // rcx
  __int16 v17; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::TargetingSystemBaseComponent *v19; // rax
  UFG::SpawnInfoInterface::SpawnPriority priority; // [rsp+38h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      v6 = 0i64;
      priority = UnReferenced;
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
        else if ( (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::StreamedResourceComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::StreamedResourceComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent;
      }
      if ( m_pComponent )
      {
        UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, &priority);
      }
      else
      {
        m_pSceneObj = pContext->mSimObject.m_pPointer->m_pSceneObj;
        mpWritableProperties = m_pSceneObj->mpWritableProperties;
        if ( !mpWritableProperties )
          mpWritableProperties = m_pSceneObj->mpConstProperties;
        UFG::SpawnInfoInterface::GetSpawnPriority(mpWritableProperties, &priority);
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v11 = UFG::CreateObject(
              pContext,
              (UFG::qSymbol *)&this->m_Track[1],
              &m_pTransformNodeComponent->mWorldTransform,
              &priority);
      if ( v11 )
      {
        v12 = pContext->mSimObject.m_pPointer;
        if ( v12 )
        {
          v13 = v12->m_Flags;
          if ( (v13 & 0x4000) != 0 )
          {
            ComponentOfTypeHK = v12->m_Components.p[20].m_pComponent;
          }
          else if ( v13 >= 0 )
          {
            v15 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
            if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v15,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = v12->m_Components.p[20].m_pComponent;
          }
          if ( ComponentOfTypeHK )
          {
            v16 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
            if ( v16 )
            {
              v17 = v16->m_Flags;
              if ( (v17 & 0x4000) != 0 )
              {
                v6 = v16->m_Components.p[20].m_pComponent;
              }
              else if ( v17 >= 0 )
              {
                if ( (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
                  ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v16,
                                      UFG::TargetingSystemBaseComponent::_TypeUID);
                else
                  ComponentOfType = UFG::SimObject::GetComponentOfType(v16, UFG::TargetingSystemBaseComponent::_TypeUID);
                v6 = ComponentOfType;
              }
              else
              {
                v6 = v16->m_Components.p[20].m_pComponent;
              }
            }
            v19 = (UFG::TargetingSystemBaseComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))v6->vfptr[15].__vecDelDtor)(v6);
            if ( v19 )
              UFG::TargetingSystemBaseComponent::SetTarget(v19, eTARGET_TYPE_LAST_CREATED_OBJECT, (UFG::SimObject *)v11);
          }
        }
      }
    }
  }
}

// File Line: 1021
// RVA: 0x2F0780
void __fastcall ObjectCreateFromPropertiesTask::Begin(ObjectCreateFromPropertiesTask *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *v3; // rdi
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  ITrack *m_Track; // rdx
  UFG::qSymbol *v9; // rax
  unsigned int mUID; // eax
  ITrack *v11; // rax
  UFG::SimObjectCVBase *v12; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  UFG::SimObject *v17; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector4 v19; // xmm2
  UFG::qVector4 v20; // xmm1
  UFG::qVector4 v21; // xmm0
  UFG::qPropertySet *PropertySet; // r14
  char *v23; // rbx
  char *v24; // rax
  UFG::SimObject *v25; // rbx
  UFG::SimObject *v26; // r8
  __int16 v27; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v29; // rcx
  UFG::SimObjectGame *v30; // rcx
  __int16 v31; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TargetingSystemBaseComponent *v33; // rax
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-D0h] BYREF
  char dest[256]; // [rsp+70h] [rbp-90h] BYREF
  UFG::qSymbol propSetName; // [rsp+1A8h] [rbp+A8h] BYREF
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+1B0h] [rbp+B0h] BYREF
  UFG::qSymbol result; // [rsp+1B8h] [rbp+B8h] BYREF

  m_pPointer = pContext->mSimObject.m_pPointer;
  v3 = 0i64;
  if ( !m_pPointer || (m_pSceneObj = m_pPointer->m_pSceneObj) == 0i64 )
  {
    mpWritableProperties = 0i64;
LABEL_6:
    if ( !mpWritableProperties )
      return;
    goto LABEL_7;
  }
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  m_Track = this->m_Track;
  propSetName.mUID = -1;
  v9 = UFG::qPropertySet::Get<UFG::qSymbol>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&m_Track[1],
         DEPTH_RECURSE);
  if ( v9 )
  {
    mUID = v9->mUID;
    transform.v0 = UFG::qMatrix44::msIdentity.v0;
    propSetName.mUID = mUID;
    v11 = this->m_Track;
    transform.v1 = UFG::qMatrix44::msIdentity.v1;
    transform.v2 = UFG::qMatrix44::msIdentity.v2;
    transform.v3 = UFG::qMatrix44::msIdentity.v3;
    if ( BYTE4(v11[1].vfptr) )
    {
      v12 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        m_Flags = v12->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12);
        }
        else if ( (m_Flags & 0x2000) != 0 )
        {
          v14 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v12);
        }
        else
        {
          v14 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
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
          if ( mCreature )
          {
            if ( mCreature->mPose.mRigHandle.mData )
            {
              BoneID = Skeleton::GetBoneID(
                         mCreature->mPose.mRigHandle.mUFGSkeleton,
                         (unsigned int)this->m_Track[1].mResourceOwner);
              Creature::GetTransform(mCreature, BoneID, &transform);
            }
            else
            {
              Creature::GetTransform(mCreature, -1, &transform);
            }
          }
        }
      }
    }
    else
    {
      v17 = pContext->mSimObject.m_pPointer;
      if ( v17 )
      {
        m_pTransformNodeComponent = v17->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          v19 = m_pTransformNodeComponent->mWorldTransform.v2;
          v20 = m_pTransformNodeComponent->mWorldTransform.v3;
          v21 = m_pTransformNodeComponent->mWorldTransform.v0;
          transform.v1 = m_pTransformNodeComponent->mWorldTransform.v1;
          transform.v2 = v19;
          transform.v0 = v21;
          transform.v3 = v20;
        }
      }
    }
    PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName);
    if ( PropertySet )
    {
      v23 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pContext->mSimObject.m_pPointer->m_Name);
      v24 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
      UFG::qSPrintf(dest, "%s_CreatedItem_%s", v23, v24);
      UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, dest);
      UFG::SpawnInfoInterface::GetSpawnPriority(PropertySet, &pPriority);
      v25 = UFG::SpawnInfoInterface::SpawnObject(&result, PropertySet, &transform, pPriority, 0i64, 0i64);
      if ( v25 )
      {
        v26 = pContext->mSimObject.m_pPointer;
        if ( v26 )
        {
          v27 = v26->m_Flags;
          if ( (v27 & 0x4000) != 0 )
          {
            m_pComponent = v26->m_Components.p[20].m_pComponent;
          }
          else if ( v27 >= 0 )
          {
            v29 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
            if ( (v27 & 0x2000) != 0 || (v27 & 0x1000) != 0 )
              m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              m_pComponent = UFG::SimObject::GetComponentOfType(v29, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            m_pComponent = v26->m_Components.p[20].m_pComponent;
          }
          if ( m_pComponent )
          {
            v30 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
            if ( v30 )
            {
              v31 = v30->m_Flags;
              if ( (v31 & 0x4000) != 0 )
              {
                v3 = v30->m_Components.p[20].m_pComponent;
              }
              else if ( v31 >= 0 )
              {
                if ( (v31 & 0x2000) != 0 || (v31 & 0x1000) != 0 )
                  ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v30,
                                        UFG::TargetingSystemBaseComponent::_TypeUID);
                else
                  ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                        v30,
                                        UFG::TargetingSystemBaseComponent::_TypeUID);
                v3 = ComponentOfTypeHK;
              }
              else
              {
                v3 = v30->m_Components.p[20].m_pComponent;
              }
            }
            v33 = (UFG::TargetingSystemBaseComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))v3->vfptr[15].__vecDelDtor)(v3);
            if ( v33 )
              UFG::TargetingSystemBaseComponent::SetTarget(v33, eTARGET_TYPE_LAST_CREATED_OBJECT, v25);
          }
        }
      }
    }
  }
}

// File Line: 1083
// RVA: 0x2EF6C0
void __fastcall HideTask::Begin(HideTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CompositeDrawableComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[14].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[9].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[14].m_pComponent;
    }
    if ( m_pComponent )
      UFG::CompositeDrawableComponent::SetIsHidden(m_pComponent, 1);
  }
}

// File Line: 1096
// RVA: 0x2FA3C0
void __fastcall UnhideTask::Begin(UnhideTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CompositeDrawableComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[14].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[9].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[14].m_pComponent;
    }
    if ( m_pComponent )
      UFG::CompositeDrawableComponent::SetIsHidden(m_pComponent, 0);
  }
}

// File Line: 1108
// RVA: 0x2EF7D0
void __fastcall InputSignalLerpFilterTask::Begin(InputSignalLerpFilterTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  UFG::SimObject *m_pPointer; // rdi
  FloatInputSignal v4; // esi
  float v6; // xmm0_4
  float v7; // xmm1_4
  ITrack *v8; // rax

  m_Track = this->m_Track;
  this->mContext = context;
  m_pPointer = context->mSimObject.m_pPointer;
  v4 = BYTE1(m_Track[1].vfptr);
  if ( m_pPointer )
    m_pPointer = (UFG::SimObject *)m_pPointer->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
  v6 = *((float *)&m_pPointer[1].vfptr + 1);
  v7 = *(float *)&m_pPointer[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
  this->mStartFacingVector.x = *(float *)&m_pPointer[1].vfptr;
  v8 = this->m_Track;
  this->mStartFacingVector.y = v6;
  this->mStartFacingVector.z = v7;
  if ( BYTE4(v8[1].mMasterRate.expression.mOffset) )
    setSignalValue(this->mContext, v4, *(float *)&v8[1].mMasterRate.expression.mOffset);
  ((void (__fastcall *)(InputSignalLerpFilterTask *))this->vfptr->Update)(this);
}

// File Line: 1123
// RVA: 0x304670
char __fastcall InputSignalFilterTask::Update(InputSignalFilterTask *this, float timeDelta)
{
  ITrack *m_Track; // rax
  FloatInputSignal vfptr_low; // esi
  FloatInputSignal v5; // r14d
  UFG::SimObjectCVBase *Target; // rbx
  UFG::SimObject *v8; // rax
  float y; // xmm1_4
  UFG::SimObjectCVBase *v10; // rdi
  float z; // xmm0_4
  float SignalValue; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm7_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float *v17; // rax
  float v18; // xmm0_4
  UFG::qVector3 v20; // [rsp+30h] [rbp-38h] BYREF

  m_Track = this->m_Track;
  vfptr_low = LOBYTE(m_Track[1].vfptr);
  v5 = BYTE1(m_Track[1].vfptr);
  Target = (UFG::SimObjectCVBase *)UFG::getTarget(
                                     this->mContext->mSimObject.m_pPointer,
                                     (UFG::eTargetTypeEnum)HIDWORD(m_Track[1].vfptr));
  v8 = UFG::getTarget(
         this->mContext->mSimObject.m_pPointer,
         (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].mResourceOwner));
  y = this->mStartFacingVector.y;
  v10 = (UFG::SimObjectCVBase *)v8;
  v20.x = this->mStartFacingVector.x;
  z = this->mStartFacingVector.z;
  v20.y = y;
  v20.z = z;
  SignalValue = getSignalValue(Target, vfptr_low, timeDelta, 6.2831855, &v20);
  v13 = this->mStartFacingVector.y;
  v14 = SignalValue;
  v20.x = this->mStartFacingVector.x;
  v15 = this->mStartFacingVector.z;
  v20.y = v13;
  v20.z = v15;
  v16 = getSignalValue(v10, v5, timeDelta, 6.2831855, &v20);
  v17 = (float *)this->m_Track;
  v18 = v16 + (float)((float)((float)((float)(v14 + v17[17]) * v17[18]) - v16) * v17[19]);
  if ( v18 <= v17[20] )
    v18 = v17[20];
  if ( v18 >= v17[21] )
    v18 = v17[21];
  setSignalValue(this->mContext, v5, v18);
  return 1;
}

// File Line: 1184
// RVA: 0x3047D0
char __fastcall InputSignalLerpFilterTask::Update(InputSignalLerpFilterTask *this, float timeDelta)
{
  ITrack *m_Track; // rdx
  __int64 vfptr_low; // r14
  __int64 v6; // rsi
  UFG::SimObjectCVBase *Target; // rbx
  UFG::SimObjectCVBase *v8; // rdi
  float y; // xmm1_4
  float z; // xmm0_4
  float SignalValue; // xmm8_4
  float v12; // xmm2_4
  float v13; // xmm4_4
  float v14; // xmm6_4
  float *v15; // rax
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm6_4
  UFG::qVector3 v21; // [rsp+38h] [rbp-70h] BYREF
  UFG::qString result; // [rsp+48h] [rbp-60h] BYREF

  m_Track = this->m_Track;
  vfptr_low = LOBYTE(m_Track[1].vfptr);
  v6 = BYTE1(m_Track[1].vfptr);
  Target = (UFG::SimObjectCVBase *)UFG::getTarget(
                                     this->mContext->mSimObject.m_pPointer,
                                     (UFG::eTargetTypeEnum)HIDWORD(m_Track[1].vfptr));
  v8 = (UFG::SimObjectCVBase *)UFG::getTarget(
                                 this->mContext->mSimObject.m_pPointer,
                                 (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].mResourceOwner));
  y = this->mStartFacingVector.y;
  z = this->mStartFacingVector.z;
  v21.x = this->mStartFacingVector.x;
  v21.y = y;
  v21.z = z;
  SignalValue = getSignalValue(Target, (FloatInputSignal)vfptr_low, timeDelta, 6.2831855, &v21);
  v12 = this->mStartFacingVector.y;
  v13 = this->mStartFacingVector.z;
  v21.x = this->mStartFacingVector.x;
  v21.y = v12;
  v21.z = v13;
  v14 = getSignalValue(v8, (FloatInputSignal)v6, timeDelta, 6.2831855, &v21);
  v15 = (float *)this->m_Track;
  v16 = v15[18];
  v17 = v15[20];
  if ( SignalValue <= v16 )
    v18 = v15[18];
  else
    v18 = SignalValue;
  if ( v18 >= v15[19] )
    v18 = v15[19];
  v19 = v14
      + (float)((float)((float)((float)((float)((float)(v18 - v16) * (float)(v15[21] - v17)) / (float)(v15[19] - v16))
                              + v17)
                      - v14)
              * v15[17]);
  if ( v19 <= v17 )
    v19 = v15[20];
  if ( v19 >= v15[21] )
    v19 = v15[21];
  setSignalValue(this->mContext, (FloatInputSignal)v6, v19);
  UFG::qString::FormatEx(
    &result,
    "InputSignalLerpFilterTask::%s:%.3f -> %s:%.3f",
    gFloatInputSignalStringList[vfptr_low],
    SignalValue,
    gFloatInputSignalStringList[v6],
    v19);
  UFG::qString::~qString(&result);
  return 1;
}

// File Line: 1236
// RVA: 0x30EC40
char __fastcall InputEnableMappingTask::updateMapping(InputEnableMappingTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerComponent *v5; // rax
  ITrack *m_Track; // rcx

  if ( UFG::UI::gUIInputLocked )
    return 0;
  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(m_pPointer);
    else
      v5 = (UFG::AICharacterControllerComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::AICharacterControllerComponent::_TypeUID)
                                                 : UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::AICharacterControllerComponent::_TypeUID));
    if ( v5 )
    {
      m_Track = this->m_Track;
      if ( LOBYTE(m_Track[1].vfptr) )
      {
        UFG::SetInputMode(IM_ON_FOOT, v5->m_ControllerID);
        return 1;
      }
      if ( BYTE1(m_Track[1].vfptr) )
        UFG::SetInputMode(IM_DRIVING, v5->m_ControllerID);
    }
  }
  return 1;
}

// File Line: 1266
// RVA: 0x304650
bool __fastcall InputEnableMappingTask::Update(InputEnableMappingTask *this, float timeDelta)
{
  return !InputEnableMappingTask::updateMapping(this);
}

// File Line: 1276
// RVA: 0x2F3730
void __fastcall SetOpeningBranchTask::Begin(SetOpeningBranchTask *this, ActionContext *pContext)
{
  ITrack *m_Track; // r9
  Expression::IMemberMapVtbl *vfptr; // rax
  Expression::IMemberMap *(__fastcall *GetResourceOwner)(Expression::IMemberMap *); // rcx
  ActionNode *v5; // r8
  ActionContext *i; // rax

  m_Track = this->m_Track;
  vfptr = m_Track[1].vfptr;
  if ( vfptr )
    vfptr = (Expression::IMemberMapVtbl *)((char *)&vfptr->ResolveReferences + (_QWORD)m_Track);
  GetResourceOwner = vfptr->GetResourceOwner;
  if ( GetResourceOwner )
  {
    v5 = (ActionNode *)((char *)&vfptr->GetResourceOwner + (_QWORD)GetResourceOwner);
    if ( v5 )
    {
      if ( LOBYTE(m_Track[1].mResourceOwner) )
      {
        for ( i = pContext->mParentContext; i; i = i->mParentContext )
          pContext = i;
      }
      if ( pContext )
        pContext->m_OpeningBranch = v5;
    }
  }
}

