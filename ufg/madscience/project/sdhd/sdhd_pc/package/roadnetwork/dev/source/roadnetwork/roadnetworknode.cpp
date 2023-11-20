// File Line: 102
// RVA: 0xDF620
void __fastcall qPagedLinearAllocator::NewPage(qPagedLinearAllocator *this)
{
  qPagedLinearAllocator *v1; // rbx
  char *v2; // rax
  char *v3; // rdx
  UFG::qNode<qPagedLinearAllocator::PageHeader,qPagedLinearAllocator::PageHeader> *v4; // rax

  v1 = this;
  v2 = UFG::qMemoryPool::Allocate(this->mpPool, this->mPageSize, this->mPageTag, 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = v2;
    *((_QWORD *)v2 + 1) = v2;
  }
  else
  {
    v3 = 0i64;
  }
  v1->mpCurrentPage = (qPagedLinearAllocator::PageHeader *)v3;
  v4 = v1->mPages.mNode.mPrev;
  v4->mNext = (UFG::qNode<qPagedLinearAllocator::PageHeader,qPagedLinearAllocator::PageHeader> *)v3;
  *(_QWORD *)v3 = v4;
  *((_QWORD *)v3 + 1) = (char *)v1 + 48;
  v1->mPages.mNode.mPrev = (UFG::qNode<qPagedLinearAllocator::PageHeader,qPagedLinearAllocator::PageHeader> *)v3;
  v1->mpCurrentPos = &v1->mpCurrentPage[1];
  v1->mRemainingBytesOnPage = v1->mPageSize - 16;
}

// File Line: 148
// RVA: 0xD96B0
qPagedLinearAllocator *__fastcall GetLaneTAllocator()
{
  if ( !(_S3_3 & 1) )
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
UFG::RoadNetworkConnection *__fastcall UFG::RoadNetworkGate::GetIncomingConnection(UFG::RoadNetworkGate *this, unsigned int index)
{
  __int64 v2; // rax
  char *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rdx
  UFG::RoadNetworkConnection *result; // rax

  v2 = this->mIncomingConnection.mOffset;
  if ( v2 )
    v3 = (char *)&this->mIncomingConnection + v2;
  else
    v3 = 0i64;
  v4 = index;
  v5 = (signed __int64)&v3[8 * v4];
  result = *(UFG::RoadNetworkConnection **)&v3[8 * v4];
  if ( result )
    result = (UFG::RoadNetworkConnection *)((char *)result + v5);
  return result;
}

// File Line: 515
// RVA: 0xD5EA0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkNode::GetCenterLane(UFG::RoadNetworkNode *this)
{
  __int64 v1; // rdx
  __int64 v2; // rax
  char *v3; // rcx
  signed __int64 v4; // rdx
  UFG::RoadNetworkLane *result; // rax

  v1 = this->mLane.mOffset;
  v2 = ((unsigned __int8)this->mNumLanes - 1) / 2;
  if ( v1 )
    v3 = (char *)&this->mLane + v1;
  else
    v3 = 0i64;
  v4 = (signed __int64)&v3[8 * v2];
  result = *(UFG::RoadNetworkLane **)&v3[8 * v2];
  if ( result )
    result = (UFG::RoadNetworkLane *)((char *)result + v4);
  return result;
}

// File Line: 522
// RVA: 0xD5EE0
__int64 __fastcall UFG::RoadNetworkNode::GetCenterLaneIndex(UFG::RoadNetworkNode *this)
{
  return ((unsigned __int8)this->mNumLanes - 1) / 2;
}

// File Line: 531
// RVA: 0xD69F0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkSegment::GetClosestLaneToCenter(UFG::RoadNetworkSegment *this, unsigned int index)
{
  unsigned int v2; // er8
  UFG::RoadNetworkLane *v3; // rbx
  __int64 v4; // r9
  __int64 v5; // rax
  char *v6; // rcx
  __int64 v7; // rax
  UFG::RoadNetworkLane *result; // rax
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkLane *> *> *v9; // r13
  __int64 v10; // r14
  _QWORD *v11; // rax
  UFG::RoadNetworkLane *v12; // r12
  char *v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rcx
  UFG::RoadNetworkLane *v16; // r15
  char *v17; // rcx
  __int64 v18; // rax
  signed __int64 v19; // rdx
  __int64 v20; // rax
  UFG::RoadNetworkLane *v21; // rsi
  char *v22; // rcx
  __int64 v23; // rax
  signed __int64 v24; // rdi
  __int64 v25; // r10
  signed __int64 v26; // r8
  __int64 v27; // r11
  char *v28; // rax
  __int64 v29; // rcx
  char *v30; // rax
  char *v31; // rdx
  __int64 v32; // rax
  signed __int64 v33; // rax
  bool v34; // zf
  __int64 v35; // rax
  signed __int64 v36; // r8
  char *v37; // rcx
  __int64 v38; // rax
  char *v39; // rax
  char *v40; // rdx
  __int64 v41; // rax
  signed __int64 v42; // rax
  __int64 v43; // rax
  signed __int64 v44; // r8
  signed __int64 v45; // rcx
  __int64 v46; // rax
  _QWORD *v47; // rax
  char *v48; // rdx
  __int64 v49; // rax
  signed __int64 v50; // rax
  bool v51; // r9
  signed __int64 v52; // r8
  char *v53; // rax
  __int64 v54; // rcx
  char *v55; // rax
  char *v56; // rdx
  __int64 v57; // rax
  signed __int64 v58; // rax
  __int64 v59; // rax
  signed __int64 v60; // rbp
  signed __int64 v61; // rcx
  __int64 v62; // rax
  _QWORD *v63; // rax
  char *v64; // rdx
  __int64 v65; // rax
  signed __int64 v66; // rsi
  __int64 v67; // rax
  char *v68; // rcx
  signed __int64 v69; // rdx
  __int64 v70; // rax
  __int64 v71; // rax
  signed __int64 v72; // rbp
  signed __int64 v73; // rcx
  __int64 v74; // rax
  _QWORD *v75; // rax
  char *v76; // rdx
  __int64 v77; // rax
  signed __int64 v78; // rsi
  char *v79; // rcx
  __int64 v80; // rax
  signed __int64 v81; // rdx
  __int64 v82; // rax
  unsigned int v83; // [rsp+60h] [rbp+8h]
  UFG::RoadNetworkLane *v84; // [rsp+70h] [rbp+18h]

  LOBYTE(v2) = this->mNumLanes;
  v3 = 0i64;
  v4 = index;
  if ( (_BYTE)v2 == 1 )
  {
    v5 = this->mLane.mOffset;
    if ( v5 )
      v6 = (char *)&this->mLane + v5;
    else
      v6 = 0i64;
    v7 = *(_QWORD *)&v6[8 * index];
    if ( v7 )
      v3 = (UFG::RoadNetworkLane *)&v6[8 * index + v7];
    result = v3;
  }
  else
  {
    v9 = &this->mLane;
    v10 = this->mLane.mOffset;
    v11 = (__int64 *)((char *)&this->mLane.mOffset + v10);
    if ( !v10 )
      v11 = 0i64;
    v12 = (UFG::RoadNetworkLane *)((char *)v11 + *v11);
    if ( !*v11 )
      v12 = 0i64;
    v13 = (char *)v9 + v10;
    if ( !v10 )
      v13 = 0i64;
    v2 = (unsigned __int8)v2;
    v83 = v2;
    v14 = (unsigned int)(unsigned __int8)v2 - 1;
    v15 = *(_QWORD *)&v13[8 * v14];
    v16 = (UFG::RoadNetworkLane *)&v13[8 * v14 + v15];
    if ( !v15 )
      v16 = 0i64;
    v17 = (char *)v9 + v10;
    v18 = (signed int)(v2 - 1) / 2;
    if ( !v10 )
      v17 = 0i64;
    v19 = (signed __int64)&v17[8 * v18];
    v20 = *(_QWORD *)&v17[8 * v18];
    v21 = (UFG::RoadNetworkLane *)(v19 + v20);
    if ( !v20 )
      v21 = 0i64;
    v84 = v21;
    v22 = (char *)v9 + v10;
    if ( !v10 )
      v22 = 0i64;
    v23 = *(_QWORD *)&v22[8 * v4];
    v24 = (signed __int64)&v22[8 * v4 + v23];
    if ( !v23 )
      v24 = 0i64;
    v25 = v12->mStartGate.mOffset;
    if ( v25 )
      v26 = (signed __int64)&v12->mStartGate + v25;
    else
      v26 = 0i64;
    v27 = v12->mNode.mOffset;
    v28 = (char *)v12 + v12->mNode.mOffset;
    if ( !v12->mNode.mOffset )
      v28 = 0i64;
    v29 = *((_QWORD *)v28 + 6);
    if ( v29 )
      v30 = &v28[v29 + 48];
    else
      v30 = 0i64;
    v31 = &v30[*(_QWORD *)v30];
    if ( !*(_QWORD *)v30 )
      v31 = 0i64;
    v32 = *((_QWORD *)v31 + 1);
    if ( v32 )
      v33 = (signed __int64)&v31[v32 + 8];
    else
      v33 = 0i64;
    v34 = v26 == v33;
    v35 = v16->mStartGate.mOffset;
    if ( v35 )
      v36 = (signed __int64)&v16->mStartGate + v35;
    else
      v36 = 0i64;
    v37 = (char *)v16 + v16->mNode.mOffset;
    if ( !v16->mNode.mOffset )
      v37 = 0i64;
    v38 = *((_QWORD *)v37 + 6);
    if ( v38 )
      v39 = &v37[v38 + 48];
    else
      v39 = 0i64;
    v40 = &v39[*(_QWORD *)v39];
    if ( !*(_QWORD *)v39 )
      v40 = 0i64;
    v41 = *((_QWORD *)v40 + 1);
    if ( v41 )
      v42 = (signed __int64)&v40[v41 + 8];
    else
      v42 = 0i64;
    if ( !v34 != (v36 != v42) )
    {
      v43 = *(_QWORD *)(v24 + 8);
      if ( v43 )
        v44 = v24 + v43 + 8;
      else
        v44 = 0i64;
      v45 = *(_QWORD *)v24 + v24;
      if ( !*(_QWORD *)v24 )
        v45 = 0i64;
      v46 = *(_QWORD *)(v45 + 48);
      if ( v46 )
        v47 = (_QWORD *)(v45 + v46 + 48);
      else
        v47 = 0i64;
      v48 = (char *)v47 + *v47;
      if ( !*v47 )
        v48 = 0i64;
      v49 = *((_QWORD *)v48 + 1);
      if ( v49 )
        v50 = (signed __int64)&v48[v49 + 8];
      else
        v50 = 0i64;
      v51 = v44 != v50;
      if ( v25 )
        v52 = (signed __int64)&v12->mStartGate + v25;
      else
        v52 = 0i64;
      v53 = (char *)v12 + v27;
      if ( !v27 )
        v53 = 0i64;
      v54 = *((_QWORD *)v53 + 6);
      if ( v54 )
        v55 = &v53[v54 + 48];
      else
        v55 = 0i64;
      v56 = &v55[*(_QWORD *)v55];
      if ( !*(_QWORD *)v55 )
        v56 = 0i64;
      v57 = *((_QWORD *)v56 + 1);
      if ( v57 )
        v58 = (signed __int64)&v56[v57 + 8];
      else
        v58 = 0i64;
      if ( v51 == (v52 != v58) )
      {
        while ( 1 )
        {
          v59 = *(_QWORD *)(v24 + 8);
          if ( v59 )
            v60 = v24 + v59 + 8;
          else
            v60 = 0i64;
          v61 = *(_QWORD *)v24 + v24;
          if ( !*(_QWORD *)v24 )
            v61 = 0i64;
          v62 = *(_QWORD *)(v61 + 48);
          if ( v62 )
            v63 = (_QWORD *)(v61 + v62 + 48);
          else
            v63 = 0i64;
          v64 = (char *)v63 + *v63;
          if ( !*v63 )
            v64 = 0i64;
          v65 = *((_QWORD *)v64 + 1);
          v66 = (signed __int64)(v65 ? &v64[v65 + 8] : 0i64);
          if ( (v60 != v66) != UFG::RoadNetworkLane::IsReversedInNode(v12) )
            break;
          v84 = (UFG::RoadNetworkLane *)v24;
          v67 = (unsigned int)*(unsigned __int16 *)(v24 + 36) + 1;
          if ( (unsigned int)v67 >= v83 )
          {
            v21 = (UFG::RoadNetworkLane *)v24;
            goto LABEL_119;
          }
          v68 = (char *)v9 + v10;
          if ( !v10 )
            v68 = 0i64;
          v69 = (signed __int64)&v68[8 * v67];
          v70 = *(_QWORD *)&v68[8 * v67];
          if ( v70 )
            v24 = v69 + v70;
          else
            v24 = 0i64;
        }
      }
      else
      {
        while ( 1 )
        {
          v71 = *(_QWORD *)(v24 + 8);
          if ( v71 )
            v72 = v24 + v71 + 8;
          else
            v72 = 0i64;
          v73 = *(_QWORD *)v24 + v24;
          if ( !*(_QWORD *)v24 )
            v73 = 0i64;
          v74 = *(_QWORD *)(v73 + 48);
          if ( v74 )
            v75 = (_QWORD *)(v73 + v74 + 48);
          else
            v75 = 0i64;
          v76 = (char *)v75 + *v75;
          if ( !*v75 )
            v76 = 0i64;
          v77 = *((_QWORD *)v76 + 1);
          v78 = (signed __int64)(v77 ? &v76[v77 + 8] : 0i64);
          if ( (v72 != v78) != UFG::RoadNetworkLane::IsReversedInNode(v16) )
            break;
          v84 = (UFG::RoadNetworkLane *)v24;
          v79 = (char *)v9 + v10;
          v80 = (unsigned int)*(unsigned __int16 *)(v24 + 36) - 1;
          if ( !v10 )
            v79 = 0i64;
          v81 = (signed __int64)&v79[8 * v80];
          v82 = *(_QWORD *)&v79[8 * v80];
          if ( v82 )
            v24 = v81 + v82;
          else
            v24 = 0i64;
        }
      }
      v21 = v84;
    }
LABEL_119:
    result = v21;
  }
  return result;
}
            v79 = 0i64;
          v81 = (signed __int64)&v79[8 * v80];
          v82 = *(_QWORD *)&v79

// File Line: 577
// RVA: 0xDAA30
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetNearestPos(UFG::RoadNetworkNode *this, UFG::qVector3 *result, UFG::qVector3 *pos, UFG::RoadNetworkLane **nearestLane, float *nearestT)
{
  UFG::RoadNetworkLane *v5; // rbp
  __int64 v6; // rdi
  float v7; // xmm6_4
  float v8; // xmm7_4
  UFG::RoadNetworkLane **v9; // r12
  UFG::qVector3 *v10; // r15
  UFG::qVector3 *v11; // r14
  UFG::RoadNetworkNode *v12; // rsi
  __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rax
  signed __int64 v16; // rbx
  __int64 v17; // rax
  UFG::RoadNetworkConnection *v18; // rcx
  UFG::qBezierPathMemImaged *v19; // rax
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm2_4
  float *v23; // rax
  UFG::qVector3 resulta; // [rsp+20h] [rbp-58h]
  float t; // [rsp+80h] [rbp+8h]

  v5 = 0i64;
  result->x = this->mPosition.x;
  v6 = 0i64;
  v7 = 0.0;
  v8 = FLOAT_3_4028235e38;
  result->y = this->mPosition.y;
  v9 = nearestLane;
  v10 = pos;
  v11 = result;
  v12 = this;
  result->z = this->mPosition.z;
  t = 0.0;
  if ( this->mNumLanes )
  {
    do
    {
      v13 = v12->mLane.mOffset;
      if ( v13 )
        v14 = (signed __int64)&v12->mLane + v13;
      else
        v14 = 0i64;
      v15 = *(_QWORD *)(v14 + 8 * v6);
      if ( v15 )
        v16 = v15 + v14 + 8 * v6;
      else
        v16 = 0i64;
      v17 = *(_QWORD *)v16;
      if ( *(_QWORD *)v16 )
        v17 += v16;
      v18 = *(UFG::RoadNetworkConnection **)(v17 + 32);
      if ( v18 )
        v18 = (UFG::RoadNetworkConnection *)((char *)v18 + v17 + 32);
      v19 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v18,
                                           *(unsigned __int16 *)(v16 + 38));
      UFG::qBezierPathMemImaged::ClosestPoint3D(v19, &resulta, v10, &t);
      v20 = resulta.y;
      v21 = resulta.z;
      v22 = (float)((float)((float)(resulta.y - v10->y) * (float)(resulta.y - v10->y))
                  + (float)((float)(resulta.x - v10->x) * (float)(resulta.x - v10->x)))
          + (float)((float)(resulta.z - v10->z) * (float)(resulta.z - v10->z));
      if ( v22 < v8 )
      {
        v7 = t;
        v11->x = resulta.x;
        v11->y = v20;
        v8 = v22;
        v5 = (UFG::RoadNetworkLane *)v16;
        v11->z = v21;
      }
      v6 = (unsigned int)(v6 + 1);
    }
    while ( (unsigned int)v6 < (unsigned __int8)v12->mNumLanes );
  }
  v23 = nearestT;
  *v9 = v5;
  *v23 = v7;
  return v11;
}

// File Line: 607
// RVA: 0xDA430
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetNearestPos(UFG::RoadNetworkNode *this, UFG::qVector3 *result, UFG::qVector3 *pos, UFG::qVector3 *_heading, UFG::RoadNetworkLane **nearestLane, float *nearestT)
{
  float v6; // xmm7_4
  UFG::qVector3 *v7; // r15
  UFG::qVector3 *v8; // r13
  UFG::RoadNetworkNode *v9; // rdi
  float v10; // xmm10_4
  __m128 v11; // xmm9
  float v12; // xmm11_4
  __m128 v13; // xmm2
  float v14; // xmm1_4
  float v15; // xmm9_4
  float v16; // xmm10_4
  _QWORD *v17; // r14
  float v18; // xmm11_4
  float v19; // xmm6_4
  unsigned int v20; // ecx
  __int64 v21; // r12
  __int64 v22; // rax
  signed __int64 v23; // rcx
  __int64 v24; // rax
  signed __int64 v25; // rsi
  _QWORD *v26; // rax
  float *v27; // r15
  __int64 v28; // rax
  UFG::RoadNetworkConnection *v29; // rcx
  UFG::qBezierPathMemImaged *v30; // rax
  UFG::RoadNetworkConnection *v31; // rbx
  unsigned int v32; // eax
  UFG::qBezierSplineMemImaged *v33; // rax
  float v34; // xmm2_4
  __m128 v35; // xmm3
  float v36; // xmm4_4
  __m128 v37; // xmm5
  float v38; // xmm1_4
  float v39; // xmm2_4
  __int64 v40; // rax
  __int64 v41; // r12
  __int64 v42; // rax
  signed __int64 v43; // rcx
  __int64 v44; // rax
  signed __int64 v45; // rsi
  _QWORD *v46; // rax
  float *v47; // r15
  __int64 v48; // rax
  UFG::RoadNetworkConnection *v49; // rcx
  UFG::qBezierPathMemImaged *v50; // rax
  UFG::RoadNetworkConnection *v51; // rbx
  unsigned int v52; // eax
  UFG::qBezierSplineMemImaged *v53; // rax
  float v54; // ST1C_4
  float v55; // xmm2_4
  __m128 v56; // xmm3
  float v57; // xmm4_4
  __m128 v58; // xmm5
  float v59; // xmm1_4
  float v60; // xmm2_4
  __int64 v61; // rax
  float v62; // xmm6_4
  char *v63; // rsi
  __int64 v64; // rdi
  char *v65; // rbx
  __int64 v66; // rax
  UFG::RoadNetworkConnection *v67; // rcx
  UFG::qBezierPathMemImaged *v68; // rax
  float v69; // xmm4_4
  float v70; // xmm5_4
  __m128 v71; // xmm2
  float v72; // xmm1_4
  float v73; // xmm6_4
  __int64 v74; // rsi
  __int64 v75; // rax
  signed __int64 v76; // rcx
  __int64 v77; // rax
  signed __int64 v78; // rbx
  __int64 v79; // rax
  UFG::RoadNetworkConnection *v80; // rcx
  UFG::qBezierPathMemImaged *v81; // rax
  float v82; // xmm4_4
  float v83; // xmm5_4
  __m128 v84; // xmm2
  float v85; // xmm1_4
  float splineT; // [rsp+20h] [rbp-79h]
  UFG::qVector3 resulta; // [rsp+28h] [rbp-71h]
  UFG::qVector3 v89; // [rsp+38h] [rbp-61h]
  unsigned int v90; // [rsp+F0h] [rbp+57h]
  float t; // [rsp+F8h] [rbp+5Fh]
  float *vars0; // [rsp+100h] [rbp+67h]
  float retaddr; // [rsp+108h] [rbp+6Fh]
  _QWORD *v94; // [rsp+110h] [rbp+77h]
  float *v95; // [rsp+118h] [rbp+7Fh]

  v6 = 0.0;
  v7 = pos;
  v8 = result;
  v9 = this;
  v10 = _heading->y;
  v11 = (__m128)LODWORD(_heading->x);
  v12 = _heading->z;
  result->x = this->mPosition.x;
  result->y = this->mPosition.y;
  v13 = v11;
  result->z = this->mPosition.z;
  v13.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10)) + (float)(v12 * v12);
  if ( v13.m128_f32[0] == 0.0 )
    v14 = 0.0;
  else
    v14 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
  v15 = v11.m128_f32[0] * v14;
  v16 = v10 * v14;
  v17 = 0i64;
  v18 = v12 * v14;
  if ( this->mType.mValue == 1 )
  {
    v19 = FLOAT_N2_0;
    v20 = 0;
    v21 = 0i64;
    v90 = 0;
    if ( v9->mNumIncomingConnections > 0u )
    {
      do
      {
        v22 = v9->mIncomingConnections.mOffset;
        if ( v22 )
          v23 = (signed __int64)&v9->mIncomingConnections + v22;
        else
          v23 = 0i64;
        v24 = *(_QWORD *)(v23 + 8 * v21);
        if ( v24 )
          v25 = v23 + 8 * v21 + v24;
        else
          v25 = 0i64;
        v26 = *(_QWORD **)(v25 + 8);
        if ( v26 )
          v26 = (_QWORD *)((char *)v26 + v25 + 8);
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
        v30 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v29,
                                             *((unsigned __int16 *)v27 + 19));
        v31 = (UFG::RoadNetworkConnection *)v30;
        v32 = UFG::qBezierPathMemImaged::GetSplineParameters(v30, 0.0, &splineT);
        v33 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v31, v32);
        UFG::RoadNetworkLane::GetOffsetPos(&resulta, v33, splineT, v27[10]);
        v7 = (UFG::qVector3 *)vars0;
        v35 = (__m128)LODWORD(resulta.y);
        v34 = resulta.x - *vars0;
        v35.m128_f32[0] = resulta.y - vars0[1];
        v36 = resulta.z - vars0[2];
        v37 = v35;
        v37.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v34 * v34)) + (float)(v36 * v36);
        if ( v37.m128_f32[0] == 0.0 )
          v38 = 0.0;
        else
          v38 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
        v39 = (float)((float)((float)(v34 * v38) * v15) + (float)((float)(v35.m128_f32[0] * v38) * v16))
            + (float)((float)(v36 * v38) * v18);
        if ( v39 <= v19 )
        {
          v20 = v90;
        }
        else
        {
          v40 = *(_QWORD *)(v25 + 8);
          v20 = *(_DWORD *)v25;
          v90 = *(_DWORD *)v25;
          if ( v40 )
          {
            v19 = v39;
            v17 = (_QWORD *)(v25 + v40 + 8);
          }
          else
          {
            v17 = 0i64;
            v19 = v39;
          }
        }
        v21 = (unsigned int)(v21 + 1);
      }
      while ( (unsigned int)v21 < (unsigned __int8)v9->mNumIncomingConnections );
    }
    v41 = 0i64;
    if ( v9->mNumOutgoingConnections )
    {
      do
      {
        v42 = v9->mOutgoingConnections.mOffset;
        if ( v42 )
          v43 = (signed __int64)&v9->mOutgoingConnections + v42;
        else
          v43 = 0i64;
        v44 = *(_QWORD *)(v43 + 8 * v41);
        if ( v44 )
          v45 = v43 + 8 * v41 + v44;
        else
          v45 = 0i64;
        v46 = *(_QWORD **)(v45 + 8);
        if ( v46 )
          v46 = (_QWORD *)((char *)v46 + v45 + 8);
        if ( *v46 )
          v47 = (float *)((char *)v46 + *v46);
        else
          v47 = 0i64;
        v48 = *(_QWORD *)v47;
        if ( *(_QWORD *)v47 )
          v48 += (__int64)v47;
        v49 = *(UFG::RoadNetworkConnection **)(v48 + 32);
        if ( v49 )
          v49 = (UFG::RoadNetworkConnection *)((char *)v49 + v48 + 32);
        v50 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v49,
                                             *((unsigned __int16 *)v47 + 19));
        v51 = (UFG::RoadNetworkConnection *)v50;
        v52 = UFG::qBezierPathMemImaged::GetSplineParameters(v50, 1.0, &splineT);
        v53 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v51, v52);
        UFG::RoadNetworkLane::GetOffsetPos(&v89, v53, splineT, v47[10]);
        v7 = (UFG::qVector3 *)vars0;
        v56 = (__m128)LODWORD(v54);
        v55 = v89.x - *vars0;
        v56.m128_f32[0] = v54 - vars0[1];
        v57 = splineT - vars0[2];
        v58 = v56;
        v58.m128_f32[0] = (float)((float)(v56.m128_f32[0] * v56.m128_f32[0]) + (float)(v55 * v55)) + (float)(v57 * v57);
        if ( v58.m128_f32[0] == 0.0 )
          v59 = 0.0;
        else
          v59 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v58));
        v60 = (float)((float)((float)(v55 * v59) * v15) + (float)((float)(v56.m128_f32[0] * v59) * v16))
            + (float)((float)(v57 * v59) * v18);
        if ( v60 <= v19 )
        {
          v20 = v90;
        }
        else
        {
          v61 = *(_QWORD *)(v45 + 8);
          v20 = *(_DWORD *)v45;
          v90 = *(_DWORD *)v45;
          if ( v61 )
          {
            v19 = v60;
            v17 = (_QWORD *)(v45 + v61 + 8);
          }
          else
          {
            v17 = 0i64;
            v19 = v60;
          }
        }
        v41 = (unsigned int)(v41 + 1);
      }
      while ( (unsigned int)v41 < (unsigned __int8)v9->mNumOutgoingConnections );
    }
    v62 = FLOAT_3_4028235e38;
    v63 = 0i64;
    t = 0.0;
    if ( v20 )
    {
      v64 = v20;
      do
      {
        if ( *v17 )
          v65 = (char *)v17 + *v17;
        else
          v65 = 0i64;
        v66 = *(_QWORD *)v65;
        if ( *(_QWORD *)v65 )
          v66 += (__int64)v65;
        v67 = *(UFG::RoadNetworkConnection **)(v66 + 32);
        if ( v67 )
          v67 = (UFG::RoadNetworkConnection *)((char *)v67 + v66 + 32);
        v68 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v67,
                                             *((unsigned __int16 *)v65 + 19));
        UFG::qBezierPathMemImaged::ClosestPoint3D(v68, &resulta, v7, &t);
        v69 = resulta.y;
        v70 = resulta.z;
        v71 = (__m128)LODWORD(resulta.y);
        v71.m128_f32[0] = (float)((float)((float)(resulta.y - v7->y) * (float)(resulta.y - v7->y))
                                + (float)((float)(resulta.x - v7->x) * (float)(resulta.x - v7->x)))
                        + (float)((float)(resulta.z - v7->z) * (float)(resulta.z - v7->z));
        LODWORD(v72) = (unsigned __int128)_mm_sqrt_ps(v71);
        if ( v72 < v62 )
        {
          v6 = t;
          v8->x = resulta.x;
          v8->y = v69;
          v62 = v72;
          v63 = v65;
          v8->z = v70;
        }
        ++v17;
        --v64;
      }
      while ( v64 );
    }
    *v94 = v63;
  }
  else
  {
    v73 = FLOAT_3_4028235e38;
    v74 = 0i64;
    retaddr = 0.0;
    if ( this->mNumLanes )
    {
      do
      {
        v75 = v9->mLane.mOffset;
        if ( v75 )
          v76 = (signed __int64)&v9->mLane + v75;
        else
          v76 = 0i64;
        v77 = *(_QWORD *)(v76 + 8 * v74);
        if ( v77 )
          v78 = v77 + v76 + 8 * v74;
        else
          v78 = 0i64;
        v79 = *(_QWORD *)v78;
        if ( *(_QWORD *)v78 )
          v79 += v78;
        v80 = *(UFG::RoadNetworkConnection **)(v79 + 32);
        if ( v80 )
          v80 = (UFG::RoadNetworkConnection *)((char *)v80 + v79 + 32);
        v81 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v80,
                                             *(unsigned __int16 *)(v78 + 38));
        UFG::qBezierPathMemImaged::ClosestPoint3D(v81, &resulta, v7, &retaddr);
        v82 = resulta.y;
        v83 = resulta.z;
        v84 = (__m128)LODWORD(resulta.y);
        v84.m128_f32[0] = (float)((float)((float)(resulta.y - v7->y) * (float)(resulta.y - v7->y))
                                + (float)((float)(resulta.x - v7->x) * (float)(resulta.x - v7->x)))
                        + (float)((float)(resulta.z - v7->z) * (float)(resulta.z - v7->z));
        LODWORD(v85) = (unsigned __int128)_mm_sqrt_ps(v84);
        if ( v85 < v73 )
        {
          v6 = retaddr;
          v8->x = resulta.x;
          v8->y = v82;
          v73 = v85;
          v17 = (_QWORD *)v78;
          v8->z = v83;
        }
        v74 = (unsigned int)(v74 + 1);
      }
      while ( (unsigned int)v74 < (unsigned __int8)v9->mNumLanes );
    }
    *v94 = v17;
  }
  *v95 = v6;
  return v8;
}

