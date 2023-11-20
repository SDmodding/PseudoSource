// File Line: 30
// RVA: 0xAEBD30
void __fastcall AkPitchShifterDSPProcess(AkAudioBuffer *io_pBuffer, AkPitchShifterFXInfo *io_FXInfo, float *in_pfBufferStorage, void *pTwoPassStorage)
{
  AkAudioBuffer *v4; // r12
  AkPitchShifterFXInfo *v5; // rbx
  unsigned __int16 v6; // ax
  unsigned int v7; // edx
  unsigned int in_uNumFrames; // er14
  unsigned int v9; // eax
  unsigned int in_uChanIndex; // er13
  unsigned int v11; // er15
  signed int v12; // ebp
  signed int v13; // edi
  float *v14; // rsi
  float v15; // xmm2_4
  float v16; // xmm1_4
  unsigned int v17; // [rsp+40h] [rbp-48h]
  unsigned int v18; // [rsp+90h] [rbp+8h]
  int v19; // [rsp+98h] [rbp+10h]
  float *out_pfOutBuf; // [rsp+A0h] [rbp+18h]

  out_pfOutBuf = in_pfBufferStorage;
  v4 = io_pBuffer;
  v5 = io_FXInfo;
  AkFXTailHandler::HandleTail(&io_FXInfo->FXTailHandler, io_pBuffer, io_FXInfo->uTailLength);
  v6 = v4->uValidFrames;
  if ( v6 )
  {
    v7 = 0;
    in_uNumFrames = v6;
    v9 = v4->uChannelMask;
    v19 = 0;
    v18 = 0;
    v17 = v9;
    in_uChanIndex = 0;
    v11 = v4->uChannelMask;
    v12 = 1;
    if ( v9 )
    {
      do
      {
        v13 = v12;
        v12 = __ROL4__(v12, 1);
        if ( v13 & v9 )
        {
          if ( v13 & 8 )
          {
            v14 = AkAudioBuffer::GetLFE(v4);
          }
          else
          {
            v14 = (float *)((char *)v4->pData + 4 * v7 * (unsigned __int64)v4->uMaxFrames);
            v19 = v7 + 1;
          }
          if ( v5->uNumProcessedChannels && v13 & v5->eProcessChannelMask )
          {
            AK::DSP::AkDelayPitchShift::ProcessChannel(
              &v5->PitchShifter,
              v14,
              out_pfOutBuf,
              in_uNumFrames,
              in_uChanIndex);
            if ( v5->Params.Voice.Filter.eFilterType )
              AK::DSP::MultiChannelBiquadFilter<8>::ProcessChannel(
                &v5->Filter,
                out_pfOutBuf,
                in_uNumFrames,
                in_uChanIndex);
            ++in_uChanIndex;
          }
          if ( v5->Params.bSyncDry )
          {
            DSP::CDelayLight::ProcessBuffer(
              (DSP::CDelayLight *)((char *)v5 + 8 * (v18 + 2i64 * v18 + 49)),
              v14,
              in_uNumFrames);
            ++v18;
          }
          if ( v5->uNumProcessedChannels && v13 & v5->eProcessChannelMask )
          {
            DSP::Mix2Interp(
              v14,
              out_pfOutBuf,
              v5->PrevParams.fDryLevel,
              v5->Params.fDryLevel,
              v5->PrevParams.fWetLevel,
              v5->Params.fWetLevel,
              in_uNumFrames);
          }
          else
          {
            v15 = v5->Params.fDryLevel;
            v16 = v5->PrevParams.fDryLevel;
            if ( v15 == v16 )
              AK::DSP::ApplyGain_3(v14, v16, in_uNumFrames);
            else
              AK::DSP::ApplyGainRamp_1(v14, v16, v15, in_uNumFrames);
          }
          v7 = v19;
          v9 = v17;
          v11 &= ~v13;
        }
      }
      while ( v11 );
    }
    v5->PrevParams.Voice.Filter.eFilterType = v5->Params.Voice.Filter.eFilterType;
    v5->PrevParams.Voice.Filter.fFilterGain = v5->Params.Voice.Filter.fFilterGain;
    v5->PrevParams.Voice.Filter.fFilterFrequency = v5->Params.Voice.Filter.fFilterFrequency;
    v5->PrevParams.Voice.Filter.fFilterQFactor = v5->Params.Voice.Filter.fFilterQFactor;
    v5->PrevParams.Voice.fPitchFactor = v5->Params.Voice.fPitchFactor;
    v5->PrevParams.Voice.fGain = v5->Params.Voice.fGain;
    v5->PrevParams.fDryLevel = v5->Params.fDryLevel;
    v5->PrevParams.fWetLevel = v5->Params.fWetLevel;
    v5->PrevParams.fDelayTime = v5->Params.fDelayTime;
    *(_DWORD *)&v5->PrevParams.bProcessLFE = *(_DWORD *)&v5->Params.bProcessLFE;
  }
}

