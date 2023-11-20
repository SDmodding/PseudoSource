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
void __fastcall antlr3EnumFree(ANTLR3_HASH_ENUM_struct *en)
{
  antlrFree(en);
}

// File Line: 121
// RVA: 0x260CD0
void __fastcall antlr3CTSFree(ANTLR3_COMMON_TOKEN_STREAM_struct *stream)
{
  ANTLR3_TOKEN_STREAM_struct *v1; // rax
  ANTLR3_COMMON_TOKEN_STREAM_struct *v2; // rbx
  ANTLR3_INT_STREAM_struct *v3; // rdx
  ANTLR3_VECTOR_struct *v4; // rax
  ANTLR3_LIST_struct *v5; // rax
  ANTLR3_LIST_struct *v6; // rax

  v1 = stream->tstream;
  v2 = stream;
  if ( stream->tstream->super == stream )
  {
    v3 = v1->istream;
    if ( v3->super == v1 )
    {
      v3->free(v1->istream);
      v2->tstream->istream = 0i64;
    }
    v2->tstream->free(v2->tstream);
  }
  v4 = v2->tokens;
  if ( v4 )
  {
    v4->free(v2->tokens);
    v2->tokens = 0i64;
  }
  v5 = v2->discardSet;
  if ( v5 )
  {
    v5->free(v2->discardSet);
    v2->discardSet = 0i64;
  }
  v6 = v2->channelOverrides;
  if ( v6 )
  {
    v6->free(v2->channelOverrides);
    v2->channelOverrides = 0i64;
  }
  antlrFree(v2);
}

// File Line: 163
// RVA: 0x2614C0
void __fastcall reset_3(ANTLR3_COMMON_TOKEN_STREAM_struct *cts)
{
  ANTLR3_LIST_struct *v1; // rax
  ANTLR3_COMMON_TOKEN_STREAM_struct *v2; // rbx
  ANTLR3_LIST_struct *v3; // rax
  ANTLR3_VECTOR_struct *v4; // rax

  v1 = cts->discardSet;
  v2 = cts;
  if ( v1 )
  {
    v1->free(cts->discardSet);
    v2->discardSet = 0i64;
  }
  v3 = v2->channelOverrides;
  if ( v3 )
  {
    v3->free(v2->channelOverrides);
    v2->channelOverrides = 0i64;
  }
  v4 = v2->tokens;
  if ( v4 )
    v4->clear(v2->tokens);
  else
    v2->tokens = (ANTLR3_VECTOR_struct *)antlr3VectorNew(0);
  v2->discardOffChannel = 0;
  v2->channel = 0;
  v2->p = -1;
}

// File Line: 206
// RVA: 0x2618D0
ANTLR3_COMMON_TOKEN_STREAM_struct *__fastcall antlr3CommonTokenDebugStreamSourceNew(unsigned int hint, ANTLR3_TOKEN_SOURCE_struct *source, ANTLR3_DEBUG_EVENT_LISTENER_struct *debugger)
{
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v3; // rdi
  ANTLR3_TOKEN_SOURCE_struct *v4; // rbx
  ANTLR3_COMMON_TOKEN_STREAM_struct *v5; // rax
  ANTLR3_COMMON_TOKEN_STREAM_struct *v6; // rsi
  ANTLR3_TOKEN_STREAM_struct *v7; // r9
  ANTLR3_TOKEN_STREAM_struct *v8; // rcx

  v3 = debugger;
  v4 = source;
  v5 = antlr3CommonTokenStreamNew(hint);
  v6 = v5;
  v7 = v5->tstream;
  v5->channel = 0;
  v5->channelOverrides = 0i64;
  v5->discardSet = 0i64;
  v5->discardOffChannel = 0;
  v7->setTokenSource(v7, v4);
  v8 = v6->tstream;
  v6->free = antlr3CTSFree;
  v8->debugger = v3;
  v6->tstream->initialStreamState = 0;
  v6->tstream->_LT = dbgTokLT;
  v6->tstream->istream->consume = dbgConsume;
  v6->tstream->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))dbgLA;
  v6->tstream->istream->mark = dbgMark;
  v6->tstream->istream->rewind = dbgRewindStream;
  v6->tstream->istream->rewindLast = dbgRewindLast;
  v6->tstream->istream->seek = seek_0;
  return v6;
}

