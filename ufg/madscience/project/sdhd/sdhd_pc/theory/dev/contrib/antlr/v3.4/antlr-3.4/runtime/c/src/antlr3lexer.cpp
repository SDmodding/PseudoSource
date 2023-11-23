// File Line: 76
// RVA: 0x25EA80
UFG::allocator::free_link *__fastcall antlr3LexerNew(unsigned int sizeHint, UFG::allocator::free_link *state)
{
  UFG::allocator::free_link *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *mNext; // rdx
  UFG::allocator::free_link *v7; // rcx
  UFG::allocator::free_link *v9; // rbx
  __int64 v10; // rbx

  v4 = antlrMalloc(0xA0ui64);
  if ( !v4 )
    return 0i64;
  v5 = antlr3BaseRecognizerNew(1u, sizeHint, state);
  v4[3].mNext = v5;
  if ( !v5 )
  {
LABEL_6:
    ((void (__fastcall *)(UFG::allocator::free_link *))v4[19].mNext)(v4);
    return 0i64;
  }
  v5->mNext = v4;
  v4[3].mNext[10].mNext = (UFG::allocator::free_link *)displayRecognitionError_0;
  v4[3].mNext[9].mNext = (UFG::allocator::free_link *)reportError_0;
  v4[3].mNext[35].mNext = (UFG::allocator::free_link *)reset_1;
  v4[3].mNext[31].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v4[3].mNext[32].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  if ( !v4[3].mNext[2].mNext[13].mNext )
  {
    v4[3].mNext[2].mNext[13].mNext = antlrCalloc(1u, 0x230u);
    mNext = v4[3].mNext;
    v7 = mNext[2].mNext[13].mNext;
    if ( !v7 )
    {
      ((void (__fastcall *)(UFG::allocator::free_link *))mNext[36].mNext)(v4[3].mNext);
      goto LABEL_6;
    }
    v7[68].mNext = v4;
    v4[3].mNext[2].mNext[13].mNext->mNext = (UFG::allocator::free_link *)nextToken;
    v4[3].mNext[2].mNext[13].mNext[1].mNext = 0i64;
    v4[3].mNext[2].mNext[12].mNext = 0i64;
  }
  v4[9].mNext = (UFG::allocator::free_link *)_;
  v4[4].mNext = (UFG::allocator::free_link *)setCharStream;
  v4[5].mNext = (UFG::allocator::free_link *)pushCharStream;
  v4[6].mNext = (UFG::allocator::free_link *)popCharStream;
  v4[8].mNext = (UFG::allocator::free_link *)emit;
  v4[7].mNext = (UFG::allocator::free_link *)emitNew;
  v4[10].mNext = (UFG::allocator::free_link *)matchs;
  v4[11].mNext = (UFG::allocator::free_link *)matchc;
  v4[12].mNext = (UFG::allocator::free_link *)matchRange;
  v4[13].mNext = (UFG::allocator::free_link *)recover_0;
  v4[14].mNext = (UFG::allocator::free_link *)recover_0;
  v4[15].mNext = (UFG::allocator::free_link *)getLine_0;
  v4[16].mNext = (UFG::allocator::free_link *)getCharIndex;
  v4[17].mNext = (UFG::allocator::free_link *)getCharPositionInLine_0;
  v4[18].mNext = (UFG::allocator::free_link *)getText_2;
  v4[19].mNext = (UFG::allocator::free_link *)freeLexer;
  v9 = v4[3].mNext[2].mNext[13].mNext;
  antlr3SetTokenAPI((ANTLR3_COMMON_TOKEN_struct *)&v9[2]);
  ((void (__fastcall *)(UFG::allocator::free_link *, __int64))v9[21].mNext)(&v9[2], 0xFFFFFFFFi64);
  BYTE4(v9[2].mNext) = 1;
  v9[3].mNext = 0i64;
  LODWORD(v9[11].mNext) = 0;
  v9[15].mNext = 0i64;
  v9[13].mNext = 0i64;
  LODWORD(v9[14].mNext) = 0;
  v10 = (__int64)&v4[3].mNext[2].mNext[13].mNext[35];
  antlr3SetTokenAPI((ANTLR3_COMMON_TOKEN_struct *)v10);
  (*(void (__fastcall **)(__int64, _QWORD))(v10 + 152))(v10, 0i64);
  *(_QWORD *)(v10 + 8) = 0i64;
  *(_QWORD *)(v10 + 104) = 0i64;
  *(_QWORD *)(v10 + 88) = 0i64;
  *(_DWORD *)(v10 + 96) = 0;
  *(_BYTE *)(v10 + 4) = 1;
  return v4;
}

