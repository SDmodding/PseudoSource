// File Line: 24
// RVA: 0xA975F0
void __fastcall CAkActionExcept::CAkActionExcept(
        CAkActionExcept *this,
        AkActionType in_eActionType,
        unsigned int in_ulID)
{
  CAkAction::CAkAction(this, in_eActionType, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkActionExcept::`vftable;
  this->m_listElementException.m_pItems = 0i64;
  *(_QWORD *)&this->m_listElementException.m_uLength = 0i64;
}

// File Line: 28
// RVA: 0xA97620
void __fastcall CAkActionExcept::~CAkActionExcept(CAkActionExcept *this)
{
  WwiseObjectIDext *m_pItems; // rdx

  this->vfptr = (CAkIndexableVtbl *)&CAkActionExcept::`vftable;
  m_pItems = this->m_listElementException.m_pItems;
  if ( m_pItems )
  {
    this->m_listElementException.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_listElementException.m_pItems = 0i64;
    this->m_listElementException.m_ulReserved = 0;
  }
  CAkAction::~CAkAction(this);
}

// File Line: 33
// RVA: 0xA976E0
__int64 __fastcall CAkActionExcept::AddException(CAkActionExcept *this, WwiseObjectIDext in_ulElementID)
{
  WwiseObjectIDext *m_pItems; // rax
  unsigned __int64 m_uLength; // rsi
  AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *p_m_listElementException; // rdi
  WwiseObjectIDext *i; // rcx
  WwiseObjectIDext *v6; // rbx
  WwiseObjectIDext *v7; // r8
  __int64 v9; // rcx
  WwiseObjectIDext v10; // [rsp+38h] [rbp+10h]

  v10 = in_ulElementID;
  m_pItems = this->m_listElementException.m_pItems;
  m_uLength = this->m_listElementException.m_uLength;
  p_m_listElementException = (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)&this->m_listElementException;
  for ( i = &m_pItems[m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( in_ulElementID.id == m_pItems->id && in_ulElementID.bIsBus == m_pItems->bIsBus )
      break;
  }
  v6 = 0i64;
  v7 = 0i64;
  if ( m_pItems != i )
    v7 = m_pItems;
  if ( v7 )
    return 1i64;
  if ( m_uLength < p_m_listElementException->m_ulReserved )
    goto LABEL_12;
  if ( AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
         p_m_listElementException,
         4u) )
  {
    in_ulElementID = v10;
LABEL_12:
    if ( m_uLength < p_m_listElementException->m_ulReserved )
    {
      v9 = p_m_listElementException->m_uLength;
      v6 = (WwiseObjectIDext *)&p_m_listElementException->m_pItems[v9];
      p_m_listElementException->m_uLength = v9 + 1;
      if ( v6 )
        *v6 = in_ulElementID;
    }
  }
  return 2 - (unsigned int)(v6 != 0i64);
}

// File Line: 41
// RVA: 0xA977B0
void __fastcall CAkActionExcept::RemoveException(CAkActionExcept *this, WwiseObjectIDext in_ulElementID)
{
  WwiseObjectIDext *m_pItems; // rdi
  WwiseObjectIDext *v3; // rax

  m_pItems = this->m_listElementException.m_pItems;
  v3 = &m_pItems[this->m_listElementException.m_uLength];
  if ( m_pItems != v3 )
  {
    do
    {
      if ( in_ulElementID.id == m_pItems->id && in_ulElementID.bIsBus == m_pItems->bIsBus )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v3 );
    if ( m_pItems != v3 )
    {
      if ( m_pItems < &v3[-1] )
        qmemcpy(m_pItems, &m_pItems[1], 8 * (((unsigned __int64)((char *)&v3[-1] - (char *)m_pItems - 1) >> 3) + 1));
      --this->m_listElementException.m_uLength;
    }
  }
}

// File Line: 46
// RVA: 0xA977A0
void __fastcall CAkActionExcept::ClearExceptions(CAkActionExcept *this)
{
  this->m_listElementException.m_uLength = 0;
}

// File Line: 51
// RVA: 0xA97820
__int64 __fastcall CAkActionExcept::SetExceptParams(
        CAkActionExcept *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  unsigned int v5; // edi
  WwiseObjectIDext *v6; // rax
  __int64 v7; // rsi
  char *v8; // rax
  unsigned int v9; // ecx
  unsigned __int64 m_uLength; // r14
  unsigned __int64 m_ulReserved; // rax
  unsigned int v12; // ebp
  WwiseObjectIDext *v13; // rdi
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rdx
  __int64 v16; // rcx
  WwiseObjectIDext *v17; // rdx
  WwiseObjectIDext v19; // [rsp+40h] [rbp+8h]

  v5 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  if ( !v5 )
    return 1i64;
  v6 = (WwiseObjectIDext *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v5);
  this->m_listElementException.m_pItems = v6;
  if ( v6 )
  {
    this->m_listElementException.m_ulReserved = v5;
    v7 = v5;
    while ( 1 )
    {
      v8 = *io_rpData + 4;
      v9 = *(_DWORD *)*io_rpData;
      *io_rpData = v8++;
      v19.id = v9;
      LOBYTE(v9) = *(v8 - 1);
      *io_rpData = v8;
      m_uLength = this->m_listElementException.m_uLength;
      m_ulReserved = this->m_listElementException.m_ulReserved;
      v19.bIsBus = (_BYTE)v9 != 0;
      if ( m_uLength < m_ulReserved )
        goto LABEL_11;
      v12 = m_ulReserved + 4;
      v13 = (WwiseObjectIDext *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(m_ulReserved + 4));
      if ( v13 )
        break;
LABEL_14:
      if ( !--v7 )
        return 1i64;
    }
    v14 = this->m_listElementException.m_uLength;
    if ( this->m_listElementException.m_pItems )
    {
      v15 = 0i64;
      if ( this->m_listElementException.m_uLength )
      {
        do
        {
          ++v15;
          v13[v15 - 1] = this->m_listElementException.m_pItems[v15 - 1];
        }
        while ( v15 < v14 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, this->m_listElementException.m_pItems);
    }
    this->m_listElementException.m_pItems = v13;
    this->m_listElementException.m_ulReserved = v12;
LABEL_11:
    if ( m_uLength < this->m_listElementException.m_ulReserved )
    {
      v16 = this->m_listElementException.m_uLength;
      v17 = &this->m_listElementException.m_pItems[v16];
      this->m_listElementException.m_uLength = v16 + 1;
      if ( v17 )
        *v17 = v19;
    }
    goto LABEL_14;
  }
  return 2i64;
}