// File Line: 235
// RVA: 0x261BD0
UFG::allocator::free_link *__fastcall antlr3CommonTokenStreamSourceNew(unsigned int hint, ANTLR3_TOKEN_SOURCE_struct *source)
{
  ANTLR3_TOKEN_SOURCE_struct *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdi
  UFG::allocator::free_link *v5; // r8

  v2 = source;
  v3 = antlr3CommonTokenStreamNew(hint);
  v4 = v3;
  v5 = v3->mNext;
  LODWORD(v3[5].mNext) = 0;
  v3[3].mNext = 0i64;
  v3[4].mNext = 0i64;
  BYTE4(v3[5].mNext) = 0;
  ((void (__fastcall *)(UFG::allocator::free_link *, ANTLR3_TOKEN_SOURCE_struct *))v5[8].mNext)(v5, v2);
  v4[16].mNext = (UFG::allocator::free_link *)antlr3CTSFree;
  return v4;
}

// File Line: 254
// RVA: 0x2619C0
UFG::allocator::free_link *__fastcall antlr3CommonTokenStreamNew(unsigned int hint)
{
  UFG::allocator::free_link *result; // rax
  ANTLR3_COMMON_TOKEN_STREAM_struct *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rax

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
    v2->getTokensSet = (ANTLR3_LIST_struct *(__fastcall *)(ANTLR3_COMMON_TOKEN_STREAM_struct *, unsigned int, unsigned int, ANTLR3_BITSET_struct *))getTokensSet;
    v2->getTokensList = getTokensList;
    v2->getTokensType = getTokensType;
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
    result = (UFG::allocator::free_link *)v2;
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
  ANTLR3_COMMON_TOKEN_STREAM_struct *v2; // rdi
  int v3; // ebx
  ANTLR3_TOKEN_STREAM_struct *v4; // rsi
  unsigned int v6; // er8
  ANTLR3_INT_STREAM_struct *v7; // rbp
  signed __int64 v8; // rdx
  __int64 v9; // r11
  signed __int64 v10; // r9
  signed __int64 v11; // rax
  signed __int64 v12; // rax
  signed __int64 v13; // rbx
  __int64 v14; // rax
  __int64 v15; // rax

  v2 = (ANTLR3_COMMON_TOKEN_STREAM_struct *)ts->super;
  v3 = k;
  v4 = ts;
  if ( k < 0 )
    return LB(v2, -k);
  if ( v2->p == -1 )
    fillBuffer_0(v2);
  v6 = v2->p;
  v7 = v4->istream;
  if ( (signed int)(v6 + v3 - 1) < (signed int)v7->cachedSize )
  {
    v8 = v2->p;
    if ( v3 > 1 )
    {
      v9 = (unsigned int)(v3 - 1);
      v10 = (signed int)v2->tstream->istream->cachedSize;
      do
      {
        v11 = v8 + 1;
        ++v6;
        v8 = v11;
        if ( v11 < v10 )
        {
          v12 = (signed __int64)&v2->tokens->elements[v11];
          do
          {
            if ( *(_DWORD *)(*(_QWORD *)v12 + 36i64) == v2->channel )
              break;
            ++v8;
            ++v6;
            v12 += 16i64;
          }
          while ( v8 < v10 );
        }
        --v9;
      }
      while ( v9 );
    }
    if ( v6 < v7->cachedSize )
      return (ANTLR3_COMMON_TOKEN_struct *)v2->tokens->elements[v6].element;
  }
  v13 = (signed __int64)&v4->tokenSource->eofToken;
  v14 = v7->index(v4->istream);
  (*(void (__fastcall **)(signed __int64, __int64))(v13 + 232))(v13, v14);
  v15 = v4->istream->index(v4->istream);
  (*(void (__fastcall **)(signed __int64, __int64))(v13 + 248))(v13, v15);
  return (ANTLR3_COMMON_TOKEN_struct *)v13;
}

