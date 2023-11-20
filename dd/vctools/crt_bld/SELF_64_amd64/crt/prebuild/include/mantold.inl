// File Line: 39
// RVA: 0x12D8E70
void __fastcall _mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  _LDBL12 *v3; // r10
  unsigned int v4; // edi
  char *v5; // rbp
  signed __int16 v6; // bx
  unsigned int v7; // er11
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned __int64 v10; // rsi
  int v11; // er15
  int v12; // er9
  int v13; // er8
  unsigned int v14; // ecx
  unsigned int v15; // er8
  signed int v16; // eax
  int v17; // er9
  unsigned int v18; // ecx
  unsigned int v19; // er14
  unsigned int v20; // eax
  signed int v21; // ecx
  unsigned __int64 v22; // rsi
  signed int v23; // eax
  unsigned int v24; // er11
  signed int v25; // eax
  unsigned int v26; // ecx
  unsigned int v27; // eax
  signed int v28; // ecx
  unsigned int v29; // er8
  int v30; // ecx
  unsigned int v31; // er9
  int v32; // edx
  unsigned int v33; // er9
  unsigned int v34; // er8
  unsigned int v35; // ecx

  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  *(_DWORD *)&ld12->ld12[8] = 0;
  v3 = ld12;
  v4 = manlen;
  v5 = manptr;
  v6 = 16462;
  if ( manlen )
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    do
    {
      v10 = *(_QWORD *)v3->ld12;
      v11 = *(_DWORD *)&v3->ld12[8];
      v12 = 2 * ((v8 >> 31) | 2 * v9);
      v13 = (v7 >> 31) | 2 * v8;
      v14 = v13;
      v15 = (2 * v7 >> 31) | 2 * v13;
      v16 = 0;
      v17 = (v14 >> 31) | v12;
      v18 = *(_QWORD *)v3->ld12;
      *(_DWORD *)v3->ld12 = 4 * v7;
      v19 = 4 * v7 + v10;
      *(_DWORD *)&v3->ld12[4] = v15;
      *(_DWORD *)&v3->ld12[8] = v17;
      if ( v19 < 4 * v7 || v19 < v18 )
        v16 = 1;
      *(_DWORD *)v3->ld12 = v19;
      if ( v16 )
      {
        v20 = v15++;
        v21 = 0;
        if ( v15 < v20 || v15 < 1 )
          v21 = 1;
        *(_DWORD *)&v3->ld12[4] = v15;
        if ( v21 )
          *(_DWORD *)&v3->ld12[8] = ++v17;
      }
      v22 = v10 >> 32;
      v23 = 0;
      v24 = v15 + v22;
      if ( v15 + (unsigned int)v22 < v15 || v24 < (unsigned int)v22 )
        v23 = 1;
      *(_DWORD *)&v3->ld12[4] = v24;
      if ( v23 )
        *(_DWORD *)&v3->ld12[8] = ++v17;
      v9 = ((v15 + (unsigned int)v22) >> 31) | 2 * (v11 + v17);
      *(_DWORD *)v3->ld12 = 2 * v19;
      *(_DWORD *)&v3->ld12[8] = v9;
      v8 = (v19 >> 31) | 2 * v24;
      v25 = 0;
      *(_DWORD *)&v3->ld12[4] = v8;
      v26 = *v5;
      v7 = 2 * v19 + v26;
      if ( v7 < 2 * v19 || v7 < v26 )
        v25 = 1;
      *(_DWORD *)v3->ld12 = v7;
      if ( v25 )
      {
        v27 = v8 + 1;
        v28 = 0;
        if ( v8 + 1 < v8 || v27 < 1 )
          v28 = 1;
        ++v8;
        *(_DWORD *)&v3->ld12[4] = v27;
        if ( v28 )
          *(_DWORD *)&v3->ld12[8] = ++v9;
      }
      ++v5;
      *(_DWORD *)&v3->ld12[4] = v8;
      *(_DWORD *)&v3->ld12[8] = v9;
      --v4;
    }
    while ( v4 );
  }
  if ( !*(_DWORD *)&v3->ld12[8] )
  {
    v29 = *(_DWORD *)&v3->ld12[4];
    do
    {
      v30 = *(_DWORD *)v3->ld12 >> 16;
      v31 = v29 >> 16;
      *(_DWORD *)v3->ld12 <<= 16;
      v29 = (v29 << 16) | v30;
      v6 -= 16;
    }
    while ( !v31 );
    *(_DWORD *)&v3->ld12[4] = v29;
    *(_DWORD *)&v3->ld12[8] = v31;
  }
  v32 = *(_DWORD *)&v3->ld12[8];
  if ( !(v32 & 0x8000) )
  {
    v33 = *(_DWORD *)v3->ld12;
    v34 = *(_DWORD *)&v3->ld12[4];
    do
    {
      v35 = v34 >> 31;
      v34 = (v33 >> 31) | 2 * v34;
      v32 = v35 | 2 * v32;
      --v6;
      v33 *= 2;
    }
    while ( !(v32 & 0x8000) );
    *(_DWORD *)v3->ld12 = v33;
    *(_DWORD *)&v3->ld12[4] = v34;
    *(_DWORD *)&v3->ld12[8] = v32;
  }
  *(_WORD *)&v3->ld12[10] = v6;
}

