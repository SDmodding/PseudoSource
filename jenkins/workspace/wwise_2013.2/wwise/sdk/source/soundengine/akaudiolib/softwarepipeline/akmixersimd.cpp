// File Line: 46
// RVA: 0xA98D00
int CAkMixer::MixChannelSIMD(...)
{
  float *v5; // r8
  float *v6; // r9
  __m128 v7; // xmm2
  __m128 v8; // xmm3
  float *v9; // rcx
  signed __int64 v10; // r8
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  float *v14; // rcx
  signed __int64 v15; // r8
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2

  v5 = in_pSourceData;
  v6 = &in_pSourceData[in_uNumSamples];
  v7 = _mm_shuffle_ps((__m128)in_fVolume, (__m128)in_fVolume, 0);
  if ( *(float *)&in_fVolumeDelta == 0.0 )
  {
    if ( v7.m128_f32[0] != 0.0 )
    {
      *(__m128 *)aVolumes = v7;
      v8 = v7;
      v9 = in_pDestData + 4;
      v10 = (char *)v5 - (char *)in_pDestData;
      do
      {
        v11 = *(__m128 *)((char *)v9 + v10 - 16);
        v12 = *(__m128 *)((char *)v9 + v10);
        v9 += 8;
        *((__m128 *)v9 - 3) = _mm_add_ps(_mm_mul_ps(v11, v8), *(__m128 *)((char *)v9 - 48));
        *((__m128 *)v9 - 2) = _mm_add_ps(_mm_mul_ps(v12, v8), *(__m128 *)((char *)v9 - 32));
      }
      while ( (float *)((char *)v9 + v10 - 16) < v6 );
    }
  }
  else
  {
    v13 = (__m128)in_fVolumeDelta;
    aVolumes[0] = v7.m128_f32[0];
    v14 = in_pDestData + 4;
    v15 = (char *)v5 - (char *)in_pDestData;
    v13.m128_f32[0] = *(float *)&in_fVolumeDelta * 4.0;
    aVolumes[1] = v7.m128_f32[0] + *(float *)&in_fVolumeDelta;
    v16 = _mm_shuffle_ps(v13, v13, 0);
    aVolumes[2] = (float)(*(float *)&in_fVolumeDelta * 2.0) + v7.m128_f32[0];
    aVolumes[3] = (float)(*(float *)&in_fVolumeDelta * 3.0) + v7.m128_f32[0];
    v17 = *(__m128 *)aVolumes;
    v18 = _mm_add_ps(*(__m128 *)aVolumes, v16);
    v19 = _mm_add_ps(v16, v16);
    do
    {
      v20 = *(__m128 *)((char *)v14 + v15 - 16);
      v21 = *(__m128 *)((char *)v14 + v15);
      v14 += 8;
      v22 = _mm_mul_ps(v20, v17);
      v23 = _mm_mul_ps(v21, v18);
      v17 = _mm_add_ps(v17, v19);
      v18 = _mm_add_ps(v18, v19);
      *((__m128 *)v14 - 3) = _mm_add_ps(v22, *(__m128 *)((char *)v14 - 48));
      *((__m128 *)v14 - 2) = _mm_add_ps(v23, *(__m128 *)((char *)v14 - 32));
    }
    while ( (float *)((char *)v14 + v15 - 16) < v6 );
  }
}

// File Line: 884
// RVA: 0xA98C20
void __fastcall CAkMixer::MixAndInterleaveStereo(CAkMixer *this, AkAudioBufferBus *in_pInputBuffer, AkPipelineBufferBase *in_pOutputBuffer)
{
  __m128 *v3; // r9
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 *v6; // r8
  __m128 v7; // xmm4
  __m128 *v8; // rdx
  unsigned int i; // eax
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  unsigned int v14; // [rsp+Ch] [rbp+Ch]

  v3 = (__m128 *)in_pOutputBuffer->pData;
  *(float *)&v14 = (float)(in_pInputBuffer->m_fNextVolume - in_pInputBuffer->m_fPreviousVolume)
                 * this->m_fOneOverNumFrames;
  aVolumes[0] = in_pInputBuffer->m_fPreviousVolume;
  v4 = (__m128)v14;
  v4.m128_f32[0] = *(float *)&v14 * 2.0;
  aVolumes[1] = *(float *)&v14 + aVolumes[0];
  aVolumes[3] = (float)(*(float *)&v14 * 3.0) + aVolumes[0];
  v5 = _mm_shuffle_ps(v4, v4, 0);
  aVolumes[2] = (float)(*(float *)&v14 * 2.0) + aVolumes[0];
  v6 = (__m128 *)in_pInputBuffer->pData;
  v7 = *(__m128 *)aVolumes;
  v8 = (__m128 *)((char *)in_pInputBuffer->pData + 4 * in_pInputBuffer->uMaxFrames);
  for ( i = (unsigned int)this->m_usMaxFrames >> 2; i; --i )
  {
    v10 = *v6;
    v11 = *v8;
    v3 += 2;
    ++v6;
    ++v8;
    v12 = _mm_mul_ps(v10, v7);
    v13 = _mm_mul_ps(v11, v7);
    v7 = _mm_add_ps(v7, v5);
    v3[-2] = _mm_unpacklo_ps(v12, v13);
    v3[-1] = _mm_unpackhi_ps(v12, v13);
  }
}

