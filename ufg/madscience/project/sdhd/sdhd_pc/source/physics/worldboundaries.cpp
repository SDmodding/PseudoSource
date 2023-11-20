// File Line: 24
// RVA: 0x451D00
void __fastcall UFG::WorldBoundaries::~WorldBoundaries(UFG::WorldBoundaries *this)
{
  UFG::WorldBoundaries *v1; // rsi
  Render::Skinning *v2; // rbx
  Render::SkinningCacheNode *v3; // rdi
  UFG::qVector3 *v4; // rcx

  v1 = this;
  this->vfptr = (UFG::WorldBoundariesVtbl *)&UFG::WorldBoundaries::`vftable;
  v2 = (Render::Skinning *)&this->mMappings;
  if ( this->mMappings.mTree.mCount )
  {
    do
    {
      v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v2->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v2->mSkinnedVertexBuffers.mTree, &v3->mNode);
      if ( v3 )
        operator delete[](v3);
    }
    while ( v2->mSkinnedVertexBuffers.mTree.mCount );
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(v2);
  v4 = v1->mWorldBoundaries.p;
  if ( v4 )
    operator delete[](v4);
  v1->mWorldBoundaries.p = 0i64;
  *(_QWORD *)&v1->mWorldBoundaries.size = 0i64;
}

// File Line: 29
// RVA: 0x46A980
char __fastcall IsAtTheEndOfTheWorld(UFG::BSP *bsp, UFG::BSPSpace *space)
{
  unsigned int v2; // ebp
  unsigned int v3; // er9
  UFG::BSPSpace *v4; // rdi
  UFG::BSP *v5; // rsi
  __int64 v6; // rbx
  __int64 v7; // r14
  __int64 v8; // r10
  signed __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax
  __int64 v12; // r11
  signed __int64 v13; // rdx
  __int64 v14; // rax
  signed __int64 v15; // r8
  __int64 v16; // rax
  signed __int64 v17; // rdx

  v2 = space->mFaceCount;
  v3 = 0;
  v4 = space;
  v5 = bsp;
  if ( !space->mFaceCount )
    return 0;
  v6 = space->mFaces.mOffset;
  v7 = bsp->mFaces.mOffset;
  v8 = 0i64;
  while ( 1 )
  {
    v9 = (signed __int64)(v6 ? (UFG::qOffset64<unsigned long *> *)((char *)&v4->mFaces + v6) : 0i64);
    v10 = (signed __int64)(v7 ? (UFG::qOffset64<UFG::BSPFace *> *)((char *)&v5->mFaces + v7) : 0i64);
    v11 = *(unsigned int *)(v8 + v9);
    v12 = *(unsigned int *)(v10 + 8 * v11);
    v13 = v10 + 8 * v11;
    if ( (_DWORD)v12 == -1 )
    {
      v14 = v5->mSpaces.mOffset;
      v15 = (signed __int64)(v14 ? (UFG::qOffset64<UFG::BSPSpace *> *)((char *)&v5->mSpaces + v14) : 0i64);
      if ( v4 == (UFG::BSPSpace *)(v15 + 80i64 * *(unsigned int *)(v13 + 4)) )
        break;
    }
    if ( *(_DWORD *)(v13 + 4) == -1 )
    {
      v16 = v5->mSpaces.mOffset;
      v17 = (signed __int64)(v16 ? (UFG::qOffset64<UFG::BSPSpace *> *)((char *)&v5->mSpaces + v16) : 0i64);
      if ( v4 == (UFG::BSPSpace *)(v17 + 80 * v12) )
        break;
    }
    ++v3;
    v8 += 4i64;
    if ( v3 >= v2 )
      return 0;
  }
  return 1;
}

// File Line: 47
// RVA: 0x4698A0
void __fastcall UFG::WorldBoundaries::Initialize(UFG::WorldBoundaries *this)
{
  UFG::WorldBoundaries *v1; // rbx
  UFG::qArray<UFG::qVector3,0> *v2; // r15
  UFG::qVector3 *v3; // rcx
  UFG::qBaseTreeRB *v4; // r13
  UFG::BSP *v5; // rbp
  char v6; // al
  signed __int64 v7; // rsi
  unsigned int v8; // ebx
  unsigned int v9; // edi
  __int64 v10; // rax
  signed __int64 v11; // rcx
  signed int v12; // eax
  signed __int64 v13; // r12
  float v14; // xmm6_4
  float v15; // xmm7_4
  signed __int64 v16; // r14
  unsigned int v17; // edi
  unsigned int v18; // ebx
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rsi
  __int64 v22; // rdx
  signed __int64 v23; // rcx
  UFG::qVector3 *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm2_4
  signed __int64 v27; // rcx
  UFG::qVector3 *v28; // rax
  UFG::allocator::free_link *v29; // rdx
  unsigned int v30; // ecx
  int v31; // eax
  __int64 v32; // rdi
  unsigned int v33; // er13
  __int64 v34; // rsi
  __int64 v35; // r14
  signed __int64 v36; // rcx
  __int64 v37; // rdx
  signed __int64 v38; // rax
  __int64 v39; // r9
  unsigned int v40; // er10
  __int64 v41; // rdx
  signed __int64 v42; // r8
  signed __int64 v43; // rcx
  signed __int64 v44; // rax
  signed __int64 v45; // rbx
  UFG::qVector3 *v46; // rcx
  int v47; // [rsp+A0h] [rbp+8h]
  signed __int64 v48; // [rsp+A8h] [rbp+10h]
  signed __int64 v49; // [rsp+B0h] [rbp+18h]
  Render::Skinning *v50; // [rsp+B8h] [rbp+20h]

  v1 = this;
  v2 = &this->mWorldBoundaries;
  v3 = this->mWorldBoundaries.p;
  if ( v3 )
    operator delete[](v3);
  v2->p = 0i64;
  *(_QWORD *)&v2->size = 0i64;
  UFG::qArray<UFG::qVector3,0>::Reallocate(v2, 0x80u, "PhysicsSystem::CalculateWorldBoundaries()");
  v4 = &v1->mMappings.mTree;
  v50 = (Render::Skinning *)&v1->mMappings;
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mMappings);
  v5 = UFG::SectionChooser::GetBSP();
  if ( v5 )
  {
    v6 = 0;
    v7 = 0i64;
    v48 = 0i64;
    v8 = 0;
    v9 = v5->mSpaceCount;
    if ( v9 )
    {
      while ( !v6 )
      {
        v10 = v5->mSpaces.mOffset;
        if ( v10 )
          v11 = (signed __int64)&v5->mSpaces + v10;
        else
          v11 = 0i64;
        v7 = v11 + 0x50i64 * v8;
        v48 = v11 + 0x50i64 * v8;
        v6 = IsAtTheEndOfTheWorld(v5, (UFG::BSPSpace *)(v11 + 0x50i64 * v8++));
        if ( v8 >= v9 )
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
        v14 = *(float *)(v13 + 20);
        v15 = *(float *)(v13 + 24);
        v16 = v2->size;
        v17 = v16 + 1;
        v18 = v2->capacity;
        if ( (signed int)v16 + 1 > v18 )
        {
          if ( v18 )
            v19 = 2 * v18;
          else
            v19 = 1;
          for ( ; v19 < v17; v19 *= 2 )
            ;
          if ( v19 - v17 > 0x10000 )
            v19 = v16 + 65537;
          if ( v19 != (_DWORD)v16 )
          {
            v20 = 12i64 * v19;
            if ( !is_mul_ok(v19, 0xCui64) )
              v20 = -1i64;
            v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
            if ( v2->p )
            {
              v22 = 0i64;
              if ( v2->size )
              {
                do
                {
                  v23 = 3 * v22;
                  v24 = v2->p;
                  v25 = v24[v22].y;
                  v26 = v24[v22].z;
                  *((_DWORD *)&v21->mNext + v23) = LODWORD(v24[v22].x);
                  *((float *)&v21->mNext + v23 + 1) = v25;
                  *((float *)&v21[1].mNext + v23) = v26;
                  v22 = (unsigned int)(v22 + 1);
                }
                while ( (unsigned int)v22 < v2->size );
              }
              operator delete[](v2->p);
            }
            v2->p = (UFG::qVector3 *)v21;
            v2->capacity = v19;
            v7 = v48;
          }
        }
        v2->size = v17;
        v27 = v16;
        v28 = v2->p;
        v28[v27].x = v14;
        v28[v27].y = v15;
        v28[v27].z = 0.0;
        v29 = UFG::qMalloc(0x28ui64, "WorldBoundaryNodes", 0i64);
        if ( v29 )
        {
          v30 = v2->size;
          v31 = *(_DWORD *)(v13 + 16);
          v29->mNext = 0i64;
          v29[1].mNext = 0i64;
          v29[2].mNext = 0i64;
          LODWORD(v29[3].mNext) = v31;
          LODWORD(v29[4].mNext) = v30 - 1;
        }
        else
        {
          v29 = 0i64;
        }
        UFG::qBaseTreeRB::Add(v4, (UFG::qBaseNodeRB *)v29);
        v32 = 0i64;
        v33 = *(_DWORD *)v13;
        if ( *(_DWORD *)v13 )
        {
          v34 = *(_QWORD *)(v13 + 8);
          v35 = v5->mFaces.mOffset;
          while ( 1 )
          {
            v36 = v34 ? v34 + v13 + 8 : 0i64;
            v37 = *(unsigned int *)(v36 + 4 * v32);
            v38 = (signed __int64)(v35 ? (UFG::qOffset64<UFG::BSPFace *> *)((char *)&v5->mFaces + v35) : 0i64);
            v39 = *(unsigned int *)(v38 + 8 * v37);
            if ( (_DWORD)v39 != -1 )
            {
              v40 = *(_DWORD *)(v38 + 8 * v37 + 4);
              if ( v40 != -1 )
              {
                v41 = v5->mSpaces.mOffset;
                if ( v41 )
                  v42 = (signed __int64)&v5->mSpaces + v41;
                else
                  v42 = 0i64;
                if ( v13 == v42 + 80 * v39 )
                  v39 = v40;
                v43 = (signed __int64)(v41 ? (UFG::qOffset64<UFG::BSPSpace *> *)((char *)&v5->mSpaces + v41) : 0i64);
                if ( v49 != v43 + 80 * v39 )
                {
                  v44 = (signed __int64)(v41 ? (UFG::qOffset64<UFG::BSPSpace *> *)((char *)&v5->mSpaces + v41) : 0i64);
                  v45 = v44 + 80 * v39;
                  if ( IsAtTheEndOfTheWorld(v5, (UFG::BSPSpace *)(v44 + 80 * v39)) )
                    break;
                }
              }
            }
            v32 = (unsigned int)(v32 + 1);
            if ( (unsigned int)v32 >= v33 )
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
        v4 = (UFG::qBaseTreeRB *)v50;
        if ( v47 <= 0 )
          goto LABEL_63;
      }
      if ( v47 > 0 && v2->size >= 3 )
        return;
LABEL_63:
      v46 = v2->p;
      if ( v46 )
        operator delete[](v46);
      v2->p = 0i64;
      *(_QWORD *)&v2->size = 0i64;
      UFG::qBaseTreeRB::~qBaseTreeRB(v50);
    }
  }
}

// File Line: 181
// RVA: 0x475F60
void __fastcall UFG::WorldBoundaries::Shutdown(UFG::WorldBoundaries *this)
{
  UFG::WorldBoundaries *v1; // rdi
  UFG::qVector3 *v2; // rcx
  Render::SkinningCacheNode *v3; // rbx

  v1 = this;
  v2 = this->mWorldBoundaries.p;
  if ( v2 )
    operator delete[](v2);
  v1->mWorldBoundaries.p = 0i64;
  *(_QWORD *)&v1->mWorldBoundaries.size = 0i64;
  while ( v1->mMappings.mTree.mCount )
  {
    v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mMappings);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mMappings,
      &v3->mNode);
    if ( v3 )
      operator delete[](v3);
  }
}

// File Line: 197
// RVA: 0x467320
UFG::qVector3 *__fastcall UFG::WorldBoundaries::GetSegmentNormal(UFG::WorldBoundaries *this, UFG::qVector3 *result, UFG::qVector3 *a, UFG::qVector3 *b)
{
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  __int128 v8; // xmm4
  float v9; // xmm3_4
  __m128 v10; // xmm6
  UFG::qVector3 *v11; // rax

  v8 = LODWORD(b->z);
  v4 = 0.0;
  v5 = b->y - a->y;
  v6 = b->x - a->x;
  *(float *)&v8 = (float)(*(float *)&v8 - a->z) * 0.0;
  v7 = v5 - *(float *)&v8;
  *(float *)&v8 = *(float *)&v8 - v6;
  v10 = (__m128)v8;
  v9 = (float)(v6 * 0.0) - (float)(v5 * 0.0);
  result->x = v7;
  LODWORD(result->y) = v8;
  result->z = v9;
  v10.m128_f32[0] = (float)((float)(*(float *)&v8 * *(float *)&v8) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] != 0.0 )
    v4 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v11 = result;
  result->x = v7 * v4;
  result->y = *(float *)&v8 * v4;
  result->z = v9 * v4;
  return v11;
}

// File Line: 209
// RVA: 0x466290
UFG::qVector3 *__fastcall GetClosestPointOnSegment(UFG::qVector3 *result, UFG::qVector3 *a, UFG::qVector3 *b, UFG::qVector3 *p, bool *isPastEdge)
{
  float v5; // xmm6_4
  float v6; // xmm3_4
  __m128 v7; // xmm7
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

  v7 = (__m128)LODWORD(b->y);
  v5 = b->x - a->x;
  v6 = b->z - a->z;
  v7.m128_f32[0] = v7.m128_f32[0] - a->y;
  v8 = v7;
  v8.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v5 * v5)) + (float)(v6 * v6);
  if ( v8.m128_f32[0] == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
  v10 = v5 * v9;
  v11 = v7.m128_f32[0] * v9;
  v12 = v9 * v6;
  v13 = p->x - a->x;
  v14 = p->y - a->y;
  LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v8);
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
char __fastcall UFG::WorldBoundaries::IsOutsideBoundaries(UFG::WorldBoundaries *this, UFG::qVector3 *pos, float radius, UFG::qVector3 *dir, float *distance)
{
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // rsi
  float v7; // xmm13_4
  UFG::WorldBoundaries *v8; // rbx
  UFG::BSP *v9; // rax
  UFG::BSPSpace *v11; // rax
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  unsigned int v14; // er9
  UFG::qVector3 *v15; // r10
  unsigned int v16; // er8
  float v17; // xmm6_4
  UFG::qVector3 *v18; // r14
  UFG::qVector3 *v19; // rbp
  UFG::qVector3 *v20; // r15
  float v21; // xmm11_4
  float v22; // xmm14_4
  float v23; // xmm4_4
  float v24; // xmm10_4
  float v25; // xmm15_4
  __m128 v26; // xmm3
  __m128 v27; // xmm12
  float v28; // xmm6_4
  __m128 v29; // xmm7
  float v30; // xmm8_4
  UFG::qVector3 *v31; // rax
  UFG::qVector3 *v32; // rax
  float v33; // xmm8_4
  float v34; // xmm6_4
  __m128 v35; // xmm2
  float v36; // xmm1_4
  float v37; // xmm0_4
  __int16 isPastEdge; // [rsp+30h] [rbp-F8h]
  float v39; // [rsp+34h] [rbp-F4h]
  float v40; // [rsp+38h] [rbp-F0h]
  UFG::qVector3 p; // [rsp+40h] [rbp-E8h]
  UFG::qVector3 result; // [rsp+50h] [rbp-D8h]
  UFG::qVector3 v43; // [rsp+60h] [rbp-C8h]

  v5 = dir;
  v6 = pos;
  v7 = radius;
  v8 = this;
  v9 = UFG::SectionChooser::GetBSP();
  if ( !v9 )
    return 0;
  v11 = UFG::BSP::GetSpaceFromPoint(v9, v6, 1, 0);
  if ( !v11 )
    return 0;
  v12 = v11->mIndex;
  if ( !v12 )
    return 0;
  v13 = UFG::qBaseTreeRB::Get(&v8->mMappings.mTree, v12);
  if ( !v13 )
    return 0;
  v14 = v8->mWorldBoundaries.size;
  v15 = v8->mWorldBoundaries.p;
  v16 = v14 + LODWORD(v13->mNULL.mParent);
  v17 = v6->x;
  p.z = 0.0;
  isPastEdge = 0;
  p.x = v17;
  p.y = v6->y;
  v27 = (__m128)LODWORD(p.y);
  v18 = &v15[(v16 - 1) % v14];
  v19 = &v15[v16 % v14];
  v20 = &v15[(v16 + 1) % v14];
  GetClosestPointOnSegment(&result, v18, &v15[v16 % v14], &p, (bool *)&isPastEdge);
  GetClosestPointOnSegment(&v43, v19, v20, &p, (bool *)&isPastEdge + 1);
  v21 = FLOAT_N1_0;
  v26 = v27;
  v22 = 0.0;
  v23 = radius * radius;
  v24 = FLOAT_N1_0;
  v25 = 0.0;
  v40 = radius * radius;
  v39 = 0.0;
  v26.m128_f32[0] = (float)((float)((float)(v27.m128_f32[0] - result.y) * (float)(v27.m128_f32[0] - result.y))
                          + (float)((float)(v17 - result.x) * (float)(v17 - result.x)))
                  + (float)(COERCE_FLOAT(LODWORD(result.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.z) ^ _xmm[0]));
  v27.m128_f32[0] = (float)((float)((float)(v27.m128_f32[0] - v43.y) * (float)(v27.m128_f32[0] - v43.y))
                          + (float)((float)(v17 - v43.x) * (float)(v17 - v43.x)))
                  + (float)(COERCE_FLOAT(LODWORD(v43.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(v43.z) ^ _xmm[0]));
  v28 = 0.0;
  v29 = 0i64;
  v30 = 0.0;
  if ( v26.m128_f32[0] < (float)(radius * radius) && !(_BYTE)isPastEdge )
  {
    LODWORD(v21) = (unsigned __int128)_mm_sqrt_ps(v26);
    v31 = UFG::WorldBoundaries::GetSegmentNormal(v8, &v43, v18, v19);
    v23 = v40;
    v22 = v31->x;
    v25 = v31->y;
    v39 = v31->z;
  }
  if ( v27.m128_f32[0] < v23 && !HIBYTE(isPastEdge) )
  {
    LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v27);
    v32 = UFG::WorldBoundaries::GetSegmentNormal(v8, &v43, v19, v20);
    v28 = v32->x;
    v29 = (__m128)LODWORD(v32->y);
    v30 = v32->z;
  }
  if ( v21 < 0.0 && v24 < 0.0 )
    return 0;
  v33 = v30 + v39;
  v34 = v28 + v22;
  v29.m128_f32[0] = v29.m128_f32[0] + v25;
  v35 = v29;
  v35.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v34 * v34)) + (float)(v33 * v33);
  if ( v35.m128_f32[0] == 0.0 )
    v36 = 0.0;
  else
    v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
  v5->x = v34 * v36;
  v5->y = v29.m128_f32[0] * v36;
  v5->z = v33 * v36;
  *distance = v7;
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
} v24 >= 0.0 )
  {
    v37 = *distance;
    if ( *distance >= v24 )
      v37 = v24;
    *distance = v37;
  }
  return 1

// File Line: 296
// RVA: 0x46AFB0
char __fastcall UFG::WorldBoundaries::IsOutsideBoundaries2(UFG::WorldBoundaries *this, UFG::qVector3 *pos, float radius, UFG::qVector3 *dir)
{
  unsigned int v4; // esi
  float v5; // xmm1_4
  char v6; // bl
  UFG::qVector3 *v7; // r12
  UFG::qVector3 *v8; // r14
  UFG::WorldBoundaries *v9; // r15
  float v10; // xmm6_4
  char result; // al
  unsigned int v12; // ebp
  __int64 v13; // rdi
  int v14; // xmm4_4
  int v15; // xmm3_4
  int v16; // xmm5_4
  float v17; // xmm2_4
  UFG::qVector3 b1; // [rsp+30h] [rbp-48h]
  UFG::qVector3 b0; // [rsp+40h] [rbp-38h]

  v4 = this->mWorldBoundaries.size;
  v5 = pos->y;
  v6 = 0;
  v7 = dir;
  v8 = pos;
  v9 = this;
  v10 = 0.0;
  b0.x = pos->x;
  b0.y = v5;
  b0.z = 0.0;
  b1.x = 6000.0;
  *(_QWORD *)&b1.y = 1169915904i64;
  if ( !v4 )
    return 0;
  v12 = 0;
  if ( v4 )
  {
    v13 = 0i64;
    do
    {
      if ( UFG::WorldBoundaries::GetSegmentIntersection(
             v9,
             &v9->mWorldBoundaries.p[v13],
             &v9->mWorldBoundaries.p[++v12 % v4],
             &b0,
             &b1) )
      {
        ++v6;
      }
      ++v13;
    }
    while ( v12 < v4 );
  }
  if ( v6 & 1 )
    return 0;
  v14 = LODWORD(v8->y) ^ _xmm[0];
  v15 = LODWORD(v8->x) ^ _xmm[0];
  v16 = LODWORD(v8->z) ^ _xmm[0];
  v17 = (float)((float)(*(float *)&v14 * *(float *)&v14) + (float)(*(float *)&v15 * *(float *)&v15))
      + (float)(*(float *)&v16 * *(float *)&v16);
  if ( v17 != 0.0 )
    v10 = 1.0 / fsqrt(v17);
  result = 1;
  v7->x = *(float *)&v15 * v10;
  v7->y = *(float *)&v14 * v10;
  v7->z = *(float *)&v16 * v10;
  return result;
}

// File Line: 331
// RVA: 0x467090
bool __fastcall UFG::WorldBoundaries::GetSegmentIntersection(UFG::WorldBoundaries *this, UFG::qVector3 *a0, UFG::qVector3 *a1, UFG::qVector3 *b0, UFG::qVector3 *b1)
{
  float v5; // xmm5_4
  float v6; // xmm4_4
  float v7; // xmm6_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  UFG::qVector3 *v10; // rax
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

  v5 = a1->y;
  v6 = b0->y;
  v7 = a1->x;
  v8 = a0->y;
  v9 = a1->z;
  v10 = b1;
  v11 = a0->x;
  v12 = b1->x;
  v13 = b1->y;
  v14 = a0->z;
  v15 = b0->x;
  v32 = a1->x - a0->x;
  v16 = b1->x - b0->x;
  v31 = b1->x - b0->x;
  v17 = v9 - v14;
  v33 = v5 - v8;
  b1a = v13 - v6;
  if ( v14 >= v9 )
    v29 = a1->z;
  else
    v29 = a0->z;
  if ( v8 >= v5 )
    v28 = a1->y;
  else
    v28 = a0->y;
  if ( v11 >= v7 )
    v34 = a1->x;
  else
    v34 = a0->x;
  if ( v14 > v9 )
    v9 = a0->z;
  if ( v8 > v5 )
    v5 = a0->y;
  if ( v11 > v7 )
    v7 = a0->x;
  v18 = b0->z;
  v19 = v10->z;
  if ( v18 >= v19 )
    v30 = v10->z;
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
    v18 = v10->z;
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
      && v25 <= v7
      && v26 >= v28
      && v26 <= v5
      && v24 >= v29
      && v24 <= v9
      && v25 >= v21
      && v25 <= v12
      && v26 >= v20
      && v26 <= v13
      && v24 >= v30
      && v24 <= v18 )
    {
      result = 1;
    }
  }
  return result;
}

