// File Line: 36
// RVA: 0x10F210
SSInstance *__fastcall SSString::as_instance(AString *str)
{
  SSInstance *result; // rax
  AStringRef *i_str_ref_p; // rcx

  result = SSInstance::pool_new(SSBrain::c_string_class_p);
  if ( result != (SSInstance *)-32i64 )
  {
    i_str_ref_p = str->i_str_ref_p;
    result->i_user_data = (unsigned __int64)str->i_str_ref_p;
    ++i_str_ref_p->i_ref_count;
  }
  return result;
}

// File Line: 50
// RVA: 0x139240
void __fastcall SSString::register_atomic(__int64 a1, SSMethodBase **a2, __int64 a3, __int64 i_uid)
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
  __int64 result; // [rsp+70h] [rbp+40h] BYREF
  SSParameters *v108; // [rsp+78h] [rbp+48h]
  __int64 v109; // [rsp+80h] [rbp+50h]

  i_array_p = (SSMethodBase **)SSBrain::c_string_class_p;
  i_count = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_string_class_p->i_methods.i_array_p;
    v6 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbolX_dtor.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_10;
        v6 = a2 - 1;
      }
      v7 = ASymbolX_dtor.i_uid == (_DWORD)i_uid;
      i_uid = ASymbolX_dtor.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v8 + 32) = SSString::mthd_destructor;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      v108 = v10;
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
      v109 = v8;
      *(ASymbol *)(v8 + 8) = ASymbolX_dtor;
      *(_QWORD *)(v8 + 16) = v9;
      *(_QWORD *)v8 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v8 + 24) = v10;
      if ( v10 )
        ++v10->i_ref_count;
      *(_QWORD *)v8 = &SSMethodBase::`vftable;
      *(_QWORD *)v8 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v8 + 32) = SSString::mthd_destructor;
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
  v13 = (SSMethodBase **)SSBrain::c_string_class_p;
  v14 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v13 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v15 = &v13[v14 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v13[((char *)v15 - (char *)v13) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= (unsigned int)i_uid )
          break;
        if ( v13 == a2 )
          goto LABEL_34;
        v15 = a2 - 1;
      }
      v16 = ASymbol_String.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_String.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v17 + 32) = SSString::mthd_as_string;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      v108 = v19;
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
      v109 = v17;
      *(ASymbol *)(v17 + 8) = ASymbol_String;
      *(_QWORD *)(v17 + 16) = v18;
      *(_QWORD *)v17 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v17 + 24) = v19;
      if ( v19 )
        ++v19->i_ref_count;
      *(_QWORD *)v17 = &SSMethodBase::`vftable;
      *(_QWORD *)v17 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v17 + 32) = SSString::mthd_as_string;
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
  v21 = (SSMethodBase **)SSBrain::c_string_class_p;
  v22 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    v21 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v23 = &v21[v22 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v21[((char *)v23 - (char *)v21) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_Symbol.i_uid >= (unsigned int)i_uid )
          break;
        if ( v21 == a2 )
          goto LABEL_58;
        v23 = a2 - 1;
      }
      v24 = ASymbol_Symbol.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_Symbol.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v25 + 32) = SSString::mthd_as_symbol;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v108 = v27;
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
      v109 = v25;
      *(ASymbol *)(v25 + 8) = ASymbol_Symbol;
      *(_QWORD *)(v25 + 16) = v26;
      *(_QWORD *)v25 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v25 + 24) = v27;
      if ( v27 )
        ++v27->i_ref_count;
      *(_QWORD *)v25 = &SSMethodBase::`vftable;
      *(_QWORD *)v25 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v25 + 32) = SSString::mthd_as_symbol;
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
  v29 = (SSMethodBase **)SSBrain::c_string_class_p;
  v30 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v30 )
  {
    v29 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v31 = &v29[v30 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v29[((char *)v31 - (char *)v29) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add.i_uid >= (unsigned int)i_uid )
          break;
        if ( v29 == a2 )
          goto LABEL_82;
        v31 = a2 - 1;
      }
      v32 = ASymbol_add.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v33 + 32) = SSString::mthd_op_add;
    }
    else
    {
      v34 = *(_QWORD *)(v33 + 16);
      v35 = *(SSParameters **)(v33 + 24);
      v108 = v35;
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
      v109 = v33;
      *(ASymbol *)(v33 + 8) = ASymbol_add;
      *(_QWORD *)(v33 + 16) = v34;
      *(_QWORD *)v33 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v33 + 24) = v35;
      if ( v35 )
        ++v35->i_ref_count;
      *(_QWORD *)v33 = &SSMethodBase::`vftable;
      *(_QWORD *)v33 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v33 + 32) = SSString::mthd_op_add;
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
  v37 = (SSMethodBase **)SSBrain::c_string_class_p;
  v38 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v38 )
  {
    v37 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v39 = &v37[v38 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v37[((char *)v39 - (char *)v37) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v37 == a2 )
          goto LABEL_106;
        v39 = a2 - 1;
      }
      v40 = ASymbol_add_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add_assign.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v41 + 32) = SSString::mthd_op_add_assign;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      v108 = v43;
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
      v109 = v41;
      *(ASymbol *)(v41 + 8) = ASymbol_add_assign;
      *(_QWORD *)(v41 + 16) = v42;
      *(_QWORD *)v41 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v41 + 24) = v43;
      if ( v43 )
        ++v43->i_ref_count;
      *(_QWORD *)v41 = &SSMethodBase::`vftable;
      *(_QWORD *)v41 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v41 + 32) = SSString::mthd_op_add_assign;
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
  v45 = (SSMethodBase **)SSBrain::c_string_class_p;
  v46 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v46 )
  {
    v45 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v47 = &v45[v46 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v45[((char *)v47 - (char *)v45) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v45 == a2 )
          goto LABEL_130;
        v47 = a2 - 1;
      }
      v48 = ASymbol_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_assign.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v49 + 32) = SSString::mthd_op_assign;
    }
    else
    {
      v50 = *(_QWORD *)(v49 + 16);
      v51 = *(SSParameters **)(v49 + 24);
      v108 = v51;
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
      v109 = v49;
      *(ASymbol *)(v49 + 8) = ASymbol_assign;
      *(_QWORD *)(v49 + 16) = v50;
      *(_QWORD *)v49 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v49 + 24) = v51;
      if ( v51 )
        ++v51->i_ref_count;
      *(_QWORD *)v49 = &SSMethodBase::`vftable;
      *(_QWORD *)v49 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v49 + 32) = SSString::mthd_op_assign;
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
  v53 = (SSMethodBase **)SSBrain::c_string_class_p;
  v54 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v54 )
  {
    v53 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v55 = &v53[v54 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v53[((char *)v55 - (char *)v53) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_equals.i_uid >= (unsigned int)i_uid )
          break;
        if ( v53 == a2 )
          goto LABEL_154;
        v55 = a2 - 1;
      }
      v56 = ASymbol_equals.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_equals.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v57 + 32) = SSString::mthd_op_equals;
    }
    else
    {
      v58 = *(_QWORD *)(v57 + 16);
      v59 = *(SSParameters **)(v57 + 24);
      v108 = v59;
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
      v109 = v57;
      *(ASymbol *)(v57 + 8) = ASymbol_equals;
      *(_QWORD *)(v57 + 16) = v58;
      *(_QWORD *)v57 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v57 + 24) = v59;
      if ( v59 )
        ++v59->i_ref_count;
      *(_QWORD *)v57 = &SSMethodBase::`vftable;
      *(_QWORD *)v57 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v57 + 32) = SSString::mthd_op_equals;
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
  v61 = (SSMethodBase **)SSBrain::c_string_class_p;
  v62 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v62 )
  {
    v61 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v63 = &v61[v62 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v61[((char *)v63 - (char *)v61) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_greater.i_uid >= (unsigned int)i_uid )
          break;
        if ( v61 == a2 )
          goto LABEL_178;
        v63 = a2 - 1;
      }
      v64 = ASymbol_greater.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_greater.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v65 + 32) = SSString::mthd_op_greater;
    }
    else
    {
      v66 = *(_QWORD *)(v65 + 16);
      v67 = *(SSParameters **)(v65 + 24);
      v108 = v67;
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
      v109 = v65;
      *(ASymbol *)(v65 + 8) = ASymbol_greater;
      *(_QWORD *)(v65 + 16) = v66;
      *(_QWORD *)v65 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v65 + 24) = v67;
      if ( v67 )
        ++v67->i_ref_count;
      *(_QWORD *)v65 = &SSMethodBase::`vftable;
      *(_QWORD *)v65 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v65 + 32) = SSString::mthd_op_greater;
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
  v69 = (SSMethodBase **)SSBrain::c_string_class_p;
  v70 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v70 )
  {
    v69 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v71 = &v69[v70 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v69[((char *)v71 - (char *)v69) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_greater_or_equal.i_uid >= (unsigned int)i_uid )
          break;
        if ( v69 == a2 )
          goto LABEL_202;
        v71 = a2 - 1;
      }
      v72 = ASymbol_greater_or_equal.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_greater_or_equal.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v73 + 32) = SSString::mthd_op_greater_or_equal;
    }
    else
    {
      v74 = *(_QWORD *)(v73 + 16);
      v75 = *(SSParameters **)(v73 + 24);
      v108 = v75;
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
      v109 = v73;
      *(ASymbol *)(v73 + 8) = ASymbol_greater_or_equal;
      *(_QWORD *)(v73 + 16) = v74;
      *(_QWORD *)v73 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v73 + 24) = v75;
      if ( v75 )
        ++v75->i_ref_count;
      *(_QWORD *)v73 = &SSMethodBase::`vftable;
      *(_QWORD *)v73 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v73 + 32) = SSString::mthd_op_greater_or_equal;
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
  v77 = (SSMethodBase **)SSBrain::c_string_class_p;
  v78 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v78 )
  {
    v77 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v79 = &v77[v78 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v77[((char *)v79 - (char *)v77) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_less.i_uid >= (unsigned int)i_uid )
          break;
        if ( v77 == a2 )
          goto LABEL_226;
        v79 = a2 - 1;
      }
      v80 = ASymbol_less.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_less.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v81 + 32) = SSString::mthd_op_less;
    }
    else
    {
      v82 = *(_QWORD *)(v81 + 16);
      v83 = *(SSParameters **)(v81 + 24);
      v108 = v83;
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
      v109 = v81;
      *(ASymbol *)(v81 + 8) = ASymbol_less;
      *(_QWORD *)(v81 + 16) = v82;
      *(_QWORD *)v81 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v81 + 24) = v83;
      if ( v83 )
        ++v83->i_ref_count;
      *(_QWORD *)v81 = &SSMethodBase::`vftable;
      *(_QWORD *)v81 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v81 + 32) = SSString::mthd_op_less;
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
  v85 = (SSMethodBase **)SSBrain::c_string_class_p;
  v86 = SSBrain::c_string_class_p->i_methods.i_count;
  if ( (_DWORD)v86 )
  {
    v85 = SSBrain::c_string_class_p->i_methods.i_array_p;
    v87 = &v85[v86 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v85[((char *)v87 - (char *)v85) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_less_or_equal.i_uid >= (unsigned int)i_uid )
          break;
        if ( v85 == a2 )
          goto LABEL_250;
        v87 = a2 - 1;
      }
      v88 = ASymbol_less_or_equal.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_less_or_equal.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v89 + 32) = SSString::mthd_op_less_or_equal;
    }
    else
    {
      v90 = *(_QWORD *)(v89 + 16);
      v91 = *(SSParameters **)(v89 + 24);
      v108 = v91;
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
      v109 = v89;
      *(ASymbol *)(v89 + 8) = ASymbol_less_or_equal;
      *(_QWORD *)(v89 + 16) = v90;
      *(_QWORD *)v89 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v89 + 24) = v91;
      if ( v91 )
        ++v91->i_ref_count;
      *(_QWORD *)v89 = &SSMethodBase::`vftable;
      *(_QWORD *)v89 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v89 + 32) = SSString::mthd_op_less_or_equal;
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
  SSClass::register_method_func(
    SSBrain::c_string_class_p,
    &ASymbol_not_equal,
    SSString::mthd_op_not_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_string_class_p,
    &ASymbol_append,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSString::mthd_op_add_assign,
    SSBindFlag_instance_no_rebind);
  v93 = SSBrain::c_string_class_p;
  v94 = ASymbol::create((ASymbol *)&result, "as_crc32", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v93, v94, SSString::mthd_as_crc32, SSBindFlag_instance_no_rebind);
  v95 = SSBrain::c_string_class_p;
  v96 = ASymbol::create((ASymbol *)&result, "empty", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v95, v96, SSString::mthd_empty, SSBindFlag_instance_no_rebind);
  v97 = SSBrain::c_string_class_p;
  v98 = ASymbol::create((ASymbol *)&result, "enumerate", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v97, v98, SSString::mthd_enumerate, SSBindFlag_instance_no_rebind);
  v99 = SSBrain::c_string_class_p;
  v100 = ASymbol::create((ASymbol *)&result, "is_empty", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v99, v100, SSString::mthd_is_empty, SSBindFlag_instance_no_rebind);
  v101 = SSBrain::c_string_class_p;
  v102 = ASymbol::create((ASymbol *)&result, "is_filled", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v101, v102, SSString::mthd_is_filled, SSBindFlag_instance_no_rebind);
  v103 = SSBrain::c_string_class_p;
  v104 = ASymbol::create((ASymbol *)&result, "lowercase", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v103, v104, SSString::mthd_lowercase, SSBindFlag_instance_no_rebind);
  v105 = SSBrain::c_string_class_p;
  v106 = ASymbol::create((ASymbol *)&result, "uppercase", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v105, v106, SSString::mthd_uppercase, SSBindFlag_instance_no_rebind);
}

// File Line: 89
// RVA: 0x1220D0
void __fastcall SSString::mthd_destructor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rbx
  AStringRef *vfptr; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v8; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (AStringRef *)i_obj_p[2].vfptr;
  if ( vfptr->i_ref_count-- == 1 )
  {
    if ( vfptr->i_deallocate )
      AMemory::c_free_func(vfptr->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)vfptr < i_objects_a
      || (v8 = (unsigned __int64)vfptr < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v8) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, vfptr);
  }
}

// File Line: 107
// RVA: 0x121870
void __fastcall SSString::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 129
// RVA: 0x1218A0
void __fastcall SSString::mthd_as_symbol(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  ASymbol *v4; // rdi
  SSInstance *v5; // rax
  ASymbol result; // [rsp+48h] [rbp+10h] BYREF
  SSInstance *v7; // [rsp+50h] [rbp+18h]
  unsigned __int64 *p_i_user_data; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v4 = ASymbol::create(&result, (AString *)&i_obj_p[2], ATerm_long);
    v5 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    v7 = v5;
    p_i_user_data = &v5->i_user_data;
    if ( v5 != (SSInstance *)-32i64 )
      LODWORD(v5->i_user_data) = (ASymbol)v4->i_uid;
    *result_pp = v5;
  }
}

// File Line: 156
// RVA: 0x1209A0
void __fastcall SSString::mthd_op_add_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // rbx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    AString::append((AString *)&i_obj_p[2], (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    AString::append((AString *)&i_obj_p[2], (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 188
// RVA: 0x123890
void __fastcall SSString::mthd_op_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // rbx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    AString::operator=((AString *)&i_obj_p[2], (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    AString::operator=((AString *)&i_obj_p[2], (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 253
// RVA: 0x123D00
void __fastcall SSString::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_data_p; // r9
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rcx
  unsigned __int64 i_user_data; // rax
  __int64 get_obj_type_low; // rdx
  void *(__fastcall *vecDelDtor)(SSObjectBase *, unsigned int); // rcx
  void *(__fastcall *v9)(SSObjectBase *, unsigned int); // rdx
  __int64 v10; // r8

  if ( result_pp )
  {
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_user_data = i_data_p->i_user_data;
    get_obj_type_low = LODWORD(vfptr->get_obj_type);
    if ( (_DWORD)get_obj_type_low != *(_DWORD *)(i_user_data + 8) )
    {
LABEL_6:
      *result_pp = SSBoolean::pool_new(0);
      return;
    }
    vecDelDtor = vfptr->__vecDelDtor;
    if ( vecDelDtor != *(void *(__fastcall **)(SSObjectBase *, unsigned int))i_user_data )
    {
      v9 = (void *(__fastcall *)(SSObjectBase *, unsigned int))((char *)vecDelDtor + get_obj_type_low);
      if ( (unsigned __int64)vecDelDtor < (unsigned __int64)v9 )
      {
        v10 = *(_QWORD *)i_user_data - (_QWORD)vecDelDtor;
        while ( *(_BYTE *)vecDelDtor == *((_BYTE *)vecDelDtor + v10) )
        {
          vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))((char *)vecDelDtor + 1);
          if ( (unsigned __int64)vecDelDtor >= (unsigned __int64)v9 )
            goto LABEL_12;
        }
        goto LABEL_6;
      }
    }
LABEL_12:
    *result_pp = SSBoolean::pool_new(1);
  }
}

// File Line: 278
// RVA: 0x124730
void __fastcall SSString::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_data_p; // r9
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rcx
  unsigned __int64 i_user_data; // rax
  __int64 get_obj_type_low; // rdx
  void *(__fastcall *vecDelDtor)(SSObjectBase *, unsigned int); // rcx
  void *(__fastcall *v9)(SSObjectBase *, unsigned int); // rdx
  __int64 v10; // r8

  if ( result_pp )
  {
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_user_data = i_data_p->i_user_data;
    get_obj_type_low = LODWORD(vfptr->get_obj_type);
    if ( (_DWORD)get_obj_type_low != *(_DWORD *)(i_user_data + 8) )
    {
LABEL_6:
      *result_pp = SSBoolean::pool_new(1);
      return;
    }
    vecDelDtor = vfptr->__vecDelDtor;
    if ( vecDelDtor != *(void *(__fastcall **)(SSObjectBase *, unsigned int))i_user_data )
    {
      v9 = (void *(__fastcall *)(SSObjectBase *, unsigned int))((char *)vecDelDtor + get_obj_type_low);
      if ( (unsigned __int64)vecDelDtor < (unsigned __int64)v9 )
      {
        v10 = *(_QWORD *)i_user_data - (_QWORD)vecDelDtor;
        while ( *(_BYTE *)vecDelDtor == *((_BYTE *)vecDelDtor + v10) )
        {
          vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))((char *)vecDelDtor + 1);
          if ( (unsigned __int64)vecDelDtor >= (unsigned __int64)v9 )
            goto LABEL_12;
        }
        goto LABEL_6;
      }
    }
LABEL_12:
    *result_pp = SSBoolean::pool_new(0);
  }
}

// File Line: 303
// RVA: 0x123E80
void __fastcall SSString::mthd_op_greater(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx
  SSObjectBaseVtbl *vfptr; // rcx
  unsigned __int64 i_user_data; // rdx
  size_t get_obj_type_low; // r8
  const char *v9; // rdx
  int v10; // eax

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    get_obj_type_low = *(unsigned int *)(i_user_data + 8);
    v9 = *(const char **)i_user_data;
    if ( LODWORD(vfptr->get_obj_type) < (unsigned int)get_obj_type_low )
      get_obj_type_low = LODWORD(vfptr->get_obj_type);
    v10 = strncmp((const char *)vfptr->__vecDelDtor, v9, get_obj_type_low);
    *result_pp = SSBoolean::pool_new(v10 > 0);
  }
}

// File Line: 328
// RVA: 0x123FE0
void __fastcall SSString::mthd_op_greater_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx
  SSObjectBaseVtbl *vfptr; // rcx
  unsigned __int64 i_user_data; // rdx
  size_t get_obj_type_low; // r8
  const char *v9; // rdx
  int v10; // eax

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    get_obj_type_low = *(unsigned int *)(i_user_data + 8);
    v9 = *(const char **)i_user_data;
    if ( LODWORD(vfptr->get_obj_type) < (unsigned int)get_obj_type_low )
      get_obj_type_low = LODWORD(vfptr->get_obj_type);
    v10 = strncmp((const char *)vfptr->__vecDelDtor, v9, get_obj_type_low);
    *result_pp = SSBoolean::pool_new(v10 >= 0);
  }
}

// File Line: 353
// RVA: 0x1241E0
void __fastcall SSString::mthd_op_less(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx
  SSObjectBaseVtbl *vfptr; // rcx
  unsigned __int64 i_user_data; // rdx
  size_t get_obj_type_low; // r8
  const char *v9; // rdx
  int v10; // eax

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    get_obj_type_low = *(unsigned int *)(i_user_data + 8);
    v9 = *(const char **)i_user_data;
    if ( LODWORD(vfptr->get_obj_type) < (unsigned int)get_obj_type_low )
      get_obj_type_low = LODWORD(vfptr->get_obj_type);
    v10 = strncmp((const char *)vfptr->__vecDelDtor, v9, get_obj_type_low);
    *result_pp = SSBoolean::pool_new(v10 < 0);
  }
}

// File Line: 378
// RVA: 0x124340
void __fastcall SSString::mthd_op_less_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx
  SSObjectBaseVtbl *vfptr; // rcx
  unsigned __int64 i_user_data; // rdx
  size_t get_obj_type_low; // r8
  const char *v9; // rdx
  int v10; // eax

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    get_obj_type_low = *(unsigned int *)(i_user_data + 8);
    v9 = *(const char **)i_user_data;
    if ( LODWORD(vfptr->get_obj_type) < (unsigned int)get_obj_type_low )
      get_obj_type_low = LODWORD(vfptr->get_obj_type);
    v10 = strncmp((const char *)vfptr->__vecDelDtor, v9, get_obj_type_low);
    *result_pp = SSBoolean::pool_new(v10 <= 0);
  }
}

// File Line: 396
// RVA: 0x1234F0
void __fastcall SSString::mthd_op_add(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  AString v4; // [rsp+48h] [rbp+10h] BYREF
  AString *v5; // [rsp+50h] [rbp+18h]

  if ( result_pp )
  {
    v5 = &v4;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v4.i_str_ref_p = (AStringRef *)i_obj_p[2].vfptr;
    ++v4.i_str_ref_p->i_ref_count;
    AString::append(&v4, (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    *result_pp = SSInstance::pool_new(SSBrain::c_string_class_p, (unsigned __int64)v4.i_str_ref_p);
  }
}

// File Line: 418
// RVA: 0x120E80
void __fastcall SSString::mthd_as_crc32(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rcx
  unsigned int crc32_cstr; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    crc32_cstr = AChecksum::generate_crc32_cstr(
                   (const char *)i_obj_p[2].vfptr->__vecDelDtor,
                   (unsigned int)i_obj_p[2].vfptr->get_obj_type,
                   0xFFFFFFFF);
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, crc32_cstr);
  }
}

// File Line: 435
// RVA: 0x1223C0
void __fastcall SSString::mthd_empty(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rdx
  AStringRef *empty; // rax

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( LOWORD(vfptr->is_actor) + BYTE3(vfptr->is_actor) == 1 )
  {
    *(_BYTE *)vfptr->__vecDelDtor = 0;
    LODWORD(i_obj_p[2].vfptr->get_obj_type) = 0;
  }
  else
  {
    AStringRef::dereference((AStringRef *)i_obj_p[2].vfptr);
    empty = AStringRef::get_empty();
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)empty;
    ++empty->i_ref_count;
  }
}

// File Line: 448
// RVA: 0x122420
void __fastcall SSString::mthd_enumerate(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // r8
  SSObjectBase *i_obj_p; // rcx
  unsigned int v6; // eax

  i_array_p = scope_p->i_data.i_array_p;
  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  v6 = AString::increment(
         (AString *)&i_obj_p[2],
         (*i_array_p)->i_data_p->i_user_data,
         i_array_p[1]->i_data_p->i_user_data);
  if ( result_pp )
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
}

// File Line: 468
// RVA: 0x122D40
void __fastcall SSString::mthd_is_empty(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr->get_obj_type) == 0);
  }
}

// File Line: 486
// RVA: 0x122DC0
void __fastcall SSString::mthd_is_filled(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr->get_obj_type) != 0);
  }
}

// File Line: 504
// RVA: 0x122E90
void __fastcall SSString::mthd_lowercase(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rax
  SSObjectBase *v4; // rbx
  __int64 get_obj_type_low; // rdi
  unsigned __int8 *vecDelDtor; // rcx
  unsigned __int8 *i; // rdx
  __int64 v8; // rax

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  v4 = i_obj_p + 2;
  get_obj_type_low = LODWORD(vfptr->get_obj_type);
  if ( (_DWORD)get_obj_type_low )
  {
    if ( LOWORD(vfptr->is_actor) + BYTE3(vfptr->is_actor) != 1 )
      AString::make_writeable((AString *)&i_obj_p[2]);
    vecDelDtor = (unsigned __int8 *)v4->vfptr->__vecDelDtor;
    for ( i = &vecDelDtor[get_obj_type_low]; vecDelDtor < i; *(vecDelDtor - 1) = AString::c_char2lower[v8] )
      v8 = *vecDelDtor++;
  }
}

// File Line: 517
// RVA: 0x125EB0
void __fastcall SSString::mthd_uppercase(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rax
  SSObjectBase *v4; // rbx
  __int64 get_obj_type_low; // rdi
  unsigned __int8 *vecDelDtor; // rcx
  unsigned __int8 *i; // rdx
  __int64 v8; // rax

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  v4 = i_obj_p + 2;
  get_obj_type_low = LODWORD(vfptr->get_obj_type);
  if ( (_DWORD)get_obj_type_low )
  {
    if ( LOWORD(vfptr->is_actor) + BYTE3(vfptr->is_actor) != 1 )
      AString::make_writeable((AString *)&i_obj_p[2]);
    vecDelDtor = (unsigned __int8 *)v4->vfptr->__vecDelDtor;
    for ( i = &vecDelDtor[get_obj_type_low]; vecDelDtor < i; *(vecDelDtor - 1) = AString::c_char2uppper[v8] )
      v8 = *vecDelDtor++;
  }
}

