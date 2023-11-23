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
  UFG::SimComponent::SimComponent(this, name->mUID);
  this->i_name = (UFG::qSymbol)name->mUID;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HintComponentBase::`vftable;
  this->UFG::HintComponentBase::mFlags = 0;
  UFG::SimComponent::AddType(this, UFG::HintComponentBase::_HintComponentBaseTypeUID, "HintComponentBase");
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RegionComponent::`vftable;
  this->mFlags = 0;
  this->mpRegion.mPtr = 0i64;
  this->mXFormChangeCacheID = -1;
  *(_QWORD *)&this->mCachedAABB.mMin.x = 0i64;
  *(_QWORD *)&this->mCachedAABB.mMin.z = 0i64;
  *(_QWORD *)&this->mCachedAABB.mMax.y = 0i64;
  UFG::SimComponent::AddType(this, UFG::RegionComponent::_RegionComponentTypeUID, "RegionComponent");
}

// File Line: 181
// RVA: 0x23D220
void __fastcall UFG::RegionComponent::GetCenter(UFG::RegionComponent *this, UFG::qVector3 *pPos)
{
  UFG::TransformNodeComponent *m_pSimObject; // rdi
  float y; // xmm2_4
  float z; // xmm1_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( m_pSimObject )
  {
    (*((void (__fastcall **)(UFG::RegionBase *))&this->mpRegion.mPtr->vfptr->__vecDelDtor + 3))(this->mpRegion.mPtr);
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
    y = pPos->y;
    z = pPos->z;
    v6 = (float)((float)((float)(y * m_pSimObject->mWorldTransform.v1.x)
                       + (float)(pPos->x * m_pSimObject->mWorldTransform.v0.x))
               + (float)(z * m_pSimObject->mWorldTransform.v2.x))
       + m_pSimObject->mWorldTransform.v3.x;
    v7 = (float)((float)((float)(y * m_pSimObject->mWorldTransform.v1.z)
                       + (float)(pPos->x * m_pSimObject->mWorldTransform.v0.z))
               + (float)(z * m_pSimObject->mWorldTransform.v2.z))
       + m_pSimObject->mWorldTransform.v3.z;
    v8 = (float)((float)((float)(y * m_pSimObject->mWorldTransform.v1.y)
                       + (float)(pPos->x * m_pSimObject->mWorldTransform.v0.y))
               + (float)(z * m_pSimObject->mWorldTransform.v2.y))
       + m_pSimObject->mWorldTransform.v3.y;
    pPos->x = v6;
    pPos->z = v7;
    pPos->y = v8;
  }
  else
  {
    v9 = UFG::qVector3::msZero.y;
    v10 = UFG::qVector3::msZero.z;
    pPos->x = UFG::qVector3::msZero.x;
    pPos->y = v9;
    pPos->z = v10;
  }
}

