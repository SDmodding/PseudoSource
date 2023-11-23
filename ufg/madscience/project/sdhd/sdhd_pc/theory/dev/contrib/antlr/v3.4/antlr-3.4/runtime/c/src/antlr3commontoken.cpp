// File Line: 77
// RVA: 0x25A780
ANTLR3_COMMON_TOKEN_struct *__fastcall antlr3CommonTokenNew(unsigned int ttype)
{
  ANTLR3_COMMON_TOKEN_struct *result; // rax
  ANTLR3_COMMON_TOKEN_struct *v3; // rbx

  result = (ANTLR3_COMMON_TOKEN_struct *)antlrCalloc(1u, 0x108u);
  v3 = result;
  if ( result )
  {
    antlr3SetTokenAPI(result);
    v3->factoryMade = 0;
    v3->setType(v3, ttype);
    return v3;
  }
  return result;
}

// File Line: 96
// RVA: 0x25A8E0
ANTLR3_TOKEN_FACTORY_struct *__fastcall antlr3TokenFactoryNew(ANTLR3_INPUT_STREAM_struct *input)
{
  ANTLR3_TOKEN_FACTORY_struct *result; // rax
  ANTLR3_TOKEN_FACTORY_struct *v3; // rbx

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
    v3->input = input;
    v3->unTruc.input = input;
    if ( input )
      v3->unTruc.strFactory = input->strFactory;
    else
      v3->unTruc.strFactory = 0i64;
    return v3;
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

  v1 = ++factory->thisPool;
  if ( v1 <= factory->maxPool )
  {
    factory->nextToken = 0;
  }
  else
  {
    factory->pools = (ANTLR3_COMMON_TOKEN_struct **)antlrRealloc(factory->pools, (unsigned int)(8 * v1 + 8));
    factory->pools[factory->thisPool] = (ANTLR3_COMMON_TOKEN_struct *)antlrCalloc(1u, 0x42000u);
    *(_QWORD *)&factory->maxPool = (unsigned int)factory->thisPool;
  }
}

// File Line: 195
// RVA: 0x25A4C0
ANTLR3_COMMON_TOKEN_struct *__fastcall newPoolToken(ANTLR3_TOKEN_FACTORY_struct *factory)
{
  ANTLR3_COMMON_TOKEN_struct *v2; // rbx
  ANTLR3_INPUT_STREAM_struct *input; // rax

  if ( factory->nextToken >= 0x400 )
    newPool(factory);
  v2 = &factory->pools[factory->thisPool][factory->nextToken++];
  if ( !v2->setStartIndex )
  {
    antlr3SetTokenAPI(v2);
    v2->factoryMade = 1;
    input = factory->input;
    if ( input )
      input = (ANTLR3_INPUT_STREAM_struct *)input->strFactory;
    v2->strFactory = (ANTLR3_STRING_FACTORY_struct *)input;
    v2->input = factory->input;
  }
  return v2;
}

