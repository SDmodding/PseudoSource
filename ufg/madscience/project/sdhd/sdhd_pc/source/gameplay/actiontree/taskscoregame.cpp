// File Line: 71
// RVA: 0x2FD840
UFG::qPropertySet *__fastcall UFG::CreateObject(ActionContext *pContext, UFG::qSymbol *propertySet, UFG::qMatrix44 *xform, UFG::SpawnInfoInterface::SpawnPriority *pOverridePriority)
{
  ActionContext *v4; // rbx
  UFG::SpawnInfoInterface::SpawnPriority *v5; // rsi
  UFG::qMatrix44 *v6; // r14
  UFG::qSymbol *v7; // rbp
  UFG::qPropertySet *v8; // rax
  UFG::qPropertySet *v9; // rdi
  char *v10; // rbx
  char *v11; // rax
  UFG::SpawnInfoInterface::SpawnPriority v12; // er9
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+30h] [rbp-118h]
  UFG::qSymbol result; // [rsp+34h] [rbp-114h]
  char dest; // [rsp+40h] [rbp-108h]

  v4 = pContext;
  v5 = pOverridePriority;
  v6 = xform;
  v7 = propertySet;
  v8 = UFG::PropertySetManager::GetPropertySet(propertySet);
  v9 = v8;
  if ( v8 )
  {
    v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->mSimObject.m_pPointer->m_Name);
    v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v7);
    UFG::qSPrintf(&dest, "%s_CreatedItem_%s", v10, v11);
    UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, &dest);
    if ( v5 )
    {
      v12 = *v5;
      pPriority = *v5;
    }
    else
    {
      UFG::SpawnInfoInterface::GetSpawnPriority(v9, &pPriority);
      v12 = pPriority;
    }
    v8 = (UFG::qPropertySet *)UFG::SpawnInfoInterface::SpawnObject(&result, v9, v6, v12, 0i64, 0i64);
  }
  return v8;
}

// File Line: 114
// RVA: 0x30D350
float __fastcall getRotationDelta(float timeDelta, float turnRate, UFG::qVector3 *currentFacing, UFG::qVector3 *leftFacing, UFG::qVector3 *motionIntention)
{
  UFG::qVector3 *v5; // rdi
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm2_4

  v5 = leftFacing;
  v6 = timeDelta;
  v7 = UFG::qAngleBetween(motionIntention, currentFacing);
  v8 = v7;
  if ( sNewTurn )
  {
    v9 = (float)(v6 * turnRate) * sTurnGain;
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
  if ( (float)((float)((float)(v5->y * motionIntention->y) + (float)(v5->x * motionIntention->x))
             + (float)(v5->z * motionIntention->z)) < 0.0 )
    LODWORD(v8) ^= _xmm[0];
  return v8;
}

// File Line: 152
// RVA: 0x2EFFC0
void __fastcall LocomotionTask::Begin(LocomotionTask *this, ActionContext *context)
{
  LocomotionTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rdx
  unsigned __int16 v5; // dx
  unsigned int v6; // edx
  UFG::SimComponent *v7; // rax
  bool v8; // zf

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[36].m_pComponent;
      goto LABEL_12;
    }
    if ( (v5 & 0x8000u) != 0 || (v5 >> 13) & 1 )
    {
      v6 = UFG::NavComponent::_TypeUID;
    }
    else
    {
      v8 = ((v5 >> 12) & 1) == 0;
      v6 = UFG::NavComponent::_TypeUID;
      if ( v8 )
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::NavComponent::_TypeUID);
        goto LABEL_11;
      }
    }
    v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, v6);
LABEL_11:
    v4 = v7;
    goto LABEL_12;
  }
  v4 = 0i64;
LABEL_12:
  ++LOBYTE(v4[2].m_BoundComponentHandles.mNode.mNext);
  *((float *)&v4[2].m_BoundComponentHandles.mNode.mPrev + 1) = sTurnGain * *(float *)&v2->m_Track[1].vfptr;
}

// File Line: 163
// RVA: 0x305040
char __fastcall LocomotionTask::Update(LocomotionTask *this, float timeDelta)
{
  LocomotionTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  float v6; // xmm8_4
  __m128 v7; // xmm9
  float v8; // xmm6_4
  __m128 v9; // xmm1
  float v10; // xmm3_4
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
  int v21; // xmm15_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  ITrack *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
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
  UFG::qMatrix44 m; // [rsp+30h] [rbp-D0h]
  float v40; // [rsp+70h] [rbp-90h]
  float v41; // [rsp+74h] [rbp-8Ch]
  float v42; // [rsp+78h] [rbp-88h]
  int v43; // [rsp+80h] [rbp-80h]
  int v44; // [rsp+84h] [rbp-7Ch]
  int v45; // [rsp+88h] [rbp-78h]
  float v46; // [rsp+90h] [rbp-70h]
  float v47; // [rsp+94h] [rbp-6Ch]
  float v48; // [rsp+98h] [rbp-68h]
  UFG::qMatrix44 dest; // [rsp+A0h] [rbp-60h]
  int v50; // [rsp+1A0h] [rbp+A0h]
  float v51; // [rsp+1A0h] [rbp+A0h]
  float v52; // [rsp+1A8h] [rbp+A8h]
  int v53; // [rsp+1B0h] [rbp+B0h]
  float v54; // [rsp+1B0h] [rbp+B0h]

  v52 = timeDelta;
  v2 = this;
  v3 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      else
        v5 = (UFG::AICharacterControllerBaseComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            (UFG::SimObjectGame *)&v3->vfptr,
                                                                            UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    if ( v5 )
    {
      v6 = v5->m_Intention.mMotionIntentionDirection.x;
      v7 = (__m128)LODWORD(v5->m_Intention.mMotionIntentionDirection.y);
      v8 = 0.0;
      v9 = v7;
      v10 = 0.0;
      v9.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v6 * v6);
      LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v9);
      if ( v11 < 0.0 )
        LODWORD(v11) ^= _xmm[0];
      if ( v11 < 0.001 )
      {
        v6 = UFG::qVector3::msAxisX.x;
        v7 = (__m128)LODWORD(UFG::qVector3::msAxisX.y);
        v10 = UFG::qVector3::msAxisX.z;
      }
      v12 = *(float *)&FLOAT_1_0;
      v13 = v7;
      v13.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v6 * v6)) + (float)(v10 * v10);
      if ( v13.m128_f32[0] != 0.0 )
        v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
      v14 = v6 * v8;
      v15 = v7.m128_f32[0] * v8;
      v16 = v2->mContext->mSimObject.m_pPointer;
      v17 = v8 * v10;
      if ( v16 )
        v16 = (UFG::SimObject *)v16->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
      v18 = *(float *)&v16[1].vfptr;
      v19 = *((float *)&v16[1].vfptr + 1);
      v20 = *(float *)&v16[1].m_SafePointerList.mNode.mPrev;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
      v21 = (int)v16[1].m_SafePointerList.mNode.mNext;
      v50 = HIDWORD(v16[1].m_SafePointerList.mNode.mNext);
      v53 = (int)v16[1].m_SafePointerWithCallbackList.mNode.mPrev;
      v22 = (float)((float)(v18 * v14) + (float)(v19 * v15)) + (float)(v20 * v17);
      if ( v22 <= -1.0 )
      {
        v22 = FLOAT_N1_0;
      }
      else if ( v22 >= 1.0 )
      {
        v22 = *(float *)&FLOAT_1_0;
      }
      v23 = cosf(*((float *)&v2->m_Track[1].vfptr + 1));
      if ( v23 <= -1.0 )
      {
        v23 = FLOAT_N1_0;
      }
      else if ( v23 >= 1.0 )
      {
        goto LABEL_29;
      }
      v12 = v23;
LABEL_29:
      if ( v22 >= v12 || !UFG::IsAnyLocalPlayer(v2->mContext->mSimObject.m_pPointer) )
      {
        v24 = v2->m_Track;
        v46 = v14;
        v47 = v15;
        v48 = v17;
        v44 = v50;
        v45 = v53;
        v40 = v18;
        v41 = v19;
        v42 = v20;
        v25 = *(float *)&v24[1].vfptr;
        v43 = v21;
        v26 = getRotationDelta(v52, v25, (UFG::qVector3 *)&v40, (UFG::qVector3 *)&v43, (UFG::qVector3 *)&v46);
        UFG::qRotationMatrixZ(&dest, v26);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
        v27 = *(float *)&v16[1].m_SafePointerList.mNode.mPrev;
        v28 = *((float *)&v16[1].m_SafePointerList.mNode.mPrev + 1);
        v29 = *(float *)&v16[1].vfptr;
        m.v0.y = *((float *)&v16[1].vfptr + 1);
        m.v0.x = v29;
        m.v0.w = v28;
        m.v0.z = v27;
        v30 = *(float *)&v16[1].m_SafePointerWithCallbackList.mNode.mPrev;
        v31 = *((float *)&v16[1].m_SafePointerWithCallbackList.mNode.mPrev + 1);
        v32 = *(float *)&v16[1].m_SafePointerList.mNode.mNext;
        m.v1.y = *((float *)&v16[1].m_SafePointerList.mNode.mNext + 1);
        m.v1.w = v31;
        m.v1.x = v32;
        m.v1.z = v30;
        v33 = *((float *)&v16[1].m_SafePointerWithCallbackList.mNode.mNext + 1);
        v34 = *(float *)&v16[1].m_SafePointerWithCallbackList.mNode.mNext;
        v35 = *(float *)&v16[1].mNode.mParent;
        m.v2.w = *((float *)&v16[1].mNode.mParent + 1);
        m.v2.x = v34;
        m.v2.y = v33;
        m.v2.z = v35;
        v36 = *((float *)v16[1].mNode.mChild + 1);
        v37 = *(float *)v16[1].mNode.mChild;
        v51 = *(float *)&v16[1].mNode.mChild[1];
        v54 = *((float *)&v16[1].mNode.mChild[1] + 1);
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
        m.v3.z = v51;
        m.v3.y = v36;
        m.v3.w = v54;
        UFG::TransformNodeComponent::SetWorldTransform((UFG::TransformNodeComponent *)v16, &m);
      }
      return 1;
    }
  }
  return 1;
}

