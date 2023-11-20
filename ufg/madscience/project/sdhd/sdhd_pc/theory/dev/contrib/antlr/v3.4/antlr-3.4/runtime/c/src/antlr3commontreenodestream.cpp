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
UFG::allocator::free_link *__fastcall antlr3CommonTreeNodeStreamNewTree(ANTLR3_BASE_TREE_struct *tree, unsigned int hint)
{
  ANTLR3_BASE_TREE_struct *v2; // rbx
  UFG::allocator::free_link *result; // rax

  v2 = tree;
  result = antlr3CommonTreeNodeStreamNew(tree->strFactory, hint);
  if ( result )
    result[161].mNext = (UFG::allocator::free_link *)v2;
  return result;
}

// File Line: 132
// RVA: 0x25C330
UFG::allocator::free_link *__fastcall antlr3CommonTreeNodeStreamNewStream(ANTLR3_COMMON_TREE_NODE_STREAM_struct *inStream)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v1; // rdi
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rax
  ANTLR3_BASE_TREE_struct *v7; // rax

  v1 = inStream;
  v2 = antlrCalloc(1u, 0x5F0u);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  v2[2].mNext = (UFG::allocator::free_link *)v1->stringFactory;
  v2[162].mNext = (UFG::allocator::free_link *)v1->adaptor;
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
  v5 = v3[1].mNext;
  if ( !v5[1].mNext )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[9].mNext)(v3[1].mNext);
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
  v5[4].mNext = (UFG::allocator::free_link *)getTreeAdaptor;
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
  v3[1].mNext[1].mNext->mNext = (UFG::allocator::free_link *)4;
  v3[1].mNext[1].mNext[2].mNext = v3[1].mNext;
  v3[1].mNext->mNext = v3;
  v3->mNext = 0i64;
  LOBYTE(v3[160].mNext) = 0;
  v3[172].mNext = 0i64;
  v3[163].mNext = (UFG::allocator::free_link *)v1->nodeStack;
  v3[159].mNext = antlr3VectorNew(0x64u);
  LODWORD(v3[164].mNext) = -1;
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v3[42]);
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v3[3]);
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v3[81]);
  antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v3[120]);
  v3[45].mNext = (UFG::allocator::free_link *)v1->UP.token;
  v1->UP.token->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3[2].mNext;
  v3[6].mNext = (UFG::allocator::free_link *)v1->DOWN.token;
  v1->DOWN.token->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3[2].mNext;
  v3[84].mNext = (UFG::allocator::free_link *)v1->EOF_NODE.token;
  v1->EOF_NODE.token->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3[2].mNext;
  v3[123].mNext = (UFG::allocator::free_link *)v1->INVALID_NODE.token;
  v1->INVALID_NODE.token->strFactory = (ANTLR3_STRING_FACTORY_struct *)v3[2].mNext;
  v7 = v1->root;
  LOBYTE(v3[189].mNext) = 1;
  v3[161].mNext = (UFG::allocator::free_link *)v7;
  return v3;
}

