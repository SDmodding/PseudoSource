// File Line: 102
// RVA: 0xEF5FBC
BI_CTX *__fastcall bi_initialize()
{
  BI_CTX *v0; // rax
  BI_CTX *v1; // rbx
  _bigint *v2; // rax
  _bigint *v3; // rax

  v0 = (BI_CTX *)ax_calloc(1ui64, 0x78ui64);
  v1 = v0;
  if ( v0 )
  {
    v2 = alloc(v0, 2);
    v1->bi_radix = v2;
    *v2->comps = 0;
    v1->bi_radix->comps[1] = 1;
    v3 = v1->bi_radix;
    if ( v3->refs != 1 )
      abort();
    v3->refs = 2147440042;
  }
  return v1;
}

// File Line: 124
// RVA: 0xEF698C
void __fastcall bi_terminate(BI_CTX *ctx)
{
  _bigint *v1; // rax
  BI_CTX *v2; // rbx

  v1 = ctx->bi_radix;
  v2 = ctx;
  if ( v1->refs != 2147440042 )
    abort();
  v1->refs = 1;
  bi_free(ctx, ctx->bi_radix);
  if ( v2->active_count )
    abort();
  bi_clear_cache(v2);
  ax_free(v2);
}

// File Line: 145
// RVA: 0xEF5860
void __fastcall bi_clear_cache(BI_CTX *ctx)
{
  _bigint *v1; // rsi
  BI_CTX *v2; // rdi
  _bigint *v3; // rbx

  v1 = ctx->free_list;
  v2 = ctx;
  if ( v1 )
  {
    do
    {
      v3 = v1->next;
      ax_free(v1->comps);
      ax_free(v1);
      v1 = v3;
    }
    while ( v3 );
    v2->free_count = 0;
    v2->free_list = 0i64;
  }
}

// File Line: 183
// RVA: 0xEF6644
void __fastcall bi_permanent(_bigint *bi)
{
  if ( bi->refs != 1 )
    abort();
  bi->refs = 2147440042;
}

// File Line: 201
// RVA: 0xEF5A10
void __fastcall bi_depermanent(_bigint *bi)
{
  if ( bi->refs != 2147440042 )
    abort();
  bi->refs = 1;
}

// File Line: 222
// RVA: 0xEF5E5C
void __fastcall bi_free(BI_CTX *ctx, _bigint *bi)
{
  int v2; // eax
  int v3; // eax
  bool v4; // sf

  v2 = bi->refs;
  if ( v2 != 2147440042 )
  {
    v3 = v2 - 1;
    bi->refs = v3;
    if ( v3 <= 0 )
    {
      bi->next = ctx->free_list;
      ++ctx->free_count;
      v4 = ctx->active_count-- - 1 < 0;
      ctx->free_list = bi;
      if ( v4 )
        abort();
    }
  }
}

// File Line: 267
// RVA: 0xEF58B0
_bigint *__fastcall bi_clone(BI_CTX *ctx, _bigint *bi)
{
  _bigint *v2; // rdi
  _bigint *v3; // rbx

  v2 = bi;
  v3 = alloc(ctx, bi->size);
  memmove(v3->comps, v2->comps, 4 * v2->size);
  return v3;
}

// File Line: 282
// RVA: 0xEF562C
_bigint *__fastcall bi_add(BI_CTX *ctx, _bigint *bia, _bigint *bib)
{
  __int16 v3; // ax
  _bigint *v4; // rsi
  BI_CTX *v5; // r14
  int v6; // ebx
  _bigint *v7; // rdi
  int v8; // ebp
  unsigned int *v9; // r9
  unsigned int *v10; // r10
  unsigned int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // er8
  BOOL v14; // ebx

  v3 = bib->size;
  v4 = bia;
  v5 = ctx;
  v6 = 0;
  if ( bia->size > v3 )
    v3 = bia->size;
  v7 = bib;
  v8 = v3;
  more_comps(bia, v3 + 1);
  more_comps(v7, v8);
  v9 = v4->comps;
  v10 = v7->comps;
  do
  {
    v11 = *v10;
    ++v10;
    v12 = *v9 + v11;
    v13 = v12 + v6;
    v14 = v12 < *v9;
    *v9 = v13;
    ++v9;
    v6 = v13 < v12 || v14;
    --v8;
  }
  while ( v8 );
  *v9 = v6;
  bi_free(v5, v7);
  return trim(v4);
}

// File Line: 322
// RVA: 0xEF68E8
_bigint *__fastcall bi_subtract(BI_CTX *ctx, _bigint *bia, _bigint *bib, int *is_negative)
{
  int v4; // er14
  _bigint *v5; // rbp
  BI_CTX *v6; // r15
  int *v7; // rdi
  _bigint *v8; // rsi
  int v9; // ebx
  unsigned int *v10; // r8
  unsigned int *v11; // r9
  unsigned int v12; // ecx
  unsigned int v13; // edx
  BOOL v14; // ebx
  _bigint *v15; // rax

  v4 = bia->size;
  v5 = bia;
  v6 = ctx;
  v7 = is_negative;
  v8 = bib;
  v9 = 0;
  more_comps(bib, v4);
  v10 = v5->comps;
  v11 = v8->comps;
  do
  {
    v12 = *v10 - *v11;
    ++v11;
    v13 = v12 - v9;
    v14 = v12 > *v10;
    *v10 = v13;
    ++v10;
    v9 = v13 > v12 || v14;
    --v4;
  }
  while ( v4 );
  if ( v7 )
    *v7 = v9;
  v15 = trim(v8);
  bi_free(v6, v15);
  return trim(v5);
}

