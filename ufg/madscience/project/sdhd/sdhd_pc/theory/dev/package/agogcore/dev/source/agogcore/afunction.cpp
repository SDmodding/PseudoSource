// File Line: 26
// RVA: 0x224520
UFG::allocator::free_link *__fastcall AFunction::copy_new(AFunction *this)
{
  AFunction *v1; // rdi
  UFG::allocator::free_link *v2; // rbx
  bool v3; // al
  bool v4; // di
  AErrorOutputBase *v5; // rax
  bool v6; // si
  bool v7; // al
  char *v8; // rdx
  const char *v9; // r8
  unsigned int v10; // edi
  AMD_HD3D *v11; // rcx
  char *v13; // [rsp+48h] [rbp-38h]
  const char *v14; // [rsp+50h] [rbp-30h]
  const char *v15; // [rsp+58h] [rbp-28h]
  int v16; // [rsp+60h] [rbp-20h]
  int v17; // [rsp+64h] [rbp-1Ch]
  const char *v18; // [rsp+68h] [rbp-18h]
  const char *v19; // [rsp+70h] [rbp-10h]
  int v20; // [rsp+78h] [rbp-8h]
  AMD_HD3D *v21; // [rsp+98h] [rbp+18h]

  v1 = this;
  v2 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
  v21 = (AMD_HD3D *)v2;
  if ( v2 )
  {
    v2->mNext = (UFG::allocator::free_link *)&AFunctionBase::`vftable;
    v2->mNext = (UFG::allocator::free_link *)&AFunction::`vftable;
    v2[1].mNext = (UFG::allocator::free_link *)v1->i_function_f;
  }
  else
  {
    v2 = 0i64;
  }
  if ( test && !v2 )
  {
    v13 = 0i64;
    v14 = "Unable to allocate memory";
    v15 = "Test failed: func_obj_p != 0";
    v16 = 3;
    v17 = 3;
    v18 = "class AFunctionBase *__cdecl AFunction::copy_new(void) const";
    v19 = "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\agogcore\\dev\\source\\agogcore\\afunction.cpp";
    v20 = 26;
    v3 = std::uncaught_exception();
    v4 = v3;
    v5 = Agog::on_error_pre(v3);
    if ( !v5 || v4 )
    {
      v7 = std::uncaught_exception();
      if ( v7 || v16 <= 1 )
      {
        LODWORD(v21) = 3;
        if ( v7 )
          ADebug::print("### Had another exception while a previous exception is being handled: ###", 1);
      }
      else
      {
        LODWORD(v21) = 0;
      }
      v8 = &customWorldMapCaption;
      if ( v13 )
        v8 = v13;
      v9 = "An error has occurred.";
      if ( v14 )
        v9 = v14;
      if ( v19 )
        ADebug::print_format("\n%s : %s\n\n  Internal Info:\n    %s\n    %s(%u) : %s\n    Exception Id: %u\n", v8, v9);
      else
        ADebug::print_format("\n%s : %s\n\n  Internal Info:\n    %s\n    %s\n    Exception Id: %u\n", v8, v9);
      ADebug::info();
      v6 = 0;
    }
    else
    {
      v6 = v5->vfptr->determine_choice(v5, (AErrMsg *)&v13, (eAErrAction *)&v21);
    }
    v10 = (unsigned int)v21;
    if ( (_DWORD)v21 == 4 )
    {
      test = 0;
      v10 = 3;
      LODWORD(v21) = 3;
    }
    _((AMD_HD3D *)v10);
    if ( !(_DWORD)v21 )
      _(v11);
    if ( v6 )
      __debugbreak();
    if ( v10 != 3 )
      __debugbreak();
  }
  return v2;
}

// File Line: 40
// RVA: 0x226230
void __fastcall AFunction::invoke(AFunction *this)
{
  void (*v1)(void); // rax

  v1 = (void (*)(void))this->i_function_f;
  if ( v1 )
    v1();
}

