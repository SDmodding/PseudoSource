// File Line: 84
// RVA: 0x25B570
UFG::allocator::free_link *__fastcall ANTLR3_TREE_ADAPTORNew(ANTLR3_STRING_FACTORY_struct *strFactory)
{
  ANTLR3_STRING_FACTORY_struct *v1; // rsi
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v3; // rdi
  ANTLR3_TOKEN_FACTORY_struct *v4; // rax

  v1 = strFactory;
  result = antlrMalloc(0x168ui64);
  v3 = result;
  if ( result )
  {
    antlr3BaseTreeAdaptorInit((ANTLR3_BASE_TREE_ADAPTOR_struct *)&result[1], 0i64);
    v3[21].mNext = (UFG::allocator::free_link *)dupNode_0;
    v3[1].mNext = v3;
    v3[17].mNext = (UFG::allocator::free_link *)create;
    v3[34].mNext = (UFG::allocator::free_link *)createToken;
    v3[35].mNext = (UFG::allocator::free_link *)createTokenFromToken;
    v3[37].mNext = (UFG::allocator::free_link *)setTokenBoundaries;
    v3[38].mNext = (UFG::allocator::free_link *)getTokenStartIndex;
    v3[39].mNext = (UFG::allocator::free_link *)getTokenStopIndex;
    v3[24].mNext = (UFG::allocator::free_link *)getText_1;
    v3[22].mNext = (UFG::allocator::free_link *)getType_0;
    v3[27].mNext = (UFG::allocator::free_link *)getChild_0;
    v3[28].mNext = (UFG::allocator::free_link *)setChild_0;
    v3[10].mNext = (UFG::allocator::free_link *)setParent_0;
    v3[11].mNext = (UFG::allocator::free_link *)getParent_0;
    v3[30].mNext = (UFG::allocator::free_link *)setChildIndex_0;
    v3[29].mNext = (UFG::allocator::free_link *)deleteChild_0;
    v3[32].mNext = (UFG::allocator::free_link *)getChildCount_0;
    v3[31].mNext = (UFG::allocator::free_link *)getChildIndex_0;
    v3[43].mNext = (UFG::allocator::free_link *)ctaFree;
    v3[40].mNext = (UFG::allocator::free_link *)setDebugEventListener;
    v3[42].mNext = (UFG::allocator::free_link *)replaceChildren_0;
    v3[12].mNext = (UFG::allocator::free_link *)errorNode;
    v3[44].mNext = antlr3ArboretumNew(v1);
    v4 = antlr3TokenFactoryNew(0i64);
    v3[3].mNext = (UFG::allocator::free_link *)v4;
    v4->unTruc.strFactory = v1;
    v3[2].mNext = (UFG::allocator::free_link *)v1;
    result = v3 + 1;
  }
  return result;
}

// File Line: 177
// RVA: 0x25B520
ANTLR3_BASE_TREE_ADAPTOR_struct *__fastcall ANTLR3_TREE_ADAPTORDebugNew(ANTLR3_STRING_FACTORY_struct *strFactory, ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v2; // rdi
  ANTLR3_BASE_TREE_ADAPTOR_struct *result; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v4; // rbx

  v2 = debugger;
  result = ANTLR3_TREE_ADAPTORNew(strFactory);
  v4 = result;
  if ( result )
  {
    antlr3BaseTreeAdaptorInit(result, v2);
    v4->create = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_COMMON_TOKEN_struct *))dbgCreate;
    v4->setTokenBoundaries = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, ANTLR3_COMMON_TOKEN_struct *, ANTLR3_COMMON_TOKEN_struct *))dbgSetTokenBoundaries;
    result = v4;
  }
  return result;
}

// File Line: 202
// RVA: 0x25B470
void __fastcall setDebugEventListener(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v2; // rbx

  v2 = adaptor;
  antlr3BaseTreeAdaptorInit(adaptor, debugger);
  v2->create = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_COMMON_TOKEN_struct *))dbgCreate;
  v2->setTokenBoundaries = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, ANTLR3_COMMON_TOKEN_struct *, ANTLR3_COMMON_TOKEN_struct *))dbgSetTokenBoundaries;
}

// File Line: 216
// RVA: 0x25B210
void __fastcall ctaFree(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v1; // rbx

  v1 = adaptor;
  (*(void (__fastcall **)(_QWORD))(*((_QWORD *)adaptor->super + 44) + 368i64))(*((_QWORD *)adaptor->super + 44));
  v1->tokenFactory->close(v1->tokenFactory);
  antlrFree(v1->super);
}

