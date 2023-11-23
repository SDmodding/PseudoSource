// File Line: 20
// RVA: 0xABC670
void __fastcall DecodeVorbis(
        AkTremorInfo *in_pTremorInfo,
        unsigned __int16 in_uMaxPacketSize,
        char *in_pInputBuf,
        __int16 *in_pOuputBuf)
{
  unsigned __int64 uInputDataSize; // r15
  int uRequestedFrames; // edi
  __int64 v10; // rsi
  int v11; // ecx
  unsigned __int16 v12; // dx
  char *v13; // r9
  unsigned int v14; // eax
  bool v15; // zf
  ogg_packet op; // [rsp+20h] [rbp-48h] BYREF

  uInputDataSize = in_pTremorInfo->uInputDataSize;
  uRequestedFrames = in_pTremorInfo->uRequestedFrames;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = vorbis_dsp_pcmout(&in_pTremorInfo->VorbisDSPState, in_pOuputBuf, uRequestedFrames);
    if ( !v11 )
      break;
    uRequestedFrames -= v11;
    in_pOuputBuf += (unsigned int)(v11 * in_pTremorInfo->VorbisDSPState.channels);
LABEL_12:
    if ( !uRequestedFrames )
      goto LABEL_13;
  }
  if ( v10 + 2 <= uInputDataSize )
  {
    v12 = *(_WORD *)&in_pInputBuf[v10];
    v13 = &in_pInputBuf[v10];
    if ( v12 > in_uMaxPacketSize )
    {
      in_pTremorInfo->ReturnInfo.uFramesProduced = 0;
      in_pTremorInfo->ReturnInfo.eDecoderStatus = AK_Fail;
      return;
    }
    if ( in_pTremorInfo->ReturnInfo.eDecoderState != 4
      && v12 + (unsigned __int64)(unsigned int)v10 + 2 <= uInputDataSize )
    {
      v10 = (unsigned int)v12 + (_DWORD)v10 + 2;
      op.buffer.data = v13 + 2;
      op.buffer.size = v12;
      if ( (_DWORD)v10 == (_DWORD)uInputDataSize && in_pTremorInfo->bNoMoreInputPackets )
      {
        op.e_o_s = 1;
        in_pTremorInfo->ReturnInfo.eDecoderState = 4;
        vorbis_dsp_synthesis(&in_pTremorInfo->VorbisDSPState, &op);
      }
      else
      {
        op.e_o_s = 0;
        vorbis_dsp_synthesis(&in_pTremorInfo->VorbisDSPState, &op);
      }
      goto LABEL_12;
    }
  }
LABEL_13:
  v14 = in_pTremorInfo->uRequestedFrames;
  in_pTremorInfo->ReturnInfo.uInputBytesConsumed = v10;
  v15 = in_pTremorInfo->ReturnInfo.eDecoderState == 4;
  in_pTremorInfo->ReturnInfo.uFramesProduced = v14 - uRequestedFrames;
  if ( !v15 || (unsigned int)vorbis_dsp_pcmout(&in_pTremorInfo->VorbisDSPState, 0i64, 0) )
    in_pTremorInfo->ReturnInfo.eDecoderStatus = 46 - (in_pTremorInfo->ReturnInfo.uFramesProduced != 0);
  else
    in_pTremorInfo->ReturnInfo.eDecoderStatus = AK_NoMoreData;
}

