// File Line: 917
// RVA: 0xBB350
AStringRef **__fastcall APArrayBase<AStringRef>::alloc_array(unsigned int needed)
{
  AStringRef **result; // rax
  AStringRef **v3; // rbx
  AErrMsg *v4; // rax
  AErrMsg err_msg; // [rsp+40h] [rbp-78h] BYREF
  AErrMsg v6; // [rsp+78h] [rbp-40h] BYREF
  eAErrAction action_p; // [rsp+C0h] [rbp+8h] BYREF

  result = (AStringRef **)AMemory::c_malloc_func(8i64 * needed, "APArrayBase.buffer");
  v3 = result;
  if ( `APArrayBase<AStringRef>::alloc_array::`3::_test && needed && !result )
  {
    AErrMsg::AErrMsg(&err_msg, "Unable to allocate memory", AErrLevel_error, 0i64, 0i64);
    AErrMsg::AErrMsg(
      &v6,
      &err_msg,
      "Test failed: !needed || (buffer_p != 0)",
      "struct AStringRef **__cdecl APArrayBase<struct AStringRef>::alloc_array(unsigned int)",
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\agogcore\\dev\\source\\agogcore\\aparraybase.hpp",
      0x398u,
      3u);
    if ( ADebug::resolve_error(v4, &action_p, &`APArrayBase<AStringRef>::alloc_array::`3::_test) )
      __debugbreak();
    if ( action_p != AErrAction_ignore )
      __debugbreak();
    return v3;
  }
  return result;
}

