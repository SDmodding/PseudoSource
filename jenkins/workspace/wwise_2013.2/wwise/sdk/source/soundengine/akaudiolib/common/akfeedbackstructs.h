// File Line: 60
// RVA: 0xA8FC60
void __fastcall AkFeedbackParams::CopyVolumes(AkFeedbackParams *this, unsigned int in_iPlayer, AkAudioMix *out_pMix)
{
  AkFeedbackParams *v3; // r9
  unsigned int v4; // er10
  unsigned int v5; // edx
  __int64 v6; // rcx
  __int64 v7; // rax
  signed __int64 v8; // rcx

  v3 = this;
  v4 = in_iPlayer * (*((_WORD *)this + 27) & 0xF);
  v5 = 0;
  if ( *((_WORD *)this + 27) & 0xF )
  {
    do
    {
      v6 = v5 + v4;
      v7 = v5++;
      v7 <<= 6;
      v8 = (v6 + 1) << 6;
      *(__m128 *)((char *)out_pMix->Next.vector + v7) = *(__m128 *)((char *)&v3->m_pOutput + v8);
      *(_OWORD *)((char *)&out_pMix->Next.aVolumes[4] + v7) = *(_OWORD *)((char *)&v3->m_LPF + v8);
      *(__m128 *)((char *)out_pMix->Previous.vector + v7) = *(__m128 *)((char *)v3->m_fNextAttenuation + v8);
      *(_OWORD *)((char *)&out_pMix->Previous.aVolumes[4] + v7) = *(_OWORD *)((char *)&v3->m_usCompanyID + v8);
    }
    while ( v5 < (*((_WORD *)v3 + 27) & 0xFu) );
  }
}

