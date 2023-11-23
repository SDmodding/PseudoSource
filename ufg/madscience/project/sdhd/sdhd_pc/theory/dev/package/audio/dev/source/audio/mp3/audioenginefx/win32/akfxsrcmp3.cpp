// File Line: 35
// RVA: 0xA353A0
void __fastcall AkMP3PrepareForPlayback(
        const wchar_t *in_tszFilename,
        AkMP3BaseInfo *in_info,
        int in_msStartAt,
        void (__fastcall *in_funcCallback)(void *, int),
        void *in_pCallbackCookie)
{
  signed __int64 v5; // r10
  wchar_t v6; // ax
  int v7; // eax

  v5 = (char *)&g_AkMP3Info - (char *)in_tszFilename;
  do
  {
    v6 = *in_tszFilename++;
    *(const wchar_t *)((char *)in_tszFilename + v5 - 2) = v6;
  }
  while ( v6 );
  *(_DWORD *)&::in_info.uNumChannels = *(_DWORD *)&in_info->uNumChannels;
  ::in_info.msDuration = in_info->msDuration;
  ::in_info.uBitRate = in_info->uBitRate;
  ::in_info.uFirstFrameOffset = in_info->uFirstFrameOffset;
  ::in_info.uMPEGStreamSize = in_info->uMPEGStreamSize;
  *(_DWORD *)::in_info.aToc = *(_DWORD *)in_info->aToc;
  *(_DWORD *)&::in_info.aToc[4] = *(_DWORD *)&in_info->aToc[4];
  *(_DWORD *)&::in_info.aToc[8] = *(_DWORD *)&in_info->aToc[8];
  *(_DWORD *)&::in_info.aToc[12] = *(_DWORD *)&in_info->aToc[12];
  *(_DWORD *)&::in_info.aToc[16] = *(_DWORD *)&in_info->aToc[16];
  *(_DWORD *)&::in_info.aToc[20] = *(_DWORD *)&in_info->aToc[20];
  *(_DWORD *)&::in_info.aToc[24] = *(_DWORD *)&in_info->aToc[24];
  *(_DWORD *)&::in_info.aToc[28] = *(_DWORD *)&in_info->aToc[28];
  *(_DWORD *)&::in_info.aToc[32] = *(_DWORD *)&in_info->aToc[32];
  *(_DWORD *)&::in_info.aToc[36] = *(_DWORD *)&in_info->aToc[36];
  *(_DWORD *)&::in_info.aToc[40] = *(_DWORD *)&in_info->aToc[40];
  *(_DWORD *)&::in_info.aToc[44] = *(_DWORD *)&in_info->aToc[44];
  *(_DWORD *)&::in_info.aToc[48] = *(_DWORD *)&in_info->aToc[48];
  *(_DWORD *)&::in_info.aToc[52] = *(_DWORD *)&in_info->aToc[52];
  *(_DWORD *)&::in_info.aToc[56] = *(_DWORD *)&in_info->aToc[56];
  *(_DWORD *)&::in_info.aToc[60] = *(_DWORD *)&in_info->aToc[60];
  *(_DWORD *)&::in_info.aToc[64] = *(_DWORD *)&in_info->aToc[64];
  *(_DWORD *)&::in_info.aToc[68] = *(_DWORD *)&in_info->aToc[68];
  *(_DWORD *)&::in_info.aToc[72] = *(_DWORD *)&in_info->aToc[72];
  *(_DWORD *)&::in_info.aToc[76] = *(_DWORD *)&in_info->aToc[76];
  *(_DWORD *)&::in_info.aToc[80] = *(_DWORD *)&in_info->aToc[80];
  *(_DWORD *)&::in_info.aToc[84] = *(_DWORD *)&in_info->aToc[84];
  *(_DWORD *)&::in_info.aToc[88] = *(_DWORD *)&in_info->aToc[88];
  *(_DWORD *)&::in_info.aToc[92] = *(_DWORD *)&in_info->aToc[92];
  *(_DWORD *)&::in_info.aToc[96] = *(_DWORD *)&in_info->aToc[96];
  v7 = *(_DWORD *)&in_info->bToc;
  unk_14249C984 = in_msStartAt;
  *(_DWORD *)&::in_info.bToc = v7;
  unk_14249C988 = in_funcCallback;
  unk_14249C990 = in_pCallbackCookie;
}

