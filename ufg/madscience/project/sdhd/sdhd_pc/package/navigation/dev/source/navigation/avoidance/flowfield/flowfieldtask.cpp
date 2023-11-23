// File Line: 54
// RVA: 0x1461400
__int64 UFG::_dynamic_initializer_for__gTaskFunctionDecl_FlowfieldTask_FloatTheBoat__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &UFG::gTaskFunctionDecl_FlowfieldTask_FloatTheBoat,
    &UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gTaskFunctionDecl_FlowfieldTask_FloatTheBoat__);
}

// File Line: 104
// RVA: 0xFE580
float __fastcall UFG::FlowfieldTask::GetFlow(
        UFG::FlowfieldComponent *pField,
        UFG::qVector3 *outFlow,
        UFG::qVector3 *vPosition)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v5; // r13
  int m_iPriority; // r12d
  float v10; // xmm8_4
  UFG::FFieldAvoidablePrint *p_mNext; // rbx
  char m_Enabled; // al
  UFG::SimComponent *m_pPointer; // rcx
  __int64 mTypeID; // rcx
  float mTimeOffset; // xmm2_4
  int v16; // ecx
  bool IsFlowDefinedAt; // al
  unsigned int v18; // ecx
  float v19; // xmm6_4
  unsigned int v20; // ecx
  float Flow; // xmm0_4
  int v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  UFG::qVector3 *optEyePosition; // [rsp+20h] [rbp-78h]
  UFG::qVector3 *optEyeVelocity; // [rsp+28h] [rbp-70h]
  UFG::qVector3 outFlowa; // [rsp+30h] [rbp-68h] BYREF

  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v5 = &pField->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  m_iPriority = 999999;
  v10 = 0.0;
  outFlow->x = UFG::qVector3::msZero.x;
  outFlow->y = y;
  outFlow->z = z;
  p_mNext = (UFG::FFieldAvoidablePrint *)&pField->m_Prints.mNode.mNext[-3].mNext;
  if ( p_mNext == (UFG::FFieldAvoidablePrint *)&pField->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> )
    return 0.0;
  do
  {
    m_Enabled = p_mNext->m_Enabled;
    if ( !m_Enabled )
      goto LABEL_29;
    m_pPointer = p_mNext->mpPrintComponent.m_pPointer;
    if ( m_pPointer )
      m_Enabled = m_pPointer[1].m_Flags;
    if ( !m_Enabled )
      goto LABEL_29;
    mTypeID = (int)p_mNext->mTypeID;
    if ( !pField->mTypeEnabled[mTypeID] || m_iPriority < p_mNext->m_iPriority )
      goto LABEL_29;
    mTimeOffset = pField->mTimeOffset;
    if ( !(_DWORD)mTypeID )
    {
      IsFlowDefinedAt = UFG::FFieldAvoidablePrint::IsFlowDefinedAt(p_mNext, vPosition, mTimeOffset);
      goto LABEL_13;
    }
    v16 = mTypeID - 1;
    if ( v16 )
    {
      if ( v16 != 1 )
        goto LABEL_29;
      IsFlowDefinedAt = UFG::FFieldAttractor::IsFlowDefinedAt((UFG::FFieldAttractor *)p_mNext, vPosition, mTimeOffset);
LABEL_13:
      if ( !IsFlowDefinedAt )
        goto LABEL_29;
    }
    v18 = p_mNext->mTypeID;
    v19 = pField->mTimeOffset;
    if ( v18 )
    {
      v20 = v18 - 1;
      if ( v20 )
      {
        if ( v20 != 1 )
          goto LABEL_29;
        Flow = UFG::FFieldAttractor::GetFlow(
                 (UFG::FFieldAttractor *)p_mNext,
                 &outFlowa,
                 vPosition,
                 pField->mTimeOffset,
                 &pField->mEyePosition,
                 &pField->mEyeVelocity);
      }
      else
      {
        Flow = UFG::FFieldPathPrint::GetFlow(
                 (UFG::FFieldPathPrint *)p_mNext,
                 &outFlowa,
                 vPosition,
                 pField->mTimeOffset,
                 &pField->mEyePosition,
                 &pField->mEyeVelocity);
      }
    }
    else
    {
      if ( !p_mNext->mpInterest.m_pPointer )
        goto LABEL_29;
      optEyeVelocity = &pField->mEyeVelocity;
      optEyePosition = &pField->mEyePosition;
      v22 = UFG::FFieldAvoidablePrint::GetAvoidMethod(p_mNext) - 2;
      if ( v22 )
      {
        if ( v22 == 1 )
          Flow = UFG::FFieldAvoidablePrint::GetFlowFlashlight(
                   p_mNext,
                   &outFlowa,
                   vPosition,
                   v19,
                   optEyePosition,
                   optEyeVelocity);
        else
          Flow = UFG::FFieldAvoidablePrint::GetFlowRegular(
                   p_mNext,
                   &outFlowa,
                   vPosition,
                   v19,
                   optEyePosition,
                   optEyeVelocity);
      }
      else
      {
        Flow = UFG::FFieldAvoidablePrint::GetFlowSweep(
                 p_mNext,
                 &outFlowa,
                 vPosition,
                 v19,
                 optEyePosition,
                 optEyeVelocity);
      }
    }
    if ( Flow > 0.0 )
    {
      if ( m_iPriority > p_mNext->m_iPriority )
      {
        v23 = UFG::qVector3::msZero.y;
        v24 = UFG::qVector3::msZero.z;
        m_iPriority = p_mNext->m_iPriority;
        v10 = 0.0;
        outFlow->x = UFG::qVector3::msZero.x;
        outFlow->y = v23;
        outFlow->z = v24;
      }
      v10 = v10 + Flow;
      v25 = (float)(Flow * outFlowa.y) + outFlow->y;
      v26 = (float)(Flow * outFlowa.z) + outFlow->z;
      v27 = (float)(outFlowa.x * Flow) + outFlow->x;
      outFlow->y = v25;
      outFlow->z = v26;
      outFlow->x = v27;
    }
LABEL_29:
    p_mNext = (UFG::FFieldAvoidablePrint *)&p_mNext->UFG::FlowfieldPrint::UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mNext[-3].mNext;
  }
  while ( p_mNext != (UFG::FFieldAvoidablePrint *)v5 );
  if ( v10 > 0.0 )
  {
    v28 = (float)(1.0 / v10) * outFlow->x;
    v29 = (float)(1.0 / v10) * outFlow->y;
    outFlow->z = (float)(1.0 / v10) * outFlow->z;
    outFlow->x = v28;
    outFlow->y = v29;
    return v10;
  }
  return 0.0;
}

