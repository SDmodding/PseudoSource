// File Line: 102
// RVA: 0xDF620
void __fastcall qPagedLinearAllocator::NewPage(qPagedLinearAllocator *this)
{
  char *v2; // rax
  qPagedLinearAllocator::PageHeader *v3; // rdx
  UFG::qNode<qPagedLinearAllocator::PageHeader,qPagedLinearAllocator::PageHeader> *mPrev; // rax

  v2 = UFG::qMemoryPool::Allocate(this->mpPool, this->mPageSize, this->mPageTag, 0i64, 1u);
  v3 = (qPagedLinearAllocator::PageHeader *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = v2;
    *((_QWORD *)v2 + 1) = v2;
  }
  else
  {
    v3 = 0i64;
  }
  this->mpCurrentPage = v3;
  mPrev = this->mPages.mNode.mPrev;
  mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = &this->mPages.mNode;
  this->mPages.mNode.mPrev = v3;
  this->mpCurrentPos = &this->mpCurrentPage[1];
  this->mRemainingBytesOnPage = this->mPageSize - 16;
}

// File Line: 148
// RVA: 0xD96B0
qPagedLinearAllocator *__fastcall GetLaneTAllocator()
{
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    allocator.mpPool = UFG::gMainMemoryPool;
    dword_142175178 = 0x4000;
    qword_142175180 = (__int64)"RoadNetworkSubSegment";
    qword_142175188 = 0i64;
    qword_142175190 = 0i64;
    dword_142175198 = 0;
    stru_1421751A0.mNode.mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_1421751A0;
    stru_1421751A0.mNode.mNext = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_1421751A0;
    atexit(GetLaneTAllocator_::_2_::_dynamic_atexit_destructor_for__allocator__);
  }
  return &allocator;
}

// File Line: 187
// RVA: 0xD8D80
UFG::RoadNetworkConnection *__fastcall UFG::RoadNetworkGate::GetIncomingConnection(
        UFG::RoadNetworkGate *this,
        unsigned int index)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  UFG::RoadNetworkConnection **v4; // rdx
  UFG::RoadNetworkConnection *result; // rax

  mOffset = this->mIncomingConnection.mOffset;
  if ( mOffset )
    v3 = (char *)&this->mIncomingConnection + mOffset;
  else
    v3 = 0i64;
  v4 = (UFG::RoadNetworkConnection **)&v3[8 * index];
  result = *v4;
  if ( *v4 )
    return (UFG::RoadNetworkConnection *)((char *)result + (_QWORD)v4);
  return result;
}

// File Line: 515
// RVA: 0xD5EA0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkNode::GetCenterLane(UFG::RoadNetworkNode *this)
{
  __int64 mOffset; // rdx
  __int64 v2; // rax
  char *v3; // rcx
  UFG::RoadNetworkLane **v4; // rdx
  UFG::RoadNetworkLane *result; // rax

  mOffset = this->mLane.mOffset;
  v2 = (unsigned int)(((unsigned __int8)this->mNumLanes - 1) / 2);
  if ( mOffset )
    v3 = (char *)&this->mLane + mOffset;
  else
    v3 = 0i64;
  v4 = (UFG::RoadNetworkLane **)&v3[8 * v2];
  result = *v4;
  if ( *v4 )
    return (UFG::RoadNetworkLane *)((char *)result + (_QWORD)v4);
  return result;
}

// File Line: 522
// RVA: 0xD5EE0
__int64 __fastcall UFG::RoadNetworkNode::GetCenterLaneIndex(UFG::RoadNetworkNode *this)
{
  return (unsigned int)(((unsigned __int8)this->mNumLanes - 1) / 2);
}

// File Line: 531
// RVA: 0xD69F0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkSegment::GetClosestLaneToCenter(
        UFG::RoadNetworkSegment *this,
        unsigned int index)
{
  unsigned int v2; // r8d
  __int64 v3; // rbx
  __int64 v4; // r9
  __int64 mOffset; // rax
  char *v6; // rcx
  __int64 v7; // rax
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkLane *> *> *p_mLane; // r13
  __int64 v10; // r14
  _QWORD *v11; // rax
  UFG::RoadNetworkLane *v12; // r12
  char *v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rcx
  UFG::RoadNetworkLane *v16; // r15
  char *v17; // rcx
  char *v18; // rdx
  char *v19; // rsi
  char *v20; // rcx
  __int64 v21; // rax
  char *v22; // rdi
  __int64 v23; // r10
  char *v24; // r8
  __int64 v25; // r11
  char *v26; // rax
  __int64 v27; // rcx
  char *v28; // rax
  char *v29; // rdx
  __int64 v30; // rax
  char *v31; // rax
  bool v32; // zf
  __int64 v33; // rax
  char *v34; // r8
  char *v35; // rcx
  __int64 v36; // rax
  char *v37; // rax
  char *v38; // rdx
  __int64 v39; // rax
  char *v40; // rax
  __int64 v41; // rax
  char *v42; // r8
  char *v43; // rcx
  __int64 v44; // rax
  char *v45; // rax
  char *v46; // rdx
  __int64 v47; // rax
  char *v48; // rax
  bool v49; // r9
  char *v50; // r8
  char *v51; // rax
  __int64 v52; // rcx
  char *v53; // rax
  char *v54; // rdx
  __int64 v55; // rax
  char *v56; // rax
  __int64 v57; // rax
  char *v58; // rbp
  char *v59; // rcx
  __int64 v60; // rax
  char *v61; // rax
  char *v62; // rdx
  __int64 v63; // rax
  __int64 v64; // rsi
  __int64 v65; // rax
  char *v66; // rcx
  char *v67; // rdx
  __int64 v68; // rax
  char *v69; // rbp
  char *v70; // rcx
  __int64 v71; // rax
  char *v72; // rax
  char *v73; // rdx
  __int64 v74; // rax
  __int64 v75; // rsi
  char *v76; // rcx
  char *v77; // rdx
  unsigned int v78; // [rsp+60h] [rbp+8h]
  char *v79; // [rsp+70h] [rbp+18h]

  LOBYTE(v2) = this->mNumLanes;
  v3 = 0i64;
  v4 = index;
  if ( (_BYTE)v2 == 1 )
  {
    mOffset = this->mLane.mOffset;
    if ( mOffset )
      v6 = (char *)&this->mLane + mOffset;
    else
      v6 = 0i64;
    v7 = *(_QWORD *)&v6[8 * index];
    if ( v7 )
      return (UFG::RoadNetworkLane *)&v6[8 * index + v7];
    return (UFG::RoadNetworkLane *)v3;
  }
  else
  {
    p_mLane = &this->mLane;
    v10 = this->mLane.mOffset;
    v11 = (__int64 *)((char *)&this->mLane.mOffset + v10);
    if ( !v10 )
      v11 = 0i64;
    v12 = (UFG::RoadNetworkLane *)((char *)v11 + *v11);
    if ( !*v11 )
      v12 = 0i64;
    v13 = (char *)p_mLane + v10;
    if ( !v10 )
      v13 = 0i64;
    v2 = (unsigned __int8)v2;
    v78 = v2;
    v14 = (unsigned int)(unsigned __int8)v2 - 1;
    v15 = *(_QWORD *)&v13[8 * v14];
    v16 = (UFG::RoadNetworkLane *)&v13[8 * v14 + v15];
    if ( !v15 )
      v16 = 0i64;
    v17 = (char *)p_mLane + v10;
    if ( !v10 )
      v17 = 0i64;
    v18 = &v17[8 * (((unsigned __int8)v2 - 1) / 2)];
    v19 = &v18[*(_QWORD *)v18];
    if ( !*(_QWORD *)v18 )
      v19 = 0i64;
    v79 = v19;
    v20 = (char *)p_mLane + v10;
    if ( !v10 )
      v20 = 0i64;
    v21 = *(_QWORD *)&v20[8 * v4];
    v22 = &v20[8 * v4 + v21];
    if ( !v21 )
      v22 = 0i64;
    v23 = v12->mStartGate.mOffset;
    if ( v23 )
      v24 = (char *)&v12->mStartGate + v23;
    else
      v24 = 0i64;
    v25 = v12->mNode.mOffset;
    v26 = (char *)v12 + v12->mNode.mOffset;
    if ( !v12->mNode.mOffset )
      v26 = 0i64;
    v27 = *((_QWORD *)v26 + 6);
    if ( v27 )
      v28 = &v26[v27 + 48];
    else
      v28 = 0i64;
    v29 = &v28[*(_QWORD *)v28];
    if ( !*(_QWORD *)v28 )
      v29 = 0i64;
    v30 = *((_QWORD *)v29 + 1);
    if ( v30 )
      v31 = &v29[v30 + 8];
    else
      v31 = 0i64;
    v32 = v24 == v31;
    v33 = v16->mStartGate.mOffset;
    if ( v33 )
      v34 = (char *)&v16->mStartGate + v33;
    else
      v34 = 0i64;
    v35 = (char *)v16 + v16->mNode.mOffset;
    if ( !v16->mNode.mOffset )
      v35 = 0i64;
    v36 = *((_QWORD *)v35 + 6);
    if ( v36 )
      v37 = &v35[v36 + 48];
    else
      v37 = 0i64;
    v38 = &v37[*(_QWORD *)v37];
    if ( !*(_QWORD *)v37 )
      v38 = 0i64;
    v39 = *((_QWORD *)v38 + 1);
    if ( v39 )
      v40 = &v38[v39 + 8];
    else
      v40 = 0i64;
    if ( !v32 != (v34 != v40) )
    {
      v41 = *((_QWORD *)v22 + 1);
      if ( v41 )
        v42 = &v22[v41 + 8];
      else
        v42 = 0i64;
      v43 = &v22[*(_QWORD *)v22];
      if ( !*(_QWORD *)v22 )
        v43 = 0i64;
      v44 = *((_QWORD *)v43 + 6);
      if ( v44 )
        v45 = &v43[v44 + 48];
      else
        v45 = 0i64;
      v46 = &v45[*(_QWORD *)v45];
      if ( !*(_QWORD *)v45 )
        v46 = 0i64;
      v47 = *((_QWORD *)v46 + 1);
      if ( v47 )
        v48 = &v46[v47 + 8];
      else
        v48 = 0i64;
      v49 = v42 != v48;
      if ( v23 )
        v50 = (char *)&v12->mStartGate + v23;
      else
        v50 = 0i64;
      v51 = (char *)v12 + v25;
      if ( !v25 )
        v51 = 0i64;
      v52 = *((_QWORD *)v51 + 6);
      if ( v52 )
        v53 = &v51[v52 + 48];
      else
        v53 = 0i64;
      v54 = &v53[*(_QWORD *)v53];
      if ( !*(_QWORD *)v53 )
        v54 = 0i64;
      v55 = *((_QWORD *)v54 + 1);
      if ( v55 )
        v56 = &v54[v55 + 8];
      else
        v56 = 0i64;
      if ( v49 == (v50 != v56) )
      {
        while ( 1 )
        {
          v57 = *((_QWORD *)v22 + 1);
          if ( v57 )
            v58 = &v22[v57 + 8];
          else
            v58 = 0i64;
          v59 = &v22[*(_QWORD *)v22];
          if ( !*(_QWORD *)v22 )
            v59 = 0i64;
          v60 = *((_QWORD *)v59 + 6);
          if ( v60 )
            v61 = &v59[v60 + 48];
          else
            v61 = 0i64;
          v62 = &v61[*(_QWORD *)v61];
          if ( !*(_QWORD *)v61 )
            v62 = 0i64;
          v63 = *((_QWORD *)v62 + 1);
          v64 = v63 ? (__int64)&v62[v63 + 8] : 0i64;
          if ( (v58 != (char *)v64) != UFG::RoadNetworkLane::IsReversedInNode(v12) )
            break;
          v79 = v22;
          v65 = (unsigned int)*((unsigned __int16 *)v22 + 18) + 1;
          if ( (unsigned int)v65 >= v78 )
            return (UFG::RoadNetworkLane *)v22;
          v66 = (char *)p_mLane + v10;
          if ( !v10 )
            v66 = 0i64;
          v67 = &v66[8 * v65];
          if ( *(_QWORD *)v67 )
            v22 = &v67[*(_QWORD *)v67];
          else
            v22 = 0i64;
        }
      }
      else
      {
        while ( 1 )
        {
          v68 = *((_QWORD *)v22 + 1);
          if ( v68 )
            v69 = &v22[v68 + 8];
          else
            v69 = 0i64;
          v70 = &v22[*(_QWORD *)v22];
          if ( !*(_QWORD *)v22 )
            v70 = 0i64;
          v71 = *((_QWORD *)v70 + 6);
          if ( v71 )
            v72 = &v70[v71 + 48];
          else
            v72 = 0i64;
          v73 = &v72[*(_QWORD *)v72];
          if ( !*(_QWORD *)v72 )
            v73 = 0i64;
          v74 = *((_QWORD *)v73 + 1);
          v75 = v74 ? (__int64)&v73[v74 + 8] : 0i64;
          if ( (v69 != (char *)v75) != UFG::RoadNetworkLane::IsReversedInNode(v16) )
            break;
          v79 = v22;
          v76 = (char *)p_mLane + v10;
          if ( !v10 )
            v76 = 0i64;
          v77 = &v76[8 * *((unsigned __int16 *)v22 + 18) - 8];
          if ( *(_QWORD *)v77 )
            v22 = &v77[*(_QWORD *)v77];
          else
            v22 = 0i64;
        }
      }
      return (UFG::RoadNetworkLane *)v79;
    }
    return (UFG::RoadNetworkLane *)v19;
  }
}

// File Line: 577
// RVA: 0xDAA30
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetNearestPos(
        UFG::RoadNetworkNode *this,
        UFG::qVector3 *result,
        UFG::qVector3 *pos,
        UFG::RoadNetworkLane **nearestLane,
        float *nearestT)
{
  UFG::RoadNetworkLane *v5; // rbp
  __int64 v6; // rdi
  float v7; // xmm6_4
  float v8; // xmm7_4
  __int64 mOffset; // rax
  char *v14; // rcx
  __int64 v15; // rax
  UFG::RoadNetworkLane *v16; // rbx
  __int64 v17; // rax
  UFG::RoadNetworkConnection *v18; // rcx
  UFG::qBezierPathMemImaged *Path; // rax
  float y; // xmm4_4
  float z; // xmm5_4
  float v22; // xmm2_4
  float *v23; // rax
  UFG::qVector3 resulta; // [rsp+20h] [rbp-58h] BYREF
  float t; // [rsp+80h] [rbp+8h] BYREF

  v5 = 0i64;
  *result = this->mPosition;
  v6 = 0i64;
  v7 = 0.0;
  v8 = FLOAT_3_4028235e38;
  for ( t = 0.0; (unsigned int)v6 < (unsigned __int8)this->mNumLanes; v6 = (unsigned int)(v6 + 1) )
  {
    mOffset = this->mLane.mOffset;
    if ( mOffset )
      v14 = (char *)&this->mLane + mOffset;
    else
      v14 = 0i64;
    v15 = *(_QWORD *)&v14[8 * v6];
    if ( v15 )
      v16 = (UFG::RoadNetworkLane *)&v14[8 * v6 + v15];
    else
      v16 = 0i64;
    v17 = v16->mNode.mOffset;
    if ( v16->mNode.mOffset )
      v17 += (__int64)v16;
    v18 = *(UFG::RoadNetworkConnection **)(v17 + 32);
    if ( v18 )
      v18 = (UFG::RoadNetworkConnection *)((char *)v18 + v17 + 32);
    Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v18, v16->mPathIndex);
    UFG::qBezierPathMemImaged::ClosestPoint3D(Path, &resulta, pos, &t);
    y = resulta.y;
    z = resulta.z;
    v22 = (float)((float)((float)(resulta.y - pos->y) * (float)(resulta.y - pos->y))
                + (float)((float)(resulta.x - pos->x) * (float)(resulta.x - pos->x)))
        + (float)((float)(resulta.z - pos->z) * (float)(resulta.z - pos->z));
    if ( v22 < v8 )
    {
      v7 = t;
      result->x = resulta.x;
      result->y = y;
      v8 = v22;
      v5 = v16;
      result->z = z;
    }
  }
  v23 = nearestT;
  *nearestLane = v5;
  *v23 = v7;
  return result;
}

// File Line: 607
// RVA: 0xDA430
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetNearestPos(
        UFG::RoadNetworkNode *this,
        UFG::qVector3 *result,
        UFG::qVector3 *pos,
        UFG::qVector3 *_heading,
        UFG::RoadNetworkLane **nearestLane,
        float *nearestT)
{
  float v6; // xmm7_4
  float y; // xmm10_4
  __m128 x_low; // xmm9
  float z; // xmm11_4
  __m128 v13; // xmm2
  float v14; // xmm1_4
  float v15; // xmm9_4
  float v16; // xmm10_4
  char *v17; // r14
  float v18; // xmm11_4
  float v19; // xmm6_4
  unsigned int v20; // ecx
  __int64 v21; // r12
  __int64 mOffset; // rax
  char *v23; // rcx
  __int64 v24; // rax
  char *v25; // rsi
  _QWORD *v26; // rax
  float *v27; // r15
  __int64 v28; // rax
  UFG::RoadNetworkConnection *v29; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v32; // rax
  float v33; // xmm2_4
  __m128 y_low; // xmm3
  float v35; // xmm4_4
  __m128 v36; // xmm5
  float v37; // xmm1_4
  float v38; // xmm2_4
  __int64 v39; // rax
  __int64 j; // r12
  __int64 v41; // rax
  char *v42; // rcx
  __int64 v43; // rax
  char *v44; // rsi
  _QWORD *v45; // rax
  float *v46; // r15
  __int64 v47; // rax
  UFG::RoadNetworkConnection *v48; // rcx
  UFG::qBezierPathMemImaged *v49; // rbx
  unsigned int v50; // eax
  UFG::qBezierSplineMemImaged *v51; // rax
  float v52; // xmm2_4
  __m128 v53; // xmm3
  float v54; // xmm4_4
  __m128 v55; // xmm5
  float v56; // xmm1_4
  float v57; // xmm2_4
  __int64 v58; // rax
  float v59; // xmm6_4
  char *v60; // rsi
  __int64 v61; // rdi
  char *v62; // rbx
  __int64 v63; // rax
  UFG::RoadNetworkConnection *v64; // rcx
  UFG::qBezierPathMemImaged *v65; // rax
  float v66; // xmm4_4
  float v67; // xmm5_4
  __m128 v68; // xmm2
  float v69; // xmm1_4
  float v70; // xmm6_4
  __int64 v71; // rsi
  __int64 v72; // rax
  char *v73; // rcx
  __int64 v74; // rax
  char *v75; // rbx
  __int64 v76; // rax
  UFG::RoadNetworkConnection *v77; // rcx
  UFG::qBezierPathMemImaged *v78; // rax
  float v79; // xmm4_4
  float v80; // xmm5_4
  __m128 v81; // xmm2
  float v82; // xmm1_4
  float v84; // [rsp+1Ch] [rbp-7Dh]
  float splineT; // [rsp+20h] [rbp-79h] BYREF
  UFG::qVector3 resulta; // [rsp+28h] [rbp-71h] BYREF
  UFG::qVector3 v87; // [rsp+38h] [rbp-61h] BYREF
  unsigned int i; // [rsp+F0h] [rbp+57h]
  float t; // [rsp+F8h] [rbp+5Fh] BYREF
  UFG::qVector3 *vars0; // [rsp+100h] [rbp+67h]
  void *retaddr; // [rsp+108h] [rbp+6Fh] BYREF
  char **v92; // [rsp+110h] [rbp+77h]
  float *v93; // [rsp+118h] [rbp+7Fh]

  v6 = 0.0;
  y = _heading->y;
  x_low = (__m128)LODWORD(_heading->x);
  z = _heading->z;
  *result = this->mPosition;
  v13 = x_low;
  v13.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  if ( v13.m128_f32[0] == 0.0 )
    v14 = 0.0;
  else
    v14 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
  v15 = x_low.m128_f32[0] * v14;
  v16 = y * v14;
  v17 = 0i64;
  v18 = z * v14;
  if ( this->mType.mValue == 1 )
  {
    v19 = FLOAT_N2_0;
    v20 = 0;
    v21 = 0i64;
    for ( i = 0; (unsigned int)v21 < (unsigned __int8)this->mNumIncomingConnections; v21 = (unsigned int)(v21 + 1) )
    {
      mOffset = this->mIncomingConnections.mOffset;
      if ( mOffset )
        v23 = (char *)&this->mIncomingConnections + mOffset;
      else
        v23 = 0i64;
      v24 = *(_QWORD *)&v23[8 * v21];
      if ( v24 )
        v25 = &v23[8 * v21 + v24];
      else
        v25 = 0i64;
      v26 = (_QWORD *)*((_QWORD *)v25 + 1);
      if ( v26 )
        v26 = (_QWORD *)((char *)v26 + (_QWORD)v25 + 8);
      if ( *v26 )
        v27 = (float *)((char *)v26 + *v26);
      else
        v27 = 0i64;
      v28 = *(_QWORD *)v27;
      if ( *(_QWORD *)v27 )
        v28 += (__int64)v27;
      v29 = *(UFG::RoadNetworkConnection **)(v28 + 32);
      if ( v29 )
        v29 = (UFG::RoadNetworkConnection *)((char *)v29 + v28 + 32);
      Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                            v29,
                                            *((unsigned __int16 *)v27 + 19));
      SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, 0.0, &splineT);
      v32 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             (UFG::RoadNetworkConnection *)Path,
                                             SplineParameters);
      UFG::RoadNetworkLane::GetOffsetPos(&resulta, v32, splineT, v27[10]);
      pos = vars0;
      y_low = (__m128)LODWORD(resulta.y);
      v33 = resulta.x - vars0->x;
      y_low.m128_f32[0] = resulta.y - vars0->y;
      v35 = resulta.z - vars0->z;
      v36 = y_low;
      v36.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v33 * v33))
                      + (float)(v35 * v35);
      if ( v36.m128_f32[0] == 0.0 )
        v37 = 0.0;
      else
        v37 = 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
      v38 = (float)((float)((float)(v33 * v37) * v15) + (float)((float)(y_low.m128_f32[0] * v37) * v16))
          + (float)((float)(v35 * v37) * v18);
      if ( v38 <= v19 )
      {
        v20 = i;
      }
      else
      {
        v39 = *((_QWORD *)v25 + 1);
        v20 = *(_DWORD *)v25;
        i = *(_DWORD *)v25;
        if ( v39 )
        {
          v19 = v38;
          v17 = &v25[v39 + 8];
        }
        else
        {
          v17 = 0i64;
          v19 = v38;
        }
      }
    }
    for ( j = 0i64; (unsigned int)j < (unsigned __int8)this->mNumOutgoingConnections; j = (unsigned int)(j + 1) )
    {
      v41 = this->mOutgoingConnections.mOffset;
      if ( v41 )
        v42 = (char *)&this->mOutgoingConnections + v41;
      else
        v42 = 0i64;
      v43 = *(_QWORD *)&v42[8 * j];
      if ( v43 )
        v44 = &v42[8 * j + v43];
      else
        v44 = 0i64;
      v45 = (_QWORD *)*((_QWORD *)v44 + 1);
      if ( v45 )
        v45 = (_QWORD *)((char *)v45 + (_QWORD)v44 + 8);
      if ( *v45 )
        v46 = (float *)((char *)v45 + *v45);
      else
        v46 = 0i64;
      v47 = *(_QWORD *)v46;
      if ( *(_QWORD *)v46 )
        v47 += (__int64)v46;
      v48 = *(UFG::RoadNetworkConnection **)(v47 + 32);
      if ( v48 )
        v48 = (UFG::RoadNetworkConnection *)((char *)v48 + v47 + 32);
      v49 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v48,
                                           *((unsigned __int16 *)v46 + 19));
      v50 = UFG::qBezierPathMemImaged::GetSplineParameters(v49, 1.0, &splineT);
      v51 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             (UFG::RoadNetworkConnection *)v49,
                                             v50);
      UFG::RoadNetworkLane::GetOffsetPos(&v87, v51, splineT, v46[10]);
      pos = vars0;
      v53 = (__m128)LODWORD(v84);
      v52 = v87.x - vars0->x;
      v53.m128_f32[0] = v84 - vars0->y;
      v54 = splineT - vars0->z;
      v55 = v53;
      v55.m128_f32[0] = (float)((float)(v53.m128_f32[0] * v53.m128_f32[0]) + (float)(v52 * v52)) + (float)(v54 * v54);
      if ( v55.m128_f32[0] == 0.0 )
        v56 = 0.0;
      else
        v56 = 1.0 / _mm_sqrt_ps(v55).m128_f32[0];
      v57 = (float)((float)((float)(v52 * v56) * v15) + (float)((float)(v53.m128_f32[0] * v56) * v16))
          + (float)((float)(v54 * v56) * v18);
      if ( v57 <= v19 )
      {
        v20 = i;
      }
      else
      {
        v58 = *((_QWORD *)v44 + 1);
        v20 = *(_DWORD *)v44;
        i = *(_DWORD *)v44;
        if ( v58 )
        {
          v19 = v57;
          v17 = &v44[v58 + 8];
        }
        else
        {
          v17 = 0i64;
          v19 = v57;
        }
      }
    }
    v59 = FLOAT_3_4028235e38;
    v60 = 0i64;
    t = 0.0;
    if ( v20 )
    {
      v61 = v20;
      do
      {
        if ( *(_QWORD *)v17 )
          v62 = &v17[*(_QWORD *)v17];
        else
          v62 = 0i64;
        v63 = *(_QWORD *)v62;
        if ( *(_QWORD *)v62 )
          v63 += (__int64)v62;
        v64 = *(UFG::RoadNetworkConnection **)(v63 + 32);
        if ( v64 )
          v64 = (UFG::RoadNetworkConnection *)((char *)v64 + v63 + 32);
        v65 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v64,
                                             *((unsigned __int16 *)v62 + 19));
        UFG::qBezierPathMemImaged::ClosestPoint3D(v65, &resulta, pos, &t);
        v66 = resulta.y;
        v67 = resulta.z;
        v68 = (__m128)LODWORD(resulta.y);
        v68.m128_f32[0] = (float)((float)((float)(resulta.y - pos->y) * (float)(resulta.y - pos->y))
                                + (float)((float)(resulta.x - pos->x) * (float)(resulta.x - pos->x)))
                        + (float)((float)(resulta.z - pos->z) * (float)(resulta.z - pos->z));
        v69 = _mm_sqrt_ps(v68).m128_f32[0];
        if ( v69 < v59 )
        {
          v6 = t;
          result->x = resulta.x;
          result->y = v66;
          v59 = v69;
          v60 = v62;
          result->z = v67;
        }
        v17 += 8;
        --v61;
      }
      while ( v61 );
    }
    *v92 = v60;
  }
  else
  {
    v70 = FLOAT_3_4028235e38;
    v71 = 0i64;
    for ( LODWORD(retaddr) = 0; (unsigned int)v71 < (unsigned __int8)this->mNumLanes; v71 = (unsigned int)(v71 + 1) )
    {
      v72 = this->mLane.mOffset;
      if ( v72 )
        v73 = (char *)&this->mLane + v72;
      else
        v73 = 0i64;
      v74 = *(_QWORD *)&v73[8 * v71];
      if ( v74 )
        v75 = &v73[8 * v71 + v74];
      else
        v75 = 0i64;
      v76 = *(_QWORD *)v75;
      if ( *(_QWORD *)v75 )
        v76 += (__int64)v75;
      v77 = *(UFG::RoadNetworkConnection **)(v76 + 32);
      if ( v77 )
        v77 = (UFG::RoadNetworkConnection *)((char *)v77 + v76 + 32);
      v78 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v77,
                                           *((unsigned __int16 *)v75 + 19));
      UFG::qBezierPathMemImaged::ClosestPoint3D(v78, &resulta, pos, (float *)&retaddr);
      v79 = resulta.y;
      v80 = resulta.z;
      v81 = (__m128)LODWORD(resulta.y);
      v81.m128_f32[0] = (float)((float)((float)(resulta.y - pos->y) * (float)(resulta.y - pos->y))
                              + (float)((float)(resulta.x - pos->x) * (float)(resulta.x - pos->x)))
                      + (float)((float)(resulta.z - pos->z) * (float)(resulta.z - pos->z));
      v82 = _mm_sqrt_ps(v81).m128_f32[0];
      if ( v82 < v70 )
      {
        v6 = *(float *)&retaddr;
        result->x = resulta.x;
        result->y = v79;
        v70 = v82;
        v17 = v75;
        result->z = v80;
      }
    }
    *v92 = v17;
  }
  *v93 = v6;
  return result;
}

