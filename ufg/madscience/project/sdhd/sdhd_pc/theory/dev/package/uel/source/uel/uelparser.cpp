// File Line: 330
// RVA: 0x2496C0
const char *__fastcall getGrammarFileName()
{
  return "D:\\UFG\\MadScience\\Project\\SD2\\dev\\Theory\\dev\\Package\\UEL\\Source\\UEL\\UEL.g";
}

// File Line: 341
// RVA: 0x24B8E0
UELParser_Ctx_struct *__fastcall UELParserNew(ANTLR3_COMMON_TOKEN_STREAM_struct *instream)
{
  return UELParserNewSSD(instream, 0i64);
}

// File Line: 355
// RVA: 0x24B8F0
UELParser_Ctx_struct *__fastcall UELParserNewSSD(
        ANTLR3_COMMON_TOKEN_STREAM_struct *instream,
        ANTLR3_RECOGNIZER_SHARED_STATE_struct *state)
{
  UELParser_Ctx_struct *result; // rax
  UELParser_Ctx_struct *v5; // rbx

  result = (UELParser_Ctx_struct *)antlrCalloc(1u, 0xD0u);
  v5 = result;
  if ( result )
  {
    result->pParser = antlr3ParserNewStream(0x401u, instream->tstream, state);
    v5->fragments = fragments;
    v5->fragmentDefinition = fragmentDefinition;
    v5->fragmentUsage = fragmentUsage;
    v5->expression = expression;
    v5->logicalExpression = logicalExpression;
    v5->booleanAndExpression = booleanAndExpression;
    v5->equalityExpression = equalityExpression;
    v5->relationalExpression = relationalExpression;
    v5->additiveExpression = additiveExpression;
    v5->multiplicativeExpression = multiplicativeExpression;
    v5->unaryExpression = unaryExpression;
    v5->referenceExpression = referenceExpression;
    v5->indexedExpression = indexedExpression;
    v5->arrayIndex = arrayIndex;
    v5->primaryExpression = primaryExpression;
    v5->value = value;
    v5->argumentDeclaration = argumentDeclaration;
    v5->argumentUsage = argumentUsage;
    v5->enumeration = enumeration;
    v5->function = function;
    v5->free = UELParserFree;
    v5->reset = UELParserReset;
    v5->getGrammarFileName = getGrammarFileName;
    v5->adaptor = ANTLR3_TREE_ADAPTORNew(instream->tstream->tokenSource->strFactory);
    v5->vectors = antlr3VectorFactoryNew(0);
    v5->pParser->rec->state->tokenNames = UELParserTokenNames;
    return v5;
  }
  return result;
}

// File Line: 424
// RVA: 0x247140
void __fastcall UELParserReset(UELParser_Ctx_struct *ctx)
{
  ctx->pParser->rec->reset(ctx->pParser->rec);
}

// File Line: 432
// RVA: 0x247100
void __fastcall UELParserFree(UELParser_Ctx_struct *ctx)
{
  ctx->vectors->close(ctx->vectors);
  ctx->adaptor->free(ctx->adaptor);
  ctx->pParser->free(ctx->pParser);
  antlrFree(ctx);
}

// File Line: 738
// RVA: 0x248F10
UELParser_fragments_return_struct *__fastcall fragments(
        UELParser_fragments_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  int v5; // edi
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  void *v7; // rbp
  int v8; // ebx
  ANTLR3_INT_STREAM_struct *istream; // rcx
  unsigned int v10; // eax
  ANTLR3_PARSER_struct *pParser; // rax
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rbx
  ANTLR3_STACK_struct *v14; // rcx
  ANTLR3_BASE_TREE_struct *v15; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v18; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v20; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v22; // rax
  UELParser_fragmentDefinition_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  v5 = 0;
  result->start = v4;
  result->stop = v4;
  adaptor = ctx->adaptor;
  result->tree = 0i64;
  v7 = adaptor->nilNode(adaptor);
  while ( 1 )
  {
    v8 = 2;
    istream = ctx->pParser->tstream->istream;
    v10 = istream->_LA(istream, 1);
    if ( v10 == 17 || v10 == 32 )
      v8 = 1;
    pParser = ctx->pParser;
    if ( v8 != 1 )
      break;
    following = pParser->rec->state->following;
    following->push(following, &FOLLOW_fragmentDefinition_in_fragments135, 0i64);
    tree = fragmentDefinition(&resulta, ctx)->tree;
    v14 = ctx->pParser->rec->state->following;
    v14->pop(v14);
    if ( ctx->pParser->rec->state->error == 1 )
      goto $rulefragmentsEx;
    ctx->adaptor->addChild(ctx->adaptor, v7, tree);
    ++v5;
  }
  if ( v5 < 1 )
  {
    pParser->rec->exConstruct(pParser->rec);
    ctx->pParser->rec->state->exception->type = 5;
    ctx->pParser->rec->state->exception->name = "org.antlr.runtime.EarlyExitException";
  }
  else
  {
    pParser->rec->match(pParser->rec, 0xFFFFFFFF, &FOLLOW_EOF_in_fragments138);
  }
$rulefragmentsEx:
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v15 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v7);
  stop = result->stop;
  start = result->start;
  v18 = ctx->adaptor;
  result->tree = v15;
  v18->setTokenBoundaries(v18, v15, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v20 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v22 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v20->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v22,
                                                state->exception);
  }
  return result;
}

// File Line: 869
// RVA: 0x2486A0
UELParser_fragmentDefinition_return_struct *__fastcall fragmentDefinition(
        UELParser_fragmentDefinition_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  void *v6; // rsi
  ANTLR3_COMMON_TOKEN_struct *v7; // rbp
  ANTLR3_INT_STREAM_struct *istream; // rcx
  ANTLR3_INT_STREAM_struct *v9; // rcx
  ANTLR3_INT_STREAM_struct *v10; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v11; // rdi
  __int64 v12; // rax
  ANTLR3_INT_STREAM_struct *v13; // rcx
  unsigned int v14; // eax
  int v15; // ecx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax
  UELParser_argumentDeclaration_return_struct *i; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_INT_STREAM_struct *v20; // rcx
  unsigned int v21; // eax
  int v22; // ecx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r9
  bool v24; // zf
  ANTLR3_BASE_RECOGNIZER_struct *v25; // rcx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v26; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v27; // rax
  ANTLR3_BASE_TREE_struct *v28; // rdi
  ANTLR3_STACK_struct *v29; // rcx
  ANTLR3_BASE_TREE_struct *v30; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v33; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v34; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v35; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v36; // rdi
  ANTLR3_COMMON_TOKEN_struct *v37; // rax
  UELParser_argumentDeclaration_return_struct resulta; // [rsp+48h] [rbp-50h] BYREF
  UELParser_logicalExpression_return_struct v40; // [rsp+60h] [rbp-38h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->start = v4;
  result->stop = v4;
  adaptor = ctx->adaptor;
  result->tree = 0i64;
  v6 = adaptor->nilNode(adaptor);
  ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v7 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  istream = ctx->pParser->tstream->istream;
  if ( istream->_LA(istream, 1) == 17 || (v9 = ctx->pParser->tstream->istream, v9->_LA(v9, 1) == 32) )
  {
    v10 = ctx->pParser->tstream->istream;
    v10->consume(v10);
    v11 = ctx->adaptor;
    v12 = (__int64)v11->create(v11, v7);
    v6 = v11->becomeRoot(ctx->adaptor, (void *)v12, v6);
    ctx->pParser->rec->state->errorRecovery = 0;
    v13 = ctx->pParser->tstream->istream;
    v14 = v13->_LA(v13, 1);
    v15 = 2;
    if ( v14 == 44 )
      v15 = 1;
    if ( v15 == 1 )
    {
      ctx->pParser->rec->match(ctx->pParser->rec, 44u, &FOLLOW_44_in_fragmentDefinition157);
      state = ctx->pParser->rec->state;
      if ( state->error != 1 )
      {
        state->following->push(state->following, &FOLLOW_argumentDeclaration_in_fragmentDefinition162, 0i64);
        for ( i = &resulta; ; i = (UELParser_argumentDeclaration_return_struct *)&v40 )
        {
          tree = argumentDeclaration(i, ctx)->tree;
          following = ctx->pParser->rec->state->following;
          following->pop(following);
          if ( ctx->pParser->rec->state->error == 1 )
            break;
          ctx->adaptor->addChild(ctx->adaptor, v6, tree);
          v20 = ctx->pParser->tstream->istream;
          v21 = v20->_LA(v20, 1);
          v22 = 2;
          rec = ctx->pParser->rec;
          if ( v21 == 46 )
            v22 = 1;
          v24 = v22 == 1;
          v25 = ctx->pParser->rec;
          if ( !v24 )
          {
            rec->match(v25, 45u, &FOLLOW_45_in_fragmentDefinition174);
            if ( ctx->pParser->rec->state->error == 1 )
              break;
            goto LABEL_16;
          }
          rec->match(v25, 46u, &FOLLOW_46_in_fragmentDefinition165);
          v26 = ctx->pParser->rec->state;
          if ( v26->error == 1 )
            break;
          v26->following->push(v26->following, &FOLLOW_argumentDeclaration_in_fragmentDefinition168, 0i64);
        }
      }
    }
    else
    {
LABEL_16:
      ctx->pParser->rec->match(ctx->pParser->rec, 49u, &FOLLOW_49_in_fragmentDefinition179);
      v27 = ctx->pParser->rec->state;
      if ( v27->error != 1 )
      {
        v27->following->push(v27->following, &FOLLOW_logicalExpression_in_fragmentDefinition182, 0i64);
        v28 = logicalExpression(&v40, ctx)->tree;
        v29 = ctx->pParser->rec->state->following;
        v29->pop(v29);
        if ( ctx->pParser->rec->state->error != 1 )
        {
          ctx->adaptor->addChild(ctx->adaptor, v6, v28);
          ctx->pParser->rec->match(ctx->pParser->rec, 51u, &FOLLOW_51_in_fragmentDefinition184);
        }
      }
    }
  }
  else
  {
    ctx->pParser->rec->exConstruct(ctx->pParser->rec);
    ctx->pParser->rec->state->exception->type = 4;
    ctx->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    ctx->pParser->rec->state->exception->expectingSet = 0i64;
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v30 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v6);
  stop = result->stop;
  start = result->start;
  v33 = ctx->adaptor;
  result->tree = v30;
  v33->setTokenBoundaries(v33, v30, start, stop);
  v34 = ctx->pParser->rec;
  if ( v34->state->error == 1 )
  {
    v34->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v35 = ctx->adaptor;
    v36 = ctx->pParser->rec->state;
    v37 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v35->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v37,
                                                v36->exception);
  }
  return result;
}

