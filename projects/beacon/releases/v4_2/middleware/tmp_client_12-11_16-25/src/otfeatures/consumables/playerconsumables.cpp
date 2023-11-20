// File Line: 33
// RVA: 0x1332910
void __fastcall OSuitePrivate::ZPlayerConsumableData::ZPlayerConsumableData(OSuitePrivate::ZPlayerConsumableData *this, OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuitePrivate::ZPlayerConsumableData *v2; // rdi
  OSuite::ZString *v3; // rcx
  OSuite::IPlayerAccount *v4; // rsi
  OSuite::ZObject *v5; // rdx
  __int64 v6; // rax
  OSuite::ZObject *v7; // rdx
  __int64 v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-28h]

  v2 = this;
  this->m_pPlayerProfile = pPlayerAccount;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ZPlayerConsumableData::`vftable';
  v3 = &this->m_prefixedUserId;
  LOBYTE(v3[-1].vfptr) = 0;
  v4 = pPlayerAccount;
  OSuite::ZString::ZString(v3);
  v2->m_pConsumablesData = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v2->m_ownedConsumables.vfptr, v5);
  v2->m_ownedConsumables.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v2->m_ownedConsumables.m_pList = 0i64;
  v2->m_ownedConsumables.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v6 = OSuite::ZObject::malloc((OSuite::ZObject *)&v2->m_ownedConsumables.vfptr, 0x80ui64, 0i64);
  v2->m_ownedConsumables.m_nSize = 16i64;
  v2->m_ownedConsumables.m_nTop = 0i64;
  v2->m_ownedConsumables.m_pList = (OSuite::ZConsumableInfoBase **)v6;
  v2->m_bRequestInProgress = 0;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v2->m_pendingRequests.vfptr, v7);
  v2->m_pendingRequests.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v2->m_pendingRequests.m_pList = 0i64;
  v2->m_pendingRequests.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v8 = OSuite::ZObject::malloc((OSuite::ZObject *)&v2->m_pendingRequests.vfptr, 0x80ui64, 0i64);
  v2->m_pendingRequests.m_nSize = 16i64;
  v2->m_pendingRequests.m_nTop = 0i64;
  v2->m_pendingRequests.m_pList = (OSuitePrivate::ZPlayerConsumableData::ZRequest **)v8;
  v2->m_pTxnFeed = 0i64;
  v2->m_pTxnEntry = 0i64;
  v2->m_pTransferEntry = 0i64;
  v2->m_bQueryTxn = 0;
  v2->m_completedTxnId = -1i64;
  v2->m_transferTxnId = -1i64;
  v2->m_eTxnCreation = 0;
  v2->m_pTransaction = 0i64;
  if ( v4 )
  {
    v9 = v4->vfptr->GetUserId(v4, 0);
    v10 = OSuite::operator+(&result, &customWorldMapCaption, v9);
    OSuite::ZString::operator=(&v2->m_prefixedUserId, v10);
    OSuite::ZString::~ZString(&result);
  }
}

// File Line: 41
// RVA: 0x1332A74
void __fastcall OSuitePrivate::ZPlayerConsumableData::~ZPlayerConsumableData(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZPlayerConsumableData *v1; // rbx
  OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *> *v2; // rcx
  OSuitePrivate::ZPlayerConsumableData::ZRequest **v3; // rdx
  OSuite::TList<OSuite::ZConsumableInfoBase *> *v4; // rcx
  OSuite::ZConsumableInfoBase **v5; // rdx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ZPlayerConsumableData::`vftable';
  OSuitePrivate::ZPlayerConsumableData::TermData(this);
  v2 = &v1->m_pendingRequests;
  v3 = v1->m_pendingRequests.m_pList;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v2->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_pendingRequests.vfptr, v3);
  v4 = &v1->m_ownedConsumables;
  v5 = v1->m_ownedConsumables.m_pList;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v4->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_ownedConsumables.vfptr, v5);
  OSuite::ZString::~ZString(&v1->m_prefixedUserId);
}

// File Line: 49
// RVA: 0x1332EBC
unsigned __int64 __fastcall OSuitePrivate::ZPlayerConsumableData::GetCount(OSuitePrivate::ZPlayerConsumableData *this)
{
  return OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_ownedConsumables);
}

// File Line: 60
// RVA: 0x1332EC8
OSuite::ConsumableError __fastcall OSuitePrivate::ZPlayerConsumableData::GetInfo(OSuitePrivate::ZPlayerConsumableData *this, const char *consumableId, OSuite::IConsumableInfo **ppInfo)
{
  OSuite::IConsumableInfo **v3; // r14
  OSuite::ConsumableError result; // eax
  __int64 v5; // rax
  __int64 v6; // rsi
  __int64 v7; // rbx
  int v8; // edi
  OSuite::ZString *v9; // rax
  __int64 v10; // [rsp+48h] [rbp+20h]

  v10 = 0i64;
  v3 = ppInfo;
  result = OSuitePrivate::ZPlayerConsumableData::InternalFind(this, consumableId, (OSuite::ZConsumableInfoBase **)&v10);
  if ( result == OS_CONSUMABLES_OK )
  {
    v5 = OSuite::ZObject::operator new(0x30ui64);
    v6 = v5;
    if ( v5 )
    {
      v7 = v10;
      *(_QWORD *)(v5 + 32) = 0i64;
      v8 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 8i64))(v7);
      v9 = (OSuite::ZString *)(**(__int64 (__fastcall ***)(__int64))v7)(v7);
      *(_QWORD *)v6 = &OSuite::ZConsumableInfoBase::`vftable'{for `OSuite::IConsumableInfo'};
      *(_QWORD *)(v6 + 8) = &OSuite::ZConsumableInfoBase::`vftable'{for `OSuite::ZObject'};
      OSuite::ZString::ZString((OSuite::ZString *)(v6 + 16), v9);
      *(_DWORD *)(v6 + 40) = v8;
    }
    else
    {
      v6 = 0i64;
    }
    if ( v6 )
    {
      *v3 = (OSuite::IConsumableInfo *)v6;
      result = 0;
    }
    else
    {
      result = -2147483644;
    }
  }
  return result;
}

