// File Line: 29
// RVA: 0xA9B3F0
void __fastcall CAkRandomInfo::Destroy(CAkSequenceInfo *this)
{
  int v1; // edi
  CAkSequenceInfo *v2; // rbx

  if ( this )
  {
    v1 = g_DefaultPoolId;
    v2 = this;
    this->vfptr->__vecDelDtor((CAkContainerBaseInfo *)this, 0);
    AK::MemoryMgr::Free(v1, v2);
  }
}

// File Line: 40
// RVA: 0xA9B140
void __fastcall CAkRandomInfo::CAkRandomInfo(CAkRandomInfo *this, unsigned __int16 in_wItemCount)
{
  unsigned int v2; // eax

  this->m_wRemainingItemsToPlay = in_wItemCount;
  this->m_wCounter = in_wItemCount;
  this->vfptr = (CAkContainerBaseInfoVtbl *)&CAkRandomInfo::`vftable';
  v2 = 50000 * in_wItemCount;
  this->m_ulTotalWeight = v2;
  this->m_ulRemainingWeight = v2;
  this->m_listAvoid.m_pItems = 0i64;
  *(_QWORD *)&this->m_listAvoid.m_uLength = 0i64;
  this->m_pcArrayBeenPlayedFlag = 0i64;
  this->m_pcArrayBlockedFlag = 0i64;
}

// File Line: 44
// RVA: 0xA9B4F0
signed __int64 __fastcall CAkRandomInfo::Init(CAkRandomInfo *this, unsigned __int16 in_wAvoidRepeatCount)
{
  unsigned int v2; // ebx
  CAkRandomInfo *v3; // rdi
  int v4; // eax
  __int64 v5; // rsi
  unsigned __int64 v6; // rbp
  char *v7; // rax
  unsigned __int16 *v9; // rax

  LOWORD(v2) = in_wAvoidRepeatCount;
  v3 = this;
  v4 = (this->m_wCounter + 7) / 8;
  v5 = v4;
  v6 = (unsigned int)(2 * v4);
  v7 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v6);
  v3->m_pcArrayBeenPlayedFlag = v7;
  if ( !v7 )
    return 2i64;
  v3->m_pcArrayBlockedFlag = &v7[v5];
  memset(v7, 0, v6);
  v2 = (unsigned __int16)v2;
  if ( (unsigned __int16)v2 >= 4u )
    v2 = 4;
  if ( v2 )
  {
    v9 = (unsigned __int16 *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 2i64 * v2);
    v3->m_listAvoid.m_pItems = v9;
    if ( !v9 )
      return 52i64;
    v3->m_listAvoid.m_ulReserved = v2;
  }
  return 1i64;
}

// File Line: 75
// RVA: 0xA9B220
CAkContainerBaseInfo *__fastcall CAkRandomInfo::Clone(CAkRandomInfo *this, unsigned __int16 in_wItemCount)
{
  unsigned __int16 v2; // bx
  CAkRandomInfo *v3; // rsi
  _WORD *v5; // rax
  _WORD *v6; // rdi
  int v7; // eax
  int v8; // eax
  __int64 v9; // rbx
  unsigned __int64 v10; // rbp
  char *v11; // rax
  unsigned int v12; // ebx
  void *v13; // rax
  unsigned __int16 *v14; // rbx
  unsigned __int16 v15; // bp
  unsigned __int16 *v16; // rax

  v2 = in_wItemCount;
  v3 = this;
  if ( !in_wItemCount )
    return 0i64;
  v5 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  v5[8] = v2;
  v5[9] = v2;
  *(_QWORD *)v5 = &CAkRandomInfo::`vftable';
  v7 = 50000 * v2;
  *((_DWORD *)v6 + 2) = v7;
  *((_DWORD *)v6 + 3) = v7;
  *((_QWORD *)v6 + 3) = 0i64;
  *((_QWORD *)v6 + 4) = 0i64;
  *((_QWORD *)v6 + 5) = 0i64;
  *((_QWORD *)v6 + 6) = 0i64;
  *((_DWORD *)v6 + 2) = v3->m_ulTotalWeight;
  *((_DWORD *)v6 + 3) = v3->m_ulRemainingWeight;
  v6[8] = v3->m_wRemainingItemsToPlay;
  v6[9] = v3->m_wCounter;
  if ( v3->m_pcArrayBeenPlayedFlag )
  {
    v8 = (v2 + 7) / 8;
    v9 = v8;
    v10 = (unsigned int)(2 * v8);
    v11 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v10);
    *((_QWORD *)v6 + 5) = v11;
    if ( !v11 )
    {
LABEL_14:
      (*(void (__fastcall **)(_WORD *))(*(_QWORD *)v6 + 8i64))(v6);
      return 0i64;
    }
    *((_QWORD *)v6 + 6) = &v11[v9];
    memmove(v11, v3->m_pcArrayBeenPlayedFlag, (unsigned int)v10);
  }
  v12 = v3->m_listAvoid.m_uLength;
  if ( v12 )
  {
    v13 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 2i64 * v12);
    *((_QWORD *)v6 + 3) = v13;
    if ( v13 )
      *((_DWORD *)v6 + 9) = v12;
  }
  v14 = v3->m_listAvoid.m_pItems;
  if ( v14 != &v14[v3->m_listAvoid.m_uLength] )
  {
    while ( 1 )
    {
      v15 = *v14;
      v16 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast((AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)(v6 + 12));
      if ( !v16 )
        break;
      *v16 = v15;
      ++v14;
      if ( v14 == &v3->m_listAvoid.m_pItems[v3->m_listAvoid.m_uLength] )
        return (CAkContainerBaseInfo *)v6;
    }
    goto LABEL_14;
  }
  return (CAkContainerBaseInfo *)v6;
}