// File Line: 695
// RVA: 0xD70B0
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetClosestPosition(
        UFG::RoadNetworkNode *this,
        UFG::qVector3 *result,
        UFG::qVector3 *pos,
        float *nearestT)
{
  UFG::qVector3 *v6; // rax
  float v7; // [rsp+48h] [rbp+10h] BYREF
  UFG::RoadNetworkLane *nearestLane; // [rsp+58h] [rbp+20h] BYREF

  v7 = 0.0;
  UFG::RoadNetworkNode::GetNearestPos(this, result, pos, &nearestLane, &v7);
  v6 = result;
  if ( nearestT )
    *nearestT = v7;
  return v6;
}

// File Line: 705
// RVA: 0xD69B0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkNode::GetClosestLane(UFG::RoadNetworkNode *this, UFG::qVector3 *pos)
{
  UFG::qVector3 result; // [rsp+30h] [rbp-18h] BYREF
  float nearestT; // [rsp+60h] [rbp+18h] BYREF
  UFG::RoadNetworkLane *nearestLane; // [rsp+68h] [rbp+20h] BYREF

  nearestLane = 0i64;
  UFG::RoadNetworkNode::GetNearestPos(this, &result, pos, &nearestLane, &nearestT);
  return nearestLane;
}

// File Line: 713
// RVA: 0xD81D0
float __fastcall UFG::RoadNetworkNode::GetClosestT(
        UFG::RoadNetworkNode *this,
        unsigned int laneIndex,
        UFG::qVector3 *position)
{
  __int64 mOffset; // r9
  UFG::RoadNetworkConnection *v5; // rcx
  char *v7; // r9
  char *v8; // rdx
  char *v9; // rax
  char *v10; // rdx
  unsigned int v11; // r8d
  __int64 v12; // rax
  UFG::qBezierPathMemImaged *Path; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF
  float t; // [rsp+48h] [rbp+10h] BYREF

  mOffset = this->mLane.mOffset;
  v5 = 0i64;
  if ( mOffset )
    v7 = (char *)&this->mLane + mOffset;
  else
    v7 = 0i64;
  v8 = &v7[8 * laneIndex];
  if ( *(_QWORD *)v8 )
    v9 = &v8[*(_QWORD *)v8];
  else
    v9 = 0i64;
  t = 0.0;
  if ( *(_QWORD *)v9 )
    v10 = &v9[*(_QWORD *)v9];
  else
    v10 = 0i64;
  v11 = *((unsigned __int16 *)v9 + 19);
  v12 = *((_QWORD *)v10 + 4);
  if ( v12 )
    v5 = (UFG::RoadNetworkConnection *)&v10[v12 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v5, v11);
  UFG::qBezierPathMemImaged::ClosestPoint3D(Path, &result, position, &t);
  return t;
}

// File Line: 749
// RVA: 0xD94E0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkNode::GetLane(UFG::RoadNetworkNode *this, const unsigned int index)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  UFG::RoadNetworkLane **v4; // rdx
  UFG::RoadNetworkLane *result; // rax

  mOffset = this->mLane.mOffset;
  if ( mOffset )
    v3 = (char *)&this->mLane + mOffset;
  else
    v3 = 0i64;
  v4 = (UFG::RoadNetworkLane **)&v3[8 * index];
  result = *v4;
  if ( *v4 )
    return (UFG::RoadNetworkLane *)((char *)result + (_QWORD)v4);
  return result;
}

// File Line: 762
// RVA: 0xDB470
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetPos(
        UFG::RoadNetworkNode *this,
        UFG::qVector3 *result,
        unsigned int laneIndex,
        float laneT)
{
  __int64 mOffset; // rdx
  UFG::RoadNetworkLane *v7; // rcx
  char *v8; // r9
  char *v9; // rdx

  mOffset = this->mLane.mOffset;
  v7 = 0i64;
  if ( mOffset )
    v8 = (char *)&this->mLane + mOffset;
  else
    v8 = 0i64;
  v9 = &v8[8 * laneIndex];
  if ( *(_QWORD *)v9 )
    v7 = (UFG::RoadNetworkLane *)&v9[*(_QWORD *)v9];
  UFG::RoadNetworkLane::GetPos(v7, result, laneT);
  return result;
}

// File Line: 774
// RVA: 0xDC020
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetTangent(
        UFG::RoadNetworkNode *this,
        UFG::qVector3 *result,
        unsigned int laneIndex,
        float laneT)
{
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v5; // r9
  char *v7; // r10
  char *v8; // rdx
  char *v9; // rax
  unsigned int v10; // edx
  __int64 v11; // rax
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v14; // rax
  float splineT; // [rsp+50h] [rbp+18h] BYREF

  mOffset = this->mLane.mOffset;
  v5 = 0i64;
  if ( mOffset )
    v7 = (char *)&this->mLane + mOffset;
  else
    v7 = 0i64;
  v8 = &v7[8 * laneIndex];
  if ( *(_QWORD *)v8 )
    v9 = &v8[*(_QWORD *)v8];
  else
    v9 = 0i64;
  v10 = *((unsigned __int16 *)v9 + 19);
  v11 = this->mPathCollection.mOffset;
  if ( v11 )
    v5 = (UFG::RoadNetworkConnection *)((char *)&this->mPathCollection + v11);
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v5, v10);
  splineT = 0.0;
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, laneT, &splineT);
  v14 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::qBezierSplineMemImaged::GetTangent(v14, result, splineT);
  return result;
}

// File Line: 786
// RVA: 0xDC930
void __fastcall UFG::RoadNetworkNode::Init(UFG::RoadNetworkNode *this)
{
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0> *p_mModifications; // r15
  char *v3; // r14
  unsigned int mNumLanes; // edi
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  bool v7; // zf
  unsigned int i; // ecx
  __int64 mOffset; // rax
  char *v10; // rdx
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  char *v14; // rbx
  void *v15; // rcx
  __int64 v16; // rbp
  unsigned __int64 v17; // rax
  __int64 v18; // rdx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mPrev; // rax
  unsigned int j; // ecx
  __int64 v21; // rax
  char *v22; // rdx
  char *v23; // r8
  char *v24; // rax
  _QWORD *v25; // rax

  p_mModifications = &this->mModifications;
  this->mModifications.mNode.mPrev = &this->mModifications.mNode;
  this->mModifications.mNode.mNext = &this->mModifications.mNode;
  v3 = 0i64;
  mNumLanes = (unsigned __int8)this->mNumLanes;
  if ( this->mNumLanes )
  {
    v5 = 1;
    if ( mNumLanes <= 1 )
      goto LABEL_5;
    do
      v5 *= 2;
    while ( v5 < mNumLanes );
    if ( v5 <= 4 )
LABEL_5:
      v5 = 4;
    if ( v5 - mNumLanes > 0x10000 )
      v5 = mNumLanes + 0x10000;
    if ( v5 )
    {
      v6 = 4i64 * v5;
      if ( !is_mul_ok(v5, 4ui64) )
        v6 = -1i64;
      v3 = UFG::qMalloc(v6, "RoadNetworkNode", 0i64);
    }
  }
  else
  {
    v7 = mNumLanes == 0;
    mNumLanes = 0;
    if ( !v7 )
      mNumLanes = 0;
  }
  for ( i = 0; i < (unsigned __int8)this->mNumLanes; *(_DWORD *)&v3[4 * i++] = (unsigned __int8)v12[44] )
  {
    mOffset = this->mLane.mOffset;
    if ( mOffset )
      v10 = (char *)&this->mLane + mOffset;
    else
      v10 = 0i64;
    v11 = &v10[8 * i];
    if ( *(_QWORD *)v11 )
      v12 = &v11[*(_QWORD *)v11];
    else
      v12 = 0i64;
  }
  v13 = UFG::qMalloc(0x28ui64, "RoadNetworkNode.RoadNetworkNodeModification", 0i64);
  v14 = v13;
  if ( v13 )
  {
    *(_QWORD *)v13 = v13;
    *((_QWORD *)v13 + 1) = v13;
    *((_QWORD *)v13 + 3) = 0i64;
    *((_QWORD *)v13 + 2) = 0i64;
    *((_QWORD *)v13 + 4) = this;
    v15 = (void *)*((_QWORD *)v13 + 3);
    if ( v15 )
      operator delete[](v15);
    *((_QWORD *)v14 + 3) = 0i64;
    *((_QWORD *)v14 + 2) = 0i64;
    if ( mNumLanes )
    {
      *((_DWORD *)v14 + 4) = mNumLanes;
      v16 = mNumLanes;
      v17 = 4i64 * mNumLanes;
      if ( !is_mul_ok(mNumLanes, 4ui64) )
        v17 = -1i64;
      *((_QWORD *)v14 + 3) = UFG::qMalloc(v17, "qArray.Clone", 0i64);
      *((_DWORD *)v14 + 5) = mNumLanes;
      v18 = 0i64;
      do
      {
        *(_DWORD *)(v18 + *((_QWORD *)v14 + 3)) = *(_DWORD *)&v3[v18];
        v18 += 4i64;
        --v16;
      }
      while ( v16 );
    }
    else
    {
      *((_QWORD *)v14 + 3) = 0i64;
      *((_QWORD *)v14 + 2) = 0i64;
    }
  }
  else
  {
    v14 = 0i64;
  }
  mPrev = p_mModifications->mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v14;
  *(_QWORD *)v14 = mPrev;
  *((_QWORD *)v14 + 1) = p_mModifications;
  p_mModifications->mNode.mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v14;
  for ( j = 0; j < (unsigned __int8)this->mNumLanes; ++j )
  {
    v21 = this->mLane.mOffset;
    if ( v21 )
      v22 = (char *)&this->mLane + v21;
    else
      v22 = 0i64;
    v23 = &v22[8 * j];
    if ( *(_QWORD *)v23 )
      v24 = &v23[*(_QWORD *)v23];
    else
      v24 = 0i64;
    v25 = v24 + 112;
    *v25 = v25;
    v25[1] = v25;
  }
  if ( v3 )
    operator delete[](v3);
}

// File Line: 898
// RVA: 0xDEF20
char __fastcall UFG::RoadNetworkNode::IsWater(UFG::RoadNetworkNode *this)
{
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int v3; // ebx
  unsigned int *v4; // rax

  if ( this->mType.mValue == 1 )
    return UFG::RoadNetworkIntersection::IsWater((UFG::RoadNetworkIntersection *)this);
  if ( *(_QWORD *)&this[1].mDataHash )
    return (unsigned int)(*(_DWORD *)&this[1].mNumLanes - 2) <= 1;
  RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet((UFG::RoadNetworkSegment *)this);
  v3 = 0;
  if ( RoadPropertySet )
  {
    v4 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
    if ( v4 )
      v3 = *v4;
  }
  return v3 - 2 <= 1;
}

// File Line: 911
// RVA: 0xDE3D0
char __fastcall UFG::RoadNetworkNode::IsConnectedToNode(UFG::RoadNetworkNode *this, UFG::RoadNetworkNode *roadNode)
{
  unsigned int mNumGates; // r11d
  int v3; // r8d
  __int64 mOffset; // r10
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *p_mGates; // rbx
  __int64 i; // r9
  char *v7; // rax
  char *v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rcx
  UFG::RoadNetworkNode *v11; // rax

  mNumGates = (unsigned __int8)this->mNumGates;
  v3 = 0;
  if ( !this->mNumGates )
    return 0;
  mOffset = this->mGates.mOffset;
  p_mGates = &this->mGates;
  for ( i = 0i64; ; i += 8i64 )
  {
    if ( mOffset )
      v7 = (char *)p_mGates + mOffset;
    else
      v7 = 0i64;
    v8 = &v7[i];
    v9 = *(_QWORD *)&v7[i];
    if ( v9 )
      v9 += (__int64)v8;
    v10 = *(_QWORD *)(v9 + 8);
    v11 = v10 ? (UFG::RoadNetworkNode *)(v10 + v9 + 8) : 0i64;
    if ( v11 == roadNode )
      break;
    if ( ++v3 >= mNumGates )
      return 0;
  }
  return 1;
}

// File Line: 945
// RVA: 0xDB7A0
__int64 __fastcall UFG::RoadNetworkIntersection::GetRoadNetworkType(UFG::RoadNetworkIntersection *this)
{
  unsigned int mNumGates; // r10d
  unsigned int v2; // ebx
  int v3; // edx
  __int64 mOffset; // r9
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *p_mGates; // r11
  __int64 i; // r8
  char *v7; // rax
  char *v8; // rcx
  __int64 v9; // rax
  char *v10; // rax
  __int64 v11; // rcx
  UFG::RoadNetworkSegment *v12; // rcx
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int *v15; // rax

  mNumGates = (unsigned __int8)this->mNumGates;
  v2 = 0;
  v3 = 0;
  if ( this->mNumGates )
  {
    mOffset = this->mGates.mOffset;
    p_mGates = &this->mGates;
    for ( i = 0i64; ; i += 8i64 )
    {
      v7 = (char *)p_mGates + mOffset;
      if ( !mOffset )
        v7 = 0i64;
      v8 = &v7[i];
      v9 = *(_QWORD *)&v7[i];
      v10 = v9 ? &v8[v9] : 0i64;
      v11 = *((_QWORD *)v10 + 1);
      if ( v11 )
      {
        v12 = (UFG::RoadNetworkSegment *)&v10[v11 + 8];
        if ( v12 )
          break;
      }
      if ( ++v3 >= mNumGates )
        return 0i64;
    }
    if ( v12->mpPropertySetCached )
      return v12->mRoadNetworkType.mValue;
    RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(v12);
    if ( RoadPropertySet )
    {
      v15 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
      if ( v15 )
        return *v15;
    }
  }
  return v2;
}

// File Line: 989
// RVA: 0xD1740
UFG::RoadNetworkNodeModification *__fastcall UFG::RoadNetworkNode::AddChangeLaneFlagsModification(
        UFG::RoadNetworkNode *this,
        UFG::qArray<unsigned long,0> *laneFlags)
{
  char *v4; // rax
  char *v5; // rbx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mPrev; // rax
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *i; // rax
  __int64 j; // r8
  __int64 mOffset; // rax
  char *v10; // rcx
  char *v11; // rax
  char *v12; // rax

  v4 = UFG::qMalloc(0x28ui64, "RoadNetworkNode.RoadNetworkNodeModification", 0i64);
  v5 = v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    *((_QWORD *)v4 + 3) = 0i64;
    *((_QWORD *)v4 + 2) = 0i64;
    *((_QWORD *)v4 + 4) = this;
    UFG::qArray<enum DNA::PropertyState::Enum,0>::Clone(laneFlags, (UFG::qArray<unsigned long,0> *)v4 + 1);
  }
  else
  {
    v5 = 0i64;
  }
  mPrev = this->mModifications.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5;
  *(_QWORD *)v5 = mPrev;
  *((_QWORD *)v5 + 1) = &this->mModifications;
  this->mModifications.mNode.mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5;
  for ( i = this->mModifications.mNode.mNext;
        i != (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&this->mModifications;
        i = i->mNext )
  {
    if ( i == (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5 )
      break;
  }
  if ( *((_DWORD *)v5 + 4) )
  {
    for ( j = 0i64; (unsigned int)j < (unsigned __int8)this->mNumLanes; j = (unsigned int)(j + 1) )
    {
      mOffset = this->mLane.mOffset;
      if ( mOffset )
        v10 = (char *)&this->mLane + mOffset;
      else
        v10 = 0i64;
      v11 = &v10[8 * j];
      if ( *(_QWORD *)v11 )
        v12 = &v11[*(_QWORD *)v11];
      else
        v12 = 0i64;
      v12[44] = *(_BYTE *)(*((_QWORD *)v5 + 3) + 4 * j);
    }
  }
  return (UFG::RoadNetworkNodeModification *)v5;
}

// File Line: 999
// RVA: 0xE0000
void __fastcall UFG::RoadNetworkNode::RemoveModification(
        UFG::RoadNetworkNode *this,
        UFG::RoadNetworkNodeModification *modification)
{
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mPrev; // r8
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mNext; // rax

  mPrev = modification->mPrev;
  mNext = modification->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  modification->mPrev = modification;
  modification->mNext = modification;
  UFG::RoadNetworkNode::ApplyAllModifications(this);
}

// File Line: 1006
// RVA: 0xD2370
void __fastcall UFG::RoadNetworkNode::ApplyAllModifications(UFG::RoadNetworkNode *this)
{
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mNext; // r10
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0> *i; // rbx
  __int64 j; // r8
  __int64 mOffset; // rax
  char *v6; // rcx
  char *v7; // rax
  char *v8; // rdx
  char v9; // cl

  mNext = this->mModifications.mNode.mNext;
  for ( i = &this->mModifications;
        mNext != (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)i;
        mNext = mNext->mNext )
  {
    if ( LODWORD(mNext[1].mPrev) )
    {
      for ( j = 0i64; (unsigned int)j < (unsigned __int8)this->mNumLanes; v8[44] = v9 )
      {
        mOffset = this->mLane.mOffset;
        if ( mOffset )
          v6 = (char *)&this->mLane + mOffset;
        else
          v6 = 0i64;
        v7 = &v6[8 * j];
        if ( *(_QWORD *)v7 )
          v8 = &v7[*(_QWORD *)v7];
        else
          v8 = 0i64;
        v9 = *((_BYTE *)&mNext[1].mNext->mPrev + 4 * j);
        j = (unsigned int)(j + 1);
      }
    }
  }
}

// File Line: 1030
// RVA: 0xD0F30
void __fastcall UFG::RoadNetworkSegment::~RoadNetworkSegment(UFG::RoadNetworkSegment *this)
{
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *p_mSubSegmentCollection; // rdi
  UFG::RoadNetworkSubSegment *mNext; // rbx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *mPrev; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v5; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v6; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v7; // rax
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v8; // rcx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v9; // rax

  p_mSubSegmentCollection = &this->mSubSegmentCollection;
  mNext = (UFG::RoadNetworkSubSegment *)this->mSubSegmentCollection.mNode.mNext;
  if ( mNext != (UFG::RoadNetworkSubSegment *)&this->mSubSegmentCollection )
  {
    do
    {
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::RoadNetworkSubSegment::~RoadNetworkSubSegment(mNext);
      operator delete[](mNext);
      mNext = (UFG::RoadNetworkSubSegment *)p_mSubSegmentCollection->mNode.mNext;
    }
    while ( mNext != (UFG::RoadNetworkSubSegment *)p_mSubSegmentCollection );
  }
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0>::DeleteNodes(&this->mModifications);
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0>::DeleteNodes(p_mSubSegmentCollection);
  v6 = p_mSubSegmentCollection->mNode.mPrev;
  v7 = p_mSubSegmentCollection->mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_mSubSegmentCollection->mNode.mPrev = &p_mSubSegmentCollection->mNode;
  p_mSubSegmentCollection->mNode.mNext = &p_mSubSegmentCollection->mNode;
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0>::DeleteNodes(&this->mModifications);
  v8 = this->mModifications.mNode.mPrev;
  v9 = this->mModifications.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->mModifications.mNode.mPrev = &this->mModifications.mNode;
  this->mModifications.mNode.mNext = &this->mModifications.mNode;
}

// File Line: 1335
// RVA: 0xE0200
void __fastcall UFG::RoadNetworkSegment::SetBitsFromRoadPropertySet(UFG::RoadNetworkSegment *this)
{
  UFG::qPropertySet *RoadPropertySet; // rax
  UFG::qPropertySet *v3; // rdi
  bool *v4; // rax
  char *v5; // rcx
  int v6; // eax
  bool *v7; // rax
  char *v8; // rcx
  int v9; // eax
  bool *v10; // rax
  char *v11; // rcx
  int v12; // eax
  bool *v13; // rax
  char *v14; // rcx
  bool *v15; // rax
  bool v16; // al
  bool *v17; // rax
  char *v18; // rcx
  unsigned int *v19; // rax
  UFG::qPropertySet *AdditionalRoadPropertySet; // rax
  bool *v21; // rax
  char *v22; // rcx
  char v23; // [rsp+38h] [rbp+10h] BYREF

  RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(this);
  v3 = RoadPropertySet;
  if ( RoadPropertySet )
  {
    v23 = 0;
    v4 = UFG::qPropertySet::Get<bool>(RoadPropertySet, &qSymbol_WayFinderNoPlayer, DEPTH_RECURSE);
    v5 = &v23;
    if ( v4 )
      v5 = (char *)v4;
    v6 = (unsigned __int8)*v5;
    v23 = 0;
    *(_DWORD *)&this->mBits ^= (*(_DWORD *)&this->mBits ^ v6) & 1;
    v7 = UFG::qPropertySet::Get<bool>(v3, &qSymbol_WayFinderNoVehicle, DEPTH_RECURSE);
    v8 = &v23;
    if ( v7 )
      v8 = (char *)v7;
    v9 = (unsigned __int8)*v8;
    v23 = 0;
    *(_DWORD *)&this->mBits ^= (*(_DWORD *)&this->mBits ^ (2 * v9)) & 2;
    v10 = UFG::qPropertySet::Get<bool>(v3, &qSymbol_GpsRestricted, DEPTH_RECURSE);
    v11 = &v23;
    if ( v10 )
      v11 = (char *)v10;
    v12 = (unsigned __int8)*v11;
    v23 = 0;
    *(_DWORD *)&this->mBits ^= (*(_DWORD *)&this->mBits ^ (4 * v12)) & 4;
    v13 = UFG::qPropertySet::Get<bool>(v3, &qSymbol_WayFinderGPSOnly, DEPTH_RECURSE);
    v14 = &v23;
    if ( v13 )
      v14 = (char *)v13;
    *(_DWORD *)&this->mBits ^= (*(_DWORD *)&this->mBits ^ (8 * (unsigned __int8)*v14)) & 8;
    v15 = UFG::qPropertySet::Get<bool>(v3, &qSymbol_RoadDriveableTraffic, DEPTH_RECURSE);
    v16 = v15 && !*v15;
    *(_DWORD *)&this->mBits &= ~0x10u;
    *(_DWORD *)&this->mBits |= 16 * v16;
    v23 = 0;
    v17 = UFG::qPropertySet::Get<bool>(v3, &qSymbol_ExtendBeyondVisibleAreaLimit, DEPTH_RECURSE);
    v18 = &v23;
    if ( v17 )
      v18 = (char *)v17;
    *(_DWORD *)&this->mBits ^= (*(_DWORD *)&this->mBits ^ ((unsigned __int8)*v18 << 6)) & 0x40;
    v19 = UFG::qPropertySet::Get<unsigned long>(v3, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
    if ( v19 )
      this->mRoadNetworkType.mValue = *v19;
  }
  AdditionalRoadPropertySet = UFG::RoadNetworkSegment::GetAdditionalRoadPropertySet(this);
  if ( AdditionalRoadPropertySet )
  {
    v23 = 0;
    v21 = UFG::qPropertySet::Get<bool>(AdditionalRoadPropertySet, &qSymbol_BuildVisibleRoadNetworkByGrid, DEPTH_RECURSE);
    v22 = &v23;
    if ( v21 )
      v22 = (char *)v21;
    *(_DWORD *)&this->mBits ^= (*(_DWORD *)&this->mBits ^ (32 * (unsigned __int8)*v22)) & 0x20;
  }
}

// File Line: 1366
// RVA: 0x1460A30
__int64 dynamic_initializer_for__gRoadSetPropertySetName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-roadnetwork-roadset", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gRoadSetPropertySetName, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gRoadSetPropertySetName__);
}

// File Line: 1370
// RVA: 0xDB8A0
UFG::qPropertySet *__fastcall UFG::RoadNetworkSegment::GetRoadPropertySet(UFG::RoadNetworkSegment *this)
{
  UFG::qPropertySet *result; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // r14
  unsigned int mNumElements; // esi
  unsigned int v7; // ebx
  UFG::qSymbol *v8; // rax
  UFG::qPropertySet *v9; // rax
  UFG::qPropertySet *v10; // rdi

  result = this->mpPropertySetCached;
  if ( !result )
  {
    PropertySet = UFG::PropertySetManager::GetPropertySet(&gRoadSetPropertySetName);
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &qSymbol_RoadSet, DEPTH_RECURSE);
    v5 = v4;
    if ( v4 && (mNumElements = v4->mNumElements, v7 = 0, mNumElements) )
    {
      while ( 1 )
      {
        v8 = UFG::qPropertyList::Get<UFG::qSymbol>(v5, v7);
        v9 = UFG::PropertySetManager::GetPropertySet(v8);
        v10 = v9;
        if ( v9 )
        {
          if ( this->mPropertyID1 == *UFG::qPropertySet::Get<unsigned long>(v9, &qSymbol_RoadID, DEPTH_RECURSE) )
            break;
        }
        if ( ++v7 >= mNumElements )
          return 0i64;
      }
      if ( (v10->mFlags & 1) != 0 )
        this->mpPropertySetCached = v10;
      return v10;
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}

// File Line: 1408
// RVA: 0x1460A70
__int64 dynamic_initializer_for__gRoadSetPropertySetNameAdditional__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-roadnetwork-additional-roadset", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gRoadSetPropertySetNameAdditional, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gRoadSetPropertySetNameAdditional__);
}

// File Line: 1414
// RVA: 0xD5950
UFG::qPropertySet *__fastcall UFG::RoadNetworkSegment::GetAdditionalRoadPropertySet(UFG::RoadNetworkSegment *this)
{
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v3; // rax
  UFG::qPropertyList *v4; // rbp
  unsigned int mNumElements; // esi
  unsigned int v6; // ebx
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::qPropertySet *v9; // rdi

  PropertySet = UFG::PropertySetManager::GetPropertySet(&gRoadSetPropertySetNameAdditional);
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &qSymbol_RoadSet, DEPTH_RECURSE);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  mNumElements = v3->mNumElements;
  v6 = 0;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    v7 = UFG::qPropertyList::Get<UFG::qSymbol>(v4, v6);
    v8 = UFG::PropertySetManager::GetPropertySet(v7);
    v9 = v8;
    if ( v8 )
    {
      if ( this->mPropertyID2 == *UFG::qPropertySet::Get<unsigned long>(v8, &qSymbol_RoadIDAdditional, DEPTH_RECURSE) )
        break;
    }
    if ( ++v6 >= mNumElements )
      return 0i64;
  }
  return v9;
}

