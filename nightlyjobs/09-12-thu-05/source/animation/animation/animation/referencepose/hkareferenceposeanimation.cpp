// File Line: 18
// RVA: 0xB3B920
void __fastcall hkaReferencePoseAnimation::hkaReferencePoseAnimation(hkaReferencePoseAnimation *this, hkaSkeleton *skeleton, int numTransformTracks, int numFloatTracks)
{
  hkaReferencePoseAnimation *v4; // rbx
  hkaAnimatedReferenceFrame *v5; // rcx
  int v6; // esi
  int v7; // ebp
  hkaSkeleton *v8; // rdi
  hkReferencedObject *v9; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaAnimation::`vftable;
  *(_QWORD *)&this->m_type.m_storage = 0i64;
  this->m_extractedMotion.m_pntr = 0i64;
  this->m_annotationTracks.m_data = 0i64;
  this->m_annotationTracks.m_size = 0;
  this->m_annotationTracks.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&this->m_numberOfTransformTracks = 0i64;
  v4 = this;
  v5 = this->m_extractedMotion.m_pntr;
  v6 = numFloatTracks;
  v7 = numTransformTracks;
  v8 = skeleton;
  if ( v5 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
  v4->m_extractedMotion.m_pntr = 0i64;
  v4->vfptr = (hkBaseObjectVtbl *)&hkaReferencePoseAnimation::`vftable;
  v4->m_skeleton.m_pntr = 0i64;
  v4->m_type.m_storage = 6;
  if ( v8 )
    hkReferencedObject::addReference((hkReferencedObject *)&v8->vfptr);
  v9 = (hkReferencedObject *)&v4->m_skeleton.m_pntr->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v4->m_skeleton.m_pntr = v8;
  if ( v7 == -1 )
  {
    v4->m_numberOfTransformTracks = v8->m_referencePose.m_size;
  }
  else
  {
    if ( v8->m_referencePose.m_size < v7 )
      v7 = v8->m_referencePose.m_size;
    v4->m_numberOfTransformTracks = v7;
  }
  if ( v6 == -1 )
  {
    v4->m_numberOfFloatTracks = v8->m_referenceFloats.m_size;
  }
  else
  {
    if ( v8->m_referenceFloats.m_size < v6 )
      v6 = v8->m_referenceFloats.m_size;
    v4->m_numberOfFloatTracks = v6;
  }
}

// File Line: 42
// RVA: 0xB3BA10
void __fastcall hkaReferencePoseAnimation::sampleTracks(hkaReferencePoseAnimation *this, float time, hkQsTransformf *transformTracksOut, float *floatTracksOut)
{
  int v4; // ST20_4

  v4 = this->m_numberOfFloatTracks;
  ((void (__fastcall *)(hkaReferencePoseAnimation *, hkBaseObjectVtbl *, _QWORD, hkQsTransformf *, int, float *))this->vfptr[2].__vecDelDtor)(
    this,
    this->vfptr,
    (unsigned int)this->m_numberOfTransformTracks,
    transformTracksOut,
    v4,
    floatTracksOut);
}

// File Line: 48
// RVA: 0xB3BA40
void __fastcall hkaReferencePoseAnimation::samplePartialTracks(hkaReferencePoseAnimation *this, float time, unsigned int maxNumTransformTracks, hkQsTransformf *transformTracksOut, unsigned int maxNumFloatTracks, float *floatTracksOut)
{
  int v6; // er10
  hkaSkeleton *v7; // r8
  hkQsTransformf *v8; // ST30_8
  const float *v9; // r9
  hkQsTransformf *v10; // r8
  hkaAnimation::DataChunk dataChunks; // [rsp+40h] [rbp-18h]

  v6 = maxNumTransformTracks;
  v7 = this->m_skeleton.m_pntr;
  v8 = transformTracksOut;
  v9 = v7->m_referenceFloats.m_data;
  v10 = v7->m_referencePose.m_data;
  dataChunks.m_data = (const char *)this;
  dataChunks.m_size = 64;
  hkaReferencePoseAnimation::samplePartialWithDataChunks(
    v6,
    maxNumFloatTracks,
    v10,
    v9,
    &dataChunks,
    1,
    v8,
    floatTracksOut);
}

// File Line: 57
// RVA: 0xB3BB10
void __fastcall hkaReferencePoseAnimation::sampleIndividualFloatTracks(hkaReferencePoseAnimation *this, float time, const __int16 *tracks, unsigned int numTracks, float *out)
{
  unsigned int v5; // ebx
  unsigned int v6; // edi
  const __int16 *v7; // r14
  hkaReferencePoseAnimation *v8; // rdx
  signed __int64 v9; // rsi
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

  v5 = numTracks;
  v6 = 0;
  v7 = tracks;
  v8 = this;
  v9 = 0i64;
  if ( (signed int)numTracks >= 4 )
  {
    v10 = tracks + 2;
    v11 = out + 2;
    v12 = ((numTracks - 4) >> 2) + 1;
    v13 = v12;
    v6 = 4 * v12;
    v9 = 4i64 * v12;
    do
    {
      v14 = *(v10 - 2);
      if ( v14 >= 0 && v14 < v8->m_numberOfFloatTracks )
        *(v11 - 2) = v8->m_skeleton.m_pntr->m_referenceFloats.m_data[v14];
      v15 = *(v10 - 1);
      if ( v15 >= 0 && v15 < v8->m_numberOfFloatTracks )
        *(v11 - 1) = v8->m_skeleton.m_pntr->m_referenceFloats.m_data[v15];
      v16 = *v10;
      if ( *v10 >= 0 && v16 < v8->m_numberOfFloatTracks )
        *v11 = v8->m_skeleton.m_pntr->m_referenceFloats.m_data[v16];
      v17 = v10[1];
      if ( v17 >= 0 && v17 < v8->m_numberOfFloatTracks )
        v11[1] = v8->m_skeleton.m_pntr->m_referenceFloats.m_data[v17];
      v10 += 4;
      v11 += 4;
      --v13;
    }
    while ( v13 );
  }
  if ( v6 < numTracks )
  {
    v18 = &out[v9];
    v19 = &v7[v9];
    v20 = v5 - v6;
    do
    {
      v21 = *v19;
      if ( *v19 >= 0 && v21 < v8->m_numberOfFloatTracks )
        *v18 = v8->m_skeleton.m_pntr->m_referenceFloats.m_data[v21];
      ++v19;
      ++v18;
      --v20;
    }
    while ( v20 );
  }
}

