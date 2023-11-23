// File Line: 56
// RVA: 0x1058D0
void __fastcall SSInvokedCoroutine::SSInvokedCoroutine(SSInvokedCoroutine *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_prev_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
  this->i_next_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedBase::`vftable;
  this->i_scope_p.i_obj_p = 0i64;
  this->i_scope_p.i_ptr_id = 0;
  this->i_caller_p.i_obj_p = 0i64;
  this->i_caller_p.i_ptr_id = 0;
  this->i_calls.i_sentinel.i_prev_p = &this->i_calls.i_sentinel;
  this->i_calls.i_sentinel.SSInvokedContextBase::SSInvokedBase::i_next_p = &this->i_calls.i_sentinel;
  this->i_pending_count = 0;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedContextBase::`vftable;
  this->i_data.i_count = 0;
  this->i_data.i_array_p = 0i64;
  this->i_data.i_size = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedCoroutine::`vftable;
  *(_QWORD *)&this->i_update_count = 0i64;
  this->i_update_next = SkookumScript::c_sim_time;
  this->i_coroutine_p = 0i64;
  this->i_updater_p.i_obj_p = 0i64;
  this->i_updater_p.i_ptr_id = 0;
  this->i_flags = 0;
}

// File Line: 91
// RVA: 0x10F150
SSInstance *__fastcall SSInvokedCoroutine::as_instance(SSInvokedCoroutine *this)
{
  return SSInstance::pool_new(SSBrain::c_invoked_coroutine_class_p, (unsigned __int64)this, this->i_ptr_id);
}

// File Line: 123
// RVA: 0x109520
void __fastcall SSInvokedCoroutine::abort_invoke(
        SSInvokedCoroutine *this,
        eSSNotify notify_caller,
        eSSNotifyChild notify_child)
{
  unsigned int i_ptr_id; // eax
  SSActor *i_obj_p; // rdi

  i_ptr_id = this->i_ptr_id;
  if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
  {
    if ( (this->i_flags & 3) != 0 )
    {
      i_obj_p = this->i_updater_p.i_obj_p;
      if ( i_obj_p )
      {
        if ( this->i_updater_p.i_ptr_id == i_obj_p->i_ptr_id )
        {
          SSActor::coroutine_track_updating_stop(this->i_updater_p.i_obj_p, this);
          SSActor::coroutine_track_pending_stop(i_obj_p, this);
        }
      }
    }
    this->i_pending_count = 0;
    if ( notify_child == SSNotifyChild_abort )
      SSInvokedBase::abort_subcalls(this, notify_caller);
    else
      SSInvokedBase::detach_subcalls(this, notify_caller);
    SSInvokedCoroutine::pool_delete(this);
  }
}

// File Line: 147
// RVA: 0x11A070
SSActor *__fastcall SSInvokedCoroutine::get_updater(SSInvokedCoroutine *this)
{
  SSActor *i_obj_p; // rcx
  unsigned int i_ptr_id; // edi
  SSInvokedBase *v5; // rcx
  SSActor *v6; // rcx
  SSObjectBase *v7; // rsi
  bool v8; // al

  i_obj_p = this->i_updater_p.i_obj_p;
  if ( i_obj_p && this->i_updater_p.i_ptr_id == i_obj_p->i_ptr_id )
    return i_obj_p;
  i_ptr_id = 0;
  if ( !i_obj_p || i_obj_p->i_ptr_id != this->i_updater_p.i_ptr_id )
    return 0i64;
  v5 = this->i_caller_p.i_obj_p;
  if ( !v5
    || this->i_caller_p.i_ptr_id != v5->i_ptr_id
    || (v6 = (SSActor *)((__int64 (__fastcall *)(SSInvokedBase *))v5->vfptr[1].is_actor)(v5)) == 0i64 )
  {
    v7 = this->i_scope_p.i_obj_p;
    if ( !v7 || this->i_scope_p.i_ptr_id != v7->i_ptr_id )
      v7 = 0i64;
    v8 = v7->vfptr->is_actor(v7);
    v6 = SkookumScript::c_world_p;
    if ( v8 )
      v6 = (SSActor *)v7;
  }
  this->i_updater_p.i_obj_p = v6;
  if ( v6 )
    i_ptr_id = v6->i_ptr_id;
  this->i_updater_p.i_ptr_id = i_ptr_id;
  return v6;
}

// File Line: 188
// RVA: 0x130510
void __fastcall SSInvokedCoroutine::pending_schedule(SSInvokedCoroutine *this, bool completed)
{
  SSCoroutineBase *i_coroutine_p; // rcx
  SSActor *i_obj_p; // rdi
  SSInvokedBase *v5; // rcx
  SSCoroutineCall *i_coroutine_call_p; // rdx

  --this->i_pending_count;
  if ( !completed )
  {
    ((void (__fastcall *)(SSInvokedCoroutine *, __int64, __int64))this->vfptr[1].as_instance)(this, 1i64, 1i64);
    return;
  }
  i_coroutine_p = this->i_coroutine_p;
  if ( !this->i_pending_count )
  {
    i_obj_p = this->i_updater_p.i_obj_p;
    if ( !i_obj_p || this->i_updater_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    if ( i_coroutine_p->vfptr->get_invoke_type(i_coroutine_p) != SSInvokable_coroutine )
    {
      if ( !i_obj_p )
      {
        SSInvokedCoroutine::on_update(this);
        return;
      }
      SSActor::coroutine_track_pending_stop(i_obj_p, this);
      goto LABEL_9;
    }
    v5 = this->i_caller_p.i_obj_p;
    if ( v5 && this->i_caller_p.i_ptr_id == v5->i_ptr_id && v5->i_pending_count )
    {
      this->i_update_count = -1;
      if ( i_obj_p )
LABEL_9:
        SSActor::coroutine_track_updating(i_obj_p, this);
    }
    else
    {
      i_coroutine_call_p = this->i_coroutine_call_p;
      if ( i_coroutine_call_p )
        SSInvokedContextBase::data_bind_return_args(this, &i_coroutine_call_p->i_return_args, this->i_coroutine_p);
      SSInvokedCoroutine::pool_delete(this);
    }
  }
}

// File Line: 262
// RVA: 0x130340
void __fastcall SSInvokedCoroutine::pending_return(SSInvokedCoroutine *this, bool completed)
{
  SSCoroutineBase *i_coroutine_p; // r14
  SSActor *i_obj_p; // rdi
  SSInvokedBase *v5; // rsi
  SSCoroutineCall *i_coroutine_call_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax

  --this->i_pending_count;
  if ( completed )
  {
    i_coroutine_p = this->i_coroutine_p;
    if ( !this->i_pending_count )
    {
      i_obj_p = this->i_updater_p.i_obj_p;
      if ( !i_obj_p || this->i_updater_p.i_ptr_id != i_obj_p->i_ptr_id )
        i_obj_p = 0i64;
      if ( i_coroutine_p->vfptr->get_invoke_type(i_coroutine_p) == SSInvokable_coroutine )
      {
        v5 = this->i_caller_p.i_obj_p;
        if ( !v5 || this->i_caller_p.i_ptr_id != v5->i_ptr_id )
          v5 = 0i64;
        if ( i_obj_p )
          SSActor::coroutine_track_pending_stop(i_obj_p, this);
        i_coroutine_call_p = this->i_coroutine_call_p;
        if ( i_coroutine_call_p )
          SSInvokedContextBase::data_bind_return_args(this, &i_coroutine_call_p->i_return_args, i_coroutine_p);
        if ( v5 && v5->i_pending_count )
        {
          i_next_p = this->i_next_p;
          if ( i_next_p != &this->AListNode<SSInvokedBase,SSInvokedBase> )
          {
            i_prev_p = this->i_prev_p;
            i_next_p->i_prev_p = i_prev_p;
            i_prev_p->i_next_p = i_next_p;
            this->i_prev_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
            this->i_next_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
          }
          LOBYTE(i_next_p) = 1;
          v5->vfptr[1].get_data_by_name(v5, (ASymbol *)i_next_p);
        }
        SSInvokedCoroutine::pool_delete(this);
      }
      else
      {
        if ( i_obj_p )
        {
          SSActor::coroutine_track_pending_stop(i_obj_p, this);
          SSActor::coroutine_track_updating(i_obj_p, this);
        }
        SSInvokedCoroutine::on_update(this);
      }
    }
  }
  else
  {
    ((void (__fastcall *)(SSInvokedCoroutine *, __int64, __int64))this->vfptr[1].as_instance)(this, 1i64, 1i64);
  }
}

// File Line: 328
// RVA: 0x13CCE0
void __fastcall SSInvokedCoroutine::suspend(SSInvokedCoroutine *this)
{
  unsigned int i_flags; // edx
  int v3; // edx
  SSActor *i_obj_p; // rdi

  i_flags = this->i_flags;
  if ( (i_flags & 4) == 0 )
  {
    ++this->i_pending_count;
    v3 = i_flags | 4;
    this->i_flags = v3;
    i_obj_p = this->i_updater_p.i_obj_p;
    if ( i_obj_p )
    {
      if ( this->i_updater_p.i_ptr_id == i_obj_p->i_ptr_id )
      {
        if ( (v3 & 2) == 0 )
        {
          APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
            &i_obj_p->i_icoroutines_pending,
            this);
          this->i_flags |= 2u;
        }
        SSActor::coroutine_track_updating_stop(i_obj_p, this);
      }
    }
  }
}

// File Line: 378
// RVA: 0x126FC0
char __fastcall SSInvokedCoroutine::on_update(SSInvokedCoroutine *this)
{
  SSActor *i_obj_p; // rsi
  SSInvokedBase *v3; // rdi
  SSObjectBase *v4; // rcx
  double i_update_next; // xmm1_8
  SSCoroutineBase *i_coroutine_p; // rcx
  unsigned int i_update_count; // ebp
  SSCoroutineCall *i_coroutine_call_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  bool v12; // bp
  SSCoroutineCall *v13; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v14; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v15; // rcx

  i_obj_p = this->i_updater_p.i_obj_p;
  if ( !i_obj_p || this->i_updater_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  v3 = this->i_caller_p.i_obj_p;
  if ( !v3 || this->i_caller_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( i_obj_p )
  {
    if ( this->i_update_count != -1 )
    {
      v4 = this->i_scope_p.i_obj_p;
      if ( v4 )
      {
        if ( v4->i_ptr_id == this->i_scope_p.i_ptr_id )
        {
          i_update_next = this->i_update_next;
          if ( i_update_next <= SkookumScript::c_sim_time )
          {
            i_coroutine_p = this->i_coroutine_p;
            this->i_update_next = this->i_update_interval + i_update_next;
            if ( i_coroutine_p
              && ((unsigned __int8 (__fastcall *)(SSCoroutineBase *, SSInvokedCoroutine *))i_coroutine_p->vfptr[1].get_custom_expr)(
                   i_coroutine_p,
                   this) )
            {
              i_update_count = this->i_update_count;
              SSActor::coroutine_track_updating_stop(i_obj_p, this);
              i_coroutine_call_p = this->i_coroutine_call_p;
              if ( i_coroutine_call_p )
                SSInvokedContextBase::data_bind_return_args(
                  this,
                  &i_coroutine_call_p->i_return_args,
                  this->i_coroutine_p);
              if ( i_update_count && v3 && v3->i_pending_count )
              {
                i_next_p = this->i_next_p;
                if ( i_next_p != &this->AListNode<SSInvokedBase,SSInvokedBase> )
                {
                  i_prev_p = this->i_prev_p;
                  i_next_p->i_prev_p = i_prev_p;
                  i_prev_p->i_next_p = i_next_p;
                  this->i_prev_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
                  this->i_next_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
                }
                LOBYTE(i_next_p) = 1;
                v3->vfptr[1].get_data_by_name(v3, (ASymbol *)i_next_p);
              }
              SSInvokedCoroutine::pool_delete(this);
              return 1;
            }
            ++this->i_update_count;
          }
          SSActor::coroutine_track(i_obj_p, this);
          return 0;
        }
      }
    }
  }
  v12 = this->i_coroutine_p != 0i64;
  if ( i_obj_p )
    SSActor::coroutine_track_updating_stop(i_obj_p, this);
  v13 = this->i_coroutine_call_p;
  if ( v13 )
    SSInvokedContextBase::data_bind_return_args(this, &v13->i_return_args, this->i_coroutine_p);
  if ( v3 )
  {
    v14 = this->i_next_p;
    if ( v14 != &this->AListNode<SSInvokedBase,SSInvokedBase> )
    {
      v15 = this->i_prev_p;
      v14->i_prev_p = v15;
      v15->i_next_p = v14;
      this->i_prev_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
      this->i_next_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
    }
    v3->vfptr[1].get_data_by_name(v3, (ASymbol *)v12);
  }
  SSInvokedCoroutine::pool_delete(this);
  return v12;
}

// File Line: 491
// RVA: 0x13C170
void __fastcall SSInvokedCoroutine::reset(
        SSInvokedCoroutine *this,
        float update_interval,
        SSInvokedBase *caller_p,
        SSActor *scope_p,
        SSActor *updater_p,
        SSCoroutineCall *coroutine_call_p)
{
  SSActor *v6; // rdx
  bool v10; // al
  unsigned int v11; // ecx
  unsigned int i_ptr_id; // eax
  SSCoroutineCall *v13; // rax

  v6 = updater_p;
  if ( !updater_p
    && (!caller_p
     || (v6 = (SSActor *)((__int64 (__fastcall *)(SSInvokedBase *))caller_p->vfptr[1].is_actor)(caller_p)) == 0i64) )
  {
    v10 = scope_p->vfptr->is_actor(scope_p);
    v6 = SkookumScript::c_world_p;
    if ( v10 )
      v6 = scope_p;
  }
  ++scope_p->i_ref_count;
  v11 = 0;
  this->i_update_interval = update_interval;
  this->i_update_count = 0;
  this->i_pending_count = 0;
  this->i_flags = 0;
  this->i_caller_p.i_obj_p = caller_p;
  if ( caller_p )
    i_ptr_id = caller_p->i_ptr_id;
  else
    i_ptr_id = 0;
  this->i_caller_p.i_ptr_id = i_ptr_id;
  this->i_scope_p.i_obj_p = scope_p;
  this->i_scope_p.i_ptr_id = scope_p->i_ptr_id;
  v13 = coroutine_call_p;
  if ( !coroutine_call_p || !coroutine_call_p->i_return_args.i_count )
    v13 = 0i64;
  this->i_coroutine_call_p = v13;
  this->i_updater_p.i_obj_p = v6;
  if ( v6 )
    v11 = v6->i_ptr_id;
  this->i_updater_p.i_ptr_id = v11;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->i_update_next = SkookumScript::c_sim_time;
}

// File Line: 552
// RVA: 0x130EE0
SSInvokedCoroutine *__fastcall SSInvokedCoroutine::pool_new(
        SSCoroutineCall *rcall,
        float update_interval,
        SSInvokedBase *caller_p,
        SSInstance *scope_p,
        SSActor *updater_p)
{
  SSInvokedCoroutine *v5; // rdi
  SSQualifier *v9; // rdx
  SSClass *i_scope_p; // rcx
  SSClass *i_class_p; // r8
  SSClassDescBaseVtbl *vfptr; // rax
  __int64 v13; // r14
  AObjReusePool<SSInvokedCoroutine> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v16; // eax
  __int64 v17; // rcx
  SSInvokedCoroutine **i_array_p; // rax
  unsigned int v19; // eax

  v5 = 0i64;
  v9 = &rcall->SSQualifier;
  if ( !rcall )
    v9 = 0i64;
  i_scope_p = v9->i_scope_p;
  i_class_p = scope_p->i_class_p;
  if ( !i_scope_p || i_scope_p == i_class_p )
  {
    vfptr = i_class_p->vfptr;
    i_scope_p = scope_p->i_class_p;
  }
  else
  {
    vfptr = i_scope_p->vfptr;
  }
  v13 = ((__int64 (__fastcall *)(SSClass *))vfptr->get_coroutine_inherited)(i_scope_p);
  pool = SSInvokedCoroutine::get_pool();
  if ( pool->i_pool.i_count )
  {
    v19 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v19;
    v17 = v19;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_13;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSInvokedCoroutine>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v16 = i_count - 1;
    pool->i_exp_pool.i_count = v16;
    v17 = v16;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_13:
    v5 = i_array_p[v17];
  }
  v5->i_coroutine_p = (SSCoroutineBase *)v13;
  SSInvokedCoroutine::reset(v5, update_interval, caller_p, scope_p, updater_p, rcall);
  return v5;
}

// File Line: 576
// RVA: 0x118D10
AObjReusePool<SSInvokedCoroutine> *__fastcall SSInvokedCoroutine::get_pool()
{
  unsigned int i_pool_incr_icoroutine; // edi
  unsigned int i_pool_init_icoroutine; // ebx
  SSInvokedCoroutine **v2; // rax

  if ( (_S7_3 & 1) != 0 )
    return &s_pool_3;
  _S7_3 |= 1u;
  i_pool_incr_icoroutine = Skookum::get_lib_vals()->i_pool_incr_icoroutine;
  i_pool_init_icoroutine = Skookum::get_lib_vals()->i_pool_init_icoroutine;
  s_pool_3.i_pool.i_count = 0;
  unk_142175C88 = 0i64;
  unk_142175C90 = 0;
  if ( i_pool_init_icoroutine )
  {
    unk_142175C90 = i_pool_init_icoroutine;
    v2 = APArrayBase<SSInvokedCoroutine>::alloc_array(i_pool_init_icoroutine);
  }
  else
  {
    unk_142175C90 = 0;
    v2 = (SSInvokedCoroutine **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  unk_142175C88 = v2;
  qword_142175C98 = 0i64;
  unk_142175CA0 = 0;
  qword_142175CA8 = 0i64;
  unk_142175CB0 = 0;
  stru_142175CB8.i_count = 0;
  stru_142175CB8.i_array_p = 0i64;
  stru_142175CB8.i_size = 0;
  unk_142175CD0 = i_pool_incr_icoroutine;
  AObjReusePool<SSInvokedCoroutine>::append_block(&s_pool_3, i_pool_init_icoroutine);
  atexit(SSInvokedCoroutine::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_3;
}

// File Line: 624
// RVA: 0x117A90
__int64 __fastcall SSInvokedCoroutine::get_invoke_type(SSInvokedCoroutine *this)
{
  return ((__int64 (__fastcall *)(SSCoroutineBase *))this->i_coroutine_p->vfptr->get_invoke_type)(this->i_coroutine_p);
}

// File Line: 644
// RVA: 0x135D90
void SSInvokedCoroutine::register_atomic(void)
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

  i_count = SSBrain::c_invoked_coroutine_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_invoked_coroutine_class_p->i_methods.i_array_p;
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
      v5[1].vfptr = (SSInvokableBaseVtbl *)SSInvokedCoroutine::mthd_String;
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
      v5[1].vfptr = (SSInvokableBaseVtbl *)SSInvokedCoroutine::mthd_String;
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

// File Line: 657
// RVA: 0x1202D0
void __fastcall SSInvokedCoroutine::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
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
    v5 = "InvokedCoroutine[stale]";
    if ( vfptr )
      v5 = "InvokedCoroutine";
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

