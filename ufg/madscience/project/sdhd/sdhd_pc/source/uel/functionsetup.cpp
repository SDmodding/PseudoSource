// File Line: 7
// RVA: 0x5BD710
UEL::Value *__fastcall distanceBetween(UEL::Value *result, UEL::Value *args)
{
  float real; // xmm0_4
  float v3; // xmm3_4
  float qVector_y; // xmm4_4
  float v5; // xmm2_4
  __m128 integer_high; // xmm1
  unsigned int mUID; // eax
  UEL::Value *v8; // rax
  __int64 integer; // [rsp+20h] [rbp-28h]

  real = args[1].real;
  v3 = COERCE_FLOAT(args->integer);
  qVector_y = args->qVector_y;
  v5 = args[1].qVector_y;
  integer_high = (__m128)HIDWORD(args->integer);
  integer = args[1].integer;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  mUID = UFG::gNullQSymbol.mUID;
  result->type.mBaseType.mValue = 4;
  result->type.mDetailedType.mUID = mUID;
  v8 = result;
  integer_high.m128_f32[0] = (float)((float)((float)(integer_high.m128_f32[0] - *((float *)&integer + 1))
                                           * (float)(integer_high.m128_f32[0] - *((float *)&integer + 1)))
                                   + (float)((float)(v3 - real) * (float)(v3 - real)))
                           + (float)((float)(qVector_y - v5) * (float)(qVector_y - v5));
  result->qSymbol_mUID = _mm_sqrt_ps(integer_high).m128_u32[0];
  return v8;
}

// File Line: 22
// RVA: 0x5BD630
UEL::Value *__fastcall angleBetween(UEL::Value *result, UEL::Value *args)
{
  float qVector_y; // xmm1_4
  unsigned __int16 mValue; // ax
  float qVector_w; // xmm1_4
  unsigned int mUID; // eax
  float qVector_z; // xmm0_4
  float v8; // xmm1_4
  float real; // xmm0_4
  float v10; // xmm1_4
  unsigned int v11; // eax
  float v12; // xmm0_4
  unsigned int v13; // eax
  float v14; // xmm0_4
  UEL::Value *v15; // rax
  UFG::qVector3 v2; // [rsp+20h] [rbp-48h] BYREF
  float v17; // [rsp+2Ch] [rbp-3Ch]
  float v18; // [rsp+30h] [rbp-38h]
  __int16 v19; // [rsp+34h] [rbp-34h]
  unsigned int v20; // [rsp+38h] [rbp-30h]
  UFG::qVector3 v1; // [rsp+40h] [rbp-28h] BYREF
  float v22; // [rsp+4Ch] [rbp-1Ch]
  float v23; // [rsp+50h] [rbp-18h]
  unsigned __int16 v24; // [rsp+54h] [rbp-14h]
  unsigned int v25; // [rsp+58h] [rbp-10h]

  qVector_y = args->qVector_y;
  *(_QWORD *)&v1.x = args->integer;
  mValue = args->type.mBaseType.mValue;
  v1.z = qVector_y;
  qVector_w = args->qVector_w;
  v24 = mValue;
  mUID = args->type.mDetailedType.mUID;
  qVector_z = args->qVector_z;
  v23 = qVector_w;
  v8 = args[1].qVector_y;
  v25 = mUID;
  *(_QWORD *)&v2.x = args[1].integer;
  LOWORD(mUID) = args[1].type.mBaseType.mValue;
  v22 = qVector_z;
  real = args[1].real;
  v2.z = v8;
  v10 = args[1].qVector_w;
  v19 = mUID;
  v11 = args[1].type.mDetailedType.mUID;
  v2.x = real;
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
  v15 = result;
  result->real = (float)(v14 * 180.0) * 0.31830987;
  return v15;
}

// File Line: 37
// RVA: 0x5BD580
UEL::Value *__fastcall angleAroundUpBetween(UEL::Value *result, UEL::Value *args)
{
  float real; // xmm1_4
  __int64 v3; // rax
  float v5; // xmm0_4
  UEL::Value *v6; // rax
  UFG::qVector3 v2; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector3 v1; // [rsp+30h] [rbp-58h] BYREF
  __int64 integer; // [rsp+40h] [rbp-48h]
  __int64 v10; // [rsp+60h] [rbp-28h]

  real = args[1].real;
  integer = args->integer;
  v3 = args[1].integer;
  *(_QWORD *)&v1.x = integer;
  v2.x = real;
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
  v6 = result;
  result->real = (float)(v5 * 180.0) * 0.31830987;
  return v6;
}

// File Line: 58
// RVA: 0x5BD790
UEL::Value *__fastcall squareRoot(UEL::Value *result, UEL::Value *args)
{
  __m128 qSymbol_mUID; // xmm0
  unsigned int mUID; // eax
  UEL::Value *v4; // rax

  qSymbol_mUID = (__m128)args->qSymbol_mUID;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  mUID = UFG::gNullQSymbol.mUID;
  result->type.mBaseType.mValue = 4;
  result->type.mDetailedType.mUID = mUID;
  v4 = result;
  result->qSymbol_mUID = _mm_sqrt_ps(qSymbol_mUID).m128_u32[0];
  return v4;
}