// File Line: 695
// RVA: 0xD70B0
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetClosestPosition(UFG::RoadNetworkNode *this, UFG::qVector3 *result, UFG::qVector3 *pos, float *nearestT)
{
  float *v4; // rdi
  UFG::qVector3 *v5; // rbx
  UFG::qVector3 *v6; // rax
  float v7; // [rsp+48h] [rbp+10h]
  UFG::RoadNetworkLane *nearestLane; // [rsp+58h] [rbp+20h]

  v4 = nearestT;
  v5 = result;
  v7 = 0.0;
  UFG::RoadNetworkNode::GetNearestPos(this, result, pos, &nearestLane, &v7);
  v6 = v5;
  if ( v4 )
    *v4 = v7;
  return v6;
}

// File Line: 705
// RVA: 0xD69B0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkNode::GetClosestLane(UFG::RoadNetworkNode *this, UFG::qVector3 *pos)
{
  UFG::qVector3 result; // [rsp+30h] [rbp-18h]
  float nearestT; // [rsp+60h] [rbp+18h]
  UFG::RoadNetworkLane *nearestLane; // [rsp+68h] [rbp+20h]

  nearestLane = 0i64;
  UFG::RoadNetworkNode::GetNearestPos(this, &result, pos, &nearestLane, &nearestT);
  return nearestLane;
}

// File Line: 713
// RVA: 0xD81D0
float __fastcall UFG::RoadNetworkNode::GetClosestT(UFG::RoadNetworkNode *this, unsigned int laneIndex, UFG::qVector3 *position)
{
  __int64 v3; // r9
  UFG::RoadNetworkNode *v4; // rax
  UFG::RoadNetworkConnection *v5; // rcx
  UFG::qVector3 *v6; // rbx
  signed __int64 v7; // r9
  __int64 v8; // rax
  signed __int64 v9; // rdx
  __int64 v10; // rax
  signed __int64 v11; // rax
  signed __int64 v12; // rdx
  unsigned int v13; // er8
  __int64 v14; // rax
  UFG::qBezierPathMemImaged *v15; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]
  float t; // [rsp+48h] [rbp+10h]

  v3 = this->mLane.mOffset;
  v4 = this;
  v5 = 0i64;
  v6 = position;
  if ( v3 )
    v7 = (signed __int64)&v4->mLane + v3;
  else
    v7 = 0i64;
  v8 = laneIndex;
  v9 = v7 + 8 * v8;
  v10 = *(_QWORD *)(v7 + 8 * v8);
  if ( v10 )
    v11 = v9 + v10;
  else
    v11 = 0i64;
  t = 0.0;
  if ( *(_QWORD *)v11 )
    v12 = v11 + *(_QWORD *)v11;
  else
    v12 = 0i64;
  v13 = *(unsigned __int16 *)(v11 + 38);
  v14 = *(_QWORD *)(v12 + 32);
  if ( v14 )
    v5 = (UFG::RoadNetworkConnection *)(v14 + v12 + 32);
  v15 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v5, v13);
  UFG::qBezierPathMemImaged::ClosestPoint3D(v15, &result, v6, &t);
  return t;
}

// File Line: 749
// RVA: 0xD94E0
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkNode::GetLane(UFG::RoadNetworkNode *this, const unsigned int index)
{
  __int64 v2; // rax
  char *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rdx
  UFG::RoadNetworkLane *result; // rax

  v2 = this->mLane.mOffset;
  if ( v2 )
    v3 = (char *)&this->mLane + v2;
  else
    v3 = 0i64;
  v4 = index;
  v5 = (signed __int64)&v3[8 * v4];
  result = *(UFG::RoadNetworkLane **)&v3[8 * v4];
  if ( result )
    result = (UFG::RoadNetworkLane *)((char *)result + v5);
  return result;
}

// File Line: 762
// RVA: 0xDB470
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetPos(UFG::RoadNetworkNode *this, UFG::qVector3 *result, unsigned int laneIndex, float laneT)
{
  UFG::qVector3 *v4; // rbx
  __int64 v5; // rdx
  UFG::RoadNetworkNode *v6; // rax
  UFG::RoadNetworkLane *v7; // rcx
  signed __int64 v8; // r9
  __int64 v9; // rax

  v4 = result;
  v5 = this->mLane.mOffset;
  v6 = this;
  v7 = 0i64;
  if ( v5 )
    v8 = (signed __int64)&v6->mLane + v5;
  else
    v8 = 0i64;
  v9 = *(_QWORD *)(v8 + 8i64 * laneIndex);
  if ( v9 )
    v7 = (UFG::RoadNetworkLane *)(v9 + v8 + 8i64 * laneIndex);
  UFG::RoadNetworkLane::GetPos(v7, v4, laneT);
  return v4;
}

// File Line: 774
// RVA: 0xDC020
UFG::qVector3 *__fastcall UFG::RoadNetworkNode::GetTangent(UFG::RoadNetworkNode *this, UFG::qVector3 *result, unsigned int laneIndex, float laneT)
{
  __int64 v4; // rax
  UFG::RoadNetworkConnection *v5; // r9
  UFG::qVector3 *v6; // rdi
  char *v7; // r10
  __int64 v8; // rax
  signed __int64 v9; // rax
  unsigned int v10; // edx
  __int64 v11; // rax
  UFG::qBezierPathMemImaged *v12; // rax
  UFG::RoadNetworkConnection *v13; // rbx
  unsigned int v14; // eax
  UFG::qBezierSplineMemImaged *v15; // rax
  float splineT; // [rsp+50h] [rbp+18h]

  v4 = this->mLane.mOffset;
  v5 = 0i64;
  v6 = result;
  if ( v4 )
    v7 = (char *)&this->mLane + v4;
  else
    v7 = 0i64;
  v8 = *(_QWORD *)&v7[8 * laneIndex];
  if ( v8 )
    v9 = (signed __int64)&v7[8 * laneIndex + v8];
  else
    v9 = 0i64;
  v10 = *(unsigned __int16 *)(v9 + 38);
  v11 = this->mPathCollection.mOffset;
  if ( v11 )
    v5 = (UFG::RoadNetworkConnection *)((char *)&this->mPathCollection + v11);
  v12 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v5, v10);
  v13 = (UFG::RoadNetworkConnection *)v12;
  splineT = 0.0;
  v14 = UFG::qBezierPathMemImaged::GetSplineParameters(v12, laneT, &splineT);
  v15 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v13, v14);
  UFG::qBezierSplineMemImaged::GetTangent(v15, v6, splineT);
  return v6;
}

// File Line: 786
// RVA: 0xDC930
void __fastcall UFG::RoadNetworkNode::Init(UFG::RoadNetworkNode *this)
{
  UFG::RoadNetworkNode *v1; // rsi
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0> *v2; // r15
  char *v3; // r14
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  bool v7; // zf
  unsigned int v8; // ecx
  __int64 v9; // rax
  signed __int64 v10; // rdx
  _QWORD *v11; // rax
  char *v12; // rax
  char *v13; // rax
  char *v14; // rbx
  void *v15; // rcx
  __int64 v16; // rbp
  unsigned __int64 v17; // rax
  __int64 v18; // rdx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v19; // rax
  unsigned int v20; // ecx
  __int64 v21; // rax
  signed __int64 v22; // rdx
  _QWORD *v23; // r8
  char *v24; // rax
  _QWORD *v25; // rax

  v1 = this;
  v2 = &this->mModifications;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v3 = 0i64;
  v4 = (unsigned __int8)this->mNumLanes;
  if ( (signed int)v4 <= 0 )
  {
    v7 = v4 == 0;
    v4 = 0;
    if ( !v7 )
      v4 = 0;
  }
  else
  {
    v5 = 1;
    if ( v4 <= 1 )
      goto LABEL_47;
    do
      v5 *= 2;
    while ( v5 < v4 );
    if ( v5 <= 4 )
LABEL_47:
      v5 = 4;
    if ( v5 - v4 > 0x10000 )
      v5 = v4 + 0x10000;
    if ( v5 )
    {
      v6 = 4i64 * v5;
      if ( !is_mul_ok(v5, 4ui64) )
        v6 = -1i64;
      v3 = UFG::qMalloc(v6, "RoadNetworkNode", 0i64);
    }
  }
  v8 = 0;
  if ( v1->mNumLanes > 0u )
  {
    do
    {
      v9 = v1->mLane.mOffset;
      if ( v9 )
        v10 = (signed __int64)&v1->mLane + v9;
      else
        v10 = 0i64;
      v11 = (_QWORD *)(v10 + 8i64 * v8);
      if ( *v11 )
        v12 = (char *)v11 + *v11;
      else
        v12 = 0i64;
      *(_DWORD *)&v3[4 * v8++] = (unsigned __int8)v12[44];
    }
    while ( v8 < (unsigned __int8)v1->mNumLanes );
  }
  v13 = UFG::qMalloc(0x28ui64, "RoadNetworkNode.RoadNetworkNodeModification", 0i64);
  v14 = v13;
  if ( v13 )
  {
    *(_QWORD *)v13 = v13;
    *((_QWORD *)v13 + 1) = v13;
    *((_QWORD *)v13 + 3) = 0i64;
    *((_QWORD *)v13 + 2) = 0i64;
    *((_QWORD *)v13 + 4) = v1;
    v15 = (void *)*((_QWORD *)v13 + 3);
    if ( v15 )
      operator delete[](v15);
    *((_QWORD *)v14 + 3) = 0i64;
    *((_QWORD *)v14 + 2) = 0i64;
    if ( v4 )
    {
      *((_DWORD *)v14 + 4) = v4;
      v16 = v4;
      v17 = 4i64 * v4;
      if ( !is_mul_ok(v4, 4ui64) )
        v17 = -1i64;
      *((_QWORD *)v14 + 3) = UFG::qMalloc(v17, "qArray.Clone", 0i64);
      *((_DWORD *)v14 + 5) = v4;
      if ( v4 )
      {
        v18 = 0i64;
        do
        {
          *(_DWORD *)(v18 + *((_QWORD *)v14 + 3)) = *(_DWORD *)&v3[v18];
          v18 += 4i64;
          --v16;
        }
        while ( v16 );
      }
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
  v19 = v2->mNode.mPrev;
  v19->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v14;
  *(_QWORD *)v14 = v19;
  *((_QWORD *)v14 + 1) = v2;
  v2->mNode.mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v14;
  v20 = 0;
  if ( v1->mNumLanes > 0u )
  {
    do
    {
      v21 = v1->mLane.mOffset;
      if ( v21 )
        v22 = (signed __int64)&v1->mLane + v21;
      else
        v22 = 0i64;
      v23 = (_QWORD *)(v22 + 8i64 * v20);
      if ( *v23 )
        v24 = (char *)v23 + *v23;
      else
        v24 = 0i64;
      v25 = v24 + 112;
      *v25 = v25;
      v25[1] = v25;
      ++v20;
    }
    while ( v20 < (unsigned __int8)v1->mNumLanes );
  }
  if ( v3 )
    operator delete[](v3);
}

// File Line: 898
// RVA: 0xDEF20
char __fastcall UFG::RoadNetworkNode::IsWater(UFG::RoadNetworkNode *this)
{
  UFG::qPropertySet *v2; // rax
  unsigned int v3; // ebx
  unsigned int *v4; // rax

  if ( this->mType.mValue == 1 )
    return UFG::RoadNetworkIntersection::IsWater((UFG::RoadNetworkIntersection *)this);
  if ( *(_QWORD *)&this[1].mDataHash )
    return (unsigned int)(*(_DWORD *)&this[1].mNumLanes - 2) <= 1;
  v2 = UFG::RoadNetworkSegment::GetRoadPropertySet((UFG::RoadNetworkSegment *)this);
  v3 = 0;
  if ( v2 )
  {
    v4 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID, DEPTH_RECURSE);
    if ( v4 )
      v3 = *v4;
  }
  return v3 - 2 <= 1;
}

// File Line: 911
// RVA: 0xDE3D0
char __fastcall UFG::RoadNetworkNode::IsConnectedToNode(UFG::RoadNetworkNode *this, UFG::RoadNetworkNode *roadNode)
{
  unsigned int v2; // er11
  unsigned int v3; // er8
  __int64 v4; // r10
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *v5; // rbx
  __int64 v6; // r9
  char *v7; // rax
  char *v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rcx
  UFG::RoadNetworkNode *v11; // rax

  v2 = (unsigned __int8)this->mNumGates;
  v3 = 0;
  if ( !this->mNumGates )
    return 0;
  v4 = this->mGates.mOffset;
  v5 = &this->mGates;
  v6 = 0i64;
  while ( 1 )
  {
    if ( v4 )
      v7 = (char *)v5 + v4;
    else
      v7 = 0i64;
    v8 = &v7[v6];
    v9 = *(_QWORD *)&v7[v6];
    if ( v9 )
      v9 += (__int64)v8;
    v10 = *(_QWORD *)(v9 + 8);
    v11 = (UFG::RoadNetworkNode *)(v10 ? v10 + v9 + 8 : 0i64);
    if ( v11 == roadNode )
      break;
    ++v3;
    v6 += 8i64;
    if ( v3 >= v2 )
      return 0;
  }
  return 1;
}

// File Line: 945
// RVA: 0xDB7A0
__int64 __fastcall UFG::RoadNetworkIntersection::GetRoadNetworkType(UFG::RoadNetworkIntersection *this)
{
  unsigned int v1; // er10
  unsigned int v2; // ebx
  unsigned int v3; // edx
  __int64 v4; // r9
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *v5; // r11
  __int64 v6; // r8
  char *v7; // rax
  char *v8; // rcx
  __int64 v9; // rax
  char *v10; // rax
  __int64 v11; // rcx
  UFG::RoadNetworkSegment *v12; // rcx
  UFG::qPropertySet *v14; // rax
  unsigned int *v15; // rax

  v1 = (unsigned __int8)this->mNumGates;
  v2 = 0;
  v3 = 0;
  if ( this->mNumGates )
  {
    v4 = this->mGates.mOffset;
    v5 = &this->mGates;
    v6 = 0i64;
    while ( 1 )
    {
      v7 = (char *)v5 + v4;
      if ( !v4 )
        v7 = 0i64;
      v8 = &v7[v6];
      v9 = *(_QWORD *)&v7[v6];
      v10 = v9 ? &v8[v9] : 0i64;
      v11 = *((_QWORD *)v10 + 1);
      if ( v11 )
      {
        v12 = (UFG::RoadNetworkSegment *)&v10[v11 + 8];
        if ( v12 )
          break;
      }
      ++v3;
      v6 += 8i64;
      if ( v3 >= v1 )
        return 0i64;
    }
    if ( v12->mpPropertySetCached )
      return v12->mRoadNetworkType.mValue;
    v14 = UFG::RoadNetworkSegment::GetRoadPropertySet(v12);
    if ( v14 )
    {
      v15 = UFG::qPropertySet::Get<unsigned long>(v14, (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID, DEPTH_RECURSE);
      if ( v15 )
        v2 = *v15;
    }
  }
  return v2;
}

// File Line: 989
// RVA: 0xD1740
UFG::RoadNetworkNodeModification *__fastcall UFG::RoadNetworkNode::AddChangeLaneFlagsModification(UFG::RoadNetworkNode *this, UFG::qArray<unsigned long,0> *laneFlags)
{
  UFG::qArray<unsigned long,0> *v2; // rbp
  UFG::RoadNetworkNode *v3; // rsi
  char *v4; // rax
  char *v5; // rbx
  _QWORD *v6; // rdx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v7; // rax
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *i; // rax
  __int64 v9; // r8
  __int64 v10; // rax
  signed __int64 v11; // rcx
  _QWORD *v12; // rax
  char *v13; // rax

  v2 = laneFlags;
  v3 = this;
  v4 = UFG::qMalloc(0x28ui64, "RoadNetworkNode.RoadNetworkNodeModification", 0i64);
  v5 = v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    v6 = v4 + 16;
    v6[1] = 0i64;
    *v6 = 0i64;
    *((_QWORD *)v4 + 4) = v3;
    UFG::qArray<enum  DNA::PropertyState::Enum,0>::Clone(v2, (UFG::qArray<unsigned long,0> *)v4 + 1);
  }
  else
  {
    v5 = 0i64;
  }
  v7 = v3->mModifications.mNode.mPrev;
  v7->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5;
  *(_QWORD *)v5 = v7;
  *((_QWORD *)v5 + 1) = (char *)v3 + 80;
  v3->mModifications.mNode.mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5;
  for ( i = v3->mModifications.mNode.mNext;
        i != (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&v3->mModifications;
        i = i->mNext )
  {
    if ( i == (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5 )
      break;
  }
  if ( *((_DWORD *)v5 + 4) )
  {
    v9 = 0i64;
    if ( v3->mNumLanes )
    {
      do
      {
        v10 = v3->mLane.mOffset;
        if ( v10 )
          v11 = (signed __int64)&v3->mLane + v10;
        else
          v11 = 0i64;
        v12 = (_QWORD *)(v11 + 8 * v9);
        if ( *v12 )
          v13 = (char *)v12 + *v12;
        else
          v13 = 0i64;
        v13[44] = *(_BYTE *)(*((_QWORD *)v5 + 3) + 4 * v9);
        v9 = (unsigned int)(v9 + 1);
      }
      while ( (unsigned int)v9 < (unsigned __int8)v3->mNumLanes );
    }
  }
  return (UFG::RoadNetworkNodeModification *)v5;
}

// File Line: 999
// RVA: 0xE0000
void __fastcall UFG::RoadNetworkNode::RemoveModification(UFG::RoadNetworkNode *this, UFG::RoadNetworkNodeModification *modification)
{
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v2; // r8
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v3; // rax

  v2 = modification->mPrev;
  v3 = modification->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  modification->mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&modification->mPrev;
  modification->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&modification->mPrev;
  UFG::RoadNetworkNode::ApplyAllModifications(this);
}

// File Line: 1006
// RVA: 0xD2370
void __fastcall UFG::RoadNetworkNode::ApplyAllModifications(UFG::RoadNetworkNode *this)
{
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v1; // r10
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0> *v2; // rbx
  UFG::RoadNetworkNode *v3; // r11
  __int64 v4; // r8
  __int64 v5; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // rax
  __int64 v8; // rcx
  signed __int64 v9; // rdx
  char v10; // cl

  v1 = this->mModifications.mNode.mNext;
  v2 = &this->mModifications;
  v3 = this;
  if ( v1 != (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&this->mModifications )
  {
    do
    {
      if ( LODWORD(v1[1].mPrev) )
      {
        v4 = 0i64;
        if ( v3->mNumLanes )
        {
          do
          {
            v5 = v3->mLane.mOffset;
            if ( v5 )
              v6 = (signed __int64)&v3->mLane + v5;
            else
              v6 = 0i64;
            v7 = v6 + 8 * v4;
            v8 = *(_QWORD *)(v6 + 8 * v4);
            if ( v8 )
              v9 = v8 + v7;
            else
              v9 = 0i64;
            v10 = *((_BYTE *)&v1[1].mNext->mPrev + 4 * v4);
            v4 = (unsigned int)(v4 + 1);
            *(_BYTE *)(v9 + 44) = v10;
          }
          while ( (unsigned int)v4 < (unsigned __int8)v3->mNumLanes );
        }
      }
      v1 = v1->mNext;
    }
    while ( v1 != (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v2 );
  }
}

// File Line: 1030
// RVA: 0xD0F30
void __fastcall UFG::RoadNetworkSegment::~RoadNetworkSegment(UFG::RoadNetworkSegment *this)
{
  UFG::RoadNetworkSegment *v1; // rsi
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *v2; // rdi
  UFG::RoadNetworkSubSegment *v3; // rbx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v4; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v5; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v6; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v7; // rax
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v8; // rcx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v9; // rax

  v1 = this;
  v2 = &this->mSubSegmentCollection;
  v3 = (UFG::RoadNetworkSubSegment *)this->mSubSegmentCollection.mNode.mNext;
  if ( v3 != (UFG::RoadNetworkSubSegment *)&this->mSubSegmentCollection )
  {
    do
    {
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v3->mPrev;
      UFG::RoadNetworkSubSegment::~RoadNetworkSubSegment(v3);
      operator delete[](v3);
      v3 = (UFG::RoadNetworkSubSegment *)v2->mNode.mNext;
    }
    while ( v3 != (UFG::RoadNetworkSubSegment *)v2 );
  }
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0>::DeleteNodes(&v1->mModifications);
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0>::DeleteNodes(v2);
  v6 = v2->mNode.mPrev;
  v7 = v2->mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0>::DeleteNodes(&v1->mModifications);
  v8 = v1->mModifications.mNode.mPrev;
  v9 = v1->mModifications.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v1->mModifications.mNode.mPrev = &v1->mModifications.mNode;
  v1->mModifications.mNode.mNext = &v1->mModifications.mNode;
}

// File Line: 1335
// RVA: 0xE0200
void __fastcall UFG::RoadNetworkSegment::SetBitsFromRoadPropertySet(UFG::RoadNetworkSegment *this)
{
  UFG::RoadNetworkSegment *v1; // rbx
  UFG::qPropertySet *v2; // rax
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
  UFG::qPropertySet *v20; // rax
  bool *v21; // rax
  char *v22; // rcx
  char v23; // [rsp+38h] [rbp+10h]

  v1 = this;
  v2 = UFG::RoadNetworkSegment::GetRoadPropertySet(this);
  v3 = v2;
  if ( v2 )
  {
    v23 = 0;
    v4 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_WayFinderNoPlayer.mUID, DEPTH_RECURSE);
    v5 = &v23;
    if ( v4 )
      v5 = (char *)v4;
    v6 = (unsigned __int8)*v5;
    v23 = 0;
    *(_DWORD *)&v1->mBits ^= (*(_DWORD *)&v1->mBits ^ v6) & 1;
    v7 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_WayFinderNoVehicle.mUID, DEPTH_RECURSE);
    v8 = &v23;
    if ( v7 )
      v8 = (char *)v7;
    v9 = (unsigned __int8)*v8;
    v23 = 0;
    *(_DWORD *)&v1->mBits ^= (*(_DWORD *)&v1->mBits ^ 2 * v9) & 2;
    v10 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_GpsRestricted.mUID, DEPTH_RECURSE);
    v11 = &v23;
    if ( v10 )
      v11 = (char *)v10;
    v12 = (unsigned __int8)*v11;
    v23 = 0;
    *(_DWORD *)&v1->mBits ^= (*(_DWORD *)&v1->mBits ^ 4 * v12) & 4;
    v13 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_WayFinderGPSOnly.mUID, DEPTH_RECURSE);
    v14 = &v23;
    if ( v13 )
      v14 = (char *)v13;
    *(_DWORD *)&v1->mBits ^= (*(_DWORD *)&v1->mBits ^ 8 * (unsigned __int8)*v14) & 8;
    v15 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_RoadDriveableTraffic.mUID, DEPTH_RECURSE);
    v16 = v15 && !*v15;
    *(_DWORD *)&v1->mBits &= 0xFFFFFFEF;
    *(_DWORD *)&v1->mBits |= 16 * v16;
    v23 = 0;
    v17 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_ExtendBeyondVisibleAreaLimit.mUID, DEPTH_RECURSE);
    v18 = &v23;
    if ( v17 )
      v18 = (char *)v17;
    *(_DWORD *)&v1->mBits ^= (*(_DWORD *)&v1->mBits ^ ((unsigned __int8)*v18 << 6)) & 0x40;
    v19 = UFG::qPropertySet::Get<unsigned long>(v3, (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID, DEPTH_RECURSE);
    if ( v19 )
      v1->mRoadNetworkType.mValue = *v19;
  }
  v20 = UFG::RoadNetworkSegment::GetAdditionalRoadPropertySet(v1);
  if ( v20 )
  {
    v23 = 0;
    v21 = UFG::qPropertySet::Get<bool>(v20, (UFG::qSymbol *)&qSymbol_BuildVisibleRoadNetworkByGrid.mUID, DEPTH_RECURSE);
    v22 = &v23;
    if ( v21 )
      v22 = (char *)v21;
    *(_DWORD *)&v1->mBits ^= (*(_DWORD *)&v1->mBits ^ 32 * (unsigned __int8)*v22) & 0x20;
  }
}

