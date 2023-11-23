// File Line: 28
// RVA: 0xA58DF0
void __fastcall CAkPathManager::CAkPathManager(CAkPathManager *this)
{
  this->m_ActivePathsList.m_pItems = 0i64;
  *(_QWORD *)&this->m_ActivePathsList.m_uLength = 0i64;
  this->m_uMaxPathNumber = 0;
}

// File Line: 39
// RVA: 0xA58F30
__int64 __fastcall CAkPathManager::Init(CAkPathManager *this, unsigned int in_uMaxNumPath)
{
  unsigned int v2; // ebx
  CAkPath **v4; // rax

  v2 = 255;
  if ( in_uMaxNumPath )
    v2 = in_uMaxNumPath;
  this->m_uMaxPathNumber = v2;
  v4 = (CAkPath **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v2);
  this->m_ActivePathsList.m_pItems = v4;
  if ( !v4 )
    return 52i64;
  this->m_ActivePathsList.m_ulReserved = v2;
  return 1i64;
}

// File Line: 47
// RVA: 0xA59290
void __fastcall CAkPathManager::Term(CAkPathManager *this)
{
  CAkPath **i; // rbx
  CAkPath *v3; // rdi
  int v4; // ebp

  for ( i = this->m_ActivePathsList.m_pItems; i != &this->m_ActivePathsList.m_pItems[this->m_ActivePathsList.m_uLength]; ++i )
  {
    v3 = *i;
    CAkPath::Term(*i);
    v4 = g_DefaultPoolId;
    if ( v3 )
    {
      _((AMD_HD3D *)v3);
      AK::MemoryMgr::Free(v4, v3);
    }
  }
  if ( this->m_ActivePathsList.m_pItems )
  {
    this->m_ActivePathsList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_ActivePathsList.m_pItems);
    this->m_ActivePathsList.m_pItems = 0i64;
    this->m_ActivePathsList.m_ulReserved = 0;
  }
}

// File Line: 62
// RVA: 0xA58E00
void __fastcall CAkPathManager::AddPathToList(CAkPathManager *this)
{
  CAkPath *v2; // rax
  AMD_HD3D *v3; // rax
  AMD_HD3D *v4; // rdi
  __int64 m_uLength; // rax
  CAkPath **v6; // r8
  int v7; // ebx

  if ( this->m_ActivePathsList.m_uLength < this->m_uMaxPathNumber )
  {
    v2 = (CAkPath *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x88ui64);
    if ( v2 )
    {
      CAkPath::CAkPath(v2);
      v4 = v3;
      if ( v3 )
      {
        m_uLength = this->m_ActivePathsList.m_uLength;
        if ( (unsigned int)m_uLength < this->m_ActivePathsList.m_ulReserved
          && (v6 = &this->m_ActivePathsList.m_pItems[m_uLength], this->m_ActivePathsList.m_uLength = m_uLength + 1, v6) )
        {
          *v6 = (CAkPath *)v4;
        }
        else
        {
          v7 = g_DefaultPoolId;
          _(v4);
          AK::MemoryMgr::Free(v7, v4);
        }
      }
    }
  }
}

// File Line: 90
// RVA: 0xA59030
__int64 __fastcall CAkPathManager::RemovePathFromList(CAkPathManager *this, CAkPath *in_pPath)
{
  CAkPath **m_pItems; // rax
  __int64 m_uLength; // rcx
  CAkPath **v5; // r8
  CAkPath *v6; // rbx
  int v7; // edi

  m_pItems = this->m_ActivePathsList.m_pItems;
  m_uLength = this->m_ActivePathsList.m_uLength;
  v5 = &m_pItems[m_uLength];
  if ( m_pItems == v5 )
    return 36i64;
  do
  {
    if ( *m_pItems == in_pPath )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v5 );
  if ( m_pItems == v5 )
    return 36i64;
  v6 = *m_pItems;
  if ( (unsigned int)m_uLength > 1 )
    *m_pItems = *(v5 - 1);
  --this->m_ActivePathsList.m_uLength;
  CAkPath::Term(v6);
  v7 = g_DefaultPoolId;
  if ( v6 )
  {
    _((AMD_HD3D *)v6);
    AK::MemoryMgr::Free(v7, v6);
  }
  return 1i64;
}

