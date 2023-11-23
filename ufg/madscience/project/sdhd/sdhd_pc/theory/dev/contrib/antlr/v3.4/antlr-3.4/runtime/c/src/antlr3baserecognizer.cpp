// File Line: 15
// RVA: 0x254E00
UFG::allocator::free_link *__fastcall antlrCalloc(unsigned int numEl, unsigned int elSize)
{
  UFG::allocator::free_link *v3; // rbx

  v3 = UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, numEl * elSize, "ANTLR_CALLOC", 0i64, 1u);
  UFG::qMemSet(v3, 0, elSize);
  return v3;
}

// File Line: 21
// RVA: 0x254EC0
UFG::allocator::free_link *__fastcall antlrStrdup(const char *s)
{
  unsigned int v2; // edi
  UFG::allocator::free_link *v3; // rbx

  v2 = UFG::qStringLength(s);
  v3 = UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, v2, "ANTLR3_STRDUP", 0i64, 1u);
  UFG::qMemCopy(v3, s, v2);
  return v3;
}

// File Line: 28
// RVA: 0x254E90
UFG::allocator::free_link *__fastcall antlrRealloc(void *current, unsigned __int64 request)
{
  return UFG::qMemoryPool::Realloc(&gAntlrMemoryPool, current, request, "ANTLR_REALLOC", 0i64);
}

// File Line: 32
// RVA: 0x254E60
UFG::allocator::free_link *__fastcall antlrMalloc(unsigned __int64 request)
{
  return UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, request, "ANTLR_MALLOC", 0i64, 1u);
}

// File Line: 36
// RVA: 0x254E50
void __fastcall antlrFree(char *mem)
{
  UFG::qMemoryPool::Free(&gAntlrMemoryPool, mem);
}

// File Line: 121
// RVA: 0x255EE0
UFG::allocator::free_link *__fastcall antlr3BaseRecognizerNew(
        unsigned int type,
        unsigned int sizeHint,
        UFG::allocator::free_link *state)
{
  UFG::allocator::free_link *result; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v7; // rbx
  UFG::allocator::free_link *v8; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v9; // rdx

  result = UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, 0x128ui64, "ANTLR_MALLOC", 0i64, 1u);
  v7 = (ANTLR3_BASE_RECOGNIZER_struct *)result;
  if ( result )
  {
    if ( state )
    {
      result[2].mNext = state;
    }
    else
    {
      v8 = UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, 0xB8ui64, "ANTLR_CALLOC", 0i64, 1u);
      UFG::qMemSet(v8, 0, 0xB8u);
      v7->state = (ANTLR3_RECOGNIZER_SHARED_STATE_struct *)v8;
      if ( !v8 )
      {
LABEL_6:
        UFG::qMemoryPool::Free(&gAntlrMemoryPool, (char *)v7);
        return 0i64;
      }
      LOBYTE(v8[4].mNext) = 0;
      v7->state->lastErrorIndex = -1i64;
      v7->state->failed = 0;
      v7->state->errorCount = 0;
      v7->state->backtracking = 0;
      v7->state->following = 0i64;
      v7->state->ruleMemo = 0i64;
      v7->state->tokenNames = 0i64;
      v7->state->sizeHint = sizeHint;
      v7->state->tokSource = 0i64;
      v7->state->tokFactory = 0i64;
      v7->state->rStreams = antlr3VectorNew(0);
      v9 = v7->state;
      if ( !v9->rStreams )
      {
        UFG::qMemoryPool::Free(&gAntlrMemoryPool, &v9->error);
        goto LABEL_6;
      }
    }
    v7->debugger = 0i64;
    v7->type = type;
    v7->alreadyParsedRule = (char (__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, __int64))alreadyParsedRule;
    v7->beginResync = beginResync;
    v7->combineFollows = combineFollows;
    v7->beginBacktrack = (void (__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, unsigned int))beginBacktrack;
    v7->endBacktrack = (void (__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, unsigned int, char))endBacktrack;
    v7->computeCSRuleFollow = computeErrorRecoverySet;
    v7->computeErrorRecoverySet = computeErrorRecoverySet;
    v7->consumeUntil = consumeUntil;
    v7->consumeUntilSet = consumeUntilSet;
    v7->displayRecognitionError = displayRecognitionError;
    v7->endResync = endResync;
    v7->exConstruct = antlr3MTExceptionNew;
    v7->getRuleInvocationStack = (ANTLR3_STACK_struct *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *))TargetVisibleInAIDataCondition::CreateClone;
    v7->getRuleInvocationStackNamed = (ANTLR3_STACK_struct *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, char *))TargetVisibleInAIDataCondition::CreateClone;
    v7->getRuleMemoization = getRuleMemoization;
    v7->match = match;
    v7->matchAny = matchAny;
    v7->memoize = (void (__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, __int64, __int64))memoize;
    v7->mismatch = mismatch;
    v7->mismatchIsUnwantedToken = mismatchIsUnwantedToken;
    v7->mismatchIsMissingToken = mismatchIsMissingToken;
    v7->recover = recover;
    v7->recoverFromMismatchedElement = recoverFromMismatchedElement;
    v7->recoverFromMismatchedSet = recoverFromMismatchedSet;
    v7->recoverFromMismatchedToken = recoverFromMismatchedToken;
    v7->getNumberOfSyntaxErrors = (unsigned int (__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *))getNumberOfSyntaxErrors;
    v7->reportError = reportError;
    v7->reset = reset;
    v7->synpred = (char (__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, void *, void (__fastcall *)(void *)))synpred;
    v7->toStrings = (ANTLR3_HASH_TABLE_struct *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, ANTLR3_HASH_TABLE_struct *))TargetVisibleInAIDataCondition::CreateClone;
    v7->getCurrentInputSymbol = (void *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, ANTLR3_INT_STREAM_struct *))getCurrentInputSymbol;
    v7->getMissingSymbol = (void *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, ANTLR3_INT_STREAM_struct *, ANTLR3_EXCEPTION_struct *, unsigned int, ANTLR3_BITSET_LIST_struct *))getMissingSymbol;
    v7->free = freeBR;
    return (UFG::allocator::free_link *)v7;
  }
  return result;
}>free = freeBR;
    return (UFG::allocator::free_link *)v7;