// File Line: 200
// RVA: 0x23C860
void __fastcall UFG::RegionComponent::GetBoundingBox(UFG::RegionComponent *this, UFG::qBox *pBox)
{
  UFG::TransformNodeComponent *m_pSimObject; // rdi
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
  float x; // xmm0_4
  float v17; // xmm3_4
  float y; // xmm0_4
  float z; // xmm1_4
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
  __int64 v84; // [rsp+20h] [rbp-68h] BYREF
  __int64 v85; // [rsp+28h] [rbp-60h]
  __int64 v86; // [rsp+30h] [rbp-58h]

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( m_pSimObject && m_pSimObject->mChangeID != this->mXFormChangeCacheID )
  {
    v84 = 0i64;
    v85 = 0i64;
    v86 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
    this->mpRegion.mPtr->vfptr->GetBoundingBox(this->mpRegion.mPtr, (UFG::qBox *)&v84);
    v5 = *((float *)&v84 + 1);
    v6 = *(float *)&v85;
    v7 = *(float *)&v84;
    v8 = *((float *)&v85 + 1);
    v9 = (float)((float)((float)(*((float *)&v84 + 1) * m_pSimObject->mWorldTransform.v1.x)
                       + (float)(*(float *)&v84 * m_pSimObject->mWorldTransform.v0.x))
               + (float)(*(float *)&v85 * m_pSimObject->mWorldTransform.v2.x))
       + m_pSimObject->mWorldTransform.v3.x;
    v10 = (float)((float)((float)(*(float *)&v84 * m_pSimObject->mWorldTransform.v0.y)
                        + (float)(*((float *)&v84 + 1) * m_pSimObject->mWorldTransform.v1.y))
                + (float)(*(float *)&v85 * m_pSimObject->mWorldTransform.v2.y))
        + m_pSimObject->mWorldTransform.v3.y;
    v11 = *((float *)&v85 + 1);
    v12 = *(float *)&v85;
    v13 = (float)((float)((float)(*(float *)&v84 * m_pSimObject->mWorldTransform.v0.z)
                        + (float)(*((float *)&v84 + 1) * m_pSimObject->mWorldTransform.v1.z))
                + (float)(*(float *)&v85 * m_pSimObject->mWorldTransform.v2.z))
        + m_pSimObject->mWorldTransform.v3.z;
    this->mCachedAABB.mMin.x = v9;
    this->mCachedAABB.mMin.y = v10;
    this->mCachedAABB.mMin.z = v13;
    this->mCachedAABB.mMax.x = v9;
    this->mCachedAABB.mMax.y = v10;
    this->mCachedAABB.mMax.z = v13;
    v14 = (float)((float)((float)(v5 * m_pSimObject->mWorldTransform.v1.x)
                        + (float)(v11 * m_pSimObject->mWorldTransform.v0.x))
                + (float)(v12 * m_pSimObject->mWorldTransform.v2.x))
        + m_pSimObject->mWorldTransform.v3.x;
    v15 = (float)((float)((float)(v8 * m_pSimObject->mWorldTransform.v0.y)
                        + (float)(v5 * m_pSimObject->mWorldTransform.v1.y))
                + (float)(v6 * m_pSimObject->mWorldTransform.v2.y))
        + m_pSimObject->mWorldTransform.v3.y;
    x = this->mCachedAABB.mMin.x;
    v17 = (float)((float)((float)(v8 * m_pSimObject->mWorldTransform.v0.z)
                        + (float)(v5 * m_pSimObject->mWorldTransform.v1.z))
                + (float)(v6 * m_pSimObject->mWorldTransform.v2.z))
        + m_pSimObject->mWorldTransform.v3.z;
    if ( x >= v14 )
      x = v14;
    this->mCachedAABB.mMin.x = x;
    y = this->mCachedAABB.mMin.y;
    if ( y >= v15 )
      y = v15;
    this->mCachedAABB.mMin.y = y;
    z = this->mCachedAABB.mMin.z;
    if ( z >= v17 )
      z = v17;
    this->mCachedAABB.mMin.z = z;
    v20 = this->mCachedAABB.mMax.x;
    if ( v20 <= v14 )
      v20 = v14;
    this->mCachedAABB.mMax.x = v20;
    v21 = this->mCachedAABB.mMax.y;
    if ( v21 <= v15 )
      v21 = v15;
    this->mCachedAABB.mMax.y = v21;
    v22 = this->mCachedAABB.mMax.z;
    if ( v22 <= v17 )
      v22 = v17;
    v23 = *(float *)&v86;
    this->mCachedAABB.mMax.z = v22;
    v24 = (float)((float)((float)(v23 * m_pSimObject->mWorldTransform.v1.x)
                        + (float)(v7 * m_pSimObject->mWorldTransform.v0.x))
                + (float)(v6 * m_pSimObject->mWorldTransform.v2.x))
        + m_pSimObject->mWorldTransform.v3.x;
    v25 = (float)((float)((float)(v7 * m_pSimObject->mWorldTransform.v0.y)
                        + (float)(v23 * m_pSimObject->mWorldTransform.v1.y))
                + (float)(v6 * m_pSimObject->mWorldTransform.v2.y))
        + m_pSimObject->mWorldTransform.v3.y;
    v26 = this->mCachedAABB.mMin.x;
    v27 = (float)((float)((float)(v7 * m_pSimObject->mWorldTransform.v0.z)
                        + (float)(v23 * m_pSimObject->mWorldTransform.v1.z))
                + (float)(v6 * m_pSimObject->mWorldTransform.v2.z))
        + m_pSimObject->mWorldTransform.v3.z;
    if ( v26 >= v24 )
      v26 = (float)((float)((float)(v23 * m_pSimObject->mWorldTransform.v1.x)
                          + (float)(v7 * m_pSimObject->mWorldTransform.v0.x))
                  + (float)(v6 * m_pSimObject->mWorldTransform.v2.x))
          + m_pSimObject->mWorldTransform.v3.x;
    this->mCachedAABB.mMin.x = v26;
    v28 = this->mCachedAABB.mMin.y;
    if ( v28 >= v25 )
      v28 = v25;
    this->mCachedAABB.mMin.y = v28;
    v29 = this->mCachedAABB.mMin.z;
    if ( v29 >= v27 )
      v29 = v27;
    this->mCachedAABB.mMin.z = v29;
    v30 = this->mCachedAABB.mMax.x;
    if ( v30 <= v24 )
      v30 = v24;
    this->mCachedAABB.mMax.x = v30;
    v31 = this->mCachedAABB.mMax.y;
    if ( v31 <= v25 )
      v31 = v25;
    this->mCachedAABB.mMax.y = v31;
    v32 = this->mCachedAABB.mMax.z;
    if ( v32 <= v27 )
      v32 = v27;
    this->mCachedAABB.mMax.z = v32;
    v33 = (float)((float)((float)(v23 * m_pSimObject->mWorldTransform.v1.x)
                        + (float)(v8 * m_pSimObject->mWorldTransform.v0.x))
                + (float)(v6 * m_pSimObject->mWorldTransform.v2.x))
        + m_pSimObject->mWorldTransform.v3.x;
    v34 = (float)((float)((float)(v8 * m_pSimObject->mWorldTransform.v0.y)
                        + (float)(v23 * m_pSimObject->mWorldTransform.v1.y))
                + (float)(v6 * m_pSimObject->mWorldTransform.v2.y))
        + m_pSimObject->mWorldTransform.v3.y;
    v35 = this->mCachedAABB.mMin.x;
    v36 = (float)((float)((float)(v8 * m_pSimObject->mWorldTransform.v0.z)
                        + (float)(v23 * m_pSimObject->mWorldTransform.v1.z))
                + (float)(v6 * m_pSimObject->mWorldTransform.v2.z))
        + m_pSimObject->mWorldTransform.v3.z;
    if ( v35 >= v33 )
      v35 = (float)((float)((float)(v23 * m_pSimObject->mWorldTransform.v1.x)
                          + (float)(v8 * m_pSimObject->mWorldTransform.v0.x))
                  + (float)(v6 * m_pSimObject->mWorldTransform.v2.x))
          + m_pSimObject->mWorldTransform.v3.x;
    this->mCachedAABB.mMin.x = v35;
    v37 = this->mCachedAABB.mMin.y;
    if ( v37 >= v34 )
      v37 = v34;
    this->mCachedAABB.mMin.y = v37;
    v38 = this->mCachedAABB.mMin.z;
    if ( v38 >= v36 )
      v38 = v36;
    this->mCachedAABB.mMin.z = v38;
    v39 = this->mCachedAABB.mMax.x;
    if ( v39 <= v33 )
      v39 = v33;
    this->mCachedAABB.mMax.x = v39;
    v40 = this->mCachedAABB.mMax.y;
    if ( v40 <= v34 )
      v40 = v34;
    this->mCachedAABB.mMax.y = v40;
    v41 = this->mCachedAABB.mMax.z;
    if ( v41 <= v36 )
      v41 = v36;
    v42 = *((float *)&v86 + 1);
    this->mCachedAABB.mMax.z = v41;
    v43 = (float)((float)((float)(v5 * m_pSimObject->mWorldTransform.v1.x)
                        + (float)(v7 * m_pSimObject->mWorldTransform.v0.x))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.x))
        + m_pSimObject->mWorldTransform.v3.x;
    v44 = this->mCachedAABB.mMin.x;
    v45 = (float)((float)((float)(v7 * m_pSimObject->mWorldTransform.v0.y)
                        + (float)(v5 * m_pSimObject->mWorldTransform.v1.y))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.y))
        + m_pSimObject->mWorldTransform.v3.y;
    v46 = (float)((float)((float)(v7 * m_pSimObject->mWorldTransform.v0.z)
                        + (float)(v5 * m_pSimObject->mWorldTransform.v1.z))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.z))
        + m_pSimObject->mWorldTransform.v3.z;
    if ( v44 >= v43 )
      v44 = (float)((float)((float)(v5 * m_pSimObject->mWorldTransform.v1.x)
                          + (float)(v7 * m_pSimObject->mWorldTransform.v0.x))
                  + (float)(v42 * m_pSimObject->mWorldTransform.v2.x))
          + m_pSimObject->mWorldTransform.v3.x;
    this->mCachedAABB.mMin.x = v44;
    v47 = this->mCachedAABB.mMin.y;
    if ( v47 >= v45 )
      v47 = v45;
    this->mCachedAABB.mMin.y = v47;
    v48 = this->mCachedAABB.mMin.z;
    if ( v48 >= v46 )
      v48 = v46;
    this->mCachedAABB.mMin.z = v48;
    v49 = this->mCachedAABB.mMax.x;
    if ( v49 <= v43 )
      v49 = v43;
    this->mCachedAABB.mMax.x = v49;
    v50 = this->mCachedAABB.mMax.y;
    if ( v50 <= v45 )
      v50 = v45;
    this->mCachedAABB.mMax.y = v50;
    v51 = this->mCachedAABB.mMax.z;
    if ( v51 <= v46 )
      v51 = v46;
    this->mCachedAABB.mMax.z = v51;
    v52 = (float)((float)((float)(v5 * m_pSimObject->mWorldTransform.v1.x)
                        + (float)(v8 * m_pSimObject->mWorldTransform.v0.x))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.x))
        + m_pSimObject->mWorldTransform.v3.x;
    v53 = (float)((float)((float)(v8 * m_pSimObject->mWorldTransform.v0.y)
                        + (float)(v5 * m_pSimObject->mWorldTransform.v1.y))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.y))
        + m_pSimObject->mWorldTransform.v3.y;
    v54 = this->mCachedAABB.mMin.x;
    v55 = (float)((float)((float)(v8 * m_pSimObject->mWorldTransform.v0.z)
                        + (float)(v5 * m_pSimObject->mWorldTransform.v1.z))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.z))
        + m_pSimObject->mWorldTransform.v3.z;
    if ( v54 >= v52 )
      v54 = (float)((float)((float)(v5 * m_pSimObject->mWorldTransform.v1.x)
                          + (float)(v8 * m_pSimObject->mWorldTransform.v0.x))
                  + (float)(v42 * m_pSimObject->mWorldTransform.v2.x))
          + m_pSimObject->mWorldTransform.v3.x;
    this->mCachedAABB.mMin.x = v54;
    v56 = this->mCachedAABB.mMin.y;
    if ( v56 >= v53 )
      v56 = v53;
    this->mCachedAABB.mMin.y = v56;
    v57 = this->mCachedAABB.mMin.z;
    if ( v57 >= v55 )
      v57 = v55;
    this->mCachedAABB.mMin.z = v57;
    v58 = this->mCachedAABB.mMax.x;
    if ( v58 <= v52 )
      v58 = v52;
    this->mCachedAABB.mMax.x = v58;
    v59 = this->mCachedAABB.mMax.y;
    if ( v59 <= v53 )
      v59 = v53;
    this->mCachedAABB.mMax.y = v59;
    v60 = this->mCachedAABB.mMax.z;
    if ( v60 <= v55 )
      v60 = v55;
    this->mCachedAABB.mMax.z = v60;
    v61 = (float)((float)((float)(v23 * m_pSimObject->mWorldTransform.v1.x)
                        + (float)(v7 * m_pSimObject->mWorldTransform.v0.x))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.x))
        + m_pSimObject->mWorldTransform.v3.x;
    v62 = (float)((float)((float)(v7 * m_pSimObject->mWorldTransform.v0.y)
                        + (float)(v23 * m_pSimObject->mWorldTransform.v1.y))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.y))
        + m_pSimObject->mWorldTransform.v3.y;
    v63 = this->mCachedAABB.mMin.x;
    v64 = (float)((float)((float)(v7 * m_pSimObject->mWorldTransform.v0.z)
                        + (float)(v23 * m_pSimObject->mWorldTransform.v1.z))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.z))
        + m_pSimObject->mWorldTransform.v3.z;
    if ( v63 >= v61 )
      v63 = v61;
    this->mCachedAABB.mMin.x = v63;
    v65 = this->mCachedAABB.mMin.y;
    if ( v65 >= v62 )
      v65 = v62;
    this->mCachedAABB.mMin.y = v65;
    v66 = v57;
    if ( v57 >= v64 )
      v66 = v64;
    this->mCachedAABB.mMin.z = v66;
    v67 = this->mCachedAABB.mMax.x;
    if ( v67 <= v61 )
      v67 = v61;
    this->mCachedAABB.mMax.x = v67;
    v68 = this->mCachedAABB.mMax.y;
    if ( v68 <= v62 )
      v68 = v62;
    this->mCachedAABB.mMax.y = v68;
    v69 = this->mCachedAABB.mMax.z;
    if ( v69 <= v64 )
      v69 = v64;
    this->mCachedAABB.mMax.z = v69;
    v70 = (float)((float)((float)(v23 * m_pSimObject->mWorldTransform.v1.x)
                        + (float)(v8 * m_pSimObject->mWorldTransform.v0.x))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.x))
        + m_pSimObject->mWorldTransform.v3.x;
    v71 = (float)(v8 * m_pSimObject->mWorldTransform.v0.y) + (float)(v23 * m_pSimObject->mWorldTransform.v1.y);
    v72 = this->mCachedAABB.mMin.x;
    v73 = (float)((float)((float)(v8 * m_pSimObject->mWorldTransform.v0.z)
                        + (float)(v23 * m_pSimObject->mWorldTransform.v1.z))
                + (float)(v42 * m_pSimObject->mWorldTransform.v2.z))
        + m_pSimObject->mWorldTransform.v3.z;
    v74 = (float)(v71 + (float)(v42 * m_pSimObject->mWorldTransform.v2.y)) + m_pSimObject->mWorldTransform.v3.y;
    if ( v72 >= v70 )
      v72 = v70;
    this->mCachedAABB.mMin.x = v72;
    v75 = this->mCachedAABB.mMin.y;
    if ( v75 >= v74 )
      v75 = v74;
    this->mCachedAABB.mMin.y = v75;
    v76 = this->mCachedAABB.mMin.z;
    if ( v76 >= v73 )
      v76 = v73;
    this->mCachedAABB.mMin.z = v76;
    v77 = this->mCachedAABB.mMax.x;
    if ( v77 <= v70 )
      v77 = v70;
    this->mCachedAABB.mMax.x = v77;
    v78 = this->mCachedAABB.mMax.y;
    if ( v78 <= v74 )
      v78 = v74;
    this->mCachedAABB.mMax.y = v78;
    v79 = this->mCachedAABB.mMax.z;
    if ( v79 <= v73 )
      v79 = v73;
    this->mCachedAABB.mMax.z = v79;
    this->mXFormChangeCacheID = m_pSimObject->mChangeID;
  }
  v80 = this->mCachedAABB.mMin.y;
  v81 = this->mCachedAABB.mMin.z;
  pBox->mMin.x = this->mCachedAABB.mMin.x;
  pBox->mMin.y = v80;
  pBox->mMin.z = v81;
  v82 = this->mCachedAABB.mMax.y;
  v83 = this->mCachedAABB.mMax.z;
  pBox->mMax.x = this->mCachedAABB.mMax.x;
  pBox->mMax.y = v82;
  pBox->mMax.z = v83;
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
  UFG::TransformNodeComponent *m_pSimObject; // rsi
  UFG::RegionBase *mPtr; // rbx
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
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 v17; // [rsp+20h] [rbp-28h] BYREF

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( m_pSimObject )
  {
    mPtr = this->mpRegion.mPtr;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
    v5 = (float *)mPtr->vfptr->GetRandomPosition(mPtr, &v17);
    v6 = v5[1];
    v7 = *v5;
    v8 = v5[2];
    v9 = result;
    v10 = v6;
    v11 = (float)((float)(v6 * m_pSimObject->mWorldTransform.v1.x) + (float)(v7 * m_pSimObject->mWorldTransform.v0.x))
        + (float)(v8 * m_pSimObject->mWorldTransform.v2.x);
    v12 = (float)(v6 * m_pSimObject->mWorldTransform.v1.z) + (float)(v7 * m_pSimObject->mWorldTransform.v0.z);
    v13 = (float)(v10 * m_pSimObject->mWorldTransform.v1.y) + (float)(v7 * m_pSimObject->mWorldTransform.v0.y);
    result->x = v11 + m_pSimObject->mWorldTransform.v3.x;
    v14 = (float)(v13 + (float)(v8 * m_pSimObject->mWorldTransform.v2.y)) + m_pSimObject->mWorldTransform.v3.y;
    result->z = (float)(v12 + (float)(v8 * m_pSimObject->mWorldTransform.v2.z)) + m_pSimObject->mWorldTransform.v3.z;
    result->y = v14;
  }
  else
  {
    y = UFG::qVector3::msZero.y;
    v9 = result;
    result->x = UFG::qVector3::msZero.x;
    z = UFG::qVector3::msZero.z;
    result->y = y;
    result->z = z;
  }
  return v9;
}