// File Line: 46
// RVA: 0xA35500
__int64 __fastcall AkMP3SeekToTime(AkMP3BaseInfo *in_info, int in_msTime)
{
  float msDuration; // xmm0_4
  float v3; // xmm1_4
  int v4; // edx
  float v5; // xmm3_4
  float v6; // xmm2_4

  msDuration = (float)in_info->msDuration;
  if ( !in_info->bToc )
    return in_info->uFirstFrameOffset
         + (int)(float)((float)((float)in_msTime / msDuration) * (float)(int)in_info->uMPEGStreamSize);
  v3 = (float)((float)in_msTime / msDuration) * 100.0;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 100.0 )
      v3 = FLOAT_100_0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (int)v3;
  if ( (int)v3 > 99 )
    v4 = 99;
  if ( v4 >= 99 )
    v6 = FLOAT_256_0;
  else
    v6 = (float)(unsigned __int8)in_info->aToc[v4 + 1];
  v5 = (float)(unsigned __int8)in_info->aToc[v4];
  return in_info->uFirstFrameOffset
       + (int)(float)((float)((float)((float)((float)(v3 - (float)v4) * (float)(v6 - v5)) + v5) * 0.00390625)
                    * (float)(int)in_info->uMPEGStreamSize);
}

// File Line: 73
// RVA: 0xA35760
AK::IAkPlugin *__fastcall CreateMP3Source(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 240i64);
  v2 = result;
  if ( result )
  {
    result->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
    result->vfptr = (AK::IAkPluginVtbl *)&AK::IAkSourcePlugin::`vftable;
    result->vfptr = (AK::IAkPluginVtbl *)&CAkFXSrcMP3::`vftable;
    result[1].vfptr = 0i64;
    result[2].vfptr = 0i64;
    result[3].vfptr = 0i64;
    result[21].vfptr = 0i64;
    LODWORD(result[22].vfptr) = 0;
    result[23].vfptr = 0i64;
    result[24].vfptr = 0i64;
    LODWORD(result[25].vfptr) = 0;
    result[26].vfptr = 0i64;
    result[27].vfptr = 0i64;
    result[28].vfptr = 0i64;
    LODWORD(result[29].vfptr) = 0;
    memset(&result[5], 0, 0x7Cui64);
    return v2;
  }
  return result;
}

