// File Line: 140
// RVA: 0x11D120
SSInvokedBase *__fastcall SSIdentifier::invoke(
        SSIdentifier *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInstance *v5; // rax

  if ( result_pp )
  {
    v5 = scope_p->vfptr->get_data_by_name(scope_p, &this->i_ident_name);
    ++v5->i_ref_count;
    *result_pp = v5;
  }
  return 0i64;
}

// File Line: 204
// RVA: 0x111710
void __fastcall SSIdentifier::bind_data(
        SSIdentifier *this,
        SSInstance *data_p,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        bool return_result)
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
  SSExpressionBase *i_owner_p; // rcx

  this->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierMember::`vftable;
  i_owner_p = this->i_owner_p;
  if ( i_owner_p )
    i_owner_p->vfptr->__vecDelDtor(i_owner_p, 1u);
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 422
// RVA: 0x11F020
_BOOL8 __fastcall SSIdentifierMember::is_local(SSIdentifierMember *this)
{
  return this->i_owner_p == 0i64;
}

// File Line: 449
// RVA: 0x11D220
SSInvokedBase *__fastcall SSIdentifierMember::invoke(
        SSIdentifierMember *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSExpressionBase *i_owner_p; // rcx
  SSInstance *v7; // rbx
  SSInstance *v8; // rax
  SSInstance *v11; // [rsp+48h] [rbp+20h] BYREF

  i_owner_p = this->i_owner_p;
  if ( result_pp )
  {
    if ( i_owner_p )
    {
      i_owner_p->vfptr->invoke(i_owner_p, scope_p, caller_p, &v11);
      v7 = v11;
    }
    else
    {
      v7 = scope_p->vfptr->get_topmost_scope(scope_p);
    }
    v8 = v7->vfptr->get_data_by_name(v7, &this->i_ident_name);
    ++v8->i_ref_count;
    *result_pp = v8;
    if ( this->i_owner_p )
    {
      if ( v7->i_ref_count-- == 1 )
      {
        v7->i_ref_count = 0x80000000;
        v7->vfptr[1].get_scope_context(v7);
      }
    }
    return 0i64;
  }
  else
  {
    if ( i_owner_p )
      i_owner_p->vfptr->invoke(i_owner_p, scope_p, caller_p, 0i64);
    return 0i64;
  }
}

// File Line: 535
// RVA: 0x1117E0
void __fastcall SSIdentifierMember::bind_data(
        SSIdentifierMember *this,
        SSInstance *data_p,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        bool return_result)
{
  SSExpressionBase *i_owner_p; // rcx
  SSInstance *v8; // rbx
  bool v9; // zf
  SSInstance *v10; // [rsp+30h] [rbp+8h] BYREF

  i_owner_p = this->i_owner_p;
  if ( i_owner_p )
  {
    i_owner_p->vfptr->invoke(i_owner_p, scope_p, caller_p, &v10);
    v8 = v10;
  }
  else
  {
    v8 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  v8->vfptr->set_data_by_name(v8, &this->i_ident_name, data_p);
  if ( this->i_owner_p )
  {
    if ( return_result )
    {
      ++data_p->i_ref_count;
      v9 = v8->i_ref_count-- == 1;
      if ( v9 )
      {
        v8->i_ref_count = 0x80000000;
        v8->vfptr[1].get_scope_context(v8);
      }
      --data_p->i_ref_count;
    }
    else
    {
      v9 = v8->i_ref_count-- == 1;
      if ( v9 )
      {
        v8->i_ref_count = 0x80000000;
        v8->vfptr[1].get_scope_context(v8);
      }
    }
  }
}

// File Line: 624
// RVA: 0x13DE00
void __fastcall SSIdentifierMember::track_memory(SSIdentifierMember *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase *i_owner_p; // rcx

  AMemoryStats::track_memory(mem_stats_p, "SSIdentifierMember", 0x18u, 8u, 0, 0, 1u);
  i_owner_p = this->i_owner_p;
  if ( i_owner_p )
    i_owner_p->vfptr->track_memory(i_owner_p, mem_stats_p);
}

// File Line: 708
// RVA: 0x11D150
SSInvokedBase *__fastcall SSIdentifierClassMember::invoke(
        SSIdentifierClassMember *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSExpressionBase *i_owner_p; // rcx
  SSInstance *v7; // rbx
  __int64 p_i_user_data2; // rax
  SSInstance *v9; // rax
  SSInstance *v12; // [rsp+48h] [rbp+20h] BYREF

  i_owner_p = this->i_owner_p;
  if ( result_pp )
  {
    if ( i_owner_p )
    {
      i_owner_p->vfptr->invoke(i_owner_p, scope_p, caller_p, &v12);
      v7 = v12;
    }
    else
    {
      v7 = scope_p->vfptr->get_topmost_scope(scope_p);
    }
    if ( ((unsigned __int8 (__fastcall *)(SSInstance *))v7->vfptr[1].__vecDelDtor)(v7) )
      p_i_user_data2 = (__int64)&v7[-1].i_user_data2;
    else
      p_i_user_data2 = (__int64)v7->i_class_p->vfptr->get_metaclass(v7->i_class_p);
    v9 = (SSInstance *)(*(__int64 (__fastcall **)(__int64, ASymbol *))(*(_QWORD *)(p_i_user_data2 + 8) + 32i64))(
                         p_i_user_data2 + 8,
                         &this->i_ident_name);
    ++v9->i_ref_count;
    *result_pp = v9;
    if ( this->i_owner_p )
    {
      if ( v7->i_ref_count-- == 1 )
      {
        v7->i_ref_count = 0x80000000;
        v7->vfptr[1].get_scope_context(v7);
      }
    }
    return 0i64;
  }
  else
  {
    if ( i_owner_p )
      i_owner_p->vfptr->invoke(i_owner_p, scope_p, caller_p, 0i64);
    return 0i64;
  }
}

// File Line: 773
// RVA: 0x111730
void __fastcall SSIdentifierClassMember::bind_data(
        SSIdentifierClassMember *this,
        SSInstance *data_p,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p)
{
  SSExpressionBase *i_owner_p; // rcx
  SSInstance *v7; // rbx
  __int64 p_i_user_data2; // rax
  SSInstance *v10; // [rsp+30h] [rbp+8h] BYREF

  i_owner_p = this->i_owner_p;
  if ( i_owner_p )
  {
    i_owner_p->vfptr->invoke(i_owner_p, scope_p, caller_p, &v10);
    v7 = v10;
  }
  else
  {
    v7 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  if ( ((unsigned __int8 (__fastcall *)(SSInstance *))v7->vfptr[1].__vecDelDtor)(v7) )
    p_i_user_data2 = (__int64)&v7[-1].i_user_data2;
  else
    p_i_user_data2 = (__int64)v7->i_class_p->vfptr->get_metaclass(v7->i_class_p);
  (*(void (__fastcall **)(__int64, ASymbol *, SSInstance *))(*(_QWORD *)(p_i_user_data2 + 8) + 40i64))(
    p_i_user_data2 + 8,
    &this->i_ident_name,
    data_p);
  if ( this->i_owner_p )
  {
    if ( v7->i_ref_count-- == 1 )
    {
      v7->i_ref_count = 0x80000000;
      v7->vfptr[1].get_scope_context(v7);
    }
  }
}

// File Line: 849
// RVA: 0x13DDA0
void __fastcall SSIdentifierClassMember::track_memory(SSIdentifierClassMember *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase *i_owner_p; // rcx

  AMemoryStats::track_memory(mem_stats_p, "SSIdentifierClassMember", 0x18u, 8u, 0, 0, 1u);
  i_owner_p = this->i_owner_p;
  if ( i_owner_p )
    i_owner_p->vfptr->track_memory(i_owner_p, mem_stats_p);
}

