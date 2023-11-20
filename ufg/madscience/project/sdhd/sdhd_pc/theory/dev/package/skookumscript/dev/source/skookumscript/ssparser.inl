// File Line: 132
// RVA: 0x1063F0
void __fastcall SSParser::SSParser(SSParser *this, AString *str)
{
  SSParser *v2; // rdi
  AStringRef *v3; // rax
  SSTypeContext *v4; // rbx
  SSTypeContext::ScopeVars *v5; // rdx
  APSortedLogical<SSTypedName,ASymbol> *v6; // rax
  APSortedLogical<SSTypedName,ASymbol> *v7; // rax
  AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v8; // rcx
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v9; // rax
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v10; // rax

  v2 = this;
  v3 = str->i_str_ref_p;
  this->i_str_ref_p = str->i_str_ref_p;
  ++v3->i_ref_count;
  this->i_flags = SSParser::c_default_flags;
  this->i_member_type = 12;
  v4 = &this->i_context;
  v4->i_obj_scope_p = 0i64;
  v4->i_scope_name.i_uid = -1;
  v5 = &this->i_context.i_top_scope;
  v5->i_prev_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&v5->i_next_p;
  v5->i_next_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&v5->i_next_p;
  v6 = &this->i_context.i_top_scope.i_vars;
  v6->i_count = 0;
  v6->i_array_p = 0i64;
  v6->i_size = 0;
  v7 = &this->i_context.i_top_scope_old;
  v7->i_count = 0;
  v7->i_array_p = 0i64;
  v7->i_size = 0;
  v8 = &this->i_context.i_scope_stack;
  v8->i_sentinel.i_prev_p = &v8->i_sentinel;
  v8->i_sentinel.i_next_p = &v8->i_sentinel;
  v4->i_current_scope_p = &v4->i_top_scope.i_vars;
  v9 = &v4->i_capture_stack;
  v9->i_sentinel.i_prev_p = &v9->i_sentinel;
  v9->i_sentinel.i_next_p = &v9->i_sentinel;
  v4->i_capture_current_p = 0i64;
  v10 = v4->i_scope_stack.i_sentinel.i_prev_p;
  v4->i_scope_stack.i_sentinel.i_prev_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&v5->i_next_p;
  v10->i_next_p = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&v5->i_next_p;
  v5->i_prev_p = v10;
  v5->i_next_p = &v8->i_sentinel;
  v4->i_obj_scope_p = (SSClassUnaryBase *)&SSBrain::c_object_class_p->vfptr;
  v2->i_context.i_scope_name = ASymbol::c_null;
  APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&v4->i_current_scope_p->i_count);
  APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&v4->i_top_scope_old.i_count);
}