// File Line: 416
// RVA: 0x260E10
void __fastcall consumeInitialHiddenTokens(ANTLR3_INT_STREAM_struct *is)
{
  _BYTE *v1; // rbx
  unsigned int v2; // esi
  signed __int64 v3; // rbp
  __int64 v4; // rdi
  __int64 v5; // rax

  v1 = is->super;
  v2 = 0;
  v3 = ((__int64 (*)(void))is->index)();
  if ( v3 <= 0 )
  {
    v1[32] = 0;
  }
  else
  {
    do
    {
      v4 = *((_QWORD *)v1 + 3);
      v5 = (*((__int64 (__fastcall **)(_BYTE *, _QWORD))v1 + 6))(v1, v2);
      (*(void (__fastcall **)(_QWORD, __int64))(v4 + 112))(*((_QWORD *)v1 + 3), v5);
      ++v2;
    }
    while ( (signed int)v2 < v3 );
    v1[32] = 0;
  }
}

// File Line: 437
// RVA: 0x261070
ANTLR3_COMMON_TOKEN_struct *__fastcall dbgTokLT(ANTLR3_TOKEN_STREAM_struct *ts, int k)
{
  int v2; // edi
  ANTLR3_TOKEN_STREAM_struct *v3; // rbx

  v2 = k;
  v3 = ts;
  if ( ts->initialStreamState == 1 )
    consumeInitialHiddenTokens(ts->istream);
  return tokLT(v3, v2);
}

// File Line: 456
// RVA: 0x260C00
ANTLR3_COMMON_TOKEN_struct *__fastcall LB(ANTLR3_COMMON_TOKEN_STREAM_struct *cts, int k)
{
  __int64 v2; // rbx
  ANTLR3_COMMON_TOKEN_STREAM_struct *v3; // rdi
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  int v5; // er8
  signed __int64 v6; // rdx
  __int64 v7; // r10
  signed __int64 v8; // rax
  signed __int64 v9; // rax

  v2 = (unsigned int)k;
  v3 = cts;
  if ( cts->p == -1 )
    fillBuffer_0(cts);
  if ( !(_DWORD)v2 )
    goto LABEL_17;
  v5 = v3->p;
  if ( v5 - (signed int)v2 < 0 )
    goto LABEL_17;
  v6 = v3->p;
  if ( (signed int)v2 >= 1 )
  {
    v7 = v2;
    do
    {
      v8 = v6 - 1;
      --v5;
      v6 = v8;
      if ( v8 >= 0 )
      {
        v9 = (signed __int64)&v3->tokens->elements[v8];
        do
        {
          if ( *(_DWORD *)(*(_QWORD *)v9 + 36i64) == v3->channel )
            break;
          --v5;
          v9 -= 16i64;
          --v6;
        }
        while ( v6 >= 0 );
      }
      --v7;
    }
    while ( v7 );
  }
  if ( v5 >= 0 )
    result = (ANTLR3_COMMON_TOKEN_struct *)v3->tokens->elements[v5].element;
  else
LABEL_17:
    result = 0i64;
  return result;
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
  ANTLR3_TOKEN_STREAM_struct *v1; // rbx
  ANTLR3_COMMON_TOKEN_STREAM_struct *v2; // rcx
  unsigned int v3; // eax

  v1 = ts;
  v2 = (ANTLR3_COMMON_TOKEN_STREAM_struct *)ts->super;
  if ( v2->p == -1 )
    fillBuffer_0(v2);
  v3 = v1->istream->size(v1->istream);
  return (ANTLR3_STRING_struct *)v1->toStringSS(v1, 0, v3);
}

