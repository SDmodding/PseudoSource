// File Line: 39
// RVA: 0x106FD0
void __fastcall SSGroupParam::~SSGroupParam(SSGroupParam *this)
{
  SSGroupParam *v1; // rdi
  __int64 v2; // rax
  SSClassDescBase **v3; // rbx
  unsigned __int64 i; // rsi

  v1 = this;
  this->vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
  v2 = this->i_class_pattern.i_count;
  if ( (_DWORD)v2 )
  {
    v3 = this->i_class_pattern.i_array_p;
    for ( i = (unsigned __int64)&v3[v2]; (unsigned __int64)v3 < i; ++v3 )
       SSClassDescBase::`vcall'{16,{flat}}(*v3);
  }
  AMemory::c_free_func(v1->i_class_pattern.i_array_p);
  v1->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
}

// File Line: 71
// RVA: 0x104FF0
void __fastcall SSGroupParam::SSGroupParam(SSGroupParam *this, unsigned int class_count, const void **binary_pp)
{
  const void **v3; // rsi
  unsigned int v4; // er15
  SSGroupParam *v5; // rdi
  SSClassDescBase **v6; // rax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  SSClass *v11; // rbx
  SSClass *v12; // rax
  ASymbol *v13; // rax
  SSClass *v14; // rax
  ASymbol *v15; // rax
  __int64 v16; // rbp
  SSClassDescBase **v17; // r14
  unsigned __int64 v18; // rax
  SSClassDescBase **v19; // rax
  ASymbol result; // [rsp+78h] [rbp+10h]
  ASymbol v21; // [rsp+88h] [rbp+20h]

  v3 = binary_pp;
  v4 = class_count;
  v5 = this;
  this->i_name = (ASymbol)ASymbol::create_from_binary(&result, binary_pp)->i_uid;
  v5->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
  v5->vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
  v5->i_class_pattern.i_count = 0;
  v5->i_class_pattern.i_array_p = 0i64;
  v5->i_class_pattern.i_size = 0;
  if ( v4 )
  {
    v5->i_class_pattern.i_size = v4;
    v6 = APArrayBase<SSClassDescBase>::alloc_array(v4);
  }
  else
  {
    v5->i_class_pattern.i_size = 0;
    v6 = (SSClassDescBase **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  v5->i_class_pattern.i_array_p = v6;
  if ( v4 )
  {
    while ( 1 )
    {
      v7 = *(unsigned __int8 *)*v3;
      *v3 = (char *)*v3 + 1;
      if ( !v7 )
      {
        v15 = ASymbol::create_from_binary(&v21, v3);
        v12 = SSBrain::get_class(v15);
        goto LABEL_16;
      }
      v8 = v7 - 1;
      if ( !v8 )
      {
        v13 = ASymbol::create_from_binary(&result, v3);
        v14 = SSBrain::get_class(v13);
        v12 = (SSClass *)v14->vfptr->get_metaclass((SSClassDescBase *)&v14->vfptr);
        goto LABEL_16;
      }
      v9 = v8 - 1;
      if ( !v9 )
      {
        v12 = (SSClass *)SSTypedClass::from_binary_ref(v3);
        goto LABEL_16;
      }
      v10 = v9 - 1;
      if ( !v10 )
        break;
      if ( v10 == 1 )
      {
        v12 = (SSClass *)SSClassUnion::from_binary_ref(v3);
LABEL_16:
        v11 = v12;
        goto LABEL_17;
      }
      v11 = 0i64;
LABEL_17:
      (*(void (__fastcall **)(SSClass *))v11->vfptr->gap8)(v11);
      v16 = v5->i_class_pattern.i_count;
      if ( v5->i_class_pattern.i_size < (unsigned int)(v16 + 1) )
      {
        v17 = v5->i_class_pattern.i_array_p;
        if ( (_DWORD)v16 == -1 )
          LODWORD(v18) = 0;
        else
          v18 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (v16 & 0xFFFFFFFC) + 32) >> 3;
        v5->i_class_pattern.i_size = v18;
        v19 = APArrayBase<SSClassDescBase>::alloc_array(v18);
        v5->i_class_pattern.i_array_p = v19;
        memmove(v19, v17, 8 * v16);
        AMemory::c_free_func(v17);
      }
      v5->i_class_pattern.i_array_p[v16] = (SSClassDescBase *)&v11->vfptr;
      ++v5->i_class_pattern.i_count;
      if ( !--v4 )
        return;
    }
    v12 = (SSClass *)SSInvokableClass::from_binary_ref(v3);
    goto LABEL_16;
  }
}

// File Line: 91
// RVA: 0x112610
char __fastcall SSGroupParam::compare_equal(SSGroupParam *this, SSParameterBase *param)
{
  SSParameterBase *v2; // rbx
  SSGroupParam *v3; // rdi
  __int64 v4; // rcx
  SSClassDescBase **v5; // rax
  unsigned __int64 v6; // r8
  __int64 v7; // rdx

  v2 = param;
  v3 = this;
  if ( this->i_name.i_uid == param->i_name.i_uid && param->vfptr->get_kind(param) == 3 )
  {
    v4 = v3->i_class_pattern.i_count;
    if ( (_DWORD)v4 == LODWORD(v2[1].vfptr) )
    {
      v5 = v3->i_class_pattern.i_array_p;
      v6 = (unsigned __int64)&v5[v4];
      if ( (unsigned __int64)v5 >= v6 )
        return 1;
      v7 = *(_QWORD *)&v2[1].i_name.i_uid - (_QWORD)v5;
      while ( *v5 == *(SSClassDescBase **)((char *)v5 + v7) )
      {
        ++v5;
        if ( (unsigned __int64)v5 >= v6 )
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
  unsigned int v2; // eax
  SSGroupParam *v3; // rbx
  unsigned int v4; // ecx
  SSParameterBase *v5; // rdi
  __int64 v7; // rcx
  unsigned int v8; // edx
  SSClassDescBase **v9; // rbx
  SSClassDescBase **v10; // rdi
  unsigned __int64 v11; // rsi
  signed int v12; // eax

  v2 = this->i_name.i_uid;
  v3 = this;
  v4 = param->i_name.i_uid;
  v5 = param;
  if ( v2 < v4 )
    return 1;
  if ( v2 > v4 || param->vfptr->get_kind(param) != 3 )
    return 0;
  v7 = v3->i_class_pattern.i_count;
  v8 = (unsigned int)v5[1].vfptr;
  if ( (_DWORD)v7 != v8 )
    return (unsigned int)v7 < v8;
  v9 = v3->i_class_pattern.i_array_p;
  v10 = *(SSClassDescBase ***)&v5[1].i_name.i_uid;
  v11 = (unsigned __int64)&v9[v7];
  if ( (unsigned __int64)v9 >= v11 )
    return 0;
  while ( 1 )
  {
    v12 = SSClassDescBase::compare(*v9, *v10, (__int64)v9);
    if ( v12 == -1 )
      break;
    if ( v12 != 1 )
    {
      ++v9;
      ++v10;
      if ( (unsigned __int64)v9 < v11 )
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
  SSClassDescBase *v2; // rbp
  SSGroupParam *v3; // rdi
  _DWORD *v4; // rax
  _DWORD *v5; // rbx
  __int64 v6; // rsi
  void *v7; // rcx
  _QWORD *v8; // r14
  SSClassDescBase **v9; // rdi
  unsigned __int64 i; // rsi

  v2 = scope_type;
  v3 = this;
  v4 = AMemory::c_malloc_func(0x28ui64, "SSGroupParam");
  v5 = v4;
  if ( v4 )
  {
    v4[2] = v3->i_name.i_uid;
    *(_QWORD *)v4 = &SSParameterBase::`vftable';
    *(_QWORD *)v4 = &SSGroupParam::`vftable';
    v4[4] = 0;
    *((_QWORD *)v4 + 3) = 0i64;
    v4[8] = 0;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v3->i_class_pattern.i_count;
  if ( (_DWORD)v6 )
  {
    if ( v5[8] != (_DWORD)v6 )
    {
      v5[8] = v6;
      v7 = (void *)*((_QWORD *)v5 + 3);
      if ( v7 )
        AMemory::c_free_func(v7);
      *((_QWORD *)v5 + 3) = APArrayBase<SSClassDescBase>::alloc_array(v6);
    }
    v5[4] = v6;
    v8 = (_QWORD *)*((_QWORD *)v5 + 3);
    v9 = v3->i_class_pattern.i_array_p;
    for ( i = (unsigned __int64)&v9[v6]; (unsigned __int64)v9 < i; ++v8 )
    {
      *v8 = (*v9)->vfptr->as_finalized_generic(*v9, v2);
      ++v9;
    }
  }
  return (SSParameterBase *)v5;
}

// File Line: 366
// RVA: 0x117A00
SSTypedClass *__fastcall SSGroupParam::get_expected_type(SSGroupParam *this)
{
  SSClassDescBase *v1; // rax

  v1 = SSClassUnion::get_merge((APArrayBase<SSClassDescBase> *)&this->i_class_pattern.i_count, 1);
  return SSTypedClass::get_or_create(SSBrain::c_list_class_p, v1);
}

// File Line: 386
// RVA: 0x11ECD0
bool __fastcall SSGroupParam::is_generic(SSGroupParam *this)
{
  __int64 v1; // rax
  SSClassDescBase **v2; // rbx
  unsigned __int64 i; // rdi

  v1 = this->i_class_pattern.i_count;
  if ( !(_DWORD)v1 )
    return 0;
  v2 = this->i_class_pattern.i_array_p;
  for ( i = (unsigned __int64)&v2[v1]; (unsigned __int64)v2 < i; ++v2 )
    ((void (*)(void))(*v2)->vfptr->is_generic)();
  return 0;
}

// File Line: 422
// RVA: 0x11F3E0
char __fastcall SSGroupParam::is_valid_arg_to(SSGroupParam *this, SSGroupParam *param)
{
  unsigned int v2; // ebp
  unsigned int v3; // esi
  SSClassDescBase **v4; // r14
  SSClassDescBase **v5; // r15
  int v6; // ebx
  unsigned int v7; // edi

  v2 = this->i_class_pattern.i_count;
  if ( !v2 || v2 == 1 && *(SSClass **)this->i_class_pattern.i_array_p == SSBrain::c_object_class_p )
    return 1;
  v3 = param->i_class_pattern.i_count;
  if ( !v3
    || v3 == 1 && *(SSClass **)param->i_class_pattern.i_array_p == SSBrain::c_object_class_p
    || v2 > v3
    || v3 % v2 )
  {
    return 0;
  }
  v4 = param->i_class_pattern.i_array_p;
  v5 = this->i_class_pattern.i_array_p;
  v6 = 0;
  v7 = 0;
  if ( !v3 )
    return 1;
  while ( (*v4)->vfptr->is_class_type(*v4, v5[v6]) )
  {
    if ( ++v6 == v2 )
      v6 = 0;
    ++v7;
    ++v4;
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

