// File Line: 74
// RVA: 0x111B10
void __fastcall SSTypeContext::capture_locals(SSTypeContext *this)
{
  char *v2; // rax
  SSTypeContext::CapturedVars *v3; // r8
  APSortedLogical<SSTypedName,ASymbol> *i_current_scope_p; // rdx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *i_prev_p; // rax

  v2 = UFG::qMalloc(0x30ui64, "CapturedVars", 0i64);
  v3 = (SSTypeContext::CapturedVars *)v2;
  if ( v2 )
  {
    i_current_scope_p = this->i_current_scope_p;
    *((_QWORD *)v2 + 1) = v2;
    *(_QWORD *)v2 = v2;
    *((_DWORD *)v2 + 4) = 0;
    *((_QWORD *)v2 + 3) = 0i64;
    *((_DWORD *)v2 + 8) = 0;
    *((_QWORD *)v2 + 5) = i_current_scope_p;
  }
  else
  {
    v3 = 0i64;
  }
  this->i_capture_current_p = v3;
  i_prev_p = this->i_capture_stack.i_sentinel.i_prev_p;
  this->i_capture_stack.i_sentinel.i_prev_p = v3;
  i_prev_p->i_next_p = v3;
  v3->i_prev_p = i_prev_p;
  v3->i_next_p = &this->i_capture_stack.i_sentinel;
  SSTypeContext::nest_locals(this);
}

// File Line: 88
// RVA: 0x111BA0
void __fastcall SSTypeContext::capture_locals_stop(
        SSTypeContext *this,
        AVCompactSortedLogical<ASymbol,ASymbol> *captured_p)
{
  SSTypeContext::CapturedVars *i_capture_current_p; // rax
  __int64 i_count; // rsi
  SSTypedName **i_array_p; // rdx
  SSTypedName **i; // r10
  ASymbol *v8; // r8
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *i_prev_p; // rbx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *i_next_p; // rcx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v11; // rax
  SSTypeContext::CapturedVars *v12; // rdx

  if ( captured_p )
  {
    i_capture_current_p = this->i_capture_current_p;
    i_count = i_capture_current_p->i_vars.i_count;
    AVCompactArrayBase<ASymbol>::empty_ensure_count_undef(captured_p, i_capture_current_p->i_vars.i_count);
    if ( (_DWORD)i_count )
    {
      i_array_p = this->i_capture_current_p->i_vars.i_array_p;
      for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
      {
        v8 = &captured_p->i_array_p[captured_p->i_count];
        if ( v8 )
          v8->i_uid = (unsigned int)(*i_array_p)->i_name;
        ++captured_p->i_count;
      }
    }
  }
  i_prev_p = this->i_capture_stack.i_sentinel.i_prev_p;
  if ( i_prev_p )
  {
    AMemory::c_free_func(i_prev_p[1].i_prev_p);
    i_next_p = i_prev_p->i_next_p;
    if ( i_prev_p->i_next_p != i_prev_p )
    {
      v11 = i_prev_p->i_prev_p;
      i_next_p->i_prev_p = v11;
      v11->i_next_p = i_next_p;
      i_prev_p->i_prev_p = i_prev_p;
      i_prev_p->i_next_p = i_prev_p;
    }
    operator delete[](i_prev_p);
  }
  v12 = 0i64;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)this->i_capture_stack.i_sentinel.i_prev_p != &this->i_capture_stack )
    v12 = (SSTypeContext::CapturedVars *)this->i_capture_stack.i_sentinel.i_prev_p;
  this->i_capture_current_p = v12;
  AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(&this->i_scope_stack);
  this->i_current_scope_p = (APSortedLogical<SSTypedName,ASymbol> *)&this->i_scope_stack.i_sentinel.i_prev_p[1];
}

