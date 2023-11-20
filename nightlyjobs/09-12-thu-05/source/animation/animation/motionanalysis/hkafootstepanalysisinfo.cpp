// File Line: 14
// RVA: 0xB357E0
void __fastcall hkaFootstepAnalysisInfoContainer::hkaFootstepAnalysisInfoContainer(hkaFootstepAnalysisInfoContainer *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaFootstepAnalysisInfoContainer::`vftable';
  this->m_previewInfo.m_capacityAndFlags = 2147483648;
  this->m_previewInfo.m_data = 0i64;
  this->m_previewInfo.m_size = 0;
}

// File Line: 18
// RVA: 0xB35810
void __fastcall hkaFootstepAnalysisInfoContainer::~hkaFootstepAnalysisInfoContainer(hkaFootstepAnalysisInfoContainer *this)
{
  hkaFootstepAnalysisInfoContainer *v1; // rdi
  hkRefPtr<hkaFootstepAnalysisInfo> *v2; // rsi
  int v3; // eax
  __int64 i; // rbx
  hkReferencedObject *v5; // rcx
  int v6; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaFootstepAnalysisInfoContainer::`vftable';
  v2 = this->m_previewInfo.m_data;
  v3 = this->m_previewInfo.m_size - 1;
  for ( i = v3; i >= 0; v2[i--].m_pntr = 0i64 )
  {
    v5 = (hkReferencedObject *)&v2[i].m_pntr->vfptr;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
  }
  v6 = v1->m_previewInfo.m_capacityAndFlags;
  v1->m_previewInfo.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_previewInfo.m_data,
      8 * v6);
  v1->m_previewInfo.m_data = 0i64;
  v1->m_previewInfo.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 32
