// File Line: 7
// RVA: 0x1475F10
__int64 dynamic_initializer_for__UEL::ParameterExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ParameterExpression", 0xFFFFFFFF);
  UEL::ParameterExpression::sClassNameUID = result;
  return result;
}

// File Line: 10
// RVA: 0x1475B40
__int64 dynamic_initializer_for__UEL::ParameterExpression::VectorX__()
{
  UFG::qSymbol *v0; // rax
  unsigned int v1; // ecx
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  __int16 v4; // [rsp+48h] [rbp+10h]
  unsigned int v5; // [rsp+4Ch] [rbp+14h]
  __int64 v6; // [rsp+50h] [rbp+18h]
  __int64 *v7; // [rsp+58h] [rbp+20h]

  v7 = &v6;
  LOWORD(v6) = 4;
  HIDWORD(v6) = UFG::gNullQSymbol;
  v4 = 4;
  v5 = UFG::gNullQSymbol.mUID;
  v0 = UFG::qSymbol::create_from_string(&result, "X");
  v1 = v0->mUID;
  _mm_store_si128((__m128i *)&UEL::ParameterExpression::VectorX, (__m128i)0i64);
  *(_QWORD *)&dword_1423AD250 = 0i64;
  unk_1423AD258 = v1;
  unk_1423AD260 = v0->mUID;
  *(_WORD *)&stru_1423AD264.mEnableStereo = v4;
  stru_1423AD264.mLineOffset = v5;
  LOWORD(stru_1423AD264.mWidth) = v6;
  stru_1423AD264.mHeight = HIDWORD(v6);
  LOBYTE(stru_1423AD264.mStereo) = 0;
  HIDWORD(stru_1423AD264.mStereo) = 0;
  *(IAmdDxExt **)((char *)&stru_1423AD264.mExtension + 4) = 0i64;
  unk_1423AD288 = 0;
  _((AMD_HD3D *)&v4);
  _((AMD_HD3D *)&v6);
  return atexit(dynamic_atexit_destructor_for__UEL::ParameterExpression::VectorX__);
}

// File Line: 11
// RVA: 0x1475C30
__int64 dynamic_initializer_for__UEL::ParameterExpression::VectorY__()
{
  UFG::qSymbol *v0; // rax
  unsigned int v1; // ecx
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  __int16 v4; // [rsp+48h] [rbp+10h]
  unsigned int v5; // [rsp+4Ch] [rbp+14h]
  __int64 v6; // [rsp+50h] [rbp+18h]
  __int64 *v7; // [rsp+58h] [rbp+20h]

  v7 = &v6;
  LOWORD(v6) = 4;
  HIDWORD(v6) = UFG::gNullQSymbol;
  v4 = 4;
  v5 = UFG::gNullQSymbol.mUID;
  v0 = UFG::qSymbol::create_from_string(&result, "Y");
  v1 = v0->mUID;
  _mm_store_si128((__m128i *)&UEL::ParameterExpression::VectorY, (__m128i)0i64);
  unk_1423AD320 = 0i64;
  unk_1423AD328 = v1;
  unk_1423AD330 = v0->mUID;
  *(_WORD *)&stru_1423AD334.mEnableStereo = v4;
  stru_1423AD334.mLineOffset = v5;
  LOWORD(stru_1423AD334.mWidth) = v6;
  stru_1423AD334.mHeight = HIDWORD(v6);
  LOBYTE(stru_1423AD334.mStereo) = 0;
  HIDWORD(stru_1423AD334.mStereo) = 4;
  *(IAmdDxExt **)((char *)&stru_1423AD334.mExtension + 4) = 0i64;
  unk_1423AD358 = 0;
  _((AMD_HD3D *)&v4);
  _((AMD_HD3D *)&v6);
  return atexit(dynamic_atexit_destructor_for__UEL::ParameterExpression::VectorY__);
}

