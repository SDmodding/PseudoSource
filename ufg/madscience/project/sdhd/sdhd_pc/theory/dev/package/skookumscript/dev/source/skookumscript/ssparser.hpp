// File Line: 701
// RVA: 0x13C970
AString *__fastcall SSParser::string_to_esacpe_string(AString *result, AString *str, bool break_newlines)
{
  bool v3; // bl
  AString *v4; // rdi
  AString *v5; // rsi
  AStringRef *v6; // rax

  v3 = break_newlines;
  v4 = str;
  v5 = result;
  v6 = AStringRef::get_empty();
  v5->i_str_ref_p = v6;
  ++v6->i_ref_count;
  SSParser::string_to_esacpe_string(v4, v5, v3);
  return v5;
}

