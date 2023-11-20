// File Line: 411
// RVA: 0xAA1340
void __fastcall block_remove(pool_t *pool, block_header_t *block)
{
  block_header_t *v2; // rsi
  pool_t *v3; // rdi
  unsigned __int64 v4; // rbx
  int v5; // er8
  int v6; // ebx
  int v7; // eax
  block_header_t *v8; // rcx
  pool_t *v9; // rdx
  signed __int64 v10; // rcx
  int v11; // eax
  bool v12; // zf

  v2 = block;
  v3 = pool;
  v4 = block->size & 0xFFFFFFFFFFFFFFFCui64;
  if ( v4 >= 0x100 )
  {
    v7 = tlsf_fls_sizet(block->size & 0xFFFFFFFFFFFFFFFCui64);
    v5 = v7 - 7;
    v6 = (v4 >> ((unsigned __int8)v7 - 5)) ^ 0x20;
  }
  else
  {
    v5 = 0;
    v6 = (signed int)v4 / 8;
  }
  v8 = v2->prev_free;
  v9 = (pool_t *)v2->next_free;
  v9->block_null.prev_free = v8;
  v8->next_free = &v9->block_null;
  v10 = v6 + 32i64 * v5;
  if ( v3->blocks[0][v10] == v2 )
  {
    v3->blocks[0][v10] = &v9->block_null;
    if ( v9 == v3 )
    {
      v11 = ~(1 << v6);
      v12 = (v11 & v3->sl_bitmap[v5]) == 0;
      v3->sl_bitmap[v5] &= v11;
      if ( v12 )
        v3->fl_bitmap &= ~(1 << v5);
    }
  }
}

// File Line: 419
// RVA: 0xAA1050
void __fastcall block_insert(pool_t *pool, block_header_t *block)
{
  block_header_t *v2; // rdi
  pool_t *v3; // rsi
  unsigned __int64 v4; // rbx
  int v5; // er9
  int v6; // ebx
  int v7; // eax
  signed __int64 v8; // rdx
  block_header_t *v9; // rax

  v2 = block;
  v3 = pool;
  v4 = block->size & 0xFFFFFFFFFFFFFFFCui64;
  if ( v4 >= 0x100 )
  {
    v7 = tlsf_fls_sizet(block->size & 0xFFFFFFFFFFFFFFFCui64);
    v5 = v7 - 7;
    v6 = (v4 >> ((unsigned __int8)v7 - 5)) ^ 0x20;
  }
  else
  {
    v5 = 0;
    v6 = (signed int)v4 / 8;
  }
  v8 = v6 + 32i64 * v5;
  v9 = v3->blocks[0][v8];
  v2->prev_free = &v3->block_null;
  v2->next_free = v9;
  v9->prev_free = v2;
  v3->blocks[0][v8] = v2;
  v3->fl_bitmap |= 1 << v5;
  v3->sl_bitmap[v5] |= 1 << v6;
}

// File Line: 522
// RVA: 0xAA1400
block_header_t *__fastcall block_trim_free_leading(pool_t *pool, block_header_t *block, unsigned __int64 size)
{
  unsigned __int64 v3; // r9
  char *v4; // rbx
  unsigned __int64 v5; // rax

  v3 = block->size & 0xFFFFFFFFFFFFFFFCui64;
  if ( v3 < size + 32 )
    return block;
  v4 = (char *)block + size;
  *((_QWORD *)v4 + 1) &= 3ui64;
  *((_QWORD *)v4 + 1) |= v3 - size;
  block->size &= 3ui64;
  block->size |= size - 8;
  v5 = *(unsigned __int64 *)((_BYTE *)&block->size + size) & 0xFFFFFFFFFFFFFFFCui64;
  *(_QWORD *)&v4[v5 + 16] |= 2ui64;
  *(_QWORD *)&v4[v5 + 8] = v4;
  *((_QWORD *)v4 + 1) |= 3ui64;
  *(unsigned __int64 *)((char *)&block->size + (block->size & 0xFFFFFFFFFFFFFFFCui64)) = (unsigned __int64)block;
  block_insert(pool, block);
  return (block_header_t *)v4;
}

