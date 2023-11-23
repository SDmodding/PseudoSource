// File Line: 129
// RVA: 0x25DC00
void __fastcall antlr38BitSetupStream(ANTLR3_INPUT_STREAM_struct *input)
{
  input->strFactory = antlr3StringFactoryNew(input->encoding);
}

// File Line: 140
// RVA: 0x25DC60
void __fastcall antlr3GenericSetupStream(ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_INT_STREAM_struct *v2; // rax

  v2 = antlr3IntStreamNew();
  input->istream = v2;
  v2->type = 1;
  input->istream->super = input;
  input->istream->consume = antlr38BitConsume;
  input->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr38BitLA;
  input->istream->index = antlr3UTF32Index;
  input->istream->mark = antlr38BitMark;
  input->istream->rewind = antlr38BitRewind;
  input->istream->rewindLast = antlr38BitRewindLast;
  input->istream->seek = antlr38BitSeek;
  input->istream->release = antlr38BitRelease;
  input->istream->getSourceName = (ANTLR3_STRING_struct *(__fastcall *)(ANTLR3_INT_STREAM_struct *))Scaleform::GFx::Stream::GetLog;
  input->close = antlr3InputClose;
  input->free = antlr3InputClose;
  input->reset = antlr3InputReset;
  input->charByteSize = 1;
  input->reuse = antlr38BitReuse;
  input->markers = 0i64;
  input->_LT = (void *(__fastcall *)(ANTLR3_INPUT_STREAM_struct *, int))antlr38BitLT;
  input->size = (unsigned int (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))hkaSparseLSQMatrix<float>::Height;
  input->substr = (ANTLR3_STRING_struct *(__fastcall *)(ANTLR3_INPUT_STREAM_struct *, __int64, __int64))antlr38BitSubstr;
  input->getLine = (unsigned int (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))Scaleform::Render::MemoryBufferImage::GetUse;
  input->getLineBuf = (void *(__fastcall *)(ANTLR3_INPUT_STREAM_struct *))hkDataArrayNative::getType;
  input->getCharPositionInLine = UFG::UIGfxMemoryFile::GetLength;
  input->setLine = antlr38BitSetLine;
  input->setCharPositionInLine = (void (__fastcall *)(ANTLR3_INPUT_STREAM_struct *, unsigned int))PoseNode::SetPlayPriority;
  input->SetNewLineChar = UFG::UIScreenTextureManager::SetGameState;
  input->setUcaseLA = antlr38BitSetUcaseLA;
  antlr3InputReset(input);
  input->SetNewLineChar(input, 10u);
}

// File Line: 207
// RVA: 0x25D2B0
void __fastcall antlr3InputClose(ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_VECTOR_struct *markers; // rax
  ANTLR3_STRING_FACTORY_struct *strFactory; // rax
  char *data; // rcx

  markers = input->markers;
  if ( markers )
  {
    markers->free(input->markers);
    input->markers = 0i64;
  }
  strFactory = input->strFactory;
  if ( strFactory )
    strFactory->close(input->strFactory);
  if ( input->isAllocated )
  {
    data = (char *)input->data;
    if ( data )
    {
      antlrFree(data);
      input->data = 0i64;
    }
  }
  input->istream->free(input->istream);
  antlrFree((char *)input);
}

// File Line: 243
// RVA: 0x25D240
void __fastcall antlr38BitSetUcaseLA(ANTLR3_INPUT_STREAM_struct *input, char flag)
{
  ANTLR3_INT_STREAM_struct *istream; // rax
  unsigned int (__fastcall *v3)(ANTLR3_INT_STREAM_struct *, int); // rcx

  istream = input->istream;
  v3 = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr38BitLA_ucase;
  if ( !flag )
    v3 = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr38BitLA;
  istream->_LA = v3;
}

// File Line: 265
// RVA: 0x25D320
void __fastcall antlr3InputReset(ANTLR3_INPUT_STREAM_struct *input)
{
  void *data; // rax
  ANTLR3_VECTOR_struct *markers; // rax

  data = input->data;
  input->line = 1;
  input->nextChar = data;
  input->currentLine = data;
  markers = input->markers;
  input->charPositionInLine = -1;
  input->markDepth = 0;
  if ( markers )
    markers->clear(markers);
  else
    input->markers = (ANTLR3_VECTOR_struct *)antlr3VectorNew(0);
}

// File Line: 292
// RVA: 0x25D090
void __fastcall antlr38BitReuse(ANTLR3_INPUT_STREAM_struct *input, char *inString, unsigned int size, char *name)
{
  ANTLR3_INT_STREAM_struct *istream; // rax
  ANTLR3_STRING_struct *streamName; // r8

  istream = input->istream;
  input->isAllocated = 0;
  input->data = inString;
  input->sizeBuf = size;
  streamName = istream->streamName;
  if ( streamName )
  {
    if ( !name )
      name = "-memory-";
    streamName->set(istream->streamName, name);
    input->reset(input);
  }
  else
  {
    if ( !name )
      name = "-memory-";
    input->istream->streamName = input->strFactory->newStr(input->strFactory, name);
    input->fileName = input->istream->streamName;
    input->reset(input);
  }
}

