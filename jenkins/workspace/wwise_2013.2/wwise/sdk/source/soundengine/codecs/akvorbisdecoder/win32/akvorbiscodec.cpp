// File Line: 20
// RVA: 0xABC670
void __fastcall DecodeVorbis(AkTremorInfo *in_pTremorInfo, unsigned __int16 in_uMaxPacketSize, char *in_pInputBuf, __int16 *in_pOuputBuf)
{
  unsigned __int64 v4; // r15
  int v5; // edi
  __int16 *v6; // r14
  char *v7; // r12
  unsigned __int16 v8; // r13
  AkTremorInfo *v9; // rbx
  __int64 v10; // rsi
  int v11; // ecx
  unsigned __int16 v12; // dx
  char *v13; // r9
  unsigned int v14; // eax
  bool v15; // zf
  ogg_packet op; // [rsp+20h] [rbp-48h]

  v4 = in_pTremorInfo->uInputDataSize;
  v5 = in_pTremorInfo->uRequestedFrames;
  v6 = in_pOuputBuf;
  v7 = in_pInputBuf;
  v8 = in_uMaxPacketSize;
  v9 = in_pTremorInfo;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = vorbis_dsp_pcmout(&v9->VorbisDSPState, v6, v5);
    if ( !v11 )
      break;
    v5 -= v11;
    v6 += (unsigned int)(v11 * v9->VorbisDSPState.channels);
LABEL_12:
    if ( !v5 )
      goto LABEL_13;
  }
  if ( v10 + 2 <= v4 )
  {
    v12 = *(_WORD *)&v7[v10];
    v13 = &v7[v10];
    if ( v12 > v8 )
    {
      v9->ReturnInfo.uFramesProduced = 0;
      v9->ReturnInfo.eDecoderStatus = 2;
      return;
    }
    if ( v9->ReturnInfo.eDecoderState != 4 && v12 + (unsigned __int64)(unsigned int)v10 + 2 <= v4 )
    {
      v10 = (unsigned int)v12 + (_DWORD)v10 + 2;
      op.buffer.data = v13 + 2;
      op.buffer.size = v12;
      if ( (_DWORD)v10 == (_DWORD)v4 && v9->bNoMoreInputPackets )
      {
        op.e_o_s = 1;
        v9->ReturnInfo.eDecoderState = 4;
        vorbis_dsp_synthesis(&v9->VorbisDSPState, &op);
      }
      else
      {
        op.e_o_s = 0;
        vorbis_dsp_synthesis(&v9->VorbisDSPState, &op);
      }
      goto LABEL_12;
    }
  }
LABEL_13:
  v14 = v9->uRequestedFrames;
  v9->ReturnInfo.uInputBytesConsumed = v10;
  v15 = v9->ReturnInfo.eDecoderState == 4;
  v9->ReturnInfo.uFramesProduced = v14 - v5;
  if ( !v15 || (unsigned int)vorbis_dsp_pcmout(&v9->VorbisDSPState, 0i64, 0) )
    v9->ReturnInfo.eDecoderStatus = 46 - (v9->ReturnInfo.uFramesProduced != 0);
  else
    v9->ReturnInfo.eDecoderStatus = 17;
}

