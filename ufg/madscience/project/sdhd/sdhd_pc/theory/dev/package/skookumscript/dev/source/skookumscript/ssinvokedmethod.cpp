// File Line: 40
// RVA: 0x10F170
SSInstance *__fastcall SSInvokedMethod::as_instance(SSInvokedMethod *this)
{
  return SSInstance::pool_new(SSBrain::c_invoked_method_class_p, (unsigned __int64)this, this->i_ptr_id);
}

// File Line: 58
// RVA: 0x109690
void __fastcall SSInvokedMethod::abort_invoke(
        SSInvokedMethod *this,
        eSSNotify notify_caller,
        eSSNotifyChild notify_child)
{
  this->i_pending_count = 0;
  if ( notify_child == SSNotifyChild_abort )
    SSInvokedBase::abort_subcalls(this, notify_caller);
  else
    SSInvokedBase::detach_subcalls(this, notify_caller);
  SSInvokedMethod::pool_delete(this);
}

// File Line: 98
// RVA: 0x118F10
AObjReusePool<SSInvokedMethod> *__fastcall SSInvokedMethod::get_pool()
{
  unsigned int i_pool_incr_imethod; // edi
  unsigned int i_pool_init_imethod; // ebx
  SSInvokedMethod **v2; // rax

  if ( (_S8_3 & 1) != 0 )
    return &s_pool_4;
  _S8_3 |= 1u;
  i_pool_incr_imethod = Skookum::get_lib_vals()->i_pool_incr_imethod;
  i_pool_init_imethod = Skookum::get_lib_vals()->i_pool_init_imethod;
  s_pool_4.i_pool.i_count = 0;
  unk_142175CE8 = 0i64;
  unk_142175CF0 = 0;
  if ( i_pool_init_imethod )
  {
    unk_142175CF0 = i_pool_init_imethod;
    v2 = APArrayBase<SSInvokedMethod>::alloc_array(i_pool_init_imethod);
  }
  else
  {
    unk_142175CF0 = 0;
    v2 = (SSInvokedMethod **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  unk_142175CE8 = v2;
  qword_142175CF8 = 0i64;
  unk_142175D00 = 0;
  qword_142175D08 = 0i64;
  unk_142175D10 = 0;
  stru_142175D18.i_count = 0;
  stru_142175D18.i_array_p = 0i64;
  stru_142175D18.i_size = 0;
  unk_142175D30 = i_pool_incr_imethod;
  AObjReusePool<SSInvokedMethod>::append_block(&s_pool_4, i_pool_init_imethod);
  atexit(SSInvokedMethod::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_4;
}

// File Line: 137
// RVA: 0x117AA0
__int64 __fastcall SSInvokedMethod::get_invoke_type(SSInvokedMethod *this)
{
  return ((__int64 (__fastcall *)(SSMethodBase *))this->i_method_p->vfptr->get_invoke_type)(this->i_method_p);
}

// File Line: 147
// RVA: 0x117A80
const char *__fastcall SSInvokedMethod::get_invokable(UFG::UIMapBlip *this)
{
  return this->mWorldMapCaption;
}

// File Line: 157
// RVA: 0x135F00
void SSInvokedMethod::register_atomic(void)
{
  __int64 i_count; // rax
  SSMethodBase **i_array_p; // r8
  SSMethodBase **v2; // r10
  SSMethodBase **v3; // rdx
  unsigned int i_uid; // r9d
  SSMethodBase *v5; // rbx
  SSClass *i_scope_p; // rbp
  SSParameters *i_obj_p; // rdi
  SSParameters *v8; // rsi
  bool v9; // zf

  i_count = SSBrain::c_invoked_method_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_invoked_method_class_p->i_methods.i_array_p;
    v2 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v3 = &i_array_p[((char *)v2 - (char *)i_array_p) >> 4];
        i_uid = (*v3)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= i_uid )
          break;
        if ( i_array_p == v3 )
          goto LABEL_10;
        v2 = v3 - 1;
      }
      if ( ASymbol_String.i_uid == i_uid )
        break;
      if ( v2 == v3 )
        goto LABEL_10;
      i_array_p = v3 + 1;
    }
    v5 = *v3;
  }
  else
  {
LABEL_10:
    v5 = 0i64;
  }
  if ( v5 )
  {
    if ( v5->vfptr->get_invoke_type(v5) == SSInvokable_method_func )
    {
      v5[1].vfptr = (SSInvokableBaseVtbl *)SSInvokedMethod::mthd_String;
    }
    else
    {
      i_scope_p = v5->i_scope_p;
      i_obj_p = v5->i_params_p.i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v8 = v5->i_params_p.i_obj_p;
      if ( v8 )
      {
        v9 = v8->i_ref_count-- == 1;
        if ( v9 )
        {
          v8->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v8);
          AMemory::c_free_func(v8);
        }
        v5->i_params_p.i_obj_p = 0i64;
      }
      v5->i_name = ASymbol_String;
      v5->i_scope_p = i_scope_p;
      v5->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v5->i_params_p.i_obj_p = i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v5->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v5->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v5[1].vfptr = (SSInvokableBaseVtbl *)SSInvokedMethod::mthd_String;
      if ( i_obj_p )
      {
        v9 = i_obj_p->i_ref_count-- == 1;
        if ( v9 )
        {
          i_obj_p->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(i_obj_p);
          AMemory::c_free_func(i_obj_p);
        }
      }
    }
  }
}

