// File Line: 24
// RVA: 0xA975F0
void __fastcall CAkActionExcept::CAkActionExcept(CAkActionExcept *this, AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionExcept *v3; // rbx

  v3 = this;
  CAkAction::CAkAction((CAkAction *)&this->vfptr, in_eActionType, in_ulID);
  v3->vfptr = (CAkIndexableVtbl *)&CAkActionExcept::`vftable;
  v3->m_listElementException.m_pItems = 0i64;
  *(_QWORD *)&v3->m_listElementException.m_uLength = 0i64;
}

// File Line: 28
// RVA: 0xA97620
void __fastcall CAkActionExcept::~CAkActionExcept(CAkActionExcept *this)
{
  CAkActionExcept *v1; // rbx
  WwiseObjectIDext *v2; // rdx

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkActionExcept::`vftable;
  v2 = this->m_listElementException.m_pItems;
  if ( v2 )
  {
    this->m_listElementException.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_listElementException.m_pItems = 0i64;
    v1->m_listElementException.m_ulReserved = 0;
  }
  CAkAction::~CAkAction((CAkAction *)&v1->vfptr);
}

// File Line: 33
// RVA: 0xA976E0
signed __int64 __fastcall CAkActionExcept::AddException(CAkActionExcept *this, WwiseObjectIDext in_ulElementID)
{
  WwiseObjectIDext *v2; // rax
  unsigned __int64 v3; // rsi
  AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *v4; // rdi
  signed __int64 i; // rcx
  WwiseObjectIDext *v6; // rbx
  WwiseObjectIDext *v7; // r8
  __int64 v9; // rcx
  WwiseObjectIDext v10; // [rsp+38h] [rbp+10h]

  v10 = in_ulElementID;
  v2 = this->m_listElementException.m_pItems;
  v3 = this->m_listElementException.m_uLength;
  v4 = (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)&this->m_listElementException;
  for ( i = (signed __int64)&v2[v3]; v2 != (WwiseObjectIDext *)i; ++v2 )
  {
    if ( in_ulElementID.id == v2->id && in_ulElementID.bIsBus == v2->bIsBus )
      break;
  }
  v6 = 0i64;
  v7 = 0i64;
  if ( v2 != (WwiseObjectIDext *)i )
    v7 = v2;
  if ( v7 )
    return 1i64;
  if ( v3 < v4->m_ulReserved )
    goto LABEL_12;
  if ( AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
         v4,
         4u) )
  {
    in_ulElementID = v10;
LABEL_12:
    if ( v3 < v4->m_ulReserved )
    {
      v9 = v4->m_uLength;
      v6 = (WwiseObjectIDext *)&v4->m_pItems[v9];
      v4->m_uLength = v9 + 1;
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
  WwiseObjectIDext *v2; // rdi
  signed __int64 v3; // rax

  v2 = this->m_listElementException.m_pItems;
  v3 = (signed __int64)&v2[this->m_listElementException.m_uLength];
  if ( v2 != (WwiseObjectIDext *)v3 )
  {
    do
    {
      if ( in_ulElementID.id == v2->id && in_ulElementID.bIsBus == v2->bIsBus )
        break;
      ++v2;
    }
    while ( v2 != (WwiseObjectIDext *)v3 );
    if ( v2 != (WwiseObjectIDext *)v3 )
    {
      if ( (unsigned __int64)v2 < v3 - 8 )
        qmemcpy(v2, &v2[1], 8 * (((unsigned __int64)(v3 - 8 - (_QWORD)v2 - 1) >> 3) + 1));
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
signed __int64 __fastcall CAkActionExcept::SetExceptParams(CAkActionExcept *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char **v3; // r15
  CAkActionExcept *v4; // rbx
  unsigned int v5; // edi
  WwiseObjectIDext *v6; // rax
  __int64 v7; // rsi
  signed __int64 v8; // rax
  unsigned int v9; // ecx
  unsigned __int64 v10; // r14
  unsigned __int64 v11; // rax
  unsigned int v12; // ebp
  WwiseObjectIDext *v13; // rdi
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rdx
  __int64 v16; // rcx
  WwiseObjectIDext *v17; // rdx
  WwiseObjectIDext v19; // [rsp+40h] [rbp+8h]

  v3 = io_rpData;
  v4 = this;
  v5 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  if ( !v5 )
    return 1i64;
  v6 = (WwiseObjectIDext *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v5);
  v4->m_listElementException.m_pItems = v6;
  if ( v6 )
  {
    v4->m_listElementException.m_ulReserved = v5;
    if ( v5 )
    {
      v7 = v5;
      while ( 1 )
      {
        v8 = (signed __int64)(*v3 + 4);
        v9 = *(_DWORD *)*v3;
        *v3 = (char *)v8++;
        v19.id = v9;
        LOBYTE(v9) = *(_BYTE *)(v8 - 1);
        *v3 = (char *)v8;
        v10 = v4->m_listElementException.m_uLength;
        v11 = v4->m_listElementException.m_ulReserved;
        v19.bIsBus = (_BYTE)v9 != 0;
        if ( v10 < v11 )
          goto LABEL_12;
        v12 = v11 + 4;
        v13 = (WwiseObjectIDext *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(v11 + 4));
        if ( v13 )
          break;
LABEL_15:
        if ( !--v7 )
          return 1i64;
      }
      v14 = v4->m_listElementException.m_uLength;
      if ( v4->m_listElementException.m_pItems )
      {
        v15 = 0i64;
        if ( v4->m_listElementException.m_uLength )
        {
          do
          {
            ++v15;
            v13[v15 - 1] = v4->m_listElementException.m_pItems[v15 - 1];
          }
          while ( v15 < v14 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v4->m_listElementException.m_pItems);
      }
      v4->m_listElementException.m_pItems = v13;
      v4->m_listElementException.m_ulReserved = v12;
LABEL_12:
      if ( v10 < v4->m_listElementException.m_ulReserved )
      {
        v16 = v4->m_listElementException.m_uLength;
        v17 = &v4->m_listElementException.m_pItems[v16];
        v4->m_listElementException.m_uLength = v16 + 1;
        if ( v17 )
          *v17 = v19;
      }
      goto LABEL_15;
    }
    return 1i64;
  }
  return 2i64;
}