// File Line: 263
// RVA: 0x2403E0
bool __fastcall UFG::RegionComponent::IsHitPoint(UFG::RegionComponent *this, UFG::qVector3 *pos)
{
  float y; // xmm0_4
  float z; // xmm0_4
  UFG::TransformNodeComponent *m_pSimObject; // rdi
  UFG::RegionBase *mPtr; // rcx
  float x; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  UFG::qBox pBox; // [rsp+20h] [rbp-19h] BYREF
  UFG::qMatrix44 d; // [rsp+40h] [rbp+7h] BYREF

  memset(&pBox, 0, sizeof(pBox));
  UFG::RegionComponent::GetBoundingBox(this, &pBox);
  if ( pos->x < pBox.mMin.x )
    return 0;
  if ( pos->x > pBox.mMax.x )
    return 0;
  y = pos->y;
  if ( y < pBox.mMin.y )
    return 0;
  if ( y > pBox.mMax.y )
    return 0;
  z = pos->z;
  if ( z < pBox.mMin.z || z > pBox.mMax.z )
    return 0;
  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( !m_pSimObject )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  UFG::qInverseAffine(&d, &m_pSimObject->mWorldTransform);
  mPtr = this->mpRegion.mPtr;
  x = pos->x;
  v9 = pos->y;
  v10 = d.v2.z * pos->z;
  v11 = (float)((float)((float)(d.v1.y * v9) + (float)(d.v0.y * pos->x)) + (float)(d.v2.y * pos->z)) + d.v3.y;
  pBox.mMin.x = (float)((float)((float)(d.v1.x * v9) + (float)(d.v0.x * pos->x)) + (float)(d.v2.x * pos->z)) + d.v3.x;
  pBox.mMin.y = v11;
  pBox.mMin.z = (float)((float)((float)(d.v1.z * v9) + (float)(d.v0.z * x)) + v10) + d.v3.z;
  return mPtr->vfptr->IsHitPoint(mPtr, &pBox.mMin);
}