// File Line: 1119
// RVA: 0x248AE0
UELParser_fragmentUsage_return_struct *__fastcall fragmentUsage(
        UELParser_fragmentUsage_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  void *v6; // rdi
  ANTLR3_COMMON_TOKEN_struct *v7; // rax
  void *v8; // rax
  ANTLR3_COMMON_TOKEN_struct *v9; // rbp
  ANTLR3_INT_STREAM_struct *istream; // rcx
  ANTLR3_INT_STREAM_struct *v11; // rcx
  ANTLR3_INT_STREAM_struct *v12; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v13; // rbx
  __int64 v14; // rax
  int v15; // ebx
  ANTLR3_INT_STREAM_struct *v16; // rcx
  ANTLR3_STACK_struct *following; // rcx
  UELParser_logicalExpression_return_struct *i; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rbx
  ANTLR3_STACK_struct *v20; // rcx
  ANTLR3_INT_STREAM_struct *v21; // rcx
  unsigned int v22; // eax
  int v23; // ecx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax
  ANTLR3_BASE_TREE_struct *v25; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v28; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v30; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v31; // rbx
  ANTLR3_COMMON_TOKEN_struct *v32; // rax
  UELParser_logicalExpression_return_struct resulta; // [rsp+48h] [rbp-50h] BYREF
  char v35; // [rsp+60h] [rbp-38h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->start = v4;
  result->stop = v4;
  adaptor = ctx->adaptor;
  result->tree = 0i64;
  v6 = adaptor->nilNode(adaptor);
  v7 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                       ctx->pParser->rec,
                                       16i64,
                                       &FOLLOW_FRAGMENT_in_fragmentUsage197);
  if ( ctx->pParser->rec->state->error != 1 )
  {
    v8 = ctx->adaptor->create(ctx->adaptor, v7);
    v6 = ctx->adaptor->becomeRoot(ctx->adaptor, v8, v6);
    v9 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
    istream = ctx->pParser->tstream->istream;
    if ( istream->_LA(istream, 1) == 17 || (v11 = ctx->pParser->tstream->istream, v11->_LA(v11, 1) == 32) )
    {
      v12 = ctx->pParser->tstream->istream;
      v12->consume(v12);
      v13 = ctx->adaptor;
      v14 = (__int64)v13->create(v13, v9);
      v13->addChild(ctx->adaptor, v6, (void *)v14);
      ctx->pParser->rec->state->errorRecovery = 0;
      ctx->pParser->rec->match(ctx->pParser->rec, 44u, &FOLLOW_44_in_fragmentUsage206);
      if ( ctx->pParser->rec->state->error != 1 )
      {
        v15 = 2;
        v16 = ctx->pParser->tstream->istream;
        switch ( v16->_LA(v16, 1) )
        {
          case 7u:
          case 8u:
          case 0xDu:
          case 0x10u:
          case 0x11u:
          case 0x15u:
          case 0x19u:
          case 0x1Du:
          case 0x20u:
          case 0x23u:
          case 0x27u:
          case 0x28u:
          case 0x2Cu:
          case 0x31u:
          case 0x32u:
            v15 = 1;
            break;
          default:
            break;
        }
        if ( v15 == 1 )
        {
          following = ctx->pParser->rec->state->following;
          following->push(following, &FOLLOW_logicalExpression_in_fragmentUsage211, 0i64);
          for ( i = &resulta; ; i = (UELParser_logicalExpression_return_struct *)&v35 )
          {
            tree = logicalExpression(i, ctx)->tree;
            v20 = ctx->pParser->rec->state->following;
            v20->pop(v20);
            if ( ctx->pParser->rec->state->error == 1 )
              break;
            ctx->adaptor->addChild(ctx->adaptor, v6, tree);
            v21 = ctx->pParser->tstream->istream;
            v22 = v21->_LA(v21, 1);
            v23 = 2;
            if ( v22 == 46 )
              v23 = 1;
            if ( v23 != 1 )
              goto $loop4;
            ctx->pParser->rec->match(ctx->pParser->rec, 46u, &FOLLOW_46_in_fragmentUsage214);
            state = ctx->pParser->rec->state;
            if ( state->error == 1 )
              break;
            state->following->push(state->following, &FOLLOW_logicalExpression_in_fragmentUsage217, 0i64);
          }
        }
        else
        {
$loop4:
          ctx->pParser->rec->match(ctx->pParser->rec, 45u, &FOLLOW_45_in_fragmentUsage224);
        }
      }
    }
    else
    {
      ctx->pParser->rec->exConstruct(ctx->pParser->rec);
      ctx->pParser->rec->state->exception->type = 4;
      ctx->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      ctx->pParser->rec->state->exception->expectingSet = 0i64;
    }
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v25 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v6);
  stop = result->stop;
  start = result->start;
  v28 = ctx->adaptor;
  result->tree = v25;
  v28->setTokenBoundaries(v28, v25, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v30 = ctx->adaptor;
    v31 = ctx->pParser->rec->state;
    v32 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v30->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v32,
                                                v31->exception);
  }
  return result;
}

// File Line: 1352
// RVA: 0x2484E0
UELParser_expression_return_struct *__fastcall expression(
        UELParser_expression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rbx
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *v8; // rcx
  ANTLR3_BASE_TREE_struct *v9; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v14; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v16; // rax
  UELParser_logicalExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  following = ctx->pParser->rec->state->following;
  following->push(following, &FOLLOW_logicalExpression_in_expression238, 0i64);
  tree = logicalExpression(&resulta, ctx)->tree;
  v8 = ctx->pParser->rec->state->following;
  v8->pop(v8);
  if ( ctx->pParser->rec->state->error != 1 )
  {
    ctx->adaptor->addChild(ctx->adaptor, v5, tree);
    ctx->pParser->rec->match(ctx->pParser->rec, 0xFFFFFFFF, &FOLLOW_EOF_in_expression240);
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v9 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  adaptor = ctx->adaptor;
  result->tree = v9;
  adaptor->setTokenBoundaries(adaptor, v9, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v14 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v16 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v14->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v16,
                                                state->exception);
  }
  return result;
}

// File Line: 1437
// RVA: 0x249920
UELParser_logicalExpression_return_struct *__fastcall logicalExpression(
        UELParser_logicalExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rdi
  ANTLR3_BITSET_LIST_struct *v6; // rdx
  ANTLR3_STACK_struct *i; // r9
  ANTLR3_BASE_TREE_struct *tree; // rsi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_INT_STREAM_struct *istream; // rcx
  unsigned int v11; // eax
  int v12; // ecx
  ANTLR3_COMMON_TOKEN_struct *v13; // rax
  void *v14; // rax
  void *v15; // rax
  ANTLR3_BASE_TREE_struct *v16; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v21; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdi
  ANTLR3_COMMON_TOKEN_struct *v23; // rax
  UELParser_booleanAndExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  v6 = &FOLLOW_booleanAndExpression_in_logicalExpression254;
  for ( i = ctx->pParser->rec->state->following; ; i = ctx->pParser->rec->state->following )
  {
    i->push(i, v6, 0i64);
    tree = booleanAndExpression(&resulta, ctx)->tree;
    following = ctx->pParser->rec->state->following;
    following->pop(following);
    if ( ctx->pParser->rec->state->error == 1 )
      break;
    ctx->adaptor->addChild(ctx->adaptor, v5, tree);
    istream = ctx->pParser->tstream->istream;
    v11 = istream->_LA(istream, 1);
    v12 = 2;
    if ( v11 == 31 )
      v12 = 1;
    if ( v12 != 1 )
      break;
    v13 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                          ctx->pParser->rec,
                                          31i64,
                                          &FOLLOW_OR_in_logicalExpression257);
    if ( ctx->pParser->rec->state->error == 1 )
      break;
    v14 = ctx->adaptor->create(ctx->adaptor, v13);
    v15 = ctx->adaptor->becomeRoot(ctx->adaptor, v14, v5);
    v6 = &FOLLOW_booleanAndExpression_in_logicalExpression260;
    v5 = v15;
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v16 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  adaptor = ctx->adaptor;
  result->tree = v16;
  adaptor->setTokenBoundaries(adaptor, v16, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v21 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v23 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v21->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v23,
                                                state->exception);
  }
  return result;
}

// File Line: 1575
// RVA: 0x247C40
UELParser_booleanAndExpression_return_struct *__fastcall booleanAndExpression(
        UELParser_booleanAndExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rdi
  ANTLR3_BITSET_LIST_struct *v6; // rdx
  ANTLR3_STACK_struct *i; // r9
  ANTLR3_BASE_TREE_struct *tree; // rsi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_INT_STREAM_struct *istream; // rcx
  unsigned int v11; // eax
  int v12; // ecx
  ANTLR3_COMMON_TOKEN_struct *v13; // rax
  void *v14; // rax
  void *v15; // rax
  ANTLR3_BASE_TREE_struct *v16; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v21; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdi
  ANTLR3_COMMON_TOKEN_struct *v23; // rax
  UELParser_equalityExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  v6 = &FOLLOW_equalityExpression_in_booleanAndExpression290;
  for ( i = ctx->pParser->rec->state->following; ; i = ctx->pParser->rec->state->following )
  {
    i->push(i, v6, 0i64);
    tree = equalityExpression(&resulta, ctx)->tree;
    following = ctx->pParser->rec->state->following;
    following->pop(following);
    if ( ctx->pParser->rec->state->error == 1 )
      break;
    ctx->adaptor->addChild(ctx->adaptor, v5, tree);
    istream = ctx->pParser->tstream->istream;
    v11 = istream->_LA(istream, 1);
    v12 = 2;
    if ( v11 == 6 )
      v12 = 1;
    if ( v12 != 1 )
      break;
    v13 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                          ctx->pParser->rec,
                                          6i64,
                                          &FOLLOW_AND_in_booleanAndExpression293);
    if ( ctx->pParser->rec->state->error == 1 )
      break;
    v14 = ctx->adaptor->create(ctx->adaptor, v13);
    v15 = ctx->adaptor->becomeRoot(ctx->adaptor, v14, v5);
    v6 = &FOLLOW_equalityExpression_in_booleanAndExpression297;
    v5 = v15;
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v16 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  adaptor = ctx->adaptor;
  result->tree = v16;
  adaptor->setTokenBoundaries(adaptor, v16, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v21 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v23 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v21->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v23,
                                                state->exception);
  }
  return result;
}