// File Line: 538
// RVA: 0xAA10F0
block_header_t *__fastcall block_locate_free(pool_t *pool, unsigned __int64 size)
{
  unsigned __int64 v2; // rbx
  pool_t *v3; // rdi
  int v4; // er9
  int v5; // ebx
  int v6; // eax
  __int64 v7; // r11
  __int64 v8; // r8
  int v9; // ecx
  int v10; // er10
  block_header_t *result; // rax
  bool v12; // zf
  int v13; // eax
  signed int v14; // ecx
  int v15; // ecx
  block_header_t *v16; // r8
  block_header_t *v17; // rax
  pool_t *v18; // rdx
  signed __int64 v19; // rax
  int v20; // edx

  v2 = size;
  v3 = pool;
  if ( !size )
    return 0i64;
  if ( size >= 0x20 )
    v2 = (1 << (tlsf_fls_sizet(size) - 5)) - 1 + size;
  if ( v2 >= 0x100 )
  {
    v6 = tlsf_fls_sizet(v2);
    v4 = v6 - 7;
    v5 = (v2 >> ((unsigned __int8)v6 - 5)) ^ 0x20;
  }
  else
  {
    v4 = 0;
    v5 = (signed int)v2 / 8;
  }
  v7 = v4;
  v8 = v4;
  v9 = (-1 << v5) & v3->sl_bitmap[v4];
  if ( !v9 )
  {
    v10 = v3->fl_bitmap & (-1 << (v4 + 1));
    if ( !v10 )
      return 0i64;
    v4 = tlsf_ffs(v10);
    v8 = v4;
    v7 = v4;
    v9 = v3->sl_bitmap[v4];
  }
  v12 = (v9 & -v9) == 0;
  v13 = v9 & -v9;
  v14 = 32;
  if ( v12 )
    v14 = 31;
  if ( !(v13 & 0xFFFF0000) )
  {
    v13 <<= 16;
    v14 -= 16;
  }
  if ( !(v13 & 0xFF000000) )
  {
    v13 <<= 8;
    v14 -= 8;
  }
  if ( !(v13 & 0xF0000000) )
  {
    v13 *= 16;
    v14 -= 4;
  }
  if ( !(v13 & 0xC0000000) )
  {
    v13 *= 4;
    v14 -= 2;
  }
  if ( v13 >= 0 )
    --v14;
  v15 = v14 - 1;
  v16 = v3->blocks[0][v15 + 32 * v8];
  if ( !v16 )
    return v16;
  v17 = v16->prev_free;
  v18 = (pool_t *)v16->next_free;
  v18->block_null.prev_free = v17;
  v17->next_free = &v18->block_null;
  v19 = v15 + 32 * v7;
  if ( v3->blocks[0][v19] != v16 )
    return v16;
  v3->blocks[0][v19] = &v18->block_null;
  if ( v18 != v3 )
    return v16;
  result = v16;
  v20 = ~(1 << v15);
  v12 = (v20 & v3->sl_bitmap[v7]) == 0;
  v3->sl_bitmap[v7] &= v20;
  if ( v12 )
    v3->fl_bitmap &= ~(1 << v4);
  return result;
}

// File Line: 558
// RVA: 0xAA12A0
signed __int64 __fastcall block_prepare_used(pool_t *pool, block_header_t *block, unsigned __int64 size)
{
  block_header_t *v3; // rbx
  unsigned __int64 v4; // r9
  block_header_t *v5; // rdx
  unsigned __int64 v6; // rax

  v3 = block;
  if ( !block )
    return 0i64;
  v4 = block->size & 0xFFFFFFFFFFFFFFFCui64;
  if ( v4 >= size + 32 )
  {
    v5 = (block_header_t *)((char *)block + size + 8);
    v5->size &= 3ui64;
    v5->size |= v4 - size - 8;
    v3->size &= 3ui64;
    v3->size |= size;
    v6 = v5->size & 0xFFFFFFFFFFFFFFFCui64;
    *(block_header_t **)((char *)&v5->next_free + v6) = (block_header_t *)(*(_QWORD *)((char *)&v5->next_free + v6) | 2i64);
    *(unsigned __int64 *)((char *)&v5->size + v6) = (unsigned __int64)v5;
    v5->size |= 1ui64;
    *(unsigned __int64 *)((char *)&v3->size + (v3->size & 0xFFFFFFFFFFFFFFFCui64)) = (unsigned __int64)v3;
    v5->size |= 2ui64;
    block_insert(pool, v5);
  }
  *(block_header_t **)((char *)&v3->next_free + (v3->size & 0xFFFFFFFFFFFFFFFCui64)) = (block_header_t *)(*(_QWORD *)((char *)&v3->next_free + (v3->size & 0xFFFFFFFFFFFFFFFCui64)) & 0xFFFFFFFFFFFFFFFDui64);
  v3->size &= 0xFFFFFFFFFFFFFFFEui64;
  return (signed __int64)&v3->next_free;
}

