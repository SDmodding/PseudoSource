// File Line: 40
// RVA: 0x1461570
__int64 dynamic_initializer_for__SSParameters::c_shared_params__()
{
  return atexit(dynamic_atexit_destructor_for__SSParameters::c_shared_params__);
}

// File Line: 55
// RVA: 0x106390
void __fastcall SSParameters::SSParameters(SSParameters *this)
{
  SSClass *v1; // rax
  APCompactArrayLogical<SSParameterBase,ASymbol> *v2; // [rsp+48h] [rbp+10h]
  APCompactArrayLogical<SSTypedName,ASymbol> *v3; // [rsp+48h] [rbp+10h]

  this->i_ref_count = 0;
  v2 = &this->i_params;
  v2->i_count = 0;
  v2->i_array_p = 0i64;
  v3 = &this->i_return_params;
  v3->i_count = 0;
  v3->i_array_p = 0i64;
  v1 = SSBrain::c_object_class_p;
  this->i_result_type_p.i_obj_p = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
  if ( v1 )
    (*(void (__fastcall **)(SSClass *))v1->vfptr->gap8)(v1);
}

// File Line: 73
// RVA: 0x1062F0
void __fastcall SSParameters::SSParameters(SSParameters *this, SSParameters *params_p)
{
  SSParameters *v2; // rbx
  SSParameters *v3; // rdi
  SSParameterBase **v4; // r8
  SSTypedName **v5; // rcx
  SSClassDescBase *v6; // rcx
  SSClassDescBase *v7; // rcx
  APCompactArrayLogical<SSParameterBase,ASymbol> *v8; // [rsp+48h] [rbp+10h]
  APCompactArrayLogical<SSTypedName,ASymbol> *v9; // [rsp+48h] [rbp+10h]

  v2 = params_p;
  v3 = this;
  this->i_ref_count = 0;
  v8 = &this->i_params;
  v4 = params_p->i_params.i_array_p;
  v8->i_count = params_p->i_params.i_count;
  v8->i_array_p = v4;
  params_p->i_params.i_count = 0;
  params_p->i_params.i_array_p = 0i64;
  v9 = &this->i_return_params;
  v5 = params_p->i_return_params.i_array_p;
  v9->i_count = params_p->i_return_params.i_count;
  v9->i_array_p = v5;
  params_p->i_return_params.i_count = 0;
  params_p->i_return_params.i_array_p = 0i64;
  v3->i_result_type_p.i_obj_p = params_p->i_result_type_p.i_obj_p;
  v6 = params_p->i_result_type_p.i_obj_p;
  if ( v6 )
    (*(void (__cdecl **)(SSClassDescBase *))v6->vfptr->gap8)(v6);
  v7 = v2->i_result_type_p.i_obj_p;
  if ( v7 )
  {
    (*(void (__cdecl **)(SSClassDescBase *))&v7->vfptr->gap8[8])(v7);
    v2->i_result_type_p.i_obj_p = 0i64;
  }
}

// File Line: 108
// RVA: 0x107600
void __fastcall SSParameters::~SSParameters(SSParameters *this)
{
  SSParameters *v1; // rbx
  void **v2; // rsi
  SSClassDescBase *v3; // rcx

  v1 = this;
  v2 = (void **)&this->i_params;
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_params.i_count);
  APCompactArrayBase<SSTypedName>::free_all((APCompactArrayBase<SSTypedName> *)&v1->i_return_params.i_count);
  v3 = v1->i_result_type_p.i_obj_p;
  if ( v3 )
    (*(void (__cdecl **)(SSClassDescBase *))&v3->vfptr->gap8[8])(v3);
  AMemory::c_free_func(v1->i_return_params.i_array_p);
  AMemory::c_free_func(v2[1]);
}