// File Line: 235
// RVA: 0x255270
void __fastcall freeBR(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax
  ANTLR3_INT_TRIE_struct *ruleMemo; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // rax
  ANTLR3_EXCEPTION_struct *exception; // rdx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v6; // rax
  ANTLR3_VECTOR_struct *rStreams; // rdx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v8; // rax
  ANTLR3_TOKEN_FACTORY_struct *tokFactory; // rdx

  state = recognizer->state;
  if ( state )
  {
    ruleMemo = state->ruleMemo;
    if ( ruleMemo )
    {
      ruleMemo->free(ruleMemo);
      recognizer->state->ruleMemo = 0i64;
    }
    v4 = recognizer->state;
    exception = v4->exception;
    if ( exception )
      exception->freeEx(v4->exception);
    v6 = recognizer->state;
    rStreams = v6->rStreams;
    if ( rStreams )
      rStreams->free(v6->rStreams);
    v8 = recognizer->state;
    tokFactory = v8->tokFactory;
    if ( tokFactory )
      tokFactory->close(v8->tokFactory);
    UFG::qMemoryPool::Free(&gAntlrMemoryPool, &recognizer->state->error);
  }
  UFG::qMemoryPool::Free(&gAntlrMemoryPool, (char *)recognizer);
}

// File Line: 291
// RVA: 0x2561F0
void __fastcall antlr3MTExceptionNew(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  antlr3RecognitionExceptionNew(recognizer);
  recognizer->state->exception->name = "org.antlr.runtime.MismatchedTokenException";
  recognizer->state->exception->type = 2;
}

