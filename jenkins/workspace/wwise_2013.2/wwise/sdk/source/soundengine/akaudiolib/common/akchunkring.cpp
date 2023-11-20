// File Line: 114
// RVA: 0xA45E30
signed __int64 __fastcall AkSparseChunkRing::Init(AkSparseChunkRing *this, unsigned int in_uNumChunks)
{
  AkSparseChunkRing *v2; // rbx
  unsigned int v3; // esi
  void *v4; // rbp
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // rcx
  unsigned int v7; // er15
  AkSparseChunkRing::Block *v8; // rdi
  __int64 v9; // r8
  __int64 v10; // rdx
  AkSparseChunkRing::Block *v11; // rcx
  unsigned int v12; // eax
  signed __int64 v13; // rcx

  v2 = this;
  if ( in_uNumChunks < 2 )
    in_uNumChunks = 2;
  v3 = 0;
  this->m_uMaxChunks = in_uNumChunks;
  while ( 1 )
  {
    v4 = AK::MemoryMgr::Malloc(g_DefaultPoolId, kSparseChunkSize);
    if ( !v4 )
      return 52i64;
    v5 = v2->blocks.m_uLength;
    v6 = v2->blocks.m_ulReserved;
    if ( v5 >= v6 )
    {
      v7 = v6 + 4;
      v8 = (AkSparseChunkRing::Block *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 16i64 * (unsigned int)(v6 + 4));
      if ( !v8 )
        goto LABEL_17;
      v9 = v2->blocks.m_uLength;
      if ( v2->blocks.m_pItems )
      {
        if ( v2->blocks.m_uLength )
        {
          v10 = 0i64;
          do
          {
            v11 = v2->blocks.m_pItems;
            ++v10;
            v8[v10 - 1].pData = v2->blocks.m_pItems[v10 - 1].pData;
            *((_QWORD *)&v8[v10] - 1) = *((_QWORD *)&v11[v10] - 1);
            --v9;
          }
          while ( v9 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v2->blocks.m_pItems);
      }
      v2->blocks.m_pItems = v8;
      v2->blocks.m_ulReserved = v7;
    }
    if ( v5 >= v2->blocks.m_ulReserved
      || (v12 = v2->blocks.m_uLength,
          v2->blocks.m_uLength = v12 + 1,
          (v13 = (signed __int64)&v2->blocks.m_pItems[v12]) == 0) )
    {
LABEL_17:
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
      return 52i64;
    }
    ++v3;
    *(_QWORD *)v13 = v4;
    *(_DWORD *)(v13 + 8) = 0;
    if ( v3 >= 2 )
      return 1i64;
  }
}

// File Line: 146
// RVA: 0xA46070
void __fastcall AkSparseChunkRing::Term(AkSparseChunkRing *this)
{
  AkSparseChunkRing::Block *v1; // rbx
  AkSparseChunkRing *i; // rdi

  v1 = this->blocks.m_pItems;
  for ( i = this; v1 != &i->blocks.m_pItems[i->blocks.m_uLength]; ++v1 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->pData);
  if ( i->blocks.m_pItems )
  {
    i->blocks.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, i->blocks.m_pItems);
    i->blocks.m_pItems = 0i64;
    i->blocks.m_ulReserved = 0;
  }
}

// File Line: 156
// RVA: 0xA45D80
char *__fastcall AkSparseChunkRing::BeginRead(AkSparseChunkRing *this)
{
  AkSparseChunkRing::Block *v1; // r9
  unsigned int v2; // er8
  __int64 v4; // rax
  bool v5; // cf

  v1 = this->blocks.m_pItems;
  v2 = this->m_uReadOffset;
  if ( v2 < this->blocks.m_pItems[this->m_uReadBlock].uUsedSize )
    return (char *)v1[this->m_uReadBlock].pData + v2;
  v4 = this->m_uReadBlock + 1;
  v5 = (unsigned int)v4 < this->blocks.m_uLength;
  this->m_uReadOffset = 0;
  if ( !v5 )
    v4 = 0i64;
  this->m_uReadBlock = v4;
  return (char *)v1[v4].pData;
}

