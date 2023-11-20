// File Line: 32
// RVA: 0xA93C30
void __fastcall CAkSinkDirectSound::CAkSinkDirectSound(CAkSinkDirectSound *this)
{
  CAkSinkDirectSound *v1; // rbx

  v1 = this;
  CAkSink::CAkSink((CAkSink *)&this->vfptr, AkSink_Main_DirectSound);
  v1->vfptr = (CAkSinkVtbl *)&CAkSinkDirectSound::`vftable';
  CAkSinkDirectSound::m_pDirectSound = 0i64;
  *(_QWORD *)&v1->m_ulBufferSize = 0i64;
  *(_QWORD *)&v1->m_lRefillToEnd = 0i64;
  *(_QWORD *)&v1->m_uPlay = 0i64;
  v1->m_pDSBuffer = 0i64;
  v1->m_bStarved = 0;
}

// File Line: 56
// RVA: 0xA94350
unsigned int __fastcall CAkSinkDirectSound::Init(CAkSinkDirectSound *this, AkPlatformInitSettings *in_settings, unsigned int in_uChannelMask)
{
  _GUID **v3; // rsi
  unsigned int v4; // edi
  CAkSinkDirectSound *v5; // rbx
  unsigned int result; // eax
  unsigned int v7; // eax
  __int64 v8; // [rsp+30h] [rbp-38h]
  __int64 v9; // [rsp+38h] [rbp-30h]
  __int64 v10; // [rsp+40h] [rbp-28h]
  __int64 v11; // [rsp+48h] [rbp-20h]
  __int64 v12; // [rsp+50h] [rbp-18h]

  v3 = (_GUID **)in_settings;
  v4 = in_uChannelMask;
  v5 = this;
  if ( CoCreateInstance(
         &CLSID_DirectSound8,
         0i64,
         1u,
         &IID_IDirectSound8,
         (LPVOID *)&CAkSinkDirectSound::m_pDirectSound) < 0 )
    return 2;
  if ( ((signed int (__fastcall *)(IDirectSound8 *, _QWORD))CAkSinkDirectSound::m_pDirectSound->vfptr[3].AddRef)(
         CAkSinkDirectSound::m_pDirectSound,
         0i64) < 0 )
    return 2;
  if ( CAkSinkDirectSound::m_pDirectSound->vfptr[2].QueryInterface(
         (IUnknown *)CAkSinkDirectSound::m_pDirectSound,
         *v3,
         (void **)2) < 0 )
    return 2;
  v9 = 0i64;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  v8 = 4294967336i64;
  if ( ((signed int (__fastcall *)(IDirectSound8 *, __int64 *, IDirectSoundBuffer **, _QWORD))CAkSinkDirectSound::m_pDirectSound->vfptr[1].QueryInterface)(
         CAkSinkDirectSound::m_pDirectSound,
         &v8,
         &v5->m_pPrimaryBuffer,
         0i64) < 0 )
    return 2;
  v5->m_SpeakersConfig = v4;
  if ( !v4 )
    v5->m_SpeakersConfig = CAkSinkDirectSound::GetDSSpeakerConfig(v5);
  v7 = v5->m_SpeakersConfig;
  if ( v7 != 1599 && v7 != 63 && v7 != 3 )
    v5->m_SpeakersConfig = 3;
  result = CAkSinkDirectSound::SetPrimaryBufferFormat(v5);
  if ( result == 1 )
    result = CAkSink::AllocBuffer((CAkSink *)&v5->vfptr);
  return result;
}

// File Line: 121
// RVA: 0xA941D0
signed __int64 __fastcall CAkSinkDirectSound::GetDSSpeakerConfig(CAkSinkDirectSound *this)
{
  signed __int64 result; // rax
  int v2; // [rsp+38h] [rbp+10h]

  v2 = 0;
  if ( ((signed int (__fastcall *)(IDirectSound8 *, int *))CAkSinkDirectSound::m_pDirectSound->vfptr[2].Release)(
         CAkSinkDirectSound::m_pDirectSound,
         &v2) < 0 )
    return 3i64;
  switch ( (unsigned __int8)v2 )
  {
    case 0u:
    case 7u:
    case 8u:
      result = 1599i64;
      break;
    case 3u:
    case 5u:
    case 6u:
    case 9u:
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
  void *v1; // rdx
  CAkSinkDirectSound *v2; // rbx
  IDirectSoundBuffer8 *v3; // rcx

  v1 = this->m_MasterOut.pData;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_MasterOut.pData = 0i64;
  }
  v3 = v2->m_pDSBuffer;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr[6].QueryInterface)();
    ((void (*)(void))v2->m_pDSBuffer->vfptr->Release)();
    v2->m_pDSBuffer = 0i64;
  }
  if ( CAkSinkDirectSound::m_pDirectSound )
  {
    ((void (*)(void))CAkSinkDirectSound::m_pDirectSound->vfptr->Release)();
    CAkSinkDirectSound::m_pDirectSound = 0i64;
  }
  CAkSink::StopOutputCapture((CAkSink *)&v2->vfptr);
  _((AMD_HD3D *)v2);
}

// File Line: 222
// RVA: 0xA93C80
__int64 __fastcall CAkSinkDirectSound::CreateSecondaryBuffer(CAkSinkDirectSound *this)
{
  CAkSinkDirectSound *v1; // rdi
  unsigned int v2; // er8
  unsigned int v3; // ecx
  unsigned __int16 i; // dx
  int v5; // er9
  int v6; // eax
  unsigned int v7; // ecx
  __int16 v8; // dx
  int v9; // er9
  __int64 result; // rax
  IDirectSoundBuffer8 *v11; // rcx
  __int64 v12; // [rsp+20h] [rbp-49h]
  __int64 v13; // [rsp+40h] [rbp-29h]
  __int64 v14; // [rsp+48h] [rbp-21h]
  __int64 v15; // [rsp+50h] [rbp-19h]
  __int64 v16; // [rsp+58h] [rbp-11h]
  GUID j; // [rsp+60h] [rbp-9h]
  __int64 v18; // [rsp+70h] [rbp+7h]
  __int64 v19; // [rsp+78h] [rbp+Fh]
  __int64 *v20; // [rsp+80h] [rbp+17h]
  __int64 v21; // [rsp+88h] [rbp+1Fh]
  __int64 v22; // [rsp+90h] [rbp+27h]
  size_t Size; // [rsp+D0h] [rbp+67h]
  int v24; // [rsp+D8h] [rbp+6Fh]
  __int64 v25; // [rsp+E0h] [rbp+77h]
  void *Dst; // [rsp+E8h] [rbp+7Fh]

  v1 = this;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  v18 = 281474976710696i64;
  if ( g_PDSettings.bGlobalFocus )
    HIDWORD(v18) = 98304;
  v2 = this->m_SpeakersConfig;
  v20 = &v14;
  v3 = v2;
  for ( i = 0; v3; v3 &= v3 - 1 )
    ++i;
  v5 = g_PDSettings.uNumRefillsInVoice;
  v6 = i;
  v1->m_usBlockAlign = 2 * i;
  v7 = v2;
  v8 = 0;
  v9 = v6 * v5 << 11;
  LODWORD(v19) = v9;
  v14 = 0i64;
  v15 = 0i64;
  v16 = 0i64;
  for ( j = (GUID)0i64; v7; v7 &= v7 - 1 )
    ++v8;
  WORD1(v14) = v8;
  HIWORD(v15) = 16;
  HIDWORD(v14) = AkAudioLibSettings::g_pipelineCoreFrequency;
  WORD2(v15) = 2 * v8;
  LODWORD(v15) = AkAudioLibSettings::g_pipelineCoreFrequency * (unsigned __int16)(2 * v8);
  if ( v2 == 3 )
  {
    LOWORD(v16) = 0;
    LOWORD(v14) = 1;
  }
  else
  {
    LODWORD(v16) = 1048598;
    HIDWORD(v16) = v2;
    LOWORD(v14) = -2;
    j = GUID_00000001_0000_0010_8000_00aa00389b71;
  }
  v1->m_ulBufferSize = v9;
  v1->m_lRefillToEnd = v9;
  v25 = 0i64;
  Dst = 0i64;
  v13 = 0i64;
  result = ((__int64 (__fastcall *)(IDirectSound8 *, __int64 *, __int64 *, _QWORD))CAkSinkDirectSound::m_pDirectSound->vfptr[1].QueryInterface)(
             CAkSinkDirectSound::m_pDirectSound,
             &v18,
             &v25,
             0i64);
  if ( (signed int)result >= 0 )
  {
    if ( (**(signed int (__fastcall ***)(__int64, GUID *, signed __int64))v25)(
           v25,
           &IID_IDirectSoundBuffer8,
           (signed __int64)&v1->m_pDSBuffer) < 0
      || ((signed int (__fastcall *)(IDirectSoundBuffer8 *, _QWORD, _QWORD, void **, size_t *))v1->m_pDSBuffer->vfptr[3].Release)(
           v1->m_pDSBuffer,
           0i64,
           v1->m_ulBufferSize,
           &Dst,
           &Size) < 0
      || (memset(Dst, 0, (unsigned int)Size),
          LODWORD(v12) = v24,
          ((signed int (__fastcall *)(IDirectSoundBuffer8 *, void *, _QWORD, __int64, __int64))v1->m_pDSBuffer->vfptr[6].AddRef)(
            v1->m_pDSBuffer,
            Dst,
            (unsigned int)Size,
            v13,
            v12) < 0) )
    {
      v11 = v1->m_pDSBuffer;
      if ( v11 )
      {
        ((void (*)(void))v11->vfptr->Release)();
        v1->m_pDSBuffer = 0i64;
      }
      if ( v25 )
        (*(void (**)(void))(*(_QWORD *)v25 + 16i64))();
      result = 2147500037i64;
    }
    else
    {
      (*(void (**)(void))(*(_QWORD *)v25 + 16i64))();
      result = 0i64;
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
  return (unsigned int)(((unsigned int (__fastcall *)(IDirectSoundBuffer8 *, _QWORD, _QWORD, signed __int64))this->m_pDSBuffer->vfptr[4].QueryInterface)(
                          this->m_pDSBuffer,
                          0i64,
                          0i64,
                          1i64) != 0)
       + 1;
}

// File Line: 338
// RVA: 0xA94770
signed __int64 __fastcall CAkSinkDirectSound::SetPrimaryBufferFormat(CAkSinkDirectSound *this, __int64 a2, __int64 a3)
{
  CAkSinkDirectSound *v3; // rbx
  unsigned int i; // eax
  unsigned int v5; // er8
  unsigned int v6; // ecx
  __int16 j; // dx
  int v8; // eax
  unsigned int v9; // ecx
  __int64 v11; // [rsp+20h] [rbp-48h]
  __int64 v12; // [rsp+28h] [rbp-40h]
  __int64 v13; // [rsp+30h] [rbp-38h]
  GUID v14; // [rsp+38h] [rbp-30h]

  v3 = this;
  while ( 1 )
  {
    for ( i = v3->m_SpeakersConfig; i; i &= i - 1 )
      ;
    ((void (__cdecl *)(IDirectSoundBuffer *, __int64, __int64))v3->m_pPrimaryBuffer->vfptr[6].QueryInterface)(
      v3->m_pPrimaryBuffer,
      a2,
      a3);
    v5 = v3->m_SpeakersConfig;
    v11 = 0i64;
    v12 = 0i64;
    v13 = 0i64;
    v14 = (GUID)0i64;
    v6 = v5;
    for ( j = 0; v6; v6 &= v6 - 1 )
      ++j;
    WORD1(v11) = j;
    HIWORD(v12) = 16;
    WORD2(v12) = 2 * j;
    HIDWORD(v11) = AkAudioLibSettings::g_pipelineCoreFrequency;
    LODWORD(v12) = AkAudioLibSettings::g_pipelineCoreFrequency * (unsigned __int16)(2 * j);
    if ( v5 == 3 )
    {
      LOWORD(v13) = 0;
      LOWORD(v11) = 1;
    }
    else
    {
      LODWORD(v13) = 1048598;
      LOWORD(v11) = -2;
      v14 = GUID_00000001_0000_0010_8000_00aa00389b71;
      HIDWORD(v13) = v5;
    }
    v8 = ((__int64 (__fastcall *)(IDirectSoundBuffer *, __int64 *))v3->m_pPrimaryBuffer->vfptr[4].Release)(
           v3->m_pPrimaryBuffer,
           &v11);
    if ( v8 >= 0 )
    {
      v8 = ((__int64 (__fastcall *)(IDirectSoundBuffer *, _QWORD, _QWORD, signed __int64, __int64))v3->m_pPrimaryBuffer->vfptr[4].QueryInterface)(
             v3->m_pPrimaryBuffer,
             0i64,
             0i64,
             1i64,
             v11);
      if ( v8 >= 0 )
      {
        v8 = CAkSinkDirectSound::CreateSecondaryBuffer(v3);
        if ( v8 >= 0 )
          return 1i64;
      }
    }
    v9 = v3->m_SpeakersConfig;
    if ( v9 == 63 )
    {
      v3->m_SpeakersConfig = 3;
      goto LABEL_16;
    }
    if ( v9 != 1599 )
      return 2i64;
    v3->m_SpeakersConfig = 63;
LABEL_16:
    if ( v8 >= 0 )
      return 1i64;
  }
}

// File Line: 419
// RVA: 0xA94480
signed __int64 __fastcall CAkSinkDirectSound::IsDataNeeded(CAkSinkDirectSound *this, unsigned int *out_uBuffersNeeded)
{
  unsigned int *v2; // rbx
  unsigned int *v3; // rdi
  signed __int64 result; // rax

  v2 = &this->m_uFreeRefillFrames;
  v3 = out_uBuffersNeeded;
  result = CAkSinkDirectSound::GetRefillSize(this, &this->m_uFreeRefillFrames);
  if ( (_DWORD)result == 1 )
  {
    *v3 = *v2 >> 10;
    result = 1i64;
  }
  return result;
}

// File Line: 450
// RVA: 0xA944D0
signed __int64 __fastcall CAkSinkDirectSound::PassData(CAkSinkDirectSound *this)
{
  IDirectSoundBuffer8 *v1; // r11
  CAkSinkDirectSound *v2; // rbx
  unsigned int v4; // edi
  __int64 v5; // rdx
  int v6; // er8
  unsigned int v7; // eax
  __int64 v8; // r8
  __int64 v9; // [rsp+20h] [rbp-58h]
  BufferUpdateParams in_rParams; // [rsp+40h] [rbp-38h]

  v1 = this->m_pDSBuffer;
  v2 = this;
  if ( !v1 )
    return 2i64;
  v4 = 1;
  if ( this->m_MasterOut.uValidFrames )
  {
    v5 = this->m_ulRefillOffset;
    v6 = 0;
    *(_QWORD *)&in_rParams.ulOffset = 0i64;
    in_rParams.pvAudioPtr1 = 0i64;
    *(_QWORD *)&in_rParams.ulAudioBytes1 = 0i64;
    in_rParams.pvAudioPtr2 = 0i64;
    *(_QWORD *)&in_rParams.ulAudioBytes2 = 0i64;
    v7 = this->m_SpeakersConfig;
    for ( in_rParams.ulOffset = v5; v7; v7 &= v7 - 1 )
      ++v6;
    v8 = (unsigned int)(v6 << 11);
    in_rParams.ulBytes = v8;
    if ( ((signed int (__fastcall *)(IDirectSoundBuffer8 *, __int64, __int64, void **, unsigned int *))v1->vfptr[3].Release)(
           v1,
           v5,
           v8,
           &in_rParams.pvAudioPtr1,
           &in_rParams.ulAudioBytes1) < 0 )
      v4 = 2;
    if ( v4 == 1 )
    {
      CAkSinkDirectSound::DoRefill(v2, &v2->m_MasterOut, &in_rParams);
      LODWORD(v9) = in_rParams.ulAudioBytes2;
      if ( ((signed int (__fastcall *)(IDirectSoundBuffer8 *, void *, _QWORD, void *, __int64))v2->m_pDSBuffer->vfptr[6].AddRef)(
             v2->m_pDSBuffer,
             in_rParams.pvAudioPtr1,
             in_rParams.ulAudioBytes1,
             in_rParams.pvAudioPtr2,
             v9) < 0 )
        v4 = 2;
    }
  }
  return v4;
}

// File Line: 488
// RVA: 0xA945F0
signed __int64 __fastcall CAkSinkDirectSound::PassSilence(CAkSinkDirectSound *this)
{
  CAkSinkDirectSound *v1; // rbx
  IDirectSoundBuffer8 *v2; // rcx
  int v4; // er8
  __int64 v5; // rdx
  __int64 v6; // r8
  unsigned int v7; // edi
  void *v8; // rbp
  unsigned int v9; // edi
  AkCaptureFile *v10; // rcx
  __int64 v11; // r9
  __int64 v12; // r8
  unsigned int v13; // ecx
  __int64 v14; // rdx
  __int64 v15; // [rsp+20h] [rbp-58h]
  __int128 v16; // [rsp+40h] [rbp-38h]
  __int64 v17; // [rsp+50h] [rbp-28h]
  __int64 v18; // [rsp+58h] [rbp-20h]
  __int64 v19; // [rsp+60h] [rbp-18h]

  v1 = this;
  v2 = this->m_pDSBuffer;
  if ( !v2 )
    return 2i64;
  v4 = v1->m_usBlockAlign;
  v5 = v1->m_ulRefillOffset;
  *((_QWORD *)&v16 + 1) = 0i64;
  v17 = 0i64;
  v18 = 0i64;
  v19 = 0i64;
  v6 = (unsigned int)(v4 << 10);
  *(_QWORD *)((char *)&v16 + 4) = (unsigned int)v6;
  v7 = 1;
  if ( ((signed int (__fastcall *)(IDirectSoundBuffer8 *, __int64, __int64, char *, __int64 *))v2->vfptr[3].Release)(
         v2,
         v5,
         v6,
         (char *)&v16 + 8,
         &v17) < 0 )
    v7 = 2;
  if ( v7 == 1 )
  {
    v8 = (void *)*((_QWORD *)&v16 + 1);
    v9 = v1->m_usBlockAlign << 10;
    memset(*((void **)&v16 + 1), 0, v9);
    v10 = v1->m_pCapture;
    if ( v10 )
      AkCaptureFile::PassSampleData(v10, v8, v9);
    v1->m_ulRefillOffset += v9;
    v11 = v18;
    v12 = (unsigned int)v17;
    v13 = v1->m_ulRefillOffset;
    v7 = 1;
    if ( v1->m_ulRefillOffset >= v1->m_ulBufferSize )
      v13 = 0;
    v14 = *((_QWORD *)&v16 + 1);
    LODWORD(v15) = v19;
    v1->m_ulRefillOffset = v13;
    if ( ((signed int (__fastcall *)(IDirectSoundBuffer8 *, __int64, __int64, __int64, __int64))v1->m_pDSBuffer->vfptr[6].AddRef)(
           v1->m_pDSBuffer,
           v14,
           v12,
           v11,
           v15) < 0 )
      v7 = 2;
  }
  return v7;
}

// File Line: 559
// RVA: 0xA93EB0
void __fastcall CAkSinkDirectSound::DoRefill(CAkSinkDirectSound *this, AkPipelineBufferBase *in_AudioBuffer, BufferUpdateParams *in_rParams)
{
  unsigned int v3; // er10
  __int64 v4; // rdi
  CAkSinkDirectSound *v5; // r15
  unsigned int v6; // er9
  signed int i; // esi
  unsigned int v8; // ecx
  float *v9; // rbx
  _WORD *v10; // r13
  unsigned int v11; // er12
  __m128i *v12; // rcx
  unsigned __int64 v13; // rdx
  signed __int64 v14; // rbx
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  _WORD *v19; // r11
  signed __int64 v20; // r9
  signed int v21; // er8
  float *v22; // rcx
  _WORD *v23; // rdx
  float v24; // xmm0_4
  signed int v25; // er14
  signed __int64 v26; // rcx
  float *v27; // r8
  signed int v28; // edx
  float *v29; // rax
  signed int v30; // edx
  float *v31; // rax
  signed int v32; // edx
  float *v33; // rax
  signed int v34; // edx
  float *v35; // rax
  signed int v36; // er10
  signed __int64 v37; // r9
  _WORD *v38; // rdx
  float v39; // xmm0_4
  _WORD *v40; // rdx
  float v41; // xmm0_4
  AkCaptureFile *v42; // rcx
  unsigned int v43; // ecx

  v3 = this->m_SpeakersConfig;
  v4 = 0i64;
  v5 = this;
  v6 = v3;
  for ( i = 0; v6; v6 &= v6 - 1 )
    ++i;
  v8 = in_AudioBuffer->uChannelMask;
  v9 = (float *)in_AudioBuffer->pData;
  v10 = in_rParams->pvAudioPtr1;
  v11 = i << 10;
  if ( v8 == v3 )
  {
    v12 = (__m128i *)in_rParams->pvAudioPtr1;
    v13 = (unsigned __int64)&v9[v11];
    if ( (unsigned __int64)v9 < v13 )
    {
      v14 = (signed __int64)(v9 + 12);
      do
      {
        v15 = *(__m128 *)(v14 - 48);
        v16 = *(__m128 *)(v14 - 32);
        v17 = *(__m128 *)(v14 - 16);
        v14 += 64i64;
        v12 += 2;
        v18 = _mm_mul_ps((__m128)_xmm, *(__m128 *)(v14 - 64));
        _mm_storeu_si128(
          v12 - 2,
          _mm_packs_epi32(
            _mm_cvtps_epi32(_mm_mul_ps(v15, (__m128)_xmm)),
            _mm_cvtps_epi32(_mm_mul_ps(v16, (__m128)_xmm))));
        _mm_storeu_si128(v12 - 1, _mm_packs_epi32(_mm_cvtps_epi32(_mm_mul_ps(v17, (__m128)_xmm)), _mm_cvtps_epi32(v18)));
      }
      while ( v14 - 48 < v13 );
    }
  }
  else
  {
    for ( ; v8; v8 &= v8 - 1 )
      v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= i )
    {
      v25 = 1024;
      v26 = 4i64 * (signed int)v4;
      v27 = v9 + 1;
      v28 = 1024;
      v29 = v9;
      do
      {
        *v29 = (float)(v29[2] * 0.70700002) + *v29;
        v29 = (float *)((char *)v29 + v26);
        --v28;
      }
      while ( v28 );
      v30 = 1024;
      v31 = v9 + 1;
      do
      {
        *v31 = (float)(v31[1] * 0.70700002) + *v31;
        v31 = (float *)((char *)v31 + v26);
        --v30;
      }
      while ( v30 );
      v32 = 1024;
      v33 = v9;
      do
      {
        *v33 = (float)(v33[4] * 0.70700002) + *v33;
        v33 = (float *)((char *)v33 + v26);
        --v32;
      }
      while ( v32 );
      v34 = 1024;
      v35 = v9 + 1;
      do
      {
        *v35 = (float)(v35[4] * 0.70700002) + *v35;
        v35 = (float *)((char *)v35 + v26);
        --v34;
      }
      while ( v34 );
      v36 = 1024;
      v37 = 2i64 * i;
      v38 = v10;
      do
      {
        v39 = *v9;
        if ( *v9 <= 1.0 )
        {
          if ( v39 < -1.0 )
            v39 = FLOAT_N1_0;
        }
        else
        {
          v39 = *(float *)&FLOAT_1_0;
        }
        v9 = (float *)((char *)v9 + v26);
        *v38 = (signed int)(float)(v39 * 32767.0);
        v38 = (_WORD *)((char *)v38 + v37);
        --v36;
      }
      while ( v36 );
      v40 = v10 + 1;
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
        *v40 = (signed int)(float)(v41 * 32767.0);
        v40 = (_WORD *)((char *)v40 + v37);
        --v25;
      }
      while ( v25 );
    }
    else
    {
      memset(v10, 0, 2i64 * v11);
      if ( (_DWORD)v4 )
      {
        v19 = v10;
        v20 = 4i64 * (signed int)v4;
        do
        {
          v21 = 1024;
          v22 = v9;
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
            *v23 = (signed int)(float)(v24 * 32767.0);
            v23 += i;
            --v21;
          }
          while ( v21 );
          ++v9;
          ++v19;
          --v4;
        }
        while ( v4 );
      }
    }
    LODWORD(v4) = 0;
  }
  v42 = v5->m_pCapture;
  if ( v42 )
    AkCaptureFile::PassSampleData(v42, v10, i << 11);
  v5->m_ulRefillOffset += i << 11;
  v43 = v5->m_ulRefillOffset;
  if ( v5->m_ulRefillOffset >= v5->m_ulBufferSize )
    v43 = v4;
  v5->m_ulRefillOffset = v43;
}

// File Line: 661
// RVA: 0xA94270
signed __int64 __fastcall CAkSinkDirectSound::GetRefillSize(CAkSinkDirectSound *this, unsigned int *out_uRefillFrames)
{
  unsigned int v2; // edi
  CAkSinkDirectSound *v3; // rbx
  unsigned int *v4; // r15
  unsigned int v6; // er8
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // er9
  bool v10; // al

  v2 = this->m_uPlay;
  v3 = this;
  v4 = out_uRefillFrames;
  if ( ((unsigned int (__fastcall *)(IDirectSoundBuffer8 *, unsigned int *, unsigned int *))this->m_pDSBuffer->vfptr[1].AddRef)(
         this->m_pDSBuffer,
         &v3->m_uPlay,
         &v3->m_uWrite) )
  {
    return 2i64;
  }
  v6 = v3->m_ulBufferSize;
  v7 = v3->m_ulRefillOffset;
  v8 = v3->m_uWrite;
  v9 = v3->m_uPlay;
  v3->m_lRefillToEnd = v3->m_ulBufferSize - v7;
  if ( v8 + v9 )
  {
    v10 = v2 < v7 && v7 < v8 || v8 < v2 && v2 < v7 || v7 < v8 && v8 < v2;
    v3->m_bStarved = v10;
    if ( v7 <= v9 )
      v6 = v9 - v7;
    else
      v6 = v9 + v6 - v7;
  }
  *v4 = v6 / v3->m_usBlockAlign;
  return 1i64;
}

