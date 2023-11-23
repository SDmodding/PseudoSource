// File Line: 11
// RVA: 0x1330CC0
OSuitePrivate::ZEidosTransaction *__fastcall OSuitePrivate::ZEidosTransaction::Create(
        OSuite::ZOEntry *in_pEntry,
        OSuite::IPlayerAccount *pUser,
        bool bOpen)
{
  __int64 v3; // rsi
  OSuite::IPlayerAccount *v5; // r13
  OSuitePrivate::ZEidosTransaction *v7; // rax
  OSuite::ZObject *v8; // rdx
  __int64 v9; // rax
  char v10; // r15
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v13; // r14
  OSuite::ZOProperty *v14; // rbx
  OSuite::ZString *v15; // rax
  OSuite::ZString *v16; // rax
  OSuite::ZString *v17; // rax
  OSuite::ZString *v18; // rdi
  bool v19; // bl
  OSuite::ZString *p_m_Name; // rdi
  int IndexOf; // eax
  __int64 v22; // r13
  int v23; // r14d
  bool v24; // bl
  unsigned __int64 v25; // rbx
  unsigned __int64 v26; // rax
  __int64 v27; // rax
  OSuite::ZConsumableInfoBase *v28; // rdi
  int v29; // ebx
  OSuite::ZConsumableInfoBase *v31; // [rsp+20h] [rbp-79h] BYREF
  OSuite::IPlayerAccount *v32; // [rsp+28h] [rbp-71h]
  OSuite::ZString v33; // [rsp+30h] [rbp-69h] BYREF
  int Element; // [rsp+48h] [rbp-51h] BYREF
  OSuite::ZString outValue; // [rsp+50h] [rbp-49h] BYREF
  int v36; // [rsp+68h] [rbp-31h] BYREF
  OSuite::TList<OSuite::ZOProperty *>::ZIterator result; // [rsp+70h] [rbp-29h] BYREF
  OSuite::ZString v38; // [rsp+88h] [rbp-11h] BYREF
  OSuite::ZString sStr; // [rsp+A0h] [rbp+7h] BYREF

  v3 = 0i64;
  v5 = pUser;
  v32 = pUser;
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
    *(_QWORD *)(v3 + 120) = in_pEntry;
    sStr.m_pString = 0i64;
    v10 = 1;
    OSuite::ZString::ZString(&sStr, "i32_C");
    result.m_pListBase = 0i64;
    OSuite::ZOEntry::Properties(in_pEntry, &result);
    while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&result) )
    {
      OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_pListBase);
      m_nIndex = result.m_nIndex;
      m_pListBase = result.m_pListBase;
      v13 = result.m_nIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)result.m_pListBase,
        result.m_nIndex + 1);
      if ( m_nIndex >= m_pListBase->m_nTop )
        m_pListBase->m_nTop = v13;
      v14 = *(OSuite::ZOProperty **)(m_pListBase[1].m_nSize + 8 * m_nIndex);
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
          v16 = OSuite::operator+(&v38, &customCaption, v15);
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
        p_m_Name = &v14->m_Name;
        if ( OSuite::ZString::StartsWith(&v14->m_Name, "i32_txnState") )
        {
          OSuite::ZOProperty::GetValue(v14, &v36);
          *(_DWORD *)(v3 + 12) = v36;
        }
        else if ( OSuite::ZString::StartsWith(&v14->m_Name, &sStr) )
        {
          OSuite::ZOProperty::GetValue(v14, &Element);
          IndexOf = OSuite::ZString::LastIndexOf(&v14->m_Name, 95);
          v38.m_pString = 0i64;
          v22 = IndexOf;
          OSuite::ZString::Slice(&v14->m_Name, &v38, IndexOf + 1);
          v23 = OSuite::ZString::ToInt(&v38);
          OSuite::ZString::ZString(&outValue, "_temp_");
          v24 = (int)OSuite::ZString::IndexOf(&v14->m_Name, &outValue, 0i64) > 0;
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
            OSuite::ZString::Slice(p_m_Name, &outValue, v26, v25);
            v27 = OSuite::ZObject::operator new(0x30ui64);
            v28 = (OSuite::ZConsumableInfoBase *)v27;
            if ( v27 )
            {
              *(_QWORD *)(v27 + 32) = 0i64;
              v29 = Element;
              *(_QWORD *)v27 = &OSuite::ZConsumableInfoBase::`vftable{for `OSuite::IConsumableInfo};
              *(_QWORD *)(v27 + 8) = &OSuite::ZConsumableInfoBase::`vftable{for `OSuite::ZObject};
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
      OSuite::ZListBase::ZListIteratorBase::Next(&result);
    }
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    if ( v10
      || *(__int64 *)(v3 + 16) < 0
      || *(int *)(v3 + 12) < 0
      || !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)(v3 + 40)) )
    {
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v3 + 24i64))(v3, 1i64);
      v3 = 0i64;
    }
    else
    {
      *(_BYTE *)(v3 + 24) = !bOpen;
    }
    OSuite::ZString::~ZString(&sStr);
  }
  return (OSuitePrivate::ZEidosTransaction *)v3;
}