// File Line: 319
// RVA: 0x25CF20
void __fastcall antlr38BitConsume(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *super; // rdx
  unsigned __int8 *v2; // rcx

  super = is->super;
  v2 = (unsigned __int8 *)super[5];
  if ( (unsigned __int64)v2 < super[2] + (unsigned __int64)*((unsigned int *)super + 12) )
  {
    ++*((_DWORD *)super + 16);
    if ( *v2 == *((_DWORD *)super + 52) )
    {
      ++*((_DWORD *)super + 13);
      *((_DWORD *)super + 16) = 0;
      super[7] = v2 + 1;
    }
    super[5] = v2 + 1;
  }
}

// File Line: 354
// RVA: 0x25CF70
__int64 __fastcall antlr38BitLA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // r8
  unsigned __int8 *v3; // rdx

  super = is->super;
  v3 = (unsigned __int8 *)(super[5] + la - 1i64);
  if ( (unsigned __int64)v3 < super[2] + (unsigned __int64)*((unsigned int *)super + 12) )
    return *v3;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 381
// RVA: 0x25CFA0
int __fastcall antlr38BitLA_ucase(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // r8
  unsigned __int8 *v3; // rdx

  super = is->super;
  v3 = (unsigned __int8 *)(super[5] + la - 1i64);
  if ( (unsigned __int64)v3 < super[2] + (unsigned __int64)*((unsigned int *)super + 12) )
    return toupper_0(*v3);
  else
    return -1;
}

// File Line: 406
// RVA: 0x25CFD0
unsigned __int64 __fastcall antlr38BitLT(ANTLR3_INPUT_STREAM_struct *input, __int64 lt)
{
  return input->istream->_LA(input->istream, lt);
}

// File Line: 420
// RVA: 0x25D510
__int64 __fastcall antlr3UTF32Index(ANTLR3_INT_STREAM_struct *is)
{
  return *((_QWORD *)is->super + 5);
}

// File Line: 449
// RVA: 0x25CFF0
__int64 __fastcall antlr38BitMark(ANTLR3_INT_STREAM_struct *is)
{
  char *super; // rbx
  __int64 v3; // rax
  unsigned int v4; // edx
  UFG::allocator::free_link *v5; // rdi

  super = (char *)is->super;
  ++*((_DWORD *)super + 17);
  v3 = *((_QWORD *)super + 9);
  v4 = *((_DWORD *)super + 17);
  if ( v4 <= *(_DWORD *)(v3 + 8) )
  {
    v5 = (UFG::allocator::free_link *)(*(__int64 (__fastcall **)(_QWORD, _QWORD))(v3 + 296))(
                                        *((_QWORD *)super + 9),
                                        v4 - 1);
  }
  else
  {
    v5 = antlrMalloc(0x20ui64);
    (*(void (__fastcall **)(_QWORD, UFG::allocator::free_link *, void (__fastcall *)(char *)))(*((_QWORD *)super + 9)
                                                                                             + 328i64))(
      *((_QWORD *)super + 9),
      v5,
      antlrFree);
  }
  LODWORD(v5[3].mNext) = *((_DWORD *)super + 16);
  v5[2].mNext = *(UFG::allocator::free_link **)(super + 56);
  LODWORD(v5[1].mNext) = *((_DWORD *)super + 13);
  v5->mNext = *(UFG::allocator::free_link **)(super + 40);
  is->lastMarker = *((unsigned int *)super + 17);
  return *((unsigned int *)super + 17);
}

// File Line: 502
// RVA: 0x25D1C0
void __fastcall antlr38BitRewindLast(ANTLR3_INT_STREAM_struct *is)
{
  is->rewind(is, is->lastMarker);
}

// File Line: 515
// RVA: 0x25D120
void __fastcall antlr38BitRewind(ANTLR3_INT_STREAM_struct *is, __int64 mark)
{
  _QWORD *super; // rsi
  int v4; // ebx
  __int64 v5; // r14
  __int64 v6; // rbx
  _QWORD *v7; // rax
  __int64 v8; // rcx
  int i; // ebx

  super = is->super;
  v4 = mark;
  (*(void (__fastcall **)(_QWORD))(*super + 88i64))(*super);
  v5 = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(super[9] + 296i64))(super[9], (unsigned int)(v4 - 1));
  v6 = *(_QWORD *)v5;
  v7 = is->super;
  v8 = v7[5];
  if ( *(_QWORD *)v5 > v8 )
  {
    for ( i = v6 - v8; i; --i )
      is->consume(is);
  }
  else
  {
    v7[5] = v6;
  }
  *((_DWORD *)super + 16) = *(_DWORD *)(v5 + 24);
  super[7] = *(_QWORD *)(v5 + 16);
  *((_DWORD *)super + 13) = *(_DWORD *)(v5 + 8);
  super[5] = *(_QWORD *)v5;
}

// File Line: 554
// RVA: 0x25D080
void __fastcall antlr38BitRelease(ANTLR3_INT_STREAM_struct *is, __int64 mark)
{
  *((_DWORD *)is->super + 17) = mark - 1;
}

// File Line: 574
// RVA: 0x25D1D0
void __fastcall antlr38BitSeek(ANTLR3_INT_STREAM_struct *is, __int64 seekPoint)
{
  _QWORD *super; // rax
  __int64 v4; // rcx
  int v5; // ebx

  super = is->super;
  v4 = super[5];
  if ( seekPoint > v4 )
  {
    v5 = seekPoint - v4;
    if ( (_DWORD)seekPoint != (_DWORD)v4 )
    {
      do
      {
        is->consume(is);
        --v5;
      }
      while ( v5 );
    }
  }
  else
  {
    super[5] = seekPoint;
  }
}

