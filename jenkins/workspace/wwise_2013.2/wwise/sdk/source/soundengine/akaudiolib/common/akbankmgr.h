// File Line: 389
// RVA: 0xA5C240
__int64 __fastcall CAkBankMgr::StdBankRead<CAkFeedbackBus,CAkParameterNodeBase>(
        CAkBankMgr *this,
        AkBank::AKBKSubHircSection *in_rSection,
        CAkUsageSlot *in_pUsageSlot,
        CAkIndexItem<CAkFxShareSet *> *in_rIndex)
{
  unsigned int v8; // ebx
  unsigned int *Data; // rax
  unsigned int *v10; // r14
  unsigned int v12; // ebp
  CAkIndexable *PtrAndAddRef; // rdi
  CAkFeedbackBus *v14; // rax
  __int64 m_uLength; // rdx
  CAkIndexable **v16; // r8

  v8 = 1;
  Data = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v10 = Data;
  if ( !Data )
    return 2i64;
  v12 = *Data;
  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(in_rIndex, *Data);
  if ( PtrAndAddRef )
    goto LABEL_9;
  EnterCriticalSection(&g_csMain.m_csLock);
  v14 = CAkFeedbackBus::Create(v12);
  PtrAndAddRef = v14;
  if ( v14 )
  {
    v8 = ((__int64 (__fastcall *)(CAkFeedbackBus *, unsigned int *, _QWORD))v14->vfptr[20].AddRef)(
           v14,
           v10,
           in_rSection->dwSectionSize);
    if ( v8 != 1 )
      PtrAndAddRef->vfptr->Release(PtrAndAddRef);
  }
  else
  {
    v8 = 2;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v8 == 1 )
  {
LABEL_9:
    m_uLength = in_pUsageSlot->m_listLoadedItem.m_uLength;
    if ( (unsigned int)m_uLength < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
    {
      v16 = &in_pUsageSlot->m_listLoadedItem.m_pItems[m_uLength];
      in_pUsageSlot->m_listLoadedItem.m_uLength = m_uLength + 1;
      if ( v16 )
        *v16 = PtrAndAddRef;
    }
  }
  CAkBankReader::ReleaseData(&this->m_BankReader);
  return v8;
}

// File Line: 432
// RVA: 0xA5BCA0
__int64 __fastcall CAkBankMgr::ReadSourceParent<CAkFeedbackNode>(
        CAkBankMgr *this,
        AkBank::AKBKSubHircSection *in_rSection,
        CAkUsageSlot *in_pUsageSlot,
        unsigned int __formal)
{
  unsigned int *Data; // rax
  char *v8; // rdi
  unsigned int v10; // ebp
  CAkFeedbackNode *NodePtrAndAddRef; // rbx
  AKRESULT v12; // edi
  CAkFeedbackNode *v13; // rax
  __int64 m_uLength; // rdx
  CAkIndexable **v15; // r8

  Data = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = (char *)Data;
  if ( !Data )
    return 2i64;
  v10 = *Data;
  NodePtrAndAddRef = (CAkFeedbackNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *Data, AkNodeType_Default);
  if ( NodePtrAndAddRef )
  {
    EnterCriticalSection(&g_csMain.m_csLock);
    v12 = CAkFeedbackNode::SetInitialValues(NodePtrAndAddRef, v8, in_rSection->dwSectionSize, in_pUsageSlot, 1);
    LeaveCriticalSection(&g_csMain.m_csLock);
    if ( v12 == AK_Success )
      goto LABEL_12;
    NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
  }
  else
  {
    EnterCriticalSection(&g_csMain.m_csLock);
    v13 = CAkFeedbackNode::Create(v10);
    NodePtrAndAddRef = v13;
    if ( v13 )
    {
      v12 = CAkFeedbackNode::SetInitialValues(v13, v8, in_rSection->dwSectionSize, in_pUsageSlot, 0);
      if ( v12 != AK_Success )
        NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
    }
    else
    {
      v12 = AK_Fail;
    }
    LeaveCriticalSection(&g_csMain.m_csLock);
  }
  if ( v12 == AK_Success )
  {
LABEL_12:
    m_uLength = in_pUsageSlot->m_listLoadedItem.m_uLength;
    if ( (unsigned int)m_uLength < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
    {
      v15 = &in_pUsageSlot->m_listLoadedItem.m_pItems[m_uLength];
      in_pUsageSlot->m_listLoadedItem.m_uLength = m_uLength + 1;
      if ( v15 )
        *v15 = NodePtrAndAddRef;
    }
  }
  CAkBankReader::ReleaseData(&this->m_BankReader);
  return (unsigned int)v12;
}

