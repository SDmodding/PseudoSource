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
  ANTLR3_INPUT_STREAM_struct *v1; // rbx
  ANTLR3_INT_STREAM_struct *v2; // rax

  v1 = input;
  v2 = antlr3IntStreamNew();
  v1->istream = v2;
  v2->type = 1;
  v1->istream->super = v1;
  v1->istream->consume = antlr38BitConsume;
  v1->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr38BitLA;
  v1->istream->index = antlr3UTF32Index;
  v1->istream->mark = antlr38BitMark;
  v1->istream->rewind = antlr38BitRewind;
  v1->istream->rewindLast = antlr38BitRewindLast;
  v1->istream->seek = antlr38BitSeek;
  v1->istream->release = antlr38BitRelease;
  v1->istream->getSourceName = (ANTLR3_STRING_struct *(__fastcall *)(ANTLR3_INT_STREAM_struct *))Scaleform::GFx::Stream::GetLog;
  v1->close = antlr3InputClose;
  v1->free = antlr3InputClose;
  v1->reset = antlr3InputReset;
  v1->charByteSize = 1;
  v1->reuse = antlr38BitReuse;
  v1->markers = 0i64;
  v1->_LT = (void *(__fastcall *)(ANTLR3_INPUT_STREAM_struct *, int))antlr38BitLT;
  v1->size = (unsigned int (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))hkaSparseLSQMatrix<float>::Height;
  v1->substr = antlr38BitSubstr;
  v1->getLine = (unsigned int (__fastcall *)(ANTLR3_INPUT_STREAM_struct *))Scaleform::Render::MemoryBufferImage::GetUse;
  v1->getLineBuf = (void *(__fastcall *)(ANTLR3_INPUT_STREAM_struct *))hkDataArrayNative::getType;
  v1->getCharPositionInLine = UFG::UIGfxMemoryFile::GetLength;
  v1->setLine = antlr38BitSetLine;
  v1->setCharPositionInLine = PoseNode::SetPlayPriority;
  v1->SetNewLineChar = UFG::UIScreenTextureManager::SetGameState;
  v1->setUcaseLA = antlr38BitSetUcaseLA;
  antlr3InputReset(v1);
  v1->SetNewLineChar(v1, 10u);
}

// File Line: 207
// RVA: 0x25D2B0
void __fastcall antlr3InputClose(ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_VECTOR_struct *v1; // rax
  ANTLR3_INPUT_STREAM_struct *v2; // rbx
  ANTLR3_STRING_FACTORY_struct *v3; // rax
  void *v4; // rcx

  v1 = input->markers;
  v2 = input;
  if ( v1 )
  {
    v1->free(input->markers);
    v2->markers = 0i64;
  }
  v3 = v2->strFactory;
  if ( v3 )
    v3->close(v2->strFactory);
  if ( v2->isAllocated )
  {
    v4 = v2->data;
    if ( v4 )
    {
      antlrFree(v4);
      v2->data = 0i64;
    }
  }
  v2->istream->free(v2->istream);
  antlrFree(v2);
}

// File Line: 243
// RVA: 0x25D240
void __fastcall antlr38BitSetUcaseLA(ANTLR3_INPUT_STREAM_struct *input, char flag)
{
  ANTLR3_INT_STREAM_struct *v2; // rax
  unsigned int (__fastcall *v3)(ANTLR3_INT_STREAM_struct *, int); // rcx

  v2 = input->istream;
  v3 = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr38BitLA_ucase;
  if ( !flag )
    v3 = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr38BitLA;
  v2->_LA = v3;
}

// File Line: 265
// RVA: 0x25D320
void __fastcall antlr3InputReset(ANTLR3_INPUT_STREAM_struct *input)
{
  void *v1; // rax
  ANTLR3_VECTOR_struct *v2; // rax

  v1 = input->data;
  input->line = 1;
  input->nextChar = v1;
  input->currentLine = v1;
  v2 = input->markers;
  input->charPositionInLine = -1;
  input->markDepth = 0;
  if ( v2 )
    v2->clear(v2);
  else
    input->markers = (ANTLR3_VECTOR_struct *)antlr3VectorNew(0);
}

