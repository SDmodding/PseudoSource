// File Line: 33
// RVA: 0x1332910
void __fastcall OSuitePrivate::ZPlayerConsumableData::ZPlayerConsumableData(
        OSuitePrivate::ZPlayerConsumableData *this,
        OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuite::ZString *p_m_prefixedUserId; // rcx
  OSuite::ZObject *v5; // rdx
  OSuite::ZConsumableInfoBase **v6; // rax
  OSuite::ZObject *v7; // rdx
  OSuitePrivate::ZPlayerConsumableData::ZRequest **v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-28h] BYREF

  this->m_pPlayerProfile = pPlayerAccount;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ZPlayerConsumableData::`vftable;
  p_m_prefixedUserId = &this->m_prefixedUserId;
  LOBYTE(p_m_prefixedUserId[-1].OSuite::IHashable::vfptr) = 0;
  OSuite::ZString::ZString(p_m_prefixedUserId);
  this->m_pConsumablesData = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_ownedConsumables, v5);
  this->m_ownedConsumables.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_ownedConsumables.m_pList = 0i64;
  this->m_ownedConsumables.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v6 = (OSuite::ZConsumableInfoBase **)OSuite::ZObject::malloc(&this->m_ownedConsumables, 0x80ui64, 0i64);
  this->m_ownedConsumables.m_nSize = 16i64;
  this->m_ownedConsumables.m_nTop = 0i64;
  this->m_ownedConsumables.m_pList = v6;
  this->m_bRequestInProgress = 0;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_pendingRequests, v7);
  this->m_pendingRequests.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_pendingRequests.m_pList = 0i64;
  this->m_pendingRequests.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v8 = (OSuitePrivate::ZPlayerConsumableData::ZRequest **)OSuite::ZObject::malloc(
                                                            &this->m_pendingRequests,
                                                            0x80ui64,
                                                            0i64);
  this->m_pendingRequests.m_nSize = 16i64;
  this->m_pendingRequests.m_nTop = 0i64;
  this->m_pendingRequests.m_pList = v8;
  this->m_pTxnFeed = 0i64;
  this->m_pTxnEntry = 0i64;
  this->m_pTransferEntry = 0i64;
  this->m_bQueryTxn = 0;
  this->m_completedTxnId = -1i64;
  this->m_transferTxnId = -1i64;
  this->m_eTxnCreation = OS_CONSUMABLES_OK;
  this->m_pTransaction = 0i64;
  if ( pPlayerAccount )
  {
    v9 = pPlayerAccount->vfptr->GetUserId(pPlayerAccount, 0i64);
    v10 = OSuite::operator+(&result, &customCaption, v9);
    OSuite::ZString::operator=(&this->m_prefixedUserId, v10);
    OSuite::ZString::~ZString(&result);
  }
}

// File Line: 41
// RVA: 0x1332A74
void __fastcall OSuitePrivate::ZPlayerConsumableData::~ZPlayerConsumableData(
        OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZPlayerConsumableData::ZRequest **m_pList; // rdx
  OSuite::ZConsumableInfoBase **v3; // rdx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ZPlayerConsumableData::`vftable;
  OSuitePrivate::ZPlayerConsumableData::TermData(this);
  m_pList = this->m_pendingRequests.m_pList;
  this->m_pendingRequests.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_pendingRequests.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_pendingRequests, m_pList);
  v3 = this->m_ownedConsumables.m_pList;
  this->m_ownedConsumables.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_ownedConsumables.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_ownedConsumables, v3);
  OSuite::ZString::~ZString(&this->m_prefixedUserId);
}

// File Line: 49
// RVA: 0x1332EBC
unsigned __int64 __fastcall OSuitePrivate::ZPlayerConsumableData::GetCount(OSuitePrivate::ZPlayerConsumableData *this)
{
  return OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_ownedConsumables);
}

// File Line: 60
// RVA: 0x1332EC8
OSuite::ConsumableError __fastcall OSuitePrivate::ZPlayerConsumableData::GetInfo(
        OSuitePrivate::ZPlayerConsumableData *this,
        const char *consumableId,
        OSuite::IConsumableInfo **ppInfo)
{
  OSuite::ConsumableError result; // eax
  __int64 v5; // rax
  __int64 v6; // rsi
  OSuite::ZConsumableInfoBase *v7; // rbx
  unsigned int v8; // edi
  OSuite::ZString *v9; // rax
  OSuite::ZConsumableInfoBase *v10; // [rsp+48h] [rbp+20h] BYREF

  v10 = 0i64;
  result = OSuitePrivate::ZPlayerConsumableData::InternalFind(this, consumableId, &v10);
  if ( result == OS_CONSUMABLES_OK )
  {
    v5 = OSuite::ZObject::operator new(0x30ui64);
    v6 = v5;
    if ( v5 )
    {
      v7 = v10;
      *(_QWORD *)(v5 + 32) = 0i64;
      v8 = v7->OSuite::IConsumableInfo::vfptr->GetQuantity(v7);
      v9 = (OSuite::ZString *)v7->OSuite::IConsumableInfo::vfptr->GetId(v7);
      *(_QWORD *)v6 = &OSuite::ZConsumableInfoBase::`vftable{for `OSuite::IConsumableInfo};
      *(_QWORD *)(v6 + 8) = &OSuite::ZConsumableInfoBase::`vftable{for `OSuite::ZObject};
      OSuite::ZString::ZString((OSuite::ZString *)(v6 + 16), v9);
      *(_DWORD *)(v6 + 40) = v8;
    }
    else
    {
      v6 = 0i64;
    }
    if ( v6 )
    {
      *ppInfo = (OSuite::IConsumableInfo *)v6;
      return 0;
    }
    else
    {
      return -2147483644;
    }
  }
  return result;
}

