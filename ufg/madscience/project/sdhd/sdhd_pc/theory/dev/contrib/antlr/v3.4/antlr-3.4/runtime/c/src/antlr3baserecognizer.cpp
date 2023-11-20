// File Line: 15
// RVA: 0x254E00
UFG::allocator::free_link *__fastcall antlrCalloc(unsigned int numEl, unsigned int elSize)
{
  unsigned int v2; // edi
  UFG::allocator::free_link *v3; // rbx

  v2 = elSize;
  v3 = UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, numEl * elSize, "ANTLR_CALLOC", 0i64, 1u);
  UFG::qMemSet(v3, 0, v2);
  return v3;
}

// File Line: 21
// RVA: 0x254EC0
UFG::allocator::free_link *__fastcall antlrStrdup(const char *s)
{
  const char *v1; // rsi
  unsigned int v2; // edi
  UFG::allocator::free_link *v3; // rbx

  v1 = s;
  v2 = UFG::qStringLength(s);
  v3 = UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, v2, "ANTLR3_STRDUP", 0i64, 1u);
  UFG::qMemCopy(v3, v1, v2);
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
void __fastcall antlrFree(void *mem)
{
  UFG::qMemoryPool::Free(&gAntlrMemoryPool, mem);
}

// File Line: 121
// RVA: 0x255EE0
UFG::allocator::free_link *__fastcall antlr3BaseRecognizerNew(unsigned int type, unsigned int sizeHint, ANTLR3_RECOGNIZER_SHARED_STATE_struct *state)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v3; // rdi
  unsigned int v4; // ebp
  unsigned int v5; // esi
  UFG::allocator::free_link *result; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v7; // rbx
  UFG::allocator::free_link *v8; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v9; // rdx

  v3 = state;
  v4 = type;
  v5 = sizeHint;
  result = UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, 0x128ui64, "ANTLR_MALLOC", 0i64, 1u);
  v7 = (ANTLR3_BASE_RECOGNIZER_struct *)result;
  if ( result )
  {
    if ( v3 )
    {
      result[2].mNext = (UFG::allocator::free_link *)v3;
    }
    else
    {
      v8 = UFG::qMemoryPool::Allocate(&gAntlrMemoryPool, 0xB8ui64, "ANTLR_CALLOC", 0i64, 1u);
      UFG::qMemSet(v8, 0, 0xB8u);
      v7->state = (ANTLR3_RECOGNIZER_SHARED_STATE_struct *)v8;
      if ( !v8 )
      {
LABEL_6:
        UFG::qMemoryPool::Free(&gAntlrMemoryPool, v7);
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
      v7->state->sizeHint = v5;
      v7->state->tokSource = 0i64;
      v7->state->tokFactory = 0i64;
      v7->state->rStreams = antlr3VectorNew(0);
      v9 = v7->state;
      if ( !v9->rStreams )
      {
        UFG::qMemoryPool::Free(&gAntlrMemoryPool, v9);
        goto LABEL_6;
      }
    }
    v7->debugger = 0i64;
    v7->type = v4;
    v7->alreadyParsedRule = alreadyParsedRule;
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
    v7->memoize = memoize;
    v7->mismatch = mismatch;
    v7->mismatchIsUnwantedToken = mismatchIsUnwantedToken;
    v7->mismatchIsMissingToken = mismatchIsMissingToken;
    v7->recover = recover;
    v7->recoverFromMismatchedElement = recoverFromMismatchedElement;
    v7->recoverFromMismatchedSet = (void *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, ANTLR3_BITSET_LIST_struct *))recoverFromMismatchedSet;
    v7->recoverFromMismatchedToken = (void *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, unsigned int, ANTLR3_BITSET_LIST_struct *))recoverFromMismatchedToken;
    v7->getNumberOfSyntaxErrors = (unsigned int (__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *))getNumberOfSyntaxErrors;
    v7->reportError = reportError;
    v7->reset = reset;
    v7->synpred = synpred;
    v7->toStrings = (ANTLR3_HASH_TABLE_struct *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, ANTLR3_HASH_TABLE_struct *))TargetVisibleInAIDataCondition::CreateClone;
    v7->getCurrentInputSymbol = (void *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, ANTLR3_INT_STREAM_struct *))getCurrentInputSymbol;
    v7->getMissingSymbol = (void *(__fastcall *)(ANTLR3_BASE_RECOGNIZER_struct *, ANTLR3_INT_STREAM_struct *, ANTLR3_EXCEPTION_struct *, unsigned int, ANTLR3_BITSET_LIST_struct *))getMissingSymbol;
    v7->free = freeBR;
    result = (UFG::allocator::free_link *)v7;
  }
  return result;
}

