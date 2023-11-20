// File Line: 50
// RVA: 0x25C8B0
void __fastcall noViableAlt(ANTLR3_BASE_RECOGNIZER_struct *rec, ANTLR3_CYCLIC_DFA_struct *cdfa, unsigned int s)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v3; // rax
  unsigned int v4; // esi
  ANTLR3_CYCLIC_DFA_struct *v5; // rdi
  ANTLR3_BASE_RECOGNIZER_struct *v6; // rbx

  v3 = rec->state;
  v4 = s;
  v5 = cdfa;
  v6 = rec;
  if ( v3->backtracking <= 0 )
  {
    ((void (*)(void))rec->exConstruct)();
    v6->state->exception->type = 3;
    v6->state->exception->message = v5->description;
    v6->state->exception->decisionNum = v5->decisionNumber;
    v6->state->exception->state = v4;
  }
  else
  {
    v3->failed = 1;
  }
}

// File Line: 76
// RVA: 0x25C940
__int64 __fastcall antlr3dfapredict(void *ctx, ANTLR3_BASE_RECOGNIZER_struct *rec, ANTLR3_INT_STREAM_struct *is, ANTLR3_CYCLIC_DFA_struct *cdfa)
{
  void *v4; // r12
  ANTLR3_CYCLIC_DFA_struct *v5; // rdi
  ANTLR3_INT_STREAM_struct *v6; // rbx
  ANTLR3_BASE_RECOGNIZER_struct *v7; // r14
  __int64 v8; // r15
  signed int v9; // esi
  signed int v10; // eax
  __int64 v11; // r8
  signed int v12; // ecx
  signed __int64 v14; // rbp
  __int64 v15; // rcx
  _QWORD v16[5]; // [rsp+20h] [rbp-28h]

  v4 = ctx;
  v5 = cdfa;
  v6 = is;
  v7 = rec;
  v8 = is->mark(is);
  v9 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( v5->special[v9] >= 0 )
      {
        LODWORD(v16[0]) = v5->special[v9];
        v9 = v5->specialStateTransition(v4, v7, v6, v5, v16[0]);
        if ( v9 < 0 )
        {
          if ( v7->state->error == 1 )
          {
LABEL_15:
            v6->rewind(v6, v8);
            return 0i64;
          }
LABEL_14:
          noViableAlt(v7, v5, v9);
          goto LABEL_15;
        }
        v6->consume(v6);
      }
      if ( v5->accept[v9] >= 1 )
      {
        v6->rewind(v6, v8);
        v15 = v9;
        return (unsigned int)v5->accept[v15];
      }
      v10 = v6->_LA(v6, 1);
      v11 = v5->min[v9];
      if ( v10 < (signed int)v11 || v10 > v5->max[v9] )
        break;
      v12 = v5->transition[v9][v10 - v11];
      if ( v12 >= 0 )
        goto LABEL_12;
      if ( v5->eot[v9] < 0 )
        goto LABEL_14;
      v9 = v5->eot[v9];
      v6->consume(v6);
    }
    v12 = v5->eot[v9];
    if ( v12 < 0 )
      break;
LABEL_12:
    v9 = v12;
    v6->consume(v6);
  }
  if ( v10 != -1 )
    goto LABEL_14;
  v14 = v9;
  if ( v5->eof[v14] < 0 )
    goto LABEL_14;
  v6->rewind(v6, v8);
  v15 = v5->eof[v14];
  return (unsigned int)v5->accept[v15];
}

