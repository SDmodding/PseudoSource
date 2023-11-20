// File Line: 85
// RVA: 0x257810
void __fastcall antlr3BaseTreeAdaptorInit(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
{
  if ( debugger )
  {
    adaptor->nilNode = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *))dbgNil;
    adaptor->addChild = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, void *))dbgAddChild;
    adaptor->becomeRoot = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, void *))dbgBecomeRoot;
    adaptor->addChildToken = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, ANTLR3_COMMON_TOKEN_struct *))dbgAddChildToken;
    adaptor->becomeRootToken = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, void *))dbgBecomeRootToken;
    adaptor->createTypeToken = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, unsigned int, ANTLR3_COMMON_TOKEN_struct *))dbgCreateTypeToken;
    adaptor->createTypeTokenText = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, unsigned int, ANTLR3_COMMON_TOKEN_struct *, char *))dbgCreateTypeTokenText;
    adaptor->createTypeText = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, unsigned int, char *))dbgCreateTypeText;
    adaptor->dupTree = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))dbgDupTree;
    debugger->adaptor = adaptor;
  }
  else
  {
    adaptor->nilNode = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *))nilNode;
    adaptor->addChild = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, void *))addChild_0;
    adaptor->becomeRoot = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, void *))becomeRoot;
    adaptor->addChildToken = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, ANTLR3_COMMON_TOKEN_struct *))addChildToken;
    adaptor->becomeRootToken = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, void *))becomeRootToken;
    adaptor->createTypeToken = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, unsigned int, ANTLR3_COMMON_TOKEN_struct *))createTypeToken;
    adaptor->createTypeTokenText = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, unsigned int, ANTLR3_COMMON_TOKEN_struct *, char *))createTypeTokenText;
    adaptor->createTypeText = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, unsigned int, char *))createTypeText;
    adaptor->dupTree = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))dupTree_0;
  }
  adaptor->dupTreeTT = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, void *))dupTreeTT;
  adaptor->rulePostProcessing = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))rulePostProcessing;
  adaptor->getType = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))TargetVisibleInAIDataCondition::CreateClone;
  adaptor->setType = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, unsigned int))_;
  adaptor->getText = (ANTLR3_STRING_struct *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))TargetVisibleInAIDataCondition::CreateClone;
  adaptor->setText8 = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, char *))_;
  adaptor->setText = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_STRING_struct *))_;
  adaptor->getChild = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, unsigned int))TargetVisibleInAIDataCondition::CreateClone;
  adaptor->getChildCount = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))TargetVisibleInAIDataCondition::CreateClone;
  adaptor->getUniqueID = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))hkpBreakableMaterial::convertShapeKeyToSubShapeId;
  adaptor->isNilNode = (char (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))isNilNode;
  adaptor->makeDot = makeDot;
}

// File Line: 165
// RVA: 0x257370
void __fastcall defineDotNodes(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, void *t, ANTLR3_STRING_struct *dotSpec)
{
  ANTLR3_STRING_struct *v3; // rbx
  void *v4; // rsi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rdi
  signed int v6; // eax
  unsigned int v7; // ebp
  __int64 v8; // rsi
  __int64 v9; // rax
  unsigned int v10; // edi
  __int64 v11; // rsi
  int v12; // eax
  unsigned int v13; // eax
  const char *v14; // rdx
  void *ta; // [rsp+20h] [rbp-68h]
  char string; // [rsp+30h] [rbp-58h]
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptora; // [rsp+90h] [rbp+8h]
  void *v18; // [rsp+98h] [rbp+10h]
  signed int v19; // [rsp+A8h] [rbp+20h]

  v18 = t;
  adaptora = adaptor;
  v3 = dotSpec;
  v4 = t;
  v5 = adaptor;
  v6 = ((__int64 (*)(void))adaptor->getChildCount)();
  v19 = v6;
  if ( v6 )
  {
    v7 = 0;
    if ( v6 > 0 )
    {
      while ( 1 )
      {
        v8 = (__int64)v5->getChild(v5, v4, v7);
        ta = (void *)v8;
        sprintf(&string, "\tn%p[label=\"", v8);
        v3->append8(v3, &string);
        v9 = (__int64)v5->getText(v5, (void *)v8);
        v10 = 0;
        v11 = v9;
        if ( *(_DWORD *)(v9 + 16) > 0 )
          break;
LABEL_13:
        v3->append8(v3, "\"]\n");
        v5 = adaptora;
        defineDotNodes(adaptora, ta, v3);
        v4 = v18;
        if ( (signed int)++v7 >= v19 )
          return;
      }
      while ( 1 )
      {
        v12 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v11 + 152))(v11, v10);
        if ( v12 == 10 )
        {
          v14 = "\\n";
          goto LABEL_11;
        }
        if ( v12 == 13 )
          break;
        if ( v12 == 34 )
        {
          v14 = "\\\"";
LABEL_11:
          v3->append8(v3, v14);
          goto LABEL_12;
        }
        v13 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v11 + 152))(v11, v10);
        v3->addc(v3, v13);
