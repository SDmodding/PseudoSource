// File Line: 389
// RVA: 0xBAB00
void __fastcall AString::AString(AString *this, const char *cstr_p)
{
  const char *v2; // rdi
  AString *v3; // rsi
  signed __int64 v4; // rbx
  unsigned int v5; // eax

  v2 = cstr_p;
  v3 = this;
  v4 = -1i64;
  do
    ++v4;
  while ( cstr_p[v4] );
  v5 = AMemory::c_req_byte_size_func(v4 + 1);
  v3->i_str_ref_p = AStringRef::pool_new(v2, v4, v5, 1u, 0, 1);
}

// File Line: 457
// RVA: 0xBAC60
void __fastcall AString::~AString(AString *this)
{
  AStringRef *v1; // rbx
  bool v2; // zf
  AObjReusePool<AStringRef> *v3; // rax
  AObjBlock<AStringRef> *v4; // rcx
  unsigned __int64 v5; // rdx
  bool v6; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v7; // rcx

  v1 = this->i_str_ref_p;
  v2 = this->i_str_ref_p->i_ref_count == 1;
  --v1->i_ref_count;
  if ( v2 )
  {
    if ( v1->i_deallocate )
      AMemory::c_free_func(v1->i_cstr_p);
    v3 = AStringRef::get_pool();
    v4 = v3->i_block_p;
    v5 = (unsigned __int64)v4->i_objects_a;
    if ( (unsigned __int64)v1 < v5 || (v6 = (unsigned __int64)v1 < v5 + 24i64 * v4->i_size, v7 = &v3->i_pool, !v6) )
      v7 = &v3->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v7, v1);
  }
}

// File Line: 467
// RVA: 0xBACC0
AString *__fastcall AString::operator=(AString *this, AString *str)
{
  AString *v2; // rsi
  AString *v3; // rdi
  AStringRef *v4; // rbx
  bool v5; // zf
  AObjReusePool<AStringRef> *v6; // rax
  AObjBlock<AStringRef> *v7; // rcx
  unsigned __int64 v8; // rdx
  bool v9; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v10; // rcx

  v2 = str;
  v3 = this;
  ++str->i_str_ref_p->i_ref_count;
  v4 = this->i_str_ref_p;
  v5 = this->i_str_ref_p->i_ref_count == 1;
  --v4->i_ref_count;
  if ( v5 )
  {
    if ( v4->i_deallocate )
      AMemory::c_free_func(v4->i_cstr_p);
    v6 = AStringRef::get_pool();
    v7 = v6->i_block_p;
    v8 = (unsigned __int64)v7->i_objects_a;
    if ( (unsigned __int64)v4 < v8 || (v9 = (unsigned __int64)v4 < v8 + 24i64 * v7->i_size, v10 = &v6->i_pool, !v9) )
      v10 = &v6->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v10, v4);
  }
  v3->i_str_ref_p = v2->i_str_ref_p;
  return v3;
}

// File Line: 539
// RVA: 0x10E9B0
char *__fastcall AString::as_cstr_writeable(AString *this)
{
  AString *v1; // rbx

  v1 = this;
  if ( this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only == 1 )
    return this->i_str_ref_p->i_cstr_p;
  AString::make_writeable(this);
  return v1->i_str_ref_p->i_cstr_p;
}

// File Line: 1118
// RVA: 0x10CDA0
void __fastcall AString::append(AString *this, AString *str)
{
  const void ***v2; // r14
  AString *v3; // rbx
  unsigned int v4; // edi
  unsigned int v5; // esi

  v2 = (const void ***)str;
  v3 = this;
  v4 = str->i_str_ref_p->i_length;
  if ( v4 )
  {
    v5 = v4 + this->i_str_ref_p->i_length;
    if ( v5 >= this->i_str_ref_p->i_size || this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
      AString::set_size(this, v5);
    memmove(&v3->i_str_ref_p->i_cstr_p[v3->i_str_ref_p->i_length], **v2, v4 + 1);
    v3->i_str_ref_p->i_length = v5;
  }
}

// File Line: 1143
// RVA: 0x10CE30
void __fastcall AString::append(AString *this, char ch)
{
  char v2; // si
  AString *v3; // rdi
  __int64 v4; // rbx

  if ( ch )
  {
    v2 = ch;
    v3 = this;
    v4 = this->i_str_ref_p->i_length + 1;
    if ( (unsigned int)v4 >= this->i_str_ref_p->i_size
      || this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(this, v4);
    }
    v3->i_str_ref_p->i_cstr_p[(unsigned int)(v4 - 1)] = v2;
    v3->i_str_ref_p->i_cstr_p[v4] = 0;
    v3->i_str_ref_p->i_length = v4;
  }
}

// File Line: 1454
// RVA: 0x13C6C0
void __fastcall AString::set_length(AString *this, unsigned int length)
{
  __int64 v2; // rbx
  bool v3; // zf
  AStringRef *v4; // rdx
  AString *v5; // rdi
  signed __int64 v6; // rax

  v2 = length;
  v3 = length == -1;
  v4 = this->i_str_ref_p;
  v5 = this;
  if ( v3 )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( v4->i_cstr_p[v6] );
    v4->i_length = v6;
  }
  else if ( v4->i_length != (_DWORD)v2 || v4->i_cstr_p[v2] )
  {
    if ( (unsigned int)v2 >= v4->i_size || v4->i_ref_count + v4->i_read_only != 1 )
      AString::set_size(this, v2);
    v5->i_str_ref_p->i_length = v2;
    v5->i_str_ref_p->i_cstr_p[v5->i_str_ref_p->i_length] = 0;
  }
}

