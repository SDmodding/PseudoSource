// File Line: 42
// RVA: 0x134670
void __fastcall SSInteger::register_atomic(__int64 a1, SSMethodBase **a2, __int64 a3, __int64 i_uid)
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
  SSClass *v119; // rbx
  ASymbol *v120; // rax
  SSClass *v121; // rbx
  ASymbol *v122; // rax
  SSClass *v123; // rbx
  ASymbol *v124; // rax
  SSClass *v125; // rbx
  ASymbol *v126; // rax
  __int64 result; // [rsp+70h] [rbp+40h] BYREF
  SSParameters *v128; // [rsp+78h] [rbp+48h]
  __int64 v129; // [rsp+80h] [rbp+50h]

  i_array_p = (SSMethodBase **)SSBrain::c_integer_class_p;
  i_count = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v6 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_Integer.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_10;
        v6 = a2 - 1;
      }
      v7 = ASymbol_Integer.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_Integer.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v8 + 32) = SSInteger::mthd_as_copy;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      v128 = v10;
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
      v129 = v8;
      *(ASymbol *)(v8 + 8) = ASymbol_Integer;
      *(_QWORD *)(v8 + 16) = v9;
      *(_QWORD *)v8 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v8 + 24) = v10;
      if ( v10 )
        ++v10->i_ref_count;
      *(_QWORD *)v8 = &SSMethodBase::`vftable;
      *(_QWORD *)v8 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v8 + 32) = SSInteger::mthd_as_copy;
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
  v13 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v14 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v13 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v15 = &v13[v14 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v13[((char *)v15 - (char *)v13) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_Boolean.i_uid >= (unsigned int)i_uid )
          break;
        if ( v13 == a2 )
          goto LABEL_34;
        v15 = a2 - 1;
      }
      v16 = ASymbol_Boolean.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_Boolean.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v17 + 32) = SSInteger::mthd_Boolean;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      v128 = v19;
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
      v129 = v17;
      *(ASymbol *)(v17 + 8) = ASymbol_Boolean;
      *(_QWORD *)(v17 + 16) = v18;
      *(_QWORD *)v17 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v17 + 24) = v19;
      if ( v19 )
        ++v19->i_ref_count;
      *(_QWORD *)v17 = &SSMethodBase::`vftable;
      *(_QWORD *)v17 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v17 + 32) = SSInteger::mthd_Boolean;
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
  v21 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v22 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    v21 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v23 = &v21[v22 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v21[((char *)v23 - (char *)v21) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_Real.i_uid >= (unsigned int)i_uid )
          break;
        if ( v21 == a2 )
          goto LABEL_58;
        v23 = a2 - 1;
      }
      v24 = ASymbol_Real.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_Real.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v25 + 32) = SSInteger::mthd_as_real;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v128 = v27;
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
      v129 = v25;
      *(ASymbol *)(v25 + 8) = ASymbol_Real;
      *(_QWORD *)(v25 + 16) = v26;
      *(_QWORD *)v25 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v25 + 24) = v27;
      if ( v27 )
        ++v27->i_ref_count;
      *(_QWORD *)v25 = &SSMethodBase::`vftable;
      *(_QWORD *)v25 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v25 + 32) = SSInteger::mthd_as_real;
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
  v29 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v30 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v30 )
  {
    v29 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v31 = &v29[v30 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v29[((char *)v31 - (char *)v29) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= (unsigned int)i_uid )
          break;
        if ( v29 == a2 )
          goto LABEL_82;
        v31 = a2 - 1;
      }
      v32 = ASymbol_String.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_String.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v33 + 32) = SSInteger::mthd_as_string;
    }
    else
    {
      v34 = *(_QWORD *)(v33 + 16);
      v35 = *(SSParameters **)(v33 + 24);
      v128 = v35;
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
      v129 = v33;
      *(ASymbol *)(v33 + 8) = ASymbol_String;
      *(_QWORD *)(v33 + 16) = v34;
      *(_QWORD *)v33 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v33 + 24) = v35;
      if ( v35 )
        ++v35->i_ref_count;
      *(_QWORD *)v33 = &SSMethodBase::`vftable;
      *(_QWORD *)v33 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v33 + 32) = SSInteger::mthd_as_string;
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
  v37 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v38 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v38 )
  {
    v37 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v39 = &v37[v38 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v37[((char *)v39 - (char *)v37) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add.i_uid >= (unsigned int)i_uid )
          break;
        if ( v37 == a2 )
          goto LABEL_106;
        v39 = a2 - 1;
      }
      v40 = ASymbol_add.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v41 + 32) = SSInteger::mthd_op_add;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      v128 = v43;
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
      v129 = v41;
      *(ASymbol *)(v41 + 8) = ASymbol_add;
      *(_QWORD *)(v41 + 16) = v42;
      *(_QWORD *)v41 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v41 + 24) = v43;
      if ( v43 )
        ++v43->i_ref_count;
      *(_QWORD *)v41 = &SSMethodBase::`vftable;
      *(_QWORD *)v41 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v41 + 32) = SSInteger::mthd_op_add;
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
  v45 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v46 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v46 )
  {
    v45 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v47 = &v45[v46 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v45[((char *)v47 - (char *)v45) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v45 == a2 )
          goto LABEL_130;
        v47 = a2 - 1;
      }
      v48 = ASymbol_add_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add_assign.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v49 + 32) = SSInteger::mthd_op_add_assign;
    }
    else
    {
      v50 = *(_QWORD *)(v49 + 16);
      v51 = *(SSParameters **)(v49 + 24);
      v128 = v51;
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
      v129 = v49;
      *(ASymbol *)(v49 + 8) = ASymbol_add_assign;
      *(_QWORD *)(v49 + 16) = v50;
      *(_QWORD *)v49 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v49 + 24) = v51;
      if ( v51 )
        ++v51->i_ref_count;
      *(_QWORD *)v49 = &SSMethodBase::`vftable;
      *(_QWORD *)v49 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v49 + 32) = SSInteger::mthd_op_add_assign;
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
  v53 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v54 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v54 )
  {
    v53 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v55 = &v53[v54 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v53[((char *)v55 - (char *)v53) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v53 == a2 )
          goto LABEL_154;
        v55 = a2 - 1;
      }
      v56 = ASymbol_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_assign.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v57 + 32) = SSReal::mthd_op_assign;
    }
    else
    {
      v58 = *(_QWORD *)(v57 + 16);
      v59 = *(SSParameters **)(v57 + 24);
      v128 = v59;
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
      v129 = v57;
      *(ASymbol *)(v57 + 8) = ASymbol_assign;
      *(_QWORD *)(v57 + 16) = v58;
      *(_QWORD *)v57 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v57 + 24) = v59;
      if ( v59 )
        ++v59->i_ref_count;
      *(_QWORD *)v57 = &SSMethodBase::`vftable;
      *(_QWORD *)v57 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v57 + 32) = SSReal::mthd_op_assign;
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
  v61 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v62 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v62 )
  {
    v61 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v63 = &v61[v62 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v61[((char *)v63 - (char *)v61) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_decrement.i_uid >= (unsigned int)i_uid )
          break;
        if ( v61 == a2 )
          goto LABEL_178;
        v63 = a2 - 1;
      }
      v64 = ASymbol_decrement.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_decrement.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v65 + 32) = SSInteger::mthd_op_decrement;
    }
    else
    {
      v66 = *(_QWORD *)(v65 + 16);
      v67 = *(SSParameters **)(v65 + 24);
      v128 = v67;
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
      v129 = v65;
      *(ASymbol *)(v65 + 8) = ASymbol_decrement;
      *(_QWORD *)(v65 + 16) = v66;
      *(_QWORD *)v65 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v65 + 24) = v67;
      if ( v67 )
        ++v67->i_ref_count;
      *(_QWORD *)v65 = &SSMethodBase::`vftable;
      *(_QWORD *)v65 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v65 + 32) = SSInteger::mthd_op_decrement;
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
  v69 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v70 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v70 )
  {
    v69 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v71 = &v69[v70 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v69[((char *)v71 - (char *)v69) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_divide.i_uid >= (unsigned int)i_uid )
          break;
        if ( v69 == a2 )
          goto LABEL_202;
        v71 = a2 - 1;
      }
      v72 = ASymbol_divide.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_divide.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v73 + 32) = SSInteger::mthd_op_divide;
    }
    else
    {
      v74 = *(_QWORD *)(v73 + 16);
      v75 = *(SSParameters **)(v73 + 24);
      v128 = v75;
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
      v129 = v73;
      *(ASymbol *)(v73 + 8) = ASymbol_divide;
      *(_QWORD *)(v73 + 16) = v74;
      *(_QWORD *)v73 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v73 + 24) = v75;
      if ( v75 )
        ++v75->i_ref_count;
      *(_QWORD *)v73 = &SSMethodBase::`vftable;
      *(_QWORD *)v73 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v73 + 32) = SSInteger::mthd_op_divide;
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
  v77 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v78 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v78 )
  {
    v77 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v79 = &v77[v78 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v77[((char *)v79 - (char *)v77) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_divide_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v77 == a2 )
          goto LABEL_226;
        v79 = a2 - 1;
      }
      v80 = ASymbol_divide_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_divide_assign.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v81 + 32) = SSInteger::mthd_op_divide_assign;
    }
    else
    {
      v82 = *(_QWORD *)(v81 + 16);
      v83 = *(SSParameters **)(v81 + 24);
      v128 = v83;
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
      v129 = v81;
      *(ASymbol *)(v81 + 8) = ASymbol_divide_assign;
      *(_QWORD *)(v81 + 16) = v82;
      *(_QWORD *)v81 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v81 + 24) = v83;
      if ( v83 )
        ++v83->i_ref_count;
      *(_QWORD *)v81 = &SSMethodBase::`vftable;
      *(_QWORD *)v81 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v81 + 32) = SSInteger::mthd_op_divide_assign;
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
  v85 = (SSMethodBase **)SSBrain::c_integer_class_p;
  v86 = SSBrain::c_integer_class_p->i_methods.i_count;
  if ( (_DWORD)v86 )
  {
    v85 = SSBrain::c_integer_class_p->i_methods.i_array_p;
    v87 = &v85[v86 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v85[((char *)v87 - (char *)v85) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_equals.i_uid >= (unsigned int)i_uid )
          break;
        if ( v85 == a2 )
          goto LABEL_250;
        v87 = a2 - 1;
      }
      v88 = ASymbol_equals.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_equals.i_uid != (_DWORD)i_uid;
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
      *(_QWORD *)(v89 + 32) = SSInteger::mthd_op_equals;
    }
    else
    {
      v90 = *(_QWORD *)(v89 + 16);
      v91 = *(SSParameters **)(v89 + 24);
      v128 = v91;
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
      v129 = v89;
      *(ASymbol *)(v89 + 8) = ASymbol_equals;
      *(_QWORD *)(v89 + 16) = v90;
      *(_QWORD *)v89 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v89 + 24) = v91;
      if ( v91 )
        ++v91->i_ref_count;
      *(_QWORD *)v89 = &SSMethodBase::`vftable;
      *(_QWORD *)v89 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v89 + 32) = SSInteger::mthd_op_equals;
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
    SSBrain::c_integer_class_p,
    &ASymbol_greater,
    SSInteger::mthd_op_greater,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_greater_or_equal,
    SSInteger::mthd_op_greater_or_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_increment,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSInteger::mthd_op_increment,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_less,
    SSInteger::mthd_op_less,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_less_or_equal,
    SSInteger::mthd_op_less_or_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_multiply,
    SSInteger::mthd_op_multiply,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_multiply_assign,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSInteger::mthd_op_multiply_assign,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_not_equal,
    SSInteger::mthd_op_not_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_subtract,
    SSInteger::mthd_op_subtract,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_subtract_assign,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSInteger::mthd_op_subtract_assign,
    SSBindFlag_instance_no_rebind);
  v93 = SSBrain::c_integer_class_p;
  v94 = ASymbol::create((ASymbol *)&result, "abs", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v93, v94, SSInteger::mthd_abs, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_integer_class_p,
    &ASymbol_as_copy,
    SSInteger::mthd_as_copy,
    SSBindFlag_instance_no_rebind);
  v95 = SSBrain::c_integer_class_p;
  v96 = ASymbol::create((ASymbol *)&result, "bit_and", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v95, v96, SSInteger::mthd_bit_and, SSBindFlag_instance_no_rebind);
  v97 = SSBrain::c_integer_class_p;
  v98 = ASymbol::create((ASymbol *)&result, "bit_not", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v97, v98, SSInteger::mthd_bit_not, SSBindFlag_instance_no_rebind);
  v99 = SSBrain::c_integer_class_p;
  v100 = ASymbol::create((ASymbol *)&result, "bit_or", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v99, v100, SSInteger::mthd_bit_or, SSBindFlag_instance_no_rebind);
  v101 = SSBrain::c_integer_class_p;
  v102 = ASymbol::create((ASymbol *)&result, "bit_shift_down", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v101, v102, SSInteger::mthd_bit_shift_down, SSBindFlag_instance_no_rebind);
  v103 = SSBrain::c_integer_class_p;
  v104 = ASymbol::create((ASymbol *)&result, "bit_shift_up", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v103, v104, SSInteger::mthd_bit_shift_up, SSBindFlag_instance_no_rebind);
  v105 = SSBrain::c_integer_class_p;
  v106 = ASymbol::create((ASymbol *)&result, "bit_xor", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v105, v106, SSInteger::mthd_bit_xor, SSBindFlag_instance_no_rebind);
  v107 = SSBrain::c_integer_class_p;
  v108 = ASymbol::create((ASymbol *)&result, "clamp", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v107, v108, SSInteger::mthd_clamp, SSBindFlag_instance_no_rebind);
  v109 = SSBrain::c_integer_class_p;
  v110 = ASymbol::create((ASymbol *)&result, "is_between", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v109, v110, SSInteger::mthd_is_between, SSBindFlag_instance_no_rebind);
  v111 = SSBrain::c_integer_class_p;
  v112 = ASymbol::create((ASymbol *)&result, "is_bit_set", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v111, v112, SSInteger::mthd_is_bit_set, SSBindFlag_instance_no_rebind);
  v113 = SSBrain::c_integer_class_p;
  v114 = ASymbol::create((ASymbol *)&result, "is_pow2", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v113, v114, SSInteger::mthd_is_pow2, SSBindFlag_instance_no_rebind);
  v115 = SSBrain::c_integer_class_p;
  v116 = ASymbol::create((ASymbol *)&result, "max", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v115, v116, SSInteger::mthd_max, SSBindFlag_instance_no_rebind);
  v117 = SSBrain::c_integer_class_p;
  v118 = ASymbol::create((ASymbol *)&result, "min", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v117, v118, SSInteger::mthd_min, SSBindFlag_instance_no_rebind);
  v119 = SSBrain::c_integer_class_p;
  v120 = ASymbol::create((ASymbol *)&result, "mod", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v119, v120, SSInteger::mthd_mod, SSBindFlag_instance_no_rebind);
  v121 = SSBrain::c_integer_class_p;
  v122 = ASymbol::create((ASymbol *)&result, "negated", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v121, v122, SSInteger::mthd_negated, SSBindFlag_instance_no_rebind);
  v123 = SSBrain::c_integer_class_p;
  v124 = ASymbol::create((ASymbol *)&result, "sign", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v123, v124, SSInteger::mthd_sign, SSBindFlag_instance_no_rebind);
  v125 = SSBrain::c_integer_class_p;
  v126 = ASymbol::create((ASymbol *)&result, "swap", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v125,
    v126,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSInteger::mthd_swap,
    SSBindFlag_instance_no_rebind);
}

// File Line: 93
// RVA: 0x120900
void __fastcall SSInteger::mthd_abs(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  int vfptr; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (int)i_obj_p[2].vfptr;
    if ( vfptr < 0 )
      vfptr = -vfptr;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)vfptr);
  }
}

// File Line: 128
// RVA: 0x120170
void __fastcall SSInteger::mthd_Boolean(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) != 0);
  }
}

// File Line: 149
// RVA: 0x120FD0
void __fastcall SSInteger::mthd_as_real(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(SSBrain::c_real_class_p, COERCE_UNSIGNED_INT((float)SLODWORD(i_obj_p[2].vfptr)));
  }
}

// File Line: 170
// RVA: 0x1216C0
void __fastcall SSInteger::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  AString *v4; // rdi
  SSInstance *v5; // rax
  AStringRef *i_str_ref_p; // rcx
  AStringRef *v7; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString result; // [rsp+48h] [rbp+10h] BYREF
  SSInstance *v15; // [rsp+50h] [rbp+18h]
  unsigned __int64 *p_i_user_data; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v4 = AString::ctor_int(&result, (int)i_obj_p[2].vfptr, 0xAu);
    v5 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v15 = v5;
    p_i_user_data = &v5->i_user_data;
    if ( v5 != (SSInstance *)-32i64 )
    {
      i_str_ref_p = v4->i_str_ref_p;
      v5->i_user_data = (unsigned __int64)v4->i_str_ref_p;
      ++i_str_ref_p->i_ref_count;
    }
    *result_pp = v5;
    v7 = result.i_str_ref_p;
    if ( result.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( v7->i_deallocate )
        AMemory::c_free_func(v7->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v7 < i_objects_a
        || (v12 = (unsigned __int64)v7 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v12) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v7);
    }
  }
}

// File Line: 187
// RVA: 0x121920
void __fastcall SSInteger::mthd_bit_and(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data) & (unsigned __int64)SLODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 206
// RVA: 0x121970
void __fastcall SSInteger::mthd_bit_not(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, ~LODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 225
// RVA: 0x1219C0
void __fastcall SSInteger::mthd_bit_or(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data) | (unsigned __int64)SLODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 244
// RVA: 0x121A10
void __fastcall SSInteger::mthd_bit_shift_down(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   SLODWORD(i_obj_p[2].vfptr) >> LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 263
// RVA: 0x121A60
void __fastcall SSInteger::mthd_bit_shift_up(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   (int)(LODWORD(i_obj_p[2].vfptr) << LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data)));
  }
}

// File Line: 282
// RVA: 0x121AB0
void __fastcall SSInteger::mthd_bit_xor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data) ^ (unsigned __int64)SLODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 301
// RVA: 0x121B00
void __fastcall SSInteger::mthd_clamp(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rdx
  SSInstance *v6; // rcx
  int vfptr; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_array_p = scope_p->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v6 = i_array_p[1]->i_data_p;
    vfptr = (int)i_obj_p[2].vfptr;
    if ( vfptr >= SLODWORD(i_data_p->i_user_data) )
    {
      i_data_p = (SSInstance *)i_obj_p;
      if ( vfptr > SLODWORD(v6->i_user_data) )
        i_data_p = v6;
    }
    ++i_data_p->i_ref_count;
    *result_pp = i_data_p;
  }
}

// File Line: 329
// RVA: 0x122C40
void __fastcall SSInteger::mthd_is_between(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  int vfptr; // edx
  SSData **i_array_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (int)i_obj_p[2].vfptr;
    i_array_p = scope_p->i_data.i_array_p;
    if ( vfptr < SLODWORD((*i_array_p)->i_data_p->i_user_data) || vfptr > SLODWORD(i_array_p[1]->i_data_p->i_user_data) )
      *result_pp = SSBoolean::pool_new(0);
    else
      *result_pp = SSBoolean::pool_new(1);
  }
}

// File Line: 350
// RVA: 0x122CB0
void __fastcall SSInteger::mthd_is_bit_set(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new((SLODWORD((*i_array_p)->i_data_p->i_user_data) >> LODWORD(i_obj_p[2].vfptr)) & 1);
  }
}

// File Line: 369
// RVA: 0x122E00
void __fastcall SSInteger::mthd_is_pow2(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(((LODWORD(i_obj_p[2].vfptr) - 1) & (__int64)i_obj_p[2].vfptr) == 0);
  }
}

// File Line: 387
// RVA: 0x122F10
void __fastcall SSInteger::mthd_max(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSInstance *i_data_p; // rdx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    if ( SLODWORD(i_obj_p[2].vfptr) >= SLODWORD(i_data_p->i_user_data) )
      i_data_p = (SSInstance *)i_obj_p;
    ++i_data_p->i_ref_count;
    *result_pp = i_data_p;
  }
}

// File Line: 411
// RVA: 0x122F50
void __fastcall SSInteger::mthd_min(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSInstance *i_data_p; // rdx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    if ( SLODWORD(i_obj_p[2].vfptr) <= SLODWORD(i_data_p->i_user_data) )
      i_data_p = (SSInstance *)i_obj_p;
    ++i_data_p->i_ref_count;
    *result_pp = i_data_p;
  }
}

// File Line: 435
// RVA: 0x122F90
void __fastcall SSInteger::mthd_mod(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   SLODWORD(i_obj_p[2].vfptr) % SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 454
// RVA: 0x122FE0
void __fastcall SSInteger::mthd_negated(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)-LODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 480
// RVA: 0x123910
void __fastcall SSReal::mthd_op_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(i_obj_p[2].vfptr) = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(i_obj_p[2].vfptr) = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 512
// RVA: 0x1240A0
void __fastcall SSInteger::mthd_op_increment(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    ++LODWORD(i_obj_p[2].vfptr);
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    ++LODWORD(i_obj_p[2].vfptr);
  }
}

// File Line: 544
// RVA: 0x123970
void __fastcall SSInteger::mthd_op_decrement(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    --LODWORD(i_obj_p[2].vfptr);
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    --LODWORD(i_obj_p[2].vfptr);
  }
}

// File Line: 576
// RVA: 0x1232D0
void __fastcall SSInteger::mthd_op_add(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data) + LODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 602
// RVA: 0x123600
void __fastcall SSInteger::mthd_op_add_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(i_obj_p[2].vfptr) += LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(i_obj_p[2].vfptr) += LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 634
// RVA: 0x124870
void __fastcall SSInteger::mthd_op_subtract(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   LODWORD(i_obj_p[2].vfptr) - LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 660
// RVA: 0x124930
void __fastcall SSInteger::mthd_op_subtract_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(i_obj_p[2].vfptr) -= LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(i_obj_p[2].vfptr) -= LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 692
// RVA: 0x124400
void __fastcall SSInteger::mthd_op_multiply(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data) * LODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 718
// RVA: 0x1244C0
void __fastcall SSInteger::mthd_op_multiply_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(i_obj_p[2].vfptr) *= LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(i_obj_p[2].vfptr) *= LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 750
// RVA: 0x123A10
void __fastcall SSInteger::mthd_op_divide(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   SLODWORD(i_obj_p[2].vfptr) / SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 776
// RVA: 0x123AD0
void __fastcall SSInteger::mthd_op_divide_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r9

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    SLODWORD(i_obj_p[2].vfptr) /= SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    SLODWORD(i_obj_p[2].vfptr) /= SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 808
// RVA: 0x123C00
void __fastcall SSInteger::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) == LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 833
// RVA: 0x124630
void __fastcall SSInteger::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) != LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 858
// RVA: 0x123DE0
void __fastcall SSInteger::mthd_op_greater(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(SLODWORD(i_obj_p[2].vfptr) > SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 883
// RVA: 0x123F40
void __fastcall SSInteger::mthd_op_greater_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(SLODWORD(i_obj_p[2].vfptr) >= SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 908
// RVA: 0x124140
void __fastcall SSInteger::mthd_op_less(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(SLODWORD(i_obj_p[2].vfptr) < SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 933
// RVA: 0x1242A0
void __fastcall SSInteger::mthd_op_less_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(SLODWORD(i_obj_p[2].vfptr) <= SLODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 951
// RVA: 0x125820
void __fastcall SSInteger::mthd_sign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  int v3; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v3 = -1;
    if ( SLODWORD(i_obj_p[2].vfptr) >= 0 )
      v3 = 1;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, v3);
  }
}

// File Line: 970
// RVA: 0x125940
void __fastcall SSInteger::mthd_swap(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSInstance *i_data_p; // rdx
  int vfptr; // ecx
  SSInstance *v6; // rdx
  int v7; // ecx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    vfptr = (int)i_obj_p[2].vfptr;
    LODWORD(i_obj_p[2].vfptr) = i_data_p->i_user_data;
    LODWORD(i_data_p->i_user_data) = vfptr;
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v6 = (*scope_p->i_data.i_array_p)->i_data_p;
    v7 = (int)i_obj_p[2].vfptr;
    LODWORD(i_obj_p[2].vfptr) = v6->i_user_data;
    LODWORD(v6->i_user_data) = v7;
  }
}