// File Line: 270
// RVA: 0x25BF70
UFG::allocator::free_link *__fastcall antlr3CommonTreeNodeStreamNew(ANTLR3_STRING_FACTORY_struct *strFactory, unsigned int hint)
{
  signed int v2; // esi
  ANTLR3_STRING_FACTORY_struct *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rax
  ANTLR3_COMMON_TOKEN_struct *v11; // rax
  ANTLR3_COMMON_TOKEN_struct *v12; // rax
  ANTLR3_COMMON_TOKEN_struct *v13; // rax
  ANTLR3_COMMON_TOKEN_struct *v14; // rax

  v2 = hint;
  v3 = strFactory;
  v4 = antlrCalloc(1u, 0x5F0u);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v4[2].mNext = (UFG::allocator::free_link *)v3;
  v6 = ANTLR3_TREE_ADAPTORNew(v3);
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
  v9 = v5[1].mNext;
  if ( v9[1].mNext )
  {
    v5[179].mNext = (UFG::allocator::free_link *)addNavigationNode;
    v5[183].mNext = (UFG::allocator::free_link *)hasUniqueNavigationNodes;
    v5[180].mNext = (UFG::allocator::free_link *)newDownNode;
    v5[181].mNext = (UFG::allocator::free_link *)newUpNode;
    v5[187].mNext = (UFG::allocator::free_link *)reset_0;
    v5[185].mNext = (UFG::allocator::free_link *)push;
    v5[186].mNext = (UFG::allocator::free_link *)pop;
    v5[188].mNext = (UFG::allocator::free_link *)antlr3CommonTreeNodeStreamFree;
    v9[4].mNext = (UFG::allocator::free_link *)getTreeAdaptor;
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
    v5[1].mNext[1].mNext->mNext = (UFG::allocator::free_link *)4;
    v5[1].mNext[1].mNext[2].mNext = v5[1].mNext;
    v5[1].mNext->mNext = v5;
    v5->mNext = 0i64;
    LOBYTE(v5[160].mNext) = 0;
    v5[172].mNext = 0i64;
    v5[163].mNext = antlr3StackNew(0xAu);
    if ( !v2 )
      v2 = 100;
    v10 = antlr3VectorNew(v2);
    LODWORD(v5[164].mNext) = -1;
    v5[159].mNext = v10;
    antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v5[42]);
    antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v5[3]);
    antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v5[81]);
    antlr3SetCTAPI((ANTLR3_COMMON_TREE_struct *)&v5[120]);
    v11 = antlr3CommonTokenNew(3u);
    v11->tokText.chars = (unsigned int *)"UP";
    v11->strFactory = v3;
    v11->textState = 1;
    v5[45].mNext = (UFG::allocator::free_link *)v11;
    v12 = antlr3CommonTokenNew(2u);
    v12->tokText.chars = (unsigned int *)"DOWN";
    v12->strFactory = v3;
    v12->textState = 1;
    v5[6].mNext = (UFG::allocator::free_link *)v12;
    v13 = antlr3CommonTokenNew(0xFFFFFFFF);
    v13->tokText.chars = (unsigned int *)"EOF";
    v13->strFactory = v3;
    v13->textState = 1;
    v5[84].mNext = (UFG::allocator::free_link *)v13;
    v14 = antlr3CommonTokenNew(0);
    v14->strFactory = v3;
    v14->textState = 1;
    v14->tokText.chars = (unsigned int *)"INVALID";
    v5[123].mNext = (UFG::allocator::free_link *)v14;
    result = v5;
  }
  else
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[162].mNext[42].mNext)(v5[162].mNext);
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[1].mNext[9].mNext)(v5[1].mNext);
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[188].mNext)(v5);
    result = 0i64;
  }
  return result;
}

// File Line: 420
// RVA: 0x25B890
void __fastcall antlr3CommonTreeNodeStreamFree(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v1; // rbx
  ANTLR3_STACK_struct *v2; // rax
  ANTLR3_VECTOR_struct *v3; // rax

  v1 = ctns;
  if ( ctns->isRewriter != 1 )
  {
    ctns->adaptor->free(ctns->adaptor);
    v2 = v1->nodeStack;
    if ( v2 )
      v2->free(v1->nodeStack);
    antlrFree(v1->INVALID_NODE.token);
    antlrFree(v1->EOF_NODE.token);
    antlrFree(v1->DOWN.token);
    antlrFree(v1->UP.token);
  }
  v3 = v1->nodes;
  if ( v3 )
    v3->free(v1->nodes);
  v1->tnstream->istream->free(v1->tnstream->istream);
  v1->tnstream->free(v1->tnstream);
  antlrFree(v1);
}

// File Line: 474
// RVA: 0x25B970
void __fastcall fillBuffer(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns, ANTLR3_BASE_TREE_struct *t)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx
  ANTLR3_BASE_TREE_struct *v3; // rbp
  char v4; // di
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // edi
  ANTLR3_BASE_TREE_struct *v8; // rax
  char v9; // [rsp+30h] [rbp+8h]

  v2 = ctns;
  v3 = t;
  v4 = ((__int64 (__fastcall *)(ANTLR3_BASE_TREE_ADAPTOR_struct *))ctns->adaptor->isNilNode)(ctns->adaptor);
  v9 = v4;
  if ( !v4 )
    v2->nodes->add(v2->nodes, v3, 0i64);
  v5 = v3->getChildCount(v3);
  v6 = v5;
  if ( !v4 && v5 )
    v2->addNavigationNode(v2, 2u);
  v7 = 0;
  if ( v6 )
  {
    do
    {
      v8 = (ANTLR3_BASE_TREE_struct *)v2->adaptor->getChild(v2->adaptor, v3, v7);
      fillBuffer(v2, v8);
      ++v7;
    }
    while ( v7 < v6 );
  }
  if ( !v9 )
  {
    if ( v6 )
      v2->addNavigationNode(v2, 3u);
  }
}

// File Line: 526
// RVA: 0x25BCD0
void __fastcall reset_0(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v1; // rbx
  ANTLR3_STACK_struct *v2; // rax

  v1 = ctns;
  if ( ctns->p != -1 )
    ctns->p = 0;
  ctns->tnstream->istream->lastMarker = 0i64;
  if ( ctns->isRewriter != 1 )
  {
    v2 = ctns->nodeStack;
    if ( v2 )
    {
      v2->free(ctns->nodeStack);
      v1->nodeStack = (ANTLR3_STACK_struct *)antlr3StackNew(0xAu);
    }
  }
}

