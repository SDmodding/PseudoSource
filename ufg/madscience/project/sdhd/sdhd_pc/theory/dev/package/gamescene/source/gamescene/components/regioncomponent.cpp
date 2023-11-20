// File Line: 59
// RVA: 0x1470A00
__int64 dynamic_initializer_for__UFG::RegionComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::RegionComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::RegionComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::RegionComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::RegionComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 73
// RVA: 0x237640
void __fastcall UFG::RegionComponent::RegionComponent(UFG::RegionComponent *this, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rbx
  UFG::RegionComponent *v3; // rdi

  v2 = name;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name->mUID);
  v3->i_name = (UFG::qSymbol)v2->mUID;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HintComponentBase::`vftable';
  v3->mFlags = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::HintComponentBase::_HintComponentBaseTypeUID,
    "HintComponentBase");
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RegionComponent::`vftable';
  v3->mFlags = 0;
  v3->mpRegion.mPtr = 0i64;
  v3->mXFormChangeCacheID = -1;
  *(_QWORD *)&v3->mCachedAABB.mMin.x = 0i64;
  *(_QWORD *)&v3->mCachedAABB.mMin.z = 0i64;
  *(_QWORD *)&v3->mCachedAABB.mMax.y = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::RegionComponent::_RegionComponentTypeUID,
    "RegionComponent");
}

// File Line: 181
// RVA: 0x23D220
void __fastcall UFG::RegionComponent::GetCenter(UFG::RegionComponent *this, UFG::qVector3 *pPos)
{
  UFG::TransformNodeComponent *v2; // rdi
  UFG::qVector3 *v3; // rbx
  float v4; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4

  v2 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v3 = pPos;
  if ( v2 )
    v2 = (UFG::TransformNodeComponent *)v2->mChildren.mNode.mNext;
  if ( v2 )
  {
    (*((void (**)(void))&this->mpRegion.mPtr->vfptr->__vecDelDtor + 3))();
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v4 = v3->z;
    v5 = (float)((float)((float)(v3->y * v2->mWorldTransform.v1.z) + (float)(v3->x * v2->mWorldTransform.v0.z))
               + (float)(v4 * v2->mWorldTransform.v2.z))
       + v2->mWorldTransform.v3.z;
    v6 = (float)((float)((float)(v3->y * v2->mWorldTransform.v1.y) + (float)(v3->x * v2->mWorldTransform.v0.y))
               + (float)(v4 * v2->mWorldTransform.v2.y))
       + v2->mWorldTransform.v3.y;
    v3->x = (float)((float)((float)(v3->y * v2->mWorldTransform.v1.x) + (float)(v3->x * v2->mWorldTransform.v0.x))
                  + (float)(v3->z * v2->mWorldTransform.v2.x))
          + v2->mWorldTransform.v3.x;
    v3->z = v5;
    v3->y = v6;
  }
  else
  {
    v7 = UFG::qVector3::msZero.y;
    v8 = UFG::qVector3::msZero.z;
    pPos->x = UFG::qVector3::msZero.x;
    pPos->y = v7;
    pPos->z = v8;
  }
}

