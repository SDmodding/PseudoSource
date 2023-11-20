// File Line: 37
// RVA: 0x6CDE0
bool __fastcall `anonymous namespace::ClipPolyVertexCompare(ClipPolyVertex *a, ClipPolyVertex *b)
{
  return b->mAngle < a->mAngle;
}

// File Line: 85
// RVA: 0x6CDA0
void __fastcall ClipCube::ClipCube(ClipCube *this)
{
  ClipCube *v1; // rbx

  v1 = this;
  *(_QWORD *)&this->mCurrentSide = 0i64;
  UFG::qMemSet(this->mSideVertexCount, 0, 0x18u);
  UFG::qMemSet(v1->mEdgeHasClipVert, 0, 0xCu);
}

// File Line: 90
// RVA: 0x6DD10
void __fastcall ClipCube::Reset(ClipCube *this)
{
  ClipCube *v1; // rbx

  v1 = this;
  *(_QWORD *)&this->mCurrentSide = 0i64;
  UFG::qMemSet(this->mSideVertexCount, 0, 0x18u);
  UFG::qMemSet(v1->mEdgeHasClipVert, 0, 0xCu);
}

// File Line: 98
// RVA: 0x6CDF0
void __fastcall ClipCube::ClipToPlane(ClipCube *this, UFG::qVector4 *plane)
{
  float v2; // xmm8_4
  UFG::qVector4 *v3; // r14
  ClipCube *v4; // r8
  unsigned __int64 v5; // r9
  signed __int64 v6; // r10
  float v7; // xmm9_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  UFG::qVector4 *v10; // rax
  UFG::qVector4 *v11; // rcx
  float v12; // xmm12_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  signed int v18; // ecx
  float v19; // xmm4_4
  float v20; // xmm5_4
  int v21; // eax
  float v22; // xmm3_4
  int v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm1_4
  UnitCubeSide *v26; // rsi
  signed __int64 v27; // rbp
  float v28; // xmm2_4
  char v29; // r10
  bool *v30; // r11
  UnitCubeSide *v31; // rbx
  signed __int64 v32; // rdi
  signed __int64 v33; // r9
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm8_4
  float v37; // xmm9_4
  unsigned int v38; // ecx
  float v39; // xmm3_4
  float v40; // xmm4_4
  float v41; // xmm5_4
  UFG::qVector4 *v42; // rax
  char v43; // al
  __int64 v44; // rdx
  signed __int64 v45; // rcx
  signed __int64 v46; // rax
  __int64 v47; // rdx
  signed __int64 v48; // rcx
  signed __int64 v49; // rax
  __int64 v50; // rdx
  bool v51; // zf
  signed __int64 v52; // rcx
  signed __int64 v53; // rax
  signed __int64 v54; // rcx
  float v55; // xmm3_4
  float v56; // xmm4_4
  float v57; // xmm5_4
  signed __int64 v58; // rax
  __int64 v59; // rdx
  signed __int64 v60; // rcx
  signed __int64 v61; // rax
  signed __int64 v62; // rcx
  float v63; // eax
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // [rsp+0h] [rbp-138h]
  float v67; // [rsp+4h] [rbp-134h]
  float v68; // [rsp+8h] [rbp-130h]
  int v69; // [rsp+10h] [rbp-128h]
  int v70[23]; // [rsp+14h] [rbp-124h]

  v2 = plane->y;
  v3 = plane;
  v4 = this;
  v5 = 0i64;
  v6 = 12i64;
  v7 = plane->x;
  v8 = plane->z;
  v9 = plane->w;
  do
  {
    v10 = &`anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v5 / 2].mStartVertex];
    v11 = &`anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v5 / 2].mEndVertex];
    v12 = v11->y;
    v13 = v11->x;
    v14 = v11->z;
    v15 = v11->w;
    v16 = v10->y;
    v17 = v10->x;
    v18 = 0;
    v19 = v10->z;
    v20 = v10->w;
    v21 = 0;
    v22 = (float)((float)((float)(v7 * v17) + (float)(v2 * v16)) + (float)(v8 * v19)) + (float)(v9 * v20);
    if ( (float)((float)((float)((float)(v7 * v13) + (float)(v2 * v12)) + (float)(v14 * v8)) + (float)(v15 * v9)) < 0.0 )
      v18 = 2;
    LOBYTE(v21) = v22 < 0.0;
    v23 = v21 | v18;
    *(int *)((char *)&v69 + v5 * 4) = v23;
    if ( v23 )
      *(float *)&v70[v5] = v22
                         / (float)((float)((float)((float)(v2 * (float)(v16 - v12)) + (float)(v7 * (float)(v17 - v13)))
                                         + (float)((float)(v19 - v14) * v8))
                                 + (float)((float)(v20 - v15) * v9));
    v5 += 2i64;
    --v6;
  }
  while ( v6 );
  v24 = v68;
  v25 = v67;
  v26 = `anonymous namespace::gUnitCubeSides;
  v27 = 6i64;
  v28 = v66;
  do
  {
    v29 = 0;
    v30 = v26->mEdgeFlipped;
    v31 = v26;
    v32 = 4i64;
    do
    {
      v33 = v31->mEdges[0];
      if ( *v30 )
      {
        v34 = 1.0 - *(float *)&v70[2 * v33];
        v35 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].x;
        v36 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].y;
        v37 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].z;
        v42 = &`anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mStartVertex];
        v38 = (unsigned int)*(&v69 + 2 * v33) >> 1;
        v39 = v42->x;
        v40 = v42->y;
        v41 = v42->z;
        LOBYTE(v42) = *((_BYTE *)&v69 + 8 * v33);
      }
      else
      {
        LOBYTE(v38) = *((_BYTE *)&v69 + 8 * v33);
        v34 = *(float *)&v70[2 * v33];
        v35 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mStartVertex].x;
        v36 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mStartVertex].y;
        v37 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mStartVertex].z;
        v39 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].x;
        v40 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].y;
        v41 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].z;
        LODWORD(v42) = (unsigned int)*(&v69 + 2 * v33) >> 1;
      }
      v43 = (unsigned __int8)v42 & 1;
      if ( v38 & 1 )
      {
        if ( !v43 )
        {
          v28 = (float)((float)(v39 - v35) * v34) + v35;
          v25 = (float)((float)(v40 - v36) * v34) + v36;
          v24 = (float)((float)(v41 - v37) * v34) + v37;
          if ( v29 )
          {
            v44 = v4->mCurrentSideVertexCount;
            v45 = 3 * (5i64 * v4->mCurrentSide + v44 + 4);
            v4->mCurrentSideVertexCount = v44 + 1;
            *(&v4->mPlane.x + v45) = v28;
            *(&v4->mPlane.y + v45) = v25;
            *(&v4->mPlane.z + v45) = v24;
            if ( !v4->mEdgeHasClipVert[v33] )
            {
              v46 = v33;
              v4->mEdgeClipVert[v46].x = v28;
              v4->mEdgeClipVert[v46].y = v25;
              v4->mEdgeClipVert[v46].z = v24;
              v4->mEdgeHasClipVert[v33] = 1;
            }
          }
          v47 = v4->mCurrentSideVertexCount;
          v48 = 3 * (5i64 * v4->mCurrentSide + v47 + 4);
          v4->mCurrentSideVertexCount = v47 + 1;
          *(&v4->mPlane.x + v48) = v39;
          *(&v4->mPlane.y + v48) = v40;
          *(&v4->mPlane.z + v48) = v41;
          if ( !v4->mEdgeHasClipVert[v33] )
          {
            v49 = v33;
            v4->mEdgeClipVert[v49].x = v28;
            v4->mEdgeClipVert[v49].y = v25;
            v4->mEdgeClipVert[v49].z = v24;
            v4->mEdgeHasClipVert[v33] = 1;
          }
          v29 = 1;
        }
      }
      else
      {
        v50 = v4->mCurrentSideVertexCount;
        v51 = v43 == 0;
        v52 = 5i64 * v4->mCurrentSide;
        v53 = v50 + 4;
        if ( v51 )
        {
          v62 = 3 * (v52 + v53);
          v4->mCurrentSideVertexCount = v50 + 1;
          *(&v4->mPlane.x + v62) = v39;
          *(&v4->mPlane.y + v62) = v40;
          *(&v4->mPlane.z + v62) = v41;
        }
        else
        {
          v54 = 3 * (v52 + v53);
          v4->mCurrentSideVertexCount = v50 + 1;
          v55 = (float)((float)(v39 - v35) * v34) + v35;
          v56 = (float)((float)(v40 - v36) * v34) + v36;
          v57 = (float)((float)(v41 - v37) * v34) + v37;
          *(&v4->mPlane.x + v54) = v55;
          *(&v4->mPlane.y + v54) = v56;
          *(&v4->mPlane.z + v54) = v57;
          if ( !v4->mEdgeHasClipVert[v33] )
          {
            v58 = v33;
            v4->mEdgeClipVert[v58].x = v55;
            v4->mEdgeClipVert[v58].y = v56;
            v4->mEdgeClipVert[v58].z = v57;
            v4->mEdgeHasClipVert[v33] = 1;
          }
          if ( v29 )
          {
            v59 = v4->mCurrentSideVertexCount;
            v60 = 3 * (5i64 * v4->mCurrentSide + v59 + 4);
            v4->mCurrentSideVertexCount = v59 + 1;
            *(&v4->mPlane.x + v60) = v28;
            *(&v4->mPlane.y + v60) = v25;
            *(&v4->mPlane.z + v60) = v24;
            if ( !v4->mEdgeHasClipVert[v33] )
            {
              v61 = v33;
              v4->mEdgeClipVert[v61].x = v55;
              v4->mEdgeClipVert[v61].y = v56;
              v4->mEdgeClipVert[v61].z = v57;
              v4->mEdgeHasClipVert[v33] = 1;
            }
          }
          v28 = v55;
          v25 = v56;
          v24 = v57;
          v29 = 1;
        }
      }
      v31 = (UnitCubeSide *)((char *)v31 + 4);
      ++v30;
      --v32;
    }
    while ( v32 );
    ++v26;
    v4->mSideVertexCount[v4->mCurrentSide++] = v4->mCurrentSideVertexCount;
    v4->mCurrentSideVertexCount = 0;
    --v27;
  }
  while ( v27 );
  v63 = v3->x;
  v64 = v3->z;
  v65 = v3->w;
  v4->mPlane.y = v3->y;
  v4->mPlane.x = v63;
  v4->mPlane.z = v64;
  v4->mPlane.w = v65;
}

// File Line: 207
// RVA: 0x6DCC0
__int64 __fastcall ClipCube::GetClipCount(ClipCube *this)
{
  __int64 result; // rax
  bool *v2; // rcx
  signed __int64 v3; // rdx

  result = 0i64;
  v2 = &this->mEdgeHasClipVert[1];
  v3 = 2i64;
  do
  {
    if ( *(v2 - 1) )
      result = (unsigned int)(result + 1);
    if ( *v2 )
      result = (unsigned int)(result + 1);
    if ( v2[1] )
      result = (unsigned int)(result + 1);
    if ( v2[2] )
      result = (unsigned int)(result + 1);
    if ( v2[3] )
      result = (unsigned int)(result + 1);
    if ( v2[4] )
      result = (unsigned int)(result + 1);
    v2 += 6;
    --v3;
  }
  while ( v3 );
  return result;
}

// File Line: 220
// RVA: 0x6D8F0
UFG::qVector3 *__fastcall ClipCube::GenerateCube(ClipCube *this, unsigned int *vertex_count)
{
  unsigned int *v2; // r12
  ClipCube *v3; // rbp
  unsigned int v4; // eax
  unsigned int v5; // ebx
  int v6; // er8
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int *v9; // rdi
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  char *v16; // rax
  unsigned int v17; // er14
  char *v18; // r15
  unsigned int v19; // esi
  UFG::qVector3 verts; // [rsp+20h] [rbp-A8h]

  v2 = vertex_count;
  v3 = this;
  v4 = ClipCube::GenerateCCWClipVerts(this, &verts);
  v5 = 0;
  v6 = v4 - 2;
  v7 = v4;
  if ( v4 < 3 )
    v6 = 0;
  v8 = v3->mSideVertexCount[0];
  v9 = v3->mSideVertexCount;
  if ( v8 >= 3 )
    v6 = v8 + v6 - 2;
  v10 = v3->mSideVertexCount[1];
  if ( v10 >= 3 )
    v6 = v10 + v6 - 2;
  v11 = v3->mSideVertexCount[2];
  if ( v11 >= 3 )
    v6 = v11 + v6 - 2;
  v12 = v3->mSideVertexCount[3];
  if ( v12 >= 3 )
    v6 = v12 + v6 - 2;
  v13 = v3->mSideVertexCount[4];
  if ( v13 >= 3 )
    v6 = v13 + v6 - 2;
  v14 = v3->mSideVertexCount[5];
  if ( v14 >= 3 )
    v6 = v14 + v6 - 2;
  if ( !v6 )
    return 0i64;
  v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 36 * v6, 0x10u);
  v17 = 0;
  v18 = v16;
  if ( v7 >= 3 )
  {
    ClipCube::GeneratePoly(v3, (UFG::qVector3 *)v16, &verts, v7);
    v17 = 3 * (v7 - 2);
  }
  do
  {
    v19 = *v9;
    if ( *v9 >= 3 )
    {
      ClipCube::GeneratePoly(v3, (UFG::qVector3 *)&v18[12 * v17], v3->mSideVertices[v5], v19);
      v17 += v19 - 2 + 2 * (v19 - 2);
    }
    ++v5;
    ++v9;
  }
  while ( v5 < 6 );
  *v2 = v17;
  return (UFG::qVector3 *)v18;
}

// File Line: 291
// RVA: 0x6D390
__int64 __fastcall ClipCube::GenerateCCWClipVerts(ClipCube *this, UFG::qVector3 *verts)
{
  float v2; // xmm6_4
  unsigned int v3; // esi
  float v4; // xmm7_4
  UFG::qVector3 *v5; // r14
  unsigned int v6; // ebx
  bool *v7; // r9
  signed __int64 v8; // r10
  float *v9; // r8
  float v10; // xmm8_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  __int64 v14; // rax
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  __int64 v18; // rax
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  __int64 v22; // rax
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  __int64 v26; // rax
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  __int64 v30; // rax
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  __int64 v34; // rax
  float v36; // xmm11_4
  __m128 v37; // xmm12
  float v38; // xmm13_4
  float v39; // xmm1_4
  float v40; // xmm6_4
  float v41; // xmm7_4
  float v42; // xmm8_4
  __m128 v43; // xmm2
  float v44; // xmm1_4
  float v45; // xmm12_4
  float v46; // xmm13_4
  float v47; // xmm11_4
  float v48; // xmm15_4
  float *v49; // rdi
  __int64 v50; // rbp
  float v51; // xmm5_4
  __m128 v52; // xmm4
  float v53; // xmm9_4
  __m128 v54; // xmm2
  float v55; // xmm1_4
  signed __int64 v56; // r9
  char *v57; // rcx
  signed __int64 v58; // rdx
  unsigned int v59; // eax
  __int64 v60; // r8
  int v61; // eax
  char *v62; // r8
  signed __int64 v63; // rdx
  __int64 v64; // r9
  int v65; // ecx
  ClipPolyVertex right; // [rsp+10h] [rbp-188h]
  ClipPolyVertex left[2]; // [rsp+20h] [rbp-178h]
  float v68; // [rsp+40h] [rbp-158h]
  float v69; // [rsp+44h] [rbp-154h]
  float v70; // [rsp+48h] [rbp-150h]
  float v71; // [rsp+1B0h] [rbp+18h]
  float v72; // [rsp+1B8h] [rbp+20h]

  v2 = UFG::qVector3::msZero.x;
  v3 = 0;
  v4 = UFG::qVector3::msZero.y;
  v5 = verts;
  v6 = 0;
  v7 = &this->mEdgeHasClipVert[1];
  v8 = 2i64;
  v9 = &this->mEdgeClipVert[0].z;
  v10 = UFG::qVector3::msZero.z;
  do
  {
    if ( *(v7 - 1) )
    {
      v11 = *(v9 - 2);
      v12 = *(v9 - 1);
      v13 = *v9;
      v14 = v6++;
      left[v14].mPoint.x = v11;
      left[v14].mPoint.y = v12;
      left[v14].mPoint.z = v13;
      v2 = v2 + v11;
      v4 = v4 + v12;
      v10 = v10 + v13;
    }
    if ( *v7 )
    {
      v15 = v9[1];
      v16 = v9[2];
      v17 = v9[3];
      v18 = v6++;
      left[v18].mPoint.x = v15;
      left[v18].mPoint.y = v16;
      v2 = v2 + v15;
      left[v18].mPoint.z = v17;
      v4 = v4 + v16;
      v10 = v10 + v17;
    }
    if ( v7[1] )
    {
      v19 = v9[4];
      v20 = v9[5];
      v21 = v9[6];
      v22 = v6++;
      left[v22].mPoint.x = v19;
      left[v22].mPoint.y = v20;
      v2 = v2 + v19;
      left[v22].mPoint.z = v21;
      v4 = v4 + v20;
      v10 = v10 + v21;
    }
    if ( v7[2] )
    {
      v23 = v9[7];
      v24 = v9[8];
      v25 = v9[9];
      v26 = v6++;
      left[v26].mPoint.x = v23;
      left[v26].mPoint.y = v24;
      v2 = v2 + v23;
      left[v26].mPoint.z = v25;
      v4 = v4 + v24;
      v10 = v10 + v25;
    }
    if ( v7[3] )
    {
      v27 = v9[10];
      v28 = v9[11];
      v29 = v9[12];
      v30 = v6++;
      left[v30].mPoint.x = v27;
      left[v30].mPoint.y = v28;
      v2 = v2 + v27;
      left[v30].mPoint.z = v29;
      v4 = v4 + v28;
      v10 = v10 + v29;
    }
    if ( v7[4] )
    {
      v31 = v9[13];
      v32 = v9[14];
      v33 = v9[15];
      v34 = v6++;
      left[v34].mPoint.x = v31;
      left[v34].mPoint.y = v32;
      v2 = v2 + v31;
      left[v34].mPoint.z = v33;
      v4 = v4 + v32;
      v10 = v10 + v33;
    }
    v9 += 18;
    v7 += 6;
    --v8;
  }
  while ( v8 );
  if ( v6 < 3 )
    return 0i64;
  v36 = left[0].mPoint.x - v68;
  v37 = (__m128)LODWORD(left[0].mPoint.y);
  v37.m128_f32[0] = left[0].mPoint.y - v69;
  v38 = left[0].mPoint.z - v70;
  v43 = v37;
  v39 = 1.0 / (float)(signed int)v6;
  v40 = v2 * v39;
  v41 = v4 * v39;
  v42 = v10 * v39;
  v43.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v36 * v36)) + (float)(v38 * v38);
  if ( v43.m128_f32[0] == 0.0 )
    v44 = 0.0;
  else
    v44 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v43));
  v45 = v37.m128_f32[0] * v44;
  v46 = v38 * v44;
  v47 = v36 * v44;
  v71 = (float)(this->mPlane.y * v46) - (float)(this->mPlane.z * v45);
  v48 = (float)(this->mPlane.z * v47) - (float)(this->mPlane.x * v46);
  v72 = (float)(this->mPlane.x * v45) - (float)(this->mPlane.y * v47);
  if ( v6 )
  {
    v49 = &left[0].mPoint.z;
    v50 = v6;
    do
    {
      v52 = (__m128)*((unsigned int *)v49 - 1);
      v51 = *(v49 - 2) - v40;
      v52.m128_f32[0] = v52.m128_f32[0] - v41;
      v53 = *v49 - v42;
      v54 = v52;
      v54.m128_f32[0] = (float)((float)(v52.m128_f32[0] * v52.m128_f32[0]) + (float)(v51 * v51)) + (float)(v53 * v53);
      if ( v54.m128_f32[0] == 0.0 )
        v55 = 0.0;
      else
        v55 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v54));
      v49 += 4;
      *(v49 - 3) = atan2f(
                     (float)((float)((float)(v52.m128_f32[0] * v55) * v48) + (float)((float)(v51 * v55) * v71))
                   + (float)((float)(v53 * v55) * v72),
                     (float)((float)((float)(v52.m128_f32[0] * v55) * v45) + (float)((float)(v51 * v55) * v47))
                   + (float)((float)(v53 * v55) * v46));
      --v50;
    }
    while ( v50 );
  }
  ___qQuickSortImpl_UClipPolyVertex__A0xe5afcb50__P6A_NAEBU12_0_Z_UFG__YAXPEAUClipPolyVertex__A0xe5afcb50__0P6A_NAEBU12_1_Z_Z(
    left,
    &right + (signed int)v6,
    `anonymous namespace::ClipPolyVertexCompare);
  v56 = 0i64;
  if ( (signed int)v6 >= 4 )
  {
    v57 = (char *)&left[0].mPoint.z;
    v58 = (signed __int64)&v5[1].z;
    v59 = ((v6 - 4) >> 2) + 1;
    v60 = v59;
    v3 = 4 * v59;
    v56 = 4i64 * v59;
    do
    {
      v61 = *((_DWORD *)v57 - 2);
      v58 += 48i64;
      v57 += 64;
      *(_DWORD *)(v58 - 68) = v61;
      *(_DWORD *)(v58 - 64) = *((_DWORD *)v57 - 17);
      *(_DWORD *)(v58 - 60) = *((_DWORD *)v57 - 16);
      *(_DWORD *)(v58 - 56) = *((_DWORD *)v57 - 14);
      *(_DWORD *)(v58 - 52) = *((_DWORD *)v57 - 13);
      *(_DWORD *)(v58 - 48) = *((_DWORD *)v57 - 12);
      *(_DWORD *)(v58 - 44) = *((_DWORD *)v57 - 10);
      *(_DWORD *)(v58 - 40) = *((_DWORD *)v57 - 9);
      *(_DWORD *)(v58 - 36) = *((_DWORD *)v57 - 8);
      *(_DWORD *)(v58 - 32) = *((_DWORD *)v57 - 6);
      *(_DWORD *)(v58 - 28) = *((_DWORD *)v57 - 5);
      *(_DWORD *)(v58 - 24) = *((_DWORD *)v57 - 4);
      --v60;
    }
    while ( v60 );
  }
  if ( v3 < v6 )
  {
    v62 = (char *)&left[v56].mPoint.z;
    v63 = (signed __int64)v5 + 4 * (v56 + 2 * (v56 + 1));
    v64 = v6 - v3;
    do
    {
      v65 = *((_DWORD *)v62 - 2);
      v63 += 12i64;
      v62 += 16;
      *(_DWORD *)(v63 - 20) = v65;
      *(_DWORD *)(v63 - 16) = *((_DWORD *)v62 - 5);
      *(_DWORD *)(v63 - 12) = *((_DWORD *)v62 - 4);
      --v64;
    }
    while ( v64 );
  }
  return v6;
}

