// File Line: 35
// RVA: 0xA353A0
void __fastcall AkMP3PrepareForPlayback(const wchar_t *in_tszFilename, AkMP3BaseInfo *in_info, int in_msStartAt, void (__fastcall *in_funcCallback)(void *, int), void *in_pCallbackCookie)
{
  signed __int64 v5; // r10
  wchar_t v6; // ax
  int v7; // eax

  v5 = (char *)&g_AkMP3Info - (char *)in_tszFilename;
  do
  {
    v6 = *in_tszFilename;
    ++in_tszFilename;
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
  float v2; // xmm0_4
  float v3; // xmm1_4
  signed int v4; // edx
  float v5; // xmm3_4
  float v6; // xmm2_4

  v2 = (float)in_info->msDuration;
  if ( !in_info->bToc )
    return in_info->uFirstFrameOffset
         + (signed int)(float)((float)((float)in_msTime / v2) * (float)(signed int)in_info->uMPEGStreamSize);
  v3 = (float)((float)in_msTime / v2) * 100.0;
  if ( v3 >= 0.0 )
  {
    if ( v3 > 100.0 )
      v3 = FLOAT_100_0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = (signed int)v3;
  if ( (signed int)v3 > 99 )
    v4 = 99;
  if ( v4 >= 99 )
    v6 = FLOAT_256_0;
  else
    v6 = (float)(unsigned __int8)in_info->aToc[v4 + 1];
  v5 = (float)(unsigned __int8)in_info->aToc[v4];
  return in_info->uFirstFrameOffset
       + (signed int)(float)((float)((float)((float)((float)(v3 - (float)v4) * (float)(v6 - v5)) + v5) * 0.00390625)
                           * (float)(signed int)in_info->uMPEGStreamSize);
}

// File Line: 73
// RVA: 0xA35760
AK::IAkPlugin *__fastcall CreateMP3Source(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 240ui64);
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
    result = v2;
  }
  return result;
}

