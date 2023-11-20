// File Line: 31
// RVA: 0xA9E710
void __fastcall CAkActionSetValue::CAkActionSetValue(CAkActionSetValue *this, AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionSetValue *v3; // rbx

  v3 = this;
  CAkActionExcept::CAkActionExcept((CAkActionExcept *)&this->vfptr, in_eActionType, in_ulID);
  v3->vfptr = (CAkIndexableVtbl *)&CAkActionSetValue::`vftable;
}

// File Line: 35
// RVA: 0xA9E740
void __fastcall CAkActionSetValue::~CAkActionSetValue(CAkActionSetValue *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkActionSetValue::`vftable;
  CAkActionExcept::~CAkActionExcept((CAkActionExcept *)&this->vfptr);
}

// File Line: 40
// RVA: 0xA9E790
signed __int64 __fastcall CAkActionSetValue::Execute(CAkActionSetValue *this, AkPendingAction *in_pAction)
{
  signed int v2; // er8
  AkPendingAction *v3; // rbp
  CAkActionSetValue *v4; // rsi
  int v5; // er8
  int v6; // er8
  int v7; // er8
  int v8; // er8
  int v9; // er8
  CAkRegisteredObj *v10; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkIndexable *v12; // rax
  CAkIndexable *v13; // rdi
  int v15; // er8
  int v16; // er8
  int v17; // er8
  int v18; // er8
  int v19; // er8
  int v20; // er8
  int v21; // er8
  CAkRegistryMgr *v22; // rbp
  __int64 v23; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v24; // rdi
  int v25; // er8
  int v26; // er8
  int v27; // er8
  CAkIndexable *v28; // rax
  CAkIndexable *v29; // rbx
  CAkIndexable *v30; // rax
  CAkIndexable *v31; // rbx
  CAkIndexable *v32; // rax
  CAkIndexable *v33; // rbx
  int v34; // er8
  int v35; // er8
  CAkRegisteredObj *v36; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *j; // rbx
  CAkIndexable *v38; // rax
  CAkIndexable *v39; // rdi
  CAkRegistryMgr *v40; // rbp
  __int64 v41; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v42; // rdi
  CAkIndexable *v43; // rax
  CAkIndexable *v44; // rbx

  v2 = this->m_eActionType;
  v3 = in_pAction;
  v4 = this;
  if ( v2 > 2818 )
  {
    if ( v2 > 3586 )
    {
      if ( v2 <= 3842 )
      {
        if ( v2 != 3842 )
        {
          if ( v2 != 3587 )
            return 1i64;
          goto LABEL_57;
        }
        goto LABEL_59;
      }
      if ( v2 <= 3848 )
      {
        if ( v2 != 3848 )
        {
          v34 = v2 - 3843;
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
          goto LABEL_83;
        }
LABEL_43:
        CAkActionSetValue::ResetAEHelper(this, &g_pRegistryMgr->m_listModifiedNodes);
        v22 = g_pRegistryMgr;
        LODWORD(v23) = 0;
        v24 = g_pRegistryMgr->m_mapRegisteredObj.m_table[0];
        if ( v24 )
          goto LABEL_100;
        while ( 1 )
        {
          v23 = (unsigned int)(v23 + 1);
          if ( (unsigned int)v23 >= 0xC1 )
            break;
          v24 = g_pRegistryMgr->m_mapRegisteredObj.m_table[v23];
          if ( v24 )
            goto LABEL_86;
        }
        if ( v24 )
        {
LABEL_100:
          do
          {
            do
            {
LABEL_86:
              CAkActionSetValue::ResetAEHelper(v4, v24->Assoc.item->m_pListModifiedNodes);
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
                goto LABEL_86;
            }
          }
          while ( v24 );
        }
        return 1i64;
      }
      if ( v2 != 3849 )
      {
        if ( v2 > 4865 )
        {
          if ( v2 <= 4867 )
          {
            ((void (__fastcall *)(CAkActionSetValue *, _QWORD, CAkRegisteredObj *))this->vfptr[3].Release)(
              this,
              0i64,
              in_pAction->pGameObj);
          }
          else if ( (unsigned int)(v2 - 5122) <= 1 )
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
      if ( v2 == 3586 )
        goto LABEL_52;
      if ( v2 > 2825 )
      {
        v25 = v2 - 3074;
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
        v28 = CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
        v29 = v28;
        if ( v28 )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkIndexable *))v4->vfptr[3].Category)(v4, v28);
          v29->vfptr->Release(v29);
        }
        return 1i64;
      }
      if ( v2 != 2825 )
      {
        v19 = v2 - 2819;
        if ( !v19 )
          goto LABEL_83;
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
    v10 = in_pAction->pGameObj;
    if ( v10->m_pListModifiedNodes )
    {
      for ( i = v10->m_pListModifiedNodes->m_pFirst; i; i = i->pNextListItem )
      {
        v12 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
        v13 = v12;
        if ( v12 )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkIndexable *, CAkRegisteredObj *))v4->vfptr[4].Category)(
            v4,
            v12,
            v3->pGameObj);
          v13->vfptr->Release(v13);
        }
      }
    }
    return 1i64;
  }
  if ( v2 == 2818 )
    goto LABEL_59;
  if ( v2 > 2050 )
  {
    if ( v2 <= 2306 )
    {
      if ( v2 != 2306 )
      {
        if ( v2 != 2051 )
          return 1i64;
        goto LABEL_57;
      }
LABEL_59:
      v32 = CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
      v33 = v32;
      if ( v32 )
      {
        ((void (__fastcall *)(CAkActionSetValue *, CAkIndexable *))v4->vfptr[4].AddRef)(v4, v32);
        v33->vfptr->Release(v33);
      }
      return 1i64;
    }
    if ( v2 <= 2312 )
    {
      if ( v2 != 2312 )
      {
        v15 = v2 - 2307;
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
LABEL_83:
        v43 = CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
        v44 = v43;
        if ( v43 )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkIndexable *, CAkRegisteredObj *))v4->vfptr[4].__vecDelDtor)(
            v4,
            v43,
            v3->pGameObj);
          v44->vfptr->Release(v44);
        }
        return 1i64;
      }
      goto LABEL_43;
    }
    v17 = v2 - 2313;
    if ( v17 )
    {
      v18 = v17 - 249;
      if ( v18 )
      {
        if ( v18 != 1 )
          return 1i64;
LABEL_57:
        v30 = CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
        v31 = v30;
        if ( v30 )
        {
          ((void (__fastcall *)(CAkActionSetValue *, CAkIndexable *, CAkRegisteredObj *))v4->vfptr[3].Release)(
            v4,
            v30,
            v3->pGameObj);
          v31->vfptr->Release(v31);
        }
        return 1i64;
      }
      goto LABEL_52;
    }
    goto LABEL_15;
  }
  if ( v2 == 2050 )
    goto LABEL_52;
  if ( v2 <= 1794 )
  {
    if ( v2 != 1794 )
    {
      v5 = v2 - 1538;
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
  v6 = v2 - 1795;
  if ( !v6 )
    goto LABEL_83;
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
          ((void (__fastcall *)(CAkActionSetValue *, CAkIndexable *, CAkRegisteredObj *))v4->vfptr[4].__vecDelDtor)(
            v4,
            v38,
            v3->pGameObj);
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
    goto LABEL_101;
  while ( 1 )
  {
    v41 = (unsigned int)(v41 + 1);
    if ( (unsigned int)v41 >= 0xC1 )
      break;
    v42 = g_pRegistryMgr->m_mapRegisteredObj.m_table[v41];
    if ( v42 )
      goto LABEL_77;
  }
  if ( v42 )
  {
LABEL_101:
    do
    {
      do
      {
LABEL_77:
        CAkActionSetValue::ResetAllHelper(v4, v42->Assoc.item->m_pListModifiedNodes);
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
    while ( v42 );
  }
  return 1i64;
}

// File Line: 180
// RVA: 0xA9ECE0
void __fastcall CAkActionSetValue::ResetAllHelper(CAkActionSetValue *this, CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *in_pListID)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v2; // rbx
  CAkActionSetValue *v3; // rsi
  CAkIndexable *v4; // rdi

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
          ((void (__fastcall *)(CAkActionSetValue *, CAkIndexable *))v3->vfptr[4].Release)(v3, v4);
          v4->vfptr->Release(v4);
        }
        v2 = v2->pNextListItem;
      }
      while ( v2 );
    }
  }
}

// File Line: 196
// RVA: 0xA9EC70
void __fastcall CAkActionSetValue::ResetAEHelper(CAkActionSetValue *this, CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *in_pListID)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v2; // rbx
  CAkActionSetValue *v3; // rsi
  CAkIndexable *v4; // rdi

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
          v3->vfptr[5].__vecDelDtor((CAkIndexable *)&v3->vfptr, (unsigned int)v4);
          v4->vfptr->Release(v4);
        }
        v2 = v2->pNextListItem;
      }
      while ( v2 );
    }
  }
}

