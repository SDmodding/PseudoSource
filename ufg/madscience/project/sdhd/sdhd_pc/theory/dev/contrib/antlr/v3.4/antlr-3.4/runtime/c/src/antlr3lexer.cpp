// File Line: 76
// RVA: 0x25EA80
UFG::allocator::free_link *__fastcall antlr3LexerNew(unsigned int sizeHint, ANTLR3_RECOGNIZER_SHARED_STATE_struct *state)
{
  unsigned int v2; // esi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v3; // rbx
  UFG::allocator::free_link *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rdx
  UFG::allocator::free_link *v7; // rcx
  UFG::allocator::free_link *v9; // rbx
  signed __int64 v10; // rbx

  v2 = sizeHint;
  v3 = state;
  v4 = antlrMalloc(0xA0ui64);
  if ( !v4 )
    return 0i64;
  v5 = antlr3BaseRecognizerNew(1u, v2, v3);
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
    v6 = v4[3].mNext;
    v7 = v6[2].mNext[13].mNext;
    if ( !v7 )
    {
      ((void (__fastcall *)(UFG::allocator::free_link *))v6[36].mNext)(v4[3].mNext);
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
  ((void (__fastcall *)(UFG::allocator::free_link *, signed __int64))v9[21].mNext)(&v9[2], 0xFFFFFFFFi64);
  BYTE4(v9[2].mNext) = 1;
  v9[3].mNext = 0i64;
  LODWORD(v9[11].mNext) = 0;
  v9[15].mNext = 0i64;
  v9[13].mNext = 0i64;
  LODWORD(v9[14].mNext) = 0;
  v10 = (signed __int64)&v4[3].mNext[2].mNext[13].mNext[35];
  antlr3SetTokenAPI((ANTLR3_COMMON_TOKEN_struct *)v10);
  (*(void (__fastcall **)(signed __int64, _QWORD))(v10 + 152))(v10, 0i64);
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
  _QWORD *v1; // rdx
  __int64 v2; // rcx
  __int64 v3; // rax

  v1 = rec->super;
  *(_QWORD *)(*(_QWORD *)(*((_QWORD *)rec->super + 3) + 16i64) + 88i64) = 0i64;
  *(_DWORD *)(*(_QWORD *)(v1[3] + 16i64) + 116i64) = 0;
  *(_DWORD *)(*(_QWORD *)(v1[3] + 16i64) + 112i64) = 0;
  *(_QWORD *)(*(_QWORD *)(v1[3] + 16i64) + 128i64) = -1i64;
  *(_DWORD *)(*(_QWORD *)(v1[3] + 16i64) + 124i64) = -1;
  *(_DWORD *)(*(_QWORD *)(v1[3] + 16i64) + 120i64) = -1;
  *(_QWORD *)(*(_QWORD *)(v1[3] + 16i64) + 136i64) = 0i64;
  v2 = *(_QWORD *)(v1[3] + 16i64);
  v3 = *(_QWORD *)(v2 + 96);
  if ( v3 )
    (*(void (__fastcall **)(_QWORD))(v3 + 304))(*(_QWORD *)(v2 + 96));
}

// File Line: 221
// RVA: 0x25E6A0
ANTLR3_COMMON_TOKEN_struct *__fastcall nextTokenStr(ANTLR3_TOKEN_SOURCE_struct *toksource)
{
  ANTLR3_LEXER_struct *v1; // rdi
  ANTLR3_TOKEN_SOURCE_struct *v2; // rsi
  ANTLR3_INPUT_STREAM_struct *v3; // r14
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // rbx
  ANTLR3_INT_STREAM_struct *v5; // rbp
  int v6; // eax
  ANTLR3_TOKEN_SOURCE_struct *v7; // rcx
  __int64 v9; // rax
  __int64 v10; // rax
  unsigned int v11; // eax

  v1 = (ANTLR3_LEXER_struct *)toksource->super;
  v2 = toksource;
  v3 = v1->input;
  v4 = v1->rec->state;
  v5 = v3->istream;
  v4->token = 0i64;
  v4->error = 0;
  v4->failed = 0;
  while ( 1 )
  {
    v4->channel = 0;
    v4->tokenStartCharIndex = (__int64)v3->nextChar;
    v4->tokenStartCharPositionInLine = v3->charPositionInLine;
    v6 = v3->line;
    v4->text = 0i64;
    v4->custom = 0i64;
    *(_QWORD *)&v4->user1 = 0i64;
    v4->user3 = 0;
    v4->tokenStartLine = v6;
    if ( v5->_LA(v5, 1) == -1 )
      break;
    v4->token = 0i64;
    v4->error = 0;
    v4->failed = 0;
    v1->mTokens(v1->ctx);
    if ( v4->error == 1 )
    {
      v4->failed = 1;
      v1->rec->reportError(v1->rec);
      v1->recover(v1);
    }
    else
    {
      v7 = (ANTLR3_TOKEN_SOURCE_struct *)v4->token;
      if ( !v7 )
      {
        emit(v1);
        return v4->token;
      }
      if ( v7 != (ANTLR3_TOKEN_SOURCE_struct *)&v2->skipToken )
        return v4->token;
    }
  }
  v9 = v1->getCharIndex(v1);
  v2->eofToken.setStartIndex(&v2->eofToken, v9);
  v10 = v1->getCharIndex(v1);
  v2->eofToken.setStopIndex(&v2->eofToken, v10);
  v11 = v1->getLine(v1);
  v2->eofToken.setLine(&v2->eofToken, v11);
  v2->eofToken.factoryMade = 1;
  return &v2->eofToken;
}

// File Line: 334
// RVA: 0x25E4F0
ANTLR3_COMMON_TOKEN_struct *__fastcall nextToken(ANTLR3_TOKEN_SOURCE_struct *toksource)
{
  ANTLR3_TOKEN_SOURCE_struct *v1; // rsi
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  ANTLR3_COMMON_TOKEN_struct *v3; // rbx
  _QWORD *v4; // rdi
  __int64 v5; // rdx
  __int64 v6; // rax
  ANTLR3_LEXER_struct *v7; // rdi
  ANTLR3_INPUT_STREAM_struct *v8; // r14
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v9; // rbx
  ANTLR3_INT_STREAM_struct *v10; // rbp
  int v11; // eax
  ANTLR3_TOKEN_SOURCE_struct *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  unsigned int v15; // eax

  v1 = toksource;
  result = nextTokenStr(toksource);
  v3 = result;
  if ( result->type == -1 )
  {
    do
    {
      v4 = v1->super;
      v5 = *(_QWORD *)(v4[3] + 16i64);
      v6 = *(_QWORD *)(v5 + 168);
      if ( !v6 || !(*(unsigned int (__fastcall **)(_QWORD))(v6 + 48))(*(_QWORD *)(v5 + 168)) )
        break;
      ((void (__fastcall *)(_QWORD *))v4[6])(v4);
      v7 = (ANTLR3_LEXER_struct *)v1->super;
      v8 = v7->input;
      v9 = v7->rec->state;
      v10 = v8->istream;
      v9->token = 0i64;
      v9->error = 0;
      v9->failed = 0;
      while ( 1 )
      {
        v9->channel = 0;
        v9->tokenStartCharIndex = (__int64)v8->nextChar;
        v9->tokenStartCharPositionInLine = v8->charPositionInLine;
        v11 = v8->line;
        v9->text = 0i64;
        v9->custom = 0i64;
        *(_QWORD *)&v9->user1 = 0i64;
        v9->user3 = 0;
        v9->tokenStartLine = v11;
        if ( v10->_LA(v10, 1) == -1 )
          break;
        v9->token = 0i64;
        v9->error = 0;
        v9->failed = 0;
        v7->mTokens(v7->ctx);
        if ( v9->error == 1 )
        {
          v9->failed = 1;
          v7->rec->reportError(v7->rec);
          v7->recover(v7);
        }
        else
        {
          v12 = (ANTLR3_TOKEN_SOURCE_struct *)v9->token;
          if ( !v12 )
          {
            emit(v7);
            v3 = v9->token;
            goto LABEL_13;
          }
          if ( v12 != (ANTLR3_TOKEN_SOURCE_struct *)&v1->skipToken )
          {
            v3 = v9->token;
            goto LABEL_13;
          }
        }
      }
      v3 = &v1->eofToken;
      v13 = v7->getCharIndex(v7);
      v1->eofToken.setStartIndex(&v1->eofToken, v13);
      v14 = v7->getCharIndex(v7);
      v1->eofToken.setStopIndex(&v1->eofToken, v14);
      v15 = v7->getLine(v7);
      v1->eofToken.setLine(&v1->eofToken, v15);
      v1->eofToken.factoryMade = 1;
LABEL_13:
      ;
    }
    while ( v3->type == -1 );
    result = v3;
  }
  return result;
}

// File Line: 388
// RVA: 0x25ED00
ANTLR3_LEXER_struct *__fastcall antlr3LexerNewStream(unsigned int sizeHint, ANTLR3_INPUT_STREAM_struct *input, ANTLR3_RECOGNIZER_SHARED_STATE_struct *state)
{
  ANTLR3_INPUT_STREAM_struct *v3; // rdi
  ANTLR3_LEXER_struct *result; // rax
  ANTLR3_LEXER_struct *v5; // rbx

  v3 = input;
  result = (ANTLR3_LEXER_struct *)antlr3LexerNew(sizeHint, state);
  v5 = result;
  if ( result )
  {
    setCharStream(result, v3);
    result = v5;
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
  _QWORD *v2; // rdi
  __int64 v3; // rbx
  __int64 v4; // rdi

  v2 = recognizer->super;
  v3 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 3) + 16i64) + 8i64);
  if ( *(_QWORD *)(v3 + 8) )
    (*(void (__fastcall **)(_QWORD, char **))(*(_QWORD *)(v3 + 24) + 176i64))(*(_QWORD *)(v3 + 24), tokenNames);
  v4 = v2[2];
  if ( (signed int)(*(_DWORD *)(v4 + 16)
                  - *(_DWORD *)(v3 + 40)
                  + (unsigned __int64)(*(__int64 (__fastcall **)(__int64, char **))(v4 + 144))(v4, tokenNames)) < 1 )
    (*(void (__fastcall **)(__int64))(v4 + 144))(v4);
  else
    isprint(*(_DWORD *)(v3 + 80));
}

