// File Line: 30
// RVA: 0xAEBD30
void __fastcall AkPitchShifterDSPProcess(
        AkAudioBuffer *io_pBuffer,
        AkPitchShifterFXInfo *io_FXInfo,
        float *in_pfBufferStorage,
        void *pTwoPassStorage)
{
  unsigned __int16 uValidFrames; // ax
  unsigned int v7; // edx
  unsigned int in_uNumFrames; // r14d
  unsigned int uChannelMask; // eax
  unsigned int in_uChanIndex; // r13d
  unsigned int v11; // r15d
  int v12; // ebp
  int v13; // edi
  float *LFE; // rsi
  float fDryLevel; // xmm2_4
  float v16; // xmm1_4
  unsigned int v17; // [rsp+40h] [rbp-48h]
  unsigned int v18; // [rsp+90h] [rbp+8h]
  unsigned int v19; // [rsp+98h] [rbp+10h]

  AkFXTailHandler::HandleTail(&io_FXInfo->FXTailHandler, io_pBuffer, io_FXInfo->uTailLength);
  uValidFrames = io_pBuffer->uValidFrames;
  if ( uValidFrames )
  {
    v7 = 0;
    in_uNumFrames = uValidFrames;
    uChannelMask = io_pBuffer->uChannelMask;
    v19 = 0;
    v18 = 0;
    v17 = uChannelMask;
    in_uChanIndex = 0;
    v11 = uChannelMask;
    v12 = 1;
    while ( v11 )
    {
      v13 = v12;
      v12 = __ROL4__(v12, 1);
      if ( (v13 & uChannelMask) != 0 )
      {
        if ( (v13 & 8) != 0 )
        {
          LFE = AkAudioBuffer::GetLFE(io_pBuffer);
        }
        else
        {
          LFE = (float *)((char *)io_pBuffer->pData + 4 * v7 * (unsigned __int64)io_pBuffer->uMaxFrames);
          v19 = v7 + 1;
        }
        if ( io_FXInfo->uNumProcessedChannels && (v13 & io_FXInfo->eProcessChannelMask) != 0 )
        {
          AK::DSP::AkDelayPitchShift::ProcessChannel(
            &io_FXInfo->PitchShifter,
            LFE,
            in_pfBufferStorage,
            in_uNumFrames,
            in_uChanIndex);
          if ( io_FXInfo->Params.Voice.Filter.eFilterType )
            AK::DSP::MultiChannelBiquadFilter<8>::ProcessChannel(
              &io_FXInfo->Filter,
              in_pfBufferStorage,
              in_uNumFrames,
              in_uChanIndex);
          ++in_uChanIndex;
        }
        if ( io_FXInfo->Params.bSyncDry )
        {
          DSP::CDelayLight::ProcessBuffer(
            (DSP::CDelayLight *)((char *)io_FXInfo->DryDelay + 16 * v18 + 8 * v18),
            LFE,
            in_uNumFrames);
          ++v18;
        }
        if ( io_FXInfo->uNumProcessedChannels && (v13 & io_FXInfo->eProcessChannelMask) != 0 )
        {
          DSP::Mix2Interp(
            LFE,
            in_pfBufferStorage,
            io_FXInfo->PrevParams.fDryLevel,
            io_FXInfo->Params.fDryLevel,
            io_FXInfo->PrevParams.fWetLevel,
            io_FXInfo->Params.fWetLevel,
            in_uNumFrames);
        }
        else
        {
          fDryLevel = io_FXInfo->Params.fDryLevel;
          v16 = io_FXInfo->PrevParams.fDryLevel;
          if ( fDryLevel == v16 )
            AK::DSP::ApplyGain_3(LFE, v16, in_uNumFrames);
          else
            AK::DSP::ApplyGainRamp_1(LFE, v16, fDryLevel, in_uNumFrames);
        }
        v7 = v19;
        uChannelMask = v17;
        v11 &= ~v13;
      }
    }
    io_FXInfo->PrevParams.Voice.Filter.eFilterType = io_FXInfo->Params.Voice.Filter.eFilterType;
    io_FXInfo->PrevParams.Voice.Filter.fFilterGain = io_FXInfo->Params.Voice.Filter.fFilterGain;
    io_FXInfo->PrevParams.Voice.Filter.fFilterFrequency = io_FXInfo->Params.Voice.Filter.fFilterFrequency;
    io_FXInfo->PrevParams.Voice.Filter.fFilterQFactor = io_FXInfo->Params.Voice.Filter.fFilterQFactor;
    io_FXInfo->PrevParams.Voice.fPitchFactor = io_FXInfo->Params.Voice.fPitchFactor;
    io_FXInfo->PrevParams.eInputType = io_FXInfo->Params.eInputType;
    io_FXInfo->PrevParams.fDryLevel = io_FXInfo->Params.fDryLevel;
    io_FXInfo->PrevParams.fWetLevel = io_FXInfo->Params.fWetLevel;
    io_FXInfo->PrevParams.fDelayTime = io_FXInfo->Params.fDelayTime;
    *(_DWORD *)&io_FXInfo->PrevParams.bProcessLFE = *(_DWORD *)&io_FXInfo->Params.bProcessLFE;
  }
}