// File Line: 200
// RVA: 0x23C860
void __fastcall UFG::RegionComponent::GetBoundingBox(UFG::RegionComponent *this, UFG::qBox *pBox)
{
  UFG::TransformNodeComponent *v2; // rdi
  UFG::qBox *v3; // rsi
  UFG::RegionComponent *v4; // rbx
  float v5; // xmm9_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm8_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm7_4
  float v43; // xmm4_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm3_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm4_4
  float v58; // xmm0_4
  float v59; // xmm0_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  float v62; // xmm2_4
  float v63; // xmm0_4
  float v64; // xmm6_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm3_4
  float v71; // xmm2_4
  float v72; // xmm0_4
  float v73; // xmm5_4
  float v74; // xmm2_4
  float v75; // xmm0_4
  float v76; // xmm0_4
  float v77; // xmm0_4
  float v78; // xmm0_4
  float v79; // xmm0_4
  float v80; // xmm1_4
  float v81; // xmm0_4
  float v82; // xmm1_4
  float v83; // xmm0_4
  __int64 v84; // [rsp+20h] [rbp-68h]
  __int64 v85; // [rsp+28h] [rbp-60h]
  __int64 v86; // [rsp+30h] [rbp-58h]

  v2 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v3 = pBox;
  v4 = this;
  if ( v2 )
    v2 = (UFG::TransformNodeComponent *)v2->mChildren.mNode.mNext;
  if ( v2 && v2->mChangeID != this->mXFormChangeCacheID )
  {
    v84 = 0i64;
    v85 = 0i64;
    v86 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v4->mpRegion.mPtr->vfptr->GetBoundingBox(v4->mpRegion.mPtr, (UFG::qBox *)&v84);
    v5 = *((float *)&v84 + 1);
    v6 = *(float *)&v85;
    v7 = *(float *)&v84;
    v8 = *((float *)&v85 + 1);
    v9 = (float)((float)((float)(*((float *)&v84 + 1) * v2->mWorldTransform.v1.x)
                       + (float)(*(float *)&v84 * v2->mWorldTransform.v0.x))
               + (float)(*(float *)&v85 * v2->mWorldTransform.v2.x))
       + v2->mWorldTransform.v3.x;
    v10 = (float)((float)((float)(*(float *)&v84 * v2->mWorldTransform.v0.y)
                        + (float)(*((float *)&v84 + 1) * v2->mWorldTransform.v1.y))
                + (float)(*(float *)&v85 * v2->mWorldTransform.v2.y))
        + v2->mWorldTransform.v3.y;
    v11 = *((float *)&v85 + 1);
    v12 = *(float *)&v85;
    v13 = (float)((float)((float)(*(float *)&v84 * v2->mWorldTransform.v0.z)
                        + (float)(*((float *)&v84 + 1) * v2->mWorldTransform.v1.z))
                + (float)(*(float *)&v85 * v2->mWorldTransform.v2.z))
        + v2->mWorldTransform.v3.z;
    v4->mCachedAABB.mMin.x = v9;
    v4->mCachedAABB.mMin.y = v10;
    v4->mCachedAABB.mMin.z = v13;
    v4->mCachedAABB.mMax.x = v9;
    v4->mCachedAABB.mMax.y = v10;
    v4->mCachedAABB.mMax.z = v13;
    v14 = (float)((float)((float)(v5 * v2->mWorldTransform.v1.x) + (float)(v11 * v2->mWorldTransform.v0.x))
                + (float)(v12 * v2->mWorldTransform.v2.x))
        + v2->mWorldTransform.v3.x;
    v15 = (float)((float)((float)(v8 * v2->mWorldTransform.v0.y) + (float)(v5 * v2->mWorldTransform.v1.y))
                + (float)(v6 * v2->mWorldTransform.v2.y))
        + v2->mWorldTransform.v3.y;
    v16 = v4->mCachedAABB.mMin.x;
    v17 = (float)((float)((float)(v8 * v2->mWorldTransform.v0.z) + (float)(v5 * v2->mWorldTransform.v1.z))
                + (float)(v6 * v2->mWorldTransform.v2.z))
        + v2->mWorldTransform.v3.z;
    if ( v16 >= v14 )
      v16 = v14;
    v4->mCachedAABB.mMin.x = v16;
    v18 = v4->mCachedAABB.mMin.y;
    if ( v18 >= v15 )
      v18 = v15;
    v4->mCachedAABB.mMin.y = v18;
    v19 = v4->mCachedAABB.mMin.z;
    if ( v19 >= v17 )
      v19 = v17;
    v4->mCachedAABB.mMin.z = v19;
    v20 = v4->mCachedAABB.mMax.x;
    if ( v20 <= v14 )
      v20 = v14;
    v4->mCachedAABB.mMax.x = v20;
    v21 = v4->mCachedAABB.mMax.y;
    if ( v21 <= v15 )
      v21 = v15;
    v4->mCachedAABB.mMax.y = v21;
    v22 = v4->mCachedAABB.mMax.z;
    if ( v22 <= v17 )
      v22 = v17;
    v23 = *(float *)&v86;
    v4->mCachedAABB.mMax.z = v22;
    v24 = (float)((float)((float)(v23 * v2->mWorldTransform.v1.x) + (float)(v7 * v2->mWorldTransform.v0.x))
                + (float)(v6 * v2->mWorldTransform.v2.x))
        + v2->mWorldTransform.v3.x;
    v25 = (float)((float)((float)(v7 * v2->mWorldTransform.v0.y) + (float)(v23 * v2->mWorldTransform.v1.y))
                + (float)(v6 * v2->mWorldTransform.v2.y))
        + v2->mWorldTransform.v3.y;
    v26 = v4->mCachedAABB.mMin.x;
    v27 = (float)((float)((float)(v7 * v2->mWorldTransform.v0.z) + (float)(v23 * v2->mWorldTransform.v1.z))
                + (float)(v6 * v2->mWorldTransform.v2.z))
        + v2->mWorldTransform.v3.z;
    if ( v26 >= v24 )
      v26 = (float)((float)((float)(v23 * v2->mWorldTransform.v1.x) + (float)(v7 * v2->mWorldTransform.v0.x))
                  + (float)(v6 * v2->mWorldTransform.v2.x))
          + v2->mWorldTransform.v3.x;
    v4->mCachedAABB.mMin.x = v26;
    v28 = v4->mCachedAABB.mMin.y;
    if ( v28 >= v25 )
      v28 = v25;
    v4->mCachedAABB.mMin.y = v28;
    v29 = v4->mCachedAABB.mMin.z;
    if ( v29 >= v27 )
      v29 = v27;
    v4->mCachedAABB.mMin.z = v29;
    v30 = v4->mCachedAABB.mMax.x;
    if ( v30 <= v24 )
      v30 = v24;
    v4->mCachedAABB.mMax.x = v30;
    v31 = v4->mCachedAABB.mMax.y;
    if ( v31 <= v25 )
      v31 = v25;
    v4->mCachedAABB.mMax.y = v31;
    v32 = v4->mCachedAABB.mMax.z;
    if ( v32 <= v27 )
      v32 = v27;
    v4->mCachedAABB.mMax.z = v32;
    v33 = (float)((float)((float)(v23 * v2->mWorldTransform.v1.x) + (float)(v8 * v2->mWorldTransform.v0.x))
                + (float)(v6 * v2->mWorldTransform.v2.x))
        + v2->mWorldTransform.v3.x;
    v34 = (float)((float)((float)(v8 * v2->mWorldTransform.v0.y) + (float)(v23 * v2->mWorldTransform.v1.y))
                + (float)(v6 * v2->mWorldTransform.v2.y))
        + v2->mWorldTransform.v3.y;
    v35 = v4->mCachedAABB.mMin.x;
    v36 = (float)((float)((float)(v8 * v2->mWorldTransform.v0.z) + (float)(v23 * v2->mWorldTransform.v1.z))
                + (float)(v6 * v2->mWorldTransform.v2.z))
        + v2->mWorldTransform.v3.z;
    if ( v35 >= v33 )
      v35 = (float)((float)((float)(v23 * v2->mWorldTransform.v1.x) + (float)(v8 * v2->mWorldTransform.v0.x))
                  + (float)(v6 * v2->mWorldTransform.v2.x))
          + v2->mWorldTransform.v3.x;
    v4->mCachedAABB.mMin.x = v35;
    v37 = v4->mCachedAABB.mMin.y;
    if ( v37 >= v34 )
      v37 = v34;
    v4->mCachedAABB.mMin.y = v37;
    v38 = v4->mCachedAABB.mMin.z;
    if ( v38 >= v36 )
      v38 = v36;
    v4->mCachedAABB.mMin.z = v38;
    v39 = v4->mCachedAABB.mMax.x;
    if ( v39 <= v33 )
      v39 = v33;
    v4->mCachedAABB.mMax.x = v39;
    v40 = v4->mCachedAABB.mMax.y;
    if ( v40 <= v34 )
      v40 = v34;
    v4->mCachedAABB.mMax.y = v40;
    v41 = v4->mCachedAABB.mMax.z;
    if ( v41 <= v36 )
      v41 = v36;
    v42 = *((float *)&v86 + 1);
    v4->mCachedAABB.mMax.z = v41;
    v43 = (float)((float)((float)(v5 * v2->mWorldTransform.v1.x) + (float)(v7 * v2->mWorldTransform.v0.x))
                + (float)(v42 * v2->mWorldTransform.v2.x))
        + v2->mWorldTransform.v3.x;
    v44 = v4->mCachedAABB.mMin.x;
    v45 = (float)((float)((float)(v7 * v2->mWorldTransform.v0.y) + (float)(v5 * v2->mWorldTransform.v1.y))
                + (float)(v42 * v2->mWorldTransform.v2.y))
        + v2->mWorldTransform.v3.y;
    v46 = (float)((float)((float)(v7 * v2->mWorldTransform.v0.z) + (float)(v5 * v2->mWorldTransform.v1.z))
                + (float)(v42 * v2->mWorldTransform.v2.z))
        + v2->mWorldTransform.v3.z;
    if ( v44 >= v43 )
      v44 = (float)((float)((float)(v5 * v2->mWorldTransform.v1.x) + (float)(v7 * v2->mWorldTransform.v0.x))
                  + (float)(v42 * v2->mWorldTransform.v2.x))
          + v2->mWorldTransform.v3.x;
    v4->mCachedAABB.mMin.x = v44;
    v47 = v4->mCachedAABB.mMin.y;
    if ( v47 >= v45 )
      v47 = v45;
    v4->mCachedAABB.mMin.y = v47;
    v48 = v4->mCachedAABB.mMin.z;
    if ( v48 >= v46 )
      v48 = v46;
    v4->mCachedAABB.mMin.z = v48;
    v49 = v4->mCachedAABB.mMax.x;
    if ( v49 <= v43 )
      v49 = v43;
    v4->mCachedAABB.mMax.x = v49;
    v50 = v4->mCachedAABB.mMax.y;
    if ( v50 <= v45 )
      v50 = v45;
    v4->mCachedAABB.mMax.y = v50;
    v51 = v4->mCachedAABB.mMax.z;
    if ( v51 <= v46 )
      v51 = v46;
    v4->mCachedAABB.mMax.z = v51;
    v52 = (float)((float)((float)(v5 * v2->mWorldTransform.v1.x) + (float)(v8 * v2->mWorldTransform.v0.x))
                + (float)(v42 * v2->mWorldTransform.v2.x))
        + v2->mWorldTransform.v3.x;
    v53 = (float)((float)((float)(v8 * v2->mWorldTransform.v0.y) + (float)(v5 * v2->mWorldTransform.v1.y))
                + (float)(v42 * v2->mWorldTransform.v2.y))
        + v2->mWorldTransform.v3.y;
    v54 = v4->mCachedAABB.mMin.x;
    v55 = (float)((float)((float)(v8 * v2->mWorldTransform.v0.z) + (float)(v5 * v2->mWorldTransform.v1.z))
                + (float)(v42 * v2->mWorldTransform.v2.z))
        + v2->mWorldTransform.v3.z;
    if ( v54 >= v52 )
      v54 = (float)((float)((float)(v5 * v2->mWorldTransform.v1.x) + (float)(v8 * v2->mWorldTransform.v0.x))
                  + (float)(v42 * v2->mWorldTransform.v2.x))
          + v2->mWorldTransform.v3.x;
    v4->mCachedAABB.mMin.x = v54;
    v56 = v4->mCachedAABB.mMin.y;
    if ( v56 >= v53 )
      v56 = v53;
    v4->mCachedAABB.mMin.y = v56;
    v57 = v4->mCachedAABB.mMin.z;
    if ( v57 >= v55 )
      v57 = v55;
    v4->mCachedAABB.mMin.z = v57;
    v58 = v4->mCachedAABB.mMax.x;
    if ( v58 <= v52 )
      v58 = v52;
    v4->mCachedAABB.mMax.x = v58;
    v59 = v4->mCachedAABB.mMax.y;
    if ( v59 <= v53 )
      v59 = v53;
    v4->mCachedAABB.mMax.y = v59;
    v60 = v4->mCachedAABB.mMax.z;
    if ( v60 <= v55 )
      v60 = v55;
    v4->mCachedAABB.mMax.z = v60;
    v61 = (float)((float)((float)(v23 * v2->mWorldTransform.v1.x) + (float)(v7 * v2->mWorldTransform.v0.x))
                + (float)(v42 * v2->mWorldTransform.v2.x))
        + v2->mWorldTransform.v3.x;
    v62 = (float)((float)((float)(v7 * v2->mWorldTransform.v0.y) + (float)(v23 * v2->mWorldTransform.v1.y))
                + (float)(v42 * v2->mWorldTransform.v2.y))
        + v2->mWorldTransform.v3.y;
    v63 = v4->mCachedAABB.mMin.x;
    v64 = (float)((float)((float)(v7 * v2->mWorldTransform.v0.z) + (float)(v23 * v2->mWorldTransform.v1.z))
                + (float)(v42 * v2->mWorldTransform.v2.z))
        + v2->mWorldTransform.v3.z;
    if ( v63 >= v61 )
      v63 = v61;
    v4->mCachedAABB.mMin.x = v63;
    v65 = v4->mCachedAABB.mMin.y;
    if ( v65 >= v62 )
      v65 = v62;
    v4->mCachedAABB.mMin.y = v65;
    v66 = v57;
    if ( v57 >= v64 )
      v66 = v64;
    v4->mCachedAABB.mMin.z = v66;
    v67 = v4->mCachedAABB.mMax.x;
    if ( v67 <= v61 )
      v67 = v61;
    v4->mCachedAABB.mMax.x = v67;
    v68 = v4->mCachedAABB.mMax.y;
    if ( v68 <= v62 )
      v68 = v62;
    v4->mCachedAABB.mMax.y = v68;
    v69 = v4->mCachedAABB.mMax.z;
    if ( v69 <= v64 )
      v69 = v64;
    v4->mCachedAABB.mMax.z = v69;
    v70 = (float)((float)((float)(v23 * v2->mWorldTransform.v1.x) + (float)(v8 * v2->mWorldTransform.v0.x))
                + (float)(v42 * v2->mWorldTransform.v2.x))
        + v2->mWorldTransform.v3.x;
    v71 = (float)(v8 * v2->mWorldTransform.v0.y) + (float)(v23 * v2->mWorldTransform.v1.y);
    v72 = v4->mCachedAABB.mMin.x;
    v73 = (float)((float)((float)(v8 * v2->mWorldTransform.v0.z) + (float)(v23 * v2->mWorldTransform.v1.z))
                + (float)(v42 * v2->mWorldTransform.v2.z))
        + v2->mWorldTransform.v3.z;
    v74 = (float)(v71 + (float)(v42 * v2->mWorldTransform.v2.y)) + v2->mWorldTransform.v3.y;
    if ( v72 >= v70 )
      v72 = v70;
    v4->mCachedAABB.mMin.x = v72;
    v75 = v4->mCachedAABB.mMin.y;
    if ( v75 >= v74 )
      v75 = v74;
    v4->mCachedAABB.mMin.y = v75;
    v76 = v4->mCachedAABB.mMin.z;
    if ( v76 >= v73 )
      v76 = v73;
    v4->mCachedAABB.mMin.z = v76;
    v77 = v4->mCachedAABB.mMax.x;
    if ( v77 <= v70 )
      v77 = v70;
    v4->mCachedAABB.mMax.x = v77;
    v78 = v4->mCachedAABB.mMax.y;
    if ( v78 <= v74 )
      v78 = v74;
    v4->mCachedAABB.mMax.y = v78;
    v79 = v4->mCachedAABB.mMax.z;
    if ( v79 <= v73 )
      v79 = v73;
    v4->mCachedAABB.mMax.z = v79;
    v4->mXFormChangeCacheID = v2->mChangeID;
  }
  v80 = v4->mCachedAABB.mMin.y;
  v81 = v4->mCachedAABB.mMin.z;
  v3->mMin.x = v4->mCachedAABB.mMin.x;
  v3->mMin.y = v80;
  v3->mMin.z = v81;
  v82 = v4->mCachedAABB.mMax.y;
  v83 = v4->mCachedAABB.mMax.z;
  v3->mMax.x = v4->mCachedAABB.mMax.x;
  v3->mMax.y = v82;
  v3->mMax.z = v83;
}