// File Line: 492
// RVA: 0x25E9A0
void __fastcall setCharStream(ANTLR3_LEXER_struct *lexer, ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_BASE_RECOGNIZER_struct *v2; // rax
  ANTLR3_INPUT_STREAM_struct *v3; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // r8
  ANTLR3_LEXER_struct *v5; // rbx
  ANTLR3_TOKEN_FACTORY_struct *v6; // rax
  ANTLR3_TOKEN_SOURCE_struct *v7; // rdx
  ANTLR3_TOKEN_SOURCE_struct *v8; // rdx

  v2 = lexer->rec;
  lexer->input = input;
  v3 = input;
  v4 = v2->state;
  v5 = lexer;
  v6 = v4->tokFactory;
  if ( v6 )
    ((void (__fastcall *)(ANTLR3_TOKEN_FACTORY_struct *))v6->setInputStream)(v4->tokFactory);
  else
    lexer->rec->state->tokFactory = antlr3TokenFactoryNew(input);
  v7 = v5->rec->state->tokSource;
  if ( !v7->strFactory )
  {
    v7->strFactory = v3->strFactory;
    v8 = v5->rec->state->tokSource;
    if ( !v8->eofToken.strFactory )
      v8->eofToken.strFactory = v3->strFactory;
  }
  v5->rec->exConstruct = antlr3RecognitionExceptionNew;
  v5->rec->state->token = 0i64;
  v5->rec->state->text = 0i64;
  v5->rec->state->tokenStartCharIndex = -1i64;
  v5->rec->state->tokSource->fileName = v3->fileName;
}