// File Line: 356
// RVA: 0xEF6020
_bigint *__fastcall bi_int_multiply(BI_CTX *ctx, _bigint *bia, unsigned int b)
{
  __int64 v3; // rbx
  _bigint *v4; // r14
  unsigned int v5; // edi
  BI_CTX *v6; // r15
  _bigint *v7; // rax
  unsigned int *v8; // r12
  unsigned int *v9; // rsi
  _bigint *v10; // r13
  unsigned int v11; // ebp
  __int64 v12; // rdx
  __int64 v13; // rcx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx

  v3 = bia->size;
  v4 = bia;
  v5 = b;
  v6 = ctx;
  v7 = alloc(ctx, (signed int)v3 + 1);
  v8 = v4->comps;
  v9 = v7->comps;
  v10 = v7;
  v11 = 0;
  memset(v7->comps, 0, 4 * (signed int)v3 + 4);
  v12 = 0i64;
  do
  {
    v13 = v8[v12++];
    v14 = *v9 + v11 + v5 * v13;
    *v9 = v14;
    v15 = v14 >> 32;
    ++v9;
    v11 = v15;
  }
  while ( v12 < v3 );
  *v9 = v15;
  bi_free(v6, v4);
  return trim(v10);
}

// File Line: 392
// RVA: 0xEF5A30
_bigint *__fastcall bi_divide(BI_CTX *ctx, _bigint *u, _bigint *v, int is_mod)
{
  int v4; // er12
  int v5; // er15
  char v6; // al
  unsigned __int64 v7; // rbx
  _bigint *v8; // rbp
  int v9; // er14
  _bigint *v10; // rsi
  BI_CTX *v11; // rdi
  _bigint *result; // rax
  _bigint *v13; // r13
  _bigint *v14; // r12
  _bigint *v15; // rbp
  int v16; // ecx
  __int64 v17; // r15
  int v18; // eax
  int v19; // er14
  size_t v20; // r8
  __int64 v21; // r11
  unsigned int *v22; // rax
  __int64 v23; // r9
  unsigned int *v24; // r10
  unsigned __int64 v25; // r8
  unsigned __int64 v26; // r14
  int v27; // eax
  _bigint *v28; // rax
  int v29; // eax
  int v30; // er14
  _bigint *v31; // rax
  __int64 v32; // r9
  unsigned int *v33; // r8
  unsigned __int64 v34; // rtt
  _bigint *v35; // rcx
  int n; // [rsp+20h] [rbp-68h]
  unsigned __int64 b; // [rsp+28h] [rbp-60h]
  size_t Size; // [rsp+30h] [rbp-58h]
  __int64 v39; // [rsp+38h] [rbp-50h]
  int is_negative; // [rsp+90h] [rbp+8h]
  int v41; // [rsp+98h] [rbp+10h]
  int v42; // [rsp+A0h] [rbp+18h]
  int v43; // [rsp+A8h] [rbp+20h]

  v43 = is_mod;
  v4 = v->size;
  v5 = u->size;
  v6 = ctx->mod_offset;
  v7 = 0i64;
  v8 = v;
  v9 = v5 - v4;
  v10 = u;
  v11 = ctx;
  v42 = v->size;
  v41 = 0;
  LOBYTE(is_negative) = v6;
  if ( is_mod && (signed int)bi_compare(v, u) > 0 )
  {
    bi_free(v11, v8);
    result = v10;
  }
  else
  {
    v13 = alloc(v11, v9 + 1);
    n = v4 + 1;
    v14 = alloc(v11, v4 + 1);
    v15 = trim(v8);
    b = 0x100000000ui64 / (v15->comps[v15->size - 1] + 1);
    memset(v13->comps, 0, 4 * v13->size);
    if ( (unsigned int)b > 1 )
    {
      v10 = bi_int_multiply(v11, v10, b);
      if ( v43 )
        v15 = v11->bi_normalised_mod[(unsigned __int8)is_negative];
      else
        v15 = bi_int_multiply(v11, v15, b);
    }
    if ( v5 == v10->size )
      more_comps(v10, v5 + 1);
    v16 = v42;
    v17 = 0i64;
    v39 = v9;
    v18 = 4 * v42 + 4;
    v19 = 0;
    v20 = v18;
    Size = v18;
    do
    {
      memmove(v14->comps, &v10->comps[v10->size - v19 - v16 - 1], v20);
      v21 = v15->size;
      v22 = v15->comps;
      v23 = v14->size;
      v24 = v14->comps;
      v25 = v22[v21 - 1];
      if ( v24[v23 - 1] == (_DWORD)v25 )
      {
        LODWORD(v26) = -1;
      }
      else
      {
        v26 = (((unsigned __int64)v24[v23 - 1] << 32) + v24[v23 - 2]) / v25;
        v22 = v15->comps;
      }
      if ( v15->size > 1
        && v22[v21 - 2]
        && (unsigned int)v26 * (unsigned __int64)v15->comps[v21 - 2] > v24[v23 - 3]
                                                                     + ((unsigned __int64)(v24[v23 - 2]
                                                                                         - (_DWORD)v26 * (_DWORD)v25) << 32) )
      {
        LODWORD(v26) = v26 - 1;
      }
      if ( (_DWORD)v26 )
      {
        v27 = v15->refs;
        if ( v27 != 2147440042 )
          v15->refs = v27 + 1;
        v28 = bi_int_multiply(v11, v15, v26);
        v14 = bi_subtract(v11, v14, v28, &is_negative);
        more_comps(v14, n);
        v13->comps[v13->size - v17 - 1] = v26;
        if ( is_negative )
        {
          --v13->comps[v13->size - v17 - 1];
          v29 = v15->refs;
          if ( v29 != 2147440042 )
            v15->refs = v29 + 1;
          v14 = bi_add(v11, v14, v15);
          --v14->size;
          --v15->size;
        }
      }
      else
      {
        v13->comps[v13->size - v17 - 1] = 0;
      }
      v30 = v41;
      memmove(&v10->comps[v10->size - v41 - v42 - 1], v14->comps, Size);
      v16 = v42;
      v20 = Size;
      v19 = v30 + 1;
      ++v17;
      v41 = v19;
    }
    while ( v17 <= v39 );
    bi_free(v11, v14);
    bi_free(v11, v15);
    if ( v43 )
    {
      bi_free(v11, v13);
      v31 = trim(v10);
      v32 = v31->size - 1;
      do
      {
        v33 = v31->comps;
        v34 = (v7 << 32) + v33[v32];
        v33[v32--] = v34 / (unsigned int)b;
        v7 = v34 % (unsigned int)b;
      }
      while ( v32 >= 0 );
      v35 = v31;
    }
    else
    {
      bi_free(v11, v10);
      v35 = v13;
    }
    result = trim(v35);
  }
  return result;
}

