// File Line: 93
// RVA: 0x260D70
UFG::allocator::free_link *__fastcall antlr3TokenStreamNew()
{
  UFG::allocator::free_link *result; // rax

  result = antlrMalloc(0x70ui64);
  if ( result )
    result[13].mNext = (UFG::allocator::free_link *)antlr3EnumFree;
  return result;
}

// File Line: 115
// RVA: 0x260D60
// attributes: thunk
void __fastcall antlr3EnumFree(char *en)
{
  antlrFree(en);
}

// File Line: 121
// RVA: 0x260CD0
void __fastcall antlr3CTSFree(ANTLR3_COMMON_TOKEN_STREAM_struct *stream)
{
  ANTLR3_TOKEN_STREAM_struct *tstream; // rax
  ANTLR3_INT_STREAM_struct *istream; // rdx
  ANTLR3_VECTOR_struct *tokens; // rax
  ANTLR3_LIST_struct *discardSet; // rax
  ANTLR3_LIST_struct *channelOverrides; // rax

  tstream = stream->tstream;
  if ( stream->tstream->super == stream )
  {
    istream = tstream->istream;
    if ( istream->super == tstream )
    {
      istream->free(tstream->istream);
      stream->tstream->istream = 0i64;
    }
    stream->tstream->free(stream->tstream);
  }
  tokens = stream->tokens;
  if ( tokens )
  {
    tokens->free(stream->tokens);
    stream->tokens = 0i64;
  }
  discardSet = stream->discardSet;
  if ( discardSet )
  {
    discardSet->free(stream->discardSet);
    stream->discardSet = 0i64;
  }
  channelOverrides = stream->channelOverrides;
  if ( channelOverrides )
  {
    channelOverrides->free(stream->channelOverrides);
    stream->channelOverrides = 0i64;
  }
  antlrFree((char *)stream);
}

// File Line: 163
// RVA: 0x2614C0
void __fastcall reset_3(ANTLR3_COMMON_TOKEN_STREAM_struct *cts)
{
  ANTLR3_LIST_struct *discardSet; // rax
  ANTLR3_LIST_struct *channelOverrides; // rax
  ANTLR3_VECTOR_struct *tokens; // rax

  discardSet = cts->discardSet;
  if ( discardSet )
  {
    discardSet->free(cts->discardSet);
    cts->discardSet = 0i64;
  }
  channelOverrides = cts->channelOverrides;
  if ( channelOverrides )
  {
    channelOverrides->free(cts->channelOverrides);
    cts->channelOverrides = 0i64;
  }
  tokens = cts->tokens;
  if ( tokens )
    tokens->clear(cts->tokens);
  else
    cts->tokens = (ANTLR3_VECTOR_struct *)antlr3VectorNew(0);
  cts->discardOffChannel = 0;
  cts->channel = 0;
  cts->p = -1;
}

// File Line: 206
// RVA: 0x2618D0
ANTLR3_COMMON_TOKEN_STREAM_struct *__fastcall antlr3CommonTokenDebugStreamSourceNew(
        unsigned int hint,
        ANTLR3_TOKEN_SOURCE_struct *source,
        ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
{
  ANTLR3_COMMON_TOKEN_STREAM_struct *v5; // rsi
  ANTLR3_TOKEN_STREAM_struct *tstream; // r9
  ANTLR3_TOKEN_STREAM_struct *v7; // rcx

  v5 = antlr3CommonTokenStreamNew(hint);
  tstream = v5->tstream;
  v5->channel = 0;
  v5->channelOverrides = 0i64;
  v5->discardSet = 0i64;
  v5->discardOffChannel = 0;
  tstream->setTokenSource(tstream, source);
  v7 = v5->tstream;
  v5->free = antlr3CTSFree;
  v7->debugger = debugger;
  v5->tstream->initialStreamState = 0;
  v5->tstream->_LT = dbgTokLT;
  v5->tstream->istream->consume = dbgConsume;
  v5->tstream->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))dbgLA;
  v5->tstream->istream->mark = dbgMark;
  v5->tstream->istream->rewind = dbgRewindStream;
  v5->tstream->istream->rewindLast = dbgRewindLast;
  v5->tstream->istream->seek = seek_0;
  return v5;
}

