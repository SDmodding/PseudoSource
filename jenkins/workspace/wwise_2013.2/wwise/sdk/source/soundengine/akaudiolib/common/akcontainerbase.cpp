// File Line: 28
// RVA: 0xA9AFF0
void __fastcall CAkContainerBase::CAkContainerBase(CAkContainerBase *this, unsigned int in_ulID)
{
  CAkContainerBase *v2; // rbx

  v2 = this;
  CAkParameterNode::CAkParameterNode((CAkParameterNode *)&this->vfptr, in_ulID);
  v2->m_mapChildId.m_pItems = 0i64;
  *(_QWORD *)&v2->m_mapChildId.m_uLength = 0i64;
  v2->vfptr = (CAkIndexableVtbl *)&CAkContainerBase::`vftable;
}

// File Line: 32
// RVA: 0xA9B030
void __fastcall CAkContainerBase::~CAkContainerBase(CAkContainerBase *this)
{
  CAkContainerBase *v1; // rbx
  CAkParameterNodeBase **v2; // rdx

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkParentNode<CAkParameterNode>::`vftable;
  v2 = this->m_mapChildId.m_pItems;
  if ( v2 )
  {
    this->m_mapChildId.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_mapChildId.m_pItems = 0i64;
    v1->m_mapChildId.m_ulReserved = 0;
  }
  CAkParameterNode::~CAkParameterNode((CAkParameterNode *)&v1->vfptr);
}

// File Line: 36
// RVA: 0xA9B090
signed __int64 __fastcall CAkContainerBase::CanAddChild(CAkContainerBase *this, CAkParameterNodeBase *in_pAudioNode)
{
  CAkContainerBase *v2; // rsi
  CAkParameterNodeBase *v3; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned int v7; // edi

  v2 = this;
  v3 = in_pAudioNode;
  v4 = 1;
  v5 = in_pAudioNode->vfptr[3].Release((CAkIndexable *)in_pAudioNode);
  if ( (unsigned __int16)v2->vfptr[20].Release((CAkIndexable *)&v2->vfptr) >= 0xFFFFu )
    return 9i64;
  if ( v5 - 2 > 3 && v5 != 11 )
    return 4i64;
  if ( v3->m_pParentNode )
    return 21i64;
  v7 = v3->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &v2->m_mapChildId,
         v7) )
  {
    return 5i64;
  }
  if ( v2->key == v7 )
    v4 = 23;
  return v4;
}

