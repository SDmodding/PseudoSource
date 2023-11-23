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
  *(_QWORD *)&this->mCurrentSide = 0i64;
  UFG::qMemSet(this->mSideVertexCount, 0, 0x18u);
  UFG::qMemSet(this->mEdgeHasClipVert, 0, 0xCu);
}

// File Line: 90
// RVA: 0x6DD10
void __fastcall ClipCube::Reset(ClipCube *this)
{
  *(_QWORD *)&this->mCurrentSide = 0i64;
  UFG::qMemSet(this->mSideVertexCount, 0, 0x18u);
  UFG::qMemSet(this->mEdgeHasClipVert, 0, 0xCu);
}

// File Line: 98
// RVA: 0x6CDF0
void __fastcall ClipCube::ClipToPlane(ClipCube *this, UFG::qVector4 *plane)
{
  float y; // xmm8_4
  unsigned __int64 v5; // r9
  __int64 v6; // r10
  float x; // xmm9_4
  float z; // xmm10_4
  float w; // xmm11_4
  UFG::qVector4 *v10; // rax
  UFG::qVector4 *v11; // rcx
  float v12; // xmm12_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  int v18; // ecx
  float v19; // xmm4_4
  float v20; // xmm5_4
  int v21; // eax
  float v22; // xmm3_4
  int v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm1_4
  UnitCubeSide *v26; // rsi
  __int64 v27; // rbp
  float v28; // xmm2_4
  char v29; // r10
  bool *mEdgeFlipped; // r11
  UnitCubeSide *v31; // rbx
  __int64 v32; // rdi
  __int64 v33; // r9
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
  __int64 mCurrentSideVertexCount; // rdx
  __int64 v45; // rcx
  __int64 v46; // rax
  __int64 v47; // rdx
  __int64 v48; // rcx
  __int64 v49; // rax
  __int64 v50; // rdx
  bool v51; // zf
  __int64 v52; // rcx
  __int64 v53; // rax
  __int64 v54; // rcx
  float v55; // xmm3_4
  float v56; // xmm4_4
  float v57; // xmm5_4
  __int64 v58; // rax
  __int64 v59; // rdx
  __int64 v60; // rcx
  __int64 v61; // rax
  __int64 v62; // rcx
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // [rsp+0h] [rbp-138h]
  float v66; // [rsp+4h] [rbp-134h]
  float v67; // [rsp+8h] [rbp-130h]
  int v68[24]; // [rsp+10h] [rbp-128h]

  y = plane->y;
  v5 = 0i64;
  v6 = 12i64;
  x = plane->x;
  z = plane->z;
  w = plane->w;
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
    v22 = (float)((float)((float)(x * v17) + (float)(y * v16)) + (float)(z * v19)) + (float)(w * v20);
    if ( (float)((float)((float)((float)(x * v13) + (float)(y * v12)) + (float)(v14 * z)) + (float)(v15 * w)) < 0.0 )
      v18 = 2;
    LOBYTE(v21) = v22 < 0.0;
    v23 = v21 | v18;
    v68[v5] = v23;
    if ( v23 )
      *(float *)&v68[v5 + 1] = v22
                             / (float)((float)((float)((float)(y * (float)(v16 - v12)) + (float)(x * (float)(v17 - v13)))
                                             + (float)((float)(v19 - v14) * z))
                                     + (float)((float)(v20 - v15) * w));
    v5 += 2i64;
    --v6;
  }
  while ( v6 );
  v24 = v67;
  v25 = v66;
  v26 = `anonymous namespace::gUnitCubeSides;
  v27 = 6i64;
  v28 = v65;
  do
  {
    v29 = 0;
    mEdgeFlipped = v26->mEdgeFlipped;
    v31 = v26;
    v32 = 4i64;
    do
    {
      v33 = v31->mEdges[0];
      if ( *mEdgeFlipped )
      {
        v34 = 1.0 - *(float *)&v68[2 * v33 + 1];
        v35 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].x;
        v36 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].y;
        v37 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].z;
        v42 = &`anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mStartVertex];
        v38 = (unsigned int)v68[2 * v33] >> 1;
        v39 = v42->x;
        v40 = v42->y;
        v41 = v42->z;
        LOBYTE(v42) = v68[2 * v33];
      }
      else
      {
        LOBYTE(v38) = v68[2 * v33];
        v34 = *(float *)&v68[2 * v33 + 1];
        v35 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mStartVertex].x;
        v36 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mStartVertex].y;
        v37 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mStartVertex].z;
        v39 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].x;
        v40 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].y;
        v41 = `anonymous namespace::gUnitCubeVertices[`anonymous namespace::gUnitCubeEdges[v33].mEndVertex].z;
        LODWORD(v42) = (unsigned int)v68[2 * v33] >> 1;
      }
      v43 = (unsigned __int8)v42 & 1;
      if ( (v38 & 1) != 0 )
      {
        if ( !v43 )
        {
          v28 = (float)((float)(v39 - v35) * v34) + v35;
          v25 = (float)((float)(v40 - v36) * v34) + v36;
          v24 = (float)((float)(v41 - v37) * v34) + v37;
          if ( v29 )
          {
            mCurrentSideVertexCount = this->mCurrentSideVertexCount;
            v45 = 3 * (5i64 * this->mCurrentSide + mCurrentSideVertexCount + 4);
            this->mCurrentSideVertexCount = mCurrentSideVertexCount + 1;
            *(&this->mPlane.x + v45) = v28;
            *(&this->mPlane.y + v45) = v25;
            *(&this->mPlane.z + v45) = v24;
            if ( !this->mEdgeHasClipVert[v33] )
            {
              v46 = v33;
              this->mEdgeClipVert[v46].x = v28;
              this->mEdgeClipVert[v46].y = v25;
              this->mEdgeClipVert[v46].z = v24;
              this->mEdgeHasClipVert[v33] = 1;
            }
          }
          v47 = this->mCurrentSideVertexCount;
          v48 = 3 * (5i64 * this->mCurrentSide + v47 + 4);
          this->mCurrentSideVertexCount = v47 + 1;
          *(&this->mPlane.x + v48) = v39;
          *(&this->mPlane.y + v48) = v40;
          *(&this->mPlane.z + v48) = v41;
          if ( !this->mEdgeHasClipVert[v33] )
          {
            v49 = v33;
            this->mEdgeClipVert[v49].x = v28;
            this->mEdgeClipVert[v49].y = v25;
            this->mEdgeClipVert[v49].z = v24;
            this->mEdgeHasClipVert[v33] = 1;
          }
          v29 = 1;
        }
      }
      else
      {
        v50 = this->mCurrentSideVertexCount;
        v51 = v43 == 0;
        v52 = 5i64 * this->mCurrentSide;
        v53 = v50 + 4;
        if ( v51 )
        {
          v62 = 3 * (v52 + v53);
          this->mCurrentSideVertexCount = v50 + 1;
          *(&this->mPlane.x + v62) = v39;
          *(&this->mPlane.y + v62) = v40;
          *(&this->mPlane.z + v62) = v41;
        }
        else
        {
          v54 = 3 * (v52 + v53);
          this->mCurrentSideVertexCount = v50 + 1;
          v55 = (float)((float)(v39 - v35) * v34) + v35;
          v56 = (float)((float)(v40 - v36) * v34) + v36;
          v57 = (float)((float)(v41 - v37) * v34) + v37;
          *(&this->mPlane.x + v54) = v55;
          *(&this->mPlane.y + v54) = v56;
          *(&this->mPlane.z + v54) = v57;
          if ( !this->mEdgeHasClipVert[v33] )
          {
            v58 = v33;
            this->mEdgeClipVert[v58].x = v55;
            this->mEdgeClipVert[v58].y = v56;
            this->mEdgeClipVert[v58].z = v57;
            this->mEdgeHasClipVert[v33] = 1;
          }
          if ( v29 )
          {
            v59 = this->mCurrentSideVertexCount;
            v60 = 3 * (5i64 * this->mCurrentSide + v59 + 4);
            this->mCurrentSideVertexCount = v59 + 1;
            *(&this->mPlane.x + v60) = v28;
            *(&this->mPlane.y + v60) = v25;
            *(&this->mPlane.z + v60) = v24;
            if ( !this->mEdgeHasClipVert[v33] )
            {
              v61 = v33;
              this->mEdgeClipVert[v61].x = v55;
              this->mEdgeClipVert[v61].y = v56;
              this->mEdgeClipVert[v61].z = v57;
              this->mEdgeHasClipVert[v33] = 1;
            }
          }
          v28 = v55;
          v25 = v56;
          v24 = v57;
          v29 = 1;
        }
      }
      v31 = (UnitCubeSide *)((char *)v31 + 4);
      ++mEdgeFlipped;
      --v32;
    }
    while ( v32 );
    ++v26;
    this->mSideVertexCount[this->mCurrentSide++] = this->mCurrentSideVertexCount;
    this->mCurrentSideVertexCount = 0;
    --v27;
  }
  while ( v27 );
  v63 = plane->z;
  v64 = plane->w;
  *(_QWORD *)&this->mPlane.x = *(_QWORD *)&plane->x;
  this->mPlane.z = v63;
  this->mPlane.w = v64;
}

