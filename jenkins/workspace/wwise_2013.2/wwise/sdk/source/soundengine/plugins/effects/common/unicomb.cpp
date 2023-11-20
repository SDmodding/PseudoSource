// File Line: 35
// RVA: 0xAFB630
signed __int64 __fastcall DSP::UniComb::Init(DSP::UniComb *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uDelayLength, unsigned int in_uMaxBufferLength, float in_fFeedbackGain, float in_fFeedforwardGain, float in_fDryGain, float in_fMaxModDepth)
{
  unsigned int v8; // eax
  AK::IAkPluginMemAlloc *v9; // rbx
  DSP::UniComb *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rax

  v8 = 8;
  v9 = in_pAllocator;
  v10 = this;
  if ( in_uDelayLength > 8 )
    v8 = in_uDelayLength;
  this->m_uDelayLength = (v8 + 3) & 0xFFFFFFFC;
  DSP::UniComb::SetParams(this, in_fFeedbackGain, in_fFeedforwardGain, in_fDryGain, in_fMaxModDepth);
  v10->m_fPrevFeedbackGain = v10->m_fFeedbackGain;
  v10->m_fPrevFeedforwardGain = v10->m_fFeedforwardGain;
  v10->m_fPrevDryGain = v10->m_fDryGain;
  v11 = 2 * v10->m_uDelayLength + 1024;
  v10->m_uAllocatedDelayLength = v11;
  v12 = (__int64)v9->vfptr->Malloc(v9, 4i64 * v11);
  v10->m_pfDelay = (float *)v12;
  if ( !v12 )
    return 52i64;
  v10->m_uWritePos = 0;
  return 1i64;
}

// File Line: 60
// RVA: 0xAFB6E0
void __fastcall DSP::UniComb::Term(DSP::UniComb *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::UniComb *v2; // rbx

  v2 = this;
  if ( this->m_pfDelay )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->m_pfDelay = 0i64;
    v2->m_uAllocatedDelayLength = 0;
  }
}

// File Line: 70
// RVA: 0xAFB720
void __fastcall DSP::UniComb::Reset(DSP::UniComb *this)
{
  DSP::UniComb *v1; // rbx
  float *v2; // rcx

  v1 = this;
  v2 = this->m_pfDelay;
  if ( v2 )
    memset(v2, 0, 4 * v1->m_uAllocatedDelayLength);
  v1->m_uWritePos = 0;
}

// File Line: 84
// RVA: 0xAFB760
void __fastcall DSP::UniComb::SetParams(DSP::UniComb *this, float in_fFeedbackGain, float in_fFeedforwardGain, float in_fDryGain, float in_fMaxModDepth)
{
  signed int v5; // edx
  float v6; // xmm0_4
  unsigned int v7; // eax

  v5 = this->m_uDelayLength;
  this->m_fFeedforwardGain = in_fFeedforwardGain;
  this->m_fFeedbackGain = in_fFeedbackGain;
  this->m_fDryGain = in_fDryGain;
  v6 = (float)v5 * in_fMaxModDepth;
  this->m_uMaxModWidth = 4 * ((unsigned int)(signed int)v6 >> 2);
  if ( ((32 * ((unsigned int)(signed int)v6 >> 2) + 4111) & 0xFFFFFFF0) >= 0x19000 )
    this->m_uMaxModWidth = (signed int)(float)((float)(98304.0 / (float)((float)((float)v5 * 2.0) * 4.0)) * (float)v5) & 0xFFFFFFFC;
  v7 = this->m_uMaxModWidth;
  if ( v7 >= v5 )
    this->m_uMaxModWidth = v7 - 4;
}

// File Line: 127
// RVA: 0xAFB7F0
void __fastcall DSP::UniComb::ProcessBuffer(DSP::UniComb *this, float *io_pfBuffer, unsigned int in_uNumFrames, float *in_pfLFOBuf)
{
  if ( in_pfLFOBuf )
    DSP::UniComb::ProcessBufferLFO(this, io_pfBuffer, in_uNumFrames, in_pfLFOBuf, this->m_pfDelay);
  else
    DSP::UniComb::ProcessBufferNoLFO(this, io_pfBuffer, in_uNumFrames, this->m_pfDelay);
}

