// File Line: 23
// RVA: 0x15BE0A0
__int64 dynamic_initializer_for__CAkBankList::m_BankListLock__()
{
  InitializeCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkBankList::m_BankListLock__);
}

// File Line: 26
// RVA: 0xA87C90
void __fastcall CAkBankList::Init(CAkBankList *this)
{
  __int64 v1; // rax

  this->m_ListLoadedBanks.m_uiSize = 0;
  v1 = 3i64;
  do
  {
    this->m_ListLoadedBanks.m_table[0] = 0i64;
    this->m_ListLoadedBanks.m_table[1] = 0i64;
    this->m_ListLoadedBanks.m_table[2] = 0i64;
    this = (CAkBankList *)((char *)this + 64);
    this[-1].m_ListLoadedBanks.m_table[27] = 0i64;
    this[-1].m_ListLoadedBanks.m_table[28] = 0i64;
    this[-1].m_ListLoadedBanks.m_table[29] = 0i64;
    this[-1].m_ListLoadedBanks.m_table[30] = 0i64;
    *(_QWORD *)&this[-1].m_ListLoadedBanks.m_uiSize = 0i64;
    --v1;
  }
  while ( v1 );
  this->m_ListLoadedBanks.m_table[0] = 0i64;
  this->m_ListLoadedBanks.m_table[1] = 0i64;
  this->m_ListLoadedBanks.m_table[2] = 0i64;
  this->m_ListLoadedBanks.m_table[3] = 0i64;
  this->m_ListLoadedBanks.m_table[4] = 0i64;
  this->m_ListLoadedBanks.m_table[5] = 0i64;
  this->m_ListLoadedBanks.m_table[6] = 0i64;
}

// File Line: 36
// RVA: 0xA87D30
void __fastcall CAkBankList::Set(CAkBankList *this, __m128i *in_BankKey, CAkUsageSlot *in_pSlot)
{
  CAkUsageSlot *v6; // rax
  __int64 v7; // r8
  __m128i v8; // [rsp+20h] [rbp-18h]

  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v8 = *in_BankKey;
  v6 = this->m_ListLoadedBanks.m_table[(_mm_cvtsi128_si32(*in_BankKey) + _mm_srli_si128(*in_BankKey, 8).m128i_u32[0])
                                     % 0x1F];
  if ( v6 )
  {
    while ( v6->key.bankID != v8.m128i_i32[0] || v6->key.pInMemoryPtr != (const void *)v8.m128i_i64[1] )
    {
      v6 = v6->pNextItem;
      if ( !v6 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    *(_QWORD *)&in_pSlot->key.bankID = in_BankKey->m128i_i64[0];
    in_pSlot->key.pInMemoryPtr = (const void *)in_BankKey->m128i_i64[1];
    v7 = (_mm_cvtsi128_si32(*in_BankKey) + _mm_srli_si128(*in_BankKey, 8).m128i_u32[0]) % 0x1F;
    in_pSlot->pNextItem = this->m_ListLoadedBanks.m_table[v7];
    this->m_ListLoadedBanks.m_table[v7] = in_pSlot;
    ++this->m_ListLoadedBanks.m_uiSize;
  }
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
}

// File Line: 51
// RVA: 0xA87BF0
CAkUsageSlot *__fastcall CAkBankList::Get(CAkBankList *this, __m128i *in_BankKey)
{
  CAkUsageSlot *v4; // rbx
  __m128i v6; // [rsp+20h] [rbp-18h]

  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v6 = *in_BankKey;
  v4 = this->m_ListLoadedBanks.m_table[(_mm_cvtsi128_si32(*in_BankKey) + _mm_srli_si128(*in_BankKey, 8).m128i_u32[0])
                                     % 0x1F];
  if ( v4 )
  {
    while ( v4->key.bankID != v6.m128i_i32[0] || v4->key.pInMemoryPtr != (const void *)v6.m128i_i64[1] )
    {
      v4 = v4->pNextItem;
      if ( !v4 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v4 = 0i64;
  }
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  return v4;
}

// File Line: 58
// RVA: 0xA87CF0
void __fastcall CAkBankList::Remove(CAkBankList *this, AkBankKey *in_BankKey)
{
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  AkHashListBare<AkBankKey,CAkUsageSlot,31,AkDefaultHashListBarePolicy<AkBankKey,CAkUsageSlot>>::Unset(
    &this->m_ListLoadedBanks,
    in_BankKey);
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
}