LABEL_12:
        if ( (signed int)++v10 >= *(_DWORD *)(v11 + 16) )
          goto LABEL_13;
      }
      v14 = "\\r";
      goto LABEL_11;
    }
  }
}

// File Line: 245
// RVA: 0x2571A0
void __fastcall defineDotEdges(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, void *t, ANTLR3_STRING_struct *dotSpec)
{
  ANTLR3_STRING_struct *v3; // rbx
  void *v4; // rdi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rbp
  int v6; // ecx
  int v7; // eax
  __int64 v8; // rax
  unsigned int v9; // edi
  __int64 v10; // rsi
  int v11; // eax
  unsigned int v12; // eax
  const char *v13; // rdx
  unsigned int v14; // edi
  __int64 v15; // rsi
  int v16; // eax
  unsigned int v17; // eax
  const char *v18; // rdx
  __int64 v19; // [rsp+20h] [rbp-A8h]
  void *ta; // [rsp+28h] [rbp-A0h]
  char string; // [rsp+30h] [rbp-98h]
  void *v22; // [rsp+D8h] [rbp+10h]
  int v23; // [rsp+E8h] [rbp+20h]

  if ( t )
  {
    v22 = t;
    v3 = dotSpec;
    v4 = t;
    v5 = adaptor;
    v6 = ((__int64 (*)(void))adaptor->getChildCount)();
    LODWORD(v19) = v6;
    if ( v6 )
    {
      v7 = 0;
      v23 = 0;
      if ( v6 > 0 )
      {
        while ( 1 )
        {
          ta = v5->getChild(v5, v4, v7);
          sprintf(&string, "\t\tn%p -> n%p\t\t// ", v4, ta, v19);
          v3->append8(v3, &string);
          v8 = (__int64)v5->getText(v5, v4);
          v9 = 0;
          v10 = v8;
          if ( *(_DWORD *)(v8 + 16) > 0 )
          {
            while ( 1 )
            {
              v11 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v10 + 152))(v10, v9);
              if ( v11 == 10 )
              {
                v13 = "\\n";
                goto LABEL_12;
              }
              if ( v11 == 13 )
                break;
              if ( v11 == 34 )
              {
                v13 = "\\\"";
LABEL_12:
                v3->append8(v3, v13);
                goto LABEL_13;
              }
              v12 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v10 + 152))(v10, v9);
              v3->addc(v3, v12);
LABEL_13:
              if ( (signed int)++v9 >= *(_DWORD *)(v10 + 16) )
                goto LABEL_14;
            }
            v13 = "\\r";
            goto LABEL_12;
          }
LABEL_14:
          v3->append8(v3, " -> ");
          v14 = 0;
          v15 = (__int64)v5->getText(v5, ta);
          if ( *(_DWORD *)(v15 + 16) > 0 )
            break;
LABEL_24:
          v3->append8(v3, "\n");
          defineDotEdges(v5, ta, v3);
          v4 = v22;
          v7 = v23 + 1;
          v23 = v7;
          if ( v7 >= (signed int)v19 )
            return;
        }
        while ( 1 )
        {
          v16 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v15 + 152))(v15, v14);
          if ( v16 == 10 )
          {
            v18 = "\\n";
            goto LABEL_22;
          }
          if ( v16 == 13 )
            break;
          if ( v16 == 34 )
          {
            v18 = "\\\"";
LABEL_22:
            v3->append8(v3, v18);
            goto LABEL_23;
          }
          v17 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v15 + 152))(v15, v14);
          v3->addc(v3, v17);
