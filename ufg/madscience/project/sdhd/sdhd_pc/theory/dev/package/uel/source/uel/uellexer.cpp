// File Line: 416
// RVA: 0x24BAB0
void __fastcall UELLexerFree(UELLexer_Ctx_struct *ctx)
{
  ctx->pLexer->free(ctx->pLexer);
  antlrFree(ctx);
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
UELLexer_Ctx_struct *__fastcall UELLexerNewSSD(
        ANTLR3_INPUT_STREAM_struct *instream,
        ANTLR3_RECOGNIZER_SHARED_STATE_struct *state)
{
  ANTLR3_LEXER_struct **v4; // rbx
  ANTLR3_LEXER_struct *v5; // rax

  v4 = (ANTLR3_LEXER_struct **)antlrCalloc(1u, 0x188u);
  if ( !v4 )
    return 0i64;
  v5 = antlr3LexerNewStream(0x401u, instream, state);
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
  return (UELLexer_Ctx_struct *)v4;
}

// File Line: 977
// RVA: 0x24D5E0
void __fastcall mT__44(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 40u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 44;
}

// File Line: 1018
// RVA: 0x24D620
void __fastcall mT__45(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 41u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 45;
}

// File Line: 1059
// RVA: 0x24D660
void __fastcall mT__46(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 44u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 46;
}

// File Line: 1100
// RVA: 0x24D6A0
void __fastcall mT__47(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 91u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 47;
}

// File Line: 1141
// RVA: 0x24D6E0
void __fastcall mT__48(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 93u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 48;
}

// File Line: 1182
// RVA: 0x24D720
void __fastcall mT__49(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 123u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 49;
}

// File Line: 1223
// RVA: 0x24D760
void __fastcall mT__50(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchs(ctx->pLexer, lit_1);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 50;
}

// File Line: 1266
// RVA: 0x24D7A0
void __fastcall mT__51(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 125u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 51;
}

// File Line: 1307
// RVA: 0x24C160
void __fastcall mENUMERATION(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 101u);
  if ( ctx->pLexer->rec->state->error != 1 )
  {
    if ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x41
      || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x5A )
    {
      ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
      ctx->pLexer->rec->state->exception->type = 4;
      ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      ctx->pLexer->recover(ctx->pLexer);
    }
    else
    {
      ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
      mLABEL(ctx);
      state = ctx->pLexer->rec->state;
      if ( state->error != 1 )
        state->type = 13;
    }
  }
}

// File Line: 1372
// RVA: 0x24D160
void __fastcall mSCOPE(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 58u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 37;
}

// File Line: 1413
// RVA: 0x24D360
void __fastcall mTYPE(UELLexer_Ctx_struct *ctx)
{
  int v2; // edi
  unsigned int v3; // eax
  unsigned int *v4; // rdx

  v2 = 1;
  switch ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) )
  {
    case B:
      v2 = 5;
      goto $LN39_3;
    case E:
      v2 = 7;
      goto $LN39_3;
    case I:
      goto $LN39_3;
    case R:
      v2 = 4;
      goto $LN39_3;
    case S:
      v3 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 2);
      if ( v3 == 116 )
      {
        v2 = 2;
      }
      else
      {
        if ( v3 != 121 )
        {
          ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
          ctx->pLexer->rec->state->exception->type = 3;
          ctx->pLexer->rec->state->exception->message = &customCaption;
          ctx->pLexer->rec->state->exception->decisionNum = 1;
          ctx->pLexer->rec->state->exception->state = 2;
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
          ctx->pLexer->matchs(ctx->pLexer, v4);
          if ( ctx->pLexer->rec->state->error != 1 )
            goto LABEL_20;
          return;
        default:
LABEL_20:
          ctx->pLexer->rec->state->type = 41;
          break;
      }
      return;
    case V:
      v2 = 6;
      goto $LN39_3;
    default:
      ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
      ctx->pLexer->rec->state->exception->type = 3;
      ctx->pLexer->rec->state->exception->message = &customCaption;
      ctx->pLexer->rec->state->exception->decisionNum = 1;
      ctx->pLexer->rec->state->exception->state = 0;
      return;
  }
}

