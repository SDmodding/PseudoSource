// File Line: 23
// RVA: 0x15BE0A0
__int64 dynamic_initializer_for__CAkBankList::m_BankListLock__()
{
  InitializeCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  return atexit(dynamic_atexit_destructor_for__CAkBankList::m_BankListLock__);
}

// File Line: 26
// RVA: 0xA87C90
void __fastcall CAkBankList::Init(CAkBankList *this)
{
  signed __int64 v1; // rax

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
void __fastcall CAkBankList::Set(CAkBankList *this, AkBankKey *in_BankKey, CAkUsageSlot *in_pSlot)
{
  CAkBankList *v3; // rdi
  CAkUsageSlot *v4; // rsi
  __m128i *v5; // rbx
  CAkUsageSlot *v6; // rax
  __int64 v7; // r8
  __m128i v8; // [rsp+20h] [rbp-18h]

  v3 = this;
  v4 = in_pSlot;
  v5 = (__m128i *)in_BankKey;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v8 = *v5;
  v6 = v3->m_ListLoadedBanks.m_table[(_mm_cvtsi128_si32(*v5) + (unsigned int)*(_OWORD *)&_mm_srli_si128(*v5, 8)) % 0x1F];
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
    *(_QWORD *)&v4->key.bankID = v5->m128i_i64[0];
    v4->key.pInMemoryPtr = (const void *)v5->m128i_i64[1];
    v7 = (_mm_cvtsi128_si32(*v5) + (unsigned int)*(_OWORD *)&_mm_srli_si128(*v5, 8)) % 0x1F;
    v4->pNextItem = v3->m_ListLoadedBanks.m_table[v7];
    v3->m_ListLoadedBanks.m_table[v7] = v4;
    ++v3->m_ListLoadedBanks.m_uiSize;
  }
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
}

// File Line: 51
// RVA: 0xA87BF0
CAkUsageSlot *__fastcall CAkBankList::Get(CAkBankList *this, AkBankKey *in_BankKey)
{
  CAkBankList *v2; // rdi
  __m128i *v3; // rbx
  CAkUsageSlot *v4; // rbx
  __m128i v6; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = (__m128i *)in_BankKey;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v6 = *v3;
  v4 = v2->m_ListLoadedBanks.m_table[(_mm_cvtsi128_si32(*v3) + (unsigned int)*(_OWORD *)&_mm_srli_si128(*v3, 8)) % 0x1F];
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
  CAkBankList *v2; // rdi
  AkBankKey *v3; // rbx

  v2 = this;
  v3 = in_BankKey;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  AkHashListBare<AkBankKey,CAkUsageSlot,31,AkDefaultHashListBarePolicy<AkBankKey,CAkUsageSlot>>::Unset(
    &v2->m_ListLoadedBanks,
    v3);
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
}

