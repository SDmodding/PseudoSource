// File Line: 72
// RVA: 0x10CEA0
void __fastcall SSList::append(SSList *this, SSInstance *instance, bool reference_b)
{
  bool v3; // bl
  SSInstance *v4; // rdi

  v3 = reference_b;
  v4 = instance;
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(&this->i_items, instance);
  if ( v3 )
    ++v4->i_ref_count;
}

// File Line: 93
// RVA: 0x13BBD0
void __fastcall SSList::remove(SSList *this, SSInstance *instance, bool dereference_b)
{
  unsigned int v3; // er10
  bool v4; // si
  SSInstance *v5; // rbx
  SSInstance **v6; // r11
  __int64 v7; // rdi
  unsigned __int64 v8; // rdx
  SSInstance **v9; // rax
  bool v10; // zf

  v3 = 0;
  v4 = dereference_b;
  v5 = instance;
  if ( this->i_items.i_count )
  {
    v6 = this->i_items.i_array_p;
    v7 = this->i_items.i_count - 1;
    v8 = (unsigned __int64)&v6[v7];
    v9 = this->i_items.i_array_p;
    if ( (unsigned __int64)v6 <= v8 )
    {
      do
      {
        if ( v5 == *v9 )
        {
          if ( v3 < 2 )
          {
            this->i_items.i_count = v7;
            memmove(
              &v6[(unsigned int)(v9 - v6)],
              &v6[(unsigned int)(v9 - v6) + 1],
              8i64 * ((unsigned int)v7 - (unsigned int)(v9 - v6)));
            break;
          }
          --v3;
        }
        ++v9;
      }
      while ( (unsigned __int64)v9 <= v8 );
    }
  }
  if ( v4 )
  {
    v10 = v5->i_ref_count-- == 1;
    if ( v10 )
    {
      v5->i_ref_count = 2147483648;
      v5->vfptr[1].get_scope_context((SSObjectBase *)&v5->vfptr);
    }
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
void __fastcall SSList::register_atomic(__int64 a1, signed __int64 a2, __int64 a3, __int64 a4)
{
  SSMethodBase **v4; // r8
  __int64 v5; // rax
  signed __int64 v6; // r10
  _BOOL8 v7; // rcx
  __int64 v8; // rdi
  __int64 v9; // r15
  SSParameters *v10; // rsi
  SSParameters *v11; // r14
  bool v12; // zf
  SSMethodBase **v13; // r8
  __int64 v14; // rax
  signed __int64 v15; // r10
  _BOOL8 v16; // rcx
  __int64 v17; // rdi
  __int64 v18; // r15
  SSParameters *v19; // rsi
  SSParameters *v20; // r14
  SSMethodBase **v21; // r8
  __int64 v22; // rax
  signed __int64 v23; // r10
  _BOOL8 v24; // rcx
  __int64 v25; // rdi
  __int64 v26; // r15
  SSParameters *v27; // rsi
  SSParameters *v28; // r14
  SSMethodBase **v29; // r8
  __int64 v30; // rax
  signed __int64 v31; // r10
  _BOOL8 v32; // rcx
  __int64 v33; // rdi
  __int64 v34; // r15
  SSParameters *v35; // rsi
  SSParameters *v36; // r14
  SSMethodBase **v37; // r8
  __int64 v38; // rax
  signed __int64 v39; // r10
  _BOOL8 v40; // rcx
  __int64 v41; // rdi
  __int64 v42; // r15
  SSParameters *v43; // rsi
  SSParameters *v44; // r14
  SSMethodBase **v45; // r8
  __int64 v46; // rax
  signed __int64 v47; // r10
  _BOOL8 v48; // rcx
  __int64 v49; // rdi
  __int64 v50; // r15
  SSParameters *v51; // rsi
  SSParameters *v52; // r14
  SSMethodBase **v53; // r8
  __int64 v54; // rax
  signed __int64 v55; // r10
  _BOOL8 v56; // rcx
  __int64 v57; // rdi
  __int64 v58; // r15
  SSParameters *v59; // rsi
  SSParameters *v60; // r14
  SSMethodBase **v61; // r8
  __int64 v62; // rax
  signed __int64 v63; // r10
  _BOOL8 v64; // rcx
  __int64 v65; // rdi
  __int64 v66; // r15
  SSParameters *v67; // rsi
  SSParameters *v68; // r14
  SSMethodBase **v69; // r8
  __int64 v70; // rax
  signed __int64 v71; // r10
  _BOOL8 v72; // rcx
  __int64 v73; // rdi
  __int64 v74; // r15
  SSParameters *v75; // rsi
  SSParameters *v76; // r14
  SSMethodBase **v77; // r8
  __int64 v78; // rax
  signed __int64 v79; // r10
  _BOOL8 v80; // rcx
  __int64 v81; // rdi
  __int64 v82; // r15
  SSParameters *v83; // rsi
  SSParameters *v84; // r14
  SSMethodBase **v85; // r8
  __int64 v86; // rax
  signed __int64 v87; // r10
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
  signed __int64 v119; // [rsp+20h] [rbp-10h]
  __int64 result; // [rsp+70h] [rbp+40h]
  SSParameters *v121; // [rsp+78h] [rbp+48h]
  __int64 v122; // [rsp+80h] [rbp+50h]

  v119 = -2i64;
  v4 = (SSMethodBase **)SSBrain::c_list_class_p;
  v5 = SSBrain::c_list_class_p->i_methods.i_count;
  if ( (_DWORD)v5 )
  {
    v4 = SSBrain::c_list_class_p->i_methods.i_array_p;
    v6 = (signed __int64)&v4[v5 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v4[(v6 - (signed __int64)v4) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbolX_ctor.i_uid < (unsigned int)a4 )
        goto LABEL_279;
      v7 = ASymbolX_ctor.i_uid == (_DWORD)a4;
      a4 = ASymbolX_ctor.i_uid != (_DWORD)a4;
      if ( v7 == 1 )
      {
        v8 = *(_QWORD *)a2;
        goto LABEL_12;
      }
      if ( a4 < 0 )
      {
LABEL_279:
        if ( v4 == (SSMethodBase **)a2 )
          break;
        v6 = a2 - 8;
      }
      else
      {
        if ( v6 == a2 )
          break;
        v4 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v8 = 0i64;
LABEL_12:
  result = v8;
  if ( v8 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v8 + 16i64))(
           v8,
           a2,
           v4,
           a4,
           -2i64) == 1 )
    {
      *(_QWORD *)(v8 + 32) = SSList::mthd_constructor;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      v121 = v10;
      if ( v10 )
        ++v10->i_ref_count;
      v11 = *(SSParameters **)(v8 + 24);
      if ( v11 )
      {
        v12 = v11->i_ref_count-- == 1;
        if ( v12 )
        {
          v11->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v11);
          AMemory::c_free_func(v11);
        }
        *(_QWORD *)(v8 + 24) = 0i64;
      }
      v122 = v8;
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
          v10->i_ref_count = 2147483648;
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
    v15 = (signed __int64)&v13[v14 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v13[(v15 - (signed __int64)v13) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbolX_ctor_copy.i_uid < (unsigned int)a4 )
        goto LABEL_280;
      v16 = ASymbolX_ctor_copy.i_uid == (_DWORD)a4;
      a4 = ASymbolX_ctor_copy.i_uid != (_DWORD)a4;
      if ( v16 == 1 )
      {
        v17 = *(_QWORD *)a2;
        goto LABEL_37;
      }
      if ( a4 < 0 )
      {
LABEL_280:
        if ( v13 == (SSMethodBase **)a2 )
          break;
        v15 = a2 - 8;
      }
      else
      {
        if ( v15 == a2 )
          break;
        v13 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v17 = 0i64;
LABEL_37:
  result = v17;
  if ( v17 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v17 + 16i64))(
           v17,
           a2,
           v13,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v17 + 32) = SSList::mthd_ctor_copy;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      v121 = v19;
      if ( v19 )
        ++v19->i_ref_count;
      v20 = *(SSParameters **)(v17 + 24);
      if ( v20 )
      {
        v12 = v20->i_ref_count-- == 1;
        if ( v12 )
        {
          v20->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v20);
          AMemory::c_free_func(v20);
        }
        *(_QWORD *)(v17 + 24) = 0i64;
      }
      v122 = v17;
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
          v19->i_ref_count = 2147483648;
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
    v23 = (signed __int64)&v21[v22 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v21[(v23 - (signed __int64)v21) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbolX_dtor.i_uid < (unsigned int)a4 )
        goto LABEL_281;
      v24 = ASymbolX_dtor.i_uid == (_DWORD)a4;
      a4 = ASymbolX_dtor.i_uid != (_DWORD)a4;
      if ( v24 == 1 )
      {
        v25 = *(_QWORD *)a2;
        goto LABEL_62;
      }
      if ( a4 < 0 )
      {
LABEL_281:
        if ( v21 == (SSMethodBase **)a2 )
          break;
        v23 = a2 - 8;
      }
      else
      {
        if ( v23 == a2 )
          break;
        v21 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v25 = 0i64;
LABEL_62:
  result = v25;
  if ( v25 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v25 + 16i64))(
           v25,
           a2,
           v21,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v25 + 32) = SSList::mthd_destructor;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v121 = v27;
      if ( v27 )
        ++v27->i_ref_count;
      v28 = *(SSParameters **)(v25 + 24);
      if ( v28 )
      {
        v12 = v28->i_ref_count-- == 1;
        if ( v12 )
        {
          v28->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v28);
          AMemory::c_free_func(v28);
        }
        *(_QWORD *)(v25 + 24) = 0i64;
      }
      v122 = v25;
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
          v27->i_ref_count = 2147483648;
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
    v31 = (signed __int64)&v29[v30 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v29[(v31 - (signed __int64)v29) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_as_copy.i_uid < (unsigned int)a4 )
        goto LABEL_282;
      v32 = ASymbol_as_copy.i_uid == (_DWORD)a4;
      a4 = ASymbol_as_copy.i_uid != (_DWORD)a4;
      if ( v32 == 1 )
      {
        v33 = *(_QWORD *)a2;
        goto LABEL_87;
      }
      if ( a4 < 0 )
      {
LABEL_282:
        if ( v29 == (SSMethodBase **)a2 )
          break;
        v31 = a2 - 8;
      }
      else
      {
        if ( v31 == a2 )
          break;
        v29 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v33 = 0i64;
LABEL_87:
  result = v33;
  if ( v33 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v33 + 16i64))(
           v33,
           a2,
           v29,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v33 + 32) = SSList::mthd_as_copy;
    }
    else
    {
      v34 = *(_QWORD *)(v33 + 16);
      v35 = *(SSParameters **)(v33 + 24);
      v121 = v35;
      if ( v35 )
        ++v35->i_ref_count;
      v36 = *(SSParameters **)(v33 + 24);
      if ( v36 )
      {
        v12 = v36->i_ref_count-- == 1;
        if ( v12 )
        {
          v36->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v36);
          AMemory::c_free_func(v36);
        }
        *(_QWORD *)(v33 + 24) = 0i64;
      }
      v122 = v33;
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
          v35->i_ref_count = 2147483648;
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
    v39 = (signed __int64)&v37[v38 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v37[(v39 - (signed __int64)v37) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_as_new.i_uid < (unsigned int)a4 )
        goto LABEL_283;
      v40 = ASymbol_as_new.i_uid == (_DWORD)a4;
      a4 = ASymbol_as_new.i_uid != (_DWORD)a4;
      if ( v40 == 1 )
      {
        v41 = *(_QWORD *)a2;
        goto LABEL_112;
      }
      if ( a4 < 0 )
      {
LABEL_283:
        if ( v37 == (SSMethodBase **)a2 )
          break;
        v39 = a2 - 8;
      }
      else
      {
        if ( v39 == a2 )
          break;
        v37 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v41 = 0i64;
LABEL_112:
  result = v41;
  if ( v41 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v41 + 16i64))(
           v41,
           a2,
           v37,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v41 + 32) = SSList::mthd_as_new;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      v121 = v43;
      if ( v43 )
        ++v43->i_ref_count;
      v44 = *(SSParameters **)(v41 + 24);
      if ( v44 )
      {
        v12 = v44->i_ref_count-- == 1;
        if ( v12 )
        {
          v44->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v44);
          AMemory::c_free_func(v44);
        }
        *(_QWORD *)(v41 + 24) = 0i64;
      }
      v122 = v41;
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
          v43->i_ref_count = 2147483648;
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
    v47 = (signed __int64)&v45[v46 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v45[(v47 - (signed __int64)v45) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_String.i_uid < (unsigned int)a4 )
        goto LABEL_284;
      v48 = ASymbol_String.i_uid == (_DWORD)a4;
      a4 = ASymbol_String.i_uid != (_DWORD)a4;
      if ( v48 == 1 )
      {
        v49 = *(_QWORD *)a2;
        goto LABEL_137;
      }
      if ( a4 < 0 )
      {
LABEL_284:
        if ( v45 == (SSMethodBase **)a2 )
          break;
        v47 = a2 - 8;
      }
      else
      {
        if ( v47 == a2 )
          break;
        v45 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v49 = 0i64;
LABEL_137:
  result = v49;
  if ( v49 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v49 + 16i64))(
           v49,
           a2,
           v45,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v49 + 32) = SSList::mthd_String;
    }
    else
    {
      v50 = *(_QWORD *)(v49 + 16);
      v51 = *(SSParameters **)(v49 + 24);
      v121 = v51;
      if ( v51 )
        ++v51->i_ref_count;
      v52 = *(SSParameters **)(v49 + 24);
      if ( v52 )
      {
        v12 = v52->i_ref_count-- == 1;
        if ( v12 )
        {
          v52->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v52);
          AMemory::c_free_func(v52);
        }
        *(_QWORD *)(v49 + 24) = 0i64;
      }
      v122 = v49;
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
          v51->i_ref_count = 2147483648;
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
    v55 = (signed __int64)&v53[v54 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v53[(v55 - (signed __int64)v53) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_equals_eqv.i_uid < (unsigned int)a4 )
        goto LABEL_285;
      v56 = ASymbol_equals_eqv.i_uid == (_DWORD)a4;
      a4 = ASymbol_equals_eqv.i_uid != (_DWORD)a4;
      if ( v56 == 1 )
      {
        v57 = *(_QWORD *)a2;
        goto LABEL_162;
      }
      if ( a4 < 0 )
      {
LABEL_285:
        if ( v53 == (SSMethodBase **)a2 )
          break;
        v55 = a2 - 8;
      }
      else
      {
        if ( v55 == a2 )
          break;
        v53 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v57 = 0i64;
LABEL_162:
  result = v57;
  if ( v57 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v57 + 16i64))(
           v57,
           a2,
           v53,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v57 + 32) = SSList::mthd_equals_eqv;
    }
    else
    {
      v58 = *(_QWORD *)(v57 + 16);
      v59 = *(SSParameters **)(v57 + 24);
      v121 = v59;
      if ( v59 )
        ++v59->i_ref_count;
      v60 = *(SSParameters **)(v57 + 24);
      if ( v60 )
      {
        v12 = v60->i_ref_count-- == 1;
        if ( v12 )
        {
          v60->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v60);
          AMemory::c_free_func(v60);
        }
        *(_QWORD *)(v57 + 24) = 0i64;
      }
      v122 = v57;
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
          v59->i_ref_count = 2147483648;
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
    v63 = (signed __int64)&v61[v62 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v61[(v63 - (signed __int64)v61) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_not_equal_eqv.i_uid < (unsigned int)a4 )
        goto LABEL_286;
      v64 = ASymbol_not_equal_eqv.i_uid == (_DWORD)a4;
      a4 = ASymbol_not_equal_eqv.i_uid != (_DWORD)a4;
      if ( v64 == 1 )
      {
        v65 = *(_QWORD *)a2;
        goto LABEL_187;
      }
      if ( a4 < 0 )
      {
LABEL_286:
        if ( v61 == (SSMethodBase **)a2 )
          break;
        v63 = a2 - 8;
      }
      else
      {
        if ( v63 == a2 )
          break;
        v61 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v65 = 0i64;
LABEL_187:
  result = v65;
  if ( v65 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v65 + 16i64))(
           v65,
           a2,
           v61,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v65 + 32) = SSList::mthd_not_equal_eqv;
    }
    else
    {
      v66 = *(_QWORD *)(v65 + 16);
      v67 = *(SSParameters **)(v65 + 24);
      v121 = v67;
      if ( v67 )
        ++v67->i_ref_count;
      v68 = *(SSParameters **)(v65 + 24);
      if ( v68 )
      {
        v12 = v68->i_ref_count-- == 1;
        if ( v12 )
        {
          v68->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v68);
          AMemory::c_free_func(v68);
        }
        *(_QWORD *)(v65 + 24) = 0i64;
      }
      v122 = v65;
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
          v67->i_ref_count = 2147483648;
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
    v71 = (signed __int64)&v69[v70 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v69[(v71 - (signed __int64)v69) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_add.i_uid < (unsigned int)a4 )
        goto LABEL_287;
      v72 = ASymbol_add.i_uid == (_DWORD)a4;
      a4 = ASymbol_add.i_uid != (_DWORD)a4;
      if ( v72 == 1 )
      {
        v73 = *(_QWORD *)a2;
        goto LABEL_212;
      }
      if ( a4 < 0 )
      {
LABEL_287:
        if ( v69 == (SSMethodBase **)a2 )
          break;
        v71 = a2 - 8;
      }
      else
      {
        if ( v71 == a2 )
          break;
        v69 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v73 = 0i64;
LABEL_212:
  result = v73;
  if ( v73 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v73 + 16i64))(
           v73,
           a2,
           v69,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v73 + 32) = SSList::mthd_op_add;
    }
    else
    {
      v74 = *(_QWORD *)(v73 + 16);
      v75 = *(SSParameters **)(v73 + 24);
      v121 = v75;
      if ( v75 )
        ++v75->i_ref_count;
      v76 = *(SSParameters **)(v73 + 24);
      if ( v76 )
      {
        v12 = v76->i_ref_count-- == 1;
        if ( v12 )
        {
          v76->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v76);
          AMemory::c_free_func(v76);
        }
        *(_QWORD *)(v73 + 24) = 0i64;
      }
      v122 = v73;
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
          v75->i_ref_count = 2147483648;
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
    v79 = (signed __int64)&v77[v78 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v77[(v79 - (signed __int64)v77) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_add_assign.i_uid < (unsigned int)a4 )
        goto LABEL_288;
      v80 = ASymbol_add_assign.i_uid == (_DWORD)a4;
      a4 = ASymbol_add_assign.i_uid != (_DWORD)a4;
      if ( v80 == 1 )
      {
        v81 = *(_QWORD *)a2;
        goto LABEL_237;
      }
      if ( a4 < 0 )
      {
LABEL_288:
        if ( v77 == (SSMethodBase **)a2 )
          break;
        v79 = a2 - 8;
      }
      else
      {
        if ( v79 == a2 )
          break;
        v77 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v81 = 0i64;
LABEL_237:
  result = v81;
  if ( v81 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v81 + 16i64))(
           v81,
           a2,
           v77,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v81 + 32) = SSList::mthd_op_add_assign;
    }
    else
    {
      v82 = *(_QWORD *)(v81 + 16);
      v83 = *(SSParameters **)(v81 + 24);
      v121 = v83;
      if ( v83 )
        ++v83->i_ref_count;
      v84 = *(SSParameters **)(v81 + 24);
      if ( v84 )
      {
        v12 = v84->i_ref_count-- == 1;
        if ( v12 )
        {
          v84->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v84);
          AMemory::c_free_func(v84);
        }
        *(_QWORD *)(v81 + 24) = 0i64;
      }
      v122 = v81;
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
          v83->i_ref_count = 2147483648;
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
    v87 = (signed __int64)&v85[v86 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v85[(v87 - (signed __int64)v85) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_assign.i_uid < (unsigned int)a4 )
        goto LABEL_289;
      v88 = ASymbol_assign.i_uid == (_DWORD)a4;
      a4 = ASymbol_assign.i_uid != (_DWORD)a4;
      if ( v88 == 1 )
      {
        v89 = *(_QWORD *)a2;
        goto LABEL_262;
      }
      if ( a4 < 0 )
      {
LABEL_289:
        if ( v85 == (SSMethodBase **)a2 )
          break;
        v87 = a2 - 8;
      }
      else
      {
        if ( v87 == a2 )
          break;
        v85 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v89 = 0i64;
LABEL_262:
  result = v89;
  if ( v89 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v89 + 16i64))(
           v89,
           a2,
           v85,
           a4,
           v119) == 1 )
    {
      *(_QWORD *)(v89 + 32) = SSList::mthd_op_assign;
    }
    else
    {
      v90 = *(_QWORD *)(v89 + 16);
      v91 = *(SSParameters **)(v89 + 24);
      v121 = v91;
      if ( v91 )
        ++v91->i_ref_count;
      v92 = *(SSParameters **)(v89 + 24);
      if ( v92 )
      {
        v12 = v92->i_ref_count-- == 1;
        if ( v12 )
        {
          v92->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v92);
          AMemory::c_free_func(v92);
        }
        *(_QWORD *)(v89 + 24) = 0i64;
      }
      v122 = v89;
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
          v91->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v91);
          AMemory::c_free_func(v91);
        }
      }
    }
  }
  v93 = SSBrain::c_list_class_p;
  v94 = ASymbol::create((ASymbol *)&result, "assign_group", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v93, v94, SSList::mthd_op_assign, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_get_count, SSList::mthd_get_count, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_get_count_after, SSList::mthd_get_count_after, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_is_empty, SSList::mthd_is_empty, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_is_filled, SSList::mthd_is_filled, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_get_at, SSList::mthd_get_at, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_get_first, SSList::mthd_get_first, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_get_last, SSList::mthd_get_last, 0);
  v95 = SSBrain::c_list_class_p;
  v96 = ASymbol::create((ASymbol *)&result, "get_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v95, v96, SSList::mthd_get_list_eqv, 0);
  v97 = SSBrain::c_list_class_p;
  v98 = ASymbol::create((ASymbol *)&result, "get_list_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v97, v98, SSList::mthd_get_list_eqv, 0);
  v99 = SSBrain::c_list_class_p;
  v100 = ASymbol::create((ASymbol *)&result, "intersection_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v99, v100, SSList::mthd_get_list_eqv, 0);
  v101 = SSBrain::c_list_class_p;
  v102 = ASymbol::create((ASymbol *)&result, "intersection_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v101, v102, SSList::mthd_get_list_eqv, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_get_range, SSList::mthd_get_range, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_reverse, SSList::mthd_reverse, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_rotate_down, SSList::mthd_rotate_down, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_rotate_up, SSList::mthd_rotate_up, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_swap, SSList::mthd_swap, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_append, SSList::mthd_append, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_append_absent_eqv, SSList::mthd_append_absent_eqv, 0);
  v103 = SSBrain::c_list_class_p;
  v104 = ASymbol::create((ASymbol *)&result, "append_absent_list_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v103, v104, SSList::mthd_append_absent_list_eqv, 0);
  v105 = SSBrain::c_list_class_p;
  v106 = ASymbol::create((ASymbol *)&result, "append_absent_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v105, v106, SSList::mthd_append_absent_list_eqv, 0);
  v107 = SSBrain::c_list_class_p;
  v108 = ASymbol::create((ASymbol *)&result, "union_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v107, v108, SSList::mthd_append_absent_list_eqv, 0);
  v109 = SSBrain::c_list_class_p;
  v110 = ASymbol::create((ASymbol *)&result, "union_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v109, v110, SSList::mthd_append_absent_list_eqv, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_append_items, SSList::mthd_append_items, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_append_list, SSList::mthd_op_add_assign, 0);
  v111 = SSBrain::c_list_class_p;
  v112 = ASymbol::create((ASymbol *)&result, "append_group", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v111, v112, SSList::mthd_op_add_assign, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_insert, SSList::mthd_insert, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_insert_items, SSList::mthd_insert_items, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_insert_list, SSList::mthd_insert_list, 0);
  v113 = SSBrain::c_list_class_p;
  v114 = ASymbol::create((ASymbol *)&result, "insert_group", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v113, v114, SSList::mthd_insert_list, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_set_at, SSList::mthd_set_at, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_set_items, SSList::mthd_set_items, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_crop, SSList::mthd_crop, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_empty, SSList::mthd_empty, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_pop_at, SSList::mthd_pop_at, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_pop_first, SSList::mthd_pop_first, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_pop_last, SSList::mthd_pop_last, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_pop_range, SSList::mthd_pop_range, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_pop_range_last, SSList::mthd_pop_range_last, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_remove_at, SSList::mthd_remove_at, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_remove_eqv, SSList::mthd_remove_eqv, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_remove_first, SSList::mthd_remove_first, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_remove_last, SSList::mthd_remove_last, 0);
  v115 = SSBrain::c_list_class_p;
  v116 = ASymbol::create((ASymbol *)&result, "remove_list_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v115, v116, SSList::mthd_remove_list_eqv, 0);
  v117 = SSBrain::c_list_class_p;
  v118 = ASymbol::create((ASymbol *)&result, "remove_group_eqv", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v117, v118, SSList::mthd_remove_list_eqv, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_remove_range, SSList::mthd_remove_range, 0);
  SSClass::register_method_func(SSBrain::c_list_class_p, &ASymbol_remove_range_last, SSList::mthd_remove_range_last, 0);
}List::mthd_remove_range_last, 0);
}

// File Line: 332
// RVA: 0x121C00
void __fastcall SSList::mthd_constructor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSObjectBaseVtbl *v3; // rax
  SSObjectBaseVtbl *v4; // rbx

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
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
    v2[2].vfptr = v4;
  }
}

// File Line: 349
// RVA: 0x121E10
void __fastcall SSList::mthd_ctor_copy(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // rsi
  SSObjectBase *v3; // rbx
  APSizedArrayBase<SSInstance> *v4; // rax
  APSizedArrayBase<SSInstance> *v5; // rdi
  unsigned int *v6; // r14
  __int64 v7; // rax
  ARefCountMix<SSInstance> **v8; // rbx
  unsigned __int64 i; // rsi
  unsigned int v10; // ebx

  v2 = scope_p;
  v3 = scope_p->i_scope_p.i_obj_p;
  if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( result_pp )
  {
    v5 = (APSizedArrayBase<SSInstance> *)v3[2].vfptr;
  }
  else
  {
    v4 = (APSizedArrayBase<SSInstance> *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v5 = v4;
    if ( v4 )
    {
      v4->i_count = 0;
      v4->i_array_p = 0i64;
      v4->i_size = 0;
      v4->i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v5 = 0i64;
    }
    v3[2].vfptr = (SSObjectBaseVtbl *)v5;
  }
  v6 = (unsigned int *)(*v2->i_data.i_array_p)->i_data_p->i_user_data;
  v7 = *v6;
  if ( (_DWORD)v7 )
  {
    v8 = (ARefCountMix<SSInstance> **)*((_QWORD *)v6 + 1);
    for ( i = (unsigned __int64)&v8[v7]; (unsigned __int64)v8 < i; ++v8 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v8 + 4);
  }
  v10 = *v6;
  APSizedArrayBase<SSInstance>::ensure_size(v5, *v6 + v5->i_count);
  memmove(&v5->i_array_p[v5->i_count], *((const void **)v6 + 1), 8i64 * v10);
  v5->i_count += v10;
}

// File Line: 380
// RVA: 0x122040
void __fastcall SSList::mthd_destructor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  void **v3; // rdi
  __int64 v4; // rax
  ARefCountMix<SSInstance> **v5; // rbx
  unsigned __int64 i; // rsi

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (void **)&v2[2].vfptr->__vecDelDtor;
  if ( v3 )
  {
    v4 = *(unsigned int *)v3;
    if ( (_DWORD)v4 )
    {
      v5 = (ARefCountMix<SSInstance> **)v3[1];
      for ( i = (unsigned __int64)&v5[v4]; (unsigned __int64)v5 < i; ++v5 )
        ARefCountMix<SSInstance>::dereference(*v5 + 4);
    }
    AMemory::c_free_func(v3[1]);
    AMemory::c_free_func(v3);
  }
}

// File Line: 390
// RVA: 0x120D70
void __fastcall SSList::mthd_as_copy(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r14
  SSObjectBase *v3; // rbp
  SSObjectBaseVtbl *v4; // rsi
  APSizedArrayBase<SSInstance> *v5; // rax
  APSizedArrayBase<SSInstance> *v6; // rdi
  unsigned int v7; // ecx
  SSInstance **v8; // rax
  unsigned int v9; // ebx
  bool v10; // zf
  ARefCountMix<SSInstance> **v11; // rbx
  unsigned __int64 i; // rsi

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    v5 = (APSizedArrayBase<SSInstance> *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v6 = v5;
    if ( v5 )
    {
      v7 = (unsigned int)v4->__vecDelDtor;
      v5->i_count = 0;
      v5->i_array_p = 0i64;
      v5->i_size = 0;
      if ( v7 )
      {
        v5->i_size = v7;
        v8 = APArrayBase<SSInstance>::alloc_array(v7);
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
    v9 = (unsigned int)v4->__vecDelDtor;
    APSizedArrayBase<SSInstance>::ensure_size(v6, LODWORD(v4->__vecDelDtor) + v6->i_count);
    memmove(&v6->i_array_p[v6->i_count], v4->get_obj_type, 8i64 * v9);
    v10 = v9 + v6->i_count == 0;
    v6->i_count += v9;
    if ( !v10 )
    {
      v11 = (ARefCountMix<SSInstance> **)v6->i_array_p;
      for ( i = (unsigned __int64)&v11[v6->i_count]; (unsigned __int64)v11 < i; ++v11 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v11 + 4);
    }
    *v2 = SSInstance::pool_new(*(SSClass **)&v3[1].i_ptr_id, (unsigned __int64)v6);
  }
}

// File Line: 411
// RVA: 0x120F20
void __fastcall SSList::mthd_as_new(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r14
  SSInvokedMethod *v3; // rsi
  _QWORD *v4; // rax
  unsigned __int64 v5; // rbx
  SSObjectBase *v6; // rcx

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p;
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
    v6 = v3->i_scope_p.i_obj_p;
    if ( !v6 || v3->i_scope_p.i_ptr_id != v6->i_ptr_id )
      v6 = 0i64;
    *v2 = SSInstance::pool_new(*(SSClass **)&v6[1].i_ptr_id, v5);
  }
}

// File Line: 427
// RVA: 0x120510
void __fastcall SSList::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r15
  SSInvokedMethod *v3; // rdi
  SSObjectBase *v4; // r8
  SSObjectBaseVtbl *v5; // r14
  __int64 v6; // rsi
  AStringRef *v7; // rax
  AStringRef *v8; // rax
  __int64 v9; // rbx
  unsigned int (__fastcall *v10)(SSObjectBase *); // rbx
  unsigned __int64 v11; // rsi
  AStringRef *v12; // rax
  __int64 v13; // rbx
  AString *v14; // rax
  AStringRef *v15; // rbx
  bool v16; // zf
  AObjReusePool<AStringRef> *v17; // rax
  AObjBlock<AStringRef> *v18; // rcx
  unsigned __int64 v19; // rdx
  bool v20; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v21; // rcx
  signed __int64 v22; // [rsp+20h] [rbp-38h]
  AString v23; // [rsp+68h] [rbp+10h]
  AString *v24; // [rsp+70h] [rbp+18h]
  AString *v25; // [rsp+78h] [rbp+20h]

  if ( result_pp )
  {
    v22 = -2i64;
    v2 = result_pp;
    v3 = scope_p;
    v23.i_str_ref_p = AStringRef::get_empty();
    ++v23.i_str_ref_p->i_ref_count;
    v4 = v3->i_scope_p.i_obj_p;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v5 = v4[2].vfptr;
    v6 = LODWORD(v5->__vecDelDtor);
    if ( (_DWORD)v6 )
    {
      v7 = v23.i_str_ref_p;
      if ( (unsigned int)(8 * v6) >= v23.i_str_ref_p->i_size
        || v23.i_str_ref_p->i_ref_count + v23.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size_buffer(&v23, 8 * v6);
        v7 = v23.i_str_ref_p;
      }
      v7->i_length = 0;
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
      v10 = v5->get_obj_type;
      v11 = (unsigned __int64)v10 + 8 * v6;
      if ( (unsigned __int64)v10 < v11 )
      {
        while ( 1 )
        {
          (*(void (__fastcall **)(_QWORD, AString *, _QWORD, SSInvokedMethod *, signed __int64))(**(_QWORD **)v10 + 88i64))(
            *(_QWORD *)v10,
            &v23,
            0i64,
            v3,
            v22);
          v10 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)v10 + 8);
          if ( (unsigned __int64)v10 >= v11 )
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
    v14 = (AString *)SSInstance::pool_new(SSBrain::c_string_class_p);
    v24 = v14;
    v25 = v14 + 4;
    if ( v14 != (AString *)-32i64 )
    {
      v14[4].i_str_ref_p = v23.i_str_ref_p;
      ++v23.i_str_ref_p->i_ref_count;
    }
    *v2 = (SSInstance *)v14;
    v15 = v23.i_str_ref_p;
    v16 = v23.i_str_ref_p->i_ref_count == 1;
    --v15->i_ref_count;
    if ( v16 )
    {
      if ( v15->i_deallocate )
        AMemory::c_free_func(v15->i_cstr_p);
      v17 = AStringRef::get_pool();
      v18 = v17->i_block_p;
      v19 = (unsigned __int64)v18->i_objects_a;
      if ( (unsigned __int64)v15 < v19
        || (v20 = (unsigned __int64)v15 < v19 + 24i64 * v18->i_size, v21 = &v17->i_pool, !v20) )
      {
        v21 = &v17->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v21, v15);
    }
  }
}

// File Line: 479
// RVA: 0x123320
void __fastcall SSList::mthd_op_add(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r14
  SSInvokedMethod *v3; // rdi
  SSObjectBase *v4; // rbp
  SSObjectBaseVtbl *v5; // r15
  APSizedArrayBase<SSInstance> *v6; // rax
  APSizedArrayBase<SSInstance> *v7; // rsi
  int v8; // ecx
  unsigned int v9; // ecx
  SSInstance **v10; // rax
  unsigned int v11; // ebx
  unsigned __int64 v12; // rbx
  unsigned int v13; // edi
  bool v14; // zf
  ARefCountMix<SSInstance> **v15; // rbx
  unsigned __int64 i; // rdi

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p;
    v4 = scope_p->i_scope_p.i_obj_p;
    if ( !v4 || scope_p->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v5 = v4[2].vfptr;
    v6 = (APSizedArrayBase<SSInstance> *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v7 = v6;
    if ( v6 )
    {
      v8 = (int)v5->__vecDelDtor;
      v6->i_count = 0;
      v6->i_array_p = 0i64;
      v6->i_size = 0;
      v9 = v8 + 1;
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
    v11 = (unsigned int)v5->__vecDelDtor;
    APSizedArrayBase<SSInstance>::ensure_size(v7, LODWORD(v5->__vecDelDtor) + v7->i_count);
    memmove(&v7->i_array_p[v7->i_count], v5->get_obj_type, 8i64 * v11);
    v7->i_count += v11;
    v12 = (*v3->i_data.i_array_p)->i_data_p->i_user_data;
    v13 = *(_DWORD *)v12;
    APSizedArrayBase<SSInstance>::ensure_size(v7, *(_DWORD *)v12 + v7->i_count);
    memmove(&v7->i_array_p[v7->i_count], *(const void **)(v12 + 8), 8i64 * v13);
    v14 = v13 + v7->i_count == 0;
    v7->i_count += v13;
    if ( !v14 )
    {
      v15 = (ARefCountMix<SSInstance> **)v7->i_array_p;
      for ( i = (unsigned __int64)&v15[v7->i_count]; (unsigned __int64)v15 < i; ++v15 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v15 + 4);
    }
    *v2 = SSInstance::pool_new(*(SSClass **)&v4[1].i_ptr_id, (unsigned __int64)v7);
  }
}

// File Line: 522
// RVA: 0x1237B0
void __fastcall SSList::mthd_op_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // r15
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v4; // r14
  APArrayBase<SSInstance> *v5; // rbp
  __int64 v6; // rax
  ARefCountMix<SSInstance> **v7; // rbx
  unsigned __int64 i; // rsi
  __int64 v9; // rax
  ARefCountMix<SSInstance> **v10; // rbx
  unsigned __int64 j; // rsi

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)v2[2].vfptr;
  v5 = (APArrayBase<SSInstance> *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = v5->i_count;
  if ( (_DWORD)v6 )
  {
    v7 = (ARefCountMix<SSInstance> **)v5->i_array_p;
    for ( i = (unsigned __int64)&v7[v6]; (unsigned __int64)v7 < i; ++v7 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v7 + 4);
  }
  v9 = v4->i_count;
  if ( (_DWORD)v9 )
  {
    v10 = (ARefCountMix<SSInstance> **)v4->i_array_p;
    for ( j = (unsigned __int64)&v10[v9]; (unsigned __int64)v10 < j; ++v10 )
      ARefCountMix<SSInstance>::dereference(*v10 + 4);
  }
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::operator=(v4, v5);
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 544
// RVA: 0x122580
void __fastcall SSList::mthd_get_count(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned __int64)v2[2].vfptr->__vecDelDtor);
  }
}

// File Line: 560
// RVA: 0x1225C0
void __fastcall SSList::mthd_get_count_after(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   (unsigned int)((char *)v2[2].vfptr->__vecDelDtor
                                - LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data)));
  }
}

// File Line: 581
// RVA: 0x122D00
void __fastcall SSList::mthd_is_empty(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v2[2].vfptr->__vecDelDtor == 0);
  }
}

