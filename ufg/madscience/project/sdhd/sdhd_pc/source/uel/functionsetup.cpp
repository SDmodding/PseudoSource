// File Line: 7
// RVA: 0x5BD710
UEL::Value *__fastcall distanceBetween(UEL::Value *result, UEL::Value *args)
{
  float v2; // xmm0_4
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm2_4
  __m128 v6; // xmm1
  __int64 v7; // ST20_8
  unsigned int v8; // eax
  UEL::Value *v9; // rax

  v2 = *(float *)&args[1].qSymbol_mUID;
  LODWORD(v3) = args->integer;
  v4 = args->qVector_y;
  v5 = args[1].qVector_y;
  v6 = (__m128)((unsigned __int64)args->integer >> 32);
  v7 = args[1].integer;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v8 = UFG::gNullQSymbol.mUID;
  result->type.mBaseType.mValue = 4;
  result->type.mDetailedType.mUID = v8;
  v9 = result;
  v6.m128_f32[0] = (float)((float)((float)(v6.m128_f32[0] - *((float *)&v7 + 1))
                                 * (float)(v6.m128_f32[0] - *((float *)&v7 + 1)))
                         + (float)((float)(v3 - v2) * (float)(v3 - v2)))
                 + (float)((float)(v4 - v5) * (float)(v4 - v5));
  result->qSymbol_mUID = (unsigned __int128)_mm_sqrt_ps(v6);
  return v9;
}

// File Line: 22
// RVA: 0x5BD630
UEL::Value *__fastcall angleBetween(UEL::Value *result, UEL::Value *args)
{
  float xmm1_4_1; // xmm1_4
  unsigned __int16 v3; // ax
  UEL::Value *v4; // rbx
  float v5; // xmm1_4
  unsigned int v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  unsigned int v11; // eax
  float v12; // xmm0_4
  unsigned int v13; // eax
  float v14; // xmm0_4
  UEL::Value *v15; // rax
  UFG::qVector3 v2; // [rsp+20h] [rbp-48h]
  float v17; // [rsp+2Ch] [rbp-3Ch]
  float v18; // [rsp+30h] [rbp-38h]
  __int16 v19; // [rsp+34h] [rbp-34h]
  unsigned int v20; // [rsp+38h] [rbp-30h]
  UFG::qVector3 v1; // [rsp+40h] [rbp-28h]
  float v22; // [rsp+4Ch] [rbp-1Ch]
  float v23; // [rsp+50h] [rbp-18h]
  unsigned __int16 v24; // [rsp+54h] [rbp-14h]
  unsigned int v25; // [rsp+58h] [rbp-10h]

  xmm1_4_1 = args->qVector_y;
  *(_QWORD *)&v1.x = args->integer;
  v3 = args->type.mBaseType.mValue;
  v4 = result;
  v1.z = xmm1_4_1;
  v5 = args->qVector_w;
  v24 = v3;
  v6 = args->type.mDetailedType.mUID;
  v7 = args->qVector_z;
  v23 = v5;
  v8 = args[1].qVector_y;
  v25 = v6;
  *(_QWORD *)&v2.x = args[1].integer;
  LOWORD(v6) = args[1].type.mBaseType.mValue;
  v22 = v7;
  v9 = *(float *)&args[1].qSymbol_mUID;
  v2.z = v8;
  v10 = args[1].qVector_w;
  v19 = v6;
  v11 = args[1].type.mDetailedType.mUID;
  v2.x = v9;
  v12 = args[1].qVector_z;
  v18 = v10;
  v20 = v11;
  v17 = v12;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v13 = UFG::gNullQSymbol.mUID;
  result->type.mBaseType.mValue = 4;
  result->type.mDetailedType.mUID = v13;
  v14 = UFG::qAngleBetween(&v1, &v2);
  v15 = v4;
  v4->real = (float)(v14 * 180.0) * 0.31830987;
  return v15;
}