// File Line: 778
// RVA: 0xAA1480
unsigned __int64 __fastcall tlsf_block_size(void *ptr)
{
  unsigned __int64 result; // rax

  if ( ptr )
    result = *((_QWORD *)ptr - 1) & 0xFFFFFFFFFFFFFFFCui64;
  else
    result = 0i64;
  return result;
}

// File Line: 794
// RVA: 0xAA18B0
unsigned __int64 __fastcall tlsf_overhead()
{
  return 6552i64;
}

// File Line: 804
// RVA: 0xAA14A0
void *__fastcall tlsf_create(void *mem, unsigned __int64 bytes)
{
  char *v2; // rdi
  unsigned __int64 v3; // r10
  char *v4; // rdx
  _DWORD *v5; // r8
  signed __int64 v6; // r9
  _QWORD *v7; // rax
  signed __int64 v8; // rcx
  signed __int64 v9; // rbx
  unsigned __int64 v10; // rax
  void *result; // rax

  v2 = (char *)mem;
  v3 = bytes - 6552 - (((_BYTE)bytes + 104) & 7);
  if ( v3 - 24 > 0xFFFFFFE8 )
  {
    printf("tlsf_create: Pool size must be at least %d bytes.\n", 6576i64);
    result = 0i64;
  }
  else
  {
    *((_QWORD *)mem + 2) = mem;
    *((_QWORD *)mem + 3) = mem;
    v4 = (char *)mem + 136;
    v5 = (char *)mem + 36;
    v6 = 25i64;
    *((_DWORD *)mem + 8) = 0;
    do
    {
      *v5 = 0;
      v7 = v4;
      v8 = 4i64;
      do
      {
        *v7 = v2;
        v7[1] = v2;
        v7[2] = v2;
        v7 += 8;
        *(v7 - 5) = v2;
        *(v7 - 4) = v2;
        *(v7 - 3) = v2;
        *(v7 - 2) = v2;
        *(v7 - 1) = v2;
        --v8;
      }
      while ( v8 );
      ++v5;
      v4 += 256;
      --v6;
    }
    while ( v6 );
    v9 = (signed __int64)(v2 + 6528);
    *((_QWORD *)v2 + 817) = (v3 - (v3 & 7)) & 0xFFFFFFFFFFFFFFFDui64 | 1;
    block_insert((pool_t *)v2, (block_header_t *)v2 + 204);
    v10 = *((_QWORD *)v2 + 817) & 0xFFFFFFFFFFFFFFFCui64;
    *(_QWORD *)(v10 + v9 + 8) = v9;
    *(_QWORD *)(v10 + v9 + 16) = 2i64;
    result = v2;
  }
  return result;
}

// File Line: 880
// RVA: 0xAA1760
signed __int64 __fastcall tlsf_malloc(void *tlsf, unsigned __int64 size)
{
  pool_t *v2; // rdi
  signed __int64 v3; // rbx
  block_header_t *v4; // rax

  v2 = (pool_t *)tlsf;
  v3 = 0i64;
  if ( size - 1 <= 0xFFFFFFFE )
  {
    v3 = 24i64;
    if ( ((size + 7) & 0xFFFFFFFFFFFFFFF8ui64) > 0x18 )
      v3 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  }
  v4 = block_locate_free((pool_t *)tlsf, v3);
  return block_prepare_used(v2, v4, v3);
}

