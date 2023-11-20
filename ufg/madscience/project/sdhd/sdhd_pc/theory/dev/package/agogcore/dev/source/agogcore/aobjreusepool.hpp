// File Line: 60
// RVA: 0x103E80
void __fastcall AObjBlock<SSInvokedExpression>::AObjBlock<SSInvokedExpression>(AObjBlock<SSInvokedExpression> *this, unsigned int size)
{
  AObjBlock<SSInvokedExpression> *v2; // rbx
  int v3; // esi
  char *v4; // rax
  signed __int64 v5; // rax
  unsigned __int8 v6; // cf
  unsigned __int64 v7; // rax
  signed __int64 v8; // rdi
  AErrMsg *v9; // rax
  AErrMsg err_msg; // [rsp+48h] [rbp-80h]
  AErrMsg v11; // [rsp+80h] [rbp-48h]
  eAErrAction action_p; // [rsp+D8h] [rbp+10h]

  v2 = this;
  this->i_size = size;
  v3 = size;
  if ( size )
  {
    v5 = 112i64 * size;
    if ( !is_mul_ok(size, 0x70ui64) )
      v5 = -1i64;
    v6 = __CFADD__(v5, 8i64);
    v7 = v5 + 8;
    if ( v6 )
      v7 = -1i64;
    v4 = (char *)AMemory::c_malloc_func(v7, "AObjBlock");
  }
  else
  {
    v4 = UFG::qMalloc(8ui64, UFG::gGlobalNewName, 0i64);
  }
  if ( v4 )
  {
    *(_DWORD *)v4 = v3;
    v8 = (signed __int64)(v4 + 8);
    `eh vector constructor iterator(
      v4 + 8,
      0x70ui64,
      v3,
      (void (__fastcall *)(void *))SSInvokedExpression::SSInvokedExpression);
  }
  else
  {
    v8 = 0i64;
  }
  v2->i_objects_a = (SSInvokedExpression *)v8;
  if ( `AObjBlock<SSInvokedExpression>::AObjBlock<SSInvokedExpression>::`3::_test && !v8 )
  {
    AErrMsg::AErrMsg(&err_msg, "Unable to allocate memory", AErrLevel_error, 0i64, 0i64);
    AErrMsg::AErrMsg(
      &v11,
      &err_msg,
      "Test failed: i_objects_a != 0",
      "__cdecl AObjBlock<class SSInvokedExpression>::AObjBlock(unsigned int)",
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\agogcore\\dev\\source\\agogcore\\aobjreusepool.hpp",
      0x3Eu,
      3u);
    if ( ADebug::resolve_error(
           v9,
           &action_p,
           &`AObjBlock<SSInvokedExpression>::AObjBlock<SSInvokedExpression>::`3::_test) )
    {
      __debugbreak();
    }
    if ( action_p != 3 )
      __debugbreak();
  }
}

// File Line: 220
// RVA: 0x223660
void __fastcall AObjReusePool<AStringRef>::~AObjReusePool<AStringRef>(AObjReusePool<AStringRef> *this)
{
  AObjReusePool<AStringRef> *v1; // rsi
  AObjBlock<AStringRef> **v2; // rbx
  unsigned __int64 v3; // rbp
  void **v4; // rdi
  void **v5; // rbx

  v1 = this;
  v2 = this->i_exp_blocks.i_array_p;
  v3 = (unsigned __int64)&v2[this->i_exp_blocks.i_count];
  for ( this->i_exp_blocks.i_count = 0; (unsigned __int64)v2 < v3; ++v2 )
  {
    v4 = (void **)*v2;
    if ( *v2 )
    {
      operator delete[](v4[1]);
      operator delete[](v4);
    }
  }
  v5 = (void **)v1->i_block_p;
  if ( v5 )
  {
    operator delete[](v5[1]);
    operator delete[](v5);
  }
  AMemory::c_free_func(v1->i_exp_blocks.i_array_p);
  AMemory::c_free_func(v1->i_exp_pool.i_array_p);
  AMemory::c_free_func(v1->i_pool.i_array_p);
}

// File Line: 377
// RVA: 0x10D640
void __fastcall AObjReusePool<SSBoolean>::append_block(AObjReusePool<SSBoolean> *this, unsigned int size)
{
  unsigned int v2; // esi
  AObjReusePool<SSBoolean> *v3; // rdi
  char *v4; // rax
  AObjBlock<SSBoolean> *v5; // rax
  AObjBlock<SSBoolean> *v6; // rbx
  AErrMsg *v7; // rax
  APArray<SSBoolean,SSBoolean,ACompareAddress<SSBoolean> > *v8; // rcx
  AErrMsg err_msg; // [rsp+48h] [rbp-80h]
  AErrMsg v10; // [rsp+80h] [rbp-48h]
  char *action_p; // [rsp+D0h] [rbp+8h]

  v2 = size;
  v3 = this;
  v4 = UFG::qMalloc(0x10ui64, "tObjBlock", 0i64);
  action_p = v4;
  if ( v4 )
  {
    AObjBlock<SSBoolean>::AObjBlock<SSBoolean>((AObjBlock<SSBoolean> *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( `AObjReusePool<SSBoolean>::append_block::`3::_test && !v6 )
  {
    AErrMsg::AErrMsg(&err_msg, "Unable to allocate memory", AErrLevel_error, 0i64, 0i64);
    AErrMsg::AErrMsg(
      &v10,
      &err_msg,
      "Test failed: obj_block_p != 0",
      "void __cdecl AObjReusePool<class SSBoolean>::append_block(unsigned int)",
      "d:\\ufg\\madscience\\project\\sdhd\\sdhd_pc\\theory\\dev\\package\\agogcore\\dev\\source\\agogcore\\aobjreusepool.hpp",
      0x184u,
      3u);
    if ( ADebug::resolve_error(v7, (eAErrAction *)&action_p, &`AObjReusePool<SSBoolean>::append_block::`3::_test) )
      __debugbreak();
    if ( (_DWORD)action_p != 3 )
      __debugbreak();
  }
  if ( v3->i_block_p )
  {
    APArray<AObjBlock<SSBoolean>,AObjBlock<SSBoolean>,ACompareAddress<AObjBlock<SSBoolean>>>::append(
      &v3->i_exp_blocks,
      v6);
    v8 = &v3->i_exp_pool;
  }
  else
  {
    v3->i_block_p = v6;
    v8 = &v3->i_pool;
  }
  APArray<SSBoolean,SSBoolean,ACompareAddress<SSBoolean>>::append_all(v8, v6->i_objects_a, v2);
}

