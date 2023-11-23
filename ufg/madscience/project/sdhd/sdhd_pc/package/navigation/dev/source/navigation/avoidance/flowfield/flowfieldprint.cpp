// File Line: 63
// RVA: 0xFBE60
void __fastcall UFG::FlowfieldPrint::~FlowfieldPrint(UFG::FlowfieldPrint *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *p_mpInterest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *p_mpPrintComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FlowfieldComponent> *p_mpParentField; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList> *v17; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList> *v18; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v19; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v22; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::FlowfieldPrint::`vftable;
  p_mpInterest = &this->mpInterest;
  if ( this->mpInterest.m_pPointer )
  {
    mPrev = p_mpInterest->mPrev;
    mNext = p_mpInterest->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpInterest->mPrev = p_mpInterest;
    p_mpInterest->mNext = p_mpInterest;
  }
  p_mpInterest->m_pPointer = 0i64;
  v5 = p_mpInterest->mPrev;
  v6 = p_mpInterest->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpInterest->mPrev = p_mpInterest;
  p_mpInterest->mNext = p_mpInterest;
  p_mpPrintComponent = &this->mpPrintComponent;
  if ( this->mpPrintComponent.m_pPointer )
  {
    v8 = p_mpPrintComponent->mPrev;
    v9 = this->mpPrintComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mpPrintComponent->mPrev = p_mpPrintComponent;
    this->mpPrintComponent.mNext = &this->mpPrintComponent;
  }
  this->mpPrintComponent.m_pPointer = 0i64;
  v10 = p_mpPrintComponent->mPrev;
  v11 = this->mpPrintComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mpPrintComponent->mPrev = p_mpPrintComponent;
  this->mpPrintComponent.mNext = &this->mpPrintComponent;
  p_mpParentField = &this->mpParentField;
  if ( this->mpParentField.m_pPointer )
  {
    v13 = p_mpParentField->mPrev;
    v14 = this->mpParentField.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_mpParentField->mPrev = p_mpParentField;
    this->mpParentField.mNext = &this->mpParentField;
  }
  this->mpParentField.m_pPointer = 0i64;
  v15 = p_mpParentField->mPrev;
  v16 = this->mpParentField.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mpParentField->mPrev = p_mpParentField;
  this->mpParentField.mNext = &this->mpParentField;
  v17 = this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>::mPrev;
  v18 = this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>::mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>::mPrev = &this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>;
  this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>::mNext = &this->UFG::qNode<UFG::FlowfieldPrint,UFG::FFieldPrintCompList>;
  v19 = this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mPrev;
  v20 = this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mPrev = &this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>;
  this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mNext = &this->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>;
  this->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::qSafePointerNode<UFG::FlowfieldPrint>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v21 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::FlowfieldPrint>::mPrev;
  v22 = this->m_SafePointerList.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::FlowfieldPrint>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

// File Line: 118
// RVA: 0xFD530
__int64 __fastcall UFG::FFieldAvoidablePrint::GetAvoidMethod(UFG::FFieldAvoidablePrint *this)
{
  unsigned int Method; // edi
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qVector3 *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  UFG::qVector3 *Center; // rax
  UFG::qVector3 v1; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 result; // [rsp+3Ch] [rbp-1Ch] BYREF
  float closing_speed; // [rsp+60h] [rbp+8h] BYREF

  Method = (int)this->mParams.Method;
  if ( Method == 2 )
  {
    m_pPointer = this->mpInterest.m_pPointer;
    v4 = (UFG::qVector3 *)this->mpParentField.m_pPointer;
    v5 = *(float *)&m_pPointer[3].m_TypeUID;
    v6 = *((float *)&m_pPointer[3].m_SafePointerList.mNode.mNext + 1);
    LODWORD(v1.z) = m_pPointer[3].m_NameUID;
    v1.x = v6;
    v1.y = v5;
    Center = UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)m_pPointer, &result, 0.0);
    UFG::ClosingTime(v4 + 12, v4 + 13, Center, &v1, &closing_speed);
    if ( closing_speed >= 1.0 )
      return 3;
  }
  return Method;
}

// File Line: 150
// RVA: 0xFDE60
float __fastcall UFG::FFieldAvoidablePrint::GetFlow(
        UFG::FFieldAvoidablePrint *this,
        UFG::qVector3 *outFlow,
        UFG::qVector3 *vPosition,
        float fTimeOffset,
        UFG::qVector3 *optEyePosition,
        UFG::qVector3 *optEyeVelocity)
{
  int v10; // eax

  if ( !this->mpInterest.m_pPointer )
    return 0.0;
  v10 = UFG::FFieldAvoidablePrint::GetAvoidMethod(this) - 2;
  if ( !v10 )
    return UFG::FFieldAvoidablePrint::GetFlowSweep(
             this,
             outFlow,
             vPosition,
             fTimeOffset,
             optEyePosition,
             optEyeVelocity);
  if ( v10 == 1 )
    return UFG::FFieldAvoidablePrint::GetFlowFlashlight(
             this,
             outFlow,
             vPosition,
             fTimeOffset,
             optEyePosition,
             optEyeVelocity);
  return UFG::FFieldAvoidablePrint::GetFlowRegular(
           this,
           outFlow,
           vPosition,
           fTimeOffset,
           optEyePosition,
           optEyeVelocity);
}

// File Line: 186
// RVA: 0x100660
bool __fastcall UFG::FFieldAvoidablePrint::IsFlowDefinedAt(
        UFG::FFieldAvoidablePrint *this,
        UFG::qVector3 *vPosition,
        float fTimeOffset)
{
  float x; // xmm8_4
  float y; // xmm7_4
  float z; // xmm9_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  UFG::SimComponent *m_pPointer; // rax
  __m128 vfptr_low; // xmm0
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::qVector3 result; // [rsp+20h] [rbp-68h] BYREF

  if ( !this->mpInterest.m_pPointer )
    return 0;
  UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)this->mpInterest.m_pPointer, &result, fTimeOffset);
  x = vPosition->x;
  y = vPosition->y;
  z = vPosition->z;
  v8 = (float)((float)((float)(y - result.y) * (float)(y - result.y))
             + (float)((float)(vPosition->x - result.x) * (float)(vPosition->x - result.x)))
     + (float)((float)(z - result.z) * (float)(z - result.z));
  if ( fTimeOffset != 0.0 )
  {
    UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)this->mpInterest.m_pPointer, &result, 0.0);
    v9 = (float)((float)((float)(y - result.y) * (float)(y - result.y))
               + (float)((float)(x - result.x) * (float)(x - result.x)))
       + (float)((float)(z - result.z) * (float)(z - result.z));
    if ( v8 >= v9 )
      v8 = v9;
  }
  if ( (unsigned int)UFG::FFieldAvoidablePrint::GetAvoidMethod(this) == 3 )
    return v8 <= (float)(this->mParams.FLMaxDist * this->mParams.FLMaxDist);
  m_pPointer = this->mpInterest.m_pPointer;
  vfptr_low = (__m128)LODWORD(m_pPointer[3].vfptr);
  v13 = *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext + 1)
      - *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev;
  vfptr_low.m128_f32[0] = (float)((float)(vfptr_low.m128_f32[0]
                                        - *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                * (float)(vfptr_low.m128_f32[0]
                                        - *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                        + (float)(v13 * v13);
  v14 = (float)((float)((float)(_mm_sqrt_ps(vfptr_low).m128_f32[0] * 0.5) + this->mParams.RadiusAdditive)
              * *(float *)&this->mpParentField.m_pPointer[2].m_pSimObject)
      * 5.0;
  return (float)(v14 * v14) > v8;
}

// File Line: 262
// RVA: 0xFFEE0
UFG::qMatrix44 *__fastcall UFG::FFieldAvoidablePrint::GetWorldTransform(UFG::FFieldAvoidablePrint *this)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimComponent *v3; // rax

  m_pPointer = this->mpInterest.m_pPointer;
  if ( m_pPointer )
    return (UFG::qMatrix44 *)&m_pPointer[3].m_Flags;
  v3 = this->mpPrintComponent.m_pPointer;
  if ( v3 )
    return (UFG::qMatrix44 *)(&v3[1].m_SimObjIndex + 1);
  else
    return &UFG::qMatrix44::msIdentity;
}

// File Line: 279
// RVA: 0xFF570
float __fastcall UFG::FFieldAvoidablePrint::GetFlowSweep(
        UFG::FFieldAvoidablePrint *this,
        UFG::qVector3 *outFlow,
        UFG::qVector3 *vPosition,
        float fTimeOffset)
{
  UFG::AIInterestComponent *m_pPointer; // rdi
  float z; // xmm10_4
  __int128 y_low; // xmm9
  float x; // xmm8_4
  float v12; // xmm11_4
  float y; // xmm12_4
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
  __m128 vfptr_low; // xmm0
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
  UFG::qMatrix44 *WorldTransform; // rax
  float v53; // xmm0_4
  float v54; // xmm5_4
  float v55; // xmm2_4
  float v56; // xmm4_4
  __m128 z_low; // xmm3
  float v58; // xmm5_4
  float v59; // xmm8_4
  float v60; // xmm2_4
  float v61; // xmm0_4
  float v62; // xmm5_4
  float v63; // xmm4_4
  __m128 v64; // xmm2
  float v65; // xmm1_4
  UFG::HermiteCurve *mpPathCurve; // rcx
  float v67; // xmm0_4
  __m128 v68; // xmm9
  __m128 x_low; // xmm2
  float v70; // xmm1_4
  float v71; // xmm8_4
  float v72; // xmm5_4
  float v73; // xmm4_4
  __m128 v74; // xmm10
  float v75; // xmm11_4
  __m128 v76; // xmm2
  float v77; // xmm1_4
  float v78; // xmm4_4
  float v79; // xmm10_4
  float v80; // xmm11_4
  float v81; // xmm13_4
  __m128 v82; // xmm2
  float v83; // xmm14_4
  __m128 v84; // xmm3
  float v85; // xmm1_4
  float v86; // xmm3_4
  float v87; // xmm2_4
  float v88; // xmm13_4
  float v89; // xmm2_4
  float v90; // xmm4_4
  float v91; // xmm0_4
  float v92; // xmm4_4
  float v93; // xmm7_4
  float v94; // xmm2_4
  UFG::qVector3 target_point; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-98h] BYREF
  UFG::qVector3 closest_point; // [rsp+60h] [rbp-88h] BYREF
  float v99; // [rsp+118h] [rbp+30h]
  float t; // [rsp+130h] [rbp+48h]
  float *v101; // [rsp+138h] [rbp+50h]

  m_pPointer = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
  z = UFG::qVector3::msZero.z;
  y_low = LODWORD(UFG::qVector3::msZero.y);
  x = UFG::qVector3::msZero.x;
  if ( m_pPointer )
  {
    UFG::AIInterestComponent::GetCenter(m_pPointer, &result, 0.0);
    v12 = result.z;
    y = result.y;
    v14 = result.x;
    fTimeOffset = t;
  }
  else
  {
    v14 = UFG::qVector3::msZero.x;
    y = UFG::qVector3::msZero.y;
    v12 = UFG::qVector3::msZero.z;
  }
  if ( m_pPointer )
  {
    UFG::AIInterestComponent::GetCenter(m_pPointer, &target_point, fTimeOffset);
    z = target_point.z;
    y_low = LODWORD(target_point.y);
    x = target_point.x;
  }
  else
  {
    target_point.x = x;
    LODWORD(target_point.y) = y_low;
    target_point.z = z;
  }
  v15 = *(float *)&FLOAT_1_0;
  v16 = x - v14;
  *(float *)&y_low = *(float *)&y_low - y;
  v17 = (__m128)y_low;
  v18 = z - v12;
  v17.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v16 * v16)) + (float)(v18 * v18);
  v19 = _mm_sqrt_ps(v17).m128_f32[0];
  if ( v19 <= 0.001 )
  {
    v24 = v14;
    v25 = y;
    v26 = v12;
  }
  else
  {
    v20 = v16 * (float)(1.0 / v19);
    v21 = *(float *)&y_low * (float)(1.0 / v19);
    v22 = v18 * (float)(1.0 / v19);
    v23 = (float)((float)((float)(vPosition->y - y) * v21) + (float)((float)(vPosition->x - v14) * v20))
        + (float)((float)(vPosition->z - v12) * v22);
    v24 = (float)(v20 * v23) + v14;
    v25 = (float)(v21 * v23) + y;
    v26 = (float)(v22 * v23) + v12;
  }
  v28 = LODWORD(vPosition->y);
  v27 = vPosition->x - v24;
  *(float *)&v28 = *(float *)&v28 - v25;
  v29 = vPosition->z - v26;
  v30 = (__m128)v28;
  outFlow->x = v27;
  LODWORD(outFlow->y) = v28;
  outFlow->z = v29;
  v30.m128_f32[0] = (float)((float)(*(float *)&v28 * *(float *)&v28) + (float)(v27 * v27)) + (float)(v29 * v29);
  v31 = this->mpInterest.m_pPointer;
  vfptr_low = (__m128)LODWORD(v31[3].vfptr);
  v33 = _mm_sqrt_ps(v30).m128_f32[0];
  v34 = *((float *)&v31[2].m_BoundComponentHandles.mNode.mNext + 1)
      - *(float *)&v31[2].m_BoundComponentHandles.mNode.mPrev;
  vfptr_low.m128_f32[0] = (float)((float)(vfptr_low.m128_f32[0]
                                        - *((float *)&v31[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                * (float)(vfptr_low.m128_f32[0]
                                        - *((float *)&v31[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                        + (float)(v34 * v34);
  v35 = (float)((float)(_mm_sqrt_ps(vfptr_low).m128_f32[0] * 0.5) + this->mParams.RadiusAdditive)
      * *(float *)&this->mpParentField.m_pPointer[2].m_pSimObject;
  v36 = v33 / v35;
  if ( (float)(v33 / v35) <= 0.0 )
  {
    v36 = 0.0;
  }
  else if ( v36 >= 1.0 )
  {
    v36 = *(float *)&FLOAT_1_0;
  }
  v99 = 1.0 - (float)(v36 * 0.69999999);
  if ( v33 <= 0.0 || v33 > v35 )
    return 0.0;
  v37 = v27 * (float)(1.0 / v33);
  v38 = *(float *)&v28 * (float)(1.0 / v33);
  v39 = v29 * (float)(1.0 / v33);
  outFlow->x = v37;
  outFlow->y = v38;
  outFlow->z = v39;
  if ( v101 )
  {
    v40 = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
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
    v44 = v43 - *v101;
    v42.m128_f32[0] = v42.m128_f32[0] - v101[1];
    v45 = v41 - v101[2];
    v46 = v42;
    v46.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v44 * v44)) + (float)(v45 * v45);
    v47 = v46.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v46).m128_f32[0];
    v48 = v44 * v47;
    v49 = v42.m128_f32[0] * v47;
    v50 = v45 * v47;
    v51 = (float)((float)(v38 * v49) + (float)(v37 * v48)) + (float)(v39 * v50);
    if ( v51 < this->mParams.SidestepMinDP )
    {
      WorldTransform = UFG::FFieldAvoidablePrint::GetWorldTransform(this);
      v53 = WorldTransform->v2.y;
      v54 = WorldTransform->v2.x;
      z_low = (__m128)LODWORD(WorldTransform->v2.z);
      v55 = z_low.m128_f32[0] * v48;
      v56 = (float)(v53 * v48) - (float)(v54 * v49);
      z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v49) - (float)(v53 * v50);
      v58 = (float)(v54 * v50) - v55;
      v59 = (float)(v51 - this->mParams.SidestepMinDP)
          / (float)(this->mParams.SidestepMaxDP - this->mParams.SidestepMinDP);
      if ( v59 <= 0.0 )
      {
        v59 = 0.0;
      }
      else if ( v59 >= 1.0 )
      {
        v59 = *(float *)&FLOAT_1_0;
      }
      v60 = (float)((float)(v38 * v58) + (float)(v37 * z_low.m128_f32[0])) + (float)(v39 * v56);
      if ( v60 <= 0.0 )
      {
        if ( v60 >= 0.0 )
          v61 = 0.0;
        else
          v61 = FLOAT_N1_0;
      }
      else
      {
        v61 = *(float *)&FLOAT_1_0;
      }
      z_low.m128_f32[0] = (float)((float)((float)(z_low.m128_f32[0] * v61) - v37) * v59) + v37;
      v62 = (float)((float)((float)(v58 * v61) - v38) * v59) + v38;
      v63 = (float)((float)((float)(v56 * v61) - v39) * v59) + v39;
      v64 = z_low;
      v64.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v62 * v62))
                      + (float)(v63 * v63);
      if ( v64.m128_f32[0] == 0.0 )
        v65 = 0.0;
      else
        v65 = 1.0 / _mm_sqrt_ps(v64).m128_f32[0];
      outFlow->x = z_low.m128_f32[0] * v65;
      outFlow->z = v65 * v63;
      outFlow->y = v65 * v62;
    }
  }
  mpPathCurve = this->mpPathCurve;
  if ( mpPathCurve && mpPathCurve->mNumControlPoints )
  {
    v67 = UFG::HermiteCurve::ClosestPointEx(
            mpPathCurve,
            &target_point,
            &closest_point,
            -1.234,
            -1.234,
            -1.0,
            -1.234,
            -1.234);
    UFG::HermiteCurve::GetTangent(this->mpPathCurve, v67, &result);
    v68 = (__m128)LODWORD(result.z);
    x_low = (__m128)LODWORD(result.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y))
                      + (float)(v68.m128_f32[0] * v68.m128_f32[0]);
    if ( x_low.m128_f32[0] == 0.0 )
      v70 = 0.0;
    else
      v70 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
    v71 = result.y * v70;
    v68.m128_f32[0] = result.z * v70;
    v72 = result.x * v70;
    v74 = v68;
    v73 = (float)((float)(result.y * v70) * UFG::qVector3::msDirUp.z)
        - (float)((float)(result.z * v70) * UFG::qVector3::msDirUp.y);
    v74.m128_f32[0] = (float)((float)(result.z * v70) * UFG::qVector3::msDirUp.x)
                    - (float)((float)(result.x * v70) * UFG::qVector3::msDirUp.z);
    v76 = v74;
    v75 = (float)((float)(result.x * v70) * UFG::qVector3::msDirUp.y)
        - (float)((float)(result.y * v70) * UFG::qVector3::msDirUp.x);
    v76.m128_f32[0] = (float)((float)(v74.m128_f32[0] * v74.m128_f32[0]) + (float)(v73 * v73)) + (float)(v75 * v75);
    if ( v76.m128_f32[0] == 0.0 )
      v77 = 0.0;
    else
      v77 = 1.0 / _mm_sqrt_ps(v76).m128_f32[0];
    v82 = (__m128)LODWORD(closest_point.y);
    v78 = v73 * v77;
    v79 = v74.m128_f32[0] * v77;
    v80 = v75 * v77;
    v81 = closest_point.x - target_point.x;
    v82.m128_f32[0] = closest_point.y - target_point.y;
    v83 = closest_point.z - target_point.z;
    v84 = v82;
    v84.m128_f32[0] = (float)((float)(v82.m128_f32[0] * v82.m128_f32[0]) + (float)(v81 * v81)) + (float)(v83 * v83);
    if ( v84.m128_f32[0] == 0.0 )
      v85 = 0.0;
    else
      v85 = 1.0 / _mm_sqrt_ps(v84).m128_f32[0];
    v86 = outFlow->y;
    v87 = (float)((float)(v82.m128_f32[0] * v85) * v79) + (float)((float)(v81 * v85) * v78);
    v88 = outFlow->z;
    v89 = v87 + (float)((float)(v83 * v85) * v80);
    v90 = (float)((float)(v78 * outFlow->x) + (float)(v79 * v86)) + (float)(v80 * v88);
    if ( v90 <= 0.0 )
    {
      if ( v90 >= 0.0 )
        v91 = 0.0;
      else
        v91 = FLOAT_N1_0;
    }
    else
    {
      v91 = *(float *)&FLOAT_1_0;
    }
    if ( v89 <= 0.0 )
    {
      if ( v89 >= 0.0 )
        v15 = 0.0;
      else
        v15 = FLOAT_N1_0;
    }
    if ( v91 != v15 )
    {
      outFlow->x = outFlow->x * -1.0;
      outFlow->y = v86 * -1.0;
      outFlow->z = v88 * -1.0;
    }
    v92 = outFlow->y;
    v93 = outFlow->z;
    v94 = (float)((float)(v72 * outFlow->x) + (float)(v71 * v92)) + (float)(v68.m128_f32[0] * v93);
    if ( v94 < 0.0 )
    {
      outFlow->x = outFlow->x - (float)((float)(v72 * v94) * 1.5);
      outFlow->y = v92 - (float)((float)(v71 * v94) * 1.5);
      outFlow->z = v93 - (float)((float)(v68.m128_f32[0] * v94) * 1.5);
    }
  }
  return v99 * this->m_fStrength;
}

// File Line: 377
// RVA: 0xFE830
float __fastcall UFG::FFieldAvoidablePrint::GetFlowFlashlight(
        UFG::FFieldAvoidablePrint *this,
        UFG::qVector3 *outFlow,
        UFG::qVector3 *vPosition,
        float fTimeOffset,
        UFG::qVector3 *optEyePosition,
        UFG::qVector3 *optEyeVelocity)
{
  UFG::AIInterestComponent *m_pPointer; // rcx
  float z; // xmm9_4
  __int128 y_low; // xmm5
  float x; // xmm8_4
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
  __m128 v30; // xmm3
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm15_4
  float v35; // xmm1_4
  float y; // xmm0_4
  float v37; // xmm15_4
  float v38; // xmm4_4
  float v39; // xmm10_4
  float v40; // xmm3_4
  int v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm5_4
  float v44; // xmm4_4
  float v45; // xmm9_4
  float v46; // xmm2_4
  float v47; // xmm8_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  UFG::SimComponent *v50; // rax
  __m128 vfptr_low; // xmm0
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  float v55; // xmm9_4
  float v56; // xmm8_4
  float FlashlightScoreMax; // xmm0_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm8_4
  UFG::HermiteCurve *mpPathCurve; // rcx
  float v62; // xmm8_4
  float v63; // xmm0_4
  __m128 z_low; // xmm10
  __m128 x_low; // xmm2
  float v66; // xmm1_4
  float v67; // xmm9_4
  float v68; // xmm5_4
  float v69; // xmm4_4
  __m128 v70; // xmm11
  float v71; // xmm12_4
  __m128 v72; // xmm2
  float v73; // xmm1_4
  float v74; // xmm4_4
  float v75; // xmm11_4
  float v76; // xmm12_4
  float v77; // xmm14_4
  __m128 fMinDistance_low; // xmm2
  float v79; // xmm15_4
  __m128 v80; // xmm3
  float v81; // xmm1_4
  float v82; // xmm3_4
  float v83; // xmm2_4
  float v84; // xmm14_4
  float v85; // xmm2_4
  float v86; // xmm4_4
  float v87; // xmm0_4
  float v88; // xmm4_4
  float v89; // xmm7_4
  float v90; // xmm2_4
  UFG::qVector3 result; // [rsp+40h] [rbp-B8h] BYREF
  UFG::qVector3 vDirection; // [rsp+50h] [rbp-A8h] BYREF
  UFG::qVector3 vPositiona; // [rsp+60h] [rbp-98h] BYREF
  UFG::FlashlightParams params; // [rsp+70h] [rbp-88h] BYREF
  float *v96; // [rsp+158h] [rbp+60h]

  m_pPointer = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
  if ( m_pPointer )
  {
    UFG::AIInterestComponent::GetCenter(m_pPointer, &result, fTimeOffset);
    z = result.z;
    y_low = LODWORD(result.y);
    x = result.x;
  }
  else
  {
    x = UFG::qVector3::msZero.x;
    y_low = LODWORD(UFG::qVector3::msZero.y);
    z = UFG::qVector3::msZero.z;
    result = UFG::qVector3::msZero;
  }
  if ( !v96 )
    return 0.0;
  v13 = *(float *)&FLOAT_1_0;
  v14 = v96[1];
  v15 = *v96;
  *(float *)&y_low = *(float *)&y_low - v14;
  v16 = x - *v96;
  vPositiona.x = *v96;
  v17 = (__m128)y_low;
  v18 = v96[2];
  vPositiona.y = v14;
  vDirection.x = v16;
  v19 = z - v18;
  vPositiona.z = v18;
  v17.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v16 * v16)) + (float)(v19 * v19);
  LODWORD(vDirection.y) = y_low;
  vDirection.z = v19;
  v20 = _mm_sqrt_ps(v17).m128_f32[0];
  v21 = FLOAT_0_001;
  if ( v20 <= 0.001 )
  {
    v23 = vPosition->x;
    v30 = (__m128)LODWORD(vPosition->y);
    v24 = vPosition->z;
    v35 = vPosition->x;
    y = vPosition->y;
    v37 = v24;
  }
  else
  {
    v22 = FLOAT_10_0;
    v16 = v16 * (float)(1.0 / v20);
    *(float *)&y_low = *(float *)&y_low * (float)(1.0 / v20);
    v19 = v19 * (float)(1.0 / v20);
    vDirection.x = v16;
    LODWORD(vDirection.y) = y_low;
    vDirection.z = v19;
    if ( v20 >= 10.0 )
      v22 = v20;
    v23 = vPosition->x;
    v24 = vPosition->z;
    v25 = v22 - v20;
    v26 = v15 - (float)(v16 * v25);
    v27 = v14 - (float)(*(float *)&y_low * v25);
    v28 = v18 - (float)(v19 * v25);
    v20 = v20 + v25;
    v29 = (float)(vPosition->x - v26) * v16;
    v30 = (__m128)LODWORD(vPosition->y);
    vPositiona.x = v26;
    vPositiona.y = v27;
    vPositiona.z = v28;
    v31 = (float)((float)((float)(v30.m128_f32[0] - v27) * *(float *)&y_low) + v29) + (float)((float)(v24 - v28) * v19);
    v32 = v16 * v31;
    v33 = *(float *)&y_low * v31;
    v34 = v19 * v31;
    v21 = FLOAT_0_001;
    v35 = v32 + v26;
    y = v33 + v27;
    v37 = v34 + v28;
  }
  v30.m128_f32[0] = v30.m128_f32[0] - y;
  v38 = v23 - v35;
  v39 = v24 - v37;
  LODWORD(outFlow->y) = v30.m128_i32[0];
  outFlow->x = v38;
  outFlow->z = v39;
  v30.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v38 * v38)) + (float)(v39 * v39);
  v40 = _mm_sqrt_ps(v30).m128_f32[0];
  *(float *)&v41 = v40;
  if ( v40 < 0.0 )
    v41 = LODWORD(v40) ^ _xmm[0];
  if ( *(float *)&v41 < v21 )
  {
    v42 = *(float *)&y_low;
    v43 = *(float *)&y_low * UFG::qVector3::msDirUp.x;
    v40 = *(float *)&FLOAT_1_0;
    v44 = v19 * UFG::qVector3::msDirUp.y;
    v45 = v19 * UFG::qVector3::msDirUp.x;
    v46 = v16 * UFG::qVector3::msDirUp.z;
    v47 = v16 * UFG::qVector3::msDirUp.y;
    outFlow->x = v44 - (float)(v42 * UFG::qVector3::msDirUp.z);
    outFlow->y = v46 - v45;
    outFlow->z = v43 - v47;
  }
  v48 = (float)(1.0 / v40) * outFlow->x;
  v49 = (float)(1.0 / v40) * outFlow->y;
  outFlow->z = (float)(1.0 / v40) * outFlow->z;
  outFlow->x = v48;
  outFlow->y = v49;
  v50 = this->mpInterest.m_pPointer;
  vfptr_low = (__m128)LODWORD(v50[3].vfptr);
  v52 = *((float *)&v50[2].m_BoundComponentHandles.mNode.mNext + 1)
      - *(float *)&v50[2].m_BoundComponentHandles.mNode.mPrev;
  vfptr_low.m128_f32[0] = (float)((float)(vfptr_low.m128_f32[0]
                                        - *((float *)&v50[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                * (float)(vfptr_low.m128_f32[0]
                                        - *((float *)&v50[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                        + (float)(v52 * v52);
  v53 = (float)((float)(_mm_sqrt_ps(vfptr_low).m128_f32[0] * 0.5) + this->mParams.RadiusAdditive)
      * *(float *)&this->mpParentField.m_pPointer[2].m_pSimObject;
  v54 = v40 / v53;
  if ( v54 <= 0.0 )
  {
    v54 = 0.0;
  }
  else if ( v54 >= 1.0 )
  {
    v54 = *(float *)&FLOAT_1_0;
  }
  params.fMinDistance = this->mParams.FLMinDist;
  params.fAngleWeight = 1.0;
  params.fDeadDistance = 0.0;
  params.fMaxDistance = v20;
  v55 = 1.0 - (float)(v54 * 0.5);
  params.fDeadDistance = atan2f(v53, v20);
  v56 = UFG::FlashlightScore(&vPositiona, &vDirection, &params, vPosition);
  if ( v56 <= 0.0 )
    return 0.0;
  FlashlightScoreMax = FLOAT_0_25;
  v58 = outFlow->y;
  v59 = outFlow->z;
  if ( this->mParams.FlashlightScoreMax >= 0.25 )
    FlashlightScoreMax = this->mParams.FlashlightScoreMax;
  v60 = v56 / FlashlightScoreMax;
  if ( v60 <= 0.0 )
  {
    v60 = 0.0;
  }
  else if ( v60 >= 1.0 )
  {
    v60 = *(float *)&FLOAT_1_0;
  }
  outFlow->x = outFlow->x * v55;
  outFlow->y = v58 * v55;
  outFlow->z = v59 * v55;
  mpPathCurve = this->mpPathCurve;
  v62 = v60 * this->m_fStrength;
  if ( mpPathCurve && mpPathCurve->mNumControlPoints )
  {
    v63 = UFG::HermiteCurve::ClosestPointEx(
            mpPathCurve,
            &result,
            (UFG::qVector3 *)&params,
            -1.234,
            -1.234,
            -1.0,
            -1.234,
            -1.234);
    UFG::HermiteCurve::GetTangent(this->mpPathCurve, v63, &vPositiona);
    z_low = (__m128)LODWORD(vPositiona.z);
    x_low = (__m128)LODWORD(vPositiona.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(vPositiona.y * vPositiona.y))
                      + (float)(z_low.m128_f32[0] * z_low.m128_f32[0]);
    if ( x_low.m128_f32[0] == 0.0 )
      v66 = 0.0;
    else
      v66 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
    v67 = vPositiona.y * v66;
    z_low.m128_f32[0] = vPositiona.z * v66;
    v68 = vPositiona.x * v66;
    v70 = z_low;
    v69 = (float)((float)(vPositiona.y * v66) * UFG::qVector3::msDirUp.z)
        - (float)((float)(vPositiona.z * v66) * UFG::qVector3::msDirUp.y);
    v70.m128_f32[0] = (float)((float)(vPositiona.z * v66) * UFG::qVector3::msDirUp.x)
                    - (float)((float)(vPositiona.x * v66) * UFG::qVector3::msDirUp.z);
    v72 = v70;
    v71 = (float)((float)(vPositiona.x * v66) * UFG::qVector3::msDirUp.y)
        - (float)((float)(vPositiona.y * v66) * UFG::qVector3::msDirUp.x);
    v72.m128_f32[0] = (float)((float)(v70.m128_f32[0] * v70.m128_f32[0]) + (float)(v69 * v69)) + (float)(v71 * v71);
    if ( v72.m128_f32[0] == 0.0 )
      v73 = 0.0;
    else
      v73 = 1.0 / _mm_sqrt_ps(v72).m128_f32[0];
    fMinDistance_low = (__m128)LODWORD(params.fMinDistance);
    v74 = v69 * v73;
    v75 = v70.m128_f32[0] * v73;
    v76 = v71 * v73;
    v77 = params.fAngleWeight - result.x;
    fMinDistance_low.m128_f32[0] = params.fMinDistance - result.y;
    v79 = params.fMaxDistance - result.z;
    v80 = fMinDistance_low;
    v80.m128_f32[0] = (float)((float)(fMinDistance_low.m128_f32[0] * fMinDistance_low.m128_f32[0]) + (float)(v77 * v77))
                    + (float)(v79 * v79);
    if ( v80.m128_f32[0] == 0.0 )
      v81 = 0.0;
    else
      v81 = 1.0 / _mm_sqrt_ps(v80).m128_f32[0];
    v82 = outFlow->y;
    v83 = (float)((float)(fMinDistance_low.m128_f32[0] * v81) * v75) + (float)((float)(v77 * v81) * v74);
    v84 = outFlow->z;
    v85 = v83 + (float)((float)(v79 * v81) * v76);
    v86 = (float)((float)(v74 * outFlow->x) + (float)(v75 * v82)) + (float)(v76 * v84);
    if ( v86 <= 0.0 )
    {
      if ( v86 >= 0.0 )
        v87 = 0.0;
      else
        v87 = FLOAT_N1_0;
    }
    else
    {
      v87 = *(float *)&FLOAT_1_0;
    }
    if ( v85 <= 0.0 )
    {
      if ( v85 >= 0.0 )
        v13 = 0.0;
      else
        v13 = FLOAT_N1_0;
    }
    if ( v87 != v13 )
    {
      outFlow->x = outFlow->x * -1.0;
      outFlow->y = v82 * -1.0;
      outFlow->z = v84 * -1.0;
    }
    v88 = outFlow->y;
    v89 = outFlow->z;
    v90 = (float)((float)(v68 * outFlow->x) + (float)(v67 * v88)) + (float)(z_low.m128_f32[0] * v89);
    if ( v90 < 0.0 )
    {
      outFlow->x = outFlow->x - (float)((float)(v68 * v90) * 1.5);
      outFlow->y = v88 - (float)((float)(v67 * v90) * 1.5);
      outFlow->z = v89 - (float)((float)(z_low.m128_f32[0] * v90) * 1.5);
    }
  }
  return v62;
}

// File Line: 476
// RVA: 0xFEFF0
float __fastcall UFG::FFieldAvoidablePrint::GetFlowRegular(
        UFG::FFieldAvoidablePrint *this,
        UFG::qVector3 *outFlow,
        UFG::qVector3 *vPosition,
        float fTimeOffset,
        UFG::qVector3 *optEyePosition,
        UFG::qVector3 *optEyeVelocity)
{
  UFG::AIInterestComponent *m_pPointer; // rcx
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  float v14; // xmm11_4
  float v15; // xmm13_4
  __int128 y_low; // xmm12
  __m128 v17; // xmm2
  UFG::SimComponent *v18; // rax
  __m128 vfptr_low; // xmm0
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
  __m128 m_TypeUID; // xmm9
  float v31; // xmm10_4
  __m128 v32; // xmm2
  float v33; // xmm3_4
  float v34; // xmm8_4
  float v35; // xmm9_4
  float v36; // xmm10_4
  UFG::qMatrix44 *p_m_Flags; // rax
  UFG::SimComponent *v38; // rax
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm1_4
  float v42; // xmm5_4
  float v43; // xmm4_4
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  UFG::AIInterestComponent *v47; // rcx
  float v48; // xmm11_4
  __m128 v49; // xmm10
  float v50; // xmm9_4
  float v51; // xmm9_4
  float v52; // xmm11_4
  __m128 v53; // xmm2
  float v54; // xmm1_4
  __m128 v55; // xmm13
  float v56; // xmm12_4
  float v57; // xmm14_4
  float v58; // xmm9_4
  float v59; // xmm10_4
  float v60; // xmm11_4
  float v61; // xmm8_4
  UFG::qMatrix44 *WorldTransform; // rax
  float v63; // xmm0_4
  float v64; // xmm5_4
  float v65; // xmm4_4
  float v66; // xmm2_4
  float v67; // xmm3_4
  float v68; // xmm4_4
  float v69; // xmm5_4
  float v70; // xmm8_4
  float v71; // xmm2_4
  float v72; // xmm0_4
  float v73; // xmm12_4
  float v74; // xmm14_4
  __m128 v75; // xmm2
  float v76; // xmm6_4
  UFG::qVector3 result; // [rsp+20h] [rbp-B8h] BYREF

  m_pPointer = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
  if ( m_pPointer )
  {
    UFG::AIInterestComponent::GetCenter(m_pPointer, &result, fTimeOffset);
    z = result.z;
    y = result.y;
    x = result.x;
  }
  else
  {
    x = UFG::qVector3::msZero.x;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
  }
  y_low = LODWORD(vPosition->y);
  v14 = vPosition->x - x;
  v15 = vPosition->z - z;
  *(float *)&y_low = *(float *)&y_low - y;
  outFlow->x = v14;
  outFlow->z = v15;
  v17 = (__m128)y_low;
  LODWORD(outFlow->y) = y_low;
  v18 = this->mpInterest.m_pPointer;
  vfptr_low = (__m128)LODWORD(v18[3].vfptr);
  v17.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v14 * v14)) + (float)(v15 * v15);
  v20 = _mm_sqrt_ps(v17).m128_f32[0];
  v21 = *((float *)&v18[2].m_BoundComponentHandles.mNode.mNext + 1)
      - *(float *)&v18[2].m_BoundComponentHandles.mNode.mPrev;
  vfptr_low.m128_f32[0] = (float)((float)(vfptr_low.m128_f32[0]
                                        - *((float *)&v18[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                * (float)(vfptr_low.m128_f32[0]
                                        - *((float *)&v18[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                        + (float)(v21 * v21);
  v22 = (float)((float)(_mm_sqrt_ps(vfptr_low).m128_f32[0] * 0.5) + this->mParams.RadiusAdditive)
      * *(float *)&this->mpParentField.m_pPointer[2].m_pSimObject;
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
  v26 = *(float *)&y_low * (float)(1.0 / v20);
  v27 = v15 * (float)(1.0 / v20);
  outFlow->x = v25;
  outFlow->y = v26;
  outFlow->z = v27;
  v28 = this->mpInterest.m_pPointer;
  v29 = *((float *)&v28[3].m_SafePointerList.mNode.mNext + 1);
  m_TypeUID = (__m128)v28[3].m_TypeUID;
  v31 = *(float *)&v28[3].m_NameUID;
  v32 = m_TypeUID;
  v32.m128_f32[0] = (float)((float)(m_TypeUID.m128_f32[0] * m_TypeUID.m128_f32[0]) + (float)(v29 * v29))
                  + (float)(v31 * v31);
  v33 = _mm_sqrt_ps(v32).m128_f32[0];
  if ( v33 > 1.0 )
  {
    v34 = v29 * (float)(1.0 / v33);
    v35 = m_TypeUID.m128_f32[0] * (float)(1.0 / v33);
    v36 = v31 * (float)(1.0 / v33);
    if ( v28 )
    {
      p_m_Flags = (UFG::qMatrix44 *)&v28[3].m_Flags;
    }
    else
    {
      v38 = this->mpPrintComponent.m_pPointer;
      if ( v38 )
        p_m_Flags = (UFG::qMatrix44 *)(&v38[1].m_SimObjIndex + 1);
      else
        p_m_Flags = &UFG::qMatrix44::msIdentity;
    }
    v39 = p_m_Flags->v2.z;
    v40 = p_m_Flags->v2.x;
    v41 = v40 * v35;
    v42 = (float)(v40 * v36) - (float)(v39 * v34);
    v43 = (float)(v39 * v35) - (float)(p_m_Flags->v2.y * v36);
    v44 = (float)(p_m_Flags->v2.y * v34) - v41;
    v45 = (float)((float)(v42 * v26) + (float)(v43 * v25)) + (float)(v44 * v27);
    if ( v45 <= 0.0 )
    {
      if ( v45 >= 0.0 )
        v46 = 0.0;
      else
        v46 = FLOAT_N1_0;
    }
    else
    {
      v46 = *(float *)&FLOAT_1_0;
    }
    outFlow->x = v43 * v46;
    outFlow->y = v42 * v46;
    outFlow->z = v44 * v46;
  }
  if ( optEyePosition )
  {
    v47 = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
    if ( v47 )
    {
      UFG::AIInterestComponent::GetCenter(v47, &result, fTimeOffset);
      v48 = result.z;
      v49 = (__m128)LODWORD(result.y);
      v50 = result.x;
    }
    else
    {
      v50 = UFG::qVector3::msZero.x;
      v49 = (__m128)LODWORD(UFG::qVector3::msZero.y);
      v48 = UFG::qVector3::msZero.z;
    }
    v51 = v50 - optEyePosition->x;
    v49.m128_f32[0] = v49.m128_f32[0] - optEyePosition->y;
    v52 = v48 - optEyePosition->z;
    v53 = v49;
    v53.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v51 * v51)) + (float)(v52 * v52);
    v54 = v53.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v53).m128_f32[0];
    v55 = (__m128)LODWORD(outFlow->y);
    v56 = outFlow->x;
    v57 = outFlow->z;
    v58 = v51 * v54;
    v59 = v49.m128_f32[0] * v54;
    v60 = v52 * v54;
    v61 = (float)((float)(outFlow->x * v58) + (float)(outFlow->y * v59)) + (float)(v57 * v60);
    if ( v61 < this->mParams.SidestepMinDP )
    {
      WorldTransform = UFG::FFieldAvoidablePrint::GetWorldTransform(this);
      v63 = WorldTransform->v2.y;
      v64 = WorldTransform->v2.x;
      v65 = WorldTransform->v2.z;
      v66 = v65 * v58;
      v67 = (float)(v63 * v58) - (float)(v64 * v59);
      v68 = (float)(v65 * v59) - (float)(v63 * v60);
      v69 = (float)(v64 * v60) - v66;
      v70 = (float)(v61 - this->mParams.SidestepMinDP)
          / (float)(this->mParams.SidestepMaxDP - this->mParams.SidestepMinDP);
      if ( v70 <= 0.0 )
      {
        v70 = 0.0;
      }
      else if ( v70 >= 1.0 )
      {
        v70 = *(float *)&FLOAT_1_0;
      }
      v71 = (float)((float)(v56 * v68) + (float)(v55.m128_f32[0] * v69)) + (float)(v57 * v67);
      if ( v71 <= 0.0 )
      {
        if ( v71 >= 0.0 )
          v72 = 0.0;
        else
          v72 = FLOAT_N1_0;
      }
      else
      {
        v72 = *(float *)&FLOAT_1_0;
      }
      v73 = v56 + (float)((float)((float)(v68 * v72) - v56) * v70);
      v55.m128_f32[0] = v55.m128_f32[0] + (float)((float)((float)(v69 * v72) - v55.m128_f32[0]) * v70);
      v74 = v57 + (float)((float)((float)(v67 * v72) - v57) * v70);
      v75 = v55;
      v75.m128_f32[0] = (float)((float)(v55.m128_f32[0] * v55.m128_f32[0]) + (float)(v73 * v73)) + (float)(v74 * v74);
      if ( v75.m128_f32[0] == 0.0 )
        v76 = 0.0;
      else
        v76 = 1.0 / _mm_sqrt_ps(v75).m128_f32[0];
      outFlow->x = v73 * v76;
      outFlow->y = v55.m128_f32[0] * v76;
      outFlow->z = v74 * v76;
    }
  }
  return v24 * this->m_fStrength;
}      outFlow->y = v55.m128_f32[0] * v76;
      outFlow->z = v74 * v76;
    }
  }
  return v24 * this->m_fStrength;
}

// File Line: 525
// RVA: 0x100A10
void __fastcall UFG::FFieldAvoidablePrint::OnDebugDraw(
        UFG::FFieldAvoidablePrint *this,
        float fDeltaT,
        Render::View *pView)
{
  UFG::SimComponent *m_pPointer; // rcx
  char m_Enabled; // al
  UFG::SimComponent *v7; // rdx
  int m_TypeUID; // xmm2_4
  int mNext_high; // xmm1_4
  UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *vfptr; // rax
  int AvoidMethod; // eax
  float *v12; // rsi
  UFG::SimComponent *v13; // rdi
  float v14; // xmm6_4
  int v15; // eax
  __m128 v16; // xmm0
  float v17; // xmm7_4
  float v18; // xmm6_4
  Render::DebugDrawContext *Context; // rax
  float z; // xmm5_4
  __int128 y_low; // xmm4
  float x; // xmm3_4
  float *v23; // rax
  float v24; // xmm7_4
  float v25; // xmm8_4
  float v26; // xmm9_4
  float v27; // xmm3_4
  float v28; // xmm5_4
  __m128 v29; // xmm2
  float v30; // xmm6_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  __m128 vfptr_low; // xmm2
  float v37; // xmm3_4
  float v38; // xmm3_4
  float FLMinAngle; // xmm0_4
  float v40; // xmm7_4
  float y; // xmm8_4
  float v42; // xmm9_4
  float v43; // xmm10_4
  float v44; // xmm11_4
  float v45; // xmm12_4
  __m128 v46; // xmm0
  float v47; // xmm6_4
  Render::DebugDrawContext *v48; // rbx
  UFG::qVector3 v49; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-C0h] BYREF
  int v51[4]; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qColour v52; // [rsp+60h] [rbp-A0h] BYREF
  float v53; // [rsp+70h] [rbp-90h]
  float v54; // [rsp+74h] [rbp-8Ch]
  UFG::FlashlightParams v55; // [rsp+80h] [rbp-80h] BYREF

  if ( this->mpInterest.m_pPointer )
  {
    m_pPointer = this->mpParentField.m_pPointer;
    if ( m_pPointer )
    {
      m_Enabled = this->m_Enabled;
      if ( m_Enabled )
      {
        v7 = this->mpPrintComponent.m_pPointer;
        if ( v7 )
          m_Enabled = v7[1].m_Flags;
        if ( m_Enabled )
        {
          m_TypeUID = m_pPointer[2].m_TypeUID;
          mNext_high = HIDWORD(m_pPointer[2].m_SafePointerList.mNode.mNext);
          vfptr = this->vfptr;
          v51[0] = (int)m_pPointer[2].m_SafePointerList.mNode.mNext;
          v51[1] = mNext_high;
          v51[2] = m_TypeUID;
          if ( vfptr[3].__vecDelDtor(this, (unsigned int)v51) )
          {
            AvoidMethod = UFG::FFieldAvoidablePrint::GetAvoidMethod(this);
            v12 = (float *)this->mpParentField.m_pPointer;
            v13 = this->mpInterest.m_pPointer;
            v14 = v12[35];
            v15 = AvoidMethod - 2;
            if ( v15 )
            {
              if ( v15 == 1 )
              {
                if ( v13 )
                {
                  UFG::AIInterestComponent::GetCenter(
                    (UFG::AIInterestComponent *)this->mpInterest.m_pPointer,
                    &result,
                    v12[35]);
                  z = result.z;
                  y_low = LODWORD(result.y);
                  x = result.x;
                }
                else
                {
                  x = UFG::qVector3::msZero.x;
                  y_low = LODWORD(UFG::qVector3::msZero.y);
                  z = UFG::qVector3::msZero.z;
                }
                v23 = v12 + 36;
                if ( v12 != (float *)-144i64 )
                {
                  v24 = *v23;
                  v25 = v12[37];
                  v26 = v12[38];
                  v27 = x - *v23;
                  *(float *)&y_low = *(float *)&y_low - v25;
                  v28 = z - v26;
                  v29 = (__m128)y_low;
                  result.x = *v23;
                  v29.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v27 * v27))
                                  + (float)(v28 * v28);
                  result.y = v25;
                  result.z = v26;
                  v30 = _mm_sqrt_ps(v29).m128_f32[0];
                  v49.x = v27;
                  LODWORD(v49.y) = y_low;
                  v49.z = v28;
                  if ( v30 > 0.001 )
                  {
                    v31 = v27 * (float)(1.0 / v30);
                    v32 = *(float *)&y_low * (float)(1.0 / v30);
                    v33 = v28 * (float)(1.0 / v30);
                    v34 = FLOAT_10_0;
                    v49.x = v31;
                    v49.y = v32;
                    v49.z = v33;
                    if ( v30 >= 10.0 )
                      v34 = v30;
                    v35 = v34 - v30;
                    v30 = v30 + v35;
                    result.x = v24 - (float)(v31 * v35);
                    result.y = v25 - (float)(v32 * v35);
                    result.z = v26 - (float)(v33 * v35);
                  }
                  vfptr_low = (__m128)LODWORD(v13[3].vfptr);
                  v37 = *((float *)&v13[2].m_BoundComponentHandles.mNode.mNext + 1);
                  v55.fAngleWeight = 1.0;
                  v55.fDeadDistance = 0.0;
                  vfptr_low.m128_f32[0] = vfptr_low.m128_f32[0]
                                        - *((float *)&v13[2].m_BoundComponentHandles.mNode.mPrev + 1);
                  v38 = v37 - *(float *)&v13[2].m_BoundComponentHandles.mNode.mPrev;
                  v52.r = 1.0;
                  *(_QWORD *)&v52.g = LODWORD(FLOAT_0_2);
                  vfptr_low.m128_f32[0] = (float)(vfptr_low.m128_f32[0] * vfptr_low.m128_f32[0]) + (float)(v38 * v38);
                  v55.fMinDistance = this->mParams.FLMinDist;
                  FLMinAngle = this->mParams.FLMinAngle;
                  v52.a = UFG::gTempFlowprintAlpha;
                  v55.fMinRads = FLMinAngle;
                  v55.fMaxDistance = v30;
                  v55.fMaxRads = atan2f(
                                   (float)((float)(_mm_sqrt_ps(vfptr_low).m128_f32[0] * 0.5)
                                         + this->mParams.RadiusAdditive)
                                 * v12[42],
                                   v30)
                               * 1.2;
                  UFG::FlashlightDisplay2(&result, &v49, &v55, pView, &v52);
                }
              }
              else
              {
                if ( v13 )
                  UFG::AIInterestComponent::GetCenter(
                    (UFG::AIInterestComponent *)this->mpInterest.m_pPointer,
                    &result,
                    v12[35]);
                else
                  result = UFG::qVector3::msZero;
                v16 = (__m128)LODWORD(v13[3].vfptr);
                v17 = v12[42];
                v16.m128_f32[0] = (float)((float)(v16.m128_f32[0]
                                                - *((float *)&v13[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                        * (float)(v16.m128_f32[0]
                                                - *((float *)&v13[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                                + (float)((float)(*((float *)&v13[2].m_BoundComponentHandles.mNode.mNext + 1)
                                                - *(float *)&v13[2].m_BoundComponentHandles.mNode.mPrev)
                                        * (float)(*((float *)&v13[2].m_BoundComponentHandles.mNode.mNext + 1)
                                                - *(float *)&v13[2].m_BoundComponentHandles.mNode.mPrev));
                v18 = (float)(_mm_sqrt_ps(v16).m128_f32[0] * 0.5) + this->mParams.RadiusAdditive;
                Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                        Render::DebugDrawManager::mInstance,
                                                        2u);
                Render::DebugDrawContext::DrawSphere(
                  Context,
                  &result,
                  v17 * v18,
                  &UFG::qColour::White,
                  &UFG::qMatrix44::msIdentity,
                  0i64);
              }
            }
            else
            {
              v40 = UFG::qVector3::msZero.z;
              y = UFG::qVector3::msZero.y;
              v42 = UFG::qVector3::msZero.x;
              if ( v13 )
              {
                UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)v13, &result, 0.0);
                v43 = result.z;
                v44 = result.y;
                v45 = result.x;
              }
              else
              {
                v45 = UFG::qVector3::msZero.x;
                v44 = UFG::qVector3::msZero.y;
                v43 = UFG::qVector3::msZero.z;
              }
              if ( v13 )
              {
                UFG::AIInterestComponent::GetCenter((UFG::AIInterestComponent *)v13, &result, v14);
                v40 = result.z;
                y = result.y;
                v42 = result.x;
              }
              v52.r = v45;
              v52.g = v44;
              v52.b = v43;
              v52.a = v42;
              v53 = y;
              v54 = v40;
              v46 = (__m128)LODWORD(v13[3].vfptr);
              v46.m128_f32[0] = (float)((float)(v46.m128_f32[0]
                                              - *((float *)&v13[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                      * (float)(v46.m128_f32[0]
                                              - *((float *)&v13[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                              + (float)((float)(*((float *)&v13[2].m_BoundComponentHandles.mNode.mNext + 1)
                                              - *(float *)&v13[2].m_BoundComponentHandles.mNode.mPrev)
                                      * (float)(*((float *)&v13[2].m_BoundComponentHandles.mNode.mNext + 1)
                                              - *(float *)&v13[2].m_BoundComponentHandles.mNode.mPrev));
              v47 = (float)((float)(_mm_sqrt_ps(v46).m128_f32[0] * 0.5) + this->mParams.RadiusAdditive) * v12[42];
              v48 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                  Render::DebugDrawManager::mInstance,
                                                  2u);
              Render::DebugDrawContext::DrawLineStrip(
                v48,
                (UFG::qVector3 *)&v52,
                2,
                &UFG::qColour::White,
                &UFG::qMatrix44::msIdentity,
                0i64);
              Render::DebugDrawContext::DrawSphere(
                v48,
                (UFG::qVector3 *)&v52,
                v47,
                &UFG::qColour::White,
                &UFG::qMatrix44::msIdentity,
                0i64);
              Render::DebugDrawContext::DrawSphere(
                v48,
                (UFG::qVector3 *)&v52.a,
                v47,
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
UFG::qVector3 *__fastcall UFG::FFieldAttractor::GetPosition(
        UFG::FFieldAttractor *this,
        UFG::qVector3 *result,
        float fTimeOffset)
{
  float *m_pPointer; // rax
  float y; // xmm3_4
  float z; // xmm4_4
  float x; // xmm6_4
  UFG::AIInterestComponent *v8; // rcx
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm8_4
  float v14; // xmm6_4
  UFG::qVector3 *Center; // rax
  float v16; // xmm8_4
  float v17; // xmm6_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-48h] BYREF

  m_pPointer = (float *)this->mpPrintComponent.m_pPointer;
  y = this->mParams.Offset.y;
  z = this->mParams.Offset.z;
  x = this->mParams.Offset.x;
  v8 = (UFG::AIInterestComponent *)this->mpInterest.m_pPointer;
  v9 = x * m_pPointer[26];
  v10 = (float)((float)(y * m_pPointer[29]) + (float)(x * m_pPointer[25])) + (float)(z * m_pPointer[33]);
  v11 = y * m_pPointer[30];
  v12 = (float)(x * m_pPointer[27]) + (float)(y * m_pPointer[31]);
  result->x = v10;
  v13 = (float)(v9 + v11) + (float)(z * m_pPointer[34]);
  v14 = v12 + (float)(z * m_pPointer[35]);
  result->y = v13;
  result->z = v14;
  if ( v8 )
  {
    Center = UFG::AIInterestComponent::GetCenter(v8, &resulta, fTimeOffset);
    v16 = v13 + Center->y;
    v17 = v14 + Center->z;
    result->x = v10 + Center->x;
    result->y = v16;
    result->z = v17;
  }
  return result;
}

// File Line: 628
// RVA: 0xFDA10
float __fastcall UFG::FFieldAttractor::GetFlow(
        UFG::FFieldAttractor *this,
        UFG::qVector3 *outFlow,
        UFG::qVector3 *vPosition,
        float fTimeOffset,
        UFG::qVector3 *optEyePosition,
        UFG::qVector3 *optEyeVelocity)
{
  float m_fStrength; // xmm7_4
  float v11; // xmm3_4
  __int128 y_low; // xmm4
  __m128 v13; // xmm2
  float v14; // xmm5_4
  UFG::SimComponent *m_pPointer; // rax
  __m128 vfptr_low; // xmm0
  float v17; // xmm9_4
  float v18; // xmm6_4
  float v19; // xmm6_4
  float Orientation; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float FLMaxDist; // xmm1_4
  float FLMinAngle; // xmm0_4
  float FLMaxAngle; // xmm1_4
  float v26; // xmm10_4
  float z; // xmm13_4
  float y; // xmm14_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm9_4
  float v33; // xmm11_4
  float v34; // xmm12_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  __m128 v37; // xmm2
  float v38; // xmm3_4
  __m128 v39; // xmm4
  float v40; // xmm2_4
  __m128 v41; // xmm5
  float v42; // xmm8_4
  float v43; // xmm3_4
  float v44; // xmm4_4
  float v45; // xmm2_4
  UFG::qVector3 result; // [rsp+20h] [rbp-E8h] BYREF
  UFG::qVector3 vOutDir; // [rsp+30h] [rbp-D8h] BYREF
  UFG::FlashlightParams params; // [rsp+40h] [rbp-C8h] BYREF

  if ( !this->mpInterest.m_pPointer )
    return 0.0;
  m_fStrength = 0.0;
  UFG::FFieldAttractor::GetPosition(this, &result, fTimeOffset);
  y_low = LODWORD(result.y);
  v11 = result.x - vPosition->x;
  *(float *)&y_low = result.y - vPosition->y;
  v13 = (__m128)y_low;
  v14 = result.z - vPosition->z;
  outFlow->x = v11;
  LODWORD(outFlow->y) = y_low;
  outFlow->z = v14;
  m_pPointer = this->mpInterest.m_pPointer;
  vfptr_low = (__m128)LODWORD(m_pPointer[3].vfptr);
  v13.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v11 * v11)) + (float)(v14 * v14);
  v17 = _mm_sqrt_ps(v13).m128_f32[0];
  vfptr_low.m128_f32[0] = (float)((float)(vfptr_low.m128_f32[0]
                                        - *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                * (float)(vfptr_low.m128_f32[0]
                                        - *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                        + (float)((float)(*((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext + 1)
                                        - *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev)
                                * (float)(*((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext + 1)
                                        - *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev));
  v18 = v17 / (float)((float)(_mm_sqrt_ps(vfptr_low).m128_f32[0] * 0.5) + this->mParams.RadiusAdditive);
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
    outFlow->z = (float)(1.0 / v17) * v14;
    outFlow->x = (float)(1.0 / v17) * v11;
    outFlow->y = (float)(1.0 / v17) * *(float *)&y_low;
    UFG::FFieldAttractor::CalcFlashlightDirection(this, &vOutDir);
    Orientation = this->mParams.Orientation;
    if ( Orientation == 1.0 || Orientation == 0.0 )
    {
      FLMaxDist = this->mParams.FLMaxDist;
      params.fMinDistance = this->mParams.FLMinDist;
      FLMinAngle = this->mParams.FLMinAngle;
      params.fMaxDistance = FLMaxDist;
      params.fAngleWeight = 0.5;
      params.fDeadDistance = 0.0;
      FLMaxAngle = this->mParams.FLMaxAngle;
      params.fMinRads = FLMinAngle;
      params.fMaxRads = FLMaxAngle;
      v26 = UFG::FlashlightScore(&result, &vOutDir, &params, vPosition);
      if ( v26 > 0.0 )
      {
        z = outFlow->z;
        y = outFlow->y;
        v29 = (float)(z * vOutDir.y) - (float)(y * vOutDir.z);
        v30 = (float)(y * vOutDir.x) - (float)(outFlow->x * vOutDir.y);
        v31 = (float)(outFlow->x * vOutDir.z) - (float)(z * vOutDir.x);
        v32 = (float)(v31 * vOutDir.x) - (float)(v29 * vOutDir.y);
        v33 = (float)(v30 * vOutDir.y) - (float)(v31 * vOutDir.z);
        v34 = (float)(v29 * vOutDir.z) - (float)(v30 * vOutDir.x);
        v35 = (float)((float)(outFlow->x * v33) + (float)(y * v34)) + (float)(z * v32);
        if ( v35 <= 0.0 )
        {
          if ( v35 >= 0.0 )
            v36 = 0.0;
          else
            v36 = FLOAT_N1_0;
        }
        else
        {
          v36 = *(float *)&FLOAT_1_0;
        }
        v37 = (__m128)(unsigned int)FLOAT_1_0;
        v37.m128_f32[0] = 1.0 - v26;
        v39 = v37;
        v38 = (float)((float)(1.0 - v26) * (float)((float)(v33 * v36) - outFlow->x)) + outFlow->x;
        v39.m128_f32[0] = (float)((float)(1.0 - v26) * (float)((float)(v34 * v36) - y)) + y;
        v40 = (float)((float)(1.0 - v26) * (float)((float)(v32 * v36) - z)) + z;
        v41 = v39;
        v41.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38)) + (float)(v40 * v40);
        if ( v41.m128_f32[0] == 0.0 )
          v42 = 0.0;
        else
          v42 = 1.0 / _mm_sqrt_ps(v41).m128_f32[0];
        v43 = v38 * v42;
        v44 = v39.m128_f32[0] * v42;
        v45 = v40 * v42;
        outFlow->x = v43;
        outFlow->y = v44;
        outFlow->z = v45;
        m_fStrength = this->m_fStrength;
        outFlow->x = v43 * v19;
        outFlow->y = v44 * v19;
        outFlow->z = v45 * v19;
      }
    }
    else
    {
      m_fStrength = this->m_fStrength;
      v21 = v19 * outFlow->x;
      v22 = v19 * outFlow->y;
      outFlow->z = v19 * outFlow->z;
      outFlow->x = v21;
      outFlow->y = v22;
    }
  }
  return m_fStrength;
}

// File Line: 678
// RVA: 0x1004D0
bool __fastcall UFG::FFieldAttractor::IsFlowDefinedAt(
        UFG::FFieldAttractor *this,
        UFG::qVector3 *vPosition,
        float fTimeOffset)
{
  UFG::qVector3 *Position; // rax
  float *m_pPointer; // rbx
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  __m128 y_low; // xmm2
  float v14; // xmm5_4
  __m128 v15; // xmm6
  UFG::qVector3 result; // [rsp+20h] [rbp-58h] BYREF

  if ( this->mpInterest.m_pPointer )
  {
    Position = UFG::FFieldAttractor::GetPosition(this, &result, fTimeOffset);
    if ( (float)((float)((float)((float)(vPosition->x - Position->x) * (float)(vPosition->x - Position->x))
                       + (float)((float)(vPosition->y - Position->y) * (float)(vPosition->y - Position->y)))
               + (float)((float)(vPosition->z - Position->z) * (float)(vPosition->z - Position->z))) > (float)(this->mParams.FLMaxDist * this->mParams.FLMaxDist) )
      return 0;
  }
  UFG::FFieldAttractor::CalcFlashlightDirection(this, &result);
  m_pPointer = (float *)this->mpParentField.m_pPointer;
  v8 = result.x * -1.0;
  v9 = result.y * -1.0;
  v10 = result.z * -1.0;
  UFG::FFieldAttractor::GetPosition(this, &result, m_pPointer[35]);
  y_low = (__m128)LODWORD(result.y);
  v11 = 0.0;
  v12 = result.x - m_pPointer[36];
  y_low.m128_f32[0] = result.y - m_pPointer[37];
  v15 = y_low;
  v14 = result.z - m_pPointer[38];
  v15.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v15.m128_f32[0] != 0.0 )
    v11 = 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
  return (float)((float)((float)((float)(y_low.m128_f32[0] * v11) * v9) + (float)((float)(v12 * v11) * v8))
               + (float)((float)(v14 * v11) * v10)) >= this->mParams.MinOrientationError;
}

// File Line: 711
// RVA: 0xFCB90
void __fastcall UFG::FFieldAttractor::CalcFlashlightDirection(UFG::FFieldAttractor *this, UFG::qVector3 *vOutDir)
{
  UFG::SimComponent *m_pPointer; // rsi
  int Orientation; // eax
  UFG::SimComponent *v6; // rax
  int v7; // xmm2_4
  int v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  __m128 mNext_high; // xmm4
  float v12; // xmm5_4
  __m128 v13; // xmm6
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 result; // [rsp+20h] [rbp-28h] BYREF

  m_pPointer = this->mpParentField.m_pPointer;
  UFG::FFieldAttractor::GetPosition(this, &result, *((float *)&m_pPointer[2].m_SafePointerList.mNode.mPrev + 1));
  Orientation = (int)this->mParams.Orientation;
  if ( Orientation == 1 )
  {
    v6 = this->mpPrintComponent.m_pPointer;
    v7 = LODWORD(v6[1].m_pSimObject) ^ _xmm[0];
    v8 = HIDWORD(v6[1].m_pSimObject) ^ _xmm[0];
    LODWORD(vOutDir->x) = *(_DWORD *)(&v6[1].m_SimObjIndex + 1) ^ _xmm[0];
    LODWORD(vOutDir->y) = v7;
    LODWORD(vOutDir->z) = v8;
  }
  else if ( Orientation )
  {
    y = UFG::qVector3::msDirFront.y;
    z = UFG::qVector3::msDirFront.z;
    vOutDir->x = UFG::qVector3::msDirFront.x;
    vOutDir->y = y;
    vOutDir->z = z;
  }
  else
  {
    mNext_high = (__m128)HIDWORD(m_pPointer[2].m_SafePointerList.mNode.mNext);
    v9 = 0.0;
    v10 = *(float *)&m_pPointer[2].m_SafePointerList.mNode.mNext - result.x;
    mNext_high.m128_f32[0] = mNext_high.m128_f32[0] - result.y;
    v12 = *(float *)&m_pPointer[2].m_TypeUID - result.z;
    v13 = mNext_high;
    v13.m128_f32[0] = (float)((float)(mNext_high.m128_f32[0] * mNext_high.m128_f32[0]) + (float)(v10 * v10))
                    + (float)(v12 * v12);
    if ( v13.m128_f32[0] != 0.0 )
      v9 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
    vOutDir->x = v10 * v9;
    vOutDir->y = mNext_high.m128_f32[0] * v9;
    vOutDir->z = v12 * v9;
  }
}

// File Line: 759
// RVA: 0xFAFC0
void __fastcall UFG::FFieldPathPrint::FFieldPathPrint(
        UFG::FFieldPathPrint *this,
        UFG::HermiteCurve *pPathCurve,
        int iPriority,
        float fStrength)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  UFG::FlowfieldPrint::FlowfieldPrint(this, 1u, iPriority, fStrength);
  this->vfptr = (UFG::qSafePointerNode<UFG::FlowfieldPrint>Vtbl *)&UFG::FFieldPathPrint::`vftable;
  this->mParams.MinTForPerp = 0.0099999998;
  this->mParams.DistForPerp = 3.0;
  this->mParams.GlobalSearchDist = 25.0;
  this->mParams.Priority = 5.0;
  this->mParams.FlowScaleTangent = 1.25;
  this->mParams.FlowScalePerp = 1.5;
  this->mParams.Strength = 0.5;
  this->mParams.VelForTangent = 20.0;
  this->mParams.MaxDistance = 200.0;
  this->mParams.VelForPerp = 5.0;
  this->mParams.DistForTangent = 0.5;
  this->mpPathCurve = pPathCurve;
  this->mCurveWalker.mpCurve = pPathCurve;
  this->mCurveWalker.mfGlobalSearchDist = 15.0;
  this->mCurveWalker.mfLastT = -1.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mCurveWalker.mvLastPos.x = UFG::qVector3::msZero.x;
  this->mCurveWalker.mvLastPos.y = y;
  this->mCurveWalker.mvLastPos.z = z;
  this->mCurveWalker.mfLastT = -1.0;
  this->mCurveWalker.mfCurveLength = -1.0;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->mCurveWalker.mvLastPos.x = UFG::qVector3::msZero.x;
  this->mCurveWalker.mvLastPos.y = v9;
  this->mCurveWalker.mvLastPos.z = v10;
  if ( iPriority <= 0 )
    this->m_iPriority = (int)this->mParams.Priority;
  if ( fStrength <= 0.0 )
    this->m_fStrength = this->mParams.Strength;
}

