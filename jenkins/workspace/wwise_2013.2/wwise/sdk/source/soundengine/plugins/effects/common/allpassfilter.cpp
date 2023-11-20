// File Line: 43
// RVA: 0xAE7AE0
signed __int64 __fastcall DSP::AllpassFilter::Init(DSP::AllpassFilter *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uDelayLineLength, float in_fG)
{
  DSP::AllpassFilter *v4; // rbx
  float *v5; // rax

  v4 = this;
  if ( in_uDelayLineLength < 1 )
    in_uDelayLineLength = 1;
  this->uDelayLineLength = in_uDelayLineLength;
  v5 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8i64 * in_uDelayLineLength);
  v4->pfDelay = v5;
  if ( !v5 )
    return 52i64;
  v4->fG = in_fG;
  v4->uCurOffset = 0;
  return 1i64;
}

// File Line: 58
// RVA: 0xAE7B60
void __fastcall DSP::AllpassFilter::Term(DSP::AllpassFilter *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::AllpassFilter *v2; // rbx

  v2 = this;
  if ( this->pfDelay )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->pfDelay = 0i64;
    v2->uDelayLineLength = 0;
  }
  else
  {
    this->uDelayLineLength = 0;
  }
}

// File Line: 68
// RVA: 0xAE7BA0
void __fastcall DSP::AllpassFilter::Reset(DSP::AllpassFilter *this)
{
  if ( this->pfDelay )
    memset(this->pfDelay, 0, 8i64 * this->uDelayLineLength);
}

// File Line: 77
// RVA: 0xAE7BD0
void __fastcall DSP::AllpassFilter::ProcessBuffer(DSP::AllpassFilter *this, float *io_pfBuffer, unsigned int in_uNumFrames)
{
  unsigned int v3; // er11
  unsigned int v4; // edi
  float *v5; // rsi
  DSP::AllpassFilter *v6; // rbx
  unsigned int v7; // er9
  float *v8; // r10
  unsigned int v9; // eax
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  unsigned int v14; // ecx
  float v15; // xmm3_4
  __int64 v16; // rax
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm2_4
  float v32; // xmm2_4
  __int64 v33; // rcx
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4

  v3 = this->uCurOffset;
  v4 = this->uDelayLineLength;
  v5 = this->pfDelay;
  v6 = this;
  v7 = this->uDelayLineLength - v3;
  v8 = &v5[2 * v3];
  if ( v7 <= in_uNumFrames )
  {
    do
    {
      v14 = 0;
      if ( in_uNumFrames < v7 )
        v7 = in_uNumFrames;
      if ( (signed int)v7 >= 4 )
      {
        v15 = v6->fG;
        v16 = ((v7 - 4) >> 2) + 1;
        v14 = 4 * v16;
        do
        {
          v17 = *v8;
          v18 = *io_pfBuffer;
          v19 = io_pfBuffer[1];
          v8 += 8;
          io_pfBuffer += 4;
          *(v8 - 8) = v18;
          v20 = (float)((float)(v18 - *(v8 - 7)) * v15) + v17;
          *(v8 - 7) = v20;
          v21 = *(v8 - 6);
          *(v8 - 6) = v19;
          v22 = v19 - *(v8 - 5);
          *(io_pfBuffer - 4) = v20;
          v23 = *(io_pfBuffer - 2);
          v24 = (float)(v22 * v15) + v21;
          *(v8 - 5) = v24;
          v25 = *(v8 - 4);
          *(v8 - 4) = v23;
          v26 = v23 - *(v8 - 3);
          *(io_pfBuffer - 3) = v24;
          v27 = *(io_pfBuffer - 1);
          v28 = (float)(v26 * v15) + v25;
          *(v8 - 3) = v28;
          v29 = *(v8 - 2);
          *(v8 - 2) = v27;
          v30 = v27 - *(v8 - 1);
          *(io_pfBuffer - 2) = v28;
          v31 = (float)(v30 * v15) + v29;
          *(v8 - 1) = v31;
          *(io_pfBuffer - 1) = v31;
          --v16;
        }
        while ( v16 );
      }
      if ( v14 < v7 )
      {
        v32 = v6->fG;
        v33 = v7 - v14;
        do
        {
          v34 = *io_pfBuffer;
          v35 = *v8;
          v8 += 2;
          ++io_pfBuffer;
          *(v8 - 2) = v34;
          v36 = (float)((float)(v34 - *(v8 - 1)) * v32) + v35;
          *(v8 - 1) = v36;
          *(io_pfBuffer - 1) = v36;
          --v33;
        }
        while ( v33 );
      }
      v3 += v7;
      v6->uCurOffset = v3;
      if ( v3 == v4 )
      {
        v8 = v5;
        v3 = 0;
        v6->uCurOffset = 0;
      }
      in_uNumFrames -= v7;
      v7 = v4 - v3;
    }
    while ( in_uNumFrames );
  }
  else
  {
    v9 = in_uNumFrames;
    if ( in_uNumFrames )
    {
      v10 = this->fG;
      do
      {
        v11 = *io_pfBuffer;
        v12 = *v8;
        v8 += 2;
        ++io_pfBuffer;
        *(v8 - 2) = v11;
        v13 = (float)((float)(v11 - *(v8 - 1)) * v10) + v12;
        *(v8 - 1) = v13;
        *(io_pfBuffer - 1) = v13;
        --v9;
      }
      while ( v9 );
    }
    this->uCurOffset = v3 + in_uNumFrames;
  }
}