// File Line: 120
// RVA: 0x107C10
char __fastcall SSParameters::operator==(SSParameters *this, SSParameters *params)
{
  SSParameters *v2; // rbp
  SSParameters *v3; // rsi
  __int64 v5; // rax
  __int64 v6; // r15
  SSParameterBase **v7; // rbx
  SSParameterBase **v8; // rdi
  unsigned __int64 v9; // r14
  SSTypedName **v10; // rbx
  SSTypedName **v11; // rdi
  unsigned __int64 v12; // rsi

  v2 = params;
  v3 = this;
  if ( this == params )
    return 1;
  if ( this->i_result_type_p.i_obj_p != params->i_result_type_p.i_obj_p )
    return 0;
  v5 = this->i_params.i_count;
  if ( (_DWORD)v5 != params->i_params.i_count )
    return 0;
  v6 = this->i_return_params.i_count;
  if ( (_DWORD)v6 != params->i_return_params.i_count )
    return 0;
  if ( !(_DWORD)v5 )
    goto LABEL_14;
  v7 = this->i_params.i_array_p;
  v8 = params->i_params.i_array_p;
  v9 = (unsigned __int64)&v7[v5];
  if ( (unsigned __int64)v7 >= v9 )
    goto LABEL_14;
  while ( (*((unsigned __int8 (__fastcall **)(SSParameterBase *, SSParameterBase *))&(*v7)->vfptr->__vecDelDtor + 1))(
            *v7,
            *v8) )
  {
    ++v7;
    ++v8;
    if ( (unsigned __int64)v7 >= v9 )
      goto LABEL_14;
  }
  if ( (unsigned __int64)v7 >= v9 )
  {
LABEL_14:
    if ( !(_DWORD)v6 )
      return 1;
    v10 = v3->i_return_params.i_array_p;
    v11 = v2->i_return_params.i_array_p;
    v12 = (unsigned __int64)&v10[v6];
    if ( (unsigned __int64)v10 >= v12 )
      return 1;
    while ( (*v10)->i_name.i_uid == (*v11)->i_name.i_uid
         && SSClassDescBase::compare((*v10)->i_type_p.i_obj_p, (*v11)->i_type_p.i_obj_p) == AEquate_equal )
    {
      ++v10;
      ++v11;
      if ( (unsigned __int64)v10 >= v12 )
        return 1;
    }
    if ( (unsigned __int64)v10 >= v12 )
      return 1;
  }
  return 0;
}

// File Line: 191
// RVA: 0x107D20
bool __fastcall SSParameters::operator<(SSParameters *this, SSParameters *params)
{
  __int64 v2; // rdi
  SSParameters *v3; // r15
  unsigned int v4; // ecx
  SSParameters *v5; // r14
  bool result; // al
  unsigned int v7; // ecx
  __int64 v8; // rbp
  eAEquate v9; // ecx
  SSParameterBase **v10; // rbx
  unsigned __int64 v11; // rsi
  SSParameterBase **v12; // rdi
  SSTypedName **v13; // rbx
  SSTypedName **v14; // rdi
  unsigned __int64 v15; // rsi
  unsigned int v16; // eax
  unsigned int v17; // ecx

  v2 = this->i_params.i_count;
  v3 = this;
  v4 = params->i_params.i_count;
  v5 = params;
  if ( (_DWORD)v2 != v4 )
    return (unsigned int)v2 < v4;
  v7 = params->i_return_params.i_count;
  v8 = v3->i_return_params.i_count;
  if ( (_DWORD)v8 != v7 )
    return (unsigned int)v8 < v7;
  v9 = SSClassDescBase::compare(v3->i_result_type_p.i_obj_p, params->i_result_type_p.i_obj_p);
  if ( v9 )
    return v9 == -1;
  if ( (_DWORD)v2
    && (v10 = v3->i_params.i_array_p,
        v11 = (unsigned __int64)&v10[v2],
        v12 = v5->i_params.i_array_p,
        (unsigned __int64)v10 < v11) )
  {
    while ( (*((unsigned __int8 (__fastcall **)(SSParameterBase *, SSParameterBase *))&(*v10)->vfptr->__vecDelDtor + 1))(
              *v10,
              *v12) )
    {
      ++v10;
      ++v12;
      if ( (unsigned __int64)v10 >= v11 )
        goto LABEL_11;
    }
    result = (*v10)->vfptr->compare_less(*v10, *v12);
  }
  else
  {
LABEL_11:
    if ( (_DWORD)v8
      && (v13 = v3->i_return_params.i_array_p,
          v14 = v5->i_return_params.i_array_p,
          v15 = (unsigned __int64)&v13[v8],
          (unsigned __int64)v13 < v15) )
    {
      while ( (*v13)->i_name.i_uid == (*v14)->i_name.i_uid
           && SSClassDescBase::compare((*v13)->i_type_p.i_obj_p, (*v14)->i_type_p.i_obj_p) == AEquate_equal )
      {
        ++v13;
        ++v14;
        if ( (unsigned __int64)v13 >= v15 )
          goto LABEL_16;
      }
      v16 = (*v13)->i_name.i_uid;
      v17 = (*v14)->i_name.i_uid;
      result = v16 < v17
            || v16 == v17 && SSClassDescBase::compare((*v13)->i_type_p.i_obj_p, (*v14)->i_type_p.i_obj_p) == -1;
    }
    else
    {
LABEL_16:
      result = 0;
    }
  }
  return result;
}

