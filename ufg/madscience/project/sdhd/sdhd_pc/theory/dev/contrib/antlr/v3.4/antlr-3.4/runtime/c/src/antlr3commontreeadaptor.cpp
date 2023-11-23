// File Line: 84
// RVA: 0x25B570
UFG::allocator::free_link *__fastcall ANTLR3_TREE_ADAPTORNew(UFG::allocator::free_link *strFactory)
{
  UFG::allocator::free_link *result; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v3; // rdi
  ANTLR3_TOKEN_FACTORY_struct *v4; // rax

  result = antlrMalloc(0x168ui64);
  v3 = (ANTLR3_BASE_TREE_ADAPTOR_struct *)result;
  if ( result )
  {
    antlr3BaseTreeAdaptorInit((ANTLR3_BASE_TREE_ADAPTOR_struct *)&result[1], 0i64);
    v3->getType = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))dupNode_0;
    v3->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3;
    v3->createTypeToken = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, unsigned int, ANTLR3_COMMON_TOKEN_struct *))create;
    v3->createTokenFromToken = (ANTLR3_COMMON_TOKEN_struct *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_COMMON_TOKEN_struct *))createToken;
    v3->getToken = (ANTLR3_COMMON_TOKEN_struct *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))createTokenFromToken;
    v3->getTokenStartIndex = (__int64 (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))setTokenBoundaries;
    v3->getTokenStopIndex = (__int64 (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))getTokenStartIndex;
    v3->setDebugEventListener = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_DEBUG_EVENT_LISTENER_struct *))getTokenStopIndex;
    v3->setText = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_STRING_struct *))getText_1;
    v3->setType = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, unsigned int))getType_0;
    v3->setChild = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, unsigned int, void *))getChild_0;
    v3->deleteChild = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, unsigned int))setChild_0;
    v3->getParent = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))setParent_0;
    v3->errorNode = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_TOKEN_STREAM_struct *, ANTLR3_COMMON_TOKEN_struct *, ANTLR3_COMMON_TOKEN_struct *, ANTLR3_EXCEPTION_struct *))getParent_0;
    v3->getChildIndex = (int (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))setChildIndex_0;
    v3->setChildIndex = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, unsigned int))deleteChild_0;
    v3->getUniqueID = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))getChildCount_0;
    v3->getChildCount = (unsigned int (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))getChildIndex_0;
    v3[1].super = ctaFree;
    v3->makeDot = (ANTLR3_STRING_struct *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))setDebugEventListener;
    v3->free = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *))replaceChildren_0;
    v3->isNilNode = (char (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *))errorNode;
    v3[1].strFactory = (ANTLR3_STRING_FACTORY_struct *)antlr3ArboretumNew(strFactory);
    v4 = antlr3TokenFactoryNew(0i64);
    v3->debugger = (ANTLR3_DEBUG_EVENT_LISTENER_struct *)v4;
    v4->unTruc.strFactory = (ANTLR3_STRING_FACTORY_struct *)strFactory;
    v3->tokenFactory = (ANTLR3_TOKEN_FACTORY_struct *)strFactory;
    return (UFG::allocator::free_link *)&v3->strFactory;
  }
  return result;
}

// File Line: 177
// RVA: 0x25B520
ANTLR3_BASE_TREE_ADAPTOR_struct *__fastcall ANTLR3_TREE_ADAPTORDebugNew(
        ANTLR3_STRING_FACTORY_struct *strFactory,
        ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *result; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v4; // rbx

  result = ANTLR3_TREE_ADAPTORNew(strFactory);
  v4 = result;
  if ( result )
  {
    antlr3BaseTreeAdaptorInit(result, debugger);
    v4->create = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_COMMON_TOKEN_struct *))dbgCreate;
    v4->setTokenBoundaries = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, ANTLR3_COMMON_TOKEN_struct *, ANTLR3_COMMON_TOKEN_struct *))dbgSetTokenBoundaries;
    return v4;
  }
  return result;
}

