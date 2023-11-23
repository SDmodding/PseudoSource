// File Line: 701
// RVA: 0x13C970
AString *__fastcall SSParser::string_to_esacpe_string(AString *result, AString *str, bool break_newlines)
{
  AStringRef *empty; // rax

  empty = AStringRef::get_empty();
  result->i_str_ref_p = empty;
  ++empty->i_ref_count;
  SSParser::string_to_esacpe_string(str, result, break_newlines);
  return result;
}

