// File Line: 128
// RVA: 0x118220
AString *__fastcall ANamed::get_name_str_dbg(ANamed *this, AString *result)
{
  AString *v2; // rbx

  v2 = result;
  ASymbol::as_str_dbg(&this->i_name, result);
  return v2;
}

