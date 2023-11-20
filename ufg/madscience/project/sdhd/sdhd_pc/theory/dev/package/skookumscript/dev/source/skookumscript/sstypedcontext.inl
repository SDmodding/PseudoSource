// File Line: 36
// RVA: 0x107770
void __fastcall SSTypeContext::~SSTypeContext(SSTypeContext *this)
{
  SSTypeContext *v1; // rdi
  void **v2; // rsi
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v3; // rbx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v4; // rcx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v5; // rax
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v6; // rcx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v7; // rax
  AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v8; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v9; // rdx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v10; // rax
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v11; // rdx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v12; // rax
  signed __int64 v13; // rdi
  __int64 v14; // rcx
  _QWORD *v15; // rax

  v1 = this;
  v2 = (void **)&this->i_top_scope_old;
  APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&this->i_top_scope_old.i_count);
  v3 = &v1->i_capture_stack;
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars>::free_all(&v1->i_capture_stack);
  v4 = v1->i_capture_stack.i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3->i_sentinel.i_next_p != v3 )
  {
    do
    {
      v5 = v4;
      v4 = v4->i_next_p;
      v5->i_next_p = v5;
      v5->i_prev_p = v5;
    }
    while ( v4 != (AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3 );
    v3->i_sentinel.i_next_p = &v3->i_sentinel;
    v1->i_capture_stack.i_sentinel.i_prev_p = &v1->i_capture_stack.i_sentinel;
  }
  v6 = v3->i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3->i_sentinel.i_next_p != v3 )
  {
    v7 = v1->i_capture_stack.i_sentinel.i_prev_p;
    v6->i_prev_p = v7;
    v7->i_next_p = v6;
    v1->i_capture_stack.i_sentinel.i_prev_p = &v1->i_capture_stack.i_sentinel;
    v3->i_sentinel.i_next_p = &v3->i_sentinel;
  }
  v8 = &v1->i_scope_stack;
  v9 = v1->i_scope_stack.i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v8->i_sentinel.i_next_p != v8 )
  {
    do
    {
      v10 = v9;
      v9 = v9->i_next_p;
      v10->i_next_p = v10;
      v10->i_prev_p = v10;
    }
    while ( v9 != (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v8 );
    v8->i_sentinel.i_next_p = &v8->i_sentinel;
    v1->i_scope_stack.i_sentinel.i_prev_p = &v1->i_scope_stack.i_sentinel;
  }
  v11 = v8->i_sentinel.i_next_p;
  if ( (AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v8->i_sentinel.i_next_p != v8 )
  {
    v12 = v1->i_scope_stack.i_sentinel.i_prev_p;
    v11->i_prev_p = v12;
    v12->i_next_p = v11;
    v1->i_scope_stack.i_sentinel.i_prev_p = &v1->i_scope_stack.i_sentinel;
    v8->i_sentinel.i_next_p = &v8->i_sentinel;
  }
  AMemory::c_free_func(v2[1]);
  v13 = (signed __int64)&v1->i_top_scope;
  APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)(v13 + 16));
  AMemory::c_free_func(*(void **)(v13 + 24));
  v14 = *(_QWORD *)v13;
  if ( *(_QWORD *)v13 != v13 )
  {
    v15 = *(_QWORD **)(v13 + 8);
    *(_QWORD *)(v14 + 8) = v15;
    *v15 = v14;
    *(_QWORD *)(v13 + 8) = v13;
    *(_QWORD *)v13 = v13;
  }
}

// File Line: 50
// RVA: 0x10E080
void __fastcall SSTypeContext::append_local(SSTypeContext *this, ASymbol *var_name, SSClassDescBase *type_p)
{
  SSClassDescBase *v3; // rdi
  ASymbol *v4; // rsi
  SSTypeContext *v5; // rbp
  SSTypedName *v6; // rbx

  v3 = type_p;
  v4 = var_name;
  v5 = this;
  v6 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
  if ( v6 )
  {
    v6->i_name = (ASymbol)v4->i_uid;
    v6->i_type_p.i_obj_p = v3;
    if ( v3 )
      (*(void (__fastcall **)(SSClassDescBase *))v3->vfptr->gap8)(v3);
  }
  else
  {
    v6 = 0i64;
  }
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(
    (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v5->i_current_scope_p->i_count,
    v6,
    0i64);
}

// File Line: 81
// RVA: 0x126840
void __fastcall SSTypeContext::nest_locals(SSTypeContext *this)
{
  SSTypeContext *v1; // rbx
  char *v2; // rax
  char *v3; // rdx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v4; // rax
  signed __int64 v5; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = UFG::qMalloc(0x28ui64, "ScopeVars", 0i64);
  v3 = v2;
  if ( v2 )
  {
    *((_QWORD *)v2 + 1) = v2;
    *(_QWORD *)v2 = v2;
    v5 = (signed __int64)(v2 + 16);
    *(_DWORD *)v5 = 0;
    *(_QWORD *)(v5 + 8) = 0i64;
    *(_DWORD *)(v5 + 16) = 0;
  }
  else
  {
    v3 = 0i64;
  }
  v1->i_current_scope_p = (APSortedLogical<SSTypedName,ASymbol> *)(v3 + 16);
  v4 = v1->i_scope_stack.i_sentinel.i_prev_p;
  v1->i_scope_stack.i_sentinel.i_prev_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v3;
  v4->i_next_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v3;
  *((_QWORD *)v3 + 1) = v4;
  *(_QWORD *)v3 = (char *)v1 + 80;
}

