// File Line: 49
// RVA: 0x226400
AStringRef *__fastcall AStringRef::pool_new(const char *cstr_p, unsigned int length, unsigned int size, unsigned __int16 ref_count, bool deallocate, bool read_only)
{
  unsigned __int16 v6; // di
  unsigned int v7; // esi
  unsigned int v8; // ebp
  char *v9; // r14
  AObjReusePool<AStringRef> *v10; // rax
  AObjReusePool<AStringRef> *v11; // rbx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  __int64 v15; // rcx
  AStringRef **v16; // rax
  AStringRef *result; // rax
  unsigned int v18; // eax

  v6 = ref_count;
  v7 = size;
  v8 = length;
  v9 = (char *)cstr_p;
  v10 = AStringRef::get_pool();
  v11 = v10;
  v12 = v10->i_pool.i_count;
  if ( v12 )
  {
    v18 = v12 - 1;
    v11->i_pool.i_count = v18;
    v15 = v18;
    v16 = v11->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v11->i_exp_pool.i_count )
    AObjReusePool<AStringRef>::append_block(v11, v11->i_expand_size);
  v13 = v11->i_exp_pool.i_count;
  if ( v13 )
  {
    v14 = v13 - 1;
    v11->i_exp_pool.i_count = v14;
    v15 = v14;
    v16 = v11->i_exp_pool.i_array_p;
LABEL_8:
    result = v16[v15];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_length = v8;
  result->i_deallocate = deallocate;
  result->i_size = v7;
  result->i_ref_count = v6;
  result->i_read_only = read_only;
  result->i_cstr_p = v9;
  return result;
}

// File Line: 79
// RVA: 0x2264B0
AStringRef *__fastcall AStringRef::pool_new_copy(const char *cstr_p, unsigned int length, unsigned __int16 ref_count, bool read_only)
{
  bool v4; // r15
  unsigned __int16 v5; // r12
  size_t v6; // rbp
  const char *v7; // r13
  AObjReusePool<AStringRef> *v8; // rax
  AObjReusePool<AStringRef> *v9; // rbx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  __int64 v13; // rcx
  AStringRef **v14; // rax
  AStringRef *v15; // r14
  unsigned int v16; // eax
  unsigned int v17; // esi
  void *v18; // rdi

  v4 = read_only;
  v5 = ref_count;
  v6 = length;
  v7 = cstr_p;
  v8 = AStringRef::get_pool();
  v9 = v8;
  v10 = v8->i_pool.i_count;
  if ( v10 )
  {
    v16 = v10 - 1;
    v9->i_pool.i_count = v16;
    v13 = v16;
    v14 = v9->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v9->i_exp_pool.i_count )
    AObjReusePool<AStringRef>::append_block(v9, v9->i_expand_size);
  v11 = v9->i_exp_pool.i_count;
  if ( v11 )
  {
    v12 = v11 - 1;
    v9->i_exp_pool.i_count = v12;
    v13 = v12;
    v14 = v9->i_exp_pool.i_array_p;
LABEL_8:
    v15 = v14[v13];
    goto LABEL_9;
  }
  v15 = 0i64;
LABEL_9:
  v17 = AMemory::c_req_byte_size_func(v6 + 1);
  v18 = AMemory::c_malloc_func(v17, "AStringRef.buffer");
  memmove(v18, v7, v6);
  *((_BYTE *)v18 + v6) = 0;
  v15->i_length = v6;
  v15->i_size = v17;
  v15->i_cstr_p = (char *)v18;
  v15->i_ref_count = v5;
  v15->i_deallocate = 1;
  v15->i_read_only = v4;
  return v15;
}

// File Line: 111
// RVA: 0x225220
AStringRef *__fastcall AStringRef::get_empty()
{
  if ( !(_S2_8 & 1) )
  {
    _S2_8 |= 1u;
    s_empty.i_cstr_p = &customWorldMapCaption;
    s_empty.i_length = 0;
    s_empty.i_size = 1;
    *(_DWORD *)&s_empty.i_ref_count = 16777218;
  }
  return &s_empty;
}

// File Line: 132
// RVA: 0x2252D0
AObjReusePool<AStringRef> *__fastcall AStringRef::get_pool()
{
  unsigned int v0; // edi
  unsigned int v1; // ebx
  AStringRef **v2; // rax

  if ( _S3_6 & 1 )
    return &s_pool_6;
  _S3_6 |= 1u;
  v0 = Agog::get_agog_core_vals()->i_pool_incr_string_ref;
  v1 = Agog::get_agog_core_vals()->i_pool_init_string_ref;
  s_pool_6.i_pool.i_count = 0;
  s_pool_6.i_pool.i_array_p = 0i64;
  s_pool_6.i_pool.i_size = 0;
  if ( v1 )
  {
    s_pool_6.i_pool.i_size = v1;
    v2 = APArrayBase<AStringRef>::alloc_array(v1);
  }
  else
  {
    s_pool_6.i_pool.i_size = 0;
    v2 = (AStringRef **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  s_pool_6.i_pool.i_array_p = v2;
  s_pool_6.i_block_p = 0i64;
  s_pool_6.i_exp_pool.i_count = 0;
  s_pool_6.i_exp_pool.i_array_p = 0i64;
  s_pool_6.i_exp_pool.i_size = 0;
  s_pool_6.i_exp_blocks.i_count = 0;
  s_pool_6.i_exp_blocks.i_array_p = 0i64;
  s_pool_6.i_exp_blocks.i_size = 0;
  s_pool_6.i_expand_size = v0;
  AObjReusePool<AStringRef>::append_block(&s_pool_6, v1);
  atexit(AStringRef::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_6;
}