// File Line: 121
// RVA: 0x1330A88
void __fastcall OSuitePrivate::ZEidosTransaction::ZEidosTransaction(
        OSuitePrivate::ZEidosTransaction *this,
        OSuite::ZObject *a2)
{
  OSuite::TList<OSuite::ZConsumableInfoBase *> *p_m_Infos; // rbx
  __int64 v4; // rax
  OSuite::ZObject *v5; // rdx
  int *v6; // rax

  this->m_eState = TRANSACTION_STATE_NEW;
  this->m_eidosState = TXN_NEW;
  this->m_id = -1i64;
  p_m_Infos = &this->m_Infos;
  this->vfptr = (OSuite::IConsumableTransactionVtbl *)&OSuitePrivate::ZEidosTransaction::`vftable;
  *(_WORD *)&this->m_bClose = 0;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Infos, a2);
  p_m_Infos->m_pList = 0i64;
  p_m_Infos->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_Infos->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v4 = OSuite::ZObject::malloc(p_m_Infos, 0x80ui64, 0i64);
  p_m_Infos->m_nTop = 0i64;
  p_m_Infos->m_nSize = 16i64;
  p_m_Infos->m_pList = (OSuite::ZConsumableInfoBase **)v4;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_tempCount, v5);
  this->m_tempCount.m_pList = 0i64;
  this->m_tempCount.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::ZListBase};
  this->m_tempCount.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::IHashable};
  v6 = (int *)OSuite::ZObject::malloc(&this->m_tempCount, 0x40ui64, 0i64);
  this->m_tempCount.m_nTop = 0i64;
  this->m_tempCount.m_nSize = 16i64;
  this->m_tempCount.m_pList = v6;
  this->m_pTransactionEntry = 0i64;
  OSuite::ZString::ZString(&this->m_tag);
}

// File Line: 125
// RVA: 0x1330B60
void __fastcall OSuitePrivate::ZEidosTransaction::~ZEidosTransaction(OSuitePrivate::ZEidosTransaction *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_Infos; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rcx
  int *m_pList; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase **v7; // rdx

  p_m_Infos = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Infos;
  this->vfptr = (OSuite::IConsumableTransactionVtbl *)&OSuitePrivate::ZEidosTransaction::`vftable;
  v3 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_Infos) )
  {
    do
    {
      v4 = v3 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_Infos, v3 + 1);
      if ( v3 >= p_m_Infos->m_nTop )
        p_m_Infos->m_nTop = v4;
      v5 = p_m_Infos->m_pList[v3];
      if ( v5 )
        v5->vfptr[3].__vecDelDtor(v5, 1u);
      ++v3;
    }
    while ( v4 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_Infos) );
  }
  OSuite::ZString::~ZString(&this->m_tag);
  m_pList = this->m_tempCount.m_pList;
  this->m_tempCount.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::ZListBase};
  this->m_tempCount.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_tempCount, m_pList);
  v7 = p_m_Infos->m_pList;
  p_m_Infos->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_Infos->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(p_m_Infos, v7);
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
__int64 __fastcall OSuitePrivate::ZEidosTransaction::SetState(
        OSuitePrivate::ZEidosTransaction *this,
        OSuite::ITransactionState state)
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
  OSuite::ZOProperty *v2; // rax
  int outValue; // [rsp+20h] [rbp-18h] BYREF

  v2 = OSuite::ZOEntry::Property(this->m_pTransactionEntry, "i32_txnState");
  OSuite::ZOProperty::GetValue(v2, &outValue);
  return outValue == this->m_eidosState;
}

// File Line: 159
// RVA: 0x13310CC
__int64 __fastcall OSuitePrivate::ZEidosTransaction::GetCompletionState(OSuitePrivate::ZEidosTransaction *this)
{
  __int64 result; // rax

  result = 1i64;
  if ( !this->m_bUpdating )
    return (unsigned int)this->m_eidosState;
  return result;
}