// File Line: 1366
// RVA: 0x1460A30
__int64 dynamic_initializer_for__gRoadSetPropertySetName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-roadnetwork-roadset", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gRoadSetPropertySetName, v0);
  return atexit(dynamic_atexit_destructor_for__gRoadSetPropertySetName__);
}

// File Line: 1370
// RVA: 0xDB8A0
UFG::qPropertySet *__fastcall UFG::RoadNetworkSegment::GetRoadPropertySet(UFG::RoadNetworkSegment *this)
{
  UFG::qPropertySet *result; // rax
  UFG::RoadNetworkSegment *v2; // rbp
  UFG::qPropertySet *v3; // rax
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // r14
  unsigned int v6; // esi
  unsigned int v7; // ebx
  UFG::qSymbol *v8; // rax
  UFG::qPropertySet *v9; // rax
  UFG::qPropertySet *v10; // rdi

  result = this->mpPropertySetCached;
  v2 = this;
  if ( !result )
  {
    v3 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&gRoadSetPropertySetName.mUID);
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&qSymbol_RoadSet.mUID, DEPTH_RECURSE);
    v5 = v4;
    if ( v4 && (v6 = v4->mNumElements, v7 = 0, v6) )
    {
      while ( 1 )
      {
        v8 = UFG::qPropertyList::Get<UFG::qSymbol>(v5, v7);
        v9 = UFG::PropertySetManager::GetPropertySet(v8);
        v10 = v9;
        if ( v9 )
        {
          if ( v2->mPropertyID1 == *UFG::qPropertySet::Get<unsigned long>(
                                      v9,
                                      (UFG::qSymbol *)&qSymbol_RoadID.mUID,
                                      DEPTH_RECURSE) )
            break;
        }
        if ( ++v7 >= v6 )
          goto LABEL_7;
      }
      if ( v10->mFlags & 1 )
        v2->mpPropertySetCached = v10;
      result = v10;
    }
    else
    {
LABEL_7:
      result = 0i64;
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
  return atexit(dynamic_atexit_destructor_for__gRoadSetPropertySetNameAdditional__);
}

// File Line: 1414
// RVA: 0xD5950
UFG::qPropertySet *__fastcall UFG::RoadNetworkSegment::GetAdditionalRoadPropertySet(UFG::RoadNetworkSegment *this)
{
  UFG::RoadNetworkSegment *v1; // r14
  UFG::qPropertySet *v2; // rax
  UFG::qPropertyList *v3; // rax
  UFG::qPropertyList *v4; // rbp
  unsigned int v5; // esi
  unsigned int v6; // ebx
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::qPropertySet *v9; // rdi

  v1 = this;
  v2 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&gRoadSetPropertySetNameAdditional.mUID);
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&qSymbol_RoadSet.mUID, DEPTH_RECURSE);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  v5 = v3->mNumElements;
  v6 = 0;
  if ( !v5 )
    return 0i64;
  while ( 1 )
  {
    v7 = UFG::qPropertyList::Get<UFG::qSymbol>(v4, v6);
    v8 = UFG::PropertySetManager::GetPropertySet(v7);
    v9 = v8;
    if ( v8 )
    {
      if ( v1->mPropertyID2 == *UFG::qPropertySet::Get<unsigned long>(
                                  v8,
                                  (UFG::qSymbol *)&qSymbol_RoadIDAdditional.mUID,
                                  DEPTH_RECURSE) )
        break;
    }
    if ( ++v6 >= v5 )
      return 0i64;
  }
  return v9;
}

// File Line: 1449
// RVA: 0xDB6B0
float __fastcall UFG::RoadNetworkSegment::GetRoadDensity(UFG::RoadNetworkSegment *this)
{
  float v1; // xmm6_4
  UFG::qPropertySet *v2; // rbx
  float v3; // xmm7_4
  float *v4; // rax
  float v5; // xmm0_4

  v1 = FLOAT_0_0123;
  v2 = UFG::RoadNetworkSegment::GetRoadPropertySet(this);
  if ( v2 )
  {
    if ( ((v3 = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight,
           UFG::TimeOfDayManager::GetInstance(),
           v3 >= 75600.0)
       || (UFG::TimeOfDayManager::GetInstance(), v3 <= 21600.0))
      && (v4 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_DensityNight.mUID, DEPTH_RECURSE)) != 0i64
      || (v4 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&qSymbol_Density.mUID, DEPTH_RECURSE)) != 0i64 )
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
  UFG::qPropertySet *v2; // rax
  unsigned int v3; // ebx
  unsigned int *v4; // rax

  if ( this->mpPropertySetCached )
    return this->mRoadNetworkType.mValue;
  v2 = UFG::RoadNetworkSegment::GetRoadPropertySet(this);
  v3 = 0;
  if ( v2 )
  {
    v4 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID, DEPTH_RECURSE);
    if ( v4 )
      v3 = *v4;
  }
  return v3;
}

// File Line: 1505
// RVA: 0xDEFA0
bool __fastcall UFG::RoadNetworkSegment::IsWater(UFG::RoadNetworkSegment *this)
{
  UFG::qPropertySet *v2; // rax
  unsigned int v3; // ebx
  unsigned int *v4; // rax

  if ( this->mpPropertySetCached )
    return this->mRoadNetworkType.mValue - 2 <= 1;
  v2 = UFG::RoadNetworkSegment::GetRoadPropertySet(this);
  v3 = 0;
  if ( v2 )
  {
    v4 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID, DEPTH_RECURSE);
    if ( v4 )
      v3 = *v4;
  }
  return v3 - 2 <= 1;
}

// File Line: 1514
// RVA: 0xD1CC0
void __fastcall UFG::RoadNetworkSegment::AddParkingSpot(UFG::RoadNetworkSegment *this, UFG::ParkingSpot *spot)
{
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v2; // r8
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *v3; // rbx
  UFG::ParkingSpot *v4; // rsi
  UFG::RoadNetworkSegment *v5; // r11
  __int64 v6; // r10
  float v7; // xmm0_4
  __int64 v8; // rdi
  signed __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax
  signed __int64 v12; // rdx
  __int64 v13; // rcx
  float v14; // xmm1_4
  float v15; // xmm2_4
  __int64 v16; // rax
  signed __int64 v17; // r9
  __int64 v18; // rax
  __int64 v19; // rcx
  signed __int64 v20; // rax
  __int64 v21; // rcx
  __int64 v22; // rax
  bool v23; // cf
  bool v24; // zf
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v25; // rax
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v26; // rcx

  v2 = this->mSubSegmentCollection.mNode.mNext;
  v3 = &this->mSubSegmentCollection;
  v4 = spot;
  v5 = this;
  if ( v2 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&this->mSubSegmentCollection )
  {
    v6 = this->mLane.mOffset;
    v7 = spot->mClosestT;
    v8 = spot->mClosestLaneIndex;
    do
    {
      if ( v6 )
        v9 = (signed __int64)&v5->mLane + v6;
      else
        v9 = 0i64;
      v10 = v9 + 8 * v8;
      v11 = *(_QWORD *)(v9 + 8 * v8);
      if ( v11 )
        v12 = v11 + v10;
      else
        v12 = 0i64;
      v13 = *(unsigned __int16 *)(v12 + 36);
      v14 = *((float *)&v2[5].mPrev->mPrev + v13);
      v15 = *((float *)&v2[5].mNext->mPrev + v13);
      v16 = *(_QWORD *)(v12 + 8);
      if ( v16 )
        v17 = v16 + v12 + 8;
      else
        v17 = 0i64;
      v18 = *(_QWORD *)v12;
      if ( *(_QWORD *)v12 )
        v18 += v12;
      v19 = *(_QWORD *)(v18 + 48);
      if ( v19 )
        v20 = v19 + v18 + 48;
      else
        v20 = 0i64;
      v21 = *(_QWORD *)v20;
      if ( *(_QWORD *)v20 )
        v21 += v20;
      v22 = *(_QWORD *)(v21 + 8);
      if ( v22 )
        v22 += v21 + 8;
      if ( v17 == v22 )
      {
        if ( v7 < v14 )
          goto LABEL_27;
        v23 = v7 < v15;
        v24 = v7 == v15;
      }
      else
      {
        if ( v7 < v15 )
          goto LABEL_27;
        v23 = v7 < v14;
        v24 = v7 == v14;
      }
      if ( v23 || v24 )
      {
        v25 = v2[6].mNext;
        v26 = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&v4->mPrev;
        v25->mNext = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v4->mPrev;
        v26->mPrev = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)v25;
        v26->mNext = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&v2[6].mNext;
        v2[6].mNext = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v4->mPrev;
        ++LOWORD(v2[6].mPrev);
        return;
      }
LABEL_27:
      v2 = v2->mNext;
    }
    while ( v2 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v3 );
  }
}

// File Line: 1531
// RVA: 0xD5CB0
void __fastcall UFG::RoadNetworkSubSegment::GetAvailableParkingSpots(UFG::RoadNetworkSubSegment *this, UFG::qArray<UFG::ParkingSpot *,0> *availableParkingSpots)
{
  UFG::RoadNetworkSubSegment *v2; // rbx
  UFG::ParkingSpot **v3; // rcx
  UFG::qArray<UFG::ParkingSpot *,0> *v4; // rdi
  signed __int64 v5; // r12
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v6; // r14
  __int64 v7; // r15
  unsigned int v8; // ebx
  unsigned int v9; // esi
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  char *v12; // rax
  char *v13; // rbp
  signed __int64 v14; // r9
  signed __int64 v15; // r8
  UFG::ParkingSpot **v16; // rax

  v2 = this;
  v3 = availableParkingSpots->p;
  v4 = availableParkingSpots;
  if ( v3 )
    operator delete[](v3);
  v4->p = 0i64;
  *(_QWORD *)&v4->size = 0i64;
  v5 = (signed __int64)&v2[-1].mPosition.z;
  v6 = v2->mParkingSpotCollection.mNode.mNext - 12;
  if ( v6 != (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&v2[-1].mPosition.z )
  {
    do
    {
      if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *))v6->mPrev[9].mPrev)(v6) )
      {
        v7 = v4->size;
        v8 = v4->capacity;
        v9 = v7 + 1;
        if ( (signed int)v7 + 1 > v8 )
        {
          if ( v8 )
            v10 = 2 * v8;
          else
            v10 = 1;
          for ( ; v10 < v9; v10 *= 2 )
            ;
          if ( v10 <= 2 )
            v10 = 2;
          if ( v10 - v9 > 0x10000 )
            v10 = v7 + 65537;
          if ( v10 != (_DWORD)v7 )
          {
            v11 = 8i64 * v10;
            if ( !is_mul_ok(v10, 8ui64) )
              v11 = -1i64;
            v12 = UFG::qMalloc(v11, "qArray.Add", 0i64);
            v13 = v12;
            if ( v4->p )
            {
              v14 = 0i64;
              if ( v4->size )
              {
                do
                {
                  v15 = v14;
                  v14 = (unsigned int)(v14 + 1);
                  *(_QWORD *)&v12[v15 * 8] = v4->p[v15];
                }
                while ( (unsigned int)v14 < v4->size );
              }
              operator delete[](v4->p);
            }
            v4->p = (UFG::ParkingSpot **)v13;
            v4->capacity = v10;
          }
        }
        v16 = v4->p;
        v4->size = v9;
        v16[v7] = (UFG::ParkingSpot *)v6;
      }
      v6 = v6[12].mNext - 12;
    }
    while ( v6 != (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)v5 );
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
  __int64 v2; // rax
  __int64 v3; // r15
  char *v4; // rdx
  __int64 v5; // rax
  signed __int64 v6; // rsi
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v7; // rbp
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *v8; // r12
  signed __int64 i; // rdi
  __int64 v10; // rbx
  float v11; // xmm0_4
  float v12; // xmm1_4

  v2 = this->mLane.mOffset;
  v3 = laneIndex;
  if ( v2 )
    v4 = (char *)&this->mLane + v2;
  else
    v4 = 0i64;
  v5 = *(_QWORD *)&v4[8 * v3];
  if ( v5 )
    v6 = (signed __int64)&v4[8 * v3 + v5];
  else
    v6 = 0i64;
  v7 = this->mSubSegmentCollection.mNode.mNext;
  v8 = &this->mSubSegmentCollection;
  *(_DWORD *)(v6 + 40) = 0;
  if ( v7 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&this->mSubSegmentCollection )
  {
    do
    {
      for ( i = (signed __int64)&v7[7].mPrev[-12];
            (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> **)i != &v7[-6].mNext;
            i = *(_QWORD *)(i + 200) - 192i64 )
      {
        if ( (_DWORD)v3 == *(unsigned __int16 *)(i + 136) )
        {
          v10 = *(_QWORD *)(i + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(i + 104));
          v11 = UFG::RoadNetworkLane::CalculateParkingOffset((UFG::RoadNetworkLane *)v6, (UFG::qVector3 *)(v10 + 176));
          v12 = *(float *)(v6 + 40);
          if ( v12 <= v11 )
            v12 = v11;
          *(float *)(v6 + 40) = v12;
        }
      }
      v7 = v7->mNext;
    }
    while ( v7 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v8 );
  }
}

// File Line: 1583
// RVA: 0xD3F00
void __fastcall UFG::RoadNetworkSegment::CreateSubSegments(UFG::RoadNetworkSegment *this)
{
  UFG::RoadNetworkSegment *v1; // rsi
  __int64 v2; // rax
  __int64 v3; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v4; // rbx
  signed __int64 v5; // rcx
  _QWORD *v6; // rdx
  char *v7; // rax
  char *v8; // rcx
  unsigned int v9; // edx
  __int64 v10; // rax
  UFG::RoadNetworkConnection *v11; // rcx
  __int128 v12; // xmm7
  char *v13; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v14; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v15; // rax
  float v16; // xmm7_4
  char *v17; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v18; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v19; // rcx
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *v20; // rdi
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v21; // rax
  char *v22; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v23; // rax
  float v24; // xmm9_4
  float v25; // xmm8_4
  float v26; // xmm6_4
  char *v27; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v28; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v29; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v30; // rax
  signed int v31; // ebp
  float v32; // xmm10_4
  unsigned int v33; // er14
  float v34; // xmm10_4
  unsigned int v35; // er15
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

  v1 = this;
  v2 = ((unsigned __int8)this->mNumLanes - 1) / 2;
  v3 = this->mLane.mOffset;
  v4 = 0i64;
  if ( v3 )
    v5 = (signed __int64)&v1->mLane + v3;
  else
    v5 = 0i64;
  v6 = (_QWORD *)(v5 + 8 * v2);
  if ( *v6 )
    v7 = (char *)v6 + *v6;
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
  v12 = HIDWORD(UFG::qBezierPathCollectionMemImaged::GetPath(v11, v9)->mNode.mOffset);
  if ( *(float *)&v12 >= 30.0 )
  {
    if ( *(float *)&v12 >= 45.0 )
    {
      v24 = 1.0 / *(float *)&v12;
      v25 = (float)(1.0 / *(float *)&v12) * 15.0;
      v26 = (float)(1.0 / *(float *)&v12) * 15.0;
      v27 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v27 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v27, v1, 15.0, 0.0);
        v29 = v28;
      }
      else
      {
        v29 = 0i64;
      }
      v20 = &v1->mSubSegmentCollection;
      v30 = v1->mSubSegmentCollection.mNode.mPrev;
      v30->mNext = v29;
      v29->mPrev = v30;
      v29->mNext = &v1->mSubSegmentCollection.mNode;
      v1->mSubSegmentCollection.mNode.mPrev = v29;
      v31 = 1;
      v32 = (float)(*(float *)&v12 - 30.0) * 0.025;
      v33 = (signed int)v32;
      v34 = (float)(v32 - (float)(signed int)v32) * 40.0;
      v35 = 0;
      if ( v34 < 15.0 )
      {
        v26 = v25 * 2.0;
        v36 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
        if ( v36 )
        {
          UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v36, v1, 15.0, v25);
          v38 = v37;
        }
        else
        {
          v38 = 0i64;
        }
        v39 = v20->mNode.mPrev;
        v39->mNext = v38;
        v38->mPrev = v39;
        v38->mNext = &v20->mNode;
        v20->mNode.mPrev = v38;
        v31 = 2;
        v25 = v25 * 2.0;
        v34 = 40.0 - (float)(15.0 - v34);
        v35 = 1;
      }
      v40 = v26 + (float)(v24 * v34);
      v41 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v41 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v41, v1, v34, v25);
        v43 = v42;
      }
      else
      {
        v43 = 0i64;
      }
      v44 = v20->mNode.mPrev;
      v44->mNext = v43;
      v43->mPrev = v44;
      v43->mNext = &v20->mNode;
      v20->mNode.mPrev = v43;
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
            UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v49, v1, 40.0, v46);
            v51 = v50;
          }
          else
          {
            v51 = 0i64;
          }
          v52 = v20->mNode.mPrev;
          v52->mNext = v51;
          v51->mPrev = v52;
          v51->mNext = &v20->mNode;
          v20->mNode.mPrev = v51;
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
          v1,
          (float)(1.0 - v40) * *(float *)&v12,
          v40);
        v4 = v54;
      }
    }
    else
    {
      v16 = *(float *)&v12 * 0.5;
      v17 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v17 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v17, v1, v16, 0.0);
        v19 = v18;
      }
      else
      {
        v19 = 0i64;
      }
      v20 = &v1->mSubSegmentCollection;
      v21 = v1->mSubSegmentCollection.mNode.mPrev;
      v21->mNext = v19;
      v19->mPrev = v21;
      v19->mNext = &v1->mSubSegmentCollection.mNode;
      v1->mSubSegmentCollection.mNode.mPrev = v19;
      v22 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
      if ( v22 )
      {
        UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v22, v1, v16, 0.5);
        v4 = v23;
      }
    }
    v55 = v20->mNode.mPrev;
    v55->mNext = v4;
    v4->mPrev = v55;
    v4->mNext = &v20->mNode;
    v20->mNode.mPrev = v4;
  }
  else
  {
    v13 = UFG::qMalloc(0x78ui64, "RoadNetworkSubSegment", 0i64);
    if ( v13 )
    {
      UFG::RoadNetworkSubSegment::RoadNetworkSubSegment((UFG::RoadNetworkSubSegment *)v13, v1, *(float *)&v12, 0.0);
      v4 = v14;
    }
    v15 = v1->mSubSegmentCollection.mNode.mPrev;
    v15->mNext = v4;
    v4->mPrev = v15;
    v4->mNext = &v1->mSubSegmentCollection.mNode;
    v1->mSubSegmentCollection.mNode.mPrev = v4;
  }
}

// File Line: 1735
// RVA: 0xD9F20
int UFG::RoadNetworkSegment::GetMatchingT(...)
{
  __int64 v4; // r14
  UFG::RoadNetworkSegment *v5; // rdi
  __int64 v6; // rax
  char *v7; // rcx
  __int64 v8; // rax
  signed __int64 v9; // rdx
  __int64 v10; // rax
  signed __int64 v11; // rsi
  signed __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // r8
  signed __int64 v15; // rdx
  __int64 v16; // rax
  signed __int64 v17; // r8
  unsigned int v18; // edx
  __int64 v19; // rax
  UFG::RoadNetworkConnection *v20; // rcx
  UFG::qBezierPathMemImaged *v21; // rax
  float v22; // xmm7_4
  UFG::RoadNetworkConnection *v23; // rbx
  unsigned int v24; // eax
  UFG::qBezierSplineMemImaged *v25; // rax
  __int64 v26; // rax
  __int128 v27; // xmm6
  signed __int64 v28; // rcx
  __int64 v29; // rax
  signed __int64 v30; // rdi
  __int64 v31; // rax
  signed __int64 v32; // rdx
  __int64 v33; // rax
  __int64 *v34; // rcx
  __int64 v35; // rax
  __int64 v36; // rcx
  __int64 v37; // rax
  bool v38; // r9
  signed __int64 v39; // r8
  __int64 v40; // rcx
  signed __int64 v41; // rax
  __int64 *v42; // rdx
  __int64 v43; // rax
  __int64 v44; // rdx
  __int128 v45; // xmm8
  bool v46; // r14
  signed __int64 v47; // rax
  UFG::RoadNetworkConnection *v48; // rcx
  UFG::qBezierPathMemImaged *v49; // rax
  UFG::RoadNetworkConnection *v50; // rbx
  unsigned int v51; // eax
  UFG::qBezierSplineMemImaged *v52; // rax
  __int64 v53; // rax
  UFG::RoadNetworkConnection *v54; // rcx
  UFG::qBezierPathMemImaged *v55; // rax
  UFG::RoadNetworkConnection *v56; // rbx
  unsigned int v57; // eax
  UFG::qBezierSplineMemImaged *v58; // rax
  float v59; // xmm1_4
  int v60; // esi
  __int64 v61; // rax
  __int128 v62; // xmm6
  UFG::RoadNetworkConnection *v63; // rcx
  UFG::qBezierPathMemImaged *v64; // rax
  UFG::RoadNetworkConnection *v65; // rbx
  unsigned int v66; // eax
  UFG::qBezierSplineMemImaged *v67; // rax
  float v68; // xmm1_4
  UFG::qVector3 v2; // [rsp+8h] [rbp-79h]
  UFG::qVector3 v71; // [rsp+18h] [rbp-69h]
  UFG::qVector3 v72; // [rsp+28h] [rbp-59h]
  UFG::qVector3 v73; // [rsp+38h] [rbp-49h]
  UFG::qVector3 result; // [rsp+48h] [rbp-39h]
  float splineT; // [rsp+F0h] [rbp+6Fh]

  v4 = otherLaneIndex;
  v5 = this;
  v6 = this->mLane.mOffset;
  if ( v6 )
    v7 = (char *)&this->mLane + v6;
  else
    v7 = 0i64;
  v8 = laneIndex;
  v9 = (signed __int64)&v7[8 * v8];
  v10 = *(_QWORD *)&v7[8 * v8];
  if ( v10 )
    v11 = v10 + v9;
  else
    v11 = 0i64;
  if ( *(_QWORD *)v11 )
    v12 = *(_QWORD *)v11 + v11;
  else
    v12 = 0i64;
  v13 = *(_QWORD *)(v12 + 48);
  v14 = *(unsigned __int16 *)(v11 + 36);
  if ( v13 )
    v15 = v13 + v12 + 48;
  else
    v15 = 0i64;
  v16 = *(_QWORD *)(v15 + 8 * v14);
  v17 = v15 + 8 * v14;
  if ( v16 )
    v16 += v17;
  v18 = *(unsigned __int16 *)(v16 + 38);
  v19 = *(_QWORD *)(v12 + 32);
  if ( v19 )
    v20 = (UFG::RoadNetworkConnection *)(v19 + v12 + 32);
  else
    v20 = 0i64;
  v21 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v20, v18);
  v22 = 0.0;
  splineT = 0.0;
  v23 = (UFG::RoadNetworkConnection *)v21;
  v24 = UFG::qBezierPathMemImaged::GetSplineParameters(v21, *(const float *)&t, &splineT);
  v25 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v23, v24);
  UFG::qBezierSplineMemImaged::GetTangent(v25, &result, splineT);
  v26 = v5->mLane.mOffset;
  v27 = t;
  if ( v26 )
    v28 = (signed __int64)&v5->mLane + v26;
  else
    v28 = 0i64;
  v29 = *(_QWORD *)(v28 + 8 * v4);
  if ( v29 )
    v30 = v28 + 8 * v4 + v29;
  else
    v30 = 0i64;
  v31 = *(_QWORD *)(v30 + 8);
  if ( v31 )
    v32 = v30 + v31 + 8;
  else
    v32 = 0i64;
  v33 = *(_QWORD *)v30;
  if ( *(_QWORD *)v30 )
    v33 += v30;
  v34 = *(__int64 **)(v33 + 48);
  if ( v34 )
    v34 = (__int64 *)((char *)v34 + v33 + 48);
  v35 = *v34;
  if ( *v34 )
    v35 += (__int64)v34;
  v36 = *(_QWORD *)(v35 + 8);
  if ( v36 )
    v36 += v35 + 8;
  v37 = *(_QWORD *)(v11 + 8);
  v38 = v32 != v36;
  if ( v37 )
    v39 = v11 + v37 + 8;
  else
    v39 = 0i64;
  v40 = *(_QWORD *)v11;
  if ( *(_QWORD *)v11 )
    v41 = v40 + v11;
  else
    v41 = 0i64;
  v42 = *(__int64 **)(v41 + 48);
  if ( v42 )
    v42 = (__int64 *)((char *)v42 + v41 + 48);
  v43 = *v42;
  if ( *v42 )
    v43 += (__int64)v42;
  v44 = *(_QWORD *)(v43 + 8);
  if ( v44 )
    v44 += v43 + 8;
  v45 = (unsigned int)FLOAT_1_0;
  v46 = v38 != (v39 != v44);
  if ( v38 != (v39 != v44) )
  {
    v27 = (unsigned int)FLOAT_1_0;
    *(float *)&v27 = 1.0 - *(float *)&t;
  }
  if ( v40 )
    v47 = v40 + v11;
  else
    v47 = 0i64;
  v48 = *(UFG::RoadNetworkConnection **)(v47 + 32);
  if ( v48 )
    v48 = (UFG::RoadNetworkConnection *)((char *)v48 + v47 + 32);
  v49 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v48, *(unsigned __int16 *)(v11 + 38));
  v50 = (UFG::RoadNetworkConnection *)v49;
  v51 = UFG::qBezierPathMemImaged::GetSplineParameters(v49, *(const float *)&t, &splineT);
  v52 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v50, v51);
  UFG::RoadNetworkLane::GetOffsetPos(&v71, v52, splineT, *(float *)(v11 + 40));
  v53 = *(_QWORD *)v30;
  if ( *(_QWORD *)v30 )
    v53 += v30;
  v54 = *(UFG::RoadNetworkConnection **)(v53 + 32);
  if ( v54 )
    v54 = (UFG::RoadNetworkConnection *)((char *)v54 + v53 + 32);
  v55 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v54, *(unsigned __int16 *)(v30 + 38));
  v56 = (UFG::RoadNetworkConnection *)v55;
  v57 = UFG::qBezierPathMemImaged::GetSplineParameters(v55, *(const float *)&v27, &splineT);
  v58 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v56, v57);
  UFG::RoadNetworkLane::GetOffsetPos(&v72, v58, splineT, *(float *)(v30 + 40));
  v59 = UFG::qAngleBetween(&result, &v2);
  if ( (float)(1.5707964 - v59) > 0.06981317 )
  {
    if ( v59 <= 1.5707964 )
    {
      if ( !v46 )
      {
        v45 = v27;
        goto LABEL_65;
      }
    }
    else if ( v46 )
    {
      v45 = v27;
LABEL_65:
      v60 = 0;
      while ( 1 )
      {
        v61 = *(_QWORD *)v30;
        v62 = v45;
        *(float *)&v62 = (float)((float)(*(float *)&v45 - v22) * 0.5) + v22;
        if ( *(_QWORD *)v30 )
          v61 += v30;
        v63 = *(UFG::RoadNetworkConnection **)(v61 + 32);
        if ( v63 )
          v63 = (UFG::RoadNetworkConnection *)((char *)v63 + v61 + 32);
        v64 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                             v63,
                                             *(unsigned __int16 *)(v30 + 38));
        v65 = (UFG::RoadNetworkConnection *)v64;
        v66 = UFG::qBezierPathMemImaged::GetSplineParameters(v64, *(const float *)&v62, &splineT);
        v67 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v65, v66);
        UFG::RoadNetworkLane::GetOffsetPos(&v73, v67, splineT, *(float *)(v30 + 40));
        v68 = UFG::qAngleBetween(&result, &v2);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(1.5707964 - v68) & _xmm) < 0.06981317 )
          return *(float *)&v62;
        if ( v68 <= 1.5707964 )
        {
          if ( v46 )
          {
LABEL_76:
            v22 = (float)((float)(*(float *)&v45 - v22) * 0.5) + v22;
            goto LABEL_77;
          }
          v45 = v62;
        }
        else
        {
          if ( !v46 )
            goto LABEL_76;
          v45 = v62;
        }