// File Line: 108
// RVA: 0xA35D30
signed __int64 __fastcall CAkFXSrcMP3::Init(CAkFXSrcMP3 *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkSourcePluginContext *in_pSourceFXContext, AK::IAkPluginParam *in_pParams, AkAudioFormat *io_rFormat)
{
  AK::IAkSourcePluginContext *v5; // rbx
  AK::IAkPluginMemAlloc *v6; // rsi
  CAkFXSrcMP3 *v7; // rdi
  AK::IAkPluginContextBaseVtbl *v8; // rax
  __int64 *v9; // rax
  AK::IAkAutoStream **v10; // rbx
  __int64 v11; // r10
  unsigned int v12; // er9
  signed int v13; // er10
  HACMSTREAM v14; // rcx
  __int64 v15; // rax
  unsigned __int64 v16; // rdx
  __int64 v17; // rax
  HACMSTREAM v18; // rcx
  __int16 *v19; // rax
  char v20; // dl
  signed int v21; // er8
  signed __int64 result; // rax
  LPWAVEFILTER pwfltr; // [rsp+20h] [rbp-51h]
  DWORD_PTR dwCallback; // [rsp+28h] [rbp-49h]
  DWORD_PTR dwInstance; // [rsp+30h] [rbp-41h]
  DWORD fdwOpen; // [rsp+38h] [rbp-39h]
  tWAVEFORMATEX pwfxSrc; // [rsp+40h] [rbp-31h]
  __int16 v28; // [rsp+52h] [rbp-1Fh]
  int v29; // [rsp+54h] [rbp-1Dh]
  int v30; // [rsp+58h] [rbp-19h]
  __int16 v31; // [rsp+5Ch] [rbp-15h]
  float v32; // [rsp+60h] [rbp-11h]
  __int64 v33; // [rsp+64h] [rbp-Dh]
  __int16 v34; // [rsp+6Ch] [rbp-5h]
  int v35; // [rsp+70h] [rbp-1h]
  __int64 v36; // [rsp+74h] [rbp+3h]
  __int64 v37; // [rsp+80h] [rbp+Fh]
  __int16 v38; // [rsp+88h] [rbp+17h]
  int v39; // [rsp+8Ch] [rbp+1Bh]
  char v40; // [rsp+90h] [rbp+1Fh]
  _DWORD *v41; // [rsp+F0h] [rbp+7Fh]

  v5 = in_pSourceFXContext;
  v6 = in_pAllocator;
  v7 = this;
  if ( (unsigned __int16)(in_info.uNumChannels - 1) > 1u || (unsigned __int16)(in_info.uSampleRate - 8000) > 0x9C40u )
    return 2i64;
  this->m_pSharedParams = (CAkFxSrcMP3Params *)in_pParams;
  this->m_pSourceFXContext = in_pSourceFXContext;
  fdwOpen = 0;
  pwfxSrc.wFormatTag = 85;
  pwfxSrc.nChannels = in_info.uNumChannels;
  pwfxSrc.nSamplesPerSec = in_info.uSampleRate;
  dwInstance = 0i64;
  pwfxSrc.nAvgBytesPerSec = 125 * in_info.uBitRate;
  dwCallback = 0i64;
  v31 = 1393;
  LOWORD(dwCallback) = 1;
  *(_DWORD *)((char *)&dwInstance + 6) = 16;
  *(_DWORD *)&pwfxSrc.wBitsPerSample = 786432;
  pwfxSrc.nBlockAlign = 1;
  v29 = 2;
  v30 = 66560;
  v28 = 1;
  this->m_hMP3Stream = 0i64;
  if ( acmStreamOpen_0(
         &this->m_hMP3Stream,
         0i64,
         &pwfxSrc,
         (LPWAVEFORMATEX)&dwCallback,
         0i64,
         dwCallback,
         dwInstance,
         fdwOpen) )
  {
    return 2i64;
  }
  v34 = 0;
  v33 = 0i64;
  v35 = 0;
  v8 = v5->vfptr;
  v36 = 201i64;
  v37 = 0i64;
  v38 = 0;
  v39 = -1;
  v32 = (float)(signed int)in_info.uBitRate * 0.125;
  v9 = (__int64 *)(*(__int64 (__fastcall **)(AK::IAkSourcePluginContext *))v8->gap8)(v5);
  LOBYTE(dwInstance) = 1;
  v10 = &v7->m_pStream;
  v11 = *v9;
  dwCallback = (DWORD_PTR)&v7->m_pStream;
  if ( (*(unsigned int (__fastcall **)(__int64 *, $0AC968BCA798225F2B235B4CAE77E902 *, int *, float *, _QWORD, AK::IAkAutoStream **, DWORD_PTR))(v11 + 48))(
         v9,
         &g_AkMP3Info,
         &v35,
         &v32,
         0i64,
         &v7->m_pStream,
         dwInstance) != 1 )
    return 2i64;
  if ( unk_14249C984 )
  {
    v12 = AkMP3SeekToTime(&in_info, unk_14249C984);
    v7->m_uFramePos = (signed int)((double)v13 * (double)in_info.uSampleRate * 0.001);
  }
  else
  {
    v12 = in_info.uFirstFrameOffset;
    v7->m_uFramePos = 0;
  }
  if ( v12 && (*v10)->vfptr->SetPosition(*v10, v12, 0i64, (__int64 *)&v40) != 1 )
    return 2i64;
  ((void (*)(void))(*v10)->vfptr->Start)();
  v14 = v7->m_hMP3Stream;
  LODWORD(pwfltr) = 0;
  if ( acmStreamSize_0(v14, 0x400u, (LPDWORD)&pwfltr, 0) )
    return 2i64;
  if ( !(_DWORD)pwfltr )
    return 2i64;
  v7->m_hdrACM.cbStruct = 124;
  v15 = (__int64)v6->vfptr->Malloc(v6, 1024ui64);
  v16 = (unsigned int)pwfltr;
  v7->m_hdrACM.cbSrcLength = 1024;
  v7->m_hdrACM.pbSrc = (char *)v15;
  v17 = (__int64)v6->vfptr->Malloc(v6, v16);
  v18 = v7->m_hMP3Stream;
  v7->m_hdrACM.pbDst = (char *)v17;
  v7->m_hdrACM.cbDstLength = (unsigned int)pwfltr;
  if ( acmStreamPrepareHeader_0(v18, &v7->m_hdrACM, 0) )
    return 2i64;
  v19 = (__int16 *)v7->m_hdrACM.pbDst;
  v7->m_hdrACM.cbSrcLengthUsed = 1024;
  v7->m_uDsBufSize = 0;
  v7->m_pDstBufPos = v19;
  v20 = in_info.uNumChannels;
  if ( in_info.uNumChannels == 1 || (v21 = 3, in_info.uNumChannels != 2) )
    v21 = 4;
  *v41 = in_info.uSampleRate;
  result = 1i64;
  v41[1] = v21 & 0x3FFFF | ((2 * v20 & 0x1F) << 24) | 0x400000;
  v7->m_uNumChannels = in_info.uNumChannels;
  v7->m_uSampleRate = in_info.uSampleRate;
  v7->m_msDuration = in_info.msDuration;
  v7->m_funcCallback = (void (__fastcall *)(void *, int))unk_14249C988;
  v7->m_pCallbackCookie = (void *)unk_14249C990;
  return result;
}

// File Line: 272
// RVA: 0xA36540
signed __int64 __fastcall CAkFXSrcMP3::Term(CAkFXSrcMP3 *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rbx
  CAkFXSrcMP3 *v3; // rdi

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_hdrACM.pbSrc )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
  if ( v3->m_hdrACM.pbDst )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 303