// File Line: 88
// RVA: 0x1332F70
__int64 __fastcall OSuitePrivate::ZPlayerConsumableData::GetNextInfo(OSuitePrivate::ZPlayerConsumableData *this, unsigned int consumableIndex, OSuite::IConsumableInfo **ppInfo)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rbx
  OSuite::IConsumableInfo **v4; // r15
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

  v3 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_ownedConsumables;
  v4 = ppInfo;
  v5 = consumableIndex;
  v6 = consumableIndex >= (unsigned int)OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_ownedConsumables) ? 0x80000104 : 0;
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
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3, v10);
      if ( v9 >= v3->m_nTop )
        v3->m_nTop = v10;
      v11 = v3->m_pList[v9];
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3, v10);
      if ( v9 >= v3->m_nTop )
        v3->m_nTop = v10;
      v12 = v3->m_pList[v9];
      v13 = ((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))v11->vfptr[1].__vecDelDtor)(v11);
      v14 = (OSuite::ZString *)((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))v12->vfptr->__vecDelDtor)(v12);
      *(_QWORD *)v8 = &OSuite::ZConsumableInfoBase::`vftable'{for `OSuite::IConsumableInfo'};
      *(_QWORD *)(v8 + 8) = &OSuite::ZConsumableInfoBase::`vftable'{for `OSuite::ZObject'};
      OSuite::ZString::ZString((OSuite::ZString *)(v8 + 16), v14);
      *(_DWORD *)(v8 + 40) = v13;
    }
    else
    {
      v8 = 0i64;
    }
    if ( v8 )
      *v4 = (OSuite::IConsumableInfo *)v8;
    else
      v6 = -2147483644;
  }
  return v6;
}

// File Line: 113
// RVA: 0x1332D24
OSuite::ConsumableError __fastcall OSuitePrivate::ZPlayerConsumableData::Consume(OSuitePrivate::ZPlayerConsumableData *this, OSuite::IConsumableInfo *pConsume)
{
  OSuitePrivate::ZPlayerConsumableData *v2; // rbp
  OSuite::IConsumableInfo *v3; // rsi
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
  OSuite::ZConsumableInfoBase *ppInfo; // [rsp+38h] [rbp+10h]

  ppInfo = 0i64;
  v2 = this;
  v3 = pConsume;
  v4 = pConsume->vfptr->GetId(pConsume);
  v5 = OSuite::ZString::c_str(v4);
  result = OSuitePrivate::ZPlayerConsumableData::InternalFind(v2, v5, &ppInfo);
  if ( result == OS_CONSUMABLES_OK )
  {
    v7 = ppInfo;
    v8 = ppInfo->vfptr->GetQuantity((OSuite::IConsumableInfo *)ppInfo);
    if ( v3->vfptr->GetQuantity(v3) > v8 )
    {
      result = -2147483389;
    }
    else
    {
      v9 = v7->vfptr->GetQuantity((OSuite::IConsumableInfo *)&v7->vfptr);
      v7->m_uiQuantity = v9 - (unsigned __int64)v3->vfptr->GetQuantity(v3);
      v10 = OSuite::ZObject::operator new(0x38ui64);
      v11 = v10;
      if ( v10 )
      {
        *(_QWORD *)(v10 + 24) = 0i64;
        v12 = v3->vfptr->GetQuantity(v3);
        v13 = (OSuite::ZString *)v3->vfptr->GetId(v3);
        *(_QWORD *)v11 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
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
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v2->m_pendingRequests,
        v2->m_pendingRequests.m_nTop + 1);
      v2->m_pendingRequests.m_pList[v2->m_pendingRequests.m_nTop++] = (OSuitePrivate::ZPlayerConsumableData::ZRequest *)v11;
      result = 0;
    }
  }
  return result;
}