// File Line: 333
// RVA: 0x6DA50
void __fastcall ClipCube::GeneratePoly(ClipCube *this, UFG::qVector3 *out_verts, UFG::qVector3 *verts, unsigned int count)
{
  unsigned int v4; // er9
  unsigned int v5; // er11
  UFG::qVector3 *v6; // r10
  char *v7; // r8
  float *v8; // rcx
  unsigned int v9; // eax
  __int64 v10; // rbx
  float v11; // xmm0_4
  float v12; // xmm1_4
  int v13; // xmm0_4
  int v14; // eax
  int v15; // xmm1_4
  int v16; // xmm2_4
  int v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  int v20; // xmm2_4
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  int v26; // xmm2_4
  int v27; // xmm0_4
  int v28; // xmm1_4
  int v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  int v32; // xmm2_4
  int v33; // xmm0_4
  int v34; // xmm1_4
  int v35; // xmm2_4
  char *v36; // rdx
  __int64 v37; // r9
  signed __int64 v38; // r8
  signed __int64 v39; // rcx
  float v40; // xmm0_4
  float v41; // xmm1_4
  int v42; // eax
  int v43; // xmm0_4
  int v44; // xmm1_4
  int v45; // xmm2_4

  v4 = count - 2;
  v5 = 0;
  v6 = verts;
  if ( (signed int)v4 >= 4 )
  {
    v7 = (char *)&verts[2].y;
    v8 = &out_verts[1].z;
    v9 = ((v4 - 4) >> 2) + 1;
    v10 = v9;
    v5 = 4 * v9;
    do
    {
      v11 = v6->y;
      v12 = v6->z;
      out_verts->x = v6->x;
      out_verts += 12;
      v8 += 36;
      *(v8 - 40) = v11;
      *(v8 - 39) = v12;
      v13 = *((_DWORD *)v7 - 3);
      v14 = *((_DWORD *)v7 - 4);
      v7 += 48;
      v15 = *((_DWORD *)v7 - 14);
      *((_DWORD *)v8 - 38) = v14;
      *((_DWORD *)v8 - 37) = v13;
      *((_DWORD *)v8 - 36) = v15;
      v16 = *((_DWORD *)v7 - 12);
      v17 = *((_DWORD *)v7 - 11);
      *(v8 - 35) = *((float *)v7 - 13);
      *((_DWORD *)v8 - 34) = v16;
      *((_DWORD *)v8 - 33) = v17;
      v18 = v6->y;
      v19 = v6->z;
      *(v8 - 32) = v6->x;
      *(v8 - 31) = v18;
      *(v8 - 30) = v19;
      v20 = *((_DWORD *)v7 - 12);
      v21 = *((_DWORD *)v7 - 11);
      *(v8 - 29) = *((float *)v7 - 13);
      *((_DWORD *)v8 - 28) = v20;
      *((_DWORD *)v8 - 27) = v21;
      v22 = *((_DWORD *)v7 - 9);
      v23 = *((_DWORD *)v7 - 8);
      *(v8 - 26) = *((float *)v7 - 10);
      *((_DWORD *)v8 - 25) = v22;
      *((_DWORD *)v8 - 24) = v23;
      v24 = v6->y;
      v25 = v6->z;
      *(v8 - 23) = v6->x;
      *(v8 - 22) = v24;
      *(v8 - 21) = v25;
      v26 = *((_DWORD *)v7 - 9);
      v27 = *((_DWORD *)v7 - 8);
      *(v8 - 20) = *((float *)v7 - 10);
      *((_DWORD *)v8 - 19) = v26;
      *((_DWORD *)v8 - 18) = v27;
      v28 = *((_DWORD *)v7 - 6);
      v29 = *((_DWORD *)v7 - 5);
      *(v8 - 17) = *((float *)v7 - 7);
      *((_DWORD *)v8 - 16) = v28;
      *((_DWORD *)v8 - 15) = v29;
      v30 = v6->y;
      v31 = v6->z;
      *(v8 - 14) = v6->x;
      *(v8 - 13) = v30;
      *(v8 - 12) = v31;
      v32 = *((_DWORD *)v7 - 6);
      v33 = *((_DWORD *)v7 - 5);
      *(v8 - 11) = *((float *)v7 - 7);
      *((_DWORD *)v8 - 10) = v32;
      *((_DWORD *)v8 - 9) = v33;
      v34 = *((_DWORD *)v7 - 3);
      v35 = *((_DWORD *)v7 - 2);
      *(v8 - 8) = *((float *)v7 - 4);
      *((_DWORD *)v8 - 7) = v34;
      *((_DWORD *)v8 - 6) = v35;
      --v10;
    }
    while ( v10 );
  }
  if ( v5 < v4 )
  {
    v36 = (char *)&out_verts[1].z;
    v37 = v4 - v5;
    v38 = (signed __int64)v6 + 4 * (v5 + 2 + 2 * (v5 + 2 + 1i64));
    v39 = (signed __int64)v6 + 4 * (v5 + 1 + 2 * (v5 + 1 + 1i64));
    do
    {
      v40 = v6->y;
      v41 = v6->z;
      *((_DWORD *)v36 - 5) = LODWORD(v6->x);
      v36 += 36;
      v39 += 12i64;
      *((float *)v36 - 13) = v40;
      *((float *)v36 - 12) = v41;
      v42 = *(_DWORD *)(v39 - 20);
      v38 += 12i64;
      v43 = *(_DWORD *)(v39 - 12);
      *((_DWORD *)v36 - 10) = *(_DWORD *)(v39 - 16);
      *((_DWORD *)v36 - 11) = v42;
      *((_DWORD *)v36 - 9) = v43;
      v44 = *(_DWORD *)(v38 - 16);
      v45 = *(_DWORD *)(v38 - 12);
      *((_DWORD *)v36 - 8) = *(_DWORD *)(v38 - 20);
      *((_DWORD *)v36 - 7) = v44;
      *((_DWORD *)v36 - 6) = v45;
      --v37;
    }
    while ( v37 );
  }
} *)v36 - 8) = *(

