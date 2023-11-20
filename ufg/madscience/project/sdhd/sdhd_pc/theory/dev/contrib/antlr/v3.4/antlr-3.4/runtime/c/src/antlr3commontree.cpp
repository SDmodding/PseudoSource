// File Line: 69
// RVA: 0x25ADF0
UFG::allocator::free_link *__fastcall antlr3ArboretumNew(ANTLR3_STRING_FACTORY_struct *strFactory)
{
  ANTLR3_STRING_FACTORY_struct *v1; // rdi
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax

  v1 = strFactory;
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
  v2[42].mNext = antlr3StackNew(0);
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
  v2[13].mNext = (UFG::allocator::free_link *)v1;
  return v2;
}

// File Line: 158
// RVA: 0x25AC60
ANTLR3_BASE_TREE_struct *__fastcall newPoolTree(ANTLR3_ARBORETUM_struct *factory)
{
  ANTLR3_ARBORETUM_struct *v1; // rdi
  ANTLR3_BASE_TREE_struct *v2; // rbx
  ANTLR3_BASE_TREE_struct *result; // rax
  signed __int64 v4; // rbx
  ANTLR3_COMMON_TREE_struct *v5; // rcx

  v1 = factory;
  v2 = (ANTLR3_BASE_TREE_struct *)factory->nilStack->peek(factory->nilStack);
  if ( v2 )
  {
    v1->nilStack->pop(v1->nilStack);
    result = v2;
  }
  else
  {
    if ( v1->nextTree >= 0x400 )
    {
      v1->pools = (ANTLR3_COMMON_TREE_struct **)antlrRealloc(v1->pools, (unsigned int)(8 * ++v1->thisPool + 8));
      v1->pools[v1->thisPool] = (ANTLR3_COMMON_TREE_struct *)antlrMalloc(0x4E000ui64);
      v1->nextTree = 0;
    }
    v4 = (signed __int64)&v1->pools[v1->thisPool][v1->nextTree];
    v5 = &v1->pools[v1->thisPool][v1->nextTree++];
    antlr3SetCTAPI(v5);
    *(_QWORD *)(v4 + 48) = v1;
    *(_QWORD *)(v4 + 88) = v1->unTruc.baseTree.strFactory;
    result = (ANTLR3_BASE_TREE_struct *)(v4 + 56);
    *(_QWORD *)(v4 + 56) = v4;
  }
  return result;
}

// File Line: 217
// RVA: 0x25AC20
ANTLR3_BASE_TREE_struct *__fastcall newFromTree(ANTLR3_ARBORETUM_struct *factory, ANTLR3_COMMON_TREE_struct *tree)
{
  ANTLR3_COMMON_TREE_struct *v2; // rbx
  ANTLR3_BASE_TREE_struct *result; // rax

  v2 = tree;
  result = (ANTLR3_BASE_TREE_struct *)((__int64 (*)(void))factory->newTree)();
  if ( result )
  {
    *((_QWORD *)result->super + 3) = v2->token;
    result->u = v2->baseTree.u;
  }
  return result;
}

// File Line: 237
// RVA: 0x25ABF0
ANTLR3_BASE_TREE_struct *__fastcall newFromToken(ANTLR3_ARBORETUM_struct *factory, ANTLR3_COMMON_TOKEN_struct *token)
{
  ANTLR3_COMMON_TOKEN_struct *v2; // rbx
  ANTLR3_BASE_TREE_struct *result; // rax

  v2 = token;
  result = (ANTLR3_BASE_TREE_struct *)((__int64 (*)(void))factory->newTree)();
  if ( result )
    *((_QWORD *)result->super + 3) = v2;
  return result;
}

// File Line: 256
// RVA: 0x25AA00
void __fastcall factoryClose_0(ANTLR3_ARBORETUM_struct *factory)
{
  ANTLR3_ARBORETUM_struct *v1; // rbx
  ANTLR3_STACK_struct *v2; // rax
  int v3; // esi
  __int64 v4; // rdi

  v1 = factory;
  factory->vFactory->close(factory->vFactory);
  v2 = v1->nilStack;
  if ( v2 )
    v2->free(v1->nilStack);
  v3 = 0;
  if ( v1->thisPool >= 0 )
  {
    v4 = 0i64;
    do
    {
      antlrFree(v1->pools[v4]);
      ++v3;
      v1->pools[v4] = 0i64;
      ++v4;
    }
    while ( v3 <= v1->thisPool );
  }
  antlrFree(v1->pools);
  antlrFree(v1);
}