// File Line: 1449
// RVA: 0xDB6B0
float __fastcall UFG::RoadNetworkSegment::GetRoadDensity(UFG::RoadNetworkSegment *this)
{
  float v1; // xmm6_4
  UFG::qPropertySet *RoadPropertySet; // rbx
  float m_SecondsSinceMidnight; // xmm7_4
  float *v4; // rax
  float v5; // xmm0_4

  v1 = FLOAT_0_0123;
  RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(this);
  if ( RoadPropertySet )
  {
    if ( ((m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight,
           UFG::TimeOfDayManager::GetInstance(),
           m_SecondsSinceMidnight >= 75600.0)
       || (UFG::TimeOfDayManager::GetInstance(), m_SecondsSinceMidnight <= 21600.0))
      && (v4 = UFG::qPropertySet::Get<float>(RoadPropertySet, &qSymbol_DensityNight, DEPTH_RECURSE)) != 0i64
      || (v4 = UFG::qPropertySet::Get<float>(RoadPropertySet, &qSymbol_Density, DEPTH_RECURSE)) != 0i64 )
    {
      v1 = *v4;
      if ( *v4 > 0.0 )
        v1 = 1.0 / v1;
    }
  }
  v5 = UFG::WheeledVehicleManager::mRoadDensityScale;
  if ( UFG::WheeledVehicleManager::mRoadDensityScale >= UFG::WheeledVehicleManager::mMaxRoadDensityScale )
    v5 = UFG::WheeledVehicleManager::mMaxRoadDensityScale;
  return v5 * v1;
}

// File Line: 1484
// RVA: 0xDB850
__int64 __fastcall UFG::RoadNetworkSegment::GetRoadNetworkType(UFG::RoadNetworkSegment *this)
{
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int v3; // ebx
  unsigned int *v4; // rax

  if ( this->mpPropertySetCached )
    return this->mRoadNetworkType.mValue;
  RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(this);
  v3 = 0;
  if ( RoadPropertySet )
  {
    v4 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
    if ( v4 )
      return *v4;
  }
  return v3;
}

// File Line: 1505
// RVA: 0xDEFA0
bool __fastcall UFG::RoadNetworkSegment::IsWater(UFG::RoadNetworkSegment *this)
{
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int v3; // ebx
  unsigned int *v4; // rax

  if ( this->mpPropertySetCached )
    return this->mRoadNetworkType.mValue - 2 <= 1;
  RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(this);
  v3 = 0;
  if ( RoadPropertySet )
  {
    v4 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
    if ( v4 )
      v3 = *v4;
  }
  return v3 - 2 <= 1;
}

// File Line: 1514
// RVA: 0xD1CC0
void __fastcall UFG::RoadNetworkSegment::AddParkingSpot(UFG::RoadNetworkSegment *this, UFG::ParkingSpot *spot)
{
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *mNext; // r8
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *p_mSubSegmentCollection; // rbx
  __int64 mOffset; // r10
  float mClosestT; // xmm0_4
  __int64 mClosestLaneIndex; // rdi
  char *v9; // rax
  char *v10; // rcx
  char *v11; // rdx
  __int64 v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm2_4
  __int64 v15; // rax
  char *v16; // r9
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 *v19; // rax
  __int64 v20; // rcx
  char *v21; // rax
  bool v22; // cc
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v23; // rax

  mNext = this->mSubSegmentCollection.mNode.mNext;
  p_mSubSegmentCollection = &this->mSubSegmentCollection;
  if ( mNext != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&this->mSubSegmentCollection )
  {
    mOffset = this->mLane.mOffset;
    mClosestT = spot->mClosestT;
    mClosestLaneIndex = spot->mClosestLaneIndex;
    do
    {
      if ( mOffset )
        v9 = (char *)&this->mLane + mOffset;
      else
        v9 = 0i64;
      v10 = &v9[8 * mClosestLaneIndex];
      if ( *(_QWORD *)v10 )
        v11 = &v10[*(_QWORD *)v10];
      else
        v11 = 0i64;
      v12 = *((unsigned __int16 *)v11 + 18);
      v13 = *((float *)&mNext[5].mPrev->mPrev + v12);
      v14 = *((float *)&mNext[5].mNext->mPrev + v12);
      v15 = *((_QWORD *)v11 + 1);
      if ( v15 )
        v16 = &v11[v15 + 8];
      else
        v16 = 0i64;
      v17 = *(_QWORD *)v11;
      if ( *(_QWORD *)v11 )
        v17 += (__int64)v11;
      v18 = *(_QWORD *)(v17 + 48);
      if ( v18 )
        v19 = (__int64 *)(v18 + v17 + 48);
      else
        v19 = 0i64;
      v20 = *v19;
      if ( *v19 )
        v20 += (__int64)v19;
      v21 = *(char **)(v20 + 8);
      if ( v21 )
        v21 += v20 + 8;
      if ( v16 == v21 )
      {
        if ( mClosestT < v13 )
          goto LABEL_27;
        v22 = mClosestT <= v14;
      }
      else
      {
        if ( mClosestT < v14 )
          goto LABEL_27;
        v22 = mClosestT <= v13;
      }
      if ( v22 )
      {
        v23 = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)mNext[6].mNext;
        v23->mNext = &spot->UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot>;
        spot->UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot>::mPrev = v23;
        spot->UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot>::mNext = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&mNext[6].mNext;
        mNext[6].mNext = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&spot->UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot>;
        ++LOWORD(mNext[6].mPrev);
        return;
      }
LABEL_27:
      mNext = mNext->mNext;
    }
    while ( mNext != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)p_mSubSegmentCollection );
  }
}

// File Line: 1531
// RVA: 0xD5CB0
void __fastcall UFG::RoadNetworkSubSegment::GetAvailableParkingSpots(
        UFG::RoadNetworkSubSegment *this,
        UFG::qArray<UFG::ParkingSpot *,0> *availableParkingSpots)
{
  UFG::ParkingSpot **p; // rcx
  UFG::RoadNetworkSubSegment *v5; // r12
  UFG::RoadNetworkSubSegment *v6; // r14
  __int64 size; // r15
  unsigned int capacity; // ebx
  unsigned int v9; // esi
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  char *v12; // rax
  UFG::ParkingSpot **v13; // rbp
  __int64 i; // r9
  __int64 v15; // r8
  UFG::ParkingSpot **v16; // rax

  p = availableParkingSpots->p;
  if ( p )
    operator delete[](p);
  availableParkingSpots->p = 0i64;
  *(_QWORD *)&availableParkingSpots->size = 0i64;
  v5 = (UFG::RoadNetworkSubSegment *)((char *)this - 88);
  v6 = (UFG::RoadNetworkSubSegment *)&this->mParkingSpotCollection.mNode.mNext[-12];
  if ( v6 != (UFG::RoadNetworkSubSegment *)&this[-1].mPosition.z )
  {
    do
    {
      if ( ((unsigned __int8 (__fastcall *)(UFG::RoadNetworkSubSegment *))v6->mPrev[9].mPrev)(v6) )
      {
        size = availableParkingSpots->size;
        capacity = availableParkingSpots->capacity;
        v9 = size + 1;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v10 = 2 * capacity;
          else
            v10 = 1;
          for ( ; v10 < v9; v10 *= 2 )
            ;
          if ( v10 <= 2 )
            v10 = 2;
          if ( v10 - v9 > 0x10000 )
            v10 = size + 65537;
          if ( v10 != (_DWORD)size )
          {
            v11 = 8i64 * v10;
            if ( !is_mul_ok(v10, 8ui64) )
              v11 = -1i64;
            v12 = UFG::qMalloc(v11, "qArray.Add", 0i64);
            v13 = (UFG::ParkingSpot **)v12;
            if ( availableParkingSpots->p )
            {
              for ( i = 0i64;
                    (unsigned int)i < availableParkingSpots->size;
                    *(_QWORD *)&v12[v15 * 8] = availableParkingSpots->p[v15] )
              {
                v15 = i;
                i = (unsigned int)(i + 1);
              }
              operator delete[](availableParkingSpots->p);
            }
            availableParkingSpots->p = v13;
            availableParkingSpots->capacity = v10;
          }
        }
        v16 = availableParkingSpots->p;
        availableParkingSpots->size = v9;
        v16[size] = (UFG::ParkingSpot *)v6;
      }
      v6 = (UFG::RoadNetworkSubSegment *)(v6[1].mBeginTCollection - 48);
    }
    while ( v6 != v5 );
  }
}

// File Line: 1542
// RVA: 0xDAF00
__int64 __fastcall UFG::RoadNetworkSubSegment::GetNumAvailableParkingSpots(UFG::RoadNetworkSubSegment *this)
{
  UFG::RoadNetworkSubSegment *v1; // rsi
  unsigned int v2; // edi
  UFG::RoadNetworkSubSegment *v3; // rbx

  v1 = (UFG::RoadNetworkSubSegment *)((char *)this - 88);
  v2 = 0;
  v3 = (UFG::RoadNetworkSubSegment *)&this->mParkingSpotCollection.mNode.mNext[-12];
  if ( v3 != (UFG::RoadNetworkSubSegment *)&this[-1].mPosition.z )
  {
    do
    {
      if ( ((unsigned __int8 (__fastcall *)(UFG::RoadNetworkSubSegment *))v3->mPrev[9].mPrev)(v3) )
        ++v2;
      v3 = (UFG::RoadNetworkSubSegment *)(v3[1].mBeginTCollection - 48);
    }
    while ( v3 != v1 );
  }
  return v2;
}

// File Line: 1555
// RVA: 0xDF800
void __fastcall UFG::RoadNetworkSegment::RecalculateLaneOffset(UFG::RoadNetworkSegment *this, unsigned int laneIndex)
{
  __int64 mOffset; // rax
  __int64 v3; // r15
  char *v4; // rdx
  __int64 v5; // rax
  UFG::RoadNetworkLane *v6; // rsi
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *mNext; // rbp
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *p_mSubSegmentCollection; // r12
  __int64 i; // rdi
  __int64 v10; // rbx
  float v11; // xmm0_4
  float v12; // xmm1_4

  mOffset = this->mLane.mOffset;
  v3 = laneIndex;
  if ( mOffset )
    v4 = (char *)&this->mLane + mOffset;
  else
    v4 = 0i64;
  v5 = *(_QWORD *)&v4[8 * v3];
  if ( v5 )
    v6 = (UFG::RoadNetworkLane *)&v4[8 * v3 + v5];
  else
    v6 = 0i64;
  mNext = this->mSubSegmentCollection.mNode.mNext;
  p_mSubSegmentCollection = &this->mSubSegmentCollection;
  for ( v6->mOffset = 0.0;
        mNext != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)p_mSubSegmentCollection;
        mNext = mNext->mNext )
  {
    for ( i = (__int64)&mNext[7].mPrev[-12];
          (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> **)i != &mNext[-6].mNext;
          i = *(_QWORD *)(i + 200) - 192i64 )
    {
      if ( (_DWORD)v3 == *(unsigned __int16 *)(i + 136) )
      {
        v10 = *(_QWORD *)(i + 104);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10);
        v11 = UFG::RoadNetworkLane::CalculateParkingOffset(v6, (UFG::qVector3 *)(v10 + 176));
        v12 = v6->mOffset;
        if ( v12 <= v11 )
          v12 = v11;
        v6->mOffset = v12;
      }
    }
  }
}

// File Line: 1583
// RVA: 0xD3F00
void __fastcall UFG::RoadNetworkSegment::CreateSubSegments(UFG::RoadNetworkSegment *this)
{
  __int64 v2; // rax
  __int64 mOffset; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v4; // rbx
  char *v5; // rcx
  char *v6; // rdx
  char *v7; // rax
  char *v8; // rcx
  unsigned int v9; // edx
  __int64 v10; // rax
  UFG::RoadNetworkConnection *v11; // rcx
  float v12; // xmm7_4
  char *v13; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v14; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v15; // rax
  float v16; // xmm7_4
  char *v17; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v18; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v19; // rcx
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *p_mSubSegmentCollection; // rdi
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v21; // rax
  char *v22; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v23; // rax
  float v24; // xmm9_4
  float v25; // xmm8_4
  float v26; // xmm6_4
  char *v27; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v28; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v29; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *mPrev; // rax
  int v31; // ebp
  float v32; // xmm10_4
  unsigned int v33; // r14d
  float v34; // xmm10_4
  unsigned int v35; // r15d
  char *v36; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v37; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v38; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v39; // rax
  float v40; // xmm6_4
  char *v41; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v42; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v43; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v44; // rax
  int v45; // ebp
  float v46; // xmm8_4
  float v47; // xmm9_4
  __int64 v48; // r14
  char *v49; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v50; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v51; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v52; // rax
  char *v53; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v54; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v55; // rax

  v2 = (unsigned int)(((unsigned __int8)this->mNumLanes - 1) / 2);
  mOffset = this->mLane.mOffset;
  v4 = 0i64;
  if ( mOffset )
    v5 = (char *)&this->mLane + mOffset;
  else
    v5 = 0i64;
  v6 = &v5[8 * v2];
  if ( *(_QWORD *)v6 )
    v7 = &v6[*(_QWORD *)v6];
  else
    v7 = 0i64;
  if ( *(_QWORD *)v7 )
    v8 = &v7[*(_QWORD *)v7];
  else
    v8 = 0i64;
  v9 = *((unsigned __int16 *)v7 + 19);
  v10 = *((_QWORD *)v8 + 4);
  if ( v10 )
    v11 = (UFG::RoadNetworkConnection *)&v8[v10 + 32];
  else
    v11 = 0i64;
  v12 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v11, v9)->mNode.mOffset + 1);
  if ( v12 >= 30.0 )
  {
    if ( v12 >= 45.0 )
    {
      v24 = 1.0 / v12;
      v25 = (float)(1.0 / v12) * 15.0;
      v26 = v25;
      v27 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v27 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v27, this, 15.0, 0.0);
        v29 = v28;
      }
      else
      {
        v29 = 0i64;
      }
      p_mSubSegmentCollection = &this->mSubSegmentCollection;
      mPrev = this->mSubSegmentCollection.mNode.mPrev;
      mPrev->mNext = v29;
      v29->mPrev = mPrev;
      v29->mNext = &this->mSubSegmentCollection.mNode;
      this->mSubSegmentCollection.mNode.mPrev = v29;
      v31 = 1;
      v32 = (float)(v12 - 30.0) * 0.025;
      v33 = (int)v32;
      v34 = (float)(v32 - (float)(int)v32) * 40.0;
      v35 = 0;
      if ( v34 < 15.0 )
      {
        v26 = v25 * 2.0;
        v36 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
        if ( v36 )
        {
          UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v36, this, 15.0, v25);
          v38 = v37;
        }
        else
        {
          v38 = 0i64;
        }
        v39 = p_mSubSegmentCollection->mNode.mPrev;
        v39->mNext = v38;
        v38->mPrev = v39;
        v38->mNext = &p_mSubSegmentCollection->mNode;
        p_mSubSegmentCollection->mNode.mPrev = v38;
        v31 = 2;
        v25 = v25 * 2.0;
        v34 = 40.0 - (float)(15.0 - v34);
        v35 = 1;
      }
      v40 = v26 + (float)(v24 * v34);
      v41 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v41 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v41, this, v34, v25);
        v43 = v42;
      }
      else
      {
        v43 = 0i64;
      }
      v44 = p_mSubSegmentCollection->mNode.mPrev;
      v44->mNext = v43;
      v43->mPrev = v44;
      v43->mNext = &p_mSubSegmentCollection->mNode;
      p_mSubSegmentCollection->mNode.mPrev = v43;
      v45 = v31 + 1;
      v46 = v40;
      v47 = v24 * 40.0;
      if ( v35 < v33 )
      {
        v48 = v33 - v35;
        do
        {
          v40 = v40 + v47;
          v49 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
          if ( v49 )
          {
            UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v49, this, 40.0, v46);
            v51 = v50;
          }
          else
          {
            v51 = 0i64;
          }
          v52 = p_mSubSegmentCollection->mNode.mPrev;
          v52->mNext = v51;
          v51->mPrev = v52;
          v51->mNext = &p_mSubSegmentCollection->mNode;
          p_mSubSegmentCollection->mNode.mPrev = v51;
          ++v45;
          v46 = v40;
          --v48;
        }
        while ( v48 );
      }
      v53 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v53 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment(
          (UFG::RoadNetworkSubSegment *)v53,
          this,
          (float)(1.0 - v40) * v12,
          v40);
        v4 = v54;
      }
    }
    else
    {
      v16 = v12 * 0.5;
      v17 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v17 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v17, this, v16, 0.0);
        v19 = v18;
      }
      else
      {
        v19 = 0i64;
      }
      p_mSubSegmentCollection = &this->mSubSegmentCollection;
      v21 = this->mSubSegmentCollection.mNode.mPrev;
      v21->mNext = v19;
      v19->mPrev = v21;
      v19->mNext = &this->mSubSegmentCollection.mNode;
      this->mSubSegmentCollection.mNode.mPrev = v19;
      v22 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v22 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v22, this, v16, 0.5);
        v4 = v23;
      }
    }
    v55 = p_mSubSegmentCollection->mNode.mPrev;
    v55->mNext = v4;
    v4->mPrev = v55;
    v4->mNext = &p_mSubSegmentCollection->mNode;
    p_mSubSegmentCollection->mNode.mPrev = v4;
  }
  else
  {
    v13 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
    if ( v13 )
    {
      UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v13, this, v12, 0.0);
      v4 = v14;
    }
    v15 = this->mSubSegmentCollection.mNode.mPrev;
    v15->mNext = v4;
    v4->mPrev = v15;
    v4->mNext = &this->mSubSegmentCollection.mNode;
    this->mSubSegmentCollection.mNode.mPrev = v4;
  }
}

// File Line: 1735
// RVA: 0xD9F20
// local variable allocation has failed, the output may be wrong!
float __fastcall UFG::RoadNetworkSegment::GetMatchingT(
        UFG::RoadNetworkSegment *this,
        const unsigned int laneIndex,
        double t,
        const unsigned int otherLaneIndex)
{
  __int64 v4; // r14
  __int64 mOffset; // rax
  char *v7; // rcx
  char *v8; // rdx
  char *v9; // rsi
  char *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // r8
  char *v13; // rdx
  __int64 v14; // rax
  char *v15; // r8
  unsigned int v16; // edx
  __int64 v17; // rax
  UFG::RoadNetworkConnection *v18; // rcx
  float v19; // xmm7_4
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v22; // rax
  __int64 v23; // rax
  __int128 v24; // xmm6
  char *v25; // rcx
  __int64 v26; // rax
  char *v27; // rdi
  __int64 v28; // rax
  char *v29; // rdx
  __int64 v30; // rax
  __int64 *v31; // rcx
  __int64 v32; // rax
  char *v33; // rcx
  __int64 v34; // rax
  bool v35; // r9
  char *v36; // r8
  __int64 v37; // rcx
  char *v38; // rax
  __int64 *v39; // rdx
  __int64 v40; // rax
  char *v41; // rdx
  __int128 v42; // xmm8
  bool v43; // r14
  char *v44; // rax
  UFG::RoadNetworkConnection *v45; // rcx
  UFG::qBezierPathMemImaged *v46; // rbx
  unsigned int v47; // eax
  UFG::qBezierSplineMemImaged *v48; // rax
  __int64 v49; // rax
  UFG::RoadNetworkConnection *v50; // rcx
  UFG::qBezierPathMemImaged *v51; // rbx
  unsigned int v52; // eax
  UFG::qBezierSplineMemImaged *v53; // rax
  float v54; // xmm1_4
  int v55; // esi
  __int64 v56; // rax
  __int128 v57; // xmm6
  UFG::RoadNetworkConnection *v58; // rcx
  UFG::qBezierPathMemImaged *v59; // rbx
  unsigned int v60; // eax
  UFG::qBezierSplineMemImaged *v61; // rax
  float v62; // xmm1_4
  UFG::qVector3 v2; // [rsp+8h] [rbp-79h] BYREF
  UFG::qVector3 v65; // [rsp+18h] [rbp-69h] BYREF
  UFG::qVector3 v66; // [rsp+28h] [rbp-59h] BYREF
  UFG::qVector3 v67; // [rsp+38h] [rbp-49h] BYREF
  UFG::qVector3 result; // [rsp+48h] [rbp-39h] BYREF
  float splineT; // [rsp+F0h] [rbp+6Fh] BYREF

  v4 = otherLaneIndex;
  mOffset = this->mLane.mOffset;
  if ( mOffset )
    v7 = (char *)&this->mLane + mOffset;
  else
    v7 = 0i64;
  v8 = &v7[8 * laneIndex];
  if ( *(_QWORD *)v8 )
    v9 = &v8[*(_QWORD *)v8];
  else
    v9 = 0i64;
  if ( *(_QWORD *)v9 )
    v10 = &v9[*(_QWORD *)v9];
  else
    v10 = 0i64;
  v11 = *((_QWORD *)v10 + 6);
  v12 = *((unsigned __int16 *)v9 + 18);
  if ( v11 )
    v13 = &v10[v11 + 48];
  else
    v13 = 0i64;
  v14 = *(_QWORD *)&v13[8 * v12];
  v15 = &v13[8 * v12];
  if ( v14 )
    v14 += (__int64)v15;
  v16 = *(unsigned __int16 *)(v14 + 38);
  v17 = *((_QWORD *)v10 + 4);
  if ( v17 )
    v18 = (UFG::RoadNetworkConnection *)&v10[v17 + 32];
  else
    v18 = 0i64;
  v19 = 0.0;
  splineT = 0.0;
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v18, v16);
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, *(const float *)&t, &splineT);
  v22 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::qBezierSplineMemImaged::GetTangent(v22, &result, splineT);
  v23 = this->mLane.mOffset;
  v24 = *(_OWORD *)&t;
  if ( v23 )
    v25 = (char *)&this->mLane + v23;
  else
    v25 = 0i64;
  v26 = *(_QWORD *)&v25[8 * v4];
  if ( v26 )
    v27 = &v25[8 * v4 + v26];
  else
    v27 = 0i64;
  v28 = *((_QWORD *)v27 + 1);
  if ( v28 )
    v29 = &v27[v28 + 8];
  else
    v29 = 0i64;
  v30 = *(_QWORD *)v27;
  if ( *(_QWORD *)v27 )
    v30 += (__int64)v27;
  v31 = *(__int64 **)(v30 + 48);
  if ( v31 )
    v31 = (__int64 *)((char *)v31 + v30 + 48);
  v32 = *v31;
  if ( *v31 )
    v32 += (__int64)v31;
  v33 = *(char **)(v32 + 8);
  if ( v33 )
    v33 += v32 + 8;
  v34 = *((_QWORD *)v9 + 1);
  v35 = v29 != v33;
  if ( v34 )
    v36 = &v9[v34 + 8];
  else
    v36 = 0i64;
  v37 = *(_QWORD *)v9;
  if ( *(_QWORD *)v9 )
    v38 = &v9[v37];
  else
    v38 = 0i64;
  v39 = (__int64 *)*((_QWORD *)v38 + 6);
  if ( v39 )
    v39 = (__int64 *)((char *)v39 + (_QWORD)v38 + 48);
  v40 = *v39;
  if ( *v39 )
    v40 += (__int64)v39;
  v41 = *(char **)(v40 + 8);
  if ( v41 )
    v41 += v40 + 8;
  v42 = (unsigned int)FLOAT_1_0;
  v43 = v35 != (v36 != v41);
  if ( v35 != (v36 != v41) )
  {
    v24 = (unsigned int)FLOAT_1_0;
    *(float *)&v24 = 1.0 - *(float *)&t;
  }
  if ( v37 )
    v44 = &v9[v37];
  else
    v44 = 0i64;
  v45 = (UFG::RoadNetworkConnection *)*((_QWORD *)v44 + 4);
  if ( v45 )
    v45 = (UFG::RoadNetworkConnection *)((char *)v45 + (_QWORD)v44 + 32);
  v46 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v45, *((unsigned __int16 *)v9 + 19));
  v47 = UFG::qBezierPathMemImaged::GetSplineParameters(v46, *(const float *)&t, &splineT);
  v48 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)v46,
                                         v47);
  UFG::RoadNetworkLane::GetOffsetPos(&v65, v48, splineT, *((float *)v9 + 10));
  v49 = *(_QWORD *)v27;
  if ( *(_QWORD *)v27 )
    v49 += (__int64)v27;
  v50 = *(UFG::RoadNetworkConnection **)(v49 + 32);
  if ( v50 )
    v50 = (UFG::RoadNetworkConnection *)((char *)v50 + v49 + 32);
  v51 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v50, *((unsigned __int16 *)v27 + 19));
  v52 = UFG::qBezierPathMemImaged::GetSplineParameters(v51, *(const float *)&v24, &splineT);
  v53 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)v51,
                                         v52);
  UFG::RoadNetworkLane::GetOffsetPos(&v66, v53, splineT, *((float *)v27 + 10));
  v54 = UFG::qAngleBetween(&result, &v2);
  if ( (float)(1.5707964 - v54) > 0.06981317 )
  {
    if ( v54 <= 1.5707964 )
    {
      if ( !v43 )
      {
        v42 = v24;
        goto LABEL_65;
      }
    }
    else if ( v43 )
    {
      v42 = v24;
LABEL_65:
      v55 = 0;
      while ( 1 )
      {
        v56 = *(_QWORD *)v27;
        v57 = v42;
        *(float *)&v57 = (float)((float)(*(float *)&v42 - v19) * 0.5) + v19;
        if ( *(_QWORD *)v27 )
          v56 += (__int64)v27;
        v58 = *(UFG::RoadNetworkConnection **)(v56 + 32);
        if ( v58 )
          v58 = (UFG::RoadNetworkConnection *)((char *)v58 + v56 + 32);
        v59 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v58,
                                             *((unsigned __int16 *)v27 + 19));
        v60 = UFG::qBezierPathMemImaged::GetSplineParameters(v59, *(const float *)&v57, &splineT);
        v61 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                               (UFG::RoadNetworkConnection *)v59,
                                               v60);
        UFG::RoadNetworkLane::GetOffsetPos(&v67, v61, splineT, *((float *)v27 + 10));
        v62 = UFG::qAngleBetween(&result, &v2);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(1.5707964 - v62) & _xmm) < 0.06981317 )
          return *(float *)&v57;
        if ( v62 <= 1.5707964 )
        {
          if ( v43 )
          {
LABEL_76:
            v19 = (float)((float)(*(float *)&v42 - v19) * 0.5) + v19;
            goto LABEL_77;
          }
          v42 = v57;
        }
        else
        {
          if ( !v43 )
            goto LABEL_76;
          v42 = v57;
        }
LABEL_77:
        if ( ++v55 >= 10 )
          return *(float *)&v57;
      }
    }
    v19 = *(float *)&v24;
    goto LABEL_65;
  }
  return *(float *)&v24;
}*(float *)&v57;
      }
    }
    v19 = *(float *)&v24;
    goto LABEL_65;
  }
  return *(float *)&v24;
}

// File Line: 1809
// RVA: 0xDBF30
float __fastcall UFG::RoadNetworkSegment::GetTFromDistance(
        UFG::RoadNetworkSegment *this,
        UFG::RoadNetworkLane *lane,
        float distance,
        float beginT,
        bool forward)
{
  UFG::RoadNetworkConnection *v5; // rcx
  char *v6; // rax
  unsigned int mPathIndex; // r8d
  __int64 v8; // rdx
  float v9; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float result; // xmm0_4

  v5 = 0i64;
  if ( lane->mNode.mOffset )
    v6 = (char *)lane + lane->mNode.mOffset;
  else
    v6 = 0i64;
  mPathIndex = lane->mPathIndex;
  v8 = *((_QWORD *)v6 + 4);
  if ( v8 )
    v5 = (UFG::RoadNetworkConnection *)&v6[v8 + 32];
  v9 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v5, mPathIndex)->mNode.mOffset + 1);
  if ( v9 <= 0.0 )
    v10 = 0.0;
  else
    v10 = distance / v9;
  if ( forward )
    v11 = v10 + beginT;
  else
    v11 = beginT - v10;
  if ( v11 <= 0.0 )
    return 0.0;
  result = *(float *)&FLOAT_1_0;
  if ( v11 < 1.0 )
    return v11;
  return result;
}

