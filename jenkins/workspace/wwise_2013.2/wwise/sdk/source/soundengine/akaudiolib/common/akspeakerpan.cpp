// File Line: 40
// RVA: 0xA4F0E0
void CAkSpeakerPan::Init(void)
{
  int v0; // ebx
  double *v1; // rdi
  double v2; // xmm0_8
  double v3; // xmm0_8
  float *v4; // rdi
  double v5; // xmm0_8

  v0 = 0;
  v1 = (double *)CAkSpeakerPan::m_fSin2;
  do
  {
    v2 = _vdecl_sin2();
    *v1 = v2 * v2;
    v3 = _vdecl_sin2();
    v0 += 4;
    v1 += 2;
    *(v1 - 1) = v3 * v3;
  }
  while ( v0 < 128 );
  if ( v0 < 129 )
  {
    v4 = &CAkSpeakerPan::m_fSin2[v0];
    do
    {
      v5 = sin((double)v0++ * 0.01227184664458036);
      ++v4;
      *(float *)&v5 = v5 * v5;
      *(v4 - 1) = *(float *)&v5;
    }
    while ( v0 < 129 );
  }
}

// File Line: 53
// RVA: 0xA4DEE0
void __fastcall CAkSpeakerPan::CreatePanCache(
        unsigned int in_uOutputConfig,
        unsigned int *in_uSpeakerAngles,
        CAkSpeakerPan::PanPair *io_pPanPairs)
{
  unsigned int v5; // ebp
  unsigned int v6; // r8d
  int v7; // r12d
  bool v8; // al
  unsigned int v9; // r14d
  __int64 v10; // rbx
  unsigned int v11; // ebp
  float v12; // xmm0_4
  float v13; // xmm8_4
  signed int *v14; // r13
  float v15; // xmm9_4
  float v16; // xmm10_4
  float v17; // xmm13_4
  signed int v18; // edi
  __m128i v19; // xmm8
  int v20; // edx
  signed int v21; // eax
  float v22; // xmm14_4
  float v23; // xmm15_4
  __int128 v24; // xmm7
  float v25; // xmm6_4
  float v26; // xmm12_4
  float v27; // xmm0_4
  float v28; // xmm10_4
  __int128 v29; // xmm0
  __int128 v30; // xmm13
  float v31; // xmm6_4
  __int128 v32; // xmm0
  __int128 v33; // xmm4
  __int128 v34; // xmm1
  __int128 v35; // xmm3
  float v36; // xmm2_4
  float v37; // xmm2_4
  __int64 v38; // r8
  CAkSpeakerPan::PanPair *v39; // rdx
  float *p_fGain_i; // r9
  unsigned __int64 v41; // rcx
  CAkSpeakerPan::PanPair *v42; // r10
  CAkSpeakerPan::PanPair *v43; // rdx
  float *v44; // rcx
  float v45; // [rsp+F0h] [rbp+8h]

  v5 = 0;
  v6 = in_uOutputConfig & 0xFFFFFFF3;
  if ( (in_uOutputConfig & 0xFFFFFFF3) != 0 )
  {
    do
    {
      ++v5;
      v6 &= v6 - 1;
    }
    while ( v6 );
  }
  v7 = 0;
  v8 = (in_uOutputConfig & 4) != 0;
  v9 = 0;
  v10 = 0i64;
  LOBYTE(v45) = v8;
  v11 = (v5 >> 1) + 1;
  if ( v11 )
  {
    v12 = FLOAT_0_5;
    v13 = v45;
    v14 = (signed int *)in_uSpeakerAngles;
    v15 = v45;
    v16 = FLOAT_6_2831855;
    v17 = FLOAT_0_012271847;
    while ( !v9 )
    {
      v18 = *in_uSpeakerAngles;
      if ( v8 )
      {
        v13 = (float)((float)((float)v18 * v16) * 0.001953125) * v12;
        v15 = v13;
        goto LABEL_15;
      }
      if ( (unsigned int)v18 < 0x80 )
      {
        v19 = _mm_cvtsi32_si128(v18);
        v15 = 0.0;
LABEL_14:
        v13 = (float)(_mm_cvtepi32_ps(v19).m128_f32[0] * v16) * 0.001953125;
      }
LABEL_15:
      v22 = sinf(v13);
      v23 = cosf(v13);
      v24 = COERCE_UNSIGNED_INT((float)v7);
      *(float *)&v24 = (float)((float)((float)(*(float *)&v24 * v16) * 0.001953125) - v15) - 0.036815539;
      v25 = *(float *)&v24 + v17;
      v26 = cosf(v17) * 2.0;
      v27 = sinf(*(float *)&v24 + v17);
      *(float *)&v24 = *(float *)&v24 + 0.024543693;
      v28 = v27;
      v29 = v24;
      *(float *)&v29 = sinf(*(float *)&v24);
      v30 = v29;
      v31 = cosf(v25);
      v32 = v24;
      *(float *)&v32 = cosf(*(float *)&v24);
      v33 = v32;
      do
      {
        v34 = v33;
        v35 = v30;
        ++v10;
        ++v7;
        *(float *)&v34 = (float)(*(float *)&v33 * v26) - v31;
        *(float *)&v35 = (float)(*(float *)&v30 * v26) - v28;
        v31 = *(float *)&v33;
        v28 = *(float *)&v30;
        v33 = v34;
        v30 = v35;
        *(float *)&v34 = *(float *)&v34 * v22;
        *(float *)&v35 = *(float *)&v35 * v23;
        v36 = *(float *)&v34 - *(float *)&v35;
        *(float *)&v35 = (float)(*(float *)&v35 + *(float *)&v34) * (float)(*(float *)&v35 + *(float *)&v34);
        v37 = v36 * v36;
        *(float *)&v34 = 1.0 / (float)(*(float *)&v35 + v37);
        io_pPanPairs[v10 - 1].fGain_i = *(float *)&v34 * *(float *)&v35;
        io_pPanPairs[v10 - 1].fGain_i_minus_1 = *(float *)&v34 * v37;
      }
      while ( v10 <= v18 );
      v16 = FLOAT_6_2831855;
      v12 = FLOAT_0_5;
      v17 = FLOAT_0_012271847;
      v8 = LOBYTE(v45);
      ++v9;
      ++v14;
      if ( v9 >= v11 )
        return;
    }
    v20 = in_uSpeakerAngles[v9 - 1];
    if ( v9 < v11 - 1 )
    {
      v18 = *v14;
      v13 = (float)((float)((float)(*v14 - v20) * v16) * 0.001953125) * v12;
      v15 = v13 + (float)((float)((float)v20 * v16) * 0.001953125);
      goto LABEL_15;
    }
    v21 = 256 - v20;
    if ( v20 <= 128 )
    {
      if ( v10 < v21 )
      {
        v7 += v21 - v10;
        do
          io_pPanPairs[v10++] = (CAkSpeakerPan::PanPair)1065353216i64;
        while ( v10 < v21 );
      }
      v38 = v7;
      if ( v7 <= 256i64 )
      {
        if ( 257i64 - v7 >= 4 )
        {
          v39 = &io_pPanPairs[v7 + 1];
          p_fGain_i = &io_pPanPairs[-v7 + 255].fGain_i;
          v41 = ((unsigned __int64)(253i64 - v7) >> 2) + 1;
          v42 = &io_pPanPairs[255i64 - v7];
          v38 = v7 + 4 * v41;
          do
          {
            v39 += 4;
            v42 -= 4;
            v39[-5].fGain_i_minus_1 = p_fGain_i[2];
            p_fGain_i -= 8;
            v39[-5].fGain_i = v42[5].fGain_i_minus_1;
            v39[-4].fGain_i_minus_1 = p_fGain_i[8];
            v39[-4].fGain_i = v42[4].fGain_i_minus_1;
            v39[-3].fGain_i_minus_1 = p_fGain_i[6];
            v39[-3].fGain_i = v42[3].fGain_i_minus_1;
            v39[-2].fGain_i_minus_1 = p_fGain_i[4];
            v39[-2].fGain_i = v42[2].fGain_i_minus_1;
            --v41;
          }
          while ( v41 );
        }
        if ( v38 <= 256 )
        {
          v43 = &io_pPanPairs[256 - v38];
          v44 = &io_pPanPairs[-v38 + 256].fGain_i;
          do
          {
            ++v38;
            --v43;
            io_pPanPairs[v38 - 1].fGain_i_minus_1 = *v44;
            v44 -= 2;
            io_pPanPairs[v38 - 1].fGain_i = v43[1].fGain_i_minus_1;
          }
          while ( v38 <= 256 );
        }
      }
      return;
    }
    v15 = FLOAT_3_1415927;
    v18 = 256;
    v19 = _mm_cvtsi32_si128(v21);
    goto LABEL_14;
  }
}

