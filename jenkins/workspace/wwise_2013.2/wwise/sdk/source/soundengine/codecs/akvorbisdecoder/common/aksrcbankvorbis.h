// File Line: 61
// RVA: 0xABAF90
void __fastcall CAkSrcBankVorbis::VorbisDSPRestart(CAkSrcBankVorbis *this, unsigned __int16 in_uSrcOffsetRemainder)
{
  unsigned __int16 uLastGranuleExtra; // r8

  if ( this->m_uLoopCnt == 1 )
    uLastGranuleExtra = this->m_VorbisState.VorbisInfo.uLastGranuleExtra;
  else
    uLastGranuleExtra = this->m_VorbisState.VorbisInfo.LoopInfo.uLoopEndExtra;
  vorbis_dsp_restart(&this->m_VorbisState.TremorInfo.VorbisDSPState, in_uSrcOffsetRemainder, uLastGranuleExtra);
  this->m_VorbisState.TremorInfo.ReturnInfo.eDecoderState = 3;
}

