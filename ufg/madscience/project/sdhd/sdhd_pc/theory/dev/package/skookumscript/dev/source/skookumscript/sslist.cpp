// File Line: 72
// RVA: 0x10CEA0
void __fastcall SSList::append(SSList *this, SSInstance *instance, bool reference_b)
{
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(&this->i_items, instance);
  if ( reference_b )
    ++instance->i_ref_count;
}

// File Line: 93
// RVA: 0x13BBD0
void __fastcall SSList::remove(SSList *this, SSInstance *instance, bool dereference_b)
{
  SSInstance **i_array_p; // r11
  __int64 v6; // rdi
  SSInstance **v7; // rdx
  SSInstance **v8; // rax

  if ( this->i_items.i_count )
  {
    i_array_p = this->i_items.i_array_p;
    v6 = this->i_items.i_count - 1;
    v7 = &i_array_p[v6];
    v8 = i_array_p;
    if ( i_array_p <= v7 )
    {
      while ( instance != *v8 )
      {
        if ( ++v8 > v7 )
          goto LABEL_6;
      }
      this->i_items.i_count = v6;
      memmove(
        &i_array_p[(unsigned int)(v8 - i_array_p)],
        &i_array_p[(unsigned int)(v8 - i_array_p) + 1],
        8i64 * ((unsigned int)v6 - (unsigned int)(v8 - i_array_p)));
    }
  }
LABEL_6:
  if ( dereference_b && instance->i_ref_count-- == 1 )
  {
    instance->i_ref_count = 0x80000000;
    instance->vfptr[1].get_scope_context(instance);
  }
}

// File Line: 187
// RVA: 0x10F190
SSInstance *__fastcall SSList::as_instance(SSList *list_p)
{
  SSList *v1; // rbx

  v1 = list_p;
  if ( !list_p )
  {
    v1 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    if ( v1 )
    {
      v1->i_items.i_count = 0;
      v1->i_items.i_array_p = 0i64;
      v1->i_items.i_size = 0;
      v1->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v1 = 0i64;
    }
  }
  return SSInstance::pool_new(SSBrain::c_list_class_p, (unsigned __int64)v1);
}

