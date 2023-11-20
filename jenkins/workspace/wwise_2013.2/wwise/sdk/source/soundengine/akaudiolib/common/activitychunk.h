// File Line: 111
// RVA: 0xA715D0
void __fastcall StructMaxInst::DisableLimiter(StructMaxInst *this)
{
  CAkLimiter *v1; // rbx
  StructMaxInst *v2; // rdi
  CAkPBI **v3; // rdx

  v1 = this->m_pLimiter;
  v2 = this;
  if ( this->m_pLimiter )
  {
    v3 = v1->m_sortedPBIList.m_pItems;
    if ( v1->m_sortedPBIList.m_pItems )
    {
      v1->m_sortedPBIList.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v3);
      v1->m_sortedPBIList.m_pItems = 0i64;
      v1->m_sortedPBIList.m_ulReserved = 0;
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_pLimiter);
    v2->m_pLimiter = 0i64;
  }
}

// File Line: 190
// RVA: 0xA70560
void __fastcall AkActivityChunk::~AkActivityChunk(AkActivityChunk *this)
{
  CAkPBI **v1; // rdx
  AkActivityChunk *v2; // rbx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v3; // rdx
  CAkParameterNodeBase **v4; // rdx

  v1 = this->m_Limiter.m_sortedPBIList.m_pItems;
  v2 = this;
  if ( v1 )
  {
    this->m_Limiter.m_sortedPBIList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_Limiter.m_sortedPBIList.m_pItems = 0i64;
    v2->m_Limiter.m_sortedPBIList.m_ulReserved = 0;
  }
  v2->m_listPBI.m_pFirst = 0i64;
  v3 = v2->m_ListPlayCountPerObj.m_pItems;
  if ( v2->m_ListPlayCountPerObj.m_pItems )
  {
    v2->m_ListPlayCountPerObj.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    v2->m_ListPlayCountPerObj.m_pItems = 0i64;
    v2->m_ListPlayCountPerObj.m_ulReserved = 0;
  }
  v4 = v2->m_ActiveChildren.m_pItems;
  if ( v4 )
  {
    v2->m_ActiveChildren.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    v2->m_ActiveChildren.m_pItems = 0i64;
    v2->m_ActiveChildren.m_ulReserved = 0;
  }
}

