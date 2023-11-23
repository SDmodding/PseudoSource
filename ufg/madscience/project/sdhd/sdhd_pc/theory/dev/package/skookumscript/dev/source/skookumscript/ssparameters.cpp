// File Line: 40
// RVA: 0x1461570
__int64 dynamic_initializer_for__SSParameters::c_shared_params__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSParameters::c_shared_params__);
}

// File Line: 55
// RVA: 0x106390
void __fastcall SSParameters::SSParameters(SSParameters *this)
{
  SSClass *v1; // rax

  this->i_ref_count = 0;
  this->i_params.i_count = 0;
  this->i_params.i_array_p = 0i64;
  this->i_return_params.i_count = 0;
  this->i_return_params.i_array_p = 0i64;
  v1 = SSBrain::c_object_class_p;
  this->i_result_type_p.i_obj_p = SSBrain::c_object_class_p;
  if ( v1 )
    (*(void (__fastcall **)(SSClass *))v1->vfptr->gap8)(v1);
}

// File Line: 73
// RVA: 0x1062F0
void __fastcall SSParameters::SSParameters(SSParameters *this, SSParameters *params_p)
{
  SSParameterBase **i_array_p; // r8
  SSTypedName **v5; // rcx
  SSClassDescBase *i_obj_p; // rcx
  SSClassDescBase *v7; // rcx
  APCompactArrayLogical<SSTypedName,ASymbol> *p_i_return_params; // [rsp+48h] [rbp+10h]

  this->i_ref_count = 0;
  i_array_p = params_p->i_params.i_array_p;
  this->i_params.i_count = params_p->i_params.i_count;
  this->i_params.i_array_p = i_array_p;
  params_p->i_params.i_count = 0;
  params_p->i_params.i_array_p = 0i64;
  p_i_return_params = &this->i_return_params;
  v5 = params_p->i_return_params.i_array_p;
  p_i_return_params->i_count = params_p->i_return_params.i_count;
  p_i_return_params->i_array_p = v5;
  params_p->i_return_params.i_count = 0;
  params_p->i_return_params.i_array_p = 0i64;
  this->i_result_type_p.i_obj_p = params_p->i_result_type_p.i_obj_p;
  i_obj_p = params_p->i_result_type_p.i_obj_p;
  if ( i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))i_obj_p->vfptr->gap8)(i_obj_p);
  v7 = params_p->i_result_type_p.i_obj_p;
  if ( v7 )
  {
    (*(void (__fastcall **)(SSClassDescBase *))&v7->vfptr->gap8[8])(v7);
    params_p->i_result_type_p.i_obj_p = 0i64;
  }
}

// File Line: 108
// RVA: 0x107600
void __fastcall SSParameters::~SSParameters(SSParameters *this)
{
  APCompactArrayLogical<SSParameterBase,ASymbol> *p_i_params; // rsi
  SSClassDescBase *i_obj_p; // rcx

  p_i_params = &this->i_params;
  APCompactArrayBase<SSParameterBase>::free_all(&this->i_params);
  APCompactArrayBase<SSTypedName>::free_all(&this->i_return_params);
  i_obj_p = this->i_result_type_p.i_obj_p;
  if ( i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
  AMemory::c_free_func(this->i_return_params.i_array_p);
  AMemory::c_free_func(p_i_params->i_array_p);
}

// File Line: 120
// RVA: 0x107C10
char __fastcall SSParameters::operator==(SSParameters *this, SSParameters *params)
{
  __int64 i_count; // rax
  __int64 v6; // r15
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v8; // rdi
  SSParameterBase **v9; // r14
  SSTypedName **v10; // rbx
  SSTypedName **v11; // rdi
  SSTypedName **v12; // rsi

  if ( this == params )
    return 1;
  if ( this->i_result_type_p.i_obj_p != params->i_result_type_p.i_obj_p )
    return 0;
  i_count = this->i_params.i_count;
  if ( (_DWORD)i_count != params->i_params.i_count )
    return 0;
  v6 = this->i_return_params.i_count;
  if ( (_DWORD)v6 != params->i_return_params.i_count )
    return 0;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_params.i_array_p;
    v8 = params->i_params.i_array_p;
    v9 = &i_array_p[i_count];
    if ( i_array_p < v9 )
    {
      while ( (*((unsigned __int8 (__fastcall **)(SSParameterBase *, SSParameterBase *))&(*i_array_p)->vfptr->__vecDelDtor
               + 1))(
                *i_array_p,
                *v8) )
      {
        ++i_array_p;
        ++v8;
        if ( i_array_p >= v9 )
          goto LABEL_14;
      }
      if ( i_array_p < v9 )
        return 0;
    }
  }
LABEL_14:
  if ( (_DWORD)v6 )
  {
    v10 = this->i_return_params.i_array_p;
    v11 = params->i_return_params.i_array_p;
    v12 = &v10[v6];
    if ( v10 < v12 )
    {
      while ( (*v10)->i_name.i_uid == (*v11)->i_name.i_uid
           && SSClassDescBase::compare((*v10)->i_type_p.i_obj_p, (*v11)->i_type_p.i_obj_p) == AEquate_equal )
      {
        ++v10;
        ++v11;
        if ( v10 >= v12 )
          return 1;
      }
      if ( v10 < v12 )
        return 0;
    }
  }
  return 1;
}