// File Line: 1917
// RVA: 0xD7E20
UFG::RoadNetworkSubSegment *__fastcall UFG::RoadNetworkSegment::GetClosestSubSegment(
        UFG::RoadNetworkSegment *this,
        UFG::qVector3 *position)
{
  float *v3; // r12
  float v4; // xmm6_4
  float v5; // xmm2_4
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *mNext; // rax
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *i; // r13
  float x; // xmm3_4
  float y; // xmm4_4
  unsigned __int64 v10; // rax
  char *v11; // r14
  unsigned int v12; // ecx
  unsigned int v13; // esi
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v14; // rbp
  float v15; // xmm0_4
  unsigned int v16; // edx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  unsigned __int64 v19; // rax
  char *v20; // rax
  char *v21; // r15
  _QWORD *v22; // rdx
  __int64 v23; // r8
  float z; // xmm2_4
  char *v25; // rax
  __int64 v26; // rdx

  v3 = 0i64;
  v4 = FLOAT_3_4028235e38;
  v5 = FLOAT_3_4028235e38;
  mNext = this->mSubSegmentCollection.mNode.mNext;
  for ( i = &this->mSubSegmentCollection;
        mNext != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)i;
        mNext = mNext->mNext )
  {
    x = position->x;
    y = position->y;
    if ( (float)((float)((float)(x - *(float *)&mNext[1].mNext) * (float)(x - *(float *)&mNext[1].mNext))
               + (float)((float)(y - *((float *)&mNext[1].mNext + 1)) * (float)(y - *((float *)&mNext[1].mNext + 1)))) < v5 )
    {
      v3 = (float *)mNext;
      v5 = (float)((float)(x - *(float *)&mNext[1].mNext) * (float)(x - *(float *)&mNext[1].mNext))
         + (float)((float)(y - *((float *)&mNext[1].mNext + 1)) * (float)(y - *((float *)&mNext[1].mNext + 1)));
    }
  }
  v10 = 16i64;
  if ( !is_mul_ok(2ui64, 8ui64) )
    v10 = -1i64;
  v11 = UFG::qMalloc(v10, "qArray.Add", 0i64);
  v12 = 2;
  v13 = 1;
  *(_QWORD *)v11 = v3;
  v14 = this->mSubSegmentCollection.mNode.mNext;
  if ( v14 == (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)i )
    goto LABEL_37;
  do
  {
    if ( v14 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v3 )
    {
      v15 = *((float *)&v14[1].mNext + 1) - v3[7];
      if ( (float)((float)((float)((float)(*(float *)&v14[1].mNext - v3[6]) * (float)(*(float *)&v14[1].mNext - v3[6]))
                         + (float)(v15 * v15))
                 + 4.0) < (float)(v3[9] * v3[9]) )
      {
        v16 = v13;
        v17 = v13 + 1;
        if ( v13 + 1 > v12 )
        {
          v18 = 1;
          if ( v12 )
            v18 = 2 * v12;
          for ( ; v18 < v17; v18 *= 2 )
            ;
          if ( v18 <= 2 )
            v18 = 2;
          if ( v18 - v17 > 0x10000 )
            v18 = v13 + 65537;
          if ( v18 != v13 )
          {
            v19 = 8i64 * v18;
            if ( !is_mul_ok(v18, 8ui64) )
              v19 = -1i64;
            v20 = UFG::qMalloc(v19, "qArray.Add", 0i64);
            v21 = v20;
            if ( v11 )
            {
              if ( v13 )
              {
                v22 = v20;
                v23 = v13;
                do
                {
                  *v22 = *(_QWORD *)((char *)v22 + v11 - v20);
                  ++v22;
                  --v23;
                }
                while ( v23 );
              }
              operator delete[](v11);
            }
            v11 = v21;
            v12 = v18;
            v16 = v13;
          }
        }
        ++v13;
        *(_QWORD *)&v11[8 * v16] = v14;
      }
    }
    v14 = v14->mNext;
  }
  while ( v14 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)i );
  if ( v13 == 1 )
  {
LABEL_37:
    v3 = *(float **)v11;
  }
  else if ( v13 )
  {
    v25 = v11;
    v26 = v13;
    do
    {
      z = position->z;
      if ( (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(z - *(float *)(*(_QWORD *)v25 + 32i64)) & _xmm) + 4.0) < v4 )
      {
        v3 = *(float **)v25;
        LODWORD(v4) = COERCE_UNSIGNED_INT(z - *(float *)(*(_QWORD *)v25 + 32i64)) & _xmm;
      }
      v25 += 8;
      --v26;
    }
    while ( v26 );
  }
  if ( v11 )
    operator delete[](v11);
  return (UFG::RoadNetworkSubSegment *)v3;
}

// File Line: 1981
// RVA: 0xD80C0
UFG::RoadNetworkSubSegment *__fastcall UFG::RoadNetworkSegment::GetClosestSubSegment(
        UFG::RoadNetworkSegment *this,
        UFG::RoadNetworkGate *gate)
{
  UFG::RoadNetworkSubSegment *result; // rax
  UFG::RoadNetworkSubSegment *mPrev; // r8
  float v4; // xmm7_4
  float v5; // xmm6_4

  result = (UFG::RoadNetworkSubSegment *)this->mSubSegmentCollection.mNode.mNext;
  mPrev = (UFG::RoadNetworkSubSegment *)this->mSubSegmentCollection.mNode.mPrev;
  if ( result != mPrev )
  {
    v4 = result->mPosition.y - gate->mPosition.y;
    v5 = mPrev->mPosition.y - gate->mPosition.y;
    if ( (float)((float)((float)(v5 * v5)
                       + (float)((float)(mPrev->mPosition.x - gate->mPosition.x)
                               * (float)(mPrev->mPosition.x - gate->mPosition.x)))
               + (float)((float)(mPrev->mPosition.z - gate->mPosition.z)
                       * (float)(mPrev->mPosition.z - gate->mPosition.z))) > (float)((float)((float)(v4 * v4)
                                                                                           + (float)((float)(result->mPosition.x - gate->mPosition.x) * (float)(result->mPosition.x - gate->mPosition.x)))
                                                                                   + (float)((float)(result->mPosition.z - gate->mPosition.z)
                                                                                           * (float)(result->mPosition.z - gate->mPosition.z))) )
      return (UFG::RoadNetworkSubSegment *)this->mSubSegmentCollection.mNode.mNext;
    return mPrev;
  }
  return result;
}

// File Line: 2011
// RVA: 0xCFA30
void __fastcall UFG::RoadNetworkSubSegment::RoadNetworkSubSegment(
        UFG::RoadNetworkSubSegment *this,
        UFG::RoadNetworkSegment *segment,
        float length,
        float beginT)
{
  __int64 v6; // r12
  __int64 mOffset; // rax
  _QWORD *v8; // rax
  float *v9; // r14
  char *v10; // rax
  __int64 v11; // rcx
  UFG::RoadNetworkConnection *v12; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v15; // rax
  __int64 v16; // rax
  _QWORD *v17; // rax
  float *v18; // r14
  char *v19; // rax
  __int64 v20; // rcx
  UFG::RoadNetworkConnection *v21; // rcx
  UFG::qBezierPathMemImaged *v22; // rbx
  float v23; // xmm8_4
  unsigned int v24; // eax
  UFG::qBezierSplineMemImaged *v25; // rax
  __int64 mNumLanes; // r13
  unsigned int v27; // r15d
  qPagedLinearAllocator *LaneTAllocator; // rax
  qPagedLinearAllocator *v29; // rbx
  __int64 v30; // r14
  float *mpCurrentPos; // rcx
  qPagedLinearAllocator *v32; // rax
  qPagedLinearAllocator *v33; // rbx
  float *v34; // rcx
  __int64 v35; // rax
  _QWORD *v36; // rax
  __int64 v37; // r15
  float *v38; // r14
  char *v39; // rax
  __int64 v40; // rcx
  UFG::RoadNetworkConnection *v41; // rcx
  UFG::qBezierPathMemImaged *v42; // rbx
  unsigned int v43; // eax
  UFG::qBezierSplineMemImaged *v44; // rax
  __int64 v45; // rax
  _QWORD *v46; // rax
  float *v47; // r14
  char *v48; // rax
  __int64 v49; // rcx
  UFG::RoadNetworkConnection *v50; // rcx
  UFG::qBezierPathMemImaged *v51; // rbx
  unsigned int v52; // eax
  UFG::qBezierSplineMemImaged *v53; // rax
  float v54; // xmm10_4
  float v55; // xmm11_4
  float v56; // xmm12_4
  float v57; // xmm13_4
  __int64 v58; // rax
  _QWORD *v59; // rax
  _QWORD *v60; // rax
  __int64 v61; // rcx
  char *v62; // rdx
  char *v63; // rcx
  __int64 v64; // rax
  char *v65; // rax
  char *v66; // rcx
  __int64 v67; // rax
  char *v68; // rax
  __int64 v69; // rsi
  __int64 i; // r14
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkLane *> *> *p_mLane; // rax
  char *v72; // rcx
  char *v73; // rax
  __int64 v74; // rcx
  char *v75; // rbx
  char *v76; // rax
  __int64 v77; // rcx
  UFG::RoadNetworkConnection *v78; // rcx
  UFG::qBezierPathMemImaged *v79; // rax
  char *v80; // rax
  __int64 v81; // rcx
  UFG::RoadNetworkConnection *v82; // rcx
  UFG::qBezierPathMemImaged *v83; // rax
  __int64 v84; // rax
  char *v85; // rdx
  char *v86; // rax
  __int64 v87; // rcx
  char *v88; // rcx
  char *v89; // rax
  __int64 v90; // rcx
  char *v91; // rcx
  float v92; // xmm0_4
  float v93; // xmm1_4
  __int64 v94; // rax
  char *v95; // rdx
  char *v96; // rax
  __int64 v97; // rcx
  char *v98; // rax
  char *v99; // rcx
  __int64 v100; // rax
  char *v101; // rax
  float x; // xmm8_4
  float y; // xmm9_4
  float z; // xmm10_4
  float v105; // xmm11_4
  float v106; // xmm14_4
  float v107; // xmm15_4
  float v108; // xmm12_4
  __int64 v109; // r14
  __int64 v110; // r12
  float v111; // xmm6_4
  UFG::RoadNetworkSegment *mParentNode; // rax
  __int64 v113; // rcx
  char *v114; // rax
  char *v115; // rcx
  __int64 v116; // rax
  char *v117; // rsi
  char *v118; // rax
  __int64 v119; // rcx
  UFG::RoadNetworkConnection *v120; // rcx
  UFG::qBezierPathMemImaged *v121; // rbx
  unsigned int v122; // eax
  UFG::qBezierSplineMemImaged *v123; // rax
  float v124; // xmm6_4
  UFG::RoadNetworkSegment *v125; // rax
  __int64 v126; // rcx
  char *v127; // rax
  char *v128; // rcx
  __int64 v129; // rax
  char *v130; // rsi
  char *v131; // rax
  __int64 v132; // rcx
  UFG::RoadNetworkConnection *v133; // rcx
  UFG::qBezierPathMemImaged *v134; // rbx
  unsigned int v135; // eax
  UFG::qBezierSplineMemImaged *v136; // rax
  float v137; // xmm7_4
  float v138; // xmm2_4
  float v139; // xmm0_4
  UFG::qVector3 v140; // [rsp+28h] [rbp-98h] BYREF
  UFG::qVector3 v141; // [rsp+38h] [rbp-88h] BYREF
  UFG::qVector3 pos; // [rsp+48h] [rbp-78h] BYREF
  UFG::qVector3 v143; // [rsp+58h] [rbp-68h] BYREF
  UFG::qVector3 result; // [rsp+68h] [rbp-58h] BYREF
  UFG::qVector3 v145; // [rsp+78h] [rbp-48h] BYREF
  UFG::qList<UFG::ParkingSpot,UFG::ParkingSpot,1,0> *p_mParkingSpotCollection; // [rsp+148h] [rbp+88h]
  float t; // [rsp+150h] [rbp+90h] BYREF
  float v148; // [rsp+158h] [rbp+98h] BYREF
  float pathT; // [rsp+160h] [rbp+A0h] BYREF
  float splineT; // [rsp+168h] [rbp+A8h] BYREF

  this->mPrev = this;
  this->mNext = this;
  this->mParentNode = segment;
  this->mLength = length;
  this->mActive = 0;
  this->mIndex = LOWORD(splineT);
  v6 = 1i64;
  this->mStatus.mValue = 4;
  this->mNumSpawnPoints = 0;
  this->mNumParkingSpots = 0;
  p_mParkingSpotCollection = &this->mParkingSpotCollection;
  this->mParkingSpotCollection.mNode.mPrev = &this->mParkingSpotCollection.mNode;
  this->mParkingSpotCollection.mNode.mNext = &this->mParkingSpotCollection.mNode;
  this->mParkingSpotCollection.mNode.mPrev = &this->mParkingSpotCollection.mNode;
  this->mParkingSpotCollection.mNode.mNext = &this->mParkingSpotCollection.mNode;
  mOffset = segment->mLane.mOffset;
  if ( mOffset )
    v8 = (__int64 *)((char *)&segment->mLane.mOffset + mOffset);
  else
    v8 = 0i64;
  v9 = (float *)((char *)v8 + *v8);
  if ( !*v8 )
    v9 = 0i64;
  if ( *(_QWORD *)v9 )
    v10 = (char *)v9 + *(_QWORD *)v9;
  else
    v10 = 0i64;
  v11 = *((_QWORD *)v10 + 4);
  if ( v11 )
    v12 = (UFG::RoadNetworkConnection *)&v10[v11 + 32];
  else
    v12 = 0i64;
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v12, *((unsigned __int16 *)v9 + 19));
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, beginT, &splineT);
  v15 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v15, splineT, v9[10]);
  v16 = segment->mLane.mOffset;
  if ( v16 )
    v17 = (__int64 *)((char *)&segment->mLane.mOffset + v16);
  else
    v17 = 0i64;
  v18 = (float *)((char *)v17 + *v17);
  if ( !*v17 )
    v18 = 0i64;
  if ( *(_QWORD *)v18 )
    v19 = (char *)v18 + *(_QWORD *)v18;
  else
    v19 = 0i64;
  v20 = *((_QWORD *)v19 + 4);
  if ( v20 )
    v21 = (UFG::RoadNetworkConnection *)&v19[v20 + 32];
  else
    v21 = 0i64;
  v22 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v21, *((unsigned __int16 *)v18 + 19));
  v23 = pathT;
  v24 = UFG::qBezierPathMemImaged::GetSplineParameters(v22, pathT, &splineT);
  v25 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)v22,
                                         v24);
  UFG::RoadNetworkLane::GetOffsetPos(&v145, v25, splineT, v18[10]);
  mNumLanes = (unsigned __int8)segment->mNumLanes;
  LODWORD(p_mParkingSpotCollection) = mNumLanes;
  v27 = 4 * mNumLanes;
  LaneTAllocator = GetLaneTAllocator();
  v29 = LaneTAllocator;
  if ( !LaneTAllocator->mpCurrentPage )
    qPagedLinearAllocator::NewPage(LaneTAllocator);
  if ( v27 > v29->mRemainingBytesOnPage )
    qPagedLinearAllocator::NewPage(v29);
  v30 = (v27 + 3) & 0xFFFFFFFC;
  mpCurrentPos = (float *)v29->mpCurrentPos;
  v29->mpCurrentPos = (char *)mpCurrentPos + v30;
  v29->mRemainingBytesOnPage -= v30;
  this->mBeginTCollection = mpCurrentPos;
  v32 = GetLaneTAllocator();
  v33 = v32;
  if ( !v32->mpCurrentPage )
    qPagedLinearAllocator::NewPage(v32);
  if ( v27 > v33->mRemainingBytesOnPage )
    qPagedLinearAllocator::NewPage(v33);
  v34 = (float *)v33->mpCurrentPos;
  v33->mpCurrentPos = (char *)v34 + v30;
  v33->mRemainingBytesOnPage -= v30;
  this->mEndTCollection = v34;
  *this->mBeginTCollection = beginT;
  *this->mEndTCollection = v23;
  v35 = segment->mLane.mOffset;
  if ( v35 )
  {
    v36 = (__int64 *)((char *)&segment->mLane.mOffset + v35);
    v37 = 0i64;
  }
  else
  {
    v37 = 0i64;
    v36 = 0i64;
  }
  v38 = (float *)((char *)v36 + *v36);
  if ( !*v36 )
    v38 = 0i64;
  if ( *(_QWORD *)v38 )
    v39 = (char *)v38 + *(_QWORD *)v38;
  else
    v39 = 0i64;
  v40 = *((_QWORD *)v39 + 4);
  if ( v40 )
    v41 = (UFG::RoadNetworkConnection *)&v39[v40 + 32];
  else
    v41 = 0i64;
  v42 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v41, *((unsigned __int16 *)v38 + 19));
  v43 = UFG::qBezierPathMemImaged::GetSplineParameters(v42, beginT, &splineT);
  v44 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)v42,
                                         v43);
  UFG::RoadNetworkLane::GetOffsetPos(&pos, v44, splineT, v38[10]);
  v45 = segment->mLane.mOffset;
  if ( v45 )
    v46 = (__int64 *)((char *)&segment->mLane.mOffset + v45);
  else
    v46 = 0i64;
  v47 = (float *)((char *)v46 + *v46);
  if ( !*v46 )
    v47 = 0i64;
  if ( *(_QWORD *)v47 )
    v48 = (char *)v47 + *(_QWORD *)v47;
  else
    v48 = 0i64;
  v49 = *((_QWORD *)v48 + 4);
  if ( v49 )
    v50 = (UFG::RoadNetworkConnection *)&v48[v49 + 32];
  else
    v50 = 0i64;
  v51 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v50, *((unsigned __int16 *)v47 + 19));
  v52 = UFG::qBezierPathMemImaged::GetSplineParameters(v51, v23, &splineT);
  v53 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)v51,
                                         v52);
  UFG::RoadNetworkLane::GetOffsetPos(&v143, v53, splineT, v47[10]);
  v54 = *(float *)&FLOAT_1_0;
  v55 = 0.0;
  v56 = 0.0;
  v57 = *(float *)&FLOAT_1_0;
  v58 = segment->mLane.mOffset;
  if ( v58 )
    v59 = (__int64 *)((char *)&segment->mLane.mOffset + v58);
  else
    v59 = 0i64;
  if ( *v59 )
    v60 = (_QWORD *)((char *)v59 + *v59);
  else
    v60 = 0i64;
  v61 = v60[1];
  if ( v61 )
    v62 = (char *)v60 + v61 + 8;
  else
    v62 = 0i64;
  if ( *v60 )
    v63 = (char *)v60 + *v60;
  else
    v63 = 0i64;
  v64 = *((_QWORD *)v63 + 6);
  if ( v64 )
    v65 = &v63[v64 + 48];
  else
    v65 = 0i64;
  if ( *(_QWORD *)v65 )
    v66 = &v65[*(_QWORD *)v65];
  else
    v66 = 0i64;
  v67 = *((_QWORD *)v66 + 1);
  if ( v67 )
    v68 = &v66[v67 + 8];
  else
    v68 = 0i64;
  if ( v62 == v68 )
  {
    if ( beginT < 1.0 )
      v54 = beginT;
    if ( v23 > 0.0 )
      v55 = v23;
  }
  else
  {
    if ( beginT > 0.0 )
      v56 = beginT;
    if ( v23 < 1.0 )
      v57 = v23;
  }
  if ( (unsigned int)mNumLanes > 1 )
  {
    v69 = 8i64;
    for ( i = (unsigned int)(mNumLanes - 1); i; --i )
    {
      splineT = 3.4028235e38;
      pathT = 3.4028235e38;
      p_mLane = &this->mParentNode->mLane;
      if ( p_mLane->mOffset )
        v72 = (char *)p_mLane + p_mLane->mOffset;
      else
        v72 = 0i64;
      v73 = &v72[v69];
      v74 = *(_QWORD *)&v72[v69];
      v75 = &v73[v74];
      if ( !v74 )
        v75 = 0i64;
      if ( *(_QWORD *)v75 )
        v76 = &v75[*(_QWORD *)v75];
      else
        v76 = 0i64;
      v77 = *((_QWORD *)v76 + 4);
      if ( v77 )
        v78 = (UFG::RoadNetworkConnection *)&v76[v77 + 32];
      else
        v78 = 0i64;
      v79 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v78,
                                           *((unsigned __int16 *)v75 + 19));
      UFG::qBezierPathMemImaged::ClosestPoint3D(v79, &v141, &pos, &splineT);
      if ( *(_QWORD *)v75 )
        v80 = &v75[*(_QWORD *)v75];
      else
        v80 = 0i64;
      v81 = *((_QWORD *)v80 + 4);
      if ( v81 )
        v82 = (UFG::RoadNetworkConnection *)&v80[v81 + 32];
      else
        v82 = 0i64;
      v83 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v82,
                                           *((unsigned __int16 *)v75 + 19));
      UFG::qBezierPathMemImaged::ClosestPoint3D(v83, &v140, &v143, &pathT);
      v84 = *((_QWORD *)v75 + 1);
      if ( v84 )
        v85 = &v75[v84 + 8];
      else
        v85 = 0i64;
      if ( *(_QWORD *)v75 )
        v86 = &v75[*(_QWORD *)v75];
      else
        v86 = 0i64;
      v87 = *((_QWORD *)v86 + 6);
      if ( v87 )
        v88 = &v86[v87 + 48];
      else
        v88 = 0i64;
      if ( *(_QWORD *)v88 )
        v89 = &v88[*(_QWORD *)v88];
      else
        v89 = 0i64;
      v90 = *((_QWORD *)v89 + 1);
      if ( v90 )
        v91 = &v89[v90 + 8];
      else
        v91 = 0i64;
      if ( v85 == v91 )
      {
        if ( beginT == 0.0 )
        {
          v92 = 0.0;
          splineT = 0.0;
        }
        else
        {
          v92 = splineT;
        }
        if ( v23 != 1.0 )
          goto LABEL_128;
        v93 = *(float *)&FLOAT_1_0;
        pathT = *(float *)&FLOAT_1_0;
      }
      else
      {
        if ( beginT == 0.0 )
        {
          v92 = *(float *)&FLOAT_1_0;
          splineT = *(float *)&FLOAT_1_0;
        }
        else
        {
          v92 = splineT;
        }
        if ( v23 != 1.0 )
        {
LABEL_128:
          v93 = pathT;
          goto LABEL_129;
        }
        v93 = 0.0;
        pathT = 0.0;
      }
LABEL_129:
      v94 = *((_QWORD *)v75 + 1);
      if ( v94 )
        v95 = &v75[v94 + 8];
      else
        v95 = 0i64;
      if ( *(_QWORD *)v75 )
        v96 = &v75[*(_QWORD *)v75];
      else
        v96 = 0i64;
      v97 = *((_QWORD *)v96 + 6);
      if ( v97 )
        v98 = &v96[v97 + 48];
      else
        v98 = 0i64;
      if ( *(_QWORD *)v98 )
        v99 = &v98[*(_QWORD *)v98];
      else
        v99 = 0i64;
      v100 = *((_QWORD *)v99 + 1);
      if ( v100 )
        v101 = &v99[v100 + 8];
      else
        v101 = 0i64;
      if ( v95 == v101 )
      {
        if ( v92 < v54 )
          v54 = v92;
        if ( v93 > v55 )
          v55 = v93;
      }
      else
      {
        if ( v92 > v56 )
          v56 = v92;
        if ( v93 < v57 )
          v57 = v93;
      }
      this->mBeginTCollection[v6] = v92;
      this->mEndTCollection[v6] = pathT;
      v69 += 8i64;
      ++v6;
    }
  }
  x = UFG::qVector3::msZero.x;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v105 = UFG::qVector3::msZero.x;
  v106 = UFG::qVector3::msZero.y;
  v107 = UFG::qVector3::msZero.z;
  v108 = UFG::qVector3::msZero.x;
  pathT = UFG::qVector3::msZero.y;
  splineT = UFG::qVector3::msZero.z;
  if ( (_DWORD)mNumLanes )
  {
    v109 = 0i64;
    v110 = mNumLanes;
    do
    {
      v111 = this->mBeginTCollection[v37];
      mParentNode = this->mParentNode;
      v113 = mParentNode->mLane.mOffset;
      if ( v113 )
        v114 = (char *)&mParentNode->mLane + v113;
      else
        v114 = 0i64;
      v115 = &v114[v109];
      v116 = *(_QWORD *)&v114[v109];
      v117 = &v115[v116];
      if ( !v116 )
        v117 = 0i64;
      if ( *(_QWORD *)v117 )
        v118 = &v117[*(_QWORD *)v117];
      else
        v118 = 0i64;
      v119 = *((_QWORD *)v118 + 4);
      if ( v119 )
        v120 = (UFG::RoadNetworkConnection *)&v118[v119 + 32];
      else
        v120 = 0i64;
      v121 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                            v120,
                                            *((unsigned __int16 *)v117 + 19));
      v122 = UFG::qBezierPathMemImaged::GetSplineParameters(v121, v111, &t);
      v123 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                              (UFG::RoadNetworkConnection *)v121,
                                              v122);
      UFG::RoadNetworkLane::GetOffsetPos(&v140, v123, t, *((float *)v117 + 10));
      v124 = this->mEndTCollection[v37];
      v125 = this->mParentNode;
      v126 = v125->mLane.mOffset;
      if ( v126 )
        v127 = (char *)&v125->mLane + v126;
      else
        v127 = 0i64;
      v128 = &v127[v109];
      v129 = *(_QWORD *)&v127[v109];
      v130 = &v128[v129];
      if ( !v129 )
        v130 = 0i64;
      if ( *(_QWORD *)v130 )
        v131 = &v130[*(_QWORD *)v130];
      else
        v131 = 0i64;
      v132 = *((_QWORD *)v131 + 4);
      if ( v132 )
        v133 = (UFG::RoadNetworkConnection *)&v131[v132 + 32];
      else
        v133 = 0i64;
      v134 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                            v133,
                                            *((unsigned __int16 *)v130 + 19));
      v135 = UFG::qBezierPathMemImaged::GetSplineParameters(v134, v124, &v148);
      v136 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                              (UFG::RoadNetworkConnection *)v134,
                                              v135);
      UFG::RoadNetworkLane::GetOffsetPos(&v141, v136, v148, *((float *)v130 + 10));
      z = v140.z + z;
      y = v140.y + y;
      x = x + v140.x;
      v107 = v141.z + v107;
      v106 = v141.y + v106;
      v105 = v105 + v141.x;
      splineT = (float)((float)(v141.z + v140.z) * 0.5) + splineT;
      pathT = (float)((float)(v141.y + v140.y) * 0.5) + pathT;
      v108 = v108 + (float)((float)(v141.x + v140.x) * 0.5);
      ++v37;
      v109 += 8i64;
      --v110;
    }
    while ( v110 );
    LODWORD(mNumLanes) = (_DWORD)p_mParkingSpotCollection;
  }
  v137 = 1.0 / (float)(int)mNumLanes;
  this->mBeginPos.x = v137 * x;
  this->mBeginPos.y = v137 * y;
  this->mBeginPos.z = v137 * z;
  this->mEndPos.x = v137 * v105;
  this->mEndPos.y = v137 * v106;
  this->mEndPos.z = v137 * v107;
  v138 = v137 * splineT;
  v139 = v137 * pathT;
  this->mPosition.x = v137 * v108;
  this->mPosition.y = v139;
  this->mPosition.z = v138;
}

