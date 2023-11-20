// File Line: 25
// RVA: 0x15BF90
AK::IAkPlugin *__fastcall CreateGrainPlayerSource(AK::IAkPluginMemAlloc *in_pAllocator)
{
  char *v1; // rbx

  v1 = (char *)in_pAllocator->vfptr->Malloc(in_pAllocator, 184ui64);
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
signed __int64 __fastcall CAkFXSrcGrainPlayer::Init(CAkFXSrcGrainPlayer *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkSourcePluginContext *in_pSourceFXContext, AK::IAkPluginParam *in_pParams, AkAudioFormat *io_rFormat)
{
  AK::IAkPluginContextBaseVtbl *v5; // rax
  AK::IAkPluginParam *v6; // rbx
  AK::IAkPluginMemAlloc *v7; // r14
  CAkFXSrcGrainPlayer *v8; // rbp
  int v9; // edi
  AkAudioFormat *v10; // rsi
  int i; // ecx
  GrainFileHeader *v12; // rbx
  char v14; // [rsp+40h] [rbp+8h]
  char *data; // [rsp+48h] [rbp+10h]

  v5 = in_pSourceFXContext->vfptr;
  v6 = in_pParams;
  v7 = in_pAllocator;
  v8 = this;
  v9 = 0;
  data = 0i64;
  v5->GetPluginMedia((AK::IAkPluginContextBase *)&in_pSourceFXContext->vfptr, 0, &data, (unsigned int *)&v14);
  v10 = io_rFormat;
  v8->m_pSharedParams = (CAkFxSrcGrainPlayerParams *)v6;
  *((_DWORD *)v10 + 1) ^= (*((_DWORD *)v10 + 1) ^ HIDWORD(v6[2].vfptr)) & 0x3FFFF;
  for ( i = *((_DWORD *)v10 + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v9;
  *((_DWORD *)v10 + 1) ^= (*((_DWORD *)v10 + 1) ^ (v9 << 26)) & 0x1F000000;
  v8->m_fCurGain = powf(10.0, v8->m_pSharedParams->m_Params.fGain * 0.050000001);
  v12 = (GrainFileHeader *)v7->vfptr->Malloc(v7, 32ui64);
  GrainFileHeader::GetGrainFileHeader(v12, data);
  v12->pGrains = (GrainHeader *)v7->vfptr->Malloc(v7, 16i64 * v12->NumberOfGrains);
  GrainFileHeader::Fixup(v12, data);
  SpectralEngineCoreDX::GrainPlayerSource::Initialize(&v8->m_grainPlayer, v12);
  v10->uSampleRate = v12->SampleRate;
  return 1i64;
}

// File Line: 78
// RVA: 0x15C1F0
signed __int64 __fastcall CAkFXSrcGrainPlayer::Term(CAkFXSrcGrainPlayer *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkFXSrcGrainPlayer *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
    this->vfptr->__vecDelDtor((AK::IAkPlugin *)this, 1u);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 107
// RVA: 0x15C000
void __fastcall CAkFXSrcGrainPlayer::Execute(CAkFXSrcGrainPlayer *this, AkAudioBuffer *io_pBufferOut)
{
  CAkFxSrcGrainPlayerParams *v2; // rax
  AkAudioBuffer *v3; // rdi
  CAkFXSrcGrainPlayer *v4; // rbx
  float v5; // xmm0_4
  SpectralEngineCoreDX::AudioSourceVtbl *v6; // rax
  int v7; // edx
  SpectralEngineCoreDX::AudioSourceVtbl *v8; // rax
  int v9; // [rsp+20h] [rbp-48h]
  int v10; // [rsp+24h] [rbp-44h]
  void *v11; // [rsp+28h] [rbp-40h]
  int v12; // [rsp+30h] [rbp-38h]
  char v13; // [rsp+34h] [rbp-34h]
  float v14; // [rsp+38h] [rbp-30h]
  int v15; // [rsp+3Ch] [rbp-2Ch]
  int v16; // [rsp+40h] [rbp-28h]
  int v17; // [rsp+44h] [rbp-24h]
  int v18; // [rsp+48h] [rbp-20h]
  float v19; // [rsp+4Ch] [rbp-1Ch]
  int v20; // [rsp+50h] [rbp-18h]

  v15 = 1065353216;
  v18 = 1065353216;
  v14 = FLOAT_0_15000001;
  v20 = 0;
  v16 = 4;
  v17 = 100;
  v13 = 0;
  v12 = 0;
  v2 = this->m_pSharedParams;
  v3 = io_pBufferOut;
  v4 = this;
  v19 = v2->m_Params.fFrequency;
  v5 = powf(10.0, v2->m_Params.fGain * 0.050000001);
  v6 = v4->m_grainPlayer.vfptr;
  v14 = v5;
  v6->Update(
    (SpectralEngineCoreDX::AudioSource *)&v4->m_grainPlayer.vfptr,
    (SpectralEngineCoreDX::SpectralUpdateParameters *)&v12);
  v7 = v3->uMaxFrames;
  v11 = v3->pData;
  v3->eState = 45;
  v8 = v4->m_grainPlayer.vfptr;
  v10 = v7;
  v9 = 0;
  v8->WriteToAudioBuffer(
    (SpectralEngineCoreDX::AudioSource *)&v4->m_grainPlayer.vfptr,
    (SpectralEngineCoreDX::AudioBuffer *)&v9);
  v3->uValidFrames = v9;
}