// File Line: 191
// RVA: 0x107D20
bool __fastcall SSParameters::operator<(SSParameters *this, SSParameters *params)
{
  __int64 i_count; // rdi
  unsigned int v4; // ecx
  unsigned int v7; // ecx
  __int64 v8; // rbp
  eAEquate v9; // ecx
  SSParameterBase **v10; // rbx
  SSParameterBase **v11; // rsi
  SSParameterBase **v12; // rdi
  SSTypedName **i_array_p; // rbx
  SSTypedName **v14; // rdi
  SSTypedName **v15; // rsi
  unsigned int i_uid; // eax
  unsigned int v17; // ecx

  i_count = this->i_params.i_count;
  v4 = params->i_params.i_count;
  if ( (_DWORD)i_count != v4 )
    return (unsigned int)i_count < v4;
  v7 = params->i_return_params.i_count;
  v8 = this->i_return_params.i_count;
  if ( (_DWORD)v8 != v7 )
    return (unsigned int)v8 < v7;
  v9 = SSClassDescBase::compare(this->i_result_type_p.i_obj_p, params->i_result_type_p.i_obj_p);
  if ( v9 )
    return v9 == AEquate_less;
  if ( (_DWORD)i_count
    && (v10 = this->i_params.i_array_p, v11 = &v10[i_count], v12 = params->i_params.i_array_p, v10 < v11) )
  {
    while ( (*((unsigned __int8 (__fastcall **)(SSParameterBase *, SSParameterBase *))&(*v10)->vfptr->__vecDelDtor + 1))(
              *v10,
              *v12) )
    {
      ++v10;
      ++v12;
      if ( v10 >= v11 )
        goto LABEL_11;
    }
    return (*v10)->vfptr->compare_less(*v10, *v12);
  }
  else
  {
LABEL_11:
    if ( (_DWORD)v8
      && (i_array_p = this->i_return_params.i_array_p,
          v14 = params->i_return_params.i_array_p,
          v15 = &i_array_p[v8],
          i_array_p < v15) )
    {
      while ( (*i_array_p)->i_name.i_uid == (*v14)->i_name.i_uid
           && SSClassDescBase::compare((*i_array_p)->i_type_p.i_obj_p, (*v14)->i_type_p.i_obj_p) == AEquate_equal )
      {
        ++i_array_p;
        ++v14;
        if ( i_array_p >= v15 )
          return 0;
      }
      i_uid = (*i_array_p)->i_name.i_uid;
      v17 = (*v14)->i_name.i_uid;
      return i_uid < v17
          || i_uid == v17
          && SSClassDescBase::compare((*i_array_p)->i_type_p.i_obj_p, (*v14)->i_type_p.i_obj_p) == AEquate_less;
    }
    else
    {
      return 0;
    }
  }
}