// File Line: 37
// RVA: 0x5BD580
UEL::Value *__fastcall angleAroundUpBetween(UEL::Value *result, UEL::Value *args)
{
  float xmm1_4_1; // xmm1_4
  __int64 v3; // rax
  UEL::Value *v4; // rbx
  float v5; // xmm0_4
  UEL::Value *v6; // rax
  UFG::qVector3 v2; // [rsp+20h] [rbp-68h]
  UFG::qVector3 v1; // [rsp+30h] [rbp-58h]
  __int64 v9; // [rsp+40h] [rbp-48h]
  __int64 v10; // [rsp+60h] [rbp-28h]

  xmm1_4_1 = *(float *)&args[1].qSymbol_mUID;
  v9 = args->integer;
  v3 = args[1].integer;
  v4 = result;
  *(_QWORD *)&v1.x = v9;
  v2.x = xmm1_4_1;
  v10 = v3;
  result->type.mBaseType.mValue = 0;
  v1.z = 0.0;
  v2.y = *((float *)&v3 + 1);
  result->type.mDetailedType = UFG::gNullQSymbol;
  LODWORD(v3) = UFG::gNullQSymbol;
  result->type.mBaseType.mValue = 4;
  v2.z = 0.0;
  result->type.mDetailedType.mUID = v3;
  v5 = UFG::qAngleBetween(&v1, &v2);
  v6 = v4;
  v4->real = (float)(v5 * 180.0) * 0.31830987;
  return v6;
}

// File Line: 58
// RVA: 0x5BD790
UEL::Value *__fastcall squareRoot(UEL::Value *result, UEL::Value *args)
{
  __m128 v2; // xmm0
  unsigned int v3; // eax
  UEL::Value *v4; // rax

  v2 = (__m128)args->qSymbol_mUID;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v3 = UFG::gNullQSymbol.mUID;
  result->type.mBaseType.mValue = 4;
  result->type.mDetailedType.mUID = v3;
  v4 = result;
  result->qSymbol_mUID = (unsigned __int128)_mm_sqrt_ps(v2);
  return v4;
}