// File Line: 144
// RVA: 0x1332B10
signed __int64 __fastcall OSuitePrivate::ZPlayerConsumableData::Acquire(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZPlayerConsumableData *v1; // rsi
  OSuitePrivate::ZEidosTransaction *v2; // rcx
  __int64 v3; // rax
  __int64 v4; // r12
  OSuitePrivate::ZEidosTransaction *v6; // rbp
  unsigned __int64 v7; // r13
  __int64 v8; // rax
  __int64 v9; // r14
  OSuite::ZConsumableInfoBase *v10; // rbx
  unsigned int v11; // edi
  OSuite::ZString *v12; // rax

  v1 = this;
  v2 = this->m_pTransaction;
  if ( !v2 )
    return 2147484163i64;
  v3 = ((__int64 (*)(void))v2->vfptr->GetId)();
  v4 = v3;
  if ( v3 == v1->m_transferTxnId )
    return 2i64;
  if ( v3 < 0 )
    return 2147484163i64;
  v6 = v1->m_pTransaction;
  v7 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v6->m_Infos) )
  {
    do
    {
      v1->m_transferTxnId = v4;
      v8 = OSuite::ZObject::operator new(0x38ui64);
      v9 = v8;
      if ( v8 )
      {
        *(_QWORD *)(v8 + 24) = 0i64;
        v10 = v6->m_Infos.m_pList[v7];
        v11 = v10->vfptr->GetQuantity((OSuite::IConsumableInfo *)&v10->vfptr);
        v12 = (OSuite::ZString *)v10->vfptr->GetId((OSuite::IConsumableInfo *)&v10->vfptr);
        *(_QWORD *)v9 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
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
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v1->m_pendingRequests,
        v1->m_pendingRequests.m_nTop + 1);
      v1->m_pendingRequests.m_pList[v1->m_pendingRequests.m_nTop++] = (OSuitePrivate::ZPlayerConsumableData::ZRequest *)v9;
      ++v7;
    }
    while ( v7 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v6->m_Infos) );
  }
  return 0i64;
}

// File Line: 174
// RVA: 0x1333138
signed __int64 __fastcall OSuitePrivate::ZPlayerConsumableData::NewTransaction(OSuitePrivate::ZPlayerConsumableData *this, OSuite::TList<OSuite::IConsumableInfo *> *infos, const char *tag)
{
  const char *v3; // r15
  OSuite::ZRedBlackTreeBase *v4; // rdi
  OSuitePrivate::ZPlayerConsumableData *v5; // rbx
  signed __int64 v6; // rax
  __int64 v7; // rsi
  OSuitePrivate::ZEidosConsumables *v8; // rax
  OSuite::ZOEntry *v9; // rax
  OSuite::ZOProperty *v10; // rax
  OSuite::ZOProperty *v11; // rax
  unsigned int v12; // er14
  __int64 v13; // rsi
  OSuite::ZString *v14; // rax
  OSuite::ZString *v15; // rax
  char *v16; // rax
  OSuite::ZOProperty *v17; // r12
  int v18; // eax
  OSuite::ZOProperty *v19; // rdi
  OSuite::ZDateTime *v20; // rax
  OSuite::ZOProperty *v21; // rax
  const char *v22; // rdx
  OSuite::ZAtomEntry *v23; // rcx
  OSuite::ZString result; // [rsp+20h] [rbp-50h]
  OSuite::ZStringBuilder v25; // [rsp+38h] [rbp-38h]

  v3 = tag;
  v4 = (OSuite::ZRedBlackTreeBase *)infos;
  v5 = this;
  if ( this->m_pTransaction )
    return 2147484161i64;
  if ( this->m_pTxnEntry )
    return 2i64;
  v6 = this->m_eTxnCreation;
  if ( !(_DWORD)v6 )
  {
    if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)infos) )
      return 2147483650i64;
    v7 = 0i64;
    if ( OSuite::ZHttpStreamReader::Tell(v4) )
    {
      while ( (*((unsigned int (**)(void))(&v4[1].m_pTop->vfptr)[v7]->__vecDelDtor + 1))() )
      {
        if ( ++v7 >= OSuite::ZHttpStreamReader::Tell(v4) )
          goto LABEL_11;
      }
      return 2147483650i64;
    }
LABEL_11:
    v5->m_eTxnCreation = 4;
    v8 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    v9 = OSuite::ZWebServiceClient::CreateEntry(v8->m_pWebServiceClient, "transactions");
    v5->m_pTxnEntry = v9;
    if ( v9 )
    {
      v10 = OSuite::ZOEntry::AddProperty(v9, "s_userId");
      if ( v10 )
        OSuite::ZOProperty::SetValue(v10, &v5->m_prefixedUserId);
      v11 = OSuite::ZOEntry::AddProperty(v5->m_pTxnEntry, "i32_txnState");
      if ( v11 )
        OSuite::ZOProperty::SetValue(v11, 0);
      v25.m_Chars.m_pList = 0i64;
      OSuite::ZStringBuilder::ZStringBuilder(&v25, 0x80ui64);
      v12 = 0;
      if ( OSuite::ZHttpStreamReader::Tell(v4) )
      {
        v13 = 0i64;
        do
        {
          OSuite::ZStringBuilder::Clear(&v25, 0x20ui64);
          OSuite::ZStringBuilder::Append(&v25, "i32_C");
          v14 = (OSuite::ZString *)(*(__int64 (**)(void))(&v4[1].m_pTop->vfptr)[v13]->__vecDelDtor)();
          OSuite::ZStringBuilder::Append(&v25, v14);
          OSuite::ZStringBuilder::Append(&v25, 95);
          OSuite::ZStringBuilder::AppendInt(&v25, v12);
          v15 = OSuite::ZStringBuilder::ToString(&v25, &result);
          v16 = OSuite::ZString::c_str(v15);
          v17 = OSuite::ZOEntry::AddProperty(v5->m_pTxnEntry, v16);
          OSuite::ZString::~ZString(&result);
          if ( v17 )
          {
            v18 = (*((__int64 (**)(void))(&v4[1].m_pTop->vfptr)[v13]->__vecDelDtor + 1))();
            OSuite::ZOProperty::SetValue(v17, v18);
          }
          v13 = ++v12;
        }
        while ( v12 < OSuite::ZHttpStreamReader::Tell(v4) );
      }
      v19 = OSuite::ZOEntry::AddProperty(v5->m_pTxnEntry, "d_Created");
      if ( v19 )
      {
        v20 = OSuite::ZDateTime::CurrentDateTime((OSuite::ZDateTime *)&result);
        OSuite::ZOProperty::SetValue(v19, v20);
        OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&result);
      }
      v21 = OSuite::ZOEntry::AddProperty(v5->m_pTxnEntry, "s_tag");
      if ( v21 )
      {
        v22 = &customWorldMapCaption;
        if ( v3 )
          v22 = v3;
        OSuite::ZOProperty::SetValue(v21, v22);
      }
      v23 = (OSuite::ZAtomEntry *)&v5->m_pTxnEntry->vfptr;
      result.vfptr = (OSuite::IHashableVtbl *)OSuitePrivate::ZPlayerConsumableData::NewTxnCB;
      result.vfptr = (OSuite::ZObjectVtbl *)v5;
      OSuite::ZAtomEntry::PostTo(
        v23,
        (OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *)&result,
        0i64);
      OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v25);
      v6 = 0i64;
    }
    else
    {
      v5->m_eTxnCreation = 0;
      v6 = 2147484165i64;
    }
  }
  return v6;
}