// File Line: 1621
// RVA: 0x24CD30
void __fastcall mOR(UELLexer_Ctx_struct *ctx)
{
  bool v2; // zf
  ANTLR3_LEXER_struct *pLexer; // rax
  unsigned int v4; // eax

  v2 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) == 124;
  pLexer = ctx->pLexer;
  if ( v2 )
  {
    v4 = pLexer->input->istream->_LA(pLexer->input->istream, 2);
    if ( v4 == 124 )
      ctx->pLexer->matchs(ctx->pLexer, lit_9);
    else
      ctx->pLexer->matchc(ctx->pLexer, 124u);
    if ( ctx->pLexer->rec->state->error != 1 )
      ctx->pLexer->rec->state->type = 31;
  }
  else
  {
    pLexer->rec->exConstruct(pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 3;
    ctx->pLexer->rec->state->exception->message = &customCaption;
    ctx->pLexer->rec->state->exception->decisionNum = 2;
    ctx->pLexer->rec->state->exception->state = 0;
  }
}

// File Line: 1719
// RVA: 0x24BE30
void __fastcall mAND(UELLexer_Ctx_struct *ctx)
{
  bool v2; // zf
  ANTLR3_LEXER_struct *pLexer; // rax
  unsigned int v4; // eax

  v2 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) == 38;
  pLexer = ctx->pLexer;
  if ( v2 )
  {
    v4 = pLexer->input->istream->_LA(pLexer->input->istream, 2);
    if ( v4 == 38 )
      ctx->pLexer->matchs(ctx->pLexer, lit_10);
    else
      ctx->pLexer->matchc(ctx->pLexer, 38u);
    if ( ctx->pLexer->rec->state->error != 1 )
      ctx->pLexer->rec->state->type = 6;
  }
  else
  {
    pLexer->rec->exConstruct(pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 3;
    ctx->pLexer->rec->state->exception->message = &customCaption;
    ctx->pLexer->rec->state->exception->decisionNum = 3;
    ctx->pLexer->rec->state->exception->state = 0;
  }
}

// File Line: 1817
// RVA: 0x24C250
void __fastcall mEQUALS(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchs(ctx->pLexer, lit_11);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 14;
}

// File Line: 1860
// RVA: 0x24CCF0
void __fastcall mNOTEQUALS(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchs(ctx->pLexer, lit_12);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 30;
}

// File Line: 1903
// RVA: 0x24CAF0
void __fastcall mLTH(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 60u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 24;
}

// File Line: 1944
// RVA: 0x24CAB0
void __fastcall mLTEQ(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchs(ctx->pLexer, lit_13);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 23;
}

// File Line: 1987
// RVA: 0x24C620
void __fastcall mGTH(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 62u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 19;
}

// File Line: 2028
// RVA: 0x24C5E0
void __fastcall mGTEQ(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchs(ctx->pLexer, lit_14);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 18;
}

// File Line: 2071
// RVA: 0x24CF00
void __fastcall mPLUS(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 43u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 34;
}

// File Line: 2112
// RVA: 0x24CB30
void __fastcall mMINUS(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 45u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 25;
}

// File Line: 2153
// RVA: 0x24CC70
void __fastcall mMULT(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 42u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 27;
}

// File Line: 2194
// RVA: 0x24C120
void __fastcall mDIV(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 47u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 12;
}

// File Line: 2235
// RVA: 0x24CCB0
void __fastcall mNOT(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 33u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 29;
}

// File Line: 2276
// RVA: 0x24D120
void __fastcall mREFERENCE(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 46u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 36;
}

// File Line: 2317
// RVA: 0x24CE30
void __fastcall mPARAMETER(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  if ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x41
    || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x5A )
  {
    ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 4;
    ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    ctx->pLexer->recover(ctx->pLexer);
  }
  else
  {
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
    mLABEL(ctx);
    state = ctx->pLexer->rec->state;
    if ( state->error != 1 )
      state->type = 32;
  }
}

// File Line: 2375
// RVA: 0x24BF30
void __fastcall mARGUMENT(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 35u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 7;
}

// File Line: 2416
// RVA: 0x24C070
void __fastcall mDIGIT(UELLexer_Ctx_struct *ctx)
{
  if ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x30
    || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x39 )
  {
    ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 4;
    ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    ctx->pLexer->recover(ctx->pLexer);
  }
  else
  {
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
  }
}