// File Line: 88
// RVA: 0x1332F70
__int64 __fastcall OSuitePrivate::ZPlayerConsumableData::GetNextInfo(
        OSuitePrivate::ZPlayerConsumableData *this,
        unsigned int consumableIndex,
        OSuite::IConsumableInfo **ppInfo)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_ownedConsumables; // rbx
  __int64 v5; // rdi
  unsigned int v6; // esi
  __int64 v7; // rax
  __int64 v8; // r14
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v11; // r12
  OSuite::ZRedBlackTreeBase::ZElementBase *v12; // rbx
  int v13; // edi
  OSuite::ZString *v14; // rax

  p_m_ownedConsumables = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_ownedConsumables;
  v5 = consumableIndex;
  v6 = consumableIndex >= (unsigned int)OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_ownedConsumables)
     ? 0x80000104
     : 0;
  if ( !v6 )
  {
    v7 = OSuite::ZObject::operator new(0x30ui64);
    v6 = 0;
    v8 = v7;
    if ( v7 )
    {
      v9 = (unsigned int)v5;
      v10 = v5 + 1;
      *(_QWORD *)(v7 + 32) = 0i64;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_ownedConsumables, v10);
      if ( v9 >= p_m_ownedConsumables->m_nTop )
        p_m_ownedConsumables->m_nTop = v10;
      v11 = p_m_ownedConsumables->m_pList[v9];
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_ownedConsumables, v10);
      if ( v9 >= p_m_ownedConsumables->m_nTop )
        p_m_ownedConsumables->m_nTop = v10;
      v12 = p_m_ownedConsumables->m_pList[v9];
      v13 = ((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))v11->vfptr[1].__vecDelDtor)(v11);
      v14 = (OSuite::ZString *)((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))v12->vfptr->__vecDelDtor)(v12);
      *(_QWORD *)v8 = &OSuite::ZConsumableInfoBase::`vftable{for `OSuite::IConsumableInfo};
      *(_QWORD *)(v8 + 8) = &OSuite::ZConsumableInfoBase::`vftable{for `OSuite::ZObject};
      OSuite::ZString::ZString((OSuite::ZString *)(v8 + 16), v14);
      *(_DWORD *)(v8 + 40) = v13;
    }
    else
    {
      v8 = 0i64;
    }
    if ( v8 )
      *ppInfo = (OSuite::IConsumableInfo *)v8;
    else
      return (unsigned int)-2147483644;
  }
  return v6;
}

// File Line: 113
// RVA: 0x1332D24
OSuite::ConsumableError __fastcall OSuitePrivate::ZPlayerConsumableData::Consume(
        OSuitePrivate::ZPlayerConsumableData *this,
        OSuite::IConsumableInfo *pConsume)
{
  OSuite::ZString *v4; // rax
  char *v5; // rax
  OSuite::ConsumableError result; // eax
  OSuite::ZConsumableInfoBase *v7; // rdi
  unsigned int v8; // ebx
  unsigned int v9; // ebx
  __int64 v10; // rax
  __int64 v11; // rdi
  unsigned int v12; // ebx
  OSuite::ZString *v13; // rax
  OSuite::ZConsumableInfoBase *ppInfo; // [rsp+38h] [rbp+10h] BYREF

  ppInfo = 0i64;
  v4 = (OSuite::ZString *)pConsume->vfptr->GetId(pConsume);
  v5 = OSuite::ZString::c_str(v4);
  result = OSuitePrivate::ZPlayerConsumableData::InternalFind(this, v5, &ppInfo);
  if ( result == OS_CONSUMABLES_OK )
  {
    v7 = ppInfo;
    v8 = ppInfo->OSuite::IConsumableInfo::vfptr->GetQuantity(ppInfo);
    if ( pConsume->vfptr->GetQuantity(pConsume) > v8 )
    {
      return -2147483389;
    }
    else
    {
      v9 = v7->OSuite::IConsumableInfo::vfptr->GetQuantity(v7);
      v7->m_uiQuantity = v9
                       - ((__int64 (__fastcall *)(OSuite::IConsumableInfo *))pConsume->vfptr->GetQuantity)(pConsume);
      v10 = OSuite::ZObject::operator new(0x38ui64);
      v11 = v10;
      if ( v10 )
      {
        *(_QWORD *)(v10 + 24) = 0i64;
        v12 = pConsume->vfptr->GetQuantity(pConsume);
        v13 = (OSuite::ZString *)pConsume->vfptr->GetId(pConsume);
        *(_QWORD *)v11 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
        OSuite::ZString::ZString((OSuite::ZString *)(v11 + 8), v13);
        *(_DWORD *)(v11 + 32) = v12;
        *(_QWORD *)(v11 + 40) = -1i64;
        *(_WORD *)(v11 + 36) = 0;
        *(_QWORD *)(v11 + 48) = 0xFFFFFFFFi64;
      }
      else
      {
        v11 = 0i64;
      }
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_pendingRequests,
        this->m_pendingRequests.m_nTop + 1);
      this->m_pendingRequests.m_pList[this->m_pendingRequests.m_nTop++] = (OSuitePrivate::ZPlayerConsumableData::ZRequest *)v11;
      return 0;
    }
  }
  return result;
}

