// File Line: 25
// RVA: 0xAD88D0
void __fastcall DSP::CAkPinkNoise::CAkPinkNoise(DSP::CAkPinkNoise *this)
{
  DSP::CAkWhiteNoise::CAkWhiteNoise(this);
  *(_QWORD *)&this->m_DCFilter.m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_DCFilter.m_fA1 = 0i64;
  this->m_fRunningSum = 0.0;
  *(_QWORD *)this->m_RandGenTable = 0i64;
  *(_QWORD *)&this->m_RandGenTable[2] = 0i64;
  *(_QWORD *)&this->m_RandGenTable[4] = 0i64;
  *(_QWORD *)&this->m_RandGenTable[6] = 0i64;
  *(_QWORD *)&this->m_RandGenTable[8] = 0i64;
  *(_QWORD *)&this->m_RandGenTable[10] = 0i64;
  *(_QWORD *)&this->m_RandGenTable[12] = 0i64;
  *(_QWORD *)&this->m_RandGenTable[14] = 0i64;
}

// File Line: 85
// RVA: 0xAD8920
void __fastcall DSP::CAkPinkNoise::GenerateBuffer(
        DSP::CAkPinkNoise *this,
        float *out_pfBuffer,
        unsigned int in_uNumFrames)
{
  __int64 v3; // r14
  unsigned int m_uIndex; // edi
  float m_fRunningSum; // xmm6_4
  float *v8; // r10
  float *v9; // r9
  float *v10; // r11
  float *v11; // r8
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
  signed __int64 v30; // r10
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
  DSP::CAkWhiteNoise::GenerateBuffer(this, out_pfBuffer, 2 * in_uNumFrames);
  m_uIndex = this->m_uIndex;
  m_fRunningSum = this->m_fRunningSum;
  v35 = *(_QWORD *)this->m_RandGenTable;
  v8 = &out_pfBuffer[v3];
  v36 = *(_QWORD *)&this->m_RandGenTable[2];
  v9 = out_pfBuffer;
  v37 = *(_QWORD *)&this->m_RandGenTable[4];
  v10 = v8;
  v38 = *(_QWORD *)&this->m_RandGenTable[6];
  v39 = *(_QWORD *)&this->m_RandGenTable[8];
  v40 = *(_QWORD *)&this->m_RandGenTable[10];
  v41 = *(_QWORD *)&this->m_RandGenTable[12];
  v42 = *(_QWORD *)&this->m_RandGenTable[14];
  if ( out_pfBuffer < v8 )
  {
    if ( (4 * v3 + 3) / 4 >= 4 )
    {
      v11 = v8 - 3;
      do
      {
        v12 = *v8;
        v9 += 4;
        v8 += 4;
        v13 = CountTrailingZerosTable[(unsigned __int64)(125613361
                                                       * ((unsigned __int16)(m_uIndex + 1) & (unsigned int)-(unsigned __int16)(m_uIndex + 1))) >> 27];
        v14 = m_fRunningSum - *((float *)&v35 + v13);
        *((float *)&v35 + v13) = v12;
        v15 = v14 + v12;
        v16 = v15 + *(v9 - 4);
        v17 = CountTrailingZerosTable[(unsigned __int64)(125613361
                                                       * ((unsigned __int16)(m_uIndex + 2) & (unsigned int)-(unsigned __int16)(m_uIndex + 2))) >> 27];
        v18 = v15 - *((float *)&v35 + v17);
        *(v9 - 4) = v16 * 0.14705883;
        v19 = *(v8 - 3);
        *((float *)&v35 + v17) = v19;
        v20 = v18 + v19;
        v21 = CountTrailingZerosTable[(unsigned __int64)(125613361
                                                       * ((unsigned __int16)(m_uIndex + 3) & (unsigned int)-(unsigned __int16)(m_uIndex + 3))) >> 27];
        m_uIndex = (unsigned __int16)(m_uIndex + 4);
        v22 = v20 + *(v9 - 3);
        v23 = v20 - *((float *)&v35 + v21);
        *(v9 - 3) = v22 * 0.14705883;
        v24 = *(v8 - 2);
        *((float *)&v35 + v21) = v24;
        v25 = v23 + v24;
        v26 = CountTrailingZerosTable[(unsigned __int64)(125613361 * (m_uIndex & -m_uIndex)) >> 27];
        v27 = v25 + *(v9 - 2);
        v28 = v25 - *((float *)&v35 + v26);
        *(v9 - 2) = v27 * 0.14705883;
        v29 = *(v8 - 1);
        m_fRunningSum = v28 + v29;
        *((float *)&v35 + v26) = v29;
        *(v9 - 1) = (float)(m_fRunningSum + *(v9 - 1)) * 0.14705883;
      }
      while ( (__int64)v9 < (__int64)v11 );
    }
    if ( v9 < v10 )
    {
      v30 = (char *)v8 - (char *)v9;
      do
      {
        v31 = *(float *)((char *)v9++ + v30);
        m_uIndex = (unsigned __int16)(m_uIndex + 1);
        v32 = CountTrailingZerosTable[(unsigned __int64)(125613361 * (m_uIndex & -m_uIndex)) >> 27];
        v33 = m_fRunningSum - *((float *)&v35 + v32);
        *((float *)&v35 + v32) = v31;
        m_fRunningSum = v33 + v31;
        *(v9 - 1) = (float)(m_fRunningSum + *(v9 - 1)) * 0.14705883;
      }
      while ( v9 < v10 );
    }
  }
  DSP::OnePoleZeroHPFilter::ProcessBuffer(&this->m_DCFilter, out_pfBuffer, v3);
  v34 = v35;
  this->m_uIndex = m_uIndex;
  this->m_fRunningSum = m_fRunningSum;
  *(_QWORD *)this->m_RandGenTable = v34;
  *(_QWORD *)&this->m_RandGenTable[2] = v36;
  *(_QWORD *)&this->m_RandGenTable[4] = v37;
  *(_QWORD *)&this->m_RandGenTable[6] = v38;
  *(_QWORD *)&this->m_RandGenTable[8] = v39;
  *(_QWORD *)&this->m_RandGenTable[10] = v40;
  *(_QWORD *)&this->m_RandGenTable[12] = v41;
  *(_QWORD *)&this->m_RandGenTable[14] = v42;
}

