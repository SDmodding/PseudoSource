// File Line: 35
// RVA: 0xAFB630
__int64 __fastcall DSP::UniComb::Init(
        DSP::UniComb *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uDelayLength,
        unsigned int in_uMaxBufferLength,
        float in_fFeedbackGain,
        float in_fFeedforwardGain,
        float in_fDryGain,
        float in_fMaxModDepth)
{
  unsigned int v8; // eax
  unsigned int v11; // eax
  float *v12; // rax

  v8 = 8;
  if ( in_uDelayLength > 8 )
    v8 = in_uDelayLength;
  this->m_uDelayLength = (v8 + 3) & 0xFFFFFFFC;
  DSP::UniComb::SetParams(this, in_fFeedbackGain, in_fFeedforwardGain, in_fDryGain, in_fMaxModDepth);
  this->m_fPrevFeedbackGain = this->m_fFeedbackGain;
  this->m_fPrevFeedforwardGain = this->m_fFeedforwardGain;
  this->m_fPrevDryGain = this->m_fDryGain;
  v11 = 2 * this->m_uDelayLength + 1024;
  this->m_uAllocatedDelayLength = v11;
  v12 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4i64 * v11);
  this->m_pfDelay = v12;
  if ( !v12 )
    return 52i64;
  this->m_uWritePos = 0;
  return 1i64;
}

// File Line: 60
// RVA: 0xAFB6E0
void __fastcall DSP::UniComb::Term(DSP::UniComb *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pfDelay )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pfDelay = 0i64;
    this->m_uAllocatedDelayLength = 0;
  }
}

// File Line: 70
// RVA: 0xAFB720
void __fastcall DSP::UniComb::Reset(DSP::UniComb *this)
{
  float *m_pfDelay; // rcx

  m_pfDelay = this->m_pfDelay;
  if ( m_pfDelay )
    memset(m_pfDelay, 0, 4 * this->m_uAllocatedDelayLength);
  this->m_uWritePos = 0;
}

// File Line: 84
// RVA: 0xAFB760
void __fastcall DSP::UniComb::SetParams(
        DSP::UniComb *this,
        float in_fFeedbackGain,
        float in_fFeedforwardGain,
        float in_fDryGain,
        float in_fMaxModDepth)
{
  signed int m_uDelayLength; // edx
  float v6; // xmm0_4
  unsigned int m_uMaxModWidth; // eax

  m_uDelayLength = this->m_uDelayLength;
  this->m_fFeedforwardGain = in_fFeedforwardGain;
  this->m_fFeedbackGain = in_fFeedbackGain;
  this->m_fDryGain = in_fDryGain;
  v6 = (float)m_uDelayLength * in_fMaxModDepth;
  this->m_uMaxModWidth = 4 * ((unsigned int)(int)v6 >> 2);
  if ( ((32 * ((unsigned int)(int)v6 >> 2) + 4111) & 0xFFFFFFF0) >= 0x19000 )
    this->m_uMaxModWidth = (int)(float)((float)(98304.0 / (float)((float)((float)m_uDelayLength * 2.0) * 4.0))
                                      * (float)m_uDelayLength) & 0xFFFFFFFC;
  m_uMaxModWidth = this->m_uMaxModWidth;
  if ( m_uMaxModWidth >= m_uDelayLength )
    this->m_uMaxModWidth = m_uMaxModWidth - 4;
}

// File Line: 127
// RVA: 0xAFB7F0
void __fastcall DSP::UniComb::ProcessBuffer(
        DSP::UniComb *this,
        float *io_pfBuffer,
        unsigned int in_uNumFrames,
        float *in_pfLFOBuf)
{
  if ( in_pfLFOBuf )
    DSP::UniComb::ProcessBufferLFO(this, io_pfBuffer, in_uNumFrames, in_pfLFOBuf, this->m_pfDelay);
  else
    DSP::UniComb::ProcessBufferNoLFO(this, io_pfBuffer, in_uNumFrames, this->m_pfDelay);
}