// File Line: 1719
// RVA: 0x248170
UELParser_equalityExpression_return_struct *__fastcall equalityExpression(
        UELParser_equalityExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rsi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *v8; // rcx
  ANTLR3_INT_STREAM_struct *istream; // rcx
  unsigned int v10; // eax
  int v11; // ecx
  ANTLR3_COMMON_TOKEN_struct *v12; // rbp
  ANTLR3_INT_STREAM_struct *v13; // rcx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_INT_STREAM_struct *v15; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rdi
  __int64 v17; // rax
  ANTLR3_STACK_struct *v18; // rcx
  ANTLR3_STACK_struct *v19; // rcx
  ANTLR3_BASE_TREE_struct *v20; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v25; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdi
  ANTLR3_COMMON_TOKEN_struct *v27; // rax
  UELParser_relationalExpression_return_struct resulta; // [rsp+48h] [rbp-30h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  following = ctx->pParser->rec->state->following;
  following->push(following, &FOLLOW_relationalExpression_in_equalityExpression326, 0i64);
  tree = relationalExpression(&resulta, ctx)->tree;
  v8 = ctx->pParser->rec->state->following;
  v8->pop(v8);
  while ( ctx->pParser->rec->state->error != 1 )
  {
    ctx->adaptor->addChild(ctx->adaptor, v5, tree);
    istream = ctx->pParser->tstream->istream;
    v10 = istream->_LA(istream, 1);
    v11 = 2;
    if ( ((v10 - 14) & 0xFFFFFFEF) == 0 )
      v11 = 1;
    if ( v11 != 1 )
      break;
    ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
    v12 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
    v13 = ctx->pParser->tstream->istream;
    if ( v13->_LA(v13, 1) != 14 )
    {
      v14 = ctx->pParser->tstream->istream;
      if ( v14->_LA(v14, 1) != 30 )
      {
        ctx->pParser->rec->exConstruct(ctx->pParser->rec);
        ctx->pParser->rec->state->exception->type = 4;
        ctx->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
        ctx->pParser->rec->state->exception->expectingSet = 0i64;
        break;
      }
    }
    v15 = ctx->pParser->tstream->istream;
    v15->consume(v15);
    adaptor = ctx->adaptor;
    v17 = (__int64)adaptor->create(adaptor, v12);
    v5 = adaptor->becomeRoot(ctx->adaptor, (void *)v17, v5);
    ctx->pParser->rec->state->errorRecovery = 0;
    v18 = ctx->pParser->rec->state->following;
    v18->push(v18, &FOLLOW_relationalExpression_in_equalityExpression336, 0i64);
    tree = relationalExpression(&resulta, ctx)->tree;
    v19 = ctx->pParser->rec->state->following;
    v19->pop(v19);
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v20 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  v23 = ctx->adaptor;
  result->tree = v20;
  v23->setTokenBoundaries(v23, v20, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v25 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v27 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v25->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v27,
                                                state->exception);
  }
  return result;
}

// File Line: 1869
// RVA: 0x24AA10
UELParser_relationalExpression_return_struct *__fastcall relationalExpression(
        UELParser_relationalExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rsi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *v8; // rcx
  int v9; // edi
  ANTLR3_INT_STREAM_struct *istream; // rcx
  unsigned int v11; // eax
  ANTLR3_COMMON_TOKEN_struct *v12; // rbp
  ANTLR3_INT_STREAM_struct *v13; // rcx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_INT_STREAM_struct *v15; // rcx
  ANTLR3_INT_STREAM_struct *v16; // rcx
  ANTLR3_INT_STREAM_struct *v17; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rdi
  __int64 v19; // rax
  ANTLR3_STACK_struct *v20; // rcx
  ANTLR3_STACK_struct *v21; // rcx
  ANTLR3_BASE_TREE_struct *v22; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v25; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v27; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdi
  ANTLR3_COMMON_TOKEN_struct *v29; // rax
  UELParser_additiveExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  following = ctx->pParser->rec->state->following;
  following->push(following, &FOLLOW_additiveExpression_in_relationalExpression372, 0i64);
  tree = additiveExpression(&resulta, ctx)->tree;
  v8 = ctx->pParser->rec->state->following;
  v8->pop(v8);
  while ( ctx->pParser->rec->state->error != 1 )
  {
    ctx->adaptor->addChild(ctx->adaptor, v5, tree);
    v9 = 2;
    istream = ctx->pParser->tstream->istream;
    v11 = istream->_LA(istream, 1);
    if ( v11 >= 0x12 && (v11 <= 0x13 || v11 - 23 <= 1) )
      v9 = 1;
    if ( v9 != 1 )
      break;
    ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
    v12 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
    v13 = ctx->pParser->tstream->istream;
    if ( v13->_LA(v13, 1) < 0x12 || (v14 = ctx->pParser->tstream->istream, v14->_LA(v14, 1) > 0x13) )
    {
      v15 = ctx->pParser->tstream->istream;
      if ( v15->_LA(v15, 1) < 0x17 || (v16 = ctx->pParser->tstream->istream, v16->_LA(v16, 1) > 0x18) )
      {
        ctx->pParser->rec->exConstruct(ctx->pParser->rec);
        ctx->pParser->rec->state->exception->type = 4;
        ctx->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
        ctx->pParser->rec->state->exception->expectingSet = 0i64;
        break;
      }
    }
    v17 = ctx->pParser->tstream->istream;
    v17->consume(v17);
    adaptor = ctx->adaptor;
    v19 = (__int64)adaptor->create(adaptor, v12);
    v5 = adaptor->becomeRoot(ctx->adaptor, (void *)v19, v5);
    ctx->pParser->rec->state->errorRecovery = 0;
    v20 = ctx->pParser->rec->state->following;
    v20->push(v20, &FOLLOW_additiveExpression_in_relationalExpression387, 0i64);
    tree = additiveExpression(&resulta, ctx)->tree;
    v21 = ctx->pParser->rec->state->following;
    v21->pop(v21);
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v22 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  v25 = ctx->adaptor;
  result->tree = v22;
  v25->setTokenBoundaries(v25, v22, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v27 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v29 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v27->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v29,
                                                state->exception);
  }
  return result;
}

// File Line: 2021
// RVA: 0x247160
UELParser_additiveExpression_return_struct *__fastcall additiveExpression(
        UELParser_additiveExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rsi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *v8; // rcx
  int v9; // edi
  ANTLR3_INT_STREAM_struct *istream; // rcx
  unsigned int v11; // eax
  ANTLR3_COMMON_TOKEN_struct *v12; // rbp
  ANTLR3_INT_STREAM_struct *v13; // rcx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_INT_STREAM_struct *v15; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rdi
  __int64 v17; // rax
  ANTLR3_STACK_struct *v18; // rcx
  ANTLR3_STACK_struct *v19; // rcx
  ANTLR3_BASE_TREE_struct *v20; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v25; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdi
  ANTLR3_COMMON_TOKEN_struct *v27; // rax
  UELParser_multiplicativeExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  following = ctx->pParser->rec->state->following;
  following->push(following, &FOLLOW_multiplicativeExpression_in_additiveExpression430, 0i64);
  tree = multiplicativeExpression(&resulta, ctx)->tree;
  v8 = ctx->pParser->rec->state->following;
  v8->pop(v8);
  while ( ctx->pParser->rec->state->error != 1 )
  {
    ctx->adaptor->addChild(ctx->adaptor, v5, tree);
    v9 = 2;
    istream = ctx->pParser->tstream->istream;
    v11 = istream->_LA(istream, 1);
    if ( v11 == 25 || v11 == 34 )
      v9 = 1;
    if ( v9 != 1 )
      break;
    ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
    v12 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
    v13 = ctx->pParser->tstream->istream;
    if ( v13->_LA(v13, 1) != 25 )
    {
      v14 = ctx->pParser->tstream->istream;
      if ( v14->_LA(v14, 1) != 34 )
      {
        ctx->pParser->rec->exConstruct(ctx->pParser->rec);
        ctx->pParser->rec->state->exception->type = 4;
        ctx->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
        ctx->pParser->rec->state->exception->expectingSet = 0i64;
        break;
      }
    }
    v15 = ctx->pParser->tstream->istream;
    v15->consume(v15);
    adaptor = ctx->adaptor;
    v17 = (__int64)adaptor->create(adaptor, v12);
    v5 = adaptor->becomeRoot(ctx->adaptor, (void *)v17, v5);
    ctx->pParser->rec->state->errorRecovery = 0;
    v18 = ctx->pParser->rec->state->following;
    v18->push(v18, &FOLLOW_multiplicativeExpression_in_additiveExpression441, 0i64);
    tree = multiplicativeExpression(&resulta, ctx)->tree;
    v19 = ctx->pParser->rec->state->following;
    v19->pop(v19);
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v20 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  v23 = ctx->adaptor;
  result->tree = v20;
  v23->setTokenBoundaries(v23, v20, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v25 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v27 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v25->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v27,
                                                state->exception);
  }
  return result;
}