// File Line: 149
// RVA: 0x1028F0
void __fastcall UFG::FlowfieldTask::SimulateFlowfieldMass(UFG::FlowfieldMass *pMass, UFG::FlowfieldTaskParam *params)
{
  UFG::FlowfieldComponent *mpFlow; // rbp
  float x; // xmm10_4
  int v4; // esi
  __m128 y_low; // xmm11
  float z; // xmm12_4
  __m128 v9; // xmm4
  float v10; // xmm5_4
  float i; // xmm6_4
  __m128 v12; // xmm2
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm4_4
  __m128 x_low; // xmm2

  mpFlow = pMass->mpFlow;
  x = pMass->mPosition.x;
  v4 = 0;
  y_low = (__m128)LODWORD(pMass->mPosition.y);
  v9 = y_low;
  z = pMass->mPosition.z;
  v9.m128_f32[0] = y_low.m128_f32[0] - y_low.m128_f32[0];
  v10 = x - x;
  for ( i = z - z;
        (float)((float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10)) + (float)(i * i)) < (float)(params->FlowMassDistOffset * params->FlowMassDistOffset);
        i = pMass->mPosition.z - z )
  {
    v12 = v9;
    v13 = 0.0;
    v12.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10)) + (float)(i * i);
    v14 = _mm_sqrt_ps(v12).m128_f32[0];
    if ( v14 > 0.0099999998 )
    {
      v15 = (float)((float)((float)(v9.m128_f32[0] * (float)(1.0 / v14)) * params->mAgentVelocity.y)
                  + (float)((float)(v10 * (float)(1.0 / v14)) * params->mAgentVelocity.x))
          + (float)((float)(i * (float)(1.0 / v14)) * params->mAgentVelocity.z);
      if ( v15 > 0.1 )
        v13 = v14 / v15;
    }
    mpFlow->mTimeOffset = v13;
    UFG::FlowfieldMass::OnUpdate(pMass, params->FlowMassUpdateDeltaT);
    x_low = (__m128)LODWORD(pMass->mVelocity.x);
    ++v4;
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                              + (float)(pMass->mVelocity.y * pMass->mVelocity.y))
                      + (float)(pMass->mVelocity.z * pMass->mVelocity.z);
    if ( _mm_sqrt_ps(x_low).m128_f32[0] < params->FlowMassOutMinVelocity )
      break;
    if ( (float)((float)v4 * params->FlowMassUpdateDeltaT) > params->FlowMassUpdateMaxT )
      break;
    v9 = (__m128)LODWORD(pMass->mPosition.y);
    v10 = pMass->mPosition.x - x;
    v9.m128_f32[0] = v9.m128_f32[0] - y_low.m128_f32[0];
  }
}