// File Line: 607
// RVA: 0x25D260
ANTLR3_STRING_struct *__fastcall antlr38BitSubstr(ANTLR3_INPUT_STREAM_struct *input, char *start, __int64 stop)
{
  return input->strFactory->newPtr(input->strFactory, start, (unsigned int)(stop - (_DWORD)start + 1));
}

// File Line: 618
// RVA: 0x25CF60
__int64 __fastcall Scaleform::Render::MemoryBufferImage::GetUse(ANTLR3_INPUT_STREAM_struct *input)
{
  return input->line;
}

// File Line: 658
// RVA: 0x25D230
void __fastcall antlr38BitSetLine(ANTLR3_INPUT_STREAM_struct *input, unsigned int line)
{
  input->line = line;
}

// File Line: 673
// RVA: 0x25D220
void __fastcall PoseNode::SetPlayPriority(ANTLR3_INPUT_STREAM_struct *input, int position)
{
  input->charPositionInLine = position;
}

// File Line: 706
// RVA: 0x25DDE0
void __fastcall antlr3UTF16SetupStream(
        ANTLR3_INPUT_STREAM_struct *input,
        unsigned __int8 machineBigEndian,
        char inputBigEndian)
{
  int v5; // ebx
  ANTLR3_INT_STREAM_struct *istream; // rax
  __int64 (__fastcall *v7)(ANTLR3_INT_STREAM_struct *, int); // rcx

  v5 = machineBigEndian;
  input->strFactory = antlr3StringFactoryNew(input->encoding);
  input->istream->index = antlr3UTF32Index;
  input->substr = (ANTLR3_STRING_struct *(__fastcall *)(ANTLR3_INPUT_STREAM_struct *, __int64, __int64))antlr3UTF16Substr;
  input->istream->seek = antlr3UTF32Seek;
  if ( !(_BYTE)v5 )
  {
    istream = input->istream;
    if ( inputBigEndian )
    {
      istream->consume = antlr3UTF16ConsumeBE;
      v7 = antlr3UTF16LABE;
      goto LABEL_8;
    }
    goto LABEL_4;
  }
  if ( v5 == 1 )
  {
    istream = input->istream;
    if ( inputBigEndian != 1 )
    {
      istream->consume = antlr3UTF16ConsumeLE;
      v7 = antlr3UTF16LALE;
      goto LABEL_8;
    }
LABEL_4:
    istream->consume = antlr3UTF16Consume;
    v7 = antlr3UTF16LA;
LABEL_8:
    input->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))v7;
  }
  input->charByteSize = 2;
}

// File Line: 782
// RVA: 0x25D380
void __fastcall antlr3UTF16Consume(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *super; // rdx
  unsigned __int16 *v2; // rcx
  unsigned __int64 v3; // r8
  int v4; // eax
  unsigned __int16 *v5; // rcx

  super = is->super;
  v2 = (unsigned __int16 *)super[5];
  v3 = super[2] + *((unsigned int *)super + 12);
  if ( (unsigned __int64)v2 < v3 )
  {
    ++*((_DWORD *)super + 16);
    if ( *v2 == *((_DWORD *)super + 52) )
    {
      ++*((_DWORD *)super + 13);
      *((_DWORD *)super + 16) = 0;
      super[7] = v2 + 1;
    }
    v4 = *v2;
    v5 = v2 + 1;
    super[5] = v5;
    if ( (unsigned int)(v4 - 55296) <= 0x3FF && (unsigned __int64)v5 < v3 && (unsigned int)*v5 - 56320 <= 0x3FF )
      super[5] = v5 + 1;
  }
}

// File Line: 861
// RVA: 0x25D520
__int64 __fastcall antlr3UTF16LA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // r10
  int v3; // r9d
  unsigned __int16 *v4; // rax
  int v5; // r9d
  unsigned __int64 v6; // rdx
  int v7; // ecx
  int v8; // ecx
  unsigned __int64 v9; // r8
  unsigned int v11; // edx
  unsigned __int16 *v12; // rax
  int v13; // r8d

  super = is->super;
  v3 = la;
  v4 = (unsigned __int16 *)super[5];
  if ( la < 0 )
  {
    do
    {
      ++v3;
      if ( (unsigned __int64)v4 <= super[2] )
        break;
      v8 = *--v4;
      if ( (unsigned int)(v8 - 56320) <= 0x3FF && (unsigned int)*(v4 - 1) - 55296 <= 0x3FF )
        --v4;
    }
    while ( v3 < 0 );
  }
  else
  {
    v5 = la - 1;
    if ( la - 1 > 0 )
    {
      v6 = super[2] + *((unsigned int *)super + 12);
      do
      {
        if ( (unsigned __int64)v4 >= v6 )
          break;
        v7 = *v4++;
        if ( (unsigned int)(v7 - 55296) <= 0x3FF && (unsigned __int64)v4 < v6 && (unsigned int)*v4 - 56320 <= 0x3FF )
          ++v4;
        --v5;
      }
      while ( v5 > 0 );
    }
  }
  v9 = super[2] + *((unsigned int *)super + 12);
  if ( (unsigned __int64)v4 >= v9 )
    return 0xFFFFFFFFi64;
  v11 = *v4;
  v12 = v4 + 1;
  if ( v11 - 55296 <= 0x3FF && (unsigned __int64)v12 < v9 )
  {
    v13 = *v12;
    if ( (unsigned int)(v13 - 56320) <= 0x3FF )
      return v13 + ((v11 - 55287) << 10);
  }
  return v11;
}

