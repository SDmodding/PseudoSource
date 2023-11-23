// File Line: 68
// RVA: 0x1475F70
__int64 dynamic_initializer_for__UEL::Value::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Value", 0xFFFFFFFF);
  UEL::Value::sClassNameUID = result;
  return result;
}

// File Line: 69
// RVA: 0x1475F30
__int64 dynamic_initializer_for__UEL::Value::Type::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Type", 0xFFFFFFFF);
  UEL::Value::Type::sClassNameUID = result;
  return result;
}

// File Line: 72
// RVA: 0x1475E20
__int64 dynamic_initializer_for__UEL::Value::msStringTable__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UEL::Value::msStringTable__);
}

// File Line: 75
// RVA: 0x2537B0
UFG::qString *__fastcall UEL::Value::ToString(UEL::Value *this, UFG::qString *result)
{
  __int64 mValue; // rcx
  char *v5; // r8
  const char *v6; // r8
  char *v7; // rax

  mValue = this->type.mBaseType.mValue;
  switch ( (int)mValue )
  {
    case 0:
      UFG::qString::qString(result, "None.");
      break;
    case 1:
      UFG::qString::FormatEx(result, "Integer %d", this->integer);
      break;
    case 2:
      v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)this);
      UFG::qString::FormatEx(result, "Symbol %s", v5);
      break;
    case 3:
      UFG::qString::FormatEx(result, "String %s", this->integer);
      break;
    case 4:
      UFG::qString::FormatEx(result, "Real %f", this->real);
      break;
    case 5:
      v6 = "FALSE";
      if ( this->boolean )
        v6 = "TRUE";
      UFG::qString::FormatEx(result, "Boolean %s", v6);
      break;
    case 6:
      v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->type.mDetailedType);
      UFG::qString::FormatEx(result, "Enum %s, %d", v7, this->qSymbol_mUID);
      break;
    case 7:
      UFG::qString::FormatEx(result, "Vector %f,%f,%f", this->real, this->qVector_y, this->qVector_z);
      break;
    case 8:
      UFG::qString::FormatEx(result, "Struct %p", this->integer);
      break;
    case 9:
      UFG::qString::FormatEx(result, "Lookup %x", this->integer);
      break;
    case 10:
      UFG::qString::FormatEx(result, "Getter %x", this->integer);
      break;
    default:
      if ( (unsigned int)mValue > 0xC )
        UFG::qString::FormatEx(result, "Array of %s", UEL::BinaryExpressionTypeStrings[mValue]);
      else
        UFG::qString::qString(result, "ERROR!");
      break;
  }
  return result;
}

// File Line: 114
// RVA: 0x251DF0
__int64 __fastcall UEL::Value::GetSizeOfValueType(UEL::Value::Type v)
{
  unsigned int v1; // edx
  __int64 result; // rax

  v1 = -1;
  switch ( *(_WORD *)v.mBaseType.mValue )
  {
    case 1:
    case 3:
    case 8:
      v1 = 8;
      goto LABEL_6;
    case 2:
    case 4:
    case 6:
      result = 4i64;
      break;
    case 5:
      result = 1i64;
      break;
    case 7:
      result = 12i64;
      break;
    default:
LABEL_6:
      result = v1;
      break;
  }
  return result;
}

