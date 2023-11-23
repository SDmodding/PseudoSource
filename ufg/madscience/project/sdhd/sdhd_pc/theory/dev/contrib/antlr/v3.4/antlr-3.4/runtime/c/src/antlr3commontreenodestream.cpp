// File Line: 88
// RVA: 0x25C6C0
UFG::allocator::free_link *__fastcall antlr3TreeNodeStreamNew()
{
  UFG::allocator::free_link *result; // rax

  result = antlrCalloc(1u, 0x60u);
  if ( result )
  {
    result[11].mNext = (UFG::allocator::free_link *)replaceChildren_1;
    result[9].mNext = (UFG::allocator::free_link *)antlr3EnumFree;
  }
  return result;
}

// File Line: 116
// RVA: 0x25C690
UFG::allocator::free_link *__fastcall antlr3CommonTreeNodeStreamNewTree(
        UFG::allocator::free_link *tree,
        unsigned int hint)
{
  UFG::allocator::free_link *result; // rax

  result = antlr3CommonTreeNodeStreamNew(tree[4].mNext, hint);
  if ( result )
    result[161].mNext = tree;
  return result;
}

// File Line: 132
// RVA: 0x25C330
UFG::allocator::free_link *__fastcall antlr3CommonTreeNodeStreamNewStream(
        ANTLR3_COMMON_TREE_NODE_STREAM_struct *inStream)
{
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *mNext; // rax
  ANTLR3_BASE_TREE_struct *root; // rax

  v2 = antlrCalloc(1u, 0x5F0u);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  v2[2].mNext = (UFG::allocator::free_link *)inStream->stringFactory;
  v2[162].mNext = (UFG::allocator::free_link *)inStream->adaptor;
  v4 = antlrCalloc(1u, 0x60u);
  if ( v4 )
  {
    v4[11].mNext = (UFG::allocator::free_link *)replaceChildren_1;
    v4[9].mNext = (UFG::allocator::free_link *)antlr3EnumFree;
  }
  v3[1].mNext = v4;
  if ( !v4 )
  {
LABEL_7:
    ((void (__fastcall *)(UFG::allocator::free_link *))v3[188].mNext)(v3);
    return 0i64;
  }
  v3[1].mNext[1].mNext = (UFG::allocator::free_link *)antlr3IntStreamNew();
  mNext = v3[1].mNext;
  if ( !mNext[1].mNext )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))mNext[9].mNext)(v3[1].mNext);
    goto LABEL_7;
  }
  v3[179].mNext = (UFG::allocator::free_link *)addNavigationNode;
  v3[183].mNext = (UFG::allocator::free_link *)hasUniqueNavigationNodes;
  v3[180].mNext = (UFG::allocator::free_link *)newDownNode;
  v3[181].mNext = (UFG::allocator::free_link *)newUpNode;
  v3[187].mNext = (UFG::allocator::free_link *)reset_0;
  v3[185].mNext = (UFG::allocator::free_link *)push;
  v3[186].mNext = (UFG::allocator::free_link *)pop;
  v3[184].mNext = (UFG::allocator::free_link *)getLookaheadSize;
  v3[188].mNext = (UFG::allocator::free_link *)antlr3CommonTreeNodeStreamFree;
  mNext[4].mNext = (UFG::allocator::free_link *)getTreeAdaptor;
  v3[1].mNext[3].mNext = (UFG::allocator::free_link *)getTreeSource;
  v3[1].mNext[2].mNext = (UFG::allocator::free_link *)LT;
  v3[1].mNext[5].mNext = (UFG::allocator::free_link *)setUniqueNavigationNodes;
  v3[1].mNext[6].mNext = (UFG::allocator::free_link *)toString_1;
  v3[1].mNext[7].mNext = (UFG::allocator::free_link *)toStringSS;
  v3[1].mNext[8].mNext = (UFG::allocator::free_link *)toStringWork;
  v3[1].mNext[10].mNext = (UFG::allocator::free_link *)get;
  v3[1].mNext[1].mNext[5].mNext = (UFG::allocator::free_link *)consume;
  v3[1].mNext[1].mNext[8].mNext = (UFG::allocator::free_link *)tindex;
  v3[1].mNext[1].mNext[6].mNext = (UFG::allocator::free_link *)LA;
  v3[1].mNext[1].mNext[7].mNext = (UFG::allocator::free_link *)mark;
  v3[1].mNext[1].mNext[11].mNext = (UFG::allocator::free_link *)_;
  v3[1].mNext[1].mNext[9].mNext = (UFG::allocator::free_link *)rewindMark;
  v3[1].mNext[1].mNext[10].mNext = (UFG::allocator::free_link *)rewindLast;
  v3[1].mNext[1].mNext[12].mNext = (UFG::allocator::free_link *)seek;
  v3[1].mNext[1].mNext[13].mNext = (UFG::allocator::free_link *)size;
  LODWORD(v3[1].mNext[1].mNext->mNext) = 4;
  v3[1].mNext[1].mNext[2].mNext = v3[1].mNext;
  v3[1].mNext->mNext = v3;
  v3->mNext = 0i64;
  LOBYTE(v3[160].mNext) = 0;
  v3[172].mNext = 0i64;
  v3[163].mNext = (UFG::allocator::free_link *)inStream->nodeStack;
  v3[159].mNext = (UFG::allocator::free_link *)antlr3VectorNew(0x64u);
  LODWORD(v3[164].mNext) = -1;
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v3[42]);
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v3[3]);
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v3[81]);
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v3[120]);
  v3[45].mNext = (UFG::allocator::free_link *)inStream->UP.token;
  inStream->UP.token->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3[2].mNext;
  v3[6].mNext = (UFG::allocator::free_link *)inStream->DOWN.token;
  inStream->DOWN.token->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3[2].mNext;
  v3[84].mNext = (UFG::allocator::free_link *)inStream->EOF_NODE.token;
  inStream->EOF_NODE.token->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3[2].mNext;
  v3[123].mNext = (UFG::allocator::free_link *)inStream->INVALID_NODE.token;
  inStream->INVALID_NODE.token->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3[2].mNext;
  root = inStream->root;
  LOBYTE(v3[189].mNext) = 1;
  v3[161].mNext = (UFG::allocator::free_link *)root;
  return v3;
}

