// File Line: 58
// RVA: 0x107990
void __fastcall SSTypeContext::ScopeVars::~ScopeVars(SSTypeContext::ScopeVars *this)
{
  SSTypeContext::ScopeVars *v1; // rdi
  void **v2; // rbx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v3; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v4; // rax

  v1 = this;
  v2 = (void **)&this->i_vars;
  APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&this->i_vars.i_count);
  AMemory::c_free_func(v2[1]);
  v3 = v1->i_next_p;
  if ( (SSTypeContext::ScopeVars *)v1->i_next_p != v1 )
  {
    v4 = v1->i_prev_p;
    v3->i_prev_p = v4;
    v4->i_next_p = v3;
    v1->i_prev_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&v1->i_next_p;
    v1->i_next_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&v1->i_next_p;
  }
}

