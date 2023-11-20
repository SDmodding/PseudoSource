// File Line: 56
// RVA: 0x261E30
UFG::allocator::free_link *__fastcall antlr3TreeParserNewStream(unsigned int sizeHint, ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctnstream, ANTLR3_RECOGNIZER_SHARED_STATE_struct *state)
{
  unsigned int v3; // esi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // rdi
  ANTLR3_COMMON_TREE_NODE_STREAM_struct *v5; // rbp
  UFG::allocator::free_link *v6; // rbx
  UFG::allocator::free_link *v7; // rax

  v3 = sizeHint;
  v4 = state;
  v5 = ctnstream;
  v6 = antlrMalloc(0x30ui64);
  if ( !v6 )
    return 0i64;
  v7 = antlr3BaseRecognizerNew(2u, v3, v4);
  v6[1].mNext = v7;
  if ( !v7 )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v6[5].mNext)(v6);
    return 0i64;
  }
  v7->mNext = v6;
  LODWORD(v6[1].mNext[1].mNext) = 4;
  v6[1].mNext[8].mNext = (UFG::allocator::free_link *)mismatch_0;
  v6[1].mNext[34].mNext = (UFG::allocator::free_link *)antlr3MTNExceptionNew;
  v6[1].mNext[31].mNext = (UFG::allocator::free_link *)getCurrentInputSymbol_0;
  v6[1].mNext[32].mNext = (UFG::allocator::free_link *)getMissingSymbol_0;
  v6[4].mNext = (UFG::allocator::free_link *)SSUnaryParam::get_expected_type;
  v6[3].mNext = (UFG::allocator::free_link *)setTreeNodeStream;
  v6[5].mNext = (UFG::allocator::free_link *)freeParser;
  setTreeNodeStream((ANTLR3_TREE_PARSER_struct *)v6, v5);
  return v6;
}

// File Line: 115
// RVA: 0x261DF0
void __fastcall antlr3MTNExceptionNew(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_BASE_RECOGNIZER_struct *v1; // rbx

  v1 = recognizer;
  antlr3RecognitionExceptionNew(recognizer);
  v1->state->exception->name = "org.antlr.runtime.MismatchedTreeNodeException";
  v1->state->exception->type = 7;
}

// File Line: 131
// RVA: 0x261C30
void __fastcall freeParser(ANTLR3_PARSER_struct *parser)
{
  ANTLR3_BASE_RECOGNIZER_struct *v1; // rax
  ANTLR3_PARSER_struct *v2; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v3; // rax
  ANTLR3_STACK_struct *v4; // rax

  v1 = parser->rec;
  v2 = parser;
  if ( v1 )
  {
    v3 = v1->state;
    if ( v3 )
    {
      v4 = v3->following;
      if ( v4 )
      {
        v4->free(v4);
        v2->rec->state->following = 0i64;
      }
    }
    v2->rec->free(v2->rec);
    v2->rec = 0i64;
  }
  antlrFree(v2);
}

// File Line: 157
// RVA: 0x261DC0
void __fastcall setTreeNodeStream(ANTLR3_TREE_PARSER_struct *parser, ANTLR3_COMMON_TREE_NODE_STREAM_struct *input)
{
  ANTLR3_BASE_RECOGNIZER_struct *v2; // rax
  ANTLR3_TREE_PARSER_struct *v3; // rbx

  v2 = parser->rec;
  v3 = parser;
  parser->ctnstream = input;
  v2->reset(v2);
  v3->ctnstream->reset(v3->ctnstream);
}

// File Line: 178
// RVA: 0x261D80
void __fastcall mismatch_0(ANTLR3_BASE_RECOGNIZER_struct *recognizer, unsigned int ttype, ANTLR3_BITSET_LIST_struct *follow)
{
  ANTLR3_BITSET_LIST_struct *v3; // rbx
  unsigned int v4; // edi
  ANTLR3_BASE_RECOGNIZER_struct *v5; // rsi

  v3 = follow;
  v4 = ttype;
  v5 = recognizer;
  ((void (*)(void))recognizer->exConstruct)();
  v5->recoverFromMismatchedToken(v5, v4, v3);
}

// File Line: 188
// RVA: 0x261C90
__int64 __fastcall getCurrentInputSymbol_0(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_INT_STREAM_struct *istream)
{
  return (*((__int64 (__fastcall **)(void *, signed __int64))istream->super + 2))(istream->super, 1i64);
}

// File Line: 205
// RVA: 0x261CA0
__int64 __fastcall getMissingSymbol_0(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_INT_STREAM_struct *istream, ANTLR3_EXCEPTION_struct *e, unsigned int expectedTokenType)
{
  __int64 (__fastcall **v4)(void *, signed __int64, ANTLR3_EXCEPTION_struct *); // rsi
  ANTLR3_BASE_RECOGNIZER_struct *v5; // r14
  __int64 (__fastcall *v6)(void *, signed __int64, ANTLR3_EXCEPTION_struct *); // rdi
  __int64 v7; // rbp
  __int64 v8; // rax
  unsigned int v9; // ebx
  __int64 (__fastcall **v10)(_QWORD); // r8
  __int64 v11; // rax
  __int64 v12; // rdi
  __int64 v13; // rbx
  __int64 v14; // rbx

  v4 = (__int64 (__fastcall **)(void *, signed __int64, ANTLR3_EXCEPTION_struct *))istream->super;
  v5 = recognizer;
  v6 = *v4;
  v7 = expectedTokenType;
  v8 = v4[2](v4, 1i64, e);
  v9 = -1;
  v10 = (__int64 (__fastcall **)(_QWORD))v8;
  if ( (__int64 (__fastcall *)(void *, signed __int64, ANTLR3_EXCEPTION_struct *))v8 == (__int64 (__fastcall *)(void *, signed __int64, ANTLR3_EXCEPTION_struct *))((char *)v6 + 704) )
  {
    v9 = -2;
    v10 = (__int64 (__fastcall **)(_QWORD))v4[2](v4, 0xFFFFFFFFi64, (ANTLR3_EXCEPTION_struct *)v8);
  }
  if ( !*((_QWORD *)*v10 + 6) )
  {
    do
    {
      v11 = ((__int64 (__fastcall *)(__int64 (__fastcall **)(void *, signed __int64, ANTLR3_EXCEPTION_struct *), _QWORD))v4[2])(
              v4,
              v9--);
      v10 = (__int64 (__fastcall **)(_QWORD))v11;
    }
    while ( !*(_QWORD *)(*(_QWORD *)v11 + 48i64) );
  }
  v12 = v10[11](v10);
  v13 = (*(__int64 (__fastcall **)(__int64))(v12 + 40))(v12);
  (*(void (__fastcall **)(__int64, const char *))(v13 + 136))(v13, "<missing ");
  v14 = (*(__int64 (__fastcall **)(__int64))(v13 + 120))(v13);
  (*(void (__fastcall **)(__int64, char *))(v14 + 56))(v14, v5->state->tokenNames[v7]);
  (*(void (__fastcall **)(__int64, const char *))(v14 + 56))(v14, ">");
  return v12;
}