// File Line: 144
// RVA: 0x1332B10
__int64 __fastcall OSuitePrivate::ZPlayerConsumableData::Acquire(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZEidosTransaction *m_pTransaction; // rcx
  __int64 v3; // rax
  __int64 v4; // r12
  OSuitePrivate::ZEidosTransaction *v6; // rbp
  unsigned __int64 i; // r13
  __int64 v8; // rax
  __int64 v9; // r14
  OSuite::ZConsumableInfoBase *v10; // rbx
  unsigned int v11; // edi
  OSuite::ZString *v12; // rax

  m_pTransaction = this->m_pTransaction;
  if ( !m_pTransaction )
    return 2147484163i64;
  v3 = m_pTransaction->vfptr->GetId(m_pTransaction);
  v4 = v3;
  if ( v3 == this->m_transferTxnId )
    return 2i64;
  if ( v3 < 0 )
    return 2147484163i64;
  v6 = this->m_pTransaction;
  for ( i = 0i64; i < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v6->m_Infos); ++i )
  {
    this->m_transferTxnId = v4;
    v8 = OSuite::ZObject::operator new(0x38ui64);
    v9 = v8;
    if ( v8 )
    {
      *(_QWORD *)(v8 + 24) = 0i64;
      v10 = v6->m_Infos.m_pList[i];
      v11 = v10->OSuite::IConsumableInfo::vfptr->GetQuantity(v10);
      v12 = (OSuite::ZString *)v10->OSuite::IConsumableInfo::vfptr->GetId(v10);
      *(_QWORD *)v9 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
      OSuite::ZString::ZString((OSuite::ZString *)(v9 + 8), v12);
      *(_DWORD *)(v9 + 32) = v11;
      *(_WORD *)(v9 + 36) = 0;
      *(_QWORD *)(v9 + 40) = v4;
      *(_DWORD *)(v9 + 48) = -1;
      *(_DWORD *)(v9 + 52) = 0;
    }
    else
    {
      v9 = 0i64;
    }
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_pendingRequests,
      this->m_pendingRequests.m_nTop + 1);
    this->m_pendingRequests.m_pList[this->m_pendingRequests.m_nTop++] = (OSuitePrivate::ZPlayerConsumableData::ZRequest *)v9;
  }
  return 0i64;
}

// File Line: 174
// RVA: 0x1333138
__int64 __fastcall OSuitePrivate::ZPlayerConsumableData::NewTransaction(
        OSuitePrivate::ZPlayerConsumableData *this,
        OSuite::ZRedBlackTreeBase *infos,
        const char *tag)
{
  __int64 m_eTxnCreation; // rax
  __int64 v7; // rsi
  OSuite::IConsumableInfo *v8; // rcx
  OSuitePrivate::ZEidosConsumables *v9; // rax
  OSuite::ZOEntry *Entry; // rax
  OSuite::ZOProperty *v11; // rax
  OSuite::ZOProperty *v12; // rax
  unsigned int v13; // r14d
  __int64 v14; // rsi
  OSuite::IConsumableInfo *v15; // rcx
  OSuite::ZString *v16; // rax
  OSuite::ZString *v17; // rax
  char *v18; // rax
  OSuite::ZOProperty *v19; // r12
  OSuite::IConsumableInfo *v20; // rcx
  unsigned int v21; // eax
  OSuite::ZOProperty *v22; // rdi
  OSuite::ZDateTime *v23; // rax
  OSuite::ZOProperty *v24; // rax
  const char *v25; // rdx
  OSuite::ZOEntry *m_pTxnEntry; // rcx
  OSuite::ZString result; // [rsp+20h] [rbp-50h] BYREF
  OSuite::ZStringBuilder v28; // [rsp+38h] [rbp-38h] BYREF

  if ( this->m_pTransaction )
    return 2147484161i64;
  if ( this->m_pTxnEntry )
    return 2i64;
  m_eTxnCreation = (unsigned int)this->m_eTxnCreation;
  if ( !(_DWORD)m_eTxnCreation )
  {
    if ( !OSuite::ZHttpStreamReader::Tell(infos) )
      return 2147483650i64;
    v7 = 0i64;
    if ( OSuite::ZHttpStreamReader::Tell(infos) )
    {
      do
      {
        v8 = (OSuite::IConsumableInfo *)(&infos[1].m_pTop->vfptr)[v7];
        if ( !v8->vfptr->GetQuantity(v8) )
          return 2147483650i64;
      }
      while ( ++v7 < OSuite::ZHttpStreamReader::Tell(infos) );
    }
    this->m_eTxnCreation = OS_CONSUMABLES_CREATINGDATA;
    v9 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    Entry = OSuite::ZWebServiceClient::CreateEntry(v9->m_pWebServiceClient, "transactions");
    this->m_pTxnEntry = Entry;
    if ( Entry )
    {
      v11 = OSuite::ZOEntry::AddProperty(Entry, "s_userId");
      if ( v11 )
        OSuite::ZOProperty::SetValue(v11, &this->m_prefixedUserId);
      v12 = OSuite::ZOEntry::AddProperty(this->m_pTxnEntry, "i32_txnState");
      if ( v12 )
        OSuite::ZOProperty::SetValue(v12, 0);
      v28.m_Chars.m_pList = 0i64;
      OSuite::ZStringBuilder::ZStringBuilder(&v28, (OSuite::ZObject *)0x80);
      v13 = 0;
      if ( OSuite::ZHttpStreamReader::Tell(infos) )
      {
        v14 = 0i64;
        do
        {
          OSuite::ZStringBuilder::Clear(&v28, 0x20ui64);
          OSuite::ZStringBuilder::Append(&v28, "i32_C");
          v15 = (OSuite::IConsumableInfo *)(&infos[1].m_pTop->vfptr)[v14];
          v16 = (OSuite::ZString *)v15->vfptr->GetId(v15);
          OSuite::ZStringBuilder::Append(&v28, v16);
          OSuite::ZStringBuilder::Append(&v28, 95);
          OSuite::ZStringBuilder::AppendInt(&v28, v13);
          v17 = OSuite::ZStringBuilder::ToString(&v28, &result);
          v18 = OSuite::ZString::c_str(v17);
          v19 = OSuite::ZOEntry::AddProperty(this->m_pTxnEntry, v18);
          OSuite::ZString::~ZString(&result);
          if ( v19 )
          {
            v20 = (OSuite::IConsumableInfo *)(&infos[1].m_pTop->vfptr)[v14];
            v21 = v20->vfptr->GetQuantity(v20);
            OSuite::ZOProperty::SetValue(v19, v21);
          }
          v14 = ++v13;
        }
        while ( v13 < OSuite::ZHttpStreamReader::Tell(infos) );
      }
      v22 = OSuite::ZOEntry::AddProperty(this->m_pTxnEntry, "d_Created");
      if ( v22 )
      {
        v23 = OSuite::ZDateTime::CurrentDateTime((OSuite::ZDateTime *)&result);
        OSuite::ZOProperty::SetValue(v22, v23);
        OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&result);
      }
      v24 = OSuite::ZOEntry::AddProperty(this->m_pTxnEntry, "s_tag");
      if ( v24 )
      {
        v25 = &customCaption;
        if ( tag )
          v25 = tag;
        OSuite::ZOProperty::SetValue(v24, v25);
      }
      m_pTxnEntry = this->m_pTxnEntry;
      result.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)OSuitePrivate::ZPlayerConsumableData::NewTxnCB;
      result.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)this;
      OSuite::ZAtomEntry::PostTo(
        m_pTxnEntry,
        (OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *)&result,
        0i64);
      OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v28);
      return 0i64;
    }
    else
    {
      this->m_eTxnCreation = OS_CONSUMABLES_OK;
      return 2147484165i64;
    }
  }
  return m_eTxnCreation;
}

