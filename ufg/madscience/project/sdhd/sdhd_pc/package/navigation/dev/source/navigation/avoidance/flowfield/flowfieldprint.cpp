// File Line: 63
// RVA: 0xFBE60
void __fastcall UFG::FlowfieldPrint::~FlowfieldPrint(UFG::FlowfieldPrint *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v16; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v25; // [rsp+40h] [rbp+8h]

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::FlowfieldPrint::`vftable;
  v2 = &this->mpInterest;
  if ( this->mpInterest.m_pPointer )
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
  v7 = &v1[4].m_SafePointerList.mNode.mNext;
  if ( v1[5].m_SafePointerList.mNode.mPrev )
  {
    v8 = *v7;
    v9 = v1[5].vfptr;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v9;
    v9->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v8;
    *v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v7;
    v1[5].vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&v1[4].m_SafePointerList.mNode.mNext;
  }
  v1[5].m_SafePointerList.mNode.mPrev = 0i64;
  v10 = *v7;
  v11 = v1[5].vfptr;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v11;
  v11->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v10;
  *v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v7;
  v1[5].vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&v1[4].m_SafePointerList.mNode.mNext;
  v12 = &v1[3].m_SafePointerList.mNode.mNext;
  if ( v1[4].m_SafePointerList.mNode.mPrev )
  {
    v13 = *v12;
    v14 = v1[4].vfptr;
    v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v14;
    v14->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v13;
    *v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v12;
    v1[4].vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&v1[3].m_SafePointerList.mNode.mNext;
  }
  v1[4].m_SafePointerList.mNode.mPrev = 0i64;
  v15 = *v12;
  v16 = v1[4].vfptr;
  v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v16;
  v16->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v15;
  *v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v12;
  v1[4].vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&v1[3].m_SafePointerList.mNode.mNext;
  v17 = &v1[2].m_SafePointerList;
  v18 = v1[2].m_SafePointerList.mNode.mPrev;
  v19 = v1[2].m_SafePointerList.mNode.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mNode.mPrev = &v17->mNode;
  v17->mNode.mNext = &v17->mNode;
  v20 = &v1[1].m_SafePointerList.mNode.mNext;
  v21 = v1[1].m_SafePointerList.mNode.mNext;
  v22 = v1[2].vfptr;
  v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v22;
  v22->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v21;
  *v20 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v20;
  v20[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v20;
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::FlowfieldPrint>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  v25 = &v1->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v23 = v1->m_SafePointerList.mNode.mPrev;
  v24 = v1->m_SafePointerList.mNode.mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v25->mNode.mPrev = &v25->mNode;
  v25->mNode.mNext = &v25->mNode;
}

// File Line: 118
// RVA: 0xFD530
__int64 __fastcall UFG::FFieldAvoidablePrint::GetAvoidMethod(UFG::FFieldAvoidablePrint *this)
{
  UFG::FFieldAvoidablePrint *rbx1; // rbx
  unsigned int v2; // edi
  UFG::SimComponent *v3; // rcx
  UFG::qVector3 *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  UFG::qVector3 *v7; // rax
  UFG::qVector3 v1; // [rsp+30h] [rbp-28h]
  UFG::qVector3 result; // [rsp+3Ch] [rbp-1Ch]
  float closing_speed; // [rsp+60h] [rbp+8h]

  rbx1 = this;
  v2 = (signed int)this->mParams.Method;
  if ( v2 == 2 )
  {
    v3 = this->mpInterest.m_pPointer;
    v4 = (UFG::qVector3 *)rbx1->mpParentField.m_pPointer;
    v5 = *(float *)&v3[3].m_TypeUID;
    v6 = *((float *)&v3[3].m_SafePointerList.mNode.mNext + 1);
    LODWORD(v1.z) = v3[3].m_NameUID;
    v1.x = v6;
    v1.y = v5;
    v7 = UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)v3, &result, 0.0);
    UFG::ClosingTime(v4 + 12, v4 + 13, v7, &v1, &closing_speed);
    if ( closing_speed >= 1.0 )
      v2 = 3;
  }
  return v2;
}

// File Line: 150
// RVA: 0xFDE60
float __fastcall UFG::FFieldAvoidablePrint::GetFlow(UFG::FFieldAvoidablePrint *this, UFG::qVector3 *outFlow, UFG::qVector3 *vPosition, float fTimeOffset, UFG::qVector3 *optEyePosition, UFG::qVector3 *optEyeVelocity)
{
  UFG::qVector3 *v6; // rdi
  UFG::qVector3 *v7; // rsi
  UFG::FFieldAvoidablePrint *v8; // rbx
  int v10; // eax

  v6 = vPosition;
  v7 = outFlow;
  v8 = this;
  if ( !this->mpInterest.m_pPointer )
    return 0.0;
  v10 = (unsigned __int64)UFG::FFieldAvoidablePrint::GetAvoidMethod(this) - 2;
  if ( !v10 )
    return UFG::FFieldAvoidablePrint::GetFlowSweep(v8, v7, v6, fTimeOffset, optEyePosition, optEyeVelocity);
  if ( v10 == 1 )
    return UFG::FFieldAvoidablePrint::GetFlowFlashlight(v8, v7, v6, fTimeOffset, optEyePosition, optEyeVelocity);
  return UFG::FFieldAvoidablePrint::GetFlowRegular(v8, v7, v6, fTimeOffset, optEyePosition, optEyeVelocity);
}

// File Line: 186
// RVA: 0x100660
bool __fastcall UFG::FFieldAvoidablePrint::IsFlowDefinedAt(UFG::FFieldAvoidablePrint *this, UFG::qVector3 *vPosition, float fTimeOffset)
{
  UFG::qVector3 *v3; // rsi
  UFG::FFieldAvoidablePrint *v4; // rbx
  float v5; // xmm8_4
  float v6; // xmm7_4
  float v7; // xmm9_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  UFG::SimComponent *v11; // rax
  __m128 v12; // xmm0
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::qVector3 result; // [rsp+20h] [rbp-68h]

  v3 = vPosition;
  v4 = this;
  if ( !this->mpInterest.m_pPointer )
    return 0;
  UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)this->mpInterest.m_pPointer, &result, fTimeOffset);
  v5 = v3->x;
  v6 = v3->y;
  v7 = v3->z;
  v8 = (float)((float)((float)(v3->y - result.y) * (float)(v3->y - result.y))
             + (float)((float)(v3->x - result.x) * (float)(v3->x - result.x)))
     + (float)((float)(v3->z - result.z) * (float)(v3->z - result.z));
  if ( fTimeOffset != 0.0 )
  {
    UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)v4->mpInterest.m_pPointer, &result, 0.0);
    v9 = (float)((float)((float)(v6 - result.y) * (float)(v6 - result.y))
               + (float)((float)(v5 - result.x) * (float)(v5 - result.x)))
       + (float)((float)(v7 - result.z) * (float)(v7 - result.z));
    if ( v8 >= v9 )
      v8 = v9;
  }
  if ( (unsigned int)UFG::FFieldAvoidablePrint::GetAvoidMethod(v4) == 3 )
    return v8 <= (float)(v4->mParams.FLMaxDist * v4->mParams.FLMaxDist);
  v11 = v4->mpInterest.m_pPointer;
  v12 = (__m128)LODWORD(v11[3].vfptr);
  v13 = *((float *)&v11[2].m_BoundComponentHandles.mNode.mNext + 1)
      - *(float *)&v11[2].m_BoundComponentHandles.mNode.mPrev;
  v12.m128_f32[0] = (float)((float)(v12.m128_f32[0] - *((float *)&v11[2].m_BoundComponentHandles.mNode.mPrev + 1))
                          * (float)(v12.m128_f32[0] - *((float *)&v11[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                  + (float)(v13 * v13);
  v14 = (float)((float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v12)) * 0.5) + v4->mParams.RadiusAdditive)
              * *(float *)&v4->mpParentField.m_pPointer[2].m_pSimObject)
      * 5.0;
  return (float)(v14 * v14) > v8;
}

// File Line: 262
// RVA: 0xFFEE0
UFG::qMatrix44 *__fastcall UFG::FFieldAvoidablePrint::GetWorldTransform(UFG::FFieldAvoidablePrint *this)
{
  UFG::SimComponent *v1; // rax
  UFG::qMatrix44 *result; // rax
  UFG::SimComponent *v3; // rax

  v1 = this->mpInterest.m_pPointer;
  if ( v1 )
    return (UFG::qMatrix44 *)&v1[3].m_Flags;
  v3 = this->mpPrintComponent.m_pPointer;
  if ( v3 )
    result = (UFG::qMatrix44 *)(&v3[1].m_SimObjIndex + 1);
  else
    result = &UFG::qMatrix44::msIdentity;
  return result;
}

// File Line: 279
// RVA: 0xFF570
float __fastcall UFG::FFieldAvoidablePrint::GetFlowSweep(UFG::FFieldAvoidablePrint *this, UFG::qVector3 *outFlow, UFG::qVector3 *vPosition, float fTimeOffset)
{
  UFG::AIInterestComponent *v4; // rdi
  UFG::qVector3 *v5; // r14
  UFG::qVector3 *v6; // rbx
  UFG::FFieldAvoidablePrint *v7; // rsi
  float v8; // xmm10_4
  __int128 v9; // xmm9
  float v10; // xmm8_4
  float v11; // xmm0_4
  float v12; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  __m128 v17; // xmm2
  float v18; // xmm10_4
  float v19; // xmm4_4
  float v20; // xmm8_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  float v23; // xmm3_4
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm13_4
  __int128 v28; // xmm14
  float v29; // xmm15_4
  __m128 v30; // xmm2
  UFG::SimComponent *v31; // rax
  __m128 v32; // xmm0
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm13_4
  float v38; // xmm14_4
  float v39; // xmm15_4
  UFG::AIInterestComponent *v40; // rcx
  float v41; // xmm11_4
  __m128 v42; // xmm10
  float v43; // xmm9_4
  float v44; // xmm9_4
  float v45; // xmm11_4
  __m128 v46; // xmm2
  float v47; // xmm1_4
  float v48; // xmm9_4
  float v49; // xmm10_4
  float v50; // xmm11_4
  float v51; // xmm8_4
  UFG::qMatrix44 *v52; // rax
  float v53; // xmm0_4
  float v54; // xmm5_4
  float v55; // xmm4_4
  __m128 v56; // xmm3
  float v57; // xmm5_4
  float v58; // xmm8_4
  float v59; // xmm2_4
  float v60; // xmm0_4
  float v61; // xmm5_4
  float v62; // xmm4_4
  __m128 v63; // xmm2
  float v64; // xmm1_4
  UFG::HermiteCurve *v65; // rcx
  float v66; // xmm0_4
  __m128 v67; // xmm9
  __m128 v68; // xmm2
  float v69; // xmm1_4
  float v70; // xmm8_4
  float v71; // xmm5_4
  float v72; // xmm4_4
  __m128 v73; // xmm10
  float v74; // xmm11_4
  __m128 v75; // xmm2
  float v76; // xmm1_4
  float v77; // xmm4_4
  float v78; // xmm10_4
  float v79; // xmm11_4
  float v80; // xmm13_4
  __m128 v81; // xmm2
  float v82; // xmm14_4
  __m128 v83; // xmm3
  float v84; // xmm1_4
  float v85; // xmm3_4
  float v86; // xmm2_4
  float v87; // xmm13_4
  float v88; // xmm2_4
  float v89; // xmm4_4
  float v90; // xmm0_4
  float v91; // xmm4_4
  float v92; // xmm7_4
  float v93; // xmm2_4
  UFG::qVector3 target_point; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 result; // [rsp+50h] [rbp-98h]
  UFG::qVector3 closest_point; // [rsp+60h] [rbp-88h]
  float v98; // [rsp+118h] [rbp+30h]
  float t; // [rsp+130h] [rbp+48h]
  float *v100; // [rsp+138h] [rbp+50h]

  v4 = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
  v5 = vPosition;
  v6 = outFlow;
  v7 = this;
  v8 = UFG::qVector3::msZero.z;
  v9 = LODWORD(UFG::qVector3::msZero.y);
  v10 = UFG::qVector3::msZero.x;
  v11 = fTimeOffset;
  if ( v4 )
  {
    UFG::AIInterestComponent::GetCenter(v4, &result, 0.0);
    v12 = result.z;
    v13 = result.y;
    v14 = result.x;
    v11 = t;
  }
  else
  {
    v14 = UFG::qVector3::msZero.x;
    v13 = UFG::qVector3::msZero.y;
    v12 = UFG::qVector3::msZero.z;
  }
  if ( v4 )
  {
    UFG::AIInterestComponent::GetCenter(v4, &target_point, v11);
    v8 = target_point.z;
    v9 = LODWORD(target_point.y);
    v10 = target_point.x;
  }
  else
  {
    target_point.x = v10;
    LODWORD(target_point.y) = v9;
    target_point.z = v8;
  }
  v15 = *(float *)&FLOAT_1_0;
  v16 = v10 - v14;
  *(float *)&v9 = *(float *)&v9 - v13;
  v17 = (__m128)v9;
  v18 = v8 - v12;
  v17.m128_f32[0] = (float)((float)(*(float *)&v9 * *(float *)&v9) + (float)(v16 * v16)) + (float)(v18 * v18);
  LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v17);
  if ( v19 <= 0.001 )
  {
    v24 = v14;
    v25 = v13;
    v26 = v12;
  }
  else
  {
    v20 = v16 * (float)(1.0 / v19);
    v21 = *(float *)&v9 * (float)(1.0 / v19);
    v22 = v18 * (float)(1.0 / v19);
    v23 = (float)((float)((float)(v5->y - v13) * v21) + (float)((float)(v5->x - v14) * v20))
        + (float)((float)(v5->z - v12) * v22);
    v24 = (float)(v20 * v23) + v14;
    v25 = (float)(v21 * v23) + v13;
    v26 = (float)(v22 * v23) + v12;
  }
  v28 = LODWORD(v5->y);
  v27 = v5->x - v24;
  *(float *)&v28 = *(float *)&v28 - v25;
  v29 = v5->z - v26;
  v30 = (__m128)v28;
  v6->x = v27;
  LODWORD(v6->y) = v28;
  v6->z = v29;
  v30.m128_f32[0] = (float)((float)(*(float *)&v28 * *(float *)&v28) + (float)(v27 * v27)) + (float)(v29 * v29);
  v31 = v7->mpInterest.m_pPointer;
  v32 = (__m128)LODWORD(v31[3].vfptr);
  LODWORD(v33) = (unsigned __int128)_mm_sqrt_ps(v30);
  v34 = *((float *)&v31[2].m_BoundComponentHandles.mNode.mNext + 1)
      - *(float *)&v31[2].m_BoundComponentHandles.mNode.mPrev;
  v32.m128_f32[0] = (float)((float)(v32.m128_f32[0] - *((float *)&v31[2].m_BoundComponentHandles.mNode.mPrev + 1))
                          * (float)(v32.m128_f32[0] - *((float *)&v31[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                  + (float)(v34 * v34);
  v35 = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v32)) * 0.5) + v7->mParams.RadiusAdditive)
      * *(float *)&v7->mpParentField.m_pPointer[2].m_pSimObject;
  v36 = v33 / v35;
  if ( (float)(v33 / v35) <= 0.0 )
  {
    v36 = 0.0;
  }
  else if ( v36 >= 1.0 )
  {
    v36 = *(float *)&FLOAT_1_0;
  }
  v98 = 1.0 - (float)(v36 * 0.69999999);
  if ( v33 <= 0.0 || v33 > v35 )
    return 0.0;
  v37 = v27 * (float)(1.0 / v33);
  v38 = *(float *)&v28 * (float)(1.0 / v33);
  v39 = v29 * (float)(1.0 / v33);
  v6->x = v37;
  v6->y = v38;
  v6->z = v39;
  if ( v100 )
  {
    v40 = (UFG::AIInterestComponent *)v7->mpInterest.m_pPointer;
    if ( v40 )
    {
      UFG::AIInterestComponent::GetCenter(v40, &result, t);
      v41 = result.z;
      v42 = (__m128)LODWORD(result.y);
      v43 = result.x;
    }
    else
    {
      v43 = UFG::qVector3::msZero.x;
      v42 = (__m128)LODWORD(UFG::qVector3::msZero.y);
      v41 = UFG::qVector3::msZero.z;
    }
    v44 = v43 - *v100;
    v42.m128_f32[0] = v42.m128_f32[0] - v100[1];
    v45 = v41 - v100[2];
    v46 = v42;
    v46.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v44 * v44)) + (float)(v45 * v45);
    v47 = v46.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v46));
    v48 = v44 * v47;
    v49 = v42.m128_f32[0] * v47;
    v50 = v45 * v47;
    v51 = (float)((float)(v38 * v49) + (float)(v37 * v48)) + (float)(v39 * v50);
    if ( v51 < v7->mParams.SidestepMinDP )
    {
      v52 = UFG::FFieldAvoidablePrint::GetWorldTransform(v7);
      v53 = v52->v2.y;
      v54 = v52->v2.x;
      v56 = (__m128)LODWORD(v52->v2.z);
      v55 = (float)(v53 * v48) - (float)(v54 * v49);
      v56.m128_f32[0] = (float)(v56.m128_f32[0] * v49) - (float)(v53 * v50);
      v57 = (float)(v54 * v50) - (float)(v52->v2.z * v48);
      v58 = (float)(v51 - v7->mParams.SidestepMinDP) / (float)(v7->mParams.SidestepMaxDP - v7->mParams.SidestepMinDP);
      if ( v58 <= 0.0 )
      {
        v58 = 0.0;
      }
      else if ( v58 >= 1.0 )
      {
        v58 = *(float *)&FLOAT_1_0;
      }
      v59 = (float)((float)(v38 * v57) + (float)(v37 * v56.m128_f32[0])) + (float)(v39 * v55);
      if ( v59 <= 0.0 )
      {
        if ( v59 >= 0.0 )
          v60 = 0.0;
        else
          v60 = FLOAT_N1_0;
      }
      else
      {
        v60 = *(float *)&FLOAT_1_0;
      }
      v56.m128_f32[0] = (float)((float)((float)(v56.m128_f32[0] * v60) - v37) * v58) + v37;
      v61 = (float)((float)((float)(v57 * v60) - v38) * v58) + v38;
      v62 = (float)((float)((float)(v55 * v60) - v39) * v58) + v39;
      v63 = v56;
      v63.m128_f32[0] = (float)((float)(v56.m128_f32[0] * v56.m128_f32[0]) + (float)(v61 * v61)) + (float)(v62 * v62);
      if ( v63.m128_f32[0] == 0.0 )
        v64 = 0.0;
      else
        v64 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v63));
      v6->x = v56.m128_f32[0] * v64;
      v6->z = v64 * v62;
      v6->y = v64 * v61;
    }
  }
  v65 = v7->mpPathCurve;
  if ( v65 && v65->mNumControlPoints )
  {
    v66 = UFG::HermiteCurve::ClosestPointEx(v65, &target_point, &closest_point, -1.234, -1.234, -1.0, -1.234, -1.234);
    UFG::HermiteCurve::GetTangent(v7->mpPathCurve, v66, &result);
    v67 = (__m128)LODWORD(result.z);
    v68 = (__m128)LODWORD(result.x);
    v68.m128_f32[0] = (float)((float)(v68.m128_f32[0] * v68.m128_f32[0]) + (float)(result.y * result.y))
                    + (float)(v67.m128_f32[0] * v67.m128_f32[0]);
    if ( v68.m128_f32[0] == 0.0 )
      v69 = 0.0;
    else
      v69 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v68));
    v70 = result.y * v69;
    v67.m128_f32[0] = result.z * v69;
    v71 = result.x * v69;
    v73 = v67;
    v72 = (float)((float)(result.y * v69) * UFG::qVector3::msDirUp.z)
        - (float)((float)(result.z * v69) * UFG::qVector3::msDirUp.y);
    v73.m128_f32[0] = (float)((float)(result.z * v69) * UFG::qVector3::msDirUp.x)
                    - (float)((float)(result.x * v69) * UFG::qVector3::msDirUp.z);
    v75 = v73;
    v74 = (float)((float)(result.x * v69) * UFG::qVector3::msDirUp.y)
        - (float)((float)(result.y * v69) * UFG::qVector3::msDirUp.x);
    v75.m128_f32[0] = (float)((float)(v73.m128_f32[0] * v73.m128_f32[0]) + (float)(v72 * v72)) + (float)(v74 * v74);
    if ( v75.m128_f32[0] == 0.0 )
      v76 = 0.0;
    else
      v76 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v75));
    v81 = (__m128)LODWORD(closest_point.y);
    v77 = v72 * v76;
    v78 = v73.m128_f32[0] * v76;
    v79 = v74 * v76;
    v80 = closest_point.x - target_point.x;
    v81.m128_f32[0] = closest_point.y - target_point.y;
    v82 = closest_point.z - target_point.z;
    v83 = v81;
    v83.m128_f32[0] = (float)((float)(v81.m128_f32[0] * v81.m128_f32[0]) + (float)(v80 * v80)) + (float)(v82 * v82);
    if ( v83.m128_f32[0] == 0.0 )
      v84 = 0.0;
    else
      v84 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v83));
    v85 = v6->y;
    v86 = (float)((float)(v81.m128_f32[0] * v84) * v78) + (float)((float)(v80 * v84) * v77);
    v87 = v6->z;
    v88 = v86 + (float)((float)(v82 * v84) * v79);
    v89 = (float)((float)(v77 * v6->x) + (float)(v78 * v85)) + (float)(v79 * v87);
    if ( v89 <= 0.0 )
    {
      if ( v89 >= 0.0 )
        v90 = 0.0;
      else
        v90 = FLOAT_N1_0;
    }
    else
    {
      v90 = *(float *)&FLOAT_1_0;
    }
    if ( v88 <= 0.0 )
    {
      if ( v88 >= 0.0 )
        v15 = 0.0;
      else
        v15 = FLOAT_N1_0;
    }
    if ( v90 != v15 )
    {
      v6->x = v6->x * -1.0;
      v6->y = v85 * -1.0;
      v6->z = v87 * -1.0;
    }
    v91 = v6->y;
    v92 = v6->z;
    v93 = (float)((float)(v71 * v6->x) + (float)(v70 * v91)) + (float)(v67.m128_f32[0] * v92);
    if ( v93 < 0.0 )
    {
      v6->x = v6->x - (float)((float)(v71 * v93) * 1.5);
      v6->y = v91 - (float)((float)(v70 * v93) * 1.5);
      v6->z = v92 - (float)((float)(v67.m128_f32[0] * v93) * 1.5);
    }
  }
  return v98 * v7->m_fStrength;
}

// File Line: 377
// RVA: 0xFE830
float __fastcall UFG::FFieldAvoidablePrint::GetFlowFlashlight(UFG::FFieldAvoidablePrint *this, UFG::qVector3 *outFlow, UFG::qVector3 *vPosition, float fTimeOffset, UFG::qVector3 *optEyePosition, UFG::qVector3 *optEyeVelocity)
{
  UFG::FFieldAvoidablePrint *v6; // rdi
  UFG::AIInterestComponent *v7; // rcx
  UFG::qVector3 *v8; // rsi
  UFG::qVector3 *v9; // rbx
  float v10; // xmm9_4
  __int128 v11; // xmm5
  float v12; // xmm8_4
  float v13; // xmm7_4
  float v14; // xmm13_4
  float v15; // xmm12_4
  float v16; // xmm8_4
  __m128 v17; // xmm2
  float v18; // xmm14_4
  float v19; // xmm9_4
  float v20; // xmm11_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm10_4
  float v25; // xmm3_4
  float v26; // xmm12_4
  float v27; // xmm13_4
  float v28; // xmm14_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  __m128 v31; // xmm3
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm15_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm15_4
  float v39; // xmm4_4
  float v40; // xmm10_4
  float v41; // xmm3_4
  int v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm5_4
  float v45; // xmm4_4
  float v46; // xmm9_4
  float v47; // xmm2_4
  float v48; // xmm8_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  UFG::SimComponent *v51; // rax
  __m128 v52; // xmm0
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm3_4
  float v56; // xmm0_4
  float v57; // xmm9_4
  float v58; // xmm8_4
  float v59; // xmm0_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  float v62; // xmm8_4
  UFG::HermiteCurve *v63; // rcx
  float v64; // xmm8_4
  float v65; // xmm0_4
  __m128 v66; // xmm10
  __m128 v67; // xmm2
  float v68; // xmm1_4
  float v69; // xmm9_4
  float v70; // xmm5_4
  float v71; // xmm4_4
  __m128 v72; // xmm11
  float v73; // xmm12_4
  __m128 v74; // xmm2
  float v75; // xmm1_4
  float v76; // xmm4_4
  float v77; // xmm11_4
  float v78; // xmm12_4
  float v79; // xmm14_4
  __m128 v80; // xmm2
  float v81; // xmm15_4
  __m128 v82; // xmm3
  float v83; // xmm1_4
  float v84; // xmm3_4
  float v85; // xmm2_4
  float v86; // xmm14_4
  float v87; // xmm2_4
  float v88; // xmm4_4
  float v89; // xmm0_4
  float v90; // xmm4_4
  float v91; // xmm7_4
  float v92; // xmm2_4
  UFG::qVector3 result; // [rsp+40h] [rbp-B8h]
  UFG::qVector3 vDirection; // [rsp+50h] [rbp-A8h]
  UFG::qVector3 vPositiona; // [rsp+60h] [rbp-98h]
  UFG::FlashlightParams params; // [rsp+70h] [rbp-88h]
  float *v98; // [rsp+158h] [rbp+60h]

  v6 = this;
  v7 = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
  v8 = vPosition;
  v9 = outFlow;
  if ( v7 )
  {
    UFG::AIInterestComponent::GetCenter(v7, &result, fTimeOffset);
    v10 = result.z;
    v11 = LODWORD(result.y);
    v12 = result.x;
  }
  else
  {
    v12 = UFG::qVector3::msZero.x;
    v11 = LODWORD(UFG::qVector3::msZero.y);
    v10 = UFG::qVector3::msZero.z;
    result = UFG::qVector3::msZero;
  }
  if ( !v98 )
    return 0.0;
  v13 = *(float *)&FLOAT_1_0;
  v14 = v98[1];
  v15 = *v98;
  *(float *)&v11 = *(float *)&v11 - v14;
  v16 = v12 - *v98;
  vPositiona.x = *v98;
  v17 = (__m128)v11;
  v18 = v98[2];
  vPositiona.y = v14;
  vDirection.x = v16;
  v19 = v10 - v18;
  vPositiona.z = v18;
  v17.m128_f32[0] = (float)((float)(*(float *)&v11 * *(float *)&v11) + (float)(v16 * v16)) + (float)(v19 * v19);
  LODWORD(vDirection.y) = v11;
  vDirection.z = v19;
  LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v17);
  v21 = FLOAT_0_001;
  if ( v20 <= 0.001 )
  {
    v23 = v8->x;
    v31 = (__m128)LODWORD(v8->y);
    v24 = v8->z;
    v36 = v8->x;
    v37 = v8->y;
    v38 = v8->z;
  }
  else
  {
    v22 = FLOAT_10_0;
    v16 = v16 * (float)(1.0 / v20);
    *(float *)&v11 = *(float *)&v11 * (float)(1.0 / v20);
    v19 = v19 * (float)(1.0 / v20);
    vDirection.x = v16;
    LODWORD(vDirection.y) = v11;
    vDirection.z = v19;
    if ( v20 >= 10.0 )
      v22 = v20;
    v23 = v8->x;
    v24 = v8->z;
    v25 = v22 - v20;
    v26 = v15 - (float)(v16 * v25);
    v27 = v14 - (float)(*(float *)&v11 * v25);
    v28 = v18 - (float)(v19 * v25);
    v20 = v20 + v25;
    v29 = (float)(v8->x - v26) * v16;
    v30 = (float)(v8->z - v28) * v19;
    v31 = (__m128)LODWORD(v8->y);
    vPositiona.x = v26;
    vPositiona.y = v27;
    vPositiona.z = v28;
    v32 = (float)((float)((float)(v31.m128_f32[0] - v27) * *(float *)&v11) + v29) + v30;
    v33 = v16 * v32;
    v34 = *(float *)&v11 * v32;
    v35 = v19 * v32;
    v21 = FLOAT_0_001;
    v36 = v33 + v26;
    v37 = v34 + v27;
    v38 = v35 + v28;
  }
  v31.m128_f32[0] = v31.m128_f32[0] - v37;
  v39 = v23 - v36;
  v40 = v24 - v38;
  LODWORD(v9->y) = v31.m128_i32[0];
  v9->x = v39;
  v9->z = v40;
  v31.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v39 * v39)) + (float)(v40 * v40);
  LODWORD(v41) = (unsigned __int128)_mm_sqrt_ps(v31);
  *(float *)&v42 = v41;
  if ( v41 < 0.0 )
    v42 = LODWORD(v41) ^ _xmm[0];
  if ( *(float *)&v42 < v21 )
  {
    v43 = *(float *)&v11;
    v44 = *(float *)&v11 * UFG::qVector3::msDirUp.x;
    v41 = *(float *)&FLOAT_1_0;
    v45 = v19 * UFG::qVector3::msDirUp.y;
    v46 = v19 * UFG::qVector3::msDirUp.x;
    v47 = v16 * UFG::qVector3::msDirUp.z;
    v48 = v16 * UFG::qVector3::msDirUp.y;
    v9->x = v45 - (float)(v43 * UFG::qVector3::msDirUp.z);
    v9->y = v47 - v46;
    v9->z = v44 - v48;
  }
  v49 = (float)(1.0 / v41) * v9->x;
  v50 = (float)(1.0 / v41) * v9->y;
  v9->z = (float)(1.0 / v41) * v9->z;
  v9->x = v49;
  v9->y = v50;
  v51 = v6->mpInterest.m_pPointer;
  v52 = (__m128)LODWORD(v51[3].vfptr);
  v53 = *((float *)&v51[2].m_BoundComponentHandles.mNode.mNext + 1)
      - *(float *)&v51[2].m_BoundComponentHandles.mNode.mPrev;
  v52.m128_f32[0] = (float)((float)(v52.m128_f32[0] - *((float *)&v51[2].m_BoundComponentHandles.mNode.mPrev + 1))
                          * (float)(v52.m128_f32[0] - *((float *)&v51[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                  + (float)(v53 * v53);
  v54 = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v52)) * 0.5) + v6->mParams.RadiusAdditive)
      * *(float *)&v6->mpParentField.m_pPointer[2].m_pSimObject;
  v55 = v41 / v54;
  if ( v55 <= 0.0 )
  {
    v55 = 0.0;
  }
  else if ( v55 >= 1.0 )
  {
    v55 = *(float *)&FLOAT_1_0;
  }
  params.fMinDistance = v6->mParams.FLMinDist;
  v56 = v6->mParams.FLMinAngle;
  params.fAngleWeight = 1.0;
  params.fDeadDistance = 0.0;
  params.fMaxDistance = v20;
  v57 = 1.0 - (float)(v55 * 0.5);
  params.fDeadDistance = atan2f(v54, v20);
  v58 = UFG::FlashlightScore(&vPositiona, &vDirection, &params, v8);
  if ( v58 <= 0.0 )
    return 0.0;
  v59 = FLOAT_0_25;
  v60 = v9->y;
  v61 = v9->z;
  if ( v6->mParams.FlashlightScoreMax >= 0.25 )
    v59 = v6->mParams.FlashlightScoreMax;
  v62 = v58 / v59;
  if ( v62 <= 0.0 )
  {
    v62 = 0.0;
  }
  else if ( v62 >= 1.0 )
  {
    v62 = *(float *)&FLOAT_1_0;
  }
  v9->x = v9->x * v57;
  v9->y = v60 * v57;
  v9->z = v61 * v57;
  v63 = v6->mpPathCurve;
  v64 = v62 * v6->m_fStrength;
  if ( v63 && v63->mNumControlPoints )
  {
    v65 = UFG::HermiteCurve::ClosestPointEx(
            v63,
            &result,
            (UFG::qVector3 *)&params,
            -1.234,
            -1.234,
            -1.0,
            -1.234,
            -1.234);
    UFG::HermiteCurve::GetTangent(v6->mpPathCurve, v65, &vPositiona);
    v66 = (__m128)LODWORD(vPositiona.z);
    v67 = (__m128)LODWORD(vPositiona.x);
    v67.m128_f32[0] = (float)((float)(v67.m128_f32[0] * v67.m128_f32[0]) + (float)(vPositiona.y * vPositiona.y))
                    + (float)(v66.m128_f32[0] * v66.m128_f32[0]);
    if ( v67.m128_f32[0] == 0.0 )
      v68 = 0.0;
    else
      v68 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v67));
    v69 = vPositiona.y * v68;
    v66.m128_f32[0] = vPositiona.z * v68;
    v70 = vPositiona.x * v68;
    v72 = v66;
    v71 = (float)((float)(vPositiona.y * v68) * UFG::qVector3::msDirUp.z)
        - (float)((float)(vPositiona.z * v68) * UFG::qVector3::msDirUp.y);
    v72.m128_f32[0] = (float)((float)(vPositiona.z * v68) * UFG::qVector3::msDirUp.x)
                    - (float)((float)(vPositiona.x * v68) * UFG::qVector3::msDirUp.z);
    v74 = v72;
    v73 = (float)((float)(vPositiona.x * v68) * UFG::qVector3::msDirUp.y)
        - (float)((float)(vPositiona.y * v68) * UFG::qVector3::msDirUp.x);
    v74.m128_f32[0] = (float)((float)(v72.m128_f32[0] * v72.m128_f32[0]) + (float)(v71 * v71)) + (float)(v73 * v73);
    if ( v74.m128_f32[0] == 0.0 )
      v75 = 0.0;
    else
      v75 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v74));
    v80 = (__m128)LODWORD(params.fMinDistance);
    v76 = v71 * v75;
    v77 = v72.m128_f32[0] * v75;
    v78 = v73 * v75;
    v79 = params.fAngleWeight - result.x;
    v80.m128_f32[0] = params.fMinDistance - result.y;
    v81 = params.fMaxDistance - result.z;
    v82 = v80;
    v82.m128_f32[0] = (float)((float)(v80.m128_f32[0] * v80.m128_f32[0]) + (float)(v79 * v79)) + (float)(v81 * v81);
    if ( v82.m128_f32[0] == 0.0 )
      v83 = 0.0;
    else
      v83 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v82));
    v84 = v9->y;
    v85 = (float)((float)(v80.m128_f32[0] * v83) * v77) + (float)((float)(v79 * v83) * v76);
    v86 = v9->z;
    v87 = v85 + (float)((float)(v81 * v83) * v78);
    v88 = (float)((float)(v76 * v9->x) + (float)(v77 * v84)) + (float)(v78 * v86);
    if ( v88 <= 0.0 )
    {
      if ( v88 >= 0.0 )
        v89 = 0.0;
      else
        v89 = FLOAT_N1_0;
    }
    else
    {
      v89 = *(float *)&FLOAT_1_0;
    }
    if ( v87 <= 0.0 )
    {
      if ( v87 >= 0.0 )
        v13 = 0.0;
      else
        v13 = FLOAT_N1_0;
    }
    if ( v89 != v13 )
    {
      v9->x = v9->x * -1.0;
      v9->y = v84 * -1.0;
      v9->z = v86 * -1.0;
    }
    v90 = v9->y;
    v91 = v9->z;
    v92 = (float)((float)(v70 * v9->x) + (float)(v69 * v90)) + (float)(v66.m128_f32[0] * v91);
    if ( v92 < 0.0 )
    {
      v9->x = v9->x - (float)((float)(v70 * v92) * 1.5);
      v9->y = v90 - (float)((float)(v69 * v92) * 1.5);
      v9->z = v91 - (float)((float)(v66.m128_f32[0] * v92) * 1.5);
    }
  }
  return v64;
}

// File Line: 476
// RVA: 0xFEFF0
float __fastcall UFG::FFieldAvoidablePrint::GetFlowRegular(UFG::FFieldAvoidablePrint *this, UFG::qVector3 *outFlow, UFG::qVector3 *vPosition, float fTimeOffset, UFG::qVector3 *optEyePosition, UFG::qVector3 *optEyeVelocity)
{
  UFG::FFieldAvoidablePrint *v6; // rdi
  UFG::AIInterestComponent *v7; // rcx
  UFG::qVector3 *v8; // rsi
  UFG::qVector3 *v9; // rbx
  float v10; // xmm14_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm11_4
  float v15; // xmm13_4
  __int128 v16; // xmm12
  __m128 v17; // xmm2
  UFG::SimComponent *v18; // rax
  __m128 v19; // xmm0
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm15_4
  float v25; // xmm11_4
  float v26; // xmm12_4
  float v27; // xmm13_4
  UFG::SimComponent *v28; // rax
  float v29; // xmm8_4
  __m128 v30; // xmm9
  float v31; // xmm10_4
  __m128 v32; // xmm2
  float v33; // xmm3_4
  float v34; // xmm8_4
  float v35; // xmm9_4
  float v36; // xmm10_4
  UFG::qMatrix44 *v37; // rax
  UFG::SimComponent *v38; // rax
  float v39; // xmm2_4
  float v40; // xmm5_4
  float v41; // xmm4_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  UFG::AIInterestComponent *v45; // rcx
  float v46; // xmm11_4
  __m128 v47; // xmm10
  float v48; // xmm9_4
  float v49; // xmm9_4
  float v50; // xmm11_4
  __m128 v51; // xmm2
  float v52; // xmm1_4
  __m128 v53; // xmm13
  float v54; // xmm12_4
  float v55; // xmm14_4
  float v56; // xmm9_4
  float v57; // xmm10_4
  float v58; // xmm11_4
  float v59; // xmm8_4
  UFG::qMatrix44 *v60; // rax
  float v61; // xmm0_4
  float v62; // xmm5_4
  float v63; // xmm3_4
  float v64; // xmm4_4
  float v65; // xmm5_4
  float v66; // xmm8_4
  float v67; // xmm2_4
  float v68; // xmm0_4
  float v69; // xmm12_4
  float v70; // xmm14_4
  __m128 v71; // xmm2
  float v72; // xmm6_4
  UFG::qVector3 result; // [rsp+20h] [rbp-B8h]

  v6 = this;
  v7 = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
  v8 = vPosition;
  v9 = outFlow;
  v10 = fTimeOffset;
  if ( v7 )
  {
    UFG::AIInterestComponent::GetCenter(v7, &result, fTimeOffset);
    v11 = result.z;
    v12 = result.y;
    v13 = result.x;
  }
  else
  {
    v13 = UFG::qVector3::msZero.x;
    v12 = UFG::qVector3::msZero.y;
    v11 = UFG::qVector3::msZero.z;
  }
  v16 = LODWORD(v8->y);
  v14 = v8->x - v13;
  v15 = v8->z - v11;
  *(float *)&v16 = *(float *)&v16 - v12;
  v9->x = v14;
  v9->z = v15;
  v17 = (__m128)v16;
  LODWORD(v9->y) = v16;
  v18 = v6->mpInterest.m_pPointer;
  v19 = (__m128)LODWORD(v18[3].vfptr);
  v17.m128_f32[0] = (float)((float)(*(float *)&v16 * *(float *)&v16) + (float)(v14 * v14)) + (float)(v15 * v15);
  LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v17);
  v21 = *((float *)&v18[2].m_BoundComponentHandles.mNode.mNext + 1)
      - *(float *)&v18[2].m_BoundComponentHandles.mNode.mPrev;
  v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] - *((float *)&v18[2].m_BoundComponentHandles.mNode.mPrev + 1))
                          * (float)(v19.m128_f32[0] - *((float *)&v18[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                  + (float)(v21 * v21);
  v22 = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v19)) * 0.5) + v6->mParams.RadiusAdditive)
      * *(float *)&v6->mpParentField.m_pPointer[2].m_pSimObject;
  v23 = v20 / v22;
  if ( (float)(v20 / v22) <= 0.0 )
  {
    v23 = 0.0;
  }
  else if ( v23 >= 1.0 )
  {
    v23 = *(float *)&FLOAT_1_0;
  }
  v24 = 1.0 - (float)(v23 * 0.69999999);
  if ( v20 <= 0.0 || v20 > v22 )
    return 0.0;
  v25 = v14 * (float)(1.0 / v20);
  v26 = *(float *)&v16 * (float)(1.0 / v20);
  v27 = v15 * (float)(1.0 / v20);
  v9->x = v25;
  v9->y = v26;
  v9->z = v27;
  v28 = v6->mpInterest.m_pPointer;
  v29 = *((float *)&v28[3].m_SafePointerList.mNode.mNext + 1);
  v30 = (__m128)v28[3].m_TypeUID;
  v31 = *(float *)&v28[3].m_NameUID;
  v32 = v30;
  v32.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v29 * v29)) + (float)(v31 * v31);
  LODWORD(v33) = (unsigned __int128)_mm_sqrt_ps(v32);
  if ( v33 > 1.0 )
  {
    v34 = v29 * (float)(1.0 / v33);
    v35 = v30.m128_f32[0] * (float)(1.0 / v33);
    v36 = v31 * (float)(1.0 / v33);
    if ( v28 )
    {
      v37 = (UFG::qMatrix44 *)&v28[3].m_Flags;
    }
    else
    {
      v38 = v6->mpPrintComponent.m_pPointer;
      if ( v38 )
        v37 = (UFG::qMatrix44 *)(&v38[1].m_SimObjIndex + 1);
      else
        v37 = &UFG::qMatrix44::msIdentity;
    }
    v39 = v37->v2.z;
    v40 = (float)(v37->v2.x * v36) - (float)(v39 * v34);
    v41 = (float)(v39 * v35) - (float)(v37->v2.y * v36);
    v42 = (float)(v37->v2.y * v34) - (float)(v37->v2.x * v35);
    v43 = (float)((float)(v40 * v26) + (float)(v41 * v25)) + (float)(v42 * v27);
    if ( v43 <= 0.0 )
    {
      if ( v43 >= 0.0 )
        v44 = 0.0;
      else
        v44 = FLOAT_N1_0;
    }
    else
    {
      v44 = *(float *)&FLOAT_1_0;
    }
    v9->x = v41 * v44;
    v9->y = v40 * v44;
    v9->z = v42 * v44;
  }
  if ( optEyePosition )
  {
    v45 = (UFG::AIInterestComponent *)v6->mpInterest.m_pPointer;
    if ( v45 )
    {
      UFG::AIInterestComponent::GetCenter(v45, &result, v10);
      v46 = result.z;
      v47 = (__m128)LODWORD(result.y);
      v48 = result.x;
    }
    else
    {
      v48 = UFG::qVector3::msZero.x;
      v47 = (__m128)LODWORD(UFG::qVector3::msZero.y);
      v46 = UFG::qVector3::msZero.z;
    }
    v49 = v48 - optEyePosition->x;
    v47.m128_f32[0] = v47.m128_f32[0] - optEyePosition->y;
    v50 = v46 - optEyePosition->z;
    v51 = v47;
    v51.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v49 * v49)) + (float)(v50 * v50);
    v52 = v51.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v51));
    v53 = (__m128)LODWORD(v9->y);
    v54 = v9->x;
    v55 = v9->z;
    v56 = v49 * v52;
    v57 = v47.m128_f32[0] * v52;
    v58 = v50 * v52;
    v59 = (float)((float)(v9->x * v56) + (float)(v9->y * v57)) + (float)(v9->z * v58);
    if ( v59 < v6->mParams.SidestepMinDP )
    {
      v60 = UFG::FFieldAvoidablePrint::GetWorldTransform(v6);
      v61 = v60->v2.y;
      v62 = v60->v2.x;
      v63 = (float)(v61 * v56) - (float)(v62 * v57);
      v64 = (float)(v60->v2.z * v57) - (float)(v61 * v58);
      v65 = (float)(v62 * v58) - (float)(v60->v2.z * v56);
      v66 = (float)(v59 - v6->mParams.SidestepMinDP) / (float)(v6->mParams.SidestepMaxDP - v6->mParams.SidestepMinDP);
      if ( v66 <= 0.0 )
      {
        v66 = 0.0;
      }
      else if ( v66 >= 1.0 )
      {
        v66 = *(float *)&FLOAT_1_0;
      }
      v67 = (float)((float)(v54 * v64) + (float)(v53.m128_f32[0] * v65)) + (float)(v55 * v63);
      if ( v67 <= 0.0 )
      {
        if ( v67 >= 0.0 )
          v68 = 0.0;
        else
          v68 = FLOAT_N1_0;
      }
      else
      {
        v68 = *(float *)&FLOAT_1_0;
      }
      v69 = v54 + (float)((float)((float)(v64 * v68) - v54) * v66);
      v53.m128_f32[0] = v53.m128_f32[0] + (float)((float)((float)(v65 * v68) - v53.m128_f32[0]) * v66);
      v70 = v55 + (float)((float)((float)(v63 * v68) - v55) * v66);
      v71 = v53;
      v71.m128_f32[0] = (float)((float)(v53.m128_f32[0] * v53.m128_f32[0]) + (float)(v69 * v69)) + (float)(v70 * v70);
      if ( v71.m128_f32[0] == 0.0 )
        v72 = 0.0;
      else
        v72 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v71));
      v9->x = v69 * v72;
      v9->y = v53.m128_f32[0] * v72;
      v9->z = v70 * v72;
    }
  }
  return v24 * v6->m_fStrength;
}

// File Line: 525
// RVA: 0x100A10
void __fastcall UFG::FFieldAvoidablePrint::OnDebugDraw(UFG::FFieldAvoidablePrint *this, float fDeltaT, Render::View *pView)
{
  Render::View *v3; // r14
  UFG::FFieldAvoidablePrint *v4; // rbx
  unsigned int *v5; // rcx
  char v6; // al
  UFG::SimComponent *v7; // rdx
  int v8; // xmm2_4
  int v9; // xmm1_4
  UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *v10; // rax
  __int128 v11; // xmm2
  int v12; // eax
  float *v13; // rsi
  UFG::SimComponent *v14; // rdi
  float v15; // xmm6_4
  int v16; // eax
  __m128 v17; // xmm0
  float v18; // xmm7_4
  float v19; // xmm6_4
  Render::DebugDrawContext *v20; // rax
  float v21; // xmm5_4
  __m128 v22; // xmm4
  float v23; // xmm3_4
  float *v24; // rax
  float v25; // xmm7_4
  float v26; // xmm8_4
  float v27; // xmm9_4
  float v28; // xmm3_4
  float v29; // xmm5_4
  __m128 v30; // xmm2
  float v31; // xmm6_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  __m128 v37; // xmm2
  float v38; // xmm3_4
  float v39; // xmm3_4
  int v40; // xmm0_4
  float v41; // xmm7_4
  float v42; // xmm8_4
  float v43; // xmm9_4
  float v44; // xmm10_4
  float v45; // xmm11_4
  float v46; // xmm12_4
  __m128 v47; // xmm0
  float v48; // xmm6_4
  Render::DebugDrawContext *v49; // rbx
  float v50; // [rsp+30h] [rbp-D0h]
  float v51; // [rsp+34h] [rbp-CCh]
  float v52; // [rsp+38h] [rbp-C8h]
  UFG::qVector3 result; // [rsp+40h] [rbp-C0h]
  unsigned int v54; // [rsp+50h] [rbp-B0h]
  int v55; // [rsp+54h] [rbp-ACh]
  int v56; // [rsp+58h] [rbp-A8h]
  __m128i v57; // [rsp+60h] [rbp-A0h]
  float v58; // [rsp+70h] [rbp-90h]
  float v59; // [rsp+74h] [rbp-8Ch]
  int v60; // [rsp+80h] [rbp-80h]
  float v61; // [rsp+84h] [rbp-7Ch]
  float v62; // [rsp+88h] [rbp-78h]
  int v63; // [rsp+8Ch] [rbp-74h]
  int v64; // [rsp+90h] [rbp-70h]
  float v65; // [rsp+94h] [rbp-6Ch]

  v3 = pView;
  v4 = this;
  if ( this->mpInterest.m_pPointer )
  {
    v5 = (unsigned int *)this->mpParentField.m_pPointer;
    if ( v5 )
    {
      v6 = v4->m_Enabled;
      if ( v6 )
      {
        v7 = v4->mpPrintComponent.m_pPointer;
        if ( v7 )
          v6 = v7[1].m_Flags;
        if ( v6 )
        {
          v8 = v5[38];
          v9 = v5[37];
          v10 = v4->vfptr;
          v54 = v5[36];
          v55 = v9;
          v56 = v8;
          v11 = v5[35];
          if ( v10[3].__vecDelDtor((UFG::qSafePointerNode<UFG::FlowfieldPrint> *)&v4->vfptr, (unsigned int)&v54) )
          {
            v12 = UFG::FFieldAvoidablePrint::GetAvoidMethod(v4);
            v13 = (float *)v4->mpParentField.m_pPointer;
            v14 = v4->mpInterest.m_pPointer;
            v15 = v13[35];
            v16 = v12 - 2;
            if ( v16 )
            {
              if ( v16 == 1 )
              {
                if ( v14 )
                {
                  UFG::AIInterestComponent::GetCenter(
                    (UFG::AIInterestComponent *)v4->mpInterest.m_pPointer,
                    &result,
                    v13[35]);
                  v21 = result.z;
                  v22 = (__m128)LODWORD(result.y);
                  v23 = result.x;
                }
                else
                {
                  v23 = UFG::qVector3::msZero.x;
                  v22 = (__m128)LODWORD(UFG::qVector3::msZero.y);
                  v21 = UFG::qVector3::msZero.z;
                }
                v24 = v13 + 36;
                if ( v13 != (float *)-144i64 )
                {
                  v25 = *v24;
                  v26 = v13[37];
                  v27 = v13[38];
                  v28 = v23 - *v24;
                  v22.m128_f32[0] = v22.m128_f32[0] - v26;
                  v29 = v21 - v27;
                  v30 = v22;
                  result.x = *v24;
                  v30.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v28 * v28))
                                  + (float)(v29 * v29);
                  result.y = v26;
                  result.z = v27;
                  LODWORD(v31) = (unsigned __int128)_mm_sqrt_ps(v30);
                  v50 = v28;
                  v51 = v22.m128_f32[0];
                  v52 = v29;
                  if ( v31 > 0.001 )
                  {
                    v32 = v28 * (float)(1.0 / v31);
                    v33 = v22.m128_f32[0] * (float)(1.0 / v31);
                    v34 = v29 * (float)(1.0 / v31);
                    v35 = FLOAT_10_0;
                    v50 = v32;
                    v51 = v33;
                    v52 = v34;
                    if ( v31 >= 10.0 )
                      v35 = v31;
                    v36 = v35 - v31;
                    v31 = v31 + v36;
                    result.x = v25 - (float)(v32 * v36);
                    result.y = v26 - (float)(v33 * v36);
                    result.z = v27 - (float)(v34 * v36);
                  }
                  v37 = (__m128)LODWORD(v14[3].vfptr);
                  v38 = *((float *)&v14[2].m_BoundComponentHandles.mNode.mNext + 1);
                  v60 = 1065353216;
                  v63 = 0;
                  v37.m128_f32[0] = v37.m128_f32[0] - *((float *)&v14[2].m_BoundComponentHandles.mNode.mPrev + 1);
                  v39 = v38 - *(float *)&v14[2].m_BoundComponentHandles.mNode.mPrev;
                  v57.m128i_i32[0] = 1065353216;
                  *(__int64 *)((char *)v57.m128i_i64 + 4) = LODWORD(FLOAT_0_2);
                  v37.m128_f32[0] = (float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v39 * v39);
                  v61 = v4->mParams.FLMinDist;
                  v40 = LODWORD(v4->mParams.FLMinAngle);
                  *(float *)&v57.m128i_i32[3] = UFG::gTempFlowprintAlpha;
                  v64 = v40;
                  v62 = v31;
                  v65 = atan2f(
                          (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v37)) * 0.5) + v4->mParams.RadiusAdditive) * v13[42],
                          v31)
                      * 1.2;
                  _mm_store_si128(&v57, v57);
                  UFG::FlashlightDisplay2(
                    &result,
                    (UFG::qVector3 *)&v50,
                    (UFG::FlashlightParams *)&v60,
                    v3,
                    (UFG::qColour *)&v57);
                }
              }
              else
              {
                if ( v14 )
                  UFG::AIInterestComponent::GetCenter(
                    (UFG::AIInterestComponent *)v4->mpInterest.m_pPointer,
                    &result,
                    v13[35]);
                else
                  result = UFG::qVector3::msZero;
                v17 = (__m128)LODWORD(v14[3].vfptr);
                v18 = v13[42];
                v17.m128_f32[0] = (float)((float)(v17.m128_f32[0]
                                                - *((float *)&v14[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                        * (float)(v17.m128_f32[0]
                                                - *((float *)&v14[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                                + (float)((float)(*((float *)&v14[2].m_BoundComponentHandles.mNode.mNext + 1)
                                                - *(float *)&v14[2].m_BoundComponentHandles.mNode.mPrev)
                                        * (float)(*((float *)&v14[2].m_BoundComponentHandles.mNode.mNext + 1)
                                                - *(float *)&v14[2].m_BoundComponentHandles.mNode.mPrev));
                v19 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v17)) * 0.5) + v4->mParams.RadiusAdditive;
                v20 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                    Render::DebugDrawManager::mInstance,
                                                    2u);
                Render::DebugDrawContext::DrawSphere(
                  v20,
                  &result,
                  v18 * v19,
                  &UFG::qColour::White,
                  &UFG::qMatrix44::msIdentity,
                  0i64);
              }
            }
            else
            {
              v41 = UFG::qVector3::msZero.z;
              v42 = UFG::qVector3::msZero.y;
              v43 = UFG::qVector3::msZero.x;
              if ( v14 )
              {
                UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)v14, &result, 0.0);
                v44 = result.z;
                v45 = result.y;
                v46 = result.x;
              }
              else
              {
                v46 = UFG::qVector3::msZero.x;
                v45 = UFG::qVector3::msZero.y;
                v44 = UFG::qVector3::msZero.z;
              }
              if ( v14 )
              {
                UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)v14, &result, v15);
                v41 = result.z;
                v42 = result.y;
                v43 = result.x;
              }
              v57.m128i_i64[0] = __PAIR__(LODWORD(v45), LODWORD(v46));
              v57.m128i_i64[1] = __PAIR__(LODWORD(v43), LODWORD(v44));
              v58 = v42;
              v59 = v41;
              v47 = (__m128)LODWORD(v14[3].vfptr);
              v47.m128_f32[0] = (float)((float)(v47.m128_f32[0]
                                              - *((float *)&v14[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                      * (float)(v47.m128_f32[0]
                                              - *((float *)&v14[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                              + (float)((float)(*((float *)&v14[2].m_BoundComponentHandles.mNode.mNext + 1)
                                              - *(float *)&v14[2].m_BoundComponentHandles.mNode.mPrev)
                                      * (float)(*((float *)&v14[2].m_BoundComponentHandles.mNode.mNext + 1)
                                              - *(float *)&v14[2].m_BoundComponentHandles.mNode.mPrev));
              v48 = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v47)) * 0.5) + v4->mParams.RadiusAdditive) * v13[42];
              v49 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                  Render::DebugDrawManager::mInstance,
                                                  2u);
              Render::DebugDrawContext::DrawLineStrip(
                v49,
                (UFG::qVector3 *)&v57,
                2,
                &UFG::qColour::White,
                &UFG::qMatrix44::msIdentity,
                0i64);
              Render::DebugDrawContext::DrawSphere(
                v49,
                (UFG::qVector3 *)&v57,
                v48,
                &UFG::qColour::White,
                &UFG::qMatrix44::msIdentity,
                0i64);
              Render::DebugDrawContext::DrawSphere(
                v49,
                (UFG::qVector3 *)((char *)&v57.m128i_u64[1] + 4),
                v48,
                &UFG::qColour::White,
                &UFG::qMatrix44::msIdentity,
                0i64);
            }
          }
        }
      }
    }
  }
}

// File Line: 617
// RVA: 0xFFD80
UFG::qVector3 *__fastcall UFG::FFieldAttractor::GetPosition(UFG::FFieldAttractor *this, UFG::qVector3 *result, float fTimeOffset)
{
  float *v3; // rax
  float v4; // xmm3_4
  float v5; // xmm4_4
  UFG::qVector3 *v6; // rbx
  float v7; // xmm6_4
  UFG::AIInterestComponent *v8; // rcx
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm8_4
  float v14; // xmm6_4
  UFG::qVector3 *v15; // rax
  float v16; // xmm8_4
  float v17; // xmm6_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-48h]

  v3 = (float *)this->mpPrintComponent.m_pPointer;
  v4 = this->mParams.Offset.y;
  v5 = this->mParams.Offset.z;
  v6 = result;
  v7 = this->mParams.Offset.x;
  v8 = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
  v9 = v7 * v3[26];
  v10 = (float)((float)(v4 * v3[29]) + (float)(v7 * v3[25])) + (float)(v5 * v3[33]);
  v11 = v4 * v3[30];
  v12 = (float)(v7 * v3[27]) + (float)(v4 * v3[31]);
  result->x = v10;
  v13 = (float)(v9 + v11) + (float)(v5 * v3[34]);
  v14 = v12 + (float)(v5 * v3[35]);
  result->y = v13;
  result->z = v14;
  if ( v8 )
  {
    v15 = UFG::AIInterestComponent::GetCenter(v8, &resulta, fTimeOffset);
    v16 = v13 + v15->y;
    v17 = v14 + v15->z;
    v6->x = v10 + v15->x;
    v6->y = v16;
    v6->z = v17;
  }
  return v6;
}

// File Line: 628
// RVA: 0xFDA10
float __fastcall UFG::FFieldAttractor::GetFlow(UFG::FFieldAttractor *this, UFG::qVector3 *outFlow, UFG::qVector3 *vPosition, float fTimeOffset, UFG::qVector3 *optEyePosition, UFG::qVector3 *optEyeVelocity)
{
  UFG::qVector3 *v6; // rsi
  UFG::qVector3 *v7; // rbx
  UFG::FFieldAttractor *v8; // rdi
  float v10; // xmm7_4
  float v11; // xmm3_4
  __int128 v12; // xmm4
  __m128 v13; // xmm2
  float v14; // xmm5_4
  UFG::SimComponent *v15; // rax
  __m128 v16; // xmm0
  float v17; // xmm9_4
  float v18; // xmm6_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm10_4
  float v27; // xmm13_4
  float v28; // xmm14_4
  float v29; // xmm5_4
  float v30; // xmm9_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm9_4
  float v34; // xmm11_4
  float v35; // xmm12_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  __m128 v38; // xmm2
  float v39; // xmm3_4
  __m128 v40; // xmm4
  float v41; // xmm2_4
  __m128 v42; // xmm5
  float v43; // xmm8_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm2_4
  UFG::qVector3 result; // [rsp+20h] [rbp-E8h]
  UFG::qVector3 vOutDir; // [rsp+30h] [rbp-D8h]
  UFG::FlashlightParams params; // [rsp+40h] [rbp-C8h]

  v6 = vPosition;
  v7 = outFlow;
  v8 = this;
  if ( !this->mpInterest.m_pPointer )
    return 0.0;
  v10 = 0.0;
  UFG::FFieldAttractor::GetPosition(this, &result, fTimeOffset);
  v12 = LODWORD(result.y);
  v11 = result.x - v6->x;
  *(float *)&v12 = result.y - v6->y;
  v13 = (__m128)v12;
  v14 = result.z - v6->z;
  v7->x = v11;
  LODWORD(v7->y) = v12;
  v7->z = v14;
  v15 = v8->mpInterest.m_pPointer;
  v16 = (__m128)LODWORD(v15[3].vfptr);
  v13.m128_f32[0] = (float)((float)(*(float *)&v12 * *(float *)&v12) + (float)(v11 * v11)) + (float)(v14 * v14);
  LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v13);
  v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] - *((float *)&v15[2].m_BoundComponentHandles.mNode.mPrev + 1))
                          * (float)(v16.m128_f32[0] - *((float *)&v15[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                  + (float)((float)(*((float *)&v15[2].m_BoundComponentHandles.mNode.mNext + 1)
                                  - *(float *)&v15[2].m_BoundComponentHandles.mNode.mPrev)
                          * (float)(*((float *)&v15[2].m_BoundComponentHandles.mNode.mNext + 1)
                                  - *(float *)&v15[2].m_BoundComponentHandles.mNode.mPrev));
  v18 = v17 / (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v16)) * 0.5) + v8->mParams.RadiusAdditive);
  if ( v18 <= 0.0 )
  {
    v18 = 0.0;
  }
  else if ( v18 >= 1.0 )
  {
    v18 = *(float *)&FLOAT_1_0;
  }
  v19 = (float)(v18 * 0.69999999) + 0.30000001;
  if ( v17 > 0.0 && v19 > 0.0 )
  {
    v7->z = (float)(1.0 / v17) * v14;
    v7->x = (float)(1.0 / v17) * v11;
    v7->y = (float)(1.0 / v17) * *(float *)&v12;
    UFG::FFieldAttractor::CalcFlashlightDirection(v8, &vOutDir);
    v20 = v8->mParams.Orientation;
    if ( v20 == 1.0 || v20 == 0.0 )
    {
      v23 = v8->mParams.FLMaxDist;
      params.fMinDistance = v8->mParams.FLMinDist;
      v24 = v8->mParams.FLMinAngle;
      params.fMaxDistance = v23;
      params.fAngleWeight = 0.5;
      params.fDeadDistance = 0.0;
      v25 = v8->mParams.FLMaxAngle;
      params.fMinRads = v24;
      params.fMaxRads = v25;
      v26 = UFG::FlashlightScore(&result, &vOutDir, &params, v6);
      if ( v26 > 0.0 )
      {
        v27 = v7->z;
        v28 = v7->y;
        v29 = (float)(v27 * vOutDir.y) - (float)(v7->y * vOutDir.z);
        v30 = (float)(v7->x * vOutDir.z) - (float)(v27 * vOutDir.x);
        v31 = (float)(v28 * vOutDir.x) - (float)(v7->x * vOutDir.y);
        v32 = v30;
        v33 = (float)(v30 * vOutDir.x) - (float)(v29 * vOutDir.y);
        v34 = (float)(v31 * vOutDir.y) - (float)(v32 * vOutDir.z);
        v35 = (float)(v29 * vOutDir.z) - (float)(v31 * vOutDir.x);
        v36 = (float)((float)(v7->x * v34) + (float)(v7->y * v35)) + (float)(v27 * v33);
        if ( v36 <= 0.0 )
        {
          if ( v36 >= 0.0 )
            v37 = 0.0;
          else
            v37 = FLOAT_N1_0;
        }
        else
        {
          v37 = *(float *)&FLOAT_1_0;
        }
        v38 = (__m128)(unsigned int)FLOAT_1_0;
        v38.m128_f32[0] = 1.0 - v26;
        v40 = v38;
        v39 = (float)((float)(1.0 - v26) * (float)((float)(v34 * v37) - v7->x)) + v7->x;
        v40.m128_f32[0] = (float)((float)(1.0 - v26) * (float)((float)(v35 * v37) - v28)) + v28;
        v41 = (float)((float)(1.0 - v26) * (float)((float)(v33 * v37) - v27)) + v27;
        v42 = v40;
        v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
        if ( v42.m128_f32[0] == 0.0 )
          v43 = 0.0;
        else
          v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v42));
        v44 = v39 * v43;
        v45 = v40.m128_f32[0] * v43;
        v46 = v41 * v43;
        v7->x = v44;
        v7->y = v45;
        v7->z = v46;
        v10 = v8->m_fStrength;
        v7->x = v44 * v19;
        v7->y = v45 * v19;
        v7->z = v46 * v19;
      }
    }
    else
    {
      v10 = v8->m_fStrength;
      v21 = v19 * v7->x;
      v22 = v19 * v7->y;
      v7->z = v19 * v7->z;
      v7->x = v21;
      v7->y = v22;
    }
  }
  return v10;
}

// File Line: 678
// RVA: 0x1004D0
bool __fastcall UFG::FFieldAttractor::IsFlowDefinedAt(UFG::FFieldAttractor *this, UFG::qVector3 *vPosition, float fTimeOffset)
{
  UFG::qVector3 *v3; // rbx
  UFG::FFieldAttractor *v4; // rdi
  UFG::qVector3 *v5; // rax
  float *v7; // rbx
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  __m128 v13; // xmm2
  float v14; // xmm5_4
  __m128 v15; // xmm6
  UFG::qVector3 result; // [rsp+20h] [rbp-58h]

  v3 = vPosition;
  v4 = this;
  if ( this->mpInterest.m_pPointer )
  {
    v5 = UFG::FFieldAttractor::GetPosition(this, &result, fTimeOffset);
    if ( (float)((float)((float)((float)(v3->x - v5->x) * (float)(v3->x - v5->x))
                       + (float)((float)(v3->y - v5->y) * (float)(v3->y - v5->y)))
               + (float)((float)(v3->z - v5->z) * (float)(v3->z - v5->z))) > (float)(v4->mParams.FLMaxDist
                                                                                   * v4->mParams.FLMaxDist) )
      return 0;
  }
  UFG::FFieldAttractor::CalcFlashlightDirection(v4, &result);
  v7 = (float *)v4->mpParentField.m_pPointer;
  v8 = result.x * -1.0;
  v9 = result.y * -1.0;
  v10 = result.z * -1.0;
  UFG::FFieldAttractor::GetPosition(v4, &result, v7[35]);
  v13 = (__m128)LODWORD(result.y);
  v11 = 0.0;
  v12 = result.x - v7[36];
  v13.m128_f32[0] = result.y - v7[37];
  v15 = v13;
  v14 = result.z - v7[38];
  v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v15.m128_f32[0] != 0.0 )
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
  return (float)((float)((float)((float)(v13.m128_f32[0] * v11) * v9) + (float)((float)(v12 * v11) * v8))
               + (float)((float)(v14 * v11) * v10)) >= v4->mParams.MinOrientationError;
}

// File Line: 711
// RVA: 0xFCB90
void __fastcall UFG::FFieldAttractor::CalcFlashlightDirection(UFG::FFieldAttractor *this, UFG::qVector3 *vOutDir)
{
  UFG::SimComponent *v2; // rsi
  UFG::qVector3 *v3; // rbx
  UFG::FFieldAttractor *v4; // rdi
  signed int v5; // eax
  UFG::SimComponent *v6; // rax
  int v7; // xmm2_4
  int v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  __m128 v11; // xmm4
  float v12; // xmm5_4
  __m128 v13; // xmm6
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qVector3 result; // [rsp+20h] [rbp-28h]

  v2 = this->mpParentField.m_pPointer;
  v3 = vOutDir;
  v4 = this;
  UFG::FFieldAttractor::GetPosition(this, &result, *((float *)&v2[2].m_SafePointerList.mNode.mPrev + 1));
  v5 = (signed int)v4->mParams.Orientation;
  if ( v5 == 1 )
  {
    v6 = v4->mpPrintComponent.m_pPointer;
    v7 = LODWORD(v6[1].m_pSimObject) ^ _xmm[0];
    v8 = HIDWORD(v6[1].m_pSimObject) ^ _xmm[0];
    LODWORD(v3->x) = *(_DWORD *)(&v6[1].m_SimObjIndex + 1) ^ _xmm[0];
    LODWORD(v3->y) = v7;
    LODWORD(v3->z) = v8;
  }
  else if ( v5 )
  {
    v14 = UFG::qVector3::msDirFront.y;
    v15 = UFG::qVector3::msDirFront.z;
    v3->x = UFG::qVector3::msDirFront.x;
    v3->y = v14;
    v3->z = v15;
  }
  else
  {
    v11 = (__m128)HIDWORD(v2[2].m_SafePointerList.mNode.mNext);
    v9 = 0.0;
    v10 = *(float *)&v2[2].m_SafePointerList.mNode.mNext - result.x;
    v11.m128_f32[0] = v11.m128_f32[0] - result.y;
    v12 = *(float *)&v2[2].m_TypeUID - result.z;
    v13 = v11;
    v13.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10)) + (float)(v12 * v12);
    if ( v13.m128_f32[0] != 0.0 )
      v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
    v3->x = v10 * v9;
    v3->y = v11.m128_f32[0] * v9;
    v3->z = v12 * v9;
  }
}

// File Line: 759
// RVA: 0xFAFC0
void __fastcall UFG::FFieldPathPrint::FFieldPathPrint(UFG::FFieldPathPrint *this, UFG::HermiteCurve *pPathCurve, int iPriority, float fStrength)
{
  int v4; // edi
  UFG::HermiteCurve *v5; // rbx
  UFG::FFieldPathPrint *v6; // rsi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  v4 = iPriority;
  v5 = pPathCurve;
  v6 = this;
  UFG::FlowfieldPrint::FlowfieldPrint((UFG::FlowfieldPrint *)&this->vfptr, 1u, iPriority, fStrength);
  v6->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::FFieldPathPrint::`vftable;
  v6->mParams.MinTForPerp = 0.0099999998;
  v6->mParams.DistForPerp = 3.0;
  v6->mParams.GlobalSearchDist = 25.0;
  v6->mParams.Priority = 5.0;
  v6->mParams.FlowScaleTangent = 1.25;
  v6->mParams.FlowScalePerp = 1.5;
  v6->mParams.Strength = 0.5;
  v6->mParams.VelForTangent = 20.0;
  v6->mParams.MaxDistance = 200.0;
  v6->mParams.VelForPerp = 5.0;
  v6->mParams.DistForTangent = 0.5;
  v6->mpPathCurve = v5;
  v6->mCurveWalker.mpCurve = v5;
  v6->mCurveWalker.mfGlobalSearchDist = 15.0;
  v6->mCurveWalker.mfLastT = -1.0;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  v6->mCurveWalker.mvLastPos.x = UFG::qVector3::msZero.x;
  v6->mCurveWalker.mvLastPos.y = v7;
  v6->mCurveWalker.mvLastPos.z = v8;
  v6->mCurveWalker.mfLastT = -1.0;
  v6->mCurveWalker.mfCurveLength = -1.0;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v6->mCurveWalker.mvLastPos.x = UFG::qVector3::msZero.x;
  v6->mCurveWalker.mvLastPos.y = v9;
  v6->mCurveWalker.mvLastPos.z = v10;
  if ( v4 <= 0 )
    v6->m_iPriority = (signed int)v6->mParams.Priority;
  if ( fStrength <= 0.0 )
    v6->m_fStrength = v6->mParams.Strength;
}

