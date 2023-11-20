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
UELParser_Ctx_struct *__fastcall UELParserNewSSD(ANTLR3_COMMON_TOKEN_STREAM_struct *instream, ANTLR3_RECOGNIZER_SHARED_STATE_struct *state)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rsi
  ANTLR3_COMMON_TOKEN_STREAM_struct *v3; // rdi
  UELParser_Ctx_struct *result; // rax
  UELParser_Ctx_struct *v5; // rbx

  v2 = state;
  v3 = instream;
  result = (UELParser_Ctx_struct *)antlrCalloc(1u, 0xD0u);
  v5 = result;
  if ( result )
  {
    result->pParser = antlr3ParserNewStream(0x401u, v3->tstream, v2);
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
    v5->adaptor = ANTLR3_TREE_ADAPTORNew(v3->tstream->tokenSource->strFactory);
    v5->vectors = antlr3VectorFactoryNew(0);
    v5->pParser->rec->state->tokenNames = UELParserTokenNames;
    result = v5;
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
  UELParser_Ctx_struct *v1; // rbx

  v1 = ctx;
  ctx->vectors->close(ctx->vectors);
  v1->adaptor->free(v1->adaptor);
  v1->pParser->free(v1->pParser);
  antlrFree(v1);
}

// File Line: 738
// RVA: 0x248F10
UELParser_fragments_return_struct *__fastcall fragments(UELParser_fragments_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_fragments_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  signed int v5; // edi
  ANTLR3_BASE_TREE_ADAPTOR_struct *v6; // rcx
  __int64 v7; // rbp
  signed int v8; // ebx
  ANTLR3_INT_STREAM_struct *v9; // rcx
  unsigned int v10; // eax
  ANTLR3_PARSER_struct *v11; // rax
  ANTLR3_STACK_struct *v12; // rcx
  UELParser_fragmentDefinition_return_struct *v13; // rax
  ANTLR3_BASE_TREE_struct *v14; // rbx
  ANTLR3_COMMON_TOKEN_struct *v15; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v16; // ST38_8
  ANTLR3_STACK_struct *v17; // rcx
  __int64 v18; // rax
  ANTLR3_COMMON_TOKEN_struct *v19; // r9
  ANTLR3_COMMON_TOKEN_struct *v20; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v21; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v22; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v24; // rbx
  __int64 v25; // rax
  UELParser_fragmentDefinition_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v5 = 0;
  v3->start = v4;
  v3->stop = v4;
  v6 = v2->adaptor;
  v3->tree = 0i64;
  v7 = (__int64)v6->nilNode(v6);
  while ( 1 )
  {
    v8 = 2;
    v9 = v2->pParser->tstream->istream;
    v10 = v9->_LA(v9, 1);
    if ( v10 == 17 || v10 == 32 )
      v8 = 1;
    v11 = v2->pParser;
    if ( v8 != 1 )
      break;
    v12 = v11->rec->state->following;
    v12->push(v12, &FOLLOW_fragmentDefinition_in_fragments135, 0i64);
    v13 = fragmentDefinition(&resulta, v2);
    v14 = v13->tree;
    v15 = v13->start;
    v16 = v13->stop;
    v17 = v2->pParser->rec->state->following;
    v17->pop(v17);
    if ( v2->pParser->rec->state->error == 1 )
      goto $rulefragmentsEx;
    v2->adaptor->addChild(v2->adaptor, (void *)v7, v14);
    ++v5;
  }
  if ( v5 < 1 )
  {
    v11->rec->exConstruct(v11->rec);
    v2->pParser->rec->state->exception->type = 5;
    v2->pParser->rec->state->exception->name = "org.antlr.runtime.EarlyExitException";
  }
  else
  {
    v11->rec->match(v11->rec, 0xFFFFFFFF, &FOLLOW_EOF_in_fragments138);
  }
$rulefragmentsEx:
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v18 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v7);
  v19 = v3->stop;
  v20 = v3->start;
  v21 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v18;
  v21->setTokenBoundaries(v21, (void *)v18, v20, v19);
  v22 = v2->pParser->rec;
  if ( v22->state->error == 1 )
  {
    v22->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v23 = v2->adaptor;
    v24 = v2->pParser->rec->state;
    v25 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v23->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v25,
                                            v24->exception);
  }
  return v3;
}

// File Line: 869
// RVA: 0x2486A0
UELParser_fragmentDefinition_return_struct *__fastcall fragmentDefinition(UELParser_fragmentDefinition_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_fragmentDefinition_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rcx
  __int64 v6; // rsi
  __int64 v7; // rbp
  ANTLR3_INT_STREAM_struct *v8; // rcx
  ANTLR3_INT_STREAM_struct *v9; // rcx
  ANTLR3_INT_STREAM_struct *v10; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v11; // rdi
  __int64 v12; // rax
  ANTLR3_INT_STREAM_struct *v13; // rcx
  unsigned int v14; // eax
  signed int v15; // ecx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v16; // rax
  UELParser_argumentDeclaration_return_struct *i; // rcx
  UELParser_argumentDeclaration_return_struct *v18; // rax
  ANTLR3_BASE_TREE_struct *v19; // rdi
  ANTLR3_COMMON_TOKEN_struct *v20; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v21; // ST38_8
  ANTLR3_STACK_struct *v22; // rcx
  ANTLR3_INT_STREAM_struct *v23; // rcx
  unsigned int v24; // eax
  signed int v25; // ecx
  ANTLR3_BASE_RECOGNIZER_struct *v26; // r9
  bool v27; // zf
  ANTLR3_BASE_RECOGNIZER_struct *v28; // rcx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v29; // rax
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v30; // rax
  UELParser_logicalExpression_return_struct *v31; // rax
  ANTLR3_BASE_TREE_struct *v32; // rdi
  ANTLR3_COMMON_TOKEN_struct *v33; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v34; // ST38_8
  ANTLR3_STACK_struct *v35; // rcx
  __int64 v36; // rax
  ANTLR3_COMMON_TOKEN_struct *v37; // r9
  ANTLR3_COMMON_TOKEN_struct *v38; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v39; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v40; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v41; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v42; // rdi
  __int64 v43; // rax
  UELParser_argumentDeclaration_return_struct resulta; // [rsp+48h] [rbp-50h]
  UELParser_logicalExpression_return_struct v46; // [rsp+60h] [rbp-38h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->start = v4;
  v3->stop = v4;
  v5 = v2->adaptor;
  v3->tree = 0i64;
  v6 = (__int64)v5->nilNode(v5);
  v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
  v7 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
  v8 = v2->pParser->tstream->istream;
  if ( v8->_LA(v8, 1) == 17 || (v9 = v2->pParser->tstream->istream, v9->_LA(v9, 1) == 32) )
  {
    v10 = v2->pParser->tstream->istream;
    v10->consume(v10);
    v11 = v2->adaptor;
    v12 = (__int64)v11->create(v11, (ANTLR3_COMMON_TOKEN_struct *)v7);
    v6 = (__int64)v11->becomeRoot(v2->adaptor, (void *)v12, (void *)v6);
    v2->pParser->rec->state->errorRecovery = 0;
    v13 = v2->pParser->tstream->istream;
    v14 = v13->_LA(v13, 1);
    v15 = 2;
    if ( v14 == 44 )
      v15 = 1;
    if ( v15 == 1 )
    {
      v2->pParser->rec->match(v2->pParser->rec, 44u, &FOLLOW_44_in_fragmentDefinition157);
      v16 = v2->pParser->rec->state;
      if ( v16->error != 1 )
      {
        v16->following->push(v16->following, &FOLLOW_argumentDeclaration_in_fragmentDefinition162, 0i64);
        for ( i = &resulta; ; i = (UELParser_argumentDeclaration_return_struct *)&v46 )
        {
          v18 = argumentDeclaration(i, v2);
          v19 = v18->tree;
          v20 = v18->start;
          v21 = v18->stop;
          v22 = v2->pParser->rec->state->following;
          v22->pop(v22);
          if ( v2->pParser->rec->state->error == 1 )
            break;
          v2->adaptor->addChild(v2->adaptor, (void *)v6, v19);
          v23 = v2->pParser->tstream->istream;
          v24 = v23->_LA(v23, 1);
          v25 = 2;
          v26 = v2->pParser->rec;
          if ( v24 == 46 )
            v25 = 1;
          v27 = v25 == 1;
          v28 = v2->pParser->rec;
          if ( !v27 )
          {
            v26->match(v28, 45u, &FOLLOW_45_in_fragmentDefinition174);
            if ( v2->pParser->rec->state->error == 1 )
              break;
            goto LABEL_16;
          }
          v26->match(v28, 46u, &FOLLOW_46_in_fragmentDefinition165);
          v29 = v2->pParser->rec->state;
          if ( v29->error == 1 )
            break;
          v29->following->push(v29->following, &FOLLOW_argumentDeclaration_in_fragmentDefinition168, 0i64);
        }
      }
    }
    else
    {
LABEL_16:
      v2->pParser->rec->match(v2->pParser->rec, 49u, &FOLLOW_49_in_fragmentDefinition179);
      v30 = v2->pParser->rec->state;
      if ( v30->error != 1 )
      {
        v30->following->push(v30->following, &FOLLOW_logicalExpression_in_fragmentDefinition182, 0i64);
        v31 = logicalExpression(&v46, v2);
        v32 = v31->tree;
        v33 = v31->start;
        v34 = v31->stop;
        v35 = v2->pParser->rec->state->following;
        v35->pop(v35);
        if ( v2->pParser->rec->state->error != 1 )
        {
          v2->adaptor->addChild(v2->adaptor, (void *)v6, v32);
          v2->pParser->rec->match(v2->pParser->rec, 51u, &FOLLOW_51_in_fragmentDefinition184);
        }
      }
    }
  }
  else
  {
    v2->pParser->rec->exConstruct(v2->pParser->rec);
    v2->pParser->rec->state->exception->type = 4;
    v2->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    v2->pParser->rec->state->exception->expectingSet = 0i64;
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v36 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v6);
  v37 = v3->stop;
  v38 = v3->start;
  v39 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v36;
  v39->setTokenBoundaries(v39, (void *)v36, v38, v37);
  v40 = v2->pParser->rec;
  if ( v40->state->error == 1 )
  {
    v40->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v41 = v2->adaptor;
    v42 = v2->pParser->rec->state;
    v43 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v41->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v43,
                                            v42->exception);
  }
  return v3;
}

