// File Line: 40
// RVA: 0xAF89B0
void __fastcall AkHarmonizerDSPProcessVoice(float *in_pfCurChan, AkHarmonizerFXInfo *io_FXInfo, unsigned int in_uChannelIndex, unsigned int in_uVoiceIndex, float *in_pfMonoPitchedVoice, float *in_pfWet, unsigned int in_uNumFrames, bool in_bNoMoreData, float in_fResamplingFactor, float *in_pfPVTDWindow)
{
  AkHarmonizerFXInfo *v10; // rdi
  unsigned int v11; // er15
  __int64 v12; // rsi
  unsigned __int64 v13; // rbx

  v10 = io_FXInfo;
  v11 = in_uChannelIndex;
  v12 = in_uVoiceIndex;
  v13 = in_uVoiceIndex;
  if ( io_FXInfo->Params.Voice[v13].bEnable )
  {
    DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::ProcessPitchChannel(
      &io_FXInfo->PhaseVocoder[(unsigned int)v12],
      in_pfCurChan,
      in_uNumFrames,
      in_bNoMoreData,
      in_uChannelIndex,
      in_pfMonoPitchedVoice,
      in_fResamplingFactor,
      in_pfPVTDWindow);
    if ( v10->Params.Voice[v13].Filter.eFilterType )
      AK::DSP::MultiChannelBiquadFilter<8>::ProcessChannel(&v10->Filter[v12], in_pfMonoPitchedVoice, in_uNumFrames, v11);
    DSP::Mix2Interp(
      in_pfWet,
      in_pfMonoPitchedVoice,
      1.0,
      1.0,
      v10->PrevParams.Voice[v13].fGain,
      v10->Params.Voice[v13].fGain,
      in_uNumFrames);
  }
}

