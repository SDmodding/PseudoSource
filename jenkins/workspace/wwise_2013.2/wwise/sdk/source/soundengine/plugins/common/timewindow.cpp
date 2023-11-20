// File Line: 28
// RVA: 0xAEF0F0
signed __int64 __fastcall DSP::CAkTimeWindow::Init(DSP::CAkTimeWindow *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uWindowSize, DSP::CAkTimeWindow::WindowType in_eWindowType, bool in_bWeighthedOLAWin, bool in_bZeroPhase)
{
  DSP::CAkTimeWindow *v6; // rsi
  DSP::CAkTimeWindow::WindowType v7; // ebx
  float *v8; // rdi
  int v10; // ebx
  int v11; // ebx
  unsigned int v12; // eax
  __int64 i; // rcx

  this->m_uWindowSize = in_uWindowSize;
  v6 = this;
  v7 = in_eWindowType;
  v8 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4 * ((unsigned __int64)in_uWindowSize >> 1));
  v6->m_pfWindowData = v8;
  if ( !v8 )
    return 52i64;
  v10 = v7 - 1;
  if ( v10 )
  {
    v11 = v10 - 1;
    if ( v11 )
    {
      if ( v11 == 1 )
      {
        DSP::CAkTimeWindow::BlackmanWindow(v6, in_bWeighthedOLAWin, in_bZeroPhase);
      }
      else
      {
        v12 = v6->m_uWindowSize >> 1;
        if ( v12 )
        {
          for ( i = v12; i; --i )
          {
            *v8 = 1.0;
            ++v8;
          }
        }
        v6->m_fCummulativeSum = (float)(signed int)v6->m_uWindowSize;
      }
    }
    else
    {
      DSP::CAkTimeWindow::HannWindow(v6, in_bWeighthedOLAWin, in_bZeroPhase);
    }
  }
  else
  {
    DSP::CAkTimeWindow::HammingWindow(v6, in_bWeighthedOLAWin, in_bZeroPhase);
  }
  return 1i64;
}

// File Line: 58
// RVA: 0xAEF1D0
void __fastcall DSP::CAkTimeWindow::Term(DSP::CAkTimeWindow *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::CAkTimeWindow *v2; // rbx

  v2 = this;
  if ( this->m_pfWindowData )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->m_pfWindowData = 0i64;
  }
}

// File Line: 68
// RVA: 0xAEF200
void __fastcall DSP::CAkTimeWindow::Apply(DSP::CAkTimeWindow *this, float *io_pfBuf, unsigned int in_uNumFrames, float in_fWinGain)
{
  if ( in_fWinGain == 1.0 )
    DSP::CAkTimeWindow::Apply(this, io_pfBuf, in_uNumFrames, this->m_pfWindowData);
  else
    DSP::CAkTimeWindow::Apply(this, io_pfBuf, in_uNumFrames, in_fWinGain, this->m_pfWindowData);
}

// File Line: 77
// RVA: 0xAEF240
void __fastcall DSP::CAkTimeWindow::RectangularWindow(DSP::CAkTimeWindow *this, bool in_bWeighthedOLAWin, bool in_bZeroPhase)
{
  signed int v3; // er8
  DSP::CAkTimeWindow *v4; // rdx
  unsigned int v5; // eax
  float *v6; // rdi
  __int64 i; // rcx

  v3 = this->m_uWindowSize;
  v4 = this;
  v5 = this->m_uWindowSize >> 1;
  if ( v5 )
  {
    v6 = this->m_pfWindowData;
    for ( i = v5; i; --i )
    {
      *v6 = 1.0;
      ++v6;
    }
  }
  v4->m_fCummulativeSum = (float)v3;
}