LABEL_23:
          if ( (signed int)++v14 >= *(_DWORD *)(v15 + 16) )
            goto LABEL_24;
        }
        v18 = "\\r";
        goto LABEL_22;
      }
    }
  }
}

// File Line: 364
// RVA: 0x2575A0
ANTLR3_STRING_struct *__fastcall makeDot(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, void *theTree)
{
  void *v2; // rbp
  ANTLR3_BASE_TREE_ADAPTOR_struct *v3; // r14
  ANTLR3_STRING_struct *v4; // rax
  ANTLR3_STRING_struct *v5; // rbx
  unsigned int v6; // edi
  __int64 v7; // rsi
  int v8; // eax
  unsigned int v9; // eax
  const char *v10; // rdx
  char string; // [rsp+20h] [rbp-48h]

  v2 = theTree;
  v3 = adaptor;
  v4 = adaptor->strFactory->newStr8(
         adaptor->strFactory,
         "digraph {\n"
         "\n"
         "\tordering=out;\n"
         "\tranksep=.4;\n"
         "\tbgcolor=\"lightgrey\";  node [shape=box, fixedsize=false, fontsize=12, fontname=\"Helvetica-bold\", fontcolor"
         "=\"blue\"\n"
         "\twidth=.25, height=.25, color=\"black\", fillcolor=\"white\", style=\"filled, solid, bold\"];\n"
         "\n"
         "\tedge [arrowsize=.5, color=\"black\", style=\"bold\"]\n"
         "\n");
  v5 = v4;
  if ( v2 )
  {
    sprintf(&string, "\tn%p[label=\"", v2);
    v5->append8(v5, &string);
    v6 = 0;
    v7 = (__int64)v3->getText(v3, v2);
    if ( *(_DWORD *)(v7 + 16) <= 0 )
    {
LABEL_13:
      v5->append8(v5, "\"]\n");
      defineDotNodes(v3, v2, v5);
      v5->append8(v5, "\n");
      defineDotEdges(v3, v2, v5);
      v5->append8(v5, "\n}");
      return v5;
    }
    while ( 1 )
    {
      v8 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v7 + 152))(v7, v6);
      if ( v8 == 10 )
      {
        v10 = "\\n";
        goto LABEL_11;
      }
      if ( v8 == 13 )
        break;
      if ( v8 == 34 )
      {
        v10 = "\\\"";
LABEL_11:
        v5->append8(v5, v10);
        goto LABEL_12;
      }
      v9 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v7 + 152))(v7, v6);
      v5->addc(v5, v9);
LABEL_12:
      if ( (signed int)++v6 >= *(_DWORD *)(v7 + 16) )
        goto LABEL_13;
    }
    v10 = "\\r";
    goto LABEL_11;
  }
  v4->append8(v4, "n0[label=\"EMPTY TREE\"]\n");
  return v5;
}

// File Line: 446
// RVA: 0x2576E0
ANTLR3_BASE_TREE_struct *__fastcall nilNode(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor)
{
  return (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, 0i64);
}

// File Line: 452
// RVA: 0x257160
ANTLR3_BASE_TREE_struct *__fastcall dbgNil(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v1; // rdi
  ANTLR3_BASE_TREE_struct *v2; // rbx

  v1 = adaptor;
  v2 = (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, 0i64);
  v1->debugger->createNode(v1->debugger, v2);
  return v2;
}

// File Line: 466
// RVA: 0x2574B0
ANTLR3_BASE_TREE_struct *__fastcall dupTree_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return (ANTLR3_BASE_TREE_struct *)adaptor->dupTreeTT(adaptor, t, 0i64);
}

