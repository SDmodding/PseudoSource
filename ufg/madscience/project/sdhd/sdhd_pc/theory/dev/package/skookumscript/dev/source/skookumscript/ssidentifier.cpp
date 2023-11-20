// File Line: 140
// RVA: 0x11D120
SSInvokedBase *__fastcall SSIdentifier::invoke(SSIdentifier *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance **v4; // rbx
  SSInstance *v5; // rax

  v4 = result_pp;
  if ( result_pp )
  {
    v5 = scope_p->vfptr->get_data_by_name(scope_p, &this->i_ident_name);
    ++v5->i_ref_count;
    *v4 = v5;
  }
  return 0i64;
}

// File Line: 204
// RVA: 0x111710
void __fastcall SSIdentifier::bind_data(SSIdentifier *this, SSInstance *data_p, SSObjectBase *scope_p, SSInvokedBase *caller_p, bool return_result)
{
  scope_p->vfptr->set_data_by_name(scope_p, &this->i_ident_name, data_p);
}

// File Line: 215
// RVA: 0x13DD60
void __fastcall SSIdentifier::track_memory(SSIdentifier *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSIdentifier", 0x10u, 8u, 0, 0, 1u);
}

// File Line: 229
// RVA: 0x107050
void __fastcall SSIdentifierMember::~SSIdentifierMember(SSIdentifierMember *this)
{
  SSIdentifierMember *v1; // rbx
  SSExpressionBase *v2; // rcx

  v1 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierMember::`vftable';
  v2 = this->i_owner_p;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v1->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
}

// File Line: 422
// RVA: 0x11F020
_BOOL8 __fastcall SSIdentifierMember::is_local(SSIdentifierMember *this)
{
  return this->i_owner_p == 0i64;
}

// File Line: 449
// RVA: 0x11D220
SSInvokedBase *__fastcall SSIdentifierMember::invoke(SSIdentifierMember *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSIdentifierMember *v4; // rdi
  SSExpressionBase *v5; // rcx
  SSInstance **v6; // rsi
  _DWORD *v7; // rbx
  __int64 v8; // rax
  bool v9; // zf
  SSInvokedBase *result; // rax
  _DWORD *v11; // [rsp+48h] [rbp+20h]

  v4 = this;
  v5 = this->i_owner_p;
  v6 = result_pp;
  if ( result_pp )
  {
    if ( v5 )
    {
      v5->vfptr->invoke(v5, scope_p, caller_p, (SSInstance **)&v11);
      v7 = v11;
    }
    else
    {
      v7 = (_DWORD *)((__int64 (__fastcall *)(SSObjectBase *, SSObjectBase *, SSInvokedBase *))scope_p->vfptr->get_topmost_scope)(
                       scope_p,
                       scope_p,
                       caller_p);
    }
    v8 = (*(__int64 (__fastcall **)(_DWORD *, ASymbol *))(*(_QWORD *)v7 + 32i64))(v7, &v4->i_ident_name);
    ++*(_DWORD *)(v8 + 16);
    *v6 = (SSInstance *)v8;
    if ( v4->i_owner_p )
    {
      v9 = v7[4]-- == 1;
      if ( v9 )
      {
        v7[4] = 2147483648;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v7 + 112i64))(v7);
      }
    }
    result = 0i64;
  }
  else
  {
    if ( v5 )
      v5->vfptr->invoke(v5, scope_p, caller_p, 0i64);
    result = 0i64;
  }
  return result;
}

// File Line: 535
// RVA: 0x1117E0
void __fastcall SSIdentifierMember::bind_data(SSIdentifierMember *this, SSInstance *data_p, SSObjectBase *scope_p, SSInvokedBase *caller_p, bool return_result)
{
  SSIdentifierMember *v5; // rsi
  SSExpressionBase *v6; // rcx
  SSInstance *v7; // rdi
  SSInstance *v8; // rbx
  bool v9; // zf
  SSInstance *v10; // [rsp+30h] [rbp+8h]

  v5 = this;
  v6 = this->i_owner_p;
  v7 = data_p;
  if ( v6 )
  {
    v6->vfptr->invoke(v6, scope_p, caller_p, &v10);
    v8 = v10;
  }
  else
  {
    v8 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  v8->vfptr->set_data_by_name((SSObjectBase *)&v8->vfptr, &v5->i_ident_name, v7);
  if ( v5->i_owner_p )
  {
    if ( return_result )
    {
      ++v7->i_ref_count;
      v9 = v8->i_ref_count-- == 1;
      if ( v9 )
      {
        v8->i_ref_count = 2147483648;
        v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
      }
      --v7->i_ref_count;
    }
    else
    {
      v9 = v8->i_ref_count-- == 1;
      if ( v9 )
      {
        v8->i_ref_count = 2147483648;
        v8->vfptr[1].get_scope_context((SSObjectBase *)&v8->vfptr);
      }
    }
  }
}

// File Line: 624
// RVA: 0x13DE00
void __fastcall SSIdentifierMember::track_memory(SSIdentifierMember *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSIdentifierMember *v3; // rbx
  SSExpressionBase *v4; // rcx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSIdentifierMember", 0x18u, 8u, 0, 0, 1u);
  v4 = v3->i_owner_p;
  if ( v4 )
    v4->vfptr->track_memory(v4, v2);
}

// File Line: 708
// RVA: 0x11D150
SSInvokedBase *__fastcall SSIdentifierClassMember::invoke(SSIdentifierClassMember *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSIdentifierClassMember *v4; // rdi
  SSExpressionBase *v5; // rcx
  SSInstance **v6; // rsi
  __int64 v7; // rbx
  signed __int64 v8; // rax
  __int64 v9; // rax
  bool v10; // zf
  SSInvokedBase *result; // rax
  __int64 v12; // [rsp+48h] [rbp+20h]

  v4 = this;
  v5 = this->i_owner_p;
  v6 = result_pp;
  if ( result_pp )
  {
    if ( v5 )
    {
      v5->vfptr->invoke(v5, scope_p, caller_p, (SSInstance **)&v12);
      v7 = v12;
    }
    else
    {
      v7 = ((__int64 (__fastcall *)(SSObjectBase *, SSObjectBase *, SSInvokedBase *))scope_p->vfptr->get_topmost_scope)(
             scope_p,
             scope_p,
             caller_p);
    }
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 64i64))(v7) )
      v8 = v7 - 8;
    else
      v8 = (*(__int64 (**)(void))(**(_QWORD **)(v7 + 24) + 136i64))();
    v9 = (*(__int64 (__fastcall **)(signed __int64, ASymbol *))(*(_QWORD *)(v8 + 8) + 32i64))(v8 + 8, &v4->i_ident_name);
    ++*(_DWORD *)(v9 + 16);
    *v6 = (SSInstance *)v9;
    if ( v4->i_owner_p )
    {
      v10 = (*(_DWORD *)(v7 + 16))-- == 1;
      if ( v10 )
      {
        *(_DWORD *)(v7 + 16) = 2147483648;
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 112i64))(v7);
      }
    }
    result = 0i64;
  }
  else
  {
    if ( v5 )
      v5->vfptr->invoke(v5, scope_p, caller_p, 0i64);
    result = 0i64;
  }
  return result;
}

// File Line: 773
// RVA: 0x111730
void __fastcall SSIdentifierClassMember::bind_data(SSIdentifierClassMember *this, SSInstance *data_p, SSObjectBase *scope_p, SSInvokedBase *caller_p)
{
  SSIdentifierClassMember *v4; // rdi
  SSExpressionBase *v5; // rcx
  SSInstance *v6; // rsi
  SSInstance *v7; // rbx
  signed __int64 v8; // rax
  bool v9; // zf
  SSInstance *v10; // [rsp+30h] [rbp+8h]

  v4 = this;
  v5 = this->i_owner_p;
  v6 = data_p;
  if ( v5 )
  {
    v5->vfptr->invoke(v5, scope_p, caller_p, &v10);
    v7 = v10;
  }
  else
  {
    v7 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  if ( ((unsigned __int8 (__fastcall *)(SSInstance *))v7->vfptr[1].__vecDelDtor)(v7) )
    v8 = (signed __int64)&v7[-1].i_user_data2;
  else
    v8 = ((__int64 (*)(void))v7->i_class_p->vfptr->get_metaclass)();
  (*(void (__fastcall **)(signed __int64, ASymbol *, SSInstance *))(*(_QWORD *)(v8 + 8) + 40i64))(
    v8 + 8,
    &v4->i_ident_name,
    v6);
  if ( v4->i_owner_p )
  {
    v9 = v7->i_ref_count-- == 1;
    if ( v9 )
    {
      v7->i_ref_count = 2147483648;
      v7->vfptr[1].get_scope_context((SSObjectBase *)&v7->vfptr);
    }
  }
}

// File Line: 849
// RVA: 0x13DDA0
void __fastcall SSIdentifierClassMember::track_memory(SSIdentifierClassMember *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSIdentifierClassMember *v3; // rbx
  SSExpressionBase *v4; // rcx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSIdentifierClassMember", 0x18u, 8u, 0, 0, 1u);
  v4 = v3->i_owner_p;
  if ( v4 )
    v4->vfptr->track_memory(v4, v2);
}

