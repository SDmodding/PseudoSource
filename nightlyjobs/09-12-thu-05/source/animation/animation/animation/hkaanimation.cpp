// File Line: 14
// RVA: 0xB35FD0
void __fastcall hkaAnimation::hkaAnimation(hkaAnimation *this, hkaAnimation *that)
{
  hkaAnimatedReferenceFrame *m_pntr; // rcx
  hkaAnimatedReferenceFrame *v5; // rcx
  __int64 m_size; // rbp
  int v7; // ebx
  int v8; // r12d
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  int v12; // ebx
  hkaAnnotationTrack *v13; // rdi
  hkaAnnotationTrack *m_data; // rbx
  char *v15; // rsi
  __int64 v16; // rdi
  hkaAnnotationTrack *v17; // rbx
  char *v18; // rsi
  __int64 v19; // rdi
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaAnimation::`vftable;
  this->m_extractedMotion.m_pntr = 0i64;
  this->m_annotationTracks.m_data = 0i64;
  this->m_annotationTracks.m_size = 0;
  this->m_annotationTracks.m_capacityAndFlags = 0x80000000;
  this->m_type.m_storage = that->m_type.m_storage;
  this->m_duration = that->m_duration;
  this->m_numberOfTransformTracks = that->m_numberOfTransformTracks;
  this->m_numberOfFloatTracks = that->m_numberOfFloatTracks;
  m_pntr = that->m_extractedMotion.m_pntr;
  if ( m_pntr )
    hkReferencedObject::addReference(m_pntr);
  v5 = this->m_extractedMotion.m_pntr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  this->m_extractedMotion.m_pntr = that->m_extractedMotion.m_pntr;
  m_size = that->m_annotationTracks.m_size;
  v7 = this->m_annotationTracks.m_size;
  v8 = that->m_annotationTracks.m_size;
  if ( (int)m_size > v7 )
    v8 = this->m_annotationTracks.m_size;
  v9 = this->m_annotationTracks.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < (int)m_size )
  {
    v10 = 2 * v9;
    v11 = that->m_annotationTracks.m_size;
    if ( (int)m_size < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_annotationTracks, v11, 24);
  }
  v12 = v7 - m_size - 1;
  if ( v12 >= 0 )
  {
    v13 = &this->m_annotationTracks.m_data[m_size + v12];
    do
    {
      hkaAnnotationTrack::~hkaAnnotationTrack(v13--);
      --v12;
    }
    while ( v12 >= 0 );
  }
  m_data = this->m_annotationTracks.m_data;
  if ( v8 > 0 )
  {
    v15 = (char *)((char *)that->m_annotationTracks.m_data - (char *)m_data);
    v16 = (unsigned int)v8;
    do
    {
      hkaAnnotationTrack::operator=(m_data, (hkaAnnotationTrack *)((char *)m_data + (_QWORD)v15));
      ++m_data;
      --v16;
    }
    while ( v16 );
  }
  v17 = &this->m_annotationTracks.m_data[v8];
  if ( (int)m_size - v8 > 0 )
  {
    v18 = (char *)((char *)&that->m_annotationTracks.m_data[v8] - (char *)v17);
    v19 = (unsigned int)(m_size - v8);
    do
    {
      if ( v17 )
        hkaAnnotationTrack::hkaAnnotationTrack(v17, (hkaAnnotationTrack *)((char *)v17 + (_QWORD)v18));
      ++v17;
      --v19;
    }
    while ( v19 );
  }
  this->m_annotationTracks.m_size = m_size;
}

// File Line: 24
// RVA: 0xB35CF0
__int64 __fastcall hkaAnimation::getNumAnnotations(hkaAnimation *this, float startTimeR, float deltaTime)
{
  __int64 m_size; // r10
  unsigned int v4; // r8d
  __m128 v5; // xmm0
  __m128 v6; // xmm5
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  hkArray<hkaAnnotationTrack::Annotation,hkContainerHeapAllocator> *p_m_annotations; // r9
  int v11; // eax
  hkaAnnotationTrack::Annotation *m_data; // rcx
  __int64 v13; // rdx
  __m128 v14; // xmm2

  m_size = this->m_annotationTracks.m_size;
  v4 = 0;
  v5 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
  v6 = _mm_shuffle_ps((__m128)LODWORD(startTimeR), (__m128)LODWORD(startTimeR), 0);
  v7 = _mm_add_ps(_mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0), v6);
  v8 = _mm_cmplt_ps(v5, v7);
  v9 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v7, v5), v8), _mm_andnot_ps(v8, (__m128)xmmword_141A712F0));
  if ( m_size > 0 )
  {
    p_m_annotations = &this->m_annotationTracks.m_data->m_annotations;
    do
    {
      v11 = p_m_annotations->m_size;
      if ( v11 > 0 )
      {
        m_data = p_m_annotations->m_data;
        v13 = (unsigned int)v11;
        do
        {
          v14 = _mm_shuffle_ps((__m128)LODWORD(m_data->m_time), (__m128)LODWORD(m_data->m_time), 0);
          if ( _mm_movemask_ps(_mm_or_ps(_mm_and_ps(_mm_cmple_ps(v6, v14), _mm_cmplt_ps(v14, v7)), _mm_cmplt_ps(v14, v9))) )
            ++v4;
          ++m_data;
          --v13;
        }
        while ( v13 );
      }
      p_m_annotations = (hkArray<hkaAnnotationTrack::Annotation,hkContainerHeapAllocator> *)((char *)p_m_annotations + 24);
      --m_size;
    }
    while ( m_size );
  }
  return v4;
}

// File Line: 68
// RVA: 0xB35DB0
__int64 __fastcall hkaAnimation::getAnnotations(
        hkaAnimation *this,
        float startTimeR,
        float deltaTime,
        hkaAnimation::TrackAnnotation *annotations,
        unsigned int maxNumAnnotations)
{
  __m128 v7; // xmm0
  unsigned int v8; // ebp
  unsigned __int16 v9; // r15
  __m128 v10; // xmm8
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  __m128 v13; // xmm7
  int v14; // edx
  hkaAnnotationTrack *m_data; // r13
  int v16; // esi
  __int64 v17; // rdi
  __int64 v18; // rbx
  __m128 m_time_low; // xmm2
  __m128 v20; // xmm1
  __int64 v21; // r8
  hkaAnnotationTrack::Annotation *v22; // rcx
  int m_size; // [rsp+20h] [rbp-78h]
  __int64 v24; // [rsp+28h] [rbp-70h]
  hkaAnimation *v25; // [rsp+A0h] [rbp+8h]

  v25 = this;
  if ( !maxNumAnnotations )
    return 0i64;
  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
  m_size = this->m_annotationTracks.m_size;
  v8 = 0;
  v9 = 0;
  v10 = _mm_shuffle_ps((__m128)LODWORD(startTimeR), (__m128)LODWORD(startTimeR), 0);
  v11 = _mm_add_ps(_mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0), v10);
  v12 = _mm_cmplt_ps(v7, v11);
  v13 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v11, v7), v12), _mm_andnot_ps(v12, (__m128)xmmword_141A712F0));
  if ( m_size > 0 )
  {
    v14 = this->m_annotationTracks.m_size;
    while ( 1 )
    {
      m_data = this->m_annotationTracks.m_data;
      v16 = 0;
      v17 = 0i64;
      v24 = m_data[v9].m_annotations.m_size;
      if ( v24 > 0 )
        break;
LABEL_11:
      if ( ++v9 >= v14 )
        return v8;
    }
    v18 = 0i64;
    while ( 1 )
    {
      m_time_low = (__m128)LODWORD(m_data[v9].m_annotations.m_data[v16].m_time);
      v20 = _mm_shuffle_ps(m_time_low, m_time_low, 0);
      if ( _mm_movemask_ps(_mm_or_ps(_mm_and_ps(_mm_cmplt_ps(v20, v11), _mm_cmple_ps(v10, v20)), _mm_cmplt_ps(v20, v13))) )
      {
        v21 = v8;
        annotations[v21].m_trackID = v9;
        v22 = m_data[v9].m_annotations.m_data;
        annotations[v21].m_annotation.m_time = v22[v18].m_time;
        hkStringPtr::operator=(&annotations[v8++].m_annotation.m_text, &v22[v18].m_text);
        if ( v8 == maxNumAnnotations )
          break;
      }
      ++v17;
      ++v16;
      ++v18;
      if ( v17 >= v24 )
      {
        this = v25;
        v14 = m_size;
        goto LABEL_11;
      }
    }
  }
  return v8;
}

// File Line: 125
// RVA: 0xB35A70
void __fastcall hkaAnimation::samplePartialTracks(
        hkaAnimation *this,
        float time,
        unsigned int maxNumTransformTracks,
        hkQsTransformf *transformTracksOut,
        signed int maxNumFloatTracks,
        float *floatTracksOut)
{
  int m_numberOfTransformTracks; // ebx
  hkLifoAllocator *Value; // rax
  _BYTE *m_cur; // rdi
  int v12; // ebp
  char *v13; // rcx
  int m_numberOfFloatTracks; // ebx
  hkLifoAllocator *v15; // rax
  int v16; // esi
  int *v17; // rbx
  int v18; // esi
  char *v19; // rcx
  unsigned __int64 *v20; // r9
  __int64 v21; // r11
  signed __int64 v22; // r10
  int v23; // edx
  int v24; // r8d
  int v25; // eax
  int *v26; // rcx
  __int64 v27; // rdx
  int v28; // eax
  hkLifoAllocator *v29; // rax
  int v30; // r8d
  hkLifoAllocator *v31; // rax
  int v32; // r8d

  m_numberOfTransformTracks = this->m_numberOfTransformTracks;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = Value->m_cur;
  v12 = (48 * m_numberOfTransformTracks + 127) & 0xFFFFFF80;
  v13 = &m_cur[v12];
  if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v12);
  else
    Value->m_cur = v13;
  m_numberOfFloatTracks = this->m_numberOfFloatTracks;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = 4 * m_numberOfFloatTracks + 127;
  v17 = (int *)v15->m_cur;
  v18 = v16 & 0xFFFFFF80;
  v19 = (char *)v17 + v18;
  if ( v18 > v15->m_slabSize || v19 > v15->m_end )
    v17 = (int *)hkLifoAllocator::allocateFromNewSlab(v15, v18);
  else
    v15->m_cur = v19;
  ((void (__fastcall *)(hkaAnimation *, hkBaseObjectVtbl *, _BYTE *, int *))this->vfptr[1].__first_virtual_table_function__)(
    this,
    this->vfptr,
    m_cur,
    v17);
  if ( (int)(3 * maxNumTransformTracks) > 0 )
  {
    v20 = &transformTracksOut->m_translation.m_quad.m128_u64[1];
    v21 = 3 * maxNumTransformTracks;
    v22 = m_cur - (_BYTE *)transformTracksOut;
    do
    {
      v23 = *(_DWORD *)((char *)v20 + v22);
      v24 = *(_DWORD *)((char *)v20 + v22 + 4);
      v25 = *(_DWORD *)((char *)v20 + v22 - 8);
      *((_DWORD *)v20 - 1) = *(_DWORD *)((char *)v20 + v22 - 4);
      *(_DWORD *)v20 = v23;
      *((_DWORD *)v20 + 1) = v24;
      *((_DWORD *)v20 - 2) = v25;
      v20 += 2;
      --v21;
    }
    while ( v21 );
  }
  v26 = v17;
  if ( maxNumFloatTracks > 0 )
  {
    v27 = (unsigned int)maxNumFloatTracks;
    do
    {
      v28 = *v26++;
      *(int *)((char *)v26 + (char *)floatTracksOut - (char *)v17 - 4) = v28;
      --v27;
    }
    while ( v27 );
  }
  v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (v18 + 15) & 0xFFFFFFF0;
  if ( v18 > v29->m_slabSize || (char *)v17 + v30 != v29->m_cur || v29->m_firstNonLifoEnd == v17 )
    hkLifoAllocator::slowBlockFree(v29, v17, v30);
  else
    v29->m_cur = v17;
  v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v31->m_slabSize || &m_cur[v32] != v31->m_cur || v31->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v31, m_cur, v32);
  else
    v31->m_cur = m_cur;
}

// File Line: 136
// RVA: 0xB35C50
__int64 __fastcall hkaAnimation::getNumDataChunks(hkaAnimation *this, unsigned int frame, float delta)
{
  return 0i64;
}

// File Line: 141
// RVA: 0xB35C60
void __fastcall hkaAnimation::getDataChunks(
        hkaAnimation *this,
        unsigned int frame,
        float delta,
        hkaAnimation::DataChunk *dataChunks)
{
  hkErrStream v4; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v4, buf, 512);
  hkOstream::operator<<(&v4, "getDataChunks not implemented for this type of animation");
  if ( hkError::messageError(1424171300, buf, "Animation\\hkaAnimation.cpp", 144) )
    __debugbreak();
  hkOstream::~hkOstream(&v4);
}

// File Line: 149
// RVA: 0xB35CD0
__int64 __fastcall hkaAnimation::getMaxSizeOfCombinedDataChunks(hkaAnimation *this)
{
  return 0i64;
}

// File Line: 154
// RVA: 0xB35CE0
__int64 __fastcall hkaAnimation::getMaxDecompressionTempBytes(hkaAnimation *this)
{
  return 0i64;
}

// File Line: 159
// RVA: 0xB35FA0
bool __fastcall hkaAnimation::requiresSkeleton(hkaAnimation *this)
{
  return 0;
}

// File Line: 164
// RVA: 0xB35FB0
hkaSkeleton *__fastcall hkaAnimation::getSkeleton(hkaAnimation *this)
{
  return 0i64;
}

// File Line: 169
// RVA: 0xB35FC0
void __fastcall hkaAnimation::setSkeleton(hkaAnimation *this, hkaSkeleton *skeleton)
{
  ;
}