// File Line: 170
// RVA: 0xAFB820
void __fastcall DSP::UniComb::ProcessBufferNoLFO(
        DSP::UniComb *this,
        float *io_pfBuffer,
        int in_uNumFrames,
        float *io_pfDelay)
{
  float m_fPrevFeedbackGain; // xmm2_4
  float m_fPrevFeedforwardGain; // xmm3_4
  unsigned int m_uAllocatedDelayLength; // edi
  unsigned int m_uWritePos; // r8d
  float m_fFeedbackGain; // xmm8_4
  float m_fFeedforwardGain; // xmm9_4
  float m_fDryGain; // xmm10_4
  unsigned int v14; // r14d
  float m_fPrevDryGain; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float i; // xmm7_4
  int v21; // r9d
  __int64 v22; // rdx
  unsigned int v23; // ecx
  float v24; // xmm1_4
  __int64 v25; // rax
  float v26; // xmm0_4

  m_fPrevFeedbackGain = this->m_fPrevFeedbackGain;
  m_fPrevFeedforwardGain = this->m_fPrevFeedforwardGain;
  m_uAllocatedDelayLength = this->m_uAllocatedDelayLength;
  m_uWritePos = this->m_uWritePos;
  m_fFeedbackGain = this->m_fFeedbackGain;
  m_fFeedforwardGain = this->m_fFeedforwardGain;
  m_fDryGain = this->m_fDryGain;
  v14 = m_uAllocatedDelayLength - this->m_uDelayLength;
  m_fPrevDryGain = this->m_fPrevDryGain;
  v17 = 1.0 / (float)in_uNumFrames;
  v18 = (float)(m_fFeedbackGain - m_fPrevFeedbackGain) * v17;
  v19 = (float)(m_fFeedforwardGain - m_fPrevFeedforwardGain) * v17;
  for ( i = (float)(m_fDryGain - m_fPrevDryGain) * v17; in_uNumFrames; m_uWritePos %= m_uAllocatedDelayLength )
  {
    v21 = in_uNumFrames;
    v22 = (v14 + m_uWritePos) % m_uAllocatedDelayLength;
    v23 = m_uAllocatedDelayLength - v22;
    if ( m_uAllocatedDelayLength - m_uWritePos < m_uAllocatedDelayLength - (unsigned int)v22 )
      v23 = m_uAllocatedDelayLength - m_uWritePos;
    if ( v23 < in_uNumFrames )
      v21 = v23;
    for ( in_uNumFrames -= v21; v21; --v21 )
    {
      v24 = io_pfDelay[v22];
      v25 = m_uWritePos;
      m_fPrevFeedbackGain = m_fPrevFeedbackGain + v18;
      ++io_pfBuffer;
      ++m_uWritePos;
      v22 = (unsigned int)(v22 + 1);
      m_fPrevFeedforwardGain = m_fPrevFeedforwardGain + v19;
      m_fPrevDryGain = m_fPrevDryGain + i;
      v26 = (float)(v24 * m_fPrevFeedbackGain) + *(io_pfBuffer - 1);
      io_pfDelay[v25] = v26;
      *(io_pfBuffer - 1) = (float)(v26 * m_fPrevDryGain) + (float)(v24 * m_fPrevFeedforwardGain);
    }
  }
  this->m_fPrevFeedbackGain = m_fFeedbackGain;
  this->m_fPrevFeedforwardGain = m_fFeedforwardGain;
  this->m_fPrevDryGain = m_fDryGain;
  this->m_uWritePos = m_uWritePos;
}

