// File Line: 39
// RVA: 0x15ADEE0
void UFG::_dynamic_initializer_for__gMathInitPlat__()
{
  UFG::gVmxConstI_Min_sb = _mm_load_si128((const __m128i *)&_xmm);
  UFG::gVmxConstI_Min_sh = _mm_load_si128((const __m128i *)&`hkIntVector::setConvertSaturateS32ToU16::`2::offset2);
  UFG::gVmxConstI_Min_sw = _mm_load_si128((const __m128i *)_xmm);
  UFG::gVmxPlat_32768_sw = _mm_load_si128((const __m128i *)&_xmm);
  UFG::gVmxPlat_32768_sh = UFG::gVmxConstI_Min_sh;
}