// File Line: 170
// RVA: 0xAFB820
void __fastcall DSP::UniComb::ProcessBufferNoLFO(DSP::UniComb *this, float *io_pfBuffer, unsigned int in_uNumFrames, float *io_pfDelay)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  unsigned int v6; // edi
  unsigned int v7; // ebx
  unsigned int v8; // er8
  float *v9; // r11
  float *v10; // r10
  float v11; // xmm8_4
  float v12; // xmm9_4
  float v13; // xmm10_4
  unsigned int v14; // er14
  DSP::UniComb *v15; // rsi
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float i; // xmm7_4
  unsigned int v21; // er9
  __int64 v22; // rdx
  unsigned int v23; // ecx
  float v24; // xmm1_4
  __int64 v25; // rax
  float v26; // xmm0_4

  v4 = this->m_fPrevFeedbackGain;
  v5 = this->m_fPrevFeedforwardGain;
  v6 = this->m_uAllocatedDelayLength;
  v7 = in_uNumFrames;
  v8 = this->m_uWritePos;
  v9 = io_pfDelay;
  v10 = io_pfBuffer;
  v11 = this->m_fFeedbackGain;
  v12 = this->m_fFeedforwardGain;
  v13 = this->m_fDryGain;
  v14 = this->m_uAllocatedDelayLength - this->m_uDelayLength;
  v15 = this;
  v16 = this->m_fPrevDryGain;
  v17 = 1.0 / (float)(signed int)v7;
  v18 = (float)(this->m_fFeedbackGain - v4) * v17;
  v19 = (float)(this->m_fFeedforwardGain - v5) * v17;
  for ( i = (float)(this->m_fDryGain - v16) * v17; v7; v8 %= v6 )
  {
    v21 = v7;
    v22 = (v14 + v8) % v6;
    v23 = v6 - v22;
    if ( v6 - v8 < v6 - (unsigned int)v22 )
      v23 = v6 - v8;
    if ( v23 < v7 )
      v21 = v23;
    for ( v7 -= v21; v21; --v21 )
    {
      v24 = v9[v22];
      v25 = v8;
      v4 = v4 + v18;
      ++v10;
      ++v8;
      v22 = (unsigned int)(v22 + 1);
      v5 = v5 + v19;
      v16 = v16 + i;
      v26 = (float)(v24 * v4) + *(v10 - 1);
      v9[v25] = v26;
      *(v10 - 1) = (float)(v26 * v16) + (float)(v24 * v5);
    }
  }
  v15->m_fPrevFeedbackGain = v11;
  v15->m_fPrevFeedforwardGain = v12;
  v15->m_fPrevDryGain = v13;
  v15->m_uWritePos = v8;
}