// File Line: 122
// RVA: 0x111CA0
void __fastcall SSTypeContext::change_variable_type(SSTypeContext *this, ASymbol *var_name, SSClassDescBase *type_p)
{
  SSTypedName *v6; // rax
  SSTypedName *v7; // rdi
  SSClassDescBase *i_obj_p; // rcx
  SSTypedName *v9; // rdi

  v6 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(this->i_current_scope_p, var_name);
  v7 = v6;
  if ( v6 )
  {
    if ( v6->i_type_p.i_obj_p != type_p )
    {
      if ( type_p )
        (*(void (__fastcall **)(SSClassDescBase *))type_p->vfptr->gap8)(type_p);
      i_obj_p = v7->i_type_p.i_obj_p;
      if ( i_obj_p )
        (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
      v7->i_type_p.i_obj_p = type_p;
    }
  }
  else if ( SSTypeContext::get_variable_type(this, var_name, 0) != type_p )
  {
    v9 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
    if ( v9 )
    {
      v9->i_name = (ASymbol)var_name->i_uid;
      v9->i_type_p.i_obj_p = type_p;
      if ( type_p )
        (*(void (__fastcall **)(SSClassDescBase *))type_p->vfptr->gap8)(type_p);
    }
    else
    {
      v9 = 0i64;
    }
    APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(this->i_current_scope_p, v9, 0i64);
  }
}

// File Line: 148
// RVA: 0x111D80
void __fastcall SSTypeContext::change_variable_types(SSTypeContext *this, APSortedLogical<SSTypedName,ASymbol> *vars)
{
  ASymbol **i_array_p; // rsi
  ASymbol **i; // r15
  ASymbol *v5; // r14
  SSClassDescBase *v6; // rdi
  APSortedLogical<SSTypedName,ASymbol> *i_current_scope_p; // rdx
  __int64 i_count; // rax
  SSTypedName **v9; // rdx
  SSTypedName **v10; // r9
  unsigned int i_uid; // r10d
  SSTypedName **v12; // rax
  unsigned int v13; // r8d
  unsigned int *v14; // rbx
  __int64 v15; // rcx
  SSTypedName *v16; // rbx

  i_array_p = (ASymbol **)vars->i_array_p;
  for ( i = &i_array_p[vars->i_count]; i_array_p < i; ++i_array_p )
  {
    v5 = *i_array_p;
    v6 = *(SSClassDescBase **)&(*i_array_p)[2].i_uid;
    i_current_scope_p = this->i_current_scope_p;
    i_count = i_current_scope_p->i_count;
    if ( !(_DWORD)i_count )
      goto LABEL_17;
    v9 = i_current_scope_p->i_array_p;
    v10 = &v9[i_count - 1];
    i_uid = v5->i_uid;
    while ( 1 )
    {
      while ( 1 )
      {
        v12 = &v9[((char *)v10 - (char *)v9) >> 4];
        v13 = (*v12)->i_name.i_uid;
        if ( i_uid >= v13 )
          break;
        if ( v9 == v12 )
          goto LABEL_17;
        v10 = v12 - 1;
      }
      if ( i_uid == v13 )
        break;
      if ( v10 == v12 )
        goto LABEL_17;
      v9 = v12 + 1;
    }
    v14 = (unsigned int *)*v12;
    if ( *v12 )
    {
      if ( *((SSClassDescBase **)v14 + 1) != v6 )
      {
        if ( v6 )
          (*(void (__fastcall **)(_QWORD))v6->vfptr->gap8)(*(_QWORD *)&(*i_array_p)[2].i_uid);
        v15 = *((_QWORD *)v14 + 1);
        if ( v15 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
        *((_QWORD *)v14 + 1) = v6;
      }
    }
    else
    {
LABEL_17:
      if ( SSTypeContext::get_variable_type(this, *i_array_p, 0) != v6 )
      {
        v16 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
        if ( v16 )
        {
          v16->i_name = (ASymbol)v5->i_uid;
          v16->i_type_p.i_obj_p = v6;
          if ( v6 )
            (*(void (__fastcall **)(SSClassDescBase *))v6->vfptr->gap8)(v6);
        }
        else
        {
          v16 = 0i64;
        }
        APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(this->i_current_scope_p, v16, 0i64);
      }
    }
  }
}

// File Line: 171
// RVA: 0x1119F0
void __fastcall SSTypeContext::capture_local(
        SSTypeContext *this,
        SSTypedName *var_p,
        SSTypeContext::CapturedVars *top_nesting_p)
{
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *p_i_capture_stack; // r15
  SSTypeContext::CapturedVars *i_next_p; // rbx
  char v7; // si
  unsigned int i_count; // eax
  SSTypedName **i_array_p; // rdi
  unsigned int i_uid; // r10d
  unsigned int **v11; // rdx
  char *v12; // r8
  unsigned int **v13; // rax
  unsigned int v14; // r9d
  _BOOL8 v15; // rcx
  _BOOL8 v16; // r9
  __int64 v17; // rdx

  p_i_capture_stack = &this->i_capture_stack;
  i_next_p = 0i64;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)p_i_capture_stack->i_sentinel.i_next_p != p_i_capture_stack )
    i_next_p = (SSTypeContext::CapturedVars *)p_i_capture_stack->i_sentinel.i_next_p;
  v7 = 0;
  if ( i_next_p )
  {
    while ( i_next_p != top_nesting_p )
    {
      if ( v7 )
        goto LABEL_7;
LABEL_20:
      i_next_p = (SSTypeContext::CapturedVars *)i_next_p->i_next_p;
      if ( i_next_p == (SSTypeContext::CapturedVars *)p_i_capture_stack )
        i_next_p = 0i64;
      if ( !i_next_p )
        return;
    }
    v7 = 1;
LABEL_7:
    i_count = i_next_p->i_vars.i_count;
    if ( i_count )
    {
      i_array_p = i_next_p->i_vars.i_array_p;
      i_uid = var_p->i_name.i_uid;
      v11 = (unsigned int **)&i_array_p[i_count - 1];
      v12 = (char *)i_array_p;
      while ( 1 )
      {
        while ( 1 )
        {
          v13 = (unsigned int **)&v12[8 * (((char *)v11 - v12) >> 4)];
          v14 = **v13;
          if ( i_uid < v14 )
            break;
          v15 = i_uid == v14;
          v16 = i_uid != v14;
          if ( 1 - v15 < 0 )
            break;
          if ( v16 <= 0 )
            goto LABEL_20;
          if ( v11 == v13 )
          {
            v17 = ((char *)v11 - (char *)i_array_p + 8) >> 3;
            goto LABEL_19;
          }
          v12 = (char *)(v13 + 1);
        }
        if ( v12 == (char *)v13 )
          break;
        v11 = v13 - 1;
      }
      LODWORD(v17) = ((char *)v13 - (char *)i_array_p) >> 3;
    }
    else
    {
      LODWORD(v17) = 0;
    }
LABEL_19:
    APSizedArrayBase<SSTypedName>::insert(&i_next_p->i_vars, var_p, v17);
    goto LABEL_20;
  }
}

