// File Line: 185
// RVA: 0x10E1D0
void __fastcall APCompactArrayBase<SSExpressionBase>::append_null(APCompactArrayBase<SSExpressionBase> *this)
{
  size_t v1; // rbx
  SSExpressionBase **v2; // rdi
  APCompactArrayBase<SSExpressionBase> *v3; // rsi
  SSExpressionBase **v4; // rax

  v1 = this->i_count;
  v2 = this->i_array_p;
  v3 = this;
  v4 = APArrayBase<SSExpressionBase>::alloc_array((signed int)v1 + 1);
  v1 *= 8i64;
  v3->i_array_p = v4;
  memmove(v4, v2, v1);
  AMemory::c_free_func(v2);
  *(SSExpressionBase **)((char *)v3->i_array_p + v1) = 0i64;
  ++v3->i_count;
}

// File Line: 268
// RVA: 0x114200
void __fastcall APCompactArrayBase<SSExpressionBase>::ensure_length_null(APCompactArrayBase<SSExpressionBase> *this, unsigned int length_min)
{
  unsigned int v2; // ebp
  unsigned int v3; // esi
  APCompactArrayBase<SSExpressionBase> *v4; // rdi
  SSExpressionBase **v5; // rbx
  SSExpressionBase **v6; // rax

  v2 = this->i_count;
  v3 = length_min;
  v4 = this;
  if ( this->i_count < length_min )
  {
    v5 = this->i_array_p;
    v6 = APArrayBase<SSExpressionBase>::alloc_array(length_min);
    v4->i_array_p = v6;
    memmove(v6, v5, 8i64 * v2);
    AMemory::c_free_func(v5);
    memset(&v4->i_array_p[v4->i_count], 0, 8i64 * (v3 - v4->i_count));
    v4->i_count = v3;
  }
}

// File Line: 341
// RVA: 0x115D20
void __fastcall APCompactArrayBase<SSParameterBase>::free_all(APCompactArrayBase<SSParameterBase> *this)
{
  SSParameterBase **v1; // rsi
  unsigned __int64 v2; // rdi
  SSParameterBase **v3; // rbx

  v1 = this->i_array_p;
  v2 = (unsigned __int64)&v1[this->i_count];
  v3 = this->i_array_p;
  this->i_array_p = 0i64;
  this->i_count = 0;
  if ( (unsigned __int64)v1 < v2 )
  {
    do
    {
      if ( *v3 )
        (*v3)->vfptr->__vecDelDtor(*v3, 1u);
      ++v3;
    }
    while ( (unsigned __int64)v3 < v2 );
  }
  AMemory::c_free_func(v1);
}

// File Line: 369
// RVA: 0x116220
void __fastcall APCompactArrayBase<SSExpressionBase>::free_all_last(APCompactArrayBase<SSExpressionBase> *this, unsigned int elem_count)
{
  __int64 v2; // r14
  unsigned int v3; // ebp
  SSExpressionBase **v4; // r15
  APCompactArrayBase<SSExpressionBase> *v5; // rsi
  unsigned __int64 v6; // rdi
  SSExpressionBase **v7; // rbx
  unsigned int v8; // er14
  SSExpressionBase **v9; // rax

  if ( elem_count )
  {
    v2 = this->i_count;
    v3 = elem_count;
    v4 = this->i_array_p;
    v5 = this;
    v6 = (unsigned __int64)&v4[v2];
    v7 = &(&v4[v2])[-elem_count];
    v8 = v2 - elem_count;
    if ( v8 )
    {
      v9 = APArrayBase<SSExpressionBase>::alloc_array(v8);
      v5->i_array_p = v9;
      memmove(v9, v4, 8i64 * v8);
    }
    else
    {
      this->i_array_p = 0i64;
    }
    for ( v5->i_count -= v3; (unsigned __int64)v7 < v6; ++v7 )
    {
      if ( *v7 )
        (*v7)->vfptr->__vecDelDtor(*v7, 1u);
    }
    AMemory::c_free_func(v4);
  }
}

// File Line: 453
// RVA: 0x13BE70
void __fastcall APCompactArrayBase<SSExpressionBase>::remove_last(APCompactArrayBase<SSExpressionBase> *this)
{
  SSExpressionBase **v1; // rsi
  APCompactArrayBase<SSExpressionBase> *v2; // rbx
  bool v3; // zf
  unsigned int v4; // edi
  SSExpressionBase **v5; // rax

  v1 = this->i_array_p;
  v2 = this;
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
    v2->i_array_p = v5;
    memmove(v5, v1, 8i64 * v4);
  }
  AMemory::c_free_func(v1);
}

// File Line: 891
// RVA: 0x13C7C0
void __fastcall APCompactArrayBase<SSClause>::set_size_free(APCompactArrayBase<SSClause> *this, unsigned int size)
{
  __int64 v2; // r15
  unsigned int v3; // er14
  APCompactArrayBase<SSClause> *v4; // rsi
  SSClause **v5; // rdi
  unsigned __int64 i; // rbp
  SSClause *v7; // rbx
  SSExpressionBase *v8; // rcx
  SSExpressionBase *v9; // rcx
  SSClause **v10; // rcx

  v2 = this->i_count;
  v3 = size;
  v4 = this;
  if ( (_DWORD)v2 )
  {
    v5 = this->i_array_p;
    for ( i = (unsigned __int64)&v5[v2]; (unsigned __int64)v5 < i; ++v5 )
    {
      v7 = *v5;
      if ( *v5 )
      {
        v8 = v7->i_test_p;
        v7->vfptr = (SSClauseVtbl *)&SSClause::`vftable';
        if ( v8 )
          v8->vfptr->__vecDelDtor(v8, 1u);
        v9 = v7->i_clause_p;
        if ( v9 )
          v9->vfptr->__vecDelDtor(v9, 1u);
        AMemory::c_free_func(v7);
      }
    }
  }
  if ( (_DWORD)v2 != v3 )
  {
    v10 = v4->i_array_p;
    v4->i_count = v3;
    if ( v10 )
      AMemory::c_free_func(v10);
    v4->i_array_p = APArrayBase<SSClause>::alloc_array(v3);
  }
}

