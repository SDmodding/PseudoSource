// File Line: 30
// RVA: 0xACD240
void __fastcall RumbleBusBase::RumbleBusBase(RumbleBusBase *this)
{
  RumbleBusBase *v1; // rbx

  v1 = this;
  this->vfptr = (AK::IAkPluginVtbl *)&RumbleBusBase::`vftable';
  memset(this->m_pData, 0, 0x80ui64);
  *(_DWORD *)&v1->m_iDrift = 0x1000000;
  *(_QWORD *)&v1->m_usWriteBuffer = 0i64;
  v1->m_bGotData = 0;
  v1->m_pCapture = 0i64;
  v1->m_fAverageSpeed = 0.0;
  v1->m_fVolume = 1.0;
}

// File Line: 47
// RVA: 0xACD870
signed __int64 __fastcall RumbleBusBase::Term(RumbleBusBase *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  RumbleBusBase *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  ((void (*)(void))this->vfptr[3].__vecDelDtor)();
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 66
// RVA: 0xACD340
signed __int64 __fastcall RumbleBusBase::Init(RumbleBusBase *this, AK::IAkPluginMemAlloc *in_pAllocator, AkPlatformInitSettings *io_pPDSettings, char in_iPlayer)
{
  this->m_iPlayer = in_iPlayer;
  return 1i64;
}

// File Line: 73
// RVA: 0xACD350
signed __int64 __fastcall RumbleBusBase::MixAudioBuffer(RumbleBusBase *this, AkAudioBuffer *io_rBuffer)
{
  AkAudioBuffer *v2; // rsi
  RumbleBusBase *v3; // rdi
  unsigned int v4; // ebx
  unsigned int i; // er8
  unsigned __int16 v6; // bp
  __int64 v7; // r14
  float v8; // xmm1_4
  unsigned __int16 v9; // ax
  __int64 v10; // r10
  signed __int64 v11; // r9
  float *v12; // rcx
  unsigned __int16 j; // dx
  __int64 v14; // rax

  v2 = io_rBuffer;
  v3 = this;
  v4 = 0;
  for ( i = io_rBuffer->uChannelMask & 0xFFFFFFF7; i; i &= i - 1 )
    ++v4;
  v6 = 0;
  v7 = 0i64;
  do
  {
    v8 = 0.0;
    v9 = v2->uValidFrames >> 1;
    if ( v4 )
    {
      v10 = v4;
      v11 = (signed __int64)v2->pData + 4 * v9 * v6;
      do
      {
        v12 = (float *)v11;
        for ( j = 0; j < (signed int)v9; ++v12 )
        {
          if ( *v12 > v8 )
            v8 = *v12;
          ++j;
        }
        v11 += 4i64 * v2->uMaxFrames;
        --v10;
      }
      while ( v10 );
    }
    ++v6;
    v3->m_pData[v7 + v3->m_usWriteBuffer] = (float)(v8 * v3->m_fVolume) + v3->m_pData[v7 + v3->m_usWriteBuffer];
    v14 = v7 + v3->m_usWriteBuffer;
    v7 += 2i64;
    v3->m_pData[v14 + 1] = (float)(v8 * v3->m_fVolume) + v3->m_pData[v14 + 1];
  }
  while ( v6 < 2u );
  v3->m_bGotData = 1;
  return 1i64;
}

// File Line: 101
// RVA: 0xACD480
signed __int64 __fastcall RumbleBusBase::MixFeedbackBuffer(RumbleBusBase *this, AkAudioBuffer *io_rBuffer)
{
  AkAudioBuffer *v2; // rsi
  RumbleBusBase *v3; // rbx
  unsigned __int16 v4; // bp
  unsigned __int64 v5; // rdi
  char v6; // r14
  unsigned __int16 v7; // r8
  float *v8; // r9
  float v9; // xmm0_4
  __int64 v10; // rax

  v2 = io_rBuffer;
  v3 = this;
  if ( io_rBuffer->uValidFrames )
  {
    v4 = 0;
    if ( (unsigned int)AkAudioBuffer::NumChannels(io_rBuffer) )
    {
      v5 = v2->uMaxFrames;
      v6 = 0;
      do
      {
        v7 = 0;
        v8 = (float *)((char *)v2->pData + 4 * v5 * v4);
        do
        {
          v9 = v3->m_fVolume * *v8;
          v10 = (v6 + (unsigned __int8)v3->m_usWriteBuffer + 2 * (_BYTE)v7) & 0x1F;
          if ( v9 < 0.0 )
            v9 = 0.0;
          ++v7;
          v3->m_pData[v10] = v9 + v3->m_pData[v10];
          v5 = v2->uMaxFrames;
          v8 += v5 >> 1;
        }
        while ( v7 < 2u );
        v6 = ++v4;
      }
      while ( v4 < (unsigned int)AkAudioBuffer::NumChannels(v2) );
    }
    v3->m_bGotData = 1;
  }
  return 1i64;
}

// File Line: 128
// RVA: 0xACD580
signed __int64 __fastcall RumbleBusBase::RenderData(RumbleBusBase *this)
{
  signed __int64 v1; // r8
  __int64 v2; // r9
  signed __int64 v3; // r10
  __int64 v4; // rax
  __int64 v5; // r9
  __int64 v6; // rax
  __int64 v8; // r9
  float v9; // xmm0_4
  signed __int64 v10; // r8
  float *v11; // rax
  signed __int64 v12; // rdx
  __int64 v13; // r9
  __int64 v14; // rax
  __int16 v15; // dx
  unsigned __int16 v16; // ax

  if ( this->m_bGotData )
  {
    v8 = this->m_usWriteBuffer;
    v9 = this->m_fPeak;
    v10 = 4i64;
    v11 = &this->m_pData[v8];
    v12 = 4i64;
    do
    {
      if ( *v11 > v9 )
        v9 = *v11;
      ++v11;
      this->m_fPeak = v9;
      --v12;
    }
    while ( v12 );
    this->m_usWriteBuffer = ((_BYTE)v8 + 4) & 0x1F;
    v13 = 0i64;
    do
    {
      v14 = v13++ + this->m_usWriteBuffer;
      this->m_pData[v14] = 0.0;
      --v10;
    }
    while ( v10 );
    this->m_iDrift += 2;
    this->m_bGotData = 0;
    v15 = this->m_iDrift;
    if ( v15 > 8 )
    {
      v16 = ((unsigned __int8)this->m_usReadBuffer + 2) & 0x1F;
      this->m_iDrift = v15 - 1;
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
    v4 = v2++ + this->m_usWriteBuffer;
    this->m_pData[v4] = 0.0;
    --v3;
  }
  while ( v3 );
  v5 = 0i64;
  this->m_usWriteBuffer = ((unsigned __int8)this->m_usWriteBuffer + 4) & 0x1F;
  do
  {
    v6 = v5++ + this->m_usWriteBuffer;
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
  RumbleBusBase *v1; // rbx
  AkCaptureFile *v2; // rcx
  unsigned __int16 v3; // ax
  int in_pData; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( this->m_usReadBuffer == this->m_usWriteBuffer )
  {
    v2 = this->m_pCapture;
    if ( v2 )
    {
      in_pData = 0;
      AkCaptureFile::PassSampleData(v2, &in_pData, 4u);
    }
    v1->m_iDrift = 0;
  }
  else
  {
    ((void (*)(void))this->vfptr[3].Reset)();
    v3 = ((unsigned __int8)v1->m_usReadBuffer + 2) & 0x1F;
    --v1->m_iDrift;
    v1->m_usReadBuffer = v3;
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
  const wchar_t *v2; // r8
  RumbleBusBase *v3; // r14
  signed __int64 v4; // rdi
  signed __int64 v5; // rdx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rcx
  signed __int64 v8; // rcx
  void *v9; // rsp
  void *v10; // rsp
  unsigned __int64 v11; // rbx
  signed __int64 v12; // rax
  unsigned __int64 v13; // rdi
  unsigned __int16 *v14; // rcx
  unsigned __int16 v15; // ax
  unsigned int v16; // ebx
  AkCaptureMgr *v17; // rax
  unsigned __int16 _Dst[4]; // [rsp+30h] [rbp+0h]

  v2 = in_CaptureFileName;
  v3 = this;
  if ( !this->m_pCapture )
  {
    v4 = -1i64;
    v5 = -1i64;
    do
      ++v5;
    while ( v2[v5] );
    v6 = v5 + 1;
    v7 = 2 * v6 + 19;
    if ( v7 <= 2 * v6 + 4 )
      v7 = 1152921504606846960i64;
    v8 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
    v9 = alloca(v8);
    v10 = alloca(v8);
    v11 = v6 - 1;
    v12 = -1i64;
    do
      ++v12;
    while ( v2[v12] );
    if ( v11 >= v12 + 1 )
    {
      do
        ++v4;
      while ( v2[v4] );
      v13 = v4 + 1;
    }
    else
    {
      v13 = v6 - 1;
    }
    wcsncpy_s(_Dst, v6, v2, v13);
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
    _Dst[v11 + 1] = (unsigned __int8)v3->m_iPlayer + 49;
    _Dst[v11] = 80;
    v16 = (unsigned __int16)(signed int)(float)((float)((float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                      * 0.0009765625)
                                              * 8.0);
    v17 = AkCaptureMgr::Instance();
    v3->m_pCapture = AkCaptureMgr::StartCapture(v17, _Dst, 2u, v16, 0x10u, Int16);
  }
}

// File Line: 262
// RVA: 0xACD840
void __fastcall RumbleBusBase::StopOutputCapture(RumbleBusBase *this)
{
  RumbleBusBase *v1; // rbx
  AkCaptureFile *v2; // rcx

  v1 = this;
  v2 = this->m_pCapture;
  if ( v2 )
  {
    AkCaptureFile::StopCapture(v2);
    v1->m_pCapture = 0i64;
  }
}

