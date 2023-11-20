// File Line: 611
// RVA: 0x12D8310
__int64 __fastcall ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  unsigned int v2; // ebx
  __int16 v3; // di
  int v4; // er9
  int v5; // edi
  signed __int64 v6; // r14
  int v7; // er8
  __int64 v8; // rax
  signed int v9; // er13
  int v10; // er11
  unsigned int v11; // er10
  int v12; // ecx
  signed __int64 j; // rax
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  int v17; // er8
  __int64 i; // rdx
  unsigned int v19; // eax
  unsigned int v20; // er8
  signed __int64 v21; // r11
  int v22; // er9
  __int64 *v23; // r8
  int v24; // eax
  int v25; // er13
  int v26; // edx
  signed __int64 v27; // r14
  signed __int64 v28; // r8
  int v29; // er10
  unsigned int v30; // er11
  int v31; // ecx
  signed __int64 l; // rax
  unsigned int v33; // eax
  unsigned int v34; // edx
  signed int v35; // ecx
  unsigned int v36; // er9
  int v37; // er8
  __int64 k; // rdx
  unsigned int v39; // eax
  unsigned int v40; // er8
  int v41; // er9
  __int64 *v42; // r8
  int v43; // eax
  signed __int64 v44; // r10
  int v45; // edx
  signed __int64 v46; // r8
  int v47; // er10
  int v48; // eax
  int v49; // er11
  int v50; // er15
  char v51; // r13
  char v52; // di
  int v53; // er9
  __int64 *v54; // r8
  int v55; // eax
  signed __int64 v56; // rdi
  int v57; // er10
  __int64 *v58; // r9
  int v59; // edx
  signed __int64 v60; // rdi
  int v61; // er8
  int v62; // eax
  int v64; // [rsp+20h] [rbp-40h]
  int v65; // [rsp+24h] [rbp-3Ch]
  int v66; // [rsp+28h] [rbp-38h]
  _CRT_DOUBLE *v67; // [rsp+30h] [rbp-30h]
  int v68; // [rsp+38h] [rbp-28h]
  __int64 v69; // [rsp+40h] [rbp-20h]
  __int64 v70; // [rsp+48h] [rbp-18h]
  int v71; // [rsp+50h] [rbp-10h]

  v2 = 0;
  v3 = *(_WORD *)&pld12->ld12[10];
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v65 = *(_WORD *)&pld12->ld12[10] & 0x8000;
  LODWORD(v70) = *(_DWORD *)&pld12->ld12[6];
  v5 = (v3 & 0x7FFF) - 0x3FFF;
  v67 = d;
  v68 = v4;
  HIDWORD(v70) = *(_DWORD *)&pld12->ld12[2];
  v71 = v4;
  v6 = 3i64;
  if ( v5 == -16383 )
  {
    v7 = 0;
    v8 = 0i64;
    while ( !*((_DWORD *)&v70 + v8) )
    {
      if ( ++v8 >= 3 )
        goto LABEL_80;
    }
    v70 = 0i64;
    v71 = 0;
    v2 = 2;
  }
  else
  {
    v69 = v70;
    v64 = v5;
    v9 = 0;
    v66 = DoubleFormat.precision - 1;
    v10 = DoubleFormat.precision / 32;
    v11 = 31 - DoubleFormat.precision % -32;
    v12 = *((_DWORD *)&v70 + DoubleFormat.precision / 32);
    if ( _bittest(&v12, v11) )
    {
      if ( ~(-1 << v11) & *((_DWORD *)&v70 + v10) )
      {
LABEL_14:
        v14 = *((_DWORD *)&v70 + v66 / 32);
        v15 = 1 << (31 - (char)v66 % -32);
        v16 = v14 + v15;
        if ( v14 + v15 < v14 || v16 < v15 )
          v9 = 1;
        v17 = v66 / 32 - 1;
        *((_DWORD *)&v70 + v66 / 32) = v16;
        for ( i = v17; i >= 0; *((_DWORD *)&v70 + i--) = v20 )
        {
          if ( !v9 )
            break;
          v19 = *((_DWORD *)&v70 + i);
          v9 = 0;
          v20 = v19 + 1;
          if ( v19 + 1 < v19 || v20 < 1 )
            v9 = 1;
        }
      }
      else
      {
        for ( j = v10 + 1; j < 3; ++j )
        {
          if ( *((_DWORD *)&v70 + j) )
            goto LABEL_14;
        }
      }
    }
    *((_DWORD *)&v70 + v10) &= -1 << v11;
    if ( v10 + 1 < 3i64 )
    {
      memset((char *)&v70 + 4 * (v10 + 1), 0, 4 * (3i64 - (v10 + 1)));
      v4 = v68;
    }
    if ( v9 )
      ++v5;
    if ( v5 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v5 > DoubleFormat.min_exp )
      {
        v47 = DoubleFormat.max_exp;
        v48 = DoubleFormat.exp_width % -32;
        v49 = DoubleFormat.exp_width / 32;
        v50 = ~(-1 << SLOBYTE(DoubleFormat.exp_width) % -32);
        if ( v5 < DoubleFormat.max_exp )
        {
          LODWORD(v70) = v70 & 0x7FFFFFFF;
          v57 = 0;
          v7 = v5 + DoubleFormat.bias;
          v58 = &v70;
          do
          {
            v59 = v50 & *(_DWORD *)v58;
            *(_DWORD *)v58 = v57 | (*(_DWORD *)v58 >> v48);
            v58 = (__int64 *)((char *)v58 + 4);
            v57 = v59 << (32 - v48);
            --v6;
          }
          while ( v6 );
          v60 = 2i64;
          do
          {
            if ( v60 < v49 )
              *((_DWORD *)&v70 + v60) = 0;
            else
              *((_DWORD *)&v70 + v60) = *(_DWORD *)((char *)&v70 + 4 * v60 - 4i64 * v49);
            --v60;
          }
          while ( v60 >= 0 );
        }
        else
        {
          v70 = 0x80000000i64;
          v71 = 0;
          v51 = 32 - v48;
          v52 = DoubleFormat.exp_width % -32;
          v53 = 0;
          v54 = &v70;
          do
          {
            v55 = v53 | (*(_DWORD *)v54 >> v52);
            v53 = (*(_DWORD *)v54 & v50) << v51;
            *(_DWORD *)v54 = v55;
            v54 = (__int64 *)((char *)v54 + 4);
            --v6;
          }
          while ( v6 );
          v56 = 2i64;
          do
          {
            if ( v56 < v49 )
              *((_DWORD *)&v70 + v56) = 0;
            else
              *((_DWORD *)&v70 + v56) = *(_DWORD *)((char *)&v70 + 4 * v56 - 4i64 * v49);
            --v56;
          }
          while ( v56 >= 0 );
          v2 = 1;
          v7 = v47 + DoubleFormat.bias;
        }
      }
      else
      {
        v70 = v69;
        v71 = v4;
        v21 = 3i64;
        v22 = 0;
        v23 = &v70;
        v24 = (DoubleFormat.min_exp - v64) % -32;
        v25 = (DoubleFormat.min_exp - v64) / 32;
        do
        {
          v26 = ~(-1 << v24) & *(_DWORD *)v23;
          *(_DWORD *)v23 = v22 | (*(_DWORD *)v23 >> v24);
          v23 = (__int64 *)((char *)v23 + 4);
          v22 = v26 << (32 - v24);
          --v21;
        }
        while ( v21 );
        v27 = 3i64;
        v28 = 2i64;
        do
        {
          if ( v28 < v25 )
            *((_DWORD *)&v70 + v28) = 0;
          else
            *((_DWORD *)&v70 + v28) = *(_DWORD *)((char *)&v70 + 4 * v28 - 4i64 * v25);
          --v28;
        }
        while ( v28 >= 0 );
        v29 = (v66 + 1) / 32;
        v30 = 31 - (v66 + 1) % -32;
        v31 = *((_DWORD *)&v70 + v29);
        if ( _bittest(&v31, v30) )
        {
          if ( ~(-1 << v30) & *((_DWORD *)&v70 + v29) )
          {
LABEL_44:
            v33 = *((_DWORD *)&v70 + v66 / 32);
            v34 = 1 << (31 - (char)v66 % -32);
            v35 = 0;
            v36 = v33 + v34;
            if ( v33 + v34 < v33 || v36 < v34 )
              v35 = 1;
            v37 = v66 / 32 - 1;
            *((_DWORD *)&v70 + v66 / 32) = v36;
            for ( k = v37; k >= 0; *((_DWORD *)&v70 + k--) = v40 )
            {
              if ( !v35 )
                break;
              v39 = *((_DWORD *)&v70 + k);
              v35 = 0;
              v40 = v39 + 1;
              if ( v39 + 1 < v39 || v40 < 1 )
                v35 = 1;
            }
          }
          else
          {
            for ( l = v29 + 1; l < 3; ++l )
            {
              if ( *((_DWORD *)&v70 + l) )
                goto LABEL_44;
            }
          }
        }
        *((_DWORD *)&v70 + v29) &= -1 << v30;
        if ( v29 + 1 < 3i64 )
          memset((char *)&v70 + 4 * (v29 + 1), 0, 4 * (3i64 - (v29 + 1)));
        v41 = 0;
        v42 = &v70;
        v43 = (DoubleFormat.exp_width + 1) % -32;
        LODWORD(v44) = (DoubleFormat.exp_width + 1) / 32;
        do
        {
          v45 = ~(-1 << v43) & *(_DWORD *)v42;
          *(_DWORD *)v42 = v41 | (*(_DWORD *)v42 >> v43);
          v42 = (__int64 *)((char *)v42 + 4);
          v41 = v45 << (32 - v43);
          --v27;
        }
        while ( v27 );
        v44 = (signed int)v44;
        v46 = 2i64;
        do
        {
          if ( v46 < v44 )
            *((_DWORD *)&v70 + v46) = 0;
          else
            *((_DWORD *)&v70 + v46) = *(_DWORD *)((char *)&v70 + 4 * v46 - 4i64 * (signed int)v44);
          --v46;
        }
        while ( v46 >= 0 );
        v7 = 0;
        v2 = 2;
      }
    }
    else
    {
      v70 = 0i64;
      v71 = 0;
      v7 = 0;
      v2 = 2;
    }
    d = v67;
  }