// RVA: 0xA35860
void __fastcall CAkFXSrcMP3::Execute(CAkFXSrcMP3 *this, AkAudioBuffer *io_pBufferOut)
{
  void (__fastcall *v2)(void *, int); // r8
  AkAudioBuffer *v3; // r12
  CAkFXSrcMP3 *v4; // rbx
  unsigned int v5; // ecx
  unsigned int v6; // er13
  char *v7; // rcx
  unsigned int v8; // er15
  unsigned int v9; // esi
  AKRESULT v10; // eax
  unsigned int v11; // ebp
  __int16 *v12; // rdi
  int v13; // eax
  unsigned int v14; // er14
  __int16 *v15; // rdx
  unsigned int v16; // eax
  unsigned __int64 v17; // rsi
  int v18; // ebp
  unsigned int v19; // er14
  unsigned int v20; // eax
  unsigned __int64 v21; // rsi
  char *Dst; // [rsp+50h] [rbp+8h]

  v2 = this->m_funcCallback;
  v3 = io_pBufferOut;
  v4 = this;
  if ( v2 )
  {
    v5 = (signed int)(1374389535 * (unsigned __int64)this->m_uSampleRate >> 32) >> 4;
    v2(v4->m_pCallbackCookie, 20 * v4->m_uFramePos / ((v5 >> 31) + v5));
  }
  v6 = v3->uMaxFrames;
  v7 = (char *)v3->pData;
  v8 = 0;
  Dst = (char *)v3->pData;
  if ( v3->uMaxFrames )
  {
    do
    {
      if ( !v4->m_uDsBufSize )
      {
        if ( v4->m_hdrACM.cbSrcLengthUsed == v4->m_hdrACM.cbSrcLength )
        {
          v9 = v4->m_uStreamBufferSize;
          if ( !v9 )
          {
            if ( v4->m_pStreamBuffer )
            {
              ((void (__fastcall *)(AK::IAkAutoStream *, signed __int64))v4->m_pStream->vfptr->ReleaseBuffer)(
                v4->m_pStream,
                1024i64);
              v4->m_pStreamBuffer = 0i64;
            }
            v10 = (unsigned int)v4->m_pStream->vfptr->GetBuffer(
                                  v4->m_pStream,
                                  &v4->m_pStreamBuffer,
                                  &v4->m_uStreamBufferSize,
                                  0);
            v3->eState = v10;
            if ( v10 == 46 || v10 == 2 )
            {
              v3->uValidFrames = 0;
              return;
            }
            v9 = v4->m_uStreamBufferSize;
            if ( !v9 )
            {
              v3->eState = 17;
              return;
            }
            v4->m_pStreamBufferPos = (char *)v4->m_pStreamBuffer;
          }
          if ( v9 > 0x400 )
            v9 = 1024;
          memmove(v4->m_hdrACM.pbSrc, v4->m_pStreamBufferPos, v9);
          v4->m_uStreamBufferSize -= v9;
          v4->m_pStreamBufferPos += v9;
          v4->m_hdrACM.cbSrcLength = v9;
        }
        acmStreamConvert_0(v4->m_hMP3Stream, &v4->m_hdrACM, 4u);
        if ( !v4->m_hdrACM.cbSrcLengthUsed && !v4->m_hdrACM.cbDstLengthUsed )
          break;
        v7 = Dst;
        v4->m_pDstBufPos = (__int16 *)v4->m_hdrACM.pbDst;
        v4->m_uDsBufSize = v4->m_hdrACM.cbDstLengthUsed;
      }
      v11 = v4->m_uDsBufSize;
      v12 = v4->m_pDstBufPos;
      v13 = v6 - v8;
      v14 = v4->m_uDsBufSize;
      v15 = v4->m_pDstBufPos;
      if ( v4->m_uNumChannels == 1 )
      {
        v16 = 2 * v13;
        if ( v16 < v11 )
          v14 = v16;
        v17 = v14;
        memmove(v7, v15, v14);
        v18 = v11 - v14;
        v19 = v14 >> 1;
      }
      else
      {
        v20 = 4 * v13;
        if ( v20 < v11 )
          v14 = v20;
        v17 = v14;
        memmove(v7, v15, v14);
        v18 = v11 - v14;
        v19 = v14 >> 2;
      }
      v4->m_uFramePos += v19;
      v21 = v17 >> 1;
      v8 += v19;
      v4->m_uDsBufSize = v18;
      v7 = &Dst[2 * v21];
      v4->m_pDstBufPos = &v12[v21];
      Dst += 2 * v21;
    }
    while ( v8 < v6 );
  }
  v3->uValidFrames = v8;
  v3->eState = 45;
}

// File Line: 400
// RVA: 0xA35D20
float __fastcall CAkFXSrcMP3::GetDuration(CAkFXSrcMP3 *this)
{
  return (float)this->m_msDuration;
}

