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
  return atexit(dynamic_atexit_destructor_for__UEL::Value::msStringTable__);
}

// File Line: 75
// RVA: 0x2537B0
UFG::qString *__fastcall UEL::Value::ToString(UEL::Value *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx
  UEL::Value *v3; // rdi
  __int64 v4; // rcx
  char *v5; // r8
  const char *v6; // rdx
  char *v7; // rax

  v2 = result;
  v3 = this;
  v4 = this->type.mBaseType.mValue;
  switch ( (_DWORD)v4 )
  {
    case 0:
      UFG::qString::qString(result, "None.");
      return v2;
    case 1:
      UFG::qString::FormatEx(result, "Integer %d", v3->integer);
      return v2;
    case 2:
      v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v3);
      v6 = "Symbol %s";
      goto LABEL_18;
    case 3:
      v5 = (char *)v3->integer;
      v6 = "String %s";
      goto LABEL_18;
    case 4:
      UFG::qString::FormatEx(result, "Real %f", v3->real);
      return v2;
    case 5:
      v5 = "FALSE";
      if ( v3->boolean )
        v5 = "TRUE";
      v6 = "Boolean %s";
      goto LABEL_18;
    case 6:
      v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->type.mDetailedType);
      UFG::qString::FormatEx(v2, "Enum %s, %d", v7, v3->qSymbol_mUID);
      return v2;
    case 7:
      UFG::qString::FormatEx(result, "Vector %f,%f,%f", v3->real, v3->qVector_y, v3->qVector_z);
      return v2;
    case 8:
      v5 = (char *)v3->integer;
      v6 = "Struct %p";
      goto LABEL_18;
    case 9:
      v5 = (char *)v3->integer;
      v6 = "Lookup %x";
      goto LABEL_18;
    case 0xA:
      v5 = (char *)v3->integer;
      v6 = "Getter %x";
      goto LABEL_18;
    default:
      if ( (unsigned int)v4 > 0xC )
      {
        v5 = (char *)UEL::BinaryExpressionTypeStrings[v4];
        v6 = "Array of %s";
LABEL_18:
        UFG::qString::FormatEx(v2, v6, v5);
      }
      else
      {
        UFG::qString::qString(result, "ERROR!");
      }
      return v2;
  }
}

