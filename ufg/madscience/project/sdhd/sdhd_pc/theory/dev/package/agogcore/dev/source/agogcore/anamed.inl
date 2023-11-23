// File Line: 128
// RVA: 0x118220
AString *__fastcall ANamed::get_name_str_dbg(ANamed *this, AString *result)
{
  ASymbol::as_str_dbg(&this->i_name, result);
  return result;
}

