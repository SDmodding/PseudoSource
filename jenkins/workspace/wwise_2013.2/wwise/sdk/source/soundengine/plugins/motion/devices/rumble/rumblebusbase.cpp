// File Line: 30
// RVA: 0xACD240
void __fastcall RumbleBusBase::RumbleBusBase(RumbleBusBase *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&RumbleBusBase::`vftable;
  memset(this->m_pData, 0, sizeof(this->m_pData));
  *(_DWORD *)&this->m_iDrift = 0x1000000;
  *(_QWORD *)&this->m_usWriteBuffer = 0i64;
  this->m_bGotData = 0;
  this->m_pCapture = 0i64;
  this->m_fAverageSpeed = 0.0;
  this->m_fVolume = 1.0;
}

// File Line: 47
// RVA: 0xACD870
__int64 __fastcall RumbleBusBase::Term(RumbleBusBase *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  ((void (__fastcall *)(RumbleBusBase *))this->vfptr[3].__vecDelDtor)(this);
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 66
// RVA: 0xACD340
__int64 __fastcall RumbleBusBase::Init(
        RumbleBusBase *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AkPlatformInitSettings *io_pPDSettings,
        char in_iPlayer)
{
  this->m_iPlayer = in_iPlayer;
  return 1i64;
}

// File Line: 73
// RVA: 0xACD350
__int64 __fastcall RumbleBusBase::MixAudioBuffer(RumbleBusBase *this, AkAudioBuffer *io_rBuffer)
{
  unsigned int v4; // ebx
  unsigned int i; // r8d
  unsigned __int16 v6; // bp
  __int64 v7; // r14
  float v8; // xmm1_4
  unsigned __int16 v9; // ax
  __int64 v10; // r10
  float *v11; // r9
  float *v12; // rcx
  unsigned __int16 v13; // dx
  __int64 v14; // rax

  v4 = 0;
  for ( i = io_rBuffer->uChannelMask & 0xFFFFFFF7; i; i &= i - 1 )
    ++v4;
  v6 = 0;
  v7 = 0i64;
  do
  {
    v8 = 0.0;
    v9 = io_rBuffer->uValidFrames >> 1;
    if ( v4 )
    {
      v10 = v4;
      v11 = (float *)((char *)io_rBuffer->pData + 4 * v9 * v6);
      do
      {
        v12 = v11;
        v13 = 0;
        if ( v9 )
        {
          do
          {
            if ( *v12 > v8 )
              v8 = *v12;
            ++v13;
            ++v12;
          }
          while ( v13 < (int)v9 );
        }
        v11 += io_rBuffer->uMaxFrames;
        --v10;
      }
      while ( v10 );
    }
    ++v6;
    this->m_pData[v7 + this->m_usWriteBuffer] = (float)(v8 * this->m_fVolume)
                                              + this->m_pData[v7 + this->m_usWriteBuffer];
    v14 = v7 + this->m_usWriteBuffer;
    v7 += 2i64;
    this->m_pData[v14 + 1] = (float)(v8 * this->m_fVolume) + this->m_pData[v14 + 1];
  }
  while ( v6 < 2u );
  this->m_bGotData = 1;
  return 1i64;
}

// File Line: 101
// RVA: 0xACD480
__int64 __fastcall RumbleBusBase::MixFeedbackBuffer(RumbleBusBase *this, AkAudioBuffer *io_rBuffer)
{
  unsigned __int16 v4; // bp
  unsigned __int64 uMaxFrames; // rdi
  char v6; // r14
  unsigned __int16 v7; // r8
  float *v8; // r9
  float v9; // xmm0_4
  __int64 v10; // rax

  if ( io_rBuffer->uValidFrames )
  {
    v4 = 0;
    if ( (unsigned int)AkAudioBuffer::NumChannels(io_rBuffer) )
    {
      uMaxFrames = io_rBuffer->uMaxFrames;
      v6 = 0;
      do
      {
        v7 = 0;
        v8 = (float *)((char *)io_rBuffer->pData + 4 * uMaxFrames * v4);
        do
        {
          v9 = this->m_fVolume * *v8;
          v10 = (v6 + (unsigned __int8)this->m_usWriteBuffer + 2 * (_BYTE)v7) & 0x1F;
          if ( v9 < 0.0 )
            v9 = 0.0;
          ++v7;
          this->m_pData[v10] = v9 + this->m_pData[v10];
          uMaxFrames = io_rBuffer->uMaxFrames;
          v8 += uMaxFrames >> 1;
        }
        while ( v7 < 2u );
        v6 = ++v4;
      }
      while ( v4 < (unsigned int)AkAudioBuffer::NumChannels(io_rBuffer) );
    }
    this->m_bGotData = 1;
  }
  return 1i64;
}

// File Line: 128
// RVA: 0xACD580
__int64 __fastcall RumbleBusBase::RenderData(RumbleBusBase *this)
{
  __int64 v1; // r8
  __int64 v2; // r9
  __int64 v3; // r10
  __int64 v4; // rax
  __int64 v5; // r9
  __int64 v6; // rax
  __int64 m_usWriteBuffer; // r9
  float m_fPeak; // xmm0_4
  __int64 v10; // r8
  float *v11; // rax
  __int64 v12; // rdx
  __int64 v13; // r9
  __int64 v14; // rax
  __int16 m_iDrift; // dx
  unsigned __int16 v16; // ax

  if ( this->m_bGotData )
  {
    m_usWriteBuffer = this->m_usWriteBuffer;
    m_fPeak = this->m_fPeak;
    v10 = 4i64;
    v11 = &this->m_pData[m_usWriteBuffer];
    v12 = 4i64;
    do
    {
      if ( *v11 > m_fPeak )
        m_fPeak = *v11;
      ++v11;
      this->m_fPeak = m_fPeak;
      --v12;
    }
    while ( v12 );
    this->m_usWriteBuffer = ((_BYTE)m_usWriteBuffer + 4) & 0x1F;
    v13 = 0i64;
    do
    {
      v14 = v13 + this->m_usWriteBuffer;
      ++v13;
      this->m_pData[v14] = 0.0;
      --v10;
    }
    while ( v10 );
    this->m_iDrift += 2;
    this->m_bGotData = 0;
    m_iDrift = this->m_iDrift;
    if ( m_iDrift > 8 )
    {
      v16 = ((unsigned __int8)this->m_usReadBuffer + 2) & 0x1F;
      this->m_iDrift = m_iDrift - 1;
      this->m_usReadBuffer = v16;
    }
    return 1i64;
  }
  if ( this->m_bStopped )
    return 1i64;
  v1 = 4i64;
  v2 = 0i64;
  v3 = 4i64;
  do
  {
    v4 = v2 + this->m_usWriteBuffer;
    ++v2;
    this->m_pData[v4] = 0.0;
    --v3;
  }
  while ( v3 );
  v5 = 0i64;
  this->m_usWriteBuffer = ((unsigned __int8)this->m_usWriteBuffer + 4) & 0x1F;
  do
  {
    v6 = v5 + this->m_usWriteBuffer;
    ++v5;
    this->m_pData[v6] = 0.0;
    --v1;
  }
  while ( v1 );
  this->m_iDrift = 0;
  return 1i64;
}

// File Line: 185
// RVA: 0xACD2A0
void __fastcall RumbleBusBase::CommandTick(RumbleBusBase *this)
{
  AkCaptureFile *m_pCapture; // rcx
  unsigned __int16 v3; // ax
  int in_pData; // [rsp+30h] [rbp+8h] BYREF

  if ( this->m_usReadBuffer == this->m_usWriteBuffer )
  {
    m_pCapture = this->m_pCapture;
    if ( m_pCapture )
    {
      in_pData = 0;
      AkCaptureFile::PassSampleData(m_pCapture, &in_pData, 4u);
    }
    this->m_iDrift = 0;
  }
  else
  {
    this->vfptr[3].Reset(this);
    v3 = ((unsigned __int8)this->m_usReadBuffer + 2) & 0x1F;
    --this->m_iDrift;
    this->m_usReadBuffer = v3;
  }
}

// File Line: 208
// RVA: 0xACD320
float __fastcall RumbleBusBase::GetPeak(RumbleBusBase *this)
{
  float result; // xmm0_4

  result = this->m_fPeak;
  this->m_fPeak = 0.0;
  return result;
}

// File Line: 225
// RVA: 0xACD6B0
void __fastcall RumbleBusBase::SetMasterVolume(RumbleBusBase *this, float in_fVol)
{
  this->m_fVolume = in_fVol;
}

// File Line: 236
// RVA: 0xACD6C0
void __fastcall RumbleBusBase::StartOutputCapture(RumbleBusBase *this, const wchar_t *in_CaptureFileName)
{
  __int64 v4; // rdi
  __int64 v5; // rdx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rcx
  signed __int64 v8; // rcx
  void *v9; // rsp
  void *v10; // rsp
  unsigned __int64 v11; // rbx
  __int64 v12; // rax
  unsigned __int64 v13; // rdi
  unsigned __int16 *v14; // rcx
  unsigned __int16 v15; // ax
  unsigned int v16; // ebx
  AkCaptureMgr *v17; // rax
  unsigned __int16 _Dst[4]; // [rsp+30h] [rbp+0h] BYREF

  if ( !this->m_pCapture )
  {
    v4 = -1i64;
    v5 = -1i64;
    do
      ++v5;
    while ( in_CaptureFileName[v5] );
    v6 = v5 + 1;
    v7 = 2 * v6 + 19;
    if ( v7 <= 2 * v6 + 4 )
      v7 = 0xFFFFFFFFFFFFFF0i64;
    v8 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
    v9 = alloca(v8);
    v10 = alloca(v8);
    v11 = v6 - 1;
    v12 = -1i64;
    do
      ++v12;
    while ( in_CaptureFileName[v12] );
    if ( v11 >= v12 + 1 )
    {
      do
        ++v4;
      while ( in_CaptureFileName[v4] );
      v13 = v4 + 1;
    }
    else
    {
      v13 = v6 - 1;
    }
    wcsncpy_s(_Dst, v6, in_CaptureFileName, v13);
    _Dst[v13] = 0;
    if ( _Dst[v11] != 46 )
    {
      v14 = &_Dst[v11 + 2];
      do
      {
        if ( !v11 )
          break;
        v15 = _Dst[v11--];
        --v14;
        v14[1] = v15;
      }
      while ( _Dst[v11] != 46 );
    }
    _Dst[v11 + 2] = 46;
    _Dst[v11 + 1] = (unsigned __int8)this->m_iPlayer + 49;
    _Dst[v11] = 80;
    v16 = (unsigned __int16)(int)(float)((float)((float)(int)AkAudioLibSettings::g_pipelineCoreFrequency * 0.0009765625)
                                       * 8.0);
    v17 = AkCaptureMgr::Instance();
    this->m_pCapture = AkCaptureMgr::StartCapture(v17, _Dst, 2u, v16, 0x10u, Int16);
  }
}

// File Line: 262
// RVA: 0xACD840
void __fastcall RumbleBusBase::StopOutputCapture(RumbleBusBase *this)
{
  AkCaptureFile *m_pCapture; // rcx

  m_pCapture = this->m_pCapture;
  if ( m_pCapture )
  {
    AkCaptureFile::StopCapture(m_pCapture);
    this->m_pCapture = 0i64;
  }
}