// File Line: 2171
// RVA: 0x249B70
UELParser_multiplicativeExpression_return_struct *__fastcall multiplicativeExpression(
        UELParser_multiplicativeExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rsi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *v8; // rcx
  int v9; // edi
  ANTLR3_INT_STREAM_struct *istream; // rcx
  unsigned int v11; // eax
  ANTLR3_COMMON_TOKEN_struct *v12; // rbp
  ANTLR3_INT_STREAM_struct *v13; // rcx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_INT_STREAM_struct *v15; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rdi
  __int64 v17; // rax
  ANTLR3_STACK_struct *v18; // rcx
  ANTLR3_STACK_struct *v19; // rcx
  ANTLR3_BASE_TREE_struct *v20; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v25; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdi
  ANTLR3_COMMON_TOKEN_struct *v27; // rax
  UELParser_unaryExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  following = ctx->pParser->rec->state->following;
  following->push(following, &FOLLOW_unaryExpression_in_multiplicativeExpression471, 0i64);
  tree = unaryExpression(&resulta, ctx)->tree;
  v8 = ctx->pParser->rec->state->following;
  v8->pop(v8);
  while ( ctx->pParser->rec->state->error != 1 )
  {
    ctx->adaptor->addChild(ctx->adaptor, v5, tree);
    v9 = 2;
    istream = ctx->pParser->tstream->istream;
    v11 = istream->_LA(istream, 1);
    if ( v11 == 12 || v11 == 27 )
      v9 = 1;
    if ( v9 != 1 )
      break;
    ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
    v12 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
    v13 = ctx->pParser->tstream->istream;
    if ( v13->_LA(v13, 1) != 12 )
    {
      v14 = ctx->pParser->tstream->istream;
      if ( v14->_LA(v14, 1) != 27 )
      {
        ctx->pParser->rec->exConstruct(ctx->pParser->rec);
        ctx->pParser->rec->state->exception->type = 4;
        ctx->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
        ctx->pParser->rec->state->exception->expectingSet = 0i64;
        break;
      }
    }
    v15 = ctx->pParser->tstream->istream;
    v15->consume(v15);
    adaptor = ctx->adaptor;
    v17 = (__int64)adaptor->create(adaptor, v12);
    v5 = adaptor->becomeRoot(ctx->adaptor, (void *)v17, v5);
    ctx->pParser->rec->state->errorRecovery = 0;
    v18 = ctx->pParser->rec->state->following;
    v18->push(v18, &FOLLOW_unaryExpression_in_multiplicativeExpression482, 0i64);
    tree = unaryExpression(&resulta, ctx)->tree;
    v19 = ctx->pParser->rec->state->following;
    v19->pop(v19);
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v20 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  v23 = ctx->adaptor;
  result->tree = v20;
  v23->setTokenBoundaries(v23, v20, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v25 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v27 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v25->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v27,
                                                state->exception);
  }
  return result;
}   v27,

// File Line: 2321
// RVA: 0x24ADB0
UELParser_unaryExpression_return_struct *__fastcall unaryExpression(
        UELParser_unaryExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  int v4; // ebx
  ANTLR3_BASE_TREE_struct *v5; // rbp
  ANTLR3_COMMON_TOKEN_struct *v6; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v7; // r15
  ANTLR3_TOKEN_STREAM_struct *tstream; // rcx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v9; // r12
  int v10; // ebx
  int v11; // ebx
  void *v12; // rbx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rdx
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rbx
  ANTLR3_STACK_struct *v16; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v17; // rdx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v18; // r13
  ANTLR3_BASE_TREE_struct *v19; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  __int64 v21; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v22; // rdi
  void *v23; // rbx
  __int64 v24; // rax
  void *v25; // rbx
  ANTLR3_BASE_TREE_struct *v26; // rax
  ANTLR3_COMMON_TOKEN_struct *v27; // rax
  void *v28; // rax
  ANTLR3_STACK_struct *v29; // rcx
  UELParser_referenceExpression_return_struct *v30; // rcx
  ANTLR3_STACK_struct *v31; // rcx
  ANTLR3_BASE_TREE_struct *v32; // rbx
  ANTLR3_STACK_struct *v33; // rcx
  ANTLR3_BASE_TREE_struct *v34; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v37; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v38; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v39; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v41; // rax
  UELParser_referenceExpression_return_struct resulta; // [rsp+48h] [rbp-70h] BYREF
  char v44; // [rsp+60h] [rbp-58h] BYREF
  UELParser_referenceExpression_return_struct v45; // [rsp+78h] [rbp-40h] BYREF

  v4 = 1;
  v5 = 0i64;
  v6 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  v7 = 0i64;
  result->start = v6;
  result->stop = v6;
  tstream = ctx->pParser->tstream;
  v9 = 0i64;
  result->tree = 0i64;
  switch ( tstream->istream->_LA(tstream->istream, 1) )
  {
    case 7u:
    case 8u:
    case 0xDu:
    case 0x10u:
    case 0x11u:
    case 0x15u:
    case 0x20u:
    case 0x23u:
    case 0x27u:
    case 0x28u:
    case 0x2Cu:
    case 0x31u:
    case 0x32u:
      goto $LN28_9;
    case 0x19u:
      v4 = 3;
      goto $LN28_9;
    case 0x1Du:
      v4 = 2;
$LN28_9:
      v10 = v4 - 1;
      if ( v10 )
      {
        v11 = v10 - 1;
        if ( v11 )
        {
          if ( v11 == 1 )
          {
            v12 = ctx->pParser->rec->match(ctx->pParser->rec, 25i64, &FOLLOW_MINUS_in_unaryExpression533);
            rec = ctx->pParser->rec;
            if ( rec->state->error != 1 )
            {
              v7 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, rec, "token MINUS");
              v7->add(v7, v12, 0i64);
              following = ctx->pParser->rec->state->following;
              following->push(following, &FOLLOW_referenceExpression_in_unaryExpression535, 0i64);
              tree = referenceExpression(&resulta, ctx)->tree;
              v16 = ctx->pParser->rec->state->following;
              v16->pop(v16);
              v17 = ctx->pParser->rec;
              if ( v17->state->error != 1 )
              {
                v9 = antlr3RewriteRuleSubtreeStreamNewAE(ctx->adaptor, v17, "rule referenceExpression");
                v9->add(v9, tree, 0i64);
                v18 = antlr3RewriteRuleSubtreeStreamNewAEE(
                        ctx->adaptor,
                        ctx->pParser->rec,
                        "token retval",
                        result->tree);
                v19 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
                adaptor = ctx->adaptor;
                v5 = v19;
                result->tree = v19;
                v21 = (__int64)adaptor->nilNode(adaptor);
                v22 = ctx->adaptor;
                v23 = (void *)v21;
                v24 = (__int64)v22->createTypeText(v22, 28u, "NEGATE");
                v25 = v22->becomeRoot(ctx->adaptor, (void *)v24, v23);
                v26 = v9->nextTree(v9);
                ctx->adaptor->addChild(ctx->adaptor, v25, v26);
                ctx->adaptor->addChild(ctx->adaptor, v5, v25);
                result->tree = v5;
                if ( v18 )
                  v18->free(v18);
              }
            }
          }
          goto $ruleunaryExpressionEx;
        }
        v5 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
        v27 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                              ctx->pParser->rec,
                                              29i64,
                                              &FOLLOW_NOT_in_unaryExpression521);
        if ( ctx->pParser->rec->state->error == 1 )
          goto $ruleunaryExpressionEx;
        v28 = ctx->adaptor->create(ctx->adaptor, v27);
        v5 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->becomeRoot(ctx->adaptor, v28, v5);
        v29 = ctx->pParser->rec->state->following;
        v29->push(v29, &FOLLOW_referenceExpression_in_unaryExpression524, 0i64);
        v30 = (UELParser_referenceExpression_return_struct *)&v44;
      }
      else
      {
        v5 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
        v31 = ctx->pParser->rec->state->following;
        v31->push(v31, &FOLLOW_referenceExpression_in_unaryExpression512, 0i64);
        v30 = &v45;
      }
      v32 = referenceExpression(v30, ctx)->tree;
      v33 = ctx->pParser->rec->state->following;
      v33->pop(v33);
      if ( ctx->pParser->rec->state->error != 1 )
        ctx->adaptor->addChild(ctx->adaptor, v5, v32);
$ruleunaryExpressionEx:
      result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
      result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
      v34 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
      stop = result->stop;
      start = result->start;
      v37 = ctx->adaptor;
      result->tree = v34;
      v37->setTokenBoundaries(v37, v34, start, stop);
      if ( v7 )
        v7->free(v7);
      if ( v9 )
        v9->free(v9);
      v38 = ctx->pParser->rec;
      if ( v38->state->error == 1 )
      {
        v38->reportError(ctx->pParser->rec);
        ctx->pParser->rec->recover(ctx->pParser->rec);
        v39 = ctx->adaptor;
        state = ctx->pParser->rec->state;
        v41 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
        result->tree = (ANTLR3_BASE_TREE_struct *)v39->errorNode(
                                                    ctx->adaptor,
                                                    ctx->pParser->tstream,
                                                    result->start,
                                                    v41,
                                                    state->exception);
      }
      return result;
    default:
      ctx->pParser->rec->exConstruct(ctx->pParser->rec);
      ctx->pParser->rec->state->exception->type = 3;
      ctx->pParser->rec->state->exception->message = &customCaption;
      ctx->pParser->rec->state->exception->decisionNum = 12;
      ctx->pParser->rec->state->exception->state = 0;
      goto $ruleunaryExpressionEx;
  }
}