// File Line: 597
// RVA: 0x122D80
void __fastcall SSList::mthd_is_filled(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v2[2].vfptr->__vecDelDtor != 0);
  }
}

// File Line: 613
// RVA: 0x122520
void __fastcall SSList::mthd_get_at(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r9
  SSObjectBase *v3; // r8
  SSObjectBaseVtbl *v4; // rdx
  __int64 v5; // rcx
  SSInstance *v6; // rdx

  v2 = result_pp;
  if ( result_pp )
  {
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    v5 = LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    if ( (signed int)v5 >= SLODWORD(v4->__vecDelDtor) || (signed int)v5 < 0 )
    {
      *v2 = SSBrain::c_nil_p;
    }
    else
    {
      v6 = (SSInstance *)*((_QWORD *)v4->get_obj_type + v5);
      *v2 = v6;
      ++v6->i_ref_count;
    }
  }
}

// File Line: 641
// RVA: 0x1226B0
void __fastcall SSList::mthd_get_first(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r9
  SSInstance *v3; // r8
  SSObjectBaseVtbl *v4; // rax

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    v3 = 0i64;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    if ( LODWORD(v4->__vecDelDtor) )
      v3 = *(SSInstance **)v4->get_obj_type;
    *result_pp = v3;
    ++v3->i_ref_count;
  }
}

