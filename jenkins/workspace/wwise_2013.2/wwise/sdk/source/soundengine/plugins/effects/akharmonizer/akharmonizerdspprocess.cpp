// File Line: 40
// RVA: 0xAF89B0
void __fastcall AkHarmonizerDSPProcessVoice(
        float *in_pfCurChan,
        AkHarmonizerFXInfo *io_FXInfo,
        unsigned int in_uChannelIndex,
        unsigned int in_uVoiceIndex,
        float *in_pfMonoPitchedVoice,
        float *in_pfWet,
        unsigned int in_uNumFrames,
        bool in_bNoMoreData,
        float in_fResamplingFactor,
        ak_fft_cpx *in_pfPVTDWindow)
{
  __int64 v12; // rsi
  __int64 v13; // rbx

  v12 = in_uVoiceIndex;
  v13 = in_uVoiceIndex;
  if ( io_FXInfo->Params.Voice[v13].bEnable )
  {
    DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::ProcessPitchChannel(
      &io_FXInfo->PhaseVocoder[in_uVoiceIndex],
      in_pfCurChan,
      in_uNumFrames,
      in_bNoMoreData,
      in_uChannelIndex,
      in_pfMonoPitchedVoice,
      in_fResamplingFactor,
      in_pfPVTDWindow);
    if ( io_FXInfo->Params.Voice[v13].Filter.eFilterType )
      AK::DSP::MultiChannelBiquadFilter<8>::ProcessChannel(
        &io_FXInfo->Filter[v12],
        in_pfMonoPitchedVoice,
        in_uNumFrames,
        in_uChannelIndex);
    DSP::Mix2Interp(
      in_pfWet,
      in_pfMonoPitchedVoice,
      COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
      COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
      io_FXInfo->PrevParams.Voice[v13].fGain,
      io_FXInfo->Params.Voice[v13].fGain,
      in_uNumFrames);
  }
}