// File Line: 179
// RVA: 0x25E910
void __fastcall reset_1(ANTLR3_BASE_RECOGNIZER_struct *rec)
{
  _QWORD *super; // rdx
  __int64 v2; // rcx
  __int64 v3; // rax

  super = rec->super;
  *(_QWORD *)(*(_QWORD *)(*((_QWORD *)rec->super + 3) + 16i64) + 88i64) = 0i64;
  *(_DWORD *)(*(_QWORD *)(super[3] + 16i64) + 116i64) = 0;
  *(_DWORD *)(*(_QWORD *)(super[3] + 16i64) + 112i64) = 0;
  *(_QWORD *)(*(_QWORD *)(super[3] + 16i64) + 128i64) = -1i64;
  *(_DWORD *)(*(_QWORD *)(super[3] + 16i64) + 124i64) = -1;
  *(_DWORD *)(*(_QWORD *)(super[3] + 16i64) + 120i64) = -1;
  *(_QWORD *)(*(_QWORD *)(super[3] + 16i64) + 136i64) = 0i64;
  v2 = *(_QWORD *)(super[3] + 16i64);
  v3 = *(_QWORD *)(v2 + 96);
  if ( v3 )
    (*(void (__fastcall **)(_QWORD))(v3 + 304))(*(_QWORD *)(v2 + 96));
}

// File Line: 221
// RVA: 0x25E6A0
ANTLR3_COMMON_TOKEN_struct *__fastcall nextTokenStr(ANTLR3_TOKEN_SOURCE_struct *toksource)
{
  ANTLR3_LEXER_struct *super; // rdi
  ANTLR3_INPUT_STREAM_struct *input; // r14
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_INT_STREAM_struct *istream; // rbp
  int line; // eax
  ANTLR3_TOKEN_SOURCE_struct *token; // rcx
  __int64 v9; // rax
  __int64 v10; // rax
  unsigned int v11; // eax

  super = (ANTLR3_LEXER_struct *)toksource->super;
  input = super->input;
  state = super->rec->state;
  istream = input->istream;
  state->token = 0i64;
  state->error = 0;
  state->failed = 0;
  while ( 1 )
  {
    state->channel = 0;
    state->tokenStartCharIndex = (__int64)input->nextChar;
    state->tokenStartCharPositionInLine = input->charPositionInLine;
    line = input->line;
    state->text = 0i64;
    state->custom = 0i64;
    *(_QWORD *)&state->user1 = 0i64;
    state->user3 = 0;
    state->tokenStartLine = line;
    if ( istream->_LA(istream, 1) == -1 )
      break;
    state->token = 0i64;
    state->error = 0;
    state->failed = 0;
    super->mTokens(super->ctx);
    if ( state->error == 1 )
    {
      state->failed = 1;
      super->rec->reportError(super->rec);
      super->recover(super);
    }
    else
    {
      token = (ANTLR3_TOKEN_SOURCE_struct *)state->token;
      if ( !token )
      {
        emit(super);
        return state->token;
      }
      if ( token != (ANTLR3_TOKEN_SOURCE_struct *)&toksource->skipToken )
        return state->token;
    }
  }
  v9 = super->getCharIndex(super);
  toksource->eofToken.setStartIndex(&toksource->eofToken, v9);
  v10 = super->getCharIndex(super);
  toksource->eofToken.setStopIndex(&toksource->eofToken, v10);
  v11 = super->getLine(super);
  toksource->eofToken.setLine(&toksource->eofToken, v11);
  toksource->eofToken.factoryMade = 1;
  return &toksource->eofToken;
}

