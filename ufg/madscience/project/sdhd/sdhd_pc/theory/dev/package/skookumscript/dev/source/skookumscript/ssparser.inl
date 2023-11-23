// File Line: 132
// RVA: 0x1063F0
void __fastcall SSParser::SSParser(SSParser *this, AString *str)
{
  AStringRef *i_str_ref_p; // rax
  SSTypeContext *p_i_context; // rbx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_prev_p; // rax

  i_str_ref_p = str->i_str_ref_p;
  this->i_str_ref_p = str->i_str_ref_p;
  ++i_str_ref_p->i_ref_count;
  this->i_flags = SSParser::c_default_flags;
  this->i_member_type = SSMember__invalid;
  p_i_context = &this->i_context;
  this->i_context.i_obj_scope_p = 0i64;
  this->i_context.i_scope_name.i_uid = -1;
  this->i_context.i_top_scope.i_prev_p = &this->i_context.i_top_scope;
  this->i_context.i_top_scope.i_next_p = &this->i_context.i_top_scope;
  this->i_context.i_top_scope.i_vars.i_count = 0;
  this->i_context.i_top_scope.i_vars.i_array_p = 0i64;
  this->i_context.i_top_scope.i_vars.i_size = 0;
  this->i_context.i_top_scope_old.i_count = 0;
  this->i_context.i_top_scope_old.i_array_p = 0i64;
  this->i_context.i_top_scope_old.i_size = 0;
  this->i_context.i_scope_stack.i_sentinel.i_prev_p = &this->i_context.i_scope_stack.i_sentinel;
  this->i_context.i_scope_stack.i_sentinel.i_next_p = &this->i_context.i_scope_stack.i_sentinel;
  this->i_context.i_current_scope_p = &this->i_context.i_top_scope.i_vars;
  this->i_context.i_capture_stack.i_sentinel.i_prev_p = &this->i_context.i_capture_stack.i_sentinel;
  this->i_context.i_capture_stack.i_sentinel.i_next_p = &this->i_context.i_capture_stack.i_sentinel;
  this->i_context.i_capture_current_p = 0i64;
  i_prev_p = this->i_context.i_scope_stack.i_sentinel.i_prev_p;
  this->i_context.i_scope_stack.i_sentinel.i_prev_p = &this->i_context.i_top_scope;
  i_prev_p->i_next_p = &this->i_context.i_top_scope;
  this->i_context.i_top_scope.i_prev_p = i_prev_p;
  this->i_context.i_top_scope.i_next_p = &this->i_context.i_scope_stack.i_sentinel;
  this->i_context.i_obj_scope_p = SSBrain::c_object_class_p;
  this->i_context.i_scope_name = ASymbol::c_null;
  APSizedArrayBase<SSTypedName>::free_all(this->i_context.i_current_scope_p);
  APSizedArrayBase<SSTypedName>::free_all(&p_i_context->i_top_scope_old);
}

