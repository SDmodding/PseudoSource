// File Line: 49
// RVA: 0x226400
AStringRef *__fastcall AStringRef::pool_new(
        char *cstr_p,
        unsigned int length,
        unsigned int size,
        unsigned __int16 ref_count,
        bool deallocate,
        bool read_only)
{
  AObjReusePool<AStringRef> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v12; // eax
  __int64 v13; // rcx
  AStringRef **i_array_p; // rax
  AStringRef *result; // rax
  unsigned int v16; // eax

  pool = AStringRef::get_pool();
  if ( pool->i_pool.i_count )
  {
    v16 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v16;
    v13 = v16;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<AStringRef>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v12 = i_count - 1;
    pool->i_exp_pool.i_count = v12;
    v13 = v12;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_8:
    result = i_array_p[v13];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_length = length;
  result->i_deallocate = deallocate;
  result->i_size = size;
  result->i_ref_count = ref_count;
  result->i_read_only = read_only;
  result->i_cstr_p = cstr_p;
  return result;
}

// File Line: 79
// RVA: 0x2264B0
AStringRef *__fastcall AStringRef::pool_new_copy(
        const char *cstr_p,
        unsigned int length,
        unsigned __int16 ref_count,
        bool read_only)
{
  size_t v6; // rbp
  AObjReusePool<AStringRef> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v10; // eax
  __int64 v11; // rcx
  AStringRef **i_array_p; // rax
  AStringRef *v13; // r14
  unsigned int v14; // eax
  unsigned int v15; // esi
  void *v16; // rdi

  v6 = length;
  pool = AStringRef::get_pool();
  if ( pool->i_pool.i_count )
  {
    v14 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v14;
    v11 = v14;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<AStringRef>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v10 = i_count - 1;
    pool->i_exp_pool.i_count = v10;
    v11 = v10;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_8:
    v13 = i_array_p[v11];
    goto LABEL_9;
  }
  v13 = 0i64;
LABEL_9:
  v15 = AMemory::c_req_byte_size_func(v6 + 1);
  v16 = AMemory::c_malloc_func(v15, "AStringRef.buffer");
  memmove(v16, cstr_p, v6);
  *((_BYTE *)v16 + v6) = 0;
  v13->i_length = v6;
  v13->i_size = v15;
  v13->i_cstr_p = (char *)v16;
  v13->i_ref_count = ref_count;
  v13->i_deallocate = 1;
  v13->i_read_only = read_only;
  return v13;
}

// File Line: 111
// RVA: 0x225220
AStringRef *__fastcall AStringRef::get_empty()
{
  if ( (_S2_8 & 1) == 0 )
  {
    _S2_8 |= 1u;
    s_empty.i_cstr_p = &customCaption;
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
  unsigned int i_pool_incr_string_ref; // edi
  unsigned int i_pool_init_string_ref; // ebx
  AStringRef **v2; // rax

  if ( (_S3_6 & 1) != 0 )
    return &s_pool_6;
  _S3_6 |= 1u;
  i_pool_incr_string_ref = Agog::get_agog_core_vals()->i_pool_incr_string_ref;
  i_pool_init_string_ref = Agog::get_agog_core_vals()->i_pool_init_string_ref;
  s_pool_6.i_pool.i_count = 0;
  s_pool_6.i_pool.i_array_p = 0i64;
  s_pool_6.i_pool.i_size = 0;
  if ( i_pool_init_string_ref )
  {
    s_pool_6.i_pool.i_size = i_pool_init_string_ref;
    v2 = APArrayBase<AStringRef>::alloc_array(i_pool_init_string_ref);
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
  s_pool_6.i_expand_size = i_pool_incr_string_ref;
  AObjReusePool<AStringRef>::append_block(&s_pool_6, i_pool_init_string_ref);
  atexit(AStringRef::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_6;
}

