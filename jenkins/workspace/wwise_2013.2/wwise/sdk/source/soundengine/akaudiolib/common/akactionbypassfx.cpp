// File Line: 40
// RVA: 0xA96B80
signed __int64 __fastcall CAkActionBypassFX::Execute(CAkActionBypassFX *this, AkPendingAction *in_pAction)
{
  CAkRegisteredObj *v2; // r14
  signed int v3; // edx
  CAkActionBypassFX *v4; // rsi
  CAkRegistryMgr *v5; // rbp
  __int64 v6; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v7; // rdi
  CAkParameterNodeBase *v8; // rax
  CAkParameterNodeBase *v9; // rbx
  CAkParameterNodeBase *v10; // rax
  CAkParameterNodeBase *v11; // rdi
  unsigned int v12; // ebx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *j; // rbx
  CAkParameterNodeBase *v14; // rax
  CAkParameterNodeBase *v15; // rdi
  int v16; // edx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkIndexable *v18; // rdi
  WwiseObjectIDext *v19; // rcx
  signed __int64 v20; // rax
  CAkRegistryMgr *v21; // rbp
  __int64 v22; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v23; // rdi

  v2 = in_pAction->pGameObj;
  v3 = this->m_eActionType;
  v4 = this;
  if ( v3 > 6917 )
  {
    v16 = v3 - 6920;
    if ( v16 )
    {
      if ( v16 == 1 )
      {
        if ( v2->m_pListModifiedNodes )
        {
          for ( i = v2->m_pListModifiedNodes->m_pFirst; i; i = i->pNextListItem )
          {
            v18 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
            if ( v18 )
            {
              v19 = v4->m_listElementException.m_pItems;
              v20 = (signed __int64)&v19[v4->m_listElementException.m_uLength];
              if ( v19 == (WwiseObjectIDext *)v20 )
              {
LABEL_41:
                CAkParameterNodeBase::ResetBypassFX((CAkParameterNodeBase *)v18, v4->m_uTargetMask, 0i64);
              }
              else
              {
                while ( v18->key != v19->id || ((BYTE3(v18[3].pNextItem) >> 1) & 1) != v19->bIsBus )
                {
                  ++v19;
                  if ( v19 == (WwiseObjectIDext *)v20 )
                    goto LABEL_41;
                }
              }
              v18->vfptr->Release(v18);
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
        goto LABEL_58;
      while ( 1 )
      {
        v22 = (unsigned int)(v22 + 1);
        if ( (unsigned int)v22 >= 0xC1 )
          break;
        v23 = g_pRegistryMgr->m_mapRegisteredObj.m_table[v22];
        if ( v23 )
          goto LABEL_50;
      }
      if ( v23 )
      {
LABEL_58:
        do
        {
          do
          {
LABEL_50:
            CAkActionBypassFX::ResetBypassFXAEHelper(v4, v23->Assoc.item->m_pListModifiedNodes);
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
              goto LABEL_50;
          }
        }
        while ( v23 );
      }
    }
  }
  else if ( v3 == 6917 )
  {
    if ( v2->m_pListModifiedNodes )
    {
      for ( j = v2->m_pListModifiedNodes->m_pFirst; j; j = j->pNextListItem )
      {
        v14 = (CAkParameterNodeBase *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &j->Item);
        v15 = v14;
        if ( v14 )
        {
          CAkParameterNodeBase::ResetBypassFX(v14, v4->m_uTargetMask, v2);
          v15->vfptr->Release((CAkIndexable *)&v15->vfptr);
        }
      }
    }
  }
  else if ( v3 >= 6658 )
  {
    if ( v3 <= 6659 )
    {
      v10 = (CAkParameterNodeBase *)CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
      v11 = v10;
      if ( v10 )
      {
        if ( v4->m_bIsBypass )
          v12 = v4->m_uTargetMask;
        else
          v12 = 0;
        CAkParameterNodeBase::BypassFX(v10, v12, v4->m_uTargetMask, v2, 0);
        v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
      }
    }
    else if ( v3 > 6913 )
    {
      if ( v3 <= 6915 )
      {
        v8 = (CAkParameterNodeBase *)CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
        v9 = v8;
        if ( v8 )
        {
          CAkParameterNodeBase::ResetBypassFX(v8, v4->m_uTargetMask, v2);
          v9->vfptr->Release((CAkIndexable *)&v9->vfptr);
        }
      }
      else if ( v3 == 6916 )
      {
        CAkActionBypassFX::ResetBypassFxAllHelper(this, &g_pRegistryMgr->m_listModifiedNodes);
        v5 = g_pRegistryMgr;
        LODWORD(v6) = 0;
        v7 = g_pRegistryMgr->m_mapRegisteredObj.m_table[0];
        if ( v7 )
          goto LABEL_59;
        while ( 1 )
        {
          v6 = (unsigned int)(v6 + 1);
          if ( (unsigned int)v6 >= 0xC1 )
            break;
          v7 = g_pRegistryMgr->m_mapRegisteredObj.m_table[v6];
          if ( v7 )
            goto LABEL_13;
        }
        if ( v7 )
        {
LABEL_59:
          do
          {
            do
            {
LABEL_13:
              CAkActionBypassFX::ResetBypassFxAllHelper(v4, v7->Assoc.item->m_pListModifiedNodes);
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
          while ( v7 );
        }
      }
    }
  }
  return 1i64;
}

// File Line: 151
// RVA: 0xA96F30
void __fastcall CAkActionBypassFX::ResetBypassFxAllHelper(CAkActionBypassFX *this, CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *in_pListID)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v2; // rbx
  CAkActionBypassFX *v3; // rsi
  CAkParameterNodeBase *v4; // rax
  CAkParameterNodeBase *v5; // rdi

  if ( in_pListID )
  {
    v2 = in_pListID->m_pFirst;
    v3 = this;
    if ( in_pListID->m_pFirst )
    {
      do
      {
        v4 = (CAkParameterNodeBase *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &v2->Item);
        v5 = v4;
        if ( v4 )
        {
          CAkParameterNodeBase::ResetBypassFX(v4, v3->m_uTargetMask, 0i64);
          v5->vfptr->Release((CAkIndexable *)&v5->vfptr);
        }
        v2 = v2->pNextListItem;
      }
      while ( v2 );
    }
  }
}

// File Line: 167
// RVA: 0xA96E80
void __fastcall CAkActionBypassFX::ResetBypassFXAEHelper(CAkActionBypassFX *this, CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *in_pListID)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v2; // rbx
  CAkActionBypassFX *v3; // rsi
  CAkIndexable *v4; // rdi
  WwiseObjectIDext *v5; // rcx
  signed __int64 v6; // rax

  if ( in_pListID )
  {
    v2 = in_pListID->m_pFirst;
    v3 = this;
    if ( in_pListID->m_pFirst )
    {
      do
      {
        v4 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &v2->Item);
        if ( v4 )
        {
          v5 = v3->m_listElementException.m_pItems;
          v6 = (signed __int64)&v5[v3->m_listElementException.m_uLength];
          if ( v5 == (WwiseObjectIDext *)v6 )
          {
LABEL_8:
            CAkParameterNodeBase::ResetBypassFX((CAkParameterNodeBase *)v4, v3->m_uTargetMask, 0i64);
          }
          else
          {
            while ( v4->key != v5->id || ((BYTE3(v4[3].pNextItem) >> 1) & 1) != v5->bIsBus )
            {
              ++v5;
              if ( v5 == (WwiseObjectIDext *)v6 )
                goto LABEL_8;
            }
          }
          v4->vfptr->Release(v4);
        }
        v2 = v2->pNextListItem;
      }
      while ( v2 );
    }
  }
}

// File Line: 196
// RVA: 0xA96B00
CAkActionBypassFX *__fastcall CAkActionBypassFX::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionBypassFX *result; // rax
  CAkActionBypassFX *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionBypassFX *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  v5 = result;
  if ( result )
  {
    CAkActionExcept::CAkActionExcept((CAkActionExcept *)&result->vfptr, v2, v3);
    v5->m_bIsBypass = 0;
    v5->m_uTargetMask = -1;
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionBypassFX::`vftable';
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 222
// RVA: 0xA96FA0
AKRESULT __fastcall CAkActionBypassFX::SetActionParams(CAkActionBypassFX *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char v3; // r9
  unsigned int v4; // er9

  v3 = *(*io_rpData)++;
  this->m_bIsBypass = v3 != 0;
  v4 = (unsigned __int8)*(*io_rpData)++;
  this->m_uTargetMask = v4;
  return CAkActionExcept::SetExceptParams((CAkActionExcept *)&this->vfptr, io_rpData, io_rulDataSize);
}

