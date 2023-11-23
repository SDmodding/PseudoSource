// File Line: 40
// RVA: 0xA96B80
__int64 __fastcall CAkActionBypassFX::Execute(CAkActionBypassFX *this, AkPendingAction *in_pAction)
{
  CAkRegisteredObj *pGameObj; // r14
  unsigned int m_eActionType; // edx
  CAkRegistryMgr *v5; // rbp
  __int64 v6; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v7; // rdi
  CAkParameterNodeBase *v8; // rax
  CAkParameterNodeBase *v9; // rbx
  CAkParameterNodeBase *v10; // rax
  CAkParameterNodeBase *v11; // rdi
  unsigned int m_uTargetMask; // ebx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *j; // rbx
  CAkParameterNodeBase *v14; // rax
  CAkParameterNodeBase *v15; // rdi
  unsigned int v16; // edx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi
  WwiseObjectIDext *m_pItems; // rcx
  WwiseObjectIDext *v20; // rax
  CAkRegistryMgr *v21; // rbp
  __int64 v22; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v23; // rdi

  pGameObj = in_pAction->pGameObj;
  m_eActionType = this->m_eActionType;
  if ( m_eActionType > 0x1B05 )
  {
    v16 = m_eActionType - 6920;
    if ( v16 )
    {
      if ( v16 == 1 )
      {
        if ( pGameObj->m_pListModifiedNodes )
        {
          for ( i = pGameObj->m_pListModifiedNodes->m_pFirst; i; i = i->pNextListItem )
          {
            NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
            if ( NodePtrAndAddRef )
            {
              m_pItems = this->m_listElementException.m_pItems;
              v20 = &m_pItems[this->m_listElementException.m_uLength];
              if ( m_pItems == v20 )
              {
LABEL_40:
                CAkParameterNodeBase::ResetBypassFX(NodePtrAndAddRef, this->m_uTargetMask, 0i64);
              }
              else
              {
                while ( NodePtrAndAddRef->key != m_pItems->id
                     || ((*((_BYTE *)NodePtrAndAddRef + 83) & 2) != 0) != m_pItems->bIsBus )
                {
                  if ( ++m_pItems == v20 )
                    goto LABEL_40;
                }
              }
              NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
            }
          }
        }
      }
    }
    else
    {
      CAkActionBypassFX::ResetBypassFXAEHelper(this, &g_pRegistryMgr->m_listModifiedNodes);
      v21 = g_pRegistryMgr;
      LODWORD(v22) = 0;
      v23 = g_pRegistryMgr->m_mapRegisteredObj.m_table[0];
      if ( v23 )
      {
        do
        {
LABEL_49:
          CAkActionBypassFX::ResetBypassFXAEHelper(this, v23->Assoc.item->m_pListModifiedNodes);
          v23 = v23->pNextItem;
        }
        while ( v23 );
        while ( 1 )
        {
          v22 = (unsigned int)(v22 + 1);
          if ( (unsigned int)v22 >= 0xC1 )
            break;
          v23 = v21->m_mapRegisteredObj.m_table[v22];
          if ( v23 )
            goto LABEL_49;
        }
      }
      else
      {
        while ( 1 )
        {
          v22 = (unsigned int)(v22 + 1);
          if ( (unsigned int)v22 >= 0xC1 )
            break;
          v23 = g_pRegistryMgr->m_mapRegisteredObj.m_table[v22];
          if ( v23 )
            goto LABEL_49;
        }
      }
    }
  }
  else if ( m_eActionType == 6917 )
  {
    if ( pGameObj->m_pListModifiedNodes )
    {
      for ( j = pGameObj->m_pListModifiedNodes->m_pFirst; j; j = j->pNextListItem )
      {
        v14 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &j->Item);
        v15 = v14;
        if ( v14 )
        {
          CAkParameterNodeBase::ResetBypassFX(v14, this->m_uTargetMask, pGameObj);
          v15->vfptr->Release(v15);
        }
      }
    }
  }
  else if ( this->m_eActionType >= 0x1A02u )
  {
    if ( this->m_eActionType <= 0x1A03u )
    {
      v10 = CAkAction::GetAndRefTarget(this);
      v11 = v10;
      if ( v10 )
      {
        if ( this->m_bIsBypass )
          m_uTargetMask = this->m_uTargetMask;
        else
          m_uTargetMask = 0;
        CAkParameterNodeBase::BypassFX(v10, m_uTargetMask, this->m_uTargetMask, pGameObj, 0);
        v11->vfptr->Release(v11);
      }
    }
    else if ( this->m_eActionType > 0x1B01u )
    {
      if ( this->m_eActionType <= 0x1B03u )
      {
        v8 = CAkAction::GetAndRefTarget(this);
        v9 = v8;
        if ( v8 )
        {
          CAkParameterNodeBase::ResetBypassFX(v8, this->m_uTargetMask, pGameObj);
          v9->vfptr->Release(v9);
        }
      }
      else if ( m_eActionType == 6916 )
      {
        CAkActionBypassFX::ResetBypassFxAllHelper(this, &g_pRegistryMgr->m_listModifiedNodes);
        v5 = g_pRegistryMgr;
        LODWORD(v6) = 0;
        v7 = g_pRegistryMgr->m_mapRegisteredObj.m_table[0];
        if ( v7 )
        {
          do
          {
LABEL_13:
            CAkActionBypassFX::ResetBypassFxAllHelper(this, v7->Assoc.item->m_pListModifiedNodes);
            v7 = v7->pNextItem;
          }
          while ( v7 );
          while ( 1 )
          {
            v6 = (unsigned int)(v6 + 1);
            if ( (unsigned int)v6 >= 0xC1 )
              break;
            v7 = v5->m_mapRegisteredObj.m_table[v6];
            if ( v7 )
              goto LABEL_13;
          }
        }
        else
        {
          while ( 1 )
          {
            v6 = (unsigned int)(v6 + 1);
            if ( (unsigned int)v6 >= 0xC1 )
              break;
            v7 = g_pRegistryMgr->m_mapRegisteredObj.m_table[v6];
            if ( v7 )
              goto LABEL_13;
          }
        }
      }
    }
  }
  return 1i64;
}

