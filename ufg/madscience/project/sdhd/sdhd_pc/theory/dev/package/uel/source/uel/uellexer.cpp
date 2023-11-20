// File Line: 416
// RVA: 0x24BAB0
void __fastcall UELLexerFree(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx

  v1 = ctx;
  ctx->pLexer->free(ctx->pLexer);
  antlrFree(v1);
}

// File Line: 424
// RVA: 0x24BAE0
void __fastcall UELLexerReset(UELLexer_Ctx_struct *ctx)
{
  ctx->pLexer->rec->reset(ctx->pLexer->rec);
}

// File Line: 435
// RVA: 0x24BB00
const char *__fastcall getGrammarFileName_0()
{
  return "D:\\UFG\\MadScience\\Project\\SD2\\dev\\Theory\\dev\\Package\\UEL\\Source\\UEL\\UEL.g";
}

// File Line: 450
// RVA: 0x24DC70
UELLexer_Ctx_struct *__fastcall UELLexerNew(ANTLR3_INPUT_STREAM_struct *instream)
{
  return UELLexerNewSSD(instream, 0i64);
}

// File Line: 466
// RVA: 0x24DC80
ANTLR3_LEXER_struct **__fastcall UELLexerNewSSD(ANTLR3_INPUT_STREAM_struct *instream, ANTLR3_RECOGNIZER_SHARED_STATE_struct *state)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rdi
  ANTLR3_INPUT_STREAM_struct *v3; // rsi
  ANTLR3_LEXER_struct **v4; // rbx
  ANTLR3_LEXER_struct *v5; // rax

  v2 = state;
  v3 = instream;
  v4 = (ANTLR3_LEXER_struct **)antlrCalloc(1u, 0x188u);
  if ( !v4 )
    return 0i64;
  v5 = antlr3LexerNewStream(0x401u, v3, v2);
  *v4 = v5;
  if ( !v5 )
  {
    antlrFree(v4);
    return 0i64;
  }
  v4[1] = (ANTLR3_LEXER_struct *)mT__44;
  v4[2] = (ANTLR3_LEXER_struct *)mT__45;
  v4[3] = (ANTLR3_LEXER_struct *)mT__46;
  v4[4] = (ANTLR3_LEXER_struct *)mT__47;
  v4[5] = (ANTLR3_LEXER_struct *)mT__48;
  v4[6] = (ANTLR3_LEXER_struct *)mT__49;
  v4[7] = (ANTLR3_LEXER_struct *)mT__50;
  v4[8] = (ANTLR3_LEXER_struct *)mT__51;
  v4[9] = (ANTLR3_LEXER_struct *)mENUMERATION;
  v4[10] = (ANTLR3_LEXER_struct *)mSCOPE;
  v4[11] = (ANTLR3_LEXER_struct *)mTYPE;
  v4[12] = (ANTLR3_LEXER_struct *)mOR;
  v4[13] = (ANTLR3_LEXER_struct *)mAND;
  v4[14] = (ANTLR3_LEXER_struct *)mEQUALS;
  v4[15] = (ANTLR3_LEXER_struct *)mNOTEQUALS;
  v4[16] = (ANTLR3_LEXER_struct *)mLTH;
  v4[17] = (ANTLR3_LEXER_struct *)mLTEQ;
  v4[18] = (ANTLR3_LEXER_struct *)mGTH;
  v4[19] = (ANTLR3_LEXER_struct *)mGTEQ;
  v4[20] = (ANTLR3_LEXER_struct *)mPLUS;
  v4[21] = (ANTLR3_LEXER_struct *)mMINUS;
  v4[22] = (ANTLR3_LEXER_struct *)mMULT;
  v4[23] = (ANTLR3_LEXER_struct *)mDIV;
  v4[24] = (ANTLR3_LEXER_struct *)mNOT;
  v4[25] = (ANTLR3_LEXER_struct *)mREFERENCE;
  v4[26] = (ANTLR3_LEXER_struct *)mPARAMETER;
  v4[27] = (ANTLR3_LEXER_struct *)mARGUMENT;
  v4[28] = (ANTLR3_LEXER_struct *)mDIGIT;
  v4[29] = (ANTLR3_LEXER_struct *)mINTEGER;
  v4[30] = (ANTLR3_LEXER_struct *)mREAL;
  v4[31] = (ANTLR3_LEXER_struct *)mBOOLEAN;
  v4[32] = (ANTLR3_LEXER_struct *)mFUNCTION;
  v4[33] = (ANTLR3_LEXER_struct *)mFRAGMENT;
  v4[34] = (ANTLR3_LEXER_struct *)mALL_TEXT_STRING;
  v4[35] = (ANTLR3_LEXER_struct *)mSTRING;
  v4[36] = (ANTLR3_LEXER_struct *)mALL_TEXT_SYMBOL;
  v4[37] = (ANTLR3_LEXER_struct *)mSYMBOL;
  v4[38] = (ANTLR3_LEXER_struct *)mLABEL;
  v4[39] = (ANTLR3_LEXER_struct *)mEscapeSequence;
  v4[40] = (ANTLR3_LEXER_struct *)mUnicodeEscape;
  v4[41] = (ANTLR3_LEXER_struct *)mHexDigit;
  v4[42] = (ANTLR3_LEXER_struct *)mSL_COMMENT;
  v4[43] = (ANTLR3_LEXER_struct *)mML_COMMENT;
  v4[44] = (ANTLR3_LEXER_struct *)mWS;
  v4[45] = (ANTLR3_LEXER_struct *)mTokens;
  v5->ctx = v4;
  (*v4)->mTokens = (void (__fastcall *)(void *))mTokens;
  v4[46] = (ANTLR3_LEXER_struct *)getGrammarFileName_0;
  v4[48] = (ANTLR3_LEXER_struct *)UELLexerFree;
  v4[47] = (ANTLR3_LEXER_struct *)UELLexerReset;
  return v4;
}