// File Line: 235
// RVA: 0x261BD0
UFG::allocator::free_link *__fastcall antlr3CommonTokenStreamSourceNew(
        unsigned int hint,
        ANTLR3_TOKEN_SOURCE_struct *source)
{
  UFG::allocator::free_link *v3; // rdi
  UFG::allocator::free_link *mNext; // r8

  v3 = antlr3CommonTokenStreamNew(hint);
  mNext = v3->mNext;
  LODWORD(v3[5].mNext) = 0;
  v3[3].mNext = 0i64;
  v3[4].mNext = 0i64;
  BYTE4(v3[5].mNext) = 0;
  ((void (__fastcall *)(UFG::allocator::free_link *, ANTLR3_TOKEN_SOURCE_struct *))mNext[8].mNext)(mNext, source);
  v3[16].mNext = (UFG::allocator::free_link *)antlr3CTSFree;
  return v3;
}

// File Line: 254
// RVA: 0x2619C0
UFG::allocator::free_link *__fastcall antlr3CommonTokenStreamNew(unsigned int hint)
{
  UFG::allocator::free_link *result; // rax
  ANTLR3_COMMON_TOKEN_STREAM_struct *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  __int64 v4; // rax

  result = antlrMalloc(0x88ui64);
  v2 = (ANTLR3_COMMON_TOKEN_STREAM_struct *)result;
  if ( result )
  {
    v3 = antlrMalloc(0x70ui64);
    if ( v3 )
      v3[13].mNext = (UFG::allocator::free_link *)antlr3EnumFree;
    v2->tstream = (ANTLR3_TOKEN_STREAM_struct *)v3;
    v3[1].mNext = (UFG::allocator::free_link *)v2;
    v2->tstream->istream = (ANTLR3_INT_STREAM_struct *)antlr3IntStreamNew();
    v2->tstream->istream->super = v2->tstream;
    v2->tstream->istream->type = 2;
    v4 = antlr3VectorNew(0);
    v2->p = -1;
    v2->tokens = (ANTLR3_VECTOR_struct *)v4;
    v2->setTokenTypeChannel = setTokenTypeChannel;
    v2->discardTokenType = discardTokenType;
    v2->discardOffChannelToks = discardOffChannel;
    v2->getTokens = getTokens;
    v2->getTokenRange = (ANTLR3_LIST_struct *(__fastcall *)(ANTLR3_COMMON_TOKEN_STREAM_struct *, unsigned int, unsigned int))getTokenRange;
    v2->getTokensSet = getTokensSet;
    v2->getTokensList = getTokensList;
    v2->getTokensType = (ANTLR3_LIST_struct *(__fastcall *)(ANTLR3_COMMON_TOKEN_STREAM_struct *, unsigned int, unsigned int, unsigned int))getTokensType;
    v2->reset = reset_3;
    v2->tstream->_LT = tokLT;
    v2->tstream->get = (ANTLR3_COMMON_TOKEN_struct *(__fastcall *)(ANTLR3_TOKEN_STREAM_struct *, unsigned int))get_0;
    v2->tstream->getTokenSource = getTokenSource;
    v2->tstream->setTokenSource = UFG::qThread::SetName;
    v2->tstream->toString = toString_2;
    v2->tstream->toStringSS = toStringSS_0;
    v2->tstream->toStringTT = toStringTT;
    v2->tstream->setDebugListener = setDebugListener_0;
    v2->tstream->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))LA_0;
    v2->tstream->istream->mark = mark_0;
    v2->tstream->istream->release = (void (__fastcall *)(ANTLR3_INT_STREAM_struct *, __int64))_;
    v2->tstream->istream->size = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *))size_1;
    v2->tstream->istream->index = tindex_0;
    v2->tstream->istream->rewind = rewindStream;
    v2->tstream->istream->rewindLast = antlr38BitRewindLast;
    v2->tstream->istream->seek = seek_0;
    v2->tstream->istream->consume = consume_0;
    v2->tstream->istream->getSourceName = getSourceName;
    return (UFG::allocator::free_link *)v2;
  }
  return result;
}