// File Line: 71
// RVA: 0x5B80F0
void __fastcall InitFunctions(UFG::qTreeRB<UEL::InvocableBindingEntry,UEL::InvocableBindingEntry,1> *FunctionBindings)
{
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
  UEL::Value::Type arg3; // [rsp+60h] [rbp-A0h] BYREF
  UEL::Value::Type arg6; // [rsp+68h] [rbp-98h] BYREF
  UEL::Value::Type arg2; // [rsp+70h] [rbp-90h] BYREF
  UEL::Value::Type arg4; // [rsp+78h] [rbp-88h] BYREF
  UEL::Value::Type arg1; // [rsp+80h] [rbp-80h] BYREF
  UEL::Value::Type arg5; // [rsp+88h] [rbp-78h] BYREF
  UEL::Value::Type returnType; // [rsp+90h] [rbp-70h] BYREF
  UEL::Value::Type *p_arg8; // [rsp+98h] [rbp-68h]
  UEL::Value::Type *p_arg4; // [rsp+A0h] [rbp-60h]
  UFG::qSymbol *v22; // [rsp+A8h] [rbp-58h]
  UEL::Value::Type *p_arg3; // [rsp+B0h] [rbp-50h]
  UEL::Value::Type *p_arg7; // [rsp+B8h] [rbp-48h]
  UEL::Value::Type *p_arg2; // [rsp+C0h] [rbp-40h]
  UEL::Value::Type *p_arg5; // [rsp+C8h] [rbp-38h]
  UEL::Value::Type *p_arg1; // [rsp+D0h] [rbp-30h]
  UEL::Value::Type *p_arg6; // [rsp+D8h] [rbp-28h]
  UEL::Value::Type *p_returnType; // [rsp+E0h] [rbp-20h]
  UFG::qSymbol *p_name; // [rsp+E8h] [rbp-18h]
  __int64 v31; // [rsp+F0h] [rbp-10h]
  UFG::qSymbol name; // [rsp+140h] [rbp+40h] BYREF
  UFG::qSymbol result; // [rsp+148h] [rbp+48h] BYREF
  UEL::Value::Type arg8; // [rsp+150h] [rbp+50h] BYREF
  UEL::Value::Type arg7; // [rsp+158h] [rbp+58h] BYREF

  v31 = -2i64;
  v2 = 0i64;
  v3 = 0;
  UFG::qSymbol::create_from_string(&result, "distanceBetween");
  v4 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
  v22 = (UFG::qSymbol *)v4;
  if ( v4 )
  {
    p_arg8 = &arg8;
    p_arg7 = &arg7;
    p_arg6 = &arg6;
    p_arg5 = &arg5;
    p_arg4 = &arg4;
    p_arg3 = &arg3;
    p_arg2 = &arg2;
    p_arg1 = &arg1;
    p_returnType = &returnType;
    p_name = &name;
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
      &name.mUID,
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
  UFG::qBaseTreeRB::Add(&FunctionBindings->mTree, v5);
  UFG::qSymbol::create_from_string(&result, "angleBetween");
  v6 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
  p_name = (UFG::qSymbol *)v6;
  if ( v6 )
  {
    p_returnType = &arg8;
    p_arg1 = &arg7;
    p_arg2 = &returnType;
    p_arg3 = &arg1;
    p_arg4 = &arg2;
    p_arg5 = &arg3;
    p_arg6 = &arg4;
    p_arg7 = &arg5;
    p_arg8 = &arg6;
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
      &name.mUID,
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
  UFG::qBaseTreeRB::Add(&FunctionBindings->mTree, v7);
  UFG::qSymbol::create_from_string(&result, "angleAroundUpBetween");
  v8 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
  p_name = (UFG::qSymbol *)v8;
  if ( v8 )
  {
    p_returnType = &arg8;
    p_arg1 = &arg7;
    p_arg2 = &returnType;
    p_arg3 = &arg1;
    p_arg4 = &arg2;
    p_arg5 = &arg3;
    p_arg6 = &arg4;
    p_arg7 = &arg5;
    p_arg8 = &arg6;
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
      &name.mUID,
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
  UFG::qBaseTreeRB::Add(&FunctionBindings->mTree, v9);
  UFG::qSymbol::create_from_string(&result, "squareRoot");
  v10 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
  p_name = (UFG::qSymbol *)v10;
  if ( v10 )
  {
    p_returnType = &arg8;
    p_arg1 = &arg7;
    p_arg2 = &returnType;
    p_arg3 = &arg1;
    p_arg4 = &arg2;
    p_arg5 = &arg3;
    p_arg6 = &arg4;
    p_arg7 = &arg5;
    p_arg8 = &arg6;
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
      &name.mUID,
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
  UFG::qBaseTreeRB::Add(&FunctionBindings->mTree, v2);
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