// File Line: 977
// RVA: 0x24D5E0
void __fastcall mT__44(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 40u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 44;
}

// File Line: 1018
// RVA: 0x24D620
void __fastcall mT__45(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 41u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 45;
}

// File Line: 1059
// RVA: 0x24D660
void __fastcall mT__46(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 44u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 46;
}

// File Line: 1100
// RVA: 0x24D6A0
void __fastcall mT__47(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 91u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 47;
}

// File Line: 1141
// RVA: 0x24D6E0
void __fastcall mT__48(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 93u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 48;
}

// File Line: 1182
// RVA: 0x24D720
void __fastcall mT__49(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 123u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 49;
}

// File Line: 1223
// RVA: 0x24D760
void __fastcall mT__50(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchs(ctx->pLexer, lit_1);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 50;
}

// File Line: 1266
// RVA: 0x24D7A0
void __fastcall mT__51(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 125u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 51;
}

// File Line: 1307
// RVA: 0x24C160
void __fastcall mENUMERATION(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 101u);
  if ( v1->pLexer->rec->state->error != 1 )
  {
    if ( v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) < 0x41
      || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0x5A )
    {
      v1->pLexer->rec->exConstruct(v1->pLexer->rec);
      v1->pLexer->rec->state->exception->type = 4;
      v1->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      v1->pLexer->recover(v1->pLexer);
    }
    else
    {
      v1->pLexer->input->istream->consume(v1->pLexer->input->istream);
      mLABEL(v1);
      v2 = v1->pLexer->rec->state;
      if ( v2->error != 1 )
        v2->type = 13;
    }
  }
}

// File Line: 1372
// RVA: 0x24D160
void __fastcall mSCOPE(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 58u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 37;
}

// File Line: 1413
// RVA: 0x24D360
void __fastcall mTYPE(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  signed int v2; // edi
  unsigned int v3; // eax
  unsigned int *v4; // rdx

  v1 = ctx;
  v2 = 1;
  switch ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) )
  {
    case 0x42u:
      v2 = 5;
      goto $LN39_3;
    case 0x45u:
      v2 = 7;
      goto $LN39_3;
    case 0x49u:
      goto $LN39_3;
    case 0x52u:
      v2 = 4;
      goto $LN39_3;
    case 0x53u:
      v3 = v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 2);
      if ( v3 == 116 )
      {
        v2 = 2;
      }
      else
      {
        if ( v3 != 121 )
        {
          v1->pLexer->rec->exConstruct(v1->pLexer->rec);
          v1->pLexer->rec->state->exception->type = 3;
          v1->pLexer->rec->state->exception->message = &customWorldMapCaption;
          v1->pLexer->rec->state->exception->decisionNum = 1;
          v1->pLexer->rec->state->exception->state = 2;
          return;
        }
        v2 = 3;
      }
