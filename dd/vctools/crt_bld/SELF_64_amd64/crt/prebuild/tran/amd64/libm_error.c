// File Line: 38
// RVA: 0x12C6F28
long double __fastcall call_matherr(int type, int error, char *name, long double arg1, long double arg2, long double retval, unsigned __int64 cw)
{
  int v7; // ebx
  _exception pexcept; // [rsp+20h] [rbp-38h]

  v7 = type;
  pexcept.type = type;
  pexcept.arg1 = arg1;
  pexcept.arg2 = arg2;
  pexcept.retval = retval;
  pexcept.name = name;
  ctrlfp(cw, 0xFFC0ui64);
  if ( !(unsigned int)OSuite::FComputeHashBegin(&pexcept) )
    set_errno_from_matherr(v7);
  return pexcept.retval;
}

// File Line: 54
// RVA: 0x12C6F90
_BOOL8 __fastcall exception_enabled(unsigned int flags, unsigned __int64 cw)
{
  unsigned __int64 v2; // rsi
  char v3; // di
  unsigned int v4; // ebx

  v2 = cw;
  v3 = flags;
  v4 = flags & 0x1F;
  if ( flags & 8 && (cw & 0x80u) != 0i64 )
  {
    set_statfp(1ui64);
    v4 &= 0xFFFFFFF7;
  }
  else if ( flags & 4 && _bittest64((const signed __int64 *)&cw, 9u) )
  {
    set_statfp(4ui64);
    v4 &= 0xFFFFFFFB;
  }
  else if ( flags & 1 && _bittest64((const signed __int64 *)&cw, 0xAu) )
  {
    set_statfp(8ui64);
    v4 &= 0xFFFFFFFE;
  }
  else if ( flags & 2 && _bittest64((const signed __int64 *)&cw, 0xBu) )
  {
    if ( flags & 0x10 )
      set_statfp(0x10ui64);
    v4 &= 0xFFFFFFFD;
  }
  if ( v3 & 0x10 && _bittest64((const signed __int64 *)&v2, 0xCu) )
  {
    set_statfp(0x20ui64);
    v4 &= 0xFFFFFFEF;
  }
  return v4 == 0;
}

// File Line: 133
// RVA: 0x12C7174
float __fastcall handle_errorf(char *fname, int opcode, unsigned __int64 value, int type)
{
  int v4; // esi
  char *v5; // r14
  int v6; // edi
  float v7; // ebx
  unsigned __int64 v8; // rax
  BOOL v9; // eax
  float v10; // xmm6_4
  float presult; // [rsp+40h] [rbp-79h]
  unsigned __int64 cw; // [rsp+48h] [rbp-71h]
  float v14; // [rsp+50h] [rbp-69h]
  _FPIEEE_RECORD prec; // [rsp+60h] [rbp-59h]
  void *retaddr; // [rsp+118h] [rbp+5Fh]
  int v17; // [rsp+120h] [rbp+67h]
  float parg1; // [rsp+128h] [rbp+6Fh]
  _FPIEEE_EXCEPTION_FLAGS v19; // [rsp+130h] [rbp+77h]
  int v20; // [rsp+138h] [rbp+7Fh]

  v4 = opcode;
  v5 = fname;
  v6 = type;
  v7 = *(float *)&value;
  v8 = ctrlfp(0x1F80ui64, 0xFFC0ui64);
  cw = v8;
  v14 = v7;
  presult = v7;
  v9 = exception_enabled((unsigned int)retaddr, v8);
  v10 = *(float *)&v19;
  if ( !v9 )
  {
    if ( v20 == 2 )
    {
      prec.Enable = v19;
      prec.Operand1.Value.Fp128Value.W[2] = prec.Operand1.Value.Fp128Value.W[2] & 0xFFFFFFE1 | 1;
    }
    raise_excf(&prec, &cw, (int)retaddr, v4, &parg1, &presult);
  }
  if ( !matherr_flag && v6 )
    return call_matherr(v6, v17, v5, parg1, v10, presult, cw);
  set_errno_from_matherr(v6);
  ctrlfp(cw, 0xFFC0ui64);
  return presult;
}

// File Line: 182
// RVA: 0x12C704C
long double __fastcall handle_error(char *fname, int opcode, unsigned __int64 value, int type)
{
  int v4; // esi
  char *v5; // r14
  int v6; // edi
  double v7; // rbx
  unsigned __int64 v8; // rax
  BOOL v9; // eax
  long double v10; // xmm6_8
  unsigned __int64 cw; // [rsp+40h] [rbp-79h]
  long double retval; // [rsp+48h] [rbp-71h]
  double v14; // [rsp+50h] [rbp-69h]
  _FPIEEE_RECORD prec; // [rsp+60h] [rbp-59h]
  void *retaddr; // [rsp+118h] [rbp+5Fh]
  int v17; // [rsp+120h] [rbp+67h]
  long double parg1; // [rsp+128h] [rbp+6Fh]
  long double v19; // [rsp+130h] [rbp+77h]
  int v20; // [rsp+138h] [rbp+7Fh]

  v4 = opcode;
  v5 = fname;
  v6 = type;
  v7 = *(double *)&value;
  v8 = ctrlfp(0x1F80ui64, 0xFFC0ui64);
  cw = v8;
  v14 = v7;
  retval = v7;
  v9 = exception_enabled((unsigned int)retaddr, v8);
  v10 = v19;
  if ( !v9 )
  {
    if ( v20 == 2 )
    {
      *(long double *)&prec.Enable = v19;
      prec.Operand1.Value.Fp128Value.W[2] = prec.Operand1.Value.Fp128Value.W[2] & 0xFFFFFFE3 | 3;
    }
    raise_exc(&prec, &cw, (int)retaddr, v4, &parg1, &retval);
  }
  if ( !matherr_flag && v6 )
    return call_matherr(v6, v17, v5, parg1, v10, retval, cw);
  set_errno_from_matherr(v6);
  ctrlfp(cw, 0xFFC0ui64);
  return retval;
}