// File Line: 839
// RVA: 0xFDF00
float __fastcall UFG::FFieldPathPrint::GetFlow(UFG::FFieldPathPrint *this, UFG::qVector3 *outFlow, UFG::qVector3 *vPosition, float fTimeOffset, UFG::qVector3 *optEyePosition, UFG::qVector3 *optEyeVelocity)
{
  UFG::FFieldPathPrint *v6; // rbx
  UFG::HermiteCurve *v7; // rcx
  UFG::qVector3 *v8; // rsi
  float v9; // xmm1_4
  float v10; // xmm0_4
  __m128 v11; // xmm4
  __m128 v12; // xmm2
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm8_4
  float v17; // xmm10_4
  __m128 v18; // xmm11
  __m128 v19; // xmm2
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm9_4
  float v23; // xmm3_4
  float v24; // xmm12_4
  float v25; // xmm10_4
  float v26; // xmm9_4
  float v27; // xmm8_4
  float v28; // xmm2_4
  __m128 v29; // xmm4
  float v30; // xmm5_4
  __m128 v31; // xmm3
  float v32; // xmm1_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm5_4
  float v37; // xmm2_4
  float v38; // xmm4_4
  __m128 v39; // xmm3
  float v40; // xmm5_4
  __m128 v41; // xmm8
  float v42; // xmm6_4
  float v43; // xmm0_4
  UFG::qVector3 vOutTangent; // [rsp+50h] [rbp-A8h]
  UFG::qVector3 target_point; // [rsp+60h] [rbp-98h]
  UFG::qVector3 closest_point; // [rsp+70h] [rbp-88h]
  float v48; // [rsp+7Ch] [rbp-7Ch]
  float v49; // [rsp+80h] [rbp-78h]
  UFG::qVector3 outTangent; // [rsp+88h] [rbp-70h]
  UFG::qVector3 *vCurrentPos; // [rsp+138h] [rbp+40h]

  v6 = this;
  v7 = this->mpPathCurve;
  v8 = outFlow;
  if ( !v7 || !v7->mNumControlPoints )
    return 0.0;
  v9 = vPosition->y;
  target_point.x = vPosition->x;
  target_point.z = vPosition->z;
  target_point.y = v9;
  v10 = UFG::HermiteCurve::ClosestPointEx(v7, &target_point, &closest_point, -1.234, -1.234, -1.0, -1.234, -1.234);
  UFG::HermiteCurve::GetTangent(v6->mpPathCurve, v10, &vOutTangent);
  v11 = (__m128)LODWORD(vOutTangent.x);
  v12 = v11;
  v12.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(vOutTangent.y * vOutTangent.y))
                  + (float)(vOutTangent.z * vOutTangent.z);
  if ( v12.m128_f32[0] == 0.0 )
    v13 = 0.0;
  else
    v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
  v18 = (__m128)LODWORD(closest_point.y);
  v14 = vOutTangent.x * v13;
  v15 = vOutTangent.y * v13;
  v16 = vOutTangent.z * v13;
  v17 = closest_point.x - target_point.x;
  v18.m128_f32[0] = closest_point.y - target_point.y;
  target_point.z = closest_point.z;
  v19 = v18;
  vOutTangent.x = vOutTangent.x * v13;
  vOutTangent.y = vOutTangent.y * v13;
  v19.m128_f32[0] = (float)((float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v17 * v17)) + (float)(0.0 * 0.0);
  v20 = v6->mParams.DistForTangent;
  vOutTangent.z = v16;
  LODWORD(v21) = (unsigned __int128)_mm_sqrt_ps(v19);
  if ( v21 <= v20 )
  {
    v43 = v6->mParams.FlowScaleTangent;
    v8->x = v14 * v43;
    v8->y = v15 * v43;
    v8->z = v16 * v43;
  }
  else
  {
    v22 = 1.0 / v21;
    v23 = (float)(v21 - v6->mParams.DistForPerp) / (float)(v20 - v6->mParams.DistForPerp);
    v24 = v22 * v17;
    v25 = v22 * v18.m128_f32[0];
    v26 = v22 * 0.0;
    if ( v23 <= 0.0 )
    {
      v23 = 0.0;
    }
    else if ( v23 >= 1.0 )
    {
      v23 = *(float *)&FLOAT_1_0;
    }
    v27 = (float)((float)(1.0 - v6->mParams.MinTForPerp) * v23) + v6->mParams.MinTForPerp;
    if ( optEyePosition
      && vCurrentPos
      && 0.0 != optEyePosition->x
      && 0.0 != optEyePosition->y
      && 0.0 != optEyePosition->z )
    {
      UFG::HermiteCurveWalker::GetClosestPoint(
        &v6->mCurveWalker,
        (UFG::qVector3 *)((char *)&closest_point + 8),
        &outTangent,
        vCurrentPos,
        0.0,
        -1.234,
        -1.234,
        20,
        -1.234);
      v29 = (__m128)LODWORD(v48);
      v28 = closest_point.z - vCurrentPos->x;
      v29.m128_f32[0] = v48 - vCurrentPos->y;
      v30 = v49 - vCurrentPos->z;
      v31 = v29;
      v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v28 * v28)) + (float)(v30 * v30);
      if ( v31.m128_f32[0] == 0.0 )
        v32 = 0.0;
      else
        v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
      v34 = (float)((float)((float)((float)((float)(v28 * v32) * optEyePosition->x)
                                  + (float)((float)(v29.m128_f32[0] * v32) * optEyePosition->y))
                          + (float)((float)(v30 * v32) * optEyePosition->z))
                  - v6->mParams.VelForPerp)
          / (float)(v6->mParams.VelForTangent - v6->mParams.VelForPerp);
      if ( v34 <= 0.0 )
      {
        v34 = 0.0;
      }
      else if ( v34 >= 1.0 )
      {
        v34 = *(float *)&FLOAT_1_0;
      }
      v33 = v6->mParams.MinTForPerp;
      if ( (float)((float)((float)(1.0 - v33) * v34) + v33) > v27 )
        v27 = (float)((float)(1.0 - v33) * v34) + v33;
    }
    v35 = v6->mParams.FlowScalePerp;
    v39 = (__m128)LODWORD(vOutTangent.y);
    v36 = (float)(v6->mParams.FlowScaleTangent - v35) * v27;
    v37 = (float)((float)(vOutTangent.x - v24) * v27) + v24;
    v38 = (float)((float)(vOutTangent.z - v26) * v27) + v26;
    v39.m128_f32[0] = (float)((float)(vOutTangent.y - v25) * v27) + v25;
    v41 = v39;
    v40 = v36 + v35;
    v41.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v37 * v37)) + (float)(v38 * v38);
    if ( v41.m128_f32[0] == 0.0 )
      v42 = 0.0;
    else
      v42 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v41));
    v8->x = (float)(v37 * v42) * v40;
    v8->y = (float)(v39.m128_f32[0] * v42) * v40;
    v8->z = (float)(v38 * v42) * v40;
  }
  return v6->m_fStrength;
}

// File Line: 991
// RVA: 0x14613C0
__int64 dynamic_initializer_for__UFG::FFieldPrintComponent::s_FFieldPrintComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::FFieldPrintComponent::s_FFieldPrintComponentList__);
}

// File Line: 992
// RVA: 0x1461320
__int64 dynamic_initializer_for__UFG::FFieldPrintComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::FFieldPrintComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::FFieldPrintComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::FFieldPrintComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::FFieldPrintComponent::_TypeIDesc.mChildren = result;
  return result;
}