// File Line: 235
// RVA: 0xA4EDB0
void __fastcall CAkSpeakerPan::GetSpeakerVolumesPlane(
        float in_fAngle,
        float in_fDivergenceCenter,
        float in_fSpread,
        AkSIMDSpeakerVolumes *out_pVolumes,
        unsigned int in_uNumFullBandChannels,
        unsigned int in_uOutputConfig,
        AkDevice *in_pDevice)
{
  __m128 v7; // xmm11
  unsigned int v9; // r14d
  unsigned int v11; // esi
  __int64 v12; // rax
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *m_pItems; // rax
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *i; // rcx
  float v15; // xmm2_4
  CAkSpeakerPan::PanPair *item; // r13
  float v17; // xmm13_4
  float v18; // xmm10_4
  float v19; // xmm13_4
  float v20; // xmm10_4
  unsigned int v21; // r12d
  float v22; // xmm7_4
  float v23; // xmm7_4
  float v24; // xmm13_4
  unsigned int v25; // ecx
  __int64 v26; // rdx
  __m128 v27; // xmm11
  unsigned int v28; // edi
  float v29; // xmm6_4
  AkSIMDSpeakerVolumes *v30; // rbx
  __m128 v31; // xmm1
  unsigned int in_uOutputConfiga; // [rsp+128h] [rbp+30h]

  v9 = in_uOutputConfig & 0xFFFFFFF7;
  if ( (in_uOutputConfig & 0xFFFFFFF7) == 4 )
  {
    v11 = 0;
    do
    {
      v12 = v11++;
      v12 *= 32i64;
      *(__m128 *)((char *)out_pVolumes->vector + v12) = 0i64;
      *(_OWORD *)((char *)&out_pVolumes->aVolumes[4] + v12) = 0i64;
      *(int *)((char *)&out_pVolumes->vector[0].m128_i32[2] + v12) = 1065353216;
    }
    while ( v11 < in_uNumFullBandChannels );
  }
  else
  {
    m_pItems = in_pDevice->m_mapConfig2PanPlane.m_pItems;
    for ( i = &m_pItems[in_pDevice->m_mapConfig2PanPlane.m_uLength]; m_pItems != i; ++m_pItems )
    {
      if ( m_pItems->key == (in_uOutputConfig & 0xFFFFFFF3) )
        break;
    }
    v15 = in_fSpread * 2.5599999;
    item = m_pItems->item;
    v17 = 1.0 / (float)(int)in_uNumFullBandChannels;
    v18 = 1.0 - v17;
    v19 = v17 * v15;
    v20 = (float)(v18 * v15) - (float)((float)(in_fAngle * 0.15915494) * 512.0);
    v21 = (int)(float)((float)(v19 * in_pDevice->fOneOverMinAngleBetweenSpeakers) + 1.0) + 1;
    v22 = v19 / (float)(int)v21;
    if ( (((unsigned __int8)(int)(float)((float)(v19 * in_pDevice->fOneOverMinAngleBetweenSpeakers) + 1.0) + 1) & 1) == 0 )
      v20 = v20 - v22;
    v23 = v22 * 2.0;
    v24 = v19 * 2.0;
    v7.m128_f32[0] = 1.0 / (float)(int)(in_uNumFullBandChannels * v21);
    v25 = 0;
    v26 = in_uNumFullBandChannels - 1;
    in_uOutputConfiga = 0;
    v27 = _mm_shuffle_ps(v7, v7, 0);
    do
    {
      v28 = 0;
      v29 = (float)((float)((float)(v21 >> 1) * v23) + 512.0) + v20;
      v30 = &out_pVolumes[ChannelIndicesForSpread[v26][v25]];
      v30->vector[0] = 0i64;
      *(_OWORD *)&v30->aVolumes[4] = 0i64;
      do
      {
        CAkSpeakerPan::AddSpeakerVolumesPower(
          (int)(float)(v29 + 0.5),
          in_fDivergenceCenter,
          v9,
          item,
          in_pDevice,
          (AkSpeakerVolumes *)v30);
        ++v28;
        v29 = v29 - v23;
      }
      while ( v28 < v21 );
      v26 = in_uNumFullBandChannels - 1;
      v20 = v20 - v24;
      v25 = ++in_uOutputConfiga;
      v31 = _mm_mul_ps(v30->vector[1], v27);
      v30->vector[0] = _mm_sqrt_ps(_mm_mul_ps(v30->vector[0], v27));
      v30->vector[1] = _mm_sqrt_ps(v31);
    }
    while ( in_uOutputConfiga < in_uNumFullBandChannels );
  }
}