// File Line: 1119
// RVA: 0x248AE0
UELParser_fragmentUsage_return_struct *__fastcall fragmentUsage(UELParser_fragmentUsage_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_fragmentUsage_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rcx
  __int64 v6; // rdi
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rbp
  ANTLR3_INT_STREAM_struct *v10; // rcx
  ANTLR3_INT_STREAM_struct *v11; // rcx
  ANTLR3_INT_STREAM_struct *v12; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v13; // rbx
  __int64 v14; // rax
  signed int v15; // ebx
  ANTLR3_INT_STREAM_struct *v16; // rcx
  ANTLR3_STACK_struct *v17; // rcx
  UELParser_logicalExpression_return_struct *i; // rcx
  UELParser_logicalExpression_return_struct *v19; // rax
  ANTLR3_BASE_TREE_struct *v20; // rbx
  ANTLR3_COMMON_TOKEN_struct *v21; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v22; // ST38_8
  ANTLR3_STACK_struct *v23; // rcx
  ANTLR3_INT_STREAM_struct *v24; // rcx
  unsigned int v25; // eax
  signed int v26; // ecx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v27; // rax
  __int64 v28; // rax
  ANTLR3_COMMON_TOKEN_struct *v29; // r9
  ANTLR3_COMMON_TOKEN_struct *v30; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v31; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v32; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v33; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v34; // rbx
  __int64 v35; // rax
  UELParser_logicalExpression_return_struct resulta; // [rsp+48h] [rbp-50h]
  char v38; // [rsp+60h] [rbp-38h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->start = v4;
  v3->stop = v4;
  v5 = v2->adaptor;
  v3->tree = 0i64;
  v6 = (__int64)v5->nilNode(v5);
  v7 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 16u, &FOLLOW_FRAGMENT_in_fragmentUsage197);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v8 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v7);
    v6 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v8, (void *)v6);
    v9 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
    v10 = v2->pParser->tstream->istream;
    if ( v10->_LA(v10, 1) == 17 || (v11 = v2->pParser->tstream->istream, v11->_LA(v11, 1) == 32) )
    {
      v12 = v2->pParser->tstream->istream;
      v12->consume(v12);
      v13 = v2->adaptor;
      v14 = (__int64)v13->create(v13, (ANTLR3_COMMON_TOKEN_struct *)v9);
      v13->addChild(v2->adaptor, (void *)v6, (void *)v14);
      v2->pParser->rec->state->errorRecovery = 0;
      v2->pParser->rec->match(v2->pParser->rec, 44u, &FOLLOW_44_in_fragmentUsage206);
      if ( v2->pParser->rec->state->error != 1 )
      {
        v15 = 2;
        v16 = v2->pParser->tstream->istream;
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
          v17 = v2->pParser->rec->state->following;
          v17->push(v17, &FOLLOW_logicalExpression_in_fragmentUsage211, 0i64);
          for ( i = &resulta; ; i = (UELParser_logicalExpression_return_struct *)&v38 )
          {
            v19 = logicalExpression(i, v2);
            v20 = v19->tree;
            v21 = v19->start;
            v22 = v19->stop;
            v23 = v2->pParser->rec->state->following;
            v23->pop(v23);
            if ( v2->pParser->rec->state->error == 1 )
              break;
            v2->adaptor->addChild(v2->adaptor, (void *)v6, v20);
            v24 = v2->pParser->tstream->istream;
            v25 = v24->_LA(v24, 1);
            v26 = 2;
            if ( v25 == 46 )
              v26 = 1;
            if ( v26 != 1 )
              goto $loop4;
            v2->pParser->rec->match(v2->pParser->rec, 46u, &FOLLOW_46_in_fragmentUsage214);
            v27 = v2->pParser->rec->state;
            if ( v27->error == 1 )
              break;
            v27->following->push(v27->following, &FOLLOW_logicalExpression_in_fragmentUsage217, 0i64);
          }
        }
        else
        {
$loop4:
          v2->pParser->rec->match(v2->pParser->rec, 45u, &FOLLOW_45_in_fragmentUsage224);
        }
      }
    }
    else
    {
      v2->pParser->rec->exConstruct(v2->pParser->rec);
      v2->pParser->rec->state->exception->type = 4;
      v2->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      v2->pParser->rec->state->exception->expectingSet = 0i64;
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v28 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v6);
  v29 = v3->stop;
  v30 = v3->start;
  v31 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v28;
  v31->setTokenBoundaries(v31, (void *)v28, v30, v29);
  v32 = v2->pParser->rec;
  if ( v32->state->error == 1 )
  {
    v32->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v33 = v2->adaptor;
    v34 = v2->pParser->rec->state;
    v35 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v33->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v35,
                                            v34->exception);
  }
  return v3;
}

// File Line: 1352
// RVA: 0x2484E0
UELParser_expression_return_struct *__fastcall expression(UELParser_expression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_expression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rbx
  ANTLR3_STACK_struct *v6; // rcx
  UELParser_logicalExpression_return_struct *v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rdi
  ANTLR3_COMMON_TOKEN_struct *v9; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v10; // ST38_8
  ANTLR3_STACK_struct *v11; // rcx
  __int64 v12; // rax
  ANTLR3_COMMON_TOKEN_struct *v13; // r9
  ANTLR3_COMMON_TOKEN_struct *v14; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v15; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v16; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v17; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v18; // rbx
  __int64 v19; // rax
  UELParser_logicalExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = v2->pParser->rec->state->following;
  v6->push(v6, &FOLLOW_logicalExpression_in_expression238, 0i64);
  v7 = logicalExpression(&resulta, v2);
  v8 = v7->tree;
  v9 = v7->start;
  v10 = v7->stop;
  v11 = v2->pParser->rec->state->following;
  v11->pop(v11);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v2->adaptor->addChild(v2->adaptor, (void *)v5, v8);
    v2->pParser->rec->match(v2->pParser->rec, 0xFFFFFFFF, &FOLLOW_EOF_in_expression240);
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v12 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v13 = v3->stop;
  v14 = v3->start;
  v15 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v12;
  v15->setTokenBoundaries(v15, (void *)v12, v14, v13);
  v16 = v2->pParser->rec;
  if ( v16->state->error == 1 )
  {
    v16->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v17 = v2->adaptor;
    v18 = v2->pParser->rec->state;
    v19 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v17->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v19,
                                            v18->exception);
  }
  return v3;
}

// File Line: 1437
// RVA: 0x249920
UELParser_logicalExpression_return_struct *__fastcall logicalExpression(UELParser_logicalExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_logicalExpression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rdi
  ANTLR3_BITSET_LIST_struct *v6; // rdx
  ANTLR3_STACK_struct *i; // r9
  UELParser_booleanAndExpression_return_struct *v8; // rax
  ANTLR3_BASE_TREE_struct *v9; // rsi
  ANTLR3_COMMON_TOKEN_struct *v10; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v11; // ST38_8
  ANTLR3_STACK_struct *v12; // rcx
  ANTLR3_INT_STREAM_struct *v13; // rcx
  unsigned int v14; // eax
  signed int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  ANTLR3_COMMON_TOKEN_struct *v20; // r9
  ANTLR3_COMMON_TOKEN_struct *v21; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v22; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v23; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v24; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v25; // rdi
  __int64 v26; // rax
  UELParser_booleanAndExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = &FOLLOW_booleanAndExpression_in_logicalExpression254;
  for ( i = v2->pParser->rec->state->following; ; i = v2->pParser->rec->state->following )
  {
    i->push(i, v6, 0i64);
    v8 = booleanAndExpression(&resulta, v2);
    v9 = v8->tree;
    v10 = v8->start;
    v11 = v8->stop;
    v12 = v2->pParser->rec->state->following;
    v12->pop(v12);
    if ( v2->pParser->rec->state->error == 1 )
      break;
    v2->adaptor->addChild(v2->adaptor, (void *)v5, v9);
    v13 = v2->pParser->tstream->istream;
    v14 = v13->_LA(v13, 1);
    v15 = 2;
    if ( v14 == 31 )
      v15 = 1;
    if ( v15 != 1 )
      break;
    v16 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 31u, &FOLLOW_OR_in_logicalExpression257);
    if ( v2->pParser->rec->state->error == 1 )
      break;
    v17 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v16);
    v18 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v17, (void *)v5);
    v6 = &FOLLOW_booleanAndExpression_in_logicalExpression260;
    v5 = v18;
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v19 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v20 = v3->stop;
  v21 = v3->start;
  v22 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v19;
  v22->setTokenBoundaries(v22, (void *)v19, v21, v20);
  v23 = v2->pParser->rec;
  if ( v23->state->error == 1 )
  {
    v23->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v24 = v2->adaptor;
    v25 = v2->pParser->rec->state;
    v26 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v24->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v26,
                                            v25->exception);
  }
  return v3;
}

// File Line: 1575
// RVA: 0x247C40
UELParser_booleanAndExpression_return_struct *__fastcall booleanAndExpression(UELParser_booleanAndExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_booleanAndExpression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rdi
  ANTLR3_BITSET_LIST_struct *v6; // rdx
  ANTLR3_STACK_struct *i; // r9
  UELParser_equalityExpression_return_struct *v8; // rax
  ANTLR3_BASE_TREE_struct *v9; // rsi
  ANTLR3_COMMON_TOKEN_struct *v10; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v11; // ST38_8
  ANTLR3_STACK_struct *v12; // rcx
  ANTLR3_INT_STREAM_struct *v13; // rcx
  unsigned int v14; // eax
  signed int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  ANTLR3_COMMON_TOKEN_struct *v20; // r9
  ANTLR3_COMMON_TOKEN_struct *v21; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v22; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v23; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v24; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v25; // rdi
  __int64 v26; // rax
  UELParser_equalityExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = &FOLLOW_equalityExpression_in_booleanAndExpression290;
  for ( i = v2->pParser->rec->state->following; ; i = v2->pParser->rec->state->following )
  {
    i->push(i, v6, 0i64);
    v8 = equalityExpression(&resulta, v2);
    v9 = v8->tree;
    v10 = v8->start;
    v11 = v8->stop;
    v12 = v2->pParser->rec->state->following;
    v12->pop(v12);
    if ( v2->pParser->rec->state->error == 1 )
      break;
    v2->adaptor->addChild(v2->adaptor, (void *)v5, v9);
    v13 = v2->pParser->tstream->istream;
    v14 = v13->_LA(v13, 1);
    v15 = 2;
    if ( v14 == 6 )
      v15 = 1;
    if ( v15 != 1 )
      break;
    v16 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 6u, &FOLLOW_AND_in_booleanAndExpression293);
    if ( v2->pParser->rec->state->error == 1 )
      break;
    v17 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v16);
    v18 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v17, (void *)v5);
    v6 = &FOLLOW_equalityExpression_in_booleanAndExpression297;
    v5 = v18;
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v19 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v20 = v3->stop;
  v21 = v3->start;
  v22 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v19;
  v22->setTokenBoundaries(v22, (void *)v19, v21, v20);
  v23 = v2->pParser->rec;
  if ( v23->state->error == 1 )
  {
    v23->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v24 = v2->adaptor;
    v25 = v2->pParser->rec->state;
    v26 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v24->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v26,
                                            v25->exception);
  }
  return v3;
}