// File Line: 199
// RVA: 0x115980
signed __int64 __fastcall SSTypeContext::find_variable(SSTypeContext *this, ASymbol *var_name)
{
  SSClassUnaryBase *i_obj_scope_p; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_next_p; // r11
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *p_i_capture_stack; // rsi
  SSTypeContext::CapturedVars *v8; // r10
  AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *p_i_scope_stack; // r15
  __int64 v10; // rax
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v11; // rdx
  unsigned int v12; // r10d
  unsigned int **v13; // r9
  unsigned int **v14; // rax
  unsigned int v15; // r8d
  __int64 i_next_p_low; // rax
  SSTypedName **i_prev_p; // rdx
  unsigned int i_uid; // ebx
  SSTypedName **v19; // r9
  SSTypedName **v20; // rcx
  unsigned int v21; // r8d
  unsigned int v22; // [rsp+50h] [rbp+8h] BYREF

  i_obj_scope_p = this->i_obj_scope_p;
  v22 = 0;
  if ( i_obj_scope_p->vfptr->get_data_type(i_obj_scope_p, var_name, (eSSScope *)&v22) )
    return v22;
  i_next_p = this->i_scope_stack.i_sentinel.i_next_p;
  p_i_capture_stack = &this->i_capture_stack;
  v8 = 0i64;
  p_i_scope_stack = &this->i_scope_stack;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)p_i_capture_stack->i_sentinel.i_next_p != p_i_capture_stack )
    v8 = (SSTypeContext::CapturedVars *)p_i_capture_stack->i_sentinel.i_next_p;
  if ( v8 )
  {
    while ( 1 )
    {
      i_next_p_low = LODWORD(i_next_p[1].i_next_p);
      if ( (_DWORD)i_next_p_low )
      {
        i_prev_p = (SSTypedName **)i_next_p[1].i_prev_p;
        i_uid = var_name->i_uid;
        v19 = &i_prev_p[i_next_p_low - 1];
        while ( 1 )
        {
          while ( 1 )
          {
            v20 = &i_prev_p[((char *)v19 - (char *)i_prev_p) >> 4];
            v21 = (*v20)->i_name.i_uid;
            if ( i_uid >= v21 )
              break;
            if ( i_prev_p == v20 )
              goto LABEL_28;
            v19 = v20 - 1;
          }
          if ( i_uid == v21 )
            break;
          if ( v19 == v20 )
            goto LABEL_28;
          i_prev_p = v20 + 1;
        }
        if ( *v20 )
          break;
      }
LABEL_28:
      if ( v8 )
      {
        if ( (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v8->i_scope_p == &i_next_p[1] )
        {
          v8 = (SSTypeContext::CapturedVars *)v8->i_next_p;
          if ( v8 == (SSTypeContext::CapturedVars *)p_i_capture_stack )
            v8 = 0i64;
        }
      }
      i_next_p = i_next_p->i_next_p;
      if ( i_next_p == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)p_i_scope_stack )
        i_next_p = 0i64;
      if ( !i_next_p )
        return 0i64;
    }
    if ( v8 )
      SSTypeContext::capture_local(this, *v20, v8);
  }
  else
  {
    while ( 1 )
    {
      v10 = LODWORD(i_next_p[1].i_next_p);
      if ( (_DWORD)v10 )
      {
        v11 = i_next_p[1].i_prev_p;
        v12 = var_name->i_uid;
        v13 = (unsigned int **)v11 + v10 - 1;
        while ( 1 )
        {
          while ( 1 )
          {
            v14 = (unsigned int **)v11 + (((char *)v13 - (char *)v11) >> 4);
            v15 = **v14;
            if ( v12 >= v15 )
              break;
            if ( v11 == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v14 )
              goto LABEL_15;
            v13 = v14 - 1;
          }
          if ( v12 == v15 )
            break;
          if ( v13 == v14 )
            goto LABEL_15;
          v11 = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)(v14 + 1);
        }
        if ( *v14 )
          break;
      }
LABEL_15:
      i_next_p = i_next_p->i_next_p;
      if ( i_next_p == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)p_i_scope_stack )
        i_next_p = 0i64;
      if ( !i_next_p )
        return 0i64;
    }
  }
  return 3i64;
}