// File Line: 261
// RVA: 0x1332E74
__int64 __fastcall OSuitePrivate::ZPlayerConsumableData::GetActiveTransaction(
        OSuitePrivate::ZPlayerConsumableData *this,
        OSuitePrivate::ZEidosTransaction **ppTransaction)
{
  OSuitePrivate::ZEidosTransaction *m_pTransaction; // rax

  if ( this->m_eTxnCreation || !this->m_pTxnFeed )
    return 2i64;
  m_pTransaction = this->m_pTransaction;
  if ( !m_pTransaction )
    return 2147484164i64;
  if ( ppTransaction )
    *ppTransaction = m_pTransaction;
  return this->m_pTransaction->m_bClose ? 6 : 0;
}

// File Line: 282
// RVA: 0x1332D08
__int64 __fastcall OSuitePrivate::ZPlayerConsumableData::CloseActiveTransaction(
        OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZEidosTransaction *m_pTransaction; // rax

  m_pTransaction = this->m_pTransaction;
  if ( !m_pTransaction )
    return 2147484164i64;
  m_pTransaction->m_bClose = 1;
  return 0i64;
}

// File Line: 298
// RVA: 0x133307C
__int64 __fastcall OSuitePrivate::ZPlayerConsumableData::InternalFind(
        OSuitePrivate::ZPlayerConsumableData *this,
        const char *id,
        OSuite::ZConsumableInfoBase **ppInfo)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_ownedConsumables; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v8; // rcx
  OSuite::ZString *v9; // rax
  __int64 result; // rax

  p_m_ownedConsumables = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_ownedConsumables;
  v6 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_ownedConsumables) )
    return 2147483908i64;
  while ( 1 )
  {
    v7 = v6 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_ownedConsumables, v6 + 1);
    if ( v6 >= p_m_ownedConsumables->m_nTop )
      p_m_ownedConsumables->m_nTop = v7;
    v8 = p_m_ownedConsumables->m_pList[v6];
    v9 = (OSuite::ZString *)((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))v8->vfptr->__vecDelDtor)(v8);
    if ( OSuite::ZString::operator==(v9, id) )
      break;
    ++v6;
    if ( v7 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_ownedConsumables) )
      return 2147483908i64;
  }
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_ownedConsumables, v6 + 1);
  if ( v6 >= p_m_ownedConsumables->m_nTop )
    p_m_ownedConsumables->m_nTop = v6 + 1;
  result = 0i64;
  *ppInfo = (OSuite::ZConsumableInfoBase *)p_m_ownedConsumables->m_pList[v6];
  return result;
}

// File Line: 323
// RVA: 0x1333400
void __fastcall OSuitePrivate::ZPlayerConsumableData::ProcessRequests(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuite::ZObject *v2; // rdx
  void *v3; // rax
  __int64 transactionId; // rsi
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r15
  OSuitePrivate::ZPlayerConsumableData::ZRequest *v7; // rdi
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  const char *v11; // rdx
  OSuitePrivate::ZEidosConsumables *v12; // rax
  OSuite::ZString key; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZString result; // [rsp+38h] [rbp-C8h] BYREF
  OSuite::ZObject v15; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v16; // [rsp+58h] [rbp-A8h]
  __int64 v17; // [rsp+60h] [rbp-A0h]
  void **v18; // [rsp+68h] [rbp-98h]
  void *ptr; // [rsp+70h] [rbp-90h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+78h] [rbp-88h] BYREF
  OSuite::ZStringBuilder v21; // [rsp+98h] [rbp-68h] BYREF
  OSuite::ZStringBuilder v22; // [rsp+C8h] [rbp-38h] BYREF
  OSuite::ZOQuery query; // [rsp+100h] [rbp+0h] BYREF

  OSuitePrivate::ZPlayerConsumableData::RemoveCompletedRequests(this);
  if ( this->m_bRequestInProgress )
    return;
  ptr = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v15, v2);
  v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v18 = &OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  ptr = 0i64;
  v3 = (void *)OSuite::ZObject::malloc(&v15, 0x80ui64, 0i64);
  v16 = 16i64;
  v17 = 0i64;
  ptr = v3;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingRequests) )
    goto LABEL_23;
  v21.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v21, (OSuite::ZObject *)0x100);
  v22.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v22, (OSuite::ZObject *)0x100);
  transactionId = -2i64;
  v5 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingRequests) )
    goto LABEL_22;
  do
  {
    v6 = v5 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_pendingRequests,
      v5 + 1);
    if ( v5 >= this->m_pendingRequests.m_nTop )
      this->m_pendingRequests.m_nTop = v6;
    v7 = this->m_pendingRequests.m_pList[v5];
    if ( !v7->Sent )
    {
      if ( transactionId == -2 )
      {
        transactionId = v7->transactionId;
        OSuite::ZStringBuilder::Append(&v21, "i32_C");
        OSuite::ZStringBuilder::Append(&v21, &v7->Id);
      }
      else
      {
        if ( transactionId != v7->transactionId )
          goto LABEL_12;
        OSuite::ZStringBuilder::Append(&v21, 44);
        OSuite::ZStringBuilder::Append(&v21, "i32_C");
        OSuite::ZStringBuilder::Append(&v21, &v7->Id);
        OSuite::ZStringBuilder::Append(&v22, 44);
      }
      OSuite::ZStringBuilder::AppendInt(&v22, v7->Quantity);
      v7->Sent = 1;
    }