// File Line: 172
// RVA: 0x24E980
UEL::Expression *__fastcall CreateInternal(ANTLR3_BASE_TREE_struct *ast)
{
  UFG::allocator::free_link *v2; // rbx
  ANTLR3_BASE_TREE_struct *v3; // rax
  UEL::Expression *v4; // rax
  UEL::Expression *v5; // rax
  UEL::Expression *v6; // rdi
  UEL::Expression *result; // rax
  ANTLR3_BASE_TREE_struct *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  ANTLR3_STRING_struct *v10; // rax
  UEL::Expression *v11; // rax
  UEL::Expression *v12; // rdi
  UFG::allocator::free_link *v13; // rbx
  ANTLR3_STRING_struct *v14; // rax
  UEL::Expression *v15; // rax
  UEL::Expression *v16; // rdi
  UFG::allocator::free_link *v17; // rbx
  ANTLR3_STRING_struct *v18; // rax
  UEL::Expression *v19; // rax
  UEL::Expression *v20; // rdi
  UFG::allocator::free_link *v21; // rbx
  ANTLR3_STRING_struct *v22; // rax
  UEL::Expression *v23; // rax
  UEL::Expression *v24; // rdi
  UFG::allocator::free_link *v25; // rbx
  ANTLR3_STRING_struct *v26; // rax
  UEL::Expression *v27; // rax
  UEL::Expression *v28; // rdi
  UFG::allocator::free_link *v29; // rbx
  ANTLR3_STRING_struct *v30; // rax
  UEL::Expression *v31; // rax
  UEL::Expression *v32; // rdi
  __int64 (__fastcall **v33)(void *); // rbx
  UFG::allocator::free_link *v34; // rdi
  __int64 v35; // rbx
  __int64 v36; // rax
  UEL::Expression *v37; // rax
  UEL::Expression *v38; // rdi
  UFG::allocator::free_link *v39; // rbx
  ANTLR3_BASE_TREE_struct *v40; // rax
  UEL::Expression *v41; // rax
  UEL::Expression *v42; // rax
  UEL::Expression *v43; // rdi
  UFG::allocator::free_link *v44; // rbx
  ANTLR3_BASE_TREE_struct *v45; // rax
  UEL::Expression *v46; // rax
  UEL::Expression *v47; // rax
  UEL::Expression *v48; // rdi
  ANTLR3_BASE_TREE_struct *v49; // rax
  UEL::Expression *v50; // rbx
  ANTLR3_BASE_TREE_struct *v51; // rax
  UEL::Expression *v52; // rax
  UEL::Expression *v53; // rax
  UEL::Expression *v54; // rdi
  ANTLR3_BASE_TREE_struct *v55; // rax
  UEL::Expression *v56; // rbx
  ANTLR3_BASE_TREE_struct *v57; // rax
  UEL::Expression *v58; // rax
  UEL::Expression *v59; // rax
  UEL::Expression *v60; // rdi
  ANTLR3_BASE_TREE_struct *v61; // rax
  UEL::Expression *v62; // rbx
  ANTLR3_BASE_TREE_struct *v63; // rax
  UEL::Expression *v64; // rax
  UEL::Expression *v65; // rax
  UEL::Expression *v66; // rdi
  ANTLR3_BASE_TREE_struct *v67; // rax
  UEL::Expression *v68; // rbx
  ANTLR3_BASE_TREE_struct *v69; // rax
  UEL::Expression *v70; // rax
  UEL::Expression *v71; // rax
  UEL::Expression *v72; // rdi
  ANTLR3_BASE_TREE_struct *v73; // rax
  UEL::Expression *v74; // rbx
  ANTLR3_BASE_TREE_struct *v75; // rax
  UEL::Expression *v76; // rax
  UEL::Expression *v77; // rax
  UEL::Expression *v78; // rdi
  ANTLR3_BASE_TREE_struct *v79; // rax
  UEL::Expression *v80; // rbx
  ANTLR3_BASE_TREE_struct *v81; // rax
  UEL::Expression *v82; // rax
  UEL::Expression *v83; // rax
  UEL::Expression *v84; // rdi
  ANTLR3_BASE_TREE_struct *v85; // rax
  UEL::Expression *v86; // rbx
  ANTLR3_BASE_TREE_struct *v87; // rax
  UEL::Expression *v88; // rax
  UEL::Expression *v89; // rax
  UEL::Expression *v90; // rdi
  ANTLR3_BASE_TREE_struct *v91; // rax
  UEL::Expression *v92; // rbx
  ANTLR3_BASE_TREE_struct *v93; // rax
  UEL::Expression *v94; // rax
  UEL::Expression *v95; // rax
  UEL::Expression *v96; // rdi
  ANTLR3_BASE_TREE_struct *v97; // rax
  UEL::Expression *v98; // rbx
  ANTLR3_BASE_TREE_struct *v99; // rax
  UEL::Expression *v100; // rax
  UEL::Expression *v101; // rax
  UEL::Expression *v102; // rdi
  ANTLR3_BASE_TREE_struct *v103; // rax
  UEL::Expression *v104; // rbx
  ANTLR3_BASE_TREE_struct *v105; // rax
  UEL::Expression *v106; // rax
  UEL::Expression *v107; // rax
  UEL::Expression *v108; // rdi
  ANTLR3_BASE_TREE_struct *v109; // rax
  UEL::Expression *Internal; // rbx
  ANTLR3_BASE_TREE_struct *v111; // rax
  UEL::Expression *v112; // rax
  UEL::Expression *v113; // rax
  UEL::Expression *v114; // rdi
  ANTLR3_BASE_TREE_struct *v115; // rax
  UEL::Expression *v116; // rbx
  ANTLR3_BASE_TREE_struct *v117; // rax
  UEL::Expression *v118; // rax
  UEL::Expression *v119; // rax
  UEL::Expression *v120; // rdi
  unsigned __int64 v121; // rax
  UEL::Expression *v122; // rdi
  __int64 v123; // rbx
  unsigned int v124; // edi
  ANTLR3_BASE_TREE_struct *v125; // rax
  UFG::allocator::free_link *v126; // rbx
  ANTLR3_STRING_struct *v127; // rax
  UEL::Expression *v128; // rax
  signed int v129; // eax
  __int64 v130; // rbx
  unsigned __int64 v131; // rax
  unsigned __int64 v132; // kr10_8
  unsigned int v133; // edi
  __int64 v134; // rcx
  UEL::Expression **v135; // rbx
  ANTLR3_BASE_TREE_struct *v136; // rax
  UEL::Expression **v137; // rbx
  __int64 v138; // rax
  UEL::Expression *v139; // rax
  UEL::Expression *v140; // rdi
  __int64 (__fastcall **v141)(void *); // rbx
  const char *v142; // rbx
  UFG::allocator::free_link *v143; // rax
  UEL::Expression *v144; // rax
  UEL::Expression *v145; // rdi
  __int64 (__fastcall **v146)(void *, _QWORD); // rbx
  ANTLR3_BASE_TREE_struct *v147; // rdi
  const char *v148; // rsi
  UFG::allocator::free_link *v149; // rbx
  UEL::Expression *v150; // rax
  UEL::Expression *v151; // rax
  UEL::Expression *v152; // rdi
  ANTLR3_BASE_TREE_struct *v153; // rbx
  UFG::allocator::free_link *v154; // rsi
  UEL::Expression *v155; // rdi
  UEL::Expression *v156; // rax
  UEL::Value::Type v157; // [rsp+30h] [rbp-48h] BYREF
  UEL::Value::Type v158; // [rsp+38h] [rbp-40h] BYREF
  UEL::Value::Type v159; // [rsp+40h] [rbp-38h] BYREF
  UEL::Value::Type v160; // [rsp+48h] [rbp-30h] BYREF
  UEL::Value::Type v161; // [rsp+50h] [rbp-28h] BYREF
  UEL::Expression **expressions; // [rsp+58h] [rbp-20h]
  UEL::Value::Type *v163; // [rsp+60h] [rbp-18h]
  __int64 v164; // [rsp+68h] [rbp-10h]
  UEL::BinaryExpression *v165; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v166; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v167; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v168; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v169; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v170; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v171; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v172; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v173; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v174; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v175; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v176; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v177; // [rsp+A0h] [rbp+28h]
  signed int v178; // [rsp+A0h] [rbp+28h]
  int v179; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v180; // [rsp+A0h] [rbp+28h]
  char *chars; // [rsp+A0h] [rbp+28h]
  UEL::Expression **args; // [rsp+A8h] [rbp+30h]
  UEL::Value::Type type; // [rsp+B0h] [rbp+38h] BYREF
  UEL::Value::Type v184; // [rsp+B8h] [rbp+40h] BYREF

  v164 = -2i64;
  switch ( ((unsigned int (*)(void))ast->getType)() )
  {
    case 6u:
      v176 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v176 )
      {
        v109 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        Internal = CreateInternal(v109);
        v111 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v112 = CreateInternal(v111);
        UEL::BinaryExpression::BinaryExpression(v176, And, v112, Internal);
        v114 = v113;
      }
      else
      {
        v114 = 0i64;
      }
      result = v114;
      break;
    case 7u:
      v141 = (__int64 (__fastcall **)(void *))ast->getChild(ast, 0i64);
      ast->getChild(ast, 1u);
      v142 = *(const char **)(v141[23](v141) + 8);
      v143 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
      if ( v143 )
      {
        UEL::ArgumentUsageExpression::ArgumentUsageExpression((UEL::ArgumentUsageExpression *)v143, v142);
        v145 = v144;
      }
      else
      {
        v145 = 0i64;
      }
      result = v145;
      break;
    case 8u:
      v25 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
      if ( v25 )
      {
        v159.mBaseType.mValue = 5;
        v159.mDetailedType = UFG::gNullQSymbol;
        v26 = ast->getText(ast);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v25,
          v26->chars,
          0i64,
          (UEL::Value::Type)&v159);
        v28 = v27;
      }
      else
      {
        v28 = 0i64;
      }
      result = v28;
      break;
    case 9u:
    case 0xAu:
      v8 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
      result = CreateInternal(v8);
      break;
    case 0xCu:
      v167 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v167 )
      {
        v55 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v56 = CreateInternal(v55);
        v57 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v58 = CreateInternal(v57);
        UEL::BinaryExpression::BinaryExpression(v167, Div, v58, v56);
        v60 = v59;
      }
      else
      {
        v60 = 0i64;
      }
      result = v60;
      break;
    case 0xEu:
      v174 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v174 )
      {
        v97 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v98 = CreateInternal(v97);
        v99 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v100 = CreateInternal(v99);
        UEL::BinaryExpression::BinaryExpression(v174, Equal, v100, v98);
        v102 = v101;
      }
      else
      {
        v102 = 0i64;
      }
      result = v102;
      break;
    case 0x10u:
      v129 = ast->getChildCount(ast);
      v130 = v129;
      v179 = v129 - 1;
      v132 = v129 - 1;
      v131 = 8 * v132;
      if ( !is_mul_ok(v132, 8ui64) )
        v131 = -1i64;
      args = (UEL::Expression **)UFG::qMalloc(v131, UFG::gGlobalNewName, 0i64);
      v163 = (UEL::Value::Type *)ast->getChild(ast, 0i64);
      v133 = 1;
      v134 = v130;
      if ( v130 > 1 )
      {
        v135 = args;
        expressions = (UEL::Expression **)(v134 - 1);
        do
        {
          v136 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, v133);
          *v135 = CreateInternal(v136);
          ++v133;
          ++v135;
          expressions = (UEL::Expression **)((char *)expressions - 1);
        }
        while ( expressions );
      }
      v137 = (UEL::Expression **)UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
      expressions = v137;
      if ( v137 )
      {
        v138 = (*(__int64 (__fastcall **)(UEL::Value::Type *))&v163[23])(v163);
        UEL::FragmentInvocationExpression::FragmentInvocationExpression(
          (UEL::FragmentInvocationExpression *)v137,
          *(const char **)(v138 + 8),
          v179,
          args);
        v140 = v139;
      }
      else
      {
        v140 = 0i64;
      }
      operator delete[](args);
      result = v140;
      break;
    case 0x11u:
      v178 = ast->getChildCount(ast);
      v121 = 8i64 * v178;
      if ( !is_mul_ok(v178, 8ui64) )
        v121 = -1i64;
      expressions = (UEL::Expression **)UFG::qMalloc(v121, UFG::gGlobalNewName, 0i64);
      v122 = 0i64;
      v123 = 0i64;
      if ( v178 > 0 )
      {
        v124 = 0;
        do
        {
          v125 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, v124);
          expressions[v123] = CreateInternal(v125);
          ++v124;
          ++v123;
        }
        while ( v123 < v178 );
        v122 = 0i64;
      }
      v126 = UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
      if ( v126 )
      {
        v127 = ast->getText(ast);
        UEL::InvocationExpression::InvocationExpression(
          (UEL::InvocationExpression *)v126,
          v127->chars,
          expressions,
          v178);
        v122 = v128;
      }
      operator delete[](expressions);
      result = v122;
      break;
    case 0x12u:
      v173 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v173 )
      {
        v91 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v92 = CreateInternal(v91);
        v93 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v94 = CreateInternal(v93);
        UEL::BinaryExpression::BinaryExpression(v173, GreaterOrEqual, v94, v92);
        v96 = v95;
      }
      else
      {
        v96 = 0i64;
      }
      result = v96;
      break;
    case 0x13u:
      v172 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v172 )
      {
        v85 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v86 = CreateInternal(v85);
        v87 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v88 = CreateInternal(v87);
        UEL::BinaryExpression::BinaryExpression(v172, Greater, v88, v86);
        v90 = v89;
      }
      else
      {
        v90 = 0i64;
      }
      result = v90;
      break;
    case 0x15u:
      v21 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
      if ( v21 )
      {
        v158.mBaseType.mValue = 1;
        v158.mDetailedType = UFG::gNullQSymbol;
        v22 = ast->getText(ast);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v21,
          v22->chars,
          0i64,
          (UEL::Value::Type)&v158);
        v24 = v23;
      }
      else
      {
        v24 = 0i64;
      }
      result = v24;
      break;
    case 0x17u:
      v171 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v171 )
      {
        v79 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v80 = CreateInternal(v79);
        v81 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v82 = CreateInternal(v81);
        UEL::BinaryExpression::BinaryExpression(v171, LesserOrEqual, v82, v80);
        v84 = v83;
      }
      else
      {
        v84 = 0i64;
      }
      result = v84;
      break;
    case 0x18u:
      v170 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v170 )
      {
        v73 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v74 = CreateInternal(v73);
        v75 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v76 = CreateInternal(v75);
        UEL::BinaryExpression::BinaryExpression(v170, Lesser, v76, v74);
        v78 = v77;
      }
      else
      {
        v78 = 0i64;
      }
      result = v78;
      break;
    case 0x19u:
      v169 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v169 )
      {
        v67 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v68 = CreateInternal(v67);
        v69 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v70 = CreateInternal(v69);
        UEL::BinaryExpression::BinaryExpression(v169, Minus, v70, v68);
        v72 = v71;
      }
      else
      {
        v72 = 0i64;
      }
      result = v72;
      break;
    case 0x1Bu:
      v166 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v166 )
      {
        v49 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v50 = CreateInternal(v49);
        v51 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v52 = CreateInternal(v51);
        UEL::BinaryExpression::BinaryExpression(v166, Times, v52, v50);
        v54 = v53;
      }
      else
      {
        v54 = 0i64;
      }
      result = v54;
      break;
    case 0x1Cu:
      v44 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v44 )
      {
        v45 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v46 = CreateInternal(v45);
        UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v44, Negate, v46);
        v48 = v47;
      }
      else
      {
        v48 = 0i64;
      }
      result = v48;
      break;
    case 0x1Du:
      v39 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v39 )
      {
        v40 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v41 = CreateInternal(v40);
        UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v39, Not, v41);
        v43 = v42;
      }
      else
      {
        v43 = 0i64;
      }
      result = v43;
      break;
    case 0x1Eu:
      v175 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v175 )
      {
        v103 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v104 = CreateInternal(v103);
        v105 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v106 = CreateInternal(v105);
        UEL::BinaryExpression::BinaryExpression(v175, NotEqual, v106, v104);
        v108 = v107;
      }
      else
      {
        v108 = 0i64;
      }
      result = v108;
      break;
    case 0x1Fu:
      v177 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v177 )
      {
        v115 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v116 = CreateInternal(v115);
        v117 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v118 = CreateInternal(v117);
        UEL::BinaryExpression::BinaryExpression(v177, Or, v118, v116);
        v120 = v119;
      }
      else
      {
        v120 = 0i64;
      }
      result = v120;
      break;
    case 0x20u:
      v153 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
      chars = ast->getText(ast)->chars;
      v154 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
      if ( v154 )
      {
        if ( v153 )
          v155 = CreateInternal(v153);
        else
          v155 = 0i64;
        UEL::ParameterExpression::ParameterExpression((UEL::ParameterExpression *)v154, chars, 0i64, v155);
        v32 = v156;
      }
      else
      {
        v32 = 0i64;
      }
      goto LABEL_126;
    case 0x21u:
      v2 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v2 )
      {
        v3 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v4 = CreateInternal(v3);
        UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v2, Parenthesize, v4);
        v6 = v5;
      }
      else
      {
        v6 = 0i64;
      }
      result = v6;
      break;
    case 0x22u:
      v168 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v168 )
      {
        v61 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 1i64);
        v62 = CreateInternal(v61);
        v63 = (ANTLR3_BASE_TREE_struct *)ast->getChild(ast, 0i64);
        v64 = CreateInternal(v63);
        UEL::BinaryExpression::BinaryExpression(v168, Plus, v64, v62);
        v66 = v65;
      }
      else
      {
        v66 = 0i64;
      }
      result = v66;
      break;
    case 0x23u:
      v29 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
      if ( v29 )
      {
        v160.mBaseType.mValue = 4;
        v160.mDetailedType = UFG::gNullQSymbol;
        v30 = ast->getText(ast);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v29,
          v30->chars,
          0i64,
          (UEL::Value::Type)&v160);
        v32 = v31;
      }
      else
      {
        v32 = 0i64;
      }