$LN39_3:
      switch ( v2 )
      {
        case 1:
          v4 = lit_2;
          goto LABEL_19;
        case 2:
          v4 = lit_3;
          goto LABEL_19;
        case 3:
          v4 = lit_4;
          goto LABEL_19;
        case 4:
          v4 = lit_5;
          goto LABEL_19;
        case 5:
          v4 = lit_6;
          goto LABEL_19;
        case 6:
          v4 = lit_7;
          goto LABEL_19;
        case 7:
          v4 = lit_8;
LABEL_19:
          v1->pLexer->matchs(v1->pLexer, v4);
          if ( v1->pLexer->rec->state->error != 1 )
            goto LABEL_20;
          break;
        default:
LABEL_20:
          v1->pLexer->rec->state->type = 41;
          break;
      }
      return;
    case 0x56u:
      v2 = 6;
      goto $LN39_3;
    default:
      v1->pLexer->rec->exConstruct(v1->pLexer->rec);
      v1->pLexer->rec->state->exception->type = 3;
      v1->pLexer->rec->state->exception->message = &customWorldMapCaption;
      v1->pLexer->rec->state->exception->decisionNum = 1;
      v1->pLexer->rec->state->exception->state = 0;
      return;
  }
}

// File Line: 1621
// RVA: 0x24CD30
void __fastcall mOR(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  bool v2; // zf
  ANTLR3_LEXER_struct *v3; // rax
  unsigned int v4; // eax

  v1 = ctx;
  v2 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) == 124;
  v3 = v1->pLexer;
  if ( v2 )
  {
    v4 = v3->input->istream->_LA(v3->input->istream, 2);
    if ( v4 == 124 )
      v1->pLexer->matchs(v1->pLexer, lit_9);
    else
      v1->pLexer->matchc(v1->pLexer, 124u);
    if ( v1->pLexer->rec->state->error != 1 )
      v1->pLexer->rec->state->type = 31;
  }
  else
  {
    v3->rec->exConstruct(v3->rec);
    v1->pLexer->rec->state->exception->type = 3;
    v1->pLexer->rec->state->exception->message = &customWorldMapCaption;
    v1->pLexer->rec->state->exception->decisionNum = 2;
    v1->pLexer->rec->state->exception->state = 0;
  }
}

// File Line: 1719
// RVA: 0x24BE30
void __fastcall mAND(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  bool v2; // zf
  ANTLR3_LEXER_struct *v3; // rax
  unsigned int v4; // eax

  v1 = ctx;
  v2 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) == 38;
  v3 = v1->pLexer;
  if ( v2 )
  {
    v4 = v3->input->istream->_LA(v3->input->istream, 2);
    if ( v4 == 38 )
      v1->pLexer->matchs(v1->pLexer, lit_10);
    else
      v1->pLexer->matchc(v1->pLexer, 38u);
    if ( v1->pLexer->rec->state->error != 1 )
      v1->pLexer->rec->state->type = 6;
  }
  else
  {
    v3->rec->exConstruct(v3->rec);
    v1->pLexer->rec->state->exception->type = 3;
    v1->pLexer->rec->state->exception->message = &customWorldMapCaption;
    v1->pLexer->rec->state->exception->decisionNum = 3;
    v1->pLexer->rec->state->exception->state = 0;
  }
}

// File Line: 1817
// RVA: 0x24C250
void __fastcall mEQUALS(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchs(ctx->pLexer, lit_11);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 14;
}

// File Line: 1860
// RVA: 0x24CCF0
void __fastcall mNOTEQUALS(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchs(ctx->pLexer, lit_12);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 30;
}

// File Line: 1903
// RVA: 0x24CAF0
void __fastcall mLTH(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 60u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 24;
}

// File Line: 1944
// RVA: 0x24CAB0
void __fastcall mLTEQ(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchs(ctx->pLexer, lit_13);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 23;
}

// File Line: 1987
// RVA: 0x24C620
void __fastcall mGTH(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 62u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 19;
}

// File Line: 2028
// RVA: 0x24C5E0
void __fastcall mGTEQ(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchs(ctx->pLexer, lit_14);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 18;
}

// File Line: 2071
// RVA: 0x24CF00
void __fastcall mPLUS(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 43u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 34;
}

// File Line: 2112
// RVA: 0x24CB30
void __fastcall mMINUS(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 45u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 25;
}

// File Line: 2153
// RVA: 0x24CC70
void __fastcall mMULT(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 42u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 27;
}

// File Line: 2194
// RVA: 0x24C120
void __fastcall mDIV(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 47u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 12;
}