// File Line: 2568
// RVA: 0x24A7C0
UELParser_referenceExpression_return_struct *__fastcall referenceExpression(
        UELParser_referenceExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rdi
  ANTLR3_BITSET_LIST_struct *v6; // rdx
  ANTLR3_STACK_struct *i; // r9
  ANTLR3_BASE_TREE_struct *tree; // rsi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_INT_STREAM_struct *istream; // rcx
  unsigned int v11; // eax
  int v12; // ecx
  ANTLR3_COMMON_TOKEN_struct *v13; // rax
  void *v14; // rax
  void *v15; // rax
  ANTLR3_BASE_TREE_struct *v16; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v21; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdi
  ANTLR3_COMMON_TOKEN_struct *v23; // rax
  UELParser_indexedExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  v6 = &FOLLOW_indexedExpression_in_referenceExpression567;
  for ( i = ctx->pParser->rec->state->following; ; i = ctx->pParser->rec->state->following )
  {
    i->push(i, v6, 0i64);
    tree = indexedExpression(&resulta, ctx)->tree;
    following = ctx->pParser->rec->state->following;
    following->pop(following);
    if ( ctx->pParser->rec->state->error == 1 )
      break;
    ctx->adaptor->addChild(ctx->adaptor, v5, tree);
    istream = ctx->pParser->tstream->istream;
    v11 = istream->_LA(istream, 1);
    v12 = 2;
    if ( v11 == 36 )
      v12 = 1;
    if ( v12 != 1 )
      break;
    v13 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                          ctx->pParser->rec,
                                          36i64,
                                          &FOLLOW_REFERENCE_in_referenceExpression570);
    if ( ctx->pParser->rec->state->error == 1 )
      break;
    v14 = ctx->adaptor->create(ctx->adaptor, v13);
    v15 = ctx->adaptor->becomeRoot(ctx->adaptor, v14, v5);
    v6 = &FOLLOW_indexedExpression_in_referenceExpression573;
    v5 = v15;
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v16 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  adaptor = ctx->adaptor;
  result->tree = v16;
  adaptor->setTokenBoundaries(adaptor, v16, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v21 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v23 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v21->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v23,
                                                state->exception);
  }
  return result;
}

// File Line: 2706
// RVA: 0x2496D0
UELParser_indexedExpression_return_struct *__fastcall indexedExpression(
        UELParser_indexedExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rdi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rbx
  ANTLR3_STACK_struct *v8; // rcx
  void *v9; // rax
  int v10; // ebx
  ANTLR3_INT_STREAM_struct *istream; // rcx
  ANTLR3_STACK_struct *v12; // rcx
  ANTLR3_BASE_TREE_struct *v13; // rbx
  ANTLR3_STACK_struct *v14; // rcx
  ANTLR3_BASE_TREE_struct *v15; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v20; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v22; // rax
  UELParser_primaryExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  following = ctx->pParser->rec->state->following;
  following->push(following, &FOLLOW_primaryExpression_in_indexedExpression596, 0i64);
  tree = primaryExpression(&resulta, ctx)->tree;
  v8 = ctx->pParser->rec->state->following;
  v8->pop(v8);
  if ( ctx->pParser->rec->state->error != 1 )
  {
    v9 = ctx->adaptor->becomeRoot(ctx->adaptor, tree, v5);
    v10 = 2;
    v5 = v9;
    istream = ctx->pParser->tstream->istream;
    if ( istream->_LA(istream, 1) == 47 )
      v10 = 1;
    if ( v10 == 1 )
    {
      v12 = ctx->pParser->rec->state->following;
      v12->push(v12, &FOLLOW_arrayIndex_in_indexedExpression600, 0i64);
      v13 = arrayIndex((UELParser_arrayIndex_return_struct *)&resulta, ctx)->tree;
      v14 = ctx->pParser->rec->state->following;
      v14->pop(v14);
      if ( ctx->pParser->rec->state->error != 1 )
        ctx->adaptor->addChild(ctx->adaptor, v5, v13);
    }
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v15 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  adaptor = ctx->adaptor;
  result->tree = v15;
  adaptor->setTokenBoundaries(adaptor, v15, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v20 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v22 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v20->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v22,
                                                state->exception);
  }
  return result;
}

// File Line: 2820
// RVA: 0x247A50
UELParser_arrayIndex_return_struct *__fastcall arrayIndex(
        UELParser_arrayIndex_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  void *v5; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // r9
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *v9; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v14; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v15; // rbx
  ANTLR3_COMMON_TOKEN_struct *v16; // rax
  UELParser_logicalExpression_return_struct resulta; // [rsp+48h] [rbp-20h] BYREF

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v4;
  result->stop = v4;
  v5 = ctx->adaptor->nilNode(ctx->adaptor);
  ctx->pParser->rec->match(ctx->pParser->rec, 47u, &FOLLOW_47_in_arrayIndex614);
  state = ctx->pParser->rec->state;
  if ( state->error != 1 )
  {
    state->following->push(state->following, &FOLLOW_logicalExpression_in_arrayIndex617, 0i64);
    tree = logicalExpression(&resulta, ctx)->tree;
    following = ctx->pParser->rec->state->following;
    following->pop(following);
    if ( ctx->pParser->rec->state->error != 1 )
    {
      ctx->adaptor->addChild(ctx->adaptor, v5, tree);
      ctx->pParser->rec->match(ctx->pParser->rec, 48u, &FOLLOW_48_in_arrayIndex619);
    }
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v9 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  adaptor = ctx->adaptor;
  result->tree = v9;
  adaptor->setTokenBoundaries(adaptor, v9, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v14 = ctx->adaptor;
    v15 = ctx->pParser->rec->state;
    v16 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v14->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v16,
                                                v15->exception);
  }
  return result;
}