// File Line: 73
// RVA: 0xB3BAA0
void __fastcall hkaReferencePoseAnimation::sampleIndividualTransformTracks(hkaReferencePoseAnimation *this, float time, const __int16 *tracks, __int64 numTracks, hkQsTransformf *transformOut)
{
  hkVector4f *v5; // r10
  __int16 v6; // ax
  hkQsTransformf *v7; // rdx

  if ( (_DWORD)numTracks )
  {
    numTracks = (unsigned int)numTracks;
    v5 = &transformOut->m_scale;
    do
    {
      v6 = *tracks;
      if ( *tracks >= 0 && v6 < this->m_numberOfTransformTracks )
      {
        v7 = &this->m_skeleton.m_pntr->m_referencePose.m_data[v6];
        v5[-2] = v7->m_translation;
        v5[-1] = v7->m_rotation.m_vec;
        *v5 = v7->m_scale;
      }
      ++tracks;
      v5 += 3;
      --numTracks;
    }
    while ( numTracks );
  }
}

// File Line: 90
// RVA: 0xB3BC60
signed __int64 __fastcall hkaReferencePoseAnimation::getNumDataChunks(hkaReferencePoseAnimation *this, unsigned int frame, float delta)
{
  return 1i64;
}

// File Line: 102
// RVA: 0xB3BC70
void __fastcall hkaReferencePoseAnimation::getDataChunks(hkaReferencePoseAnimation *this, unsigned int frame, float delta, hkaAnimation::DataChunk *chunks)
{
  chunks->m_data = (const char *)this;
  chunks->m_size = 64;
}

// File Line: 122
// RVA: 0xB3BC90
signed __int64 __fastcall hkaReferencePoseAnimation::getMaxSizeOfCombinedDataChunks(hkaReferencePoseAnimation *this)
{
  return 64i64;
}

// File Line: 140
// RVA: 0xB3BCA0
void __fastcall hkaReferencePoseAnimation::samplePartialWithDataChunks(int maxNumTransformTracks, int maxNumFloatTracks, hkQsTransformf *referenceBones, const float *referenceFloats, hkaAnimation::DataChunk *dataChunks, int numDataChunks, hkQsTransformf *transformTracksOut, float *floatTracksOut)
{
  int v8; // esi
  const float *v9; // rbx
  hkQsTransformf *v10; // rdi
  __int64 v11; // rbp
  _QWORD *v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  const char *v17; // r11
  __int64 v18; // r10
  int *v19; // r9
  signed __int64 v20; // rdi
  int v21; // edx
  int v22; // er8
  int v23; // eax
  __int64 v24; // rcx
  char *v25; // rdx
  int v26; // eax
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  signed __int64 v30; // rcx

  v8 = maxNumTransformTracks;
  v9 = referenceFloats;
  v10 = referenceBones;
  v11 = (unsigned int)maxNumFloatTracks;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  v14 = v12;
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "TtSampleRefPoseChunk";
    v15 = __rdtsc();
    v16 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v14[1] = v16;
  }
  v17 = dataChunks->m_data;
  if ( *((_DWORD *)dataChunks->m_data + 6) > 0 && 3 * v8 > 0 )
  {
    v18 = (unsigned int)(3 * v8);
    v19 = &transformTracksOut->m_translation.m_quad.m128_i32[2];
    v20 = (char *)v10 - (char *)transformTracksOut;
    do
    {
      v21 = *(int *)((char *)v19 + v20);
      v22 = *(int *)((char *)v19 + v20 + 4);
      v23 = *(int *)((char *)v19 + v20 - 8);
      *(v19 - 1) = *(int *)((char *)v19 + v20 - 4);
      *v19 = v21;
      v19[1] = v22;
      *(v19 - 2) = v23;
      v19 += 4;
      --v18;
    }
    while ( v18 );
  }
  if ( *((_DWORD *)v17 + 7) > 0 && (signed int)v11 > 0 )
  {
    v24 = v11;
    v25 = (char *)((char *)floatTracksOut - (char *)v9);
    do
    {
      v26 = *(_DWORD *)v9;
      ++v9;
      *(_DWORD *)((char *)v9 + (_QWORD)v25 - 4) = v26;
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
    v30 = (signed __int64)(v28 + 2);
    *(_DWORD *)(v30 - 8) = v29;
    v27[1] = v30;
  }
}