// File Line: 261
// RVA: 0x11F4E0
char __fastcall SSParameters::is_valid_arg_to(SSParameters *this, SSParameters *params)
{
  SSParameters *v2; // r15
  SSParameters *v3; // r14
  __int64 v4; // rdx
  __int64 v5; // r8
  unsigned int v6; // er12
  __int64 v7; // rsi
  __int64 v8; // rbp
  SSParameterBase **v9; // rcx
  SSGroupParam **v10; // r13
  SSGroupParam *v11; // rbx
  SSGroupParam *v12; // r14
  eSSParameter v13; // er15
  eSSParameter v14; // eax
  int v15; // eax
  __int64 *v16; // rbx
  __int64 v17; // rdi
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rdi
  __int64 v21; // rbx
  __int64 v22; // rax
  SSClassDescBase *v23; // rbx
  __int64 *v24; // rbx
  SSClassDescBase **v25; // rdi
  SSParameterBase **v27; // rbx
  unsigned int v28; // edi
  SSTypedName **v29; // rax
  signed __int64 v30; // rbx
  char *v31; // rsi
  SSGroupParam param; // [rsp+28h] [rbp-60h]
  SSParameters *v33; // [rsp+90h] [rbp+8h]
  SSParameters *v34; // [rsp+98h] [rbp+10h]
  SSParameterBase **v35; // [rsp+A0h] [rbp+18h]

  v34 = params;
  v33 = this;
  v2 = params;
  v3 = this;
  if ( this != params )
  {
    if ( !this->i_result_type_p.i_obj_p->vfptr->is_class_type(
            this->i_result_type_p.i_obj_p,
            params->i_result_type_p.i_obj_p) )
      return 0;
    v6 = v3->i_params.i_count;
    v7 = 0i64;
    v8 = 0i64;
    v9 = v3->i_params.i_array_p;
    v35 = v3->i_params.i_array_p;
    v10 = (SSGroupParam **)v2->i_params.i_array_p;
    if ( v6 )
    {
      while ( 1 )
      {
        if ( (unsigned int)v7 >= v6 )
          return 0;
        v11 = *v10;
        v12 = (SSGroupParam *)v9[v7];
        v13 = (unsigned int)v12->vfptr->get_kind(v9[v7]);
        v14 = (unsigned int)v11->vfptr->get_kind((SSParameterBase *)&v11->vfptr);
        if ( v14 )
        {
          v15 = v14 - 1;
          if ( !v15 )
          {
            if ( v13 != 1 )
              return 0;
LABEL_12:
            v16 = (__int64 *)v11->vfptr->get_expected_type((SSParameterBase *)&v11->vfptr);
            v17 = *v16;
            v18 = (__int64)v12->vfptr->get_expected_type((SSParameterBase *)&v12->vfptr);
            if ( !(*(unsigned __int8 (__fastcall **)(__int64 *, __int64))(v17 + 96))(v16, v18) )
              return 0;
            goto LABEL_23;
          }
          if ( v15 == 2 )
          {
            if ( v13 != 3 )
              goto LABEL_12;
            if ( !SSGroupParam::is_valid_arg_to(v12, v11) )
              return 0;
          }
        }
        else
        {
          v19 = (__int64)v11->vfptr->get_expected_type((SSParameterBase *)&v11->vfptr);
          v20 = v19;
          if ( v13 == 3 )
          {
            v23 = (SSClassDescBase *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v19 + 112i64))(v19);
            if ( !v23 )
              return 0;
            param.i_name = (ASymbol)ASymbol::get_null()->i_uid;
            param.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
            param.i_class_pattern.i_count = 0;
            param.i_class_pattern.i_array_p = 0i64;
            param.i_class_pattern.i_size = 0;
            (*(void (__fastcall **)(SSClassDescBase *))v23->vfptr->gap8)(v23);
            APArray<SSClassDescBase,SSClassDescBase,ACompareAddress<SSClassDescBase>>::append(
              &param.i_class_pattern,
              v23);
            if ( !SSGroupParam::is_valid_arg_to(v12, &param) )
            {
              SSGroupParam::~SSGroupParam(&param);
              return 0;
            }
            param.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
            if ( param.i_class_pattern.i_count )
            {
              v24 = (__int64 *)param.i_class_pattern.i_array_p;
              v25 = &param.i_class_pattern.i_array_p[param.i_class_pattern.i_count];
              if ( param.i_class_pattern.i_array_p < v25 )
              {
                do
                {
                   SSClassDescBase::`vcall'{16,{flat}}(*v24);
                  ++v24;
                }
                while ( v24 < (__int64 *)v25 );
              }
            }
            AMemory::c_free_func(param.i_class_pattern.i_array_p);
            param.vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
          }
          else
          {
            v21 = *(_QWORD *)v19;
            v22 = (__int64)v12->vfptr->get_expected_type((SSParameterBase *)&v12->vfptr);
            if ( !(*(unsigned __int8 (__fastcall **)(__int64, __int64))(v21 + 96))(v20, v22) )
              return 0;
          }
        }
LABEL_23:
        v7 = (unsigned int)(v7 + 1);
        v8 = (unsigned int)(v8 + 1);
        ++v10;
        v9 = v35;
        if ( (unsigned int)v8 >= v6 )
        {
          v3 = v33;
          v2 = v34;
          break;
        }
      }
    }
    if ( (unsigned int)v7 < v6 )
    {
      v27 = &v9[v7];
      while ( ((unsigned __int8 (__cdecl *)(SSParameterBase *, __int64, __int64))(*v27)->vfptr->is_defaultable)(
                *v27,
                v4,
                v5) )
      {
        LODWORD(v7) = v7 + 1;
        ++v27;
        if ( (unsigned int)v7 >= v6 )
          goto LABEL_31;
      }
      return 0;
    }
LABEL_31:
    v28 = v2->i_return_params.i_count;
    if ( v3->i_return_params.i_count < v28 )
      return 0;
    if ( v28 )
    {
      v29 = v2->i_return_params.i_array_p;
      if ( (unsigned int)v8 < v28 )
      {
        v30 = (signed __int64)&v29[v8];
        v31 = (char *)((char *)v3->i_return_params.i_array_p - (char *)v29);
        while ( (*(unsigned __int8 (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)(*(_QWORD *)&v31[v30] + 8i64) + 96i64))(
                  *(_QWORD *)(*(_QWORD *)&v31[v30] + 8i64),
                  *(_QWORD *)(*(_QWORD *)v30 + 8i64)) )
        {
          LODWORD(v8) = v8 + 1;
          v30 += 8i64;
          if ( (unsigned int)v8 >= v28 )
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
  SSClassDescBase *v2; // rbx
  SSParameters *v3; // rdi
  SSClassDescBase *v4; // rcx

  v2 = rclass;
  v3 = this;
  if ( this->i_result_type_p.i_obj_p != rclass )
  {
    if ( rclass )
      (*(void (__fastcall **)(SSClassDescBase *))rclass->vfptr->gap8)(rclass);
    v4 = v3->i_result_type_p.i_obj_p;
    if ( v4 )
      (*(void (**)(void))&v4->vfptr->gap8[8])();
    v3->i_result_type_p.i_obj_p = v2;
  }
}

// File Line: 540
// RVA: 0x1060D0
void __fastcall SSParameters::SSParameters(SSParameters *this, const void **binary_pp)
{
  const void **v2; // rbx
  SSParameters *v3; // r14
  APCompactArrayLogical<SSParameterBase,ASymbol> *v4; // rdi
  APCompactArrayBase<SSTypedName> *v5; // rsi
  __int64 v6; // rbp
  SSParameterBase **v7; // rcx
  SSParameterBase **v8; // rdi
  unsigned __int64 i; // rbp
  __int64 v10; // rdi
  SSTypedName **v11; // rcx
  SSTypedName **v12; // rsi
  unsigned __int64 v13; // rbp
  SSTypedName *v14; // rdi
  __int64 v15; // rdx
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  SSClass *v20; // rcx
  SSClass *v21; // rax
  ASymbol *v22; // rax
  SSClass *v23; // rax
  ASymbol *v24; // rax
  eSSClassType v25; // ecx
  SSClassDescBase *v26; // rax
  __int64 v27; // rdx
  SSClassDescBase *v28; // rbx
  SSClassDescBase *v29; // rcx
  APCompactArrayBase<SSTypedName> *result; // [rsp+78h] [rbp+10h]
  ASymbol v31; // [rsp+80h] [rbp+18h]
  ASymbol v32; // [rsp+88h] [rbp+20h]

  v2 = binary_pp;
  v3 = this;
  this->i_ref_count = 0;
  v4 = &this->i_params;
  v4->i_count = 0;
  v4->i_array_p = 0i64;
  v5 = (APCompactArrayBase<SSTypedName> *)&this->i_return_params.i_count;
  result = v5;
  v5->i_count = 0;
  v5->i_array_p = 0i64;
  this->i_result_type_p.i_obj_p = 0i64;
  v6 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_params.i_count);
  if ( v4->i_count != (_DWORD)v6 )
  {
    v4->i_count = v6;
    v7 = v4->i_array_p;
    if ( v7 )
      AMemory::c_free_func(v7);
    v4->i_array_p = APArrayBase<SSParameterBase>::alloc_array(v6);
  }
  v8 = v3->i_params.i_array_p;
  for ( i = (unsigned __int64)&v8[v6]; (unsigned __int64)v8 < i; ++v8 )
    *v8 = SSParameterBase::from_binary_new(v2);
  v10 = *(unsigned __int8 *)*v2;
  *v2 = (char *)*v2 + 1;
  APCompactArrayBase<SSTypedName>::free_all(v5);
  if ( v5->i_count != (_DWORD)v10 )
  {
    v5->i_count = v10;
    v11 = v5->i_array_p;
    if ( v11 )
      AMemory::c_free_func(v11);
    v5->i_array_p = APArrayBase<SSTypedName>::alloc_array(v10);
  }
  v12 = v3->i_return_params.i_array_p;
  v13 = (unsigned __int64)&v12[v10];
  if ( (unsigned __int64)v12 < v13 )
  {
    while ( 1 )
    {
      v14 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      if ( v14 )
        break;
      v14 = 0i64;
LABEL_29:
      *v12 = v14;
      ++v12;
      if ( (unsigned __int64)v12 >= v13 )
        goto LABEL_30;
    }
    v14->i_name = (ASymbol)ASymbol::create_from_binary((ASymbol *)&result, v2)->i_uid;
    v16 = *(unsigned __int8 *)*v2;
    *v2 = (char *)*v2 + 1;
    if ( v16 )
    {
      v17 = v16 - 1;
      if ( v17 )
      {
        v18 = v17 - 1;
        if ( v18 )
        {
          v19 = v18 - 1;
          if ( v19 )
          {
            if ( v19 != 1 )
            {
              v20 = 0i64;
              goto LABEL_25;
            }
            v21 = (SSClass *)SSClassUnion::from_binary_ref(v2);
          }
          else
          {
            v21 = (SSClass *)SSInvokableClass::from_binary_ref(v2);
          }
        }
        else
        {
          v21 = (SSClass *)SSTypedClass::from_binary_ref(v2);
        }
      }
      else
      {
        v22 = ASymbol::create_from_binary(&v31, v2);
        v23 = SSBrain::get_class(v22);
        v21 = (SSClass *)v23->vfptr->get_metaclass((SSClassDescBase *)&v23->vfptr);
      }
    }
    else
    {
      v24 = ASymbol::create_from_binary(&v32, v2);
      v21 = SSBrain::get_class(v24);
    }
    v20 = v21;
LABEL_25:
    v14->i_type_p.i_obj_p = (SSClassDescBase *)&v20->vfptr;
    if ( v20 )
      (*(void (__cdecl **)(SSClass *, __int64))v20->vfptr->gap8)(v20, v15);
    goto LABEL_29;
  }
LABEL_30:
  v25 = *(unsigned __int8 *)*v2;
  *v2 = (char *)*v2 + 1;
  v26 = SSClassDescBase::from_binary_ref(v25, v2);
  v28 = v26;
  if ( v3->i_result_type_p.i_obj_p != v26 )
  {
    if ( v26 )
      (*(void (__fastcall **)(SSClassDescBase *))v26->vfptr->gap8)(v26);
    v29 = v3->i_result_type_p.i_obj_p;
    if ( v29 )
      (*(void (__cdecl **)(SSClassDescBase *, __int64))&v29->vfptr->gap8[8])(v29, v27);
    v3->i_result_type_p.i_obj_p = v28;
  }
}

// File Line: 746
// RVA: 0x117480
__int64 __fastcall SSParameters::get_arg_count_min(SSParameters *this)
{
  SSParameterBase **v1; // rbx
  unsigned int v2; // edi
  unsigned __int64 i; // rsi

  v1 = this->i_params.i_array_p;
  v2 = 0;
  for ( i = (unsigned __int64)&v1[this->i_params.i_count]; (unsigned __int64)v1 < i; ++v1 )
  {
    if ( !((unsigned int (*)(void))(*v1)->vfptr->get_kind)() )
      ++v2;
  }
  return v2;
}

// File Line: 767
// RVA: 0x13E7A0
void __fastcall SSParameters::track_memory(SSParameters *this, AMemoryStats *mem_stats_p)
{
  unsigned int v2; // er14
  AMemoryStats *v3; // rsi
  SSParameters *v4; // rbp
  SSParameterBase **v5; // rbx
  unsigned __int64 i; // rdi

  v2 = this->i_return_params.i_count;
  v3 = mem_stats_p;
  v4 = this;
  if ( v2 )
    AMemoryStats::track_memory(mem_stats_p, "SSTypedName", 0x10u, 0, 0, 0, this->i_return_params.i_count);
  v5 = v4->i_params.i_array_p;
  for ( i = (unsigned __int64)&v5[v4->i_params.i_count]; (unsigned __int64)v5 < i; ++v5 )
  {
    if ( *v5 )
      (*v5)->vfptr->track_memory(*v5, v3);
  }
  AMemoryStats::track_memory(
    v3,
    "SSParameters",
    0x30u,
    0,
    8 * (v2 + v4->i_params.i_count),
    8 * (v2 + v4->i_params.i_count),
    1u);
}

// File Line: 794
// RVA: 0x11ED50
char __fastcall SSParameters::is_generic(SSParameters *this)
{
  SSParameters *v1; // rsi
  __int64 v3; // rax
  SSParameterBase **v4; // rbx
  unsigned __int64 v5; // rdi
  __int64 v6; // rax
  SSTypedName **v7; // rbx
  unsigned __int64 v8; // rdi

  v1 = this;
  if ( ((unsigned __int8 (*)(void))this->i_result_type_p.i_obj_p->vfptr->is_generic)() )
    return 1;
  v3 = v1->i_params.i_count;
  if ( (_DWORD)v3 && (v4 = v1->i_params.i_array_p, v5 = (unsigned __int64)&v4[v3], (unsigned __int64)v4 < v5) )
  {
    while ( !((unsigned __int8 (*)(void))(*v4)->vfptr->is_generic)() )
    {
      ++v4;
      if ( (unsigned __int64)v4 >= v5 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v6 = v1->i_return_params.i_count;
    if ( !(_DWORD)v6 )
      return 0;
    v7 = v1->i_return_params.i_array_p;
    v8 = (unsigned __int64)&v7[v6];
    if ( (unsigned __int64)v7 >= v8 )
      return 0;
    while ( !((unsigned __int8 (*)(void))(*v7)->i_type_p.i_obj_p->vfptr->is_generic)() )
    {
      ++v7;
      if ( (unsigned __int64)v7 >= v8 )
        return 0;
    }
  }
  return 1;
}

// File Line: 860
// RVA: 0x10EE30
SSParameters *__fastcall SSParameters::as_finalized_generic(SSParameters *this, SSClassDescBase *scope_type)
{
  SSClassDescBase *v2; // r12
  SSParameters *v3; // r14
  __int64 v4; // rdx
  __int64 v5; // rsi
  SSParameterBase **v6; // rdi
  SSParameterBase **v7; // rbx
  unsigned __int64 i; // rsi
  __int64 v9; // rbx
  SSTypedName **v10; // rsi
  SSTypedName **v11; // rdi
  unsigned __int64 j; // r15
  SSTypedName *v13; // r14
  SSTypedName *v14; // rbx
  __int64 v15; // rax
  SSParameters *v16; // rbx
  __int64 v17; // rdx
  SSParameters params_p; // [rsp+28h] [rbp-38h]

  v2 = scope_type;
  v3 = this;
  if ( !SSParameters::is_generic(this) )
    return v3;
  params_p.i_ref_count = 0;
  params_p.i_params.i_count = 0;
  params_p.i_params.i_array_p = 0i64;
  params_p.i_return_params.i_count = 0;
  params_p.i_return_params.i_array_p = 0i64;
  params_p.i_result_type_p.i_obj_p = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
  if ( SSBrain::c_object_class_p )
    (*(void (__cdecl **)(SSClass *, __int64))SSBrain::c_object_class_p->vfptr->gap8)(SSBrain::c_object_class_p, v4);
  params_p.i_result_type_p.i_obj_p->vfptr->as_finalized_generic(params_p.i_result_type_p.i_obj_p, v2);
  v5 = v3->i_params.i_count;
  if ( (_DWORD)v5 )
  {
    if ( params_p.i_params.i_count == (_DWORD)v5 )
    {
      v6 = params_p.i_params.i_array_p;
    }
    else
    {
      params_p.i_params.i_count = v3->i_params.i_count;
      if ( params_p.i_params.i_array_p )
        AMemory::c_free_func(params_p.i_params.i_array_p);
      v6 = APArrayBase<SSParameterBase>::alloc_array(v5);
      params_p.i_params.i_array_p = v6;
    }
    v7 = v3->i_params.i_array_p;
    for ( i = (unsigned __int64)&v7[v5]; (unsigned __int64)v7 < i; ++v7 )
    {
      *v6 = (*v7)->vfptr->as_finalized_generic(*v7, v2);
      ++v6;
    }
  }
  v9 = v3->i_return_params.i_count;
  if ( (_DWORD)v9 )
  {
    if ( params_p.i_return_params.i_count == (_DWORD)v9 )
    {
      v10 = params_p.i_return_params.i_array_p;
    }
    else
    {
      params_p.i_return_params.i_count = v3->i_return_params.i_count;
      if ( params_p.i_return_params.i_array_p )
        AMemory::c_free_func(params_p.i_return_params.i_array_p);
      v10 = APArrayBase<SSTypedName>::alloc_array(v9);
      params_p.i_return_params.i_array_p = v10;
    }
    v11 = v3->i_return_params.i_array_p;
    for ( j = (unsigned __int64)&v11[v9]; (unsigned __int64)v11 < j; ++v11 )
    {
      v13 = *v11;
      v14 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      if ( v14 )
      {
        v15 = (__int64)v13->i_type_p.i_obj_p->vfptr->as_finalized_generic(v13->i_type_p.i_obj_p, v2);
        v14->i_name.i_uid = v13->i_name.i_uid;
        v14->i_type_p.i_obj_p = (SSClassDescBase *)v15;
        if ( v15 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 8i64))(v15);
      }
      else
      {
        v14 = 0i64;
      }
      *v10 = v14;
      ++v10;
    }
  }
  v16 = SSParameters::get_or_create(&params_p);
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&params_p.i_params.i_count);
  APCompactArrayBase<SSTypedName>::free_all((APCompactArrayBase<SSTypedName> *)&params_p.i_return_params.i_count);
  if ( params_p.i_result_type_p.i_obj_p )
    (*(void (__cdecl **)(SSClassDescBase *, __int64))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])(
      params_p.i_result_type_p.i_obj_p,
      v17);
  AMemory::c_free_func(params_p.i_return_params.i_array_p);
  AMemory::c_free_func(params_p.i_params.i_array_p);
  return v16;
}

// File Line: 932
// RVA: 0x118590
SSParameters *__fastcall SSParameters::get_or_create(SSParameters *params_p)
{
  SSParameters *v1; // r14
  __int64 v2; // rax
  SSParameterBase **v3; // rbx
  unsigned __int64 v4; // rdi
  SSParameters *v5; // rax
  __int64 v6; // rax
  SSParameters *v7; // rbp
  SSParameters **v8; // rsi
  SSParameters **v9; // rdi
  SSParameters **v10; // rbx
  SSParameters *v11; // r15
  signed __int64 v12; // rcx
  signed __int64 v13; // rdi
  SSParameters *result; // rax
  SSParameters *v15; // rax
  SSParameters *v16; // rax

  v1 = params_p;
  v2 = params_p->i_params.i_count;
  if ( (_DWORD)v2 )
  {
    v3 = params_p->i_params.i_array_p;
    v4 = (unsigned __int64)&v3[v2];
    if ( (unsigned __int64)v3 < v4 )
    {
      while ( !((unsigned __int8 (__cdecl *)(SSParameterBase *))(*v3)->vfptr->is_defaultable)(*v3) )
      {
        ++v3;
        if ( (unsigned __int64)v3 >= v4 )
          goto LABEL_10;
      }
      ++SSParameters::c_param_count;
      v5 = (SSParameters *)AMemory::c_malloc_func(0x30ui64, "SSParameters");
      if ( !v5 )
        return 0i64;
      SSParameters::SSParameters(v5, v1);
      return (SSParameters *)v6;
    }
  }
LABEL_10:
  v7 = 0i64;
  if ( !SSParameters::c_shared_params.i_count )
  {
    LODWORD(v13) = 0;
LABEL_24:
    v15 = (SSParameters *)AMemory::c_malloc_func(0x30ui64, "SSParameters");
    if ( v15 )
    {
      SSParameters::SSParameters(v15, v1);
      v7 = v16;
    }
    ++v7->i_ref_count;
    APSizedArrayBase<SSParameters>::insert(
      (APSizedArrayBase<SSParameters> *)&SSParameters::c_shared_params.i_count,
      v7,
      v13);
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
      if ( !SSParameters::operator<(v1, *v10) )
      {
        v12 = 1i64 - (unsigned __int8)SSParameters::operator==(v1, v11);
        if ( v12 >= 0 )
          break;
      }
      if ( v8 == v10 )
      {
        LODWORD(v13) = v10 - SSParameters::c_shared_params.i_array_p;
        goto LABEL_24;
      }
      v9 = v10 - 1;
    }
    if ( v12 <= 0 )
      break;
    if ( v9 == v10 )
    {
      v13 = ((char *)v9 - (char *)SSParameters::c_shared_params.i_array_p + 8) >> 3;
      goto LABEL_24;
    }
    v8 = v10 + 1;
  }
  v13 = (unsigned int)(v10 - SSParameters::c_shared_params.i_array_p);
  result = SSParameters::c_shared_params.i_array_p[v13];
  if ( !result )
    goto LABEL_24;
  return result;
}

