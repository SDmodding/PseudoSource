// File Line: 242
// RVA: 0x1123E0
void __fastcall APSizedArrayBase<SSActor>::compact(APSizedArrayBase<SSActor> *this)
{
  unsigned int v1; // esi
  APSizedArrayBase<SSActor> *v2; // rdi
  SSActor **v3; // rax
  SSActor **v4; // rdx
  SSActor **v5; // rbx

  v1 = this->i_count;
  v2 = this;
  if ( this->i_size > this->i_count )
  {
    if ( v1 )
    {
      v3 = APArrayBase<SSActor>::alloc_array(v1);
      v4 = v2->i_array_p;
      v2->i_size = v1;
      v5 = v3;
      memmove(v3, v4, 8i64 * v1);
      AMemory::c_free_func(v2->i_array_p);
      v2->i_array_p = v5;
    }
    else
    {
      AMemory::c_free_func(this->i_array_p);
      v2->i_array_p = 0i64;
      v2->i_size = 0;
    }
  }
}

// File Line: 371
// RVA: 0x114300
void __fastcall APSizedArrayBase<SSData>::ensure_size(APSizedArrayBase<SSData> *this, unsigned int needed)
{
  APSizedArrayBase<SSData> *v2; // rdi
  unsigned int v3; // eax
  bool v4; // zf
  SSData **v5; // rbx
  SSData **v6; // rax
  size_t v7; // r8

  v2 = this;
  if ( this->i_size < needed )
  {
    v3 = AMemory::c_req_byte_size_func(8 * needed) >> 3;
    v4 = v2->i_count == 0;
    v2->i_size = v3;
    if ( v4 )
    {
      AMemory::c_free_func(v2->i_array_p);
      v2->i_array_p = APArrayBase<SSData>::alloc_array(v2->i_size);
    }
    else
    {
      v5 = v2->i_array_p;
      v6 = APArrayBase<SSData>::alloc_array(v3);
      v7 = 8i64 * v2->i_count;
      v2->i_array_p = v6;
      memmove(v6, v5, v7);
      AMemory::c_free_func(v5);
    }
  }
}

// File Line: 502
// RVA: 0x115F10
void __fastcall APSizedArrayBase<AString>::free_all(APSizedArrayBase<AString> *this)
{
  AString **v1; // rdi
  __int64 v2; // rax
  unsigned __int64 i; // rbp
  AString *v4; // rsi
  AStringRef *v5; // rbx
  bool v6; // zf
  AObjReusePool<AStringRef> *v7; // rax
  AObjBlock<AStringRef> *v8; // rcx
  unsigned __int64 v9; // r8
  bool v10; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v11; // rcx

  v1 = this->i_array_p;
  v2 = this->i_count;
  this->i_count = 0;
  for ( i = (unsigned __int64)&v1[v2]; (unsigned __int64)v1 < i; ++v1 )
  {
    v4 = *v1;
    if ( *v1 )
    {
      v5 = v4->i_str_ref_p;
      v6 = v4->i_str_ref_p->i_ref_count == 1;
      --v5->i_ref_count;
      if ( v6 )
      {
        if ( v5->i_deallocate )
          AMemory::c_free_func(v5->i_cstr_p);
        v7 = AStringRef::get_pool();
        v8 = v7->i_block_p;
        v9 = (unsigned __int64)v8->i_objects_a;
        if ( (unsigned __int64)v5 < v9
          || (v10 = (unsigned __int64)v5 < v9 + 24i64 * v8->i_size, v11 = &v7->i_pool, !v10) )
        {
          v11 = &v7->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v11, v5);
      }
      AMemory::c_free_func(v4);
    }
  }
}

