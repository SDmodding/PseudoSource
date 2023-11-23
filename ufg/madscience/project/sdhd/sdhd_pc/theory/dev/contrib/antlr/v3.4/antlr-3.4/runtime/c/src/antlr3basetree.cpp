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
  tree->replaceChildren = (void (__fastcall *)(ANTLR3_BASE_TREE_struct *, int, int, ANTLR3_BASE_TREE_struct *))replaceChildren;
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
  ANTLR3_VECTOR_struct *children; // rax
  unsigned int v5; // ebx
  unsigned int v6; // edi
  ANTLR3_BASE_TREE_struct *v7; // rbp

  children = tree->children;
  if ( !children )
    return 0i64;
  v5 = 0;
  v6 = children->size(tree->children);
  if ( !v6 )
    return 0i64;
  while ( 1 )
  {
    v7 = (ANTLR3_BASE_TREE_struct *)tree->children->get(tree->children, v5);
    if ( tree->getType(v7) == type )
      break;
    if ( ++v5 >= v6 )
      return 0i64;
  }
  return v7;
}

// File Line: 119
// RVA: 0x2566F0
void *__fastcall getChild(ANTLR3_BASE_TREE_struct *tree, unsigned int i)
{
  ANTLR3_VECTOR_struct *children; // rax

  children = tree->children;
  if ( children && i < children->size(tree->children) )
    return tree->children->get(tree->children, i);
  else
    return 0i64;
}

// File Line: 131
// RVA: 0x256740
ANTLR3_VECTOR_struct *__fastcall getChildCount(ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_VECTOR_struct *result; // rax

  result = tree->children;
  if ( result )
    return (ANTLR3_VECTOR_struct *)((__int64 (__fastcall *)(ANTLR3_VECTOR_struct *))result->size)(tree->children);
  return result;
}

// File Line: 144
// RVA: 0x256450
void __fastcall addChild(ANTLR3_BASE_TREE_struct *tree, ANTLR3_BASE_TREE_struct *child)
{
  ANTLR3_VECTOR_struct *children; // rax
  unsigned int v5; // ebx
  unsigned int v6; // ebp
  void *v7; // rax

  if ( child )
  {
    if ( child->isNilNode(child) == 1 )
    {
      children = child->children;
      if ( children && children != tree->children )
      {
        if ( tree->children )
        {
          v5 = 0;
          v6 = children->size(children);
          if ( v6 )
          {
            do
            {
              v7 = child->children->get(child->children, v5);
              if ( v7 )
                tree->children->add(tree->children, v7, (void (__fastcall *)(void *))child->free);
              ++v5;
            }
            while ( v5 < v6 );
          }
        }
        else
        {
          tree->children = children;
          child->children = 0i64;
          tree->freshenPACIndexes(tree, 0);
        }
      }
    }
    else
    {
      if ( !tree->children )
        tree->createChildrenList(tree);
      tree->children->add(tree->children, child, (void (__fastcall *)(void *))child->free);
    }
  }
}