// File Line: 261
// RVA: 0x1332E74
signed __int64 __fastcall OSuitePrivate::ZPlayerConsumableData::GetActiveTransaction(OSuitePrivate::ZPlayerConsumableData *this, OSuite::IConsumableTransaction **ppTransaction)
{
  OSuitePrivate::ZEidosTransaction *v2; // rax

  if ( this->m_eTxnCreation || !this->m_pTxnFeed )
    return 2i64;
  v2 = this->m_pTransaction;
  if ( !v2 )
    return 2147484164i64;
  if ( ppTransaction )
    *ppTransaction = (OSuite::IConsumableTransaction *)&v2->vfptr;
  return this->m_pTransaction->m_bClose != 0 ? 6 : 0;
}

// File Line: 282
// RVA: 0x1332D08
signed __int64 __fastcall OSuitePrivate::ZPlayerConsumableData::CloseActiveTransaction(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZEidosTransaction *v1; // rax

  v1 = this->m_pTransaction;
  if ( !v1 )
    return 2147484164i64;
  v1->m_bClose = 1;
  return 0i64;
}

// File Line: 298
// RVA: 0x133307C
signed __int64 __fastcall OSuitePrivate::ZPlayerConsumableData::InternalFind(OSuitePrivate::ZPlayerConsumableData *this, const char *id, OSuite::ZConsumableInfoBase **ppInfo)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rbx
  OSuite::ZConsumableInfoBase **v4; // r14
  const char *v5; // rbp
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rsi
  OSuite::ZString *v8; // rax
  signed __int64 result; // rax

  v3 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_ownedConsumables;
  v4 = ppInfo;
  v5 = id;
  v6 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_ownedConsumables) )
    return 2147483908i64;
  while ( 1 )
  {
    v7 = v6 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3, v6 + 1);
    if ( v6 >= v3->m_nTop )
      v3->m_nTop = v7;
    v8 = (OSuite::ZString *)((__int64 (*)(void))v3->m_pList[v6]->vfptr->__vecDelDtor)();
    if ( OSuite::ZString::operator==(v8, v5) )
      break;
    ++v6;
    if ( v7 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v3) )
      return 2147483908i64;
  }
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3, v6 + 1);
  if ( v6 >= v3->m_nTop )
    v3->m_nTop = v6 + 1;
  result = 0i64;
  *v4 = (OSuite::ZConsumableInfoBase *)v3->m_pList[v6];
  return result;
}