// File Line: 340
// RVA: 0xAFB9B0
void __fastcall DSP::UniComb::ProcessBufferLFO(
        DSP::UniComb *this,
        float *io_pfBuffer,
        int in_uNumFrames,
        float *in_pfLFOBuf,
        float *io_pfDelay)
{
  unsigned int m_uAllocatedDelayLength; // ebx
  unsigned int m_uWritePos; // r10d
  float m_fPrevFeedbackGain; // xmm3_4
  float m_fPrevFeedforwardGain; // xmm4_4
  float m_fPrevDryGain; // xmm5_4
  signed int m_uMaxModWidth; // r15d
  unsigned int v12; // r11d
  float m_fFeedbackGain; // xmm11_4
  float m_fFeedforwardGain; // xmm12_4
  unsigned int v16; // r12d
  unsigned int v18; // r14d
  unsigned int v19; // edx
  float m_fDryGain; // xmm13_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm8_4
  unsigned int v25; // r8d
  unsigned int v26; // ecx
  float v27; // xmm0_4
  unsigned int v28; // r9d
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  unsigned int v32; // ecx
  unsigned int v33; // r8d
  unsigned int v34; // ecx
  unsigned int v35; // r8d
  float v36; // xmm10_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  int v41; // edx
  float v42; // xmm1_4
  __int64 v43; // rax
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  __int64 v47; // rax
  __int64 v48; // r10
  float v49; // xmm2_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm0_4
  float v56; // xmm0_4
  float v57; // xmm5_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm0_4
  __int64 v62; // r10
  float v63; // xmm1_4
  float v64; // xmm3_4
  float v65; // xmm4_4
  float v66; // xmm2_4
  float v67; // xmm0_4
  float v68; // xmm5_4
  float v69; // xmm3_4
  float v70; // xmm1_4
  float v71; // xmm4_4
  __int64 v72; // r10
  float v73; // xmm0_4
  float v74; // xmm5_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  float v77; // xmm1_4
  float v78; // xmm0_4
  float v79; // xmm2_4
  float v80; // xmm3_4
  float v81; // xmm4_4
  float v82; // xmm0_4
  float v83; // xmm0_4
  __int64 v84; // r10
  float v85; // xmm5_4
  float v86; // xmm1_4
  float v87; // xmm2_4
  float v88; // xmm1_4
  float v89; // xmm0_4
  __int64 v90; // r10
  float v91; // xmm1_4
  float v92; // xmm3_4
  float v93; // xmm4_4
  float v94; // xmm5_4
  __int64 v95; // rax
  float v96; // xmm1_4
  float v97; // xmm2_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  float v100; // xmm1_4
  float v101; // xmm0_4
  float v102; // xmm2_4
  float v103; // xmm3_4
  float v104; // xmm4_4
  float v105; // xmm0_4
  float v106; // xmm0_4
  __int64 v107; // r10
  float v108; // xmm5_4
  float v109; // xmm1_4
  float v110; // xmm0_4
  float v111; // xmm2_4
  float v112; // xmm0_4
  float v113; // xmm0_4
  float v114; // xmm0_4
  __int64 v115; // r10
  float v116; // xmm1_4
  float v117; // xmm2_4
  float v118; // xmm0_4

  m_uAllocatedDelayLength = this->m_uAllocatedDelayLength;
  m_uWritePos = this->m_uWritePos;
  m_fPrevFeedbackGain = this->m_fPrevFeedbackGain;
  m_fPrevFeedforwardGain = this->m_fPrevFeedforwardGain;
  m_fPrevDryGain = this->m_fPrevDryGain;
  m_uMaxModWidth = this->m_uMaxModWidth;
  v12 = in_uNumFrames;
  m_fFeedbackGain = this->m_fFeedbackGain;
  m_fFeedforwardGain = this->m_fFeedforwardGain;
  v16 = m_uAllocatedDelayLength - this->m_uDelayLength;
  v18 = m_uAllocatedDelayLength - m_uMaxModWidth - 1;
  v19 = (v16 + m_uWritePos) % m_uAllocatedDelayLength;
  m_fDryGain = this->m_fDryGain;
  v21 = 1.0 / (float)in_uNumFrames;
  v22 = (float)(m_fFeedbackGain - m_fPrevFeedbackGain) * v21;
  v23 = (float)(m_fFeedforwardGain - m_fPrevFeedforwardGain) * v21;
  v24 = (float)(m_fDryGain - m_fPrevDryGain) * v21;
  if ( in_uNumFrames )
  {
    do
    {
      v25 = v12;
      v26 = m_uAllocatedDelayLength - m_uWritePos - 1;
      if ( v18 - v19 < v26 )
        v26 = v18 - v19;
      if ( v26 < v12 )
        v25 = v26;
      while ( v12 )
      {
        if ( v19 < v18 && v19 >= m_uMaxModWidth && m_uWritePos != m_uAllocatedDelayLength - 1 && v25 >= 8 )
          break;
        v27 = *in_pfLFOBuf;
        v28 = v16 + m_uWritePos;
        --v12;
        ++in_pfLFOBuf;
        ++io_pfBuffer;
        m_fPrevFeedbackGain = m_fPrevFeedbackGain + v22;
        m_fPrevFeedforwardGain = m_fPrevFeedforwardGain + v23;
        m_fPrevDryGain = m_fPrevDryGain + v24;
        v29 = (float)((float)m_uMaxModWidth * v27) + (float)(int)(v16 + m_uWritePos);
        v25 = v12;
        v30 = (float)((float)(1.0 - (float)(v29 - (float)(int)v29)) * io_pfDelay[(int)v29 % m_uAllocatedDelayLength])
            + (float)((float)(v29 - (float)(int)v29) * io_pfDelay[((int)v29 + 1) % m_uAllocatedDelayLength]);
        v31 = (float)(v30 * m_fPrevFeedbackGain) + *(io_pfBuffer - 1);
        io_pfDelay[m_uWritePos] = v31;
        *(io_pfBuffer - 1) = (float)(v31 * m_fPrevDryGain) + (float)(v30 * m_fPrevFeedforwardGain);
        m_uWritePos = (m_uWritePos + 1) % m_uAllocatedDelayLength;
        v19 = (v28 + 1) % m_uAllocatedDelayLength;
        v32 = m_uAllocatedDelayLength - m_uWritePos - 1;
        if ( v18 - v19 < v32 )
          v32 = v18 - v19;
        if ( v32 < v12 )
          v25 = v32;
      }
      v33 = v12;
      v19 = (v16 + m_uWritePos) % m_uAllocatedDelayLength;
      v34 = m_uAllocatedDelayLength - m_uWritePos - 1;
      if ( v18 - v19 < v34 )
        v34 = v18 - v19;
      if ( v34 < v12 )
        v33 = v34;
      v35 = v33 >> 3;
      v12 += -8 * v35;
      if ( v35 )
      {
        v36 = (float)m_uMaxModWidth;
        do
        {
          v37 = m_fPrevFeedbackGain + v22;
          v38 = (float)(int)v19;
          v39 = m_fPrevFeedforwardGain + v23;
          v40 = m_fPrevDryGain + v24;
          v41 = v19 + 1;
          v42 = (float)(v36 * *in_pfLFOBuf) + v38;
          v43 = (unsigned int)(int)v42;
          v44 = v42 - (float)(int)v42;
          v45 = (float)(1.0 - v44) * io_pfDelay[v43];
          v46 = v44 * io_pfDelay[(unsigned int)(v43 + 1)];
          v47 = m_uWritePos;
          v48 = m_uWritePos + 1;
          v49 = v45 + v46;
          v50 = v36 * in_pfLFOBuf[1];
          v51 = v49 * v37;
          v52 = v49 * v39;
          v53 = v37 + v22;
          v54 = v39 + v23;
          v55 = v51 + *io_pfBuffer;
          io_pfDelay[v47] = v55;
          v56 = v55 * v40;
          v57 = v40 + v24;
          *io_pfBuffer = v56 + v52;
          v58 = v50 + (float)v41;
          v59 = (float)((float)(1.0 - (float)(v58 - (float)(int)v58)) * io_pfDelay[v58])
              + (float)((float)(v58 - (float)(int)v58) * io_pfDelay[(int)v58 + 1]);
          v60 = v36 * in_pfLFOBuf[2];
          v61 = (float)(v59 * v53) + io_pfBuffer[1];
          io_pfDelay[v48] = v61;
          v62 = (unsigned int)(v48 + 1);
          ++v41;
          io_pfBuffer[1] = (float)(v61 * v57) + (float)(v59 * v54);
          v63 = v60 + (float)v41;
          v64 = v53 + v22;
          v65 = v54 + v23;
          LODWORD(v47) = v41 + 1;
          v41 += 2;
          v66 = (float)((float)((float)(1.0 - (float)(v63 - (float)(int)v63)) * io_pfDelay[v63])
                      + (float)((float)(v63 - (float)(int)v63) * io_pfDelay[(int)v63 + 1]))
              * v65;
          v67 = (float)((float)((float)((float)(1.0 - (float)(v63 - (float)(int)v63)) * io_pfDelay[v63])
                              + (float)((float)(v63 - (float)(int)v63) * io_pfDelay[(int)v63 + 1]))
                      * v64)
              + io_pfBuffer[2];
          v68 = v57 + v24;
          v69 = v64 + v22;
          v70 = v36 * in_pfLFOBuf[3];
          io_pfDelay[v62] = v67;
          v71 = v65 + v23;
          v72 = (unsigned int)(v62 + 1);
          v73 = (float)(v67 * v68) + v66;
          v74 = v68 + v24;
          io_pfBuffer[2] = v73;
          v75 = v70 + (float)(int)v47;
          v76 = (float)((float)(1.0 - (float)(v75 - (float)(int)v75)) * io_pfDelay[v75])
              + (float)((float)(v75 - (float)(int)v75) * io_pfDelay[(int)v75 + 1]);
          v77 = v36 * in_pfLFOBuf[4];
          v78 = v76 * v69;
          v79 = v76 * v71;
          v80 = v69 + v22;
          v81 = v71 + v23;
          v82 = v78 + io_pfBuffer[3];
          io_pfDelay[v72] = v82;
          v83 = v82 * v74;
          v84 = (unsigned int)(v72 + 1);
          v85 = v74 + v24;
          io_pfBuffer[3] = v83 + v79;
          v86 = v77 + (float)v41;
          v87 = (float)((float)(1.0 - (float)(v86 - (float)(int)v86)) * io_pfDelay[v86])
              + (float)((float)(v86 - (float)(int)v86) * io_pfDelay[(int)v86 + 1]);
          v88 = v36 * in_pfLFOBuf[5];
          v89 = (float)(v87 * v80) + io_pfBuffer[4];
          io_pfDelay[v84] = v89;
          v90 = (unsigned int)(v84 + 1);
          io_pfBuffer[4] = (float)(v89 * v85) + (float)(v87 * v81);
          v91 = v88 + (float)(v41 + 1);
          v92 = v80 + v22;
          v93 = v81 + v23;
          v94 = v85 + v24;
          v95 = (unsigned int)(int)v91;
          v96 = v91 - (float)(int)v91;
          v97 = (float)(1.0 - v96) * io_pfDelay[v95];
          v98 = v96 * io_pfDelay[(unsigned int)(v95 + 1)];
          LODWORD(v95) = v41 + 2;
          v41 += 3;
          v99 = v97 + v98;
          v100 = v36 * in_pfLFOBuf[6];
          v101 = v99 * v92;
          v102 = v99 * v93;
          v103 = v92 + v22;
          v104 = v93 + v23;
          v105 = v101 + io_pfBuffer[5];
          io_pfDelay[v90] = v105;
          v106 = v105 * v94;
          v107 = (unsigned int)(v90 + 1);
          v108 = v94 + v24;
          io_pfBuffer[5] = v106 + v102;
          v109 = v100 + (float)(int)v95;
          v110 = (float)((float)(1.0 - (float)(v109 - (float)(int)v109)) * io_pfDelay[v109])
               + (float)((float)(v109 - (float)(int)v109) * io_pfDelay[(int)v109 + 1]);
          v111 = v110 * v104;
          m_fPrevFeedforwardGain = v104 + v23;
          v112 = v110 * v103;
          m_fPrevFeedbackGain = v103 + v22;
          v113 = v112 + io_pfBuffer[6];
          io_pfDelay[v107] = v113;
          v114 = v113 * v108;
          v115 = (unsigned int)(v107 + 1);
          in_pfLFOBuf += 8;
          m_fPrevDryGain = v108 + v24;
          io_pfBuffer[6] = v114 + v111;
          v116 = (float)(v36 * *(in_pfLFOBuf - 1)) + (float)v41;
          v117 = (float)((float)(1.0 - (float)(v116 - (float)(int)v116)) * io_pfDelay[v116])
               + (float)((float)(v116 - (float)(int)v116) * io_pfDelay[(int)v116 + 1]);
          v118 = (float)(v117 * m_fPrevFeedbackGain) + io_pfBuffer[7];
          io_pfBuffer += 8;
          v19 = v41 + 1;
          io_pfDelay[v115] = v118;
          m_uWritePos = v115 + 1;
          *(io_pfBuffer - 1) = (float)(v118 * m_fPrevDryGain) + (float)(v117 * m_fPrevFeedforwardGain);
          --v35;
        }
        while ( v35 );
      }
    }
    while ( v12 );
  }
  this->m_fPrevFeedbackGain = m_fFeedbackGain;
  this->m_fPrevFeedforwardGain = m_fFeedforwardGain;
  this->m_fPrevDryGain = m_fDryGain;
  this->m_uWritePos = m_uWritePos;
}