// File Line: 222
// RVA: 0x256570
void __fastcall addChildren(ANTLR3_BASE_TREE_struct *tree, ANTLR3_LIST_struct *kids)
{
  unsigned int v4; // eax
  __int64 v5; // rsi
  unsigned __int64 v6; // rbx
  void *v7; // rax

  v4 = kids->size(kids);
  if ( v4 )
  {
    v5 = v4;
    v6 = 1i64;
    do
    {
      v7 = kids->get(kids, v6);
      tree->addChild(tree, v7);
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
  char v6; // [rsp+20h] [rbp-18h]

  if ( !tree->children )
    ((void (*)(void))tree->createChildrenList)();
  v6 = 0;
  tree->children->set(tree->children, i, child, 0i64, v6);
}

// File Line: 246
// RVA: 0x2565D0
ANTLR3_VECTOR_struct *__fastcall deleteChild(ANTLR3_BASE_TREE_struct *tree, __int64 i)
{
  ANTLR3_VECTOR_struct *result; // rax

  result = tree->children;
  if ( result )
    return (ANTLR3_VECTOR_struct *)result->remove(tree->children, i);
  return result;
}

// File Line: 257
// RVA: 0x2565F0
__int64 __fastcall dupTree(ANTLR3_BASE_TREE_struct *tree)
{
  __int64 v2; // rdi
  ANTLR3_VECTOR_struct *children; // rax
  unsigned int v4; // ebx
  unsigned int v5; // esi
  __int64 (__fastcall **v6)(void *); // rax
  __int64 v7; // rax

  v2 = ((__int64 (*)(void))tree->dupNode)();
  children = tree->children;
  if ( !children )
    return v2;
  v4 = 0;
  v5 = children->size(tree->children);
  if ( v5 )
  {
    do
    {
      v6 = (__int64 (__fastcall **)(void *))tree->children->get(tree->children, v4);
      if ( v6 )
      {
        v7 = v6[12](v6);
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
  ANTLR3_VECTOR_struct *children; // rax
  ANTLR3_STRING_struct *v3; // rbx
  ANTLR3_STRING_struct *v4; // rax
  ANTLR3_VECTOR_struct *v5; // rax
  unsigned int v6; // esi
  unsigned int v7; // r14d
  __int64 (__fastcall **v8)(void *); // rbp
  __int64 v9; // rax

  children = tree->children;
  if ( !children || !children->size(tree->children) )
    return tree->toString(tree);
  v3 = tree->strFactory->newRaw(tree->strFactory);
  if ( !tree->isNilNode(tree) )
  {
    v3->append8(v3, "(");
    v4 = tree->toString(tree);
    v3->appendS(v3, v4);
    v3->append8(v3, " ");
  }
  v5 = tree->children;
  if ( v5 )
  {
    v6 = 0;
    v7 = v5->size(tree->children);
    if ( v7 )
    {
      do
      {
        v8 = (__int64 (__fastcall **)(void *))tree->children->get(tree->children, v6);
        if ( v6 )
          v3->append8(v3, " ");
        v9 = v8[26](v8);
        v3->appendS(v3, (ANTLR3_STRING_struct *)v9);
        ++v6;
      }
      while ( v6 < v7 );
    }
  }
  if ( !tree->isNilNode(tree) )
    v3->append8(v3, ")");
  return v3;
}

// File Line: 339
// RVA: 0x2567F0
void __fastcall replaceChildren(
        ANTLR3_BASE_TREE_struct *parent,
        unsigned int startChildIndex,
        int stopChildIndex,
        ANTLR3_BASE_TREE_struct *newTree)
{
  ANTLR3_VECTOR_struct *children; // rdi
  ANTLR3_VECTOR_struct *v9; // rax
  int v10; // ebp
  int v11; // r12d
  int v12; // eax
  int v13; // r13d
  void (__fastcall **v14)(_QWORD, _QWORD); // rbx
  int v15; // r12d
  ANTLR3_VECTOR_struct *v16; // rbx
  __int64 v17; // rax
  unsigned int v18; // ebp
  __int64 v19; // rbx
  int i; // r15d
  ANTLR3_VECTOR_struct *v21; // rbx
  __int64 v22; // rax
  ANTLR3_VECTOR_struct *v23; // rbx
  __int64 v24; // rax
  int v25; // [rsp+20h] [rbp-38h]
  char v26; // [rsp+60h] [rbp+8h]

  if ( parent->children )
  {
    if ( newTree->isNilNode(newTree) )
    {
      children = newTree->children;
      v26 = 0;
    }
    else
    {
      v9 = antlr3VectorNew(1u);
      children = v9;
      if ( !v9 )
        exit(1);
      v9->add(v9, newTree, 0i64);
      v26 = 1;
    }
    v10 = stopChildIndex - startChildIndex + 1;
    v11 = children->size(children);
    v12 = children->size(children);
    v13 = v12;
    if ( v10 == v11 )
    {
      for ( ; (int)startChildIndex <= stopChildIndex; ++startChildIndex )
      {
        v14 = (void (__fastcall **)(_QWORD, _QWORD))children->get(children, 0);
        LOBYTE(v25) = 0;
        parent->children->set(parent->children, startChildIndex, v14, 0i64, v25);
        ((void (__fastcall **)(_QWORD, ANTLR3_BASE_TREE_struct *))v14)[19](v14, parent);
        v14[15](v14, startChildIndex);
      }
    }
    else
    {
      if ( v10 - v11 <= 0 )
      {
        for ( i = 0; i < v10; ++i )
        {
          v21 = parent->children;
          v22 = (__int64)children->get(children, i);
          LOBYTE(v25) = 0;
          v21->set(parent->children, i + startChildIndex, (void *)v22, 0i64, v25);
        }
        for ( ; v10 < v11; ++v10 )
        {
          v23 = parent->children;
          v24 = (__int64)children->get(children, v10);
          v23->add(parent->children, (void *)v24, 0i64);
        }
      }
      else
      {
        v15 = 0;
        if ( v12 > 0 )
        {
          do
          {
            v16 = parent->children;
            v17 = (__int64)children->get(children, v15);
            LOBYTE(v25) = 0;
            v16->set(parent->children, v15 + startChildIndex, (void *)v17, 0i64, v25);
            ++v15;
          }
          while ( v15 < v13 );
        }
        v18 = startChildIndex + v13;
        if ( (int)(startChildIndex + v13) <= stopChildIndex )
        {
          v19 = stopChildIndex - v18 + 1;
          do
          {
            parent->children->remove(parent->children, v18);
            --v19;
          }
          while ( v19 );
        }
      }
      parent->freshenPACIndexes(parent, startChildIndex);
    }
    if ( v26 == 1 )
    {
      antlrFree((char *)children->elements);
      children->elements = 0i64;
      children->size = 0i64;
      antlrFree((char *)children);
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
  unsigned int i; // ebp
  void (__fastcall **v5)(void *, _QWORD); // rdi

  for ( i = ((__int64 (*)(void))tree->getChildCount)(); offset < i; ++offset )
  {
    v5 = (void (__fastcall **)(void *, _QWORD))tree->getChild(tree, offset);
    v5[15](v5, offset);
    ((void (__fastcall **)(void *, ANTLR3_BASE_TREE_struct *))v5)[19](v5, tree);
  }
}

