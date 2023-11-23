// File Line: 69
// RVA: 0x25ADF0
UFG::allocator::free_link *__fastcall antlr3ArboretumNew(UFG::allocator::free_link *strFactory)
{
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax

  v2 = antlrMalloc(0x178ui64);
  if ( !v2 )
    return 0i64;
  v3 = antlr3VectorFactoryNew(0);
  v2[41].mNext = v3;
  if ( !v3 )
  {
    free(v2);
    return 0i64;
  }
  v2[42].mNext = (UFG::allocator::free_link *)antlr3StackNew(0);
  v2->mNext = 0i64;
  v2[43].mNext = (UFG::allocator::free_link *)newPoolTree;
  LODWORD(v2[1].mNext) = 0;
  v2[44].mNext = (UFG::allocator::free_link *)newFromTree;
  v2[45].mNext = (UFG::allocator::free_link *)newFromToken;
  v2[46].mNext = (UFG::allocator::free_link *)factoryClose_0;
  v2->mNext = antlrRealloc(0i64, 8ui64);
  v2->mNext[SLODWORD(v2[1].mNext)].mNext = antlrMalloc(0x4E000ui64);
  HIDWORD(v2[1].mNext) = 0;
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v2[2]);
  v2[8].mNext = v2;
  v2[13].mNext = strFactory;
  return v2;
}

// File Line: 158
// RVA: 0x25AC60
ANTLR3_BASE_TREE_struct *__fastcall newPoolTree(ANTLR3_ARBORETUM_struct *factory)
{
  void *v2; // rbx
  ANTLR3_BASE_TREE_struct *result; // rax
  ANTLR3_COMMON_TREE_struct *v4; // rbx

  v2 = factory->nilStack->peek(factory->nilStack);
  if ( v2 )
  {
    factory->nilStack->pop(factory->nilStack);
    return (ANTLR3_BASE_TREE_struct *)v2;
  }
  else
  {
    if ( factory->nextTree >= 0x400 )
    {
      ++factory->thisPool;
      factory->pools = (ANTLR3_COMMON_TREE_struct **)antlrRealloc(
                                                       factory->pools,
                                                       (unsigned int)(8 * factory->thisPool + 8));
      factory->pools[factory->thisPool] = (ANTLR3_COMMON_TREE_struct *)antlrMalloc(0x4E000ui64);
      factory->nextTree = 0;
    }
    v4 = &factory->pools[factory->thisPool][factory->nextTree++];
    antlr3SetCTAPI(v4);
    v4->factory = factory;
    v4->baseTree.strFactory = factory->unTruc.baseTree.strFactory;
    result = &v4->baseTree;
    v4->baseTree.super = v4;
  }
  return result;
}

// File Line: 217
// RVA: 0x25AC20
ANTLR3_BASE_TREE_struct *__fastcall newFromTree(ANTLR3_ARBORETUM_struct *factory, ANTLR3_COMMON_TREE_struct *tree)
{
  ANTLR3_BASE_TREE_struct *result; // rax

  result = (ANTLR3_BASE_TREE_struct *)((__int64 (*)(void))factory->newTree)();
  if ( result )
  {
    *((_QWORD *)result->super + 3) = tree->token;
    result->u = tree->baseTree.u;
  }
  return result;
}

// File Line: 237
// RVA: 0x25ABF0
ANTLR3_BASE_TREE_struct *__fastcall newFromToken(ANTLR3_ARBORETUM_struct *factory, ANTLR3_COMMON_TOKEN_struct *token)
{
  ANTLR3_BASE_TREE_struct *result; // rax

  result = (ANTLR3_BASE_TREE_struct *)((__int64 (*)(void))factory->newTree)();
  if ( result )
    *((_QWORD *)result->super + 3) = token;
  return result;
}

// File Line: 256
// RVA: 0x25AA00
void __fastcall factoryClose_0(ANTLR3_ARBORETUM_struct *factory)
{
  ANTLR3_STACK_struct *nilStack; // rax
  int v3; // esi
  __int64 v4; // rdi

  factory->vFactory->close(factory->vFactory);
  nilStack = factory->nilStack;
  if ( nilStack )
    nilStack->free(factory->nilStack);
  v3 = 0;
  if ( factory->thisPool >= 0 )
  {
    v4 = 0i64;
    do
    {
      antlrFree((char *)factory->pools[v4]);
      ++v3;
      factory->pools[v4++] = 0i64;
    }
    while ( v3 <= factory->thisPool );
  }
  antlrFree((char *)factory->pools);
  antlrFree((char *)factory);
}