// File Line: 1719
// RVA: 0x248170
UELParser_equalityExpression_return_struct *__fastcall equalityExpression(UELParser_equalityExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_equalityExpression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rsi
  ANTLR3_STACK_struct *v6; // rcx
  UELParser_relationalExpression_return_struct *v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rdi
  ANTLR3_COMMON_TOKEN_struct *v9; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v10; // ST38_8
  ANTLR3_STACK_struct *v11; // rcx
  ANTLR3_INT_STREAM_struct *v12; // rcx
  unsigned int v13; // eax
  signed int v14; // ecx
  __int64 v15; // rbp
  ANTLR3_INT_STREAM_struct *v16; // rcx
  ANTLR3_INT_STREAM_struct *v17; // rcx
  ANTLR3_INT_STREAM_struct *v18; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v19; // rdi
  __int64 v20; // rax
  ANTLR3_STACK_struct *v21; // rcx
  UELParser_relationalExpression_return_struct *v22; // rax
  ANTLR3_BASE_TREE_struct *v23; // rdi
  ANTLR3_COMMON_TOKEN_struct *v24; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v25; // ST38_8
  ANTLR3_STACK_struct *v26; // rcx
  __int64 v27; // rax
  ANTLR3_COMMON_TOKEN_struct *v28; // r9
  ANTLR3_COMMON_TOKEN_struct *v29; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v30; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v31; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v32; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v33; // rdi
  __int64 v34; // rax
  UELParser_relationalExpression_return_struct resulta; // [rsp+48h] [rbp-30h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = v2->pParser->rec->state->following;
  v6->push(v6, &FOLLOW_relationalExpression_in_equalityExpression326, 0i64);
  v7 = relationalExpression(&resulta, v2);
  v8 = v7->tree;
  v9 = v7->start;
  v10 = v7->stop;
  v11 = v2->pParser->rec->state->following;
  v11->pop(v11);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v2->adaptor->addChild(v2->adaptor, (void *)v5, v8);
    while ( 1 )
    {
      v12 = v2->pParser->tstream->istream;
      v13 = v12->_LA(v12, 1);
      v14 = 2;
      if ( !((v13 - 14) & 0xFFFFFFEF) )
        v14 = 1;
      if ( v14 != 1 )
        break;
      v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v15 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v16 = v2->pParser->tstream->istream;
      if ( v16->_LA(v16, 1) != 14 )
      {
        v17 = v2->pParser->tstream->istream;
        if ( v17->_LA(v17, 1) != 30 )
        {
          v2->pParser->rec->exConstruct(v2->pParser->rec);
          v2->pParser->rec->state->exception->type = 4;
          v2->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
          v2->pParser->rec->state->exception->expectingSet = 0i64;
          break;
        }
      }
      v18 = v2->pParser->tstream->istream;
      v18->consume(v18);
      v19 = v2->adaptor;
      v20 = (__int64)v19->create(v19, (ANTLR3_COMMON_TOKEN_struct *)v15);
      v5 = (__int64)v19->becomeRoot(v2->adaptor, (void *)v20, (void *)v5);
      v2->pParser->rec->state->errorRecovery = 0;
      v21 = v2->pParser->rec->state->following;
      v21->push(v21, &FOLLOW_relationalExpression_in_equalityExpression336, 0i64);
      v22 = relationalExpression(&resulta, v2);
      v23 = v22->tree;
      v24 = v22->start;
      v25 = v22->stop;
      v26 = v2->pParser->rec->state->following;
      v26->pop(v26);
      if ( v2->pParser->rec->state->error == 1 )
        break;
      v2->adaptor->addChild(v2->adaptor, (void *)v5, v23);
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v27 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v28 = v3->stop;
  v29 = v3->start;
  v30 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v27;
  v30->setTokenBoundaries(v30, (void *)v27, v29, v28);
  v31 = v2->pParser->rec;
  if ( v31->state->error == 1 )
  {
    v31->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v32 = v2->adaptor;
    v33 = v2->pParser->rec->state;
    v34 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v32->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v34,
                                            v33->exception);
  }
  return v3;
}

// File Line: 1869
// RVA: 0x24AA10
UELParser_relationalExpression_return_struct *__fastcall relationalExpression(UELParser_relationalExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_relationalExpression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rsi
  ANTLR3_STACK_struct *v6; // rcx
  UELParser_additiveExpression_return_struct *v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rdi
  ANTLR3_COMMON_TOKEN_struct *v9; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v10; // ST38_8
  ANTLR3_STACK_struct *v11; // rcx
  signed int v12; // edi
  ANTLR3_INT_STREAM_struct *v13; // rcx
  unsigned int v14; // eax
  __int64 v15; // rbp
  ANTLR3_INT_STREAM_struct *v16; // rcx
  ANTLR3_INT_STREAM_struct *v17; // rcx
  ANTLR3_INT_STREAM_struct *v18; // rcx
  ANTLR3_INT_STREAM_struct *v19; // rcx
  ANTLR3_INT_STREAM_struct *v20; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v21; // rdi
  __int64 v22; // rax
  ANTLR3_STACK_struct *v23; // rcx
  UELParser_additiveExpression_return_struct *v24; // rax
  ANTLR3_BASE_TREE_struct *v25; // rdi
  ANTLR3_COMMON_TOKEN_struct *v26; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v27; // ST38_8
  ANTLR3_STACK_struct *v28; // rcx
  __int64 v29; // rax
  ANTLR3_COMMON_TOKEN_struct *v30; // r9
  ANTLR3_COMMON_TOKEN_struct *v31; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v32; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v33; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v34; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v35; // rdi
  __int64 v36; // rax
  UELParser_additiveExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = v2->pParser->rec->state->following;
  v6->push(v6, &FOLLOW_additiveExpression_in_relationalExpression372, 0i64);
  v7 = additiveExpression(&resulta, v2);
  v8 = v7->tree;
  v9 = v7->start;
  v10 = v7->stop;
  v11 = v2->pParser->rec->state->following;
  v11->pop(v11);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v2->adaptor->addChild(v2->adaptor, (void *)v5, v8);
    while ( 1 )
    {
      v12 = 2;
      v13 = v2->pParser->tstream->istream;
      v14 = v13->_LA(v13, 1);
      if ( v14 >= 0x12 && (v14 <= 0x13 || v14 - 23 <= 1) )
        v12 = 1;
      if ( v12 != 1 )
        break;
      v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v15 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v16 = v2->pParser->tstream->istream;
      if ( v16->_LA(v16, 1) < 0x12 || (v17 = v2->pParser->tstream->istream, v17->_LA(v17, 1) > 0x13) )
      {
        v18 = v2->pParser->tstream->istream;
        if ( v18->_LA(v18, 1) < 0x17 || (v19 = v2->pParser->tstream->istream, v19->_LA(v19, 1) > 0x18) )
        {
          v2->pParser->rec->exConstruct(v2->pParser->rec);
          v2->pParser->rec->state->exception->type = 4;
          v2->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
          v2->pParser->rec->state->exception->expectingSet = 0i64;
          break;
        }
      }
      v20 = v2->pParser->tstream->istream;
      v20->consume(v20);
      v21 = v2->adaptor;
      v22 = (__int64)v21->create(v21, (ANTLR3_COMMON_TOKEN_struct *)v15);
      v5 = (__int64)v21->becomeRoot(v2->adaptor, (void *)v22, (void *)v5);
      v2->pParser->rec->state->errorRecovery = 0;
      v23 = v2->pParser->rec->state->following;
      v23->push(v23, &FOLLOW_additiveExpression_in_relationalExpression387, 0i64);
      v24 = additiveExpression(&resulta, v2);
      v25 = v24->tree;
      v26 = v24->start;
      v27 = v24->stop;
      v28 = v2->pParser->rec->state->following;
      v28->pop(v28);
      if ( v2->pParser->rec->state->error == 1 )
        break;
      v2->adaptor->addChild(v2->adaptor, (void *)v5, v25);
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v29 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v30 = v3->stop;
  v31 = v3->start;
  v32 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v29;
  v32->setTokenBoundaries(v32, (void *)v29, v31, v30);
  v33 = v2->pParser->rec;
  if ( v33->state->error == 1 )
  {
    v33->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v34 = v2->adaptor;
    v35 = v2->pParser->rec->state;
    v36 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v34->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v36,
                                            v35->exception);
  }
  return v3;
}

// File Line: 2021
// RVA: 0x247160
UELParser_additiveExpression_return_struct *__fastcall additiveExpression(UELParser_additiveExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_additiveExpression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rsi
  ANTLR3_STACK_struct *v6; // rcx
  UELParser_multiplicativeExpression_return_struct *v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rdi
  ANTLR3_COMMON_TOKEN_struct *v9; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v10; // ST38_8
  ANTLR3_STACK_struct *v11; // rcx
  signed int v12; // edi
  ANTLR3_INT_STREAM_struct *v13; // rcx
  unsigned int v14; // eax
  __int64 v15; // rbp
  ANTLR3_INT_STREAM_struct *v16; // rcx
  ANTLR3_INT_STREAM_struct *v17; // rcx
  ANTLR3_INT_STREAM_struct *v18; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v19; // rdi
  __int64 v20; // rax
  ANTLR3_STACK_struct *v21; // rcx
  UELParser_multiplicativeExpression_return_struct *v22; // rax
  ANTLR3_BASE_TREE_struct *v23; // rdi
  ANTLR3_COMMON_TOKEN_struct *v24; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v25; // ST38_8
  ANTLR3_STACK_struct *v26; // rcx
  __int64 v27; // rax
  ANTLR3_COMMON_TOKEN_struct *v28; // r9
  ANTLR3_COMMON_TOKEN_struct *v29; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v30; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v31; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v32; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v33; // rdi
  __int64 v34; // rax
  UELParser_multiplicativeExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = v2->pParser->rec->state->following;
  v6->push(v6, &FOLLOW_multiplicativeExpression_in_additiveExpression430, 0i64);
  v7 = multiplicativeExpression(&resulta, v2);
  v8 = v7->tree;
  v9 = v7->start;
  v10 = v7->stop;
  v11 = v2->pParser->rec->state->following;
  v11->pop(v11);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v2->adaptor->addChild(v2->adaptor, (void *)v5, v8);
    while ( 1 )
    {
      v12 = 2;
      v13 = v2->pParser->tstream->istream;
      v14 = v13->_LA(v13, 1);
      if ( v14 == 25 || v14 == 34 )
        v12 = 1;
      if ( v12 != 1 )
        break;
      v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v15 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v16 = v2->pParser->tstream->istream;
      if ( v16->_LA(v16, 1) != 25 )
      {
        v17 = v2->pParser->tstream->istream;
        if ( v17->_LA(v17, 1) != 34 )
        {
          v2->pParser->rec->exConstruct(v2->pParser->rec);
          v2->pParser->rec->state->exception->type = 4;
          v2->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
          v2->pParser->rec->state->exception->expectingSet = 0i64;
          break;
        }
      }
      v18 = v2->pParser->tstream->istream;
      v18->consume(v18);
      v19 = v2->adaptor;
      v20 = (__int64)v19->create(v19, (ANTLR3_COMMON_TOKEN_struct *)v15);
      v5 = (__int64)v19->becomeRoot(v2->adaptor, (void *)v20, (void *)v5);
      v2->pParser->rec->state->errorRecovery = 0;
      v21 = v2->pParser->rec->state->following;
      v21->push(v21, &FOLLOW_multiplicativeExpression_in_additiveExpression441, 0i64);
      v22 = multiplicativeExpression(&resulta, v2);
      v23 = v22->tree;
      v24 = v22->start;
      v25 = v22->stop;
      v26 = v2->pParser->rec->state->following;
      v26->pop(v26);
      if ( v2->pParser->rec->state->error == 1 )
        break;
      v2->adaptor->addChild(v2->adaptor, (void *)v5, v23);
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v27 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v28 = v3->stop;
  v29 = v3->start;
  v30 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v27;
  v30->setTokenBoundaries(v30, (void *)v27, v29, v28);
  v31 = v2->pParser->rec;
  if ( v31->state->error == 1 )
  {
    v31->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v32 = v2->adaptor;
    v33 = v2->pParser->rec->state;
    v34 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v32->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v34,
                                            v33->exception);
  }
  return v3;
}

