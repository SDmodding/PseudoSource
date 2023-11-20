// File Line: 58
// RVA: 0x256BB0
ANTLR3_BASE_TREE_struct *__fastcall antlr3BaseTreeNew(ANTLR3_BASE_TREE_struct *tree)
{
  tree->getChild = getChild;
  tree->getChildCount = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getChildCount;
  tree->addChild = (void (__fastcall *)(ANTLR3_BASE_TREE_struct *, void *))addChild;
  tree->addChildren = addChildren;
  tree->setChild = setChild;
  tree->deleteChild = (void *(__fastcall *)(ANTLR3_BASE_TREE_struct *, unsigned int))deleteChild;
  tree->dupTree = (void *(__fastcall *)(ANTLR3_BASE_TREE_struct *))dupTree;
  tree->toStringTree = toStringTree;
  tree->getCharPositionInLine = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))TargetVisibleInAIDataCondition::CreateClone;
  tree->getLine = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))TargetVisibleInAIDataCondition::CreateClone;
  tree->replaceChildren = replaceChildren;
  tree->freshenPACIndexesAll = freshenPACIndexesAll;
  tree->freshenPACIndexes = freshenPACIndexes;
  tree->getFirstChildWithType = (void *(__fastcall *)(ANTLR3_BASE_TREE_struct *, unsigned int))getFirstChildWithType;
  tree->children = 0i64;
  tree->strFactory = 0i64;
  return tree;
}

// File Line: 95
// RVA: 0x256760
ANTLR3_BASE_TREE_struct *__fastcall getFirstChildWithType(ANTLR3_BASE_TREE_struct *tree, unsigned int type)
{
  ANTLR3_VECTOR_struct *v2; // rax
  unsigned int v3; // er14
  ANTLR3_BASE_TREE_struct *v4; // rsi
  unsigned int v5; // ebx
  unsigned int v6; // edi
  __int64 v7; // rbp

  v2 = tree->children;
  v3 = type;
  v4 = tree;
  if ( !v2 )
    return 0i64;
  v5 = 0;
  v6 = v2->size(tree->children);
  if ( !v6 )
    return 0i64;
  while ( 1 )
  {
    v7 = (__int64)v4->children->get(v4->children, v5);
    if ( v4->getType((ANTLR3_BASE_TREE_struct *)v7) == v3 )
      break;
    if ( ++v5 >= v6 )
      return 0i64;
  }
  return (ANTLR3_BASE_TREE_struct *)v7;
}

// File Line: 119
// RVA: 0x2566F0
void *__fastcall getChild(ANTLR3_BASE_TREE_struct *tree, unsigned int i)
{
  ANTLR3_VECTOR_struct *v2; // rax
  unsigned int v3; // ebx
  ANTLR3_BASE_TREE_struct *v4; // rdi
  void *result; // rax

  v2 = tree->children;
  v3 = i;
  v4 = tree;
  if ( v2 && i < v2->size(tree->children) )
    result = v4->children->get(v4->children, v3);
  else
    result = 0i64;
  return result;
}

// File Line: 131
// RVA: 0x256740
ANTLR3_VECTOR_struct *__fastcall getChildCount(ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_VECTOR_struct *result; // rax

  result = tree->children;
  if ( result )
    result = (ANTLR3_VECTOR_struct *)result->size(tree->children);
  return result;
}

// File Line: 144
// RVA: 0x256450
void __fastcall addChild(ANTLR3_BASE_TREE_struct *tree, ANTLR3_BASE_TREE_struct *child)
{
  ANTLR3_BASE_TREE_struct *v2; // rsi
  ANTLR3_BASE_TREE_struct *v3; // rdi
  ANTLR3_VECTOR_struct *v4; // rax
  unsigned int v5; // ebx
  unsigned int v6; // ebp
  __int64 v7; // rax

  if ( child )
  {
    v2 = tree;
    v3 = child;
    if ( child->isNilNode(child) == 1 )
    {
      v4 = v3->children;
      if ( v4 && v4 != v2->children && v4 )
      {
        if ( v2->children )
        {
          v5 = 0;
          v6 = v4->size(v4);
          if ( v6 )
          {
            do
            {
              v7 = (__int64)v3->children->get(v3->children, v5);
              if ( v7 )
                v2->children->add(v2->children, (void *)v7, (void (__fastcall *)(void *))v3->free);
              ++v5;
            }
            while ( v5 < v6 );
          }
        }
        else
        {
          v2->children = v4;
          v3->children = 0i64;
          v2->freshenPACIndexes(v2, 0);
        }
      }
    }
    else
    {
      if ( !v2->children )
        v2->createChildrenList(v2);
      v2->children->add(v2->children, v3, (void (__fastcall *)(void *))v3->free);
    }
  }
}