// File Line: 1017
// RVA: 0x25D850
void __fastcall antlr3UTF32Seek(ANTLR3_INT_STREAM_struct *is, __int64 seekPoint)
{
  _QWORD *super; // rsi

  super = is->super;
  if ( seekPoint > super[5] )
  {
    while ( is->_LA(is, 1) != -1 )
    {
      if ( seekPoint >= super[5] )
        break;
      is->consume(is);
    }
  }
  else
  {
    super[5] = seekPoint;
  }
}

// File Line: 1050
// RVA: 0x25D8C0
ANTLR3_STRING_struct *__fastcall antlr3UTF16Substr(ANTLR3_INPUT_STREAM_struct *input, char *start, __int64 stop)
{
  return input->strFactory->newPtr(input->strFactory, start, ((unsigned int)(stop - (_DWORD)start) >> 1) + 1);
}

// File Line: 1064
// RVA: 0x25D480
void __fastcall antlr3UTF16ConsumeLE(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *super; // rdx
  unsigned __int16 *v2; // r8
  unsigned __int64 v3; // r9
  int v4; // ecx
  int v5; // eax
  unsigned __int8 *v6; // r8

  super = is->super;
  v2 = (unsigned __int16 *)super[5];
  v3 = super[2] + *((unsigned int *)super + 12);
  if ( (unsigned __int64)v2 < v3 )
  {
    ++*((_DWORD *)super + 16);
    if ( *v2 == *((_DWORD *)super + 52) )
    {
      ++*((_DWORD *)super + 13);
      *((_DWORD *)super + 16) = 0;
      super[7] = v2 + 1;
    }
    v4 = *((unsigned __int8 *)v2 + 1);
    v5 = *(unsigned __int8 *)v2;
    v6 = (unsigned __int8 *)(v2 + 1);
    super[5] = v6;
    if ( (unsigned int)((v4 << 8) + v5 - 55296) <= 0x3FF
      && (unsigned __int64)v6 < v3
      && (v6[1] << 8) + (unsigned int)*v6 - 56320 <= 0x3FF )
    {
      super[5] = v6 + 2;
    }
  }
}

// File Line: 1141
// RVA: 0x25D730
__int64 __fastcall antlr3UTF16LALE(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // r10
  int v3; // r9d
  int *v4; // rax
  int v5; // r9d
  unsigned __int64 v6; // rdx
  int v7; // ecx
  int v8; // edx
  unsigned __int64 v9; // r8
  int v11; // edx
  _DWORD *v12; // rax
  unsigned int v13; // edx
  int v14; // r8d

  super = is->super;
  v3 = la;
  v4 = (int *)super[5];
  if ( la < 0 )
  {
    do
    {
      ++v3;
      if ( (unsigned __int64)v4 <= super[2] )
        break;
      v8 = *v4;
      v4 -= 2;
      if ( (unsigned int)(v8 + ((v8 - 1) << 8) - 56322) <= 0x3FF
        && (unsigned int)(*v4 + ((*v4 - 1) << 8) - 55298) <= 0x3FF )
      {
        v4 -= 2;
      }
    }
    while ( v3 < 0 );
  }
  else
  {
    v5 = la - 1;
    if ( la - 1 > 0 )
    {
      v6 = super[2] + *((unsigned int *)super + 12);
      do
      {
        if ( (unsigned __int64)v4 >= v6 )
          break;
        v7 = v4[1];
        v4 += 2;
        if ( (unsigned int)(*(v4 - 2) + (v7 << 8) - 55296) <= 0x3FF
          && (unsigned __int64)v4 < v6
          && (unsigned int)(*v4 + (v4[1] << 8) - 56320) <= 0x3FF )
        {
          v4 += 2;
        }
        --v5;
      }
      while ( v5 > 0 );
    }
  }
  v9 = super[2] + *((unsigned int *)super + 12);
  if ( (unsigned __int64)v4 >= v9 )
    return 0xFFFFFFFFi64;
  v11 = v4[1];
  v12 = v4 + 2;
  v13 = *(v12 - 2) + (v11 << 8);
  if ( v13 - 55296 <= 0x3FF && (unsigned __int64)v12 < v9 )
  {
    v14 = *v12 + (v12[1] << 8);
    if ( (unsigned int)(v14 - 56320) <= 0x3FF )
      return v14 + ((v13 - 55287) << 10);
  }
  return v13;
}

// File Line: 1283
// RVA: 0x25D3F0
void __fastcall antlr3UTF16ConsumeBE(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *super; // rdx
  unsigned __int16 *v2; // r8
  unsigned __int64 v3; // r9
  int v4; // ecx
  int v5; // eax
  unsigned __int8 *v6; // r8

  super = is->super;
  v2 = (unsigned __int16 *)super[5];
  v3 = super[2] + *((unsigned int *)super + 12);
  if ( (unsigned __int64)v2 < v3 )
  {
    ++*((_DWORD *)super + 16);
    if ( *v2 == *((_DWORD *)super + 52) )
    {
      ++*((_DWORD *)super + 13);
      *((_DWORD *)super + 16) = 0;
      super[7] = v2 + 1;
    }
    v4 = *(unsigned __int8 *)v2;
    v5 = *((unsigned __int8 *)v2 + 1);
    v6 = (unsigned __int8 *)(v2 + 1);
    super[5] = v6;
    if ( (unsigned int)((v4 << 8) + v5 - 55296) <= 0x3FF
      && (unsigned __int64)v6 < v3
      && (*v6 << 8) + (unsigned int)v6[1] - 56320 <= 0x3FF )
    {
      super[5] = v6 + 2;
    }
  }
}

