// File Line: 58
// RVA: 0x107990
void __fastcall SSTypeContext::ScopeVars::~ScopeVars(SSTypeContext::ScopeVars *this)
{
  APSortedLogical<SSTypedName,ASymbol> *p_i_vars; // rbx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_next_p; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_prev_p; // rax

  p_i_vars = &this->i_vars;
  APSizedArrayBase<SSTypedName>::free_all(&this->i_vars);
  AMemory::c_free_func(p_i_vars->i_array_p);
  i_next_p = this->i_next_p;
  if ( this->i_next_p != this )
  {
    i_prev_p = this->i_prev_p;
    i_next_p->i_prev_p = i_prev_p;
    i_prev_p->i_next_p = i_next_p;
    this->i_prev_p = this;
    this->i_next_p = this;
  }
}

