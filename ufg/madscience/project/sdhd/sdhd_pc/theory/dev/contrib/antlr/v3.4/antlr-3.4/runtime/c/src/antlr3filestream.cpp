// File Line: 58
// RVA: 0x25CD00
UFG::allocator::free_link *__fastcall antlr3FileStreamNew(char *fileName, unsigned int encoding)
{
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rdi
  unsigned int v6; // ebx
  UFG::allocator::free_link *result; // rax

  if ( !fileName )
    return 0i64;
  v4 = antlrCalloc(1u, 0xE0u);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = antlr3read8Bit((ANTLR3_INPUT_STREAM_struct *)v4, fileName);
  antlr3GenericSetupStream((ANTLR3_INPUT_STREAM_struct *)v5);
  if ( v6 )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v5[12].mNext)(v5);
    return 0i64;
  }
  LODWORD(v5[27].mNext) = encoding;
  setupInputStream((ANTLR3_INPUT_STREAM_struct *)v5);
  v5->mNext[1].mNext = (UFG::allocator::free_link *)((__int64 (__fastcall *)(UFG::allocator::free_link *, char *))v5[4].mNext[7].mNext)(
                                                      v5[4].mNext,
                                                      fileName);
  result = v5;
  v5[10].mNext = v5->mNext[1].mNext;
  return result;
}

// File Line: 93
// RVA: 0x25CDE0
ANTLR3_INPUT_STREAM_struct *__fastcall antlr3StringStreamNew(
        char *data,
        unsigned int encoding,
        unsigned int size,
        char *name)
{
  ANTLR3_INPUT_STREAM_struct *v8; // rax
  ANTLR3_INPUT_STREAM_struct *v9; // rbx
  ANTLR3_INPUT_STREAM_struct *result; // rax

  if ( !data )
    return 0i64;
  v8 = (ANTLR3_INPUT_STREAM_struct *)antlrCalloc(1u, 0xE0u);
  v9 = v8;
  if ( !v8 )
    return 0i64;
  v8->data = data;
  v8->isAllocated = 0;
  antlr3GenericSetupStream(v8);
  v9->sizeBuf = size;
  v9->encoding = encoding;
  setupInputStream(v9);
  v9->istream->streamName = v9->strFactory->newStr8(v9->strFactory, name);
  result = v9;
  v9->fileName = v9->istream->streamName;
  return result;
}

// File Line: 134
// RVA: 0x25CBB0
void __fastcall setupInputStream(ANTLR3_INPUT_STREAM_struct *input)
{
  char *nextChar; // rax
  char *v2; // rax
  char *v3; // rax

  switch ( input->encoding )
  {
    case 8u:
      nextChar = (char *)input->nextChar;
      if ( *(_WORD *)nextChar == 0xBBEF && nextChar[2] == -65 )
        input->nextChar = nextChar + 3;
      antlr3UTF8SetupStream(input);
      return;
    case 0x10u:
      v2 = (char *)input->nextChar;
      if ( *(_WORD *)v2 == 0xFFFE )
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
      v3 = (char *)input->nextChar;
      if ( *(_WORD *)v3 || v3[2] != -2 || v3[3] != -1 )
        goto $LN10_23;
      input->nextChar = v3 + 4;
$LN4_22:
      antlr3UTF32SetupStream(input, 0, 1);
      break;
    case 0x21u:
      goto $LN4_22;
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
__int64 __fastcall antlr3read8Bit(ANTLR3_INPUT_STREAM_struct *input, char *fileName)
{
  _iobuf *v3; // rdi
  UFG::allocator::free_link *v5; // rax

  v3 = fopen(fileName, "rb");
  if ( !v3 )
    return 2i64;
  v5 = antlrMalloc(0i64);
  input->sizeBuf = 0;
  input->data = v5;
  if ( !v5 )
    return 1i64;
  input->isAllocated = 1;
  fread(v5, 0i64, 1ui64, v3);
  fclose(v3);
  return 0i64;
}

// File Line: 408
// RVA: 0x25CDB0
// attributes: thunk
_iobuf *__fastcall antlr3Fopen(char *filename, const char *mode)
{
  return fopen(filename, mode);
}

// File Line: 417
// RVA: 0x25CCF0
// attributes: thunk
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