// File Line: 270
// RVA: 0x25BF70
UFG::allocator::free_link *__fastcall antlr3CommonTreeNodeStreamNew(
        UFG::allocator::free_link *strFactory,
        unsigned int hint)
{
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *mNext; // rax
  __int64 v10; // rax
  ANTLR3_COMMON_TOKEN_struct *v11; // rax
  ANTLR3_COMMON_TOKEN_struct *v12; // rax
  ANTLR3_COMMON_TOKEN_struct *v13; // rax
  ANTLR3_COMMON_TOKEN_struct *v14; // rax

  v4 = antlrCalloc(1u, 0x5F0u);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v4[2].mNext = strFactory;
  v6 = ANTLR3_TREE_ADAPTORNew(strFactory);
  v5[162].mNext = v6;
  if ( !v6 )
  {
LABEL_7:
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[188].mNext)(v5);
    return 0i64;
  }
  v7 = antlrCalloc(1u, 0x60u);
  if ( v7 )
  {
    v7[11].mNext = (UFG::allocator::free_link *)replaceChildren_1;
    v7[9].mNext = (UFG::allocator::free_link *)antlr3EnumFree;
  }
  v5[1].mNext = v7;
  if ( !v7 )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[162].mNext[42].mNext)(v5[162].mNext);
    goto LABEL_7;
  }
  v5[1].mNext[1].mNext = (UFG::allocator::free_link *)antlr3IntStreamNew();
  mNext = v5[1].mNext;
  if ( mNext[1].mNext )
  {
    v5[179].mNext = (UFG::allocator::free_link *)addNavigationNode;
    v5[183].mNext = (UFG::allocator::free_link *)hasUniqueNavigationNodes;
    v5[180].mNext = (UFG::allocator::free_link *)newDownNode;
    v5[181].mNext = (UFG::allocator::free_link *)newUpNode;
    v5[187].mNext = (UFG::allocator::free_link *)reset_0;
    v5[185].mNext = (UFG::allocator::free_link *)push;
    v5[186].mNext = (UFG::allocator::free_link *)pop;
    v5[188].mNext = (UFG::allocator::free_link *)antlr3CommonTreeNodeStreamFree;
    mNext[4].mNext = (UFG::allocator::free_link *)getTreeAdaptor;
    v5[1].mNext[3].mNext = (UFG::allocator::free_link *)getTreeSource;
    v5[1].mNext[2].mNext = (UFG::allocator::free_link *)LT;
    v5[1].mNext[5].mNext = (UFG::allocator::free_link *)setUniqueNavigationNodes;
    v5[1].mNext[6].mNext = (UFG::allocator::free_link *)toString_1;
    v5[1].mNext[7].mNext = (UFG::allocator::free_link *)toStringSS;
    v5[1].mNext[8].mNext = (UFG::allocator::free_link *)toStringWork;
    v5[1].mNext[10].mNext = (UFG::allocator::free_link *)get;
    v5[1].mNext[1].mNext[5].mNext = (UFG::allocator::free_link *)consume;
    v5[1].mNext[1].mNext[8].mNext = (UFG::allocator::free_link *)tindex;
    v5[1].mNext[1].mNext[6].mNext = (UFG::allocator::free_link *)LA;
    v5[1].mNext[1].mNext[7].mNext = (UFG::allocator::free_link *)mark;
    v5[1].mNext[1].mNext[11].mNext = (UFG::allocator::free_link *)_;
    v5[1].mNext[1].mNext[9].mNext = (UFG::allocator::free_link *)rewindMark;
    v5[1].mNext[1].mNext[10].mNext = (UFG::allocator::free_link *)rewindLast;
    v5[1].mNext[1].mNext[12].mNext = (UFG::allocator::free_link *)seek;
    v5[1].mNext[1].mNext[13].mNext = (UFG::allocator::free_link *)size;
    LODWORD(v5[1].mNext[1].mNext->mNext) = 4;
    v5[1].mNext[1].mNext[2].mNext = v5[1].mNext;
    v5[1].mNext->mNext = v5;
    v5->mNext = 0i64;
    LOBYTE(v5[160].mNext) = 0;
    v5[172].mNext = 0i64;
    v5[163].mNext = (UFG::allocator::free_link *)antlr3StackNew(0xAu);
    if ( !hint )
      hint = 100;
    v10 = antlr3VectorNew(hint);
    LODWORD(v5[164].mNext) = -1;
    v5[159].mNext = (UFG::allocator::free_link *)v10;
    antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v5[42]);
    antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v5[3]);
    antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v5[81]);
    antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v5[120]);
    v11 = antlr3CommonTokenNew(3u);
    v11->tokText.chars = (unsigned int *)"UP";
    v11->strFactory = (ANTLR3_STRING_FACTORY_struct *)strFactory;
    v11->textState = 1;
    v5[45].mNext = (UFG::allocator::free_link *)v11;
    v12 = antlr3CommonTokenNew(2u);
    v12->tokText.chars = (unsigned int *)"DOWN";
    v12->strFactory = (ANTLR3_STRING_FACTORY_struct *)strFactory;
    v12->textState = 1;
    v5[6].mNext = (UFG::allocator::free_link *)v12;
    v13 = antlr3CommonTokenNew(0xFFFFFFFF);
    v13->tokText.chars = (unsigned int *)"EOF";
    v13->strFactory = (ANTLR3_STRING_FACTORY_struct *)strFactory;
    v13->textState = 1;
    v5[84].mNext = (UFG::allocator::free_link *)v13;
    v14 = antlr3CommonTokenNew(0);
    v14->strFactory = (ANTLR3_STRING_FACTORY_struct *)strFactory;
    v14->textState = 1;
    v14->tokText.chars = (unsigned int *)"INVALID";
    v5[123].mNext = (UFG::allocator::free_link *)v14;
    return v5;
  }
  else
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[162].mNext[42].mNext)(v5[162].mNext);
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[1].mNext[9].mNext)(v5[1].mNext);
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[188].mNext)(v5);
    return 0i64;
  }
}