// RVA: 0xB34DA0
void __fastcall hkaFootstepAnalysisInfo::hkaFootstepAnalysisInfo(hkaFootstepAnalysisInfo *this, int n, float duration, float posTol, float velTol, const char *name, const char *nameStrike, const char *nameLift, const char *nameLock, const char *nameUnlock)
{
  float *v10; // rsi
  unsigned int v11; // er15
  hkaFootstepAnalysisInfo *v12; // rbx
  __int64 v13; // r14
  int v14; // ecx
  float *v15; // rdi
  unsigned int v16; // eax
  __int64 i; // rcx
  int v18; // ecx
  float *v19; // rdi
  unsigned int v20; // eax
  __int64 j; // rcx
  int v22; // eax
  float *v23; // rdi
  unsigned int v24; // ecx
  __int64 k; // rcx
  int v26; // eax
  float *v27; // rdi
  unsigned int v28; // ecx
  __int64 l; // rcx
  int v30; // ecx
  float *v31; // rdi
  unsigned int v32; // eax
  __int64 m; // rcx
  int v34; // eax
  float *v35; // rdi
  __int64 ii; // rcx
  float v37; // xmm0_4
  const char *v38; // rsi
  int v39; // edi
  int v40; // eax
  int v41; // eax
  int v42; // er9
  const char *v43; // rsi
  int v44; // edi
  int v45; // eax
  int v46; // eax
  int v47; // er9
  const char *v48; // rsi
  int v49; // edi
  int v50; // eax
  int v51; // eax
  int v52; // er9
  const char *v53; // rsi
  int v54; // edi
  int v55; // eax
  int v56; // eax
  int v57; // er9
  const char *v58; // rsi
  int v59; // edi
  int v60; // eax
  int v61; // eax
  int v62; // er9
  int v63; // [rsp+88h] [rbp+38h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v10 = 0i64;
  v11 = 2147483648;
  v12 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaFootstepAnalysisInfo::`vftable';
  this->m_name.m_data = 0i64;
  this->m_name.m_size = 0;
  this->m_name.m_capacityAndFlags = 2147483648;
  this->m_nameStrike.m_data = 0i64;
  this->m_nameStrike.m_size = 0;
  this->m_nameStrike.m_capacityAndFlags = 2147483648;
  this->m_nameLift.m_data = 0i64;
  this->m_nameLift.m_size = 0;
  this->m_nameLift.m_capacityAndFlags = 2147483648;
  this->m_nameLock.m_data = 0i64;
  this->m_nameLock.m_size = 0;
  this->m_nameLock.m_capacityAndFlags = 2147483648;
  this->m_nameUnlock.m_data = 0i64;
  this->m_nameUnlock.m_size = 0;
  this->m_nameUnlock.m_capacityAndFlags = 2147483648;
  v13 = n;
  this->m_minPos.m_data = 0i64;
  this->m_minPos.m_size = 0;
  this->m_minPos.m_capacityAndFlags = 2147483648;
  v14 = n;
  if ( n )
  {
    v63 = 4 * n;
    v15 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v63);
    v14 = v63 / 4;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = 2147483648;
  v12->m_minPos.m_data = v15;
  if ( v14 )
    v16 = v14;
  v12->m_minPos.m_size = v13;
  v12->m_minPos.m_capacityAndFlags = v16;
  if ( (signed int)v13 > 0 )
  {
    for ( i = v13; i; --i )
    {
      *v15 = 3.40282e38;
      ++v15;
    }
  }
  v18 = v13;
  v12->m_maxPos.m_data = 0i64;
  v12->m_maxPos.m_size = 0;
  v12->m_maxPos.m_capacityAndFlags = 2147483648;
  if ( (_DWORD)v13 )
  {
    v63 = 4 * v13;
    v19 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v63);
    v18 = v63 / 4;
  }
  else
  {
    v19 = 0i64;
  }
  v20 = 2147483648;
  v12->m_maxPos.m_data = v19;
  if ( v18 )
    v20 = v18;
  v12->m_maxPos.m_size = v13;
  v12->m_maxPos.m_capacityAndFlags = v20;
  if ( (signed int)v13 > 0 )
  {
    for ( j = v13; j; --j )
    {
      *v19 = -3.40282e38;
      ++v19;
    }
  }
  v22 = v13;
  v12->m_minVel.m_data = 0i64;
  v12->m_minVel.m_size = 0;
  v12->m_minVel.m_capacityAndFlags = 2147483648;
  if ( (_DWORD)v13 )
  {
    v63 = 4 * v13;
    v23 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v63);
    v22 = v63 / 4;
  }
  else
  {
    v23 = 0i64;
  }
  v24 = 2147483648;
  v12->m_minVel.m_data = v23;
  if ( v22 )
    v24 = v22;
  v12->m_minVel.m_size = v13;
  v12->m_minVel.m_capacityAndFlags = v24;
  if ( (signed int)v13 > 0 )
  {
    for ( k = v13; k; --k )
    {
      *v23 = 3.40282e38;
      ++v23;
    }
  }
  v26 = v13;
  v12->m_maxVel.m_data = 0i64;
  v12->m_maxVel.m_size = 0;
  v12->m_maxVel.m_capacityAndFlags = 2147483648;
  if ( (_DWORD)v13 )
  {
    v63 = 4 * v13;
    v27 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v63);
    v26 = v63 / 4;
  }
  else
  {
    v27 = 0i64;
  }
  v28 = 2147483648;
  v12->m_maxVel.m_data = v27;
  if ( v26 )
    v28 = v26;
  v12->m_maxVel.m_size = v13;
  v12->m_maxVel.m_capacityAndFlags = v28;
  if ( (signed int)v13 > 0 )
  {
    for ( l = v13; l; --l )
    {
      *v27 = -3.40282e38;
      ++v27;
    }
  }
  v30 = v13;
  v12->m_allBonesDown.m_data = 0i64;
  v12->m_allBonesDown.m_size = 0;
  v12->m_allBonesDown.m_capacityAndFlags = 2147483648;
  if ( (_DWORD)v13 )
  {
    v63 = 4 * v13;
    v31 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v63);
    v30 = v63 / 4;
  }
  else
  {
    v31 = 0i64;
  }
  v32 = 2147483648;
  v12->m_allBonesDown.m_data = v31;
  if ( v30 )
    v32 = v30;
  v12->m_allBonesDown.m_size = v13;
  v12->m_allBonesDown.m_capacityAndFlags = v32;
  if ( (signed int)v13 > 0 )
  {
    for ( m = v13; m; --m )
    {
      *v31 = 0.0;
      ++v31;
    }
  }
  v34 = v13;
  v12->m_anyBonesDown.m_data = 0i64;
  v12->m_anyBonesDown.m_size = 0;
  v12->m_anyBonesDown.m_capacityAndFlags = 2147483648;
  if ( (_DWORD)v13 )
  {
    v63 = 4 * v13;
    v10 = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                     &v63);
    v34 = v63 / 4;
  }
  v12->m_anyBonesDown.m_data = v10;
  v12->m_anyBonesDown.m_size = v13;
  if ( v34 )
    v11 = v34;
  v12->m_anyBonesDown.m_capacityAndFlags = v11;
  if ( (signed int)v13 > 0 )
  {
    v35 = v10;
    for ( ii = v13; ii; --ii )
    {
      *v35 = 1.0;
      ++v35;
    }
  }
  v37 = velTol;
  v38 = name;
  v12->m_posTol = posTol;
  v12->m_velTol = v37;
  v12->m_duration = duration;
  v39 = hkString::strLen(v38) + 1;
  v40 = v12->m_name.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v40 < v39 )
  {
    v41 = 2 * v40;
    v42 = v39;
    if ( v39 < v41 )
      v42 = v41;
    hkArrayUtil::_reserve(
      (hkResult *)&velTol,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v12->m_name,
      v42,
      1);
  }
  v12->m_name.m_size = v39;
  hkString::strCpy(v12->m_name.m_data, v38);
  v43 = nameStrike;
  v44 = hkString::strLen(nameStrike) + 1;
  v45 = v12->m_nameStrike.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v45 < v44 )
  {
    v46 = 2 * v45;
    v47 = v44;
    if ( v44 < v46 )
      v47 = v46;
    hkArrayUtil::_reserve(
      (hkResult *)&velTol,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v12->m_nameStrike,
      v47,
      1);
  }
  v12->m_nameStrike.m_size = v44;
  hkString::strCpy(v12->m_nameStrike.m_data, v43);
  v48 = nameLift;
  v49 = hkString::strLen(nameLift) + 1;
  v50 = v12->m_nameLift.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v50 < v49 )
  {
    v51 = 2 * v50;
    v52 = v49;
    if ( v49 < v51 )
      v52 = v51;
    hkArrayUtil::_reserve(
      (hkResult *)&velTol,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v12->m_nameLift,
      v52,
      1);
  }
  v12->m_nameLift.m_size = v49;
  hkString::strCpy(v12->m_nameLift.m_data, v48);
  v53 = nameLock;
  v54 = hkString::strLen(nameLock) + 1;
  v55 = v12->m_nameLock.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v55 < v54 )
  {
    v56 = 2 * v55;
    v57 = v54;
    if ( v54 < v56 )
      v57 = v56;
    hkArrayUtil::_reserve(
      (hkResult *)&velTol,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v12->m_nameLock,
      v57,
      1);
  }
  v12->m_nameLock.m_size = v54;
  hkString::strCpy(v12->m_nameLock.m_data, v53);
  v58 = nameUnlock;
  v59 = hkString::strLen(nameUnlock) + 1;
  v60 = v12->m_nameUnlock.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v60 < v59 )
  {
    v61 = 2 * v60;
    v62 = v59;
    if ( v59 < v61 )
      v62 = v61;
    hkArrayUtil::_reserve(
      (hkResult *)&velTol,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v12->m_nameUnlock,
      v62,
      1);
  }
  v12->m_nameUnlock.m_size = v59;
  hkString::strCpy(v12->m_nameUnlock.m_data, v58);
}

// File Line: 62
// RVA: 0xB352C0
void __fastcall hkaFootstepAnalysisInfo::hkaFootstepAnalysisInfo(hkaFootstepAnalysisInfo *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaFootstepAnalysisInfo::`vftable';
}