// File Line: 306
// RVA: 0x256230
void __fastcall antlr3RecognitionExceptionNew(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  __int64 *v2; // r14
  _QWORD *v3; // r15
  __int64 v4; // rbp
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  __int64 v7; // rsi
  __int64 v8; // rcx
  ANTLR3_EXCEPTION_struct *v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rax
  _QWORD *v12; // rcx
  __int64 v13; // rax
  const char *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  _QWORD *token; // rax
  ANTLR3_STRING_struct *v18; // rcx

  v2 = 0i64;
  v3 = 0i64;
  v4 = 0i64;
  v5 = recognizer->type - 1;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 != 2 )
        return;
      v4 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64);
      v7 = *(_QWORD *)(v4 + 8);
    }
    else
    {
      v8 = *((_QWORD *)recognizer->super + 2);
      v3 = *(_QWORD **)(v8 + 8);
      v7 = *(_QWORD *)(v8 + 16);
    }
  }
  else
  {
    v2 = (__int64 *)*((_QWORD *)recognizer->super + 2);
    v7 = *v2;
  }
  v9 = antlr3ExceptionNew(1u, "org.antlr.runtime.RecognitionException", 0i64, 0);
  switch ( *(_DWORD *)v7 & 7 )
  {
    case 1:
      v9->c = (*(__int64 (__fastcall **)(__int64, __int64))(v7 + 48))(v7, 1i64);
      v9->line = ((__int64 (__fastcall *)(__int64 *))v2[20])(v2);
      v9->charPositionInLine = ((__int64 (__fastcall *)(__int64 *))v2[22])(v2);
      v9->index = (*(__int64 (__fastcall **)(__int64))(v7 + 64))(v7);
      v9->streamName = (ANTLR3_STRING_struct *)v2[10];
      v14 = "Unexpected character";
LABEL_20:
      v9->message = (void *)v14;
      break;
    case 2:
      v16 = (*(__int64 (__fastcall **)(_QWORD, __int64))(*v3 + 40i64))(*v3, 1i64);
      v9->token = (void *)v16;
      v9->line = (*(__int64 (__fastcall **)(__int64))(v16 + 160))(v16);
      v9->charPositionInLine = (*((__int64 (__fastcall **)(void *))v9->token + 22))(v9->token);
      v9->index = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*v3 + 16i64) + 64i64))(*(_QWORD *)(*v3 + 16i64));
      token = v9->token;
      if ( *(_DWORD *)token == -1 )
      {
        v9->streamName = 0i64;
        v14 = "Unexpected token";
      }
      else
      {
        v18 = *(ANTLR3_STRING_struct **)(token[5] + 80i64);
        v14 = "Unexpected token";
        v9->streamName = v18;
      }
      goto LABEL_20;
    case 4:
      v10 = (*(__int64 (__fastcall **)(__int64, __int64))(v4 + 16))(v4, 1i64);
      v9->token = (void *)v10;
      v9->line = (*(__int64 (__fastcall **)(__int64))(v10 + 176))(v10);
      v9->charPositionInLine = (*((__int64 (__fastcall **)(void *))v9->token + 13))(v9->token);
      v11 = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v4 + 8) + 64i64))(*(_QWORD *)(v4 + 8));
      v12 = v9->token;
      v9->index = v11;
      v13 = *(_QWORD *)(*v12 + 24i64);
      if ( v13 )
      {
        v15 = *(_QWORD *)(v13 + 40);
        if ( v15 )
          v9->streamName = *(ANTLR3_STRING_struct **)(v15 + 80);
        else
          v9->streamName = 0i64;
        v14 = "Unexpected node";
      }
      else
      {
        v9->streamName = (ANTLR3_STRING_struct *)(*(__int64 (__fastcall **)(_QWORD, const char *))(v12[4] + 48i64))(
                                                   v12[4],
                                                   "-unknown source-");
        v14 = "Unexpected node";
      }
      goto LABEL_20;
  }
  v9->input = (ANTLR3_INT_STREAM_struct *)v7;
  v9->nextException = recognizer->state->exception;
  recognizer->state->exception = v9;
  recognizer->state->error = 1;
}

