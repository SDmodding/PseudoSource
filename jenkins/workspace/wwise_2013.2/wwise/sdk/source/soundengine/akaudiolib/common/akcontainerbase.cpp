// File Line: 28
// RVA: 0xA9AFF0
void __fastcall CAkContainerBase::CAkContainerBase(CAkContainerBase *this, unsigned int in_ulID)
{
  CAkParameterNode::CAkParameterNode(this, in_ulID);
  this->m_mapChildId.m_pItems = 0i64;
  *(_QWORD *)&this->m_mapChildId.m_uLength = 0i64;
  this->vfptr = (CAkIndexableVtbl *)&CAkContainerBase::`vftable;
}

// File Line: 32
// RVA: 0xA9B030
void __fastcall CAkContainerBase::~CAkContainerBase(CAkContainerBase *this)
{
  CAkParameterNodeBase **m_pItems; // rdx

  this->vfptr = (CAkIndexableVtbl *)&CAkParentNode<CAkParameterNode>::`vftable;
  m_pItems = this->m_mapChildId.m_pItems;
  if ( m_pItems )
  {
    this->m_mapChildId.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_mapChildId.m_pItems = 0i64;
    this->m_mapChildId.m_ulReserved = 0;
  }
  CAkParameterNode::~CAkParameterNode(this);
}

// File Line: 36
// RVA: 0xA9B090
__int64 __fastcall CAkContainerBase::CanAddChild(CAkContainerBase *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned int key; // edi

  v4 = 1;
  v5 = in_pAudioNode->vfptr[3].Release(in_pAudioNode);
  if ( (unsigned __int16)this->vfptr[20].Release(this) == 0xFFFF )
    return 9i64;
  if ( v5 - 2 > 3 && v5 != 11 )
    return 4i64;
  if ( in_pAudioNode->m_pParentNode )
    return 21i64;
  key = in_pAudioNode->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &this->m_mapChildId,
         key) )
  {
    return 5i64;
  }
  if ( this->key == key )
    return 23;
  return v4;
}

