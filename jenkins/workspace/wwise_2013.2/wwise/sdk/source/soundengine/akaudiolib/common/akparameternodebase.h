// File Line: 185
// RVA: 0xA6DDB0
// attributes: thunk
void __fastcall CAkParameterNodeBase::OnPreRelease(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase::FlushStateTransitions(this);
}

// File Line: 246
// RVA: 0xA708C0
__int64 __fastcall CAkParameterNodeBase::AddChildByPtr(CAkParameterNodeBase *this, CAkParameterNodeBase *in_pChild)
{
  in_pChild->vfptr->AddRef(in_pChild);
  return ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkParameterNodeBase *))this->vfptr[2].AddRef)(
           this,
           in_pChild);
}

// File Line: 252
// RVA: 0xA6B650
__int64 __fastcall CAkParameterNodeBase::AddChild(CAkParameterNodeBase *this, WwiseObjectIDext in_ulID)
{
  CAkParameterNodeBase *NodePtrAndAddRef; // rdx

  if ( !in_ulID.id )
    return 14i64;
  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ulID.id, AkNodeType_Default);
  if ( NodePtrAndAddRef )
    return ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkParameterNodeBase *))this->vfptr[2].AddRef)(
             this,
             NodePtrAndAddRef);
  else
    return 15i64;
}

// File Line: 653
// RVA: 0xA81AE0
char __fastcall CAkParameterNodeBase::IsInHdrHierarchy(CAkParameterNodeBase *this)
{
  if ( (*((_BYTE *)this + 83) & 8) != 0 )
    return 1;
  while ( this->m_pBusOutputNode )
  {
    this = this->m_pBusOutputNode;
LABEL_5:
    if ( (*((_BYTE *)this + 83) & 8) != 0 )
      return 1;
  }
  this = this->m_pParentNode;
  if ( this )
    goto LABEL_5;
  return 0;
}

// File Line: 736
// RVA: 0xA6E1E0
void __fastcall CAkParameterNodeBase::PositioningChangeNotification(
        CAkParameterNodeBase *this,
        float in_RTPCValue,
        __int64 in_ParameterID,
        CAkRegisteredObj *in_GameObj)
{
  if ( (*((_BYTE *)this + 83) & 0x10) != 0 )
    ((void (__fastcall *)(CAkParameterNodeBase *, CAkIndexableVtbl *, __int64, CAkRegisteredObj *))this->vfptr[6].AddRef)(
      this,
      this->vfptr,
      in_ParameterID,
      in_GameObj);
}

// File Line: 852
// RVA: 0xA71630
char __fastcall CAkParameterNodeBase::EnableActivityChunk(
        CAkParameterNodeBase *this,
        unsigned __int16 in_flagForwardToBus)
{
  AkActivityChunk *v4; // rbx
  int RTPCConvertedValue; // r8d
  bool v6; // si
  char v7; // cl

  if ( this->m_pActivityChunk )
    return 1;
  v4 = (AkActivityChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  if ( v4 )
  {
    LOWORD(RTPCConvertedValue) = this->m_u16MaxNumInstance;
    v6 = *((_BYTE *)this + 82) & 1;
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x200) != 0 && (_WORD)RTPCConvertedValue )
      RTPCConvertedValue = (int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 9u, 0i64);
    v7 = *((_BYTE *)this + 82);
    v4->m_ListPlayCountPerObj.m_pItems = 0i64;
    *(_QWORD *)&v4->m_ListPlayCountPerObj.m_uLength = 0i64;
    v4->m_listPBI.m_pFirst = 0i64;
    v4->m_Limiter.m_sortedPBIList.m_pItems = 0i64;
    *(_QWORD *)&v4->m_Limiter.m_sortedPBIList.m_uLength = 0i64;
    v4->m_Limiter.m_bDoesKillNewest = v6;
    v4->m_Limiter.m_u16LimiterMax = RTPCConvertedValue;
    v4->m_Limiter.m_bAllowUseVirtualBehavior = (v7 & 2) != 0;
    v4->m_ActiveChildren.m_pItems = 0i64;
    *(_QWORD *)&v4->m_ActiveChildren.m_uLength = 0i64;
    *((_BYTE *)v4 + 80) &= ~1u;
    *(_QWORD *)&v4->m_PlayCount = 0i64;
    *((_BYTE *)v4 + 80) |= (v7 & 0x10) != 0;
  }
  else
  {
    v4 = 0i64;
  }
  this->m_pActivityChunk = v4;
  if ( v4 )
    return ((__int64 (__fastcall *)(CAkParameterNodeBase *, _QWORD))this->vfptr[19].Release)(this, in_flagForwardToBus);
  else
    return 0;
}

// File Line: 949
// RVA: 0xA829A0
void __fastcall CAkParameterNodeBase::RemovePBI(CAkParameterNodeBase *this, CAkPBI *in_pPBI)
{
  AkActivityChunk *m_pActivityChunk; // r10
  CAkPBI *v4; // r8
  CAkPBI *m_pFirst; // rcx
  CAkPBI *v6; // rax
  bool v7; // zf
  CAkPBI *pNextLightItem; // rcx
  AkActivityChunk *v9; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  v4 = 0i64;
  m_pFirst = m_pActivityChunk->m_listPBI.m_pFirst;
  v6 = m_pFirst;
  if ( m_pFirst )
  {
    while ( v6 != in_pPBI )
    {
      v4 = v6;
      v6 = v6->pNextLightItem;
      if ( !v6 )
        goto LABEL_9;
    }
    if ( v6 )
    {
      v7 = v6 == m_pFirst;
      pNextLightItem = v6->pNextLightItem;
      if ( v7 )
        m_pActivityChunk->m_listPBI.m_pFirst = pNextLightItem;
      else
        v4->pNextLightItem = pNextLightItem;
    }
  }
LABEL_9:
  v9 = this->m_pActivityChunk;
  if ( !v9->m_PlayCount
    && !v9->m_uActivityCount
    && !v9->m_iPlayCountValid
    && !v9->m_iVirtualCountValid
    && !v9->m_listPBI.m_pFirst
    && !v9->m_ListPlayCountPerObj.m_uLength )
  {
    CAkParameterNodeBase::DeleteActivityChunk(this);
  }
}