// File Line: 328
// RVA: 0x261550
void __fastcall setDebugListener_0(ANTLR3_TOKEN_STREAM_struct *ts, ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
{
  ts->debugger = debugger;
  ts->initialStreamState = 0;
  ts->_LT = dbgTokLT;
  ts->istream->consume = dbgConsume;
  ts->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))dbgLA;
  ts->istream->mark = dbgMark;
  ts->istream->rewind = dbgRewindStream;
  ts->istream->rewindLast = dbgRewindLast;
  ts->istream->seek = seek_0;
}

// File Line: 352
// RVA: 0x2617B0
ANTLR3_COMMON_TOKEN_struct *__fastcall tokLT(ANTLR3_TOKEN_STREAM_struct *ts, int k)
{
  ANTLR3_COMMON_TOKEN_STREAM_struct *super; // rdi
  unsigned int p; // r8d
  ANTLR3_INT_STREAM_struct *istream; // rbp
  __int64 v8; // rdx
  __int64 v9; // r11
  __int64 cachedSize; // r9
  __int64 v11; // rax
  __int64 v12; // rax
  ANTLR3_COMMON_TOKEN_struct *p_eofToken; // rbx
  __int64 v14; // rax
  __int64 v15; // rax

  super = (ANTLR3_COMMON_TOKEN_STREAM_struct *)ts->super;
  if ( k < 0 )
    return LB(super, -k);
  if ( super->p == -1 )
    fillBuffer_0(super);
  p = super->p;
  istream = ts->istream;
  if ( (signed int)(p + k - 1) < (signed int)istream->cachedSize )
  {
    v8 = super->p;
    if ( k > 1 )
    {
      v9 = (unsigned int)(k - 1);
      cachedSize = (int)super->tstream->istream->cachedSize;
      do
      {
        v11 = v8 + 1;
        ++p;
        v8 = v11;
        if ( v11 < cachedSize )
        {
          v12 = (__int64)&super->tokens->elements[v11];
          do
          {
            if ( *(_DWORD *)(*(_QWORD *)v12 + 36i64) == super->channel )
              break;
            ++v8;
            ++p;
            v12 += 16i64;
          }
          while ( v8 < cachedSize );
        }
        --v9;
      }
      while ( v9 );
    }
    if ( p < istream->cachedSize )
      return (ANTLR3_COMMON_TOKEN_struct *)super->tokens->elements[p].element;
  }
  p_eofToken = &ts->tokenSource->eofToken;
  v14 = istream->index(ts->istream);
  p_eofToken->setStartIndex(p_eofToken, v14);
  v15 = ts->istream->index(ts->istream);
  p_eofToken->setStopIndex(p_eofToken, v15);
  return p_eofToken;
}

// File Line: 416
// RVA: 0x260E10
void __fastcall consumeInitialHiddenTokens(ANTLR3_INT_STREAM_struct *is)
{
  _BYTE *super; // rbx
  unsigned int v2; // esi
  __int64 v3; // rbp
  __int64 v4; // rdi
  __int64 v5; // rax

  super = is->super;
  v2 = 0;
  v3 = ((__int64 (*)(void))is->index)();
  if ( v3 <= 0 )
  {
    super[32] = 0;
  }
  else
  {
    do
    {
      v4 = *((_QWORD *)super + 3);
      v5 = (*((__int64 (__fastcall **)(_BYTE *, _QWORD))super + 6))(super, v2);
      (*(void (__fastcall **)(_QWORD, __int64))(v4 + 112))(*((_QWORD *)super + 3), v5);
      ++v2;
    }
    while ( (int)v2 < v3 );
    super[32] = 0;
  }
}

