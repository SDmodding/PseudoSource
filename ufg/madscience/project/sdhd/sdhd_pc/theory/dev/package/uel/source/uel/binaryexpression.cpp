// File Line: 6
// RVA: 0x1475E70
__int64 dynamic_initializer_for__UEL::BinaryExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BinaryExpression", 0xFFFFFFFF);
  UEL::BinaryExpression::sClassNameUID = result;
  return result;
}

// File Line: 19
// RVA: 0x24DFE0
void __fastcall UEL::BinaryExpression::BinaryExpression(
        UEL::BinaryExpression *this,
        UEL::BinaryExpression::Type type,
        UEL::Expression *leftExpression,
        UEL::Expression *rightExpression)
{
  UFG::qOffset64<UEL::Expression *> *p_mLeftExpression; // rax
  char *v5; // r8
  UFG::qOffset64<UEL::Expression *> *p_mRightExpression; // rax
  char *v7; // r9

  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->UEL::Expression::mType.mValue = 1;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::BinaryExpression::`vftable;
  p_mLeftExpression = &this->mLeftExpression;
  if ( leftExpression )
    v5 = (char *)((char *)leftExpression - (char *)p_mLeftExpression);
  else
    v5 = 0i64;
  p_mLeftExpression->mOffset = (__int64)v5;
  p_mRightExpression = &this->mRightExpression;
  if ( rightExpression )
    v7 = (char *)((char *)rightExpression - (char *)p_mRightExpression);
  else
    v7 = 0i64;
  p_mRightExpression->mOffset = (__int64)v7;
  this->mType.mValue = type;
}

// File Line: 29
// RVA: 0x2522E0
bool __fastcall UEL::BinaryExpression::Resolve(UEL::BinaryExpression *this, UEL::Runtime *instance)
{
  UEL::Expression *v4; // rdi
  UFG::qOffset64<UEL::Expression *> *p_mLeftExpression; // r14
  __int64 mOffset; // rax
  char *v7; // rcx
  bool v8; // al
  UFG::qOffset64<UEL::Expression *> *p_mRightExpression; // rsi
  __int64 v10; // rax
  char *v11; // rcx
  unsigned int mUID; // r15d
  UEL::Expression *v13; // rcx
  UEL::Value::Type *ValueType; // rax
  unsigned int v15; // r15d
  UEL::Expression *v16; // rcx
  UEL::Value::Type *v17; // rax
  char v18; // al
  unsigned int v19; // eax
  unsigned int v20; // r15d
  UEL::Expression *v21; // rcx
  UEL::Value::Type *v22; // rax
  unsigned int v23; // r15d
  UEL::Expression *v24; // rcx
  UEL::Value::Type *v25; // rax
  char v26; // al
  UFG::allocator::free_link *v27; // rax
  UEL::Expression *v28; // r8
  __int64 v29; // rax
  __int64 v30; // r15
  unsigned int v31; // r15d
  UEL::Expression *v32; // rcx
  UEL::Value::Type *v33; // rax
  unsigned int v34; // r15d
  UEL::Expression *v35; // rcx
  UEL::Value::Type *v36; // rax
  char v37; // al
  UFG::allocator::free_link *v38; // rax
  UEL::Expression *v39; // r8
  __int64 v40; // rax
  __int64 v41; // r15
  unsigned int v42; // r15d
  UEL::Expression *v43; // rcx
  UEL::Value::Type *v44; // rax
  unsigned int v45; // r15d
  UEL::Expression *v46; // rcx
  UEL::Value::Type *v47; // rax
  char v48; // al
  UFG::allocator::free_link *v49; // rax
  UEL::Expression *v50; // r8
  __int64 v51; // rax
  __int64 v52; // rbx
  unsigned int v53; // r15d
  UEL::Expression *v54; // rcx
  UEL::Value::Type *v55; // rax
  unsigned int v56; // r15d
  UEL::Expression *v57; // rcx
  UEL::Value::Type *v58; // rax
  char v59; // al
  UFG::allocator::free_link *v60; // rax
  UEL::Expression *v61; // r8
  __int64 v62; // rax
  __int64 v63; // rbx
  UEL::Expression *v64; // rcx
  UEL::Value::Type *v65; // rbx
  UEL::Expression *v66; // rcx
  UEL::Value::Type *v67; // rax
  UEL::Expression *v68; // rcx
  UEL::Value::Type *v69; // rbx
  UEL::Value::Type *v70; // rax
  UEL::Value::Type *OperationResultType; // rax
  UEL::Value::Type v72; // [rsp+38h] [rbp-8h] BYREF
  UEL::Value::Type result; // [rsp+80h] [rbp+40h] BYREF
  UEL::Value::Type v74; // [rsp+90h] [rbp+50h] BYREF
  UEL::Value::Type *p_result; // [rsp+98h] [rbp+58h]

  v4 = 0i64;
  p_mLeftExpression = &this->mLeftExpression;
  mOffset = this->mLeftExpression.mOffset;
  v7 = (char *)&this->mLeftExpression + mOffset;
  if ( !mOffset )
    v7 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v7 + 16i64))(v7) )
    return 0;
  p_mRightExpression = &this->mRightExpression;
  v10 = this->mRightExpression.mOffset;
  v11 = (char *)&this->mRightExpression + v10;
  if ( !v10 )
    v11 = 0i64;
  if ( !(*(unsigned __int8 (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v11 + 16i64))(v11, instance) )
    return 0;
  mUID = UFG::gNullQSymbol.mUID;
  v13 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
  if ( !p_mLeftExpression->mOffset )
    v13 = 0i64;
  ValueType = UEL::Expression::GetValueType(v13, &result);
  if ( !ValueType->mBaseType.mValue && mUID == ValueType->mDetailedType.mUID )
    goto LABEL_16;
  v15 = UFG::gNullQSymbol.mUID;
  v16 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
  if ( !p_mRightExpression->mOffset )
    v16 = 0i64;
  v17 = UEL::Expression::GetValueType(v16, &v74);
  if ( v17->mBaseType.mValue || v15 != v17->mDetailedType.mUID )
    v18 = 0;
  else
LABEL_16:
    v18 = 1;
  if ( v18 )
  {
    this->mNeedsRuntimeResolve = 1;
    v19 = UFG::gNullQSymbol.mUID;
    this->mValueType.mBaseType.mValue = 0;
    this->mValueType.mDetailedType.mUID = v19;
    return 1;
  }
  v20 = UFG::gNullQSymbol.mUID;
  v21 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
  if ( !p_mLeftExpression->mOffset )
    v21 = 0i64;
  v22 = UEL::Expression::GetValueType(v21, &result);
  if ( v22->mBaseType.mValue != 1 || v20 != v22->mDetailedType.mUID )
    goto LABEL_29;
  v23 = UFG::gNullQSymbol.mUID;
  v24 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
  if ( !p_mRightExpression->mOffset )
    v24 = 0i64;
  v25 = UEL::Expression::GetValueType(v24, &v74);
  if ( v25->mBaseType.mValue == 6 && v23 == v25->mDetailedType.mUID )
    v26 = 1;
  else
LABEL_29:
    v26 = 0;
  if ( v26 )
  {
    v27 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    result = (UEL::Value::Type)v27;
    if ( v27 )
    {
      v28 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
      if ( !p_mRightExpression->mOffset )
        v28 = 0i64;
      UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v27, CastToInteger, v28);
      v30 = v29;
    }
    else
    {
      v30 = 0i64;
    }
    if ( !(*(unsigned __int8 (__fastcall **)(__int64, UEL::Runtime *))(*(_QWORD *)v30 + 16i64))(v30, instance) )
      return 0;
    p_mRightExpression->mOffset = v30 - (_QWORD)p_mRightExpression;
  }
  else
  {
    v31 = UFG::gNullQSymbol.mUID;
    v32 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
    if ( !p_mLeftExpression->mOffset )
      v32 = 0i64;
    v33 = UEL::Expression::GetValueType(v32, &result);
    if ( v33->mBaseType.mValue != 6 || v31 != v33->mDetailedType.mUID )
      goto LABEL_47;
    v34 = UFG::gNullQSymbol.mUID;
    v35 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
    if ( !p_mRightExpression->mOffset )
      v35 = 0i64;
    v36 = UEL::Expression::GetValueType(v35, &v74);
    if ( v36->mBaseType.mValue == 1 && v34 == v36->mDetailedType.mUID )
      v37 = 1;
    else
LABEL_47:
      v37 = 0;
    if ( v37 )
    {
      v38 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      result = (UEL::Value::Type)v38;
      if ( v38 )
      {
        v39 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
        if ( !p_mLeftExpression->mOffset )
          v39 = 0i64;
        UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v38, CastToInteger, v39);
        v41 = v40;
      }
      else
      {
        v41 = 0i64;
      }
      if ( !(*(unsigned __int8 (__fastcall **)(__int64, UEL::Runtime *))(*(_QWORD *)v41 + 16i64))(v41, instance) )
        return 0;
      p_mLeftExpression->mOffset = v41 - (_QWORD)p_mLeftExpression;
    }
  }
  v42 = UFG::gNullQSymbol.mUID;
  v43 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
  if ( !p_mLeftExpression->mOffset )
    v43 = 0i64;
  v44 = UEL::Expression::GetValueType(v43, &result);
  if ( v44->mBaseType.mValue != 4 || v42 != v44->mDetailedType.mUID )
    goto LABEL_65;
  v45 = UFG::gNullQSymbol.mUID;
  v46 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
  if ( !p_mRightExpression->mOffset )
    v46 = 0i64;
  v47 = UEL::Expression::GetValueType(v46, &v74);
  if ( v47->mBaseType.mValue == 1 && v45 == v47->mDetailedType.mUID )
    v48 = 1;
  else
LABEL_65:
    v48 = 0;
  if ( v48 )
  {
    v49 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    result = (UEL::Value::Type)v49;
    if ( v49 )
    {
      v50 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
      if ( !p_mRightExpression->mOffset )
        v50 = 0i64;
      UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v49, CastToReal, v50);
      v52 = v51;
    }
    else
    {
      v52 = 0i64;
    }
    if ( !(*(unsigned __int8 (__fastcall **)(__int64, UEL::Runtime *))(*(_QWORD *)v52 + 16i64))(v52, instance) )
      return 0;
    p_mRightExpression->mOffset = v52 - (_QWORD)p_mRightExpression;
  }
  else
  {
    v53 = UFG::gNullQSymbol.mUID;
    v54 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
    if ( !p_mLeftExpression->mOffset )
      v54 = 0i64;
    v55 = UEL::Expression::GetValueType(v54, &result);
    if ( v55->mBaseType.mValue != 1 || v53 != v55->mDetailedType.mUID )
      goto LABEL_83;
    v56 = UFG::gNullQSymbol.mUID;
    v57 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
    if ( !p_mRightExpression->mOffset )
      v57 = 0i64;
    v58 = UEL::Expression::GetValueType(v57, &v74);
    if ( v58->mBaseType.mValue == 4 && v56 == v58->mDetailedType.mUID )
      v59 = 1;
    else
LABEL_83:
      v59 = 0;
    if ( v59 )
    {
      v60 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      result = (UEL::Value::Type)v60;
      if ( v60 )
      {
        v61 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
        if ( !p_mLeftExpression->mOffset )
          v61 = 0i64;
        UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v60, CastToReal, v61);
        v63 = v62;
      }
      else
      {
        v63 = 0i64;
      }
      if ( !(*(unsigned __int8 (__fastcall **)(__int64, UEL::Runtime *))(*(_QWORD *)v63 + 16i64))(v63, instance) )
        return 0;
      p_mLeftExpression->mOffset = v63 - (_QWORD)p_mLeftExpression;
    }
  }
  p_result = &result;
  v64 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
  if ( !p_mRightExpression->mOffset )
    v64 = 0i64;
  v65 = UEL::Expression::GetValueType(v64, &result);
  if ( p_mLeftExpression->mOffset )
    v66 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
  else
    v66 = 0i64;
  v67 = UEL::Expression::GetValueType(v66, &v74);
  if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
          (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
          (UEL::Value::Type)v67,
          (UEL::Value::Type)v65) )
    return 0;
  p_result = &result;
  v68 = (UEL::Expression *)((char *)p_mRightExpression + p_mRightExpression->mOffset);
  if ( !p_mRightExpression->mOffset )
    v68 = 0i64;
  v69 = UEL::Expression::GetValueType(v68, &result);
  if ( p_mLeftExpression->mOffset )
    v4 = (UEL::Expression *)((char *)p_mLeftExpression + p_mLeftExpression->mOffset);
  v70 = UEL::Expression::GetValueType(v4, &v74);
  OperationResultType = UEL::BinaryExpression::GetOperationResultType(
                          &v72,
                          (unsigned __int8)this->mType.mValue,
                          (UEL::Value::Type)v70,
                          (UEL::Value::Type)v69);
  this->mValueType.mBaseType.mValue = OperationResultType->mBaseType.mValue;
  this->mValueType.mDetailedType.mUID = OperationResultType->mDetailedType.mUID;
  v8 = 1;
  this->mResolved = 1;
  return v8;
}

// File Line: 94
// RVA: 0x24F7E0
UEL::Value *__fastcall UEL::BinaryExpression::Eval(
        UEL::BinaryExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *parameters,
        UFG::qArray<UEL::Value,0> *args)
{
  __int64 mOffset; // rax
  char *v9; // rcx
  unsigned __int16 mValue; // bx
  UEL::Value::Type *ValueType; // rax
  __int64 v12; // rax
  char *v13; // rcx
  int v14; // eax
  UEL::Value::Type *OperationResultType; // rax
  __int64 v16; // rax
  char *v17; // rcx
  UEL::Value::Type *v18; // rax
  __int64 v19; // rax
  char *v20; // rcx
  UEL::Value::Type *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  __int64 v26; // rax
  char *v27; // rcx
  UEL::Value::Type *v28; // rax
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  __int64 v33; // rax
  char *v34; // rcx
  UEL::Value::Type *v35; // rax
  __int64 v36; // rax
  char *v37; // rcx
  UEL::Value::Type *v38; // rax
  __int64 v39; // rax
  char *v40; // rcx
  UEL::Value::Type *v41; // rax
  __int64 v42; // rax
  char *v43; // rcx
  UEL::Value::Type *v44; // rax
  __int64 v45; // rax
  char *v46; // rcx
  UEL::Value::Type *v47; // rax
  __int64 v48; // rax
  __int64 v49; // rax
  char *v50; // rcx
  UEL::Value::Type *v51; // rax
  __int64 v52; // rax
  char *v53; // rcx
  UEL::Value::Type *v54; // rax
  __int64 v55; // rax
  char *v56; // rcx
  UEL::Value::Type *v57; // rax
  UFG::qString *v58; // rax
  UEL::Value retLeft; // [rsp+38h] [rbp-A0h] BYREF
  UFG::qString resulta; // [rsp+58h] [rbp-80h] BYREF
  unsigned int mUID; // [rsp+80h] [rbp-58h]
  UEL::Value::Type v63; // [rsp+88h] [rbp-50h] BYREF
  UEL::Value::Type v64; // [rsp+90h] [rbp-48h] BYREF
  UEL::Value::Type v65; // [rsp+98h] [rbp-40h] BYREF
  UEL::Value::Type v66; // [rsp+A0h] [rbp-38h] BYREF
  UEL::Value::Type v67; // [rsp+A8h] [rbp-30h] BYREF
  UEL::Value::Type v68; // [rsp+B0h] [rbp-28h] BYREF
  UEL::Value::Type v69; // [rsp+B8h] [rbp-20h] BYREF
  UEL::Value::Type v70; // [rsp+C0h] [rbp-18h] BYREF
  UEL::Value::Type v71; // [rsp+C8h] [rbp-10h] BYREF
  UEL::Value::Type v72; // [rsp+D0h] [rbp-8h] BYREF
  UEL::Value::Type v73; // [rsp+D8h] [rbp+0h] BYREF
  UEL::Value::Type v74; // [rsp+E0h] [rbp+8h] BYREF
  UEL::Value::Type v75; // [rsp+E8h] [rbp+10h] BYREF
  UEL::Value::Type v76; // [rsp+F0h] [rbp+18h] BYREF
  UEL::Value::Type v77; // [rsp+F8h] [rbp+20h] BYREF
  UEL::Value::Type v78; // [rsp+100h] [rbp+28h] BYREF
  UEL::Value::Type v79; // [rsp+108h] [rbp+30h] BYREF
  UEL::Value::Type v80; // [rsp+110h] [rbp+38h] BYREF
  UEL::Value::Type v81; // [rsp+118h] [rbp+40h] BYREF
  UEL::Value::Type v82; // [rsp+120h] [rbp+48h] BYREF
  UEL::Value::Type v83; // [rsp+128h] [rbp+50h] BYREF
  UEL::Value::Type v84; // [rsp+130h] [rbp+58h] BYREF
  UEL::Value::Type v85; // [rsp+138h] [rbp+60h] BYREF
  UEL::Value::Type v86; // [rsp+140h] [rbp+68h] BYREF
  UEL::Value::Type v87; // [rsp+148h] [rbp+70h] BYREF
  UEL::Value::Type v88; // [rsp+150h] [rbp+78h] BYREF
  UEL::Value::Type v89; // [rsp+158h] [rbp+80h] BYREF
  UEL::Value::Type v90; // [rsp+160h] [rbp+88h] BYREF
  UEL::Value::Type v91; // [rsp+168h] [rbp+90h] BYREF
  UEL::Value::Type v92; // [rsp+170h] [rbp+98h] BYREF
  UEL::Value::Type v93; // [rsp+178h] [rbp+A0h] BYREF
  UEL::Value::Type v94; // [rsp+180h] [rbp+A8h] BYREF
  UEL::Value::Type v95; // [rsp+188h] [rbp+B0h] BYREF
  UEL::Value::Type v96; // [rsp+190h] [rbp+B8h] BYREF
  UEL::Value::Type v97; // [rsp+198h] [rbp+C0h] BYREF
  UEL::Value::Type v98; // [rsp+1A0h] [rbp+C8h] BYREF
  UEL::Value::Type v99; // [rsp+1A8h] [rbp+D0h] BYREF
  UEL::Value::Type left; // [rsp+1B0h] [rbp+D8h] BYREF
  UEL::Value::Type v101; // [rsp+1B8h] [rbp+E0h] BYREF
  UEL::Value::Type v102; // [rsp+1C0h] [rbp+E8h] BYREF
  UEL::Value::Type v103; // [rsp+1C8h] [rbp+F0h] BYREF
  UEL::Value::Type v104; // [rsp+1D0h] [rbp+F8h] BYREF
  UEL::Value::Type v105; // [rsp+1D8h] [rbp+100h] BYREF
  UEL::Value::Type v106; // [rsp+1E0h] [rbp+108h] BYREF
  UEL::Value::Type v107; // [rsp+1E8h] [rbp+110h] BYREF
  UEL::Value::Type v108; // [rsp+1F0h] [rbp+118h] BYREF
  UEL::Value::Type v109; // [rsp+1F8h] [rbp+120h] BYREF
  __int64 v110; // [rsp+200h] [rbp+128h]
  UEL::Value::Type v111; // [rsp+208h] [rbp+130h] BYREF
  UEL::Value::Type v112; // [rsp+210h] [rbp+138h] BYREF
  UEL::Value::Type v113; // [rsp+218h] [rbp+140h] BYREF
  UEL::Value::Type v114; // [rsp+220h] [rbp+148h] BYREF
  UEL::Value::Type v115; // [rsp+228h] [rbp+150h] BYREF
  UEL::Value::Type v116; // [rsp+230h] [rbp+158h] BYREF
  UEL::Value::Type v117; // [rsp+238h] [rbp+160h] BYREF
  UEL::Value::Type v118; // [rsp+240h] [rbp+168h] BYREF
  UEL::Value::Type v119; // [rsp+248h] [rbp+170h] BYREF
  UEL::Value::Type v120; // [rsp+250h] [rbp+178h] BYREF
  UEL::Value::Type v121; // [rsp+258h] [rbp+180h] BYREF
  UEL::Value::Type v122; // [rsp+260h] [rbp+188h] BYREF
  UFG::qString v123; // [rsp+268h] [rbp+190h] BYREF
  UEL::Value::Type right; // [rsp+2C8h] [rbp+1F0h] BYREF
  void *retaddr; // [rsp+2E8h] [rbp+210h]

  v110 = -2i64;
  UFG::qString::qString(&resulta, "(");
  UFG::qString::~qString(&resulta);
  LOWORD(resulta.mStringHashUpper32) = 0;
  mUID = UFG::gNullQSymbol.mUID;
  mOffset = this->mLeftExpression.mOffset;
  if ( mOffset )
    v9 = (char *)&this->mLeftExpression + mOffset;
  else
    v9 = 0i64;
  (*(void (__fastcall **)(char *, UEL::Value *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v9 + 24i64))(
    v9,
    &retLeft,
    parameters,
    args,
    retaddr);
  UFG::qString::FormatEx(&resulta, " %s ", UEL::BinaryExpressionTypeStrings[(unsigned __int8)this->mType.mValue]);
  UFG::qString::~qString(&resulta);
  mValue = retLeft.type.mBaseType.mValue;
  *(_DWORD *)&right.mBaseType.mValue = retLeft.type.mDetailedType.mUID;
  ValueType = UEL::Expression::GetValueType(this, &v63);
  LOWORD(resulta.mStringHashUpper32) = ValueType->mBaseType.mValue;
  mUID = ValueType->mDetailedType.mUID;
  switch ( this->mType.mValue )
  {
    case 0:
      if ( !retLeft.boolean )
        goto LABEL_15;
      v12 = this->mRightExpression.mOffset;
      if ( v12 )
        v13 = (char *)&this->mRightExpression + v12;
      else
        v13 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v13 + 24i64))(
        v13,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( this->mNeedsRuntimeResolve )
      {
        UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
        resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&right;
        resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&left;
        right.mBaseType.mValue = resulta.mLength;
        right.mDetailedType.mUID = (unsigned int)resulta.mData;
        left.mBaseType.mValue = retLeft.type.mBaseType.mValue;
        left.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
        if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
                (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
                (UEL::Value::Type)&left,
                (UEL::Value::Type)&right) )
          goto LABEL_11;
        resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v85;
        resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v103;
        v85.mBaseType.mValue = resulta.mLength;
        v85.mDetailedType.mUID = (unsigned int)resulta.mData;
        v103.mBaseType.mValue = retLeft.type.mBaseType.mValue;
        v103.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
        OperationResultType = UEL::BinaryExpression::GetOperationResultType(
                                &v117,
                                (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
                                (UEL::Value::Type)&v103,
                                (UEL::Value::Type)&v85);
        LOWORD(resulta.mStringHashUpper32) = OperationResultType->mBaseType.mValue;
        mUID = OperationResultType->mDetailedType.mUID;
      }
      if ( !retLeft.boolean )
        goto LABEL_15;
      goto LABEL_14;
    case 1:
      v16 = this->mRightExpression.mOffset;
      if ( v16 )
        v17 = (char *)&this->mRightExpression + v16;
      else
        v17 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v17 + 24i64))(
        v17,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_22;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v105;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v107;
      v105.mBaseType.mValue = resulta.mLength;
      v105.mDetailedType.mUID = (unsigned int)resulta.mData;
      v107.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v107.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v107,
              (UEL::Value::Type)&v105) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v109;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v88;
      v109.mBaseType.mValue = resulta.mLength;
      v109.mDetailedType.mUID = (unsigned int)resulta.mData;
      v88.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v88.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v18 = UEL::BinaryExpression::GetOperationResultType(
              &v119,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v88,
              (UEL::Value::Type)&v109);
      LOWORD(resulta.mStringHashUpper32) = v18->mBaseType.mValue;
      mUID = v18->mDetailedType.mUID;
LABEL_22:
      if ( retLeft.boolean )
        goto LABEL_70;
LABEL_14:
      if ( LOBYTE(resulta.mPrev) )
LABEL_70:
        LOBYTE(resulta.mMagic) = 1;
      else
LABEL_15:
        LOBYTE(resulta.mMagic) = 0;
      goto LABEL_167;
    case 2:
      v19 = this->mRightExpression.mOffset;
      if ( v19 )
        v20 = (char *)&this->mRightExpression + v19;
      else
        v20 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v20 + 24i64))(
        v20,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_30;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v66;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v102;
      v66.mBaseType.mValue = resulta.mLength;
      v66.mDetailedType.mUID = (unsigned int)resulta.mData;
      v102.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v102.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v102,
              (UEL::Value::Type)&v66) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v68;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v96;
      v68.mBaseType.mValue = resulta.mLength;
      v68.mDetailedType.mUID = (unsigned int)resulta.mData;
      v96.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v96.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v21 = UEL::BinaryExpression::GetOperationResultType(
              &v121,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v96,
              (UEL::Value::Type)&v68);
      LOWORD(resulta.mStringHashUpper32) = v21->mBaseType.mValue;
      mUID = v21->mDetailedType.mUID;
LABEL_30:
      switch ( mValue )
      {
        case 1u:
          LOBYTE(resulta.mMagic) = (UFG::qNode<UFG::qString,UFG::qString> *)retLeft.integer != resulta.mPrev;
          goto LABEL_167;
        case 2u:
        case 6u:
          LOBYTE(resulta.mMagic) = retLeft.qSymbol_mUID != LODWORD(resulta.mPrev);
          goto LABEL_167;
        case 3u:
          UFG::qStringCompare(retLeft.string, (const char *)resulta.mPrev, -1);
          goto $LN95_0;
        case 4u:
$LN95_0:
          v22 = retLeft.real - *(float *)&resulta.mPrev;
          if ( (float)(retLeft.real - *(float *)&resulta.mPrev) < 0.0 )
            LODWORD(v22) ^= _xmm[0];
          LOBYTE(resulta.mMagic) = v22 >= 0.001;
          break;
        case 5u:
          LOBYTE(resulta.mMagic) = retLeft.boolean != LOBYTE(resulta.mPrev);
          break;
        case 7u:
          v23 = retLeft.real - *(float *)&resulta.mPrev;
          if ( (float)(retLeft.real - *(float *)&resulta.mPrev) < 0.0 )
            LODWORD(v23) ^= _xmm[0];
          if ( v23 < 0.001 )
          {
            v24 = retLeft.qVector_y - *(float *)&resulta.mNext;
            if ( (float)(retLeft.qVector_y - *(float *)&resulta.mNext) < 0.0 )
              LODWORD(v24) ^= _xmm[0];
            if ( v24 < 0.001 )
            {
              v25 = retLeft.qVector_z - *((float *)&resulta.mNext + 1);
              if ( (float)(retLeft.qVector_z - *((float *)&resulta.mNext + 1)) < 0.0 )
                LODWORD(v25) ^= _xmm[0];
              if ( v25 < 0.001 )
                goto LABEL_15;
            }
          }
          goto LABEL_70;
        default:
          goto LABEL_167;
      }
      goto LABEL_167;
    case 3:
      v33 = this->mRightExpression.mOffset;
      if ( v33 )
        v34 = (char *)&this->mRightExpression + v33;
      else
        v34 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v34 + 24i64))(
        v34,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_78;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v74;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v87;
      v74.mBaseType.mValue = resulta.mLength;
      v74.mDetailedType.mUID = (unsigned int)resulta.mData;
      v87.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v87.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v87,
              (UEL::Value::Type)&v74) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v76;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v89;
      v76.mBaseType.mValue = resulta.mLength;
      v76.mDetailedType.mUID = (unsigned int)resulta.mData;
      v89.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v89.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v35 = UEL::BinaryExpression::GetOperationResultType(
              &v118,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v89,
              (UEL::Value::Type)&v76);
      LOWORD(resulta.mStringHashUpper32) = v35->mBaseType.mValue;
      mUID = v35->mDetailedType.mUID;
LABEL_78:
      switch ( mValue )
      {
        case 1u:
          LOBYTE(resulta.mMagic) = retLeft.integer <= (__int64)resulta.mPrev;
          break;
        case 4u:
          LOBYTE(resulta.mMagic) = *(float *)&resulta.mPrev >= retLeft.real;
          break;
        case 6u:
          LOBYTE(resulta.mMagic) = (signed int)retLeft.qSymbol_mUID <= SLODWORD(resulta.mPrev);
          break;
      }
      goto LABEL_167;
    case 4:
      v36 = this->mRightExpression.mOffset;
      if ( v36 )
        v37 = (char *)&this->mRightExpression + v36;
      else
        v37 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v37 + 24i64))(
        v37,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_90;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v78;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v91;
      v78.mBaseType.mValue = resulta.mLength;
      v78.mDetailedType.mUID = (unsigned int)resulta.mData;
      v91.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v91.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v91,
              (UEL::Value::Type)&v78) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v80;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v93;
      v80.mBaseType.mValue = resulta.mLength;
      v80.mDetailedType.mUID = (unsigned int)resulta.mData;
      v93.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v93.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v38 = UEL::BinaryExpression::GetOperationResultType(
              &v114,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v93,
              (UEL::Value::Type)&v80);
      LOWORD(resulta.mStringHashUpper32) = v38->mBaseType.mValue;
      mUID = v38->mDetailedType.mUID;
LABEL_90:
      switch ( mValue )
      {
        case 1u:
          LOBYTE(resulta.mMagic) = retLeft.integer >= (__int64)resulta.mPrev;
          break;
        case 4u:
          LOBYTE(resulta.mMagic) = retLeft.real >= *(float *)&resulta.mPrev;
          break;
        case 6u:
          LOBYTE(resulta.mMagic) = (signed int)retLeft.qSymbol_mUID >= SLODWORD(resulta.mPrev);
          break;
      }
      goto LABEL_167;
    case 5:
      v39 = this->mRightExpression.mOffset;
      if ( v39 )
        v40 = (char *)&this->mRightExpression + v39;
      else
        v40 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v40 + 24i64))(
        v40,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_102;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v82;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v95;
      v82.mBaseType.mValue = resulta.mLength;
      v82.mDetailedType.mUID = (unsigned int)resulta.mData;
      v95.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v95.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v95,
              (UEL::Value::Type)&v82) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v84;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v97;
      v84.mBaseType.mValue = resulta.mLength;
      v84.mDetailedType.mUID = (unsigned int)resulta.mData;
      v97.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v97.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v41 = UEL::BinaryExpression::GetOperationResultType(
              &v122,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v97,
              (UEL::Value::Type)&v84);
      LOWORD(resulta.mStringHashUpper32) = v41->mBaseType.mValue;
      mUID = v41->mDetailedType.mUID;
LABEL_102:
      switch ( mValue )
      {
        case 1u:
          LOBYTE(resulta.mMagic) = retLeft.integer < (__int64)resulta.mPrev;
          break;
        case 4u:
          LOBYTE(resulta.mMagic) = *(float *)&resulta.mPrev > retLeft.real;
          break;
        case 6u:
          LOBYTE(resulta.mMagic) = (signed int)retLeft.qSymbol_mUID < SLODWORD(resulta.mPrev);
          break;
      }
      goto LABEL_167;
    case 6:
      v42 = this->mRightExpression.mOffset;
      if ( v42 )
        v43 = (char *)&this->mRightExpression + v42;
      else
        v43 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v43 + 24i64))(
        v43,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_114;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v86;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v99;
      v86.mBaseType.mValue = resulta.mLength;
      v86.mDetailedType.mUID = (unsigned int)resulta.mData;
      v99.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v99.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v99,
              (UEL::Value::Type)&v86) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v101;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v104;
      v101.mBaseType.mValue = resulta.mLength;
      v101.mDetailedType.mUID = (unsigned int)resulta.mData;
      v104.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v104.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v44 = UEL::BinaryExpression::GetOperationResultType(
              &v116,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v104,
              (UEL::Value::Type)&v101);
      LOWORD(resulta.mStringHashUpper32) = v44->mBaseType.mValue;
      mUID = v44->mDetailedType.mUID;
LABEL_114:
      switch ( mValue )
      {
        case 1u:
          LOBYTE(resulta.mMagic) = retLeft.integer > (__int64)resulta.mPrev;
          break;
        case 4u:
          LOBYTE(resulta.mMagic) = retLeft.real > *(float *)&resulta.mPrev;
          break;
        case 6u:
          LOBYTE(resulta.mMagic) = (signed int)retLeft.qSymbol_mUID > SLODWORD(resulta.mPrev);
          break;
      }
      goto LABEL_167;
    case 7:
      v26 = this->mRightExpression.mOffset;
      if ( v26 )
        v27 = (char *)&this->mRightExpression + v26;
      else
        v27 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v27 + 24i64))(
        v27,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_54;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v70;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v106;
      v70.mBaseType.mValue = resulta.mLength;
      v70.mDetailedType.mUID = (unsigned int)resulta.mData;
      v106.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v106.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v106,
              (UEL::Value::Type)&v70) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v72;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v98;
      v72.mBaseType.mValue = resulta.mLength;
      v72.mDetailedType.mUID = (unsigned int)resulta.mData;
      v98.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v98.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v28 = UEL::BinaryExpression::GetOperationResultType(
              &v112,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v98,
              (UEL::Value::Type)&v72);
      LOWORD(resulta.mStringHashUpper32) = v28->mBaseType.mValue;
      mUID = v28->mDetailedType.mUID;
LABEL_54:
      switch ( mValue )
      {
        case 1u:
          LOBYTE(resulta.mMagic) = (UFG::qNode<UFG::qString,UFG::qString> *)retLeft.integer == resulta.mPrev;
          break;
        case 2u:
        case 6u:
          LOBYTE(resulta.mMagic) = retLeft.qSymbol_mUID == LODWORD(resulta.mPrev);
          break;
        case 3u:
          LOBYTE(resulta.mMagic) = (unsigned int)UFG::qStringCompare(retLeft.string, (const char *)resulta.mPrev, -1) == 0;
          break;
        case 4u:
          v29 = retLeft.real - *(float *)&resulta.mPrev;
          if ( (float)(retLeft.real - *(float *)&resulta.mPrev) < 0.0 )
            LODWORD(v29) ^= _xmm[0];
          LOBYTE(resulta.mMagic) = v29 < 0.001;
          break;
        case 5u:
          LOBYTE(resulta.mMagic) = retLeft.boolean == LOBYTE(resulta.mPrev);
          break;
        case 7u:
          v30 = retLeft.real - *(float *)&resulta.mPrev;
          if ( (float)(retLeft.real - *(float *)&resulta.mPrev) < 0.0 )
            LODWORD(v30) ^= _xmm[0];
          if ( v30 < 0.001 )
          {
            v31 = retLeft.qVector_y - *(float *)&resulta.mNext;
            if ( (float)(retLeft.qVector_y - *(float *)&resulta.mNext) < 0.0 )
              LODWORD(v31) ^= _xmm[0];
            if ( v31 < 0.001 )
            {
              v32 = retLeft.qVector_z - *((float *)&resulta.mNext + 1);
              if ( (float)(retLeft.qVector_z - *((float *)&resulta.mNext + 1)) < 0.0 )
                LODWORD(v32) ^= _xmm[0];
              if ( v32 < 0.001 )
                goto LABEL_70;
            }
          }
          goto LABEL_15;
        default:
          goto LABEL_167;
      }
      goto LABEL_167;
    case 8:
      v45 = this->mRightExpression.mOffset;
      if ( v45 )
        v46 = (char *)&this->mRightExpression + v45;
      else
        v46 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v46 + 24i64))(
        v46,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_126;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v90;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v64;
      v90.mBaseType.mValue = resulta.mLength;
      v90.mDetailedType.mUID = (unsigned int)resulta.mData;
      v64.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v64.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v64,
              (UEL::Value::Type)&v90) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v92;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v108;
      v92.mBaseType.mValue = resulta.mLength;
      v92.mDetailedType.mUID = (unsigned int)resulta.mData;
      v108.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v108.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v47 = UEL::BinaryExpression::GetOperationResultType(
              &v120,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v108,
              (UEL::Value::Type)&v92);
      LOWORD(resulta.mStringHashUpper32) = v47->mBaseType.mValue;
      mUID = v47->mDetailedType.mUID;
LABEL_126:
      switch ( mValue )
      {
        case 1u:
          v48 = retLeft.integer - (unsigned __int64)resulta.mPrev;
          goto LABEL_166;
        case 4u:
          *(float *)&resulta.mMagic = retLeft.real - *(float *)&resulta.mPrev;
          break;
        case 7u:
          LOWORD(resulta.mStringHashUpper32) = 7;
          mUID = UFG::gNullQSymbol.mUID;
          *(float *)&resulta.mMagic = retLeft.real - *(float *)&resulta.mPrev;
          *(float *)&resulta.mData = *(&retLeft.real + 1) - *((float *)&resulta.mPrev + 1);
          *((float *)&resulta.mData + 1) = retLeft.qVector_y - *(float *)&resulta.mNext;
          break;
      }
      goto LABEL_167;
    case 9:
      v49 = this->mRightExpression.mOffset;
      if ( v49 )
        v50 = (char *)&this->mRightExpression + v49;
      else
        v50 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v50 + 24i64))(
        v50,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_138;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v94;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v65;
      v94.mBaseType.mValue = resulta.mLength;
      v94.mDetailedType.mUID = (unsigned int)resulta.mData;
      v65.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v65.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v65,
              (UEL::Value::Type)&v94) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v67;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v69;
      v67.mBaseType.mValue = resulta.mLength;
      v67.mDetailedType.mUID = (unsigned int)resulta.mData;
      v69.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v69.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v51 = UEL::BinaryExpression::GetOperationResultType(
              &v111,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v69,
              (UEL::Value::Type)&v67);
      LOWORD(resulta.mStringHashUpper32) = v51->mBaseType.mValue;
      mUID = v51->mDetailedType.mUID;
LABEL_138:
      switch ( mValue )
      {
        case 1u:
          *(_QWORD *)&resulta.mMagic = (char *)resulta.mPrev + retLeft.integer;
          break;
        case 4u:
          *(float *)&resulta.mMagic = *(float *)&resulta.mPrev + retLeft.real;
          break;
        case 7u:
          LOWORD(resulta.mStringHashUpper32) = 7;
          mUID = UFG::gNullQSymbol.mUID;
          *(float *)&resulta.mMagic = *(float *)&resulta.mPrev + retLeft.real;
          *(float *)&resulta.mData = *((float *)&resulta.mPrev + 1) + *(&retLeft.real + 1);
          *((float *)&resulta.mData + 1) = *(float *)&resulta.mNext + retLeft.qVector_y;
          break;
      }
      goto LABEL_167;
    case 0xA:
      v52 = this->mRightExpression.mOffset;
      if ( v52 )
        v53 = (char *)&this->mRightExpression + v52;
      else
        v53 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v53 + 24i64))(
        v53,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_150;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v71;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v73;
      v71.mBaseType.mValue = resulta.mLength;
      v71.mDetailedType.mUID = (unsigned int)resulta.mData;
      v73.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v73.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( !UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v73,
              (UEL::Value::Type)&v71) )
        goto LABEL_11;
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v75;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v77;
      v75.mBaseType.mValue = resulta.mLength;
      v75.mDetailedType.mUID = (unsigned int)resulta.mData;
      v77.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v77.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      v54 = UEL::BinaryExpression::GetOperationResultType(
              &v113,
              (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
              (UEL::Value::Type)&v77,
              (UEL::Value::Type)&v75);
      LOWORD(resulta.mStringHashUpper32) = v54->mBaseType.mValue;
      mUID = v54->mDetailedType.mUID;
LABEL_150:
      if ( mValue == 1 )
      {
        v48 = retLeft.integer / (__int64)resulta.mPrev;
        goto LABEL_166;
      }
      if ( mValue == 4 )
        *(float *)&resulta.mMagic = retLeft.real / *(float *)&resulta.mPrev;
      goto LABEL_167;
    case 0xB:
      v55 = this->mRightExpression.mOffset;
      if ( v55 )
        v56 = (char *)&this->mRightExpression + v55;
      else
        v56 = 0i64;
      (*(void (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v56 + 24i64))(
        v56,
        &resulta,
        parameters,
        args,
        retaddr);
      if ( !this->mNeedsRuntimeResolve )
        goto LABEL_160;
      UEL::BinaryExpression::PerformRuntimeCast(this, &retLeft, (UEL::Value *)&resulta);
      resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v79;
      resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v81;
      v79.mBaseType.mValue = resulta.mLength;
      v79.mDetailedType.mUID = (unsigned int)resulta.mData;
      v81.mBaseType.mValue = retLeft.type.mBaseType.mValue;
      v81.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
      if ( UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
             (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
             (UEL::Value::Type)&v81,
             (UEL::Value::Type)&v79) )
      {
        resulta.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v83;
        resulta.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v63;
        v83.mBaseType.mValue = resulta.mLength;
        v83.mDetailedType.mUID = (unsigned int)resulta.mData;
        v63.mBaseType.mValue = retLeft.type.mBaseType.mValue;
        v63.mDetailedType.mUID = retLeft.type.mDetailedType.mUID;
        v57 = UEL::BinaryExpression::GetOperationResultType(
                &v115,
                (UEL::BinaryExpression::Type)(unsigned __int8)this->mType.mValue,
                (UEL::Value::Type)&v63,
                (UEL::Value::Type)&v83);
        LOWORD(resulta.mStringHashUpper32) = v57->mBaseType.mValue;
        mUID = v57->mDetailedType.mUID;
LABEL_160:
        switch ( mValue )
        {
          case 1u:
            v48 = retLeft.integer * (__int64)resulta.mPrev;
LABEL_166:
            *(_QWORD *)&resulta.mMagic = v48;
            break;
          case 4u:
            *(float *)&resulta.mMagic = *(float *)&resulta.mPrev * retLeft.real;
            break;
          case 7u:
            LOWORD(resulta.mStringHashUpper32) = 7;
            mUID = UFG::gNullQSymbol.mUID;
            *(float *)&resulta.mMagic = *(float *)&resulta.mPrev * retLeft.real;
            *(float *)&resulta.mData = *(&retLeft.real + 1) * *(float *)&resulta.mPrev;
            *((float *)&resulta.mData + 1) = *(float *)&resulta.mPrev * retLeft.qVector_y;
            break;
        }
LABEL_167:
        v58 = UEL::Value::ToString((UEL::Value *)&resulta.mMagic, &v123);
        UFG::qString::FormatEx(&resulta, " [%s])", v58->mData);
        UFG::qString::~qString(&resulta);
        UFG::qString::~qString(&v123);
        result->integer = *(_QWORD *)&resulta.mMagic;
        result->qSymbol_mUID = resulta.mMagic;
        *(_QWORD *)&result->qVector_y = resulta.mData;
        LODWORD(result->qVector_w) = resulta.mStringHash32;
        result->type.mBaseType.mValue = resulta.mStringHashUpper32;
        v14 = mUID;
      }
      else
      {
LABEL_11:
        result->type.mBaseType.mValue = 0;
        v14 = UFG::gNullQSymbol.mUID;
      }
      result->type.mDetailedType.mUID = v14;
      return result;
    default:
      goto LABEL_167;
  }
}

// File Line: 557
// RVA: 0x251E80
void __fastcall UEL::BinaryExpression::PerformRuntimeCast(
        UEL::BinaryExpression *this,
        UEL::Value *retLeft,
        UEL::Value *retRight)
{
  unsigned __int16 mValue; // r10
  unsigned int mUID; // eax
  unsigned __int16 v7; // r10

  mValue = retLeft->type.mBaseType.mValue;
  mUID = UFG::gNullQSymbol.mUID;
  if ( mValue == 1
    && UFG::gNullQSymbol.mUID == retLeft->type.mDetailedType.mUID
    && retRight->type.mBaseType.mValue == 6
    && UFG::gNullQSymbol.mUID == retRight->type.mDetailedType.mUID )
  {
    retRight->type.mBaseType.mValue = 1;
    retRight->type.mDetailedType.mUID = mUID;
    retRight->integer = retRight->enumeration;
LABEL_17:
    mUID = UFG::gNullQSymbol.mUID;
    goto LABEL_18;
  }
  if ( mValue == 6
    && UFG::gNullQSymbol.mUID == retLeft->type.mDetailedType.mUID
    && retRight->type.mBaseType.mValue == 1
    && UFG::gNullQSymbol.mUID == retRight->type.mDetailedType.mUID )
  {
    retLeft->type.mBaseType.mValue = 1;
    retLeft->type.mDetailedType.mUID = mUID;
    retLeft->integer = retLeft->enumeration;
    goto LABEL_17;
  }
LABEL_18:
  v7 = retLeft->type.mBaseType.mValue;
  if ( v7 == 4
    && mUID == retLeft->type.mDetailedType.mUID
    && retRight->type.mBaseType.mValue == 1
    && mUID == retRight->type.mDetailedType.mUID )
  {
    retRight->type.mBaseType.mValue = 4;
    retRight->type.mDetailedType.mUID = mUID;
    retRight->real = (float)(int)retRight->integer;
  }
  else if ( v7 == 1
         && mUID == retLeft->type.mDetailedType.mUID
         && retRight->type.mBaseType.mValue == 4
         && mUID == retRight->type.mDetailedType.mUID )
  {
    retLeft->type.mBaseType.mValue = 4;
    retLeft->type.mDetailedType.mUID = mUID;
    retLeft->real = (float)(int)retLeft->integer;
  }
}

// File Line: 583
// RVA: 0x253980
_BOOL8 __fastcall UEL::BinaryExpression::ValueTypesAreConsistentWithExpressionType(
        UEL::BinaryExpression::Type type,
        UEL::Value::Type left,
        UEL::Value::Type right)
{
  char v3; // r9
  bool v5; // r10
  __int16 v6; // cx
  char v7; // dl
  _BOOL8 result; // rax
  __int16 v9; // r10
  int v10; // ecx
  __int16 v11; // r9

  v3 = 0;
  v5 = 1;
  switch ( type )
  {
    case And:
    case Or:
      v6 = *(_WORD *)left.mBaseType.mValue;
      v7 = 1;
      v5 = 0;
      if ( *(_WORD *)left.mBaseType.mValue == 5 && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&left + 4i64)
        || (v7 = 3, v6 == 8) && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&left + 4i64) )
      {
        if ( (v7 |= 4u, *(_WORD *)right.mBaseType.mValue == 5)
          && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&right + 4i64)
          || (v7 |= 8u, *(_WORD *)right.mBaseType.mValue == 8)
          && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&right + 4i64) )
        {
          v5 = 1;
        }
      }
      if ( (v7 & 8) != 0 )
        v7 &= ~8u;
      if ( (v7 & 4) != 0 )
        v7 &= ~4u;
      if ( (v7 & 2) != 0 )
        v7 &= ~2u;
      if ( (v7 & 1) == 0 )
        goto LABEL_52;
      result = v5;
      break;
    case NotEqual:
    case Equal:
      result = *(_WORD *)right.mBaseType.mValue == *(_WORD *)left.mBaseType.mValue
            && *(_DWORD *)(*(_QWORD *)&right + 4i64) == *(_DWORD *)(*(_QWORD *)&left + 4i64);
      break;
    case LesserOrEqual:
    case GreaterOrEqual:
    case Lesser:
    case Greater:
      v9 = *(_WORD *)left.mBaseType.mValue;
      v5 = 0;
      if ( *(_WORD *)right.mBaseType.mValue == *(_WORD *)left.mBaseType.mValue )
      {
        v10 = *(_DWORD *)(*(_QWORD *)&left + 4i64);
        if ( *(_DWORD *)(*(_QWORD *)&right + 4i64) == v10 )
        {
          if ( (v3 = 16, v9 == 1) && UFG::gNullQSymbol.mUID == v10
            || (v3 = 48, v9 == 4) && UFG::gNullQSymbol.mUID == v10 )
          {
            v5 = 1;
          }
        }
      }
      if ( (v3 & 0x20) != 0 )
        v3 &= ~0x20u;
      if ( (v3 & 0x10) == 0 )
        goto LABEL_52;
      result = v5;
      break;
    case Minus:
    case Plus:
    case Div:
    case Times:
      v11 = *(_WORD *)left.mBaseType.mValue;
      v5 = *(_WORD *)left.mBaseType.mValue == 4
        && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&left + 4i64)
        && *(_WORD *)right.mBaseType.mValue == 4
        && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&right + 4i64)
        || v11 == 1
        && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&left + 4i64)
        && *(_WORD *)right.mBaseType.mValue == 1
        && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&right + 4i64)
        || v11 == 7
        && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&left + 4i64)
        && (*(_WORD *)right.mBaseType.mValue == 4 && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&right + 4i64)
         || *(_WORD *)right.mBaseType.mValue == 1 && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&right + 4i64));
      goto LABEL_52;
    default:
LABEL_52:
      result = v5;
      break;
  }
  return result;
}

// File Line: 634
// RVA: 0x251D50
UEL::Value::Type *__fastcall UEL::BinaryExpression::GetOperationResultType(
        UEL::Value::Type *result,
        int type,
        UEL::Value::Type left,
        UEL::Value::Type right)
{
  if ( type >= 0 )
  {
    if ( type <= 7 )
    {
      result->mBaseType.mValue = 5;
      result->mDetailedType = UFG::gNullQSymbol;
      return result;
    }
    if ( type <= 11 )
    {
      result->mBaseType.mValue = *(_WORD *)left.mBaseType.mValue;
      result->mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&left + 4i64);
      return result;
    }
  }
  result->mBaseType.mValue = 0;
  result->mDetailedType = UFG::gNullQSymbol;
  return result;
}