// File Line: 472
// RVA: 0x2574C0
ANTLR3_BASE_TREE_struct *__fastcall dupTreeTT(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, ANTLR3_BASE_TREE_struct *parent)
{
  ANTLR3_BASE_TREE_struct *v3; // rsi
  ANTLR3_BASE_TREE_struct *v4; // rdi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rbx
  void *v7; // rbp
  unsigned int v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // er14
  __int64 v11; // rax
  __int64 v12; // rax

  v3 = parent;
  v4 = t;
  v5 = adaptor;
  if ( !t )
    return 0i64;
  v7 = t->dupNode(t);
  v8 = v4->getChildIndex(v4);
  v5->setChildIndex(v5, v7, v8);
  v5->setParent(v5, v7, v3);
  v9 = 0;
  v10 = v5->getChildCount(v5, v4);
  if ( v10 )
  {
    do
    {
      v11 = (__int64)v5->getChild(v5, v4, v9);
      v12 = (__int64)v5->dupTreeTT(v5, (void *)v11, v4);
      v5->addChild(v5, v7, (void *)v12);
      ++v9;
    }
    while ( v9 < v10 );
  }
  return (ANTLR3_BASE_TREE_struct *)v7;
}

// File Line: 505
// RVA: 0x257780
void __fastcall simulateTreeConstruction(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v2; // rbx
  ANTLR3_BASE_TREE_struct *v3; // rbp
  unsigned int v4; // esi
  ANTLR3_BASE_TREE_struct *v5; // rdi
  unsigned int v6; // [rsp+30h] [rbp+8h]

  v2 = adaptor;
  v3 = tree;
  ((void (__fastcall *)(ANTLR3_DEBUG_EVENT_LISTENER_struct *))adaptor->debugger->createNode)(adaptor->debugger);
  v4 = 0;
  v6 = v2->getChildCount(v2, v3);
  if ( v6 )
  {
    do
    {
      v5 = (ANTLR3_BASE_TREE_struct *)v2->getChild(v2, v3, v4);
      simulateTreeConstruction(v2, v5);
      v2->debugger->addChild(v2->debugger, v3, v5);
      ++v4;
    }
    while ( v4 < v6 );
  }
}

// File Line: 525
// RVA: 0x257130
ANTLR3_BASE_TREE_struct *__fastcall dbgDupTree(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v2; // rdi
  ANTLR3_BASE_TREE_struct *v3; // rbx

  v2 = adaptor;
  v3 = (ANTLR3_BASE_TREE_struct *)adaptor->dupTreeTT(adaptor, tree, 0i64);
  simulateTreeConstruction(v2, v3);
  return v3;
}

// File Line: 553
// RVA: 0x256C70
void __fastcall addChild_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, ANTLR3_BASE_TREE_struct *child)
{
  if ( t )
  {
    if ( child )
      t->addChild(t, child);
  }
}

// File Line: 561
// RVA: 0x256E90
void __fastcall dbgAddChild(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, ANTLR3_BASE_TREE_struct *child)
{
  ANTLR3_BASE_TREE_struct *v3; // rdi
  ANTLR3_BASE_TREE_struct *v4; // rbx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rsi

  if ( t )
  {
    v3 = child;
    v4 = t;
    v5 = adaptor;
    if ( child )
    {
      t->addChild(t, child);
      v5->debugger->addChild(v5->debugger, v4, v3);
    }
  }
}

// File Line: 572
// RVA: 0x256C90
void __fastcall addChildToken(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, ANTLR3_COMMON_TOKEN_struct *child)
{
  ANTLR3_BASE_TREE_struct *v3; // rdi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v4; // rbx
  void *v5; // rax

  if ( t )
  {
    v3 = t;
    v4 = adaptor;
    if ( child )
    {
      v5 = adaptor->create(adaptor, child);
      v4->addChild(v4, v3, v5);
    }
  }
}

// File Line: 580
// RVA: 0x256EE0
void __fastcall dbgAddChildToken(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, ANTLR3_COMMON_TOKEN_struct *child)
{
  ANTLR3_BASE_TREE_struct *v3; // rdi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v4; // rsi
  ANTLR3_BASE_TREE_struct *v5; // rbx

  if ( t )
  {
    v3 = t;
    v4 = adaptor;
    if ( child )
    {
      v5 = (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, child);
      v4->addChild(v4, v3, v5);
      v4->debugger->addChild(v4->debugger, v3, v5);
    }
  }
}

