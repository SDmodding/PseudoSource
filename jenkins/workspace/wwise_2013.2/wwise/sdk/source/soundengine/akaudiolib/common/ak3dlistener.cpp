// File Line: 42
// RVA: 0x15BE040
hkSeekableStreamReader *dynamic_initializer_for__CAkListener::m_listeners__()
{
  hkSeekableStreamReader *v0; // rbx
  int i; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &CAkListener::m_listeners;
  for ( i = 7; i >= 0; --i )
  {
    result = Assembly::GetRCX(v0);
    v0 += 9;
  }
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
  float Z; // [rsp+28h] [rbp-30h]
  AkVector result; // [rsp+30h] [rbp-28h] BYREF

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
    *((AkListenerPosition *)v1 - 3) = g_DefaultListenerPosition;
    v3 = AkMath::CrossProduct(
           &result,
           &g_DefaultListenerPosition.OrientationTop,
           &g_DefaultListenerPosition.OrientationFront);
    Z = v3->Z;
    *(_QWORD *)(v1 - 28) = *(_QWORD *)&v3->X;
    *((float *)v1 - 5) = Z;
    *((_DWORD *)v1 - 4) = *((_DWORD *)v1 - 24);
    *((_DWORD *)v1 - 3) = *((_DWORD *)v1 - 23);
    *((_DWORD *)v1 - 2) = *((_DWORD *)v1 - 22);
    *((_DWORD *)v1 - 1) = *((_DWORD *)v1 - 27);
    *(_DWORD *)v1 = *((_DWORD *)v1 - 26);
    *((_DWORD *)v1 + 1) = *((_DWORD *)v1 - 25);
    v1[20] = 1;
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
    if ( (in_uListenerMask & 1) != 0 )
      *((_QWORD *)&unk_14249F008 + 18 * i) = in_uDeviceID;
    i = (unsigned int)(i + 1);
  }
}