// File Line: 2916
// RVA: 0x249ED0
UELParser_primaryExpression_return_struct *__fastcall primaryExpression(
        UELParser_primaryExpression_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  int v4; // ebx
  ANTLR3_BASE_TREE_struct *v5; // r15
  ANTLR3_COMMON_TOKEN_struct *v6; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v7; // r13
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v8; // rdi
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v9; // r12
  ANTLR3_INT_STREAM_struct *istream; // rcx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v11; // rbp
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rbx
  ANTLR3_STACK_struct *v17; // rcx
  void *v18; // rax
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rdx
  void *v20; // rbx
  ANTLR3_STACK_struct *v21; // rcx
  ANTLR3_BASE_TREE_struct *v22; // rbx
  ANTLR3_STACK_struct *v23; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v24; // rdx
  void *v25; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v26; // rdx
  void *v27; // rbx
  ANTLR3_BASE_TREE_struct *v28; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  __int64 v30; // rax
  const char *v31; // r8
  __int64 v32; // rdx
  void *v33; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v34; // rdx
  void *v35; // rbx
  ANTLR3_STACK_struct *v36; // rcx
  ANTLR3_BASE_TREE_struct *v37; // rbx
  ANTLR3_STACK_struct *v38; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v39; // rdx
  void *v40; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v41; // rdx
  void *v42; // rbx
  ANTLR3_BASE_TREE_struct *v43; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v44; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v45; // rdi
  void *v46; // rbx
  __int64 v47; // rax
  void *v48; // rbx
  ANTLR3_BASE_TREE_struct *v49; // rax
  void *v50; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v51; // rdx
  void *v52; // rbx
  ANTLR3_STACK_struct *v53; // rcx
  ANTLR3_BASE_TREE_struct *v54; // rbx
  ANTLR3_STACK_struct *v55; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v56; // rdx
  void *v57; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v58; // rdx
  void *v59; // rbx
  ANTLR3_BASE_TREE_struct *v60; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v61; // rcx
  __int64 v62; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v63; // rdi
  void *v64; // rbx
  __int64 v65; // rax
  void *v66; // rbx
  ANTLR3_BASE_TREE_struct *v67; // rax
  ANTLR3_BASE_TREE_struct *v68; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v71; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v72; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v73; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v75; // rax
  UELParser_logicalExpression_return_struct v77; // [rsp+48h] [rbp-B0h] BYREF
  UELParser_logicalExpression_return_struct v78; // [rsp+60h] [rbp-98h] BYREF
  UELParser_value_return_struct resulta; // [rsp+78h] [rbp-80h] BYREF
  UELParser_logicalExpression_return_struct v80; // [rsp+90h] [rbp-68h] BYREF
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v81; // [rsp+100h] [rbp+8h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v82; // [rsp+108h] [rbp+10h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v83; // [rsp+110h] [rbp+18h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v84; // [rsp+118h] [rbp+20h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v85; // [rsp+118h] [rbp+20h]

  v4 = 1;
  v5 = 0i64;
  v6 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  v82 = 0i64;
  result->start = v6;
  result->stop = v6;
  v83 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  istream = ctx->pParser->tstream->istream;
  v11 = 0i64;
  result->tree = 0i64;
  switch ( istream->_LA(istream, 1) )
  {
    case 7u:
    case 8u:
    case 0xDu:
    case 0x10u:
    case 0x11u:
    case 0x15u:
    case 0x20u:
    case 0x23u:
    case 0x27u:
    case 0x28u:
      v4 = 4;
      goto $LN53_1;
    case 0x2Cu:
      goto $LN53_1;
    case 0x31u:
      v4 = 2;
      goto $LN53_1;
    case 0x32u:
      v4 = 3;
$LN53_1:
      v12 = v4 - 1;
      if ( v12 )
      {
        v13 = v12 - 1;
        if ( v13 )
        {
          v14 = v13 - 1;
          if ( v14 )
          {
            if ( v14 == 1 )
            {
              v5 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
              following = ctx->pParser->rec->state->following;
              following->push(following, &FOLLOW_value_in_primaryExpression689, 0i64);
              tree = value(&resulta, ctx)->tree;
              v17 = ctx->pParser->rec->state->following;
              v17->pop(v17);
              if ( ctx->pParser->rec->state->error != 1 )
                ctx->adaptor->addChild(ctx->adaptor, v5, tree);
            }
            goto $ruleprimaryExpressionEx;
          }
          v18 = ctx->pParser->rec->match(ctx->pParser->rec, 50i64, &FOLLOW_50_in_primaryExpression670);
          rec = ctx->pParser->rec;
          v20 = v18;
          if ( rec->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v9 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, rec, "token 50");
          v9->add(v9, v20, 0i64);
          v21 = ctx->pParser->rec->state->following;
          v21->push(v21, &FOLLOW_logicalExpression_in_primaryExpression672, 0i64);
          v22 = logicalExpression(&v77, ctx)->tree;
          v23 = ctx->pParser->rec->state->following;
          v23->pop(v23);
          v24 = ctx->pParser->rec;
          if ( v24->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v11 = antlr3RewriteRuleSubtreeStreamNewAE(ctx->adaptor, v24, "rule logicalExpression");
          v11->add(v11, v22, 0i64);
          v25 = ctx->pParser->rec->match(ctx->pParser->rec, 51i64, &FOLLOW_51_in_primaryExpression674);
          v26 = ctx->pParser->rec;
          v27 = v25;
          if ( v26->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v81 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v26, "token 51");
          v81->add(v81, v27, 0i64);
          v84 = antlr3RewriteRuleSubtreeStreamNewAEE(ctx->adaptor, ctx->pParser->rec, "token retval", result->tree);
          v28 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
          adaptor = ctx->adaptor;
          v5 = v28;
          result->tree = v28;
          v30 = (__int64)adaptor->nilNode(adaptor);
          v31 = "DEBUG_THIS_RECURSIVELY";
          v32 = 10i64;
        }
        else
        {
          v33 = ctx->pParser->rec->match(ctx->pParser->rec, 49i64, &FOLLOW_49_in_primaryExpression651);
          v34 = ctx->pParser->rec;
          v35 = v33;
          if ( v34->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v82 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v34, "token 49");
          v82->add(v82, v35, 0i64);
          v36 = ctx->pParser->rec->state->following;
          v36->push(v36, &FOLLOW_logicalExpression_in_primaryExpression653, 0i64);
          v37 = logicalExpression(&v78, ctx)->tree;
          v38 = ctx->pParser->rec->state->following;
          v38->pop(v38);
          v39 = ctx->pParser->rec;
          if ( v39->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v11 = antlr3RewriteRuleSubtreeStreamNewAE(ctx->adaptor, v39, "rule logicalExpression");
          v11->add(v11, v37, 0i64);
          v40 = ctx->pParser->rec->match(ctx->pParser->rec, 51i64, &FOLLOW_51_in_primaryExpression655);
          v41 = ctx->pParser->rec;
          v42 = v40;
          if ( v41->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v81 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v41, "token 51");
          v81->add(v81, v42, 0i64);
          v84 = antlr3RewriteRuleSubtreeStreamNewAEE(ctx->adaptor, ctx->pParser->rec, "token retval", result->tree);
          v43 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
          v44 = ctx->adaptor;
          v5 = v43;
          result->tree = v43;
          v30 = (__int64)v44->nilNode(v44);
          v31 = "DEBUG_THIS";
          v32 = 9i64;
        }
        v45 = ctx->adaptor;
        v46 = (void *)v30;
        v47 = (__int64)v45->createTypeText(v45, v32, v31);
        v48 = v45->becomeRoot(ctx->adaptor, (void *)v47, v46);
        v49 = v11->nextTree(v11);
        ctx->adaptor->addChild(ctx->adaptor, v48, v49);
        ctx->adaptor->addChild(ctx->adaptor, v5, v48);
        result->tree = v5;
        if ( v84 )
          v84->free(v84);
        v8 = v81;
      }
      else
      {
        v50 = ctx->pParser->rec->match(ctx->pParser->rec, 44i64, &FOLLOW_44_in_primaryExpression631);
        v51 = ctx->pParser->rec;
        v52 = v50;
        if ( v51->state->error != 1 )
        {
          v7 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v51, "token 44");
          v7->add(v7, v52, 0i64);
          v53 = ctx->pParser->rec->state->following;
          v53->push(v53, &FOLLOW_logicalExpression_in_primaryExpression633, 0i64);
          v54 = logicalExpression(&v80, ctx)->tree;
          v55 = ctx->pParser->rec->state->following;
          v55->pop(v55);
          v56 = ctx->pParser->rec;
          if ( v56->state->error != 1 )
          {
            v11 = antlr3RewriteRuleSubtreeStreamNewAE(ctx->adaptor, v56, "rule logicalExpression");
            v11->add(v11, v54, 0i64);
            v57 = ctx->pParser->rec->match(ctx->pParser->rec, 45i64, &FOLLOW_45_in_primaryExpression635);
            v58 = ctx->pParser->rec;
            v59 = v57;
            if ( v58->state->error != 1 )
            {
              v83 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v58, "token 45");
              v83->add(v83, v59, 0i64);
              v85 = antlr3RewriteRuleSubtreeStreamNewAEE(ctx->adaptor, ctx->pParser->rec, "token retval", result->tree);
              v60 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
              v61 = ctx->adaptor;
              v5 = v60;
              result->tree = v60;
              v62 = (__int64)v61->nilNode(v61);
              v63 = ctx->adaptor;
              v64 = (void *)v62;
              v65 = (__int64)v63->createTypeText(v63, 33u, "PARENTHESIZE");
              v66 = v63->becomeRoot(ctx->adaptor, (void *)v65, v64);
              v67 = v11->nextTree(v11);
              ctx->adaptor->addChild(ctx->adaptor, v66, v67);
              ctx->adaptor->addChild(ctx->adaptor, v5, v66);
              result->tree = v5;
              if ( v85 )
                v85->free(v85);
              v8 = 0i64;
            }
          }
        }
      }
$ruleprimaryExpressionEx:
      result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
      result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
      v68 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
      stop = result->stop;
      start = result->start;
      v71 = ctx->adaptor;
      result->tree = v68;
      v71->setTokenBoundaries(v71, v68, start, stop);
      if ( v82 )
        v82->free(v82);
      if ( v83 )
        v83->free(v83);
      if ( v7 )
        v7->free(v7);
      if ( v8 )
        v8->free(v8);
      if ( v9 )
        v9->free(v9);
      if ( v11 )
        v11->free(v11);
      v72 = ctx->pParser->rec;
      if ( v72->state->error == 1 )
      {
        v72->reportError(ctx->pParser->rec);
        ctx->pParser->rec->recover(ctx->pParser->rec);
        v73 = ctx->adaptor;
        state = ctx->pParser->rec->state;
        v75 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
        result->tree = (ANTLR3_BASE_TREE_struct *)v73->errorNode(
                                                    ctx->adaptor,
                                                    ctx->pParser->tstream,
                                                    result->start,
                                                    v75,
                                                    state->exception);
      }
      return result;
    default:
      ctx->pParser->rec->exConstruct(ctx->pParser->rec);
      ctx->pParser->rec->state->exception->type = 3;
      ctx->pParser->rec->state->exception->message = &customCaption;
      ctx->pParser->rec->state->exception->decisionNum = 15;
      ctx->pParser->rec->state->exception->state = 0;
      goto $ruleprimaryExpressionEx;
  }
}

