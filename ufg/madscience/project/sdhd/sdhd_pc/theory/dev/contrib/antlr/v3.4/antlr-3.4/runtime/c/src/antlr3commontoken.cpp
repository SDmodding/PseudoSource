// File Line: 77
// RVA: 0x25A780
ANTLR3_COMMON_TOKEN_struct *__fastcall antlr3CommonTokenNew(unsigned int ttype)
{
  unsigned int v1; // edi
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  ANTLR3_COMMON_TOKEN_struct *v3; // rbx

  v1 = ttype;
  result = (ANTLR3_COMMON_TOKEN_struct *)antlrCalloc(1u, 0x108u);
  v3 = result;
  if ( result )
  {
    antlr3SetTokenAPI(result);
    v3->factoryMade = 0;
    v3->setType(v3, v1);
    result = v3;
  }
  return result;
}

// File Line: 96
// RVA: 0x25A8E0
ANTLR3_TOKEN_FACTORY_struct *__fastcall antlr3TokenFactoryNew(ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_INPUT_STREAM_struct *v1; // rdi
  ANTLR3_TOKEN_FACTORY_struct *result; // rax
  ANTLR3_TOKEN_FACTORY_struct *v3; // rbx

  v1 = input;
  result = (ANTLR3_TOKEN_FACTORY_struct *)antlrMalloc(0x148ui64);
  v3 = result;
  if ( result )
  {
    *(_QWORD *)&result->thisPool = -1i64;
    result->newToken = newPoolToken;
    result->pools = 0i64;
    result->close = factoryClose;
    result->setInputStream = setInputStream;
    result->reset = factoryReset;
    newPool(result);
    antlr3SetTokenAPI(&v3->unTruc);
    v3->unTruc.factoryMade = 1;
    v3->input = v1;
    v3->unTruc.input = v1;
    if ( v1 )
      v3->unTruc.strFactory = v1->strFactory;
    else
      v3->unTruc.strFactory = 0i64;
    result = v3;
  }
  return result;
}

// File Line: 141
// RVA: 0x25A560
void __fastcall setInputStream(ANTLR3_TOKEN_FACTORY_struct *factory, ANTLR3_INPUT_STREAM_struct *input)
{
  factory->input = input;
  factory->unTruc.input = input;
  if ( input )
    factory->unTruc.strFactory = input->strFactory;
  else
    factory->unTruc.strFactory = 0i64;
}

// File Line: 156
// RVA: 0x25A460
void __fastcall newPool(ANTLR3_TOKEN_FACTORY_struct *factory)
{
  int v1; // eax
  ANTLR3_TOKEN_FACTORY_struct *v2; // rbx

  v1 = ++factory->thisPool;
  v2 = factory;
  if ( v1 <= factory->maxPool )
  {
    factory->nextToken = 0;
  }
  else
  {
    factory->pools = (ANTLR3_COMMON_TOKEN_struct **)antlrRealloc(factory->pools, (unsigned int)(8 * v1 + 8));
    v2->pools[v2->thisPool] = (ANTLR3_COMMON_TOKEN_struct *)antlrCalloc(1u, 0x42000u);
    *(_QWORD *)&v2->maxPool = (unsigned int)v2->thisPool;
  }
}

// File Line: 195
// RVA: 0x25A4C0
ANTLR3_COMMON_TOKEN_struct *__fastcall newPoolToken(ANTLR3_TOKEN_FACTORY_struct *factory)
{
  ANTLR3_TOKEN_FACTORY_struct *v1; // rdi
  ANTLR3_COMMON_TOKEN_struct *v2; // rbx
  ANTLR3_STRING_FACTORY_struct *v3; // rax

  v1 = factory;
  if ( factory->nextToken >= 0x400 )
    newPool(factory);
  v2 = &v1->pools[v1->thisPool][v1->nextToken++];
  if ( !v2->setStartIndex )
  {
    antlr3SetTokenAPI(v2);
    v2->factoryMade = 1;
    v3 = (ANTLR3_STRING_FACTORY_struct *)v1->input;
    if ( v3 )
      v3 = (ANTLR3_STRING_FACTORY_struct *)v3->newPtr;
    v2->strFactory = v3;
    v2->input = v1->input;
  }
  return v2;
}

// File Line: 236
// RVA: 0x25A2F0
void __fastcall factoryReset(ANTLR3_TOKEN_FACTORY_struct *factory)
{
  bool v1; // sf
  ANTLR3_TOKEN_FACTORY_struct *v2; // rbx

  v1 = factory->maxPool < 0;
  v2 = factory;
  factory->thisPool = 0;
  if ( v1 )
  {
    factory->pools = (ANTLR3_COMMON_TOKEN_struct **)antlrRealloc(factory->pools, 8ui64);
    v2->pools[v2->thisPool] = (ANTLR3_COMMON_TOKEN_struct *)antlrCalloc(1u, 0x42000u);
    *(_QWORD *)&v2->maxPool = (unsigned int)v2->thisPool;
  }
  else
  {
    factory->nextToken = 0;
  }
}

