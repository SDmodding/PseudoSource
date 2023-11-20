// File Line: 107
// RVA: 0x1461470
__int64 dynamic_initializer_for__SSBrain::c_classes__()
{
  return atexit(dynamic_atexit_destructor_for__SSBrain::c_classes__);
}

// File Line: 123
// RVA: 0x1174F0
SSClass *__fastcall SSBrain::get_class(ASymbol *class_name)
{
  SSClass **v1; // rdx
  unsigned int v2; // er10
  SSClass **v3; // r9
  signed __int64 v4; // rax
  unsigned int v5; // er8
  _BOOL8 v6; // r8

  if ( SSBrain::c_classes.i_count )
  {
    v1 = SSBrain::c_classes.i_array_p;
    v2 = class_name->i_uid;
    v3 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
    while ( 1 )
    {
      v4 = (signed __int64)&v1[((char *)v3 - (char *)v1) >> 4];
      v5 = *(_DWORD *)(*(_QWORD *)v4 + 8i64);
      if ( v2 < v5 )
        goto LABEL_14;
      v6 = v2 != v5;
      if ( !v6 )
        return *(SSClass **)v4;
      if ( v6 < 0 )
      {
LABEL_14:
        if ( v1 == (SSClass **)v4 )
          return 0i64;
        v3 = (SSClass **)(v4 - 8);
      }
      else
      {
        if ( v3 == (SSClass **)v4 )
          return 0i64;
        v1 = (SSClass **)(v4 + 8);
      }
    }
  }
  return 0i64;
}

// File Line: 139
// RVA: 0x117560
SSClass *__fastcall SSBrain::get_class(const char *class_name_p)
{
  ASymbol *v1; // rax
  SSClass **v2; // rdx
  unsigned int v3; // er10
  SSClass **v4; // r9
  signed __int64 v5; // rax
  unsigned int v6; // er8
  _BOOL8 v7; // r8
  ASymbol result; // [rsp+38h] [rbp+10h]

  v1 = ASymbol::create(&result, class_name_p, 0xFFFFFFFF, ATerm_long);
  if ( SSBrain::c_classes.i_count )
  {
    v2 = SSBrain::c_classes.i_array_p;
    v3 = v1->i_uid;
    v4 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
    while ( 1 )
    {
      v5 = (signed __int64)&v2[((char *)v4 - (char *)v2) >> 4];
      v6 = *(_DWORD *)(*(_QWORD *)v5 + 8i64);
      if ( v3 < v6 )
        goto LABEL_14;
      v7 = v3 != v6;
      if ( !v7 )
        return *(SSClass **)v5;
      if ( v7 < 0 )
      {
LABEL_14:
        if ( v2 == (SSClass **)v5 )
          return 0i64;
        v4 = (SSClass **)(v5 - 8);
      }
      else
      {
        if ( v4 == (SSClass **)v5 )
          return 0i64;
        v2 = (SSClass **)(v5 + 8);
      }
    }
  }
  return 0i64;
}

