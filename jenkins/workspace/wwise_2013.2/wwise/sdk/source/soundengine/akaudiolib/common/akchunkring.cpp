// File Line: 114
// RVA: 0xA45E30
__int64 __fastcall AkSparseChunkRing::Init(AkSparseChunkRing *this, unsigned int in_uNumChunks)
{
  unsigned int v3; // esi
  void *v4; // rbp
  unsigned __int64 m_uLength; // r14
  unsigned __int64 m_ulReserved; // rcx
  unsigned int v7; // r15d
  AkSparseChunkRing::Block *v8; // rdi
  __int64 v9; // r8
  __int64 v10; // rdx
  AkSparseChunkRing::Block *m_pItems; // rcx
  __int64 v12; // rcx
  AkSparseChunkRing::Block *v13; // rcx

  if ( in_uNumChunks < 2 )
    in_uNumChunks = 2;
  v3 = 0;
  this->m_uMaxChunks = in_uNumChunks;
  while ( 1 )
  {
    v4 = AK::MemoryMgr::Malloc(g_DefaultPoolId, kSparseChunkSize);
    if ( !v4 )
      return 52i64;
    m_uLength = this->blocks.m_uLength;
    m_ulReserved = this->blocks.m_ulReserved;
    if ( m_uLength >= m_ulReserved )
    {
      v7 = m_ulReserved + 4;
      v8 = (AkSparseChunkRing::Block *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 16i64 * (unsigned int)(m_ulReserved + 4));
      if ( !v8 )
        goto LABEL_17;
      v9 = this->blocks.m_uLength;
      if ( this->blocks.m_pItems )
      {
        if ( this->blocks.m_uLength )
        {
          v10 = 0i64;
          do
          {
            m_pItems = this->blocks.m_pItems;
            ++v10;
            v8[v10 - 1].pData = this->blocks.m_pItems[v10 - 1].pData;
            *(_QWORD *)&v8[v10 - 1].uUsedSize = *(_QWORD *)&m_pItems[v10 - 1].uUsedSize;
            --v9;
          }
          while ( v9 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, this->blocks.m_pItems);
      }
      this->blocks.m_pItems = v8;
      this->blocks.m_ulReserved = v7;
    }
    if ( m_uLength >= this->blocks.m_ulReserved
      || (v12 = this->blocks.m_uLength, this->blocks.m_uLength = v12 + 1, (v13 = &this->blocks.m_pItems[v12]) == 0i64) )
    {
LABEL_17:
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
      return 52i64;
    }
    ++v3;
    v13->pData = v4;
    v13->uUsedSize = 0;
    if ( v3 >= 2 )
      return 1i64;
  }
}

// File Line: 146
// RVA: 0xA46070
void __fastcall AkSparseChunkRing::Term(AkSparseChunkRing *this)
{
  AkSparseChunkRing::Block *i; // rbx

  for ( i = this->blocks.m_pItems; i != &this->blocks.m_pItems[this->blocks.m_uLength]; ++i )
    AK::MemoryMgr::Free(g_DefaultPoolId, i->pData);
  if ( this->blocks.m_pItems )
  {
    this->blocks.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->blocks.m_pItems);
    this->blocks.m_pItems = 0i64;
    this->blocks.m_ulReserved = 0;
  }
}

// File Line: 156
// RVA: 0xA45D80
char *__fastcall AkSparseChunkRing::BeginRead(AkSparseChunkRing *this)
{
  AkSparseChunkRing::Block *m_pItems; // r9
  unsigned int m_uReadOffset; // r8d
  __int64 v4; // rax
  bool v5; // cf

  m_pItems = this->blocks.m_pItems;
  m_uReadOffset = this->m_uReadOffset;
  if ( m_uReadOffset < this->blocks.m_pItems[this->m_uReadBlock].uUsedSize )
    return (char *)m_pItems[this->m_uReadBlock].pData + m_uReadOffset;
  v4 = this->m_uReadBlock + 1;
  v5 = (unsigned int)v4 < this->blocks.m_uLength;
  this->m_uReadOffset = 0;
  if ( !v5 )
    v4 = 0i64;
  this->m_uReadBlock = v4;
  return (char *)m_pItems[v4].pData;
}