// File Line: 164
// RVA: 0x133128C
void __fastcall OSuitePrivate::ZEidosTransaction::SetCompletionState(
        OSuitePrivate::ZEidosTransaction *this,
        OSuitePrivate::EidosTransactionState state)
{
  this->m_eidosState = state;
}

// File Line: 169
// RVA: 0x1331560
void __fastcall OSuitePrivate::ZEidosTransaction::UpdateToPurchased(
        OSuitePrivate::ZEidosTransaction *this,
        OSuite::ZRedBlackTreeBase *tempCounts)
{
  unsigned int v4; // r12d
  OSuite::ZObject *v5; // rdx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r14
  OSuite::ZConsumableInfoBase *v8; // rcx
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  char *v11; // rax
  OSuite::ZOProperty *v12; // rcx
  OSuite::ZString *v13; // rax
  char *v14; // rax
  OSuite::ZOProperty *v15; // [rsp+20h] [rbp-49h]
  OSuite::ZOProperty *v16; // [rsp+20h] [rbp-49h]
  int *m_pTop; // [rsp+20h] [rbp-49h]
  OSuite::ZString result; // [rsp+28h] [rbp-41h] BYREF
  OSuite::ZString v19; // [rsp+40h] [rbp-29h] BYREF
  OSuite::ZStringBuilder v20; // [rsp+58h] [rbp-11h] BYREF

  if ( !this->m_bUpdating )
  {
    v20.m_Chars.m_pList = 0i64;
    OSuite::ZStringBuilder::ZStringBuilder(&v20, (OSuite::ZObject *)0x80);
    v4 = 0;
    if ( OSuite::ZHttpStreamReader::Tell(tempCounts) )
    {
      v6 = 0i64;
      do
      {
        OSuite::ZStringBuilder::Clear(&v20, 0x20ui64);
        OSuite::ZStringBuilder::Append(&v20, "i32_C");
        v7 = v6 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_Infos,
          v6 + 1);
        if ( v6 >= this->m_Infos.m_nTop )
          this->m_Infos.m_nTop = v7;
        v8 = this->m_Infos.m_pList[v6];
        v9 = (OSuite::ZString *)v8->OSuite::IConsumableInfo::vfptr->GetId(v8);
        OSuite::ZStringBuilder::Append(&v20, v9);
        OSuite::ZStringBuilder::Append(&v20, "_temp_");
        OSuite::ZStringBuilder::AppendInt(&v20, v4);
        v10 = OSuite::ZStringBuilder::ToString(&v20, &result);
        v11 = OSuite::ZString::c_str(v10);
        v15 = OSuite::ZOEntry::Property(this->m_pTransactionEntry, v11);
        OSuite::ZString::~ZString(&result);
        v12 = v15;
        if ( !v15 )
        {
          v13 = OSuite::ZStringBuilder::ToString(&v20, &v19);
          v14 = OSuite::ZString::c_str(v13);
          v16 = OSuite::ZOEntry::AddProperty(this->m_pTransactionEntry, v14);
          OSuite::ZString::~ZString(&v19);
          v12 = v16;
        }
        OSuite::ZOProperty::SetValue(v12, *((_DWORD *)&tempCounts[1].m_pTop->vfptr + v6));
        m_pTop = (int *)tempCounts[1].m_pTop;
        OSuite::TList<int>::Grow(&this->m_tempCount, v6 + 1);
        if ( v6 >= this->m_tempCount.m_nTop )
          this->m_tempCount.m_nTop = v7;
        ++v4;
        this->m_tempCount.m_pList[v6] = m_pTop[v6];
        v6 = v4;
      }
      while ( v4 < OSuite::ZHttpStreamReader::Tell(tempCounts) );
    }
    this->m_eidosState = TXN_PURCHASED;
    OSuitePrivate::ZEidosTransaction::UpdateState(this, v5);
    OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v20);
  }
}