// File Line: 537
// RVA: 0x261690
ANTLR3_STRING_struct *__fastcall toStringSS_0(ANTLR3_TOKEN_STREAM_struct *ts, unsigned int start, unsigned int stop)
{
  _DWORD *v3; // rbp
  unsigned int v4; // esi
  unsigned int v5; // ebx
  ANTLR3_TOKEN_STREAM_struct *v6; // rdi
  __int64 v7; // rax
  __int64 i; // rbp
  __int64 v9; // rax
  __int64 v10; // rax

  v3 = ts->super;
  v4 = stop;
  v5 = start;
  v6 = ts;
  if ( v3[12] == -1 )
    fillBuffer_0((ANTLR3_COMMON_TOKEN_STREAM_struct *)ts->super);
  if ( v4 >= v6->istream->size(v6->istream) )
    v4 = (unsigned __int64)v6->istream->size(v6->istream) - 1;
  v7 = (__int64)v6->getTokenSource(v6);
  if ( !v7 || !*((_QWORD *)v3 + 2) )
    return 0i64;
  for ( i = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v7 + 8) + 16i64))(*(_QWORD *)(v7 + 8)); v5 <= v4; ++v5 )
  {
    v9 = (__int64)v6->get(v6, v5);
    if ( v9 )
    {
      v10 = (*(__int64 (__fastcall **)(__int64))(v9 + 120))(v9);
      (*(void (__fastcall **)(__int64, __int64))(i + 88))(i, v10);
    }
  }
  return (ANTLR3_STRING_struct *)i;
}

// File Line: 582
// RVA: 0x261740
ANTLR3_STRING_struct *__fastcall toStringTT(ANTLR3_TOKEN_STREAM_struct *ts, ANTLR3_COMMON_TOKEN_struct *start, ANTLR3_COMMON_TOKEN_struct *stop)
{
  ANTLR3_COMMON_TOKEN_struct *v3; // rdi
  ANTLR3_TOKEN_STREAM_struct *v4; // rsi
  unsigned int v5; // ebx
  __int64 v6; // rax

  v3 = start;
  v4 = ts;
  if ( !start || !stop )
    return 0i64;
  v5 = stop->getTokenIndex(stop);
  v6 = v3->getTokenIndex(v3);
  return (ANTLR3_STRING_struct *)v4->toStringSS(v4, v6, v5);
}

