// File Line: 102
// RVA: 0xEF5FBC
BI_CTX *__fastcall bi_initialize()
{
  BI_CTX *v0; // rax
  BI_CTX *v1; // rbx
  _bigint *v2; // rax
  _bigint *bi_radix; // rax

  v0 = (BI_CTX *)ax_calloc(1ui64, 0x78ui64);
  v1 = v0;
  if ( v0 )
  {
    v2 = alloc(v0, 2);
    v1->bi_radix = v2;
    *v2->comps = 0;
    v1->bi_radix->comps[1] = 1;
    bi_radix = v1->bi_radix;
    if ( bi_radix->refs != 1 )
      abort();
    bi_radix->refs = 2147440042;
  }
  return v1;
}

// File Line: 124
// RVA: 0xEF698C
void __fastcall bi_terminate(BI_CTX *ctx)
{
  _bigint *bi_radix; // rax

  bi_radix = ctx->bi_radix;
  if ( bi_radix->refs != 2147440042 )
    abort();
  bi_radix->refs = 1;
  bi_free(ctx, ctx->bi_radix);
  if ( ctx->active_count )
    abort();
  bi_clear_cache(ctx);
  ax_free(ctx);
}

// File Line: 145
// RVA: 0xEF5860
void __fastcall bi_clear_cache(BI_CTX *ctx)
{
  _bigint *free_list; // rsi
  _bigint *next; // rbx

  free_list = ctx->free_list;
  if ( free_list )
  {
    do
    {
      next = free_list->next;
      ax_free(free_list->comps);
      ax_free(free_list);
      free_list = next;
    }
    while ( next );
    ctx->free_count = 0;
    ctx->free_list = 0i64;
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
  int refs; // eax
  int v3; // eax
  bool v4; // sf

  refs = bi->refs;
  if ( refs != 2147440042 )
  {
    v3 = refs - 1;
    bi->refs = v3;
    if ( v3 <= 0 )
    {
      bi->next = ctx->free_list;
      ++ctx->free_count;
      v4 = --ctx->active_count < 0;
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
  _bigint *v3; // rbx

  v3 = alloc(ctx, bi->size);
  memmove(v3->comps, bi->comps, 4 * bi->size);
  return v3;
}

// File Line: 282
// RVA: 0xEF562C
_bigint *__fastcall bi_add(BI_CTX *ctx, _bigint *bia, _bigint *bib)
{
  __int16 size; // ax
  int v6; // ebx
  int v8; // ebp
  unsigned int *comps; // r9
  unsigned int *v10; // r10
  int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // r8d
  BOOL v14; // ebx

  size = bib->size;
  v6 = 0;
  if ( bia->size > size )
    size = bia->size;
  v8 = size;
  more_comps(bia, size + 1);
  more_comps(bib, v8);
  comps = bia->comps;
  v10 = bib->comps;
  do
  {
    v11 = *v10++;
    v12 = *comps + v11;
    v13 = v12 + v6;
    v14 = v12 < *comps;
    *comps++ = v13;
    v6 = v13 < v12 || v14;
    --v8;
  }
  while ( v8 );
  *comps = v6;
  bi_free(ctx, bib);
  return trim(bia);
}

// File Line: 322
// RVA: 0xEF68E8
_bigint *__fastcall bi_subtract(BI_CTX *ctx, _bigint *bia, _bigint *bib, int *is_negative)
{
  int size; // r14d
  int v9; // ebx
  unsigned int *comps; // r8
  unsigned int *v11; // r9
  unsigned int v12; // ecx
  unsigned int v13; // edx
  BOOL v14; // ebx
  _bigint *v15; // rax

  size = bia->size;
  v9 = 0;
  more_comps(bib, size);
  comps = bia->comps;
  v11 = bib->comps;
  do
  {
    v12 = *comps - *v11++;
    v13 = v12 - v9;
    v14 = v12 > *comps;
    *comps++ = v13;
    v9 = v13 > v12 || v14;
    --size;
  }
  while ( size );
  if ( is_negative )
    *is_negative = v9;
  v15 = trim(bib);
  bi_free(ctx, v15);
  return trim(bia);
}

// File Line: 356
// RVA: 0xEF6020
_bigint *__fastcall bi_int_multiply(BI_CTX *ctx, _bigint *bia, unsigned int b)
{
  __int64 size; // rbx
  _bigint *v7; // rax
  unsigned int *comps; // r12
  unsigned int *v9; // rsi
  _bigint *v10; // r13
  unsigned int v11; // ebp
  __int64 v12; // rdx
  __int64 v13; // rcx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx

  size = bia->size;
  v7 = alloc(ctx, (int)size + 1);
  comps = bia->comps;
  v9 = v7->comps;
  v10 = v7;
  v11 = 0;
  memset(v9, 0, 4 * (int)size + 4);
  v12 = 0i64;
  do
  {
    v13 = comps[v12++];
    v14 = *v9 + v11 + b * v13;
    *v9 = v14;
    v15 = HIDWORD(v14);
    ++v9;
    v11 = v15;
  }
  while ( v12 < size );
  *v9 = v15;
  bi_free(ctx, bia);
  return trim(v10);
}

// File Line: 392
// RVA: 0xEF5A30
_bigint *__fastcall bi_divide(BI_CTX *ctx, _bigint *u, _bigint *v, int is_mod)
{
  int v4; // r12d
  int v5; // r15d
  char mod_offset; // al
  unsigned __int64 v7; // rbx
  int v9; // r14d
  _bigint *v10; // rsi
  _bigint *v13; // r13
  _bigint *v14; // r12
  _bigint *v15; // rbp
  int v16; // ecx
  __int64 v17; // r15
  int v18; // eax
  int v19; // r14d
  size_t v20; // r8
  __int64 v21; // r11
  unsigned int *comps; // rax
  __int64 v23; // r9
  unsigned int *v24; // r10
  unsigned __int64 v25; // r8
  unsigned __int64 v26; // r14
  int refs; // eax
  _bigint *v28; // rax
  int v29; // eax
  int v30; // r14d
  _bigint *v31; // rax
  __int64 v32; // r9
  unsigned int *v33; // r8
  unsigned __int64 v34; // rdx
  _bigint *v35; // rcx
  int n; // [rsp+20h] [rbp-68h]
  unsigned __int64 b; // [rsp+28h] [rbp-60h]
  size_t Size; // [rsp+30h] [rbp-58h]
  __int64 v39; // [rsp+38h] [rbp-50h]
  int is_negative; // [rsp+90h] [rbp+8h] BYREF
  int v41; // [rsp+98h] [rbp+10h]
  int v42; // [rsp+A0h] [rbp+18h]
  int v43; // [rsp+A8h] [rbp+20h]

  v43 = is_mod;
  v4 = v->size;
  v5 = u->size;
  mod_offset = ctx->mod_offset;
  v7 = 0i64;
  v9 = v5 - v4;
  v10 = u;
  v42 = v4;
  v41 = 0;
  LOBYTE(is_negative) = mod_offset;
  if ( is_mod && (int)bi_compare(v, u) > 0 )
  {
    bi_free(ctx, v);
    return v10;
  }
  else
  {
    v13 = alloc(ctx, v9 + 1);
    n = v4 + 1;
    v14 = alloc(ctx, v4 + 1);
    v15 = trim(v);
    b = 0x100000000ui64 / (v15->comps[v15->size - 1] + 1);
    memset(v13->comps, 0, 4 * v13->size);
    if ( (unsigned int)b > 1 )
    {
      v10 = bi_int_multiply(ctx, v10, b);
      if ( v43 )
        v15 = ctx->bi_normalised_mod[(unsigned __int8)is_negative];
      else
        v15 = bi_int_multiply(ctx, v15, b);
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
      comps = v15->comps;
      v23 = v14->size;
      v24 = v14->comps;
      v25 = comps[v21 - 1];
      if ( v24[v23 - 1] == (_DWORD)v25 )
      {
        LODWORD(v26) = -1;
      }
      else
      {
        v26 = (((unsigned __int64)v24[v23 - 1] << 32) + v24[v23 - 2]) / v25;
        comps = v15->comps;
      }
      if ( v15->size > 1
        && comps[v21 - 2]
        && (unsigned int)v26 * (unsigned __int64)v15->comps[v21 - 2] > v24[v23 - 3]
                                                                     + ((unsigned __int64)(v24[v23 - 2]
                                                                                         - (_DWORD)v26 * (_DWORD)v25) << 32) )
      {
        LODWORD(v26) = v26 - 1;
      }
      if ( (_DWORD)v26 )
      {
        refs = v15->refs;
        if ( refs != 2147440042 )
          v15->refs = refs + 1;
        v28 = bi_int_multiply(ctx, v15, v26);
        v14 = bi_subtract(ctx, v14, v28, &is_negative);
        more_comps(v14, n);
        v13->comps[v13->size - v17 - 1] = v26;
        if ( is_negative )
        {
          --v13->comps[v13->size - v17 - 1];
          v29 = v15->refs;
          if ( v29 != 2147440042 )
            v15->refs = v29 + 1;
          v14 = bi_add(ctx, v14, v15);
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
    bi_free(ctx, v14);
    bi_free(ctx, v15);
    if ( v43 )
    {
      bi_free(ctx, v13);
      v31 = trim(v10);
      v32 = v31->size - 1;
      do
      {
        v33 = v31->comps;
        v34 = ((v7 << 32) + v33[v32]) % (unsigned int)b;
        v33[v32] = ((v7 << 32) + v33[v32]) / (unsigned int)b;
        --v32;
        v7 = v34;
      }
      while ( v32 >= 0 );
      v35 = v31;
    }
    else
    {
      bi_free(ctx, v10);
      v35 = v13;
    }
    return trim(v35);
  }
}

// File Line: 628
// RVA: 0xEF5F24
_bigint *__fastcall bi_import(BI_CTX *ctx, const char *data, int size)
{
  int v5; // edi
  _bigint *v6; // rsi
  __int64 v7; // r9
  __int64 v8; // r8
  char v9; // cl

  v5 = 0;
  v6 = alloc(ctx, (size + 3) / 4);
  memset(v6->comps, 0, 4 * v6->size);
  v7 = size - 1;
  if ( size - 1 >= 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = 8 * v5++;
      v6->comps[v8] += (unsigned __int8)data[v7] << v9;
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
  int v7; // ebx
  int v8; // r9d
  __int64 v9; // r10
  __int64 v10; // r8
  int i; // ecx

  v7 = size - 1;
  memset(data, 0, size);
  v8 = 0;
  v9 = v7;
  if ( x->size > 0 )
  {
    v10 = 0i64;
    do
    {
      for ( i = 0; i < 32; i += 8 )
      {
        data[v9] = (x->comps[v10] & (255 << i)) >> i;
        if ( --v9 < 0 )
          break;
      }
      ++v8;
      ++v10;
    }
    while ( v8 < x->size );
  }
  bi_free(ctx, x);
}

// File Line: 753
// RVA: 0xEF6660
void __fastcall bi_set_mod(BI_CTX *ctx, _bigint *bim, int mod_offset)
{
  __int64 size; // r14
  __int64 v4; // rbp
  unsigned __int64 v5; // r9
  _bigint *v7; // rax
  int v8; // r14d
  _bigint *v9; // rdi
  int v10; // eax
  int v11; // esi
  unsigned int *comps; // r8
  unsigned int *v13; // rcx
  unsigned int *v14; // rdx
  unsigned int v15; // eax
  int v16; // eax
  _bigint *v17; // rax

  size = bim->size;
  v4 = mod_offset;
  v5 = bim->comps[size - 1] + 1;
  ctx->bi_mod[mod_offset] = bim;
  if ( bim->refs != 1 )
    abort();
  bim->refs = 2147440042;
  v7 = bi_int_multiply(ctx, bim, 0x100000000i64 / v5);
  ctx->bi_normalised_mod[v4] = v7;
  if ( v7->refs != 1 )
    abort();
  v7->refs = 2147440042;
  v8 = 2 * size - 1;
  v9 = bi_clone(ctx, ctx->bi_radix);
  v10 = v9->size;
  v11 = v10 - 1;
  if ( v8 > 0 )
  {
    more_comps(v9, v10 + v8);
    comps = v9->comps;
    v13 = &comps[v8 + v11];
    v14 = &comps[v11];
    do
    {
      v15 = *v14--;
      *v13 = v15;
      v16 = v11--;
      --v13;
    }
    while ( v16 );
    memset(v9->comps, 0, 4 * v8);
  }
  v17 = bi_divide(ctx, v9, ctx->bi_mod[v4], 0);
  ctx->bi_mu[v4] = v17;
  if ( v17->refs != 1 )
    abort();
  v17->refs = 2147440042;
}

// File Line: 792
// RVA: 0xEF5E94
void __fastcall bi_free_mod(BI_CTX *ctx, int mod_offset)
{
  __int64 v2; // rdi
  _bigint *v4; // rax
  _bigint *v5; // rax
  _bigint *v6; // rax

  v2 = mod_offset;
  v4 = ctx->bi_mod[mod_offset];
  if ( v4->refs != 2147440042 )
    abort();
  v4->refs = 1;
  bi_free(ctx, ctx->bi_mod[mod_offset]);
  v5 = ctx->bi_mu[v2];
  if ( v5->refs != 2147440042 )
    abort();
  v5->refs = 1;
  bi_free(ctx, ctx->bi_mu[v2]);
  v6 = ctx->bi_normalised_mod[v2];
  if ( v6->refs != 2147440042 )
    abort();
  v6->refs = 1;
  bi_free(ctx, ctx->bi_normalised_mod[v2]);
}

// File Line: 915
// RVA: 0xEF6550
_bigint *__fastcall bi_multiply(BI_CTX *ctx, _bigint *bia, _bigint *bib)
{
  __int64 size; // rdi
  __int64 v4; // rsi
  _bigint *v7; // rax
  unsigned int *comps; // rbp
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
  _bigint *v24; // [rsp+88h] [rbp+20h]

  size = bia->size;
  v4 = bib->size;
  v7 = alloc(ctx, (int)v4 + (int)size);
  comps = bia->comps;
  v9 = bib->comps;
  v10 = v7->comps;
  v24 = v7;
  memset(v10, 0, 4 * ((int)v4 + (int)size));
  v11 = 0i64;
  v12 = (char *)comps - (char *)v10;
  v13 = v10;
  v14 = size;
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
      *v19++ = v20;
      v16 = HIDWORD(v20);
    }
    while ( v18 < v14 );
    ++v11;
    ++v13;
    v12 -= 4i64;
    v10[v17] = HIDWORD(v20);
  }
  while ( v11 < v4 );
  bi_free(ctx, bia);
  bi_free(ctx, bib);
  return trim(v24);
}

// File Line: 997
// RVA: 0xEF679C
_bigint *__fastcall bi_square(BI_CTX *ctx, _bigint *bia)
{
  __int64 size; // rbx
  _bigint *v4; // rax
  unsigned int *comps; // rdi
  unsigned int *v6; // r14
  __int64 v7; // rdx
  signed __int64 v8; // rbp
  __int64 v9; // rsi
  char *v10; // r8
  __int64 v11; // r15
  unsigned __int64 v12; // rcx
  int v13; // ebx
  unsigned __int64 v14; // rcx
  unsigned int *v15; // r9
  __int64 v16; // r10
  unsigned __int64 v17; // r11
  __int64 v18; // r12
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rcx
  char *v23; // [rsp+68h] [rbp+10h]
  _bigint *bi; // [rsp+70h] [rbp+18h]

  size = bia->size;
  v4 = alloc(ctx, 2 * (int)size);
  comps = bia->comps;
  v6 = v4->comps;
  bi = v4;
  memset(v6, 0, 4 * v4->size);
  v7 = 0i64;
  v8 = (char *)comps - (char *)v6;
  v9 = size;
  v10 = (char *)v6 + 4 * size - (_QWORD)comps;
  v23 = v10;
  do
  {
    v11 = v7 + 1;
    v12 = v6[2 * v7] + *comps * (unsigned __int64)*comps;
    v13 = 0;
    v6[2 * v7] = v12;
    v14 = HIDWORD(v12);
    if ( v7 + 1 < v9 )
    {
      v15 = &v6[v11 + v7];
      v16 = v9 - v11;
      do
      {
        v17 = *comps * (unsigned __int64)*(unsigned int *)((char *)v15 + v8);
        v18 = 2 * v17;
        v19 = (unsigned int)v14 + (unsigned __int64)*v15;
        if ( v13 )
          v19 += 0x100000000i64;
        v13 = 0;
        v20 = v19 + v18;
        if ( -1i64 - v17 < v17 || -1 - v18 < v19 )
          v13 = 1;
        *v15 = v20;
        v14 = HIDWORD(v20);
        ++v15;
        --v16;
      }
      while ( v16 );
      v10 = v23;
    }
    *(unsigned int *)((char *)comps + (_QWORD)v10) += v14;
    if ( v13 )
      v6[v9 + 1 + v7] = 1;
    ++comps;
    v8 -= 4i64;
    ++v7;
  }
  while ( v11 < v9 );
  bi_free(ctx, bia);
  return trim(bi);
}

// File Line: 1020
// RVA: 0xEF58F0
__int64 __fastcall bi_compare(_bigint *bia, _bigint *bib)
{
  __int16 size; // ax
  unsigned int v4; // edx
  unsigned int *comps; // rcx
  unsigned int *v6; // r10
  int v7; // r8d
  signed __int64 v8; // r10
  unsigned int *i; // r9
  unsigned int v10; // eax

  size = bib->size;
  if ( bia->size > size )
    return 1;
  if ( bia->size >= size )
  {
    comps = bia->comps;
    v6 = bib->comps;
    v7 = bia->size - 1;
    v4 = 0;
    v8 = (char *)v6 - (char *)comps;
    for ( i = &comps[v7]; ; --i )
    {
      v10 = *(unsigned int *)((char *)i + v8);
      if ( *i > v10 )
        break;
      if ( *i < v10 )
        return (unsigned int)-1;
      if ( --v7 < 0 )
        return v4;
    }
    return 1;
  }
  return (unsigned int)-1;
}

// File Line: 1062
// RVA: 0xEF69DC
void __fastcall more_comps(_bigint *bi, int n)
{
  int max_comps; // eax
  int v5; // eax
  __int16 v6; // r8
  unsigned int *v7; // rax
  int size; // ecx

  max_comps = bi->max_comps;
  if ( n <= max_comps )
    goto LABEL_6;
  v5 = 2 * max_comps;
  v6 = n;
  if ( v5 > n )
    v6 = v5;
  bi->max_comps = v6;
  v7 = (unsigned int *)ax_realloc(bi->comps, 4 * v6);
  bi->comps = v7;
  if ( v7 )
  {
LABEL_6:
    size = bi->size;
    if ( n > size )
      memset(&bi->comps[bi->size], 0, 4 * (n - size));
    bi->size = n;
  }
  else
  {
    *(_DWORD *)&bi->size = 0;
  }
}

// File Line: 1088
// RVA: 0xEF5590
_bigint *__fastcall alloc(BI_CTX *ctx, int size)
{
  _bigint *free_list; // rbx
  _bigint *next; // rax
  __int64 v7; // rax

  free_list = ctx->free_list;
  if ( free_list )
  {
    next = free_list->next;
    --ctx->free_count;
    ctx->free_list = next;
    if ( free_list->refs )
      abort();
    more_comps(free_list, size);
    goto LABEL_9;
  }
  free_list = (_bigint *)ax_malloc(0x18ui64);
  if ( !free_list )
    return 0i64;
  v7 = ax_malloc(4 * size);
  free_list->comps = (unsigned int *)v7;
  if ( !v7 )
  {
    ax_free(free_list);
    return 0i64;
  }
  free_list->max_comps = size;
LABEL_9:
  free_list->next = 0i64;
  free_list->size = size;
  free_list->refs = 1;
  ++ctx->active_count;
  return free_list;
}

// File Line: 1201
// RVA: 0xEF6C50
_bigint *__fastcall trim(_bigint *bi)
{
  unsigned int *comps; // rdx
  __int64 i; // rax
  __int16 size; // ax

  comps = bi->comps;
  for ( i = bi->size; !comps[i - 1]; i = (__int16)i )
  {
    size = bi->size;
    if ( size <= 1 )
      break;
    LOWORD(i) = size - 1;
    bi->size = i;
  }
  return bi;
}

// File Line: 1275
// RVA: 0xEF6A5C
_bigint *__fastcall partial_multiply(BI_CTX *ctx, _bigint *bia, _bigint *bib, int inner_partial, int outer_partial)
{
  int size; // ebp
  __int64 v6; // r14
  __int64 v8; // r12
  int v11; // ebx
  _bigint *v12; // rsi
  size_t v13; // r8
  unsigned int *v14; // rcx
  unsigned int *v15; // r11
  unsigned int *v16; // rdi
  unsigned int *v17; // rsi
  __int64 v18; // r8
  __int64 v19; // rcx
  int v20; // r14d
  __int64 v21; // r10
  unsigned __int64 v22; // rax
  int v23; // r9d
  unsigned int *v24; // rbx
  __int64 v25; // rcx
  unsigned __int64 v26; // rcx
  unsigned __int64 v28; // [rsp+20h] [rbp-78h]
  unsigned int *v29; // [rsp+28h] [rbp-70h]
  unsigned int *v30; // [rsp+28h] [rbp-70h]
  __int64 v31; // [rsp+30h] [rbp-68h]
  unsigned int *comps; // [rsp+38h] [rbp-60h]
  _bigint *v33; // [rsp+40h] [rbp-58h]
  unsigned int *v35; // [rsp+A8h] [rbp+10h]
  unsigned int v36; // [rsp+A8h] [rbp+10h]
  int v38; // [rsp+B8h] [rbp+20h]

  size = bia->size;
  v6 = bib->size;
  v38 = 0;
  v8 = inner_partial;
  v11 = outer_partial;
  v12 = alloc(ctx, (int)v6 + size);
  v33 = v12;
  comps = bia->comps;
  v35 = v12->comps;
  v29 = bib->comps;
  if ( (_DWORD)v8 )
  {
    v13 = 4 * (int)v8;
    v14 = v12->comps;
  }
  else
  {
    if ( size < outer_partial || (int)v6 < outer_partial )
    {
      bi_free(ctx, bia);
      bi_free(ctx, bib);
      *v12->comps = 0;
      v12->size = 1;
      return v12;
    }
    v14 = &v12->comps[outer_partial];
    v13 = 4 * (size + (int)v6 - outer_partial);
  }
  memset(v14, 0, v13);
  v15 = v35;
  v16 = v29;
  v17 = comps;
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
    v23 = size;
    LODWORD(v28) = 0;
    if ( v11 && v18 < v19 )
    {
      v21 = v19;
      v23 = v38 + size - v11;
      v30 = &v17[v20];
      LODWORD(v22) = 0;
    }
    v24 = v30;
    do
    {
      if ( (_DWORD)v8 && v21 >= v8 )
        break;
      v25 = *v24++;
      v26 = (unsigned int)v28 + v15[v21] + v36 * v25;
      v15[v21++] = v26;
      v22 = HIDWORD(v26);
      v28 = HIDWORD(v26);
      --v23;
    }
    while ( v23 );
    v11 = outer_partial;
    ++v38;
    v17 = comps;
    ++v18;
    --v20;
    v19 = outer_partial;
    v15[v21] = v22;
  }
  while ( v18 < v31 );
  bi_free(ctx, bia);
  bi_free(ctx, bib);
  return trim(v33);
}

// File Line: 1350
// RVA: 0xEF56DC
_bigint *__fastcall bi_barrett(BI_CTX *ctx, _bigint *bi)
{
  __int64 mod_offset; // r12
  _bigint *v4; // r14
  int size; // r15d
  _bigint *v8; // rax
  unsigned int *comps; // r9
  _bigint *v10; // rdx
  int v11; // r8d
  unsigned int *v12; // r10
  unsigned int v13; // eax
  _bigint *v14; // rax
  int v15; // edi
  unsigned int *v16; // r8
  int v17; // r9d
  _bigint *v18; // rdx
  unsigned int *v19; // r10
  unsigned int v20; // eax
  _bigint *v21; // rax
  _bigint *v22; // rdi

  mod_offset = (unsigned __int8)ctx->mod_offset;
  v4 = ctx->bi_mod[mod_offset];
  size = v4->size;
  if ( bi->size > 2 * size )
    return bi_divide(ctx, bi, ctx->bi_mod[(unsigned __int8)ctx->mod_offset], 1);
  v8 = bi_clone(ctx, bi);
  comps = v8->comps;
  v10 = v8;
  v11 = v8->size - (size - 1);
  v12 = &comps[size - 1];
  if ( v11 > 0 )
  {
    do
    {
      v13 = *v12;
      --v11;
      ++v12;
      *comps++ = v13;
    }
    while ( v11 > 0 );
    v10->size -= size - 1;
  }
  else
  {
    *comps = 0;
    v8->size = 1;
  }
  v14 = partial_multiply(ctx, v10, ctx->bi_mu[mod_offset], 0, size - 1);
  v15 = size + 1;
  v16 = v14->comps;
  v17 = v14->size - (size + 1);
  v18 = v14;
  v19 = &v16[size + 1];
  if ( v17 > 0 )
  {
    do
    {
      v20 = *v19;
      --v17;
      ++v19;
      *v16++ = v20;
    }
    while ( v17 > 0 );
    v18->size -= v15;
  }
  else
  {
    *v16 = 0;
    v14->size = 1;
  }
  if ( bi->size > v15 )
    bi->size = v15;
  v21 = partial_multiply(ctx, v18, v4, v15, 0);
  if ( v21->size > v15 )
    v21->size = v15;
  v22 = bi_subtract(ctx, bi, v21, 0i64);
  if ( bi_compare(v22, v4) >= 0 )
    return bi_subtract(ctx, v22, v4, 0i64);
  return v22;
}

// File Line: 1439
// RVA: 0xEF61B4
_bigint *__fastcall bi_mod_power(BI_CTX *ctx, _bigint *bi, _bigint *biexp)
{
  int v3; // r10d
  _bigint *v5; // rsi
  unsigned int v6; // ecx
  int v7; // edi
  int v8; // r15d
  _bigint *v9; // rax
  int v10; // ecx
  _bigint *v11; // r13
  int v12; // r14d
  _bigint **v13; // rax
  int v14; // ebp
  _bigint **v15; // rax
  _bigint **v16; // rax
  _bigint **g; // rax
  _bigint *v18; // rax
  __int64 v19; // rsi
  _bigint *v20; // r15
  int refs; // ecx
  _bigint *v22; // rax
  _bigint *v23; // rcx
  unsigned int *comps; // r8
  __int64 v25; // rax
  int v26; // ecx
  int v27; // r14d
  int v28; // esi
  _bigint *v29; // rax
  __int64 v30; // rax
  int v31; // ecx
  _bigint *v32; // rax
  _bigint *v33; // rax
  __int64 v34; // rax
  int v35; // ecx
  _bigint *v36; // rax
  __int64 v37; // rdi
  _bigint *v38; // rcx
  int v40; // [rsp+60h] [rbp+8h]

  v3 = 31;
  v5 = biexp;
  v6 = 0x80000000;
  while ( (biexp->comps[biexp->size - 1] & v6) == 0 )
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
  v9 = alloc(ctx, 1);
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
  v13 = (_bigint **)ax_malloc(8i64 * v12);
  v14 = 0;
  ctx->g = v13;
  if ( v13 )
  {
    *ctx->g = bi_clone(ctx, bi);
    g = ctx->g;
    if ( (*g)->refs != 1 )
      abort();
    (*g)->refs = 2147440042;
    v18 = bi_square(ctx, *ctx->g);
    v19 = 1i64;
    v20 = bi_barrett(ctx, v18);
    while ( v19 < v12 )
    {
      refs = v20->refs;
      if ( refs != 2147440042 )
        v20->refs = refs + 1;
      v22 = bi_multiply(ctx, ctx->g[v19 - 1], v20);
      ctx->g[v19] = bi_barrett(ctx, v22);
      v23 = ctx->g[v19];
      if ( v23->refs != 1 )
        abort();
      v23->refs = 2147440042;
      ++v19;
    }
    bi_free(ctx, v20);
    v8 = v40;
    v5 = biexp;
    ctx->window = v12;
  }
  else
  {
    v15 = (_bigint **)ax_malloc(8ui64);
    ctx->g = v15;
    if ( v15 )
    {
      *ctx->g = bi_clone(ctx, bi);
      v16 = ctx->g;
      ctx->window = 1;
      if ( (*v16)->refs != 1 )
        abort();
      (*v16)->refs = 2147440042;
    }
    else
    {
      ctx->window = 0;
    }
  }
  do
  {
    comps = v5->comps;
    v25 = (unsigned int)(v7 % 32);
    v26 = 1;
    if ( (int)v25 > 0 )
    {
      do
      {
        v26 *= 2;
        --v25;
      }
      while ( v25 );
    }
    if ( (v26 & comps[v7 / 32]) != 0 )
    {
      v27 = 0;
      v28 = v7 - v8 + 1;
      if ( v28 >= 0 )
      {
        while ( 1 )
        {
          v34 = (unsigned int)(v28 % 32);
          v35 = 1;
          if ( (int)v34 > 0 )
          {
            do
            {
              v35 *= 2;
              --v34;
            }
            while ( v34 );
          }
          if ( (v35 & comps[v28 / 32]) != 0 )
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
        v29 = bi_square(ctx, v11);
        v11 = bi_barrett(ctx, v29);
        v30 = (unsigned int)(v7 % 32);
        v31 = 1;
        if ( (int)v30 > 0 )
        {
          do
          {
            v31 *= 2;
            --v30;
          }
          while ( v30 );
        }
        if ( (v31 & biexp->comps[v7 / 32]) != 0 )
          ++v27;
        if ( v7 != v28 )
          v27 *= 2;
      }
      v32 = bi_multiply(ctx, v11, ctx->g[(v27 - 1) / 2]);
      v33 = bi_barrett(ctx, v32);
      v7 = v28 - 1;
      v5 = biexp;
    }
    else
    {
      v36 = bi_square(ctx, v11);
      v33 = bi_barrett(ctx, v36);
      --v7;
    }
    v11 = v33;
  }
  while ( v7 >= 0 );
  if ( ctx->window > 0 )
  {
    v37 = 0i64;
    do
    {
      v38 = ctx->g[v37];
      if ( v38->refs != 2147440042 )
        abort();
      v38->refs = 1;
      bi_free(ctx, ctx->g[v37]);
      ++v14;
      ++v37;
    }
    while ( v14 < ctx->window );
  }
  ax_free(ctx->g);
  bi_free(ctx, bi);
  bi_free(ctx, v5);
  return v11;
}t();
      v38->refs = 

// File Line: 1541
// RVA: 0xEF60D0
_bigint *__fastcall bi_mod_power2(BI_CTX *ctx, _bigint *bi, _bigint *bim, _bigint *biexp)
{
  BI_CTX *v8; // rsi
  _bigint *v9; // rax
  _bigint *v10; // rbx
  _bigint *v11; // rax
  _bigint *v12; // rbx
  _bigint *v13; // rdi

  v8 = bi_initialize();
  v9 = bi_clone(v8, bim);
  bi_set_mod(v8, v9, 0);
  v10 = bi_clone(v8, biexp);
  v11 = bi_clone(v8, bi);
  v12 = bi_mod_power(v8, v11, v10);
  v13 = bi_clone(ctx, v12);
  bi_free(v8, v12);
  bi_free_mod(v8, 0);
  bi_terminate(v8);
  bi_free(ctx, bi);
  bi_free(ctx, bim);
  bi_free(ctx, biexp);
  return v13;
}

// File Line: 1581
// RVA: 0xEF5940
_bigint *__fastcall bi_crt(BI_CTX *ctx, _bigint *bi, _bigint *dP, _bigint *dQ, _bigint *p, _bigint *q, _bigint *qInv)
{
  int refs; // eax
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
  refs = bi->refs;
  if ( refs != 2147440042 )
    bi->refs = refs + 1;
  v11 = bi_mod_power(ctx, bi, dP);
  ctx->mod_offset = 2;
  v12 = v11;
  v13 = bi_mod_power(ctx, bi, dQ);
  v14 = v13;
  v15 = v13->refs;
  if ( v15 != 2147440042 )
    v13->refs = v15 + 1;
  v16 = bi_add(ctx, v12, p);
  v17 = bi_subtract(ctx, v16, v14, 0i64);
  v18 = bi_multiply(ctx, v17, qInv);
  ctx->mod_offset = 1;
  v19 = bi_barrett(ctx, v18);
  v20 = bi_multiply(ctx, q, v19);
  return bi_add(ctx, v14, v20);
}