// File Line: 2463
// RVA: 0x24C770
void __fastcall mINTEGER(UELLexer_Ctx_struct *ctx)
{
  int i; // edi
  unsigned int v3; // eax
  int v4; // ecx
  bool v5; // cc
  ANTLR3_LEXER_struct *pLexer; // rax

  for ( i = 0; ; ++i )
  {
    v3 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
    v4 = 2;
    v5 = v3 - 48 <= 9;
    pLexer = ctx->pLexer;
    if ( v5 )
      v4 = 1;
    if ( v4 != 1 )
      break;
    if ( pLexer->input->istream->_LA(pLexer->input->istream, 1) < 0x30
      || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x39 )
    {
      ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
      ctx->pLexer->rec->state->exception->type = 4;
      ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      ctx->pLexer->recover(ctx->pLexer);
      return;
    }
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
  }
  if ( i < 1 )
  {
    pLexer->rec->exConstruct(pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 5;
    ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.EarlyExitException";
  }
  else
  {
    pLexer->rec->state->type = 21;
  }
}

// File Line: 2566
// RVA: 0x24CF40
void __fastcall mREAL(UELLexer_Ctx_struct *ctx)
{
  int v1; // esi
  int i; // edi
  unsigned int v4; // eax
  int v5; // ecx
  bool v6; // cc
  ANTLR3_LEXER_struct *pLexer; // rax
  unsigned int v8; // eax
  int v9; // ecx

  v1 = 0;
  for ( i = 0; ; ++i )
  {
    v4 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
    v5 = 2;
    v6 = v4 - 48 <= 9;
    pLexer = ctx->pLexer;
    if ( v6 )
      v5 = 1;
    if ( v5 != 1 )
      break;
    if ( pLexer->input->istream->_LA(pLexer->input->istream, 1) < 0x30
      || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x39 )
    {
LABEL_16:
      ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
      ctx->pLexer->rec->state->exception->type = 4;
      ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      ctx->pLexer->recover(ctx->pLexer);
      return;
    }
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
  }
  if ( i < 1 )
    goto LABEL_19;
  pLexer->matchc(ctx->pLexer, 46u);
  if ( ctx->pLexer->rec->state->error == 1 )
    return;
  while ( 1 )
  {
    v8 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
    v9 = 2;
    v6 = v8 - 48 <= 9;
    pLexer = ctx->pLexer;
    if ( v6 )
      v9 = 1;
    if ( v9 != 1 )
      break;
    if ( pLexer->input->istream->_LA(pLexer->input->istream, 1) < 0x30
      || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x39 )
    {
      goto LABEL_16;
    }
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
    ++v1;
  }
  if ( v1 < 1 )
  {
LABEL_19:
    pLexer->rec->exConstruct(pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 5;
    ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.EarlyExitException";
  }
  else
  {
    pLexer->rec->state->type = 35;
  }
}

// File Line: 2745
// RVA: 0x24BF70
void __fastcall mBOOLEAN(UELLexer_Ctx_struct *ctx)
{
  int v2; // ebx
  unsigned int v3; // eax
  int v4; // ebx
  unsigned int *v5; // rdx

  v2 = 1;
  v3 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
  if ( v3 == 102 )
  {
    v2 = 2;
  }
  else if ( v3 != 116 )
  {
    ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 3;
    ctx->pLexer->rec->state->exception->message = &customCaption;
    ctx->pLexer->rec->state->exception->decisionNum = 7;
    ctx->pLexer->rec->state->exception->state = 0;
    return;
  }
  v4 = v2 - 1;
  if ( !v4 )
  {
    v5 = lit_15;
LABEL_9:
    ctx->pLexer->matchs(ctx->pLexer, v5);
    if ( ctx->pLexer->rec->state->error == 1 )
      return;
    goto LABEL_10;
  }
  if ( v4 == 1 )
  {
    v5 = lit_16;
    goto LABEL_9;
  }
LABEL_10:
  ctx->pLexer->rec->state->type = 8;
}

// File Line: 2839
// RVA: 0x24C510
void __fastcall mFUNCTION(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  if ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x61
    || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x7A )
  {
    ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 4;
    ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    ctx->pLexer->recover(ctx->pLexer);
  }
  else
  {
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
    mLABEL(ctx);
    state = ctx->pLexer->rec->state;
    if ( state->error != 1 )
      state->type = 17;
  }
}

// File Line: 2897
// RVA: 0x24C4D0
void __fastcall mFRAGMENT(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 94u);
  state = ctx->pLexer->rec->state;
  if ( state->error != 1 )
    state->type = 16;
}