// File Line: 211
// RVA: 0xFA010
void __fastcall UFG::FlowfieldTask_FloatTheBoat(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        UFG::FlowfieldTaskParam *_params)
{
  __int64 i; // rax
  UFG::HermiteCurve *v5; // rsi
  int mNumFlowfieldPrints; // eax
  char v7; // r10
  UFG::FlowfieldComponent *v8; // rax
  __int64 p_mNext; // rcx
  int v10; // ebp
  __int64 v11; // rbx
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rdx
  float v17; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  _QWORD *v20; // rax
  UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *p_m_Prints; // rax
  int v22; // r9d
  __int64 *v23; // r8
  UFG::HermiteCurve *v24; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v25; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *mPrev; // rax
  UFG::FlowfieldMass *mpResults; // rcx
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  UFG::FlowfieldComponent *mpFlowfield; // [rsp+38h] [rbp-9D0h]
  __int64 ptr; // [rsp+50h] [rbp-9B8h] BYREF
  __int64 v40[101]; // [rsp+58h] [rbp-9B0h] BYREF
  __int64 v41[102]; // [rsp+380h] [rbp-688h] BYREF
  __int64 v42[104]; // [rsp+6B0h] [rbp-358h] BYREF

  gpFlowTask_memstream = memory_streamer;
  mpFlowfield = (UFG::FlowfieldComponent *)_params->mpFlowfield;
  _params->FlowMass.mpFlow = mpFlowfield;
  `eh vector constructor iterator(
    &ptr,
    0x18ui64,
    34,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  `eh vector constructor iterator(
    v42,
    0x18ui64,
    34,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  `eh vector constructor iterator(
    v41,
    0x18ui64,
    34,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  for ( i = 0i64; i < 102; i += 3i64 )
  {
    v40[i - 1] = (__int64)"FlowfieldPrintArray";
    v42[i] = (__int64)"AvoidableArray";
    v41[i] = (__int64)"FFieldPrintArray";
  }
  v5 = 0i64;
  mNumFlowfieldPrints = _params->mNumFlowfieldPrints;
  if ( mNumFlowfieldPrints )
  {
    if ( mNumFlowfieldPrints > 34 )
      _params->mNumFlowfieldPrints = 34;
    v7 = 0;
    v8 = mpFlowfield;
    p_mNext = (__int64)&mpFlowfield->m_Prints.mNode.mNext[-3].mNext;
    v10 = 0;
    if ( _params->mNumFlowfieldPrints > 0 )
    {
      v11 = 0i64;
      do
      {
        v40[v11] = p_mNext;
        *(_QWORD *)(p_mNext + 104) = v8;
        v12 = v40[v11];
        if ( *(_QWORD *)(v12 + 128) )
        {
          v13 = *(_QWORD *)(v12 + 128);
          v41[v11 + 1] = v13;
          *(_QWORD *)(v12 + 128) = v13;
        }
        v14 = v40[v11];
        if ( *(_QWORD *)(v14 + 152) )
        {
          v15 = *(_QWORD *)(v14 + 152);
          v42[v11 + 1] = v15;
          *(_QWORD *)(v14 + 152) = v15;
        }
        v16 = v40[v11];
        if ( *(_DWORD *)(v16 + 28) == 1 )
        {
          v5 = *(UFG::HermiteCurve **)(v16 + 208);
          v17 = *(float *)(v16 + 232);
          *(_QWORD *)(v16 + 216) = v5;
          *(_DWORD *)(v16 + 232) = -1082130432;
          *(_DWORD *)(v16 + 228) = -1082130432;
          y = UFG::qVector3::msZero.y;
          z = UFG::qVector3::msZero.z;
          *(float *)(v16 + 236) = UFG::qVector3::msZero.x;
          *(float *)(v16 + 240) = y;
          *(float *)(v16 + 244) = z;
          if ( v17 >= 0.0 )
          {
            *(float *)(v16 + 232) = v17;
            UFG::HermiteCurve::GetPosition(v5, v17, (UFG::qVector3 *)(v16 + 236));
          }
          v7 = 1;
        }
        v20 = (_QWORD *)v40[v11];
        p_mNext = v20[6] - 40i64;
        v20 += 5;
        *v20 = v20;
        v20[1] = v20;
        ++v10;
        v11 += 3i64;
        v8 = mpFlowfield;
      }
      while ( v10 < _params->mNumFlowfieldPrints );
    }
    p_m_Prints = &v8->m_Prints;
    p_m_Prints->mNode.mPrev = &p_m_Prints->mNode;
    p_m_Prints->mNode.mNext = &p_m_Prints->mNode;
    v22 = 0;
    if ( _params->mNumFlowfieldPrints > 0 )
    {
      v23 = v40;
      do
      {
        if ( !*(_DWORD *)(*v23 + 28) )
        {
          v24 = 0i64;
          if ( v7 )
            v24 = v5;
          *(_QWORD *)(*v23 + 160) = v24;
        }
        v25 = (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *)(*v23 + 40);
        mPrev = mpFlowfield->m_Prints.mNode.mPrev;
        mPrev->mNext = v25;
        v25->mPrev = mPrev;
        v25->mNext = &mpFlowfield->m_Prints.mNode;
        mpFlowfield->m_Prints.mNode.mPrev = v25;
        ++v22;
        v23 += 3;
      }
      while ( v22 < _params->mNumFlowfieldPrints );
    }
    mpResults = (UFG::FlowfieldMass *)_params->mpResults;
    mpResults->mParams = _params->FlowMass.mParams;
    mpResults->mpFlow = _params->FlowMass.mpFlow;
    v28 = _params->FlowMass.mStartPosition.y;
    v29 = _params->FlowMass.mStartPosition.z;
    mpResults->mStartPosition.x = _params->FlowMass.mStartPosition.x;
    mpResults->mStartPosition.y = v28;
    mpResults->mStartPosition.z = v29;
    v30 = _params->FlowMass.mStartVelocity.y;
    v31 = _params->FlowMass.mStartVelocity.z;
    mpResults->mStartVelocity.x = _params->FlowMass.mStartVelocity.x;
    mpResults->mStartVelocity.y = v30;
    mpResults->mStartVelocity.z = v31;
    v32 = _params->FlowMass.mNegVelDir.y;
    v33 = _params->FlowMass.mNegVelDir.z;
    mpResults->mNegVelDir.x = _params->FlowMass.mNegVelDir.x;
    mpResults->mNegVelDir.y = v32;
    mpResults->mNegVelDir.z = v33;
    mpResults->mFlowStrength = _params->FlowMass.mFlowStrength;
    mpResults->mDistanceTravelled = _params->FlowMass.mDistanceTravelled;
    v34 = _params->FlowMass.mPosition.y;
    v35 = _params->FlowMass.mPosition.z;
    mpResults->mPosition.x = _params->FlowMass.mPosition.x;
    mpResults->mPosition.y = v34;
    mpResults->mPosition.z = v35;
    v36 = _params->FlowMass.mVelocity.y;
    v37 = _params->FlowMass.mVelocity.z;
    mpResults->mVelocity.x = _params->FlowMass.mVelocity.x;
    mpResults->mVelocity.y = v36;
    mpResults->mVelocity.z = v37;
    mpResults->mActive = _params->FlowMass.mActive;
    mpResults->mAge = _params->FlowMass.mAge;
    UFG::FlowfieldTask::SimulateFlowfieldMass(mpResults, _params);
    gpFlowTask_memstream = 0i64;
  }
  `eh vector destructor iterator(v41, 0x18ui64, 34, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(v42, 0x18ui64, 34, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(&ptr, 0x18ui64, 34, (void (__fastcall *)(void *))_);
}