LABEL_77:
        if ( ++v60 >= 10 )
          return *(float *)&v62;
      }
    }
    v22 = *(float *)&v27;
    goto LABEL_65;
  }
  return *(float *)&v27;
}

// File Line: 1809
// RVA: 0xDBF30
float __fastcall UFG::RoadNetworkSegment::GetTFromDistance(UFG::RoadNetworkSegment *this, UFG::RoadNetworkLane *lane, float distance, float beginT, bool forward)
{
  UFG::RoadNetworkConnection *v5; // rcx
  char *v6; // rax
  unsigned int v7; // er8
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
  v7 = lane->mPathIndex;
  v8 = *((_QWORD *)v6 + 4);
  if ( v8 )
    v5 = (UFG::RoadNetworkConnection *)&v6[v8 + 32];
  v9 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v5, v7)->mNode.mOffset + 1);
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
UFG::RoadNetworkSubSegment *__fastcall UFG::RoadNetworkSegment::GetClosestSubSegment(UFG::RoadNetworkSegment *this, UFG::qVector3 *position)
{
  UFG::RoadNetworkSegment *v2; // rbp
  float *v3; // r12
  float v4; // xmm6_4
  float v5; // xmm2_4
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v6; // rax
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *v7; // r13
  float v8; // xmm3_4
  float v9; // xmm4_4
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
  float v24; // xmm2_4
  char *v25; // rax
  __int64 v26; // rdx
  UFG::qVector3 *v28; // [rsp+A8h] [rbp+10h]

  v28 = position;
  v2 = this;
  v3 = 0i64;
  v4 = FLOAT_3_4028235e38;
  v5 = FLOAT_3_4028235e38;
  v6 = this->mSubSegmentCollection.mNode.mNext;
  v7 = &this->mSubSegmentCollection;
  if ( v6 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&this->mSubSegmentCollection )
  {
    do
    {
      v8 = position->x;
      v9 = position->y;
      if ( (float)((float)((float)(v8 - *(float *)&v6[1].mNext) * (float)(v8 - *(float *)&v6[1].mNext))
                 + (float)((float)(v9 - *((float *)&v6[1].mNext + 1)) * (float)(v9 - *((float *)&v6[1].mNext + 1)))) < v5 )
      {
        v3 = (float *)v6;
        v5 = (float)((float)(v8 - *(float *)&v6[1].mNext) * (float)(v8 - *(float *)&v6[1].mNext))
           + (float)((float)(v9 - *((float *)&v6[1].mNext + 1)) * (float)(v9 - *((float *)&v6[1].mNext + 1)));
      }
      v6 = v6->mNext;
    }
    while ( v6 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v7 );
  }
  v10 = 16i64;
  if ( !is_mul_ok(2ui64, 8ui64) )
    v10 = -1i64;
  v11 = UFG::qMalloc(v10, "qArray.Add", 0i64);
  v12 = 2;
  v13 = 1;
  *(_QWORD *)v11 = v3;
  v14 = v2->mSubSegmentCollection.mNode.mNext;
  if ( v14 == (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v7 )
    goto LABEL_43;
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
  while ( v14 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v7 );
  if ( v13 == 1 )
  {
LABEL_43:
    v3 = *(float **)v11;
  }
  else if ( v13 )
  {
    v25 = v11;
    v26 = v13;
    do
    {
      v24 = v28->z;
      if ( (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *(float *)(*(_QWORD *)v25 + 32i64)) & _xmm) + 4.0) < v4 )
      {
        v3 = *(float **)v25;
        LODWORD(v4) = COERCE_UNSIGNED_INT(v24 - *(float *)(*(_QWORD *)v25 + 32i64)) & _xmm;
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
UFG::RoadNetworkSubSegment *__fastcall UFG::RoadNetworkSegment::GetClosestSubSegment(UFG::RoadNetworkSegment *this, UFG::RoadNetworkGate *gate)
{
  UFG::RoadNetworkSubSegment *result; // rax
  UFG::RoadNetworkSubSegment *v3; // r8
  float v4; // xmm7_4
  float v5; // xmm6_4

  result = (UFG::RoadNetworkSubSegment *)this->mSubSegmentCollection.mNode.mNext;
  v3 = (UFG::RoadNetworkSubSegment *)this->mSubSegmentCollection.mNode.mPrev;
  if ( result != v3 )
  {
    v4 = result->mPosition.y - gate->mPosition.y;
    v5 = v3->mPosition.y - gate->mPosition.y;
    if ( (float)((float)((float)(v5 * v5)
                       + (float)((float)(v3->mPosition.x - gate->mPosition.x)
                               * (float)(v3->mPosition.x - gate->mPosition.x)))
               + (float)((float)(v3->mPosition.z - gate->mPosition.z) * (float)(v3->mPosition.z - gate->mPosition.z))) > (float)((float)((float)(v4 * v4) + (float)((float)(result->mPosition.x - gate->mPosition.x) * (float)(result->mPosition.x - gate->mPosition.x))) + (float)((float)(result->mPosition.z - gate->mPosition.z) * (float)(result->mPosition.z - gate->mPosition.z))) )
      v3 = (UFG::RoadNetworkSubSegment *)this->mSubSegmentCollection.mNode.mNext;
    result = v3;
  }
  return result;
}

// File Line: 2011
// RVA: 0xCFA30
void __fastcall UFG::RoadNetworkSubSegment::RoadNetworkSubSegment(UFG::RoadNetworkSubSegment *this, UFG::RoadNetworkSegment *segment, float length, float beginT)
{
  UFG::RoadNetworkSegment *v4; // rsi
  UFG::RoadNetworkSubSegment *v5; // rdi
  signed __int64 v6; // r12
  UFG::qList<UFG::ParkingSpot,UFG::ParkingSpot,1,0> *v7; // rax
  __int64 v8; // rax
  _QWORD *v9; // rax
  float *v10; // r14
  char *v11; // rax
  __int64 v12; // rcx
  UFG::RoadNetworkConnection *v13; // rcx
  UFG::qBezierPathMemImaged *v14; // rax
  UFG::RoadNetworkConnection *v15; // rbx
  unsigned int v16; // eax
  UFG::qBezierSplineMemImaged *v17; // rax
  __int64 v18; // rax
  _QWORD *v19; // rax
  float *v20; // r14
  char *v21; // rax
  __int64 v22; // rcx
  UFG::RoadNetworkConnection *v23; // rcx
  UFG::qBezierPathMemImaged *v24; // rax
  UFG::RoadNetworkConnection *v25; // rbx
  float v26; // xmm8_4
  unsigned int v27; // eax
  UFG::qBezierSplineMemImaged *v28; // rax
  __int64 v29; // r13
  unsigned int v30; // er15
  qPagedLinearAllocator *v31; // rax
  qPagedLinearAllocator *v32; // rbx
  __int64 v33; // r14
  float *v34; // rcx
  qPagedLinearAllocator *v35; // rax
  qPagedLinearAllocator *v36; // rbx
  float *v37; // rcx
  __int64 v38; // rax
  _QWORD *v39; // rax
  __int64 v40; // r15
  float *v41; // r14
  char *v42; // rax
  __int64 v43; // rcx
  UFG::RoadNetworkConnection *v44; // rcx
  UFG::qBezierPathMemImaged *v45; // rax
  UFG::RoadNetworkConnection *v46; // rbx
  unsigned int v47; // eax
  UFG::qBezierSplineMemImaged *v48; // rax
  __int64 v49; // rax
  _QWORD *v50; // rax
  float *v51; // r14
  char *v52; // rax
  __int64 v53; // rcx
  UFG::RoadNetworkConnection *v54; // rcx
  UFG::qBezierPathMemImaged *v55; // rax
  UFG::RoadNetworkConnection *v56; // rbx
  unsigned int v57; // eax
  UFG::qBezierSplineMemImaged *v58; // rax
  float v59; // xmm10_4
  float v60; // xmm11_4
  float v61; // xmm12_4
  float v62; // xmm13_4
  __int64 v63; // rax
  _QWORD *v64; // rax
  _QWORD *v65; // rax
  __int64 v66; // rcx
  signed __int64 v67; // rdx
  char *v68; // rcx
  __int64 v69; // rax
  char *v70; // rax
  char *v71; // rcx
  __int64 v72; // rax
  signed __int64 v73; // rax
  signed __int64 v74; // rsi
  __int64 v75; // r14
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkLane *> *> *v76; // rax
  char *v77; // rcx
  signed __int64 v78; // rax
  __int64 v79; // rcx
  signed __int64 v80; // rbx
  signed __int64 v81; // rax
  __int64 v82; // rcx
  UFG::RoadNetworkConnection *v83; // rcx
  UFG::qBezierPathMemImaged *v84; // rax
  signed __int64 v85; // rax
  __int64 v86; // rcx
  UFG::RoadNetworkConnection *v87; // rcx
  UFG::qBezierPathMemImaged *v88; // rax
  __int64 v89; // rax
  signed __int64 v90; // rdx
  signed __int64 v91; // rax
  __int64 v92; // rcx
  _QWORD *v93; // rcx
  char *v94; // rax
  __int64 v95; // rcx
  signed __int64 v96; // rcx
  float v97; // xmm0_4
  float v98; // xmm1_4
  __int64 v99; // rax
  signed __int64 v100; // rdx
  signed __int64 v101; // rax
  __int64 v102; // rcx
  _QWORD *v103; // rax
  char *v104; // rcx
  __int64 v105; // rax
  signed __int64 v106; // rax
  float v107; // xmm8_4
  float v108; // xmm9_4
  float v109; // xmm10_4
  float v110; // xmm11_4
  float v111; // xmm14_4
  float v112; // xmm15_4
  float v113; // xmm12_4
  __int64 v114; // r14
  __int64 v115; // r12
  float v116; // xmm6_4
  UFG::RoadNetworkSegment *v117; // rax
  __int64 v118; // rcx
  signed __int64 v119; // rax
  signed __int64 v120; // rcx
  __int64 v121; // rax
  signed __int64 v122; // rsi
  signed __int64 v123; // rax
  __int64 v124; // rcx
  UFG::RoadNetworkConnection *v125; // rcx
  UFG::qBezierPathMemImaged *v126; // rax
  UFG::RoadNetworkConnection *v127; // rbx
  unsigned int v128; // eax
  UFG::qBezierSplineMemImaged *v129; // rax
  float v130; // xmm6_4
  UFG::RoadNetworkSegment *v131; // rax
  __int64 v132; // rcx
  signed __int64 v133; // rax
  signed __int64 v134; // rcx
  __int64 v135; // rax
  signed __int64 v136; // rsi
  signed __int64 v137; // rax
  __int64 v138; // rcx
  UFG::RoadNetworkConnection *v139; // rcx
  UFG::qBezierPathMemImaged *v140; // rax
  UFG::RoadNetworkConnection *v141; // rbx
  unsigned int v142; // eax
  UFG::qBezierSplineMemImaged *v143; // rax
  float v144; // xmm7_4
  float v145; // xmm2_4
  float v146; // xmm0_4
  UFG::qVector3 v147; // [rsp+28h] [rbp-98h]
  UFG::qVector3 v148; // [rsp+38h] [rbp-88h]
  UFG::qVector3 pos; // [rsp+48h] [rbp-78h]
  UFG::qVector3 v150; // [rsp+58h] [rbp-68h]
  UFG::qVector3 result; // [rsp+68h] [rbp-58h]
  UFG::qVector3 v152; // [rsp+78h] [rbp-48h]
  UFG::qList<UFG::ParkingSpot,UFG::ParkingSpot,1,0> *v153; // [rsp+148h] [rbp+88h]
  float t; // [rsp+150h] [rbp+90h]
  float v155; // [rsp+158h] [rbp+98h]
  float pathT; // [rsp+160h] [rbp+A0h]
  float splineT; // [rsp+168h] [rbp+A8h]

  v4 = segment;
  v5 = this;
  this->mPrev = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&this->mPrev;
  this->mParentNode = segment;
  this->mLength = length;
  this->mActive = 0;
  this->mIndex = LOWORD(splineT);
  v6 = 1i64;
  this->mStatus.mValue = 4;
  this->mNumSpawnPoints = 0;
  this->mNumParkingSpots = 0;
  v7 = &this->mParkingSpotCollection;
  v153 = v7;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v7->mNode.mPrev = &v7->mNode;
  this->mParkingSpotCollection.mNode.mNext = &this->mParkingSpotCollection.mNode;
  v8 = segment->mLane.mOffset;
  if ( v8 )
    v9 = (__int64 *)((char *)&segment->mLane.mOffset + v8);
  else
    v9 = 0i64;
  v10 = (float *)((char *)v9 + *v9);
  if ( !*v9 )
    v10 = 0i64;
  if ( *(_QWORD *)v10 )
    v11 = (char *)v10 + *(_QWORD *)v10;
  else
    v11 = 0i64;
  v12 = *((_QWORD *)v11 + 4);
  if ( v12 )
    v13 = (UFG::RoadNetworkConnection *)&v11[v12 + 32];
  else
    v13 = 0i64;
  v14 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v13, *((unsigned __int16 *)v10 + 19));
  v15 = (UFG::RoadNetworkConnection *)v14;
  v16 = UFG::qBezierPathMemImaged::GetSplineParameters(v14, beginT, &splineT);
  v17 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v15, v16);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v17, splineT, v10[10]);
  v18 = v4->mLane.mOffset;
  if ( v18 )
    v19 = (__int64 *)((char *)&v4->mLane.mOffset + v18);
  else
    v19 = 0i64;
  v20 = (float *)((char *)v19 + *v19);
  if ( !*v19 )
    v20 = 0i64;
  if ( *(_QWORD *)v20 )
    v21 = (char *)v20 + *(_QWORD *)v20;
  else
    v21 = 0i64;
  v22 = *((_QWORD *)v21 + 4);
  if ( v22 )
    v23 = (UFG::RoadNetworkConnection *)&v21[v22 + 32];
  else
    v23 = 0i64;
  v24 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v23, *((unsigned __int16 *)v20 + 19));
  v25 = (UFG::RoadNetworkConnection *)v24;
  v26 = pathT;
  v27 = UFG::qBezierPathMemImaged::GetSplineParameters(v24, pathT, &splineT);
  v28 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v25, v27);
  UFG::RoadNetworkLane::GetOffsetPos(&v152, v28, splineT, v20[10]);
  v29 = (unsigned __int8)v4->mNumLanes;
  LODWORD(v153) = v29;
  v30 = 4 * v29;
  v31 = GetLaneTAllocator();
  v32 = v31;
  if ( !v31->mpCurrentPage )
    qPagedLinearAllocator::NewPage(v31);
  if ( v30 > v32->mRemainingBytesOnPage )
    qPagedLinearAllocator::NewPage(v32);
  v33 = (v30 + 3) & 0xFFFFFFFC;
  v34 = (float *)v32->mpCurrentPos;
  v32->mpCurrentPos = (char *)v34 + v33;
  v32->mRemainingBytesOnPage -= v33;
  v5->mBeginTCollection = v34;
  v35 = GetLaneTAllocator();
  v36 = v35;
  if ( !v35->mpCurrentPage )
    qPagedLinearAllocator::NewPage(v35);
  if ( v30 > v36->mRemainingBytesOnPage )
    qPagedLinearAllocator::NewPage(v36);
  v37 = (float *)v36->mpCurrentPos;
  v36->mpCurrentPos = (char *)v37 + v33;
  v36->mRemainingBytesOnPage -= v33;
  v5->mEndTCollection = v37;
  *v5->mBeginTCollection = beginT;
  *v5->mEndTCollection = v26;
  v38 = v4->mLane.mOffset;
  if ( v38 )
  {
    v39 = (__int64 *)((char *)&v4->mLane.mOffset + v38);
    v40 = 0i64;
  }
  else
  {
    v40 = 0i64;
    v39 = 0i64;
  }
  v41 = (float *)((char *)v39 + *v39);
  if ( !*v39 )
    v41 = 0i64;
  if ( *(_QWORD *)v41 )
    v42 = (char *)v41 + *(_QWORD *)v41;
  else
    v42 = 0i64;
  v43 = *((_QWORD *)v42 + 4);
  if ( v43 )
    v44 = (UFG::RoadNetworkConnection *)&v42[v43 + 32];
  else
    v44 = 0i64;
  v45 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v44, *((unsigned __int16 *)v41 + 19));
  v46 = (UFG::RoadNetworkConnection *)v45;
  v47 = UFG::qBezierPathMemImaged::GetSplineParameters(v45, beginT, &splineT);
  v48 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v46, v47);
  UFG::RoadNetworkLane::GetOffsetPos(&pos, v48, splineT, v41[10]);
  v49 = v4->mLane.mOffset;
  if ( v49 )
    v50 = (__int64 *)((char *)&v4->mLane.mOffset + v49);
  else
    v50 = 0i64;
  v51 = (float *)((char *)v50 + *v50);
  if ( !*v50 )
    v51 = 0i64;
  if ( *(_QWORD *)v51 )
    v52 = (char *)v51 + *(_QWORD *)v51;
  else
    v52 = 0i64;
  v53 = *((_QWORD *)v52 + 4);
  if ( v53 )
    v54 = (UFG::RoadNetworkConnection *)&v52[v53 + 32];
  else
    v54 = 0i64;
  v55 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v54, *((unsigned __int16 *)v51 + 19));
  v56 = (UFG::RoadNetworkConnection *)v55;
  v57 = UFG::qBezierPathMemImaged::GetSplineParameters(v55, v26, &splineT);
  v58 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v56, v57);
  UFG::RoadNetworkLane::GetOffsetPos(&v150, v58, splineT, v51[10]);
  v59 = *(float *)&FLOAT_1_0;
  v60 = 0.0;
  v61 = 0.0;
  v62 = *(float *)&FLOAT_1_0;
  v63 = v4->mLane.mOffset;
  if ( v63 )
    v64 = (__int64 *)((char *)&v4->mLane.mOffset + v63);
  else
    v64 = 0i64;
  if ( *v64 )
    v65 = (_QWORD *)((char *)v64 + *v64);
  else
    v65 = 0i64;
  v66 = v65[1];
  if ( v66 )
    v67 = (signed __int64)v65 + v66 + 8;
  else
    v67 = 0i64;
  if ( *v65 )
    v68 = (char *)v65 + *v65;
  else
    v68 = 0i64;
  v69 = *((_QWORD *)v68 + 6);
  if ( v69 )
    v70 = &v68[v69 + 48];
  else
    v70 = 0i64;
  if ( *(_QWORD *)v70 )
    v71 = &v70[*(_QWORD *)v70];
  else
    v71 = 0i64;
  v72 = *((_QWORD *)v71 + 1);
  if ( v72 )
    v73 = (signed __int64)&v71[v72 + 8];
  else
    v73 = 0i64;
  if ( v67 == v73 )
  {
    if ( beginT < 1.0 )
      v59 = beginT;
    if ( v26 > 0.0 )
      v60 = v26;
  }
  else
  {
    if ( beginT > 0.0 )
      v61 = beginT;
    if ( v26 < 1.0 )
      v62 = v26;
  }
  if ( (unsigned int)v29 > 1 )
  {
    v74 = 8i64;
    v75 = (unsigned int)(v29 - 1);
    do
    {
      splineT = 3.4028235e38;
      pathT = 3.4028235e38;
      v76 = &v5->mParentNode->mLane;
      if ( v76->mOffset )
        v77 = (char *)v76 + v76->mOffset;
      else
        v77 = 0i64;
      v78 = (signed __int64)&v77[v74];
      v79 = *(_QWORD *)&v77[v74];
      v80 = v79 + v78;
      if ( !v79 )
        v80 = 0i64;
      if ( *(_QWORD *)v80 )
        v81 = v80 + *(_QWORD *)v80;
      else
        v81 = 0i64;
      v82 = *(_QWORD *)(v81 + 32);
      if ( v82 )
        v83 = (UFG::RoadNetworkConnection *)(v81 + v82 + 32);
      else
        v83 = 0i64;
      v84 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v83,
                                           *(unsigned __int16 *)(v80 + 38));
      UFG::qBezierPathMemImaged::ClosestPoint3D(v84, &v148, &pos, &splineT);
      if ( *(_QWORD *)v80 )
        v85 = v80 + *(_QWORD *)v80;
      else
        v85 = 0i64;
      v86 = *(_QWORD *)(v85 + 32);
      if ( v86 )
        v87 = (UFG::RoadNetworkConnection *)(v85 + v86 + 32);
      else
        v87 = 0i64;
      v88 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                           v87,
                                           *(unsigned __int16 *)(v80 + 38));
      UFG::qBezierPathMemImaged::ClosestPoint3D(v88, &v147, &v150, &pathT);
      v89 = *(_QWORD *)(v80 + 8);
      if ( v89 )
        v90 = v89 + v80 + 8;
      else
        v90 = 0i64;
      if ( *(_QWORD *)v80 )
        v91 = v80 + *(_QWORD *)v80;
      else
        v91 = 0i64;
      v92 = *(_QWORD *)(v91 + 48);
      if ( v92 )
        v93 = (_QWORD *)(v91 + v92 + 48);
      else
        v93 = 0i64;
      if ( *v93 )
        v94 = (char *)v93 + *v93;
      else
        v94 = 0i64;
      v95 = *((_QWORD *)v94 + 1);
      if ( v95 )
        v96 = (signed __int64)&v94[v95 + 8];
      else
        v96 = 0i64;
      if ( v90 == v96 )
      {
        if ( beginT == 0.0 )
        {
          v97 = 0.0;
          splineT = 0.0;
        }
        else
        {
          v97 = splineT;
        }
        if ( v26 != 1.0 )
          goto LABEL_128;
        v98 = *(float *)&FLOAT_1_0;
        pathT = *(float *)&FLOAT_1_0;
      }
      else
      {
        if ( beginT == 0.0 )
        {
          v97 = *(float *)&FLOAT_1_0;
          splineT = *(float *)&FLOAT_1_0;
        }
        else
        {
          v97 = splineT;
        }
        if ( v26 != 1.0 )
        {
LABEL_128:
          v98 = pathT;
          goto LABEL_129;
        }
        v98 = 0.0;
        pathT = 0.0;
      }
LABEL_129:
      v99 = *(_QWORD *)(v80 + 8);
      if ( v99 )
        v100 = v99 + v80 + 8;
      else
        v100 = 0i64;
      if ( *(_QWORD *)v80 )
        v101 = v80 + *(_QWORD *)v80;
      else
        v101 = 0i64;
      v102 = *(_QWORD *)(v101 + 48);
      if ( v102 )
        v103 = (_QWORD *)(v102 + v101 + 48);
      else
        v103 = 0i64;
      if ( *v103 )
        v104 = (char *)v103 + *v103;
      else
        v104 = 0i64;
      v105 = *((_QWORD *)v104 + 1);
      if ( v105 )
        v106 = (signed __int64)&v104[v105 + 8];
      else
        v106 = 0i64;
      if ( v100 == v106 )
      {
        if ( v97 < v59 )
          v59 = v97;
        if ( v98 > v60 )
          v60 = v98;
      }
      else
      {
        if ( v97 > v61 )
          v61 = v97;
        if ( v98 < v62 )
          v62 = v98;
      }
      v5->mBeginTCollection[v6] = v97;
      v5->mEndTCollection[v6] = pathT;
      v74 += 8i64;
      ++v6;
      --v75;
    }
    while ( v75 );
  }
  v107 = UFG::qVector3::msZero.x;
  v108 = UFG::qVector3::msZero.y;
  v109 = UFG::qVector3::msZero.z;
  v110 = UFG::qVector3::msZero.x;
  v111 = UFG::qVector3::msZero.y;
  v112 = UFG::qVector3::msZero.z;
  v113 = UFG::qVector3::msZero.x;
  pathT = UFG::qVector3::msZero.y;
  splineT = UFG::qVector3::msZero.z;
  if ( (_DWORD)v29 )
  {
    v114 = 0i64;
    v115 = v29;
    do
    {
      v116 = v5->mBeginTCollection[v40];
      v117 = v5->mParentNode;
      v118 = v117->mLane.mOffset;
      if ( v118 )
        v119 = (signed __int64)&v117->mLane + v118;
      else
        v119 = 0i64;
      v120 = v114 + v119;
      v121 = *(_QWORD *)(v114 + v119);
      v122 = v121 + v120;
      if ( !v121 )
        v122 = 0i64;
      if ( *(_QWORD *)v122 )
        v123 = v122 + *(_QWORD *)v122;
      else
        v123 = 0i64;
      v124 = *(_QWORD *)(v123 + 32);
      if ( v124 )
        v125 = (UFG::RoadNetworkConnection *)(v123 + v124 + 32);
      else
        v125 = 0i64;
      v126 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                            v125,
                                            *(unsigned __int16 *)(v122 + 38));
      v127 = (UFG::RoadNetworkConnection *)v126;
      v128 = UFG::qBezierPathMemImaged::GetSplineParameters(v126, v116, &t);
      v129 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v127, v128);
      UFG::RoadNetworkLane::GetOffsetPos(&v147, v129, t, *(float *)(v122 + 40));
      v130 = v5->mEndTCollection[v40];
      v131 = v5->mParentNode;
      v132 = v131->mLane.mOffset;
      if ( v132 )
        v133 = (signed __int64)&v131->mLane + v132;
      else
        v133 = 0i64;
      v134 = v114 + v133;
      v135 = *(_QWORD *)(v114 + v133);
      v136 = v135 + v134;
      if ( !v135 )
        v136 = 0i64;
      if ( *(_QWORD *)v136 )
        v137 = v136 + *(_QWORD *)v136;
      else
        v137 = 0i64;
      v138 = *(_QWORD *)(v137 + 32);
      if ( v138 )
        v139 = (UFG::RoadNetworkConnection *)(v137 + v138 + 32);
      else
        v139 = 0i64;
      v140 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                            v139,
                                            *(unsigned __int16 *)(v136 + 38));
      v141 = (UFG::RoadNetworkConnection *)v140;
      v142 = UFG::qBezierPathMemImaged::GetSplineParameters(v140, v130, &v155);
      v143 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v141, v142);
      UFG::RoadNetworkLane::GetOffsetPos(&v148, v143, v155, *(float *)(v136 + 40));
      v109 = v147.z + v109;
      v108 = v147.y + v108;
      v107 = v107 + v147.x;
      v112 = v148.z + v112;
      v111 = v148.y + v111;
      v110 = v110 + v148.x;
      splineT = (float)((float)(v148.z + v147.z) * 0.5) + splineT;
      pathT = (float)((float)(v148.y + v147.y) * 0.5) + pathT;
      v113 = v113 + (float)((float)(v148.x + v147.x) * 0.5);
      ++v40;
      v114 += 8i64;
      --v115;
    }
    while ( v115 );
    LODWORD(v29) = (_DWORD)v153;
  }
  v144 = 1.0 / (float)(signed int)v29;
  v5->mBeginPos.x = v144 * v107;
  v5->mBeginPos.y = v144 * v108;
  v5->mBeginPos.z = v144 * v109;
  v5->mEndPos.x = v144 * v110;
  v5->mEndPos.y = v144 * v111;
  v5->mEndPos.z = v144 * v112;
  v145 = v144 * splineT;
  v146 = v144 * pathT;
  v5->mPosition.x = v144 * v113;
  v5->mPosition.y = v146;
  v5->mPosition.z = v145;
}