// File Line: 211
// RVA: 0x2FF1C0
void __fastcall LocomotionTask::End(LocomotionTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  unsigned int v3; // edx
  UFG::SimComponent *v4; // rax
  bool v5; // zf
  UFG::SimComponent *v6; // rax

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( !v1 )
  {
    --MEMORY[0xB8];
    return;
  }
  v2 = v1->m_Flags;
  if ( (v2 >> 14) & 1 )
  {
    --LOBYTE(v1->m_Components.p[36].m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
    return;
  }
  if ( (v2 & 0x8000u) != 0 || (v2 >> 13) & 1 )
  {
    v3 = UFG::NavComponent::_TypeUID;
LABEL_7:
    v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, v3);
    --LOBYTE(v4[2].m_BoundComponentHandles.mNode.mNext);
    return;
  }
  v5 = ((v2 >> 12) & 1) == 0;
  v3 = UFG::NavComponent::_TypeUID;
  if ( !v5 )
    goto LABEL_7;
  v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::NavComponent::_TypeUID);
  --LOBYTE(v6[2].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 220
// RVA: 0x2EFE50
void __fastcall Locomotion2Task::Begin(Locomotion2Task *this, ActionContext *context)
{
  Locomotion2Task *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rdi
  unsigned __int16 v5; // dx
  UFG::AICharacterControllerBaseComponent *v6; // rax
  float v7; // xmm1_4
  float v8; // ecx
  float v9; // xmm0_4
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  unsigned int v12; // edx
  UFG::SimComponent *v13; // rax
  bool v14; // zf

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      else
        v6 = (UFG::AICharacterControllerBaseComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            (UFG::SimObjectGame *)&v3->vfptr,
                                                                            UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    if ( v6 )
    {
      v7 = v6->m_Intention.mCurrentRotationInput;
      if ( v7 < 0.0 )
      {
        v8 = *((float *)&v2->m_Track[1].vfptr + 1);
        *(_QWORD *)&v2->mAccel = 0i64;
        v2->mCurrentRotation = v8;
      }
      else
      {
        v2->mCurrentRotation = v7;
        v2->mAccel = v6->m_Intention.mCurrentRotationAccel;
        v2->mAngularVel = v6->m_Intention.mCurrentRotationAngularVel;
      }
      v9 = v2->mAngularVel;
      v2->mValueBuff[3] = v9;
      v2->mValueBuff[2] = v9;
      v2->mValueBuff[1] = v9;
      v2->mValueBuff[0] = v9;
    }
  }
  v10 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v4 = v10->m_Components.p[36].m_pComponent;
      goto LABEL_26;
    }
    if ( (v11 & 0x8000u) != 0 || (v11 >> 13) & 1 )
    {
      v12 = UFG::NavComponent::_TypeUID;
    }
    else
    {
      v14 = ((v11 >> 12) & 1) == 0;
      v12 = UFG::NavComponent::_TypeUID;
      if ( v14 )
      {
        v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::NavComponent::_TypeUID);
        goto LABEL_25;
      }
    }
    v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, v12);
LABEL_25:
    v4 = v13;
  }
LABEL_26:
  ++LOBYTE(v4[2].m_BoundComponentHandles.mNode.mNext);
  HIDWORD(v4[2].m_BoundComponentHandles.mNode.mPrev) = HIDWORD(v2->m_Track[1].vfptr);
}

// File Line: 260
// RVA: 0x3049E0
char __fastcall Locomotion2Task::Update(Locomotion2Task *this, float timeDelta)
{
  float xmm9_4_1; // xmm9_4
  Locomotion2Task *v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  UFG::TransformNodeComponent *v5; // rsi
  UFG::AICharacterControllerBaseComponent *v6; // rdi
  unsigned __int16 v7; // dx
  UFG::AICharacterControllerBaseComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm2_4
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  ITrack *v16; // rax
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float *v25; // rax
  float v26; // xmm1_4
  float v27; // xmm6_4
  float v28; // xmm6_4
  float v29; // xmm1_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm14_4
  float v35; // xmm15_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-D8h]
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C8h]
  __int128 v1; // [rsp+70h] [rbp-88h]
  UFG::qMatrix44 dest; // [rsp+88h] [rbp-70h]

  *((_QWORD *)&v1 + 1) = -2i64;
  xmm9_4_1 = timeDelta;
  v3 = this;
  v4 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  v5 = 0i64;
  if ( v4 )
  {
    v7 = v4->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v4->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v4->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v4->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
    }
    v6 = v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = (UFG::SimObjectGame *)v3->mContext->mSimObject.m_pPointer;
  if ( v9 )
    v5 = v9->m_pTransformNodeComponent;
  if ( v6 && v5 )
  {
    v10 = v6->m_Intention.mMotionIntentionDirection.y;
    v11 = v6->m_Intention.mMotionIntentionDirection.z;
    v2.x = v6->m_Intention.mMotionIntentionDirection.x;
    v2.y = v10;
    v2.z = v11;
    if ( BYTE1(v3->m_Track[1].m_TrackClassNameUID) && v9 )
    {
      v12 = v9->m_Flags;
      if ( (v12 >> 14) & 1 )
      {
        v13 = v9->m_Components.p[47].m_pComponent;
      }
      else if ( (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::AimingBaseComponent::_TypeUID);
        else
          v13 = (v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::AimingBaseComponent::_TypeUID);
      }
      if ( v13 )
      {
        v14 = *(float *)&v13[2].m_SafePointerList.mNode.mNext;
        v15 = *((float *)&v13[2].m_SafePointerList.mNode.mNext + 1);
        v2.x = *((float *)&v13[2].m_SafePointerList.mNode.mPrev + 1);
        v2.y = v14;
        v2.z = v15;
      }
    }
    v16 = v3->m_Track;
    v17 = *((float *)&v16[1].vfptr + 1);
    v18 = (float)((float)(*((float *)&v16[1].vfptr + 1) - v3->mCurrentRotation) * sRateGain) + v3->mCurrentRotation;
    v3->mCurrentRotation = v18;
    if ( v18 <= 0.0 )
      v18 = 0.0;
    if ( v18 >= v17 )
      v18 = v17;
    v3->mCurrentRotation = v18;
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    v19 = v5->mWorldTransform.v0.y;
    v20 = v5->mWorldTransform.v0.z;
    *(float *)&v1 = v5->mWorldTransform.v0.x;
    *(_QWORD *)((char *)&v1 + 4) = __PAIR__(LODWORD(v20), LODWORD(v19));
    v21 = (float)((float)(v2.y * v19) + (float)(v2.x * *(float *)&v1)) + (float)(v2.z * v20);
    v22 = *(float *)&FLOAT_1_0;
    if ( v21 <= -1.0 )
    {
      v21 = FLOAT_N1_0;
    }
    else if ( v21 >= 1.0 )
    {
      v21 = *(float *)&FLOAT_1_0;
    }
    v23 = cosf(*(float *)&v3->m_Track[1].vfptr);
    if ( v23 <= -1.0 )
    {
      v23 = FLOAT_N1_0;
    }
    else if ( v23 >= 1.0 )
    {
      v23 = *(float *)&FLOAT_1_0;
    }
    if ( v21 >= v23 || !UFG::IsAnyLocalPlayer(v3->mContext->mSimObject.m_pPointer) )
    {
      v24 = UFG::qHeadingDifference2D((UFG::qVector3 *)&v1, &v2);
      if ( !UFG::IsAnyLocalPlayer(v3->mContext->mSimObject.m_pPointer) )
        v22 = FLOAT_2_0;
      v25 = (float *)v3->m_Track;
      v26 = v3->mAngularVel;
      v27 = (float)((float)(v24 * v25[16]) * v22) - (float)(v3->mAngularVel * v25[17]);
      v3->mAccel = v27;
      v28 = (float)(v27 * xmm9_4_1) + v26;
      v3->mAngularVel = v28;
      v29 = v25[15];
      if ( v28 <= COERCE_FLOAT(*((_DWORD *)v25 + 15) ^ _xmm[0]) )
        LODWORD(v28) = *((_DWORD *)v25 + 15) ^ _xmm[0];
      if ( v28 >= v29 )
        v28 = v25[15];
      v3->mAngularVel = v28;
      v30 = v28 * xmm9_4_1;
      v3->mValueBuff[3] = v3->mValueBuff[2];
      v3->mValueBuff[2] = v3->mValueBuff[1];
      v3->mValueBuff[1] = v3->mValueBuff[0];
      v31 = v3->mAngularVel;
      v3->mValueBuff[0] = v31;
      v32 = (float)((float)((float)(v31 + v3->mValueBuff[1]) + v3->mValueBuff[2]) + v3->mValueBuff[3]) * 0.25;
      if ( _S11_1 & 1 )
      {
        v33 = sMaxLeanAngle;
      }
      else
      {
        _S11_1 |= 1u;
        v33 = FLOAT_0_52359879;
        sMaxLeanAngle = FLOAT_0_52359879;
      }
      v6->m_Intention.mCurrentRotationSignal = (float)(v32 / v29) * v33;
      v6->m_Intention.mCurrentRotationAccel = v3->mAccel;
      v6->m_Intention.mCurrentRotationAngularVel = v3->mAngularVel;
      v6->m_IntentionUpdated = 1;
      UFG::qRotationMatrixZ(&dest, v30);
      UFG::TransformNodeComponent::UpdateWorldTransform(v5);
      m.v0.x = v5->mWorldTransform.v0.x;
      m.v0.y = v5->mWorldTransform.v0.y;
      m.v0.z = v5->mWorldTransform.v0.z;
      m.v0.w = v5->mWorldTransform.v0.w;
      m.v1.x = v5->mWorldTransform.v1.x;
      m.v1.y = v5->mWorldTransform.v1.y;
      m.v1.z = v5->mWorldTransform.v1.z;
      m.v1.w = v5->mWorldTransform.v1.w;
      m.v2.x = v5->mWorldTransform.v2.x;
      m.v2.y = v5->mWorldTransform.v2.y;
      m.v2.z = v5->mWorldTransform.v2.z;
      m.v2.w = v5->mWorldTransform.v2.w;
      v34 = v5->mWorldTransform.v3.x;
      v35 = v5->mWorldTransform.v3.y;
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
      m.v3 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 85), (__m128)dest.v1),
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 0), (__m128)dest.v0),
                                    (__m128)0i64)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 170), (__m128)dest.v2)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)_xmm, (__m128)_xmm, 255), (__m128)dest.v3));
      m.v3.x = v34;
      m.v3.y = v35;
      m.v3.z = v5->mWorldTransform.v3.z;
      m.v3.w = v5->mWorldTransform.v3.w;
      UFG::TransformNodeComponent::SetWorldTransform(v5, &m);
    }
  }
  return 1;
}