// File Line: 261
// RVA: 0x11F4E0
char __fastcall SSParameters::is_valid_arg_to(SSParameters *this, SSParameters *params)
{
  SSParameters *v2; // r15
  SSParameters *v3; // r14
  unsigned int i_count; // r12d
  __int64 v5; // rsi
  __int64 v6; // rbp
  SSParameterBase **i_array_p; // rcx
  SSGroupParam **v8; // r13
  SSGroupParam *v9; // rbx
  SSGroupParam *v10; // r14
  eSSParameter v11; // r15d
  eSSParameter v12; // eax
  __int32 v13; // eax
  SSClassDescBase *v14; // rbx
  SSClassDescBaseVtbl *vfptr; // rdi
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rdi
  __int64 v19; // rbx
  __int64 v20; // rax
  SSClassDescBase *v21; // rbx
  __int64 *v22; // rbx
  SSClassDescBase **v23; // rdi
  SSParameterBase **v25; // rbx
  unsigned int v26; // edi
  SSTypedName **v27; // rax
  SSTypedName **v28; // rbx
  char *v29; // rsi
  SSGroupParam param; // [rsp+28h] [rbp-60h] BYREF
  SSParameterBase **v33; // [rsp+A0h] [rbp+18h]

  v2 = params;
  v3 = this;
  if ( this != params )
  {
    if ( !this->i_result_type_p.i_obj_p->vfptr->is_class_type(
            this->i_result_type_p.i_obj_p,
            params->i_result_type_p.i_obj_p) )
      return 0;
    i_count = v3->i_params.i_count;
    v5 = 0i64;
    v6 = 0i64;
    i_array_p = v3->i_params.i_array_p;
    v33 = i_array_p;
    v8 = (SSGroupParam **)v2->i_params.i_array_p;
    if ( i_count )
    {
      while ( 1 )
      {
        if ( (unsigned int)v5 >= i_count )
          return 0;
        v9 = *v8;
        v10 = (SSGroupParam *)i_array_p[v5];
        v11 = v10->vfptr->get_kind(v10);
        v12 = v9->vfptr->get_kind(v9);
        if ( v12 )
        {
          v13 = v12 - 1;
          if ( !v13 )
          {
            if ( v11 != SSParameter_unary_default )
              return 0;
LABEL_12:
            v14 = v9->vfptr->get_expected_type(v9);
            vfptr = v14->vfptr;
            v16 = (__int64)v10->vfptr->get_expected_type(v10);
            if ( !vfptr->is_class_type(v14, (SSClassDescBase *)v16) )
              return 0;
            goto LABEL_23;
          }
          if ( v13 == 2 )
          {
            if ( v11 != SSParameter_group )
              goto LABEL_12;
            if ( !SSGroupParam::is_valid_arg_to(v10, v9) )
              return 0;
          }
        }
        else
        {
          v17 = (__int64)v9->vfptr->get_expected_type(v9);
          v18 = v17;
          if ( v11 == SSParameter_group )
          {
            v21 = (SSClassDescBase *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v17 + 112i64))(v17);
            if ( !v21 )
              return 0;
            param.i_name = (ASymbol)ASymbol::get_null()->i_uid;
            param.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
            param.i_class_pattern.i_count = 0;
            param.i_class_pattern.i_array_p = 0i64;
            param.i_class_pattern.i_size = 0;
            (*(void (__fastcall **)(SSClassDescBase *))v21->vfptr->gap8)(v21);
            APArray<SSClassDescBase,SSClassDescBase,ACompareAddress<SSClassDescBase>>::append(
              &param.i_class_pattern,
              v21);
            if ( !SSGroupParam::is_valid_arg_to(v10, &param) )
            {
              SSGroupParam::~SSGroupParam(&param);
              return 0;
            }
            param.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
            if ( param.i_class_pattern.i_count )
            {
              v22 = (__int64 *)param.i_class_pattern.i_array_p;
              v23 = &param.i_class_pattern.i_array_p[param.i_class_pattern.i_count];
              if ( param.i_class_pattern.i_array_p < v23 )
              {
                do
                   SSClassDescBase::`vcall{16,{flat}}(*v22++);
                while ( v22 < (__int64 *)v23 );
              }
            }
            AMemory::c_free_func(param.i_class_pattern.i_array_p);
            param.vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
          }
          else
          {
            v19 = *(_QWORD *)v17;
            v20 = (__int64)v10->vfptr->get_expected_type(v10);
            if ( !(*(unsigned __int8 (__fastcall **)(__int64, __int64))(v19 + 96))(v18, v20) )
              return 0;
          }
        }
LABEL_23:
        v5 = (unsigned int)(v5 + 1);
        v6 = (unsigned int)(v6 + 1);
        ++v8;
        i_array_p = v33;
        if ( (unsigned int)v6 >= i_count )
        {
          v3 = this;
          v2 = params;
          break;
        }
      }
    }
    if ( (unsigned int)v5 < i_count )
    {
      v25 = &i_array_p[v5];
      while ( (*v25)->vfptr->is_defaultable(*v25) )
      {
        LODWORD(v5) = v5 + 1;
        ++v25;
        if ( (unsigned int)v5 >= i_count )
          goto LABEL_31;
      }
      return 0;
    }
LABEL_31:
    v26 = v2->i_return_params.i_count;
    if ( v3->i_return_params.i_count < v26 )
      return 0;
    if ( v26 )
    {
      v27 = v2->i_return_params.i_array_p;
      if ( (unsigned int)v6 < v26 )
      {
        v28 = &v27[v6];
        v29 = (char *)((char *)v3->i_return_params.i_array_p - (char *)v27);
        while ( (*(SSTypedName **)((char *)v28 + (_QWORD)v29))->i_type_p.i_obj_p->vfptr->is_class_type(
                  (*(SSTypedName **)((char *)v28 + (_QWORD)v29))->i_type_p.i_obj_p,
                  (*v28)->i_type_p.i_obj_p) )
        {
          LODWORD(v6) = v6 + 1;
          ++v28;
          if ( (unsigned int)v6 >= v26 )
            return 1;
        }
        return 0;
      }
    }
  }
  return 1;
}

// File Line: 464
// RVA: 0x13C770
void __fastcall SSParameters::set_result_type(SSParameters *this, SSClassDescBase *rclass)
{
  SSClassDescBase *i_obj_p; // rcx

  if ( this->i_result_type_p.i_obj_p != rclass )
  {
    if ( rclass )
      (*(void (__fastcall **)(SSClassDescBase *))rclass->vfptr->gap8)(rclass);
    i_obj_p = this->i_result_type_p.i_obj_p;
    if ( i_obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
    this->i_result_type_p.i_obj_p = rclass;
  }
}

// File Line: 540
// RVA: 0x1060D0
void __fastcall SSParameters::SSParameters(SSParameters *this, const void **binary_pp)
{
  APCompactArrayLogical<SSParameterBase,ASymbol> *p_i_params; // rdi
  APCompactArrayLogical<SSTypedName,ASymbol> *p_i_return_params; // rsi
  __int64 v6; // rbp
  SSParameterBase **i_array_p; // rcx
  SSParameterBase **v8; // rdi
  SSParameterBase **i; // rbp
  __int64 v10; // rdi
  SSTypedName **v11; // rcx
  SSTypedName **v12; // rsi
  SSTypedName **v13; // rbp
  SSTypedName *v14; // rdi
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  SSClass *v19; // rcx
  SSClass *v20; // rax
  ASymbol *v21; // rax
  SSClass *v22; // rax
  ASymbol *v23; // rax
  eSSClassType v24; // ecx
  SSClassDescBase *v25; // rax
  SSClassDescBase *v26; // rbx
  SSClassDescBase *i_obj_p; // rcx
  APCompactArrayLogical<SSTypedName,ASymbol> *result; // [rsp+78h] [rbp+10h] BYREF
  ASymbol v29; // [rsp+80h] [rbp+18h] BYREF
  ASymbol v30; // [rsp+88h] [rbp+20h] BYREF

  this->i_ref_count = 0;
  p_i_params = &this->i_params;
  this->i_params.i_count = 0;
  this->i_params.i_array_p = 0i64;
  p_i_return_params = &this->i_return_params;
  result = &this->i_return_params;
  this->i_return_params.i_count = 0;
  this->i_return_params.i_array_p = 0i64;
  this->i_result_type_p.i_obj_p = 0i64;
  v6 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  APCompactArrayBase<SSParameterBase>::free_all(&this->i_params);
  if ( p_i_params->i_count != (_DWORD)v6 )
  {
    p_i_params->i_count = v6;
    i_array_p = p_i_params->i_array_p;
    if ( i_array_p )
      AMemory::c_free_func(i_array_p);
    p_i_params->i_array_p = APArrayBase<SSParameterBase>::alloc_array(v6);
  }
  v8 = this->i_params.i_array_p;
  for ( i = &v8[v6]; v8 < i; ++v8 )
    *v8 = SSParameterBase::from_binary_new(binary_pp);
  v10 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  APCompactArrayBase<SSTypedName>::free_all(p_i_return_params);
  if ( p_i_return_params->i_count != (_DWORD)v10 )
  {
    p_i_return_params->i_count = v10;
    v11 = p_i_return_params->i_array_p;
    if ( v11 )
      AMemory::c_free_func(v11);
    p_i_return_params->i_array_p = APArrayBase<SSTypedName>::alloc_array(v10);
  }
  v12 = this->i_return_params.i_array_p;
  v13 = &v12[v10];
  if ( v12 < v13 )
  {
    while ( 1 )
    {
      v14 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      if ( v14 )
        break;
      v14 = 0i64;
LABEL_29:
      *v12++ = v14;
      if ( v12 >= v13 )
        goto LABEL_30;
    }
    v14->i_name = (ASymbol)ASymbol::create_from_binary((ASymbol *)&result, binary_pp)->i_uid;
    v15 = *(unsigned __int8 *)*binary_pp;
    *binary_pp = (char *)*binary_pp + 1;
    if ( v15 )
    {
      v16 = v15 - 1;
      if ( v16 )
      {
        v17 = v16 - 1;
        if ( v17 )
        {
          v18 = v17 - 1;
          if ( v18 )
          {
            if ( v18 != 1 )
            {
              v19 = 0i64;
              goto LABEL_25;
            }
            v20 = (SSClass *)SSClassUnion::from_binary_ref(binary_pp);
          }
          else
          {
            v20 = (SSClass *)SSInvokableClass::from_binary_ref(binary_pp);
          }
        }
        else
        {
          v20 = (SSClass *)SSTypedClass::from_binary_ref(binary_pp);
        }
      }
      else
      {
        v21 = ASymbol::create_from_binary(&v29, binary_pp);
        v22 = SSBrain::get_class(v21);
        v20 = (SSClass *)v22->vfptr->get_metaclass(v22);
      }
    }
    else
    {
      v23 = ASymbol::create_from_binary(&v30, binary_pp);
      v20 = SSBrain::get_class(v23);
    }
    v19 = v20;
LABEL_25:
    v14->i_type_p.i_obj_p = v19;
    if ( v19 )
      (*(void (__fastcall **)(SSClass *))v19->vfptr->gap8)(v19);
    goto LABEL_29;
  }
LABEL_30:
  v24 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v25 = SSClassDescBase::from_binary_ref(v24, binary_pp);
  v26 = v25;
  if ( this->i_result_type_p.i_obj_p != v25 )
  {
    if ( v25 )
      (*(void (__fastcall **)(SSClassDescBase *))v25->vfptr->gap8)(v25);
    i_obj_p = this->i_result_type_p.i_obj_p;
    if ( i_obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
    this->i_result_type_p.i_obj_p = v26;
  }
}

// File Line: 746
// RVA: 0x117480
__int64 __fastcall SSParameters::get_arg_count_min(SSParameters *this)
{
  SSParameterBase **i_array_p; // rbx
  unsigned int v2; // edi
  SSParameterBase **i; // rsi

  i_array_p = this->i_params.i_array_p;
  v2 = 0;
  for ( i = &i_array_p[this->i_params.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( (*i_array_p)->vfptr->get_kind(*i_array_p) == SSParameter_unary )
      ++v2;
  }
  return v2;
}

// File Line: 767
// RVA: 0x13E7A0
void __fastcall SSParameters::track_memory(SSParameters *this, AMemoryStats *mem_stats_p)
{
  unsigned int i_count; // r14d
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **i; // rdi

  i_count = this->i_return_params.i_count;
  if ( i_count )
    AMemoryStats::track_memory(mem_stats_p, "SSTypedName", 0x10u, 0, 0, 0, this->i_return_params.i_count);
  i_array_p = this->i_params.i_array_p;
  for ( i = &i_array_p[this->i_params.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSParameters",
    0x30u,
    0,
    8 * (i_count + this->i_params.i_count),
    8 * (i_count + this->i_params.i_count),
    1u);
}

// File Line: 794
// RVA: 0x11ED50
char __fastcall SSParameters::is_generic(SSParameters *this)
{
  __int64 i_count; // rax
  SSParameterBase **v4; // rbx
  SSParameterBase **v5; // rdi
  __int64 v6; // rax
  SSTypedName **i_array_p; // rbx
  SSTypedName **v8; // rdi

  if ( this->i_result_type_p.i_obj_p->vfptr->is_generic(this->i_result_type_p.i_obj_p) )
    return 1;
  i_count = this->i_params.i_count;
  if ( (_DWORD)i_count && (v4 = this->i_params.i_array_p, v5 = &v4[i_count], v4 < v5) )
  {
    while ( !(*v4)->vfptr->is_generic(*v4) )
    {
      if ( ++v4 >= v5 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v6 = this->i_return_params.i_count;
    if ( !(_DWORD)v6 )
      return 0;
    i_array_p = this->i_return_params.i_array_p;
    v8 = &i_array_p[v6];
    if ( i_array_p >= v8 )
      return 0;
    while ( !(*i_array_p)->i_type_p.i_obj_p->vfptr->is_generic((*i_array_p)->i_type_p.i_obj_p) )
    {
      if ( ++i_array_p >= v8 )
        return 0;
    }
  }
  return 1;
}

// File Line: 860
// RVA: 0x10EE30
SSParameters *__fastcall SSParameters::as_finalized_generic(SSParameters *this, SSClassDescBase *scope_type)
{
  __int64 i_count; // rsi
  SSParameterBase **i_array_p; // rdi
  SSParameterBase **v6; // rbx
  SSParameterBase **i; // rsi
  __int64 v8; // rbx
  SSTypedName **v9; // rsi
  SSTypedName **v10; // rdi
  SSTypedName **j; // r15
  SSTypedName *v12; // r14
  SSTypedName *v13; // rbx
  __int64 v14; // rax
  SSParameters *v15; // rbx
  SSParameters params_p; // [rsp+28h] [rbp-38h] BYREF

  if ( !SSParameters::is_generic(this) )
    return this;
  params_p.i_ref_count = 0;
  params_p.i_params.i_count = 0;
  params_p.i_params.i_array_p = 0i64;
  params_p.i_return_params.i_count = 0;
  params_p.i_return_params.i_array_p = 0i64;
  params_p.i_result_type_p.i_obj_p = SSBrain::c_object_class_p;
  if ( SSBrain::c_object_class_p )
    (*(void (__fastcall **)(SSClass *))SSBrain::c_object_class_p->vfptr->gap8)(SSBrain::c_object_class_p);
  params_p.i_result_type_p.i_obj_p->vfptr->as_finalized_generic(params_p.i_result_type_p.i_obj_p, scope_type);
  i_count = this->i_params.i_count;
  if ( (_DWORD)i_count )
  {
    if ( params_p.i_params.i_count == (_DWORD)i_count )
    {
      i_array_p = params_p.i_params.i_array_p;
    }
    else
    {
      params_p.i_params.i_count = this->i_params.i_count;
      i_array_p = APArrayBase<SSParameterBase>::alloc_array(i_count);
      params_p.i_params.i_array_p = i_array_p;
    }
    v6 = this->i_params.i_array_p;
    for ( i = &v6[i_count]; v6 < i; ++v6 )
      *i_array_p++ = (*v6)->vfptr->as_finalized_generic(*v6, scope_type);
  }
  v8 = this->i_return_params.i_count;
  if ( (_DWORD)v8 )
  {
    if ( params_p.i_return_params.i_count == (_DWORD)v8 )
    {
      v9 = params_p.i_return_params.i_array_p;
    }
    else
    {
      params_p.i_return_params.i_count = this->i_return_params.i_count;
      if ( params_p.i_return_params.i_array_p )
        AMemory::c_free_func(params_p.i_return_params.i_array_p);
      v9 = APArrayBase<SSTypedName>::alloc_array(v8);
      params_p.i_return_params.i_array_p = v9;
    }
    v10 = this->i_return_params.i_array_p;
    for ( j = &v10[v8]; v10 < j; ++v10 )
    {
      v12 = *v10;
      v13 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      if ( v13 )
      {
        v14 = (__int64)v12->i_type_p.i_obj_p->vfptr->as_finalized_generic(v12->i_type_p.i_obj_p, scope_type);
        v13->i_name.i_uid = v12->i_name.i_uid;
        v13->i_type_p.i_obj_p = (SSClassDescBase *)v14;
        if ( v14 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 8i64))(v14);
      }
      else
      {
        v13 = 0i64;
      }
      *v9++ = v13;
    }
  }
  v15 = SSParameters::get_or_create(&params_p);
  APCompactArrayBase<SSParameterBase>::free_all(&params_p.i_params);
  APCompactArrayBase<SSTypedName>::free_all(&params_p.i_return_params);
  if ( params_p.i_result_type_p.i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])(params_p.i_result_type_p.i_obj_p);
  AMemory::c_free_func(params_p.i_return_params.i_array_p);
  AMemory::c_free_func(params_p.i_params.i_array_p);
  return v15;
}

// File Line: 932
// RVA: 0x118590
SSParameters *__fastcall SSParameters::get_or_create(SSParameters *params_p)
{
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v4; // rdi
  SSParameters *v5; // rax
  __int64 v6; // rax
  SSParameters *v7; // rbp
  SSParameters **v8; // rsi
  SSParameters **v9; // rdi
  SSParameters **v10; // rbx
  SSParameters *v11; // r15
  __int64 v12; // rcx
  signed __int64 v13; // rdi
  SSParameters *result; // rax
  SSParameters *v15; // rax
  SSParameters *v16; // rax

  i_count = params_p->i_params.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = params_p->i_params.i_array_p;
    v4 = &i_array_p[i_count];
    if ( i_array_p < v4 )
    {
      while ( !(*i_array_p)->vfptr->is_defaultable(*i_array_p) )
      {
        if ( ++i_array_p >= v4 )
          goto LABEL_9;
      }
      ++SSParameters::c_param_count;
      v5 = (SSParameters *)AMemory::c_malloc_func(0x30ui64, "SSParameters");
      if ( !v5 )
        return 0i64;
      SSParameters::SSParameters(v5, params_p);
      return (SSParameters *)v6;
    }
  }
LABEL_9:
  v7 = 0i64;
  if ( !SSParameters::c_shared_params.i_count )
  {
    LODWORD(v13) = 0;
LABEL_23:
    v15 = (SSParameters *)AMemory::c_malloc_func(0x30ui64, "SSParameters");
    if ( v15 )
    {
      SSParameters::SSParameters(v15, params_p);
      v7 = v16;
    }
    ++v7->i_ref_count;
    APSizedArrayBase<SSParameters>::insert(&SSParameters::c_shared_params, v7, v13);
    return v7;
  }
  v8 = SSParameters::c_shared_params.i_array_p;
  v9 = &SSParameters::c_shared_params.i_array_p[SSParameters::c_shared_params.i_count - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v10 = &v8[((char *)v9 - (char *)v8) >> 4];
      v11 = *v10;
      if ( !SSParameters::operator<(params_p, *v10) )
      {
        v12 = 1i64 - (unsigned __int8)SSParameters::operator==(params_p, v11);
        if ( v12 >= 0 )
          break;
      }
      if ( v8 == v10 )
      {
        LODWORD(v13) = v10 - SSParameters::c_shared_params.i_array_p;
        goto LABEL_23;
      }
      v9 = v10 - 1;
    }
    if ( v12 <= 0 )
      break;
    if ( v9 == v10 )
    {
      v13 = ((char *)v9 - (char *)SSParameters::c_shared_params.i_array_p + 8) >> 3;
      goto LABEL_23;
    }
    v8 = v10 + 1;
  }
  v13 = (unsigned int)(v10 - SSParameters::c_shared_params.i_array_p);
  result = SSParameters::c_shared_params.i_array_p[v13];
  if ( !result )
    goto LABEL_23;
  return result;
}