// File Line: 75
// RVA: 0xAF8AC0
void __fastcall AkHarmonizerDSPProcess(AkAudioBuffer *io_pBuffer, AkHarmonizerFXInfo *io_FXInfo, float *in_pfTempStorage)
{
  float *v3; // rdi
  AkAudioBuffer *v4; // r15
  AkHarmonizerFXInfo *v5; // rbx
  unsigned __int16 v6; // ax
  unsigned int v7; // er13
  __int64 in_uNumFrames; // r14
  float *v9; // r9
  signed int v10; // ebp
  unsigned int v11; // eax
  unsigned int v12; // er12
  signed int v13; // edi
  unsigned __int64 v14; // rcx
  float *v15; // rsi
  float *v16; // rax
  float v17; // xmm2_4
  float v18; // xmm1_4
  float *in_pfInput2; // [rsp+50h] [rbp-58h]
  float *in_pfPVTDWindow; // [rsp+58h] [rbp-50h]
  unsigned int in_uChannelIndex; // [rsp+B0h] [rbp+8h]
  unsigned int v22; // [rsp+B8h] [rbp+10h]
  float *in_pfMonoPitchedVoice; // [rsp+C0h] [rbp+18h]
  unsigned int v24; // [rsp+C8h] [rbp+20h]

  in_pfMonoPitchedVoice = in_pfTempStorage;
  v3 = in_pfTempStorage;
  v4 = io_pBuffer;
  v5 = io_FXInfo;
  AkFXTailHandler::HandleTail(&io_FXInfo->FXTailHandler, io_pBuffer, 12 * io_FXInfo->Params.uWindowSize);
  v6 = v4->uValidFrames;
  if ( v6 )
  {
    v7 = 0;
    in_uNumFrames = v6;
    v9 = &v3[v6];
    v22 = 0;
    in_uChannelIndex = 0;
    v10 = 1;
    in_pfPVTDWindow = &v3[2 * v6];
    v11 = v4->uChannelMask;
    in_pfInput2 = &v3[in_uNumFrames];
    v24 = v11;
    v12 = v4->uChannelMask;
    if ( v11 )
    {
      do
      {
        v13 = v10;
        v10 = __ROL4__(v10, 1);
        if ( v13 & v11 )
        {
          if ( v13 & 8 )
          {
            v16 = AkAudioBuffer::GetLFE(v4);
            v9 = in_pfInput2;
            v15 = v16;
          }
          else
          {
            v14 = v7++ * (unsigned __int64)v4->uMaxFrames;
            v15 = (float *)((char *)v4->pData + 4 * v14);
          }
          if ( v5->bWetPathEnabled && v13 & v5->eProcessChannelMask )
          {
            memset(v9, 0, (unsigned int)(4 * in_uNumFrames));
            AkHarmonizerDSPProcessVoice(
              v15,
              v5,
              in_uChannelIndex,
              0,
              in_pfMonoPitchedVoice,
              in_pfInput2,
              in_uNumFrames,
              v4->eState == 17,
              v5->Params.Voice[0].fPitchFactor,
              in_pfPVTDWindow);
            AkHarmonizerDSPProcessVoice(
              v15,
              v5,
              in_uChannelIndex++,
              1u,
              in_pfMonoPitchedVoice,
              in_pfInput2,
              in_uNumFrames,
              v4->eState == 17,
              v5->Params.Voice[1].fPitchFactor,
              in_pfPVTDWindow);
          }
          if ( v5->Params.bSyncDry )
            DSP::CDelayLight::ProcessBuffer((DSP::CDelayLight *)v5 + v22++ + 115i64, v15, in_uNumFrames);
          if ( v5->bWetPathEnabled && v13 & v5->eProcessChannelMask || v5->Params.eInputType == 6 && v13 == 2 && v24 & 2 )
          {
            DSP::Mix2Interp(
              v15,
              in_pfInput2,
              v5->PrevParams.fDryLevel,
              v5->Params.fDryLevel,
              v5->PrevParams.fWetLevel,
              v5->Params.fWetLevel,
              in_uNumFrames);
          }
          else
          {
            v17 = v5->Params.fDryLevel;
            v18 = v5->PrevParams.fDryLevel;
            if ( v17 == v18 )
              AK::DSP::ApplyGain_10(v15, v18, in_uNumFrames);
            else
              AK::DSP::ApplyGainRamp_4(v15, v18, v17, in_uNumFrames);
          }
          v11 = v24;
          v9 = in_pfInput2;
          v12 &= ~v13;
        }
      }
      while ( v12 );
    }
    v5->PrevParams.Voice[0].Filter.eFilterType = v5->Params.Voice[0].Filter.eFilterType;
    v5->PrevParams.Voice[0].Filter.fFilterGain = v5->Params.Voice[0].Filter.fFilterGain;
    v5->PrevParams.Voice[0].Filter.fFilterFrequency = v5->Params.Voice[0].Filter.fFilterFrequency;
    v5->PrevParams.Voice[0].Filter.fFilterQFactor = v5->Params.Voice[0].Filter.fFilterQFactor;
    v5->PrevParams.Voice[0].fPitchFactor = v5->Params.Voice[0].fPitchFactor;
    v5->PrevParams.Voice[0].fGain = v5->Params.Voice[0].fGain;
    *(_DWORD *)&v5->PrevParams.Voice[0].bEnable = *(_DWORD *)&v5->Params.Voice[0].bEnable;
    v5->PrevParams.Voice[1].Filter.eFilterType = v5->Params.Voice[1].Filter.eFilterType;
    v5->PrevParams.Voice[1].Filter.fFilterGain = v5->Params.Voice[1].Filter.fFilterGain;
    v5->PrevParams.Voice[1].Filter.fFilterFrequency = v5->Params.Voice[1].Filter.fFilterFrequency;
    v5->PrevParams.Voice[1].Filter.fFilterQFactor = v5->Params.Voice[1].Filter.fFilterQFactor;
    v5->PrevParams.Voice[1].fPitchFactor = v5->Params.Voice[1].fPitchFactor;
    v5->PrevParams.Voice[1].fGain = v5->Params.Voice[1].fGain;
    *(_DWORD *)&v5->PrevParams.Voice[1].bEnable = *(_DWORD *)&v5->Params.Voice[1].bEnable;
    v5->PrevParams.eInputType = v5->Params.eInputType;
    v5->PrevParams.fDryLevel = v5->Params.fDryLevel;
    v5->PrevParams.fWetLevel = v5->Params.fWetLevel;
    v5->PrevParams.uWindowSize = v5->Params.uWindowSize;
    *(_DWORD *)&v5->PrevParams.bProcessLFE = *(_DWORD *)&v5->Params.bProcessLFE;
  }
}