// File Line: 2171
// RVA: 0x249B70
UELParser_multiplicativeExpression_return_struct *__fastcall multiplicativeExpression(UELParser_multiplicativeExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_multiplicativeExpression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rsi
  ANTLR3_STACK_struct *v6; // rcx
  UELParser_unaryExpression_return_struct *v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rdi
  ANTLR3_COMMON_TOKEN_struct *v9; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v10; // ST38_8
  ANTLR3_STACK_struct *v11; // rcx
  signed int v12; // edi
  ANTLR3_INT_STREAM_struct *v13; // rcx
  unsigned int v14; // eax
  __int64 v15; // rbp
  ANTLR3_INT_STREAM_struct *v16; // rcx
  ANTLR3_INT_STREAM_struct *v17; // rcx
  ANTLR3_INT_STREAM_struct *v18; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v19; // rdi
  __int64 v20; // rax
  ANTLR3_STACK_struct *v21; // rcx
  UELParser_unaryExpression_return_struct *v22; // rax
  ANTLR3_BASE_TREE_struct *v23; // rdi
  ANTLR3_COMMON_TOKEN_struct *v24; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v25; // ST38_8
  ANTLR3_STACK_struct *v26; // rcx
  __int64 v27; // rax
  ANTLR3_COMMON_TOKEN_struct *v28; // r9
  ANTLR3_COMMON_TOKEN_struct *v29; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v30; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v31; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v32; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v33; // rdi
  __int64 v34; // rax
  UELParser_unaryExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = v2->pParser->rec->state->following;
  v6->push(v6, &FOLLOW_unaryExpression_in_multiplicativeExpression471, 0i64);
  v7 = unaryExpression(&resulta, v2);
  v8 = v7->tree;
  v9 = v7->start;
  v10 = v7->stop;
  v11 = v2->pParser->rec->state->following;
  v11->pop(v11);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v2->adaptor->addChild(v2->adaptor, (void *)v5, v8);
    while ( 1 )
    {
      v12 = 2;
      v13 = v2->pParser->tstream->istream;
      v14 = v13->_LA(v13, 1);
      if ( v14 == 12 || v14 == 27 )
        v12 = 1;
      if ( v12 != 1 )
        break;
      v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v15 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v16 = v2->pParser->tstream->istream;
      if ( v16->_LA(v16, 1) != 12 )
      {
        v17 = v2->pParser->tstream->istream;
        if ( v17->_LA(v17, 1) != 27 )
        {
          v2->pParser->rec->exConstruct(v2->pParser->rec);
          v2->pParser->rec->state->exception->type = 4;
          v2->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
          v2->pParser->rec->state->exception->expectingSet = 0i64;
          break;
        }
      }
      v18 = v2->pParser->tstream->istream;
      v18->consume(v18);
      v19 = v2->adaptor;
      v20 = (__int64)v19->create(v19, (ANTLR3_COMMON_TOKEN_struct *)v15);
      v5 = (__int64)v19->becomeRoot(v2->adaptor, (void *)v20, (void *)v5);
      v2->pParser->rec->state->errorRecovery = 0;
      v21 = v2->pParser->rec->state->following;
      v21->push(v21, &FOLLOW_unaryExpression_in_multiplicativeExpression482, 0i64);
      v22 = unaryExpression(&resulta, v2);
      v23 = v22->tree;
      v24 = v22->start;
      v25 = v22->stop;
      v26 = v2->pParser->rec->state->following;
      v26->pop(v26);
      if ( v2->pParser->rec->state->error == 1 )
        break;
      v2->adaptor->addChild(v2->adaptor, (void *)v5, v23);
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v27 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v28 = v3->stop;
  v29 = v3->start;
  v30 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v27;
  v30->setTokenBoundaries(v30, (void *)v27, v29, v28);
  v31 = v2->pParser->rec;
  if ( v31->state->error == 1 )
  {
    v31->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v32 = v2->adaptor;
    v33 = v2->pParser->rec->state;
    v34 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v32->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v34,
                                            v33->exception);
  }
  return v3;
}

// File Line: 2321
// RVA: 0x24ADB0
UELParser_unaryExpression_return_struct *__fastcall unaryExpression(UELParser_unaryExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_unaryExpression_return_struct *v3; // r14
  signed int v4; // ebx
  __int64 v5; // rbp
  ANTLR3_COMMON_TOKEN_struct *v6; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v7; // r15
  ANTLR3_TOKEN_STREAM_struct *v8; // rcx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v9; // r12
  int v10; // ebx
  int v11; // ebx
  __int64 v12; // rbx
  ANTLR3_BASE_RECOGNIZER_struct *v13; // rdx
  ANTLR3_STACK_struct *v14; // rcx
  UELParser_referenceExpression_return_struct *v15; // rax
  ANTLR3_BASE_TREE_struct *v16; // rbx
  ANTLR3_COMMON_TOKEN_struct *v17; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v18; // ST38_8
  ANTLR3_STACK_struct *v19; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v20; // rdx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v21; // r13
  __int64 v22; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rcx
  __int64 v24; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v25; // rdi
  __int64 v26; // rbx
  __int64 v27; // rax
  __int64 v28; // rbx
  __int64 v29; // rax
  __int64 v30; // rax
  __int64 v31; // rax
  ANTLR3_STACK_struct *v32; // rcx
  UELParser_referenceExpression_return_struct *v33; // rcx
  ANTLR3_STACK_struct *v34; // rcx
  UELParser_referenceExpression_return_struct *v35; // rax
  ANTLR3_BASE_TREE_struct *v36; // rbx
  ANTLR3_COMMON_TOKEN_struct *v37; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v38; // ST38_8
  ANTLR3_STACK_struct *v39; // rcx
  __int64 v40; // rax
  ANTLR3_COMMON_TOKEN_struct *v41; // r9
  ANTLR3_COMMON_TOKEN_struct *v42; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v43; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v44; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v45; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v46; // rbx
  __int64 v47; // rax
  UELParser_referenceExpression_return_struct resulta; // [rsp+48h] [rbp-70h]
  char v50; // [rsp+60h] [rbp-58h]
  UELParser_referenceExpression_return_struct v51; // [rsp+78h] [rbp-40h]

  v2 = ctx;
  v3 = result;
  v4 = 1;
  v5 = 0i64;
  v6 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v7 = 0i64;
  v3->start = v6;
  v3->stop = v6;
  v8 = v2->pParser->tstream;
  v9 = 0i64;
  v3->tree = 0i64;
  switch ( v8->istream->_LA(v8->istream, 1) )
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
            v12 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 25u, &FOLLOW_MINUS_in_unaryExpression533);
            v13 = v2->pParser->rec;
            if ( v13->state->error != 1 )
            {
              v7 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v13, "token MINUS");
              v7->add(v7, (void *)v12, 0i64);
              v14 = v2->pParser->rec->state->following;
              v14->push(v14, &FOLLOW_referenceExpression_in_unaryExpression535, 0i64);
              v15 = referenceExpression(&resulta, v2);
              v16 = v15->tree;
              v17 = v15->start;
              v18 = v15->stop;
              v19 = v2->pParser->rec->state->following;
              v19->pop(v19);
              v20 = v2->pParser->rec;
              if ( v20->state->error != 1 )
              {
                v9 = antlr3RewriteRuleSubtreeStreamNewAE(v2->adaptor, v20, "rule referenceExpression");
                v9->add(v9, v16, 0i64);
                v21 = antlr3RewriteRuleSubtreeStreamNewAEE(v2->adaptor, v2->pParser->rec, "token retval", v3->tree);
                v22 = (__int64)v2->adaptor->nilNode(v2->adaptor);
                v23 = v2->adaptor;
                v5 = v22;
                v3->tree = (ANTLR3_BASE_TREE_struct *)v22;
                v24 = (__int64)v23->nilNode(v23);
                v25 = v2->adaptor;
                v26 = v24;
                v27 = (__int64)v25->createTypeText(v25, 28u, "NEGATE");
                v28 = (__int64)v25->becomeRoot(v2->adaptor, (void *)v27, (void *)v26);
                v29 = (__int64)v9->nextTree(v9);
                v2->adaptor->addChild(v2->adaptor, (void *)v28, (void *)v29);
                v2->adaptor->addChild(v2->adaptor, (void *)v5, (void *)v28);
                v3->tree = (ANTLR3_BASE_TREE_struct *)v5;
                if ( v21 )
                  v21->free(v21);
              }
            }
          }
          goto $ruleunaryExpressionEx;
        }
        v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
        v30 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 29u, &FOLLOW_NOT_in_unaryExpression521);
        if ( v2->pParser->rec->state->error == 1 )
          goto $ruleunaryExpressionEx;
        v31 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v30);
        v5 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v31, (void *)v5);
        v32 = v2->pParser->rec->state->following;
        v32->push(v32, &FOLLOW_referenceExpression_in_unaryExpression524, 0i64);
        v33 = (UELParser_referenceExpression_return_struct *)&v50;
      }
      else
      {
        v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
        v34 = v2->pParser->rec->state->following;
        v34->push(v34, &FOLLOW_referenceExpression_in_unaryExpression512, 0i64);
        v33 = &v51;
      }
      v35 = referenceExpression(v33, v2);
      v36 = v35->tree;
      v37 = v35->start;
      v38 = v35->stop;
      v39 = v2->pParser->rec->state->following;
      v39->pop(v39);
      if ( v2->pParser->rec->state->error != 1 )
        v2->adaptor->addChild(v2->adaptor, (void *)v5, v36);
$ruleunaryExpressionEx:
      v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
      v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
      v40 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
      v41 = v3->stop;
      v42 = v3->start;
      v43 = v2->adaptor;
      v3->tree = (ANTLR3_BASE_TREE_struct *)v40;
      v43->setTokenBoundaries(v43, (void *)v40, v42, v41);
      if ( v7 )
        v7->free(v7);
      if ( v9 )
        v9->free(v9);
      v44 = v2->pParser->rec;
      if ( v44->state->error == 1 )
      {
        v44->reportError(v2->pParser->rec);
        v2->pParser->rec->recover(v2->pParser->rec);
        v45 = v2->adaptor;
        v46 = v2->pParser->rec->state;
        v47 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
        v3->tree = (ANTLR3_BASE_TREE_struct *)v45->errorNode(
                                                v2->adaptor,
                                                v2->pParser->tstream,
                                                v3->start,
                                                (ANTLR3_COMMON_TOKEN_struct *)v47,
                                                v46->exception);
      }
      return v3;
    default:
      v2->pParser->rec->exConstruct(v2->pParser->rec);
      v2->pParser->rec->state->exception->type = 3;
      v2->pParser->rec->state->exception->message = &customWorldMapCaption;
      v2->pParser->rec->state->exception->decisionNum = 12;
      v2->pParser->rec->state->exception->state = 0;
      goto $ruleunaryExpressionEx;
  }
}

