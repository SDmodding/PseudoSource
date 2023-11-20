// File Line: 49
// RVA: 0xD06BB0
__int64 __fastcall add1SaturateAndSetLowBit(unsigned int x)
{
  if ( x != 0xFFFF )
    ++x;
  return x | 1;
}

// File Line: 99
// RVA: 0xD071F0
void __fastcall hkp3AxisSweep::getOffsetLowHigh32bit(hkp3AxisSweep *this, hkVector4f *offsetLow32bit, hkVector4f *offsetHigh32bit)
{
  *offsetLow32bit = this->m_offsetLow32bit;
  *offsetHigh32bit = this->m_offsetHigh32bit;
}