// File Line: 564
// RVA: 0x25E860
void __fastcall pushCharStream(ANTLR3_LEXER_struct *lexer, ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_INPUT_STREAM_struct *v2; // rdi
  ANTLR3_LEXER_struct *v3; // rbx
  ANTLR3_STACK_struct *v4; // rcx

  v2 = input;
  v3 = lexer;
  if ( lexer->rec->state->streams
    || (lexer->rec->state->streams = (ANTLR3_STACK_struct *)antlr3StackNew(0), v3->rec->state->streams) )
  {
    v3->input->istream->mark(v3->input->istream);
    v4 = v3->rec->state->streams;
    v4->push(v4, v3->input, 0i64);
    v3->setCharStream(v3, v2);
  }
}

// File Line: 610
// RVA: 0x25E7F0
void __fastcall popCharStream(ANTLR3_LEXER_struct *lexer)
{
  ANTLR3_LEXER_struct *v1; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rdx
  ANTLR3_STACK_struct *v3; // rax
  ANTLR3_STACK_struct *v4; // rcx
  ANTLR3_INPUT_STREAM_struct *v5; // rbx

  v1 = lexer;
  v2 = lexer->rec->state;
  v3 = v2->streams;
  if ( v3 )
  {
    if ( v3->size(v2->streams) )
    {
      v4 = v1->rec->state->streams;
      v5 = (ANTLR3_INPUT_STREAM_struct *)v4->top;
      v4->pop(v4);
      v1->setCharStream(v1, v5);
      v1->input->istream->rewindLast(v1->input->istream);
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
  ANTLR3_LEXER_struct *v1; // rdi
  ANTLR3_TOKEN_FACTORY_struct *v2; // rcx
  ANTLR3_COMMON_TOKEN_struct *v3; // rbx
  ANTLR3_COMMON_TOKEN_struct *result; // rax

  v1 = lexer;
  v2 = lexer->rec->state->tokFactory;
  v3 = v2->newToken(v2);
  v3->type = v1->rec->state->type;
  v3->channel = v1->rec->state->channel;
  v3->start = v1->rec->state->tokenStartCharIndex;
  v3->stop = v1->getCharIndex(v1) - 1;
  v3->line = v1->rec->state->tokenStartLine;
  v3->charPosition = v1->rec->state->tokenStartCharPositionInLine;
  if ( v1->rec->state->text )
  {
    v3->textState = 2;
    v3->tokText.chars = (unsigned int *)v1->rec->state->text;
  }
  else
  {
    v3->textState = 0;
  }
  v3->lineStart = v1->input->currentLine;
  v3->user1 = v1->rec->state->user1;
  v3->user2 = v1->rec->state->user2;
  v3->user3 = v1->rec->state->user3;
  v3->custom = v1->rec->state->custom;
  result = v3;
  v1->rec->state->token = v3;
  return result;
}

// File Line: 688
// RVA: 0x25E1B0
void __fastcall freeLexer(ANTLR3_LEXER_struct *lexer)
{
  ANTLR3_LEXER_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax
  ANTLR3_STACK_struct *v3; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // rcx
  ANTLR3_TOKEN_FACTORY_struct *v5; // rax
  ANTLR3_TOKEN_SOURCE_struct *v6; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v7; // rax

  v1 = lexer;
  v2 = lexer->rec->state;
  if ( v2 )
  {
    v3 = v2->streams;
    if ( v3 )
      v3->free(v3);
    v4 = v1->rec->state;
    v5 = v4->tokFactory;
    if ( v5 )
    {
      v5->close(v4->tokFactory);
      v1->rec->state->tokFactory = 0i64;
    }
    v6 = v1->rec->state->tokSource;
    if ( v6 )
    {
      antlrFree(v6);
      v1->rec->state->tokSource = 0i64;
    }
  }
  v7 = v1->rec;
  if ( v7 )
  {
    v7->free(v1->rec);
    v1->rec = 0i64;
  }
  antlrFree(v1);
}

// File Line: 727
// RVA: 0x25E440
char __fastcall matchs(ANTLR3_LEXER_struct *lexer, unsigned int *string)
{
  unsigned int *v2; // rdi
  ANTLR3_LEXER_struct *v3; // rbx
  ANTLR3_BASE_RECOGNIZER_struct *v5; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v6; // rcx

  v2 = string;
  v3 = lexer;
  if ( *string == -1 )
    return 1;
  while ( v3->input->istream->_LA(v3->input->istream, 1) == *v2 )
  {
    v3->input->istream->consume(v3->input->istream);
    ++v2;
    v3->rec->state->failed = 0;
    if ( *v2 == -1 )
      return 1;
  }
  v5 = v3->rec;
  v6 = v5->state;
  if ( v6->backtracking <= 0 )
  {
    v5->exConstruct(v3->rec);
    v3->rec->state->failed = 1;
    v3->recover(v3);
  }
  else
  {
    v6->failed = 1;
  }
  return 0;
}

// File Line: 770
// RVA: 0x25E3B0
char __fastcall matchc(ANTLR3_LEXER_struct *lexer, unsigned int c)
{
  ANTLR3_LEXER_struct *v2; // rdi
  char result; // al
  ANTLR3_BASE_RECOGNIZER_struct *v4; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v5; // rcx

  v2 = lexer;
  if ( lexer->input->istream->_LA(lexer->input->istream, 1) == c )
  {
    v2->input->istream->consume(v2->input->istream);
    result = 1;
    v2->rec->state->failed = 0;
  }
  else
  {
    v4 = v2->rec;
    v5 = v4->state;
    if ( v5->backtracking <= 0 )
    {
      v4->exConstruct(v2->rec);
      v2->recover(v2);
    }
    else
    {
      v5->failed = 1;
    }
    result = 0;
  }
  return result;
}

// File Line: 810
// RVA: 0x25E300
char __fastcall matchRange(ANTLR3_LEXER_struct *lexer, unsigned int low, unsigned int high)
{
  unsigned int v3; // ebx
  ANTLR3_LEXER_struct *v4; // rdi
  unsigned int v5; // esi
  unsigned int v6; // eax
  char result; // al
  ANTLR3_BASE_RECOGNIZER_struct *v8; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v9; // rcx

  v3 = low;
  v4 = lexer;
  v5 = high;
  v6 = lexer->input->istream->_LA(lexer->input->istream, 1);
  if ( v6 < v3 || v6 > v5 )
  {
    v8 = v4->rec;
    v9 = v8->state;
    if ( v9->backtracking <= 0 )
    {
      v8->exConstruct(v4->rec);
      v4->recover(v4);
    }
    else
    {
      v9->failed = 1;
    }
    result = 0;
  }
  else
  {
    v4->input->istream->consume(v4->input->istream);
    result = 1;
    v4->rec->state->failed = 0;
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
  return lexer->input->getLine(lexer->input);
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
  ANTLR3_LEXER_struct *v1; // rsi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_INPUT_STREAM_struct *v3; // rdi
  __int64 v4; // rax

  v1 = lexer;
  result = lexer->rec->state->text;
  if ( !result )
  {
    v3 = lexer->input;
    v4 = ((__int64 (*)(void))lexer->getCharIndex)();
    result = v3->substr(v3, v1->rec->state->tokenStartCharIndex, v4 - (unsigned __int8)v3->charByteSize);
  }
  return result;
}

