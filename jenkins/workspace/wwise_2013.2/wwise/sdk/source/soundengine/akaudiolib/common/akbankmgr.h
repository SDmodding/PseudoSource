// File Line: 389
// RVA: 0xA5C240
signed __int64 __fastcall CAkBankMgr::StdBankRead<CAkFeedbackBus,CAkParameterNodeBase>(CAkBankMgr *this, AkBank::AKBKSubHircSection *in_rSection, CAkUsageSlot *in_pUsageSlot, CAkIndexItem<CAkParameterNodeBase *> *in_rIndex)
{
  AkBank::AKBKSubHircSection *v4; // r13
  CAkIndexItem<CAkParameterNodeBase *> *v5; // rdi
  CAkUsageSlot *v6; // rsi
  CAkBankMgr *v7; // r15
  unsigned int v8; // ebx
  unsigned int *v9; // rax
  unsigned int *v10; // r14
  unsigned int v12; // ebp
  CAkIndexable *v13; // rdi
  CAkFeedbackBus *v14; // rax
  __int64 v15; // rdx
  CAkIndexable **v16; // r8

  v4 = in_rSection;
  v5 = in_rIndex;
  v6 = in_pUsageSlot;
  v7 = this;
  v8 = 1;
  v9 = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v10 = v9;
  if ( !v9 )
    return 2i64;
  v12 = *v9;
  v13 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef((CAkIndexItem<CAkFxShareSet *> *)v5, *v9);
  if ( v13 )
    goto LABEL_15;
  EnterCriticalSection(&g_csMain.m_csLock);
  v14 = CAkFeedbackBus::Create(v12);
  v13 = (CAkIndexable *)&v14->vfptr;
  if ( v14 )
  {
    v8 = ((__int64 (__fastcall *)(CAkFeedbackBus *, unsigned int *, _QWORD))v14->vfptr[20].AddRef)(
           v14,
           v10,
           v4->dwSectionSize);
    if ( v8 != 1 )
      v13->vfptr->Release(v13);
  }
  else
  {
    v8 = 2;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v8 == 1 )
  {
LABEL_15:
    v15 = v6->m_listLoadedItem.m_uLength;
    if ( (unsigned int)v15 < v6->m_listLoadedItem.m_ulReserved )
    {
      v16 = &v6->m_listLoadedItem.m_pItems[v15];
      v6->m_listLoadedItem.m_uLength = v15 + 1;
      if ( v16 )
        *v16 = v13;
    }
  }
  CAkBankReader::ReleaseData(&v7->m_BankReader);
  return v8;
}

// File Line: 432
// RVA: 0xA5BCA0
signed __int64 __fastcall CAkBankMgr::ReadSourceParent<CAkFeedbackNode>(CAkBankMgr *this, AkBank::AKBKSubHircSection *in_rSection, CAkUsageSlot *in_pUsageSlot, unsigned int __formal)
{
  AkBank::AKBKSubHircSection *v4; // r14
  CAkUsageSlot *v5; // rsi
  CAkBankMgr *v6; // r15
  unsigned int *v7; // rax
  char *v8; // rdi
  unsigned int v10; // ebp
  CAkFeedbackNode *v11; // rbx
  AKRESULT v12; // edi
  CAkFeedbackNode *v13; // rax
  __int64 v14; // rdx
  CAkFeedbackNode **v15; // r8

  v4 = in_rSection;
  v5 = in_pUsageSlot;
  v6 = this;
  v7 = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = (char *)v7;
  if ( !v7 )
    return 2i64;
  v10 = *v7;
  v11 = (CAkFeedbackNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *v7, 0);
  if ( v11 )
  {
    EnterCriticalSection(&g_csMain.m_csLock);
    v12 = CAkFeedbackNode::SetInitialValues(v11, v8, v4->dwSectionSize, v5, 1);
    LeaveCriticalSection(&g_csMain.m_csLock);
    if ( v12 == 1 )
      goto LABEL_12;
    v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
  }
  else
  {
    EnterCriticalSection(&g_csMain.m_csLock);
    v13 = CAkFeedbackNode::Create(v10);
    v11 = v13;
    if ( v13 )
    {
      v12 = CAkFeedbackNode::SetInitialValues(v13, v8, v4->dwSectionSize, v5, 0);
      if ( v12 != 1 )
        v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
    }
    else
    {
      v12 = 2;
    }
    LeaveCriticalSection(&g_csMain.m_csLock);
  }
  if ( v12 == 1 )
  {
LABEL_12:
    v14 = v5->m_listLoadedItem.m_uLength;
    if ( (unsigned int)v14 < v5->m_listLoadedItem.m_ulReserved )
    {
      v15 = (CAkFeedbackNode **)&v5->m_listLoadedItem.m_pItems[v14];
      v5->m_listLoadedItem.m_uLength = v14 + 1;
      if ( v15 )
        *v15 = v11;
    }
  }
  CAkBankReader::ReleaseData(&v6->m_BankReader);
  return (unsigned int)v12;
}

