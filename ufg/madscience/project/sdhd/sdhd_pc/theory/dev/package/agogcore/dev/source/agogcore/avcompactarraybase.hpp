// File Line: 455
// RVA: 0x113C90
void __fastcall AVCompactArrayBase<ASymbol>::empty_ensure_count_undef(AVCompactArrayBase<ASymbol> *this, unsigned int count)
{
  unsigned int v2; // edi
  AVCompactArrayBase<ASymbol> *v3; // rbx
  ASymbol *v4; // rax
  ASymbol *v5; // rax

  v2 = count;
  v3 = this;
  if ( this->i_count )
  {
    if ( this->i_count != count )
    {
      AMemory::c_free_func(this->i_array_p);
      v5 = AVCompactArrayBase<ASymbol>::alloc_array(v2);
      v3->i_count = 0;
      v3->i_array_p = v5;
      return;
    }
  }
  else if ( count )
  {
    v4 = AVCompactArrayBase<ASymbol>::alloc_array(count);
    v3->i_count = 0;
    v3->i_array_p = v4;
    return;
  }
  this->i_count = 0;
}

// File Line: 501
// RVA: 0x11C5D0
void __fastcall AVCompactArrayBase<ASymbol>::insert(AVCompactArrayBase<ASymbol> *this, ASymbol *elem, unsigned int pos)
{
  __int64 v3; // rbx
  ASymbol *v4; // r12
  AVCompactArrayBase<ASymbol> *v5; // rdi
  unsigned int v6; // esi
  unsigned int v7; // ebp
  ASymbol *v8; // rax
  ASymbol *v9; // r14
  ASymbol *v10; // r15
  unsigned int v11; // esi
  unsigned int *v12; // rcx

  v3 = pos;
  v4 = elem;
  v5 = this;
  v6 = this->i_count;
  v7 = this->i_count + 1;
  v8 = AVCompactArrayBase<ASymbol>::alloc_array(v7);
  v9 = v8;
  if ( v6 )
  {
    v10 = v5->i_array_p;
    if ( (_DWORD)v3 )
      memmove(v8, v5->i_array_p, 4i64 * (unsigned int)v3);
    v11 = v6 - v3;
    if ( v11 )
      memmove(&v9[v3 + 1], &v10[v3], 4i64 * v11);
    AMemory::c_free_func(v10);
  }
  v5->i_count = v7;
  v5->i_array_p = v9;
  v12 = &v9[v3].i_uid;
  if ( v12 )
    *v12 = v4->i_uid;
}

// File Line: 902
// RVA: 0x10B580
ASymbol *__fastcall AVCompactArrayBase<ASymbol>::alloc_array(unsigned int count)
{
  unsigned int v1; // edi
  ASymbol *result; // rax
  ASymbol *v3; // rbx
  AErrMsg *v4; // rax
  AErrMsg err_msg; // [rsp+40h] [rbp-78h]
  AErrMsg v6; // [rsp+78h] [rbp-40h]
  eAErrAction action_p; // [rsp+C0h] [rbp+8h]

  v1 = count;
  result = (ASymbol *)AMemory::c_malloc_func(4i64 * count, "AVCompactArray");
  v3 = result;
  if ( `AVCompactArrayBase<ASymbol>::alloc_array::`3::_test && v1 && !result )
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
    if ( action_p != 3 )
      __debugbreak();
    result = v3;
  }
  return result;
}