// File Line: 321
// RVA: 0xA4DCA0
void __fastcall CAkSpeakerPan::AddSpeakerVolumesPower(
        __int16 in_iAngle,
        float in_fDivergenceCenter,
        unsigned int in_uOutputConfig,
        CAkSpeakerPan::PanPair *in_pPanTableNoCenter,
        AkDevice *in_pDevice,
        AkSpeakerVolumes *out_pVolumes)
{
  int v9; // r10d
  float v10; // xmm0_4
  unsigned int v11; // r10d
  char v12; // al
  unsigned int *puSpeakerAngles; // r11
  AkSpeakerVolumes *v14; // rdx
  float *p_fFrontRight; // r8
  AkSpeakerVolumes *p_fRearRight; // r9
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *m_pItems; // rax
  MapStruct<unsigned long,CAkSpeakerPan::PanPair *> *i; // rcx
  CAkSpeakerPan::PanPair *item; // rcx
  float v20; // xmm2_4
  float v21; // xmm1_4

  if ( (in_uOutputConfig & 0xFFFFFFFC) == 0 && in_pDevice->ePanningRule == AkPanningRule_Headphones )
  {
    v9 = (in_iAngle + 128) & 0x1FF;
    if ( (unsigned int)v9 >= 0x100 )
      v9 = 512 - v9;
    v10 = CAkSpeakerPan::m_fSin2[(__int64)v9 >> 1] + out_pVolumes->fFrontLeft;
    out_pVolumes->fFrontRight = (float)(1.0 - CAkSpeakerPan::m_fSin2[(__int64)v9 >> 1]) + out_pVolumes->fFrontRight;
    out_pVolumes->fFrontLeft = v10;
    return;
  }
  v11 = in_iAngle & 0x1FF;
  if ( v11 > 0x100 )
  {
    v11 = 512 - v11;
    v12 = 0;
  }
  else
  {
    v12 = 1;
  }
  puSpeakerAngles = in_pDevice->puSpeakerAngles;
  if ( (in_uOutputConfig & 0xFFFFFFFB) != 1587 )
  {
    if ( (in_uOutputConfig & 0xFFFFFFFB) != 51 )
      goto LABEL_28;
    if ( v11 <= puSpeakerAngles[1] )
    {
      if ( v11 > *puSpeakerAngles )
      {
        v14 = out_pVolumes;
        if ( !v12 )
        {
          p_fFrontRight = &out_pVolumes->fFrontRight;
          p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fRearRight;
          goto LABEL_32;
        }
        p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fRearLeft;
        goto LABEL_31;
      }
      goto LABEL_28;
    }
LABEL_21:
    v14 = out_pVolumes;
    if ( v12 )
    {
      p_fFrontRight = &out_pVolumes->fRearLeft;
      p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fRearRight;
    }
    else
    {
      p_fFrontRight = &out_pVolumes->fRearRight;
      p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fRearLeft;
    }
    goto LABEL_32;
  }
  if ( v11 > puSpeakerAngles[2] )
    goto LABEL_21;
  if ( v11 > puSpeakerAngles[1] )
  {
    v14 = out_pVolumes;
    if ( v12 )
    {
      p_fFrontRight = &out_pVolumes->fSideLeft;
      p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fRearLeft;
    }
    else
    {
      p_fFrontRight = &out_pVolumes->fSideRight;
      p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fRearRight;
    }
    goto LABEL_32;
  }
  if ( v11 > *puSpeakerAngles )
  {
    v14 = out_pVolumes;
    if ( !v12 )
    {
      p_fFrontRight = &out_pVolumes->fFrontRight;
      p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fSideRight;
      goto LABEL_32;
    }
    p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fSideLeft;
    goto LABEL_31;
  }
LABEL_28:
  v14 = out_pVolumes;
  if ( v12 != v11 > *puSpeakerAngles )
  {
    p_fFrontRight = &out_pVolumes->fFrontRight;
    p_fRearRight = out_pVolumes;
    goto LABEL_32;
  }
  p_fRearRight = (AkSpeakerVolumes *)&out_pVolumes->fFrontRight;
LABEL_31:
  p_fFrontRight = &v14->fFrontLeft;
LABEL_32:
  if ( (in_uOutputConfig & 4) != 0 && v11 < *puSpeakerAngles && in_fDivergenceCenter > 0.0 )
  {
    m_pItems = in_pDevice->m_mapConfig2PanPlane.m_pItems;
    for ( i = &m_pItems[in_pDevice->m_mapConfig2PanPlane.m_uLength]; m_pItems != i; ++m_pItems )
    {
      if ( m_pItems->key == in_uOutputConfig )
        break;
    }
    item = m_pItems->item;
    v20 = (float)((float)(1.0 - in_fDivergenceCenter) * in_pPanTableNoCenter[v11].fGain_i_minus_1) + *p_fFrontRight;
    v21 = (float)((float)((float)(1.0 - in_fDivergenceCenter) * in_pPanTableNoCenter[v11].fGain_i)
                + (float)(in_fDivergenceCenter * item[v11].fGain_i))
        + p_fRearRight->fFrontLeft;
    v14->fCenter = (float)(in_fDivergenceCenter * item[v11].fGain_i_minus_1) + v14->fCenter;
    *p_fFrontRight = v20;
  }
  else
  {
    v21 = in_pPanTableNoCenter[v11].fGain_i + p_fRearRight->fFrontLeft;
    *p_fFrontRight = *p_fFrontRight + in_pPanTableNoCenter[v11].fGain_i_minus_1;
  }
  p_fRearRight->fFrontLeft = v21;
}

// File Line: 564
// RVA: 0xA4F300
void __fastcall _GetSpeakerVolumes2DPan1RouteToCenter(float in_fX, float in_fCenterPct, AkSpeakerVolumes *out_pVolumes)
{
  __m128 v3; // xmm4
  float v4; // xmm3_4
  float v5; // xmm2_4

  v3 = (__m128)(unsigned int)FLOAT_1_0;
  if ( in_fX > 0.5 )
  {
    v4 = (float)(1.0 - in_fX) * (float)(in_fCenterPct * 2.0);
    v5 = (float)((float)(in_fX - 1.0) * in_fCenterPct) + in_fX;
  }
  else
  {
    v4 = (float)(in_fCenterPct * 2.0) * in_fX;
    v5 = (float)(1.0 - in_fCenterPct) * in_fX;
  }
  v3.m128_f32[0] = (float)(1.0 - v5) - v4;
  *(_QWORD *)&out_pVolumes->fSideRight = 0i64;
  *(_QWORD *)&out_pVolumes->fRearLeft = 0i64;
  out_pVolumes->fSideLeft = 0.0;
  out_pVolumes->fFrontRight = fsqrt(v5);
  LODWORD(out_pVolumes->fFrontLeft) = _mm_sqrt_ps(v3).m128_u32[0];
  out_pVolumes->fCenter = fsqrt(v4);
}

// File Line: 673
// RVA: 0xA4F480
void __fastcall _GetSpeakerVolumes2DPan2RouteToCenter(
        float in_fX,
        float in_fY,
        float in_fCenterPct,
        AkSpeakerVolumes *out_pVolumes)
{
  __m128 v4; // xmm6
  float v7; // xmm4_4
  float v8; // xmm3_4
  __m128 v9; // xmm0
  __m128 v10; // xmm1

  v4 = (__m128)(unsigned int)FLOAT_1_0;
  if ( in_fX > 0.5 )
  {
    v7 = (float)(1.0 - in_fX) * (float)(in_fCenterPct * 2.0);
    v8 = (float)((float)(in_fX - 1.0) * in_fCenterPct) + in_fX;
  }
  else
  {
    v7 = (float)(in_fCenterPct * 2.0) * in_fX;
    v8 = (float)(1.0 - in_fCenterPct) * in_fX;
  }
  v9 = (__m128)(unsigned int)FLOAT_1_0;
  v10 = (__m128)(unsigned int)FLOAT_1_0;
  *(_QWORD *)&out_pVolumes->fSideRight = 0i64;
  out_pVolumes->fSideLeft = 0.0;
  v4.m128_f32[0] = (float)(1.0 - in_fX) * (float)(1.0 - in_fY);
  v10.m128_f32[0] = (float)(1.0 - in_fY) * in_fX;
  v9.m128_f32[0] = (float)((float)(1.0 - v8) - v7) * in_fY;
  LODWORD(out_pVolumes->fFrontLeft) = _mm_sqrt_ps(v9).m128_u32[0];
  out_pVolumes->fFrontRight = fsqrt(v8 * in_fY);
  out_pVolumes->fCenter = fsqrt(v7 * in_fY);
  LODWORD(out_pVolumes->fRearLeft) = _mm_sqrt_ps(v4).m128_u32[0];
  LODWORD(out_pVolumes->fRearRight) = _mm_sqrt_ps(v10).m128_u32[0];
}

