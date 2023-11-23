// File Line: 242
// RVA: 0x1123E0
void __fastcall APSizedArrayBase<SSActor>::compact(APSizedArrayBase<SSActor> *this)
{
  unsigned int i_count; // esi
  SSActor **v3; // rax
  SSActor **i_array_p; // rdx
  SSActor **v5; // rbx

  i_count = this->i_count;
  if ( this->i_size > this->i_count )
  {
    if ( i_count )
    {
      v3 = APArrayBase<SSActor>::alloc_array(i_count);
      i_array_p = this->i_array_p;
      this->i_size = i_count;
      v5 = v3;
      memmove(v3, i_array_p, 8i64 * i_count);
      AMemory::c_free_func(this->i_array_p);
      this->i_array_p = v5;
    }
    else
    {
      AMemory::c_free_func(this->i_array_p);
      this->i_array_p = 0i64;
      this->i_size = 0;
    }
  }
}

// File Line: 371
// RVA: 0x114300
void __fastcall APSizedArrayBase<SSData>::ensure_size(APSizedArrayBase<SSData> *this, unsigned int needed)
{
  unsigned int v3; // eax
  bool v4; // zf
  SSData **i_array_p; // rbx
  SSData **v6; // rax
  size_t v7; // r8

  if ( this->i_size < needed )
  {
    v3 = AMemory::c_req_byte_size_func(8 * needed) >> 3;
    v4 = this->i_count == 0;
    this->i_size = v3;
    if ( v4 )
    {
      AMemory::c_free_func(this->i_array_p);
      this->i_array_p = APArrayBase<SSData>::alloc_array(this->i_size);
    }
    else
    {
      i_array_p = this->i_array_p;
      v6 = APArrayBase<SSData>::alloc_array(v3);
      v7 = 8i64 * this->i_count;
      this->i_array_p = v6;
      memmove(v6, i_array_p, v7);
      AMemory::c_free_func(i_array_p);
    }
  }
}

// File Line: 502
// RVA: 0x115F10
void __fastcall APSizedArrayBase<AString>::free_all(APSizedArrayBase<AString> *this)
{
  AString **i_array_p; // rdi
  __int64 i_count; // rax
  AString **i; // rbp
  AString *v4; // rsi
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v10; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  i_array_p = this->i_array_p;
  i_count = this->i_count;
  this->i_count = 0;
  for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
  {
    v4 = *i_array_p;
    if ( *i_array_p )
    {
      i_str_ref_p = v4->i_str_ref_p;
      if ( v4->i_str_ref_p->i_ref_count-- == 1 )
      {
        if ( i_str_ref_p->i_deallocate )
          AMemory::c_free_func(i_str_ref_p->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)i_str_ref_p < i_objects_a
          || (v10 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
              p_i_exp_pool = &pool->i_pool,
              !v10) )
        {
          p_i_exp_pool = &pool->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
      }
      AMemory::c_free_func(v4);
    }
  }
}

// File Line: 605
// RVA: 0x11BE20
void __fastcall APSizedArrayBase<SSClassUnion>::insert(
        APSizedArrayBase<SSClassUnion> *this,
        SSClassUnion *elem,
        unsigned int pos)
{
  unsigned int i_count; // ecx
  __int64 v5; // rsi
  SSClassUnion **i_array_p; // r14
  unsigned __int64 v8; // rax
  SSClassUnion **v9; // rax
  __int64 v10; // rdi

  i_count = this->i_count;
  v5 = pos;
  if ( this->i_size >= i_count + 1 )
  {
    v10 = pos;
    memmove(&this->i_array_p[v10 + 1], &this->i_array_p[v10], 8i64 * (i_count - pos));
  }
  else
  {
    i_array_p = this->i_array_p;
    if ( i_count == -1 )
      LODWORD(v8) = 0;
    else
      v8 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (i_count & 0xFFFFFFFC) + 32) >> 3;
    this->i_size = v8;
    v9 = APArrayBase<SSClassUnion>::alloc_array(v8);
    v10 = v5;
    this->i_array_p = v9;
    memmove(v9, i_array_p, 8 * v5);
    memmove(&this->i_array_p[v10 + 1], &i_array_p[v10], 8i64 * (unsigned int)(this->i_count - v5));
    AMemory::c_free_func(i_array_p);
  }
  this->i_array_p[v10] = elem;
  ++this->i_count;
}

// File Line: 648
// RVA: 0x11C0F0
void __fastcall APSizedArrayBase<SSInstance>::insert(
        APSizedArrayBase<SSInstance> *this,
        SSInstance *elem,
        unsigned int pos,
        unsigned int count)
{
  __int64 v4; // r15
  __int64 v5; // r12
  unsigned int v7; // ebp
  SSInstance **i_array_p; // rbx
  unsigned int v10; // eax
  SSInstance **v11; // rax
  __int64 v12; // r14
  SSInstance **v13; // rdi
  SSInstance **v14; // rdi

  v4 = count;
  v5 = pos;
  v7 = this->i_count + count;
  if ( this->i_size >= v7 )
  {
    v12 = pos;
    memmove(&this->i_array_p[count] + pos, &this->i_array_p[v12], 8i64 * (this->i_count - pos));
  }
  else
  {
    i_array_p = this->i_array_p;
    v10 = AMemory::c_req_byte_size_func(8 * v7);
    this->i_size = v10 >> 3;
    v11 = APArrayBase<SSInstance>::alloc_array(v10 >> 3);
    v12 = v5;
    this->i_array_p = v11;
    memmove(v11, i_array_p, 8 * v5);
    memmove(&this->i_array_p[v4] + v5, &i_array_p[v5], 8i64 * (unsigned int)(this->i_count - v5));
    AMemory::c_free_func(i_array_p);
  }
  v13 = this->i_array_p;
  this->i_count = v7;
  v14 = &v13[v12];
  if ( v14 < &v14[v4] )
    memset64(v14, (unsigned __int64)elem, ((unsigned __int64)(8 * v4 - 1) >> 3) + 1);
}

// File Line: 699
// RVA: 0x11C680
void __fastcall APSizedArrayBase<SSInstance>::insert_all(
        APSizedArrayBase<SSInstance> *this,
        APArrayBase<SSInstance> *array,
        unsigned int pos)
{
  __int64 i_count; // r15
  __int64 v4; // r13
  unsigned int v5; // ebp
  SSInstance **i_array_p; // rdi
  unsigned int v9; // eax
  SSInstance **v10; // rax
  __int64 v11; // r14
  SSInstance **v12; // rcx

  i_count = array->i_count;
  v4 = pos;
  v5 = this->i_count + i_count;
  if ( this->i_size >= v5 )
  {
    v11 = pos;
    memmove(&this->i_array_p[i_count] + pos, &this->i_array_p[v11], 8i64 * (this->i_count - pos));
  }
  else
  {
    i_array_p = this->i_array_p;
    v9 = AMemory::c_req_byte_size_func(8 * v5);
    this->i_size = v9 >> 3;
    v10 = APArrayBase<SSInstance>::alloc_array(v9 >> 3);
    v11 = v4;
    this->i_array_p = v10;
    memmove(v10, i_array_p, 8 * v4);
    memmove(&this->i_array_p[i_count] + v4, &i_array_p[v4], 8i64 * (unsigned int)(this->i_count - v4));
    AMemory::c_free_func(i_array_p);
  }
  v12 = this->i_array_p;
  this->i_count = v5;
  memmove(&v12[v11], array->i_array_p, 8 * i_count);
}