// File Line: 437
// RVA: 0x261070
ANTLR3_COMMON_TOKEN_struct *__fastcall dbgTokLT(ANTLR3_TOKEN_STREAM_struct *ts, int k)
{
  if ( ts->initialStreamState == 1 )
    consumeInitialHiddenTokens(ts->istream);
  return tokLT(ts, k);
}

// File Line: 456
// RVA: 0x260C00
ANTLR3_COMMON_TOKEN_struct *__fastcall LB(ANTLR3_COMMON_TOKEN_STREAM_struct *cts, unsigned int k)
{
  __int64 v2; // rbx
  int p; // r8d
  __int64 v6; // rdx
  __int64 v7; // r10
  __int64 v8; // rax
  ANTLR3_VECTOR_ELEMENT_struct *v9; // rax

  v2 = k;
  if ( cts->p == -1 )
    fillBuffer_0(cts);
  if ( !(_DWORD)v2 )
    return 0i64;
  p = cts->p;
  if ( p - (int)v2 < 0 )
    return 0i64;
  v6 = cts->p;
  if ( (int)v2 >= 1 )
  {
    v7 = v2;
    do
    {
      v8 = v6 - 1;
      --p;
      v6 = v8;
      if ( v8 >= 0 )
      {
        v9 = &cts->tokens->elements[v8];
        do
        {
          if ( *((_DWORD *)v9->element + 9) == cts->channel )
            break;
          --p;
          --v9;
          --v6;
        }
        while ( v6 >= 0 );
      }
      --v7;
    }
    while ( v7 );
  }
  if ( p >= 0 )
    return (ANTLR3_COMMON_TOKEN_struct *)cts->tokens->elements[p].element;
  else
    return 0i64;
}

// File Line: 499
// RVA: 0x261260
ANTLR3_COMMON_TOKEN_struct *__fastcall get_0(ANTLR3_TOKEN_STREAM_struct *ts, __int64 i)
{
  return (ANTLR3_COMMON_TOKEN_struct *)(*(__int64 (__fastcall **)(_QWORD, __int64))(*((_QWORD *)ts->super + 2) + 296i64))(
                                         *((_QWORD *)ts->super + 2),
                                         i);
}

// File Line: 509
// RVA: 0x2612A0
ANTLR3_TOKEN_SOURCE_struct *__fastcall getTokenSource(ANTLR3_TOKEN_STREAM_struct *ts)
{
  return ts->tokenSource;
}

// File Line: 516
// RVA: 0x2615C0
void __fastcall UFG::qThread::SetName(ANTLR3_TOKEN_STREAM_struct *ts, ANTLR3_TOKEN_SOURCE_struct *tokenSource)
{
  ts->tokenSource = tokenSource;
}

// File Line: 522
// RVA: 0x261650
ANTLR3_STRING_struct *__fastcall toString_2(ANTLR3_TOKEN_STREAM_struct *ts)
{
  ANTLR3_COMMON_TOKEN_STREAM_struct *super; // rcx
  unsigned int v3; // eax

  super = (ANTLR3_COMMON_TOKEN_STREAM_struct *)ts->super;
  if ( super->p == -1 )
    fillBuffer_0(super);
  v3 = ts->istream->size(ts->istream);
  return ts->toStringSS(ts, 0i64, v3);
}