// File Line: 888
// RVA: 0xAA17C0
signed __int64 __fastcall tlsf_memalign(void *tlsf, unsigned __int64 align, unsigned __int64 size)
{
  unsigned __int64 v3; // rbx
  signed __int64 v4; // rdx
  pool_t *v5; // rsi
  signed __int64 v6; // rdi
  signed __int64 v7; // rax
  block_header_t *v8; // rax
  block_header_t *v9; // rdx
  signed __int64 v10; // r9
  unsigned __int64 v11; // r8
  signed __int64 v12; // rcx

  v3 = align;
  v4 = 0i64;
  v5 = (pool_t *)tlsf;
  v6 = 0i64;
  if ( size - 1 <= 0xFFFFFFFE )
  {
    v6 = 24i64;
    if ( ((size + 7) & 0xFFFFFFFFFFFFFFF8ui64) > 0x18 )
      v6 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  }
  if ( v6 + v3 + 31 <= 0xFFFFFFFE )
  {
    v4 = 24i64;
    v7 = ~(v3 - 1);
    if ( (v7 & (v3 + v6 + v3 + 31)) > 0x18 )
      v4 = v7 & (v3 + v6 + v3 + 31);
  }
  if ( v3 <= 8 )
    v4 = v6;
  v8 = block_locate_free((pool_t *)tlsf, v4);
  v9 = v8;
  if ( v8 )
  {
    v10 = ~(v3 - 1);
    v11 = (v10 & ((unsigned __int64)&v8->size + v3 + 7)) - ((_QWORD)v8 + 16);
    if ( (block_header_t **)(v10 & ((unsigned __int64)&v8->size + v3 + 7)) != &v8->next_free )
    {
      if ( v11 < 0x20 )
      {
        v12 = v3;
        if ( 32 - v11 > v3 )
          v12 = 32 - v11;
        v11 = (v10 & ((v10 & ((unsigned __int64)&v8->size + v3 + 7)) + v12 + v3 - 1)) - ((_QWORD)v8 + 16);
      }
      if ( v11 )
        v9 = block_trim_free_leading(v5, v8, v11);
    }
  }
  return block_prepare_used(v5, v9, v6);
}

// File Line: 1020
// RVA: 0xAA16A0
void __fastcall tlsf_free(void *tlsf, void *ptr)
{
  block_header_t *v2; // rbx
  _QWORD *v3; // rdi
  pool_t *v4; // rsi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rdi

  if ( ptr )
  {
    v2 = (block_header_t *)((char *)ptr - 16);
    v3 = (char *)ptr - 8;
    v4 = (pool_t *)tlsf;
    v5 = *v3 & 0xFFFFFFFFFFFFFFFCui64;
    *(block_header_t **)((char *)&v2->next_free + v5) = (block_header_t *)(*(_QWORD *)((char *)&v2->next_free + v5) | 2i64);
    *(unsigned __int64 *)((char *)&v2->size + v5) = (unsigned __int64)v2;
    *v3 |= 1ui64;
    if ( *(_BYTE *)v3 & 2 )
    {
      v2 = v2->prev_phys_block;
      block_remove((pool_t *)tlsf, v2);
      v2->size += (*v3 & 0xFFFFFFFFFFFFFFFCui64) + 8;
      *(unsigned __int64 *)((char *)&v2->size + (v2->size & 0xFFFFFFFFFFFFFFFCui64)) = (unsigned __int64)v2;
    }
    v6 = v2->size & 0xFFFFFFFFFFFFFFFCui64;
    if ( *((_BYTE *)&v2->next_free + v6) & 1 )
    {
      block_remove(v4, (block_header_t *)((char *)v2 + v6 + 8));
      v2->size += (*(_QWORD *)((_BYTE *)&v2->next_free + v6) & 0xFFFFFFFFFFFFFFFCui64) + 8;
      *(unsigned __int64 *)((char *)&v2->size + (v2->size & 0xFFFFFFFFFFFFFFFCui64)) = (unsigned __int64)v2;
    }
    block_insert(v4, v2);
  }
}