// File Line: 292
// RVA: 0x25D090
void __fastcall antlr38BitReuse(ANTLR3_INPUT_STREAM_struct *input, char *inString, unsigned int size, char *name)
{
  ANTLR3_INT_STREAM_struct *v4; // rax
  ANTLR3_STRING_struct *v5; // r8
  ANTLR3_INPUT_STREAM_struct *v6; // rbx

  v4 = input->istream;
  input->isAllocated = 0;
  input->data = inString;
  input->sizeBuf = size;
  v5 = v4->streamName;
  v6 = input;
  if ( v5 )
  {
    if ( !name )
      name = "-memory-";
    v5->set(v4->streamName, name);
    v6->reset(v6);
  }
  else
  {
    if ( !name )
      name = "-memory-";
    input->istream->streamName = input->strFactory->newStr(input->strFactory, name);
    v6->fileName = v6->istream->streamName;
    v6->reset(v6);
  }
}

// File Line: 319
// RVA: 0x25CF20
void __fastcall antlr38BitConsume(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *v1; // rdx
  unsigned __int8 *v2; // rcx

  v1 = is->super;
  v2 = (unsigned __int8 *)v1[5];
  if ( (unsigned __int64)v2 < v1[2] + (unsigned __int64)*((unsigned int *)v1 + 12) )
  {
    ++*((_DWORD *)v1 + 16);
    if ( *v2 == *((_DWORD *)v1 + 52) )
    {
      ++*((_DWORD *)v1 + 13);
      *((_DWORD *)v1 + 16) = 0;
      v1[7] = v2 + 1;
    }
    v1[5] = v2 + 1;
  }
}

// File Line: 354
// RVA: 0x25CF70
signed __int64 __fastcall antlr38BitLA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // r8
  unsigned __int8 *v3; // rdx
  signed __int64 result; // rax

  v2 = is->super;
  v3 = (unsigned __int8 *)(v2[5] + la - 1i64);
  if ( (unsigned __int64)v3 < v2[2] + (unsigned __int64)*((unsigned int *)v2 + 12) )
    result = *v3;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 381
// RVA: 0x25CFA0
int __fastcall antlr38BitLA_ucase(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // r8
  unsigned __int8 *v3; // rdx
  int result; // eax

  v2 = is->super;
  v3 = (unsigned __int8 *)(v2[5] + la - 1i64);
  if ( (unsigned __int64)v3 < v2[2] + (unsigned __int64)*((unsigned int *)v2 + 12) )
    result = toupper_0(*v3);
  else
    result = -1;
  return result;
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
  char *v1; // rbx
  ANTLR3_INT_STREAM_struct *v2; // rsi
  __int64 v3; // rax
  unsigned int v4; // edx
  UFG::allocator::free_link *v5; // rdi

  v1 = (char *)is->super;
  v2 = is;
  ++*((_DWORD *)v1 + 17);
  v3 = *((_QWORD *)v1 + 9);
  v4 = *((_DWORD *)v1 + 17);
  if ( v4 <= *(_DWORD *)(v3 + 8) )
  {
    v5 = (UFG::allocator::free_link *)(*(__int64 (__fastcall **)(_QWORD, _QWORD))(v3 + 296))(
                                        *((_QWORD *)v1 + 9),
                                        v4 - 1);
  }
  else
  {
    v5 = antlrMalloc(0x20ui64);
    (*(void (__fastcall **)(_QWORD, UFG::allocator::free_link *, void (__fastcall *)(void *)))(*((_QWORD *)v1 + 9)
                                                                                             + 328i64))(
      *((_QWORD *)v1 + 9),
      v5,
      antlrFree);
  }
  LODWORD(v5[3].mNext) = *((_DWORD *)v1 + 16);
  v5[2].mNext = *(UFG::allocator::free_link **)(v1 + 56);
  LODWORD(v5[1].mNext) = *((_DWORD *)v1 + 13);
  v5->mNext = *(UFG::allocator::free_link **)(v1 + 40);
  v2->lastMarker = *((unsigned int *)v1 + 17);
  return *((unsigned int *)v1 + 17);
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
  _QWORD *v2; // rsi
  ANTLR3_INT_STREAM_struct *v3; // rdi
  int v4; // ebx
  _QWORD *v5; // rax
  _QWORD *v6; // r14
  __int64 v7; // rbx
  _QWORD *v8; // rax
  __int64 v9; // rcx
  int i; // ebx

  v2 = is->super;
  v3 = is;
  v4 = mark;
  (*(void (__fastcall **)(_QWORD))(*v2 + 88i64))(*v2);
  v5 = (_QWORD *)(*(__int64 (__fastcall **)(_QWORD, _QWORD))(v2[9] + 296i64))(v2[9], (unsigned int)(v4 - 1));
  v6 = v5;
  v7 = *v5;
  v8 = v3->super;
  v9 = v8[5];
  if ( v7 > v9 )
  {
    for ( i = v7 - v9; i; --i )
      v3->consume(v3);
  }
  else
  {
    v8[5] = v7;
  }
  *((_DWORD *)v2 + 16) = *((_DWORD *)v6 + 6);
  v2[7] = v6[2];
  *((_DWORD *)v2 + 13) = *((_DWORD *)v6 + 2);
  v2[5] = *v6;
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
  _QWORD *v2; // rax
  ANTLR3_INT_STREAM_struct *v3; // rdi
  __int64 v4; // rcx
  int v5; // ebx

  v2 = is->super;
  v3 = is;
  v4 = v2[5];
  if ( seekPoint > v4 )
  {
    v5 = seekPoint - v4;
    if ( (_DWORD)seekPoint != (_DWORD)v4 )
    {
      do
      {
        v3->consume(v3);
        --v5;
      }
      while ( v5 );
    }
  }
  else
  {
    v2[5] = seekPoint;
  }
}