// File Line: 235
// RVA: 0x255270
void __fastcall freeBR(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v1; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v2; // rbx
  ANTLR3_INT_TRIE_struct *v3; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // rax
  ANTLR3_EXCEPTION_struct *v5; // rdx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v6; // rax
  ANTLR3_VECTOR_struct *v7; // rdx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v8; // rax
  ANTLR3_TOKEN_FACTORY_struct *v9; // rdx

  v1 = recognizer->state;
  v2 = recognizer;
  if ( v1 )
  {
    v3 = v1->ruleMemo;
    if ( v3 )
    {
      v3->free(v3);
      v2->state->ruleMemo = 0i64;
    }
    v4 = v2->state;
    v5 = v4->exception;
    if ( v5 )
      v5->freeEx(v4->exception);
    v6 = v2->state;
    v7 = v6->rStreams;
    if ( v7 )
      v7->free(v6->rStreams);
    v8 = v2->state;
    v9 = v8->tokFactory;
    if ( v9 )
      v9->close(v8->tokFactory);
    UFG::qMemoryPool::Free(&gAntlrMemoryPool, v2->state);
  }
  UFG::qMemoryPool::Free(&gAntlrMemoryPool, v2);
}

// File Line: 291
// RVA: 0x2561F0
void __fastcall antlr3MTExceptionNew(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_BASE_RECOGNIZER_struct *v1; // rbx

  v1 = recognizer;
  antlr3RecognitionExceptionNew(recognizer);
  v1->state->exception->name = "org.antlr.runtime.MismatchedTokenException";
  v1->state->exception->type = 2;
}

// File Line: 306
// RVA: 0x256230
void __fastcall antlr3RecognitionExceptionNew(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_BASE_RECOGNIZER_struct *v1; // rdi
  __int64 *v2; // r14
  _QWORD *v3; // r15
  __int64 v4; // rbp
  unsigned int v5; // ecx
  int v6; // ecx
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
  _QWORD *v17; // rax
  ANTLR3_STRING_struct *v18; // rcx

  v1 = recognizer;
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
      v4 = *(_QWORD *)(*((_QWORD *)v1->super + 2) + 8i64);
      v7 = *(_QWORD *)(v4 + 8);
    }
    else
    {
      v8 = *((_QWORD *)v1->super + 2);
      v3 = *(_QWORD **)(v8 + 8);
      v7 = *(_QWORD *)(v8 + 16);
    }
  }
  else
  {
    v2 = (__int64 *)*((_QWORD *)v1->super + 2);
    v7 = *v2;
  }
  v9 = antlr3ExceptionNew(1u, "org.antlr.runtime.RecognitionException", 0i64, 0);
  switch ( *(_DWORD *)v7 & 7 )
  {
    case 1:
      v9->c = (*(__int64 (__fastcall **)(__int64, signed __int64))(v7 + 48))(v7, 1i64);
      v9->line = ((__int64 (__fastcall *)(__int64 *))v2[20])(v2);
      v9->charPositionInLine = ((__int64 (__fastcall *)(__int64 *))v2[22])(v2);
      v9->index = (*(__int64 (__fastcall **)(__int64))(v7 + 64))(v7);
      v9->streamName = (ANTLR3_STRING_struct *)v2[10];
      v14 = "Unexpected character";
LABEL_20:
      v9->message = (void *)v14;
      break;
    case 2:
      v16 = (*(__int64 (__fastcall **)(_QWORD, signed __int64))(*v3 + 40i64))(*v3, 1i64);
      v9->token = (void *)v16;
      v9->line = (*(__int64 (__fastcall **)(__int64))(v16 + 160))(v16);
      v9->charPositionInLine = (*((__int64 (__fastcall **)(void *))v9->token + 22))(v9->token);
      v9->index = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*v3 + 16i64) + 64i64))(*(_QWORD *)(*v3 + 16i64));
      v17 = v9->token;
      if ( *(_DWORD *)v17 == -1 )
      {
        v9->streamName = 0i64;
        v14 = "Unexpected token";
      }
      else
      {
        v18 = *(ANTLR3_STRING_struct **)(v17[5] + 80i64);
        v14 = "Unexpected token";
        v9->streamName = v18;
      }
      goto LABEL_20;
    case 4:
      v10 = (*(__int64 (__fastcall **)(__int64, signed __int64))(v4 + 16))(v4, 1i64);
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
  v9->nextException = v1->state->exception;
  v1->state->exception = v9;
  v1->state->error = 1;
}

