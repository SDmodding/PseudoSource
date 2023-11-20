// File Line: 205
// RVA: 0x107360
void __fastcall SSLiteral::~SSLiteral(SSLiteral *this)
{
  SSLiteral *v1; // rdi
  AStringRef *v2; // rbx
  bool v3; // zf
  AObjReusePool<AStringRef> *v4; // rax
  AObjBlock<AStringRef> *v5; // rcx
  unsigned __int64 v6; // rdx
  bool v7; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v8; // rcx

  v1 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
  if ( this->i_kind == 4 )
  {
    v2 = (AStringRef *)this->i_data;
    v3 = v2->i_ref_count-- == 1;
    if ( v3 )
    {
      if ( v2->i_deallocate )
        AMemory::c_free_func(v2->i_cstr_p);
      v4 = AStringRef::get_pool();
      v5 = v4->i_block_p;
      v6 = (unsigned __int64)v5->i_objects_a;
      if ( (unsigned __int64)v2 < v6 || (v7 = (unsigned __int64)v2 < v6 + 24i64 * v5->i_size, v8 = &v4->i_pool, !v7) )
        v8 = &v4->i_exp_pool;
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v8, v2);
    }
  }
  v1->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 253
// RVA: 0x105AD0
void __fastcall SSLiteral::SSLiteral(SSLiteral *this, const void **binary_pp)
{
  SSLiteral *v2; // rbx
  SSLiteral::eType v3; // eax
  ASymbol *v4; // rax
  SSClass *v5; // rax
  ASymbol *v6; // rcx
  AString *v7; // rcx
  ASymbol result; // [rsp+48h] [rbp+10h]

  v2 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
  this->i_kind = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v3 = this->i_kind;
  switch ( v3 )
  {
    case 4:
      v7 = (AString *)&this->i_data;
      *(_QWORD *)&result.i_uid = (char *)v2 + 8;
      if ( v2 != (SSLiteral *)-8i64 )
        AString::AString(v7, binary_pp);
      break;
    case 5:
      v6 = (ASymbol *)&this->i_data;
      *(_QWORD *)&result.i_uid = (char *)v2 + 8;
      if ( v2 != (SSLiteral *)-8i64 )
        ASymbol::create_from_binary(v6, binary_pp);
      break;
    case 6:
      v4 = ASymbol::create_from_binary(&result, binary_pp);
      v5 = SSBrain::get_class(v4);
      v2->i_data = (__int64)v5->vfptr->get_metaclass((SSClassDescBase *)&v5->vfptr);
      break;
    default:
      if ( (unsigned int)(v3 - 7) > 3 )
      {
        this->i_data = *(unsigned int *)*binary_pp;
        *binary_pp = (char *)*binary_pp + 4;
      }
      break;
  }
}

