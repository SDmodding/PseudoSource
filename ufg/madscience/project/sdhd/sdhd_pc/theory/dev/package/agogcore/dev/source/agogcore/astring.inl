// File Line: 389
// RVA: 0xBAB00
void __fastcall AString::AString(AString *this, const char *cstr_p)
{
  __int64 v4; // rbx
  unsigned int v5; // eax

  v4 = -1i64;
  do
    ++v4;
  while ( cstr_p[v4] );
  v5 = AMemory::c_req_byte_size_func(v4 + 1);
  this->i_str_ref_p = AStringRef::pool_new(cstr_p, v4, v5, 1u, 0, 1);
}

// File Line: 457
// RVA: 0xBAC60
void __fastcall AString::~AString(AString *this)
{
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v6; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  i_str_ref_p = this->i_str_ref_p;
  if ( this->i_str_ref_p->i_ref_count-- == 1 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_str_ref_p < i_objects_a
      || (v6 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool,
                                                                                        !v6) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
  }
}

// File Line: 467
// RVA: 0xBACC0
AString *__fastcall AString::operator=(AString *this, AString *str)
{
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v9; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  ++str->i_str_ref_p->i_ref_count;
  i_str_ref_p = this->i_str_ref_p;
  if ( this->i_str_ref_p->i_ref_count-- == 1 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_str_ref_p < i_objects_a
      || (v9 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool,
                                                                                        !v9) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
  }
  this->i_str_ref_p = str->i_str_ref_p;
  return this;
}

// File Line: 539
// RVA: 0x10E9B0
char *__fastcall AString::as_cstr_writeable(AString *this)
{
  if ( this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only == 1 )
    return this->i_str_ref_p->i_cstr_p;
  AString::make_writeable(this);
  return this->i_str_ref_p->i_cstr_p;
}

// File Line: 1118
// RVA: 0x10CDA0
void __fastcall AString::append(AString *this, AString *str)
{
  unsigned int i_length; // edi
  unsigned int v5; // esi

  i_length = str->i_str_ref_p->i_length;
  if ( i_length )
  {
    v5 = i_length + this->i_str_ref_p->i_length;
    if ( v5 >= this->i_str_ref_p->i_size || this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
      AString::set_size(this, v5);
    memmove(&this->i_str_ref_p->i_cstr_p[this->i_str_ref_p->i_length], str->i_str_ref_p->i_cstr_p, i_length + 1);
    this->i_str_ref_p->i_length = v5;
  }
}

// File Line: 1143
// RVA: 0x10CE30
void __fastcall AString::append(AString *this, char ch)
{
  __int64 v4; // rbx

  if ( ch )
  {
    v4 = this->i_str_ref_p->i_length + 1;
    if ( (unsigned int)v4 >= this->i_str_ref_p->i_size
      || this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(this, v4);
    }
    this->i_str_ref_p->i_cstr_p[(unsigned int)(v4 - 1)] = ch;
    this->i_str_ref_p->i_cstr_p[v4] = 0;
    this->i_str_ref_p->i_length = v4;
  }
}

// File Line: 1454
// RVA: 0x13C6C0
void __fastcall AString::set_length(AString *this, unsigned int length)
{
  __int64 v2; // rbx
  bool v3; // zf
  AStringRef *i_str_ref_p; // rdx
  __int64 v6; // rax

  v2 = length;
  v3 = length == -1;
  i_str_ref_p = this->i_str_ref_p;
  if ( v3 )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( i_str_ref_p->i_cstr_p[v6] );
    i_str_ref_p->i_length = v6;
  }
  else if ( i_str_ref_p->i_length != (_DWORD)v2 || i_str_ref_p->i_cstr_p[v2] )
  {
    if ( (unsigned int)v2 >= i_str_ref_p->i_size || i_str_ref_p->i_ref_count + i_str_ref_p->i_read_only != 1 )
      AString::set_size(this, v2);
    this->i_str_ref_p->i_length = v2;
    this->i_str_ref_p->i_cstr_p[this->i_str_ref_p->i_length] = 0;
  }
}