// File Line: 167
// RVA: 0xAE7DD0
void __fastcall DSP::AllpassFilter::ProcessBuffer(DSP::AllpassFilter *this, float *in_pfInBuffer, float *out_pfOutBuffer, unsigned int in_uNumFrames)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  float *v6; // r14
  DSP::AllpassFilter *v7; // rdi
  unsigned int v8; // er10
  float *v9; // r11
  unsigned int v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  unsigned int v15; // ecx
  float v16; // xmm3_4
  __int64 v17; // rax
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm2_4
  float v33; // xmm2_4
  __int64 v34; // rcx
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm1_4

  v4 = this->uCurOffset;
  v5 = this->uDelayLineLength;
  v6 = this->pfDelay;
  v7 = this;
  v8 = this->uDelayLineLength - v4;
  v9 = &v6[2 * v4];
  if ( v8 <= in_uNumFrames )
  {
    for ( ; in_uNumFrames; v8 = v5 - v4 )
    {
      v15 = 0;
      if ( in_uNumFrames < v8 )
        v8 = in_uNumFrames;
      if ( (signed int)v8 >= 4 )
      {
        v16 = v7->fG;
        v17 = ((v8 - 4) >> 2) + 1;
        v15 = 4 * v17;
        do
        {
          v18 = *v9;
          v19 = *in_pfInBuffer;
          v20 = in_pfInBuffer[1];
          v9 += 8;
          out_pfOutBuffer += 4;
          in_pfInBuffer += 4;
          *(v9 - 8) = v19;
          v21 = (float)((float)(v19 - *(v9 - 7)) * v16) + v18;
          *(v9 - 7) = v21;
          v22 = *(v9 - 6);
          *(v9 - 6) = v20;
          v23 = v20 - *(v9 - 5);
          *(out_pfOutBuffer - 4) = v21;
          v24 = *(in_pfInBuffer - 2);
          v25 = (float)(v23 * v16) + v22;
          *(v9 - 5) = v25;
          v26 = *(v9 - 4);
          *(v9 - 4) = v24;
          v27 = v24 - *(v9 - 3);
          *(out_pfOutBuffer - 3) = v25;
          v28 = *(in_pfInBuffer - 1);
          v29 = (float)(v27 * v16) + v26;
          *(v9 - 3) = v29;
          v30 = *(v9 - 2);
          *(v9 - 2) = v28;
          v31 = v28 - *(v9 - 1);
          *(out_pfOutBuffer - 2) = v29;
          v32 = (float)(v31 * v16) + v30;
          *(v9 - 1) = v32;
          *(out_pfOutBuffer - 1) = v32;
          --v17;
        }
        while ( v17 );
      }
      if ( v15 < v8 )
      {
        v33 = v7->fG;
        v34 = v8 - v15;
        do
        {
          v35 = *v9;
          v36 = *in_pfInBuffer;
          v9 += 2;
          ++out_pfOutBuffer;
          ++in_pfInBuffer;
          *(v9 - 2) = v36;
          v37 = (float)((float)(v36 - *(v9 - 1)) * v33) + v35;
          *(v9 - 1) = v37;
          *(out_pfOutBuffer - 1) = v37;
          --v34;
        }
        while ( v34 );
      }
      v4 += v8;
      v7->uCurOffset = v4;
      if ( v4 == v5 )
      {
        v9 = v6;
        v4 = 0;
        v7->uCurOffset = 0;
      }
      in_uNumFrames -= v8;
    }
  }
  else
  {
    v10 = in_uNumFrames;
    if ( in_uNumFrames )
    {
      v11 = this->fG;
      do
      {
        v12 = *v9;
        v13 = *in_pfInBuffer;
        v9 += 2;
        ++out_pfOutBuffer;
        ++in_pfInBuffer;
        *(v9 - 2) = v13;
        v14 = (float)((float)(v13 - *(v9 - 1)) * v11) + v12;
        *(v9 - 1) = v14;
        *(out_pfOutBuffer - 1) = v14;
        --v10;
      }
      while ( v10 );
    }
    this->uCurOffset = v4 + in_uNumFrames;
  }
}

