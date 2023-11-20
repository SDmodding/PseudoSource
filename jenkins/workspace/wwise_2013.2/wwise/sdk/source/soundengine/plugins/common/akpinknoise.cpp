// File Line: 25
// RVA: 0xAD88D0
void __fastcall DSP::CAkPinkNoise::CAkPinkNoise(DSP::CAkPinkNoise *this)
{
  DSP::CAkPinkNoise *v1; // rbx

  v1 = this;
  DSP::CAkWhiteNoise::CAkWhiteNoise((DSP::CAkWhiteNoise *)&this->m_uLCGState);
  *(_QWORD *)&v1->m_DCFilter.m_fFFwd1 = 0i64;
  *(_QWORD *)&v1->m_DCFilter.m_fA1 = 0i64;
  v1->m_fRunningSum = 0.0;
  *(_QWORD *)v1->m_RandGenTable = 0i64;
  *(_QWORD *)&v1->m_RandGenTable[2] = 0i64;
  *(_QWORD *)&v1->m_RandGenTable[4] = 0i64;
  *(_QWORD *)&v1->m_RandGenTable[6] = 0i64;
  *(_QWORD *)&v1->m_RandGenTable[8] = 0i64;
  *(_QWORD *)&v1->m_RandGenTable[10] = 0i64;
  *(_QWORD *)&v1->m_RandGenTable[12] = 0i64;
  *(_QWORD *)&v1->m_RandGenTable[14] = 0i64;
}

// File Line: 85
// RVA: 0xAD8920
void __fastcall DSP::CAkPinkNoise::GenerateBuffer(DSP::CAkPinkNoise *this, float *out_pfBuffer, unsigned int in_uNumFrames)
{
  __int64 v3; // r14
  float *v4; // rsi
  DSP::CAkPinkNoise *v5; // rbx
  unsigned int v6; // edi
  float v7; // xmm6_4
  float *v8; // r10
  float *v9; // r9
  float *v10; // r11
  signed __int64 v11; // r8
  float v12; // xmm0_4
  __int64 v13; // rcx
  float v14; // xmm6_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  __int64 v17; // rcx
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm6_4
  __int64 v21; // rcx
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  __int64 v26; // rcx
  float v27; // xmm0_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  char *v30; // r10
  float v31; // xmm0_4
  __int64 v32; // rcx
  float v33; // xmm6_4
  __int64 v34; // rax
  __int64 v35; // [rsp+20h] [rbp-58h]
  __int64 v36; // [rsp+28h] [rbp-50h]
  __int64 v37; // [rsp+30h] [rbp-48h]
  __int64 v38; // [rsp+38h] [rbp-40h]
  __int64 v39; // [rsp+40h] [rbp-38h]
  __int64 v40; // [rsp+48h] [rbp-30h]
  __int64 v41; // [rsp+50h] [rbp-28h]
  __int64 v42; // [rsp+58h] [rbp-20h]

  v3 = in_uNumFrames;
  v4 = out_pfBuffer;
  v5 = this;
  DSP::CAkWhiteNoise::GenerateBuffer((DSP::CAkWhiteNoise *)&this->m_uLCGState, out_pfBuffer, 2 * in_uNumFrames);
  v6 = v5->m_uIndex;
  v7 = v5->m_fRunningSum;
  v35 = *(_QWORD *)v5->m_RandGenTable;
  v8 = &v4[v3];
  v36 = *(_QWORD *)&v5->m_RandGenTable[2];
  v9 = v4;
  v37 = *(_QWORD *)&v5->m_RandGenTable[4];
  v10 = v8;
  v38 = *(_QWORD *)&v5->m_RandGenTable[6];
  v39 = *(_QWORD *)&v5->m_RandGenTable[8];
  v40 = *(_QWORD *)&v5->m_RandGenTable[10];
  v41 = *(_QWORD *)&v5->m_RandGenTable[12];
  v42 = *(_QWORD *)&v5->m_RandGenTable[14];
  if ( v4 < v8 )
  {
    if ( (4 * v3 + 3) / 4 >= 4 )
    {
      v11 = (signed __int64)(v8 - 3);
      do
      {
        v12 = *v8;
        v9 += 4;
        v8 += 4;
        v13 = CountTrailingZerosTable[(unsigned __int64)(125613361
                                                       * ((unsigned __int16)(v6 + 1) & (unsigned int)-(unsigned __int16)(v6 + 1))) >> 27];
        v14 = v7 - *((float *)&v35 + v13);
        *((float *)&v35 + v13) = v12;
        v15 = v14 + v12;
        v16 = v15 + *(v9 - 4);
        v17 = CountTrailingZerosTable[(unsigned __int64)(125613361
                                                       * ((unsigned __int16)(v6 + 2) & (unsigned int)-(unsigned __int16)(v6 + 2))) >> 27];
        v18 = v15 - *((float *)&v35 + v17);
        *(v9 - 4) = v16 * 0.14705883;
        v19 = *(v8 - 3);
        *((float *)&v35 + v17) = v19;
        v20 = v18 + v19;
        v21 = CountTrailingZerosTable[(unsigned __int64)(125613361
                                                       * ((unsigned __int16)(v6 + 3) & (unsigned int)-(unsigned __int16)(v6 + 3))) >> 27];
        v6 = (unsigned __int16)(v6 + 4);
        v22 = v20 + *(v9 - 3);
        v23 = v20 - *((float *)&v35 + v21);
        *(v9 - 3) = v22 * 0.14705883;
        v24 = *(v8 - 2);
        *((float *)&v35 + v21) = v24;
        v25 = v23 + v24;
        v26 = CountTrailingZerosTable[(unsigned __int64)(125613361 * (v6 & -v6)) >> 27];
        v27 = v25 + *(v9 - 2);
        v28 = v25 - *((float *)&v35 + v26);
        *(v9 - 2) = v27 * 0.14705883;
        v29 = *(v8 - 1);
        v7 = v28 + v29;
        *((float *)&v35 + v26) = v29;
        *(v9 - 1) = (float)(v7 + *(v9 - 1)) * 0.14705883;
      }
      while ( (signed __int64)v9 < v11 );
    }
    if ( v9 < v10 )
    {
      v30 = (char *)((char *)v8 - (char *)v9);
      do
      {
        v31 = *(float *)((char *)v9 + (_QWORD)v30);
        ++v9;
        v6 = (unsigned __int16)(v6 + 1);
        v32 = CountTrailingZerosTable[(unsigned __int64)(125613361 * (v6 & -v6)) >> 27];
        v33 = v7 - *((float *)&v35 + v32);
        *((float *)&v35 + v32) = v31;
        v7 = v33 + v31;
        *(v9 - 1) = (float)(v7 + *(v9 - 1)) * 0.14705883;
      }
      while ( v9 < v10 );
    }
  }
  DSP::OnePoleZeroHPFilter::ProcessBuffer(&v5->m_DCFilter, v4, v3);
  v34 = v35;
  v5->m_uIndex = v6;
  v5->m_fRunningSum = v7;
  *(_QWORD *)v5->m_RandGenTable = v34;
  *(_QWORD *)&v5->m_RandGenTable[2] = v36;
  *(_QWORD *)&v5->m_RandGenTable[4] = v37;
  *(_QWORD *)&v5->m_RandGenTable[6] = v38;
  *(_QWORD *)&v5->m_RandGenTable[8] = v39;
  *(_QWORD *)&v5->m_RandGenTable[10] = v40;
  *(_QWORD *)&v5->m_RandGenTable[12] = v41;
  *(_QWORD *)&v5->m_RandGenTable[14] = v42;
}

