// File Line: 106
// RVA: 0x12B1540
void __fastcall qsort(void *base, unsigned __int64 num, unsigned __int64 width, int (__fastcall *comp)(const void *, const void *))
{
  int (__fastcall *v4)(const void *, const void *); // r14
  unsigned __int64 v5; // rbp
  char *v6; // r12
  char *v7; // r15
  __int64 v8; // r13
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rsi
  unsigned __int64 v11; // r8
  char *v12; // rdx
  char *v13; // r9
  char v14; // al
  char v15; // cl
  unsigned __int64 v16; // r8
  char *v17; // rdx
  signed __int64 v18; // r9
  char v19; // al
  char v20; // cl
  unsigned __int64 v21; // r8
  char *v22; // rdx
  unsigned __int64 v23; // r9
  char v24; // al
  char v25; // cl
  unsigned __int64 v26; // rbx
  char *v27; // rdi
  char *v28; // rdx
  unsigned __int64 v29; // r9
  char v30; // al
  char v31; // cl
  unsigned __int64 v32; // rdi
  __int64 v33[62]; // [rsp+20h] [rbp-408h]
  __int64 v34[62]; // [rsp+210h] [rbp-218h]

  v4 = comp;
  v5 = width;
  v6 = (char *)base;
  if ( (base || !num) && width && comp )
  {
    if ( num >= 2 )
    {
      v7 = (char *)base + width * (num - 1);
      v8 = 0i64;
      while ( 1 )
      {
        while ( 1 )
        {
          v9 = (v7 - v6) / v5 + 1;
          if ( v9 <= 8 )
          {
            shortsort(v6, v7, v5, v4);
            goto LABEL_10;
          }
          v10 = (unsigned __int64)&v6[v5 * (v9 >> 1)];
          if ( v4(v6, (const void *)v10) > 0 )
          {
            v11 = v5;
            v12 = (char *)v10;
            if ( v6 != (char *)v10 )
            {
              v13 = &v6[-v10];
              do
              {
                v14 = *v12;
                v15 = (v12++)[(_QWORD)v13];
                v12[(_QWORD)v13 - 1] = v14;
                *(v12 - 1) = v15;
                --v11;
              }
              while ( v11 );
            }
          }
          if ( ((signed int (__fastcall *)(char *, char *, unsigned __int64))v4)(v6, v7, v11) > 0 )
          {
            v16 = v5;
            v17 = v7;
            if ( v6 != v7 )
            {
              v18 = v6 - v7;
              do
              {
                v19 = *v17;
                v20 = (v17++)[v18];
                v17[v18 - 1] = v19;
                *(v17 - 1) = v20;
                --v16;
              }
              while ( v16 );
            }
          }
          if ( ((signed int (__fastcall *)(unsigned __int64, char *, unsigned __int64))v4)(v10, v7, v16) > 0 )
          {
            v21 = v5;
            v22 = v7;
            if ( (char *)v10 != v7 )
            {
              v23 = v10 - (_QWORD)v7;
              do
              {
                v24 = *v22;
                v25 = (v22++)[v23];
                v22[v23 - 1] = v24;
                *(v22 - 1) = v25;
                --v21;
              }
              while ( v21 );
            }
          }
          v26 = (unsigned __int64)v6;
          v27 = v7;
          while ( 1 )
          {
            if ( v10 > v26 )
            {
              while ( 1 )
              {
                v26 += v5;
                if ( v26 >= v10 )
                  break;
                if ( ((signed int (__fastcall *)(unsigned __int64, unsigned __int64, unsigned __int64))v4)(
                       v26,
                       v10,
                       v21) > 0 )
                {
                  if ( v10 > v26 )
                    goto LABEL_31;
                  goto LABEL_29;
                }
              }
            }
            do
LABEL_29:
              v26 += v5;
            while ( v26 <= (unsigned __int64)v7
                 && ((signed int (__fastcall *)(unsigned __int64, unsigned __int64, unsigned __int64))v4)(v26, v10, v21) <= 0 );
            do
LABEL_31:
              v27 -= v5;
            while ( (unsigned __int64)v27 > v10 && v4(v27, (const void *)v10) > 0 );
            if ( (unsigned __int64)v27 < v26 )
              break;
            v21 = v5;
            v28 = v27;
            if ( (char *)v26 != v27 )
            {
              v29 = v26 - (_QWORD)v27;
              do
              {
                v30 = *v28;
                v31 = (v28++)[v29];
                v28[v29 - 1] = v30;
                *(v28 - 1) = v31;
                --v21;
              }
              while ( v21 );
            }
            if ( (char *)v10 == v27 )
              v10 = v26;
          }
          v32 = (unsigned __int64)&v27[v5];
          if ( v10 < v32 )
          {
            while ( 1 )
            {
              v32 -= v5;
              if ( v32 <= v10 )
                break;
              if ( v4((const void *)v32, (const void *)v10) )
              {
                if ( v10 < v32 )
                  goto LABEL_45;
                goto LABEL_43;
              }
            }
          }
          do
LABEL_43:
            v32 -= v5;
          while ( v32 > (unsigned __int64)v6 && !v4((const void *)v32, (const void *)v10) );
LABEL_45:
          if ( (signed __int64)(v32 - (_QWORD)v6) >= (signed __int64)&v7[-v26] )
            break;
          if ( v26 < (unsigned __int64)v7 )
          {
            v33[v8] = v26;
            v34[v8++] = (__int64)v7;
          }
          if ( (unsigned __int64)v6 >= v32 )
          {
LABEL_10:
            if ( --v8 < 0 )
              return;
            v6 = (char *)v33[v8];
            v7 = (char *)v34[v8];
          }
          else
          {
            v7 = (char *)v32;
          }
        }
        if ( (unsigned __int64)v6 < v32 )
        {
          v33[v8] = (__int64)v6;
          v34[v8++] = v32;
        }
        if ( v26 >= (unsigned __int64)v7 )
          goto LABEL_10;
        v6 = (char *)v26;
      }
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
}

// File Line: 344
// RVA: 0x12B1830
void __fastcall shortsort(char *lo, char *hi, unsigned __int64 width, int (__fastcall *comp)(const void *, const void *))
{
  char *v4; // r12
  int (__fastcall *v5)(const void *, const void *); // r15
  unsigned __int64 v6; // rbp
  char *v7; // rsi
  char *v8; // r14
  char *v9; // rbx
  char *i; // rdi
  unsigned __int64 v11; // r8
  char *v12; // rax
  signed __int64 v13; // rbx
  char v14; // cl
  char v15; // dl

  if ( hi > lo )
  {
    v4 = &lo[width];
    v5 = comp;
    v6 = width;
    v7 = hi;
    v8 = lo;
    do
    {
      v9 = v8;
      for ( i = v4; i <= v7; i += v6 )
      {
        if ( v5(i, v9) > 0 )
          v9 = i;
      }
      v11 = v6;
      v12 = v7;
      if ( v9 != v7 && v6 )
      {
        v13 = v9 - v7;
        do
        {
          v14 = *v12;
          v15 = (v12++)[v13];
          v12[v13 - 1] = v14;
          *(v12 - 1) = v15;
          --v11;
        }
        while ( v11 );
      }
      v7 -= v6;
    }
    while ( v7 > v8 );
  }
}