// File Line: 1362
// RVA: 0x25D610
__int64 __fastcall antlr3UTF16LABE(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // r10
  int v3; // r9d
  int *v4; // rax
  int v5; // r9d
  unsigned __int64 v6; // rdx
  int v7; // ecx
  int v8; // edx
  unsigned __int64 v9; // r8
  int v11; // edx
  _DWORD *v12; // rax
  unsigned int v13; // edx
  int v14; // r8d

  super = is->super;
  v3 = la;
  v4 = (int *)super[5];
  if ( la < 0 )
  {
    do
    {
      ++v3;
      if ( (unsigned __int64)v4 <= super[2] )
        break;
      v8 = *v4;
      v4 -= 2;
      if ( (unsigned int)(v8 + ((v8 - 2) << 8) - 56321) <= 0x3FF
        && (unsigned int)(*v4 + ((*v4 - 2) << 8) - 55297) <= 0x3FF )
      {
        v4 -= 2;
      }
    }
    while ( v3 < 0 );
  }
  else
  {
    v5 = la - 1;
    if ( la - 1 > 0 )
    {
      v6 = super[2] + *((unsigned int *)super + 12);
      do
      {
        if ( (unsigned __int64)v4 >= v6 )
          break;
        v7 = *v4;
        v4 += 2;
        if ( (unsigned int)(*(v4 - 1) + (v7 << 8) - 55296) <= 0x3FF
          && (unsigned __int64)v4 < v6
          && (unsigned int)(v4[1] + (*v4 << 8) - 56320) <= 0x3FF )
        {
          v4 += 2;
        }
        --v5;
      }
      while ( v5 > 0 );
    }
  }
  v9 = super[2] + *((unsigned int *)super + 12);
  if ( (unsigned __int64)v4 >= v9 )
    return 0xFFFFFFFFi64;
  v11 = *v4;
  v12 = v4 + 2;
  v13 = *(v12 - 1) + (v11 << 8);
  if ( v13 - 55296 <= 0x3FF && (unsigned __int64)v12 < v9 )
  {
    v14 = v12[1] + (*v12 << 8);
    if ( (unsigned int)(v14 - 56320) <= 0x3FF )
      return v14 + ((v13 - 55287) << 10);
  }
  return v13;
}

// File Line: 1504
// RVA: 0x25DEB0
void __fastcall antlr3UTF32SetupStream(
        ANTLR3_INPUT_STREAM_struct *input,
        unsigned __int8 machineBigEndian,
        char inputBigEndian)
{
  int v5; // ebx
  ANTLR3_INT_STREAM_struct *istream; // rax
  __int64 (__fastcall *v7)(ANTLR3_INT_STREAM_struct *, int); // rcx

  v5 = machineBigEndian;
  input->strFactory = antlr3StringFactoryNew(input->encoding);
  input->istream->index = antlr3UTF32Index;
  input->substr = (ANTLR3_STRING_struct *(__fastcall *)(ANTLR3_INPUT_STREAM_struct *, __int64, __int64))antlr3UTF32Substr;
  input->istream->seek = antlr3UTF32Seek;
  input->istream->consume = antlr3UTF32Consume;
  if ( !(_BYTE)v5 )
  {
    istream = input->istream;
    v7 = antlr3UTF32LA;
    if ( inputBigEndian )
      v7 = antlr3UTF32LALE;
    goto LABEL_8;
  }
  if ( v5 == 1 )
  {
    istream = input->istream;
    if ( inputBigEndian == 1 )
      v7 = antlr3UTF32LA;
    else
      v7 = antlr3UTF32LALE;
LABEL_8:
    istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))v7;
  }
  input->charByteSize = 4;
}

// File Line: 1574
// RVA: 0x25D8E0
void __fastcall antlr3UTF32Consume(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *super; // rdx
  _DWORD *v2; // rcx
  int v3; // eax

  super = is->super;
  v2 = (_DWORD *)super[5];
  if ( (unsigned __int64)v2 < super[2] + (unsigned __int64)*((unsigned int *)super + 12) )
  {
    v3 = *((_DWORD *)super + 52);
    ++*((_DWORD *)super + 16);
    if ( *v2 == v3 )
    {
      ++*((_DWORD *)super + 13);
      *((_DWORD *)super + 16) = 0;
      super[7] = v2 + 1;
    }
    super[5] = v2 + 1;
  }
}

// File Line: 1624
// RVA: 0x25D9A0
ANTLR3_STRING_struct *__fastcall antlr3UTF32Substr(ANTLR3_INPUT_STREAM_struct *input, char *start, __int64 stop)
{
  return input->strFactory->newPtr(input->strFactory, start, ((unsigned int)(stop - (_DWORD)start) >> 2) + 1);
}

// File Line: 1671
// RVA: 0x25D920
__int64 __fastcall antlr3UTF32LA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // rax
  __int64 v3; // r8
  __int64 v4; // rdx

  super = is->super;
  v3 = la;
  v4 = super[5];
  if ( v4 + v3 - 1 < super[2] + (unsigned __int64)*((unsigned int *)super + 12) )
    return *(unsigned int *)(v4 + 4 * v3 - 4);
  else
    return 0xFFFFFFFFi64;
}

