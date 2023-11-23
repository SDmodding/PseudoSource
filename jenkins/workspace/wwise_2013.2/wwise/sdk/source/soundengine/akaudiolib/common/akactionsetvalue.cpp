// File Line: 31
// RVA: 0xA9E710
void __fastcall CAkActionSetValue::CAkActionSetValue(
        CAkActionSetValue *this,
        AkActionType in_eActionType,
        unsigned int in_ulID)
{
  CAkActionExcept::CAkActionExcept(this, in_eActionType, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkActionSetValue::`vftable;
}

// File Line: 35
// RVA: 0xA9E740
void __fastcall CAkActionSetValue::~CAkActionSetValue(CAkActionSetValue *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkActionSetValue::`vftable;
  CAkActionExcept::~CAkActionExcept(this);
}

// File Line: 40
// RVA: 0xA9E790
__int64 __fastcall CAkActionSetValue::Execute(CAkActionSetValue *this, AkPendingAction *in_pAction)
{
  unsigned int m_eActionType; // r8d
  unsigned int v5; // r8d
  unsigned int v6; // r8d
  unsigned int v7; // r8d
  unsigned int v8; // r8d
  unsigned int v9; // r8d
  CAkRegisteredObj *pGameObj; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v13; // rdi
  unsigned int v15; // r8d
  unsigned int v16; // r8d
  unsigned int v17; // r8d
  unsigned int v18; // r8d
  unsigned int v19; // r8d
  unsigned int v20; // r8d
  unsigned int v21; // r8d
  CAkRegistryMgr *v22; // rbp
  __int64 v23; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v24; // rdi
  unsigned int v25; // r8d
  unsigned int v26; // r8d
  unsigned int v27; // r8d
  CAkParameterNodeBase *v28; // rax
  CAkParameterNodeBase *v29; // rbx
  CAkParameterNodeBase *v30; // rax
  CAkParameterNodeBase *v31; // rbx
  CAkParameterNodeBase *v32; // rax
  CAkParameterNodeBase *v33; // rbx
  unsigned int v34; // r8d
  unsigned int v35; // r8d
  CAkRegisteredObj *v36; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *j; // rbx
  CAkParameterNodeBase *v38; // rax
  CAkParameterNodeBase *v39; // rdi
  CAkRegistryMgr *v40; // rbp
  __int64 v41; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v42; // rdi
  CAkParameterNodeBase *v43; // rax
  CAkParameterNodeBase *v44; // rbx

  m_eActionType = this->m_eActionType;
  if ( m_eActionType > 0xB02 )
  {
    if ( this->m_eActionType > 0xE02u )
    {
      if ( this->m_eActionType <= 0xF02u )
      {
        if ( m_eActionType != 3842 )
        {
          if ( m_eActionType != 3587 )
            return 1i64;
          goto LABEL_57;
        }
        goto LABEL_59;
      }
      if ( this->m_eActionType <= 0xF08u )
      {
        if ( m_eActionType != 3848 )
        {
          v34 = m_eActionType - 3843;
          if ( v34 )
          {
            v35 = v34 - 1;
            if ( v35 )
            {
              if ( v35 != 1 )
                return 1i64;
              goto LABEL_66;
            }
            goto LABEL_72;
          }
          goto LABEL_82;
        }
LABEL_43:
        CAkActionSetValue::ResetAEHelper(this, &g_pRegistryMgr->m_listModifiedNodes);
        v22 = g_pRegistryMgr;
        LODWORD(v23) = 0;
        v24 = g_pRegistryMgr->m_mapRegisteredObj.m_table[0];
        if ( v24 )
        {
          do
          {
LABEL_85:
            CAkActionSetValue::ResetAEHelper(this, v24->Assoc.item->m_pListModifiedNodes);
            v24 = v24->pNextItem;
          }
          while ( v24 );
          while ( 1 )
          {
            v23 = (unsigned int)(v23 + 1);
            if ( (unsigned int)v23 >= 0xC1 )
              break;
            v24 = v22->m_mapRegisteredObj.m_table[v23];
            if ( v24 )
              goto LABEL_85;
          }
        }
        else
        {
          while ( 1 )
          {
            v23 = (unsigned int)(v23 + 1);
            if ( (unsigned int)v23 >= 0xC1 )
              break;
            v24 = g_pRegistryMgr->m_mapRegisteredObj.m_table[v23];
            if ( v24 )
              goto LABEL_85;
          }
        }
        return 1i64;
      }
      if ( m_eActionType != 3849 )
      {
        if ( this->m_eActionType > 0x1301u )
        {
          if ( this->m_eActionType <= 0x1303u )
          {
            ((void (__fastcall *)(CAkActionSetValue *, _QWORD, CAkRegisteredObj *))this->vfptr[3].Release)(
              this,
              0i64,
              in_pAction->pGameObj);
          }
          else if ( m_eActionType - 5122 <= 1 )
          {
            ((void (__fastcall *)(CAkActionSetValue *, _QWORD, CAkRegisteredObj *))this->vfptr[4].__vecDelDtor)(
              this,
              0i64,
              in_pAction->pGameObj);
          }
        }
        return 1i64;
      }
    }
    else
    {
      if ( m_eActionType == 3586 )
        goto LABEL_52;
      if ( this->m_eActionType > 0xB09u )
      {
        v25 = m_eActionType - 3074;
        if ( v25 )
        {
          v26 = v25 - 256;
          if ( !v26 )
            goto LABEL_59;
          v27 = v26 - 2;
          if ( !v27 )
            goto LABEL_72;
          if ( v27 != 4 )
            return 1i64;
          goto LABEL_43;
        }
LABEL_52:
        v28 = CAkAction::GetAndRefTarget(this);
        v29 = v28;
        if ( v28 )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkParameterNodeBase *))this->vfptr[3].Category)(this, v28);
          v29->vfptr->Release(v29);
        }
        return 1i64;
      }
      if ( m_eActionType != 2825 )
      {
        v19 = m_eActionType - 2819;
        if ( !v19 )
          goto LABEL_82;
        v20 = v19 - 1;
        if ( !v20 )
          goto LABEL_72;
        v21 = v20 - 1;
        if ( !v21 )
          goto LABEL_66;
        if ( v21 != 3 )
          return 1i64;
        goto LABEL_43;
      }
    }