// File Line: 2113
// RVA: 0xD1000
void __fastcall UFG::RoadNetworkSubSegment::~RoadNetworkSubSegment(UFG::RoadNetworkSubSegment *this)
{
  UFG::RoadNetworkSubSegment *v1; // rdi
  UFG::qList<UFG::ParkingSpot,UFG::ParkingSpot,1,0> *v2; // rbx
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v3; // rax
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v4; // r8
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v5; // rdx
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v6; // rcx
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v7; // rax
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v8; // rcx
  UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *v9; // rax
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v10; // rcx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v11; // rax

  v1 = this;
  v2 = &this->mParkingSpotCollection;
  v3 = this->mParkingSpotCollection.mNode.mNext - 12;
  v4 = (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&this[-1].mPosition.z;
  if ( v3 != (UFG::qNode<UFG::ParkingSpot,UFG::ParkingSpot> *)&this[-1].mPosition.z )
  {
    do
    {
      v5 = v3 + 12;
      v6 = v3[12].mPrev;
      v7 = v3[12].mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mPrev = v5;
      v5->mNext = v5;
      v3 = v2->mNode.mNext - 12;
    }
    while ( v3 != v4 );
  }
  UFG::qList<UFG::ParkingSpot,UFG::ParkingSpot,1,0>::DeleteNodes(v2);
  v8 = v2->mNode.mPrev;
  v9 = v2->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v1->mPrev = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v1->mPrev;
}

// File Line: 2148
// RVA: 0xDF000
char __fastcall UFG::RoadNetworkSubSegment::IsWithinSubSegment(UFG::RoadNetworkSubSegment *this, UFG::RoadNetworkLane *roadLane, float laneT)
{
  __int64 v3; // r8
  float v4; // xmm7_4
  float v5; // xmm8_4
  bool v6; // cf
  bool v7; // zf

  v3 = roadLane->mLaneIndex;
  v4 = this->mBeginTCollection[v3];
  v5 = this->mEndTCollection[v3];
  if ( UFG::RoadNetworkLane::IsReversedInNode(roadLane) )
  {
    if ( laneT < v5 )
      return 0;
    v6 = laneT < v4;
    v7 = laneT == v4;
  }
  else
  {
    if ( laneT < v4 )
      return 0;
    v6 = laneT < v5;
    v7 = laneT == v5;
  }
  if ( v6 || v7 )
    return 1;
  return 0;
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
void __fastcall UFG::RoadNetworkSubSegment::GetGatesConnectedToSubSegment(UFG::RoadNetworkSubSegment *this, UFG::qArray<UFG::RoadNetworkGate *,0> *gateCollection)
{
  UFG::RoadNetworkSubSegment *v2; // r15
  UFG::RoadNetworkGate **v3; // rcx
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v4; // rsi
  signed __int64 v5; // rax
  UFG::RoadNetworkSegment *v6; // rdi
  __int64 v7; // rcx
  _QWORD *v8; // rdx
  char *v9; // r8
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  signed __int64 v12; // r14
  __int64 v13; // rcx
  _QWORD *v14; // rcx
  char *v15; // r9
  __int64 v16; // rcx
  signed __int64 v17; // rbp
  signed __int64 v18; // rdi
  unsigned int v19; // ebx
  UFG::qReflectInventoryBase **v20; // rax
  __int64 v21; // rbp
  unsigned int v22; // eax
  unsigned int v23; // edi
  UFG::qReflectInventoryBase **v24; // rax

  v2 = this;
  v3 = gateCollection->p;
  v4 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)gateCollection;
  if ( v3 )
    operator delete[](v3);
  v5 = 0i64;
  v4->p = 0i64;
  *(_QWORD *)&v4->size = 0i64;
  v6 = v2->mParentNode;
  v7 = v6->mGates.mOffset;
  if ( v7 )
    v8 = (__int64 *)((char *)&v6->mGates.mOffset + v7);
  else
    v8 = 0i64;
  if ( *v8 )
    v9 = (char *)v8 + *v8;
  else
    v9 = 0i64;
  if ( v7 )
    v10 = (signed __int64)&v6->mGates + v7;
  else
    v10 = 0i64;
  v11 = *(_QWORD *)(v10 + 8);
  if ( v11 )
    v12 = v11 + v10 + 8;
  else
    v12 = 0i64;
  v13 = v6->mLane.mOffset;
  if ( v13 )
    v14 = (__int64 *)((char *)&v6->mLane.mOffset + v13);
  else
    v14 = 0i64;
  v15 = (char *)v14 + *v14;
  if ( !*v14 )
    v15 = 0i64;
  v16 = *((_QWORD *)v15 + 1);
  if ( v16 )
    v5 = (signed __int64)&v15[v16 + 8];
  if ( (char *)v5 == v9 )
  {
    v17 = (signed __int64)v9;
  }
  else
  {
    v17 = v12;
    v12 = (signed __int64)v9;
  }
  v18 = (signed __int64)&v6->mSubSegmentCollection;
  v19 = 1;
  if ( v2->mPrev == (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v18 )
  {
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v4, 2u, "qArray.Add");
    v20 = v4->p;
    v4->size = 1;
    *v20 = (UFG::qReflectInventoryBase *)v17;
  }
  if ( v2->mNext == (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)v18 )
  {
    v21 = v4->size;
    v22 = v4->capacity;
    v23 = v21 + 1;
    if ( (signed int)v21 + 1 > v22 )
    {
      if ( v22 )
        v19 = 2 * v22;
      for ( ; v19 < v23; v19 *= 2 )
        ;
      if ( v19 <= 2 )
        v19 = 2;
      if ( v19 - v23 > 0x10000 )
        v19 = v21 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v4, v19, "qArray.Add");
    }
    v24 = v4->p;
    v4->size = v23;
    v24[v21] = (UFG::qReflectInventoryBase *)v12;
  }
}

// File Line: 2365
// RVA: 0xCF8F0
void __fastcall UFG::RoadNetworkNodeModification::RoadNetworkNodeModification(UFG::RoadNetworkNodeModification *this, UFG::RoadNetworkNode *node)
{
  UFG::RoadNetworkNode *v2; // rbp
  UFG::RoadNetworkNodeModification *v3; // rsi
  unsigned int v4; // ecx
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  _QWORD *v12; // rax
  char *v13; // rax

  v2 = node;
  v3 = this;
  this->mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&this->mPrev;
  this->mLaneFlagsCollection.p = 0i64;
  *(_QWORD *)&this->mLaneFlagsCollection.size = 0i64;
  this->mNode = node;
  v4 = this->mLaneFlagsCollection.size;
  v5 = (unsigned __int8)node->mNumLanes - v4;
  if ( v5 <= 0 )
  {
    if ( v4 != (unsigned __int8)node->mNumLanes )
    {
      if ( v4 - (unsigned __int8)node->mNumLanes < v4 )
        v3->mLaneFlagsCollection.size = (unsigned __int8)node->mNumLanes;
      else
        v3->mLaneFlagsCollection.size = 0;
    }
  }
  else
  {
    v6 = (unsigned __int8)node->mNumLanes;
    v7 = v3->mLaneFlagsCollection.capacity;
    if ( v4 + v5 > v7 )
    {
      if ( v7 )
        v8 = 2 * v7;
      else
        v8 = 1;
      for ( ; v8 < v6; v8 *= 2 )
        ;
      if ( v8 <= 4 )
        v8 = 4;
      if ( v8 - v6 > 0x10000 )
        v8 = v6 + 0x10000;
      UFG::qArray<long,0>::Reallocate(&v3->mLaneFlagsCollection, v8, "RoadNetworkNodeModification");
    }
    v3->mLaneFlagsCollection.size = v6;
  }
  v9 = 0;
  if ( v2->mNumLanes > 0u )
  {
    do
    {
      v10 = v2->mLane.mOffset;
      if ( v10 )
        v11 = (signed __int64)&v2->mLane + v10;
      else
        v11 = 0i64;
      v12 = (_QWORD *)(v11 + 8i64 * v9);
      if ( *v12 )
        v13 = (char *)v12 + *v12;
      else
        v13 = 0i64;
      v3->mLaneFlagsCollection.p[v9++] = (unsigned __int8)v13[44];
    }
    while ( v9 < (unsigned __int8)v2->mNumLanes );
  }
}

// File Line: 2383
// RVA: 0xD0EC0
void __fastcall UFG::RoadNetworkNodeModification::~RoadNetworkNodeModification(UFG::RoadNetworkNodeModification *this)
{
  UFG::RoadNetworkNodeModification *v1; // rbx
  unsigned int *v2; // rcx
  unsigned int *v3; // rcx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v4; // rcx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v5; // rax

  v1 = this;
  v2 = this->mLaneFlagsCollection.p;
  if ( v2 )
    operator delete[](v2);
  v1->mLaneFlagsCollection.p = 0i64;
  *(_QWORD *)&v1->mLaneFlagsCollection.size = 0i64;
  v3 = v1->mLaneFlagsCollection.p;
  if ( v3 )
    operator delete[](v3);
  v1->mLaneFlagsCollection.p = 0i64;
  *(_QWORD *)&v1->mLaneFlagsCollection.size = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)&v1->mPrev;
}

// File Line: 2421
// RVA: 0xD0D90
void __fastcall UFG::RoadNetworkIntersection::~RoadNetworkIntersection(UFG::RoadNetworkIntersection *this)
{
  UFG::RoadNetworkIntersection *v1; // rdi
  __int64 v2; // rsi
  __int64 v3; // rbp
  __int64 v4; // rax
  signed __int64 v5; // rcx
  signed __int64 v6; // rax
  __int64 v7; // rcx
  signed __int64 v8; // rbx
  unsigned int v9; // edx
  unsigned int v10; // edx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v11; // rcx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v12; // rax

  v1 = this;
  if ( this->mNumTrafficLightLocations )
  {
    v2 = 0i64;
    v3 = (unsigned __int8)this->mNumTrafficLightLocations;
    do
    {
      if ( v1->mNumTrafficLightLocations
        && ((v4 = v1->mTrafficLightLocations.mOffset) == 0 ? (v5 = 0i64) : (v5 = (signed __int64)&v1->mTrafficLightLocations
                                                                               + v4),
            v6 = v2 + v5,
            (v7 = *(_QWORD *)(v2 + v5)) != 0) )
      {
        v8 = v7 + v6;
      }
      else
      {
        v8 = 0i64;
      }
      v9 = *(_DWORD *)(v8 + 28);
      if ( v9 != -1 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, v9, 0);
        *(_DWORD *)(v8 + 28) = -1;
      }
      v10 = *(_DWORD *)(v8 + 32);
      if ( v10 != -1 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, v10, 0);
        *(_DWORD *)(v8 + 32) = -1;
      }
      v2 += 8i64;
      --v3;
    }
    while ( v3 );
  }
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0>::DeleteNodes(&v1->mModifications);
  UFG::qList<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification,1,0>::DeleteNodes(&v1->mModifications);
  v11 = v1->mModifications.mNode.mPrev;
  v12 = v1->mModifications.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->mModifications.mNode.mPrev = &v1->mModifications.mNode;
  v1->mModifications.mNode.mNext = &v1->mModifications.mNode;
}

// File Line: 2463
// RVA: 0xDC3F0
UFG::RoadNetworkTrafficLightPhase *__fastcall UFG::RoadNetworkIntersection::GetTrafficLightPhase(UFG::RoadNetworkIntersection *this, unsigned int index)
{
  __int64 v2; // r8
  __int64 v4; // rdx
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkTrafficLightPhase *> *> *v5; // rax
  signed __int64 v6; // rcx
  char *v7; // rdx
  __int64 v8; // rax
  signed __int64 v9; // r8

  v2 = index;
  if ( !this->mNumLightPhases )
    return 0i64;
  v4 = this->mLightPhases.mOffset;
  v5 = &this->mLightPhases;
  v6 = 0i64;
  if ( v4 )
    v7 = (char *)v5 + v4;
  else
    v7 = 0i64;
  v8 = *(_QWORD *)&v7[8 * v2];
  v9 = (signed __int64)&v7[8 * v2];
  if ( v8 )
    v6 = v8 + v9;
  return (UFG::RoadNetworkTrafficLightPhase *)v6;
}

// File Line: 2478
// RVA: 0xDB620
float __fastcall UFG::RoadNetworkIntersection::GetRemainingGreenLightTime(UFG::RoadNetworkIntersection *this)
{
  char v1; // r8
  signed __int64 v2; // rdx
  __int64 v3; // rax
  char *v4; // r9
  __int64 v5; // rax
  signed __int64 v6; // r10
  __int64 v7; // rax
  signed __int64 v8; // rax
  __int64 v9; // rax
  char *v10; // r8
  __int64 v11; // rax
  signed __int64 v12; // r9
  __int64 v13; // rax

  v1 = this->mNumLightPhases;
  v2 = 0i64;
  if ( v1
    && ((v3 = this->mLightPhases.mOffset) == 0 ? (v4 = 0i64) : (v4 = (char *)&this->mLightPhases + v3),
        v5 = this->mCurrentPhaseIndex,
        v6 = (signed __int64)&v4[8 * v5],
        (v7 = *(_QWORD *)&v4[8 * v5]) != 0) )
  {
    v8 = v6 + v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( *(_DWORD *)(v8 + 24) != 2 )
    return FLOAT_N1_0;
  if ( v1 )
  {
    v9 = this->mLightPhases.mOffset;
    if ( v9 )
      v10 = (char *)&this->mLightPhases + v9;
    else
      v10 = 0i64;
    v11 = this->mCurrentPhaseIndex;
    v12 = (signed __int64)&v10[8 * v11];
    v13 = *(_QWORD *)&v10[8 * v11];
    if ( v13 )
      v2 = v13 + v12;
  }
  return *(float *)(v2 + 4) - this->mTimer;
}

// File Line: 2575
// RVA: 0xDD970
void __fastcall UFG::RoadNetworkIntersection::InitializePhases(UFG::RoadNetworkIntersection *this)
{
  UFG::RoadNetworkIntersection *v1; // rbx
  float v2; // xmm0_4
  signed __int64 v3; // rcx
  __int64 v4; // rax
  __int64 *v5; // rcx
  __int64 v6; // rax

  v1 = this;
  UFG::OnlineManager::Instance();
  v2 = UFG::qRandom((float)(unsigned __int8)v1->mNumLightPhases, &UFG::qDefaultSeed);
  v3 = 0i64;
  v1->mTimer = 0.0;
  v1->mCurrentPhaseIndex = (signed int)v2;
  if ( v1->mNumLightPhases )
  {
    v4 = v1->mLightPhases.mOffset;
    if ( v4 )
      v3 = (signed __int64)&v1->mLightPhases + v4;
    v5 = (__int64 *)(v3 + 8i64 * (unsigned int)(signed int)v2);
    v6 = *v5;
    if ( *v5 )
    {
      if ( (__int64 *)((char *)v5 + v6) )
        UFG::RoadNetworkIntersection::EnableLanes(v1, (UFG::RoadNetworkTrafficLightPhase *)((char *)v5 + v6), 0);
    }
  }
}

// File Line: 2602
// RVA: 0xE17E0
void __fastcall UFG::RoadNetworkIntersection::UpdateLights(UFG::RoadNetworkIntersection *this, float seconds, UFG::qVector3 *viewPosition, float visibleDistance)
{
  bool v4; // si
  char v5; // al
  UFG::RoadNetworkIntersection *v6; // rbx
  __int64 v7; // rax
  char *v8; // rcx
  __int64 v9; // r8
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  signed __int64 v12; // rdi
  signed __int64 v13; // rcx
  __int64 v14; // rax
  float v15; // xmm8_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  unsigned int v18; // ecx
  unsigned int v19; // eax
  UFG::RoadNetworkTrafficLightPhase *v20; // rax

  v4 = 0;
  v5 = this->mNumLightPhases;
  v6 = this;
  if ( (float)(visibleDistance * visibleDistance) > (float)((float)((float)((float)(viewPosition->x - this->mPosition.x)
                                                                          * (float)(viewPosition->x - this->mPosition.x))
                                                                  + (float)((float)(viewPosition->y - this->mPosition.y)
                                                                          * (float)(viewPosition->y - this->mPosition.y)))
                                                          + (float)((float)(viewPosition->z - this->mPosition.z)
                                                                  * (float)(viewPosition->z - this->mPosition.z))) )
    v4 = 1;
  if ( v5 && (v5 != 1 || this->mIsMerged) )
  {
    v7 = this->mLightPhases.mOffset;
    if ( v7 )
      v8 = (char *)&this->mLightPhases + v7;
    else
      v8 = 0i64;
    v9 = v6->mCurrentPhaseIndex;
    v10 = (signed __int64)&v8[8 * v9];
    v11 = *(_QWORD *)&v8[8 * v9];
    if ( v11 )
      v12 = v11 + v10;
    else
      v12 = 0i64;
    if ( v7 )
      v13 = (signed __int64)&v6->mLightPhases + v7;
    else
      v13 = 0i64;
    v14 = *(_QWORD *)(v13 + 8 * v9);
    if ( v14 )
      v14 += v13 + 8 * v9;
    v15 = *(float *)(v14 + 4);
    v16 = *(float *)(v14 + 4) + *(float *)(v14 + 8);
    if ( v6->mEnableTimer )
    {
      UFG::OnlineManager::Instance();
      v17 = seconds + v6->mTimer;
      v6->mTimer = v17;
      if ( v17 <= v16 )
      {
        if ( v17 > v15 && *(_DWORD *)(v12 + 24) == 2 )
          UFG::RoadNetworkTrafficLightPhase::SetLaneStatus((UFG::RoadNetworkTrafficLightPhase *)v12, YELLOW, v4);
      }
      else
      {
        v18 = (unsigned __int8)v6->mNumLightPhases;
        v19 = v6->mCurrentPhaseIndex + 1;
        v6->mTimer = 0.0;
        v6->mCurrentPhaseIndex = v19 % v18;
        v20 = UFG::RoadNetworkIntersection::GetTrafficLightPhase(v6, v19 % v18);
        UFG::RoadNetworkIntersection::EnableLanes(v6, v20, v4);
      }
    }
  }
}

// File Line: 2669
// RVA: 0xD4590
void __fastcall UFG::RoadNetworkIntersection::EnableLanes(UFG::RoadNetworkIntersection *this, UFG::RoadNetworkTrafficLightPhase *phase, bool updateTrafficLightEffects)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  __int64 v5; // rbx
  bool v6; // bp
  UFG::RoadNetworkTrafficLightPhase *v7; // r14
  UFG::RoadNetworkIntersection *v8; // rdi
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax
  UFG::RoadNetworkTrafficLightPhase *v12; // rcx
  unsigned int v13; // eax
  __int64 v14; // rdx
  __int64 v15; // r8
  __int64 v16; // rax
  signed __int64 v17; // rcx
  signed __int64 v18; // rax
  __int64 v19; // rcx
  signed __int64 v20; // rax
  unsigned int v21; // eax
  __int64 v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rax
  signed __int64 v25; // rcx
  signed __int64 v26; // rax
  __int64 v27; // rcx
  signed __int64 v28; // rax
  __int64 v29; // rbx
  __int64 v30; // rax
  signed __int64 v31; // rcx
  UFG::RoadNetworkTrafficLightLocation **v32; // rax
  UFG::RoadNetworkTrafficLightLocation *v33; // rcx

  LOBYTE(v3) = this->mNumLightPhases;
  v4 = phase->mIndex;
  v5 = 0i64;
  v6 = updateTrafficLightEffects;
  v7 = phase;
  v8 = this;
  if ( (_BYTE)v3 )
  {
    do
    {
      if ( (_DWORD)v5 != v4 )
      {
        if ( (_BYTE)v3
          && ((v9 = v8->mLightPhases.mOffset) == 0 ? (v10 = 0i64) : (v10 = (signed __int64)&v8->mLightPhases + v9),
              (v11 = *(_QWORD *)(v10 + 8 * v5)) != 0) )
        {
          v12 = (UFG::RoadNetworkTrafficLightPhase *)(v11 + v10 + 8 * v5);
        }
        else
        {
          v12 = 0i64;
        }
        UFG::RoadNetworkTrafficLightPhase::SetLaneStatus(v12, 0, v6);
      }
      v3 = (unsigned __int8)v8->mNumLightPhases;
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < v3 );
  }
  v13 = v7->mNumProtectedLanes;
  v7->mCurrentStatus = 2;
  if ( v13 )
  {
    v14 = 0i64;
    v15 = v13;
    do
    {
      v16 = v7->mProtectedLanes.mOffset;
      if ( v16 )
        v17 = (signed __int64)&v7->mProtectedLanes + v16;
      else
        v17 = 0i64;
      v18 = v14 + v17;
      v19 = *(_QWORD *)(v14 + v17);
      if ( v19 )
        v20 = v19 + v18;
      else
        v20 = 0i64;
      v14 += 8i64;
      *(_BYTE *)(v20 + 55) = 2;
      --v15;
    }
    while ( v15 );
  }
  v21 = v7->mNumPermissiveLanes;
  if ( v21 )
  {
    v22 = 0i64;
    v23 = v21;
    do
    {
      v24 = v7->mPermissiveLanes.mOffset;
      if ( v24 )
        v25 = (signed __int64)&v7->mPermissiveLanes + v24;
      else
        v25 = 0i64;
      v26 = v22 + v25;
      v27 = *(_QWORD *)(v22 + v25);
      if ( v27 )
        v28 = v27 + v26;
      else
        v28 = 0i64;
      v22 += 8i64;
      *(_BYTE *)(v28 + 55) = 2;
      --v23;
    }
    while ( v23 );
  }
  if ( v6 )
  {
    v29 = 0i64;
    if ( v7->mNumTrafficLights )
    {
      do
      {
        v30 = v7->mTrafficLightCollection.mOffset;
        if ( v30 )
          v31 = (signed __int64)&v7->mTrafficLightCollection + v30;
        else
          v31 = 0i64;
        v32 = *(UFG::RoadNetworkTrafficLightLocation ***)(v31 + 8 * v29);
        if ( v32 )
          v32 = (UFG::RoadNetworkTrafficLightLocation **)((char *)v32 + 8 * v29 + v31);
        v33 = *v32;
        if ( *v32 )
          v33 = (UFG::RoadNetworkTrafficLightLocation *)((char *)v33 + (_QWORD)v32);
        UFG::RoadNetworkTrafficLightLocation::SetLampEffect(v33, green, 0);
        v29 = (unsigned int)(v29 + 1);
      }
      while ( (unsigned int)v29 < v7->mNumTrafficLights );
    }
  }
}

