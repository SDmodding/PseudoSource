// File Line: 11
// RVA: 0x1330CC0
OSuitePrivate::ZEidosTransaction *__fastcall OSuitePrivate::ZEidosTransaction::Create(OSuite::ZOEntry *in_pEntry, OSuite::IPlayerAccount *pUser, bool bOpen)
{
  __int64 v3; // rsi
  bool v4; // r12
  OSuite::IPlayerAccount *v5; // r13
  OSuite::ZOEntry *v6; // rbx
  OSuitePrivate::ZEidosTransaction *v7; // rax
  OSuite::ZObject *v8; // rdx
  __int64 v9; // rax
  char v10; // r15
  unsigned __int64 v11; // rdi
  OSuite::ZListBase *v12; // rbx
  unsigned __int64 v13; // r14
  OSuite::ZOProperty *v14; // rbx
  OSuite::ZString *v15; // rax
  OSuite::ZString *v16; // rax
  OSuite::ZString *v17; // rax
  OSuite::ZString *v18; // rdi
  bool v19; // bl
  OSuite::ZString *v20; // rdi
  int v21; // eax
  __int64 v22; // r13
  int v23; // er14
  bool v24; // bl
  unsigned __int64 v25; // rbx
  unsigned __int64 v26; // rax
  __int64 v27; // rax
  OSuite::ZConsumableInfoBase *v28; // rdi
  int v29; // ebx
  OSuite::ZConsumableInfoBase *v31; // [rsp+20h] [rbp-79h]
  OSuite::IPlayerAccount *v32; // [rsp+28h] [rbp-71h]
  OSuite::ZString v33; // [rsp+30h] [rbp-69h]
  int Element; // [rsp+48h] [rbp-51h]
  OSuite::ZString outValue; // [rsp+50h] [rbp-49h]
  int v36; // [rsp+68h] [rbp-31h]
  OSuite::TList<OSuite::ZOProperty *>::ZIterator result; // [rsp+70h] [rbp-29h]
  OSuite::ZString v38; // [rsp+88h] [rbp-11h]
  OSuite::ZString sStr; // [rsp+A0h] [rbp+7h]

  v3 = 0i64;
  v4 = bOpen;
  v5 = pUser;
  v32 = pUser;
  v6 = in_pEntry;
  if ( in_pEntry )
  {
    v7 = (OSuitePrivate::ZEidosTransaction *)AMemory::malloc_default(0x98ui64);
    if ( v7 )
    {
      v7->m_pPlayerAccount = 0i64;
      v7->m_Infos.m_pList = 0i64;
      v7->m_tempCount.m_pList = 0i64;
      v7->m_pTransactionEntry = 0i64;
      v7->m_tag.m_pString = 0i64;
      OSuitePrivate::ZEidosTransaction::ZEidosTransaction(v7, v8);
      v3 = v9;
    }
    *(_QWORD *)(v3 + 120) = v6;
    sStr.m_pString = 0i64;
    v10 = 1;
    OSuite::ZString::ZString(&sStr, "i32_C");
    result.m_pListBase = 0i64;
    OSuite::ZOEntry::Properties(v6, &result);
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&result.vfptr) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_pListBase);
      v11 = result.m_nIndex;
      v12 = result.m_pListBase;
      v13 = result.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)result.m_pListBase,
        result.m_nIndex + 1);
      if ( v11 >= v12->m_nTop )
        v12->m_nTop = v13;
      v14 = *(OSuite::ZOProperty **)(v12[1].m_nSize + 8 * v11);
      if ( (unsigned int)OSuite::ZOProperty::Type(v14) == 11 )
      {
        if ( OSuite::ZString::StartsWith(&v14->m_Name, "_id") )
          OSuite::ZOProperty::GetValue(v14, (__int64 *)(v3 + 16));
      }
      else if ( (unsigned int)OSuite::ZOProperty::Type(v14) == 14 )
      {
        if ( OSuite::ZString::StartsWith(&v14->m_Name, "s_userId") )
        {
          outValue.m_pString = 0i64;
          OSuite::ZString::ZString(&outValue);
          OSuite::ZOProperty::GetValue(v14, &outValue);
          v15 = v5->vfptr->GetUserId(v5, 0);
          v16 = OSuite::operator+(&v38, &customWorldMapCaption, v15);
          OSuite::ZString::ZString(&v33, v16);
          v18 = v17;
          v19 = OSuite::ZString::operator==(&outValue, v17) == 0;
          OSuite::ZString::~ZString(v18);
          OSuite::ZString::~ZString(&v38);
          if ( v19 )
          {
            OSuite::ZString::~ZString(&outValue);
            break;
          }
          v10 = 0;
          OSuite::ZString::~ZString(&outValue);
        }
        else if ( OSuite::ZString::StartsWith(&v14->m_Name, "s_tag") )
        {
          OSuite::ZOProperty::GetValue(v14, (OSuite::ZString *)(v3 + 128));
        }
      }
      else if ( (unsigned int)OSuite::ZOProperty::Type(v14) == 10 )
      {
        v20 = &v14->m_Name;
        if ( OSuite::ZString::StartsWith(&v14->m_Name, "i32_txnState") )
        {
          OSuite::ZOProperty::GetValue(v14, &v36);
          *(_DWORD *)(v3 + 12) = v36;
        }
        else if ( OSuite::ZString::StartsWith(&v14->m_Name, &sStr) )
        {
          OSuite::ZOProperty::GetValue(v14, &Element);
          v21 = OSuite::ZString::LastIndexOf(&v14->m_Name, 95);
          v38.m_pString = 0i64;
          v22 = v21;
          OSuite::ZString::Slice(&v14->m_Name, &v38, v21 + 1);
          v23 = OSuite::ZString::ToInt(&v38);
          OSuite::ZString::ZString(&outValue, "_temp_");
          v24 = (signed int)OSuite::ZString::IndexOf(&v14->m_Name, &outValue, 0i64) > 0;
          OSuite::ZString::~ZString(&outValue);
          if ( v24 )
          {
            OSuite::TList<int>::Insert((OSuite::TList<int> *)(v3 + 80), v23, 1ui64, &Element);
          }
          else
          {
            outValue.m_pString = 0i64;
            v25 = v22 - OSuite::ZString::Count(&sStr);
            v26 = OSuite::ZString::Count(&sStr);
            OSuite::ZString::Slice(v20, &outValue, v26, v25);
            v27 = OSuite::ZObject::operator new(0x30ui64);
            v28 = (OSuite::ZConsumableInfoBase *)v27;
            if ( v27 )
            {
              *(_QWORD *)(v27 + 32) = 0i64;
              v29 = Element;
              *(_QWORD *)v27 = &OSuite::ZConsumableInfoBase::`vftable'{for `OSuite::IConsumableInfo'};
              *(_QWORD *)(v27 + 8) = &OSuite::ZConsumableInfoBase::`vftable'{for `OSuite::ZObject'};
              OSuite::ZString::ZString((OSuite::ZString *)(v27 + 16), &outValue);
              v28->m_uiQuantity = v29;
              v31 = v28;
            }
            else
            {
              v31 = 0i64;
            }
            OSuite::TList<OSuite::ZConsumableInfoBase *>::Insert(
              (OSuite::TList<OSuite::ZConsumableInfoBase *> *)(v3 + 40),
              v23,
              1ui64,
              &v31);
            OSuite::ZString::~ZString(&outValue);
          }
          OSuite::ZString::~ZString(&v38);
          v5 = v32;
        }
      }
      OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&result.vfptr);
    }
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    if ( v10
      || *(_QWORD *)(v3 + 16) < 0i64
      || *(_DWORD *)(v3 + 12) < 0
      || !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)(v3 + 40)) )
    {
      (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v3 + 24i64))(v3, 1i64);
      v3 = 0i64;
    }
    else
    {
      *(_BYTE *)(v3 + 24) = v4 == 0;
    }
    OSuite::ZString::~ZString(&sStr);
  }
  return (OSuitePrivate::ZEidosTransaction *)v3;
}

