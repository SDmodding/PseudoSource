// File Line: 263
// RVA: 0xAA8D00
__int64 __fastcall AkListBare<AK::StreamMgr::AkMemBlock,AK::StreamMgr::AkListBareNextMemBlock,AkCountPolicyWithCount>::Remove(
        AkListBare<AK::StreamMgr::AkMemBlock,AK::StreamMgr::AkListBareNextMemBlock,AkCountPolicyWithCount> *this,
        AK::StreamMgr::AkMemBlock *in_pItem)
{
  AK::StreamMgr::AkMemBlock *m_pFirst; // rcx
  AK::StreamMgr::AkMemBlock *v4; // r9
  AK::StreamMgr::AkMemBlock *pNextBlock; // rax
  bool v7; // zf
  AK::StreamMgr::AkMemBlock *v8; // rcx

  m_pFirst = this->m_pFirst;
  v4 = 0i64;
  pNextBlock = m_pFirst;
  if ( !m_pFirst )
    return 2i64;
  while ( pNextBlock != in_pItem )
  {
    v4 = pNextBlock;
    pNextBlock = pNextBlock->pNextBlock;
    if ( !pNextBlock )
      return 2i64;
  }
  if ( !pNextBlock )
    return 2i64;
  v7 = pNextBlock == m_pFirst;
  v8 = pNextBlock->pNextBlock;
  if ( v7 )
    this->m_pFirst = v8;
  else
    v4->pNextBlock = v8;
  if ( pNextBlock == this->m_pLast )
    this->m_pLast = v4;
  --this->m_ulNumListItems;
  return 1i64;
}