// File Line: 335
// RVA: 0x2FF070
void __fastcall Locomotion2Task::End(Locomotion2Task *this)
{
  Locomotion2Task *v1; // rdi
  UFG::SimComponent *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  unsigned int v8; // edx
  UFG::SimComponent *v9; // rax
  bool v10; // zf

  v1 = this;
  v2 = 0i64;
  v3 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      else
        v5 = (UFG::AICharacterControllerBaseComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            (UFG::SimObjectGame *)&v3->vfptr,
                                                                            UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    if ( v5 )
    {
      v5->m_Intention.mCurrentRotationInput = v1->mCurrentRotation;
      if ( !LOBYTE(v1->m_Track[1].m_TrackClassNameUID) )
        v5->m_Intention.mCurrentRotationSignal = 0.0;
      v5->m_Intention.mCurrentRotationAccel = v1->mAccel;
      v5->m_Intention.mCurrentRotationAngularVel = v1->mAngularVel;
      v5->m_IntentionUpdated = 1;
    }
  }
  v6 = (UFG::SimObjectGame *)v1->mContext->mSimObject.m_pPointer;
  if ( !v6 )
    goto LABEL_25;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    --LOBYTE(v6->m_Components.p[36].m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
    return;
  }
  if ( (v7 & 0x8000u) != 0 || (v7 >> 13) & 1 )
  {
    v8 = UFG::NavComponent::_TypeUID;
  }
  else
  {
    v10 = ((v7 >> 12) & 1) == 0;
    v8 = UFG::NavComponent::_TypeUID;
    if ( v10 )
    {
      v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::NavComponent::_TypeUID);
      goto LABEL_24;
    }
  }
  v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, v8);
LABEL_24:
  v2 = v9;
LABEL_25:
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
void __fastcall LocomotionParamTask::End(LocomotionParamTask *this)
{
  LocomotionParamTask::setParameters(this);
}

// File Line: 382
// RVA: 0x30E100
void __fastcall LocomotionParamTask::setParameters(LocomotionParamTask *this)
{
  LocomotionParamTask *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AICharacterControllerBaseComponent *v4; // rax
  ITrack *v5; // rcx

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
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
    {
      v5 = v1->m_Track;
      v4->m_Intention.mCurrentRotationInput = *(float *)&v5[1].vfptr;
      v4->m_Intention.mCurrentRotationSignal = *((float *)&v5[1].vfptr + 1);
      v4->m_Intention.mCurrentRotationAccel = *(float *)&v5[1].mResourceOwner;
      v4->m_Intention.mCurrentRotationAngularVel = *((float *)&v5[1].mResourceOwner + 1);
      v4->m_IntentionUpdated = 1;
    }
  }
}

// File Line: 402
// RVA: 0x2EFD00
void __fastcall JumpTask::Begin(JumpTask *this, ActionContext *context)
{
  JumpTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rdi
  float v8; // xmm4_4
  __m128 v9; // xmm5
  float v10; // xmm2_4
  __m128 v11; // xmm3
  ITrack *v12; // rax
  float v13; // xmm4_4
  float v14; // xmm5_4

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v4 = v6;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = v2->mContext->mSimObject.m_pPointer;
  if ( v7 )
    v7 = (UFG::SimObject *)v7->m_pTransformNodeComponent;
  if ( v4 && v7 )
  {
    HIDWORD(v4[9].vfptr) = v2->m_Track[1].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
    v8 = *(float *)&v7[1].vfptr;
    v9 = (__m128)HIDWORD(v7[1].vfptr);
    v10 = 0.0;
    v11 = v9;
    v11.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8))
                    + (float)(*(float *)&v7[1].m_SafePointerList.mNode.mPrev
                            * *(float *)&v7[1].m_SafePointerList.mNode.mPrev);
    if ( v11.m128_f32[0] != 0.0 )
      v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
    v12 = v2->m_Track;
    v13 = (float)(v8 * v10) * *((float *)&v12[1].vfptr + 1);
    v14 = (float)(v9.m128_f32[0] * v10) * *((float *)&v12[1].vfptr + 1);
    LODWORD(v4[6].m_pSimObject) = 0;
    *(float *)&v4[6].m_Flags = v13;
    *(float *)(&v4[6].m_SimObjIndex + 1) = v14;
  }
}

// File Line: 428
// RVA: 0x2FEFB0
void __fastcall JumpTask::End(JumpTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[27].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v3 )
    {
      v4 = UFG::qVector3::msZero.y;
      v5 = UFG::qVector3::msZero.z;
      *(float *)&v3[6].m_Flags = UFG::qVector3::msZero.x;
      *(float *)(&v3[6].m_SimObjIndex + 1) = v4;
      *(float *)&v3[6].m_pSimObject = v5;
    }
  }
}

// File Line: 441
// RVA: 0x149ED00
__int64 dynamic_initializer_for__qwsPlayTimeDilate__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayTimeDilate, "PLAY_TIME_DILATE");
  return atexit(dynamic_atexit_destructor_for__qwsPlayTimeDilate__);
}

// File Line: 442
// RVA: 0x149ED30
__int64 dynamic_initializer_for__qwsStopTimeDilate__()
{
  UFG::qWiseSymbol::create_from_string(&qwsStopTimeDilate, "STOP_TIME_DILATE");
  return atexit(dynamic_atexit_destructor_for__qwsStopTimeDilate__);
}

