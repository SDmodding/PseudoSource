// File Line: 54
// RVA: 0x1461400
__int64 UFG::_dynamic_initializer_for__gTaskFunctionDecl_FlowfieldTask_FloatTheBoat__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &UFG::gTaskFunctionDecl_FlowfieldTask_FloatTheBoat,
    &UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat);
  return atexit(UFG::_dynamic_atexit_destructor_for__gTaskFunctionDecl_FlowfieldTask_FloatTheBoat__);
}

// File Line: 104
// RVA: 0xFE580
float __fastcall UFG::FlowfieldTask::GetFlow(UFG::FlowfieldComponent *pField, UFG::qVector3 *outFlow, UFG::qVector3 *vPosition)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v5; // r13
  UFG::qVector3 *v6; // r15
  UFG::qVector3 *v7; // rdi
  UFG::FlowfieldComponent *v8; // r14
  signed int v9; // er12
  float v10; // xmm8_4
  UFG::FFieldAvoidablePrint *v11; // rbx
  char v12; // al
  UFG::SimComponent *v13; // rcx
  __int64 v14; // rcx
  float v15; // xmm2_4
  int v16; // ecx
  bool v17; // al
  unsigned int v18; // ecx
  float v19; // xmm6_4
  int v20; // ecx
  float v21; // xmm0_4
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
  UFG::qVector3 outFlowa; // [rsp+30h] [rbp-68h]

  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  v5 = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&pField->mPrev;
  v6 = vPosition;
  v7 = outFlow;
  v8 = pField;
  v9 = 999999;
  v10 = 0.0;
  outFlow->x = UFG::qVector3::msZero.x;
  outFlow->y = v3;
  outFlow->z = v4;
  v11 = (UFG::FFieldAvoidablePrint *)&pField->m_Prints.mNode.mNext[-3].mNext;
  if ( v11 == (UFG::FFieldAvoidablePrint *)&pField->mPrev )
    return 0.0;
  do
  {
    v12 = v11->m_Enabled;
    if ( !v12 )
      goto LABEL_29;
    v13 = v11->mpPrintComponent.m_pPointer;
    if ( v13 )
      v12 = v13[1].m_Flags;
    if ( !v12 )
      goto LABEL_29;
    v14 = (signed int)v11->mTypeID;
    if ( !v8->mTypeEnabled[v14] || v9 < v11->m_iPriority )
      goto LABEL_29;
    v15 = v8->mTimeOffset;
    if ( !(_DWORD)v14 )
    {
      v17 = UFG::FFieldAvoidablePrint::IsFlowDefinedAt(v11, v6, v15);
      goto LABEL_13;
    }
    v16 = v14 - 1;
    if ( v16 )
    {
      if ( v16 != 1 )
        goto LABEL_29;
      v17 = UFG::FFieldAttractor::IsFlowDefinedAt((UFG::FFieldAttractor *)v11, v6, v15);
LABEL_13:
      if ( !v17 )
        goto LABEL_29;
    }
    v18 = v11->mTypeID;
    v19 = v8->mTimeOffset;
    if ( v18 )
    {
      v20 = v18 - 1;
      if ( v20 )
      {
        if ( v20 != 1 )
          goto LABEL_29;
        v21 = UFG::FFieldAttractor::GetFlow(
                (UFG::FFieldAttractor *)v11,
                &outFlowa,
                v6,
                v8->mTimeOffset,
                &v8->mEyePosition,
                &v8->mEyeVelocity);
      }
      else
      {
        v21 = UFG::FFieldPathPrint::GetFlow(
                (UFG::FFieldPathPrint *)v11,
                &outFlowa,
                v6,
                v8->mTimeOffset,
                &v8->mEyePosition,
                &v8->mEyeVelocity);
      }
    }
    else
    {
      if ( !v11->mpInterest.m_pPointer )
        goto LABEL_29;
      optEyeVelocity = &v8->mEyeVelocity;
      optEyePosition = &v8->mEyePosition;
      v22 = (unsigned __int64)UFG::FFieldAvoidablePrint::GetAvoidMethod(v11) - 2;
      if ( v22 )
      {
        if ( v22 == 1 )
          v21 = UFG::FFieldAvoidablePrint::GetFlowFlashlight(v11, &outFlowa, v6, v19, optEyePosition, optEyeVelocity);
        else
          v21 = UFG::FFieldAvoidablePrint::GetFlowRegular(v11, &outFlowa, v6, v19, optEyePosition, optEyeVelocity);
      }
      else
      {
        v21 = UFG::FFieldAvoidablePrint::GetFlowSweep(v11, &outFlowa, v6, v19, optEyePosition, optEyeVelocity);
      }
    }
    if ( v21 > 0.0 )
    {
      if ( v9 > v11->m_iPriority )
      {
        v23 = UFG::qVector3::msZero.y;
        v24 = UFG::qVector3::msZero.z;
        v9 = v11->m_iPriority;
        v10 = 0.0;
        v7->x = UFG::qVector3::msZero.x;
        v7->y = v23;
        v7->z = v24;
      }
      v10 = v10 + v21;
      v25 = (float)(v21 * outFlowa.y) + v7->y;
      v26 = (float)(v21 * outFlowa.z) + v7->z;
      v27 = (float)(outFlowa.x * v21) + v7->x;
      v7->y = v25;
      v7->z = v26;
      v7->x = v27;
    }
LABEL_29:
    v11 = (UFG::FFieldAvoidablePrint *)&v11->mNext[-3].mNext;
  }
  while ( v11 != (UFG::FFieldAvoidablePrint *)v5 );
  if ( v10 > 0.0 )
  {
    v28 = (float)(1.0 / v10) * v7->x;
    v29 = (float)(1.0 / v10) * v7->y;
    v7->z = (float)(1.0 / v10) * v7->z;
    v7->x = v28;
    v7->y = v29;
    return v10;
  }
  return 0.0;
}