// File Line: 202
// RVA: 0x25B470
void __fastcall setDebugEventListener(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
{
  antlr3BaseTreeAdaptorInit(adaptor, debugger);
  adaptor->create = (void *(__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, ANTLR3_COMMON_TOKEN_struct *))dbgCreate;
  adaptor->setTokenBoundaries = (void (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, void *, ANTLR3_COMMON_TOKEN_struct *, ANTLR3_COMMON_TOKEN_struct *))dbgSetTokenBoundaries;
}

// File Line: 216
// RVA: 0x25B210
void __fastcall ctaFree(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor)
{
  (*(void (__fastcall **)(_QWORD))(*((_QWORD *)adaptor->super + 44) + 368i64))(*((_QWORD *)adaptor->super + 44));
  adaptor->tokenFactory->close(adaptor->tokenFactory);
  antlrFree((char *)adaptor->super);
}

// File Line: 239
// RVA: 0x25B380
ANTLR3_BASE_TREE_struct *__fastcall errorNode(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_TOKEN_STREAM_struct *ctnstream,
        ANTLR3_COMMON_TOKEN_struct *startToken,
        ANTLR3_COMMON_TOKEN_struct *stopToken,
        ANTLR3_EXCEPTION_struct *e)
{
  return (ANTLR3_BASE_TREE_struct *)((__int64 (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *, _QWORD, const char *, ANTLR3_COMMON_TOKEN_struct *))adaptor->createTypeText)(
                                      adaptor,
                                      0i64,
                                      "Tree Error Node",
                                      stopToken);
}

// File Line: 253
// RVA: 0x25B370
ANTLR3_BASE_TREE_struct *__fastcall dupNode_0(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *treeNode)
{
  if ( treeNode )
    return (ANTLR3_BASE_TREE_struct *)treeNode->dupNode(treeNode);
  else
    return 0i64;
}

// File Line: 259
// RVA: 0x25B080
ANTLR3_BASE_TREE_struct *__fastcall create(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_COMMON_TOKEN_struct *payload)
{
  return (ANTLR3_BASE_TREE_struct *)(*(__int64 (__fastcall **)(_QWORD, ANTLR3_COMMON_TOKEN_struct *))(*((_QWORD *)adaptor->super + 44) + 360i64))(
                                      *((_QWORD *)adaptor->super + 44),
                                      payload);
}

// File Line: 272
// RVA: 0x25B250
ANTLR3_BASE_TREE_struct *__fastcall dbgCreate(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_COMMON_TOKEN_struct *payload)
{
  ANTLR3_BASE_TREE_struct *v3; // rbx

  v3 = (ANTLR3_BASE_TREE_struct *)(*(__int64 (__fastcall **)(_QWORD, ANTLR3_COMMON_TOKEN_struct *))(*((_QWORD *)adaptor->super + 44)
                                                                                                  + 360i64))(
                                    *((_QWORD *)adaptor->super + 44),
                                    payload);
  adaptor->debugger->createNode(adaptor->debugger, v3);
  return v3;
}

// File Line: 291
// RVA: 0x25B0A0
ANTLR3_COMMON_TOKEN_struct *__fastcall createToken(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        unsigned int tokenType,
        char *text)
{
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  ANTLR3_COMMON_TOKEN_struct *v7; // rbx

  result = adaptor->tokenFactory->newToken(adaptor->tokenFactory);
  v7 = result;
  if ( result )
  {
    result->textState = 1;
    result->tokText.chars = (unsigned int *)text;
    result->setType(result, tokenType);
    result = v7;
    v7->input = adaptor->tokenFactory->input;
    v7->strFactory = adaptor->strFactory;
  }
  return result;
}

// File Line: 327
// RVA: 0x25B120
ANTLR3_COMMON_TOKEN_struct *__fastcall createTokenFromToken(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_COMMON_TOKEN_struct *fromToken)
{
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  ANTLR3_COMMON_TOKEN_struct *v5; // rbx
  ANTLR3_STRING_struct *v6; // rax
  unsigned int v7; // eax
  __int64 v8; // rax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax

  result = adaptor->tokenFactory->newToken(adaptor->tokenFactory);
  v5 = result;
  if ( result )
  {
    result->toString = fromToken->toString;
    if ( fromToken->textState == 1 )
    {
      result->textState = 1;
      result->tokText.chars = fromToken->tokText.chars;
    }
    else
    {
      v6 = fromToken->getText(fromToken);
      v5->textState = 2;
      v5->tokText.chars = (unsigned int *)adaptor->strFactory->newPtr(adaptor->strFactory, v6->chars, v6->len);
    }
    v7 = fromToken->getLine(fromToken);
    v5->setLine(v5, v7);
    v8 = fromToken->getTokenIndex(fromToken);
    v5->setTokenIndex(v5, v8);
    v9 = fromToken->getCharPositionInLine(fromToken);
    v5->setCharPositionInLine(v5, v9);
    v10 = fromToken->getChannel(fromToken);
    v5->setChannel(v5, v10);
    v11 = fromToken->getType(fromToken);
    v5->setType(v5, v11);
    return v5;
  }
  return result;
}

// File Line: 372
// RVA: 0x25B4B0
void __fastcall setTokenBoundaries(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        ANTLR3_COMMON_TOKEN_struct *startToken,
        ANTLR3_COMMON_TOKEN_struct *stopToken)
{
  __int64 v4; // rbx
  __int64 v7; // rsi
  _QWORD *super; // rax

  if ( t )
  {
    v4 = 0i64;
    if ( startToken )
      v7 = startToken->getTokenIndex(startToken);
    else
      v7 = 0i64;
    if ( stopToken )
      v4 = stopToken->getTokenIndex(stopToken);
    super = t->super;
    super[1] = v7;
    super[2] = v4;
  }
}

// File Line: 409
// RVA: 0x25B2A0
void __fastcall dbgSetTokenBoundaries(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        ANTLR3_COMMON_TOKEN_struct *startToken,
        ANTLR3_COMMON_TOKEN_struct *stopToken)
{
  __int64 v4; // rdi
  __int64 v9; // rbp
  _QWORD *super; // rax
  ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger; // rdi
  __int64 v12; // rbx
  __int64 v13; // rax

  if ( t )
  {
    v4 = 0i64;
    if ( startToken )
      v9 = startToken->getTokenIndex(startToken);
    else
      v9 = 0i64;
    if ( stopToken )
      v4 = stopToken->getTokenIndex(stopToken);
    super = t->super;
    super[1] = v9;
    super[2] = v4;
    if ( startToken )
    {
      if ( stopToken )
      {
        debugger = adaptor->debugger;
        v12 = stopToken->getTokenIndex(stopToken);
        v13 = startToken->getTokenIndex(startToken);
        debugger->setTokenBoundaries(adaptor->debugger, t, v13, v12);
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
  return t->getText(t);
}

// File Line: 438
// RVA: 0x25B400
__int64 __fastcall getType_0(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_TREE_struct *t)
{
  return ((__int64 (__fastcall *)(ANTLR3_BASE_TREE_struct *))t->getType)(t);
}

// File Line: 445
// RVA: 0x25B410
void __fastcall replaceChildren_0(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *parent,
        int startChildIndex,
        int stopChildIndex,
        ANTLR3_BASE_TREE_struct *t)
{
  if ( parent )
    parent->replaceChildren(parent, startChildIndex, stopChildIndex, t);
}

// File Line: 454
// RVA: 0x25B390
ANTLR3_BASE_TREE_struct *__fastcall getChild_0(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        unsigned int i)
{
  return (ANTLR3_BASE_TREE_struct *)t->getChild(t, i);
}

// File Line: 459
// RVA: 0x25B440
void __fastcall setChild_0(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *t,
        unsigned int i,
        ANTLR3_BASE_TREE_struct *child)
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
  return ((__int64 (__fastcall *)(ANTLR3_BASE_TREE_struct *))t->getChildCount)(t);
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
  return ((__int64 (__fastcall *)(ANTLR3_BASE_TREE_struct *))t->getChildIndex)(t);
}

// File Line: 488
// RVA: 0x25B4A0
void __fastcall setParent_0(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *child,
        ANTLR3_BASE_TREE_struct *parent)
{
  child->setParent(child, parent);
}

// File Line: 493
// RVA: 0x25B3C0
ANTLR3_BASE_TREE_struct *__fastcall getParent_0(
        ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor,
        ANTLR3_BASE_TREE_struct *child)
{
  return child->getParent(child);
}