// File Line: 246
// RVA: 0x25A230
void __fastcall factoryClose(ANTLR3_TOKEN_FACTORY_struct *factory)
{
  int v1; // edx
  ANTLR3_TOKEN_FACTORY_struct *v2; // rsi
  int v3; // ebp
  __int64 v4; // r14
  unsigned int v5; // eax
  void **v6; // rbx
  __int64 v7; // rdi
  void (*v8)(void); // rax

  v1 = factory->thisPool;
  v2 = factory;
  v3 = 0;
  if ( v1 >= 0 )
  {
    v4 = 0i64;
    while ( v3 == v1 )
    {
      v5 = v2->nextToken;
      if ( v5 )
        goto LABEL_7;
LABEL_12:
      antlrFree(v2->pools[v4]);
      ++v3;
      v2->pools[v4] = 0i64;
      v1 = v2->thisPool;
      ++v4;
      if ( v3 > v1 )
        goto LABEL_13;
    }
    v5 = 1024;
LABEL_7:
    v6 = &v2->pools[v4]->custom;
    v7 = v5;
    do
    {
      if ( *v6 )
      {
        v8 = (void (*)(void))v6[1];
        if ( v8 )
        {
          v8();
          *v6 = 0i64;
        }
      }
      v6 += 33;
      --v7;
    }
    while ( v7 );
    goto LABEL_12;
  }
LABEL_13:
  antlrFree(v2->pools);
  antlrFree(v2);
}

// File Line: 330
// RVA: 0x25A7E0
void __fastcall antlr3SetTokenAPI(ANTLR3_COMMON_TOKEN_struct *token)
{
  token->getText = getText;
  token->setText = setText;
  token->setText8 = setText8;
  token->getType = (unsigned int (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *))UFG::qSymbolUC::as_uint32;
  token->setType = setType;
  token->getLine = (unsigned int (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *))hkaMatrix<float>::Height;
  token->setLine = setLine;
  token->getCharPositionInLine = (int (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *))Scaleform::Render::ShapeMeshProvider::GetLayerCount;
  token->setCharPositionInLine = (void (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *, int))CAkMatrixAwareCtx::SetRegisteredNotif;
  token->getChannel = (unsigned int (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *))Scaleform::MemoryFile::Tell;
  token->setChannel = setChannel;
  token->getTokenIndex = (__int64 (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *))UFG::UIMapBlip::GetType;
  token->setTokenIndex = Scaleform::MemoryHeap::ReleaseOnFree;
  token->getStartIndex = getStartIndex;
  token->setStartIndex = (void (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *, __int64))CAkParameterNodeBase::Parent;
  token->getStopIndex = (__int64 (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *))Scaleform::GFx::MovieImpl::GetHeap;
  token->setStopIndex = (void (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *, __int64))FaceInteractionResultSetTrack::ResolveReferences;
  token->toString = toString;
}

// File Line: 355
// RVA: 0x25A390
ANTLR3_STRING_struct *__fastcall getText(ANTLR3_COMMON_TOKEN_struct *token)
{
  ANTLR3_COMMON_TOKEN_struct *v1; // rdi
  unsigned int v2; // ecx
  unsigned int *v3; // rax
  ANTLR3_STRING_FACTORY_struct *v4; // rcx
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_INPUT_STREAM_struct *v6; // rsi
  __int64 v7; // rbx
  __int64 v8; // rax

  v1 = token;
  v2 = token->textState - 1;
  if ( v2 )
  {
    if ( v2 == 1 )
      return v1->tokText.text;
    if ( v1->type == -1 )
    {
      v3 = (unsigned int *)v1->strFactory->newStr8(v1->strFactory, "<EOF>");
      v4 = v1->strFactory;
      v1->textState = 2;
      v1->tokText.chars = v3;
      *(_QWORD *)v3 = v4;
      return v1->tokText.text;
    }
    v6 = v1->input;
    if ( v6 )
    {
      v7 = v1->getStopIndex(v1);
      v8 = v1->getStartIndex(v1);
      result = v6->substr(v1->input, v8, v7);
    }
    else
    {
      result = 0i64;
    }
  }
  else
  {
    result = (ANTLR3_STRING_struct *)v1->strFactory;
    if ( result )
    {
      result = (ANTLR3_STRING_struct *)result->append8(
                                         (ANTLR3_STRING_struct *)v1->strFactory,
                                         (const char *)v1->tokText.chars);
      v1->textState = 2;
      v1->tokText.chars = (unsigned int *)result;
    }
  }
  return result;
}

// File Line: 419
// RVA: 0x25A5B0
void __fastcall setText8(ANTLR3_COMMON_TOKEN_struct *token, char *text)
{
  if ( text )
  {
    if ( token->textState > 1 )
    {
      (*((void (__fastcall **)(unsigned int *))token->tokText.chars + 5))(token->tokText.chars);
    }
    else
    {
      token->textState = 1;
      token->tokText.chars = (unsigned int *)text;
    }
  }
}