// File Line: 202
// RVA: 0x136070
void __fastcall SSList::register_atomic(__int64 a1, SSMethodBase **a2, __int64 a3, __int64 i_uid)
{
  SSMethodBase **i_array_p; // r8
  __int64 i_count; // rax
  SSMethodBase **v6; // r10
  _BOOL8 v7; // rcx
  __int64 v8; // rdi
  __int64 v9; // r15
  SSParameters *v10; // rsi
  SSParameters *v11; // r14
  bool v12; // zf
  SSMethodBase **v13; // r8
  __int64 v14; // rax
  SSMethodBase **v15; // r10
  _BOOL8 v16; // rcx
  __int64 v17; // rdi
  __int64 v18; // r15
  SSParameters *v19; // rsi
  SSParameters *v20; // r14
  SSMethodBase **v21; // r8
  __int64 v22; // rax
  SSMethodBase **v23; // r10
  _BOOL8 v24; // rcx
  __int64 v25; // rdi
  __int64 v26; // r15
  SSParameters *v27; // rsi
  SSParameters *v28; // r14
  SSMethodBase **v29; // r8
  __int64 v30; // rax
  SSMethodBase **v31; // r10
  _BOOL8 v32; // rcx
  __int64 v33; // rdi
  __int64 v34; // r15
  SSParameters *v35; // rsi
  SSParameters *v36; // r14
  SSMethodBase **v37; // r8
  __int64 v38; // rax
  SSMethodBase **v39; // r10
  _BOOL8 v40; // rcx
  __int64 v41; // rdi
  __int64 v42; // r15
  SSParameters *v43; // rsi
  SSParameters *v44; // r14
  SSMethodBase **v45; // r8
  __int64 v46; // rax
  SSMethodBase **v47; // r10
  _BOOL8 v48; // rcx
  __int64 v49; // rdi
  __int64 v50; // r15
  SSParameters *v51; // rsi
  SSParameters *v52; // r14
  SSMethodBase **v53; // r8
  __int64 v54; // rax
  SSMethodBase **v55; // r10
  _BOOL8 v56; // rcx
  __int64 v57; // rdi
  __int64 v58; // r15
  SSParameters *v59; // rsi
  SSParameters *v60; // r14
  SSMethodBase **v61; // r8
  __int64 v62; // rax
  SSMethodBase **v63; // r10
  _BOOL8 v64; // rcx
  __int64 v65; // rdi
  __int64 v66; // r15
  SSParameters *v67; // rsi
  SSParameters *v68; // r14
  SSMethodBase **v69; // r8
  __int64 v70; // rax
  SSMethodBase **v71; // r10
  _BOOL8 v72; // rcx
  __int64 v73; // rdi
  __int64 v74; // r15
  SSParameters *v75; // rsi
  SSParameters *v76; // r14
  SSMethodBase **v77; // r8
  __int64 v78; // rax
  SSMethodBase **v79; // r10
  _BOOL8 v80; // rcx
  __int64 v81; // rdi
  __int64 v82; // r15
  SSParameters *v83; // rsi
  SSParameters *v84; // r14
  SSMethodBase **v85; // r8
  __int64 v86; // rax
  SSMethodBase **v87; // r10
  _BOOL8 v88; // rcx
  __int64 v89; // rdi
  __int64 v90; // r15
  SSParameters *v91; // rsi
  SSParameters *v92; // r14
  SSClass *v93; // rbx
  ASymbol *v94; // rax
  SSClass *v95; // rbx
  ASymbol *v96; // rax
  SSClass *v97; // rbx
  ASymbol *v98; // rax
  SSClass *v99; // rbx
  ASymbol *v100; // rax
  SSClass *v101; // rbx
  ASymbol *v102; // rax
  SSClass *v103; // rbx
  ASymbol *v104; // rax
  SSClass *v105; // rbx
  ASymbol *v106; // rax
  SSClass *v107; // rbx
  ASymbol *v108; // rax
  SSClass *v109; // rbx
  ASymbol *v110; // rax
  SSClass *v111; // rbx
  ASymbol *v112; // rax
  SSClass *v113; // rbx
  ASymbol *v114; // rax
  SSClass *v115; // rbx
  ASymbol *v116; // rax
  SSClass *v117; // rbx
  ASymbol *v118; // rax
  __int64 result; // [rsp+70h] [rbp+40h] BYREF
  SSParameters *v120; // [rsp+78h] [rbp+48h]
  __int64 v121; // [rsp+80h] [rbp+50h]

  i_array_p = (SSMethodBase **)SSBrain::c_list_class_p;
  i_count = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_list_class_p->i_methods.i_array_p;
    v6 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbolX_ctor.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_10;
        v6 = a2 - 1;
      }
      v7 = ASymbolX_ctor.i_uid == (_DWORD)i_uid;
      i_uid = ASymbolX_ctor.i_uid != (_DWORD)i_uid;
      if ( v7 )
        break;
      if ( v6 == a2 )
        goto LABEL_10;
      i_array_p = a2 + 1;
    }
    v8 = (__int64)*a2;
  }
  else
  {
LABEL_10:
    v8 = 0i64;
  }
  result = v8;
  if ( v8 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64, __int64))(*(_QWORD *)v8 + 16i64))(
           v8,
           a2,
           i_array_p,
           i_uid,
           -2i64) == 1 )
    {
      *(_QWORD *)(v8 + 32) = SSList::mthd_constructor;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      v120 = v10;
      if ( v10 )
        ++v10->i_ref_count;
      v11 = *(SSParameters **)(v8 + 24);
      if ( v11 )
      {
        v12 = v11->i_ref_count-- == 1;
        if ( v12 )
        {
          v11->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v11);
          AMemory::c_free_func(v11);
        }
        *(_QWORD *)(v8 + 24) = 0i64;
      }
      v121 = v8;
      *(ASymbol *)(v8 + 8) = ASymbolX_ctor;
      *(_QWORD *)(v8 + 16) = v9;
      *(_QWORD *)v8 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v8 + 24) = v10;
      if ( v10 )
        ++v10->i_ref_count;
      *(_QWORD *)v8 = &SSMethodBase::`vftable;
      *(_QWORD *)v8 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v8 + 32) = SSList::mthd_constructor;
      if ( v10 )
      {
        v12 = v10->i_ref_count-- == 1;
        if ( v12 )
        {
          v10->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v10);
          AMemory::c_free_func(v10);
        }
      }
    }
  }
  v13 = (SSMethodBase **)SSBrain::c_list_class_p;
  v14 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v13 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v15 = &v13[v14 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v13[((char *)v15 - (char *)v13) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbolX_ctor_copy.i_uid >= (unsigned int)i_uid )
          break;
        if ( v13 == a2 )
          goto LABEL_34;
        v15 = a2 - 1;
      }
      v16 = ASymbolX_ctor_copy.i_uid == (_DWORD)i_uid;
      i_uid = ASymbolX_ctor_copy.i_uid != (_DWORD)i_uid;
      if ( v16 )
        break;
      if ( v15 == a2 )
        goto LABEL_34;
      v13 = a2 + 1;
    }
    v17 = (__int64)*a2;
  }
  else
  {
LABEL_34:
    v17 = 0i64;
  }
  result = v17;
  if ( v17 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v17 + 16i64))(
           v17,
           a2,
           v13,
           i_uid) == 1 )
    {
      *(_QWORD *)(v17 + 32) = SSList::mthd_ctor_copy;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      v120 = v19;
      if ( v19 )
        ++v19->i_ref_count;
      v20 = *(SSParameters **)(v17 + 24);
      if ( v20 )
      {
        v12 = v20->i_ref_count-- == 1;
        if ( v12 )
        {
          v20->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v20);
          AMemory::c_free_func(v20);
        }
        *(_QWORD *)(v17 + 24) = 0i64;
      }
      v121 = v17;
      *(ASymbol *)(v17 + 8) = ASymbolX_ctor_copy;
      *(_QWORD *)(v17 + 16) = v18;
      *(_QWORD *)v17 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v17 + 24) = v19;
      if ( v19 )
        ++v19->i_ref_count;
      *(_QWORD *)v17 = &SSMethodBase::`vftable;
      *(_QWORD *)v17 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v17 + 32) = SSList::mthd_ctor_copy;
      if ( v19 )
      {
        v12 = v19->i_ref_count-- == 1;
        if ( v12 )
        {
          v19->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v19);
          AMemory::c_free_func(v19);
        }
      }
    }
  }
  v21 = (SSMethodBase **)SSBrain::c_list_class_p;
  v22 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    v21 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v23 = &v21[v22 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v21[((char *)v23 - (char *)v21) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbolX_dtor.i_uid >= (unsigned int)i_uid )
          break;
        if ( v21 == a2 )
          goto LABEL_58;
        v23 = a2 - 1;
      }
      v24 = ASymbolX_dtor.i_uid == (_DWORD)i_uid;
      i_uid = ASymbolX_dtor.i_uid != (_DWORD)i_uid;
      if ( v24 )
        break;
      if ( v23 == a2 )
        goto LABEL_58;
      v21 = a2 + 1;
    }
    v25 = (__int64)*a2;
  }
  else
  {
LABEL_58:
    v25 = 0i64;
  }
  result = v25;
  if ( v25 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v25 + 16i64))(
           v25,
           a2,
           v21,
           i_uid) == 1 )
    {
      *(_QWORD *)(v25 + 32) = SSList::mthd_destructor;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v120 = v27;
      if ( v27 )
        ++v27->i_ref_count;
      v28 = *(SSParameters **)(v25 + 24);
      if ( v28 )
      {
        v12 = v28->i_ref_count-- == 1;
        if ( v12 )
        {
          v28->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v28);
          AMemory::c_free_func(v28);
        }
        *(_QWORD *)(v25 + 24) = 0i64;
      }
      v121 = v25;
      *(ASymbol *)(v25 + 8) = ASymbolX_dtor;
      *(_QWORD *)(v25 + 16) = v26;
      *(_QWORD *)v25 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v25 + 24) = v27;
      if ( v27 )
        ++v27->i_ref_count;
      *(_QWORD *)v25 = &SSMethodBase::`vftable;
      *(_QWORD *)v25 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v25 + 32) = SSList::mthd_destructor;
      if ( v27 )
      {
        v12 = v27->i_ref_count-- == 1;
        if ( v12 )
        {
          v27->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v27);
          AMemory::c_free_func(v27);
        }
      }
    }
  }
  v29 = (SSMethodBase **)SSBrain::c_list_class_p;
  v30 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v30 )
  {
    v29 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v31 = &v29[v30 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v29[((char *)v31 - (char *)v29) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_as_copy.i_uid >= (unsigned int)i_uid )
          break;
        if ( v29 == a2 )
          goto LABEL_82;
        v31 = a2 - 1;
      }
      v32 = ASymbol_as_copy.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_as_copy.i_uid != (_DWORD)i_uid;
      if ( v32 )
        break;
      if ( v31 == a2 )
        goto LABEL_82;
      v29 = a2 + 1;
    }
    v33 = (__int64)*a2;
  }
  else
  {
LABEL_82:
    v33 = 0i64;
  }
  result = v33;
  if ( v33 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v33 + 16i64))(
           v33,
           a2,
           v29,
           i_uid) == 1 )
    {
      *(_QWORD *)(v33 + 32) = SSList::mthd_as_copy;
    }
    else
    {
      v34 = *(_QWORD *)(v33 + 16);
      v35 = *(SSParameters **)(v33 + 24);
      v120 = v35;
      if ( v35 )
        ++v35->i_ref_count;
      v36 = *(SSParameters **)(v33 + 24);
      if ( v36 )
      {
        v12 = v36->i_ref_count-- == 1;
        if ( v12 )
        {
          v36->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v36);
          AMemory::c_free_func(v36);
        }
        *(_QWORD *)(v33 + 24) = 0i64;
      }
      v121 = v33;
      *(ASymbol *)(v33 + 8) = ASymbol_as_copy;
      *(_QWORD *)(v33 + 16) = v34;
      *(_QWORD *)v33 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v33 + 24) = v35;
      if ( v35 )
        ++v35->i_ref_count;
      *(_QWORD *)v33 = &SSMethodBase::`vftable;
      *(_QWORD *)v33 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v33 + 32) = SSList::mthd_as_copy;
      if ( v35 )
      {
        v12 = v35->i_ref_count-- == 1;
        if ( v12 )
        {
          v35->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v35);
          AMemory::c_free_func(v35);
        }
      }
    }
  }
  v37 = (SSMethodBase **)SSBrain::c_list_class_p;
  v38 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v38 )
  {
    v37 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v39 = &v37[v38 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v37[((char *)v39 - (char *)v37) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_as_new.i_uid >= (unsigned int)i_uid )
          break;
        if ( v37 == a2 )
          goto LABEL_106;
        v39 = a2 - 1;
      }
      v40 = ASymbol_as_new.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_as_new.i_uid != (_DWORD)i_uid;
      if ( v40 )
        break;
      if ( v39 == a2 )
        goto LABEL_106;
      v37 = a2 + 1;
    }
    v41 = (__int64)*a2;
  }
  else
  {
LABEL_106:
    v41 = 0i64;
  }
  result = v41;
  if ( v41 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v41 + 16i64))(
           v41,
           a2,
           v37,
           i_uid) == 1 )
    {
      *(_QWORD *)(v41 + 32) = SSList::mthd_as_new;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      v120 = v43;
      if ( v43 )
        ++v43->i_ref_count;
      v44 = *(SSParameters **)(v41 + 24);
      if ( v44 )
      {
        v12 = v44->i_ref_count-- == 1;
        if ( v12 )
        {
          v44->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v44);
          AMemory::c_free_func(v44);
        }
        *(_QWORD *)(v41 + 24) = 0i64;
      }
      v121 = v41;
      *(ASymbol *)(v41 + 8) = ASymbol_as_new;
      *(_QWORD *)(v41 + 16) = v42;
      *(_QWORD *)v41 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v41 + 24) = v43;
      if ( v43 )
        ++v43->i_ref_count;
      *(_QWORD *)v41 = &SSMethodBase::`vftable;
      *(_QWORD *)v41 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v41 + 32) = SSList::mthd_as_new;
      if ( v43 )
      {
        v12 = v43->i_ref_count-- == 1;
        if ( v12 )
        {
          v43->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v43);
          AMemory::c_free_func(v43);
        }
      }
    }
  }
  v45 = (SSMethodBase **)SSBrain::c_list_class_p;
  v46 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v46 )
  {
    v45 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v47 = &v45[v46 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v45[((char *)v47 - (char *)v45) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= (unsigned int)i_uid )
          break;
        if ( v45 == a2 )
          goto LABEL_130;
        v47 = a2 - 1;
      }
      v48 = ASymbol_String.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_String.i_uid != (_DWORD)i_uid;
      if ( v48 )
        break;
      if ( v47 == a2 )
        goto LABEL_130;
      v45 = a2 + 1;
    }
    v49 = (__int64)*a2;
  }
  else
  {
LABEL_130:
    v49 = 0i64;
  }
  result = v49;
  if ( v49 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v49 + 16i64))(
           v49,
           a2,
           v45,
           i_uid) == 1 )
    {
      *(_QWORD *)(v49 + 32) = SSList::mthd_String;
    }
    else
    {
      v50 = *(_QWORD *)(v49 + 16);
      v51 = *(SSParameters **)(v49 + 24);
      v120 = v51;
      if ( v51 )
        ++v51->i_ref_count;
      v52 = *(SSParameters **)(v49 + 24);
      if ( v52 )
      {
        v12 = v52->i_ref_count-- == 1;
        if ( v12 )
        {
          v52->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v52);
          AMemory::c_free_func(v52);
        }
        *(_QWORD *)(v49 + 24) = 0i64;
      }
      v121 = v49;
      *(ASymbol *)(v49 + 8) = ASymbol_String;
      *(_QWORD *)(v49 + 16) = v50;
      *(_QWORD *)v49 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v49 + 24) = v51;
      if ( v51 )
        ++v51->i_ref_count;
      *(_QWORD *)v49 = &SSMethodBase::`vftable;
      *(_QWORD *)v49 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v49 + 32) = SSList::mthd_String;
      if ( v51 )
      {
        v12 = v51->i_ref_count-- == 1;
        if ( v12 )
        {
          v51->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v51);
          AMemory::c_free_func(v51);
        }
      }
    }
  }
  v53 = (SSMethodBase **)SSBrain::c_list_class_p;
  v54 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v54 )
  {
    v53 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v55 = &v53[v54 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v53[((char *)v55 - (char *)v53) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_equals_eqv.i_uid >= (unsigned int)i_uid )
          break;
        if ( v53 == a2 )
          goto LABEL_154;
        v55 = a2 - 1;
      }
      v56 = ASymbol_equals_eqv.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_equals_eqv.i_uid != (_DWORD)i_uid;
      if ( v56 )
        break;
      if ( v55 == a2 )
        goto LABEL_154;
      v53 = a2 + 1;
    }
    v57 = (__int64)*a2;
  }
  else
  {
LABEL_154:
    v57 = 0i64;
  }
  result = v57;
  if ( v57 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v57 + 16i64))(
           v57,
           a2,
           v53,
           i_uid) == 1 )
    {
      *(_QWORD *)(v57 + 32) = SSList::mthd_equals_eqv;
    }
    else
    {
      v58 = *(_QWORD *)(v57 + 16);
      v59 = *(SSParameters **)(v57 + 24);
      v120 = v59;
      if ( v59 )
        ++v59->i_ref_count;
      v60 = *(SSParameters **)(v57 + 24);
      if ( v60 )
      {
        v12 = v60->i_ref_count-- == 1;
        if ( v12 )
        {
          v60->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v60);
          AMemory::c_free_func(v60);
        }
        *(_QWORD *)(v57 + 24) = 0i64;
      }
      v121 = v57;
      *(ASymbol *)(v57 + 8) = ASymbol_equals_eqv;
      *(_QWORD *)(v57 + 16) = v58;
      *(_QWORD *)v57 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v57 + 24) = v59;
      if ( v59 )
        ++v59->i_ref_count;
      *(_QWORD *)v57 = &SSMethodBase::`vftable;
      *(_QWORD *)v57 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v57 + 32) = SSList::mthd_equals_eqv;
      if ( v59 )
      {
        v12 = v59->i_ref_count-- == 1;
        if ( v12 )
        {
          v59->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v59);
          AMemory::c_free_func(v59);
        }
      }
    }
  }
  v61 = (SSMethodBase **)SSBrain::c_list_class_p;
  v62 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v62 )
  {
    v61 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v63 = &v61[v62 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v61[((char *)v63 - (char *)v61) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_not_equal_eqv.i_uid >= (unsigned int)i_uid )
          break;
        if ( v61 == a2 )
          goto LABEL_178;
        v63 = a2 - 1;
      }
      v64 = ASymbol_not_equal_eqv.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_not_equal_eqv.i_uid != (_DWORD)i_uid;
      if ( v64 )
        break;
      if ( v63 == a2 )
        goto LABEL_178;
      v61 = a2 + 1;
    }
    v65 = (__int64)*a2;
  }
  else
  {
LABEL_178:
    v65 = 0i64;
  }
  result = v65;
  if ( v65 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v65 + 16i64))(
           v65,
           a2,
           v61,
           i_uid) == 1 )
    {
      *(_QWORD *)(v65 + 32) = SSList::mthd_not_equal_eqv;
    }
    else
    {
      v66 = *(_QWORD *)(v65 + 16);
      v67 = *(SSParameters **)(v65 + 24);
      v120 = v67;
      if ( v67 )
        ++v67->i_ref_count;
      v68 = *(SSParameters **)(v65 + 24);
      if ( v68 )
      {
        v12 = v68->i_ref_count-- == 1;
        if ( v12 )
        {
          v68->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v68);
          AMemory::c_free_func(v68);
        }
        *(_QWORD *)(v65 + 24) = 0i64;
      }
      v121 = v65;
      *(ASymbol *)(v65 + 8) = ASymbol_not_equal_eqv;
      *(_QWORD *)(v65 + 16) = v66;
      *(_QWORD *)v65 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v65 + 24) = v67;
      if ( v67 )
        ++v67->i_ref_count;
      *(_QWORD *)v65 = &SSMethodBase::`vftable;
      *(_QWORD *)v65 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v65 + 32) = SSList::mthd_not_equal_eqv;
      if ( v67 )
      {
        v12 = v67->i_ref_count-- == 1;
        if ( v12 )
        {
          v67->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v67);
          AMemory::c_free_func(v67);
        }
      }
    }
  }
  v69 = (SSMethodBase **)SSBrain::c_list_class_p;
  v70 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v70 )
  {
    v69 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v71 = &v69[v70 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v69[((char *)v71 - (char *)v69) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add.i_uid >= (unsigned int)i_uid )
          break;
        if ( v69 == a2 )
          goto LABEL_202;
        v71 = a2 - 1;
      }
      v72 = ASymbol_add.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add.i_uid != (_DWORD)i_uid;
      if ( v72 )
        break;
      if ( v71 == a2 )
        goto LABEL_202;
      v69 = a2 + 1;
    }
    v73 = (__int64)*a2;
  }
  else
  {
LABEL_202:
    v73 = 0i64;
  }
  result = v73;
  if ( v73 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v73 + 16i64))(
           v73,
           a2,
           v69,
           i_uid) == 1 )
    {
      *(_QWORD *)(v73 + 32) = SSList::mthd_op_add;
    }
    else
    {
      v74 = *(_QWORD *)(v73 + 16);
      v75 = *(SSParameters **)(v73 + 24);
      v120 = v75;
      if ( v75 )
        ++v75->i_ref_count;
      v76 = *(SSParameters **)(v73 + 24);
      if ( v76 )
      {
        v12 = v76->i_ref_count-- == 1;
        if ( v12 )
        {
          v76->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v76);
          AMemory::c_free_func(v76);
        }
        *(_QWORD *)(v73 + 24) = 0i64;
      }
      v121 = v73;
      *(ASymbol *)(v73 + 8) = ASymbol_add;
      *(_QWORD *)(v73 + 16) = v74;
      *(_QWORD *)v73 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v73 + 24) = v75;
      if ( v75 )
        ++v75->i_ref_count;
      *(_QWORD *)v73 = &SSMethodBase::`vftable;
      *(_QWORD *)v73 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v73 + 32) = SSList::mthd_op_add;
      if ( v75 )
      {
        v12 = v75->i_ref_count-- == 1;
        if ( v12 )
        {
          v75->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v75);
          AMemory::c_free_func(v75);
        }
      }
    }
  }
  v77 = (SSMethodBase **)SSBrain::c_list_class_p;
  v78 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v78 )
  {
    v77 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v79 = &v77[v78 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v77[((char *)v79 - (char *)v77) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v77 == a2 )
          goto LABEL_226;
        v79 = a2 - 1;
      }
      v80 = ASymbol_add_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add_assign.i_uid != (_DWORD)i_uid;
      if ( v80 )
        break;
      if ( v79 == a2 )
        goto LABEL_226;
      v77 = a2 + 1;
    }
    v81 = (__int64)*a2;
  }
  else
  {
LABEL_226:
    v81 = 0i64;
  }
  result = v81;
  if ( v81 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v81 + 16i64))(
           v81,
           a2,
           v77,
           i_uid) == 1 )
    {
      *(_QWORD *)(v81 + 32) = SSList::mthd_op_add_assign;
    }
    else
    {
      v82 = *(_QWORD *)(v81 + 16);
      v83 = *(SSParameters **)(v81 + 24);
      v120 = v83;
      if ( v83 )
        ++v83->i_ref_count;
      v84 = *(SSParameters **)(v81 + 24);
      if ( v84 )
      {
        v12 = v84->i_ref_count-- == 1;
        if ( v12 )
        {
          v84->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v84);
          AMemory::c_free_func(v84);
        }
        *(_QWORD *)(v81 + 24) = 0i64;
      }
      v121 = v81;
      *(ASymbol *)(v81 + 8) = ASymbol_add_assign;
      *(_QWORD *)(v81 + 16) = v82;
      *(_QWORD *)v81 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v81 + 24) = v83;
      if ( v83 )
        ++v83->i_ref_count;
      *(_QWORD *)v81 = &SSMethodBase::`vftable;
      *(_QWORD *)v81 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v81 + 32) = SSList::mthd_op_add_assign;
      if ( v83 )
      {
        v12 = v83->i_ref_count-- == 1;
        if ( v12 )
        {
          v83->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v83);
          AMemory::c_free_func(v83);
        }
      }
    }
  }
  v85 = (SSMethodBase **)SSBrain::c_list_class_p;
  v86 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v86 )
  {
    v85 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v87 = &v85[v86 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v85[((char *)v87 - (char *)v85) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v85 == a2 )
          goto LABEL_250;
        v87 = a2 - 1;
      }
      v88 = ASymbol_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_assign.i_uid != (_DWORD)i_uid;
      if ( v88 )
        break;
      if ( v87 == a2 )
        goto LABEL_250;
      v85 = a2 + 1;
    }
    v89 = (__int64)*a2;
  }
  else
  {
LABEL_250:
    v89 = 0i64;
  }
  result = v89;
  if ( v89 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v89 + 16i64))(
           v89,
           a2,
           v85,
           i_uid) == 1 )
    {
      *(_QWORD *)(v89 + 32) = SSList::mthd_op_assign;
    }
    else
    {
      v90 = *(_QWORD *)(v89 + 16);
      v91 = *(SSParameters **)(v89 + 24);
      v120 = v91;
      if ( v91 )
        ++v91->i_ref_count;
      v92 = *(SSParameters **)(v89 + 24);
      if ( v92 )
      {
        v12 = v92->i_ref_count-- == 1;
        if ( v12 )
        {
          v92->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v92);
          AMemory::c_free_func(v92);
        }
        *(_QWORD *)(v89 + 24) = 0i64;
      }
      v121 = v89;
      *(ASymbol *)(v89 + 8) = ASymbol_assign;
      *(_QWORD *)(v89 + 16) = v90;
      *(_QWORD *)v89 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v89 + 24) = v91;
      if ( v91 )
        ++v91->i_ref_count;
      *(_QWORD *)v89 = &SSMethodBase::`vftable;
      *(_QWORD *)v89 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v89 + 32) = SSList::mthd_op_assign;
      if ( v91 )
      {
        v12 = v91->i_ref_count-- == 1;
        if ( v12 )
        {
          v91->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v91);
          AMemory::c_free_func(v91);
        }
      }
    }
  }
  v93 = SSBrain::c_list_class_p;
  v94 = ASymbol::create((ASymbol *)&result, "assign_group", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v93, v94, SSList::mthd_op_assign, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_get_count,
    SSList::mthd_get_count,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_get_count_after,
    SSList::mthd_get_count_after,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_is_empty,
    SSList::mthd_is_empty,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_is_filled,
    SSList::mthd_is_filled,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_get_at,
    SSList::mthd_get_at,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_get_first,
    SSList::mthd_get_first,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_get_last,
    SSList::mthd_get_last,
    SSBindFlag_instance_no_rebind);
  v95 = SSBrain::c_list_class_p;
  v96 = ASymbol::create((ASymbol *)&result, "get_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v95, v96, SSList::mthd_get_list_eqv, SSBindFlag_instance_no_rebind);
  v97 = SSBrain::c_list_class_p;
  v98 = ASymbol::create((ASymbol *)&result, "get_list_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v97, v98, SSList::mthd_get_list_eqv, SSBindFlag_instance_no_rebind);
  v99 = SSBrain::c_list_class_p;
  v100 = ASymbol::create((ASymbol *)&result, "intersection_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v99, v100, SSList::mthd_get_list_eqv, SSBindFlag_instance_no_rebind);
  v101 = SSBrain::c_list_class_p;
  v102 = ASymbol::create((ASymbol *)&result, "intersection_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v101, v102, SSList::mthd_get_list_eqv, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_get_range,
    SSList::mthd_get_range,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_reverse,
    SSList::mthd_reverse,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_rotate_down,
    SSList::mthd_rotate_down,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_rotate_up,
    SSList::mthd_rotate_up,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_swap,
    SSList::mthd_swap,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_append,
    SSList::mthd_append,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_append_absent_eqv,
    SSList::mthd_append_absent_eqv,
    SSBindFlag_instance_no_rebind);
  v103 = SSBrain::c_list_class_p;
  v104 = ASymbol::create((ASymbol *)&result, "append_absent_list_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v103, v104, SSList::mthd_append_absent_list_eqv, SSBindFlag_instance_no_rebind);
  v105 = SSBrain::c_list_class_p;
  v106 = ASymbol::create((ASymbol *)&result, "append_absent_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v105, v106, SSList::mthd_append_absent_list_eqv, SSBindFlag_instance_no_rebind);
  v107 = SSBrain::c_list_class_p;
  v108 = ASymbol::create((ASymbol *)&result, "union_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v107, v108, SSList::mthd_append_absent_list_eqv, SSBindFlag_instance_no_rebind);
  v109 = SSBrain::c_list_class_p;
  v110 = ASymbol::create((ASymbol *)&result, "union_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v109, v110, SSList::mthd_append_absent_list_eqv, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_append_items,
    SSList::mthd_append_items,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_append_list,
    SSList::mthd_op_add_assign,
    SSBindFlag_instance_no_rebind);
  v111 = SSBrain::c_list_class_p;
  v112 = ASymbol::create((ASymbol *)&result, "append_group", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v111, v112, SSList::mthd_op_add_assign, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_insert,
    SSList::mthd_insert,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_insert_items,
    SSList::mthd_insert_items,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_insert_list,
    SSList::mthd_insert_list,
    SSBindFlag_instance_no_rebind);
  v113 = SSBrain::c_list_class_p;
  v114 = ASymbol::create((ASymbol *)&result, "insert_group", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v113, v114, SSList::mthd_insert_list, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_set_at,
    SSList::mthd_set_at,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_set_items,
    SSList::mthd_set_items,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_crop,
    SSList::mthd_crop,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_empty,
    SSList::mthd_empty,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_pop_at,
    SSList::mthd_pop_at,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_pop_first,
    SSList::mthd_pop_first,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_pop_last,
    SSList::mthd_pop_last,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_pop_range,
    SSList::mthd_pop_range,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_pop_range_last,
    SSList::mthd_pop_range_last,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_remove_at,
    SSList::mthd_remove_at,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_remove_eqv,
    SSList::mthd_remove_eqv,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_remove_first,
    SSList::mthd_remove_first,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_remove_last,
    SSList::mthd_remove_last,
    SSBindFlag_instance_no_rebind);
  v115 = SSBrain::c_list_class_p;
  v116 = ASymbol::create((ASymbol *)&result, "remove_list_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v115, v116, SSList::mthd_remove_list_eqv, SSBindFlag_instance_no_rebind);
  v117 = SSBrain::c_list_class_p;
  v118 = ASymbol::create((ASymbol *)&result, "remove_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v117, v118, SSList::mthd_remove_list_eqv, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_remove_range,
    SSList::mthd_remove_range,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_list_class_p,
    &ASymbol_remove_range_last,
    SSList::mthd_remove_range_last,
    SSBindFlag_instance_no_rebind);
}ymbol_remove_range_last,
    SSList::mthd_remove_range_last,
    SSBindFlag_instance_no_rebind);
}

// File Line: 332
// RVA: 0x121C00
void __fastcall SSList::mthd_constructor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdi
  SSObjectBaseVtbl *v3; // rax
  SSObjectBaseVtbl *v4; // rbx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( !result_pp )
  {
    v3 = (SSObjectBaseVtbl *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v4 = v3;
    if ( v3 )
    {
      LODWORD(v3->__vecDelDtor) = 0;
      v3->get_obj_type = 0i64;
      LODWORD(v3->is_actor) = 0;
      v3->get_obj_type = (unsigned int (__fastcall *)(SSObjectBase *))AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v4 = 0i64;
    }
    i_obj_p[2].vfptr = v4;
  }
}

// File Line: 349
// RVA: 0x121E10
void __fastcall SSList::mthd_ctor_copy(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rbx
  APSizedArrayBase<SSInstance> *v4; // rax
  APSizedArrayBase<SSInstance> *vfptr; // rdi
  unsigned int *i_user_data; // r14
  __int64 v7; // rax
  ARefCountMix<SSInstance> **v8; // rbx
  ARefCountMix<SSInstance> **i; // rsi
  unsigned int v10; // ebx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( result_pp )
  {
    vfptr = (APSizedArrayBase<SSInstance> *)i_obj_p[2].vfptr;
  }
  else
  {
    v4 = (APSizedArrayBase<SSInstance> *)AMemory::c_malloc_func(0x18ui64, "SSList");
    vfptr = v4;
    if ( v4 )
    {
      v4->i_count = 0;
      v4->i_array_p = 0i64;
      v4->i_size = 0;
      v4->i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      vfptr = 0i64;
    }
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)vfptr;
  }
  i_user_data = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v7 = *i_user_data;
  if ( (_DWORD)v7 )
  {
    v8 = (ARefCountMix<SSInstance> **)*((_QWORD *)i_user_data + 1);
    for ( i = &v8[v7]; v8 < i; ++v8 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v8 + 4);
  }
  v10 = *i_user_data;
  APSizedArrayBase<SSInstance>::ensure_size(vfptr, *i_user_data + vfptr->i_count);
  memmove(&vfptr->i_array_p[vfptr->i_count], *((const void **)i_user_data + 1), 8i64 * v10);
  vfptr->i_count += v10;
}

// File Line: 380
// RVA: 0x122040
void __fastcall SSList::mthd_destructor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdi
  void **p_vecDelDtor; // rdi
  __int64 v4; // rax
  ARefCountMix<SSInstance> **v5; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  p_vecDelDtor = (void **)&i_obj_p[2].vfptr->__vecDelDtor;
  if ( p_vecDelDtor )
  {
    v4 = *(unsigned int *)p_vecDelDtor;
    if ( (_DWORD)v4 )
    {
      v5 = (ARefCountMix<SSInstance> **)p_vecDelDtor[1];
      for ( i = &v5[v4]; v5 < i; ++v5 )
        ARefCountMix<SSInstance>::dereference(*v5 + 4);
    }
    AMemory::c_free_func(p_vecDelDtor[1]);
    AMemory::c_free_func(p_vecDelDtor);
  }
}

// File Line: 390
// RVA: 0x120D70
void __fastcall SSList::mthd_as_copy(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rbp
  SSObjectBaseVtbl *vfptr; // rsi
  APSizedArrayBase<SSInstance> *v5; // rax
  APSizedArrayBase<SSInstance> *v6; // rdi
  unsigned int vecDelDtor; // ecx
  SSInstance **v8; // rax
  unsigned int v9; // ebx
  bool v10; // zf
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    v5 = (APSizedArrayBase<SSInstance> *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v6 = v5;
    if ( v5 )
    {
      vecDelDtor = (unsigned int)vfptr->__vecDelDtor;
      v5->i_count = 0;
      v5->i_array_p = 0i64;
      v5->i_size = 0;
      if ( vecDelDtor )
      {
        v5->i_size = vecDelDtor;
        v8 = APArrayBase<SSInstance>::alloc_array(vecDelDtor);
      }
      else
      {
        v5->i_size = 0;
        v8 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
      }
      v6->i_array_p = v8;
    }
    else
    {
      v6 = 0i64;
    }
    v9 = (unsigned int)vfptr->__vecDelDtor;
    APSizedArrayBase<SSInstance>::ensure_size(v6, LODWORD(vfptr->__vecDelDtor) + v6->i_count);
    memmove(&v6->i_array_p[v6->i_count], vfptr->get_obj_type, 8i64 * v9);
    v10 = v9 + v6->i_count == 0;
    v6->i_count += v9;
    if ( !v10 )
    {
      i_array_p = (ARefCountMix<SSInstance> **)v6->i_array_p;
      for ( i = &i_array_p[v6->i_count]; i_array_p < i; ++i_array_p )
        UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
    }
    *result_pp = SSInstance::pool_new(*(SSClass **)&i_obj_p[1].i_ptr_id, (unsigned __int64)v6);
  }
}

// File Line: 411
// RVA: 0x120F20
void __fastcall SSList::mthd_as_new(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  _QWORD *v4; // rax
  unsigned __int64 v5; // rbx
  SSObjectBase *i_obj_p; // rcx

  if ( result_pp )
  {
    v4 = AMemory::c_malloc_func(0x18ui64, "SSList");
    v5 = (unsigned __int64)v4;
    if ( v4 )
    {
      *(_DWORD *)v4 = 0;
      v4[1] = 0i64;
      *((_DWORD *)v4 + 4) = 0;
      v4[1] = AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v5 = 0i64;
    }
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(*(SSClass **)&i_obj_p[1].i_ptr_id, v5);
  }
}

// File Line: 427
// RVA: 0x120510
void __fastcall SSList::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // r14
  __int64 vecDelDtor_low; // rsi
  AStringRef *i_str_ref_p; // rax
  AStringRef *v8; // rax
  __int64 v9; // rbx
  unsigned int (__fastcall *get_obj_type)(SSObjectBase *); // rbx
  unsigned int (__fastcall *v11)(SSObjectBase *); // rsi
  AStringRef *v12; // rax
  __int64 v13; // rbx
  SSInstance *v14; // rax
  AStringRef *v15; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v20; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  __int64 v22; // [rsp+20h] [rbp-38h]
  AString v23; // [rsp+68h] [rbp+10h] BYREF
  SSInstance *v24; // [rsp+70h] [rbp+18h]
  unsigned __int64 *p_i_user_data; // [rsp+78h] [rbp+20h]

  if ( result_pp )
  {
    v22 = -2i64;
    v23.i_str_ref_p = AStringRef::get_empty();
    ++v23.i_str_ref_p->i_ref_count;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    vecDelDtor_low = LODWORD(vfptr->__vecDelDtor);
    if ( (_DWORD)vecDelDtor_low )
    {
      i_str_ref_p = v23.i_str_ref_p;
      if ( (unsigned int)(8 * vecDelDtor_low) >= v23.i_str_ref_p->i_size
        || v23.i_str_ref_p->i_ref_count + v23.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size_buffer(&v23, 8 * vecDelDtor_low);
        i_str_ref_p = v23.i_str_ref_p;
      }
      i_str_ref_p->i_length = 0;
      *v23.i_str_ref_p->i_cstr_p = 0;
      v8 = v23.i_str_ref_p;
      v9 = v23.i_str_ref_p->i_length + 1;
      if ( (unsigned int)v9 >= v23.i_str_ref_p->i_size
        || v23.i_str_ref_p->i_ref_count + v23.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&v23, v9);
        v8 = v23.i_str_ref_p;
      }
      v8->i_cstr_p[(unsigned int)(v9 - 1)] = 123;
      v23.i_str_ref_p->i_cstr_p[v9] = 0;
      v23.i_str_ref_p->i_length = v9;
      get_obj_type = vfptr->get_obj_type;
      v11 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)get_obj_type + 8 * vecDelDtor_low);
      if ( (unsigned __int64)get_obj_type < (unsigned __int64)v11 )
      {
        while ( 1 )
        {
          (*(void (__fastcall **)(_QWORD, AString *, _QWORD, SSInvokedMethod *, __int64))(**(_QWORD **)get_obj_type
                                                                                        + 88i64))(
            *(_QWORD *)get_obj_type,
            &v23,
            0i64,
            scope_p,
            v22);
          get_obj_type = (unsigned int (__fastcall *)(SSObjectBase *))((char *)get_obj_type + 8);
          if ( (unsigned __int64)get_obj_type >= (unsigned __int64)v11 )
            break;
          AString::append(&v23, ", ", 2u);
        }
      }
      v12 = v23.i_str_ref_p;
      v13 = v23.i_str_ref_p->i_length + 1;
      if ( (unsigned int)v13 >= v23.i_str_ref_p->i_size
        || v23.i_str_ref_p->i_ref_count + v23.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&v23, v13);
        v12 = v23.i_str_ref_p;
      }
      v12->i_cstr_p[(unsigned int)(v13 - 1)] = 125;
      v23.i_str_ref_p->i_cstr_p[v13] = 0;
      v23.i_str_ref_p->i_length = v13;
    }
    else
    {
      AString::set_cstr(&v23, "{}", 2u, 1);
    }
    v14 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v24 = v14;
    p_i_user_data = &v14->i_user_data;
    if ( v14 != (SSInstance *)-32i64 )
    {
      v14->i_user_data = (unsigned __int64)v23.i_str_ref_p;
      ++v23.i_str_ref_p->i_ref_count;
    }
    *result_pp = v14;
    v15 = v23.i_str_ref_p;
    if ( v23.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( v15->i_deallocate )
        AMemory::c_free_func(v15->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v15 < i_objects_a
        || (v20 = (unsigned __int64)v15 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v20) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v15);
    }
  }
}

// File Line: 479
// RVA: 0x123320
void __fastcall SSList::mthd_op_add(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rbp
  SSObjectBaseVtbl *vfptr; // r15
  APSizedArrayBase<SSInstance> *v6; // rax
  APSizedArrayBase<SSInstance> *v7; // rsi
  int vecDelDtor; // ecx
  unsigned int v9; // ecx
  SSInstance **v10; // rax
  unsigned int v11; // ebx
  unsigned __int64 i_user_data; // rbx
  unsigned int v13; // edi
  bool v14; // zf
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rdi

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    v6 = (APSizedArrayBase<SSInstance> *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v7 = v6;
    if ( v6 )
    {
      vecDelDtor = (int)vfptr->__vecDelDtor;
      v6->i_count = 0;
      v6->i_array_p = 0i64;
      v6->i_size = 0;
      v9 = vecDelDtor + 1;
      if ( v9 )
      {
        v6->i_size = v9;
        v10 = APArrayBase<SSInstance>::alloc_array(v9);
      }
      else
      {
        v6->i_size = 0;
        v10 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
      }
      v7->i_array_p = v10;
    }
    else
    {
      v7 = 0i64;
    }
    v11 = (unsigned int)vfptr->__vecDelDtor;
    APSizedArrayBase<SSInstance>::ensure_size(v7, LODWORD(vfptr->__vecDelDtor) + v7->i_count);
    memmove(&v7->i_array_p[v7->i_count], vfptr->get_obj_type, 8i64 * v11);
    v7->i_count += v11;
    i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v13 = *(_DWORD *)i_user_data;
    APSizedArrayBase<SSInstance>::ensure_size(v7, *(_DWORD *)i_user_data + v7->i_count);
    memmove(&v7->i_array_p[v7->i_count], *(const void **)(i_user_data + 8), 8i64 * v13);
    v14 = v13 + v7->i_count == 0;
    v7->i_count += v13;
    if ( !v14 )
    {
      i_array_p = (ARefCountMix<SSInstance> **)v7->i_array_p;
      for ( i = &i_array_p[v7->i_count]; i_array_p < i; ++i_array_p )
        UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
    }
    *result_pp = SSInstance::pool_new(*(SSClass **)&i_obj_p[1].i_ptr_id, (unsigned __int64)v7);
  }
}

// File Line: 522
// RVA: 0x1237B0
void __fastcall SSList::mthd_op_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *i_user_data; // r14
  APArrayBase<SSInstance> *v5; // rbp
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rsi
  __int64 v9; // rax
  ARefCountMix<SSInstance> **v10; // rbx
  ARefCountMix<SSInstance> **j; // rsi

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)i_obj_p->i_user_data;
  v5 = (APArrayBase<SSInstance> *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  i_count = v5->i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = (ARefCountMix<SSInstance> **)v5->i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
      UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
  }
  v9 = i_user_data->i_count;
  if ( (_DWORD)v9 )
  {
    v10 = (ARefCountMix<SSInstance> **)i_user_data->i_array_p;
    for ( j = &v10[v9]; v10 < j; ++v10 )
      ARefCountMix<SSInstance>::dereference(*v10 + 4);
  }
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::operator=(i_user_data, v5);
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 544
// RVA: 0x122580
void __fastcall SSList::mthd_get_count(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned __int64)i_obj_p[2].vfptr->__vecDelDtor);
  }
}

// File Line: 560
// RVA: 0x1225C0
void __fastcall SSList::mthd_get_count_after(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   (unsigned int)i_obj_p[2].vfptr->__vecDelDtor
                 - LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 581
// RVA: 0x122D00
void __fastcall SSList::mthd_is_empty(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(i_obj_p[2].vfptr->__vecDelDtor == 0);
  }
}

// File Line: 597
// RVA: 0x122D80
void __fastcall SSList::mthd_is_filled(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(i_obj_p[2].vfptr->__vecDelDtor != 0);
  }
}

// File Line: 613
// RVA: 0x122520
void __fastcall SSList::mthd_get_at(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdx
  __int64 i_user_data_low; // rcx
  SSInstance *v6; // rdx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_user_data_low = LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    if ( (int)i_user_data_low >= SLODWORD(vfptr->__vecDelDtor) || (int)i_user_data_low < 0 )
    {
      *result_pp = SSBrain::c_nil_p;
    }
    else
    {
      v6 = (SSInstance *)*((_QWORD *)vfptr->get_obj_type + i_user_data_low);
      *result_pp = v6;
      ++v6->i_ref_count;
    }
  }
}

// File Line: 641
// RVA: 0x1226B0
void __fastcall SSList::mthd_get_first(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r9
  SSInstance *v3; // r8
  SSObjectBaseVtbl *vfptr; // rax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    v3 = 0i64;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( LODWORD(vfptr->__vecDelDtor) )
      v3 = *(SSInstance **)vfptr->get_obj_type;
    *result_pp = v3;
    ++v3->i_ref_count;
  }
}

// File Line: 659
// RVA: 0x1226F0
void __fastcall SSList::mthd_get_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r9
  SSInstance *v3; // r8
  SSObjectBaseVtbl *vfptr; // r10

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    v3 = 0i64;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( LODWORD(vfptr->__vecDelDtor) )
      v3 = (SSInstance *)*((_QWORD *)vfptr->get_obj_type + (unsigned int)(LODWORD(vfptr->__vecDelDtor) - 1));
    *result_pp = v3;
    ++v3->i_ref_count;
  }
}

// File Line: 677
// RVA: 0x122730
void __fastcall SSList::mthd_get_list_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r15
  SSObjectBaseVtbl *vfptr; // r14
  unsigned int *i_user_data; // rdi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v6; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rsi
  __int64 v8; // rax
  SSInstance **v9; // rdi
  SSInstance **i; // rbp
  SSInstance *v11; // rbx
  SSInstance **get_obj_type; // rax
  SSInstance **v13; // rdx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_user_data = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v7 = v6;
    if ( v6 )
    {
      v6->i_count = 0;
      v6->i_array_p = 0i64;
      v6->i_size = 0;
      v6->i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v7 = 0i64;
    }
    v8 = *i_user_data;
    if ( (_DWORD)v8 )
    {
      if ( LODWORD(vfptr->__vecDelDtor) )
      {
        v9 = (SSInstance **)*((_QWORD *)i_user_data + 1);
        for ( i = &v9[v8]; v9 < i; ++v9 )
        {
          v11 = *v9;
          if ( LODWORD(vfptr->__vecDelDtor) )
          {
            get_obj_type = (SSInstance **)vfptr->get_obj_type;
            v13 = &get_obj_type[LODWORD(vfptr->__vecDelDtor) - 1];
            if ( get_obj_type <= v13 )
            {
              while ( v11 != *get_obj_type )
              {
                if ( ++get_obj_type > v13 )
                  goto LABEL_17;
              }
              ++v11->i_ref_count;
              APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(v7, v11);
              ++v11->i_ref_count;
            }
          }
LABEL_17:
          ;
        }
      }
    }
    *result_pp = SSInstance::pool_new(*(SSClass **)&i_obj_p[1].i_ptr_id, (unsigned __int64)v7);
  }
}

// File Line: 717
// RVA: 0x122930
void __fastcall SSList::mthd_get_range(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // r9
  unsigned int i_user_data; // r15d
  unsigned int v5; // ebx
  SSObjectBase *i_obj_p; // rbp
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *vfptr; // rsi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v8; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v9; // rdi
  SSInstance **v10; // rax
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **v12; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    v5 = i_array_p[1]->i_data_p->i_user_data;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)i_obj_p[2].vfptr;
    v8 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v9 = v8;
    if ( v8 )
    {
      v8->i_count = 0;
      v8->i_array_p = 0i64;
      v8->i_size = 0;
      if ( v5 )
      {
        v8->i_size = v5;
        v10 = APArrayBase<SSInstance>::alloc_array(v5);
      }
      else
      {
        v8->i_size = 0;
        v10 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
      }
      v9->i_array_p = v10;
    }
    else
    {
      v9 = 0i64;
    }
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append_all(v9, vfptr, i_user_data, v5);
    i_count = v9->i_count;
    if ( (_DWORD)i_count )
    {
      v12 = (ARefCountMix<SSInstance> **)v9->i_array_p;
      for ( i = &v12[i_count]; v12 < i; ++v12 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v12 + 4);
    }
    *result_pp = SSInstance::pool_new(*(SSClass **)&i_obj_p[1].i_ptr_id, (unsigned __int64)v9);
  }
}

// File Line: 740
// RVA: 0x125480
void __fastcall SSList::mthd_reverse(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // r9
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rcx
  SSData *v6; // rax
  unsigned __int64 i_user_data; // rdx
  __int64 i_user_data_low; // r8
  __int64 v9; // rax
  __int64 *v10; // rax
  __int64 *i; // r8
  __int64 v12; // rcx
  __int64 v13; // rdx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_data_p = i_array_p[1]->i_data_p;
  v6 = *i_array_p;
  i_user_data = i_obj_p->i_user_data;
  i_user_data_low = LODWORD(i_data_p->i_user_data);
  v9 = LODWORD(v6->i_data_p->i_user_data);
  if ( (_DWORD)i_user_data_low == -1 )
    i_user_data_low = (unsigned int)(*(_DWORD *)i_user_data - v9);
  if ( (_DWORD)i_user_data_low )
  {
    v10 = (__int64 *)(*(_QWORD *)(i_user_data + 8) + 8 * v9);
    for ( i = &v10[i_user_data_low - 1]; v10 < i; ++v10 )
    {
      v12 = *i;
      v13 = *v10;
      --i;
      *v10 = v12;
      i[1] = v13;
    }
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 761
// RVA: 0x125510
void __fastcall SSList::mthd_rotate_down(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  unsigned __int64 i_user_data; // r14
  __int64 *v5; // rcx
  __int64 v6; // rbx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = i_obj_p->i_user_data;
  if ( *(_DWORD *)i_user_data > 1u )
  {
    v5 = *(__int64 **)(i_user_data + 8);
    v6 = *v5;
    memmove(v5, v5 + 1, 8i64 * (unsigned int)(*(_DWORD *)i_user_data - 1));
    *(_QWORD *)(*(_QWORD *)(i_user_data + 8) + 8i64 * (unsigned int)(*(_DWORD *)i_user_data - 1)) = v6;
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 780
// RVA: 0x125590
void __fastcall SSList::mthd_rotate_up(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  unsigned __int64 i_user_data; // r14
  __int64 v5; // rdx
  unsigned int v6; // eax
  __int64 v7; // rbx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = i_obj_p->i_user_data;
  if ( *(_DWORD *)i_user_data > 1u )
  {
    v5 = *(_QWORD *)(i_user_data + 8);
    v6 = *(_DWORD *)i_user_data - 1;
    v7 = *(_QWORD *)(v5 + 8i64 * v6);
    memmove((void *)(v5 + 8), (const void *)v5, 8i64 * v6);
    **(_QWORD **)(i_user_data + 8) = v7;
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 799
// RVA: 0x1259B0
void __fastcall SSList::mthd_swap(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // r10
  SSData **i_array_p; // rdx
  __int64 v5; // r8
  _DWORD *v6; // r9
  _DWORD *v7; // rcx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  v5 = *(_QWORD *)(i_obj_p->i_user_data + 8);
  v6 = (_DWORD *)(v5 + 8i64 * LODWORD((*i_array_p)->i_data_p->i_user_data));
  v7 = (_DWORD *)(v5 + 8i64 * LODWORD(i_array_p[1]->i_data_p->i_user_data));
  *v6 ^= *v7;
  *v7 ^= *v6;
  *v6 ^= *v7;
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 820
// RVA: 0x120950
void __fastcall SSList::mthd_append(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rbx
  SSData **i_array_p; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *i_user_data; // rcx
  SSInstance *i_data_p; // rdx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)i_obj_p->i_user_data;
  i_data_p = (*i_array_p)->i_data_p;
  ++i_data_p->i_ref_count;
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(i_user_data, i_data_p);
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 841
// RVA: 0x120A20
void __fastcall SSList::mthd_append_absent_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r9
  SSObjectBaseVtbl *vfptr; // r10
  SSInstance *i_data_p; // rbx
  SSInstance **get_obj_type; // rcx
  SSInstance **v7; // rdx
  bool v8; // cl

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
  if ( LODWORD(vfptr->__vecDelDtor)
    && (get_obj_type = (SSInstance **)vfptr->get_obj_type,
        v7 = &get_obj_type[LODWORD(vfptr->__vecDelDtor) - 1],
        get_obj_type <= v7) )
  {
    while ( i_data_p != *get_obj_type )
    {
      if ( ++get_obj_type > v7 )
        goto LABEL_9;
    }
    v8 = 0;
  }
  else
  {
LABEL_9:
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(
      (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)i_obj_p[2].vfptr,
      i_data_p);
    ++i_data_p->i_ref_count;
    v8 = 1;
  }
  if ( result_pp )
    *result_pp = SSBoolean::pool_new(v8);
}

// File Line: 863
// RVA: 0x120AC0
void __fastcall SSList::mthd_append_absent_list_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rsi
  unsigned int *i_user_data; // rbx
  __int64 v5; // rax
  SSInstance **v6; // rbx
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rdi
  SSInstance **i; // rbp
  SSInstance *v9; // rdx
  SSInstance **i_array_p; // rax
  SSInstance **v11; // r9

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = *i_user_data;
  if ( (_DWORD)v5 )
  {
    v6 = (SSInstance **)*((_QWORD *)i_user_data + 1);
    v7 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)i_obj_p->i_user_data;
    for ( i = &v6[v5]; v6 < i; ++v6 )
    {
      v9 = *v6;
      if ( v7->i_count && (i_array_p = v7->i_array_p, v11 = &i_array_p[v7->i_count - 1], i_array_p <= v11) )
      {
        while ( v9 != *i_array_p )
        {
          if ( ++i_array_p > v11 )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(v7, v9);
        ++(*v6)->i_ref_count;
      }
    }
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 898
// RVA: 0x120BA0
void __fastcall SSList::mthd_append_items(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rbx
  SSData **i_array_p; // rdx
  APSizedArrayBase<SSInstance> *i_user_data; // rsi
  __int64 i_user_data_low; // r14
  unsigned __int64 i_data_p; // rbp
  SSInstance **v8; // rdi

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = (APSizedArrayBase<SSInstance> *)i_obj_p->i_user_data;
  i_user_data_low = LODWORD(i_array_p[1]->i_data_p->i_user_data);
  if ( (_DWORD)i_user_data_low )
  {
    i_data_p = (unsigned __int64)(*i_array_p)->i_data_p;
    *(_DWORD *)(i_data_p + 16) += i_user_data_low;
    APSizedArrayBase<SSInstance>::ensure_size(i_user_data, i_user_data_low + i_user_data->i_count);
    v8 = &i_user_data->i_array_p[i_user_data->i_count];
    if ( v8 < &v8[i_user_data_low] )
      memset64(v8, i_data_p, ((unsigned __int64)(8 * i_user_data_low - 1) >> 3) + 1);
    i_user_data->i_count += i_user_data_low;
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 924
// RVA: 0x120C60
void __fastcall SSList::mthd_op_add_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  APSizedArrayBase<SSInstance> *i_user_data; // r15
  unsigned int *v5; // r14
  __int64 v6; // rax
  ARefCountMix<SSInstance> **v7; // rbx
  ARefCountMix<SSInstance> **i; // rsi
  unsigned int v9; // ebx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (APSizedArrayBase<SSInstance> *)i_obj_p->i_user_data;
  v5 = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = *v5;
  if ( (_DWORD)v6 )
  {
    v7 = (ARefCountMix<SSInstance> **)*((_QWORD *)v5 + 1);
    for ( i = &v7[v6]; v7 < i; ++v7 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v7 + 4);
  }
  v9 = *v5;
  APSizedArrayBase<SSInstance>::ensure_size(i_user_data, *v5 + i_user_data->i_count);
  memmove(&i_user_data->i_array_p[i_user_data->i_count], *((const void **)v5 + 1), 8i64 * v9);
  i_user_data->i_count += v9;
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 945
// RVA: 0x122AB0
void __fastcall SSList::mthd_insert(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rbx
  SSData **i_array_p; // r8
  APSizedArrayBase<SSInstance> *i_user_data; // rcx
  SSInstance *i_data_p; // rdx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = (APSizedArrayBase<SSInstance> *)i_obj_p->i_user_data;
  i_data_p = (*i_array_p)->i_data_p;
  LODWORD(i_array_p) = i_array_p[1]->i_data_p->i_user_data;
  ++i_data_p->i_ref_count;
  APSizedArrayBase<SSInstance>::insert(i_user_data, i_data_p, (unsigned int)i_array_p);
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 967
// RVA: 0x122B10
void __fastcall SSList::mthd_insert_items(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rbx
  SSData **i_array_p; // r8
  unsigned int i_user_data; // r9d
  APSizedArrayBase<SSInstance> *v6; // rcx
  SSInstance *i_data_p; // rdx
  unsigned int v8; // r8d

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = i_array_p[2]->i_data_p->i_user_data;
  if ( i_user_data )
  {
    v6 = (APSizedArrayBase<SSInstance> *)i_obj_p->i_user_data;
    i_data_p = (*i_array_p)->i_data_p;
    v8 = i_array_p[1]->i_data_p->i_user_data;
    i_data_p->i_ref_count += i_user_data;
    APSizedArrayBase<SSInstance>::insert(v6, i_data_p, v8, i_user_data);
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 994
// RVA: 0x122B80
void __fastcall SSList::mthd_insert_list(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  SSData **i_array_p; // rdx
  APSizedArrayBase<SSInstance> *i_user_data; // rbp
  APArrayBase<SSInstance> *v6; // r15
  __int64 i_count; // rax
  unsigned int v8; // r12d
  ARefCountMix<SSInstance> **v9; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = (APSizedArrayBase<SSInstance> *)i_obj_p->i_user_data;
  v6 = (APArrayBase<SSInstance> *)(*i_array_p)->i_data_p->i_user_data;
  i_count = v6->i_count;
  v8 = i_array_p[1]->i_data_p->i_user_data;
  if ( (_DWORD)i_count )
  {
    v9 = (ARefCountMix<SSInstance> **)v6->i_array_p;
    for ( i = &v9[i_count]; v9 < i; ++v9 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v9 + 4);
  }
  APSizedArrayBase<SSInstance>::insert_all(i_user_data, v6, v8);
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1016
// RVA: 0x125610
void __fastcall SSList::mthd_set_at(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rbx
  SSData **i_array_p; // rdx
  unsigned __int64 i_user_data; // rbp
  SSInstance *i_data_p; // rsi
  __int64 v7; // r14
  _DWORD *v8; // rcx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = i_obj_p->i_user_data;
  i_data_p = i_array_p[1]->i_data_p;
  v7 = 8i64 * LODWORD((*i_array_p)->i_data_p->i_user_data);
  v8 = *(_DWORD **)(v7 + *(_QWORD *)(i_user_data + 8));
  ++i_data_p->i_ref_count;
  if ( v8[4]-- == 1 )
  {
    v8[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v8 + 112i64))(v8);
  }
  *(_QWORD *)(v7 + *(_QWORD *)(i_user_data + 8)) = i_data_p;
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1040
// RVA: 0x125700
void __fastcall SSList::mthd_set_items(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  SSData **i_array_p; // rdx
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *i_user_data; // r15
  unsigned int v6; // ebp
  SSInstance *i_data_p; // r13
  SSData *v8; // rax
  __int64 v9; // rdx
  __int64 i_user_data_low; // r12
  unsigned int v11; // eax
  ARefCountMix<SSInstance> **v12; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)i_obj_p->i_user_data;
  v6 = i_array_p[2]->i_data_p->i_user_data;
  if ( v6 )
  {
    i_data_p = (*i_array_p)->i_data_p;
    v8 = i_array_p[1];
    v9 = v6;
    i_user_data_low = LODWORD(v8->i_data_p->i_user_data);
    i_data_p->i_ref_count += v6;
    v11 = i_user_data->i_count - i_user_data_low;
    if ( v11 < v6 )
      v9 = v11;
    if ( (_DWORD)v9 )
    {
      if ( (_DWORD)v9 == -1 )
        v9 = v11;
      if ( (_DWORD)v9 )
      {
        v12 = (ARefCountMix<SSInstance> **)&i_user_data->i_array_p[i_user_data_low];
        for ( i = &v12[v9]; v12 < i; ++v12 )
          ARefCountMix<SSInstance>::dereference(*v12 + 4);
      }
    }
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::set_all(i_user_data, i_data_p, i_user_data_low, v6);
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1075
// RVA: 0x121CE0
void __fastcall SSList::mthd_crop(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  SSData **i_array_p; // rdx
  unsigned int *i_user_data; // r14
  __int64 i_user_data_low; // r12
  __int64 v7; // r15
  __int64 v8; // rax
  ARefCountMix<SSInstance> **v9; // rbx
  ARefCountMix<SSInstance> **i; // rsi
  unsigned int v11; // eax
  ARefCountMix<SSInstance> **v12; // rbx
  ARefCountMix<SSInstance> **j; // rsi
  char *v14; // rcx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = (unsigned int *)i_obj_p->i_user_data;
  i_user_data_low = LODWORD((*i_array_p)->i_data_p->i_user_data);
  v7 = LODWORD(i_array_p[1]->i_data_p->i_user_data);
  v8 = (unsigned int)i_user_data_low;
  if ( (_DWORD)i_user_data_low == -1 )
    v8 = *i_user_data;
  if ( (_DWORD)v8 )
  {
    v9 = (ARefCountMix<SSInstance> **)*((_QWORD *)i_user_data + 1);
    for ( i = &v9[v8]; v9 < i; ++v9 )
      ARefCountMix<SSInstance>::dereference(*v9 + 4);
  }
  v11 = v7 + i_user_data_low;
  if ( *i_user_data != (_DWORD)v7 + (_DWORD)i_user_data_low )
  {
    v12 = (ARefCountMix<SSInstance> **)(*((_QWORD *)i_user_data + 1) + 8i64 * v11);
    for ( j = &v12[*i_user_data - v11]; v12 < j; ++v12 )
      ARefCountMix<SSInstance>::dereference(*v12 + 4);
  }
  if ( (_DWORD)v7 )
  {
    v14 = (char *)*((_QWORD *)i_user_data + 1);
    *i_user_data = v7;
    memmove(v14, &v14[8 * i_user_data_low], 8 * v7);
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1098
// RVA: 0x122320
void __fastcall SSList::mthd_empty(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  unsigned int *i_user_data; // r14
  __int64 v5; // rax
  ARefCountMix<SSInstance> **v6; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (unsigned int *)i_obj_p->i_user_data;
  v5 = *i_user_data;
  if ( (_DWORD)v5 )
  {
    v6 = (ARefCountMix<SSInstance> **)*((_QWORD *)i_user_data + 1);
    for ( i = &v6[v5]; v6 < i; ++v6 )
      ARefCountMix<SSInstance>::dereference(*v6 + 4);
  }
  *i_user_data = 0;
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1118
// RVA: 0x124AF0
void __fastcall SSList::mthd_pop_at(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rdx
  __int64 i_user_data_low; // r8
  unsigned int (__fastcall *get_obj_type)(SSObjectBase *); // rax
  SSInstance *v7; // rbx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  i_user_data_low = LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  get_obj_type = vfptr->get_obj_type;
  v7 = (SSInstance *)*((_QWORD *)get_obj_type + i_user_data_low);
  memmove(
    (char *)get_obj_type + 8 * i_user_data_low,
    (char *)get_obj_type + 8 * i_user_data_low + 8,
    8i64 * (unsigned int)(--LODWORD(vfptr->__vecDelDtor) - i_user_data_low));
  if ( result_pp )
  {
    *result_pp = v7;
  }
  else if ( v7->i_ref_count-- == 1 )
  {
    v7->i_ref_count = 0x80000000;
    v7->vfptr[1].get_scope_context(v7);
  }
}

// File Line: 1138
// RVA: 0x124B80
void __fastcall SSList::mthd_pop_first(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSInstance *v3; // rbx
  SSObjectBaseVtbl *vfptr; // rdx
  SSInstance **get_obj_type; // rcx
  unsigned int v7; // eax

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( LODWORD(vfptr->__vecDelDtor) )
  {
    get_obj_type = (SSInstance **)vfptr->get_obj_type;
    v7 = LODWORD(vfptr->__vecDelDtor) - 1;
    v3 = *get_obj_type;
    LODWORD(vfptr->__vecDelDtor) = v7;
    memmove(get_obj_type, get_obj_type + 1, 8i64 * v7);
  }
  if ( result_pp )
  {
    *result_pp = v3;
  }
  else if ( v3->i_ref_count-- == 1 )
  {
    v3->i_ref_count = 0x80000000;
    v3->vfptr[1].get_scope_context(v3);
  }
}

// File Line: 1158
// RVA: 0x124C00
void __fastcall SSList::mthd_pop_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSInstance *v5; // rcx
  SSObjectBaseVtbl *vfptr; // rdx
  unsigned int v7; // eax

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  v5 = 0i64;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( LODWORD(vfptr->__vecDelDtor) )
  {
    v7 = LODWORD(vfptr->__vecDelDtor) - 1;
    LODWORD(vfptr->__vecDelDtor) = v7;
    v5 = (SSInstance *)*((_QWORD *)vfptr->get_obj_type + v7);
  }
  if ( result_pp )
  {
    *result_pp = v5;
  }
  else if ( v5->i_ref_count-- == 1 )
  {
    v5->i_ref_count = 0x80000000;
    v5->vfptr[1].get_scope_context(v5);
  }
}

// File Line: 1178
// RVA: 0x124C60
void __fastcall SSList::mthd_pop_range(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rbp
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *vfptr; // rsi
  SSData **i_array_p; // rdx
  __int64 i_user_data_low; // r14
  unsigned int i_user_data; // edi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v8; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v9; // rbx
  SSInstance **v10; // rax
  int v11; // edx
  ARefCountMix<SSInstance> **v12; // rbx
  ARefCountMix<SSInstance> **i; // rbp

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)i_obj_p[2].vfptr;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data_low = LODWORD((*i_array_p)->i_data_p->i_user_data);
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  if ( result_pp )
  {
    v8 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v9 = v8;
    if ( v8 )
    {
      v8->i_count = 0;
      v8->i_array_p = 0i64;
      v8->i_size = 0;
      if ( i_user_data )
      {
        v8->i_size = i_user_data;
        v10 = APArrayBase<SSInstance>::alloc_array(i_user_data);
      }
      else
      {
        v8->i_size = 0;
        v10 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
      }
      v9->i_array_p = v10;
    }
    else
    {
      v9 = 0i64;
    }
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::pop_all(vfptr, v9, i_user_data_low, i_user_data);
    *result_pp = SSInstance::pool_new(*(SSClass **)&i_obj_p[1].i_ptr_id, (unsigned __int64)v9);
  }
  else
  {
    v11 = i_array_p[1]->i_data_p->i_user_data;
    if ( i_user_data == -1 )
      v11 = vfptr->i_count - i_user_data_low;
    if ( v11 )
    {
      v12 = (ARefCountMix<SSInstance> **)&vfptr->i_array_p[i_user_data_low];
      for ( i = &v12[v11]; v12 < i; ++v12 )
        ARefCountMix<SSInstance>::dereference(*v12 + 4);
    }
    if ( i_user_data == -1 )
      i_user_data = vfptr->i_count - i_user_data_low;
    if ( i_user_data )
    {
      vfptr->i_count -= i_user_data;
      memmove(
        &vfptr->i_array_p[i_user_data_low],
        &vfptr->i_array_p[i_user_data_low] + i_user_data,
        8i64 * (unsigned int)(vfptr->i_count - i_user_data_low));
    }
  }
}

// File Line: 1205
// RVA: 0x124DC0
void __fastcall SSList::mthd_pop_range_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rsi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *vfptr; // r14
  unsigned int i_user_data; // edi
  __int64 v6; // rbp
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v8; // rbx
  SSInstance **v9; // rax
  int v10; // edx
  ARefCountMix<SSInstance> **v11; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)i_obj_p[2].vfptr;
  i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = vfptr->i_count - i_user_data;
  if ( result_pp )
  {
    v7 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v8 = v7;
    if ( v7 )
    {
      v7->i_count = 0;
      v7->i_array_p = 0i64;
      v7->i_size = 0;
      if ( i_user_data )
      {
        v7->i_size = i_user_data;
        v9 = APArrayBase<SSInstance>::alloc_array(i_user_data);
      }
      else
      {
        v7->i_size = 0;
        v9 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
      }
      v8->i_array_p = v9;
    }
    else
    {
      v8 = 0i64;
    }
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::pop_all(vfptr, v8, v6, i_user_data);
    *result_pp = SSInstance::pool_new(*(SSClass **)&i_obj_p[1].i_ptr_id, (unsigned __int64)v8);
  }
  else
  {
    v10 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data == -1 )
      v10 = vfptr->i_count - v6;
    if ( v10 )
    {
      v11 = (ARefCountMix<SSInstance> **)&vfptr->i_array_p[v6];
      for ( i = &v11[v10]; v11 < i; ++v11 )
        ARefCountMix<SSInstance>::dereference(*v11 + 4);
    }
    vfptr->i_count -= i_user_data;
  }
}

// File Line: 1232
// RVA: 0x124EF0
void __fastcall SSList::mthd_remove_at(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rbx
  unsigned __int64 i_user_data; // rdx
  __int64 i_user_data_low; // r8
  __int64 v6; // rax
  _DWORD *v7; // rsi

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = i_obj_p->i_user_data;
  i_user_data_low = LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  v6 = *(_QWORD *)(i_user_data + 8);
  v7 = *(_DWORD **)(v6 + 8 * i_user_data_low);
  memmove(
    (void *)(v6 + 8 * i_user_data_low),
    (const void *)(v6 + 8 * i_user_data_low + 8),
    8i64 * (unsigned int)(--*(_DWORD *)i_user_data - i_user_data_low));
  if ( v7[4]-- == 1 )
  {
    v7[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v7 + 112i64))(v7);
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1257
// RVA: 0x124F80
void __fastcall SSList::mthd_remove_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // r10
  bool v3; // si
  int i_user_data; // r11d
  SSObjectBase *i_obj_p; // r9
  SSObjectBaseVtbl *vfptr; // rbx
  SSInstance *i_data_p; // rdi
  SSData *v10; // rax
  int vecDelDtor; // r10d
  __int64 i_user_data_low; // rax
  __int64 v13; // rcx
  unsigned int (__fastcall *get_obj_type)(SSObjectBase *); // r9
  SSInstance **v15; // rax
  unsigned __int64 v16; // rdx
  unsigned int v17; // ebx
  SSInstance *v18; // rax
  __int64 v19; // rbx
  SSInstance *v20; // r15
  _DWORD *v21; // rcx
  bool v22; // zf

  i_array_p = scope_p->i_data.i_array_p;
  v3 = 0;
  i_user_data = i_array_p[2]->i_data_p->i_user_data;
  if ( i_user_data )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_data_p = (*i_array_p)->i_data_p;
    v10 = i_array_p[1];
    vecDelDtor = (int)vfptr->__vecDelDtor;
    i_user_data_low = LODWORD(v10->i_data_p->i_user_data);
    v13 = (unsigned int)(i_user_data_low + i_user_data - 1);
    if ( !LODWORD(vfptr->__vecDelDtor) )
      goto LABEL_11;
    if ( (_DWORD)v13 == -1 )
      v13 = (unsigned int)(vecDelDtor - 1);
    get_obj_type = vfptr->get_obj_type;
    v15 = (SSInstance **)((char *)get_obj_type + 8 * i_user_data_low);
    v16 = (unsigned __int64)get_obj_type + 8 * v13;
    if ( (unsigned __int64)v15 <= v16 )
    {
      while ( i_data_p != *v15 )
      {
        if ( (unsigned __int64)++v15 > v16 )
          goto LABEL_11;
      }
      LODWORD(vfptr->__vecDelDtor) = vecDelDtor - 1;
      v17 = ((char *)v15 - (char *)get_obj_type) >> 3;
      memmove((char *)get_obj_type + 8 * v17, (char *)get_obj_type + 8 * v17 + 8, 8i64 * (vecDelDtor - 1 - v17));
      v3 = 1;
      v18 = SSInstance::pool_new(SSBrain::c_integer_class_p, v17);
      v19 = *((_QWORD *)scope_p->i_data.i_array_p + 3);
      v20 = v18;
      v21 = *(_DWORD **)(v19 + 8);
      v22 = v21[4]-- == 1;
      if ( v22 )
      {
        v21[4] = 0x80000000;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v21 + 112i64))(v21);
      }
      *(_QWORD *)(v19 + 8) = v20;
      v22 = i_data_p->i_ref_count-- == 1;
      if ( v22 )
      {
        i_data_p->i_ref_count = 0x80000000;
        i_data_p->vfptr[1].get_scope_context(i_data_p);
      }
    }
    else
    {
LABEL_11:
      v3 = 0;
    }
  }
  if ( result_pp )
    *result_pp = SSBoolean::pool_new(v3);
}

// File Line: 1292
// RVA: 0x1250E0
void __fastcall SSList::mthd_remove_first(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rbx
  _DWORD *v3; // rdi
  unsigned __int64 i_user_data; // rdx
  _QWORD *v6; // rcx
  unsigned int v7; // eax

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = i_obj_p->i_user_data;
  if ( *(_DWORD *)i_user_data )
  {
    v6 = *(_QWORD **)(i_user_data + 8);
    v7 = *(_DWORD *)i_user_data - 1;
    v3 = (_DWORD *)*v6;
    *(_DWORD *)i_user_data = v7;
    memmove(v6, v6 + 1, 8i64 * v7);
  }
  if ( v3[4]-- == 1 )
  {
    v3[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v3 + 112i64))(v3);
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1311
// RVA: 0x125160
void __fastcall SSList::mthd_remove_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rbx
  _DWORD *v5; // rcx
  unsigned __int64 i_user_data; // rdx
  unsigned int v7; // eax

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  v5 = 0i64;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = i_obj_p->i_user_data;
  if ( *(_DWORD *)i_user_data )
  {
    v7 = *(_DWORD *)i_user_data - 1;
    *(_DWORD *)i_user_data = v7;
    v5 = *(_DWORD **)(*(_QWORD *)(i_user_data + 8) + 8i64 * v7);
  }
  if ( v5[4]-- == 1 )
  {
    v5[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 112i64))(v5);
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1330
// RVA: 0x1251D0
void __fastcall SSList::mthd_remove_list_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  unsigned int *i_user_data; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rsi
  unsigned __int64 i; // rbp
  _QWORD *v9; // r9
  __int64 v10; // r10
  unsigned __int64 v11; // rdx
  _QWORD *v12; // rax
  _DWORD *v13; // rcx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = *i_user_data;
  if ( (_DWORD)v5 )
  {
    v6 = *((_QWORD *)i_user_data + 1);
    v7 = i_obj_p->i_user_data;
    for ( i = v6 + 8 * v5; v6 < i; v6 += 8i64 )
    {
      if ( *(_DWORD *)v7 )
      {
        v9 = *(_QWORD **)(v7 + 8);
        v10 = (unsigned int)(*(_DWORD *)v7 - 1);
        v11 = (unsigned __int64)&v9[v10];
        v12 = v9;
        if ( (unsigned __int64)v9 <= v11 )
        {
          while ( *(_QWORD *)v6 != *v12 )
          {
            if ( (unsigned __int64)++v12 > v11 )
              goto LABEL_13;
          }
          *(_DWORD *)v7 = v10;
          memmove(
            &v9[(unsigned int)(v12 - v9)],
            &v9[(unsigned int)(v12 - v9) + 1],
            8i64 * ((unsigned int)v10 - (unsigned int)(v12 - v9)));
          v13 = *(_DWORD **)v6;
          if ( (*(_DWORD *)(*(_QWORD *)v6 + 16i64))-- == 1 )
          {
            v13[4] = 0x80000000;
            (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v13 + 112i64))(v13);
          }
        }
      }
LABEL_13:
      ;
    }
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1365
// RVA: 0x1252D0
void __fastcall SSList::mthd_remove_range(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  SSData **i_array_p; // rdx
  unsigned __int64 i_user_data; // r14
  __int64 i_user_data_low; // r15
  unsigned int v7; // esi
  unsigned int v8; // edx
  ARefCountMix<SSInstance> **v9; // rbx
  ARefCountMix<SSInstance> **i; // rbp
  __int64 v11; // rcx

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  i_user_data = i_obj_p->i_user_data;
  i_user_data_low = LODWORD((*i_array_p)->i_data_p->i_user_data);
  v7 = i_array_p[1]->i_data_p->i_user_data;
  v8 = v7;
  if ( v7 == -1 )
    v8 = *(_DWORD *)i_user_data - i_user_data_low;
  if ( v8 )
  {
    v9 = (ARefCountMix<SSInstance> **)(*(_QWORD *)(i_user_data + 8) + 8 * i_user_data_low);
    for ( i = &v9[v8]; v9 < i; ++v9 )
      ARefCountMix<SSInstance>::dereference(*v9 + 4);
  }
  if ( v7 == -1 )
    v7 = *(_DWORD *)i_user_data - i_user_data_low;
  if ( v7 )
  {
    v11 = *(_QWORD *)(i_user_data + 8);
    *(_DWORD *)i_user_data -= v7;
    memmove(
      (void *)(v11 + 8 * i_user_data_low),
      (const void *)(v11 + 8 * (i_user_data_low + v7)),
      8i64 * (unsigned int)(*(_DWORD *)i_user_data - i_user_data_low));
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1387
// RVA: 0x1253D0
void __fastcall SSList::mthd_remove_range_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // rdi
  unsigned __int64 i_user_data; // r14
  unsigned int v5; // ebp
  unsigned int v6; // eax
  unsigned int v7; // edx
  ARefCountMix<SSInstance> **v8; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = i_obj_p->i_user_data;
  v5 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = *(_DWORD *)i_user_data - v5;
  v7 = v5;
  if ( v5 == -1 )
    v7 = *(_DWORD *)i_user_data - v6;
  if ( v7 )
  {
    v8 = (ARefCountMix<SSInstance> **)(*(_QWORD *)(i_user_data + 8) + 8i64 * v6);
    for ( i = &v8[v7]; v8 < i; ++v8 )
      ARefCountMix<SSInstance>::dereference(*v8 + 4);
  }
  *(_DWORD *)i_user_data -= v5;
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 1408
// RVA: 0x122480
void __fastcall SSList::mthd_equals_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdx
  bool v5; // r9
  SSInstance *i_data_p; // rax
  __int64 vecDelDtor_low; // rcx
  unsigned __int64 i_user_data; // rax
  unsigned int (__fastcall *v9)(SSObjectBase *); // rax
  unsigned int (__fastcall *get_obj_type)(SSObjectBase *); // rdx
  unsigned int (__fastcall *v11)(SSObjectBase *); // r8
  signed __int64 v12; // rdx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    v5 = 0;
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    vecDelDtor_low = LODWORD(vfptr->__vecDelDtor);
    i_user_data = i_data_p->i_user_data;
    if ( (_DWORD)vecDelDtor_low == *(_DWORD *)i_user_data )
    {
      v9 = *(unsigned int (__fastcall **)(SSObjectBase *))(i_user_data + 8);
      get_obj_type = vfptr->get_obj_type;
      v5 = 1;
      v11 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)v9 + 8 * vecDelDtor_low);
      if ( (unsigned __int64)v9 < (unsigned __int64)v11 )
      {
        v12 = (char *)get_obj_type - (char *)v9;
        while ( *(_QWORD *)((char *)v9 + v12) == *(_QWORD *)v9 )
        {
          v9 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)v9 + 8);
          if ( (unsigned __int64)v9 >= (unsigned __int64)v11 )
          {
            *result_pp = SSBoolean::pool_new(1);
            return;
          }
        }
        v5 = 0;
      }
    }
    *result_pp = SSBoolean::pool_new(v5);
  }
}

// File Line: 1451
// RVA: 0x123230
void __fastcall SSList::mthd_not_equal_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdx
  bool v5; // r9
  SSInstance *i_data_p; // rax
  __int64 vecDelDtor_low; // rcx
  unsigned __int64 i_user_data; // rax
  unsigned int (__fastcall *v9)(SSObjectBase *); // rax
  unsigned int (__fastcall *get_obj_type)(SSObjectBase *); // rdx
  unsigned int (__fastcall *v11)(SSObjectBase *); // r8
  signed __int64 v12; // rdx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    v5 = 1;
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    vecDelDtor_low = LODWORD(vfptr->__vecDelDtor);
    i_user_data = i_data_p->i_user_data;
    if ( (_DWORD)vecDelDtor_low == *(_DWORD *)i_user_data )
    {
      v9 = *(unsigned int (__fastcall **)(SSObjectBase *))(i_user_data + 8);
      get_obj_type = vfptr->get_obj_type;
      v5 = 0;
      v11 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)v9 + 8 * vecDelDtor_low);
      if ( (unsigned __int64)v9 < (unsigned __int64)v11 )
      {
        v12 = (char *)get_obj_type - (char *)v9;
        while ( *(_QWORD *)((char *)v9 + v12) == *(_QWORD *)v9 )
        {
          v9 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)v9 + 8);
          if ( (unsigned __int64)v9 >= (unsigned __int64)v11 )
          {
            *result_pp = SSBoolean::pool_new(0);
            return;
          }
        }
        v5 = 1;
      }
    }
    *result_pp = SSBoolean::pool_new(v5);
  }
}