// File Line: 607
// RVA: 0x25D260
ANTLR3_STRING_struct *__fastcall antlr38BitSubstr(ANTLR3_INPUT_STREAM_struct *input, __int64 start, __int64 stop)
{
  return (ANTLR3_STRING_struct *)input->strFactory->newPtr(input->strFactory, (char *)start, stop - start + 1);
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
void __fastcall PoseNode::SetPlayPriority(ANTLR3_INPUT_STREAM_struct *input, unsigned int position)
{
  input->charPositionInLine = position;
}

// File Line: 706
// RVA: 0x25DDE0
void __fastcall antlr3UTF16SetupStream(ANTLR3_INPUT_STREAM_struct *input, char machineBigEndian, char inputBigEndian)
{
  ANTLR3_INPUT_STREAM_struct *v3; // rdi
  char v4; // si
  int v5; // ebx
  ANTLR3_INT_STREAM_struct *v6; // rax
  signed __int64 (__fastcall *v7)(ANTLR3_INT_STREAM_struct *, int); // rcx

  v3 = input;
  v4 = inputBigEndian;
  v5 = (unsigned __int8)machineBigEndian;
  input->strFactory = antlr3StringFactoryNew(input->encoding);
  v3->istream->index = antlr3UTF32Index;
  v3->substr = antlr3UTF16Substr;
  v3->istream->seek = antlr3UTF32Seek;
  if ( !(_BYTE)v5 )
  {
    v6 = v3->istream;
    if ( v4 )
    {
      v6->consume = antlr3UTF16ConsumeBE;
      v7 = antlr3UTF16LABE;
      goto LABEL_8;
    }
    goto LABEL_4;
  }
  if ( v5 == 1 )
  {
    v6 = v3->istream;
    if ( v4 != 1 )
    {
      v6->consume = antlr3UTF16ConsumeLE;
      v7 = antlr3UTF16LALE;
      goto LABEL_8;
    }
LABEL_4:
    v6->consume = antlr3UTF16Consume;
    v7 = antlr3UTF16LA;
LABEL_8:
    v3->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))v7;
  }
  v3->charByteSize = 2;
}

// File Line: 782
// RVA: 0x25D380
void __fastcall antlr3UTF16Consume(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *v1; // rdx
  unsigned __int16 *v2; // rcx
  unsigned __int64 v3; // r8
  int v4; // eax
  unsigned __int16 *v5; // rcx

  v1 = is->super;
  v2 = (unsigned __int16 *)v1[5];
  v3 = v1[2] + *((unsigned int *)v1 + 12);
  if ( (unsigned __int64)v2 < v3 )
  {
    ++*((_DWORD *)v1 + 16);
    if ( *v2 == *((_DWORD *)v1 + 52) )
    {
      ++*((_DWORD *)v1 + 13);
      *((_DWORD *)v1 + 16) = 0;
      v1[7] = v2 + 1;
    }
    v4 = *v2;
    v5 = v2 + 1;
    v1[5] = v5;
    if ( (unsigned int)(v4 - 55296) <= 0x3FF && (unsigned __int64)v5 < v3 && (unsigned int)*v5 - 56320 <= 0x3FF )
      v1[5] = v5 + 1;
  }
}

