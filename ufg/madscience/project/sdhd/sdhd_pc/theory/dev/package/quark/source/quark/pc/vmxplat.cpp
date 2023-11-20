// File Line: 39
// RVA: 0x15ADEE0
void UFG::_dynamic_initializer_for__gMathInitPlat__()
{
  __m128i v0; // xmm2

  v0 = _mm_load_si128((const __m128i *)&`hkIntVector::setConvertSaturateS32ToU16::`2::offset2);
  _mm_store_si128(&UFG::gVmxConstI_Min_sb, _mm_load_si128((const __m128i *)&_xmm));
  _mm_store_si128(&UFG::gVmxConstI_Min_sh, v0);
  _mm_store_si128(&UFG::gVmxConstI_Min_sw, _mm_load_si128((const __m128i *)_xmm));
  _mm_store_si128(&UFG::gVmxPlat_32768_sw, _mm_load_si128((const __m128i *)&_xmm));
  _mm_store_si128(&UFG::gVmxPlat_32768_sh, v0);
}