// File Line: 235
// RVA: 0x23D8E0
void __fastcall UFG::RegionComponent::GetLocalBoundingBox(UFG::RegionComponent *this, UFG::qBox *pBox)
{
  this->mpRegion.mPtr->vfptr->GetBoundingBox(this->mpRegion.mPtr, pBox);
}

// File Line: 244
// RVA: 0x23DB30
UFG::qVector3 *__fastcall UFG::RegionComponent::GetRandomPosition(UFG::RegionComponent *this, UFG::qVector3 *result)
{
  UFG::TransformNodeComponent *v2; // rsi
  UFG::qVector3 *v3; // rdi
  UFG::RegionBase *v4; // rbx
  float *v5; // rax
  float v6; // xmm6_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  UFG::qVector3 *v9; // rax
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  char v17; // [rsp+20h] [rbp-28h]

  v2 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v3 = result;
  if ( v2 )
    v2 = (UFG::TransformNodeComponent *)v2->mChildren.mNode.mNext;
  if ( v2 )
  {
    v4 = this->mpRegion.mPtr;
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v5 = (float *)v4->vfptr->GetRandomPosition(v4, (UFG::qVector3 *)&v17);
    v6 = v5[1];
    v7 = *v5;
    v8 = v5[2];
    v9 = v3;
    v10 = v6;
    v11 = (float)((float)(v6 * v2->mWorldTransform.v1.x) + (float)(v7 * v2->mWorldTransform.v0.x))
        + (float)(v8 * v2->mWorldTransform.v2.x);
    v12 = (float)(v6 * v2->mWorldTransform.v1.z) + (float)(v7 * v2->mWorldTransform.v0.z);
    v13 = (float)(v10 * v2->mWorldTransform.v1.y) + (float)(v7 * v2->mWorldTransform.v0.y);
    v3->x = v11 + v2->mWorldTransform.v3.x;
    v14 = (float)(v13 + (float)(v8 * v2->mWorldTransform.v2.y)) + v2->mWorldTransform.v3.y;
    v3->z = (float)(v12 + (float)(v8 * v2->mWorldTransform.v2.z)) + v2->mWorldTransform.v3.z;
    v3->y = v14;
  }
  else
  {
    v15 = UFG::qVector3::msZero.y;
    v9 = result;
    result->x = UFG::qVector3::msZero.x;
    v16 = UFG::qVector3::msZero.z;
    result->y = v15;
    result->z = v16;
  }
  return v9;
}

