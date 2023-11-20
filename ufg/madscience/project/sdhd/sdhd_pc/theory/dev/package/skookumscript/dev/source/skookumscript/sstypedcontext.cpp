// File Line: 74
// RVA: 0x111B10
void __fastcall SSTypeContext::capture_locals(SSTypeContext *this)
{
  SSTypeContext *v1; // rbx
  char *v2; // rax
  char *v3; // r8
  APSortedLogical<SSTypedName,ASymbol> *v4; // rdx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v5; // rax
  signed __int64 v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = UFG::qMalloc(0x30ui64, "CapturedVars", 0i64);
  v3 = v2;
  if ( v2 )
  {
    v4 = v1->i_current_scope_p;
    *((_QWORD *)v2 + 1) = v2;
    *(_QWORD *)v2 = v2;
    v6 = (signed __int64)(v2 + 16);
    *(_DWORD *)v6 = 0;
    *(_QWORD *)(v6 + 8) = 0i64;
    *(_DWORD *)(v6 + 16) = 0;
    *((_QWORD *)v2 + 5) = v4;
  }
  else
  {
    v3 = 0i64;
  }
  v1->i_capture_current_p = (SSTypeContext::CapturedVars *)v3;
  v5 = v1->i_capture_stack.i_sentinel.i_prev_p;
  v1->i_capture_stack.i_sentinel.i_prev_p = (AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3;
  v5->i_next_p = (AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3;
  *((_QWORD *)v3 + 1) = v5;
  *(_QWORD *)v3 = (char *)v1 + 104;
  SSTypeContext::nest_locals(v1);
}

// File Line: 88
// RVA: 0x111BA0
void __fastcall SSTypeContext::capture_locals_stop(SSTypeContext *this, AVCompactSortedLogical<ASymbol,ASymbol> *captured_p)
{
  AVCompactSortedLogical<ASymbol,ASymbol> *v2; // rbx
  SSTypeContext *v3; // rdi
  SSTypeContext::CapturedVars *v4; // rax
  __int64 v5; // rsi
  SSTypedName **v6; // rdx
  unsigned __int64 i; // r10
  ASymbol *v8; // r8
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v9; // rbx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v10; // rcx
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v11; // rax
  SSTypeContext::CapturedVars *v12; // rdx

  v2 = captured_p;
  v3 = this;
  if ( captured_p )
  {
    v4 = this->i_capture_current_p;
    v5 = v4->i_vars.i_count;
    AVCompactArrayBase<ASymbol>::empty_ensure_count_undef(
      (AVCompactArrayBase<ASymbol> *)&captured_p->i_count,
      v4->i_vars.i_count);
    if ( (_DWORD)v5 )
    {
      v6 = v3->i_capture_current_p->i_vars.i_array_p;
      for ( i = (unsigned __int64)&v6[v5]; (unsigned __int64)v6 < i; ++v6 )
      {
        v8 = &v2->i_array_p[v2->i_count];
        if ( v8 )
          v8->i_uid = (unsigned int)(*v6)->i_name;
        ++v2->i_count;
      }
    }
  }
  v9 = v3->i_capture_stack.i_sentinel.i_prev_p;
  if ( v9 )
  {
    AMemory::c_free_func(v9[1].i_prev_p);
    v10 = v9->i_next_p;
    if ( v9->i_next_p != v9 )
    {
      v11 = v9->i_prev_p;
      v10->i_prev_p = v11;
      v11->i_next_p = v10;
      v9->i_prev_p = v9;
      v9->i_next_p = v9;
    }
    operator delete[](v9);
  }
  v12 = 0i64;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3->i_capture_stack.i_sentinel.i_prev_p != &v3->i_capture_stack )
    v12 = (SSTypeContext::CapturedVars *)v3->i_capture_stack.i_sentinel.i_prev_p;
  v3->i_capture_current_p = v12;
  AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(&v3->i_scope_stack);
  v3->i_current_scope_p = (APSortedLogical<SSTypedName,ASymbol> *)&v3->i_scope_stack.i_sentinel.i_prev_p[1];
}

// File Line: 122
// RVA: 0x111CA0
void __fastcall SSTypeContext::change_variable_type(SSTypeContext *this, ASymbol *var_name, SSClassDescBase *type_p)
{
  SSClassDescBase *v3; // rbx
  ASymbol *v4; // rsi
  SSTypeContext *v5; // rbp
  SSTypedName *v6; // rax
  SSTypedName *v7; // rdi
  SSClassDescBase *v8; // rcx
  SSTypedName *v9; // rdi

  v3 = type_p;
  v4 = var_name;
  v5 = this;
  v6 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_current_scope_p->i_count,
         var_name);
  v7 = v6;
  if ( v6 )
  {
    if ( v6->i_type_p.i_obj_p != v3 )
    {
      if ( v3 )
        (*(void (__fastcall **)(SSClassDescBase *))v3->vfptr->gap8)(v3);
      v8 = v7->i_type_p.i_obj_p;
      if ( v8 )
        (*(void (__cdecl **)(SSClassDescBase *))&v8->vfptr->gap8[8])(v8);
      v7->i_type_p.i_obj_p = v3;
    }
  }
  else if ( SSTypeContext::get_variable_type(v5, v4, 0) != v3 )
  {
    v9 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
    if ( v9 )
    {
      v9->i_name = (ASymbol)v4->i_uid;
      v9->i_type_p.i_obj_p = v3;
      if ( v3 )
        (*(void (__fastcall **)(SSClassDescBase *))v3->vfptr->gap8)(v3);
    }
    else
    {
      v9 = 0i64;
    }
    APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(
      (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v5->i_current_scope_p->i_count,
      v9,
      0i64);
  }
}

// File Line: 148
// RVA: 0x111D80
void __fastcall SSTypeContext::change_variable_types(SSTypeContext *this, APSortedLogical<SSTypedName,ASymbol> *vars)
{
  SSTypeContext *v2; // rbp
  ASymbol **v3; // rsi
  unsigned __int64 v4; // r15
  ASymbol *v5; // r14
  SSClassDescBase *v6; // rdi
  APSortedLogical<SSTypedName,ASymbol> *v7; // rdx
  __int64 v8; // rax
  signed __int64 v9; // rdx
  signed __int64 v10; // r9
  unsigned int v11; // er10
  unsigned int **v12; // rax
  unsigned int v13; // er8
  _BOOL8 v14; // r8
  unsigned int *v15; // rbx
  __int64 v16; // rcx
  SSTypedName *v17; // rbx

  v2 = this;
  v3 = (ASymbol **)vars->i_array_p;
  v4 = (unsigned __int64)&v3[vars->i_count];
  if ( (unsigned __int64)v3 >= v4 )
    return;
  do
  {
    v5 = *v3;
    v6 = *(SSClassDescBase **)&(*v3)[2].i_uid;
    v7 = v2->i_current_scope_p;
    v8 = v7->i_count;
    if ( !(_DWORD)v8 )
    {
LABEL_18:
      if ( SSTypeContext::get_variable_type(v2, *v3, 0) != v6 )
      {
        v17 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
        if ( v17 )
        {
          v17->i_name = (ASymbol)v5->i_uid;
          v17->i_type_p.i_obj_p = v6;
          if ( v6 )
            (*(void (__fastcall **)(SSClassDescBase *))v6->vfptr->gap8)(v6);
        }
        else
        {
          v17 = 0i64;
        }
        APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(
          (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_current_scope_p->i_count,
          v17,
          0i64);
      }
      goto LABEL_25;
    }
    v9 = (signed __int64)v7->i_array_p;
    v10 = v9 + 8 * (v8 - 1);
    v11 = v5->i_uid;
    while ( 1 )
    {
      v12 = (unsigned int **)(v9 + 8 * ((v10 - v9) >> 4));
      v13 = **v12;
      if ( v11 < v13 )
        goto LABEL_9;
      v14 = v11 != v13;
      if ( !v14 )
        break;
      if ( v14 < 0 )
      {
LABEL_9:
        if ( (unsigned int **)v9 == v12 )
          goto LABEL_18;
        v10 = (signed __int64)(v12 - 1);
      }
      else
      {
        if ( (unsigned int **)v10 == v12 )
          goto LABEL_18;
        v9 = (signed __int64)(v12 + 1);
      }
    }
    v15 = *v12;
    if ( !*v12 )
      goto LABEL_18;
    if ( *((SSClassDescBase **)v15 + 1) != v6 )
    {
      if ( v6 )
        (*(void (__fastcall **)(_QWORD))v6->vfptr->gap8)(*(_QWORD *)&(*v3)[2].i_uid);
      v16 = *((_QWORD *)v15 + 1);
      if ( v16 )
        (*(void (__cdecl **)(__int64))(*(_QWORD *)v16 + 16i64))(v16);
      *((_QWORD *)v15 + 1) = v6;
    }
LABEL_25:
    ++v3;
  }
  while ( (unsigned __int64)v3 < v4 );
}

// File Line: 171
// RVA: 0x1119F0
void __fastcall SSTypeContext::capture_local(SSTypeContext *this, SSTypedName *var_p, SSTypeContext::CapturedVars *top_nesting_p)
{
  AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v3; // r15
  SSTypeContext::CapturedVars *v4; // rbp
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v5; // rbx
  SSTypedName *v6; // r14
  char v7; // si
  int v8; // eax
  AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *v9; // rdi
  unsigned int v10; // er10
  signed __int64 v11; // rdx
  signed __int64 v12; // r8
  unsigned int **v13; // rax
  unsigned int v14; // er9
  _BOOL8 v15; // rcx
  _BOOL8 v16; // r9
  signed __int64 v17; // rdx

  v3 = &this->i_capture_stack;
  v4 = top_nesting_p;
  v5 = 0i64;
  v6 = var_p;
  if ( (AList<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3->i_sentinel.i_next_p != v3 )
    v5 = v3->i_sentinel.i_next_p;
  v7 = 0;
  if ( v5 )
  {
    while ( v5 != (AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v4 )
    {
      if ( v7 )
        goto LABEL_7;
LABEL_20:
      v5 = v5->i_next_p;
      if ( v5 == (AListNode<SSTypeContext::CapturedVars,SSTypeContext::CapturedVars> *)v3 )
        v5 = 0i64;
      if ( !v5 )
        return;
    }
    v7 = 1;
LABEL_7:
    v8 = (int)v5[1].i_next_p;
    if ( v8 )
    {
      v9 = v5[1].i_prev_p;
      v10 = v6->i_name.i_uid;
      v11 = (signed __int64)v9 + 8 * (unsigned int)(v8 - 1);
      v12 = (signed __int64)v5[1].i_prev_p;
      while ( 1 )
      {
        while ( 1 )
        {
          v13 = (unsigned int **)(v12 + 8 * ((v11 - v12) >> 4));
          v14 = **v13;
          if ( v10 < v14 )
            break;
          v15 = v10 == v14;
          v16 = v10 != v14;
          if ( 1 - v15 < 0 )
            break;
          if ( v16 <= 0 )
            goto LABEL_20;
          if ( (unsigned int **)v11 == v13 )
          {
            v17 = (v11 - (signed __int64)v9 + 8) >> 3;
            goto LABEL_19;
          }
          v12 = (signed __int64)(v13 + 1);
        }
        if ( (unsigned int **)v12 == v13 )
          break;
        v11 = (signed __int64)(v13 - 1);
      }
      LODWORD(v17) = ((char *)v13 - (char *)v9) >> 3;
    }
    else
    {
      LODWORD(v17) = 0;
    }
LABEL_19:
    APSizedArrayBase<SSTypedName>::insert((APSizedArrayBase<SSTypedName> *)&v5[1], v6, v17);
    goto LABEL_20;
  }
}

// File Line: 199
// RVA: 0x115980
signed __int64 __fastcall SSTypeContext::find_variable(SSTypeContext *this, ASymbol *var_name)
{
  SSTypeContext *v2; // r14
  SSClassUnaryBase *v3; // rcx
  ASymbol *v4; // rbp
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v6; // r11
  SSTypeContext::CapturedVars **v7; // rsi
  SSTypeContext::CapturedVars *v8; // r10
  signed __int64 v9; // r15
  __int64 v10; // rax
  signed __int64 v11; // rdx
  unsigned int v12; // er10
  signed __int64 v13; // r9
  unsigned int **v14; // rax
  unsigned int v15; // er8
  _BOOL8 v16; // rcx
  _BOOL8 v17; // r8
  __int64 v18; // rax
  signed __int64 v19; // rdx
  unsigned int v20; // ebx
  signed __int64 v21; // r9
  SSTypedName **v22; // rcx
  unsigned int v23; // er8
  _BOOL8 v24; // rax
  _BOOL8 v25; // r8
  unsigned int v26; // [rsp+50h] [rbp+8h]

  v2 = this;
  v3 = this->i_obj_scope_p;
  v26 = 0;
  v4 = var_name;
  if ( v3->vfptr->get_data_type((SSClassDescBase *)&v3->vfptr, var_name, (eSSScope *)&v26) )
    return v26;
  v6 = v2->i_scope_stack.i_sentinel.i_next_p;
  v7 = (SSTypeContext::CapturedVars **)&v2->i_capture_stack;
  v8 = 0i64;
  v9 = (signed __int64)&v2->i_scope_stack;
  if ( *v7 != (SSTypeContext::CapturedVars *)v7 )
    v8 = *v7;
  if ( v8 )
  {
    while ( 1 )
    {
      v18 = LODWORD(v6[1].i_next_p);
      if ( (_DWORD)v18 )
        break;
LABEL_31:
      if ( v8 )
      {
        if ( (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v8->i_scope_p == &v6[1] )
        {
          v8 = (SSTypeContext::CapturedVars *)v8->i_next_p;
          if ( v8 == (SSTypeContext::CapturedVars *)v7 )
            v8 = 0i64;
        }
      }
      v6 = v6->i_next_p;
      if ( v6 == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v9 )
        v6 = 0i64;
      if ( !v6 )
        return 0i64;
    }
    v19 = (signed __int64)v6[1].i_prev_p;
    v20 = v4->i_uid;
    v21 = v19 + 8 * (v18 - 1);
    while ( 1 )
    {
      v22 = (SSTypedName **)(v19 + 8 * ((v21 - v19) >> 4));
      v23 = (*v22)->i_name.i_uid;
      if ( v20 < v23 )
        goto LABEL_44;
      v24 = v20 == v23;
      v25 = v20 != v23;
      if ( v24 == 1 )
      {
        if ( *v22 )
        {
          if ( v8 )
            SSTypeContext::capture_local(v2, *v22, v8);
          return 3i64;
        }
        goto LABEL_31;
      }
      if ( v25 < 0 )
      {
LABEL_44:
        if ( (SSTypedName **)v19 == v22 )
          goto LABEL_31;
        v21 = (signed __int64)(v22 - 1);
      }
      else
      {
        if ( (SSTypedName **)v21 == v22 )
          goto LABEL_31;
        v19 = (signed __int64)(v22 + 1);
      }
    }
  }
  while ( 2 )
  {
    v10 = LODWORD(v6[1].i_next_p);
    if ( !(_DWORD)v10 )
      goto LABEL_16;
    v11 = (signed __int64)v6[1].i_prev_p;
    v12 = v4->i_uid;
    v13 = v11 + 8 * (v10 - 1);
    while ( 1 )
    {
      v14 = (unsigned int **)(v11 + 8 * ((v13 - v11) >> 4));
      v15 = **v14;
      if ( v12 < v15 )
        goto LABEL_13;
      v16 = v12 == v15;
      v17 = v12 != v15;
      if ( v16 == 1 )
        break;
      if ( v17 < 0 )
      {
LABEL_13:
        if ( (unsigned int **)v11 == v14 )
          goto LABEL_16;
        v13 = (signed __int64)(v14 - 1);
      }
      else
      {
        if ( (unsigned int **)v13 == v14 )
          goto LABEL_16;
        v11 = (signed __int64)(v14 + 1);
      }
    }
    if ( !*v14 )
    {
LABEL_16:
      v6 = v6->i_next_p;
      if ( v6 == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)v9 )
        v6 = 0i64;
      if ( !v6 )
        return 0i64;
      continue;
    }
    return 3i64;
  }
}

// File Line: 275
// RVA: 0x10E400
void __fastcall SSTypeContext::archive_locals(SSTypeContext *this, AVCompactArrayBase<ASymbol> *var_names)
{
  SSTypeContext *v2; // r15
  __int64 v3; // rax
  ASymbol *v4; // rdi
  unsigned __int64 i; // r14
  APSortedLogical<SSTypedName,ASymbol> *v6; // r11
  SSTypedName *v7; // rbx
  __int64 v8; // rbp
  signed __int64 v9; // rsi
  signed __int64 v10; // rdx
  signed __int64 v11; // r9
  unsigned int v12; // er10
  unsigned int **v13; // rax
  unsigned int v14; // er8
  _BOOL8 v15; // r8
  signed __int64 v16; // rax
  SSTypedName **v17; // rcx
  SSClassDescBase *v18; // rcx

  v2 = this;
  v3 = var_names->i_count;
  if ( (_DWORD)v3 )
  {
    v4 = var_names->i_array_p;
    for ( i = (unsigned __int64)&v4[v3]; (unsigned __int64)v4 < i; ++v4 )
    {
      v6 = v2->i_current_scope_p;
      v7 = 0i64;
      if ( v6->i_count )
      {
        v8 = v6->i_count - 1;
        v9 = (signed __int64)v6->i_array_p;
        v10 = v9;
        v11 = v9 + 8 * v8;
        v12 = v4->i_uid;
        while ( 1 )
        {
          while ( 1 )
          {
            v13 = (unsigned int **)(v10 + 8 * ((v11 - v10) >> 4));
            v14 = **v13;
            if ( v12 >= v14 )
            {
              v15 = v12 != v14;
              if ( v15 >= 0 )
                break;
            }
            if ( (unsigned int **)v10 == v13 )
              goto LABEL_13;
            v11 = (signed __int64)(v13 - 1);
          }
          if ( v15 <= 0 )
            break;
          if ( (unsigned int **)v11 == v13 )
            goto LABEL_13;
          v10 = (signed __int64)(v13 + 1);
        }
        v16 = ((signed __int64)v13 - v9) >> 3;
        v17 = (SSTypedName **)(v9 + 8i64 * (unsigned int)v16);
        v7 = *v17;
        v6->i_count = v8;
        memmove(v17, v17 + 1, 8i64 * (unsigned int)(v8 - v16));
      }
LABEL_13:
      if ( !APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append_absent(
              (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v2->i_top_scope_old.i_count,
              v7,
              0i64)
        && v7 )
      {
        v18 = v7->i_type_p.i_obj_p;
        if ( v18 )
          (*(void (__cdecl **)(SSClassDescBase *))&v18->vfptr->gap8[8])(v18);
        AMemory::c_free_func(v7);
      }
    }
  }
}

// File Line: 321
// RVA: 0x11A150
SSClassDescBase *__fastcall SSTypeContext::get_variable_type(SSTypeContext *this, ASymbol *var_name, bool skip_current_scope_b)
{
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v3; // r10
  __int64 v4; // rbx
  ASymbol *v5; // rsi
  SSTypeContext *v6; // rdi
  __int64 v7; // rax
  signed __int64 v8; // rdx
  unsigned int v9; // er11
  signed __int64 v10; // r9
  unsigned int **v11; // rax
  unsigned int v12; // er8
  _BOOL8 v13; // rcx
  _BOOL8 v14; // r8
  __int64 v15; // rax

  v3 = this->i_scope_stack.i_sentinel.i_prev_p;
  v4 = 0i64;
  v5 = var_name;
  v6 = this;
  if ( skip_current_scope_b )
  {
    v3 = v3->i_prev_p;
    if ( v3 == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&this->i_scope_stack )
      v3 = 0i64;
  }
  if ( !v3 )
  {
LABEL_18:
    v15 = (__int64)v6->i_obj_scope_p->vfptr->get_data_type((SSClassDescBase *)&v6->i_obj_scope_p->vfptr, v5, 0i64);
    if ( v15 )
      v4 = (*(__int64 (__fastcall **)(__int64, SSClassUnaryBase *))(*(_QWORD *)v15 + 32i64))(v15, v6->i_obj_scope_p);
    return (SSClassDescBase *)v4;
  }
  while ( 2 )
  {
    v7 = LODWORD(v3[1].i_next_p);
    if ( !(_DWORD)v7 )
      goto LABEL_15;
    v8 = (signed __int64)v3[1].i_prev_p;
    v9 = v5->i_uid;
    v10 = v8 + 8 * (v7 - 1);
    while ( 1 )
    {
      v11 = (unsigned int **)(v8 + 8 * ((v10 - v8) >> 4));
      v12 = **v11;
      if ( v9 < v12 )
        goto LABEL_12;
      v13 = v9 == v12;
      v14 = v9 != v12;
      if ( v13 == 1 )
        break;
      if ( v14 < 0 )
      {
LABEL_12:
        if ( (unsigned int **)v8 == v11 )
          goto LABEL_15;
        v10 = (signed __int64)(v11 - 1);
      }
      else
      {
        if ( (unsigned int **)v10 == v11 )
          goto LABEL_15;
        v8 = (signed __int64)(v11 + 1);
      }
    }
    if ( !*v11 )
    {
LABEL_15:
      v3 = v3->i_prev_p;
      if ( v3 == (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *)&v6->i_scope_stack )
        v3 = 0i64;
      if ( !v3 )
        goto LABEL_18;
      continue;
    }
    return (SSClassDescBase *)(*(__int64 (__fastcall **)(_QWORD, SSClassUnaryBase *, _BOOL8))(**((_QWORD **)*v11 + 1)
                                                                                            + 32i64))(
                                *((_QWORD *)*v11 + 1),
                                v6->i_obj_scope_p,
                                v14);
  }
}

// File Line: 361
// RVA: 0x11F270
char __fastcall SSTypeContext::is_previous_variable(SSTypeContext *this, ASymbol *var_name)
{
  ASymbol *v2; // rdi
  SSTypeContext *v3; // rbx
  unsigned int v4; // eax
  signed __int64 v5; // rdx
  unsigned int v6; // er10
  signed __int64 v7; // r9
  unsigned int **v8; // rax
  unsigned int v9; // er8
  _BOOL8 v10; // r8

  v2 = var_name;
  v3 = this;
  if ( (unsigned int)SSTypeContext::find_variable(this, var_name) )
    return 1;
  v4 = v3->i_top_scope_old.i_count;
  if ( v4 )
  {
    v5 = (signed __int64)v3->i_top_scope_old.i_array_p;
    v6 = v2->i_uid;
    v7 = v5 + 8i64 * (v4 - 1);
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = (unsigned int **)(v5 + 8 * ((v7 - v5) >> 4));
        v9 = **v8;
        if ( v6 >= v9 )
        {
          v10 = v6 != v9;
          if ( v10 >= 0 )
            break;
        }
        if ( (unsigned int **)v5 == v8 )
          return 0;
        v7 = (signed __int64)(v8 - 1);
      }
      if ( v10 <= 0 )
        return 1;
      if ( (unsigned int **)v7 == v8 )
        break;
      v5 = (signed __int64)(v8 + 1);
    }
  }
  return 0;
}

// File Line: 372
// RVA: 0x11F7F0
void __fastcall SSTypeContext::merge(SSTypeContext *this, APSortedLogical<SSTypedName,ASymbol> *merge_vars_p)
{
  ASymbol **v2; // rdi
  SSTypeContext *v3; // r14
  unsigned __int64 i; // rbp
  ASymbol *v5; // rsi
  SSClassDescBase *v6; // rbx
  SSClassDescBase *v7; // rax
  __int64 v8; // r8
  SSClassUnaryBase *v9; // rax
  SSClassUnaryBase *v10; // rbx
  __int64 v11; // rcx

  v2 = (ASymbol **)merge_vars_p->i_array_p;
  v3 = this;
  for ( i = (unsigned __int64)&v2[merge_vars_p->i_count]; (unsigned __int64)v2 < i; ++v2 )
  {
    v5 = *v2;
    v6 = *(SSClassDescBase **)&(*v2)[2].i_uid;
    v7 = SSTypeContext::get_variable_type(v3, *v2, 0);
    v9 = SSClassUnion::get_merge(v6, v7, v8);
    v10 = v9;
    if ( *(SSClassUnaryBase **)&v5[2].i_uid != v9 )
    {
      if ( v9 )
        (*(void (__fastcall **)(SSClassUnaryBase *))v9->vfptr->gap8)(v9);
      v11 = *(_QWORD *)&v5[2].i_uid;
      if ( v11 )
        (*(void (**)(void))(*(_QWORD *)v11 + 16i64))();
      *(_QWORD *)&v5[2].i_uid = v10;
    }
  }
}

// File Line: 397
// RVA: 0x11FA60
void __fastcall SSTypeContext::merge_locals(SSTypeContext *this, APSortedLogical<SSTypedName,ASymbol> *merge_vars_p, bool first_path_b)
{
  bool v3; // bl
  APSortedLogical<SSTypedName,ASymbol> *v4; // r12
  SSTypeContext *v5; // r13
  APSortedLogical<SSTypedName,ASymbol> *v6; // r15
  ASymbol **v7; // rsi
  unsigned __int64 v8; // rbp
  ASymbol *v9; // rdi
  __int64 v10; // rax
  signed __int64 v11; // rdx
  signed __int64 v12; // r9
  unsigned int v13; // er10
  unsigned int **v14; // rax
  unsigned int v15; // er8
  _BOOL8 v16; // r8
  SSClassDescBase *v17; // rbx
  SSClassDescBase *v18; // rax
  __int64 v19; // r8
  SSClassUnaryBase *v20; // rax
  SSClassUnaryBase *v21; // rbx
  __int64 v22; // rcx
  SSTypedName **v23; // r14
  unsigned __int64 v24; // rbp
  SSTypedName *v25; // rsi
  __int64 v26; // rax
  signed __int64 v27; // rdx
  signed __int64 v28; // r9
  ASymbol v29; // er10
  unsigned int **v30; // rcx
  unsigned int v31; // er8
  _BOOL8 v32; // r8
  SSClassDescBase **v33; // rdi
  SSClassUnaryBase *v34; // rax
  SSClassUnaryBase *v35; // rbx
  SSClassDescBase *v36; // rcx
  SSTypedName *v37; // rdi
  SSClassUnaryBase *v38; // rax
  SSClassDescBase *v39; // rbx
  SSClassDescBase *v40; // rax
  __int64 v41; // r8
  bool v42; // [rsp+80h] [rbp+18h]

  v42 = first_path_b;
  v3 = first_path_b;
  v4 = merge_vars_p;
  v5 = this;
  v6 = this->i_current_scope_p;
  v7 = (ASymbol **)merge_vars_p->i_array_p;
  v8 = (unsigned __int64)&v7[merge_vars_p->i_count];
  if ( (unsigned __int64)v7 >= v8 )
    goto LABEL_20;
  do
  {
    v9 = *v7;
    v10 = v6->i_count;
    if ( !(_DWORD)v10 )
    {
LABEL_12:
      v17 = *(SSClassDescBase **)&v9[2].i_uid;
      v18 = SSTypeContext::get_variable_type(v5, *v7, 1);
      v20 = SSClassUnion::get_merge(v17, v18, v19);
      v21 = v20;
      if ( *(SSClassUnaryBase **)&v9[2].i_uid != v20 )
      {
        if ( v20 )
          (*(void (__fastcall **)(SSClassUnaryBase *))v20->vfptr->gap8)(v20);
        v22 = *(_QWORD *)&v9[2].i_uid;
        if ( v22 )
          (*(void (__cdecl **)(__int64))(*(_QWORD *)v22 + 16i64))(v22);
        *(_QWORD *)&v9[2].i_uid = v21;
      }
      goto LABEL_18;
    }
    v11 = (signed __int64)v6->i_array_p;
    v12 = v11 + 8 * (v10 - 1);
    v13 = v9->i_uid;
    while ( 1 )
    {
      v14 = (unsigned int **)(v11 + 8 * ((v12 - v11) >> 4));
      v15 = **v14;
      if ( v13 < v15 )
        goto LABEL_9;
      v16 = v13 != v15;
      if ( !v16 )
        break;
      if ( v16 < 0 )
      {
LABEL_9:
        if ( (unsigned int **)v11 == v14 )
          goto LABEL_12;
        v12 = (signed __int64)(v14 - 1);
      }
      else
      {
        if ( (unsigned int **)v12 == v14 )
          goto LABEL_12;
        v11 = (signed __int64)(v14 + 1);
      }
    }
    if ( !*v14 )
      goto LABEL_12;
LABEL_18:
    ++v7;
  }
  while ( (unsigned __int64)v7 < v8 );
  v3 = v42;
LABEL_20:
  v23 = v6->i_array_p;
  v24 = (unsigned __int64)&v23[v6->i_count];
  if ( (unsigned __int64)v23 >= v24 )
    return;
  while ( 2 )
  {
    v25 = *v23;
    v26 = v4->i_count;
    if ( !(_DWORD)v26 )
    {
LABEL_37:
      v37 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      if ( v37 )
      {
        if ( v3 )
        {
          v38 = (SSClassUnaryBase *)v25->i_type_p.i_obj_p;
        }
        else
        {
          v39 = v25->i_type_p.i_obj_p;
          v40 = SSTypeContext::get_variable_type(v5, &v25->i_name, 1);
          v38 = SSClassUnion::get_merge(v39, v40, v41);
        }
        v37->i_name.i_uid = v25->i_name.i_uid;
        v37->i_type_p.i_obj_p = (SSClassDescBase *)&v38->vfptr;
        if ( v38 )
          (*(void (__fastcall **)(SSClassUnaryBase *))v38->vfptr->gap8)(v38);
      }
      else
      {
        v37 = 0i64;
      }
      APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(
        (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v4->i_count,
        v37,
        0i64);
      goto LABEL_46;
    }
    v27 = (signed __int64)v4->i_array_p;
    v28 = v27 + 8 * (v26 - 1);
    v29.i_uid = v25->i_name.i_uid;
    while ( 2 )
    {
      while ( 2 )
      {
        v30 = (unsigned int **)(v27 + 8 * ((v28 - v27) >> 4));
        v31 = **v30;
        if ( v29.i_uid < v31 )
        {
LABEL_28:
          if ( (unsigned int **)v27 == v30 )
            goto LABEL_37;
          v28 = (signed __int64)(v30 - 1);
          continue;
        }
        break;
      }
      v32 = v29.i_uid != v31;
      if ( v32 )
      {
        if ( v32 >= 0 )
        {
          if ( (unsigned int **)v28 == v30 )
            goto LABEL_37;
          v27 = (signed __int64)(v30 + 1);
          continue;
        }
        goto LABEL_28;
      }
      break;
    }
    v33 = (SSClassDescBase **)*v30;
    if ( !*v30 )
      goto LABEL_37;
    v34 = SSClassUnion::get_merge(v33[1], v25->i_type_p.i_obj_p, 0i64);
    v35 = v34;
    if ( v33[1] != (SSClassDescBase *)v34 )
    {
      if ( v34 )
        (*(void (__fastcall **)(SSClassUnaryBase *))v34->vfptr->gap8)(v34);
      v36 = v33[1];
      if ( v36 )
        (*(void (__cdecl **)(SSClassDescBase *))&v36->vfptr->gap8[8])(v36);
      v33[1] = (SSClassDescBase *)&v35->vfptr;
    }
LABEL_46:
    ++v23;
    v3 = v42;
    if ( (unsigned __int64)v23 < v24 )
      continue;
    break;
  }
}