// File Line: 1726
// RVA: 0x25D950
__int64 __fastcall antlr3UTF32LALE(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // rax
  __int64 v3; // r8
  __int64 v4; // rdx

  super = is->super;
  v3 = la;
  v4 = super[5];
  if ( v4 + v3 - 1 < super[2] + (unsigned __int64)*((unsigned int *)super + 12) )
    return (((*(_DWORD *)(v4 + 4 * v3 - 4) << 16) | *(_DWORD *)(v4 + 4 * v3 - 4) & 0xFF00) << 8) | ((HIWORD(*(_DWORD *)(v4 + 4 * v3 - 4)) | *(_DWORD *)(v4 + 4 * v3 - 4) & 0xFF0000u) >> 8);
  else
    return 0xFFFFFFFFi64;
}

// File Line: 1754
// RVA: 0x25DF70
void __fastcall antlr3UTF8SetupStream(ANTLR3_INPUT_STREAM_struct *input)
{
  input->strFactory = antlr3StringFactoryNew(input->encoding);
  input->istream->consume = antlr3UTF8Consume;
  input->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr3UTF8LA;
  input->charByteSize = 0;
}

// File Line: 1808
// RVA: 0x25D9C0
void __fastcall antlr3UTF8Consume(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *super; // r9
  unsigned __int8 *v2; // r8
  unsigned __int64 v3; // rdx
  __int64 v4; // r10
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  super = is->super;
  v2 = (unsigned __int8 *)super[5];
  v3 = super[2] + *((unsigned int *)super + 12);
  if ( (unsigned __int64)v2 < v3 )
  {
    ++*((_DWORD *)super + 16);
    v4 = *v2;
    if ( (unsigned __int64)&v2[trailingBytesForUTF8_0[v4]] < v3 )
    {
      v5 = 0;
      switch ( v4 )
      {
        case 0i64:
        case 1i64:
        case 2i64:
        case 3i64:
        case 4i64:
        case 5i64:
        case 6i64:
        case 7i64:
        case 8i64:
        case 9i64:
        case 10i64:
        case 11i64:
        case 12i64:
        case 13i64:
        case 14i64:
        case 15i64:
        case 16i64:
        case 17i64:
        case 18i64:
        case 19i64:
        case 20i64:
        case 21i64:
        case 22i64:
        case 23i64:
        case 24i64:
        case 25i64:
        case 26i64:
        case 27i64:
        case 28i64:
        case 29i64:
        case 30i64:
        case 31i64:
        case 32i64:
        case 33i64:
        case 34i64:
        case 35i64:
        case 36i64:
        case 37i64:
        case 38i64:
        case 39i64:
        case 40i64:
        case 41i64:
        case 42i64:
        case 43i64:
        case 44i64:
        case 45i64:
        case 46i64:
        case 47i64:
        case 48i64:
        case 49i64:
        case 50i64:
        case 51i64:
        case 52i64:
        case 53i64:
        case 54i64:
        case 55i64:
        case 56i64:
        case 57i64:
        case 58i64:
        case 59i64:
        case 60i64:
        case 61i64:
        case 62i64:
        case 63i64:
        case 64i64:
        case 65i64:
        case 66i64:
        case 67i64:
        case 68i64:
        case 69i64:
        case 70i64:
        case 71i64:
        case 72i64:
        case 73i64:
        case 74i64:
        case 75i64:
        case 76i64:
        case 77i64:
        case 78i64:
        case 79i64:
        case 80i64:
        case 81i64:
        case 82i64:
        case 83i64:
        case 84i64:
        case 85i64:
        case 86i64:
        case 87i64:
        case 88i64:
        case 89i64:
        case 90i64:
        case 91i64:
        case 92i64:
        case 93i64:
        case 94i64:
        case 95i64:
        case 96i64:
        case 97i64:
        case 98i64:
        case 99i64:
        case 100i64:
        case 101i64:
        case 102i64:
        case 103i64:
        case 104i64:
        case 105i64:
        case 106i64:
        case 107i64:
        case 108i64:
        case 109i64:
        case 110i64:
        case 111i64:
        case 112i64:
        case 113i64:
        case 114i64:
        case 115i64:
        case 116i64:
        case 117i64:
        case 118i64:
        case 119i64:
        case 120i64:
        case 121i64:
        case 122i64:
        case 123i64:
        case 124i64:
        case 125i64:
        case 126i64:
        case 127i64:
        case 128i64:
        case 129i64:
        case 130i64:
        case 131i64:
        case 132i64:
        case 133i64:
        case 134i64:
        case 135i64:
        case 136i64:
        case 137i64:
        case 138i64:
        case 139i64:
        case 140i64:
        case 141i64:
        case 142i64:
        case 143i64:
        case 144i64:
        case 145i64:
        case 146i64:
        case 147i64:
        case 148i64:
        case 149i64:
        case 150i64:
        case 151i64:
        case 152i64:
        case 153i64:
        case 154i64:
        case 155i64:
        case 156i64:
        case 157i64:
        case 158i64:
        case 159i64:
        case 160i64:
        case 161i64:
        case 162i64:
        case 163i64:
        case 164i64:
        case 165i64:
        case 166i64:
        case 167i64:
        case 168i64:
        case 169i64:
        case 170i64:
        case 171i64:
        case 172i64:
        case 173i64:
        case 174i64:
        case 175i64:
        case 176i64:
        case 177i64:
        case 178i64:
        case 179i64:
        case 180i64:
        case 181i64:
        case 182i64:
        case 183i64:
        case 184i64:
        case 185i64:
        case 186i64:
        case 187i64:
        case 188i64:
        case 189i64:
        case 190i64:
        case 191i64:
        case 256i64:
          goto $LN2_21;
        case 192i64:
        case 193i64:
        case 194i64:
        case 195i64:
        case 196i64:
        case 197i64:
        case 198i64:
        case 199i64:
        case 200i64:
        case 201i64:
        case 202i64:
        case 203i64:
        case 204i64:
        case 205i64:
        case 206i64:
        case 207i64:
        case 208i64:
        case 209i64:
        case 210i64:
        case 211i64:
        case 212i64:
        case 213i64:
        case 214i64:
        case 215i64:
        case 216i64:
        case 217i64:
        case 218i64:
        case 219i64:
        case 220i64:
        case 221i64:
        case 222i64:
        case 223i64:
          goto $LN3_17;
        case 224i64:
        case 225i64:
        case 226i64:
        case 227i64:
        case 228i64:
        case 229i64:
        case 230i64:
        case 231i64:
        case 232i64:
        case 233i64:
        case 234i64:
        case 235i64:
        case 236i64:
        case 237i64:
        case 238i64:
        case 239i64:
          goto $LN4_23;
        case 240i64:
        case 241i64:
        case 242i64:
        case 243i64:
        case 244i64:
        case 245i64:
        case 246i64:
        case 247i64:
          goto $LN5_16;
        case 248i64:
        case 249i64:
        case 250i64:
        case 251i64:
          goto $LN6_23;
        case 252i64:
        case 253i64:
        case 254i64:
        case 255i64:
          ++v2;
          v5 = (_DWORD)v4 << 6;
$LN6_23:
          v6 = *v2++;
          v5 = (v6 + v5) << 6;
$LN5_16:
          v7 = *v2++;
          v5 = (v7 + v5) << 6;
$LN4_23:
          v8 = *v2++;
          v5 = (v8 + v5) << 6;
$LN3_17:
          v9 = *v2++;
          v5 = (v9 + v5) << 6;
$LN2_21:
          v5 += *v2++;
          break;
        default:
          break;
      }
      if ( v5 - offsetsFromUTF8_0[trailingBytesForUTF8_0[v4]] == *((_DWORD *)super + 52) )
      {
        ++*((_DWORD *)super + 13);
        *((_DWORD *)super + 16) = 0;
        super[7] = v2;
      }
      super[5] = v2;
    }
    else
    {
      super[5] = v3;
    }
  }
}