// File Line: 537
// RVA: 0x261690
ANTLR3_STRING_struct *__fastcall toStringSS_0(ANTLR3_TOKEN_STREAM_struct *ts, unsigned int start, unsigned int stop)
{
  _DWORD *super; // rbp
  ANTLR3_TOKEN_SOURCE_struct *v7; // rax
  __int64 i; // rbp
  ANTLR3_COMMON_TOKEN_struct *v9; // rax
  __int64 v10; // rax

  super = ts->super;
  if ( super[12] == -1 )
    fillBuffer_0((ANTLR3_COMMON_TOKEN_STREAM_struct *)ts->super);
  if ( stop >= ts->istream->size(ts->istream) )
    stop = ((__int64 (__fastcall *)(ANTLR3_INT_STREAM_struct *))ts->istream->size)(ts->istream) - 1;
  v7 = ts->getTokenSource(ts);
  if ( !v7 || !*((_QWORD *)super + 2) )
    return 0i64;
  for ( i = (__int64)v7->strFactory->newRaw(v7->strFactory); start <= stop; ++start )
  {
    v9 = ts->get(ts, start);
    if ( v9 )
    {
      v10 = (__int64)v9->getText(v9);
      (*(void (__fastcall **)(__int64, __int64))(i + 88))(i, v10);
    }
  }
  return (ANTLR3_STRING_struct *)i;
}

// File Line: 582
// RVA: 0x261740
ANTLR3_STRING_struct *__fastcall toStringTT(
        ANTLR3_TOKEN_STREAM_struct *ts,
        ANTLR3_COMMON_TOKEN_struct *start,
        ANTLR3_COMMON_TOKEN_struct *stop)
{
  unsigned int v5; // ebx
  __int64 v6; // rax

  if ( !start || !stop )
    return 0i64;
  v5 = stop->getTokenIndex(stop);
  v6 = start->getTokenIndex(start);
  return ts->toStringSS(ts, v6, v5);
}

// File Line: 602
// RVA: 0x260DA0
void __fastcall consume_0(ANTLR3_INT_STREAM_struct *is)
{
  __int64 *v1; // r9
  __int64 v2; // rbx
  unsigned int v3; // r8d
  __int64 v4; // rax
  unsigned int v5; // r8d
  __int64 v6; // rdx
  __int64 v7; // r10
  __int64 v8; // rax

  v1 = (__int64 *)*((_QWORD *)is->super + 1);
  v2 = v1[2];
  v3 = *((_DWORD *)v1 + 12);
  if ( v3 < *(_DWORD *)(v2 + 8) )
  {
    v4 = *v1;
    v5 = v3 + 1;
    *((_DWORD *)v1 + 12) = v5;
    v6 = (int)v5;
    v7 = *(int *)(*(_QWORD *)(v4 + 16) + 112i64);
    if ( (int)v5 < v7 )
    {
      v8 = *(_QWORD *)v2 + 16i64 * (int)v5;
      do
      {
        if ( *(_DWORD *)(*(_QWORD *)v8 + 36i64) == *((_DWORD *)v1 + 10) )
          break;
        ++v6;
        ++v5;
        v8 += 16i64;
      }
      while ( v6 < v7 );
    }
    *((_DWORD *)v1 + 12) = v5;
  }
}

// File Line: 622
// RVA: 0x260E90
void __fastcall dbgConsume(ANTLR3_INT_STREAM_struct *is)
{
  _BYTE *super; // rbx
  __int64 v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rbp
  __int64 v6; // rdi
  __int64 v7; // rax

  super = is->super;
  if ( super[32] == 1 )
    consumeInitialHiddenTokens(is);
  v3 = is->index(is) + 1;
  v4 = (*((__int64 (__fastcall **)(_BYTE *, __int64))super + 5))(super, 1i64);
  consume_0(is);
  v5 = is->index(is);
  (*(void (__fastcall **)(_QWORD, __int64))(*((_QWORD *)super + 3) + 104i64))(*((_QWORD *)super + 3), v4);
  for ( ; v3 < v5; ++v3 )
  {
    v6 = *((_QWORD *)super + 3);
    v7 = (*((__int64 (__fastcall **)(_BYTE *, _QWORD))super + 6))(super, (unsigned int)v3);
    (*(void (__fastcall **)(_QWORD, __int64))(v6 + 112))(*((_QWORD *)super + 3), v7);
  }
}

