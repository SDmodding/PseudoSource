// File Line: 185
// RVA: 0x10E1D0
void __fastcall APCompactArrayBase<SSExpressionBase>::append_null(APCompactArrayBase<SSExpressionBase> *this)
{
  size_t i_count; // rbx
  SSExpressionBase **i_array_p; // rdi
  SSExpressionBase **v4; // rax

  i_count = this->i_count;
  i_array_p = this->i_array_p;
  v4 = APArrayBase<SSExpressionBase>::alloc_array((int)i_count + 1);
  i_count *= 8i64;
  this->i_array_p = v4;
  memmove(v4, i_array_p, i_count);
  AMemory::c_free_func(i_array_p);
  *(SSExpressionBase **)((char *)this->i_array_p + i_count) = 0i64;
  ++this->i_count;
}

// File Line: 268
// RVA: 0x114200
void __fastcall APCompactArrayBase<SSExpressionBase>::ensure_length_null(
        APCompactArrayBase<SSExpressionBase> *this,
        unsigned int length_min)
{
  unsigned int i_count; // ebp
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **v6; // rax

  i_count = this->i_count;
  if ( this->i_count < length_min )
  {
    i_array_p = this->i_array_p;
    v6 = APArrayBase<SSExpressionBase>::alloc_array(length_min);
    this->i_array_p = v6;
    memmove(v6, i_array_p, 8i64 * i_count);
    AMemory::c_free_func(i_array_p);
    memset(&this->i_array_p[this->i_count], 0, 8i64 * (length_min - this->i_count));
    this->i_count = length_min;
  }
}

// File Line: 341
// RVA: 0x115D20
void __fastcall APCompactArrayBase<SSParameterBase>::free_all(APCompactArrayBase<SSParameterBase> *this)
{
  SSParameterBase **i_array_p; // rsi
  SSParameterBase **v2; // rdi
  SSParameterBase **v3; // rbx

  i_array_p = this->i_array_p;
  v2 = &i_array_p[this->i_count];
  v3 = i_array_p;
  this->i_array_p = 0i64;
  for ( this->i_count = 0; v3 < v2; ++v3 )
  {
    if ( *v3 )
      (*v3)->vfptr->__vecDelDtor(*v3, 1u);
  }
  AMemory::c_free_func(i_array_p);
}

// File Line: 369
// RVA: 0x116220
void __fastcall APCompactArrayBase<SSExpressionBase>::free_all_last(
        APCompactArrayBase<SSExpressionBase> *this,
        unsigned int elem_count)
{
  __int64 i_count; // r14
  SSExpressionBase **i_array_p; // r15
  SSExpressionBase **v6; // rdi
  SSExpressionBase **v7; // rbx
  unsigned int v8; // r14d
  SSExpressionBase **v9; // rax

  if ( elem_count )
  {
    i_count = this->i_count;
    i_array_p = this->i_array_p;
    v6 = &i_array_p[i_count];
    v7 = &v6[-elem_count];
    v8 = i_count - elem_count;
    if ( v8 )
    {
      v9 = APArrayBase<SSExpressionBase>::alloc_array(v8);
      this->i_array_p = v9;
      memmove(v9, i_array_p, 8i64 * v8);
    }
    else
    {
      this->i_array_p = 0i64;
    }
    for ( this->i_count -= elem_count; v7 < v6; ++v7 )
    {
      if ( *v7 )
        (*v7)->vfptr->__vecDelDtor(*v7, 1u);
    }
    AMemory::c_free_func(i_array_p);
  }
}

// File Line: 453
// RVA: 0x13BE70
void __fastcall APCompactArrayBase<SSExpressionBase>::remove_last(APCompactArrayBase<SSExpressionBase> *this)
{
  SSExpressionBase **i_array_p; // rsi
  bool v3; // zf
  unsigned int v4; // edi
  SSExpressionBase **v5; // rax

  i_array_p = this->i_array_p;
  v3 = this->i_count == 1;
  v4 = this->i_count - 1;
  this->i_count = v4;
  if ( v3 )
  {
    this->i_array_p = 0i64;
  }
  else
  {
    v5 = APArrayBase<SSExpressionBase>::alloc_array(v4);
    this->i_array_p = v5;
    memmove(v5, i_array_p, 8i64 * v4);
  }
  AMemory::c_free_func(i_array_p);
}

// File Line: 891
// RVA: 0x13C7C0
void __fastcall APCompactArrayBase<SSClause>::set_size_free(APCompactArrayBase<SSClause> *this, unsigned int size)
{
  __int64 i_count; // r15
  SSClause **i_array_p; // rdi
  SSClause **i; // rbp
  SSClause *v7; // rbx
  SSExpressionBase *i_test_p; // rcx
  SSExpressionBase *i_clause_p; // rcx
  SSClause **v10; // rcx

  i_count = this->i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
    {
      v7 = *i_array_p;
      if ( *i_array_p )
      {
        i_test_p = v7->i_test_p;
        v7->vfptr = (SSClauseVtbl *)&SSClause::`vftable;
        if ( i_test_p )
          i_test_p->vfptr->__vecDelDtor(i_test_p, 1u);
        i_clause_p = v7->i_clause_p;
        if ( i_clause_p )
          i_clause_p->vfptr->__vecDelDtor(i_clause_p, 1u);
        AMemory::c_free_func(v7);
      }
    }
  }
  if ( (_DWORD)i_count != size )
  {
    v10 = this->i_array_p;
    this->i_count = size;
    if ( v10 )
      AMemory::c_free_func(v10);
    this->i_array_p = APArrayBase<SSClause>::alloc_array(size);
  }
}