// File Line: 2235
// RVA: 0x24CCB0
void __fastcall mNOT(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 33u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 29;
}

// File Line: 2276
// RVA: 0x24D120
void __fastcall mREFERENCE(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 46u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 36;
}

// File Line: 2317
// RVA: 0x24CE30
void __fastcall mPARAMETER(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  if ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x41
    || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0x5A )
  {
    v1->pLexer->rec->exConstruct(v1->pLexer->rec);
    v1->pLexer->rec->state->exception->type = 4;
    v1->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    v1->pLexer->recover(v1->pLexer);
  }
  else
  {
    v1->pLexer->input->istream->consume(v1->pLexer->input->istream);
    mLABEL(v1);
    v2 = v1->pLexer->rec->state;
    if ( v2->error != 1 )
      v2->type = 32;
  }
}

// File Line: 2375
// RVA: 0x24BF30
void __fastcall mARGUMENT(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 35u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 7;
}

// File Line: 2416
// RVA: 0x24C070
void __fastcall mDIGIT(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx

  v1 = ctx;
  if ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x30
    || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0x39 )
  {
    v1->pLexer->rec->exConstruct(v1->pLexer->rec);
    v1->pLexer->rec->state->exception->type = 4;
    v1->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    v1->pLexer->recover(v1->pLexer);
  }
  else
  {
    v1->pLexer->input->istream->consume(v1->pLexer->input->istream);
  }
}

// File Line: 2463
// RVA: 0x24C770
void __fastcall mINTEGER(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  signed int i; // edi
  unsigned int v3; // eax
  signed int v4; // ecx
  bool v5; // cf
  bool v6; // zf
  ANTLR3_LEXER_struct *v7; // rax

  v1 = ctx;
  for ( i = 0; ; ++i )
  {
    v3 = v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1);
    v4 = 2;
    v3 -= 48;
    v5 = v3 < 9;
    v6 = v3 == 9;
    v7 = v1->pLexer;
    if ( v5 || v6 )
      v4 = 1;
    if ( v4 != 1 )
      break;
    if ( v7->input->istream->_LA(v7->input->istream, 1) < 0x30
      || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0x39 )
    {
      v1->pLexer->rec->exConstruct(v1->pLexer->rec);
      v1->pLexer->rec->state->exception->type = 4;
      v1->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      v1->pLexer->recover(v1->pLexer);
      return;
    }
    v1->pLexer->input->istream->consume(v1->pLexer->input->istream);
  }
  if ( i < 1 )
  {
    v7->rec->exConstruct(v7->rec);
    v1->pLexer->rec->state->exception->type = 5;
    v1->pLexer->rec->state->exception->name = "org.antlr.runtime.EarlyExitException";
  }
  else
  {
    v7->rec->state->type = 21;
  }
}

// File Line: 2566
// RVA: 0x24CF40
void __fastcall mREAL(UELLexer_Ctx_struct *ctx)
{
  signed int v1; // esi
  UELLexer_Ctx_struct *v2; // rbx
  signed int i; // edi
  unsigned int v4; // eax
  signed int v5; // ecx
  bool v6; // cf
  bool v7; // zf
  ANTLR3_LEXER_struct *v8; // rax
  unsigned int v9; // eax
  signed int v10; // ecx

  v1 = 0;
  v2 = ctx;
  for ( i = 0; ; ++i )
  {
    v4 = v2->pLexer->input->istream->_LA(v2->pLexer->input->istream, 1);
    v5 = 2;
    v4 -= 48;
    v6 = v4 < 9;
    v7 = v4 == 9;
    v8 = v2->pLexer;
    if ( v6 || v7 )
      v5 = 1;
    if ( v5 != 1 )
      break;
    if ( v8->input->istream->_LA(v8->input->istream, 1) < 0x30
      || v2->pLexer->input->istream->_LA(v2->pLexer->input->istream, 1) > 0x39 )
    {
LABEL_16:
      v2->pLexer->rec->exConstruct(v2->pLexer->rec);
      v2->pLexer->rec->state->exception->type = 4;
      v2->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      v2->pLexer->recover(v2->pLexer);
      return;
    }
    v2->pLexer->input->istream->consume(v2->pLexer->input->istream);
  }
  if ( i < 1 )
    goto LABEL_22;
  v8->matchc(v2->pLexer, 46u);
  if ( v2->pLexer->rec->state->error == 1 )
    return;
  while ( 1 )
  {
    v9 = v2->pLexer->input->istream->_LA(v2->pLexer->input->istream, 1);
    v10 = 2;
    v9 -= 48;
    v6 = v9 < 9;
    v7 = v9 == 9;
    v8 = v2->pLexer;
    if ( v6 || v7 )
      v10 = 1;
    if ( v10 != 1 )
      break;
    if ( v8->input->istream->_LA(v8->input->istream, 1) < 0x30
      || v2->pLexer->input->istream->_LA(v2->pLexer->input->istream, 1) > 0x39 )
    {
      goto LABEL_16;
    }
    v2->pLexer->input->istream->consume(v2->pLexer->input->istream);
    ++v1;
  }
  if ( v1 < 1 )
  {
LABEL_22:
    v8->rec->exConstruct(v8->rec);
    v2->pLexer->rec->state->exception->type = 5;
    v2->pLexer->rec->state->exception->name = "org.antlr.runtime.EarlyExitException";
  }
  else
  {
    v8->rec->state->type = 35;
  }
}