LABEL_126:
      result = v32;
      break;
    case 0x24u:
      v180 = (UEL::BinaryExpression *)ast->getChild(ast, 0i64);
      v146 = (__int64 (__fastcall **)(void *, _QWORD))ast->getChild(ast, 1i64);
      v147 = (ANTLR3_BASE_TREE_struct *)v146[14](v146, 0i64);
      v148 = *(const char **)(((__int64 (__fastcall *)(__int64 (__fastcall **)(void *, _QWORD)))v146[23])(v146) + 8);
      v149 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
      if ( v149 )
      {
        if ( v147 )
          v147 = (ANTLR3_BASE_TREE_struct *)CreateInternal(v147);
        v150 = CreateInternal((ANTLR3_BASE_TREE_struct *)v180);
        UEL::ParameterExpression::ParameterExpression(
          (UEL::ParameterExpression *)v149,
          v148,
          v150,
          (UEL::Expression *)v147);
        v152 = v151;
      }
      else
      {
        v152 = 0i64;
      }
      result = v152;
      break;
    case 0x25u:
      v165 = (UEL::BinaryExpression *)ast->getChild(ast, 0i64);
      v33 = (__int64 (__fastcall **)(void *))ast->getChild(ast, 1i64);
      v34 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
      if ( v34 )
      {
        v163 = &v161;
        v161.mBaseType.mValue = 6;
        v161.mDetailedType = UFG::gNullQSymbol;
        v35 = v33[23](v33);
        v36 = (*(__int64 (__fastcall **)(UEL::BinaryExpression *))&v165[3].mType.mValue)(v165);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v34,
          *(char **)(v36 + 8),
          *(const char **)(v35 + 8),
          (UEL::Value::Type)&v161);
        v38 = v37;
      }
      else
      {
        v38 = 0i64;
      }
      result = v38;
      break;
    case 0x27u:
      v17 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
      if ( v17 )
      {
        v157.mBaseType.mValue = 3;
        v157.mDetailedType = UFG::gNullQSymbol;
        v18 = ast->getText(ast);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v17,
          v18->chars,
          0i64,
          (UEL::Value::Type)&v157);
        v20 = v19;
      }
      else
      {
        v20 = 0i64;
      }
      result = v20;
      break;
    case 0x28u:
      if ( ast->getText(ast)->chars && *ast->getText(ast)->chars == 39 )
      {
        v9 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
        if ( v9 )
        {
          type.mBaseType.mValue = 2;
          type.mDetailedType = UFG::gNullQSymbol;
          v10 = ast->getText(ast);
          UEL::ConstantExpression::ConstantExpression(
            (UEL::ConstantExpression *)v9,
            v10->chars,
            0i64,
            (UEL::Value::Type)&type);
          v12 = v11;
        }
        else
        {
          v12 = 0i64;
        }
        result = v12;
      }
      else
      {
        v13 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
        if ( v13 )
        {
          v184.mBaseType.mValue = 3;
          v184.mDetailedType = UFG::gNullQSymbol;
          v14 = ast->getText(ast);
          UEL::ConstantExpression::ConstantExpression(
            (UEL::ConstantExpression *)v13,
            v14->chars,
            0i64,
            (UEL::Value::Type)&v184);
          v16 = v15;
        }
        else
        {
          v16 = 0i64;
        }
        result = v16;
      }
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 338
// RVA: 0x1475F90
__int64 dynamic_initializer_for__gAntlrMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gAntlrMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAntlrMemoryPool__);
}

