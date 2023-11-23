// File Line: 97
// RVA: 0xD0C50
void __fastcall ADatum::~ADatum(ADatum *this)
{
  ADatum::Reference *i_dref_p; // rbx

  i_dref_p = this->i_dref_p;
  if ( this->i_dref_p->i_references-- == 1 )
  {
    if ( i_dref_p->i_deallocate )
      operator delete[](i_dref_p->i_buffer_p);
    operator delete[](i_dref_p);
  }
}

// File Line: 455
// RVA: 0x223CC0
UFG::allocator::free_link *__fastcall ADatum::alloc_buffer(unsigned int data_length)
{
  UFG::allocator::free_link *result; // rax
  char *v2; // rdi
  bool v3; // si
  bool v4; // bl
  AErrorOutputBase *v5; // rax
  const char *v6; // r9
  const char *v7; // rcx
  const char *v8; // r8
  unsigned int v9; // ebx
  AMD_HD3D *v10; // rcx
  __int64 v11; // [rsp+40h] [rbp-40h] BYREF
  const char *v12; // [rsp+48h] [rbp-38h]
  const char *v13; // [rsp+50h] [rbp-30h]
  int v14; // [rsp+58h] [rbp-28h]
  int v15; // [rsp+5Ch] [rbp-24h]
  const char *v16; // [rsp+60h] [rbp-20h]
  const char *v17; // [rsp+68h] [rbp-18h]
  int v18; // [rsp+70h] [rbp-10h]
  AMD_HD3D *v19; // [rsp+90h] [rbp+10h] BYREF

  result = UFG::qMalloc(data_length, "ADatum::alloc_buffer", 0i64);
  v2 = (char *)result;
  if ( `ADatum::alloc_buffer::`3::_test && !result )
  {
    v12 = "Unable to allocate memory";
    v3 = 0;
    v13 = "Test failed: buffer_p != 0";
    v14 = 3;
    v16 = "unsigned char *__cdecl ADatum::alloc_buffer(unsigned int)";
    v11 = 0i64;
    v15 = 3;
    v18 = 459;
    v17 = "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\agogcore\\dev\\source\\agogcore\\adatum.inl";
    v4 = std::uncaught_exception();
    v5 = Agog::on_error_pre(v4);
    if ( !v5 || v4 )
    {
      if ( std::uncaught_exception() )
      {
        LODWORD(v19) = 3;
        ADebug::print("### Had another exception while a previous exception is being handled: ###", 1);
      }
      else
      {
        LODWORD(v19) = 0;
      }
      v6 = &customCaption;
      v7 = &customCaption;
      v8 = "An error has occurred.";
      if ( v12 )
        v8 = v12;
      if ( v13 )
        v7 = v13;
      if ( v16 )
        v6 = v16;
      if ( v17 )
        ADebug::print_format(
          "\n%s : %s\n\n  Internal Info:\n    %s\n    %s(%u) : %s\n    Exception Id: %u\n",
          &customCaption,
          v8,
          v6,
          v17,
          v18,
          v7,
          v15);
      else
        ADebug::print_format(
          "\n%s : %s\n\n  Internal Info:\n    %s\n    %s\n    Exception Id: %u\n",
          &customCaption,
          v8,
          v6,
          v7,
          v15);
      ADebug::info();
    }
    else
    {
      v3 = v5->vfptr->determine_choice(v5, (AErrMsg *)&v11, (eAErrAction *)&v19);
    }
    v9 = (unsigned int)v19;
    if ( (_DWORD)v19 == 4 )
    {
      v9 = 3;
      `ADatum::alloc_buffer::`3::_test = 0;
      LODWORD(v19) = 3;
    }
    _((AMD_HD3D *)v9);
    if ( !(_DWORD)v19 )
      _(v10);
    if ( v3 )
      __debugbreak();
    if ( v9 != 3 )
      __debugbreak();
    return (UFG::allocator::free_link *)v2;
  }
  return result;
}