// File Line: 12
// RVA: 0x1475D20
__int64 dynamic_initializer_for__UEL::ParameterExpression::VectorZ__()
{
  UFG::qSymbol *v0; // rax
  unsigned int v1; // ecx
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  __int16 v4; // [rsp+48h] [rbp+10h]
  unsigned int v5; // [rsp+4Ch] [rbp+14h]
  __int64 v6; // [rsp+50h] [rbp+18h]
  __int64 *v7; // [rsp+58h] [rbp+20h]

  v7 = &v6;
  LOWORD(v6) = 4;
  HIDWORD(v6) = UFG::gNullQSymbol;
  v4 = 4;
  v5 = UFG::gNullQSymbol.mUID;
  v0 = UFG::qSymbol::create_from_string(&result, "Z");
  v1 = v0->mUID;
  _mm_store_si128((__m128i *)&UEL::ParameterExpression::VectorZ, (__m128i)0i64);
  unk_1423AD2D0 = 0i64;
  unk_1423AD2D8 = v1;
  unk_1423AD2E0 = v0->mUID;
  *(_WORD *)&stru_1423AD2E4.mEnableStereo = v4;
  stru_1423AD2E4.mLineOffset = v5;
  LOWORD(stru_1423AD2E4.mWidth) = v6;
  stru_1423AD2E4.mHeight = HIDWORD(v6);
  LOBYTE(stru_1423AD2E4.mStereo) = 0;
  HIDWORD(stru_1423AD2E4.mStereo) = 8;
  *(IAmdDxExt **)((char *)&stru_1423AD2E4.mExtension + 4) = 0i64;
  unk_1423AD308 = 0;
  _((AMD_HD3D *)&v4);
  _((AMD_HD3D *)&v6);
  return atexit(dynamic_atexit_destructor_for__UEL::ParameterExpression::VectorZ__);
}

