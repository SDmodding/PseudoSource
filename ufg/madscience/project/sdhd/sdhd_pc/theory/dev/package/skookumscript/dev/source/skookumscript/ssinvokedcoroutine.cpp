// File Line: 56
// RVA: 0x1058D0
void __fastcall SSInvokedCoroutine::SSInvokedCoroutine(SSInvokedCoroutine *this)
{
  AListNode<SSInvokedBase,SSInvokedBase> *v1; // rax
  AList<SSInvokedBase,SSInvokedBase> *v2; // [rsp+28h] [rbp+10h]
  APArrayLogical<SSData,ASymbol> *v3; // [rsp+28h] [rbp+10h]

  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
  v1 = (AListNode<SSInvokedBase,SSInvokedBase> *)&this->i_next_p;
  v1->i_prev_p = v1;
  v1->i_next_p = v1;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedBase::`vftable';
  this->i_scope_p.i_obj_p = 0i64;
  this->i_scope_p.i_ptr_id = 0;
  this->i_caller_p.i_obj_p = 0i64;
  this->i_caller_p.i_ptr_id = 0;
  v2 = &this->i_calls;
  v2->i_sentinel.i_prev_p = &v2->i_sentinel;
  v2->i_sentinel.i_next_p = &v2->i_sentinel;
  this->i_pending_count = 0;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedContextBase::`vftable';
  v3 = &this->i_data;
  v3->i_count = 0;
  v3->i_array_p = 0i64;
  v3->i_size = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedCoroutine::`vftable';
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
void __fastcall SSInvokedCoroutine::abort_invoke(SSInvokedCoroutine *this, eSSNotify notify_caller, eSSNotifyChild notify_child)
{
  unsigned int v3; // eax
  eSSNotifyChild v4; // ebp
  eSSNotify v5; // esi
  SSInvokedCoroutine *v6; // rbx
  SSActor *v7; // rdi

  v3 = this->i_ptr_id;
  v4 = notify_child;
  v5 = notify_caller;
  v6 = this;
  if ( v3 && v3 <= SSObjectBase::c_ptr_id_prev )
  {
    if ( this->i_flags & 3 )
    {
      v7 = this->i_updater_p.i_obj_p;
      if ( v7 )
      {
        if ( this->i_updater_p.i_ptr_id == v7->i_ptr_id )
        {
          SSActor::coroutine_track_updating_stop(this->i_updater_p.i_obj_p, this);
          SSActor::coroutine_track_pending_stop(v7, v6);
        }
      }
    }
    v6->i_pending_count = 0;
    if ( v4 == 1 )
      SSInvokedBase::abort_subcalls((SSInvokedBase *)&v6->vfptr, v5);
    else
      SSInvokedBase::detach_subcalls((SSInvokedBase *)&v6->vfptr, v5);
    SSInvokedCoroutine::pool_delete(v6);
  }
}

// File Line: 147
// RVA: 0x11A070
SSActor *__fastcall SSInvokedCoroutine::get_updater(SSInvokedCoroutine *this)
{
  SSInvokedCoroutine *v1; // rbx
  SSActor *v2; // rcx
  unsigned int v4; // edi
  SSInvokedBase *v5; // rcx
  SSActor *v6; // rcx
  SSActor *v7; // rsi
  bool v8; // al

  v1 = this;
  v2 = this->i_updater_p.i_obj_p;
  if ( v2 && v1->i_updater_p.i_ptr_id == v2->i_ptr_id )
    return v2;
  v4 = 0;
  if ( !v2 || v2->i_ptr_id != v1->i_updater_p.i_ptr_id )
    return 0i64;
  v5 = v1->i_caller_p.i_obj_p;
  if ( !v5
    || v1->i_caller_p.i_ptr_id != v5->i_ptr_id
    || (v6 = (SSActor *)((__int64 (*)(void))v5->vfptr[1].is_actor)()) == 0i64 )
  {
    v7 = (SSActor *)v1->i_scope_p.i_obj_p;
    if ( !v7 || v1->i_scope_p.i_ptr_id != v7->i_ptr_id )
      v7 = 0i64;
    v8 = v7->vfptr->is_actor((SSObjectBase *)&v7->vfptr);
    v6 = SkookumScript::c_world_p;
    if ( v8 )
      v6 = v7;
  }
  v1->i_updater_p.i_obj_p = v6;
  if ( v6 )
    v4 = v6->i_ptr_id;
  v1->i_updater_p.i_ptr_id = v4;
  return v6;
}

// File Line: 188
// RVA: 0x130510
void __fastcall SSInvokedCoroutine::pending_schedule(SSInvokedCoroutine *this, bool completed)
{
  SSInvokedCoroutine *v2; // rbx
  SSCoroutineBase *v3; // rcx
  SSActor *v4; // rdi
  SSInvokedBase *v5; // rcx
  SSCoroutineCall *v6; // rdx

  --this->i_pending_count;
  v2 = this;
  if ( !completed )
  {
    ((void (__fastcall *)(SSInvokedCoroutine *, signed __int64, signed __int64))this->vfptr[1].as_instance)(
      this,
      1i64,
      1i64);
    return;
  }
  v3 = this->i_coroutine_p;
  if ( !v2->i_pending_count )
  {
    v4 = v2->i_updater_p.i_obj_p;
    if ( !v4 || v2->i_updater_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    if ( ((unsigned int (*)(void))v3->vfptr->get_invoke_type)() != 3 )
    {
      if ( !v4 )
      {
        SSInvokedCoroutine::on_update(v2);
        return;
      }
      SSActor::coroutine_track_pending_stop(v4, v2);
      goto LABEL_9;
    }
    v5 = v2->i_caller_p.i_obj_p;
    if ( v5 && v2->i_caller_p.i_ptr_id == v5->i_ptr_id && v5->i_pending_count )
    {
      v2->i_update_count = -1;
      if ( v4 )
      {
LABEL_9:
        SSActor::coroutine_track_updating(v4, v2);
        return;
      }
    }
    else
    {
      v6 = v2->i_coroutine_call_p;
      if ( v6 )
        SSInvokedContextBase::data_bind_return_args(
          (SSInvokedContextBase *)&v2->vfptr,
          (APArrayBase<SSIdentifier> *)&v6->i_return_args.i_count,
          (SSInvokableBase *)&v2->i_coroutine_p->vfptr);
      SSInvokedCoroutine::pool_delete(v2);
    }
  }
}

// File Line: 262
// RVA: 0x130340
void __fastcall SSInvokedCoroutine::pending_return(SSInvokedCoroutine *this, bool completed)
{
  SSInvokedCoroutine *v2; // rbx
  SSCoroutineBase *v3; // r14
  SSActor *v4; // rdi
  SSInvokedBase *v5; // rsi
  SSCoroutineCall *v6; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v8; // rax

  --this->i_pending_count;
  v2 = this;
  if ( completed )
  {
    v3 = this->i_coroutine_p;
    if ( !this->i_pending_count )
    {
      v4 = this->i_updater_p.i_obj_p;
      if ( !v4 || this->i_updater_p.i_ptr_id != v4->i_ptr_id )
        v4 = 0i64;
      if ( v3->vfptr->get_invoke_type((SSInvokableBase *)&v3->vfptr) == 3 )
      {
        v5 = v2->i_caller_p.i_obj_p;
        if ( !v5 || v2->i_caller_p.i_ptr_id != v5->i_ptr_id )
          v5 = 0i64;
        if ( v4 )
          SSActor::coroutine_track_pending_stop(v4, v2);
        v6 = v2->i_coroutine_call_p;
        if ( v6 )
          SSInvokedContextBase::data_bind_return_args(
            (SSInvokedContextBase *)&v2->vfptr,
            (APArrayBase<SSIdentifier> *)&v6->i_return_args.i_count,
            (SSInvokableBase *)&v3->vfptr);
        if ( v5 && v5->i_pending_count )
        {
          v7 = v2->i_next_p;
          if ( v7 != (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p )
          {
            v8 = v2->i_prev_p;
            v7->i_prev_p = v8;
            v8->i_next_p = v7;
            v2->i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p;
            v2->i_next_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p;
          }
          LOBYTE(v7) = 1;
          v5->vfptr[1].get_data_by_name((SSObjectBase *)&v5->vfptr, (ASymbol *)v7);
        }
        SSInvokedCoroutine::pool_delete(v2);
      }
      else
      {
        if ( v4 )
        {
          SSActor::coroutine_track_pending_stop(v4, v2);
          SSActor::coroutine_track_updating(v4, v2);
        }
        SSInvokedCoroutine::on_update(v2);
      }
    }
  }
  else
  {
    ((void (__fastcall *)(SSInvokedCoroutine *, signed __int64, signed __int64))this->vfptr[1].as_instance)(
      this,
      1i64,
      1i64);
  }
}

// File Line: 328
// RVA: 0x13CCE0
void __fastcall SSInvokedCoroutine::suspend(SSInvokedCoroutine *this)
{
  unsigned int v1; // edx
  SSInvokedCoroutine *v2; // rbx
  int v3; // edx
  SSActor *v4; // rdi

  v1 = this->i_flags;
  v2 = this;
  if ( !(v1 & 4) )
  {
    ++this->i_pending_count;
    v3 = v1 | 4;
    this->i_flags = v3;
    v4 = this->i_updater_p.i_obj_p;
    if ( v4 )
    {
      if ( this->i_updater_p.i_ptr_id == v4->i_ptr_id )
      {
        if ( !(v3 & 2) )
        {
          APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
            &v4->i_icoroutines_pending,
            this);
          v2->i_flags |= 2u;
        }
        SSActor::coroutine_track_updating_stop(v4, v2);
      }
    }
  }
}

// File Line: 378
// RVA: 0x126FC0
char __fastcall SSInvokedCoroutine::on_update(SSInvokedCoroutine *this)
{
  SSActor *v1; // rsi
  SSInvokedCoroutine *v2; // rbx
  SSInvokedBase *v3; // rdi
  SSObjectBase *v4; // rcx
  double v5; // xmm1_8
  SSCoroutineBase *v6; // rcx
  unsigned int v7; // ebp
  SSCoroutineCall *v8; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v10; // rax
  bool v12; // bp
  SSCoroutineCall *v13; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v14; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v15; // rcx

  v1 = this->i_updater_p.i_obj_p;
  v2 = this;
  if ( !v1 || this->i_updater_p.i_ptr_id != v1->i_ptr_id )
    v1 = 0i64;
  v3 = this->i_caller_p.i_obj_p;
  if ( !v3 || this->i_caller_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( v1 )
  {
    if ( this->i_update_count != -1 )
    {
      v4 = this->i_scope_p.i_obj_p;
      if ( v4 )
      {
        if ( v4->i_ptr_id == v2->i_scope_p.i_ptr_id )
        {
          v5 = v2->i_update_next;
          if ( v5 <= SkookumScript::c_sim_time )
          {
            v6 = v2->i_coroutine_p;
            v2->i_update_next = v2->i_update_interval + v5;
            if ( v6
              && ((unsigned __int8 (__fastcall *)(SSCoroutineBase *, SSInvokedCoroutine *))v6->vfptr[1].get_custom_expr)(
                   v6,
                   v2) )
            {
              v7 = v2->i_update_count;
              SSActor::coroutine_track_updating_stop(v1, v2);
              v8 = v2->i_coroutine_call_p;
              if ( v8 )
                SSInvokedContextBase::data_bind_return_args(
                  (SSInvokedContextBase *)&v2->vfptr,
                  (APArrayBase<SSIdentifier> *)&v8->i_return_args.i_count,
                  (SSInvokableBase *)&v2->i_coroutine_p->vfptr);
              if ( v7 && v3 && v3->i_pending_count )
              {
                v9 = v2->i_next_p;
                if ( v9 != (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p )
                {
                  v10 = v2->i_prev_p;
                  v9->i_prev_p = v10;
                  v10->i_next_p = v9;
                  v2->i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p;
                  v2->i_next_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p;
                }
                LOBYTE(v9) = 1;
                v3->vfptr[1].get_data_by_name((SSObjectBase *)&v3->vfptr, (ASymbol *)v9);
              }
              SSInvokedCoroutine::pool_delete(v2);
              return 1;
            }
            ++v2->i_update_count;
          }
          SSActor::coroutine_track(v1, v2);
          return 0;
        }
      }
    }
  }
  v12 = v2->i_coroutine_p != 0i64;
  if ( v1 )
    SSActor::coroutine_track_updating_stop(v1, v2);
  v13 = v2->i_coroutine_call_p;
  if ( v13 )
    SSInvokedContextBase::data_bind_return_args(
      (SSInvokedContextBase *)&v2->vfptr,
      (APArrayBase<SSIdentifier> *)&v13->i_return_args.i_count,
      (SSInvokableBase *)&v2->i_coroutine_p->vfptr);
  if ( v3 )
  {
    v14 = v2->i_next_p;
    if ( v14 != (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p )
    {
      v15 = v2->i_prev_p;
      v14->i_prev_p = v15;
      v15->i_next_p = v14;
      v2->i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p;
      v2->i_next_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v2->i_next_p;
    }
    v3->vfptr[1].get_data_by_name((SSObjectBase *)&v3->vfptr, (ASymbol *)v12);
  }
  SSInvokedCoroutine::pool_delete(v2);
  return v12;
}

// File Line: 491
// RVA: 0x13C170
void __fastcall SSInvokedCoroutine::reset(SSInvokedCoroutine *this, float update_interval, SSInvokedBase *caller_p, SSInstance *scope_p, SSActor *updater_p, SSCoroutineCall *coroutine_call_p)
{
  SSActor *v6; // rdx
  SSInstance *v7; // rsi
  SSInvokedBase *v8; // rdi
  SSInvokedCoroutine *v9; // rbx
  bool v10; // al
  unsigned int v11; // ecx
  unsigned int v12; // eax
  SSCoroutineCall *v13; // rax

  v6 = updater_p;
  v7 = scope_p;
  v8 = caller_p;
  v9 = this;
  if ( !updater_p )
  {
    if ( !caller_p || (v6 = (SSActor *)caller_p->vfptr[1].is_actor((SSObjectBase *)caller_p)) == 0i64 )
    {
      v10 = v7->vfptr->is_actor((SSObjectBase *)&v7->vfptr);
      v6 = SkookumScript::c_world_p;
      if ( v10 )
        v6 = (SSActor *)v7;
    }
  }
  ++v7->i_ref_count;
  v11 = 0;
  v9->i_update_interval = update_interval;
  v9->i_update_count = 0;
  v9->i_pending_count = 0;
  v9->i_flags = 0;
  v9->i_caller_p.i_obj_p = v8;
  if ( v8 )
    v12 = v8->i_ptr_id;
  else
    v12 = 0;
  v9->i_caller_p.i_ptr_id = v12;
  v9->i_scope_p.i_obj_p = (SSObjectBase *)&v7->vfptr;
  v9->i_scope_p.i_ptr_id = v7->i_ptr_id;
  v13 = coroutine_call_p;
  if ( !coroutine_call_p || !coroutine_call_p->i_return_args.i_count )
    v13 = 0i64;
  v9->i_coroutine_call_p = v13;
  v9->i_updater_p.i_obj_p = v6;
  if ( v6 )
    v11 = v6->i_ptr_id;
  v9->i_updater_p.i_ptr_id = v11;
  v9->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  v9->i_update_next = SkookumScript::c_sim_time;
}

// File Line: 552
// RVA: 0x130EE0
SSInvokedCoroutine *__fastcall SSInvokedCoroutine::pool_new(SSCoroutineCall *rcall, float update_interval, SSInvokedBase *caller_p, SSInstance *scope_p, SSActor *updater_p)
{
  SSInvokedCoroutine *v5; // rdi
  SSInstance *v6; // rbp
  SSInvokedBase *v7; // r15
  SSCoroutineCall *coroutine_call_p; // rsi
  SSQualifier *v9; // rdx
  SSClass *v10; // rcx
  SSClass *v11; // r8
  SSClassDescBaseVtbl *v12; // rax
  __int64 v13; // r14
  AObjReusePool<SSInvokedCoroutine> *v14; // rax
  AObjReusePool<SSInvokedCoroutine> *v15; // rbx
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  __int64 v19; // rcx
  SSInvokedCoroutine **v20; // rax
  unsigned int v21; // eax

  v5 = 0i64;
  v6 = scope_p;
  v7 = caller_p;
  coroutine_call_p = rcall;
  v9 = (SSQualifier *)&rcall->i_name;
  if ( !rcall )
    v9 = 0i64;
  v10 = v9->i_scope_p;
  v11 = scope_p->i_class_p;
  if ( v10 && v10 != v11 )
  {
    v12 = v10->vfptr;
  }
  else
  {
    v12 = v11->vfptr;
    v10 = scope_p->i_class_p;
  }
  v13 = ((__int64 (__fastcall *)(SSClass *))v12->get_coroutine_inherited)(v10);
  v14 = SSInvokedCoroutine::get_pool();
  v15 = v14;
  v16 = v14->i_pool.i_count;
  if ( v16 )
  {
    v21 = v16 - 1;
    v15->i_pool.i_count = v21;
    v19 = v21;
    v20 = v15->i_pool.i_array_p;
    goto LABEL_13;
  }
  if ( !v15->i_exp_pool.i_count )
    AObjReusePool<SSInvokedCoroutine>::append_block(v15, v15->i_expand_size);
  v17 = v15->i_exp_pool.i_count;
  if ( v17 )
  {
    v18 = v17 - 1;
    v15->i_exp_pool.i_count = v18;
    v19 = v18;
    v20 = v15->i_exp_pool.i_array_p;
LABEL_13:
    v5 = v20[v19];
  }
  v5->i_coroutine_p = (SSCoroutineBase *)v13;
  SSInvokedCoroutine::reset(v5, update_interval, v7, v6, updater_p, coroutine_call_p);
  return v5;
}

// File Line: 576
// RVA: 0x118D10
AObjReusePool<SSInvokedCoroutine> *__fastcall SSInvokedCoroutine::get_pool()
{
  unsigned int v0; // edi
  unsigned int v1; // ebx
  SSInvokedCoroutine **v2; // rax

  if ( _S7_3 & 1 )
    return &s_pool_3;
  _S7_3 |= 1u;
  v0 = Skookum::get_lib_vals()->i_pool_incr_icoroutine;
  v1 = Skookum::get_lib_vals()->i_pool_init_icoroutine;
  s_pool_3.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175C88 = 0i64;
  unk_142175C90 = 0;
  if ( v1 )
  {
    unk_142175C90 = v1;
    v2 = APArrayBase<SSInvokedCoroutine>::alloc_array(v1);
  }
  else
  {
    unk_142175C90 = 0;
    v2 = (SSInvokedCoroutine **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  *(_QWORD *)&dword_142175C88 = v2;
  qword_142175C98 = 0i64;
  unk_142175CA0 = 0;
  qword_142175CA8 = 0i64;
  unk_142175CB0 = 0;
  stru_142175CB8.i_count = 0;
  stru_142175CB8.i_array_p = 0i64;
  stru_142175CB8.i_size = 0;
  unk_142175CD0 = v0;
  AObjReusePool<SSInvokedCoroutine>::append_block(&s_pool_3, v1);
  atexit(SSInvokedCoroutine::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_3;
}

// File Line: 624
// RVA: 0x117A90
__int64 __fastcall SSInvokedCoroutine::get_invoke_type(SSInvokedCoroutine *this)
{
  return ((__int64 (*)(void))this->i_coroutine_p->vfptr->get_invoke_type)();
}

// File Line: 644
// RVA: 0x135D90
void SSInvokedCoroutine::register_atomic(void)
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

  v0 = SSBrain::c_invoked_coroutine_class_p->i_methods.i_count;
  if ( (_DWORD)v0 )
  {
    v1 = SSBrain::c_invoked_coroutine_class_p->i_methods.i_array_p;
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
      *(_QWORD *)(v6 + 32) = SSInvokedCoroutine::mthd_String;
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
      *(_QWORD *)v6 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v6 + 24) = v8;
      if ( v8 )
        ++v8->i_ref_count;
      *(_QWORD *)v6 = &SSMethodBase::`vftable';
      *(_QWORD *)v6 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v6 + 32) = SSInvokedCoroutine::mthd_String;
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

// File Line: 657
// RVA: 0x1202D0
void __fastcall SSInvokedCoroutine::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
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
    v5 = "InvokedCoroutine[stale]";
    if ( v4 )
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