// File Line: 420
// RVA: 0x25B890
void __fastcall antlr3CommonTreeNodeStreamFree(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  ANTLR3_STACK_struct *nodeStack; // rax
  ANTLR3_VECTOR_struct *nodes; // rax

  if ( ctns->isRewriter != 1 )
  {
    ctns->adaptor->free(ctns->adaptor);
    nodeStack = ctns->nodeStack;
    if ( nodeStack )
      nodeStack->free(ctns->nodeStack);
    antlrFree((char *)ctns->INVALID_NODE.token);
    antlrFree((char *)ctns->EOF_NODE.token);
    antlrFree((char *)ctns->DOWN.token);
    antlrFree((char *)ctns->UP.token);
  }
  nodes = ctns->nodes;
  if ( nodes )
    nodes->free(ctns->nodes);
  ctns->tnstream->istream->free(ctns->tnstream->istream);
  ctns->tnstream->free(ctns->tnstream);
  antlrFree((char *)ctns);
}

// File Line: 474
// RVA: 0x25B970
void __fastcall fillBuffer(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns, ANTLR3_BASE_TREE_struct *t)
{
  char v4; // di
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned int i; // edi
  ANTLR3_BASE_TREE_struct *v8; // rax
  char v9; // [rsp+30h] [rbp+8h]

  v4 = ((__int64 (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *))ctns->adaptor->isNilNode)(ctns->adaptor);
  v9 = v4;
  if ( !v4 )
    ctns->nodes->add(ctns->nodes, t, 0i64);
  v5 = t->getChildCount(t);
  v6 = v5;
  if ( !v4 && v5 )
    ctns->addNavigationNode(ctns, 2u);
  for ( i = 0; i < v6; ++i )
  {
    v8 = (ANTLR3_BASE_TREE_struct *)ctns->adaptor->getChild(ctns->adaptor, t, i);
    fillBuffer(ctns, v8);
  }
  if ( !v9 )
  {
    if ( v6 )
      ctns->addNavigationNode(ctns, 3u);
  }
}

