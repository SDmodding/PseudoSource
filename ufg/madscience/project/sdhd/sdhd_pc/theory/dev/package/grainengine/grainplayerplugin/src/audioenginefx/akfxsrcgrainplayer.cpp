// File Line: 25
// RVA: 0x15BF90
AK::IAkPlugin *__fastcall CreateGrainPlayerSource(AK::IAkPluginMemAlloc *in_pAllocator)
{
  char *v1; // rbx

  v1 = (char *)in_pAllocator->vfptr->Malloc(in_pAllocator, 184i64);
  if ( !v1 )
    return 0i64;
  *(_QWORD *)v1 = &AK::IAkPlugin::`vftable;
  *(_QWORD *)v1 = &AK::IAkSourcePlugin::`vftable;
  *(_QWORD *)v1 = &CAkFXSrcGrainPlayer::`vftable;
  SpectralEngineCoreDX::GrainPlayerSource::GrainPlayerSource((SpectralEngineCoreDX::GrainPlayerSource *)(v1 + 16));
  *((_QWORD *)v1 + 22) = 0i64;
  return (AK::IAkPlugin *)v1;
}

// File Line: 47
// RVA: 0x15C0E0
__int64 __fastcall CAkFXSrcGrainPlayer::Init(
        CAkFXSrcGrainPlayer *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkSourcePluginContext *in_pSourceFXContext,
        CAkFxSrcGrainPlayerParams *in_pParams,
        AkAudioFormat *io_rFormat)
{
  AK::IAkPluginContextBaseVtbl *vfptr; // rax
  int v9; // edi
  AkAudioFormat *v10; // rsi
  int i; // ecx
  GrainFileHeader *v12; // rbx
  char v14; // [rsp+40h] [rbp+8h] BYREF
  char *data; // [rsp+48h] [rbp+10h] BYREF

  vfptr = in_pSourceFXContext->vfptr;
  v9 = 0;
  data = 0i64;
  vfptr->GetPluginMedia(in_pSourceFXContext, 0, &data, (unsigned int *)&v14);
  v10 = io_rFormat;
  this->m_pSharedParams = in_pParams;
  *((_DWORD *)v10 + 1) ^= (*((_DWORD *)v10 + 1) ^ in_pParams->m_Params.uChannelMask) & 0x3FFFF;
  for ( i = *((_DWORD *)v10 + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v9;
  *((_DWORD *)v10 + 1) ^= (*((_DWORD *)v10 + 1) ^ (v9 << 26)) & 0x1F000000;
  this->m_fCurGain = powf(10.0, this->m_pSharedParams->m_Params.fGain * 0.050000001);
  v12 = (GrainFileHeader *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32i64);
  GrainFileHeader::GetGrainFileHeader(v12, data);
  v12->pGrains = (GrainHeader *)in_pAllocator->vfptr->Malloc(in_pAllocator, 16i64 * v12->NumberOfGrains);
  GrainFileHeader::Fixup(v12, data);
  SpectralEngineCoreDX::GrainPlayerSource::Initialize(&this->m_grainPlayer, v12);
  v10->uSampleRate = v12->SampleRate;
  return 1i64;
}

// File Line: 78
// RVA: 0x15C1F0
__int64 __fastcall CAkFXSrcGrainPlayer::Term(CAkFXSrcGrainPlayer *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
    this->vfptr->__vecDelDtor(this, 1i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 107
// RVA: 0x15C000
void __fastcall CAkFXSrcGrainPlayer::Execute(CAkFXSrcGrainPlayer *this, AkAudioBuffer *io_pBufferOut)
{
  CAkFxSrcGrainPlayerParams *m_pSharedParams; // rax
  float v5; // xmm0_4
  SpectralEngineCoreDX::AudioSourceVtbl *vfptr; // rax
  int uMaxFrames; // edx
  SpectralEngineCoreDX::AudioSourceVtbl *v8; // rax
  int v9[2]; // [rsp+20h] [rbp-48h] BYREF
  void *pData; // [rsp+28h] [rbp-40h]
  int v11; // [rsp+30h] [rbp-38h] BYREF
  char v12; // [rsp+34h] [rbp-34h]
  float v13; // [rsp+38h] [rbp-30h]
  int v14; // [rsp+3Ch] [rbp-2Ch]
  int v15; // [rsp+40h] [rbp-28h]
  int v16; // [rsp+44h] [rbp-24h]
  int v17; // [rsp+48h] [rbp-20h]
  float fFrequency; // [rsp+4Ch] [rbp-1Ch]
  int v19; // [rsp+50h] [rbp-18h]

  v14 = 1065353216;
  v17 = 1065353216;
  v13 = FLOAT_0_15000001;
  v19 = 0;
  v15 = 4;
  v16 = 100;
  v12 = 0;
  v11 = 0;
  m_pSharedParams = this->m_pSharedParams;
  fFrequency = m_pSharedParams->m_Params.fFrequency;
  v5 = powf(10.0, m_pSharedParams->m_Params.fGain * 0.050000001);
  vfptr = this->m_grainPlayer.vfptr;
  v13 = v5;
  vfptr->Update(&this->m_grainPlayer, (SpectralEngineCoreDX::SpectralUpdateParameters *)&v11);
  uMaxFrames = io_pBufferOut->uMaxFrames;
  pData = io_pBufferOut->pData;
  io_pBufferOut->eState = AK_DataReady;
  v8 = this->m_grainPlayer.vfptr;
  v9[1] = uMaxFrames;
  v9[0] = 0;
  v8->WriteToAudioBuffer(&this->m_grainPlayer, (SpectralEngineCoreDX::AudioBuffer *)v9);
  io_pBufferOut->uValidFrames = v9[0];
}