// File Line: 2745
// RVA: 0x24BF70
void __fastcall mBOOLEAN(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rdi
  signed int v2; // ebx
  unsigned int v3; // eax
  int v4; // ebx
  unsigned int *v5; // rdx

  v1 = ctx;
  v2 = 1;
  v3 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
  if ( v3 == 102 )
  {
    v2 = 2;
  }
  else if ( v3 != 116 )
  {
    v1->pLexer->rec->exConstruct(v1->pLexer->rec);
    v1->pLexer->rec->state->exception->type = 3;
    v1->pLexer->rec->state->exception->message = &customWorldMapCaption;
    v1->pLexer->rec->state->exception->decisionNum = 7;
    v1->pLexer->rec->state->exception->state = 0;
    return;
  }
  v4 = v2 - 1;
  if ( !v4 )
  {
    v5 = lit_15;
LABEL_9:
    v1->pLexer->matchs(v1->pLexer, v5);
    if ( v1->pLexer->rec->state->error == 1 )
      return;
    goto LABEL_10;
  }
  if ( v4 == 1 )
  {
    v5 = lit_16;
    goto LABEL_9;
  }
LABEL_10:
  v1->pLexer->rec->state->type = 8;
}

// File Line: 2839
// RVA: 0x24C510
void __fastcall mFUNCTION(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  if ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x61
    || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0x7A )
  {
    v1->pLexer->rec->exConstruct(v1->pLexer->rec);
    v1->pLexer->rec->state->exception->type = 4;
    v1->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    v1->pLexer->recover(v1->pLexer);
  }
  else
  {
    v1->pLexer->input->istream->consume(v1->pLexer->input->istream);
    mLABEL(v1);
    v2 = v1->pLexer->rec->state;
    if ( v2->error != 1 )
      v2->type = 17;
  }
}

// File Line: 2897
// RVA: 0x24C4D0
void __fastcall mFRAGMENT(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 94u);
  v2 = v1->pLexer->rec->state;
  if ( v2->error != 1 )
    v2->type = 16;
}

// File Line: 2938
// RVA: 0x24BB10
void __fastcall mALL_TEXT_STRING(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *i; // rdi
  signed int v2; // ebx
  signed int v3; // eax
  int v4; // ebx

  for ( i = ctx; ; i->pLexer->input->istream->consume(i->pLexer->input->istream) )
  {
    while ( 1 )
    {
      v2 = 3;
      v3 = i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1);
      if ( v3 == 92 )
      {
        v2 = 1;
      }
      else if ( v3 != 34 && v3 > 31 && v3 < 92 || (unsigned int)(v3 - 93) <= 0xFFA2 )
      {
        v2 = 2;
      }
      v4 = v2 - 1;
      if ( v4 )
        break;
      mEscapeSequence(i);
      if ( i->pLexer->rec->state->error == 1 )
        return;
    }
    if ( v4 != 1 )
      return;
    if ( (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x20
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0x21)
      && (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x23
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0x5B)
      && (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x5D
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0xFFFF) )
    {
      break;
    }
  }
  i->pLexer->rec->exConstruct(i->pLexer->rec);
  i->pLexer->rec->state->exception->type = 4;
  i->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
  i->pLexer->recover(i->pLexer);
}