// File Line: 625
// RVA: 0x256CD0
ANTLR3_BASE_TREE_struct *__fastcall becomeRoot(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *newRootTree, ANTLR3_BASE_TREE_struct *oldRootTree)
{
  ANTLR3_BASE_TREE_struct *v3; // rsi
  ANTLR3_BASE_TREE_struct *v4; // rdi
  ANTLR3_BASE_TREE_struct *v6; // rbx
  __int64 v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rcx

  v3 = oldRootTree;
  v4 = newRootTree;
  if ( !newRootTree )
    return oldRootTree;
  if ( !oldRootTree )
    return newRootTree;
  if ( !newRootTree->isNilNode(newRootTree) )
    goto LABEL_8;
  if ( v4->getChildCount(v4) <= 1 )
  {
    v6 = v4;
    v7 = (__int64)v4->getChild(v4, 0);
    v8 = v4;
    v4 = (ANTLR3_BASE_TREE_struct *)v7;
    v6->reuse(v8);
LABEL_8:
    v4->addChild(v4, v3);
    if ( v3->isNilNode(v3) )
      v3->reuse(v3);
  }
  return v4;
}

// File Line: 696
// RVA: 0x256F40
ANTLR3_BASE_TREE_struct *__fastcall dbgBecomeRoot(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *newRootTree, ANTLR3_BASE_TREE_struct *oldRootTree)
{
  ANTLR3_BASE_TREE_struct *v3; // rsi
  ANTLR3_BASE_TREE_struct *v4; // rbp
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rdi
  ANTLR3_BASE_TREE_struct *v6; // rbx

  v3 = oldRootTree;
  v4 = newRootTree;
  v5 = adaptor;
  v6 = becomeRoot(adaptor, newRootTree, oldRootTree);
  v5->debugger->becomeRoot(v5->debugger, v4, v3);
  return v6;
}

// File Line: 709
// RVA: 0x2576F0
ANTLR3_BASE_TREE_struct *__fastcall rulePostProcessing(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *root)
{
  ANTLR3_BASE_TREE_struct *v2; // rdi
  __int64 v4; // rbx

  v2 = root;
  if ( !root )
    return 0i64;
  if ( !root->isNilNode(root) )
    return v2;
  if ( !v2->getChildCount(v2) )
    return 0i64;
  if ( v2->getChildCount(v2) != 1 )
    return v2;
  v4 = (__int64)v2->getChild(v2, 0);
  (*(void (__fastcall **)(__int64, _QWORD))(v4 + 152))(v4, 0i64);
  (*(void (__fastcall **)(__int64, signed __int64))(v4 + 120))(v4, 0xFFFFFFFFi64);
  v2->reuse(v2);
  return (ANTLR3_BASE_TREE_struct *)v4;
}

// File Line: 745
// RVA: 0x256D70
ANTLR3_BASE_TREE_struct *__fastcall becomeRootToken(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, void *newRoot, ANTLR3_BASE_TREE_struct *oldRoot)
{
  ANTLR3_BASE_TREE_struct *v3; // rbx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v4; // rdi
  void *v5; // rax

  v3 = oldRoot;
  v4 = adaptor;
  v5 = adaptor->create(adaptor, (ANTLR3_COMMON_TOKEN_struct *)newRoot);
  return (ANTLR3_BASE_TREE_struct *)v4->becomeRoot(v4, v5, v3);
}

// File Line: 750
// RVA: 0x256FA0
ANTLR3_BASE_TREE_struct *__fastcall dbgBecomeRootToken(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, void *newRoot, ANTLR3_BASE_TREE_struct *oldRoot)
{
  ANTLR3_BASE_TREE_struct *v3; // rsi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v4; // rdi
  void *v5; // rax
  __int64 v6; // rbx

  v3 = oldRoot;
  v4 = adaptor;
  v5 = adaptor->create(adaptor, (ANTLR3_COMMON_TOKEN_struct *)newRoot);
  v6 = (__int64)v4->becomeRoot(v4, v5, v3);
  v4->debugger->becomeRoot(v4->debugger, (ANTLR3_BASE_TREE_struct *)v6, v3);
  return (ANTLR3_BASE_TREE_struct *)v6;
}