// File Line: 334
// RVA: 0x25E4F0
ANTLR3_COMMON_TOKEN_struct *__fastcall nextToken(ANTLR3_TOKEN_SOURCE_struct *toksource)
{
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  ANTLR3_COMMON_TOKEN_struct *p_eofToken; // rbx
  _QWORD *super; // rdi
  __int64 v5; // rdx
  __int64 v6; // rax
  ANTLR3_LEXER_struct *v7; // rdi
  ANTLR3_INPUT_STREAM_struct *input; // r14
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_INT_STREAM_struct *istream; // rbp
  int line; // eax
  ANTLR3_TOKEN_SOURCE_struct *token; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  unsigned int v15; // eax

  result = nextTokenStr(toksource);
  p_eofToken = result;
  if ( result->type == -1 )
  {
    do
    {
      super = toksource->super;
      v5 = *(_QWORD *)(super[3] + 16i64);
      v6 = *(_QWORD *)(v5 + 168);
      if ( !v6 || !(*(unsigned int (__fastcall **)(_QWORD))(v6 + 48))(*(_QWORD *)(v5 + 168)) )
        break;
      ((void (__fastcall *)(_QWORD *))super[6])(super);
      v7 = (ANTLR3_LEXER_struct *)toksource->super;
      input = v7->input;
      state = v7->rec->state;
      istream = input->istream;
      state->token = 0i64;
      state->error = 0;
      state->failed = 0;
      while ( 1 )
      {
        state->channel = 0;
        state->tokenStartCharIndex = (__int64)input->nextChar;
        state->tokenStartCharPositionInLine = input->charPositionInLine;
        line = input->line;
        state->text = 0i64;
        state->custom = 0i64;
        *(_QWORD *)&state->user1 = 0i64;
        state->user3 = 0;
        state->tokenStartLine = line;
        if ( istream->_LA(istream, 1) == -1 )
          break;
        state->token = 0i64;
        state->error = 0;
        state->failed = 0;
        v7->mTokens(v7->ctx);
        if ( state->error == 1 )
        {
          state->failed = 1;
          v7->rec->reportError(v7->rec);
          v7->recover(v7);
        }
        else
        {
          token = (ANTLR3_TOKEN_SOURCE_struct *)state->token;
          if ( !token )
          {
            emit(v7);
            p_eofToken = state->token;
            goto LABEL_13;
          }
          if ( token != (ANTLR3_TOKEN_SOURCE_struct *)&toksource->skipToken )
          {
            p_eofToken = state->token;
            goto LABEL_13;
          }
        }
      }
      p_eofToken = &toksource->eofToken;
      v13 = v7->getCharIndex(v7);
      toksource->eofToken.setStartIndex(&toksource->eofToken, v13);
      v14 = v7->getCharIndex(v7);
      toksource->eofToken.setStopIndex(&toksource->eofToken, v14);
      v15 = v7->getLine(v7);
      toksource->eofToken.setLine(&toksource->eofToken, v15);
      toksource->eofToken.factoryMade = 1;
LABEL_13:
      ;
    }
    while ( p_eofToken->type == -1 );
    return p_eofToken;
  }
  return result;
}

// File Line: 388
// RVA: 0x25ED00
ANTLR3_LEXER_struct *__fastcall antlr3LexerNewStream(
        unsigned int sizeHint,
        ANTLR3_INPUT_STREAM_struct *input,
        UFG::allocator::free_link *state)
{
  ANTLR3_LEXER_struct *result; // rax
  ANTLR3_LEXER_struct *v5; // rbx

  result = (ANTLR3_LEXER_struct *)antlr3LexerNew(sizeHint, state);
  v5 = result;
  if ( result )
  {
    setCharStream(result, input);
    return v5;
  }
  return result;
}

// File Line: 415
// RVA: 0x25E8F0
void __fastcall reportError_0(ANTLR3_BASE_RECOGNIZER_struct *rec)
{
  ++rec->state->errorCount;
  rec->displayRecognitionError(rec, rec->state->tokenNames);
}

// File Line: 427
// RVA: 0x25DFF0
void __fastcall displayRecognitionError_0(ANTLR3_BASE_RECOGNIZER_struct *recognizer, char **tokenNames)
{
  _QWORD *super; // rdi
  __int64 v3; // rbx
  __int64 v4; // rdi

  super = recognizer->super;
  v3 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 3) + 16i64) + 8i64);
  if ( *(_QWORD *)(v3 + 8) )
    (*(void (__fastcall **)(_QWORD, char **))(*(_QWORD *)(v3 + 24) + 176i64))(*(_QWORD *)(v3 + 24), tokenNames);
  v4 = super[2];
  if ( (int)(*(_DWORD *)(v4 + 16)
           - *(_DWORD *)(v3 + 40)
           + (*(__int64 (__fastcall **)(__int64, char **))(v4 + 144))(v4, tokenNames)) < 1 )
    (*(void (__fastcall **)(__int64))(v4 + 144))(v4);
  else
    isprint(*(_DWORD *)(v3 + 80));
}