// File Line: 263
// RVA: 0x2403E0
bool __fastcall UFG::RegionComponent::IsHitPoint(UFG::RegionComponent *this, UFG::qVector3 *pos)
{
  UFG::qVector3 *v2; // rbx
  UFG::RegionComponent *v3; // rsi
  float v4; // xmm0_4
  float v5; // xmm0_4
  UFG::TransformNodeComponent *v6; // rdi
  UFG::RegionBase *v7; // rcx
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  UFG::qBox pBox; // [rsp+20h] [rbp-19h]
  UFG::qMatrix44 d; // [rsp+40h] [rbp+7h]

  v2 = pos;
  v3 = this;
  *(_QWORD *)&pBox.mMin.x = 0i64;
  *(_QWORD *)&pBox.mMin.z = 0i64;
  *(_QWORD *)&pBox.mMax.y = 0i64;
  UFG::RegionComponent::GetBoundingBox(this, &pBox);
  if ( v2->x < pBox.mMin.x )
    return 0;
  if ( v2->x > pBox.mMax.x )
    return 0;
  v4 = v2->y;
  if ( v4 < pBox.mMin.y )
    return 0;
  if ( v4 > pBox.mMax.y )
    return 0;
  v5 = v2->z;
  if ( v5 < pBox.mMin.z || v5 > pBox.mMax.z )
    return 0;
  v6 = (UFG::TransformNodeComponent *)v3->m_pSimObject;
  if ( v6 )
    v6 = (UFG::TransformNodeComponent *)v6->mChildren.mNode.mNext;
  if ( !v6 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  UFG::qInverseAffine(&d, &v6->mWorldTransform);
  v7 = v3->mpRegion.mPtr;
  v8 = v2->x;
  v9 = v2->y;
  v10 = d.v2.z * v2->z;
  v11 = (float)((float)((float)(d.v1.y * v9) + (float)(d.v0.y * v2->x)) + (float)(d.v2.y * v2->z)) + d.v3.y;
  pBox.mMin.x = (float)((float)((float)(d.v1.x * v9) + (float)(d.v0.x * v2->x)) + (float)(d.v2.x * v2->z)) + d.v3.x;
  pBox.mMin.y = v11;
  pBox.mMin.z = (float)((float)((float)(d.v1.z * v9) + (float)(d.v0.z * v8)) + v10) + d.v3.z;
  return v7->vfptr->IsHitPoint(v7, &pBox.mMin);
}

// File Line: 323
// RVA: 0x241A10
bool __fastcall UFG::RegionComponent::IsHitSegment(UFG::RegionComponent *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *v4; // r14
  UFG::qVector3 *v5; // rbx
  UFG::qVector3 *v6; // rsi
  UFG::RegionComponent *v7; // r15
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  float v15; // xmm8_4
  UFG::TransformNodeComponent *v16; // rdi
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm6_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  UFG::RegionBase *v38; // rcx
  float v39; // xmm2_4
  bool result; // al
  float v41; // xmm4_4
  float v42; // xmm6_4
  float v43; // xmm3_4
  float v44; // xmm2_4
  float v45; // xmm2_4
  UFG::qBox pBox; // [rsp+20h] [rbp-C8h]
  UFG::qMatrix44 m; // [rsp+40h] [rbp-A8h]
  float v48; // [rsp+80h] [rbp-68h]
  float v49; // [rsp+88h] [rbp-60h]
  float v50; // [rsp+8Ch] [rbp-5Ch]
  float v51; // [rsp+90h] [rbp-58h]
  float v52; // [rsp+98h] [rbp-50h]
  float v53; // [rsp+9Ch] [rbp-4Ch]
  float v54; // [rsp+A0h] [rbp-48h]
  float v55; // [rsp+A8h] [rbp-40h]
  float v56; // [rsp+ACh] [rbp-3Ch]
  float v57; // [rsp+B0h] [rbp-38h]

  v4 = start;
  v5 = pHitPos;
  v6 = end;
  v7 = this;
  *(_QWORD *)&pBox.mMin.x = 0i64;
  *(_QWORD *)&pBox.mMin.z = 0i64;
  *(_QWORD *)&pBox.mMax.y = 0i64;
  UFG::RegionComponent::GetBoundingBox(this, &pBox);
  v8 = v4->x;
  if ( v4->x >= v6->x )
    v9 = v6->x;
  else
    v9 = v4->x;
  v10 = v4->y;
  v11 = v6->y;
  if ( v10 >= v11 )
    v12 = v6->y;
  else
    v12 = v4->y;
  v13 = v4->z;
  v14 = v6->z;
  if ( v13 >= v14 )
    v15 = v6->z;
  else
    v15 = v4->z;
  if ( v8 <= v6->x )
    v8 = v6->x;
  if ( v10 <= v11 )
    v10 = v6->y;
  if ( v13 <= v14 )
    v13 = v6->z;
  if ( pBox.mMin.x > v8
    || pBox.mMax.x < v9
    || pBox.mMin.y > v10
    || pBox.mMax.y < v12
    || pBox.mMin.z > v13
    || pBox.mMax.z < v15 )
  {
    return 0;
  }
  v16 = (UFG::TransformNodeComponent *)v7->m_pSimObject;
  if ( v16 )
    v16 = (UFG::TransformNodeComponent *)v16->mChildren.mNode.mNext;
  if ( !v16 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v16);
  v17 = v16->mWorldTransform.v0.y;
  m.v0.x = v16->mWorldTransform.v0.x;
  v18 = v16->mWorldTransform.v0.z;
  m.v0.y = v17;
  v19 = v16->mWorldTransform.v0.w;
  m.v0.z = v18;
  v20 = v16->mWorldTransform.v1.x;
  m.v0.w = v19;
  v21 = v16->mWorldTransform.v1.y;
  m.v1.x = v20;
  v22 = v16->mWorldTransform.v1.z;
  m.v1.y = v21;
  v23 = v16->mWorldTransform.v1.w;
  m.v1.z = v22;
  v24 = v16->mWorldTransform.v2.x;
  m.v1.w = v23;
  v25 = v16->mWorldTransform.v2.y;
  m.v2.x = v24;
  v26 = v16->mWorldTransform.v2.z;
  m.v2.y = v25;
  v27 = v16->mWorldTransform.v2.w;
  m.v2.z = v26;
  v28 = v16->mWorldTransform.v3.x;
  m.v2.w = v27;
  v29 = v16->mWorldTransform.v3.y;
  m.v3.x = v28;
  v30 = v16->mWorldTransform.v3.z;
  m.v3.y = v29;
  v31 = v16->mWorldTransform.v3.w;
  m.v3.z = v30;
  m.v3.w = v31;
  UFG::qInverseAffine((UFG::qMatrix44 *)((char *)&m + 56), &m);
  v32 = v6->y;
  v33 = v6->z;
  v34 = (float)((float)((float)(v50 * v32) + (float)(m.v3.w * v6->x)) + (float)(v53 * v33)) + v56;
  v35 = (float)((float)(v51 * v32) + (float)(v48 * v6->x)) + (float)(v54 * v33);
  m.v2.z = (float)((float)((float)(v49 * v32) + (float)(m.v3.z * v6->x)) + (float)(v52 * v33)) + v55;
  m.v2.w = v34;
  v36 = v4->x;
  v37 = v4->y;
  v38 = v7->mpRegion.mPtr;
  m.v3.x = v35 + v57;
  v39 = v4->z;
  pBox.mMin.x = (float)((float)((float)(v49 * v37) + (float)(m.v3.z * v36)) + (float)(v52 * v39)) + v55;
  pBox.mMin.y = (float)((float)((float)(v50 * v37) + (float)(m.v3.w * v36)) + (float)(v53 * v39)) + v56;
  pBox.mMin.z = (float)((float)((float)(v51 * v37) + (float)(v48 * v36)) + (float)(v54 * v39)) + v57;
  result = ((__int64 (__fastcall *)(UFG::RegionBase *, UFG::qBox *, float *, UFG::qVector3 *, _QWORD, _QWORD))v38->vfptr->IsHitSegment)(
             v38,
             &pBox,
             &m.v2.z,
             v5,
             *(_QWORD *)&pBox.mMin.x,
             *(_QWORD *)&pBox.mMin.z);
  if ( result )
  {
    if ( v5 )
    {
      v41 = v5->y;
      v42 = v5->z;
      v43 = (float)((float)((float)(m.v1.y * v41) + (float)(m.v0.y * v5->x)) + (float)(m.v2.y * v42)) + m.v3.y;
      v44 = (float)((float)(m.v1.z * v41) + (float)(m.v0.z * v5->x)) + (float)(m.v2.z * v42);
      v5->x = (float)((float)((float)(m.v1.x * v41) + (float)(m.v0.x * v5->x)) + (float)(m.v2.x * v42)) + m.v3.x;
      v45 = v44 + m.v3.z;
      v5->y = v43;
      v5->z = v45;
    }
  }
  return result;
}

// File Line: 454
// RVA: 0x23A7A0
__int64 __fastcall UFG::RegionComponent::CycleAspect(UFG::RegionComponent *this, __int64 aspect, __int64 forward)
{
  return this->mpRegion.mPtr->vfptr->CycleAspect(this->mpRegion.mPtr, aspect, forward);
}

// File Line: 463
// RVA: 0x23C470
__int64 __fastcall UFG::RegionComponent::GetAspectDefault(UFG::RegionComponent *this)
{
  return ((__int64 (*)(void))this->mpRegion.mPtr->vfptr->GetAspectDefault)();
}

// File Line: 472
// RVA: 0x23C190
UFG::qVector3 *__fastcall UFG::RegionComponent::GetAspectCenter(UFG::RegionComponent *this, UFG::qVector3 *result, unsigned int aspect)
{
  UFG::TransformNodeComponent *v3; // rsi
  unsigned int v4; // ebp
  UFG::qVector3 *v5; // rdi
  UFG::RegionBase *v6; // rbx
  float *v7; // rax
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  UFG::qVector3 *v11; // rax
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  char v19; // [rsp+20h] [rbp-28h]

  v3 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v4 = aspect;
  v5 = result;
  if ( v3 )
    v3 = (UFG::TransformNodeComponent *)v3->mChildren.mNode.mNext;
  if ( v3 )
  {
    v6 = this->mpRegion.mPtr;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v7 = (float *)v6->vfptr->GetAspectCenter(v6, (UFG::qVector3 *)&v19, v4);
    v8 = v7[1];
    v9 = *v7;
    v10 = v7[2];
    v11 = v5;
    v12 = v8;
    v13 = (float)((float)(v8 * v3->mWorldTransform.v1.x) + (float)(v9 * v3->mWorldTransform.v0.x))
        + (float)(v10 * v3->mWorldTransform.v2.x);
    v14 = (float)(v8 * v3->mWorldTransform.v1.z) + (float)(v9 * v3->mWorldTransform.v0.z);
    v15 = (float)(v12 * v3->mWorldTransform.v1.y) + (float)(v9 * v3->mWorldTransform.v0.y);
    v5->x = v13 + v3->mWorldTransform.v3.x;
    v16 = (float)(v15 + (float)(v10 * v3->mWorldTransform.v2.y)) + v3->mWorldTransform.v3.y;
    v5->z = (float)(v14 + (float)(v10 * v3->mWorldTransform.v2.z)) + v3->mWorldTransform.v3.z;
    v5->y = v16;
  }
  else
  {
    v17 = UFG::qVector3::msZero.y;
    v11 = result;
    result->x = UFG::qVector3::msZero.x;
    v18 = UFG::qVector3::msZero.z;
    result->y = v17;
    result->z = v18;
  }
  return v11;
}

// File Line: 488
// RVA: 0x23C4E0
UFG::qVector3 *__fastcall UFG::RegionComponent::GetAspectNormal(UFG::RegionComponent *this, UFG::qVector3 *result, unsigned int aspect)
{
  UFG::TransformNodeComponent *v3; // rsi
  unsigned int v4; // ebp
  UFG::qVector3 *v5; // rdi
  UFG::RegionBase *v6; // rbx
  float *v7; // rax
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  UFG::qVector3 *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  char v23; // [rsp+20h] [rbp-28h]

  v3 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v4 = aspect;
  v5 = result;
  if ( v3 )
    v3 = (UFG::TransformNodeComponent *)v3->mChildren.mNode.mNext;
  if ( v3 )
  {
    v6 = this->mpRegion.mPtr;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v7 = (float *)v6->vfptr->GetAspectNormal(v6, (UFG::qVector3 *)&v23, v4);
    v8 = *v7;
    v9 = v7[1];
    v10 = v7[2];
    v11 = v5;
    v12 = v8;
    v13 = v8;
    v14 = v8 * v3->mWorldTransform.v0.z;
    v15 = v13 * v3->mWorldTransform.v0.y;
    v16 = (float)(v9 * v3->mWorldTransform.v1.x) + (float)(v12 * v3->mWorldTransform.v0.x);
    v17 = v9;
    v18 = v9 * v3->mWorldTransform.v1.z;
    v19 = v17 * v3->mWorldTransform.v1.y;
    v5->x = v16 + (float)(v10 * v3->mWorldTransform.v2.x);
    v20 = (float)(v15 + v19) + (float)(v10 * v3->mWorldTransform.v2.y);
    v5->z = (float)(v14 + v18) + (float)(v10 * v3->mWorldTransform.v2.z);
    v5->y = v20;
  }
  else
  {
    v21 = UFG::qVector3::msDirFront.y;
    v11 = result;
    result->x = UFG::qVector3::msDirFront.x;
    v22 = UFG::qVector3::msDirFront.z;
    result->y = v21;
    result->z = v22;
  }
  return v11;
}

// File Line: 508
// RVA: 0x23F410
bool __fastcall UFG::RegionComponent::IsHitAspect(UFG::RegionComponent *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, unsigned int *pHitAspect)
{
  UFG::TransformNodeComponent *v4; // rbx
  unsigned int *v5; // r14
  UFG::qVector3 *v6; // rsi
  UFG::qVector3 *v7; // rbp
  UFG::RegionComponent *v8; // rdi
  UFG::RegionBase *v9; // rcx
  float v10; // xmm4_4
  float v11; // xmm6_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm9_4
  float v15; // xmm4_4
  float v16; // xmm9_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v24; // [rsp+20h] [rbp-88h]
  float v25; // [rsp+24h] [rbp-84h]
  float v26; // [rsp+28h] [rbp-80h]
  float v27; // [rsp+2Ch] [rbp-7Ch]
  float v28; // [rsp+30h] [rbp-78h]
  float v29; // [rsp+34h] [rbp-74h]
  UFG::qMatrix44 d; // [rsp+40h] [rbp-68h]

  v4 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v5 = pHitAspect;
  v6 = rayDir;
  v7 = rayPos;
  v8 = this;
  if ( v4 )
    v4 = (UFG::TransformNodeComponent *)v4->mChildren.mNode.mNext;
  if ( !v4 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  UFG::qInverseAffine(&d, &v4->mWorldTransform);
  v9 = v8->mpRegion.mPtr;
  v10 = v7->y;
  v11 = v7->z;
  v12 = d.v1.y * v10;
  v13 = d.v1.z * v10;
  v14 = d.v1.x * v10;
  v15 = v6->y;
  v16 = (float)((float)(v14 + (float)(d.v0.x * v7->x)) + (float)(d.v2.x * v11)) + d.v3.x;
  v17 = v6->z;
  v18 = d.v2.z * v11;
  v19 = (float)((float)(v12 + (float)(d.v0.y * v7->x)) + (float)(d.v2.y * v11)) + d.v3.y;
  v20 = v6->x;
  v21 = v6->y * d.v1.x;
  v22 = (float)(v13 + (float)(d.v0.z * v7->x)) + v18;
  v28 = v19;
  v27 = v16;
  v29 = v22 + d.v3.z;
  v24 = (float)((float)(v20 * d.v0.x) + v21) + (float)(v17 * d.v2.x);
  v25 = (float)((float)(v20 * d.v0.y) + (float)(v15 * d.v1.y)) + (float)(v17 * d.v2.y);
  v26 = (float)((float)(v20 * d.v0.z) + (float)(v15 * d.v1.z)) + (float)(v17 * d.v2.z);
  return ((__int64 (__fastcall *)(UFG::RegionBase *, float *, float *, unsigned int *, _QWORD, _QWORD, _QWORD))v9->vfptr->IsHitAspect)(
           v9,
           &v27,
           &v24,
           v5,
           *(_QWORD *)&v24,
           *(_QWORD *)&v26,
           *(_QWORD *)&v28);
}

// File Line: 536
// RVA: 0x246100
void __fastcall UFG::RegionComponent::TranslateAspect(UFG::RegionComponent *this, unsigned int aspect, UFG::qVector3 *delta)
{
  UFG::TransformNodeComponent *v3; // rbx
  UFG::qVector3 *v4; // rsi
  unsigned int v5; // ebp
  UFG::RegionComponent *v6; // rdi
  UFG::RegionBase *v7; // rcx
  float v8; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // [rsp+20h] [rbp-68h]
  float v15; // [rsp+24h] [rbp-64h]
  float v16; // [rsp+28h] [rbp-60h]
  UFG::qMatrix44 d; // [rsp+30h] [rbp-58h]

  v3 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v4 = delta;
  v5 = aspect;
  v6 = this;
  if ( v3 )
    v3 = (UFG::TransformNodeComponent *)v3->mChildren.mNode.mNext;
  if ( v3 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    UFG::qInverseAffine(&d, &v3->mWorldTransform);
    v7 = v6->mpRegion.mPtr;
    v8 = v4->x;
    v9 = v4->z;
    v10 = v4->x;
    v11 = v4->y * d.v1.y;
    v12 = v4->y * d.v1.z;
    v13 = v4->z;
    v14 = (float)((float)(v4->x * d.v0.x) + (float)(v4->y * d.v1.x)) + (float)(v4->z * d.v2.x);
    v15 = (float)((float)(v10 * d.v0.y) + v11) + (float)(v13 * d.v2.y);
    v16 = (float)((float)(v8 * d.v0.z) + v12) + (float)(v9 * d.v2.z);
    v7->vfptr->TranslateAspect(v7, v5, (UFG::qVector3 *)&v14);
  }
}

// File Line: 559
// RVA: 0x2439E0
void __fastcall UFG::RegionComponent::PropertiesLoad(UFG::RegionComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // r13
  UFG::RegionComponent *v3; // r14
  UFG::RegionBase *v4; // rdi
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *v6; // rbp
  unsigned int *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::RegionBase *v9; // rax
  float *v10; // r15
  float *v11; // rsi
  float *v12; // rbx
  UFG::allocator::free_link *v13; // rax
  float v14; // xmm2_4
  float v15; // xmm1_4
  int v16; // xmm0_4
  UFG::allocator::free_link *v17; // rsi
  UFG::qVector3 *v18; // rbx
  UFG::qVector3 *v19; // rax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  UFG::allocator::free_link *v26; // rbx
  __int128 v27; // xmm0
  UFG::RegionBase *v28; // rcx
  UFG::SimObjectModifier v29; // [rsp+28h] [rbp-50h]

  v2 = pSceneObj;
  v3 = this;
  v4 = 0i64;
  v5 = PropertyUtils::Get<UFG::qPropertySet>(pSceneObj, (UFG::qSymbol *)&SimSymX_propset_componentRegion.mUID);
  v6 = v5;
  v7 = UFG::qPropertySet::Get<unsigned long>(v5, (UFG::qSymbol *)&SimSym_Type.mUID, DEPTH_RECURSE);
  switch ( *v7 )
  {
    case 2u:
      v26 = UFG::qMalloc(0x18ui64, "RegionSphere", 0i64);
      if ( v26 )
      {
        v27 = *(unsigned int *)UFG::qPropertySet::Get<float>(v6, (UFG::qSymbol *)&SimSym_Radius.mUID, DEPTH_RECURSE);
        v26->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable';
        LODWORD(v26[1].mNext) = 0;
        v26->mNext = (UFG::allocator::free_link *)&UFG::RegionSphere::`vftable';
        LODWORD(v26[2].mNext) = v27;
        v4 = (UFG::RegionBase *)v26;
      }
      break;
    case 3u:
      v17 = UFG::qMalloc(0x28ui64, "RegionBox", 0i64);
      if ( v17 )
      {
        v18 = UFG::qPropertySet::Get<UFG::qVector3>(v6, (UFG::qSymbol *)&SimSym_Max.mUID, DEPTH_RECURSE);
        v19 = UFG::qPropertySet::Get<UFG::qVector3>(v6, (UFG::qSymbol *)&SimSym_Min.mUID, DEPTH_RECURSE);
        v20 = v19->x;
        v21 = v19->y;
        v22 = v19->z;
        v23 = v18->x;
        v24 = v18->y;
        v25 = v18->z;
        v17->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable';
        LODWORD(v17[1].mNext) = 0;
        v17->mNext = (UFG::allocator::free_link *)&UFG::RegionBox::`vftable';
        *(float *)&v17[2].mNext = v20;
        *((float *)&v17[2].mNext + 1) = v21;
        *(float *)&v17[3].mNext = v22;
        *((float *)&v17[3].mNext + 1) = v23;
        *(float *)&v17[4].mNext = v24;
        *((float *)&v17[4].mNext + 1) = v25;
        v4 = (UFG::RegionBase *)v17;
      }
      break;
    case 6u:
      v10 = UFG::qPropertySet::Get<float>(v6, (UFG::qSymbol *)&SimSym_Radius.mUID, DEPTH_RECURSE);
      v11 = UFG::qPropertySet::Get<float>(v6, (UFG::qSymbol *)&SimSym_ExtentAbove.mUID, DEPTH_RECURSE);
      v12 = UFG::qPropertySet::Get<float>(v6, (UFG::qSymbol *)&SimSym_ExtentBelow.mUID, DEPTH_RECURSE);
      v13 = UFG::qMalloc(0x20ui64, "RegionDisc", 0i64);
      if ( v13 )
      {
        if ( v12 )
          v14 = *v12;
        else
          v14 = FLOAT_N0_25;
        if ( v11 )
          v15 = *v11;
        else
          v15 = FLOAT_1_75;
        if ( v10 )
          v16 = *(_DWORD *)v10;
        else
          v16 = (signed int)FLOAT_1_0;
        v13->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable';
        LODWORD(v13[1].mNext) = 0;
        v13->mNext = (UFG::allocator::free_link *)&UFG::RegionDisc::`vftable';
        LODWORD(v13[2].mNext) = v16;
        *((float *)&v13[2].mNext + 1) = v15;
        *(float *)&v13[3].mNext = v14;
        v4 = (UFG::RegionBase *)v13;
      }
      break;
    case 8u:
      v8 = UFG::qMalloc(0x58ui64, "RegionPolygon", 0i64);
      if ( v8 )
      {
        UFG::RegionPolygon::RegionPolygon((UFG::RegionPolygon *)v8, v6);
        v4 = v9;
      }
      break;
  }
  v28 = v3->mpRegion.mPtr;
  if ( v4 != v28 )
  {
    if ( v28 )
    {
      if ( --v28->mRefCount <= 0 )
        v28->vfptr->__vecDelDtor(v28, 1u);
    }
    v3->mpRegion.mPtr = v4;
    if ( v4 )
      ++v4->mRefCount;
  }
  if ( !v3->m_pSimObject )
  {
    UFG::SimObjectModifier::SimObjectModifier(&v29, v2->m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v29, (UFG::SimComponent *)&v3->vfptr, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v29);
    UFG::SimObjectModifier::~SimObjectModifier(&v29);
  }
}

// File Line: 612
// RVA: 0x2442B0
void __fastcall UFG::RegionComponent::PropertiesSave(UFG::RegionComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::RegionPolygon *v2; // rsi
  UFG::SceneObjectProperties *v3; // rbp
  unsigned int v4; // eax
  UFG::qPropertySet *v5; // rcx
  unsigned int v6; // ebx
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rdi
  unsigned int *v9; // rax
  UFG::qPropertySet *v10; // r14
  UFG::qPropertySet *v11; // rax
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  UFG::qStaticSymbol *v15; // rdx
  float v16; // xmm2_4

  v2 = (UFG::RegionPolygon *)this->mpRegion.mPtr;
  v3 = pSceneObj;
  v4 = v2->vfptr->GetType((UFG::RegionBase *)&v2->vfptr);
  v5 = v3->mpConstProperties;
  v6 = v4;
  if ( !v5 )
    v5 = v3->mpWritableProperties;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(v5, (UFG::qSymbol *)&SimSymX_propset_componentRegion.mUID, 0);
  v8 = v7;
  if ( v7 )
  {
    v9 = UFG::qPropertySet::Get<unsigned long>(v7, (UFG::qSymbol *)&SimSym_Type.mUID, DEPTH_RECURSE);
    if ( v9 && *v9 != v6 )
      UFG::qPropertySet::RemovePropertiesAllLocal(v8);
  }
  else
  {
    v10 = v3->mpConstProperties;
    if ( !v10 )
      v10 = v3->mpWritableProperties;
    v8 = UFG::qPropertySet::CreateContainedSet(&UFG::gNullQSymbol, "RegionCompPS");
    v11 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&SimSymX_propset_componentRegion.mUID);
    UFG::PSWrapper::AppendParentLocal(v8, v11);
    UFG::qPropertySet::Set<UFG::qPropertySet>(v10, (UFG::qSymbol *)&SimSymX_propset_componentRegion.mUID, v8);
  }
  UFG::qPropertySet::Set<unsigned long>(v8, (UFG::qSymbol *)&SimSym_Type.mUID, v6);
  v12 = v6 - 2;
  if ( !v12 )
  {
    v16 = *(float *)&v2->mpVerts;
    v15 = &SimSym_Radius;
    goto LABEL_18;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    UFG::qPropertySet::Set<UFG::qVector3>(v8, (UFG::qSymbol *)&SimSym_Min.mUID, (UFG::qVector3 *)&v2->mpVerts);
    UFG::qPropertySet::Set<UFG::qVector3>(v8, (UFG::qSymbol *)&SimSym_Max.mUID, (UFG::qVector3 *)&v2->mExtentAbove);
    return;
  }
  v14 = v13 - 3;
  if ( !v14 )
  {
    UFG::qPropertySet::Set<float>(v8, (UFG::qSymbol *)&SimSym_Radius.mUID, *(float *)&v2->mpVerts);
    UFG::qPropertySet::Set<float>(v8, (UFG::qSymbol *)&SimSym_ExtentAbove.mUID, *((float *)&v2->mpVerts + 1));
    v15 = &SimSym_ExtentBelow;
    v16 = *(float *)&v2->mVertCount;
LABEL_18:
    UFG::qPropertySet::Set<float>(v8, (UFG::qSymbol *)&v15->mUID, v16);
    return;
  }
  if ( v14 == 2 )
    UFG::RegionPolygon::PropertiesSave(v2, v8);
}

// File Line: 664
// RVA: 0x23E430
bool __fastcall UFG::RegionComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::PropertyExists(pSceneObj, (UFG::qSymbol *)&SimSymX_propset_componentRegion.mUID);
}

// File Line: 681
// RVA: 0x244170
UFG::RegionComponent *__fastcall UFG::RegionComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::qSymbol *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v9; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x78ui64, "RegionComponent", 0i64, 1u);
  v9 = v3;
  if ( v3 )
  {
    v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v1->m_NameUID);
    UFG::RegionComponent::RegionComponent((UFG::RegionComponent *)v3, v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  (*(void (__fastcall **)(__int64, UFG::SceneObjectProperties *))(*(_QWORD *)v6 + 96i64))(v6, v1);
  return (UFG::RegionComponent *)v6;
}

// File Line: 693
// RVA: 0x243980
UFG::qPropertySet *__fastcall UFG::RegionComponent::PropertiesAppendDefaultProperty(UFG::qPropertySet *pProps)
{
  UFG::qPropertySet *v1; // rdi
  UFG::qPropertySet *v2; // rbx
  UFG::qPropertySet *v3; // rax

  v1 = pProps;
  v2 = UFG::qPropertySet::CreateContainedSet(&UFG::gNullQSymbol, "RegionCompPS");
  v3 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&SimSymX_propset_componentRegion.mUID);
  UFG::PSWrapper::AppendParentLocal(v2, v3);
  UFG::qPropertySet::Set<UFG::qPropertySet>(v1, (UFG::qSymbol *)&SimSymX_propset_componentRegion.mUID, v2);
  return v2;
}