LABEL_12:
    v5 = v6;
  }
  while ( v6 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingRequests) );
  if ( transactionId != -2 )
  {
    params.m_pLists = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
    OSuite::ZString::ZString(&key, "playerId");
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(&params, &key, &this->m_prefixedUserId);
    OSuite::ZString::~ZString(&key);
    OSuite::ZString::ZString(&key, "consumables");
    v8 = OSuite::ZStringBuilder::ToString(&v21, &result);
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(&params, &key, v8);
    OSuite::ZString::~ZString(&result);
    OSuite::ZString::~ZString(&key);
    OSuite::ZString::ZString(&key, "deltas");
    v9 = OSuite::ZStringBuilder::ToString(&v22, &result);
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(&params, &key, v9);
    OSuite::ZString::~ZString(&result);
    OSuite::ZString::~ZString(&key);
    if ( transactionId >= 0 )
    {
      OSuite::ZString::ZString(&key, "transactionId");
      OSuite::ZString::ZString(&result, transactionId);
      OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(&params, &key, v10);
      OSuite::ZString::~ZString(&result);
      OSuite::ZString::~ZString(&key);
    }
    query.m_entityName.m_pString = 0i64;
    query.m_queryMap.m_pLists = 0i64;
    query.m_functionParameters.m_pLists = 0i64;
    OSuite::ZOQuery::ZOQuery(&query);
    v11 = "DecreaseConsumables";
    if ( transactionId != -1 )
      v11 = "IncreaseConsumables";
    OSuite::ZOQuery::ServiceOperation(
      &query,
      v11,
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&params);
    key.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)this;
    key.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)OSuitePrivate::ZPlayerConsumableData::RequestCB;
    v12 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    OSuite::ZWebServiceClient::ExecuteQuery(
      v12->m_pWebServiceClient,
      &query,
      (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *)&key);
    this->m_bRequestInProgress = 1;
    OSuite::ZOQuery::~ZOQuery(&query);
    params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
    if ( params.m_pLists )
    {
      if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
        params.m_pLists->vfptr->__vecDelDtor(params.m_pLists, 3u);
      else
        Illusion::ShaderParam::operator delete(&params.m_pLists[-1].m_Comparer.OSuite::ZObject);
    }
  }
LABEL_22:
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v22);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v21);
LABEL_23:
  v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v18 = &OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&v15, ptr);
}

// File Line: 391
// RVA: 0x13337B0
void __fastcall OSuitePrivate::ZPlayerConsumableData::RemoveCompletedRequests(
        OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_pendingRequests; // rbx
  unsigned __int64 v2; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rcx

  p_m_pendingRequests = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_pendingRequests;
  v2 = 0i64;
  while ( v2 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_pendingRequests) )
  {
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_pendingRequests, v2 + 1);
    if ( v2 >= p_m_pendingRequests->m_nTop )
      p_m_pendingRequests->m_nTop = v2 + 1;
    v3 = p_m_pendingRequests->m_pList[v2];
    if ( BYTE5(v3[1].vfptr) )
    {
      v3->vfptr->__vecDelDtor(v3, 1u);
      p_m_pendingRequests->OSuite::ZListBase::OSuite::ZObject::vfptr[1].__vecDelDtor(p_m_pendingRequests, v2);
    }
    else
    {
      ++v2;
    }
  }
}

// File Line: 420
// RVA: 0x1333074
void __fastcall OSuitePrivate::ZPlayerConsumableData::InitData(OSuitePrivate::ZPlayerConsumableData *this)
{
  this->m_bRefresh = 0;
}

// File Line: 429
// RVA: 0x1333C00
void __fastcall OSuitePrivate::ZPlayerConsumableData::UpdateData(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuite::ConsumableError m_eTxnCreation; // eax
  OSuitePrivate::ZEidosConsumables *v3; // rax
  OSuitePrivate::ZEidosConsumables *v4; // rax
  OSuitePrivate::ZEidosConsumables *v5; // rax

  OSuitePrivate::ZPlayerConsumableData::UpdateConsumableData(this);
  m_eTxnCreation = this->m_eTxnCreation;
  if ( m_eTxnCreation != OS_CONSUMABLES_DATACREATED || this->m_bQueryTxn )
  {
    if ( m_eTxnCreation == OS_CONSUMABLES_TRANSACTION_CREATION_FAILED )
    {
      v5 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
      OSuite::ZWebServiceClient::ReleaseEntry(v5->m_pWebServiceClient, this->m_pTxnEntry);
      this->m_pTxnEntry = 0i64;
      this->m_eTxnCreation = OS_CONSUMABLES_OK;
    }
  }
  else
  {
    v3 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    OSuite::ZWebServiceClient::ReleaseEntry(v3->m_pWebServiceClient, this->m_pTxnEntry);
    this->m_pTxnEntry = 0i64;
    if ( this->m_pTxnFeed )
    {
      v4 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
      OSuite::ZWebServiceClient::CloseRequest(v4->m_pWebServiceClient, this->m_pTxnFeed);
      this->m_pTxnFeed = 0i64;
    }
    this->m_eTxnCreation = OS_CONSUMABLES_PROCESSING;
  }
  OSuitePrivate::ZPlayerConsumableData::UpdateTransactionFeed(this);
  OSuitePrivate::ZPlayerConsumableData::UpdateTransaction(this);
}