// File Line: 495
// RVA: 0x11D910
SSInvokedBase *__fastcall SSLiteral::invoke(SSLiteral *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance **v4; // rbx
  SSInvokedBase *result; // rax
  unsigned __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax

  v4 = result_pp;
  if ( result_pp )
  {
    switch ( this->i_kind )
    {
      case 0:
        *result_pp = (SSInstance *)SSBoolean::pool_new(this->i_data);
        return 0i64;
      case 1:
        *result_pp = SSInstance::pool_new(SSBrain::c_char_class_p, this->i_data);
        return 0i64;
      case 2:
        *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, this->i_data);
        return 0i64;
      case 3:
        *result_pp = SSInstance::pool_new(SSBrain::c_real_class_p, this->i_data);
        return 0i64;
      case 4:
        *result_pp = SSString::as_instance((AString *)&this->i_data);
        return 0i64;
      case 5:
        *result_pp = SSSymbol::as_instance((ASymbol *)&this->i_data);
        return 0i64;
      case 6:
        v6 = this->i_data;
        if ( v6 )
          goto LABEL_10;
        goto LABEL_13;
      case 7:
        goto $LN21_1;
      case 8:
        v7 = ((__int64 (__fastcall *)(SSObjectBase *, SSObjectBase *, SSInvokedBase *))scope_p->vfptr->get_topmost_scope)(
               scope_p,
               scope_p,
               caller_p);
        ++*(_DWORD *)(v7 + 16);
        *v4 = (SSInstance *)v7;
        return 0i64;
      case 9:
        v8 = ((__int64 (__fastcall *)(SSObjectBase *, SSObjectBase *, SSInvokedBase *))scope_p->vfptr->get_topmost_scope)(
               scope_p,
               scope_p,
               caller_p);
        v6 = (*(__int64 (**)(void))(**(_QWORD **)(v8 + 24) + 136i64))();
        if ( v6 )
        {
LABEL_10:
          *v4 = (SSInstance *)(v6 + 8);
          result = 0i64;
        }
        else
        {
LABEL_13:
          result = 0i64;
          *v4 = 0i64;
        }
        return result;
      case 0xA:
        v9 = ((__int64 (__fastcall *)(SSObjectBase *, SSObjectBase *, SSInvokedBase *))scope_p->vfptr->get_scope_context)(
               scope_p,
               scope_p,
               caller_p);
        if ( v9 )
        {
          *v4 = (SSInstance *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
          return 0i64;
        }
$LN21_1:
        *v4 = SSBrain::c_nil_p;
        break;
      default:
        return 0i64;
    }
  }
  return 0i64;
}

// File Line: 573
// RVA: 0x13E1C0
void __fastcall SSLiteral::track_memory(SSLiteral *this, AMemoryStats *mem_stats_p)
{
  const char *v2; // rbx
  AMemoryStats *v3; // rsi
  SSLiteral *v4; // rdi
  unsigned int size_dynamic_needed; // er8
  unsigned int size_dynamic; // edx
  unsigned __int64 v7; // rax

  v2 = 0i64;
  v3 = mem_stats_p;
  v4 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSLiteral", 0x18u, 8u, 0, 0, 1u);
  size_dynamic_needed = 0;
  size_dynamic = 0;
  switch ( v4->i_kind )
  {
    case 0:
      v2 = "SSLiteral.Boolean";
      break;
    case 1:
      v2 = "SSLiteral.Char";
      break;
    case 2:
      v2 = "SSLiteral.Integer";
      break;
    case 3:
      v2 = "SSLiteral.Real";
      break;
    case 4:
      v7 = v4->i_data;
      v2 = "SSLiteral.String";
      size_dynamic = *(_DWORD *)(v7 + 12);
      size_dynamic_needed = *(_DWORD *)(v7 + 8) + 1;
      break;
    case 5:
      v2 = "SSLiteral.Symbol";
      break;
    case 6:
      v2 = "SSLiteral.Class";
      break;
    case 7:
      v2 = "SSLiteral.nil";
      break;
    case 8:
      v2 = "SSLiteral.this";
      break;
    case 9:
      v2 = "SSLiteral.this_class";
      break;
    case 0xA:
      v2 = "SSLiteral.this_code";
      break;
    default:
      break;
  }
  AMemoryStats::track_memory(v3, v2, 0, 0, size_dynamic_needed, size_dynamic, 1u);
}