// File Line: 75
// RVA: 0xAF8AC0
void __fastcall AkHarmonizerDSPProcess(
        AkAudioBuffer *io_pBuffer,
        AkHarmonizerFXInfo *io_FXInfo,
        float *in_pfTempStorage)
{
  unsigned __int16 uValidFrames; // ax
  unsigned int v7; // r13d
  unsigned int in_uNumFrames; // r14d
  float *v9; // r9
  int v10; // ebp
  unsigned int uChannelMask; // eax
  unsigned int v12; // r12d
  int v13; // edi
  unsigned __int64 v14; // rcx
  float *v15; // rsi
  float *LFE; // rax
  float fDryLevel; // xmm2_4
  float v18; // xmm1_4
  float *in_pfInput2; // [rsp+50h] [rbp-58h]
  ak_fft_cpx *in_pfPVTDWindow; // [rsp+58h] [rbp-50h]
  unsigned int in_uChannelIndex; // [rsp+B0h] [rbp+8h]
  int v22; // [rsp+B8h] [rbp+10h]
  unsigned int v24; // [rsp+C8h] [rbp+20h]

  AkFXTailHandler::HandleTail(&io_FXInfo->FXTailHandler, io_pBuffer, 12 * io_FXInfo->Params.uWindowSize);
  uValidFrames = io_pBuffer->uValidFrames;
  if ( uValidFrames )
  {
    v7 = 0;
    in_uNumFrames = uValidFrames;
    v9 = &in_pfTempStorage[uValidFrames];
    v22 = 0;
    in_uChannelIndex = 0;
    v10 = 1;
    in_pfPVTDWindow = (ak_fft_cpx *)&in_pfTempStorage[2 * uValidFrames];
    uChannelMask = io_pBuffer->uChannelMask;
    in_pfInput2 = v9;
    v24 = uChannelMask;
    v12 = uChannelMask;
    while ( v12 )
    {
      v13 = v10;
      v10 = __ROL4__(v10, 1);
      if ( (v13 & uChannelMask) != 0 )
      {
        if ( (v13 & 8) != 0 )
        {
          LFE = AkAudioBuffer::GetLFE(io_pBuffer);
          v9 = in_pfInput2;
          v15 = LFE;
        }
        else
        {
          v14 = v7++ * (unsigned __int64)io_pBuffer->uMaxFrames;
          v15 = (float *)((char *)io_pBuffer->pData + 4 * v14);
        }
        if ( io_FXInfo->bWetPathEnabled && (v13 & io_FXInfo->eProcessChannelMask) != 0 )
        {
          memset(v9, 0, 4 * in_uNumFrames);
          AkHarmonizerDSPProcessVoice(
            v15,
            io_FXInfo,
            in_uChannelIndex,
            0,
            in_pfTempStorage,
            in_pfInput2,
            in_uNumFrames,
            io_pBuffer->eState == AK_NoMoreData,
            io_FXInfo->Params.Voice[0].fPitchFactor,
            in_pfPVTDWindow);
          AkHarmonizerDSPProcessVoice(
            v15,
            io_FXInfo,
            in_uChannelIndex++,
            1u,
            in_pfTempStorage,
            in_pfInput2,
            in_uNumFrames,
            io_pBuffer->eState == AK_NoMoreData,
            io_FXInfo->Params.Voice[1].fPitchFactor,
            in_pfPVTDWindow);
        }
        if ( io_FXInfo->Params.bSyncDry )
          DSP::CDelayLight::ProcessBuffer(&io_FXInfo->DryDelay[v22++], v15, in_uNumFrames);
        if ( io_FXInfo->bWetPathEnabled && (v13 & io_FXInfo->eProcessChannelMask) != 0
          || io_FXInfo->Params.eInputType == (AKINPUTTYPE_4POINT0|AKINPUTTYPE_STEREO) && v13 == 2 && (v24 & 2) != 0 )
        {
          DSP::Mix2Interp(
            v15,
            in_pfInput2,
            COERCE_DOUBLE((unsigned __int64)LODWORD(io_FXInfo->PrevParams.fDryLevel)),
            COERCE_DOUBLE((unsigned __int64)LODWORD(io_FXInfo->Params.fDryLevel)),
            io_FXInfo->PrevParams.fWetLevel,
            io_FXInfo->Params.fWetLevel,
            in_uNumFrames);
        }
        else
        {
          fDryLevel = io_FXInfo->Params.fDryLevel;
          v18 = io_FXInfo->PrevParams.fDryLevel;
          if ( fDryLevel == v18 )
            AK::DSP::ApplyGain_10(v15, v18, in_uNumFrames);
          else
            AK::DSP::ApplyGainRamp_4(v15, v18, fDryLevel, in_uNumFrames);
        }
        uChannelMask = v24;
        v9 = in_pfInput2;
        v12 &= ~v13;
      }
    }
    io_FXInfo->PrevParams.Voice[0].Filter.eFilterType = io_FXInfo->Params.Voice[0].Filter.eFilterType;
    io_FXInfo->PrevParams.Voice[0].Filter.fFilterGain = io_FXInfo->Params.Voice[0].Filter.fFilterGain;
    io_FXInfo->PrevParams.Voice[0].Filter.fFilterFrequency = io_FXInfo->Params.Voice[0].Filter.fFilterFrequency;
    io_FXInfo->PrevParams.Voice[0].Filter.fFilterQFactor = io_FXInfo->Params.Voice[0].Filter.fFilterQFactor;
    io_FXInfo->PrevParams.Voice[0].fPitchFactor = io_FXInfo->Params.Voice[0].fPitchFactor;
    io_FXInfo->PrevParams.Voice[0].fGain = io_FXInfo->Params.Voice[0].fGain;
    *(_DWORD *)&io_FXInfo->PrevParams.Voice[0].bEnable = *(_DWORD *)&io_FXInfo->Params.Voice[0].bEnable;
    io_FXInfo->PrevParams.Voice[1].Filter.eFilterType = io_FXInfo->Params.Voice[1].Filter.eFilterType;
    io_FXInfo->PrevParams.Voice[1].Filter.fFilterGain = io_FXInfo->Params.Voice[1].Filter.fFilterGain;
    io_FXInfo->PrevParams.Voice[1].Filter.fFilterFrequency = io_FXInfo->Params.Voice[1].Filter.fFilterFrequency;
    io_FXInfo->PrevParams.Voice[1].Filter.fFilterQFactor = io_FXInfo->Params.Voice[1].Filter.fFilterQFactor;
    io_FXInfo->PrevParams.Voice[1].fPitchFactor = io_FXInfo->Params.Voice[1].fPitchFactor;
    io_FXInfo->PrevParams.Voice[1].fGain = io_FXInfo->Params.Voice[1].fGain;
    *(_DWORD *)&io_FXInfo->PrevParams.Voice[1].bEnable = *(_DWORD *)&io_FXInfo->Params.Voice[1].bEnable;
    io_FXInfo->PrevParams.eInputType = io_FXInfo->Params.eInputType;
    io_FXInfo->PrevParams.fDryLevel = io_FXInfo->Params.fDryLevel;
    io_FXInfo->PrevParams.fWetLevel = io_FXInfo->Params.fWetLevel;
    io_FXInfo->PrevParams.uWindowSize = io_FXInfo->Params.uWindowSize;
    *(_DWORD *)&io_FXInfo->PrevParams.bProcessLFE = *(_DWORD *)&io_FXInfo->Params.bProcessLFE;
  }
}