// File Line: 628
// RVA: 0xEF5F24
_bigint *__fastcall bi_import(BI_CTX *ctx, const char *data, int size)
{
  const char *v3; // rbp
  int v4; // ebx
  int v5; // edi
  _bigint *v6; // rsi
  __int64 v7; // r9
  __int64 v8; // r8
  char v9; // cl

  v3 = data;
  v4 = size;
  v5 = 0;
  v6 = alloc(ctx, (size + 3) / 4);
  memset(v6->comps, 0, 4 * v6->size);
  v7 = v4 - 1;
  if ( v4 - 1 >= 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = 8 * v5++;
      v6->comps[v8] += (unsigned __int8)v3[v7] << v9;
      if ( v5 == 4 )
      {
        v5 = 0;
        ++v8;
      }
      --v7;
    }
    while ( v7 >= 0 );
  }
  return trim(v6);
}

// File Line: 715
// RVA: 0xEF5DC4
void __fastcall bi_export(BI_CTX *ctx, _bigint *x, char *data, int size)
{
  char *v4; // rbp
  _bigint *v5; // rdi
  BI_CTX *v6; // rsi
  int v7; // ebx
  signed int v8; // er9
  __int64 v9; // r10
  __int64 v10; // r8
  signed int v11; // ecx

  v4 = data;
  v5 = x;
  v6 = ctx;
  v7 = size - 1;
  memset(data, 0, size);
  v8 = 0;
  v9 = v7;
  if ( v5->size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = 0;
      do
      {
        v4[v9--] = (v5->comps[v10] & (255 << v11)) >> v11;
        if ( v9 < 0 )
          break;
        v11 += 8;
      }
      while ( v11 < 32 );
      ++v8;
      ++v10;
    }
    while ( v8 < v5->size );
  }
  bi_free(v6, v5);
}

// File Line: 753
// RVA: 0xEF6660
void __fastcall bi_set_mod(BI_CTX *ctx, _bigint *bim, int mod_offset)
{
  __int64 v3; // r14
  __int64 v4; // rbp
  unsigned __int64 v5; // r9
  unsigned __int64 v6; // rax
  BI_CTX *v7; // rbx
  _bigint *v8; // rax
  int v9; // er14
  _bigint *v10; // rax
  _bigint *v11; // rdi
  int v12; // eax
  int v13; // esi
  unsigned int *v14; // r8
  unsigned int *v15; // rcx
  unsigned int *v16; // rdx
  unsigned int v17; // eax
  int v18; // eax
  _bigint *v19; // rax

  v3 = bim->size;
  v4 = mod_offset;
  v5 = bim->comps[v3 - 1] + 1;
  ctx->bi_mod[mod_offset] = bim;
  v6 = 0x100000000i64 / v5;
  v7 = ctx;
  if ( bim->refs != 1 )
    abort();
  bim->refs = 2147440042;
  v8 = bi_int_multiply(ctx, bim, v6);
  v7->bi_normalised_mod[v4] = v8;
  if ( v8->refs != 1 )
    abort();
  v8->refs = 2147440042;
  v9 = 2 * v3 - 1;
  v10 = bi_clone(v7, v7->bi_radix);
  v11 = v10;
  v12 = v10->size;
  v13 = v12 - 1;
  if ( v9 > 0 )
  {
    more_comps(v11, v12 + v9);
    v14 = v11->comps;
    v15 = &v14[v9 + v13];
    v16 = &v14[v13];
    do
    {
      v17 = *v16;
      --v16;
      *v15 = v17;
      v18 = v13--;
      --v15;
    }
    while ( v18 );
    memset(v11->comps, 0, 4 * v9);
  }
  v19 = bi_divide(v7, v11, v7->bi_mod[v4], 0);
  v7->bi_mu[v4] = v19;
  if ( v19->refs != 1 )
    abort();
  v19->refs = 2147440042;
}