// File Line: 207
// RVA: 0x6DCC0
__int64 __fastcall ClipCube::GetClipCount(ClipCube *this)
{
  __int64 result; // rax
  bool *v2; // rcx
  __int64 v3; // rdx

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
  unsigned int v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // r8d
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int *mSideVertexCount; // rdi
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  char *v16; // rax
  unsigned int v17; // r14d
  char *v18; // r15
  unsigned int v19; // esi
  UFG::qVector3 verts; // [rsp+20h] [rbp-A8h] BYREF

  v4 = ClipCube::GenerateCCWClipVerts(this, &verts);
  v5 = 0;
  v6 = v4 - 2;
  v7 = v4;
  if ( v4 < 3 )
    v6 = 0;
  v8 = this->mSideVertexCount[0];
  mSideVertexCount = this->mSideVertexCount;
  if ( v8 >= 3 )
    v6 = v8 + v6 - 2;
  v10 = this->mSideVertexCount[1];
  if ( v10 >= 3 )
    v6 = v10 + v6 - 2;
  v11 = this->mSideVertexCount[2];
  if ( v11 >= 3 )
    v6 = v11 + v6 - 2;
  v12 = this->mSideVertexCount[3];
  if ( v12 >= 3 )
    v6 = v12 + v6 - 2;
  v13 = this->mSideVertexCount[4];
  if ( v13 >= 3 )
    v6 = v13 + v6 - 2;
  v14 = this->mSideVertexCount[5];
  if ( v14 >= 3 )
    v6 = v14 + v6 - 2;
  if ( !v6 )
    return 0i64;
  v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 36 * v6, 0x10u);
  v17 = 0;
  v18 = v16;
  if ( v7 >= 3 )
  {
    ClipCube::GeneratePoly(this, (UFG::qVector3 *)v16, &verts, v7);
    v17 = 3 * (v7 - 2);
  }
  do
  {
    v19 = *mSideVertexCount;
    if ( *mSideVertexCount >= 3 )
    {
      ClipCube::GeneratePoly(this, (UFG::qVector3 *)&v18[12 * v17], this->mSideVertices[v5], v19);
      v17 += v19 - 2 + 2 * (v19 - 2);
    }
    ++v5;
    ++mSideVertexCount;
  }
  while ( v5 < 6 );
  *vertex_count = v17;
  return (UFG::qVector3 *)v18;
}