// File Line: 2113
// RVA: 0xD1000
void __fastcall UFG::RoadNetworkSubSegment::~RoadNetworkSubSegment(UFG::RoadNetworkSubSegment *this)
{
  UFG::qList<UFG::ParkingSpot,UFG::ParkingSpot,1,0> *p_mParkingSpotCollection; // rbx
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v3; // rax
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *i; // r8
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v5; // rdx
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *mPrev; // rcx
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *mNext; // rax
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v8; // rcx
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v9; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v10; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v11; // rax

  p_mParkingSpotCollection = &this->mParkingSpotCollection;
  v3 = this->mParkingSpotCollection.mNode.mNext - 12;
  for ( i = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&this[-1].mPosition.z;
        v3 != i;
        v3 = p_mParkingSpotCollection->mNode.mNext - 12 )
  {
    v5 = v3 + 12;
    mPrev = v3[12].mPrev;
    mNext = v3[12].mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v5->mPrev = v5;
    v5->mNext = v5;
  }
  UFG::qList<UFG::ParkingSpot,UFG::ParkingSpot,1,0>::DeleteNodes(p_mParkingSpotCollection);
  v8 = p_mParkingSpotCollection->mNode.mPrev;
  v9 = p_mParkingSpotCollection->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mParkingSpotCollection->mNode.mPrev = &p_mParkingSpotCollection->mNode;
  p_mParkingSpotCollection->mNode.mNext = &p_mParkingSpotCollection->mNode;
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 2148
// RVA: 0xDF000
bool __fastcall UFG::RoadNetworkSubSegment::IsWithinSubSegment(
        UFG::RoadNetworkSubSegment *this,
        UFG::RoadNetworkLane *roadLane,
        float laneT)
{
  __int64 mLaneIndex; // r8
  float v4; // xmm7_4
  float v5; // xmm8_4

  mLaneIndex = roadLane->mLaneIndex;
  v4 = this->mBeginTCollection[mLaneIndex];
  v5 = this->mEndTCollection[mLaneIndex];
  if ( UFG::RoadNetworkLane::IsReversedInNode(roadLane) )
  {
    if ( laneT < v5 )
      return 0;
    return laneT <= v4;
  }
  else
  {
    if ( laneT < v4 )
      return 0;
    return laneT <= v5;
  }
}

// File Line: 2242
// RVA: 0xD5E20
float __fastcall UFG::RoadNetworkSubSegment::GetBeginT(UFG::RoadNetworkSubSegment *this, unsigned int laneIndex)
{
  return this->mBeginTCollection[laneIndex];
}

// File Line: 2248
// RVA: 0xD87B0
float __fastcall UFG::RoadNetworkSubSegment::GetEndT(UFG::RoadNetworkSubSegment *this, unsigned int laneIndex)
{
  return this->mEndTCollection[laneIndex];
}

// File Line: 2303
// RVA: 0xD8DB0
void __fastcall UFG::RoadNetworkSubSegment::GetGatesConnectedToSubSegment(
        UFG::RoadNetworkSubSegment *this,
        UFG::qArray<UFG::qReflectInventoryBase *,0> *gateCollection)
{
  UFG::RoadNetworkGate **p; // rcx
  char *v5; // rax
  UFG::RoadNetworkSegment *mParentNode; // rdi
  __int64 mOffset; // rcx
  _QWORD *v8; // rdx
  UFG::RoadNetworkGate *v9; // r8
  char *v10; // rdx
  __int64 v11; // rcx
  UFG::RoadNetworkGate *v12; // r14
  __int64 v13; // rcx
  _QWORD *v14; // rcx
  char *v15; // r9
  __int64 v16; // rcx
  UFG::RoadNetworkGate *v17; // rbp
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *p_mNode; // rdi
  unsigned int v19; // ebx
  UFG::RoadNetworkGate **v20; // rax
  __int64 size; // rbp
  unsigned int capacity; // eax
  unsigned int v23; // edi
  UFG::RoadNetworkGate **v24; // rax

  p = (UFG::RoadNetworkGate **)gateCollection->p;
  if ( p )
    operator delete[](p);
  v5 = 0i64;
  gateCollection->p = 0i64;
  *(_QWORD *)&gateCollection->size = 0i64;
  mParentNode = this->mParentNode;
  mOffset = mParentNode->mGates.mOffset;
  if ( mOffset )
    v8 = (__int64 *)((char *)&mParentNode->mGates.mOffset + mOffset);
  else
    v8 = 0i64;
  if ( *v8 )
    v9 = (UFG::RoadNetworkGate *)((char *)v8 + *v8);
  else
    v9 = 0i64;
  if ( mOffset )
    v10 = (char *)&mParentNode->mGates + mOffset;
  else
    v10 = 0i64;
  v11 = *((_QWORD *)v10 + 1);
  if ( v11 )
    v12 = (UFG::RoadNetworkGate *)&v10[v11 + 8];
  else
    v12 = 0i64;
  v13 = mParentNode->mLane.mOffset;
  if ( v13 )
    v14 = (__int64 *)((char *)&mParentNode->mLane.mOffset + v13);
  else
    v14 = 0i64;
  v15 = (char *)v14 + *v14;
  if ( !*v14 )
    v15 = 0i64;
  v16 = *((_QWORD *)v15 + 1);
  if ( v16 )
    v5 = &v15[v16 + 8];
  if ( v5 == (char *)v9 )
  {
    v17 = v9;
  }
  else
  {
    v17 = v12;
    v12 = v9;
  }
  p_mNode = &mParentNode->mSubSegmentCollection.mNode;
  v19 = 1;
  if ( this->mPrev == p_mNode )
  {
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(gateCollection, 2u, "qArray.Add");
    v20 = (UFG::RoadNetworkGate **)gateCollection->p;
    gateCollection->size = 1;
    *v20 = v17;
  }
  if ( this->mNext == p_mNode )
  {
    size = gateCollection->size;
    capacity = gateCollection->capacity;
    v23 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v19 = 2 * capacity;
      for ( ; v19 < v23; v19 *= 2 )
        ;
      if ( v19 <= 2 )
        v19 = 2;
      if ( v19 - v23 > 0x10000 )
        v19 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(gateCollection, v19, "qArray.Add");
    }
    v24 = (UFG::RoadNetworkGate **)gateCollection->p;
    gateCollection->size = v23;
    v24[size] = v12;
  }
}

// File Line: 2365
// RVA: 0xCF8F0
void __fastcall UFG::RoadNetworkNodeModification::RoadNetworkNodeModification(
        UFG::RoadNetworkNodeModification *this,
        UFG::RoadNetworkNode *node)
{
  unsigned int size; // ecx
  int v5; // eax
  unsigned int mNumLanes; // ebx
  unsigned int capacity; // edx
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int i; // edx
  __int64 mOffset; // rax
  char *v12; // rcx
  char *v13; // rax
  char *v14; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mLaneFlagsCollection.p = 0i64;
  *(_QWORD *)&this->mLaneFlagsCollection.size = 0i64;
  this->mNode = node;
  size = this->mLaneFlagsCollection.size;
  v5 = (unsigned __int8)node->mNumLanes - size;
  if ( v5 <= 0 )
  {
    v9 = size - (unsigned __int8)node->mNumLanes;
    if ( v9 )
    {
      if ( v9 < size )
        this->mLaneFlagsCollection.size = (unsigned __int8)node->mNumLanes;
      else
        this->mLaneFlagsCollection.size = 0;
    }
  }
  else
  {
    mNumLanes = (unsigned __int8)node->mNumLanes;
    capacity = this->mLaneFlagsCollection.capacity;
    if ( size + v5 > capacity )
    {
      if ( capacity )
        v8 = 2 * capacity;
      else
        v8 = 1;
      for ( ; v8 < mNumLanes; v8 *= 2 )
        ;
      if ( v8 <= 4 )
        v8 = 4;
      if ( v8 - mNumLanes > 0x10000 )
        v8 = mNumLanes + 0x10000;
      UFG::qArray<long,0>::Reallocate(&this->mLaneFlagsCollection, v8, "RoadNetworkNodeModification");
    }
    this->mLaneFlagsCollection.size = mNumLanes;
  }
  for ( i = 0; i < (unsigned __int8)node->mNumLanes; this->mLaneFlagsCollection.p[i++] = (unsigned __int8)v14[44] )
  {
    mOffset = node->mLane.mOffset;
    if ( mOffset )
      v12 = (char *)&node->mLane + mOffset;
    else
      v12 = 0i64;
    v13 = &v12[8 * i];
    if ( *(_QWORD *)v13 )
      v14 = &v13[*(_QWORD *)v13];
    else
      v14 = 0i64;
  }
}

// File Line: 2383
// RVA: 0xD0EC0
void __fastcall UFG::RoadNetworkNodeModification::~RoadNetworkNodeModification(UFG::RoadNetworkNodeModification *this)
{
  unsigned int *p; // rcx
  unsigned int *v3; // rcx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mPrev; // rcx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mNext; // rax

  p = this->mLaneFlagsCollection.p;
  if ( p )
    operator delete[](p);
  this->mLaneFlagsCollection.p = 0i64;
  *(_QWORD *)&this->mLaneFlagsCollection.size = 0i64;
  v3 = this->mLaneFlagsCollection.p;
  if ( v3 )
    operator delete[](v3);
  this->mLaneFlagsCollection.p = 0i64;
  *(_QWORD *)&this->mLaneFlagsCollection.size = 0i64;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 2421
// RVA: 0xD0D90
void __fastcall UFG::RoadNetworkIntersection::~RoadNetworkIntersection(UFG::RoadNetworkIntersection *this)
{
  __int64 v2; // rsi
  __int64 mNumTrafficLightLocations; // rbp
  __int64 mOffset; // rax
  char *v5; // rcx
  char *v6; // rax
  __int64 v7; // rcx
  char *v8; // rbx
  unsigned int v9; // edx
  unsigned int v10; // edx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mPrev; // rcx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mNext; // rax

  if ( this->mNumTrafficLightLocations )
  {
    v2 = 0i64;
    mNumTrafficLightLocations = (unsigned __int8)this->mNumTrafficLightLocations;
    do
    {
      if ( this->mNumTrafficLightLocations
        && ((mOffset = this->mTrafficLightLocations.mOffset) == 0
          ? (v5 = 0i64)
          : (v5 = (char *)&this->mTrafficLightLocations + mOffset),
            v6 = &v5[v2],
            (v7 = *(_QWORD *)&v5[v2]) != 0) )
      {
        v8 = &v6[v7];
      }
      else
      {
        v8 = 0i64;
      }
      v9 = *((_DWORD *)v8 + 7);
      if ( v9 != -1 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, v9, FXKILLOPTION_DEFAULT);
        *((_DWORD *)v8 + 7) = -1;
      }
      v10 = *((_DWORD *)v8 + 8);
      if ( v10 != -1 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, v10, FXKILLOPTION_DEFAULT);
        *((_DWORD *)v8 + 8) = -1;
      }
      v2 += 8i64;
      --mNumTrafficLightLocations;
    }
    while ( mNumTrafficLightLocations );
  }
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0>::DeleteNodes(&this->mModifications);
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0>::DeleteNodes(&this->mModifications);
  mPrev = this->mModifications.mNode.mPrev;
  mNext = this->mModifications.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mModifications.mNode.mPrev = &this->mModifications.mNode;
  this->mModifications.mNode.mNext = &this->mModifications.mNode;
}

// File Line: 2463
// RVA: 0xDC3F0
UFG::RoadNetworkTrafficLightPhase *__fastcall UFG::RoadNetworkIntersection::GetTrafficLightPhase(
        UFG::RoadNetworkIntersection *this,
        unsigned int index)
{
  __int64 v2; // r8
  __int64 mOffset; // rdx
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkTrafficLightPhase *> *> *p_mLightPhases; // rax
  __int64 v6; // rcx
  char *v7; // rdx
  __int64 v8; // rax
  char *v9; // r8

  v2 = index;
  if ( !this->mNumLightPhases )
    return 0i64;
  mOffset = this->mLightPhases.mOffset;
  p_mLightPhases = &this->mLightPhases;
  v6 = 0i64;
  if ( mOffset )
    v7 = (char *)p_mLightPhases + mOffset;
  else
    v7 = 0i64;
  v8 = *(_QWORD *)&v7[8 * v2];
  v9 = &v7[8 * v2];
  if ( v8 )
    return (UFG::RoadNetworkTrafficLightPhase *)&v9[v8];
  return (UFG::RoadNetworkTrafficLightPhase *)v6;
}

// File Line: 2478
// RVA: 0xDB620
float __fastcall UFG::RoadNetworkIntersection::GetRemainingGreenLightTime(UFG::RoadNetworkIntersection *this)
{
  char mNumLightPhases; // r8
  float *v2; // rdx
  __int64 mOffset; // rax
  char *v4; // r9
  char *v5; // r10
  char *v6; // rax
  __int64 v7; // rax
  char *v8; // r8
  char *v9; // r9

  mNumLightPhases = this->mNumLightPhases;
  v2 = 0i64;
  if ( mNumLightPhases
    && ((mOffset = this->mLightPhases.mOffset) == 0 ? (v4 = 0i64) : (v4 = (char *)&this->mLightPhases + mOffset),
        v5 = &v4[8 * this->mCurrentPhaseIndex],
        *(_QWORD *)v5) )
  {
    v6 = &v5[*(_QWORD *)v5];
  }
  else
  {
    v6 = 0i64;
  }
  if ( *((_DWORD *)v6 + 6) != 2 )
    return FLOAT_N1_0;
  if ( mNumLightPhases )
  {
    v7 = this->mLightPhases.mOffset;
    if ( v7 )
      v8 = (char *)&this->mLightPhases + v7;
    else
      v8 = 0i64;
    v9 = &v8[8 * this->mCurrentPhaseIndex];
    if ( *(_QWORD *)v9 )
      v2 = (float *)&v9[*(_QWORD *)v9];
  }
  return v2[1] - this->mTimer;
}

// File Line: 2575
// RVA: 0xDD970
void __fastcall UFG::RoadNetworkIntersection::InitializePhases(UFG::RoadNetworkIntersection *this)
{
  float v2; // xmm0_4
  char *v3; // rcx
  __int64 mOffset; // rax
  char *v5; // rcx
  __int64 v6; // rax

  UFG::OnlineManager::Instance();
  v2 = UFG::qRandom((float)(unsigned __int8)this->mNumLightPhases, &UFG::qDefaultSeed);
  v3 = 0i64;
  this->mTimer = 0.0;
  this->mCurrentPhaseIndex = (int)v2;
  if ( this->mNumLightPhases )
  {
    mOffset = this->mLightPhases.mOffset;
    if ( mOffset )
      v3 = (char *)&this->mLightPhases + mOffset;
    v5 = &v3[8 * (int)v2];
    v6 = *(_QWORD *)v5;
    if ( *(_QWORD *)v5 )
    {
      if ( &v5[v6] )
        UFG::RoadNetworkIntersection::EnableLanes(this, (UFG::RoadNetworkTrafficLightPhase *)&v5[v6], 0);
    }
  }
}

// File Line: 2602
// RVA: 0xE17E0
void __fastcall UFG::RoadNetworkIntersection::UpdateLights(
        UFG::RoadNetworkIntersection *this,
        float seconds,
        UFG::qVector3 *viewPosition,
        float visibleDistance)
{
  bool v4; // si
  char mNumLightPhases; // al
  __int64 mOffset; // rax
  char *v8; // rcx
  __int64 mCurrentPhaseIndex; // r8
  char *v10; // rdx
  UFG::RoadNetworkTrafficLightPhase *v11; // rdi
  char *v12; // rcx
  __int64 v13; // rax
  float v14; // xmm8_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  unsigned int v17; // ecx
  unsigned int v18; // eax
  UFG::RoadNetworkTrafficLightPhase *TrafficLightPhase; // rax

  v4 = 0;
  mNumLightPhases = this->mNumLightPhases;
  if ( (float)(visibleDistance * visibleDistance) > (float)((float)((float)((float)(viewPosition->x - this->mPosition.x)
                                                                          * (float)(viewPosition->x - this->mPosition.x))
                                                                  + (float)((float)(viewPosition->y - this->mPosition.y)
                                                                          * (float)(viewPosition->y - this->mPosition.y)))
                                                          + (float)((float)(viewPosition->z - this->mPosition.z)
                                                                  * (float)(viewPosition->z - this->mPosition.z))) )
    v4 = 1;
  if ( mNumLightPhases && (mNumLightPhases != 1 || this->mIsMerged) )
  {
    mOffset = this->mLightPhases.mOffset;
    if ( mOffset )
      v8 = (char *)&this->mLightPhases + mOffset;
    else
      v8 = 0i64;
    mCurrentPhaseIndex = this->mCurrentPhaseIndex;
    v10 = &v8[8 * mCurrentPhaseIndex];
    if ( *(_QWORD *)v10 )
      v11 = (UFG::RoadNetworkTrafficLightPhase *)&v10[*(_QWORD *)v10];
    else
      v11 = 0i64;
    if ( mOffset )
      v12 = (char *)&this->mLightPhases + mOffset;
    else
      v12 = 0i64;
    v13 = *(_QWORD *)&v12[8 * mCurrentPhaseIndex];
    if ( v13 )
      v13 += (__int64)&v12[8 * mCurrentPhaseIndex];
    v14 = *(float *)(v13 + 4);
    v15 = v14 + *(float *)(v13 + 8);
    if ( this->mEnableTimer )
    {
      UFG::OnlineManager::Instance();
      v16 = seconds + this->mTimer;
      this->mTimer = v16;
      if ( v16 <= v15 )
      {
        if ( v16 > v14 && v11->mCurrentStatus == GREEN )
          UFG::RoadNetworkTrafficLightPhase::SetLaneStatus(v11, YELLOW, v4);
      }
      else
      {
        v17 = (unsigned __int8)this->mNumLightPhases;
        v18 = this->mCurrentPhaseIndex + 1;
        this->mTimer = 0.0;
        this->mCurrentPhaseIndex = v18 % v17;
        TrafficLightPhase = UFG::RoadNetworkIntersection::GetTrafficLightPhase(this, v18 % v17);
        UFG::RoadNetworkIntersection::EnableLanes(this, TrafficLightPhase, v4);
      }
    }
  }
}

// File Line: 2669
// RVA: 0xD4590
void __fastcall UFG::RoadNetworkIntersection::EnableLanes(
        UFG::RoadNetworkIntersection *this,
        UFG::RoadNetworkTrafficLightPhase *phase,
        bool updateTrafficLightEffects)
{
  unsigned int mNumLightPhases; // eax
  unsigned int mIndex; // esi
  __int64 v5; // rbx
  __int64 mOffset; // rax
  char *v10; // rcx
  __int64 v11; // rax
  UFG::RoadNetworkTrafficLightPhase *v12; // rcx
  unsigned int mNumProtectedLanes; // eax
  __int64 v14; // rdx
  __int64 v15; // r8
  __int64 v16; // rax
  char *v17; // rcx
  char *v18; // rax
  __int64 v19; // rcx
  char *v20; // rax
  unsigned int mNumPermissiveLanes; // eax
  __int64 v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rax
  char *v25; // rcx
  char *v26; // rax
  __int64 v27; // rcx
  char *v28; // rax
  __int64 i; // rbx
  __int64 v30; // rax
  char *v31; // rcx
  UFG::RoadNetworkTrafficLightLocation **v32; // rax
  UFG::RoadNetworkTrafficLightLocation *v33; // rcx

  LOBYTE(mNumLightPhases) = this->mNumLightPhases;
  mIndex = phase->mIndex;
  v5 = 0i64;
  if ( (_BYTE)mNumLightPhases )
  {
    do
    {
      if ( (_DWORD)v5 != mIndex )
      {
        if ( (_BYTE)mNumLightPhases
          && ((mOffset = this->mLightPhases.mOffset) == 0 ? (v10 = 0i64) : (v10 = (char *)&this->mLightPhases + mOffset),
              (v11 = *(_QWORD *)&v10[8 * v5]) != 0) )
        {
          v12 = (UFG::RoadNetworkTrafficLightPhase *)&v10[8 * v5 + v11];
        }
        else
        {
          v12 = 0i64;
        }
        UFG::RoadNetworkTrafficLightPhase::SetLaneStatus(v12, RED, updateTrafficLightEffects);
      }
      mNumLightPhases = (unsigned __int8)this->mNumLightPhases;
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < mNumLightPhases );
  }
  mNumProtectedLanes = phase->mNumProtectedLanes;
  phase->mCurrentStatus = GREEN;
  if ( mNumProtectedLanes )
  {
    v14 = 0i64;
    v15 = mNumProtectedLanes;
    do
    {
      v16 = phase->mProtectedLanes.mOffset;
      if ( v16 )
        v17 = (char *)&phase->mProtectedLanes + v16;
      else
        v17 = 0i64;
      v18 = &v17[v14];
      v19 = *(_QWORD *)&v17[v14];
      if ( v19 )
        v20 = &v18[v19];
      else
        v20 = 0i64;
      v14 += 8i64;
      v20[55] = 2;
      --v15;
    }
    while ( v15 );
  }
  mNumPermissiveLanes = phase->mNumPermissiveLanes;
  if ( mNumPermissiveLanes )
  {
    v22 = 0i64;
    v23 = mNumPermissiveLanes;
    do
    {
      v24 = phase->mPermissiveLanes.mOffset;
      if ( v24 )
        v25 = (char *)&phase->mPermissiveLanes + v24;
      else
        v25 = 0i64;
      v26 = &v25[v22];
      v27 = *(_QWORD *)&v25[v22];
      if ( v27 )
        v28 = &v26[v27];
      else
        v28 = 0i64;
      v22 += 8i64;
      v28[55] = 2;
      --v23;
    }
    while ( v23 );
  }
  if ( updateTrafficLightEffects )
  {
    for ( i = 0i64; (unsigned int)i < phase->mNumTrafficLights; i = (unsigned int)(i + 1) )
    {
      v30 = phase->mTrafficLightCollection.mOffset;
      if ( v30 )
        v31 = (char *)&phase->mTrafficLightCollection + v30;
      else
        v31 = 0i64;
      v32 = *(UFG::RoadNetworkTrafficLightLocation ***)&v31[8 * i];
      if ( v32 )
        v32 = (UFG::RoadNetworkTrafficLightLocation **)&v31[8 * i + (_QWORD)v32];
      v33 = *v32;
      if ( *v32 )
        v33 = (UFG::RoadNetworkTrafficLightLocation *)((char *)v33 + (_QWORD)v32);
      UFG::RoadNetworkTrafficLightLocation::SetLampEffect(v33, green, Straight);
    }
  }
}

// File Line: 2688
// RVA: 0xD8F60
float __fastcall UFG::RoadNetworkIntersection::GetIntersectionRadius(UFG::RoadNetworkIntersection *this)
{
  int mNumGates; // ebx
  unsigned int v3; // edi
  __int64 v4; // rcx
  float v5; // xmm2_4
  __int64 mOffset; // rdx
  float x; // xmm3_4
  float y; // xmm4_4
  unsigned int v9; // eax
  __int64 v10; // r11
  char *v11; // rax
  char *v12; // r9
  float *v13; // r10
  char *v14; // rax
  char *v15; // r9
  __int64 v16; // rax
  char *v17; // r9
  char *v18; // r10
  char *v19; // rax
  char *v20; // r9
  __int64 v21; // rax
  char *v22; // r9
  char *v23; // r10
  char *v24; // rax
  char *v25; // r9
  __int64 v26; // rax
  char *v27; // r9
  char *v28; // r10
  __int64 v29; // r9
  float v30; // xmm3_4
  float v31; // xmm4_4
  __int64 v32; // rdx
  __int64 v33; // r10
  char *v34; // rax
  char *v35; // rcx
  __int64 v36; // rax

  mNumGates = (unsigned __int8)this->mNumGates;
  v3 = 0;
  v4 = 0i64;
  v5 = 0.0;
  if ( mNumGates >= 4 )
  {
    mOffset = this->mGates.mOffset;
    x = this->mPosition.x;
    y = this->mPosition.y;
    v9 = ((unsigned int)(mNumGates - 4) >> 2) + 1;
    v10 = v9;
    v3 = 4 * v9;
    do
    {
      if ( mOffset )
        v11 = (char *)&this->mGates + mOffset;
      else
        v11 = 0i64;
      v12 = &v11[8 * v4];
      if ( *(_QWORD *)v12 )
        v13 = (float *)&v12[*(_QWORD *)v12];
      else
        v13 = 0i64;
      if ( (float)((float)((float)(v13[7] - y) * (float)(v13[7] - y))
                 + (float)((float)(v13[6] - x) * (float)(v13[6] - x))) > v5 )
        v5 = (float)((float)(v13[7] - y) * (float)(v13[7] - y)) + (float)((float)(v13[6] - x) * (float)(v13[6] - x));
      if ( mOffset )
        v14 = (char *)&this->mGates + mOffset;
      else
        v14 = 0i64;
      v15 = v14 + 8;
      v16 = *(_QWORD *)&v14[8 * v4 + 8];
      v17 = &v15[8 * v4];
      if ( v16 )
        v18 = &v17[v16];
      else
        v18 = 0i64;
      if ( (float)((float)((float)(*((float *)v18 + 7) - y) * (float)(*((float *)v18 + 7) - y))
                 + (float)((float)(*((float *)v18 + 6) - x) * (float)(*((float *)v18 + 6) - x))) > v5 )
        v5 = (float)((float)(*((float *)v18 + 7) - y) * (float)(*((float *)v18 + 7) - y))
           + (float)((float)(*((float *)v18 + 6) - x) * (float)(*((float *)v18 + 6) - x));
      if ( mOffset )
        v19 = (char *)&this->mGates + mOffset;
      else
        v19 = 0i64;
      v20 = v19 + 16;
      v21 = *(_QWORD *)&v19[8 * v4 + 16];
      v22 = &v20[8 * v4];
      if ( v21 )
        v23 = &v22[v21];
      else
        v23 = 0i64;
      if ( (float)((float)((float)(*((float *)v23 + 7) - y) * (float)(*((float *)v23 + 7) - y))
                 + (float)((float)(*((float *)v23 + 6) - x) * (float)(*((float *)v23 + 6) - x))) > v5 )
        v5 = (float)((float)(*((float *)v23 + 7) - y) * (float)(*((float *)v23 + 7) - y))
           + (float)((float)(*((float *)v23 + 6) - x) * (float)(*((float *)v23 + 6) - x));
      if ( mOffset )
        v24 = (char *)&this->mGates + mOffset;
      else
        v24 = 0i64;
      v25 = v24 + 24;
      v26 = *(_QWORD *)&v24[8 * v4 + 24];
      v27 = &v25[8 * v4];
      if ( v26 )
        v28 = &v27[v26];
      else
        v28 = 0i64;
      if ( (float)((float)((float)(*((float *)v28 + 7) - y) * (float)(*((float *)v28 + 7) - y))
                 + (float)((float)(*((float *)v28 + 6) - x) * (float)(*((float *)v28 + 6) - x))) > v5 )
        v5 = (float)((float)(*((float *)v28 + 7) - y) * (float)(*((float *)v28 + 7) - y))
           + (float)((float)(*((float *)v28 + 6) - x) * (float)(*((float *)v28 + 6) - x));
      v4 += 4i64;
      --v10;
    }
    while ( v10 );
  }
  if ( v3 < mNumGates )
  {
    v29 = this->mGates.mOffset;
    v32 = 8 * v4;
    v33 = mNumGates - v3;
    do
    {
      if ( v29 )
        v34 = (char *)&this->mGates + v29;
      else
        v34 = 0i64;
      v35 = &v34[v32];
      v36 = *(_QWORD *)&v34[v32];
      if ( v36 )
        v36 += (__int64)v35;
      v30 = this->mPosition.x;
      v31 = this->mPosition.y;
      if ( (float)((float)((float)(*(float *)(v36 + 28) - v31) * (float)(*(float *)(v36 + 28) - v31))
                 + (float)((float)(*(float *)(v36 + 24) - v30) * (float)(*(float *)(v36 + 24) - v30))) > v5 )
        v5 = (float)((float)(*(float *)(v36 + 28) - v31) * (float)(*(float *)(v36 + 28) - v31))
           + (float)((float)(*(float *)(v36 + 24) - v30) * (float)(*(float *)(v36 + 24) - v30));
      v32 += 8i64;
      --v33;
    }
    while ( v33 );
  }
  return fsqrt(v5);
}