// File Line: 431
// RVA: 0x10F550
void __fastcall SSBrain::assign_binary(const void **binary_pp)
{
  unsigned int **v1; // r14
  char *v2; // rax
  unsigned int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // eax
  SSClass **v6; // rbx
  unsigned int *v7; // rax
  __int64 v8; // rbp
  SSTypedClass **v9; // rbx
  unsigned __int64 v10; // r12
  _DWORD *v11; // rax
  unsigned int *v12; // rax
  __int64 v13; // r13
  SSInvokableClass **v14; // rbx
  unsigned __int64 v15; // r15
  _DWORD *v16; // rax
  unsigned int v17; // edi
  SSClassUnion **v18; // rsi
  SSClassUnion *v19; // rax
  SSClassUnion *v20; // rbx
  SSTypedClass **v21; // rdi
  SSTypedClass *v22; // rsi
  ASymbol *v23; // rax
  SSClass **v24; // rdx
  SSClass **v25; // r9
  unsigned int v26; // er10
  signed __int64 v27; // rax
  unsigned int v28; // er8
  _BOOL8 v29; // r8
  SSClass *v30; // rax
  eSSClassType v31; // ecx
  SSClassDescBase *v32; // rbx
  SSClassDescBase *v33; // rcx
  SSInvokableClass **v34; // rbx
  const void **result; // [rsp+80h] [rbp+8h]
  unsigned int v36; // [rsp+88h] [rbp+10h]
  _DWORD *v37; // [rsp+90h] [rbp+18h]
  _DWORD *v38; // [rsp+98h] [rbp+20h]

  result = binary_pp;
  v1 = (unsigned int **)binary_pp;
  v2 = (char *)*binary_pp;
  v3 = *(_DWORD *)*binary_pp;
  *v1 = (unsigned int *)(v2 + 8);
  if ( SkookumScript::c_on_script_linear_bytes_f )
    SkookumScript::c_on_script_linear_bytes_f(v3);
  v4 = **v1;
  ++*v1;
  if ( SSBrain::c_classes.i_size < v4 )
  {
    v5 = AMemory::c_req_byte_size_func(8 * v4) >> 3;
    SSBrain::c_classes.i_size = v5;
    if ( SSBrain::c_classes.i_count )
    {
      v6 = SSBrain::c_classes.i_array_p;
      SSBrain::c_classes.i_array_p = APArrayBase<SSClass>::alloc_array(v5);
      memmove(SSBrain::c_classes.i_array_p, v6, 8i64 * SSBrain::c_classes.i_count);
      AMemory::c_free_func(v6);
    }
    else
    {
      AMemory::c_free_func(SSBrain::c_classes.i_array_p);
      SSBrain::c_classes.i_array_p = APArrayBase<SSClass>::alloc_array(SSBrain::c_classes.i_size);
    }
  }
  SSBrain::assign_binary_class_hier((const void **)v1, 0i64);
  SSBrain::initialize_pre_load(v4);
  v7 = *v1;
  v36 = **v1;
  v8 = v36;
  *v1 = v7 + 1;
  if ( SSTypedClass::c_typed_classes.i_size == (_DWORD)v8 )
  {
    v9 = SSTypedClass::c_typed_classes.i_array_p;
  }
  else
  {
    SSTypedClass::c_typed_classes.i_size = v8;
    if ( SSTypedClass::c_typed_classes.i_array_p )
      AMemory::c_free_func(SSTypedClass::c_typed_classes.i_array_p);
    v9 = APArrayBase<SSTypedClass>::alloc_array(v8);
    SSTypedClass::c_typed_classes.i_array_p = v9;
  }
  SSTypedClass::c_typed_classes.i_count = v8;
  v10 = 0i64;
  if ( (_DWORD)v8 )
  {
    v10 = (unsigned __int64)&v9[v8];
    if ( (unsigned __int64)v9 < v10 )
    {
      do
      {
        v11 = AMemory::c_malloc_func(0x20ui64, "SSTypedClass");
        v37 = v11;
        if ( v11 )
        {
          *(_QWORD *)v11 = &SSClassDescBase::`vftable';
          *(_QWORD *)v11 = &SSClassUnaryBase::`vftable';
          v11[2] = 0;
          *(_QWORD *)v11 = &SSContextClassBase::`vftable';
          *(_QWORD *)v11 = &SSTypedClass::`vftable';
          *((_QWORD *)v11 + 3) = 0i64;
        }
        else
        {
          v11 = 0i64;
        }
        *v9 = (SSTypedClass *)v11;
        ++v9;
      }
      while ( (unsigned __int64)v9 < v10 );
      LODWORD(v8) = v36;
    }
  }
  v12 = *v1;
  LODWORD(v37) = **v1;
  v13 = (unsigned int)v37;
  *v1 = v12 + 1;
  if ( SSInvokableClass::c_shared_classes.i_size == (_DWORD)v13 )
  {
    v14 = SSInvokableClass::c_shared_classes.i_array_p;
  }
  else
  {
    SSInvokableClass::c_shared_classes.i_size = v13;
    if ( SSInvokableClass::c_shared_classes.i_array_p )
      AMemory::c_free_func(SSInvokableClass::c_shared_classes.i_array_p);
    v14 = APArrayBase<SSInvokableClass>::alloc_array(v13);
    SSInvokableClass::c_shared_classes.i_array_p = v14;
  }
  SSInvokableClass::c_shared_classes.i_count = v13;
  v15 = 0i64;
  if ( (_DWORD)v13 )
  {
    v15 = (unsigned __int64)&v14[v13];
    if ( (unsigned __int64)v14 < v15 )
    {
      do
      {
        v16 = AMemory::c_malloc_func(0x28ui64, "SSInvokableClass");
        v38 = v16;
        if ( v16 )
        {
          *(_QWORD *)v16 = &SSClassDescBase::`vftable';
          *(_QWORD *)v16 = &SSClassUnaryBase::`vftable';
          v16[2] = 0;
          *(_QWORD *)v16 = &SSContextClassBase::`vftable';
          *(_QWORD *)v16 = &SSInvokableClass::`vftable';
          *((_QWORD *)v16 + 3) = 0i64;
        }
        else
        {
          v16 = 0i64;
        }
        *v14 = (SSInvokableClass *)v16;
        ++v14;
      }
      while ( (unsigned __int64)v14 < v15 );
      v1 = (unsigned int **)result;
      LODWORD(v8) = v36;
      LODWORD(v13) = (_DWORD)v37;
    }
  }
  v17 = **v1;
  ++*v1;
  if ( SSClassUnion::c_shared_unions.i_size == v17 )
  {
    v18 = SSClassUnion::c_shared_unions.i_array_p;
  }
  else
  {
    SSClassUnion::c_shared_unions.i_size = v17;
    if ( SSClassUnion::c_shared_unions.i_array_p )
      AMemory::c_free_func(SSClassUnion::c_shared_unions.i_array_p);
    v18 = APArrayBase<SSClassUnion>::alloc_array(v17);
    SSClassUnion::c_shared_unions.i_array_p = v18;
  }
  SSClassUnion::c_shared_unions.i_count = v17;
  if ( v17 )
  {
    do
    {
      v19 = (SSClassUnion *)AMemory::c_malloc_func(0x30ui64, "SSClassUnion");
      v20 = v19;
      result = (const void **)&v19->vfptr;
      if ( v19 )
      {
        v19->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
        v19->i_ref_count = 0;
        v19->vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
        v19->i_common_class_p = 0i64;
        v19->i_union.i_count = 0;
        v19->i_union.i_array_p = 0i64;
        v19->i_union.i_size = 0;
        SSClassUnion::assign_binary(v19, (const void **)v1);
      }
      else
      {
        v20 = 0i64;
      }
      *v18 = v20;
      ++v18;
      --v17;
    }
    while ( v17 );
    LODWORD(v8) = v36;
    LODWORD(v13) = (_DWORD)v37;
  }
  if ( (_DWORD)v8 )
  {
    v21 = SSTypedClass::c_typed_classes.i_array_p;
    if ( SSTypedClass::c_typed_classes.i_array_p < (SSTypedClass **)v10 )
    {
      do
      {
        v22 = *v21;
        v23 = ASymbol::create_from_binary((ASymbol *)&result, (const void **)v1);
        if ( SSBrain::c_classes.i_count )
        {
          v24 = SSBrain::c_classes.i_array_p;
          v25 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
          v26 = v23->i_uid;
          while ( 1 )
          {
            v27 = (signed __int64)&v24[((char *)v25 - (char *)v24) >> 4];
            v28 = *(_DWORD *)(*(_QWORD *)v27 + 8i64);
            if ( v26 < v28 )
              goto LABEL_65;
            v29 = v26 != v28;
            if ( !v29 )
            {
              v30 = *(SSClass **)v27;
              goto LABEL_55;
            }
            if ( v29 < 0 )
            {
LABEL_65:
              if ( v24 == (SSClass **)v27 )
                break;
              v25 = (SSClass **)(v27 - 8);
            }
            else
            {
              if ( v25 == (SSClass **)v27 )
                break;
              v24 = (SSClass **)(v27 + 8);
            }
          }
        }
        v30 = 0i64;
LABEL_55:
        v22->i_class_p = v30;
        v31 = *(unsigned __int8 *)*v1;
        *v1 = (unsigned int *)((char *)*v1 + 1);
        v32 = SSClassDescBase::from_binary_ref(v31, (const void **)v1);
        (*(void (__fastcall **)(SSClassDescBase *))v32->vfptr->gap8)(v32);
        v33 = v22->i_item_type_p;
        if ( v33 )
          ((void (__cdecl *)(SSClassDescBase *))v33->vfptr->dereference_delay)(v33);
        v22->i_item_type_p = v32;
        ++v21;
      }
      while ( (unsigned __int64)v21 < v10 );
    }
  }
  if ( (_DWORD)v13 )
  {
    v34 = SSInvokableClass::c_shared_classes.i_array_p;
    if ( SSInvokableClass::c_shared_classes.i_array_p < (SSInvokableClass **)v15 )
    {
      do
      {
        SSInvokableClass::assign_binary(*v34, (const void **)v1);
        ++v34;
      }
      while ( (unsigned __int64)v34 < v15 );
    }
  }
  SSClass::from_binary_group((const void **)v1);
  if ( SkookumScript::c_on_script_linear_bytes_f )
    SkookumScript::c_on_script_linear_bytes_f(0);
}a