// File Line: 792
// RVA: 0xEF5E94
void __fastcall bi_free_mod(BI_CTX *ctx, int mod_offset)
{
  __int64 v2; // rdi
  BI_CTX *v3; // rbx
  _bigint *v4; // rax
  _bigint *v5; // rax
  _bigint *v6; // rax

  v2 = mod_offset;
  v3 = ctx;
  v4 = ctx->bi_mod[mod_offset];
  if ( v4->refs != 2147440042 )
    abort();
  v4->refs = 1;
  bi_free(ctx, ctx->bi_mod[mod_offset]);
  v5 = v3->bi_mu[v2];
  if ( v5->refs != 2147440042 )
    abort();
  v5->refs = 1;
  bi_free(v3, v3->bi_mu[v2]);
  v6 = v3->bi_normalised_mod[v2];
  if ( v6->refs != 2147440042 )
    abort();
  v6->refs = 1;
  bi_free(v3, v3->bi_normalised_mod[v2]);
}

// File Line: 915
// RVA: 0xEF6550
_bigint *__fastcall bi_multiply(BI_CTX *ctx, _bigint *bia, _bigint *bib)
{
  __int64 v3; // rdi
  __int64 v4; // rsi
  _bigint *v5; // rbp
  _bigint *v6; // r13
  _bigint *v7; // rax
  unsigned int *v8; // rbp
  unsigned int *v9; // r15
  unsigned int *v10; // r12
  __int64 v11; // rdx
  signed __int64 v12; // rbp
  unsigned int *v13; // r10
  __int64 v14; // r14
  __int64 v15; // rdi
  unsigned __int64 v16; // r8
  __int64 v17; // r11
  __int64 v18; // rbx
  unsigned int *v19; // r9
  unsigned __int64 v20; // rcx
  BI_CTX *ctxa; // [rsp+70h] [rbp+8h]
  _bigint *bi; // [rsp+78h] [rbp+10h]
  _bigint *v24; // [rsp+88h] [rbp+20h]

  bi = bia;
  ctxa = ctx;
  v3 = bia->size;
  v4 = bib->size;
  v5 = bia;
  v6 = bib;
  v7 = alloc(ctx, (signed int)v4 + (signed int)v3);
  v8 = v5->comps;
  v9 = v6->comps;
  v10 = v7->comps;
  v24 = v7;
  memset(v7->comps, 0, 4 * ((signed int)v4 + (signed int)v3));
  v11 = 0i64;
  v12 = (char *)v8 - (char *)v10;
  v13 = v10;
  v14 = v3;
  do
  {
    v15 = *v9;
    LODWORD(v16) = 0;
    v17 = v11;
    ++v9;
    v18 = 0i64;
    v19 = v13;
    do
    {
      ++v18;
      ++v17;
      v20 = (unsigned int)v16 + *v19 + v15 * *(unsigned int *)((char *)v19 + v12);
      *v19 = v20;
      ++v19;
      v16 = v20 >> 32;
    }
    while ( v18 < v14 );
    ++v11;
    ++v13;
    v12 -= 4i64;
    v10[v17] = v16;
  }
  while ( v11 < v4 );
  bi_free(ctxa, bi);
  bi_free(ctxa, v6);
  return trim(v24);
}