// File Line: 861
// RVA: 0x25D520
signed __int64 __fastcall antlr3UTF16LA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // r10
  int v3; // er9
  unsigned __int16 *v4; // rax
  int v5; // er9
  unsigned __int64 v6; // rdx
  int v7; // ecx
  int v8; // ecx
  unsigned __int64 v9; // r8
  unsigned int v11; // edx
  unsigned __int16 *v12; // rax
  int v13; // er8

  v2 = is->super;
  v3 = la;
  v4 = (unsigned __int16 *)v2[5];
  if ( la < 0 )
  {
    do
    {
      ++v3;
      if ( (unsigned __int64)v4 <= v2[2] )
        break;
      v8 = *(v4 - 1);
      --v4;
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
      v6 = v2[2] + *((unsigned int *)v2 + 12);
      do
      {
        if ( (unsigned __int64)v4 >= v6 )
          break;
        v7 = *v4;
        ++v4;
        if ( (unsigned int)(v7 - 55296) <= 0x3FF && (unsigned __int64)v4 < v6 && (unsigned int)*v4 - 56320 <= 0x3FF )
          ++v4;
        --v5;
      }
      while ( v5 > 0 );
    }
  }
  v9 = v2[2] + *((unsigned int *)v2 + 12);
  if ( (unsigned __int64)v4 >= v9 )
    return 0xFFFFFFFFi64;
  v11 = *v4;
  v12 = v4 + 1;
  if ( v11 - 55296 <= 0x3FF && (unsigned __int64)v12 < v9 )
  {
    v13 = *v12;
    if ( (unsigned int)(v13 - 56320) <= 0x3FF )
      v11 = v13 + ((v11 - 55287) << 10);
  }
  return v11;
}

// File Line: 1017
// RVA: 0x25D850
void __fastcall antlr3UTF32Seek(ANTLR3_INT_STREAM_struct *is, __int64 seekPoint)
{
  _QWORD *v2; // rsi
  __int64 v3; // rdi
  ANTLR3_INT_STREAM_struct *v4; // rbx

  v2 = is->super;
  v3 = seekPoint;
  v4 = is;
  if ( seekPoint > v2[5] )
  {
    if ( is->_LA(is, 1) != -1 )
    {
      do
      {
        if ( v3 >= v2[5] )
          break;
        v4->consume(v4);
      }
      while ( v4->_LA(v4, 1) != -1 );
    }
  }
  else
  {
    v2[5] = seekPoint;
  }
}

// File Line: 1050
// RVA: 0x25D8C0
ANTLR3_STRING_struct *__fastcall antlr3UTF16Substr(ANTLR3_INPUT_STREAM_struct *input, __int64 start, __int64 stop)
{
  return (ANTLR3_STRING_struct *)input->strFactory->newPtr(
                                   input->strFactory,
                                   (char *)start,
                                   ((unsigned int)(stop - start) >> 1) + 1);
}

// File Line: 1064
// RVA: 0x25D480
void __fastcall antlr3UTF16ConsumeLE(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *v1; // rdx
  unsigned __int16 *v2; // r8
  unsigned __int64 v3; // r9
  int v4; // ecx
  int v5; // eax
  unsigned __int8 *v6; // r8

  v1 = is->super;
  v2 = (unsigned __int16 *)v1[5];
  v3 = v1[2] + *((unsigned int *)v1 + 12);
  if ( (unsigned __int64)v2 < v3 )
  {
    ++*((_DWORD *)v1 + 16);
    if ( *v2 == *((_DWORD *)v1 + 52) )
    {
      ++*((_DWORD *)v1 + 13);
      *((_DWORD *)v1 + 16) = 0;
      v1[7] = v2 + 1;
    }
    v4 = *((unsigned __int8 *)v2 + 1);
    v5 = *(unsigned __int8 *)v2;
    v6 = (unsigned __int8 *)(v2 + 1);
    v1[5] = v6;
    if ( (unsigned int)((v4 << 8) + v5 - 55296) <= 0x3FF
      && (unsigned __int64)v6 < v3
      && (v6[1] << 8) + (unsigned int)*v6 - 56320 <= 0x3FF )
    {
      v1[5] = v6 + 2;
    }
  }
}