// File Line: 765
// RVA: 0x256DD0
ANTLR3_BASE_TREE_struct *__fastcall createTypeToken(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, unsigned int tokenType, ANTLR3_COMMON_TOKEN_struct *fromToken)
{
  unsigned int v3; // edi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v4; // rsi
  ANTLR3_COMMON_TOKEN_struct *v5; // rbx

  v3 = tokenType;
  v4 = adaptor;
  v5 = adaptor->createTokenFromToken(adaptor, fromToken);
  v5->setType(v5, v3);
  return (ANTLR3_BASE_TREE_struct *)v4->create(v4, v5);
}

// File Line: 780
// RVA: 0x257050
ANTLR3_BASE_TREE_struct *__fastcall dbgCreateTypeToken(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, unsigned int tokenType, ANTLR3_COMMON_TOKEN_struct *fromToken)
{
  unsigned int v3; // edi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v4; // rsi
  ANTLR3_COMMON_TOKEN_struct *v5; // rbx
  __int64 v6; // rbx

  v3 = tokenType;
  v4 = adaptor;
  v5 = adaptor->createTokenFromToken(adaptor, fromToken);
  v5->setType(v5, v3);
  v6 = (__int64)v4->create(v4, v5);
  v4->debugger->createNode(v4->debugger, (ANTLR3_BASE_TREE_struct *)v6);
  return (ANTLR3_BASE_TREE_struct *)v6;
}

// File Line: 792
// RVA: 0x256E20
ANTLR3_BASE_TREE_struct *__fastcall createTypeTokenText(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, unsigned int tokenType, ANTLR3_COMMON_TOKEN_struct *fromToken, char *text)
{
  unsigned int v4; // ebx
  char *v5; // rsi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v6; // rbp
  ANTLR3_COMMON_TOKEN_struct *v7; // rdi

  v4 = tokenType;
  v5 = text;
  v6 = adaptor;
  v7 = adaptor->createTokenFromToken(adaptor, fromToken);
  v7->setType(v7, v4);
  v7->setText8(v7, v5);
  return (ANTLR3_BASE_TREE_struct *)v6->create(v6, v7);
}

// File Line: 811
// RVA: 0x2570B0
ANTLR3_BASE_TREE_struct *__fastcall dbgCreateTypeTokenText(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, unsigned int tokenType, ANTLR3_COMMON_TOKEN_struct *fromToken, char *text)
{
  unsigned int v4; // ebx
  char *v5; // rsi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v6; // rbp
  ANTLR3_COMMON_TOKEN_struct *v7; // rdi
  __int64 v8; // rbx

  v4 = tokenType;
  v5 = text;
  v6 = adaptor;
  v7 = adaptor->createTokenFromToken(adaptor, fromToken);
  v7->setType(v7, v4);
  v7->setText8(v7, v5);
  v8 = (__int64)v6->create(v6, v7);
  v6->debugger->createNode(v6->debugger, (ANTLR3_BASE_TREE_struct *)v8);
  return (ANTLR3_BASE_TREE_struct *)v8;
}

// File Line: 823
// RVA: 0x256DA0
ANTLR3_BASE_TREE_struct *__fastcall createTypeText(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, __int64 tokenType, char *text)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v3; // rbx
  ANTLR3_COMMON_TOKEN_struct *v4; // rax

  v3 = adaptor;
  v4 = adaptor->createToken(adaptor, tokenType, text);
  return (ANTLR3_BASE_TREE_struct *)v3->create(v3, v4);
}

// File Line: 836
// RVA: 0x257000
ANTLR3_BASE_TREE_struct *__fastcall dbgCreateTypeText(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, __int64 tokenType, char *text)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v3; // rdi
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rbx

  v3 = adaptor;
  v4 = adaptor->createToken(adaptor, tokenType, text);
  v5 = (__int64)v3->create(v3, v4);
  v3->debugger->createNode(v3->debugger, (ANTLR3_BASE_TREE_struct *)v5);
  return (ANTLR3_BASE_TREE_struct *)v5;
}

// File Line: 911
// RVA: 0x257590
__int64 __fastcall isNilNode(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return t->isNilNode(t);
}