// File Line: 149
// RVA: 0x1028F0
void __fastcall UFG::FlowfieldTask::SimulateFlowfieldMass(UFG::FlowfieldMass *pMass, UFG::FlowfieldTaskParam *params)
{
  UFG::FlowfieldComponent *v2; // rbp
  float v3; // xmm10_4
  signed int v4; // esi
  UFG::FlowfieldTaskParam *v5; // rbx
  UFG::FlowfieldMass *v6; // rdi
  __m128 v7; // xmm11
  float v8; // xmm12_4
  __m128 v9; // xmm4
  float v10; // xmm5_4
  float v11; // xmm6_4
  __m128 v12; // xmm2
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm4_4
  __m128 v16; // xmm2

  v2 = pMass->mpFlow;
  v3 = pMass->mPosition.x;
  v4 = 0;
  v5 = params;
  v6 = pMass;
  v7 = (__m128)LODWORD(pMass->mPosition.y);
  v9 = v7;
  v8 = pMass->mPosition.z;
  v9.m128_f32[0] = v7.m128_f32[0] - v7.m128_f32[0];
  v10 = v3 - v3;
  v11 = v8 - v8;
  if ( (float)((float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10)) + (float)(v11 * v11)) < (float)(params->FlowMassDistOffset * params->FlowMassDistOffset) )
  {
    do
    {
      v12 = v9;
      v13 = 0.0;
      v12.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10)) + (float)(v11 * v11);
      LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v12);
      if ( v14 > 0.0099999998 )
      {
        v15 = (float)((float)((float)(v9.m128_f32[0] * (float)(1.0 / v14)) * v5->mAgentVelocity.y)
                    + (float)((float)(v10 * (float)(1.0 / v14)) * v5->mAgentVelocity.x))
            + (float)((float)(v11 * (float)(1.0 / v14)) * v5->mAgentVelocity.z);
        if ( v15 > 0.1 )
          v13 = v14 / v15;
      }
      v2->mTimeOffset = v13;
      UFG::FlowfieldMass::OnUpdate(v6, v5->FlowMassUpdateDeltaT);
      v16 = (__m128)LODWORD(v6->mVelocity.x);
      ++v4;
      v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v6->mVelocity.y * v6->mVelocity.y))
                      + (float)(v6->mVelocity.z * v6->mVelocity.z);
      if ( COERCE_FLOAT(_mm_sqrt_ps(v16)) < v5->FlowMassOutMinVelocity )
        break;
      if ( (float)((float)v4 * v5->FlowMassUpdateDeltaT) > v5->FlowMassUpdateMaxT )
        break;
      v9 = (__m128)LODWORD(v6->mPosition.y);
      v10 = v6->mPosition.x - v3;
      v9.m128_f32[0] = v9.m128_f32[0] - v7.m128_f32[0];
      v11 = v6->mPosition.z - v8;
    }
    while ( (float)((float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10)) + (float)(v11 * v11)) < (float)(v5->FlowMassDistOffset * v5->FlowMassDistOffset) );
  }
}