// File Line: 668
// RVA: 0x2615D0
void __fastcall setTokenTypeChannel(
        ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream,
        unsigned int ttype,
        unsigned int channel)
{
  unsigned __int64 v4; // rsi

  v4 = ttype;
  if ( !tokenStream->channelOverrides )
    tokenStream->channelOverrides = (ANTLR3_LIST_struct *)antlr3ListNew(0xAu);
  tokenStream->channelOverrides->put(tokenStream->channelOverrides, v4, (void *)(channel + 1), 0i64);
}

// File Line: 682
// RVA: 0x2610C0
void __fastcall discardTokenType(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream, int ttype)
{
  unsigned __int64 v2; // rdi

  v2 = ttype;
  if ( !tokenStream->discardSet )
    tokenStream->discardSet = (ANTLR3_LIST_struct *)antlr3ListNew(0x1Fu);
  tokenStream->discardSet->put(tokenStream->discardSet, v2, (void *)(unsigned int)(v2 + 1), 0i64);
}

// File Line: 696
// RVA: 0x2610B0
void __fastcall discardOffChannel(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream, char discard)
{
  tokenStream->discardOffChannel = discard;
}

// File Line: 702
// RVA: 0x2612B0
ANTLR3_VECTOR_struct *__fastcall getTokens(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream)
{
  if ( tokenStream->p != -1 )
    return tokenStream->tokens;
  fillBuffer_0(tokenStream);
  return tokenStream->tokens;
}

// File Line: 713
// RVA: 0x261290
ANTLR3_LIST_struct *__fastcall getTokenRange(
        ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream,
        __int64 start,
        __int64 stop)
{
  return tokenStream->getTokensSet(tokenStream, start, stop, 0i64);
}

// File Line: 722
// RVA: 0x261340
ANTLR3_LIST_struct *__fastcall getTokensSet(
        ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream,
        unsigned int start,
        unsigned int stop,
        ANTLR3_BITSET_struct *types)
{
  unsigned int v9; // eax
  unsigned int v10; // r15d
  __int64 v11; // rdi
  ANTLR3_COMMON_TOKEN_struct *v12; // rax
  ANTLR3_COMMON_TOKEN_struct *v13; // rsi
  unsigned int v14; // eax

  if ( tokenStream->p == -1 )
    fillBuffer_0(tokenStream);
  if ( stop > tokenStream->tstream->istream->size(tokenStream->tstream->istream) )
    stop = tokenStream->tstream->istream->size(tokenStream->tstream->istream);
  if ( start > stop )
    return 0i64;
  v9 = tokenStream->tstream->istream->size(tokenStream->tstream->istream);
  v10 = 0;
  v11 = antlr3ListNew(v9);
  do
  {
    v12 = tokenStream->tstream->get(tokenStream->tstream, start);
    v13 = v12;
    if ( !types || (v14 = v12->getType(v12), types->isMember(types, v14 == 1)) )
      (*(void (__fastcall **)(__int64, _QWORD, ANTLR3_COMMON_TOKEN_struct *, _QWORD))(v11 + 48))(v11, v10++, v13, 0i64);
    ++start;
  }
  while ( start <= stop );
  if ( !(*(unsigned int (__fastcall **)(__int64))(v11 + 56))(v11) )
  {
    (*(void (__fastcall **)(__int64))(v11 + 8))(v11);
    return 0i64;
  }
  return (ANTLR3_LIST_struct *)v11;
}

