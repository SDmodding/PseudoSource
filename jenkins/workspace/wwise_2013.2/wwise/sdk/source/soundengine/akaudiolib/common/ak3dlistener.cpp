// File Line: 42
// RVA: 0x15BE040
hkSeekableStreamReader *dynamic_initializer_for__CAkListener::m_listeners__()
{
  hkSeekableStreamReader *v0; // rbx
  signed int v1; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &CAkListener::m_listeners;
  v1 = 7;
  do
  {
    result = Assembly::GetRCX(v0);
    v0 += 9;
    --v1;
  }
  while ( v1 >= 0 );
  return result;
}

// File Line: 56
// RVA: 0xA69BC0
void CAkListener::Init(void)
{
  unsigned int v0; // edi
  char *v1; // rbx
  __m128 v2; // xmm6
  AkVector *v3; // rax
  float v4; // ST28_4
  AkVector result; // [rsp+30h] [rbp-28h]

  v0 = 0;
  v1 = (char *)&unk_14249EFFC;
  v2 = _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0);
  do
  {
    *(__m128 *)(v1 - 60) = v2;
    *(__m128 *)(v1 - 44) = v2;
    *(v1 - 68) = 1;
    *((_DWORD *)v1 - 18) = 1065353216;
    *(_QWORD *)(v1 + 12) = 0i64;
    v1[20] = 1;
    if ( v0 < 8 )
    {
      *((_DWORD *)v1 - 27) = LODWORD(g_DefaultListenerPosition.OrientationFront.X);
      *((_DWORD *)v1 - 26) = unk_1420F711C;
      *((_DWORD *)v1 - 25) = unk_1420F7120;
      *((_DWORD *)v1 - 24) = LODWORD(Vector1.X);
      *((_DWORD *)v1 - 23) = LODWORD(Vector1.Y);
      *((_DWORD *)v1 - 22) = LODWORD(Vector1.Z);
      *((_DWORD *)v1 - 21) = unk_1420F7130;
      *((_DWORD *)v1 - 20) = unk_1420F7134;
      *((_DWORD *)v1 - 19) = unk_1420F7138;
      v3 = AkMath::CrossProduct(&result, &Vector1, &g_DefaultListenerPosition.OrientationFront);
      v4 = v3->Z;
      *(_QWORD *)(v1 - 28) = *(_QWORD *)&v3->X;
      *((float *)v1 - 5) = v4;
      *((_DWORD *)v1 - 4) = *((_DWORD *)v1 - 24);
      *((_DWORD *)v1 - 3) = *((_DWORD *)v1 - 23);
      *((_DWORD *)v1 - 2) = *((_DWORD *)v1 - 22);
      *((_DWORD *)v1 - 1) = *((_DWORD *)v1 - 27);
      *(_DWORD *)v1 = *((_DWORD *)v1 - 26);
      *((_DWORD *)v1 + 1) = *((_DWORD *)v1 - 25);
      v1[20] = 1;
    }
    ++v0;
    v1 += 144;
  }
  while ( v0 < 8 );
  CAkListener::m_uFeedbackMask = 0;
  CAkListener::m_uAudioMask = -1;
}

// File Line: 79
// RVA: 0xA69EE0
void __fastcall CAkListener::RouteListenersToDevice(unsigned int in_uListenerMask, unsigned __int64 in_uDeviceID)
{
  __int64 i; // r8

  for ( i = 0i64; in_uListenerMask; in_uListenerMask >>= 1 )
  {
    if ( in_uListenerMask & 1 )
      *((_QWORD *)&unk_14249F008 + 18 * i) = in_uDeviceID;
    i = (unsigned int)(i + 1);
  }
}

// File Line: 92
// RVA: 0xA69D10
void CAkListener::OnBeginFrame(void)
{
  unsigned int v0; // edx

  v0 = 0;
  if ( unk_14249F010 )
    v0 = 1;
  if ( unk_14249F0A0 )
    v0 |= 2u;
  if ( unk_14249F130 )
    v0 |= 4u;
  if ( unk_14249F1C0 )
    v0 |= 8u;
  if ( unk_14249F250 )
    v0 |= 0x10u;
  if ( unk_14249F2E0 )
    v0 |= 0x20u;
  if ( unk_14249F370 )
    v0 |= 0x40u;
  if ( unk_14249F400 )
    v0 |= 0x80u;
  if ( v0 )
    CAkRegistryMgr::NotifyListenerPosChanged(g_pRegistryMgr, v0);
  unk_14249F010 = 0;
  unk_14249F0A0 = 0;
  unk_14249F130 = 0;
  unk_14249F1C0 = 0;
  unk_14249F250 = 0;
  unk_14249F2E0 = 0;
  unk_14249F370 = 0;
  unk_14249F400 = 0;
}

// File Line: 115
// RVA: 0xA69DD0
void CAkListener::ResetListenerData(void)
{
  unsigned int v0; // esi
  AkVector *v1; // r14
  AkVector *v2; // rax
  float v3; // ST28_4
  AkVector result; // [rsp+30h] [rbp-18h]

  v0 = 0;
  v1 = (AkVector *)&unk_14249EFFC;
  do
  {
    v1[-9].X = v1[-9].X;
    v1[-9].Y = v1[-9].Y;
    v1[-9].Z = v1[-9].Z;
    v1[-8].X = v1[-8].X;
    v1[-8].Y = v1[-8].Y;
    v1[-8].Z = v1[-8].Z;
    v1[-7].X = v1[-7].X;
    v1[-7].Y = v1[-7].Y;
    v1[-7].Z = v1[-7].Z;
    v2 = AkMath::CrossProduct(&result, v1 - 8, v1 - 9);
    v3 = v2->Z;
    *(_QWORD *)&v1[-3].Z = *(_QWORD *)&v2->X;
    v1[-2].Y = v3;
    v1[-2].Z = v1[-8].X;
    v1[-1].X = v1[-8].Y;
    v1[-1].Y = v1[-8].Z;
    v1[-1].Z = v1[-9].X;
    v1->X = v1[-9].Y;
    v1->Y = v1[-9].Z;
    LOBYTE(v1[1].Z) = 1;
    ++v0;
    v1 += 12;
  }
  while ( v0 < 8 );
}

// File Line: 125
// RVA: 0xA69F60
signed __int64 __fastcall CAkListener::SetListenerPosition(unsigned int in_uListener, AkListenerPosition *in_Position)
{
  AkListenerPosition *v2; // r8
  AkVector *v4; // rdx
  hkSeekableStreamReader *v5; // rbx
  AkVector *v6; // rax
  float v7; // ST28_4
  AkVector result; // [rsp+30h] [rbp-18h]

  v2 = in_Position;
  if ( in_uListener >= 8 )
    return 31i64;
  v4 = &in_Position->OrientationTop;
  v5 = &CAkListener::m_listeners + 9 * in_uListener;
  *(float *)&v5->vfptr = v4[-1].X;
  HIDWORD(v5->vfptr) = LODWORD(v4[-1].Y);
  *(float *)&v5->m_memSizeAndFlags = v4[-1].Z;
  *(float *)(&v5->m_referenceCount + 1) = v4->X;
  *(float *)&v5[1].vfptr = v4->Y;
  HIDWORD(v5[1].vfptr) = LODWORD(v4->Z);
  *(float *)&v5[1].m_memSizeAndFlags = v4[1].X;
  *(float *)(&v5[1].m_referenceCount + 1) = v4[1].Y;
  *(float *)&v5[2].vfptr = v4[1].Z;
  v6 = AkMath::CrossProduct(&result, v4, &v2->OrientationFront);
  v7 = v6->Z;
  v5[5].vfptr = *(hkBaseObjectVtbl **)&v6->X;
  *(float *)&v5[5].m_memSizeAndFlags = v7;
  *(_DWORD *)(&v5[5].m_referenceCount + 1) = *(_DWORD *)(&v5->m_referenceCount + 1);
  LODWORD(v5[6].vfptr) = v5[1].vfptr;
  HIDWORD(v5[6].vfptr) = HIDWORD(v5[1].vfptr);
  *(_DWORD *)&v5[6].m_memSizeAndFlags = v5->vfptr;
  *(_DWORD *)(&v5[6].m_referenceCount + 1) = HIDWORD(v5->vfptr);
  LODWORD(v5[7].vfptr) = *(_DWORD *)&v5->m_memSizeAndFlags;
  LOBYTE(v5[8].vfptr) = 1;
  return 1i64;
}

// File Line: 159
// RVA: 0xA6A5C0
void __fastcall CAkListener::SetScalingFactor(unsigned int in_uListener, float in_fScalingFactor)
{
  signed __int64 v2; // rcx

  v2 = 18i64 * in_uListener;
  *((float *)&CAkListener::m_listeners + 2 * v2 + 9) = in_fScalingFactor;
  *((_BYTE *)&CAkListener::m_listeners + 8 * v2 + 128) = 1;
}

