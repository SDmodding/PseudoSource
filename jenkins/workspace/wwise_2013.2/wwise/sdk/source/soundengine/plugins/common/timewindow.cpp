// File Line: 28
// RVA: 0xAEF0F0
__int64 __fastcall DSP::CAkTimeWindow::Init(
        DSP::CAkTimeWindow *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uWindowSize,
        DSP::CAkTimeWindow::WindowType in_eWindowType,
        bool in_bWeighthedOLAWin,
        bool in_bZeroPhase)
{
  float *v8; // rdi
  int v10; // ebx
  int v11; // ebx
  unsigned int v12; // eax
  __int64 i; // rcx

  this->m_uWindowSize = in_uWindowSize;
  v8 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4 * ((unsigned __int64)in_uWindowSize >> 1));
  this->m_pfWindowData = v8;
  if ( !v8 )
    return 52i64;
  v10 = in_eWindowType - 1;
  if ( v10 )
  {
    v11 = v10 - 1;
    if ( v11 )
    {
      if ( v11 == 1 )
      {
        DSP::CAkTimeWindow::BlackmanWindow(this, in_bWeighthedOLAWin, in_bZeroPhase);
      }
      else
      {
        v12 = this->m_uWindowSize >> 1;
        if ( v12 )
        {
          for ( i = v12; i; --i )
            *v8++ = 1.0;
        }
        this->m_fCummulativeSum = (float)(int)this->m_uWindowSize;
      }
    }
    else
    {
      DSP::CAkTimeWindow::HannWindow(this, in_bWeighthedOLAWin, in_bZeroPhase);
    }
  }
  else
  {
    DSP::CAkTimeWindow::HammingWindow(this, in_bWeighthedOLAWin, in_bZeroPhase);
  }
  return 1i64;
}

// File Line: 58
// RVA: 0xAEF1D0
void __fastcall DSP::CAkTimeWindow::Term(DSP::CAkTimeWindow *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pfWindowData )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pfWindowData = 0i64;
  }
}

// File Line: 68
// RVA: 0xAEF200
void __fastcall DSP::CAkTimeWindow::Apply(
        DSP::CAkTimeWindow *this,
        float *io_pfBuf,
        unsigned int in_uNumFrames,
        float in_fWinGain)
{
  if ( in_fWinGain == 1.0 )
    DSP::CAkTimeWindow::Apply(this, io_pfBuf, in_uNumFrames, this->m_pfWindowData);
  else
    DSP::CAkTimeWindow::Apply(this, io_pfBuf, in_uNumFrames, in_fWinGain, this->m_pfWindowData);
}

// File Line: 77
// RVA: 0xAEF240
void __fastcall DSP::CAkTimeWindow::RectangularWindow(
        DSP::CAkTimeWindow *this,
        bool in_bWeighthedOLAWin,
        bool in_bZeroPhase)
{
  unsigned int m_uWindowSize; // r8d
  float *m_pfWindowData; // rdi
  __int64 i; // rcx

  m_uWindowSize = this->m_uWindowSize;
  if ( m_uWindowSize >> 1 )
  {
    m_pfWindowData = this->m_pfWindowData;
    for ( i = m_uWindowSize >> 1; i; --i )
      *m_pfWindowData++ = 1.0;
  }
  this->m_fCummulativeSum = (float)(int)m_uWindowSize;
}