// File Line: 121
// RVA: 0x1330A88
void __fastcall OSuitePrivate::ZEidosTransaction::ZEidosTransaction(OSuitePrivate::ZEidosTransaction *this, OSuite::ZObject *a2)
{
  OSuite::ZObject *v2; // rbx
  OSuitePrivate::ZEidosTransaction *v3; // rdi
  __int64 v4; // rax
  OSuite::ZObject *v5; // rdx
  __int64 v6; // rax

  this->m_eState = 0;
  this->m_eidosState = 0;
  this->m_id = -1i64;
  v2 = (OSuite::ZObject *)&this->m_Infos.vfptr;
  v3 = this;
  this->vfptr = (OSuite::IConsumableTransactionVtbl *)&OSuitePrivate::ZEidosTransaction::`vftable';
  *(_WORD *)&this->m_bClose = 0;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&this->m_Infos.vfptr, a2);
  v2[4].vfptr = 0i64;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v2[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v4 = OSuite::ZObject::malloc(v2, 0x80ui64, 0i64);
  v2[2].vfptr = 0i64;
  v2[1].vfptr = (OSuite::ZObjectVtbl *)16;
  v2[4].vfptr = (OSuite::ZObjectVtbl *)v4;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v3->m_tempCount.vfptr, v5);
  v3->m_tempCount.m_pList = 0i64;
  v3->m_tempCount.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable'{for `OSuite::ZListBase'};
  v3->m_tempCount.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<int>::`vftable'{for `OSuite::IHashable'};
  v6 = OSuite::ZObject::malloc((OSuite::ZObject *)&v3->m_tempCount.vfptr, 0x40ui64, 0i64);
  v3->m_tempCount.m_nTop = 0i64;
  v3->m_tempCount.m_nSize = 16i64;
  v3->m_tempCount.m_pList = (int *)v6;
  v3->m_pTransactionEntry = 0i64;
  OSuite::ZString::ZString(&v3->m_tag);
}

