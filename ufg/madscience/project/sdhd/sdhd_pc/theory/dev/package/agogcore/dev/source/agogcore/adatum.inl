// File Line: 97
// RVA: 0xD0C50
void __fastcall ADatum::~ADatum(ADatum *this)
{
  ADatum::Reference *v1; // rbx
  bool v2; // zf

  v1 = this->i_dref_p;
  v2 = this->i_dref_p->i_references == 1;
  --v1->i_references;
  if ( v2 )
  {
    if ( v1->i_deallocate )
      operator delete[](v1->i_buffer_p);
    operator delete[](v1);
  }
}

// File Line: 455
// RVA: 0x223CC0
UFG::allocator::free_link *__fastcall ADatum::alloc_buffer(unsigned int data_length)
{
  UFG::allocator::free_link *result; // rax
  char *v2; // rdi
  bool v3; // si
  bool v4; // al
  bool v5; // bl
  AErrorOutputBase *v6; // rax
  bool v7; // al
  char *v8; // rdx
  const char *v9; // r8
  unsigned int v10; // ebx
  AMD_HD3D *v11; // rcx
  char *v12; // [rsp+40h] [rbp-40h]
  const char *v13; // [rsp+48h] [rbp-38h]
  const char *v14; // [rsp+50h] [rbp-30h]
  int v15; // [rsp+58h] [rbp-28h]
  int v16; // [rsp+5Ch] [rbp-24h]
  const char *v17; // [rsp+60h] [rbp-20h]
  const char *v18; // [rsp+68h] [rbp-18h]
  int v19; // [rsp+70h] [rbp-10h]
  AMD_HD3D *v20; // [rsp+90h] [rbp+10h]

  result = UFG::qMalloc(data_length, "ADatum::alloc_buffer", 0i64);
  v2 = (char *)result;
  if ( `ADatum::alloc_buffer::`3::_test && !result )
  {
    v13 = "Unable to allocate memory";
    v3 = 0;
    v14 = "Test failed: buffer_p != 0";
    v15 = 3;
    v17 = "unsigned char *__cdecl ADatum::alloc_buffer(unsigned int)";
    v12 = 0i64;
    v16 = 3;
    v19 = 459;
    v18 = "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\agogcore\\dev\\source\\agogcore\\adatum.inl";
    v4 = std::uncaught_exception();
    v5 = v4;
    v6 = Agog::on_error_pre(v4);
    if ( !v6 || v5 )
    {
      v7 = std::uncaught_exception();
      if ( v7 || v15 <= 1 )
      {
        LODWORD(v20) = 3;
        if ( v7 )
          ADebug::print("### Had another exception while a previous exception is being handled: ###", 1);
      }
      else
      {
        LODWORD(v20) = 0;
      }
      v8 = &customWorldMapCaption;
      if ( v12 )
        v8 = v12;
      v9 = "An error has occurred.";
      if ( v13 )
        v9 = v13;
      if ( v18 )
        ADebug::print_format("\n%s : %s\n\n  Internal Info:\n    %s\n    %s(%u) : %s\n    Exception Id: %u\n", v8, v9);
      else
        ADebug::print_format("\n%s : %s\n\n  Internal Info:\n    %s\n    %s\n    Exception Id: %u\n", v8, v9);
      ADebug::info();
    }
    else
    {
      v3 = v6->vfptr->determine_choice(v6, (AErrMsg *)&v12, (eAErrAction *)&v20);
    }
    v10 = (unsigned int)v20;
    if ( (_DWORD)v20 == 4 )
    {
      v10 = 3;
      `ADatum::alloc_buffer::`3::_test = 0;
      LODWORD(v20) = 3;
    }
    _((AMD_HD3D *)v10);
    if ( !(_DWORD)v20 )
      _(v11);
    if ( v3 )
      __debugbreak();
    if ( v10 != 3 )
      __debugbreak();
    result = (UFG::allocator::free_link *)v2;
  }
  return result;
}