// File Line: 446
// RVA: 0x2F9D20
void __fastcall TimeWarpTask::Begin(TimeWarpTask *this, ActionContext *context)
{
  TimeWarpTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCharacter *v7; // rbx
  float *v8; // rax
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  unsigned int v16; // edx

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[23].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleDriverInterface::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleDriverInterface::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleDriverInterface::_TypeUID);
      }
      v4 = v6;
    }
    else
    {
      v4 = v3->m_Components.p[23].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  if ( !BYTE4(v2->m_Track[1].vfptr)
    || UFG::GetLocalPlayer() == (UFG::SimObjectCharacter *)v2->mContext->mSimObject.m_pPointer
    || v4 && (v7 = (UFG::SimObjectCharacter *)v4[3].m_BoundComponentHandles.mNode.mNext, v7 == UFG::GetLocalPlayer()) )
  {
    v8 = (float *)v2->m_Track;
    v9 = v8[13];
    v10 = v8[12];
    v11 = v8[14];
    v2->mCurrentStrength = UFG::Metrics::msInstance.mSimTimeScaleInGame;
    v12 = v8[16];
    if ( v10 >= 0.0 && v9 >= 0.0 && v12 > (float)((float)(v9 - v10) * 0.5) )
      v12 = (float)(v9 - v10) * 0.5;
    v13 = v11 - v2->mCurrentStrength;
    if ( v12 <= 0.0 )
      v14 = v13 * 3.4028233e32;
    else
      v14 = v13 / v12;
    v2->mDeltaStrength = v14;
    v2->mActivated = 1;
    if ( v12 == 0.0 )
    {
      if ( !bRestrictSimTimeScaleChange )
      {
        if ( v11 <= 0.0 )
          v15 = 0.0;
        else
          v15 = v11;
        if ( v15 >= UFG::Metrics::msInstance.mSimTimeScaleMax )
          v15 = UFG::Metrics::msInstance.mSimTimeScaleMax;
        UFG::Metrics::msInstance.mSimTimeScaleInGame = v15;
        UFG::Metrics::msInstance.mSimPausedInGame = v15 == 0.0;
        UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      }
      v2->mDeltaStrength = 0.0;
      v2->mCurrentStrength = v11;
    }
    v16 = *(_DWORD *)&v2->m_Track[1].mBreakPoint;
    if ( v16 && (v9 < 0.0 || (float)(v9 - v10) >= UFG::TidoGame::sm_timeWarpAudioLength) )
    {
      if ( UFG::AmbienceAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
          v16,
          0i64,
          0,
          0i64);
      if ( !(_S12_0 & 1) )
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
  float *v2; // r8
  float v3; // xmm0_4
  float v4; // xmm2_4
  bool result; // al

  if ( this->mActivated )
  {
    v2 = (float *)this->m_Track;
    if ( v2[13] >= 0.0 )
    {
      v3 = v2[12];
      if ( v3 >= 0.0
        && (float)(this->mContext->mActionController->m_ActionNodePlayTime - v3) > (float)((float)(v2[13] - v2[12]) * 0.5) )
      {
        LODWORD(this->mDeltaStrength) &= _xmm;
      }
    }
    v4 = (float)(timeDelta * this->mDeltaStrength) + this->mCurrentStrength;
    this->mCurrentStrength = v4;
    if ( v4 < v2[14] )
      v4 = v2[14];
    if ( v4 > 1.0 )
      v4 = *(float *)&FLOAT_1_0;
    if ( !bRestrictSimTimeScaleChange )
    {
      if ( v4 <= 0.0 )
        v4 = 0.0;
      if ( v4 >= UFG::Metrics::msInstance.mSimTimeScaleMax )
        v4 = UFG::Metrics::msInstance.mSimTimeScaleMax;
      UFG::Metrics::msInstance.mSimTimeScaleInGame = v4;
      if ( v4 == 0.0 )
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
  TimeWarpTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  bool v4; // al
  ITrack *v5; // rax
  unsigned int v6; // edx
  float v7; // xmm0_4

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( !((v3 >> 14) & 1) && (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleDriverInterface::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleDriverInterface::_TypeUID);
      }
      else
      {
        UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::VehicleDriverInterface::_TypeUID);
      }
    }
  }
  if ( v1->mActivated )
  {
    if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
      {
        v4 = 1;
LABEL_15:
        UFG::Metrics::msInstance.mSimPausedInGame = v4;
        UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
        v5 = v1->m_Track;
        v6 = v5[1].mMasterRate.text.mOffset;
        if ( v6 )
        {
          v7 = v5->mTimeEnd;
          if ( v7 < 0.0 || (float)(v7 - v5->mTimeBegin) >= UFG::TidoGame::sm_timeWarpAudioLength )
          {
            if ( UFG::AmbienceAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
                v6,
                0i64,
                0,
                0i64);
            if ( !(_S13_1 & 1) )
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
    goto LABEL_15;
  }
}

// File Line: 598
// RVA: 0x2EB640
void __fastcall DamageTask::Begin(DamageTask *this, ActionContext *context)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rbx
  DamageTask *v3; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // r8
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax

  v2 = &this->mpSource;
  this->mContext = context;
  v3 = this;
  if ( this->mpSource.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = this->mpSource.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    this->mpSource.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpSource.mPrev;
  }
  this->mpSource.m_pPointer = 0i64;
  if ( LODWORD(this->m_Track[1].mMasterRate.text.mOffset) )
  {
    v6 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = v6->m_Components.p[20].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v6,
                                  UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v6->vfptr,
                                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
        v8 = v9;
      }
      else
      {
        v8 = v6->m_Components.p[20].m_pComponent;
      }
      if ( v8 )
      {
        v10 = *(UFG::SimObject **)(56i64
                                 * *(unsigned __int8 *)(LODWORD(v3->m_Track[1].mMasterRate.text.mOffset)
                                                      + *(_QWORD *)&v8[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&v8[1].m_TypeUID
                                 + 40);
        if ( v2->m_pPointer )
        {
          v11 = v2->mPrev;
          v12 = v2->mNext;
          v11->mNext = v12;
          v12->mPrev = v11;
          v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
          v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
        }
        v2->m_pPointer = v10;
        if ( v10 )
        {
          v13 = v10->m_SafePointerList.mNode.mPrev;
          v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
          v2->mPrev = v13;
          v2->mNext = &v10->m_SafePointerList.mNode;
          v10->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
        }
      }
    }
  }
}

// File Line: 616
// RVA: 0x2FE8C0
void __fastcall DamageTask::End(DamageTask *this)
{
  DamageTask *v1; // r15
  UFG::SimObjectGame *v2; // rbx
  unsigned __int16 v3; // dx
  UFG::HealthComponent *v4; // rsi
  UFG::SimComponent *v5; // rax
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rdi
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // rbp
  UFG::HitRecord *v10; // r14
  int v11; // er15
  bool v12; // r14
  UFG::CopSystem *v13; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
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
      v6 = v2->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v2->m_Components.p[15].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID);
        }
        v7 = v8;
      }
      else
      {
        v7 = v2->m_Components.p[15].m_pComponent;
      }
      if ( v7 )
      {
        v9 = *(UFG::SimObject **)&v7[3].m_TypeUID;
        v10 = (UFG::HitRecord *)&v7[2].m_BoundComponentHandles.mNode.mNext;
      }
      else
      {
        v10 = 0i64;
        v9 = 0i64;
      }
      if ( v1->mpSource.m_pPointer )
        v9 = v1->mpSource.m_pPointer;
      v11 = ExpressionParameterInt::operator long((ExpressionParameterInt *)&v1->m_Track[1]);
      if ( UFG::IsAnyLocalPlayer(v9) )
        v11 = (signed int)(float)((float)(UFG::PlayerBuffTracker::GetGrappleDamageMultiplier() + 1.0) * (float)v11);
      v12 = UFG::HealthComponent::ApplyHealthDamage(v4, v11, v9, v10, 0);
      if ( v12 )
      {
        if ( v7 )
        {
          v13 = UFG::CopSystem::Instance();
          ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, UFG::SimObjectGame *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **, UFG::HealthComponent *, bool))v13->vfptr[95].__vecDelDtor)(
            v13,
            v9,
            v2,
            &v7[2].m_BoundComponentHandles.mNode.mNext,
            v4,
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
  ActionContext *v2; // r13
  HandleDamageTask *v3; // r15
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::HitReactionComponent *v6; // rbp
  UFG::HitReactionComponent *v7; // rax
  UFG::SimObjectGame *v8; // rdi
  UFG::TransformNodeComponent *v9; // rsi
  UFG::SimObject *v10; // rax
  UFG::TransformNodeComponent *v11; // rbx
  float v12; // xmm5_4
  float v13; // xmm4_4
  UFG::SimObjectGame *v14; // rcx
  unsigned __int16 v15; // dx
  UFG::HealthComponent *v16; // r14
  UFG::SimComponent *v17; // rax
  float v18; // xmm6_4
  bool v19; // si
  bool v20; // r15
  UFG::GameStatTracker *v21; // rax
  signed int v22; // ebx
  UFG::HitRecord *v23; // rax
  float v24; // xmm1_4
  int v25; // esi
  bool v26; // sf
  unsigned __int8 v27; // of
  unsigned __int16 v28; // cx
  UFG::SimComponent *v29; // rax
  unsigned __int16 v30; // cx
  UFG::SimComponent *v31; // rax
  UFG::SimObjectGame *v32; // rcx
  unsigned __int16 v33; // dx
  UFG::CharacterOccupantComponent *v34; // rax
  UFG::VehicleOccupantComponent *v35; // rax
  bool v36; // r12
  UFG::SimObjectCharacter *v37; // rax
  UFG::SimObjectCharacter *v38; // r8
  char v39; // bl
  int v40; // ecx
  char v41; // r15
  UFG::SimComponent *v42; // rbp
  unsigned __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  bool v45; // zf
  UFG::SimObjectGame *v46; // rcx
  unsigned int v47; // eax
  float v48; // xmm2_4
  UFG::CopSystem *v49; // rax
  unsigned __int16 v50; // cx
  UFG::FaceMeterComponent *v51; // rax
  int fOffsetRadians; // [rsp+28h] [rbp-C0h]
  bool bSteerWithNoTarget; // [rsp+30h] [rbp-B8h]
  bool bSteerUsingAimPosition; // [rsp+38h] [rbp-B0h]
  UFG::qVector3 *pOverrideTargetPosition; // [rsp+40h] [rbp-A8h]
  float v56; // [rsp+58h] [rbp-90h]
  float v57; // [rsp+5Ch] [rbp-8Ch]
  float v58; // [rsp+60h] [rbp-88h]
  UFG::FaceEventParameters parameters; // [rsp+68h] [rbp-80h]
  UFG::HitRecord *v60; // [rsp+F8h] [rbp+10h]

  v2 = context;
  v3 = this;
  v4 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v4 )
    return;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = (UFG::HitReactionComponent *)v4->m_Components.p[15].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v4,
                                          UFG::HitReactionComponent::_TypeUID);
    else
      v7 = (UFG::HitReactionComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v4,
                                                            UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v4->vfptr,
                                                                                                     UFG::HitReactionComponent::_TypeUID));
    v6 = v7;
  }
  else
  {
    v6 = (UFG::HitReactionComponent *)v4->m_Components.p[15].m_pComponent;
  }
  if ( !v6 )
    return;
  v8 = (UFG::SimObjectGame *)v6->mHitRecord.mAttacker.m_pPointer;
  if ( LOBYTE(v3->m_Track[1].mMasterRate.text.mOffset) && v8 )
  {
    if ( v6->mHitRecord.mMeleeInfo.mAttackFromBehind )
    {
      v9 = v8->m_pTransformNodeComponent;
      if ( !v9 )
        goto LABEL_23;
      v10 = v2->mSimObject.m_pPointer;
      if ( v10 )
        v11 = v10->m_pTransformNodeComponent;
      else
        v11 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      UFG::TransformNodeComponent::UpdateWorldTransform(v9);
      v12 = v11->mWorldTransform.v3.z + (float)(v11->mWorldTransform.v3.z - v9->mWorldTransform.v3.z);
      v13 = v11->mWorldTransform.v3.y + (float)(v11->mWorldTransform.v3.y - v9->mWorldTransform.v3.y);
      v56 = v11->mWorldTransform.v3.x + (float)(v11->mWorldTransform.v3.x - v9->mWorldTransform.v3.x);
      v57 = v13;
      v58 = v12;
      pOverrideTargetPosition = (UFG::qVector3 *)&v56;
      bSteerUsingAimPosition = 0;
    }
    else
    {
      pOverrideTargetPosition = 0i64;
      bSteerUsingAimPosition = 1;
    }
    bSteerWithNoTarget = 0;
    fOffsetRadians = 0;
    UFG::SteerToTarget(v2->mSimObject.m_pPointer, (UFG::SimObject *)&v8->vfptr, &UFG::gNullQSymbolUC, 6.0);
  }
