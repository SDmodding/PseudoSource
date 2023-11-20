// File Line: 57
// RVA: 0x12CD540
void __fastcall initp_misc_winsig(void *enull)
{
  ctrlc_action = enull;
  ctrlbreak_action = (void (__fastcall *)(int))enull;
  abort_action = (void (__fastcall *)(int))enull;
  term_action = (void (__fastcall *)(int))enull;
}

// File Line: 450
// RVA: 0x12CD560
signed __int64 __fastcall raise(int signum)
{
  unsigned int v1; // ebx
  signed int v2; // edi
  _tiddata *v3; // rsi
  void (__fastcall **v4)(int); // r14
  void (__fastcall *v5)(int); // rcx
  _tiddata *v6; // rax
  void *v8; // rdx
  unsigned __int64 v9; // rcx
  __int64 v10; // r8
  void (__fastcall *v11)(signed __int64, __int64, __int64); // r15
  signed int v12; // er12
  int v13; // ecx
  __int64 v14; // rdx
  void *v15; // [rsp+28h] [rbp-30h]
  int v16; // [rsp+68h] [rbp+10h]

  v1 = signum;
  v2 = 0;
  v3 = 0i64;
  if ( signum == 2 )
  {
    v4 = (void (__fastcall **)(int))&ctrlc_action;
    v5 = (void (__fastcall *)(int))ctrlc_action;
    goto LABEL_23;
  }
  if ( signum != 4 )
  {
    if ( signum == 6 )
    {
LABEL_12:
      v4 = &abort_action;
      v5 = abort_action;
      goto LABEL_23;
    }
    if ( signum != 8 && signum != 11 )
    {
      switch ( signum )
      {
        case 15:
          v4 = &term_action;
          v5 = term_action;
          break;
        case 21:
          v4 = &ctrlbreak_action;
          v5 = ctrlbreak_action;
          break;
        case 22:
          goto LABEL_12;
        default:
          *errno() = 22;
          invalid_parameter_noinfo();
          return 0xFFFFFFFFi64;
      }
LABEL_23:
      v2 = 1;
      v11 = (void (__fastcall *)(signed __int64, __int64, __int64))DecodePointer(v5);
      goto $decode_done;
    }
  }
  v6 = getptd_noexit();
  v3 = v6;
  if ( !v6 )
    return 0xFFFFFFFFi64;
  v8 = v6->_pxcptacttab;
  v9 = (unsigned __int64)v6->_pxcptacttab;
  v10 = XcptActTabCount;
  do
  {
    if ( *(_DWORD *)(v9 + 4) == v1 )
      break;
    v9 += 16i64;
  }
  while ( v9 < (unsigned __int64)v8 + 16 * XcptActTabCount );
  if ( v9 >= (unsigned __int64)v8 + 16 * XcptActTabCount || *(_DWORD *)(v9 + 4) != v1 )
    v9 = 0i64;
  v4 = (void (__fastcall **)(int))(v9 + 8);
  v11 = *(void (__fastcall **)(signed __int64, __int64, __int64))(v9 + 8);
$decode_done:
  if ( v11 != (void (__fastcall *)(signed __int64, __int64, __int64))1 )
  {
    if ( !v11 )
      exit(3);
    if ( v2 )
      lock(0);
    v12 = 2320;
    if ( v1 <= 0xB && _bittest(&v12, v1) )
    {
      v15 = v3->_tpxcptinfoptrs;
      v3->_tpxcptinfoptrs = 0i64;
      if ( v1 != 8 )
        goto LABEL_38;
      v16 = v3->_tfpecode;
      v3->_tfpecode = 140;
    }
    if ( v1 == 8 )
    {
      v13 = First_FPE_Indx;
      v14 = (unsigned int)First_FPE_Indx;
      while ( (signed int)v14 < Num_FPE + v13 )
      {
        *((_QWORD *)v3->_pxcptacttab + 2 * (signed int)v14 + 1) = 0i64;
        v14 = (unsigned int)(v14 + 1);
        v13 = First_FPE_Indx;
      }
      goto $LN38_31;
    }
LABEL_38:
    *v4 = (void (__fastcall *)(int))EncodePointer(0i64);
$LN38_31:
    if ( v2 )
      unlock(0);
    if ( v1 == 8 )
      v11(8i64, (unsigned int)v3->_tfpecode, v10);
    else
      v11(v1, v14, v10);
    if ( v1 <= 0xB && _bittest(&v12, v1) )
    {
      v3->_tpxcptinfoptrs = v15;
      if ( v1 == 8 )
        v3->_tfpecode = v16;
    }
  }
  return 0i64;
}

// File Line: 573
// RVA: 0x14522B6
raise$fin$0

// File Line: 669
// RVA: 0x12CD530
void (__fastcall *__fastcall _get_sigabrt())(int)
{
  return (void (__fastcall *)(int))DecodePointer(abort_action);
}

