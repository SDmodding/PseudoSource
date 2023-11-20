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
signed __int64 __fastcall CAkPathManager::Init(CAkPathManager *this, unsigned int in_uMaxNumPath)
{
  unsigned int v2; // ebx
  CAkPathManager *v3; // rdi
  CAkPath **v4; // rax

  v2 = 255;
  v3 = this;
  if ( in_uMaxNumPath )
    v2 = in_uMaxNumPath;
  this->m_uMaxPathNumber = v2;
  if ( v2 )
  {
    v4 = (CAkPath **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v2);
    v3->m_ActivePathsList.m_pItems = v4;
    if ( !v4 )
      return 52i64;
    v3->m_ActivePathsList.m_ulReserved = v2;
  }
  return 1i64;
}

// File Line: 47
// RVA: 0xA59290
void __fastcall CAkPathManager::Term(CAkPathManager *this)
{
  CAkPath **v1; // rbx
  CAkPathManager *i; // rsi
  CAkPath *v3; // rdi
  int v4; // ebp

  v1 = this->m_ActivePathsList.m_pItems;
  for ( i = this; v1 != &i->m_ActivePathsList.m_pItems[i->m_ActivePathsList.m_uLength]; ++v1 )
  {
    v3 = *v1;
    CAkPath::Term(*v1);
    v4 = g_DefaultPoolId;
    if ( v3 )
    {
      _((AMD_HD3D *)v3);
      AK::MemoryMgr::Free(v4, v3);
    }
  }
  if ( i->m_ActivePathsList.m_pItems )
  {
    i->m_ActivePathsList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, i->m_ActivePathsList.m_pItems);
    i->m_ActivePathsList.m_pItems = 0i64;
    i->m_ActivePathsList.m_ulReserved = 0;
  }
}