// File Line: 463
// RVA: 0x13338E0
void __fastcall OSuitePrivate::ZPlayerConsumableData::TermData(OSuitePrivate::ZPlayerConsumableData *this)
{
  unsigned __int64 v2; // rsi
  unsigned __int64 v3; // rbp
  OSuitePrivate::ZPlayerConsumableData::ZRequest *v4; // rcx
  OSuitePrivate::ZPlayerConsumableData::ZRequest **v5; // rax
  OSuitePrivate::ZEidosTransaction *m_pTransaction; // rcx
  OSuitePrivate::ZEidosConsumables *v7; // rax
  OSuitePrivate::ZEidosConsumables *v8; // rax

  OSuitePrivate::ZPlayerConsumableData::CleanData(this);
  v2 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingRequests) )
  {
    do
    {
      v3 = v2 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_pendingRequests,
        v2 + 1);
      if ( v2 >= this->m_pendingRequests.m_nTop )
        this->m_pendingRequests.m_nTop = v3;
      v4 = this->m_pendingRequests.m_pList[v2];
      if ( v4 )
        v4->vfptr->__vecDelDtor(v4, 1u);
      ++v2;
    }
    while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingRequests) );
  }
  OSuite::ZObject::free(&this->m_pendingRequests, this->m_pendingRequests.m_pList);
  v5 = (OSuitePrivate::ZPlayerConsumableData::ZRequest **)OSuite::ZObject::malloc(
                                                            &this->m_pendingRequests,
                                                            0x80ui64,
                                                            0i64);
  this->m_pendingRequests.m_nTop = 0i64;
  this->m_pendingRequests.m_nSize = 16i64;
  this->m_pendingRequests.m_pList = v5;
  m_pTransaction = this->m_pTransaction;
  if ( m_pTransaction )
  {
    ((void (__fastcall *)(OSuitePrivate::ZEidosTransaction *, __int64))m_pTransaction->vfptr->~IConsumableTransaction)(
      m_pTransaction,
      1i64);
    this->m_pTransaction = 0i64;
  }
  if ( this->m_pTxnEntry )
  {
    v7 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    OSuite::ZWebServiceClient::ReleaseEntry(v7->m_pWebServiceClient, this->m_pTxnEntry);
    this->m_pTxnEntry = 0i64;
  }
  if ( this->m_pTxnFeed )
  {
    v8 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    OSuite::ZWebServiceClient::CloseRequest(v8->m_pWebServiceClient, this->m_pTxnFeed);
    this->m_pTxnFeed = 0i64;
  }
}

// File Line: 492
// RVA: 0x1332C4C
void __fastcall OSuitePrivate::ZPlayerConsumableData::CleanData(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_ownedConsumables; // rbx
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rcx
  __int64 v5; // rax

  p_m_ownedConsumables = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_ownedConsumables;
  v2 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_ownedConsumables) )
  {
    do
    {
      v3 = v2 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_ownedConsumables, v2 + 1);
      if ( v2 >= p_m_ownedConsumables->m_nTop )
        p_m_ownedConsumables->m_nTop = v3;
      v4 = p_m_ownedConsumables->m_pList[v2];
      if ( v4 )
        v4->vfptr[3].__vecDelDtor(v4, 1u);
      ++v2;
    }
    while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_ownedConsumables) );
  }
  OSuite::ZObject::free(p_m_ownedConsumables, p_m_ownedConsumables->m_pList);
  v5 = OSuite::ZObject::malloc(p_m_ownedConsumables, 0x80ui64, 0i64);
  p_m_ownedConsumables->m_nTop = 0i64;
  p_m_ownedConsumables->m_pList = (OSuite::ZRedBlackTreeBase::ZElementBase **)v5;
  p_m_ownedConsumables->m_nSize = 16i64;
}

// File Line: 501
// RVA: 0x1333A00
void __fastcall OSuitePrivate::ZPlayerConsumableData::UpdateConsumableData(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuite::ZOEntry *m_pConsumablesData; // rcx
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v5; // r14
  OSuite::ZOProperty *v6; // rbx
  unsigned __int64 v7; // rax
  __int64 v8; // rax
  OSuite::ZConsumableInfoBase *v9; // rsi
  int v10; // ebx
  OSuite::ZOEntry *v11; // rax
  int outValue; // [rsp+20h] [rbp-60h] BYREF
  OSuite::TList<OSuite::ZOProperty *>::ZIterator result; // [rsp+28h] [rbp-58h] BYREF
  OSuite::ZString sStr; // [rsp+40h] [rbp-40h] BYREF
  OSuite::ZString that; // [rsp+58h] [rbp-28h] BYREF

  if ( this->m_pConsumablesData )
  {
    OSuitePrivate::ZPlayerConsumableData::CleanData(this);
    sStr.m_pString = 0i64;
    OSuite::ZString::ZString(&sStr, "i32_C");
    m_pConsumablesData = this->m_pConsumablesData;
    result.m_pListBase = 0i64;
    OSuite::ZOEntry::Properties(m_pConsumablesData, &result);
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&result) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_pListBase);
      m_nIndex = result.m_nIndex;
      m_pListBase = result.m_pListBase;
      v5 = result.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)result.m_pListBase,
        result.m_nIndex + 1);
      if ( m_nIndex >= m_pListBase->m_nTop )
        m_pListBase->m_nTop = v5;
      v6 = *(OSuite::ZOProperty **)(m_pListBase[1].m_nSize + 8 * m_nIndex);
      if ( (unsigned int)OSuite::ZOProperty::Type(v6) == 10 )
      {
        outValue = 0;
        if ( OSuite::ZString::StartsWith(&v6->m_Name, &sStr) && OSuite::ZOProperty::GetValue(v6, &outValue) )
        {
          that.m_pString = 0i64;
          v7 = OSuite::ZString::Count(&sStr);
          OSuite::ZString::Slice(&v6->m_Name, &that, v7);
          v8 = OSuite::ZObject::operator new(0x30ui64);
          v9 = (OSuite::ZConsumableInfoBase *)v8;
          if ( v8 )
          {
            *(_QWORD *)(v8 + 32) = 0i64;
            v10 = outValue;
            *(_QWORD *)v8 = &OSuite::ZConsumableInfoBase::`vftable{for `OSuite::IConsumableInfo};
            *(_QWORD *)(v8 + 8) = &OSuite::ZConsumableInfoBase::`vftable{for `OSuite::ZObject};
            OSuite::ZString::ZString((OSuite::ZString *)(v8 + 16), &that);
            v9->m_uiQuantity = v10;
          }
          else
          {
            v9 = 0i64;
          }
          if ( v9 )
          {
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
              (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_ownedConsumables,
              this->m_ownedConsumables.m_nTop + 1);
            this->m_ownedConsumables.m_pList[this->m_ownedConsumables.m_nTop++] = v9;
          }
          OSuite::ZString::~ZString(&that);
        }
      }
      else if ( (unsigned int)OSuite::ZOProperty::Type(v6) == 11
             && OSuite::ZString::StartsWith(&v6->m_Name, "i64_currentTransaction") )
      {
        OSuite::ZOProperty::GetValue(v6, &this->m_completedTxnId);
        v11 = this->m_pConsumablesData;
        this->m_transferTxnId = -1i64;
        this->m_pTransferEntry = v11;
      }
      OSuite::ZListBase::ZListIteratorBase::Next(&result);
    }
    this->m_pConsumablesData = 0i64;
    OSuite::ZString::~ZString(&sStr);
  }
}