// File Line: 66
// RVA: 0xB352E0
void __fastcall hkaFootstepAnalysisInfo::~hkaFootstepAnalysisInfo(hkaFootstepAnalysisInfo *this)
{
  hkaFootstepAnalysisInfo *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // er8
  int v6; // er8
  int v7; // er8
  int v8; // er8
  int v9; // er8
  int v10; // er8
  int v11; // er8
  int v12; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaFootstepAnalysisInfo::`vftable';
  v2 = this->m_anyBonesDown.m_capacityAndFlags;
  this->m_anyBonesDown.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_anyBonesDown.m_data,
      4 * v2);
  v1->m_anyBonesDown.m_data = 0i64;
  v1->m_anyBonesDown.m_capacityAndFlags = 2147483648;
  v3 = v1->m_allBonesDown.m_capacityAndFlags;
  v1->m_allBonesDown.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_allBonesDown.m_data,
      4 * v3);
  v1->m_allBonesDown.m_data = 0i64;
  v1->m_allBonesDown.m_capacityAndFlags = 2147483648;
  v4 = v1->m_maxVel.m_capacityAndFlags;
  v1->m_maxVel.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_maxVel.m_data,
      4 * v4);
  v1->m_maxVel.m_data = 0i64;
  v1->m_maxVel.m_capacityAndFlags = 2147483648;
  v5 = v1->m_minVel.m_capacityAndFlags;
  v1->m_minVel.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_minVel.m_data,
      4 * v5);
  v1->m_minVel.m_data = 0i64;
  v1->m_minVel.m_capacityAndFlags = 2147483648;
  v6 = v1->m_maxPos.m_capacityAndFlags;
  v1->m_maxPos.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_maxPos.m_data,
      4 * v6);
  v1->m_maxPos.m_data = 0i64;
  v1->m_maxPos.m_capacityAndFlags = 2147483648;
  v7 = v1->m_minPos.m_capacityAndFlags;
  v1->m_minPos.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_minPos.m_data,
      4 * v7);
  v1->m_minPos.m_data = 0i64;
  v1->m_minPos.m_capacityAndFlags = 2147483648;
  v8 = v1->m_nameUnlock.m_capacityAndFlags;
  v1->m_nameUnlock.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_nameUnlock.m_data,
      v8 & 0x3FFFFFFF);
  v1->m_nameUnlock.m_data = 0i64;
  v1->m_nameUnlock.m_capacityAndFlags = 2147483648;
  v9 = v1->m_nameLock.m_capacityAndFlags;
  v1->m_nameLock.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_nameLock.m_data,
      v9 & 0x3FFFFFFF);
  v1->m_nameLock.m_data = 0i64;
  v1->m_nameLock.m_capacityAndFlags = 2147483648;
  v10 = v1->m_nameLift.m_capacityAndFlags;
  v1->m_nameLift.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_nameLift.m_data,
      v10 & 0x3FFFFFFF);
  v1->m_nameLift.m_data = 0i64;
  v1->m_nameLift.m_capacityAndFlags = 2147483648;
  v11 = v1->m_nameStrike.m_capacityAndFlags;
  v1->m_nameStrike.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_nameStrike.m_data,
      v11 & 0x3FFFFFFF);
  v1->m_nameStrike.m_data = 0i64;
  v1->m_nameStrike.m_capacityAndFlags = 2147483648;
  v12 = v1->m_name.m_capacityAndFlags;
  v1->m_name.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_name.m_data,
      v12 & 0x3FFFFFFF);
  v1->m_name.m_data = 0i64;
  v1->m_name.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 70
// RVA: 0xB356A0
float __fastcall hkaFootstepAnalysisInfo::getMax(hkArrayBase<float> *arr)
{
  int v1; // er8
  __m128 v2; // xmm2
  int v3; // er9
  hkArrayBase<float> *v4; // r10
  float *v5; // rdx
  unsigned int v6; // eax
  __int64 v7; // rcx
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  float *v10; // rdx
  __int64 v11; // rax
  __m128 v12; // xmm1

  v1 = arr->m_size;
  v2 = (__m128)xmmword_141A712F0;
  v3 = 0;
  v4 = arr;
  if ( (signed int)(arr->m_size & 0xFFFFFFFC) > 0 )
  {
    v5 = arr->m_data;
    v6 = (((arr->m_size & 0xFFFFFFFC) - 1) >> 2) + 1;
    v7 = v6;
    v3 = 4 * v6;
    do
    {
      v8 = *(__m128 *)v5;
      v5 += 4;
      v9 = _mm_max_ps(_mm_shuffle_ps(v8, v8, 78), v8);
      v2 = _mm_max_ps(v2, _mm_max_ps(v9, _mm_shuffle_ps(v9, v9, 177)));
      --v7;
    }
    while ( v7 );
  }
  if ( v3 >= v1 )
    return v2.m128_f32[0];
  v10 = &v4->m_data[v3];
  v11 = (unsigned int)(v1 - v3);
  do
  {
    v12 = (__m128)*(unsigned int *)v10;
    ++v10;
    v2 = _mm_max_ps(v2, _mm_shuffle_ps(v12, v12, 0));
    --v11;
  }
  while ( v11 );
  return v2.m128_f32[0];
}

// File Line: 91
// RVA: 0xB35740
float __fastcall hkaFootstepAnalysisInfo::getMin(hkArrayBase<float> *arr)
{
  int v1; // er8
  __m128 v2; // xmm2
  int v3; // er9
  hkArrayBase<float> *v4; // r10
  float *v5; // rdx
  unsigned int v6; // eax
  __int64 v7; // rcx
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  float *v10; // rdx
  __int64 v11; // rax
  __m128 v12; // xmm1

  v1 = arr->m_size;
  v2 = (__m128)xmmword_141A712A0;
  v3 = 0;
  v4 = arr;
  if ( (signed int)(arr->m_size & 0xFFFFFFFC) > 0 )
  {
    v5 = arr->m_data;
    v6 = (((arr->m_size & 0xFFFFFFFC) - 1) >> 2) + 1;
    v7 = v6;
    v3 = 4 * v6;
    do
    {
      v8 = *(__m128 *)v5;
      v5 += 4;
      v9 = _mm_min_ps(_mm_shuffle_ps(v8, v8, 78), v8);
      v2 = _mm_min_ps(v2, _mm_min_ps(v9, _mm_shuffle_ps(v9, v9, 177)));
      --v7;
    }
    while ( v7 );
  }
  if ( v3 >= v1 )
    return v2.m128_f32[0];
  v10 = &v4->m_data[v3];
  v11 = (unsigned int)(v1 - v3);
  do
  {
    v12 = (__m128)*(unsigned int *)v10;
    ++v10;
    v2 = _mm_min_ps(v2, _mm_shuffle_ps(v12, v12, 0));
    --v11;
  }
  while ( v11 );
  return v2.m128_f32[0];
}

// File Line: 112
// RVA: 0xB355A0
void __fastcall hkaFootstepAnalysisInfo::updatePosition(hkaFootstepAnalysisInfo *this, int frame, float value)
{
  __int64 v3; // rdx
  float v4; // xmm2_4

  v3 = frame;
  LODWORD(v4) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(value), (__m128)LODWORD(value), 0);
  this->m_minPos.m_data[v3] = fmin(
                                v4,
                                COERCE_FLOAT(
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(this->m_minPos.m_data[v3]),
                                    (__m128)LODWORD(this->m_minPos.m_data[v3]),
                                    0)));
  this->m_maxPos.m_data[v3] = fmax(
                                v4,
                                COERCE_FLOAT(
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(this->m_maxPos.m_data[v3]),
                                    (__m128)LODWORD(this->m_maxPos.m_data[v3]),
                                    0)));
}

// File Line: 124
// RVA: 0xB355F0
void __fastcall hkaFootstepAnalysisInfo::updateVelocity(hkaFootstepAnalysisInfo *this, int frame, float value)
{
  hkaFootstepAnalysisInfo *v3; // r8
  signed __int64 v4; // rcx
  float v5; // xmm2_4

  v3 = this;
  v4 = frame;
  LODWORD(v5) = 2 * (unsigned int)*(_OWORD *)&_mm_shuffle_ps((__m128)LODWORD(value), (__m128)LODWORD(value), 0) >> 1;
  v3->m_minVel.m_data[v4] = fmin(
                              v5,
                              COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v3->m_minVel.m_data[v4]),
                                  (__m128)LODWORD(v3->m_minVel.m_data[v4]),
                                  0)));
  v3->m_maxVel.m_data[v4] = fmax(
                              v5,
                              COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v3->m_maxVel.m_data[v4]),
                                  (__m128)LODWORD(v3->m_maxVel.m_data[v4]),
                                  0)));
}

// File Line: 136
// RVA: 0xB35660
void __fastcall hkaFootstepAnalysisInfo::updateBones(hkaFootstepAnalysisInfo *this, int frame, hkBool isDown)
{
  if ( isDown.m_bool )
    this->m_anyBonesDown.m_data[frame] = 0.0;
  else
    this->m_allBonesDown.m_data[frame] = 1.0;
}

// File Line: 149
// RVA: 0xB358C0
hkaFootstepAnalysisInfo *__fastcall hkaFootstepAnalysisInfoContainer::newPreviewInfo(hkaFootstepAnalysisInfoContainer *this, int numFrames, float duration, float posTol, float velTol, const char *name, const char *nameStrike, const char *nameLift, const char *nameLock, const char *nameUnlock)
{
  hkaFootstepAnalysisInfoContainer *v10; // rbp
  int v11; // ebx
  _QWORD **v12; // rax
  hkaFootstepAnalysisInfo *v13; // rax
  hkReferencedObject *v14; // rax
  hkReferencedObject *v15; // rbx
  _QWORD *v16; // rsi
  hkaFootstepAnalysisInfo *v17; // rdi

  v10 = this;
  v11 = numFrames;
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkaFootstepAnalysisInfo *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                     v12[11],
                                     208i64);
  if ( v13 )
  {
    hkaFootstepAnalysisInfo::hkaFootstepAnalysisInfo(
      v13,
      v11,
      duration,
      posTol,
      velTol,
      name,
      nameStrike,
      nameLift,
      nameLock,
      nameUnlock);
    v15 = v14;
    if ( v14 )
      hkReferencedObject::addReference(v14);
  }
  else
  {
    v15 = 0i64;
  }
  if ( v10->m_previewInfo.m_size == (v10->m_previewInfo.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v10->m_previewInfo, 8);
  v16 = &v10->m_previewInfo.m_data[v10->m_previewInfo.m_size].m_pntr;
  if ( v16 )
  {
    if ( v15 )
      hkReferencedObject::addReference(v15);
    *v16 = v15;
  }
  ++v10->m_previewInfo.m_size;
  hkReferencedObject::removeReference(v15);
  v17 = v10->m_previewInfo.m_data[v10->m_previewInfo.m_size - 1].m_pntr;
  if ( v15 )
    hkReferencedObject::removeReference(v15);
  return v17;
}