// File Line: 526
// RVA: 0x25BCD0
void __fastcall reset_0(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  ANTLR3_STACK_struct *nodeStack; // rax

  if ( ctns->p != -1 )
    ctns->p = 0;
  ctns->tnstream->istream->lastMarker = 0i64;
  if ( ctns->isRewriter != 1 )
  {
    nodeStack = ctns->nodeStack;
    if ( nodeStack )
    {
      nodeStack->free(ctns->nodeStack);
      ctns->nodeStack = (ANTLR3_STACK_struct *)antlr3StackNew(0xAu);
    }
  }
}

// File Line: 577
// RVA: 0x25B740
ANTLR3_BASE_TREE_struct *__fastcall LT(ANTLR3_TREE_NODE_STREAM_struct *tns, int k)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns; // rsi
  int v5; // ebx
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v6; // rax
  ANTLR3_VECTOR_struct *nodes; // r8
  int v9; // edx

  ctns = tns->ctns;
  if ( tns->ctns->p == -1 )
  {
    fillBuffer(tns->ctns, ctns->root);
    ctns->p = 0;
  }
  if ( k < 0 )
  {
    v5 = -k;
    v6 = tns->ctns;
    if ( v5 && v6->p - v5 >= 0 )
      return (ANTLR3_BASE_TREE_struct *)((__int64 (__fastcall *)(ANTLR3_VECTOR_struct *))v6->nodes->get)(v6->nodes);
    return &v6->INVALID_NODE.baseTree;
  }
  if ( !k )
  {
    v6 = tns->ctns;
    return &v6->INVALID_NODE.baseTree;
  }
  nodes = tns->ctns->nodes;
  v9 = k + tns->ctns->p;
  if ( v9 - 1 < (signed int)nodes->count )
    return (ANTLR3_BASE_TREE_struct *)nodes->get(tns->ctns->nodes, v9 - 1);
  else
    return &tns->ctns->EOF_NODE.baseTree;
}

// File Line: 607
// RVA: 0x25BAF0
ANTLR3_BASE_TREE_struct *__fastcall getTreeSource(ANTLR3_TREE_NODE_STREAM_struct *tns)
{
  return tns->ctns->root;
}

// File Line: 615
// RVA: 0x25B930
void __fastcall consume(ANTLR3_INT_STREAM_struct *is)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct **super; // rax
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx

  super = (ANTLR3_COMMON_TREE_NODE_STREAM_struct **)is->super;
  v2 = *super;
  if ( (*super)->p == -1 )
  {
    fillBuffer(*super, v2->root);
    v2->p = 0;
  }
  ++v2->p;
}

// File Line: 631
// RVA: 0x25B710
__int64 __fastcall LA(ANTLR3_INT_STREAM_struct *is, __int64 i)
{
  __int64 result; // rax

  result = (*((__int64 (__fastcall **)(void *, __int64))is->super + 2))(is->super, i);
  if ( result )
    return (*(__int64 (__fastcall **)(__int64))(result + 160))(result);
  return result;
}

