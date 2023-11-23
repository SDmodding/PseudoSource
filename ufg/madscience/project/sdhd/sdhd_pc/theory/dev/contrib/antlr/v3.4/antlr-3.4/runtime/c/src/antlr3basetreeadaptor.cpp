// File Line: 85
// RVA: 0x257810
void __fastcall antlr3BaseTreeAdaptorInit(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
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
  void *v4; // rsi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rdi
  int v6; // eax
  unsigned int v7; // ebp
  __int64 v8; // rax
  unsigned int v9; // edi
  __int64 v10; // rsi
  int v11; // eax
  unsigned int v12; // eax
  const char *v13; // rdx
  void *ta; // [rsp+20h] [rbp-68h]
  char string[88]; // [rsp+30h] [rbp-58h] BYREF
  int v18; // [rsp+A8h] [rbp+20h]

  v4 = t;
  v5 = adaptor;
  v6 = ((__int64 (*)(void))adaptor->getChildCount)();
  v18 = v6;
  if ( v6 )
  {
    v7 = 0;
    if ( v6 > 0 )
    {
      while ( 1 )
      {
        ta = v5->getChild(v5, v4, v7);
        sprintf(string, "\tn%p[label=\"", ta);
        dotSpec->append8(dotSpec, string);
        v8 = (__int64)v5->getText(v5, ta);
        v9 = 0;
        v10 = v8;
        if ( *(int *)(v8 + 16) > 0 )
          break;
LABEL_13:
        dotSpec->append8(dotSpec, "\"]\n");
        v5 = adaptor;
        defineDotNodes(adaptor, ta, dotSpec);
        v4 = t;
        if ( (int)++v7 >= v18 )
          return;
      }
      while ( 1 )
      {
        v11 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v10 + 152))(v10, v9);
        if ( v11 == 10 )
        {
          v13 = "\\n";
          goto LABEL_11;
        }
        if ( v11 == 13 )
          break;
        if ( v11 == 34 )
        {
          v13 = "\\\"";
LABEL_11:
          dotSpec->append8(dotSpec, v13);
          goto LABEL_12;
        }
        v12 = (*(__int64 (__fastcall **)(__int64, _QWORD))(v10 + 152))(v10, v9);
        dotSpec->addc(dotSpec, v12);
LABEL_12:
        if ( (signed int)++v9 >= *(_DWORD *)(v10 + 16) )
          goto LABEL_13;
      }
      v13 = "\\r";
      goto LABEL_11;
    }
  }
}