// File Line: 211
// RVA: 0xFA010
void __fastcall UFG::FlowfieldTask_FloatTheBoat(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *_params)
{
  UFG::FlowfieldTaskParam *v3; // rdi
  signed __int64 v4; // rax
  UFG::HermiteCurve *v5; // rsi
  signed int v6; // eax
  char v7; // r10
  __int64 v8; // rax
  signed __int64 v9; // rcx
  int v10; // ebp
  __int64 v11; // rbx
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rdx
  float v17; // xmm1_4
  signed __int64 v18; // r8
  float v19; // xmm2_4
  float v20; // xmm3_4
  _QWORD *v21; // rax
  _QWORD *v22; // rax
  int v23; // er9
  __int64 *v24; // r8
  UFG::HermiteCurve *v25; // rax
  _QWORD *v26; // rcx
  __int64 v27; // rax
  UFG::FlowfieldMass *v28; // rcx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  __int64 v39; // [rsp+38h] [rbp-9D0h]
  __int64 ptr; // [rsp+50h] [rbp-9B8h]
  __int64 v41[101]; // [rsp+58h] [rbp-9B0h]
  __int64 v42; // [rsp+380h] [rbp-688h]
  __int64 v43[101]; // [rsp+388h] [rbp-680h]
  __int64 v44; // [rsp+6B0h] [rbp-358h]
  __int64 v45[103]; // [rsp+6B8h] [rbp-350h]

  v3 = (UFG::FlowfieldTaskParam *)_params;
  gpFlowTask_memstream = memory_streamer;
  v39 = *((_QWORD *)_params + 20);
  *((_QWORD *)_params + 4) = v39;
  `eh vector constructor iterator(
    &ptr,
    0x18ui64,
    34,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  `eh vector constructor iterator(
    &v44,
    0x18ui64,
    34,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  `eh vector constructor iterator(
    &v42,
    0x18ui64,
    34,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  v4 = 0i64;
  do
  {
    *(__int64 *)((char *)&ptr + v4) = (__int64)"FlowfieldPrintArray";
    *(__int64 *)((char *)&v44 + v4) = (__int64)"AvoidableArray";
    *(__int64 *)((char *)&v42 + v4) = (__int64)"FFieldPrintArray";
    v4 += 24i64;
  }
  while ( v4 < 816 );
  v5 = 0i64;
  v6 = v3->mNumFlowfieldPrints;
  if ( v6 )
  {
    if ( v6 > 34 )
      v3->mNumFlowfieldPrints = 34;
    v7 = 0;
    v8 = v39;
    v9 = *(_QWORD *)(v39 + 128) - 40i64;
    v10 = 0;
    if ( v3->mNumFlowfieldPrints > 0 )
    {
      v11 = 0i64;
      do
      {
        v41[v11] = v9;
        *(_QWORD *)(v9 + 104) = v8;
        v12 = v41[v11];
        if ( *(_QWORD *)(v12 + 128) )
        {
          v13 = *(_QWORD *)(v12 + 128);
          v43[v11] = v13;
          *(_QWORD *)(v12 + 128) = v13;
        }
        v14 = v41[v11];
        if ( *(_QWORD *)(v14 + 152) )
        {
          v15 = *(_QWORD *)(v14 + 152);
          v45[v11] = v15;
          *(_QWORD *)(v14 + 152) = v15;
        }
        v16 = v41[v11];
        if ( *(_DWORD *)(v16 + 28) == 1 )
        {
          v5 = *(UFG::HermiteCurve **)(v16 + 208);
          v17 = *(float *)(v16 + 232);
          *(_QWORD *)(v16 + 216) = v5;
          *(_DWORD *)(v16 + 232) = -1082130432;
          *(_DWORD *)(v16 + 228) = -1082130432;
          v18 = v16 + 236;
          v19 = UFG::qVector3::msZero.y;
          v20 = UFG::qVector3::msZero.z;
          *(float *)v18 = UFG::qVector3::msZero.x;
          *(float *)(v18 + 4) = v19;
          *(float *)(v18 + 8) = v20;
          if ( v17 >= 0.0 )
          {
            *(float *)(v16 + 232) = v17;
            UFG::HermiteCurve::GetPosition(v5, v17, (UFG::qVector3 *)v18);
          }
          v7 = 1;
        }
        v21 = (_QWORD *)v41[v11];
        v9 = v21[6] - 40i64;
        v21 += 5;
        *v21 = v21;
        v21[1] = v21;
        ++v10;
        v11 += 3i64;
        v8 = v39;
      }
      while ( v10 < v3->mNumFlowfieldPrints );
    }
    v22 = (_QWORD *)(v8 + 120);
    *v22 = v22;
    v22[1] = v22;
    v23 = 0;
    if ( v3->mNumFlowfieldPrints > 0 )
    {
      v24 = v41;
      do
      {
        if ( !*(_DWORD *)(*v24 + 28) )
        {
          v25 = 0i64;
          if ( v7 )
            v25 = v5;
          *(_QWORD *)(*v24 + 160) = v25;
        }
        v26 = (_QWORD *)(*v24 + 40);
        v27 = *(_QWORD *)(v39 + 120);
        *(_QWORD *)(v27 + 8) = v26;
        *v26 = v27;
        v26[1] = v39 + 120;
        *(_QWORD *)(v39 + 120) = v26;
        ++v23;
        v24 += 3;
      }
      while ( v23 < v3->mNumFlowfieldPrints );
    }
    v28 = (UFG::FlowfieldMass *)v3->mpResults;
    v28->mParams = v3->FlowMass.mParams;
    v28->mpFlow = v3->FlowMass.mpFlow;
    v29 = v3->FlowMass.mStartPosition.y;
    v30 = v3->FlowMass.mStartPosition.z;
    v28->mStartPosition.x = v3->FlowMass.mStartPosition.x;
    v28->mStartPosition.y = v29;
    v28->mStartPosition.z = v30;
    v31 = v3->FlowMass.mStartVelocity.y;
    v32 = v3->FlowMass.mStartVelocity.z;
    v28->mStartVelocity.x = v3->FlowMass.mStartVelocity.x;
    v28->mStartVelocity.y = v31;
    v28->mStartVelocity.z = v32;
    v33 = v3->FlowMass.mNegVelDir.y;
    v34 = v3->FlowMass.mNegVelDir.z;
    v28->mNegVelDir.x = v3->FlowMass.mNegVelDir.x;
    v28->mNegVelDir.y = v33;
    v28->mNegVelDir.z = v34;
    v28->mFlowStrength = v3->FlowMass.mFlowStrength;
    v28->mDistanceTravelled = v3->FlowMass.mDistanceTravelled;
    v35 = v3->FlowMass.mPosition.y;
    v36 = v3->FlowMass.mPosition.z;
    v28->mPosition.x = v3->FlowMass.mPosition.x;
    v28->mPosition.y = v35;
    v28->mPosition.z = v36;
    v37 = v3->FlowMass.mVelocity.y;
    v38 = v3->FlowMass.mVelocity.z;
    v28->mVelocity.x = v3->FlowMass.mVelocity.x;
    v28->mVelocity.y = v37;
    v28->mVelocity.z = v38;
    v28->mActive = v3->FlowMass.mActive;
    v28->mAge = v3->FlowMass.mAge;
    UFG::FlowfieldTask::SimulateFlowfieldMass(v28, v3);
    gpFlowTask_memstream = 0i64;
  }
  `eh vector destructor iterator(&v42, 0x18ui64, 34, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(&v44, 0x18ui64, 34, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(&ptr, 0x18ui64, 34, (void (__fastcall *)(void *))_);
}