// File Line: 772
// RVA: 0x2612E0
ANTLR3_LIST_struct *__fastcall getTokensList(
        ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream,
        unsigned int start,
        unsigned int stop,
        ANTLR3_LIST_struct *list)
{
  ANTLR3_BITSET_struct *v7; // rsi
  ANTLR3_LIST_struct *v8; // rbx

  v7 = antlr3BitsetList(list->table);
  v8 = tokenStream->getTokensSet(tokenStream, start, stop, v7);
  v7->free(v7);
  return v8;
}

// File Line: 788
// RVA: 0x261440
ANTLR3_LIST_struct *__fastcall getTokensType(
        ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream,
        unsigned int start,
        unsigned int stop,
        int type)
{
  UFG::allocator::free_link *v7; // rdi
  ANTLR3_LIST_struct *v8; // rbx

  v7 = antlr3BitsetOf(type, 0xFFFFFFFFi64);
  v8 = tokenStream->getTokensSet(tokenStream, start, stop, v7);
  ((void (__fastcall *)(UFG::allocator::free_link *))v7[14].mNext)(v7);
  return v8;
}

// File Line: 802
// RVA: 0x260CA0
__int64 __fastcall LA_0(ANTLR3_INT_STREAM_struct *is, __int64 i)
{
  __int64 result; // rax

  result = (*((__int64 (__fastcall **)(void *, __int64))is->super + 5))(is->super, i);
  if ( result )
    return (*(__int64 (__fastcall **)(__int64))(result + 144))(result);
  return result;
}

// File Line: 824
// RVA: 0x260F40
__int64 __fastcall dbgLA(ANTLR3_INT_STREAM_struct *is, unsigned int i)
{
  ANTLR3_TOKEN_STREAM_struct *super; // rsi
  ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger; // rbx
  ANTLR3_COMMON_TOKEN_struct *v6; // rax
  __int64 result; // rax

  super = (ANTLR3_TOKEN_STREAM_struct *)is->super;
  if ( super->initialStreamState == 1 )
    consumeInitialHiddenTokens(is);
  debugger = super->debugger;
  v6 = tokLT(super, i);
  debugger->LT(super->debugger, i, v6);
  result = (*((__int64 (__fastcall **)(void *, _QWORD))is->super + 5))(is->super, i);
  if ( result )
    return (*(__int64 (__fastcall **)(__int64))(result + 144))(result);
  return result;
}

// File Line: 839
// RVA: 0x2614A0
__int64 __fastcall mark_0(ANTLR3_INT_STREAM_struct *is)
{
  __int64 result; // rax

  result = ((__int64 (*)(void))is->index)();
  is->lastMarker = result;
  return result;
}

// File Line: 848
// RVA: 0x260FC0
__int64 __fastcall dbgMark(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *super; // rbx
  __int64 v3; // rax

  super = is->super;
  v3 = ((__int64 (*)(void))is->index)();
  is->lastMarker = v3;
  (*(void (__fastcall **)(_QWORD, __int64))(super[3] + 128i64))(super[3], v3);
  return is->lastMarker;
}

// File Line: 867
// RVA: 0x261620
__int64 __fastcall size_1(ANTLR3_INT_STREAM_struct *is)
{
  __int64 result; // rax

  result = is->cachedSize;
  if ( !(_DWORD)result )
  {
    result = *(unsigned int *)(*(_QWORD *)(*((_QWORD *)is->super + 1) + 16i64) + 8i64);
    is->cachedSize = result;
  }
  return result;
}

// File Line: 884
// RVA: 0x261640
__int64 __fastcall tindex_0(ANTLR3_INT_STREAM_struct *is)
{
  return *(int *)(*((_QWORD *)is->super + 1) + 48i64);
}

// File Line: 896
// RVA: 0x261000
void __fastcall dbgRewindLast(ANTLR3_INT_STREAM_struct *is)
{
  (*(void (__fastcall **)(_QWORD))(*((_QWORD *)is->super + 3) + 144i64))(*((_QWORD *)is->super + 3));
  is->rewind(is, is->lastMarker);
}