// File Line: 453
// RVA: 0x255510
void *__fastcall match(ANTLR3_BASE_RECOGNIZER_struct *recognizer, unsigned int ttype, ANTLR3_BITSET_LIST_struct *follow)
{
  unsigned int v3; // eax
  ANTLR3_BITSET_LIST_struct *v4; // r14
  unsigned int v5; // ebp
  ANTLR3_BASE_RECOGNIZER_struct *v6; // rbx
  void *result; // rax
  __int64 v8; // rdi
  void *v9; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v10; // rax

  v3 = recognizer->type;
  v4 = follow;
  v5 = ttype;
  v6 = recognizer;
  if ( v3 == 2 )
  {
    v8 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v3 != 4 )
      return 0i64;
    v8 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  v9 = recognizer->getCurrentInputSymbol(recognizer, (ANTLR3_INT_STREAM_struct *)v8);
  if ( (*(unsigned int (__fastcall **)(__int64, signed __int64))(v8 + 48))(v8, 1i64) == v5 )
  {
    (*(void (__fastcall **)(__int64))(v8 + 40))(v8);
    result = v9;
    v6->state->errorRecovery = 0;
    v6->state->failed = 0;
  }
  else
  {
    v10 = v6->state;
    if ( v10->backtracking <= 0 )
    {
      result = v6->recoverFromMismatchedToken(v6, v5, v4);
    }
    else
    {
      v10->failed = 1;
      result = v9;
    }
  }
  return result;
}

// File Line: 526
// RVA: 0x2555E0
void __fastcall matchAny(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  unsigned int v1; // eax
  __int64 v2; // rdx

  v1 = recognizer->type;
  if ( v1 == 2 )
  {
    v2 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v1 != 4 )
      return;
    v2 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  recognizer->state->errorRecovery = 0;
  recognizer->state->failed = 0;
  (*(void (__fastcall **)(__int64))(v2 + 40))(v2);
}

// File Line: 566
// RVA: 0x255900
char __fastcall mismatchIsUnwantedToken(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_INT_STREAM_struct *is, unsigned int ttype)
{
  ANTLR3_BASE_RECOGNIZER_struct *v3; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // eax
  ANTLR3_EXCEPTION_struct *v6; // rdx

  v3 = recognizer;
  v4 = ttype;
  v5 = is->_LA(is, 2);
  if ( v5 != v4 )
    return 0;
  v6 = v3->state->exception;
  if ( v6 )
    v6->expecting = v5;
  return 1;
}

// File Line: 589
// RVA: 0x255830
char __fastcall mismatchIsMissingToken(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_INT_STREAM_struct *is, ANTLR3_BITSET_LIST_struct *follow)
{
  ANTLR3_INT_STREAM_struct *v3; // rbp
  ANTLR3_BASE_RECOGNIZER_struct *v4; // rsi
  ANTLR3_BITSET_struct *v5; // rax
  __int64 v6; // rdi
  ANTLR3_BITSET_struct *v7; // rbx
  unsigned int v8; // eax
  bool v9; // si

  v3 = is;
  v4 = recognizer;
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
        v6 = (__int64)v4->computeCSRuleFollow(v4);
        v7->borInPlace(v7, (ANTLR3_BITSET_struct *)v6);
      }
      v8 = v3->_LA(v3, 1);
      v9 = v7->isMember(v7, v8) || v7->isMember(v7, 1u);
      if ( v6 )
        (*(void (__fastcall **)(__int64))(v6 + 112))(v6);
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
void __fastcall mismatch(ANTLR3_BASE_RECOGNIZER_struct *recognizer, unsigned int ttype, ANTLR3_BITSET_LIST_struct *follow)
{
  ANTLR3_BITSET_LIST_struct *v3; // rbp
  unsigned int v4; // esi
  ANTLR3_BASE_RECOGNIZER_struct *v5; // rbx
  __int64 v6; // rdi
  unsigned int v7; // eax
  ANTLR3_EXCEPTION_struct *v8; // rdx

  v3 = follow;
  v4 = ttype;
  v5 = recognizer;
  antlr3RecognitionExceptionNew(recognizer);
  v5->state->exception->name = "org.antlr.runtime.MismatchedTokenException";
  v5->state->exception->type = 2;
  v5->state->exception->expecting = v4;
  if ( v5->type == 2 )
  {
    v6 = *(_QWORD *)(*((_QWORD *)v5->super + 2) + 16i64);
    v7 = (*(__int64 (__fastcall **)(__int64, signed __int64))(v6 + 48))(v6, 2i64);
    if ( v7 == v4 )
    {
      v8 = v5->state->exception;
      if ( v8 )
        v8->expecting = v7;
      antlr3RecognitionExceptionNew(v5);
      v5->state->exception->name = "org.antlr.runtime.UnwantedTokenException";
      v5->state->exception->type = 9;
    }
    else if ( mismatchIsMissingToken(v5, (ANTLR3_INT_STREAM_struct *)v6, v3) )
    {
      antlr3RecognitionExceptionNew(v5);
      v5->state->exception->name = "org.antlr.runtime.MissingTokenException";
      v5->state->exception->type = 10;
    }
    else
    {
      antlr3RecognitionExceptionNew(v5);
      v5->state->exception->name = "org.antlr.runtime.MismatchedTokenException";
      v5->state->exception->type = 2;
    }
  }
}