// File Line: 577
// RVA: 0x25B740
ANTLR3_BASE_TREE_struct *__fastcall LT(ANTLR3_TREE_NODE_STREAM_struct *tns, int k)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rsi
  int v3; // ebx
  ANTLR3_TREE_NODE_STREAM_struct *v4; // rdi
  int v5; // ebx
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v6; // rax
  ANTLR3_BASE_TREE_struct *result; // rax
  ANTLR3_VECTOR_struct *v8; // r8
  int v9; // edx

  v2 = tns->ctns;
  v3 = k;
  v4 = tns;
  if ( tns->ctns->p == -1 )
  {
    fillBuffer(tns->ctns, v2->root);
    v2->p = 0;
  }
  if ( v3 < 0 )
  {
    v5 = -v3;
    v6 = v4->ctns;
    if ( v5 && v6->p - v5 >= 0 )
      return (ANTLR3_BASE_TREE_struct *)((__int64 (__fastcall *)(ANTLR3_VECTOR_struct *))v6->nodes->get)(v6->nodes);
    return &v6->INVALID_NODE.baseTree;
  }
  if ( !v3 )
  {
    v6 = v4->ctns;
    return &v6->INVALID_NODE.baseTree;
  }
  v8 = v4->ctns->nodes;
  v9 = v3 + v4->ctns->p;
  if ( v9 - 1 < (signed int)v8->count )
    result = (ANTLR3_BASE_TREE_struct *)v8->get(v4->ctns->nodes, v9 - 1);
  else
    result = &v4->ctns->EOF_NODE.baseTree;
  return result;
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
  ANTLR3_COMMON_TREE_NODE_STREAM_struct **v1; // rax
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx

  v1 = (ANTLR3_COMMON_TREE_NODE_STREAM_struct **)is->super;
  v2 = *v1;
  if ( (*v1)->p == -1 )
  {
    fillBuffer(*v1, v2->root);
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
    result = (*(__int64 (__fastcall **)(__int64))(result + 160))(result);
  return result;
}

// File Line: 656
// RVA: 0x25BB10
__int64 __fastcall mark(ANTLR3_INT_STREAM_struct *is)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct **v1; // rax
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx

  v1 = (ANTLR3_COMMON_TREE_NODE_STREAM_struct **)is->super;
  v2 = *v1;
  if ( (*v1)->p == -1 )
  {
    fillBuffer(*v1, v2->root);
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
  return *(signed int *)(*(_QWORD *)is->super + 1312i64);
}

// File Line: 731
// RVA: 0x25BD70
__int64 __fastcall size(ANTLR3_INT_STREAM_struct *is)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct **v1; // rax
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx

  v1 = (ANTLR3_COMMON_TREE_NODE_STREAM_struct **)is->super;
  v2 = *v1;
  if ( (*v1)->p == -1 )
  {
    fillBuffer(*v1, v2->root);
    v2->p = 0;
  }
  return v2->nodes->size(v2->nodes);
}

// File Line: 752
// RVA: 0x25B820
void __fastcall addNavigationNode(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns, unsigned int ttype)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx
  signed __int64 v3; // rdx

  v2 = ctns;
  if ( ttype == 2 )
  {
    if ( ((unsigned __int8 (*)(void))ctns->hasUniqueNavigationNodes)() == 1 )
      v3 = (__int64)v2->newDownNode(v2);
    else
      v3 = (signed __int64)&v2->DOWN.baseTree;
  }
  else if ( ((unsigned __int8 (*)(void))ctns->hasUniqueNavigationNodes)() == 1 )
  {
    v3 = (__int64)v2->newUpNode(v2);
  }
  else
  {
    v3 = (signed __int64)&v2->UP.baseTree;
  }
  v2->nodes->add(v2->nodes, (void *)v3, 0i64);
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
  return (ANTLR3_STRING_struct *)tns->toStringSS(tns, tns->ctns->root, 0i64);
}

// File Line: 818
// RVA: 0x25BDF0
ANTLR3_STRING_struct *__fastcall toStringSS(ANTLR3_TREE_NODE_STREAM_struct *tns, ANTLR3_BASE_TREE_struct *start, ANTLR3_BASE_TREE_struct *stop)
{
  ANTLR3_TREE_NODE_STREAM_struct *v3; // r14
  ANTLR3_BASE_TREE_struct *v4; // rdi
  ANTLR3_BASE_TREE_struct *v5; // rsi
  ANTLR3_STRING_struct *v6; // rbx

  v3 = tns;
  v4 = stop;
  v5 = start;
  v6 = tns->ctns->stringFactory->newRaw(tns->ctns->stringFactory);
  v3->toStringWork(v3, v5, v4, v6);
  return v6;
}