// File Line: 323
// RVA: 0x1333400
void __fastcall OSuitePrivate::ZPlayerConsumableData::ProcessRequests(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZPlayerConsumableData *v1; // r14
  OSuite::ZObject *v2; // rdx
  void *v3; // rax
  __int64 v4; // rsi
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r15
  OSuitePrivate::ZPlayerConsumableData::ZRequest *v7; // rdi
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  const char *v11; // rdx
  OSuitePrivate::ZEidosConsumables *v12; // rax
  OSuite::ZString key; // [rsp+20h] [rbp-E0h]
  OSuite::ZString result; // [rsp+38h] [rbp-C8h]
  OSuite::ZObject v15; // [rsp+50h] [rbp-B0h]
  __int64 v16; // [rsp+58h] [rbp-A8h]
  __int64 v17; // [rsp+60h] [rbp-A0h]
  void **v18; // [rsp+68h] [rbp-98h]
  void *ptr; // [rsp+70h] [rbp-90h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+78h] [rbp-88h]
  OSuite::ZStringBuilder v21; // [rsp+98h] [rbp-68h]
  OSuite::ZStringBuilder v22; // [rsp+C8h] [rbp-38h]
  OSuite::ZOQuery query; // [rsp+100h] [rbp+0h]

  v1 = this;
  OSuitePrivate::ZPlayerConsumableData::RemoveCompletedRequests(this);
  if ( v1->m_bRequestInProgress )
    return;
  ptr = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v15, v2);
  v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v18 = &OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  ptr = 0i64;
  v3 = (void *)OSuite::ZObject::malloc(&v15, 0x80ui64, 0i64);
  v16 = 16i64;
  v17 = 0i64;
  ptr = v3;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pendingRequests) )
    goto LABEL_23;
  v21.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v21, 0x100ui64);
  v22.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v22, 0x100ui64);
  v4 = -2i64;
  v5 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pendingRequests) )
    goto LABEL_22;
  do
  {
    v6 = v5 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v1->m_pendingRequests,
      v5 + 1);
    if ( v5 >= v1->m_pendingRequests.m_nTop )
      v1->m_pendingRequests.m_nTop = v6;
    v7 = v1->m_pendingRequests.m_pList[v5];
    if ( !v7->Sent )
    {
      if ( v4 == -2 )
      {
        v4 = v7->transactionId;
        OSuite::ZStringBuilder::Append(&v21, "i32_C");
        OSuite::ZStringBuilder::Append(&v21, &v7->Id);
      }
      else
      {
        if ( v4 != v7->transactionId )
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
  while ( v6 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pendingRequests) );
  if ( v4 != -2 )
  {
    params.m_pLists = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
    OSuite::ZString::ZString(&key, "playerId");
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(&params, &key, &v1->m_prefixedUserId);
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
    if ( v4 >= 0 )
    {
      OSuite::ZString::ZString(&key, "transactionId");
      OSuite::ZString::ZString(&result, v4);
      OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(&params, &key, v10);
      OSuite::ZString::~ZString(&result);
      OSuite::ZString::~ZString(&key);
    }
    query.m_entityName.m_pString = 0i64;
    query.m_queryMap.m_pLists = 0i64;
    query.m_functionParameters.m_pLists = 0i64;
    OSuite::ZOQuery::ZOQuery(&query);
    v11 = "DecreaseConsumables";
    if ( v4 != -1 )
      v11 = "IncreaseConsumables";
    OSuite::ZOQuery::ServiceOperation(&query, v11, &params);
    key.vfptr = (OSuite::ZObjectVtbl *)v1;
    key.vfptr = (OSuite::IHashableVtbl *)OSuitePrivate::ZPlayerConsumableData::RequestCB;
    v12 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    OSuite::ZWebServiceClient::ExecuteQuery(
      v12->m_pWebServiceClient,
      &query,
      (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *)&key);
    v1->m_bRequestInProgress = 1;
    OSuite::ZOQuery::~ZOQuery(&query);
    params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
    if ( params.m_pLists )
    {
      if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
        params.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)params.m_pLists, 3u);
      else
        Illusion::ShaderParam::operator delete(&params.m_pLists[-1].m_Comparer.vfptr);
    }
  }
LABEL_22:
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v22);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v21);
LABEL_23:
  v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v18 = &OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free(&v15, ptr);
}

// File Line: 391
// RVA: 0x13337B0
void __fastcall OSuitePrivate::ZPlayerConsumableData::RemoveCompletedRequests(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rbx
  unsigned __int64 v2; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rcx

  v1 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_pendingRequests;
  v2 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingRequests) )
  {
    do
    {
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v2 + 1);
      if ( v2 >= v1->m_nTop )
        v1->m_nTop = v2 + 1;
      v3 = v1->m_pList[v2];
      if ( BYTE5(v3[1].vfptr) )
      {
        v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
        v1->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, v2);
      }
      else
      {
        ++v2;
      }
    }
    while ( v2 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) );
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
  OSuitePrivate::ZPlayerConsumableData *v1; // rbx
  OSuite::ConsumableError v2; // eax
  OSuitePrivate::ZEidosConsumables *v3; // rax
  OSuitePrivate::ZEidosConsumables *v4; // rax
  OSuitePrivate::ZEidosConsumables *v5; // rax

  v1 = this;
  OSuitePrivate::ZPlayerConsumableData::UpdateConsumableData(this);
  v2 = v1->m_eTxnCreation;
  if ( v2 != 5 || v1->m_bQueryTxn )
  {
    if ( v2 == -2147483131 )
    {
      v5 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
      OSuite::ZWebServiceClient::ReleaseEntry(v5->m_pWebServiceClient, v1->m_pTxnEntry);
      v1->m_pTxnEntry = 0i64;
      v1->m_eTxnCreation = 0;
    }
  }
  else
  {
    v3 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    OSuite::ZWebServiceClient::ReleaseEntry(v3->m_pWebServiceClient, v1->m_pTxnEntry);
    v1->m_pTxnEntry = 0i64;
    if ( v1->m_pTxnFeed )
    {
      v4 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
      OSuite::ZWebServiceClient::CloseRequest(v4->m_pWebServiceClient, (OSuite::ZAtomBase *)&v1->m_pTxnFeed->vfptr);
      v1->m_pTxnFeed = 0i64;
    }
    v1->m_eTxnCreation = 2;
  }
  OSuitePrivate::ZPlayerConsumableData::UpdateTransactionFeed(v1);
  OSuitePrivate::ZPlayerConsumableData::UpdateTransaction(v1);
}