// File Line: 90
// RVA: 0xAEF280
void __fastcall DSP::CAkTimeWindow::HammingWindow(
        DSP::CAkTimeWindow *this,
        bool in_bWeighthedOLAWin,
        bool in_bZeroPhase)
{
  double v4; // xmm7_8
  double v5; // xmm6_8
  unsigned int m_uWindowSize; // eax
  float *m_pfWindowData; // rbx
  unsigned int v8; // ecx
  double v9; // xmm8_8
  __int64 v10; // rdi
  double v11; // xmm0_8
  double v12; // xmm2_8
  __int64 v13; // rdi
  double v14; // xmm0_8
  double v15; // xmm1_8
  float v16; // xmm0_4

  v4 = 0.0;
  if ( in_bZeroPhase )
    v5 = DOUBLE_3_141592653589793;
  else
    v5 = 0.0;
  m_uWindowSize = this->m_uWindowSize;
  m_pfWindowData = this->m_pfWindowData;
  v8 = m_uWindowSize >> 1;
  v9 = 6.283185307179586 / ((double)(int)m_uWindowSize - 1.0);
  if ( in_bWeighthedOLAWin )
  {
    if ( v8 )
    {
      v10 = v8;
      do
      {
        v11 = cos(v5);
        ++m_pfWindowData;
        v5 = v5 + v9;
        v12 = 0.54 - v11 * 0.46;
        v4 = v4 + v12;
        *(m_pfWindowData - 1) = sqrt(v12);
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
      ++m_pfWindowData;
      v5 = v5 + v9;
      v15 = 0.54 - v14 * 0.46;
      *(float *)&v14 = v15;
      *(m_pfWindowData - 1) = *(float *)&v14;
      v4 = v4 + v15 * v15;
      --v13;
    }
    while ( v13 );
  }
  v16 = v4;
  this->m_fCummulativeSum = v16 * 2.0;
}

// File Line: 120
// RVA: 0xAEF3F0
void __fastcall DSP::CAkTimeWindow::HannWindow(DSP::CAkTimeWindow *this, bool in_bWeighthedOLAWin, bool in_bZeroPhase)
{
  double v4; // xmm7_8
  double v5; // xmm6_8
  unsigned int m_uWindowSize; // eax
  float *m_pfWindowData; // rbx
  unsigned int v8; // ecx
  double v9; // xmm8_8
  __int64 v10; // rdi
  double v11; // xmm0_8
  double v12; // xmm2_8
  __int64 v13; // rdi
  double v14; // xmm0_8
  double v15; // xmm1_8
  float v16; // xmm0_4

  v4 = 0.0;
  if ( in_bZeroPhase )
    v5 = DOUBLE_3_141592653589793;
  else
    v5 = 0.0;
  m_uWindowSize = this->m_uWindowSize;
  m_pfWindowData = this->m_pfWindowData;
  v8 = m_uWindowSize >> 1;
  v9 = 6.283185307179586 / ((double)(int)m_uWindowSize - 1.0);
  if ( in_bWeighthedOLAWin )
  {
    if ( v8 )
    {
      v10 = v8;
      do
      {
        v11 = cos(v5);
        ++m_pfWindowData;
        v5 = v5 + v9;
        v12 = (1.0 - v11) * 0.5;
        v4 = v4 + v12;
        *(m_pfWindowData - 1) = sqrt(v12);
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
      ++m_pfWindowData;
      v5 = v5 + v9;
      v15 = (1.0 - v14) * 0.5;
      *(float *)&v14 = v15;
      *(m_pfWindowData - 1) = *(float *)&v14;
      v4 = v4 + v15 * v15;
      --v13;
    }
    while ( v13 );
  }
  v16 = v4;
  this->m_fCummulativeSum = v16 * 2.0;
}

// File Line: 150
// RVA: 0xAEF550
void __fastcall DSP::CAkTimeWindow::BlackmanWindow(
        DSP::CAkTimeWindow *this,
        bool in_bWeighthedOLAWin,
        bool in_bZeroPhase)
{
  double v4; // xmm8_8
  double v5; // xmm7_8
  unsigned int m_uWindowSize; // eax
  float *m_pfWindowData; // rbx
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

  v4 = 0.0;
  if ( in_bZeroPhase )
    v5 = DOUBLE_3_141592653589793;
  else
    v5 = 0.0;
  m_uWindowSize = this->m_uWindowSize;
  m_pfWindowData = this->m_pfWindowData;
  v8 = m_uWindowSize >> 1;
  v9 = 6.283185307179586 / ((double)(int)m_uWindowSize - 1.0);
  if ( in_bWeighthedOLAWin )
  {
    if ( v8 )
    {
      v10 = v8;
      do
      {
        v11 = 0.42 - cos(v5) * 0.5;
        v12 = cos(v5 * 2.0);
        ++m_pfWindowData;
        v5 = v5 + v9;
        v13 = v11 + v12 * 0.08;
        v4 = v4 + v13;
        *(m_pfWindowData - 1) = sqrt(v13);
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
      ++m_pfWindowData;
      v5 = v5 + v9;
      v17 = v15 + v16 * 0.08;
      *(float *)&v16 = v17;
      *(m_pfWindowData - 1) = *(float *)&v16;
      v4 = v4 + v17 * v17;
      --v14;
    }
    while ( v14 );
  }
  v18 = v4;
  this->m_fCummulativeSum = v18 * 2.0;
}

// File Line: 185
// RVA: 0xAEF750
void __fastcall DSP::CAkTimeWindow::Apply(
        DSP::CAkTimeWindow *this,
        float *io_pfBuf,
        unsigned int in_uNumFrames,
        float *in_pfWindow)
{
  unsigned int m_uWindowSize; // r10d
  unsigned int v5; // r8d
  __int64 v8; // rax
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
  float *v20; // rax
  __int64 v21; // rcx
  float v22; // xmm0_4
  __int64 v23; // rbx
  float *v24; // r9
  unsigned int v25; // edx
  float *v26; // rcx
  unsigned int v27; // eax

  m_uWindowSize = this->m_uWindowSize;
  v5 = 0;
  v8 = 0i64;
  v9 = m_uWindowSize >> 1;
  if ( m_uWindowSize >> 1 >= 4 )
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
    v20 = &io_pfBuf[v8];
    v5 += v19;
    v21 = v19;
    do
    {
      v22 = *(float *)((char *)v20++ + (char *)in_pfWindow - (char *)io_pfBuf);
      *(v20 - 1) = v22 * *(v20 - 1);
      --v21;
    }
    while ( v21 );
  }
  v23 = v5;
  if ( v5 < m_uWindowSize )
  {
    if ( (int)(m_uWindowSize - v5) >= 4 )
    {
      v24 = &io_pfBuf[v5 + 2];
      v23 = v5 + 4i64 * (((m_uWindowSize - 3 - v5 - 1) >> 2) + 1);
      do
      {
        v24 += 4;
        v25 = m_uWindowSize - v5;
        v5 += 4;
        *(v24 - 6) = in_pfWindow[v25 - 1] * *(v24 - 6);
        *(v24 - 5) = in_pfWindow[v25 - 2] * *(v24 - 5);
        *(v24 - 4) = in_pfWindow[v25 - 3] * *(v24 - 4);
        *(v24 - 3) = in_pfWindow[v25 - 4] * *(v24 - 3);
      }
      while ( v5 < m_uWindowSize - 3 );
    }
    if ( v5 < m_uWindowSize )
    {
      v26 = &io_pfBuf[v23];
      do
      {
        ++v26;
        v27 = m_uWindowSize - v5++;
        *(v26 - 1) = in_pfWindow[v27 - 1] * *(v26 - 1);
      }
      while ( v5 < m_uWindowSize );
    }
  }
}

// File Line: 202
// RVA: 0xAEF900
void __fastcall DSP::CAkTimeWindow::Apply(
        DSP::CAkTimeWindow *this,
        float *io_pfBuf,
        unsigned int in_uNumFrames,
        float in_fWinGain,
        float *in_pfWindow)
{
  unsigned int m_uWindowSize; // r9d
  unsigned int v6; // r8d
  __int64 v8; // rdi
  unsigned int v9; // r11d
  float *v10; // rcx
  signed __int64 v11; // rdx
  __int64 v12; // rax
  float v13; // xmm1_4
  float v14; // xmm1_4
  unsigned int v15; // r11d
  float *v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rdi
  float *v19; // r11
  unsigned int v20; // edx
  float *v21; // rcx
  unsigned int v22; // eax

  m_uWindowSize = this->m_uWindowSize;
  v6 = 0;
  v8 = 0i64;
  v9 = m_uWindowSize >> 1;
  if ( m_uWindowSize >> 1 >= 4 )
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
    v16 = &io_pfBuf[v8];
    v6 += v15;
    v17 = v15;
    do
    {
      ++v16;
      *(v16 - 1) = (float)(in_fWinGain * *(float *)((char *)v16 + (char *)in_pfWindow - (char *)io_pfBuf - 4))
                 * *(v16 - 1);
      --v17;
    }
    while ( v17 );
  }
  v18 = v6;
  if ( v6 < m_uWindowSize )
  {
    if ( (int)(m_uWindowSize - v6) >= 4 )
    {
      v19 = &io_pfBuf[v6 + 2];
      v18 = v6 + 4i64 * (((m_uWindowSize - 3 - v6 - 1) >> 2) + 1);
      do
      {
        v19 += 4;
        v20 = m_uWindowSize - v6;
        v6 += 4;
        *(v19 - 6) = (float)(in_fWinGain * in_pfWindow[v20 - 1]) * *(v19 - 6);
        *(v19 - 5) = (float)(in_fWinGain * in_pfWindow[v20 - 2]) * *(v19 - 5);
        *(v19 - 4) = (float)(in_fWinGain * in_pfWindow[v20 - 3]) * *(v19 - 4);
        *(v19 - 3) = (float)(in_fWinGain * in_pfWindow[v20 - 4]) * *(v19 - 3);
      }
      while ( v6 < m_uWindowSize - 3 );
    }
    if ( v6 < m_uWindowSize )
    {
      v21 = &io_pfBuf[v18];
      do
      {
        ++v21;
        v22 = m_uWindowSize - v6++;
        *(v21 - 1) = (float)(in_fWinGain * in_pfWindow[v22 - 1]) * *(v21 - 1);
      }
      while ( v6 < m_uWindowSize );
    }
  }
}

