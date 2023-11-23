// File Line: 611
// RVA: 0x12D8310
__int64 __fastcall ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  unsigned int v2; // ebx
  __int16 v3; // di
  int v4; // r9d
  int v5; // edi
  __int64 v6; // r14
  int v7; // r8d
  __int64 v8; // rax
  int v9; // r13d
  int v10; // r11d
  unsigned int v11; // r10d
  int v12; // ecx
  __int64 j; // rax
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  int v17; // r8d
  __int64 i; // rdx
  unsigned int v19; // eax
  __int64 v20; // r11
  int v21; // r9d
  __int64 *v22; // r8
  int v23; // r13d
  int v24; // ecx
  int v25; // eax
  int v26; // r9d
  __int64 v27; // r14
  __int64 n; // r8
  int v29; // r10d
  unsigned int v30; // r11d
  int v31; // ecx
  __int64 jj; // rax
  unsigned int v33; // eax
  unsigned int v34; // edx
  int v35; // ecx
  unsigned int v36; // r9d
  int v37; // r8d
  __int64 ii; // rdx
  unsigned int v39; // eax
  int v40; // r9d
  __int64 *v41; // r8
  int v42; // eax
  int v43; // r10d
  char v44; // r11
  char v45; // r13
  int v46; // r15d
  int v47; // eax
  int v48; // r9d
  __int64 kk; // r8
  int max_exp; // r10d
  int v51; // eax
  int v52; // r11d
  int v53; // r15d
  char v54; // r13
  char v55; // di
  int v56; // r9d
  __int64 *v57; // r8
  int v58; // eax
  __int64 m; // rdi
  int v60; // r10d
  char v61; // di
  char v62; // r13
  __int64 *v63; // r9
  int v64; // eax
  int v65; // r10d
  __int64 k; // rdi
  int v67; // r8d
  int v68; // eax
  int v70; // [rsp+20h] [rbp-40h]
  int v71; // [rsp+24h] [rbp-3Ch]
  int v72; // [rsp+28h] [rbp-38h]
  _CRT_DOUBLE *v73; // [rsp+30h] [rbp-30h]
  int v74; // [rsp+38h] [rbp-28h]
  __int64 v75; // [rsp+40h] [rbp-20h]
  __int64 v76; // [rsp+48h] [rbp-18h] BYREF
  int v77; // [rsp+50h] [rbp-10h]

  v2 = 0;
  v3 = *(_WORD *)&pld12->ld12[10];
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v71 = v3 & 0x8000;
  LODWORD(v76) = *(_DWORD *)&pld12->ld12[6];
  v5 = (v3 & 0x7FFF) - 0x3FFF;
  v73 = d;
  v74 = v4;
  HIDWORD(v76) = *(_DWORD *)&pld12->ld12[2];
  v77 = v4;
  v6 = 3i64;
  if ( v5 == -16383 )
  {
    v7 = 0;
    v8 = 0i64;
    while ( !*((_DWORD *)&v76 + v8) )
    {
      if ( ++v8 >= 3 )
        goto LABEL_80;
    }
    v76 = 0i64;
    v77 = 0;
    v2 = 2;
  }
  else
  {
    v75 = v76;
    v70 = v5;
    v9 = 0;
    v72 = DoubleFormat.precision - 1;
    v10 = DoubleFormat.precision / 32;
    v11 = 31 - DoubleFormat.precision % 32;
    v12 = *((_DWORD *)&v76 + DoubleFormat.precision / 32);
    if ( _bittest(&v12, v11) )
    {
      if ( (~(-1 << v11) & *((_DWORD *)&v76 + v10)) != 0 )
      {
LABEL_14:
        v14 = *((_DWORD *)&v76 + v72 / 32);
        v15 = 1 << (31 - v72 % 32);
        v16 = v14 + v15;
        if ( v14 + v15 < v14 || v16 < v15 )
          v9 = 1;
        v17 = v72 / 32 - 1;
        *((_DWORD *)&v76 + v72 / 32) = v16;
        for ( i = v17; i >= 0; *((_DWORD *)&v76 + i--) = v19 + 1 )
        {
          if ( !v9 )
            break;
          v19 = *((_DWORD *)&v76 + i);
          v9 = 0;
          if ( v19 + 1 < v19 || v19 == -1 )
            v9 = 1;
        }
      }
      else
      {
        for ( j = v10 + 1; j < 3; ++j )
        {
          if ( *((_DWORD *)&v76 + j) )
            goto LABEL_14;
        }
      }
    }
    *((_DWORD *)&v76 + v10) &= -1 << v11;
    if ( v10 + 1 < 3i64 )
    {
      memset((char *)&v76 + 4 * v10 + 4, 0, 4 * (3i64 - (v10 + 1)));
      v4 = v74;
    }
    if ( v9 )
      ++v5;
    if ( v5 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v5 > DoubleFormat.min_exp )
      {
        max_exp = DoubleFormat.max_exp;
        v51 = DoubleFormat.exp_width % 32;
        v52 = DoubleFormat.exp_width / 32;
        v53 = ~(-1 << (DoubleFormat.exp_width % 32));
        if ( v5 < DoubleFormat.max_exp )
        {
          LODWORD(v76) = v76 & 0x7FFFFFFF;
          v60 = 0;
          v7 = v5 + DoubleFormat.bias;
          v61 = DoubleFormat.exp_width % 32;
          v62 = 32 - v51;
          v63 = &v76;
          do
          {
            v64 = v60 | (*(_DWORD *)v63 >> v61);
            v65 = v53 & *(_DWORD *)v63;
            *(_DWORD *)v63 = v64;
            v63 = (__int64 *)((char *)v63 + 4);
            v60 = v65 << v62;
            --v6;
          }
          while ( v6 );
          for ( k = 2i64; k >= 0; --k )
          {
            if ( k < v52 )
              *((_DWORD *)&v76 + k) = 0;
            else
              *((_DWORD *)&v76 + k) = *(_DWORD *)((char *)&v76 + 4 * k - 4i64 * v52);
          }
        }
        else
        {
          v76 = 0x80000000i64;
          v77 = 0;
          v54 = 32 - v51;
          v55 = DoubleFormat.exp_width % 32;
          v56 = 0;
          v57 = &v76;
          do
          {
            v58 = v56 | (*(_DWORD *)v57 >> v55);
            v56 = (*(_DWORD *)v57 & v53) << v54;
            *(_DWORD *)v57 = v58;
            v57 = (__int64 *)((char *)v57 + 4);
            --v6;
          }
          while ( v6 );
          for ( m = 2i64; m >= 0; --m )
          {
            if ( m < v52 )
              *((_DWORD *)&v76 + m) = 0;
            else
              *((_DWORD *)&v76 + m) = *(_DWORD *)((char *)&v76 + 4 * m - 4i64 * v52);
          }
          v2 = 1;
          v7 = max_exp + DoubleFormat.bias;
        }
      }
      else
      {
        v76 = v75;
        v77 = v4;
        v20 = 3i64;
        v21 = 0;
        v22 = &v76;
        v23 = (DoubleFormat.min_exp - v70) / 32;
        v24 = (DoubleFormat.min_exp - v70) % 32;
        do
        {
          v25 = v21 | (*(_DWORD *)v22 >> v24);
          v26 = ~(-1 << v24) & *(_DWORD *)v22;
          *(_DWORD *)v22 = v25;
          v22 = (__int64 *)((char *)v22 + 4);
          v21 = v26 << (32 - v24);
          --v20;
        }
        while ( v20 );
        v27 = 3i64;
        for ( n = 2i64; n >= 0; --n )
        {
          if ( n < v23 )
            *((_DWORD *)&v76 + n) = 0;
          else
            *((_DWORD *)&v76 + n) = *(_DWORD *)((char *)&v76 + 4 * n - 4i64 * v23);
        }
        v29 = (v72 + 1) / 32;
        v30 = 31 - (v72 + 1) % 32;
        v31 = *((_DWORD *)&v76 + v29);
        if ( _bittest(&v31, v30) )
        {
          if ( (~(-1 << v30) & *((_DWORD *)&v76 + v29)) != 0 )
          {
LABEL_44:
            v33 = *((_DWORD *)&v76 + v72 / 32);
            v34 = 1 << (31 - v72 % 32);
            v35 = 0;
            v36 = v33 + v34;
            if ( v33 + v34 < v33 || v36 < v34 )
              v35 = 1;
            v37 = v72 / 32 - 1;
            *((_DWORD *)&v76 + v72 / 32) = v36;
            for ( ii = v37; ii >= 0; *((_DWORD *)&v76 + ii--) = v39 + 1 )
            {
              if ( !v35 )
                break;
              v39 = *((_DWORD *)&v76 + ii);
              v35 = 0;
              if ( v39 + 1 < v39 || v39 == -1 )
                v35 = 1;
            }
          }
          else
          {
            for ( jj = v29 + 1; jj < 3; ++jj )
            {
              if ( *((_DWORD *)&v76 + jj) )
                goto LABEL_44;
            }
          }
        }
        *((_DWORD *)&v76 + v29) &= -1 << v30;
        if ( v29 + 1 < 3i64 )
          memset((char *)&v76 + 4 * v29 + 4, 0, 4 * (3i64 - (v29 + 1)));
        v40 = 0;
        v41 = &v76;
        v42 = (DoubleFormat.exp_width + 1) % 32;
        v43 = (DoubleFormat.exp_width + 1) / 32;
        v44 = v42;
        v45 = 32 - v42;
        v46 = ~(-1 << v42);
        do
        {
          v47 = v40 | (*(_DWORD *)v41 >> v44);
          v48 = v46 & *(_DWORD *)v41;
          *(_DWORD *)v41 = v47;
          v41 = (__int64 *)((char *)v41 + 4);
          v40 = v48 << v45;
          --v27;
        }
        while ( v27 );
        for ( kk = 2i64; kk >= 0; --kk )
        {
          if ( kk < v43 )
            *((_DWORD *)&v76 + kk) = 0;
          else
            *((_DWORD *)&v76 + kk) = *(_DWORD *)((char *)&v76 + 4 * kk - 4i64 * v43);
        }
        v7 = 0;
        v2 = 2;
      }
    }
    else
    {
      v76 = 0i64;
      v77 = 0;
      v7 = 0;
      v2 = 2;
    }
    d = v73;
  }