// File Line: 3040
// RVA: 0x24D280
void __fastcall mSTRING(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 34u);
  if ( v1->pLexer->rec->state->error != 1 )
  {
    mALL_TEXT_STRING(v1);
    if ( v1->pLexer->rec->state->error != 1 )
    {
      v1->pLexer->matchc(v1->pLexer, 34u);
      v2 = v1->pLexer->rec->state;
      if ( v2->error != 1 )
        v2->type = 39;
    }
  }
}

// File Line: 3097
// RVA: 0x24BCA0
void __fastcall mALL_TEXT_SYMBOL(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *i; // rdi
  signed int v2; // ebx
  signed int v3; // eax
  int v4; // ebx

  for ( i = ctx; ; i->pLexer->input->istream->consume(i->pLexer->input->istream) )
  {
    while ( 1 )
    {
      v2 = 3;
      v3 = i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1);
      if ( v3 == 92 )
      {
        v2 = 1;
      }
      else if ( v3 != 39 && v3 > 31 && v3 < 92 || (unsigned int)(v3 - 93) <= 0xFFA2 )
      {
        v2 = 2;
      }
      v4 = v2 - 1;
      if ( v4 )
        break;
      mEscapeSequence(i);
      if ( i->pLexer->rec->state->error == 1 )
        return;
    }
    if ( v4 != 1 )
      return;
    if ( (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x20
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0x26)
      && (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x28
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0x5B)
      && (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x5D
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0xFFFF) )
    {
      break;
    }
  }
  i->pLexer->rec->exConstruct(i->pLexer->rec);
  i->pLexer->rec->state->exception->type = 4;
  i->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
  i->pLexer->recover(i->pLexer);
}

// File Line: 3199
// RVA: 0x24D2F0
void __fastcall mSYMBOL(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v2; // rax

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 39u);
  if ( v1->pLexer->rec->state->error != 1 )
  {
    mALL_TEXT_SYMBOL(v1);
    if ( v1->pLexer->rec->state->error != 1 )
    {
      v1->pLexer->matchc(v1->pLexer, 39u);
      v2 = v1->pLexer->rec->state;
      if ( v2->error != 1 )
        v2->type = 40;
    }
  }
}

// File Line: 3256
// RVA: 0x24C8D0
void __fastcall mLABEL(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *i; // rbx
  signed int v2; // edi

  for ( i = ctx; ; i->pLexer->input->istream->consume(i->pLexer->input->istream) )
  {
    v2 = 2;
    switch ( i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) )
    {
      case 0x30u:
      case 0x31u:
      case 0x32u:
      case 0x33u:
      case 0x34u:
      case 0x35u:
      case 0x36u:
      case 0x37u:
      case 0x38u:
      case 0x39u:
      case 0x41u:
      case 0x42u:
      case 0x43u:
      case 0x44u:
      case 0x45u:
      case 0x46u:
      case 0x47u:
      case 0x48u:
      case 0x49u:
      case 0x4Au:
      case 0x4Bu:
      case 0x4Cu:
      case 0x4Du:
      case 0x4Eu:
      case 0x4Fu:
      case 0x50u:
      case 0x51u:
      case 0x52u:
      case 0x53u:
      case 0x54u:
      case 0x55u:
      case 0x56u:
      case 0x57u:
      case 0x58u:
      case 0x59u:
      case 0x5Au:
      case 0x5Fu:
      case 0x61u:
      case 0x62u:
      case 0x63u:
      case 0x64u:
      case 0x65u:
      case 0x66u:
      case 0x67u:
      case 0x68u:
      case 0x69u:
      case 0x6Au:
      case 0x6Bu:
      case 0x6Cu:
      case 0x6Du:
      case 0x6Eu:
      case 0x6Fu:
      case 0x70u:
      case 0x71u:
      case 0x72u:
      case 0x73u:
      case 0x74u:
      case 0x75u:
      case 0x76u:
      case 0x77u:
      case 0x78u:
      case 0x79u:
      case 0x7Au:
        v2 = 1;
        break;
      default:
        break;
    }
    if ( v2 != 1 )
      break;
    if ( (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x30
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0x39)
      && (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x41
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0x5A)
      && i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) != 95
      && (i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) < 0x61
       || i->pLexer->input->istream->_LA(i->pLexer->input->istream, 1) > 0x7A) )
    {
      i->pLexer->rec->exConstruct(i->pLexer->rec);
      i->pLexer->rec->state->exception->type = 4;
      i->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      i->pLexer->recover(i->pLexer);
      return;
    }
  }
}