LABEL_23:
  if ( v6->mHitRecord.mDamageHandled != 1 )
  {
    v14 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v14 )
    {
      v15 = v14->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = (UFG::HealthComponent *)v14->m_Components.p[6].m_pComponent;
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::HealthComponent::_TypeUID);
        else
          v17 = (v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::HealthComponent::_TypeUID);
        v16 = (UFG::HealthComponent *)v17;
      }
      else
      {
        v16 = (UFG::HealthComponent *)v14->m_Components.p[6].m_pComponent;
      }
      if ( v16 )
      {
        v60 = &v6->mHitRecord;
        v18 = (float)(signed int)ExpressionParameterInt::operator long((ExpressionParameterInt *)&v3->m_Track[1])
            * 0.0099999998;
        v19 = LocalPlayer == (UFG::SimObjectCharacter *)v2->mSimObject.m_pPointer;
        v20 = v6->mHitRecord.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue;
        if ( LocalPlayer == (UFG::SimObjectCharacter *)v6->mHitRecord.mAttacker.m_pPointer )
        {
          v21 = UFG::GameStatTracker::Instance();
          if ( (signed int)UFG::GameStatTracker::GetStat(v21, GunplayUpgradeStage) >= UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_iRequiredLevelForGunplayUpgradeDamage
            && UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fGunplayUpgradeDamageMultiplier > 0.0 )
          {
            v18 = v18 * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fGunplayUpgradeDamageMultiplier;
          }
        }
        v22 = 0;
        v23 = &v6->mHitRecord;
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
            v24 = (float)((float)v22 * 0.0099999998) * (float)(signed int)v16->m_fMaxHealth;
            if ( v24 > 0.0 && v18 > 0.0 )
            {
              v25 = (signed int)(float)(v24 * v18);
              v27 = __OFSUB__(v25, 1);
              v26 = v25 - 1 < 0;
              goto LABEL_62;
            }
            goto LABEL_65;
          }
        }
        else if ( v8 )
        {
          v28 = v8->m_Flags;
          if ( (v28 >> 14) & 1 )
          {
            v29 = v8->m_Components.p[15].m_pComponent;
          }
          else if ( (v28 & 0x8000u) == 0 )
          {
            if ( (v28 >> 13) & 1 )
              v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID);
            else
              v29 = (v28 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::HitReactionComponent::_TypeUID);
          }
          else
          {
            v29 = v8->m_Components.p[15].m_pComponent;
          }
          if ( v29 )
            v18 = v18 * (float)((float)*(signed int *)(&v29[1].m_SimObjIndex + 1) * 0.0099999998);
        }
        if ( v22 > 0 && v18 > 0.0 )
        {
          v25 = (signed int)(float)((float)v22 * v18);
          v27 = __OFSUB__(v25, 1);
          v26 = v25 - 1 < 0;
LABEL_62:
          if ( v26 ^ v27 )
            v25 = 1;
LABEL_66:
          if ( v8 )
          {
            v30 = v8->m_Flags;
            if ( (v30 >> 14) & 1 )
            {
              v31 = v8->m_Components.p[6].m_pComponent;
            }
            else if ( (v30 & 0x8000u) == 0 )
            {
              if ( (v30 >> 13) & 1 )
                v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HealthComponent::_TypeUID);
              else
                v31 = (v30 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::HealthComponent::_TypeUID);
            }
            else
            {
              v31 = v8->m_Components.p[6].m_pComponent;
            }
            if ( v31 && LOBYTE(v31[1].m_BoundComponentHandles.mNode.mNext) )
              v25 = (signed int)v16->m_fHealth;
          }
          if ( v6->mHitRecord.mAttackTypeID == gAttackCollisionExplosion.m_EnumValue )
          {
            v32 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
            if ( v32 )
            {
              v33 = v32->m_Flags;
              if ( (v33 >> 14) & 1 )
              {
                v34 = (UFG::CharacterOccupantComponent *)v32->m_Components.p[44].m_pComponent;
              }
              else if ( (v33 & 0x8000u) == 0 )
              {
                if ( (v33 >> 13) & 1 )
                  v34 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v32,
                                                             UFG::CharacterOccupantComponent::_TypeUID);
                else
                  v34 = (UFG::CharacterOccupantComponent *)((v33 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                v32,
                                                                                UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v32->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
              }
              else
              {
                v34 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v32,
                                                           UFG::CharacterOccupantComponent::_TypeUID);
              }
              if ( v34 )
              {
                v35 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v34);
                if ( v35 )
                {
                  if ( v8 == (UFG::SimObjectGame *)v35 )
                    v25 = (signed int)v16->m_fMaxHealth;
                }
              }
            }
          }
          v36 = UFG::HealthComponent::ApplyHealthDamage(
                  v16,
                  v25,
                  v6->mHitRecord.mAttacker.m_pPointer,
                  &v6->mHitRecord,
                  v20);
          v6->mHitRecord.mDamageHandled = 1;
          v37 = UFG::GetLocalPlayer();
          v38 = (UFG::SimObjectCharacter *)v2->mSimObject.m_pPointer;
          if ( v37 != v38 )
            goto LABEL_130;
          v39 = 0;
          v40 = v6->mHitRecord.mAttackTypeID;
          v41 = 0;
          if ( v40 == gAttackCollisionExplosion.m_EnumValue )
            v41 = 1;
          if ( v40 == gAttackCollisionHeavy.m_EnumValue )
          {
            v39 = 0;
            if ( !v6->mHitRecord.mMeleeInfo.mAttackLocationHorizontalID )
              v39 = 1;
          }
          if ( !v41 && !v39 || !v36 || v25 <= 0 )
            goto LABEL_130;
          if ( v38 )
          {
            v43 = v38->m_Flags;
            if ( (v43 >> 14) & 1 )
            {
              v42 = v38->m_Components.p[40].m_pComponent;
            }
            else if ( (v43 & 0x8000u) == 0 )
            {
              if ( (v43 >> 13) & 1 )
              {
                v44 = UFG::SimObjectGame::GetComponentOfTypeHK(
                        (UFG::SimObjectGame *)v2->mSimObject.m_pPointer,
                        UFG::HkAudioEntityComponent::_TypeUID);
              }
              else
              {
                v45 = ((v43 >> 12) & 1) == 0;
                v46 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
                if ( v45 )
                  v44 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v46->vfptr,
                          UFG::HkAudioEntityComponent::_TypeUID);
                else
                  v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v46, UFG::HkAudioEntityComponent::_TypeUID);
              }
              v42 = v44;
            }
            else
            {
              v42 = v38->m_Components.p[28].m_pComponent;
            }
          }
          else
          {
            v42 = 0i64;
          }
          v47 = _S14_0;
          if ( !(_S14_0 & 1) )
          {
            _S14_0 |= 1u;
            play_ears_ringing.mUID = UFG::qWiseSymbolUIDFromString("play_ears_ringing", 0x811C9DC5);
            _((AMD_HD3D *)play_ears_ringing.mUID);
            atexit(HandleDamageTask::Begin_::_81_::_dynamic_atexit_destructor_for__play_ears_ringing__);
            v47 = _S14_0;
          }
          if ( !(v47 & 2) )
          {
            _S14_0 = v47 | 2;
            explosion_damage.mUID = UFG::qWiseSymbolUIDFromString("explosion_damage", 0x811C9DC5);
            _((AMD_HD3D *)explosion_damage.mUID);
            atexit(HandleDamageTask::Begin_::_81_::_dynamic_atexit_destructor_for__explosion_damage__);
            v47 = _S14_0;
          }
          if ( !(v47 & 4) )
          {
            _S14_0 = v47 | 4;
            melee_damage.mUID = UFG::qWiseSymbolUIDFromString("melee_damage", 0x811C9DC5);
            _((AMD_HD3D *)melee_damage.mUID);
            atexit(HandleDamageTask::Begin_::_81_::_dynamic_atexit_destructor_for__melee_damage__);
          }
          if ( !v42 )
            goto LABEL_130;
          if ( v39 )
          {
            if ( !v41 )
            {
              UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v42[1], explosion_damage.mUID, 200.0);
              v48 = (float)v25;
LABEL_128:
              UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v42[1], melee_damage.mUID, v48);
              goto LABEL_129;
            }
          }
          else if ( !v41 )
          {
LABEL_129:
            UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v42[1], play_ears_ringing.mUID, 0i64, 0, 0i64);