// File Line: 912
// RVA: 0x261530
void __fastcall rewindStream(ANTLR3_INT_STREAM_struct *is, __int64 marker)
{
  is->seek(is, (unsigned int)marker);
}

// File Line: 917
// RVA: 0x261030
void __fastcall dbgRewindStream(ANTLR3_INT_STREAM_struct *is, __int64 marker)
{
  unsigned int v3; // ebx

  v3 = marker;
  (*(void (__fastcall **)(_QWORD))(*((_QWORD *)is->super + 3) + 136i64))(*((_QWORD *)is->super + 3));
  is->seek(is, v3);
}

// File Line: 940
// RVA: 0x261540
void __fastcall seek_0(ANTLR3_INT_STREAM_struct *is, __int64 index)
{
  *(_DWORD *)(*((_QWORD *)is->super + 1) + 48i64) = index;
}

// File Line: 947
// RVA: 0x261C20
// attributes: thunk
void __fastcall fillBufferExt(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream)
{
  fillBuffer_0(tokenStream);
}

// File Line: 951
// RVA: 0x261110
void __fastcall fillBuffer_0(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream)
{
  int v2; // ebp
  unsigned int v3; // r14d
  ANTLR3_COMMON_TOKEN_struct *v4; // rbx
  ANTLR3_LIST_struct *discardSet; // rdi
  unsigned int v6; // eax
  ANTLR3_LIST_struct *channelOverrides; // rdi
  unsigned int v8; // eax
  __int64 v9; // rax
  ANTLR3_VECTOR_struct *tokens; // rax
  ANTLR3_TOKEN_STREAM_struct *tstream; // rax
  __int64 v12; // rdx
  __int64 cachedSize; // r8
  ANTLR3_VECTOR_ELEMENT_struct *elements; // rcx

  v2 = 0;
  v3 = 0;
  v4 = tokenStream->tstream->tokenSource->nextToken(tokenStream->tstream->tokenSource);
  while ( v4 )
  {
    if ( v4->type == -1 )
      break;
    if ( tokenStream->discardSet )
    {
      discardSet = tokenStream->discardSet;
      v6 = v4->getType(v4);
      if ( discardSet->get(discardSet, v6) )
        continue;
    }
    if ( tokenStream->discardOffChannel != 1 || v4->getChannel(v4) == tokenStream->channel )
    {
      if ( tokenStream->channelOverrides )
      {
        channelOverrides = tokenStream->channelOverrides;
        v8 = v4->getType(v4);
        v9 = (__int64)channelOverrides->get(channelOverrides, v8 + 1);
        if ( v9 )
          v4->setChannel(v4, v9 - 1);
      }
      v4->setTokenIndex(v4, v3);
      tokens = tokenStream->tokens;
      ++tokenStream->p;
      tokens->add(tokens, v4, 0i64);
      ++v3;
    }
    v4 = tokenStream->tstream->tokenSource->nextToken(tokenStream->tstream->tokenSource);
  }
  tokenStream->tstream->istream->cachedSize = tokenStream->tokens->count;
  tstream = tokenStream->tstream;
  tokenStream->p = 0;
  v12 = 0i64;
  cachedSize = (int)tstream->istream->cachedSize;
  if ( cachedSize > 0 )
  {
    elements = tokenStream->tokens->elements;
    do
    {
      if ( *((_DWORD *)elements->element + 9) == tokenStream->channel )
        break;
      ++v12;
      ++v2;
      ++elements;
    }
    while ( v12 < cachedSize );
  }
  tokenStream->p = v2;
}

// File Line: 1085
// RVA: 0x261280
ANTLR3_STRING_struct *__fastcall getSourceName(ANTLR3_INT_STREAM_struct *is)
{
  return *(ANTLR3_STRING_struct **)(*(_QWORD *)is->super + 552i64);
}