// File Line: 712
// RVA: 0xA4F390
void __fastcall _GetSpeakerVolumes2DPan2HasCenter(float in_fX, float in_fY, AkSpeakerVolumes *out_pVolumes)
{
  __m128 v3; // xmm3
  float v5; // xmm8_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm1

  v3 = (__m128)(unsigned int)FLOAT_1_0;
  v5 = 1.0 - in_fX;
  v6 = (float)(in_fX * 2.0) * 0.33333334;
  v7 = (float)(2.0 - (float)(in_fX * 2.0)) * 0.33333334;
  if ( in_fY < 0.5 )
  {
    v8 = (__m128)(unsigned int)FLOAT_1_0;
    v8.m128_f32[0] = 1.0 - (float)((float)(in_fY * 6.0) * 0.2);
  }
  else
  {
    v8 = (__m128)LODWORD(FLOAT_4_0);
    v8.m128_f32[0] = (float)(4.0 - (float)(in_fY * 4.0)) * 0.2;
  }
  v3.m128_f32[0] = 1.0 - v8.m128_f32[0];
  *(_QWORD *)&out_pVolumes->fSideRight = 0i64;
  out_pVolumes->fSideLeft = 0.0;
  v9 = v3;
  v10 = v3;
  v3.m128_f32[0] = (float)(1.0 - v8.m128_f32[0]) * 0.33333334;
  v9.m128_f32[0] = v9.m128_f32[0] * v7;
  v10.m128_f32[0] = v10.m128_f32[0] * v6;
  LODWORD(out_pVolumes->fFrontLeft) = _mm_sqrt_ps(v9).m128_u32[0];
  v9.m128_i32[0] = _mm_sqrt_ps(v10).m128_u32[0];
  v11 = v8;
  v11.m128_f32[0] = v8.m128_f32[0] * v5;
  v8.m128_f32[0] = v8.m128_f32[0] * in_fX;
  LODWORD(out_pVolumes->fFrontRight) = v9.m128_i32[0];
  LODWORD(out_pVolumes->fCenter) = _mm_sqrt_ps(v3).m128_u32[0];
  LODWORD(out_pVolumes->fRearLeft) = _mm_sqrt_ps(v11).m128_u32[0];
  LODWORD(out_pVolumes->fRearRight) = _mm_sqrt_ps(v8).m128_u32[0];
}

// File Line: 770
// RVA: 0xA4F560
void __fastcall _GetSpeakerVolumes2DPan3(float in_fX, float in_fY, AkSpeakerVolumes *out_pVolumes)
{
  __m128 v3; // xmm4
  float v4; // xmm3_4
  float v6; // xmm5_4
  float v7; // xmm2_4
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm1

  v3 = (__m128)(unsigned int)FLOAT_1_0;
  v4 = in_fY * 4.0;
  v6 = 1.0 - in_fX;
  v7 = (float)((float)(in_fY * 4.0) - 1.0) * 0.33333334;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v8 = (__m128)LODWORD(FLOAT_3_0);
  v8.m128_f32[0] = (float)(3.0 - v4) * 0.33333334;
  if ( v8.m128_f32[0] < 0.0 )
    v8 = 0i64;
  out_pVolumes->fCenter = 0.0;
  out_pVolumes->fLfe = 0.0;
  v3.m128_f32[0] = 1.0 - (float)(v8.m128_f32[0] + v7);
  out_pVolumes->fFrontLeft = fsqrt(v7 * v6);
  out_pVolumes->fFrontRight = fsqrt(v7 * in_fX);
  v9 = v8;
  v8.m128_f32[0] = v8.m128_f32[0] * in_fX;
  v9.m128_f32[0] = v9.m128_f32[0] * v6;
  LODWORD(out_pVolumes->fRearLeft) = _mm_sqrt_ps(v9).m128_u32[0];
  v9.m128_i32[0] = _mm_sqrt_ps(v8).m128_u32[0];
  v10 = v3;
  v10.m128_f32[0] = v3.m128_f32[0] * v6;
  v3.m128_f32[0] = v3.m128_f32[0] * in_fX;
  LODWORD(out_pVolumes->fRearRight) = v9.m128_i32[0];
  LODWORD(out_pVolumes->fSideLeft) = _mm_sqrt_ps(v10).m128_u32[0];
  LODWORD(out_pVolumes->fSideRight) = _mm_sqrt_ps(v3).m128_u32[0];
}

// File Line: 807
// RVA: 0xA4F780
void __fastcall _GetSpeakerVolumes2DPan3RouteToCenter(
        float in_fX,
        float in_fY,
        float in_fCenterPct,
        AkSpeakerVolumes *out_pVolumes)
{
  __m128 v4; // xmm6
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm9_4
  float v10; // xmm7_4
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  float v13; // xmm0_4
  __m128 v14; // xmm1

  v4 = (__m128)(unsigned int)FLOAT_1_0;
  if ( in_fX > 0.5 )
  {
    v6 = (float)(1.0 - in_fX) * (float)(in_fCenterPct * 2.0);
    v7 = (float)((float)(in_fX - 1.0) * in_fCenterPct) + in_fX;
  }
  else
  {
    v6 = (float)(in_fCenterPct * 2.0) * in_fX;
    v7 = (float)(1.0 - in_fCenterPct) * in_fX;
  }
  v8 = in_fY * 4.0;
  v9 = 1.0 - in_fX;
  v10 = (float)(v8 - 1.0) * 0.33333334;
  if ( v10 < 0.0 )
    v10 = 0.0;
  v11 = (__m128)LODWORD(FLOAT_3_0);
  v11.m128_f32[0] = (float)(3.0 - v8) * 0.33333334;
  if ( v11.m128_f32[0] < 0.0 )
    v11 = 0i64;
  out_pVolumes->fLfe = 0.0;
  v4.m128_f32[0] = 1.0 - (float)(v11.m128_f32[0] + v10);
  out_pVolumes->fFrontLeft = fsqrt(v10 * (float)((float)(1.0 - v7) - v6));
  v12 = v11;
  v12.m128_f32[0] = v11.m128_f32[0] * v9;
  v11.m128_f32[0] = v11.m128_f32[0] * in_fX;
  out_pVolumes->fFrontRight = fsqrt(v10 * v7);
  out_pVolumes->fCenter = fsqrt(v10 * v6);
  LODWORD(v13) = _mm_sqrt_ps(v12).m128_u32[0];
  v14 = v4;
  v14.m128_f32[0] = v4.m128_f32[0] * v9;
  v4.m128_f32[0] = v4.m128_f32[0] * in_fX;
  out_pVolumes->fRearLeft = v13;
  LODWORD(out_pVolumes->fRearRight) = _mm_sqrt_ps(v11).m128_u32[0];
  LODWORD(out_pVolumes->fSideLeft) = _mm_sqrt_ps(v14).m128_u32[0];
  LODWORD(out_pVolumes->fSideRight) = _mm_sqrt_ps(v4).m128_u32[0];
}