// File Line: 114
// RVA: 0x251DF0
signed __int64 __fastcall UEL::Value::GetSizeOfValueType(UEL::Value::Type v)
{
  unsigned int v1; // edx
  signed __int64 result; // rax

  v1 = -1;
  switch ( **(unsigned __int16 **)&v )
  {
    case 1u:
    case 3u:
    case 8u:
      v1 = 8;
      goto LABEL_6;
    case 2u:
    case 4u:
    case 6u:
      result = 4i64;
      break;
    case 5u:
      result = 1i64;
      break;
    case 7u:
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
  ANTLR3_BASE_TREE_struct *v1; // rsi
  UFG::allocator::free_link *v2; // rbx
  ANTLR3_BASE_TREE_struct *v3; // rax
  UEL::Expression *v4; // rax
  UEL::Expression *v5; // rax
  UEL::Expression *v6; // rdi
  UEL::Expression *result; // rax
  ANTLR3_BASE_TREE_struct *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  __int64 v10; // rax
  UEL::Expression *v11; // rax
  UEL::Expression *v12; // rdi
  UFG::allocator::free_link *v13; // rbx
  __int64 v14; // rax
  UEL::Expression *v15; // rax
  UEL::Expression *v16; // rdi
  UFG::allocator::free_link *v17; // rbx
  __int64 v18; // rax
  UEL::Expression *v19; // rax
  UEL::Expression *v20; // rdi
  UFG::allocator::free_link *v21; // rbx
  __int64 v22; // rax
  UEL::Expression *v23; // rax
  UEL::Expression *v24; // rdi
  UFG::allocator::free_link *v25; // rbx
  __int64 v26; // rax
  UEL::Expression *v27; // rax
  UEL::Expression *v28; // rdi
  UFG::allocator::free_link *v29; // rbx
  __int64 v30; // rax
  UEL::Expression *v31; // rax
  UEL::Expression *v32; // rdi
  __int64 v33; // rbx
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
  UEL::Expression *v110; // rbx
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
  int v121; // eax
  unsigned __int64 v122; // rax
  unsigned __int64 v123; // kr00_8
  UEL::Expression *v124; // rdi
  signed __int64 v125; // rbx
  unsigned int v126; // edi
  ANTLR3_BASE_TREE_struct *v127; // rax
  UFG::allocator::free_link *v128; // rbx
  __int64 v129; // rax
  UEL::Expression *v130; // rax
  int v131; // eax
  signed __int64 v132; // rbx
  unsigned __int64 v133; // rax
  unsigned __int64 v134; // kr10_8
  unsigned int v135; // edi
  signed __int64 v136; // rcx
  UEL::Expression **v137; // rbx
  ANTLR3_BASE_TREE_struct *v138; // rax
  UEL::Expression **v139; // rbx
  __int64 v140; // rax
  UEL::Expression *v141; // rax
  UEL::Expression *v142; // rdi
  __int64 v143; // rbx
  const char *v144; // rbx
  UFG::allocator::free_link *v145; // rax
  UEL::Expression *v146; // rax
  UEL::Expression *v147; // rdi
  __int64 v148; // rbx
  ANTLR3_BASE_TREE_struct *v149; // rdi
  const char *v150; // rsi
  UFG::allocator::free_link *v151; // rbx
  UEL::Expression *v152; // rax
  UEL::Expression *v153; // rax
  UEL::Expression *v154; // rdi
  ANTLR3_BASE_TREE_struct *v155; // rbx
  UFG::allocator::free_link *v156; // rsi
  UEL::Expression *v157; // rdi
  UEL::Expression *v158; // rax
  UEL::Value::Type v159; // [rsp+30h] [rbp-48h]
  UEL::Value::Type v160; // [rsp+38h] [rbp-40h]
  UEL::Value::Type v161; // [rsp+40h] [rbp-38h]
  UEL::Value::Type v162; // [rsp+48h] [rbp-30h]
  UEL::Value::Type v163; // [rsp+50h] [rbp-28h]
  UEL::Expression **expressions; // [rsp+58h] [rbp-20h]
  UEL::Value::Type *v165; // [rsp+60h] [rbp-18h]
  __int64 v166; // [rsp+68h] [rbp-10h]
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
  UEL::BinaryExpression *v178; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v179; // [rsp+A0h] [rbp+28h]
  int v180; // [rsp+A0h] [rbp+28h]
  int v181; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v182; // [rsp+A0h] [rbp+28h]
  UEL::BinaryExpression *v183; // [rsp+A0h] [rbp+28h]
  UEL::Expression **args; // [rsp+A8h] [rbp+30h]
  UEL::Value::Type type; // [rsp+B0h] [rbp+38h]
  UEL::Value::Type v186; // [rsp+B8h] [rbp+40h]

  v166 = -2i64;
  v1 = ast;
  switch ( ((unsigned int (*)(void))ast->getType)() )
  {
    case 6u:
      v178 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v178 )
      {
        v109 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v110 = CreateInternal(v109);
        v111 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v112 = CreateInternal(v111);
        UEL::BinaryExpression::BinaryExpression(v178, 0, v112, v110);
        v114 = v113;
      }
      else
      {
        v114 = 0i64;
      }
      result = v114;
      break;
    case 7u:
      v143 = (__int64)v1->getChild(v1, 0);
      v1->getChild(v1, 1u);
      v144 = *(const char **)((*(__int64 (__fastcall **)(__int64))(v143 + 184))(v143) + 8);
      v145 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
      if ( v145 )
      {
        UEL::ArgumentUsageExpression::ArgumentUsageExpression((UEL::ArgumentUsageExpression *)v145, v144);
        v147 = v146;
      }
      else
      {
        v147 = 0i64;
      }
      result = v147;
      break;
    case 8u:
      v25 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
      if ( v25 )
      {
        v161.mBaseType.mValue = 5;
        v161.mDetailedType = UFG::gNullQSymbol;
        v26 = (__int64)v1->getText(v1);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v25,
          *(const char **)(v26 + 8),
          0i64,
          (UEL::Value::Type)&v161);
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
      v8 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
      result = CreateInternal(v8);
      break;
    case 0xCu:
      v169 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v169 )
      {
        v55 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v56 = CreateInternal(v55);
        v57 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v58 = CreateInternal(v57);
        UEL::BinaryExpression::BinaryExpression(v169, Div, v58, v56);
        v60 = v59;
      }
      else
      {
        v60 = 0i64;
      }
      result = v60;
      break;
    case 0xEu:
      v176 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v176 )
      {
        v97 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v98 = CreateInternal(v97);
        v99 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v100 = CreateInternal(v99);
        UEL::BinaryExpression::BinaryExpression(v176, Equal, v100, v98);
        v102 = v101;
      }
      else
      {
        v102 = 0i64;
      }
      result = v102;
      break;
    case 0x10u:
      v131 = v1->getChildCount(v1);
      v132 = v131--;
      v181 = v131;
      v134 = v131;
      v133 = 8i64 * v131;
      if ( !is_mul_ok(v134, 8ui64) )
        v133 = -1i64;
      args = (UEL::Expression **)UFG::qMalloc(v133, UFG::gGlobalNewName, 0i64);
      v165 = (UEL::Value::Type *)v1->getChild(v1, 0);
      v135 = 1;
      v136 = v132;
      if ( v132 > 1 )
      {
        v137 = args;
        expressions = (UEL::Expression **)(v136 - 1);
        do
        {
          v138 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, v135);
          *v137 = CreateInternal(v138);
          ++v135;
          ++v137;
          expressions = (UEL::Expression **)((char *)expressions - 1);
        }
        while ( expressions );
      }
      v139 = (UEL::Expression **)UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
      expressions = v139;
      if ( v139 )
      {
        v140 = (*(__int64 (__fastcall **)(UEL::Value::Type *))&v165[23])(v165);
        UEL::FragmentInvocationExpression::FragmentInvocationExpression(
          (UEL::FragmentInvocationExpression *)v139,
          *(const char **)(v140 + 8),
          v181,
          args);
        v142 = v141;
      }
      else
      {
        v142 = 0i64;
      }
      operator delete[](args);
      result = v142;
      break;
    case 0x11u:
      v121 = v1->getChildCount(v1);
      v180 = v121;
      v123 = v121;
      v122 = 8i64 * v121;
      if ( !is_mul_ok(v123, 8ui64) )
        v122 = -1i64;
      expressions = (UEL::Expression **)UFG::qMalloc(v122, UFG::gGlobalNewName, 0i64);
      v124 = 0i64;
      v125 = 0i64;
      if ( v180 > 0 )
      {
        v126 = 0;
        do
        {
          v127 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, v126);
          expressions[v125] = CreateInternal(v127);
          ++v126;
          ++v125;
        }
        while ( v125 < v180 );
        v124 = 0i64;
      }
      v128 = UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
      if ( v128 )
      {
        v129 = (__int64)v1->getText(v1);
        UEL::InvocationExpression::InvocationExpression(
          (UEL::InvocationExpression *)v128,
          *(const char **)(v129 + 8),
          expressions,
          v180);
        v124 = v130;
      }
      operator delete[](expressions);
      result = v124;
      break;
    case 0x12u:
      v175 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v175 )
      {
        v91 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v92 = CreateInternal(v91);
        v93 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v94 = CreateInternal(v93);
        UEL::BinaryExpression::BinaryExpression(v175, GreaterOrEqual, v94, v92);
        v96 = v95;
      }
      else
      {
        v96 = 0i64;
      }
      result = v96;
      break;
    case 0x13u:
      v174 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v174 )
      {
        v85 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v86 = CreateInternal(v85);
        v87 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v88 = CreateInternal(v87);
        UEL::BinaryExpression::BinaryExpression(v174, Greater, v88, v86);
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
        v160.mBaseType.mValue = 1;
        v160.mDetailedType = UFG::gNullQSymbol;
        v22 = (__int64)v1->getText(v1);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v21,
          *(const char **)(v22 + 8),
          0i64,
          (UEL::Value::Type)&v160);
        v24 = v23;
      }
      else
      {
        v24 = 0i64;
      }
      result = v24;
      break;
    case 0x17u:
      v173 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v173 )
      {
        v79 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v80 = CreateInternal(v79);
        v81 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v82 = CreateInternal(v81);
        UEL::BinaryExpression::BinaryExpression(v173, LesserOrEqual, v82, v80);
        v84 = v83;
      }
      else
      {
        v84 = 0i64;
      }
      result = v84;
      break;
    case 0x18u:
      v172 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v172 )
      {
        v73 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v74 = CreateInternal(v73);
        v75 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v76 = CreateInternal(v75);
        UEL::BinaryExpression::BinaryExpression(v172, Lesser, v76, v74);
        v78 = v77;
      }
      else
      {
        v78 = 0i64;
      }
      result = v78;
      break;
    case 0x19u:
      v171 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v171 )
      {
        v67 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v68 = CreateInternal(v67);
        v69 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v70 = CreateInternal(v69);
        UEL::BinaryExpression::BinaryExpression(v171, Minus, v70, v68);
        v72 = v71;
      }
      else
      {
        v72 = 0i64;
      }
      result = v72;
      break;
    case 0x1Bu:
      v168 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v168 )
      {
        v49 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v50 = CreateInternal(v49);
        v51 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v52 = CreateInternal(v51);
        UEL::BinaryExpression::BinaryExpression(v168, Times, v52, v50);
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
        v45 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
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
        v40 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v41 = CreateInternal(v40);
        UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v39, 0, v41);
        v43 = v42;
      }
      else
      {
        v43 = 0i64;
      }
      result = v43;
      break;
    case 0x1Eu:
      v177 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v177 )
      {
        v103 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v104 = CreateInternal(v103);
        v105 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v106 = CreateInternal(v105);
        UEL::BinaryExpression::BinaryExpression(v177, NotEqual, v106, v104);
        v108 = v107;
      }
      else
      {
        v108 = 0i64;
      }
      result = v108;
      break;
    case 0x1Fu:
      v179 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v179 )
      {
        v115 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v116 = CreateInternal(v115);
        v117 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v118 = CreateInternal(v117);
        UEL::BinaryExpression::BinaryExpression(v179, Or, v118, v116);
        v120 = v119;
      }
      else
      {
        v120 = 0i64;
      }
      result = v120;
      break;
    case 0x20u:
      v155 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
      v183 = *(UEL::BinaryExpression **)((__int64)v1->getText(v1) + 8);
      v156 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
      if ( v156 )
      {
        if ( v155 )
          v157 = CreateInternal(v155);
        else
          v157 = 0i64;
        UEL::ParameterExpression::ParameterExpression((UEL::ParameterExpression *)v156, (const char *)v183, 0i64, v157);
        v32 = v158;
      }
      else
      {
        v32 = 0i64;
      }
      goto LABEL_127;
    case 0x21u:
      v2 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v2 )
      {
        v3 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
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
      v170 = (UEL::BinaryExpression *)UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
      if ( v170 )
      {
        v61 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 1u);
        v62 = CreateInternal(v61);
        v63 = (ANTLR3_BASE_TREE_struct *)v1->getChild(v1, 0);
        v64 = CreateInternal(v63);
        UEL::BinaryExpression::BinaryExpression(v170, Plus, v64, v62);
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
        v162.mBaseType.mValue = 4;
        v162.mDetailedType = UFG::gNullQSymbol;
        v30 = (__int64)v1->getText(v1);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v29,
          *(const char **)(v30 + 8),
          0i64,
          (UEL::Value::Type)&v162);
        v32 = v31;
      }
      else
      {
        v32 = 0i64;
      }
