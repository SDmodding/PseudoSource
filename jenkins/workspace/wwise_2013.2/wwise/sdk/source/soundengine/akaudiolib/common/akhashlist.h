// File Line: 180
// RVA: 0xA4CF10
void __fastcall AkHashList<AkSwitchKey,unsigned long,193>::RemoveAll(AkHashList<AkSwitchKey,unsigned long,193> *this)
{
  AkHashList<AkSwitchKey,unsigned long,193> *v1; // rsi
  AkHashList<AkSwitchKey,unsigned long,193>::Item **v2; // rdi
  signed __int64 v3; // rbp
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v4; // rdx
  AkHashList<AkSwitchKey,unsigned long,193>::Item *v5; // rbx

  v1 = this;
  v2 = this->m_table;
  v3 = 193i64;
  do
  {
    v4 = *v2;
    if ( *v2 )
    {
      do
      {
        v5 = v4->pNextItem;
        AK::MemoryMgr::Free(v1->m_MemPoolId, v4);
        v4 = v5;
      }
      while ( v5 );
    }
    *v2 = 0i64;
    ++v2;
    --v3;
  }
  while ( v3 );
  v1->m_uiSize = 0;
}

// File Line: 226
// RVA: 0xA57260
unsigned int *__fastcall AkHashList<AkSwitchKey,unsigned long,193>::Set(AkHashList<AkSwitchKey,unsigned long,193> *this, AkSwitchKey *in_Key)
{
  AkHashList<AkSwitchKey,unsigned long,193> *v2; // rbx
  unsigned __int64 v3; // r8
  char *v4; // rdi
  __int64 *v5; // rax
  unsigned int *result; // rax
  unsigned int *v7; // rcx
  AkSwitchKey v8; // [rsp+20h] [rbp-18h]
  AkSwitchKey v9; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = *(unsigned __int128 *)&_mm_srli_si128(*(__m128i *)in_Key, 8)
     + (unsigned int)_mm_cvtsi128_si32(*(__m128i *)in_Key);
  v8 = *in_Key;
  v4 = (char *)this + 8 * (v3 - 193 * ((unsigned __int64)(v3 * (unsigned __int128)0x15390948F40FEAC7ui64 >> 64) >> 4));
  v5 = (__int64 *)*((_QWORD *)v4 + 1);
  if ( !v5 )
    goto LABEL_7;
  while ( *((_DWORD *)v5 + 2) != v8.m_SwitchGroup || (CAkRegisteredObj *)v5[2] != v8.m_pGameObj )
  {
    v5 = (__int64 *)*v5;
    if ( !v5 )
      goto LABEL_7;
  }
  result = (unsigned int *)(v5 + 3);
  if ( !result )
  {
LABEL_7:
    v9 = *in_Key;
    result = (unsigned int *)AK::MemoryMgr::Malloc(this->m_MemPoolId, 0x20ui64);
    v7 = result;
    if ( result )
    {
      *(_QWORD *)result = *((_QWORD *)v4 + 1);
      result += 6;
      *(AkSwitchKey *)(v7 + 2) = v9;
      *((_QWORD *)v4 + 1) = v7;
      ++v2->m_uiSize;
    }
  }
  return result;
}

// File Line: 257
// RVA: 0xA620E0
void __fastcall AkHashList<unsigned long,AkMediaEntry,193>::Unset(AkHashList<unsigned long,AkMediaEntry,193> *this, unsigned int in_Key)
{
  unsigned int v2; // er8
  AkHashList<unsigned long,AkMediaEntry,193> *v3; // rdi
  char *v4; // rdx
  _QWORD *v5; // rcx
  _QWORD *v6; // rbx
  __int64 v7; // rax
  void *v8; // rdx

  v2 = in_Key;
  v3 = this;
  v4 = (char *)this + 8 * (in_Key % 0xC1);
  v5 = 0i64;
  v6 = (_QWORD *)*((_QWORD *)v4 + 1);
  if ( v6 )
  {
    while ( *((_DWORD *)v6 + 2) != v2 )
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
    AK::MemoryMgr::Free(v3->m_MemPoolId, v6);
    --v3->m_uiSize;
  }
}

// File Line: 335
// RVA: 0xA4CA70
CAkRegisteredObj **__fastcall AkHashList<unsigned __int64,CAkRegisteredObj *,193>::CreateEntry(AkHashList<unsigned __int64,CAkRegisteredObj *,193> *this, unsigned __int64 in_Key, unsigned __int64 in_uiTable)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193> *v3; // rbx
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rdi
  CAkRegisteredObj **result; // rax
  CAkRegisteredObj **v7; // r9
  CAkRegisteredObj *v8; // rax

  v3 = this;
  v4 = in_Key;
  v5 = in_uiTable;
  result = (CAkRegisteredObj **)AK::MemoryMgr::Malloc(this->m_MemPoolId, 0x18ui64);
  v7 = result;
  if ( result )
  {
    v8 = (CAkRegisteredObj *)v3->m_table[v5];
    v7[1] = (CAkRegisteredObj *)v4;
    *v7 = v8;
    v3->m_table[v5] = (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)v7;
    ++v3->m_uiSize;
    result = v7 + 2;
  }
  return result;
}

// File Line: 543
// RVA: 0xA87E30
CAkUsageSlot *__fastcall AkHashListBare<AkBankKey,CAkUsageSlot,31,AkDefaultHashListBarePolicy<AkBankKey,CAkUsageSlot>>::Unset(AkHashListBare<AkBankKey,CAkUsageSlot,31,AkDefaultHashListBarePolicy<AkBankKey,CAkUsageSlot> > *this, AkBankKey *in_Key)
{
  AkBankKey *v2; // r10
  AkHashListBare<AkBankKey,CAkUsageSlot,31,AkDefaultHashListBarePolicy<AkBankKey,CAkUsageSlot> > *v3; // r11
  int v4; // eax
  int v5; // xmm0_4
  CAkUsageSlot *v6; // rdx
  __int64 v7; // r9
  CAkUsageSlot *result; // rax
  CAkUsageSlot **v9; // r9
  CAkUsageSlot *v10; // rcx

  v2 = in_Key;
  v3 = this;
  v4 = _mm_cvtsi128_si32(*(__m128i *)in_Key);
  v5 = (unsigned __int128)_mm_srli_si128(*(__m128i *)in_Key, 8);
  v6 = 0i64;
  v7 = (v4 + v5) % 0x1Fu;
  result = this->m_table[v7];
  v9 = &this->m_table[v7];
  if ( result )
  {
    while ( result->key.bankID != v2->bankID || result->key.pInMemoryPtr != v2->pInMemoryPtr )
    {
      v6 = result;
      result = result->pNextItem;
      if ( !result )
        return result;
    }
    v10 = result->pNextItem;
    if ( v6 )
      v6->pNextItem = v10;
    else
      *v9 = v10;
    --v3->m_uiSize;
  }
  return result;
}