// File Line: 656
// RVA: 0x25BB10
__int64 __fastcall mark(ANTLR3_INT_STREAM_struct *is)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct **super; // rax
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx

  super = (ANTLR3_COMMON_TREE_NODE_STREAM_struct **)is->super;
  v2 = *super;
  if ( (*super)->p == -1 )
  {
    fillBuffer(*super, v2->root);
    v2->p = 0;
  }
  v2->tnstream->istream->lastMarker = v2->tnstream->istream->index(v2->tnstream->istream);
  return v2->tnstream->istream->lastMarker;
}

// File Line: 688
// RVA: 0x25BD40
void __fastcall rewindMark(ANTLR3_INT_STREAM_struct *is, __int64 marker)
{
  is->seek(is, marker);
}

// File Line: 694
// RVA: 0x25BD30
void __fastcall rewindLast(ANTLR3_INT_STREAM_struct *is)
{
  is->seek(is, is->lastMarker);
}

// File Line: 703
// RVA: 0x25BD50
void __fastcall seek(ANTLR3_INT_STREAM_struct *is, __int64 index)
{
  *(_DWORD *)(*(_QWORD *)is->super + 1312i64) = index;
}

// File Line: 715
// RVA: 0x25BDC0
__int64 __fastcall tindex(ANTLR3_INT_STREAM_struct *is)
{
  return *(int *)(*(_QWORD *)is->super + 1312i64);
}

// File Line: 731
// RVA: 0x25BD70
__int64 __fastcall size(ANTLR3_INT_STREAM_struct *is)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct **super; // rax
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx

  super = (ANTLR3_COMMON_TREE_NODE_STREAM_struct **)is->super;
  v2 = *super;
  if ( (*super)->p == -1 )
  {
    fillBuffer(*super, v2->root);
    v2->p = 0;
  }
  return ((__int64 (__fastcall *)(ANTLR3_VECTOR_struct *))v2->nodes->size)(v2->nodes);
}

// File Line: 752
// RVA: 0x25B820
void __fastcall addNavigationNode(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns, unsigned int ttype)
{
  ANTLR3_BASE_TREE_struct *p_baseTree; // rdx

  if ( ttype == 2 )
  {
    if ( ((unsigned __int8 (*)(void))ctns->hasUniqueNavigationNodes)() == 1 )
      p_baseTree = ctns->newDownNode(ctns);
    else
      p_baseTree = &ctns->DOWN.baseTree;
  }
  else if ( ((unsigned __int8 (*)(void))ctns->hasUniqueNavigationNodes)() == 1 )
  {
    p_baseTree = ctns->newUpNode(ctns);
  }
  else
  {
    p_baseTree = &ctns->UP.baseTree;
  }
  ctns->nodes->add(ctns->nodes, p_baseTree, 0i64);
}

// File Line: 788
// RVA: 0x25BAE0
ANTLR3_BASE_TREE_ADAPTOR_struct *__fastcall getTreeAdaptor(ANTLR3_TREE_NODE_STREAM_struct *tns)
{
  return tns->ctns->adaptor;
}

// File Line: 794
// RVA: 0x25BB00
__int64 __fastcall hasUniqueNavigationNodes(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  return (unsigned __int8)ctns->uniqueNavigationNodes;
}

// File Line: 800
// RVA: 0x25BD60
void __fastcall setUniqueNavigationNodes(ANTLR3_TREE_NODE_STREAM_struct *tns, char uniqueNavigationNodes)
{
  tns->ctns->uniqueNavigationNodes = uniqueNavigationNodes;
}

// File Line: 811
// RVA: 0x25BDD0
ANTLR3_STRING_struct *__fastcall toString_1(ANTLR3_TREE_NODE_STREAM_struct *tns)
{
  return tns->toStringSS(tns, tns->ctns->root, 0i64);
}

// File Line: 818
// RVA: 0x25BDF0
ANTLR3_STRING_struct *__fastcall toStringSS(
        ANTLR3_TREE_NODE_STREAM_struct *tns,
        ANTLR3_BASE_TREE_struct *start,
        ANTLR3_BASE_TREE_struct *stop)
{
  ANTLR3_STRING_struct *v6; // rbx

  v6 = tns->ctns->stringFactory->newRaw(tns->ctns->stringFactory);
  tns->toStringWork(tns, start, stop, v6);
  return v6;
}