// File Line: 758
// RVA: 0x255D40
void __fastcall reportError(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v1; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v2; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v3; // rax

  v1 = recognizer->debugger;
  v2 = recognizer;
  if ( v1 )
    v1->recognitionException(recognizer->debugger, recognizer->state->exception);
  v3 = v2->state;
  if ( v3->errorRecovery != 1 )
  {
    v3->errorRecovery = 1;
    ++v2->state->errorCount;
    v2->displayRecognitionError(v2, v2->state->tokenNames);
  }
}

// File Line: 788
// RVA: 0x254F20
void __fastcall beginBacktrack(ANTLR3_BASE_RECOGNIZER_struct *recognizer, __int64 level)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v2; // rax

  v2 = recognizer->debugger;
  if ( v2 )
    v2->beginBacktrack(recognizer->debugger, level);
}

// File Line: 797
// RVA: 0x255230
void __fastcall endBacktrack(ANTLR3_BASE_RECOGNIZER_struct *recognizer, __int64 level, __int64 successful)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v3; // rax

  v3 = recognizer->debugger;
  if ( v3 )
    v3->endBacktrack(recognizer->debugger, level, successful);
}

// File Line: 805
// RVA: 0x254F40
void __fastcall beginResync(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v1; // rax

  v1 = recognizer->debugger;
  if ( v1 )
    v1->beginResync(recognizer->debugger);
}

// File Line: 814
// RVA: 0x255250
void __fastcall endResync(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v1; // rax

  v1 = recognizer->debugger;
  if ( v1 )
    v1->endResync(recognizer->debugger);
}

// File Line: 976
// RVA: 0x255040
ANTLR3_BITSET_struct *__fastcall computeErrorRecoverySet(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  return (ANTLR3_BITSET_struct *)recognizer->combineFollows(recognizer, 0);
}