LABEL_130:
            v49 = UFG::CopSystem::Instance();
            LOBYTE(fOffsetRadians) = v36;
            ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObjectGame *, UFG::SimObject *, bool *, UFG::HealthComponent *, int, bool, bool, UFG::qVector3 *))v49->vfptr[95].__vecDelDtor)(
              v49,
              v8,
              v2->mSimObject.m_pPointer,
              &v60->mHitRecordProcessed,
              v16,
              fOffsetRadians,
              bSteerWithNoTarget,
              bSteerUsingAimPosition,
              pOverrideTargetPosition);
            if ( v36 && v8 )
            {
              v50 = v8->m_Flags;
              if ( (v50 >> 14) & 1 )
              {
                v51 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v8,
                                                   UFG::FaceMeterComponent::_TypeUID);
              }
              else if ( (v50 & 0x8000u) == 0 )
              {
                if ( (v50 >> 13) & 1 )
                  v51 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v8,
                                                     UFG::FaceMeterComponent::_TypeUID);
                else
                  v51 = (UFG::FaceMeterComponent *)((v50 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v8,
                                                                        UFG::FaceMeterComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::FaceMeterComponent::_TypeUID));
              }
              else
              {
                v51 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v8,
                                                   UFG::FaceMeterComponent::_TypeUID);
              }
              if ( v51 )
              {
                parameters.mpPropertySet = 0i64;
                parameters.mIsApply = 1;
                parameters.mpSimObject = v2->mSimObject.m_pPointer;
                v45 = v16->m_bIsKnockedOut == 0;
                parameters.mType = 109;
                if ( v45 )
                  parameters.mType = 108;
                UFG::FaceMeterComponent::ApplyEvent(v51, &parameters);
              }
            }
            return;
          }
          UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v42[1], explosion_damage.mUID, (float)v25);
          v48 = FLOAT_200_0;
          goto LABEL_128;
        }
LABEL_65:
        v25 = 0;
        goto LABEL_66;
      }
    }
  }
}

// File Line: 906
// RVA: 0x2F49F0
void __fastcall StimulusTask::Begin(StimulusTask *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rbx
  ActionContext *v3; // rsi
  __int64 v4; // rbp
  StimulusTask *v5; // rdi
  unsigned __int16 v6; // r8
  UFG::SimComponent *v7; // r8
  UFG::SimComponent *v8; // rax
  ITrack *v9; // rcx
  char v10; // r8
  int v11; // edx
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  __int64 v15; // rbp
  UFG::SimObjectGame *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rdx
  UFG::SimComponent *v19; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h]

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = context;
  v4 = HIDWORD(this->m_Track[1].vfptr);
  v5 = this;
  if ( v2 )
  {
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v7 = v8;
    }
    else
    {
      v7 = v2->m_Components.p[20].m_pComponent;
    }
    if ( v7 )
      v2 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + v4 + 8)
                                  + *(_QWORD *)&v7[1].m_TypeUID
                                  + 40);
  }
  v9 = v5->m_Track;
  v10 = 0;
  v11 = (int)v9[1].vfptr;
  stimulus_parameters.m_StimulusEmissionType = -1;
  stimulus_parameters.m_MaxStimulusDuration = -1.0;
  stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
  stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
  if ( v11 )
  {
    if ( v11 != 1 )
      goto LABEL_19;
    stimulus_parameters.m_StimulusEmissionType = 0;
  }
  else
  {
    stimulus_parameters.m_StimulusEmissionType = 1;
  }
  v10 = 1;
LABEL_19:
  v12 = *(float *)&v9[1].mResourceOwner;
  stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
  stimulus_parameters.m_MaxStimulusDuration = v12;
  v13 = *(float *)&v9[1].mMasterRate.text.mOffset;
  v14 = *(float *)&v9[1].m_TrackClassNameUID;
  stimulus_parameters.m_StimulusProducerOffset.y = *(float *)&v9[1].mBreakPoint;
  stimulus_parameters.m_StimulusProducerOffset.z = v13;
  stimulus_parameters.m_StimulusProducerOffset.x = v14;
  if ( v10 )
  {
    if ( LOBYTE(v9[1].mMasterRate.expression.mOffset)
      && (v15 = HIDWORD(v9[1].mResourceOwner), (v16 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer) != 0i64)
      && ((v17 = v16->m_Flags, !((v17 >> 14) & 1)) ? ((v17 & 0x8000u) == 0 ? (!((v17 >> 13) & 1) ? (!((v17 >> 12) & 1) ? (v19 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v16->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                              v18 = v19) : (v18 = v16->m_Components.p[20].m_pComponent)) : (v18 = v16->m_Components.p[20].m_pComponent),
          v18) )
    {
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        SHIDWORD(v5->m_Track[1].mMasterRate.text.mOffset),
        &stimulus_parameters,
        (UFG::SimObject *)&v2->vfptr,
        *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v18[1].m_Flags + v15 + 8)
                           + *(_QWORD *)&v18[1].m_TypeUID
                           + 40));
    }
    else
    {
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        SHIDWORD(v5->m_Track[1].mMasterRate.text.mOffset),
        &stimulus_parameters,
        (UFG::SimObject *)&v2->vfptr,
        0);
    }
  }
  else
  {
    UFG::StimulusManager::EndStimulus(
      UFG::StimulusManager::s_pInstance,
      SHIDWORD(v9[1].mMasterRate.text.mOffset),
      (UFG::SimObject *)&v2->vfptr);
  }
}

