// File Line: 411
// RVA: 0xAA1340
void __fastcall block_remove(pool_t *pool, block_header_t *block)
{
  unsigned __int64 v4; // rbx
  int v5; // r8d
  int v6; // ebx
  int v7; // eax
  block_header_t *prev_free; // rcx
  pool_t *next_free; // rdx
  __int64 v10; // rcx
  int v11; // eax
  bool v12; // zf

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
    v6 = (int)v4 / 8;
  }
  prev_free = block->prev_free;
  next_free = (pool_t *)block->next_free;
  next_free->block_null.prev_free = prev_free;
  prev_free->next_free = &next_free->block_null;
  v10 = v6 + 32i64 * v5;
  if ( pool->blocks[0][v10] == block )
  {
    pool->blocks[0][v10] = &next_free->block_null;
    if ( next_free == pool )
    {
      v11 = ~(1 << v6);
      v12 = (v11 & pool->sl_bitmap[v5]) == 0;
      pool->sl_bitmap[v5] &= v11;
      if ( v12 )
        pool->fl_bitmap &= ~(1 << v5);
    }
  }
}

// File Line: 419
// RVA: 0xAA1050
void __fastcall block_insert(pool_t *pool, block_header_t *block)
{
  unsigned __int64 v4; // rbx
  int v5; // r9d
  int v6; // ebx
  int v7; // eax
  __int64 v8; // rdx
  block_header_t *v9; // rax

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
    v6 = (int)v4 / 8;
  }
  v8 = v6 + 32i64 * v5;
  v9 = pool->blocks[0][v8];
  block->prev_free = &pool->block_null;
  block->next_free = v9;
  v9->prev_free = block;
  pool->blocks[0][v8] = block;
  pool->fl_bitmap |= 1 << v5;
  pool->sl_bitmap[v5] |= 1 << v6;
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
  int v4; // r9d
  int v5; // eax
  __int64 v6; // r11
  __int64 v7; // r8
  unsigned int v8; // ecx
  unsigned int v9; // r10d
  block_header_t *result; // rax
  bool v11; // zf
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  block_header_t *v15; // r8
  block_header_t *prev_free; // rax
  pool_t *next_free; // rdx
  __int64 v18; // rax
  int v19; // edx

  v2 = size;
  if ( !size )
    return 0i64;
  if ( size >= 0x20 )
    v2 = (1 << (tlsf_fls_sizet(size) - 5)) - 1 + size;
  if ( v2 >= 0x100 )
  {
    v5 = tlsf_fls_sizet(v2);
    v4 = v5 - 7;
    LOBYTE(v2) = (v2 >> ((unsigned __int8)v5 - 5)) ^ 0x20;
  }
  else
  {
    v4 = 0;
    LODWORD(v2) = (int)v2 / 8;
  }
  v6 = v4;
  v7 = v4;
  v8 = (-1 << v2) & pool->sl_bitmap[v4];
  if ( !v8 )
  {
    v9 = pool->fl_bitmap & (-1 << (v4 + 1));
    if ( !v9 )
      return 0i64;
    v4 = tlsf_ffs(v9);
    v7 = v4;
    v6 = v4;
    v8 = pool->sl_bitmap[v4];
  }
  v11 = (v8 & -v8) == 0;
  v12 = v8 & -v8;
  v13 = 32;
  if ( v11 )
    v13 = 31;
  if ( (v12 & 0xFFFF0000) == 0 )
  {
    v12 <<= 16;
    v13 -= 16;
  }
  if ( (v12 & 0xFF000000) == 0 )
  {
    v12 <<= 8;
    v13 -= 8;
  }
  if ( (v12 & 0xF0000000) == 0 )
  {
    v12 *= 16;
    v13 -= 4;
  }
  if ( (v12 & 0xC0000000) == 0 )
  {
    v12 *= 4;
    v13 -= 2;
  }
  if ( v12 >= 0 )
    --v13;
  v14 = v13 - 1;
  v15 = pool->blocks[v7][v14];
  if ( !v15 )
    return v15;
  prev_free = v15->prev_free;
  next_free = (pool_t *)v15->next_free;
  next_free->block_null.prev_free = prev_free;
  prev_free->next_free = &next_free->block_null;
  v18 = v14 + 32 * v6;
  if ( pool->blocks[0][v18] != v15 )
    return v15;
  pool->blocks[0][v18] = &next_free->block_null;
  if ( next_free != pool )
    return v15;
  result = v15;
  v19 = ~(1 << v14);
  v11 = (v19 & pool->sl_bitmap[v6]) == 0;
  pool->sl_bitmap[v6] &= v19;
  if ( v11 )
    pool->fl_bitmap &= ~(1 << v4);
  return result;
}