// File Line: 90
// RVA: 0xAEF280
void __fastcall DSP::CAkTimeWindow::HammingWindow(DSP::CAkTimeWindow *this, bool in_bWeighthedOLAWin, bool in_bZeroPhase)
{
  DSP::CAkTimeWindow *v3; // rsi
  double v4; // xmm7_8
  double v5; // xmm6_8
  unsigned int v6; // eax
  float *v7; // rbx
  unsigned int v8; // ecx
  double v9; // xmm8_8
  __int64 v10; // rdi
  double v11; // xmm0_8
  double v12; // xmm2_8
  __int64 v13; // rdi
  double v14; // xmm0_8
  double v15; // xmm1_8
  float v16; // xmm0_4

  v3 = this;
  v4 = 0.0;
  if ( in_bZeroPhase )
    v5 = DOUBLE_3_141592653589793;
  else
    v5 = 0.0;
  v6 = this->m_uWindowSize;
  v7 = this->m_pfWindowData;
  v8 = v6 >> 1;
  v9 = 6.283185307179586 / ((double)(signed int)v6 - 1.0);
  if ( in_bWeighthedOLAWin )
  {
    if ( v8 )
    {
      v10 = v8;
      do
      {
        v11 = cos(v5);
        ++v7;
        v5 = v5 + v9;
        v12 = 0.54 - v11 * 0.46;
        v4 = v4 + v12;
        *(v7 - 1) = sqrt(v12);
        --v10;
      }
      while ( v10 );
    }
  }
  else if ( v8 )
  {
    v13 = v8;
    do
    {
      v14 = cos(v5);
      ++v7;
      v5 = v5 + v9;
      v15 = 0.54 - v14 * 0.46;
      *(float *)&v14 = v15;
      *(v7 - 1) = *(float *)&v14;
      v4 = v4 + v15 * v15;
      --v13;
    }
    while ( v13 );
  }
  v16 = v4;
  v3->m_fCummulativeSum = v16 * 2.0;
}

// File Line: 120
// RVA: 0xAEF3F0
void __fastcall DSP::CAkTimeWindow::HannWindow(DSP::CAkTimeWindow *this, bool in_bWeighthedOLAWin, bool in_bZeroPhase)
{
  DSP::CAkTimeWindow *v3; // rsi
  double v4; // xmm7_8
  double v5; // xmm6_8
  signed int v6; // eax
  float *v7; // rbx
  unsigned int v8; // ecx
  double v9; // xmm8_8
  __int64 v10; // rdi
  double v11; // xmm0_8
  double v12; // xmm2_8
  __int64 v13; // rdi
  double v14; // xmm0_8
  double v15; // xmm1_8
  float v16; // xmm0_4

  v3 = this;
  v4 = 0.0;
  if ( in_bZeroPhase )
    v5 = DOUBLE_3_141592653589793;
  else
    v5 = 0.0;
  v6 = this->m_uWindowSize;
  v7 = this->m_pfWindowData;
  v8 = this->m_uWindowSize >> 1;
  v9 = 6.283185307179586 / ((double)v6 - 1.0);
  if ( in_bWeighthedOLAWin )
  {
    if ( v8 )
    {
      v10 = v8;
      do
      {
        v11 = cos(v5);
        ++v7;
        v5 = v5 + v9;
        v12 = (1.0 - v11) * 0.5;
        v4 = v4 + v12;
        *(v7 - 1) = sqrt(v12);
        --v10;
      }
      while ( v10 );
    }
  }
  else if ( v8 )
  {
    v13 = v8;
    do
    {
      v14 = cos(v5);
      ++v7;
      v5 = v5 + v9;
      v15 = (1.0 - v14) * 0.5;
      *(float *)&v14 = v15;
      *(v7 - 1) = *(float *)&v14;
      v4 = v4 + v15 * v15;
      --v13;
    }
    while ( v13 );
  }
  v16 = v4;
  v3->m_fCummulativeSum = v16 * 2.0;
}