// File Line: 989
// RVA: 0x2F0B20
void __fastcall ObjectCreateTask::Begin(ObjectCreateTask *this, ActionContext *pContext)
{
  ObjectCreateTask *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::SimComponent *v6; // rbx
  unsigned __int16 v7; // dx
  UFG::StreamedResourceComponent *v8; // rax
  UFG::SceneObjectProperties *v9; // rdx
  UFG::qPropertySet *v10; // rcx
  UFG::qPropertySet *v11; // rsi
  UFG::SimObject *v12; // r8
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::SimObjectGame *v15; // rcx
  UFG::SimObjectGame *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rax
  UFG::TargetingSystemBaseComponent *v19; // rax
  UFG::SpawnInfoInterface::SpawnPriority priority; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_pTransformNodeComponent;
    if ( v5 )
    {
      v6 = 0i64;
      priority = 0;
      if ( v3
        && ((v7 = v3->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::StreamedResourceComponent::_TypeUID)) : (v8 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StreamedResourceComponent::_TypeUID))) : (v8 = (UFG::StreamedResourceComponent *)v3->m_Components.p[7].m_pComponent)) : (v8 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent)) : (v8 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent),
            v8) )
      {
        UFG::StreamedResourceComponent::GetSpawnPriority(v8, &priority);
      }
      else
      {
        v9 = v4->mSimObject.m_pPointer->m_pSceneObj;
        v10 = v9->mpWritableProperties;
        if ( !v10 )
          v10 = v9->mpConstProperties;
        UFG::SpawnInfoInterface::GetSpawnPriority(v10, &priority);
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(v5);
      v11 = UFG::CreateObject(v4, (UFG::qSymbol *)&v2->m_Track[1], &v5->mWorldTransform, &priority);
      if ( v11 )
      {
        v12 = v4->mSimObject.m_pPointer;
        if ( v12 )
        {
          v13 = v12->m_Flags;
          if ( (v13 >> 14) & 1 )
          {
            v14 = v12->m_Components.p[20].m_pComponent;
          }
          else if ( (v13 & 0x8000u) == 0 )
          {
            v15 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
            if ( (v13 >> 13) & 1 )
              v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              v14 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v15,
                                        UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v15->vfptr,
                                                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v14 = v12->m_Components.p[20].m_pComponent;
          }
          if ( v14 )
          {
            v16 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
            if ( v16 )
            {
              v17 = v16->m_Flags;
              if ( (v17 >> 14) & 1 )
              {
                v6 = v16->m_Components.p[20].m_pComponent;
              }
              else if ( (v17 & 0x8000u) == 0 )
              {
                if ( (v17 >> 13) & 1 )
                {
                  v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::TargetingSystemBaseComponent::_TypeUID);
                }
                else if ( (v17 >> 12) & 1 )
                {
                  v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::TargetingSystemBaseComponent::_TypeUID);
                }
                else
                {
                  v18 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v16->vfptr,
                          UFG::TargetingSystemBaseComponent::_TypeUID);
                }
                v6 = v18;
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
  UFG::SimObject *v2; // rax
  UFG::SimComponent *v3; // rdi
  ActionContext *v4; // rsi
  ObjectCreateFromPropertiesTask *v5; // r14
  UFG::SceneObjectProperties *v6; // rax
  UFG::qPropertySet *v7; // rcx
  UFG::qSymbol *v8; // rdx
  UFG::qSymbol *v9; // rax
  unsigned int v10; // eax
  UFG::SimObjectCVBase *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::CharacterAnimationComponent *v13; // rax
  Creature *v14; // rbx
  int v15; // eax
  UFG::SimObject *v16; // rbx
  UFG::TransformNodeComponent *v17; // rbx
  UFG::qVector4 v18; // xmm2
  UFG::qVector4 v19; // xmm1
  UFG::qVector4 v20; // xmm0
  UFG::qPropertySet *v21; // r14
  char *v22; // rbx
  char *v23; // rax
  UFG::SimObject *v24; // rbx
  UFG::SimObject *v25; // r8
  unsigned __int16 v26; // dx
  UFG::SimComponent *v27; // rax
  UFG::SimObjectGame *v28; // rcx
  UFG::SimObjectGame *v29; // rcx
  unsigned __int16 v30; // dx
  UFG::SimComponent *v31; // rax
  UFG::TargetingSystemBaseComponent *v32; // rax
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-D0h]
  char dest; // [rsp+70h] [rbp-90h]
  UFG::qSymbol propSetName; // [rsp+1A8h] [rbp+A8h]
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+1B0h] [rbp+B0h]
  UFG::qSymbol result; // [rsp+1B8h] [rbp+B8h]

  v2 = pContext->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = pContext;
  v5 = this;
  if ( !v2 || (v6 = v2->m_pSceneObj) == 0i64 )
  {
    v7 = 0i64;
LABEL_6:
    if ( !v7 )
      return;
    goto LABEL_7;
  }
  v7 = v6->mpWritableProperties;
  if ( !v7 )
  {
    v7 = v6->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v8 = (UFG::qSymbol *)v5->m_Track;
  propSetName.mUID = -1;
  v9 = UFG::qPropertySet::Get<UFG::qSymbol>(v7, v8 + 14, DEPTH_RECURSE);
  if ( v9 )
  {
    v10 = v9->mUID;
    transform = UFG::qMatrix44::msIdentity;
    propSetName.mUID = v10;
    if ( BYTE4(v5->m_Track[1].vfptr) )
    {
      v11 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 >> 14) & 1 )
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v11);
        }
        else if ( (v12 & 0x8000u) == 0 )
        {
          if ( (v12 >> 13) & 1 )
            v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v11);
          else
            v13 = (UFG::CharacterAnimationComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v11->vfptr,
                                                                           UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
        }
        else
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v11);
        }
        if ( v13 )
        {
          v14 = v13->mCreature;
          if ( v14 )
          {
            if ( v14->mPose.mRigHandle.mData )
            {
              v15 = Skeleton::GetBoneID(
                      v14->mPose.mRigHandle.mUFGSkeleton,
                      (const unsigned int)v5->m_Track[1].mResourceOwner);
              Creature::GetTransform(v14, v15, &transform);
            }
            else
            {
              Creature::GetTransform(v14, -1, &transform);
            }
          }
        }
      }
    }
    else
    {
      v16 = v4->mSimObject.m_pPointer;
      if ( v16 )
      {
        v17 = v16->m_pTransformNodeComponent;
        if ( v17 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v17);
          v18 = v17->mWorldTransform.v2;
          v19 = v17->mWorldTransform.v3;
          v20 = v17->mWorldTransform.v0;
          transform.v1 = v17->mWorldTransform.v1;
          transform.v2 = v18;
          transform.v0 = v20;
          transform.v3 = v19;
        }
      }
    }
    v21 = UFG::PropertySetManager::GetPropertySet(&propSetName);
    if ( v21 )
    {
      v22 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->mSimObject.m_pPointer->m_Name);
      v23 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propSetName);
      UFG::qSPrintf(&dest, "%s_CreatedItem_%s", v22, v23);
      UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, &dest);
      UFG::SpawnInfoInterface::GetSpawnPriority(v21, &pPriority);
      v24 = UFG::SpawnInfoInterface::SpawnObject(&result, v21, &transform, pPriority, 0i64, 0i64);
      if ( v24 )
      {
        v25 = v4->mSimObject.m_pPointer;
        if ( v25 )
        {
          v26 = v25->m_Flags;
          if ( (v26 >> 14) & 1 )
          {
            v27 = v25->m_Components.p[20].m_pComponent;
          }
          else if ( (v26 & 0x8000u) == 0 )
          {
            v28 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
            if ( (v26 >> 13) & 1 )
              v27 = UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              v27 = (v26 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v28,
                                        UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v28->vfptr,
                                                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v27 = v25->m_Components.p[20].m_pComponent;
          }
          if ( v27 )
          {
            v29 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
            if ( v29 )
            {
              v30 = v29->m_Flags;
              if ( (v30 >> 14) & 1 )
              {
                v3 = v29->m_Components.p[20].m_pComponent;
              }
              else if ( (v30 & 0x8000u) == 0 )
              {
                if ( (v30 >> 13) & 1 )
                {
                  v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::TargetingSystemBaseComponent::_TypeUID);
                }
                else if ( (v30 >> 12) & 1 )
                {
                  v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::TargetingSystemBaseComponent::_TypeUID);
                }
                else
                {
                  v31 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v29->vfptr,
                          UFG::TargetingSystemBaseComponent::_TypeUID);
                }
                v3 = v31;
              }
              else
              {
                v3 = v29->m_Components.p[20].m_pComponent;
              }
            }
            v32 = (UFG::TargetingSystemBaseComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))v3->vfptr[15].__vecDelDtor)(v3);
            if ( v32 )
              UFG::TargetingSystemBaseComponent::SetTarget(v32, eTARGET_TYPE_LAST_CREATED_OBJECT, v24);
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CompositeDrawableComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CompositeDrawableComponent *)v2->m_Components.p[14].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::CompositeDrawableComponent *)v2->m_Components.p[9].m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v2,
                                                  UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v2->vfptr,
                                                  UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::CompositeDrawableComponent *)v2->m_Components.p[14].m_pComponent;
    }
    if ( v4 )
      UFG::CompositeDrawableComponent::SetIsHidden(v4, 1);
  }
}

// File Line: 1096
// RVA: 0x2FA3C0
void __fastcall UnhideTask::Begin(UnhideTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CompositeDrawableComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CompositeDrawableComponent *)v2->m_Components.p[14].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::CompositeDrawableComponent *)v2->m_Components.p[9].m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v2,
                                                  UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v2->vfptr,
                                                  UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::CompositeDrawableComponent *)v2->m_Components.p[14].m_pComponent;
    }
    if ( v4 )
      UFG::CompositeDrawableComponent::SetIsHidden(v4, 0);
  }
}

