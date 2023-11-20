// File Line: 51
// RVA: 0x99A2A0
char __fastcall Scaleform::Render::MeshKey::Match(Scaleform::Render::MeshKey *this, unsigned int layer, unsigned int flags, const float *keyData, Scaleform::Render::ToleranceParams *cfg)
{
  Scaleform::Render::MeshKey *v5; // r10
  unsigned int v7; // eax
  const float *v8; // rcx
  Scaleform::Render::ToleranceParams *v9; // rdx
  unsigned int v10; // ecx
  float v11; // xmm2_4
  unsigned int v12; // ecx
  float v13; // xmm3_4
  float v14; // xmm4_4
  unsigned int v15; // eax
  const float *v16; // rcx
  signed __int64 v17; // r8
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm10_4
  unsigned int v24; // eax
  const float *v25; // rcx
  signed __int64 v26; // r8
  unsigned int v27; // eax
  const float *v28; // rcx
  signed __int64 v29; // r8
  __int64 v30; // rax
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4

  v5 = this;
  if ( flags == this->Flags && layer == this->pMesh.pObject->Layer )
  {
    if ( _bittest((const signed int *)&flags, 0xFu) )
      return 1;
    if ( flags & 0x10 )
    {
      v7 = 0;
      v8 = keyData;
      while ( *(const float *)((char *)v8 + (char *)v5 - (char *)keyData + 40) == *v8 )
      {
        ++v7;
        ++v8;
        if ( v7 >= 8 )
        {
          v9 = cfg;
          v10 = 8;
          while ( 1 )
          {
            v11 = keyData[v10];
            if ( v11 < (float)(v5->Data[v10] * cfg->Scale9LowerScale)
              || v11 > (float)(v5->Data[v10] * cfg->Scale9UpperScale) )
            {
              return 0;
            }
            if ( ++v10 - 8 >= 3 )
            {
              v12 = 11;
              while ( v5->Data[v12] == keyData[v12] )
              {
                if ( ++v12 - 11 >= 2 )
                  goto LABEL_43;
              }
              return 0;
            }
          }
        }
      }
    }
    else
    {
      v9 = cfg;
      v13 = cfg->FillLowerScale;
      v14 = cfg->FillUpperScale;
      if ( !(flags & 0x40) || (flags & 0x80u) != 0 )
      {
        v13 = cfg->FillAliasedLowerScale;
        v14 = cfg->FillAliasedUpperScale;
      }
      if ( (flags & 7) == 1 )
      {
        v27 = 0;
        v28 = keyData;
        v29 = (char *)v5 - (char *)keyData;
        while ( *v28 >= (float)(*(const float *)((char *)v28 + v29 + 40) * v13)
             && *v28 <= (float)(*(const float *)((char *)v28 + v29 + 40) * v14) )
        {
          ++v27;
          ++v28;
          if ( v27 >= 3 )
            goto LABEL_43;
        }
      }
      else if ( (flags & 7) == 2 )
      {
        v18 = cfg->StrokeLowerScale;
        v19 = cfg->StrokeUpperScale;
        if ( flags & 0x20 )
        {
          v20 = *(float *)&this[1].pPrev;
          v21 = this->Data[1] * *keyData;
          v22 = this->Data[0] * keyData[1];
          v23 = keyData[2];
          if ( v23 >= (float)(v20 * 0.99900001)
            && v23 <= (float)(v20 * 1.001)
            && v21 >= (float)(v22 * 0.99900001)
            && v21 <= (float)(v22 * 1.001) )
          {
            v18 = cfg->FillLowerScale;
            v19 = cfg->FillUpperScale;
          }
        }
        v24 = 0;
        v25 = keyData;
        v26 = (char *)v5 - (char *)keyData;
        while ( *v25 >= (float)(*(const float *)((char *)v25 + v26 + 40) * v18)
             && *v25 <= (float)(*(const float *)((char *)v25 + v26 + 40) * v19) )
        {
          ++v24;
          ++v25;
          if ( v24 >= 3 )
            goto LABEL_43;
        }
      }
      else
      {
        v15 = (flags & 7) - 3;
        if ( (flags & 7) == 3 )
        {
          v16 = keyData;
          v17 = (char *)v5 - (char *)keyData;
          while ( *v16 >= (float)(*(const float *)((char *)v16 + v17 + 40) * cfg->HintedStrokeLowerScale)
               && *v16 <= (float)(*(const float *)((char *)v16 + v17 + 40) * cfg->HintedStrokeUpperScale) )
          {
            ++v15;
            ++v16;
            if ( v15 >= 3 )
              goto LABEL_43;
          }
        }
        else
        {
LABEL_43:
          v30 = v5->Size;
          v31 = v9->MorphTolerance;
          v32 = *((float *)&v5->UseCount + v30);
          v33 = keyData[v30 - 1];
          if ( v33 >= (float)((float)(1.0 - v31) * v32) && v33 <= (float)((float)(v31 + 1.0) * v32) )
            return 1;
        }
      }
    }
  }
  return 0;
}