// File Line: 323
// RVA: 0x241A10
bool __fastcall UFG::RegionComponent::IsHitSegment(
        UFG::RegionComponent *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *pHitPos)
{
  float x; // xmm2_4
  float v9; // xmm6_4
  float y; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float z; // xmm3_4
  float v14; // xmm5_4
  float v15; // xmm8_4
  UFG::SimObject *m_pSimObject; // rdi
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
  UFG::RegionBase *mPtr; // rcx
  float v39; // xmm2_4
  bool result; // al
  float v41; // xmm4_4
  float v42; // xmm6_4
  float v43; // xmm3_4
  float v44; // xmm2_4
  float v45; // xmm2_4
  UFG::qBox pBox; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qMatrix44 m; // [rsp+40h] [rbp-A8h] BYREF
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

  memset(&pBox, 0, sizeof(pBox));
  UFG::RegionComponent::GetBoundingBox(this, &pBox);
  x = start->x;
  if ( start->x >= end->x )
    v9 = end->x;
  else
    v9 = start->x;
  y = start->y;
  v11 = end->y;
  if ( y >= v11 )
    v12 = end->y;
  else
    v12 = start->y;
  z = start->z;
  v14 = end->z;
  if ( z >= v14 )
    v15 = end->z;
  else
    v15 = start->z;
  if ( x <= end->x )
    x = end->x;
  if ( y <= v11 )
    y = end->y;
  if ( z <= v14 )
    z = end->z;
  if ( pBox.mMin.x > x
    || pBox.mMax.x < v9
    || pBox.mMin.y > y
    || pBox.mMax.y < v12
    || pBox.mMin.z > z
    || pBox.mMax.z < v15 )
  {
    return 0;
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
  if ( !m_pSimObject )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  v17 = *((float *)&m_pSimObject[1].vfptr + 1);
  m.v0.x = *(float *)&m_pSimObject[1].vfptr;
  v18 = *(float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
  m.v0.y = v17;
  v19 = *((float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev
        + 1);
  m.v0.z = v18;
  v20 = *(float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
  m.v0.w = v19;
  v21 = *((float *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext
        + 1);
  m.v1.x = v20;
  v22 = *(float *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
  m.v1.y = v21;
  v23 = *((float *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev
        + 1);
  m.v1.z = v22;
  v24 = *(float *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
  m.v1.w = v23;
  v25 = *((float *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext
        + 1);
  m.v2.x = v24;
  v26 = *(float *)&m_pSimObject[1].mNode.mParent;
  m.v2.y = v25;
  v27 = *((float *)&m_pSimObject[1].mNode.mParent + 1);
  m.v2.z = v26;
  v28 = *(float *)m_pSimObject[1].mNode.mChild;
  m.v2.w = v27;
  v29 = *((float *)m_pSimObject[1].mNode.mChild + 1);
  m.v3.x = v28;
  v30 = *(float *)&m_pSimObject[1].mNode.mChild[1];
  m.v3.y = v29;
  v31 = *((float *)&m_pSimObject[1].mNode.mChild[1] + 1);
  m.v3.z = v30;
  m.v3.w = v31;
  UFG::qInverseAffine((UFG::qMatrix44 *)&m.v3.z, &m);
  v32 = end->y;
  v33 = end->z;
  v34 = (float)((float)((float)(v50 * v32) + (float)(m.v3.w * end->x)) + (float)(v53 * v33)) + v56;
  v35 = (float)((float)(v51 * v32) + (float)(v48 * end->x)) + (float)(v54 * v33);
  m.v2.z = (float)((float)((float)(v49 * v32) + (float)(m.v3.z * end->x)) + (float)(v52 * v33)) + v55;
  m.v2.w = v34;
  v36 = start->x;
  v37 = start->y;
  mPtr = this->mpRegion.mPtr;
  m.v3.x = v35 + v57;
  v39 = start->z;
  pBox.mMin.x = (float)((float)((float)(v49 * v37) + (float)(m.v3.z * v36)) + (float)(v52 * v39)) + v55;
  pBox.mMin.y = (float)((float)((float)(v50 * v37) + (float)(m.v3.w * v36)) + (float)(v53 * v39)) + v56;
  pBox.mMin.z = (float)((float)((float)(v51 * v37) + (float)(v48 * v36)) + (float)(v54 * v39)) + v57;
  result = mPtr->vfptr->IsHitSegment(mPtr, &pBox.mMin, (UFG::qVector3 *)&m.v2.z, pHitPos);
  if ( result )
  {
    if ( pHitPos )
    {
      v41 = pHitPos->y;
      v42 = pHitPos->z;
      v43 = (float)((float)((float)(m.v1.y * v41) + (float)(m.v0.y * pHitPos->x)) + (float)(m.v2.y * v42)) + m.v3.y;
      v44 = (float)((float)(m.v1.z * v41) + (float)(m.v0.z * pHitPos->x)) + (float)(m.v2.z * v42);
      pHitPos->x = (float)((float)((float)(m.v1.x * v41) + (float)(m.v0.x * pHitPos->x)) + (float)(m.v2.x * v42))
                 + m.v3.x;
      v45 = v44 + m.v3.z;
      pHitPos->y = v43;
      pHitPos->z = v45;
    }
  }
  return result;
}

// File Line: 454
// RVA: 0x23A7A0
__int64 __fastcall UFG::RegionComponent::CycleAspect(UFG::RegionComponent *this, __int64 aspect, __int64 forward)
{
  return ((__int64 (__fastcall *)(UFG::RegionBase *, __int64, __int64))this->mpRegion.mPtr->vfptr->CycleAspect)(
           this->mpRegion.mPtr,
           aspect,
           forward);
}

// File Line: 463
// RVA: 0x23C470
__int64 __fastcall UFG::RegionComponent::GetAspectDefault(UFG::RegionComponent *this)
{
  return ((__int64 (__fastcall *)(UFG::RegionBase *))this->mpRegion.mPtr->vfptr->GetAspectDefault)(this->mpRegion.mPtr);
}

// File Line: 472
// RVA: 0x23C190
UFG::qVector3 *__fastcall UFG::RegionComponent::GetAspectCenter(
        UFG::RegionComponent *this,
        UFG::qVector3 *result,
        unsigned int aspect)
{
  UFG::TransformNodeComponent *m_pSimObject; // rsi
  UFG::RegionBase *mPtr; // rbx
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
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 v19; // [rsp+20h] [rbp-28h] BYREF

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( m_pSimObject )
  {
    mPtr = this->mpRegion.mPtr;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
    v7 = (float *)mPtr->vfptr->GetAspectCenter(mPtr, &v19, aspect);
    v8 = v7[1];
    v9 = *v7;
    v10 = v7[2];
    v11 = result;
    v12 = v8;
    v13 = (float)((float)(v8 * m_pSimObject->mWorldTransform.v1.x) + (float)(v9 * m_pSimObject->mWorldTransform.v0.x))
        + (float)(v10 * m_pSimObject->mWorldTransform.v2.x);
    v14 = (float)(v8 * m_pSimObject->mWorldTransform.v1.z) + (float)(v9 * m_pSimObject->mWorldTransform.v0.z);
    v15 = (float)(v12 * m_pSimObject->mWorldTransform.v1.y) + (float)(v9 * m_pSimObject->mWorldTransform.v0.y);
    result->x = v13 + m_pSimObject->mWorldTransform.v3.x;
    v16 = (float)(v15 + (float)(v10 * m_pSimObject->mWorldTransform.v2.y)) + m_pSimObject->mWorldTransform.v3.y;
    result->z = (float)(v14 + (float)(v10 * m_pSimObject->mWorldTransform.v2.z)) + m_pSimObject->mWorldTransform.v3.z;
    result->y = v16;
  }
  else
  {
    y = UFG::qVector3::msZero.y;
    v11 = result;
    result->x = UFG::qVector3::msZero.x;
    z = UFG::qVector3::msZero.z;
    result->y = y;
    result->z = z;
  }
  return v11;
}

// File Line: 488
// RVA: 0x23C4E0
UFG::qVector3 *__fastcall UFG::RegionComponent::GetAspectNormal(
        UFG::RegionComponent *this,
        UFG::qVector3 *result,
        unsigned int aspect)
{
  UFG::TransformNodeComponent *m_pSimObject; // rsi
  UFG::RegionBase *mPtr; // rbx
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
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 v23; // [rsp+20h] [rbp-28h] BYREF

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( m_pSimObject )
  {
    mPtr = this->mpRegion.mPtr;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
    v7 = (float *)mPtr->vfptr->GetAspectNormal(mPtr, &v23, aspect);
    v8 = *v7;
    v9 = v7[1];
    v10 = v7[2];
    v11 = result;
    v12 = v8;
    v13 = v8;
    v14 = v8 * m_pSimObject->mWorldTransform.v0.z;
    v15 = v13 * m_pSimObject->mWorldTransform.v0.y;
    v16 = (float)(v9 * m_pSimObject->mWorldTransform.v1.x) + (float)(v12 * m_pSimObject->mWorldTransform.v0.x);
    v17 = v9;
    v18 = v9 * m_pSimObject->mWorldTransform.v1.z;
    v19 = v17 * m_pSimObject->mWorldTransform.v1.y;
    result->x = v16 + (float)(v10 * m_pSimObject->mWorldTransform.v2.x);
    v20 = (float)(v15 + v19) + (float)(v10 * m_pSimObject->mWorldTransform.v2.y);
    result->z = (float)(v14 + v18) + (float)(v10 * m_pSimObject->mWorldTransform.v2.z);
    result->y = v20;
  }
  else
  {
    y = UFG::qVector3::msDirFront.y;
    v11 = result;
    result->x = UFG::qVector3::msDirFront.x;
    z = UFG::qVector3::msDirFront.z;
    result->y = y;
    result->z = z;
  }
  return v11;
}

// File Line: 508
// RVA: 0x23F410
bool __fastcall UFG::RegionComponent::IsHitAspect(
        UFG::RegionComponent *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        unsigned int *pHitAspect)
{
  UFG::TransformNodeComponent *m_pSimObject; // rbx
  UFG::RegionBase *mPtr; // rcx
  float y; // xmm4_4
  float z; // xmm6_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm9_4
  float v15; // xmm4_4
  float v16; // xmm9_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  int v19; // xmm3_4
  float x; // xmm6_4
  float v21; // xmm2_4
  int v23[3]; // [rsp+20h] [rbp-88h] BYREF
  int v24[5]; // [rsp+2Ch] [rbp-7Ch] BYREF
  UFG::qMatrix44 d; // [rsp+40h] [rbp-68h] BYREF

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( !m_pSimObject )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  UFG::qInverseAffine(&d, &m_pSimObject->mWorldTransform);
  mPtr = this->mpRegion.mPtr;
  y = rayPos->y;
  z = rayPos->z;
  v12 = d.v1.y * y;
  v13 = d.v1.z * y;
  v14 = d.v1.x * y;
  v15 = rayDir->y;
  v16 = (float)((float)(v14 + (float)(d.v0.x * rayPos->x)) + (float)(d.v2.x * z)) + d.v3.x;
  v17 = rayDir->z;
  v18 = d.v2.z * z;
  *(float *)&v19 = (float)((float)(v12 + (float)(d.v0.y * rayPos->x)) + (float)(d.v2.y * z)) + d.v3.y;
  x = rayDir->x;
  v21 = (float)(v13 + (float)(d.v0.z * rayPos->x)) + v18;
  v24[1] = v19;
  *(float *)v24 = v16;
  *(float *)&v24[2] = v21 + d.v3.z;
  *(float *)v23 = (float)((float)(x * d.v0.x) + (float)(v15 * d.v1.x)) + (float)(v17 * d.v2.x);
  *(float *)&v23[1] = (float)((float)(x * d.v0.y) + (float)(v15 * d.v1.y)) + (float)(v17 * d.v2.y);
  *(float *)&v23[2] = (float)((float)(x * d.v0.z) + (float)(v15 * d.v1.z)) + (float)(v17 * d.v2.z);
  return mPtr->vfptr->IsHitAspect(mPtr, (UFG::qVector3 *)v24, (UFG::qVector3 *)v23, pHitAspect);
}

// File Line: 536
// RVA: 0x246100
void __fastcall UFG::RegionComponent::TranslateAspect(
        UFG::RegionComponent *this,
        unsigned int aspect,
        UFG::qVector3 *delta)
{
  UFG::TransformNodeComponent *m_pSimObject; // rbx
  UFG::RegionBase *mPtr; // rcx
  float x; // xmm6_4
  float z; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  int v13[4]; // [rsp+20h] [rbp-68h] BYREF
  UFG::qMatrix44 d; // [rsp+30h] [rbp-58h] BYREF

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( m_pSimObject )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
    UFG::qInverseAffine(&d, &m_pSimObject->mWorldTransform);
    mPtr = this->mpRegion.mPtr;
    x = delta->x;
    z = delta->z;
    v10 = delta->x;
    v11 = delta->y * d.v1.y;
    v12 = delta->y * d.v1.z;
    *(float *)v13 = (float)((float)(delta->x * d.v0.x) + (float)(delta->y * d.v1.x)) + (float)(z * d.v2.x);
    *(float *)&v13[1] = (float)((float)(v10 * d.v0.y) + v11) + (float)(z * d.v2.y);
    *(float *)&v13[2] = (float)((float)(x * d.v0.z) + v12) + (float)(z * d.v2.z);
    mPtr->vfptr->TranslateAspect(mPtr, aspect, (UFG::qVector3 *)v13);
  }
}

// File Line: 559
// RVA: 0x2439E0
void __fastcall UFG::RegionComponent::PropertiesLoad(UFG::RegionComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::RegionBase *v4; // rdi
  UFG::qPropertySet *v5; // rbp
  unsigned int *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::RegionBase *v8; // rax
  float *v9; // r15
  float *v10; // rsi
  float *v11; // rbx
  UFG::allocator::free_link *v12; // rax
  float v13; // xmm2_4
  float v14; // xmm1_4
  int v15; // xmm0_4
  UFG::allocator::free_link *v16; // rsi
  UFG::qVector3 *v17; // rbx
  UFG::qVector3 *v18; // rax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  UFG::allocator::free_link *v25; // rbx
  int v26; // xmm0_4
  UFG::RegionBase *mPtr; // rcx
  UFG::SimObjectModifier v28; // [rsp+28h] [rbp-50h] BYREF

  v4 = 0i64;
  v5 = PropertyUtils::Get<UFG::qPropertySet>(
         pSceneObj,
         (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentRegion);
  v6 = UFG::qPropertySet::Get<unsigned long>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_Type, DEPTH_RECURSE);
  switch ( *v6 )
  {
    case 2u:
      v25 = UFG::qMalloc(0x18ui64, "RegionSphere", 0i64);
      if ( v25 )
      {
        v26 = *(_DWORD *)UFG::qPropertySet::Get<float>(
                           v5,
                           (UFG::qArray<unsigned long,0> *)&SimSym_Radius,
                           DEPTH_RECURSE);
        v25->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable;
        LODWORD(v25[1].mNext) = 0;
        v25->mNext = (UFG::allocator::free_link *)&UFG::RegionSphere::`vftable;
        LODWORD(v25[2].mNext) = v26;
        v4 = (UFG::RegionBase *)v25;
      }
      break;
    case 3u:
      v16 = UFG::qMalloc(0x28ui64, "RegionBox", 0i64);
      if ( v16 )
      {
        v17 = UFG::qPropertySet::Get<UFG::qVector3>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_Max, DEPTH_RECURSE);
        v18 = UFG::qPropertySet::Get<UFG::qVector3>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_Min, DEPTH_RECURSE);
        x = v18->x;
        y = v18->y;
        z = v18->z;
        v22 = v17->x;
        v23 = v17->y;
        v24 = v17->z;
        v16->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable;
        LODWORD(v16[1].mNext) = 0;
        v16->mNext = (UFG::allocator::free_link *)&UFG::RegionBox::`vftable;
        *(float *)&v16[2].mNext = x;
        *((float *)&v16[2].mNext + 1) = y;
        *(float *)&v16[3].mNext = z;
        *((float *)&v16[3].mNext + 1) = v22;
        *(float *)&v16[4].mNext = v23;
        *((float *)&v16[4].mNext + 1) = v24;
        v4 = (UFG::RegionBase *)v16;
      }
      break;
    case 6u:
      v9 = UFG::qPropertySet::Get<float>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_Radius, DEPTH_RECURSE);
      v10 = UFG::qPropertySet::Get<float>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_ExtentAbove, DEPTH_RECURSE);
      v11 = UFG::qPropertySet::Get<float>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_ExtentBelow, DEPTH_RECURSE);
      v12 = UFG::qMalloc(0x20ui64, "RegionDisc", 0i64);
      if ( v12 )
      {
        if ( v11 )
          v13 = *v11;
        else
          v13 = FLOAT_N0_25;
        if ( v10 )
          v14 = *v10;
        else
          v14 = FLOAT_1_75;
        if ( v9 )
          v15 = *(_DWORD *)v9;
        else
          v15 = (int)FLOAT_1_0;
        v12->mNext = (UFG::allocator::free_link *)&UFG::RegionBase::`vftable;
        LODWORD(v12[1].mNext) = 0;
        v12->mNext = (UFG::allocator::free_link *)&UFG::RegionDisc::`vftable;
        LODWORD(v12[2].mNext) = v15;
        *((float *)&v12[2].mNext + 1) = v14;
        *(float *)&v12[3].mNext = v13;
        v4 = (UFG::RegionBase *)v12;
      }
      break;
    case 8u:
      v7 = UFG::qMalloc(0x58ui64, "RegionPolygon", 0i64);
      if ( v7 )
      {
        UFG::RegionPolygon::RegionPolygon((UFG::RegionPolygon *)v7, v5);
        v4 = v8;
      }
      break;
  }
  mPtr = this->mpRegion.mPtr;
  if ( v4 != mPtr )
  {
    if ( mPtr )
    {
      if ( --mPtr->mRefCount <= 0 )
        mPtr->vfptr->__vecDelDtor(mPtr, 1u);
    }
    this->mpRegion.mPtr = v4;
    if ( v4 )
      ++v4->mRefCount;
  }
  if ( !this->m_pSimObject )
  {
    UFG::SimObjectModifier::SimObjectModifier(&v28, pSceneObj->m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v28, this, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v28);
    UFG::SimObjectModifier::~SimObjectModifier(&v28);
  }
}

// File Line: 612
// RVA: 0x2442B0
void __fastcall UFG::RegionComponent::PropertiesSave(UFG::RegionComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::RegionPolygon *mPtr; // rsi
  unsigned int v4; // eax
  UFG::qPropertySet *mpConstProperties; // rcx
  unsigned int v6; // ebx
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *ContainedSet; // rdi
  unsigned int *v9; // rax
  UFG::qPropertySet *mpWritableProperties; // r14
  UFG::qPropertySet *PropertySet; // rax
  unsigned int v12; // ebx
  unsigned int v13; // ebx
  unsigned int v14; // ebx
  UFG::qStaticSymbol *v15; // rdx
  float v16; // xmm2_4

  mPtr = (UFG::RegionPolygon *)this->mpRegion.mPtr;
  v4 = mPtr->vfptr->GetType(mPtr);
  mpConstProperties = pSceneObj->mpConstProperties;
  v6 = v4;
  if ( !mpConstProperties )
    mpConstProperties = pSceneObj->mpWritableProperties;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpConstProperties,
         (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentRegion,
         DEPTH_LOCAL);
  ContainedSet = v7;
  if ( v7 )
  {
    v9 = UFG::qPropertySet::Get<unsigned long>(v7, (UFG::qArray<unsigned long,0> *)&SimSym_Type, DEPTH_RECURSE);
    if ( v9 && *v9 != v6 )
      UFG::qPropertySet::RemovePropertiesAllLocal(ContainedSet);
  }
  else
  {
    mpWritableProperties = pSceneObj->mpConstProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpWritableProperties;
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gNullQSymbol, "RegionCompPS");
    PropertySet = UFG::PropertySetManager::GetPropertySet(&SimSymX_propset_componentRegion);
    UFG::PSWrapper::AppendParentLocal(ContainedSet, PropertySet);
    UFG::qPropertySet::Set<UFG::qPropertySet>(
      mpWritableProperties,
      (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentRegion,
      ContainedSet);
  }
  UFG::qPropertySet::Set<unsigned long>(ContainedSet, (UFG::qArray<unsigned long,0> *)&SimSym_Type, v6);
  v12 = v6 - 2;
  if ( !v12 )
  {
    v16 = *(float *)&mPtr->mpVerts;
    v15 = &SimSym_Radius;
    goto LABEL_18;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    UFG::qPropertySet::Set<UFG::qVector3>(
      ContainedSet,
      (UFG::qArray<unsigned long,0> *)&SimSym_Min,
      (UFG::qVector3 *)&mPtr->mpVerts);
    UFG::qPropertySet::Set<UFG::qVector3>(
      ContainedSet,
      (UFG::qArray<unsigned long,0> *)&SimSym_Max,
      (UFG::qVector3 *)&mPtr->mExtentAbove);
    return;
  }
  v14 = v13 - 3;
  if ( !v14 )
  {
    UFG::qPropertySet::Set<float>(
      ContainedSet,
      (UFG::qArray<unsigned long,0> *)&SimSym_Radius,
      *(float *)&mPtr->mpVerts);
    UFG::qPropertySet::Set<float>(
      ContainedSet,
      (UFG::qArray<unsigned long,0> *)&SimSym_ExtentAbove,
      *((float *)&mPtr->mpVerts + 1));
    v15 = &SimSym_ExtentBelow;
    v16 = *(float *)&mPtr->mVertCount;
LABEL_18:
    UFG::qPropertySet::Set<float>(ContainedSet, (UFG::qArray<unsigned long,0> *)v15, v16);
    return;
  }
  if ( v14 == 2 )
    UFG::RegionPolygon::PropertiesSave(mPtr, ContainedSet);
}

// File Line: 664
// RVA: 0x23E430
bool __fastcall UFG::RegionComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::PropertyExists(pSceneObj, &SimSymX_propset_componentRegion);
}

// File Line: 681
// RVA: 0x244170
UFG::RegionComponent *__fastcall UFG::RegionComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::qSymbol *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v9; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x78ui64, "RegionComponent", 0i64, 1u);
  v9 = v3;
  if ( v3 )
  {
    v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, pSceneObj->m_NameUID);
    UFG::RegionComponent::RegionComponent((UFG::RegionComponent *)v3, v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  (*(void (__fastcall **)(__int64, UFG::SceneObjectProperties *))(*(_QWORD *)v6 + 96i64))(v6, pSceneObj);
  return (UFG::RegionComponent *)v6;
}

// File Line: 693
// RVA: 0x243980
UFG::qPropertySet *__fastcall UFG::RegionComponent::PropertiesAppendDefaultProperty(UFG::qPropertySet *pProps)
{
  UFG::qPropertySet *ContainedSet; // rbx
  UFG::qPropertySet *PropertySet; // rax

  ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gNullQSymbol, "RegionCompPS");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&SimSymX_propset_componentRegion);
  UFG::PSWrapper::AppendParentLocal(ContainedSet, PropertySet);
  UFG::qPropertySet::Set<UFG::qPropertySet>(
    pProps,
    (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentRegion,
    ContainedSet);
  return ContainedSet;
}

