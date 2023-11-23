// File Line: 111
// RVA: 0xA715D0
void __fastcall StructMaxInst::DisableLimiter(StructMaxInst *this)
{
  CAkLimiter *m_pLimiter; // rbx
  CAkPBI **m_pItems; // rdx

  m_pLimiter = this->m_pLimiter;
  if ( this->m_pLimiter )
  {
    m_pItems = m_pLimiter->m_sortedPBIList.m_pItems;
    if ( m_pLimiter->m_sortedPBIList.m_pItems )
    {
      m_pLimiter->m_sortedPBIList.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
      m_pLimiter->m_sortedPBIList.m_pItems = 0i64;
      m_pLimiter->m_sortedPBIList.m_ulReserved = 0;
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pLimiter);
    this->m_pLimiter = 0i64;
  }
}

// File Line: 190
// RVA: 0xA70560
void __fastcall AkActivityChunk::~AkActivityChunk(AkActivityChunk *this)
{
  CAkPBI **m_pItems; // rdx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v3; // rdx
  CAkParameterNodeBase **v4; // rdx

  m_pItems = this->m_Limiter.m_sortedPBIList.m_pItems;
  if ( m_pItems )
  {
    this->m_Limiter.m_sortedPBIList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_Limiter.m_sortedPBIList.m_pItems = 0i64;
    this->m_Limiter.m_sortedPBIList.m_ulReserved = 0;
  }
  this->m_listPBI.m_pFirst = 0i64;
  v3 = this->m_ListPlayCountPerObj.m_pItems;
  if ( this->m_ListPlayCountPerObj.m_pItems )
  {
    this->m_ListPlayCountPerObj.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    this->m_ListPlayCountPerObj.m_pItems = 0i64;
    this->m_ListPlayCountPerObj.m_ulReserved = 0;
  }
  v4 = this->m_ActiveChildren.m_pItems;
  if ( v4 )
  {
    this->m_ActiveChildren.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    this->m_ActiveChildren.m_pItems = 0i64;
    this->m_ActiveChildren.m_ulReserved = 0;
  }
}

