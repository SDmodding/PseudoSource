// File Line: 39
// RVA: 0x106FD0
void __fastcall SSGroupParam::~SSGroupParam(SSGroupParam *this)
{
  __int64 i_count; // rax
  SSClassDescBase **i_array_p; // rbx
  SSClassDescBase **i; // rsi

  this->vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
  i_count = this->i_class_pattern.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_class_pattern.i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
       SSClassDescBase::`vcall{16,{flat}}(*i_array_p);
  }
  AMemory::c_free_func(this->i_class_pattern.i_array_p);
  this->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
}

// File Line: 71
// RVA: 0x104FF0
void __fastcall SSGroupParam::SSGroupParam(SSGroupParam *this, unsigned int class_count, const void **binary_pp)
{
  SSClassDescBase **v6; // rax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  SSClassDescBase *v11; // rbx
  SSClass *v12; // rax
  ASymbol *v13; // rax
  SSClass *v14; // rax
  ASymbol *v15; // rax
  __int64 i_count; // rbp
  SSClassDescBase **i_array_p; // r14
  unsigned __int64 v18; // rax
  SSClassDescBase **v19; // rax
  ASymbol result; // [rsp+78h] [rbp+10h] BYREF
  ASymbol v21; // [rsp+88h] [rbp+20h] BYREF

  this->i_name = (ASymbol)ASymbol::create_from_binary(&result, binary_pp)->i_uid;
  this->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
  this->vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
  this->i_class_pattern.i_count = 0;
  this->i_class_pattern.i_array_p = 0i64;
  this->i_class_pattern.i_size = 0;
  if ( class_count )
  {
    this->i_class_pattern.i_size = class_count;
    v6 = APArrayBase<SSClassDescBase>::alloc_array(class_count);
  }
  else
  {
    this->i_class_pattern.i_size = 0;
    v6 = (SSClassDescBase **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  this->i_class_pattern.i_array_p = v6;
  if ( class_count )
  {
    while ( 1 )
    {
      v7 = *(unsigned __int8 *)*binary_pp;
      *binary_pp = (char *)*binary_pp + 1;
      if ( !v7 )
      {
        v15 = ASymbol::create_from_binary(&v21, binary_pp);
        v12 = SSBrain::get_class(v15);
        goto LABEL_16;
      }
      v8 = v7 - 1;
      if ( !v8 )
      {
        v13 = ASymbol::create_from_binary(&result, binary_pp);
        v14 = SSBrain::get_class(v13);
        v12 = (SSClass *)v14->vfptr->get_metaclass(v14);
        goto LABEL_16;
      }
      v9 = v8 - 1;
      if ( !v9 )
      {
        v12 = (SSClass *)SSTypedClass::from_binary_ref(binary_pp);
        goto LABEL_16;
      }
      v10 = v9 - 1;
      if ( !v10 )
        break;
      if ( v10 == 1 )
      {
        v12 = (SSClass *)SSClassUnion::from_binary_ref(binary_pp);
LABEL_16:
        v11 = v12;
        goto LABEL_17;
      }
      v11 = 0i64;
LABEL_17:
      (*(void (__fastcall **)(SSClassDescBase *))v11->vfptr->gap8)(v11);
      i_count = this->i_class_pattern.i_count;
      if ( this->i_class_pattern.i_size < (unsigned int)(i_count + 1) )
      {
        i_array_p = this->i_class_pattern.i_array_p;
        if ( (_DWORD)i_count == -1 )
          LODWORD(v18) = 0;
        else
          v18 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (i_count & 0xFFFFFFFC) + 32) >> 3;
        this->i_class_pattern.i_size = v18;
        v19 = APArrayBase<SSClassDescBase>::alloc_array(v18);
        this->i_class_pattern.i_array_p = v19;
        memmove(v19, i_array_p, 8 * i_count);
        AMemory::c_free_func(i_array_p);
      }
      this->i_class_pattern.i_array_p[i_count] = v11;
      ++this->i_class_pattern.i_count;
      if ( !--class_count )
        return;
    }
    v12 = (SSClass *)SSInvokableClass::from_binary_ref(binary_pp);
    goto LABEL_16;
  }
}

// File Line: 91
// RVA: 0x112610
char __fastcall SSGroupParam::compare_equal(SSGroupParam *this, SSParameterBase *param)
{
  __int64 i_count; // rcx
  SSClassDescBase **i_array_p; // rax
  SSClassDescBase **v6; // r8
  __int64 v7; // rdx

  if ( this->i_name.i_uid == param->i_name.i_uid && param->vfptr->get_kind(param) == SSParameter_group )
  {
    i_count = this->i_class_pattern.i_count;
    if ( (_DWORD)i_count == LODWORD(param[1].vfptr) )
    {
      i_array_p = this->i_class_pattern.i_array_p;
      v6 = &i_array_p[i_count];
      if ( i_array_p >= v6 )
        return 1;
      v7 = *(_QWORD *)&param[1].i_name.i_uid - (_QWORD)i_array_p;
      while ( *i_array_p == *(SSClassDescBase **)((char *)i_array_p + v7) )
      {
        if ( ++i_array_p >= v6 )
          return 1;
      }
    }
  }
  return 0;
}

// File Line: 137
// RVA: 0x1126D0
bool __fastcall SSGroupParam::compare_less(SSGroupParam *this, SSParameterBase *param)
{
  unsigned int i_uid; // eax
  unsigned int v4; // ecx
  __int64 i_count; // rcx
  unsigned int vfptr; // edx
  SSClassDescBase **i_array_p; // rbx
  SSClassDescBase **v10; // rdi
  SSClassDescBase **v11; // rsi
  int v12; // eax

  i_uid = this->i_name.i_uid;
  v4 = param->i_name.i_uid;
  if ( i_uid < v4 )
    return 1;
  if ( i_uid > v4 || param->vfptr->get_kind(param) != SSParameter_group )
    return 0;
  i_count = this->i_class_pattern.i_count;
  vfptr = (unsigned int)param[1].vfptr;
  if ( (_DWORD)i_count != vfptr )
    return (unsigned int)i_count < vfptr;
  i_array_p = this->i_class_pattern.i_array_p;
  v10 = *(SSClassDescBase ***)&param[1].i_name.i_uid;
  v11 = &i_array_p[i_count];
  if ( i_array_p >= v11 )
    return 0;
  while ( 1 )
  {
    v12 = SSClassDescBase::compare(*i_array_p, *v10);
    if ( v12 == -1 )
      break;
    if ( v12 != 1 )
    {
      ++i_array_p;
      ++v10;
      if ( i_array_p < v11 )
        continue;
    }
    return 0;
  }
  return 1;
}

// File Line: 317
// RVA: 0x10EC70
SSParameterBase *__fastcall SSGroupParam::as_finalized_generic(SSGroupParam *this, SSClassDescBase *scope_type)
{
  _DWORD *v4; // rax
  _DWORD *v5; // rbx
  __int64 i_count; // rsi
  void *v7; // rcx
  _QWORD *v8; // r14
  SSClassDescBase **i_array_p; // rdi
  SSClassDescBase **i; // rsi

  v4 = AMemory::c_malloc_func(0x28ui64, "SSGroupParam");
  v5 = v4;
  if ( v4 )
  {
    v4[2] = this->i_name.i_uid;
    *(_QWORD *)v4 = &SSParameterBase::`vftable;
    *(_QWORD *)v4 = &SSGroupParam::`vftable;
    v4[4] = 0;
    *((_QWORD *)v4 + 3) = 0i64;
    v4[8] = 0;
  }
  else
  {
    v5 = 0i64;
  }
  i_count = this->i_class_pattern.i_count;
  if ( (_DWORD)i_count )
  {
    if ( v5[8] != (_DWORD)i_count )
    {
      v5[8] = i_count;
      v7 = (void *)*((_QWORD *)v5 + 3);
      if ( v7 )
        AMemory::c_free_func(v7);
      *((_QWORD *)v5 + 3) = APArrayBase<SSClassDescBase>::alloc_array(i_count);
    }
    v5[4] = i_count;
    v8 = (_QWORD *)*((_QWORD *)v5 + 3);
    i_array_p = this->i_class_pattern.i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++v8 )
    {
      *v8 = (*i_array_p)->vfptr->as_finalized_generic(*i_array_p, scope_type);
      ++i_array_p;
    }
  }
  return (SSParameterBase *)v5;
}

// File Line: 366
// RVA: 0x117A00
SSTypedClass *__fastcall SSGroupParam::get_expected_type(SSGroupParam *this)
{
  SSClassDescBase *merge; // rax

  merge = SSClassUnion::get_merge(&this->i_class_pattern, 1);
  return SSTypedClass::get_or_create(SSBrain::c_list_class_p, merge);
}

// File Line: 386
// RVA: 0x11ECD0
bool __fastcall SSGroupParam::is_generic(SSGroupParam *this)
{
  __int64 i_count; // rax
  SSClassDescBase **i_array_p; // rbx
  SSClassDescBase **i; // rdi

  i_count = this->i_class_pattern.i_count;
  if ( !(_DWORD)i_count )
    return 0;
  i_array_p = this->i_class_pattern.i_array_p;
  for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
    (*i_array_p)->vfptr->is_generic(*i_array_p);
  return 0;
}

// File Line: 422
// RVA: 0x11F3E0
char __fastcall SSGroupParam::is_valid_arg_to(SSGroupParam *this, SSGroupParam *param)
{
  unsigned int i_count; // ebp
  unsigned int v3; // esi
  SSClassDescBase **i_array_p; // r14
  SSClassDescBase **v5; // r15
  int v6; // ebx
  unsigned int v7; // edi

  i_count = this->i_class_pattern.i_count;
  if ( !i_count || i_count == 1 && *(SSClass **)this->i_class_pattern.i_array_p == SSBrain::c_object_class_p )
    return 1;
  v3 = param->i_class_pattern.i_count;
  if ( !v3
    || v3 == 1 && *(SSClass **)param->i_class_pattern.i_array_p == SSBrain::c_object_class_p
    || i_count > v3
    || v3 % i_count )
  {
    return 0;
  }
  i_array_p = param->i_class_pattern.i_array_p;
  v5 = this->i_class_pattern.i_array_p;
  v6 = 0;
  v7 = 0;
  while ( (*i_array_p)->vfptr->is_class_type(*i_array_p, v5[v6]) )
  {
    if ( ++v6 == i_count )
      v6 = 0;
    ++v7;
    ++i_array_p;
    if ( v7 >= v3 )
      return 1;
  }
  return 0;
}

// File Line: 483
// RVA: 0x13DD10
void __fastcall SSGroupParam::track_memory(SSGroupParam *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSGroupParam",
    0x28u,
    0,
    8 * this->i_class_pattern.i_count,
    8 * this->i_class_pattern.i_size,
    1u);
}