// File Line: 293
// RVA: 0x25AF70
void __fastcall antlr3SetCTAPI(ANTLR3_COMMON_TREE_struct *tree)
{
  ANTLR3_COMMON_TREE_struct *v1; // rdi

  v1 = tree;
  antlr3BaseTreeNew(&tree->baseTree);
  v1->baseTree.isNilNode = (char (__fastcall *)(ANTLR3_BASE_TREE_struct *))isNilNode_0;
  v1->baseTree.super = v1;
  v1->baseTree.dupNode = (void *(__fastcall *)(ANTLR3_BASE_TREE_struct *))dupNode;
  v1->childIndex = -1;
  v1->baseTree.getLine = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getLine;
  v1->baseTree.getCharPositionInLine = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getCharPositionInLine;
  v1->baseTree.toString = toString_0;
  v1->baseTree.getType = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getType;
  v1->baseTree.getText = getText_0;
  v1->baseTree.getToken = (ANTLR3_COMMON_TOKEN_struct *(__fastcall *)(ANTLR3_BASE_TREE_struct *))SimpleXML::XMLDocument::GetFilename;
  v1->baseTree.getParent = getParent;
  v1->baseTree.setParent = setParent;
  v1->baseTree.setChildIndex = setChildIndex;
  v1->baseTree.getChildIndex = (int (__fastcall *)(ANTLR3_BASE_TREE_struct *))getChildIndex;
  v1->baseTree.createChildrenList = createChildrenList;
  v1->baseTree.reuse = reuse;
  v1->baseTree.free = 0i64;
  v1->baseTree.u = 0i64;
  v1->baseTree.children = 0i64;
  v1->token = 0i64;
  v1->startIndex = 0i64;
  v1->stopIndex = 0i64;
  v1->parent = 0i64;
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
    result = v1;
  }
  return result;
}

// File Line: 357
// RVA: 0x25AF20
ANTLR3_COMMON_TREE_struct *__fastcall antlr3CommonTreeNewFromToken(ANTLR3_COMMON_TOKEN_struct *token)
{
  ANTLR3_COMMON_TOKEN_struct *v1; // rdi
  ANTLR3_COMMON_TREE_struct *result; // rax
  ANTLR3_COMMON_TREE_struct *v3; // rbx

  v1 = token;
  result = (ANTLR3_COMMON_TREE_struct *)antlrCalloc(1u, 0x138u);
  v3 = result;
  if ( result )
  {
    antlr3SetCTAPI(result);
    v3->token = v1;
    result = v3;
  }
  return result;
}

// File Line: 378
// RVA: 0x25A9B0
void __fastcall createChildrenList(ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_BASE_TREE_struct *v1; // rbx
  __int64 v2; // rcx

  v1 = tree;
  v2 = *(_QWORD *)(*((_QWORD *)tree->super + 6) + 328i64);
  v1->children = (ANTLR3_VECTOR_struct *)(*(__int64 (__fastcall **)(__int64))(v2 + 384))(v2);
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
  __int64 result; // rax

  v1 = *((_QWORD *)tree->super + 3);
  if ( v1 )
    result = (*(__int64 (__fastcall **)(_QWORD))(v1 + 144))(*((_QWORD *)tree->super + 3));
  else
    result = 0i64;
  return result;
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
  ANTLR3_BASE_TREE_struct *v1; // rdi
  __int64 v2; // rbx
  __int64 v4; // rax

  v1 = tree;
  v2 = *((_QWORD *)tree->super + 3);
  if ( v2 && (*(unsigned int (__fastcall **)(_QWORD))(v2 + 160))(*((_QWORD *)tree->super + 3)) )
    return (*(__int64 (__fastcall **)(__int64))(v2 + 160))(v2);
  if ( !v1->getChildCount(v1) )
    return 0i64;
  v4 = (__int64)v1->getChild(v1, 0);
  return (*(__int64 (__fastcall **)(__int64))(v4 + 176))(v4);
}

// File Line: 472
// RVA: 0x25AA90
__int64 __fastcall getCharPositionInLine(ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_BASE_TREE_struct *v1; // rdi
  __int64 v2; // rbx
  __int64 v4; // rax

  v1 = tree;
  v2 = *((_QWORD *)tree->super + 3);
  if ( v2 && (*(unsigned int (__fastcall **)(_QWORD))(v2 + 176))(*((_QWORD *)tree->super + 3)) != -1 )
    return (*(__int64 (__fastcall **)(__int64))(v2 + 176))(v2);
  if ( !v1->getChildCount(v1) )
    return 0i64;
  v4 = (__int64)v1->getChild(v1, 0);
  return (*(__int64 (__fastcall **)(__int64))(v4 + 104))(v4);
}

// File Line: 493
// RVA: 0x25ADA0
ANTLR3_STRING_struct *__fastcall toString_0(ANTLR3_BASE_TREE_struct *tree)
{
  ANTLR3_BASE_TREE_struct *v1; // rbx
  ANTLR3_STRING_struct *result; // rax

  v1 = tree;
  if ( ((unsigned __int8 (*)(void))tree->isNilNode)() == 1 )
    result = v1->strFactory->newPtr(v1->strFactory, "nil", 3u);
  else
    result = (ANTLR3_STRING_struct *)(*(__int64 (__fastcall **)(_QWORD))(*((_QWORD *)v1->super + 3) + 120i64))(*((_QWORD *)v1->super + 3));
  return result;
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
  _QWORD *v1; // rbx
  ANTLR3_BASE_TREE_struct *v2; // rdi
  __int64 v3; // rax

  v1 = tree->super;
  v2 = tree;
  if ( *((_QWORD *)tree->super + 6) )
  {
    v3 = v1[9];
    if ( v3 )
      (*(void (__fastcall **)(_QWORD))(v3 + 312))(v1[9]);
    (*(void (__fastcall **)(_QWORD, ANTLR3_BASE_TREE_struct *, _QWORD))(*(_QWORD *)(v1[6] + 336i64) + 40i64))(
      *(_QWORD *)(v1[6] + 336i64),
      v2,
      0i64);
  }
}