// File Line: 602
// RVA: 0x260DA0
void __fastcall consume_0(ANTLR3_INT_STREAM_struct *is)
{
  __int64 *v1; // r9
  __int64 v2; // rbx
  unsigned int v3; // er8
  __int64 v4; // rax
  int v5; // er8
  signed __int64 v6; // rdx
  signed __int64 v7; // r10
  signed __int64 v8; // rax

  v1 = (__int64 *)*((_QWORD *)is->super + 1);
  v2 = v1[2];
  v3 = *((_DWORD *)v1 + 12);
  if ( v3 < *(_DWORD *)(v2 + 8) )
  {
    v4 = *v1;
    v5 = v3 + 1;
    *((_DWORD *)v1 + 12) = v5;
    v6 = v5;
    v7 = *(signed int *)(*(_QWORD *)(v4 + 16) + 112i64);
    if ( v5 < v7 )
    {
      v8 = *(_QWORD *)v2 + 16i64 * v5;
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
  _BYTE *v1; // rbx
  ANTLR3_INT_STREAM_struct *v2; // rbp
  __int64 v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rbp
  __int64 v6; // rdi
  __int64 v7; // rax

  v1 = is->super;
  v2 = is;
  if ( v1[32] == 1 )
    consumeInitialHiddenTokens(is);
  v3 = v2->index(v2) + 1;
  v4 = (*((__int64 (__fastcall **)(_BYTE *, signed __int64))v1 + 5))(v1, 1i64);
  consume_0(v2);
  v5 = v2->index(v2);
  (*(void (__fastcall **)(_QWORD, __int64))(*((_QWORD *)v1 + 3) + 104i64))(*((_QWORD *)v1 + 3), v4);
  if ( v5 > v3 && v3 < v5 )
  {
    do
    {
      v6 = *((_QWORD *)v1 + 3);
      v7 = (*((__int64 (__fastcall **)(_BYTE *, _QWORD))v1 + 6))(v1, (unsigned int)v3);
      (*(void (__fastcall **)(_QWORD, __int64))(v6 + 112))(*((_QWORD *)v1 + 3), v7);
      ++v3;
    }
    while ( v3 < v5 );
  }
}

// File Line: 668
// RVA: 0x2615D0
void __fastcall setTokenTypeChannel(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream, unsigned int ttype, unsigned int channel)
{
  unsigned int v3; // edi
  unsigned __int64 v4; // rsi
  ANTLR3_COMMON_TOKEN_STREAM_struct *v5; // rbx

  v3 = channel;
  v4 = ttype;
  v5 = tokenStream;
  if ( !tokenStream->channelOverrides )
    tokenStream->channelOverrides = (ANTLR3_LIST_struct *)antlr3ListNew(0xAu);
  v5->channelOverrides->put(v5->channelOverrides, v4, (void *)(v3 + 1), 0i64);
}

// File Line: 682
// RVA: 0x2610C0
void __fastcall discardTokenType(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream, int ttype)
{
  unsigned __int64 v2; // rdi
  ANTLR3_COMMON_TOKEN_STREAM_struct *v3; // rbx

  v2 = ttype;
  v3 = tokenStream;
  if ( !tokenStream->discardSet )
    tokenStream->discardSet = (ANTLR3_LIST_struct *)antlr3ListNew(0x1Fu);
  v3->discardSet->put(v3->discardSet, v2, (void *)(unsigned int)(v2 + 1), 0i64);
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
  ANTLR3_COMMON_TOKEN_STREAM_struct *v1; // rbx

  v1 = tokenStream;
  if ( tokenStream->p != -1 )
    return tokenStream->tokens;
  fillBuffer_0(tokenStream);
  return v1->tokens;
}

// File Line: 713
// RVA: 0x261290
ANTLR3_LIST_struct *__fastcall getTokenRange(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream, __int64 start, __int64 stop)
{
  return (ANTLR3_LIST_struct *)tokenStream->getTokensSet(tokenStream, start, stop, 0i64);
}

// File Line: 722
// RVA: 0x261340
UFG::allocator::free_link *__fastcall getTokensSet(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream, unsigned int start, unsigned int stop, ANTLR3_BITSET_struct *types)
{
  ANTLR3_BITSET_struct *v4; // r12
  unsigned int v5; // ebp
  unsigned int v6; // ebx
  ANTLR3_COMMON_TOKEN_STREAM_struct *v7; // r14
  unsigned int v9; // eax
  unsigned int v10; // er15
  UFG::allocator::free_link *v11; // rdi
  __int64 v12; // rax
  __int64 v13; // rsi
  int v14; // eax

  v4 = types;
  v5 = stop;
  v6 = start;
  v7 = tokenStream;
  if ( tokenStream->p == -1 )
    fillBuffer_0(tokenStream);
  if ( v5 > v7->tstream->istream->size(v7->tstream->istream) )
    v5 = v7->tstream->istream->size(v7->tstream->istream);
  if ( v6 > v5 )
    return 0i64;
  v9 = v7->tstream->istream->size(v7->tstream->istream);
  v10 = 0;
  v11 = antlr3ListNew(v9);
  do
  {
    v12 = (__int64)v7->tstream->get(v7->tstream, v6);
    v13 = v12;
    if ( !v4 || (v14 = (*(__int64 (__fastcall **)(__int64))(v12 + 144))(v12), v4->isMember(v4, v14 == 1)) )
      ((void (__fastcall *)(UFG::allocator::free_link *, _QWORD, __int64, _QWORD))v11[6].mNext)(v11, v10++, v13, 0i64);
    ++v6;
  }
  while ( v6 <= v5 );
  if ( !((unsigned int (__fastcall *)(UFG::allocator::free_link *))v11[7].mNext)(v11) )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v11[1].mNext)(v11);
    v11 = 0i64;
  }
  return v11;
}