// File Line: 3321
// RVA: 0x24B2D0
UELParser_value_return_struct *__fastcall value(UELParser_value_return_struct *result, UELParser_Ctx_struct *ctx)
{
  int v4; // edi
  void *v5; // rbx
  ANTLR3_COMMON_TOKEN_struct *v6; // rax
  ANTLR3_INT_STREAM_struct *istream; // rcx
  void *v8; // rax
  ANTLR3_BITSET_LIST_struct *v9; // r8
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r9
  __int64 v11; // rdx
  ANTLR3_COMMON_TOKEN_struct *v12; // rax
  void *v13; // rax
  void *v14; // rax
  void *v15; // rax
  void *v16; // rax
  void *v17; // rax
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *v20; // rcx
  ANTLR3_STACK_struct *v21; // rcx
  ANTLR3_BASE_TREE_struct *v22; // rdi
  ANTLR3_STACK_struct *v23; // rcx
  void *v24; // rax
  ANTLR3_STACK_struct *v25; // rcx
  ANTLR3_BASE_TREE_struct *v26; // rdi
  ANTLR3_STACK_struct *v27; // rcx
  ANTLR3_STACK_struct *v28; // rcx
  ANTLR3_BASE_TREE_struct *v29; // rdi
  ANTLR3_STACK_struct *v30; // rcx
  ANTLR3_BASE_TREE_struct *v31; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v35; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v36; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v38; // rax
  UELParser_enumeration_return_struct v40; // [rsp+48h] [rbp-70h] BYREF
  UELParser_argumentUsage_return_struct v41; // [rsp+60h] [rbp-58h] BYREF
  UELParser_function_return_struct resulta; // [rsp+78h] [rbp-40h] BYREF
  UELParser_fragmentUsage_return_struct v43; // [rsp+90h] [rbp-28h] BYREF

  v4 = 1;
  v5 = 0i64;
  v6 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->tree = 0i64;
  result->start = v6;
  result->stop = v6;
  istream = ctx->pParser->tstream->istream;
  switch ( istream->_LA(istream, 1) )
  {
    case 7u:
      v4 = 9;
      goto $LN47_0;
    case 8u:
      v4 = 3;
      goto $LN47_0;
    case 0xDu:
      v4 = 7;
      goto $LN47_0;
    case 0x10u:
      v4 = 10;
      goto $LN47_0;
    case 0x11u:
      v4 = 6;
      goto $LN47_0;
    case 0x15u:
      goto $LN47_0;
    case 0x20u:
      v4 = 8;
      goto $LN47_0;
    case 0x23u:
      v4 = 2;
      goto $LN47_0;
    case 0x27u:
      v4 = 5;
      goto $LN47_0;
    case 0x28u:
      v4 = 4;
$LN47_0:
      switch ( v4 )
      {
        case 1:
          v8 = ctx->adaptor->nilNode(ctx->adaptor);
          v9 = &FOLLOW_INTEGER_in_value703;
          rec = ctx->pParser->rec;
          v5 = v8;
          v11 = 21i64;
          goto LABEL_13;
        case 2:
          v14 = ctx->adaptor->nilNode(ctx->adaptor);
          v9 = &FOLLOW_REAL_in_value709;
          v11 = 35i64;
          v5 = v14;
          rec = ctx->pParser->rec;
          goto LABEL_13;
        case 3:
          v15 = ctx->adaptor->nilNode(ctx->adaptor);
          v9 = &FOLLOW_BOOLEAN_in_value715;
          v11 = 8i64;
          v5 = v15;
          rec = ctx->pParser->rec;
          goto LABEL_13;
        case 4:
          v16 = ctx->adaptor->nilNode(ctx->adaptor);
          v9 = &FOLLOW_SYMBOL_in_value720;
          v11 = 40i64;
          v5 = v16;
          rec = ctx->pParser->rec;
          goto LABEL_13;
        case 5:
          v17 = ctx->adaptor->nilNode(ctx->adaptor);
          v9 = &FOLLOW_STRING_in_value725;
          v11 = 39i64;
          v5 = v17;
          rec = ctx->pParser->rec;
          goto LABEL_13;
        case 6:
          v5 = ctx->adaptor->nilNode(ctx->adaptor);
          following = ctx->pParser->rec->state->following;
          following->push(following, &FOLLOW_function_in_value730, 0i64);
          tree = function(&resulta, ctx)->tree;
          v20 = ctx->pParser->rec->state->following;
          v20->pop(v20);
          if ( ctx->pParser->rec->state->error != 1 )
            ctx->adaptor->addChild(ctx->adaptor, v5, tree);
          goto $rulevalueEx;
        case 7:
          v5 = ctx->adaptor->nilNode(ctx->adaptor);
          v21 = ctx->pParser->rec->state->following;
          v21->push(v21, &FOLLOW_enumeration_in_value735, 0i64);
          v22 = enumeration(&v40, ctx)->tree;
          v23 = ctx->pParser->rec->state->following;
          v23->pop(v23);
          if ( ctx->pParser->rec->state->error != 1 )
            ctx->adaptor->addChild(ctx->adaptor, v5, v22);
          goto $rulevalueEx;
        case 8:
          v24 = ctx->adaptor->nilNode(ctx->adaptor);
          v9 = &FOLLOW_PARAMETER_in_value740;
          v11 = 32i64;
          v5 = v24;
          rec = ctx->pParser->rec;
LABEL_13:
          v12 = (ANTLR3_COMMON_TOKEN_struct *)rec->match(rec, v11, v9);
          if ( ctx->pParser->rec->state->error != 1 )
          {
            v13 = ctx->adaptor->create(ctx->adaptor, v12);
            ctx->adaptor->addChild(ctx->adaptor, v5, v13);
          }
          break;
        case 9:
          v5 = ctx->adaptor->nilNode(ctx->adaptor);
          v25 = ctx->pParser->rec->state->following;
          v25->push(v25, &FOLLOW_argumentUsage_in_value745, 0i64);
          v26 = argumentUsage(&v41, ctx)->tree;
          v27 = ctx->pParser->rec->state->following;
          v27->pop(v27);
          if ( ctx->pParser->rec->state->error != 1 )
            ctx->adaptor->addChild(ctx->adaptor, v5, v26);
          break;
        case 10:
          v5 = ctx->adaptor->nilNode(ctx->adaptor);
          v28 = ctx->pParser->rec->state->following;
          v28->push(v28, &FOLLOW_fragmentUsage_in_value750, 0i64);
          v29 = fragmentUsage(&v43, ctx)->tree;
          v30 = ctx->pParser->rec->state->following;
          v30->pop(v30);
          if ( ctx->pParser->rec->state->error != 1 )
            ctx->adaptor->addChild(ctx->adaptor, v5, v29);
          break;
        default:
          goto $rulevalueEx;
      }
      break;
    default:
      ctx->pParser->rec->exConstruct(ctx->pParser->rec);
      ctx->pParser->rec->state->exception->type = 3;
      ctx->pParser->rec->state->exception->message = &customCaption;
      ctx->pParser->rec->state->exception->decisionNum = 16;
      ctx->pParser->rec->state->exception->state = 0;
      break;
  }
$rulevalueEx:
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v31 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v5);
  stop = result->stop;
  start = result->start;
  adaptor = ctx->adaptor;
  result->tree = v31;
  adaptor->setTokenBoundaries(adaptor, v31, start, stop);
  v35 = ctx->pParser->rec;
  if ( v35->state->error == 1 )
  {
    v35->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v36 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v38 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v36->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v38,
                                                state->exception);
  }
  return result;
}

// File Line: 3679
// RVA: 0x2474C0
UELParser_argumentDeclaration_return_struct *__fastcall argumentDeclaration(
        UELParser_argumentDeclaration_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  void *v6; // rdi
  ANTLR3_COMMON_TOKEN_struct *v7; // rax
  void *v8; // rax
  ANTLR3_COMMON_TOKEN_struct *v9; // rax
  void *v10; // rax
  ANTLR3_COMMON_TOKEN_struct *v11; // rbp
  ANTLR3_INT_STREAM_struct *istream; // rcx
  ANTLR3_INT_STREAM_struct *v13; // rcx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v15; // rbx
  __int64 v16; // rax
  ANTLR3_BASE_TREE_struct *v17; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v20; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v22; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v24; // rax

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->start = v4;
  result->stop = v4;
  adaptor = ctx->adaptor;
  result->tree = 0i64;
  v6 = adaptor->nilNode(adaptor);
  v7 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                       ctx->pParser->rec,
                                       7i64,
                                       &FOLLOW_ARGUMENT_in_argumentDeclaration780);
  if ( ctx->pParser->rec->state->error != 1 )
  {
    v8 = ctx->adaptor->create(ctx->adaptor, v7);
    v6 = ctx->adaptor->becomeRoot(ctx->adaptor, v8, v6);
    v9 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                         ctx->pParser->rec,
                                         32i64,
                                         &FOLLOW_PARAMETER_in_argumentDeclaration783);
    if ( ctx->pParser->rec->state->error != 1 )
    {
      v10 = ctx->adaptor->create(ctx->adaptor, v9);
      ctx->adaptor->addChild(ctx->adaptor, v6, v10);
      ctx->pParser->rec->match(ctx->pParser->rec, 37u, &FOLLOW_SCOPE_in_argumentDeclaration785);
      if ( ctx->pParser->rec->state->error != 1 )
      {
        v11 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
        istream = ctx->pParser->tstream->istream;
        if ( istream->_LA(istream, 1) == 13 || (v13 = ctx->pParser->tstream->istream, v13->_LA(v13, 1) == 41) )
        {
          v14 = ctx->pParser->tstream->istream;
          v14->consume(v14);
          v15 = ctx->adaptor;
          v16 = (__int64)v15->create(v15, v11);
          v15->addChild(ctx->adaptor, v6, (void *)v16);
          ctx->pParser->rec->state->errorRecovery = 0;
        }
        else
        {
          ctx->pParser->rec->exConstruct(ctx->pParser->rec);
          ctx->pParser->rec->state->exception->type = 4;
          ctx->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
          ctx->pParser->rec->state->exception->expectingSet = 0i64;
        }
      }
    }
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v17 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v6);
  stop = result->stop;
  start = result->start;
  v20 = ctx->adaptor;
  result->tree = v17;
  v20->setTokenBoundaries(v20, v17, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v22 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v24 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v22->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v24,
                                                state->exception);
  }
  return result;
}

// File Line: 3804
// RVA: 0x2477B0
UELParser_argumentUsage_return_struct *__fastcall argumentUsage(
        UELParser_argumentUsage_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_BASE_TREE_struct *v4; // r15
  ANTLR3_COMMON_TOKEN_struct *v5; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // rdi
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v7; // rbp
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rcx
  __int64 v9; // rbx
  ANTLR3_BASE_RECOGNIZER_struct *v10; // rdx
  void *v11; // rbx
  ANTLR3_BASE_RECOGNIZER_struct *v12; // rdx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v13; // r12
  ANTLR3_BASE_TREE_struct *v14; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  void *v16; // rbx
  ANTLR3_BASE_TREE_struct *v17; // rax
  void *v18; // rbx
  ANTLR3_BASE_TREE_struct *v19; // rax
  ANTLR3_BASE_TREE_struct *v20; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v24; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v25; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v27; // rax

  v4 = 0i64;
  v5 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->start = v5;
  result->stop = v5;
  v6 = 0i64;
  v7 = 0i64;
  rec = ctx->pParser->rec;
  result->tree = 0i64;
  v9 = (__int64)rec->match(rec, 7u, &FOLLOW_ARGUMENT_in_argumentUsage802);
  v10 = ctx->pParser->rec;
  if ( v10->state->error != 1 )
  {
    v6 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v10, "token ARGUMENT");
    v6->add(v6, (void *)v9, 0i64);
    v11 = ctx->pParser->rec->match(ctx->pParser->rec, 32i64, &FOLLOW_PARAMETER_in_argumentUsage804);
    v12 = ctx->pParser->rec;
    if ( v12->state->error != 1 )
    {
      v7 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v12, "token PARAMETER");
      v7->add(v7, v11, 0i64);
      v13 = antlr3RewriteRuleSubtreeStreamNewAEE(ctx->adaptor, ctx->pParser->rec, "token retval", result->tree);
      v14 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
      adaptor = ctx->adaptor;
      v4 = v14;
      result->tree = v14;
      v16 = adaptor->nilNode(adaptor);
      v17 = v6->nextNode(v6);
      v18 = ctx->adaptor->becomeRoot(ctx->adaptor, v17, v16);
      v19 = v7->nextNode(v7);
      ctx->adaptor->addChild(ctx->adaptor, v18, v19);
      ctx->adaptor->addChild(ctx->adaptor, v4, v18);
      result->tree = v4;
      if ( v13 )
        v13->free(v13);
    }
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v20 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v4);
  stop = result->stop;
  start = result->start;
  v23 = ctx->adaptor;
  result->tree = v20;
  v23->setTokenBoundaries(v23, v20, start, stop);
  if ( v6 )
    v6->free(v6);
  if ( v7 )
    v7->free(v7);
  v24 = ctx->pParser->rec;
  if ( v24->state->error == 1 )
  {
    v24->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v25 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v27 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v25->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v27,
                                                state->exception);
  }
  return result;
}