// File Line: 108
// RVA: 0xA35D30
signed __int64 __fastcall CAkFXSrcMP3::Init(
        CAkFXSrcMP3 *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkSourcePluginContext *in_pSourceFXContext,
        CAkFxSrcMP3Params *in_pParams,
        AkAudioFormat *io_rFormat)
{
  _DWORD *v5; // r12
  AK::IAkPluginContextBaseVtbl *vfptr; // rax
  __int64 v10; // rax
  AK::IAkAutoStream **p_m_pStream; // rbx
  unsigned int uFirstFrameOffset; // r9d
  int v13; // r10d
  HACMSTREAM__ *m_hMP3Stream; // rcx
  char *v15; // rax
  unsigned __int64 v16; // rdx
  char *v17; // rax
  HACMSTREAM__ *v18; // rcx
  __int16 *pbDst; // rax
  char uNumChannels; // dl
  int v21; // r8d
  signed __int64 result; // rax
  LPWAVEFILTER pwfltr; // [rsp+20h] [rbp-51h] BYREF
  DWORD_PTR dwCallback; // [rsp+28h] [rbp-49h] BYREF
  _BYTE dwInstance[12]; // [rsp+30h] [rbp-41h]
  tWAVEFORMATEX pwfxSrc; // [rsp+40h] [rbp-31h] BYREF
  __int16 v27; // [rsp+52h] [rbp-1Fh]
  int v28; // [rsp+54h] [rbp-1Dh]
  int v29; // [rsp+58h] [rbp-19h]
  __int16 v30; // [rsp+5Ch] [rbp-15h]
  float v31; // [rsp+60h] [rbp-11h] BYREF
  __int64 v32; // [rsp+64h] [rbp-Dh]
  __int16 v33; // [rsp+6Ch] [rbp-5h]
  int v34; // [rsp+70h] [rbp-1h] BYREF
  __int64 v35; // [rsp+74h] [rbp+3h]
  __int64 v36; // [rsp+80h] [rbp+Fh]
  __int16 v37; // [rsp+88h] [rbp+17h]
  int v38; // [rsp+8Ch] [rbp+1Bh]
  __int64 v39[6]; // [rsp+90h] [rbp+1Fh] BYREF

  if ( (unsigned __int16)(in_info.uNumChannels - 1) > 1u || (unsigned __int16)(in_info.uSampleRate - 8000) > 0x9C40u )
    return 2i64;
  this->m_pSharedParams = in_pParams;
  this->m_pSourceFXContext = in_pSourceFXContext;
  *(_WORD *)&dwInstance[10] = 0;
  pwfxSrc.wFormatTag = 85;
  pwfxSrc.nChannels = in_info.uNumChannels;
  pwfxSrc.nSamplesPerSec = in_info.uSampleRate;
  *(_QWORD *)dwInstance = 0i64;
  pwfxSrc.nAvgBytesPerSec = 125 * in_info.uBitRate;
  dwCallback = 1i64;
  v30 = 1393;
  *(_DWORD *)&dwInstance[6] = 16;
  *(_DWORD *)&pwfxSrc.wBitsPerSample = 786432;
  pwfxSrc.nBlockAlign = 1;
  v28 = 2;
  v29 = 66560;
  v27 = 1;
  this->m_hMP3Stream = 0i64;
  if ( acmStreamOpen_0(
         &this->m_hMP3Stream,
         0i64,
         &pwfxSrc,
         (LPWAVEFORMATEX)&dwCallback,
         0i64,
         dwCallback,
         *(DWORD_PTR *)dwInstance,
         *(DWORD *)&dwInstance[8]) )
  {
    return 2i64;
  }
  v33 = 0;
  v32 = 0i64;
  v34 = 0;
  vfptr = in_pSourceFXContext->vfptr;
  v35 = 201i64;
  v36 = 0i64;
  v37 = 0;
  v38 = -1;
  v31 = (float)(int)in_info.uBitRate * 0.125;
  v10 = (*(__int64 (__fastcall **)(AK::IAkSourcePluginContext *))vfptr->gap8)(in_pSourceFXContext);
  dwInstance[0] = 1;
  p_m_pStream = &this->m_pStream;
  if ( (*(unsigned int (__fastcall **)(__int64, $0AC968BCA798225F2B235B4CAE77E902 *, int *, float *, _QWORD, AK::IAkAutoStream **, _DWORD))(*(_QWORD *)v10 + 48i64))(
         v10,
         &g_AkMP3Info,
         &v34,
         &v31,
         0i64,
         &this->m_pStream,
         *(_DWORD *)dwInstance) != 1 )
    return 2i64;
  if ( unk_14249C984 )
  {
    uFirstFrameOffset = AkMP3SeekToTime(&in_info, unk_14249C984);
    this->m_uFramePos = (int)((double)v13 * (double)in_info.uSampleRate * 0.001);
  }
  else
  {
    uFirstFrameOffset = in_info.uFirstFrameOffset;
    this->m_uFramePos = 0;
  }
  if ( uFirstFrameOffset
    && (*p_m_pStream)->vfptr->SetPosition(*p_m_pStream, uFirstFrameOffset, AK_MoveBegin, v39) != AK_Success )
  {
    return 2i64;
  }
  (*p_m_pStream)->vfptr->Start(*p_m_pStream);
  m_hMP3Stream = this->m_hMP3Stream;
  LODWORD(pwfltr) = 0;
  if ( acmStreamSize_0(m_hMP3Stream, 0x400u, (LPDWORD)&pwfltr, 0) )
    return 2i64;
  if ( !(_DWORD)pwfltr )
    return 2i64;
  this->m_hdrACM.cbStruct = 124;
  v15 = (char *)in_pAllocator->vfptr->Malloc(in_pAllocator, 1024i64);
  v16 = (unsigned int)pwfltr;
  this->m_hdrACM.cbSrcLength = 1024;
  this->m_hdrACM.pbSrc = v15;
  v17 = (char *)in_pAllocator->vfptr->Malloc(in_pAllocator, v16);
  v18 = this->m_hMP3Stream;
  this->m_hdrACM.pbDst = v17;
  this->m_hdrACM.cbDstLength = (unsigned int)pwfltr;
  if ( acmStreamPrepareHeader_0(v18, &this->m_hdrACM, 0) )
    return 2i64;
  pbDst = (__int16 *)this->m_hdrACM.pbDst;
  this->m_hdrACM.cbSrcLengthUsed = 1024;
  this->m_uDsBufSize = 0;
  this->m_pDstBufPos = pbDst;
  uNumChannels = in_info.uNumChannels;
  if ( in_info.uNumChannels == 1 || (v21 = 3, in_info.uNumChannels != 2) )
    v21 = 4;
  *v5 = in_info.uSampleRate;
  result = 1i64;
  v5[1] = v21 & 0x3FFFF | (((2 * uNumChannels) & 0x1F) << 24) | 0x400000;
  this->m_uNumChannels = in_info.uNumChannels;
  this->m_uSampleRate = in_info.uSampleRate;
  this->m_msDuration = in_info.msDuration;
  this->m_funcCallback = (void (__fastcall *)(void *, int))unk_14249C988;
  this->m_pCallbackCookie = (void *)unk_14249C990;
  return result;
}

// File Line: 272
// RVA: 0xA36540
signed __int64 __fastcall CAkFXSrcMP3::Term(CAkFXSrcMP3 *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_hdrACM.pbSrc )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
  if ( this->m_hdrACM.pbDst )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 303