// File Line: 239
// RVA: 0x25B380
ANTLR3_BASE_TREE_struct *__fastcall errorNode(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_TOKEN_STREAM_struct *ctnstream, ANTLR3_COMMON_TOKEN_struct *startToken, ANTLR3_COMMON_TOKEN_struct *stopToken, ANTLR3_EXCEPTION_struct *e)
{
  return (ANTLR3_BASE_TREE_struct *)((__int64 (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, _QWORD, const char *, ANTLR3_COMMON_TOKEN_struct *))adaptor->createTypeText)(
                                      adaptor,
                                      0i64,
                                      "Tree Error Node",
                                      stopToken);
}

// File Line: 253
// RVA: 0x25B370
ANTLR3_BASE_TREE_struct *__fastcall dupNode_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *treeNode)
{
  ANTLR3_BASE_TREE_struct *result; // rax

  if ( treeNode )
    result = (ANTLR3_BASE_TREE_struct *)treeNode->dupNode(treeNode);
  else
    result = 0i64;
  return result;
}

// File Line: 259
// RVA: 0x25B080
ANTLR3_BASE_TREE_struct *__fastcall create(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_COMMON_TOKEN_struct *payload)
{
  return (ANTLR3_BASE_TREE_struct *)(*(__int64 (__fastcall **)(_QWORD, ANTLR3_COMMON_TOKEN_struct *))(*((_QWORD *)adaptor->super + 44) + 360i64))(
                                      *((_QWORD *)adaptor->super + 44),
                                      payload);
}

// File Line: 272
// RVA: 0x25B250
ANTLR3_BASE_TREE_struct *__fastcall dbgCreate(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_COMMON_TOKEN_struct *payload)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v2; // rdi
  __int64 v3; // rbx

  v2 = adaptor;
  v3 = (*(__int64 (__fastcall **)(_QWORD, ANTLR3_COMMON_TOKEN_struct *))(*((_QWORD *)adaptor->super + 44) + 360i64))(
         *((_QWORD *)adaptor->super + 44),
         payload);
  v2->debugger->createNode(v2->debugger, (ANTLR3_BASE_TREE_struct *)v3);
  return (ANTLR3_BASE_TREE_struct *)v3;
}

// File Line: 291
// RVA: 0x25B0A0
ANTLR3_COMMON_TOKEN_struct *__fastcall createToken(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, unsigned int tokenType, char *text)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v3; // rdi
  unsigned int *v4; // rsi
  unsigned int v5; // ebp
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  ANTLR3_COMMON_TOKEN_struct *v7; // rbx

  v3 = adaptor;
  v4 = (unsigned int *)text;
  v5 = tokenType;
  result = adaptor->tokenFactory->newToken(adaptor->tokenFactory);
  v7 = result;
  if ( result )
  {
    result->textState = 1;
    result->tokText.chars = v4;
    result->setType(result, v5);
    result = v7;
    v7->input = v3->tokenFactory->input;
    v7->strFactory = v3->strFactory;
  }
  return result;
}

// File Line: 327
// RVA: 0x25B120
ANTLR3_COMMON_TOKEN_struct *__fastcall createTokenFromToken(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_COMMON_TOKEN_struct *fromToken)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v2; // rsi
  ANTLR3_COMMON_TOKEN_struct *v3; // rdi
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  ANTLR3_COMMON_TOKEN_struct *v5; // rbx
  __int64 v6; // rax
  unsigned int v7; // eax
  __int64 v8; // rax
  int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax

  v2 = adaptor;
  v3 = fromToken;
  result = adaptor->tokenFactory->newToken(adaptor->tokenFactory);
  v5 = result;
  if ( result )
  {
    result->toString = v3->toString;
    if ( v3->textState == 1 )
    {
      result->textState = 1;
      result->tokText.chars = v3->tokText.chars;
    }
    else
    {
      v6 = (__int64)v3->getText(v3);
      v5->textState = 2;
      v5->tokText.chars = (unsigned int *)v2->strFactory->newPtr(
                                            v2->strFactory,
                                            *(char **)(v6 + 8),
                                            *(unsigned int *)(v6 + 16));
    }
    v7 = v3->getLine(v3);
    v5->setLine(v5, v7);
    v8 = v3->getTokenIndex(v3);
    v5->setTokenIndex(v5, v8);
    v9 = v3->getCharPositionInLine(v3);
    v5->setCharPositionInLine(v5, v9);
    v10 = v3->getChannel(v3);
    v5->setChannel(v5, v10);
    v11 = v3->getType(v3);
    v5->setType(v5, v11);
    result = v5;
  }
  return result;
}