// File Line: 839
// RVA: 0xFDF00
float __fastcall UFG::FFieldPathPrint::GetFlow(
        UFG::FFieldPathPrint *this,
        UFG::qVector3 *outFlow,
        UFG::qVector3 *vPosition,
        float fTimeOffset,
        UFG::qVector3 *optEyePosition,
        UFG::qVector3 *optEyeVelocity)
{
  UFG::HermiteCurve *mpPathCurve; // rcx
  float y; // xmm1_4
  float v10; // xmm0_4
  __m128 x_low; // xmm2
  float v12; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm8_4
  float v16; // xmm10_4
  __m128 y_low; // xmm11
  __m128 v18; // xmm2
  float DistForTangent; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm9_4
  float v22; // xmm3_4
  float v23; // xmm12_4
  float v24; // xmm10_4
  float v25; // xmm9_4
  float v26; // xmm8_4
  float v27; // xmm2_4
  __m128 v28; // xmm4
  float v29; // xmm5_4
  __m128 v30; // xmm3
  float v31; // xmm1_4
  float MinTForPerp; // xmm3_4
  float v33; // xmm2_4
  float FlowScalePerp; // xmm0_4
  float v35; // xmm5_4
  float v36; // xmm2_4
  float v37; // xmm4_4
  __m128 v38; // xmm3
  float v39; // xmm5_4
  __m128 v40; // xmm8
  float v41; // xmm6_4
  float FlowScaleTangent; // xmm0_4
  UFG::qVector3 vOutTangent; // [rsp+50h] [rbp-A8h] BYREF
  UFG::qVector3 target_point; // [rsp+60h] [rbp-98h] BYREF
  UFG::qVector3 closest_point; // [rsp+70h] [rbp-88h] BYREF
  float v47; // [rsp+7Ch] [rbp-7Ch]
  float v48; // [rsp+80h] [rbp-78h]
  UFG::qVector3 outTangent; // [rsp+88h] [rbp-70h] BYREF
  UFG::qVector3 *vCurrentPos; // [rsp+138h] [rbp+40h]

  mpPathCurve = this->mpPathCurve;
  if ( !mpPathCurve || !mpPathCurve->mNumControlPoints )
    return 0.0;
  y = vPosition->y;
  target_point.x = vPosition->x;
  target_point.z = vPosition->z;
  target_point.y = y;
  v10 = UFG::HermiteCurve::ClosestPointEx(
          mpPathCurve,
          &target_point,
          &closest_point,
          -1.234,
          -1.234,
          -1.0,
          -1.234,
          -1.234);
  UFG::HermiteCurve::GetTangent(this->mpPathCurve, v10, &vOutTangent);
  x_low = (__m128)LODWORD(vOutTangent.x);
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(vOutTangent.y * vOutTangent.y))
                    + (float)(vOutTangent.z * vOutTangent.z);
  if ( x_low.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
  y_low = (__m128)LODWORD(closest_point.y);
  v13 = vOutTangent.x * v12;
  v14 = vOutTangent.y * v12;
  v15 = vOutTangent.z * v12;
  v16 = closest_point.x - target_point.x;
  y_low.m128_f32[0] = closest_point.y - target_point.y;
  target_point.z = closest_point.z;
  v18 = y_low;
  vOutTangent.x = vOutTangent.x * v12;
  vOutTangent.y = vOutTangent.y * v12;
  v18.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v16 * v16)) + (float)(0.0 * 0.0);
  DistForTangent = this->mParams.DistForTangent;
  vOutTangent.z = v15;
  v20 = _mm_sqrt_ps(v18).m128_f32[0];
  if ( v20 <= DistForTangent )
  {
    FlowScaleTangent = this->mParams.FlowScaleTangent;
    outFlow->x = v13 * FlowScaleTangent;
    outFlow->y = v14 * FlowScaleTangent;
    outFlow->z = v15 * FlowScaleTangent;
  }
  else
  {
    v21 = 1.0 / v20;
    v22 = (float)(v20 - this->mParams.DistForPerp) / (float)(DistForTangent - this->mParams.DistForPerp);
    v23 = v21 * v16;
    v24 = v21 * y_low.m128_f32[0];
    v25 = v21 * 0.0;
    if ( v22 <= 0.0 )
    {
      v22 = 0.0;
    }
    else if ( v22 >= 1.0 )
    {
      v22 = *(float *)&FLOAT_1_0;
    }
    v26 = (float)((float)(1.0 - this->mParams.MinTForPerp) * v22) + this->mParams.MinTForPerp;
    if ( optEyePosition
      && vCurrentPos
      && optEyePosition->x != 0.0
      && optEyePosition->y != 0.0
      && optEyePosition->z != 0.0 )
    {
      UFG::HermiteCurveWalker::GetClosestPoint(
        &this->mCurveWalker,
        (UFG::qVector3 *)&closest_point.z,
        &outTangent,
        vCurrentPos,
        0.0,
        -1.234,
        -1.234,
        20,
        -1.234);
      v28 = (__m128)LODWORD(v47);
      v27 = closest_point.z - vCurrentPos->x;
      v28.m128_f32[0] = v47 - vCurrentPos->y;
      v29 = v48 - vCurrentPos->z;
      v30 = v28;
      v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
      if ( v30.m128_f32[0] == 0.0 )
        v31 = 0.0;
      else
        v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
      v33 = (float)((float)((float)((float)((float)(v27 * v31) * optEyePosition->x)
                                  + (float)((float)(v28.m128_f32[0] * v31) * optEyePosition->y))
                          + (float)((float)(v29 * v31) * optEyePosition->z))
                  - this->mParams.VelForPerp)
          / (float)(this->mParams.VelForTangent - this->mParams.VelForPerp);
      if ( v33 <= 0.0 )
      {
        v33 = 0.0;
      }
      else if ( v33 >= 1.0 )
      {
        v33 = *(float *)&FLOAT_1_0;
      }
      MinTForPerp = this->mParams.MinTForPerp;
      if ( (float)((float)((float)(1.0 - MinTForPerp) * v33) + MinTForPerp) > v26 )
        v26 = (float)((float)(1.0 - MinTForPerp) * v33) + MinTForPerp;
    }
    FlowScalePerp = this->mParams.FlowScalePerp;
    v38 = (__m128)LODWORD(vOutTangent.y);
    v35 = (float)(this->mParams.FlowScaleTangent - FlowScalePerp) * v26;
    v36 = (float)((float)(vOutTangent.x - v23) * v26) + v23;
    v37 = (float)((float)(vOutTangent.z - v25) * v26) + v25;
    v38.m128_f32[0] = (float)((float)(vOutTangent.y - v24) * v26) + v24;
    v40 = v38;
    v39 = v35 + FlowScalePerp;
    v40.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v36 * v36)) + (float)(v37 * v37);
    if ( v40.m128_f32[0] == 0.0 )
      v41 = 0.0;
    else
      v41 = 1.0 / _mm_sqrt_ps(v40).m128_f32[0];
    outFlow->x = (float)(v36 * v41) * v39;
    outFlow->y = (float)(v38.m128_f32[0] * v41) * v39;
    outFlow->z = (float)(v37 * v41) * v39;
  }
  return this->m_fStrength;
}

// File Line: 991
// RVA: 0x14613C0
__int64 dynamic_initializer_for__UFG::FFieldPrintComponent::s_FFieldPrintComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::FFieldPrintComponent::s_FFieldPrintComponentList__);
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