// File Line: 150
// RVA: 0xAEF550
void __fastcall DSP::CAkTimeWindow::BlackmanWindow(DSP::CAkTimeWindow *this, bool in_bWeighthedOLAWin, bool in_bZeroPhase)
{
  DSP::CAkTimeWindow *v3; // rsi
  double v4; // xmm8_8
  double v5; // xmm7_8
  unsigned int v6; // eax
  float *v7; // rbx
  unsigned int v8; // ecx
  double v9; // xmm9_8
  __int64 v10; // rdi
  double v11; // xmm6_8
  double v12; // xmm0_8
  double v13; // xmm6_8
  __int64 v14; // rdi
  double v15; // xmm6_8
  double v16; // xmm0_8
  double v17; // xmm6_8
  float v18; // xmm0_4

  v3 = this;
  v4 = 0.0;
  if ( in_bZeroPhase )
    v5 = DOUBLE_3_141592653589793;
  else
    v5 = 0.0;
  v6 = this->m_uWindowSize;
  v7 = this->m_pfWindowData;
  v8 = v6 >> 1;
  v9 = 6.283185307179586 / ((double)(signed int)v6 - 1.0);
  if ( in_bWeighthedOLAWin )
  {
    if ( v8 )
    {
      v10 = v8;
      do
      {
        v11 = 0.42 - cos(v5) * 0.5;
        v12 = cos(v5 * 2.0);
        ++v7;
        v5 = v5 + v9;
        v13 = v11 + v12 * 0.08;
        v4 = v4 + v13;
        *(v7 - 1) = sqrt(v13);
        --v10;
      }
      while ( v10 );
    }
  }
  else if ( v8 )
  {
    v14 = v8;
    do
    {
      v15 = 0.42 - cos(v5) * 0.5;
      v16 = cos(v5 * 2.0);
      ++v7;
      v5 = v5 + v9;
      v17 = v15 + v16 * 0.08;
      *(float *)&v16 = v17;
      *(v7 - 1) = *(float *)&v16;
      v4 = v4 + v17 * v17;
      --v14;
    }
    while ( v14 );
  }
  v18 = v4;
  v3->m_fCummulativeSum = v18 * 2.0;
}

// File Line: 185
// RVA: 0xAEF750
void __fastcall DSP::CAkTimeWindow::Apply(DSP::CAkTimeWindow *this, float *io_pfBuf, unsigned int in_uNumFrames, float *in_pfWindow)
{
  unsigned int v4; // er10
  unsigned int v5; // er8
  float *v6; // r11
  float *v7; // rdi
  signed __int64 v8; // rax
  unsigned int v9; // ebx
  signed __int64 v10; // r9
  float *v11; // rcx
  unsigned int v12; // eax
  __int64 v13; // rdx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  unsigned int v19; // ebx
  signed __int64 v20; // rax
  __int64 v21; // rcx
  float v22; // xmm0_4
  signed __int64 v23; // rbx
  signed __int64 v24; // r9
  int v25; // edx
  signed __int64 v26; // rcx
  int v27; // eax

  v4 = this->m_uWindowSize;
  v5 = 0;
  v6 = in_pfWindow;
  v7 = io_pfBuf;
  v8 = 0i64;
  v9 = this->m_uWindowSize >> 1;
  if ( (signed int)v9 >= 4 )
  {
    v10 = (char *)in_pfWindow - (char *)io_pfBuf;
    v11 = io_pfBuf + 1;
    v12 = ((v9 - 4) >> 2) + 1;
    v13 = v12;
    v5 = 4 * v12;
    v8 = 4i64 * v12;
    do
    {
      v14 = *(float *)((char *)v11 + v10 - 4);
      v15 = *(float *)((char *)v11 + v10);
      v11 += 4;
      v16 = v15 * *(v11 - 4);
      *(v11 - 5) = v14 * *(v11 - 5);
      v17 = *(float *)((char *)v11 + v10 - 12);
      *(v11 - 4) = v16;
      v18 = *(float *)((char *)v11 + v10 - 8) * *(v11 - 2);
      *(v11 - 3) = v17 * *(v11 - 3);
      *(v11 - 2) = v18;
      --v13;
    }
    while ( v13 );
  }
  if ( v5 < v9 )
  {
    v19 = v9 - v5;
    v20 = (signed __int64)&v7[v8];
    v5 += v19;
    v21 = v19;
    do
    {
      v22 = *(float *)(v20 + (char *)v6 - (char *)v7);
      v20 += 4i64;
      *(float *)(v20 - 4) = v22 * *(float *)(v20 - 4);
      --v21;
    }
    while ( v21 );
  }
  v23 = v5;
  if ( v5 < v4 )
  {
    if ( (signed int)(v4 - v5) >= 4 )
    {
      v24 = (signed __int64)&v7[v5 + 2];
      v23 = v5 + 4i64 * (((v4 - 3 - v5 - 1) >> 2) + 1);
      do
      {
        v24 += 16i64;
        v25 = v4 - v5;
        v5 += 4;
        *(float *)(v24 - 24) = v6[v25 - 1] * *(float *)(v24 - 24);
        *(float *)(v24 - 20) = v6[v25 - 2] * *(float *)(v24 - 20);
        *(float *)(v24 - 16) = v6[v25 - 3] * *(float *)(v24 - 16);
        *(float *)(v24 - 12) = v6[v25 - 4] * *(float *)(v24 - 12);
      }
      while ( v5 < v4 - 3 );
    }
    if ( v5 < v4 )
    {
      v26 = (signed __int64)&v7[v23];
      do
      {
        v26 += 4i64;
        v27 = v4 - v5++;
        *(float *)(v26 - 4) = v6[v27 - 1] * *(float *)(v26 - 4);
      }
      while ( v5 < v4 );
    }
  }
}