// File Line: 897
// RVA: 0xA98790
void __usercall CAkMixer::MixAndInterleave51(CAkMixer *this@<rcx>, AkAudioBufferBus *in_pInputBuffer@<rdx>, AkPipelineBufferBase *in_pOutputBuffer@<r8>, __m128 a4@<xmm11>)
{
  __m128 *v4; // r10
  __m128 v5; // xmm11
  __int64 v6; // r8
  __m128 *v7; // r9
  __m128 v8; // xmm12
  __m128 *v9; // rdx
  __m128 *v10; // r11
  __m128 *v11; // rbx
  __m128 *v12; // rdi
  __m128 *v13; // r8
  unsigned int i; // eax
  __m128 v15; // xmm10
  __m128 v16; // xmm8
  __m128 v17; // xmm7
  __m128 v18; // xmm10
  __m128 v19; // xmm8
  __m128 v20; // xmm7
  __m128 v21; // xmm9
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm9
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm10
  __m128 v31; // xmm8
  __m128 v32; // xmm9
  float v33; // [rsp+80h] [rbp+8h]
  float v34; // [rsp+84h] [rbp+Ch]

  v4 = (__m128 *)in_pOutputBuffer->pData;
  v33 = in_pInputBuffer->m_fPreviousVolume;
  v34 = (float)(in_pInputBuffer->m_fNextVolume - v33) * this->m_fOneOverNumFrames;
  aVolumes[0] = in_pInputBuffer->m_fPreviousVolume;
  aVolumes[1] = v34 + v33;
  aVolumes[3] = (float)(v34 * 3.0) + v33;
  a4.m128_f32[0] = v34 * 2.0;
  v5 = _mm_shuffle_ps(a4, a4, 0);
  aVolumes[2] = (float)(v34 * 2.0) + v33;
  v6 = in_pInputBuffer->uMaxFrames;
  v7 = (__m128 *)in_pInputBuffer->pData;
  v8 = *(__m128 *)aVolumes;
  v9 = (__m128 *)((char *)in_pInputBuffer->pData + 4 * v6);
  v10 = (__m128 *)((char *)v7 + 8 * v6);
  v11 = (__m128 *)((char *)v7 + 20 * v6);
  v12 = (__m128 *)((char *)v7 + 12 * v6);
  v13 = &v7[v6];
  for ( i = (unsigned int)this->m_usMaxFrames >> 2; i; --i )
  {
    v15 = *v7;
    v16 = *v12;
    v17 = *v9;
    v4 += 6;
    ++v7;
    ++v9;
    ++v12;
    v18 = _mm_mul_ps(v15, v8);
    v19 = _mm_mul_ps(v16, v8);
    v20 = _mm_mul_ps(v17, v8);
    v21 = *v10;
    v22 = *v13;
    v23 = *v11;
    ++v10;
    ++v11;
    ++v13;
    v24 = _mm_mul_ps(v21, v8);
    v25 = _mm_mul_ps(v22, v8);
    v26 = _mm_mul_ps(v23, v8);
    v8 = _mm_add_ps(v8, v5);
    v27 = _mm_shuffle_ps(v18, v20, 68);
    v28 = _mm_shuffle_ps(v19, v25, 68);
    v29 = _mm_shuffle_ps(v24, v26, 68);
    v30 = _mm_shuffle_ps(v18, v20, 238);
    v4[-6] = _mm_shuffle_ps(v27, v29, 136);
    v4[-5] = _mm_shuffle_ps(v28, v27, 216);
    v31 = _mm_shuffle_ps(v19, v25, 238);
    v32 = _mm_shuffle_ps(v24, v26, 238);
    v4[-4] = _mm_shuffle_ps(v29, v28, 221);
    v4[-3] = _mm_shuffle_ps(v30, v32, 136);
    v4[-2] = _mm_shuffle_ps(v31, v30, 216);
    v4[-1] = _mm_shuffle_ps(v32, v31, 221);
  }
}