// File Line: 340
// RVA: 0x24E840
ANTLR3_INPUT_STREAM_struct *__fastcall UEL::Expression::Compile(char *pcUELCode)
{
  __int64 v1; // rax
  ANTLR3_INPUT_STREAM_struct *result; // rax
  ANTLR3_INPUT_STREAM_struct *v3; // rbp
  ANTLR3_INPUT_STREAM_struct *v4; // rbx
  ANTLR3_INPUT_STREAM_struct *v5; // rsi
  ANTLR3_INPUT_STREAM_struct *v6; // rdi
  UEL::Expression *Internal; // r14
  ANTLR3_BASE_TREE_struct *v8; // r15
  char v9[24]; // [rsp+38h] [rbp-30h] BYREF

  v1 = -1i64;
  do
    ++v1;
  while ( pcUELCode[v1] );
  result = antlr3StringStreamNew(pcUELCode, 4u, v1, "UEL_Expression");
  v3 = result;
  if ( result )
  {
    result = (ANTLR3_INPUT_STREAM_struct *)UELLexerNew(result);
    v4 = result;
    if ( result )
    {
      result = (ANTLR3_INPUT_STREAM_struct *)antlr3CommonTokenStreamSourceNew(
                                               0x401u,
                                               *(ANTLR3_TOKEN_SOURCE_struct **)(*(_QWORD *)(result->istream->lastMarker
                                                                                          + 16)
                                                                              + 104i64));
      v5 = result;
      if ( result )
      {
        result = (ANTLR3_INPUT_STREAM_struct *)UELParserNew((ANTLR3_COMMON_TOKEN_STREAM_struct *)result);
        v6 = result;
        if ( result )
        {
          Internal = 0i64;
          v8 = *(ANTLR3_BASE_TREE_struct **)(((__int64 (__fastcall *)(char *, ANTLR3_INPUT_STREAM_struct *))result->strFactory)(
                                               v9,
                                               result)
                                           + 16);
          if ( !((unsigned int (__fastcall *)(ANTLR3_STRING_struct *))v6->istream->streamName->appendS)(v6->istream->streamName) )
            Internal = CreateInternal(v8);
          ((void (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))v6->setLine)(v6);
          ((void (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))v5->setUcaseLA)(v5);
          v4[1].getLine(v4);
          v3->free(v3);
          return (ANTLR3_INPUT_STREAM_struct *)Internal;
        }
      }
    }
  }
  return result;
}