// File Line: 1141
// RVA: 0x25D730
signed __int64 __fastcall antlr3UTF16LALE(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // r10
  int v3; // er9
  int *v4; // rax
  int v5; // er9
  unsigned __int64 v6; // rdx
  int v7; // ecx
  int v8; // edx
  unsigned __int64 v9; // r8
  int v11; // edx
  _DWORD *v12; // rax
  unsigned int v13; // edx
  int v14; // er8

  v2 = is->super;
  v3 = la;
  v4 = (int *)v2[5];
  if ( la < 0 )
  {
    do
    {
      ++v3;
      if ( (unsigned __int64)v4 <= v2[2] )
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
      v6 = v2[2] + *((unsigned int *)v2 + 12);
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
  v9 = v2[2] + *((unsigned int *)v2 + 12);
  if ( (unsigned __int64)v4 >= v9 )
    return 0xFFFFFFFFi64;
  v11 = v4[1];
  v12 = v4 + 2;
  v13 = *(v12 - 2) + (v11 << 8);
  if ( v13 - 55296 <= 0x3FF && (unsigned __int64)v12 < v9 )
  {
    v14 = *v12 + (v12[1] << 8);
    if ( (unsigned int)(v14 - 56320) <= 0x3FF )
      v13 = v14 + ((v13 - 55287) << 10);
  }
  return v13;
}

// File Line: 1283
// RVA: 0x25D3F0
void __fastcall antlr3UTF16ConsumeBE(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *v1; // rdx
  unsigned __int16 *v2; // r8
  unsigned __int64 v3; // r9
  int v4; // ecx
  int v5; // eax
  unsigned __int8 *v6; // r8

  v1 = is->super;
  v2 = (unsigned __int16 *)v1[5];
  v3 = v1[2] + *((unsigned int *)v1 + 12);
  if ( (unsigned __int64)v2 < v3 )
  {
    ++*((_DWORD *)v1 + 16);
    if ( *v2 == *((_DWORD *)v1 + 52) )
    {
      ++*((_DWORD *)v1 + 13);
      *((_DWORD *)v1 + 16) = 0;
      v1[7] = v2 + 1;
    }
    v4 = *(unsigned __int8 *)v2;
    v5 = *((unsigned __int8 *)v2 + 1);
    v6 = (unsigned __int8 *)(v2 + 1);
    v1[5] = v6;
    if ( (unsigned int)((v4 << 8) + v5 - 55296) <= 0x3FF
      && (unsigned __int64)v6 < v3
      && (*v6 << 8) + (unsigned int)v6[1] - 56320 <= 0x3FF )
    {
      v1[5] = v6 + 2;
    }
  }
}

// File Line: 1362
// RVA: 0x25D610
signed __int64 __fastcall antlr3UTF16LABE(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // r10
  int v3; // er9
  int *v4; // rax
  int v5; // er9
  unsigned __int64 v6; // rdx
  int v7; // ecx
  int v8; // edx
  unsigned __int64 v9; // r8
  int v11; // edx
  _DWORD *v12; // rax
  unsigned int v13; // edx
  int v14; // er8

  v2 = is->super;
  v3 = la;
  v4 = (int *)v2[5];
  if ( la < 0 )
  {
    do
    {
      ++v3;
      if ( (unsigned __int64)v4 <= v2[2] )
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
      v6 = v2[2] + *((unsigned int *)v2 + 12);
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
  v9 = v2[2] + *((unsigned int *)v2 + 12);
  if ( (unsigned __int64)v4 >= v9 )
    return 0xFFFFFFFFi64;
  v11 = *v4;
  v12 = v4 + 2;
  v13 = *(v12 - 1) + (v11 << 8);
  if ( v13 - 55296 <= 0x3FF && (unsigned __int64)v12 < v9 )
  {
    v14 = v12[1] + (*v12 << 8);
    if ( (unsigned int)(v14 - 56320) <= 0x3FF )
      v13 = v14 + ((v13 - 55287) << 10);
  }
  return v13;
}

// File Line: 1504
// RVA: 0x25DEB0
void __fastcall antlr3UTF32SetupStream(ANTLR3_INPUT_STREAM_struct *input, char machineBigEndian, char inputBigEndian)
{
  ANTLR3_INPUT_STREAM_struct *v3; // rdi
  char v4; // si
  int v5; // ebx
  ANTLR3_INT_STREAM_struct *v6; // rax
  signed __int64 (__fastcall *v7)(ANTLR3_INT_STREAM_struct *, int); // rcx

  v3 = input;
  v4 = inputBigEndian;
  v5 = (unsigned __int8)machineBigEndian;
  input->strFactory = antlr3StringFactoryNew(input->encoding);
  v3->istream->index = antlr3UTF32Index;
  v3->substr = antlr3UTF32Substr;
  v3->istream->seek = antlr3UTF32Seek;
  v3->istream->consume = antlr3UTF32Consume;
  if ( !(_BYTE)v5 )
  {
    v6 = v3->istream;
    v7 = antlr3UTF32LA;
    if ( v4 )
      v7 = antlr3UTF32LALE;
    goto LABEL_8;
  }
  if ( v5 == 1 )
  {
    v6 = v3->istream;
    if ( v4 == 1 )
      v7 = antlr3UTF32LA;
    else
      v7 = antlr3UTF32LALE;
LABEL_8:
    v6->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))v7;
  }
  v3->charByteSize = 4;
}

// File Line: 1574
// RVA: 0x25D8E0
void __fastcall antlr3UTF32Consume(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *v1; // rdx
  _DWORD *v2; // rcx
  int v3; // eax

  v1 = is->super;
  v2 = (_DWORD *)v1[5];
  if ( (unsigned __int64)v2 < v1[2] + (unsigned __int64)*((unsigned int *)v1 + 12) )
  {
    v3 = *((_DWORD *)v1 + 52);
    ++*((_DWORD *)v1 + 16);
    if ( *v2 == v3 )
    {
      ++*((_DWORD *)v1 + 13);
      *((_DWORD *)v1 + 16) = 0;
      v1[7] = v2 + 1;
    }
    v1[5] = v2 + 1;
  }
}

// File Line: 1624
// RVA: 0x25D9A0
ANTLR3_STRING_struct *__fastcall antlr3UTF32Substr(ANTLR3_INPUT_STREAM_struct *input, __int64 start, __int64 stop)
{
  return (ANTLR3_STRING_struct *)input->strFactory->newPtr(
                                   input->strFactory,
                                   (char *)start,
                                   ((unsigned int)(stop - start) >> 2) + 1);
}

// File Line: 1671
// RVA: 0x25D920
signed __int64 __fastcall antlr3UTF32LA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // rax
  __int64 v3; // r8
  __int64 v4; // rdx
  signed __int64 result; // rax

  v2 = is->super;
  v3 = la;
  v4 = v2[5];
  if ( v4 + v3 - 1 < v2[2] + (unsigned __int64)*((unsigned int *)v2 + 12) )
    result = *(unsigned int *)(v4 + 4 * v3 - 4);
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 1726
// RVA: 0x25D950
signed __int64 __fastcall antlr3UTF32LALE(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // rax
  __int64 v3; // r8
  __int64 v4; // rdx
  signed __int64 result; // rax

  v2 = is->super;
  v3 = la;
  v4 = v2[5];
  if ( v4 + v3 - 1 < v2[2] + (unsigned __int64)*((unsigned int *)v2 + 12) )
    result = (((*(_DWORD *)(v4 + 4 * v3 - 4) << 16) | *(_DWORD *)(v4 + 4 * v3 - 4) & 0xFF00) << 8) | (((*(_DWORD *)(v4 + 4 * v3 - 4) >> 16) | *(_DWORD *)(v4 + 4 * v3 - 4) & 0xFF0000u) >> 8);
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 1754
// RVA: 0x25DF70
void __fastcall antlr3UTF8SetupStream(ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_INPUT_STREAM_struct *v1; // rbx

  v1 = input;
  input->strFactory = antlr3StringFactoryNew(input->encoding);
  v1->istream->consume = antlr3UTF8Consume;
  v1->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr3UTF8LA;
  v1->charByteSize = 0;
}

// File Line: 1808
// RVA: 0x25D9C0
void __fastcall antlr3UTF8Consume(ANTLR3_INT_STREAM_struct *is)
{
  _QWORD *v1; // r9
  unsigned __int8 *v2; // r8
  unsigned __int64 v3; // rdx
  __int64 v4; // r10
  __int64 v5; // rcx
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  v1 = is->super;
  v2 = (unsigned __int8 *)v1[5];
  v3 = v1[2] + *((unsigned int *)v1 + 12);
  if ( (unsigned __int64)v2 < v3 )
  {
    ++*((_DWORD *)v1 + 16);
    v4 = *v2;
    v5 = trailingBytesForUTF8_0[v4];
    if ( (unsigned __int64)&v2[v5] < v3 )
    {
      v6 = 0;
      switch ( (_DWORD)v5 )
      {
        case 0:
          goto $LN2_21;
        case 1:
          goto $LN3_17;
        case 2:
          goto $LN4_23;
        case 3:
          goto $LN5_16;
        case 4:
          goto $LN6_23;
        case 5:
          ++v2;
          v6 = (_DWORD)v4 << 6;
$LN6_23:
          v7 = *v2++;
          v6 = (v7 + v6) << 6;
$LN5_16:
          v8 = *v2++;
          v6 = (v8 + v6) << 6;
$LN4_23:
          v9 = *v2++;
          v6 = (v9 + v6) << 6;
$LN3_17:
          v10 = *v2++;
          v6 = (v10 + v6) << 6;
$LN2_21:
          v6 += *v2++;
          break;
        default:
          break;
      }
      if ( v6 - offsetsFromUTF8_0[trailingBytesForUTF8_0[v4]] == *((_DWORD *)v1 + 52) )
      {
        ++*((_DWORD *)v1 + 13);
        *((_DWORD *)v1 + 16) = 0;
        v1[7] = v2;
      }
      v1[5] = v2;
    }
    else
    {
      v1[5] = v3;
    }
  }
}

// File Line: 1874
// RVA: 0x25DAB0
signed __int64 __fastcall antlr3UTF8LA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // rbx
  unsigned __int8 *v3; // rax
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // r9
  int v6; // edx
  int v8; // ecx
  char v9; // cl
  char v10; // cl
  __int64 v11; // r10
  __int64 v12; // r9
  int v13; // er8
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx

  v2 = is->super;
  v3 = (unsigned __int8 *)v2[5];
  v4 = v2[2];
  if ( la <= 1 )
  {
    while ( (unsigned __int64)v3 > v4 )
    {
      v8 = la++;
      if ( v8 >= 0 )
        break;
      v9 = *(v3-- - 1);
      if ( (v9 & 0xC0) == -128 )
      {
        do
          v10 = *(v3-- - 1);
        while ( (v10 & 0xC0) == -128 );
      }
    }
  }
  else
  {
    v5 = v4 + *((unsigned int *)v2 + 12);
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
  if ( (unsigned __int64)&v3[v12] >= v4 + *((unsigned int *)v2 + 12) )
    return 0xFFFFFFFFi64;
  v13 = 0;
  switch ( (_DWORD)v12 )
  {
    case 0:
      goto $LN1_11;
    case 1:
      goto $LN2_22;
    case 2:
      goto $LN3_18;
    case 3:
      goto $LN4_24;
    case 4:
      goto $LN5_17;
    case 5:
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
  ANTLR3_INPUT_STREAM_struct *v1; // rbx

  v1 = input;
  input->strFactory = antlr3StringFactoryNew(input->encoding);
  v1->istream->_LA = (unsigned int (__fastcall *)(ANTLR3_INT_STREAM_struct *, int))antlr3EBCDICLA;
  v1->charByteSize = 1;
}

// File Line: 2038
// RVA: 0x25D280
signed __int64 __fastcall antlr3EBCDICLA(ANTLR3_INT_STREAM_struct *is, int la)
{
  _QWORD *v2; // r8
  unsigned __int8 *v3; // rdx
  signed __int64 result; // rax

  v2 = is->super;
  v3 = (unsigned __int8 *)(v2[5] + la - 1i64);
  if ( (unsigned __int64)v3 < v2[2] + (unsigned __int64)*((unsigned int *)v2 + 12) )
    result = e2a[*v3];
  else
    result = 0xFFFFFFFFi64;
  return result;
}