// File Line: 918
// RVA: 0xA98990
void __usercall CAkMixer::MixAndInterleave71(CAkMixer *this@<rcx>, AkAudioBufferBus *in_pInputBuffer@<rdx>, AkPipelineBufferBase *in_pOutputBuffer@<r8>, __m128 a4@<xmm14>)
{
  __m128 *v4; // r10
  CAkMixer *v5; // r9
  __m128 v6; // xmm14
  signed __int64 v7; // rcx
  __m128 *v8; // r8
  __m128 v9; // xmm15
  __m128 *v10; // rsi
  signed __int64 v11; // r11
  __m128 *v12; // rbp
  __m128 *v13; // rbx
  __m128 *v14; // rdi
  __m128 *v15; // rcx
  unsigned int v16; // eax
  __m128 *v17; // rdx
  __m128 *i; // r11
  __m128 v19; // xmm13
  __m128 v20; // xmm11
  __m128 v21; // xmm10
  __m128 v22; // xmm13
  __m128 v23; // xmm11
  __m128 v24; // xmm10
  __m128 v25; // xmm12
  __m128 v26; // xmm7
  __m128 v27; // xmm9
  __m128 v28; // xmm12
  __m128 v29; // xmm7
  __m128 v30; // xmm9
  __m128 v31; // xmm8
  __m128 v32; // xmm6
  __m128 v33; // xmm8
  __m128 v34; // xmm6
  __m128 v35; // xmm5
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm13
  __m128 v40; // xmm11
  __m128 v41; // xmm12
  __m128 v42; // xmm9
  float v43; // [rsp+B0h] [rbp+8h]
  float v44; // [rsp+B4h] [rbp+Ch]

  v4 = (__m128 *)in_pOutputBuffer->pData;
  v5 = this;
  v43 = in_pInputBuffer->m_fPreviousVolume;
  v44 = (float)(in_pInputBuffer->m_fNextVolume - v43) * this->m_fOneOverNumFrames;
  aVolumes[0] = in_pInputBuffer->m_fPreviousVolume;
  aVolumes[1] = v44 + v43;
  aVolumes[3] = (float)(v44 * 3.0) + v43;
  a4.m128_f32[0] = v44 * 2.0;
  v6 = _mm_shuffle_ps(a4, a4, 0);
  aVolumes[2] = (float)(v44 * 2.0) + v43;
  v7 = in_pInputBuffer->uMaxFrames;
  v8 = (__m128 *)in_pInputBuffer->pData;
  v9 = *(__m128 *)aVolumes;
  v10 = (__m128 *)((char *)in_pInputBuffer->pData + 12 * v7);
  v11 = v7;
  v12 = (__m128 *)((char *)in_pInputBuffer->pData + 20 * v7);
  v13 = (__m128 *)((char *)in_pInputBuffer->pData + 4 * v7);
  v14 = (__m128 *)((char *)in_pInputBuffer->pData + 8 * v7);
  v15 = (__m128 *)((char *)in_pInputBuffer->pData + 24 * v7);
  v16 = (unsigned int)v5->m_usMaxFrames >> 2;
  v17 = (__m128 *)((char *)in_pInputBuffer->pData + 28 * in_pInputBuffer->uMaxFrames);
  for ( i = &v8[v11]; v16; --v16 )
  {
    v19 = *v8;
    v20 = *v10;
    v21 = *v13;
    v4 += 8;
    ++v8;
    ++v13;
    ++v10;
    v22 = _mm_mul_ps(v19, v9);
    v23 = _mm_mul_ps(v20, v9);
    v24 = _mm_mul_ps(v21, v9);
    v25 = *v14;
    v26 = *i;
    v27 = *v12;
    ++v14;
    ++i;
    ++v12;
    v28 = _mm_mul_ps(v25, v9);
    v29 = _mm_mul_ps(v26, v9);
    v30 = _mm_mul_ps(v27, v9);
    v31 = *v17;
    v32 = *v15;
    ++v17;
    ++v15;
    v33 = _mm_mul_ps(v31, v9);
    v34 = _mm_mul_ps(v32, v9);
    v35 = _mm_shuffle_ps(v22, v24, 68);
    v9 = _mm_add_ps(v9, v6);
    v36 = _mm_shuffle_ps(v23, v29, 68);
    v37 = _mm_shuffle_ps(v28, v33, 68);
    v38 = _mm_shuffle_ps(v30, v34, 68);
    v39 = _mm_shuffle_ps(v22, v24, 238);
    v4[-8] = _mm_shuffle_ps(v35, v37, 136);
    v4[-7] = _mm_shuffle_ps(v36, v38, 136);
    v40 = _mm_shuffle_ps(v23, v29, 238);
    v41 = _mm_shuffle_ps(v28, v33, 238);
    v42 = _mm_shuffle_ps(v30, v34, 238);
    v4[-6] = _mm_shuffle_ps(v35, v37, 221);
    v4[-5] = _mm_shuffle_ps(v36, v38, 221);
    v4[-4] = _mm_shuffle_ps(v39, v41, 136);
    v4[-3] = _mm_shuffle_ps(v40, v42, 136);
    v4[-2] = _mm_shuffle_ps(v39, v41, 221);
    v4[-1] = _mm_shuffle_ps(v40, v42, 221);
  }
}