// File Line: 595
// RVA: 0x111640
void __fastcall SSBrain::assign_binary_class_hier(const void **binary_pp, SSClass *superclass_p)
{
  SSClass *v2; // rbx
  const void **v3; // rdi
  unsigned int v4; // er8
  SSClass *v5; // rax
  unsigned int v6; // ebx
  SSClass *v7; // rsi
  ASymbol result; // [rsp+30h] [rbp+8h]

  v2 = superclass_p;
  v3 = binary_pp;
  ASymbol::create_from_binary(&result, binary_pp);
  v4 = *(_DWORD *)*v3;
  *v3 = (char *)*v3 + 4;
  v5 = SSBrain::create_class(&result, v2, v4, 0);
  v6 = *(unsigned __int16 *)*v3;
  v7 = v5;
  *v3 = (char *)*v3 + 2;
  APSizedArrayBase<SSClass>::ensure_size((APSizedArrayBase<SSClass> *)&v5->i_subclasses.i_count, v6);
  for ( ; v6; --v6 )
    SSBrain::assign_binary_class_hier(v3, v7);
}

// File Line: 633
// RVA: 0x1116C0
void __fastcall SSBrain::assign_datum(ADatum *datum)
{
  char *v1; // rcx
  unsigned int v2; // eax
  unsigned int v3; // eax
  void *binary_pp; // [rsp+30h] [rbp+8h]

  v1 = datum->i_dref_p->i_buffer_p + 8;
  binary_pp = v1;
  v1 += 4;
  v2 = *((_DWORD *)v1 - 1);
  binary_pp = v1;
  v1 += 4;
  SSBrain::c_checksum_folders = v2;
  v3 = *((_DWORD *)v1 - 1);
  binary_pp = v1;
  SSBrain::c_checksum_files = v3;
  SSBrain::assign_binary((const void **)&binary_pp);
}

