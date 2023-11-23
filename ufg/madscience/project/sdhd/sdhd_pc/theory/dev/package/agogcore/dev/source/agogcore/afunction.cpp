// File Line: 26
// RVA: 0x224520
UFG::allocator::free_link *__fastcall AFunction::copy_new(AFunction *this)
{
  UFG::allocator::free_link *v2; // rbx
  bool v3; // di
  AErrorOutputBase *v4; // rax
  bool v5; // si
  const char *v6; // r9
  const char *v7; // r8
  const char *v8; // rcx
  unsigned int v9; // edi
  AMD_HD3D *v10; // rcx
  __int64 v12; // [rsp+48h] [rbp-38h] BYREF
  const char *v13; // [rsp+50h] [rbp-30h]
  const char *v14; // [rsp+58h] [rbp-28h]
  int v15; // [rsp+60h] [rbp-20h]
  int v16; // [rsp+64h] [rbp-1Ch]
  const char *v17; // [rsp+68h] [rbp-18h]
  const char *v18; // [rsp+70h] [rbp-10h]
  int v19; // [rsp+78h] [rbp-8h]
  AMD_HD3D *v20; // [rsp+98h] [rbp+18h] BYREF

  v2 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
  v20 = (AMD_HD3D *)v2;
  if ( v2 )
  {
    v2->mNext = (UFG::allocator::free_link *)&AFunctionBase::`vftable;
    v2->mNext = (UFG::allocator::free_link *)&AFunction::`vftable;
    v2[1].mNext = (UFG::allocator::free_link *)this->i_function_f;
  }
  else
  {
    v2 = 0i64;
  }
  if ( test && !v2 )
  {
    v12 = 0i64;
    v13 = "Unable to allocate memory";
    v14 = "Test failed: func_obj_p != 0";
    v15 = 3;
    v16 = 3;
    v17 = "class AFunctionBase *__cdecl AFunction::copy_new(void) const";
    v18 = "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\agogcore\\dev\\source\\agogcore\\afunction.cpp";
    v19 = 26;
    v3 = std::uncaught_exception();
    v4 = Agog::on_error_pre(v3);
    if ( !v4 || v3 )
    {
      if ( std::uncaught_exception() )
      {
        LODWORD(v20) = 3;
        ADebug::print("### Had another exception while a previous exception is being handled: ###", 1);
      }
      else
      {
        LODWORD(v20) = 0;
      }
      v6 = &customCaption;
      v7 = "An error has occurred.";
      if ( v13 )
        v7 = v13;
      v8 = &customCaption;
      if ( v14 )
        v8 = v14;
      if ( v17 )
        v6 = v17;
      if ( v18 )
        ADebug::print_format(
          "\n%s : %s\n\n  Internal Info:\n    %s\n    %s(%u) : %s\n    Exception Id: %u\n",
          &customCaption,
          v7,
          v6,
          v18,
          v19,
          v8,
          v16);
      else
        ADebug::print_format(
          "\n%s : %s\n\n  Internal Info:\n    %s\n    %s\n    Exception Id: %u\n",
          &customCaption,
          v7,
          v6,
          v8,
          v16);
      ADebug::info();
      v5 = 0;
    }
    else
    {
      v5 = v4->vfptr->determine_choice(v4, (AErrMsg *)&v12, (eAErrAction *)&v20);
    }
    v9 = (unsigned int)v20;
    if ( (_DWORD)v20 == 4 )
    {
      test = 0;
      v9 = 3;
      LODWORD(v20) = 3;
    }
    _((AMD_HD3D *)v9);
    if ( !(_DWORD)v20 )
      _(v10);
    if ( v5 )
      __debugbreak();
    if ( v9 != 3 )
      __debugbreak();
  }
  return v2;
}

// File Line: 40
// RVA: 0x226230
void __fastcall AFunction::invoke(AFunction *this)
{
  void (*i_function_f)(void); // rax

  i_function_f = this->i_function_f;
  if ( i_function_f )
    i_function_f();
}