// File Line: 2702
// RVA: 0xD5F70
UFG::RoadNetworkGate *__fastcall UFG::RoadNetworkIntersection::GetClosestGate(
        UFG::RoadNetworkIntersection *this,
        UFG::qVector3 *pos)
{
  unsigned int mNumGates; // ebx
  float v3; // xmm2_4
  __int64 v5; // r11
  unsigned int v6; // esi
  __int64 v7; // rdx
  __int64 mOffset; // r8
  float x; // xmm3_4
  float y; // xmm4_4
  unsigned int v12; // eax
  __int64 v13; // r9
  char *v14; // rax
  char *v15; // rcx
  __int64 v16; // rax
  char *v17; // rax
  char *v18; // rcx
  __int64 v19; // rax
  char *v20; // rcx
  char *v21; // rax
  char *v22; // rcx
  __int64 v23; // rax
  char *v24; // rcx
  char *v25; // rax
  char *v26; // rcx
  __int64 v27; // rax
  char *v28; // rcx
  __int64 v29; // r8
  float v30; // xmm3_4
  float v31; // xmm4_4
  __int64 v32; // rdx
  __int64 v33; // r9
  char *v34; // rax
  char *v35; // rcx
  __int64 v36; // rax

  mNumGates = (unsigned __int8)this->mNumGates;
  v3 = FLOAT_3_4028235e38;
  v5 = 0i64;
  v6 = 0;
  v7 = 0i64;
  if ( mNumGates >= 4 )
  {
    mOffset = this->mGates.mOffset;
    x = pos->x;
    y = pos->y;
    v12 = ((mNumGates - 4) >> 2) + 1;
    v13 = v12;
    v6 = 4 * v12;
    do
    {
      if ( mOffset )
        v14 = (char *)&this->mGates + mOffset;
      else
        v14 = 0i64;
      v15 = &v14[8 * v7];
      v16 = *(_QWORD *)v15;
      if ( *(_QWORD *)v15 )
        v16 += (__int64)v15;
      if ( (float)((float)((float)(*(float *)(v16 + 28) - y) * (float)(*(float *)(v16 + 28) - y))
                 + (float)((float)(*(float *)(v16 + 24) - x) * (float)(*(float *)(v16 + 24) - x))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v16 + 28) - y) * (float)(*(float *)(v16 + 28) - y))
           + (float)((float)(*(float *)(v16 + 24) - x) * (float)(*(float *)(v16 + 24) - x));
        v5 = v16;
      }
      if ( mOffset )
        v17 = (char *)&this->mGates + mOffset;
      else
        v17 = 0i64;
      v18 = v17 + 8;
      v19 = *(_QWORD *)&v17[8 * v7 + 8];
      v20 = &v18[8 * v7];
      if ( v19 )
        v19 += (__int64)v20;
      if ( (float)((float)((float)(*(float *)(v19 + 28) - y) * (float)(*(float *)(v19 + 28) - y))
                 + (float)((float)(*(float *)(v19 + 24) - x) * (float)(*(float *)(v19 + 24) - x))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v19 + 28) - y) * (float)(*(float *)(v19 + 28) - y))
           + (float)((float)(*(float *)(v19 + 24) - x) * (float)(*(float *)(v19 + 24) - x));
        v5 = v19;
      }
      if ( mOffset )
        v21 = (char *)&this->mGates + mOffset;
      else
        v21 = 0i64;
      v22 = v21 + 16;
      v23 = *(_QWORD *)&v21[8 * v7 + 16];
      v24 = &v22[8 * v7];
      if ( v23 )
        v23 += (__int64)v24;
      if ( (float)((float)((float)(*(float *)(v23 + 28) - y) * (float)(*(float *)(v23 + 28) - y))
                 + (float)((float)(*(float *)(v23 + 24) - x) * (float)(*(float *)(v23 + 24) - x))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v23 + 28) - y) * (float)(*(float *)(v23 + 28) - y))
           + (float)((float)(*(float *)(v23 + 24) - x) * (float)(*(float *)(v23 + 24) - x));
        v5 = v23;
      }
      if ( mOffset )
        v25 = (char *)&this->mGates + mOffset;
      else
        v25 = 0i64;
      v26 = v25 + 24;
      v27 = *(_QWORD *)&v25[8 * v7 + 24];
      v28 = &v26[8 * v7];
      if ( v27 )
        v27 += (__int64)v28;
      if ( (float)((float)((float)(*(float *)(v27 + 28) - y) * (float)(*(float *)(v27 + 28) - y))
                 + (float)((float)(*(float *)(v27 + 24) - x) * (float)(*(float *)(v27 + 24) - x))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v27 + 28) - y) * (float)(*(float *)(v27 + 28) - y))
           + (float)((float)(*(float *)(v27 + 24) - x) * (float)(*(float *)(v27 + 24) - x));
        v5 = v27;
      }
      v7 += 4i64;
      --v13;
    }
    while ( v13 );
  }
  if ( v6 < mNumGates )
  {
    v29 = this->mGates.mOffset;
    v32 = 8 * v7;
    v33 = mNumGates - v6;
    do
    {
      if ( v29 )
        v34 = (char *)&this->mGates + v29;
      else
        v34 = 0i64;
      v35 = &v34[v32];
      v36 = *(_QWORD *)&v34[v32];
      if ( v36 )
        v36 += (__int64)v35;
      v30 = pos->x;
      v31 = pos->y;
      if ( (float)((float)((float)(*(float *)(v36 + 28) - v31) * (float)(*(float *)(v36 + 28) - v31))
                 + (float)((float)(*(float *)(v36 + 24) - v30) * (float)(*(float *)(v36 + 24) - v30))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v36 + 28) - v31) * (float)(*(float *)(v36 + 28) - v31))
           + (float)((float)(*(float *)(v36 + 24) - v30) * (float)(*(float *)(v36 + 24) - v30));
        v5 = v36;
      }
      v32 += 8i64;
      --v33;
    }
    while ( v33 );
  }
  return (UFG::RoadNetworkGate *)v5;
}

// File Line: 2739
// RVA: 0xD1940
void __fastcall UFG::RoadNetworkIntersection::AddLanesToGateModification(
        UFG::RoadNetworkIntersection *this,
        unsigned int gateIndex,
        unsigned int flags)
{
  char *v6; // r15
  unsigned int mNumLanes; // esi
  unsigned int v8; // ebx
  unsigned __int64 v9; // rax
  bool v10; // zf
  unsigned int v11; // edi
  __int64 mOffset; // rax
  char *v13; // rcx
  char *v14; // rax
  char *v15; // rax
  __int64 v16; // rcx
  char *v17; // rbx
  char *v18; // r14
  UFG::RoadNetworkConnection *IncomingConnection; // rax
  __int64 v20; // rcx
  char *v21; // rdx
  __int64 v22; // rax
  char *v23; // rax
  char *v24; // rcx
  char *v25; // rax
  char *v26; // rbx
  void *v27; // rcx
  __int64 v28; // rdi
  unsigned __int64 v29; // rax
  __int64 v30; // rdx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mPrev; // rax
  unsigned int v32; // [rsp+70h] [rbp+8h]

  v6 = 0i64;
  mNumLanes = (unsigned __int8)this->mNumLanes;
  v32 = mNumLanes;
  if ( this->mNumLanes )
  {
    v8 = 1;
    if ( mNumLanes <= 1 )
      goto LABEL_5;
    do
      v8 *= 2;
    while ( v8 < mNumLanes );
    if ( v8 <= 4 )
LABEL_5:
      v8 = 4;
    if ( v8 - mNumLanes > 0x10000 )
      v8 = mNumLanes + 0x10000;
    if ( v8 )
    {
      v9 = 4i64 * v8;
      if ( !is_mul_ok(v8, 4ui64) )
        v9 = -1i64;
      v6 = UFG::qMalloc(v9, "RoadNetworkIntersection", 0i64);
    }
  }
  else
  {
    v10 = mNumLanes == 0;
    mNumLanes = 0;
    if ( !v10 )
      mNumLanes = 0;
    v32 = 0;
  }
  v11 = 0;
  if ( this->mNumLanes )
  {
    do
    {
      mOffset = this->mLane.mOffset;
      if ( mOffset )
        v13 = (char *)&this->mLane + mOffset;
      else
        v13 = 0i64;
      v14 = &v13[8 * v11];
      if ( *(_QWORD *)v14 )
        v15 = &v14[*(_QWORD *)v14];
      else
        v15 = 0i64;
      v16 = *((_QWORD *)v15 + 13);
      if ( v16 )
        v17 = &v15[v16 + 104];
      else
        v17 = 0i64;
      v18 = &v6[4 * v11];
      *(_DWORD *)v18 = (unsigned __int8)v15[44];
      IncomingConnection = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)this, gateIndex);
      v20 = IncomingConnection->mLaneList.mOffset;
      if ( v20 )
        v21 = (char *)&IncomingConnection->mLaneList + v20;
      else
        v21 = 0i64;
      v22 = *((_QWORD *)v17 + 3);
      if ( v22 )
        v23 = &v17[v22 + 24];
      else
        v23 = 0i64;
      if ( *(_QWORD *)v23 )
        v24 = &v23[*(_QWORD *)v23];
      else
        v24 = 0i64;
      if ( v24 == v21 )
        *(_DWORD *)v18 = flags;
      ++v11;
    }
    while ( v11 < (unsigned __int8)this->mNumLanes );
    mNumLanes = v32;
  }
  v25 = UFG::qMalloc(0x30ui64, "RoadNetworkIntersection.RoadNetworkIntersectionModification", 0i64);
  v26 = v25;
  if ( v25 )
  {
    *(_QWORD *)v25 = v25;
    *((_QWORD *)v25 + 1) = v25;
    *((_QWORD *)v25 + 3) = 0i64;
    *((_QWORD *)v25 + 2) = 0i64;
    *((_QWORD *)v25 + 4) = this;
    v27 = (void *)*((_QWORD *)v25 + 3);
    if ( v27 )
      operator delete[](v27);
    *((_QWORD *)v26 + 3) = 0i64;
    *((_QWORD *)v26 + 2) = 0i64;
    if ( mNumLanes )
    {
      *((_DWORD *)v26 + 4) = mNumLanes;
      v28 = mNumLanes;
      v29 = 4i64 * mNumLanes;
      if ( !is_mul_ok(mNumLanes, 4ui64) )
        v29 = -1i64;
      *((_QWORD *)v26 + 3) = UFG::qMalloc(v29, "qArray.Clone", 0i64);
      *((_DWORD *)v26 + 5) = mNumLanes;
      v30 = 0i64;
      do
      {
        *(_DWORD *)(v30 + *((_QWORD *)v26 + 3)) = *(_DWORD *)&v6[v30];
        v30 += 4i64;
        --v28;
      }
      while ( v28 );
    }
    else
    {
      *((_QWORD *)v26 + 3) = 0i64;
      *((_QWORD *)v26 + 2) = 0i64;
    }
    *((_DWORD *)v26 + 10) = 0;
  }
  else
  {
    v26 = 0i64;
  }
  mPrev = this->mModifications.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v26;
  *(_QWORD *)v26 = mPrev;
  *((_QWORD *)v26 + 1) = &this->mModifications;
  this->mModifications.mNode.mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v26;
  UFG::RoadNetworkIntersection::ApplyModification(this, (UFG::RoadNetworkNodeModification *)v26);
  if ( v6 )
    operator delete[](v6);
}

// File Line: 2765
// RVA: 0xD1DF0
void __fastcall UFG::RoadNetworkIntersection::AddPhaseModification(
        UFG::RoadNetworkIntersection *this,
        UFG::RoadNetworkIntersectionModification::AllPhaseStatus status)
{
  char *v4; // rax
  char *v5; // rbx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *mPrev; // rax

  v4 = UFG::qMalloc(0x30ui64, "RoadNetworkIntersection.RoadNetworkIntersectionModification", 0i64);
  v5 = v4;
  if ( v4 )
  {
    UFG::RoadNetworkNodeModification::RoadNetworkNodeModification((UFG::RoadNetworkNodeModification *)v4, this);
    *((_DWORD *)v5 + 10) = status;
  }
  else
  {
    v5 = 0i64;
  }
  mPrev = this->mModifications.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5;
  *(_QWORD *)v5 = mPrev;
  *((_QWORD *)v5 + 1) = &this->mModifications;
  this->mModifications.mNode.mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5;
  UFG::RoadNetworkIntersection::ApplyModification(this, (UFG::RoadNetworkNodeModification *)v5);
}

// File Line: 2773
// RVA: 0xD23F0
void __fastcall UFG::RoadNetworkIntersection::ApplyModification(
        UFG::RoadNetworkIntersection *this,
        UFG::RoadNetworkNodeModification *modification)
{
  unsigned int i; // r8d
  __int64 mOffset; // rax
  char *v6; // rcx
  __int64 v7; // r9
  char *v8; // rax
  char *v9; // rdx
  int mPrev; // eax
  char v11; // r9
  unsigned int j; // ecx
  __int64 v13; // rax
  char *v14; // rdx
  char *v15; // r8
  char *v16; // rax

  if ( modification->mLaneFlagsCollection.size )
  {
    for ( i = 0; i < (unsigned __int8)this->mNumLanes; v9[44] = modification->mLaneFlagsCollection.p[v7] )
    {
      mOffset = this->mLane.mOffset;
      if ( mOffset )
        v6 = (char *)&this->mLane + mOffset;
      else
        v6 = 0i64;
      v7 = i;
      v8 = &v6[8 * i];
      v9 = &v8[*(_QWORD *)v8];
      if ( !*(_QWORD *)v8 )
        v9 = 0i64;
      ++i;
    }
  }
  mPrev = (int)modification[1].mPrev;
  if ( mPrev )
  {
    v11 = 2;
    this->mEnableTimer = 0;
    if ( mPrev == 2 )
    {
      v11 = 1;
    }
    else if ( mPrev == 1 )
    {
      v11 = 0;
    }
    for ( j = 0; j < (unsigned __int8)this->mNumLanes; ++j )
    {
      v13 = this->mLane.mOffset;
      if ( v13 )
        v14 = (char *)&this->mLane + v13;
      else
        v14 = 0i64;
      v15 = &v14[8 * j];
      if ( *(_QWORD *)v15 )
        v16 = &v15[*(_QWORD *)v15];
      else
        v16 = 0i64;
      v16[55] = v11;
    }
  }
  else
  {
    UFG::RoadNetworkIntersection::InitializePhases(this);
    this->mEnableTimer = 1;
  }
}

// File Line: 2974
// RVA: 0xD87C0
char __fastcall UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(UFG::RoadNetworkIntersection *this)
{
  unsigned int mNumGates; // r11d
  int v2; // edx
  __int64 mOffset; // r10
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *p_mGates; // rbx
  __int64 i; // r9
  char *v6; // rax
  char *v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // r8

  mNumGates = (unsigned __int8)this->mNumGates;
  v2 = 0;
  if ( !this->mNumGates )
    return 0;
  mOffset = this->mGates.mOffset;
  p_mGates = &this->mGates;
  for ( i = 0i64; ; i += 8i64 )
  {
    v6 = mOffset ? (char *)p_mGates + mOffset : 0i64;
    v7 = &v6[i];
    v8 = *(_QWORD *)&v6[i];
    if ( v8 )
      v8 += (__int64)v7;
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 )
    {
      v10 = v9 + v8 + 8;
      if ( v10 )
      {
        if ( (*(_DWORD *)(v10 + 168) & 0x40) != 0 )
          break;
      }
    }
    if ( ++v2 >= mNumGates )
      return 0;
  }
  return 1;
}

// File Line: 2993
// RVA: 0xD5E30
bool __fastcall UFG::RoadNetworkIntersection::GetBuildVisibleRoadNetworkByGrid(UFG::RoadNetworkIntersection *this)
{
  unsigned int mNumGates; // ebx
  bool result; // al
  unsigned int v3; // r9d
  __int64 mOffset; // r11
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *p_mGates; // rdi
  __int64 v6; // r10
  char *v7; // rcx
  char *v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // r8

  mNumGates = (unsigned __int8)this->mNumGates;
  result = 0;
  v3 = 0;
  if ( this->mNumGates )
  {
    mOffset = this->mGates.mOffset;
    p_mGates = &this->mGates;
    v6 = 0i64;
    do
    {
      if ( mOffset )
        v7 = (char *)p_mGates + mOffset;
      else
        v7 = 0i64;
      v8 = &v7[v6];
      v9 = *(_QWORD *)&v7[v6];
      if ( v9 )
        v9 += (__int64)v8;
      v10 = *(_QWORD *)(v9 + 8);
      if ( v10 )
      {
        v11 = v10 + v9 + 8;
        if ( v11 )
        {
          result = (*(_DWORD *)(v11 + 168) & 0x20) != 0;
          if ( (*(_DWORD *)(v11 + 168) & 0x20) != 0 )
            break;
        }
      }
      ++v3;
      v6 += 8i64;
    }
    while ( v3 < mNumGates );
  }
  return result;
}

// File Line: 3012
// RVA: 0xDEE50
char __fastcall UFG::RoadNetworkIntersection::IsWater(UFG::RoadNetworkIntersection *this)
{
  __int64 v1; // rdi
  __int64 mOffset; // rax
  char *v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rcx
  UFG::RoadNetworkSegment *v7; // rcx
  unsigned int mValue; // ebx
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int *v10; // rax

  v1 = 0i64;
  if ( !this->mNumGates )
    return 0;
  while ( 1 )
  {
    mOffset = this->mGates.mOffset;
    if ( mOffset )
      v4 = (char *)&this->mGates + mOffset;
    else
      v4 = 0i64;
    v5 = *(_QWORD *)&v4[8 * v1];
    if ( v5 )
      v5 += (__int64)&v4[8 * v1];
    v6 = *(_QWORD *)(v5 + 8);
    if ( v6 )
    {
      v7 = (UFG::RoadNetworkSegment *)(v5 + v6 + 8);
      if ( v7 )
      {
        if ( v7->mpPropertySetCached )
        {
          mValue = v7->mRoadNetworkType.mValue;
        }
        else
        {
          RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(v7);
          mValue = 0;
          if ( RoadPropertySet )
          {
            v10 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
            if ( v10 )
              mValue = *v10;
          }
        }
        if ( mValue - 2 <= 1 )
          break;
      }
    }
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= (unsigned __int8)this->mNumGates )
      return 0;
  }
  return 1;
}

// File Line: 3122
// RVA: 0xE0850
void __fastcall UFG::RoadNetworkTrafficLightPhase::SetLaneStatus(
        UFG::RoadNetworkTrafficLightPhase *this,
        UFG::RoadNetworkLane::LaneStatus laneStatus,
        bool updateTrafficLightEffects)
{
  unsigned int mNumProtectedLanes; // eax
  __int64 v7; // r9
  __int64 v8; // r10
  __int64 mOffset; // rax
  char *v10; // rcx
  char *v11; // rax
  __int64 v12; // rcx
  char *v13; // rax
  unsigned int mNumPermissiveLanes; // eax
  __int64 v15; // rdx
  __int64 v16; // r8
  __int64 v17; // rax
  char *v18; // rcx
  char *v19; // rax
  __int64 v20; // rcx
  char *v21; // rax
  __int64 i; // rdi
  __int64 v23; // rax
  char *v24; // rcx
  UFG::RoadNetworkTrafficLightLocation **v25; // rax
  UFG::RoadNetworkTrafficLightLocation *v26; // rcx
  UFG::RoadNetworkTrafficLightLampData::TrafficLightColour v27; // edx

  mNumProtectedLanes = this->mNumProtectedLanes;
  this->mCurrentStatus = laneStatus;
  if ( mNumProtectedLanes )
  {
    v7 = 0i64;
    v8 = mNumProtectedLanes;
    do
    {
      mOffset = this->mProtectedLanes.mOffset;
      if ( mOffset )
        v10 = (char *)&this->mProtectedLanes + mOffset;
      else
        v10 = 0i64;
      v11 = &v10[v7];
      v12 = *(_QWORD *)&v10[v7];
      if ( v12 )
        v13 = &v11[v12];
      else
        v13 = 0i64;
      v7 += 8i64;
      v13[55] = laneStatus;
      --v8;
    }
    while ( v8 );
  }
  mNumPermissiveLanes = this->mNumPermissiveLanes;
  if ( mNumPermissiveLanes )
  {
    v15 = 0i64;
    v16 = mNumPermissiveLanes;
    do
    {
      v17 = this->mPermissiveLanes.mOffset;
      if ( v17 )
        v18 = (char *)&this->mPermissiveLanes + v17;
      else
        v18 = 0i64;
      v19 = &v18[v15];
      v20 = *(_QWORD *)&v18[v15];
      if ( v20 )
        v21 = &v19[v20];
      else
        v21 = 0i64;
      v15 += 8i64;
      v21[55] = laneStatus;
      --v16;
    }
    while ( v16 );
  }
  if ( updateTrafficLightEffects )
  {
    for ( i = 0i64; (unsigned int)i < this->mNumTrafficLights; i = (unsigned int)(i + 1) )
    {
      v23 = this->mTrafficLightCollection.mOffset;
      if ( v23 )
        v24 = (char *)&this->mTrafficLightCollection + v23;
      else
        v24 = 0i64;
      v25 = *(UFG::RoadNetworkTrafficLightLocation ***)&v24[8 * i];
      if ( v25 )
        v25 = (UFG::RoadNetworkTrafficLightLocation **)&v24[8 * i + (_QWORD)v25];
      v26 = *v25;
      if ( *v25 )
        v26 = (UFG::RoadNetworkTrafficLightLocation *)((char *)v26 + (_QWORD)v25);
      if ( laneStatus )
      {
        if ( laneStatus == YELLOW )
        {
          v27 = yellow;
        }
        else
        {
          v27 = numColours;
          if ( laneStatus == GREEN )
            v27 = green;
        }
      }
      else
      {
        v27 = red;
      }
      UFG::RoadNetworkTrafficLightLocation::SetLampEffect(v26, v27, Straight);
    }
  }
}

// File Line: 3154
// RVA: 0x1460950
hkSeekableStreamReader *dynamic_initializer_for__UFG::RoadNetworkTrafficLightLampData::trafficLight001__()
{
  hkSeekableStreamReader *v0; // rbx
  int i; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::RoadNetworkTrafficLightLampData::trafficLight001;
  for ( i = 2; i >= 0; --i )
  {
    result = Assembly::GetRCX(v0);
    v0 += 4;
  }
  return result;
}

// File Line: 3155
// RVA: 0x1460990
hkSeekableStreamReader *dynamic_initializer_for__UFG::RoadNetworkTrafficLightLampData::trafficLight002__()
{
  hkSeekableStreamReader *v0; // rbx
  int i; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::RoadNetworkTrafficLightLampData::trafficLight002;
  for ( i = 2; i >= 0; --i )
  {
    result = Assembly::GetRCX(v0);
    v0 += 4;
  }
  return result;
}

// File Line: 3172
// RVA: 0xDCB70
void UFG::RoadNetworkTrafficLightLampData::Init(void)
{
  UFG::RoadNetworkTrafficLightLampData::trafficLight001 = (hkSeekableStreamReader)_xmm;
  xmmword_142174AA0 = (__int128)_xmm;
  xmmword_142174AB0 = _xmm;
  xmmword_142174AC0 = _xmm;
  xmmword_142174AD0 = _xmm;
  xmmword_142174AE0 = (__int128)_xmm;
  xmmword_142174AF0 = _xmm;
  xmmword_142174B00 = _xmm;
  xmmword_142174B10 = _xmm;
  xmmword_142174B20 = (__int128)_xmm;
  xmmword_142174B30 = _xmm;
  xmmword_142174B40 = _xmm;
  UFG::RoadNetworkTrafficLightLampData::trafficLight002 = (hkSeekableStreamReader)_xmm;
  xmmword_142174F60 = _xmm;
  xmmword_142174F70 = _xmm;
  xmmword_142174F80 = _xmm;
  xmmword_142174F90 = _xmm;
  xmmword_142174FA0 = _xmm;
  xmmword_142174FB0 = _xmm;
  xmmword_142174FC0 = _xmm;
  xmmword_142174FD0 = _xmm;
  xmmword_142174FE0 = _xmm;
  xmmword_142174FF0 = _xmm;
  xmmword_142175000 = _xmm;
}

// File Line: 3213
// RVA: 0xD9430
__int64 __fastcall UFG::RoadNetworkTrafficLightLampData::GetLampEffectUID(
        UFG::RoadNetworkTrafficLightLampData::TrafficLightColour colour)
{
  unsigned int v2; // eax
  __int64 result; // rax

  v2 = _S8_1;
  if ( (_S8_1 & 1) == 0 )
  {
    _S8_1 |= 1u;
    redUID = UFG::qStringHashUpper32("HK_Stoplight_Red_01_Effect", 0xFFFFFFFF);
    v2 = _S8_1;
  }
  if ( (v2 & 2) == 0 )
  {
    _S8_1 = v2 | 2;
    yellowUID = UFG::qStringHashUpper32("HK_Stoplight_Yellow_01_Effect", 0xFFFFFFFF);
    v2 = _S8_1;
  }
  if ( (v2 & 4) != 0 )
  {
    result = greenUID;
  }
  else
  {
    _S8_1 = v2 | 4;
    result = UFG::qStringHashUpper32("HK_Stoplight_Green_01_Effect", 0xFFFFFFFF);
    greenUID = result;
  }
  if ( colour != green )
  {
    result = redUID;
    if ( colour == yellow )
      return yellowUID;
  }
  return result;
}

// File Line: 3232
// RVA: 0xD5C60
__int64 __fastcall UFG::RoadNetworkTrafficLightLampData::GetArrowEffectUID()
{
  __int64 result; // rax

  if ( (_S9_0 & 1) != 0 )
    return greenArrowUID;
  _S9_0 |= 1u;
  result = UFG::qStringHashUpper32("HK_Stoplight_GrnArrow_01_Effect", 0xFFFFFFFF);
  greenArrowUID = result;
  return result;
}

// File Line: 3250
// RVA: 0xD4580
void __fastcall UFG::RoadNetworkTrafficLightLocation::EnableEffects(UFG::RoadNetworkTrafficLightLocation *this)
{
  this->mFlags &= ~4u;
}

// File Line: 3258
// RVA: 0xD4530
void __fastcall UFG::RoadNetworkTrafficLightLocation::DisableEffects(UFG::RoadNetworkTrafficLightLocation *this)
{
  unsigned int mVehicleSignalEffect; // edx
  unsigned int mPedestrianSignalEffect; // edx

  mVehicleSignalEffect = this->mVehicleSignalEffect;
  if ( mVehicleSignalEffect != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, mVehicleSignalEffect, FXKILLOPTION_DEFAULT);
    this->mVehicleSignalEffect = -1;
  }
  mPedestrianSignalEffect = this->mPedestrianSignalEffect;
  if ( mPedestrianSignalEffect != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, mPedestrianSignalEffect, FXKILLOPTION_DEFAULT);
    this->mPedestrianSignalEffect = -1;
  }
  this->mFlags |= 4u;
}