// File Line: 2568
// RVA: 0x24A7C0
UELParser_referenceExpression_return_struct *__fastcall referenceExpression(UELParser_referenceExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_referenceExpression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rdi
  ANTLR3_BITSET_LIST_struct *v6; // rdx
  ANTLR3_STACK_struct *i; // r9
  UELParser_indexedExpression_return_struct *v8; // rax
  ANTLR3_BASE_TREE_struct *v9; // rsi
  ANTLR3_COMMON_TOKEN_struct *v10; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v11; // ST38_8
  ANTLR3_STACK_struct *v12; // rcx
  ANTLR3_INT_STREAM_struct *v13; // rcx
  unsigned int v14; // eax
  signed int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  ANTLR3_COMMON_TOKEN_struct *v20; // r9
  ANTLR3_COMMON_TOKEN_struct *v21; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v22; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v23; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v24; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v25; // rdi
  __int64 v26; // rax
  UELParser_indexedExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = &FOLLOW_indexedExpression_in_referenceExpression567;
  for ( i = v2->pParser->rec->state->following; ; i = v2->pParser->rec->state->following )
  {
    i->push(i, v6, 0i64);
    v8 = indexedExpression(&resulta, v2);
    v9 = v8->tree;
    v10 = v8->start;
    v11 = v8->stop;
    v12 = v2->pParser->rec->state->following;
    v12->pop(v12);
    if ( v2->pParser->rec->state->error == 1 )
      break;
    v2->adaptor->addChild(v2->adaptor, (void *)v5, v9);
    v13 = v2->pParser->tstream->istream;
    v14 = v13->_LA(v13, 1);
    v15 = 2;
    if ( v14 == 36 )
      v15 = 1;
    if ( v15 != 1 )
      break;
    v16 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 36u, &FOLLOW_REFERENCE_in_referenceExpression570);
    if ( v2->pParser->rec->state->error == 1 )
      break;
    v17 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v16);
    v18 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v17, (void *)v5);
    v6 = &FOLLOW_indexedExpression_in_referenceExpression573;
    v5 = v18;
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v19 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v20 = v3->stop;
  v21 = v3->start;
  v22 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v19;
  v22->setTokenBoundaries(v22, (void *)v19, v21, v20);
  v23 = v2->pParser->rec;
  if ( v23->state->error == 1 )
  {
    v23->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v24 = v2->adaptor;
    v25 = v2->pParser->rec->state;
    v26 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v24->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v26,
                                            v25->exception);
  }
  return v3;
}

// File Line: 2706
// RVA: 0x2496D0
UELParser_indexedExpression_return_struct *__fastcall indexedExpression(UELParser_indexedExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_indexedExpression_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rdi
  ANTLR3_STACK_struct *v6; // rcx
  UELParser_primaryExpression_return_struct *v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rbx
  ANTLR3_COMMON_TOKEN_struct *v9; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v10; // ST38_8
  ANTLR3_STACK_struct *v11; // rcx
  __int64 v12; // rax
  signed int v13; // ebx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_STACK_struct *v15; // rcx
  UELParser_arrayIndex_return_struct *v16; // rax
  ANTLR3_BASE_TREE_struct *v17; // rbx
  ANTLR3_COMMON_TOKEN_struct *v18; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v19; // ST38_8
  ANTLR3_STACK_struct *v20; // rcx
  __int64 v21; // rax
  ANTLR3_COMMON_TOKEN_struct *v22; // r9
  ANTLR3_COMMON_TOKEN_struct *v23; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v24; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v25; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v26; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v27; // rbx
  __int64 v28; // rax
  UELParser_primaryExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v6 = v2->pParser->rec->state->following;
  v6->push(v6, &FOLLOW_primaryExpression_in_indexedExpression596, 0i64);
  v7 = primaryExpression(&resulta, v2);
  v8 = v7->tree;
  v9 = v7->start;
  v10 = v7->stop;
  v11 = v2->pParser->rec->state->following;
  v11->pop(v11);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v12 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, v8, (void *)v5);
    v13 = 2;
    v5 = v12;
    v14 = v2->pParser->tstream->istream;
    if ( v14->_LA(v14, 1) == 47 )
      v13 = 1;
    if ( v13 == 1 )
    {
      v15 = v2->pParser->rec->state->following;
      v15->push(v15, &FOLLOW_arrayIndex_in_indexedExpression600, 0i64);
      v16 = arrayIndex((UELParser_arrayIndex_return_struct *)&resulta, v2);
      v17 = v16->tree;
      v18 = v16->start;
      v19 = v16->stop;
      v20 = v2->pParser->rec->state->following;
      v20->pop(v20);
      if ( v2->pParser->rec->state->error != 1 )
        v2->adaptor->addChild(v2->adaptor, (void *)v5, v17);
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v21 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v22 = v3->stop;
  v23 = v3->start;
  v24 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v21;
  v24->setTokenBoundaries(v24, (void *)v21, v23, v22);
  v25 = v2->pParser->rec;
  if ( v25->state->error == 1 )
  {
    v25->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v26 = v2->adaptor;
    v27 = v2->pParser->rec->state;
    v28 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v26->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v28,
                                            v27->exception);
  }
  return v3;
}

