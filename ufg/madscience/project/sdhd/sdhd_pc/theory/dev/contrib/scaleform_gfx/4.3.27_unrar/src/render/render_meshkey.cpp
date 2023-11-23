// File Line: 51
// RVA: 0x99A2A0
char __fastcall Scaleform::Render::MeshKey::Match(
        Scaleform::Render::MeshKey *this,
        unsigned int layer,
        unsigned int flags,
        float *keyData,
        Scaleform::Render::ToleranceParams *cfg)
{
  unsigned int v7; // eax
  float *v8; // rcx
  Scaleform::Render::ToleranceParams *v9; // rdx
  int v10; // ecx
  float v11; // xmm2_4
  int v12; // ecx
  float FillLowerScale; // xmm3_4
  float FillUpperScale; // xmm4_4
  unsigned int v15; // eax
  float *v16; // rcx
  signed __int64 v17; // r8
  float StrokeLowerScale; // xmm3_4
  float StrokeUpperScale; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm10_4
  unsigned int v24; // eax
  float *v25; // rcx
  signed __int64 v26; // r8
  unsigned int v27; // eax
  float *v28; // rcx
  signed __int64 v29; // r8
  __int64 Size; // rax
  float MorphTolerance; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4

  if ( flags == this->Flags && layer == this->pMesh.pObject->Layer )
  {
    if ( (flags & 0x8000) != 0 )
      return 1;
    if ( (flags & 0x10) != 0 )
    {
      v7 = 0;
      v8 = keyData;
      while ( *(float *)((char *)v8 + (char *)this - (char *)keyData + 40) == *v8 )
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
            if ( v11 < (float)(this->Data[v10] * cfg->Scale9LowerScale)
              || v11 > (float)(this->Data[v10] * cfg->Scale9UpperScale) )
            {
              return 0;
            }
            if ( (unsigned int)(++v10 - 8) >= 3 )
            {
              v12 = 11;
              while ( this->Data[v12] == keyData[v12] )
              {
                if ( (unsigned int)(++v12 - 11) >= 2 )
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
      FillLowerScale = cfg->FillLowerScale;
      FillUpperScale = cfg->FillUpperScale;
      if ( (flags & 0x40) == 0 || (flags & 0x80u) != 0 )
      {
        FillLowerScale = cfg->FillAliasedLowerScale;
        FillUpperScale = cfg->FillAliasedUpperScale;
      }
      if ( (flags & 7) == 1 )
      {
        v27 = 0;
        v28 = keyData;
        v29 = (char *)this - (char *)keyData;
        while ( *v28 >= (float)(*(float *)((char *)v28 + v29 + 40) * FillLowerScale)
             && *v28 <= (float)(*(float *)((char *)v28 + v29 + 40) * FillUpperScale) )
        {
          ++v27;
          ++v28;
          if ( v27 >= 3 )
            goto LABEL_43;
        }
      }
      else if ( (flags & 7) == 2 )
      {
        StrokeLowerScale = cfg->StrokeLowerScale;
        StrokeUpperScale = cfg->StrokeUpperScale;
        if ( (flags & 0x20) != 0 )
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
            StrokeLowerScale = cfg->FillLowerScale;
            StrokeUpperScale = cfg->FillUpperScale;
          }
        }
        v24 = 0;
        v25 = keyData;
        v26 = (char *)this - (char *)keyData;
        while ( *v25 >= (float)(*(float *)((char *)v25 + v26 + 40) * StrokeLowerScale)
             && *v25 <= (float)(*(float *)((char *)v25 + v26 + 40) * StrokeUpperScale) )
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
          v17 = (char *)this - (char *)keyData;
          while ( *v16 >= (float)(*(float *)((char *)v16 + v17 + 40) * cfg->HintedStrokeLowerScale)
               && *v16 <= (float)(*(float *)((char *)v16 + v17 + 40) * cfg->HintedStrokeUpperScale) )
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
          Size = this->Size;
          MorphTolerance = v9->MorphTolerance;
          v32 = *((float *)&this->UseCount + Size);
          v33 = keyData[Size - 1];
          if ( v33 >= (float)((float)(1.0 - MorphTolerance) * v32)
            && v33 <= (float)((float)(MorphTolerance + 1.0) * v32) )
          {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 170
// RVA: 0x95C5F0
bool __fastcall Scaleform::Render::MeshKey::CalcMatrixKey(
        Scaleform::Render::Matrix2x4<float> *m,
        float *key,
        Scaleform::Render::Matrix2x4<float> *m2)
{
  bool result; // al
  __m128 v4; // xmm5
  __m128 v5; // xmm4
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm7
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 si128; // xmm5
  __m128 v14; // xmm6
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm2

  if ( m2 )
    return Scaleform::Render::MeshKey::CalcMatrixKey_NonOpt(m, key, m2);
  v4 = *(__m128 *)&m->M[1][0];
  v5 = _mm_shuffle_ps(*(__m128 *)&m->M[0][0], v4, 85);
  v6 = _mm_shuffle_ps(*(__m128 *)&m->M[0][0], v4, 0);
  v7 = _mm_sub_ps(v5, v6);
  v8 = _mm_add_ps(_mm_mul_ps(v4, v4), _mm_mul_ps(*(__m128 *)&m->M[0][0], *(__m128 *)&m->M[0][0]));
  v9 = _mm_mul_ps(v5, v6);
  v10 = _mm_mul_ps(_mm_shuffle_ps(v4, *(__m128 *)&m->M[0][0], 0), v7);
  v11 = _mm_rsqrt_ps(v8);
  v12 = _mm_sub_ps(_mm_shuffle_ps(v10, v10, 10), v10);
  si128 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>::`2::v);
  v14 = _mm_mul_ps(
          _mm_unpacklo_ps(
            _mm_and_ps(
              v12,
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<2147483647,2147483647,2147483647,2147483647>::`2::v),
            _mm_add_ps(_mm_shuffle_ps(v9, v9, 10), v9)),
          _mm_shuffle_ps(v11, v11, 0));
  v15 = _mm_shuffle_ps(v14, v14, 207);
  result = (_mm_movemask_ps(_mm_cmpneq_ps(_mm_shuffle_ps(v8, v14, 4), si128)) & 0xF) == 15;
  v16 = _mm_rcp_ps(
          _mm_shuffle_ps(
            _mm_sub_ps(
              v14,
              _mm_and_ps(v15, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,0,0,0>::`2::v)),
            v11,
            72));
  v17 = _mm_add_ps(_mm_mul_ps(v16, v14), _xmm);
  *(__m128 *)key = _mm_shuffle_ps(
                     v16,
                     _mm_xor_ps(
                       _mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v17, v17, 225), v17), _mm_cmple_ps(si128, v15)),
                       v17),
                     14);
  return result;
}

// File Line: 224
// RVA: 0x95C6E0
char __fastcall Scaleform::Render::MeshKey::CalcMatrixKey_NonOpt(
        Scaleform::Render::Matrix2x4<float> *m,
        float *key,
        Scaleform::Render::Matrix2x4<float> *m2)
{
  float v3; // xmm5_4
  __m128 v4; // xmm3
  float v5; // xmm6_4
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
  int v20; // edx
  unsigned int v21; // eax
  float *v22; // rcx
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  float src[2]; // [rsp+18h] [rbp-29h] BYREF
  __int64 v27; // [rsp+20h] [rbp-21h]
  int v28; // [rsp+28h] [rbp-19h]
  int v29; // [rsp+2Ch] [rbp-15h]
  float dst[2]; // [rsp+30h] [rbp-11h] BYREF
  int v31; // [rsp+38h] [rbp-9h]
  __int64 v32; // [rsp+3Ch] [rbp-5h]
  float v33; // [rsp+44h] [rbp+3h]
  __int64 v34; // [rsp+48h] [rbp+7h]

  v3 = m->M[0][1];
  v4 = (__m128)LODWORD(m->M[1][1]);
  v10 = v4;
  v5 = 0.0;
  v7 = (__m128)LODWORD(m->M[1][0]);
  v8 = m->M[0][0];
  v9 = v7;
  v9.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8);
  v10.m128_f32[0] = (float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v3 * v3);
  if ( v9.m128_f32[0] == 0.0 || v10.m128_f32[0] == 0.0 )
    return 0;
  v11 = _mm_sqrt_ps(v9).m128_f32[0];
  v12 = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                       (float)((float)(v4.m128_f32[0] - v7.m128_f32[0]) * v8)
                     - (float)((float)(v3 - v8) * v7.m128_f32[0])) & _xmm)
      / v11;
  if ( v12 < 0.0000000099999999 )
    return 0;
  *key = v11;
  *((_DWORD *)key + 1) = _mm_sqrt_ps(v10).m128_u32[0];
  v14 = (float)((float)((float)(v4.m128_f32[0] * v7.m128_f32[0]) + (float)(v3 * v8)) * v11) / v9.m128_f32[0];
  if ( v14 < 0.0 )
    v15 = v12 / (float)(v12 - v14);
  else
    v15 = (float)(v14 / v12) + 1.0;
  key[2] = v15;
  if ( m2 )
  {
    v31 = LODWORD(v11);
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
    v16 = m2->M[0][1];
    v31 = 1060439283;
    v32 = 1060439283i64;
    v17 = m2->M[0][0];
    v18 = m2->M[1][1];
    v19 = m2->M[1][0];
    v20 = 4;
    v21 = 0;
    v22 = dst;
    v33 = FLOAT_1_05;
    v34 = LODWORD(FLOAT_N0_70710677) | 0x3F3504F300000000i64;
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
    Scaleform::Render::Matrix2x4<float>::AppendRotation(m2, 1.5707964 - v25);
  }
  return 1;
}

// File Line: 344
// RVA: 0x967900
Scaleform::Render::MeshKey *__fastcall Scaleform::Render::MeshKeySet::CreateKey(
        Scaleform::Render::MeshKeySet *this,
        const float *keyData,
        unsigned __int16 flags)
{
  int v6; // esi
  unsigned int v7; // esi
  Scaleform::Render::MeshKey *result; // rax
  Scaleform::Render::MeshKey *v9; // rbx

  v6 = 3;
  if ( (flags & 0x10) != 0 )
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
    result->pKeySet = this;
    result->Size = v7;
    result->Flags = flags;
    memmove(result->Data, keyData, 4i64 * v7);
    v9->pPrev = this->Meshes.Root.pPrev;
    v9->pNext = (Scaleform::Render::MeshKey *)&this->Meshes;
    this->Meshes.Root.pPrev->pNext = v9;
    this->Meshes.Root.pPrev = v9;
    return v9;
  }
  return result;
}

// File Line: 364
// RVA: 0x96D8F0
void __fastcall Scaleform::Render::MeshKeySet::DestroyKey(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::MeshKey *key)
{
  Scaleform::Render::MeshBase *pObject; // rsi
  Scaleform::Render::MeshProvider *v5; // rcx
  Scaleform::Render::MeshBase *v6; // rcx

  key->pPrev->pNext = key->pNext;
  key->pNext->Scaleform::ListNode<Scaleform::Render::MeshKey>::$BAB5F015784FB5A60A5FC1FF513343B7::pPrev = key->pPrev;
  pObject = key->pMesh.pObject;
  key->pPrev = (Scaleform::Render::MeshKey *)-1i64;
  key->pNext = (Scaleform::Render::MeshKey *)-1i64;
  if ( pObject )
  {
    v5 = pObject->pProvider.pObject;
    if ( v5 )
      v5->vfptr->Release(v5);
    pObject->pProvider.pObject = 0i64;
    v6 = key->pMesh.pObject;
    if ( v6 && _InterlockedExchangeAdd(&v6->RefCount, 0xFFFFFFFF) == 1 )
      v6->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        v6,
        1u);
    key->pMesh.pObject = 0i64;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, key);
  if ( (Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *)this->Meshes.Root.pNext == &this->Meshes )
    Scaleform::Render::MeshKeyManager::destroyKeySet(this->pManager.pObject, this);
}

// File Line: 386
// RVA: 0x96D770
void __fastcall Scaleform::Render::MeshKeySet::DestroyAllKeys(Scaleform::Render::MeshKeySet *this)
{
  Scaleform::Render::MeshKey *pNext; // rbx
  Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *i; // rsi
  Scaleform::Render::MeshBase *pObject; // rdi
  Scaleform::Render::MeshProvider *v5; // rcx
  Scaleform::Render::MeshKey *v6; // rbx
  Scaleform::Render::MeshBase *v7; // rcx
  Scaleform::Render::MeshKey *v8; // rdi

  pNext = this->Meshes.Root.pNext;
  for ( i = &this->Meshes; pNext != (Scaleform::Render::MeshKey *)i; pNext = pNext->pNext )
  {
    pObject = pNext->pMesh.pObject;
    if ( pObject )
    {
      v5 = pObject->pProvider.pObject;
      if ( v5 )
        v5->vfptr->Release(v5);
      pObject->pProvider.pObject = 0i64;
    }
  }
  v6 = this->Meshes.Root.pNext;
  if ( v6 != (Scaleform::Render::MeshKey *)i )
  {
    do
    {
      v7 = v6->pMesh.pObject;
      v8 = v6->pNext;
      if ( v7 )
      {
        if ( !_InterlockedDecrement(&v7->RefCount) )
          v7->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
            v7,
            1u);
        v6->pMesh.pObject = 0i64;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
      v6 = v8;
    }
    while ( v8 != (Scaleform::Render::MeshKey *)i );
  }
  i->Root.pPrev = (Scaleform::Render::MeshKey *)i;
  i->Root.pNext = (Scaleform::Render::MeshKey *)i;
}

// File Line: 416
// RVA: 0x99CAB0
void __fastcall Scaleform::Render::MeshKeySet::OnEvict(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::MeshBase *pmesh)
{
  Scaleform::Render::MeshKey *pNext; // rdx

  pNext = this->Meshes.Root.pNext;
  if ( pNext != (Scaleform::Render::MeshKey *)&this->Meshes )
  {
    while ( pmesh != pNext->pMesh.pObject )
    {
      pNext = pNext->pNext;
      if ( pNext == (Scaleform::Render::MeshKey *)&this->Meshes )
        return;
    }
    if ( !pNext->UseCount )
      Scaleform::Render::MeshKeySet::DestroyKey(this, pNext);
  }
}

// File Line: 434
// RVA: 0x9E2EB0
Scaleform::Render::MeshKeySet *__fastcall Scaleform::Render::MeshKeySet::findMatchingKey(
        Scaleform::Render::MeshKeySet *this,
        unsigned int layer,
        unsigned int flags,
        float *keyData,
        Scaleform::Render::ToleranceParams *cfg)
{
  Scaleform::Render::MeshKeySet *pNext; // rbx
  Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *p_Meshes; // rsi
  const char *pObject; // rax
  const char *pPrev; // rdi

  pNext = (Scaleform::Render::MeshKeySet *)this->Meshes.Root.pNext;
  p_Meshes = &this->Meshes;
  if ( pNext == (Scaleform::Render::MeshKeySet *)&this->Meshes )
    return 0i64;
  while ( 1 )
  {
    pObject = (const char *)pNext->pManager.pObject;
    _mm_prefetch(pObject + 128, 2);
    _mm_prefetch(pObject + 96, 2);
    _mm_prefetch(pObject + 64, 2);
    _mm_prefetch(pObject + 32, 2);
    _mm_prefetch(pObject, 2);
    pPrev = (const char *)pNext->pPrev;
    _mm_prefetch(pPrev + 32, 2);
    _mm_prefetch(pPrev, 2);
    if ( Scaleform::Render::MeshKey::Match((Scaleform::Render::MeshKey *)pNext, layer, flags, keyData, cfg) )
      break;
    pNext = (Scaleform::Render::MeshKeySet *)pPrev;
    if ( pPrev == (const char *)p_Meshes )
      return 0i64;
  }
  return pNext;
}

// File Line: 477
// RVA: 0x96D670
void __fastcall Scaleform::Render::MeshKeyManager::DestroyAllKeys(Scaleform::Render::MeshKeyManager *this)
{
  Scaleform::Lock *p_KeySetLock; // rbx
  $3DA36EFC0C1599C4856EEB4A28887C64 *v3; // rax
  $3DA36EFC0C1599C4856EEB4A28887C64 *v4; // rdx
  Scaleform::Render::MeshKeySet *pNext; // r9
  Scaleform::Render::MeshKeySet *v6; // rcx
  Scaleform::Render::MeshKeySet *pPrev; // rdx
  _QWORD v8[5]; // [rsp+0h] [rbp-48h] BYREF
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v9; // [rsp+28h] [rbp-20h] BYREF

  v8[4] = -2i64;
  p_KeySetLock = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  v3 = 0i64;
  v4 = &this->KeySets[0].Root.8;
  if ( this == (Scaleform::Render::MeshKeyManager *)-72i64 )
    v4 = 0i64;
  pNext = this->KeySets[1].Root.pNext;
  if ( pNext != (Scaleform::Render::MeshKeySet *)v4 )
  {
    v6 = (Scaleform::Render::MeshKeySet *)&v8[4];
    v9.Root.pPrev = v6;
    v9.Root.pNext = v6;
    if ( this != (Scaleform::Render::MeshKeyManager *)-72i64 )
      v3 = &this->KeySets[0].Root.8;
    if ( pNext != (Scaleform::Render::MeshKeySet *)v3 )
    {
      pPrev = this->KeySets[1].Root.pPrev;
      this->KeySets[1].Root.pPrev = (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.8;
      this->KeySets[1].Root.pNext = (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.8;
      pPrev->pNext = v6;
      pNext->pPrev = v6;
      v9.Root.pNext->pPrev = pPrev;
      v6 = pNext;
      v9.Root.pNext = pNext;
    }
    while ( 1 )
    {
      v6->pPrev->pNext = v6->pNext;
      v6->pNext->pPrev = v6->pPrev;
      v6->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
      v6->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
      if ( v6 )
        v6->vfptr->__vecDelDtor(v6, 1u);
      if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v9) )
        break;
      v6 = v9.Root.pNext;
    }
  }
  Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(this, KeySet_LiveList);
  LeaveCriticalSection(&p_KeySetLock->cs);
}

// File Line: 484
// RVA: 0x99FCD0
void __fastcall Scaleform::Render::MeshKeyManager::ProcessKillList(Scaleform::Render::MeshKeyManager *this)
{
  Scaleform::Lock *p_KeySetLock; // rbx
  Scaleform::Render::MeshKeySet *v3; // rax
  bool v4; // zf
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> *v5; // rdi
  Scaleform::Render::MeshKeySet *v6; // rcx
  Scaleform::Render::MeshKeySet *pNext; // r8
  Scaleform::Render::MeshKeySet *v8; // rcx
  Scaleform::Render::MeshKeySet *pPrev; // rdx
  _QWORD v10[5]; // [rsp+0h] [rbp-48h] BYREF
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v11; // [rsp+28h] [rbp-20h] BYREF

  v10[4] = -2i64;
  p_KeySetLock = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  v3 = 0i64;
  v4 = &this->KeySets[1] == 0i64;
  v5 = &this->KeySets[1];
  v6 = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
  if ( v4 )
    v6 = 0i64;
  pNext = v5->Root.pNext;
  if ( pNext != v6 )
  {
    v8 = (Scaleform::Render::MeshKeySet *)&v10[4];
    v11.Root.pPrev = v8;
    v11.Root.pNext = v8;
    if ( v5 )
      v3 = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
    if ( pNext != v3 )
    {
      pPrev = v5->Root.pPrev;
      v5->Root.pPrev = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
      v5->Root.pNext = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
      pPrev->pNext = v8;
      pNext->pPrev = v8;
      v11.Root.pNext->pPrev = pPrev;
      v8 = pNext;
      v11.Root.pNext = pNext;
    }
    while ( 1 )
    {
      v8->pPrev->pNext = v8->pNext;
      v8->pNext->pPrev = v8->pPrev;
      v8->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
      v8->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
      if ( v8 )
        v8->vfptr->__vecDelDtor(v8, 1u);
      if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v11) )
        break;
      v8 = v11.Root.pNext;
    }
  }
  LeaveCriticalSection(&p_KeySetLock->cs);
}

// File Line: 494
// RVA: 0x9679D0
Scaleform::Render::MeshKey *__fastcall Scaleform::Render::MeshKeyManager::CreateMatchingKey(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshProvider_KeySupport *provider,
        unsigned int layer,
        unsigned int flags,
        const float *keyData,
        Scaleform::Render::ToleranceParams *cfg)
{
  Scaleform::Render::MeshKeySet *v10; // rcx
  Scaleform::Render::MeshKey *result; // rax
  Scaleform::Render::MeshKeySet *volatile pKeySet; // rcx
  Scaleform::Render::MeshKeySet *v13; // rbx
  Scaleform::Lock *lpCriticalSection; // [rsp+68h] [rbp+10h]

  if ( !provider->hKeySet.pManager.Value )
  {
    _InterlockedExchangeAdd(&this->RefCount, 1u);
    provider->hKeySet.pManager.Value = this;
  }
  if ( !provider->hKeySet.pKeySet )
  {
    lpCriticalSection = &this->KeySetLock;
    EnterCriticalSection(&this->KeySetLock.cs);
    v10 = (Scaleform::Render::MeshKeySet *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pRenderHeap->vfptr->Alloc)(
                                             this->pRenderHeap,
                                             56i64);
    if ( v10 )
    {
      v10->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable;
      v10->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshKeySet::`vftable;
      _InterlockedExchangeAdd(&this->RefCount, 1u);
      v10->pManager.pObject = this;
      v10->pDelegate = provider;
      v10->Meshes.Root.pPrev = (Scaleform::Render::MeshKey *)&v10->Meshes;
      v10->Meshes.Root.pNext = (Scaleform::Render::MeshKey *)&v10->Meshes;
    }
    else
    {
      v10 = 0i64;
    }
    provider->hKeySet.pKeySet = v10;
    if ( !provider->hKeySet.pKeySet )
    {
      LeaveCriticalSection(&lpCriticalSection->cs);
      return 0i64;
    }
    pKeySet = provider->hKeySet.pKeySet;
    pKeySet->pPrev = this->KeySets[0].Root.pPrev;
    pKeySet->pNext = (Scaleform::Render::MeshKeySet *)&this->KeySetLock.cs.SpinCount;
    this->KeySets[0].Root.pPrev->pNext = pKeySet;
    this->KeySets[0].Root.pPrev = pKeySet;
    LeaveCriticalSection(&lpCriticalSection->cs);
  }
  v13 = provider->hKeySet.pKeySet;
  result = Scaleform::Render::MeshKeySet::findMatchingKey(v13, layer, flags, keyData, cfg);
  if ( !result )
    return Scaleform::Render::MeshKeySet::CreateKey(v13, keyData, flags);
  ++result->UseCount;
  return result;
}

// File Line: 537
// RVA: 0x9EE490
void __fastcall Scaleform::Render::MeshKeyManager::providerLost(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshKeySetHandle *handle)
{
  Scaleform::Render::MeshKeySet *volatile pKeySet; // r8
  Scaleform::Lock *p_KeySetLock; // [rsp+40h] [rbp+8h]

  p_KeySetLock = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  pKeySet = handle->pKeySet;
  if ( pKeySet )
  {
    pKeySet->pPrev->pNext = pKeySet->pNext;
    pKeySet->pNext->pPrev = pKeySet->pPrev;
    pKeySet->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
    pKeySet->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
    pKeySet->pPrev = this->KeySets[1].Root.pPrev;
    pKeySet->pNext = (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.8;
    this->KeySets[1].Root.pPrev->pNext = pKeySet;
    this->KeySets[1].Root.pPrev = pKeySet;
    pKeySet->pDelegate = 0i64;
    handle->pKeySet = 0i64;
  }
  LeaveCriticalSection(&p_KeySetLock->cs);
}

// File Line: 562
// RVA: 0x9DFB60
void __fastcall Scaleform::Render::MeshKeyManager::destroyKeySet(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshKeySet *keySet)
{
  Scaleform::Lock *p_KeySetLock; // rbx
  Scaleform::Render::MeshProvider_KeySupport *pDelegate; // rax
  $3DA36EFC0C1599C4856EEB4A28887C64 *v6; // rdi
  __int64 v7; // rcx
  $3DA36EFC0C1599C4856EEB4A28887C64 *v8; // rax
  Scaleform::Render::MeshKeySet *pNext; // r9
  $3DA36EFC0C1599C4856EEB4A28887C64 *v10; // rax
  Scaleform::Render::MeshKeySet *v11; // rcx
  Scaleform::Render::MeshKeySet *pPrev; // rdx
  _QWORD v13[5]; // [rsp+0h] [rbp-48h] BYREF
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v14; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::Lock *v15; // [rsp+50h] [rbp+8h]

  v13[4] = -2i64;
  p_KeySetLock = &this->KeySetLock;
  v15 = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  pDelegate = keySet->pDelegate;
  v6 = 0i64;
  if ( pDelegate )
  {
    pDelegate->hKeySet.pKeySet = 0i64;
    v7 = _InterlockedExchange64((volatile __int64 *)&pDelegate->hKeySet, 0i64);
    if ( v7 && !_InterlockedDecrement((volatile signed __int32 *)(v7 + 8)) )
      (**(void (__fastcall ***)(__int64, __int64))v7)(v7, 1i64);
    keySet->pDelegate = 0i64;
    p_KeySetLock = v15;
  }
  keySet->pPrev->pNext = keySet->pNext;
  keySet->pNext->pPrev = keySet->pPrev;
  keySet->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
  keySet->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
  keySet->vfptr->__vecDelDtor(keySet, 1i64);
  v8 = &this->KeySets[0].Root.8;
  if ( this == (Scaleform::Render::MeshKeyManager *)-72i64 )
    v8 = 0i64;
  pNext = this->KeySets[1].Root.pNext;
  if ( pNext != (Scaleform::Render::MeshKeySet *)v8 )
  {
    v10 = &this->KeySets[0].Root.8;
    if ( this == (Scaleform::Render::MeshKeyManager *)-72i64 )
      v10 = 0i64;
    if ( pNext != (Scaleform::Render::MeshKeySet *)v10 )
    {
      v11 = (Scaleform::Render::MeshKeySet *)&v13[4];
      v14.Root.pPrev = v11;
      v14.Root.pNext = v11;
      if ( this != (Scaleform::Render::MeshKeyManager *)-72i64 )
        v6 = &this->KeySets[0].Root.8;
      if ( pNext != (Scaleform::Render::MeshKeySet *)v6 )
      {
        pPrev = this->KeySets[1].Root.pPrev;
        this->KeySets[1].Root.pPrev = (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.8;
        this->KeySets[1].Root.pNext = (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.8;
        pPrev->pNext = v11;
        pNext->pPrev = v11;
        v14.Root.pNext->pPrev = pPrev;
        v11 = pNext;
        v14.Root.pNext = pNext;
      }
      while ( 1 )
      {
        v11->pPrev->pNext = v11->pNext;
        v11->pNext->pPrev = v11->pPrev;
        v11->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
        v11->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
        if ( v11 )
          v11->vfptr->__vecDelDtor(v11, 1u);
        if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v14) )
          break;
        v11 = v14.Root.pNext;
      }
    }
  }
  LeaveCriticalSection(&p_KeySetLock->cs);
}

// File Line: 575
// RVA: 0x9DFCF0
void __fastcall Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshKeyManager::KeySetListType type)
{
  __int64 v3; // rax
  bool v4; // zf
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> *v5; // r8
  Scaleform::Render::MeshKeySet *v6; // rax
  Scaleform::Render::MeshKeySet *pNext; // rdx
  Scaleform::Render::MeshKeySet *v8; // rax
  Scaleform::Render::MeshKeySet *v9; // rbx
  Scaleform::Render::MeshKeySet *pPrev; // rcx
  Scaleform::Render::MeshProvider_KeySupport *pDelegate; // rax
  __int64 v12; // rcx
  __int64 v13; // [rsp+0h] [rbp-38h] BYREF
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v14; // [rsp+20h] [rbp-18h] BYREF

  v3 = type;
  v4 = &this->KeySets[v3] == 0i64;
  v5 = &this->KeySets[v3];
  v6 = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
  if ( v4 )
    v6 = 0i64;
  pNext = v5->Root.pNext;
  if ( pNext != v6 )
  {
    v8 = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
    v9 = (Scaleform::Render::MeshKeySet *)(&v13 + 3);
    v14.Root.pPrev = v9;
    v14.Root.pNext = v9;
    if ( !v5 )
      v8 = 0i64;
    if ( pNext != v8 )
    {
      pPrev = v5->Root.pPrev;
      v5->Root.pPrev = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
      v5->Root.pNext = (Scaleform::Render::MeshKeySet *)&v5[-1].Root.8;
      pPrev->pNext = v9;
      pNext->pPrev = v9;
      v9 = pNext;
      v14.Root.pNext->pPrev = pPrev;
      v14.Root.pNext = pNext;
    }
    while ( 1 )
    {
      if ( type != KeySet_KillList )
      {
        pDelegate = v9->pDelegate;
        if ( pDelegate )
        {
          pDelegate->hKeySet.pKeySet = 0i64;
          v12 = _InterlockedExchange64((volatile __int64 *)&pDelegate->hKeySet, 0i64);
          if ( v12 )
          {
            if ( !_InterlockedDecrement((volatile signed __int32 *)(v12 + 8)) )
              (**(void (__fastcall ***)(__int64, __int64))v12)(v12, 1i64);
          }
          v9->pDelegate = 0i64;
        }
      }
      v9->pPrev->pNext = v9->pNext;
      v9->pNext->pPrev = v9->pPrev;
      v9->pPrev = (Scaleform::Render::MeshKeySet *)-1i64;
      v9->pNext = (Scaleform::Render::MeshKeySet *)-1i64;
      v9->vfptr->__vecDelDtor(v9, 1u);
      if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v14) )
        break;
      v9 = v14.Root.pNext;
    }
  }
}

