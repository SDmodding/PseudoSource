// File Line: 366
// RVA: 0x12CCB58
void __fastcall raise_exc_ex(
        _FPIEEE_RECORD *prec,
        unsigned __int64 *pcw,
        char flags,
        __int16 opcode,
        _DWORD *parg1,
        _DWORD *presult,
        int isfloat)
{
  DWORD v9; // edi
  char v10; // al
  __int64 v11; // rax
  _DWORD *v12; // rsi
  ULONG_PTR v13; // rcx
  ULONG_PTR Arguments; // [rsp+30h] [rbp+10h] BYREF

  Arguments = (ULONG_PTR)prec;
  prec->Cause = 0;
  *(_DWORD *)(Arguments + 8) = 0;
  *(_DWORD *)(Arguments + 12) = 0;
  if ( (flags & 0x10) != 0 )
  {
    v9 = -1073741681;
    *(_DWORD *)(Arguments + 4) |= 1u;
  }
  else
  {
    v9 = isfloat;
  }
  if ( (flags & 2) != 0 )
  {
    v9 = -1073741677;
    *(_DWORD *)(Arguments + 4) |= 2u;
  }
  if ( (flags & 1) != 0 )
  {
    v9 = -1073741679;
    *(_DWORD *)(Arguments + 4) |= 4u;
  }
  if ( (flags & 4) != 0 )
  {
    v9 = -1073741682;
    *(_DWORD *)(Arguments + 4) |= 8u;
  }
  if ( (flags & 8) != 0 )
  {
    v9 = -1073741680;
    *(_DWORD *)(Arguments + 4) |= 0x10u;
  }
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(16 * (*pcw >> 7))) & 0x10;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(8 * (*pcw >> 9))) & 8;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(4 * (*pcw >> 10))) & 4;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(2 * (*pcw >> 11))) & 2;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*(_DWORD *)pcw >> 12)) & 1;
  v10 = statfp();
  if ( (v10 & 1) != 0 )
    *(_DWORD *)(Arguments + 12) |= 0x10u;
  if ( (v10 & 4) != 0 )
    *(_DWORD *)(Arguments + 12) |= 8u;
  if ( (v10 & 8) != 0 )
    *(_DWORD *)(Arguments + 12) |= 4u;
  if ( (v10 & 0x10) != 0 )
    *(_DWORD *)(Arguments + 12) |= 2u;
  if ( (v10 & 0x20) != 0 )
    *(_DWORD *)(Arguments + 12) |= 1u;
  v11 = *(_DWORD *)pcw & 0x6000i64;
  if ( v11 )
  {
    switch ( v11 )
    {
      case 8192i64:
        *(_DWORD *)Arguments &= ~2u;
        *(_DWORD *)Arguments |= 1u;
        break;
      case 16384i64:
        *(_DWORD *)Arguments &= ~1u;
        *(_DWORD *)Arguments |= 2u;
        break;
      case 24576i64:
        *(_DWORD *)Arguments |= 3u;
        break;
    }
  }
  else
  {
    *(_DWORD *)Arguments &= 0xFFFFFFFC;
  }
  *(_DWORD *)Arguments &= 0xFFFE001F;
  *(_DWORD *)Arguments |= 32 * (opcode & 0xFFF);
  v12 = presult;
  *(_DWORD *)(Arguments + 32) |= 1u;
  if ( isfloat )
  {
    *(_DWORD *)(Arguments + 32) &= 0xFFFFFFE1;
    *(_DWORD *)(Arguments + 16) = *parg1;
    *(_DWORD *)(Arguments + 96) |= 1u;
    *(_DWORD *)(Arguments + 96) &= 0xFFFFFFE1;
    *(_DWORD *)(Arguments + 80) = *v12;
  }
  else
  {
    *(_DWORD *)(Arguments + 32) = *(_DWORD *)(Arguments + 32) & 0xFFFFFFE1 | 2;
    *(_QWORD *)(Arguments + 16) = *(_QWORD *)parg1;
    *(_DWORD *)(Arguments + 96) |= 1u;
    *(_DWORD *)(Arguments + 96) = *(_DWORD *)(Arguments + 96) & 0xFFFFFFE1 | 2;
    *(_QWORD *)(Arguments + 80) = *(_QWORD *)v12;
  }
  clrfp();
  RaiseException(v9, 0, 1u, &Arguments);
  v13 = Arguments;
  if ( (*(_BYTE *)(Arguments + 8) & 0x10) != 0 )
    *pcw &= ~0x80ui64;
  if ( (*(_BYTE *)(v13 + 8) & 8) != 0 )
    *pcw &= ~0x200ui64;
  if ( (*(_BYTE *)(v13 + 8) & 4) != 0 )
    *pcw &= ~0x400ui64;
  if ( (*(_BYTE *)(v13 + 8) & 2) != 0 )
    *pcw &= ~0x800ui64;
  if ( (*(_BYTE *)(v13 + 8) & 1) != 0 )
    *pcw &= ~0x1000ui64;
  if ( (*(_DWORD *)v13 & 3) != 0 )
  {
    switch ( *(_DWORD *)v13 & 3 )
    {
      case 1:
        *pcw &= ~0x4000ui64;
        *pcw |= 0x2000ui64;
        break;
      case 2:
        *pcw &= ~0x2000ui64;
        *pcw |= 0x4000ui64;
        break;
      case 3:
        *pcw |= 0x6000ui64;
        break;
    }
  }
  else
  {
    *pcw &= 0xFFFFFFFFFFFF9FFFui64;
  }
  if ( isfloat )
    *v12 = *(_DWORD *)(v13 + 80);
  else
    *(_QWORD *)v12 = *(_QWORD *)(v13 + 80);
}

// File Line: 581
// RVA: 0x12CCB30
void __fastcall raise_exc(
        _FPIEEE_RECORD *prec,
        unsigned __int64 *pcw,
        int flags,
        int opcode,
        long double *parg1,
        long double *presult)
{
  raise_exc_ex(prec, pcw, flags, opcode, parg1, presult, 0);
}

// File Line: 590
// RVA: 0x12CCE5C
void __fastcall raise_excf(
        _FPIEEE_RECORD *prec,
        unsigned __int64 *pcw,
        char flags,
        __int16 opcode,
        float *parg1,
        float *presult)
{
  raise_exc_ex(prec, pcw, flags, opcode, parg1, presult, 1);
}

// File Line: 849
// RVA: 0x12CCE88
void __fastcall set_errno_from_matherr(int matherrtype)
{
  if ( matherrtype == 1 )
  {
    *errno() = 33;
  }
  else if ( (unsigned int)(matherrtype - 2) <= 1 )
  {
    *errno() = 34;
  }
}