LABEL_80:
  v67 = v76 | (v71 != 0 ? 0x80000000 : 0) | (v7 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v68 = HIDWORD(v76);
    HIDWORD(d->x) = v67;
    LODWORD(d->x) = v68;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v67;
  }
  return v2;
}

// File Line: 631
// RVA: 0x12D88C0
__int64 __fastcall ld12tof(_LDBL12 *pld12, _CRT_FLOAT *f)
{
  unsigned int v2; // ebx
  __int16 v3; // di
  int v4; // r9d
  int v5; // edi
  __int64 v6; // r14
  int v7; // r8d
  __int64 v8; // rax
  int v9; // r13d
  int v10; // r11d
  unsigned int v11; // r10d
  int v12; // ecx
  __int64 j; // rax
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  int v17; // r8d
  __int64 i; // rdx
  unsigned int v19; // eax
  __int64 v20; // r11
  int v21; // r9d
  __int64 *v22; // r8
  int v23; // r13d
  int v24; // ecx
  int v25; // eax
  int v26; // r9d
  __int64 v27; // r14
  __int64 n; // r8
  int v29; // r10d
  unsigned int v30; // r11d
  int v31; // ecx
  __int64 jj; // rax
  unsigned int v33; // eax
  unsigned int v34; // edx
  int v35; // ecx
  unsigned int v36; // r9d
  int v37; // r8d
  __int64 ii; // rdx
  unsigned int v39; // eax
  int v40; // r9d
  __int64 *v41; // r8
  int v42; // eax
  int v43; // r10d
  char v44; // r11
  char v45; // r13
  int v46; // r15d
  int v47; // eax
  int v48; // r9d
  __int64 kk; // r8
  int max_exp; // r10d
  int v51; // eax
  int v52; // r11d
  int v53; // r15d
  char v54; // r13
  char v55; // di
  int v56; // r9d
  __int64 *v57; // r8
  int v58; // eax
  __int64 m; // rdi
  int v60; // r10d
  char v61; // di
  char v62; // r13
  __int64 *v63; // r9
  int v64; // eax
  int v65; // r10d
  __int64 k; // rdi
  float v67; // r8d
  float v68; // eax
  int v70; // [rsp+20h] [rbp-40h]
  int v71; // [rsp+24h] [rbp-3Ch]
  int v72; // [rsp+28h] [rbp-38h]
  _CRT_FLOAT *v73; // [rsp+30h] [rbp-30h]
  int v74; // [rsp+38h] [rbp-28h]
  __int64 v75; // [rsp+40h] [rbp-20h]
  __int64 v76; // [rsp+48h] [rbp-18h] BYREF
  int v77; // [rsp+50h] [rbp-10h]

  v2 = 0;
  v3 = *(_WORD *)&pld12->ld12[10];
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v71 = v3 & 0x8000;
  LODWORD(v76) = *(_DWORD *)&pld12->ld12[6];
  v5 = (v3 & 0x7FFF) - 0x3FFF;
  v73 = f;
  v74 = v4;
  HIDWORD(v76) = *(_DWORD *)&pld12->ld12[2];
  v77 = v4;
  v6 = 3i64;
  if ( v5 == -16383 )
  {
    v7 = 0;
    v8 = 0i64;
    while ( !*((_DWORD *)&v76 + v8) )
    {
      if ( ++v8 >= 3 )
        goto LABEL_80;
    }
    v76 = 0i64;
    v77 = 0;
    v2 = 2;
  }
  else
  {
    v75 = v76;
    v70 = v5;
    v9 = 0;
    v72 = FloatFormat.precision - 1;
    v10 = FloatFormat.precision / 32;
    v11 = 31 - FloatFormat.precision % 32;
    v12 = *((_DWORD *)&v76 + FloatFormat.precision / 32);
    if ( _bittest(&v12, v11) )
    {
      if ( (~(-1 << v11) & *((_DWORD *)&v76 + v10)) != 0 )
      {
LABEL_14:
        v14 = *((_DWORD *)&v76 + v72 / 32);
        v15 = 1 << (31 - v72 % 32);
        v16 = v14 + v15;
        if ( v14 + v15 < v14 || v16 < v15 )
          v9 = 1;
        v17 = v72 / 32 - 1;
        *((_DWORD *)&v76 + v72 / 32) = v16;
        for ( i = v17; i >= 0; *((_DWORD *)&v76 + i--) = v19 + 1 )
        {
          if ( !v9 )
            break;
          v19 = *((_DWORD *)&v76 + i);
          v9 = 0;
          if ( v19 + 1 < v19 || v19 == -1 )
            v9 = 1;
        }
      }
      else
      {
        for ( j = v10 + 1; j < 3; ++j )
        {
          if ( *((_DWORD *)&v76 + j) )
            goto LABEL_14;
        }
      }
    }
    *((_DWORD *)&v76 + v10) &= -1 << v11;
    if ( v10 + 1 < 3i64 )
    {
      memset((char *)&v76 + 4 * v10 + 4, 0, 4 * (3i64 - (v10 + 1)));
      v4 = v74;
    }
    if ( v9 )
      ++v5;
    if ( v5 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v5 > FloatFormat.min_exp )
      {
        max_exp = FloatFormat.max_exp;
        v51 = FloatFormat.exp_width % 32;
        v52 = FloatFormat.exp_width / 32;
        v53 = ~(-1 << (FloatFormat.exp_width % 32));
        if ( v5 < FloatFormat.max_exp )
        {
          LODWORD(v76) = v76 & 0x7FFFFFFF;
          v60 = 0;
          v7 = v5 + FloatFormat.bias;
          v61 = FloatFormat.exp_width % 32;
          v62 = 32 - v51;
          v63 = &v76;
          do
          {
            v64 = v60 | (*(_DWORD *)v63 >> v61);
            v65 = v53 & *(_DWORD *)v63;
            *(_DWORD *)v63 = v64;
            v63 = (__int64 *)((char *)v63 + 4);
            v60 = v65 << v62;
            --v6;
          }
          while ( v6 );
          for ( k = 2i64; k >= 0; --k )
          {
            if ( k < v52 )
              *((_DWORD *)&v76 + k) = 0;
            else
              *((_DWORD *)&v76 + k) = *(_DWORD *)((char *)&v76 + 4 * k - 4i64 * v52);
          }
        }
        else
        {
          v76 = 0x80000000i64;
          v77 = 0;
          v54 = 32 - v51;
          v55 = FloatFormat.exp_width % 32;
          v56 = 0;
          v57 = &v76;
          do
          {
            v58 = v56 | (*(_DWORD *)v57 >> v55);
            v56 = (*(_DWORD *)v57 & v53) << v54;
            *(_DWORD *)v57 = v58;
            v57 = (__int64 *)((char *)v57 + 4);
            --v6;
          }
          while ( v6 );
          for ( m = 2i64; m >= 0; --m )
          {
            if ( m < v52 )
              *((_DWORD *)&v76 + m) = 0;
            else
              *((_DWORD *)&v76 + m) = *(_DWORD *)((char *)&v76 + 4 * m - 4i64 * v52);
          }
          v2 = 1;
          v7 = max_exp + FloatFormat.bias;
        }
      }
      else
      {
        v76 = v75;
        v77 = v4;
        v20 = 3i64;
        v21 = 0;
        v22 = &v76;
        v23 = (FloatFormat.min_exp - v70) / 32;
        v24 = (FloatFormat.min_exp - v70) % 32;
        do
        {
          v25 = v21 | (*(_DWORD *)v22 >> v24);
          v26 = ~(-1 << v24) & *(_DWORD *)v22;
          *(_DWORD *)v22 = v25;
          v22 = (__int64 *)((char *)v22 + 4);
          v21 = v26 << (32 - v24);
          --v20;
        }
        while ( v20 );
        v27 = 3i64;
        for ( n = 2i64; n >= 0; --n )
        {
          if ( n < v23 )
            *((_DWORD *)&v76 + n) = 0;
          else
            *((_DWORD *)&v76 + n) = *(_DWORD *)((char *)&v76 + 4 * n - 4i64 * v23);
        }
        v29 = (v72 + 1) / 32;
        v30 = 31 - (v72 + 1) % 32;
        v31 = *((_DWORD *)&v76 + v29);
        if ( _bittest(&v31, v30) )
        {
          if ( (~(-1 << v30) & *((_DWORD *)&v76 + v29)) != 0 )
          {
LABEL_44:
            v33 = *((_DWORD *)&v76 + v72 / 32);
            v34 = 1 << (31 - v72 % 32);
            v35 = 0;
            v36 = v33 + v34;
            if ( v33 + v34 < v33 || v36 < v34 )
              v35 = 1;
            v37 = v72 / 32 - 1;
            *((_DWORD *)&v76 + v72 / 32) = v36;
            for ( ii = v37; ii >= 0; *((_DWORD *)&v76 + ii--) = v39 + 1 )
            {
              if ( !v35 )
                break;
              v39 = *((_DWORD *)&v76 + ii);
              v35 = 0;
              if ( v39 + 1 < v39 || v39 == -1 )
                v35 = 1;
            }
          }
          else
          {
            for ( jj = v29 + 1; jj < 3; ++jj )
            {
              if ( *((_DWORD *)&v76 + jj) )
                goto LABEL_44;
            }
          }
        }
        *((_DWORD *)&v76 + v29) &= -1 << v30;
        if ( v29 + 1 < 3i64 )
          memset((char *)&v76 + 4 * v29 + 4, 0, 4 * (3i64 - (v29 + 1)));
        v40 = 0;
        v41 = &v76;
        v42 = (FloatFormat.exp_width + 1) % 32;
        v43 = (FloatFormat.exp_width + 1) / 32;
        v44 = v42;
        v45 = 32 - v42;
        v46 = ~(-1 << v42);
        do
        {
          v47 = v40 | (*(_DWORD *)v41 >> v44);
          v48 = v46 & *(_DWORD *)v41;
          *(_DWORD *)v41 = v47;
          v41 = (__int64 *)((char *)v41 + 4);
          v40 = v48 << v45;
          --v27;
        }
        while ( v27 );
        for ( kk = 2i64; kk >= 0; --kk )
        {
          if ( kk < v43 )
            *((_DWORD *)&v76 + kk) = 0;
          else
            *((_DWORD *)&v76 + kk) = *(_DWORD *)((char *)&v76 + 4 * kk - 4i64 * v43);
        }
        v7 = 0;
        v2 = 2;
      }
    }
    else
    {
      v76 = 0i64;
      v77 = 0;
      v7 = 0;
      v2 = 2;
    }
    f = v73;
  }
LABEL_80:
  LODWORD(v67) = v76 | (v71 != 0 ? 0x80000000 : 0) | (v7 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v68 = *((float *)&v76 + 1);
    f[1].f = v67;
    f->f = v68;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v67;
  }
  return v2;
}