// File Line: 2938
// RVA: 0x24BB10
void __fastcall mALL_TEXT_STRING(UELLexer_Ctx_struct *ctx)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ebx

  while ( 1 )
  {
    while ( 1 )
    {
      v2 = 3;
      v3 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
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
      mEscapeSequence(ctx);
      if ( ctx->pLexer->rec->state->error == 1 )
        return;
    }
    if ( v4 != 1 )
      return;
    if ( (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x20
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x21)
      && (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x23
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x5B)
      && (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x5D
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0xFFFF) )
    {
      break;
    }
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
  }
  ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
  ctx->pLexer->rec->state->exception->type = 4;
  ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
  ctx->pLexer->recover(ctx->pLexer);
}

// File Line: 3040
// RVA: 0x24D280
void __fastcall mSTRING(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 34u);
  if ( ctx->pLexer->rec->state->error != 1 )
  {
    mALL_TEXT_STRING(ctx);
    if ( ctx->pLexer->rec->state->error != 1 )
    {
      ctx->pLexer->matchc(ctx->pLexer, 34u);
      state = ctx->pLexer->rec->state;
      if ( state->error != 1 )
        state->type = 39;
    }
  }
}

// File Line: 3097
// RVA: 0x24BCA0
void __fastcall mALL_TEXT_SYMBOL(UELLexer_Ctx_struct *ctx)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ebx

  while ( 1 )
  {
    while ( 1 )
    {
      v2 = 3;
      v3 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
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
      mEscapeSequence(ctx);
      if ( ctx->pLexer->rec->state->error == 1 )
        return;
    }
    if ( v4 != 1 )
      return;
    if ( (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x20
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x26)
      && (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x28
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x5B)
      && (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x5D
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0xFFFF) )
    {
      break;
    }
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
  }
  ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
  ctx->pLexer->rec->state->exception->type = 4;
  ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
  ctx->pLexer->recover(ctx->pLexer);
}

// File Line: 3199
// RVA: 0x24D2F0
void __fastcall mSYMBOL(UELLexer_Ctx_struct *ctx)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchc(ctx->pLexer, 39u);
  if ( ctx->pLexer->rec->state->error != 1 )
  {
    mALL_TEXT_SYMBOL(ctx);
    if ( ctx->pLexer->rec->state->error != 1 )
    {
      ctx->pLexer->matchc(ctx->pLexer, 39u);
      state = ctx->pLexer->rec->state;
      if ( state->error != 1 )
        state->type = 40;
    }
  }
}

// File Line: 3256
// RVA: 0x24C8D0
void __fastcall mLABEL(UELLexer_Ctx_struct *ctx)
{
  int v2; // edi

  while ( 1 )
  {
    v2 = 2;
    switch ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) )
    {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case A:
      case B:
      case C:
      case D:
      case E:
      case F:
      case G:
      case H:
      case I:
      case J:
      case K:
      case L:
      case M:
      case N:
      case O:
      case P:
      case Q:
      case R:
      case S:
      case T:
      case U:
      case V:
      case W:
      case X:
      case Y:
      case Z:
      case _:
      case a:
      case b:
      case c:
      case d:
      case e:
      case f:
      case g:
      case h:
      case i:
      case j:
      case k:
      case l:
      case m:
      case n:
      case o:
      case p:
      case q:
      case r:
      case s:
      case t:
      case u:
      case v:
      case w:
      case x:
      case y:
      case z:
        v2 = 1;
        break;
      default:
        break;
    }
    if ( v2 != 1 )
      break;
    if ( (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x30
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x39)
      && (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x41
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x5A)
      && ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) != 95
      && (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x61
       || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x7A) )
    {
      ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
      ctx->pLexer->rec->state->exception->type = 4;
      ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
      ctx->pLexer->recover(ctx->pLexer);
      return;
    }
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
  }
}