// File Line: 772
// RVA: 0x2612E0
ANTLR3_LIST_struct *__fastcall getTokensList(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream, unsigned int start, unsigned int stop, ANTLR3_LIST_struct *list)
{
  ANTLR3_COMMON_TOKEN_STREAM_struct *v4; // rbp
  unsigned int v5; // ebx
  unsigned int v6; // edi
  ANTLR3_BITSET_struct *v7; // rsi
  __int64 v8; // rbx

  v4 = tokenStream;
  v5 = stop;
  v6 = start;
  v7 = antlr3BitsetList(list->table);
  v8 = (__int64)v4->getTokensSet(v4, v6, v5, v7);
  v7->free(v7);
  return (ANTLR3_LIST_struct *)v8;
}

// File Line: 788
// RVA: 0x261440
ANTLR3_LIST_struct *__fastcall getTokensType(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream, unsigned int start, unsigned int stop, unsigned int type)
{
  unsigned int v4; // esi
  ANTLR3_COMMON_TOKEN_STREAM_struct *v5; // rbp
  unsigned int v6; // ebx
  UFG::allocator::free_link *v7; // rdi
  __int64 v8; // rbx

  v4 = start;
  v5 = tokenStream;
  v6 = stop;
  v7 = antlr3BitsetOf(type, 0xFFFFFFFFi64);
  v8 = (__int64)v5->getTokensSet(v5, v4, v6, (ANTLR3_BITSET_struct *)v7);
  ((void (__fastcall *)(UFG::allocator::free_link *))v7[14].mNext)(v7);
  return (ANTLR3_LIST_struct *)v8;
}

// File Line: 802
// RVA: 0x260CA0
__int64 __fastcall LA_0(ANTLR3_INT_STREAM_struct *is, __int64 i)
{
  __int64 result; // rax

  result = (*((__int64 (__fastcall **)(void *, __int64))is->super + 5))(is->super, i);
  if ( result )
    result = (*(__int64 (__fastcall **)(__int64))(result + 144))(result);
  return result;
}

// File Line: 824
// RVA: 0x260F40
__int64 __fastcall dbgLA(ANTLR3_INT_STREAM_struct *is, int i)
{
  ANTLR3_TOKEN_STREAM_struct *v2; // rsi
  unsigned int v3; // ebp
  ANTLR3_INT_STREAM_struct *v4; // rdi
  ANTLR3_DEBUG_EVENT_LISTENER_struct *v5; // rbx
  ANTLR3_COMMON_TOKEN_struct *v6; // rax
  __int64 result; // rax

  v2 = (ANTLR3_TOKEN_STREAM_struct *)is->super;
  v3 = i;
  v4 = is;
  if ( v2->initialStreamState == 1 )
    consumeInitialHiddenTokens(is);
  v5 = v2->debugger;
  v6 = tokLT(v2, v3);
  v5->LT(v2->debugger, v3, v6);
  result = (*((__int64 (__fastcall **)(void *, _QWORD))v4->super + 5))(v4->super, v3);
  if ( result )
    result = (*(__int64 (__fastcall **)(__int64))(result + 144))(result);
  return result;
}

// File Line: 839
// RVA: 0x2614A0
__int64 __fastcall mark_0(ANTLR3_INT_STREAM_struct *is)
{
  ANTLR3_INT_STREAM_struct *v1; // rbx
  __int64 result; // rax

  v1 = is;
  result = ((__int64 (*)(void))is->index)();
  v1->lastMarker = result;
  return result;
}

// File Line: 848
// RVA: 0x260FC0
__int64 __fastcall dbgMark(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *v1; // rbx
  ANTLR3_INT_STREAM_struct *v2; // rdi
  __int64 v3; // rax

  v1 = is->super;
  v2 = is;
  v3 = ((__int64 (*)(void))is->index)();
  v2->lastMarker = v3;
  (*(void (__fastcall **)(_QWORD, __int64))(v1[3] + 128i64))(v1[3], v3);
  return v2->lastMarker;
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
  return *(signed int *)(*((_QWORD *)is->super + 1) + 48i64);
}