// File Line: 659
// RVA: 0x1226F0
void __fastcall SSList::mthd_get_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r9
  SSInstance *v3; // r8
  SSObjectBaseVtbl *v4; // r10

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    v3 = 0i64;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    if ( LODWORD(v4->__vecDelDtor) )
      v3 = (SSInstance *)*((_QWORD *)v4->get_obj_type + (unsigned int)(LODWORD(v4->__vecDelDtor) - 1));
    *result_pp = v3;
    ++v3->i_ref_count;
  }
}

// File Line: 677
// RVA: 0x122730
void __fastcall SSList::mthd_get_list_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r12
  SSObjectBase *v3; // r15
  SSObjectBaseVtbl *v4; // r14
  unsigned int *v5; // rdi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v6; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rsi
  __int64 v8; // rax
  SSInstance **v9; // rdi
  unsigned __int64 i; // rbp
  SSInstance *v11; // rbx
  SSInstance **v12; // rax
  unsigned __int64 v13; // rdx

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    v5 = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
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
    v8 = *v5;
    if ( (_DWORD)v8 )
    {
      if ( LODWORD(v4->__vecDelDtor) )
      {
        v9 = (SSInstance **)*((_QWORD *)v5 + 1);
        for ( i = (unsigned __int64)&v9[v8]; (unsigned __int64)v9 < i; ++v9 )
        {
          v11 = *v9;
          if ( LODWORD(v4->__vecDelDtor) )
          {
            v12 = (SSInstance **)v4->get_obj_type;
            v13 = (unsigned __int64)&v12[LODWORD(v4->__vecDelDtor) - 1];
            if ( (unsigned __int64)v12 <= v13 )
            {
              while ( v11 != *v12 )
              {
                ++v12;
                if ( (unsigned __int64)v12 > v13 )
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
    *v2 = SSInstance::pool_new(*(SSClass **)&v3[1].i_ptr_id, (unsigned __int64)v7);
  }
}

// File Line: 717
// RVA: 0x122930
void __fastcall SSList::mthd_get_range(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r14
  SSData **v3; // r9
  unsigned int v4; // er15
  unsigned int v5; // ebx
  SSObjectBase *v6; // rbp
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rsi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v8; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v9; // rdi
  SSInstance **v10; // rax
  __int64 v11; // rax
  ARefCountMix<SSInstance> **v12; // rbx
  unsigned __int64 i; // rsi

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_data.i_array_p;
    v4 = (*v3)->i_data_p->i_user_data;
    v5 = v3[1]->i_data_p->i_user_data;
    v6 = scope_p->i_scope_p.i_obj_p;
    if ( !v6 || scope_p->i_scope_p.i_ptr_id != v6->i_ptr_id )
      v6 = 0i64;
    v7 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)v6[2].vfptr;
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
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append_all(v9, v7, v4, v5);
    v11 = v9->i_count;
    if ( (_DWORD)v11 )
    {
      v12 = (ARefCountMix<SSInstance> **)v9->i_array_p;
      for ( i = (unsigned __int64)&v12[v11]; (unsigned __int64)v12 < i; ++v12 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v12 + 4);
    }
    *v2 = SSInstance::pool_new(*(SSClass **)&v6[1].i_ptr_id, (unsigned __int64)v9);
  }
}

// File Line: 740
// RVA: 0x125480
void __fastcall SSList::mthd_reverse(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r9
  SSInstance **v3; // r10
  SSData **v4; // rdx
  SSInstance *v5; // rcx
  SSData *v6; // rax
  SSObjectBaseVtbl *v7; // rdx
  __int64 v8; // r8
  __int64 v9; // rax
  __int64 *v10; // rax
  __int64 *i; // r8
  __int64 v12; // rcx
  __int64 v13; // rdx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = v4[1]->i_data_p;
  v6 = *v4;
  v7 = v2[2].vfptr;
  v8 = LODWORD(v5->i_user_data);
  v9 = LODWORD(v6->i_data_p->i_user_data);
  if ( (_DWORD)v8 == -1 )
    v8 = (unsigned int)(LODWORD(v7->__vecDelDtor) - v9);
  if ( (_DWORD)v8 )
  {
    v10 = (__int64 *)((char *)v7->get_obj_type + 8 * v9);
    for ( i = &v10[v8 - 1]; v10 < i; ++v10 )
    {
      v12 = *i;
      v13 = *v10;
      --i;
      *v10 = v12;
      i[1] = v13;
    }
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 761
// RVA: 0x125510
void __fastcall SSList::mthd_rotate_down(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // r14
  unsigned int (__fastcall *v5)(SSObjectBase *); // rcx
  __int64 v6; // rbx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  if ( LODWORD(v4->__vecDelDtor) > 1 )
  {
    v5 = v4->get_obj_type;
    v6 = *(_QWORD *)v5;
    memmove(v5, (char *)v5 + 8, 8i64 * (unsigned int)(LODWORD(v4->__vecDelDtor) - 1));
    *((_QWORD *)v4->get_obj_type + (unsigned int)(LODWORD(v4->__vecDelDtor) - 1)) = v6;
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 780
// RVA: 0x125590
void __fastcall SSList::mthd_rotate_up(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // r14
  unsigned int (__fastcall *v5)(SSObjectBase *); // rdx
  unsigned int v6; // eax
  __int64 v7; // rbx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  if ( LODWORD(v4->__vecDelDtor) > 1 )
  {
    v5 = v4->get_obj_type;
    v6 = LODWORD(v4->__vecDelDtor) - 1;
    v7 = *((_QWORD *)v5 + v6);
    memmove((char *)v5 + 8, v5, 8i64 * v6);
    *(_QWORD *)v4->get_obj_type = v7;
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 799
// RVA: 0x1259B0
void __fastcall SSList::mthd_swap(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r10
  SSInstance **v3; // r11
  SSData **v4; // rdx
  unsigned int (__fastcall *v5)(SSObjectBase *); // r8
  _DWORD *v6; // r9
  _DWORD *v7; // rcx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = v2[2].vfptr->get_obj_type;
  v6 = (_DWORD *)((char *)v5 + 8 * LODWORD((*v4)->i_data_p->i_user_data));
  v7 = (_DWORD *)((char *)v5 + 8 * LODWORD(v4[1]->i_data_p->i_user_data));
  *v6 ^= *v7;
  *v7 ^= *v6;
  *v6 ^= *v7;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 820
// RVA: 0x120950
void __fastcall SSList::mthd_append(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSData **v4; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v5; // rcx
  SSInstance *v6; // rdx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)v2[2].vfptr;
  v6 = (*v4)->i_data_p;
  ++v6->i_ref_count;
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(v5, v6);
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 841
// RVA: 0x120A20
void __fastcall SSList::mthd_append_absent_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r9
  unsigned int v3; // er8
  SSInstance **v4; // rdi
  SSObjectBaseVtbl *v5; // r10
  SSInstance *v6; // rbx
  SSInstance **v7; // rcx
  unsigned __int64 v8; // rdx
  bool v9; // cl

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = 0;
  v4 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v5 = v2[2].vfptr;
  v6 = (*scope_p->i_data.i_array_p)->i_data_p;
  if ( !LODWORD(v5->__vecDelDtor)
    || (v7 = (SSInstance **)v5->get_obj_type,
        v8 = (unsigned __int64)&v7[LODWORD(v5->__vecDelDtor) - 1],
        (unsigned __int64)v7 > v8) )
  {
LABEL_10:
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(
      (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)v2[2].vfptr,
      v6);
    ++v6->i_ref_count;
    v9 = 1;
    goto LABEL_11;
  }
  while ( v6 != *v7 )
  {
LABEL_9:
    ++v7;
    if ( (unsigned __int64)v7 > v8 )
      goto LABEL_10;
  }
  if ( v3 >= 2 )
  {
    --v3;
    goto LABEL_9;
  }
  v9 = 0;
LABEL_11:
  if ( v4 )
    *v4 = (SSInstance *)SSBoolean::pool_new(v9);
}

// File Line: 863
// RVA: 0x120AC0
void __fastcall SSList::mthd_append_absent_list_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rsi
  SSInstance **v3; // r14
  unsigned int *v4; // rbx
  __int64 v5; // rax
  SSInstance **v6; // rbx
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rdi
  unsigned __int64 i; // rbp
  SSInstance *v9; // rdx
  unsigned int v10; // er8
  SSInstance **v11; // rax
  unsigned __int64 j; // r9

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = *v4;
  if ( (_DWORD)v5 )
  {
    v6 = (SSInstance **)*((_QWORD *)v4 + 1);
    v7 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)v2[2].vfptr;
    for ( i = (unsigned __int64)&v6[v5]; (unsigned __int64)v6 < i; ++v6 )
    {
      v9 = *v6;
      v10 = 0;
      if ( v7->i_count )
      {
        v11 = v7->i_array_p;
        for ( j = (unsigned __int64)&v11[v7->i_count - 1]; (unsigned __int64)v11 <= j; ++v11 )
        {
          if ( v9 == *v11 )
          {
            if ( v10 < 2 )
              goto LABEL_13;
            --v10;
          }
        }
      }
      APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(v7, v9);
      ++(*v6)->i_ref_count;
LABEL_13:
      ;
    }
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 898
// RVA: 0x120BA0
void __fastcall SSList::mthd_append_items(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // r15
  SSData **v4; // rdx
  APSizedArrayBase<SSInstance> *v5; // rsi
  __int64 v6; // r14
  unsigned __int64 v7; // rbp
  SSInstance **v8; // rdi

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = (APSizedArrayBase<SSInstance> *)v2[2].vfptr;
  v6 = LODWORD(v4[1]->i_data_p->i_user_data);
  if ( (_DWORD)v6 )
  {
    v7 = (unsigned __int64)(*v4)->i_data_p;
    *(_DWORD *)(v7 + 16) += v6;
    APSizedArrayBase<SSInstance>::ensure_size(v5, v6 + v5->i_count);
    v8 = &v5->i_array_p[v5->i_count];
    if ( v8 < &v8[v6] )
      memset64(v8, v7, ((unsigned __int64)(8 * v6 - 1) >> 3) + 1);
    v5->i_count += v6;
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 924
// RVA: 0x120C60
void __fastcall SSList::mthd_op_add_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // rbp
  APSizedArrayBase<SSInstance> *v4; // r15
  unsigned int *v5; // r14
  __int64 v6; // rax
  ARefCountMix<SSInstance> **v7; // rbx
  unsigned __int64 i; // rsi
  unsigned int v9; // ebx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (APSizedArrayBase<SSInstance> *)v2[2].vfptr;
  v5 = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = *v5;
  if ( (_DWORD)v6 )
  {
    v7 = (ARefCountMix<SSInstance> **)*((_QWORD *)v5 + 1);
    for ( i = (unsigned __int64)&v7[v6]; (unsigned __int64)v7 < i; ++v7 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v7 + 4);
  }
  v9 = *v5;
  APSizedArrayBase<SSInstance>::ensure_size(v4, *v5 + v4->i_count);
  memmove(&v4->i_array_p[v4->i_count], *((const void **)v5 + 1), 8i64 * v9);
  v4->i_count += v9;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 945
// RVA: 0x122AB0
void __fastcall SSList::mthd_insert(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSData **v4; // r8
  APSizedArrayBase<SSInstance> *v5; // rcx
  SSInstance *v6; // rdx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = (APSizedArrayBase<SSInstance> *)v2[2].vfptr;
  v6 = (*v4)->i_data_p;
  LODWORD(v4) = v4[1]->i_data_p->i_user_data;
  ++v6->i_ref_count;
  APSizedArrayBase<SSInstance>::insert(v5, v6, (unsigned int)v4);
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 967
// RVA: 0x122B10
void __fastcall SSList::mthd_insert_items(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSData **v4; // r8
  unsigned int v5; // er9
  APSizedArrayBase<SSInstance> *v6; // rcx
  SSInstance *v7; // rdx
  unsigned int v8; // er8

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = v4[2]->i_data_p->i_user_data;
  if ( v5 )
  {
    v6 = (APSizedArrayBase<SSInstance> *)v2[2].vfptr;
    v7 = (*v4)->i_data_p;
    v8 = v4[1]->i_data_p->i_user_data;
    v7->i_ref_count += v5;
    APSizedArrayBase<SSInstance>::insert(v6, v7, v8, v5);
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 994
// RVA: 0x122B80
void __fastcall SSList::mthd_insert_list(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // r14
  SSData **v4; // rdx
  APSizedArrayBase<SSInstance> *v5; // rbp
  APArrayBase<SSInstance> *v6; // r15
  __int64 v7; // rax
  unsigned int v8; // er12
  ARefCountMix<SSInstance> **v9; // rbx
  unsigned __int64 i; // rsi

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = (APSizedArrayBase<SSInstance> *)v2[2].vfptr;
  v6 = (APArrayBase<SSInstance> *)(*v4)->i_data_p->i_user_data;
  v7 = v6->i_count;
  v8 = v4[1]->i_data_p->i_user_data;
  if ( (_DWORD)v7 )
  {
    v9 = (ARefCountMix<SSInstance> **)v6->i_array_p;
    for ( i = (unsigned __int64)&v9[v7]; (unsigned __int64)v9 < i; ++v9 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v9 + 4);
  }
  APSizedArrayBase<SSInstance>::insert_all(v5, v6, v8);
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1016
// RVA: 0x125610
void __fastcall SSList::mthd_set_at(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSData **v4; // rdx
  SSObjectBaseVtbl *v5; // rbp
  SSInstance *v6; // rsi
  signed __int64 v7; // r14
  _DWORD *v8; // rcx
  bool v9; // zf

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = v2[2].vfptr;
  v6 = v4[1]->i_data_p;
  v7 = 8i64 * LODWORD((*v4)->i_data_p->i_user_data);
  v8 = *(_DWORD **)((char *)v5->get_obj_type + v7);
  ++v6->i_ref_count;
  v9 = v8[4]-- == 1;
  if ( v9 )
  {
    v8[4] = 2147483648;
    (*(void (**)(void))(*(_QWORD *)v8 + 112i64))();
  }
  *(_QWORD *)((char *)v5->get_obj_type + v7) = v6;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1040
// RVA: 0x125700
void __fastcall SSList::mthd_set_items(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // r14
  SSData **v4; // rdx
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v5; // r15
  unsigned int v6; // ebp
  SSInstance *v7; // r13
  SSData *v8; // rax
  __int64 v9; // rdx
  __int64 v10; // r12
  unsigned int v11; // eax
  ARefCountMix<SSInstance> **v12; // rbx
  unsigned __int64 i; // rsi

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)v2[2].vfptr;
  v6 = v4[2]->i_data_p->i_user_data;
  if ( v6 )
  {
    v7 = (*v4)->i_data_p;
    v8 = v4[1];
    v9 = v6;
    v10 = LODWORD(v8->i_data_p->i_user_data);
    v7->i_ref_count += v6;
    v11 = v5->i_count - v10;
    if ( v11 < v6 )
      v9 = v11;
    if ( (_DWORD)v9 )
    {
      if ( (_DWORD)v9 == -1 )
        v9 = v11;
      if ( (_DWORD)v9 )
      {
        v12 = (ARefCountMix<SSInstance> **)&v5->i_array_p[v10];
        for ( i = (unsigned __int64)&v12[v9]; (unsigned __int64)v12 < i; ++v12 )
          ARefCountMix<SSInstance>::dereference(*v12 + 4);
      }
    }
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::set_all(v5, v7, v10, v6);
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1075
// RVA: 0x121CE0
void __fastcall SSList::mthd_crop(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // rbp
  SSData **v4; // rdx
  SSObjectBaseVtbl *v5; // r14
  __int64 v6; // r12
  __int64 v7; // r15
  __int64 v8; // rax
  ARefCountMix<SSInstance> **v9; // rbx
  unsigned __int64 i; // rsi
  unsigned int v11; // eax
  ARefCountMix<SSInstance> **v12; // rbx
  unsigned __int64 j; // rsi
  unsigned int (__fastcall *v14)(SSObjectBase *); // rcx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = v2[2].vfptr;
  v6 = LODWORD((*v4)->i_data_p->i_user_data);
  v7 = LODWORD(v4[1]->i_data_p->i_user_data);
  v8 = (unsigned int)v6;
  if ( (_DWORD)v6 == -1 )
    v8 = LODWORD(v5->__vecDelDtor);
  if ( (_DWORD)v8 )
  {
    v9 = (ARefCountMix<SSInstance> **)v5->get_obj_type;
    for ( i = (unsigned __int64)&v9[v8]; (unsigned __int64)v9 < i; ++v9 )
      ARefCountMix<SSInstance>::dereference(*v9 + 4);
  }
  v11 = v7 + v6;
  if ( LODWORD(v5->__vecDelDtor) != (_DWORD)v7 + (_DWORD)v6 )
  {
    v12 = (ARefCountMix<SSInstance> **)((char *)v5->get_obj_type + 8 * v11);
    for ( j = (unsigned __int64)&v12[LODWORD(v5->__vecDelDtor) - v11]; (unsigned __int64)v12 < j; ++v12 )
      ARefCountMix<SSInstance>::dereference(*v12 + 4);
  }
  if ( (_DWORD)v7 )
  {
    v14 = v5->get_obj_type;
    LODWORD(v5->__vecDelDtor) = v7;
    memmove(v14, (char *)v14 + 8 * v6, 8 * v7);
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1098
// RVA: 0x122320
void __fastcall SSList::mthd_empty(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // r15
  SSObjectBaseVtbl *v4; // r14
  __int64 v5; // rax
  ARefCountMix<SSInstance> **v6; // rbx
  unsigned __int64 i; // rsi

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  v5 = LODWORD(v4->__vecDelDtor);
  if ( (_DWORD)v5 )
  {
    v6 = (ARefCountMix<SSInstance> **)v4->get_obj_type;
    for ( i = (unsigned __int64)&v6[v5]; (unsigned __int64)v6 < i; ++v6 )
      ARefCountMix<SSInstance>::dereference(*v6 + 4);
  }
  LODWORD(v4->__vecDelDtor) = 0;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1118
// RVA: 0x124AF0
void __fastcall SSList::mthd_pop_at(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rdi
  SSObjectBase *v3; // rdx
  SSObjectBaseVtbl *v4; // rdx
  __int64 v5; // r8
  unsigned int (__fastcall *v6)(SSObjectBase *); // rax
  SSInstance *v7; // rbx
  bool v8; // zf

  v2 = result_pp;
  v3 = scope_p->i_scope_p.i_obj_p;
  if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = v3[2].vfptr;
  v5 = LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  v6 = v4->get_obj_type;
  v7 = (SSInstance *)*((_QWORD *)v6 + v5);
  memmove((char *)v6 + 8 * v5, (char *)v6 + 8 * v5 + 8, 8i64 * (unsigned int)(--LODWORD(v4->__vecDelDtor) - v5));
  if ( v2 )
  {
    *v2 = v7;
  }
  else
  {
    v8 = v7->i_ref_count-- == 1;
    if ( v8 )
    {
      v7->i_ref_count = 2147483648;
      v7->vfptr[1].get_scope_context((SSObjectBase *)&v7->vfptr);
    }
  }
}

// File Line: 1138
// RVA: 0x124B80
void __fastcall SSList::mthd_pop_first(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  SSInstance *v3; // rbx
  SSInstance **v4; // rdi
  SSObjectBaseVtbl *v5; // rdx
  SSInstance **v6; // rcx
  unsigned int v7; // eax
  bool v8; // zf

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = 0i64;
  v4 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v5 = v2[2].vfptr;
  if ( LODWORD(v5->__vecDelDtor) )
  {
    v6 = (SSInstance **)v5->get_obj_type;
    v7 = LODWORD(v5->__vecDelDtor) - 1;
    v3 = *v6;
    LODWORD(v5->__vecDelDtor) = v7;
    memmove(v6, v6 + 1, 8i64 * v7);
  }
  if ( v4 )
  {
    *v4 = v3;
  }
  else
  {
    v8 = v3->i_ref_count-- == 1;
    if ( v8 )
    {
      v3->i_ref_count = 2147483648;
      v3->vfptr[1].get_scope_context((SSObjectBase *)&v3->vfptr);
    }
  }
}

// File Line: 1158
// RVA: 0x124C00
void __fastcall SSList::mthd_pop_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // r9
  SSInvokedMethod *v4; // rdx
  SSInstance *v5; // rcx
  SSObjectBaseVtbl *v6; // rdx
  unsigned int v7; // eax
  bool v8; // zf

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  v4 = scope_p;
  v5 = 0i64;
  if ( !v2 || v4->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v6 = v2[2].vfptr;
  if ( LODWORD(v6->__vecDelDtor) )
  {
    v7 = LODWORD(v6->__vecDelDtor) - 1;
    LODWORD(v6->__vecDelDtor) = v7;
    v5 = (SSInstance *)*((_QWORD *)v6->get_obj_type + v7);
  }
  if ( v3 )
  {
    *v3 = v5;
  }
  else
  {
    v8 = v5->i_ref_count-- == 1;
    if ( v8 )
    {
      v5->i_ref_count = 2147483648;
      ((void (*)(void))v5->vfptr[1].get_scope_context)();
    }
  }
}

// File Line: 1178
// RVA: 0x124C60
void __fastcall SSList::mthd_pop_range(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r15
  SSObjectBase *v3; // rbp
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v4; // rsi
  SSData **v5; // rdx
  __int64 v6; // r14
  unsigned int v7; // edi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v8; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v9; // rbx
  SSInstance **v10; // rax
  int v11; // edx
  ARefCountMix<SSInstance> **v12; // rbx
  unsigned __int64 i; // rbp

  v2 = result_pp;
  v3 = scope_p->i_scope_p.i_obj_p;
  if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)v3[2].vfptr;
  v5 = scope_p->i_data.i_array_p;
  v6 = LODWORD((*v5)->i_data_p->i_user_data);
  v7 = v5[1]->i_data_p->i_user_data;
  if ( v2 )
  {
    v8 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v9 = v8;
    if ( v8 )
    {
      v8->i_count = 0;
      v8->i_array_p = 0i64;
      v8->i_size = 0;
      if ( v7 )
      {
        v8->i_size = v7;
        v10 = APArrayBase<SSInstance>::alloc_array(v7);
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
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::pop_all(v4, v9, v6, v7);
    *v2 = SSInstance::pool_new(*(SSClass **)&v3[1].i_ptr_id, (unsigned __int64)v9);
  }
  else
  {
    v11 = v5[1]->i_data_p->i_user_data;
    if ( v7 == -1 )
      v11 = v4->i_count - v6;
    if ( v11 )
    {
      v12 = (ARefCountMix<SSInstance> **)&v4->i_array_p[v6];
      for ( i = (unsigned __int64)&v12[v11]; (unsigned __int64)v12 < i; ++v12 )
        ARefCountMix<SSInstance>::dereference(*v12 + 4);
    }
    if ( v7 == -1 )
      v7 = v4->i_count - v6;
    if ( v7 )
    {
      v4->i_count -= v7;
      memmove(&v4->i_array_p[v6], &v4->i_array_p[v6 + v7], 8i64 * (unsigned int)(v4->i_count - v6));
    }
  }
}

// File Line: 1205
// RVA: 0x124DC0
void __fastcall SSList::mthd_pop_range_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r15
  SSObjectBase *v3; // rsi
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v4; // r14
  unsigned int v5; // edi
  __int64 v6; // rbp
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v7; // rax
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v8; // rbx
  SSInstance **v9; // rax
  int v10; // edx
  ARefCountMix<SSInstance> **v11; // rbx
  unsigned __int64 i; // rsi

  v2 = result_pp;
  v3 = scope_p->i_scope_p.i_obj_p;
  if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)v3[2].vfptr;
  v5 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = v4->i_count - v5;
  if ( result_pp )
  {
    v7 = (APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v8 = v7;
    if ( v7 )
    {
      v7->i_count = 0;
      v7->i_array_p = 0i64;
      v7->i_size = 0;
      if ( v5 )
      {
        v7->i_size = v5;
        v9 = APArrayBase<SSInstance>::alloc_array(v5);
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
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::pop_all(v4, v8, v6, v5);
    *v2 = SSInstance::pool_new(*(SSClass **)&v3[1].i_ptr_id, (unsigned __int64)v8);
  }
  else
  {
    v10 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v5 == -1 )
      v10 = v4->i_count - v6;
    if ( v10 )
    {
      v11 = (ARefCountMix<SSInstance> **)&v4->i_array_p[v6];
      for ( i = (unsigned __int64)&v11[v10]; (unsigned __int64)v11 < i; ++v11 )
        ARefCountMix<SSInstance>::dereference(*v11 + 4);
    }
    v4->i_count -= v5;
  }
}

// File Line: 1232
// RVA: 0x124EF0
void __fastcall SSList::mthd_remove_at(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSObjectBaseVtbl *v4; // rdx
  __int64 v5; // r8
  unsigned int (__fastcall *v6)(SSObjectBase *); // rax
  _DWORD *v7; // rsi
  bool v8; // zf

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  v5 = LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  v6 = v4->get_obj_type;
  v7 = (_DWORD *)*((_QWORD *)v6 + v5);
  memmove((char *)v6 + 8 * v5, (char *)v6 + 8 * v5 + 8, 8i64 * (unsigned int)(--LODWORD(v4->__vecDelDtor) - v5));
  v8 = v7[4]-- == 1;
  if ( v8 )
  {
    v7[4] = 2147483648;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v7 + 112i64))(v7);
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1257
// RVA: 0x124F80
void __fastcall SSList::mthd_remove_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // r10
  bool v3; // si
  SSInstance **v4; // r14
  SSInvokedMethod *v5; // rbp
  int v6; // er11
  SSObjectBase *v7; // r9
  unsigned int v8; // er8
  SSObjectBaseVtbl *v9; // rbx
  SSInstance *v10; // rdi
  SSData *v11; // rax
  int v12; // er10
  __int64 v13; // rax
  __int64 v14; // rcx
  unsigned int (__fastcall *v15)(SSObjectBase *); // r9
  SSInstance **v16; // rax
  unsigned __int64 v17; // rdx
  unsigned int v18; // ebx
  SSInstance *v19; // rax
  __int64 v20; // rbx
  SSInstance *v21; // r15
  _DWORD *v22; // rcx
  bool v23; // zf

  v2 = scope_p->i_data.i_array_p;
  v3 = 0;
  v4 = result_pp;
  v5 = scope_p;
  v6 = v2[2]->i_data_p->i_user_data;
  if ( !v6 )
    goto LABEL_14;
  v7 = scope_p->i_scope_p.i_obj_p;
  v8 = 0;
  if ( !v7 || scope_p->i_scope_p.i_ptr_id != v7->i_ptr_id )
    v7 = 0i64;
  v9 = v7[2].vfptr;
  v10 = (*v2)->i_data_p;
  v11 = v2[1];
  v12 = (int)v9->__vecDelDtor;
  v13 = LODWORD(v11->i_data_p->i_user_data);
  v14 = (unsigned int)(v13 + v6 - 1);
  if ( !LODWORD(v9->__vecDelDtor) )
    goto LABEL_13;
  if ( (_DWORD)v14 == -1 )
    v14 = (unsigned int)(v12 - 1);
  v15 = v9->get_obj_type;
  v16 = (SSInstance **)((char *)v15 + 8 * v13);
  v17 = (unsigned __int64)v15 + 8 * v14;
  if ( (unsigned __int64)v16 > v17 )
  {
LABEL_13:
    v3 = 0;
    goto LABEL_14;
  }
  while ( v10 != *v16 )
  {
LABEL_12:
    ++v16;
    if ( (unsigned __int64)v16 > v17 )
      goto LABEL_13;
  }
  if ( v8 >= 2 )
  {
    --v8;
    goto LABEL_12;
  }
  LODWORD(v9->__vecDelDtor) = v12 - 1;
  v18 = ((char *)v16 - (char *)v15) >> 3;
  memmove((char *)v15 + 8 * v18, (char *)v15 + 8 * v18 + 8, 8i64 * (v12 - 1 - v18));
  v3 = 1;
  v19 = SSInstance::pool_new(SSBrain::c_integer_class_p, v18);
  v20 = *((_QWORD *)v5->i_data.i_array_p + 3);
  v21 = v19;
  v22 = *(_DWORD **)(v20 + 8);
  v23 = v22[4]-- == 1;
  if ( v23 )
  {
    v22[4] = 2147483648;
    (*(void (**)(void))(*(_QWORD *)v22 + 112i64))();
  }
  *(_QWORD *)(v20 + 8) = v21;
  v23 = v10->i_ref_count-- == 1;
  if ( v23 )
  {
    v10->i_ref_count = 2147483648;
    v10->vfptr[1].get_scope_context((SSObjectBase *)&v10->vfptr);
  }
LABEL_14:
  if ( v4 )
    *v4 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 1292
// RVA: 0x1250E0
void __fastcall SSList::mthd_remove_first(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  _DWORD *v3; // rdi
  SSInstance **v4; // rsi
  SSObjectBaseVtbl *v5; // rdx
  unsigned int (__fastcall *v6)(SSObjectBase *); // rcx
  unsigned int v7; // eax
  bool v8; // zf

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = 0i64;
  v4 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v5 = v2[2].vfptr;
  if ( LODWORD(v5->__vecDelDtor) )
  {
    v6 = v5->get_obj_type;
    v7 = LODWORD(v5->__vecDelDtor) - 1;
    v3 = *(_DWORD **)v6;
    LODWORD(v5->__vecDelDtor) = v7;
    memmove(v6, (char *)v6 + 8, 8i64 * v7);
  }
  v8 = v3[4]-- == 1;
  if ( v8 )
  {
    v3[4] = 2147483648;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v3 + 112i64))(v3);
  }
  if ( v4 )
  {
    ++LODWORD(v2[1].vfptr);
    *v4 = (SSInstance *)v2;
  }
}

// File Line: 1311
// RVA: 0x125160
void __fastcall SSList::mthd_remove_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSInvokedMethod *v4; // rdx
  _DWORD *v5; // rcx
  SSObjectBaseVtbl *v6; // rdx
  unsigned int v7; // eax
  bool v8; // zf

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  v4 = scope_p;
  v5 = 0i64;
  if ( !v2 || v4->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v6 = v2[2].vfptr;
  if ( LODWORD(v6->__vecDelDtor) )
  {
    v7 = LODWORD(v6->__vecDelDtor) - 1;
    LODWORD(v6->__vecDelDtor) = v7;
    v5 = (_DWORD *)*((_QWORD *)v6->get_obj_type + v7);
  }
  v8 = v5[4]-- == 1;
  if ( v8 )
  {
    v5[4] = 2147483648;
    (*(void (**)(void))(*(_QWORD *)v5 + 112i64))();
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1330
// RVA: 0x1251D0
void __fastcall SSList::mthd_remove_list_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // r14
  unsigned int *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  SSObjectBaseVtbl *v7; // rsi
  unsigned __int64 i; // rbp
  unsigned __int64 v9; // r9
  __int64 v10; // r10
  unsigned __int64 v11; // rdx
  unsigned int (__fastcall *v12)(SSObjectBase *); // rax
  _DWORD *v13; // rcx
  bool v14; // zf

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (unsigned int *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = *v4;
  if ( (_DWORD)v5 )
  {
    v6 = *((_QWORD *)v4 + 1);
    v7 = v2[2].vfptr;
    for ( i = v6 + 8 * v5; v6 < i; v6 += 8i64 )
    {
      if ( LODWORD(v7->__vecDelDtor) )
      {
        v9 = (unsigned __int64)v7->get_obj_type;
        v10 = (unsigned int)(LODWORD(v7->__vecDelDtor) - 1);
        v11 = v9 + 8 * v10;
        v12 = v7->get_obj_type;
        if ( v9 <= v11 )
        {
          while ( *(_QWORD *)v6 != *(_QWORD *)v12 )
          {
            v12 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)v12 + 8);
            if ( (unsigned __int64)v12 > v11 )
              goto LABEL_13;
          }
          LODWORD(v7->__vecDelDtor) = v10;
          memmove(
            (void *)(v9 + 8i64 * (unsigned int)((signed __int64)((signed __int64)v12 - v9) >> 3)),
            (const void *)(v9 + 8i64 * (unsigned int)((signed __int64)((signed __int64)v12 - v9) >> 3) + 8),
            8i64 * ((unsigned int)v10 - (unsigned int)((signed __int64)((signed __int64)v12 - v9) >> 3)));
          v13 = *(_DWORD **)v6;
          v14 = *(_DWORD *)(*(_QWORD *)v6 + 16i64) == 1;
          --v13[4];
          if ( v14 )
          {
            v13[4] = 2147483648;
            (*(void (**)(void))(*(_QWORD *)v13 + 112i64))();
          }
        }
      }
LABEL_13:
      ;
    }
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1365
// RVA: 0x1252D0
void __fastcall SSList::mthd_remove_range(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // r12
  SSData **v4; // rdx
  SSObjectBaseVtbl *v5; // r14
  __int64 v6; // r15
  unsigned int v7; // esi
  unsigned int v8; // edx
  ARefCountMix<SSInstance> **v9; // rbx
  unsigned __int64 i; // rbp
  unsigned int (__fastcall *v11)(SSObjectBase *); // rcx

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = v2[2].vfptr;
  v6 = LODWORD((*v4)->i_data_p->i_user_data);
  v7 = v4[1]->i_data_p->i_user_data;
  v8 = v7;
  if ( v7 == -1 )
    v8 = LODWORD(v5->__vecDelDtor) - v6;
  if ( v8 )
  {
    v9 = (ARefCountMix<SSInstance> **)((char *)v5->get_obj_type + 8 * v6);
    for ( i = (unsigned __int64)&v9[v8]; (unsigned __int64)v9 < i; ++v9 )
      ARefCountMix<SSInstance>::dereference(*v9 + 4);
  }
  if ( v7 == -1 )
    v7 = LODWORD(v5->__vecDelDtor) - v6;
  if ( v7 )
  {
    v11 = v5->get_obj_type;
    LODWORD(v5->__vecDelDtor) -= v7;
    memmove((char *)v11 + 8 * v6, (char *)v11 + 8 * (v6 + v7), 8i64 * (unsigned int)(LODWORD(v5->__vecDelDtor) - v6));
  }
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1387
// RVA: 0x1253D0
void __fastcall SSList::mthd_remove_range_last(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdi
  SSInstance **v3; // r15
  SSObjectBaseVtbl *v4; // r14
  int v5; // ebp
  unsigned int v6; // eax
  unsigned int v7; // edx
  ARefCountMix<SSInstance> **v8; // rbx
  unsigned __int64 i; // rsi

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  v5 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = LODWORD(v4->__vecDelDtor) - v5;
  v7 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v5 == -1 )
    v7 = LODWORD(v4->__vecDelDtor) - v6;
  if ( v7 )
  {
    v8 = (ARefCountMix<SSInstance> **)((char *)v4->get_obj_type + 8 * v6);
    for ( i = (unsigned __int64)&v8[v7]; (unsigned __int64)v8 < i; ++v8 )
      ARefCountMix<SSInstance>::dereference(*v8 + 4);
  }
  LODWORD(v4->__vecDelDtor) -= v5;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 1408
// RVA: 0x122480
void __fastcall SSList::mthd_equals_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  SSObjectBaseVtbl *v4; // rdx
  bool v5; // r9
  SSInstance *v6; // rax
  __int64 v7; // rcx
  unsigned __int64 v8; // rax
  unsigned int (__fastcall *v9)(SSObjectBase *); // rax
  unsigned int (__fastcall *v10)(SSObjectBase *); // rdx
  unsigned __int64 v11; // r8
  signed __int64 v12; // rdx

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    v3 = result_pp;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = 0;
    v6 = (*scope_p->i_data.i_array_p)->i_data_p;
    v7 = LODWORD(v4->__vecDelDtor);
    v8 = v6->i_user_data;
    if ( (_DWORD)v7 == *(_DWORD *)v8 )
    {
      v9 = *(unsigned int (__fastcall **)(SSObjectBase *))(v8 + 8);
      v10 = v4->get_obj_type;
      v5 = 1;
      v11 = (unsigned __int64)v9 + 8 * v7;
      if ( (unsigned __int64)v9 < v11 )
      {
        v12 = (char *)v10 - (char *)v9;
        while ( *(_QWORD *)((char *)v9 + v12) == *(_QWORD *)v9 )
        {
          v9 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)v9 + 8);
          if ( (unsigned __int64)v9 >= v11 )
          {
            *v3 = (SSInstance *)SSBoolean::pool_new(1);
            return;
          }
        }
        v5 = 0;
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 1451
// RVA: 0x123230
void __fastcall SSList::mthd_not_equal_eqv(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  SSObjectBaseVtbl *v4; // rdx
  bool v5; // r9
  SSInstance *v6; // rax
  __int64 v7; // rcx
  unsigned __int64 v8; // rax
  unsigned int (__fastcall *v9)(SSObjectBase *); // rax
  unsigned int (__fastcall *v10)(SSObjectBase *); // rdx
  unsigned __int64 v11; // r8
  signed __int64 v12; // rdx

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    v3 = result_pp;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = 1;
    v6 = (*scope_p->i_data.i_array_p)->i_data_p;
    v7 = LODWORD(v4->__vecDelDtor);
    v8 = v6->i_user_data;
    if ( (_DWORD)v7 == *(_DWORD *)v8 )
    {
      v9 = *(unsigned int (__fastcall **)(SSObjectBase *))(v8 + 8);
      v10 = v4->get_obj_type;
      v5 = 0;
      v11 = (unsigned __int64)v9 + 8 * v7;
      if ( (unsigned __int64)v9 < v11 )
      {
        v12 = (char *)v10 - (char *)v9;
        while ( *(_QWORD *)((char *)v9 + v12) == *(_QWORD *)v9 )
        {
          v9 = (unsigned int (__fastcall *)(SSObjectBase *))((char *)v9 + 8);
          if ( (unsigned __int64)v9 >= v11 )
          {
            *v3 = (SSInstance *)SSBoolean::pool_new(0);
            return;
          }
        }
        v5 = 1;
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