// File Line: 130
// RVA: 0xA9B490
void __fastcall CAkRandomInfo::FlagSetPlayed(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  char *v2; // r9

  v2 = &this->m_pcArrayBeenPlayedFlag[(unsigned __int64)in_wPosition >> 3];
  *v2 |= 1 << in_wPosition % 8;
}

// File Line: 140
// RVA: 0xA9B5D0
unsigned __int8 __fastcall CAkRandomInfo::IsFlagSetPlayed(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  int v2; // er9

  v2 = this->m_pcArrayBeenPlayedFlag[(unsigned __int64)in_wPosition >> 3];
  return _bittest(&v2, (unsigned __int8)(in_wPosition % 8));
}

// File Line: 145
// RVA: 0xA9B600
void __fastcall CAkRandomInfo::ResetFlagsPlayed(CAkRandomInfo *this, unsigned __int64 in_PlaylistSize)
{
  CAkRandomInfo *v2; // rbx
  unsigned __int16 v3; // di

  v2 = this;
  v3 = in_PlaylistSize;
  memset(this->m_pcArrayBeenPlayedFlag, 0, (unsigned int)((in_PlaylistSize + 7) >> 3));
  v2->m_wRemainingItemsToPlay = v3;
}

// File Line: 153
// RVA: 0xA9B430
void __fastcall CAkRandomInfo::FlagAsBlocked(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  char *v2; // r9

  v2 = &this->m_pcArrayBlockedFlag[(unsigned __int64)in_wPosition >> 3];
  *v2 |= 1 << in_wPosition % 8;
}

// File Line: 158
// RVA: 0xA9B460
void __fastcall CAkRandomInfo::FlagAsUnBlocked(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  char *v2; // r9

  v2 = &this->m_pcArrayBlockedFlag[(unsigned __int64)in_wPosition >> 3];
  *v2 &= ~(1 << in_wPosition % 8);
}

// File Line: 163
// RVA: 0xA9B5A0
unsigned __int8 __fastcall CAkRandomInfo::IsFlagBlocked(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  int v2; // er9

  v2 = this->m_pcArrayBlockedFlag[(unsigned __int64)in_wPosition >> 3];
  return _bittest(&v2, (unsigned __int8)(in_wPosition % 8));
}

// File Line: 173
// RVA: 0xA9B4C0
__int64 __fastcall CAkRandomInfo::GetRandomValue(CAkRandomInfo *this)
{
  CAkRandomInfo *v1; // rdi
  int v2; // ebx

  v1 = this;
  v2 = rand() << 15;
  return (v2 + rand()) % v1->m_ulRemainingWeight;
}

// File Line: 184
// RVA: 0xA9B180
void __fastcall CAkSequenceInfo::CAkSequenceInfo(CAkSequenceInfo *this)
{
  this->m_bIsForward = 1;
  this->vfptr = (CAkContainerBaseInfoVtbl *)&CAkSequenceInfo::`vftable';
  this->m_i16LastPositionChosen = -1;
}

// File Line: 203
// RVA: 0xA9B3A0
CAkContainerBaseInfo *__fastcall CAkSequenceInfo::Clone(CAkSequenceInfo *this, unsigned __int16 __formal)
{
  CAkSequenceInfo *v2; // rbx
  CAkContainerBaseInfo *result; // rax

  v2 = this;
  result = (CAkContainerBaseInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
  if ( result )
  {
    LOBYTE(result[1].vfptr) = 1;
    result->vfptr = (CAkContainerBaseInfoVtbl *)&CAkSequenceInfo::`vftable';
    WORD1(result[1].vfptr) = -1;
    LOBYTE(result[1].vfptr) = v2->m_bIsForward;
    WORD1(result[1].vfptr) = v2->m_i16LastPositionChosen;
  }
  return result;
}