// File Line: 1874
// RVA: 0x25DAB0
__int64 __fastcall antlr3UTF8LA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // rbx
  unsigned __int8 *v3; // rax
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // r9
  int v6; // edx
  int v8; // ecx
  char v9; // cl
  char v10; // cl
  __int64 v11; // r10
  __int64 v12; // r9
  int v13; // r8d
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx

  super = is->super;
  v3 = (unsigned __int8 *)super[5];
  v4 = super[2];
  if ( la <= 1 )
  {
    while ( (unsigned __int64)v3 > v4 )
    {
      v8 = la++;
      if ( v8 >= 0 )
        break;
      v9 = *--v3;
      if ( (v9 & 0xC0) == 0x80 )
      {
        do
          v10 = *--v3;
        while ( (v10 & 0xC0) == 0x80 );
      }
    }
  }
  else
  {
    v5 = v4 + *((unsigned int *)super + 12);
    if ( (unsigned __int64)v3 >= v5 )
      return 0xFFFFFFFFi64;
    v6 = la - 1;
    if ( v6 > 0 )
    {
      do
      {
        v3 += trailingBytesForUTF8_0[*v3] + 1;
        if ( (unsigned __int64)v3 >= v5 )
          return 0xFFFFFFFFi64;
      }
      while ( --v6 > 0 );
    }
  }
  v11 = *v3;
  v12 = trailingBytesForUTF8_0[v11];
  if ( (unsigned __int64)&v3[v12] >= v4 + *((unsigned int *)super + 12) )
    return 0xFFFFFFFFi64;
  v13 = 0;
  switch ( v11 )
  {
    case 0i64:
    case 1i64:
    case 2i64:
    case 3i64:
    case 4i64:
    case 5i64:
    case 6i64:
    case 7i64:
    case 8i64:
    case 9i64:
    case 10i64:
    case 11i64:
    case 12i64:
    case 13i64:
    case 14i64:
    case 15i64:
    case 16i64:
    case 17i64:
    case 18i64:
    case 19i64:
    case 20i64:
    case 21i64:
    case 22i64:
    case 23i64:
    case 24i64:
    case 25i64:
    case 26i64:
    case 27i64:
    case 28i64:
    case 29i64:
    case 30i64:
    case 31i64:
    case 32i64:
    case 33i64:
    case 34i64:
    case 35i64:
    case 36i64:
    case 37i64:
    case 38i64:
    case 39i64:
    case 40i64:
    case 41i64:
    case 42i64:
    case 43i64:
    case 44i64:
    case 45i64:
    case 46i64:
    case 47i64:
    case 48i64:
    case 49i64:
    case 50i64:
    case 51i64:
    case 52i64:
    case 53i64:
    case 54i64:
    case 55i64:
    case 56i64:
    case 57i64:
    case 58i64:
    case 59i64:
    case 60i64:
    case 61i64:
    case 62i64:
    case 63i64:
    case 64i64:
    case 65i64:
    case 66i64:
    case 67i64:
    case 68i64:
    case 69i64:
    case 70i64:
    case 71i64:
    case 72i64:
    case 73i64:
    case 74i64:
    case 75i64:
    case 76i64:
    case 77i64:
    case 78i64:
    case 79i64:
    case 80i64:
    case 81i64:
    case 82i64:
    case 83i64:
    case 84i64:
    case 85i64:
    case 86i64:
    case 87i64:
    case 88i64:
    case 89i64:
    case 90i64:
    case 91i64:
    case 92i64:
    case 93i64:
    case 94i64:
    case 95i64:
    case 96i64:
    case 97i64:
    case 98i64:
    case 99i64:
    case 100i64:
    case 101i64:
    case 102i64:
    case 103i64:
    case 104i64:
    case 105i64:
    case 106i64:
    case 107i64:
    case 108i64:
    case 109i64:
    case 110i64:
    case 111i64:
    case 112i64:
    case 113i64:
    case 114i64:
    case 115i64:
    case 116i64:
    case 117i64:
    case 118i64:
    case 119i64:
    case 120i64:
    case 121i64:
    case 122i64:
    case 123i64:
    case 124i64:
    case 125i64:
    case 126i64:
    case 127i64:
    case 128i64:
    case 129i64:
    case 130i64:
    case 131i64:
    case 132i64:
    case 133i64:
    case 134i64:
    case 135i64:
    case 136i64:
    case 137i64:
    case 138i64:
    case 139i64:
    case 140i64:
    case 141i64:
    case 142i64:
    case 143i64:
    case 144i64:
    case 145i64:
    case 146i64:
    case 147i64:
    case 148i64:
    case 149i64:
    case 150i64:
    case 151i64:
    case 152i64:
    case 153i64:
    case 154i64:
    case 155i64:
    case 156i64:
    case 157i64:
    case 158i64:
    case 159i64:
    case 160i64:
    case 161i64:
    case 162i64:
    case 163i64:
    case 164i64:
    case 165i64:
    case 166i64:
    case 167i64:
    case 168i64:
    case 169i64:
    case 170i64:
    case 171i64:
    case 172i64:
    case 173i64:
    case 174i64:
    case 175i64:
    case 176i64:
    case 177i64:
    case 178i64:
    case 179i64:
    case 180i64:
    case 181i64:
    case 182i64:
    case 183i64:
    case 184i64:
    case 185i64:
    case 186i64:
    case 187i64:
    case 188i64:
    case 189i64:
    case 190i64:
    case 191i64:
    case 256i64:
      goto $LN1_11;
    case 192i64:
    case 193i64:
    case 194i64:
    case 195i64:
    case 196i64:
    case 197i64:
    case 198i64:
    case 199i64:
    case 200i64:
    case 201i64:
    case 202i64:
    case 203i64:
    case 204i64:
    case 205i64:
    case 206i64:
    case 207i64:
    case 208i64:
    case 209i64:
    case 210i64:
    case 211i64:
    case 212i64:
    case 213i64:
    case 214i64:
    case 215i64:
    case 216i64:
    case 217i64:
    case 218i64:
    case 219i64:
    case 220i64:
    case 221i64:
    case 222i64:
    case 223i64:
      goto $LN2_22;
    case 224i64:
    case 225i64:
    case 226i64:
    case 227i64:
    case 228i64:
    case 229i64:
    case 230i64:
    case 231i64:
    case 232i64:
    case 233i64:
    case 234i64:
    case 235i64:
    case 236i64:
    case 237i64:
    case 238i64:
    case 239i64:
      goto $LN3_18;
    case 240i64:
    case 241i64:
    case 242i64:
    case 243i64:
    case 244i64:
    case 245i64:
    case 246i64:
    case 247i64:
      goto $LN4_24;
    case 248i64:
    case 249i64:
    case 250i64:
    case 251i64:
      goto $LN5_17;
    case 252i64:
    case 253i64:
    case 254i64:
    case 255i64:
      ++v3;
      v13 = (_DWORD)v11 << 6;
$LN5_17:
      v14 = *v3++;
      v13 = (v14 + v13) << 6;
$LN4_24:
      v15 = *v3++;
      v13 = (v15 + v13) << 6;
$LN3_18:
      v16 = *v3++;
      v13 = (v16 + v13) << 6;
$LN2_22:
      v17 = *v3++;
      v13 = (v17 + v13) << 6;
$LN1_11:
      v13 += *v3;
      break;
    default:
      return v13 - offsetsFromUTF8_0[v12];
  }
  return v13 - offsetsFromUTF8_0[v12];
}

// File Line: 2017
// RVA: 0x25DC20
void __fastcall antlr3EBCDICSetupStream(ANTLR3_INPUT_STREAM_struct *input)
{
  input->strFactory = antlr3StringFactoryNew(input->encoding);
  input->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr3EBCDICLA;
  input->charByteSize = 1;
}

// File Line: 2038
// RVA: 0x25D280
__int64 __fastcall antlr3EBCDICLA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *super; // r8
  unsigned __int8 *v3; // rdx

  super = is->super;
  v3 = (unsigned __int8 *)(super[5] + la - 1i64);
  if ( (unsigned __int64)v3 < super[2] + (unsigned __int64)*((unsigned int *)super + 12) )
    return e2a[*v3];
  else
    return 0xFFFFFFFFi64;
}