// File Line: 984
// RVA: 0x254F60
ANTLR3_BITSET_struct *__fastcall combineFollows(ANTLR3_BASE_RECOGNIZER_struct *recognizer, char exact)
{
  ANTLR3_BASE_RECOGNIZER_struct *v2; // r15
  char v3; // r14
  unsigned int v4; // esi
  ANTLR3_BITSET_struct *result; // rax
  ANTLR3_BITSET_struct *v6; // rdi
  int v7; // ebp
  ANTLR3_BITSET_LIST_struct *v8; // rax
  ANTLR3_BITSET_struct *v9; // rax
  ANTLR3_BITSET_struct *v10; // rbx

  v2 = recognizer;
  v3 = exact;
  v4 = recognizer->state->following->size(recognizer->state->following);
  result = antlr3BitsetNew(0);
  v6 = result;
  if ( v4 )
  {
    do
    {
      v7 = v4 - 1;
      v8 = (ANTLR3_BITSET_LIST_struct *)v2->state->following->get(v2->state->following, v4 - 1);
      v9 = antlr3BitsetLoad(v8);
      v10 = v9;
      if ( v9 )
      {
        v6->borInPlace(v6, v9);
        if ( v3 == 1 )
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
    result = v6;
  }
  return result;
}

// File Line: 1045
// RVA: 0x255140
void __fastcall displayRecognitionError(ANTLR3_BASE_RECOGNIZER_struct *recognizer, char **tokenNames)
{
  char **v2; // rbp
  ANTLR3_BASE_RECOGNIZER_struct *v3; // rbx
  ANTLR3_EXCEPTION_struct *v4; // rsi
  ANTLR3_STRING_struct *v5; // rax
  unsigned int v6; // eax
  void (__fastcall **v7)(void *); // rbx
  void (__fastcall **v8)(void *); // rcx
  unsigned int v9; // edi
  ANTLR3_BITSET_struct *v10; // rbx
  unsigned int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // edx
  _QWORD *v14; // rcx

  v2 = tokenNames;
  v3 = recognizer;
  v4 = recognizer->state->exception;
  v5 = v4->streamName;
  if ( v5 )
    v5->to8(v4->streamName);
  v6 = v3->type;
  if ( v6 == 2 )
  {
    v8 = (void (__fastcall **)(void *))v3->state->exception->token;
    v8[32](v8);
  }
  else
  {
    if ( v6 != 4 )
      return;
    v7 = (void (__fastcall **)(void *))v3->state->exception->token;
    v7[26](v7);
    if ( *v7 )
      v7[5](v7);
  }
  if ( v4->type != 2 && v4->type == 4 )
  {
    v9 = 0;
    v10 = antlr3BitsetLoad(v4->expectingSet);
    v11 = v10->numBits(v10);
    v12 = v10->size(v10);
    if ( v12 )
    {
      v13 = 1;
      if ( v11 > 1 )
      {
        v14 = v2 + 1;
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
  unsigned int v1; // eax
  ANTLR3_BASE_RECOGNIZER_struct *v2; // rdi
  __int64 v3; // rbx
  __int64 v4; // rbx

  v1 = recognizer->type;
  v2 = recognizer;
  if ( v1 == 2 )
  {
    v3 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v1 != 4 )
      return;
    v3 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  if ( recognizer->state->lastErrorIndex == (*(__int64 (__fastcall **)(__int64))(v3 + 64))(v3) )
    (*(void (__fastcall **)(__int64))(v3 + 40))(v3);
  v2->state->lastErrorIndex = (*(__int64 (__fastcall **)(__int64))(v3 + 64))(v3);
  v4 = (__int64)v2->computeErrorRecoverySet(v2);
  v2->beginResync(v2);
  v2->consumeUntilSet(v2, (ANTLR3_BITSET_struct *)v4);
  v2->endResync(v2);
  (*(void (__fastcall **)(__int64))(v4 + 112))(v4);
  v2->state->error = 0;
  v2->state->failed = 0;
}

// File Line: 1469
// RVA: 0x255BB0
__int64 __fastcall recoverFromMismatchedToken(ANTLR3_BASE_RECOGNIZER_struct *recognizer, unsigned int ttype, ANTLR3_BITSET_LIST_struct *follow)
{
  unsigned int v3; // eax
  ANTLR3_BITSET_LIST_struct *v4; // rbx
  unsigned int v5; // ebp
  ANTLR3_BASE_RECOGNIZER_struct *v6; // rdi
  __int64 v7; // rsi
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v8; // rax
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v9; // rax
  __int64 v10; // rbx
  __int64 v12; // rax
  __int64 v13; // rbx

  v3 = recognizer->type;
  v4 = follow;
  v5 = ttype;
  v6 = recognizer;
  if ( v3 == 2 )
  {
    v7 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v3 != 4 )
      return 0i64;
    v7 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  if ( !recognizer->state->exception )
    antlr3RecognitionExceptionNew(recognizer);
  if ( v6->mismatchIsUnwantedToken(v6, (ANTLR3_INT_STREAM_struct *)v7, v5) != 1 )
  {
    if ( mismatchIsMissingToken(v6, (ANTLR3_INT_STREAM_struct *)v7, v4) )
    {
      v12 = (__int64)v6->getMissingSymbol(v6, (ANTLR3_INT_STREAM_struct *)v7, v6->state->exception, v5, v4);
      v13 = v12;
      v6->state->exception->type = 10;
      v6->state->exception->message = "org.antlr.runtime.MissingTokenException";
      v6->state->exception->token = (void *)v12;
      v6->state->exception->expecting = v5;
      v6->reportError(v6);
      v6->state->error = 0;
      return v13;
    }
    v6->state->error = 1;
    return 0i64;
  }
  v6->state->exception->type = 9;
  v6->state->exception->message = "org.antlr.runtime.UnwantedTokenException";
  v8 = v6->debugger;
  if ( v8 )
    v8->beginResync(v6->debugger);
  v6->beginResync(v6);
  (*(void (__fastcall **)(__int64))(v7 + 40))(v7);
  v6->endResync(v6);
  v9 = v6->debugger;
  if ( v9 )
    v9->endResync(v6->debugger);
  v6->reportError(v6);
  v10 = (__int64)v6->getCurrentInputSymbol(v6, (ANTLR3_INT_STREAM_struct *)v7);
  (*(void (__fastcall **)(__int64))(v7 + 40))(v7);
  v6->state->error = 0;
  return v10;
}

// File Line: 1592
// RVA: 0x255AE0
__int64 __fastcall recoverFromMismatchedSet(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_BITSET_LIST_struct *follow)
{
  unsigned int v2; // eax
  ANTLR3_BITSET_LIST_struct *v3; // rsi
  ANTLR3_BASE_RECOGNIZER_struct *v4; // rdi
  ANTLR3_INT_STREAM_struct *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rbx

  v2 = recognizer->type;
  v3 = follow;
  v4 = recognizer;
  if ( v2 == 2 )
  {
    v5 = *(ANTLR3_INT_STREAM_struct **)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v2 != 4 )
      return 0i64;
    v5 = *(ANTLR3_INT_STREAM_struct **)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  if ( recognizer->mismatchIsMissingToken(recognizer, v5, follow) == 1 )
  {
    v6 = (__int64)v4->getMissingSymbol(v4, v5, v4->state->exception, 0, v3);
    v7 = v6;
    v4->state->exception->type = 10;
    v4->state->exception->token = (void *)v6;
    v4->reportError(v4);
    v4->state->error = 0;
    return v7;
  }
  v4->state->error = 1;
  v4->state->failed = 1;
  return 0i64;
}

// File Line: 1656
// RVA: 0x2559F0
char __fastcall recoverFromMismatchedElement(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_BITSET_LIST_struct *followBits)
{
  unsigned int v2; // eax
  ANTLR3_BASE_RECOGNIZER_struct *v3; // rsi
  __int64 v5; // rbp
  ANTLR3_BITSET_struct *v6; // rax
  ANTLR3_BITSET_struct *v7; // rdi
  __int64 v8; // rbx
  unsigned int v9; // eax

  v2 = recognizer->type;
  v3 = recognizer;
  if ( v2 == 2 )
  {
    v5 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v2 != 4 )
      return 0;
    v5 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  v6 = antlr3BitsetLoad(followBits);
  v7 = v6;
  if ( v6 )
  {
    if ( v6->isMember(v6, 1u) == 1 )
    {
      v8 = (__int64)v3->computeCSRuleFollow(v3);
      v7->remove(v7, 1u);
      (*(void (__fastcall **)(__int64))(v8 + 112))(v8);
    }
    v9 = (*(__int64 (__fastcall **)(__int64, signed __int64))(v5 + 48))(v5, 1i64);
    if ( v7->isMember(v7, v9) == 1 )
    {
      v3->reportError(v3);
      v7->free(v7);
      v3->state->error = 0;
      v3->state->failed = 0;
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
  unsigned int v2; // eax
  unsigned int v3; // edi
  __int64 v4; // rbx
  int i; // eax

  v2 = recognizer->type;
  v3 = tokenType;
  if ( v2 == 2 )
  {
    v4 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v2 != 4 )
      return;
    v4 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  for ( i = (*(__int64 (__fastcall **)(__int64, signed __int64))(v4 + 48))(v4, 1i64);
        i != -1;
        i = (*(__int64 (__fastcall **)(__int64, signed __int64))(v4 + 48))(v4, 1i64) )
  {
    if ( i == v3 )
      break;
    (*(void (__fastcall **)(__int64))(v4 + 40))(v4);
  }
}

// File Line: 1803
// RVA: 0x2550C0
void __fastcall consumeUntilSet(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_BITSET_struct *set)
{
  unsigned int v2; // eax
  ANTLR3_BITSET_struct *v3; // rdi
  __int64 v4; // rbx
  unsigned int i; // eax

  v2 = recognizer->type;
  v3 = set;
  if ( v2 == 2 )
  {
    v4 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v2 != 4 )
      return;
    v4 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  for ( i = (*(__int64 (__fastcall **)(__int64, signed __int64))(v4 + 48))(v4, 1i64);
        i != -1;
        i = (*(__int64 (__fastcall **)(__int64, signed __int64))(v4 + 48))(v4, 1i64) )
  {
    if ( v3->isMember(v3, i) )
      break;
    (*(void (__fastcall **)(__int64))(v4 + 40))(v4);
  }
}

// File Line: 1875
// RVA: 0x255310
void __fastcall freeIntTrie(void *trie)
{
  (*((void (**)(void))trie + 6))();
}

// File Line: 1892
// RVA: 0x255470
__int64 __fastcall getRuleMemoization(ANTLR3_BASE_RECOGNIZER_struct *recognizer, unsigned __int64 ruleIndex, __int64 ruleParseStart)
{
  ANTLR3_BASE_RECOGNIZER_struct *v3; // rdi
  __int64 v4; // rsi
  unsigned __int64 v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 result; // rax

  v3 = recognizer;
  v4 = ruleParseStart;
  v5 = ruleIndex;
  v6 = ((__int64 (__fastcall *)(ANTLR3_INT_TRIE_struct *))recognizer->state->ruleMemo->get)(recognizer->state->ruleMemo);
  if ( !v6 )
  {
    if ( antlr3IntTrieNew(0x3Fu) )
      ((void (__fastcall *)(ANTLR3_INT_TRIE_struct *, unsigned __int64, signed __int64))v3->state->ruleMemo->add)(
        v3->state->ruleMemo,
        v5,
        1i64);
    return 0xFFFFFFFFi64;
  }
  v7 = (*(__int64 (__fastcall **)(_QWORD, __int64))(*(_QWORD *)(v6 + 16) + 24i64))(*(_QWORD *)(v6 + 16), v4);
  if ( !v7 )
    return 0xFFFFFFFFi64;
  result = *(_QWORD *)(v7 + 16);
  if ( !result )
    return 0xFFFFFFFFi64;
  return result;
}

// File Line: 1955
// RVA: 0x254D30
char __fastcall alreadyParsedRule(ANTLR3_BASE_RECOGNIZER_struct *recognizer, __int64 ruleIndex)
{
  __int64 v2; // rsi
  ANTLR3_BASE_RECOGNIZER_struct *v3; // rbx
  __int64 v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rax

  v2 = ruleIndex;
  v3 = recognizer;
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
  v7 = v3->getRuleMemoization(v3, v2, v6);
  if ( v7 == 0xFFFFFFFFi64 )
    return 0;
  if ( v7 == 4294967294i64 )
    v3->state->failed = 1;
  else
    (*(void (__fastcall **)(__int64, __int64))(v5 + 96))(v5, v7 + 1);
  return 1;
}

// File Line: 2026
// RVA: 0x255630
void __fastcall memoize(ANTLR3_BASE_RECOGNIZER_struct *recognizer, __int64 ruleIndex, __int64 ruleParseStart)
{
  __int64 v3; // rbp
  __int64 v4; // rsi
  ANTLR3_BASE_RECOGNIZER_struct *v5; // rbx
  __int64 v6; // rdx
  __int64 v7; // rdi
  __int64 v8; // rax

  v3 = ruleParseStart;
  v4 = ruleIndex;
  v5 = recognizer;
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
  v8 = (__int64)v5->state->ruleMemo->get(v5->state->ruleMemo, v4);
  if ( v8 )
    (*(void (__fastcall **)(_QWORD, __int64, _QWORD, __int64, _QWORD, _QWORD))(*(_QWORD *)(v8 + 16) + 40i64))(
      *(_QWORD *)(v8 + 16),
      v3,
      0i64,
      v7,
      0i64,
      0i64);
}

// File Line: 2092
// RVA: 0x255E40
char __fastcall synpred(ANTLR3_BASE_RECOGNIZER_struct *recognizer, void *ctx, void (__fastcall *predicate)(void *))
{
  unsigned int v3; // eax
  void (__fastcall *v4)(void *); // rbp
  void *v5; // r14
  ANTLR3_BASE_RECOGNIZER_struct *v6; // rdi
  __int64 v8; // rsi
  __int64 v9; // rax
  __int64 v10; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v11; // rax
  bool v12; // zf

  v3 = recognizer->type;
  v4 = predicate;
  v5 = ctx;
  v6 = recognizer;
  if ( v3 == 2 )
  {
    v8 = *(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 16i64);
  }
  else
  {
    if ( v3 != 4 )
      return 0;
    v8 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)recognizer->super + 2) + 8i64) + 8i64);
  }
  v9 = (*(__int64 (__fastcall **)(__int64))(v8 + 56))(v8);
  ++v6->state->backtracking;
  v10 = v9;
  v4(v5);
  (*(void (__fastcall **)(__int64, __int64))(v8 + 72))(v8, v10);
  --v6->state->backtracking;
  v11 = v6->state;
  v12 = v11->failed == 1;
  v11->failed = 0;
  if ( v12 )
    return 0;
  return 1;
}

// File Line: 2157
// RVA: 0x255DA0
void __fastcall reset(ANTLR3_BASE_RECOGNIZER_struct *recognizer)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v1; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v2; // rbx
  ANTLR3_STACK_struct *v3; // rdx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v4; // rax
  ANTLR3_INT_TRIE_struct *v5; // rax

  v1 = recognizer->state;
  v2 = recognizer;
  v3 = v1->following;
  if ( v3 )
    v3->free(v1->following);
  v2->state->errorRecovery = 0;
  v2->state->lastErrorIndex = -1i64;
  v2->state->failed = 0;
  v2->state->errorCount = 0;
  v2->state->backtracking = 0;
  v2->state->following = 0i64;
  v4 = v2->state;
  if ( v4 )
  {
    v5 = v4->ruleMemo;
    if ( v5 )
    {
      v5->free(v5);
      v2->state->ruleMemo = antlr3IntTrieNew(0xFu);
    }
  }
  v2->state->following = antlr3StackNew(8u);
}

// File Line: 2193
// RVA: 0x255320
__int64 __fastcall getCurrentInputSymbol(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_INT_STREAM_struct *istream)
{
  return (*((__int64 (__fastcall **)(void *, signed __int64))istream->super + 5))(istream->super, 1i64);
}

// File Line: 2203
// RVA: 0x255330
__int64 __fastcall getMissingSymbol(ANTLR3_BASE_RECOGNIZER_struct *recognizer, ANTLR3_INT_STREAM_struct *istream, ANTLR3_EXCEPTION_struct *e, unsigned int expectedTokenType)
{
  __int64 (__fastcall **v4)(void *, signed __int64, ANTLR3_EXCEPTION_struct *); // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v5; // rsi
  __int64 v6; // rbp
  __int64 v7; // rbx
  __int64 v8; // rdi
  unsigned int v9; // eax
  unsigned int v10; // eax
  __int64 v11; // rax
  __int64 v12; // rbx

  v4 = (__int64 (__fastcall **)(void *, signed __int64, ANTLR3_EXCEPTION_struct *))istream->super;
  v5 = recognizer;
  v6 = expectedTokenType;
  v7 = v4[5](v4, 1i64, e);
  if ( (*(unsigned int (__fastcall **)(__int64))(v7 + 144))(v7) == -1 )
    v7 = ((__int64 (__fastcall *)(__int64 (__fastcall **)(void *, signed __int64, ANTLR3_EXCEPTION_struct *), signed __int64))v4[5])(
           v4,
           0xFFFFFFFFi64);
  if ( !v5->state->tokFactory )
    v5->state->tokFactory = antlr3TokenFactoryNew(*(ANTLR3_INPUT_STREAM_struct **)(v7 + 40));
  v8 = (__int64)v5->state->tokFactory->newToken(v5->state->tokFactory);
  v9 = (*(__int64 (__fastcall **)(__int64))(v7 + 160))(v7);
  (*(void (__fastcall **)(__int64, _QWORD))(v8 + 168))(v8, v9);
  v10 = (*(__int64 (__fastcall **)(__int64))(v7 + 176))(v7);
  (*(void (__fastcall **)(__int64, _QWORD))(v8 + 184))(v8, v10);
  (*(void (__fastcall **)(__int64, _QWORD))(v8 + 200))(v8, 0i64);
  (*(void (__fastcall **)(__int64, _QWORD))(v8 + 152))(v8, (unsigned int)v6);
  *(_DWORD *)(v8 + 88) = *(_DWORD *)(v7 + 88);
  *(_DWORD *)(v8 + 92) = *(_DWORD *)(v7 + 92);
  *(_DWORD *)(v8 + 96) = *(_DWORD *)(v7 + 96);
  *(_QWORD *)(v8 + 104) = *(_QWORD *)(v7 + 104);
  *(_QWORD *)(v8 + 24) = *(_QWORD *)(v7 + 24);
  (*(void (__fastcall **)(__int64, const char *))(v8 + 136))(v8, "<missing ");
  v11 = (*(__int64 (__fastcall **)(__int64))(v8 + 120))(v8);
  v12 = v11;
  if ( v11 )
  {
    (*(void (__fastcall **)(__int64, char *))(v11 + 56))(v11, v5->state->tokenNames[v6]);
    (*(void (__fastcall **)(__int64, const char *))(v12 + 56))(v12, ">");
  }
  return v8;
}

