// File Line: 32
// RVA: 0xA93C30
void __fastcall CAkSinkDirectSound::CAkSinkDirectSound(CAkSinkDirectSound *this)
{
  CAkSink::CAkSink(this, AkSink_Main_DirectSound);
  this->vfptr = (CAkSinkVtbl *)&CAkSinkDirectSound::`vftable;
  CAkSinkDirectSound::m_pDirectSound = 0i64;
  *(_QWORD *)&this->m_ulBufferSize = 0i64;
  *(_QWORD *)&this->m_lRefillToEnd = 0i64;
  *(_QWORD *)&this->m_uPlay = 0i64;
  this->m_pDSBuffer = 0i64;
  this->m_bStarved = 0;
}

// File Line: 56
// RVA: 0xA94350
unsigned int __fastcall CAkSinkDirectSound::Init(
        CAkSinkDirectSound *this,
        AkPlatformInitSettings *in_settings,
        unsigned int in_uChannelMask)
{
  unsigned int result; // eax
  unsigned int m_SpeakersConfig; // eax
  __int64 v8[7]; // [rsp+30h] [rbp-38h] BYREF

  if ( CoCreateInstance(
         &CLSID_DirectSound8,
         0i64,
         1u,
         &IID_IDirectSound8,
         (LPVOID *)&CAkSinkDirectSound::m_pDirectSound) < 0 )
    return 2;
  if ( ((int (__fastcall *)(IDirectSound8 *, _QWORD))CAkSinkDirectSound::m_pDirectSound->vfptr[3].AddRef)(
         CAkSinkDirectSound::m_pDirectSound,
         0i64) < 0 )
    return 2;
  if ( CAkSinkDirectSound::m_pDirectSound->vfptr[2].QueryInterface(
         CAkSinkDirectSound::m_pDirectSound,
         (_GUID *)in_settings->hWnd,
         (void **)2) < 0 )
    return 2;
  memset(&v8[1], 0, 32);
  v8[0] = 0x100000028i64;
  if ( ((int (__fastcall *)(IDirectSound8 *, __int64 *, IDirectSoundBuffer **, _QWORD))CAkSinkDirectSound::m_pDirectSound->vfptr[1].QueryInterface)(
         CAkSinkDirectSound::m_pDirectSound,
         v8,
         &this->m_pPrimaryBuffer,
         0i64) < 0 )
    return 2;
  this->m_SpeakersConfig = in_uChannelMask;
  if ( !in_uChannelMask )
    this->m_SpeakersConfig = CAkSinkDirectSound::GetDSSpeakerConfig(this);
  m_SpeakersConfig = this->m_SpeakersConfig;
  if ( m_SpeakersConfig != 1599 && m_SpeakersConfig != 63 && m_SpeakersConfig != 3 )
    this->m_SpeakersConfig = 3;
  result = CAkSinkDirectSound::SetPrimaryBufferFormat(this);
  if ( result == 1 )
    return CAkSink::AllocBuffer(this);
  return result;
}

// File Line: 121
// RVA: 0xA941D0
__int64 __fastcall CAkSinkDirectSound::GetDSSpeakerConfig(CAkSinkDirectSound *this)
{
  __int64 result; // rax
  int v2; // [rsp+38h] [rbp+10h] BYREF

  v2 = 0;
  if ( ((int (__fastcall *)(IDirectSound8 *, int *))CAkSinkDirectSound::m_pDirectSound->vfptr[2].Release)(
         CAkSinkDirectSound::m_pDirectSound,
         &v2) < 0 )
    return 3i64;
  switch ( (char)v2 )
  {
    case 0:
    case 7:
    case 8:
      result = 1599i64;
      break;
    case 3:
    case 5:
    case 6:
    case 9:
      result = 63i64;
      break;
    default:
      return 3i64;
  }
  return result;
}

// File Line: 165
// RVA: 0xA948E0
void __fastcall CAkSinkDirectSound::Term(CAkSinkDirectSound *this)
{
  void *pData; // rdx
  IDirectSoundBuffer8 *m_pDSBuffer; // rcx

  pData = this->m_MasterOut.pData;
  if ( pData )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pData);
    this->m_MasterOut.pData = 0i64;
  }
  m_pDSBuffer = this->m_pDSBuffer;
  if ( m_pDSBuffer )
  {
    ((void (__fastcall *)(IDirectSoundBuffer8 *))m_pDSBuffer->vfptr[6].QueryInterface)(m_pDSBuffer);
    this->m_pDSBuffer->vfptr->Release(this->m_pDSBuffer);
    this->m_pDSBuffer = 0i64;
  }
  if ( CAkSinkDirectSound::m_pDirectSound )
  {
    CAkSinkDirectSound::m_pDirectSound->vfptr->Release(CAkSinkDirectSound::m_pDirectSound);
    CAkSinkDirectSound::m_pDirectSound = 0i64;
  }
  CAkSink::StopOutputCapture(this);
  _((AMD_HD3D *)this);
}

// File Line: 222
// RVA: 0xA93C80
__int64 __fastcall CAkSinkDirectSound::CreateSecondaryBuffer(CAkSinkDirectSound *this)
{
  unsigned int m_SpeakersConfig; // r8d
  unsigned int v3; // ecx
  unsigned __int16 i; // dx
  int uNumRefillsInVoice; // r9d
  int v6; // eax
  unsigned int v7; // ecx
  __int16 v8; // dx
  int v9; // r9d
  __int64 result; // rax
  IDirectSoundBuffer8 *m_pDSBuffer; // rcx
  __int64 v12; // [rsp+40h] [rbp-29h] BYREF
  __int64 v13; // [rsp+48h] [rbp-21h] BYREF
  __int64 v14; // [rsp+50h] [rbp-19h]
  __int64 v15; // [rsp+58h] [rbp-11h]
  GUID v16; // [rsp+60h] [rbp-9h]
  __int64 v17; // [rsp+70h] [rbp+7h] BYREF
  __int64 v18; // [rsp+78h] [rbp+Fh]
  __int64 *v19; // [rsp+80h] [rbp+17h]
  __int64 v20; // [rsp+88h] [rbp+1Fh]
  __int64 v21; // [rsp+90h] [rbp+27h]
  size_t Size; // [rsp+D0h] [rbp+67h] BYREF
  int v23; // [rsp+D8h] [rbp+6Fh] BYREF
  __int64 v24; // [rsp+E0h] [rbp+77h] BYREF
  void *Dst; // [rsp+E8h] [rbp+7Fh] BYREF

  v18 = 0i64;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v17 = 0x1000000000028i64;
  if ( g_PDSettings.bGlobalFocus )
    HIDWORD(v17) = 98304;
  m_SpeakersConfig = this->m_SpeakersConfig;
  v19 = &v13;
  v3 = m_SpeakersConfig;
  for ( i = 0; v3; v3 &= v3 - 1 )
    ++i;
  uNumRefillsInVoice = g_PDSettings.uNumRefillsInVoice;
  v6 = i;
  this->m_usBlockAlign = 2 * i;
  v7 = m_SpeakersConfig;
  v8 = 0;
  v9 = (v6 * uNumRefillsInVoice) << 11;
  LODWORD(v18) = v9;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0i64;
  *(_QWORD *)&v16.Data1 = 0i64;
  for ( *(_QWORD *)v16.Data4 = 0i64; v7; v7 &= v7 - 1 )
    ++v8;
  WORD1(v13) = v8;
  HIWORD(v14) = 16;
  HIDWORD(v13) = AkAudioLibSettings::g_pipelineCoreFrequency;
  WORD2(v14) = 2 * v8;
  LODWORD(v14) = AkAudioLibSettings::g_pipelineCoreFrequency * (unsigned __int16)(2 * v8);
  if ( m_SpeakersConfig == 3 )
  {
    LOWORD(v15) = 0;
    LOWORD(v13) = 1;
  }
  else
  {
    LODWORD(v15) = 1048598;
    HIDWORD(v15) = m_SpeakersConfig;
    LOWORD(v13) = -2;
    v16 = GUID_00000001_0000_0010_8000_00aa00389b71;
  }
  this->m_ulBufferSize = v9;
  this->m_lRefillToEnd = v9;
  v24 = 0i64;
  Dst = 0i64;
  v12 = 0i64;
  result = ((__int64 (__fastcall *)(IDirectSound8 *, __int64 *, __int64 *, _QWORD))CAkSinkDirectSound::m_pDirectSound->vfptr[1].QueryInterface)(
             CAkSinkDirectSound::m_pDirectSound,
             &v17,
             &v24,
             0i64);
  if ( (int)result >= 0 )
  {
    if ( (**(int (__fastcall ***)(__int64, GUID *, IDirectSoundBuffer8 **))v24)(
           v24,
           &IID_IDirectSoundBuffer8,
           &this->m_pDSBuffer) < 0
      || ((int (__fastcall *)(IDirectSoundBuffer8 *, _QWORD, _QWORD, void **, size_t *, __int64 *, int *, int))this->m_pDSBuffer->vfptr[3].Release)(
           this->m_pDSBuffer,
           0i64,
           this->m_ulBufferSize,
           &Dst,
           &Size,
           &v12,
           &v23,
           1) < 0
      || (memset(Dst, 0, (unsigned int)Size),
          ((int (__fastcall *)(IDirectSoundBuffer8 *, void *, _QWORD, __int64, int))this->m_pDSBuffer->vfptr[6].AddRef)(
            this->m_pDSBuffer,
            Dst,
            (unsigned int)Size,
            v12,
            v23) < 0) )
    {
      m_pDSBuffer = this->m_pDSBuffer;
      if ( m_pDSBuffer )
      {
        m_pDSBuffer->vfptr->Release(m_pDSBuffer);
        this->m_pDSBuffer = 0i64;
      }
      if ( v24 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v24 + 16i64))(v24);
      return 2147500037i64;
    }
    else
    {
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v24 + 16i64))(v24);
      return 0i64;
    }
  }
  return result;
}

// File Line: 314
// RVA: 0xA94340
__int64 __fastcall CAkSinkDirectSound::GetThreadWaitTime(CAkSinkDirectSound *this)
{
  return AkAudioLibSettings::g_pcWaitTime;
}

// File Line: 319
// RVA: 0xA944C0
_BOOL8 __fastcall CAkSinkDirectSound::IsStarved(CAkSinkDirectSound *this)
{
  return this->m_bStarved;
}

// File Line: 324
// RVA: 0xA94760
void __fastcall CAkSinkDirectSound::ResetStarved(CAkSinkDirectSound *this)
{
  this->m_bStarved = 0;
}

// File Line: 329
// RVA: 0xA94730
__int64 __fastcall CAkSinkDirectSound::Play(CAkSinkDirectSound *this)
{
  return (unsigned int)(((unsigned int (__fastcall *)(IDirectSoundBuffer8 *, _QWORD, _QWORD, __int64))this->m_pDSBuffer->vfptr[4].QueryInterface)(
                          this->m_pDSBuffer,
                          0i64,
                          0i64,
                          1i64) != 0)
       + 1;
}

// File Line: 338
// RVA: 0xA94770
__int64 __fastcall CAkSinkDirectSound::SetPrimaryBufferFormat(CAkSinkDirectSound *this)
{
  unsigned int i; // eax
  unsigned int m_SpeakersConfig; // r8d
  unsigned int v4; // ecx
  __int16 j; // dx
  unsigned int v6; // ecx
  __int64 v8; // [rsp+20h] [rbp-48h] BYREF
  __int64 v9; // [rsp+28h] [rbp-40h]
  __int64 v10; // [rsp+30h] [rbp-38h]
  GUID v11; // [rsp+38h] [rbp-30h]

  while ( 1 )
  {
    while ( 1 )
    {
      for ( i = this->m_SpeakersConfig; i; i &= i - 1 )
        ;
      ((void (__fastcall *)(IDirectSoundBuffer *))this->m_pPrimaryBuffer->vfptr[6].QueryInterface)(this->m_pPrimaryBuffer);
      m_SpeakersConfig = this->m_SpeakersConfig;
      v8 = 0i64;
      v9 = 0i64;
      v10 = 0i64;
      *(_QWORD *)&v11.Data1 = 0i64;
      *(_QWORD *)v11.Data4 = 0i64;
      v4 = m_SpeakersConfig;
      for ( j = 0; v4; v4 &= v4 - 1 )
        ++j;
      WORD1(v8) = j;
      HIWORD(v9) = 16;
      WORD2(v9) = 2 * j;
      HIDWORD(v8) = AkAudioLibSettings::g_pipelineCoreFrequency;
      LODWORD(v9) = AkAudioLibSettings::g_pipelineCoreFrequency * (unsigned __int16)(2 * j);
      if ( m_SpeakersConfig == 3 )
      {
        LOWORD(v10) = 0;
        LOWORD(v8) = 1;
      }
      else
      {
        LODWORD(v10) = 1048598;
        LOWORD(v8) = -2;
        v11 = GUID_00000001_0000_0010_8000_00aa00389b71;
        HIDWORD(v10) = m_SpeakersConfig;
      }
      if ( ((int (__fastcall *)(IDirectSoundBuffer *, __int64 *))this->m_pPrimaryBuffer->vfptr[4].Release)(
             this->m_pPrimaryBuffer,
             &v8) >= 0
        && ((int (__fastcall *)(IDirectSoundBuffer *, _QWORD, _QWORD, __int64, __int64, __int64, __int64, _QWORD, _QWORD))this->m_pPrimaryBuffer->vfptr[4].QueryInterface)(
             this->m_pPrimaryBuffer,
             0i64,
             0i64,
             1i64,
             v8,
             v9,
             v10,
             *(_QWORD *)&v11.Data1,
             *(_QWORD *)v11.Data4) >= 0
        && (int)CAkSinkDirectSound::CreateSecondaryBuffer(this) >= 0 )
      {
        return 1i64;
      }
      v6 = this->m_SpeakersConfig;
      if ( v6 != 63 )
        break;
      this->m_SpeakersConfig = 3;
    }
    if ( v6 != 1599 )
      break;
    this->m_SpeakersConfig = 63;
  }
  return 2i64;
}

// File Line: 419
// RVA: 0xA94480
__int64 __fastcall CAkSinkDirectSound::IsDataNeeded(CAkSinkDirectSound *this, unsigned int *out_uBuffersNeeded)
{
  unsigned int *p_m_uFreeRefillFrames; // rbx
  __int64 result; // rax

  p_m_uFreeRefillFrames = &this->m_uFreeRefillFrames;
  result = CAkSinkDirectSound::GetRefillSize(this, &this->m_uFreeRefillFrames);
  if ( (_DWORD)result == 1 )
  {
    *out_uBuffersNeeded = *p_m_uFreeRefillFrames >> 10;
    return 1i64;
  }
  return result;
}

// File Line: 450
// RVA: 0xA944D0
__int64 __fastcall CAkSinkDirectSound::PassData(CAkSinkDirectSound *this)
{
  IDirectSoundBuffer8 *m_pDSBuffer; // r11
  unsigned int v4; // edi
  __int64 m_ulRefillOffset; // rdx
  int v6; // r8d
  unsigned int m_SpeakersConfig; // eax
  __int64 v8; // r8
  BufferUpdateParams in_rParams; // [rsp+40h] [rbp-38h] BYREF

  m_pDSBuffer = this->m_pDSBuffer;
  if ( !m_pDSBuffer )
    return 2i64;
  v4 = 1;
  if ( this->m_MasterOut.uValidFrames )
  {
    m_ulRefillOffset = this->m_ulRefillOffset;
    v6 = 0;
    memset(&in_rParams, 0, sizeof(in_rParams));
    m_SpeakersConfig = this->m_SpeakersConfig;
    for ( in_rParams.ulOffset = m_ulRefillOffset; m_SpeakersConfig; m_SpeakersConfig &= m_SpeakersConfig - 1 )
      ++v6;
    v8 = (unsigned int)(v6 << 11);
    in_rParams.ulBytes = v8;
    if ( ((int (__fastcall *)(IDirectSoundBuffer8 *, __int64, __int64, void **, unsigned int *, void **, unsigned int *, unsigned int, _QWORD))m_pDSBuffer->vfptr[3].Release)(
           m_pDSBuffer,
           m_ulRefillOffset,
           v8,
           &in_rParams.pvAudioPtr1,
           &in_rParams.ulAudioBytes1,
           &in_rParams.pvAudioPtr2,
           &in_rParams.ulAudioBytes2,
           in_rParams.ulFlags,
           *(_QWORD *)&in_rParams.ulOffset) < 0 )
      v4 = 2;
    if ( v4 == 1 )
    {
      CAkSinkDirectSound::DoRefill(this, &this->m_MasterOut, &in_rParams);
      if ( ((int (__fastcall *)(IDirectSoundBuffer8 *, void *, _QWORD, void *, unsigned int))this->m_pDSBuffer->vfptr[6].AddRef)(
             this->m_pDSBuffer,
             in_rParams.pvAudioPtr1,
             in_rParams.ulAudioBytes1,
             in_rParams.pvAudioPtr2,
             in_rParams.ulAudioBytes2) < 0 )
        return 2;
    }
  }
  return v4;
}

// File Line: 488
// RVA: 0xA945F0
__int64 __fastcall CAkSinkDirectSound::PassSilence(CAkSinkDirectSound *this)
{
  IDirectSoundBuffer8 *m_pDSBuffer; // rcx
  int m_usBlockAlign; // r8d
  __int64 m_ulRefillOffset; // rdx
  unsigned int v6; // edi
  void *v7; // rbp
  unsigned int v8; // edi
  AkCaptureFile *m_pCapture; // rcx
  __int64 v10; // r9
  __int64 v11; // r8
  unsigned int v12; // ecx
  void *v13; // rdx
  int v14; // [rsp+20h] [rbp-58h]
  void *Dst; // [rsp+48h] [rbp-30h] BYREF
  __int64 v16; // [rsp+50h] [rbp-28h] BYREF
  __int64 v17; // [rsp+58h] [rbp-20h] BYREF
  __int64 v18[3]; // [rsp+60h] [rbp-18h] BYREF

  m_pDSBuffer = this->m_pDSBuffer;
  if ( !m_pDSBuffer )
    return 2i64;
  m_usBlockAlign = this->m_usBlockAlign;
  m_ulRefillOffset = this->m_ulRefillOffset;
  Dst = 0i64;
  v16 = 0i64;
  v17 = 0i64;
  v18[0] = 0i64;
  v6 = 1;
  if ( ((int (__fastcall *)(IDirectSoundBuffer8 *, __int64, _QWORD, void **, __int64 *, __int64 *, __int64 *, _DWORD, unsigned __int64))m_pDSBuffer->vfptr[3].Release)(
         m_pDSBuffer,
         m_ulRefillOffset,
         (unsigned int)(m_usBlockAlign << 10),
         &Dst,
         &v16,
         &v17,
         v18,
         0,
         __PAIR64__(m_usBlockAlign << 10, m_ulRefillOffset)) < 0 )
    v6 = 2;
  if ( v6 == 1 )
  {
    v7 = Dst;
    v8 = this->m_usBlockAlign << 10;
    memset(Dst, 0, v8);
    m_pCapture = this->m_pCapture;
    if ( m_pCapture )
      AkCaptureFile::PassSampleData(m_pCapture, v7, v8);
    this->m_ulRefillOffset += v8;
    v10 = v17;
    v11 = (unsigned int)v16;
    v12 = this->m_ulRefillOffset;
    v6 = 1;
    if ( v12 >= this->m_ulBufferSize )
      v12 = 0;
    v13 = Dst;
    v14 = v18[0];
    this->m_ulRefillOffset = v12;
    if ( ((int (__fastcall *)(IDirectSoundBuffer8 *, void *, __int64, __int64, int))this->m_pDSBuffer->vfptr[6].AddRef)(
           this->m_pDSBuffer,
           v13,
           v11,
           v10,
           v14) < 0 )
      return 2;
  }
  return v6;
}

// File Line: 559
// RVA: 0xA93EB0
void __fastcall CAkSinkDirectSound::DoRefill(
        CAkSinkDirectSound *this,
        AkPipelineBufferBase *in_AudioBuffer,
        BufferUpdateParams *in_rParams)
{
  unsigned int m_SpeakersConfig; // r10d
  __int64 v4; // rdi
  unsigned int v6; // r9d
  signed int i; // esi
  unsigned int uChannelMask; // ecx
  float *pData; // rbx
  _WORD *pvAudioPtr1; // r13
  unsigned int v11; // r12d
  __m128i *v12; // rcx
  unsigned __int64 v13; // rdx
  float *v14; // rbx
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  _WORD *v19; // r11
  __int64 v20; // r9
  int v21; // r8d
  float *v22; // rcx
  _WORD *v23; // rdx
  float v24; // xmm0_4
  int v25; // r14d
  __int64 v26; // rcx
  float *v27; // r8
  int v28; // edx
  float *v29; // rax
  int v30; // edx
  float *v31; // rax
  int v32; // edx
  float *v33; // rax
  int v34; // edx
  float *v35; // rax
  int v36; // r10d
  __int64 v37; // r9
  _WORD *v38; // rdx
  float v39; // xmm0_4
  _WORD *v40; // rdx
  float v41; // xmm0_4
  AkCaptureFile *m_pCapture; // rcx
  unsigned int m_ulRefillOffset; // ecx

  m_SpeakersConfig = this->m_SpeakersConfig;
  v4 = 0i64;
  v6 = m_SpeakersConfig;
  for ( i = 0; v6; v6 &= v6 - 1 )
    ++i;
  uChannelMask = in_AudioBuffer->uChannelMask;
  pData = (float *)in_AudioBuffer->pData;
  pvAudioPtr1 = in_rParams->pvAudioPtr1;
  v11 = i << 10;
  if ( uChannelMask == m_SpeakersConfig )
  {
    v12 = (__m128i *)in_rParams->pvAudioPtr1;
    v13 = (unsigned __int64)&pData[v11];
    if ( (unsigned __int64)pData < v13 )
    {
      v14 = pData + 12;
      do
      {
        v15 = *(__m128 *)(v14 - 12);
        v16 = *(__m128 *)(v14 - 8);
        v17 = *(__m128 *)(v14 - 4);
        v14 += 16;
        v12 += 2;
        v18 = _mm_mul_ps((__m128)_xmm, *(__m128 *)(v14 - 16));
        v12[-2] = _mm_packs_epi32(
                    _mm_cvtps_epi32(_mm_mul_ps(v15, (__m128)_xmm)),
                    _mm_cvtps_epi32(_mm_mul_ps(v16, (__m128)_xmm)));
        v12[-1] = _mm_packs_epi32(_mm_cvtps_epi32(_mm_mul_ps(v17, (__m128)_xmm)), _mm_cvtps_epi32(v18));
      }
      while ( (unsigned __int64)(v14 - 12) < v13 );
    }
  }
  else
  {
    for ( ; uChannelMask; uChannelMask &= uChannelMask - 1 )
      v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= i )
    {
      v25 = 1024;
      v26 = 4i64 * (int)v4;
      v27 = pData + 1;
      v28 = 1024;
      v29 = pData;
      do
      {
        *v29 = (float)(v29[2] * 0.70700002) + *v29;
        v29 = (float *)((char *)v29 + v26);
        --v28;
      }
      while ( v28 );
      v30 = 1024;
      v31 = pData + 1;
      do
      {
        *v31 = (float)(v31[1] * 0.70700002) + *v31;
        v31 = (float *)((char *)v31 + v26);
        --v30;
      }
      while ( v30 );
      v32 = 1024;
      v33 = pData;
      do
      {
        *v33 = (float)(v33[4] * 0.70700002) + *v33;
        v33 = (float *)((char *)v33 + v26);
        --v32;
      }
      while ( v32 );
      v34 = 1024;
      v35 = pData + 1;
      do
      {
        *v35 = (float)(v35[4] * 0.70700002) + *v35;
        v35 = (float *)((char *)v35 + v26);
        --v34;
      }
      while ( v34 );
      v36 = 1024;
      v37 = 2i64 * i;
      v38 = pvAudioPtr1;
      do
      {
        v39 = *pData;
        if ( *pData <= 1.0 )
        {
          if ( v39 < -1.0 )
            v39 = FLOAT_N1_0;
        }
        else
        {
          v39 = *(float *)&FLOAT_1_0;
        }
        pData = (float *)((char *)pData + v26);
        *v38 = (int)(float)(v39 * 32767.0);
        v38 = (_WORD *)((char *)v38 + v37);
        --v36;
      }
      while ( v36 );
      v40 = pvAudioPtr1 + 1;
      do
      {
        v41 = *v27;
        if ( *v27 <= 1.0 )
        {
          if ( v41 < -1.0 )
            v41 = FLOAT_N1_0;
        }
        else
        {
          v41 = *(float *)&FLOAT_1_0;
        }
        v27 = (float *)((char *)v27 + v26);
        *v40 = (int)(float)(v41 * 32767.0);
        v40 = (_WORD *)((char *)v40 + v37);
        --v25;
      }
      while ( v25 );
    }
    else
    {
      memset(pvAudioPtr1, 0, 2i64 * v11);
      if ( (_DWORD)v4 )
      {
        v19 = pvAudioPtr1;
        v20 = 4i64 * (int)v4;
        do
        {
          v21 = 1024;
          v22 = pData;
          v23 = v19;
          do
          {
            v24 = *v22;
            if ( *v22 <= 1.0 )
            {
              if ( v24 < -1.0 )
                v24 = FLOAT_N1_0;
            }
            else
            {
              v24 = *(float *)&FLOAT_1_0;
            }
            v22 = (float *)((char *)v22 + v20);
            *v23 = (int)(float)(v24 * 32767.0);
            v23 += i;
            --v21;
          }
          while ( v21 );
          ++pData;
          ++v19;
          --v4;
        }
        while ( v4 );
      }
    }
  }
  m_pCapture = this->m_pCapture;
  if ( m_pCapture )
    AkCaptureFile::PassSampleData(m_pCapture, pvAudioPtr1, i << 11);
  this->m_ulRefillOffset += i << 11;
  m_ulRefillOffset = this->m_ulRefillOffset;
  if ( m_ulRefillOffset >= this->m_ulBufferSize )
    m_ulRefillOffset = 0;
  this->m_ulRefillOffset = m_ulRefillOffset;
}

// File Line: 661
// RVA: 0xA94270
__int64 __fastcall CAkSinkDirectSound::GetRefillSize(CAkSinkDirectSound *this, unsigned int *out_uRefillFrames)
{
  unsigned int m_uPlay; // edi
  unsigned int m_ulBufferSize; // r8d
  unsigned int m_ulRefillOffset; // ecx
  unsigned int m_uWrite; // edx
  unsigned int v9; // r9d
  bool v10; // al

  m_uPlay = this->m_uPlay;
  if ( ((unsigned int (__fastcall *)(IDirectSoundBuffer8 *, unsigned int *, unsigned int *))this->m_pDSBuffer->vfptr[1].AddRef)(
         this->m_pDSBuffer,
         &this->m_uPlay,
         &this->m_uWrite) )
  {
    return 2i64;
  }
  m_ulBufferSize = this->m_ulBufferSize;
  m_ulRefillOffset = this->m_ulRefillOffset;
  m_uWrite = this->m_uWrite;
  v9 = this->m_uPlay;
  this->m_lRefillToEnd = m_ulBufferSize - m_ulRefillOffset;
  if ( m_uWrite + v9 )
  {
    v10 = m_uPlay < m_ulRefillOffset && m_ulRefillOffset < m_uWrite
       || m_uWrite < m_uPlay && m_uPlay < m_ulRefillOffset
       || m_ulRefillOffset < m_uWrite && m_uWrite < m_uPlay;
    this->m_bStarved = v10;
    if ( m_ulRefillOffset <= v9 )
      m_ulBufferSize = v9 - m_ulRefillOffset;
    else
      m_ulBufferSize = v9 + m_ulBufferSize - m_ulRefillOffset;
  }
  *out_uRefillFrames = m_ulBufferSize / this->m_usBlockAlign;
  return 1i64;
}