// File Line: 3396
// RVA: 0x24C290
void __fastcall mEscapeSequence(UELLexer_Ctx_struct *ctx)
{
  int v2; // edi

  ctx->pLexer->matchc(ctx->pLexer, 92u);
  if ( ctx->pLexer->rec->state->error != 1 )
  {
    v2 = 1;
    switch ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) )
    {
      case \:
        v2 = 4;
        goto $LN30_6;
      case \\:
        v2 = 5;
        goto $LN30_6;
      case n:
        goto $LN30_6;
      case r:
        v2 = 2;
        goto $LN30_6;
      case t:
        v2 = 3;
        goto $LN30_6;
      case u:
        v2 = 6;
$LN30_6:
        switch ( v2 )
        {
          case 1:
            ctx->pLexer->matchc(ctx->pLexer, 110u);
            break;
          case 2:
            ctx->pLexer->matchc(ctx->pLexer, 114u);
            break;
          case 3:
            ctx->pLexer->matchc(ctx->pLexer, 116u);
            break;
          case 4:
            ctx->pLexer->matchc(ctx->pLexer, 39u);
            break;
          case 5:
            ctx->pLexer->matchc(ctx->pLexer, 92u);
            break;
          case 6:
            mUnicodeEscape(ctx);
            break;
          default:
            return;
        }
        break;
      default:
        ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
        ctx->pLexer->rec->state->exception->type = 3;
        ctx->pLexer->rec->state->exception->message = &customCaption;
        ctx->pLexer->rec->state->exception->decisionNum = 11;
        ctx->pLexer->rec->state->exception->state = 0;
        break;
    }
  }
}

// File Line: 3563
// RVA: 0x24DAC0
void __fastcall mUnicodeEscape(UELLexer_Ctx_struct *ctx)
{
  ctx->pLexer->matchc(ctx->pLexer, 117u);
  if ( ctx->pLexer->rec->state->error != 1 )
  {
    mHexDigit(ctx);
    if ( ctx->pLexer->rec->state->error != 1 )
    {
      mHexDigit(ctx);
      if ( ctx->pLexer->rec->state->error != 1 )
      {
        mHexDigit(ctx);
        if ( ctx->pLexer->rec->state->error != 1 )
          mHexDigit(ctx);
      }
    }
  }
}

// File Line: 3638
// RVA: 0x24C660
void __fastcall mHexDigit(UELLexer_Ctx_struct *ctx)
{
  if ( (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x30
     || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x39)
    && (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x41
     || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x46)
    && (ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) < 0x61
     || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) > 0x66) )
  {
    ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 4;
    ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    ctx->pLexer->recover(ctx->pLexer);
  }
  else
  {
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
  }
}

// File Line: 3685
// RVA: 0x24D1A0
void __fastcall mSL_COMMENT(UELLexer_Ctx_struct *ctx)
{
  int v2; // ebx
  unsigned int v3; // eax
  ANTLR3_LEXER_struct *pLexer; // rax
  ANTLR3_LEXER_struct *v5; // rcx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchs(ctx->pLexer, lit_17);
  if ( ctx->pLexer->rec->state->error != 1 )
  {
    while ( 1 )
    {
      v2 = 2;
      v3 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
      if ( v3 != 10 && (v3 <= 9 || v3 - 11 <= 0xFFF4) )
        v2 = 1;
      pLexer = ctx->pLexer;
      v5 = ctx->pLexer;
      if ( v2 != 1 )
        break;
      pLexer->matchAny(v5);
      if ( ctx->pLexer->rec->state->error == 1 )
        return;
    }
    pLexer->matchc(v5, 10u);
    state = ctx->pLexer->rec->state;
    if ( state->error != 1 )
    {
      state->channel = 99;
      ctx->pLexer->rec->state->type = 38;
    }
  }
}

// File Line: 3788
// RVA: 0x24CB70
void __fastcall mML_COMMENT(UELLexer_Ctx_struct *ctx)
{
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // eax
  bool v5; // cc
  ANTLR3_LEXER_struct *pLexer; // rax
  ANTLR3_LEXER_struct *v7; // rcx
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  ctx->pLexer->matchs(ctx->pLexer, lit_18);
  while ( ctx->pLexer->rec->state->error != 1 )
  {
    v2 = 2;
    v3 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1);
    if ( v3 == 42 )
    {
      v4 = ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 2);
      if ( v4 == 47 )
        goto LABEL_10;
      if ( v4 > 0x2E )
      {
        v5 = v4 - 48 <= 0xFFCF;
        goto LABEL_8;
      }
    }
    else if ( v3 > 0x29 )
    {
      v5 = v3 - 43 <= 0xFFD4;
LABEL_8:
      if ( !v5 )
        goto LABEL_10;
    }
    v2 = 1;
