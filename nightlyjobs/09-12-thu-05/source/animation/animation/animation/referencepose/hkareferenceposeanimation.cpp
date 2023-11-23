// File Line: 18
// RVA: 0xB3B920
void __fastcall hkaReferencePoseAnimation::hkaReferencePoseAnimation(
        hkaReferencePoseAnimation *this,
        hkaSkeleton *skeleton,
        int numTransformTracks,
        int numFloatTracks)
{
  hkaAnimatedReferenceFrame *m_pntr; // rcx
  hkaSkeleton *v9; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaAnimation::`vftable;
  *(_QWORD *)&this->m_type.m_storage = 0i64;
  this->m_extractedMotion.m_pntr = 0i64;
  this->m_annotationTracks.m_data = 0i64;
  this->m_annotationTracks.m_size = 0;
  this->m_annotationTracks.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_numberOfTransformTracks = 0i64;
  m_pntr = this->m_extractedMotion.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_extractedMotion.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkaReferencePoseAnimation::`vftable;
  this->m_skeleton.m_pntr = 0i64;
  this->m_type.m_storage = 6;
  if ( skeleton )
    hkReferencedObject::addReference(skeleton);
  v9 = this->m_skeleton.m_pntr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  this->m_skeleton.m_pntr = skeleton;
  if ( numTransformTracks == -1 )
  {
    this->m_numberOfTransformTracks = skeleton->m_referencePose.m_size;
  }
  else
  {
    if ( skeleton->m_referencePose.m_size < numTransformTracks )
      numTransformTracks = skeleton->m_referencePose.m_size;
    this->m_numberOfTransformTracks = numTransformTracks;
  }
  if ( numFloatTracks == -1 )
  {
    this->m_numberOfFloatTracks = skeleton->m_referenceFloats.m_size;
  }
  else
  {
    if ( skeleton->m_referenceFloats.m_size < numFloatTracks )
      numFloatTracks = skeleton->m_referenceFloats.m_size;
    this->m_numberOfFloatTracks = numFloatTracks;
  }
}

// File Line: 42
// RVA: 0xB3BA10
void __fastcall hkaReferencePoseAnimation::sampleTracks(
        hkaReferencePoseAnimation *this,
        float time,
        hkQsTransformf *transformTracksOut,
        float *floatTracksOut)
{
  ((void (__fastcall *)(hkaReferencePoseAnimation *, hkBaseObjectVtbl *, _QWORD, hkQsTransformf *, int, float *))this->vfptr[2].__vecDelDtor)(
    this,
    this->vfptr,
    (unsigned int)this->m_numberOfTransformTracks,
    transformTracksOut,
    this->m_numberOfFloatTracks,
    floatTracksOut);
}

// File Line: 48
// RVA: 0xB3BA40
void __fastcall hkaReferencePoseAnimation::samplePartialTracks(
        hkaReferencePoseAnimation *this,
        float time,
        int maxNumTransformTracks,
        hkQsTransformf *transformTracksOut,
        int maxNumFloatTracks,
        float *floatTracksOut)
{
  hkaSkeleton *m_pntr; // r8
  const float *m_data; // r9
  hkQsTransformf *v9; // r8
  hkaAnimation::DataChunk dataChunks; // [rsp+40h] [rbp-18h] BYREF

  m_pntr = this->m_skeleton.m_pntr;
  m_data = m_pntr->m_referenceFloats.m_data;
  v9 = m_pntr->m_referencePose.m_data;
  dataChunks.m_data = (const char *)this;
  dataChunks.m_size = 64;
  hkaReferencePoseAnimation::samplePartialWithDataChunks(
    maxNumTransformTracks,
    maxNumFloatTracks,
    v9,
    m_data,
    &dataChunks,
    1,
    transformTracksOut,
    floatTracksOut);
}

// File Line: 57
// RVA: 0xB3BB10
void __fastcall hkaReferencePoseAnimation::sampleIndividualFloatTracks(
        hkaReferencePoseAnimation *this,
        float time,
        const __int16 *tracks,
        int numTracks,
        float *out)
{
  unsigned int v6; // edi
  __int64 v9; // rsi
  const __int16 *v10; // r10
  float *v11; // r11
  unsigned int v12; // eax
  __int64 v13; // r8
  __int16 v14; // cx
  __int16 v15; // cx
  __int16 v16; // cx
  __int16 v17; // cx
  float *v18; // r9
  const __int16 *v19; // r8
  __int64 v20; // r10
  __int16 v21; // cx

  v6 = 0;
  v9 = 0i64;
  if ( numTracks >= 4 )
  {
    v10 = tracks + 2;
    v11 = out + 2;
    v12 = ((unsigned int)(numTracks - 4) >> 2) + 1;
    v13 = v12;
    v6 = 4 * v12;
    v9 = 4i64 * v12;
    do
    {
      v14 = *(v10 - 2);
      if ( v14 >= 0 && v14 < this->m_numberOfFloatTracks )
        *(v11 - 2) = this->m_skeleton.m_pntr->m_referenceFloats.m_data[v14];
      v15 = *(v10 - 1);
      if ( v15 >= 0 && v15 < this->m_numberOfFloatTracks )
        *(v11 - 1) = this->m_skeleton.m_pntr->m_referenceFloats.m_data[v15];
      v16 = *v10;
      if ( *v10 >= 0 && v16 < this->m_numberOfFloatTracks )
        *v11 = this->m_skeleton.m_pntr->m_referenceFloats.m_data[v16];
      v17 = v10[1];
      if ( v17 >= 0 && v17 < this->m_numberOfFloatTracks )
        v11[1] = this->m_skeleton.m_pntr->m_referenceFloats.m_data[v17];
      v10 += 4;
      v11 += 4;
      --v13;
    }
    while ( v13 );
  }
  if ( v6 < numTracks )
  {
    v18 = &out[v9];
    v19 = &tracks[v9];
    v20 = numTracks - v6;
    do
    {
      v21 = *v19;
      if ( *v19 >= 0 && v21 < this->m_numberOfFloatTracks )
        *v18 = this->m_skeleton.m_pntr->m_referenceFloats.m_data[v21];
      ++v19;
      ++v18;
      --v20;
    }
    while ( v20 );
  }
}