// File Line: 275
// RVA: 0x10E400
void __fastcall SSTypeContext::archive_locals(SSTypeContext *this, AVCompactArrayBase<ASymbol> *var_names)
{
  __int64 i_count; // rax
  ASymbol *i_array_p; // rdi
  ASymbol *i; // r14
  APSortedLogical<SSTypedName,ASymbol> *i_current_scope_p; // r11
  SSTypedName *v7; // rbx
  __int64 v8; // rbp
  SSTypedName **v9; // rsi
  char *v10; // rdx
  char *v11; // r9
  unsigned int i_uid; // r10d
  unsigned int **v13; // rax
  unsigned int v14; // r8d
  __int64 v15; // rax
  SSTypedName **v16; // rcx
  SSClassDescBase *i_obj_p; // rcx

  i_count = var_names->i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = var_names->i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
    {
      i_current_scope_p = this->i_current_scope_p;
      v7 = 0i64;
      if ( i_current_scope_p->i_count )
      {
        v8 = i_current_scope_p->i_count - 1;
        v9 = i_current_scope_p->i_array_p;
        v10 = (char *)v9;
        v11 = (char *)&v9[v8];
        i_uid = i_array_p->i_uid;
        while ( 1 )
        {
          while ( 1 )
          {
            v13 = (unsigned int **)&v10[8 * ((v11 - v10) >> 4)];
            v14 = **v13;
            if ( i_uid >= v14 )
              break;
            if ( v10 == (char *)v13 )
              goto LABEL_12;
            v11 = (char *)(v13 - 1);
          }
          if ( i_uid == v14 )
            break;
          if ( v11 == (char *)v13 )
            goto LABEL_12;
          v10 = (char *)(v13 + 1);
        }
        v15 = ((char *)v13 - (char *)v9) >> 3;
        v16 = &v9[(unsigned int)v15];
        v7 = *v16;
        i_current_scope_p->i_count = v8;
        memmove(v16, v16 + 1, 8i64 * (unsigned int)(v8 - v15));
      }
LABEL_12:
      if ( !APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append_absent(&this->i_top_scope_old, v7, 0i64)
        && v7 )
      {
        i_obj_p = v7->i_type_p.i_obj_p;
        if ( i_obj_p )
          (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
        AMemory::c_free_func(v7);
      }
    }
  }
}

