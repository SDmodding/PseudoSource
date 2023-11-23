// File Line: 50
// RVA: 0x25C8B0
void __fastcall noViableAlt(ANTLR3_BASE_RECOGNIZER_struct *rec, ANTLR3_CYCLIC_DFA_struct *cdfa, unsigned int s)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *state; // rax

  state = rec->state;
  if ( state->backtracking <= 0 )
  {
    ((void (*)(void))rec->exConstruct)();
    rec->state->exception->type = 3;
    rec->state->exception->message = cdfa->description;
    rec->state->exception->decisionNum = cdfa->decisionNumber;
    rec->state->exception->state = s;
  }
  else
  {
    state->failed = 1;
  }
}

// File Line: 76
// RVA: 0x25C940
__int64 __fastcall antlr3dfapredict(
        void *ctx,
        ANTLR3_BASE_RECOGNIZER_struct *rec,
        ANTLR3_INT_STREAM_struct *is,
        ANTLR3_CYCLIC_DFA_struct *cdfa)
{
  __int64 v8; // r15
  signed int v9; // esi
  int v10; // edx
  int v11; // eax
  __int64 v12; // r8
  int v13; // ecx
  __int64 v15; // rcx

  v8 = is->mark(is);
  v9 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v10 = cdfa->special[v9];
      if ( v10 < 0 )
        break;
      v9 = cdfa->specialStateTransition(ctx, rec, is, cdfa, v10);
      if ( v9 < 0 )
      {
        if ( rec->state->error == 1 )
        {
LABEL_15:
          is->rewind(is, v8);
          return 0i64;
        }
LABEL_14:
        noViableAlt(rec, cdfa, v9);
        goto LABEL_15;
      }
      is->consume(is);
    }
    if ( cdfa->accept[v9] >= 1 )
    {
      is->rewind(is, v8);
      v15 = v9;
      return (unsigned int)cdfa->accept[v15];
    }
    v11 = is->_LA(is, 1);
    v12 = cdfa->min[v9];
    if ( v11 < (int)v12 || v11 > cdfa->max[v9] )
      break;
    v13 = cdfa->transition[v9][v11 - v12];
    if ( v13 < 0 )
    {
      v13 = cdfa->eot[v9];
      if ( v13 < 0 )
        goto LABEL_14;
    }
LABEL_10:
    v9 = v13;
    is->consume(is);
  }
  v13 = cdfa->eot[v9];
  if ( v13 >= 0 )
    goto LABEL_10;
  if ( v11 != -1 || cdfa->eof[v9] < 0 )
    goto LABEL_14;
  is->rewind(is, v8);
  v15 = cdfa->eof[v9];
  return (unsigned int)cdfa->accept[v15];
}