// File Line: 3299
// RVA: 0xE04C0
void __fastcall UFG::RoadNetworkTrafficLightLocation::SetLampEffect(
        UFG::RoadNetworkTrafficLightLocation *this,
        UFG::RoadNetworkTrafficLightLampData::TrafficLightColour colour,
        UFG::RoadNetworkLane::LaneTurnDirection turnDirection)
{
  __int64 v3; // rdi
  unsigned int mVehicleSignalEffect; // edx
  unsigned int mPedestrianSignalEffect; // edx
  unsigned int mFlags; // eax
  bool v9; // zf
  hkSeekableStreamReader *v10; // rax
  float y; // xmm6_4
  __m128 x_low; // xmm5
  float z; // xmm7_4
  __m128 v14; // xmm2
  float v15; // xmm1_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  __m128 v19; // xmm2
  float v20; // xmm0_4
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  float v23; // xmm10_4
  float v24; // xmm10_4
  __m128 v25; // xmm11
  float v26; // xmm10_4
  __m128 v27; // xmm8
  float v28; // xmm1_4
  float v29; // xmm0_4
  __m128 v30; // xmm9
  float v31; // xmm2_4
  float v32; // xmm8_4
  __m128 v33; // xmm5
  float v34; // xmm3_4
  float x; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  unsigned int ArrowEffectUID; // eax
  UFG::qMatrix44 b; // [rsp+30h] [rbp-E8h] BYREF
  UFG::qMatrix44 result; // [rsp+70h] [rbp-A8h] BYREF

  v3 = colour;
  mVehicleSignalEffect = this->mVehicleSignalEffect;
  if ( mVehicleSignalEffect != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, mVehicleSignalEffect, FXKILLOPTION_DEFAULT);
    this->mVehicleSignalEffect = -1;
  }
  mPedestrianSignalEffect = this->mPedestrianSignalEffect;
  if ( mPedestrianSignalEffect != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, mPedestrianSignalEffect, FXKILLOPTION_DEFAULT);
    this->mPedestrianSignalEffect = -1;
  }
  mFlags = this->mFlags;
  if ( (mFlags & 4) == 0 )
  {
    if ( (mFlags & 1) != 0 || (v9 = (mFlags & 2) == 0, v10 = &UFG::RoadNetworkTrafficLightLampData::trafficLight002, v9) )
      v10 = &UFG::RoadNetworkTrafficLightLampData::trafficLight001;
    y = this->mDirection.y;
    x_low = (__m128)LODWORD(this->mDirection.x);
    z = this->mDirection.z;
    v14 = x_low;
    v14.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
    if ( v14.m128_f32[0] == 0.0 )
      v15 = 0.0;
    else
      v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
    v16 = x_low.m128_f32[0] * v15;
    v17 = y * v15;
    v18 = z * v15;
    b.v0.w = 0.0;
    v19 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    b.v0.x = v16;
    b.v0.y = v17;
    b.v0.z = v18;
    v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
    if ( v19.m128_f32[0] == 0.0 )
    {
      v21 = 0i64;
    }
    else
    {
      v20 = _mm_sqrt_ps(v19).m128_f32[0];
      v21 = (__m128)(unsigned int)FLOAT_1_0;
      v21.m128_f32[0] = 1.0 / v20;
    }
    v22 = v21;
    v23 = v21.m128_f32[0];
    v21.m128_f32[0] = v21.m128_f32[0] * UFG::qVector3::msDirUp.z;
    v24 = v23 * UFG::qVector3::msDirUp.x;
    v22.m128_f32[0] = v22.m128_f32[0] * UFG::qVector3::msDirUp.y;
    v25 = v22;
    v25.m128_f32[0] = (float)(v22.m128_f32[0] * v18) - (float)(v21.m128_f32[0] * v17);
    v21.m128_f32[0] = (float)(v21.m128_f32[0] * v16) - (float)(v24 * v18);
    v26 = (float)(v24 * v17) - (float)(v22.m128_f32[0] * v16);
    v27 = v21;
    v27.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v25.m128_f32[0] * v25.m128_f32[0]))
                    + (float)(v26 * v26);
    if ( v27.m128_f32[0] == 0.0 )
      v28 = 0.0;
    else
      v28 = 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
    v25.m128_f32[0] = v25.m128_f32[0] * v28;
    b.v1.w = 0.0;
    v30 = v25;
    b.v1.z = v26 * v28;
    LODWORD(b.v1.x) = v25.m128_i32[0];
    b.v1.y = v21.m128_f32[0] * v28;
    v29 = (float)(v21.m128_f32[0] * v28) * v18;
    v30.m128_f32[0] = (float)(v25.m128_f32[0] * v18) - (float)((float)(v26 * v28) * v16);
    v31 = (float)((float)(v21.m128_f32[0] * v28) * v16) - (float)(v25.m128_f32[0] * v17);
    v32 = (float)((float)(v26 * v28) * v17) - v29;
    v33 = v30;
    v33.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v32 * v32)) + (float)(v31 * v31);
    if ( v33.m128_f32[0] == 0.0 )
      v34 = 0.0;
    else
      v34 = 1.0 / _mm_sqrt_ps(v33).m128_f32[0];
    x = this->mPosition.x;
    v36 = this->mPosition.y;
    b.v2.w = 0.0;
    b.v3.w = 1.0;
    b.v3.x = x;
    v37 = this->mPosition.z;
    b.v3.y = v36;
    b.v3.z = v37;
    b.v2.x = v32 * v34;
    b.v2.y = v30.m128_f32[0] * v34;
    b.v2.z = v31 * v34;
    UFG::qMatrix44::operator*((UFG::qMatrix44 *)&v10[4 * v3], &result, &b);
    if ( (_DWORD)v3 == 2 && turnDirection == RightTurn )
      ArrowEffectUID = UFG::RoadNetworkTrafficLightLampData::GetArrowEffectUID();
    else
      ArrowEffectUID = UFG::RoadNetworkTrafficLightLampData::GetLampEffectUID((UFG::RoadNetworkTrafficLightLampData::TrafficLightColour)v3);
    this->mVehicleSignalEffect = Render::FXManager::CreateEffect(
                                   &Render::gFXManager,
                                   ArrowEffectUID,
                                   &result,
                                   0xFFFFFFFF);
  }
}

// File Line: 3336
// RVA: 0xDC5C0
void __fastcall UFG::RoadNetworkConnection::GetValidLanes(
        UFG::RoadNetworkConnection *this,
        unsigned __int8 laneFlags,
        UFG::qArray<unsigned long,0> *laneIDs)
{
  __int64 v3; // r14
  __int64 mOffset; // rax
  char *v8; // rcx
  __int64 v9; // rax
  __int64 size; // r15
  unsigned int capacity; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  char *v15; // rax
  unsigned int *v16; // rbp
  __int64 i; // r9
  __int64 v18; // r8
  unsigned int *p; // rax

  v3 = 0i64;
  for ( laneIDs->size = 0; (unsigned int)v3 < this->mNumLanes; v3 = (unsigned int)(v3 + 1) )
  {
    mOffset = this->mLaneList.mOffset;
    if ( mOffset )
      v8 = (char *)&this->mLaneList + mOffset;
    else
      v8 = 0i64;
    v9 = *(_QWORD *)&v8[8 * v3];
    if ( v9 )
      v9 += (__int64)&v8[8 * v3];
    if ( (laneFlags & *(_BYTE *)(v9 + 44)) != 0 )
    {
      size = laneIDs->size;
      capacity = laneIDs->capacity;
      v12 = size + 1;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v13 = 2 * capacity;
        else
          v13 = 1;
        for ( ; v13 < v12; v13 *= 2 )
          ;
        if ( v13 <= 4 )
          v13 = 4;
        if ( v13 - v12 > 0x10000 )
          v13 = size + 65537;
        if ( v13 != (_DWORD)size )
        {
          v14 = 4i64 * v13;
          if ( !is_mul_ok(v13, 4ui64) )
            v14 = -1i64;
          v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
          v16 = (unsigned int *)v15;
          if ( laneIDs->p )
          {
            for ( i = 0i64; (unsigned int)i < laneIDs->size; *(_DWORD *)&v15[v18 * 4] = laneIDs->p[v18] )
            {
              v18 = i;
              i = (unsigned int)(i + 1);
            }
            operator delete[](laneIDs->p);
          }
          laneIDs->p = v16;
          laneIDs->capacity = v13;
        }
      }
      p = laneIDs->p;
      laneIDs->size = v12;
      p[size] = v3;
    }
  }
}

// File Line: 3354
// RVA: 0xDE7A0
char __fastcall UFG::RoadNetworkLane::IsPermissive(UFG::RoadNetworkLane *this, bool checkCurrentPhaseOnly)
{
  char *v3; // rbp
  unsigned int v5; // ebx
  unsigned int v6; // r14d
  __int64 i; // rsi
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rax
  unsigned int v13; // r10d
  unsigned int v14; // edx
  __int64 v15; // r9
  __int64 v16; // r11
  __int64 v17; // r8
  __int64 v18; // rax
  __int64 v19; // rcx
  UFG::RoadNetworkLane *v20; // rax

  if ( this->mNode.mOffset )
    v3 = (char *)this + this->mNode.mOffset;
  else
    v3 = 0i64;
  if ( *(_WORD *)v3 != 1 )
    return 0;
  v5 = 0;
  v6 = (unsigned __int8)v3[107];
  if ( checkCurrentPhaseOnly )
  {
    v5 = *((_DWORD *)v3 + 30);
    v6 = v5 + 1;
  }
  if ( v5 >= v6 )
    return 0;
  for ( i = 8i64 * v5; ; i += 8i64 )
  {
    if ( v3[107] )
    {
      v8 = *((_QWORD *)v3 + 14);
      v9 = v8 ? (__int64)&v3[v8 + 112] : 0i64;
      v10 = i + v9;
      v11 = *(_QWORD *)(i + v9);
      if ( v11 )
      {
        v12 = v11 + v10;
        if ( v12 )
        {
          v13 = *(_DWORD *)(v12 + 16);
          v14 = 0;
          if ( v13 )
            break;
        }
      }
    }
LABEL_25:
    if ( ++v5 >= v6 )
      return 0;
  }
  v15 = *(_QWORD *)(v12 + 40);
  v16 = v12 + 40;
  v17 = 0i64;
  while ( 1 )
  {
    v18 = v15 ? v15 + v16 : 0i64;
    v19 = v17 + v18;
    v20 = *(UFG::RoadNetworkLane **)(v17 + v18);
    if ( v20 )
      v20 = (UFG::RoadNetworkLane *)((char *)v20 + v19);
    if ( v20 == this )
      return 1;
    ++v14;
    v17 += 8i64;
    if ( v14 >= v13 )
      goto LABEL_25;
  }
}

// File Line: 3414
// RVA: 0xD9EE0
float __fastcall UFG::RoadNetworkLane::GetLength(UFG::RoadNetworkLane *this)
{
  UFG::RoadNetworkConnection *v1; // r8
  char *v2; // rax
  unsigned int mPathIndex; // edx
  __int64 v4; // rcx

  v1 = 0i64;
  if ( this->mNode.mOffset )
    v2 = (char *)this + this->mNode.mOffset;
  else
    v2 = 0i64;
  mPathIndex = this->mPathIndex;
  v4 = *((_QWORD *)v2 + 4);
  if ( v4 )
    v1 = (UFG::RoadNetworkConnection *)&v2[v4 + 32];
  return *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v1, mPathIndex)->mNode.mOffset + 1);
}

// File Line: 3420
// RVA: 0xD1640
void __fastcall UFG::RoadNetworkLane::AddCarGuide(
        UFG::RoadNetworkLane *this,
        UFG::RoadNetworkGuide *guide,
        bool spawned)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mPrev; // r9
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mNext; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v5; // r10
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v7; // rcx
  float m_LaneT; // xmm0_4
  float v9; // xmm2_4
  __int64 p_mNext; // rcx
  char *v11; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v12; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v13; // rcx
  float v14; // xmm1_4
  UFG::qList<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide,1,0> *p_mCars; // rcx
  float v16; // xmm2_4
  __int64 v17; // rax
  float v18; // xmm1_4
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v19; // rax

  mPrev = guide->mPrev;
  mNext = guide->mNext;
  v5 = &guide->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  guide->mPrev = &guide->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  guide->mNext = &guide->UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide>;
  if ( !spawned
    || (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&this->mCars.mNode.mNext[-2].mNext == &this->mStartConnection )
  {
    p_mCars = &this->mCars;
  }
  else
  {
    v7 = this->mCars.mNode.mNext;
    m_LaneT = guide->m_CurrentLocation.m_LaneT;
    v9 = *(float *)&v7[2].mPrev;
    p_mNext = (__int64)&v7[-2].mNext;
    v11 = (char *)&this->mCars.mNode.mPrev[-2].mNext;
    if ( m_LaneT == v9 )
    {
LABEL_4:
      v12 = *(UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)(p_mNext + 24);
      v13 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)(p_mNext + 24);
      v12->mNext = v5;
      v5->mPrev = v12;
      v5->mNext = v13;
      v13->mPrev = v5;
      return;
    }
    v14 = *((float *)v11 + 14);
    if ( m_LaneT == v14 )
      goto LABEL_6;
    if ( m_LaneT <= v9 )
      goto LABEL_4;
    if ( m_LaneT > v14 )
    {
LABEL_6:
      p_mCars = (UFG::qList<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide,1,0> *)this->mCars.mNode.mPrev;
    }
    else
    {
      if ( (char *)p_mNext == v11 )
        return;
      while ( 1 )
      {
        v16 = *(float *)(p_mNext + 56);
        v17 = *(_QWORD *)(p_mNext + 32) - 24i64;
        if ( m_LaneT == v16 )
        {
LABEL_16:
          p_mCars = (UFG::qList<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide,1,0> *)(p_mNext + 24);
          goto LABEL_19;
        }
        v18 = *(float *)(v17 + 56);
        if ( m_LaneT == v18 )
          break;
        if ( m_LaneT > v16 && m_LaneT < v18 )
          goto LABEL_16;
        p_mNext = *(_QWORD *)(p_mNext + 32) - 24i64;
        if ( (char *)v17 == v11 )
          return;
      }
      p_mCars = *(UFG::qList<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide,1,0> **)(p_mNext + 32);
    }
  }
LABEL_19:
  v19 = p_mCars->mNode.mNext;
  p_mCars->mNode.mNext = v5;
  v5->mPrev = &p_mCars->mNode;
  v5->mNext = v19;
  v19->mPrev = v5;
}

// File Line: 3514
// RVA: 0xDB180
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetOffsetPos(
        UFG::qVector3 *result,
        UFG::qBezierSplineMemImaged *spline,
        float t,
        float offset)
{
  float v6; // xmm3_4
  int v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float z; // xmm1_4
  UFG::qVector3 *Position; // rax
  float y; // xmm0_4
  UFG::qVector3 tangent; // [rsp+20h] [rbp-38h] BYREF

  if ( offset == 0.0 )
  {
    Position = UFG::qBezierSplineMemImaged::GetPosition(spline, &tangent, t);
    y = Position->y;
    z = Position->z;
    result->x = Position->x;
    result->y = y;
  }
  else
  {
    UFG::qBezierSplineMemImaged::GetPositionAndTangent(spline, t, result, &tangent);
    v6 = tangent.y;
    v7 = LODWORD(tangent.x) ^ _xmm[0];
    v8 = (float)(*(float *)&v7 * *(float *)&v7) + (float)(v6 * v6);
    if ( v8 == 0.0 )
      v9 = 0.0;
    else
      v9 = 1.0 / fsqrt(v8);
    v10 = v9;
    v11 = (float)((float)(*(float *)&v7 * v9) * offset) + result->y;
    z = (float)((float)(v9 * 0.0) * offset) + result->z;
    result->y = v11;
    result->x = (float)((float)(v10 * v6) * offset) + result->x;
  }
  result->z = z;
  return result;
}

// File Line: 3542
// RVA: 0xDB270
char __fastcall UFG::RoadNetworkLane::GetOffsetPosAndTangent(
        UFG::qBezierSplineMemImaged *spline,
        float t,
        float offset,
        UFG::qVector3 *pos,
        UFG::qVector3 *tangent)
{
  float y; // xmm4_4
  int v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm3_4

  UFG::qBezierSplineMemImaged::GetPositionAndTangent(spline, t, pos, tangent);
  if ( offset != 0.0 )
  {
    y = tangent->y;
    v8 = LODWORD(tangent->x) ^ _xmm[0];
    v9 = (float)(*(float *)&v8 * *(float *)&v8) + (float)(y * y);
    if ( v9 == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / fsqrt(v9);
    v11 = (float)((float)(y * v10) * offset) + pos->x;
    v12 = (float)((float)(*(float *)&v8 * v10) * offset) + pos->y;
    pos->z = (float)((float)(v10 * 0.0) * offset) + pos->z;
    pos->x = v11;
    pos->y = v12;
  }
  return 1;
}

// File Line: 3564
// RVA: 0xDB570
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetPosNoOffset(
        UFG::RoadNetworkLane *this,
        UFG::qVector3 *result,
        float laneT)
{
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v4; // r8
  char *v6; // rax
  unsigned int mPathIndex; // edx
  __int64 v8; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v11; // rax
  float splineT; // [rsp+40h] [rbp+8h] BYREF

  mOffset = this->mNode.mOffset;
  v4 = 0i64;
  splineT = 0.0;
  if ( mOffset )
    v6 = (char *)this + mOffset;
  else
    v6 = 0i64;
  mPathIndex = this->mPathIndex;
  v8 = *((_QWORD *)v6 + 4);
  if ( v8 )
    v4 = (UFG::RoadNetworkConnection *)&v6[v8 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v4, mPathIndex);
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, laneT, &splineT);
  v11 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(result, v11, splineT, 0.0);
  return result;
}

// File Line: 3574
// RVA: 0xDB0D0
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetOffsetPos(
        UFG::RoadNetworkLane *this,
        UFG::qVector3 *result,
        float t,
        float offset)
{
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v6; // rcx
  char *v8; // rax
  __int64 v9; // rdx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v12; // rax
  float splineT; // [rsp+68h] [rbp+20h] BYREF

  mOffset = this->mNode.mOffset;
  v6 = 0i64;
  if ( mOffset )
    v8 = (char *)this + mOffset;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 4);
  if ( v9 )
    v6 = (UFG::RoadNetworkConnection *)&v8[v9 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v6, this->mPathIndex);
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, t, &splineT);
  v12 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(result, v12, splineT, offset + this->mOffset);
  return result;
}

// File Line: 3594
// RVA: 0xDA3C0
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetNearestPoint(
        UFG::RoadNetworkLane *this,
        UFG::qVector3 *result,
        UFG::qVector3 *pos,
        float *laneT)
{
  UFG::RoadNetworkConnection *v4; // r10
  char *v8; // rax
  unsigned int mPathIndex; // edx
  __int64 v10; // rcx
  UFG::qBezierPathMemImaged *Path; // rax

  v4 = 0i64;
  if ( this->mNode.mOffset )
    v8 = (char *)this + this->mNode.mOffset;
  else
    v8 = 0i64;
  mPathIndex = this->mPathIndex;
  v10 = *((_QWORD *)v8 + 4);
  if ( v10 )
    v4 = (UFG::RoadNetworkConnection *)&v8[v10 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v4, mPathIndex);
  UFG::qBezierPathMemImaged::ClosestPoint3D(Path, result, pos, laneT);
  return result;
}

// File Line: 3602
// RVA: 0xD8160
float __fastcall UFG::RoadNetworkLane::GetClosestT(UFG::RoadNetworkLane *this, UFG::qVector3 *pos)
{
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v3; // r8
  char *v5; // rax
  unsigned int mPathIndex; // edx
  __int64 v7; // rcx
  UFG::qBezierPathMemImaged *Path; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF
  float t; // [rsp+40h] [rbp+8h] BYREF

  mOffset = this->mNode.mOffset;
  v3 = 0i64;
  t = 0.0;
  if ( mOffset )
    v5 = (char *)this + mOffset;
  else
    v5 = 0i64;
  mPathIndex = this->mPathIndex;
  v7 = *((_QWORD *)v5 + 4);
  if ( v7 )
    v3 = (UFG::RoadNetworkConnection *)&v5[v7 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v3, mPathIndex);
  UFG::qBezierPathMemImaged::ClosestPoint3D(Path, &result, pos, &t);
  return t;
}

// File Line: 3609
// RVA: 0xDB360
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetPos(UFG::RoadNetworkLane *this, UFG::qVector3 *result, float t)
{
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v5; // rcx
  char *v7; // rax
  __int64 v8; // rdx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v11; // rax
  float splineT; // [rsp+40h] [rbp+8h] BYREF

  mOffset = this->mNode.mOffset;
  v5 = 0i64;
  if ( mOffset )
    v7 = (char *)this + mOffset;
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 4);
  if ( v8 )
    v5 = (UFG::RoadNetworkConnection *)&v7[v8 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v5, this->mPathIndex);
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, t, &splineT);
  v11 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(result, v11, splineT, this->mOffset);
  return result;
}

// File Line: 3619
// RVA: 0xDB4C0
char __fastcall UFG::RoadNetworkLane::GetPosAndTangent(
        UFG::RoadNetworkLane *this,
        float t,
        UFG::qVector3 *pos,
        UFG::qVector3 *tangent)
{
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v6; // rcx
  char *v9; // rax
  __int64 v10; // rdx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v13; // rax
  float splineT; // [rsp+50h] [rbp+8h] BYREF

  mOffset = this->mNode.mOffset;
  v6 = 0i64;
  if ( mOffset )
    v9 = (char *)this + mOffset;
  else
    v9 = 0i64;
  v10 = *((_QWORD *)v9 + 4);
  if ( v10 )
    v6 = (UFG::RoadNetworkConnection *)&v9[v10 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v6, this->mPathIndex);
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, t, &splineT);
  v13 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  return UFG::RoadNetworkLane::GetOffsetPosAndTangent(v13, splineT, this->mOffset, pos, tangent);
}

// File Line: 3631
// RVA: 0xD5F50
UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **__fastcall UFG::RoadNetworkLane::GetClosestCarToStart(
        UFG::RoadNetworkLane *this)
{
  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&this->mCars.mNode.mNext[-2].mNext == &this->mStartConnection )
    return 0i64;
  else
    return &this->mCars.mNode.mNext[-2].mNext;
}

// File Line: 3647
// RVA: 0xDE8A0
bool __fastcall UFG::RoadNetworkLane::IsReversedInNode(UFG::RoadNetworkLane *this)
{
  __int64 mOffset; // rdx
  char *v2; // r9
  char *v3; // r8
  __int64 v4; // rcx
  char *v5; // rcx
  char *v6; // r8
  __int64 v7; // rcx

  mOffset = this->mStartGate.mOffset;
  if ( mOffset )
    v2 = (char *)&this->mStartGate + mOffset;
  else
    v2 = 0i64;
  v3 = (char *)this + this->mNode.mOffset;
  if ( !this->mNode.mOffset )
    v3 = 0i64;
  v4 = *((_QWORD *)v3 + 6);
  if ( v4 )
    v5 = &v3[v4 + 48];
  else
    v5 = 0i64;
  v6 = &v5[*(_QWORD *)v5];
  if ( !*(_QWORD *)v5 )
    v6 = 0i64;
  v7 = *((_QWORD *)v6 + 1);
  if ( v7 )
    return v2 != &v6[v7 + 8];
  else
    return v2 != 0i64;
}

// File Line: 3653
// RVA: 0xD9510
signed __int64 __fastcall UFG::RoadNetworkLane::GetLaneDirection(
        UFG::RoadNetworkLane *this,
        UFG::RoadNetworkLane *otherLane)
{
  __int64 mOffset; // rcx
  signed __int64 result; // rax
  char *v5; // r9
  __int64 v7; // r11
  char *v8; // rdi
  char *v9; // rcx
  char *v10; // r10
  __int64 v11; // rcx
  char *v12; // r15
  __int64 v13; // rcx
  char *v14; // rsi
  int mLaneIndex; // r14d
  unsigned int v16; // ebx
  int v17; // r10d
  __int64 v18; // r8
  __int64 v19; // r9
  char *v20; // rcx
  char *v21; // rdx
  __int64 v22; // rcx
  UFG::RoadNetworkLane *v23; // rcx
  __int64 v24; // rdx
  __int64 v25; // rdx
  int v26; // r9d
  __int64 i; // r8
  char *v28; // rcx
  char *v29; // rdx
  UFG::RoadNetworkLane *v30; // rcx
  __int64 v31; // rdx
  __int64 v32; // rdx

  mOffset = this->mNode.mOffset;
  result = 0i64;
  v5 = (char *)this + mOffset;
  if ( !mOffset )
    v5 = 0i64;
  v7 = *((_QWORD *)v5 + 6);
  v8 = v5 + 48;
  v9 = &v5[v7 + 48];
  if ( !v7 )
    v9 = 0i64;
  v10 = &v9[*(_QWORD *)v9];
  if ( !*(_QWORD *)v9 )
    v10 = 0i64;
  v11 = *((_QWORD *)v10 + 1);
  if ( v11 )
    v12 = &v10[v11 + 8];
  else
    v12 = 0i64;
  v13 = this->mStartGate.mOffset;
  if ( v13 )
    v14 = (char *)&this->mStartGate + v13;
  else
    v14 = 0i64;
  mLaneIndex = this->mLaneIndex;
  v16 = (unsigned __int8)v5[40];
  v17 = 0;
  v18 = (unsigned int)(mLaneIndex + 1);
  if ( (unsigned int)v18 < v16 )
  {
    v19 = 8 * v18;
    do
    {
      v20 = &v8[v7];
      if ( !v7 )
        v20 = 0i64;
      v21 = &v20[v19];
      v22 = *(_QWORD *)&v20[v19];
      v23 = v22 ? (UFG::RoadNetworkLane *)&v21[v22] : 0i64;
      v24 = v23->mStartGate.mOffset;
      v25 = v24 ? (__int64)&v23->mStartGate + v24 : 0i64;
      if ( (char *)v25 != v14 )
        break;
      if ( v23 == otherLane )
      {
        v17 = v18 - mLaneIndex;
        if ( (_DWORD)v18 != mLaneIndex )
          goto LABEL_42;
        break;
      }
      LODWORD(v18) = v18 + 1;
      v19 += 8i64;
    }
    while ( (unsigned int)v18 < v16 );
  }
  v26 = mLaneIndex - 1;
  for ( i = mLaneIndex - 1; i >= 0; --i )
  {
    v28 = &v8[v7];
    if ( !v7 )
      v28 = 0i64;
    v29 = &v28[8 * i];
    v30 = *(_QWORD *)v29 ? (UFG::RoadNetworkLane *)&v29[*(_QWORD *)v29] : 0i64;
    v31 = v30->mStartGate.mOffset;
    v32 = v31 ? (__int64)&v30->mStartGate + v31 : 0i64;
    if ( (char *)v32 != v14 )
      break;
    if ( v30 == otherLane )
    {
      v17 = v26 - mLaneIndex;
      break;
    }
    --v26;
  }
LABEL_42:
  if ( v14 != v12 )
    v17 = -v17;
  if ( v17 > 0 )
    return 1i64;
  if ( v17 < 0 )
    return 2i64;
  return result;
}

// File Line: 3700
// RVA: 0xDC430
__int64 __fastcall UFG::RoadNetworkLane::GetTurnDirection(UFG::RoadNetworkLane *this)
{
  char mDirection; // dl
  __int64 result; // rax

  mDirection = this->mDirection;
  if ( mDirection == -1 )
    return 1i64;
  result = 0i64;
  if ( mDirection == 1 )
    return 2i64;
  return result;
}

// File Line: 3730
// RVA: 0xDE4A0
bool __fastcall UFG::RoadNetworkLane::IsFlagMatch(UFG::RoadNetworkLane *this, unsigned __int8 laneFlags)
{
  return (laneFlags & this->mLaneFlags) != 0;
}

