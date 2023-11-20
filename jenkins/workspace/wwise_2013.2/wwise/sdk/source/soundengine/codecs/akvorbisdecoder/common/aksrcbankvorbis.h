// File Line: 61
// RVA: 0xABAF90
void __fastcall CAkSrcBankVorbis::VorbisDSPRestart(CAkSrcBankVorbis *this, unsigned __int16 in_uSrcOffsetRemainder)
{
  CAkSrcBankVorbis *v2; // rbx
  unsigned __int16 v3; // r8

  v2 = this;
  if ( this->m_uLoopCnt == 1 )
    v3 = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  else
    v3 = this->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
  vorbis_dsp_restart(&this->m_VorbisState.TremorInfo.VorbisDSPState, in_uSrcOffsetRemainder, v3);
  v2->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
}