// File Line: 854
// RVA: 0xA4F640
void __fastcall _GetSpeakerVolumes2DPan3HasCenter(float in_fX, float in_fY, AkSpeakerVolumes *out_pVolumes)
{
  __m128 v3; // xmm4
  float v5; // xmm8_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  float v10; // xmm0_4
  __m128 v11; // xmm1

  v3 = (__m128)(unsigned int)FLOAT_1_0;
  v5 = 1.0 - in_fX;
  v6 = (float)(2.0 - (float)(in_fX * 2.0)) * 0.33333334;
  v7 = (float)((float)(in_fY * 8.0) - 1.0) * 0.14285715;
  if ( v7 < 0.0 )
    v7 = 0.0;
  v8 = (__m128)LODWORD(FLOAT_7_0);
  v8.m128_f32[0] = (float)(7.0 - (float)(in_fY * 10.0)) * 0.14285715;
  if ( v8.m128_f32[0] < 0.0 )
    v8 = 0i64;
  out_pVolumes->fLfe = 0.0;
  v3.m128_f32[0] = 1.0 - (float)(v8.m128_f32[0] + v7);
  out_pVolumes->fFrontLeft = fsqrt(v7 * v6);
  v9 = v8;
  v9.m128_f32[0] = v8.m128_f32[0] * v5;
  v8.m128_f32[0] = v8.m128_f32[0] * in_fX;
  out_pVolumes->fFrontRight = fsqrt(v7 * (float)(1.0 - (float)(v6 + 0.33333334)));
  out_pVolumes->fCenter = fsqrt(v7 * 0.33333334);
  LODWORD(v10) = _mm_sqrt_ps(v9).m128_u32[0];
  v11 = v3;
  v11.m128_f32[0] = v3.m128_f32[0] * v5;
  v3.m128_f32[0] = v3.m128_f32[0] * in_fX;
  out_pVolumes->fRearLeft = v10;
  LODWORD(out_pVolumes->fRearRight) = _mm_sqrt_ps(v8).m128_u32[0];
  LODWORD(out_pVolumes->fSideLeft) = _mm_sqrt_ps(v11).m128_u32[0];
  LODWORD(out_pVolumes->fSideRight) = _mm_sqrt_ps(v3).m128_u32[0];
}