// File Line: 463
// RVA: 0x13338E0
void __fastcall OSuitePrivate::ZPlayerConsumableData::TermData(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZPlayerConsumableData *v1; // rbx
  unsigned __int64 v2; // rsi
  unsigned __int64 v3; // rbp
  OSuitePrivate::ZPlayerConsumableData::ZRequest *v4; // rcx
  __int64 v5; // rax
  OSuitePrivate::ZEidosTransaction *v6; // rcx
  OSuitePrivate::ZEidosConsumables *v7; // rax
  OSuitePrivate::ZEidosConsumables *v8; // rax

  v1 = this;
  OSuitePrivate::ZPlayerConsumableData::CleanData(this);
  v2 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pendingRequests) )
  {
    do
    {
      v3 = v2 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v1->m_pendingRequests,
        v2 + 1);
      if ( v2 >= v1->m_pendingRequests.m_nTop )
        v1->m_pendingRequests.m_nTop = v3;
      v4 = v1->m_pendingRequests.m_pList[v2];
      if ( v4 )
        v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
      ++v2;
    }
    while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pendingRequests) );
  }
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_pendingRequests.vfptr, v1->m_pendingRequests.m_pList);
  v5 = OSuite::ZObject::malloc((OSuite::ZObject *)&v1->m_pendingRequests.vfptr, 0x80ui64, 0i64);
  v1->m_pendingRequests.m_nTop = 0i64;
  v1->m_pendingRequests.m_nSize = 16i64;
  v1->m_pendingRequests.m_pList = (OSuitePrivate::ZPlayerConsumableData::ZRequest **)v5;
  v6 = v1->m_pTransaction;
  if ( v6 )
  {
    ((void (__fastcall *)(OSuitePrivate::ZEidosTransaction *, signed __int64))v6->vfptr->~IConsumableTransaction)(
      v6,
      1i64);
    v1->m_pTransaction = 0i64;
  }
  if ( v1->m_pTxnEntry )
  {
    v7 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    OSuite::ZWebServiceClient::ReleaseEntry(v7->m_pWebServiceClient, v1->m_pTxnEntry);
    v1->m_pTxnEntry = 0i64;
  }
  if ( v1->m_pTxnFeed )
  {
    v8 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    OSuite::ZWebServiceClient::CloseRequest(v8->m_pWebServiceClient, (OSuite::ZAtomBase *)&v1->m_pTxnFeed->vfptr);
    v1->m_pTxnFeed = 0i64;
  }
}

// File Line: 492
// RVA: 0x1332C4C
void __fastcall OSuitePrivate::ZPlayerConsumableData::CleanData(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rbx
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rcx
  __int64 v5; // rax

  v1 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_ownedConsumables;
  v2 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_ownedConsumables) )
  {
    do
    {
      v3 = v2 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v2 + 1);
      if ( v2 >= v1->m_nTop )
        v1->m_nTop = v3;
      v4 = v1->m_pList[v2];
      if ( v4 )
        v4->vfptr[3].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
      ++v2;
    }
    while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) );
  }
  OSuite::ZObject::free((OSuite::ZObject *)&v1->vfptr, v1->m_pList);
  v5 = OSuite::ZObject::malloc((OSuite::ZObject *)&v1->vfptr, 0x80ui64, 0i64);
  v1->m_nTop = 0i64;
  v1->m_pList = (OSuite::ZRedBlackTreeBase::ZElementBase **)v5;
  v1->m_nSize = 16i64;
}

// File Line: 501
// RVA: 0x1333A00
void __fastcall OSuitePrivate::ZPlayerConsumableData::UpdateConsumableData(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZPlayerConsumableData *v1; // rdi
  OSuite::ZOEntry *v2; // rcx
  unsigned __int64 v3; // rsi
  OSuite::ZListBase *v4; // rbx
  unsigned __int64 v5; // r14
  OSuite::ZOProperty *v6; // rbx
  unsigned __int64 v7; // rax
  __int64 v8; // rax
  OSuite::ZConsumableInfoBase *v9; // rsi
  int v10; // ebx
  OSuite::ZOEntry *v11; // rax
  int outValue; // [rsp+20h] [rbp-60h]
  OSuite::TList<OSuite::ZOProperty *>::ZIterator result; // [rsp+28h] [rbp-58h]
  OSuite::ZString sStr; // [rsp+40h] [rbp-40h]
  OSuite::ZString that; // [rsp+58h] [rbp-28h]

  v1 = this;
  if ( this->m_pConsumablesData )
  {
    OSuitePrivate::ZPlayerConsumableData::CleanData(this);
    sStr.m_pString = 0i64;
    OSuite::ZString::ZString(&sStr, "i32_C");
    v2 = v1->m_pConsumablesData;
    result.m_pListBase = 0i64;
    OSuite::ZOEntry::Properties(v2, &result);
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&result.vfptr) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_pListBase);
      v3 = result.m_nIndex;
      v4 = result.m_pListBase;
      v5 = result.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)result.m_pListBase,
        result.m_nIndex + 1);
      if ( v3 >= v4->m_nTop )
        v4->m_nTop = v5;
      v6 = *(OSuite::ZOProperty **)(v4[1].m_nSize + 8 * v3);
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
            *(_QWORD *)v8 = &OSuite::ZConsumableInfoBase::`vftable'{for `OSuite::IConsumableInfo'};
            *(_QWORD *)(v8 + 8) = &OSuite::ZConsumableInfoBase::`vftable'{for `OSuite::ZObject'};
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
              (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v1->m_ownedConsumables,
              v1->m_ownedConsumables.m_nTop + 1);
            v1->m_ownedConsumables.m_pList[v1->m_ownedConsumables.m_nTop++] = v9;
          }
          OSuite::ZString::~ZString(&that);
        }
      }
      else if ( (unsigned int)OSuite::ZOProperty::Type(v6) == 11
             && OSuite::ZString::StartsWith(&v6->m_Name, "i64_currentTransaction") )
      {
        OSuite::ZOProperty::GetValue(v6, &v1->m_completedTxnId);
        v11 = v1->m_pConsumablesData;
        v1->m_transferTxnId = -1i64;
        v1->m_pTransferEntry = v11;
      }
      OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&result.vfptr);
    }
    v1->m_pConsumablesData = 0i64;
    OSuite::ZString::~ZString(&sStr);
  }
}