// File Line: 492
// RVA: 0x25E9A0
void __fastcall setCharStream(ANTLR3_LEXER_struct *lexer, ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // r8
  ANTLR3_TOKEN_FACTORY_struct *tokFactory; // rax
  ANTLR3_TOKEN_SOURCE_struct *tokSource; // rdx
  ANTLR3_TOKEN_SOURCE_struct *v8; // rdx

  rec = lexer->rec;
  lexer->input = input;
  state = rec->state;
  tokFactory = state->tokFactory;
  if ( tokFactory )
    ((void (__fastcall *)(ANTLR3_TOKEN_FACTORY_struct *))tokFactory->setInputStream)(state->tokFactory);
  else
    lexer->rec->state->tokFactory = antlr3TokenFactoryNew(input);
  tokSource = lexer->rec->state->tokSource;
  if ( !tokSource->strFactory )
  {
    tokSource->strFactory = input->strFactory;
    v8 = lexer->rec->state->tokSource;
    if ( !v8->eofToken.strFactory )
      v8->eofToken.strFactory = input->strFactory;
  }
  lexer->rec->exConstruct = antlr3RecognitionExceptionNew;
  lexer->rec->state->token = 0i64;
  lexer->rec->state->text = 0i64;
  lexer->rec->state->tokenStartCharIndex = -1i64;
  lexer->rec->state->tokSource->fileName = input->fileName;
}

// File Line: 564
// RVA: 0x25E860
void __fastcall pushCharStream(ANTLR3_LEXER_struct *lexer, ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_STACK_struct *streams; // rcx

  if ( lexer->rec->state->streams || (lexer->rec->state->streams = (ANTLR3_STACK_struct *)antlr3StackNew(0)) != 0i64 )
  {
    lexer->input->istream->mark(lexer->input->istream);
    streams = lexer->rec->state->streams;
    streams->push(streams, lexer->input, 0i64);
    lexer->setCharStream(lexer, input);
  }
}

// File Line: 610
// RVA: 0x25E7F0
void __fastcall popCharStream(ANTLR3_LEXER_struct *lexer)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdx
  ANTLR3_STACK_struct *streams; // rax
  ANTLR3_STACK_struct *v4; // rcx
  ANTLR3_INPUT_STREAM_struct *top; // rbx

  state = lexer->rec->state;
  streams = state->streams;
  if ( streams )
  {
    if ( streams->size(state->streams) )
    {
      v4 = lexer->rec->state->streams;
      top = (ANTLR3_INPUT_STREAM_struct *)v4->top;
      v4->pop(v4);
      lexer->setCharStream(lexer, top);
      lexer->input->istream->rewindLast(lexer->input->istream);
    }
  }
}

// File Line: 636
// RVA: 0x25E1A0
void __fastcall emitNew(ANTLR3_LEXER_struct *lexer, ANTLR3_COMMON_TOKEN_struct *token)
{
  lexer->rec->state->token = token;
}

// File Line: 642
// RVA: 0x25E070
ANTLR3_COMMON_TOKEN_struct *__fastcall emit(ANTLR3_LEXER_struct *lexer)
{
  ANTLR3_TOKEN_FACTORY_struct *tokFactory; // rcx
  ANTLR3_COMMON_TOKEN_struct *v3; // rbx
  ANTLR3_COMMON_TOKEN_struct *result; // rax

  tokFactory = lexer->rec->state->tokFactory;
  v3 = tokFactory->newToken(tokFactory);
  v3->type = lexer->rec->state->type;
  v3->channel = lexer->rec->state->channel;
  v3->start = lexer->rec->state->tokenStartCharIndex;
  v3->stop = lexer->getCharIndex(lexer) - 1;
  v3->line = lexer->rec->state->tokenStartLine;
  v3->charPosition = lexer->rec->state->tokenStartCharPositionInLine;
  if ( lexer->rec->state->text )
  {
    v3->textState = 2;
    v3->tokText.chars = (unsigned int *)lexer->rec->state->text;
  }
  else
  {
    v3->textState = 0;
  }
  v3->lineStart = lexer->input->currentLine;
  v3->user1 = lexer->rec->state->user1;
  v3->user2 = lexer->rec->state->user2;
  v3->user3 = lexer->rec->state->user3;
  v3->custom = lexer->rec->state->custom;
  result = v3;
  lexer->rec->state->token = v3;
  return result;
}