// File Line: 3932
// RVA: 0x247E90
UELParser_enumeration_return_struct *__fastcall enumeration(
        UELParser_enumeration_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  void *v6; // rdi
  ANTLR3_COMMON_TOKEN_struct *v7; // rax
  void *v8; // rax
  ANTLR3_COMMON_TOKEN_struct *v9; // rax
  void *v10; // rax
  ANTLR3_COMMON_TOKEN_struct *v11; // rbp
  ANTLR3_INT_STREAM_struct *istream; // rcx
  ANTLR3_INT_STREAM_struct *v13; // rcx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_INT_STREAM_struct *v15; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v16; // rbx
  __int64 v17; // rax
  ANTLR3_BASE_TREE_struct *v18; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v21; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *rec; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rbx
  ANTLR3_COMMON_TOKEN_struct *v25; // rax

  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->start = v4;
  result->stop = v4;
  adaptor = ctx->adaptor;
  result->tree = 0i64;
  v6 = adaptor->nilNode(adaptor);
  v7 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                       ctx->pParser->rec,
                                       13i64,
                                       &FOLLOW_ENUMERATION_in_enumeration833);
  if ( ctx->pParser->rec->state->error != 1 )
  {
    v8 = ctx->adaptor->create(ctx->adaptor, v7);
    ctx->adaptor->addChild(ctx->adaptor, v6, v8);
    v9 = (ANTLR3_COMMON_TOKEN_struct *)ctx->pParser->rec->match(
                                         ctx->pParser->rec,
                                         37i64,
                                         &FOLLOW_SCOPE_in_enumeration835);
    if ( ctx->pParser->rec->state->error != 1 )
    {
      v10 = ctx->adaptor->create(ctx->adaptor, v9);
      v6 = ctx->adaptor->becomeRoot(ctx->adaptor, v10, v6);
      v11 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
      istream = ctx->pParser->tstream->istream;
      if ( istream->_LA(istream, 1) == 13
        || (v13 = ctx->pParser->tstream->istream, v13->_LA(v13, 1) == 17)
        || (v14 = ctx->pParser->tstream->istream, v14->_LA(v14, 1) == 32) )
      {
        v15 = ctx->pParser->tstream->istream;
        v15->consume(v15);
        v16 = ctx->adaptor;
        v17 = (__int64)v16->create(v16, v11);
        v16->addChild(ctx->adaptor, v6, (void *)v17);
        ctx->pParser->rec->state->errorRecovery = 0;
      }
      else
      {
        ctx->pParser->rec->exConstruct(ctx->pParser->rec);
        ctx->pParser->rec->state->exception->type = 4;
        ctx->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
        ctx->pParser->rec->state->exception->expectingSet = 0i64;
      }
    }
  }
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v18 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v6);
  stop = result->stop;
  start = result->start;
  v21 = ctx->adaptor;
  result->tree = v18;
  v21->setTokenBoundaries(v21, v18, start, stop);
  rec = ctx->pParser->rec;
  if ( rec->state->error == 1 )
  {
    rec->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v23 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v25 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v23->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v25,
                                                state->exception);
  }
  return result;
}

// File Line: 4046
// RVA: 0x249150
UELParser_function_return_struct *__fastcall function(
        UELParser_function_return_struct *result,
        UELParser_Ctx_struct *ctx)
{
  ANTLR3_BASE_TREE_struct *v4; // r15
  ANTLR3_COMMON_TOKEN_struct *v5; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // r12
  ANTLR3_BASE_RECOGNIZER_struct *rec; // rcx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v8; // r13
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v9; // rbp
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v10; // rsi
  __int64 v11; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v12; // rdx
  void *v13; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v14; // rdx
  int v15; // edi
  ANTLR3_INT_STREAM_struct *istream; // rcx
  ANTLR3_STACK_struct *following; // rcx
  ANTLR3_BASE_TREE_struct *tree; // rdi
  ANTLR3_STACK_struct *v19; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v20; // rdx
  ANTLR3_INT_STREAM_struct *v21; // rcx
  unsigned int v22; // eax
  int v23; // ecx
  void *v24; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v25; // rdx
  ANTLR3_STACK_struct *v26; // rcx
  ANTLR3_BASE_TREE_struct *v27; // rdi
  ANTLR3_STACK_struct *v28; // rcx
  void *v29; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v30; // rdx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v31; // r12
  ANTLR3_BASE_TREE_struct *v32; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rcx
  void *v34; // rdi
  ANTLR3_BASE_TREE_struct *v35; // rax
  void *v36; // rdi
  ANTLR3_BASE_TREE_struct *v37; // rax
  ANTLR3_BASE_TREE_struct *v38; // rax
  ANTLR3_COMMON_TOKEN_struct *stop; // r9
  ANTLR3_COMMON_TOKEN_struct *start; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v41; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v42; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v43; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rdi
  ANTLR3_COMMON_TOKEN_struct *v45; // rax
  UELParser_logicalExpression_return_struct resulta; // [rsp+48h] [rbp-70h] BYREF
  UELParser_logicalExpression_return_struct v48; // [rsp+60h] [rbp-58h] BYREF
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v49; // [rsp+C0h] [rbp+8h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v50; // [rsp+C8h] [rbp+10h]

  v4 = 0i64;
  v5 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1i64);
  result->start = v5;
  result->stop = v5;
  v49 = 0i64;
  v6 = 0i64;
  rec = ctx->pParser->rec;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  result->tree = 0i64;
  v11 = (__int64)rec->match(rec, 17u, &FOLLOW_FUNCTION_in_function939);
  v12 = ctx->pParser->rec;
  if ( v12->state->error != 1 )
  {
    v49 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v12, "token FUNCTION");
    v49->add(v49, (void *)v11, 0i64);
    v13 = ctx->pParser->rec->match(ctx->pParser->rec, 44i64, &FOLLOW_44_in_function941);
    v14 = ctx->pParser->rec;
    if ( v14->state->error != 1 )
    {
      v8 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v14, "token 44");
      v8->add(v8, v13, 0i64);
      v15 = 2;
      istream = ctx->pParser->tstream->istream;
      switch ( istream->_LA(istream, 1) )
      {
        case 7u:
        case 8u:
        case 0xDu:
        case 0x10u:
        case 0x11u:
        case 0x15u:
        case 0x19u:
        case 0x1Du:
        case 0x20u:
        case 0x23u:
        case 0x27u:
        case 0x28u:
        case 0x2Cu:
        case 0x31u:
        case 0x32u:
          v15 = 1;
          break;
        default:
          break;
      }
      if ( v15 == 1 )
      {
        following = ctx->pParser->rec->state->following;
        following->push(following, &FOLLOW_logicalExpression_in_function945, 0i64);
        tree = logicalExpression(&resulta, ctx)->tree;
        v19 = ctx->pParser->rec->state->following;
        v19->pop(v19);
        v20 = ctx->pParser->rec;
        if ( v20->state->error == 1 )
          goto $rulefunctionEx;
        v10 = antlr3RewriteRuleSubtreeStreamNewAE(ctx->adaptor, v20, "rule logicalExpression");
        v10->add(v10, tree, 0i64);
        while ( 1 )
        {
          v21 = ctx->pParser->tstream->istream;
          v22 = v21->_LA(v21, 1);
          v23 = 2;
          if ( v22 == 46 )
            v23 = 1;
          if ( v23 != 1 )
            break;
          v24 = ctx->pParser->rec->match(ctx->pParser->rec, 46i64, &FOLLOW_46_in_function948);
          v25 = ctx->pParser->rec;
          if ( v25->state->error == 1 )
            goto $rulefunctionEx;
          if ( !v9 )
            v9 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v25, "token 46");
          v9->add(v9, v24, 0i64);
          v26 = ctx->pParser->rec->state->following;
          v26->push(v26, &FOLLOW_logicalExpression_in_function950, 0i64);
          v27 = logicalExpression(&v48, ctx)->tree;
          v28 = ctx->pParser->rec->state->following;
          v28->pop(v28);
          if ( ctx->pParser->rec->state->error == 1 )
            goto $rulefunctionEx;
          v10->add(v10, v27, 0i64);
        }
      }
      v29 = ctx->pParser->rec->match(ctx->pParser->rec, 45i64, &FOLLOW_45_in_function957);
      v30 = ctx->pParser->rec;
      if ( v30->state->error != 1 )
      {
        v50 = antlr3RewriteRuleTOKENStreamNewAE(ctx->adaptor, v30, "token 45");
        v50->add(v50, v29, 0i64);
        v31 = antlr3RewriteRuleSubtreeStreamNewAEE(ctx->adaptor, ctx->pParser->rec, "token retval", result->tree);
        v32 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->nilNode(ctx->adaptor);
        adaptor = ctx->adaptor;
        v4 = v32;
        result->tree = v32;
        v34 = adaptor->nilNode(adaptor);
        v35 = v49->nextNode(v49);
        v36 = ctx->adaptor->becomeRoot(ctx->adaptor, v35, v34);
        if ( v10 )
        {
          while ( v10->hasNext(v10) )
          {
            v37 = v10->nextTree(v10);
            ctx->adaptor->addChild(ctx->adaptor, v36, v37);
          }
          v10->reset(v10);
        }
        ctx->adaptor->addChild(ctx->adaptor, v4, v36);
        result->tree = v4;
        if ( v31 )
          v31->free(v31);
        v6 = v50;
      }
    }
  }
$rulefunctionEx:
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  result->stop = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
  v38 = (ANTLR3_BASE_TREE_struct *)ctx->adaptor->rulePostProcessing(ctx->adaptor, v4);
  stop = result->stop;
  start = result->start;
  v41 = ctx->adaptor;
  result->tree = v38;
  v41->setTokenBoundaries(v41, v38, start, stop);
  if ( v49 )
    v49->free(v49);
  if ( v6 )
    v6->free(v6);
  if ( v8 )
    v8->free(v8);
  if ( v9 )
    v9->free(v9);
  if ( v10 )
    v10->free(v10);
  v42 = ctx->pParser->rec;
  if ( v42->state->error == 1 )
  {
    v42->reportError(ctx->pParser->rec);
    ctx->pParser->rec->recover(ctx->pParser->rec);
    v43 = ctx->adaptor;
    state = ctx->pParser->rec->state;
    v45 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 0xFFFFFFFFi64);
    result->tree = (ANTLR3_BASE_TREE_struct *)v43->errorNode(
                                                ctx->adaptor,
                                                ctx->pParser->tstream,
                                                result->start,
                                                v45,
                                                state->exception);
  }
  return result;
}