// File Line: 340
// RVA: 0xAFB9B0
void __fastcall DSP::UniComb::ProcessBufferLFO(DSP::UniComb *this, float *io_pfBuffer, unsigned int in_uNumFrames, float *in_pfLFOBuf, float *io_pfDelay)
{
  unsigned int v5; // ebx
  __int64 v6; // r10
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  signed int v10; // er15
  float *v11; // rdi
  unsigned int v12; // er11
  float *v13; // rbp
  float v14; // xmm11_4
  float v15; // xmm12_4
  unsigned int v16; // er12
  DSP::UniComb *v17; // r13
  unsigned int v18; // er14
  unsigned int v19; // edx
  float v20; // xmm13_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm8_4
  unsigned int v25; // er8
  unsigned int v26; // ecx
  float v27; // xmm0_4
  int v28; // er9
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  unsigned int v32; // ecx
  unsigned int v33; // er8
  unsigned int v34; // ecx
  unsigned int v35; // er8
  float v36; // xmm10_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  int v41; // edx
  float v42; // xmm1_4
  signed int v43; // ecx
  __int64 v44; // rax
  float v45; // xmm1_4
  float v46; // xmm2_4
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
  signed int v92; // ecx
  float v93; // xmm3_4
  float v94; // xmm4_4
  float v95; // xmm5_4
  __int64 v96; // rax
  float v97; // xmm1_4
  float v98; // xmm2_4
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
  float v110; // xmm2_4
  float v111; // xmm0_4
  float v112; // xmm2_4
  float v113; // xmm0_4
  float v114; // xmm0_4
  float v115; // xmm0_4
  float v116; // xmm1_4
  float v117; // xmm2_4
  float v118; // xmm0_4

  v5 = this->m_uAllocatedDelayLength;
  LODWORD(v6) = this->m_uWritePos;
  v7 = this->m_fPrevFeedbackGain;
  v8 = this->m_fPrevFeedforwardGain;
  v9 = this->m_fPrevDryGain;
  v10 = this->m_uMaxModWidth;
  v11 = io_pfBuffer;
  v12 = in_uNumFrames;
  v13 = in_pfLFOBuf;
  v14 = this->m_fFeedbackGain;
  v15 = this->m_fFeedforwardGain;
  v16 = v5 - this->m_uDelayLength;
  v17 = this;
  v18 = this->m_uAllocatedDelayLength - v10 - 1;
  v19 = (v16 + (unsigned int)v6) % v5;
  v20 = this->m_fDryGain;
  v21 = 1.0 / (float)(signed int)in_uNumFrames;
  v22 = (float)(this->m_fFeedbackGain - v7) * v21;
  v23 = (float)(this->m_fFeedforwardGain - v8) * v21;
  v24 = (float)(this->m_fDryGain - v9) * v21;
  while ( v12 )
  {
    v25 = v12;
    v26 = v5 - v6 - 1;
    if ( v18 - v19 < v26 )
      v26 = v18 - v19;
    if ( v26 < v12 )
      v25 = v26;
    while ( v12 )
    {
      if ( v19 < v18 && v19 >= v10 && (_DWORD)v6 != v5 - 1 && v25 >= 8 )
        break;
      v27 = *v13;
      v28 = v16 + v6;
      --v12;
      ++v13;
      ++v11;
      v7 = v7 + v22;
      v8 = v8 + v23;
      v9 = v9 + v24;
      v29 = (float)((float)v10 * v27) + (float)(signed int)(v16 + v6);
      v25 = v12;
      v30 = (float)((float)(1.0 - (float)(v29 - (float)(signed int)v29)) * io_pfDelay[(signed int)v29 % v5])
          + (float)((float)(v29 - (float)(signed int)v29) * io_pfDelay[((signed int)v29 + 1) % v5]);
      v31 = (float)(v30 * v7) + *(v11 - 1);
      io_pfDelay[(unsigned int)v6] = v31;
      *(v11 - 1) = (float)(v31 * v9) + (float)(v30 * v8);
      LODWORD(v6) = ((signed int)v6 + 1) % v5;
      v19 = (v28 + 1) % v5;
      v32 = v5 - v6 - 1;
      if ( v18 - v19 < v32 )
        v32 = v18 - v19;
      if ( v32 < v12 )
        v25 = v32;
    }
    v33 = v12;
    v19 = (v16 + (unsigned int)v6) % v5;
    v34 = v5 - v6 - 1;
    if ( v18 - v19 < v34 )
      v34 = v18 - v19;
    if ( v34 < v12 )
      v33 = v34;
    v35 = v33 >> 3;
    v12 += -8 * v35;
    if ( v35 )
    {
      v36 = (float)v10;
      do
      {
        v37 = v7 + v22;
        v38 = (float)(signed int)v19;
        v39 = v8 + v23;
        v40 = v9 + v24;
        v41 = v19 + 1;
        v42 = (float)(v36 * *v13) + v38;
        v43 = (signed int)v42;
        v44 = (unsigned int)(signed int)v42;
        v45 = v42 - (float)(signed int)v42;
        v46 = (float)(1.0 - v45) * io_pfDelay[v44];
        v47 = (unsigned int)v6;
        v48 = (unsigned int)(v6 + 1);
        v49 = v46 + (float)(v45 * io_pfDelay[v43 + 1]);
        v50 = v36 * v13[1];
        v51 = v49 * v37;
        v52 = v49 * v39;
        v53 = v37 + v22;
        v54 = v39 + v23;
        v55 = v51 + *v11;
        io_pfDelay[v47] = v55;
        v56 = v55 * v40;
        v57 = v40 + v24;
        *v11 = v56 + v52;
        v58 = v50 + (float)v41;
        v59 = (float)((float)(1.0 - (float)(v58 - (float)(signed int)v58)) * io_pfDelay[v58])
            + (float)((float)(v58 - (float)(signed int)v58) * io_pfDelay[(signed int)v58 + 1]);
        v60 = v36 * v13[2];
        v61 = (float)(v59 * v53) + v11[1];
        io_pfDelay[v48] = v61;
        v62 = (unsigned int)(v48 + 1);
        ++v41;
        v11[1] = (float)(v61 * v57) + (float)(v59 * v54);
        v63 = v60 + (float)v41;
        v64 = v53 + v22;
        v65 = v54 + v23;
        LODWORD(v47) = ++v41;
        ++v41;
        v66 = (float)((float)((float)(1.0 - (float)(v63 - (float)(signed int)v63)) * io_pfDelay[v63])
                    + (float)((float)(v63 - (float)(signed int)v63) * io_pfDelay[(signed int)v63 + 1]))
            * v65;
        v67 = (float)((float)((float)((float)(1.0 - (float)(v63 - (float)(signed int)v63)) * io_pfDelay[v63])
                            + (float)((float)(v63 - (float)(signed int)v63) * io_pfDelay[(signed int)v63 + 1]))
                    * v64)
            + v11[2];
        v68 = v57 + v24;
        v69 = v64 + v22;
        v70 = v36 * v13[3];
        io_pfDelay[v62] = v67;
        v71 = v65 + v23;
        v72 = (unsigned int)(v62 + 1);
        v73 = (float)(v67 * v68) + v66;
        v74 = v68 + v24;
        v11[2] = v73;
        v75 = v70 + (float)(signed int)v47;
        v76 = (float)((float)(1.0 - (float)(v75 - (float)(signed int)v75)) * io_pfDelay[v75])
            + (float)((float)(v75 - (float)(signed int)v75) * io_pfDelay[(signed int)v75 + 1]);
        v77 = v36 * v13[4];
        v78 = v76 * v69;
        v79 = v76 * v71;
        v80 = v69 + v22;
        v81 = v71 + v23;
        v82 = v78 + v11[3];
        io_pfDelay[v72] = v82;
        v83 = v82 * v74;
        v84 = (unsigned int)(v72 + 1);
        v85 = v74 + v24;
        v11[3] = v83 + v79;
        v86 = v77 + (float)v41;
        v87 = (float)((float)(1.0 - (float)(v86 - (float)(signed int)v86)) * io_pfDelay[v86])
            + (float)((float)(v86 - (float)(signed int)v86) * io_pfDelay[(signed int)v86 + 1]);
        v88 = v36 * v13[5];
        v89 = (float)(v87 * v80) + v11[4];
        io_pfDelay[v84] = v89;
        v90 = (unsigned int)(v84 + 1);
        ++v41;
        v11[4] = (float)(v89 * v85) + (float)(v87 * v81);
        v91 = v88 + (float)v41;
        v92 = (signed int)v91;
        ++v41;
        v93 = v80 + v22;
        v94 = v81 + v23;
        v95 = v85 + v24;
        v96 = (unsigned int)(signed int)v91;
        v97 = v91 - (float)(signed int)v91;
        v98 = (float)(1.0 - v97) * io_pfDelay[v96];
        LODWORD(v96) = v41++;
        v99 = v98 + (float)(v97 * io_pfDelay[v92 + 1]);
        v100 = v36 * v13[6];
        v101 = v99 * v93;
        v102 = v99 * v94;
        v103 = v93 + v22;
        v104 = v94 + v23;
        v105 = v101 + v11[5];
        io_pfDelay[v90] = v105;
        v106 = v105 * v95;
        v107 = (unsigned int)(v90 + 1);
        v108 = v95 + v24;
        v11[5] = v106 + v102;
        v109 = v100 + (float)(signed int)v96;
        v110 = (float)((float)(1.0 - (float)(v109 - (float)(signed int)v109)) * io_pfDelay[v109])
             + (float)((float)(v109 - (float)(signed int)v109) * io_pfDelay[(signed int)v109 + 1]);
        v111 = v110;
        v112 = v110 * v104;
        v8 = v104 + v23;
        v113 = v111 * v103;
        v7 = v103 + v22;
        v114 = v113 + v11[6];
        io_pfDelay[v107] = v114;
        v115 = v114 * v108;
        v6 = (unsigned int)(v107 + 1);
        v13 += 8;
        v9 = v108 + v24;
        v11[6] = v115 + v112;
        v116 = (float)(v36 * *(v13 - 1)) + (float)v41;
        v117 = (float)((float)(1.0 - (float)(v116 - (float)(signed int)v116)) * io_pfDelay[v116])
             + (float)((float)(v116 - (float)(signed int)v116) * io_pfDelay[(signed int)v116 + 1]);
        v118 = (float)(v117 * v7) + v11[7];
        v11 += 8;
        v19 = v41 + 1;
        io_pfDelay[v6] = v118;
        *(v11 - 1) = (float)(v118 * v9) + (float)(v117 * v8);
        --v35;
      }
      while ( v35 );
    }
  }
  v17->m_fPrevFeedbackGain = v14;
  v17->m_fPrevFeedforwardGain = v15;
  v17->m_fPrevDryGain = v20;
  v17->m_uWritePos = v6;
}