LABEL_15:
    pGameObj = in_pAction->pGameObj;
    if ( pGameObj->m_pListModifiedNodes )
    {
      for ( i = pGameObj->m_pListModifiedNodes->m_pFirst; i; i = i->pNextListItem )
      {
        NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
        v13 = NodePtrAndAddRef;
        if ( NodePtrAndAddRef )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkParameterNodeBase *, CAkRegisteredObj *))this->vfptr[4].Category)(
            this,
            NodePtrAndAddRef,
            in_pAction->pGameObj);
          v13->vfptr->Release(v13);
        }
      }
    }
    return 1i64;
  }
  if ( m_eActionType == 2818 )
    goto LABEL_59;
  if ( this->m_eActionType > 0x802u )
  {
    if ( this->m_eActionType <= 0x902u )
    {
      if ( m_eActionType != 2306 )
      {
        if ( m_eActionType != 2051 )
          return 1i64;
        goto LABEL_57;
      }
LABEL_59:
      v32 = CAkAction::GetAndRefTarget(this);
      v33 = v32;
      if ( v32 )
      {
        ((void (__fastcall *)(CAkActionSetValue *, CAkParameterNodeBase *))this->vfptr[4].AddRef)(this, v32);
        v33->vfptr->Release(v33);
      }
      return 1i64;
    }
    if ( this->m_eActionType <= 0x908u )
    {
      if ( m_eActionType != 2312 )
      {
        v15 = m_eActionType - 2307;
        if ( v15 )
        {
          v16 = v15 - 1;
          if ( v16 )
          {
            if ( v16 != 1 )
              return 1i64;
            goto LABEL_66;
          }
          goto LABEL_72;
        }
LABEL_82:
        v43 = CAkAction::GetAndRefTarget(this);
        v44 = v43;
        if ( v43 )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkParameterNodeBase *, CAkRegisteredObj *))this->vfptr[4].__vecDelDtor)(
            this,
            v43,
            in_pAction->pGameObj);
          v44->vfptr->Release(v44);
        }
        return 1i64;
      }
      goto LABEL_43;
    }
    v17 = m_eActionType - 2313;
    if ( v17 )
    {
      v18 = v17 - 249;
      if ( v18 )
      {
        if ( v18 != 1 )
          return 1i64;
LABEL_57:
        v30 = CAkAction::GetAndRefTarget(this);
        v31 = v30;
        if ( v30 )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkParameterNodeBase *, CAkRegisteredObj *))this->vfptr[3].Release)(
            this,
            v30,
            in_pAction->pGameObj);
          v31->vfptr->Release(v31);
        }
        return 1i64;
      }
      goto LABEL_52;
    }
    goto LABEL_15;
  }
  if ( m_eActionType == 2050 )
    goto LABEL_52;
  if ( this->m_eActionType <= 0x702u )
  {
    if ( m_eActionType != 1794 )
    {
      v5 = m_eActionType - 1538;
      if ( v5 )
      {
        if ( v5 != 1 )
          return 1i64;
        goto LABEL_57;
      }
      goto LABEL_52;
    }
    goto LABEL_59;
  }
  v6 = m_eActionType - 1795;
  if ( !v6 )
    goto LABEL_82;
  v7 = v6 - 1;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      v9 = v8 - 3;
      if ( v9 )
      {
        if ( v9 != 1 )
          return 1i64;
        goto LABEL_15;
      }
      goto LABEL_43;
    }