// File Line: 197
// RVA: 0x13312C4
void __fastcall OSuitePrivate::ZEidosTransaction::UpdateState(
        OSuitePrivate::ZEidosTransaction *this,
        OSuite::ZObject *a2)
{
  bool v3; // cc
  OSuite::ZString *v4; // rax
  OSuite::ZOEntry *m_pTransactionEntry; // rcx
  unsigned __int64 m_nIndex; // r14
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v8; // rsi
  __int64 v9; // rsi
  bool v10; // bl
  unsigned __int64 v11; // r14
  __int64 v12; // rsi
  unsigned __int64 v13; // rbx
  unsigned __int64 m_nTop; // rax
  char *v15; // rax
  OSuite::ZOProperty *v16; // rax
  OSuite::ZOProperty *v17; // rbx
  OSuite::ZDateTime *v18; // rax
  OSuite::ZOEntry *v19; // rcx
  OSuite::ZString InternalString; // [rsp+20h] [rbp-60h] BYREF
  OSuite::TList<OSuite::ZString> v21; // [rsp+38h] [rbp-48h] BYREF
  OSuite::TList<OSuite::ZOProperty *>::ZIterator result; // [rsp+60h] [rbp-20h] BYREF

  if ( !this->m_bUpdating )
  {
    v3 = this->m_eidosState < TXN_COMPLETED;
    this->m_bUpdating = 1;
    if ( !v3 )
    {
      v21.m_pList = 0i64;
      OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v21, a2);
      v21.m_pList = 0i64;
      v21.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
      v21.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
      v4 = OSuite::TList<OSuite::ZString>::AllocList(&v21, 0i64, 0x10ui64);
      m_pTransactionEntry = this->m_pTransactionEntry;
      v21.m_nTop = 0i64;
      result.m_pListBase = 0i64;
      v21.m_pList = v4;
      v21.m_nSize = 16i64;
      OSuite::ZOEntry::Properties(m_pTransactionEntry, &result);
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&result) )
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_pListBase);
        m_nIndex = result.m_nIndex;
        m_pListBase = result.m_pListBase;
        v8 = result.m_nIndex + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)result.m_pListBase,
          result.m_nIndex + 1);
        if ( m_nIndex >= m_pListBase->m_nTop )
          m_pListBase->m_nTop = v8;
        v9 = *(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex);
        OSuite::ZString::ZString(&InternalString, "_temp_");
        v10 = (unsigned int)OSuite::ZString::IndexOf((OSuite::ZString *)(v9 + 152), &InternalString, 0i64) != -1;
        OSuite::ZString::~ZString(&InternalString);
        if ( v10 )
        {
          OSuite::TList<OSuite::ZString>::Grow(&v21, v21.m_nTop + 1);
          OSuite::ZString::operator=(&v21.m_pList[v21.m_nTop++], (OSuite::ZString *)(v9 + 152));
        }
        OSuite::ZListBase::ZListIteratorBase::Next(&result);
      }
      v11 = 0i64;
      result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v21) )
      {
        v12 = 0i64;
        do
        {
          v13 = v11 + 1;
          OSuite::TList<OSuite::ZString>::Grow(&v21, v11 + 1);
          m_nTop = v21.m_nTop;
          if ( v11 >= v21.m_nTop )
            m_nTop = v11 + 1;
          v21.m_nTop = m_nTop;
          v15 = OSuite::ZString::c_str(&v21.m_pList[v12]);
          OSuite::ZOEntry::DeleteProperty(this->m_pTransactionEntry, v15);
          ++v11;
          ++v12;
        }
        while ( v13 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v21) );
      }
      v21.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
      v21.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
      if ( v21.m_pList )
      {
        if ( LODWORD(v21.m_pList[-1].m_pString) )
          v21.m_pList->vfptr->__vecDelDtor(v21.m_pList, 3u);
        else
          Illusion::ShaderParam::operator delete(&v21.m_pList[-1].m_pString);
      }
    }
    v16 = OSuite::ZOEntry::Property(this->m_pTransactionEntry, "i32_txnState");
    OSuite::ZOProperty::SetValue(v16, this->m_eidosState);
    v17 = OSuite::ZOEntry::Property(this->m_pTransactionEntry, "d_LastUpdate");
    if ( v17 || (v17 = OSuite::ZOEntry::AddProperty(this->m_pTransactionEntry, "d_LastUpdate")) != 0i64 )
    {
      v18 = OSuite::ZDateTime::CurrentDateTime((OSuite::ZDateTime *)&InternalString);
      OSuite::ZOProperty::SetValue(v17, v18);
      OSuite::ZJsonSerializer::~ZJsonSerializer((OSuite::ZDateTime *)&InternalString);
    }
    v19 = this->m_pTransactionEntry;
    result.m_pListBase = (OSuite::ZListBase *)OSuitePrivate::ZEidosTransaction::UpdateCB;
    result.vfptr = (OSuite::ZObjectVtbl *)this;
    OSuite::ZAtomEntry::Update(v19, (OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *)&result, 0i64);
  }
}

// File Line: 237
// RVA: 0x13312B4
void __fastcall OSuitePrivate::ZEidosTransaction::UpdateCB(
        OSuitePrivate::ZEidosTransaction *this,
        OSuite::SCallbackData *pData)
{
  if ( pData->Status.eError == HTTPERROR_OK )
    this->m_bUpdating = 0;
  this->m_bUpdating = 0;
}

