// File Line: 185
// RVA: 0xA6DDB0
void __fastcall CAkParameterNodeBase::OnPreRelease(CAkParameterNodeBase *this)
{
  CAkParameterNodeBase::FlushStateTransitions(this);
}

// File Line: 246
// RVA: 0xA708C0
__int64 __fastcall CAkParameterNodeBase::AddChildByPtr(CAkParameterNodeBase *this, CAkParameterNodeBase *in_pChild)
{
  CAkParameterNodeBase *v2; // rdi
  CAkParameterNodeBase *v3; // rbx

  v2 = this;
  v3 = in_pChild;
  in_pChild->vfptr->AddRef((CAkIndexable *)in_pChild);
  return ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkParameterNodeBase *))v2->vfptr[2].AddRef)(v2, v3);
}

// File Line: 252
// RVA: 0xA6B650
__int64 __fastcall CAkParameterNodeBase::AddChild(CAkParameterNodeBase *this, WwiseObjectIDext in_ulID)
{
  CAkParameterNodeBase *v2; // rbx
  __int64 result; // rax
  CAkIndexable *v4; // rdx

  v2 = this;
  if ( !in_ulID.id )
    return 14i64;
  v4 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ulID.id, 0);
  if ( v4 )
    result = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkIndexable *))v2->vfptr[2].AddRef)(v2, v4);
  else
    result = 15i64;
  return result;
}

// File Line: 653
// RVA: 0xA81AE0
char __fastcall CAkParameterNodeBase::IsInHdrHierarchy(CAkParameterNodeBase *this)
{
  if ( *((_BYTE *)this + 83) & 8 )
    return 1;
  while ( this->m_pBusOutputNode )
  {
    this = this->m_pBusOutputNode;
LABEL_5:
    if ( *((_BYTE *)this + 83) & 8 )
      return 1;
  }
  this = this->m_pParentNode;
  if ( this )
    goto LABEL_5;
  return 0;
}

// File Line: 736
// RVA: 0xA6E1E0
void __fastcall CAkParameterNodeBase::PositioningChangeNotification(CAkParameterNodeBase *this, float in_RTPCValue, __int64 in_ParameterID, CAkRegisteredObj *in_GameObj)
{
  if ( *((_BYTE *)this + 83) & 0x10 )
    ((void (__fastcall *)(CAkParameterNodeBase *, CAkIndexableVtbl *, __int64, CAkRegisteredObj *))this->vfptr[6].AddRef)(
      this,
      this->vfptr,
      in_ParameterID,
      in_GameObj);
}

// File Line: 852
// RVA: 0xA71630
char __fastcall CAkParameterNodeBase::EnableActivityChunk(CAkParameterNodeBase *this, unsigned __int16 in_flagForwardToBus)
{
  unsigned __int16 v2; // bp
  CAkParameterNodeBase *v3; // rdi
  AkActivityChunk *v4; // rbx
  signed int v5; // er8
  bool v6; // si
  unsigned __int8 v7; // cl
  char result; // al

  v2 = in_flagForwardToBus;
  v3 = this;
  if ( this->m_pActivityChunk )
    return 1;
  v4 = (AkActivityChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  if ( v4 )
  {
    LOWORD(v5) = v3->m_u16MaxNumInstance;
    v6 = *((_BYTE *)v3 + 82) & 1;
    if ( ((unsigned __int64)LODWORD(v3->m_RTPCBitArray.m_iBitArray) >> 9) & 1 && (_WORD)v5 )
      v5 = (signed int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v3, 9u, 0i64);
    v7 = *((_BYTE *)v3 + 82);
    v4->m_ListPlayCountPerObj.m_pItems = 0i64;
    *(_QWORD *)&v4->m_ListPlayCountPerObj.m_uLength = 0i64;
    v4->m_listPBI.m_pFirst = 0i64;
    v4->m_Limiter.m_sortedPBIList.m_pItems = 0i64;
    *(_QWORD *)&v4->m_Limiter.m_sortedPBIList.m_uLength = 0i64;
    v4->m_Limiter.m_bDoesKillNewest = v6;
    v4->m_Limiter.m_u16LimiterMax = v5;
    v4->m_Limiter.m_bAllowUseVirtualBehavior = (v7 >> 1) & 1;
    v4->m_ActiveChildren.m_pItems = 0i64;
    *(_QWORD *)&v4->m_ActiveChildren.m_uLength = 0i64;
    *((_BYTE *)v4 + 80) &= 0xFEu;
    *(_QWORD *)&v4->m_PlayCount = 0i64;
    *((_BYTE *)v4 + 80) |= (v7 >> 4) & 1;
  }
  else
  {
    v4 = 0i64;
  }
  v3->m_pActivityChunk = v4;
  if ( v4 )
    result = ((__int64 (__fastcall *)(CAkParameterNodeBase *, _QWORD))v3->vfptr[19].Release)(v3, v2);
  else
    result = 0;
  return result;
}

// File Line: 949
// RVA: 0xA829A0
void __fastcall CAkParameterNodeBase::RemovePBI(CAkParameterNodeBase *this, CAkPBI *in_pPBI)
{
  AkActivityChunk *v2; // r10
  CAkParameterNodeBase *v3; // r9
  CAkPBI *v4; // r8
  CAkPBI *v5; // rcx
  CAkPBI *v6; // rax
  bool v7; // zf
  CAkPBI *v8; // rcx
  AkActivityChunk *v9; // rax

  v2 = this->m_pActivityChunk;
  v3 = this;
  v4 = 0i64;
  v5 = v2->m_listPBI.m_pFirst;
  v6 = v5;
  if ( v5 )
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
      v7 = v6 == v5;
      v8 = v6->pNextLightItem;
      if ( v7 )
        v2->m_listPBI.m_pFirst = v8;
      else
        v4->pNextLightItem = v8;
    }
  }
LABEL_9:
  v9 = v3->m_pActivityChunk;
  if ( !v9->m_PlayCount
    && !v9->m_uActivityCount
    && !v9->m_iPlayCountValid
    && !v9->m_iVirtualCountValid
    && !v9->m_listPBI.m_pFirst
    && !v9->m_ListPlayCountPerObj.m_uLength )
  {
    CAkParameterNodeBase::DeleteActivityChunk(v3);
  }
}

