// File Line: 106
// RVA: 0x12B1540
void __fastcall qsort(
        char *base,
        unsigned __int64 num,
        unsigned __int64 width,
        int (__fastcall *comp)(const void *, const void *))
{
  char *v6; // r12
  char *v7; // r15
  __int64 v8; // r13
  unsigned __int64 v9; // rsi
  char *v10; // rsi
  unsigned __int64 v11; // r8
  char *v12; // rdx
  signed __int64 v13; // r9
  char v14; // al
  char v15; // cl
  unsigned __int64 v16; // r8
  char *v17; // rdx
  signed __int64 v18; // r9
  char v19; // al
  char v20; // cl
  unsigned __int64 v21; // r8
  char *v22; // rdx
  signed __int64 v23; // r9
  char v24; // al
  char v25; // cl
  unsigned __int64 v26; // rbx
  char *v27; // rdi
  char *v28; // rdx
  unsigned __int64 v29; // r9
  char v30; // al
  char v31; // cl
  char *v32; // rdi
  __int64 v33[124]; // [rsp+20h] [rbp-408h]

  v6 = base;
  if ( (base || !num) && width && comp )
  {
    if ( num >= 2 )
    {
      v7 = &base[width * (num - 1)];
      v8 = 0i64;
      while ( 1 )
      {
        while ( 1 )
        {
          v9 = (v7 - v6) / width + 1;
          if ( v9 <= 8 )
          {
            shortsort(v6, v7, width, comp);
            goto LABEL_10;
          }
          v10 = &v6[width * (v9 >> 1)];
          if ( comp(v6, v10) > 0 )
          {
            v11 = width;
            v12 = v10;
            if ( v6 != v10 )
            {
              v13 = v6 - v10;
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
          }
          if ( ((int (__fastcall *)(char *, char *, unsigned __int64))comp)(v6, v7, v11) > 0 )
          {
            v16 = width;
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
          if ( ((int (__fastcall *)(char *, char *, unsigned __int64))comp)(v10, v7, v16) > 0 )
          {
            v21 = width;
            v22 = v7;
            if ( v10 != v7 )
            {
              v23 = v10 - v7;
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
            if ( (unsigned __int64)v10 > v26 )
            {
              while ( 1 )
              {
                v26 += width;
                if ( v26 >= (unsigned __int64)v10 )
                  break;
                if ( ((int (__fastcall *)(unsigned __int64, char *, unsigned __int64))comp)(v26, v10, v21) > 0 )
                {
                  if ( (unsigned __int64)v10 > v26 )
                    goto LABEL_31;
                  goto LABEL_29;
                }
              }
            }
            do
LABEL_29:
              v26 += width;
            while ( v26 <= (unsigned __int64)v7
                 && ((int (__fastcall *)(unsigned __int64, char *, unsigned __int64))comp)(v26, v10, v21) <= 0 );
            do
LABEL_31:
              v27 -= width;
            while ( v27 > v10 && comp(v27, v10) > 0 );
            if ( (unsigned __int64)v27 < v26 )
              break;
            v21 = width;
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
            if ( v10 == v27 )
              v10 = (char *)v26;
          }
          v32 = &v27[width];
          if ( v10 < v32 )
          {
            while ( 1 )
            {
              v32 -= width;
              if ( v32 <= v10 )
                break;
              if ( comp(v32, v10) )
              {
                if ( v10 < v32 )
                  goto LABEL_45;
                goto LABEL_43;
              }
            }
          }
          do
LABEL_43:
            v32 -= width;
          while ( v32 > v6 && !comp(v32, v10) );
LABEL_45:
          if ( v32 - v6 >= (__int64)&v7[-v26] )
            break;
          if ( v26 < (unsigned __int64)v7 )
          {
            v33[v8] = v26;
            v33[v8++ + 62] = (__int64)v7;
          }
          if ( v6 >= v32 )
          {
LABEL_10:
            if ( --v8 < 0 )
              return;
            v6 = (char *)v33[v8];
            v7 = (char *)v33[v8 + 62];
          }
          else
          {
            v7 = v32;
          }
        }
        if ( v6 < v32 )
        {
          v33[v8] = (__int64)v6;
          v33[v8++ + 62] = (__int64)v32;
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
void __fastcall shortsort(
        char *lo,
        char *hi,
        unsigned __int64 width,
        int (__fastcall *comp)(const void *, const void *))
{
  char *v4; // r12
  char *v7; // rsi
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
    v7 = hi;
    do
    {
      v9 = lo;
      for ( i = v4; i <= v7; i += width )
      {
        if ( comp(i, v9) > 0 )
          v9 = i;
      }
      v11 = width;
      v12 = v7;
      if ( v9 != v7 && width )
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
      v7 -= width;
    }
    while ( v7 > lo );
  }
}