// File Line: 222
// RVA: 0x256570
void __fastcall addChildren(ANTLR3_BASE_TREE_struct *tree, ANTLR3_LIST_struct *kids)
{
  ANTLR3_BASE_TREE_struct *v2; // rbp
  ANTLR3_LIST_struct *v3; // rdi
  unsigned int v4; // eax
  __int64 v5; // rsi
  signed __int64 v6; // rbx
  __int64 v7; // rax

  v2 = tree;
  v3 = kids;
  v4 = kids->size(kids);
  if ( v4 )
  {
    v5 = v4;
    v6 = 1i64;
    do
    {
      v7 = (__int64)v3->get(v3, v6);
      v2->addChild(v2, (void *)v7);
      ++v6;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 236
// RVA: 0x256A30
void __fastcall setChild(ANTLR3_BASE_TREE_struct *tree, unsigned int i, void *child)
{
  void *v3; // rdi
  unsigned int v4; // esi
  ANTLR3_BASE_TREE_struct *v5; // rbx
  char v6; // ST20_1

  v3 = child;
  v4 = i;
  v5 = tree;
  if ( !tree->children )
    ((void (*)(void))tree->createChildrenList)();
  v6 = 0;
  v5->children->set(v5->children, v4, v3, 0i64, v6);
}

// File Line: 246
// RVA: 0x2565D0
ANTLR3_VECTOR_struct *__fastcall deleteChild(ANTLR3_BASE_TREE_struct *tree, __int64 i)
{
  ANTLR3_VECTOR_struct *result; // rax

  result = tree->children;
  if ( result )
    result = (ANTLR3_VECTOR_struct *)result->remove(tree->children, i);
  return result;
}

// File Line: 257
// RVA: 0x2565F0
__int64 __fastcall dupTree(ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_BASE_TREE_struct *v1; // rbp
  __int64 v2; // rdi
  ANTLR3_VECTOR_struct *v3; // rax
  unsigned int v4; // ebx
  unsigned int v5; // esi
  __int64 v6; // rax
  __int64 v7; // rax

  v1 = tree;
  v2 = ((__int64 (*)(void))tree->dupNode)();
  v3 = v1->children;
  if ( !v3 )
    return v2;
  v4 = 0;
  v5 = v3->size(v1->children);
  if ( v5 )
  {
    do
    {
      v6 = (__int64)v1->children->get(v1->children, v4);
      if ( v6 )
      {
        v7 = (*(__int64 (__fastcall **)(__int64))(v6 + 96))(v6);
        (*(void (__fastcall **)(__int64, __int64))(v2 + 48))(v2, v7);
      }
      ++v4;
    }
    while ( v4 < v5 );
  }
  return v2;
}

// File Line: 288
// RVA: 0x256A80
ANTLR3_STRING_struct *__fastcall toStringTree(ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_VECTOR_struct *v1; // rax
  ANTLR3_BASE_TREE_struct *v2; // rdi
  __int64 v3; // rbx
  __int64 v4; // rax
  ANTLR3_VECTOR_struct *v5; // rax
  unsigned int v6; // esi
  unsigned int v7; // er14
  __int64 v8; // rbp
  __int64 v9; // rax

  v1 = tree->children;
  v2 = tree;
  if ( !v1 || !v1->size(tree->children) )
    return (ANTLR3_STRING_struct *)v2->toString(v2);
  v3 = (__int64)v2->strFactory->newRaw(v2->strFactory);
  if ( !v2->isNilNode(v2) )
  {
    (*(void (__fastcall **)(__int64, const char *))(v3 + 56))(v3, "(");
    v4 = (__int64)v2->toString(v2);
    (*(void (__fastcall **)(__int64, __int64))(v3 + 88))(v3, v4);
    (*(void (__fastcall **)(__int64, const char *))(v3 + 56))(v3, " ");
  }
  v5 = v2->children;
  if ( v5 )
  {
    v6 = 0;
    v7 = v5->size(v2->children);
    if ( v7 )
    {
      do
      {
        v8 = (__int64)v2->children->get(v2->children, v6);
        if ( v6 )
          (*(void (__fastcall **)(__int64, const char *))(v3 + 56))(v3, " ");
        v9 = (*(__int64 (__fastcall **)(__int64))(v8 + 208))(v8);
        (*(void (__fastcall **)(__int64, __int64))(v3 + 88))(v3, v9);
        ++v6;
      }
      while ( v6 < v7 );
    }
  }
  if ( !v2->isNilNode(v2) )
    (*(void (__fastcall **)(__int64, const char *))(v3 + 56))(v3, ")");
  return (ANTLR3_STRING_struct *)v3;
}

// File Line: 339
// RVA: 0x2567F0
void __fastcall replaceChildren(ANTLR3_BASE_TREE_struct *parent, int startChildIndex, int stopChildIndex, ANTLR3_BASE_TREE_struct *newTree)
{
  ANTLR3_BASE_TREE_struct *v4; // rbx
  int v5; // er15
  unsigned int v6; // er14
  ANTLR3_BASE_TREE_struct *v7; // rsi
  ANTLR3_VECTOR_struct *v8; // rdi
  ANTLR3_VECTOR_struct *v9; // rax
  int v10; // ebp
  int v11; // er12
  signed int v12; // eax
  signed int v13; // er13
  __int64 v14; // rbx
  signed int v15; // er12
  ANTLR3_VECTOR_struct *v16; // rbx
  __int64 v17; // rax
  unsigned int v18; // ebp
  __int64 v19; // rbx
  int i; // er15
  ANTLR3_VECTOR_struct *v21; // rbx
  __int64 v22; // rax
  ANTLR3_VECTOR_struct *v23; // rbx
  __int64 v24; // rax
  __int64 v25[2]; // [rsp+20h] [rbp-38h]
  char v26; // [rsp+60h] [rbp+8h]

  v4 = newTree;
  v5 = stopChildIndex;
  v6 = startChildIndex;
  v7 = parent;
  if ( parent->children )
  {
    if ( newTree->isNilNode(newTree) )
    {
      v8 = v4->children;
      v26 = 0;
    }
    else
    {
      v9 = antlr3VectorNew(1u);
      v8 = v9;
      if ( !v9 )
        exit(1);
      v9->add(v9, v4, 0i64);
      v26 = 1;
    }
    v10 = v5 - v6 + 1;
    v11 = v8->size(v8);
    v12 = v8->size(v8);
    v13 = v12;
    if ( v10 == v11 )
    {
      for ( ; (signed int)v6 <= v5; ++v6 )
      {
        v14 = (__int64)v8->get(v8, 0);
        LOBYTE(v25[0]) = 0;
        v7->children->set(v7->children, v6, (void *)v14, 0i64, v25[0]);
        (*(void (__fastcall **)(__int64, ANTLR3_BASE_TREE_struct *))(v14 + 152))(v14, v7);
        (*(void (__fastcall **)(__int64, _QWORD))(v14 + 120))(v14, v6);
      }
    }
    else
    {
      if ( (signed int)(v5 - v6 + 1 - v11) <= 0 )
      {
        for ( i = 0; i < v10; ++i )
        {
          v21 = v7->children;
          v22 = (__int64)v8->get(v8, i);
          LOBYTE(v25[0]) = 0;
          v21->set(v7->children, i + v6, (void *)v22, 0i64, v25[0]);
        }
        for ( ; v10 < v11; ++v10 )
        {
          v23 = v7->children;
          v24 = (__int64)v8->get(v8, v10);
          v23->add(v7->children, (void *)v24, 0i64);
        }
      }
      else
      {
        v15 = 0;
        if ( v12 > 0 )
        {
          do
          {
            v16 = v7->children;
            v17 = (__int64)v8->get(v8, v15);
            LOBYTE(v25[0]) = 0;
            v16->set(v7->children, v15++ + v6, (void *)v17, 0i64, v25[0]);
          }
          while ( v15 < v13 );
        }
        v18 = v6 + v13;
        if ( (signed int)(v6 + v13) <= v5 )
        {
          v19 = v5 - v18 + 1;
          do
          {
            v7->children->remove(v7->children, v18);
            --v19;
          }
          while ( v19 );
        }
      }
      v7->freshenPACIndexes(v7, v6);
    }
    if ( v26 == 1 )
    {
      antlrFree(v8->elements);
      v8->elements = 0i64;
      v8->size = 0i64;
      antlrFree(v8);
    }
  }
}

// File Line: 461
// RVA: 0x2566E0
void __fastcall freshenPACIndexesAll(ANTLR3_BASE_TREE_struct *tree)
{
  tree->freshenPACIndexes(tree, 0);
}

// File Line: 470
// RVA: 0x256680
void __fastcall freshenPACIndexes(ANTLR3_BASE_TREE_struct *tree, unsigned int offset)
{
  unsigned int v2; // ebx
  ANTLR3_BASE_TREE_struct *v3; // rsi
  unsigned int i; // ebp
  __int64 v5; // rdi

  v2 = offset;
  v3 = tree;
  for ( i = ((__int64 (*)(void))tree->getChildCount)(); v2 < i; ++v2 )
  {
    v5 = (__int64)v3->getChild(v3, v2);
    (*(void (__fastcall **)(__int64, _QWORD))(v5 + 120))(v5, v2);
    (*(void (__fastcall **)(__int64, ANTLR3_BASE_TREE_struct *))(v5 + 152))(v5, v3);
  }
}