LABEL_127:
      result = v32;
      break;
    case 0x24u:
      v182 = (UEL::BinaryExpression *)v1->getChild(v1, 0);
      v148 = (__int64)v1->getChild(v1, 1u);
      v149 = (ANTLR3_BASE_TREE_struct *)(*(__int64 (__fastcall **)(__int64, _QWORD))(v148 + 112))(v148, 0i64);
      v150 = *(const char **)((*(__int64 (__fastcall **)(__int64))(v148 + 184))(v148) + 8);
      v151 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
      if ( v151 )
      {
        if ( v149 )
          v149 = (ANTLR3_BASE_TREE_struct *)CreateInternal(v149);
        v152 = CreateInternal((ANTLR3_BASE_TREE_struct *)v182);
        UEL::ParameterExpression::ParameterExpression(
          (UEL::ParameterExpression *)v151,
          v150,
          v152,
          (UEL::Expression *)v149);
        v154 = v153;
      }
      else
      {
        v154 = 0i64;
      }
      result = v154;
      break;
    case 0x25u:
      v167 = (UEL::BinaryExpression *)v1->getChild(v1, 0);
      v33 = (__int64)v1->getChild(v1, 1u);
      v34 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
      if ( v34 )
      {
        v165 = &v163;
        v163.mBaseType.mValue = 6;
        v163.mDetailedType = UFG::gNullQSymbol;
        v35 = (*(__int64 (__fastcall **)(__int64))(v33 + 184))(v33);
        v36 = (*(__int64 (__fastcall **)(UEL::BinaryExpression *))&v167[3].mType.mValue)(v167);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v34,
          *(const char **)(v36 + 8),
          *(const char **)(v35 + 8),
          (UEL::Value::Type)&v163);
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
        v159.mBaseType.mValue = 3;
        v159.mDetailedType = UFG::gNullQSymbol;
        v18 = (__int64)v1->getText(v1);
        UEL::ConstantExpression::ConstantExpression(
          (UEL::ConstantExpression *)v17,
          *(const char **)(v18 + 8),
          0i64,
          (UEL::Value::Type)&v159);
        v20 = v19;
      }
      else
      {
        v20 = 0i64;
      }
      result = v20;
      break;
    case 0x28u:
      if ( *(_QWORD *)((__int64)v1->getText(v1) + 8) && **(_BYTE **)((__int64)v1->getText(v1) + 8) == 39 )
      {
        v9 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
        if ( v9 )
        {
          type.mBaseType.mValue = 2;
          type.mDetailedType = UFG::gNullQSymbol;
          v10 = (__int64)v1->getText(v1);
          UEL::ConstantExpression::ConstantExpression(
            (UEL::ConstantExpression *)v9,
            *(const char **)(v10 + 8),
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
          v186.mBaseType.mValue = 3;
          v186.mDetailedType = UFG::gNullQSymbol;
          v14 = (__int64)v1->getText(v1);
          UEL::ConstantExpression::ConstantExpression(
            (UEL::ConstantExpression *)v13,
            *(const char **)(v14 + 8),
            0i64,
            (UEL::Value::Type)&v186);
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
  return atexit(dynamic_atexit_destructor_for__gAntlrMemoryPool__);
}

// File Line: 340
// RVA: 0x24E840
ANTLR3_INPUT_STREAM_struct *__fastcall UEL::Expression::Compile(const char *pcUELCode)
{
  signed __int64 v1; // rax
  ANTLR3_INPUT_STREAM_struct *result; // rax
  ANTLR3_INPUT_STREAM_struct *v3; // rbp
  ANTLR3_INPUT_STREAM_struct *v4; // rbx
  ANTLR3_INPUT_STREAM_struct *v5; // rsi
  ANTLR3_INPUT_STREAM_struct *v6; // rdi
  __int64 *v7; // rax
  UEL::Expression *v8; // r14
  ANTLR3_BASE_TREE_struct *v9; // r15
  __int64 v10; // ST20_8
  __int64 v11; // ST28_8
  char v12; // [rsp+38h] [rbp-30h]

  v1 = -1i64;
  do
    ++v1;
  while ( pcUELCode[v1] );
  result = antlr3StringStreamNew((char *)pcUELCode, 4u, v1, "UEL_Expression");
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
          v7 = (__int64 *)((__int64 (__fastcall *)(char *, ANTLR3_INPUT_STREAM_struct *))result->strFactory)(
                            &v12,
                            result);
          v8 = 0i64;
          v9 = (ANTLR3_BASE_TREE_struct *)v7[2];
          v10 = *v7;
          v11 = v7[1];
          if ( !((unsigned int (__fastcall *)(ANTLR3_STRING_struct *))v6->istream->streamName->appendS)(v6->istream->streamName) )
            v8 = CreateInternal(v9);
          ((void (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))v6->setLine)(v6);
          ((void (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))v5->setUcaseLA)(v5);
          v4[1].getLine(v4);
          v3->free(v3);
          result = (ANTLR3_INPUT_STREAM_struct *)v8;
        }
      }
    }
  }
  return result;
}

