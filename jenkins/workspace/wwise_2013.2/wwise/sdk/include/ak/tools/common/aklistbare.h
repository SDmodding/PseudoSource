// File Line: 263
// RVA: 0xAA8D00
signed __int64 __fastcall AkListBare<AK::StreamMgr::AkMemBlock,AK::StreamMgr::AkListBareNextMemBlock,AkCountPolicyWithCount>::Remove(AkListBare<AK::StreamMgr::AkMemBlock,AK::StreamMgr::AkListBareNextMemBlock,AkCountPolicyWithCount> *this, AK::StreamMgr::AkMemBlock *in_pItem)
{
  AkListBare<AK::StreamMgr::AkMemBlock,AK::StreamMgr::AkListBareNextMemBlock,AkCountPolicyWithCount> *v2; // r8
  AK::StreamMgr::AkMemBlock *v3; // rcx
  AK::StreamMgr::AkMemBlock *v4; // r9
  AK::StreamMgr::AkMemBlock *v5; // rax
  bool v7; // zf
  AK::StreamMgr::AkMemBlock *v8; // rcx

  v2 = this;
  v3 = this->m_pFirst;
  v4 = 0i64;
  v5 = v3;
  if ( !v3 )
    return 2i64;
  while ( v5 != in_pItem )
  {
    v4 = v5;
    v5 = v5->pNextBlock;
    if ( !v5 )
      return 2i64;
  }
  if ( !v5 )
    return 2i64;
  v7 = v5 == v3;
  v8 = v5->pNextBlock;
  if ( v7 )
    v2->m_pFirst = v8;
  else
    v4->pNextBlock = v8;
  if ( v5 == v2->m_pLast )
    v2->m_pLast = v4;
  --v2->m_ulNumListItems;
  return 1i64;
}