// File Line: 62
// RVA: 0xA58E00
void __fastcall CAkPathManager::AddPathToList(CAkPathManager *this)
{
  CAkPathManager *v1; // rbx
  CAkPath *v2; // rax
  AMD_HD3D *v3; // rax
  AMD_HD3D *v4; // rdi
  __int64 v5; // rax
  AMD_HD3D **v6; // r8
  int v7; // ebx

  v1 = this;
  if ( this->m_ActivePathsList.m_uLength < this->m_uMaxPathNumber )
  {
    v2 = (CAkPath *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x88ui64);
    if ( v2 )
    {
      CAkPath::CAkPath(v2);
      v4 = v3;
      if ( v3 )
      {
        v5 = v1->m_ActivePathsList.m_uLength;
        if ( (unsigned int)v5 < v1->m_ActivePathsList.m_ulReserved
          && (v6 = (AMD_HD3D **)&v1->m_ActivePathsList.m_pItems[v5], v1->m_ActivePathsList.m_uLength = v5 + 1, v6) )
        {
          *v6 = v4;
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
signed __int64 __fastcall CAkPathManager::RemovePathFromList(CAkPathManager *this, CAkPath *in_pPath)
{
  CAkPath **v2; // rax
  CAkPathManager *v3; // r9
  __int64 v4; // rcx
  signed __int64 v5; // r8
  CAkPath *v6; // rbx
  int v7; // edi

  v2 = this->m_ActivePathsList.m_pItems;
  v3 = this;
  v4 = this->m_ActivePathsList.m_uLength;
  v5 = (signed __int64)&v2[v4];
  if ( v2 == (CAkPath **)v5 )
    return 36i64;
  do
  {
    if ( *v2 == in_pPath )
      break;
    ++v2;
  }
  while ( v2 != (CAkPath **)v5 );
  if ( v2 == (CAkPath **)v5 )
    return 36i64;
  v6 = *v2;
  if ( (unsigned int)v4 > 1 )
    *v2 = *(CAkPath **)(v5 - 8);
  --v3->m_ActivePathsList.m_uLength;
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
signed __int64 __fastcall CAkPathManager::AddPathUser(CAkPathManager *this, CAkPath *in_pPath, CAkPBI *in_pPBI)
{
  CAkPath *v3; // rbx
  CAkPBI **v4; // rax
  signed __int64 i; // r9
  CAkPBI **v6; // rdx

  v3 = in_pPath;
  if ( in_pPath->m_PBIsList.m_uLength >= 8 )
    return 2i64;
  v4 = in_pPath->m_PBIsList.m_pItems;
  for ( i = (signed __int64)&v4[in_pPath->m_PBIsList.m_uLength]; v4 != (CAkPBI **)i; ++v4 )
  {
    if ( *v4 == in_pPBI )
      break;
  }
  v6 = 0i64;
  if ( v4 != (CAkPBI **)i )
    v6 = v4;
  if ( v6
    || !AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(
          (AkArray<ITransitionable *,ITransitionable *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&v3->m_PBIsList,
          (ITransitionable *)in_pPBI) )
  {
    return 40i64;
  }
  ++v3->m_iNumUsers;
  return 1i64;
}

// File Line: 155
// RVA: 0xA590C0
signed __int64 __fastcall CAkPathManager::RemovePathUser(CAkPathManager *this, CAkPath *in_pPath, CAkPBI *in_pPBI)
{
  CAkPBI **v3; // rax
  __int64 v4; // r10
  signed __int64 v5; // r9
  signed __int64 result; // rax

  v3 = in_pPath->m_PBIsList.m_pItems;
  v4 = in_pPath->m_PBIsList.m_uLength;
  v5 = (signed __int64)&v3[v4];
  if ( v3 == (CAkPBI **)v5 )
    return 41i64;
  do
  {
    if ( *v3 == in_pPBI )
      break;
    ++v3;
  }
  while ( v3 != (CAkPBI **)v5 );
  if ( v3 == (CAkPBI **)v5 )
    return 41i64;
  if ( (unsigned int)v4 > 1 )
    *v3 = *(CAkPBI **)(v5 - 8);
  --in_pPath->m_PBIsList.m_uLength;
  --in_pPath->m_iNumUsers;
  if ( *(_WORD *)&in_pPath->m_iPotentialUsers )
    result = 1i64;
  else
    result = CAkPathManager::RemovePathFromList(this, in_pPath);
  return result;
}

// File Line: 190
// RVA: 0xA58F20
void __fastcall CAkPathManager::AddPotentialUser(CAkPathManager *this, CAkPath *in_pPath)
{
  ++in_pPath->m_iPotentialUsers;
}

// File Line: 207
// RVA: 0xA59120
signed __int64 __fastcall CAkPathManager::RemovePotentialUser(CAkPathManager *this, CAkPath *in_pPath)
{
  char v2; // al

  v2 = in_pPath->m_iPotentialUsers;
  if ( v2 )
    in_pPath->m_iPotentialUsers = v2 - 1;
  if ( !in_pPath->m_iPotentialUsers )
    JUMPOUT(in_pPath->m_iNumUsers, 0, CAkPathManager::RemovePathFromList);
  return 1i64;
}

// File Line: 244
// RVA: 0xA59190
AKRESULT __fastcall CAkPathManager::SetPathsList(CAkPathManager *this, CAkPath *in_pPath, AkPathListItem *in_pPathList, unsigned int in_ulListSize, AkPathMode in_PathMode, bool in_bIsLooping, AkPathState *in_pState)
{
  AKRESULT result; // eax

  if ( in_pPathList && in_ulListSize )
    result = CAkPath::SetPathsList(in_pPath, in_pPathList, in_ulListSize, in_PathMode, in_bIsLooping, in_pState);
  else
    result = 31;
  return result;
}

// File Line: 259
// RVA: 0xA591E0
AKRESULT __fastcall CAkPathManager::Start(CAkPathManager *this, CAkPath *in_pPath, AkPathState *in_pState)
{
  AkPathState *v3; // rdi
  CAkPath *v4; // rbx
  bool *v5; // rax
  __int64 v6; // rax
  AKRESULT result; // eax
  AKRESULT v8; // esi

  v3 = in_pState;
  v4 = in_pPath;
  if ( in_pPath->m_eState )
    return 2;
  if ( in_pPath->m_bWasStarted )
  {
    CAkPath::UpdateStartPosition(in_pPath);
    return 2;
  }
  v5 = in_pState->pbPlayed;
  if ( v5 )
  {
    in_pPath->m_pbPlayed = v5;
    v6 = LOWORD(in_pState->ulCurrentListIndex);
    in_pPath->m_ulCurrentListIndex = v6;
    in_pPath->m_pCurrentList = &in_pPath->m_pPathsList[v6];
  }
  result = CAkPath::Start(in_pPath, g_pAudioMgr->m_uBufferTick);
  v8 = result;
  if ( !(v4->m_PathMode & 2) )
  {
    CAkPath::GetNextPathList(v4);
    v3->ulCurrentListIndex = v4->m_ulCurrentListIndex;
    v3->pbPlayed = v4->m_pbPlayed;
    result = v8;
  }
  return result;
}

// File Line: 315
// RVA: 0xA58F90
signed __int64 __fastcall CAkPathManager::Pause(CAkPathManager *this, CAkPath *in_pPath)
{
  if ( in_pPath->m_eState != 1 )
    return 38i64;
  CAkPath::Pause(in_pPath, g_pAudioMgr->m_uBufferTick);
  return 1i64;
}

// File Line: 335
// RVA: 0xA59150
signed __int64 __fastcall CAkPathManager::Resume(CAkPathManager *this, CAkPath *in_pPath)
{
  if ( in_pPath->m_eState != 2 )
    return 39i64;
  CAkPath::Resume(in_pPath, g_pAudioMgr->m_uBufferTick);
  return 1i64;
}

// File Line: 355
// RVA: 0xA58FD0
void __fastcall CAkPathManager::ProcessPathsList(CAkPathManager *this, unsigned int in_uCurrentBufferTick)
{
  CAkPath **v2; // rbx
  unsigned int v3; // esi
  CAkPathManager *i; // rdi

  v2 = this->m_ActivePathsList.m_pItems;
  v3 = in_uCurrentBufferTick;
  for ( i = this; v2 != &i->m_ActivePathsList.m_pItems[i->m_ActivePathsList.m_uLength]; ++v2 )
  {
    if ( (*v2)->m_eState == 1 )
      CAkPath::UpdatePosition(*v2, v3);
  }
}