// File Line: 997
// RVA: 0xEF679C
_bigint *__fastcall bi_square(BI_CTX *ctx, _bigint *bia)
{
  signed __int64 v2; // rbx
  _bigint *v3; // r13
  _bigint *v4; // rax
  unsigned int *v5; // rdi
  unsigned int *v6; // r14
  __int64 v7; // rdx
  char *v8; // rbp
  signed __int64 v9; // rsi
  signed __int64 v10; // r8
  signed __int64 v11; // r15
  unsigned __int64 v12; // rcx
  signed int v13; // ebx
  unsigned __int64 v14; // rcx
  unsigned int *v15; // r9
  signed __int64 v16; // r10
  unsigned __int64 v17; // r11
  signed __int64 v18; // r12
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rcx
  BI_CTX *ctxa; // [rsp+60h] [rbp+8h]
  signed __int64 v23; // [rsp+68h] [rbp+10h]
  _bigint *bi; // [rsp+70h] [rbp+18h]

  ctxa = ctx;
  v2 = bia->size;
  v3 = bia;
  v4 = alloc(ctx, 2 * (signed int)v2);
  v5 = v3->comps;
  v6 = v4->comps;
  bi = v4;
  memset(v4->comps, 0, 4 * v4->size);
  v7 = 0i64;
  v8 = (char *)((char *)v5 - (char *)v6);
  v9 = v2;
  v10 = (signed __int64)v6 + 4 * v2 - (_QWORD)v5;
  v23 = (signed __int64)v6 + 4 * v2 - (_QWORD)v5;
  do
  {
    v11 = v7 + 1;
    v12 = v6[2 * v7] + *v5 * (unsigned __int64)*v5;
    v13 = 0;
    v6[2 * v7] = v12;
    v14 = v12 >> 32;
    if ( v7 + 1 < v9 )
    {
      v15 = &v6[v11 + v7];
      v16 = v9 - v11;
      do
      {
        v17 = *v5 * (unsigned __int64)*(unsigned int *)&v8[(_QWORD)v15];
        v18 = 2 * v17;
        v19 = (unsigned int)v14 + (unsigned __int64)*v15;
        if ( v13 )
          v19 += 0x100000000i64;
        v13 = 0;
        v20 = v19 + v18;
        if ( -1i64 - v17 < v17 || -1 - v18 < v19 )
          v13 = 1;
        *v15 = v20;
        v14 = v20 >> 32;
        ++v15;
        --v16;
      }
      while ( v16 );
      v10 = v23;
    }
    *(unsigned int *)((char *)v5 + v10) += v14;
    if ( v13 )
      v6[v9 + 1 + v7] = 1;
    ++v5;
    v8 -= 4;
    ++v7;
  }
  while ( v11 < v9 );
  bi_free(ctxa, v3);
  return trim(bi);
}

// File Line: 1020
// RVA: 0xEF58F0
__int64 __fastcall bi_compare(_bigint *bia, _bigint *bib)
{
  __int16 v2; // ax
  _bigint *v3; // r8
  __int128 v4; // ax
  unsigned int *v5; // rcx
  int v6; // er8
  char *v7; // r10
  unsigned int *v8; // r9
  unsigned int v9; // eax

  v2 = bib->size;
  v3 = bia;
  if ( bia->size > v2 )
  {
LABEL_9:
    DWORD2(v4) = 1;
    return DWORD2(v4);
  }
  if ( bia->size >= v2 )
  {
    v5 = bia->comps;
    v6 = v3->size - 1;
    v7 = (char *)((char *)bib->comps - (char *)v5);
    v4 = (unsigned __int64)v6;
    v8 = &v5[v6];
    while ( 1 )
    {
      v9 = *(unsigned int *)((char *)v8 + (_QWORD)v7);
      if ( *v8 > v9 )
        goto LABEL_9;
      if ( *v8 < v9 )
        break;
      --v8;
      if ( --v6 < 0 )
        return DWORD2(v4);
    }
  }
  DWORD2(v4) = -1;
  return DWORD2(v4);
}

// File Line: 1062
// RVA: 0xEF69DC
void __fastcall more_comps(_bigint *bi, int n)
{
  int v2; // eax
  int v3; // edi
  _bigint *v4; // rbx
  int v5; // eax
  __int16 v6; // r8
  __int64 v7; // rax
  int v8; // ecx

  v2 = bi->max_comps;
  v3 = n;
  v4 = bi;
  if ( n <= v2 )
    goto LABEL_11;
  v5 = 2 * v2;
  v6 = n;
  if ( v5 > n )
    v6 = v5;
  bi->max_comps = v6;
  v7 = ax_realloc(bi->comps, 4 * v6);
  v4->comps = (unsigned int *)v7;
  if ( v7 )
  {
LABEL_11:
    v8 = v4->size;
    if ( v3 > v8 )
      memset(&v4->comps[v4->size], 0, 4 * (v3 - v8));
    v4->size = v3;
  }
  else
  {
    *(_DWORD *)&v4->size = 0;
  }
}

// File Line: 1088
// RVA: 0xEF5590
_bigint *__fastcall alloc(BI_CTX *ctx, int size)
{
  _bigint *v2; // rbx
  int v3; // esi
  BI_CTX *v4; // rdi
  _bigint *v5; // rax
  __int64 v7; // rax

  v2 = ctx->free_list;
  v3 = size;
  v4 = ctx;
  if ( v2 )
  {
    v5 = v2->next;
    --ctx->free_count;
    ctx->free_list = v5;
    if ( v2->refs )
      abort();
    more_comps(v2, size);
    goto LABEL_9;
  }
  v2 = (_bigint *)ax_malloc(0x18ui64);
  if ( !v2 )
    return 0i64;
  v7 = ax_malloc(4 * v3);
  v2->comps = (unsigned int *)v7;
  if ( !v7 )
  {
    ax_free(v2);
    return 0i64;
  }
  v2->max_comps = v3;
LABEL_9:
  v2->next = 0i64;
  v2->size = v3;
  v2->refs = 1;
  ++v4->active_count;
  return v2;
}

// File Line: 1201
// RVA: 0xEF6C50
_bigint *__fastcall trim(_bigint *bi)
{
  unsigned int *v1; // rdx
  __int64 i; // rax
  __int16 v3; // ax

  v1 = bi->comps;
  for ( i = bi->size; !v1[i - 1]; i = (signed __int16)i )
  {
    v3 = bi->size;
    if ( v3 <= 1 )
      break;
    LOWORD(i) = v3 - 1;
    bi->size = i;
  }
  return bi;
}

