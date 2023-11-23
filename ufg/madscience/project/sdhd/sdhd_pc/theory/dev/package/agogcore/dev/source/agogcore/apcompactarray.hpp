// File Line: 516
// RVA: 0x10BED0
void __fastcall APCompactArray<SSClause,SSClause,ACompareAddress<SSClause>>::append(
        APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *this,
        SSClause *elem)
{
  size_t i_count; // rbx
  SSClause **i_array_p; // rdi
  SSClause **v6; // rax

  i_count = this->i_count;
  i_array_p = this->i_array_p;
  v6 = APArrayBase<SSClause>::alloc_array((int)i_count + 1);
  i_count *= 8i64;
  this->i_array_p = v6;
  memmove(v6, i_array_p, i_count);
  AMemory::c_free_func(i_array_p);
  *(SSClause **)((char *)this->i_array_p + i_count) = elem;
  ++this->i_count;
}

// File Line: 1012
// RVA: 0x13C320
void __fastcall APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::set_at_expand(
        APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *this,
        unsigned int idx,
        SSExpressionBase *elem_p)
{
  __int64 v3; // rbx

  v3 = idx;
  APCompactArrayBase<SSExpressionBase>::ensure_length_null(this, idx + 1);
  this->i_array_p[v3] = elem_p;
}

// File Line: 2218
// RVA: 0x106920
void __fastcall APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::~APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>(
        APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *this)
{
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)this);
  AMemory::c_free_func(this->i_array_p);
}

