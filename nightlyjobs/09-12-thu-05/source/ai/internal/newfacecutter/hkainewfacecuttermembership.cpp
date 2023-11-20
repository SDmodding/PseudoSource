// File Line: 15
// RVA: 0x12FAF60
char __fastcall hkaiNewFaceCutterUtil::Membership::getEffectivePainterIndex(hkaiNewFaceCutterUtil::Membership *this)
{
  unsigned int v1; // eax
  char i; // cl

  v1 = (this->m_data >> 1) & 0x7FFF;
  if ( !v1 )
    return -1;
  for ( i = 0; !(v1 & 1); ++i )
    v1 >>= 1;
  return i;
}