// File Line: 119
// RVA: 0xA58EA0
__int64 __fastcall CAkPathManager::AddPathUser(CAkPathManager *this, CAkPath *in_pPath, ITransitionable *in_pPBI)
{
  CAkPBI **m_pItems; // rax
  CAkPBI **i; // r9
  CAkPBI **v6; // rdx

  if ( in_pPath->m_PBIsList.m_uLength >= 8 )
    return 2i64;
  m_pItems = in_pPath->m_PBIsList.m_pItems;
  for ( i = &m_pItems[in_pPath->m_PBIsList.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( *m_pItems == (CAkPBI *)in_pPBI )
      break;
  }
  v6 = 0i64;
  if ( m_pItems != i )
    v6 = m_pItems;
  if ( v6
    || !AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(
          (AkArray<ITransitionable *,ITransitionable *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&in_pPath->m_PBIsList,
          in_pPBI) )
  {
    return 40i64;
  }
  ++in_pPath->m_iNumUsers;
  return 1i64;
}

// File Line: 155
// RVA: 0xA590C0
__int64 __fastcall CAkPathManager::RemovePathUser(CAkPathManager *this, CAkPath *in_pPath, CAkPBI *in_pPBI)
{
  CAkPBI **m_pItems; // rax
  __int64 m_uLength; // r10
  CAkPBI **v5; // r9

  m_pItems = in_pPath->m_PBIsList.m_pItems;
  m_uLength = in_pPath->m_PBIsList.m_uLength;
  v5 = &m_pItems[m_uLength];
  if ( m_pItems == v5 )
    return 41i64;
  do
  {
    if ( *m_pItems == in_pPBI )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v5 );
  if ( m_pItems == v5 )
    return 41i64;
  if ( (unsigned int)m_uLength > 1 )
    *m_pItems = *(v5 - 1);
  --in_pPath->m_PBIsList.m_uLength;
  --in_pPath->m_iNumUsers;
  if ( in_pPath->m_iPotentialUsers || in_pPath->m_iNumUsers )
    return 1i64;
  else
    return CAkPathManager::RemovePathFromList(this, in_pPath);
}

// File Line: 190
// RVA: 0xA58F20
void __fastcall CAkPathManager::AddPotentialUser(CAkPathManager *this, CAkPath *in_pPath)
{
  ++in_pPath->m_iPotentialUsers;
}

// File Line: 207
// RVA: 0xA59120
__int64 __fastcall CAkPathManager::RemovePotentialUser(CAkPathManager *this, CAkPath *in_pPath)
{
  char m_iPotentialUsers; // al

  m_iPotentialUsers = in_pPath->m_iPotentialUsers;
  if ( m_iPotentialUsers )
    in_pPath->m_iPotentialUsers = m_iPotentialUsers - 1;
  if ( in_pPath->m_iPotentialUsers || in_pPath->m_iNumUsers )
    return 1i64;
  else
    return CAkPathManager::RemovePathFromList(this, in_pPath);
}

// File Line: 244
// RVA: 0xA59190
AKRESULT __fastcall CAkPathManager::SetPathsList(
        CAkPathManager *this,
        CAkPath *in_pPath,
        AkPathListItem *in_pPathList,
        unsigned int in_ulListSize,
        AkPathMode in_PathMode,
        bool in_bIsLooping,
        AkPathState *in_pState)
{
  if ( in_pPathList && in_ulListSize )
    return CAkPath::SetPathsList(in_pPath, in_pPathList, in_ulListSize, in_PathMode, in_bIsLooping, in_pState);
  else
    return 31;
}

// File Line: 259
// RVA: 0xA591E0
AKRESULT __fastcall CAkPathManager::Start(CAkPathManager *this, CAkPath *in_pPath, AkPathState *in_pState)
{
  bool *pbPlayed; // rax
  __int64 ulCurrentListIndex_low; // rax
  AKRESULT result; // eax
  AKRESULT v8; // esi

  if ( in_pPath->m_eState )
    return 2;
  if ( in_pPath->m_bWasStarted )
  {
    CAkPath::UpdateStartPosition(in_pPath);
    return 2;
  }
  pbPlayed = in_pState->pbPlayed;
  if ( pbPlayed )
  {
    in_pPath->m_pbPlayed = pbPlayed;
    ulCurrentListIndex_low = LOWORD(in_pState->ulCurrentListIndex);
    in_pPath->m_ulCurrentListIndex = ulCurrentListIndex_low;
    in_pPath->m_pCurrentList = &in_pPath->m_pPathsList[ulCurrentListIndex_low];
  }
  result = CAkPath::Start(in_pPath, g_pAudioMgr->m_uBufferTick);
  v8 = result;
  if ( (in_pPath->m_PathMode & 2) == 0 )
  {
    CAkPath::GetNextPathList(in_pPath);
    in_pState->ulCurrentListIndex = in_pPath->m_ulCurrentListIndex;
    in_pState->pbPlayed = in_pPath->m_pbPlayed;
    return v8;
  }
  return result;
}

// File Line: 315
// RVA: 0xA58F90
__int64 __fastcall CAkPathManager::Pause(CAkPathManager *this, CAkPath *in_pPath)
{
  if ( in_pPath->m_eState != Running )
    return 38i64;
  CAkPath::Pause(in_pPath, g_pAudioMgr->m_uBufferTick);
  return 1i64;
}

// File Line: 335
// RVA: 0xA59150
__int64 __fastcall CAkPathManager::Resume(CAkPathManager *this, CAkPath *in_pPath)
{
  if ( in_pPath->m_eState != Suspended )
    return 39i64;
  CAkPath::Resume(in_pPath, g_pAudioMgr->m_uBufferTick);
  return 1i64;
}

// File Line: 355
// RVA: 0xA58FD0
void __fastcall CAkPathManager::ProcessPathsList(CAkPathManager *this, unsigned int in_uCurrentBufferTick)
{
  CAkPath **i; // rbx

  for ( i = this->m_ActivePathsList.m_pItems; i != &this->m_ActivePathsList.m_pItems[this->m_ActivePathsList.m_uLength]; ++i )
  {
    if ( (*i)->m_eState == Running )
      CAkPath::UpdatePosition(*i, in_uCurrentBufferTick);
  }
}