// File Line: 125
// RVA: 0x1330B60
void __fastcall OSuitePrivate::ZEidosTransaction::~ZEidosTransaction(OSuitePrivate::ZEidosTransaction *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rbx
  OSuitePrivate::ZEidosTransaction *v2; // r14
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rcx
  OSuite::TList<int> *v6; // rcx
  int *v7; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase **v8; // rdx

  v1 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Infos;
  v2 = this;
  this->vfptr = (OSuite::IConsumableTransactionVtbl *)&OSuitePrivate::ZEidosTransaction::`vftable';
  v3 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Infos) )
  {
    do
    {
      v4 = v3 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v3 + 1);
      if ( v3 >= v1->m_nTop )
        v1->m_nTop = v4;
      v5 = v1->m_pList[v3];
      if ( v5 )
        v5->vfptr[3].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
      ++v3;
    }
    while ( v4 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) );
  }
  OSuite::ZString::~ZString(&v2->m_tag);
  v6 = &v2->m_tempCount;
  v7 = v2->m_tempCount.m_pList;
  v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable'{for `OSuite::ZListBase'};
  v6->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<int>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free((OSuite::ZObject *)&v2->m_tempCount.vfptr, v7);
  v8 = v1->m_pList;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v1->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->vfptr, v8);
}

// File Line: 131
// RVA: 0x13310E4
unsigned __int64 __fastcall OSuite::ZHttpStreamReader::Tell(OSuite::ZRedBlackTreeBase *this)
{
  return this->m_nTotalElements;
}

// File Line: 135
// RVA: 0x13310F0
__int64 __fastcall OSuitePrivate::ZEidosTransaction::GetState(OSuite::Statistics *this)
{
  return (unsigned int)this->count;
}

// File Line: 139
// RVA: 0x1331290
signed __int64 __fastcall OSuitePrivate::ZEidosTransaction::SetState(OSuitePrivate::ZEidosTransaction *this, OSuite::ITransactionState state)
{
  if ( state == TRANSACTION_STATE_NEW )
    return 2147483650i64;
  if ( this->m_eState && this->m_bClose )
    return 2147484162i64;
  this->m_eState = state;
  return 0i64;
}

// File Line: 150
// RVA: 0x133121C
bool __fastcall OSuitePrivate::ZEidosTransaction::LatestState(OSuitePrivate::ZEidosTransaction *this)
{
  OSuitePrivate::ZEidosTransaction *v1; // rbx
  OSuite::ZOProperty *v2; // rax
  int outValue; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = OSuite::ZOEntry::Property(this->m_pTransactionEntry, "i32_txnState");
  OSuite::ZOProperty::GetValue(v2, &outValue);
  return outValue == v1->m_eidosState;
}

// File Line: 159
// RVA: 0x13310CC
signed __int64 __fastcall OSuitePrivate::ZEidosTransaction::GetCompletionState(OSuitePrivate::ZEidosTransaction *this)
{
  signed __int64 result; // rax

  result = 1i64;
  if ( !this->m_bUpdating )
    result = (unsigned int)this->m_eidosState;
  return result;
}

// File Line: 164
// RVA: 0x133128C
void __fastcall OSuitePrivate::ZEidosTransaction::SetCompletionState(OSuitePrivate::ZEidosTransaction *this, OSuitePrivate::EidosTransactionState state)
{
  this->m_eidosState = state;
}