// File Line: 542
// RVA: 0x1333E04
void __fastcall OSuitePrivate::ZPlayerConsumableData::UpdateTransactionFeed(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZPlayerConsumableData *v1; // rdi
  OSuite::ZOFeed *v2; // rcx
  char *v3; // rax
  __int64 v4; // rbx
  OSuite::ZOFilter *v5; // rax
  OSuite::ZOFilter *v6; // rax
  OSuitePrivate::ZEidosConsumables *v7; // rax
  __int64 v8; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rax
  OSuite::ZOEntry *v10; // rcx
  OSuitePrivate::ZEidosTransaction *v11; // rax
  OSuitePrivate::ZEidosConsumables *v12; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+20h] [rbp-D8h]
  OSuite::ZOFilter v14; // [rsp+30h] [rbp-C8h]
  OSuite::ZOFilter filterExpression; // [rsp+68h] [rbp-90h]
  __int64 v16; // [rsp+B8h] [rbp-40h]
  __int64 v17; // [rsp+C8h] [rbp-30h]
  __int64 v18; // [rsp+E8h] [rbp-10h]

  v1 = this;
  v2 = this->m_pTxnFeed;
  if ( v2 )
  {
    if ( !v1->m_bQueryTxn && !v1->m_pTransaction )
    {
      v8 = 0i64;
      if ( OSuite::ZAtomFeed::TotalEntries((OSuite::ZAtomFeed *)&v2->vfptr) )
      {
        while ( 1 )
        {
          v9 = OSuite::ZAtomFeed::GetEntry((OSuite::ZAtomFeed *)&v1->m_pTxnFeed->vfptr, v8);
          v10 = (OSuite::ZOEntry *)((unsigned __int64)v9 & -(signed __int64)((unsigned __int8)v9->vfptr[1].__vecDelDtor(
                                                                                                (OSuite::ZObject *)&v9->vfptr,
                                                                                                OSuite::ZOEntry::s_nClassId) != 0));
          if ( v10 )
          {
            v11 = OSuitePrivate::ZEidosTransaction::Create(v10, v1->m_pPlayerProfile, v1->m_eTxnCreation == 2);
            v1->m_eTxnCreation = 0;
            v1->m_pTransaction = v11;
          }
          if ( v1->m_pTransaction )
            break;
          if ( ++v8 >= OSuite::ZAtomFeed::TotalEntries((OSuite::ZAtomFeed *)&v1->m_pTxnFeed->vfptr) )
            goto LABEL_15;
        }
      }
      else
      {
LABEL_15:
        if ( !v1->m_pTransaction && v1->m_completedTxnId != -1 )
        {
          v12 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
          OSuite::ZWebServiceClient::CloseRequest(v12->m_pWebServiceClient, (OSuite::ZAtomBase *)&v1->m_pTxnFeed->vfptr);
          v1->m_pTxnFeed = 0i64;
        }
      }
    }
  }
  else if ( !v1->m_bQueryTxn )
  {
    v16 = 0i64;
    v17 = 0i64;
    v18 = 0i64;
    OSuite::ZOQuery::ZOQuery((OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList);
    OSuite::ZOQuery::EntitySet((OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList, "transactions");
    filterExpression.m_queryBuilder.m_Chars.vfptr = 0i64;
    OSuite::ZOFilter::ZOFilter(&filterExpression);
    v3 = OSuite::ZString::c_str(&v1->m_prefixedUserId);
    OSuite::ZOFilter::Compare(&filterExpression, "s_userId", v3, 0);
    v4 = v1->m_completedTxnId;
    OSuite::ZOFilter::ZOFilter(&v14);
    if ( v4 < 0 )
      v6 = OSuite::ZOFilter::Compare(v5, "i32_txnState", 5, LESSER);
    else
      v6 = OSuite::ZOFilter::Compare(v5, "_id", v4, 0);
    OSuite::ZOFilter::And(&filterExpression, v6);
    OSuite::ZOFilter::~ZOFilter(&v14);
    OSuite::ZOQuery::Filter((OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList, &filterExpression);
    cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)v1;
    cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuitePrivate::ZPlayerConsumableData::FeedFetchedCB;
    v7 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
    v1->m_bQueryTxn = OSuite::ZWebServiceClient::ExecuteQuery(
                        v7->m_pWebServiceClient,
                        (OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList,
                        &cb);
    OSuite::ZOFilter::~ZOFilter(&filterExpression);
    OSuite::ZOQuery::~ZOQuery((OSuite::ZOQuery *)&filterExpression.m_queryBuilder.m_Chars.m_pList);
  }
}ry::~ZOQuery((OSuite::ZOQue

// File Line: 593
// RVA: 0x1333CB4
void __fastcall OSuitePrivate::ZPlayerConsumableData::UpdateTransaction(OSuitePrivate::ZPlayerConsumableData *this)
{
  OSuitePrivate::ZPlayerConsumableData *v1; // rbx
  OSuitePrivate::ZEidosTransaction *v2; // rcx
  signed int v3; // eax
  __int64 v4; // rdi
  OSuitePrivate::EidosTransactionState v5; // edx
  OSuite::ZObject *v6; // rdx
  OSuite::ZOEntry *v7; // rcx
  OSuite::ZAtomEntry *v8; // rcx
  OSuitePrivate::ZEidosTransaction *v9; // rcx
  OSuitePrivate::ZEidosConsumables *v10; // rax
  OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> callback; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = this->m_pTransaction;
  if ( v2 )
  {
    v3 = OSuitePrivate::ZEidosTransaction::GetCompletionState(v2);
    if ( v3 == 4 )
    {
      v4 = v1->m_completedTxnId;
      if ( v4 == ((__int64 (*)(void))v1->m_pTransaction->vfptr->GetId)() )
      {
        v5 = 5;
LABEL_8:
        OSuitePrivate::ZEidosTransaction::SetCompletionState(v1->m_pTransaction, v5);
        return;
      }
      if ( v4 == -1 && (signed int)OSuitePrivate::ZPlayerConsumableData::Acquire(v1) < 0 )
      {
        v5 = 7;
        goto LABEL_8;
      }
    }
    else if ( v3 >= 5 )
    {
      if ( OSuitePrivate::ZEidosTransaction::LatestState(v1->m_pTransaction) )
      {
        if ( !v1->m_bRequestInProgress )
        {
          v7 = v1->m_pTransferEntry;
          if ( v7 )
          {
            if ( OSuite::ZOEntry::DeleteProperty(v7, "i64_currentTransaction") )
            {
              v8 = (OSuite::ZAtomEntry *)&v1->m_pTransferEntry->vfptr;
              callback.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuitePrivate::ZPlayerConsumableData::ClearTxnCB;
              v1->m_bRequestInProgress = 1;
              callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)v1;
              OSuite::ZAtomEntry::Update(v8, &callback, 0i64);
            }
            else
            {
              v1->m_pTransferEntry = 0i64;
            }
            v1->m_completedTxnId = -1i64;
          }
          v9 = v1->m_pTransaction;
          if ( v9 )
            ((void (__fastcall *)(OSuitePrivate::ZEidosTransaction *, signed __int64))v9->vfptr->~IConsumableTransaction)(
              v9,
              1i64);
          v1->m_pTransaction = 0i64;
          if ( v1->m_pTxnFeed )
          {
            v10 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
            OSuite::ZWebServiceClient::CloseRequest(
              v10->m_pWebServiceClient,
              (OSuite::ZAtomBase *)&v1->m_pTxnFeed->vfptr);
            v1->m_pTxnFeed = 0i64;
          }
        }
      }
      else
      {
        OSuitePrivate::ZEidosTransaction::UpdateState(v1->m_pTransaction, v6);
      }
    }
  }
}

// File Line: 649
// RVA: 0x1333834
void __fastcall OSuitePrivate::ZPlayerConsumableData::RequestCB(OSuitePrivate::ZPlayerConsumableData *this, OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rbx
  OSuitePrivate::ZPlayerConsumableData *v4; // rbp
  OSuite::ZWebServiceClient *v5; // r15
  OSuite::SCallbackData *v6; // rsi
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // r14
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rcx

  v3 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_pendingRequests;
  v4 = this;
  v5 = pWebServiceClient;
  v6 = pData;
  v7 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pendingRequests) )
  {
    do
    {
      v8 = v7 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3, v7 + 1);
      if ( v7 >= v3->m_nTop )
        v3->m_nTop = v8;
      v9 = v3->m_pList[v7];
      if ( BYTE4(v9[1].vfptr) )
      {
        BYTE5(v9[1].vfptr) = 1;
        v9[1].m_pRight = (OSuite::ZRedBlackTreeBase::ZElementBase *)v6->Status;
      }
      ++v7;
    }
    while ( v8 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v3) );
  }
  if ( v6->Status.eError == HTTPERROR_OK )
    v4->m_pConsumablesData = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(v5, &v6->URL);
  v4->m_bRequestInProgress = 0;
}

// File Line: 669
// RVA: 0x13333E8
void __fastcall OSuitePrivate::ZPlayerConsumableData::NewTxnCB(OSuitePrivate::ZPlayerConsumableData *this, OSuite::SCallbackData *pData)
{
  this->m_eTxnCreation = pData->Status.eError != 0 ? -2147483131 : 5;
}

// File Line: 681
// RVA: 0x1332CEC
void __fastcall OSuitePrivate::ZPlayerConsumableData::ClearTxnCB(OSuitePrivate::ZPlayerConsumableData *this, OSuite::SCallbackData *pData)
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
void __fastcall OSuitePrivate::ZPlayerConsumableData::FeedFetchedCB(OSuitePrivate::ZPlayerConsumableData *this, OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuitePrivate::ZPlayerConsumableData *v3; // rbx

  v3 = this;
  if ( pData->Status.eError == HTTPERROR_OK )
    this->m_pTxnFeed = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOFeed>(pWebServiceClient, &pData->URL);
  v3->m_bQueryTxn = 0;
}

