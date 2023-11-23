// File Line: 180
// RVA: 0xA4CF10
void __fastcall AkHashList<AkSwitchKey,unsigned long,193>::RemoveAll(AkHashList<AkSwitchKey,unsigned long,193> *this)
{
  AkHashList<AkSwitchKey,unsigned long,193>::Item **m_table; // rdi
  __int64 v3; // rbp
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v4; // rdx
  AkHashList<AkSwitchKey,unsigned long,193>::Item *pNextItem; // rbx

  m_table = this->m_table;
  v3 = 193i64;
  do
  {
    v4 = *m_table;
    if ( *m_table )
    {
      do
      {
        pNextItem = v4->pNextItem;
        AK::MemoryMgr::Free(this->m_MemPoolId, v4);
        v4 = pNextItem;
      }
      while ( pNextItem );
    }
    *m_table++ = 0i64;
    --v3;
  }
  while ( v3 );
  this->m_uiSize = 0;
}

// File Line: 226
// RVA: 0xA57260
unsigned int *__fastcall AkHashList<AkSwitchKey,unsigned long,193>::Set(
        AkHashList<AkSwitchKey,unsigned long,193> *this,
        __m128i *in_Key)
{
  char *v3; // rdi
  __int64 *v4; // rax
  unsigned int *result; // rax
  unsigned int *v6; // rcx
  __m128i v7; // [rsp+20h] [rbp-18h]
  __m128i v8; // [rsp+20h] [rbp-18h]

  v7 = *in_Key;
  v3 = (char *)this + 8 * ((_mm_srli_si128(*in_Key, 8).m128i_u64[0] + (unsigned int)_mm_cvtsi128_si32(*in_Key)) % 0xC1);
  v4 = (__int64 *)*((_QWORD *)v3 + 1);
  if ( !v4 )
    goto LABEL_7;
  while ( *((_DWORD *)v4 + 2) != v7.m128i_i32[0] || v4[2] != v7.m128i_i64[1] )
  {
    v4 = (__int64 *)*v4;
    if ( !v4 )
      goto LABEL_7;
  }
  result = (unsigned int *)(v4 + 3);
  if ( !result )
  {
LABEL_7:
    v8 = *in_Key;
    result = (unsigned int *)AK::MemoryMgr::Malloc(this->m_MemPoolId, 0x20ui64);
    v6 = result;
    if ( result )
    {
      *(_QWORD *)result = *((_QWORD *)v3 + 1);
      result += 6;
      *(__m128i *)(v6 + 2) = v8;
      *((_QWORD *)v3 + 1) = v6;
      ++this->m_uiSize;
    }
  }
  return result;
}

// File Line: 257
// RVA: 0xA620E0
void __fastcall AkHashList<unsigned long,AkMediaEntry,193>::Unset(
        AkHashList<unsigned long,AkMediaEntry,193> *this,
        unsigned int in_Key)
{
  char *v4; // rdx
  _QWORD *v5; // rcx
  _QWORD *v6; // rbx
  __int64 v7; // rax
  void *v8; // rdx

  v4 = (char *)this + 8 * (in_Key % 0xC1);
  v5 = 0i64;
  v6 = (_QWORD *)*((_QWORD *)v4 + 1);
  if ( v6 )
  {
    while ( *((_DWORD *)v6 + 2) != in_Key )
    {
      v5 = v6;
      v6 = (_QWORD *)*v6;
      if ( !v6 )
        return;
    }
    v7 = *v6;
    if ( v5 )
      *v5 = v7;
    else
      *((_QWORD *)v4 + 1) = v7;
    v8 = (void *)v6[4];
    if ( v8 )
    {
      *((_DWORD *)v6 + 10) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
      v6[4] = 0i64;
      *((_DWORD *)v6 + 11) = 0;
    }
    AK::MemoryMgr::Free(this->m_MemPoolId, v6);
    --this->m_uiSize;
  }
}

// File Line: 335
// RVA: 0xA4CA70
CAkRegisteredObj **__fastcall AkHashList<unsigned __int64,CAkRegisteredObj *,193>::CreateEntry(
        AkHashList<unsigned __int64,CAkRegisteredObj *,193> *this,
        unsigned __int64 in_Key,
        unsigned __int64 in_uiTable)
{
  CAkRegisteredObj **result; // rax
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v7; // r9
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v8; // rax

  result = (CAkRegisteredObj **)AK::MemoryMgr::Malloc(this->m_MemPoolId, 0x18ui64);
  v7 = (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)result;
  if ( result )
  {
    v8 = this->m_table[in_uiTable];
    v7->Assoc.key = in_Key;
    v7->pNextItem = v8;
    this->m_table[in_uiTable] = v7;
    ++this->m_uiSize;
    return &v7->Assoc.item;
  }
  return result;
}

// File Line: 543
// RVA: 0xA87E30
CAkUsageSlot *__fastcall AkHashListBare<AkBankKey,CAkUsageSlot,31,AkDefaultHashListBarePolicy<AkBankKey,CAkUsageSlot>>::Unset(
        AkHashListBare<AkBankKey,CAkUsageSlot,31,AkDefaultHashListBarePolicy<AkBankKey,CAkUsageSlot> > *this,
        __m128i *in_Key)
{
  int v4; // eax
  unsigned int v5; // xmm0_4
  CAkUsageSlot *v6; // rdx
  __int64 v7; // r9
  CAkUsageSlot *result; // rax
  CAkUsageSlot **v9; // r9
  CAkUsageSlot *pNextItem; // rcx

  v4 = _mm_cvtsi128_si32(*in_Key);
  v5 = _mm_srli_si128(*in_Key, 8).m128i_u32[0];
  v6 = 0i64;
  v7 = (v4 + v5) % 0x1F;
  result = this->m_table[v7];
  v9 = &this->m_table[v7];
  if ( result )
  {
    while ( result->key.bankID != in_Key->m128i_i32[0] || result->key.pInMemoryPtr != (const void *)in_Key->m128i_i64[1] )
    {
      v6 = result;
      result = result->pNextItem;
      if ( !result )
        return result;
    }
    pNextItem = result->pNextItem;
    if ( v6 )
      v6->pNextItem = pNextItem;
    else
      *v9 = pNextItem;
    --this->m_uiSize;
  }
  return result;
}