// File Line: 455
// RVA: 0x25A5E0
void __fastcall setText(ANTLR3_COMMON_TOKEN_struct *token, ANTLR3_STRING_struct *text)
{
  token->textState = 2;
  token->tokText.chars = (unsigned int *)text;
}

// File Line: 473
// RVA: 0x25A600
void __fastcall setType(ANTLR3_COMMON_TOKEN_struct *token, unsigned int type)
{
  token->type = type;
}

// File Line: 483
// RVA: 0x25A590
void __fastcall setLine(ANTLR3_COMMON_TOKEN_struct *token, unsigned int line)
{
  token->line = line;
}

// File Line: 488
// RVA: 0x25A360
__int64 __fastcall Scaleform::Render::ShapeMeshProvider::GetLayerCount(hkDataClassDict *this)
{
  return (unsigned int)this->m_version;
}

// File Line: 493
// RVA: 0x25A550
void __fastcall CAkMatrixAwareCtx::SetRegisteredNotif(CAkMatrixAwareCtx *this, unsigned int in_uCallbackFlags)
{
  this->m_uRegisteredNotif = in_uCallbackFlags;
}

// File Line: 498
// RVA: 0x25A350
__int64 __fastcall Scaleform::MemoryFile::Tell(ANTLR3_COMMON_TOKEN_struct *token)
{
  return token->channel;
}

// File Line: 503
// RVA: 0x25A540
void __fastcall setChannel(ANTLR3_COMMON_TOKEN_struct *token, unsigned int channel)
{
  token->channel = channel;
}

// File Line: 513
// RVA: 0x25A5F0
void __fastcall Scaleform::MemoryHeap::ReleaseOnFree(ANTLR3_COMMON_TOKEN_struct *token, __int64 index)
{
  token->index = index;
}

// File Line: 518
// RVA: 0x25A370
__int64 __fastcall getStartIndex(ANTLR3_COMMON_TOKEN_struct *token)
{
  __int64 result; // rax

  result = token->start;
  if ( result == -1 )
    result = (__int64)token->input->data;
  return result;
}

// File Line: 523
// RVA: 0x25A5A0
void __fastcall CAkParameterNodeBase::Parent(CAkParameterNodeBase *this, CAkParameterNodeBase *in_pParent)
{
  this->m_pParentNode = in_pParent;
}

// File Line: 538
// RVA: 0x25A610
ANTLR3_STRING_struct *__fastcall toString(ANTLR3_COMMON_TOKEN_struct *token)
{
  ANTLR3_COMMON_TOKEN_struct *v1; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rsi
  ANTLR3_STRING_FACTORY_struct *v4; // rax
  __int64 v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax

  v1 = token;
  result = (ANTLR3_STRING_struct *)((__int64 (*)(void))token->getText)();
  v3 = result;
  if ( result )
  {
    v4 = result->factory;
    if ( v4 )
    {
      v5 = (__int64)v4->newRaw(v4);
      (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, "[Index: ");
      v6 = v1->getTokenIndex(v1);
      (*(void (__fastcall **)(__int64, __int64))(v5 + 120))(v5, v6);
      (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, " (Start: ");
      v7 = v1->getStartIndex(v1);
      (*(void (__fastcall **)(__int64, __int64))(v5 + 120))(v5, v7);
      (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, "-Stop: ");
      v8 = v1->getStopIndex(v1);
      (*(void (__fastcall **)(__int64, __int64))(v5 + 120))(v5, v8);
      (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, ") ='");
      (*(void (__fastcall **)(__int64, ANTLR3_STRING_struct *))(v5 + 88))(v5, v3);
      (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, "', type<");
      (*(void (__fastcall **)(__int64, _QWORD))(v5 + 120))(v5, v1->type);
      (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, "> ");
      if ( v1->getChannel(v1) )
      {
        (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, "(channel = ");
        v9 = v1->getChannel(v1);
        (*(void (__fastcall **)(__int64, _QWORD))(v5 + 120))(v5, v9);
        (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, ") ");
      }
      (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, "Line: ");
      v10 = v1->getLine(v1);
      (*(void (__fastcall **)(__int64, _QWORD))(v5 + 120))(v5, v10);
      (*(void (__fastcall **)(__int64, const char *))(v5 + 56))(v5, " LinePos:");
      v11 = v1->getCharPositionInLine(v1);
      (*(void (__fastcall **)(__int64, _QWORD))(v5 + 120))(v5, v11);
      (*(void (__fastcall **)(__int64, signed __int64))(v5 + 112))(v5, 93i64);
      result = (ANTLR3_STRING_struct *)v5;
    }
    else
    {
      result = v3;
    }
  }
  return result;
}

