// File Line: 45
// RVA: 0xA52160
AkVPL *__fastcall AkVPL::GetHdrBus(AkVPL *this)
{
  if ( *((_BYTE *)this + 1376) & 2 )
    return this;
  while ( 1 )
  {
    this = this->m_MixBus.m_pParent;
    if ( !this )
      break;
    if ( *((_BYTE *)this + 1376) & 2 )
      return this;
  }
  return 0i64;
}