// RVA: 0xA35860
void __fastcall CAkFXSrcMP3::Execute(CAkFXSrcMP3 *this, AkAudioBuffer *io_pBufferOut)
{
  void (__fastcall *m_funcCallback)(void *, int); // r8
  unsigned int uMaxFrames; // r13d
  char *pData; // rcx
  unsigned int v7; // r15d
  unsigned int m_uStreamBufferSize; // esi
  AKRESULT v9; // eax
  unsigned int m_uDsBufSize; // ebp
  __int16 *m_pDstBufPos; // rdi
  unsigned int v12; // eax
  unsigned int v13; // r14d
  unsigned int v14; // eax
  unsigned __int64 v15; // rsi
  unsigned int v16; // ebp
  unsigned int v17; // r14d
  unsigned int v18; // eax
  unsigned __int64 v19; // rsi
  char *Dst; // [rsp+50h] [rbp+8h]

  m_funcCallback = this->m_funcCallback;
  if ( m_funcCallback )
    m_funcCallback(this->m_pCallbackCookie, 20 * this->m_uFramePos / (this->m_uSampleRate / 0x32u));
  uMaxFrames = io_pBufferOut->uMaxFrames;
  pData = (char *)io_pBufferOut->pData;
  v7 = 0;
  for ( Dst = (char *)io_pBufferOut->pData; v7 < uMaxFrames; Dst = pData )
  {
    if ( !this->m_uDsBufSize )
    {
      if ( this->m_hdrACM.cbSrcLengthUsed == this->m_hdrACM.cbSrcLength )
      {
        m_uStreamBufferSize = this->m_uStreamBufferSize;
        if ( !m_uStreamBufferSize )
        {
          if ( this->m_pStreamBuffer )
          {
            ((void (__fastcall *)(AK::IAkAutoStream *, __int64))this->m_pStream->vfptr->ReleaseBuffer)(
              this->m_pStream,
              1024i64);
            this->m_pStreamBuffer = 0i64;
          }
          v9 = this->m_pStream->vfptr->GetBuffer(this->m_pStream, &this->m_pStreamBuffer, &this->m_uStreamBufferSize, 0);
          io_pBufferOut->eState = v9;
          if ( v9 == AK_NoDataReady || v9 == AK_Fail )
          {
            io_pBufferOut->uValidFrames = 0;
            return;
          }
          m_uStreamBufferSize = this->m_uStreamBufferSize;
          if ( !m_uStreamBufferSize )
          {
            io_pBufferOut->eState = AK_NoMoreData;
            return;
          }
          this->m_pStreamBufferPos = (char *)this->m_pStreamBuffer;
        }
        if ( m_uStreamBufferSize > 0x400 )
          m_uStreamBufferSize = 1024;
        memmove(this->m_hdrACM.pbSrc, this->m_pStreamBufferPos, m_uStreamBufferSize);
        this->m_uStreamBufferSize -= m_uStreamBufferSize;
        this->m_pStreamBufferPos += m_uStreamBufferSize;
        this->m_hdrACM.cbSrcLength = m_uStreamBufferSize;
      }
      acmStreamConvert_0(this->m_hMP3Stream, &this->m_hdrACM, 4u);
      if ( !this->m_hdrACM.cbSrcLengthUsed && !this->m_hdrACM.cbDstLengthUsed )
        break;
      pData = Dst;
      this->m_pDstBufPos = (__int16 *)this->m_hdrACM.pbDst;
      this->m_uDsBufSize = this->m_hdrACM.cbDstLengthUsed;
    }
    m_uDsBufSize = this->m_uDsBufSize;
    m_pDstBufPos = this->m_pDstBufPos;
    v12 = uMaxFrames - v7;
    v13 = m_uDsBufSize;
    if ( this->m_uNumChannels == 1 )
    {
      v14 = 2 * v12;
      if ( v14 < m_uDsBufSize )
        v13 = v14;
      v15 = v13;
      memmove(pData, m_pDstBufPos, v13);
      v16 = m_uDsBufSize - v13;
      v17 = v13 >> 1;
    }
    else
    {
      v18 = 4 * v12;
      if ( v18 < m_uDsBufSize )
        v13 = v18;
      v15 = v13;
      memmove(pData, m_pDstBufPos, v13);
      v16 = m_uDsBufSize - v13;
      v17 = v13 >> 2;
    }
    this->m_uFramePos += v17;
    v19 = v15 >> 1;
    v7 += v17;
    this->m_uDsBufSize = v16;
    pData = &Dst[2 * v19];
    this->m_pDstBufPos = &m_pDstBufPos[v19];
  }
  io_pBufferOut->uValidFrames = v7;
  io_pBufferOut->eState = AK_DataReady;
}

// File Line: 400
// RVA: 0xA35D20
float __fastcall CAkFXSrcMP3::GetDuration(CAkFXSrcMP3 *this)
{
  return (float)this->m_msDuration;
}

