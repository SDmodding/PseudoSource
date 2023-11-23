// File Line: 56
// RVA: 0x261E30
UFG::allocator::free_link *__fastcall antlr3TreeParserNewStream(
        unsigned int sizeHint,
        ANTLR3_COMMON_TREE_NODE_STREAM_struct *ctnstream,
        UFG::allocator::free_link *state)
{
  UFG::allocator::free_link *v6; // rbx
  UFG::allocator::free_link *v7; // rax

  v6 = antlrMalloc(0x30ui64);
  if ( !v6 )
    return 0i64;
  v7 = antlr3BaseRecognizerNew(2u, sizeHint, state);
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
  setTreeNodeStream((ANTLR3_TREE_PARSER_struct *)v6, ctnstream);
  return v6;
}

// File Line: 115
// RVA: 0x261DF0
void __fastcall antlr3MTNExceptionNew(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  antlr3RecognitionExceptionNew(recognizer);
  recognizer->state->exception->name = "org.antlr.runtime.MismatchedTreeNodeException";
  recognizer->state->exception->type = 7;
}

// File Line: 131
// RVA: 0x261C30
void __fastcall freeParser(ANTLR3_PARSER_struct *parser)
{
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax
  ANTLR3_STACK_struct *following; // rax

  rec = parser->rec;
  if ( rec )
  {
    state = rec->state;
    if ( state )
    {
      following = state->following;
      if ( following )
      {
        following->free(following);
        parser->rec->state->following = 0i64;
      }
    }
    parser->rec->free(parser->rec);
    parser->rec = 0i64;
  }
  antlrFree((char *)parser);
}

// File Line: 157
// RVA: 0x261DC0
void __fastcall setTreeNodeStream(ANTLR3_TREE_PARSER_struct *parser, ANTLR3_COMMON_TREE_NODE_STREAM_struct *input)
{
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rax

  rec = parser->rec;
  parser->ctnstream = input;
  rec->reset(rec);
  parser->ctnstream->reset(parser->ctnstream);
}

// File Line: 178
// RVA: 0x261D80
void __fastcall mismatch_0(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        unsigned int ttype,
        ANTLR3_BITSET_LIST_struct *follow)
{
  ((void (*)(void))recognizer->exConstruct)();
  recognizer->recoverFromMismatchedToken(recognizer, ttype, follow);
}

// File Line: 188
// RVA: 0x261C90
__int64 __fastcall getCurrentInputSymbol_0(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        ANTLR3_INT_STREAM_struct *istream)
{
  return (*((__int64 (__fastcall **)(void *, __int64))istream->super + 2))(istream->super, 1i64);
}

// File Line: 205
// RVA: 0x261CA0
__int64 __fastcall getMissingSymbol_0(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        ANTLR3_INT_STREAM_struct *istream,
        ANTLR3_EXCEPTION_struct *e,
        unsigned int expectedTokenType)
{
  __int64 (__fastcall **super)(void *, __int64, ANTLR3_EXCEPTION_struct *); // rsi
  __int64 (__fastcall *v6)(void *, __int64, ANTLR3_EXCEPTION_struct *); // rdi
  __int64 v7; // rbp
  __int64 v8; // rax
  unsigned int v9; // ebx
  __int64 (__fastcall **v10)(_QWORD); // r8
  __int64 v11; // rax
  __int64 v12; // rdi
  __int64 v13; // rbx
  __int64 v14; // rbx

  super = (__int64 (__fastcall **)(void *, __int64, ANTLR3_EXCEPTION_struct *))istream->super;
  v6 = *super;
  v7 = expectedTokenType;
  v8 = super[2](super, 1i64, e);
  v9 = -1;
  v10 = (__int64 (__fastcall **)(_QWORD))v8;
  if ( (__int64 (__fastcall *)(void *, __int64, ANTLR3_EXCEPTION_struct *))v8 == (__int64 (__fastcall *)(void *, __int64, ANTLR3_EXCEPTION_struct *))((char *)v6 + 704) )
  {
    v9 = -2;
    v10 = (__int64 (__fastcall **)(_QWORD))super[2](super, 0xFFFFFFFFi64, (ANTLR3_EXCEPTION_struct *)v8);
  }
  if ( !*((_QWORD *)*v10 + 6) )
  {
    do
    {
      v11 = ((__int64 (__fastcall *)(__int64 (__fastcall **)(void *, __int64, ANTLR3_EXCEPTION_struct *), _QWORD))super[2])(
              super,
              v9--);
      v10 = (__int64 (__fastcall **)(_QWORD))v11;
    }
    while ( !*(_QWORD *)(*(_QWORD *)v11 + 48i64) );
  }
  v12 = v10[11](v10);
  v13 = (*(__int64 (__fastcall **)(__int64))(v12 + 40))(v12);
  (*(void (__fastcall **)(__int64, const char *))(v13 + 136))(v13, "<missing ");
  v14 = (*(__int64 (__fastcall **)(__int64))(v13 + 120))(v13);
  (*(void (__fastcall **)(__int64, char *))(v14 + 56))(v14, recognizer->state->tokenNames[v7]);
  (*(void (__fastcall **)(__int64, const char *))(v14 + 56))(v14, ">");
  return v12;
}