// File Line: 245
// RVA: 0x2571A0
void __fastcall defineDotEdges(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, void *t, ANTLR3_STRING_struct *dotSpec)
{
  void *v4; // rdi
  int v6; // ecx
  int v7; // eax
  ANTLR3_STRING_struct *v8; // rax
  unsigned int v9; // edi
  ANTLR3_STRING_struct *v10; // rsi
  unsigned int v11; // eax
  unsigned int v12; // eax
  const char *v13; // rdx
  unsigned int v14; // edi
  ANTLR3_STRING_struct *v15; // rsi
  unsigned int v16; // eax
  unsigned int v17; // eax
  const char *v18; // rdx
  int v19; // [rsp+20h] [rbp-A8h]
  void *ta; // [rsp+28h] [rbp-A0h]
  char string[152]; // [rsp+30h] [rbp-98h] BYREF
  int v23; // [rsp+E8h] [rbp+20h]

  if ( t )
  {
    v4 = t;
    v6 = ((__int64 (*)(void))adaptor->getChildCount)();
    v19 = v6;
    if ( v6 )
    {
      v7 = 0;
      v23 = 0;
      if ( v6 > 0 )
      {
        while ( 1 )
        {
          ta = adaptor->getChild(adaptor, v4, (unsigned int)v7);
          sprintf(string, "\t\tn%p -> n%p\t\t// ", v4, ta);
          dotSpec->append8(dotSpec, string);
          v8 = adaptor->getText(adaptor, v4);
          v9 = 0;
          v10 = v8;
          if ( (int)v8->len > 0 )
          {
            while ( 1 )
            {
              v11 = v10->charAt(v10, v9);
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
                dotSpec->append8(dotSpec, v13);
                goto LABEL_13;
              }
              v12 = v10->charAt(v10, v9);
              dotSpec->addc(dotSpec, v12);
LABEL_13:
              if ( (signed int)++v9 >= (signed int)v10->len )
                goto LABEL_14;
            }
            v13 = "\\r";
            goto LABEL_12;
          }
LABEL_14:
          dotSpec->append8(dotSpec, " -> ");
          v14 = 0;
          v15 = adaptor->getText(adaptor, ta);
          if ( (int)v15->len > 0 )
            break;
LABEL_24:
          dotSpec->append8(dotSpec, "\n");
          defineDotEdges(adaptor, ta, dotSpec);
          v4 = t;
          v7 = v23 + 1;
          v23 = v7;
          if ( v7 >= v19 )
            return;
        }
        while ( 1 )
        {
          v16 = v15->charAt(v15, v14);
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
            dotSpec->append8(dotSpec, v18);
            goto LABEL_23;
          }
          v17 = v15->charAt(v15, v14);
          dotSpec->addc(dotSpec, v17);
LABEL_23:
          if ( (signed int)++v14 >= (signed int)v15->len )
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
  ANTLR3_STRING_struct *v4; // rax
  ANTLR3_STRING_struct *v5; // rbx
  unsigned int v6; // edi
  ANTLR3_STRING_struct *v7; // rsi
  unsigned int v8; // eax
  unsigned int v9; // eax
  const char *v10; // rdx
  char string[64]; // [rsp+20h] [rbp-48h] BYREF

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
  if ( theTree )
  {
    sprintf(string, "\tn%p[label=\"", theTree);
    v5->append8(v5, string);
    v6 = 0;
    v7 = adaptor->getText(adaptor, theTree);
    if ( (int)v7->len <= 0 )
    {
LABEL_13:
      v5->append8(v5, "\"]\n");
      defineDotNodes(adaptor, theTree, v5);
      v5->append8(v5, "\n");
      defineDotEdges(adaptor, theTree, v5);
      v5->append8(v5, "\n}");
      return v5;
    }
    while ( 1 )
    {
      v8 = v7->charAt(v7, v6);
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
      v9 = v7->charAt(v7, v6);
      v5->addc(v5, v9);
LABEL_12:
      if ( (signed int)++v6 >= (signed int)v7->len )
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
  ANTLR3_BASE_TREE_struct *v2; // rbx

  v2 = (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, 0i64);
  adaptor->debugger->createNode(adaptor->debugger, v2);
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
ANTLR3_BASE_TREE_struct *__fastcall dupTreeTT(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        ANTLR3_BASE_TREE_struct *parent)
{
  void *v7; // rbp
  unsigned int v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // r14d
  void *v11; // rax
  void *v12; // rax

  if ( !t )
    return 0i64;
  v7 = t->dupNode(t);
  v8 = t->getChildIndex(t);
  adaptor->setChildIndex(adaptor, v7, v8);
  adaptor->setParent(adaptor, v7, parent);
  v9 = 0;
  v10 = adaptor->getChildCount(adaptor, t);
  if ( v10 )
  {
    do
    {
      v11 = adaptor->getChild(adaptor, t, v9);
      v12 = adaptor->dupTreeTT(adaptor, v11, t);
      adaptor->addChild(adaptor, v7, v12);
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
  unsigned int v4; // esi
  ANTLR3_BASE_TREE_struct *v5; // rdi
  unsigned int v6; // [rsp+30h] [rbp+8h]

  ((void (__fastcall *)(ANTLR3_DEBUG_EVENT_LISTENER_struct *))adaptor->debugger->createNode)(adaptor->debugger);
  v4 = 0;
  v6 = adaptor->getChildCount(adaptor, tree);
  if ( v6 )
  {
    do
    {
      v5 = (ANTLR3_BASE_TREE_struct *)adaptor->getChild(adaptor, tree, v4);
      simulateTreeConstruction(adaptor, v5);
      adaptor->debugger->addChild(adaptor->debugger, tree, v5);
      ++v4;
    }
    while ( v4 < v6 );
  }
}

// File Line: 525
// RVA: 0x257130
ANTLR3_BASE_TREE_struct *__fastcall dbgDupTree(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_BASE_TREE_struct *v3; // rbx

  v3 = (ANTLR3_BASE_TREE_struct *)adaptor->dupTreeTT(adaptor, tree, 0i64);
  simulateTreeConstruction(adaptor, v3);
  return v3;
}

// File Line: 553
// RVA: 0x256C70
void __fastcall addChild_0(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        ANTLR3_BASE_TREE_struct *child)
{
  if ( t )
  {
    if ( child )
      t->addChild(t, child);
  }
}

// File Line: 561
// RVA: 0x256E90
void __fastcall dbgAddChild(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        ANTLR3_BASE_TREE_struct *child)
{
  if ( t )
  {
    if ( child )
    {
      t->addChild(t, child);
      adaptor->debugger->addChild(adaptor->debugger, t, child);
    }
  }
}

// File Line: 572
// RVA: 0x256C90
void __fastcall addChildToken(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        ANTLR3_COMMON_TOKEN_struct *child)
{
  void *v5; // rax

  if ( t )
  {
    if ( child )
    {
      v5 = adaptor->create(adaptor, child);
      adaptor->addChild(adaptor, t, v5);
    }
  }
}

// File Line: 580
// RVA: 0x256EE0
void __fastcall dbgAddChildToken(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        ANTLR3_COMMON_TOKEN_struct *child)
{
  ANTLR3_BASE_TREE_struct *v5; // rbx

  if ( t )
  {
    if ( child )
    {
      v5 = (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, child);
      adaptor->addChild(adaptor, t, v5);
      adaptor->debugger->addChild(adaptor->debugger, t, v5);
    }
  }
}

// File Line: 625
// RVA: 0x256CD0
ANTLR3_BASE_TREE_struct *__fastcall becomeRoot(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *newRootTree,
        ANTLR3_BASE_TREE_struct *oldRootTree)
{
  ANTLR3_BASE_TREE_struct *v4; // rdi
  ANTLR3_BASE_TREE_struct *v6; // rbx
  __int64 v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rcx

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
    v4->addChild(v4, oldRootTree);
    if ( oldRootTree->isNilNode(oldRootTree) )
      oldRootTree->reuse(oldRootTree);
  }
  return v4;
}

// File Line: 696
// RVA: 0x256F40
ANTLR3_BASE_TREE_struct *__fastcall dbgBecomeRoot(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *newRootTree,
        ANTLR3_BASE_TREE_struct *oldRootTree)
{
  ANTLR3_BASE_TREE_struct *v6; // rbx

  v6 = becomeRoot(adaptor, newRootTree, oldRootTree);
  adaptor->debugger->becomeRoot(adaptor->debugger, newRootTree, oldRootTree);
  return v6;
}

// File Line: 709
// RVA: 0x2576F0
ANTLR3_BASE_TREE_struct *__fastcall rulePostProcessing(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *root)
{
  void (__fastcall **v4)(void *, _QWORD); // rbx

  if ( !root )
    return 0i64;
  if ( !root->isNilNode(root) )
    return root;
  if ( !root->getChildCount(root) )
    return 0i64;
  if ( root->getChildCount(root) != 1 )
    return root;
  v4 = (void (__fastcall **)(void *, _QWORD))root->getChild(root, 0i64);
  v4[19](v4, 0i64);
  v4[15](v4, 0xFFFFFFFFi64);
  root->reuse(root);
  return (ANTLR3_BASE_TREE_struct *)v4;
}

// File Line: 745
// RVA: 0x256D70
ANTLR3_BASE_TREE_struct *__fastcall becomeRootToken(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_COMMON_TOKEN_struct *newRoot,
        ANTLR3_BASE_TREE_struct *oldRoot)
{
  void *v5; // rax

  v5 = adaptor->create(adaptor, newRoot);
  return (ANTLR3_BASE_TREE_struct *)adaptor->becomeRoot(adaptor, v5, oldRoot);
}

// File Line: 750
// RVA: 0x256FA0
ANTLR3_BASE_TREE_struct *__fastcall dbgBecomeRootToken(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_COMMON_TOKEN_struct *newRoot,
        ANTLR3_BASE_TREE_struct *oldRoot)
{
  void *v5; // rax
  ANTLR3_BASE_TREE_struct *v6; // rbx

  v5 = adaptor->create(adaptor, newRoot);
  v6 = (ANTLR3_BASE_TREE_struct *)adaptor->becomeRoot(adaptor, v5, oldRoot);
  adaptor->debugger->becomeRoot(adaptor->debugger, v6, oldRoot);
  return v6;
}

// File Line: 765
// RVA: 0x256DD0
ANTLR3_BASE_TREE_struct *__fastcall createTypeToken(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        unsigned int tokenType,
        ANTLR3_COMMON_TOKEN_struct *fromToken)
{
  ANTLR3_COMMON_TOKEN_struct *v5; // rbx

  v5 = adaptor->createTokenFromToken(adaptor, fromToken);
  v5->setType(v5, tokenType);
  return (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, v5);
}

// File Line: 780
// RVA: 0x257050
ANTLR3_BASE_TREE_struct *__fastcall dbgCreateTypeToken(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        unsigned int tokenType,
        ANTLR3_COMMON_TOKEN_struct *fromToken)
{
  ANTLR3_COMMON_TOKEN_struct *v5; // rbx
  ANTLR3_BASE_TREE_struct *v6; // rbx

  v5 = adaptor->createTokenFromToken(adaptor, fromToken);
  v5->setType(v5, tokenType);
  v6 = (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, v5);
  adaptor->debugger->createNode(adaptor->debugger, v6);
  return v6;
}

// File Line: 792
// RVA: 0x256E20
ANTLR3_BASE_TREE_struct *__fastcall createTypeTokenText(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        unsigned int tokenType,
        ANTLR3_COMMON_TOKEN_struct *fromToken,
        char *text)
{
  ANTLR3_COMMON_TOKEN_struct *v7; // rdi

  v7 = adaptor->createTokenFromToken(adaptor, fromToken);
  v7->setType(v7, tokenType);
  v7->setText8(v7, text);
  return (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, v7);
}

// File Line: 811
// RVA: 0x2570B0
ANTLR3_BASE_TREE_struct *__fastcall dbgCreateTypeTokenText(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        unsigned int tokenType,
        ANTLR3_COMMON_TOKEN_struct *fromToken,
        char *text)
{
  ANTLR3_COMMON_TOKEN_struct *v7; // rdi
  ANTLR3_BASE_TREE_struct *v8; // rbx

  v7 = adaptor->createTokenFromToken(adaptor, fromToken);
  v7->setType(v7, tokenType);
  v7->setText8(v7, text);
  v8 = (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, v7);
  adaptor->debugger->createNode(adaptor->debugger, v8);
  return v8;
}

// File Line: 823
// RVA: 0x256DA0
ANTLR3_BASE_TREE_struct *__fastcall createTypeText(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        __int64 tokenType,
        char *text)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax

  v4 = adaptor->createToken(adaptor, tokenType, text);
  return (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, v4);
}

// File Line: 836
// RVA: 0x257000
ANTLR3_BASE_TREE_struct *__fastcall dbgCreateTypeText(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        __int64 tokenType,
        char *text)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_struct *v5; // rbx

  v4 = adaptor->createToken(adaptor, tokenType, text);
  v5 = (ANTLR3_BASE_TREE_struct *)adaptor->create(adaptor, v4);
  adaptor->debugger->createNode(adaptor->debugger, v5);
  return v5;
}

// File Line: 911
// RVA: 0x257590
__int64 __fastcall isNilNode(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return ((__int64 (__fastcall *)(ANTLR3_BASE_TREE_struct *))t->isNilNode)(t);
}