// File Line: 558
// RVA: 0xAA12A0
block_header_t **__fastcall block_prepare_used(pool_t *pool, block_header_t *block, unsigned __int64 size)
{
  unsigned __int64 v4; // r9
  block_header_t *v5; // rdx
  unsigned __int64 v6; // rax

  if ( !block )
    return 0i64;
  v4 = block->size & 0xFFFFFFFFFFFFFFFCui64;
  if ( v4 >= size + 32 )
  {
    v5 = (block_header_t *)((char *)&block->size + size);
    v5->size &= 3ui64;
    v5->size |= v4 - size - 8;
    block->size &= 3ui64;
    block->size |= size;
    v6 = v5->size & 0xFFFFFFFFFFFFFFFCui64;
    *(block_header_t **)((char *)&v5->next_free + v6) = (block_header_t *)(*(unsigned __int64 *)((char *)&v5->next_free
                                                                                               + v6) | 2);
    *(unsigned __int64 *)((char *)&v5->size + v6) = (unsigned __int64)v5;
    v5->size |= 1ui64;
    *(unsigned __int64 *)((char *)&block->size + (block->size & 0xFFFFFFFFFFFFFFFCui64)) = (unsigned __int64)block;
    v5->size |= 2ui64;
    block_insert(pool, v5);
  }
  *(block_header_t **)((char *)&block->next_free + (block->size & 0xFFFFFFFFFFFFFFFCui64)) = (block_header_t *)(*(unsigned __int64 *)((char *)&block->next_free + (block->size & 0xFFFFFFFFFFFFFFFCui64)) & ~2ui64);
  block->size &= ~1ui64;
  return &block->next_free;
}

// File Line: 778
// RVA: 0xAA1480
unsigned __int64 __fastcall tlsf_block_size(_QWORD *ptr)
{
  if ( ptr )
    return *(ptr - 1) & 0xFFFFFFFFFFFFFFFCui64;
  else
    return 0i64;
}

// File Line: 794
// RVA: 0xAA18B0
unsigned __int64 __fastcall tlsf_overhead()
{
  return 6552i64;
}

// File Line: 804
// RVA: 0xAA14A0
char *__fastcall tlsf_create(char *mem, unsigned __int64 bytes)
{
  unsigned __int64 v3; // r10
  char *v4; // rdx
  _DWORD *v5; // r8
  __int64 v6; // r9
  _QWORD *v7; // rax
  __int64 v8; // rcx
  char *v9; // rbx
  unsigned __int64 v10; // rax

  v3 = bytes - 6552 - (((_BYTE)bytes + 104) & 7);
  if ( v3 - 24 > 0xFFFFFFE8 )
  {
    printf("tlsf_create: Pool size must be at least %d bytes.\n", 6576i64);
    return 0i64;
  }
  else
  {
    *((_QWORD *)mem + 2) = mem;
    *((_QWORD *)mem + 3) = mem;
    v4 = mem + 136;
    v5 = mem + 36;
    v6 = 25i64;
    *((_DWORD *)mem + 8) = 0;
    do
    {
      *v5 = 0;
      v7 = v4;
      v8 = 4i64;
      do
      {
        *v7 = mem;
        v7[1] = mem;
        v7[2] = mem;
        v7 += 8;
        *(v7 - 5) = mem;
        *(v7 - 4) = mem;
        *(v7 - 3) = mem;
        *(v7 - 2) = mem;
        *(v7 - 1) = mem;
        --v8;
      }
      while ( v8 );
      ++v5;
      v4 += 256;
      --v6;
    }
    while ( v6 );
    v9 = mem + 6528;
    *((_QWORD *)mem + 817) = (v3 - (v3 & 7)) & 0xFFFFFFFFFFFFFFFCui64 | 1;
    block_insert((pool_t *)mem, (block_header_t *)mem + 204);
    v10 = *((_QWORD *)mem + 817) & 0xFFFFFFFFFFFFFFFCui64;
    *(_QWORD *)&v9[v10 + 8] = v9;
    *(_QWORD *)&v9[v10 + 16] = 2i64;
    return mem;
  }
}