// File Line: 167
// RVA: 0xA6A040
signed __int64 __fastcall CAkListener::SetListenerSpatialization(unsigned int in_uListener, bool in_bSpatialized, AkSpeakerVolumes *in_pVolumeOffsets)
{
  signed __int64 result; // rax
  int v4; // edx
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  __m128 v29; // xmm0

  if ( in_uListener >= 8 )
    return 31i64;
  *((_BYTE *)&CAkListener::m_listeners + 144 * in_uListener + 40) = in_bSpatialized;
  if ( in_pVolumeOffsets )
  {
    v4 = `AkMath::FastPow10::`4::`local static guard;
    *((_DWORD *)&CAkListener::m_listeners + 36 * in_uListener + 12) = LODWORD(in_pVolumeOffsets->fFrontLeft);
    v5 = 0.0;
    *((_DWORD *)&CAkListener::m_listeners + 36 * in_uListener + 13) = LODWORD(in_pVolumeOffsets->fFrontRight);
    *((_DWORD *)&CAkListener::m_listeners + 36 * in_uListener + 14) = LODWORD(in_pVolumeOffsets->fCenter);
    *((_DWORD *)&CAkListener::m_listeners + 36 * in_uListener + 15) = LODWORD(in_pVolumeOffsets->fRearLeft);
    *((_DWORD *)&CAkListener::m_listeners + 36 * in_uListener + 16) = LODWORD(in_pVolumeOffsets->fRearRight);
    *((_DWORD *)&CAkListener::m_listeners + 36 * in_uListener + 17) = LODWORD(in_pVolumeOffsets->fSideLeft);
    *((_DWORD *)&CAkListener::m_listeners + 36 * in_uListener + 18) = LODWORD(in_pVolumeOffsets->fSideRight);
    *((_DWORD *)&CAkListener::m_listeners + 36 * in_uListener + 19) = LODWORD(in_pVolumeOffsets->fLfe);
    v6 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 12) * 0.050000001;
    if ( v6 >= -37.0 )
    {
      if ( v4 & 1 )
      {
        v7 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      }
      else
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v8 = (float)((float)((float)((float)(COERCE_FLOAT(
                                             ((signed int)(float)((float)(v7 * v6) + 1065353200.0) & 0x7FFFFF)
                                           + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((signed int)(float)((float)(v7 * v6) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((signed int)(float)((float)(v7 * v6) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v7 = *(float *)&`AkMath::FastPow10::`4::SCALE;
      v8 = 0.0;
    }
    v9 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 13);
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 12) = v8;
    v10 = v9 * 0.050000001;
    if ( v10 >= -37.0 )
    {
      if ( !(v4 & 1) )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v11 = (float)((float)((float)((float)(COERCE_FLOAT(
                                              ((signed int)(float)((float)(v7 * v10) + 1065353200.0) & 0x7FFFFF)
                                            + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((signed int)(float)((float)(v7 * v10) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((signed int)(float)((float)(v7 * v10) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v11 = 0.0;
    }
    v12 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 14);
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 13) = v11;
    v13 = v12 * 0.050000001;
    if ( v13 >= -37.0 )
    {
      if ( !(v4 & 1) )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v14 = (float)((float)((float)((float)(COERCE_FLOAT(
                                              ((signed int)(float)((float)(v7 * v13) + 1065353200.0) & 0x7FFFFF)
                                            + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((signed int)(float)((float)(v7 * v13) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((signed int)(float)((float)(v7 * v13) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v14 = 0.0;
    }
    v15 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 19);
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 14) = v14;
    v16 = v15 * 0.050000001;
    if ( v16 >= -37.0 )
    {
      if ( !(v4 & 1) )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v17 = (float)((float)((float)((float)(COERCE_FLOAT(
                                              ((signed int)(float)((float)(v16 * v7) + 1065353200.0) & 0x7FFFFF)
                                            + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((signed int)(float)((float)(v16 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((signed int)(float)((float)(v16 * v7) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v17 = 0.0;
    }
    v18 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 15);
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 19) = v17;
    v19 = v18 * 0.050000001;
    if ( v19 >= -37.0 )
    {
      if ( !(v4 & 1) )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v20 = (float)((float)((float)((float)(COERCE_FLOAT(
                                              ((signed int)(float)((float)(v19 * v7) + 1065353200.0) & 0x7FFFFF)
                                            + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((signed int)(float)((float)(v19 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((signed int)(float)((float)(v19 * v7) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v20 = 0.0;
    }
    v21 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 16);
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 15) = v20;
    v22 = v21 * 0.050000001;
    if ( v22 >= -37.0 )
    {
      if ( !(v4 & 1) )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v23 = (float)((float)((float)((float)(COERCE_FLOAT(
                                              ((signed int)(float)((float)(v22 * v7) + 1065353200.0) & 0x7FFFFF)
                                            + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((signed int)(float)((float)(v22 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((signed int)(float)((float)(v22 * v7) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v23 = 0.0;
    }
    v24 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 17);
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 16) = v23;
    v25 = v24 * 0.050000001;
    if ( v25 >= -37.0 )
    {
      if ( !(v4 & 1) )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v26 = (float)((float)((float)((float)(COERCE_FLOAT(
                                              ((signed int)(float)((float)(v25 * v7) + 1065353200.0) & 0x7FFFFF)
                                            + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((signed int)(float)((float)(v25 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((signed int)(float)((float)(v25 * v7) + 1065353200.0) & 0xFF800000);
    }
    else
    {
      v26 = 0.0;
    }
    v27 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 18);
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 17) = v26;
    v28 = v27 * 0.050000001;
    if ( v28 >= -37.0 )
    {
      if ( !(v4 & 1) )
      {
        v7 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::`local static guard = v4 | 1;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v5 = (float)((float)((float)((float)(COERCE_FLOAT(
                                             ((signed int)(float)((float)(v28 * v7) + 1065353200.0) & 0x7FFFFF)
                                           + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((signed int)(float)((float)(v28 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((signed int)(float)((float)(v28 * v7) + 1065353200.0) & 0xFF800000);
    }
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 18) = v5;
    result = 1i64;
  }
  else
  {
    result = 1i64;
    v29 = _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0);
    *(&CAkListener::m_listeners + 9 * in_uListener + 3) = (hkSeekableStreamReader)v29;
    *(&CAkListener::m_listeners + 9 * in_uListener + 4) = (hkSeekableStreamReader)v29;
  }
  return result;
}

// File Line: 206
// RVA: 0xA69F10
void __fastcall CAkListener::SetListenerPipeline(unsigned int in_uListener, bool in_bAudio, bool in_bFeedback)
{
  signed int v3; // er9
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax

  v3 = 1 << in_uListener;
  v4 = ~(1 << in_uListener);
  v5 = v4 & CAkListener::m_uAudioMask;
  CAkListener::m_uAudioMask &= v4;
  if ( in_bAudio )
    CAkListener::m_uAudioMask = v3 | v5;
  v6 = v4 & CAkListener::m_uFeedbackMask;
  CAkListener::m_uFeedbackMask &= v4;
  if ( in_bFeedback )
    CAkListener::m_uFeedbackMask = v3 | v6;
}

// File Line: 224
// RVA: 0xA69630
void __usercall CAkListener::Get3DVolumes(AkPositionSourceType in_ePosType@<ecx>, bool in_bIsAuxRoutable@<dl>, CAkPBI *in_pContext@<r8>, AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *io_arVolumeData@<r9>, __int128 a5@<xmm0>)
{
  AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v5; // rsi
  CAkPBI *v6; // r14
  AkPositionSourceType v7; // edi
  float v8; // xmm8_4
  float v9; // xmm0_4
  float v10; // xmm7_4
  float v11; // xmm1_4
  signed int v12; // ecx
  CAkGen3DParams *v13; // rbx
  float v14; // xmm12_4
  CAkAttenuation *v15; // r15
  AkRayVolumeData *v16; // rbx
  unsigned __int8 v17; // al
  unsigned __int8 i; // cl
  __int64 v19; // rdi
  __int64 v20; // rbp
  signed int v21; // ecx
  CAkEnvironmentsMgr *v22; // rdi
  __int128 v23; // xmm6
  float v24; // xmm0_4
  float v25; // xmm0_4
  unsigned int out_index; // [rsp+40h] [rbp-A8h]
  float out_fListenerVolumeGameDefAux; // [rsp+F0h] [rbp+8h]
  float out_fListenerVolumeDry; // [rsp+F8h] [rbp+10h]
  float out_fListenerVolumeUserDefAux; // [rsp+100h] [rbp+18h]

  v5 = io_arVolumeData;
  v6 = in_pContext;
  v7 = in_ePosType;
  if ( in_bIsAuxRoutable )
    v8 = in_pContext->m_pGameObj->m_fDryLevelValue;
  else
    v8 = *(float *)&FLOAT_1_0;
  v9 = CAkPBI::GetOutputBusVolumeValuedB(in_pContext) * 0.050000001;
  if ( v9 >= -37.0 )
  {
    if ( `AkMath::FastPow10::`4::`local static guard & 1 )
    {
      v11 = *(float *)&`AkMath::FastPow10::`4::SCALE;
    }
    else
    {
      v11 = FLOAT_2_7866352e7;
      `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      `AkMath::FastPow10::`4::`local static guard |= 1u;
    }
    v12 = (signed int)(float)((float)(v9 * v11) + 1065353200.0);
    LODWORD(out_fListenerVolumeDry) = (v12 & 0x7FFFFF) + 1065353216;
    LODWORD(out_fListenerVolumeGameDefAux) = v12 & 0xFF800000;
    a5 = LODWORD(out_fListenerVolumeDry);
    v10 = (float)((float)((float)((float)(out_fListenerVolumeDry * 0.32518977) + 0.020805772) * out_fListenerVolumeDry)
                + 0.65304345)
        * COERCE_FLOAT(v12 & 0xFF800000);
  }
  else
  {
    v10 = 0.0;
  }
  v13 = v6->m_p3DSound;
  v14 = v13->m_Params.m_fConeOutsideVolume;
  if ( !v13->m_Params.m_pAttenuation )
    v13->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                       (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                       v13->m_Params.m_uAttenuationID);
  v15 = v13->m_Params.m_pAttenuation;
  v16 = v5->m_pItems;
  if ( v7 == 1 )
  {
    do
    {
      v17 = v16->m_uListenerMask;
      for ( i = 0; !(v17 & 1); ++i )
        v17 >>= 1;
      v19 = i;
      CAkListener::GetListenerVolume(
        v15,
        (AkEmitterListenerPair *)&v16->0,
        v14,
        &v16->fConeInterp,
        &out_fListenerVolumeDry,
        &out_fListenerVolumeGameDefAux,
        &out_fListenerVolumeUserDefAux);
      v20 = (unsigned int)v19;
      v21 = (unsigned __int8)v6->m_pGameObj->m_fOcclusionValue[v19].m_ByteValue;
      v22 = g_pEnvironmentMgr;
      if ( g_pEnvironmentMgr->m_bCurveEnabled[1][0] && g_pEnvironmentMgr->ConversionTable[1][0].m_pArrayGraphPoints )
      {
        *(float *)&a5 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                          g_pEnvironmentMgr->ConversionTable[1],
                          (float)((float)v21 * 0.0039215689) * 100.0,
                          0,
                          &out_index);
        v23 = a5;
      }
      else
      {
        v23 = (unsigned int)FLOAT_1_0;
      }
      if ( v22->m_bCurveEnabled[0][0] && v22->ConversionTable[0][0].m_pArrayGraphPoints )
        v24 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)v22->ConversionTable,
                (float)((float)(unsigned __int8)v6->m_pGameObj->m_fObstructionValue[v20].m_ByteValue * 0.0039215689)
              * 100.0,
                0,
                &out_index)
            * *(float *)&v23;
      else
        v24 = *(float *)&v23;
      ++v16;
      v16[-1].fDryMixGain = (float)((float)(v24 * out_fListenerVolumeDry) * v8) * v10;
      a5 = v23;
      *(float *)&a5 = *(float *)&v23 * out_fListenerVolumeGameDefAux;
      v16[-1].fUserDefAuxMixGain = *(float *)&v23 * out_fListenerVolumeUserDefAux;
      LODWORD(v16[-1].fGameDefAuxMixGain) = a5;
    }
    while ( v16 != &v5->m_pItems[v5->m_uLength] );
  }
  else
  {
    do
    {
      CAkListener::GetListenerVolume(
        v15,
        (AkEmitterListenerPair *)&v16->0,
        v14,
        &v16->fConeInterp,
        &out_fListenerVolumeDry,
        &out_fListenerVolumeGameDefAux,
        &out_fListenerVolumeUserDefAux);
      ++v16;
      v25 = out_fListenerVolumeDry;
      v16[-1].fUserDefAuxMixGain = out_fListenerVolumeUserDefAux;
      v16[-1].fDryMixGain = (float)(v25 * v8) * v10;
      v16[-1].fGameDefAuxMixGain = out_fListenerVolumeGameDefAux;
    }
    while ( v16 != &v5->m_pItems[v5->m_uLength] );
  }
}

// File Line: 300
// RVA: 0xA68140
void __fastcall CAkListener::ComputeSpeakerMatrix(bool in_bIsAuxRoutable, CAkPBI *in_pContext, AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_arVolumeData, unsigned int in_uInputConfig, float in_fBehavioralVolume, CAkOutputDevices *in_deviceVolumes)
{
  unsigned int v6; // esi
  AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v7; // r15
  unsigned int v8; // er10
  int v9; // er8
  __int64 v10; // rbx
  unsigned int v11; // eax
  float v12; // xmm10_4
  size_t v13; // r8
  signed __int64 v14; // rax
  void *v15; // rsp
  bool *v16; // r14
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rax
  void *v19; // rsp
  signed __int64 v20; // rax
  void *v21; // rsp
  signed __int64 v22; // rax
  signed __int64 v23; // rax
  void *v24; // rsp
  CAkPBI *v25; // r10
  void *v26; // rsp
  bool *v27; // r13
  signed __int64 v28; // rbx
  CAkIndexable *v29; // rax
  __int64 v30; // rdx
  unsigned __int8 v31; // al
  unsigned __int8 v32; // al
  unsigned int v33; // ebx
  int v34; // ebx
  bool v35; // zf
  AkFeedbackParams *v36; // rdi
  float v37; // xmm9_4
  AkRayVolumeData *v38; // rbx
  unsigned int v39; // er8
  __int64 v40; // r12
  unsigned __int8 v41; // cl
  unsigned __int8 v42; // al
  float j; // xmm7_4
  __int64 v44; // r15
  CAkRegisteredObj *v45; // rcx
  signed __int64 v46; // rsi
  __m128 *v47; // r13
  signed int v48; // eax
  unsigned int v49; // ecx
  unsigned __int64 *v50; // rax
  AkDevice *v51; // r14
  AkDeviceInfo *v52; // rdi
  float v53; // xmm0_4
  float v54; // xmm6_4
  unsigned int in_uOutputConfig; // eax
  AkDevice *in_pDevice; // ST30_8
  unsigned int v57; // er14
  unsigned int v58; // eax
  float v59; // xmm0_4
  __int64 v60; // rdi
  unsigned __int8 v61; // r8
  char v62; // cl
  unsigned __int8 v63; // al
  float v64; // xmm0_4
  int v65; // er8
  bool *v66; // r15
  unsigned int v67; // edx
  __int64 v68; // rcx
  unsigned int v69; // eax
  __m128 v70; // xmm0
  __m128 v71; // xmm3
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  signed __int64 v74; // rcx
  __int128 *v75; // rdx
  __int64 v76; // r8
  __int128 v77; // xmm0
  unsigned int v78; // er9
  signed __int64 v79; // rcx
  __int64 v80; // rax
  unsigned int *v81; // r14
  signed __int64 v82; // rcx
  AkRayVolumeData *v83; // rax
  int v84; // er12
  __int64 v85; // r13
  unsigned __int8 v86; // cl
  unsigned __int8 i; // al
  __int64 v88; // r15
  AkDeviceInfo *v89; // rdi
  __int64 v90; // rdx
  unsigned int v91; // ecx
  unsigned __int64 *v92; // rax
  AkDevice *v93; // rsi
  AkSIMDSpeakerVolumes *v94; // r14
  float v95; // xmm0_4
  float v96; // xmm7_4
  float v97; // xmm0_4
  float v98; // xmm6_4
  unsigned int v99; // eax
  unsigned int v100; // eax
  __int64 v101; // rax
  signed __int64 v102; // rcx
  __int64 v103; // rdi
  unsigned __int8 v104; // r8
  char v105; // cl
  unsigned __int8 v106; // al
  float v107; // xmm0_4
  unsigned int v108; // er14
  unsigned int v109; // edx
  __int64 v110; // rcx
  int v111; // esi
  signed __int64 v112; // rcx
  float v113; // xmm15_4
  float *v114; // rdx
  unsigned __int8 v115; // cl
  unsigned __int8 k; // al
  AkDeviceInfo *v117; // rbx
  signed __int64 v118; // rax
  __int64 v119; // rcx
  __int128 v120; // xmm0
  float v121; // xmm1_4
  float v122; // xmm6_4
  float v123; // xmm0_4
  CAkEnvironmentsMgr *v124; // rdi
  float v125; // xmm0_4
  CAkOutputDevices *v126; // rdi
  unsigned int v127; // er13
  AkDeviceInfo *v128; // rax
  unsigned int v129; // edx
  __int64 v130; // rcx
  float v131; // xmm11_4
  float v132; // xmm12_4
  float v133; // xmm13_4
  float *v134; // rdi
  __m128 v135; // xmm10
  AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v136; // r11
  float *v137; // rbx
  __int64 v138; // r15
  unsigned __int8 v139; // al
  unsigned __int8 l; // r14
  __int64 v141; // rsi
  __int64 v142; // rcx
  AkDeviceInfo *v143; // rax
  float v144; // xmm6_4
  float v145; // xmm7_4
  float v146; // xmm8_4
  __int64 v147; // r12
  __int64 v148; // rsi
  __int64 v149; // r11
  int v150; // er9
  signed __int64 v151; // r10
  unsigned int v152; // er8
  __m128 v153; // xmm3
  __m128 *v154; // rdx
  __m128 v155; // xmm3
  __m128 v156; // xmm0
  __int64 v157; // rcx
  __m128 v158; // xmm1
  unsigned __int8 v159; // al
  char m; // cl
  __int64 v161; // r12
  char *v162; // rcx
  __m128 *v163; // rax
  __int64 v164; // rdx
  __m128 v165; // xmm0
  __m128 v166; // xmm1
  __m128 v167; // xmm1
  float v168; // xmm0_4
  float v169; // xmm0_4
  float v170; // xmm0_4
  float v171; // xmm0_4
  unsigned __int8 v172; // al
  char n; // cl
  float *v174; // r8
  __m128 v175; // xmm4
  __int64 v176; // r12
  float *v177; // rax
  __int64 v178; // rbx
  unsigned __int8 v179; // cl
  unsigned __int8 ii; // si
  AkDeviceInfo *v181; // r11
  AkDeviceInfo *v182; // rcx
  int v183; // edi
  unsigned int v184; // er9
  __m128 *v185; // r8
  __m128 v186; // xmm0
  __m128 v187; // xmm1
  signed __int64 v188; // rdx
  __m128 v189; // xmm1
  __m128 v190; // xmm0
  __m128 v191; // xmm1
  float v192; // xmm0_4
  __int64 v193; // rdx
  float v194; // xmm1_4
  __int64 v195; // rdx
  float v196; // xmm0_4
  float v197; // xmm2_4
  float v198; // xmm1_4
  signed __int64 v199; // rdx
  float *v200; // rcx
  unsigned __int8 v201; // cl
  char jj; // dl
  __int64 v203; // r12
  AkDeviceInfo *v204; // rbx
  __int64 v205; // rax
  unsigned __int64 *v206; // rcx
  unsigned int v207; // edx
  float v208; // xmm4_4
  signed __int64 v209; // r8
  unsigned __int8 v210; // cl
  char kk; // dl
  unsigned int v212; // er15
  float v213; // xmm7_4
  unsigned int v214; // er14
  CAkEnvironmentsMgr *v215; // rdi
  float v216; // xmm6_4
  float v217; // xmm0_4
  float v218; // xmm0_4
  bool Dst; // [rsp+40h] [rbp+0h]
  unsigned int in_uNumFullBandChannels; // [rsp+44h] [rbp+4h]
  int v221; // [rsp+48h] [rbp+8h]
  bool *v222; // [rsp+50h] [rbp+10h]
  int v223; // [rsp+58h] [rbp+18h]
  int v224; // [rsp+5Ch] [rbp+1Ch]
  float *v225; // [rsp+60h] [rbp+20h]
  unsigned int out_index; // [rsp+68h] [rbp+28h]
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v227; // [rsp+70h] [rbp+30h]
  float *v228; // [rsp+78h] [rbp+38h]
  float *v229; // [rsp+80h] [rbp+40h]
  __m128 *v230; // [rsp+88h] [rbp+48h]
  int v231; // [rsp+90h] [rbp+50h]
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v232; // [rsp+98h] [rbp+58h]
  __int64 v233; // [rsp+A0h] [rbp+60h]
  __int64 v234; // [rsp+A8h] [rbp+68h]
  float in_fX[2]; // [rsp+B0h] [rbp+70h]
  __int64 v236; // [rsp+B8h] [rbp+78h]
  __int64 v237; // [rsp+C0h] [rbp+80h]
  __int64 v238; // [rsp+C8h] [rbp+88h]
  __int64 v239; // [rsp+D0h] [rbp+90h]
  __int64 v240; // [rsp+D8h] [rbp+98h]
  __int64 v241; // [rsp+E0h] [rbp+A0h]
  __int64 v242; // [rsp+E8h] [rbp+A8h]
  __int64 v243; // [rsp+F0h] [rbp+B0h]
  __int64 v244; // [rsp+F8h] [rbp+B8h]
  __int64 v245; // [rsp+100h] [rbp+C0h]
  __int64 v246; // [rsp+108h] [rbp+C8h]
  __int64 v247; // [rsp+110h] [rbp+D0h]
  __int64 v248; // [rsp+118h] [rbp+D8h]
  __int64 v249; // [rsp+120h] [rbp+E0h]
  __int64 v250; // [rsp+128h] [rbp+E8h]
  char v251; // [rsp+130h] [rbp+F0h]
  bool v252; // [rsp+320h] [rbp+2E0h]
  CAkPBI *v253; // [rsp+328h] [rbp+2E8h]
  AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v254; // [rsp+330h] [rbp+2F0h]
  unsigned int in_uInputConfiga; // [rsp+338h] [rbp+2F8h]

  in_uInputConfiga = in_uInputConfig;
  v254 = in_arVolumeData;
  v253 = in_pContext;
  v252 = in_bIsAuxRoutable;
  v6 = 0;
  v7 = in_arVolumeData;
  v8 = in_uInputConfig;
  v9 = 0;
  v221 = 0;
  if ( in_uInputConfig )
  {
    do
    {
      ++v9;
      v8 &= v8 - 1;
    }
    while ( v8 );
    v221 = v9;
  }
  v10 = v7->m_uLength;
  v11 = v9;
  v12 = in_pContext->m_BasePosParams.m_fCenterPCT * 0.0099999998;
  Dst = (in_uInputConfig & 8) != 0;
  if ( in_uInputConfig & 8 )
    v11 = v9 - 1;
  v13 = 32i64 * (unsigned int)(8 * v10);
  in_uNumFullBandChannels = v11;
  v14 = v13 + 15;
  if ( v13 + 15 <= v13 )
    v14 = 1152921504606846960i64;
  v15 = alloca(v14);
  v16 = &Dst;
  v222 = &Dst;
  memset(&Dst, 0, v13);
  v17 = 4 * v10;
  v18 = 4 * v10 + 15;
  if ( v18 <= 4 * v10 )
    v18 = 1152921504606846960i64;
  v19 = alloca(v18);
  v228 = (float *)&Dst;
  v20 = v17 + 15;
  if ( v17 + 15 <= v17 )
    v20 = 1152921504606846960i64;
  v21 = alloca(v20);
  v229 = (float *)&Dst;
  v22 = v17 + 15;
  if ( v17 + 15 <= v17 )
    v22 = 1152921504606846960i64;
  v23 = v22 & 0xFFFFFFFFFFFFFFF0ui64;
  v24 = alloca(v23);
  v25 = v253;
  v26 = alloca(v23);
  v27 = &Dst;
  v28 = (signed __int64)&v253->m_p3DSound->m_Params;
  v225 = (float *)&Dst;
  v234 = v28;
  if ( !*(_QWORD *)(v28 + 72) )
  {
    v29 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
            (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
            *(_DWORD *)(v28 + 4));
    v25 = v253;
    *(_QWORD *)(v28 + 72) = v29;
  }
  v30 = *(_QWORD *)(v28 + 72);
  v227 = 0i64;
  v233 = v30;
  v232 = 0i64;
  if ( v30 )
  {
    v31 = *(_BYTE *)(v30 + 124);
    if ( v31 == -1
      || (v227 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(16i64 * v31 + v30 + 40),
          !v227->m_pArrayGraphPoints) )
    {
      v227 = 0i64;
    }
    v32 = *(_BYTE *)(v30 + 123);
    if ( v32 == -1
      || (v232 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(v30 + 16i64 * v32 + 40),
          !v232->m_pArrayGraphPoints) )
    {
      v232 = 0i64;
    }
  }
  v33 = *((unsigned __int8 *)v25 + 371);
  v224 = 0;
  v34 = (v33 >> 2) & 3;
  v35 = (*((_BYTE *)v25 + 374) & 0x40) == 0;
  v231 = v34;
  if ( v35 )
  {
    CAkPBI::ValidateFeedbackParameters(v25);
    v25 = v253;
  }
  v36 = v25->m_pFeedbackInfo;
  v230 = (__m128 *)v36;
  if ( v36 )
  {
    AkFeedbackParams::ZeroNewVolumes(v36);
    AkFeedbackParams::ZeroNewAttenuations(v36);
    v25 = v253;
  }
  v37 = *(float *)&FLOAT_1_0;
  v35 = v34 == 1;
  v38 = v7->m_pItems;
  if ( !v35 )
  {
    v84 = 0;
    while ( 1 )
    {
      v85 = v6;
      v86 = 0;
      v225[v6] = 0.0;
      for ( i = v38->m_uListenerMask; !(i & 1); ++v86 )
        i >>= 1;
      v88 = v86;
      v89 = in_deviceVolumes->m_listDeviceVolumes.m_pFirst;
      v90 = *((_QWORD *)&CAkListener::m_listeners + 18 * v86 + 15);
      if ( in_deviceVolumes->m_listDeviceVolumes.m_pFirst )
      {
        while ( v89->uDeviceID != v90 )
        {
          v89 = v89->pNextLightItem;
          if ( !v89 )
            goto LABEL_100;
        }
      }
      else
      {
LABEL_100:
        v89 = 0i64;
      }
      v91 = 0;
      if ( CAkOutputMgr::m_Devices.m_uLength )
      {
        v92 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
        while ( *v92 != v90 )
        {
          ++v91;
          v92 += 10;
          if ( v91 >= CAkOutputMgr::m_Devices.m_uLength )
            goto LABEL_105;
        }
        v93 = &CAkOutputMgr::m_Devices.m_pItems[v91];
      }
      else
      {
LABEL_105:
        v93 = 0i64;
      }
      v94 = (AkSIMDSpeakerVolumes *)&v222[32 * v84];
      if ( v93 && v89 )
      {
        if ( *(_BYTE *)(v234 + 68) & 1 )
        {
          if ( v232 )
          {
            v95 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(v232, v38->r, 0, &out_index);
            v225[v85] = v95;
          }
          if ( in_uNumFullBandChannels )
          {
            v96 = 0.0;
            if ( v227 )
            {
              v97 = cosf(v38->phi);
              v96 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                      v227,
                      v97 * v38->r,
                      0,
                      &out_index);
            }
            v98 = v38->theta;
            v99 = AkDeviceInfo::GetOutputConfig(v89);
            CAkSpeakerPan::GetSpeakerVolumesPlane(v98, v12, v96, v94, 0i64, in_uNumFullBandChannels, v99, v93);
          }
        }
        else
        {
          v100 = AkDeviceInfo::GetOutputConfig(v89);
          CAkSpeakerPan::GetSpeakerVolumes2DPan(0.5, 0.5, v12, 1, in_uInputConfiga, v100, v94);
        }
        if ( Dst )
        {
          v101 = (__int64)v222;
          v102 = 32i64 * (unsigned int)(v84 + v221 - 1);
          *(_OWORD *)&v222[v102] = 0i64;
          *(_OWORD *)(v102 + v101 + 16) = 0i64;
          *(_DWORD *)(v102 + v101 + 28) = 1065353216;
        }
      }
      v103 = (__int64)v230;
      if ( !v230 || !((1 << v88) & CAkListener::m_uFeedbackMask) )
        goto LABEL_295;
      v104 = CAkFeedbackDeviceMgr::s_pSingleton->m_uPlayerMask & CAkFeedbackDeviceMgr::s_pSingleton->m_aListenerToPlayer[v88];
      if ( v104 )
      {
        v105 = 1;
        v106 = 0;
        do
        {
          if ( (unsigned __int8)v105 & v104 )
          {
            v107 = v38->fDryMixGain;
            if ( v107 <= *(float *)(v103 + 4i64 * v106 + 32) )
              v107 = *(float *)(v103 + 4i64 * v106 + 32);
            *(float *)(v103 + 4i64 * v106 + 32) = v107;
          }
          ++v106;
          v105 *= 2;
        }
        while ( v106 < 4u );
      }
      if ( !((1 << v88) & CAkListener::m_uAudioMask) || *((_BYTE *)v253 + 374) < 0 )
      {
        v108 = in_uNumFullBandChannels;
        v66 = v222;
        v109 = 0;
        if ( in_uNumFullBandChannels )
        {
          do
          {
            v110 = v84 + v109++;
            v110 *= 32i64;
            *(_OWORD *)&v66[v110] = 0i64;
            *(_OWORD *)&v66[v110 + 16] = 0i64;
          }
          while ( v109 < v108 );
        }
      }
      else
      {
LABEL_295:
        v66 = v222;
      }
      v81 = (unsigned int *)v254;
      v111 = v224;
      v228[v85] = 0.0;
      v6 = v111 + 1;
      v229[v85] = 0.0;
      ++v38;
      v84 += 8;
      v112 = *(_QWORD *)v81 + 36i64 * v81[2];
      v224 = v6;
      if ( v38 == (AkRayVolumeData *)v112 )
      {
        v78 = v221;
        goto LABEL_136;
      }
    }
  }
  v39 = 0;
  v223 = 0;
  while ( 1 )
  {
    v40 = v6;
    v41 = 0;
    *(_DWORD *)&v27[4 * v6] = 0;
    v42 = v38->m_uListenerMask;
    for ( j = 0.0; !(v42 & 1); ++v41 )
      v42 >>= 1;
    v44 = v41;
    v45 = v25->m_pGameObj;
    v46 = (signed __int64)&v16[32 * v39];
    v47 = (__m128 *)(&CAkListener::m_listeners + 9 * v44);
    v228[v40] = (float)(unsigned __int8)v25->m_pGameObj->m_fOcclusionValue[v44].m_ByteValue * 0.0039215689;
    v48 = (unsigned __int8)v45->m_fObstructionValue[v44].m_ByteValue;
    v49 = 0;
    v229[v40] = (float)v48 * 0.0039215689;
    if ( CAkOutputMgr::m_Devices.m_uLength )
    {
      v50 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
      while ( *v50 != v47[7].m128_u64[1] )
      {
        ++v49;
        v50 += 10;
        if ( v49 >= CAkOutputMgr::m_Devices.m_uLength )
          goto LABEL_36;
      }
      v51 = &CAkOutputMgr::m_Devices.m_pItems[v49];
    }
    else
    {
LABEL_36:
      v51 = 0i64;
    }
    v52 = in_deviceVolumes->m_listDeviceVolumes.m_pFirst;
    if ( in_deviceVolumes->m_listDeviceVolumes.m_pFirst )
    {
      while ( v52->uDeviceID != v47[7].m128_u64[1] )
      {
        v52 = v52->pNextLightItem;
        if ( !v52 )
          goto LABEL_40;
      }
    }
    else
    {
LABEL_40:
      v52 = 0i64;
    }
    if ( !in_uNumFullBandChannels || !v51 || !v52 )
      goto LABEL_51;
    if ( v47[2].m128_i8[8] )
    {
      if ( !(*(_BYTE *)(v234 + 68) & 1) )
      {
        v58 = AkDeviceInfo::GetOutputConfig(v52);
        CAkSpeakerPan::GetSpeakerVolumes2DPan(0.5, 0.5, v12, 1, in_uInputConfiga, v58, (AkSIMDSpeakerVolumes *)v46);
LABEL_51:
        v57 = in_uNumFullBandChannels;
        goto LABEL_52;
      }
      if ( v227 )
      {
        v53 = cosf(v38->phi);
        j = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(v227, v53 * v38->r, 0, &out_index);
      }
      v54 = v38->theta;
      in_uOutputConfig = AkDeviceInfo::GetOutputConfig(v52);
      in_pDevice = v51;
      v57 = in_uNumFullBandChannels;
      CAkSpeakerPan::GetSpeakerVolumesPlane(
        v54,
        v12,
        j,
        (AkSIMDSpeakerVolumes *)v46,
        0i64,
        in_uNumFullBandChannels,
        in_uOutputConfig,
        in_pDevice);
    }
    else
    {
      *(_OWORD *)v46 = 0i64;
      *(_OWORD *)(v46 + 16) = 0i64;
      v69 = AkDeviceInfo::GetOutputConfig(v52);
      if ( v69 & 1 )
        *(_DWORD *)v46 = 1065353216;
      if ( v69 & 2 )
        *(_DWORD *)(v46 + 4) = 1065353216;
      if ( v69 & 4 )
        *(_DWORD *)(v46 + 8) = 1065353216;
      if ( v69 & 0x10 )
        *(_DWORD *)(v46 + 12) = 1065353216;
      if ( v69 & 0x20 )
        *(_DWORD *)(v46 + 16) = 1065353216;
      if ( _bittest((const signed int *)&v69, 9u) )
        *(_DWORD *)(v46 + 20) = 1065353216;
      if ( _bittest((const signed int *)&v69, 0xAu) )
        *(_DWORD *)(v46 + 24) = 1065353216;
      v57 = in_uNumFullBandChannels;
      v70 = 0i64;
      v71 = (__m128)(unsigned int)FLOAT_1_0;
      v70.m128_f32[0] = (float)(signed int)in_uNumFullBandChannels;
      v71.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v70));
      v72 = _mm_shuffle_ps(v71, v71, 0);
      v73 = _mm_mul_ps(v72, *(__m128 *)v46);
      *(__m128 *)(v46 + 16) = _mm_mul_ps(v72, *(__m128 *)(v46 + 16));
      *(__m128 *)v46 = v73;
      if ( v57 > 1 )
      {
        v74 = v46 + 32;
        v75 = (__int128 *)v46;
        v76 = v57 - 1;
        do
        {
          v77 = *v75;
          v74 += 32i64;
          v75 += 2;
          *(_OWORD *)(v74 - 32) = v77;
          *(_OWORD *)(v74 - 16) = *(v75 - 1);
          --v76;
        }
        while ( v76 );
      }
    }
LABEL_52:
    if ( v232 )
    {
      v59 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(v232, v38->r, 0, &out_index);
      v225[v40] = v59;
    }
    v60 = (__int64)v230;
    if ( !v230 || !((1 << v44) & CAkListener::m_uFeedbackMask) )
      goto LABEL_296;
    v61 = CAkFeedbackDeviceMgr::s_pSingleton->m_uPlayerMask & CAkFeedbackDeviceMgr::s_pSingleton->m_aListenerToPlayer[v44];
    if ( v61 )
    {
      v62 = 1;
      v63 = 0;
      do
      {
        if ( (unsigned __int8)v62 & v61 )
        {
          v64 = v38->fDryMixGain;
          if ( v64 <= *(float *)(v60 + 4i64 * v63 + 32) )
            v64 = *(float *)(v60 + 4i64 * v63 + 32);
          *(float *)(v60 + 4i64 * v63 + 32) = v64;
        }
        ++v63;
        v62 *= 2;
      }
      while ( v63 < 4u );
    }
    if ( !((1 << v44) & CAkListener::m_uAudioMask) || *((_BYTE *)v253 + 374) < 0 )
    {
      v65 = v223;
      v66 = v222;
      v67 = 0;
      if ( v57 )
      {
        do
        {
          v68 = v65 + v67++;
          v68 *= 32i64;
          *(_OWORD *)&v66[v68] = 0i64;
          *(_OWORD *)&v66[v68 + 16] = 0i64;
        }
        while ( v67 < v57 );
      }
    }
    else
    {
LABEL_296:
      v65 = v223;
      v66 = v222;
    }
    v78 = v221;
    if ( Dst )
    {
      v79 = 32i64 * (unsigned int)(v65 + v221 - 1);
      *(_OWORD *)&v66[v79] = 0i64;
      *(_OWORD *)&v66[v79 + 16] = 0i64;
      *(_DWORD *)&v66[v79 + 28] = 1065353216;
    }
    if ( v78 )
    {
      v80 = v78;
      do
      {
        v46 += 32i64;
        *(__m128 *)(v46 - 32) = _mm_mul_ps(v47[3], *(__m128 *)(v46 - 32));
        *(__m128 *)(v46 - 16) = _mm_mul_ps(v47[4], *(__m128 *)(v46 - 16));
        --v80;
      }
      while ( v80 );
    }
    v81 = (unsigned int *)v254;
    v39 = v65 + 8;
    v6 = v224 + 1;
    ++v38;
    v82 = v254->m_uLength;
    v83 = v254->m_pItems;
    ++v224;
    v223 = v39;
    if ( v38 == &v83[v82] )
      break;
    v16 = v222;
    v27 = (bool *)v225;
    v25 = v253;
  }
  v37 = *(float *)&FLOAT_1_0;
LABEL_136:
  if ( v233 && *(_BYTE *)(v233 + 125) & 1 )
    v113 = *(float *)(v234 + 12);
  else
    v113 = 0.0;
  if ( v81[2] == 1 )
  {
    v114 = *(float **)v81;
    v115 = 0;
    for ( k = *(_BYTE *)(*(_QWORD *)v81 + 17i64); !(k & 1); ++v115 )
      k >>= 1;
    v117 = in_deviceVolumes->m_listDeviceVolumes.m_pFirst;
    if ( in_deviceVolumes->m_listDeviceVolumes.m_pFirst )
    {
      while ( v117->uDeviceID != *((_QWORD *)&CAkListener::m_listeners + 18 * v115 + 15) )
      {
        v117 = v117->pNextLightItem;
        if ( !v117 )
          return;
      }
      if ( v78 )
      {
        v118 = (signed __int64)v117->mxDirect;
        v119 = v78;
        do
        {
          v120 = *(_OWORD *)v66;
          v118 += 64i64;
          v66 += 32;
          *(_OWORD *)(v118 - 64) = v120;
          *(_OWORD *)(v118 - 48) = *((_OWORD *)v66 - 1);
          --v119;
        }
        while ( v119 );
      }
      v121 = in_fBehavioralVolume;
      v117->mxAttenuations.dry.fNext = in_fBehavioralVolume * v114[5];
      if ( v252 )
      {
        v117->mxAttenuations.gameDef.fNext = v121 * v114[6];
        v117->mxAttenuations.userDef.fNext = v121 * v114[7];
      }
      else
      {
        v117->mxAttenuations.gameDef.fNext = 0.0;
        v117->mxAttenuations.userDef.fNext = 0.0;
      }
      v122 = v253->m_EffectiveParams.LPF;
      if ( v122 <= *v225 )
        v122 = *v225;
      if ( v113 > 0.0 )
      {
        v123 = AkMath::Interpolate(0.0, 0.0, v37, v113, v114[8]);
        if ( v122 <= v123 )
          v122 = v123;
      }
      if ( v231 == 1 )
      {
        v124 = g_pEnvironmentMgr;
        if ( g_pEnvironmentMgr->m_bCurveEnabled[1][1] )
        {
          if ( g_pEnvironmentMgr->ConversionTable[1][1].m_pArrayGraphPoints )
          {
            v125 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                     &g_pEnvironmentMgr->ConversionTable[1][1],
                     *v228 * 100.0,
                     0,
                     &in_uInputConfiga);
            if ( v122 <= v125 )
              v122 = v125;
          }
        }
        if ( v124->m_bCurveEnabled[0][1] )
        {
          if ( v124->ConversionTable[0][1].m_pArrayGraphPoints )
            v117->fObsLPF = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                              &v124->ConversionTable[0][1],
                              *v229 * 100.0,
                              0,
                              &in_uInputConfiga);
        }
      }
      v117->fLPF = v122;
    }
  }
  else
  {
    v126 = in_deviceVolumes;
    v127 = v221;
    v128 = in_deviceVolumes->m_listDeviceVolumes.m_pFirst;
    if ( in_deviceVolumes->m_listDeviceVolumes.m_pFirst )
    {
      do
      {
        v129 = 0;
        do
        {
          v130 = v129++;
          v130 <<= 6;
          *(__m128 *)((char *)v128->mxDirect[0].Next.vector + v130) = 0i64;
          *(_OWORD *)((char *)&v128->mxDirect[0].Next.aVolumes[4] + v130) = 0i64;
        }
        while ( v129 < v127 );
        v128->mxAttenuations.dry.fNext = 0.0;
        v128->mxAttenuations.userDef.fNext = 0.0;
        v128->mxAttenuations.gameDef.fNext = 0.0;
        v128 = v128->pNextLightItem;
      }
      while ( v128 );
    }
    v131 = 0.0;
    *(_QWORD *)in_fX = 4575657222473777152i64;
    v236 = 4575657222473777152i64;
    v237 = 4575657222473777152i64;
    v132 = 0.0;
    v133 = 0.0;
    v238 = 4575657222473777152i64;
    v243 = 4575657222473777152i64;
    v244 = 4575657222473777152i64;
    v245 = 4575657222473777152i64;
    v246 = 4575657222473777152i64;
    v239 = 4575657222473777152i64;
    v240 = 4575657222473777152i64;
    v241 = 4575657222473777152i64;
    v242 = 4575657222473777152i64;
    v247 = 4812096202965778432i64;
    v248 = 4812096202965778432i64;
    v249 = 4812096202965778432i64;
    v250 = 4812096202965778432i64;
    if ( CAkPBI::IsMultiPositionTypeMultiSources(v253) )
    {
      v134 = *(float **)v81;
      v135 = (__m128)LODWORD(in_fBehavioralVolume);
      v136 = v254;
      v137 = *(float **)v81;
      v138 = 0i64;
      do
      {
        v139 = *((_BYTE *)v137 + 17);
        for ( l = 0; !(v139 & 1); ++l )
          v139 >>= 1;
        v141 = 0i64;
        v233 = l;
        v230 = 0i64;
        v142 = *((_QWORD *)&CAkListener::m_listeners + 18 * l + 15);
        v143 = in_deviceVolumes->m_listDeviceVolumes.m_pFirst;
        if ( in_deviceVolumes->m_listDeviceVolumes.m_pFirst )
        {
          while ( !v141 )
          {
            if ( v143->uDeviceID == v142 )
              v141 = (__int64)v143;
            v143 = v143->pNextLightItem;
            v230 = (__m128 *)v141;
            if ( !v143 )
            {
              if ( !v141 )
                goto LABEL_216;
              break;
            }
          }
          v144 = FLOAT_100_0;
          v145 = v37;
          v146 = v37;
          memset(&v251, 0, 0x100ui64);
          v147 = (__int64)v222;
          v148 = (__int64)v229;
          v149 = (__int64)v225;
          v150 = 8 * v138;
          v151 = (signed __int64)&v134[9 * v254->m_uLength];
          do
          {
            v152 = 0;
            if ( v127 )
            {
              v153 = v135;
              v154 = (__m128 *)&v251;
              v153.m128_f32[0] = v135.m128_f32[0] * v137[5];
              v155 = _mm_shuffle_ps(v153, v153, 0);
              do
              {
                v156 = *v154;
                v157 = v150 + v152++;
                v157 *= 32i64;
                v154 += 2;
                v158 = _mm_add_ps(v154[-1], _mm_mul_ps(*(__m128 *)(v157 + v147 + 16), v155));
                v154[-2] = _mm_add_ps(v156, _mm_mul_ps(*(__m128 *)(v157 + v147), v155));
                v154[-1] = v158;
              }
              while ( v152 < v127 );
            }
            if ( v137[5] > v131 )
              v131 = v137[5];
            if ( v252 )
            {
              if ( v137[7] > v132 )
                v132 = v137[7];
              if ( v137[6] > v133 )
                v133 = v137[6];
            }
            if ( v144 >= *(float *)(v149 + 4 * v138) )
              v144 = *(float *)(v149 + 4 * v138);
            if ( v145 >= v228[v138] )
              v145 = v228[v138];
            if ( v146 >= *(float *)(v148 + 4 * v138) )
              v146 = *(float *)(v148 + 4 * v138);
            if ( v37 >= v137[8] )
              v37 = v137[8];
            v137 += 9;
            v138 = (unsigned int)(v138 + 1);
            v150 += 8;
            if ( v137 == (float *)v151 )
              break;
            v159 = *((_BYTE *)v137 + 17);
            for ( m = 0; !(v159 & 1); ++m )
              v159 >>= 1;
          }
          while ( m == l );
          v161 = v233;
          v136 = v254;
          if ( v127 )
          {
            v162 = &v251;
            v163 = v230 + 1;
            v164 = v127;
            do
            {
              v165 = *v163;
              v166 = v163[1];
              v163 += 4;
              v162 += 32;
              v167 = _mm_max_ps(v166, *((__m128 *)v162 - 1));
              v163[-4] = _mm_max_ps(v165, *((__m128 *)v162 - 2));
              v163[-3] = v167;
              --v164;
            }
            while ( v164 );
          }
          v168 = *((float *)&v247 + v161);
          if ( v168 >= v144 )
            v168 = v144;
          *((float *)&v247 + v161) = v168;
          v169 = *((float *)&v239 + v161);
          if ( v169 >= v145 )
            v169 = v145;
          *((float *)&v239 + v161) = v169;
          v170 = *((float *)&v243 + v161);
          if ( v170 >= v146 )
            v170 = v146;
          *((float *)&v243 + v161) = v170;
          v171 = in_fX[v161];
          if ( v171 >= v37 )
            v171 = v37;
          in_fX[v161] = v171;
        }
        else
        {
          do
          {
LABEL_216:
            v137 += 9;
            v138 = (unsigned int)(v138 + 1);
            if ( v137 == &v134[9 * v136->m_uLength] )
              break;
            v172 = *((_BYTE *)v137 + 17);
            for ( n = 0; !(v172 & 1); ++n )
              v172 >>= 1;
          }
          while ( n == l );
        }
        v134 = (float *)&v136->m_pItems->0;
        v37 = *(float *)&FLOAT_1_0;
      }
      while ( v137 != (float *)&v136->m_pItems[v136->m_uLength].0 );
    }
    else
    {
      v174 = *(float **)v81;
      v175 = (__m128)LODWORD(in_fBehavioralVolume);
      v176 = (__int64)v225;
      v177 = *(float **)v81;
      v178 = 0i64;
      do
      {
        v179 = *((_BYTE *)v177 + 17);
        for ( ii = 0; !(v179 & 1); ++ii )
          v179 >>= 1;
        v181 = 0i64;
        v182 = v126->m_listDeviceVolumes.m_pFirst;
        if ( v126->m_listDeviceVolumes.m_pFirst )
        {
          while ( !v181 )
          {
            if ( v182->uDeviceID == *((_QWORD *)&CAkListener::m_listeners + 18 * ii + 15) )
              v181 = v182;
            v182 = v182->pNextLightItem;
            if ( !v182 )
            {
              if ( !v181 )
                goto LABEL_265;
              break;
            }
          }
          v183 = 8 * v178;
          do
          {
            v184 = 0;
            if ( v127 )
            {
              v185 = (__m128 *)v181->mxDirect;
              do
              {
                v186 = *v185;
                v187 = v175;
                v188 = 32i64 * (v184++ + v183);
                v185 += 4;
                v187.m128_f32[0] = v175.m128_f32[0] * v177[5];
                v189 = _mm_shuffle_ps(v187, v187, 0);
                v190 = _mm_max_ps(v186, _mm_mul_ps(*(__m128 *)&v66[v188], v189));
                v191 = _mm_max_ps(v185[-3], _mm_mul_ps(*(__m128 *)&v66[v188 + 16], v189));
                v185[-4] = v190;
                v185[-3] = v191;
              }
              while ( v184 < v127 );
            }
            if ( v177[5] > v131 )
              v131 = v177[5];
            if ( v252 )
            {
              if ( v177[7] > v132 )
                v132 = v177[7];
              if ( v177[6] > v133 )
                v133 = v177[6];
            }
            v192 = *((float *)&v247 + ii);
            if ( v192 >= *(float *)(v176 + 4 * v178) )
              v192 = *(float *)(v176 + 4 * v178);
            v193 = (__int64)v228;
            v194 = *((float *)&v239 + ii);
            *((float *)&v247 + ii) = v192;
            if ( v194 >= *(float *)(v193 + 4 * v178) )
              v194 = *(float *)(v193 + 4 * v178);
            v195 = (__int64)v229;
            v196 = *((float *)&v243 + ii);
            *((float *)&v239 + ii) = v194;
            if ( v196 >= *(float *)(v195 + 4 * v178) )
              v196 = *(float *)(v195 + 4 * v178);
            v197 = v177[8];
            v198 = in_fX[ii];
            *((float *)&v243 + ii) = v196;
            if ( v198 >= v197 )
              v198 = v197;
            v177 += 9;
            v178 = (unsigned int)(v178 + 1);
            v199 = 9i64 * v81[2];
            v200 = *(float **)v81;
            v183 += 8;
            in_fX[ii] = v198;
            if ( v177 == &v200[v199] )
              break;
            v201 = *((_BYTE *)v177 + 17);
            for ( jj = 0; !(v201 & 1); ++jj )
              v201 >>= 1;
          }
          while ( jj == ii );
          v126 = in_deviceVolumes;
        }
        else
        {
LABEL_265:
          v209 = (signed __int64)&v174[9 * v81[2]];
          do
          {
            v177 += 9;
            v178 = (unsigned int)(v178 + 1);
            if ( v177 == (float *)v209 )
              break;
            v210 = *((_BYTE *)v177 + 17);
            for ( kk = 0; !(v210 & 1); ++kk )
              v210 >>= 1;
          }
          while ( kk == ii );
        }
        v174 = *(float **)v81;
      }
      while ( v177 != (float *)(*(_QWORD *)v81 + 36i64 * v81[2]) );
    }
    v203 = v231;
    v204 = in_deviceVolumes->m_listDeviceVolumes.m_pFirst;
    if ( in_deviceVolumes->m_listDeviceVolumes.m_pFirst )
    {
      do
      {
        v205 = 0i64;
        if ( CAkOutputMgr::m_Devices.m_uLength )
        {
          v206 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
          while ( *v206 != v204->uDeviceID )
          {
            v205 = (unsigned int)(v205 + 1);
            v206 += 10;
            if ( (unsigned int)v205 >= CAkOutputMgr::m_Devices.m_uLength )
              goto LABEL_261;
          }
          v207 = CAkOutputMgr::m_Devices.m_pItems[v205].uListeners;
        }
        else
        {
LABEL_261:
          LOBYTE(v207) = 0;
        }
        v204->mxAttenuations.dry.fNext = 1.0;
        if ( v252 && v131 > 0.0 )
        {
          v208 = *(float *)&FLOAT_1_0;
          v204->mxAttenuations.gameDef.fNext = v133 * (float)(1.0 / v131);
          v204->mxAttenuations.userDef.fNext = v132 * (float)(1.0 / v131);
        }
        else
        {
          v208 = *(float *)&FLOAT_1_0;
          v204->mxAttenuations.gameDef.fNext = 0.0;
          v204->mxAttenuations.userDef.fNext = 0.0;
        }
        v212 = 0;
        v213 = FLOAT_100_0;
        v214 = v207 & v253->m_pGameObj->m_PosKeep.m_uListenerMask;
        if ( (unsigned __int8)v207 & v253->m_pGameObj->m_PosKeep.m_uListenerMask )
        {
          v215 = g_pEnvironmentMgr;
          do
          {
            if ( v214 & 1 )
            {
              v216 = *((float *)&v247 + v212);
              if ( v113 > 0.0 )
              {
                v217 = AkMath::Interpolate(0.0, 0.0, v208, v113, in_fX[v212]);
                v215 = g_pEnvironmentMgr;
                if ( v216 <= v217 )
                  v216 = v217;
              }
              if ( v203 == 1 )
              {
                if ( v215->m_bCurveEnabled[1][1] )
                {
                  if ( v215->ConversionTable[1][1].m_pArrayGraphPoints )
                  {
                    v218 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                             &v215->ConversionTable[1][1],
                             *((float *)&v239 + v212) * 100.0,
                             0,
                             &in_uInputConfiga);
                    if ( v216 <= v218 )
                      v216 = v218;
                  }
                }
                if ( v215->m_bCurveEnabled[0][1] && v215->ConversionTable[0][1].m_pArrayGraphPoints )
                {
                  v204->fObsLPF = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                                    &v215->ConversionTable[0][1],
                                    *((float *)&v243 + v212) * 100.0,
                                    0,
                                    &in_uInputConfiga);
                  v215 = g_pEnvironmentMgr;
                }
              }
              if ( v213 >= v216 )
                v213 = v216;
            }
            v208 = *(float *)&FLOAT_1_0;
            ++v212;
            v214 >>= 1;
          }
          while ( v214 );
        }
        if ( v213 <= v253->m_EffectiveParams.LPF )
          v213 = v253->m_EffectiveParams.LPF;
        v204->fLPF = v213;
        v204 = v204->pNextLightItem;
      }
      while ( v204 );
    }
  }
}v213;
        v204 = v204->pNextLightItem;
      }
      while ( v204 );
    }
  }
}

// File Line: 904
// RVA: 0xA69570
void __fastcall CAkListener::DoSpeakerVolumeMatrixCallback(unsigned int in_playingID, __int64 in_uNumChannels, unsigned int in_uInputConfig, unsigned int in_uOutputConfig, AkDeviceInfo *io_rDeviceVolume)
{
  __int64 v5; // r10
  AkSpeakerVolumes **v6; // rax
  AkAudioMix *v7; // rdi
  AkSpeakerVolumeMatrixCallbackInfo in_pInfo; // [rsp+20h] [rbp-88h]

  v5 = 0i64;
  if ( (_DWORD)in_uNumChannels )
  {
    v5 = (unsigned int)in_uNumChannels;
    v6 = in_pInfo.pVolumes;
    v7 = io_rDeviceVolume->mxDirect;
    in_uNumChannels = (unsigned int)in_uNumChannels;
    do
    {
      *v6 = (AkSpeakerVolumes *)v7;
      ++v7;
      ++v6;
      --in_uNumChannels;
    }
    while ( in_uNumChannels );
  }
  if ( (unsigned int)v5 < 8 )
    memset(&in_pInfo.pVolumes[v5], 0, 8i64 * (unsigned int)(8 - v5));
  in_pInfo.uInputConfig = in_uInputConfig;
  in_pInfo.io_pfDryAttenuation = (float *)&io_rDeviceVolume->mxAttenuations.dry;
  in_pInfo.io_pfGameDefAuxSendAttenuation = (float *)&io_rDeviceVolume->mxAttenuations.gameDef;
  in_pInfo.io_pfUserDefAuxSendDryAttenuation = (float *)&io_rDeviceVolume->mxAttenuations.userDef;
  in_pInfo.uOutputConfig = in_uOutputConfig;
  CAkPlayingMgr::NotifySpeakerVolumeMatrix(g_pPlayingMgr, in_playingID, &in_pInfo);
}

// File Line: 934
// RVA: 0xA699C0
void __fastcall CAkListener::GetListenerVolume(CAkAttenuation *in_pAttenuation, AkEmitterListenerPair *in_ray, float in_fConeOutsideVolume, float *out_fMinCone, float *out_fListenerVolumeDry, float *out_fListenerVolumeGameDefAux, float *out_fListenerVolumeUserDefAux)
{
  float *out_fCone; // rsi
  AkEmitterListenerPair *v8; // r14
  CAkAttenuation *v9; // rbx
  unsigned __int8 v10; // al
  float v11; // xmm7_4
  __int64 v12; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v13; // rdi
  float v14; // xmm6_4
  float *v15; // rbp
  unsigned __int8 v16; // al
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v17; // rcx
  float v18; // xmm0_4
  unsigned __int8 v19; // al
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v20; // rcx
  float v21; // xmm0_4
  float *v22; // rax
  unsigned int out_index; // [rsp+80h] [rbp+8h]

  out_fCone = out_fMinCone;
  v8 = in_ray;
  v9 = in_pAttenuation;
  if ( !in_pAttenuation )
  {
    v22 = out_fListenerVolumeDry;
    *out_fMinCone = 1.0;
    *v22 = 1.0;
    *out_fListenerVolumeGameDefAux = 1.0;
    *out_fListenerVolumeUserDefAux = 1.0;
    return;
  }
  v10 = in_pAttenuation->m_curveToUse[0];
  v11 = in_ray->r;
  if ( v10 != -1 && (v12 = v10, v13 = &in_pAttenuation->m_curves[v12], v13->m_pArrayGraphPoints) )
  {
    if ( v13 )
    {
      v14 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
              &in_pAttenuation->m_curves[v12],
              in_ray->r,
              0,
              &out_index);
      goto LABEL_8;
    }
  }
  else
  {
    v13 = 0i64;
  }
  v14 = *(float *)&FLOAT_1_0;
LABEL_8:
  v15 = out_fListenerVolumeDry;
  *out_fListenerVolumeDry = v14;
  v16 = v9->m_curveToUse[1];
  if ( v16 == -1 || (v17 = &v9->m_curves[v16], !v17->m_pArrayGraphPoints) )
    v17 = 0i64;
  if ( v17 == v13 )
  {
    *out_fListenerVolumeGameDefAux = v14;
  }
  else if ( v17 )
  {
    v18 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(v17, v11, 0, &out_index);
    *out_fListenerVolumeGameDefAux = v18;
  }
  else
  {
    *out_fListenerVolumeGameDefAux = 1.0;
  }
  v19 = v9->m_curveToUse[2];
  if ( v19 == -1 || (v20 = &v9->m_curves[v19], !v20->m_pArrayGraphPoints) )
    v20 = 0i64;
  if ( v20 == v13 )
  {
    *out_fListenerVolumeUserDefAux = v14;
  }
  else if ( v20 )
  {
    v21 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(v20, v11, 0, &out_index);
    *out_fListenerVolumeUserDefAux = v21;
  }
  else
  {
    *out_fListenerVolumeUserDefAux = 1.0;
  }
  if ( *((_BYTE *)v9 + 125) & 1 )
    *v15 = CAkListener::ComputeConeAttenuation(
             v9->m_ConeParams.fInsideAngle,
             v9->m_ConeParams.fOutsideAngle,
             in_fConeOutsideVolume,
             v8->fEmitterAngle,
             out_fCone)
         * *v15;
  else
    *out_fCone = 1.0;
}

