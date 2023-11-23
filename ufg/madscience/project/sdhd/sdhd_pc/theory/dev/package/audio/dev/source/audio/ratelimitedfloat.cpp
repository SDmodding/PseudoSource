// File Line: 10
// RVA: 0x1465500
__int64 UFG::_dynamic_initializer_for__RlfSym_min___1()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("min", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RlfSym_min_1, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RlfSym_min___1);
}

// File Line: 11
// RVA: 0x14654C0
__int64 UFG::_dynamic_initializer_for__RlfSym_max___1()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("max", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RlfSym_max_1, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RlfSym_max___1);
}

// File Line: 12
// RVA: 0x1465540
__int64 UFG::_dynamic_initializer_for__RlfSym_rise_rate___1()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("rise_rate", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RlfSym_rise_rate_1, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RlfSym_rise_rate___1);
}

// File Line: 13
// RVA: 0x1465480
__int64 UFG::_dynamic_initializer_for__RlfSym_fall_rate___1()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("fall_rate", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&RlfSym_fall_rate_1, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__RlfSym_fall_rate___1);
}

// File Line: 21
// RVA: 0x14BFB0
void __fastcall UFG::RateLimitedFloat::SetMinMax(UFG::RateLimitedFloat *this, float min, float max)
{
  float v3; // xmm0_4

  if ( min >= max )
    v3 = max;
  else
    v3 = min;
  this->m_min = v3;
  if ( min <= max )
    this->m_max = max;
  else
    this->m_max = min;
}

