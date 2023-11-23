// File Line: 24
// RVA: 0x451D00
void __fastcall UFG::WorldBoundaries::~WorldBoundaries(UFG::WorldBoundaries *this)
{
  Render::Skinning *p_mMappings; // rbx
  Render::SkinningCacheNode *Head; // rdi
  UFG::qVector3 *p; // rcx

  this->vfptr = (UFG::WorldBoundariesVtbl *)&UFG::WorldBoundaries::`vftable;
  p_mMappings = (Render::Skinning *)&this->mMappings;
  if ( this->mMappings.mTree.mCount )
  {
    do
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mMappings->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mMappings->mSkinnedVertexBuffers.mTree, &Head->mNode);
      if ( Head )
        operator delete[](Head);
    }
    while ( p_mMappings->mSkinnedVertexBuffers.mTree.mCount );
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mMappings);
  p = this->mWorldBoundaries.p;
  if ( p )
    operator delete[](p);
  this->mWorldBoundaries.p = 0i64;
  *(_QWORD *)&this->mWorldBoundaries.size = 0i64;
}

// File Line: 29
// RVA: 0x46A980
char __fastcall IsAtTheEndOfTheWorld(UFG::BSP *bsp, UFG::BSPSpace *space)
{
  unsigned int mFaceCount; // ebp
  int v3; // r9d
  __int64 mOffset; // rbx
  __int64 v7; // r14
  __int64 i; // r10
  char *v9; // rax
  char *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // r11
  char *v13; // rdx
  __int64 v14; // rax
  char *v15; // r8
  __int64 v16; // rax
  char *v17; // rdx

  mFaceCount = space->mFaceCount;
  v3 = 0;
  if ( !space->mFaceCount )
    return 0;
  mOffset = space->mFaces.mOffset;
  v7 = bsp->mFaces.mOffset;
  for ( i = 0i64; ; i += 4i64 )
  {
    v9 = mOffset ? (char *)&space->mFaces + mOffset : 0i64;
    v10 = v7 ? (char *)&bsp->mFaces + v7 : 0i64;
    v11 = *(unsigned int *)&v9[i];
    v12 = *(unsigned int *)&v10[8 * v11];
    v13 = &v10[8 * v11];
    if ( (_DWORD)v12 == -1 )
    {
      v14 = bsp->mSpaces.mOffset;
      v15 = v14 ? (char *)&bsp->mSpaces + v14 : 0i64;
      if ( space == (UFG::BSPSpace *)&v15[80 * *((unsigned int *)v13 + 1)] )
        break;
    }
    if ( *((_DWORD *)v13 + 1) == -1 )
    {
      v16 = bsp->mSpaces.mOffset;
      v17 = v16 ? (char *)&bsp->mSpaces + v16 : 0i64;
      if ( space == (UFG::BSPSpace *)&v17[80 * v12] )
        break;
    }
    if ( ++v3 >= mFaceCount )
      return 0;
  }
  return 1;
}

// File Line: 47
// RVA: 0x4698A0
void __fastcall UFG::WorldBoundaries::Initialize(UFG::WorldBoundaries *this)
{
  UFG::qArray<UFG::qVector3,0> *p_mWorldBoundaries; // r15
  UFG::qVector3 *p; // rcx
  UFG::qTreeRB<UFG::WorldBoundaries::WorldBoundaryNode,UFG::WorldBoundaries::WorldBoundaryNode,1> *p_mMappings; // r13
  UFG::BSP *BSP; // rbp
  char v6; // al
  UFG::BSPSpace *v7; // rsi
  int v8; // ebx
  unsigned int mSpaceCount; // edi
  __int64 mOffset; // rax
  char *v11; // rcx
  int v12; // eax
  UFG::BSPSpace *v13; // r12
  float x; // xmm6_4
  float y; // xmm7_4
  __int64 size; // r14
  unsigned int v17; // edi
  unsigned int capacity; // ebx
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rsi
  __int64 i; // rdx
  __int64 v23; // rcx
  UFG::qVector3 *v24; // rax
  float v25; // xmm1_4
  float z; // xmm2_4
  __int64 v27; // rcx
  UFG::qVector3 *v28; // rax
  UFG::allocator::free_link *v29; // rdx
  unsigned int v30; // ecx
  unsigned int mIndex; // eax
  __int64 v32; // rdi
  unsigned int mFaceCount; // r13d
  __int64 v34; // rsi
  __int64 v35; // r14
  __int64 v36; // rcx
  __int64 v37; // rdx
  __int64 v38; // rax
  __int64 v39; // r9
  unsigned int v40; // r10d
  __int64 v41; // rdx
  char *v42; // r8
  __int64 v43; // rcx
  __int64 v44; // rax
  UFG::BSPSpace *v45; // rbx
  UFG::qVector3 *v46; // rcx
  int v47; // [rsp+A0h] [rbp+8h]
  UFG::BSPSpace *v48; // [rsp+A8h] [rbp+10h]
  UFG::BSPSpace *v49; // [rsp+B0h] [rbp+18h]
  Render::Skinning *v50; // [rsp+B8h] [rbp+20h]

  p_mWorldBoundaries = &this->mWorldBoundaries;
  p = this->mWorldBoundaries.p;
  if ( p )
    operator delete[](p);
  p_mWorldBoundaries->p = 0i64;
  *(_QWORD *)&p_mWorldBoundaries->size = 0i64;
  UFG::qArray<UFG::qVector3,0>::Reallocate(p_mWorldBoundaries, 0x80u, "PhysicsSystem::CalculateWorldBoundaries()");
  p_mMappings = &this->mMappings;
  v50 = (Render::Skinning *)&this->mMappings;
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mMappings);
  BSP = UFG::SectionChooser::GetBSP();
  if ( BSP )
  {
    v6 = 0;
    v7 = 0i64;
    v48 = 0i64;
    v8 = 0;
    mSpaceCount = BSP->mSpaceCount;
    if ( mSpaceCount )
    {
      while ( !v6 )
      {
        mOffset = BSP->mSpaces.mOffset;
        if ( mOffset )
          v11 = (char *)&BSP->mSpaces + mOffset;
        else
          v11 = 0i64;
        v7 = (UFG::BSPSpace *)&v11[0x50 * v8];
        v48 = v7;
        v6 = IsAtTheEndOfTheWorld(BSP, v7);
        if ( ++v8 >= mSpaceCount )
        {
          if ( !v6 )
            return;
          break;
        }
      }
      v12 = 300;
      v49 = 0i64;
      v13 = v7;
      while ( 1 )
      {
        v47 = v12 - 1;
        x = v13->mCenter.x;
        y = v13->mCenter.y;
        size = p_mWorldBoundaries->size;
        v17 = size + 1;
        capacity = p_mWorldBoundaries->capacity;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v19 = 2 * capacity;
          else
            v19 = 1;
          for ( ; v19 < v17; v19 *= 2 )
            ;
          if ( v19 - v17 > 0x10000 )
            v19 = size + 65537;
          if ( v19 != (_DWORD)size )
          {
            v20 = 12i64 * v19;
            if ( !is_mul_ok(v19, 0xCui64) )
              v20 = -1i64;
            v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
            if ( p_mWorldBoundaries->p )
            {
              for ( i = 0i64; (unsigned int)i < p_mWorldBoundaries->size; i = (unsigned int)(i + 1) )
              {
                v23 = 3 * i;
                v24 = p_mWorldBoundaries->p;
                v25 = v24[i].y;
                z = v24[i].z;
                *((_DWORD *)&v21->mNext + v23) = LODWORD(v24[i].x);
                *((float *)&v21->mNext + v23 + 1) = v25;
                *((float *)&v21[1].mNext + v23) = z;
              }
              operator delete[](p_mWorldBoundaries->p);
            }
            p_mWorldBoundaries->p = (UFG::qVector3 *)v21;
            p_mWorldBoundaries->capacity = v19;
            v7 = v48;
          }
        }
        p_mWorldBoundaries->size = v17;
        v27 = size;
        v28 = p_mWorldBoundaries->p;
        v28[v27].x = x;
        v28[v27].y = y;
        v28[v27].z = 0.0;
        v29 = UFG::qMalloc(0x28ui64, "WorldBoundaryNodes", 0i64);
        if ( v29 )
        {
          v30 = p_mWorldBoundaries->size;
          mIndex = v13->mIndex;
          v29->mNext = 0i64;
          v29[1].mNext = 0i64;
          v29[2].mNext = 0i64;
          LODWORD(v29[3].mNext) = mIndex;
          LODWORD(v29[4].mNext) = v30 - 1;
        }
        else
        {
          v29 = 0i64;
        }
        UFG::qBaseTreeRB::Add(&p_mMappings->mTree, (UFG::qBaseNodeRB *)v29);
        v32 = 0i64;
        mFaceCount = v13->mFaceCount;
        if ( v13->mFaceCount )
        {
          v34 = v13->mFaces.mOffset;
          v35 = BSP->mFaces.mOffset;
          while ( 1 )
          {
            v36 = v34 ? (__int64)&v13->mFaces + v34 : 0i64;
            v37 = *(unsigned int *)(v36 + 4 * v32);
            v38 = v35 ? (__int64)&BSP->mFaces + v35 : 0i64;
            v39 = *(unsigned int *)(v38 + 8 * v37);
            if ( (_DWORD)v39 != -1 )
            {
              v40 = *(_DWORD *)(v38 + 8 * v37 + 4);
              if ( v40 != -1 )
              {
                v41 = BSP->mSpaces.mOffset;
                if ( v41 )
                  v42 = (char *)&BSP->mSpaces + v41;
                else
                  v42 = 0i64;
                if ( v13 == (UFG::BSPSpace *)&v42[80 * v39] )
                  v39 = v40;
                v43 = v41 ? (__int64)&BSP->mSpaces + v41 : 0i64;
                if ( v49 != (UFG::BSPSpace *)(v43 + 80 * v39) )
                {
                  v44 = v41 ? (__int64)&BSP->mSpaces + v41 : 0i64;
                  v45 = (UFG::BSPSpace *)(v44 + 80 * v39);
                  if ( IsAtTheEndOfTheWorld(BSP, v45) )
                    break;
                }
              }
            }
            v32 = (unsigned int)(v32 + 1);
            if ( (unsigned int)v32 >= mFaceCount )
              goto LABEL_57;
          }
          v49 = v13;
          v13 = v45;
LABEL_57:
          v7 = v48;
        }
        if ( v13 == v7 )
          break;
        v12 = v47;
        p_mMappings = (UFG::qTreeRB<UFG::WorldBoundaries::WorldBoundaryNode,UFG::WorldBoundaries::WorldBoundaryNode,1> *)v50;
        if ( v47 <= 0 )
          goto LABEL_63;
      }
      if ( v47 > 0 && p_mWorldBoundaries->size >= 3 )
        return;
LABEL_63:
      v46 = p_mWorldBoundaries->p;
      if ( v46 )
        operator delete[](v46);
      p_mWorldBoundaries->p = 0i64;
      *(_QWORD *)&p_mWorldBoundaries->size = 0i64;
      UFG::qBaseTreeRB::~qBaseTreeRB(v50);
    }
  }
}

// File Line: 181
// RVA: 0x475F60
void __fastcall UFG::WorldBoundaries::Shutdown(UFG::WorldBoundaries *this)
{
  UFG::qVector3 *p; // rcx
  Render::SkinningCacheNode *Head; // rbx

  p = this->mWorldBoundaries.p;
  if ( p )
    operator delete[](p);
  this->mWorldBoundaries.p = 0i64;
  *(_QWORD *)&this->mWorldBoundaries.size = 0i64;
  while ( this->mMappings.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mMappings);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mMappings,
      &Head->mNode);
    if ( Head )
      operator delete[](Head);
  }
}

// File Line: 197
// RVA: 0x467320
UFG::qVector3 *__fastcall UFG::WorldBoundaries::GetSegmentNormal(
        UFG::WorldBoundaries *this,
        UFG::qVector3 *result,
        UFG::qVector3 *a,
        UFG::qVector3 *b)
{
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  __int128 z_low; // xmm4
  float v9; // xmm3_4
  __m128 v10; // xmm6
  UFG::qVector3 *v11; // rax

  z_low = LODWORD(b->z);
  v4 = 0.0;
  v5 = b->y - a->y;
  v6 = b->x - a->x;
  *(float *)&z_low = (float)(*(float *)&z_low - a->z) * 0.0;
  v7 = v5 - *(float *)&z_low;
  *(float *)&z_low = *(float *)&z_low - v6;
  v10 = (__m128)z_low;
  v9 = (float)(v6 * 0.0) - (float)(v5 * 0.0);
  result->x = v7;
  LODWORD(result->y) = z_low;
  result->z = v9;
  v10.m128_f32[0] = (float)((float)(*(float *)&z_low * *(float *)&z_low) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] != 0.0 )
    v4 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v11 = result;
  result->x = v7 * v4;
  result->y = *(float *)&z_low * v4;
  result->z = v9 * v4;
  return v11;
}

// File Line: 209
// RVA: 0x466290
UFG::qVector3 *__fastcall GetClosestPointOnSegment(
        UFG::qVector3 *result,
        UFG::qVector3 *a,
        UFG::qVector3 *b,
        UFG::qVector3 *p,
        bool *isPastEdge)
{
  float v5; // xmm6_4
  float v6; // xmm3_4
  __m128 y_low; // xmm7
  __m128 v8; // xmm4
  float v9; // xmm2_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm9_4
  float v14; // xmm8_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm2_4

  y_low = (__m128)LODWORD(b->y);
  v5 = b->x - a->x;
  v6 = b->z - a->z;
  y_low.m128_f32[0] = y_low.m128_f32[0] - a->y;
  v8 = y_low;
  v8.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5)) + (float)(v6 * v6);
  if ( v8.m128_f32[0] == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
  v10 = v5 * v9;
  v11 = y_low.m128_f32[0] * v9;
  v12 = v9 * v6;
  v13 = p->x - a->x;
  v14 = p->y - a->y;
  LODWORD(v15) = _mm_sqrt_ps(v8).m128_u32[0];
  v16 = (float)((float)(v14 * v11) + (float)(v13 * v10)) + (float)((float)(p->z - a->z) * v12);
  if ( v16 <= 0.0 )
    v16 = 0.0;
  if ( v16 >= v15 )
    v16 = v15;
  v17 = (float)(v11 * v16) + a->y;
  v18 = (float)(v12 * v16) + a->z;
  result->x = (float)(v10 * v16) + a->x;
  result->y = v17;
  result->z = v18;
  *isPastEdge = (float)((float)(v14 * v10) - (float)(v13 * v11)) >= 0.0;
  return result;
}

// File Line: 228
// RVA: 0x46B120
char __fastcall UFG::WorldBoundaries::IsOutsideBoundaries(
        UFG::WorldBoundaries *this,
        UFG::qVector3 *pos,
        float radius,
        UFG::qVector3 *dir,
        float *distance)
{
  UFG::BSP *BSP; // rax
  UFG::BSPSpace *SpaceFromPoint; // rax
  unsigned int mIndex; // edx
  UFG::qBaseTreeRB *v13; // rax
  unsigned int size; // r9d
  UFG::qVector3 *v15; // r10
  unsigned int v16; // r8d
  float x; // xmm6_4
  UFG::qVector3 *v18; // r14
  UFG::qVector3 *v19; // rbp
  UFG::qVector3 *v20; // r15
  float v21; // xmm11_4
  float v22; // xmm14_4
  float v23; // xmm4_4
  float v24; // xmm10_4
  float y; // xmm15_4
  __m128 v26; // xmm3
  __m128 y_low; // xmm12
  float v28; // xmm6_4
  __m128 v29; // xmm7
  float v30; // xmm8_4
  UFG::qVector3 *SegmentNormal; // rax
  UFG::qVector3 *v32; // rax
  float v33; // xmm8_4
  float v34; // xmm6_4
  __m128 v35; // xmm2
  float v36; // xmm1_4
  float v37; // xmm0_4
  __int16 isPastEdge[2]; // [rsp+30h] [rbp-F8h] BYREF
  float z; // [rsp+34h] [rbp-F4h]
  float v40; // [rsp+38h] [rbp-F0h]
  UFG::qVector3 p; // [rsp+40h] [rbp-E8h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-D8h] BYREF
  UFG::qVector3 v43; // [rsp+60h] [rbp-C8h] BYREF

  BSP = UFG::SectionChooser::GetBSP();
  if ( !BSP )
    return 0;
  SpaceFromPoint = UFG::BSP::GetSpaceFromPoint(BSP, pos, 1, 0);
  if ( !SpaceFromPoint )
    return 0;
  mIndex = SpaceFromPoint->mIndex;
  if ( !mIndex )
    return 0;
  v13 = UFG::qBaseTreeRB::Get(&this->mMappings.mTree, mIndex);
  if ( !v13 )
    return 0;
  size = this->mWorldBoundaries.size;
  v15 = this->mWorldBoundaries.p;
  v16 = size + LODWORD(v13->mNULL.mParent);
  x = pos->x;
  p.z = 0.0;
  isPastEdge[0] = 0;
  p.x = x;
  p.y = pos->y;
  y_low = (__m128)LODWORD(p.y);
  v18 = &v15[(v16 - 1) % size];
  v19 = &v15[v16 % size];
  v20 = &v15[(v16 + 1) % size];
  GetClosestPointOnSegment(&result, v18, v19, &p, (bool *)isPastEdge);
  GetClosestPointOnSegment(&v43, v19, v20, &p, (bool *)isPastEdge + 1);
  v21 = FLOAT_N1_0;
  v26 = y_low;
  v22 = 0.0;
  v23 = radius * radius;
  v24 = FLOAT_N1_0;
  y = 0.0;
  v40 = radius * radius;
  z = 0.0;
  v26.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - result.y) * (float)(y_low.m128_f32[0] - result.y))
                          + (float)((float)(x - result.x) * (float)(x - result.x)))
                  + (float)(COERCE_FLOAT(LODWORD(result.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.z) ^ _xmm[0]));
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v43.y) * (float)(y_low.m128_f32[0] - v43.y))
                            + (float)((float)(x - v43.x) * (float)(x - v43.x)))
                    + (float)(COERCE_FLOAT(LODWORD(v43.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(v43.z) ^ _xmm[0]));
  v28 = 0.0;
  v29 = 0i64;
  v30 = 0.0;
  if ( v26.m128_f32[0] < (float)(radius * radius) && !LOBYTE(isPastEdge[0]) )
  {
    LODWORD(v21) = _mm_sqrt_ps(v26).m128_u32[0];
    SegmentNormal = UFG::WorldBoundaries::GetSegmentNormal(this, &v43, v18, v19);
    v23 = v40;
    v22 = SegmentNormal->x;
    y = SegmentNormal->y;
    z = SegmentNormal->z;
  }
  if ( y_low.m128_f32[0] < v23 && !HIBYTE(isPastEdge[0]) )
  {
    LODWORD(v24) = _mm_sqrt_ps(y_low).m128_u32[0];
    v32 = UFG::WorldBoundaries::GetSegmentNormal(this, &v43, v19, v20);
    v28 = v32->x;
    v29 = (__m128)LODWORD(v32->y);
    v30 = v32->z;
  }
  if ( v21 < 0.0 && v24 < 0.0 )
    return 0;
  v33 = v30 + z;
  v34 = v28 + v22;
  v29.m128_f32[0] = v29.m128_f32[0] + y;
  v35 = v29;
  v35.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v34 * v34)) + (float)(v33 * v33);
  if ( v35.m128_f32[0] == 0.0 )
    v36 = 0.0;
  else
    v36 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
  dir->x = v34 * v36;
  dir->y = v29.m128_f32[0] * v36;
  dir->z = v33 * v36;
  *distance = radius;
  if ( v21 >= 0.0 )
    *distance = v21;
  if ( v24 >= 0.0 )
  {
    v37 = *distance;
    if ( *distance >= v24 )
      v37 = v24;
    *distance = v37;
  }
  return 1;
}4 >= 0.0 )
  {
    v37 = *distance;
    if ( *distance >= v24 )
      v37 = v24;
    *distance = v37;
  }
 

// File Line: 296
// RVA: 0x46AFB0
char __fastcall UFG::WorldBoundaries::IsOutsideBoundaries2(
        UFG::WorldBoundaries *this,
        UFG::qVector3 *pos,
        float radius,
        UFG::qVector3 *dir)
{
  unsigned int size; // esi
  float y; // xmm1_4
  char v6; // bl
  float v10; // xmm6_4
  char result; // al
  unsigned int v12; // ebp
  __int64 v13; // rdi
  int v14; // xmm4_4
  int v15; // xmm3_4
  int v16; // xmm5_4
  float v17; // xmm2_4
  UFG::qVector3 b1; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector3 b0; // [rsp+40h] [rbp-38h] BYREF

  size = this->mWorldBoundaries.size;
  y = pos->y;
  v6 = 0;
  v10 = 0.0;
  b0.x = pos->x;
  b0.y = y;
  b0.z = 0.0;
  b1.x = 6000.0;
  *(_QWORD *)&b1.y = 1169915904i64;
  if ( !size )
    return 0;
  v12 = 0;
  v13 = 0i64;
  do
  {
    if ( UFG::WorldBoundaries::GetSegmentIntersection(
           this,
           &this->mWorldBoundaries.p[v13],
           &this->mWorldBoundaries.p[++v12 % size],
           &b0,
           &b1) )
    {
      ++v6;
    }
    ++v13;
  }
  while ( v12 < size );
  if ( (v6 & 1) != 0 )
    return 0;
  v14 = LODWORD(pos->y) ^ _xmm[0];
  v15 = LODWORD(pos->x) ^ _xmm[0];
  v16 = LODWORD(pos->z) ^ _xmm[0];
  v17 = (float)((float)(*(float *)&v14 * *(float *)&v14) + (float)(*(float *)&v15 * *(float *)&v15))
      + (float)(*(float *)&v16 * *(float *)&v16);
  if ( v17 != 0.0 )
    v10 = 1.0 / fsqrt(v17);
  result = 1;
  dir->x = *(float *)&v15 * v10;
  dir->y = *(float *)&v14 * v10;
  dir->z = *(float *)&v16 * v10;
  return result;
}

// File Line: 331
// RVA: 0x467090
bool __fastcall UFG::WorldBoundaries::GetSegmentIntersection(
        UFG::WorldBoundaries *this,
        UFG::qVector3 *a0,
        UFG::qVector3 *a1,
        UFG::qVector3 *b0,
        UFG::qVector3 *b1)
{
  float y; // xmm5_4
  float v6; // xmm4_4
  float x; // xmm6_4
  float v8; // xmm9_4
  float z; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm8_4
  float v13; // xmm7_4
  float v14; // xmm15_4
  float v15; // xmm13_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm14_4
  float v21; // xmm12_4
  float v22; // xmm1_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  bool result; // al
  float v28; // [rsp+0h] [rbp-B8h]
  float v29; // [rsp+4h] [rbp-B4h]
  float v30; // [rsp+8h] [rbp-B0h]
  float v31; // [rsp+Ch] [rbp-ACh]
  float v32; // [rsp+C8h] [rbp+10h]
  float v33; // [rsp+D0h] [rbp+18h]
  float v34; // [rsp+D8h] [rbp+20h]
  float b1a; // [rsp+E0h] [rbp+28h]

  y = a1->y;
  v6 = b0->y;
  x = a1->x;
  v8 = a0->y;
  z = a1->z;
  v11 = a0->x;
  v12 = b1->x;
  v13 = b1->y;
  v14 = a0->z;
  v15 = b0->x;
  v32 = a1->x - a0->x;
  v16 = b1->x - b0->x;
  v31 = v16;
  v17 = z - v14;
  v33 = y - v8;
  b1a = v13 - v6;
  if ( v14 >= z )
    v29 = a1->z;
  else
    v29 = a0->z;
  if ( v8 >= y )
    v28 = a1->y;
  else
    v28 = a0->y;
  if ( v11 >= x )
    v34 = a1->x;
  else
    v34 = a0->x;
  if ( v14 > z )
    z = a0->z;
  if ( v8 > y )
    y = a0->y;
  if ( v11 > x )
    x = a0->x;
  v18 = b0->z;
  v19 = b1->z;
  if ( v18 >= v19 )
    v30 = b1->z;
  else
    v30 = b0->z;
  if ( v6 >= v13 )
    v20 = v13;
  else
    v20 = b0->y;
  if ( v15 >= v12 )
    v21 = v12;
  else
    v21 = b0->x;
  if ( v18 <= v19 )
    v18 = b1->z;
  if ( v6 > v13 )
    v13 = b0->y;
  if ( v15 > v12 )
    v12 = b0->x;
  v22 = (float)(v16 * v33) - (float)(v32 * b1a);
  result = 0;
  if ( v22 != 0.0 )
  {
    v23 = (float)((float)((float)(v6 - v8) * v31) + (float)((float)(v11 - v15) * b1a)) / v22;
    v24 = (float)(v17 * v23) + v14;
    v25 = (float)(v23 * v32) + v11;
    v26 = (float)(v23 * v33) + v8;
    if ( v25 >= v34
      && v25 <= x
      && v26 >= v28
      && v26 <= y
      && v24 >= v29
      && v24 <= z
      && v25 >= v21
      && v25 <= v12
      && v26 >= v20
      && v26 <= v13
      && v24 >= v30
      && v24 <= v18 )
    {
      return 1;
    }
  }
  return result;
}