// File Line: 2820
// RVA: 0x247A50
UELParser_arrayIndex_return_struct *__fastcall arrayIndex(UELParser_arrayIndex_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_arrayIndex_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  __int64 v5; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v6; // r9
  UELParser_logicalExpression_return_struct *v7; // rax
  ANTLR3_BASE_TREE_struct *v8; // rdi
  ANTLR3_COMMON_TOKEN_struct *v9; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v10; // ST38_8
  ANTLR3_STACK_struct *v11; // rcx
  __int64 v12; // rax
  ANTLR3_COMMON_TOKEN_struct *v13; // r9
  ANTLR3_COMMON_TOKEN_struct *v14; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v15; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v16; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v17; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v18; // rbx
  __int64 v19; // rax
  UELParser_logicalExpression_return_struct resulta; // [rsp+48h] [rbp-20h]

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v4;
  v3->stop = v4;
  v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
  v2->pParser->rec->match(v2->pParser->rec, 47u, &FOLLOW_47_in_arrayIndex614);
  v6 = v2->pParser->rec->state;
  if ( v6->error != 1 )
  {
    v6->following->push(v6->following, &FOLLOW_logicalExpression_in_arrayIndex617, 0i64);
    v7 = logicalExpression(&resulta, v2);
    v8 = v7->tree;
    v9 = v7->start;
    v10 = v7->stop;
    v11 = v2->pParser->rec->state->following;
    v11->pop(v11);
    if ( v2->pParser->rec->state->error != 1 )
    {
      v2->adaptor->addChild(v2->adaptor, (void *)v5, v8);
      v2->pParser->rec->match(v2->pParser->rec, 48u, &FOLLOW_48_in_arrayIndex619);
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v12 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v13 = v3->stop;
  v14 = v3->start;
  v15 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v12;
  v15->setTokenBoundaries(v15, (void *)v12, v14, v13);
  v16 = v2->pParser->rec;
  if ( v16->state->error == 1 )
  {
    v16->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v17 = v2->adaptor;
    v18 = v2->pParser->rec->state;
    v19 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v17->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v19,
                                            v18->exception);
  }
  return v3;
}

// File Line: 2916
// RVA: 0x249ED0
UELParser_primaryExpression_return_struct *__fastcall primaryExpression(UELParser_primaryExpression_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_primaryExpression_return_struct *v3; // r14
  signed int v4; // ebx
  __int64 v5; // r15
  ANTLR3_COMMON_TOKEN_struct *v6; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v7; // r13
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v8; // rdi
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v9; // r12
  ANTLR3_INT_STREAM_struct *v10; // rcx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v11; // rbp
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  ANTLR3_STACK_struct *v15; // rcx
  UELParser_value_return_struct *v16; // rax
  ANTLR3_BASE_TREE_struct *v17; // rbx
  ANTLR3_COMMON_TOKEN_struct *v18; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v19; // ST38_8
  ANTLR3_STACK_struct *v20; // rcx
  __int64 v21; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v22; // rdx
  void *v23; // rbx
  ANTLR3_STACK_struct *v24; // rcx
  UELParser_logicalExpression_return_struct *v25; // rax
  ANTLR3_BASE_TREE_struct *v26; // rbx
  ANTLR3_COMMON_TOKEN_struct *v27; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v28; // ST38_8
  ANTLR3_STACK_struct *v29; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v30; // rdx
  __int64 v31; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v32; // rdx
  void *v33; // rbx
  __int64 v34; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v35; // rcx
  __int64 v36; // rax
  const char *v37; // r8
  signed __int64 v38; // rdx
  __int64 v39; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v40; // rdx
  void *v41; // rbx
  ANTLR3_STACK_struct *v42; // rcx
  UELParser_logicalExpression_return_struct *v43; // rax
  ANTLR3_BASE_TREE_struct *v44; // rbx
  ANTLR3_COMMON_TOKEN_struct *v45; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v46; // ST38_8
  ANTLR3_STACK_struct *v47; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v48; // rdx
  __int64 v49; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v50; // rdx
  void *v51; // rbx
  __int64 v52; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v53; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v54; // rdi
  __int64 v55; // rbx
  __int64 v56; // rax
  __int64 v57; // rbx
  __int64 v58; // rax
  __int64 v59; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v60; // rdx
  void *v61; // rbx
  ANTLR3_STACK_struct *v62; // rcx
  UELParser_logicalExpression_return_struct *v63; // rax
  ANTLR3_BASE_TREE_struct *v64; // rbx
  ANTLR3_COMMON_TOKEN_struct *v65; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v66; // ST38_8
  ANTLR3_STACK_struct *v67; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v68; // rdx
  __int64 v69; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v70; // rdx
  void *v71; // rbx
  __int64 v72; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v73; // rcx
  __int64 v74; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v75; // rdi
  __int64 v76; // rbx
  __int64 v77; // rax
  __int64 v78; // rbx
  __int64 v79; // rax
  __int64 v80; // rax
  ANTLR3_COMMON_TOKEN_struct *v81; // r9
  ANTLR3_COMMON_TOKEN_struct *v82; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v83; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v84; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v85; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v86; // rbx
  __int64 v87; // rax
  UELParser_logicalExpression_return_struct v89; // [rsp+48h] [rbp-B0h]
  UELParser_logicalExpression_return_struct v90; // [rsp+60h] [rbp-98h]
  UELParser_value_return_struct resulta; // [rsp+78h] [rbp-80h]
  UELParser_logicalExpression_return_struct v92; // [rsp+90h] [rbp-68h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v93; // [rsp+100h] [rbp+8h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v94; // [rsp+108h] [rbp+10h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v95; // [rsp+110h] [rbp+18h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v96; // [rsp+118h] [rbp+20h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v97; // [rsp+118h] [rbp+20h]

  v2 = ctx;
  v3 = result;
  v4 = 1;
  v5 = 0i64;
  v6 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v94 = 0i64;
  v3->start = v6;
  v3->stop = v6;
  v95 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = v2->pParser->tstream->istream;
  v11 = 0i64;
  v3->tree = 0i64;
  switch ( v10->_LA(v10, 1) )
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
              v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
              v15 = v2->pParser->rec->state->following;
              v15->push(v15, &FOLLOW_value_in_primaryExpression689, 0i64);
              v16 = value(&resulta, v2);
              v17 = v16->tree;
              v18 = v16->start;
              v19 = v16->stop;
              v20 = v2->pParser->rec->state->following;
              v20->pop(v20);
              if ( v2->pParser->rec->state->error != 1 )
                v2->adaptor->addChild(v2->adaptor, (void *)v5, v17);
            }
            goto $ruleprimaryExpressionEx;
          }
          v21 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 50u, &FOLLOW_50_in_primaryExpression670);
          v22 = v2->pParser->rec;
          v23 = (void *)v21;
          if ( v22->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v9 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v22, "token 50");
          v9->add(v9, v23, 0i64);
          v24 = v2->pParser->rec->state->following;
          v24->push(v24, &FOLLOW_logicalExpression_in_primaryExpression672, 0i64);
          v25 = logicalExpression(&v89, v2);
          v26 = v25->tree;
          v27 = v25->start;
          v28 = v25->stop;
          v29 = v2->pParser->rec->state->following;
          v29->pop(v29);
          v30 = v2->pParser->rec;
          if ( v30->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v11 = antlr3RewriteRuleSubtreeStreamNewAE(v2->adaptor, v30, "rule logicalExpression");
          v11->add(v11, v26, 0i64);
          v31 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 51u, &FOLLOW_51_in_primaryExpression674);
          v32 = v2->pParser->rec;
          v33 = (void *)v31;
          if ( v32->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v93 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v32, "token 51");
          v93->add(v93, v33, 0i64);
          v96 = antlr3RewriteRuleSubtreeStreamNewAEE(v2->adaptor, v2->pParser->rec, "token retval", v3->tree);
          v34 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v35 = v2->adaptor;
          v5 = v34;
          v3->tree = (ANTLR3_BASE_TREE_struct *)v34;
          v36 = (__int64)v35->nilNode(v35);
          v37 = "DEBUG_THIS_RECURSIVELY";
          v38 = 10i64;
        }
        else
        {
          v39 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 49u, &FOLLOW_49_in_primaryExpression651);
          v40 = v2->pParser->rec;
          v41 = (void *)v39;
          if ( v40->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v94 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v40, "token 49");
          v94->add(v94, v41, 0i64);
          v42 = v2->pParser->rec->state->following;
          v42->push(v42, &FOLLOW_logicalExpression_in_primaryExpression653, 0i64);
          v43 = logicalExpression(&v90, v2);
          v44 = v43->tree;
          v45 = v43->start;
          v46 = v43->stop;
          v47 = v2->pParser->rec->state->following;
          v47->pop(v47);
          v48 = v2->pParser->rec;
          if ( v48->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v11 = antlr3RewriteRuleSubtreeStreamNewAE(v2->adaptor, v48, "rule logicalExpression");
          v11->add(v11, v44, 0i64);
          v49 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 51u, &FOLLOW_51_in_primaryExpression655);
          v50 = v2->pParser->rec;
          v51 = (void *)v49;
          if ( v50->state->error == 1 )
            goto $ruleprimaryExpressionEx;
          v93 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v50, "token 51");
          v93->add(v93, v51, 0i64);
          v96 = antlr3RewriteRuleSubtreeStreamNewAEE(v2->adaptor, v2->pParser->rec, "token retval", v3->tree);
          v52 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v53 = v2->adaptor;
          v5 = v52;
          v3->tree = (ANTLR3_BASE_TREE_struct *)v52;
          v36 = (__int64)v53->nilNode(v53);
          v37 = "DEBUG_THIS";
          v38 = 9i64;
        }
        v54 = v2->adaptor;
        v55 = v36;
        v56 = (__int64)v54->createTypeText(v54, v38, (char *)v37);
        v57 = (__int64)v54->becomeRoot(v2->adaptor, (void *)v56, (void *)v55);
        v58 = (__int64)v11->nextTree(v11);
        v2->adaptor->addChild(v2->adaptor, (void *)v57, (void *)v58);
        v2->adaptor->addChild(v2->adaptor, (void *)v5, (void *)v57);
        v3->tree = (ANTLR3_BASE_TREE_struct *)v5;
        if ( v96 )
          v96->free(v96);
        v8 = v93;
      }
      else
      {
        v59 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 44u, &FOLLOW_44_in_primaryExpression631);
        v60 = v2->pParser->rec;
        v61 = (void *)v59;
        if ( v60->state->error != 1 )
        {
          v7 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v60, "token 44");
          v7->add(v7, v61, 0i64);
          v62 = v2->pParser->rec->state->following;
          v62->push(v62, &FOLLOW_logicalExpression_in_primaryExpression633, 0i64);
          v63 = logicalExpression(&v92, v2);
          v64 = v63->tree;
          v65 = v63->start;
          v66 = v63->stop;
          v67 = v2->pParser->rec->state->following;
          v67->pop(v67);
          v68 = v2->pParser->rec;
          if ( v68->state->error != 1 )
          {
            v11 = antlr3RewriteRuleSubtreeStreamNewAE(v2->adaptor, v68, "rule logicalExpression");
            v11->add(v11, v64, 0i64);
            v69 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 45u, &FOLLOW_45_in_primaryExpression635);
            v70 = v2->pParser->rec;
            v71 = (void *)v69;
            if ( v70->state->error != 1 )
            {
              v95 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v70, "token 45");
              v95->add(v95, v71, 0i64);
              v97 = antlr3RewriteRuleSubtreeStreamNewAEE(v2->adaptor, v2->pParser->rec, "token retval", v3->tree);
              v72 = (__int64)v2->adaptor->nilNode(v2->adaptor);
              v73 = v2->adaptor;
              v5 = v72;
              v3->tree = (ANTLR3_BASE_TREE_struct *)v72;
              v74 = (__int64)v73->nilNode(v73);
              v75 = v2->adaptor;
              v76 = v74;
              v77 = (__int64)v75->createTypeText(v75, 33u, "PARENTHESIZE");
              v78 = (__int64)v75->becomeRoot(v2->adaptor, (void *)v77, (void *)v76);
              v79 = (__int64)v11->nextTree(v11);
              v2->adaptor->addChild(v2->adaptor, (void *)v78, (void *)v79);
              v2->adaptor->addChild(v2->adaptor, (void *)v5, (void *)v78);
              v3->tree = (ANTLR3_BASE_TREE_struct *)v5;
              if ( v97 )
                v97->free(v97);
              v8 = 0i64;
            }
          }
        }
      }
$ruleprimaryExpressionEx:
      v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
      v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
      v80 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
      v81 = v3->stop;
      v82 = v3->start;
      v83 = v2->adaptor;
      v3->tree = (ANTLR3_BASE_TREE_struct *)v80;
      v83->setTokenBoundaries(v83, (void *)v80, v82, v81);
      if ( v94 )
        v94->free(v94);
      if ( v95 )
        v95->free(v95);
      if ( v7 )
        v7->free(v7);
      if ( v8 )
        v8->free(v8);
      if ( v9 )
        v9->free(v9);
      if ( v11 )
        v11->free(v11);
      v84 = v2->pParser->rec;
      if ( v84->state->error == 1 )
      {
        v84->reportError(v2->pParser->rec);
        v2->pParser->rec->recover(v2->pParser->rec);
        v85 = v2->adaptor;
        v86 = v2->pParser->rec->state;
        v87 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
        v3->tree = (ANTLR3_BASE_TREE_struct *)v85->errorNode(
                                                v2->adaptor,
                                                v2->pParser->tstream,
                                                v3->start,
                                                (ANTLR3_COMMON_TOKEN_struct *)v87,
                                                v86->exception);
      }
      return v3;
    default:
      v2->pParser->rec->exConstruct(v2->pParser->rec);
      v2->pParser->rec->state->exception->type = 3;
      v2->pParser->rec->state->exception->message = &customWorldMapCaption;
      v2->pParser->rec->state->exception->decisionNum = 15;
      v2->pParser->rec->state->exception->state = 0;
      goto $ruleprimaryExpressionEx;
  }
}