// File Line: 1108
// RVA: 0x2EF7D0
void __fastcall InputSignalLerpFilterTask::Begin(InputSignalLerpFilterTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  UFG::SimObject *v3; // rdi
  FloatInputSignal v4; // esi
  InputSignalLerpFilterTask *v5; // rbx
  float v6; // xmm0_4
  float v7; // xmm1_4
  ITrack *v8; // rax

  v2 = this->m_Track;
  this->mContext = context;
  v3 = context->mSimObject.m_pPointer;
  v4 = BYTE1(v2[1].vfptr);
  v5 = this;
  if ( v3 )
    v3 = (UFG::SimObject *)v3->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
  v6 = *((float *)&v3[1].vfptr + 1);
  v7 = *(float *)&v3[1].m_SafePointerList.mNode.mPrev;
  v5->mStartFacingVector.x = *(float *)&v3[1].vfptr;
  v8 = v5->m_Track;
  v5->mStartFacingVector.y = v6;
  v5->mStartFacingVector.z = v7;
  if ( BYTE4(v8[1].mMasterRate.expression.mOffset) )
    setSignalValue(v5->mContext, v4, *(float *)&v8[1].mMasterRate.expression.mOffset);
  ((void (__fastcall *)(InputSignalLerpFilterTask *))v5->vfptr->Update)(v5);
}

// File Line: 1123
// RVA: 0x304670
char __fastcall InputSignalFilterTask::Update(InputSignalFilterTask *this, float timeDelta)
{
  ITrack *v2; // rax
  InputSignalFilterTask *v3; // rbp
  FloatInputSignal v4; // esi
  FloatInputSignal v5; // er14
  float v6; // xmm8_4
  UFG::SimObject *v7; // rbx
  UFG::SimObject *v8; // rax
  int v9; // xmm1_4
  UFG::SimObject *v10; // rdi
  int v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // xmm2_4
  float v14; // xmm7_4
  int v15; // xmm1_4
  float v16; // xmm0_4
  float *v17; // rax
  float v18; // xmm0_4
  float v20; // [rsp+30h] [rbp-38h]
  int v21; // [rsp+34h] [rbp-34h]
  int v22; // [rsp+38h] [rbp-30h]

  v2 = this->m_Track;
  v3 = this;
  v4 = LOBYTE(v2[1].vfptr);
  v5 = BYTE1(v2[1].vfptr);
  v6 = timeDelta;
  v7 = UFG::getTarget(this->mContext->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)HIDWORD(v2[1].vfptr));
  v8 = UFG::getTarget(v3->mContext->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)LODWORD(v3->m_Track[1].mResourceOwner));
  v9 = LODWORD(v3->mStartFacingVector.y);
  v10 = v8;
  v20 = v3->mStartFacingVector.x;
  v11 = LODWORD(v3->mStartFacingVector.z);
  v21 = v9;
  v22 = v11;
  v12 = getSignalValue(v7, v4, v6, 6.2831855, (__int64)v8, (UFG::qVector3 *)&v20);
  v13 = LODWORD(v3->mStartFacingVector.y);
  v14 = v12;
  v20 = v3->mStartFacingVector.x;
  v15 = LODWORD(v3->mStartFacingVector.z);
  v21 = v13;
  v22 = v15;
  v16 = getSignalValue(v10, v5, v6, 6.2831855, (__int64)v10, (UFG::qVector3 *)&v20);
  v17 = (float *)v3->m_Track;
  v18 = v16 + (float)((float)((float)((float)(v14 + v17[17]) * v17[18]) - v16) * v17[19]);
  if ( v18 <= v17[20] )
    v18 = v17[20];
  if ( v18 >= v17[21] )
    v18 = v17[21];
  setSignalValue(v3->mContext, v5, v18);
  return 1;
}

// File Line: 1184
// RVA: 0x3047D0
char __fastcall InputSignalLerpFilterTask::Update(InputSignalLerpFilterTask *this, float timeDelta)
{
  float v2; // xmm7_4
  InputSignalLerpFilterTask *v3; // rbp
  ITrack *v4; // rdx
  __int64 v5; // r14
  __int64 v6; // rsi
  UFG::SimObject *v7; // rbx
  UFG::SimObject *v8; // rdi
  int v9; // xmm1_4
  int v10; // xmm0_4
  float v11; // xmm8_4
  int v12; // xmm2_4
  int v13; // xmm4_4
  float v14; // xmm6_4
  float *v15; // rax
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm6_4
  float v21; // [rsp+38h] [rbp-70h]
  int v22; // [rsp+3Ch] [rbp-6Ch]
  int v23; // [rsp+40h] [rbp-68h]
  UFG::qString result; // [rsp+48h] [rbp-60h]

  v2 = timeDelta;
  v3 = this;
  v4 = this->m_Track;
  v5 = LOBYTE(v4[1].vfptr);
  v6 = BYTE1(v4[1].vfptr);
  v7 = UFG::getTarget(this->mContext->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)HIDWORD(v4[1].vfptr));
  v8 = UFG::getTarget(v3->mContext->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)LODWORD(v3->m_Track[1].mResourceOwner));
  v9 = LODWORD(v3->mStartFacingVector.y);
  v10 = LODWORD(v3->mStartFacingVector.z);
  v21 = v3->mStartFacingVector.x;
  v22 = v9;
  v23 = v10;
  v11 = getSignalValue(v7, (FloatInputSignal)v5, v2, 6.2831855, (__int64)v8, (UFG::qVector3 *)&v21);
  v12 = LODWORD(v3->mStartFacingVector.y);
  v13 = LODWORD(v3->mStartFacingVector.z);
  v21 = v3->mStartFacingVector.x;
  v22 = v12;
  v23 = v13;
  v14 = getSignalValue(v8, (FloatInputSignal)v6, v2, 6.2831855, (__int64)v8, (UFG::qVector3 *)&v21);
  v15 = (float *)v3->m_Track;
  v16 = v15[18];
  v17 = v15[20];
  if ( v11 <= v16 )
    v18 = v15[18];
  else
    v18 = v11;
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
  setSignalValue(v3->mContext, (FloatInputSignal)v6, v19);
  UFG::qString::FormatEx(
    &result,
    "InputSignalLerpFilterTask::%s:%.3f -> %s:%.3f",
    gFloatInputSignalStringList[v5],
    v11,
    gFloatInputSignalStringList[v6],
    v19,
    -2i64);
  UFG::qString::~qString(&result);
  return 1;
}

// File Line: 1236
// RVA: 0x30EC40
char __fastcall InputEnableMappingTask::updateMapping(InputEnableMappingTask *this)
{
  InputEnableMappingTask *v1; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerComponent *v5; // rax
  ITrack *v6; // rcx

  v1 = this;
  if ( UFG::UI::gUIInputLocked )
    return 0;
  v3 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
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
        v5 = (UFG::AICharacterControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v3->vfptr,
                                                      UFG::AICharacterControllerComponent::_TypeUID);
      else
        v5 = (UFG::AICharacterControllerComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        (UFG::SimObjectGame *)&v3->vfptr,
                                                                        UFG::AICharacterControllerComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerComponent::_TypeUID));
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(v3);
    }
    if ( v5 )
    {
      v6 = v1->m_Track;
      if ( LOBYTE(v6[1].vfptr) )
      {
        UFG::SetInputMode(IM_ON_FOOT, v5->m_ControllerID);
        return 1;
      }
      if ( BYTE1(v6[1].vfptr) )
        UFG::SetInputMode(IM_DRIVING, v5->m_ControllerID);
    }
  }
  return 1;
}

// File Line: 1266
// RVA: 0x304650
bool __fastcall InputEnableMappingTask::Update(InputEnableMappingTask *this, float timeDelta)
{
  return InputEnableMappingTask::updateMapping(this) == 0;
}

// File Line: 1276
// RVA: 0x2F3730
void __fastcall SetOpeningBranchTask::Begin(SetOpeningBranchTask *this, ActionContext *pContext)
{
  ITrack *v2; // r9
  Expression::IMemberMapVtbl *v3; // rax
  Expression::IMemberMap *(__fastcall *v4)(Expression::IMemberMap *); // rcx
  ActionNode *v5; // r8
  ActionContext *i; // rax

  v2 = this->m_Track;
  v3 = v2[1].vfptr;
  if ( v3 )
    v3 = (Expression::IMemberMapVtbl *)((char *)v3 + (_QWORD)v2 + 56);
  v4 = v3->GetResourceOwner;
  if ( v4 )
  {
    v5 = (ActionNode *)((char *)&v3->GetResourceOwner + (_QWORD)v4);
    if ( v5 )
    {
      if ( LOBYTE(v2[1].mResourceOwner) )
      {
        for ( i = pContext->mParentContext; i; i = i->mParentContext )
          pContext = i;
      }
      if ( pContext )
        pContext->m_OpeningBranch = v5;
    }
  }
}