// File Line: 236
// RVA: 0x25A2F0
void __fastcall factoryReset(ANTLR3_TOKEN_FACTORY_struct *factory)
{
  bool v1; // sf

  v1 = factory->maxPool < 0;
  factory->thisPool = 0;
  if ( v1 )
  {
    factory->pools = (ANTLR3_COMMON_TOKEN_struct **)antlrRealloc(factory->pools, 8ui64);
    factory->pools[factory->thisPool] = (ANTLR3_COMMON_TOKEN_struct *)antlrCalloc(1u, 0x42000u);
    *(_QWORD *)&factory->maxPool = (unsigned int)factory->thisPool;
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
  int thisPool; // edx
  int v3; // ebp
  __int64 v4; // r14
  unsigned int nextToken; // eax
  void **p_custom; // rbx
  __int64 v7; // rdi
  void (*v8)(void); // rax

  thisPool = factory->thisPool;
  v3 = 0;
  if ( thisPool >= 0 )
  {
    v4 = 0i64;
    while ( v3 == thisPool )
    {
      nextToken = factory->nextToken;
      if ( nextToken )
        goto LABEL_7;
LABEL_12:
      antlrFree((char *)factory->pools[v4]);
      ++v3;
      factory->pools[v4] = 0i64;
      thisPool = factory->thisPool;
      ++v4;
      if ( v3 > thisPool )
        goto LABEL_13;
    }
    nextToken = 1024;
LABEL_7:
    p_custom = &factory->pools[v4]->custom;
    v7 = nextToken;
    do
    {
      if ( *p_custom )
      {
        v8 = (void (*)(void))p_custom[1];
        if ( v8 )
        {
          v8();
          *p_custom = 0i64;
        }
      }
      p_custom += 33;
      --v7;
    }
    while ( v7 );
    goto LABEL_12;
  }
LABEL_13:
  antlrFree((char *)factory->pools);
  antlrFree((char *)factory);
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
  token->getStartIndex = (__int64 (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *))getStartIndex;
  token->setStartIndex = (void (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *, __int64))CAkParameterNodeBase::Parent;
  token->getStopIndex = (__int64 (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *))Scaleform::GFx::MovieImpl::GetHeap;
  token->setStopIndex = (void (__fastcall *)(ANTLR3_COMMON_TOKEN_struct *, __int64))FaceInteractionResultSetTrack::ResolveReferences;
  token->toString = toString;
}

// File Line: 355
// RVA: 0x25A390
ANTLR3_STRING_struct *__fastcall getText(ANTLR3_COMMON_TOKEN_struct *token)
{
  unsigned int v2; // ecx
  unsigned int *v3; // rax
  ANTLR3_STRING_FACTORY_struct *strFactory; // rcx
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_INPUT_STREAM_struct *input; // rsi
  __int64 v7; // rbx
  __int64 v8; // rax

  v2 = token->textState - 1;
  if ( v2 )
  {
    if ( v2 == 1 )
      return token->tokText.text;
    if ( token->type == -1 )
    {
      v3 = (unsigned int *)token->strFactory->newStr8(token->strFactory, "<EOF>");
      strFactory = token->strFactory;
      token->textState = 2;
      token->tokText.chars = v3;
      *(_QWORD *)v3 = strFactory;
      return token->tokText.text;
    }
    input = token->input;
    if ( input )
    {
      v7 = token->getStopIndex(token);
      v8 = token->getStartIndex(token);
      return input->substr(token->input, v8, v7);
    }
    else
    {
      return 0i64;
    }
  }
  else
  {
    result = (ANTLR3_STRING_struct *)token->strFactory;
    if ( result )
    {
      result = (ANTLR3_STRING_struct *)result->append8(token->strFactory, token->tokText.chars);
      token->textState = 2;
      token->tokText.chars = (unsigned int *)result;
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
void *__fastcall getStartIndex(ANTLR3_COMMON_TOKEN_struct *token)
{
  void *result; // rax

  result = (void *)token->start;
  if ( result == (void *)-1i64 )
    return token->input->data;
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
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rsi
  ANTLR3_STRING_FACTORY_struct *factory; // rax
  ANTLR3_STRING_struct *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax

  result = (ANTLR3_STRING_struct *)((__int64 (*)(void))token->getText)();
  v3 = result;
  if ( result )
  {
    factory = result->factory;
    if ( factory )
    {
      v5 = factory->newRaw(factory);
      v5->append8(v5, "[Index: ");
      v6 = token->getTokenIndex(token);
      v5->addi(v5, v6);
      v5->append8(v5, " (Start: ");
      v7 = token->getStartIndex(token);
      v5->addi(v5, v7);
      v5->append8(v5, "-Stop: ");
      v8 = token->getStopIndex(token);
      v5->addi(v5, v8);
      v5->append8(v5, ") =");
      v5->appendS(v5, v3);
      v5->append8(v5, ", type<");
      v5->addi(v5, token->type);
      v5->append8(v5, "> ");
      if ( token->getChannel(token) )
      {
        v5->append8(v5, "(channel = ");
        v9 = token->getChannel(token);
        v5->addi(v5, v9);
        v5->append8(v5, ") ");
      }
      v5->append8(v5, "Line: ");
      v10 = token->getLine(token);
      v5->addi(v5, v10);
      v5->append8(v5, " LinePos:");
      v11 = token->getCharPositionInLine(token);
      v5->addi(v5, v11);
      v5->addc(v5, 93u);
      return v5;
    }
    else
    {
      return v3;
    }
  }
  return result;
}

