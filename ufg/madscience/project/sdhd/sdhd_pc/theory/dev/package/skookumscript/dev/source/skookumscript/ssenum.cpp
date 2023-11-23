// File Line: 77
// RVA: 0x1337E0
void SSEnum::register_atomic(void)
{
  SSClass *v0; // rax
  __int64 *v1; // rdx
  SSMethodBase **i_array_p; // r8
  __int64 v3; // r9
  SSClass *v4; // r13
  __int64 i_count; // rcx
  __int64 *v6; // r10
  _BOOL8 v7; // rax
  __int64 v8; // rdi
  __int64 v9; // r15
  SSParameters *v10; // rsi
  SSParameters *v11; // r14
  bool v12; // zf
  __int64 v13; // rax
  __int64 *v14; // r10
  _BOOL8 v15; // rcx
  __int64 v16; // rdi
  __int64 v17; // r15
  SSParameters *v18; // rsi
  SSParameters *v19; // r14
  ASymbol *v20; // rax
  __int64 *v21; // rdx
  SSMethodBase **v22; // r8
  __int64 v23; // r9
  __int64 v24; // rax
  __int64 *v25; // r10
  _BOOL8 v26; // rcx
  __int64 v27; // rdi
  __int64 v28; // r15
  SSParameters *v29; // rsi
  SSParameters *v30; // r14
  __int64 v31; // rax
  __int64 *v32; // r10
  _BOOL8 v33; // rcx
  __int64 v34; // rdi
  __int64 v35; // r15
  SSParameters *v36; // rsi
  SSParameters *v37; // r14
  __int64 v38; // rax
  __int64 *v39; // r10
  _BOOL8 v40; // rcx
  __int64 v41; // rdi
  __int64 v42; // r15
  SSParameters *v43; // rsi
  SSParameters *v44; // r14
  __int64 v45; // rax
  __int64 *v46; // r10
  _BOOL8 v47; // rcx
  __int64 v48; // rdi
  __int64 v49; // r15
  SSParameters *v50; // rsi
  SSParameters *v51; // r14
  __int64 v52; // rax
  __int64 *v53; // r10
  _BOOL8 v54; // rcx
  __int64 v55; // rdi
  __int64 v56; // r15
  SSParameters *v57; // rsi
  SSParameters *v58; // r14
  __int64 v59; // rax
  __int64 *v60; // r10
  _BOOL8 v61; // rcx
  __int64 v62; // rdi
  __int64 v63; // r15
  SSParameters *v64; // rsi
  SSParameters *v65; // r14
  __int64 v66; // rax
  __int64 *v67; // r10
  _BOOL8 v68; // rcx
  __int64 v69; // rdi
  __int64 v70; // r15
  SSParameters *v71; // rsi
  SSParameters *v72; // r14
  __int64 v73; // rax
  __int64 *v74; // r10
  _BOOL8 v75; // rcx
  __int64 v76; // rdi
  __int64 v77; // r15
  SSParameters *v78; // rsi
  SSParameters *v79; // r14
  __int64 v80; // rax
  __int64 *v81; // r10
  _BOOL8 v82; // rcx
  __int64 v83; // rdi
  __int64 v84; // r15
  SSParameters *v85; // rsi
  SSParameters *v86; // r14
  ASymbol *v87; // rax
  ASymbol *v88; // rax
  ASymbol *v89; // rax
  __int64 result; // [rsp+70h] [rbp+40h] BYREF
  SSParameters *v91; // [rsp+78h] [rbp+48h]
  __int64 v92; // [rsp+80h] [rbp+50h]

  v0 = SSBrain::get_class("Enum");
  v4 = v0;
  i_count = v0->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = v0->i_methods.i_array_p;
    v6 = (__int64 *)&i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v1 = (__int64 *)&i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
        v3 = *(unsigned int *)(*v1 + 8);
        if ( ASymbolX_ctor.i_uid >= (unsigned int)v3 )
          break;
        if ( i_array_p == (SSMethodBase **)v1 )
          goto LABEL_10;
        v6 = v1 - 1;
      }
      v7 = ASymbolX_ctor.i_uid == (_DWORD)v3;
      v3 = ASymbolX_ctor.i_uid != (_DWORD)v3;
      if ( v7 )
        break;
      if ( v6 == v1 )
        goto LABEL_10;
      i_array_p = (SSMethodBase **)(v1 + 1);
    }
    v8 = *v1;
  }
  else
  {
LABEL_10:
    v8 = 0i64;
  }
  result = v8;
  if ( v8 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64, __int64))(*(_QWORD *)v8 + 16i64))(
           v8,
           v1,
           i_array_p,
           v3,
           -2i64) == 1 )
    {
      *(_QWORD *)(v8 + 32) = SSEnum::mthd_ctor;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      v91 = v10;
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
      v92 = v8;
      *(ASymbol *)(v8 + 8) = ASymbolX_ctor;
      *(_QWORD *)(v8 + 16) = v9;
      *(_QWORD *)v8 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v8 + 24) = v10;
      if ( v10 )
        ++v10->i_ref_count;
      *(_QWORD *)v8 = &SSMethodBase::`vftable;
      *(_QWORD *)v8 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v8 + 32) = SSEnum::mthd_ctor;
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
  v13 = v4->i_methods.i_count;
  if ( (_DWORD)v13 )
  {
    i_array_p = v4->i_methods.i_array_p;
    v14 = (__int64 *)&i_array_p[v13 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v1 = (__int64 *)&i_array_p[((char *)v14 - (char *)i_array_p) >> 4];
        v3 = *(unsigned int *)(*v1 + 8);
        if ( ASymbolX_ctor_copy.i_uid >= (unsigned int)v3 )
          break;
        if ( i_array_p == (SSMethodBase **)v1 )
          goto LABEL_34;
        v14 = v1 - 1;
      }
      v15 = ASymbolX_ctor_copy.i_uid == (_DWORD)v3;
      v3 = ASymbolX_ctor_copy.i_uid != (_DWORD)v3;
      if ( v15 )
        break;
      if ( v14 == v1 )
        goto LABEL_34;
      i_array_p = (SSMethodBase **)(v1 + 1);
    }
    v16 = *v1;
  }
  else
  {
LABEL_34:
    v16 = 0i64;
  }
  result = v16;
  if ( v16 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v16 + 16i64))(
           v16,
           v1,
           i_array_p,
           v3) == 1 )
    {
      *(_QWORD *)(v16 + 32) = SSReal::mthd_ctor_copy;
    }
    else
    {
      v17 = *(_QWORD *)(v16 + 16);
      v18 = *(SSParameters **)(v16 + 24);
      v91 = v18;
      if ( v18 )
        ++v18->i_ref_count;
      v19 = *(SSParameters **)(v16 + 24);
      if ( v19 )
      {
        v12 = v19->i_ref_count-- == 1;
        if ( v12 )
        {
          v19->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v19);
          AMemory::c_free_func(v19);
        }
        *(_QWORD *)(v16 + 24) = 0i64;
      }
      v92 = v16;
      *(ASymbol *)(v16 + 8) = ASymbolX_ctor_copy;
      *(_QWORD *)(v16 + 16) = v17;
      *(_QWORD *)v16 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v16 + 24) = v18;
      if ( v18 )
        ++v18->i_ref_count;
      *(_QWORD *)v16 = &SSMethodBase::`vftable;
      *(_QWORD *)v16 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v16 + 32) = SSReal::mthd_ctor_copy;
      if ( v18 )
      {
        v12 = v18->i_ref_count-- == 1;
        if ( v12 )
        {
          v18->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v18);
          AMemory::c_free_func(v18);
        }
      }
    }
  }
  v20 = ASymbol::create((ASymbol *)&result, "!int", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v4, v20, SSReal::mthd_ctor_copy, SSBindFlag_instance_no_rebind);
  v24 = v4->i_methods.i_count;
  if ( (_DWORD)v24 )
  {
    v22 = v4->i_methods.i_array_p;
    v25 = (__int64 *)&v22[v24 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v25 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_Integer.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_58;
        v25 = v21 - 1;
      }
      v26 = ASymbol_Integer.i_uid == (_DWORD)v23;
      v23 = ASymbol_Integer.i_uid != (_DWORD)v23;
      if ( v26 )
        break;
      if ( v25 == v21 )
        goto LABEL_58;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v27 = *v21;
  }
  else
  {
LABEL_58:
    v27 = 0i64;
  }
  result = v27;
  if ( v27 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v27 + 16i64))(
           v27,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v27 + 32) = SSInteger::mthd_as_copy;
    }
    else
    {
      v28 = *(_QWORD *)(v27 + 16);
      v29 = *(SSParameters **)(v27 + 24);
      v91 = v29;
      if ( v29 )
        ++v29->i_ref_count;
      v30 = *(SSParameters **)(v27 + 24);
      if ( v30 )
      {
        v12 = v30->i_ref_count-- == 1;
        if ( v12 )
        {
          v30->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v30);
          AMemory::c_free_func(v30);
        }
        *(_QWORD *)(v27 + 24) = 0i64;
      }
      v92 = v27;
      *(ASymbol *)(v27 + 8) = ASymbol_Integer;
      *(_QWORD *)(v27 + 16) = v28;
      *(_QWORD *)v27 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v27 + 24) = v29;
      if ( v29 )
        ++v29->i_ref_count;
      *(_QWORD *)v27 = &SSMethodBase::`vftable;
      *(_QWORD *)v27 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v27 + 32) = SSInteger::mthd_as_copy;
      if ( v29 )
      {
        v12 = v29->i_ref_count-- == 1;
        if ( v12 )
        {
          v29->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v29);
          AMemory::c_free_func(v29);
        }
      }
    }
  }
  v31 = v4->i_methods.i_count;
  if ( (_DWORD)v31 )
  {
    v22 = v4->i_methods.i_array_p;
    v32 = (__int64 *)&v22[v31 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v32 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_String.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_82;
        v32 = v21 - 1;
      }
      v33 = ASymbol_String.i_uid == (_DWORD)v23;
      v23 = ASymbol_String.i_uid != (_DWORD)v23;
      if ( v33 )
        break;
      if ( v32 == v21 )
        goto LABEL_82;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v34 = *v21;
  }
  else
  {
LABEL_82:
    v34 = 0i64;
  }
  result = v34;
  if ( v34 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v34 + 16i64))(
           v34,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v34 + 32) = SSEnum::mthd_as_string;
    }
    else
    {
      v35 = *(_QWORD *)(v34 + 16);
      v36 = *(SSParameters **)(v34 + 24);
      v91 = v36;
      if ( v36 )
        ++v36->i_ref_count;
      v37 = *(SSParameters **)(v34 + 24);
      if ( v37 )
      {
        v12 = v37->i_ref_count-- == 1;
        if ( v12 )
        {
          v37->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v37);
          AMemory::c_free_func(v37);
        }
        *(_QWORD *)(v34 + 24) = 0i64;
      }
      v92 = v34;
      *(ASymbol *)(v34 + 8) = ASymbol_String;
      *(_QWORD *)(v34 + 16) = v35;
      *(_QWORD *)v34 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v34 + 24) = v36;
      if ( v36 )
        ++v36->i_ref_count;
      *(_QWORD *)v34 = &SSMethodBase::`vftable;
      *(_QWORD *)v34 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v34 + 32) = SSEnum::mthd_as_string;
      if ( v36 )
      {
        v12 = v36->i_ref_count-- == 1;
        if ( v12 )
        {
          v36->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v36);
          AMemory::c_free_func(v36);
        }
      }
    }
  }
  v38 = v4->i_methods.i_count;
  if ( (_DWORD)v38 )
  {
    v22 = v4->i_methods.i_array_p;
    v39 = (__int64 *)&v22[v38 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v39 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_assign.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_106;
        v39 = v21 - 1;
      }
      v40 = ASymbol_assign.i_uid == (_DWORD)v23;
      v23 = ASymbol_assign.i_uid != (_DWORD)v23;
      if ( v40 )
        break;
      if ( v39 == v21 )
        goto LABEL_106;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v41 = *v21;
  }
  else
  {
LABEL_106:
    v41 = 0i64;
  }
  result = v41;
  if ( v41 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v41 + 16i64))(
           v41,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v41 + 32) = SSReal::mthd_op_assign;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      v91 = v43;
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
      v92 = v41;
      *(ASymbol *)(v41 + 8) = ASymbol_assign;
      *(_QWORD *)(v41 + 16) = v42;
      *(_QWORD *)v41 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v41 + 24) = v43;
      if ( v43 )
        ++v43->i_ref_count;
      *(_QWORD *)v41 = &SSMethodBase::`vftable;
      *(_QWORD *)v41 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v41 + 32) = SSReal::mthd_op_assign;
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
  v45 = v4->i_methods.i_count;
  if ( (_DWORD)v45 )
  {
    v22 = v4->i_methods.i_array_p;
    v46 = (__int64 *)&v22[v45 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v46 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_decrement.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_130;
        v46 = v21 - 1;
      }
      v47 = ASymbol_decrement.i_uid == (_DWORD)v23;
      v23 = ASymbol_decrement.i_uid != (_DWORD)v23;
      if ( v47 )
        break;
      if ( v46 == v21 )
        goto LABEL_130;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v48 = *v21;
  }
  else
  {
LABEL_130:
    v48 = 0i64;
  }
  result = v48;
  if ( v48 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v48 + 16i64))(
           v48,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v48 + 32) = SSInteger::mthd_op_decrement;
    }
    else
    {
      v49 = *(_QWORD *)(v48 + 16);
      v50 = *(SSParameters **)(v48 + 24);
      v91 = v50;
      if ( v50 )
        ++v50->i_ref_count;
      v51 = *(SSParameters **)(v48 + 24);
      if ( v51 )
      {
        v12 = v51->i_ref_count-- == 1;
        if ( v12 )
        {
          v51->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v51);
          AMemory::c_free_func(v51);
        }
        *(_QWORD *)(v48 + 24) = 0i64;
      }
      v92 = v48;
      *(ASymbol *)(v48 + 8) = ASymbol_decrement;
      *(_QWORD *)(v48 + 16) = v49;
      *(_QWORD *)v48 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v48 + 24) = v50;
      if ( v50 )
        ++v50->i_ref_count;
      *(_QWORD *)v48 = &SSMethodBase::`vftable;
      *(_QWORD *)v48 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v48 + 32) = SSInteger::mthd_op_decrement;
      if ( v50 )
      {
        v12 = v50->i_ref_count-- == 1;
        if ( v12 )
        {
          v50->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v50);
          AMemory::c_free_func(v50);
        }
      }
    }
  }
  v52 = v4->i_methods.i_count;
  if ( (_DWORD)v52 )
  {
    v22 = v4->i_methods.i_array_p;
    v53 = (__int64 *)&v22[v52 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v53 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_equals.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_154;
        v53 = v21 - 1;
      }
      v54 = ASymbol_equals.i_uid == (_DWORD)v23;
      v23 = ASymbol_equals.i_uid != (_DWORD)v23;
      if ( v54 )
        break;
      if ( v53 == v21 )
        goto LABEL_154;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v55 = *v21;
  }
  else
  {
LABEL_154:
    v55 = 0i64;
  }
  result = v55;
  if ( v55 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v55 + 16i64))(
           v55,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v55 + 32) = SSInteger::mthd_op_equals;
    }
    else
    {
      v56 = *(_QWORD *)(v55 + 16);
      v57 = *(SSParameters **)(v55 + 24);
      v91 = v57;
      if ( v57 )
        ++v57->i_ref_count;
      v58 = *(SSParameters **)(v55 + 24);
      if ( v58 )
      {
        v12 = v58->i_ref_count-- == 1;
        if ( v12 )
        {
          v58->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v58);
          AMemory::c_free_func(v58);
        }
        *(_QWORD *)(v55 + 24) = 0i64;
      }
      v92 = v55;
      *(ASymbol *)(v55 + 8) = ASymbol_equals;
      *(_QWORD *)(v55 + 16) = v56;
      *(_QWORD *)v55 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v55 + 24) = v57;
      if ( v57 )
        ++v57->i_ref_count;
      *(_QWORD *)v55 = &SSMethodBase::`vftable;
      *(_QWORD *)v55 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v55 + 32) = SSInteger::mthd_op_equals;
      if ( v57 )
      {
        v12 = v57->i_ref_count-- == 1;
        if ( v12 )
        {
          v57->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v57);
          AMemory::c_free_func(v57);
        }
      }
    }
  }
  v59 = v4->i_methods.i_count;
  if ( (_DWORD)v59 )
  {
    v22 = v4->i_methods.i_array_p;
    v60 = (__int64 *)&v22[v59 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v60 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_greater.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_178;
        v60 = v21 - 1;
      }
      v61 = ASymbol_greater.i_uid == (_DWORD)v23;
      v23 = ASymbol_greater.i_uid != (_DWORD)v23;
      if ( v61 )
        break;
      if ( v60 == v21 )
        goto LABEL_178;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v62 = *v21;
  }
  else
  {
LABEL_178:
    v62 = 0i64;
  }
  result = v62;
  if ( v62 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v62 + 16i64))(
           v62,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v62 + 32) = SSInteger::mthd_op_greater;
    }
    else
    {
      v63 = *(_QWORD *)(v62 + 16);
      v64 = *(SSParameters **)(v62 + 24);
      v91 = v64;
      if ( v64 )
        ++v64->i_ref_count;
      v65 = *(SSParameters **)(v62 + 24);
      if ( v65 )
      {
        v12 = v65->i_ref_count-- == 1;
        if ( v12 )
        {
          v65->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v65);
          AMemory::c_free_func(v65);
        }
        *(_QWORD *)(v62 + 24) = 0i64;
      }
      v92 = v62;
      *(ASymbol *)(v62 + 8) = ASymbol_greater;
      *(_QWORD *)(v62 + 16) = v63;
      *(_QWORD *)v62 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v62 + 24) = v64;
      if ( v64 )
        ++v64->i_ref_count;
      *(_QWORD *)v62 = &SSMethodBase::`vftable;
      *(_QWORD *)v62 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v62 + 32) = SSInteger::mthd_op_greater;
      if ( v64 )
      {
        v12 = v64->i_ref_count-- == 1;
        if ( v12 )
        {
          v64->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v64);
          AMemory::c_free_func(v64);
        }
      }
    }
  }
  v66 = v4->i_methods.i_count;
  if ( (_DWORD)v66 )
  {
    v22 = v4->i_methods.i_array_p;
    v67 = (__int64 *)&v22[v66 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v67 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_greater_or_equal.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_202;
        v67 = v21 - 1;
      }
      v68 = ASymbol_greater_or_equal.i_uid == (_DWORD)v23;
      v23 = ASymbol_greater_or_equal.i_uid != (_DWORD)v23;
      if ( v68 )
        break;
      if ( v67 == v21 )
        goto LABEL_202;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v69 = *v21;
  }
  else
  {
LABEL_202:
    v69 = 0i64;
  }
  result = v69;
  if ( v69 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v69 + 16i64))(
           v69,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v69 + 32) = SSInteger::mthd_op_greater_or_equal;
    }
    else
    {
      v70 = *(_QWORD *)(v69 + 16);
      v71 = *(SSParameters **)(v69 + 24);
      v91 = v71;
      if ( v71 )
        ++v71->i_ref_count;
      v72 = *(SSParameters **)(v69 + 24);
      if ( v72 )
      {
        v12 = v72->i_ref_count-- == 1;
        if ( v12 )
        {
          v72->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v72);
          AMemory::c_free_func(v72);
        }
        *(_QWORD *)(v69 + 24) = 0i64;
      }
      v92 = v69;
      *(ASymbol *)(v69 + 8) = ASymbol_greater_or_equal;
      *(_QWORD *)(v69 + 16) = v70;
      *(_QWORD *)v69 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v69 + 24) = v71;
      if ( v71 )
        ++v71->i_ref_count;
      *(_QWORD *)v69 = &SSMethodBase::`vftable;
      *(_QWORD *)v69 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v69 + 32) = SSInteger::mthd_op_greater_or_equal;
      if ( v71 )
      {
        v12 = v71->i_ref_count-- == 1;
        if ( v12 )
        {
          v71->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v71);
          AMemory::c_free_func(v71);
        }
      }
    }
  }
  v73 = v4->i_methods.i_count;
  if ( (_DWORD)v73 )
  {
    v22 = v4->i_methods.i_array_p;
    v74 = (__int64 *)&v22[v73 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v74 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_increment.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_226;
        v74 = v21 - 1;
      }
      v75 = ASymbol_increment.i_uid == (_DWORD)v23;
      v23 = ASymbol_increment.i_uid != (_DWORD)v23;
      if ( v75 )
        break;
      if ( v74 == v21 )
        goto LABEL_226;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v76 = *v21;
  }
  else
  {
LABEL_226:
    v76 = 0i64;
  }
  result = v76;
  if ( v76 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v76 + 16i64))(
           v76,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v76 + 32) = SSInteger::mthd_op_increment;
    }
    else
    {
      v77 = *(_QWORD *)(v76 + 16);
      v78 = *(SSParameters **)(v76 + 24);
      v91 = v78;
      if ( v78 )
        ++v78->i_ref_count;
      v79 = *(SSParameters **)(v76 + 24);
      if ( v79 )
      {
        v12 = v79->i_ref_count-- == 1;
        if ( v12 )
        {
          v79->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v79);
          AMemory::c_free_func(v79);
        }
        *(_QWORD *)(v76 + 24) = 0i64;
      }
      v92 = v76;
      *(ASymbol *)(v76 + 8) = ASymbol_increment;
      *(_QWORD *)(v76 + 16) = v77;
      *(_QWORD *)v76 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v76 + 24) = v78;
      if ( v78 )
        ++v78->i_ref_count;
      *(_QWORD *)v76 = &SSMethodBase::`vftable;
      *(_QWORD *)v76 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v76 + 32) = SSInteger::mthd_op_increment;
      if ( v78 )
      {
        v12 = v78->i_ref_count-- == 1;
        if ( v12 )
        {
          v78->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v78);
          AMemory::c_free_func(v78);
        }
      }
    }
  }
  v80 = v4->i_methods.i_count;
  if ( (_DWORD)v80 )
  {
    v22 = v4->i_methods.i_array_p;
    v81 = (__int64 *)&v22[v80 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = (__int64 *)&v22[((char *)v81 - (char *)v22) >> 4];
        v23 = *(unsigned int *)(*v21 + 8);
        if ( ASymbol_less.i_uid >= (unsigned int)v23 )
          break;
        if ( v22 == (SSMethodBase **)v21 )
          goto LABEL_250;
        v81 = v21 - 1;
      }
      v82 = ASymbol_less.i_uid == (_DWORD)v23;
      v23 = ASymbol_less.i_uid != (_DWORD)v23;
      if ( v82 )
        break;
      if ( v81 == v21 )
        goto LABEL_250;
      v22 = (SSMethodBase **)(v21 + 1);
    }
    v83 = *v21;
  }
  else
  {
LABEL_250:
    v83 = 0i64;
  }
  result = v83;
  if ( v83 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, __int64 *, SSMethodBase **, __int64))(*(_QWORD *)v83 + 16i64))(
           v83,
           v21,
           v22,
           v23) == 1 )
    {
      *(_QWORD *)(v83 + 32) = SSInteger::mthd_op_less;
    }
    else
    {
      v84 = *(_QWORD *)(v83 + 16);
      v85 = *(SSParameters **)(v83 + 24);
      v91 = v85;
      if ( v85 )
        ++v85->i_ref_count;
      v86 = *(SSParameters **)(v83 + 24);
      if ( v86 )
      {
        v12 = v86->i_ref_count-- == 1;
        if ( v12 )
        {
          v86->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v86);
          AMemory::c_free_func(v86);
        }
        *(_QWORD *)(v83 + 24) = 0i64;
      }
      v92 = v83;
      *(ASymbol *)(v83 + 8) = ASymbol_less;
      *(_QWORD *)(v83 + 16) = v84;
      *(_QWORD *)v83 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v83 + 24) = v85;
      if ( v85 )
        ++v85->i_ref_count;
      *(_QWORD *)v83 = &SSMethodBase::`vftable;
      *(_QWORD *)v83 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v83 + 32) = SSInteger::mthd_op_less;
      if ( v85 )
      {
        v12 = v85->i_ref_count-- == 1;
        if ( v12 )
        {
          v85->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v85);
          AMemory::c_free_func(v85);
        }
      }
    }
  }
  SSClass::register_method_func(
    v4,
    &ASymbol_less_or_equal,
    SSInteger::mthd_op_less_or_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v4, &ASymbol_not_equal, SSInteger::mthd_op_not_equal, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v4, &ASymbol_as_copy, SSEnum::mthd_as_copy, SSBindFlag_instance_no_rebind);
  v87 = ASymbol::create((ASymbol *)&result, "is_between", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v4, v87, SSInteger::mthd_is_between, SSBindFlag_instance_no_rebind);
  v88 = ASymbol::create((ASymbol *)&result, "max", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v4, v88, SSInteger::mthd_max, SSBindFlag_instance_no_rebind);
  v89 = ASymbol::create((ASymbol *)&result, "min", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v4, v89, SSInteger::mthd_min, SSBindFlag_instance_no_rebind);
}ATerm_long);
  SSClass::register_method_func(v4, v89, SSInteger::mthd_min, SSBindFlag_instance_no_rebind);
}

// File Line: 110
// RVA: 0x121DF0
void __fastcall SSEnum::mthd_ctor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( i_obj_p && scope_p->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    LODWORD(i_obj_p[2].vfptr) = 0;
  else
    MEMORY[0x20] = 0;
}

// File Line: 127
// RVA: 0x121F20
void __fastcall SSReal::mthd_ctor_copy(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  LODWORD(i_obj_p[2].vfptr) = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 142
// RVA: 0x120D30
void __fastcall SSEnum::mthd_as_copy(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rcx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(*(SSClass **)&i_obj_p[1].i_ptr_id, LODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 160
// RVA: 0x121190
void __fastcall SSEnum::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rbx
  ANamed *v4; // rdi
  __int64 vfptr_low; // rsi
  __int64 v6; // r8
  __int64 v7; // rax
  ANamed **v8; // rcx
  ANamed **v9; // r9
  __int64 v10; // rdx
  AString *name_str_dbg; // rsi
  AStringRef *v12; // rbx
  bool v13; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v17; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *v20; // rax
  AObjBlock<AStringRef> *v21; // rcx
  unsigned __int64 v22; // rdx
  AStringRef *v23; // rax
  __int64 v24; // rbx
  AString *v25; // rsi
  unsigned int i_length; // edi
  AStringRef *v27; // rcx
  unsigned int v28; // ebx
  AStringRef *v29; // rbx
  AObjReusePool<AStringRef> *v30; // rax
  AObjBlock<AStringRef> *v31; // rcx
  unsigned __int64 v32; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AStringRef *v34; // rax
  __int64 v35; // rbx
  AStringRef *v36; // rax
  unsigned int v37; // edx
  __int64 v38; // rbx
  AStringRef *v39; // rdx
  unsigned int v40; // esi
  unsigned int v41; // ebx
  AStringRef *v42; // rax
  SSInstance *v43; // rax
  AStringRef *v44; // rbx
  AObjReusePool<AStringRef> *v45; // rax
  AObjBlock<AStringRef> *v46; // rcx
  unsigned __int64 v47; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v48; // rcx
  AStringRef *v49; // rbx
  AObjReusePool<AStringRef> *v50; // rax
  AObjBlock<AStringRef> *v51; // rcx
  unsigned __int64 v52; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v53; // rcx
  AStringRef *elem; // [rsp+68h] [rbp+38h] BYREF
  AString result; // [rsp+70h] [rbp+40h] BYREF
  AString v56; // [rsp+78h] [rbp+48h] BYREF

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    v4 = 0i64;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    ANamed::get_name_str_dbg((ANamed *)(*(_QWORD *)&i_obj_p[1].i_ptr_id + 8i64), &result);
    vfptr_low = LODWORD(i_obj_p[2].vfptr);
    v6 = *(_QWORD *)&i_obj_p[1].i_ptr_id;
    v7 = *(unsigned int *)(v6 + 168);
    if ( (_DWORD)v7 )
    {
      v8 = *(ANamed ***)(v6 + 176);
      v9 = &v8[v7];
      while ( v8 < v9 )
      {
        v10 = *(_QWORD *)&(*v8)[4].i_name.i_uid;
        if ( *(_QWORD *)(v10 + 32) == vfptr_low && *(_QWORD *)(v10 + 24) == v6 )
        {
          v4 = *v8;
          break;
        }
        ++v8;
      }
    }
    elem = AStringRef::get_empty();
    ++elem->i_ref_count;
    if ( v4 )
    {
      name_str_dbg = ANamed::get_name_str_dbg(v4, &v56);
      ++name_str_dbg->i_str_ref_p->i_ref_count;
      v12 = elem;
      v13 = elem->i_ref_count-- == 1;
      if ( v13 )
      {
        if ( v12->i_deallocate )
          AMemory::c_free_func(v12->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)v12 < i_objects_a
          || (v17 = (unsigned __int64)v12 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v17) )
        {
          p_i_exp_pool = &pool->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v12);
      }
      elem = name_str_dbg->i_str_ref_p;
      i_str_ref_p = v56.i_str_ref_p;
      v13 = v56.i_str_ref_p->i_ref_count-- == 1;
      if ( v13 )
      {
        if ( i_str_ref_p->i_deallocate )
          AMemory::c_free_func(i_str_ref_p->i_cstr_p);
        v20 = AStringRef::get_pool();
        v21 = v20->i_block_p;
        v22 = (unsigned __int64)v21->i_objects_a;
        if ( (unsigned __int64)i_str_ref_p < v22 || (unsigned __int64)i_str_ref_p >= v22 + 24i64 * v21->i_size )
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&v20->i_exp_pool, i_str_ref_p);
        else
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&v20->i_pool, i_str_ref_p);
      }
    }
    else
    {
      v23 = elem;
      v24 = elem->i_length + 1;
      if ( (unsigned int)v24 >= elem->i_size || elem->i_ref_count + elem->i_read_only != 1 )
      {
        AString::set_size((AString *)&elem, v24);
        v23 = elem;
      }
      v23->i_cstr_p[(unsigned int)(v24 - 1)] = 35;
      elem->i_cstr_p[v24] = 0;
      elem->i_length = v24;
      v25 = AString::ctor_int(&v56, vfptr_low, 0xAu);
      i_length = v25->i_str_ref_p->i_length;
      if ( i_length )
      {
        v27 = elem;
        v28 = i_length + elem->i_length;
        if ( v28 >= elem->i_size || elem->i_ref_count + elem->i_read_only != 1 )
        {
          AString::set_size((AString *)&elem, v28);
          v27 = elem;
        }
        memmove(&v27->i_cstr_p[v27->i_length], v25->i_str_ref_p->i_cstr_p, i_length + 1);
        elem->i_length = v28;
      }
      v29 = v56.i_str_ref_p;
      v13 = v56.i_str_ref_p->i_ref_count-- == 1;
      if ( v13 )
      {
        if ( v29->i_deallocate )
          AMemory::c_free_func(v29->i_cstr_p);
        v30 = AStringRef::get_pool();
        v31 = v30->i_block_p;
        v32 = (unsigned __int64)v31->i_objects_a;
        if ( (unsigned __int64)v29 < v32
          || (v17 = (unsigned __int64)v29 < v32 + 24i64 * v31->i_size, p_i_pool = &v30->i_pool, !v17) )
        {
          p_i_pool = &v30->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v29);
      }
      v34 = elem;
      v35 = elem->i_length + 1;
      if ( (unsigned int)v35 >= elem->i_size || elem->i_ref_count + elem->i_read_only != 1 )
      {
        AString::set_size((AString *)&elem, v35);
        v34 = elem;
      }
      v34->i_cstr_p[(unsigned int)(v35 - 1)] = 35;
      elem->i_cstr_p[v35] = 0;
      elem->i_length = v35;
    }
    v36 = result.i_str_ref_p;
    v37 = result.i_str_ref_p->i_length + elem->i_length + 1;
    if ( v37 >= result.i_str_ref_p->i_size || result.i_str_ref_p->i_ref_count + result.i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(&result, v37);
      v36 = result.i_str_ref_p;
    }
    v38 = v36->i_length + 1;
    if ( (unsigned int)v38 >= v36->i_size || v36->i_ref_count + v36->i_read_only != 1 )
    {
      AString::set_size(&result, v38);
      v36 = result.i_str_ref_p;
    }
    v36->i_cstr_p[(unsigned int)(v38 - 1)] = 46;
    result.i_str_ref_p->i_cstr_p[v38] = 0;
    result.i_str_ref_p->i_length = v38;
    v39 = elem;
    v40 = elem->i_length;
    if ( v40 )
    {
      v41 = v40 + v38;
      v42 = result.i_str_ref_p;
      if ( v41 >= result.i_str_ref_p->i_size || result.i_str_ref_p->i_ref_count + result.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&result, v41);
        v42 = result.i_str_ref_p;
        v39 = elem;
      }
      memmove(&v42->i_cstr_p[v42->i_length], v39->i_cstr_p, v40 + 1);
      result.i_str_ref_p->i_length = v41;
    }
    v43 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v56.i_str_ref_p = (AStringRef *)v43;
    if ( v43 != (SSInstance *)-32i64 )
    {
      v43->i_user_data = (unsigned __int64)result.i_str_ref_p;
      ++result.i_str_ref_p->i_ref_count;
    }
    *result_pp = v43;
    v44 = elem;
    v13 = elem->i_ref_count-- == 1;
    if ( v13 )
    {
      if ( v44->i_deallocate )
        AMemory::c_free_func(v44->i_cstr_p);
      v45 = AStringRef::get_pool();
      v46 = v45->i_block_p;
      v47 = (unsigned __int64)v46->i_objects_a;
      if ( (unsigned __int64)v44 < v47
        || (v17 = (unsigned __int64)v44 < v47 + 24i64 * v46->i_size, v48 = &v45->i_pool, !v17) )
      {
        v48 = &v45->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v48, v44);
    }
    v49 = result.i_str_ref_p;
    v13 = result.i_str_ref_p->i_ref_count-- == 1;
    if ( v13 )
    {
      if ( v49->i_deallocate )
        AMemory::c_free_func(v49->i_cstr_p);
      v50 = AStringRef::get_pool();
      v51 = v50->i_block_p;
      v52 = (unsigned __int64)v51->i_objects_a;
      if ( (unsigned __int64)v49 < v52
        || (v17 = (unsigned __int64)v49 < v52 + 24i64 * v51->i_size, v53 = &v50->i_pool, !v17) )
      {
        v53 = &v50->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v53, v49);
    }
  }
}