// File Line: 896
// RVA: 0x261000
void __fastcall dbgRewindLast(ANTLR3_INT_STREAM_struct *is)
{
  ANTLR3_INT_STREAM_struct *v1; // rbx

  v1 = is;
  (*(void (__fastcall **)(_QWORD))(*((_QWORD *)is->super + 3) + 144i64))(*((_QWORD *)is->super + 3));
  v1->rewind(v1, v1->lastMarker);
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
  ANTLR3_INT_STREAM_struct *v2; // rdi
  unsigned int v3; // ebx

  v2 = is;
  v3 = marker;
  (*(void (__fastcall **)(_QWORD))(*((_QWORD *)is->super + 3) + 136i64))(*((_QWORD *)is->super + 3));
  v2->seek(v2, v3);
}

// File Line: 940
// RVA: 0x261540
void __fastcall seek_0(ANTLR3_INT_STREAM_struct *is, __int64 index)
{
  *(_DWORD *)(*((_QWORD *)is->super + 1) + 48i64) = index;
}

// File Line: 947
// RVA: 0x261C20
void __fastcall fillBufferExt(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream)
{
  fillBuffer_0(tokenStream);
}

// File Line: 951
// RVA: 0x261110
void __fastcall fillBuffer_0(ANTLR3_COMMON_TOKEN_STREAM_struct *tokenStream)
{
  ANTLR3_COMMON_TOKEN_STREAM_struct *v1; // rsi
  int v2; // ebp
  unsigned int v3; // er14
  ANTLR3_COMMON_TOKEN_struct *v4; // rbx
  ANTLR3_LIST_struct *v5; // rdi
  unsigned int v6; // eax
  ANTLR3_LIST_struct *v7; // rdi
  unsigned int v8; // eax
  __int64 v9; // rax
  ANTLR3_VECTOR_struct *v10; // rax
  ANTLR3_TOKEN_STREAM_struct *v11; // rax
  __int64 v12; // rdx
  __int64 v13; // r8
  ANTLR3_VECTOR_ELEMENT_struct *v14; // rcx

  v1 = tokenStream;
  v2 = 0;
  v3 = 0;
  v4 = tokenStream->tstream->tokenSource->nextToken(tokenStream->tstream->tokenSource);
  while ( v4 )
  {
    if ( v4->type == -1 )
      break;
    if ( v1->discardSet )
    {
      v5 = v1->discardSet;
      v6 = v4->getType(v4);
      if ( v5->get(v5, v6) )
        continue;
    }
    if ( v1->discardOffChannel != 1 || v4->getChannel(v4) == v1->channel )
    {
      if ( v1->channelOverrides )
      {
        v7 = v1->channelOverrides;
        v8 = v4->getType(v4);
        v9 = (__int64)v7->get(v7, v8 + 1);
        if ( v9 )
          v4->setChannel(v4, v9 - 1);
      }
      v4->setTokenIndex(v4, v3);
      v10 = v1->tokens;
      ++v1->p;
      v10->add(v10, v4, 0i64);
      ++v3;
    }
    v4 = v1->tstream->tokenSource->nextToken(v1->tstream->tokenSource);
  }
  v1->tstream->istream->cachedSize = v1->tokens->count;
  v11 = v1->tstream;
  v1->p = 0;
  v12 = 0i64;
  v13 = (signed int)v11->istream->cachedSize;
  if ( v13 > 0 )
  {
    v14 = v1->tokens->elements;
    do
    {
      if ( *((_DWORD *)v14->element + 9) == v1->channel )
        break;
      ++v12;
      ++v2;
      ++v14;
    }
    while ( v12 < v13 );
  }
  v1->p = v2;
}

// File Line: 1085
// RVA: 0x261280
ANTLR3_STRING_struct *__fastcall getSourceName(ANTLR3_INT_STREAM_struct *is)
{
  return *(ANTLR3_STRING_struct **)(*(_QWORD *)is->super + 552i64);
}

