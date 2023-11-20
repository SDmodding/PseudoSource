// File Line: 58
// RVA: 0x25CD00
UFG::allocator::free_link *__fastcall antlr3FileStreamNew(char *fileName, unsigned int encoding)
{
  unsigned int v2; // ebp
  char *v3; // rsi
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rdi
  unsigned int v6; // ebx
  UFG::allocator::free_link *result; // rax

  v2 = encoding;
  v3 = fileName;
  if ( !fileName )
    return 0i64;
  v4 = antlrCalloc(1u, 0xE0u);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = antlr3read8Bit((ANTLR3_INPUT_STREAM_struct *)v4, v3);
  antlr3GenericSetupStream((ANTLR3_INPUT_STREAM_struct *)v5);
  if ( v6 )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[12].mNext)(v5);
    return 0i64;
  }
  LODWORD(v5[27].mNext) = v2;
  setupInputStream((ANTLR3_INPUT_STREAM_struct *)v5);
  v5->mNext[1].mNext = (UFG::allocator::free_link *)((__int64 (__fastcall *)(UFG::allocator::free_link *, char *))v5[4].mNext[7].mNext)(
                                                      v5[4].mNext,
                                                      v3);
  result = v5;
  v5[10].mNext = v5->mNext[1].mNext;
  return result;
}

// File Line: 93
// RVA: 0x25CDE0
ANTLR3_INPUT_STREAM_struct *__fastcall antlr3StringStreamNew(char *data, unsigned int encoding, unsigned int size, char *name)
{
  char *v4; // rsi
  unsigned int v5; // ebp
  unsigned int v6; // er14
  char *v7; // rdi
  ANTLR3_INPUT_STREAM_struct *v8; // rax
  ANTLR3_INPUT_STREAM_struct *v9; // rbx
  ANTLR3_INPUT_STREAM_struct *result; // rax

  v4 = name;
  v5 = size;
  v6 = encoding;
  v7 = data;
  if ( !data )
    return 0i64;
  v8 = (ANTLR3_INPUT_STREAM_struct *)antlrCalloc(1u, 0xE0u);
  v9 = v8;
  if ( !v8 )
    return 0i64;
  v8->data = v7;
  v8->isAllocated = 0;
  antlr3GenericSetupStream(v8);
  v9->sizeBuf = v5;
  v9->encoding = v6;
  setupInputStream(v9);
  v9->istream->streamName = v9->strFactory->newStr8(v9->strFactory, v4);
  result = v9;
  v9->fileName = v9->istream->streamName;
  return result;
}

// File Line: 134
// RVA: 0x25CBB0
void __fastcall setupInputStream(ANTLR3_INPUT_STREAM_struct *input)
{
  _BYTE *v1; // rax
  _BYTE *v2; // rax
  _BYTE *v3; // rax

  switch ( input->encoding )
  {
    case 8u:
      v1 = input->nextChar;
      if ( *v1 == -17 && v1[1] == -69 && v1[2] == -65 )
        input->nextChar = v1 + 3;
      antlr3UTF8SetupStream(input);
      return;
    case 0x10u:
      v2 = input->nextChar;
      if ( *v2 == -2 && v2[1] == -1 )
      {
        input->nextChar = v2 + 2;
        goto $LN6_22;
      }
      if ( *v2 == -1 && v2[1] == -2 )
        input->nextChar = v2 + 2;
      goto $LN13_25;
    case 0x11u:
$LN6_22:
      antlr3UTF16SetupStream(input, 0, 1);
      return;
    case 0x12u:
$LN13_25:
      antlr3UTF16SetupStream(input, 0, 0);
      return;
    case 0x20u:
      v3 = input->nextChar;
      if ( *v3 || v3[1] || v3[2] != -2 || v3[3] != -1 )
        goto $LN10_23;
      input->nextChar = v3 + 4;
      goto $LN4_22;
    case 0x21u:
$LN4_22:
      antlr3UTF32SetupStream(input, 0, 1);
      break;
    case 0x22u:
$LN10_23:
      antlr3UTF32SetupStream(input, 0, 0);
      break;
    case 0x40u:
      antlr3EBCDICSetupStream(input);
      break;
    default:
      antlr38BitSetupStream(input);
      break;
  }
}

// File Line: 357
// RVA: 0x25CE90
signed __int64 __fastcall antlr3read8Bit(ANTLR3_INPUT_STREAM_struct *input, char *fileName)
{
  ANTLR3_INPUT_STREAM_struct *v2; // rbx
  _iobuf *v3; // rdi
  UFG::allocator::free_link *v5; // rax

  v2 = input;
  v3 = fopen(fileName, "rb");
  if ( !v3 )
    return 2i64;
  v5 = antlrMalloc(0i64);
  v2->sizeBuf = 0;
  v2->data = v5;
  if ( !v5 )
    return 1i64;
  v2->isAllocated = 1;
  fread(v5, 0i64, 1ui64, v3);
  fclose(v3);
  return 0i64;
}

// File Line: 408
// RVA: 0x25CDB0
_iobuf *__fastcall antlr3Fopen(char *filename, const char *mode)
{
  return fopen(filename, mode);
}

// File Line: 417
// RVA: 0x25CCF0
void __fastcall antlr3Fclose(_iobuf *fd)
{
  fclose(fd);
}

// File Line: 434
// RVA: 0x25CDC0
unsigned __int64 __fastcall antlr3Fread(_iobuf *fdsc, unsigned int count, void *data)
{
  return fread(data, count, 1ui64, fdsc);
}