// File Line: 151
// RVA: 0xA96F30
void __fastcall CAkActionBypassFX::ResetBypassFxAllHelper(
        CAkActionBypassFX *this,
        CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *in_pListID)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v5; // rdi

  if ( in_pListID )
  {
    for ( i = in_pListID->m_pFirst; i; i = i->pNextListItem )
    {
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
      v5 = NodePtrAndAddRef;
      if ( NodePtrAndAddRef )
      {
        CAkParameterNodeBase::ResetBypassFX(NodePtrAndAddRef, this->m_uTargetMask, 0i64);
        v5->vfptr->Release(v5);
      }
    }
  }
}

// File Line: 167
// RVA: 0xA96E80
void __fastcall CAkActionBypassFX::ResetBypassFXAEHelper(
        CAkActionBypassFX *this,
        CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *in_pListID)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi
  WwiseObjectIDext *m_pItems; // rcx
  WwiseObjectIDext *v6; // rax

  if ( in_pListID )
  {
    for ( i = in_pListID->m_pFirst; i; i = i->pNextListItem )
    {
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
      if ( NodePtrAndAddRef )
      {
        m_pItems = this->m_listElementException.m_pItems;
        v6 = &m_pItems[this->m_listElementException.m_uLength];
        if ( m_pItems == v6 )
        {
LABEL_8:
          CAkParameterNodeBase::ResetBypassFX(NodePtrAndAddRef, this->m_uTargetMask, 0i64);
        }
        else
        {
          while ( NodePtrAndAddRef->key != m_pItems->id
               || ((*((_BYTE *)NodePtrAndAddRef + 83) & 2) != 0) != m_pItems->bIsBus )
          {
            if ( ++m_pItems == v6 )
              goto LABEL_8;
          }
        }
        NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
      }
    }
  }
}

// File Line: 196
// RVA: 0xA96B00
CAkActionBypassFX *__fastcall CAkActionBypassFX::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionBypassFX *result; // rax
  CAkActionBypassFX *v5; // rbx

  result = (CAkActionBypassFX *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  v5 = result;
  if ( result )
  {
    CAkActionExcept::CAkActionExcept(result, in_eActionType, in_ulID);
    v5->m_bIsBypass = 0;
    v5->m_uTargetMask = -1;
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionBypassFX::`vftable;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

// File Line: 222
// RVA: 0xA96FA0
AKRESULT __fastcall CAkActionBypassFX::SetActionParams(
        CAkActionBypassFX *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  char v3; // r9
  unsigned int v4; // r9d

  v3 = *(*io_rpData)++;
  this->m_bIsBypass = v3 != 0;
  v4 = (unsigned __int8)*(*io_rpData)++;
  this->m_uTargetMask = v4;
  return CAkActionExcept::SetExceptParams(this, io_rpData, io_rulDataSize);
}