// File Line: 321
// RVA: 0x11A150
SSClassDescBase *__fastcall SSTypeContext::get_variable_type(
        SSTypeContext *this,
        ASymbol *var_name,
        bool skip_current_scope_b)
{
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_prev_p; // r10
  __int64 v4; // rbx
  __int64 i_next_p_low; // rax
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v8; // rdx
  unsigned int i_uid; // r11d
  unsigned int **v10; // r9
  unsigned int **v11; // rax
  unsigned int v12; // r8d
  _BOOL8 v13; // rcx
  _BOOL8 v14; // r8
  SSClassDescBase *v15; // rax

  i_prev_p = this->i_scope_stack.i_sentinel.i_prev_p;
  v4 = 0i64;
  if ( skip_current_scope_b )
  {
    i_prev_p = i_prev_p->i_prev_p;
    if ( i_prev_p == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&this->i_scope_stack )
      i_prev_p = 0i64;
  }
  if ( i_prev_p )
  {
    while ( 1 )
    {
      i_next_p_low = LODWORD(i_prev_p[1].i_next_p);
      if ( (_DWORD)i_next_p_low )
      {
        v8 = i_prev_p[1].i_prev_p;
        i_uid = var_name->i_uid;
        v10 = (unsigned int **)v8 + i_next_p_low - 1;
        while ( 1 )
        {
          while ( 1 )
          {
            v11 = (unsigned int **)v8 + (((char *)v10 - (char *)v8) >> 4);
            v12 = **v11;
            if ( i_uid >= v12 )
              break;
            if ( v8 == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v11 )
              goto LABEL_14;
            v10 = v11 - 1;
          }
          v13 = i_uid == v12;
          v14 = i_uid != v12;
          if ( v13 )
            break;
          if ( v10 == v11 )
            goto LABEL_14;
          v8 = (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)(v11 + 1);
        }
        if ( *v11 )
          return (SSClassDescBase *)(*(__int64 (__fastcall **)(_QWORD, SSClassUnaryBase *, _BOOL8))(**((_QWORD **)*v11 + 1)
                                                                                                  + 32i64))(
                                      *((_QWORD *)*v11 + 1),
                                      this->i_obj_scope_p,
                                      v14);
      }
LABEL_14:
      i_prev_p = i_prev_p->i_prev_p;
      if ( i_prev_p == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&this->i_scope_stack )
        i_prev_p = 0i64;
      if ( !i_prev_p )
        goto LABEL_17;
    }
  }
  else
  {
LABEL_17:
    v15 = this->i_obj_scope_p->vfptr->get_data_type(this->i_obj_scope_p, var_name, 0i64);
    if ( v15 )
      return v15->vfptr->as_finalized_generic(v15, this->i_obj_scope_p);
    return (SSClassDescBase *)v4;
  }
}