// File Line: 170
// RVA: 0x95C5F0
bool __fastcall Scaleform::Render::MeshKey::CalcMatrixKey(Scaleform::Render::Matrix2x4<float> *m, float *key, Scaleform::Render::Matrix2x4<float> *m2)
{
  bool result; // al
  __m128 v4; // xmm5
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm7
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm2
  __m128 v11; // xmm6
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm2

  if ( m2 )
    return Scaleform::Render::MeshKey::CalcMatrixKey_NonOpt(m, key, m2);
  v4 = *(__m128 *)&m->M[1][0];
  v5 = _mm_shuffle_ps(*(__m128 *)&m->M[0][0], v4, 85);
  v6 = _mm_shuffle_ps(*(__m128 *)&m->M[0][0], v4, 0);
  v7 = _mm_add_ps(_mm_mul_ps(v4, v4), _mm_mul_ps(*(__m128 *)&m->M[0][0], *(__m128 *)&m->M[0][0]));
  v8 = _mm_mul_ps(v5, v6);
  v9 = _mm_mul_ps(_mm_shuffle_ps(v4, *(__m128 *)&m->M[0][0], 0), _mm_sub_ps(v5, v6));
  v10 = _mm_rsqrt_ps(v7);
  v11 = _mm_sub_ps(_mm_shuffle_ps(v9, v9, 10), v9);
  v12 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>::`2::v);
  v13 = _mm_mul_ps(
          _mm_unpacklo_ps(
            _mm_and_ps(
              v11,
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<2147483647,2147483647,2147483647,2147483647>::`2::v),
            _mm_add_ps(_mm_shuffle_ps(v8, v8, 10), v8)),
          _mm_shuffle_ps(v10, v10, 0));
  v14 = _mm_shuffle_ps(v13, v13, 207);
  result = (_mm_movemask_ps(_mm_cmpneqps(_mm_shuffle_ps(v7, v13, 4), v12)) & 0xF) == 15;
  v15 = _mm_rcp_ps(
          _mm_shuffle_ps(
            _mm_sub_ps(
              v13,
              _mm_and_ps(v14, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,0,0,0>::`2::v)),
            v10,
            72));
  v16 = _mm_add_ps(_mm_mul_ps(v15, v13), _xmm);
  *(__m128 *)key = _mm_shuffle_ps(
                     v15,
                     _mm_xor_ps(_mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v16, v16, 225), v16), _mm_cmpleps(v12, v14)), v16),
                     14);
  return result;
}

// File Line: 224
// RVA: 0x95C6E0
char __fastcall Scaleform::Render::MeshKey::CalcMatrixKey_NonOpt(Scaleform::Render::Matrix2x4<float> *m, float *key, Scaleform::Render::Matrix2x4<float> *m2)
{
  float v3; // xmm5_4
  __m128 v4; // xmm3
  float v5; // xmm6_4
  Scaleform::Render::Matrix2x4<float> *v6; // rbx
  __m128 v7; // xmm8
  float v8; // xmm7_4
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  float v11; // xmm9_4
  float v12; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  signed int v20; // edx
  unsigned int v21; // eax
  float *v22; // rcx
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  float src[2]; // [rsp+18h] [rbp-29h]
  __int64 v27; // [rsp+20h] [rbp-21h]
  int v28; // [rsp+28h] [rbp-19h]
  int v29; // [rsp+2Ch] [rbp-15h]
  float dst[2]; // [rsp+30h] [rbp-11h]
  float v31; // [rsp+38h] [rbp-9h]
  __int64 v32; // [rsp+3Ch] [rbp-5h]
  float v33; // [rsp+44h] [rbp+3h]
  unsigned __int64 v34; // [rsp+48h] [rbp+7h]

  v3 = m->M[0][1];
  v4 = (__m128)LODWORD(m->M[1][1]);
  v10 = v4;
  v5 = 0.0;
  v6 = m2;
  v7 = (__m128)LODWORD(m->M[1][0]);
  v8 = m->M[0][0];
  v9 = v7;
  v9.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8);
  v10.m128_f32[0] = (float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v3 * v3);
  if ( v9.m128_f32[0] == 0.0 || v10.m128_f32[0] == 0.0 )
    return 0;
  LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v9);
  v12 = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                       (float)((float)(v4.m128_f32[0] - v7.m128_f32[0]) * v8)
                     - (float)((float)(v3 - v8) * v7.m128_f32[0])) & _xmm)
      / v11;
  if ( v12 < 0.0000000099999999 )
    return 0;
  *key = v11;
  *((_DWORD *)key + 1) = (unsigned __int128)_mm_sqrt_ps(v10);
  v14 = (float)((float)((float)(v4.m128_f32[0] * v7.m128_f32[0]) + (float)(v3 * v8)) * v11) / v9.m128_f32[0];
  if ( v14 < 0.0 )
    v15 = v12 / (float)(v12 - v14);
  else
    v15 = (float)(v14 / v12) + 1.0;
  key[2] = v15;
  if ( m2 )
  {
    v31 = v11;
    *(_QWORD *)dst = 0i64;
    LODWORD(v32) = 0;
    v34 = 0i64;
    v33 = v12;
    *((float *)&v32 + 1) = v14 + v11;
    v27 = 1065353216i64;
    v28 = 1065353216;
    v29 = 1065353216;
    Scaleform::Render::Matrix2x4<float>::SetParlToParl(m2, src, dst);
    *(_QWORD *)dst = 1065353216i64;
    v16 = v6->M[0][1];
    v31 = 0.70710677;
    v32 = 1060439283i64;
    v17 = v6->M[0][0];
    v18 = v6->M[1][1];
    v19 = v6->M[1][0];
    v20 = 4;
    v21 = 0;
    v22 = dst;
    v33 = FLOAT_1_05;
    v34 = __PAIR__(1060439283, LODWORD(FLOAT_N0_70710677));
    do
    {
      v23 = *v22;
      *v22 = (float)(v17 * *v22) + (float)(v16 * v22[1]);
      v24 = (float)(v19 * v23) + (float)(v18 * v22[1]);
      v22[1] = v24;
      if ( (float)((float)(*v22 * *v22) + (float)(v24 * v24)) > v5 )
      {
        v5 = (float)(*v22 * *v22) + (float)(v24 * v24);
        v20 = v21;
      }
      v21 += 2;
      v22 += 2;
    }
    while ( v21 < 8 );
    v25 = atan2f(dst[v20 + 1], dst[v20]);
    Scaleform::Render::Matrix2x4<float>::AppendRotation(v6, 1.5707964 - v25);
  }
  return 1;
}

// File Line: 344
// RVA: 0x967900
Scaleform::Render::MeshKey *__fastcall Scaleform::Render::MeshKeySet::CreateKey(Scaleform::Render::MeshKeySet *this, const float *keyData, unsigned int flags)
{
  unsigned __int16 v3; // bp
  const float *v4; // r14
  Scaleform::Render::MeshKeySet *v5; // rdi
  signed int v6; // esi
  unsigned int v7; // esi
  Scaleform::Render::MeshKey *result; // rax
  Scaleform::Render::MeshKey *v9; // rbx

  v3 = flags;
  v4 = keyData;
  v5 = this;
  v6 = 3;
  if ( flags & 0x10 )
    v6 = 13;
  v7 = v6 + 1;
  result = (Scaleform::Render::MeshKey *)this->pManager.pObject->pRenderHeap->vfptr->Alloc(
                                           this->pManager.pObject->pRenderHeap,
                                           4i64 * (v7 - 1) + 48,
                                           0i64);
  v9 = result;
  if ( result )
  {
    result->pKeySet = 0i64;
    result->pMesh.pObject = 0i64;
    *(_DWORD *)&result->Size = 0;
    result->UseCount = 1;
    result->pKeySet = v5;
    result->Size = v7;
    result->Flags = v3;
    memmove(result->Data, v4, 4i64 * v7);
    v9->pPrev = v5->Meshes.Root.pPrev;
    v9->pNext = (Scaleform::Render::MeshKey *)&v5->Meshes;
    v5->Meshes.Root.pPrev->pNext = v9;
    v5->Meshes.Root.pPrev = v9;
    result = v9;
  }
  return result;
}

// File Line: 364
// RVA: 0x96D8F0
void __fastcall Scaleform::Render::MeshKeySet::DestroyKey(Scaleform::Render::MeshKeySet *this, Scaleform::Render::MeshKey *key)
{
  Scaleform::Render::MeshBase *v2; // rsi
  Scaleform::Render::MeshKey *v3; // rbx
  Scaleform::Render::MeshKeySet *v4; // rdi
  Scaleform::Render::MeshProvider *v5; // rcx
  Scaleform::Render::MeshBase *v6; // rcx

  key->pPrev->pNext = key->pNext;
  key->pNext->pPrev = key->pPrev;
  v2 = key->pMesh.pObject;
  v3 = key;
  v4 = this;
  key->pPrev = (Scaleform::Render::MeshKey *)-1i64;
  key->pNext = (Scaleform::Render::MeshKey *)-1i64;
  if ( v2 )
  {
    v5 = v2->pProvider.pObject;
    if ( v5 )
      ((void (*)(void))v5->vfptr->Release)();
    v2->pProvider.pObject = 0i64;
    v6 = v3->pMesh.pObject;
    if ( v6 && _InterlockedExchangeAdd(&v6->RefCount, 0xFFFFFFFF) == 1 && v6 )
      v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
    v3->pMesh.pObject = 0i64;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( (Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *)v4->Meshes.Root.pNext == &v4->Meshes )
    Scaleform::Render::MeshKeyManager::destroyKeySet(v4->pManager.pObject, v4);
}

// File Line: 386
// RVA: 0x96D770
void __fastcall Scaleform::Render::MeshKeySet::DestroyAllKeys(Scaleform::Render::MeshKeySet *this)
{
  Scaleform::Render::MeshKey *v1; // rbx
  Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *v2; // rsi
  Scaleform::Render::MeshKeySet *v3; // rbp
  Scaleform::Render::MeshBase *v4; // rdi
  Scaleform::Render::MeshProvider *v5; // rcx
  Scaleform::Render::MeshKey *v6; // rbx
  Scaleform::Render::MeshBase *v7; // rcx
  Scaleform::Render::MeshKey *v8; // rdi

  v1 = this->Meshes.Root.pNext;
  v2 = &this->Meshes;
  v3 = this;
  if ( v1 != (Scaleform::Render::MeshKey *)&this->Meshes )
  {
    do
    {
      v4 = v1->pMesh.pObject;
      if ( v4 )
      {
        v5 = v4->pProvider.pObject;
        if ( v5 )
          ((void (*)(void))v5->vfptr->Release)();
        v4->pProvider.pObject = 0i64;
      }
      v1 = v1->pNext;
    }
    while ( v1 != (Scaleform::Render::MeshKey *)v2 );
  }
  v6 = v3->Meshes.Root.pNext;
  if ( v6 != (Scaleform::Render::MeshKey *)v2 )
  {
    do
    {
      v7 = v6->pMesh.pObject;
      v8 = v6->pNext;
      if ( v7 )
      {
        if ( !_InterlockedDecrement(&v7->RefCount) && v7 )
          v7->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, 1u);
        v6->pMesh.pObject = 0i64;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
      v6 = v8;
    }
    while ( v8 != (Scaleform::Render::MeshKey *)v2 );
  }
  v2->Root.pPrev = (Scaleform::Render::MeshKey *)v2;
  v2->Root.pNext = (Scaleform::Render::MeshKey *)v2;
}

// File Line: 416
// RVA: 0x99CAB0
void __fastcall Scaleform::Render::MeshKeySet::OnEvict(Scaleform::Render::MeshKeySet *this, Scaleform::Render::MeshBase *pmesh)
{
  Scaleform::Render::MeshBase *v2; // r8
  Scaleform::Render::MeshKey *v3; // rdx

  v2 = pmesh;
  v3 = this->Meshes.Root.pNext;
  if ( v3 != (Scaleform::Render::MeshKey *)&this->Meshes )
  {
    while ( v2 != v3->pMesh.pObject )
    {
      v3 = v3->pNext;
      if ( v3 == (Scaleform::Render::MeshKey *)&this->Meshes )
        return;
    }
    JUMPOUT(v3->UseCount, 0, Scaleform::Render::MeshKeySet::DestroyKey);
  }
}

// File Line: 434
// RVA: 0x9E2EB0
Scaleform::Render::MeshKeySet *__fastcall Scaleform::Render::MeshKeySet::findMatchingKey(Scaleform::Render::MeshKeySet *this, unsigned int layer, unsigned int flags, const float *keyData, Scaleform::Render::ToleranceParams *cfg)
{
  Scaleform::Render::MeshKeySet *v5; // rbx
  Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *v6; // rsi
  const float *v7; // r14
  unsigned int v8; // er15
  unsigned int v9; // er12

  v5 = (Scaleform::Render::MeshKeySet *)this->Meshes.Root.pNext;
  v6 = &this->Meshes;
  v7 = keyData;
  v8 = flags;
  v9 = layer;
  if ( v5 == (Scaleform::Render::MeshKeySet *)&this->Meshes )
    return 0i64;
  while ( 1 )
  {
    _RAX = v5->pManager.pObject;
    __asm
    {
      prefetcht1 byte ptr [rax+80h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+60h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+40h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax+20h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rax]; Prefetch to all cache levels
    }
    _RDI = v5->pPrev;
    __asm
    {
      prefetcht1 byte ptr [rdi+20h]; Prefetch to all cache levels
      prefetcht1 byte ptr [rdi]; Prefetch to all cache levels
    }
    if ( Scaleform::Render::MeshKey::Match((Scaleform::Render::MeshKey *)v5, v9, v8, v7, cfg) )
      break;
    v5 = _RDI;
    if ( _RDI == (Scaleform::Render::MeshKeySet *)v6 )
      return 0i64;
  }
  return v5;
}

// File Line: 477
// RVA: 0x96D670
void __fastcall Scaleform::Render::MeshKeyManager::DestroyAllKeys(Scaleform::Render::MeshKeyManager *this)
{
  Scaleform::Render::MeshKeyManager *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  signed __int64 v3; // rax
  signed __int64 v4; // rdx
  Scaleform::Render::MeshKeySet *v5; // r9
  Scaleform::Render::MeshKeySet *v6; // rcx
  Scaleform::Render::MeshKeySet *v7; // rdx
  __int64 v8; // [rsp+0h] [rbp-48h]
  __int64 v9; // [rsp+20h] [rbp-28h]
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v10; // [rsp+28h] [rbp-20h]

  v9 = -2i64;
  v1 = this;
  v2 = &this->KeySetLock.cs;
  EnterCriticalSection(&this->KeySetLock.cs);
  v3 = 0i64;
  v4 = (signed __int64)&v1->KeySets[0].Root.8;
  if ( v1 == (Scaleform::Render::MeshKeyManager *)-72i64 )
    v4 = 0i64;
  v5 = v1->KeySets[1].Root.pNext;
  if ( v5 != (Scaleform::Render::MeshKeySet *)v4 )
  {
    v6 = (Scaleform::Render::MeshKeySet *)(&v8 + 4);
    v10.Root.pPrev = (Scaleform::Render::MeshKeySet *)(&v8 + 4);
    v10.Root.pNext = (Scaleform::Render::MeshKeySet *)(&v8 + 4);
    if ( v1 != (Scaleform::Render::MeshKeyManager *)-72i64 )
      v3 = (signed __int64)&v1->KeySets[0].Root.8;
    if ( v5 != (Scaleform::Render::MeshKeySet *)v3 )
    {
      v7 = v1->KeySets[1].Root.pPrev;
      v1->KeySets[1].Root.pPrev = (Scaleform::Render::MeshKeySet *)&v1->KeySets[0].Root.8;
      v1->KeySets[1].Root.pNext = (Scaleform::Render::MeshKeySet *)&v1->KeySets[0].Root.8;
      v7->pNext = v6;
      v5->pPrev = v6;
      v10.Root.pNext->pPrev = v7;
      v6 = v5;
      v10.Root.pNext = v5;
    }
    while ( 1 )
    {
      v6->pPrev->pNext = v6->pNext;
      v6->pNext->pPrev = v6->pPrev;
      v6->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
      v6->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
      if ( v6 )
        v6->vfptr->__vecDelDtor((Scaleform::Render::MeshProvider *)&v6->vfptr, 1u);
      if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v10) )
        break;
      v6 = v10.Root.pNext;
    }
  }
  Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(v1, 0);
  LeaveCriticalSection(v2);
}

// File Line: 484
// RVA: 0x99FCD0
void __fastcall Scaleform::Render::MeshKeyManager::ProcessKillList(Scaleform::Render::MeshKeyManager *this)
{
  Scaleform::Render::MeshKeyManager *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  signed __int64 v3; // rax
  bool v4; // zf
  signed __int64 v5; // rdi
  signed __int64 v6; // rcx
  Scaleform::Render::MeshKeySet *v7; // r8
  Scaleform::Render::MeshKeySet *v8; // rcx
  Scaleform::Render::MeshKeySet *v9; // rdx
  __int64 v10; // [rsp+0h] [rbp-48h]
  __int64 v11; // [rsp+20h] [rbp-28h]
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v12; // [rsp+28h] [rbp-20h]

  v11 = -2i64;
  v1 = this;
  v2 = &this->KeySetLock.cs;
  EnterCriticalSection(&this->KeySetLock.cs);
  v3 = 0i64;
  v4 = &v1->KeySets[1] == 0i64;
  v5 = (signed __int64)&v1->KeySets[1];
  v6 = v5 - 8;
  if ( v4 )
    v6 = 0i64;
  v7 = *(Scaleform::Render::MeshKeySet **)(v5 + 8);
  if ( v7 != (Scaleform::Render::MeshKeySet *)v6 )
  {
    v8 = (Scaleform::Render::MeshKeySet *)(&v10 + 4);
    v12.Root.pPrev = (Scaleform::Render::MeshKeySet *)(&v10 + 4);
    v12.Root.pNext = (Scaleform::Render::MeshKeySet *)(&v10 + 4);
    if ( v5 )
      v3 = v5 - 8;
    if ( v7 != (Scaleform::Render::MeshKeySet *)v3 )
    {
      v9 = *(Scaleform::Render::MeshKeySet **)v5;
      *(_QWORD *)v5 = v5 - 8;
      *(_QWORD *)(v5 + 8) = v5 - 8;
      v9->pNext = v8;
      v7->pPrev = v8;
      v12.Root.pNext->pPrev = v9;
      v8 = v7;
      v12.Root.pNext = v7;
    }
    while ( 1 )
    {
      v8->pPrev->pNext = v8->pNext;
      v8->pNext->pPrev = v8->pPrev;
      v8->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
      v8->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
      if ( v8 )
        v8->vfptr->__vecDelDtor((Scaleform::Render::MeshProvider *)&v8->vfptr, 1u);
      if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v12) )
        break;
      v8 = v12.Root.pNext;
    }
  }
  LeaveCriticalSection(v2);
}

// File Line: 494
// RVA: 0x9679D0
Scaleform::Render::MeshKey *__fastcall Scaleform::Render::MeshKeyManager::CreateMatchingKey(Scaleform::Render::MeshKeyManager *this, Scaleform::Render::MeshProvider_KeySupport *provider, unsigned int layer, unsigned int flags, const float *keyData, Scaleform::Render::ToleranceParams *cfg)
{
  unsigned int v6; // ebp
  unsigned int v7; // er14
  Scaleform::Render::MeshProvider_KeySupport *v8; // rdi
  Scaleform::Render::MeshKeyManager *v9; // rbx
  Scaleform::Render::MeshKeySet *v10; // rcx
  Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *v11; // rax
  Scaleform::Render::MeshKey *result; // rax
  Scaleform::Render::MeshKeySet *volatile v13; // rcx
  Scaleform::Render::MeshKeySet *v14; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+68h] [rbp+10h]

  v6 = flags;
  v7 = layer;
  v8 = provider;
  v9 = this;
  if ( !provider->hKeySet.pManager.Value )
  {
    _InterlockedExchangeAdd(&this->RefCount, 1u);
    provider->hKeySet.pManager.Value = this;
  }
  if ( !provider->hKeySet.pKeySet )
  {
    lpCriticalSection = &this->KeySetLock.cs;
    EnterCriticalSection(&this->KeySetLock.cs);
    v10 = (Scaleform::Render::MeshKeySet *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v9->pRenderHeap->vfptr->Alloc)(
                                             v9->pRenderHeap,
                                             56i64);
    if ( v10 )
    {
      v10->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable;
      v10->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshKeySet::`vftable;
      _InterlockedExchangeAdd(&v9->RefCount, 1u);
      v10->pManager.pObject = v9;
      v10->pDelegate = v8;
      v11 = &v10->Meshes;
      v11->Root.pPrev = (Scaleform::Render::MeshKey *)v11;
      v11->Root.pNext = (Scaleform::Render::MeshKey *)v11;
    }
    else
    {
      v10 = 0i64;
    }
    v8->hKeySet.pKeySet = v10;
    if ( !v8->hKeySet.pKeySet )
    {
      LeaveCriticalSection(lpCriticalSection);
      return 0i64;
    }
    v13 = v8->hKeySet.pKeySet;
    v13->pPrev = v9->KeySets[0].Root.pPrev;
    v13->pNext = (Scaleform::Render::MeshKeySet *)&v9->KeySetLock.cs.SpinCount;
    v9->KeySets[0].Root.pPrev->pNext = v13;
    v9->KeySets[0].Root.pPrev = v13;
    LeaveCriticalSection(lpCriticalSection);
  }
  v14 = v8->hKeySet.pKeySet;
  result = Scaleform::Render::MeshKeySet::findMatchingKey(v14, v7, v6, keyData, cfg);
  if ( !result )
    return Scaleform::Render::MeshKeySet::CreateKey(v14, keyData, v6);
  ++result->UseCount;
  return result;
}

// File Line: 537
// RVA: 0x9EE490
void __fastcall Scaleform::Render::MeshKeyManager::providerLost(Scaleform::Render::MeshKeyManager *this, Scaleform::Render::MeshKeySetHandle *handle)
{
  Scaleform::Render::MeshKeySetHandle *v2; // rdi
  Scaleform::Render::MeshKeyManager *v3; // rbx
  Scaleform::Render::MeshKeySet *v4; // r8
  _RTL_CRITICAL_SECTION *v5; // [rsp+40h] [rbp+8h]

  v2 = handle;
  v3 = this;
  v5 = &this->KeySetLock.cs;
  EnterCriticalSection(&this->KeySetLock.cs);
  v4 = v2->pKeySet;
  if ( v4 )
  {
    v4->pPrev->pNext = v4->pNext;
    v4->pNext->pPrev = v4->pPrev;
    v4->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
    v4->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
    v4->pPrev = v3->KeySets[1].Root.pPrev;
    v4->pNext = (Scaleform::Render::MeshKeySet *)&v3->KeySets[0].Root.8;
    v3->KeySets[1].Root.pPrev->pNext = v4;
    v3->KeySets[1].Root.pPrev = v4;
    v4->pDelegate = 0i64;
    v2->pKeySet = 0i64;
  }
  LeaveCriticalSection(v5);
}

// File Line: 562
// RVA: 0x9DFB60
void __fastcall Scaleform::Render::MeshKeyManager::destroyKeySet(Scaleform::Render::MeshKeyManager *this, Scaleform::Render::MeshKeySet *keySet)
{
  Scaleform::Render::MeshKeySet *v2; // rsi
  Scaleform::Render::MeshKeyManager *v3; // rbp
  _RTL_CRITICAL_SECTION *v4; // rbx
  signed __int64 v6; // rdi
  signed __int64 v9; // rax
  Scaleform::Render::MeshKeySet *v10; // r9
  signed __int64 v11; // rax
  Scaleform::Render::MeshKeySet *v12; // rcx
  Scaleform::Render::MeshKeySet *v13; // rdx
  __int64 v14; // [rsp+0h] [rbp-48h]
  __int64 v15; // [rsp+20h] [rbp-28h]
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v16; // [rsp+28h] [rbp-20h]
  Scaleform::Lock *v17; // [rsp+50h] [rbp+8h]

  v15 = -2i64;
  v2 = keySet;
  v3 = this;
  v4 = &this->KeySetLock.cs;
  v17 = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  _RAX = v2->pDelegate;
  v6 = 0i64;
  if ( _RAX )
  {
    _RAX->hKeySet.pKeySet = 0i64;
    _RCX = 0i64;
    __asm { xchg    rcx, [rax+18h]; Exchange Register/Memory with Register }
    if ( _RCX && !_InterlockedDecrement((volatile signed __int32 *)(_RCX + 8)) )
      (**(void (__fastcall ***)(__int64, signed __int64))_RCX)(_RCX, 1i64);
    v2->pDelegate = 0i64;
    v4 = &v17->cs;
  }
  v2->pPrev->pNext = v2->pNext;
  v2->pNext->pPrev = v2->pPrev;
  v2->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
  v2->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
  v2->vfptr->__vecDelDtor((Scaleform::Render::MeshProvider *)&v2->vfptr, 1u);
  v9 = (signed __int64)&v3->KeySets[0].Root.8;
  if ( v3 == (Scaleform::Render::MeshKeyManager *)-72i64 )
    v9 = 0i64;
  v10 = v3->KeySets[1].Root.pNext;
  if ( v10 != (Scaleform::Render::MeshKeySet *)v9 )
  {
    v11 = (signed __int64)&v3->KeySets[0].Root.8;
    if ( v3 == (Scaleform::Render::MeshKeyManager *)-72i64 )
      v11 = 0i64;
    if ( v10 != (Scaleform::Render::MeshKeySet *)v11 )
    {
      v12 = (Scaleform::Render::MeshKeySet *)(&v14 + 4);
      v16.Root.pPrev = (Scaleform::Render::MeshKeySet *)(&v14 + 4);
      v16.Root.pNext = (Scaleform::Render::MeshKeySet *)(&v14 + 4);
      if ( v3 != (Scaleform::Render::MeshKeyManager *)-72i64 )
        v6 = (signed __int64)&v3->KeySets[0].Root.8;
      if ( v10 != (Scaleform::Render::MeshKeySet *)v6 )
      {
        v13 = v3->KeySets[1].Root.pPrev;
        v3->KeySets[1].Root.pPrev = (Scaleform::Render::MeshKeySet *)&v3->KeySets[0].Root.8;
        v3->KeySets[1].Root.pNext = (Scaleform::Render::MeshKeySet *)&v3->KeySets[0].Root.8;
        v13->pNext = v12;
        v10->pPrev = v12;
        v16.Root.pNext->pPrev = v13;
        v12 = v10;
        v16.Root.pNext = v10;
      }
      while ( 1 )
      {
        v12->pPrev->pNext = v12->pNext;
        v12->pNext->pPrev = v12->pPrev;
        v12->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
        v12->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
        if ( v12 )
          v12->vfptr->__vecDelDtor((Scaleform::Render::MeshProvider *)&v12->vfptr, 1u);
        if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v16) )
          break;
        v12 = v16.Root.pNext;
      }
    }
  }
  LeaveCriticalSection(v4);
}