// File Line: 830
// RVA: 0x25BE50
void __fastcall toStringWork(ANTLR3_TREE_NODE_STREAM_struct *tns, ANTLR3_BASE_TREE_struct *p, ANTLR3_BASE_TREE_struct *stop, ANTLR3_STRING_struct *buf)
{
  ANTLR3_TREE_NODE_STREAM_struct *v4; // r14
  ANTLR3_STRING_struct *v5; // rdi
  ANTLR3_BASE_TREE_struct *v6; // r15
  ANTLR3_BASE_TREE_struct *v7; // rbx
  __int64 v8; // rsi
  unsigned int v9; // eax
  unsigned int v10; // ebp
  unsigned int v11; // esi
  __int64 v12; // rax

  v4 = tns;
  v5 = buf;
  v6 = stop;
  v7 = p;
  if ( !p->isNilNode(p) )
  {
    v8 = (__int64)v7->toString(v7);
    if ( !v8 )
    {
      v8 = (__int64)v4->ctns->stringFactory->newRaw(v4->ctns->stringFactory);
      (*(void (__fastcall **)(__int64, signed __int64))(v8 + 112))(v8, 32i64);
      v9 = v7->getType(v7);
      (*(void (__fastcall **)(__int64, _QWORD))(v8 + 120))(v8, v9);
    }
    v5->appendS(v5, (ANTLR3_STRING_struct *)v8);
  }
  if ( v7 != v6 )
  {
    v10 = v7->getChildCount(v7);
    if ( v10 && !v7->isNilNode(v7) )
    {
      v5->addc(v5, 32u);
      v5->addi(v5, 2);
    }
    v11 = 0;
    if ( v10 )
    {
      do
      {
        v12 = (__int64)v7->getChild(v7, v11);
        v4->toStringWork(v4, (ANTLR3_BASE_TREE_struct *)v12, v6, v5);
        ++v11;
      }
      while ( v11 < v10 );
      if ( v10 )
      {
        if ( !v7->isNilNode(v7) )
        {
          v5->addc(v5, 32u);
          v5->addi(v5, 3);
        }
      }
    }
  }
}

// File Line: 882
// RVA: 0x25BAB0
__int64 __fastcall getLookaheadSize(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  unsigned int v1; // edx
  unsigned int v2; // er8
  __int64 result; // rax

  v1 = ctns->tail;
  v2 = ctns->head;
  if ( v1 >= v2 )
    result = v1 - v2;
  else
    result = v1 + ctns->lookAheadLength - v2;
  return result;
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
void __fastcall replaceChildren_1(ANTLR3_TREE_NODE_STREAM_struct *tns, ANTLR3_BASE_TREE_struct *parent, int startChildIndex, int stopChildIndex, ANTLR3_BASE_TREE_struct *t)
{
  unsigned int v5; // edi
  unsigned int v6; // esi
  ANTLR3_BASE_TREE_struct *v7; // rbx
  __int64 v8; // rax

  if ( parent )
  {
    v5 = stopChildIndex;
    v6 = startChildIndex;
    v7 = parent;
    v8 = ((__int64 (*)(void))tns->getTreeAdaptor)();
    (*(void (__fastcall **)(__int64, ANTLR3_BASE_TREE_struct *, _QWORD, _QWORD, ANTLR3_BASE_TREE_struct *))(v8 + 328))(
      v8,
      v7,
      v6,
      v5,
      t);
  }
}

// File Line: 943
// RVA: 0x25BA50
ANTLR3_BASE_TREE_struct *__fastcall get(ANTLR3_TREE_NODE_STREAM_struct *tns, int k)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v2; // rbx
  unsigned int v3; // esi
  ANTLR3_TREE_NODE_STREAM_struct *v4; // rdi

  v2 = tns->ctns;
  v3 = k;
  v4 = tns;
  if ( tns->ctns->p == -1 )
  {
    fillBuffer(tns->ctns, v2->root);
    v2->p = 0;
  }
  return (ANTLR3_BASE_TREE_struct *)v4->ctns->nodes->get(v4->ctns->nodes, v3);
}

// File Line: 954
// RVA: 0x25BC30
void __fastcall push(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns, int index)
{
  __int64 v2; // rdi
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v3; // rbx

  v2 = index;
  v3 = ctns;
  ctns->nodeStack->push(ctns->nodeStack, (void *)ctns->p, 0i64);
  v3->tnstream->istream->seek(v3->tnstream->istream, v2);
}

// File Line: 961
// RVA: 0x25BBF0
__int64 __fastcall pop(ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctns)
{
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v1; // rbx
  unsigned int v2; // edi

  v1 = ctns;
  v2 = (__int64)ctns->nodeStack->pop(ctns->nodeStack);
  v1->tnstream->istream->seek(v1->tnstream->istream, (signed int)v2);
  return v2;
}