// File Line: 2688
// RVA: 0xD8F60
float __fastcall UFG::RoadNetworkIntersection::GetIntersectionRadius(UFG::RoadNetworkIntersection *this)
{
  signed int v1; // ebx
  UFG::RoadNetworkIntersection *v2; // r8
  unsigned int v3; // edi
  __int64 v4; // rcx
  float v5; // xmm2_4
  __int64 v6; // rdx
  float v7; // xmm3_4
  float v8; // xmm4_4
  unsigned int v9; // eax
  __int64 v10; // r11
  signed __int64 v11; // rax
  signed __int64 v12; // r9
  __int64 v13; // rax
  signed __int64 v14; // r10
  signed __int64 v15; // rax
  signed __int64 v16; // r9
  __int64 v17; // rax
  signed __int64 v18; // r9
  signed __int64 v19; // r10
  signed __int64 v20; // rax
  signed __int64 v21; // r9
  __int64 v22; // rax
  signed __int64 v23; // r9
  signed __int64 v24; // r10
  signed __int64 v25; // rax
  signed __int64 v26; // r9
  __int64 v27; // rax
  signed __int64 v28; // r9
  signed __int64 v29; // r10
  __int64 v30; // r9
  float v31; // xmm3_4
  float v32; // xmm4_4
  signed __int64 v33; // rdx
  __int64 v34; // r10
  signed __int64 v35; // rax
  signed __int64 v36; // rcx
  __int64 v37; // rax

  v1 = (unsigned __int8)this->mNumGates;
  v2 = this;
  v3 = 0;
  v4 = 0i64;
  v5 = 0.0;
  if ( v1 >= 4 )
  {
    v6 = v2->mGates.mOffset;
    v7 = v2->mPosition.x;
    v8 = v2->mPosition.y;
    v9 = ((unsigned int)(v1 - 4) >> 2) + 1;
    v10 = v9;
    v3 = 4 * v9;
    do
    {
      if ( v6 )
        v11 = (signed __int64)&v2->mGates + v6;
      else
        v11 = 0i64;
      v12 = v11 + 8 * v4;
      v13 = *(_QWORD *)(v11 + 8 * v4);
      if ( v13 )
        v14 = v13 + v12;
      else
        v14 = 0i64;
      if ( (float)((float)((float)(*(float *)(v14 + 28) - v8) * (float)(*(float *)(v14 + 28) - v8))
                 + (float)((float)(*(float *)(v14 + 24) - v7) * (float)(*(float *)(v14 + 24) - v7))) > v5 )
        v5 = (float)((float)(*(float *)(v14 + 28) - v8) * (float)(*(float *)(v14 + 28) - v8))
           + (float)((float)(*(float *)(v14 + 24) - v7) * (float)(*(float *)(v14 + 24) - v7));
      if ( v6 )
        v15 = (signed __int64)&v2->mGates + v6;
      else
        v15 = 0i64;
      v16 = v15 + 8;
      v17 = *(_QWORD *)(v15 + 8 + 8 * v4);
      v18 = v16 + 8 * v4;
      if ( v17 )
        v19 = v17 + v18;
      else
        v19 = 0i64;
      if ( (float)((float)((float)(*(float *)(v19 + 28) - v8) * (float)(*(float *)(v19 + 28) - v8))
                 + (float)((float)(*(float *)(v19 + 24) - v7) * (float)(*(float *)(v19 + 24) - v7))) > v5 )
        v5 = (float)((float)(*(float *)(v19 + 28) - v8) * (float)(*(float *)(v19 + 28) - v8))
           + (float)((float)(*(float *)(v19 + 24) - v7) * (float)(*(float *)(v19 + 24) - v7));
      if ( v6 )
        v20 = (signed __int64)&v2->mGates + v6;
      else
        v20 = 0i64;
      v21 = v20 + 16;
      v22 = *(_QWORD *)(v20 + 16 + 8 * v4);
      v23 = v21 + 8 * v4;
      if ( v22 )
        v24 = v22 + v23;
      else
        v24 = 0i64;
      if ( (float)((float)((float)(*(float *)(v24 + 28) - v8) * (float)(*(float *)(v24 + 28) - v8))
                 + (float)((float)(*(float *)(v24 + 24) - v7) * (float)(*(float *)(v24 + 24) - v7))) > v5 )
        v5 = (float)((float)(*(float *)(v24 + 28) - v8) * (float)(*(float *)(v24 + 28) - v8))
           + (float)((float)(*(float *)(v24 + 24) - v7) * (float)(*(float *)(v24 + 24) - v7));
      if ( v6 )
        v25 = (signed __int64)&v2->mGates + v6;
      else
        v25 = 0i64;
      v26 = v25 + 24;
      v27 = *(_QWORD *)(v25 + 24 + 8 * v4);
      v28 = v26 + 8 * v4;
      if ( v27 )
        v29 = v27 + v28;
      else
        v29 = 0i64;
      if ( (float)((float)((float)(*(float *)(v29 + 28) - v8) * (float)(*(float *)(v29 + 28) - v8))
                 + (float)((float)(*(float *)(v29 + 24) - v7) * (float)(*(float *)(v29 + 24) - v7))) > v5 )
        v5 = (float)((float)(*(float *)(v29 + 28) - v8) * (float)(*(float *)(v29 + 28) - v8))
           + (float)((float)(*(float *)(v29 + 24) - v7) * (float)(*(float *)(v29 + 24) - v7));
      v4 += 4i64;
      --v10;
    }
    while ( v10 );
  }
  if ( v3 < v1 )
  {
    v30 = v2->mGates.mOffset;
    v33 = 8 * v4;
    v34 = v1 - v3;
    do
    {
      if ( v30 )
        v35 = (signed __int64)&v2->mGates + v30;
      else
        v35 = 0i64;
      v36 = v33 + v35;
      v37 = *(_QWORD *)(v33 + v35);
      if ( v37 )
        v37 += v36;
      v31 = v2->mPosition.x;
      v32 = v2->mPosition.y;
      if ( (float)((float)((float)(*(float *)(v37 + 28) - v32) * (float)(*(float *)(v37 + 28) - v32))
                 + (float)((float)(*(float *)(v37 + 24) - v31) * (float)(*(float *)(v37 + 24) - v31))) > v5 )
        v5 = (float)((float)(*(float *)(v37 + 28) - v32) * (float)(*(float *)(v37 + 28) - v32))
           + (float)((float)(*(float *)(v37 + 24) - v31) * (float)(*(float *)(v37 + 24) - v31));
      v33 += 8i64;
      --v34;
    }
    while ( v34 );
  }
  return fsqrt(v5);
}

// File Line: 2702
// RVA: 0xD5F70
UFG::RoadNetworkGate *__fastcall UFG::RoadNetworkIntersection::GetClosestGate(UFG::RoadNetworkIntersection *this, UFG::qVector3 *pos)
{
  signed int v2; // ebx
  float v3; // xmm2_4
  UFG::qVector3 *v4; // rdi
  __int64 v5; // r11
  unsigned int v6; // esi
  __int64 v7; // rdx
  UFG::RoadNetworkIntersection *v8; // r10
  __int64 v9; // r8
  float v10; // xmm3_4
  float v11; // xmm4_4
  unsigned int v12; // eax
  __int64 v13; // r9
  signed __int64 v14; // rax
  signed __int64 v15; // rcx
  __int64 v16; // rax
  signed __int64 v17; // rax
  signed __int64 v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // rcx
  signed __int64 v21; // rax
  signed __int64 v22; // rcx
  __int64 v23; // rax
  signed __int64 v24; // rcx
  signed __int64 v25; // rax
  signed __int64 v26; // rcx
  __int64 v27; // rax
  signed __int64 v28; // rcx
  __int64 v29; // r8
  float v30; // xmm3_4
  float v31; // xmm4_4
  signed __int64 v32; // rdx
  __int64 v33; // r9
  signed __int64 v34; // rax
  signed __int64 v35; // rcx
  __int64 v36; // rax

  v2 = (unsigned __int8)this->mNumGates;
  v3 = FLOAT_3_4028235e38;
  v4 = pos;
  v5 = 0i64;
  v6 = 0;
  v7 = 0i64;
  v8 = this;
  if ( v2 >= 4 )
  {
    v9 = this->mGates.mOffset;
    v10 = v4->x;
    v11 = v4->y;
    v12 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v13 = v12;
    v6 = 4 * v12;
    do
    {
      if ( v9 )
        v14 = (signed __int64)&v8->mGates + v9;
      else
        v14 = 0i64;
      v15 = v14 + 8 * v7;
      v16 = *(_QWORD *)(v14 + 8 * v7);
      if ( v16 )
        v16 += v15;
      if ( (float)((float)((float)(*(float *)(v16 + 28) - v11) * (float)(*(float *)(v16 + 28) - v11))
                 + (float)((float)(*(float *)(v16 + 24) - v10) * (float)(*(float *)(v16 + 24) - v10))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v16 + 28) - v11) * (float)(*(float *)(v16 + 28) - v11))
           + (float)((float)(*(float *)(v16 + 24) - v10) * (float)(*(float *)(v16 + 24) - v10));
        v5 = v16;
      }
      if ( v9 )
        v17 = (signed __int64)&v8->mGates + v9;
      else
        v17 = 0i64;
      v18 = v17 + 8;
      v19 = *(_QWORD *)(v17 + 8 + 8 * v7);
      v20 = v18 + 8 * v7;
      if ( v19 )
        v19 += v20;
      if ( (float)((float)((float)(*(float *)(v19 + 28) - v11) * (float)(*(float *)(v19 + 28) - v11))
                 + (float)((float)(*(float *)(v19 + 24) - v10) * (float)(*(float *)(v19 + 24) - v10))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v19 + 28) - v11) * (float)(*(float *)(v19 + 28) - v11))
           + (float)((float)(*(float *)(v19 + 24) - v10) * (float)(*(float *)(v19 + 24) - v10));
        v5 = v19;
      }
      if ( v9 )
        v21 = (signed __int64)&v8->mGates + v9;
      else
        v21 = 0i64;
      v22 = v21 + 16;
      v23 = *(_QWORD *)(v21 + 16 + 8 * v7);
      v24 = v22 + 8 * v7;
      if ( v23 )
        v23 += v24;
      if ( (float)((float)((float)(*(float *)(v23 + 28) - v11) * (float)(*(float *)(v23 + 28) - v11))
                 + (float)((float)(*(float *)(v23 + 24) - v10) * (float)(*(float *)(v23 + 24) - v10))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v23 + 28) - v11) * (float)(*(float *)(v23 + 28) - v11))
           + (float)((float)(*(float *)(v23 + 24) - v10) * (float)(*(float *)(v23 + 24) - v10));
        v5 = v23;
      }
      if ( v9 )
        v25 = (signed __int64)&v8->mGates + v9;
      else
        v25 = 0i64;
      v26 = v25 + 24;
      v27 = *(_QWORD *)(v25 + 24 + 8 * v7);
      v28 = v26 + 8 * v7;
      if ( v27 )
        v27 += v28;
      if ( (float)((float)((float)(*(float *)(v27 + 28) - v11) * (float)(*(float *)(v27 + 28) - v11))
                 + (float)((float)(*(float *)(v27 + 24) - v10) * (float)(*(float *)(v27 + 24) - v10))) < v3 )
      {
        v3 = (float)((float)(*(float *)(v27 + 28) - v11) * (float)(*(float *)(v27 + 28) - v11))
           + (float)((float)(*(float *)(v27 + 24) - v10) * (float)(*(float *)(v27 + 24) - v10));
        v5 = v27;
      }
      v7 += 4i64;
      --v13;
    }
    while ( v13 );
  }
  if ( v6 < v2 )
  {
    v29 = v8->mGates.mOffset;
    v32 = 8 * v7;
    v33 = v2 - v6;
    do
    {
      if ( v29 )
        v34 = (signed __int64)&v8->mGates + v29;
      else
        v34 = 0i64;
      v35 = v32 + v34;
      v36 = *(_QWORD *)(v32 + v34);
      if ( v36 )
        v36 += v35;
      v30 = v4->x;
      v31 = v4->y;
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
void __fastcall UFG::RoadNetworkIntersection::AddLanesToGateModification(UFG::RoadNetworkIntersection *this, const unsigned int gateIndex, unsigned int flags)
{
  unsigned int v3; // er12
  unsigned int v4; // er13
  UFG::RoadNetworkIntersection *v5; // rbp
  char *v6; // r15
  unsigned int v7; // esi
  unsigned int v8; // ebx
  unsigned __int64 v9; // rax
  bool v10; // zf
  unsigned int v11; // edi
  __int64 v12; // rax
  signed __int64 v13; // rcx
  _QWORD *v14; // rax
  char *v15; // rax
  __int64 v16; // rcx
  signed __int64 v17; // rbx
  unsigned int *v18; // r14
  UFG::RoadNetworkConnection *v19; // rax
  __int64 v20; // rcx
  signed __int64 v21; // rdx
  __int64 v22; // rax
  _QWORD *v23; // rax
  char *v24; // rcx
  char *v25; // rax
  char *v26; // rbx
  void *v27; // rcx
  __int64 v28; // rdi
  unsigned __int64 v29; // rax
  __int64 v30; // rdx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v31; // rax
  unsigned int v32; // [rsp+70h] [rbp+8h]

  v3 = flags;
  v4 = gateIndex;
  v5 = this;
  v6 = 0i64;
  v7 = (unsigned __int8)this->mNumLanes;
  v32 = v7;
  if ( (signed int)v7 <= 0 )
  {
    v10 = v7 == 0;
    v7 = 0;
    if ( !v10 )
      v7 = 0;
    v32 = 0;
  }
  else
  {
    v8 = 1;
    if ( v7 <= 1 )
      goto LABEL_55;
    do
      v8 *= 2;
    while ( v8 < v7 );
    if ( v8 <= 4 )
LABEL_55:
      v8 = 4;
    if ( v8 - v7 > 0x10000 )
      v8 = v7 + 0x10000;
    if ( v8 )
    {
      v9 = 4i64 * v8;
      if ( !is_mul_ok(v8, 4ui64) )
        v9 = -1i64;
      v6 = UFG::qMalloc(v9, "RoadNetworkIntersection", 0i64);
    }
  }
  v11 = 0;
  if ( v5->mNumLanes > 0u )
  {
    do
    {
      v12 = v5->mLane.mOffset;
      if ( v12 )
        v13 = (signed __int64)&v5->mLane + v12;
      else
        v13 = 0i64;
      v14 = (_QWORD *)(v13 + 8i64 * v11);
      if ( *v14 )
        v15 = (char *)v14 + *v14;
      else
        v15 = 0i64;
      v16 = *((_QWORD *)v15 + 13);
      if ( v16 )
        v17 = (signed __int64)&v15[v16 + 104];
      else
        v17 = 0i64;
      v18 = (unsigned int *)&v6[4 * v11];
      *v18 = (unsigned __int8)v15[44];
      v19 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v5, v4);
      v20 = v19->mLaneList.mOffset;
      if ( v20 )
        v21 = (signed __int64)&v19->mLaneList + v20;
      else
        v21 = 0i64;
      v22 = *(_QWORD *)(v17 + 24);
      if ( v22 )
        v23 = (_QWORD *)(v17 + v22 + 24);
      else
        v23 = 0i64;
      if ( *v23 )
        v24 = (char *)v23 + *v23;
      else
        v24 = 0i64;
      if ( v24 == (char *)v21 )
        *v18 = v3;
      ++v11;
    }
    while ( v11 < (unsigned __int8)v5->mNumLanes );
    v7 = v32;
  }
  v25 = UFG::qMalloc(0x30ui64, "RoadNetworkIntersection.RoadNetworkIntersectionModification", 0i64);
  v26 = v25;
  if ( v25 )
  {
    *(_QWORD *)v25 = v25;
    *((_QWORD *)v25 + 1) = v25;
    *((_QWORD *)v25 + 3) = 0i64;
    *((_QWORD *)v25 + 2) = 0i64;
    *((_QWORD *)v25 + 4) = v5;
    v27 = (void *)*((_QWORD *)v25 + 3);
    if ( v27 )
      operator delete[](v27);
    *((_QWORD *)v26 + 3) = 0i64;
    *((_QWORD *)v26 + 2) = 0i64;
    if ( v7 )
    {
      *((_DWORD *)v26 + 4) = v7;
      v28 = v7;
      v29 = 4i64 * v7;
      if ( !is_mul_ok(v7, 4ui64) )
        v29 = -1i64;
      *((_QWORD *)v26 + 3) = UFG::qMalloc(v29, "qArray.Clone", 0i64);
      *((_DWORD *)v26 + 5) = v7;
      if ( v7 )
      {
        v30 = 0i64;
        do
        {
          *(_DWORD *)(v30 + *((_QWORD *)v26 + 3)) = *(_DWORD *)&v6[v30];
          v30 += 4i64;
          --v28;
        }
        while ( v28 );
      }
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
  v31 = v5->mModifications.mNode.mPrev;
  v31->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v26;
  *(_QWORD *)v26 = v31;
  *((_QWORD *)v26 + 1) = (char *)v5 + 80;
  v5->mModifications.mNode.mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v26;
  UFG::RoadNetworkIntersection::ApplyModification(v5, (UFG::RoadNetworkNodeModification *)v26);
  if ( v6 )
    operator delete[](v6);
}

// File Line: 2765
// RVA: 0xD1DF0
void __fastcall UFG::RoadNetworkIntersection::AddPhaseModification(UFG::RoadNetworkIntersection *this, UFG::RoadNetworkIntersectionModification::AllPhaseStatus status)
{
  UFG::RoadNetworkIntersectionModification::AllPhaseStatus v2; // esi
  UFG::RoadNetworkIntersection *v3; // rdi
  char *v4; // rax
  char *v5; // rbx
  UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *v6; // rax

  v2 = status;
  v3 = this;
  v4 = UFG::qMalloc(0x30ui64, "RoadNetworkIntersection.RoadNetworkIntersectionModification", 0i64);
  v5 = v4;
  if ( v4 )
  {
    UFG::RoadNetworkNodeModification::RoadNetworkNodeModification(
      (UFG::RoadNetworkNodeModification *)v4,
      (UFG::RoadNetworkNode *)&v3->mType);
    *((_DWORD *)v5 + 10) = v2;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v3->mModifications.mNode.mPrev;
  v6->mNext = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5;
  *(_QWORD *)v5 = v6;
  *((_QWORD *)v5 + 1) = (char *)v3 + 80;
  v3->mModifications.mNode.mPrev = (UFG::qNode<UFG::RoadNetworkNodeModification,UFG::RoadNetworkNodeModification> *)v5;
  UFG::RoadNetworkIntersection::ApplyModification(v3, (UFG::RoadNetworkNodeModification *)v5);
}

// File Line: 2773
// RVA: 0xD23F0
void __fastcall UFG::RoadNetworkIntersection::ApplyModification(UFG::RoadNetworkIntersection *this, UFG::RoadNetworkNodeModification *modification)
{
  UFG::RoadNetworkNodeModification *v2; // r10
  UFG::RoadNetworkIntersection *v3; // rbx
  unsigned int v4; // er8
  __int64 v5; // rax
  signed __int64 v6; // rcx
  __int64 v7; // r9
  signed __int64 v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // rdx
  int v11; // eax
  char v12; // r9
  unsigned int v13; // ecx
  __int64 v14; // rax
  signed __int64 v15; // rdx
  __int64 v16; // rax
  signed __int64 v17; // rax

  v2 = modification;
  v3 = this;
  if ( modification->mLaneFlagsCollection.size )
  {
    v4 = 0;
    if ( this->mNumLanes > 0u )
    {
      do
      {
        v5 = v3->mLane.mOffset;
        if ( v5 )
          v6 = (signed __int64)&v3->mLane + v5;
        else
          v6 = 0i64;
        v7 = v4;
        v8 = v6 + 8i64 * v4;
        v9 = *(_QWORD *)(v6 + 8i64 * v4);
        v10 = v9 + v8;
        if ( !v9 )
          v10 = 0i64;
        ++v4;
        *(_BYTE *)(v10 + 44) = v2->mLaneFlagsCollection.p[v7];
      }
      while ( v4 < (unsigned __int8)v3->mNumLanes );
    }
  }
  v11 = (int)v2[1].mPrev;
  if ( v11 )
  {
    v12 = 2;
    v3->mEnableTimer = 0;
    if ( v11 == 2 )
    {
      v12 = 1;
    }
    else if ( v11 == 1 )
    {
      v12 = 0;
    }
    v13 = 0;
    if ( v3->mNumLanes > 0u )
    {
      do
      {
        v14 = v3->mLane.mOffset;
        if ( v14 )
          v15 = (signed __int64)&v3->mLane + v14;
        else
          v15 = 0i64;
        v16 = *(_QWORD *)(v15 + 8i64 * v13);
        if ( v16 )
          v17 = v15 + 8i64 * v13 + v16;
        else
          v17 = 0i64;
        *(_BYTE *)(v17 + 55) = v12;
        ++v13;
      }
      while ( v13 < (unsigned __int8)v3->mNumLanes );
    }
  }
  else
  {
    UFG::RoadNetworkIntersection::InitializePhases(v3);
    v3->mEnableTimer = 1;
  }
}

// File Line: 2974
// RVA: 0xD87C0
char __fastcall UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(UFG::RoadNetworkIntersection *this)
{
  unsigned int v1; // er11
  unsigned int v2; // edx
  __int64 v3; // r10
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *v4; // rbx
  __int64 v5; // r9
  char *v6; // rax
  char *v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // r8

  v1 = (unsigned __int8)this->mNumGates;
  v2 = 0;
  if ( !this->mNumGates )
    return 0;
  v3 = this->mGates.mOffset;
  v4 = &this->mGates;
  v5 = 0i64;
  while ( 1 )
  {
    v6 = (char *)(v3 ? (UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *)((char *)v4 + v3) : 0i64);
    v7 = &v6[v5];
    v8 = *(_QWORD *)&v6[v5];
    if ( v8 )
      v8 += (__int64)v7;
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 )
    {
      v10 = v9 + v8 + 8;
      if ( v10 )
      {
        if ( (*(_DWORD *)(v10 + 168) >> 6) & 1 )
          break;
      }
    }
    ++v2;
    v5 += 8i64;
    if ( v2 >= v1 )
      return 0;
  }
  return 1;
}

// File Line: 2993
// RVA: 0xD5E30
bool __fastcall UFG::RoadNetworkIntersection::GetBuildVisibleRoadNetworkByGrid(UFG::RoadNetworkIntersection *this)
{
  unsigned int v1; // ebx
  bool result; // al
  unsigned int v3; // er9
  __int64 v4; // r11
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *v5; // rdi
  __int64 v6; // r10
  char *v7; // rcx
  char *v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // rdx
  signed __int64 v11; // r8

  v1 = (unsigned __int8)this->mNumGates;
  result = 0;
  v3 = 0;
  if ( this->mNumGates )
  {
    v4 = this->mGates.mOffset;
    v5 = &this->mGates;
    v6 = 0i64;
    do
    {
      if ( v4 )
        v7 = (char *)v5 + v4;
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
          result = (*(_DWORD *)(v11 + 168) >> 5) & 1;
          if ( result )
            break;
        }
      }
      ++v3;
      v6 += 8i64;
    }
    while ( v3 < v1 );
  }
  return result;
}

// File Line: 3012
// RVA: 0xDEE50
char __fastcall UFG::RoadNetworkIntersection::IsWater(UFG::RoadNetworkIntersection *this)
{
  __int64 v1; // rdi
  UFG::RoadNetworkIntersection *v2; // rsi
  __int64 v3; // rax
  signed __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rcx
  UFG::RoadNetworkSegment *v7; // rcx
  unsigned int v8; // ebx
  UFG::qPropertySet *v9; // rax
  unsigned int *v10; // rax

  v1 = 0i64;
  v2 = this;
  if ( !this->mNumGates )
    return 0;
  while ( 1 )
  {
    v3 = v2->mGates.mOffset;
    if ( v3 )
      v4 = (signed __int64)&v2->mGates + v3;
    else
      v4 = 0i64;
    v5 = *(_QWORD *)(v4 + 8 * v1);
    if ( v5 )
      v5 += v4 + 8 * v1;
    v6 = *(_QWORD *)(v5 + 8);
    if ( v6 )
    {
      v7 = (UFG::RoadNetworkSegment *)(v5 + v6 + 8);
      if ( v7 )
      {
        if ( v7->mpPropertySetCached )
        {
          v8 = v7->mRoadNetworkType.mValue;
        }
        else
        {
          v9 = UFG::RoadNetworkSegment::GetRoadPropertySet(v7);
          v8 = 0;
          if ( v9 )
          {
            v10 = UFG::qPropertySet::Get<unsigned long>(
                    v9,
                    (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID,
                    DEPTH_RECURSE);
            if ( v10 )
              v8 = *v10;
          }
        }
        if ( v8 - 2 <= 1 )
          break;
      }
    }
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= (unsigned __int8)v2->mNumGates )
      return 0;
  }
  return 1;
}

// File Line: 3122
// RVA: 0xE0850
void __fastcall UFG::RoadNetworkTrafficLightPhase::SetLaneStatus(UFG::RoadNetworkTrafficLightPhase *this, UFG::RoadNetworkLane::LaneStatus laneStatus, bool updateTrafficLightEffects)
{
  unsigned int v3; // eax
  bool v4; // r11
  UFG::RoadNetworkLane::LaneStatus v5; // ebx
  UFG::RoadNetworkTrafficLightPhase *v6; // rsi
  __int64 v7; // r9
  __int64 v8; // r10
  __int64 v9; // rax
  signed __int64 v10; // rcx
  signed __int64 v11; // rax
  __int64 v12; // rcx
  signed __int64 v13; // rax
  unsigned int v14; // eax
  __int64 v15; // rdx
  __int64 v16; // r8
  __int64 v17; // rax
  signed __int64 v18; // rcx
  signed __int64 v19; // rax
  __int64 v20; // rcx
  signed __int64 v21; // rax
  __int64 v22; // rdi
  __int64 v23; // rax
  signed __int64 v24; // rcx
  UFG::RoadNetworkTrafficLightLocation **v25; // rax
  UFG::RoadNetworkTrafficLightLocation *v26; // rcx
  UFG::RoadNetworkTrafficLightLampData::TrafficLightColour v27; // edx

  v3 = this->mNumProtectedLanes;
  v4 = updateTrafficLightEffects;
  v5 = laneStatus;
  v6 = this;
  this->mCurrentStatus = laneStatus;
  if ( v3 )
  {
    v7 = 0i64;
    v8 = v3;
    do
    {
      v9 = v6->mProtectedLanes.mOffset;
      if ( v9 )
        v10 = (signed __int64)&v6->mProtectedLanes + v9;
      else
        v10 = 0i64;
      v11 = v7 + v10;
      v12 = *(_QWORD *)(v7 + v10);
      if ( v12 )
        v13 = v12 + v11;
      else
        v13 = 0i64;
      v7 += 8i64;
      *(_BYTE *)(v13 + 55) = laneStatus;
      --v8;
    }
    while ( v8 );
  }
  v14 = v6->mNumPermissiveLanes;
  if ( v14 )
  {
    v15 = 0i64;
    v16 = v14;
    do
    {
      v17 = v6->mPermissiveLanes.mOffset;
      if ( v17 )
        v18 = (signed __int64)&v6->mPermissiveLanes + v17;
      else
        v18 = 0i64;
      v19 = v15 + v18;
      v20 = *(_QWORD *)(v15 + v18);
      if ( v20 )
        v21 = v20 + v19;
      else
        v21 = 0i64;
      v15 += 8i64;
      *(_BYTE *)(v21 + 55) = v5;
      --v16;
    }
    while ( v16 );
  }
  if ( v4 )
  {
    v22 = 0i64;
    if ( v6->mNumTrafficLights )
    {
      do
      {
        v23 = v6->mTrafficLightCollection.mOffset;
        if ( v23 )
          v24 = (signed __int64)&v6->mTrafficLightCollection + v23;
        else
          v24 = 0i64;
        v25 = *(UFG::RoadNetworkTrafficLightLocation ***)(v24 + 8 * v22);
        if ( v25 )
          v25 = (UFG::RoadNetworkTrafficLightLocation **)((char *)v25 + 8 * v22 + v24);
        v26 = *v25;
        if ( *v25 )
          v26 = (UFG::RoadNetworkTrafficLightLocation *)((char *)v26 + (_QWORD)v25);
        if ( v5 )
        {
          if ( v5 == 1 )
          {
            v27 = 1;
          }
          else
          {
            v27 = 3;
            if ( v5 == 2 )
              v27 = 2;
          }
        }
        else
        {
          v27 = 0;
        }
        UFG::RoadNetworkTrafficLightLocation::SetLampEffect(v26, v27, 0);
        v22 = (unsigned int)(v22 + 1);
      }
      while ( (unsigned int)v22 < v6->mNumTrafficLights );
    }
  }
}

// File Line: 3154
// RVA: 0x1460950
hkSeekableStreamReader *dynamic_initializer_for__UFG::RoadNetworkTrafficLightLampData::trafficLight001__()
{
  hkSeekableStreamReader *v0; // rbx
  signed int v1; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::RoadNetworkTrafficLightLampData::trafficLight001;
  v1 = 2;
  do
  {
    result = Assembly::GetRCX(v0);
    v0 += 4;
    --v1;
  }
  while ( v1 >= 0 );
  return result;
}

// File Line: 3155
// RVA: 0x1460990
hkSeekableStreamReader *dynamic_initializer_for__UFG::RoadNetworkTrafficLightLampData::trafficLight002__()
{
  hkSeekableStreamReader *v0; // rbx
  signed int v1; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::RoadNetworkTrafficLightLampData::trafficLight002;
  v1 = 2;
  do
  {
    result = Assembly::GetRCX(v0);
    v0 += 4;
    --v1;
  }
  while ( v1 >= 0 );
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
__int64 __fastcall UFG::RoadNetworkTrafficLightLampData::GetLampEffectUID(UFG::RoadNetworkTrafficLightLampData::TrafficLightColour colour)
{
  UFG::RoadNetworkTrafficLightLampData::TrafficLightColour v1; // ebx
  unsigned int v2; // eax
  __int64 result; // rax

  v1 = colour;
  v2 = _S8_1;
  if ( !(_S8_1 & 1) )
  {
    _S8_1 |= 1u;
    redUID = UFG::qStringHashUpper32("HK_Stoplight_Red_01_Effect", 0xFFFFFFFF);
    v2 = _S8_1;
  }
  if ( !(v2 & 2) )
  {
    _S8_1 = v2 | 2;
    yellowUID = UFG::qStringHashUpper32("HK_Stoplight_Yellow_01_Effect", 0xFFFFFFFF);
    v2 = _S8_1;
  }
  if ( v2 & 4 )
  {
    result = greenUID;
  }
  else
  {
    _S8_1 = v2 | 4;
    result = UFG::qStringHashUpper32("HK_Stoplight_Green_01_Effect", 0xFFFFFFFF);
    greenUID = result;
  }
  if ( v1 != 2 )
  {
    result = redUID;
    if ( v1 == 1 )
      result = yellowUID;
  }
  return result;
}

// File Line: 3232
// RVA: 0xD5C60
__int64 __fastcall UFG::RoadNetworkTrafficLightLampData::GetArrowEffectUID()
{
  __int64 result; // rax

  if ( _S9_0 & 1 )
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
  this->mFlags &= 0xFFFFFFFB;
}

// File Line: 3258
// RVA: 0xD4530
void __fastcall UFG::RoadNetworkTrafficLightLocation::DisableEffects(UFG::RoadNetworkTrafficLightLocation *this)
{
  unsigned int v1; // edx
  UFG::RoadNetworkTrafficLightLocation *v2; // rbx
  unsigned int v3; // edx

  v1 = this->mVehicleSignalEffect;
  v2 = this;
  if ( v1 != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, v1, 0);
    v2->mVehicleSignalEffect = -1;
  }
  v3 = v2->mPedestrianSignalEffect;
  if ( v3 != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, v3, 0);
    v2->mPedestrianSignalEffect = -1;
  }
  v2->mFlags |= 4u;
}

