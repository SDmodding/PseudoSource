// File Line: 178
// RVA: 0x224320
AString *__fastcall ASymbol::as_str_dbg(ASymbol *this, AString *result)
{
  char *v3; // rax
  const char *v4; // rdi
  __int64 v5; // rbx
  unsigned int v6; // eax

  v3 = UFG::qSymbolRegistry::Get(this->i_uid);
  v4 = v3;
  v5 = -1i64;
  do
    ++v5;
  while ( v3[v5] );
  v6 = AMemory::c_req_byte_size_func(v5 + 1);
  result->i_str_ref_p = AStringRef::pool_new(v4, v5, v6, 1u, 0, 1);
  return result;
}

// File Line: 191
// RVA: 0x224310
char *__fastcall UFG::qSymbol::as_cstr_dbg(UFG::qSymbolUC *this)
{
  return UFG::qSymbolRegistry::Get(this->mUID);
}

// File Line: 211
// RVA: 0x224780
ASymbol *__fastcall ASymbol::create(ASymbol *result, AString *str, eATerm term)
{
  result->i_uid = UFG::qSymbolUIDFromStringN(str->i_str_ref_p->i_cstr_p, str->i_str_ref_p->i_length, 0xFFFFFFFF);
  return result;
}

// File Line: 249
// RVA: 0x2247B0
ASymbol *__fastcall ASymbol::create(ASymbol *result, const char *cstr_p, unsigned int length, eATerm term)
{
  __int64 v4; // rax

  LODWORD(v4) = length;
  if ( length && cstr_p && *cstr_p )
  {
    if ( length == -1 )
    {
      v4 = -1i64;
      do
        ++v4;
      while ( cstr_p[v4] );
    }
    result->i_uid = UFG::qSymbolUIDFromStringN(cstr_p, v4, 0xFFFFFFFF);
    return result;
  }
  else
  {
    result->i_uid = ASymbol::c_null.i_uid;
    return result;
  }
}

// File Line: 284
// RVA: 0x224840
ASymbol *__fastcall ASymbol::create_from_binary(ASymbol *result, unsigned int **sym_binary_pp)
{
  unsigned int v2; // r8d
  ASymbol *v3; // rax

  v2 = *(*sym_binary_pp)++;
  v3 = result;
  result->i_uid = v2;
  return v3;
}

// File Line: 318
// RVA: 0x224810
ASymbol *__fastcall ASymbol::create_add(ASymbol *this, ASymbol *result, AString *suffix)
{
  result->i_uid = UFG::qSymbolUIDFromStringN(suffix->i_str_ref_p->i_cstr_p, suffix->i_str_ref_p->i_length, this->i_uid);
  return result;
}

// File Line: 365
// RVA: 0x225280
ASymbol *__fastcall ASymbol::get_null()
{
  if ( (_S5_6 & 1) == 0 )
  {
    _S5_6 |= 1u;
    s_null_sym.i_uid = -1;
    atexit(ASymbol::get_null_::_2_::_dynamic_atexit_destructor_for__s_null_sym__);
  }
  return &s_null_sym;
}

