// File Line: 36
// RVA: 0x107770
void __fastcall SSTypeContext::~SSTypeContext(SSTypeContext *this)
{
  APSortedLogical<SSTypedName,ASymbol> *p_i_top_scope_old; // rsi
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *p_i_capture_stack; // rbx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *i_next_p; // rcx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v5; // rax
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v6; // rcx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *i_prev_p; // rax
  AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *p_i_scope_stack; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v9; // rdx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v10; // rax
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v11; // rdx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v12; // rax
  SSTypeContext::ScopeVars *p_i_top_scope; // rdi
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v14; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v15; // rax

  p_i_top_scope_old = &this->i_top_scope_old;
  APSizedArrayBase<SSTypedName>::free_all(&this->i_top_scope_old);
  p_i_capture_stack = &this->i_capture_stack;
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars>::free_all(&this->i_capture_stack);
  i_next_p = this->i_capture_stack.i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)p_i_capture_stack->i_sentinel.i_next_p != p_i_capture_stack )
  {
    do
    {
      v5 = i_next_p;
      i_next_p = i_next_p->i_next_p;
      v5->i_next_p = v5;
      v5->i_prev_p = v5;
    }
    while ( i_next_p != (AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)p_i_capture_stack );
    p_i_capture_stack->i_sentinel.i_next_p = &p_i_capture_stack->i_sentinel;
    this->i_capture_stack.i_sentinel.i_prev_p = &this->i_capture_stack.i_sentinel;
  }
  v6 = p_i_capture_stack->i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)p_i_capture_stack->i_sentinel.i_next_p != p_i_capture_stack )
  {
    i_prev_p = this->i_capture_stack.i_sentinel.i_prev_p;
    v6->i_prev_p = i_prev_p;
    i_prev_p->i_next_p = v6;
    this->i_capture_stack.i_sentinel.i_prev_p = &this->i_capture_stack.i_sentinel;
    p_i_capture_stack->i_sentinel.i_next_p = &p_i_capture_stack->i_sentinel;
  }
  p_i_scope_stack = &this->i_scope_stack;
  v9 = this->i_scope_stack.i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)p_i_scope_stack->i_sentinel.i_next_p != p_i_scope_stack )
  {
    do
    {
      v10 = v9;
      v9 = v9->i_next_p;
      v10->i_next_p = v10;
      v10->i_prev_p = v10;
    }
    while ( v9 != (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)p_i_scope_stack );
    p_i_scope_stack->i_sentinel.i_next_p = &p_i_scope_stack->i_sentinel;
    this->i_scope_stack.i_sentinel.i_prev_p = &this->i_scope_stack.i_sentinel;
  }
  v11 = p_i_scope_stack->i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)p_i_scope_stack->i_sentinel.i_next_p != p_i_scope_stack )
  {
    v12 = this->i_scope_stack.i_sentinel.i_prev_p;
    v11->i_prev_p = v12;
    v12->i_next_p = v11;
    this->i_scope_stack.i_sentinel.i_prev_p = &this->i_scope_stack.i_sentinel;
    p_i_scope_stack->i_sentinel.i_next_p = &p_i_scope_stack->i_sentinel;
  }
  AMemory::c_free_func(p_i_top_scope_old->i_array_p);
  p_i_top_scope = &this->i_top_scope;
  APSizedArrayBase<SSTypedName>::free_all(&p_i_top_scope->i_vars);
  AMemory::c_free_func(p_i_top_scope->i_vars.i_array_p);
  v14 = p_i_top_scope->i_next_p;
  if ( p_i_top_scope->i_next_p != p_i_top_scope )
  {
    v15 = p_i_top_scope->i_prev_p;
    v14->i_prev_p = v15;
    v15->i_next_p = v14;
    p_i_top_scope->i_prev_p = p_i_top_scope;
    p_i_top_scope->i_next_p = p_i_top_scope;
  }
}

// File Line: 50
// RVA: 0x10E080
void __fastcall SSTypeContext::append_local(SSTypeContext *this, ASymbol *var_name, SSClassDescBase *type_p)
{
  SSTypedName *v6; // rbx

  v6 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
  if ( v6 )
  {
    v6->i_name = (ASymbol)var_name->i_uid;
    v6->i_type_p.i_obj_p = type_p;
    if ( type_p )
      (*(void (__fastcall **)(SSClassDescBase *))type_p->vfptr->gap8)(type_p);
  }
  else
  {
    v6 = 0i64;
  }
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(this->i_current_scope_p, v6, 0i64);
}

// File Line: 81
// RVA: 0x126840
void __fastcall SSTypeContext::nest_locals(SSTypeContext *this)
{
  char *v2; // rax
  char *v3; // rdx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_prev_p; // rax

  v2 = UFG::qMalloc(0x28ui64, "ScopeVars", 0i64);
  v3 = v2;
  if ( v2 )
  {
    *((_QWORD *)v2 + 1) = v2;
    *(_QWORD *)v2 = v2;
    *((_DWORD *)v2 + 4) = 0;
    *((_QWORD *)v2 + 3) = 0i64;
    *((_DWORD *)v2 + 8) = 0;
  }
  else
  {
    v3 = 0i64;
  }
  this->i_current_scope_p = (APSortedLogical<SSTypedName,ASymbol> *)(v3 + 16);
  i_prev_p = this->i_scope_stack.i_sentinel.i_prev_p;
  this->i_scope_stack.i_sentinel.i_prev_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v3;
  i_prev_p->i_next_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v3;
  *((_QWORD *)v3 + 1) = i_prev_p;
  *(_QWORD *)v3 = &this->i_scope_stack;
}