// File Line: 3396
// RVA: 0x24C290
void __fastcall mEscapeSequence(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  signed int v2; // edi

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 92u);
  if ( v1->pLexer->rec->state->error != 1 )
  {
    v2 = 1;
    switch ( v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) )
    {
      case 0x27u:
        v2 = 4;
        goto $LN30_6;
      case 0x5Cu:
        v2 = 5;
        goto $LN30_6;
      case 0x6Eu:
        goto $LN30_6;
      case 0x72u:
        v2 = 2;
        goto $LN30_6;
      case 0x74u:
        v2 = 3;
        goto $LN30_6;
      case 0x75u:
        v2 = 6;
$LN30_6:
        switch ( v2 )
        {
          case 1:
            v1->pLexer->matchc(v1->pLexer, 110u);
            break;
          case 2:
            v1->pLexer->matchc(v1->pLexer, 114u);
            break;
          case 3:
            v1->pLexer->matchc(v1->pLexer, 116u);
            break;
          case 4:
            v1->pLexer->matchc(v1->pLexer, 39u);
            break;
          case 5:
            v1->pLexer->matchc(v1->pLexer, 92u);
            break;
          case 6:
            mUnicodeEscape(v1);
            break;
          default:
            return;
        }
        break;
      default:
        v1->pLexer->rec->exConstruct(v1->pLexer->rec);
        v1->pLexer->rec->state->exception->type = 3;
        v1->pLexer->rec->state->exception->message = &customWorldMapCaption;
        v1->pLexer->rec->state->exception->decisionNum = 11;
        v1->pLexer->rec->state->exception->state = 0;
        break;
    }
  }
}

// File Line: 3563
// RVA: 0x24DAC0
void __fastcall mUnicodeEscape(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx

  v1 = ctx;
  ctx->pLexer->matchc(ctx->pLexer, 117u);
  if ( v1->pLexer->rec->state->error != 1 )
  {
    mHexDigit(v1);
    if ( v1->pLexer->rec->state->error != 1 )
    {
      mHexDigit(v1);
      if ( v1->pLexer->rec->state->error != 1 )
      {
        mHexDigit(v1);
        if ( v1->pLexer->rec->state->error != 1 )
          mHexDigit(v1);
      }
    }
  }
}

// File Line: 3638
// RVA: 0x24C660
void __fastcall mHexDigit(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx

  v1 = ctx;
  if ( (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x30
     || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0x39)
    && (v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) < 0x41
     || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0x46)
    && (v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) < 0x61
     || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0x66) )
  {
    v1->pLexer->rec->exConstruct(v1->pLexer->rec);
    v1->pLexer->rec->state->exception->type = 4;
    v1->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    v1->pLexer->recover(v1->pLexer);
  }
  else
  {
    v1->pLexer->input->istream->consume(v1->pLexer->input->istream);
  }
}

// File Line: 3685
// RVA: 0x24D1A0
void __fastcall mSL_COMMENT(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rdi
  signed int v2; // ebx
  unsigned int v3; // eax
  ANTLR3_LEXER_struct *v4; // rax
  ANTLR3_LEXER_struct *v5; // rcx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v6; // rax

  v1 = ctx;
  ctx->pLexer->matchs(ctx->pLexer, lit_17);
  if ( v1->pLexer->rec->state->error != 1 )
  {
    while ( 1 )
    {
      v2 = 2;
      v3 = v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1);
      if ( v3 != 10 && (v3 <= 9 || v3 - 11 <= 0xFFF4) )
        v2 = 1;
      v4 = v1->pLexer;
      v5 = v1->pLexer;
      if ( v2 != 1 )
        break;
      v4->matchAny(v5);
      if ( v1->pLexer->rec->state->error == 1 )
        return;
    }
    v4->matchc(v5, 10u);
    v6 = v1->pLexer->rec->state;
    if ( v6->error != 1 )
    {
      v6->channel = 99;
      v1->pLexer->rec->state->type = 38;
    }
  }
}