LABEL_66:
    v36 = in_pAction->pGameObj;
    if ( v36->m_pListModifiedNodes )
    {
      for ( j = v36->m_pListModifiedNodes->m_pFirst; j; j = j->pNextListItem )
      {
        v38 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &j->Item);
        v39 = v38;
        if ( v38 )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkParameterNodeBase *, CAkRegisteredObj *))this->vfptr[4].__vecDelDtor)(
            this,
            v38,
            in_pAction->pGameObj);
          v39->vfptr->Release(v39);
        }
      }
    }
    return 1i64;
  }
LABEL_72:
  CAkActionSetValue::ResetAllHelper(this, &g_pRegistryMgr->m_listModifiedNodes);
  v40 = g_pRegistryMgr;
  LODWORD(v41) = 0;
  v42 = g_pRegistryMgr->m_mapRegisteredObj.m_table[0];
  if ( v42 )
  {
    do
    {
LABEL_77:
      CAkActionSetValue::ResetAllHelper(this, v42->Assoc.item->m_pListModifiedNodes);
      v42 = v42->pNextItem;
    }
    while ( v42 );
    while ( 1 )
    {
      v41 = (unsigned int)(v41 + 1);
      if ( (unsigned int)v41 >= 0xC1 )
        break;
      v42 = v40->m_mapRegisteredObj.m_table[v41];
      if ( v42 )
        goto LABEL_77;
    }
  }
  else
  {
    while ( 1 )
    {
      v41 = (unsigned int)(v41 + 1);
      if ( (unsigned int)v41 >= 0xC1 )
        break;
      v42 = g_pRegistryMgr->m_mapRegisteredObj.m_table[v41];
      if ( v42 )
        goto LABEL_77;
    }
  }
  return 1i64;
}

// File Line: 180
// RVA: 0xA9ECE0
void __fastcall CAkActionSetValue::ResetAllHelper(
        CAkActionSetValue *this,
        CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *in_pListID)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi

  if ( in_pListID )
  {
    for ( i = in_pListID->m_pFirst; i; i = i->pNextListItem )
    {
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
      if ( NodePtrAndAddRef )
      {
        ((void (__fastcall *)(CAkActionSetValue *, CAkParameterNodeBase *))this->vfptr[4].Release)(
          this,
          NodePtrAndAddRef);
        NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
      }
    }
  }
}

// File Line: 196
// RVA: 0xA9EC70
void __fastcall CAkActionSetValue::ResetAEHelper(
        CAkActionSetValue *this,
        CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *in_pListID)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi

  if ( in_pListID )
  {
    for ( i = in_pListID->m_pFirst; i; i = i->pNextListItem )
    {
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
      if ( NodePtrAndAddRef )
      {
        this->vfptr[5].__vecDelDtor(this, (unsigned int)NodePtrAndAddRef);
        NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
      }
    }
  }
}