// File Line: 293
// RVA: 0x25AF70
void __fastcall antlr3SetCTAPI(ANTLR3_COMMON_TREE_struct *tree)
{
  antlr3BaseTreeNew(&tree->baseTree);
  tree->baseTree.isNilNode = (char (__fastcall *)(ANTLR3_BASE_TREE_struct *))isNilNode_0;
  tree->baseTree.super = tree;
  tree->baseTree.dupNode = (void *(__fastcall *)(ANTLR3_BASE_TREE_struct *))dupNode;
  tree->childIndex = -1;
  tree->baseTree.getLine = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getLine;
  tree->baseTree.getCharPositionInLine = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getCharPositionInLine;
  tree->baseTree.toString = toString_0;
  tree->baseTree.getType = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getType;
  tree->baseTree.getText = getText_0;
  tree->baseTree.getToken = (ANTLR3_COMMON_TOKEN_struct *(__fastcall *)(ANTLR3_BASE_TREE_struct *))SimpleXML::XMLDocument::GetFilename;
  tree->baseTree.getParent = getParent;
  tree->baseTree.setParent = setParent;
  tree->baseTree.setChildIndex = setChildIndex;
  tree->baseTree.getChildIndex = (int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getChildIndex;
  tree->baseTree.createChildrenList = createChildrenList;
  tree->baseTree.reuse = reuse;
  tree->baseTree.free = 0i64;
  tree->baseTree.u = 0i64;
  tree->baseTree.children = 0i64;
  tree->token = 0i64;
  tree->startIndex = 0i64;
  tree->stopIndex = 0i64;
  tree->parent = 0i64;
}

// File Line: 341
// RVA: 0x25AEE0
ANTLR3_COMMON_TREE_struct *__fastcall antlr3CommonTreeNew()
{
  ANTLR3_COMMON_TREE_struct *result; // rax
  ANTLR3_COMMON_TREE_struct *v1; // rbx

  result = (ANTLR3_COMMON_TREE_struct *)antlrCalloc(1u, 0x138u);
  v1 = result;
  if ( result )
  {
    antlr3SetCTAPI(result);
    return v1;
  }
  return result;
}

// File Line: 357
// RVA: 0x25AF20
ANTLR3_COMMON_TREE_struct *__fastcall antlr3CommonTreeNewFromToken(ANTLR3_COMMON_TOKEN_struct *token)
{
  ANTLR3_COMMON_TREE_struct *result; // rax
  ANTLR3_COMMON_TREE_struct *v3; // rbx

  result = (ANTLR3_COMMON_TREE_struct *)antlrCalloc(1u, 0x138u);
  v3 = result;
  if ( result )
  {
    antlr3SetCTAPI(result);
    v3->token = token;
    return v3;
  }
  return result;
}

// File Line: 378
// RVA: 0x25A9B0
void __fastcall createChildrenList(ANTLR3_BASE_TREE_struct *tree)
{
  __int64 v2; // rcx

  v2 = *(_QWORD *)(*((_QWORD *)tree->super + 6) + 328i64);
  tree->children = (ANTLR3_VECTOR_struct *)(*(__int64 (__fastcall **)(__int64))(v2 + 384))(v2);
}

// File Line: 397
// RVA: 0x25A9E0
ANTLR3_BASE_TREE_struct *__fastcall dupNode(ANTLR3_BASE_TREE_struct *tree)
{
  return (ANTLR3_BASE_TREE_struct *)(*(__int64 (__fastcall **)(_QWORD))(*((_QWORD *)tree->super + 6) + 352i64))(*((_QWORD *)tree->super + 6));
}

// File Line: 412
// RVA: 0x25ABE0
bool __fastcall isNilNode_0(ANTLR3_BASE_TREE_struct *tree)
{
  return *((_QWORD *)tree->super + 3) == 0i64;
}

// File Line: 427
// RVA: 0x25ABC0
__int64 __fastcall getType(ANTLR3_BASE_TREE_struct *tree)
{
  __int64 v1; // rdx

  v1 = *((_QWORD *)tree->super + 3);
  if ( v1 )
    return (*(__int64 (__fastcall **)(_QWORD))(v1 + 144))(*((_QWORD *)tree->super + 3));
  else
    return 0i64;
}

// File Line: 444
// RVA: 0x25ABB0
ANTLR3_STRING_struct *__fastcall getText_0(ANTLR3_BASE_TREE_struct *tree)
{
  return (ANTLR3_STRING_struct *)((__int64 (*)(void))tree->toString)();
}

// File Line: 449
// RVA: 0x25AB20
__int64 __fastcall getLine(ANTLR3_BASE_TREE_struct *tree)
{
  __int64 v2; // rbx
  __int64 (__fastcall **v4)(void *); // rax

  v2 = *((_QWORD *)tree->super + 3);
  if ( v2 && (*(unsigned int (__fastcall **)(_QWORD))(v2 + 160))(*((_QWORD *)tree->super + 3)) )
    return (*(__int64 (__fastcall **)(__int64))(v2 + 160))(v2);
  if ( !tree->getChildCount(tree) )
    return 0i64;
  v4 = (__int64 (__fastcall **)(void *))tree->getChild(tree, 0i64);
  return v4[22](v4);
}

// File Line: 472
// RVA: 0x25AA90
__int64 __fastcall getCharPositionInLine(ANTLR3_BASE_TREE_struct *tree)
{
  __int64 v2; // rbx
  __int64 (__fastcall **v4)(void *); // rax

  v2 = *((_QWORD *)tree->super + 3);
  if ( v2 && (*(unsigned int (__fastcall **)(_QWORD))(v2 + 176))(*((_QWORD *)tree->super + 3)) != -1 )
    return (*(__int64 (__fastcall **)(__int64))(v2 + 176))(v2);
  if ( !tree->getChildCount(tree) )
    return 0i64;
  v4 = (__int64 (__fastcall **)(void *))tree->getChild(tree, 0i64);
  return v4[13](v4);
}

// File Line: 493
// RVA: 0x25ADA0
ANTLR3_STRING_struct *__fastcall toString_0(ANTLR3_BASE_TREE_struct *tree)
{
  if ( ((unsigned __int8 (*)(void))tree->isNilNode)() == 1 )
    return tree->strFactory->newPtr(tree->strFactory, "nil", 3i64);
  else
    return (ANTLR3_STRING_struct *)(*(__int64 (__fastcall **)(_QWORD))(*((_QWORD *)tree->super + 3) + 120i64))(*((_QWORD *)tree->super + 3));
}

// File Line: 508
// RVA: 0x25ABA0
ANTLR3_BASE_TREE_struct *__fastcall getParent(ANTLR3_BASE_TREE_struct *tree)
{
  return (ANTLR3_BASE_TREE_struct *)(*((_QWORD *)tree->super + 4) + 56i64);
}

// File Line: 514
// RVA: 0x25AD80
void __fastcall setParent(ANTLR3_BASE_TREE_struct *tree, ANTLR3_BASE_TREE_struct *parent)
{
  if ( parent )
    *((_QWORD *)tree->super + 4) = *((_QWORD *)parent->super + 4);
  else
    *((_QWORD *)tree->super + 4) = 0i64;
}

// File Line: 520
// RVA: 0x25AD70
void __fastcall setChildIndex(ANTLR3_BASE_TREE_struct *tree, int i)
{
  *((_DWORD *)tree->super + 10) = i;
}

// File Line: 525
// RVA: 0x25AB10
__int64 __fastcall getChildIndex(ANTLR3_BASE_TREE_struct *tree)
{
  return *((unsigned int *)tree->super + 10);
}

// File Line: 534
// RVA: 0x25AD20
void __fastcall reuse(ANTLR3_BASE_TREE_struct *tree)
{
  _QWORD *super; // rbx
  __int64 v3; // rax

  super = tree->super;
  if ( *((_QWORD *)tree->super + 6) )
  {
    v3 = super[9];
    if ( v3 )
      (*(void (__fastcall **)(_QWORD))(v3 + 312))(super[9]);
    (*(void (__fastcall **)(_QWORD, ANTLR3_BASE_TREE_struct *, _QWORD))(*(_QWORD *)(super[6] + 336i64) + 40i64))(
      *(_QWORD *)(super[6] + 336i64),
      tree,
      0i64);
  }
}

