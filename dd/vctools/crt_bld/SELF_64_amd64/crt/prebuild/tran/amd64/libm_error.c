// File Line: 38
// RVA: 0x12C6F28
long double __fastcall call_matherr(
        int type,
        int error,
        char *name,
        long double arg1,
        long double arg2,
        long double retval,
        unsigned __int64 cw)
{
  _exception pexcept; // [rsp+20h] [rbp-38h] BYREF

  pexcept.type = type;
  pexcept.arg1 = arg1;
  pexcept.arg2 = arg2;
  pexcept.retval = retval;
  pexcept.name = name;
  ctrlfp(cw, 0xFFC0ui64);
  if ( !(unsigned int)OSuite::FComputeHashBegin(&pexcept) )
    set_errno_from_matherr(type);
  return pexcept.retval;
}

// File Line: 54
// RVA: 0x12C6F90
_BOOL8 __fastcall exception_enabled(char flags, unsigned __int64 cw)
{
  __int16 v2; // si
  int v4; // ebx

  v2 = cw;
  v4 = flags & 0x1F;
  if ( (flags & 8) != 0 && (cw & 0x80u) != 0i64 )
  {
    set_statfp(1ui64);
    v4 &= ~8u;
  }
  else if ( (flags & 4) != 0 && (cw & 0x200) != 0 )
  {
    set_statfp(4ui64);
    v4 &= ~4u;
  }
  else if ( (flags & 1) != 0 && (cw & 0x400) != 0 )
  {
    set_statfp(8ui64);
    v4 &= ~1u;
  }
  else if ( (flags & 2) != 0 && (cw & 0x800) != 0 )
  {
    if ( (flags & 0x10) != 0 )
      set_statfp(0x10ui64);
    v4 &= ~2u;
  }
  if ( (flags & 0x10) != 0 && (v2 & 0x1000) != 0 )
  {
    set_statfp(0x20ui64);
    v4 &= ~0x10u;
  }
  return v4 == 0;
}

// File Line: 133
// RVA: 0x12C7174
float __fastcall handle_errorf(char *fname, int opcode, unsigned __int64 value, int type)
{
  float v7; // ebx
  BOOL v8; // eax
  float v9; // xmm6_4
  float presult; // [rsp+40h] [rbp-79h] BYREF
  unsigned __int64 cw; // [rsp+48h] [rbp-71h] BYREF
  float v13; // [rsp+50h] [rbp-69h]
  _FPIEEE_RECORD prec; // [rsp+60h] [rbp-59h] BYREF
  void *retaddr; // [rsp+118h] [rbp+5Fh]
  int v16; // [rsp+120h] [rbp+67h]
  float parg1; // [rsp+128h] [rbp+6Fh] BYREF
  _FPIEEE_EXCEPTION_FLAGS v18; // [rsp+130h] [rbp+77h]
  int v19; // [rsp+138h] [rbp+7Fh]

  v7 = *(float *)&value;
  cw = ctrlfp(0x1F80ui64, 0xFFC0ui64);
  v13 = v7;
  presult = v7;
  v8 = exception_enabled((char)retaddr, cw);
  v9 = *(float *)&v18;
  if ( !v8 )
  {
    if ( v19 == 2 )
    {
      prec.Enable = v18;
      prec.Operand1.Value.Fp128Value.W[2] = prec.Operand1.Value.Fp128Value.W[2] & 0xFFFFFFE0 | 1;
    }
    raise_excf(&prec, &cw, (int)retaddr, opcode, &parg1, &presult);
  }
  if ( !matherr_flag && type )
    return call_matherr(type, v16, fname, parg1, v9, presult, cw);
  set_errno_from_matherr(type);
  ctrlfp(cw, 0xFFC0ui64);
  return presult;
}

// File Line: 182
// RVA: 0x12C704C
long double __fastcall handle_error(char *fname, int opcode, unsigned __int64 value, int type)
{
  BOOL v8; // eax
  long double v9; // xmm6_8
  unsigned __int64 cw; // [rsp+40h] [rbp-79h] BYREF
  long double retval[3]; // [rsp+48h] [rbp-71h] BYREF
  _FPIEEE_RECORD prec; // [rsp+60h] [rbp-59h] BYREF
  void *retaddr; // [rsp+118h] [rbp+5Fh]
  int v15; // [rsp+120h] [rbp+67h]
  long double parg1; // [rsp+128h] [rbp+6Fh] BYREF
  long double v17; // [rsp+130h] [rbp+77h]
  int v18; // [rsp+138h] [rbp+7Fh]

  cw = ctrlfp(0x1F80ui64, 0xFFC0ui64);
  *(_QWORD *)&retval[1] = value;
  *(_QWORD *)&retval[0] = value;
  v8 = exception_enabled((char)retaddr, cw);
  v9 = v17;
  if ( !v8 )
  {
    if ( v18 == 2 )
    {
      *(long double *)&prec.Enable = v17;
      prec.Operand1.Value.Fp128Value.W[2] = prec.Operand1.Value.Fp128Value.W[2] & 0xFFFFFFE0 | 3;
    }
    raise_exc(&prec, &cw, (int)retaddr, opcode, &parg1, retval);
  }
  if ( !matherr_flag && type )
    return call_matherr(type, v15, fname, parg1, v9, retval[0], cw);
  set_errno_from_matherr(type);
  ctrlfp(cw, 0xFFC0ui64);
  return retval[0];
}