// File Line: 71
// RVA: 0x5B80F0
void __fastcall InitFunctions(UFG::qTreeRB<UEL::InvocableBindingEntry,UEL::InvocableBindingEntry,1> *FunctionBindings)
{
  UFG::qTreeRB<UEL::InvocableBindingEntry,UEL::InvocableBindingEntry,1> *v1; // rdi
  UFG::qBaseNodeRB *v2; // rbx
  unsigned int v3; // esi
  UFG::allocator::free_link *v4; // rcx
  UFG::qBaseNodeRB *v5; // rax
  UFG::allocator::free_link *v6; // rcx
  UFG::qBaseNodeRB *v7; // rax
  UFG::allocator::free_link *v8; // rcx
  UFG::qBaseNodeRB *v9; // rax
  UFG::allocator::free_link *v10; // rcx
  UFG::qBaseNodeRB *v11; // rax
  unsigned __int64 v12; // rax
  UEL::Value::Type arg3; // [rsp+60h] [rbp-A0h]
  UEL::Value::Type arg6; // [rsp+68h] [rbp-98h]
  UEL::Value::Type arg2; // [rsp+70h] [rbp-90h]
  UEL::Value::Type arg4; // [rsp+78h] [rbp-88h]
  UEL::Value::Type arg1; // [rsp+80h] [rbp-80h]
  UEL::Value::Type arg5; // [rsp+88h] [rbp-78h]
  UEL::Value::Type returnType; // [rsp+90h] [rbp-70h]
  UEL::Value::Type *v20; // [rsp+98h] [rbp-68h]
  UEL::Value::Type *v21; // [rsp+A0h] [rbp-60h]
  UFG::qSymbol *v22; // [rsp+A8h] [rbp-58h]
  UEL::Value::Type *v23; // [rsp+B0h] [rbp-50h]
  UEL::Value::Type *v24; // [rsp+B8h] [rbp-48h]
  UEL::Value::Type *v25; // [rsp+C0h] [rbp-40h]
  UEL::Value::Type *v26; // [rsp+C8h] [rbp-38h]
  UEL::Value::Type *v27; // [rsp+D0h] [rbp-30h]
  UEL::Value::Type *v28; // [rsp+D8h] [rbp-28h]
  UEL::Value::Type *v29; // [rsp+E0h] [rbp-20h]
  UFG::qSymbol *v30; // [rsp+E8h] [rbp-18h]
  __int64 v31; // [rsp+F0h] [rbp-10h]
  UFG::qSymbol name; // [rsp+140h] [rbp+40h]
  UFG::qSymbol result; // [rsp+148h] [rbp+48h]
  UEL::Value::Type arg8; // [rsp+150h] [rbp+50h]
  UEL::Value::Type arg7; // [rsp+158h] [rbp+58h]

  v31 = -2i64;
  v1 = FunctionBindings;
  v2 = 0i64;
  v3 = 0;
  UFG::qSymbol::create_from_string(&result, "distanceBetween");
  v4 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
  v22 = (UFG::qSymbol *)v4;
  if ( v4 )
  {
    v20 = &arg8;
    v24 = &arg7;
    v28 = &arg6;
    v26 = &arg5;
    v21 = &arg4;
    v23 = &arg3;
    v25 = &arg2;
    v27 = &arg1;
    v29 = &returnType;
    v30 = &name;
    arg8.mBaseType.mValue = 0;
    arg8.mDetailedType = UFG::gNullQSymbol;
    arg7.mBaseType.mValue = 0;
    arg7.mDetailedType = UFG::gNullQSymbol;
    arg6.mBaseType.mValue = 0;
    arg6.mDetailedType = UFG::gNullQSymbol;
    arg5.mBaseType.mValue = 0;
    arg5.mDetailedType = UFG::gNullQSymbol;
    arg4.mBaseType.mValue = 0;
    arg4.mDetailedType = UFG::gNullQSymbol;
    arg3.mBaseType.mValue = 0;
    arg3.mDetailedType = UFG::gNullQSymbol;
    arg2.mBaseType.mValue = 7;
    arg2.mDetailedType = UFG::gNullQSymbol;
    arg1.mBaseType.mValue = 7;
    arg1.mDetailedType = UFG::gNullQSymbol;
    returnType.mBaseType.mValue = 4;
    returnType.mDetailedType = UFG::gNullQSymbol;
    name.mUID = result.mUID;
    UEL::InvocableBindingEntry::InvocableBindingEntry(
      (UEL::InvocableBindingEntry *)v4,
      (__int64)&name,
      0,
      (UEL::Value::Type)&returnType,
      (UEL::Value::Type)&arg1,
      (UEL::Value::Type)&arg2,
      (UEL::Value::Type)&arg3,
      (UEL::Value::Type)&arg4,
      (UEL::Value::Type)&arg5,
      (UEL::Value::Type)&arg6,
      (UEL::Value::Type)&arg7,
      (UEL::Value::Type)&arg8);
    v3 = 1;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&v1->mTree, v5);
  UFG::qSymbol::create_from_string(&result, "angleBetween");
  v6 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
  v30 = (UFG::qSymbol *)v6;
  if ( v6 )
  {
    v29 = &arg8;
    v27 = &arg7;
    v25 = &returnType;
    v23 = &arg1;
    v21 = &arg2;
    v26 = &arg3;
    v28 = &arg4;
    v24 = &arg5;
    v20 = &arg6;
    v22 = &name;
    arg8.mBaseType.mValue = 0;
    arg8.mDetailedType = UFG::gNullQSymbol;
    arg7.mBaseType.mValue = 0;
    arg7.mDetailedType = UFG::gNullQSymbol;
    returnType.mBaseType.mValue = 0;
    returnType.mDetailedType = UFG::gNullQSymbol;
    arg1.mBaseType.mValue = 0;
    arg1.mDetailedType = UFG::gNullQSymbol;
    arg2.mBaseType.mValue = 0;
    arg2.mDetailedType = UFG::gNullQSymbol;
    arg3.mBaseType.mValue = 0;
    arg3.mDetailedType = UFG::gNullQSymbol;
    arg4.mBaseType.mValue = 7;
    arg4.mDetailedType = UFG::gNullQSymbol;
    arg5.mBaseType.mValue = 7;
    arg5.mDetailedType = UFG::gNullQSymbol;
    arg6.mBaseType.mValue = 4;
    arg6.mDetailedType = UFG::gNullQSymbol;
    name.mUID = result.mUID;
    UEL::InvocableBindingEntry::InvocableBindingEntry(
      (UEL::InvocableBindingEntry *)v6,
      (__int64)&name,
      v3++,
      (UEL::Value::Type)&arg6,
      (UEL::Value::Type)&arg5,
      (UEL::Value::Type)&arg4,
      (UEL::Value::Type)&arg3,
      (UEL::Value::Type)&arg2,
      (UEL::Value::Type)&arg1,
      (UEL::Value::Type)&returnType,
      (UEL::Value::Type)&arg7,
      (UEL::Value::Type)&arg8);
  }
  else
  {
    v7 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&v1->mTree, v7);
  UFG::qSymbol::create_from_string(&result, "angleAroundUpBetween");
  v8 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
  v30 = (UFG::qSymbol *)v8;
  if ( v8 )
  {
    v29 = &arg8;
    v27 = &arg7;
    v25 = &returnType;
    v23 = &arg1;
    v21 = &arg2;
    v26 = &arg3;
    v28 = &arg4;
    v24 = &arg5;
    v20 = &arg6;
    v22 = &name;
    arg8.mBaseType.mValue = 0;
    arg8.mDetailedType = UFG::gNullQSymbol;
    arg7.mBaseType.mValue = 0;
    arg7.mDetailedType = UFG::gNullQSymbol;
    returnType.mBaseType.mValue = 0;
    returnType.mDetailedType = UFG::gNullQSymbol;
    arg1.mBaseType.mValue = 0;
    arg1.mDetailedType = UFG::gNullQSymbol;
    arg2.mBaseType.mValue = 0;
    arg2.mDetailedType = UFG::gNullQSymbol;
    arg3.mBaseType.mValue = 0;
    arg3.mDetailedType = UFG::gNullQSymbol;
    arg4.mBaseType.mValue = 7;
    arg4.mDetailedType = UFG::gNullQSymbol;
    arg5.mBaseType.mValue = 7;
    arg5.mDetailedType = UFG::gNullQSymbol;
    arg6.mBaseType.mValue = 4;
    arg6.mDetailedType = UFG::gNullQSymbol;
    name.mUID = result.mUID;
    UEL::InvocableBindingEntry::InvocableBindingEntry(
      (UEL::InvocableBindingEntry *)v8,
      (__int64)&name,
      v3++,
      (UEL::Value::Type)&arg6,
      (UEL::Value::Type)&arg5,
      (UEL::Value::Type)&arg4,
      (UEL::Value::Type)&arg3,
      (UEL::Value::Type)&arg2,
      (UEL::Value::Type)&arg1,
      (UEL::Value::Type)&returnType,
      (UEL::Value::Type)&arg7,
      (UEL::Value::Type)&arg8);
  }
  else
  {
    v9 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&v1->mTree, v9);
  UFG::qSymbol::create_from_string(&result, "squareRoot");
  v10 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
  v30 = (UFG::qSymbol *)v10;
  if ( v10 )
  {
    v29 = &arg8;
    v27 = &arg7;
    v25 = &returnType;
    v23 = &arg1;
    v21 = &arg2;
    v26 = &arg3;
    v28 = &arg4;
    v24 = &arg5;
    v20 = &arg6;
    v22 = &name;
    arg8.mBaseType.mValue = 0;
    arg8.mDetailedType = UFG::gNullQSymbol;
    arg7.mBaseType.mValue = 0;
    arg7.mDetailedType = UFG::gNullQSymbol;
    returnType.mBaseType.mValue = 0;
    returnType.mDetailedType = UFG::gNullQSymbol;
    arg1.mBaseType.mValue = 0;
    arg1.mDetailedType = UFG::gNullQSymbol;
    arg2.mBaseType.mValue = 0;
    arg2.mDetailedType = UFG::gNullQSymbol;
    arg3.mBaseType.mValue = 0;
    arg3.mDetailedType = UFG::gNullQSymbol;
    arg4.mBaseType.mValue = 0;
    arg4.mDetailedType = UFG::gNullQSymbol;
    arg5.mBaseType.mValue = 4;
    arg5.mDetailedType = UFG::gNullQSymbol;
    arg6.mBaseType.mValue = 4;
    arg6.mDetailedType = UFG::gNullQSymbol;
    name.mUID = result.mUID;
    UEL::InvocableBindingEntry::InvocableBindingEntry(
      (UEL::InvocableBindingEntry *)v10,
      (__int64)&name,
      v3,
      (UEL::Value::Type)&arg6,
      (UEL::Value::Type)&arg5,
      (UEL::Value::Type)&arg4,
      (UEL::Value::Type)&arg3,
      (UEL::Value::Type)&arg2,
      (UEL::Value::Type)&arg1,
      (UEL::Value::Type)&returnType,
      (UEL::Value::Type)&arg7,
      (UEL::Value::Type)&arg8);
    v2 = v11;
    ++v3;
  }
  UFG::qBaseTreeRB::Add(&v1->mTree, v2);
  v12 = 8i64 * v3;
  if ( !is_mul_ok(v3, 8ui64) )
    v12 = -1i64;
  UFG::UELRuntime::FunctionTable = (UEL::Value *(__fastcall **)(UEL::Value *, UEL::Value *))UFG::qMalloc(
                                                                                              v12,
                                                                                              UFG::gGlobalNewName,
                                                                                              0i64);
  *UFG::UELRuntime::FunctionTable = distanceBetween;
  UFG::UELRuntime::FunctionTable[1] = angleBetween;
  UFG::UELRuntime::FunctionTable[2] = angleAroundUpBetween;
  UFG::UELRuntime::FunctionTable[3] = squareRoot;
}

