// File Line: 40
// RVA: 0x10F170
SSInstance *__fastcall SSInvokedMethod::as_instance(SSInvokedMethod *this)
{
  return SSInstance::pool_new(SSBrain::c_invoked_method_class_p, (unsigned __int64)this, this->i_ptr_id);
}

// File Line: 58
// RVA: 0x109690
void __fastcall SSInvokedMethod::abort_invoke(SSInvokedMethod *this, eSSNotify notify_caller, eSSNotifyChild notify_child)
{
  SSInvokedMethod *v3; // rbx

  v3 = this;
  this->i_pending_count = 0;
  if ( notify_child == 1 )
    SSInvokedBase::abort_subcalls((SSInvokedBase *)&this->vfptr, notify_caller);
  else
    SSInvokedBase::detach_subcalls((SSInvokedBase *)&this->vfptr, notify_caller);
  SSInvokedMethod::pool_delete(v3);
}

// File Line: 98
// RVA: 0x118F10
AObjReusePool<SSInvokedMethod> *__fastcall SSInvokedMethod::get_pool()
{
  unsigned int v0; // edi
  unsigned int v1; // ebx
  SSInvokedMethod **v2; // rax

  if ( _S8_3 & 1 )
    return &s_pool_4;
  _S8_3 |= 1u;
  v0 = Skookum::get_lib_vals()->i_pool_incr_imethod;
  v1 = Skookum::get_lib_vals()->i_pool_init_imethod;
  s_pool_4.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175CE8 = 0i64;
  unk_142175CF0 = 0;
  if ( v1 )
  {
    unk_142175CF0 = v1;
    v2 = APArrayBase<SSInvokedMethod>::alloc_array(v1);
  }
  else
  {
    unk_142175CF0 = 0;
    v2 = (SSInvokedMethod **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  *(_QWORD *)&dword_142175CE8 = v2;
  qword_142175CF8 = 0i64;
  unk_142175D00 = 0;
  qword_142175D08 = 0i64;
  unk_142175D10 = 0;
  stru_142175D18.i_count = 0;
  stru_142175D18.i_array_p = 0i64;
  stru_142175D18.i_size = 0;
  unk_142175D30 = v0;
  AObjReusePool<SSInvokedMethod>::append_block(&s_pool_4, v1);
  atexit(SSInvokedMethod::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_4;
}

// File Line: 137
// RVA: 0x117AA0
__int64 __fastcall SSInvokedMethod::get_invoke_type(SSInvokedMethod *this)
{
  return ((__int64 (*)(void))this->i_method_p->vfptr->get_invoke_type)();
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
  __int64 v0; // rax
  SSMethodBase **v1; // r8
  signed __int64 v2; // r10
  signed __int64 v3; // rdx
  unsigned int v4; // er9
  _BOOL8 v5; // r9
  __int64 v6; // rbx
  __int64 v7; // rbp
  SSParameters *v8; // rdi
  SSParameters *v9; // rsi
  bool v10; // zf

  v0 = SSBrain::c_invoked_method_class_p->i_methods.i_count;
  if ( (_DWORD)v0 )
  {
    v1 = SSBrain::c_invoked_method_class_p->i_methods.i_array_p;
    v2 = (signed __int64)&v1[v0 - 1];
    while ( 1 )
    {
      v3 = (signed __int64)&v1[(v2 - (signed __int64)v1) >> 4];
      v4 = *(_DWORD *)(*(_QWORD *)v3 + 8i64);
      if ( ASymbol_String.i_uid < v4 )
        goto LABEL_28;
      v5 = ASymbol_String.i_uid != v4;
      if ( !v5 )
      {
        v6 = *(_QWORD *)v3;
        goto LABEL_12;
      }
      if ( v5 < 0 )
      {
LABEL_28:
        if ( v1 == (SSMethodBase **)v3 )
          break;
        v2 = v3 - 8;
      }
      else
      {
        if ( v2 == v3 )
          break;
        v1 = (SSMethodBase **)(v3 + 8);
      }
    }
  }
  v6 = 0i64;
LABEL_12:
  if ( v6 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6) == 1 )
    {
      *(_QWORD *)(v6 + 32) = SSInvokedMethod::mthd_String;
    }
    else
    {
      v7 = *(_QWORD *)(v6 + 16);
      v8 = *(SSParameters **)(v6 + 24);
      if ( v8 )
        ++v8->i_ref_count;
      v9 = *(SSParameters **)(v6 + 24);
      if ( v9 )
      {
        v10 = v9->i_ref_count-- == 1;
        if ( v10 )
        {
          v9->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v9);
          AMemory::c_free_func(v9);
        }
        *(_QWORD *)(v6 + 24) = 0i64;
      }
      *(ASymbol *)(v6 + 8) = ASymbol_String;
      *(_QWORD *)(v6 + 16) = v7;
      *(_QWORD *)v6 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v6 + 24) = v8;
      if ( v8 )
        ++v8->i_ref_count;
      *(_QWORD *)v6 = &SSMethodBase::`vftable;
      *(_QWORD *)v6 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v6 + 32) = SSInvokedMethod::mthd_String;
      if ( v8 )
      {
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v8);
          AMemory::c_free_func(v8);
        }
      }
    }
  }
}

// File Line: 170
// RVA: 0x1203F0
void __fastcall SSInvokedMethod::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rsi
  SSObjectBase *v3; // r8
  SSObjectBaseVtbl *v4; // rcx
  const char *v5; // rdi
  signed __int64 v6; // rbx
  unsigned int v7; // eax
  AStringRef *v8; // rbx
  SSInstance *v9; // rax
  bool v10; // zf
  AObjReusePool<AStringRef> *v11; // rax
  AObjBlock<AStringRef> *v12; // rcx
  unsigned __int64 v13; // r8
  bool v14; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v15; // rcx

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    if ( !v4 || v3[2].i_ptr_id != LODWORD(v4->get_obj_type) )
      v4 = 0i64;
    v5 = "InvokedMethod[stale]";
    if ( v4 )
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
    *v2 = v9;
    v10 = v8->i_ref_count-- == 1;
    if ( v10 )
    {
      if ( v8->i_deallocate )
        AMemory::c_free_func(v8->i_cstr_p);
      v11 = AStringRef::get_pool();
      v12 = v11->i_block_p;
      v13 = (unsigned __int64)v12->i_objects_a;
      if ( (unsigned __int64)v8 < v13
        || (v14 = (unsigned __int64)v8 < v13 + 24i64 * v12->i_size, v15 = &v11->i_pool, !v14) )
      {
        v15 = &v11->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v15, v8);
    }
  }
}

// File Line: 200
// RVA: 0x1095C0
void __fastcall SSInvokedDeferrableMethod::abort_invoke(SSInvokedDeferrableMethod *this, eSSNotify notify_caller, eSSNotifyChild notify_child)
{
  SSInvokedDeferrableMethod *v3; // rbx
  SSMethodBase *v4; // rcx

  v3 = this;
  this->i_pending_count = 0;
  if ( notify_child == 1 )
    SSInvokedBase::abort_subcalls((SSInvokedBase *)&this->vfptr, notify_caller);
  else
    SSInvokedBase::detach_subcalls((SSInvokedBase *)&this->vfptr, notify_caller);
  ADebug::print_format("[Background Code aborted - invoked method 0x%p]\n", v3);
  v4 = v3->i_method_p;
  if ( v4 )
    v4->vfptr->__vecDelDtor((SSInvokableBase *)&v4->vfptr, 1u);
  v3->vfptr->__vecDelDtor((SSObjectBase *)&v3->vfptr, 1u);
}

// File Line: 221
// RVA: 0x130470
void __fastcall SSInvokedDeferrableMethod::pending_return(SSInvokedDeferrableMethod *this, bool completed)
{
  bool v2; // zf
  SSInvokedDeferrableMethod *v3; // rbx
  SSMethodBase *v4; // rcx

  v2 = this->i_pending_count-- == 1;
  v3 = this;
  if ( v2 )
  {
    ADebug::print_format("[Background Code completed - invoked method 0x%p]\n", this);
    v4 = v3->i_method_p;
    if ( v4 )
      v4->vfptr->__vecDelDtor((SSInvokableBase *)&v4->vfptr, 1u);
    v3->vfptr->__vecDelDtor((SSObjectBase *)&v3->vfptr, 1u);
  }
}

// File Line: 249
// RVA: 0x1094D0
void __fastcall SSIExternalMethodCallWrapper::abort_invoke(SSIExternalMethodCallWrapper *this, eSSNotify notify_caller, eSSNotifyChild notify_child)
{
  SSIExternalMethodCallWrapper *v3; // rbx

  v3 = this;
  this->i_pending_count = 0;
  if ( notify_child == 1 )
    SSInvokedBase::abort_subcalls((SSInvokedBase *)&this->vfptr, notify_caller);
  else
    SSInvokedBase::detach_subcalls((SSInvokedBase *)&this->vfptr, notify_caller);
  v3->vfptr->__vecDelDtor((SSObjectBase *)&v3->vfptr, 1u);
}

// File Line: 266
// RVA: 0x130320
void __fastcall SSIExternalMethodCallWrapper::pending_return(SSIExternalMethodCallWrapper *this, bool completed)
{
  bool v2; // zf

  v2 = this->i_pending_count-- == 1;
  if ( v2 )
    this->vfptr->__vecDelDtor((SSObjectBase *)this, 1u);
}

