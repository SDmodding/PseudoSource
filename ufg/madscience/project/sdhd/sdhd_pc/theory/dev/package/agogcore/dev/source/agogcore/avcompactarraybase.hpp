// File Line: 455
// RVA: 0x113C90
void __fastcall AVCompactArrayBase<ASymbol>::empty_ensure_count_undef(
        AVCompactArrayBase<ASymbol> *this,
        unsigned int count)
{
  ASymbol *v4; // rax
  ASymbol *v5; // rax

  if ( this->i_count )
  {
    if ( this->i_count != count )
    {
      AMemory::c_free_func(this->i_array_p);
      v5 = AVCompactArrayBase<ASymbol>::alloc_array(count);
      this->i_count = 0;
      this->i_array_p = v5;
      return;
    }
  }
  else if ( count )
  {
    v4 = AVCompactArrayBase<ASymbol>::alloc_array(count);
    this->i_count = 0;
    this->i_array_p = v4;
    return;
  }
  this->i_count = 0;
}

// File Line: 501
// RVA: 0x11C5D0
void __fastcall AVCompactArrayBase<ASymbol>::insert(AVCompactArrayBase<ASymbol> *this, ASymbol *elem, unsigned int pos)
{
  __int64 v3; // rbx
  unsigned int i_count; // esi
  unsigned int v7; // ebp
  ASymbol *v8; // rax
  ASymbol *v9; // r14
  ASymbol *i_array_p; // r15
  unsigned int v11; // esi
  ASymbol *v12; // rcx

  v3 = pos;
  i_count = this->i_count;
  v7 = this->i_count + 1;
  v8 = AVCompactArrayBase<ASymbol>::alloc_array(v7);
  v9 = v8;
  if ( i_count )
  {
    i_array_p = this->i_array_p;
    if ( (_DWORD)v3 )
      memmove(v8, this->i_array_p, 4i64 * (unsigned int)v3);
    v11 = i_count - v3;
    if ( v11 )
      memmove(&v9[v3 + 1], &i_array_p[v3], 4i64 * v11);
    AMemory::c_free_func(i_array_p);
  }
  this->i_count = v7;
  this->i_array_p = v9;
  v12 = &v9[v3];
  if ( v12 )
    v12->i_uid = elem->i_uid;
}

// File Line: 902
// RVA: 0x10B580
ASymbol *__fastcall AVCompactArrayBase<ASymbol>::alloc_array(unsigned int count)
{
  ASymbol *result; // rax
  ASymbol *v3; // rbx
  AErrMsg *v4; // rax
  AErrMsg err_msg; // [rsp+40h] [rbp-78h] BYREF
  AErrMsg v6; // [rsp+78h] [rbp-40h] BYREF
  eAErrAction action_p; // [rsp+C0h] [rbp+8h] BYREF

  result = (ASymbol *)AMemory::c_malloc_func(4i64 * count, "AVCompactArray");
  v3 = result;
  if ( `AVCompactArrayBase<ASymbol>::alloc_array::`3::_test && count && !result )
  {
    AErrMsg::AErrMsg(&err_msg, "Unable to allocate memory", AErrLevel_error, 0i64, 0i64);
    AErrMsg::AErrMsg(
      &v6,
      &err_msg,
      "Test failed: !count || (buffer_p != 0)",
      "class ASymbol *__cdecl AVCompactArrayBase<class ASymbol>::alloc_array(unsigned int)",
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\agogcore\\dev\\source\\agogcore\\avcompactarraybase.hpp",
      0x38Au,
      3u);
    if ( ADebug::resolve_error(v4, &action_p, &`AVCompactArrayBase<ASymbol>::alloc_array::`3::_test) )
      __debugbreak();
    if ( action_p != AErrAction_ignore )
      __debugbreak();
    return v3;
  }
  return result;
}