// File Line: 688
// RVA: 0x25E1B0
void __fastcall freeLexer(ANTLR3_LEXER_struct *lexer)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax
  ANTLR3_STACK_struct *streams; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // rcx
  ANTLR3_TOKEN_FACTORY_struct *tokFactory; // rax
  char *tokSource; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rax

  state = lexer->rec->state;
  if ( state )
  {
    streams = state->streams;
    if ( streams )
      streams->free(streams);
    v4 = lexer->rec->state;
    tokFactory = v4->tokFactory;
    if ( tokFactory )
    {
      tokFactory->close(v4->tokFactory);
      lexer->rec->state->tokFactory = 0i64;
    }
    tokSource = (char *)lexer->rec->state->tokSource;
    if ( tokSource )
    {
      antlrFree(tokSource);
      lexer->rec->state->tokSource = 0i64;
    }
  }
  rec = lexer->rec;
  if ( rec )
  {
    rec->free(lexer->rec);
    lexer->rec = 0i64;
  }
  antlrFree((char *)lexer);
}

// File Line: 727
// RVA: 0x25E440
char __fastcall matchs(ANTLR3_LEXER_struct *lexer, unsigned int *string)
{
  unsigned int *v2; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rcx

  v2 = string;
  if ( *string == -1 )
    return 1;
  while ( lexer->input->istream->_LA(lexer->input->istream, 1) == *v2 )
  {
    lexer->input->istream->consume(lexer->input->istream);
    ++v2;
    lexer->rec->state->failed = 0;
    if ( *v2 == -1 )
      return 1;
  }
  rec = lexer->rec;
  state = rec->state;
  if ( state->backtracking <= 0 )
  {
    rec->exConstruct(lexer->rec);
    lexer->rec->state->failed = 1;
    lexer->recover(lexer);
  }
  else
  {
    state->failed = 1;
  }
  return 0;
}

// File Line: 770
// RVA: 0x25E3B0
char __fastcall matchc(ANTLR3_LEXER_struct *lexer, unsigned int c)
{
  char result; // al
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rcx

  if ( lexer->input->istream->_LA(lexer->input->istream, 1) == c )
  {
    lexer->input->istream->consume(lexer->input->istream);
    result = 1;
    lexer->rec->state->failed = 0;
  }
  else
  {
    rec = lexer->rec;
    state = rec->state;
    if ( state->backtracking <= 0 )
    {
      rec->exConstruct(lexer->rec);
      lexer->recover(lexer);
    }
    else
    {
      state->failed = 1;
    }
    return 0;
  }
  return result;
}

// File Line: 810
// RVA: 0x25E300
char __fastcall matchRange(ANTLR3_LEXER_struct *lexer, unsigned int low, unsigned int high)
{
  unsigned int v6; // eax
  char result; // al
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rcx

  v6 = lexer->input->istream->_LA(lexer->input->istream, 1);
  if ( v6 < low || v6 > high )
  {
    rec = lexer->rec;
    state = rec->state;
    if ( state->backtracking <= 0 )
    {
      rec->exConstruct(lexer->rec);
      lexer->recover(lexer);
    }
    else
    {
      state->failed = 1;
    }
    return 0;
  }
  else
  {
    lexer->input->istream->consume(lexer->input->istream);
    result = 1;
    lexer->rec->state->failed = 0;
  }
  return result;
}

// File Line: 849
// RVA: 0x25E2F0
void __fastcall recover_0(ANTLR3_LEXER_struct *lexer)
{
  lexer->input->istream->consume(lexer->input->istream);
}

// File Line: 861
// RVA: 0x25E270
__int64 __fastcall getLine_0(ANTLR3_LEXER_struct *lexer)
{
  return ((__int64 (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))lexer->input->getLine)(lexer->input);
}

// File Line: 867
// RVA: 0x25E260
__int64 __fastcall getCharPositionInLine_0(ANTLR3_LEXER_struct *lexer)
{
  return (unsigned int)lexer->input->charPositionInLine;
}

// File Line: 872
// RVA: 0x25E250
__int64 __fastcall getCharIndex(ANTLR3_LEXER_struct *lexer)
{
  return lexer->input->istream->index(lexer->input->istream);
}

// File Line: 878
// RVA: 0x25E280
ANTLR3_STRING_struct *__fastcall getText_2(ANTLR3_LEXER_struct *lexer)
{
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_INPUT_STREAM_struct *input; // rdi
  __int64 v4; // rax

  result = lexer->rec->state->text;
  if ( !result )
  {
    input = lexer->input;
    v4 = ((__int64 (*)(void))lexer->getCharIndex)();
    return input->substr(input, lexer->rec->state->tokenStartCharIndex, v4 - (unsigned __int8)input->charByteSize);
  }
  return result;
}