// File Line: 169
// RVA: 0x1331560
void __fastcall OSuitePrivate::ZEidosTransaction::UpdateToPurchased(OSuitePrivate::ZEidosTransaction *this, OSuite::TList<int> *tempCounts)
{
  OSuite::ZRedBlackTreeBase *v2; // rsi
  OSuitePrivate::ZEidosTransaction *v3; // rbx
  unsigned int v4; // er12
  OSuite::ZObject *v5; // rdx
  unsigned __int64 v6; // rdi
  signed __int64 v7; // r14
  OSuite::ZString *v8; // rax
  OSuite::ZString *v9; // rax
  char *v10; // rax
  OSuite::ZOProperty *v11; // ST20_8
  OSuite::ZOProperty *v12; // rcx
  OSuite::ZString *v13; // rax
  char *v14; // rax
  OSuite::ZOProperty *v15; // ST20_8
  OSuite::ZOProperty *v16; // [rsp+20h] [rbp-49h]
  OSuite::ZString result; // [rsp+28h] [rbp-41h]
  OSuite::ZString v18; // [rsp+40h] [rbp-29h]
  OSuite::ZStringBuilder v19; // [rsp+58h] [rbp-11h]

  v2 = (OSuite::ZRedBlackTreeBase *)tempCounts;
  v3 = this;
  if ( !this->m_bUpdating )
  {
    v19.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v19, 0x80ui64);
    v4 = 0;
    if ( OSuite::ZHttpStreamReader::Tell(v2) )
    {
      v6 = 0i64;
      do
      {
        OSuite::ZStringBuilder::Clear(&v19, 0x20ui64);
        OSuite::ZStringBuilder::Append(&v19, "i32_C");
        v7 = v6 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v3->m_Infos,
          v6 + 1);
        if ( v6 >= v3->m_Infos.m_nTop )
          v3->m_Infos.m_nTop = v7;
        v8 = (OSuite::ZString *)((__int64 (*)(void))v3->m_Infos.m_pList[v6]->vfptr->GetId)();
        OSuite::ZStringBuilder::Append(&v19, v8);
        OSuite::ZStringBuilder::Append(&v19, "_temp_");
        OSuite::ZStringBuilder::AppendInt(&v19, v4);
        v9 = OSuite::ZStringBuilder::ToString(&v19, &result);
        v10 = OSuite::ZString::c_str(v9);
        v11 = OSuite::ZOEntry::Property(v3->m_pTransactionEntry, v10);
        OSuite::ZString::~ZString(&result);
        v12 = v11;
        if ( !v11 )
        {
          v13 = OSuite::ZStringBuilder::ToString(&v19, &v18);
          v14 = OSuite::ZString::c_str(v13);
          v15 = OSuite::ZOEntry::AddProperty(v3->m_pTransactionEntry, v14);
          OSuite::ZString::~ZString(&v18);
          v12 = v15;
        }
        OSuite::ZOProperty::SetValue(v12, *((_DWORD *)&v2[1].m_pTop->vfptr + v6));
        v16 = (OSuite::ZOProperty *)v2[1].m_pTop;
        OSuite::TList<int>::Grow(&v3->m_tempCount, v6 + 1);
        if ( v6 >= v3->m_tempCount.m_nTop )
          v3->m_tempCount.m_nTop = v7;
        ++v4;
        v3->m_tempCount.m_pList[v6] = *((_DWORD *)&v16->vfptr + v6);
        v6 = v4;
      }
      while ( v4 < OSuite::ZHttpStreamReader::Tell(v2) );
    }
    v3->m_eidosState = 2;
    OSuitePrivate::ZEidosTransaction::UpdateState(v3, v5);
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v19);
  }
}