// File Line: 184
// RVA: 0xA45DC0
char *__fastcall AkSparseChunkRing::BeginReadEx(AkSparseChunkRing *this, unsigned int *out_uSizeAvail)
{
  AkSparseChunkRing::Block *m_pItems; // r11
  unsigned int m_uReadOffset; // r10d
  __int64 m_uReadBlock; // r8
  unsigned int uUsedSize; // eax
  unsigned int v7; // r9d
  bool v8; // cf

  m_pItems = this->blocks.m_pItems;
  m_uReadOffset = this->m_uReadOffset;
  m_uReadBlock = this->m_uReadBlock;
  uUsedSize = this->blocks.m_pItems[this->m_uReadBlock].uUsedSize;
  if ( m_uReadOffset >= uUsedSize )
  {
    v7 = this->m_uReadBlock + 1;
    v8 = v7 < this->blocks.m_uLength;
    this->m_uReadOffset = 0;
    if ( !v8 )
      v7 = 0;
    this->m_uReadBlock = v7;
    *out_uSizeAvail = m_pItems[v7].uUsedSize;
    return (char *)m_pItems[v7].pData;
  }
  else
  {
    *out_uSizeAvail = uUsedSize - m_uReadOffset;
    return (char *)m_pItems[m_uReadBlock].pData + m_uReadOffset;
  }
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
__int64 __fastcall AkSparseChunkRing::Write(AkSparseChunkRing *this, void *in_pData, unsigned int in_uSize)
{
  size_t v3; // rbp
  __int64 m_uWriteOffset; // rcx
  unsigned int m_uLength; // eax
  unsigned int v8; // esi
  void *pData; // rdi
  AkSparseChunkRing::Block *v11; // rax

  v3 = in_uSize;
  m_uWriteOffset = this->m_uWriteOffset;
  if ( kSparseChunkSize - (unsigned int)m_uWriteOffset < in_uSize )
  {
    if ( !this->m_bBufferFull )
    {
      m_uLength = this->blocks.m_uLength;
      v8 = this->m_uWriteBlock + 1;
      if ( v8 >= m_uLength )
        v8 = 0;
      if ( this->m_uReadBlock != v8 )
      {
        pData = this->blocks.m_pItems[v8].pData;
LABEL_15:
        this->m_uWriteBlock = v8;
        this->m_uWriteOffset = v3;
        memmove(pData, in_pData, v3);
        goto LABEL_16;
      }
      if ( m_uLength < this->m_uMaxChunks )
      {
        pData = AK::MemoryMgr::Malloc(g_DefaultPoolId, kSparseChunkSize);
        if ( pData )
        {
          v11 = AkArray<AkSparseChunkRing::Block,AkSparseChunkRing::Block const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Insert(
                  &this->blocks,
                  v8);
          if ( !v11 )
          {
            this->m_bBufferFull = 1;
            AK::MemoryMgr::Free(g_DefaultPoolId, pData);
            return 52i64;
          }
          v11->pData = pData;
          ++this->m_uReadBlock;
          goto LABEL_15;
        }
      }
      this->m_bBufferFull = 1;
    }
    return 52i64;
  }
  memmove((char *)this->blocks.m_pItems[this->m_uWriteBlock].pData + m_uWriteOffset, in_pData, in_uSize);
  this->m_uWriteOffset += v3;
LABEL_16:
  this->blocks.m_pItems[this->m_uWriteBlock].uUsedSize = this->m_uWriteOffset;
  return 1i64;
}

// File Line: 353
// RVA: 0xA45E20
__int64 __fastcall AkSparseChunkRing::GetChunkSize()
{
  return kSparseChunkSize;
}