// File Line: 605
// RVA: 0x11BE20
void __fastcall APSizedArrayBase<SSClassUnion>::insert(APSizedArrayBase<SSClassUnion> *this, SSClassUnion *elem, unsigned int pos)
{
  APSizedArrayBase<SSClassUnion> *v3; // rbx
  unsigned int v4; // ecx
  signed __int64 v5; // rsi
  SSClassUnion *v6; // rbp
  SSClassUnion **v7; // r14
  unsigned __int64 v8; // rax
  SSClassUnion **v9; // rax
  signed __int64 v10; // rdi

  v3 = this;
  v4 = this->i_count;
  v5 = pos;
  v6 = elem;
  if ( v3->i_size >= v4 + 1 )
  {
    v10 = pos;
    memmove(&v3->i_array_p[pos + 1], &v3->i_array_p[pos], 8i64 * (v4 - pos));
  }
  else
  {
    v7 = v3->i_array_p;
    if ( v4 == -1 )
      LODWORD(v8) = 0;
    else
      v8 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (v4 & 0xFFFFFFFC) + 32) >> 3;
    v3->i_size = v8;
    v9 = APArrayBase<SSClassUnion>::alloc_array(v8);
    v10 = v5;
    v3->i_array_p = v9;
    memmove(v9, v7, 8 * v5);
    memmove(&v3->i_array_p[v10 + 1], &v7[v10], 8i64 * (unsigned int)(v3->i_count - v5));
    AMemory::c_free_func(v7);
  }
  v3->i_array_p[v10] = v6;
  ++v3->i_count;
}

// File Line: 648
// RVA: 0x11C0F0
void __fastcall APSizedArrayBase<SSInstance>::insert(APSizedArrayBase<SSInstance> *this, SSInstance *elem, unsigned int pos, unsigned int count)
{
  __int64 v4; // r15
  signed __int64 v5; // r12
  SSInstance *v6; // r13
  unsigned int v7; // ebp
  APSizedArrayBase<SSInstance> *v8; // rsi
  SSInstance **v9; // rbx
  unsigned int v10; // eax
  SSInstance **v11; // rax
  signed __int64 v12; // r14
  SSInstance **v13; // rdi
  char *v14; // rdi

  v4 = count;
  v5 = pos;
  v6 = elem;
  v7 = this->i_count + count;
  v8 = this;
  if ( this->i_size >= v7 )
  {
    v12 = pos;
    memmove(&this->i_array_p[count + (unsigned __int64)pos], &this->i_array_p[pos], 8i64 * (this->i_count - pos));
  }
  else
  {
    v9 = this->i_array_p;
    v10 = AMemory::c_req_byte_size_func(8 * v7) >> 3;
    v8->i_size = v10;
    v11 = APArrayBase<SSInstance>::alloc_array(v10);
    v12 = v5;
    v8->i_array_p = v11;
    memmove(v11, v9, 8 * v5);
    memmove(&v8->i_array_p[v4 + v5], &v9[v5], 8i64 * (unsigned int)(v8->i_count - v5));
    AMemory::c_free_func(v9);
  }
  v13 = v8->i_array_p;
  v8->i_count = v7;
  v14 = (char *)&v13[v12];
  if ( v14 < &v14[8 * v4] )
    memset64(v14, (unsigned __int64)v6, ((unsigned __int64)(8 * v4 - 1) >> 3) + 1);
}

// File Line: 699
// RVA: 0x11C680
void __fastcall APSizedArrayBase<SSInstance>::insert_all(APSizedArrayBase<SSInstance> *this, APArrayBase<SSInstance> *array, unsigned int pos)
{
  __int64 v3; // r15
  signed __int64 v4; // r13
  unsigned int v5; // ebp
  APArrayBase<SSInstance> *v6; // r12
  APSizedArrayBase<SSInstance> *v7; // rsi
  SSInstance **v8; // rdi
  unsigned int v9; // eax
  SSInstance **v10; // rax
  signed __int64 v11; // r14
  SSInstance **v12; // rcx

  v3 = array->i_count;
  v4 = pos;
  v5 = this->i_count + v3;
  v6 = array;
  v7 = this;
  if ( this->i_size >= v5 )
  {
    v11 = pos;
    memmove(&this->i_array_p[v3 + pos], &this->i_array_p[pos], 8i64 * (this->i_count - pos));
  }
  else
  {
    v8 = this->i_array_p;
    v9 = AMemory::c_req_byte_size_func(8 * v5) >> 3;
    v7->i_size = v9;
    v10 = APArrayBase<SSInstance>::alloc_array(v9);
    v11 = v4;
    v7->i_array_p = v10;
    memmove(v10, v8, 8 * v4);
    memmove(&v7->i_array_p[v3 + v4], &v8[v4], 8i64 * (unsigned int)(v7->i_count - v4));
    AMemory::c_free_func(v8);
  }
  v12 = v7->i_array_p;
  v7->i_count = v5;
  memmove(&v12[v11], v6->i_array_p, 8 * v3);
}