// File Line: 3788
// RVA: 0x24CB70
void __fastcall mML_COMMENT(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rdi
  signed int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  bool v6; // cf
  bool v7; // zf
  unsigned int v8; // eax
  ANTLR3_LEXER_struct *v9; // rax
  ANTLR3_LEXER_struct *v10; // rcx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v11; // rax

  v1 = ctx;
  ctx->pLexer->matchs(ctx->pLexer, lit_18);
  while ( v1->pLexer->rec->state->error != 1 )
  {
    v2 = 2;
    v3 = v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1);
    if ( v3 == 42 )
    {
      v4 = v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 2);
      if ( v4 == 47 )
        goto LABEL_10;
      if ( v4 > 0x2E )
      {
        v5 = v4 - 48;
        v6 = v5 < 0xFFCF;
        v7 = v5 == 65487;
        goto LABEL_8;
      }
    }
    else if ( v3 > 0x29 )
    {
      v8 = v3 - 43;
      v6 = v8 < 0xFFD4;
      v7 = v8 == 65492;
LABEL_8:
      if ( !v6 && !v7 )
        goto LABEL_10;
      goto LABEL_9;
    }
LABEL_9:
    v2 = 1;
LABEL_10:
    v9 = v1->pLexer;
    v10 = v1->pLexer;
    if ( v2 != 1 )
    {
      v9->matchs(v10, lit_19);
      v11 = v1->pLexer->rec->state;
      if ( v11->error != 1 )
      {
        v11->channel = 99;
        v1->pLexer->rec->state->type = 26;
      }
      return;
    }
    v9->matchAny(v10);
  }
}

// File Line: 3906
// RVA: 0x24DB50
void __fastcall mWS(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx

  v1 = ctx;
  if ( (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 9
     || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0xA)
    && (v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) < 0xC
     || v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) > 0xD)
    && v1->pLexer->input->istream->_LA(v1->pLexer->input->istream, 1) != 32 )
  {
    v1->pLexer->rec->exConstruct(v1->pLexer->rec);
    v1->pLexer->rec->state->exception->type = 4;
    v1->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    v1->pLexer->recover(v1->pLexer);
  }
  else
  {
    v1->pLexer->input->istream->consume(v1->pLexer->input->istream);
    v1->pLexer->rec->state->channel = 99;
    v1->pLexer->rec->state->type = 43;
  }
}

// File Line: 3951
// RVA: 0x24D7E0
void __fastcall mTokens(UELLexer_Ctx_struct *ctx)
{
  UELLexer_Ctx_struct *v1; // rbx
  int v2; // eax

  v1 = ctx;
  v2 = cdfa14.predict(ctx, ctx->pLexer->rec, ctx->pLexer->input->istream, &cdfa14);
  if ( v1->pLexer->rec->state->error != 1 )
  {
    switch ( v2 )
    {
      case 1:
        mT__44(v1);
        break;
      case 2:
        mT__45(v1);
        break;
      case 3:
        mT__46(v1);
        break;
      case 4:
        mT__47(v1);
        break;
      case 5:
        mT__48(v1);
        break;
      case 6:
        mT__49(v1);
        break;
      case 7:
        mT__50(v1);
        break;
      case 8:
        mT__51(v1);
        break;
      case 9:
        mENUMERATION(v1);
        break;
      case 10:
        mSCOPE(v1);
        break;
      case 11:
        mTYPE(v1);
        break;
      case 12:
        mOR(v1);
        break;
      case 13:
        mAND(v1);
        break;
      case 14:
        mEQUALS(v1);
        break;
      case 15:
        mNOTEQUALS(v1);
        break;
      case 16:
        mLTH(v1);
        break;
      case 17:
        mLTEQ(v1);
        break;
      case 18:
        mGTH(v1);
        break;
      case 19:
        mGTEQ(v1);
        break;
      case 20:
        mPLUS(v1);
        break;
      case 21:
        mMINUS(v1);
        break;
      case 22:
        mMULT(v1);
        break;
      case 23:
        mDIV(v1);
        break;
      case 24:
        mNOT(v1);
        break;
      case 25:
        mREFERENCE(v1);
        break;
      case 26:
        mPARAMETER(v1);
        break;
      case 27:
        mARGUMENT(v1);
        break;
      case 28:
        mINTEGER(v1);
        break;
      case 29:
        mREAL(v1);
        break;
      case 30:
        mBOOLEAN(v1);
        break;
      case 31:
        mFUNCTION(v1);
        break;
      case 32:
        mFRAGMENT(v1);
        break;
      case 33:
        mSTRING(v1);
        break;
      case 34:
        mSYMBOL(v1);
        break;
      case 35:
        mSL_COMMENT(v1);
        break;
      case 36:
        mML_COMMENT(v1);
        break;
      case 37:
        mWS(v1);
        break;
      default:
        return;
    }
  }
}

