// File Line: 516
// RVA: 0x10BED0
void __fastcall APCompactArray<SSClause,SSClause,ACompareAddress<SSClause>>::append(APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *this, SSClause *elem)
{
  size_t v2; // rbx
  SSClause **v3; // rdi
  APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *v4; // r14
  SSClause *v5; // rsi
  SSClause **v6; // rax

  v2 = this->i_count;
  v3 = this->i_array_p;
  v4 = this;
  v5 = elem;
  v6 = APArrayBase<SSClause>::alloc_array((signed int)v2 + 1);
  v2 *= 8i64;
  v4->i_array_p = v6;
  memmove(v6, v3, v2);
  AMemory::c_free_func(v3);
  *(SSClause **)((char *)v4->i_array_p + v2) = v5;
  ++v4->i_count;
}

// File Line: 1012
// RVA: 0x13C320
void __fastcall APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::set_at_expand(APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *this, unsigned int idx, SSExpressionBase *elem_p)
{
  __int64 v3; // rbx
  SSExpressionBase *v4; // rsi
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v5; // rdi

  v3 = idx;
  v4 = elem_p;
  v5 = this;
  APCompactArrayBase<SSExpressionBase>::ensure_length_null(
    (APCompactArrayBase<SSExpressionBase> *)&this->i_count,
    idx + 1);
  v5->i_array_p[v3] = v4;
}

// File Line: 2218
// RVA: 0x106920
void __fastcall APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::~APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>(APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *this)
{
  APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v1; // rbx

  v1 = this;
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)this);
  AMemory::c_free_func(v1->i_array_p);
}

