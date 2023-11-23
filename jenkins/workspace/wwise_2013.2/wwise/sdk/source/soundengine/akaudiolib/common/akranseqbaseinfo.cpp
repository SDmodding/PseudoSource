// File Line: 29
// RVA: 0xA9B3F0
void __fastcall CAkRandomInfo::Destroy(CAkSequenceInfo *this)
{
  int v1; // edi

  if ( this )
  {
    v1 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v1, this);
  }
}

// File Line: 40
// RVA: 0xA9B140
void __fastcall CAkRandomInfo::CAkRandomInfo(CAkRandomInfo *this, unsigned __int16 in_wItemCount)
{
  unsigned int v2; // eax

  this->m_wRemainingItemsToPlay = in_wItemCount;
  this->m_wCounter = in_wItemCount;
  this->vfptr = (CAkContainerBaseInfoVtbl *)&CAkRandomInfo::`vftable;
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
__int64 __fastcall CAkRandomInfo::Init(CAkRandomInfo *this, unsigned __int16 in_wAvoidRepeatCount)
{
  unsigned int v2; // ebx
  int v4; // eax
  __int64 v5; // rsi
  unsigned __int64 v6; // rbp
  char *v7; // rax
  unsigned __int16 *v9; // rax

  LOWORD(v2) = in_wAvoidRepeatCount;
  v4 = (this->m_wCounter + 7) / 8;
  v5 = v4;
  v6 = (unsigned int)(2 * v4);
  v7 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v6);
  this->m_pcArrayBeenPlayedFlag = v7;
  if ( !v7 )
    return 2i64;
  this->m_pcArrayBlockedFlag = &v7[v5];
  memset(v7, 0, v6);
  v2 = (unsigned __int16)v2;
  if ( (unsigned __int16)v2 >= 4u )
    v2 = 4;
  if ( v2 )
  {
    v9 = (unsigned __int16 *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 2i64 * v2);
    this->m_listAvoid.m_pItems = v9;
    if ( !v9 )
      return 52i64;
    this->m_listAvoid.m_ulReserved = v2;
  }
  return 1i64;
}

// File Line: 75
// RVA: 0xA9B220
CAkContainerBaseInfo *__fastcall CAkRandomInfo::Clone(CAkRandomInfo *this, unsigned __int16 in_wItemCount)
{
  _WORD *v5; // rax
  _WORD *v6; // rdi
  int v7; // eax
  int v8; // eax
  __int64 v9; // rbx
  unsigned __int64 v10; // rbp
  char *v11; // rax
  unsigned int m_uLength; // ebx
  void *v13; // rax
  unsigned __int16 *m_pItems; // rbx
  unsigned __int16 v15; // bp
  unsigned __int16 *v16; // rax

  if ( !in_wItemCount )
    return 0i64;
  v5 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  v5[8] = in_wItemCount;
  v5[9] = in_wItemCount;
  *(_QWORD *)v5 = &CAkRandomInfo::`vftable;
  v7 = 50000 * in_wItemCount;
  *((_DWORD *)v6 + 2) = v7;
  *((_DWORD *)v6 + 3) = v7;
  *((_QWORD *)v6 + 3) = 0i64;
  *((_QWORD *)v6 + 4) = 0i64;
  *((_QWORD *)v6 + 5) = 0i64;
  *((_QWORD *)v6 + 6) = 0i64;
  *((_DWORD *)v6 + 2) = this->m_ulTotalWeight;
  *((_DWORD *)v6 + 3) = this->m_ulRemainingWeight;
  v6[8] = this->m_wRemainingItemsToPlay;
  v6[9] = this->m_wCounter;
  if ( this->m_pcArrayBeenPlayedFlag )
  {
    v8 = (in_wItemCount + 7) / 8;
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
    memmove(v11, this->m_pcArrayBeenPlayedFlag, (unsigned int)v10);
  }
  m_uLength = this->m_listAvoid.m_uLength;
  if ( m_uLength )
  {
    v13 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 2i64 * m_uLength);
    *((_QWORD *)v6 + 3) = v13;
    if ( v13 )
      *((_DWORD *)v6 + 9) = m_uLength;
  }
  m_pItems = this->m_listAvoid.m_pItems;
  if ( m_pItems != &m_pItems[this->m_listAvoid.m_uLength] )
  {
    while ( 1 )
    {
      v15 = *m_pItems;
      v16 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast((AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)(v6 + 12));
      if ( !v16 )
        break;
      *v16 = v15;
      if ( ++m_pItems == &this->m_listAvoid.m_pItems[this->m_listAvoid.m_uLength] )
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
  *v2 |= 1 << (in_wPosition & 7);
}

// File Line: 140
// RVA: 0xA9B5D0
unsigned __int8 __fastcall CAkRandomInfo::IsFlagSetPlayed(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  int v2; // r9d

  v2 = this->m_pcArrayBeenPlayedFlag[(unsigned __int64)in_wPosition >> 3];
  return _bittest(&v2, in_wPosition & 7);
}

// File Line: 145
// RVA: 0xA9B600
void __fastcall CAkRandomInfo::ResetFlagsPlayed(CAkRandomInfo *this, unsigned __int64 in_PlaylistSize)
{
  unsigned __int16 v3; // di

  v3 = in_PlaylistSize;
  memset(this->m_pcArrayBeenPlayedFlag, 0, (unsigned int)((in_PlaylistSize + 7) >> 3));
  this->m_wRemainingItemsToPlay = v3;
}

// File Line: 153
// RVA: 0xA9B430
void __fastcall CAkRandomInfo::FlagAsBlocked(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  char *v2; // r9

  v2 = &this->m_pcArrayBlockedFlag[(unsigned __int64)in_wPosition >> 3];
  *v2 |= 1 << (in_wPosition & 7);
}

// File Line: 158
// RVA: 0xA9B460
void __fastcall CAkRandomInfo::FlagAsUnBlocked(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  char *v2; // r9

  v2 = &this->m_pcArrayBlockedFlag[(unsigned __int64)in_wPosition >> 3];
  *v2 &= ~(1 << (in_wPosition & 7));
}

// File Line: 163
// RVA: 0xA9B5A0
unsigned __int8 __fastcall CAkRandomInfo::IsFlagBlocked(CAkRandomInfo *this, unsigned __int16 in_wPosition)
{
  int v2; // r9d

  v2 = this->m_pcArrayBlockedFlag[(unsigned __int64)in_wPosition >> 3];
  return _bittest(&v2, in_wPosition & 7);
}

// File Line: 173
// RVA: 0xA9B4C0
__int64 __fastcall CAkRandomInfo::GetRandomValue(CAkRandomInfo *this)
{
  int v2; // ebx

  v2 = rand() << 15;
  return (v2 + rand()) % this->m_ulRemainingWeight;
}

// File Line: 184
// RVA: 0xA9B180
void __fastcall CAkSequenceInfo::CAkSequenceInfo(CAkSequenceInfo *this)
{
  this->m_bIsForward = 1;
  this->vfptr = (CAkContainerBaseInfoVtbl *)&CAkSequenceInfo::`vftable;
  this->m_i16LastPositionChosen = -1;
}

// File Line: 203
// RVA: 0xA9B3A0
CAkContainerBaseInfo *__fastcall CAkSequenceInfo::Clone(CAkSequenceInfo *this, unsigned __int16 __formal)
{
  CAkContainerBaseInfo *result; // rax

  result = (CAkContainerBaseInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
  if ( result )
  {
    LOBYTE(result[1].vfptr) = 1;
    result->vfptr = (CAkContainerBaseInfoVtbl *)&CAkSequenceInfo::`vftable;
    WORD1(result[1].vfptr) = -1;
    LOBYTE(result[1].vfptr) = this->m_bIsForward;
    WORD1(result[1].vfptr) = this->m_i16LastPositionChosen;
  }
  return result;
}