// File Line: 3299
// RVA: 0xE04C0
void __fastcall UFG::RoadNetworkTrafficLightLocation::SetLampEffect(UFG::RoadNetworkTrafficLightLocation *this, UFG::RoadNetworkTrafficLightLampData::TrafficLightColour colour, UFG::RoadNetworkLane::LaneTurnDirection turnDirection)
{
  __int64 v3; // rdi
  unsigned int v4; // edx
  UFG::RoadNetworkLane::LaneTurnDirection v5; // esi
  UFG::RoadNetworkTrafficLightLocation *v6; // rbx
  unsigned int v7; // edx
  unsigned int v8; // eax
  bool v9; // zf
  hkSeekableStreamReader *v10; // rax
  float v11; // xmm6_4
  __m128 v12; // xmm5
  float v13; // xmm7_4
  __m128 v14; // xmm2
  float v15; // xmm1_4
  __m128 v16; // xmm8
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  __m128 v20; // xmm2
  float v21; // xmm0_4
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  float v24; // xmm10_4
  float v25; // xmm10_4
  __m128 v26; // xmm11
  float v27; // xmm10_4
  __m128 v28; // xmm8
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  __m128 v32; // xmm9
  float v33; // xmm2_4
  float v34; // xmm8_4
  __m128 v35; // xmm5
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  unsigned int v40; // eax
  UFG::qMatrix44 b; // [rsp+30h] [rbp-E8h]
  UFG::qMatrix44 result; // [rsp+70h] [rbp-A8h]

  v3 = colour;
  v4 = this->mVehicleSignalEffect;
  v5 = turnDirection;
  v6 = this;
  if ( v4 != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, v4, 0);
    v6->mVehicleSignalEffect = -1;
  }
  v7 = v6->mPedestrianSignalEffect;
  if ( v7 != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, v7, 0);
    v6->mPedestrianSignalEffect = -1;
  }
  v8 = v6->mFlags;
  if ( !(v8 & 4) )
  {
    if ( v8 & 1 || (v9 = (v8 & 2) == 0, v10 = &UFG::RoadNetworkTrafficLightLampData::trafficLight002, v9) )
      v10 = &UFG::RoadNetworkTrafficLightLampData::trafficLight001;
    v11 = v6->mDirection.y;
    v12 = (__m128)LODWORD(v6->mDirection.x);
    v13 = v6->mDirection.z;
    v14 = v12;
    v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
    if ( v14.m128_f32[0] == 0.0 )
      v15 = 0.0;
    else
      v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
    v16 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    v17 = v12.m128_f32[0] * v15;
    v18 = v11 * v15;
    v19 = v13 * v15;
    b.v0.w = 0.0;
    v20 = v16;
    b.v0.x = v17;
    b.v0.y = v18;
    b.v0.z = v19;
    v20.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
    if ( v20.m128_f32[0] == 0.0 )
    {
      v22 = 0i64;
    }
    else
    {
      LODWORD(v21) = (unsigned __int128)_mm_sqrt_ps(v20);
      v22 = (__m128)(unsigned int)FLOAT_1_0;
      v22.m128_f32[0] = 1.0 / v21;
    }
    v23 = v22;
    v24 = v22.m128_f32[0];
    v22.m128_f32[0] = v22.m128_f32[0] * UFG::qVector3::msDirUp.z;
    v25 = v24 * UFG::qVector3::msDirUp.x;
    v23.m128_f32[0] = v23.m128_f32[0] * UFG::qVector3::msDirUp.y;
    v26 = v23;
    v26.m128_f32[0] = (float)(v23.m128_f32[0] * v19) - (float)(v22.m128_f32[0] * v18);
    v22.m128_f32[0] = (float)(v22.m128_f32[0] * v17) - (float)(v25 * v19);
    v27 = (float)(v25 * v18) - (float)(v23.m128_f32[0] * v17);
    v28 = v22;
    v28.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v26.m128_f32[0] * v26.m128_f32[0]))
                    + (float)(v27 * v27);
    if ( v28.m128_f32[0] == 0.0 )
      v29 = 0.0;
    else
      v29 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
    v26.m128_f32[0] = v26.m128_f32[0] * v29;
    v30 = v22.m128_f32[0] * v29;
    b.v1.w = 0.0;
    v32 = v26;
    b.v1.z = v27 * v29;
    LODWORD(b.v1.x) = v26.m128_i32[0];
    b.v1.y = v30;
    v31 = v30 * v19;
    v32.m128_f32[0] = (float)(v26.m128_f32[0] * v19) - (float)((float)(v27 * v29) * v17);
    v33 = (float)(v30 * v17) - (float)(v26.m128_f32[0] * v18);
    v34 = (float)((float)(v27 * v29) * v18) - v31;
    v35 = v32;
    v35.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v34 * v34)) + (float)(v33 * v33);
    if ( v35.m128_f32[0] == 0.0 )
      v36 = 0.0;
    else
      v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
    v37 = v6->mPosition.x;
    v38 = v6->mPosition.y;
    b.v2.w = 0.0;
    b.v3.w = 1.0;
    b.v3.x = v37;
    v39 = v6->mPosition.z;
    b.v3.y = v38;
    b.v3.z = v39;
    b.v2.x = v34 * v36;
    b.v2.y = v32.m128_f32[0] * v36;
    b.v2.z = v33 * v36;
    UFG::qMatrix44::operator*((UFG::qMatrix44 *)&v10[4 * v3], &result, &b);
    if ( (_DWORD)v3 != 2 || v5 != 2 )
      v40 = UFG::RoadNetworkTrafficLightLampData::GetLampEffectUID((UFG::RoadNetworkTrafficLightLampData::TrafficLightColour)v3);
    else
      v40 = UFG::RoadNetworkTrafficLightLampData::GetArrowEffectUID();
    v6->mVehicleSignalEffect = Render::FXManager::CreateEffect(&Render::gFXManager, v40, &result, 0xFFFFFFFF);
  }
}

// File Line: 3336
// RVA: 0xDC5C0
void __fastcall UFG::RoadNetworkConnection::GetValidLanes(UFG::RoadNetworkConnection *this, unsigned int laneFlags, UFG::qArray<unsigned long,0> *laneIDs)
{
  __int64 v3; // r14
  UFG::qArray<unsigned long,0> *v4; // rdi
  unsigned __int8 v5; // r12
  UFG::RoadNetworkConnection *v6; // r13
  __int64 v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // r15
  unsigned int v11; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  char *v15; // rax
  unsigned int *v16; // rbp
  signed __int64 v17; // r9
  signed __int64 v18; // r8
  unsigned int *v19; // rax

  v3 = 0i64;
  laneIDs->size = 0;
  v4 = laneIDs;
  v5 = laneFlags;
  v6 = this;
  if ( this->mNumLanes )
  {
    do
    {
      v7 = v6->mLaneList.mOffset;
      if ( v7 )
        v8 = (signed __int64)&v6->mLaneList + v7;
      else
        v8 = 0i64;
      v9 = *(_QWORD *)(v8 + 8 * v3);
      if ( v9 )
        v9 += v8 + 8 * v3;
      if ( v5 & *(_BYTE *)(v9 + 44) )
      {
        v10 = v4->size;
        v11 = v4->capacity;
        v12 = v10 + 1;
        if ( (signed int)v10 + 1 > v11 )
        {
          if ( v11 )
            v13 = 2 * v11;
          else
            v13 = 1;
          for ( ; v13 < v12; v13 *= 2 )
            ;
          if ( v13 <= 4 )
            v13 = 4;
          if ( v13 - v12 > 0x10000 )
            v13 = v10 + 65537;
          if ( v13 != (_DWORD)v10 )
          {
            v14 = 4i64 * v13;
            if ( !is_mul_ok(v13, 4ui64) )
              v14 = -1i64;
            v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
            v16 = (unsigned int *)v15;
            if ( v4->p )
            {
              v17 = 0i64;
              if ( v4->size )
              {
                do
                {
                  v18 = v17;
                  v17 = (unsigned int)(v17 + 1);
                  *(_DWORD *)&v15[v18 * 4] = v4->p[v18];
                }
                while ( (unsigned int)v17 < v4->size );
              }
              operator delete[](v4->p);
            }
            v4->p = v16;
            v4->capacity = v13;
          }
        }
        v19 = v4->p;
        v4->size = v12;
        v19[v10] = v3;
      }
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v6->mNumLanes );
  }
}

// File Line: 3354
// RVA: 0xDE7A0
char __fastcall UFG::RoadNetworkLane::IsPermissive(UFG::RoadNetworkLane *this, bool checkCurrentPhaseOnly)
{
  UFG::RoadNetworkLane *v2; // rdi
  char *v3; // rbp
  unsigned int v5; // ebx
  unsigned int v6; // er14
  signed __int64 v7; // rsi
  __int64 v8; // rax
  signed __int64 v9; // rcx
  signed __int64 v10; // rax
  __int64 v11; // rcx
  signed __int64 v12; // rax
  unsigned int v13; // er10
  unsigned int v14; // edx
  __int64 v15; // r9
  signed __int64 v16; // r11
  __int64 v17; // r8
  signed __int64 v18; // rax
  signed __int64 v19; // rcx
  UFG::RoadNetworkLane *v20; // rax

  v2 = this;
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
  v7 = 8i64 * v5;
  while ( 1 )
  {
    if ( v3[107] )
    {
      v8 = *((_QWORD *)v3 + 14);
      v9 = (signed __int64)(v8 ? &v3[v8 + 112] : 0i64);
      v10 = v7 + v9;
      v11 = *(_QWORD *)(v7 + v9);
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
    ++v5;
    v7 += 8i64;
    if ( v5 >= v6 )
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
    if ( v20 == v2 )
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
  unsigned int v3; // edx
  __int64 v4; // rcx
  __int128 v5; // xmm0

  v1 = 0i64;
  if ( this->mNode.mOffset )
    v2 = (char *)this + this->mNode.mOffset;
  else
    v2 = 0i64;
  v3 = this->mPathIndex;
  v4 = *((_QWORD *)v2 + 4);
  if ( v4 )
    v1 = (UFG::RoadNetworkConnection *)&v2[v4 + 32];
  v5 = HIDWORD(UFG::qBezierPathCollectionMemImaged::GetPath(v1, v3)->mNode.mOffset);
  return *(float *)&v5;
}

// File Line: 3420
// RVA: 0xD1640
void __fastcall UFG::RoadNetworkLane::AddCarGuide(UFG::RoadNetworkLane *this, UFG::RoadNetworkGuide *guide, bool spawned)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v3; // r9
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v4; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v5; // r10
  UFG::RoadNetworkLane *v6; // r11
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v7; // rcx
  float v8; // xmm0_4
  float v9; // xmm2_4
  signed __int64 v10; // rcx
  signed __int64 v11; // rdx
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v12; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v13; // rcx
  float v14; // xmm1_4
  UFG::qList<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide,1,0> *v15; // rcx
  float v16; // xmm2_4
  signed __int64 v17; // rax
  float v18; // xmm1_4
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v19; // rax

  v3 = guide->mPrev;
  v4 = guide->mNext;
  v5 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)&guide->mPrev;
  v3->mNext = v4;
  v4->mPrev = v3;
  v5->mPrev = v5;
  v5->mNext = v5;
  v6 = this;
  if ( spawned
    && (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&this->mCars.mNode.mNext[-2].mNext != &this->mStartConnection )
  {
    v7 = this->mCars.mNode.mNext;
    v8 = guide->m_CurrentLocation.m_LaneT;
    v9 = *(float *)&v7[2].mPrev;
    v10 = (signed __int64)&v7[-2].mNext;
    v11 = (signed __int64)&v6->mCars.mNode.mPrev[-2].mNext;
    if ( v8 == v9 )
    {
LABEL_4:
      v12 = *(UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **)(v10 + 24);
      v13 = (UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *)(v10 + 24);
      v12->mNext = v5;
      v5->mPrev = v12;
      v5->mNext = v13;
      v13->mPrev = v5;
      return;
    }
    v14 = *(float *)(v11 + 56);
    if ( v8 == v14 )
      goto LABEL_22;
    if ( v8 <= v9 )
      goto LABEL_4;
    if ( v8 > v14 )
    {
LABEL_22:
      v15 = (UFG::qList<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide,1,0> *)v6->mCars.mNode.mPrev;
    }
    else
    {
      if ( v10 == v11 )
        return;
      while ( 1 )
      {
        v16 = *(float *)(v10 + 56);
        v17 = *(_QWORD *)(v10 + 32) - 24i64;
        if ( v8 == v16 )
        {
LABEL_16:
          v15 = (UFG::qList<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide,1,0> *)(v10 + 24);
          goto LABEL_19;
        }
        v18 = *(float *)(v17 + 56);
        if ( v8 == v18 )
          break;
        if ( v8 > v16 && v8 < v18 )
          goto LABEL_16;
        v10 = *(_QWORD *)(v10 + 32) - 24i64;
        if ( v17 == v11 )
          return;
      }
      v15 = *(UFG::qList<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide,1,0> **)(v10 + 32);
    }
  }
  else
  {
    v15 = &this->mCars;
  }
LABEL_19:
  v19 = v15->mNode.mNext;
  v15->mNode.mNext = v5;
  v5->mPrev = &v15->mNode;
  v5->mNext = v19;
  v19->mPrev = v5;
}

// File Line: 3514
// RVA: 0xDB180
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetOffsetPos(UFG::qVector3 *result, UFG::qBezierSplineMemImaged *spline, float t, float offset)
{
  UFG::qVector3 *v4; // rbx
  float v5; // xmm7_4
  float v6; // xmm3_4
  int v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  UFG::qVector3 *v13; // rax
  float v14; // xmm0_4
  UFG::qVector3 tangent; // [rsp+20h] [rbp-38h]

  v4 = result;
  v5 = offset;
  if ( offset == 0.0 )
  {
    v13 = UFG::qBezierSplineMemImaged::GetPosition(spline, &tangent, t);
    v14 = v13->y;
    v12 = v13->z;
    v4->x = v13->x;
    v4->y = v14;
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
    v11 = (float)((float)(*(float *)&v7 * v9) * v5) + v4->y;
    v12 = (float)((float)(v9 * 0.0) * v5) + v4->z;
    v4->y = v11;
    v4->x = (float)((float)(v10 * v6) * v5) + v4->x;
  }
  v4->z = v12;
  return v4;
}

// File Line: 3542
// RVA: 0xDB270
char __fastcall UFG::RoadNetworkLane::GetOffsetPosAndTangent(UFG::qBezierSplineMemImaged *spline, float t, float offset, UFG::qVector3 *pos, UFG::qVector3 *tangent)
{
  UFG::qVector3 *v5; // rdi
  float v6; // xmm6_4
  float v7; // xmm4_4
  int v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm3_4

  v5 = pos;
  v6 = offset;
  UFG::qBezierSplineMemImaged::GetPositionAndTangent(spline, t, pos, tangent);
  if ( offset != 0.0 )
  {
    v7 = tangent->y;
    v8 = LODWORD(tangent->x) ^ _xmm[0];
    v9 = (float)(*(float *)&v8 * *(float *)&v8) + (float)(v7 * v7);
    if ( v9 == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / fsqrt(v9);
    v11 = (float)((float)(v7 * v10) * v6) + v5->x;
    v12 = (float)((float)(*(float *)&v8 * v10) * v6) + v5->y;
    v5->z = (float)((float)(v10 * 0.0) * v6) + v5->z;
    v5->x = v11;
    v5->y = v12;
  }
  return 1;
}

// File Line: 3564
// RVA: 0xDB570
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetPosNoOffset(UFG::RoadNetworkLane *this, UFG::qVector3 *result, float laneT)
{
  __int64 v3; // rax
  UFG::RoadNetworkConnection *v4; // r8
  UFG::qVector3 *v5; // rdi
  char *v6; // rax
  unsigned int v7; // edx
  __int64 v8; // rcx
  UFG::qBezierPathMemImaged *v9; // rax
  UFG::RoadNetworkConnection *v10; // rbx
  unsigned int v11; // eax
  UFG::qBezierSplineMemImaged *v12; // rax
  float splineT; // [rsp+40h] [rbp+8h]

  v3 = this->mNode.mOffset;
  v4 = 0i64;
  v5 = result;
  splineT = 0.0;
  if ( v3 )
    v6 = (char *)this + v3;
  else
    v6 = 0i64;
  v7 = this->mPathIndex;
  v8 = *((_QWORD *)v6 + 4);
  if ( v8 )
    v4 = (UFG::RoadNetworkConnection *)&v6[v8 + 32];
  v9 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v4, v7);
  v10 = (UFG::RoadNetworkConnection *)v9;
  v11 = UFG::qBezierPathMemImaged::GetSplineParameters(v9, laneT, &splineT);
  v12 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v10, v11);
  UFG::RoadNetworkLane::GetOffsetPos(v5, v12, splineT, 0.0);
  return v5;
}

// File Line: 3574
// RVA: 0xDB0D0
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetOffsetPos(UFG::RoadNetworkLane *this, UFG::qVector3 *result, float t, float offset)
{
  __int64 v4; // rax
  UFG::RoadNetworkLane *v5; // rdi
  UFG::RoadNetworkConnection *v6; // rcx
  UFG::qVector3 *v7; // rsi
  char *v8; // rax
  __int64 v9; // rdx
  UFG::qBezierPathMemImaged *v10; // rax
  UFG::RoadNetworkConnection *v11; // rbx
  unsigned int v12; // eax
  UFG::qBezierSplineMemImaged *v13; // rax
  float splineT; // [rsp+68h] [rbp+20h]

  v4 = this->mNode.mOffset;
  v5 = this;
  v6 = 0i64;
  v7 = result;
  if ( v4 )
    v8 = (char *)v5 + v4;
  else
    v8 = 0i64;
  v9 = *((_QWORD *)v8 + 4);
  if ( v9 )
    v6 = (UFG::RoadNetworkConnection *)&v8[v9 + 32];
  v10 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v6, v5->mPathIndex);
  v11 = (UFG::RoadNetworkConnection *)v10;
  v12 = UFG::qBezierPathMemImaged::GetSplineParameters(v10, t, &splineT);
  v13 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v11, v12);
  UFG::RoadNetworkLane::GetOffsetPos(v7, v13, splineT, offset + v5->mOffset);
  return v7;
}

// File Line: 3594
// RVA: 0xDA3C0
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetNearestPoint(UFG::RoadNetworkLane *this, UFG::qVector3 *result, UFG::qVector3 *pos, float *laneT)
{
  UFG::RoadNetworkConnection *v4; // r10
  float *v5; // rdi
  UFG::qVector3 *v6; // rsi
  UFG::qVector3 *v7; // rbx
  char *v8; // rax
  unsigned int v9; // edx
  __int64 v10; // rcx
  UFG::qBezierPathMemImaged *v11; // rax

  v4 = 0i64;
  v5 = laneT;
  v6 = pos;
  v7 = result;
  if ( this->mNode.mOffset )
    v8 = (char *)this + this->mNode.mOffset;
  else
    v8 = 0i64;
  v9 = this->mPathIndex;
  v10 = *((_QWORD *)v8 + 4);
  if ( v10 )
    v4 = (UFG::RoadNetworkConnection *)&v8[v10 + 32];
  v11 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v4, v9);
  UFG::qBezierPathMemImaged::ClosestPoint3D(v11, v7, v6, v5);
  return v7;
}

// File Line: 3602
// RVA: 0xD8160
float __fastcall UFG::RoadNetworkLane::GetClosestT(UFG::RoadNetworkLane *this, UFG::qVector3 *pos)
{
  __int64 v2; // rax
  UFG::RoadNetworkConnection *v3; // r8
  UFG::qVector3 *v4; // rbx
  char *v5; // rax
  unsigned int v6; // edx
  __int64 v7; // rcx
  UFG::qBezierPathMemImaged *v8; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]
  float t; // [rsp+40h] [rbp+8h]

  v2 = this->mNode.mOffset;
  v3 = 0i64;
  v4 = pos;
  t = 0.0;
  if ( v2 )
    v5 = (char *)this + v2;
  else
    v5 = 0i64;
  v6 = this->mPathIndex;
  v7 = *((_QWORD *)v5 + 4);
  if ( v7 )
    v3 = (UFG::RoadNetworkConnection *)&v5[v7 + 32];
  v8 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v3, v6);
  UFG::qBezierPathMemImaged::ClosestPoint3D(v8, &result, v4, &t);
  return t;
}

// File Line: 3609
// RVA: 0xDB360
UFG::qVector3 *__fastcall UFG::RoadNetworkLane::GetPos(UFG::RoadNetworkLane *this, UFG::qVector3 *result, float t)
{
  __int64 v3; // rax
  UFG::RoadNetworkLane *v4; // rdi
  UFG::RoadNetworkConnection *v5; // rcx
  UFG::qVector3 *v6; // rsi
  char *v7; // rax
  __int64 v8; // rdx
  UFG::qBezierPathMemImaged *v9; // rax
  UFG::RoadNetworkConnection *v10; // rbx
  unsigned int v11; // eax
  UFG::qBezierSplineMemImaged *v12; // rax
  float splineT; // [rsp+40h] [rbp+8h]

  v3 = this->mNode.mOffset;
  v4 = this;
  v5 = 0i64;
  v6 = result;
  if ( v3 )
    v7 = (char *)v4 + v3;
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 4);
  if ( v8 )
    v5 = (UFG::RoadNetworkConnection *)&v7[v8 + 32];
  v9 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v5, v4->mPathIndex);
  v10 = (UFG::RoadNetworkConnection *)v9;
  v11 = UFG::qBezierPathMemImaged::GetSplineParameters(v9, t, &splineT);
  v12 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v10, v11);
  UFG::RoadNetworkLane::GetOffsetPos(v6, v12, splineT, v4->mOffset);
  return v6;
}

// File Line: 3619
// RVA: 0xDB4C0
char __fastcall UFG::RoadNetworkLane::GetPosAndTangent(UFG::RoadNetworkLane *this, float t, UFG::qVector3 *pos, UFG::qVector3 *tangent)
{
  __int64 v4; // rax
  UFG::RoadNetworkLane *v5; // rdi
  UFG::RoadNetworkConnection *v6; // rcx
  UFG::qVector3 *v7; // rsi
  UFG::qVector3 *v8; // rbp
  char *v9; // rax
  __int64 v10; // rdx
  UFG::qBezierPathMemImaged *v11; // rax
  UFG::RoadNetworkConnection *v12; // rbx
  unsigned int v13; // eax
  UFG::qBezierSplineMemImaged *v14; // rax
  float splineT; // [rsp+50h] [rbp+8h]

  v4 = this->mNode.mOffset;
  v5 = this;
  v6 = 0i64;
  v7 = tangent;
  v8 = pos;
  if ( v4 )
    v9 = (char *)v5 + v4;
  else
    v9 = 0i64;
  v10 = *((_QWORD *)v9 + 4);
  if ( v10 )
    v6 = (UFG::RoadNetworkConnection *)&v9[v10 + 32];
  v11 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v6, v5->mPathIndex);
  v12 = (UFG::RoadNetworkConnection *)v11;
  v13 = UFG::qBezierPathMemImaged::GetSplineParameters(v11, t, &splineT);
  v14 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v12, v13);
  return UFG::RoadNetworkLane::GetOffsetPosAndTangent(v14, splineT, v5->mOffset, v8, v7);
}

// File Line: 3631
// RVA: 0xD5F50
UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **__fastcall UFG::RoadNetworkLane::GetClosestCarToStart(UFG::RoadNetworkLane *this)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> **result; // rax

  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)&this->mCars.mNode.mNext[-2].mNext == &this->mStartConnection )
    result = 0i64;
  else
    result = &this->mCars.mNode.mNext[-2].mNext;
  return result;
}

// File Line: 3647
// RVA: 0xDE8A0
bool __fastcall UFG::RoadNetworkLane::IsReversedInNode(UFG::RoadNetworkLane *this)
{
  __int64 v1; // rdx
  char *v2; // r9
  char *v3; // r8
  __int64 v4; // rcx
  char *v5; // rcx
  char *v6; // r8
  __int64 v7; // rcx
  bool result; // al

  v1 = this->mStartGate.mOffset;
  if ( v1 )
    v2 = (char *)&this->mStartGate + v1;
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
    result = v2 != &v6[v7 + 8];
  else
    result = v2 != 0i64;
  return result;
}