// File Line: 197
// RVA: 0x13312C4
void __fastcall OSuitePrivate::ZEidosTransaction::UpdateState(OSuitePrivate::ZEidosTransaction *this, OSuite::ZObject *a2)
{
  OSuitePrivate::ZEidosTransaction *v2; // rdi
  bool v3; // sf
  unsigned __int8 v4; // of
  OSuite::ZString *v5; // rax
  OSuite::ZOEntry *v6; // rcx
  unsigned __int64 v7; // r14
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // rsi
  __int64 v10; // rsi
  bool v11; // bl
  unsigned __int64 v12; // r14
  __int64 v13; // rsi
  unsigned __int64 v14; // rbx
  signed __int64 v15; // rax
  char *v16; // rax
  OSuite::ZOProperty *v17; // rax
  OSuite::ZOProperty *v18; // rbx
  OSuite::ZDateTime *v19; // rax
  OSuite::ZAtomEntry *v20; // rcx
  OSuite::ZString InternalString; // [rsp+20h] [rbp-60h]
  OSuite::ZObject v22; // [rsp+38h] [rbp-48h]
  __int64 v23; // [rsp+40h] [rbp-40h]
  unsigned __int64 v24; // [rsp+48h] [rbp-38h]
  void **v25; // [rsp+50h] [rbp-30h]
  OSuite::ZString *v26; // [rsp+58h] [rbp-28h]
  OSuite::TList<OSuite::ZOProperty *>::ZIterator result; // [rsp+60h] [rbp-20h]

  v2 = this;
  if ( !this->m_bUpdating )
  {
    v4 = __OFSUB__(this->m_eidosState, 5);
    v3 = this->m_eidosState - 5 < 0;
    this->m_bUpdating = 1;
    if ( !(v3 ^ v4) )
    {
      v26 = 0i64;
      OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v22, a2);
      v26 = 0i64;
      v22.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
      v25 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
      v5 = OSuite::TList<OSuite::ZString>::AllocList((OSuite::TList<OSuite::ZString> *)&v22, 0i64, 0x10ui64);
      v6 = v2->m_pTransactionEntry;
      v24 = 0i64;
      result.m_pListBase = 0i64;
      v26 = v5;
      v23 = 16i64;
      OSuite::ZOEntry::Properties(v6, &result);
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&result.vfptr) )
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_pListBase);
        v7 = result.m_nIndex;
        v8 = result.m_pListBase;
        v9 = result.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)result.m_pListBase,
          result.m_nIndex + 1);
        if ( v7 >= v8->m_nTop )
          v8->m_nTop = v9;
        v10 = *(_QWORD *)(v8[1].m_nSize + 8 * v7);
        OSuite::ZString::ZString(&InternalString, "_temp_");
        v11 = (unsigned int)OSuite::ZString::IndexOf((OSuite::ZString *)(v10 + 152), &InternalString, 0i64) != -1;
        OSuite::ZString::~ZString(&InternalString);
        if ( v11 )
        {
          OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)&v22, v24 + 1);
          OSuite::ZString::operator=(&v26[v24++], (OSuite::ZString *)(v10 + 152));
        }
        OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&result.vfptr);
      }
      v12 = 0i64;
      result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
      if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v22) )
      {
        v13 = 0i64;
        do
        {
          v14 = v12 + 1;
          OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)&v22, v12 + 1);
          v15 = v24;
          if ( v12 >= v24 )
            v15 = v12 + 1;
          v24 = v15;
          v16 = OSuite::ZString::c_str(&v26[v13]);
          OSuite::ZOEntry::DeleteProperty(v2->m_pTransactionEntry, v16);
          ++v12;
          ++v13;
        }
        while ( v14 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v22) );
      }
      v22.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
      v25 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
      if ( v26 )
      {
        if ( LODWORD(v26[-1].m_pString) )
          v26->vfptr->__vecDelDtor((OSuite::ZObject *)&v26->vfptr, 3u);
        else
          Illusion::ShaderParam::operator delete(&v26[-1].m_pString);
      }
    }
    v17 = OSuite::ZOEntry::Property(v2->m_pTransactionEntry, "i32_txnState");
    OSuite::ZOProperty::SetValue(v17, v2->m_eidosState);
    v18 = OSuite::ZOEntry::Property(v2->m_pTransactionEntry, "d_LastUpdate");
    if ( v18 || (v18 = OSuite::ZOEntry::AddProperty(v2->m_pTransactionEntry, "d_LastUpdate")) != 0i64 )
    {
      v19 = OSuite::ZDateTime::CurrentDateTime((OSuite::ZDateTime *)&InternalString);
      OSuite::ZOProperty::SetValue(v18, v19);
      OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&InternalString);
    }
    v20 = (OSuite::ZAtomEntry *)&v2->m_pTransactionEntry->vfptr;
    result.m_pListBase = (OSuite::ZListBase *)OSuitePrivate::ZEidosTransaction::UpdateCB;
    result.vfptr = (OSuite::ZObjectVtbl *)v2;
    OSuite::ZAtomEntry::Update(v20, (OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *)&result, 0i64);
  }
}

// File Line: 237
// RVA: 0x13312B4
void __fastcall OSuitePrivate::ZEidosTransaction::UpdateCB(OSuitePrivate::ZEidosTransaction *this, OSuite::SCallbackData *pData)
{
  if ( pData->Status.eError == HTTPERROR_OK )
    this->m_bUpdating = 0;
  this->m_bUpdating = 0;
}

