// File Line: 48
// RVA: 0x25EE70
ANTLR3_PARSER_struct *__fastcall antlr3ParserNewStreamDbg(
        unsigned int sizeHint,
        ANTLR3_TOKEN_STREAM_struct *tstream,
        ANTLR3_DEBUG_EVENT_LISTENER_struct *dbg,
        UFG::allocator::free_link *state)
{
  ANTLR3_PARSER_struct *result; // rax
  ANTLR3_PARSER_struct *v7; // rbx

  result = (ANTLR3_PARSER_struct *)antlr3ParserNew(sizeHint, state);
  v7 = result;
  if ( result )
  {
    result->setTokenStream(result, tstream);
    v7->setDebugListener(v7, dbg);
    return v7;
  }
  return result;
}

// File Line: 65
// RVA: 0x25ED80
UFG::allocator::free_link *__fastcall antlr3ParserNew(unsigned int sizeHint, UFG::allocator::free_link *state)
{
  UFG::allocator::free_link *v4; // rbx
  UFG::allocator::free_link *v5; // rax

  v4 = antlrMalloc(0x38ui64);
  if ( !v4 )
    return 0i64;
  v5 = antlr3BaseRecognizerNew(2u, sizeHint, state);
  v4[1].mNext = v5;
  if ( !v5 )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v4[6].mNext)(v4);
    return 0i64;
  }
  v5->mNext = v4;
  v4[1].mNext[34].mNext = (UFG::allocator::free_link *)antlr3MTExceptionNew;
  v4[3].mNext = (UFG::allocator::free_link *)setDebugListener;
  v4[4].mNext = (UFG::allocator::free_link *)setTokenStream;
  v4[5].mNext = (UFG::allocator::free_link *)SSUnaryParam::get_expected_type;
  v4[6].mNext = (UFG::allocator::free_link *)freeParser;
  return v4;
}

// File Line: 106
// RVA: 0x25EE30
ANTLR3_PARSER_struct *__fastcall antlr3ParserNewStream(
        unsigned int sizeHint,
        ANTLR3_TOKEN_STREAM_struct *tstream,
        UFG::allocator::free_link *state)
{
  ANTLR3_PARSER_struct *result; // rax
  ANTLR3_PARSER_struct *v5; // rbx

  result = (ANTLR3_PARSER_struct *)antlr3ParserNew(sizeHint, state);
  v5 = result;
  if ( result )
  {
    result->setTokenStream(result, tstream);
    return v5;
  }
  return result;
}

// File Line: 150
// RVA: 0x25ED40
void __fastcall setDebugListener(ANTLR3_PARSER_struct *parser, ANTLR3_DEBUG_EVENT_LISTENER_struct *dbg)
{
  ANTLR3_TOKEN_STREAM_struct *tstream; // rax

  parser->rec->debugger = dbg;
  tstream = parser->tstream;
  if ( tstream )
    ((void (__fastcall *)(ANTLR3_TOKEN_STREAM_struct *))tstream->setDebugListener)(parser->tstream);
}

// File Line: 173
// RVA: 0x25ED60
void __fastcall setTokenStream(ANTLR3_PARSER_struct *parser, ANTLR3_TOKEN_STREAM_struct *tstream)
{
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rax

  rec = parser->rec;
  parser->tstream = tstream;
  rec->reset(rec);
}