// File Line: 184
// RVA: 0xA45DC0
char *__fastcall AkSparseChunkRing::BeginReadEx(AkSparseChunkRing *this, unsigned int *out_uSizeAvail)
{
  AkSparseChunkRing::Block *v2; // r11
  unsigned int v3; // er10
  signed __int64 v4; // r8
  unsigned int v5; // eax
  char *result; // rax
  unsigned int v7; // er9
  bool v8; // cf

  v2 = this->blocks.m_pItems;
  v3 = this->m_uReadOffset;
  v4 = this->m_uReadBlock;
  v5 = this->blocks.m_pItems[this->m_uReadBlock].uUsedSize;
  if ( v3 >= v5 )
  {
    v7 = this->m_uReadBlock + 1;
    v8 = v7 < this->blocks.m_uLength;
    this->m_uReadOffset = 0;
    if ( !v8 )
      v7 = 0;
    this->m_uReadBlock = v7;
    *out_uSizeAvail = v2[v7].uUsedSize;
    result = (char *)v2[v7].pData;
  }
  else
  {
    *out_uSizeAvail = v5 - v3;
    result = (char *)v2[v4].pData + v3;
  }
  return result;
}

// File Line: 216
// RVA: 0xA45E10
void __fastcall AkSparseChunkRing::EndRead(AkSparseChunkRing *this, unsigned int in_uSize)
{
  this->m_uReadOffset += in_uSize;
  this->m_bBufferFull = 0;
}

// File Line: 232
// RVA: 0xA460E0
signed __int64 __fastcall AkSparseChunkRing::Write(AkSparseChunkRing *this, void *in_pData, unsigned int in_uSize)
{
  size_t v3; // rbp
  AkSparseChunkRing *v4; // rbx
  __int64 v5; // rcx
  void *v6; // r14
  unsigned int v7; // eax
  unsigned int v8; // esi
  void *v10; // rdi
  AkSparseChunkRing::Block *v11; // rax

  v3 = in_uSize;
  v4 = this;
  v5 = this->m_uWriteOffset;
  v6 = in_pData;
  if ( kSparseChunkSize - (unsigned int)v5 < in_uSize )
  {
    if ( !v4->m_bBufferFull )
    {
      v7 = v4->blocks.m_uLength;
      v8 = v4->m_uWriteBlock + 1;
      if ( v8 >= v7 )
        v8 = 0;
      if ( v4->m_uReadBlock != v8 )
      {
        v10 = v4->blocks.m_pItems[v8].pData;
LABEL_15:
        v4->m_uWriteBlock = v8;
        v4->m_uWriteOffset = v3;
        memmove(v10, v6, v3);
        goto LABEL_16;
      }
      if ( v7 < v4->m_uMaxChunks )
      {
        v10 = AK::MemoryMgr::Malloc(g_DefaultPoolId, kSparseChunkSize);
        if ( v10 )
        {
          v11 = AkArray<AkSparseChunkRing::Block,AkSparseChunkRing::Block const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Insert(
                  &v4->blocks,
                  v8);
          if ( !v11 )
          {
            v4->m_bBufferFull = 1;
            AK::MemoryMgr::Free(g_DefaultPoolId, v10);
            return 52i64;
          }
          v11->pData = v10;
          ++v4->m_uReadBlock;
          goto LABEL_15;
        }
      }
      v4->m_bBufferFull = 1;
    }
    return 52i64;
  }
  memmove((char *)v4->blocks.m_pItems[v4->m_uWriteBlock].pData + v5, in_pData, (unsigned int)v3);
  v4->m_uWriteOffset += v3;
LABEL_16:
  v4->blocks.m_pItems[v4->m_uWriteBlock].uUsedSize = v4->m_uWriteOffset;
  return 1i64;
}

// File Line: 353
// RVA: 0xA45E20
__int64 __fastcall AkSparseChunkRing::GetChunkSize()
{
  return kSparseChunkSize;
}