// File Line: 453
// RVA: 0x255510
void *__fastcall match(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        unsigned int ttype,
        ANTLR3_BITSET_LIST_struct *follow)
{
  unsigned int type; // eax
  void *result; // rax
  __int64 v8; // rdi
  void *v9; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  type = recognizer->type;
  if ( type == 2 )
  {
    v8 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return 0i64;
    v8 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  v9 = recognizer->getCurrentInputSymbol(recognizer, v8);
  if ( (*(unsigned int (__fastcall **)(__int64, __int64))(v8 + 48))(v8, 1i64) == ttype )
  {
    (*(void (__fastcall **)(__int64))(v8 + 40))(v8);
    result = v9;
    recognizer->state->errorRecovery = 0;
    recognizer->state->failed = 0;
  }
  else
  {
    state = recognizer->state;
    if ( state->backtracking <= 0 )
    {
      return recognizer->recoverFromMismatchedToken(recognizer, ttype, follow);
    }
    else
    {
      state->failed = 1;
      return v9;
    }
  }
  return result;
}

// File Line: 526
// RVA: 0x2555E0
void __fastcall matchAny(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  unsigned int type; // eax
  __int64 v2; // rdx

  type = recognizer->type;
  if ( type == 2 )
  {
    v2 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return;
    v2 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  recognizer->state->errorRecovery = 0;
  recognizer->state->failed = 0;
  (*(void (__fastcall **)(__int64))(v2 + 40))(v2);
}

// File Line: 566
// RVA: 0x255900
char __fastcall mismatchIsUnwantedToken(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        ANTLR3_INT_STREAM_struct *is,
        unsigned int ttype)
{
  unsigned int v5; // eax
  ANTLR3_EXCEPTION_struct *exception; // rdx

  v5 = is->_LA(is, 2);
  if ( v5 != ttype )
    return 0;
  exception = recognizer->state->exception;
  if ( exception )
    exception->expecting = v5;
  return 1;
}

// File Line: 589
// RVA: 0x255830
char __fastcall mismatchIsMissingToken(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        ANTLR3_INT_STREAM_struct *is,
        ANTLR3_BITSET_LIST_struct *follow)
{
  ANTLR3_BITSET_struct *v5; // rax
  ANTLR3_BITSET_struct *v6; // rdi
  ANTLR3_BITSET_struct *v7; // rbx
  unsigned int v8; // eax
  bool v9; // si

  if ( follow )
  {
    v6 = 0i64;
    v5 = antlr3BitsetLoad(follow);
    v7 = v5;
    if ( v5 )
    {
      if ( v5->isMember(v5, 1u) )
      {
        v7->remove(v7, 1u);
        v6 = recognizer->computeCSRuleFollow(recognizer);
        v7->borInPlace(v7, v6);
      }
      v8 = is->_LA(is, 1);
      v9 = v7->isMember(v7, v8) || v7->isMember(v7, 1u);
      if ( v6 )
        v6->free(v6);
      v7->free(v7);
      LOBYTE(v5) = v9;
    }
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  return (char)v5;
}

// File Line: 679
// RVA: 0x255700
void __fastcall mismatch(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        unsigned int ttype,
        ANTLR3_BITSET_LIST_struct *follow)
{
  __int64 v6; // rdi
  unsigned int v7; // eax
  ANTLR3_EXCEPTION_struct *exception; // rdx

  antlr3RecognitionExceptionNew(recognizer);
  recognizer->state->exception->name = "org.antlr.runtime.MismatchedTokenException";
  recognizer->state->exception->type = 2;
  recognizer->state->exception->expecting = ttype;
  if ( recognizer->type == 2 )
  {
    v6 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
    v7 = (*(__int64 (__fastcall **)(__int64, __int64))(v6 + 48))(v6, 2i64);
    if ( v7 == ttype )
    {
      exception = recognizer->state->exception;
      if ( exception )
        exception->expecting = v7;
      antlr3RecognitionExceptionNew(recognizer);
      recognizer->state->exception->name = "org.antlr.runtime.UnwantedTokenException";
      recognizer->state->exception->type = 9;
    }
    else if ( mismatchIsMissingToken(recognizer, (ANTLR3_INT_STREAM_struct *)v6, follow) )
    {
      antlr3RecognitionExceptionNew(recognizer);
      recognizer->state->exception->name = "org.antlr.runtime.MissingTokenException";
      recognizer->state->exception->type = 10;
    }
    else
    {
      antlr3RecognitionExceptionNew(recognizer);
      recognizer->state->exception->name = "org.antlr.runtime.MismatchedTokenException";
      recognizer->state->exception->type = 2;
    }
  }
}

// File Line: 758
// RVA: 0x255D40
void __fastcall reportError(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  debugger = recognizer->debugger;
  if ( debugger )
    debugger->recognitionException(recognizer->debugger, recognizer->state->exception);
  state = recognizer->state;
  if ( state->errorRecovery != 1 )
  {
    state->errorRecovery = 1;
    ++recognizer->state->errorCount;
    recognizer->displayRecognitionError(recognizer, recognizer->state->tokenNames);
  }
}

// File Line: 788
// RVA: 0x254F20
void __fastcall beginBacktrack(ANTLR3_BASE_RECOGNIZER_struct *recognizer, __int64 level)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger; // rax

  debugger = recognizer->debugger;
  if ( debugger )
    debugger->beginBacktrack(recognizer->debugger, level);
}

// File Line: 797
// RVA: 0x255230
void __fastcall endBacktrack(ANTLR3_BASE_RECOGNIZER_struct *recognizer, __int64 level, __int64 successful)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger; // rax

  debugger = recognizer->debugger;
  if ( debugger )
    debugger->endBacktrack(recognizer->debugger, level, successful);
}

// File Line: 805
// RVA: 0x254F40
void __fastcall beginResync(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger; // rax

  debugger = recognizer->debugger;
  if ( debugger )
    debugger->beginResync(recognizer->debugger);
}

// File Line: 814
// RVA: 0x255250
void __fastcall endResync(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger; // rax

  debugger = recognizer->debugger;
  if ( debugger )
    debugger->endResync(recognizer->debugger);
}

// File Line: 976
// RVA: 0x255040
ANTLR3_BITSET_struct *__fastcall computeErrorRecoverySet(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  return recognizer->combineFollows(recognizer, 0i64);
}

// File Line: 984
// RVA: 0x254F60
ANTLR3_BITSET_struct *__fastcall combineFollows(ANTLR3_BASE_RECOGNIZER_struct *recognizer, char exact)
{
  unsigned int v4; // esi
  ANTLR3_BITSET_struct *result; // rax
  ANTLR3_BITSET_struct *v6; // rdi
  unsigned int v7; // ebp
  ANTLR3_BITSET_LIST_struct *v8; // rax
  ANTLR3_BITSET_struct *v9; // rax
  ANTLR3_BITSET_struct *v10; // rbx

  v4 = recognizer->state->following->size(recognizer->state->following);
  result = antlr3BitsetNew(0);
  v6 = result;
  if ( v4 )
  {
    do
    {
      v7 = v4 - 1;
      v8 = (ANTLR3_BITSET_LIST_struct *)recognizer->state->following->get(recognizer->state->following, v4 - 1);
      v9 = antlr3BitsetLoad(v8);
      v10 = v9;
      if ( v9 )
      {
        v6->borInPlace(v6, v9);
        if ( exact == 1 )
        {
          if ( v10->isMember(v10, 1u) )
            break;
          if ( v4 > 1 )
            v6->remove(v6, 1u);
        }
        v10->free(v10);
        v10 = 0i64;
      }
      --v4;
    }
    while ( v7 );
    if ( v10 )
      v10->free(v10);
    return v6;
  }
  return result;
}

// File Line: 1045
// RVA: 0x255140
void __fastcall displayRecognitionError(ANTLR3_BASE_RECOGNIZER_struct *recognizer, char **tokenNames)
{
  ANTLR3_EXCEPTION_struct *exception; // rsi
  ANTLR3_STRING_struct *streamName; // rax
  unsigned int type; // eax
  void (__fastcall **v7)(void *); // rbx
  void (__fastcall **token)(void *); // rcx
  unsigned int v9; // edi
  ANTLR3_BITSET_struct *v10; // rbx
  unsigned int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // edx
  char **v14; // rcx

  exception = recognizer->state->exception;
  streamName = exception->streamName;
  if ( streamName )
    streamName->to8(exception->streamName);
  type = recognizer->type;
  if ( type == 2 )
  {
    token = (void (__fastcall **)(void *))recognizer->state->exception->token;
    token[32](token);
  }
  else
  {
    if ( type != 4 )
      return;
    v7 = (void (__fastcall **)(void *))recognizer->state->exception->token;
    v7[26](v7);
    if ( *v7 )
      v7[5](v7);
  }
  if ( exception->type == 4 )
  {
    v9 = 0;
    v10 = antlr3BitsetLoad(exception->expectingSet);
    v11 = v10->numBits(v10);
    v12 = v10->size(v10);
    if ( v12 )
    {
      v13 = 1;
      if ( v11 > 1 )
      {
        v14 = tokenNames + 1;
        do
        {
          if ( v9 >= 8 || v9 >= v12 )
            break;
          if ( *v14 )
            ++v9;
          ++v13;
          ++v14;
        }
        while ( v13 < v11 );
      }
    }
  }
}

// File Line: 1347
// RVA: 0x255460
__int64 __fastcall getNumberOfSyntaxErrors(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  return recognizer->state->errorCount;
}

// File Line: 1357
// RVA: 0x255950
void __fastcall recover(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  unsigned int type; // eax
  __int64 v3; // rbx
  ANTLR3_BITSET_struct *v4; // rbx

  type = recognizer->type;
  if ( type == 2 )
  {
    v3 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return;
    v3 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  if ( recognizer->state->lastErrorIndex == (*(__int64 (__fastcall **)(__int64))(v3 + 64))(v3) )
    (*(void (__fastcall **)(__int64))(v3 + 40))(v3);
  recognizer->state->lastErrorIndex = (*(__int64 (__fastcall **)(__int64))(v3 + 64))(v3);
  v4 = recognizer->computeErrorRecoverySet(recognizer);
  recognizer->beginResync(recognizer);
  recognizer->consumeUntilSet(recognizer, v4);
  recognizer->endResync(recognizer);
  v4->free(v4);
  recognizer->state->error = 0;
  recognizer->state->failed = 0;
}

// File Line: 1469
// RVA: 0x255BB0
void *__fastcall recoverFromMismatchedToken(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        unsigned int ttype,
        ANTLR3_BITSET_LIST_struct *follow)
{
  unsigned int type; // eax
  __int64 v7; // rsi
  ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger; // rax
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v9; // rax
  void *v10; // rbx
  void *v12; // rbx

  type = recognizer->type;
  if ( type == 2 )
  {
    v7 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return 0i64;
    v7 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  if ( !recognizer->state->exception )
    antlr3RecognitionExceptionNew(recognizer);
  if ( recognizer->mismatchIsUnwantedToken(recognizer, (ANTLR3_INT_STREAM_struct *)v7, ttype) != 1 )
  {
    if ( mismatchIsMissingToken(recognizer, (ANTLR3_INT_STREAM_struct *)v7, follow) )
    {
      v12 = recognizer->getMissingSymbol(recognizer, v7, recognizer->state->exception, ttype, follow);
      recognizer->state->exception->type = 10;
      recognizer->state->exception->message = "org.antlr.runtime.MissingTokenException";
      recognizer->state->exception->token = v12;
      recognizer->state->exception->expecting = ttype;
      recognizer->reportError(recognizer);
      recognizer->state->error = 0;
      return v12;
    }
    recognizer->state->error = 1;
    return 0i64;
  }
  recognizer->state->exception->type = 9;
  recognizer->state->exception->message = "org.antlr.runtime.UnwantedTokenException";
  debugger = recognizer->debugger;
  if ( debugger )
    debugger->beginResync(recognizer->debugger);
  recognizer->beginResync(recognizer);
  (*(void (__fastcall **)(__int64))(v7 + 40))(v7);
  recognizer->endResync(recognizer);
  v9 = recognizer->debugger;
  if ( v9 )
    v9->endResync(recognizer->debugger);
  recognizer->reportError(recognizer);
  v10 = recognizer->getCurrentInputSymbol(recognizer, v7);
  (*(void (__fastcall **)(__int64))(v7 + 40))(v7);
  recognizer->state->error = 0;
  return v10;
}

// File Line: 1592
// RVA: 0x255AE0
void *__fastcall recoverFromMismatchedSet(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_BITSET_LIST_struct *follow)
{
  unsigned int type; // eax
  ANTLR3_INT_STREAM_struct *v5; // rbx
  void *v6; // rbx

  type = recognizer->type;
  if ( type == 2 )
  {
    v5 = *(ANTLR3_INT_STREAM_struct **)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return 0i64;
    v5 = *(ANTLR3_INT_STREAM_struct **)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  if ( recognizer->mismatchIsMissingToken(recognizer, v5, follow) == 1 )
  {
    v6 = recognizer->getMissingSymbol(recognizer, v5, recognizer->state->exception, 0i64, follow);
    recognizer->state->exception->type = 10;
    recognizer->state->exception->token = v6;
    recognizer->reportError(recognizer);
    recognizer->state->error = 0;
    return v6;
  }
  recognizer->state->error = 1;
  recognizer->state->failed = 1;
  return 0i64;
}

// File Line: 1656
// RVA: 0x2559F0
char __fastcall recoverFromMismatchedElement(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        ANTLR3_BITSET_LIST_struct *followBits)
{
  unsigned int type; // eax
  __int64 v5; // rbp
  ANTLR3_BITSET_struct *v6; // rax
  ANTLR3_BITSET_struct *v7; // rdi
  ANTLR3_BITSET_struct *v8; // rbx
  unsigned int v9; // eax

  type = recognizer->type;
  if ( type == 2 )
  {
    v5 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return 0;
    v5 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  v6 = antlr3BitsetLoad(followBits);
  v7 = v6;
  if ( v6 )
  {
    if ( v6->isMember(v6, 1u) == 1 )
    {
      v8 = recognizer->computeCSRuleFollow(recognizer);
      v7->remove(v7, 1u);
      v8->free(v8);
    }
    v9 = (*(__int64 (__fastcall **)(__int64, __int64))(v5 + 48))(v5, 1i64);
    if ( v7->isMember(v7, v9) == 1 )
    {
      recognizer->reportError(recognizer);
      v7->free(v7);
      recognizer->state->error = 0;
      recognizer->state->failed = 0;
      return 1;
    }
    v7->free(v7);
  }
  return 0;
}

// File Line: 1753
// RVA: 0x255050
void __fastcall consumeUntil(ANTLR3_BASE_RECOGNIZER_struct *recognizer, unsigned int tokenType)
{
  unsigned int type; // eax
  __int64 v4; // rbx
  int i; // eax

  type = recognizer->type;
  if ( type == 2 )
  {
    v4 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return;
    v4 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  for ( i = (*(__int64 (__fastcall **)(__int64, __int64))(v4 + 48))(v4, 1i64);
        i != -1;
        i = (*(__int64 (__fastcall **)(__int64, __int64))(v4 + 48))(v4, 1i64) )
  {
    if ( i == tokenType )
      break;
    (*(void (__fastcall **)(__int64))(v4 + 40))(v4);
  }
}

// File Line: 1803
// RVA: 0x2550C0
void __fastcall consumeUntilSet(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_BITSET_struct *set)
{
  unsigned int type; // eax
  __int64 v4; // rbx
  unsigned int i; // eax

  type = recognizer->type;
  if ( type == 2 )
  {
    v4 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return;
    v4 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  for ( i = (*(__int64 (__fastcall **)(__int64, __int64))(v4 + 48))(v4, 1i64);
        i != -1;
        i = (*(__int64 (__fastcall **)(__int64, __int64))(v4 + 48))(v4, 1i64) )
  {
    if ( set->isMember(set, i) )
      break;
    (*(void (__fastcall **)(__int64))(v4 + 40))(v4);
  }
}

// File Line: 1875
// RVA: 0x255310
void __fastcall freeIntTrie(void (**trie)(void))
{
  trie[6]();
}

// File Line: 1892
// RVA: 0x255470
__int64 __fastcall getRuleMemoization(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        unsigned __int64 ruleIndex,
        __int64 ruleParseStart)
{
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 result; // rax

  v6 = ((__int64 (__fastcall *)(ANTLR3_INT_TRIE_struct *))recognizer->state->ruleMemo->get)(recognizer->state->ruleMemo);
  if ( !v6 )
  {
    if ( antlr3IntTrieNew(0x3Fu) )
      ((void (__fastcall *)(ANTLR3_INT_TRIE_struct *, unsigned __int64, __int64))recognizer->state->ruleMemo->add)(
        recognizer->state->ruleMemo,
        ruleIndex,
        1i64);
    return 0xFFFFFFFFi64;
  }
  v7 = (*(__int64 (__fastcall **)(_QWORD, __int64))(*(_QWORD *)(v6 + 16) + 24i64))(*(_QWORD *)(v6 + 16), ruleParseStart);
  if ( !v7 )
    return 0xFFFFFFFFi64;
  result = *(_QWORD *)(v7 + 16);
  if ( !result )
    return 0xFFFFFFFFi64;
  return result;
}

// File Line: 1955
// RVA: 0x254D30
char __fastcall alreadyParsedRule(ANTLR3_BASE_RECOGNIZER_struct *recognizer, unsigned __int64 ruleIndex)
{
  __int64 v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rax

  switch ( recognizer->type )
  {
    case 1u:
      v5 = **((_QWORD **)recognizer->super + 2);
      break;
    case 2u:
      v5 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
      break;
    case 4u:
      v5 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
      break;
    default:
      return 0;
  }
  v6 = (*(__int64 (__fastcall **)(__int64))(v5 + 64))(v5);
  v7 = recognizer->getRuleMemoization(recognizer, ruleIndex, v6);
  if ( v7 == 0xFFFFFFFFi64 )
    return 0;
  if ( v7 == 4294967294i64 )
    recognizer->state->failed = 1;
  else
    (*(void (__fastcall **)(__int64, __int64))(v5 + 96))(v5, v7 + 1);
  return 1;
}

// File Line: 2026
// RVA: 0x255630
void __fastcall memoize(ANTLR3_BASE_RECOGNIZER_struct *recognizer, unsigned __int64 ruleIndex, __int64 ruleParseStart)
{
  __int64 v6; // rdx
  __int64 v7; // rdi
  ANTLR3_TRIE_ENTRY_struct *v8; // rax

  switch ( recognizer->type )
  {
    case 1u:
      v6 = **((_QWORD **)recognizer->super + 2);
      break;
    case 2u:
      v6 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
      break;
    case 4u:
      v6 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
      break;
    default:
      return;
  }
  if ( recognizer->state->failed == 1 )
    v7 = 4294967294i64;
  else
    v7 = (*(__int64 (__fastcall **)(__int64))(v6 + 64))(v6) - 1;
  v8 = recognizer->state->ruleMemo->get(recognizer->state->ruleMemo, ruleIndex);
  if ( v8 )
    (*(void (__fastcall **)(unsigned __int64, __int64, _QWORD, __int64, _QWORD, _QWORD))(v8->data.intVal + 40))(
      v8->data.intVal,
      ruleParseStart,
      0i64,
      v7,
      0i64,
      0i64);
}

// File Line: 2092
// RVA: 0x255E40
bool __fastcall synpred(ANTLR3_BASE_RECOGNIZER_struct *recognizer, void *ctx, void (__fastcall *predicate)(void *))
{
  unsigned int type; // eax
  __int64 v8; // rsi
  __int64 v9; // rax
  __int64 v10; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax
  bool v12; // zf

  type = recognizer->type;
  if ( type == 2 )
  {
    v8 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( type != 4 )
      return 0;
    v8 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  v9 = (*(__int64 (__fastcall **)(__int64))(v8 + 56))(v8);
  ++recognizer->state->backtracking;
  v10 = v9;
  predicate(ctx);
  (*(void (__fastcall **)(__int64, __int64))(v8 + 72))(v8, v10);
  --recognizer->state->backtracking;
  state = recognizer->state;
  v12 = state->failed == 1;
  state->failed = 0;
  return !v12;
}

// File Line: 2157
// RVA: 0x255DA0
void __fastcall reset(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax
  ANTLR3_STACK_struct *following; // rdx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // rax
  ANTLR3_INT_TRIE_struct *ruleMemo; // rax

  state = recognizer->state;
  following = state->following;
  if ( following )
    following->free(state->following);
  recognizer->state->errorRecovery = 0;
  recognizer->state->lastErrorIndex = -1i64;
  recognizer->state->failed = 0;
  recognizer->state->errorCount = 0;
  recognizer->state->backtracking = 0;
  recognizer->state->following = 0i64;
  v4 = recognizer->state;
  if ( v4 )
  {
    ruleMemo = v4->ruleMemo;
    if ( ruleMemo )
    {
      ruleMemo->free(ruleMemo);
      recognizer->state->ruleMemo = antlr3IntTrieNew(0xFu);
    }
  }
  recognizer->state->following = antlr3StackNew(8u);
}

// File Line: 2193
// RVA: 0x255320
__int64 __fastcall getCurrentInputSymbol(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_INT_STREAM_struct *istream)
{
  return (*((__int64 (__fastcall **)(void *, __int64))istream->super + 5))(istream->super, 1i64);
}

// File Line: 2203
// RVA: 0x255330
ANTLR3_COMMON_TOKEN_struct *__fastcall getMissingSymbol(
        ANTLR3_BASE_RECOGNIZER_struct *recognizer,
        ANTLR3_INT_STREAM_struct *istream,
        ANTLR3_EXCEPTION_struct *e,
        unsigned int expectedTokenType)
{
  __int64 (__fastcall **super)(void *, __int64, ANTLR3_EXCEPTION_struct *); // rdi
  __int64 v6; // rbp
  __int64 v7; // rbx
  ANTLR3_COMMON_TOKEN_struct *v8; // rdi
  unsigned int v9; // eax
  int v10; // eax
  __int64 v11; // rax
  __int64 v12; // rbx

  super = (__int64 (__fastcall **)(void *, __int64, ANTLR3_EXCEPTION_struct *))istream->super;
  v6 = expectedTokenType;
  v7 = super[5](super, 1i64, e);
  if ( (*(unsigned int (__fastcall **)(__int64))(v7 + 144))(v7) == -1 )
    v7 = ((__int64 (__fastcall *)(__int64 (__fastcall **)(void *, __int64, ANTLR3_EXCEPTION_struct *), __int64))super[5])(
           super,
           0xFFFFFFFFi64);
  if ( !recognizer->state->tokFactory )
    recognizer->state->tokFactory = antlr3TokenFactoryNew(*(ANTLR3_INPUT_STREAM_struct **)(v7 + 40));
  v8 = recognizer->state->tokFactory->newToken(recognizer->state->tokFactory);
  v9 = (*(__int64 (__fastcall **)(__int64))(v7 + 160))(v7);
  v8->setLine(v8, v9);
  v10 = (*(__int64 (__fastcall **)(__int64))(v7 + 176))(v7);
  v8->setCharPositionInLine(v8, v10);
  v8->setChannel(v8, 0);
  v8->setType(v8, v6);
  v8->user1 = *(_DWORD *)(v7 + 88);
  v8->user2 = *(_DWORD *)(v7 + 92);
  v8->user3 = *(_DWORD *)(v7 + 96);
  v8->custom = *(void **)(v7 + 104);
  v8->lineStart = *(void **)(v7 + 24);
  v8->setText8(v8, "<missing ");
  v11 = (__int64)v8->getText(v8);
  v12 = v11;
  if ( v11 )
  {
    (*(void (__fastcall **)(__int64, char *))(v11 + 56))(v11, recognizer->state->tokenNames[v6]);
    (*(void (__fastcall **)(__int64, const char *))(v12 + 56))(v12, ">");
  }
  return v8;
}