// File Line: 1275
// RVA: 0xEF6A5C
_bigint *__fastcall partial_multiply(BI_CTX *ctx, _bigint *bia, _bigint *bib, int inner_partial, int outer_partial)
{
  int v5; // ebp
  __int64 v6; // r14
  _bigint *v7; // r13
  __int64 v8; // r12
  _bigint *v9; // r15
  BI_CTX *v10; // rdi
  int v11; // ebx
  _bigint *v12; // rsi
  size_t v13; // r8
  unsigned int *v14; // rcx
  unsigned int *v15; // r11
  unsigned int *v16; // rdi
  signed __int64 v17; // rsi
  __int64 v18; // r8
  __int64 v19; // rcx
  int v20; // er14
  __int64 v21; // r10
  unsigned __int64 v22; // rax
  int v23; // er9
  unsigned int *v24; // rbx
  __int64 v25; // rcx
  unsigned __int64 v26; // rcx
  unsigned __int64 v28; // [rsp+20h] [rbp-78h]
  unsigned int *v29; // [rsp+28h] [rbp-70h]
  signed __int64 v30; // [rsp+28h] [rbp-70h]
  __int64 v31; // [rsp+30h] [rbp-68h]
  unsigned int *v32; // [rsp+38h] [rbp-60h]
  _bigint *v33; // [rsp+40h] [rbp-58h]
  BI_CTX *ctxa; // [rsp+A0h] [rbp+8h]
  unsigned int *v35; // [rsp+A8h] [rbp+10h]
  unsigned int v36; // [rsp+A8h] [rbp+10h]
  _bigint *bi; // [rsp+B0h] [rbp+18h]
  int v38; // [rsp+B8h] [rbp+20h]

  bi = bib;
  ctxa = ctx;
  v5 = bia->size;
  v6 = bib->size;
  v38 = 0;
  v7 = bia;
  v8 = inner_partial;
  v9 = bib;
  v10 = ctx;
  v11 = outer_partial;
  v12 = alloc(ctx, (signed int)v6 + v5);
  v33 = v12;
  v32 = v7->comps;
  v35 = v12->comps;
  v29 = v9->comps;
  if ( (_DWORD)v8 )
  {
    v13 = 4 * (signed int)v8;
    v14 = v12->comps;
  }
  else
  {
    if ( v5 < outer_partial || (signed int)v6 < outer_partial )
    {
      bi_free(v10, v7);
      bi_free(v10, v9);
      *v12->comps = 0;
      v12->size = 1;
      return v12;
    }
    v14 = &v12->comps[outer_partial];
    v13 = 4 * (v5 + (signed int)v6 - outer_partial);
  }
  memset(v14, 0, v13);
  v15 = v35;
  v16 = v29;
  v17 = (signed __int64)v32;
  v18 = 0i64;
  v31 = v6;
  v19 = outer_partial;
  v20 = outer_partial;
  do
  {
    v30 = v17;
    v21 = v18;
    v36 = *v16;
    LODWORD(v22) = 0;
    ++v16;
    v23 = v5;
    LODWORD(v28) = 0;
    if ( v11 && v18 < v19 )
    {
      v21 = v19;
      v23 = v38 + v5 - v11;
      v30 = v17 + 4i64 * v20;
      LODWORD(v22) = 0;
    }
    v24 = (unsigned int *)v30;
    do
    {
      if ( (_DWORD)v8 && v21 >= v8 )
        break;
      v25 = *v24;
      ++v24;
      v26 = (unsigned int)v28 + v15[v21] + v36 * v25;
      v15[v21++] = v26;
      v22 = v26 >> 32;
      v28 = v26 >> 32;
      --v23;
    }
    while ( v23 );
    v11 = outer_partial;
    ++v38;
    v17 = (signed __int64)v32;
    ++v18;
    --v20;
    v19 = outer_partial;
    v15[v21] = v22;
  }
  while ( v18 < v31 );
  bi_free(ctxa, v7);
  bi_free(ctxa, bi);
  return trim(v33);
}