// File Line: 880
// RVA: 0xAA1760
block_header_t **__fastcall tlsf_malloc(pool_t *tlsf, unsigned __int64 size)
{
  unsigned __int64 v3; // rbx
  block_header_t *free; // rax

  v3 = 0i64;
  if ( size - 1 <= 0xFFFFFFFE )
  {
    v3 = 24i64;
    if ( ((size + 7) & 0xFFFFFFFFFFFFFFF8ui64) > 0x18 )
      v3 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  }
  free = block_locate_free(tlsf, v3);
  return block_prepare_used(tlsf, free, v3);
}

// File Line: 888
// RVA: 0xAA17C0
block_header_t **__fastcall tlsf_memalign(pool_t *tlsf, unsigned __int64 align, unsigned __int64 size)
{
  unsigned __int64 v4; // rdx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rax
  block_header_t *free; // rax
  block_header_t *v9; // rdx
  unsigned __int64 v10; // r9
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rcx

  v4 = 0i64;
  v6 = 0i64;
  if ( size - 1 <= 0xFFFFFFFE )
  {
    v6 = 24i64;
    if ( ((size + 7) & 0xFFFFFFFFFFFFFFF8ui64) > 0x18 )
      v6 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  }
  if ( v6 + align + 31 <= 0xFFFFFFFE )
  {
    v4 = 24i64;
    v7 = ~(align - 1);
    if ( (v7 & (align + v6 + align + 31)) > 0x18 )
      v4 = v7 & (align + v6 + align + 31);
  }
  if ( align <= 8 )
    v4 = v6;
  free = block_locate_free(tlsf, v4);
  v9 = free;
  if ( free )
  {
    v10 = ~(align - 1);
    v11 = (v10 & ((unsigned __int64)&free->size + align + 7)) - (_QWORD)&free->next_free;
    if ( v11 )
    {
      if ( v11 < 0x20 )
      {
        v12 = align;
        if ( 32 - v11 > align )
          v12 = 32 - v11;
        v11 = (v10 & ((v10 & ((unsigned __int64)&free->size + align + 7)) + v12 + align - 1)) - (_QWORD)&free->next_free;
      }
      if ( v11 )
        v9 = block_trim_free_leading(tlsf, free, v11);
    }
  }
  return block_prepare_used(tlsf, v9, v6);
}

// File Line: 1020
// RVA: 0xAA16A0
void __fastcall tlsf_free(pool_t *tlsf, char *ptr)
{
  block_header_t *v2; // rbx
  char *v3; // rdi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rdi

  if ( ptr )
  {
    v2 = (block_header_t *)(ptr - 16);
    v3 = ptr - 8;
    v5 = *(_QWORD *)v3 & 0xFFFFFFFFFFFFFFFCui64;
    *(block_header_t **)((char *)&v2->next_free + v5) = (block_header_t *)(*(unsigned __int64 *)((char *)&v2->next_free
                                                                                               + v5) | 2);
    *(unsigned __int64 *)((char *)&v2->size + v5) = (unsigned __int64)v2;
    *(_QWORD *)v3 |= 1ui64;
    if ( (*v3 & 2) != 0 )
    {
      v2 = v2->prev_phys_block;
      block_remove(tlsf, v2);
      v2->size += (*(_QWORD *)v3 & 0xFFFFFFFFFFFFFFFCui64) + 8;
      *(unsigned __int64 *)((char *)&v2->size + (v2->size & 0xFFFFFFFFFFFFFFFCui64)) = (unsigned __int64)v2;
    }
    v6 = v2->size & 0xFFFFFFFFFFFFFFFCui64;
    if ( (*((_BYTE *)&v2->next_free + v6) & 1) != 0 )
    {
      block_remove(tlsf, (block_header_t *)((char *)&v2->size + v6));
      v2->size += (*(unsigned __int64 *)((_BYTE *)&v2->next_free + v6) & 0xFFFFFFFFFFFFFFFCui64) + 8;
      *(unsigned __int64 *)((char *)&v2->size + (v2->size & 0xFFFFFFFFFFFFFFFCui64)) = (unsigned __int64)v2;
    }
    block_insert(tlsf, v2);
  }
}