// File Line: 901
// RVA: 0xA4E470
void __fastcall CAkSpeakerPan::GetSpeakerVolumes2DPan(
        float in_fX,
        float in_fY,
        float in_fCenterPct,
        bool in_bIsPannerEnabled,
        unsigned int in_uInputConfig,
        unsigned int in_uOutputConfig,
        AkSIMDSpeakerVolumes *out_pVolumes)
{
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int v11; // eax
  unsigned int v12; // eax
  __m128 v13; // xmm0
  float v14; // xmm6_4
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 v19; // xmm0
  __m128 v20; // xmm0
  AkSIMDSpeakerVolumes *v21; // rax
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm0
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  unsigned int v41; // eax
  unsigned int v42; // eax
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm1
  __m128 v49; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm0
  __m128 v56; // xmm1
  __m128 v57; // xmm1
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm3
  __m128 v61; // xmm2
  __m128 v62; // xmm1
  __m128 v63; // xmm0
  __m128 v64; // xmm1
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  AkSpeakerVolumes v67; // [rsp+20h] [rbp-40h] BYREF

  v7 = in_uInputConfig & 0xFFFFFFF7;
  v8 = in_uOutputConfig & 0xFFFFFFF7;
  if ( (in_uInputConfig & 0xFFFFFFF7) > 0x33 )
  {
    v41 = v7 - 55;
    if ( v41 )
    {
      v42 = v41 - 1532;
      if ( v42 )
      {
        if ( v42 == 4 )
        {
          memset(out_pVolumes, 0, 0xE0ui64);
          out_pVolumes->vector[0].m128_i32[0] = 1065353216;
          out_pVolumes[1].vector[0].m128_i32[1] = 1065353216;
          out_pVolumes[2].vector[0].m128_i32[2] = 1065353216;
          out_pVolumes[3].vector[0].m128_i32[3] = 1065353216;
          out_pVolumes[4].vector[1].m128_i32[0] = 1065353216;
          out_pVolumes[5].vector[1].m128_i32[1] = 1065353216;
          out_pVolumes[6].vector[1].m128_i32[2] = 1065353216;
          if ( in_bIsPannerEnabled )
          {
            _GetSpeakerVolumes2DPan3HasCenter(in_fX, in_fY, &v67);
            v43 = *(__m128 *)&v67.fFrontLeft;
            v44 = *(__m128 *)&v67.fRearRight;
            v45 = *(__m128 *)&v67.fFrontLeft;
            out_pVolumes->vector[0] = _mm_mul_ps(*(__m128 *)&v67.fFrontLeft, out_pVolumes->vector[0]);
            out_pVolumes->vector[1] = _mm_mul_ps(v44, out_pVolumes->vector[1]);
            v46 = _mm_mul_ps(out_pVolumes[1].vector[1], v44);
            out_pVolumes[1].vector[0] = _mm_mul_ps(v45, out_pVolumes[1].vector[0]);
            out_pVolumes[1].vector[1] = v46;
            v47 = _mm_mul_ps(out_pVolumes[2].vector[1], v44);
            out_pVolumes[2].vector[0] = _mm_mul_ps(v43, out_pVolumes[2].vector[0]);
            out_pVolumes[2].vector[1] = v47;
            v48 = _mm_mul_ps(v44, out_pVolumes[3].vector[1]);
            out_pVolumes[3].vector[0] = _mm_mul_ps(v43, out_pVolumes[3].vector[0]);
            out_pVolumes[3].vector[1] = v48;
            v49 = _mm_mul_ps(v44, out_pVolumes[4].vector[1]);
            out_pVolumes[4].vector[0] = _mm_mul_ps(v43, out_pVolumes[4].vector[0]);
            out_pVolumes[4].vector[1] = v49;
            v50 = _mm_mul_ps(v44, out_pVolumes[5].vector[1]);
            out_pVolumes[5].vector[0] = _mm_mul_ps(v43, out_pVolumes[5].vector[0]);
            out_pVolumes[5].vector[1] = v50;
            v51 = _mm_mul_ps(v44, out_pVolumes[6].vector[1]);
            out_pVolumes[6].vector[0] = _mm_mul_ps(v43, out_pVolumes[6].vector[0]);
            out_pVolumes[6].vector[1] = v51;
          }
        }
      }
      else
      {
        memset(out_pVolumes, 0, 0xC0ui64);
        out_pVolumes->vector[0].m128_i32[0] = 1065353216;
        out_pVolumes[1].vector[0].m128_i32[1] = 1065353216;
        out_pVolumes[2].vector[0].m128_i32[3] = 1065353216;
        out_pVolumes[3].vector[1].m128_i32[0] = 1065353216;
        out_pVolumes[4].vector[1].m128_i32[1] = 1065353216;
        out_pVolumes[5].vector[1].m128_i32[2] = 1065353216;
        if ( in_bIsPannerEnabled )
        {
          _GetSpeakerVolumes2DPan3(in_fX, in_fY, &v67);
          v52 = *(__m128 *)&v67.fFrontLeft;
          v53 = *(__m128 *)&v67.fRearRight;
          v54 = *(__m128 *)&v67.fFrontLeft;
          out_pVolumes->vector[0] = _mm_mul_ps(*(__m128 *)&v67.fFrontLeft, out_pVolumes->vector[0]);
          out_pVolumes->vector[1] = _mm_mul_ps(v53, out_pVolumes->vector[1]);
          v55 = _mm_mul_ps(out_pVolumes[1].vector[1], v53);
          out_pVolumes[1].vector[0] = _mm_mul_ps(v54, out_pVolumes[1].vector[0]);
          out_pVolumes[1].vector[1] = v55;
          v56 = _mm_mul_ps(out_pVolumes[2].vector[1], v53);
          out_pVolumes[2].vector[0] = _mm_mul_ps(v52, out_pVolumes[2].vector[0]);
          out_pVolumes[2].vector[1] = v56;
          v57 = _mm_mul_ps(v53, out_pVolumes[3].vector[1]);
          out_pVolumes[3].vector[0] = _mm_mul_ps(v52, out_pVolumes[3].vector[0]);
          out_pVolumes[3].vector[1] = v57;
          v58 = _mm_mul_ps(v53, out_pVolumes[4].vector[1]);
          out_pVolumes[4].vector[0] = _mm_mul_ps(v52, out_pVolumes[4].vector[0]);
          out_pVolumes[4].vector[1] = v58;
          v59 = _mm_mul_ps(v53, out_pVolumes[5].vector[1]);
          out_pVolumes[5].vector[0] = _mm_mul_ps(v52, out_pVolumes[5].vector[0]);
          out_pVolumes[5].vector[1] = v59;
        }
      }
    }
    else
    {
      memset(out_pVolumes, 0, 0xA0ui64);
      out_pVolumes->vector[0].m128_i32[0] = 1065353216;
      out_pVolumes[1].vector[0].m128_i32[1] = 1065353216;
      out_pVolumes[2].vector[0].m128_i32[2] = 1065353216;
      if ( ((v8 - 1587) & 0xFFFFFFFB) != 0 )
      {
        out_pVolumes[3].vector[0].m128_i32[3] = 1065353216;
        out_pVolumes[4].vector[1].m128_i32[0] = 1065353216;
      }
      else
      {
        out_pVolumes[3].vector[1].m128_i32[1] = 1065353216;
        out_pVolumes[4].vector[1].m128_i32[2] = 1065353216;
      }
      if ( in_bIsPannerEnabled )
      {
        if ( ((v8 - 1587) & 0xFFFFFFFB) != 0 )
        {
          _GetSpeakerVolumes2DPan2HasCenter(in_fX, in_fY, &v67);
        }
        else
        {
          out_pVolumes[3].vector[0].m128_i32[3] = 1065353216;
          out_pVolumes[4].vector[1].m128_i32[0] = 1065353216;
          _GetSpeakerVolumes2DPan3HasCenter(in_fX, in_fY, &v67);
        }
        v60 = *(__m128 *)&v67.fFrontLeft;
        v61 = *(__m128 *)&v67.fRearRight;
        v62 = *(__m128 *)&v67.fFrontLeft;
        out_pVolumes->vector[0] = _mm_mul_ps(*(__m128 *)&v67.fFrontLeft, out_pVolumes->vector[0]);
        out_pVolumes->vector[1] = _mm_mul_ps(v61, out_pVolumes->vector[1]);
        v63 = _mm_mul_ps(out_pVolumes[1].vector[1], v61);
        out_pVolumes[1].vector[0] = _mm_mul_ps(v62, out_pVolumes[1].vector[0]);
        out_pVolumes[1].vector[1] = v63;
        v64 = _mm_mul_ps(out_pVolumes[2].vector[1], v61);
        out_pVolumes[2].vector[0] = _mm_mul_ps(v60, out_pVolumes[2].vector[0]);
        out_pVolumes[2].vector[1] = v64;
        v65 = _mm_mul_ps(v61, out_pVolumes[3].vector[1]);
        out_pVolumes[3].vector[0] = _mm_mul_ps(v60, out_pVolumes[3].vector[0]);
        out_pVolumes[3].vector[1] = v65;
        v66 = _mm_mul_ps(v61, out_pVolumes[4].vector[1]);
        out_pVolumes[4].vector[0] = _mm_mul_ps(v60, out_pVolumes[4].vector[0]);
        out_pVolumes[4].vector[1] = v66;
      }
    }
  }
  else if ( v7 == 51 )
  {
    memset(out_pVolumes, 0, 0x80ui64);
    out_pVolumes->vector[0].m128_i32[0] = 1065353216;
    out_pVolumes[1].vector[0].m128_i32[1] = 1065353216;
    if ( ((v8 - 1587) & 0xFFFFFFFB) != 0 )
    {
      out_pVolumes[2].vector[0].m128_i32[3] = 1065353216;
      out_pVolumes[3].vector[1].m128_i32[0] = 1065353216;
    }
    else
    {
      out_pVolumes[2].vector[1].m128_i32[1] = 1065353216;
      out_pVolumes[3].vector[1].m128_i32[2] = 1065353216;
    }
    if ( in_bIsPannerEnabled )
    {
      if ( ((v8 - 1587) & 0xFFFFFFFB) != 0 )
      {
        v32 = (__m128)(unsigned int)FLOAT_1_0;
        v67.fCenter = 0.0;
        *(_QWORD *)&v67.fSideRight = 0i64;
        v67.fSideLeft = 0.0;
        v33 = (__m128)(unsigned int)FLOAT_1_0;
        v33.m128_f32[0] = 1.0 - in_fX;
        v34 = v33;
        v33.m128_f32[0] = (float)(1.0 - in_fX) * (float)(1.0 - in_fY);
        v32.m128_f32[0] = (float)(1.0 - in_fY) * in_fX;
        v34.m128_f32[0] = v34.m128_f32[0] * in_fY;
        LODWORD(v67.fFrontLeft) = _mm_sqrt_ps(v34).m128_u32[0];
        v67.fFrontRight = fsqrt(in_fX * in_fY);
        LODWORD(v67.fRearLeft) = _mm_sqrt_ps(v33).m128_u32[0];
        LODWORD(v67.fRearRight) = _mm_sqrt_ps(v32).m128_u32[0];
      }
      else
      {
        out_pVolumes[2].vector[0].m128_i32[3] = 1065353216;
        out_pVolumes[3].vector[1].m128_i32[0] = 1065353216;
        _GetSpeakerVolumes2DPan3(in_fX, in_fY, &v67);
      }
      v35 = *(__m128 *)&v67.fFrontLeft;
      v36 = *(__m128 *)&v67.fRearRight;
      v37 = *(__m128 *)&v67.fFrontLeft;
      out_pVolumes->vector[0] = _mm_mul_ps(*(__m128 *)&v67.fFrontLeft, out_pVolumes->vector[0]);
      out_pVolumes->vector[1] = _mm_mul_ps(v36, out_pVolumes->vector[1]);
      v38 = _mm_mul_ps(out_pVolumes[1].vector[1], v36);
      out_pVolumes[1].vector[0] = _mm_mul_ps(v37, out_pVolumes[1].vector[0]);
      out_pVolumes[1].vector[1] = v38;
      v39 = _mm_mul_ps(out_pVolumes[2].vector[1], v36);
      out_pVolumes[2].vector[0] = _mm_mul_ps(v35, out_pVolumes[2].vector[0]);
      out_pVolumes[2].vector[1] = v39;
      v40 = _mm_mul_ps(v36, out_pVolumes[3].vector[1]);
      out_pVolumes[3].vector[0] = _mm_mul_ps(v35, out_pVolumes[3].vector[0]);
      out_pVolumes[3].vector[1] = v40;
    }
  }
  else
  {
    v11 = v7 - 3;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        if ( v12 == 3 )
        {
          memset(out_pVolumes, 0, 0x60ui64);
          out_pVolumes->vector[0].m128_i32[0] = 1065353216;
          out_pVolumes[1].vector[0].m128_i32[1] = 1065353216;
          out_pVolumes[2].vector[0].m128_i32[2] = 1065353216;
          if ( in_bIsPannerEnabled )
          {
            if ( ((v8 - 1587) & 0xFFFFFFFB) != 0 )
            {
              if ( ((v8 - 51) & 0xFFFFFFFB) != 0 )
              {
                v13 = (__m128)LODWORD(FLOAT_2_0);
                *(_QWORD *)&v67.fSideRight = 0i64;
                v67.fRearRight = 0.0;
                v67.fSideLeft = 0.0;
                v14 = in_fX * 2.0;
                v13.m128_f32[0] = (float)(2.0 - v14) * 0.33333334;
                *(_QWORD *)&v67.fCenter = _mm_sqrt_ps((__m128)LODWORD(FLOAT_0_33333334)).m128_u32[0];
                LODWORD(v67.fFrontLeft) = _mm_sqrt_ps(v13).m128_u32[0];
                v67.fFrontRight = fsqrt(v14 * 0.33333334);
              }
              else
              {
                out_pVolumes->vector[0].m128_i32[3] = 1065353216;
                out_pVolumes[1].vector[1].m128_i32[0] = 1065353216;
                out_pVolumes[2].vector[0].m128_i32[3] = 1056964608;
                out_pVolumes[2].vector[1].m128_i32[0] = 1056964608;
                _GetSpeakerVolumes2DPan2HasCenter(in_fX, in_fY, &v67);
              }
            }
            else
            {
              out_pVolumes->vector[0].m128_i32[3] = 1065353216;
              out_pVolumes->vector[1].m128_i32[1] = 1065353216;
              out_pVolumes[1].vector[1].m128_i32[0] = 1065353216;
              out_pVolumes[1].vector[1].m128_i32[2] = 1065353216;
              out_pVolumes[2].vector[0].m128_i32[3] = 1056964608;
              out_pVolumes[2].vector[1].m128_i32[1] = 1056964608;
              out_pVolumes[2].vector[1].m128_i32[0] = 1056964608;
              out_pVolumes[2].vector[1].m128_i32[2] = 1056964608;
              _GetSpeakerVolumes2DPan3HasCenter(in_fX, in_fY, &v67);
            }
            v15 = *(__m128 *)&v67.fFrontLeft;
            v16 = *(__m128 *)&v67.fRearRight;
            v17 = *(__m128 *)&v67.fFrontLeft;
            out_pVolumes->vector[0] = _mm_mul_ps(*(__m128 *)&v67.fFrontLeft, out_pVolumes->vector[0]);
            out_pVolumes->vector[1] = _mm_mul_ps(v16, out_pVolumes->vector[1]);
            v18 = _mm_mul_ps(out_pVolumes[1].vector[1], v16);
            out_pVolumes[1].vector[0] = _mm_mul_ps(v17, out_pVolumes[1].vector[0]);
            out_pVolumes[1].vector[1] = v18;
            v19 = _mm_mul_ps(out_pVolumes[2].vector[1], v16);
            out_pVolumes[2].vector[0] = _mm_mul_ps(v15, out_pVolumes[2].vector[0]);
            out_pVolumes[2].vector[1] = v19;
          }
        }
      }
      else if ( in_bIsPannerEnabled )
      {
        switch ( v8 )
        {
          case 0x637u:
            _GetSpeakerVolumes2DPan3RouteToCenter(in_fX, in_fY, in_fCenterPct, (AkSpeakerVolumes *)out_pVolumes);
            break;
          case 0x633u:
            _GetSpeakerVolumes2DPan3(in_fX, in_fY, (AkSpeakerVolumes *)out_pVolumes);
            break;
          case 0x37u:
            _GetSpeakerVolumes2DPan2RouteToCenter(in_fX, in_fY, in_fCenterPct, (AkSpeakerVolumes *)out_pVolumes);
            break;
          case 0x33u:
            v22 = (__m128)(unsigned int)FLOAT_1_0;
            out_pVolumes->vector[0].m128_i32[2] = 0;
            out_pVolumes->vector[1].m128_u64[1] = 0i64;
            out_pVolumes->vector[1].m128_i32[1] = 0;
            v23 = (__m128)(unsigned int)FLOAT_1_0;
            v23.m128_f32[0] = 1.0 - in_fX;
            v24 = v23;
            v23.m128_f32[0] = (float)(1.0 - in_fX) * (float)(1.0 - in_fY);
            v22.m128_f32[0] = (float)(1.0 - in_fY) * in_fX;
            v24.m128_f32[0] = v24.m128_f32[0] * in_fY;
            out_pVolumes->vector[0].m128_i32[0] = _mm_sqrt_ps(v24).m128_u32[0];
            out_pVolumes->vector[0].m128_f32[1] = fsqrt(in_fX * in_fY);
            out_pVolumes->vector[0].m128_i32[3] = _mm_sqrt_ps(v23).m128_u32[0];
            out_pVolumes->vector[1].m128_i32[0] = _mm_sqrt_ps(v22).m128_u32[0];
            break;
          case 7u:
            _GetSpeakerVolumes2DPan1RouteToCenter(in_fX, in_fCenterPct, (AkSpeakerVolumes *)out_pVolumes);
            break;
          default:
            v25 = (__m128)(unsigned int)FLOAT_1_0;
            v25.m128_f32[0] = 1.0 - in_fX;
            out_pVolumes->vector[0].m128_u64[1] = 0i64;
            *(_OWORD *)&out_pVolumes->aVolumes[4] = 0ui64;
            out_pVolumes->vector[0].m128_i32[0] = _mm_sqrt_ps(v25).m128_u32[0];
            out_pVolumes->vector[0].m128_f32[1] = fsqrt(in_fX);
            break;
        }
      }
      else
      {
        if ( (in_uOutputConfig & 4) != 0 && (in_uOutputConfig & 0xFFFFFFF3) != 0 )
        {
          v20 = (__m128)(unsigned int)FLOAT_1_0;
          v21 = out_pVolumes;
          v20.m128_f32[0] = (float)(1.0 - in_fCenterPct) * 0.5;
          v20.m128_i32[0] = _mm_sqrt_ps(v20).m128_u32[0];
          out_pVolumes->vector[0].m128_i32[0] = v20.m128_i32[0];
          out_pVolumes->vector[0].m128_i32[1] = v20.m128_i32[0];
          out_pVolumes->vector[0].m128_f32[2] = fsqrt(in_fCenterPct);
        }
        else
        {
          v21 = out_pVolumes;
          out_pVolumes->vector[0].m128_i32[0] = 1060439283;
          *(unsigned __int64 *)((char *)out_pVolumes->vector[0].m128_u64 + 4) = 1060439283i64;
        }
        v21->vector[1].m128_i32[3] = 0;
        *(unsigned __int64 *)((char *)&v21->vector[0].m128_u64[1] + 4) = 0i64;
        *(unsigned __int64 *)((char *)v21->vector[1].m128_u64 + 4) = 0i64;
      }
    }
    else
    {
      out_pVolumes->vector[0] = 0ui64;
      *(_OWORD *)&out_pVolumes->aVolumes[4] = 0ui64;
      out_pVolumes[1].vector[0].m128_u64[0] = 0i64;
      out_pVolumes[1].vector[0].m128_u64[1] = 0i64;
      out_pVolumes[1].vector[1].m128_u64[0] = 0i64;
      out_pVolumes[1].vector[1].m128_u64[1] = 0i64;
      out_pVolumes->vector[0].m128_i32[0] = 1065353216;
      out_pVolumes[1].vector[0].m128_i32[1] = 1065353216;
      if ( in_bIsPannerEnabled )
      {
        if ( ((v8 - 1587) & 0xFFFFFFFB) != 0 )
        {
          *(_QWORD *)&v67.fSideRight = 0i64;
          if ( ((v8 - 51) & 0xFFFFFFFB) != 0 )
          {
            v26 = (__m128)(unsigned int)FLOAT_1_0;
            *(_QWORD *)&v67.fCenter = 0i64;
            v26.m128_f32[0] = 1.0 - in_fX;
            *(_QWORD *)&v67.fRearRight = 0i64;
            v67.fFrontRight = fsqrt(in_fX);
            LODWORD(v67.fFrontLeft) = _mm_sqrt_ps(v26).m128_u32[0];
          }
          else
          {
            v27 = (__m128)(unsigned int)FLOAT_1_0;
            out_pVolumes->vector[0].m128_i32[3] = 1065353216;
            out_pVolumes[1].vector[1].m128_i32[0] = 1065353216;
            v67.fCenter = 0.0;
            v67.fSideLeft = 0.0;
            v28 = (__m128)(unsigned int)FLOAT_1_0;
            v28.m128_f32[0] = 1.0 - in_fX;
            v29 = v28;
            v28.m128_f32[0] = (float)(1.0 - in_fX) * (float)(1.0 - in_fY);
            v27.m128_f32[0] = (float)(1.0 - in_fY) * in_fX;
            v29.m128_f32[0] = v29.m128_f32[0] * in_fY;
            LODWORD(v67.fFrontLeft) = _mm_sqrt_ps(v29).m128_u32[0];
            v67.fFrontRight = fsqrt(in_fX * in_fY);
            LODWORD(v67.fRearLeft) = _mm_sqrt_ps(v28).m128_u32[0];
            LODWORD(v67.fRearRight) = _mm_sqrt_ps(v27).m128_u32[0];
          }
        }
        else
        {
          out_pVolumes->vector[0].m128_i32[3] = 1065353216;
          out_pVolumes->vector[1].m128_i32[1] = 1065353216;
          out_pVolumes[1].vector[1].m128_i32[0] = 1065353216;
          out_pVolumes[1].vector[1].m128_i32[2] = 1065353216;
          _GetSpeakerVolumes2DPan3(in_fX, in_fY, &v67);
        }
        v30 = *(__m128 *)&v67.fFrontLeft;
        out_pVolumes->vector[0] = _mm_mul_ps(*(__m128 *)&v67.fFrontLeft, out_pVolumes->vector[0]);
        out_pVolumes->vector[1] = _mm_mul_ps(*(__m128 *)&v67.fRearRight, out_pVolumes->vector[1]);
        v31 = _mm_mul_ps(out_pVolumes[1].vector[1], *(__m128 *)&v67.fRearRight);
        out_pVolumes[1].vector[0] = _mm_mul_ps(v30, out_pVolumes[1].vector[0]);
        out_pVolumes[1].vector[1] = v31;
      }
    }
  }
}

