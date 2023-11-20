// File Line: 103
// RVA: 0xC30C10
_BOOL8 __fastcall hkpShapeCollection::isWeldingEnabled(hkpShapeCollection *this)
{
  return LOBYTE(this->m_memSizeAndFlags) == 0;
}