// File Line: 3735
// RVA: 0xDF350
bool __fastcall UFG::RoadNetworkLane::LaneChangeAvailable(UFG::RoadNetworkLane *this, unsigned int *whichLanes)
{
  unsigned int v4; // r12d
  __int64 mOffset; // r15
  char *v6; // rbp
  int v8; // esi
  int v9; // edi
  int mLaneIndex; // eax
  int v11; // r11d
  __int64 v12; // rcx
  __int64 v13; // r10
  __int64 v14; // rax
  char *v15; // rdx
  __int64 v16; // rax
  char *v17; // rcx
  char *v18; // rax
  __int64 v19; // rcx
  char *v20; // r8
  char *v21; // rdx
  __int64 v22; // rax
  char *v23; // rax
  char *v24; // rdx
  __int64 v25; // rax
  char *v26; // rax
  bool v27; // zf
  __int64 v28; // rax
  char *v29; // r8
  char *v30; // rax
  __int64 v31; // rcx
  char *v32; // rax
  char *v33; // rdx
  __int64 v34; // rax
  char *v35; // rcx
  __int64 v36; // rax
  char *v37; // rcx
  __int64 v38; // rax
  char *v39; // rax
  __int64 v40; // rcx
  char *v41; // r8
  char *v42; // rdx
  __int64 v43; // rax
  char *v44; // rax
  char *v45; // rdx
  __int64 v46; // rax
  char *v47; // rax
  bool v48; // zf
  __int64 v49; // rax
  char *v50; // r8
  char *v51; // rax
  __int64 v52; // rcx
  char *v53; // rax
  char *v54; // rdx
  __int64 v55; // rax
  char *v56; // rax

  v4 = 0;
  if ( whichLanes )
    *whichLanes = 0;
  mOffset = this->mNode.mOffset;
  v6 = (char *)this + this->mNode.mOffset;
  if ( !this->mNode.mOffset )
    v6 = 0i64;
  if ( *(_WORD *)v6 == 1 )
    return 0;
  v8 = -1;
  v9 = 1;
  if ( UFG::RoadNetworkLane::IsReversedInNode(this) )
  {
    v8 = 1;
    v9 = -1;
  }
  mLaneIndex = this->mLaneIndex;
  v11 = (unsigned __int8)v6[40];
  v12 = (unsigned int)(mLaneIndex + v8);
  v13 = (unsigned int)(mLaneIndex + v9);
  if ( (int)v12 >= 0 && (int)v12 < v11 )
  {
    v14 = *((_QWORD *)v6 + 6);
    if ( v14 )
      v15 = &v6[v14 + 48];
    else
      v15 = 0i64;
    v16 = *(_QWORD *)&v15[8 * v12];
    v17 = &v15[8 * v12];
    if ( v16 )
      v18 = &v17[v16];
    else
      v18 = 0i64;
    v19 = *((_QWORD *)v18 + 1);
    if ( v19 )
      v20 = &v18[v19 + 8];
    else
      v20 = 0i64;
    v21 = &v18[*(_QWORD *)v18];
    if ( !*(_QWORD *)v18 )
      v21 = 0i64;
    v22 = *((_QWORD *)v21 + 6);
    if ( v22 )
      v23 = &v21[v22 + 48];
    else
      v23 = 0i64;
    v24 = &v23[*(_QWORD *)v23];
    if ( !*(_QWORD *)v23 )
      v24 = 0i64;
    v25 = *((_QWORD *)v24 + 1);
    if ( v25 )
      v26 = &v24[v25 + 8];
    else
      v26 = 0i64;
    v27 = v20 == v26;
    v28 = this->mStartGate.mOffset;
    if ( v28 )
      v29 = (char *)&this->mStartGate + v28;
    else
      v29 = 0i64;
    v30 = (char *)this + mOffset;
    if ( !mOffset )
      v30 = 0i64;
    v31 = *((_QWORD *)v30 + 6);
    if ( v31 )
      v32 = &v30[v31 + 48];
    else
      v32 = 0i64;
    v33 = &v32[*(_QWORD *)v32];
    if ( !*(_QWORD *)v32 )
      v33 = 0i64;
    v34 = *((_QWORD *)v33 + 1);
    if ( v34 )
      v35 = &v33[v34 + 8];
    else
      v35 = 0i64;
    if ( !v27 == (v29 != v35) )
      v4 = 2;
  }
  if ( (int)v13 >= 0 && (int)v13 < v11 )
  {
    v36 = *((_QWORD *)v6 + 6);
    if ( v36 )
      v37 = &v6[v36 + 48];
    else
      v37 = 0i64;
    v38 = *(_QWORD *)&v37[8 * v13];
    if ( v38 )
      v39 = &v37[8 * v13 + v38];
    else
      v39 = 0i64;
    v40 = *((_QWORD *)v39 + 1);
    if ( v40 )
      v41 = &v39[v40 + 8];
    else
      v41 = 0i64;
    v42 = &v39[*(_QWORD *)v39];
    if ( !*(_QWORD *)v39 )
      v42 = 0i64;
    v43 = *((_QWORD *)v42 + 6);
    if ( v43 )
      v44 = &v42[v43 + 48];
    else
      v44 = 0i64;
    v45 = &v44[*(_QWORD *)v44];
    if ( !*(_QWORD *)v44 )
      v45 = 0i64;
    v46 = *((_QWORD *)v45 + 1);
    if ( v46 )
      v47 = &v45[v46 + 8];
    else
      v47 = 0i64;
    v48 = v41 == v47;
    v49 = this->mStartGate.mOffset;
    if ( v49 )
      v50 = (char *)&this->mStartGate + v49;
    else
      v50 = 0i64;
    v51 = (char *)this + mOffset;
    if ( !mOffset )
      v51 = 0i64;
    v52 = *((_QWORD *)v51 + 6);
    if ( v52 )
      v53 = &v51[v52 + 48];
    else
      v53 = 0i64;
    v54 = &v53[*(_QWORD *)v53];
    if ( !*(_QWORD *)v53 )
      v54 = 0i64;
    v55 = *((_QWORD *)v54 + 1);
    if ( v55 )
      v56 = &v54[v55 + 8];
    else
      v56 = 0i64;
    if ( !v48 == (v50 != v56) )
      ++v4;
  }
  if ( whichLanes )
    *whichLanes = v4;
  return v4 != 0;
}

// File Line: 3779
// RVA: 0xDAF70
__int64 __fastcall UFG::RoadNetworkLane::GetNumberOfCarsInLaneAheadOfDistance(UFG::RoadNetworkLane *this, float d)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mNext; // rax
  UFG::qOffset64<UFG::RoadNetworkConnection *> *p_mStartConnection; // rcx
  __int64 p_mNext; // rax
  int v6; // edx
  __int64 mOffset; // rax
  __int64 v8; // rdi
  UFG::RoadNetworkConnection *v9; // rcx
  UFG::RoadNetworkLane *Path; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *mPrev; // rbx
  UFG::qOffset64<UFG::RoadNetworkConnection *> *v12; // rsi
  __int64 v13; // rbx
  unsigned int v14; // ebp
  float i; // xmm6_4
  __int64 v16; // rax
  __int64 v17; // rcx
  unsigned int v18; // edx
  __int64 v19; // rax
  UFG::RoadNetworkConnection *v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rcx
  unsigned int v23; // edx
  __int64 v24; // rax
  UFG::RoadNetworkConnection *v25; // rcx
  float v26; // xmm0_4

  mNext = this->mCars.mNode.mNext;
  p_mStartConnection = &this->mStartConnection;
  p_mNext = (__int64)&mNext[-2].mNext;
  v6 = 0;
  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)p_mNext == p_mStartConnection )
    return 0i64;
  do
  {
    ++v6;
    p_mNext = *(_QWORD *)(p_mNext + 32) - 24i64;
  }
  while ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)p_mNext != p_mStartConnection );
  if ( !v6 )
    return 0i64;
  mOffset = this->mNode.mOffset;
  v8 = 0i64;
  if ( this->mNode.mOffset )
    mOffset += (__int64)this;
  v9 = *(UFG::RoadNetworkConnection **)(mOffset + 32);
  if ( v9 )
    v9 = (UFG::RoadNetworkConnection *)((char *)v9 + mOffset + 32);
  Path = UFG::qBezierPathCollectionMemImaged::GetPath(v9, this->mPathIndex);
  mPrev = this->mCars.mNode.mPrev;
  v12 = &this->mStartConnection;
  v13 = (__int64)&mPrev[-2].mNext;
  v14 = 0;
  for ( i = *((float *)&Path->mNode.mOffset + 1);
        (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v13 != v12;
        v13 = *(_QWORD *)(v13 + 24) - 24i64 )
  {
    if ( v8 )
    {
      v16 = *(_QWORD *)(v8 + 64);
      v17 = *(_QWORD *)v16;
      if ( *(_QWORD *)v16 )
        v17 += v16;
      v18 = *(unsigned __int16 *)(v16 + 38);
      v19 = *(_QWORD *)(v17 + 32);
      if ( v19 )
        v20 = (UFG::RoadNetworkConnection *)(v19 + v17 + 32);
      else
        v20 = 0i64;
      i = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v20, v18)->mNode.mOffset + 1) * *(float *)(v8 + 56);
    }
    v21 = *(_QWORD *)(v13 + 64);
    v22 = *(_QWORD *)v21;
    if ( *(_QWORD *)v21 )
      v22 += v21;
    v23 = *(unsigned __int16 *)(v21 + 38);
    v24 = *(_QWORD *)(v22 + 32);
    if ( v24 )
      v25 = (UFG::RoadNetworkConnection *)(v24 + v22 + 32);
    else
      v25 = 0i64;
    v26 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v25, v23)->mNode.mOffset + 1) * *(float *)(v13 + 56);
    if ( v26 > d && v26 < i )
    {
      v8 = v13;
      ++v14;
    }
  }
  return v14;
}

// File Line: 3803
// RVA: 0xDBD00
__int64 __fastcall UFG::RoadNetworkLane::GetStatus(UFG::RoadNetworkLane *this)
{
  return (unsigned __int8)this->mStatus.mValue;
}

// File Line: 3871
// RVA: 0xD2DA0
float __fastcall UFG::RoadNetworkLane::CalculateParkingOffset(UFG::RoadNetworkLane *this, UFG::qVector3 *position)
{
  __int64 mOffset; // rax
  unsigned int mPathIndex; // edx
  UFG::RoadNetworkConnection *v6; // rcx
  UFG::qBezierPathMemImaged *Path; // rax
  __int64 v8; // rax
  UFG::RoadNetworkConnection *v9; // rcx
  UFG::qBezierPathMemImaged *v10; // rax
  float v11; // xmm8_4
  UFG::RoadNetworkConnection *v12; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v14; // rax
  __m128 y_low; // xmm2
  float v16; // xmm6_4
  __int64 v17; // rax
  UFG::RoadNetworkConnection *v18; // rcx
  UFG::qBezierPathMemImaged *v19; // rbx
  unsigned int v20; // eax
  UFG::qBezierSplineMemImaged *v21; // rax
  __m128 v22; // xmm3
  UFG::qVector3 result; // [rsp+20h] [rbp-68h] BYREF
  float t; // [rsp+90h] [rbp+8h] BYREF
  float splineT; // [rsp+98h] [rbp+10h] BYREF

  t = 0.0;
  mOffset = this->mNode.mOffset;
  if ( this->mNode.mOffset )
    mOffset += (__int64)this;
  mPathIndex = this->mPathIndex;
  v6 = *(UFG::RoadNetworkConnection **)(mOffset + 32);
  if ( v6 )
    v6 = (UFG::RoadNetworkConnection *)((char *)v6 + mOffset + 32);
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v6, mPathIndex);
  UFG::qBezierPathMemImaged::ClosestPoint3D(Path, &result, position, &t);
  v8 = this->mNode.mOffset;
  if ( this->mNode.mOffset )
    v8 += (__int64)this;
  v9 = *(UFG::RoadNetworkConnection **)(v8 + 32);
  if ( v9 )
    v9 = (UFG::RoadNetworkConnection *)((char *)v9 + v8 + 32);
  v10 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v9, this->mPathIndex);
  v11 = t;
  v12 = (UFG::RoadNetworkConnection *)v10;
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(v10, t, &splineT);
  v14 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v12, SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v14, splineT, this->mOffset);
  y_low = (__m128)LODWORD(result.y);
  v16 = this->mOffset;
  y_low.m128_f32[0] = (float)((float)((float)(result.y - position->y) * (float)(result.y - position->y))
                            + (float)((float)(result.x - position->x) * (float)(result.x - position->x)))
                    + (float)((float)(result.z - position->z) * (float)(result.z - position->z));
  if ( (float)(_mm_sqrt_ps(y_low).m128_f32[0] - 2.0) < 0.75 )
  {
    do
    {
      v17 = this->mNode.mOffset;
      v16 = v16 + 0.25;
      if ( this->mNode.mOffset )
        v17 += (__int64)this;
      v18 = *(UFG::RoadNetworkConnection **)(v17 + 32);
      if ( v18 )
        v18 = (UFG::RoadNetworkConnection *)((char *)v18 + v17 + 32);
      v19 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v18, this->mPathIndex);
      v20 = UFG::qBezierPathMemImaged::GetSplineParameters(v19, v11, &t);
      v21 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             (UFG::RoadNetworkConnection *)v19,
                                             v20);
      UFG::RoadNetworkLane::GetOffsetPos(&result, v21, t, v16 + this->mOffset);
      v22 = (__m128)LODWORD(result.y);
      v22.m128_f32[0] = (float)((float)((float)(result.y - position->y) * (float)(result.y - position->y))
                              + (float)((float)(result.x - position->x) * (float)(result.x - position->x)))
                      + (float)((float)(result.z - position->z) * (float)(result.z - position->z));
    }
    while ( (float)(_mm_sqrt_ps(v22).m128_f32[0] - 2.0) < 0.75 );
  }
  return v16;
}

// File Line: 3977
// RVA: 0xDB330
UFG::RoadNetworkConnection *__fastcall UFG::RoadNetworkGate::GetOutgoingConnection(
        UFG::RoadNetworkGate *this,
        unsigned int index)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  UFG::RoadNetworkConnection **v4; // rdx
  UFG::RoadNetworkConnection *result; // rax

  mOffset = this->mOutgoingConnection.mOffset;
  if ( mOffset )
    v3 = (char *)&this->mOutgoingConnection + mOffset;
  else
    v3 = 0i64;
  v4 = (UFG::RoadNetworkConnection **)&v3[8 * index];
  result = *v4;
  if ( *v4 )
    return (UFG::RoadNetworkConnection *)((char *)result + (_QWORD)v4);
  return result;
}

// File Line: 3984
// RVA: 0xD5B30
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(
        UFG::RoadNetworkGate *this,
        UFG::RoadNetworkNode *targetNode)
{
  unsigned int mNumOutgoingConnections; // r15d
  int v3; // edi
  __int64 mOffset; // r14
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *p_mOutgoingConnection; // r12
  __int64 i; // rsi
  char *v8; // rax
  char *v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  unsigned int *v12; // rax
  unsigned int v13; // r11d
  unsigned int v14; // r8d
  __int64 v15; // r10
  int *v16; // rbx
  __int64 v17; // r9
  __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rcx
  _QWORD *v24; // rax
  UFG::RoadNetworkNode **v25; // rax
  UFG::RoadNetworkNode *v26; // rcx

  mNumOutgoingConnections = this->mNumOutgoingConnections;
  v3 = 0;
  if ( !mNumOutgoingConnections )
    return 0i64;
  mOffset = this->mOutgoingConnection.mOffset;
  p_mOutgoingConnection = &this->mOutgoingConnection;
  for ( i = 0i64; ; i += 8i64 )
  {
    if ( mOffset )
      v8 = (char *)p_mOutgoingConnection + mOffset;
    else
      v8 = 0i64;
    v9 = &v8[i];
    v10 = *(_QWORD *)&v8[i];
    if ( v10 )
      v10 += (__int64)v9;
    v11 = *(_QWORD *)(v10 + 16);
    if ( v11 )
    {
      v12 = (unsigned int *)(v11 + v10 + 16);
      if ( v12 )
      {
        v13 = *v12;
        v14 = 0;
        if ( *v12 )
          break;
      }
    }
LABEL_30:
    if ( ++v3 >= mNumOutgoingConnections )
      return 0i64;
  }
  v15 = *((_QWORD *)v12 + 1);
  v16 = (int *)(v12 + 2);
  v17 = 0i64;
  while ( 1 )
  {
    if ( v15 )
      v18 = (__int64)v16 + v15;
    else
      v18 = 0i64;
    v19 = v17 + v18;
    v20 = *(_QWORD *)(v17 + v18);
    if ( v20 )
      v21 = v20 + v19;
    else
      v21 = 0i64;
    v22 = *(_QWORD *)(v21 + 104);
    if ( v22 )
      v23 = v22 + v21 + 104;
    else
      v23 = 0i64;
    v24 = *(_QWORD **)(v23 + 8);
    if ( v24 )
      v24 = (_QWORD *)((char *)v24 + v23 + 8);
    v25 = *v24 ? (UFG::RoadNetworkNode **)((char *)v24 + *v24) : 0i64;
    v26 = *v25;
    if ( *v25 )
      v26 = (UFG::RoadNetworkNode *)((char *)v26 + (_QWORD)v25);
    if ( v26 == targetNode )
      return (UFG::RoadNetworkLane *)v21;
    ++v14;
    v17 += 8i64;
    if ( v14 >= v13 )
      goto LABEL_30;
  }
}

// File Line: 4010
// RVA: 0xD5A00
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkGate::GetAnyLaneLeadingHereFromNode(
        UFG::RoadNetworkGate *this,
        UFG::RoadNetworkNode *targetNode)
{
  unsigned int mNumIncomingConnections; // r15d
  int v3; // edi
  __int64 mOffset; // r14
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *p_mIncomingConnection; // r12
  __int64 i; // rsi
  char *v8; // rax
  char *v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  unsigned int *v12; // rax
  unsigned int v13; // r11d
  unsigned int v14; // r8d
  __int64 v15; // r10
  int *v16; // rbx
  __int64 v17; // r9
  __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rcx
  _QWORD *v24; // rax
  UFG::RoadNetworkNode **v25; // rax
  UFG::RoadNetworkNode *v26; // rcx

  mNumIncomingConnections = this->mNumIncomingConnections;
  v3 = 0;
  if ( !mNumIncomingConnections )
    return 0i64;
  mOffset = this->mIncomingConnection.mOffset;
  p_mIncomingConnection = &this->mIncomingConnection;
  for ( i = 0i64; ; i += 8i64 )
  {
    if ( mOffset )
      v8 = (char *)p_mIncomingConnection + mOffset;
    else
      v8 = 0i64;
    v9 = &v8[i];
    v10 = *(_QWORD *)&v8[i];
    if ( v10 )
      v10 += (__int64)v9;
    v11 = *(_QWORD *)(v10 + 16);
    if ( v11 )
    {
      v12 = (unsigned int *)(v11 + v10 + 16);
      if ( v12 )
      {
        v13 = *v12;
        v14 = 0;
        if ( *v12 )
          break;
      }
    }
LABEL_30:
    if ( ++v3 >= mNumIncomingConnections )
      return 0i64;
  }
  v15 = *((_QWORD *)v12 + 1);
  v16 = (int *)(v12 + 2);
  v17 = 0i64;
  while ( 1 )
  {
    if ( v15 )
      v18 = (__int64)v16 + v15;
    else
      v18 = 0i64;
    v19 = v17 + v18;
    v20 = *(_QWORD *)(v17 + v18);
    if ( v20 )
      v21 = v20 + v19;
    else
      v21 = 0i64;
    v22 = *(_QWORD *)(v21 + 80);
    if ( v22 )
      v23 = v22 + v21 + 80;
    else
      v23 = 0i64;
    v24 = *(_QWORD **)(v23 + 8);
    if ( v24 )
      v24 = (_QWORD *)((char *)v24 + v23 + 8);
    v25 = *v24 ? (UFG::RoadNetworkNode **)((char *)v24 + *v24) : 0i64;
    v26 = *v25;
    if ( *v25 )
      v26 = (UFG::RoadNetworkNode *)((char *)v26 + (_QWORD)v25);
    if ( v26 == targetNode )
      return (UFG::RoadNetworkLane *)v21;
    ++v14;
    v17 += 8i64;
    if ( v14 >= v13 )
      goto LABEL_30;
  }
}

// File Line: 4031
// RVA: 0xD8840
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkGate::GetFirstOutgoingLaneLeadingToNode(
        UFG::RoadNetworkGate *this,
        UFG::RoadNetworkNode *targetNode)
{
  unsigned int mNumOutgoingConnections; // r13d
  __int64 v3; // r8
  unsigned int v5; // ebp
  __int64 mOffset; // r12
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *p_mOutgoingConnection; // rax
  __int64 v8; // r14
  char *v9; // rax
  char *v10; // rcx
  __int64 v11; // rax
  char *v12; // rsi
  __int64 v13; // rax
  unsigned int *v14; // rax
  unsigned int v15; // ebx
  unsigned int v16; // r9d
  __int64 v17; // r11
  int *v18; // rdi
  __int64 v19; // r10
  __int64 v20; // rax
  __int64 v21; // rcx
  __int64 v22; // rax
  char *v23; // rax
  char *v24; // rdx
  __int64 v25; // rcx
  char *v26; // rax
  __int64 v27; // rcx
  char *v28; // rax
  UFG::RoadNetworkNode *v29; // rcx
  __int64 v30; // rax
  char *v31; // rax
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *i; // [rsp+30h] [rbp+8h]

  mNumOutgoingConnections = this->mNumOutgoingConnections;
  v3 = 0i64;
  v5 = 0;
  if ( !mNumOutgoingConnections )
    return 0i64;
  mOffset = this->mOutgoingConnection.mOffset;
  p_mOutgoingConnection = &this->mOutgoingConnection;
  v8 = 0i64;
  for ( i = &this->mOutgoingConnection; ; p_mOutgoingConnection = i )
  {
    if ( mOffset )
      v9 = (char *)p_mOutgoingConnection + mOffset;
    else
      v9 = 0i64;
    v10 = &v9[v8];
    v11 = *(_QWORD *)&v9[v8];
    v12 = &v10[v11];
    if ( !v11 )
      v12 = 0i64;
    v13 = *((_QWORD *)v12 + 2);
    if ( v13 )
    {
      v14 = (unsigned int *)&v12[v13 + 16];
      if ( v14 )
      {
        v15 = *v14;
        v16 = 0;
        if ( *v14 )
          break;
      }
    }
LABEL_34:
    ++v5;
    v8 += 8i64;
    if ( v5 >= mNumOutgoingConnections )
      return 0i64;
  }
  v17 = *((_QWORD *)v14 + 1);
  v18 = (int *)(v14 + 2);
  v19 = 0i64;
  while ( 1 )
  {
    v20 = (__int64)v18 + v17;
    if ( !v17 )
      v20 = 0i64;
    v21 = v19 + v20;
    v22 = *(_QWORD *)(v19 + v20);
    if ( v22 )
      v23 = (char *)(v21 + v22);
    else
      v23 = 0i64;
    v24 = &v23[*(_QWORD *)v23];
    if ( !*(_QWORD *)v23 )
      v24 = 0i64;
    if ( *(_WORD *)v24 == 1 )
    {
      v25 = *((_QWORD *)v23 + 13);
      if ( v25 )
        v26 = &v23[v25 + 104];
      else
        v26 = 0i64;
      v27 = *((_QWORD *)v26 + 1);
      if ( v27 )
        v28 = &v26[v27 + 8];
      else
        v28 = 0i64;
      if ( *(_QWORD *)v28 )
        v23 = &v28[*(_QWORD *)v28];
      else
        v23 = 0i64;
    }
    v29 = *(_QWORD *)v23 ? (UFG::RoadNetworkNode *)&v23[*(_QWORD *)v23] : 0i64;
    if ( v29 == targetNode )
      break;
    ++v16;
    v19 += 8i64;
    if ( v16 >= v15 )
      goto LABEL_34;
  }
  v30 = *((_QWORD *)v12 + 1);
  if ( v30 )
    v31 = &v12[v30 + 8];
  else
    v31 = 0i64;
  if ( *(_QWORD *)v31 )
    return (UFG::RoadNetworkLane *)&v31[*(_QWORD *)v31];
  return (UFG::RoadNetworkLane *)v3;
}

// File Line: 4060
// RVA: 0xD9D40
void __fastcall UFG::RoadNetworkGate::GetLanesLeadingToNode(
        UFG::RoadNetworkGate *this,
        UFG::RoadNetworkNode *targetNode,
        UFG::RoadNetworkLane **laneList,
        unsigned int *numLanes,
        unsigned int maxLanes,
        unsigned __int8 laneFlags)
{
  __int64 v6; // rbp
  __int64 mOffset; // rax
  char *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // r10
  __int64 v13; // rax
  __int64 v14; // rsi
  __int64 v15; // r11
  __int64 v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // rcx
  _WORD *v20; // rdx
  __int64 v21; // rax
  __int64 v22; // rdx
  _QWORD *v23; // rax
  UFG::RoadNetworkNode **v24; // rax
  UFG::RoadNetworkNode *v25; // rcx
  __int64 v26; // rdx
  __int64 v27; // rax
  __int64 v28; // rcx
  __int64 v29; // rax
  UFG::RoadNetworkLane *v30; // rcx

  v6 = 0i64;
  if ( this->mNumOutgoingConnections )
  {
    while ( 1 )
    {
      mOffset = this->mOutgoingConnection.mOffset;
      v10 = mOffset ? (char *)&this->mOutgoingConnection + mOffset : 0i64;
      v11 = *(_QWORD *)&v10[8 * v6];
      v12 = v11 ? (__int64)&v10[8 * v6 + v11] : 0i64;
      v13 = *(_QWORD *)(v12 + 16);
      if ( v13 )
      {
        v14 = v13 + v12 + 16;
        if ( v14 )
        {
          v15 = 0i64;
          if ( *(_DWORD *)v14 )
            break;
        }
      }
LABEL_44:
      v6 = (unsigned int)(v6 + 1);
      if ( (unsigned int)v6 >= this->mNumOutgoingConnections )
        return;
    }
    while ( 1 )
    {
      v16 = *(_QWORD *)(v14 + 8);
      v17 = v16 ? v16 + v14 + 8 : 0i64;
      v18 = *(_QWORD *)(v17 + 8 * v15);
      v19 = v18 ? v18 + v17 + 8 * v15 : 0i64;
      v20 = *(_QWORD *)v19 ? (_WORD *)(*(_QWORD *)v19 + v19) : 0i64;
      if ( *v20 == 1 )
      {
        v21 = *(_QWORD *)(v19 + 104);
        if ( v21 )
          v22 = v21 + v19 + 104;
        else
          v22 = 0i64;
        v23 = *(_QWORD **)(v22 + 8);
        if ( v23 )
          v23 = (_QWORD *)((char *)v23 + v22 + 8);
        v24 = *v23 ? (UFG::RoadNetworkNode **)((char *)v23 + *v23) : 0i64;
      }
      else
      {
        v24 = (UFG::RoadNetworkNode **)v19;
      }
      if ( (laneFlags & *(_BYTE *)(v19 + 44)) != 0 )
      {
        v25 = *v24;
        if ( *v24 )
          v25 = (UFG::RoadNetworkNode *)((char *)v25 + (_QWORD)v24);
        if ( v25 == targetNode )
        {
          v26 = 0i64;
          if ( *(_DWORD *)v12 )
            break;
        }
      }
LABEL_43:
      v15 = (unsigned int)(v15 + 1);
      if ( (unsigned int)v15 >= *(_DWORD *)v14 )
        goto LABEL_44;
    }
    while ( 1 )
    {
      v27 = *(_QWORD *)(v12 + 8);
      v28 = v27 ? v27 + v12 + 8 : 0i64;
      v29 = *(_QWORD *)(v28 + 8 * v26);
      v30 = v29 ? (UFG::RoadNetworkLane *)(v29 + v28 + 8 * v26) : 0i64;
      laneList[(*numLanes)++] = v30;
      if ( *numLanes == maxLanes )
        break;
      v26 = (unsigned int)(v26 + 1);
      if ( (unsigned int)v26 >= *(_DWORD *)v12 )
        goto LABEL_43;
    }
  }
}