// File Line: 1350
// RVA: 0xEF56DC
_bigint *__fastcall bi_barrett(BI_CTX *ctx, _bigint *bi)
{
  __int64 v2; // r12
  _bigint *v3; // rbp
  _bigint *v4; // r14
  BI_CTX *v5; // rbx
  int v6; // er15
  _bigint *v8; // rax
  unsigned int *v9; // r9
  _bigint *v10; // rdx
  int v11; // er8
  unsigned int *v12; // r10
  unsigned int v13; // eax
  _bigint *v14; // rax
  int v15; // edi
  unsigned int *v16; // r8
  int v17; // er9
  _bigint *v18; // rdx
  unsigned int *v19; // r10
  unsigned int v20; // eax
  _bigint *v21; // rax
  _bigint *v22; // rdi

  v2 = (unsigned __int8)ctx->mod_offset;
  v3 = bi;
  v4 = ctx->bi_mod[v2];
  v5 = ctx;
  v6 = v4->size;
  if ( bi->size > 2 * v6 )
    return bi_divide(ctx, bi, ctx->bi_mod[(unsigned __int8)ctx->mod_offset], 1);
  v8 = bi_clone(ctx, bi);
  v9 = v8->comps;
  v10 = v8;
  v11 = v8->size - (v6 - 1);
  v12 = &v9[v6 - 1];
  if ( v11 > 0 )
  {
    do
    {
      v13 = *v12;
      --v11;
      ++v12;
      *v9 = v13;
      ++v9;
    }
    while ( v11 > 0 );
    v10->size -= v6 - 1;
  }
  else
  {
    *v9 = 0;
    v8->size = 1;
  }
  v14 = partial_multiply(v5, v10, v5->bi_mu[v2], 0, v6 - 1);
  v15 = v6 + 1;
  v16 = v14->comps;
  v17 = v14->size - (v6 + 1);
  v18 = v14;
  v19 = &v16[v6 + 1];
  if ( v17 > 0 )
  {
    do
    {
      v20 = *v19;
      --v17;
      ++v19;
      *v16 = v20;
      ++v16;
    }
    while ( v17 > 0 );
    v18->size -= v15;
  }
  else
  {
    *v16 = 0;
    v14->size = 1;
  }
  if ( v3->size > v15 )
    v3->size = v15;
  v21 = partial_multiply(v5, v18, v4, v15, 0);
  if ( v21->size > v15 )
    v21->size = v15;
  v22 = bi_subtract(v5, v3, v21, 0i64);
  if ( bi_compare(v22, v4) >= 0 )
    v22 = bi_subtract(v5, v22, v4, 0i64);
  return v22;
}

// File Line: 1439
// RVA: 0xEF61B4
_bigint *__fastcall bi_mod_power(BI_CTX *ctx, _bigint *bi, _bigint *biexp)
{
  signed int v3; // er10
  BI_CTX *v4; // rbx
  _bigint *v5; // rsi
  unsigned int v6; // ecx
  int v7; // edi
  signed int v8; // er15
  _bigint *v9; // rax
  signed int v10; // ecx
  _bigint *v11; // r13
  signed int v12; // er14
  __int64 v13; // rax
  int v14; // ebp
  __int64 v15; // rax
  _bigint **v16; // rax
  _bigint **v17; // rax
  _bigint *v18; // rax
  signed __int64 v19; // rsi
  _bigint *v20; // r15
  int v21; // ecx
  _bigint *v22; // rax
  _bigint *v23; // rcx
  unsigned int *v24; // r8
  __int64 v25; // rax
  signed int v26; // ecx
  int v27; // er14
  int v28; // esi
  _bigint *v29; // rax
  __int64 v30; // rax
  signed int v31; // ecx
  _bigint *v32; // rax
  _bigint *v33; // rax
  __int64 v34; // rax
  signed int v35; // ecx
  _bigint *v36; // rax
  __int64 v37; // rdi
  _bigint *v38; // rcx
  signed int v40; // [rsp+60h] [rbp+8h]
  _bigint *bia; // [rsp+68h] [rbp+10h]
  _bigint *v42; // [rsp+70h] [rbp+18h]

  v42 = biexp;
  bia = bi;
  v3 = 31;
  v4 = ctx;
  v5 = biexp;
  v6 = 2147483648;
  while ( !(biexp->comps[biexp->size - 1] & v6) )
  {
    v6 >>= 1;
    if ( !--v3 )
    {
      v7 = -1;
      goto LABEL_6;
    }
  }
  v7 = v3 + 32 * biexp->size - 32;
LABEL_6:
  v8 = 1;
  v40 = 1;
  v9 = alloc(v4, 1);
  v10 = v7;
  v11 = v9;
  *v9->comps = 1;
  if ( v7 > 32 )
  {
    do
    {
      ++v8;
      v10 /= 5;
    }
    while ( v10 > 32 );
    v40 = v8;
  }
  v12 = 1 << (v8 - 1);
  v13 = ax_malloc(8i64 * v12);
  v14 = 0;
  v4->g = (_bigint **)v13;
  if ( v13 )
  {
    *v4->g = bi_clone(v4, bia);
    v17 = v4->g;
    if ( (*v17)->refs != 1 )
      abort();
    (*v17)->refs = 2147440042;
    v18 = bi_square(v4, *v4->g);
    v19 = 1i64;
    v20 = bi_barrett(v4, v18);
    while ( v19 < v12 )
    {
      v21 = v20->refs;
      if ( v21 != 2147440042 )
        v20->refs = v21 + 1;
      v22 = bi_multiply(v4, v4->g[v19 - 1], v20);
      v4->g[v19] = bi_barrett(v4, v22);
      v23 = v4->g[v19];
      if ( v23->refs != 1 )
        abort();
      v23->refs = 2147440042;
      ++v19;
    }
    bi_free(v4, v20);
    v8 = v40;
    v5 = v42;
    v4->window = v12;
  }
  else
  {
    v15 = ax_malloc(8ui64);
    v4->g = (_bigint **)v15;
    if ( v15 )
    {
      *v4->g = bi_clone(v4, bia);
      v16 = v4->g;
      v4->window = 1;
      if ( (*v16)->refs != 1 )
        abort();
      (*v16)->refs = 2147440042;
    }
    else
    {
      v4->window = 0;
    }
  }
  do
  {
    v24 = v5->comps;
    v25 = (unsigned int)(v7 % -32);
    v26 = 1;
    if ( (signed int)v25 > 0 )
    {
      do
      {
        v26 *= 2;
        --v25;
      }
      while ( v25 );
    }
    if ( v26 & v24[v7 / 32] )
    {
      v27 = 0;
      v28 = v7 - v8 + 1;
      if ( v28 >= 0 )
      {
        while ( 1 )
        {
          v34 = (unsigned int)(v28 % -32);
          v35 = 1;
          if ( (signed int)v34 > 0 )
          {
            do
            {
              v35 *= 2;
              --v34;
            }
            while ( v34 );
          }
          if ( v35 & v24[v28 / 32] )
            break;
          ++v28;
        }
      }
      else
      {
        v28 = 0;
      }
      for ( ; v7 >= v28; --v7 )
      {
        v29 = bi_square(v4, v11);
        v11 = bi_barrett(v4, v29);
        v30 = (unsigned int)(v7 % -32);
        v31 = 1;
        if ( (signed int)v30 > 0 )
        {
          do
          {
            v31 *= 2;
            --v30;
          }
          while ( v30 );
        }
        if ( v31 & v42->comps[v7 / 32] )
          ++v27;
        if ( v7 != v28 )
          v27 *= 2;
      }
      v32 = bi_multiply(v4, v11, v4->g[(v27 - 1) / 2]);
      v33 = bi_barrett(v4, v32);
      v7 = v28 - 1;
      v5 = v42;
    }
    else
    {
      v36 = bi_square(v4, v11);
      v33 = bi_barrett(v4, v36);
      --v7;
    }
    v11 = v33;
  }
  while ( v7 >= 0 );
  if ( v4->window > 0 )
  {
    v37 = 0i64;
    do
    {
      v38 = v4->g[v37];
      if ( v38->refs != 2147440042 )
        abort();
      v38->refs = 1;
      bi_free(v4, v4->g[v37]);
      ++v14;
      ++v37;
    }
    while ( v14 < v4->window );
  }
  ax_free(v4->g);
  bi_free(v4, bia);
  bi_free(v4, v5);
  return v11;
}