// File Line: 830
// RVA: 0x25BE50
void __fastcall toStringWork(
        ANTLR3_TREE_NODE_STREAM_struct *tns,
        ANTLR3_BASE_TREE_struct *p,
        ANTLR3_BASE_TREE_struct *stop,
        ANTLR3_STRING_struct *buf)
{
  ANTLR3_STRING_struct *v8; // rsi
  unsigned int v9; // eax
  unsigned int v10; // ebp
  unsigned int v11; // esi
  ANTLR3_BASE_TREE_struct *v12; // rax

  if ( !p->isNilNode(p) )
  {
    v8 = p->toString(p);
    if ( !v8 )
    {
      v8 = tns->ctns->stringFactory->newRaw(tns->ctns->stringFactory);
      v8->addc(v8, 32u);
      v9 = p->getType(p);
      v8->addi(v8, v9);
    }
    buf->appendS(buf, v8);
  }
  if ( p != stop )
  {
    v10 = p->getChildCount(p);
    if ( v10 && !p->isNilNode(p) )
    {
      buf->addc(buf, 32u);
      buf->addi(buf, 2);
    }
    v11 = 0;
    if ( v10 )
    {
      do
      {
        v12 = (ANTLR3_BASE_TREE_struct *)p->getChild(p, v11);
        tns->toStringWork(tns, v12, stop, buf);
        ++v11;
      }
      while ( v11 < v10 );
      if ( !p->isNilNode(p) )
      {
        buf->addc(buf, 32u);
        buf->addi(buf, 3);
      }
    }
  }
}

// File Line: 882
// RVA: 0x25BAB0
__int64 __fastcall getLookaheadSize(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  unsigned int tail; // edx
  unsigned int head; // r8d

  tail = ctns->tail;
  head = ctns->head;
  if ( tail >= head )
    return tail - head;
  else
    return tail + ctns->lookAheadLength - head;
}

// File Line: 890
// RVA: 0x25BB70
ANTLR3_BASE_TREE_struct *__fastcall newDownNode(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  ANTLR3_COMMON_TOKEN_struct *v1; // rax

  v1 = antlr3CommonTokenNew(2u);
  v1->tokText.chars = (unsigned int *)"DOWN";
  v1->textState = 1;
  return &antlr3CommonTreeNewFromToken(v1)->baseTree;
}

// File Line: 904
// RVA: 0x25BBB0
ANTLR3_BASE_TREE_struct *__fastcall newUpNode(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  ANTLR3_COMMON_TOKEN_struct *v1; // rax

  v1 = antlr3CommonTokenNew(3u);
  v1->tokText.chars = (unsigned int *)"UP";
  v1->textState = 1;
  return &antlr3CommonTreeNewFromToken(v1)->baseTree;
}

// File Line: 928
// RVA: 0x25BC80
void __fastcall replaceChildren_1(
        ANTLR3_TREE_NODE_STREAM_struct *tns,
        ANTLR3_BASE_TREE_struct *parent,
        unsigned int startChildIndex,
        unsigned int stopChildIndex,
        ANTLR3_BASE_TREE_struct *t)
{
  __int64 v8; // rax

  if ( parent )
  {
    v8 = ((__int64 (*)(void))tns->getTreeAdaptor)();
    (*(void (__fastcall **)(__int64, ANTLR3_BASE_TREE_struct *, _QWORD, _QWORD, ANTLR3_BASE_TREE_struct *))(v8 + 328))(
      v8,
      parent,
      startChildIndex,
      stopChildIndex,
      t);
  }
}

// File Line: 943
// RVA: 0x25BA50
ANTLR3_BASE_TREE_struct *__fastcall get(ANTLR3_TREE_NODE_STREAM_struct *tns, unsigned int k)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns; // rbx

  ctns = tns->ctns;
  if ( tns->ctns->p == -1 )
  {
    fillBuffer(tns->ctns, ctns->root);
    ctns->p = 0;
  }
  return (ANTLR3_BASE_TREE_struct *)tns->ctns->nodes->get(tns->ctns->nodes, k);
}

// File Line: 954
// RVA: 0x25BC30
void __fastcall push(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns, int index)
{
  __int64 v2; // rdi

  v2 = index;
  ctns->nodeStack->push(ctns->nodeStack, (void *)ctns->p, 0i64);
  ctns->tnstream->istream->seek(ctns->tnstream->istream, v2);
}

// File Line: 961
// RVA: 0x25BBF0
__int64 __fastcall pop(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  unsigned int v2; // edi

  v2 = (unsigned int)ctns->nodeStack->pop(ctns->nodeStack);
  ctns->tnstream->istream->seek(ctns->tnstream->istream, (int)v2);
  return v2;
}