// File Line: 202
// RVA: 0xAEF900
void __fastcall DSP::CAkTimeWindow::Apply(DSP::CAkTimeWindow *this, float *io_pfBuf, unsigned int in_uNumFrames, float in_fWinGain, float *in_pfWindow)
{
  unsigned int v5; // er9
  unsigned int v6; // er8
  float *v7; // rbx
  signed __int64 v8; // rdi
  unsigned int v9; // er11
  float *v10; // rcx
  signed __int64 v11; // rdx
  __int64 v12; // rax
  float v13; // xmm1_4
  float v14; // xmm1_4
  unsigned int v15; // er11
  signed __int64 v16; // rax
  __int64 v17; // rcx
  signed __int64 v18; // rdi
  signed __int64 v19; // r11
  int v20; // edx
  signed __int64 v21; // rcx
  int v22; // eax

  v5 = this->m_uWindowSize;
  v6 = 0;
  v7 = io_pfBuf;
  v8 = 0i64;
  v9 = this->m_uWindowSize >> 1;
  if ( (signed int)v9 >= 4 )
  {
    v10 = io_pfBuf + 1;
    v11 = (char *)in_pfWindow - (char *)io_pfBuf;
    v12 = ((v9 - 4) >> 2) + 1;
    v6 = 4 * v12;
    v8 = 4i64 * (unsigned int)v12;
    do
    {
      v10 += 4;
      v13 = (float)(in_fWinGain * *(float *)((char *)v10 + v11 - 16)) * *(v10 - 4);
      *(v10 - 5) = (float)(in_fWinGain * *(float *)((char *)v10 + v11 - 20)) * *(v10 - 5);
      *(v10 - 4) = v13;
      v14 = (float)(in_fWinGain * *(float *)((char *)v10 + v11 - 8)) * *(v10 - 2);
      *(v10 - 3) = (float)(in_fWinGain * *(float *)((char *)v10 + v11 - 12)) * *(v10 - 3);
      *(v10 - 2) = v14;
      --v12;
    }
    while ( v12 );
  }
  if ( v6 < v9 )
  {
    v15 = v9 - v6;
    v16 = (signed __int64)&v7[v8];
    v6 += v15;
    v17 = v15;
    do
    {
      v16 += 4i64;
      *(float *)(v16 - 4) = (float)(in_fWinGain * *(float *)(v16 + (char *)in_pfWindow - (char *)v7 - 4))
                          * *(float *)(v16 - 4);
      --v17;
    }
    while ( v17 );
  }
  v18 = v6;
  if ( v6 < v5 )
  {
    if ( (signed int)(v5 - v6) >= 4 )
    {
      v19 = (signed __int64)&v7[v6 + 2];
      v18 = v6 + 4i64 * (((v5 - 3 - v6 - 1) >> 2) + 1);
      do
      {
        v19 += 16i64;
        v20 = v5 - v6;
        v6 += 4;
        *(float *)(v19 - 24) = (float)(in_fWinGain * in_pfWindow[v20 - 1]) * *(float *)(v19 - 24);
        *(float *)(v19 - 20) = (float)(in_fWinGain * in_pfWindow[v20 - 2]) * *(float *)(v19 - 20);
        *(float *)(v19 - 16) = (float)(in_fWinGain * in_pfWindow[v20 - 3]) * *(float *)(v19 - 16);
        *(float *)(v19 - 12) = (float)(in_fWinGain * in_pfWindow[v20 - 4]) * *(float *)(v19 - 12);
      }
      while ( v6 < v5 - 3 );
    }
    if ( v6 < v5 )
    {
      v21 = (signed __int64)&v7[v18];
      do
      {
        v21 += 4i64;
        v22 = v5 - v6++;
        *(float *)(v21 - 4) = (float)(in_fWinGain * in_pfWindow[v22 - 1]) * *(float *)(v21 - 4);
      }
      while ( v6 < v5 );
    }
  }
}