// File Line: 542
// RVA: 0x1333E04
void __fastcall OSuitePrivate::ZPlayerConsumableData::UpdateTransactionFeed(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuite::ZOFeed *m_pTxnFeed; // rcx
  char *v3; // rax
  __int64 m_completedTxnId; // rbx
  OSuite::ZOFilter *v5; // rax
  OSuite::ZOFilter *v6; // rax
  OSuitePrivate::ZEidosConsumables *v7; // rax
  __int64 v8; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *Entry; // rbx
  OSuite::ZOEntry *v10; // rcx
  OSuitePrivate::ZEidosTransaction *v11; // rax
  OSuitePrivate::ZEidosConsumables *v12; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+20h] [rbp-D8h] BYREF
  OSuite::ZOFilter v14; // [rsp+30h] [rbp-C8h] BYREF
  OSuite::ZOFilter filterExpression; // [rsp+68h] [rbp-90h] BYREF
  __int64 v16; // [rsp+B8h] [rbp-40h]
  __int64 v17; // [rsp+C8h] [rbp-30h]
  __int64 v18; // [rsp+E8h] [rbp-10h]

  m_pTxnFeed = this->m_pTxnFeed;
  if ( m_pTxnFeed )
  {
    if ( !this->m_bQueryTxn && !this->m_pTransaction )
    {
      v8 = 0i64;
      if ( OSuite::ZAtomFeed::TotalEntries(m_pTxnFeed) )
      {
        while ( 1 )
        {
          Entry = OSuite::ZAtomFeed::GetEntry(this->m_pTxnFeed, v8);
          v10 = (OSuite::ZOEntry *)((unsigned __int64)Entry & -(__int64)(Entry->vfptr[1].__vecDelDtor(
                                                                           Entry,
                                                                           OSuite::ZOEntry::s_nClassId) != 0));
          if ( v10 )
          {
            v11 = OSuitePrivate::ZEidosTransaction::Create(
                    v10,
                    this->m_pPlayerProfile,
                    this->m_eTxnCreation == OS_CONSUMABLES_PROCESSING);
            this->m_eTxnCreation = OS_CONSUMABLES_OK;
            this->m_pTransaction = v11;
          }
          if ( this->m_pTransaction )
            break;
          if ( ++v8 >= OSuite::ZAtomFeed::TotalEntries(this->m_pTxnFeed) )
            goto LABEL_15;
        }
      }
      else
      {
LABEL_15:
        if ( !this->m_pTransaction && this->m_completedTxnId != -1 )
        {
          v12 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
          OSuite::ZWebServiceClient::CloseRequest(v12->m_pWebServiceClient, this->m_pTxnFeed);
          this->m_pTxnFeed = 0i64;
        }
      }
    }
  }
  else if ( !this->m_bQueryTxn )
  {
    v16 = 0i64;
    v17 = 0i64;
    v18 = 0i64;
    OSuite::ZOQuery::ZOQuery((OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList);
    OSuite::ZOQuery::EntitySet((OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList, "transactions");
    filterExpression.m_queryBuilder.m_Chars.vfptr = 0i64;
    OSuite::ZOFilter::ZOFilter(&filterExpression);
    v3 = OSuite::ZString::c_str(&this->m_prefixedUserId);
    OSuite::ZOFilter::Compare(&filterExpression, "s_userId", v3, EQUAL);
    m_completedTxnId = this->m_completedTxnId;
    OSuite::ZOFilter::ZOFilter(&v14);
    if ( m_completedTxnId < 0 )
      v6 = OSuite::ZOFilter::Compare(v5, "i32_txnState", 5, LESSER);
    else
      v6 = OSuite::ZOFilter::Compare(v5, "_id", m_completedTxnId, EQUAL);
    OSuite::ZOFilter::And(&filterExpression, v6);
    OSuite::ZOFilter::~ZOFilter(&v14);
    OSuite::ZOQuery::Filter((OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList, &filterExpression);
    cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)this;
    cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuitePrivate::ZPlayerConsumableData::FeedFetchedCB;
    v7 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    this->m_bQueryTxn = OSuite::ZWebServiceClient::ExecuteQuery(
                          v7->m_pWebServiceClient,
                          (OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList,
                          &cb);
    OSuite::ZOFilter::~ZOFilter(&filterExpression);
    OSuite::ZOQuery::~ZOQuery((OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList);
  }
}ery::~ZOQuery((OSuite::ZOQue

// File Line: 593
// RVA: 0x1333CB4
void __fastcall OSuitePrivate::ZPlayerConsumableData::UpdateTransaction(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZEidosTransaction *m_pTransaction; // rcx
  int CompletionState; // eax
  __int64 m_completedTxnId; // rdi
  OSuitePrivate::EidosTransactionState v5; // edx
  OSuite::ZObject *v6; // rdx
  OSuite::ZOEntry *m_pTransferEntry; // rcx
  OSuite::ZOEntry *v8; // rcx
  OSuitePrivate::ZEidosTransaction *v9; // rcx
  OSuitePrivate::ZEidosConsumables *v10; // rax
  OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> callback; // [rsp+20h] [rbp-18h] BYREF

  m_pTransaction = this->m_pTransaction;
  if ( m_pTransaction )
  {
    CompletionState = OSuitePrivate::ZEidosTransaction::GetCompletionState(m_pTransaction);
    if ( CompletionState == 4 )
    {
      m_completedTxnId = this->m_completedTxnId;
      if ( m_completedTxnId == this->m_pTransaction->vfptr->GetId(this->m_pTransaction) )
      {
        v5 = TXN_COMPLETED;
LABEL_8:
        OSuitePrivate::ZEidosTransaction::SetCompletionState(this->m_pTransaction, v5);
        return;
      }
      if ( m_completedTxnId == -1 && (int)OSuitePrivate::ZPlayerConsumableData::Acquire(this) < 0 )
      {
        v5 = TXN_ERROR;
        goto LABEL_8;
      }
    }
    else if ( CompletionState >= 5 )
    {
      if ( OSuitePrivate::ZEidosTransaction::LatestState(this->m_pTransaction) )
      {
        if ( !this->m_bRequestInProgress )
        {
          m_pTransferEntry = this->m_pTransferEntry;
          if ( m_pTransferEntry )
          {
            if ( OSuite::ZOEntry::DeleteProperty(m_pTransferEntry, "i64_currentTransaction") )
            {
              v8 = this->m_pTransferEntry;
              callback.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuitePrivate::ZPlayerConsumableData::ClearTxnCB;
              this->m_bRequestInProgress = 1;
              callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)this;
              OSuite::ZAtomEntry::Update(v8, &callback, 0i64);
            }
            else
            {
              this->m_pTransferEntry = 0i64;
            }
            this->m_completedTxnId = -1i64;
          }
          v9 = this->m_pTransaction;
          if ( v9 )
            ((void (__fastcall *)(OSuitePrivate::ZEidosTransaction *, __int64))v9->vfptr->~IConsumableTransaction)(
              v9,
              1i64);
          this->m_pTransaction = 0i64;
          if ( this->m_pTxnFeed )
          {
            v10 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
            OSuite::ZWebServiceClient::CloseRequest(v10->m_pWebServiceClient, this->m_pTxnFeed);
            this->m_pTxnFeed = 0i64;
          }
        }
      }
      else
      {
        OSuitePrivate::ZEidosTransaction::UpdateState(this->m_pTransaction, v6);
      }
    }
  }
}

// File Line: 649
// RVA: 0x1333834
void __fastcall OSuitePrivate::ZPlayerConsumableData::RequestCB(
        OSuitePrivate::ZPlayerConsumableData *this,
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_pendingRequests; // rbx
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rcx

  p_m_pendingRequests = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_pendingRequests;
  v7 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingRequests) )
  {
    do
    {
      v8 = v7 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_pendingRequests, v7 + 1);
      if ( v7 >= p_m_pendingRequests->m_nTop )
        p_m_pendingRequests->m_nTop = v8;
      v9 = p_m_pendingRequests->m_pList[v7];
      if ( BYTE4(v9[1].vfptr) )
      {
        BYTE5(v9[1].vfptr) = 1;
        v9[1].m_pRight = (OSuite::ZRedBlackTreeBase::ZElementBase *)pData->Status;
      }
      ++v7;
    }
    while ( v8 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_pendingRequests) );
  }
  if ( pData->Status.eError == HTTPERROR_OK )
    this->m_pConsumablesData = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(
                                 pWebServiceClient,
                                 &pData->URL);
  this->m_bRequestInProgress = 0;
}