// File Line: 25
// RVA: 0x24E440
void __fastcall UEL::ParameterExpression::ParameterExpression(UEL::ParameterExpression *this, const char *name, UEL::Expression *withinParameter, UEL::Expression *arrayIndex)
{
  UEL::ParameterExpression *v4; // rbx
  UFG::qOffset64<UEL::Expression *> *v5; // rax
  char *v6; // r8
  UFG::qOffset64<UEL::Expression *> *v7; // rax
  char *v8; // r9

  v4 = this;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->mType.mValue = 4;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::ParameterExpression::`vftable;
  v5 = &this->mWithinParameter;
  if ( withinParameter )
    v6 = (char *)((char *)withinParameter - (char *)v5);
  else
    v6 = 0i64;
  v5->mOffset = (__int64)v6;
  v7 = &this->mArrayIndex;
  if ( arrayIndex )
    v8 = (char *)((char *)arrayIndex - (char *)v7);
  else
    v8 = 0i64;
  v7->mOffset = (__int64)v8;
  this->mTypeMap = 0i64;
  this->mEnumBinding = 0i64;
  *(_WORD *)&this->mArrayIndexIndexesBitField = 0;
  this->mAlwaysReturns.mBaseType.mValue = 0;
  this->mAlwaysReturns.mDetailedType = UFG::gNullQSymbol;
  UFG::qSymbol::create_from_string(&this->mName, name);
  v4->mResolvedOffset = -1;
}

// File Line: 34
// RVA: 0x252E90
char __fastcall UEL::ParameterExpression::Resolve(UEL::ParameterExpression *this, UEL::Runtime *instance)
{
  UEL::Runtime *v2; // r13
  UEL::ParameterExpression *v3; // rdi
  UFG::qBaseTreeRB *v4; // rbp
  __int64 v5; // rax
  char *v6; // rcx
  UEL::ParameterBindingEntry *v7; // rbx
  __int64 v8; // rax
  UEL::Expression *v9; // rcx
  unsigned __int16 v10; // cx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  __int64 v13; // rax
  signed __int64 v14; // rdx
  unsigned int v15; // eax
  signed __int64 v16; // rcx
  bool v17; // bl
  unsigned int v18; // edx
  __int64 v19; // rax
  signed __int64 v20; // rcx
  signed __int64 v21; // rdx
  unsigned int v22; // eax
  signed __int64 v23; // rcx
  unsigned int v24; // edx
  UFG::qOffset64<UEL::Expression *> *v25; // r14
  __int64 v26; // rax
  unsigned __int16 v27; // cx
  signed __int16 v28; // dx
  char v29; // al
  unsigned int v30; // eax
  char *v31; // rcx
  unsigned int v32; // esi
  UEL::Expression *v33; // rcx
  UEL::Value::Type *v34; // rax
  UFG::allocator::free_link *v35; // rax
  UEL::Expression *v36; // r8
  __int64 v37; // rax
  __int64 v38; // rsi
  unsigned int v39; // er15
  UEL::Expression *v40; // rcx
  UEL::Value::Type *v41; // rax
  unsigned int v42; // er15
  UEL::Expression *v43; // rcx
  UEL::Value::Type *v44; // rax
  char v45; // al
  bool v46; // al
  unsigned __int16 v47; // ax
  unsigned int v48; // edx
  UFG::qBaseTreeRB *v49; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *v50; // rax
  __int64 v52; // rax
  UEL::Expression *v53; // rcx
  bool v54; // al
  unsigned int v55; // eax
  UEL::Value::Type result; // [rsp+70h] [rbp+8h]
  UEL::Value::Type v57; // [rsp+80h] [rbp+18h]

  v2 = instance;
  v3 = this;
  v4 = 0i64;
  v5 = this->mWithinParameter.mOffset;
  if ( v5 )
  {
    v6 = (char *)&this->mWithinParameter + v5;
    if ( v6 )
    {
      if ( !(*(unsigned __int8 (__cdecl **)(char *, UEL::Runtime *))(*(_QWORD *)v6 + 16i64))(v6, instance) )
        return 0;
    }
  }
  v7 = 0i64;
  v8 = v3->mWithinParameter.mOffset;
  if ( !v8 || (v9 = (UEL::Expression *)((char *)&v3->mWithinParameter + v8)) == 0i64 )
  {
    v24 = v3->mName.mUID;
    if ( v24 )
      v7 = (UEL::ParameterBindingEntry *)UFG::qBaseTreeRB::Get(&v2->mParameterBindings->mTree, v24);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mName);
    if ( !v7 )
      return 0;
    v3->mValueType.mBaseType.mValue = v7->type.mBaseType.mValue;
    v3->mValueType.mDetailedType.mUID = v7->type.mDetailedType.mUID;
    v3->mAlwaysReturns.mBaseType.mValue = v7->alwaysReturns.mBaseType.mValue;
    v22 = v7->alwaysReturns.mDetailedType.mUID;
LABEL_50:
    v3->mAlwaysReturns.mDetailedType.mUID = v22;
    goto LABEL_51;
  }
  UEL::Expression::GetValueType(v9, &result);
  v10 = result.mBaseType.mValue;
  if ( result.mBaseType.mValue == 10 )
  {
    v11 = v3->mWithinParameter.mOffset;
    if ( v11 )
      v12 = (signed __int64)&v3->mWithinParameter + v11;
    else
      v12 = 0i64;
    v10 = *(_WORD *)(v12 + 60);
  }
  if ( (unsigned __int16)(v10 - 7) > 2u )
    return 0;
  v13 = v3->mWithinParameter.mOffset;
  v14 = (signed __int64)(v13 ? (UFG::qOffset64<UEL::Expression *> *)((char *)&v3->mWithinParameter + v13) : 0i64);
  if ( *(_WORD *)(v14 + 8) != 4 )
    return 0;
  if ( v10 != 7 )
  {
    if ( v10 != 8 )
    {
      if ( v10 == 9 || v10 == 10 )
      {
        if ( v13 )
          v23 = (signed __int64)&v3->mWithinParameter + v13;
        else
          v23 = 0i64;
        v3->mValueType.mBaseType.mValue = *(_WORD *)(v23 + 60);
        v3->mValueType.mDetailedType.mUID = *(_DWORD *)(v23 + 64);
      }
      goto LABEL_51;
    }
    if ( v13 )
      v16 = (signed __int64)&v3->mWithinParameter + v13;
    else
      v16 = 0i64;
    v17 = *(_QWORD *)(v16 + 40) != 0i64;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mName);
    if ( !v17 )
      return 0;
    v18 = v3->mName.mUID;
    v19 = v3->mWithinParameter.mOffset;
    v20 = (signed __int64)(v19 ? (UFG::qOffset64<UEL::Expression *> *)((char *)&v3->mWithinParameter + v19) : 0i64);
    v7 = (UEL::ParameterBindingEntry *)(v18 ? UFG::qBaseTreeRB::Get(*(UFG::qBaseTreeRB **)(v20 + 40), v18) : 0i64);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mName);
    if ( !v7 )
      return 0;
    v21 = (signed __int64)&v7->type;
    v3->mValueType.mBaseType.mValue = v7->type.mBaseType.mValue;
    v3->mValueType.mDetailedType.mUID = v7->type.mDetailedType.mUID;
    if ( (unsigned __int16)(v3->mValueType.mBaseType.mValue - 9) <= 1u )
      v21 = (signed __int64)&v7->alwaysReturns;
    v3->mAlwaysReturns.mBaseType.mValue = *(_WORD *)v21;
    v22 = *(_DWORD *)(v21 + 4);
    goto LABEL_50;
  }
  v15 = v3->mName.mUID;
  if ( v15 == unk_1423AD258 )
  {
    v7 = &UEL::ParameterExpression::VectorX;
  }
  else if ( v15 == unk_1423AD328 )
  {
    v7 = &UEL::ParameterExpression::VectorY;
  }
  else
  {
    if ( v15 != unk_1423AD2D8 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mName);
      return 0;
    }
    v7 = &UEL::ParameterExpression::VectorZ;
  }
  v3->mValueType.mBaseType.mValue = v7->type.mBaseType.mValue;
  v3->mValueType.mDetailedType.mUID = v7->type.mDetailedType.mUID;
LABEL_51:
  v25 = &v3->mArrayIndex;
  v26 = v3->mArrayIndex.mOffset;
  if ( v26 && (UFG::qOffset64<UEL::Expression *> *)((char *)v25 + v26) )
  {
    v27 = v3->mValueType.mBaseType.mValue;
    if ( v27 <= 0xCu )
      return 0;
    if ( v27 != 23 || UFG::gNullQSymbol.mUID != v3->mValueType.mDetailedType.mUID )
      v28 = v27 - 12;
    else
      v28 = 5;
    if ( 23 != v27 || (v29 = 1, UFG::gNullQSymbol.mUID != v3->mValueType.mDetailedType.mUID) )
      v29 = 0;
    v3->mArrayIndexIndexesBitField = v29;
    v30 = UFG::gNullQSymbol.mUID;
    v3->mValueType.mBaseType.mValue = v28;
    v3->mValueType.mDetailedType.mUID = v30;
    v31 = (char *)v25 + v25->mOffset;
    if ( !v25->mOffset )
      v31 = 0i64;
    (*(void (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v31 + 16i64))(v31, v2);
    v32 = UFG::gNullQSymbol.mUID;
    v33 = (UEL::Expression *)((char *)v25 + v25->mOffset);
    if ( !v25->mOffset )
      v33 = 0i64;
    v34 = UEL::Expression::GetValueType(v33, &result);
    if ( 6 == v34->mBaseType.mValue && v32 == v34->mDetailedType.mUID )
    {
      v35 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      result = (UEL::Value::Type)v35;
      if ( v35 )
      {
        v36 = (UEL::Expression *)((char *)v25 + v25->mOffset);
        if ( !v25->mOffset )
          v36 = 0i64;
        UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v35, CastToInteger, v36);
        v38 = v37;
      }
      else
      {
        v38 = 0i64;
      }
      if ( !(*(unsigned __int8 (__fastcall **)(__int64, UEL::Runtime *))(*(_QWORD *)v38 + 16i64))(v38, v2) )
        return 0;
      v25->mOffset = v38 - (_QWORD)v25;
    }
    v39 = UFG::gNullQSymbol.mUID;
    v40 = (UEL::Expression *)((char *)v25 + v25->mOffset);
    if ( !v25->mOffset )
      v40 = 0i64;
    v41 = UEL::Expression::GetValueType(v40, &result);
    if ( 1 == v41->mBaseType.mValue && v39 == v41->mDetailedType.mUID )
      goto LABEL_115;
    v42 = UFG::gNullQSymbol.mUID;
    v43 = (UEL::Expression *)((char *)v25 + v25->mOffset);
    if ( !v25->mOffset )
      v43 = 0i64;
    v44 = UEL::Expression::GetValueType(v43, &v57);
    if ( v44->mBaseType.mValue != 6 || v42 != v44->mDetailedType.mUID )
      v45 = 0;
    else
LABEL_115:
      v45 = 1;
    if ( !v45 )
      return 0;
  }
  if ( v7 )
    v46 = v7->needsCall;
  else
    v46 = 0;
  v3->mNeedsCall = v46;
  v47 = v3->mValueType.mBaseType.mValue;
  if ( v47 == 8 )
  {
    v3->mTypeMap = v7->parameterNameToDataMap;
    goto LABEL_105;
  }
  if ( v3->mAlwaysReturns.mBaseType.mValue == 8 )
  {
    v48 = v3->mAlwaysReturns.mDetailedType.mUID;
    if ( v48 && (v49 = UFG::qBaseTreeRB::Get(&v2->mParameterBindings->mTree, v48)) != 0i64 )
      v50 = *(UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> **)&v49->mCount;
    else
      v50 = v2->mParameterBindings;
    v3->mTypeMap = v50;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mAlwaysReturns.mDetailedType);
    if ( !v3->mTypeMap )
      return 0;
    goto LABEL_105;
  }
  v54 = 1;
  if ( v47 )
  {
    v52 = v3->mWithinParameter.mOffset;
    if ( !v52
      || (v53 = (UEL::Expression *)((char *)&v3->mWithinParameter + v52)) == 0i64
      || UEL::Expression::GetValueType(v53, &result)->mBaseType.mValue != 9 )
    {
      v54 = 0;
    }
  }
  if ( !v54 )
  {
LABEL_105:
    v3->mResolvedOffset = v7->offset;
    goto LABEL_106;
  }
  v3->mResolvedOffset = 0;
LABEL_106:
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mName);
  if ( v3->mResolvedOffset == -1 )
    return 0;
  if ( 6 == v3->mValueType.mBaseType.mValue )
  {
    v55 = v3->mValueType.mDetailedType.mUID;
    if ( UFG::gNullQSymbol.mUID == v55 )
    {
      if ( v55 )
        v4 = UFG::qBaseTreeRB::Get(&v2->mEnumBindings->mTree, v55);
      v3->mEnumBinding = (UEL::EnumBindingEntry *)v4;
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mName);
      if ( !v3->mEnumBinding )
        return 0;
    }
  }
  v3->mResolved = 1;
  return 1;
}

// File Line: 183
// RVA: 0x2512C0
UEL::Value *__fastcall UEL::ParameterExpression::Eval(UEL::ParameterExpression *this, UEL::Value *result, UEL::ParametersBase *parameters, UFG::qArray<UEL::Value,0> *args)
{
  UEL::Value *v4; // r14
  UEL::ParameterExpression *v5; // rsi
  UFG::qSymbolUC *v6; // r12
  signed int v7; // ebx
  bool v8; // r15
  __int64 v9; // rax
  char *v10; // rcx
  unsigned int v11; // eax
  UEL::ParametersBase *v12; // r13
  __int64 v13; // rax
  UEL::Expression *v14; // rcx
  char *v15; // rax
  UFG::qSymbol *v16; // r8
  __int64 v17; // rax
  UEL::ParametersBase *v18; // rdi
  __int64 v19; // rax
  __int64 *v20; // r15
  UEL::Value::Type *v21; // rax
  __int64 v22; // rdi
  __int64 v23; // rcx
  signed __int64 v24; // rcx
  UEL::Value *v25; // rax
  UFG::qSymbolUC *v26; // rax
  __int64 v27; // rax
  UEL::Expression *v28; // rcx
  unsigned int v29; // er13
  UEL::Value::Type *v30; // rax
  bool v31; // al
  UEL::Value *v32; // rax
  unsigned int v33; // edi
  int v34; // ebx
  UEL::Value::Type *v35; // rax
  __int64 v36; // rax
  UFG::qSymbolUC *v37; // rax
  UEL::Value::Type *v38; // rax
  __int64 *v39; // rax
  unsigned int v40; // edx
  const char *v41; // rdx
  __int64 v42; // rax
  signed int *v43; // rax
  __int64 v44; // r8
  int v45; // eax
  unsigned __int64 v46; // rcx
  _QWORD *v47; // rax
  char v48; // cf
  __int64 v49; // rcx
  float v50; // xmm3_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  unsigned int v53; // xmm0_4
  UFG::qString *v54; // rax
  UEL::Value::Type v56; // [rsp+30h] [rbp-79h]
  UEL::Value v57; // [rsp+38h] [rbp-71h]
  UEL::Value::Type v58; // [rsp+58h] [rbp-51h]
  UEL::Value::Type v59; // [rsp+60h] [rbp-49h]
  UEL::ParametersBase *v60; // [rsp+70h] [rbp-39h]
  __int16 v61; // [rsp+84h] [rbp-25h]
  __int64 v62; // [rsp+90h] [rbp-19h]
  UFG::qString v63; // [rsp+98h] [rbp-11h]
  UEL::Value::Type resulta; // [rsp+108h] [rbp+5Fh]
  __int64 v65; // [rsp+118h] [rbp+6Fh]
  __int64 v66; // [rsp+120h] [rbp+77h]
  __int64 v67; // [rsp+128h] [rbp+7Fh]

  v62 = -2i64;
  v4 = result;
  v5 = this;
  v6 = 0i64;
  v7 = 0;
  *(_DWORD *)&v56.mBaseType.mValue = 0;
  v57.type.mBaseType.mValue = 0;
  v57.type.mDetailedType = UFG::gNullQSymbol;
  v8 = 0;
  v9 = this->mWithinParameter.mOffset;
  if ( v9 && (v10 = (char *)&this->mWithinParameter + v9) != 0i64 )
  {
    (*(void (__fastcall **)(char *, UEL::ParametersBase **))(*(_QWORD *)v10 + 24i64))(v10, &v60);
    switch ( v61 )
    {
      case 0:
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mName);
LABEL_5:
        v4->type.mBaseType.mValue = 0;
        v11 = UFG::gNullQSymbol.mUID;
        goto LABEL_83;
      case 8:
        v12 = v60;
        v13 = v5->mWithinParameter.mOffset;
        if ( v13 )
          v14 = (UEL::Expression *)((char *)&v5->mWithinParameter + v13);
        else
          v14 = 0i64;
        v8 = UEL::Expression::GetValueType(v14, &resulta)->mBaseType.mValue == 10;
        break;
      case 9:
        v12 = v60;
        break;
      default:
        v12 = (UEL::ParametersBase *)&v60;
        v8 = 1;
        break;
    }
  }
  else
  {
    v12 = parameters;
  }
  v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mName);
  UFG::qString::FormatEx((UFG::qString *)&v57.qVector_w, "(\"%s\"", v15);
  UFG::qString::~qString((UFG::qString *)&v57.qVector_w);
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mName);
  if ( !v12 )
    goto LABEL_5;
  v17 = v5->mResolvedOffset;
  if ( (_DWORD)v17 == -1 )
    goto LABEL_5;
  v18 = &v12[v17];
  v19 = v5->mArrayIndex.mOffset;
  if ( v19 && (UFG::qOffset64<UEL::Expression *> *)((char *)&v5->mArrayIndex + v19) && !v5->mArrayIndexIndexesBitField )
  {
    v20 = *(__int64 **)v18;
    v58 = (UEL::Value::Type)&resulta;
    v21 = UEL::Expression::GetValueType((UEL::Expression *)&v5->vfptr, &resulta);
    v22 = UEL::Value::GetSizeOfValueType((UEL::Value::Type)v21);
    v23 = v5->mArrayIndex.mOffset;
    if ( v23 )
      v24 = (signed __int64)&v5->mArrayIndex + v23;
    else
      v24 = 0i64;
    v18 = (UEL::ParametersBase *)v20
        + *(_QWORD *)(*(__int64 (__fastcall **)(signed __int64, UFG::qString *, __int64, __int64, __int64))(*(_QWORD *)v24 + 24i64))(
                       v24,
                       &v63,
                       v65,
                       v66,
                       v67)
        * v22;
    v8 = 1;
  }
  if ( v5->mNeedsCall )
  {
    v25 = fastdelegate::FastDelegate0<UEL::Value>::operator()(
            (fastdelegate::FastDelegate1<UFG::qSymbol const &,UEL::Value> *)v18,
            (UEL::Value *)((char *)&v57 + 16),
            v16);
    UEL::Value::operator=(&v57, v25);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mName);
    v59 = (UEL::Value::Type)&v58;
    UEL::Expression::GetValueType((UEL::Expression *)&v5->vfptr, &v58);
    v59 = (UEL::Value::Type)&resulta;
    resulta.mBaseType.mValue = v57.type.mBaseType.mValue;
    resulta.mDetailedType.mUID = v57.type.mDetailedType.mUID;
    v26 = (UFG::qSymbolUC *)UEL::Expression::GetValueType((UEL::Expression *)&v5->vfptr, &v56);
    UFG::qSymbol::as_cstr_dbg(v26 + 1);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v57.type.mDetailedType);
  }
  else
  {
    v27 = v5->mWithinParameter.mOffset;
    v31 = 0;
    if ( v27 )
    {
      v28 = (UEL::Expression *)((char *)&v5->mWithinParameter + v27);
      if ( v28 )
      {
        v29 = UFG::gNullQSymbol.mUID;
        v7 = 3;
        *(_DWORD *)&v56.mBaseType.mValue = 3;
        v30 = UEL::Expression::GetValueType(v28, &v56);
        if ( v30->mBaseType.mValue == 9 && v29 == v30->mDetailedType.mUID )
          v31 = 1;
      }
    }
    if ( v7 & 2 )
    {
      v7 &= 0xFFFFFFFD;
      *(_DWORD *)&v56.mBaseType.mValue = v7;
    }
    if ( v7 & 1 )
    {
      v7 &= 0xFFFFFFFE;
      *(_DWORD *)&v56.mBaseType.mValue = v7;
    }
    if ( v31 )
    {
      v32 = fastdelegate::FastDelegate0<UEL::Value>::operator()(
              (fastdelegate::FastDelegate1<UFG::qSymbol const &,UEL::Value> *)v18,
              (UEL::Value *)((char *)&v57 + 16),
              &v5->mName);
      UEL::Value::operator=(&v57, v32);
      v33 = UFG::gNullQSymbol.mUID;
      v34 = v7 | 0xC;
      *(_DWORD *)&v56.mBaseType.mValue = v34;
      v35 = UEL::Expression::GetValueType((UEL::Expression *)&v5->vfptr, &v56);
      if ( 0 != v35->mBaseType.mValue || v33 != v35->mDetailedType.mUID )
      {
        v34 |= 0x10u;
        *(_DWORD *)&v56.mBaseType.mValue = v34;
        UEL::Expression::GetValueType((UEL::Expression *)&v5->vfptr, &v59);
      }
      v36 = v5->mWithinParameter.mOffset;
      if ( v36 )
        v6 = (UFG::qSymbolUC *)((char *)&v5->mWithinParameter + v36);
      UFG::qSymbol::as_cstr_dbg(v6 + 17);
      v57.integer = (__int64)&v58;
      UEL::Expression::GetValueType((UEL::Expression *)&v5->vfptr, &v58);
      v57.integer = (__int64)&resulta;
      resulta.mBaseType.mValue = v57.type.mBaseType.mValue;
      resulta.mDetailedType.mUID = v57.type.mDetailedType.mUID;
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mName);
      v37 = (UFG::qSymbolUC *)UEL::Expression::GetValueType(
                                (UEL::Expression *)&v5->vfptr,
                                (UEL::Value::Type *)&v57.qVector_y);
      UFG::qSymbol::as_cstr_dbg(v37 + 1);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v57.type.mDetailedType);
      if ( v34 & 0x10 )
      {
        v34 &= 0xFFFFFFEF;
        *(_DWORD *)&v56.mBaseType.mValue = v34;
      }
      if ( v34 & 8 )
      {
        v34 &= 0xFFFFFFF7;
        *(_DWORD *)&v56.mBaseType.mValue = v34;
      }
      if ( v34 & 4 )
        *(_DWORD *)&v56.mBaseType.mValue = v34 & 0xFFFFFFFB;
    }
    else
    {
      v38 = UEL::Expression::GetValueType((UEL::Expression *)&v5->vfptr, (UEL::Value::Type *)&v57.qVector_y);
      v57.type.mBaseType.mValue = v38->mBaseType.mValue;
      v57.type.mDetailedType.mUID = v38->mDetailedType.mUID;
      switch ( v57.type.mBaseType.mValue )
      {
        case 1u:
          v39 = *(__int64 **)v18;
          if ( v8 )
            goto LABEL_80;
          v57.integer = *v39;
          break;
        case 2u:
          if ( v8 )
            v40 = *(_DWORD *)v18;
          else
            v40 = **(_DWORD **)v18;
          v57.type.mBaseType.mValue = 2;
          v57.type.mDetailedType = UFG::gNullQSymbol;
          LODWORD(v57.integer) = (UFG::qWiseSymbol)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&resulta, v40)->mUID;
          break;
        case 3u:
          if ( v8 )
            v41 = *(const char **)v18;
          else
            v41 = **(const char ***)v18;
          v57.type.mBaseType.mValue = 2;
          v57.type.mDetailedType = UFG::gNullQSymbol;
          LODWORD(v57.integer) = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&resulta, v41)->mUID;
          break;
        case 4u:
          if ( v8 )
            v57.qSymbol_mUID = *(_DWORD *)v18;
          else
            v57.qSymbol_mUID = **(_DWORD **)v18;
          break;
        case 5u:
          if ( v5->mArrayIndexIndexesBitField )
          {
            v42 = v5->mArrayIndex.mOffset;
            if ( v42 )
              v6 = (UFG::qSymbolUC *)((char *)&v5->mArrayIndex + v42);
            v43 = (signed int *)(*(__int64 (__fastcall **)(UFG::qSymbolUC *, float *, __int64, __int64, __int64))(*(_QWORD *)&v6->mUID + 24i64))(
                                  v6,
                                  &v57.qVector_w,
                                  v65,
                                  v66,
                                  v67);
            v44 = *v43;
            v45 = *v43 & 0x3F;
            if ( v8 )
            {
              v46 = (unsigned __int8)v45;
              v47 = *(_QWORD **)&v18[8 * (v44 >> 6)];
              v48 = _bittest64((const signed __int64 *)&v47, v46);
            }
            else
            {
              v49 = *(_QWORD *)(*(_QWORD *)v18 + 8 * (v44 >> 6));
              v48 = _bittest64(&v49, (unsigned __int8)v45);
            }
            v57.boolean = v48;
          }
          else if ( v8 )
          {
            v57.boolean = *v18 != 0;
          }
          else
          {
            v57.boolean = **(_BYTE **)v18 != 0;
          }
          break;
        case 6u:
          if ( v8 )
            v57.qSymbol_mUID = *(_DWORD *)v18;
          else
            v57.qSymbol_mUID = **(_DWORD **)v18;
          v57.type.mDetailedType.mUID = v5->mEnumBinding->name.mUID;
          break;
        case 7u:
          if ( !v8 )
            v18 = *(UEL::ParametersBase **)v18;
          v50 = *(float *)&v18[12];
          v51 = *(float *)&v18[8];
          v52 = *(float *)&v18[4];
          v53 = *(_DWORD *)v18;
          v57.type.mBaseType.mValue = 7;
          v57.type.mDetailedType = UFG::gNullQSymbol;
          v57.qSymbol_mUID = v53;
          v57.qVector_y = v52;
          v57.qVector_z = v51;
          v57.qVector_w = v50;
          break;
        case 8u:
          v39 = *(__int64 **)v18;
LABEL_80:
          v57.integer = (__int64)v39;
          break;
        case 9u:
          v57.integer = (__int64)v18;
          break;
        default:
          break;
      }
    }
  }
  v54 = UEL::Value::ToString(&v57, &v63);
  UFG::qString::FormatEx((UFG::qString *)&v57.qVector_w, " [%s])", v54->mData);
  UFG::qString::~qString((UFG::qString *)&v57.qVector_w);
  UFG::qString::~qString(&v63);
  v4->integer = v57.integer;
  v4->qSymbol_mUID = v57.qSymbol_mUID;
  v4->qVector_y = v57.qVector_y;
  v4->qVector_z = v57.qVector_z;
  v4->qVector_w = v57.qVector_w;
  v4->type.mBaseType.mValue = v57.type.mBaseType.mValue;
  v11 = v57.type.mDetailedType.mUID;
LABEL_83:
  v4->type.mDetailedType.mUID = v11;
  return v4;
}