// File Line: 170
// RVA: 0x1203F0
void __fastcall SSInvokedMethod::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rcx
  const char *v5; // rdi
  __int64 v6; // rbx
  unsigned int v7; // eax
  AStringRef *v8; // rbx
  SSInstance *v9; // rax
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v14; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( !vfptr || i_obj_p[2].i_ptr_id != LODWORD(vfptr->get_obj_type) )
      vfptr = 0i64;
    v5 = "InvokedMethod[stale]";
    if ( vfptr )
      v5 = "InvokedMethod";
    v6 = -1i64;
    do
      ++v6;
    while ( v5[v6] );
    v7 = AMemory::c_req_byte_size_func(v6 + 1);
    v8 = AStringRef::pool_new(v5, v6, v7, 1u, 0, 1);
    v9 = SSInstance::pool_new(SSBrain::c_string_class_p);
    if ( v9 != (SSInstance *)-32i64 )
    {
      v9->i_user_data = (unsigned __int64)v8;
      ++v8->i_ref_count;
    }
    *result_pp = v9;
    if ( v8->i_ref_count-- == 1 )
    {
      if ( v8->i_deallocate )
        AMemory::c_free_func(v8->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v8 < i_objects_a
        || (v14 = (unsigned __int64)v8 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v14) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v8);
    }
  }
}

// File Line: 200
// RVA: 0x1095C0
void __fastcall SSInvokedDeferrableMethod::abort_invoke(
        SSInvokedDeferrableMethod *this,
        eSSNotify notify_caller,
        eSSNotifyChild notify_child)
{
  SSMethodBase *i_method_p; // rcx

  this->i_pending_count = 0;
  if ( notify_child == SSNotifyChild_abort )
    SSInvokedBase::abort_subcalls(this, notify_caller);
  else
    SSInvokedBase::detach_subcalls(this, notify_caller);
  ADebug::print_format("[Background Code aborted - invoked method 0x%p]\n", this);
  i_method_p = this->i_method_p;
  if ( i_method_p )
    i_method_p->vfptr->__vecDelDtor(i_method_p, 1u);
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 221
// RVA: 0x130470
void __fastcall SSInvokedDeferrableMethod::pending_return(SSInvokedDeferrableMethod *this, bool completed)
{
  SSMethodBase *i_method_p; // rcx

  if ( this->i_pending_count-- == 1 )
  {
    ADebug::print_format("[Background Code completed - invoked method 0x%p]\n", this);
    i_method_p = this->i_method_p;
    if ( i_method_p )
      i_method_p->vfptr->__vecDelDtor(i_method_p, 1u);
    this->vfptr->__vecDelDtor(this, 1i64);
  }
}

// File Line: 249
// RVA: 0x1094D0
void __fastcall SSIExternalMethodCallWrapper::abort_invoke(
        SSIExternalMethodCallWrapper *this,
        eSSNotify notify_caller,
        eSSNotifyChild notify_child)
{
  this->i_pending_count = 0;
  if ( notify_child == SSNotifyChild_abort )
    SSInvokedBase::abort_subcalls(this, notify_caller);
  else
    SSInvokedBase::detach_subcalls(this, notify_caller);
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 266
// RVA: 0x130320
void __fastcall SSIExternalMethodCallWrapper::pending_return(SSIExternalMethodCallWrapper *this, bool completed)
{
  if ( this->i_pending_count-- == 1 )
    this->vfptr->__vecDelDtor(this, 1i64);
}