// File Line: 1541
// RVA: 0xEF60D0
_bigint *__fastcall bi_mod_power2(BI_CTX *ctx, _bigint *bi, _bigint *bim, _bigint *biexp)
{
  _bigint *v4; // r12
  _bigint *v5; // r14
  _bigint *v6; // rbp
  BI_CTX *v7; // r15
  BI_CTX *v8; // rax
  BI_CTX *v9; // rsi
  _bigint *v10; // rax
  _bigint *v11; // rbx
  _bigint *v12; // rax
  _bigint *v13; // rbx
  _bigint *v14; // rdi

  v4 = biexp;
  v5 = bim;
  v6 = bi;
  v7 = ctx;
  v8 = bi_initialize();
  v9 = v8;
  v10 = bi_clone(v8, v5);
  bi_set_mod(v9, v10, 0);
  v11 = bi_clone(v9, v4);
  v12 = bi_clone(v9, v6);
  v13 = bi_mod_power(v9, v12, v11);
  v14 = bi_clone(v7, v13);
  bi_free(v9, v13);
  bi_free_mod(v9, 0);
  bi_terminate(v9);
  bi_free(v7, v6);
  bi_free(v7, v5);
  bi_free(v7, v4);
  return v14;
}

// File Line: 1581
// RVA: 0xEF5940
_bigint *__fastcall bi_crt(BI_CTX *ctx, _bigint *bi, _bigint *dP, _bigint *dQ, _bigint *p, _bigint *q, _bigint *qInv)
{
  int v7; // eax
  _bigint *v8; // rsi
  _bigint *v9; // rdi
  BI_CTX *v10; // rbx
  _bigint *v11; // rax
  _bigint *v12; // rbp
  _bigint *v13; // rax
  _bigint *v14; // rdi
  int v15; // ecx
  _bigint *v16; // rax
  _bigint *v17; // rax
  _bigint *v18; // rax
  _bigint *v19; // rax
  _bigint *v20; // rax

  ctx->mod_offset = 1;
  v7 = bi->refs;
  v8 = dQ;
  v9 = bi;
  v10 = ctx;
  if ( v7 != 2147440042 )
    bi->refs = v7 + 1;
  v11 = bi_mod_power(ctx, bi, dP);
  v10->mod_offset = 2;
  v12 = v11;
  v13 = bi_mod_power(v10, v9, v8);
  v14 = v13;
  v15 = v13->refs;
  if ( v15 != 2147440042 )
    v13->refs = v15 + 1;
  v16 = bi_add(v10, v12, p);
  v17 = bi_subtract(v10, v16, v14, 0i64);
  v18 = bi_multiply(v10, v17, qInv);
  v10->mod_offset = 1;
  v19 = bi_barrett(v10, v18);
  v20 = bi_multiply(v10, q, v19);
  return bi_add(v10, v14, v20);
}