// File Line: 361
// RVA: 0x11F270
char __fastcall SSTypeContext::is_previous_variable(SSTypeContext *this, ASymbol *var_name)
{
  unsigned int i_count; // eax
  SSTypedName **i_array_p; // rdx
  unsigned int i_uid; // r10d
  SSTypedName **v7; // r9
  SSTypedName **v8; // rax
  unsigned int v9; // r8d

  if ( (unsigned int)SSTypeContext::find_variable(this, var_name) )
    return 1;
  i_count = this->i_top_scope_old.i_count;
  if ( i_count )
  {
    i_array_p = this->i_top_scope_old.i_array_p;
    i_uid = var_name->i_uid;
    v7 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = &i_array_p[((char *)v7 - (char *)i_array_p) >> 4];
        v9 = (*v8)->i_name.i_uid;
        if ( i_uid >= v9 )
          break;
        if ( i_array_p == v8 )
          return 0;
        v7 = v8 - 1;
      }
      if ( i_uid == v9 )
        return 1;
      if ( v7 == v8 )
        break;
      i_array_p = v8 + 1;
    }
  }
  return 0;
}

// File Line: 372
// RVA: 0x11F7F0
void __fastcall SSTypeContext::merge(SSTypeContext *this, APSortedLogical<SSTypedName,ASymbol> *merge_vars_p)
{
  ASymbol **i_array_p; // rdi
  ASymbol **i; // rbp
  ASymbol *v5; // rsi
  SSClassUnion *v6; // rbx
  SSClassUnion *variable_type; // rax
  SSClassUnaryBase *merge; // rax
  SSClassUnaryBase *v9; // rbx
  __int64 v10; // rcx

  i_array_p = (ASymbol **)merge_vars_p->i_array_p;
  for ( i = &i_array_p[merge_vars_p->i_count]; i_array_p < i; ++i_array_p )
  {
    v5 = *i_array_p;
    v6 = *(SSClassUnion **)&(*i_array_p)[2].i_uid;
    variable_type = (SSClassUnion *)SSTypeContext::get_variable_type(this, *i_array_p, 0);
    merge = SSClassUnion::get_merge(v6, variable_type);
    v9 = merge;
    if ( *(SSClassUnaryBase **)&v5[2].i_uid != merge )
    {
      if ( merge )
        (*(void (__fastcall **)(SSClassUnaryBase *))merge->vfptr->gap8)(merge);
      v10 = *(_QWORD *)&v5[2].i_uid;
      if ( v10 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 16i64))(v10);
      *(_QWORD *)&v5[2].i_uid = v9;
    }
  }
}