// File Line: 669
// RVA: 0x13333E8
void __fastcall OSuitePrivate::ZPlayerConsumableData::NewTxnCB(
        OSuitePrivate::ZPlayerConsumableData *this,
        OSuite::SCallbackData *pData)
{
  this->m_eTxnCreation = pData->Status.eError != HTTPERROR_OK
                       ? OS_CONSUMABLES_TRANSACTION_CREATION_FAILED
                       : OS_CONSUMABLES_DATACREATED;
}

// File Line: 681
// RVA: 0x1332CEC
void __fastcall OSuitePrivate::ZPlayerConsumableData::ClearTxnCB(
        OSuitePrivate::ZPlayerConsumableData *this,
        OSuite::SCallbackData *pData)
{
  if ( pData->Status.eError == HTTPERROR_OK )
  {
    this->m_completedTxnId = -1i64;
    this->m_pTransferEntry = 0i64;
  }
  this->m_bRequestInProgress = 0;
}

// File Line: 691
// RVA: 0x1332E44
void __fastcall OSuitePrivate::ZPlayerConsumableData::FeedFetchedCB(
        OSuitePrivate::ZPlayerConsumableData *this,
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  if ( pData->Status.eError == HTTPERROR_OK )
    this->m_pTxnFeed = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOFeed>(pWebServiceClient, &pData->URL);
  this->m_bQueryTxn = 0;
}