// File Line: 693
// RVA: 0x11EC00
signed __int64 __fastcall SSBrain::is_datum_valid(ADatum *datum)
{
  int v1; // edx
  signed __int64 result; // rax

  v1 = *((_DWORD *)datum->i_dref_p->i_buffer_p + 1);
  if ( v1 == 484360395 )
    return 0i64;
  result = 0xFFFFFFFFi64;
  if ( (v1 & 0xFF000000) > 0x1C000000 )
    result = 1i64;
  return result;
}

// File Line: 722
// RVA: 0x112D80
SSClass *__fastcall SSBrain::create_class(ASymbol *class_name, SSClass *superclass_p, unsigned int flags, bool append_super_members)
{
  bool v4; // r12
  signed int v5; // ebp
  SSClass *v6; // r14
  ASymbol *v7; // r15
  SSClass **v8; // r10
  SSClass **v9; // rbx
  unsigned int v10; // er11
  SSClass *v11; // rdi
  signed __int64 v12; // rcx
  unsigned int v13; // edx
  _BOOL8 v14; // rax
  _BOOL8 v15; // rdx
  signed __int64 v16; // rbx
  SSClass *result; // rax
  SSClass *v18; // rax
  SSClass *v19; // rax
  SSClass *v20; // rsi
  signed __int64 v21; // ST30_8

  v4 = append_super_members;
  v5 = flags;
  v6 = superclass_p;
  v7 = class_name;
  if ( SSBrain::c_classes.i_count )
  {
    v8 = SSBrain::c_classes.i_array_p;
    v9 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
    v10 = class_name->i_uid;
    v11 = 0i64;
    while ( 1 )
    {
      while ( 1 )
      {
        v12 = (signed __int64)&v8[((char *)v9 - (char *)v8) >> 4];
        v13 = *(_DWORD *)(*(_QWORD *)v12 + 8i64);
        if ( v10 < v13 )
          break;
        v14 = v10 == v13;
        v15 = v10 != v13;
        if ( 1 - v14 < 0 )
          break;
        if ( v15 <= 0 )
        {
          v16 = (unsigned int)((signed __int64)(v12 - (unsigned __int64)SSBrain::c_classes.i_array_p) >> 3);
          result = SSBrain::c_classes.i_array_p[v16];
          goto LABEL_15;
        }
        if ( v9 == (SSClass **)v12 )
        {
          v16 = ((char *)v9 - (char *)SSBrain::c_classes.i_array_p + 8) >> 3;
          goto LABEL_14;
        }
        v8 = (SSClass **)(v12 + 8);
      }
      if ( v8 == (SSClass **)v12 )
        break;
      v9 = (SSClass **)(v12 - 8);
    }
    LODWORD(v16) = (signed __int64)(v12 - (unsigned __int64)SSBrain::c_classes.i_array_p) >> 3;
  }
  else
  {
    v11 = 0i64;
    LODWORD(v16) = 0;
  }
LABEL_14:
  result = 0i64;
LABEL_15:
  if ( !result )
  {
    if ( v7->i_uid == ASymbol_Actor.i_uid || v6 && v6->vfptr->is_actor_class((SSClassDescBase *)&v6->vfptr) )
    {
      v20 = (SSClass *)AMemory::c_malloc_func(0x148ui64, "SSActorClass");
      if ( v20 )
      {
        if ( v5 == -1 )
          v5 = 48;
        SSClass::SSClass(v20, v7, v6, v5);
        v20->vfptr = (SSClassDescBaseVtbl *)&SSActorClass::`vftable';
        v21 = (signed __int64)&v20[1];
        *(_DWORD *)v21 = 0;
        *(_QWORD *)(v21 + 8) = 0i64;
        *(_DWORD *)(v21 + 16) = 0;
        v11 = v20;
      }
    }
    else
    {
      v18 = (SSClass *)AMemory::c_malloc_func(0x130ui64, "SSClass");
      if ( v18 )
      {
        if ( v5 == -1 )
          v5 = (signed int)v11;
        SSClass::SSClass(v18, v7, v6, v5);
        v11 = v19;
      }
    }
    if ( v4 )
    {
      if ( v6 )
      {
        APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append_all(
          (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v11->i_data_table.i_count,
          (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v6->i_data_table.i_count);
        APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol>>::append_all(
          (APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *)&v11->i_class_data_table.i_count,
          (APSorted<SSTypedData,ASymbol,ACompareLogical<ASymbol> > *)&v6->i_class_data_table.i_count);
      }
    }
    APSizedArrayBase<SSClass>::insert((APSizedArrayBase<SSClass> *)&SSBrain::c_classes.i_count, v11, v16);
    result = v11;
  }
  return result;
}

// File Line: 913
// RVA: 0x13AF10
void __fastcall SSBrain::register_bind_atomics_func(void (__fastcall *bind_atomics_f)())
{
  void (__fastcall *v1)(); // rsi
  char *v2; // rdi
  unsigned __int64 v3; // rbx
  __int64 v4; // rsi
  ASymbol *v5; // rbp

  v1 = bind_atomics_f;
  v2 = UFG::qMalloc(0x10ui64, "AFunction", 0i64);
  LODWORD(v3) = 0;
  if ( v2 )
  {
    *(_QWORD *)v2 = &AFunctionBase::`vftable';
    *(_QWORD *)v2 = &AFunction::`vftable';
    *((_QWORD *)v2 + 1) = v1;
  }
  else
  {
    v2 = 0i64;
  }
  if ( !(_S2_4 & 1) )
  {
    _S2_4 |= 1u;
    stru_142175B00.i_count = 0;
    stru_142175B00.i_array_p = 0i64;
    dword_142175B10 = 0;
    atexit(SSBrain::get_bind_funcs_::_2_::_dynamic_atexit_destructor_for__s_atomic_funcs__);
  }
  v4 = stru_142175B00.i_count;
  if ( dword_142175B10 < stru_142175B00.i_count + 1 )
  {
    v5 = stru_142175B00.i_array_p;
    if ( stru_142175B00.i_count != -1 )
      v3 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (stru_142175B00.i_count & 0xFFFFFFFC) + 32) >> 3;
    dword_142175B10 = v3;
    stru_142175B00.i_array_p = (ASymbol *)APArrayBase<AFunctionBase>::alloc_array(v3);
    memmove(stru_142175B00.i_array_p, v5, 8 * v4);
    AMemory::c_free_func(v5);
  }
  *(_QWORD *)&stru_142175B00.i_array_p[2 * v4].i_uid = v2;
  ++stru_142175B00.i_count;
}

// File Line: 934
// RVA: 0x11A400
void __fastcall SSBrain::initialize_pre_load(unsigned int ensure_class_count)
{
  unsigned int v1; // eax
  SSClass **v2; // rbx
  SSClass **v3; // rdx
  SSClass **v4; // r8
  SSClass *v5; // rbx
  AObjReusePool<SSBoolean> *v6; // rax
  SSBoolean **v7; // rcx
  unsigned __int64 i; // rdx

  if ( SSBrain::c_classes.i_size < ensure_class_count )
  {
    v1 = AMemory::c_req_byte_size_func(8 * ensure_class_count) >> 3;
    SSBrain::c_classes.i_size = v1;
    if ( SSBrain::c_classes.i_count )
    {
      v2 = SSBrain::c_classes.i_array_p;
      SSBrain::c_classes.i_array_p = APArrayBase<SSClass>::alloc_array(v1);
      memmove(SSBrain::c_classes.i_array_p, v2, 8i64 * SSBrain::c_classes.i_count);
      AMemory::c_free_func(v2);
    }
    else
    {
      AMemory::c_free_func(SSBrain::c_classes.i_array_p);
      SSBrain::c_classes.i_array_p = APArrayBase<SSClass>::alloc_array(SSBrain::c_classes.i_size);
    }
  }
  SSBrain::c_object_class_p = SSBrain::create_class(&ASymbol_Object, 0i64, 0xFFFFFFFF, 0);
  SSBrain::c_class_class_p = SSBrain::create_class(&ASymbol_Class, SSBrain::c_object_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_simple_type_class_p = SSBrain::create_class(&ASymbol_SimpleType, SSBrain::c_object_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_actor_class_p = (SSActorClass *)SSBrain::create_class(
                                               &ASymbol_Actor,
                                               SSBrain::c_object_class_p,
                                               0xFFFFFFFF,
                                               0);
  SSBrain::c_logical_actor_class_p = (SSActorClass *)SSBrain::create_class(
                                                       &ASymbol_LogicalActor,
                                                       (SSClass *)&SSBrain::c_actor_class_p->vfptr,
                                                       0xFFFFFFFF,
                                                       0);
  SSBrain::c_physical_actor_class_p = (SSActorClass *)SSBrain::create_class(
                                                        &ASymbol_PhysicalActor,
                                                        (SSClass *)&SSBrain::c_actor_class_p->vfptr,
                                                        0xFFFFFFFF,
                                                        0);
  SSBrain::c_none_class_p = SSBrain::create_class(&ASymbol_None, SSBrain::c_object_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_auto_class_p = SSBrain::create_class(&ASymbol_Auto_, SSBrain::c_class_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_this_class_p = SSBrain::create_class(&ASymbol_ThisClass_, SSBrain::c_class_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_item_class_p = SSBrain::create_class(&ASymbol_ItemClass_, SSBrain::c_class_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_invoked_base_class_p = SSBrain::create_class(
                                      &ASymbol_InvokedBase,
                                      SSBrain::c_object_class_p,
                                      0xFFFFFFFF,
                                      0);
  SSBrain::c_invoked_context_base_class_p = SSBrain::create_class(
                                              &ASymbol_InvokedContextBase,
                                              SSBrain::c_invoked_base_class_p,
                                              0xFFFFFFFF,
                                              0);
  SSBrain::c_invoked_method_class_p = SSBrain::create_class(
                                        &ASymbol_InvokedMethod,
                                        SSBrain::c_invoked_context_base_class_p,
                                        0xFFFFFFFF,
                                        0);
  SSBrain::c_invoked_coroutine_class_p = SSBrain::create_class(
                                           &ASymbol_InvokedCoroutine,
                                           SSBrain::c_invoked_context_base_class_p,
                                           0xFFFFFFFF,
                                           0);
  SSBrain::c_closure_class_p = SSBrain::create_class(&ASymbol_Closure, SSBrain::c_object_class_p, 0xFFFFFFFF, 0);
  v3 = SSBrain::c_classes.i_array_p;
  v4 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count];
  if ( SSBrain::c_classes.i_array_p < v4 )
  {
    do
    {
      (*v3)->i_metaclass.i_class_p = SSBrain::c_class_class_p;
      ++v3;
    }
    while ( v3 < v4 );
  }
  SSBrain::c_boolean_class_p = SSBrain::create_class(&ASymbol_Boolean, SSBrain::c_simple_type_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_char_class_p = SSBrain::create_class(&ASymbol_Char, SSBrain::c_simple_type_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_integer_class_p = SSBrain::create_class(&ASymbol_Integer, SSBrain::c_simple_type_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_list_class_p = SSBrain::create_class(&ASymbol_List, SSBrain::c_simple_type_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_real_class_p = SSBrain::create_class(&ASymbol_Real, SSBrain::c_simple_type_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_string_class_p = SSBrain::create_class(&ASymbol_String, SSBrain::c_simple_type_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_symbol_class_p = SSBrain::create_class(&ASymbol_Symbol, SSBrain::c_simple_type_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_world_class_p = (SSActorClass *)SSBrain::create_class(
                                               &ASymbol_World,
                                               (SSClass *)&SSBrain::c_logical_actor_class_p->vfptr,
                                               0xFFFFFFFF,
                                               0);
  v5 = SSBrain::c_boolean_class_p;
  v6 = SSBoolean::get_pool();
  v7 = v6->i_pool.i_array_p;
  for ( i = (unsigned __int64)&v7[v6->i_pool.i_count]; (unsigned __int64)v7 < i; ++v7 )
    (*v7)->i_class_p = v5;
  if ( !(_S3_4 & 1) )
  {
    _S3_4 |= 1u;
    s_nil.i_class_p = 0i64;
    s_nil.i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
    s_nil.vfptr = (SSObjectBaseVtbl *)&SSInstanceUnreffed::`vftable';
    s_nil.i_ref_count = 1000000;
    atexit(SSBrain::initialize_pre_load_::_4_::_dynamic_atexit_destructor_for__s_nil__);
  }
  s_nil.i_class_p = SSBrain::c_none_class_p;
  SSBrain::c_nil_p = (SSInstance *)&s_nil;
}

// File Line: 1018
// RVA: 0x11A300
void SSBrain::initialize_post_load(void)
{
  __int64 *v0; // rbx
  ASymbol *v1; // rdi

  SSInstance::register_bindings();
  SSInvokedBase::register_atomic();
  SSInvokedMethod::register_atomic();
  SSInvokedCoroutine::register_atomic();
  SSClosure::register_bindings();
  SSBoolean::register_atomic();
  SSInteger::register_atomic();
  SSEnum::register_atomic();
  SSReal::register_atomic();
  SSString::register_atomic();
  SSSymbol::register_atomic();
  SSRandom::register_atomic();
  SSList::register_atomic();
  SSDebug::register_atomic();
  SSActor::register_atomic();
  if ( !(_S2_4 & 1) )
  {
    _S2_4 |= 1u;
    stru_142175B00.i_count = 0;
    stru_142175B00.i_array_p = 0i64;
    dword_142175B10 = 0;
    atexit(SSBrain::get_bind_funcs_::_2_::_dynamic_atexit_destructor_for__s_atomic_funcs__);
  }
  if ( stru_142175B00.i_count )
  {
    v0 = (__int64 *)stru_142175B00.i_array_p;
    v1 = &stru_142175B00.i_array_p[2 * stru_142175B00.i_count];
    if ( stru_142175B00.i_array_p < v1 )
    {
      do
      {
         SSClassDescBase::`vcall'{8,{flat}}(*v0);
        ++v0;
      }
      while ( v0 < (__int64 *)v1 );
    }
  }
}

// File Line: 1101
// RVA: 0x113850
void SSBrain::deinitialize(void)
{
  __int64 *v0; // rbx
  SSClass **v1; // rdi
  SSInvokableClass **v2; // rbx
  SSInvokableClass **v3; // rdi
  unsigned int v4; // ecx
  SSTypedClass **v5; // rbx
  SSTypedClass **v6; // rdi
  SSClassUnion **v7; // rbx
  __int64 v8; // rax
  SSClassUnion **v9; // rdi
  SSTypedClass **v10; // rbx
  SSTypedClass **v11; // rdi
  SSClass **v12; // rbx
  __int64 v13; // rax
  SSClass **v14; // rdi

  if ( SSBrain::c_classes.i_count )
  {
    v0 = (__int64 *)SSBrain::c_classes.i_array_p;
    v1 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count];
    if ( SSBrain::c_classes.i_array_p < v1 )
    {
      do
      {
         SSClass::`vcall'{280,{flat}}(*v0);
        ++v0;
      }
      while ( v0 < (__int64 *)v1 );
    }
  }
  v2 = SSInvokableClass::c_shared_classes.i_array_p;
  v3 = &SSInvokableClass::c_shared_classes.i_array_p[SSInvokableClass::c_shared_classes.i_count];
  SSInvokableClass::c_shared_classes.i_count = 0;
  if ( SSInvokableClass::c_shared_classes.i_array_p < v3 )
  {
    do
    {
      if ( *v2 )
        (*v2)->vfptr->__vecDelDtor((SSClassDescBase *)&(*v2)->vfptr, 1u);
      ++v2;
    }
    while ( v2 < v3 );
  }
  APSizedArrayBase<SSParameters>::free_all((APSizedArrayBase<SSParameters> *)&SSParameters::c_shared_params.i_count);
  v4 = SSTypedClass::c_typed_classes.i_count;
  if ( SSTypedClass::c_typed_classes.i_count )
  {
    v5 = SSTypedClass::c_typed_classes.i_array_p;
    v6 = &SSTypedClass::c_typed_classes.i_array_p[SSTypedClass::c_typed_classes.i_count];
    if ( SSTypedClass::c_typed_classes.i_array_p < v6 )
    {
      do
      {
        SSTypedClass::clear(*v5);
        ++v5;
      }
      while ( v5 < v6 );
      v4 = SSTypedClass::c_typed_classes.i_count;
    }
  }
  v7 = SSClassUnion::c_shared_unions.i_array_p;
  v8 = SSClassUnion::c_shared_unions.i_count;
  SSClassUnion::c_shared_unions.i_count = 0;
  v9 = &SSClassUnion::c_shared_unions.i_array_p[v8];
  if ( SSClassUnion::c_shared_unions.i_array_p < v9 )
  {
    do
    {
      if ( *v7 )
        (*v7)->vfptr->__vecDelDtor((SSClassDescBase *)&(*v7)->vfptr, 1u);
      ++v7;
    }
    while ( v7 < v9 );
    v4 = SSTypedClass::c_typed_classes.i_count;
  }
  v10 = SSTypedClass::c_typed_classes.i_array_p;
  SSTypedClass::c_typed_classes.i_count = 0;
  v11 = &SSTypedClass::c_typed_classes.i_array_p[v4];
  if ( SSTypedClass::c_typed_classes.i_array_p < v11 )
  {
    do
    {
      if ( *v10 )
        (*v10)->vfptr->__vecDelDtor((SSClassDescBase *)&(*v10)->vfptr, 1u);
      ++v10;
    }
    while ( v10 < v11 );
  }
  v12 = SSBrain::c_classes.i_array_p;
  v13 = SSBrain::c_classes.i_count;
  SSBrain::c_classes.i_count = 0;
  v14 = &SSBrain::c_classes.i_array_p[v13];
  if ( SSBrain::c_classes.i_array_p < v14 )
  {
    do
    {
      if ( *v12 )
        (*v12)->vfptr->__vecDelDtor((SSClassDescBase *)&(*v12)->vfptr, 1u);
      ++v12;
    }
    while ( v12 < v14 );
  }
  if ( SSBrain::c_nil_p )
    ((void (*)(void))SSBrain::c_nil_p->vfptr[1].is_actor)();
}