// File Line: 397
// RVA: 0x11FA60
void __fastcall SSTypeContext::merge_locals(
        SSTypeContext *this,
        APSortedLogical<SSTypedName,ASymbol> *merge_vars_p,
        bool first_path_b)
{
  bool v3; // bl
  APSortedLogical<SSTypedName,ASymbol> *i_current_scope_p; // r15
  ASymbol **i_array_p; // rsi
  ASymbol **v8; // rbp
  ASymbol *v9; // rdi
  __int64 i_count; // rax
  SSTypedName **v11; // rdx
  SSTypedName **v12; // r9
  unsigned int i_uid; // r10d
  SSTypedName **v14; // rax
  unsigned int v15; // r8d
  SSClassUnion *v16; // rbx
  SSClassUnion *variable_type; // rax
  SSClassUnaryBase *merge; // rax
  SSClassUnaryBase *v19; // rbx
  __int64 v20; // rcx
  SSTypedName **v21; // r14
  SSTypedName **i; // rbp
  SSTypedName *v23; // rsi
  __int64 v24; // rax
  SSTypedName **v25; // rdx
  SSTypedName **v26; // r9
  ASymbol v27; // r10d
  SSTypedName **v28; // rcx
  unsigned int v29; // r8d
  SSClassUnion **v30; // rdi
  SSClassUnaryBase *v31; // rax
  SSClassUnaryBase *v32; // rbx
  SSClassUnion *v33; // rcx
  SSTypedName *v34; // rdi
  SSClassUnaryBase *i_obj_p; // rax
  SSClassUnion *v36; // rbx
  SSClassUnion *v37; // rax

  v3 = first_path_b;
  i_current_scope_p = this->i_current_scope_p;
  i_array_p = (ASymbol **)merge_vars_p->i_array_p;
  v8 = &i_array_p[merge_vars_p->i_count];
  if ( i_array_p < v8 )
  {
    do
    {
      v9 = *i_array_p;
      i_count = i_current_scope_p->i_count;
      if ( !(_DWORD)i_count )
        goto LABEL_11;
      v11 = i_current_scope_p->i_array_p;
      v12 = &v11[i_count - 1];
      i_uid = v9->i_uid;
      while ( 1 )
      {
        while ( 1 )
        {
          v14 = &v11[((char *)v12 - (char *)v11) >> 4];
          v15 = (*v14)->i_name.i_uid;
          if ( i_uid >= v15 )
            break;
          if ( v11 == v14 )
            goto LABEL_11;
          v12 = v14 - 1;
        }
        if ( i_uid == v15 )
          break;
        if ( v12 == v14 )
          goto LABEL_11;
        v11 = v14 + 1;
      }
      if ( !*v14 )
      {
LABEL_11:
        v16 = *(SSClassUnion **)&v9[2].i_uid;
        variable_type = (SSClassUnion *)SSTypeContext::get_variable_type(this, *i_array_p, 1);
        merge = SSClassUnion::get_merge(v16, variable_type);
        v19 = merge;
        if ( *(SSClassUnaryBase **)&v9[2].i_uid != merge )
        {
          if ( merge )
            (*(void (__fastcall **)(SSClassUnaryBase *))merge->vfptr->gap8)(merge);
          v20 = *(_QWORD *)&v9[2].i_uid;
          if ( v20 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v20 + 16i64))(v20);
          *(_QWORD *)&v9[2].i_uid = v19;
        }
      }
      ++i_array_p;
    }
    while ( i_array_p < v8 );
    v3 = first_path_b;
  }
  v21 = i_current_scope_p->i_array_p;
  for ( i = &v21[i_current_scope_p->i_count]; v21 < i; v3 = first_path_b )
  {
    v23 = *v21;
    v24 = merge_vars_p->i_count;
    if ( !(_DWORD)v24 )
      goto LABEL_35;
    v25 = merge_vars_p->i_array_p;
    v26 = &v25[v24 - 1];
    v27.i_uid = v23->i_name.i_uid;
    while ( 1 )
    {
      while ( 1 )
      {
        v28 = &v25[((char *)v26 - (char *)v25) >> 4];
        v29 = (*v28)->i_name.i_uid;
        if ( v27.i_uid >= v29 )
          break;
        if ( v25 == v28 )
          goto LABEL_35;
        v26 = v28 - 1;
      }
      if ( v27.i_uid == v29 )
        break;
      if ( v26 == v28 )
        goto LABEL_35;
      v25 = v28 + 1;
    }
    v30 = (SSClassUnion **)*v28;
    if ( *v28 )
    {
      v31 = SSClassUnion::get_merge(v30[1], (SSClassUnion *)v23->i_type_p.i_obj_p);
      v32 = v31;
      if ( v30[1] != (SSClassUnion *)v31 )
      {
        if ( v31 )
          (*(void (__fastcall **)(SSClassUnaryBase *))v31->vfptr->gap8)(v31);
        v33 = v30[1];
        if ( v33 )
          (*(void (__fastcall **)(SSClassUnion *))&v33->vfptr->gap8[8])(v33);
        v30[1] = (SSClassUnion *)v32;
      }
    }
    else
    {
LABEL_35:
      v34 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      if ( v34 )
      {
        if ( v3 )
        {
          i_obj_p = (SSClassUnaryBase *)v23->i_type_p.i_obj_p;
        }
        else
        {
          v36 = (SSClassUnion *)v23->i_type_p.i_obj_p;
          v37 = (SSClassUnion *)SSTypeContext::get_variable_type(this, &v23->i_name, 1);
          i_obj_p = SSClassUnion::get_merge(v36, v37);
        }
        v34->i_name.i_uid = v23->i_name.i_uid;
        v34->i_type_p.i_obj_p = i_obj_p;
        if ( i_obj_p )
          (*(void (__fastcall **)(SSClassUnaryBase *))i_obj_p->vfptr->gap8)(i_obj_p);
      }
      else
      {
        v34 = 0i64;
      }
      APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(merge_vars_p, v34, 0i64);
    }
    ++v21;
  }
}