LABEL_80:
  v61 = v70 | (v65 != 0 ? 0x80000000 : 0) | (v7 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v62 = HIDWORD(v70);
    HIDWORD(d->x) = v61;
    LODWORD(d->x) = v62;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v61;
  }
  return v2;
}

// File Line: 631
// RVA: 0x12D88C0
__int64 __fastcall ld12tof(_LDBL12 *pld12, _CRT_FLOAT *f)
{
  unsigned int v2; // ebx
  __int16 v3; // di
  int v4; // er9
  int v5; // edi
  signed __int64 v6; // r14
  int v7; // er8
  __int64 v8; // rax
  signed int v9; // er13
  int v10; // er11
  unsigned int v11; // er10
  int v12; // ecx
  signed __int64 j; // rax
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  int v17; // er8
  __int64 i; // rdx
  unsigned int v19; // eax
  unsigned int v20; // er8
  signed __int64 v21; // r11
  int v22; // er9
  __int64 *v23; // r8
  int v24; // eax
  int v25; // er13
  int v26; // edx
  signed __int64 v27; // r14
  signed __int64 v28; // r8
  int v29; // er10
  unsigned int v30; // er11
  int v31; // ecx
  signed __int64 l; // rax
  unsigned int v33; // eax
  unsigned int v34; // edx
  signed int v35; // ecx
  unsigned int v36; // er9
  int v37; // er8
  __int64 k; // rdx
  unsigned int v39; // eax
  unsigned int v40; // er8
  int v41; // er9
  __int64 *v42; // r8
  int v43; // eax
  signed __int64 v44; // r10
  int v45; // edx
  signed __int64 v46; // r8
  int v47; // er10
  int v48; // eax
  int v49; // er11
  int v50; // er15
  char v51; // r13
  char v52; // di
  int v53; // er9
  __int64 *v54; // r8
  int v55; // eax
  signed __int64 v56; // rdi
  int v57; // er10
  __int64 *v58; // r9
  int v59; // edx
  signed __int64 v60; // rdi
  float v61; // er8
  float v62; // eax
  int v64; // [rsp+20h] [rbp-40h]
  int v65; // [rsp+24h] [rbp-3Ch]
  int v66; // [rsp+28h] [rbp-38h]
  _CRT_FLOAT *v67; // [rsp+30h] [rbp-30h]
  int v68; // [rsp+38h] [rbp-28h]
  __int64 v69; // [rsp+40h] [rbp-20h]
  __int64 v70; // [rsp+48h] [rbp-18h]
  int v71; // [rsp+50h] [rbp-10h]

  v2 = 0;
  v3 = *(_WORD *)&pld12->ld12[10];
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v65 = *(_WORD *)&pld12->ld12[10] & 0x8000;
  LODWORD(v70) = *(_DWORD *)&pld12->ld12[6];
  v5 = (v3 & 0x7FFF) - 0x3FFF;
  v67 = f;
  v68 = v4;
  HIDWORD(v70) = *(_DWORD *)&pld12->ld12[2];
  v71 = v4;
  v6 = 3i64;
  if ( v5 == -16383 )
  {
    v7 = 0;
    v8 = 0i64;
    while ( !*((_DWORD *)&v70 + v8) )
    {
      if ( ++v8 >= 3 )
        goto LABEL_80;
    }
    v70 = 0i64;
    v71 = 0;
    v2 = 2;
  }
  else
  {
    v69 = v70;
    v64 = v5;
    v9 = 0;
    v66 = FloatFormat.precision - 1;
    v10 = FloatFormat.precision / 32;
    v11 = 31 - FloatFormat.precision % -32;
    v12 = *((_DWORD *)&v70 + FloatFormat.precision / 32);
    if ( _bittest(&v12, v11) )
    {
      if ( ~(-1 << v11) & *((_DWORD *)&v70 + v10) )
      {
LABEL_14:
        v14 = *((_DWORD *)&v70 + v66 / 32);
        v15 = 1 << (31 - (char)v66 % -32);
        v16 = v14 + v15;
        if ( v14 + v15 < v14 || v16 < v15 )
          v9 = 1;
        v17 = v66 / 32 - 1;
        *((_DWORD *)&v70 + v66 / 32) = v16;
        for ( i = v17; i >= 0; *((_DWORD *)&v70 + i--) = v20 )
        {
          if ( !v9 )
            break;
          v19 = *((_DWORD *)&v70 + i);
          v9 = 0;
          v20 = v19 + 1;
          if ( v19 + 1 < v19 || v20 < 1 )
            v9 = 1;
        }
      }
      else
      {
        for ( j = v10 + 1; j < 3; ++j )
        {
          if ( *((_DWORD *)&v70 + j) )
            goto LABEL_14;
        }
      }
    }
    *((_DWORD *)&v70 + v10) &= -1 << v11;
    if ( v10 + 1 < 3i64 )
    {
      memset((char *)&v70 + 4 * (v10 + 1), 0, 4 * (3i64 - (v10 + 1)));
      v4 = v68;
    }
    if ( v9 )
      ++v5;
    if ( v5 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v5 > FloatFormat.min_exp )
      {
        v47 = FloatFormat.max_exp;
        v48 = FloatFormat.exp_width % -32;
        v49 = FloatFormat.exp_width / 32;
        v50 = ~(-1 << SLOBYTE(FloatFormat.exp_width) % -32);
        if ( v5 < FloatFormat.max_exp )
        {
          LODWORD(v70) = v70 & 0x7FFFFFFF;
          v57 = 0;
          v7 = v5 + FloatFormat.bias;
          v58 = &v70;
          do
          {
            v59 = v50 & *(_DWORD *)v58;
            *(_DWORD *)v58 = v57 | (*(_DWORD *)v58 >> v48);
            v58 = (__int64 *)((char *)v58 + 4);
            v57 = v59 << (32 - v48);
            --v6;
          }
          while ( v6 );
          v60 = 2i64;
          do
          {
            if ( v60 < v49 )
              *((_DWORD *)&v70 + v60) = 0;
            else
              *((_DWORD *)&v70 + v60) = *(_DWORD *)((char *)&v70 + 4 * v60 - 4i64 * v49);
            --v60;
          }
          while ( v60 >= 0 );
        }
        else
        {
          v70 = 0x80000000i64;
          v71 = 0;
          v51 = 32 - v48;
          v52 = FloatFormat.exp_width % -32;
          v53 = 0;
          v54 = &v70;
          do
          {
            v55 = v53 | (*(_DWORD *)v54 >> v52);
            v53 = (*(_DWORD *)v54 & v50) << v51;
            *(_DWORD *)v54 = v55;
            v54 = (__int64 *)((char *)v54 + 4);
            --v6;
          }
          while ( v6 );
          v56 = 2i64;
          do
          {
            if ( v56 < v49 )
              *((_DWORD *)&v70 + v56) = 0;
            else
              *((_DWORD *)&v70 + v56) = *(_DWORD *)((char *)&v70 + 4 * v56 - 4i64 * v49);
            --v56;
          }
          while ( v56 >= 0 );
          v2 = 1;
          v7 = v47 + FloatFormat.bias;
        }
      }
      else
      {
        v70 = v69;
        v71 = v4;
        v21 = 3i64;
        v22 = 0;
        v23 = &v70;
        v24 = (FloatFormat.min_exp - v64) % -32;
        v25 = (FloatFormat.min_exp - v64) / 32;
        do
        {
          v26 = ~(-1 << v24) & *(_DWORD *)v23;
          *(_DWORD *)v23 = v22 | (*(_DWORD *)v23 >> v24);
          v23 = (__int64 *)((char *)v23 + 4);
          v22 = v26 << (32 - v24);
          --v21;
        }
        while ( v21 );
        v27 = 3i64;
        v28 = 2i64;
        do
        {
          if ( v28 < v25 )
            *((_DWORD *)&v70 + v28) = 0;
          else
            *((_DWORD *)&v70 + v28) = *(_DWORD *)((char *)&v70 + 4 * v28 - 4i64 * v25);
          --v28;
        }
        while ( v28 >= 0 );
        v29 = (v66 + 1) / 32;
        v30 = 31 - (v66 + 1) % -32;
        v31 = *((_DWORD *)&v70 + v29);
        if ( _bittest(&v31, v30) )
        {
          if ( ~(-1 << v30) & *((_DWORD *)&v70 + v29) )
          {
LABEL_44:
            v33 = *((_DWORD *)&v70 + v66 / 32);
            v34 = 1 << (31 - (char)v66 % -32);
            v35 = 0;
            v36 = v33 + v34;
            if ( v33 + v34 < v33 || v36 < v34 )
              v35 = 1;
            v37 = v66 / 32 - 1;
            *((_DWORD *)&v70 + v66 / 32) = v36;
            for ( k = v37; k >= 0; *((_DWORD *)&v70 + k--) = v40 )
            {
              if ( !v35 )
                break;
              v39 = *((_DWORD *)&v70 + k);
              v35 = 0;
              v40 = v39 + 1;
              if ( v39 + 1 < v39 || v40 < 1 )
                v35 = 1;
            }
          }
          else
          {
            for ( l = v29 + 1; l < 3; ++l )
            {
              if ( *((_DWORD *)&v70 + l) )
                goto LABEL_44;
            }
          }
        }
        *((_DWORD *)&v70 + v29) &= -1 << v30;
        if ( v29 + 1 < 3i64 )
          memset((char *)&v70 + 4 * (v29 + 1), 0, 4 * (3i64 - (v29 + 1)));
        v41 = 0;
        v42 = &v70;
        v43 = (FloatFormat.exp_width + 1) % -32;
        LODWORD(v44) = (FloatFormat.exp_width + 1) / 32;
        do
        {
          v45 = ~(-1 << v43) & *(_DWORD *)v42;
          *(_DWORD *)v42 = v41 | (*(_DWORD *)v42 >> v43);
          v42 = (__int64 *)((char *)v42 + 4);
          v41 = v45 << (32 - v43);
          --v27;
        }
        while ( v27 );
        v44 = (signed int)v44;
        v46 = 2i64;
        do
        {
          if ( v46 < v44 )
            *((_DWORD *)&v70 + v46) = 0;
          else
            *((_DWORD *)&v70 + v46) = *(_DWORD *)((char *)&v70 + 4 * v46 - 4i64 * (signed int)v44);
          --v46;
        }
        while ( v46 >= 0 );
        v7 = 0;
        v2 = 2;
      }
    }
    else
    {
      v70 = 0i64;
      v71 = 0;
      v7 = 0;
      v2 = 2;
    }
    f = v67;
  }
LABEL_80:
  LODWORD(v61) = v70 | (v65 != 0 ? 0x80000000 : 0) | (v7 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v62 = *((float *)&v70 + 1);
    f[1].f = v61;
    f->f = v62;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v61;
  }
  return v2;
}