// File Line: 372
// RVA: 0x25B4B0
void __fastcall setTokenBoundaries(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, ANTLR3_COMMON_TOKEN_struct *startToken, ANTLR3_COMMON_TOKEN_struct *stopToken)
{
  __int64 v4; // rbx
  ANTLR3_COMMON_TOKEN_struct *v5; // rdi
  ANTLR3_BASE_TREE_struct *v6; // r14
  __int64 v7; // rsi
  _QWORD *v8; // rax

  if ( t )
  {
    v4 = 0i64;
    v5 = stopToken;
    v6 = t;
    if ( startToken )
      v7 = startToken->getTokenIndex(startToken);
    else
      v7 = 0i64;
    if ( v5 )
      v4 = v5->getTokenIndex(v5);
    v8 = v6->super;
    v8[1] = v7;
    v8[2] = v4;
  }
}

// File Line: 409
// RVA: 0x25B2A0
void __fastcall dbgSetTokenBoundaries(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, ANTLR3_COMMON_TOKEN_struct *startToken, ANTLR3_COMMON_TOKEN_struct *stopToken)
{
  __int64 v4; // rdi
  ANTLR3_COMMON_TOKEN_struct *v5; // rbx
  ANTLR3_COMMON_TOKEN_struct *v6; // rsi
  ANTLR3_BASE_TREE_struct *v7; // r14
  ANTLR3_BASE_TREE_ADAPTOR_struct *v8; // r15
  __int64 v9; // rbp
  _QWORD *v10; // rax
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v11; // rdi
  __int64 v12; // rbx
  __int64 v13; // rax

  if ( t )
  {
    v4 = 0i64;
    v5 = stopToken;
    v6 = startToken;
    v7 = t;
    v8 = adaptor;
    if ( startToken )
      v9 = startToken->getTokenIndex(startToken);
    else
      v9 = 0i64;
    if ( v5 )
      v4 = v5->getTokenIndex(v5);
    v10 = v7->super;
    v10[1] = v9;
    v10[2] = v4;
    if ( v6 )
    {
      if ( v5 )
      {
        v11 = v8->debugger;
        v12 = v5->getTokenIndex(v5);
        v13 = v6->getTokenIndex(v6);
        v11->setTokenBoundaries(v8->debugger, v7, v13, v12);
      }
    }
  }
}

// File Line: 420
// RVA: 0x25B3E0
__int64 __fastcall getTokenStartIndex(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return *((_QWORD *)t->super + 1);
}

// File Line: 426
// RVA: 0x25B3F0
__int64 __fastcall getTokenStopIndex(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return *((_QWORD *)t->super + 2);
}

// File Line: 432
// RVA: 0x25B3D0
ANTLR3_STRING_struct *__fastcall getText_1(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return (ANTLR3_STRING_struct *)t->getText(t);
}

// File Line: 438
// RVA: 0x25B400
__int64 __fastcall getType_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return t->getType(t);
}

// File Line: 445
// RVA: 0x25B410
void __fastcall replaceChildren_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *parent, int startChildIndex, int stopChildIndex, ANTLR3_BASE_TREE_struct *t)
{
  if ( parent )
    parent->replaceChildren(parent, startChildIndex, stopChildIndex, t);
}

// File Line: 454
// RVA: 0x25B390
ANTLR3_BASE_TREE_struct *__fastcall getChild_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, unsigned int i)
{
  return (ANTLR3_BASE_TREE_struct *)t->getChild(t, i);
}

// File Line: 459
// RVA: 0x25B440
void __fastcall setChild_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, unsigned int i, ANTLR3_BASE_TREE_struct *child)
{
  t->setChild(t, i, child);
}

// File Line: 465
// RVA: 0x25B360
void __fastcall deleteChild_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, unsigned int i)
{
  t->deleteChild(t, i);
}

// File Line: 471
// RVA: 0x25B3A0
__int64 __fastcall getChildCount_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return t->getChildCount(t);
}

// File Line: 477
// RVA: 0x25B460
void __fastcall setChildIndex_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t, int i)
{
  t->setChildIndex(t, i);
}

// File Line: 483
// RVA: 0x25B3B0
__int64 __fastcall getChildIndex_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return t->getChildIndex(t);
}

// File Line: 488
// RVA: 0x25B4A0
void __fastcall setParent_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *child, ANTLR3_BASE_TREE_struct *parent)
{
  child->setParent(child, parent);
}

// File Line: 493
// RVA: 0x25B3C0
ANTLR3_BASE_TREE_struct *__fastcall getParent_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *child)
{
  return (ANTLR3_BASE_TREE_struct *)child->getParent(child);
}