// File Line: 674
// RVA: 0x105DE0
void __fastcall SSLiteralList::SSLiteralList(SSLiteralList *this, const void **binary_pp)
{
  const void **v2; // rdi
  SSLiteralList *v3; // rsi
  __int64 v4; // rbp
  SSExpressionBase **v5; // rcx
  SSExpressionBase **v6; // rbx
  unsigned __int64 i; // rbp
  eSSExprType v8; // ecx
  signed __int64 v9; // rax
  SSExpressionBase *v10; // rax

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteralList::`vftable;
  this->i_item_exprs.i_count = 0;
  this->i_item_exprs.i_array_p = 0i64;
  this->i_ctor_p = (SSMethodCall *)SSInvokeBase::from_binary_typed_new(binary_pp);
  v4 = *(unsigned __int16 *)*v2;
  *v2 = (char *)*v2 + 2;
  if ( v3->i_item_exprs.i_count != (_DWORD)v4 )
  {
    v3->i_item_exprs.i_count = v4;
    v5 = v3->i_item_exprs.i_array_p;
    if ( v5 )
      AMemory::c_free_func(v5);
    v3->i_item_exprs.i_array_p = APArrayBase<SSExpressionBase>::alloc_array(v4);
  }
  v6 = v3->i_item_exprs.i_array_p;
  for ( i = (unsigned __int64)&v6[v4]; (unsigned __int64)v6 < i; ++v6 )
  {
    v8 = *(unsigned __int8 *)*v2;
    v9 = (signed __int64)*v2 + 1;
    *v2 = (const void *)v9;
    if ( v8 )
    {
      *v2 = (const void *)(v9 + 2);
      v10 = SSExpressionBase::from_binary_new(v8, v2);
    }
    else
    {
      v10 = 0i64;
    }
    *v6 = v10;
  }
}

// File Line: 819
// RVA: 0x119F60
signed __int64 __fastcall SSLiteralList::get_side_effect(SSLiteralList *this)
{
  __int64 v1; // rax
  SSExpressionBase **v2; // rbx
  unsigned __int64 v3; // rdi

  v1 = this->i_item_exprs.i_count;
  if ( !(_DWORD)v1 )
    return 0i64;
  v2 = this->i_item_exprs.i_array_p;
  v3 = (unsigned __int64)&v2[v1];
  if ( (unsigned __int64)v2 >= v3 )
    return 0i64;
  while ( !((unsigned int (*)(void))(*v2)->vfptr->get_side_effect)() )
  {
    ++v2;
    if ( (unsigned __int64)v2 >= v3 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 1039
// RVA: 0x11DB70
SSInvokedBase *__fastcall SSLiteralList::invoke(SSLiteralList *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance **v4; // r12
  SSLiteralList *v5; // r13
  __int64 v6; // rbp
  SSExpressionBase **v7; // rsi
  unsigned __int64 v8; // r15
  unsigned int *v9; // rax
  unsigned int *v10; // rdi
  SSInstance *v11; // rbx
  SSInstance **v12; // rax
  unsigned int **v13; // r14
  SSClass *v14; // rbp
  AObjReusePool<SSInstance> *v15; // rax
  AObjReusePool<SSInstance> *v16; // rsi
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  __int64 v20; // rcx
  SSInstance **v21; // rax
  unsigned int v22; // eax
  SSMethodCall *v23; // rcx
  bool v24; // zf
  __int64 v25; // rax
  ARefCountMix<SSInstance> **v26; // rbx
  unsigned __int64 i; // rsi
  unsigned int *v29; // [rsp+30h] [rbp-58h]
  __int64 v30; // [rsp+38h] [rbp-50h]
  SSLiteralList *v31; // [rsp+90h] [rbp+8h]
  SSObjectBase *v32; // [rsp+98h] [rbp+10h]
  SSInvokedBase *v33; // [rsp+A0h] [rbp+18h]
  SSInstance **v34; // [rsp+A8h] [rbp+20h]

  v34 = result_pp;
  v33 = caller_p;
  v32 = scope_p;
  v31 = this;
  v30 = -2i64;
  v4 = result_pp;
  v5 = this;
  v6 = this->i_item_exprs.i_count;
  v7 = this->i_item_exprs.i_array_p;
  v8 = (unsigned __int64)&v7[v6];
  v9 = (unsigned int *)AMemory::c_malloc_func(0x18ui64, "SSList");
  v10 = v9;
  v29 = v9;
  v11 = 0i64;
  if ( v9 )
  {
    *v9 = 0;
    *((_QWORD *)v9 + 1) = 0i64;
    v9[4] = 0;
    if ( (_DWORD)v6 )
    {
      v9[4] = v6;
      v12 = APArrayBase<SSInstance>::alloc_array(v6);
    }
    else
    {
      v9[4] = 0;
      v12 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    *((_QWORD *)v10 + 1) = v12;
  }
  else
  {
    v10 = 0i64;
  }
  v13 = (unsigned int **)*((_QWORD *)v10 + 1);
  if ( (unsigned __int64)v7 < v8 )
  {
    do
    {
      (*v7)->vfptr->invoke(*v7, v32, v33, (SSInstance **)&v29);
      *v13 = v29;
      ++v7;
      ++v13;
    }
    while ( (unsigned __int64)v7 < v8 );
    v4 = v34;
    v5 = v31;
  }
  *v10 = v6;
  if ( v5->i_ctor_p || v4 )
  {
    v14 = SSBrain::c_list_class_p;
    v15 = SSInstance::get_pool();
    v16 = v15;
    v17 = v15->i_pool.i_count;
    if ( v17 )
    {
      v22 = v17 - 1;
      v16->i_pool.i_count = v22;
      v20 = v22;
      v21 = v16->i_pool.i_array_p;
    }
    else
    {
      if ( !v16->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(v16, v16->i_expand_size);
      v18 = v16->i_exp_pool.i_count;
      if ( !v18 )
        goto LABEL_19;
      v19 = v18 - 1;
      v16->i_exp_pool.i_count = v19;
      v20 = v19;
      v21 = v16->i_exp_pool.i_array_p;
    }
    v11 = v21[v20];
LABEL_19:
    v11->i_class_p = v14;
    v11->i_user_data = (unsigned __int64)v10;
    v11->i_ref_count = 1;
    v11->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  }
  v23 = v5->i_ctor_p;
  if ( v23 )
    v23->vfptr->invoke_call((SSInvokeBase *)&v23->vfptr, v11, v32, v33, (SSInstance **)&v34);
  if ( v4 )
  {
    *v4 = v11;
  }
  else if ( v11 )
  {
    v24 = v11->i_ref_count-- == 1;
    if ( v24 )
    {
      v11->i_ref_count = 2147483648;
      v11->vfptr[1].get_scope_context((SSObjectBase *)&v11->vfptr);
    }
  }
  else
  {
    v34 = (SSInstance **)v10;
    v25 = *v10;
    if ( (_DWORD)v25 )
    {
      v26 = (ARefCountMix<SSInstance> **)*((_QWORD *)v10 + 1);
      for ( i = (unsigned __int64)&v26[v25]; (unsigned __int64)v26 < i; ++v26 )
        ARefCountMix<SSInstance>::dereference(*v26 + 4);
    }
    AMemory::c_free_func(*((void **)v10 + 1));
    AMemory::c_free_func(v10);
  }
  return 0i64;
}

// File Line: 1114
// RVA: 0x13E370
void __fastcall SSLiteralList::track_memory(SSLiteralList *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **v2; // rbx
  AMemoryStats *v3; // rsi
  unsigned __int64 v4; // rdi
  SSLiteralList *i; // rbp
  SSMethodCall *v6; // rcx

  v2 = this->i_item_exprs.i_array_p;
  v3 = mem_stats_p;
  v4 = (unsigned __int64)&v2[this->i_item_exprs.i_count];
  for ( i = this; (unsigned __int64)v2 < v4; ++v2 )
  {
    if ( *v2 )
      (*v2)->vfptr->track_memory(*v2, v3);
  }
  AMemoryStats::track_memory(
    v3,
    "SSLiteralList",
    0x20u,
    8u,
    8 * i->i_item_exprs.i_count,
    8 * i->i_item_exprs.i_count,
    1u);
  v6 = i->i_ctor_p;
  if ( v6 )
    v6->vfptr->track_memory((SSInvokeBase *)&v6->vfptr, v3);
}

