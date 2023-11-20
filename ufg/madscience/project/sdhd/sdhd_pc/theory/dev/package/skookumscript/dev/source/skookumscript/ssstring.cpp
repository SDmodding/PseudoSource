// File Line: 36
// RVA: 0x10F210
SSInstance *__fastcall SSString::as_instance(AString *str)
{
  unsigned __int64 *v1; // rbx
  SSInstance *result; // rax
  unsigned __int64 v3; // rcx

  v1 = (unsigned __int64 *)str;
  result = SSInstance::pool_new(SSBrain::c_string_class_p);
  if ( result != (SSInstance *)-32i64 )
  {
    v3 = *v1;
    result->i_user_data = *v1;
    ++*(_WORD *)(v3 + 16);
  }
  return result;
}

// File Line: 50
// RVA: 0x139240
void __fastcall SSString::register_atomic(__int64 a1, signed __int64 a2, __int64 a3, __int64 a4)
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
  signed __int64 v107; // [rsp+20h] [rbp-10h]
  __int64 result; // [rsp+70h] [rbp+40h]
  SSParameters *v109; // [rsp+78h] [rbp+48h]
  __int64 v110; // [rsp+80h] [rbp+50h]

  v107 = -2i64;
  v4 = (SSMethodBase **)SSBrain::c_string_class_p;
  v5 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v5 )
  {
    v4 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v6 = (signed __int64)&v4[v5 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v4[(v6 - (signed __int64)v4) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbolX_dtor.i_uid < (unsigned int)a4 )
        goto LABEL_279;
      v7 = ASymbolX_dtor.i_uid == (_DWORD)a4;
      a4 = ASymbolX_dtor.i_uid != (_DWORD)a4;
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
      *(_QWORD *)(v8 + 32) = SSString::mthd_destructor;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      v109 = v10;
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
      v110 = v8;
      *(ASymbol *)(v8 + 8) = ASymbolX_dtor;
      *(_QWORD *)(v8 + 16) = v9;
      *(_QWORD *)v8 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v8 + 24) = v10;
      if ( v10 )
        ++v10->i_ref_count;
      *(_QWORD *)v8 = &SSMethodBase::`vftable';
      *(_QWORD *)v8 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v8 + 32) = SSString::mthd_destructor;
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
  v13 = (SSMethodBase **)SSBrain::c_string_class_p;
  v14 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v13 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v15 = (signed __int64)&v13[v14 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v13[(v15 - (signed __int64)v13) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_String.i_uid < (unsigned int)a4 )
        goto LABEL_280;
      v16 = ASymbol_String.i_uid == (_DWORD)a4;
      a4 = ASymbol_String.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v17 + 32) = SSString::mthd_as_string;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      v109 = v19;
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
      v110 = v17;
      *(ASymbol *)(v17 + 8) = ASymbol_String;
      *(_QWORD *)(v17 + 16) = v18;
      *(_QWORD *)v17 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v17 + 24) = v19;
      if ( v19 )
        ++v19->i_ref_count;
      *(_QWORD *)v17 = &SSMethodBase::`vftable';
      *(_QWORD *)v17 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v17 + 32) = SSString::mthd_as_string;
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
  v21 = (SSMethodBase **)SSBrain::c_string_class_p;
  v22 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    v21 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v23 = (signed __int64)&v21[v22 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v21[(v23 - (signed __int64)v21) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_Symbol.i_uid < (unsigned int)a4 )
        goto LABEL_281;
      v24 = ASymbol_Symbol.i_uid == (_DWORD)a4;
      a4 = ASymbol_Symbol.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v25 + 32) = SSString::mthd_as_symbol;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v109 = v27;
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
      v110 = v25;
      *(ASymbol *)(v25 + 8) = ASymbol_Symbol;
      *(_QWORD *)(v25 + 16) = v26;
      *(_QWORD *)v25 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v25 + 24) = v27;
      if ( v27 )
        ++v27->i_ref_count;
      *(_QWORD *)v25 = &SSMethodBase::`vftable';
      *(_QWORD *)v25 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v25 + 32) = SSString::mthd_as_symbol;
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
  v29 = (SSMethodBase **)SSBrain::c_string_class_p;
  v30 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v30 )
  {
    v29 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v31 = (signed __int64)&v29[v30 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v29[(v31 - (signed __int64)v29) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_add.i_uid < (unsigned int)a4 )
        goto LABEL_282;
      v32 = ASymbol_add.i_uid == (_DWORD)a4;
      a4 = ASymbol_add.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v33 + 32) = SSString::mthd_op_add;
    }
    else
    {
      v34 = *(_QWORD *)(v33 + 16);
      v35 = *(SSParameters **)(v33 + 24);
      v109 = v35;
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
      v110 = v33;
      *(ASymbol *)(v33 + 8) = ASymbol_add;
      *(_QWORD *)(v33 + 16) = v34;
      *(_QWORD *)v33 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v33 + 24) = v35;
      if ( v35 )
        ++v35->i_ref_count;
      *(_QWORD *)v33 = &SSMethodBase::`vftable';
      *(_QWORD *)v33 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v33 + 32) = SSString::mthd_op_add;
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
  v37 = (SSMethodBase **)SSBrain::c_string_class_p;
  v38 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v38 )
  {
    v37 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v39 = (signed __int64)&v37[v38 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v37[(v39 - (signed __int64)v37) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_add_assign.i_uid < (unsigned int)a4 )
        goto LABEL_283;
      v40 = ASymbol_add_assign.i_uid == (_DWORD)a4;
      a4 = ASymbol_add_assign.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v41 + 32) = SSString::mthd_op_add_assign;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      v109 = v43;
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
      v110 = v41;
      *(ASymbol *)(v41 + 8) = ASymbol_add_assign;
      *(_QWORD *)(v41 + 16) = v42;
      *(_QWORD *)v41 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v41 + 24) = v43;
      if ( v43 )
        ++v43->i_ref_count;
      *(_QWORD *)v41 = &SSMethodBase::`vftable';
      *(_QWORD *)v41 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v41 + 32) = SSString::mthd_op_add_assign;
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
  v45 = (SSMethodBase **)SSBrain::c_string_class_p;
  v46 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v46 )
  {
    v45 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v47 = (signed __int64)&v45[v46 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v45[(v47 - (signed __int64)v45) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_assign.i_uid < (unsigned int)a4 )
        goto LABEL_284;
      v48 = ASymbol_assign.i_uid == (_DWORD)a4;
      a4 = ASymbol_assign.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v49 + 32) = SSString::mthd_op_assign;
    }
    else
    {
      v50 = *(_QWORD *)(v49 + 16);
      v51 = *(SSParameters **)(v49 + 24);
      v109 = v51;
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
      v110 = v49;
      *(ASymbol *)(v49 + 8) = ASymbol_assign;
      *(_QWORD *)(v49 + 16) = v50;
      *(_QWORD *)v49 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v49 + 24) = v51;
      if ( v51 )
        ++v51->i_ref_count;
      *(_QWORD *)v49 = &SSMethodBase::`vftable';
      *(_QWORD *)v49 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v49 + 32) = SSString::mthd_op_assign;
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
  v53 = (SSMethodBase **)SSBrain::c_string_class_p;
  v54 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v54 )
  {
    v53 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v55 = (signed __int64)&v53[v54 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v53[(v55 - (signed __int64)v53) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_equals.i_uid < (unsigned int)a4 )
        goto LABEL_285;
      v56 = ASymbol_equals.i_uid == (_DWORD)a4;
      a4 = ASymbol_equals.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v57 + 32) = SSString::mthd_op_equals;
    }
    else
    {
      v58 = *(_QWORD *)(v57 + 16);
      v59 = *(SSParameters **)(v57 + 24);
      v109 = v59;
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
      v110 = v57;
      *(ASymbol *)(v57 + 8) = ASymbol_equals;
      *(_QWORD *)(v57 + 16) = v58;
      *(_QWORD *)v57 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v57 + 24) = v59;
      if ( v59 )
        ++v59->i_ref_count;
      *(_QWORD *)v57 = &SSMethodBase::`vftable';
      *(_QWORD *)v57 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v57 + 32) = SSString::mthd_op_equals;
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
  v61 = (SSMethodBase **)SSBrain::c_string_class_p;
  v62 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v62 )
  {
    v61 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v63 = (signed __int64)&v61[v62 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v61[(v63 - (signed __int64)v61) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_greater.i_uid < (unsigned int)a4 )
        goto LABEL_286;
      v64 = ASymbol_greater.i_uid == (_DWORD)a4;
      a4 = ASymbol_greater.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v65 + 32) = SSString::mthd_op_greater;
    }
    else
    {
      v66 = *(_QWORD *)(v65 + 16);
      v67 = *(SSParameters **)(v65 + 24);
      v109 = v67;
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
      v110 = v65;
      *(ASymbol *)(v65 + 8) = ASymbol_greater;
      *(_QWORD *)(v65 + 16) = v66;
      *(_QWORD *)v65 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v65 + 24) = v67;
      if ( v67 )
        ++v67->i_ref_count;
      *(_QWORD *)v65 = &SSMethodBase::`vftable';
      *(_QWORD *)v65 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v65 + 32) = SSString::mthd_op_greater;
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
  v69 = (SSMethodBase **)SSBrain::c_string_class_p;
  v70 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v70 )
  {
    v69 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v71 = (signed __int64)&v69[v70 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v69[(v71 - (signed __int64)v69) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_greater_or_equal.i_uid < (unsigned int)a4 )
        goto LABEL_287;
      v72 = ASymbol_greater_or_equal.i_uid == (_DWORD)a4;
      a4 = ASymbol_greater_or_equal.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v73 + 32) = SSString::mthd_op_greater_or_equal;
    }
    else
    {
      v74 = *(_QWORD *)(v73 + 16);
      v75 = *(SSParameters **)(v73 + 24);
      v109 = v75;
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
      v110 = v73;
      *(ASymbol *)(v73 + 8) = ASymbol_greater_or_equal;
      *(_QWORD *)(v73 + 16) = v74;
      *(_QWORD *)v73 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v73 + 24) = v75;
      if ( v75 )
        ++v75->i_ref_count;
      *(_QWORD *)v73 = &SSMethodBase::`vftable';
      *(_QWORD *)v73 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v73 + 32) = SSString::mthd_op_greater_or_equal;
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
  v77 = (SSMethodBase **)SSBrain::c_string_class_p;
  v78 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v78 )
  {
    v77 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v79 = (signed __int64)&v77[v78 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v77[(v79 - (signed __int64)v77) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_less.i_uid < (unsigned int)a4 )
        goto LABEL_288;
      v80 = ASymbol_less.i_uid == (_DWORD)a4;
      a4 = ASymbol_less.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v81 + 32) = SSString::mthd_op_less;
    }
    else
    {
      v82 = *(_QWORD *)(v81 + 16);
      v83 = *(SSParameters **)(v81 + 24);
      v109 = v83;
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
      v110 = v81;
      *(ASymbol *)(v81 + 8) = ASymbol_less;
      *(_QWORD *)(v81 + 16) = v82;
      *(_QWORD *)v81 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v81 + 24) = v83;
      if ( v83 )
        ++v83->i_ref_count;
      *(_QWORD *)v81 = &SSMethodBase::`vftable';
      *(_QWORD *)v81 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v81 + 32) = SSString::mthd_op_less;
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
  v85 = (SSMethodBase **)SSBrain::c_string_class_p;
  v86 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v86 )
  {
    v85 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v87 = (signed __int64)&v85[v86 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v85[(v87 - (signed __int64)v85) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_less_or_equal.i_uid < (unsigned int)a4 )
        goto LABEL_289;
      v88 = ASymbol_less_or_equal.i_uid == (_DWORD)a4;
      a4 = ASymbol_less_or_equal.i_uid != (_DWORD)a4;
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
           v107) == 1 )
    {
      *(_QWORD *)(v89 + 32) = SSString::mthd_op_less_or_equal;
    }
    else
    {
      v90 = *(_QWORD *)(v89 + 16);
      v91 = *(SSParameters **)(v89 + 24);
      v109 = v91;
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
      v110 = v89;
      *(ASymbol *)(v89 + 8) = ASymbol_less_or_equal;
      *(_QWORD *)(v89 + 16) = v90;
      *(_QWORD *)v89 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v89 + 24) = v91;
      if ( v91 )
        ++v91->i_ref_count;
      *(_QWORD *)v89 = &SSMethodBase::`vftable';
      *(_QWORD *)v89 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v89 + 32) = SSString::mthd_op_less_or_equal;
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
  SSClass::register_method_func(SSBrain::c_string_class_p, &ASymbol_not_equal, SSString::mthd_op_not_equal, 0);
  SSClass::register_method_func(SSBrain::c_string_class_p, &ASymbol_append, SSString::mthd_op_add_assign, 0);
  v93 = SSBrain::c_string_class_p;
  v94 = ASymbol::create((ASymbol *)&result, "as_crc32", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v93, v94, SSString::mthd_as_crc32, 0);
  v95 = SSBrain::c_string_class_p;
  v96 = ASymbol::create((ASymbol *)&result, "empty", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v95, v96, SSString::mthd_empty, 0);
  v97 = SSBrain::c_string_class_p;
  v98 = ASymbol::create((ASymbol *)&result, "enumerate", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v97, v98, SSString::mthd_enumerate, 0);
  v99 = SSBrain::c_string_class_p;
  v100 = ASymbol::create((ASymbol *)&result, "is_empty", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v99, v100, SSString::mthd_is_empty, 0);
  v101 = SSBrain::c_string_class_p;
  v102 = ASymbol::create((ASymbol *)&result, "is_filled", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v101, v102, SSString::mthd_is_filled, 0);
  v103 = SSBrain::c_string_class_p;
  v104 = ASymbol::create((ASymbol *)&result, "lowercase", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v103, v104, SSString::mthd_lowercase, 0);
  v105 = SSBrain::c_string_class_p;
  v106 = ASymbol::create((ASymbol *)&result, "uppercase", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v105, v106, SSString::mthd_uppercase, 0);
}

// File Line: 89
// RVA: 0x1220D0
void __fastcall SSString::mthd_destructor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  AStringRef *v3; // rbx
  bool v4; // zf
  AObjReusePool<AStringRef> *v5; // rax
  AObjBlock<AStringRef> *v6; // rcx
  unsigned __int64 v7; // rdx
  bool v8; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v9; // rcx

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (AStringRef *)v2[2].vfptr;
  v4 = v3->i_ref_count-- == 1;
  if ( v4 )
  {
    if ( v3->i_deallocate )
      AMemory::c_free_func(v3->i_cstr_p);
    v5 = AStringRef::get_pool();
    v6 = v5->i_block_p;
    v7 = (unsigned __int64)v6->i_objects_a;
    if ( (unsigned __int64)v3 < v7 || (v8 = (unsigned __int64)v3 < v7 + 24i64 * v6->i_size, v9 = &v5->i_pool, !v8) )
      v9 = &v5->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v9, v3);
  }
}

// File Line: 107
// RVA: 0x121870
void __fastcall SSString::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v2; // r8

  if ( result_pp )
  {
    v2 = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    ++v2->i_ref_count;
    *result_pp = v2;
  }
}

// File Line: 129
// RVA: 0x1218A0
void __fastcall SSString::mthd_as_symbol(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // rdx
  ASymbol *v4; // rdi
  SSInstance *v5; // rax
  ASymbol result; // [rsp+48h] [rbp+10h]
  SSInstance *v7; // [rsp+50h] [rbp+18h]
  unsigned __int64 *v8; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = ASymbol::create(&result, (AString *)&v3[2], ATerm_long);
    v5 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    v7 = v5;
    v8 = &v5->i_user_data;
    if ( v5 != (SSInstance *)-32i64 )
      LODWORD(v5->i_user_data) = (ASymbol)v4->i_uid;
    *v2 = v5;
  }
}

// File Line: 156
// RVA: 0x1209A0
void __fastcall SSString::mthd_op_add_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( result_pp )
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    AString::append((AString *)&v2[2], (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
  else
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    AString::append((AString *)&v2[2], (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 188
// RVA: 0x123890
void __fastcall SSString::mthd_op_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( result_pp )
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    AString::operator=((AString *)&v2[2], (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
  else
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    AString::operator=((AString *)&v2[2], (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 253
// RVA: 0x123D00
void __fastcall SSString::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSInstance *v3; // r9
  SSObjectBase *v4; // r8
  SSObjectBaseVtbl *v5; // rcx
  unsigned __int64 v6; // rax
  __int64 v7; // rdx
  void *(__fastcall *v8)(SSObjectBase *, unsigned int); // rcx
  void *(__fastcall *v9)(SSObjectBase *, unsigned int); // rdx
  __int64 v10; // r8

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = scope_p->i_scope_p.i_obj_p;
    if ( !v4 || scope_p->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v5 = v4[2].vfptr;
    v6 = v3->i_user_data;
    v7 = LODWORD(v5->get_obj_type);
    if ( (_DWORD)v7 != *(_DWORD *)(v6 + 8) )
    {
LABEL_6:
      *v2 = (SSInstance *)SSBoolean::pool_new(0);
      return;
    }
    v8 = v5->__vecDelDtor;
    if ( v8 != *(void *(__fastcall **)(SSObjectBase *, unsigned int))v6 )
    {
      v9 = (void *(__fastcall *)(SSObjectBase *, unsigned int))((char *)v8 + v7);
      if ( (unsigned __int64)v8 < (unsigned __int64)v9 )
      {
        v10 = *(_QWORD *)v6 - (_QWORD)v8;
        while ( *(_BYTE *)v8 == *((_BYTE *)v8 + v10) )
        {
          v8 = (void *(__fastcall *)(SSObjectBase *, unsigned int))((char *)v8 + 1);
          if ( (unsigned __int64)v8 >= (unsigned __int64)v9 )
            goto LABEL_12;
        }
        goto LABEL_6;
      }
    }
LABEL_12:
    *v2 = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 278
// RVA: 0x124730
void __fastcall SSString::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSInstance *v3; // r9
  SSObjectBase *v4; // r8
  SSObjectBaseVtbl *v5; // rcx
  unsigned __int64 v6; // rax
  __int64 v7; // rdx
  void *(__fastcall *v8)(SSObjectBase *, unsigned int); // rcx
  void *(__fastcall *v9)(SSObjectBase *, unsigned int); // rdx
  __int64 v10; // r8

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = scope_p->i_scope_p.i_obj_p;
    if ( !v4 || scope_p->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v5 = v4[2].vfptr;
    v6 = v3->i_user_data;
    v7 = LODWORD(v5->get_obj_type);
    if ( (_DWORD)v7 != *(_DWORD *)(v6 + 8) )
    {
LABEL_6:
      *v2 = (SSInstance *)SSBoolean::pool_new(1);
      return;
    }
    v8 = v5->__vecDelDtor;
    if ( v8 != *(void *(__fastcall **)(SSObjectBase *, unsigned int))v6 )
    {
      v9 = (void *(__fastcall *)(SSObjectBase *, unsigned int))((char *)v8 + v7);
      if ( (unsigned __int64)v8 < (unsigned __int64)v9 )
      {
        v10 = *(_QWORD *)v6 - (_QWORD)v8;
        while ( *(_BYTE *)v8 == *((_BYTE *)v8 + v10) )
        {
          v8 = (void *(__fastcall *)(SSObjectBase *, unsigned int))((char *)v8 + 1);
          if ( (unsigned __int64)v8 >= (unsigned __int64)v9 )
            goto LABEL_12;
        }
        goto LABEL_6;
      }
    }
LABEL_12:
    *v2 = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 303
// RVA: 0x123E80
void __fastcall SSString::mthd_op_greater(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // r9
  SSObjectBase *v4; // rcx
  SSInstance **v5; // rbx
  SSObjectBaseVtbl *v6; // rcx
  unsigned __int64 v7; // rdx
  size_t v8; // r8
  const char *v9; // rdx
  int v10; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_data.i_array_p;
    v3 = scope_p;
    v4 = scope_p->i_scope_p.i_obj_p;
    v5 = result_pp;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v6 = v4[2].vfptr;
    v7 = (*v2)->i_data_p->i_user_data;
    v8 = *(unsigned int *)(v7 + 8);
    v9 = *(const char **)v7;
    if ( LODWORD(v6->get_obj_type) < (unsigned int)v8 )
      v8 = LODWORD(v6->get_obj_type);
    v10 = strncmp((const char *)v6->__vecDelDtor, v9, v8);
    *v5 = (SSInstance *)SSBoolean::pool_new(v10 > 0);
  }
}

// File Line: 328
// RVA: 0x123FE0
void __fastcall SSString::mthd_op_greater_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // r9
  SSObjectBase *v4; // rcx
  SSInstance **v5; // rbx
  SSObjectBaseVtbl *v6; // rcx
  unsigned __int64 v7; // rdx
  size_t v8; // r8
  const char *v9; // rdx
  int v10; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_data.i_array_p;
    v3 = scope_p;
    v4 = scope_p->i_scope_p.i_obj_p;
    v5 = result_pp;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v6 = v4[2].vfptr;
    v7 = (*v2)->i_data_p->i_user_data;
    v8 = *(unsigned int *)(v7 + 8);
    v9 = *(const char **)v7;
    if ( LODWORD(v6->get_obj_type) < (unsigned int)v8 )
      v8 = LODWORD(v6->get_obj_type);
    v10 = strncmp((const char *)v6->__vecDelDtor, v9, v8);
    *v5 = (SSInstance *)SSBoolean::pool_new(v10 >= 0);
  }
}

// File Line: 353
// RVA: 0x1241E0
void __fastcall SSString::mthd_op_less(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // r9
  SSObjectBase *v4; // rcx
  SSInstance **v5; // rbx
  SSObjectBaseVtbl *v6; // rcx
  unsigned __int64 v7; // rdx
  size_t v8; // r8
  const char *v9; // rdx
  int v10; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_data.i_array_p;
    v3 = scope_p;
    v4 = scope_p->i_scope_p.i_obj_p;
    v5 = result_pp;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v6 = v4[2].vfptr;
    v7 = (*v2)->i_data_p->i_user_data;
    v8 = *(unsigned int *)(v7 + 8);
    v9 = *(const char **)v7;
    if ( LODWORD(v6->get_obj_type) < (unsigned int)v8 )
      v8 = LODWORD(v6->get_obj_type);
    v10 = strncmp((const char *)v6->__vecDelDtor, v9, v8);
    *v5 = (SSInstance *)SSBoolean::pool_new(v10 < 0);
  }
}

// File Line: 378
// RVA: 0x124340
void __fastcall SSString::mthd_op_less_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // r9
  SSObjectBase *v4; // rcx
  SSInstance **v5; // rbx
  SSObjectBaseVtbl *v6; // rcx
  unsigned __int64 v7; // rdx
  size_t v8; // r8
  const char *v9; // rdx
  int v10; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_data.i_array_p;
    v3 = scope_p;
    v4 = scope_p->i_scope_p.i_obj_p;
    v5 = result_pp;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v6 = v4[2].vfptr;
    v7 = (*v2)->i_data_p->i_user_data;
    v8 = *(unsigned int *)(v7 + 8);
    v9 = *(const char **)v7;
    if ( LODWORD(v6->get_obj_type) < (unsigned int)v8 )
      v8 = LODWORD(v6->get_obj_type);
    v10 = strncmp((const char *)v6->__vecDelDtor, v9, v8);
    *v5 = (SSInstance *)SSBoolean::pool_new(v10 <= 0);
  }
}

// File Line: 396
// RVA: 0x1234F0
void __fastcall SSString::mthd_op_add(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  AString v4; // [rsp+48h] [rbp+10h]
  AString *v5; // [rsp+50h] [rbp+18h]

  if ( result_pp )
  {
    v2 = result_pp;
    v5 = &v4;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4.i_str_ref_p = (AStringRef *)v3[2].vfptr;
    ++v4.i_str_ref_p->i_ref_count;
    AString::append(&v4, (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    *v2 = SSInstance::pool_new(SSBrain::c_string_class_p, (unsigned __int64)v4.i_str_ref_p);
  }
}

// File Line: 418
// RVA: 0x120E80
void __fastcall SSString::mthd_as_crc32(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSInstance **v4; // rbx
  unsigned int v5; // eax

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = scope_p->i_scope_p.i_obj_p;
    v4 = result_pp;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v5 = AChecksum::generate_crc32_cstr(
           (const char *)v3[2].vfptr->__vecDelDtor,
           (unsigned int)v3[2].vfptr->get_obj_type,
           0xFFFFFFFF);
    *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 435
// RVA: 0x1223C0
void __fastcall SSString::mthd_empty(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rbx
  SSObjectBaseVtbl *v3; // rdx
  AStringRef *v4; // rax

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( LOWORD(v3->is_actor) + BYTE3(v3->is_actor) == 1 )
  {
    *(_BYTE *)v3->__vecDelDtor = 0;
    LODWORD(v2[2].vfptr->get_obj_type) = 0;
  }
  else
  {
    AStringRef::dereference((AStringRef *)v2[2].vfptr);
    v4 = AStringRef::get_empty();
    v2[2].vfptr = (SSObjectBaseVtbl *)v4;
    ++v4->i_ref_count;
  }
}

// File Line: 448
// RVA: 0x122420
void __fastcall SSString::mthd_enumerate(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // r8
  SSInstance **v3; // rbx
  SSInvokedMethod *v4; // r9
  SSObjectBase *v5; // rcx
  unsigned int v6; // eax

  v2 = scope_p->i_data.i_array_p;
  v3 = result_pp;
  v4 = scope_p;
  v5 = scope_p->i_scope_p.i_obj_p;
  if ( !v5 || v4->i_scope_p.i_ptr_id != v5->i_ptr_id )
    v5 = 0i64;
  v6 = AString::increment((AString *)&v5[2], (*v2)->i_data_p->i_user_data, v2[1]->i_data_p->i_user_data);
  if ( v3 )
    *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
}

// File Line: 468
// RVA: 0x122D40
void __fastcall SSString::mthd_is_empty(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(LODWORD(v2[2].vfptr->get_obj_type) == 0);
  }
}

// File Line: 486
// RVA: 0x122DC0
void __fastcall SSString::mthd_is_filled(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(LODWORD(v2[2].vfptr->get_obj_type) != 0);
  }
}

// File Line: 504
// RVA: 0x122E90
void __fastcall SSString::mthd_lowercase(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rax
  SSObjectBase *v4; // rbx
  __int64 v5; // rdi
  unsigned __int8 *v6; // rcx
  unsigned __int8 *i; // rdx
  __int64 v8; // rax

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = v2 + 2;
  v5 = LODWORD(v3->get_obj_type);
  if ( (_DWORD)v5 )
  {
    if ( LOWORD(v3->is_actor) + BYTE3(v3->is_actor) != 1 )
      AString::make_writeable((AString *)&v2[2]);
    v6 = (unsigned __int8 *)v4->vfptr->__vecDelDtor;
    for ( i = &v6[v5]; v6 < i; *(v6 - 1) = AString::c_char2lower[v8] )
      v8 = *v6++;
  }
}

// File Line: 517
// RVA: 0x125EB0
void __fastcall SSString::mthd_uppercase(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rax
  SSObjectBase *v4; // rbx
  __int64 v5; // rdi
  unsigned __int8 *v6; // rcx
  unsigned __int8 *i; // rdx
  __int64 v8; // rax

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  v4 = v2 + 2;
  v5 = LODWORD(v3->get_obj_type);
  if ( (_DWORD)v5 )
  {
    if ( LOWORD(v3->is_actor) + BYTE3(v3->is_actor) != 1 )
      AString::make_writeable((AString *)&v2[2]);
    v6 = (unsigned __int8 *)v4->vfptr->__vecDelDtor;
    for ( i = &v6[v5]; v6 < i; *(v6 - 1) = AString::c_char2uppper[v8] )
      v8 = *v6++;
  }
}