// File Line: 291
// RVA: 0x6D390
__int64 __fastcall ClipCube::GenerateCCWClipVerts(ClipCube *this, UFG::qVector3 *verts)
{
  float x; // xmm6_4
  unsigned int v3; // esi
  float y; // xmm7_4
  unsigned int v6; // ebx
  bool *v7; // r9
  __int64 v8; // r10
  float *p_z; // r8
  float z; // xmm8_4
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
  __m128 y_low; // xmm12
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
  __int64 v56; // r9
  float *v57; // rcx
  char *v58; // rdx
  unsigned int v59; // eax
  __int64 v60; // r8
  int v61; // eax
  float *v62; // r8
  float *v63; // rdx
  __int64 v64; // r9
  int v65; // ecx
  ClipPolyVertex right; // [rsp+10h] [rbp-188h] BYREF
  ClipPolyVertex left[2]; // [rsp+20h] [rbp-178h] BYREF
  float v68; // [rsp+40h] [rbp-158h]
  float v69; // [rsp+44h] [rbp-154h]
  float v70; // [rsp+48h] [rbp-150h]
  float v71; // [rsp+1B0h] [rbp+18h]
  float v72; // [rsp+1B8h] [rbp+20h]

  x = UFG::qVector3::msZero.x;
  v3 = 0;
  y = UFG::qVector3::msZero.y;
  v6 = 0;
  v7 = &this->mEdgeHasClipVert[1];
  v8 = 2i64;
  p_z = &this->mEdgeClipVert[0].z;
  z = UFG::qVector3::msZero.z;
  do
  {
    if ( *(v7 - 1) )
    {
      v11 = *(p_z - 2);
      v12 = *(p_z - 1);
      v13 = *p_z;
      v14 = v6++;
      left[v14].mPoint.x = v11;
      left[v14].mPoint.y = v12;
      left[v14].mPoint.z = v13;
      x = x + v11;
      y = y + v12;
      z = z + v13;
    }
    if ( *v7 )
    {
      v15 = p_z[1];
      v16 = p_z[2];
      v17 = p_z[3];
      v18 = v6++;
      left[v18].mPoint.x = v15;
      left[v18].mPoint.y = v16;
      x = x + v15;
      left[v18].mPoint.z = v17;
      y = y + v16;
      z = z + v17;
    }
    if ( v7[1] )
    {
      v19 = p_z[4];
      v20 = p_z[5];
      v21 = p_z[6];
      v22 = v6++;
      left[v22].mPoint.x = v19;
      left[v22].mPoint.y = v20;
      x = x + v19;
      left[v22].mPoint.z = v21;
      y = y + v20;
      z = z + v21;
    }
    if ( v7[2] )
    {
      v23 = p_z[7];
      v24 = p_z[8];
      v25 = p_z[9];
      v26 = v6++;
      left[v26].mPoint.x = v23;
      left[v26].mPoint.y = v24;
      x = x + v23;
      left[v26].mPoint.z = v25;
      y = y + v24;
      z = z + v25;
    }
    if ( v7[3] )
    {
      v27 = p_z[10];
      v28 = p_z[11];
      v29 = p_z[12];
      v30 = v6++;
      left[v30].mPoint.x = v27;
      left[v30].mPoint.y = v28;
      x = x + v27;
      left[v30].mPoint.z = v29;
      y = y + v28;
      z = z + v29;
    }
    if ( v7[4] )
    {
      v31 = p_z[13];
      v32 = p_z[14];
      v33 = p_z[15];
      v34 = v6++;
      left[v34].mPoint.x = v31;
      left[v34].mPoint.y = v32;
      x = x + v31;
      left[v34].mPoint.z = v33;
      y = y + v32;
      z = z + v33;
    }
    p_z += 18;
    v7 += 6;
    --v8;
  }
  while ( v8 );
  if ( v6 < 3 )
    return 0i64;
  v36 = left[0].mPoint.x - v68;
  y_low = (__m128)LODWORD(left[0].mPoint.y);
  y_low.m128_f32[0] = left[0].mPoint.y - v69;
  v38 = left[0].mPoint.z - v70;
  v43 = y_low;
  v39 = 1.0 / (float)(int)v6;
  v40 = x * v39;
  v41 = y * v39;
  v42 = z * v39;
  v43.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v36 * v36)) + (float)(v38 * v38);
  if ( v43.m128_f32[0] == 0.0 )
    v44 = 0.0;
  else
    v44 = 1.0 / _mm_sqrt_ps(v43).m128_f32[0];
  v45 = y_low.m128_f32[0] * v44;
  v46 = v38 * v44;
  v47 = v36 * v44;
  v71 = (float)(this->mPlane.y * v46) - (float)(this->mPlane.z * v45);
  v48 = (float)(this->mPlane.z * v47) - (float)(this->mPlane.x * v46);
  v72 = (float)(this->mPlane.x * v45) - (float)(this->mPlane.y * v47);
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
      v55 = 1.0 / _mm_sqrt_ps(v54).m128_f32[0];
    v49 += 4;
    *(v49 - 3) = atan2f(
                   (float)((float)((float)(v52.m128_f32[0] * v55) * v48) + (float)((float)(v51 * v55) * v71))
                 + (float)((float)(v53 * v55) * v72),
                   (float)((float)((float)(v52.m128_f32[0] * v55) * v45) + (float)((float)(v51 * v55) * v47))
                 + (float)((float)(v53 * v55) * v46));
    --v50;
  }
  while ( v50 );
  UFG::qQuickSortImpl<`anonymous namespace::ClipPolyVertex,bool (*)(A0xe5afcb50::ClipPolyVertex const &,A0xe5afcb50::ClipPolyVertex const &)>(
    left,
    &right + (int)v6,
    `anonymous namespace::ClipPolyVertexCompare);
  v56 = 0i64;
  if ( (int)v6 >= 4 )
  {
    v57 = &left[0].mPoint.z;
    v58 = (char *)&verts[1].z;
    v59 = ((v6 - 4) >> 2) + 1;
    v60 = v59;
    v3 = 4 * v59;
    v56 = 4i64 * v59;
    do
    {
      v61 = *((_DWORD *)v57 - 2);
      v58 += 48;
      v57 += 16;
      *((_DWORD *)v58 - 17) = v61;
      *((float *)v58 - 16) = *(v57 - 17);
      *((float *)v58 - 15) = *(v57 - 16);
      *((float *)v58 - 14) = *(v57 - 14);
      *((float *)v58 - 13) = *(v57 - 13);
      *((float *)v58 - 12) = *(v57 - 12);
      *((float *)v58 - 11) = *(v57 - 10);
      *((float *)v58 - 10) = *(v57 - 9);
      *((float *)v58 - 9) = *(v57 - 8);
      *((float *)v58 - 8) = *(v57 - 6);
      *((float *)v58 - 7) = *(v57 - 5);
      *((float *)v58 - 6) = *(v57 - 4);
      --v60;
    }
    while ( v60 );
  }
  if ( v3 < v6 )
  {
    v62 = &left[v56].mPoint.z;
    v63 = &verts->z + 2 * v56 + v56;
    v64 = v6 - v3;
    do
    {
      v65 = *((_DWORD *)v62 - 2);
      v63 += 3;
      v62 += 4;
      *((_DWORD *)v63 - 5) = v65;
      *(v63 - 4) = *(v62 - 5);
      *(v63 - 3) = *(v62 - 4);
      --v64;
    }
    while ( v64 );
  }
  return v6;
}