// File Line: 92
// RVA: 0xA69D10
void CAkListener::OnBeginFrame(void)
{
  int v0; // edx

  v0 = unk_14249F010 != 0;
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
  float Z; // [rsp+28h] [rbp-20h]
  AkVector result; // [rsp+30h] [rbp-18h] BYREF

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
    Z = v2->Z;
    *(_QWORD *)&v1[-3].Z = *(_QWORD *)&v2->X;
    v1[-2].Y = Z;
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
__int64 __fastcall CAkListener::SetListenerPosition(unsigned int in_uListener, AkListenerPosition *in_Position)
{
  AkVector *p_OrientationTop; // rdx
  hkSeekableStreamReader *v5; // rbx
  AkVector *v6; // rax
  float Z; // [rsp+28h] [rbp-20h]
  AkVector result; // [rsp+30h] [rbp-18h] BYREF

  if ( in_uListener >= 8 )
    return 31i64;
  p_OrientationTop = &in_Position->OrientationTop;
  v5 = &CAkListener::m_listeners + 9 * in_uListener;
  *(AkListenerPosition *)&v5->vfptr = *(AkListenerPosition *)&p_OrientationTop[-1].X;
  v6 = AkMath::CrossProduct(&result, p_OrientationTop, &in_Position->OrientationFront);
  Z = v6->Z;
  v5[5].vfptr = *(hkBaseObjectVtbl **)&v6->X;
  *(float *)&v5[5].m_memSizeAndFlags = Z;
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
  __int64 v2; // rcx

  v2 = 18i64 * in_uListener;
  *((float *)&CAkListener::m_listeners + 2 * v2 + 9) = in_fScalingFactor;
  *((_BYTE *)&CAkListener::m_listeners + 8 * v2 + 128) = 1;
}

// File Line: 167
// RVA: 0xA6A040
__int64 __fastcall CAkListener::SetListenerSpatialization(
        unsigned int in_uListener,
        bool in_bSpatialized,
        AkSpeakerVolumes *in_pVolumeOffsets)
{
  __int64 result; // rax
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
    *(AkSpeakerVolumes *)(&CAkListener::m_listeners + 9 * in_uListener + 3) = *in_pVolumeOffsets;
    v5 = 0.0;
    v6 = *((float *)&CAkListener::m_listeners + 36 * in_uListener + 12) * 0.050000001;
    if ( v6 >= -37.0 )
    {
      if ( (v4 & 1) != 0 )
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
      v8 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v7 * v6) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((int)(float)((float)(v7 * v6) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((int)(float)((float)(v7 * v6) + 1065353200.0) & 0xFF800000);
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
      if ( (v4 & 1) == 0 )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v11 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v7 * v10) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((int)(float)((float)(v7 * v10) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((int)(float)((float)(v7 * v10) + 1065353200.0) & 0xFF800000);
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
      if ( (v4 & 1) == 0 )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v14 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v7 * v13) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((int)(float)((float)(v7 * v13) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((int)(float)((float)(v7 * v13) + 1065353200.0) & 0xFF800000);
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
      if ( (v4 & 1) == 0 )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v17 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v16 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((int)(float)((float)(v16 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((int)(float)((float)(v16 * v7) + 1065353200.0) & 0xFF800000);
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
      if ( (v4 & 1) == 0 )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v20 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v19 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((int)(float)((float)(v19 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((int)(float)((float)(v19 * v7) + 1065353200.0) & 0xFF800000);
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
      if ( (v4 & 1) == 0 )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v23 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v22 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((int)(float)((float)(v22 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((int)(float)((float)(v22 * v7) + 1065353200.0) & 0xFF800000);
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
      if ( (v4 & 1) == 0 )
      {
        v7 = FLOAT_2_7866352e7;
        v4 |= 1u;
        `AkMath::FastPow10::`4::`local static guard = v4;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v26 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v25 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                          * 0.32518977)
                                  + 0.020805772)
                          * COERCE_FLOAT(((int)(float)((float)(v25 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                  + 0.65304345)
          * COERCE_FLOAT((int)(float)((float)(v25 * v7) + 1065353200.0) & 0xFF800000);
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
      if ( (v4 & 1) == 0 )
      {
        v7 = FLOAT_2_7866352e7;
        `AkMath::FastPow10::`4::`local static guard = v4 | 1;
        `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      }
      v5 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v28 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                         * 0.32518977)
                                 + 0.020805772)
                         * COERCE_FLOAT(((int)(float)((float)(v28 * v7) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                 + 0.65304345)
         * COERCE_FLOAT((int)(float)((float)(v28 * v7) + 1065353200.0) & 0xFF800000);
    }
    *((float *)&CAkListener::m_listeners + 36 * in_uListener + 18) = v5;
    return 1i64;
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
void __fastcall CAkListener::SetListenerPipeline(char in_uListener, bool in_bAudio, bool in_bFeedback)
{
  int v3; // r9d
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
void __fastcall CAkListener::Get3DVolumes(
        AkPositionSourceType in_ePosType,
        bool in_bIsAuxRoutable,
        CAkPBI *in_pContext,
        AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *io_arVolumeData)
{
  __int128 v4; // xmm0
  float m_fDryLevelValue; // xmm8_4
  float v9; // xmm0_4
  float v10; // xmm7_4
  float v11; // xmm1_4
  int v12; // eax
  CAkGen3DParams *m_p3DSound; // rbx
  float m_fConeOutsideVolume; // xmm12_4
  CAkAttenuation *m_pAttenuation; // r15
  AkRayVolumeData *m_pItems; // rbx
  unsigned __int8 m_uListenerMask; // al
  unsigned __int8 i; // cl
  __int64 v19; // rdi
  __int64 v20; // rbp
  int m_ByteValue; // ecx
  CAkEnvironmentsMgr *v22; // rdi
  __int128 v23; // xmm6
  float v24; // xmm0_4
  float v25; // xmm0_4
  unsigned int out_index[4]; // [rsp+40h] [rbp-A8h] BYREF
  float out_fListenerVolumeGameDefAux; // [rsp+F0h] [rbp+8h] BYREF
  float out_fListenerVolumeDry; // [rsp+F8h] [rbp+10h] BYREF
  float out_fListenerVolumeUserDefAux; // [rsp+100h] [rbp+18h] BYREF

  if ( in_bIsAuxRoutable )
    m_fDryLevelValue = in_pContext->m_pGameObj->m_fDryLevelValue;
  else
    m_fDryLevelValue = *(float *)&FLOAT_1_0;
  v9 = CAkPBI::GetOutputBusVolumeValuedB(in_pContext) * 0.050000001;
  if ( v9 >= -37.0 )
  {
    if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
    {
      v11 = *(float *)&`AkMath::FastPow10::`4::SCALE;
    }
    else
    {
      v11 = FLOAT_2_7866352e7;
      `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
      `AkMath::FastPow10::`4::`local static guard |= 1u;
    }
    v12 = (int)(float)((float)(v9 * v11) + 1065353200.0);
    LODWORD(out_fListenerVolumeDry) = (v12 & 0x7FFFFF) + 1065353216;
    LODWORD(out_fListenerVolumeGameDefAux) = v12 & 0xFF800000;
    v4 = LODWORD(out_fListenerVolumeDry);
    v10 = (float)((float)((float)((float)(out_fListenerVolumeDry * 0.32518977) + 0.020805772) * out_fListenerVolumeDry)
                + 0.65304345)
        * COERCE_FLOAT(v12 & 0xFF800000);
  }
  else
  {
    v10 = 0.0;
  }
  m_p3DSound = in_pContext->m_p3DSound;
  m_fConeOutsideVolume = m_p3DSound->m_Params.m_fConeOutsideVolume;
  if ( !m_p3DSound->m_Params.m_pAttenuation )
    m_p3DSound->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                              (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                              m_p3DSound->m_Params.m_uAttenuationID);
  m_pAttenuation = m_p3DSound->m_Params.m_pAttenuation;
  m_pItems = io_arVolumeData->m_pItems;
  if ( in_ePosType == AkGameDef )
  {
    do
    {
      m_uListenerMask = m_pItems->m_uListenerMask;
      for ( i = 0; (m_uListenerMask & 1) == 0; ++i )
        m_uListenerMask >>= 1;
      v19 = i;
      CAkListener::GetListenerVolume(
        m_pAttenuation,
        m_pItems,
        m_fConeOutsideVolume,
        &m_pItems->fConeInterp,
        &out_fListenerVolumeDry,
        &out_fListenerVolumeGameDefAux,
        &out_fListenerVolumeUserDefAux);
      v20 = (unsigned int)v19;
      m_ByteValue = (unsigned __int8)in_pContext->m_pGameObj->m_fOcclusionValue[v19].m_ByteValue;
      v22 = g_pEnvironmentMgr;
      if ( g_pEnvironmentMgr->m_bCurveEnabled[1][0] && g_pEnvironmentMgr->ConversionTable[1][0].m_pArrayGraphPoints )
      {
        *(float *)&v4 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                          g_pEnvironmentMgr->ConversionTable[1],
                          (float)((float)m_ByteValue * 0.0039215689) * 100.0,
                          0,
                          out_index);
        v23 = v4;
      }
      else
      {
        v23 = (unsigned int)FLOAT_1_0;
      }
      if ( v22->m_bCurveEnabled[0][0] && v22->ConversionTable[0][0].m_pArrayGraphPoints )
        v24 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                v22->ConversionTable[0],
                (float)((float)(unsigned __int8)in_pContext->m_pGameObj->m_fObstructionValue[v20].m_ByteValue
                      * 0.0039215689)
              * 100.0,
                0,
                out_index)
            * *(float *)&v23;
      else
        v24 = *(float *)&v23;
      ++m_pItems;
      m_pItems[-1].fDryMixGain = (float)((float)(v24 * out_fListenerVolumeDry) * m_fDryLevelValue) * v10;
      v4 = v23;
      *(float *)&v4 = *(float *)&v23 * out_fListenerVolumeGameDefAux;
      m_pItems[-1].fUserDefAuxMixGain = *(float *)&v23 * out_fListenerVolumeUserDefAux;
      LODWORD(m_pItems[-1].fGameDefAuxMixGain) = v4;
    }
    while ( m_pItems != &io_arVolumeData->m_pItems[io_arVolumeData->m_uLength] );
  }
  else
  {
    do
    {
      CAkListener::GetListenerVolume(
        m_pAttenuation,
        m_pItems,
        m_fConeOutsideVolume,
        &m_pItems->fConeInterp,
        &out_fListenerVolumeDry,
        &out_fListenerVolumeGameDefAux,
        &out_fListenerVolumeUserDefAux);
      ++m_pItems;
      v25 = out_fListenerVolumeDry;
      m_pItems[-1].fUserDefAuxMixGain = out_fListenerVolumeUserDefAux;
      m_pItems[-1].fDryMixGain = (float)(v25 * m_fDryLevelValue) * v10;
      m_pItems[-1].fGameDefAuxMixGain = out_fListenerVolumeGameDefAux;
    }
    while ( m_pItems != &io_arVolumeData->m_pItems[io_arVolumeData->m_uLength] );
  }
}

// File Line: 300
// RVA: 0xA68140
void __fastcall CAkListener::ComputeSpeakerMatrix(
        bool in_bIsAuxRoutable,
        CAkPBI *in_pContext,
        AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_arVolumeData,
        unsigned int in_uInputConfig,
        float in_fBehavioralVolume,
        CAkOutputDevices *in_deviceVolumes)
{
  unsigned int v6; // esi
  unsigned int v8; // r10d
  int v9; // r8d
  __int64 m_uLength; // rbx
  unsigned int v11; // eax
  float v12; // xmm10_4
  size_t v13; // r8
  __int64 v14; // rax
  void *v15; // rsp
  char *v16; // r14
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rax
  void *v19; // rsp
  __int64 v20; // rax
  void *v21; // rsp
  __int64 v22; // rax
  signed __int64 v23; // rax
  void *v24; // rsp
  CAkPBI *v25; // r10
  void *v26; // rsp
  char *v27; // r13
  Gen3DParams *p_m_Params; // rbx
  CAkIndexable *PtrAndAddRef; // rax
  __int64 m_pAttenuation; // rdx
  unsigned __int8 v31; // al
  unsigned __int8 v32; // al
  unsigned int v33; // ebx
  int v34; // ebx
  bool v35; // zf
  AkFeedbackParams *m_pFeedbackInfo; // rdi
  float fConeInterp; // xmm9_4
  AkRayVolumeData *m_pItems; // rbx
  unsigned int v39; // r8d
  __int64 v40; // r12
  unsigned __int8 v41; // cl
  unsigned __int8 m_uListenerMask; // al
  float m; // xmm7_4
  __int64 v44; // r15
  CAkRegisteredObj *m_pGameObj; // rcx
  char *v46; // rsi
  __m128 *v47; // r13
  int m_ByteValue; // eax
  unsigned int v49; // ecx
  unsigned __int64 *v50; // rax
  AkDevice *v51; // r14
  AkDeviceInfo *v52; // rdi
  float v53; // xmm0_4
  float v54; // xmm6_4
  unsigned int in_uOutputConfig; // eax
  unsigned int v56; // r14d
  unsigned int v57; // eax
  float v58; // xmm0_4
  __int64 v59; // rdi
  unsigned __int8 v60; // r8
  char v61; // cl
  unsigned __int8 n; // al
  float v63; // xmm0_4
  int v64; // r8d
  __m128 *v65; // r15
  unsigned int ii; // edx
  __int64 v67; // rcx
  __int16 v68; // ax
  __m128 v69; // xmm0
  __m128 v70; // xmm3
  __m128 v71; // xmm0
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  char *v74; // rcx
  char *v75; // rdx
  __int64 v76; // r8
  __int128 v77; // xmm0
  unsigned int v78; // r9d
  __int64 v79; // rcx
  __int64 v80; // rax
  AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v81; // r14
  __int64 v82; // rcx
  AkRayVolumeData *v83; // rax
  int v84; // r12d
  __int64 v85; // r13
  unsigned __int8 v86; // cl
  unsigned __int8 i; // al
  __int64 v88; // r15
  AkDeviceInfo *m_pFirst; // rdi
  __int64 v90; // rdx
  unsigned int v91; // ecx
  unsigned __int64 *p_uDeviceID; // rax
  AkDevice *v93; // rsi
  AkSIMDSpeakerVolumes *v94; // r14
  float v95; // xmm0_4
  float v96; // xmm7_4
  float v97; // xmm0_4
  float theta; // xmm6_4
  unsigned int OutputConfig; // eax
  unsigned int v100; // eax
  __int64 v101; // rax
  __int64 v102; // rcx
  __int64 v103; // rdi
  unsigned __int8 v104; // r8
  char v105; // cl
  unsigned __int8 j; // al
  float fDryMixGain; // xmm0_4
  unsigned int v108; // r14d
  unsigned int k; // edx
  __int64 v110; // rcx
  int v111; // esi
  __int64 v112; // rcx
  float m_fConeLoPass; // xmm15_4
  float *v114; // rdx
  unsigned __int8 v115; // cl
  unsigned __int8 jj; // al
  AkDeviceInfo *v117; // rbx
  AkAudioMix *mxDirect; // rax
  __int64 v119; // rcx
  __m128 v120; // xmm0
  float v121; // xmm1_4
  float LPF; // xmm6_4
  float v123; // xmm0_4
  CAkEnvironmentsMgr *v124; // rdi
  float v125; // xmm0_4
  CAkOutputDevices *v126; // rdi
  unsigned int v127; // r13d
  AkDeviceInfo *kk; // rax
  unsigned int v129; // edx
  __int64 v130; // rcx
  float v131; // xmm11_4
  float fUserDefAuxMixGain; // xmm12_4
  float fGameDefAuxMixGain; // xmm13_4
  AkRayVolumeData *v134; // rdi
  __m128 v135; // xmm10
  AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v136; // r11
  AkRayVolumeData *v137; // rbx
  __int64 v138; // r15
  unsigned __int8 v139; // al
  unsigned __int8 mm; // r14
  __int64 v141; // rsi
  __int64 v142; // rcx
  AkDeviceInfo *v143; // rax
  float v144; // xmm6_4
  float v145; // xmm7_4
  float v146; // xmm8_4
  __int64 v147; // r12
  __int64 v148; // rsi
  __int64 v149; // r11
  int v150; // r9d
  AkRayVolumeData *v151; // r10
  unsigned int v152; // r8d
  __m128 v153; // xmm3
  __m128 *v154; // rdx
  __m128 v155; // xmm3
  __m128 v156; // xmm0
  __int64 v157; // rcx
  __m128 v158; // xmm1
  unsigned __int8 v159; // al
  char nn; // cl
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
  char i1; // cl
  AkRayVolumeData *v174; // r8
  __m128 v175; // xmm4
  __int64 v176; // r12
  AkRayVolumeData *v177; // rax
  __int64 v178; // rbx
  unsigned __int8 v179; // cl
  unsigned __int8 i2; // si
  AkDeviceInfo *v181; // r11
  AkDeviceInfo *v182; // rcx
  int v183; // edi
  unsigned int v184; // r9d
  __m128 *vector; // r8
  __m128 v186; // xmm0
  __m128 v187; // xmm1
  __int64 v188; // rdx
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
  __int64 v199; // rdx
  AkRayVolumeData *v200; // rcx
  unsigned __int8 v201; // cl
  char i3; // dl
  __int64 v203; // r12
  AkDeviceInfo *i5; // rbx
  __int64 v205; // rax
  unsigned __int64 *v206; // rcx
  unsigned int uListeners; // edx
  float v208; // xmm4_4
  AkRayVolumeData *v209; // r8
  unsigned __int8 v210; // cl
  char i4; // dl
  unsigned int v212; // r15d
  float v213; // xmm7_4
  unsigned int v214; // r14d
  CAkEnvironmentsMgr *v215; // rdi
  float v216; // xmm6_4
  float v217; // xmm0_4
  float v218; // xmm0_4
  AkDevice *in_pDevice; // [rsp+30h] [rbp-10h]
  char Dst[4]; // [rsp+40h] [rbp+0h] BYREF
  unsigned int in_uNumFullBandChannels; // [rsp+44h] [rbp+4h]
  int v222; // [rsp+48h] [rbp+8h]
  char *v223; // [rsp+50h] [rbp+10h]
  int v224; // [rsp+58h] [rbp+18h]
  int v225; // [rsp+5Ch] [rbp+1Ch]
  float *v226; // [rsp+60h] [rbp+20h]
  unsigned int out_index; // [rsp+68h] [rbp+28h] BYREF
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v228; // [rsp+70h] [rbp+30h]
  float *v229; // [rsp+78h] [rbp+38h]
  float *v230; // [rsp+80h] [rbp+40h]
  __m128 *v231; // [rsp+88h] [rbp+48h]
  int v232; // [rsp+90h] [rbp+50h]
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v233; // [rsp+98h] [rbp+58h]
  __int64 v234; // [rsp+A0h] [rbp+60h]
  Gen3DParams *v235; // [rsp+A8h] [rbp+68h]
  float in_fX[2]; // [rsp+B0h] [rbp+70h]
  __int64 v237; // [rsp+B8h] [rbp+78h]
  __int64 v238; // [rsp+C0h] [rbp+80h]
  __int64 v239; // [rsp+C8h] [rbp+88h]
  __int64 v240[4]; // [rsp+D0h] [rbp+90h]
  __int64 v241[4]; // [rsp+F0h] [rbp+B0h]
  __int64 v242[4]; // [rsp+110h] [rbp+D0h]
  char v243[256]; // [rsp+130h] [rbp+F0h] BYREF
  unsigned int in_uInputConfiga; // [rsp+338h] [rbp+2F8h] BYREF

  in_uInputConfiga = in_uInputConfig;
  v6 = 0;
  v8 = in_uInputConfig;
  v9 = 0;
  v222 = 0;
  if ( in_uInputConfig )
  {
    do
    {
      ++v9;
      v8 &= v8 - 1;
    }
    while ( v8 );
    v222 = v9;
  }
  m_uLength = in_arVolumeData->m_uLength;
  v11 = v9;
  v12 = in_pContext->m_BasePosParams.m_fCenterPCT * 0.0099999998;
  Dst[0] = (in_uInputConfig & 8) != 0;
  if ( (in_uInputConfig & 8) != 0 )
    v11 = v9 - 1;
  v13 = 32i64 * (unsigned int)(8 * m_uLength);
  in_uNumFullBandChannels = v11;
  v14 = v13 + 15;
  if ( v13 + 15 <= v13 )
    v14 = 0xFFFFFFFFFFFFFF0i64;
  v15 = alloca(v14 & 0xFFFFFFFFFFFFFFF0ui64);
  v16 = Dst;
  v223 = Dst;
  memset(Dst, 0, v13);
  v17 = 4 * m_uLength;
  v18 = 4 * m_uLength + 15;
  if ( v18 <= 4 * m_uLength )
    v18 = 0xFFFFFFFFFFFFFF0i64;
  v19 = alloca(v18 & 0xFFFFFFFFFFFFFFF0ui64);
  v229 = (float *)Dst;
  v20 = v17 + 15;
  if ( v17 + 15 <= v17 )
    v20 = 0xFFFFFFFFFFFFFF0i64;
  v21 = alloca(v20 & 0xFFFFFFFFFFFFFFF0ui64);
  v230 = (float *)Dst;
  v22 = v17 + 15;
  if ( v17 + 15 <= v17 )
    v22 = 0xFFFFFFFFFFFFFF0i64;
  v23 = v22 & 0xFFFFFFFFFFFFFFF0ui64;
  v24 = alloca(v23);
  v25 = in_pContext;
  v26 = alloca(v23);
  v27 = Dst;
  p_m_Params = &in_pContext->m_p3DSound->m_Params;
  v226 = (float *)Dst;
  v235 = p_m_Params;
  if ( !p_m_Params->m_pAttenuation )
  {
    PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                     (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                     p_m_Params->m_uAttenuationID);
    v25 = in_pContext;
    p_m_Params->m_pAttenuation = (CAkAttenuation *)PtrAndAddRef;
  }
  m_pAttenuation = (__int64)p_m_Params->m_pAttenuation;
  v228 = 0i64;
  v234 = m_pAttenuation;
  v233 = 0i64;
  if ( m_pAttenuation )
  {
    v31 = *(_BYTE *)(m_pAttenuation + 124);
    if ( v31 == 0xFF
      || (v228 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(16i64 * v31 + m_pAttenuation + 40),
          !v228->m_pArrayGraphPoints) )
    {
      v228 = 0i64;
    }
    v32 = *(_BYTE *)(m_pAttenuation + 123);
    if ( v32 == 0xFF
      || (v233 = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)(m_pAttenuation + 16i64 * v32 + 40),
          !v233->m_pArrayGraphPoints) )
    {
      v233 = 0i64;
    }
  }
  v33 = *((unsigned __int8 *)v25 + 371);
  v225 = 0;
  v34 = (v33 >> 2) & 3;
  v35 = (*((_BYTE *)v25 + 374) & 0x40) == 0;
  v232 = v34;
  if ( v35 )
  {
    CAkPBI::ValidateFeedbackParameters(v25);
    v25 = in_pContext;
  }
  m_pFeedbackInfo = v25->m_pFeedbackInfo;
  v231 = (__m128 *)m_pFeedbackInfo;
  if ( m_pFeedbackInfo )
  {
    AkFeedbackParams::ZeroNewVolumes(m_pFeedbackInfo);
    AkFeedbackParams::ZeroNewAttenuations(m_pFeedbackInfo);
    v25 = in_pContext;
  }
  fConeInterp = *(float *)&FLOAT_1_0;
  v35 = v34 == 1;
  m_pItems = in_arVolumeData->m_pItems;
  if ( !v35 )
  {
    v84 = 0;
    while ( 1 )
    {
      v85 = v6;
      v86 = 0;
      v226[v6] = 0.0;
      for ( i = m_pItems->m_uListenerMask; (i & 1) == 0; ++v86 )
        i >>= 1;
      v88 = v86;
      m_pFirst = in_deviceVolumes->m_listDeviceVolumes.m_pFirst;
      v90 = *((_QWORD *)&CAkListener::m_listeners + 18 * v86 + 15);
      if ( in_deviceVolumes->m_listDeviceVolumes.m_pFirst )
      {
        while ( m_pFirst->uDeviceID != v90 )
        {
          m_pFirst = m_pFirst->pNextLightItem;
          if ( !m_pFirst )
            goto LABEL_100;
        }
      }
      else
      {
LABEL_100:
        m_pFirst = 0i64;
      }
      v91 = 0;
      if ( CAkOutputMgr::m_Devices.m_uLength )
      {
        p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
        while ( *p_uDeviceID != v90 )
        {
          ++v91;
          p_uDeviceID += 10;
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
      v94 = (AkSIMDSpeakerVolumes *)&v223[32 * v84];
      if ( v93 && m_pFirst )
      {
        if ( (*((_BYTE *)v235 + 68) & 1) != 0 )
        {
          if ( v233 )
          {
            v95 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                    v233,
                    m_pItems->r,
                    0,
                    &out_index);
            v226[v85] = v95;
          }
          if ( in_uNumFullBandChannels )
          {
            v96 = 0.0;
            if ( v228 )
            {
              v97 = cosf(m_pItems->phi);
              v96 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                      v228,
                      v97 * m_pItems->r,
                      0,
                      &out_index);
            }
            theta = m_pItems->theta;
            OutputConfig = AkDeviceInfo::GetOutputConfig(m_pFirst);
            CAkSpeakerPan::GetSpeakerVolumesPlane(theta, v12, v96, v94, in_uNumFullBandChannels, OutputConfig, v93);
          }
        }
        else
        {
          v100 = AkDeviceInfo::GetOutputConfig(m_pFirst);
          CAkSpeakerPan::GetSpeakerVolumes2DPan(0.5, 0.5, v12, 1, in_uInputConfiga, v100, v94);
        }
        if ( Dst[0] )
        {
          v101 = (__int64)v223;
          v102 = 32i64 * (unsigned int)(v84 + v222 - 1);
          *(_OWORD *)&v223[v102] = 0i64;
          *(_OWORD *)(v102 + v101 + 16) = 0i64;
          *(_DWORD *)(v102 + v101 + 28) = 1065353216;
        }
      }
      v103 = (__int64)v231;
      if ( !v231 || ((1 << v88) & CAkListener::m_uFeedbackMask) == 0 )
        goto LABEL_133;
      v104 = CAkFeedbackDeviceMgr::s_pSingleton->m_uPlayerMask & CAkFeedbackDeviceMgr::s_pSingleton->m_aListenerToPlayer[v88];
      if ( v104 )
      {
        v105 = 1;
        for ( j = 0; j < 4u; ++j )
        {
          if ( ((unsigned __int8)v105 & v104) != 0 )
          {
            fDryMixGain = m_pItems->fDryMixGain;
            if ( fDryMixGain <= *(float *)(v103 + 4i64 * j + 32) )
              fDryMixGain = *(float *)(v103 + 4i64 * j + 32);
            *(float *)(v103 + 4i64 * j + 32) = fDryMixGain;
          }
          v105 *= 2;
        }
      }
      if ( ((1 << v88) & CAkListener::m_uAudioMask) == 0 || *((char *)in_pContext + 374) < 0 )
      {
        v108 = in_uNumFullBandChannels;
        v65 = (__m128 *)v223;
        for ( k = 0; k < v108; *(__m128 *)((char *)&v65[1] + v110) = 0i64 )
        {
          v110 = v84 + k++;
          v110 *= 32i64;
          *(__m128 *)((char *)v65 + v110) = 0i64;
        }
      }
      else
      {
LABEL_133:
        v65 = (__m128 *)v223;
      }
      v81 = in_arVolumeData;
      v111 = v225;
      v229[v85] = 0.0;
      v6 = v111 + 1;
      v230[v85] = 0.0;
      ++m_pItems;
      v84 += 8;
      v112 = (__int64)&v81->m_pItems[v81->m_uLength];
      v225 = v6;
      if ( m_pItems == (AkRayVolumeData *)v112 )
      {
        v78 = v222;
        goto LABEL_136;
      }
    }
  }
  v39 = 0;
  v224 = 0;
  while ( 1 )
  {
    v40 = v6;
    v41 = 0;
    *(_DWORD *)&v27[4 * v6] = 0;
    m_uListenerMask = m_pItems->m_uListenerMask;
    for ( m = 0.0; (m_uListenerMask & 1) == 0; ++v41 )
      m_uListenerMask >>= 1;
    v44 = v41;
    m_pGameObj = v25->m_pGameObj;
    v46 = &v16[32 * v39];
    v47 = (__m128 *)(&CAkListener::m_listeners + 9 * v44);
    v229[v40] = (float)(unsigned __int8)m_pGameObj->m_fOcclusionValue[v44].m_ByteValue * 0.0039215689;
    m_ByteValue = (unsigned __int8)m_pGameObj->m_fObstructionValue[v44].m_ByteValue;
    v49 = 0;
    v230[v40] = (float)m_ByteValue * 0.0039215689;
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
      if ( (*((_BYTE *)v235 + 68) & 1) == 0 )
      {
        v57 = AkDeviceInfo::GetOutputConfig(v52);
        CAkSpeakerPan::GetSpeakerVolumes2DPan(0.5, 0.5, v12, 1, in_uInputConfiga, v57, (AkSIMDSpeakerVolumes *)v46);
LABEL_51:
        v56 = in_uNumFullBandChannels;
        goto LABEL_52;
      }
      if ( v228 )
      {
        v53 = cosf(m_pItems->phi);
        m = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
              v228,
              v53 * m_pItems->r,
              0,
              &out_index);
      }
      v54 = m_pItems->theta;
      in_uOutputConfig = AkDeviceInfo::GetOutputConfig(v52);
      in_pDevice = v51;
      v56 = in_uNumFullBandChannels;
      CAkSpeakerPan::GetSpeakerVolumesPlane(
        v54,
        v12,
        m,
        (AkSIMDSpeakerVolumes *)v46,
        in_uNumFullBandChannels,
        in_uOutputConfig,
        in_pDevice);
    }
    else
    {
      *(_OWORD *)v46 = 0i64;
      *((_OWORD *)v46 + 1) = 0i64;
      v68 = AkDeviceInfo::GetOutputConfig(v52);
      if ( (v68 & 1) != 0 )
        *(_DWORD *)v46 = 1065353216;
      if ( (v68 & 2) != 0 )
        *((_DWORD *)v46 + 1) = 1065353216;
      if ( (v68 & 4) != 0 )
        *((_DWORD *)v46 + 2) = 1065353216;
      if ( (v68 & 0x10) != 0 )
        *((_DWORD *)v46 + 3) = 1065353216;
      if ( (v68 & 0x20) != 0 )
        *((_DWORD *)v46 + 4) = 1065353216;
      if ( (v68 & 0x200) != 0 )
        *((_DWORD *)v46 + 5) = 1065353216;
      if ( (v68 & 0x400) != 0 )
        *((_DWORD *)v46 + 6) = 1065353216;
      v56 = in_uNumFullBandChannels;
      v69 = 0i64;
      v70 = (__m128)(unsigned int)FLOAT_1_0;
      v69.m128_f32[0] = (float)(int)in_uNumFullBandChannels;
      v70.m128_f32[0] = 1.0 / _mm_sqrt_ps(v69).m128_f32[0];
      v71 = _mm_shuffle_ps(v70, v70, 0);
      v72 = _mm_mul_ps(v71, *((__m128 *)v46 + 1));
      v73 = _mm_mul_ps(v71, *(__m128 *)v46);
      *((__m128 *)v46 + 1) = v72;
      *(__m128 *)v46 = v73;
      if ( v56 > 1 )
      {
        v74 = v46 + 32;
        v75 = v46;
        v76 = v56 - 1;
        do
        {
          v77 = *(_OWORD *)v75;
          v74 += 32;
          v75 += 32;
          *((_OWORD *)v74 - 2) = v77;
          *((_OWORD *)v74 - 1) = *((_OWORD *)v75 - 1);
          --v76;
        }
        while ( v76 );
      }
    }
LABEL_52:
    if ( v233 )
    {
      v58 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(v233, m_pItems->r, 0, &out_index);
      v226[v40] = v58;
    }
    v59 = (__int64)v231;
    if ( !v231 || ((1 << v44) & CAkListener::m_uFeedbackMask) == 0 )
      goto LABEL_86;
    v60 = CAkFeedbackDeviceMgr::s_pSingleton->m_uPlayerMask & CAkFeedbackDeviceMgr::s_pSingleton->m_aListenerToPlayer[v44];
    if ( v60 )
    {
      v61 = 1;
      for ( n = 0; n < 4u; ++n )
      {
        if ( ((unsigned __int8)v61 & v60) != 0 )
        {
          v63 = m_pItems->fDryMixGain;
          if ( v63 <= *(float *)(v59 + 4i64 * n + 32) )
            v63 = *(float *)(v59 + 4i64 * n + 32);
          *(float *)(v59 + 4i64 * n + 32) = v63;
        }
        v61 *= 2;
      }
    }
    if ( ((1 << v44) & CAkListener::m_uAudioMask) == 0 || *((char *)in_pContext + 374) < 0 )
    {
      v64 = v224;
      v65 = (__m128 *)v223;
      for ( ii = 0; ii < v56; *(__m128 *)((char *)&v65[1] + v67) = 0i64 )
      {
        v67 = v64 + ii++;
        v67 *= 32i64;
        *(__m128 *)((char *)v65 + v67) = 0i64;
      }
    }
    else
    {
LABEL_86:
      v64 = v224;
      v65 = (__m128 *)v223;
    }
    v78 = v222;
    if ( Dst[0] )
    {
      v79 = 2i64 * (unsigned int)(v64 + v222 - 1);
      v65[v79] = 0i64;
      v65[v79 + 1] = 0i64;
      v65[v79 + 1].m128_i32[3] = 1065353216;
    }
    if ( v78 )
    {
      v80 = v78;
      do
      {
        v46 += 32;
        *((__m128 *)v46 - 2) = _mm_mul_ps(v47[3], *((__m128 *)v46 - 2));
        *((__m128 *)v46 - 1) = _mm_mul_ps(v47[4], *((__m128 *)v46 - 1));
        --v80;
      }
      while ( v80 );
    }
    v81 = in_arVolumeData;
    v39 = v64 + 8;
    v6 = v225 + 1;
    ++m_pItems;
    v82 = in_arVolumeData->m_uLength;
    v83 = in_arVolumeData->m_pItems;
    ++v225;
    v224 = v39;
    if ( m_pItems == &v83[v82] )
      break;
    v16 = v223;
    v27 = (char *)v226;
    v25 = in_pContext;
  }
  fConeInterp = *(float *)&FLOAT_1_0;
LABEL_136:
  if ( v234 && (*(_BYTE *)(v234 + 125) & 1) != 0 )
    m_fConeLoPass = v235->m_fConeLoPass;
  else
    m_fConeLoPass = 0.0;
  if ( v81->m_uLength == 1 )
  {
    v114 = (float *)&v81->m_pItems->AkPolarCoord;
    v115 = 0;
    for ( jj = v81->m_pItems->m_uListenerMask; (jj & 1) == 0; ++v115 )
      jj >>= 1;
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
        mxDirect = v117->mxDirect;
        v119 = v78;
        do
        {
          v120 = *v65;
          ++mxDirect;
          v65 += 2;
          mxDirect[-1].Next.vector[0] = v120;
          mxDirect[-1].Next.vector[1] = v65[-1];
          --v119;
        }
        while ( v119 );
      }
      v121 = in_fBehavioralVolume;
      v117->mxAttenuations.dry.fNext = in_fBehavioralVolume * v114[5];
      if ( in_bIsAuxRoutable )
      {
        v117->mxAttenuations.gameDef.fNext = v121 * v114[6];
        v117->mxAttenuations.userDef.fNext = v121 * v114[7];
      }
      else
      {
        v117->mxAttenuations.gameDef.fNext = 0.0;
        v117->mxAttenuations.userDef.fNext = 0.0;
      }
      LPF = in_pContext->m_EffectiveParams.LPF;
      if ( LPF <= *v226 )
        LPF = *v226;
      if ( m_fConeLoPass > 0.0 )
      {
        v123 = AkMath::Interpolate(0.0, 0.0, fConeInterp, m_fConeLoPass, v114[8]);
        if ( LPF <= v123 )
          LPF = v123;
      }
      if ( v232 == 1 )
      {
        v124 = g_pEnvironmentMgr;
        if ( g_pEnvironmentMgr->m_bCurveEnabled[1][1] )
        {
          if ( g_pEnvironmentMgr->ConversionTable[1][1].m_pArrayGraphPoints )
          {
            v125 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                     &g_pEnvironmentMgr->ConversionTable[1][1],
                     *v229 * 100.0,
                     0,
                     &in_uInputConfiga);
            if ( LPF <= v125 )
              LPF = v125;
          }
        }
        if ( v124->m_bCurveEnabled[0][1] )
        {
          if ( v124->ConversionTable[0][1].m_pArrayGraphPoints )
            v117->fObsLPF = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                              &v124->ConversionTable[0][1],
                              *v230 * 100.0,
                              0,
                              &in_uInputConfiga);
        }
      }
      v117->fLPF = LPF;
    }
  }
  else
  {
    v126 = in_deviceVolumes;
    v127 = v222;
    for ( kk = in_deviceVolumes->m_listDeviceVolumes.m_pFirst; kk; kk = kk->pNextLightItem )
    {
      v129 = 0;
      do
      {
        v130 = v129++;
        v130 <<= 6;
        *(__m128 *)((char *)kk->mxDirect[0].Next.vector + v130) = 0i64;
        *(_OWORD *)((char *)&kk->mxDirect[0].Next.aVolumes[4] + v130) = 0i64;
      }
      while ( v129 < v127 );
      kk->mxAttenuations.dry.fNext = 0.0;
      kk->mxAttenuations.userDef.fNext = 0.0;
      kk->mxAttenuations.gameDef.fNext = 0.0;
    }
    v131 = 0.0;
    *(_QWORD *)in_fX = 0x3F8000003F800000i64;
    v237 = 0x3F8000003F800000i64;
    v238 = 0x3F8000003F800000i64;
    fUserDefAuxMixGain = 0.0;
    fGameDefAuxMixGain = 0.0;
    v239 = 0x3F8000003F800000i64;
    v241[0] = 0x3F8000003F800000i64;
    v241[1] = 0x3F8000003F800000i64;
    v241[2] = 0x3F8000003F800000i64;
    v241[3] = 0x3F8000003F800000i64;
    v240[0] = 0x3F8000003F800000i64;
    v240[1] = 0x3F8000003F800000i64;
    v240[2] = 0x3F8000003F800000i64;
    v240[3] = 0x3F8000003F800000i64;
    v242[0] = 0x42C8000042C80000i64;
    v242[1] = 0x42C8000042C80000i64;
    v242[2] = 0x42C8000042C80000i64;
    v242[3] = 0x42C8000042C80000i64;
    if ( CAkPBI::IsMultiPositionTypeMultiSources(in_pContext) )
    {
      v134 = v81->m_pItems;
      v135 = (__m128)LODWORD(in_fBehavioralVolume);
      v136 = in_arVolumeData;
      v137 = v81->m_pItems;
      v138 = 0i64;
      do
      {
        v139 = v137->m_uListenerMask;
        for ( mm = 0; (v139 & 1) == 0; ++mm )
          v139 >>= 1;
        v141 = 0i64;
        v234 = mm;
        v231 = 0i64;
        v142 = *((_QWORD *)&CAkListener::m_listeners + 18 * mm + 15);
        v143 = in_deviceVolumes->m_listDeviceVolumes.m_pFirst;
        if ( in_deviceVolumes->m_listDeviceVolumes.m_pFirst )
        {
          while ( !v141 )
          {
            if ( v143->uDeviceID == v142 )
              v141 = (__int64)v143;
            v143 = v143->pNextLightItem;
            v231 = (__m128 *)v141;
            if ( !v143 )
            {
              if ( !v141 )
                goto LABEL_216;
              break;
            }
          }
          v144 = FLOAT_100_0;
          v145 = fConeInterp;
          v146 = fConeInterp;
          memset(v243, 0, sizeof(v243));
          v147 = (__int64)v223;
          v148 = (__int64)v230;
          v149 = (__int64)v226;
          v150 = 8 * v138;
          v151 = &v134[in_arVolumeData->m_uLength];
          do
          {
            v152 = 0;
            if ( v127 )
            {
              v153 = v135;
              v154 = (__m128 *)v243;
              v153.m128_f32[0] = v135.m128_f32[0] * v137->fDryMixGain;
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
            if ( v137->fDryMixGain > v131 )
              v131 = v137->fDryMixGain;
            if ( in_bIsAuxRoutable )
            {
              if ( v137->fUserDefAuxMixGain > fUserDefAuxMixGain )
                fUserDefAuxMixGain = v137->fUserDefAuxMixGain;
              if ( v137->fGameDefAuxMixGain > fGameDefAuxMixGain )
                fGameDefAuxMixGain = v137->fGameDefAuxMixGain;
            }
            if ( v144 >= *(float *)(v149 + 4 * v138) )
              v144 = *(float *)(v149 + 4 * v138);
            if ( v145 >= v229[v138] )
              v145 = v229[v138];
            if ( v146 >= *(float *)(v148 + 4 * v138) )
              v146 = *(float *)(v148 + 4 * v138);
            if ( fConeInterp >= v137->fConeInterp )
              fConeInterp = v137->fConeInterp;
            ++v137;
            v138 = (unsigned int)(v138 + 1);
            v150 += 8;
            if ( v137 == v151 )
              break;
            v159 = v137->m_uListenerMask;
            for ( nn = 0; (v159 & 1) == 0; ++nn )
              v159 >>= 1;
          }
          while ( nn == mm );
          v161 = v234;
          v136 = in_arVolumeData;
          if ( v127 )
          {
            v162 = v243;
            v163 = v231 + 1;
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
          v168 = *((float *)v242 + v161);
          if ( v168 >= v144 )
            v168 = v144;
          *((float *)v242 + v161) = v168;
          v169 = *((float *)v240 + v161);
          if ( v169 >= v145 )
            v169 = v145;
          *((float *)v240 + v161) = v169;
          v170 = *((float *)v241 + v161);
          if ( v170 >= v146 )
            v170 = v146;
          *((float *)v241 + v161) = v170;
          v171 = in_fX[v161];
          if ( v171 >= fConeInterp )
            v171 = fConeInterp;
          in_fX[v161] = v171;
        }
        else
        {
          do
          {
LABEL_216:
            ++v137;
            v138 = (unsigned int)(v138 + 1);
            if ( v137 == &v134[v136->m_uLength] )
              break;
            v172 = v137->m_uListenerMask;
            for ( i1 = 0; (v172 & 1) == 0; ++i1 )
              v172 >>= 1;
          }
          while ( i1 == mm );
        }
        v134 = v136->m_pItems;
        fConeInterp = *(float *)&FLOAT_1_0;
      }
      while ( v137 != &v136->m_pItems[v136->m_uLength] );
    }
    else
    {
      v174 = v81->m_pItems;
      v175 = (__m128)LODWORD(in_fBehavioralVolume);
      v176 = (__int64)v226;
      v177 = v81->m_pItems;
      v178 = 0i64;
      do
      {
        v179 = v177->m_uListenerMask;
        for ( i2 = 0; (v179 & 1) == 0; ++i2 )
          v179 >>= 1;
        v181 = 0i64;
        v182 = v126->m_listDeviceVolumes.m_pFirst;
        if ( v126->m_listDeviceVolumes.m_pFirst )
        {
          while ( !v181 )
          {
            if ( v182->uDeviceID == *((_QWORD *)&CAkListener::m_listeners + 18 * i2 + 15) )
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
              vector = v181->mxDirect[0].Next.vector;
              do
              {
                v186 = *vector;
                v187 = v175;
                v188 = 2i64 * (v184 + v183);
                ++v184;
                vector += 4;
                v187.m128_f32[0] = v175.m128_f32[0] * v177->fDryMixGain;
                v189 = _mm_shuffle_ps(v187, v187, 0);
                v190 = _mm_max_ps(v186, _mm_mul_ps(v65[v188], v189));
                v191 = _mm_max_ps(vector[-3], _mm_mul_ps(v65[v188 + 1], v189));
                vector[-4] = v190;
                vector[-3] = v191;
              }
              while ( v184 < v127 );
            }
            if ( v177->fDryMixGain > v131 )
              v131 = v177->fDryMixGain;
            if ( in_bIsAuxRoutable )
            {
              if ( v177->fUserDefAuxMixGain > fUserDefAuxMixGain )
                fUserDefAuxMixGain = v177->fUserDefAuxMixGain;
              if ( v177->fGameDefAuxMixGain > fGameDefAuxMixGain )
                fGameDefAuxMixGain = v177->fGameDefAuxMixGain;
            }
            v192 = *((float *)v242 + i2);
            if ( v192 >= *(float *)(v176 + 4 * v178) )
              v192 = *(float *)(v176 + 4 * v178);
            v193 = (__int64)v229;
            v194 = *((float *)v240 + i2);
            *((float *)v242 + i2) = v192;
            if ( v194 >= *(float *)(v193 + 4 * v178) )
              v194 = *(float *)(v193 + 4 * v178);
            v195 = (__int64)v230;
            v196 = *((float *)v241 + i2);
            *((float *)v240 + i2) = v194;
            if ( v196 >= *(float *)(v195 + 4 * v178) )
              v196 = *(float *)(v195 + 4 * v178);
            v197 = v177->fConeInterp;
            v198 = in_fX[i2];
            *((float *)v241 + i2) = v196;
            if ( v198 >= v197 )
              v198 = v197;
            ++v177;
            v178 = (unsigned int)(v178 + 1);
            v199 = v81->m_uLength;
            v200 = v81->m_pItems;
            v183 += 8;
            in_fX[i2] = v198;
            if ( v177 == &v200[v199] )
              break;
            v201 = v177->m_uListenerMask;
            for ( i3 = 0; (v201 & 1) == 0; ++i3 )
              v201 >>= 1;
          }
          while ( i3 == i2 );
          v126 = in_deviceVolumes;
        }
        else
        {
LABEL_265:
          v209 = &v174[v81->m_uLength];
          do
          {
            ++v177;
            v178 = (unsigned int)(v178 + 1);
            if ( v177 == v209 )
              break;
            v210 = v177->m_uListenerMask;
            for ( i4 = 0; (v210 & 1) == 0; ++i4 )
              v210 >>= 1;
          }
          while ( i4 == i2 );
        }
        v174 = v81->m_pItems;
      }
      while ( v177 != &v81->m_pItems[v81->m_uLength] );
    }
    v203 = v232;
    for ( i5 = in_deviceVolumes->m_listDeviceVolumes.m_pFirst; i5; i5 = i5->pNextLightItem )
    {
      v205 = 0i64;
      if ( CAkOutputMgr::m_Devices.m_uLength )
      {
        v206 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
        while ( *v206 != i5->uDeviceID )
        {
          v205 = (unsigned int)(v205 + 1);
          v206 += 10;
          if ( (unsigned int)v205 >= CAkOutputMgr::m_Devices.m_uLength )
            goto LABEL_261;
        }
        uListeners = CAkOutputMgr::m_Devices.m_pItems[v205].uListeners;
      }
      else
      {
LABEL_261:
        LOBYTE(uListeners) = 0;
      }
      i5->mxAttenuations.dry.fNext = 1.0;
      if ( in_bIsAuxRoutable && v131 > 0.0 )
      {
        v208 = *(float *)&FLOAT_1_0;
        i5->mxAttenuations.gameDef.fNext = fGameDefAuxMixGain * (float)(1.0 / v131);
        i5->mxAttenuations.userDef.fNext = fUserDefAuxMixGain * (float)(1.0 / v131);
      }
      else
      {
        v208 = *(float *)&FLOAT_1_0;
        i5->mxAttenuations.gameDef.fNext = 0.0;
        i5->mxAttenuations.userDef.fNext = 0.0;
      }
      v212 = 0;
      v213 = FLOAT_100_0;
      v214 = uListeners & in_pContext->m_pGameObj->m_PosKeep.m_uListenerMask;
      if ( ((unsigned __int8)uListeners & in_pContext->m_pGameObj->m_PosKeep.m_uListenerMask) != 0 )
      {
        v215 = g_pEnvironmentMgr;
        do
        {
          if ( (v214 & 1) != 0 )
          {
            v216 = *((float *)v242 + v212);
            if ( m_fConeLoPass > 0.0 )
            {
              v217 = AkMath::Interpolate(0.0, 0.0, v208, m_fConeLoPass, in_fX[v212]);
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
                           *((float *)v240 + v212) * 100.0,
                           0,
                           &in_uInputConfiga);
                  if ( v216 <= v218 )
                    v216 = v218;
                }
              }
              if ( v215->m_bCurveEnabled[0][1] && v215->ConversionTable[0][1].m_pArrayGraphPoints )
              {
                i5->fObsLPF = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                                &v215->ConversionTable[0][1],
                                *((float *)v241 + v212) * 100.0,
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
      if ( v213 <= in_pContext->m_EffectiveParams.LPF )
        v213 = in_pContext->m_EffectiveParams.LPF;
      i5->fLPF = v213;
    }
  }
}Params.LPF )
        v213 = in_pContext->m_EffectiveParams.LPF;
      i5->fLPF = v213;
    }
  }
}

// File Line: 904
// RVA: 0xA69570
void __fastcall CAkListener::DoSpeakerVolumeMatrixCallback(
        unsigned int in_playingID,
        __int64 in_uNumChannels,
        unsigned int in_uInputConfig,
        unsigned int in_uOutputConfig,
        AkDeviceInfo *io_rDeviceVolume)
{
  __int64 v5; // r10
  AkSpeakerVolumes **pVolumes; // rax
  AkAudioMix *mxDirect; // rdi
  AkSpeakerVolumeMatrixCallbackInfo in_pInfo; // [rsp+20h] [rbp-88h] BYREF

  v5 = 0i64;
  if ( (_DWORD)in_uNumChannels )
  {
    v5 = (unsigned int)in_uNumChannels;
    pVolumes = in_pInfo.pVolumes;
    mxDirect = io_rDeviceVolume->mxDirect;
    in_uNumChannels = (unsigned int)in_uNumChannels;
    do
    {
      *pVolumes++ = (AkSpeakerVolumes *)mxDirect++;
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
void __fastcall CAkListener::GetListenerVolume(
        CAkAttenuation *in_pAttenuation,
        AkEmitterListenerPair *in_ray,
        float in_fConeOutsideVolume,
        float *out_fMinCone,
        float *out_fListenerVolumeDry,
        float *out_fListenerVolumeGameDefAux,
        float *out_fListenerVolumeUserDefAux)
{
  unsigned __int8 v10; // al
  float r; // xmm7_4
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
  unsigned int out_index; // [rsp+80h] [rbp+8h] BYREF

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
  r = in_ray->r;
  if ( v10 == 0xFF || (v12 = v10, v13 = &in_pAttenuation->m_curves[v12], !v13->m_pArrayGraphPoints) )
  {
    v13 = 0i64;
  }
  else if ( v13 )
  {
    v14 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
            &in_pAttenuation->m_curves[v12],
            in_ray->r,
            0,
            &out_index);
    goto LABEL_8;
  }
  v14 = *(float *)&FLOAT_1_0;
LABEL_8:
  v15 = out_fListenerVolumeDry;
  *out_fListenerVolumeDry = v14;
  v16 = in_pAttenuation->m_curveToUse[1];
  if ( v16 == 0xFF || (v17 = &in_pAttenuation->m_curves[v16], !v17->m_pArrayGraphPoints) )
    v17 = 0i64;
  if ( v17 == v13 )
  {
    *out_fListenerVolumeGameDefAux = v14;
  }
  else if ( v17 )
  {
    v18 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(v17, r, 0, &out_index);
    *out_fListenerVolumeGameDefAux = v18;
  }
  else
  {
    *out_fListenerVolumeGameDefAux = 1.0;
  }
  v19 = in_pAttenuation->m_curveToUse[2];
  if ( v19 == 0xFF || (v20 = &in_pAttenuation->m_curves[v19], !v20->m_pArrayGraphPoints) )
    v20 = 0i64;
  if ( v20 == v13 )
  {
    *out_fListenerVolumeUserDefAux = v14;
  }
  else if ( v20 )
  {
    v21 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(v20, r, 0, &out_index);
    *out_fListenerVolumeUserDefAux = v21;
  }
  else
  {
    *out_fListenerVolumeUserDefAux = 1.0;
  }
  if ( (*((_BYTE *)in_pAttenuation + 125) & 1) != 0 )
    *v15 = CAkListener::ComputeConeAttenuation(
             in_pAttenuation->m_ConeParams.fInsideAngle,
             in_pAttenuation->m_ConeParams.fOutsideAngle,
             in_fConeOutsideVolume,
             in_ray->fEmitterAngle,
             out_fMinCone)
         * *v15;
  else
    *out_fMinCone = 1.0;
}