LABEL_10:
    pLexer = ctx->pLexer;
    v7 = ctx->pLexer;
    if ( v2 != 1 )
    {
      pLexer->matchs(v7, lit_19);
      state = ctx->pLexer->rec->state;
      if ( state->error != 1 )
      {
        state->channel = 99;
        ctx->pLexer->rec->state->type = 26;
      }
      return;
    }
    pLexer->matchAny(v7);
  }
}

// File Line: 3906
// RVA: 0x24DB50
void __fastcall mWS(UELLexer_Ctx_struct *ctx)
{
  if ( ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) >= 9
    && ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) <= 0xA
    || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) >= 0xC
    && ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) <= 0xD
    || ctx->pLexer->input->istream->_LA(ctx->pLexer->input->istream, 1) == 32 )
  {
    ctx->pLexer->input->istream->consume(ctx->pLexer->input->istream);
    ctx->pLexer->rec->state->channel = 99;
    ctx->pLexer->rec->state->type = 43;
  }
  else
  {
    ctx->pLexer->rec->exConstruct(ctx->pLexer->rec);
    ctx->pLexer->rec->state->exception->type = 4;
    ctx->pLexer->rec->state->exception->name = "org.antlr.runtime.MismatchedSetException";
    ctx->pLexer->recover(ctx->pLexer);
  }
}

// File Line: 3951
// RVA: 0x24D7E0
void __fastcall mTokens(UELLexer_Ctx_struct *ctx)
{
  int v2; // eax

  v2 = cdfa14.predict(ctx, ctx->pLexer->rec, ctx->pLexer->input->istream, &cdfa14);
  if ( ctx->pLexer->rec->state->error != 1 )
  {
    switch ( v2 )
    {
      case 1:
        mT__44(ctx);
        break;
      case 2:
        mT__45(ctx);
        break;
      case 3:
        mT__46(ctx);
        break;
      case 4:
        mT__47(ctx);
        break;
      case 5:
        mT__48(ctx);
        break;
      case 6:
        mT__49(ctx);
        break;
      case 7:
        mT__50(ctx);
        break;
      case 8:
        mT__51(ctx);
        break;
      case 9:
        mENUMERATION(ctx);
        break;
      case 10:
        mSCOPE(ctx);
        break;
      case 11:
        mTYPE(ctx);
        break;
      case 12:
        mOR(ctx);
        break;
      case 13:
        mAND(ctx);
        break;
      case 14:
        mEQUALS(ctx);
        break;
      case 15:
        mNOTEQUALS(ctx);
        break;
      case 16:
        mLTH(ctx);
        break;
      case 17:
        mLTEQ(ctx);
        break;
      case 18:
        mGTH(ctx);
        break;
      case 19:
        mGTEQ(ctx);
        break;
      case 20:
        mPLUS(ctx);
        break;
      case 21:
        mMINUS(ctx);
        break;
      case 22:
        mMULT(ctx);
        break;
      case 23:
        mDIV(ctx);
        break;
      case 24:
        mNOT(ctx);
        break;
      case 25:
        mREFERENCE(ctx);
        break;
      case 26:
        mPARAMETER(ctx);
        break;
      case 27:
        mARGUMENT(ctx);
        break;
      case 28:
        mINTEGER(ctx);
        break;
      case 29:
        mREAL(ctx);
        break;
      case 30:
        mBOOLEAN(ctx);
        break;
      case 31:
        mFUNCTION(ctx);
        break;
      case 32:
        mFRAGMENT(ctx);
        break;
      case 33:
        mSTRING(ctx);
        break;
      case 34:
        mSYMBOL(ctx);
        break;
      case 35:
        mSL_COMMENT(ctx);
        break;
      case 36:
        mML_COMMENT(ctx);
        break;
      case 37:
        mWS(ctx);
        break;
      default:
        return;
    }
  }
}