// File Line: 333
// RVA: 0x6DA50
void __fastcall ClipCube::GeneratePoly(
        ClipCube *this,
        UFG::qVector3 *out_verts,
        UFG::qVector3 *verts,
        unsigned int count)
{
  int v4; // r9d
  unsigned int v5; // r11d
  char *p_y; // r8
  float *p_z; // rcx
  unsigned int v9; // eax
  __int64 v10; // rbx
  float y; // xmm0_4
  float z; // xmm1_4
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
  float *v38; // r8
  float *v39; // rcx
  float v40; // xmm0_4
  float v41; // xmm1_4
  int v42; // eax
  int v43; // xmm0_4
  int v44; // xmm1_4
  int v45; // xmm2_4

  v4 = count - 2;
  v5 = 0;
  if ( v4 >= 4 )
  {
    p_y = (char *)&verts[2].y;
    p_z = &out_verts[1].z;
    v9 = ((unsigned int)(v4 - 4) >> 2) + 1;
    v10 = v9;
    v5 = 4 * v9;
    do
    {
      y = verts->y;
      z = verts->z;
      out_verts->x = verts->x;
      out_verts += 12;
      p_z += 36;
      *(p_z - 40) = y;
      *(p_z - 39) = z;
      v13 = *((_DWORD *)p_y - 3);
      v14 = *((_DWORD *)p_y - 4);
      p_y += 48;
      v15 = *((_DWORD *)p_y - 14);
      *((_DWORD *)p_z - 38) = v14;
      *((_DWORD *)p_z - 37) = v13;
      *((_DWORD *)p_z - 36) = v15;
      v16 = *((_DWORD *)p_y - 12);
      v17 = *((_DWORD *)p_y - 11);
      *(p_z - 35) = *((float *)p_y - 13);
      *((_DWORD *)p_z - 34) = v16;
      *((_DWORD *)p_z - 33) = v17;
      v18 = verts->y;
      v19 = verts->z;
      *(p_z - 32) = verts->x;
      *(p_z - 31) = v18;
      *(p_z - 30) = v19;
      v20 = *((_DWORD *)p_y - 12);
      v21 = *((_DWORD *)p_y - 11);
      *(p_z - 29) = *((float *)p_y - 13);
      *((_DWORD *)p_z - 28) = v20;
      *((_DWORD *)p_z - 27) = v21;
      v22 = *((_DWORD *)p_y - 9);
      v23 = *((_DWORD *)p_y - 8);
      *(p_z - 26) = *((float *)p_y - 10);
      *((_DWORD *)p_z - 25) = v22;
      *((_DWORD *)p_z - 24) = v23;
      v24 = verts->y;
      v25 = verts->z;
      *(p_z - 23) = verts->x;
      *(p_z - 22) = v24;
      *(p_z - 21) = v25;
      v26 = *((_DWORD *)p_y - 9);
      v27 = *((_DWORD *)p_y - 8);
      *(p_z - 20) = *((float *)p_y - 10);
      *((_DWORD *)p_z - 19) = v26;
      *((_DWORD *)p_z - 18) = v27;
      v28 = *((_DWORD *)p_y - 6);
      v29 = *((_DWORD *)p_y - 5);
      *(p_z - 17) = *((float *)p_y - 7);
      *((_DWORD *)p_z - 16) = v28;
      *((_DWORD *)p_z - 15) = v29;
      v30 = verts->y;
      v31 = verts->z;
      *(p_z - 14) = verts->x;
      *(p_z - 13) = v30;
      *(p_z - 12) = v31;
      v32 = *((_DWORD *)p_y - 6);
      v33 = *((_DWORD *)p_y - 5);
      *(p_z - 11) = *((float *)p_y - 7);
      *((_DWORD *)p_z - 10) = v32;
      *((_DWORD *)p_z - 9) = v33;
      v34 = *((_DWORD *)p_y - 3);
      v35 = *((_DWORD *)p_y - 2);
      *(p_z - 8) = *((float *)p_y - 4);
      *((_DWORD *)p_z - 7) = v34;
      *((_DWORD *)p_z - 6) = v35;
      --v10;
    }
    while ( v10 );
  }
  if ( v5 < v4 )
  {
    v36 = (char *)&out_verts[1].z;
    v37 = v4 - v5;
    v38 = &verts[2].z + 2 * v5 + v5;
    v39 = &verts[1].z + 2 * v5 + v5;
    do
    {
      v40 = verts->y;
      v41 = verts->z;
      *((_DWORD *)v36 - 5) = LODWORD(verts->x);
      v36 += 36;
      v39 += 3;
      *((float *)v36 - 13) = v40;
      *((float *)v36 - 12) = v41;
      v42 = *((_DWORD *)v39 - 5);
      v38 += 3;
      v43 = *((_DWORD *)v39 - 3);
      *((float *)v36 - 10) = *(v39 - 4);
      *((_DWORD *)v36 - 11) = v42;
      *((_DWORD *)v36 - 9) = v43;
      v44 = *((_DWORD *)v38 - 4);
      v45 = *((_DWORD *)v38 - 3);
      *((float *)v36 - 8) = *(v38 - 5);
      *((_DWORD *)v36 - 7) = v44;
      *((_DWORD *)v36 - 6) = v45;
      --v37;
    }
    while ( v37 );
  }
}     *((float *)v36 - 8) = *(v38 - 5);
      