// File Line: 3653
// RVA: 0xD9510
signed __int64 __fastcall UFG::RoadNetworkLane::GetLaneDirection(UFG::RoadNetworkLane *this, UFG::RoadNetworkLane *otherLane)
{
  UFG::RoadNetworkLane *v2; // r8
  __int64 v3; // rcx
  signed __int64 result; // rax
  char *v5; // r9
  UFG::RoadNetworkLane *v6; // rbp
  __int64 v7; // r11
  signed __int64 v8; // rdi
  char *v9; // rcx
  char *v10; // r10
  __int64 v11; // rcx
  signed __int64 v12; // r15
  __int64 v13; // rcx
  signed __int64 v14; // rsi
  int v15; // er14
  unsigned int v16; // ebx
  int v17; // er10
  __int64 v18; // r8
  signed __int64 v19; // r9
  signed __int64 v20; // rcx
  signed __int64 v21; // rdx
  __int64 v22; // rcx
  UFG::RoadNetworkLane *v23; // rcx
  __int64 v24; // rdx
  signed __int64 v25; // rdx
  int v26; // er9
  __int64 i; // r8
  signed __int64 v28; // rcx
  signed __int64 v29; // rdx
  __int64 v30; // rcx
  UFG::RoadNetworkLane *v31; // rcx
  __int64 v32; // rdx
  signed __int64 v33; // rdx

  v2 = this;
  v3 = this->mNode.mOffset;
  result = 0i64;
  v5 = (char *)v2 + v3;
  v6 = otherLane;
  if ( !v3 )
    v5 = 0i64;
  v7 = *((_QWORD *)v5 + 6);
  v8 = (signed __int64)(v5 + 48);
  v9 = &v5[v7 + 48];
  if ( !v7 )
    v9 = 0i64;
  v10 = &v9[*(_QWORD *)v9];
  if ( !*(_QWORD *)v9 )
    v10 = 0i64;
  v11 = *((_QWORD *)v10 + 1);
  if ( v11 )
    v12 = (signed __int64)&v10[v11 + 8];
  else
    v12 = 0i64;
  v13 = v2->mStartGate.mOffset;
  if ( v13 )
    v14 = (signed __int64)&v2->mStartGate + v13;
  else
    v14 = 0i64;
  v15 = v2->mLaneIndex;
  v16 = (unsigned __int8)v5[40];
  v17 = 0;
  v18 = (unsigned int)(v15 + 1);
  if ( (unsigned int)v18 < v16 )
  {
    v19 = 8 * v18;
    do
    {
      v20 = v7 + v8;
      if ( !v7 )
        v20 = 0i64;
      v21 = v19 + v20;
      v22 = *(_QWORD *)(v19 + v20);
      v23 = (UFG::RoadNetworkLane *)(v22 ? v21 + v22 : 0i64);
      v24 = v23->mStartGate.mOffset;
      v25 = (signed __int64)(v24 ? (UFG::qOffset64<UFG::RoadNetworkGate *> *)((char *)&v23->mStartGate + v24) : 0i64);
      if ( v25 != v14 )
        break;
      if ( v23 == v6 )
      {
        v17 = v18 - v15;
        if ( (_DWORD)v18 != v15 )
          goto LABEL_42;
        break;
      }
      LODWORD(v18) = v18 + 1;
      v19 += 8i64;
    }
    while ( (unsigned int)v18 < v16 );
  }
  v26 = v15 - 1;
  for ( i = v15 - 1; i >= 0; --i )
  {
    v28 = v7 + v8;
    if ( !v7 )
      v28 = 0i64;
    v29 = v28 + 8 * i;
    v30 = *(_QWORD *)(v28 + 8 * i);
    v31 = (UFG::RoadNetworkLane *)(v30 ? v29 + v30 : 0i64);
    v32 = v31->mStartGate.mOffset;
    v33 = (signed __int64)(v32 ? (UFG::qOffset64<UFG::RoadNetworkGate *> *)((char *)&v31->mStartGate + v32) : 0i64);
    if ( v33 != v14 )
      break;
    if ( v31 == v6 )
    {
      v17 = v26 - v15;
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
    result = 2i64;
  return result;
}

// File Line: 3700
// RVA: 0xDC430
signed __int64 __fastcall UFG::RoadNetworkLane::GetTurnDirection(UFG::RoadNetworkLane *this)
{
  char v1; // dl
  signed __int64 result; // rax

  v1 = this->mDirection;
  if ( v1 == -1 )
    return 1i64;
  result = 0i64;
  if ( v1 == 1 )
    result = 2i64;
  return result;
}

// File Line: 3730
// RVA: 0xDE4A0
bool __fastcall UFG::RoadNetworkLane::IsFlagMatch(UFG::RoadNetworkLane *this, unsigned int laneFlags)
{
  return ((unsigned __int8)laneFlags & this->mLaneFlags) != 0;
}

// File Line: 3735
// RVA: 0xDF350
bool __fastcall UFG::RoadNetworkLane::LaneChangeAvailable(UFG::RoadNetworkLane *this, unsigned int *whichLanes)
{
  unsigned int *v2; // r13
  UFG::RoadNetworkLane *v3; // r14
  signed int v4; // er12
  __int64 v5; // r15
  char *v6; // rbp
  signed int v8; // esi
  signed int v9; // edi
  int v10; // eax
  signed int v11; // er11
  __int64 v12; // rcx
  __int64 v13; // r10
  __int64 v14; // rax
  signed __int64 v15; // rdx
  __int64 v16; // rax
  signed __int64 v17; // rcx
  _QWORD *v18; // rax
  __int64 v19; // rcx
  signed __int64 v20; // r8
  char *v21; // rdx
  __int64 v22; // rax
  char *v23; // rax
  char *v24; // rdx
  __int64 v25; // rax
  signed __int64 v26; // rax
  bool v27; // zf
  __int64 v28; // rax
  signed __int64 v29; // r8
  char *v30; // rax
  __int64 v31; // rcx
  char *v32; // rax
  char *v33; // rdx
  __int64 v34; // rax
  signed __int64 v35; // rcx
  __int64 v36; // rax
  signed __int64 v37; // rcx
  __int64 v38; // rax
  _QWORD *v39; // rax
  __int64 v40; // rcx
  signed __int64 v41; // r8
  char *v42; // rdx
  __int64 v43; // rax
  char *v44; // rax
  char *v45; // rdx
  __int64 v46; // rax
  signed __int64 v47; // rax
  bool v48; // zf
  __int64 v49; // rax
  signed __int64 v50; // r8
  char *v51; // rax
  __int64 v52; // rcx
  char *v53; // rax
  char *v54; // rdx
  __int64 v55; // rax
  signed __int64 v56; // rax

  v2 = whichLanes;
  v3 = this;
  v4 = 0;
  if ( whichLanes )
    *whichLanes = 0;
  v5 = this->mNode.mOffset;
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
  v10 = v3->mLaneIndex;
  v11 = (unsigned __int8)v6[40];
  v12 = (unsigned int)(v10 + v8);
  v13 = (unsigned int)(v10 + v9);
  if ( (signed int)v12 >= 0 && (signed int)v12 < v11 )
  {
    v14 = *((_QWORD *)v6 + 6);
    if ( v14 )
      v15 = (signed __int64)&v6[v14 + 48];
    else
      v15 = 0i64;
    v16 = *(_QWORD *)(v15 + 8 * v12);
    v17 = v15 + 8 * v12;
    if ( v16 )
      v18 = (_QWORD *)(v17 + v16);
    else
      v18 = 0i64;
    v19 = v18[1];
    if ( v19 )
      v20 = (signed __int64)v18 + v19 + 8;
    else
      v20 = 0i64;
    v21 = (char *)v18 + *v18;
    if ( !*v18 )
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
      v26 = (signed __int64)&v24[v25 + 8];
    else
      v26 = 0i64;
    v27 = v20 == v26;
    v28 = v3->mStartGate.mOffset;
    if ( v28 )
      v29 = (signed __int64)&v3->mStartGate + v28;
    else
      v29 = 0i64;
    v30 = (char *)v3 + v5;
    if ( !v5 )
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
      v35 = (signed __int64)&v33[v34 + 8];
    else
      v35 = 0i64;
    if ( !v27 == (v29 != v35) )
      v4 = 2;
  }
  if ( (signed int)v13 >= 0 && (signed int)v13 < v11 )
  {
    v36 = *((_QWORD *)v6 + 6);
    if ( v36 )
      v37 = (signed __int64)&v6[v36 + 48];
    else
      v37 = 0i64;
    v38 = *(_QWORD *)(v37 + 8 * v13);
    if ( v38 )
      v39 = (_QWORD *)(v37 + 8 * v13 + v38);
    else
      v39 = 0i64;
    v40 = v39[1];
    if ( v40 )
      v41 = (signed __int64)v39 + v40 + 8;
    else
      v41 = 0i64;
    v42 = (char *)v39 + *v39;
    if ( !*v39 )
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
      v47 = (signed __int64)&v45[v46 + 8];
    else
      v47 = 0i64;
    v48 = v41 == v47;
    v49 = v3->mStartGate.mOffset;
    if ( v49 )
      v50 = (signed __int64)&v3->mStartGate + v49;
    else
      v50 = 0i64;
    v51 = (char *)v3 + v5;
    if ( !v5 )
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
      v56 = (signed __int64)&v54[v55 + 8];
    else
      v56 = 0i64;
    if ( !v48 == (v50 != v56) )
      ++v4;
  }
  if ( v2 )
    *v2 = v4;
  return v4 != 0;
}

// File Line: 3779
// RVA: 0xDAF70
__int64 __fastcall UFG::RoadNetworkLane::GetNumberOfCarsInLaneAheadOfDistance(UFG::RoadNetworkLane *this, float d)
{
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v2; // rax
  UFG::RoadNetworkLane *v3; // rsi
  UFG::qOffset64<UFG::RoadNetworkConnection *> *v4; // rcx
  signed __int64 v5; // rax
  int v6; // edx
  __int64 v7; // rax
  signed __int64 v8; // rdi
  UFG::RoadNetworkConnection *v9; // rcx
  UFG::RoadNetworkLane *v10; // rax
  UFG::qNode<UFG::RoadNetworkGuide,UFG::RoadNetworkGuide> *v11; // rbx
  signed __int64 v12; // rsi
  signed __int64 v13; // rbx
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

  v2 = this->mCars.mNode.mNext;
  v3 = this;
  v4 = &this->mStartConnection;
  v5 = (signed __int64)&v2[-2].mNext;
  v6 = 0;
  if ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v5 == v4 )
    return 0i64;
  do
  {
    ++v6;
    v5 = *(_QWORD *)(v5 + 32) - 24i64;
  }
  while ( (UFG::qOffset64<UFG::RoadNetworkConnection *> *)v5 != v4 );
  if ( !v6 )
    return 0i64;
  v7 = v3->mNode.mOffset;
  v8 = 0i64;
  if ( v3->mNode.mOffset )
    v7 += (__int64)v3;
  v9 = *(UFG::RoadNetworkConnection **)(v7 + 32);
  if ( v9 )
    v9 = (UFG::RoadNetworkConnection *)((char *)v9 + v7 + 32);
  v10 = UFG::qBezierPathCollectionMemImaged::GetPath(v9, v3->mPathIndex);
  v11 = v3->mCars.mNode.mPrev;
  v12 = (signed __int64)&v3->mStartConnection;
  v13 = (signed __int64)&v11[-2].mNext;
  v14 = 0;
  for ( i = *((float *)&v10->mNode.mOffset + 1); v13 != v12; v13 = *(_QWORD *)(v13 + 24) - 24i64 )
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
  UFG::qVector3 *v2; // rsi
  UFG::RoadNetworkLane *v3; // rdi
  __int64 v4; // rax
  unsigned int v5; // edx
  UFG::RoadNetworkConnection *v6; // rcx
  UFG::qBezierPathMemImaged *v7; // rax
  __int64 v8; // rax
  UFG::RoadNetworkConnection *v9; // rcx
  UFG::qBezierPathMemImaged *v10; // rax
  float v11; // xmm8_4
  UFG::RoadNetworkConnection *v12; // rbx
  unsigned int v13; // eax
  UFG::qBezierSplineMemImaged *v14; // rax
  __m128 v15; // xmm2
  float v16; // xmm6_4
  __int64 v17; // rax
  UFG::RoadNetworkConnection *v18; // rcx
  UFG::qBezierPathMemImaged *v19; // rax
  UFG::RoadNetworkConnection *v20; // rbx
  unsigned int v21; // eax
  UFG::qBezierSplineMemImaged *v22; // rax
  __m128 v23; // xmm3
  UFG::qVector3 result; // [rsp+20h] [rbp-68h]
  float t; // [rsp+90h] [rbp+8h]
  float splineT; // [rsp+98h] [rbp+10h]

  v2 = position;
  v3 = this;
  t = 0.0;
  v4 = this->mNode.mOffset;
  if ( this->mNode.mOffset )
    v4 += (__int64)this;
  v5 = this->mPathIndex;
  v6 = *(UFG::RoadNetworkConnection **)(v4 + 32);
  if ( v6 )
    v6 = (UFG::RoadNetworkConnection *)((char *)v6 + v4 + 32);
  v7 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v6, v5);
  UFG::qBezierPathMemImaged::ClosestPoint3D(v7, &result, v2, &t);
  v8 = v3->mNode.mOffset;
  if ( v3->mNode.mOffset )
    v8 += (__int64)v3;
  v9 = *(UFG::RoadNetworkConnection **)(v8 + 32);
  if ( v9 )
    v9 = (UFG::RoadNetworkConnection *)((char *)v9 + v8 + 32);
  v10 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v9, v3->mPathIndex);
  v11 = t;
  v12 = (UFG::RoadNetworkConnection *)v10;
  v13 = UFG::qBezierPathMemImaged::GetSplineParameters(v10, t, &splineT);
  v14 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v12, v13);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v14, splineT, v3->mOffset);
  v15 = (__m128)LODWORD(result.y);
  v16 = v3->mOffset;
  v15.m128_f32[0] = (float)((float)((float)(result.y - v2->y) * (float)(result.y - v2->y))
                          + (float)((float)(result.x - v2->x) * (float)(result.x - v2->x)))
                  + (float)((float)(result.z - v2->z) * (float)(result.z - v2->z));
  if ( (float)(COERCE_FLOAT(_mm_sqrt_ps(v15)) - 2.0) < 0.75 )
  {
    do
    {
      v17 = v3->mNode.mOffset;
      v16 = v16 + 0.25;
      if ( v3->mNode.mOffset )
        v17 += (__int64)v3;
      v18 = *(UFG::RoadNetworkConnection **)(v17 + 32);
      if ( v18 )
        v18 = (UFG::RoadNetworkConnection *)((char *)v18 + v17 + 32);
      v19 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v18, v3->mPathIndex);
      v20 = (UFG::RoadNetworkConnection *)v19;
      v21 = UFG::qBezierPathMemImaged::GetSplineParameters(v19, v11, &t);
      v22 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v20, v21);
      UFG::RoadNetworkLane::GetOffsetPos(&result, v22, t, v16 + v3->mOffset);
      v23 = (__m128)LODWORD(result.y);
      v23.m128_f32[0] = (float)((float)((float)(result.y - v2->y) * (float)(result.y - v2->y))
                              + (float)((float)(result.x - v2->x) * (float)(result.x - v2->x)))
                      + (float)((float)(result.z - v2->z) * (float)(result.z - v2->z));
    }
    while ( (float)(COERCE_FLOAT(_mm_sqrt_ps(v23)) - 2.0) < 0.75 );
  }
  return v16;
}

// File Line: 3977
// RVA: 0xDB330
UFG::RoadNetworkConnection *__fastcall UFG::RoadNetworkGate::GetOutgoingConnection(UFG::RoadNetworkGate *this, unsigned int index)
{
  __int64 v2; // rax
  char *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rdx
  UFG::RoadNetworkConnection *result; // rax

  v2 = this->mOutgoingConnection.mOffset;
  if ( v2 )
    v3 = (char *)&this->mOutgoingConnection + v2;
  else
    v3 = 0i64;
  v4 = index;
  v5 = (signed __int64)&v3[8 * v4];
  result = *(UFG::RoadNetworkConnection **)&v3[8 * v4];
  if ( result )
    result = (UFG::RoadNetworkConnection *)((char *)result + v5);
  return result;
}

// File Line: 3984
// RVA: 0xD5B30
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(UFG::RoadNetworkGate *this, UFG::RoadNetworkNode *targetNode)
{
  unsigned int v2; // er15
  unsigned int v3; // edi
  UFG::RoadNetworkNode *v4; // rbp
  __int64 v5; // r14
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *v6; // r12
  __int64 v7; // rsi
  char *v8; // rax
  char *v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  signed __int64 v12; // rax
  unsigned int v13; // er11
  unsigned int v14; // er8
  __int64 v15; // r10
  signed __int64 v16; // rbx
  __int64 v17; // r9
  signed __int64 v18; // rax
  signed __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // rdx
  __int64 v22; // rax
  signed __int64 v23; // rcx
  _QWORD *v24; // rax
  UFG::RoadNetworkNode **v25; // rax
  UFG::RoadNetworkNode *v26; // rcx

  v2 = this->mNumOutgoingConnections;
  v3 = 0;
  v4 = targetNode;
  if ( !v2 )
    return 0i64;
  v5 = this->mOutgoingConnection.mOffset;
  v6 = &this->mOutgoingConnection;
  v7 = 0i64;
  while ( 1 )
  {
    if ( v5 )
      v8 = (char *)v6 + v5;
    else
      v8 = 0i64;
    v9 = &v8[v7];
    v10 = *(_QWORD *)&v8[v7];
    if ( v10 )
      v10 += (__int64)v9;
    v11 = *(_QWORD *)(v10 + 16);
    if ( v11 )
    {
      v12 = v11 + v10 + 16;
      if ( v12 )
      {
        v13 = *(_DWORD *)v12;
        v14 = 0;
        if ( *(_DWORD *)v12 )
          break;
      }
    }
LABEL_30:
    ++v3;
    v7 += 8i64;
    if ( v3 >= v2 )
      return 0i64;
  }
  v15 = *(_QWORD *)(v12 + 8);
  v16 = v12 + 8;
  v17 = 0i64;
  while ( 1 )
  {
    if ( v15 )
      v18 = v15 + v16;
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
    v25 = (UFG::RoadNetworkNode **)(*v24 ? (_QWORD *)((char *)v24 + *v24) : 0i64);
    v26 = *v25;
    if ( *v25 )
      v26 = (UFG::RoadNetworkNode *)((char *)v26 + (_QWORD)v25);
    if ( v26 == v4 )
      return (UFG::RoadNetworkLane *)v21;
    ++v14;
    v17 += 8i64;
    if ( v14 >= v13 )
      goto LABEL_30;
  }
}

// File Line: 4010
// RVA: 0xD5A00
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkGate::GetAnyLaneLeadingHereFromNode(UFG::RoadNetworkGate *this, UFG::RoadNetworkNode *targetNode)
{
  unsigned int v2; // er15
  unsigned int v3; // edi
  UFG::RoadNetworkNode *v4; // rbp
  __int64 v5; // r14
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *v6; // r12
  __int64 v7; // rsi
  char *v8; // rax
  char *v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  signed __int64 v12; // rax
  unsigned int v13; // er11
  unsigned int v14; // er8
  __int64 v15; // r10
  signed __int64 v16; // rbx
  __int64 v17; // r9
  signed __int64 v18; // rax
  signed __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // rdx
  __int64 v22; // rax
  signed __int64 v23; // rcx
  _QWORD *v24; // rax
  UFG::RoadNetworkNode **v25; // rax
  UFG::RoadNetworkNode *v26; // rcx

  v2 = this->mNumIncomingConnections;
  v3 = 0;
  v4 = targetNode;
  if ( !v2 )
    return 0i64;
  v5 = this->mIncomingConnection.mOffset;
  v6 = &this->mIncomingConnection;
  v7 = 0i64;
  while ( 1 )
  {
    if ( v5 )
      v8 = (char *)v6 + v5;
    else
      v8 = 0i64;
    v9 = &v8[v7];
    v10 = *(_QWORD *)&v8[v7];
    if ( v10 )
      v10 += (__int64)v9;
    v11 = *(_QWORD *)(v10 + 16);
    if ( v11 )
    {
      v12 = v11 + v10 + 16;
      if ( v12 )
      {
        v13 = *(_DWORD *)v12;
        v14 = 0;
        if ( *(_DWORD *)v12 )
          break;
      }
    }
LABEL_30:
    ++v3;
    v7 += 8i64;
    if ( v3 >= v2 )
      return 0i64;
  }
  v15 = *(_QWORD *)(v12 + 8);
  v16 = v12 + 8;
  v17 = 0i64;
  while ( 1 )
  {
    if ( v15 )
      v18 = v15 + v16;
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
    v25 = (UFG::RoadNetworkNode **)(*v24 ? (_QWORD *)((char *)v24 + *v24) : 0i64);
    v26 = *v25;
    if ( *v25 )
      v26 = (UFG::RoadNetworkNode *)((char *)v26 + (_QWORD)v25);
    if ( v26 == v4 )
      return (UFG::RoadNetworkLane *)v21;
    ++v14;
    v17 += 8i64;
    if ( v14 >= v13 )
      goto LABEL_30;
  }
}

// File Line: 4031
// RVA: 0xD8840
UFG::RoadNetworkLane *__fastcall UFG::RoadNetworkGate::GetFirstOutgoingLaneLeadingToNode(UFG::RoadNetworkGate *this, UFG::RoadNetworkNode *targetNode)
{
  unsigned int v2; // er13
  char *v3; // r8
  UFG::RoadNetworkNode *v4; // r15
  unsigned int v5; // ebp
  __int64 v6; // r12
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *v7; // rax
  __int64 v8; // r14
  char *v9; // rax
  char *v10; // rcx
  __int64 v11; // rax
  char *v12; // rsi
  __int64 v13; // rax
  signed __int64 v14; // rax
  unsigned int v15; // ebx
  unsigned int v16; // er9
  __int64 v17; // r11
  signed __int64 v18; // rdi
  __int64 v19; // r10
  signed __int64 v20; // rax
  signed __int64 v21; // rcx
  __int64 v22; // rax
  _QWORD *v23; // rax
  _WORD *v24; // rdx
  __int64 v25; // rcx
  signed __int64 v26; // rax
  __int64 v27; // rcx
  _QWORD *v28; // rax
  UFG::RoadNetworkNode *v29; // rcx
  __int64 v30; // rax
  char *v31; // rax
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *i; // [rsp+30h] [rbp+8h]

  v2 = this->mNumOutgoingConnections;
  v3 = 0i64;
  v4 = targetNode;
  v5 = 0;
  if ( !v2 )
    return 0i64;
  v6 = this->mOutgoingConnection.mOffset;
  v7 = &this->mOutgoingConnection;
  v8 = 0i64;
  for ( i = &this->mOutgoingConnection; ; v7 = i )
  {
    if ( v6 )
      v9 = (char *)v7 + v6;
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
      v14 = (signed __int64)&v12[v13 + 16];
      if ( v14 )
      {
        v15 = *(_DWORD *)v14;
        v16 = 0;
        if ( *(_DWORD *)v14 )
          break;
      }
    }
LABEL_34:
    ++v5;
    v8 += 8i64;
    if ( v5 >= v2 )
      return 0i64;
  }
  v17 = *(_QWORD *)(v14 + 8);
  v18 = v14 + 8;
  v19 = 0i64;
  while ( 1 )
  {
    v20 = v17 + v18;
    if ( !v17 )
      v20 = 0i64;
    v21 = v19 + v20;
    v22 = *(_QWORD *)(v19 + v20);
    if ( v22 )
      v23 = (_QWORD *)(v21 + v22);
    else
      v23 = 0i64;
    v24 = (_WORD *)((char *)v23 + *v23);
    if ( !*v23 )
      v24 = 0i64;
    if ( *v24 == 1 )
    {
      v25 = v23[13];
      if ( v25 )
        v26 = (signed __int64)v23 + v25 + 104;
      else
        v26 = 0i64;
      v27 = *(_QWORD *)(v26 + 8);
      if ( v27 )
        v28 = (_QWORD *)(v27 + v26 + 8);
      else
        v28 = 0i64;
      if ( *v28 )
        v23 = (_QWORD *)((char *)v28 + *v28);
      else
        v23 = 0i64;
    }
    v29 = (UFG::RoadNetworkNode *)(*v23 ? (_QWORD *)((char *)v23 + *v23) : 0i64);
    if ( v29 == v4 )
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
    v3 = &v31[*(_QWORD *)v31];
  return (UFG::RoadNetworkLane *)v3;
}

// File Line: 4060
// RVA: 0xD9D40
void __fastcall UFG::RoadNetworkGate::GetLanesLeadingToNode(UFG::RoadNetworkGate *this, UFG::RoadNetworkNode *targetNode, UFG::RoadNetworkLane **laneList, unsigned int *numLanes, const unsigned int maxLanes, unsigned int laneFlags)
{
  __int64 v6; // rbp
  UFG::RoadNetworkNode *v7; // r14
  UFG::RoadNetworkGate *v8; // r13
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax
  signed __int64 v12; // r10
  __int64 v13; // rax
  signed __int64 v14; // rsi
  __int64 v15; // r11
  __int64 v16; // rax
  signed __int64 v17; // rcx
  __int64 v18; // rax
  signed __int64 v19; // rcx
  _WORD *v20; // rdx
  __int64 v21; // rax
  signed __int64 v22; // rdx
  _QWORD *v23; // rax
  signed __int64 v24; // rax
  UFG::RoadNetworkNode *v25; // rcx
  __int64 v26; // rdx
  __int64 v27; // rax
  signed __int64 v28; // rcx
  __int64 v29; // rax
  UFG::RoadNetworkLane *v30; // rcx

  v6 = 0i64;
  v7 = targetNode;
  v8 = this;
  if ( this->mNumOutgoingConnections )
  {
    while ( 1 )
    {
      v9 = v8->mOutgoingConnection.mOffset;
      v10 = (signed __int64)(v9 ? (UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkConnection *> *> *)((char *)&v8->mOutgoingConnection + v9) : 0i64);
      v11 = *(_QWORD *)(v10 + 8 * v6);
      v12 = v11 ? v11 + v10 + 8 * v6 : 0i64;
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
      if ( (unsigned int)v6 >= v8->mNumOutgoingConnections )
        return;
    }
    while ( 1 )
    {
      v16 = *(_QWORD *)(v14 + 8);
      v17 = v16 ? v16 + v14 + 8 : 0i64;
      v18 = *(_QWORD *)(v17 + 8 * v15);
      v19 = v18 ? v18 + v17 + 8 * v15 : 0i64;
      v20 = (_WORD *)(*(_QWORD *)v19 ? *(_QWORD *)v19 + v19 : 0i64);
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
        v24 = (signed __int64)(*v23 ? (_QWORD *)((char *)v23 + *v23) : 0i64);
      }
      else
      {
        v24 = v19;
      }
      if ( (unsigned __int8)laneFlags & *(_BYTE *)(v19 + 44) )
      {
        v25 = *(UFG::RoadNetworkNode **)v24;
        if ( *(_QWORD *)v24 )
          v25 = (UFG::RoadNetworkNode *)((char *)v25 + v24);
        if ( v25 == v7 )
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
      v30 = (UFG::RoadNetworkLane *)(v29 ? v29 + v28 + 8 * v26 : 0i64);
      laneList[(*numLanes)++] = v30;
      if ( *numLanes == maxLanes )
        break;
      v26 = (unsigned int)(v26 + 1);
      if ( (unsigned int)v26 >= *(_DWORD *)v12 )
        goto LABEL_43;
    }
  }
}