// File Line: 3321
// RVA: 0x24B2D0
UELParser_value_return_struct *__fastcall value(UELParser_value_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_value_return_struct *v3; // r14
  signed int v4; // edi
  __int64 v5; // rbx
  ANTLR3_COMMON_TOKEN_struct *v6; // rax
  ANTLR3_INT_STREAM_struct *v7; // rcx
  __int64 v8; // rax
  ANTLR3_BITSET_LIST_struct *v9; // r8
  ANTLR3_BASE_RECOGNIZER_struct *v10; // r9
  signed __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  ANTLR3_STACK_struct *v18; // rcx
  UELParser_function_return_struct *v19; // rax
  ANTLR3_BASE_TREE_struct *v20; // rdi
  ANTLR3_COMMON_TOKEN_struct *v21; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v22; // ST38_8
  ANTLR3_STACK_struct *v23; // rcx
  ANTLR3_STACK_struct *v24; // rcx
  UELParser_enumeration_return_struct *v25; // rax
  ANTLR3_BASE_TREE_struct *v26; // rdi
  ANTLR3_COMMON_TOKEN_struct *v27; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v28; // ST38_8
  ANTLR3_STACK_struct *v29; // rcx
  __int64 v30; // rax
  ANTLR3_STACK_struct *v31; // rcx
  UELParser_argumentUsage_return_struct *v32; // rax
  ANTLR3_BASE_TREE_struct *v33; // rdi
  ANTLR3_COMMON_TOKEN_struct *v34; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v35; // ST38_8
  ANTLR3_STACK_struct *v36; // rcx
  ANTLR3_STACK_struct *v37; // rcx
  UELParser_fragmentUsage_return_struct *v38; // rax
  ANTLR3_BASE_TREE_struct *v39; // rdi
  ANTLR3_COMMON_TOKEN_struct *v40; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v41; // ST38_8
  ANTLR3_STACK_struct *v42; // rcx
  __int64 v43; // rax
  ANTLR3_COMMON_TOKEN_struct *v44; // r9
  ANTLR3_COMMON_TOKEN_struct *v45; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v46; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v47; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v48; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v49; // rbx
  __int64 v50; // rax
  UELParser_enumeration_return_struct v52; // [rsp+48h] [rbp-70h]
  UELParser_argumentUsage_return_struct v53; // [rsp+60h] [rbp-58h]
  UELParser_function_return_struct resulta; // [rsp+78h] [rbp-40h]
  UELParser_fragmentUsage_return_struct v55; // [rsp+90h] [rbp-28h]

  v2 = ctx;
  v3 = result;
  v4 = 1;
  v5 = 0i64;
  v6 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->tree = 0i64;
  v3->start = v6;
  v3->stop = v6;
  v7 = v2->pParser->tstream->istream;
  switch ( v7->_LA(v7, 1) )
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
          v8 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v9 = &FOLLOW_INTEGER_in_value703;
          v10 = v2->pParser->rec;
          v5 = v8;
          v11 = 21i64;
          goto LABEL_13;
        case 2:
          v14 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v9 = &FOLLOW_REAL_in_value709;
          v11 = 35i64;
          v5 = v14;
          v10 = v2->pParser->rec;
          goto LABEL_13;
        case 3:
          v15 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v9 = &FOLLOW_BOOLEAN_in_value715;
          v11 = 8i64;
          v5 = v15;
          v10 = v2->pParser->rec;
          goto LABEL_13;
        case 4:
          v16 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v9 = &FOLLOW_SYMBOL_in_value720;
          v11 = 40i64;
          v5 = v16;
          v10 = v2->pParser->rec;
          goto LABEL_13;
        case 5:
          v17 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v9 = &FOLLOW_STRING_in_value725;
          v11 = 39i64;
          v5 = v17;
          v10 = v2->pParser->rec;
          goto LABEL_13;
        case 6:
          v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v18 = v2->pParser->rec->state->following;
          v18->push(v18, &FOLLOW_function_in_value730, 0i64);
          v19 = function(&resulta, v2);
          v20 = v19->tree;
          v21 = v19->start;
          v22 = v19->stop;
          v23 = v2->pParser->rec->state->following;
          v23->pop(v23);
          if ( v2->pParser->rec->state->error != 1 )
            v2->adaptor->addChild(v2->adaptor, (void *)v5, v20);
          break;
        case 7:
          v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v24 = v2->pParser->rec->state->following;
          v24->push(v24, &FOLLOW_enumeration_in_value735, 0i64);
          v25 = enumeration(&v52, v2);
          v26 = v25->tree;
          v27 = v25->start;
          v28 = v25->stop;
          v29 = v2->pParser->rec->state->following;
          v29->pop(v29);
          if ( v2->pParser->rec->state->error != 1 )
            v2->adaptor->addChild(v2->adaptor, (void *)v5, v26);
          break;
        case 8:
          v30 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v9 = &FOLLOW_PARAMETER_in_value740;
          v11 = 32i64;
          v5 = v30;
          v10 = v2->pParser->rec;
LABEL_13:
          v12 = (__int64)v10->match(v10, v11, v9);
          if ( v2->pParser->rec->state->error != 1 )
          {
            v13 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v12);
            v2->adaptor->addChild(v2->adaptor, (void *)v5, (void *)v13);
          }
          break;
        case 9:
          v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v31 = v2->pParser->rec->state->following;
          v31->push(v31, &FOLLOW_argumentUsage_in_value745, 0i64);
          v32 = argumentUsage(&v53, v2);
          v33 = v32->tree;
          v34 = v32->start;
          v35 = v32->stop;
          v36 = v2->pParser->rec->state->following;
          v36->pop(v36);
          if ( v2->pParser->rec->state->error != 1 )
            v2->adaptor->addChild(v2->adaptor, (void *)v5, v33);
          break;
        case 10:
          v5 = (__int64)v2->adaptor->nilNode(v2->adaptor);
          v37 = v2->pParser->rec->state->following;
          v37->push(v37, &FOLLOW_fragmentUsage_in_value750, 0i64);
          v38 = fragmentUsage(&v55, v2);
          v39 = v38->tree;
          v40 = v38->start;
          v41 = v38->stop;
          v42 = v2->pParser->rec->state->following;
          v42->pop(v42);
          if ( v2->pParser->rec->state->error != 1 )
            v2->adaptor->addChild(v2->adaptor, (void *)v5, v39);
          break;
        default:
          goto $rulevalueEx;
      }
      break;
    default:
      v2->pParser->rec->exConstruct(v2->pParser->rec);
      v2->pParser->rec->state->exception->type = 3;
      v2->pParser->rec->state->exception->message = &customWorldMapCaption;
      v2->pParser->rec->state->exception->decisionNum = 16;
      v2->pParser->rec->state->exception->state = 0;
      break;
  }
$rulevalueEx:
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v43 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v5);
  v44 = v3->stop;
  v45 = v3->start;
  v46 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v43;
  v46->setTokenBoundaries(v46, (void *)v43, v45, v44);
  v47 = v2->pParser->rec;
  if ( v47->state->error == 1 )
  {
    v47->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v48 = v2->adaptor;
    v49 = v2->pParser->rec->state;
    v50 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v48->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v50,
                                            v49->exception);
  }
  return v3;
}Parser->tstream,
                                            v3->start,
            

// File Line: 3679
// RVA: 0x2474C0
UELParser_argumentDeclaration_return_struct *__fastcall argumentDeclaration(UELParser_argumentDeclaration_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_argumentDeclaration_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rcx
  __int64 v6; // rdi
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbp
  ANTLR3_INT_STREAM_struct *v12; // rcx
  ANTLR3_INT_STREAM_struct *v13; // rcx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v15; // rbx
  __int64 v16; // rax
  __int64 v17; // rax
  ANTLR3_COMMON_TOKEN_struct *v18; // r9
  ANTLR3_COMMON_TOKEN_struct *v19; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v20; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v21; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v22; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v23; // rbx
  __int64 v24; // rax

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->start = v4;
  v3->stop = v4;
  v5 = v2->adaptor;
  v3->tree = 0i64;
  v6 = (__int64)v5->nilNode(v5);
  v7 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 7u, &FOLLOW_ARGUMENT_in_argumentDeclaration780);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v8 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v7);
    v6 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v8, (void *)v6);
    v9 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 32u, &FOLLOW_PARAMETER_in_argumentDeclaration783);
    if ( v2->pParser->rec->state->error != 1 )
    {
      v10 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v9);
      v2->adaptor->addChild(v2->adaptor, (void *)v6, (void *)v10);
      v2->pParser->rec->match(v2->pParser->rec, 37u, &FOLLOW_SCOPE_in_argumentDeclaration785);
      if ( v2->pParser->rec->state->error != 1 )
      {
        v11 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
        v12 = v2->pParser->tstream->istream;
        if ( v12->_LA(v12, 1) == 13 || (v13 = v2->pParser->tstream->istream, v13->_LA(v13, 1) == 41) )
        {
          v14 = v2->pParser->tstream->istream;
          v14->consume(v14);
          v15 = v2->adaptor;
          v16 = (__int64)v15->create(v15, (ANTLR3_COMMON_TOKEN_struct *)v11);
          v15->addChild(v2->adaptor, (void *)v6, (void *)v16);
          v2->pParser->rec->state->errorRecovery = 0;
        }
        else
        {
          v2->pParser->rec->exConstruct(v2->pParser->rec);
          v2->pParser->rec->state->exception->type = 4;
          v2->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
          v2->pParser->rec->state->exception->expectingSet = 0i64;
        }
      }
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v17 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v6);
  v18 = v3->stop;
  v19 = v3->start;
  v20 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v17;
  v20->setTokenBoundaries(v20, (void *)v17, v19, v18);
  v21 = v2->pParser->rec;
  if ( v21->state->error == 1 )
  {
    v21->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v22 = v2->adaptor;
    v23 = v2->pParser->rec->state;
    v24 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v22->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v24,
                                            v23->exception);
  }
  return v3;
}

// File Line: 3804
// RVA: 0x2477B0
UELParser_argumentUsage_return_struct *__fastcall argumentUsage(UELParser_argumentUsage_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_argumentUsage_return_struct *v3; // r14
  ANTLR3_BASE_TREE_struct *v4; // r15
  ANTLR3_COMMON_TOKEN_struct *v5; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // rdi
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v7; // rbp
  ANTLR3_BASE_RECOGNIZER_struct *v8; // rcx
  __int64 v9; // rbx
  ANTLR3_BASE_RECOGNIZER_struct *v10; // rdx
  __int64 v11; // rbx
  ANTLR3_BASE_RECOGNIZER_struct *v12; // rdx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v13; // r12
  __int64 v14; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v15; // rcx
  __int64 v16; // rbx
  __int64 v17; // rax
  __int64 v18; // rbx
  __int64 v19; // rax
  __int64 v20; // rax
  ANTLR3_COMMON_TOKEN_struct *v21; // r9
  ANTLR3_COMMON_TOKEN_struct *v22; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v24; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v25; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v26; // rbx
  __int64 v27; // rax

  v2 = ctx;
  v3 = result;
  v4 = 0i64;
  v5 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->start = v5;
  v3->stop = v5;
  v6 = 0i64;
  v7 = 0i64;
  v8 = v2->pParser->rec;
  v3->tree = 0i64;
  v9 = (__int64)v8->match(v8, 7u, &FOLLOW_ARGUMENT_in_argumentUsage802);
  v10 = v2->pParser->rec;
  if ( v10->state->error != 1 )
  {
    v6 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v10, "token ARGUMENT");
    v6->add(v6, (void *)v9, 0i64);
    v11 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 32u, &FOLLOW_PARAMETER_in_argumentUsage804);
    v12 = v2->pParser->rec;
    if ( v12->state->error != 1 )
    {
      v7 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v12, "token PARAMETER");
      v7->add(v7, (void *)v11, 0i64);
      v13 = antlr3RewriteRuleSubtreeStreamNewAEE(v2->adaptor, v2->pParser->rec, "token retval", v3->tree);
      v14 = (__int64)v2->adaptor->nilNode(v2->adaptor);
      v15 = v2->adaptor;
      v4 = (ANTLR3_BASE_TREE_struct *)v14;
      v3->tree = (ANTLR3_BASE_TREE_struct *)v14;
      v16 = (__int64)v15->nilNode(v15);
      v17 = (__int64)v6->nextNode(v6);
      v18 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v17, (void *)v16);
      v19 = (__int64)v7->nextNode(v7);
      v2->adaptor->addChild(v2->adaptor, (void *)v18, (void *)v19);
      v2->adaptor->addChild(v2->adaptor, v4, (void *)v18);
      v3->tree = v4;
      if ( v13 )
        v13->free(v13);
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v20 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, v4);
  v21 = v3->stop;
  v22 = v3->start;
  v23 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v20;
  v23->setTokenBoundaries(v23, (void *)v20, v22, v21);
  if ( v6 )
    v6->free(v6);
  if ( v7 )
    v7->free(v7);
  v24 = v2->pParser->rec;
  if ( v24->state->error == 1 )
  {
    v24->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v25 = v2->adaptor;
    v26 = v2->pParser->rec->state;
    v27 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v25->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v27,
                                            v26->exception);
  }
  return v3;
}