// File Line: 575
// RVA: 0x9DFCF0
void __fastcall Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(Scaleform::Render::MeshKeyManager *this, Scaleform::Render::MeshKeyManager::KeySetListType type)
{
  Scaleform::Render::MeshKeyManager::KeySetListType v2; // edi
  __int64 v3; // rax
  bool v4; // zf
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> *v5; // r8
  signed __int64 v6; // rax
  Scaleform::Render::MeshKeySet *v7; // rdx
  signed __int64 v8; // rax
  Scaleform::Render::MeshKeySet *v9; // rbx
  Scaleform::Render::MeshKeySet *v10; // rcx
  __int64 v14; // [rsp+0h] [rbp-38h]
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v15; // [rsp+20h] [rbp-18h]

  v2 = type;
  v3 = type;
  v4 = &this->KeySets[v3] == 0i64;
  v5 = &this->KeySets[v3];
  v6 = (signed __int64)&v5[-1].Root.8;
  if ( v4 )
    v6 = 0i64;
  v7 = v5->Root.pNext;
  if ( v7 != (Scaleform::Render::MeshKeySet *)v6 )
  {
    v8 = (signed __int64)&v5[-1].Root.8;
    v9 = (Scaleform::Render::MeshKeySet *)(&v14 + 3);
    v15.Root.pPrev = (Scaleform::Render::MeshKeySet *)(&v14 + 3);
    v15.Root.pNext = (Scaleform::Render::MeshKeySet *)(&v14 + 3);
    if ( !v5 )
      v8 = 0i64;
    if ( v7 != (Scaleform::Render::MeshKeySet *)v8 )
    {
      v10 = v5->Root.pPrev;
      v5->Root.pPrev = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
      v5->Root.pNext = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
      v10->pNext = v9;
      v7->pPrev = v9;
      v9 = v7;
      v15.Root.pNext->pPrev = v10;
      v15.Root.pNext = v7;
    }
    while ( 1 )
    {
      if ( v2 != 1 )
      {
        _RAX = v9->pDelegate;
        if ( _RAX )
        {
          _RCX = 0i64;
          _RAX->hKeySet.pKeySet = 0i64;
          __asm { xchg    rcx, [rax+18h]; Exchange Register/Memory with Register }
          if ( _RCX )
          {
            if ( !_InterlockedDecrement((volatile signed __int32 *)(_RCX + 8)) )
              (**(void (__fastcall ***)(__int64, signed __int64))_RCX)(_RCX, 1i64);
          }
          v9->pDelegate = 0i64;
        }
      }
      v9->pPrev->pNext = v9->pNext;
      v9->pNext->pPrev = v9->pPrev;
      v9->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
      v9->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
      v9->vfptr->__vecDelDtor((Scaleform::Render::MeshProvider *)&v9->vfptr, 1u);
      if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v15) )
        break;
      v9 = v15.Root.pNext;
    }
  }
}