// File Line: 73
// RVA: 0xB3BAA0
void __fastcall hkaReferencePoseAnimation::sampleIndividualTransformTracks(
        hkaReferencePoseAnimation *this,
        float time,
        __int16 *tracks,
        __int64 numTracks,
        hkQsTransformf *transformOut)
{
  hkVector4f *p_m_scale; // r10
  __int16 v6; // ax
  hkQsTransformf *v7; // rdx

  if ( (_DWORD)numTracks )
  {
    numTracks = (unsigned int)numTracks;
    p_m_scale = &transformOut->m_scale;
    do
    {
      v6 = *tracks;
      if ( *tracks >= 0 && v6 < this->m_numberOfTransformTracks )
      {
        v7 = &this->m_skeleton.m_pntr->m_referencePose.m_data[v6];
        p_m_scale[-2] = v7->m_translation;
        p_m_scale[-1] = v7->m_rotation.m_vec;
        *p_m_scale = v7->m_scale;
      }
      ++tracks;
      p_m_scale += 3;
      --numTracks;
    }
    while ( numTracks );
  }
}

// File Line: 90
// RVA: 0xB3BC60
__int64 __fastcall hkaReferencePoseAnimation::getNumDataChunks(
        hkaReferencePoseAnimation *this,
        unsigned int frame,
        float delta)
{
  return 1i64;
}

// File Line: 102
// RVA: 0xB3BC70
void __fastcall hkaReferencePoseAnimation::getDataChunks(
        hkaReferencePoseAnimation *this,
        unsigned int frame,
        float delta,
        hkaAnimation::DataChunk *chunks)
{
  chunks->m_data = (const char *)this;
  chunks->m_size = 64;
}

// File Line: 122
// RVA: 0xB3BC90
__int64 __fastcall hkaReferencePoseAnimation::getMaxSizeOfCombinedDataChunks(hkaReferencePoseAnimation *this)
{
  return 64i64;
}

// File Line: 140
// RVA: 0xB3BCA0
void __fastcall hkaReferencePoseAnimation::samplePartialWithDataChunks(
        int maxNumTransformTracks,
        unsigned int maxNumFloatTracks,
        hkQsTransformf *referenceBones,
        const float *referenceFloats,
        hkaAnimation::DataChunk *dataChunks,
        int numDataChunks,
        hkQsTransformf *transformTracksOut,
        float *floatTracksOut)
{
  __int64 v11; // rbp
  _QWORD *Value; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  const char *m_data; // r11
  __int64 v18; // r10
  unsigned __int64 *v19; // r9
  signed __int64 v20; // rdi
  int v21; // edx
  int v22; // r8d
  int v23; // eax
  __int64 v24; // rcx
  signed __int64 v25; // rdx
  int v26; // eax
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  _QWORD *v30; // rcx

  v11 = maxNumFloatTracks;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)Value[1];
  v14 = Value;
  if ( (unsigned __int64)v13 < Value[3] )
  {
    *v13 = "TtSampleRefPoseChunk";
    v15 = __rdtsc();
    v16 = v13 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v14[1] = v16;
  }
  m_data = dataChunks->m_data;
  if ( *((int *)dataChunks->m_data + 6) > 0 && 3 * maxNumTransformTracks > 0 )
  {
    v18 = (unsigned int)(3 * maxNumTransformTracks);
    v19 = &transformTracksOut->m_translation.m_quad.m128_u64[1];
    v20 = (char *)referenceBones - (char *)transformTracksOut;
    do
    {
      v21 = *(_DWORD *)((char *)v19 + v20);
      v22 = *(_DWORD *)((char *)v19 + v20 + 4);
      v23 = *(_DWORD *)((char *)v19 + v20 - 8);
      *((_DWORD *)v19 - 1) = *(_DWORD *)((char *)v19 + v20 - 4);
      *(_DWORD *)v19 = v21;
      *((_DWORD *)v19 + 1) = v22;
      *((_DWORD *)v19 - 2) = v23;
      v19 += 2;
      --v18;
    }
    while ( v18 );
  }
  if ( *((int *)m_data + 7) > 0 && (int)v11 > 0 )
  {
    v24 = v11;
    v25 = (char *)floatTracksOut - (char *)referenceFloats;
    do
    {
      v26 = *(_DWORD *)referenceFloats++;
      *(_DWORD *)((char *)referenceFloats + v25 - 4) = v26;
      --v24;
    }
    while ( v24 );
  }
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v29 = __rdtsc();
    v30 = v28 + 2;
    *((_DWORD *)v30 - 2) = v29;
    v27[1] = v30;
  }
}

