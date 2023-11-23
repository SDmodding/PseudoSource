// File Line: 205
// RVA: 0x107360
void __fastcall SSLiteral::~SSLiteral(SSLiteral *this)
{
  AStringRef *i_data; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v7; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
  if ( this->i_kind == Type_int16 )
  {
    i_data = (AStringRef *)this->i_data;
    if ( i_data->i_ref_count-- == 1 )
    {
      if ( i_data->i_deallocate )
        AMemory::c_free_func(i_data->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_data < i_objects_a
        || (v7 = (unsigned __int64)i_data < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v7) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_data);
    }
  }
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 253
// RVA: 0x105AD0
void __fastcall SSLiteral::SSLiteral(SSLiteral *this, const void **binary_pp)
{
  SSLiteral::eType i_kind; // eax
  ASymbol *v4; // rax
  SSClass *v5; // rax
  unsigned __int64 *v6; // rcx
  unsigned __int64 *p_i_data; // rcx
  unsigned __int64 *result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
  this->i_kind = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  i_kind = this->i_kind;
  switch ( i_kind )
  {
    case Type_int16:
      p_i_data = &this->i_data;
      result = &this->i_data;
      if ( this != (SSLiteral *)-8i64 )
        AString::AString((AString *)p_i_data, binary_pp);
      break;
    case Type_int32:
      v6 = &this->i_data;
      result = &this->i_data;
      if ( this != (SSLiteral *)-8i64 )
        ASymbol::create_from_binary((ASymbol *)v6, binary_pp);
      break;
    case Type_float:
      v4 = ASymbol::create_from_binary((ASymbol *)&result, binary_pp);
      v5 = SSBrain::get_class(v4);
      this->i_data = (unsigned __int64)v5->vfptr->get_metaclass(v5);
      break;
    default:
      if ( (unsigned int)(i_kind - 7) > 3 )
      {
        this->i_data = *(unsigned int *)*binary_pp;
        *binary_pp = (char *)*binary_pp + 4;
      }
      break;
  }
}

// File Line: 495
// RVA: 0x11D910
SSInvokedBase *__fastcall SSLiteral::invoke(
        SSLiteral *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedBase *result; // rax
  unsigned __int64 i_data; // rax
  SSInstance *v7; // rax
  SSInstance *v8; // rax
  SSInvokedContextBase *v9; // rax

  if ( result_pp )
  {
    switch ( this->i_kind )
    {
      case Type_uint8:
        *result_pp = SSBoolean::pool_new(this->i_data);
        return 0i64;
      case Type_uint16:
        *result_pp = SSInstance::pool_new(SSBrain::c_char_class_p, this->i_data);
        return 0i64;
      case Type_uint32:
        *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, this->i_data);
        return 0i64;
      case Type_int8:
        *result_pp = SSInstance::pool_new(SSBrain::c_real_class_p, this->i_data);
        return 0i64;
      case Type_int16:
        *result_pp = SSString::as_instance((AString *)&this->i_data);
        return 0i64;
      case Type_int32:
        *result_pp = SSSymbol::as_instance((ASymbol *)&this->i_data);
        return 0i64;
      case Type_float:
        i_data = this->i_data;
        if ( i_data )
          goto LABEL_10;
        goto LABEL_13;
      case Type_string:
        goto $LN21_1;
      case Type_qVector2:
        v7 = scope_p->vfptr->get_topmost_scope(scope_p);
        ++v7->i_ref_count;
        *result_pp = v7;
        return 0i64;
      case Type_qVector3:
        v8 = scope_p->vfptr->get_topmost_scope(scope_p);
        i_data = (unsigned __int64)v8->i_class_p->vfptr->get_metaclass(v8->i_class_p);
        if ( i_data )
        {
LABEL_10:
          *result_pp = (SSInstance *)(i_data + 8);
          return 0i64;
        }
        else
        {
LABEL_13:
          result = 0i64;
          *result_pp = 0i64;
        }
        return result;
      case Type_qVector4:
        v9 = scope_p->vfptr->get_scope_context(scope_p);
        if ( v9 )
        {
          *result_pp = v9->vfptr->as_instance(v9);
          return 0i64;
        }
$LN21_1:
        *result_pp = SSBrain::c_nil_p;
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
  unsigned int size_dynamic_needed; // r8d
  unsigned int size_dynamic; // edx
  unsigned __int64 i_data; // rax

  v2 = 0i64;
  AMemoryStats::track_memory(mem_stats_p, "SSLiteral", 0x18u, 8u, 0, 0, 1u);
  size_dynamic_needed = 0;
  size_dynamic = 0;
  switch ( this->i_kind )
  {
    case Type_uint8:
      v2 = "SSLiteral.Boolean";
      break;
    case Type_uint16:
      v2 = "SSLiteral.Char";
      break;
    case Type_uint32:
      v2 = "SSLiteral.Integer";
      break;
    case Type_int8:
      v2 = "SSLiteral.Real";
      break;
    case Type_int16:
      i_data = this->i_data;
      v2 = "SSLiteral.String";
      size_dynamic = *(_DWORD *)(i_data + 12);
      size_dynamic_needed = *(_DWORD *)(i_data + 8) + 1;
      break;
    case Type_int32:
      v2 = "SSLiteral.Symbol";
      break;
    case Type_float:
      v2 = "SSLiteral.Class";
      break;
    case Type_string:
      v2 = "SSLiteral.nil";
      break;
    case Type_qVector2:
      v2 = "SSLiteral.this";
      break;
    case Type_qVector3:
      v2 = "SSLiteral.this_class";
      break;
    case Type_qVector4:
      v2 = "SSLiteral.this_code";
      break;
    default:
      break;
  }
  AMemoryStats::track_memory(mem_stats_p, v2, 0, 0, size_dynamic_needed, size_dynamic, 1u);
}

// File Line: 674
// RVA: 0x105DE0
void __fastcall SSLiteralList::SSLiteralList(SSLiteralList *this, const void **binary_pp)
{
  __int64 v4; // rbp
  SSExpressionBase **i_array_p; // rcx
  SSExpressionBase **v6; // rbx
  SSExpressionBase **i; // rbp
  eSSExprType v8; // ecx
  char *v9; // rax
  SSExpressionBase *v10; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteralList::`vftable;
  this->i_item_exprs.i_count = 0;
  this->i_item_exprs.i_array_p = 0i64;
  this->i_ctor_p = (SSMethodCall *)SSInvokeBase::from_binary_typed_new(binary_pp);
  v4 = *(unsigned __int16 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 2;
  if ( this->i_item_exprs.i_count != (_DWORD)v4 )
  {
    this->i_item_exprs.i_count = v4;
    i_array_p = this->i_item_exprs.i_array_p;
    if ( i_array_p )
      AMemory::c_free_func(i_array_p);
    this->i_item_exprs.i_array_p = APArrayBase<SSExpressionBase>::alloc_array(v4);
  }
  v6 = this->i_item_exprs.i_array_p;
  for ( i = &v6[v4]; v6 < i; ++v6 )
  {
    v8 = *(unsigned __int8 *)*binary_pp;
    v9 = (char *)*binary_pp + 1;
    *binary_pp = v9;
    if ( v8 )
    {
      *binary_pp = v9 + 2;
      v10 = SSExpressionBase::from_binary_new(v8, binary_pp);
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
__int64 __fastcall SSLiteralList::get_side_effect(SSLiteralList *this)
{
  __int64 i_count; // rax
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **v3; // rdi

  i_count = this->i_item_exprs.i_count;
  if ( !(_DWORD)i_count )
    return 0i64;
  i_array_p = this->i_item_exprs.i_array_p;
  v3 = &i_array_p[i_count];
  if ( i_array_p >= v3 )
    return 0i64;
  while ( (*i_array_p)->vfptr->get_side_effect(*i_array_p) == SSSideEffect_none )
  {
    if ( ++i_array_p >= v3 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 1039
// RVA: 0x11DB70
SSInvokedBase *__fastcall SSLiteralList::invoke(
        SSLiteralList *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInstance **v4; // r12
  SSLiteralList *v5; // r13
  __int64 i_count; // rbp
  SSExpressionBase **i_array_p; // rsi
  SSExpressionBase **v8; // r15
  unsigned int *v9; // rax
  unsigned int *v10; // rdi
  SSInstance *v11; // rbx
  SSInstance **v12; // rax
  _QWORD *v13; // r14
  SSClass *v14; // rbp
  AObjReusePool<SSInstance> *pool; // rsi
  unsigned int v16; // eax
  unsigned int v17; // eax
  __int64 v18; // rcx
  SSInstance **v19; // rax
  unsigned int v20; // eax
  SSMethodCall *i_ctor_p; // rcx
  __int64 v23; // rax
  ARefCountMix<SSInstance> **v24; // rbx
  ARefCountMix<SSInstance> **i; // rsi
  __int64 v27[11]; // [rsp+30h] [rbp-58h] BYREF
  SSInstance **v31; // [rsp+A8h] [rbp+20h] BYREF

  v31 = result_pp;
  v27[1] = -2i64;
  v4 = result_pp;
  v5 = this;
  i_count = this->i_item_exprs.i_count;
  i_array_p = this->i_item_exprs.i_array_p;
  v8 = &i_array_p[i_count];
  v9 = (unsigned int *)AMemory::c_malloc_func(0x18ui64, "SSList");
  v10 = v9;
  v27[0] = (__int64)v9;
  v11 = 0i64;
  if ( v9 )
  {
    *v9 = 0;
    *((_QWORD *)v9 + 1) = 0i64;
    v9[4] = 0;
    if ( (_DWORD)i_count )
    {
      v9[4] = i_count;
      v12 = APArrayBase<SSInstance>::alloc_array(i_count);
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
  v13 = (_QWORD *)*((_QWORD *)v10 + 1);
  if ( i_array_p < v8 )
  {
    do
    {
      (*i_array_p)->vfptr->invoke(*i_array_p, scope_p, caller_p, (SSInstance **)v27);
      *v13 = v27[0];
      ++i_array_p;
      ++v13;
    }
    while ( i_array_p < v8 );
    v4 = v31;
    v5 = this;
  }
  *v10 = i_count;
  if ( v5->i_ctor_p || v4 )
  {
    v14 = SSBrain::c_list_class_p;
    pool = SSInstance::get_pool();
    if ( pool->i_pool.i_count )
    {
      v20 = pool->i_pool.i_count - 1;
      pool->i_pool.i_count = v20;
      v18 = v20;
      v19 = pool->i_pool.i_array_p;
    }
    else
    {
      if ( !pool->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
      v16 = pool->i_exp_pool.i_count;
      if ( !v16 )
        goto LABEL_19;
      v17 = v16 - 1;
      pool->i_exp_pool.i_count = v17;
      v18 = v17;
      v19 = pool->i_exp_pool.i_array_p;
    }
    v11 = v19[v18];
LABEL_19:
    v11->i_class_p = v14;
    v11->i_user_data = (unsigned __int64)v10;
    v11->i_ref_count = 1;
    v11->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  }
  i_ctor_p = v5->i_ctor_p;
  if ( i_ctor_p )
    i_ctor_p->vfptr->invoke_call(i_ctor_p, v11, scope_p, caller_p, (SSInstance **)&v31);
  if ( v4 )
  {
    *v4 = v11;
  }
  else if ( v11 )
  {
    if ( v11->i_ref_count-- == 1 )
    {
      v11->i_ref_count = 0x80000000;
      v11->vfptr[1].get_scope_context(v11);
    }
  }
  else
  {
    v31 = (SSInstance **)v10;
    v23 = *v10;
    if ( (_DWORD)v23 )
    {
      v24 = (ARefCountMix<SSInstance> **)*((_QWORD *)v10 + 1);
      for ( i = &v24[v23]; v24 < i; ++v24 )
        ARefCountMix<SSInstance>::dereference(*v24 + 4);
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
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rdi
  SSMethodCall *i_ctor_p; // rcx

  i_array_p = this->i_item_exprs.i_array_p;
  for ( i = &i_array_p[this->i_item_exprs.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSLiteralList",
    0x20u,
    8u,
    8 * this->i_item_exprs.i_count,
    8 * this->i_item_exprs.i_count,
    1u);
  i_ctor_p = this->i_ctor_p;
  if ( i_ctor_p )
    i_ctor_p->vfptr->track_memory(i_ctor_p, mem_stats_p);
}

