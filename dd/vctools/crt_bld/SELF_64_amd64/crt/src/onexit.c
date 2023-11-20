// File Line: 81
// RVA: 0x12ADB4C
int (__fastcall *__fastcall onexit(int (__fastcall *func)()))()
{
  int (__fastcall *v1)(); // r12
  PVOID *v2; // r14
  PVOID *v3; // rax
  PVOID *v4; // rbx
  signed __int64 v5; // rdi
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rsi
  signed __int64 v9; // rdx
  unsigned __int64 v10; // rdx
  char *v11; // rax
  int (__fastcall *v12)(); // rbx

  v1 = func;
  lockexit();
  v2 = (PVOID *)DecodePointer(_onexitbegin);
  v3 = (PVOID *)DecodePointer(_onexitend);
  v4 = v3;
  if ( v3 < v2
    || (v5 = (char *)v3 - (char *)v2,
        v6 = (char *)v3 - (char *)v2 + 8,
        (unsigned __int64)((char *)v3 - (char *)v2) >= 0xFFFFFFFFFFFFFFF8ui64) )
  {
    v12 = 0i64;
    goto $LN8_202;
  }
  v7 = msize(v2);
  v8 = v7;
  if ( v7 >= v6 )
    goto LABEL_13;
  v9 = 4096i64;
  if ( v7 < 0x1000 )
    v9 = v7;
  v10 = v7 + v9;
  if ( v10 < v7 )
  {
    v12 = 0i64;
  }
  else
  {
    v11 = (char *)realloc_crt(v2, v10);
    v12 = 0i64;
    if ( v11 )
    {
LABEL_12:
      v4 = (PVOID *)&v11[8 * (v5 >> 3)];
      _onexitbegin = EncodePointer(v11);
LABEL_13:
      *v4 = EncodePointer(v1);
      _onexitend = EncodePointer(v4 + 1);
      v12 = v1;
      goto $LN8_202;
    }
  }
  if ( v8 + 32 >= v8 )
  {
    v11 = (char *)realloc_crt(v2, v8 + 32);
    if ( v11 )
      goto LABEL_12;
  }
$LN8_202:
  unlockexit();
  return v12;
}

// File Line: 89
// RVA: 0x1451CD3
_onexit$fin$0

// File Line: 161
// RVA: 0x12ADC58
__int64 __fastcall atexit(void (__fastcall *func)())
{
  return (unsigned int)(onexit((int (__fastcall *)())func) != 0i64) - 1;
}

// File Line: 201
// RVA: 0x12ADB08
signed __int64 __fastcall _onexitinit()
{
  _QWORD *v0; // rbx

  v0 = calloc_crt(0x20ui64, 8ui64);
  _onexitbegin = EncodePointer(v0);
  _onexitend = _onexitbegin;
  if ( !v0 )
    return 24i64;
  *v0 = 0i64;
  return 0i64;
}