// File Line: 1251
// RVA: 0xA4E430
void __fastcall CAkSpeakerPan::GetDefaultSpeakerAngles(unsigned int in_channelMask, float *out_angles)
{
  *out_angles = 30.0;
  out_angles[1] = 110.0;
  out_angles[2] = 142.5;
  if ( (in_channelMask & 0x600) != 0 )
    out_angles[1] = 100.0;
  if ( (in_channelMask & 0xFFFFFFF8) == 0 )
    *out_angles = 45.0;
}

// File Line: 1282
// RVA: 0xA4F1F0
__int64 __fastcall CAkSpeakerPan::SetSpeakerAngles(
        const float *in_pfSpeakerAngles,
        unsigned int in_uNumAngles,
        char *out_uSpeakerAngles,
        unsigned int *out_uMinAngleBetweenSpeakers)
{
  unsigned int v4; // r11d
  char *v8; // r10
  signed __int64 v9; // rcx
  float v10; // xmm0_4
  unsigned int v11; // edx
  unsigned int v12; // r9d
  unsigned int *v13; // r10
  unsigned int v14; // eax
  unsigned int v15; // r8d

  v4 = 0;
  if ( in_uNumAngles )
  {
    v8 = out_uSpeakerAngles;
    v9 = (char *)in_pfSpeakerAngles - out_uSpeakerAngles;
    while ( 1 )
    {
      v10 = (float)((float)(*(float *)&v8[v9] * 512.0) * 0.0027777778) + 0.5;
      *(_DWORD *)v8 = (int)v10;
      if ( (unsigned int)(int)v10 >= 0x100 )
        break;
      ++v4;
      v8 += 4;
      if ( v4 >= in_uNumAngles )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v11 = *(_DWORD *)out_uSpeakerAngles;
    if ( *(_DWORD *)out_uSpeakerAngles < 0x80u )
    {
      v12 = 1;
      if ( in_uNumAngles <= 1 )
      {
LABEL_16:
        *out_uMinAngleBetweenSpeakers = v11;
        return 1i64;
      }
      v13 = (unsigned int *)(out_uSpeakerAngles + 4);
      while ( 1 )
      {
        v14 = *(_DWORD *)&out_uSpeakerAngles[4 * v12 - 4];
        if ( *v13 < v14 )
          break;
        v15 = *v13 - v14;
        if ( v15 - 1 > 0xFE )
          break;
        if ( v15 < v11 )
          v11 = *v13 - v14;
        ++v12;
        ++v13;
        if ( v12 >= in_uNumAngles )
        {
          if ( v12 > 1 && 2 * (256 - *(_DWORD *)&out_uSpeakerAngles[4 * v12 - 4]) < v11 )
            v11 = 2 * (256 - *(_DWORD *)&out_uSpeakerAngles[4 * v12 - 4]);
          goto LABEL_16;
        }
      }
    }
  }
  return 2i64;
}