// File Line: 3932
// RVA: 0x247E90
UELParser_enumeration_return_struct *__fastcall enumeration(UELParser_enumeration_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rsi
  UELParser_enumeration_return_struct *v3; // r14
  ANTLR3_COMMON_TOKEN_struct *v4; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v5; // rcx
  __int64 v6; // rdi
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbp
  ANTLR3_INT_STREAM_struct *v12; // rcx
  ANTLR3_INT_STREAM_struct *v13; // rcx
  ANTLR3_INT_STREAM_struct *v14; // rcx
  ANTLR3_INT_STREAM_struct *v15; // rcx
  ANTLR3_BASE_TREE_ADAPTOR_struct *v16; // rbx
  __int64 v17; // rax
  __int64 v18; // rax
  ANTLR3_COMMON_TOKEN_struct *v19; // r9
  ANTLR3_COMMON_TOKEN_struct *v20; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v21; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v22; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v23; // rdi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v24; // rbx
  __int64 v25; // rax

  v2 = ctx;
  v3 = result;
  v4 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->start = v4;
  v3->stop = v4;
  v5 = v2->adaptor;
  v3->tree = 0i64;
  v6 = (__int64)v5->nilNode(v5);
  v7 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 13u, &FOLLOW_ENUMERATION_in_enumeration833);
  if ( v2->pParser->rec->state->error != 1 )
  {
    v8 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v7);
    v2->adaptor->addChild(v2->adaptor, (void *)v6, (void *)v8);
    v9 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 37u, &FOLLOW_SCOPE_in_enumeration835);
    if ( v2->pParser->rec->state->error != 1 )
    {
      v10 = (__int64)v2->adaptor->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v9);
      v6 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v10, (void *)v6);
      v11 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, 1);
      v12 = v2->pParser->tstream->istream;
      if ( v12->_LA(v12, 1) == 13
        || (v13 = v2->pParser->tstream->istream, v13->_LA(v13, 1) == 17)
        || (v14 = v2->pParser->tstream->istream, v14->_LA(v14, 1) == 32) )
      {
        v15 = v2->pParser->tstream->istream;
        v15->consume(v15);
        v16 = v2->adaptor;
        v17 = (__int64)v16->create(v16, (ANTLR3_COMMON_TOKEN_struct *)v11);
        v16->addChild(v2->adaptor, (void *)v6, (void *)v17);
        v2->pParser->rec->state->errorRecovery = 0;
      }
      else
      {
        v2->pParser->rec->exConstruct(v2->pParser->rec);
        v2->pParser->rec->state->exception->type = 4;
        v2->pParser->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
        v2->pParser->rec->state->exception->expectingSet = 0i64;
      }
    }
  }
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v18 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, (void *)v6);
  v19 = v3->stop;
  v20 = v3->start;
  v21 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v18;
  v21->setTokenBoundaries(v21, (void *)v18, v20, v19);
  v22 = v2->pParser->rec;
  if ( v22->state->error == 1 )
  {
    v22->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v23 = v2->adaptor;
    v24 = v2->pParser->rec->state;
    v25 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v23->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v25,
                                            v24->exception);
  }
  return v3;
}

// File Line: 4046
// RVA: 0x249150
UELParser_function_return_struct *__fastcall function(UELParser_function_return_struct *result, UELParser_Ctx_struct *ctx)
{
  UELParser_Ctx_struct *v2; // rbx
  UELParser_function_return_struct *v3; // r14
  ANTLR3_BASE_TREE_struct *v4; // r15
  ANTLR3_COMMON_TOKEN_struct *v5; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // r12
  ANTLR3_BASE_RECOGNIZER_struct *v7; // rcx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v8; // r13
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v9; // rbp
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v10; // rsi
  __int64 v11; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v12; // rdx
  __int64 v13; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v14; // rdx
  signed int v15; // edi
  ANTLR3_INT_STREAM_struct *v16; // rcx
  ANTLR3_STACK_struct *v17; // rcx
  UELParser_logicalExpression_return_struct *v18; // rax
  ANTLR3_BASE_TREE_struct *v19; // rdi
  ANTLR3_COMMON_TOKEN_struct *v20; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v21; // ST38_8
  ANTLR3_STACK_struct *v22; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v23; // rdx
  ANTLR3_INT_STREAM_struct *v24; // rcx
  unsigned int v25; // eax
  signed int v26; // ecx
  __int64 v27; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v28; // rdx
  ANTLR3_STACK_struct *v29; // rcx
  UELParser_logicalExpression_return_struct *v30; // rax
  ANTLR3_BASE_TREE_struct *v31; // rdi
  ANTLR3_COMMON_TOKEN_struct *v32; // ST30_8
  ANTLR3_COMMON_TOKEN_struct *v33; // ST38_8
  ANTLR3_STACK_struct *v34; // rcx
  __int64 v35; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v36; // rdx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v37; // r12
  __int64 v38; // rax
  ANTLR3_BASE_TREE_ADAPTOR_struct *v39; // rcx
  __int64 v40; // rdi
  __int64 v41; // rax
  __int64 v42; // rdi
  __int64 v43; // rax
  __int64 v44; // rax
  ANTLR3_COMMON_TOKEN_struct *v45; // r9
  ANTLR3_COMMON_TOKEN_struct *v46; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v47; // rcx
  ANTLR3_BASE_RECOGNIZER_struct *v48; // r8
  ANTLR3_BASE_TREE_ADAPTOR_struct *v49; // rsi
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v50; // rdi
  __int64 v51; // rax
  UELParser_logicalExpression_return_struct resulta; // [rsp+48h] [rbp-70h]
  UELParser_logicalExpression_return_struct v54; // [rsp+60h] [rbp-58h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v55; // [rsp+C0h] [rbp+8h]
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v56; // [rsp+C8h] [rbp+10h]

  v2 = ctx;
  v3 = result;
  v4 = 0i64;
  v5 = ctx->pParser->tstream->_LT(ctx->pParser->tstream, 1);
  v3->start = v5;
  v3->stop = v5;
  v55 = 0i64;
  v6 = 0i64;
  v7 = v2->pParser->rec;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  v3->tree = 0i64;
  v11 = (__int64)v7->match(v7, 17u, &FOLLOW_FUNCTION_in_function939);
  v12 = v2->pParser->rec;
  if ( v12->state->error != 1 )
  {
    v55 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v12, "token FUNCTION");
    v55->add(v55, (void *)v11, 0i64);
    v13 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 44u, &FOLLOW_44_in_function941);
    v14 = v2->pParser->rec;
    if ( v14->state->error != 1 )
    {
      v8 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v14, "token 44");
      v8->add(v8, (void *)v13, 0i64);
      v15 = 2;
      v16 = v2->pParser->tstream->istream;
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
        v17 = v2->pParser->rec->state->following;
        v17->push(v17, &FOLLOW_logicalExpression_in_function945, 0i64);
        v18 = logicalExpression(&resulta, v2);
        v19 = v18->tree;
        v20 = v18->start;
        v21 = v18->stop;
        v22 = v2->pParser->rec->state->following;
        v22->pop(v22);
        v23 = v2->pParser->rec;
        if ( v23->state->error == 1 )
          goto $rulefunctionEx;
        v10 = antlr3RewriteRuleSubtreeStreamNewAE(v2->adaptor, v23, "rule logicalExpression");
        v10->add(v10, v19, 0i64);
        while ( 1 )
        {
          v24 = v2->pParser->tstream->istream;
          v25 = v24->_LA(v24, 1);
          v26 = 2;
          if ( v25 == 46 )
            v26 = 1;
          if ( v26 != 1 )
            break;
          v27 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 46u, &FOLLOW_46_in_function948);
          v28 = v2->pParser->rec;
          if ( v28->state->error == 1 )
            goto $rulefunctionEx;
          if ( !v9 )
            v9 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v28, "token 46");
          v9->add(v9, (void *)v27, 0i64);
          v29 = v2->pParser->rec->state->following;
          v29->push(v29, &FOLLOW_logicalExpression_in_function950, 0i64);
          v30 = logicalExpression(&v54, v2);
          v31 = v30->tree;
          v32 = v30->start;
          v33 = v30->stop;
          v34 = v2->pParser->rec->state->following;
          v34->pop(v34);
          if ( v2->pParser->rec->state->error == 1 )
            goto $rulefunctionEx;
          v10->add(v10, v31, 0i64);
        }
      }
      v35 = (__int64)v2->pParser->rec->match(v2->pParser->rec, 45u, &FOLLOW_45_in_function957);
      v36 = v2->pParser->rec;
      if ( v36->state->error != 1 )
      {
        v56 = antlr3RewriteRuleTOKENStreamNewAE(v2->adaptor, v36, "token 45");
        v56->add(v56, (void *)v35, 0i64);
        v37 = antlr3RewriteRuleSubtreeStreamNewAEE(v2->adaptor, v2->pParser->rec, "token retval", v3->tree);
        v38 = (__int64)v2->adaptor->nilNode(v2->adaptor);
        v39 = v2->adaptor;
        v4 = (ANTLR3_BASE_TREE_struct *)v38;
        v3->tree = (ANTLR3_BASE_TREE_struct *)v38;
        v40 = (__int64)v39->nilNode(v39);
        v41 = (__int64)v55->nextNode(v55);
        v42 = (__int64)v2->adaptor->becomeRoot(v2->adaptor, (void *)v41, (void *)v40);
        if ( v10 )
        {
          while ( v10->hasNext(v10) )
          {
            v43 = (__int64)v10->nextTree(v10);
            v2->adaptor->addChild(v2->adaptor, (void *)v42, (void *)v43);
          }
          v10->reset(v10);
        }
        v2->adaptor->addChild(v2->adaptor, v4, (void *)v42);
        v3->tree = v4;
        if ( v37 )
          v37->free(v37);
        v6 = v56;
      }
    }
  }
$rulefunctionEx:
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v3->stop = v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
  v44 = (__int64)v2->adaptor->rulePostProcessing(v2->adaptor, v4);
  v45 = v3->stop;
  v46 = v3->start;
  v47 = v2->adaptor;
  v3->tree = (ANTLR3_BASE_TREE_struct *)v44;
  v47->setTokenBoundaries(v47, (void *)v44, v46, v45);
  if ( v55 )
    v55->free(v55);
  if ( v6 )
    v6->free(v6);
  if ( v8 )
    v8->free(v8);
  if ( v9 )
    v9->free(v9);
  if ( v10 )
    v10->free(v10);
  v48 = v2->pParser->rec;
  if ( v48->state->error == 1 )
  {
    v48->reportError(v2->pParser->rec);
    v2->pParser->rec->recover(v2->pParser->rec);
    v49 = v2->adaptor;
    v50 = v2->pParser->rec->state;
    v51 = (__int64)v2->pParser->tstream->_LT(v2->pParser->tstream, -1);
    v3->tree = (ANTLR3_BASE_TREE_struct *)v49->errorNode(
                                            v2->adaptor,
                                            v2->pParser->tstream,
                                            v3->start,
                                            (ANTLR3_COMMON_TOKEN_struct *)v51,
                                            v50->exception);
  }
  return v3;
}

