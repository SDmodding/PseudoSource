// File Line: 39
// RVA: 0x12D8E70
void __fastcall _mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  unsigned int v4; // edi
  __int16 v6; // bx
  unsigned int v7; // r11d
  unsigned int v8; // r8d
  int v9; // r9d
  unsigned __int64 v10; // rsi
  int v11; // r15d
  int v12; // r9d
  unsigned int v13; // ecx
  unsigned int v14; // r8d
  int v15; // eax
  int v16; // r9d
  unsigned int v17; // ecx
  unsigned int v18; // r14d
  unsigned int v19; // eax
  int v20; // ecx
  unsigned __int64 v21; // rsi
  int v22; // eax
  unsigned int v23; // r11d
  int v24; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  int v27; // ecx
  unsigned int v28; // r8d
  int v29; // ecx
  unsigned int v30; // r9d
  int v31; // edx
  unsigned int v32; // r9d
  unsigned int v33; // r8d
  unsigned int v34; // ecx

  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  *(_DWORD *)&ld12->ld12[8] = 0;
  v4 = manlen;
  v6 = 16462;
  if ( manlen )
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    do
    {
      v10 = *(_QWORD *)ld12->ld12;
      v11 = *(_DWORD *)&ld12->ld12[8];
      v12 = 2 * ((v8 >> 31) | (2 * v9));
      v13 = (v7 >> 31) | (2 * v8);
      v14 = ((2 * v7) >> 31) | (2 * v13);
      v15 = 0;
      v16 = (v13 >> 31) | v12;
      v17 = *(_QWORD *)ld12->ld12;
      *(_DWORD *)ld12->ld12 = 4 * v7;
      v18 = 4 * v7 + v10;
      *(_DWORD *)&ld12->ld12[4] = v14;
      *(_DWORD *)&ld12->ld12[8] = v16;
      if ( v18 < 4 * v7 || v18 < v17 )
        v15 = 1;
      *(_DWORD *)ld12->ld12 = v18;
      if ( v15 )
      {
        v19 = v14++;
        v20 = 0;
        if ( v14 < v19 || !v14 )
          v20 = 1;
        *(_DWORD *)&ld12->ld12[4] = v14;
        if ( v20 )
          *(_DWORD *)&ld12->ld12[8] = ++v16;
      }
      v21 = HIDWORD(v10);
      v22 = 0;
      v23 = v14 + v21;
      if ( v14 + (unsigned int)v21 < v14 || v23 < (unsigned int)v21 )
        v22 = 1;
      *(_DWORD *)&ld12->ld12[4] = v23;
      if ( v22 )
        *(_DWORD *)&ld12->ld12[8] = ++v16;
      v9 = (v23 >> 31) | (2 * (v11 + v16));
      *(_DWORD *)ld12->ld12 = 2 * v18;
      *(_DWORD *)&ld12->ld12[8] = v9;
      v8 = (v18 >> 31) | (2 * v23);
      v24 = 0;
      *(_DWORD *)&ld12->ld12[4] = v8;
      v25 = *manptr;
      v7 = 2 * v18 + v25;
      if ( v7 < 2 * v18 || v7 < v25 )
        v24 = 1;
      *(_DWORD *)ld12->ld12 = v7;
      if ( v24 )
      {
        v26 = v8 + 1;
        v27 = 0;
        if ( v8 + 1 < v8 || v8 == -1 )
          v27 = 1;
        ++v8;
        *(_DWORD *)&ld12->ld12[4] = v26;
        if ( v27 )
          *(_DWORD *)&ld12->ld12[8] = ++v9;
      }
      ++manptr;
      *(_DWORD *)&ld12->ld12[4] = v8;
      *(_DWORD *)&ld12->ld12[8] = v9;
      --v4;
    }
    while ( v4 );
  }
  if ( !*(_DWORD *)&ld12->ld12[8] )
  {
    v28 = *(_DWORD *)&ld12->ld12[4];
    do
    {
      v29 = HIWORD(*(_DWORD *)ld12->ld12);
      v30 = HIWORD(v28);
      *(_DWORD *)ld12->ld12 <<= 16;
      v28 = (v28 << 16) | v29;
      v6 -= 16;
    }
    while ( !v30 );
    *(_DWORD *)&ld12->ld12[4] = v28;
    *(_DWORD *)&ld12->ld12[8] = v30;
  }
  v31 = *(_DWORD *)&ld12->ld12[8];
  if ( (v31 & 0x8000) == 0 )
  {
    v32 = *(_DWORD *)ld12->ld12;
    v33 = *(_DWORD *)&ld12->ld12[4];
    do
    {
      v34 = v33 >> 31;
      v33 = (v32 >> 31) | (2 * v33);
      v31 = v34 | (2 * v31);
      --v6;
      v32 *= 2;
    }
    while ( (v31 & 0x8000) == 0 );
    *(_DWORD *)ld12->ld12 = v32;
    *(_DWORD *)&ld12->ld12[4] = v33;
    *(_DWORD *)&ld12->ld12[8] = v31;
  }
  *(_WORD *)&ld12->ld12[10] = v6;
}

