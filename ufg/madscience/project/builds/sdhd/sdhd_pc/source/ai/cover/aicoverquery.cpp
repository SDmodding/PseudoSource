// File Line: 52
// RVA: 0x14AD0E0
void (__fastcall *dynamic_initializer_for__UFG::AICoverQuery::ms_aStateInfo__())(UFG::AICoverQuery *this)
{
  __int128 v0; // xmm0
  __int128 v1; // xmm0
  __int64 v2; // rax
  __int128 v3; // xmm0
  __int128 v4; // xmm0
  __int64 v5; // rax
  __int128 v6; // xmm0
  __int128 v7; // xmm0
  __int64 v8; // rax
  __int128 v9; // xmm0
  __int128 v10; // xmm0
  __int128 v11; // xmm0
  __int128 v12; // xmm0
  __int64 v13; // rax
  __int64 v14; // rax
  __int128 v15; // xmm0
  __int128 v16; // xmm0
  __int64 v17; // rax
  __int64 v18; // rax
  __int128 v19; // xmm0
  void (__fastcall *result)(UFG::AICoverQuery *); // rax
  __int128 v21; // [rsp+0h] [rbp-10h]

  DWORD2(v21) = 0;
  *(_QWORD *)&v21 = 0i64;
  qword_14206DAA8 = (__int64)UFG::AICoverQuery::SetupSensor;
  v0 = v21;
  *(_QWORD *)&v21 = UFG::AICoverQuery::InitializeQuery;
  DWORD2(v21) = 0;
  *(_OWORD *)&UFG::AICoverQuery::ms_aStateInfo[0].m_InitFunc = v0;
  v1 = v21;
  v2 = *((_QWORD *)&v21 + 1);
  DWORD2(v21) = 0;
  xmmword_14206DA80 = v1;
  qword_14206DAA0 = v2;
  qword_14206DAB0 = *((_QWORD *)&v21 + 1);
  *(_QWORD *)&v21 = 0i64;
  qword_14206DAE8 = (__int64)UFG::AICoverQuery::InitFindParkourSyncs;
  v3 = v21;
  DWORD2(v21) = 0;
  xmmword_14206DAC0 = v3;
  *(_QWORD *)&v21 = UFG::AICoverQuery::GatherInRange;
  qword_14206DAF8 = (__int64)UFG::AICoverQuery::FindParkourSyncs;
  v4 = v21;
  DWORD2(v21) = 0;
  xmmword_14206DAD0 = v4;
  qword_14206DAF0 = *((_QWORD *)&v21 + 1);
  v5 = *((_QWORD *)&v21 + 1);
  DWORD2(v21) = 0;
  qword_14206DB00 = v5;
  qword_14206DB38 = (__int64)UFG::AICoverQuery::InitProcessConnections;
  *(_QWORD *)&v21 = UFG::AICoverQuery::InitProcessObstructions;
  v6 = v21;
  *(_QWORD *)&v21 = UFG::AICoverQuery::ProcessObstructions;
  qword_14206DB48 = (__int64)UFG::AICoverQuery::ProcessConnections;
  xmmword_14206DB10 = v6;
  v7 = v21;
  DWORD2(v21) = 0;
  xmmword_14206DB20 = v7;
  qword_14206DB40 = *((_QWORD *)&v21 + 1);
  v8 = *((_QWORD *)&v21 + 1);
  DWORD2(v21) = 0;
  qword_14206DB50 = v8;
  *(_QWORD *)&v21 = UFG::AICoverQuery::InitGetCoverPositions;
  qword_14206DB88 = (__int64)UFG::AICoverQuery::DetailedCullInit;
  v9 = v21;
  *(_QWORD *)&v21 = UFG::AICoverQuery::GetCoverPositions;
  xmmword_14206DB60 = v9;
  v10 = v21;
  DWORD2(v21) = 0;
  xmmword_14206DB70 = v10;
  qword_14206DB90 = *((_QWORD *)&v21 + 1);
  qword_14206DA98 = 0i64;
  qword_14206DBA0 = *((_QWORD *)&v21 + 1);
  qword_14206DB98 = (__int64)UFG::AICoverQuery::DetailedCull;
  *(_QWORD *)&v21 = UFG::AICoverQuery::PrioritizePointsInit;
  DWORD2(v21) = 0;
  v11 = v21;
  DWORD2(v21) = 0;
  *(_QWORD *)&v21 = UFG::AICoverQuery::PrioritizePoints;
  qword_14206DC28 = 0i64;
  xmmword_14206DBB0 = v11;
  v12 = v21;
  DWORD2(v21) = 0;
  v13 = *((_QWORD *)&v21 + 1);
  DWORD2(v21) = 0;
  xmmword_14206DBC0 = v12;
  qword_14206DBE0 = v13;
  v14 = *((_QWORD *)&v21 + 1);
  DWORD2(v21) = 0;
  *(_QWORD *)&v21 = 0i64;
  qword_14206DBF0 = v14;
  v15 = v21;
  *(_QWORD *)&v21 = UFG::AICoverQuery::PathTestInit;
  DWORD2(v21) = 0;
  qword_14206DBD8 = (__int64)UFG::AICoverQuery::TestDirectPathInit;
  xmmword_14206DC00 = v15;
  v16 = v21;
  DWORD2(v21) = 0;
  v17 = *((_QWORD *)&v21 + 1);
  DWORD2(v21) = 0;
  xmmword_14206DC10 = v16;
  *(_QWORD *)&v21 = 0i64;
  qword_14206DC30 = v17;
  v18 = *((_QWORD *)&v21 + 1);
  DWORD2(v21) = 0;
  qword_14206DC40 = v18;
  v19 = v21;
  result = UFG::AICoverQuery::ChooseBest;
  DWORD2(v21) = 0;
  qword_14206DBE8 = (__int64)UFG::AICoverQuery::PathTestInit;
  xmmword_14206DC50 = v19;
  *(_QWORD *)&v21 = UFG::AICoverQuery::ChooseBest;
  qword_14206DC38 = (__int64)UFG::AICoverQuery::PathTest;
  xmmword_14206DC60 = v21;
  return result;
}

// File Line: 106
// RVA: 0x356A50
__int64 __fastcall UFG::AICoverQuery::CoverQueryRecord::FindMeshPos(UFG::AICoverQuery::CoverQueryRecord *this)
{
  UFG::CoverPosition *m_pCoverPosition; // rbx
  UFG::qVector3 *v3; // rax
  float z; // xmm1_4
  float y; // xmm0_4
  char v7; // [rsp+20h] [rbp-18h] BYREF

  m_pCoverPosition = this->m_pCoverPosition;
  v3 = m_pCoverPosition->vfptr->GetSyncPos(m_pCoverPosition, (UFG::qVector3 *)&v7);
  z = v3->z;
  y = v3->y;
  m_pCoverPosition->m_NavPosition.m_vPosition.x = v3->x;
  m_pCoverPosition->m_NavPosition.m_vPosition.z = z;
  m_pCoverPosition->m_NavPosition.m_vPosition.y = y;
  m_pCoverPosition->m_NavPosition.m_bValid = 0;
  ((void (__fastcall *)(UFG::HavokNavPosition *))m_pCoverPosition->m_NavPosition.vfptr->Validate)(&m_pCoverPosition->m_NavPosition);
  return ((__int64 (__fastcall *)(UFG::HavokNavPosition *))this->m_pCoverPosition->m_NavPosition.vfptr->IsMeshPositionValid)(&this->m_pCoverPosition->m_NavPosition);
}

// File Line: 120
// RVA: 0x32B170
void __fastcall UFG::AICoverQuery::AICoverQuery(UFG::AICoverQuery *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIQuery::`vftable;
  this->m_bStateNeedsInit = 1;
  *(_QWORD *)&this->m_iRefCount = 0i64;
  this->mPrev = &this->UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery>;
  this->mNext = &this->UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery>;
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AICoverQuery::`vftable;
  this->m_npQueryCenter.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_npQueryCenter.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npQueryCenter.m_vPosition.y = y;
  this->m_npQueryCenter.m_vPosition.z = z;
  this->m_npQueryCenter.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npQueryCenter.m_bValid = 0;
  this->m_npQueryCenter.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&this->m_npQueryCenter.m_packedKey = -1i64;
  this->m_pSearchParams = 0i64;
  this->m_pParkourQuery = 0i64;
  this->m_aCoverObjects.p = 0i64;
  *(_QWORD *)&this->m_aCoverObjects.size = 0i64;
  this->m_aCoverPositions.p = 0i64;
  *(_QWORD *)&this->m_aCoverPositions.size = 0i64;
  this->m_aCulledObjects.p = 0i64;
  *(_QWORD *)&this->m_aCulledObjects.size = 0i64;
  this->m_aCoverGroups.p = 0i64;
  *(_QWORD *)&this->m_aCoverGroups.size = 0i64;
  this->m_aQueryRecords.p = 0i64;
  *(_QWORD *)&this->m_aQueryRecords.size = 0i64;
  this->m_vAllyAvoidancePositions.p = 0i64;
  *(_QWORD *)&this->m_vAllyAvoidancePositions.size = 0i64;
  this->m_pBestCoverPosition = 0i64;
  this->m_queryFinishedDelegate.m_Closure.m_pthis = 0i64;
  this->m_queryFinishedDelegate.m_Closure.m_pFunction = 0i64;
  this->m_pConstraint = 0i64;
  this->m_fInitialPathCost = 0.0;
  this->m_iBestCoverIndex = -1;
  this->m_fBestCoverScore = -3.4028235e38;
  this->m_pFoundPath.m_pNavPath = 0i64;
}

// File Line: 151
// RVA: 0x333F20
void __fastcall UFG::AICoverQuery::~AICoverQuery(UFG::AICoverQuery *this)
{
  UFG::AICoverSearchParams *m_pSearchParams; // rdi
  bool v3; // zf
  UFG::ParkourQuery *m_pParkourQuery; // rdi
  unsigned int i; // edi
  UFG::CoverObjectBase *v6; // rcx
  unsigned int j; // edi
  UFG::CoverPosition *v8; // rcx
  unsigned int k; // edi
  UFG::CoverObjectGroup *v10; // rcx
  unsigned int m; // edi
  UFG::CoverPosition *v12; // rcx
  UFG::CoverPosition *m_pBestCoverPosition; // rcx
  UFG::NavPath *m_pNavPath; // rcx
  UFG::qVector3 *p; // rcx
  UFG::AICoverQuery::CoverQueryRecord *v16; // rcx
  UFG::CoverObjectGroup **v17; // rcx
  UFG::CoverPosition **v18; // rcx
  UFG::CoverPosition **v19; // rcx
  UFG::CoverObjectBase **v20; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *mPrev; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *mNext; // rax

  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AICoverQuery::`vftable;
  m_pSearchParams = this->m_pSearchParams;
  if ( m_pSearchParams )
  {
    v3 = m_pSearchParams->m_iRefCount-- == 1;
    if ( v3 )
    {
      UFG::AICoverSearchParams::~AICoverSearchParams(m_pSearchParams);
      operator delete[](m_pSearchParams);
    }
    this->m_pSearchParams = 0i64;
  }
  m_pParkourQuery = this->m_pParkourQuery;
  if ( m_pParkourQuery )
  {
    UFG::ParkourQuery::~ParkourQuery(this->m_pParkourQuery);
    operator delete[](m_pParkourQuery);
    this->m_pParkourQuery = 0i64;
  }
  for ( i = 0; i < this->m_aCoverObjects.size; ++i )
  {
    v6 = this->m_aCoverObjects.p[i];
    v3 = v6->m_iRefCount-- == 1;
    if ( v3 )
      v6->vfptr->__vecDelDtor(v6, 1u);
  }
  for ( j = 0; j < this->m_aCulledObjects.size; ++j )
  {
    v8 = this->m_aCulledObjects.p[j];
    v3 = v8->m_iRefCount-- == 1;
    if ( v3 )
      v8->vfptr->__vecDelDtor(v8, 1u);
  }
  for ( k = 0; k < this->m_aCoverGroups.size; ++k )
  {
    v10 = this->m_aCoverGroups.p[k];
    v3 = v10->m_iRefCount-- == 1;
    if ( v3 )
      v10->vfptr->__vecDelDtor(v10, 1u);
  }
  for ( m = 0; m < this->m_aCoverPositions.size; ++m )
  {
    v12 = this->m_aCoverPositions.p[m];
    v3 = v12->m_iRefCount-- == 1;
    if ( v3 )
      v12->vfptr->__vecDelDtor(v12, 1u);
  }
  m_pBestCoverPosition = this->m_pBestCoverPosition;
  if ( m_pBestCoverPosition )
  {
    v3 = m_pBestCoverPosition->m_iRefCount-- == 1;
    if ( v3 )
      m_pBestCoverPosition->vfptr->__vecDelDtor(m_pBestCoverPosition, 1u);
  }
  m_pNavPath = this->m_pFoundPath.m_pNavPath;
  if ( m_pNavPath )
  {
    v3 = m_pNavPath->m_uRefCount-- == 1;
    if ( v3 )
      m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
  }
  p = this->m_vAllyAvoidancePositions.p;
  if ( p )
    operator delete[](p);
  this->m_vAllyAvoidancePositions.p = 0i64;
  *(_QWORD *)&this->m_vAllyAvoidancePositions.size = 0i64;
  v16 = this->m_aQueryRecords.p;
  if ( v16 )
  {
    if ( LODWORD(v16[-1].m_fDistanceFromAlliesPriority) )
      v16->vfptr->__vecDelDtor(v16, 3u);
    else
      operator delete[](&v16[-1].m_fDistanceFromAlliesPriority);
  }
  this->m_aQueryRecords.p = 0i64;
  *(_QWORD *)&this->m_aQueryRecords.size = 0i64;
  v17 = this->m_aCoverGroups.p;
  if ( v17 )
    operator delete[](v17);
  this->m_aCoverGroups.p = 0i64;
  *(_QWORD *)&this->m_aCoverGroups.size = 0i64;
  v18 = this->m_aCulledObjects.p;
  if ( v18 )
    operator delete[](v18);
  this->m_aCulledObjects.p = 0i64;
  *(_QWORD *)&this->m_aCulledObjects.size = 0i64;
  v19 = this->m_aCoverPositions.p;
  if ( v19 )
    operator delete[](v19);
  this->m_aCoverPositions.p = 0i64;
  *(_QWORD *)&this->m_aCoverPositions.size = 0i64;
  v20 = this->m_aCoverObjects.p;
  if ( v20 )
    operator delete[](v20);
  this->m_aCoverObjects.p = 0i64;
  *(_QWORD *)&this->m_aCoverObjects.size = 0i64;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery>;
  this->mNext = &this->UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery>;
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIQuery::`vftable;
}ext = &this->UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery>;
  

// File Line: 191
// RVA: 0x341960
void __fastcall UFG::AICoverQuery::AdvanceState(UFG::AICoverQuery *this)
{
  unsigned int v1; // eax

  v1 = *((_DWORD *)&unk_14206DA90 + 10 * this->m_uState);
  this->m_bStateNeedsInit = 1;
  this->m_uState = v1;
}

// File Line: 198
// RVA: 0x383030
void __fastcall UFG::AICoverQuery::ResetParkourLifetimes(UFG::AICoverQuery *this)
{
  UFG::ParkourQuery *m_pParkourQuery; // rdx
  unsigned __int64 i; // r8
  UFG::ParkourHandle *m_pPointer; // rdx
  UFG::ParkourHandle *v4; // rax
  UFG::ParkourHandle *v5; // rax

  m_pParkourQuery = this->m_pParkourQuery;
  if ( m_pParkourQuery )
  {
    for ( i = 0i64; i < m_pParkourQuery->handlesOut.size; ++i )
    {
      m_pPointer = m_pParkourQuery->handlesOut.p[(unsigned int)i].m_pPointer;
      if ( m_pPointer )
      {
        v4 = m_pPointer->mCachedLeftNeighbor.m_pPointer;
        m_pPointer->mFramesUntilDeleted = 10;
        if ( v4 )
          v4->mFramesUntilDeleted = 10;
        v5 = m_pPointer->mCachedRightNeighbor.m_pPointer;
        if ( v5 )
          v5->mFramesUntilDeleted = 10;
      }
      m_pParkourQuery = this->m_pParkourQuery;
    }
  }
}

// File Line: 250
// RVA: 0x368F70
void __fastcall UFG::AICoverQuery::InitializeQuery(UFG::AICoverQuery *this)
{
  UFG::SimObjectCVBase *m_pPointer; // r13
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // cx
  __int64 m_eFactionClass; // rbx
  UFG::TransformNodeComponent *mNext; // rcx
  UFG::NearbyCharacterManager *v7; // r8
  __int64 v8; // rax
  __int64 **v9; // rcx
  __int64 **i; // r15
  _QWORD *v11; // rdx
  __int64 *v12; // rcx
  __int64 **v13; // rax
  UFG::NearbyCharacterManager *v14; // rcx
  __int64 *v15; // rdx
  __int64 v16; // r14
  __int64 v17; // rsi
  _QWORD *v18; // rdi
  UFG::SimObjectGame *v19; // rdi
  __int64 v20; // rbx
  __int64 size; // rbp
  unsigned int v22; // ebx
  unsigned int capacity; // edx
  unsigned int v24; // edx
  __int64 v25; // rbp
  UFG::qVector3 *p; // rsi
  __int16 v27; // cx
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v29; // rbx
  float *v30; // rax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __int64 **j; // rax
  _QWORD *v36; // rdx
  __int64 *v37; // rcx
  __int64 *v38; // rax
  __int64 *v39; // rcx
  __int64 **v40; // rax
  _QWORD v41[5]; // [rsp+0h] [rbp-78h] BYREF
  char v42[16]; // [rsp+28h] [rbp-50h] BYREF
  __int64 *v43; // [rsp+38h] [rbp-40h] BYREF
  __int64 **v44; // [rsp+40h] [rbp-38h]
  __int64 v45; // [rsp+80h] [rbp+8h]

  v41[4] = -2i64;
  UFG::AICoverQuery::AcquireQueryCenter(this);
  m_pPointer = (UFG::SimObjectCVBase *)this->m_pSearchParams->m_pInitiator.m_pPointer;
  v43 = (__int64 *)&v43;
  v44 = &v43;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  m_eFactionClass = ComponentOfTypeHK->m_eFactionClass;
  mNext = (UFG::TransformNodeComponent *)this->m_pSearchParams->m_pInitiator.m_pPointer;
  if ( mNext )
    mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
  v7 = UFG::NearbyCharacterManager::s_pInstance;
  v8 = (__int64)v44;
  v9 = v44 - 2;
  for ( i = (__int64 **)&v41[5]; v44 - 2 != i; v9 = v44 - 2 )
  {
    v11 = v9 + 2;
    v12 = v9[2];
    v13 = (__int64 **)v11[1];
    v12[1] = (__int64)v13;
    *v13 = v12;
    *v11 = v11;
    v11[1] = v11;
    v8 = (__int64)v44;
  }
  v14 = (UFG::NearbyCharacterManager *)v7->m_Characters[0].mNode.mNext;
  if ( v14 != v7 )
  {
    v15 = v43;
    do
    {
      v15[1] = (__int64)&v14->m_Characters[1];
      v14->m_Characters[1].mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v15;
      v14->m_Characters[1].mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&v43;
      v15 = (__int64 *)&v14->m_Characters[1];
      v43 = (__int64 *)&v14->m_Characters[1];
      v14 = (UFG::NearbyCharacterManager *)v14->m_Characters[0].mNode.mNext;
    }
    while ( v14 != v7 );
    v8 = (__int64)v44;
  }
  v16 = v8 - 16;
  v17 = m_eFactionClass;
  v45 = m_eFactionClass;
  if ( (__int64 **)(v8 - 16) != i )
  {
    while ( 1 )
    {
      v18 = *(_QWORD **)(v16 + 48);
      if ( !v18 )
        goto LABEL_48;
      if ( !(*(unsigned __int8 (__fastcall **)(_QWORD))(*v18 + 112i64))(*(_QWORD *)(v16 + 48)) )
        goto LABEL_48;
      v19 = (UFG::SimObjectGame *)v18[5];
      if ( v19 == m_pPointer )
        goto LABEL_48;
      v20 = *(int *)(*(_QWORD *)(*(_QWORD *)(v16 + 48) + 280i64) + 200i64);
      if ( UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v17][v20] )
        goto LABEL_48;
      size = this->m_vAllyAvoidancePositions.size;
      v22 = size + 1;
      capacity = this->m_vAllyAvoidancePositions.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v24 = 2 * capacity;
        else
          v24 = 1;
        for ( ; v24 < v22; v24 *= 2 )
          ;
        if ( v24 - v22 > 0x10000 )
          v24 = size + 65537;
        UFG::qArray<UFG::qVector3,0>::Reallocate(&this->m_vAllyAvoidancePositions, v24, "qArray.Add");
      }
      this->m_vAllyAvoidancePositions.size = v22;
      v25 = size;
      p = this->m_vAllyAvoidancePositions.p;
      if ( !v19 )
        break;
      v27 = v19->m_Flags;
      if ( (v27 & 0x4000) != 0 || v27 < 0 || (v27 & 0x2000) != 0 || (v27 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::AICoverComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v19, UFG::AICoverComponent::_TypeUID);
      if ( !ComponentOfType
        || (v29 = *(_QWORD *)&ComponentOfType[1].m_Flags) == 0
        || !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v29 + 16i64))(v29) )
      {
        m_pTransformNodeComponent = v19->m_pTransformNodeComponent;
LABEL_46:
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        x = m_pTransformNodeComponent->mWorldTransform.v3.x;
        y = m_pTransformNodeComponent->mWorldTransform.v3.y;
        z = m_pTransformNodeComponent->mWorldTransform.v3.z;
        goto LABEL_47;
      }
      v30 = (float *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v29 + 120i64))(v29, v42);
      x = *v30;
      y = v30[1];
      z = v30[2];
LABEL_47:
      p[v25].x = x;
      p[v25].y = y;
      p[v25].z = z;
      v17 = v45;
LABEL_48:
      v16 = *(_QWORD *)(v16 + 24) - 16i64;
      if ( (__int64 **)v16 == i )
        goto LABEL_49;
    }
    m_pTransformNodeComponent = 0i64;
    goto LABEL_46;
  }
LABEL_49:
  this->vfptr[1].IsCompleted(this);
  for ( j = v44 - 2; v44 - 2 != i; j = v44 - 2 )
  {
    v36 = j + 2;
    v37 = j[2];
    v38 = j[3];
    v37[1] = (__int64)v38;
    *v38 = (__int64)v37;
    *v36 = v36;
    v36[1] = v36;
  }
  v39 = v43;
  v40 = v44;
  v43[1] = (__int64)v44;
  *v40 = v39;
}

// File Line: 327
// RVA: 0x3882B0
void __fastcall UFG::AICoverQuery::SetupSensor(UFG::AICoverQuery *this)
{
  float m_fMaxDistance; // xmm6_4
  UFG::allocator::free_link *v3; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::ParkourQuery *m_pParkourQuery; // rax

  if ( this->m_pParkourQuery )
  {
    this->vfptr[1].IsCompleted(this);
  }
  else
  {
    m_fMaxDistance = this->m_pSearchParams->m_fMaxDistance;
    v3 = UFG::qMalloc(0x48ui64, "ParkourQuery", 0i64);
    if ( v3 )
    {
      v3->mNext = v3;
      v3[1].mNext = v3;
      v3[8].mNext = 0i64;
      v3[7].mNext = 0i64;
    }
    else
    {
      v3 = 0i64;
    }
    this->m_pParkourQuery = (UFG::ParkourQuery *)v3;
    LODWORD(v3[7].mNext) = 0;
    this->m_pParkourQuery->userData = this;
    this->m_pParkourQuery->callback = 0i64;
    y = this->m_npQueryCenter.m_vPosition.y;
    z = this->m_npQueryCenter.m_vPosition.z;
    m_pParkourQuery = this->m_pParkourQuery;
    m_pParkourQuery->mCentre.x = this->m_npQueryCenter.m_vPosition.x;
    m_pParkourQuery->mCentre.y = y;
    m_pParkourQuery->mCentre.z = z;
    m_pParkourQuery->mCentre.w = 1.0;
    this->m_pParkourQuery->mRadius = m_fMaxDistance;
    UFG::ParkourQueryManager::AddAsyncQuery(UFG::ParkourQueryManager::mInstance, this->m_pParkourQuery);
    this->m_bCanContinue = 0;
  }
}

// File Line: 352
// RVA: 0x33F760
void __fastcall UFG::AICoverQuery::AcquireQueryCenter(UFG::AICoverQuery *this)
{
  UFG::AICoverSearchParams *m_pSearchParams; // rcx
  hkVector4f *v3; // rbx
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v13; // eax
  float v14; // xmm1_4
  char v15; // al

  m_pSearchParams = this->m_pSearchParams;
  v3 = 0i64;
  if ( m_pSearchParams->m_bUseCombatRegionDestination )
  {
    m_pPointer = (UFG::SimObjectGame *)m_pSearchParams->m_pInitiator.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                     ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID)
                     : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    v7 = *(float *)&m_pComponent[20].m_pSimObject;
    if ( v7 != UFG::qVector3::msZero.x
      || UFG::qVector3::msZero.y != *((float *)&m_pComponent[20].m_pSimObject + 1)
      || UFG::qVector3::msZero.z != *(float *)&m_pComponent[20].m_BoundComponentHandles.mNode.mPrev )
    {
      v8 = *(float *)&m_pComponent[20].m_BoundComponentHandles.mNode.mPrev;
      v9 = *((float *)&m_pComponent[20].m_pSimObject + 1);
      this->m_npQueryCenter.m_vPosition.x = v7;
      this->m_npQueryCenter.m_vPosition.z = v8;
      this->m_npQueryCenter.m_vPosition.y = v9;
      this->m_npQueryCenter.m_bValid = 0;
      ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_npQueryCenter.vfptr->Validate)(&this->m_npQueryCenter);
    }
  }
  v10 = (UFG::SimObjectGame *)this->m_pSearchParams->m_pInitiator.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      v3 = (hkVector4f *)v10->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( v11 < 0 || (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::NavComponent::_TypeUID);
      v3 = (hkVector4f *)ComponentOfTypeHK;
    }
  }
  v13 = v3[5].m_quad.m128_f32[2];
  v14 = v3[6].m_quad.m128_f32[0];
  LODWORD(this->m_npQueryCenter.m_vPosition.y) = v3[5].m_quad.m128_i32[3];
  this->m_npQueryCenter.m_vPosition.z = v14;
  this->m_npQueryCenter.m_vPosition.x = v13;
  v15 = v3[6].m_quad.m128_i8[8];
  if ( v15 )
  {
    this->m_npQueryCenter.m_bValid = v15;
    this->m_npQueryCenter.m_hkvMeshPosition = (hkVector4f)v3[7].m_quad;
    this->m_npQueryCenter.m_packedKey = v3[8].m_quad.m128_u32[0];
    this->m_npQueryCenter.m_aiMeshUid = v3[8].m_quad.m128_u32[1];
  }
  else
  {
    this->m_npQueryCenter.m_bValid = 0;
  }
  ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_npQueryCenter.vfptr->Validate)(&this->m_npQueryCenter);
}

// File Line: 383
// RVA: 0x3584E0
void __fastcall UFG::AICoverQuery::GatherInRange(UFG::AICoverQuery *this)
{
  UFG::AICoverQuery *v1; // r15
  UFG::qVector3 *p_m_vPosition; // rbp
  UFG::AICoverSearchParams *m_pSearchParams; // rax
  float m_fMaxZDistance; // xmm9_4
  float v5; // xmm10_4
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_m_aCoverObjects; // rdi
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::qReflectInventoryBase **v9; // rbx
  unsigned int i; // r9d
  float m_fMaxDistance; // xmm8_4
  float y; // xmm7_4
  float x; // xmm6_4
  UFG::CoverDataInventory *Instance; // rax
  UFG::CoverDataInventory *v15; // rsi
  float mXMin; // xmm1_4
  float mGridSizeInv; // xmm2_4
  int v18; // r10d
  int v19; // r11d
  __int64 mXDim; // rbx
  float mYMin; // xmm1_4
  int v22; // r8d
  int v23; // ecx
  int mYDim; // eax
  unsigned int v25; // edx
  __int64 v26; // r9
  __int64 v27; // rbp
  __int64 v28; // rbx
  __int64 v29; // rcx
  __int64 v30; // r8
  __int64 *v31; // rax
  __int64 v32; // rcx
  UFG::CoverCorner *v33; // r12
  UFG::CoverCorner *mNext; // r15
  float v35; // xmm2_4
  float v36; // xmm0_4
  UFG::allocator::free_link *v37; // rax
  UFG::allocator::free_link *v38; // rsi
  __int64 size; // r13
  unsigned int v40; // ebp
  unsigned int capacity; // ebx
  unsigned int v42; // ebx
  unsigned __int64 v43; // rax
  UFG::allocator::free_link *v44; // rax
  UFG::qReflectInventoryBase **v45; // r14
  __int64 j; // r9
  UFG::ParkourQuery *m_pParkourQuery; // rsi
  unsigned int k; // eax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p; // rdx
  UFG::ParkourHandle *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v52; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v53; // rax
  unsigned int v54; // eax
  bool v55; // r12
  UFG::SimObject *v56; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  unsigned int m; // r14d
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v59; // rax
  UFG::ParkourHandle *v60; // rbx
  UFG::qVector3 *v61; // rax
  float v62; // xmm0_4
  __m128 x_low; // xmm1
  UFG::allocator::free_link *v64; // rax
  __int64 v65; // rax
  __int64 v66; // rbp
  __int64 v67; // r15
  unsigned int v68; // ebx
  unsigned int v69; // edx
  unsigned int v70; // edx
  UFG::ParkourQuery *v71; // rdi
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v72; // rcx
  char *p_m_pPointer; // rbx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v74; // rdx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v75; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-198h] BYREF
  UFG::qVector3 p0; // [rsp+30h] [rbp-188h] BYREF
  UFG::qVector3 p1; // [rsp+3Ch] [rbp-17Ch] BYREF
  __int64 v79; // [rsp+48h] [rbp-170h]
  __int64 v80[25]; // [rsp+50h] [rbp-168h] BYREF
  int v81; // [rsp+118h] [rbp-A0h]
  UFG::qVector3 *v83; // [rsp+1C8h] [rbp+10h]
  __int64 *v84; // [rsp+1D0h] [rbp+18h]
  __int64 v85; // [rsp+1D8h] [rbp+20h]

  v79 = -2i64;
  v1 = this;
  p_m_vPosition = &this->m_npQueryCenter.m_vPosition;
  v83 = &this->m_npQueryCenter.m_vPosition;
  m_pSearchParams = this->m_pSearchParams;
  m_fMaxZDistance = m_pSearchParams->m_fMaxZDistance;
  v5 = m_pSearchParams->m_fMaxDistance * m_pSearchParams->m_fMaxDistance;
  p_m_aCoverObjects = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_aCoverObjects;
  if ( this->m_aCoverObjects.capacity < 0x80 && p_m_aCoverObjects->size != 128 )
  {
    v7 = 1024i64;
    if ( !is_mul_ok(0x80ui64, 8ui64) )
      v7 = -1i64;
    v8 = UFG::qMalloc(v7, "AICoverQuery::m_aCoverObjects", 0i64);
    v9 = (UFG::qReflectInventoryBase **)v8;
    if ( p_m_aCoverObjects->p )
    {
      for ( i = 0; i < p_m_aCoverObjects->size; ++i )
        v8[i] = (UFG::allocator::free_link)p_m_aCoverObjects->p[i];
      operator delete[](p_m_aCoverObjects->p);
    }
    p_m_aCoverObjects->p = v9;
    p_m_aCoverObjects->capacity = 128;
  }
  m_fMaxDistance = v1->m_pSearchParams->m_fMaxDistance;
  y = p_m_vPosition->y;
  x = p_m_vPosition->x;
  Instance = UFG::CoverDataInventory::GetInstance();
  v15 = Instance;
  mXMin = Instance->m_CornerGrid.mXMin;
  mGridSizeInv = Instance->m_CornerGrid.mGridSizeInv;
  v18 = (int)(float)((float)((float)(x - m_fMaxDistance) - mXMin) * mGridSizeInv);
  if ( v18 < 0 )
    v18 = 0;
  v19 = (int)(float)((float)((float)(x + m_fMaxDistance) - mXMin) * mGridSizeInv);
  mXDim = Instance->m_CornerGrid.mXDim;
  if ( v19 >= (int)mXDim )
    v19 = mXDim - 1;
  mYMin = Instance->m_CornerGrid.mYMin;
  v22 = (int)(float)((float)((float)(y - m_fMaxDistance) - mYMin) * mGridSizeInv);
  if ( v22 < 0 )
    v22 = 0;
  v23 = (int)(float)((float)((float)(y + m_fMaxDistance) - mYMin) * mGridSizeInv);
  mYDim = Instance->m_CornerGrid.mYDim;
  if ( v23 >= mYDim )
    v23 = mYDim - 1;
  v25 = 0;
  v81 = 0;
  if ( v22 <= v23 )
  {
    v26 = 16i64 * (v18 + v22 * (int)mXDim);
    v27 = 16 * mXDim;
    v28 = (unsigned int)(v23 - v22 + 1);
    do
    {
      if ( v18 <= v19 )
      {
        v29 = (__int64)v15->m_CornerGrid.mGridNodes + v26;
        v30 = (unsigned int)(v19 - v18 + 1);
        do
        {
          if ( *(_QWORD *)(v29 + 8) != v29 )
          {
            v80[v25] = v29;
            v25 = ++v81;
          }
          v29 += 16i64;
          --v30;
        }
        while ( v30 );
      }
      v26 += v27;
      --v28;
    }
    while ( v28 );
    p_m_vPosition = v83;
  }
  if ( v25 )
  {
    v31 = v80;
    v84 = v80;
    v32 = v25;
    v85 = v25;
    do
    {
      v33 = (UFG::CoverCorner *)*v31;
      mNext = *(UFG::CoverCorner **)(*v31 + 8);
      if ( mNext != (UFG::CoverCorner *)*v31 )
      {
        do
        {
          v35 = mNext->m_vCornerPosition.z - p_m_vPosition->z;
          v36 = mNext->m_vCornerPosition.y - p_m_vPosition->y;
          if ( (float)((float)((float)((float)(mNext->m_vCornerPosition.x - p_m_vPosition->x)
                                     * (float)(mNext->m_vCornerPosition.x - p_m_vPosition->x))
                             + (float)(v36 * v36))
                     + (float)(v35 * v35)) < v5
            && COERCE_FLOAT(LODWORD(v35) & _xmm) < m_fMaxZDistance )
          {
            v37 = UFG::qMalloc(0x68ui64, "CoverObjectCorner", 0i64);
            v38 = v37;
            *(_QWORD *)&result.x = v37;
            if ( v37 )
            {
              v37->mNext = (UFG::allocator::free_link *)&UFG::CoverObjectBase::`vftable;
              LODWORD(v37[1].mNext) = 0;
              v37[2].mNext = 0i64;
              LODWORD(v37[3].mNext) = 0;
              v37->mNext = (UFG::allocator::free_link *)&UFG::CoverObjectCorner::`vftable;
              UFG::CoverCornerHandle::CoverCornerHandle((UFG::CoverCornerHandle *)&v37[4], mNext);
              v38[12].mNext = 0i64;
            }
            else
            {
              v38 = 0i64;
            }
            ++LODWORD(v38[1].mNext);
            size = p_m_aCoverObjects->size;
            v40 = size + 1;
            capacity = p_m_aCoverObjects->capacity;
            if ( (int)size + 1 > capacity )
            {
              if ( capacity )
                v42 = 2 * capacity;
              else
                v42 = 1;
              for ( ; v42 < v40; v42 *= 2 )
                ;
              if ( v42 <= 2 )
                v42 = 2;
              if ( v42 - v40 > 0x10000 )
                v42 = size + 65537;
              if ( v42 != (_DWORD)size )
              {
                v43 = 8i64 * v42;
                if ( !is_mul_ok(v42, 8ui64) )
                  v43 = -1i64;
                v44 = UFG::qMalloc(v43, "qArray.Add", 0i64);
                v45 = (UFG::qReflectInventoryBase **)v44;
                if ( p_m_aCoverObjects->p )
                {
                  for ( j = 0i64; (unsigned int)j < p_m_aCoverObjects->size; j = (unsigned int)(j + 1) )
                    v44[j] = (UFG::allocator::free_link)p_m_aCoverObjects->p[j];
                  operator delete[](p_m_aCoverObjects->p);
                }
                p_m_aCoverObjects->p = v45;
                p_m_aCoverObjects->capacity = v42;
              }
            }
            p_m_aCoverObjects->size = v40;
            p_m_aCoverObjects->p[size] = (UFG::qReflectInventoryBase *)v38;
            p_m_vPosition = v83;
          }
          mNext = (UFG::CoverCorner *)mNext->mNext;
        }
        while ( mNext != v33 );
        v31 = v84;
        v32 = v85;
      }
      v84 = ++v31;
      v85 = --v32;
    }
    while ( v32 );
    v1 = this;
  }
  m_pParkourQuery = v1->m_pParkourQuery;
  for ( k = m_pParkourQuery->handlesOut.size; k; k = m_pParkourQuery->handlesOut.size )
  {
    p = m_pParkourQuery->handlesOut.p;
    if ( p->m_pPointer )
      break;
    m_pPointer = p[k - 1].m_pPointer;
    if ( p->m_pPointer )
    {
      mPrev = p->mPrev;
      v52 = p->mNext;
      mPrev->mNext = v52;
      v52->mPrev = mPrev;
      p->mPrev = p;
      p->mNext = p;
    }
    p->m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v53 = m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
      v53->mNext = p;
      p->mPrev = v53;
      p->mNext = &m_pPointer->m_SafePointerList.mNode;
      m_pPointer->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = p;
    }
    v54 = m_pParkourQuery->handlesOut.size;
    m_pParkourQuery->handlesOut.size = v54 > 1 ? v54 - 1 : 0;
  }
  v55 = 1;
  if ( m_pParkourQuery->handlesOut.size )
  {
    v56 = m_pParkourQuery->handlesOut.p->m_pPointer->mSimObject.m_pPointer;
    if ( v56 )
    {
      m_pTransformNodeComponent = v56->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v55 = (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity * UFG::CoverObjectBase::ms_fMaxCoverVelocity) > (float)((float)((float)(m_pTransformNodeComponent->mWorldVelocity.x * m_pTransformNodeComponent->mWorldVelocity.x) + (float)(m_pTransformNodeComponent->mWorldVelocity.y * m_pTransformNodeComponent->mWorldVelocity.y)) + (float)(m_pTransformNodeComponent->mWorldVelocity.z * m_pTransformNodeComponent->mWorldVelocity.z));
      }
    }
  }
  for ( m = 0; m < m_pParkourQuery->handlesOut.size; p_m_vPosition = v83 )
  {
    v59 = m_pParkourQuery->handlesOut.p;
    v60 = v59[m].m_pPointer;
    if ( v60 )
    {
      if ( UFG::ParkourHandle::IsEnabled(v59[m].m_pPointer) && v55 )
      {
        UFG::ParkourHandle::GetEndpoints(v60, &p0, &p1);
        v61 = UFG::qNearestSegPoint(&result, &p0, &p1, p_m_vPosition);
        v62 = p_m_vPosition->y - v61->y;
        x_low = (__m128)LODWORD(p_m_vPosition->x);
        x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - v61->x) * (float)(x_low.m128_f32[0] - v61->x))
                                  + (float)(v62 * v62))
                          + (float)((float)(p_m_vPosition->z - v61->z) * (float)(p_m_vPosition->z - v61->z));
        if ( _mm_sqrt_ps(x_low).m128_f32[0] < v1->m_pSearchParams->m_fMaxDistance
          && !UFG::ParkourHandle::IsType(v60, 16)
          && !UFG::ParkourHandle::IsType(v60, 32)
          && (!UFG::ParkourHandle::IsAttachedToVehicle(v60) || UFG::ParkourHandle::IsType(v60, 64)) )
        {
          v64 = UFG::qMalloc(0x48ui64, "CoverObjectParkour", 0i64);
          if ( v64 )
          {
            UFG::CoverObjectParkour::CoverObjectParkour((UFG::CoverObjectParkour *)v64, v60);
            v66 = v65;
          }
          else
          {
            v66 = 0i64;
          }
          ++*(_DWORD *)(v66 + 8);
          v67 = p_m_aCoverObjects->size;
          v68 = v67 + 1;
          v69 = p_m_aCoverObjects->capacity;
          if ( (int)v67 + 1 > v69 )
          {
            if ( v69 )
              v70 = 2 * v69;
            else
              v70 = 1;
            for ( ; v70 < v68; v70 *= 2 )
              ;
            if ( v70 <= 2 )
              v70 = 2;
            if ( v70 - v68 > 0x10000 )
              v70 = v67 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_m_aCoverObjects, v70, "qArray.Add");
          }
          p_m_aCoverObjects->size = v68;
          p_m_aCoverObjects->p[v67] = (UFG::qReflectInventoryBase *)v66;
          v1 = this;
        }
      }
    }
    ++m;
  }
  v71 = v1->m_pParkourQuery;
  if ( v71 )
  {
    v72 = v71->handlesOut.p;
    if ( v72 )
    {
      p_m_pPointer = (char *)&v72[-1].m_pPointer;
      `eh vector destructor iterator(
        v72,
        0x18ui64,
        (int)v72[-1].m_pPointer,
        (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
      operator delete[](p_m_pPointer);
    }
    v71->handlesOut.p = 0i64;
    *(_QWORD *)&v71->handlesOut.size = 0i64;
    v74 = v71->mPrev;
    v75 = v71->mNext;
    v74->mNext = v75;
    v75->mPrev = v74;
    v71->mPrev = v71;
    v71->mNext = v71;
    operator delete[](v71);
    v1->m_pParkourQuery = 0i64;
  }
  v1->vfptr[1].IsCompleted(v1);
}

// File Line: 480
// RVA: 0x366D30
void __fastcall UFG::AICoverQuery::InitFindParkourSyncs(UFG::AICoverQuery *this)
{
  this->m_uCurrentSyncFinding = 0;
}

// File Line: 485
// RVA: 0x357E40
void __fastcall UFG::AICoverQuery::FindParkourSyncs(UFG::AICoverQuery *this)
{
  float m_fMaxZDistance; // xmm6_4
  unsigned __int64 Ticks; // rax
  unsigned int m_uCurrentSyncFinding; // eax
  UFG::CoverObjectBase *v5; // rdi
  unsigned int size; // eax
  char v8; // [rsp+20h] [rbp-38h] BYREF
  float v9; // [rsp+28h] [rbp-30h]

  m_fMaxZDistance = this->m_pSearchParams->m_fMaxZDistance;
  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentSyncFinding = this->m_uCurrentSyncFinding;
    if ( m_uCurrentSyncFinding >= this->m_aCoverObjects.size )
      break;
    v5 = this->m_aCoverObjects.p[m_uCurrentSyncFinding];
    if ( v5->vfptr->IsCorner(v5)
      || (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v5->vfptr->__vecDelDtor + 2))(v5)
      && v5->vfptr->IsParkour(v5)
      && this->vfptr[1].__vecDelDtor(this, v5)
      && (v5->vfptr->GetSyncPos(v5, (UFG::qVector3 *)&v8),
          m_fMaxZDistance > COERCE_FLOAT(COERCE_UNSIGNED_INT(v9 - this->m_npQueryCenter.m_vPosition.z) & _xmm)) )
    {
LABEL_15:
      ++this->m_uCurrentSyncFinding;
    }
    else
    {
      if ( v5->m_iRefCount-- == 1 )
        v5->vfptr->__vecDelDtor(v5, 1u);
      this->m_aCoverObjects.p[this->m_uCurrentSyncFinding] = this->m_aCoverObjects.p[this->m_aCoverObjects.size - 1];
      size = this->m_aCoverObjects.size;
      if ( size > 1 )
      {
        this->m_aCoverObjects.size = size - 1;
        --this->m_uCurrentSyncFinding;
        goto LABEL_15;
      }
      this->m_aCoverObjects.size = 0;
      --this->m_uCurrentSyncFinding;
      ++this->m_uCurrentSyncFinding;
    }
  }
  if ( this->m_uCurrentSyncFinding == this->m_aCoverObjects.size )
    this->vfptr[1].IsCompleted(this);
}

// File Line: 530
// RVA: 0x36B8F0
bool __fastcall UFG::AICoverQuery::IsParkourSyncValid(UFG::AICoverQuery *this, UFG::CoverObjectParkour *pCoverObject)
{
  UFG::qVector3 *v3; // rbx
  bool result; // al
  char v5[12]; // [rsp+20h] [rbp-28h] BYREF
  char v6[28]; // [rsp+2Ch] [rbp-1Ch] BYREF

  result = 0;
  if ( UFG::CoverObjectParkour::FindParkourSyncPos(pCoverObject) )
  {
    v3 = pCoverObject->vfptr->GetPosition(pCoverObject, v5);
    if ( (float)(v3->z - pCoverObject->vfptr->GetSyncPos(pCoverObject, v6)->z) < 1.4 )
      return 1;
  }
  return result;
}

// File Line: 548
// RVA: 0x36B960
bool __fastcall UFG::PlayerCoverQuery::IsParkourSyncValid(
        UFG::PlayerCoverQuery *this,
        UFG::CoverObjectParkour *pCoverObject)
{
  return UFG::CoverObjectParkour::FindParkourSyncPos(pCoverObject);
}

// File Line: 555
// RVA: 0x368890
void __fastcall UFG::AICoverQuery::InitProcessObstructions(UFG::AICoverQuery *this)
{
  this->m_uCurrentObstructionTest = 0;
}

// File Line: 560
// RVA: 0x37E000
void __fastcall UFG::AICoverQuery::ProcessObstructions(UFG::AICoverQuery *this)
{
  unsigned __int64 Ticks; // rax
  unsigned int m_uCurrentObstructionTest; // eax
  UFG::CoverObjectCorner *v4; // r14
  __int64 v5; // rsi
  UFG::CoverObjectParkour *v6; // rdi
  UFG::CoverObjectBaseVtbl *vfptr; // rax
  bool v8; // zf
  UFG::CoverObjectBaseVtbl *v9; // rax
  unsigned int v10; // eax
  unsigned int size; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  UFG::CoverObjectBaseVtbl *v14; // rax
  UFG::CoverObjectBase *v15; // rcx
  unsigned int v16; // eax
  unsigned int uObstructed; // [rsp+40h] [rbp+8h] BYREF

LABEL_1:
  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentObstructionTest = this->m_uCurrentObstructionTest;
    if ( m_uCurrentObstructionTest >= this->m_aCoverObjects.size )
      break;
    v4 = (UFG::CoverObjectCorner *)this->m_aCoverObjects.p[m_uCurrentObstructionTest];
    if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectCorner *))&v4->vfptr->__vecDelDtor + 2))(v4) )
      goto LABEL_44;
    v5 = this->m_uCurrentObstructionTest + 1;
    if ( (unsigned int)v5 >= this->m_aCoverObjects.size )
      goto LABEL_44;
    while ( 1 )
    {
      v6 = (UFG::CoverObjectParkour *)this->m_aCoverObjects.p[v5];
      if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectParkour *))&v6->vfptr->__vecDelDtor + 2))(v6) )
        goto LABEL_25;
      vfptr = v4->vfptr;
      uObstructed = 0;
      v8 = !vfptr->IsParkour(v4);
      v9 = v6->vfptr;
      if ( v8 )
      {
        if ( !v9->IsParkour(v6) )
          goto LABEL_25;
        UFG::CoverObjectBase::CheckObstructionLineCorner(v6, v4, &uObstructed);
        v10 = uObstructed;
        if ( uObstructed && uObstructed != 3 )
          v10 = uObstructed ^ 3;
      }
      else
      {
        if ( v9->IsParkour(v6) )
          UFG::CoverObjectBase::CheckObstructionLineLine((UFG::CoverObjectParkour *)v4, v6, &uObstructed);
        else
          UFG::CoverObjectBase::CheckObstructionLineCorner(
            (UFG::CoverObjectParkour *)v4,
            (UFG::CoverObjectCorner *)v6,
            &uObstructed);
        v10 = uObstructed;
      }
      if ( v10 == 1 )
        break;
      if ( v10 == 2 )
      {
        this->m_aCoverObjects.p[v5] = this->m_aCoverObjects.p[this->m_aCoverObjects.size - 1];
        size = this->m_aCoverObjects.size;
        if ( size > 1 )
          this->m_aCoverObjects.size = size - 1;
        else
          this->m_aCoverObjects.size = 0;
        v8 = v6->m_iRefCount-- == 1;
        if ( v8 )
          v6->vfptr->__vecDelDtor(v6, 1u);
        LODWORD(v5) = v5 - 1;
      }
      else if ( v10 == 3 )
      {
        this->m_aCoverObjects.p[v5] = this->m_aCoverObjects.p[this->m_aCoverObjects.size - 1];
        v12 = this->m_aCoverObjects.size;
        if ( v12 > 1 )
          this->m_aCoverObjects.size = v12 - 1;
        else
          this->m_aCoverObjects.size = 0;
        this->m_aCoverObjects.p[this->m_uCurrentObstructionTest] = this->m_aCoverObjects.p[this->m_aCoverObjects.size
                                                                                         - 1];
        v13 = this->m_aCoverObjects.size;
        if ( v13 > 1 )
          this->m_aCoverObjects.size = v13 - 1;
        else
          this->m_aCoverObjects.size = 0;
        v8 = v4->m_iRefCount-- == 1;
        if ( v8 )
          v4->vfptr->__vecDelDtor(v4, 1u);
        v8 = v6->m_iRefCount-- == 1;
        if ( v8 )
        {
          v14 = v6->vfptr;
          v15 = v6;
LABEL_42:
          v14->__vecDelDtor(v15, 1u);
          goto LABEL_43;
        }
        goto LABEL_43;
      }
LABEL_25:
      v5 = (unsigned int)(v5 + 1);
      if ( (unsigned int)v5 >= this->m_aCoverObjects.size )
      {
        ++this->m_uCurrentObstructionTest;
        goto LABEL_1;
      }
    }
    this->m_aCoverObjects.p[this->m_uCurrentObstructionTest] = this->m_aCoverObjects.p[this->m_aCoverObjects.size - 1];
    v16 = this->m_aCoverObjects.size;
    if ( v16 > 1 )
      this->m_aCoverObjects.size = v16 - 1;
    else
      this->m_aCoverObjects.size = 0;
    v8 = v4->m_iRefCount-- == 1;
    if ( v8 )
    {
      v14 = v4->vfptr;
      v15 = v4;
      goto LABEL_42;
    }
LABEL_43:
    --this->m_uCurrentObstructionTest;
LABEL_44:
    ++this->m_uCurrentObstructionTest;
  }
  if ( this->m_uCurrentObstructionTest == this->m_aCoverObjects.size )
    this->vfptr[1].IsCompleted(this);
}

// File Line: 620
// RVA: 0x368880
void __fastcall UFG::AICoverQuery::InitProcessConnections(UFG::AICoverQuery *this)
{
  this->m_uCurrentConnecting = 0;
}

// File Line: 625
// RVA: 0x37DA20
void __fastcall UFG::AICoverQuery::ProcessConnections(UFG::AICoverQuery *this)
{
  unsigned __int64 Ticks; // rax
  unsigned int m_uCurrentConnecting; // eax
  UFG::CoverObjectBase *v4; // r13
  __int64 i; // r12
  UFG::CoverObjectBase *v6; // r14
  UFG::CoverObjectGroup *v7; // rsi
  UFG::CoverObjectGroup *v8; // rax
  UFG::CoverObjectGroup *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::CoverObjectGroup *v11; // rbx
  __int64 v12; // rbp
  unsigned int v13; // esi
  unsigned int capacity; // edx
  unsigned int v15; // edx
  __int64 v16; // rcx
  unsigned int size; // edx
  UFG::CoverObjectGroup **p; // r8
  unsigned int v19; // eax
  bool v20; // zf
  unsigned int v21; // eax
  unsigned int v22; // ebx
  UFG::CoverObjectBase *v23; // rsi
  unsigned int v24; // eax
  unsigned int j; // r12d
  UFG::CoverObjectGroup *v26; // rsi
  __int64 v27; // r15
  unsigned int v28; // ebp
  unsigned int v29; // ebx
  unsigned int v30; // ebx
  unsigned __int64 v31; // rax
  UFG::allocator::free_link *v32; // rax
  UFG::CoverObjectBase **v33; // r14
  __int64 k; // r9
  unsigned int m; // ebx
  UFG::ParkourHandle **v36; // r14
  unsigned int n; // esi
  UFG::CoverObjectBase *v38; // rbx
  UFG::ParkourHandle *m_pCoverObjectGroup; // r14
  float v40; // xmm0_4
  float v41; // xmm6_4
  unsigned int v42; // eax

  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentConnecting = this->m_uCurrentConnecting;
    if ( m_uCurrentConnecting >= this->m_aCoverObjects.size )
      break;
    v4 = this->m_aCoverObjects.p[m_uCurrentConnecting];
    if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v4->vfptr->__vecDelDtor + 2))(v4) )
    {
      for ( i = this->m_uCurrentConnecting + 1; (unsigned int)i < this->m_aCoverObjects.size; i = (unsigned int)(i + 1) )
      {
        v6 = this->m_aCoverObjects.p[i];
        if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v6->vfptr->__vecDelDtor + 2))(v6)
          && v4->vfptr->IsConnectedTo(v4, v6) )
        {
          v7 = v4->vfptr->GetCoverObjectGroup(v4);
          v8 = v6->vfptr->GetCoverObjectGroup(v6);
          v9 = v8;
          if ( v7 )
          {
            if ( v8 )
            {
              if ( v7 != v8 )
              {
                UFG::CoverObjectGroup::AddGroup(v7, v8);
                v16 = 0i64;
                size = this->m_aCoverGroups.size;
                if ( size )
                {
                  p = this->m_aCoverGroups.p;
                  while ( v9 != p[v16] )
                  {
                    v16 = (unsigned int)(v16 + 1);
                    if ( (unsigned int)v16 >= size )
                      goto LABEL_38;
                  }
                  if ( (int)v16 >= 0 )
                  {
                    p[v16] = p[size - 1];
                    v19 = this->m_aCoverGroups.size;
                    if ( v19 > 1 )
                      this->m_aCoverGroups.size = v19 - 1;
                    else
                      this->m_aCoverGroups.size = 0;
                  }
                }
LABEL_38:
                v20 = v9->m_iRefCount-- == 1;
                if ( v20 )
                  v9->vfptr->__vecDelDtor(v9, 1u);
              }
            }
            else
            {
              UFG::CoverObjectGroup::AddObject(v7, v6);
            }
          }
          else if ( v8 )
          {
            UFG::CoverObjectGroup::AddObject(v8, v4);
          }
          else
          {
            v10 = UFG::qMalloc(0x38ui64, "CoverObjectGroup", 0i64);
            v11 = (UFG::CoverObjectGroup *)v10;
            if ( v10 )
            {
              v10->mNext = (UFG::allocator::free_link *)&UFG::CoverObjectBase::`vftable;
              LODWORD(v10[1].mNext) = 0;
              v10[2].mNext = 0i64;
              LODWORD(v10[3].mNext) = 0;
              v10->mNext = (UFG::allocator::free_link *)&UFG::CoverObjectGroup::`vftable;
              v10[5].mNext = 0i64;
              v10[4].mNext = 0i64;
            }
            else
            {
              v11 = 0i64;
            }
            ++v11->m_iRefCount;
            v12 = this->m_aCoverGroups.size;
            v13 = v12 + 1;
            capacity = this->m_aCoverGroups.capacity;
            if ( (int)v12 + 1 > capacity )
            {
              if ( capacity )
                v15 = 2 * capacity;
              else
                v15 = 1;
              for ( ; v15 < v13; v15 *= 2 )
                ;
              if ( v15 <= 2 )
                v15 = 2;
              if ( v15 - v13 > 0x10000 )
                v15 = v12 + 65537;
              UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
                (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_aCoverGroups,
                v15,
                "qArray.Add");
            }
            this->m_aCoverGroups.size = v13;
            this->m_aCoverGroups.p[v12] = v11;
            UFG::CoverObjectGroup::AddObject(v11, v4);
            UFG::CoverObjectGroup::AddObject(v11, v6);
          }
        }
      }
    }
    ++this->m_uCurrentConnecting;
  }
  v21 = this->m_aCoverObjects.size;
  if ( this->m_uCurrentConnecting == v21 )
  {
    v22 = 0;
    if ( v21 )
    {
      do
      {
        v23 = this->m_aCoverObjects.p[v22];
        if ( v23->vfptr->GetCoverObjectGroup(v23) )
        {
          v20 = v23->m_iRefCount-- == 1;
          if ( v20 )
            v23->vfptr->__vecDelDtor(v23, 1u);
          this->m_aCoverObjects.p[v22] = this->m_aCoverObjects.p[this->m_aCoverObjects.size - 1];
          v24 = this->m_aCoverObjects.size;
          if ( v24 > 1 )
            this->m_aCoverObjects.size = v24 - 1;
          else
            this->m_aCoverObjects.size = 0;
          --v22;
        }
        ++v22;
      }
      while ( v22 < this->m_aCoverObjects.size );
    }
    for ( j = 0; j < this->m_aCoverGroups.size; ++j )
    {
      v26 = this->m_aCoverGroups.p[j];
      if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectGroup *))&v26->vfptr->__vecDelDtor + 2))(v26) )
      {
        ++v26->m_iRefCount;
        v27 = this->m_aCoverObjects.size;
        v28 = v27 + 1;
        v29 = this->m_aCoverObjects.capacity;
        if ( (int)v27 + 1 > v29 )
        {
          if ( v29 )
            v30 = 2 * v29;
          else
            v30 = 1;
          for ( ; v30 < v28; v30 *= 2 )
            ;
          if ( v30 <= 2 )
            v30 = 2;
          if ( v30 - v28 > 0x10000 )
            v30 = v27 + 65537;
          if ( v30 != (_DWORD)v27 )
          {
            v31 = 8i64 * v30;
            if ( !is_mul_ok(v30, 8ui64) )
              v31 = -1i64;
            v32 = UFG::qMalloc(v31, "qArray.Add", 0i64);
            v33 = (UFG::CoverObjectBase **)v32;
            if ( this->m_aCoverObjects.p )
            {
              for ( k = 0i64; (unsigned int)k < this->m_aCoverObjects.size; k = (unsigned int)(k + 1) )
                v32[k] = (UFG::allocator::free_link)this->m_aCoverObjects.p[k];
              operator delete[](this->m_aCoverObjects.p);
            }
            this->m_aCoverObjects.p = v33;
            this->m_aCoverObjects.capacity = v30;
          }
        }
        this->m_aCoverObjects.size = v28;
        this->m_aCoverObjects.p[v27] = v26;
        v26->m_fTotalLength = 0.0;
        for ( m = 0; m < v26->m_aChildObjects.size; ++m )
        {
          v36 = (UFG::ParkourHandle **)v26->m_aChildObjects.p[m];
          if ( ((unsigned __int8 (__fastcall *)(UFG::ParkourHandle **))(*v36)->mSimObject.mNext)(v36) )
            v26->m_fTotalLength = (float)(UFG::ParkourHandle::GetHalfLength(v36[6]) * 2.0) + v26->m_fTotalLength;
        }
      }
    }
    for ( n = 0; n < this->m_aCoverObjects.size; ++n )
    {
      v38 = this->m_aCoverObjects.p[n];
      if ( v38->vfptr->IsParkour(v38)
        && (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v38->vfptr->__vecDelDtor + 2))(v38) )
      {
        m_pCoverObjectGroup = (UFG::ParkourHandle *)v38[1].m_pCoverObjectGroup;
        v40 = v38->vfptr->GetHeight(v38);
        if ( v40 <= 0.5 || v40 >= 1.6 )
          v41 = UFG::CoverObjectBase::ms_fHighSideOffset;
        else
          v41 = UFG::CoverObjectBase::ms_fLowSideOffset;
        if ( UFG::ParkourHandle::GetHalfLength(m_pCoverObjectGroup) < v41 )
        {
          v20 = v38->m_iRefCount-- == 1;
          if ( v20 )
            v38->vfptr->__vecDelDtor(v38, 1u);
          this->m_aCoverObjects.p[n] = this->m_aCoverObjects.p[this->m_aCoverObjects.size - 1];
          v42 = this->m_aCoverObjects.size;
          if ( v42 > 1 )
            this->m_aCoverObjects.size = v42 - 1;
          else
            this->m_aCoverObjects.size = 0;
          --n;
        }
      }
    }
    this->vfptr[1].IsCompleted(this);
  }
}

// File Line: 733
// RVA: 0x368760
void __fastcall UFG::AICoverQuery::InitGetCoverPositions(UFG::AICoverQuery *this)
{
  this->m_uCurrentGetCoverPositions = 0;
}

// File Line: 738
// RVA: 0x35CAB0
void __fastcall UFG::AICoverQuery::GetCoverPositions(UFG::AICoverQuery *this)
{
  unsigned __int64 Ticks; // rax
  unsigned int m_uCurrentGetCoverPositions; // eax
  UFG::CoverObjectBase *v4; // rbx
  unsigned int i; // ebp
  UFG::CoverPosition *v6; // r12
  __int64 size; // r15
  unsigned int v8; // esi
  unsigned int capacity; // ebx
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::CoverPosition **v13; // r14
  unsigned int j; // r9d
  __int64 v15; // [rsp+28h] [rbp-40h] BYREF
  void *mem; // [rsp+30h] [rbp-38h]

  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentGetCoverPositions = this->m_uCurrentGetCoverPositions;
    if ( m_uCurrentGetCoverPositions >= this->m_aCoverObjects.size )
      break;
    v4 = this->m_aCoverObjects.p[m_uCurrentGetCoverPositions];
    if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v4->vfptr->__vecDelDtor + 2))(v4) )
    {
      mem = 0i64;
      v15 = 0i64;
      if ( v4->vfptr->GetCoverPositions(v4, (UFG::qArray<UFG::CoverPosition *,0> *)&v15) )
      {
        for ( i = 0; i < (unsigned int)v15; ++i )
        {
          v6 = (UFG::CoverPosition *)*((_QWORD *)mem + i);
          size = this->m_aCoverPositions.size;
          v8 = size + 1;
          capacity = this->m_aCoverPositions.capacity;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v10 = 2 * capacity;
            else
              v10 = 1;
            for ( ; v10 < v8; v10 *= 2 )
              ;
            if ( v10 <= 2 )
              v10 = 2;
            if ( v10 - v8 > 0x10000 )
              v10 = size + 65537;
            if ( v10 != (_DWORD)size )
            {
              v11 = 8i64 * v10;
              if ( !is_mul_ok(v10, 8ui64) )
                v11 = -1i64;
              v12 = UFG::qMalloc(v11, "qArray.Add", 0i64);
              v13 = (UFG::CoverPosition **)v12;
              if ( this->m_aCoverPositions.p )
              {
                for ( j = 0; j < this->m_aCoverPositions.size; ++j )
                  v12[j] = (UFG::allocator::free_link)this->m_aCoverPositions.p[j];
                operator delete[](this->m_aCoverPositions.p);
              }
              this->m_aCoverPositions.p = v13;
              this->m_aCoverPositions.capacity = v10;
            }
          }
          this->m_aCoverPositions.size = v8;
          this->m_aCoverPositions.p[size] = v6;
          ++v6->m_iRefCount;
        }
      }
      if ( mem )
        operator delete[](mem);
      mem = 0i64;
      v15 = 0i64;
    }
    ++this->m_uCurrentGetCoverPositions;
  }
  if ( this->m_uCurrentGetCoverPositions == this->m_aCoverObjects.size )
    this->vfptr[1].IsCompleted(this);
}

// File Line: 768
// RVA: 0x352560
void __fastcall UFG::AICoverQuery::DetailedCullInit(UFG::AICoverQuery *this)
{
  this->m_uCurrentCulling = 0;
}

// File Line: 773
// RVA: 0x352250
void __fastcall UFG::AICoverQuery::DetailedCull(UFG::AICoverQuery *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  UFG::CombatRegion *v5; // r15
  unsigned __int64 Ticks; // rax
  unsigned int m_uCurrentCulling; // eax
  UFG::CoverPosition *v8; // rsi
  UFG::AICoverSearchParams *m_pSearchParams; // rdx
  __int64 v10; // rdi
  UFG::AICoverSearchParams *v11; // rdx
  float *v12; // rax
  float v13; // xmm2_4
  float v14; // xmm1_4
  __int64 size; // rbp
  unsigned int v16; // edi
  unsigned int capacity; // edx
  unsigned int v18; // edx
  UFG::qVector3 vPoint; // [rsp+28h] [rbp-40h] BYREF
  UFG::qVector3 v20; // [rsp+34h] [rbp-34h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->m_pSearchParams->m_pInitiator.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v5 = *(UFG::CombatRegion **)&m_pComponent[15].m_TypeUID;
  if ( (_S33 & 1) == 0 )
  {
    _S33 |= 1u;
    *(_QWORD *)&vOffset.x = 0i64;
    LODWORD(vOffset.z) = (_DWORD)FLOAT_1_0;
  }
  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentCulling = this->m_uCurrentCulling;
    if ( m_uCurrentCulling >= this->m_aCoverPositions.size )
      break;
    v8 = this->m_aCoverPositions.p[m_uCurrentCulling];
    if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v8->vfptr->__vecDelDtor + 2))(v8) )
    {
      if ( v8->vfptr->CanUse(v8, this->m_pSearchParams->m_pInitiator.m_pPointer) )
      {
        m_pSearchParams = this->m_pSearchParams;
        if ( !m_pSearchParams->m_bConstrainMaxDistance
          || ((unsigned __int8 (__fastcall *)(UFG::CoverPosition *, UFG::AICoverSearchParams::HostileTarget *))v8->vfptr->InRange2)(
               v8,
               m_pSearchParams->m_aHostileTargets.p) )
        {
          v10 = 0i64;
          if ( this->m_pSearchParams->m_aHostileTargets.size )
          {
            while ( !((unsigned __int8 (__fastcall *)(UFG::CoverPosition *, UFG::AICoverSearchParams::HostileTarget *))v8->vfptr->InRange2)(
                       v8,
                       &this->m_pSearchParams->m_aHostileTargets.p[v10]) )
            {
              v10 = (unsigned int)(v10 + 1);
              if ( (unsigned int)v10 >= this->m_pSearchParams->m_aHostileTargets.size )
                goto LABEL_23;
            }
          }
          else
          {
LABEL_23:
            v11 = this->m_pSearchParams;
            if ( v11->m_bIgnoreDirection
              || ((unsigned __int8 (__fastcall *)(UFG::CoverPosition *, UFG::AICoverSearchParams::HostileTarget *))v8->vfptr->FacesPosition)(
                   v8,
                   v11->m_aHostileTargets.p) )
            {
              if ( !v5
                || (v12 = (float *)v8->vfptr->GetSyncPos(v8, &v20),
                    v13 = vOffset.z + v12[2],
                    v14 = vOffset.y + v12[1],
                    vPoint.x = vOffset.x + *v12,
                    vPoint.y = v14,
                    vPoint.z = v13,
                    UFG::CombatRegion::IsHitPoint(v5, &vPoint)) )
              {
                ++v8->m_iRefCount;
                size = this->m_aCulledObjects.size;
                v16 = size + 1;
                capacity = this->m_aCulledObjects.capacity;
                if ( (int)size + 1 > capacity )
                {
                  if ( capacity )
                    v18 = 2 * capacity;
                  else
                    v18 = 1;
                  for ( ; v18 < v16; v18 *= 2 )
                    ;
                  if ( v18 <= 2 )
                    v18 = 2;
                  if ( v18 - v16 > 0x10000 )
                    v18 = size + 65537;
                  UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
                    (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_aCulledObjects,
                    v18,
                    "qArray.Add");
                }
                this->m_aCulledObjects.size = v16;
                this->m_aCulledObjects.p[size] = v8;
              }
            }
          }
        }
      }
    }
    ++this->m_uCurrentCulling;
  }
  if ( this->m_uCurrentCulling == this->m_aCoverPositions.size )
    this->vfptr[1].IsCompleted(this);
}

// File Line: 852
// RVA: 0x37CC30
void __fastcall UFG::AICoverQuery::PrioritizePointsInit(UFG::AICoverQuery *this)
{
  this->m_uCurrentPrioritizing = 0;
}

// File Line: 857
// RVA: 0x37C960
void __fastcall UFG::AICoverQuery::PrioritizePoints(UFG::AICoverQuery *this)
{
  unsigned __int64 Ticks; // rax
  unsigned int m_uCurrentPrioritizing; // eax
  UFG::CoverPosition *v4; // rsi
  UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0> *p_m_aQueryRecords; // r14
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v8; // edi
  unsigned int v9; // edx
  UFG::AICoverQuery::CoverQueryRecord *v10; // rdi
  float DistanceToTargetPriority; // xmm0_4
  float v12; // xmm0_4
  float RadialSpreadFromAlliesPriority; // xmm0_4
  UFG::AICoverSearchParams *m_pSearchParams; // rax
  float v15; // xmm4_4
  UFG::AICoverSearchParams *v16; // rax
  float m_fMinimumPriority; // xmm0_4
  UFG::CoverPosition *m_pCoverPosition; // rcx

  while ( this->m_bCanContinue )
  {
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->m_uStartTicks, Ticks) >= this->m_fDuration )
      break;
    m_uCurrentPrioritizing = this->m_uCurrentPrioritizing;
    if ( m_uCurrentPrioritizing >= this->m_aCulledObjects.size )
      break;
    v4 = this->m_aCulledObjects.p[m_uCurrentPrioritizing];
    if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v4->vfptr->__vecDelDtor + 2))(v4)
      || !v4->vfptr->CanUse(v4, this->m_pSearchParams->m_pInitiator.m_pPointer) )
    {
      goto LABEL_31;
    }
    p_m_aQueryRecords = &this->m_aQueryRecords;
    size = this->m_aQueryRecords.size;
    capacity = this->m_aQueryRecords.capacity;
    v8 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v9 = 2 * capacity;
      else
        v9 = 1;
      for ( ; v9 < v8; v9 *= 2 )
        ;
      if ( v9 - v8 > 0x10000 )
        v9 = size + 65537;
      UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0>::Reallocate(&this->m_aQueryRecords, v9, "qArray.Add");
    }
    p_m_aQueryRecords->size = v8;
    v10 = &this->m_aQueryRecords.p[size];
    v10->m_fDistancePriority = UFG::AICoverQuery::GetDistancePriority(this, v4);
    DistanceToTargetPriority = UFG::AICoverQuery::GetDistanceToTargetPriority(this, v4);
    v10->m_fSweetSpotPriority = 0.0;
    v10->m_fDistanceToTargetPriority = DistanceToTargetPriority;
    v10->m_fLineOfSightPriority = UFG::AICoverQuery::GetLineOfSightPriority(this, v4);
    v12 = this->m_pSearchParams->m_fDirectLineOfSightWeight <= 0.0
        ? 0.0
        : UFG::AICoverQuery::GetDirectLineOfSightPriority(this, v4);
    v10->m_fDirectLineOfSightPriority = v12;
    v10->m_fNotExposedPriority = UFG::AICoverQuery::GetNotExposedPriority(this, v4);
    v10->m_fDistanceFromAlliesPriority = UFG::AICoverQuery::GetDistanceFromAlliesPriority(this, v4);
    RadialSpreadFromAlliesPriority = UFG::AICoverQuery::GetRadialSpreadFromAlliesPriority(this, v4);
    v10->m_fRadialSpreadFromAlliesPriority = RadialSpreadFromAlliesPriority;
    m_pSearchParams = this->m_pSearchParams;
    v15 = (float)((float)((float)((float)((float)((float)((float)(m_pSearchParams->m_fDistanceToTargetWeight
                                                                * v10->m_fDistanceToTargetPriority)
                                                        + (float)(m_pSearchParams->m_fDistanceWeight
                                                                * v10->m_fDistancePriority))
                                                + (float)(m_pSearchParams->m_fSweetSpotWeight * v10->m_fSweetSpotPriority))
                                        + (float)(m_pSearchParams->m_fLineOfSightWeight * v10->m_fLineOfSightPriority))
                                + (float)(m_pSearchParams->m_fDirectLineOfSightWeight * v10->m_fDirectLineOfSightPriority))
                        + (float)(m_pSearchParams->m_fNotExposedWeight * v10->m_fNotExposedPriority))
                + (float)(m_pSearchParams->m_fDistanceFromAlliesWeight * v10->m_fDistanceFromAlliesPriority))
        + (float)(RadialSpreadFromAlliesPriority * m_pSearchParams->m_fRadialSpreadFromAlliesWeight);
    v4->m_fPriority = v15;
    v16 = this->m_pSearchParams;
    m_fMinimumPriority = v16->m_fMinimumPriority;
    if ( m_fMinimumPriority >= 0.0 && v15 <= m_fMinimumPriority )
      goto LABEL_24;
    if ( v10->m_fLineOfSightPriority <= 0.0 && v10->m_fDirectLineOfSightPriority <= 0.0 && v16->m_bLineOfSightRequired
      || (v10->m_pCoverPosition = v4,
          ++v4->m_iRefCount,
          !(unsigned __int8)UFG::AICoverQuery::CoverQueryRecord::FindMeshPos(v10)) )
    {
LABEL_24:
      m_pCoverPosition = v10->m_pCoverPosition;
      if ( m_pCoverPosition )
      {
        if ( m_pCoverPosition->m_iRefCount-- == 1 )
          m_pCoverPosition->vfptr->__vecDelDtor(m_pCoverPosition, 1u);
        v10->m_pCoverPosition = 0i64;
      }
      v10->m_bPathFound = 0;
      if ( p_m_aQueryRecords->size > 1 )
      {
        --p_m_aQueryRecords->size;
        goto LABEL_31;
      }
      p_m_aQueryRecords->size = 0;
      ++this->m_uCurrentPrioritizing;
    }
    else
    {
LABEL_31:
      ++this->m_uCurrentPrioritizing;
    }
  }
  if ( this->m_uCurrentPrioritizing == this->m_aCulledObjects.size )
  {
    if ( this->m_aQueryRecords.size )
      this->vfptr[1].IsCompleted(this);
    else
      this->m_uState = 14;
  }
}

// File Line: 932
// RVA: 0x389F10
void __fastcall UFG::AICoverQuery::TestDirectPathInit(UFG::AICoverQuery *this)
{
  this->m_uCurrentTestDirectPath = 0;
}

// File Line: 1033
// RVA: 0x389F00
void __fastcall UFG::AICoverQuery::PathTestInit(UFG::AICoverQuery *this)
{
  this->vfptr[1].IsCompleted(this);
}

// File Line: 1039
// RVA: 0x37BE60
void __fastcall UFG::AICoverQuery::PathTest(UFG::AICoverQuery *this)
{
  UFG::AICoverSearchParams *m_pSearchParams; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  unsigned int i; // esi
  UFG::AICoverQuery::CoverQueryRecord *v10; // r14
  UFG::CoverPosition *m_pCoverPosition; // rbx
  UFG::qVector3 *v12; // rax
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::DaemonManager *v15; // rax
  unsigned int j; // edx
  UFG::AICoverQuery::CoverQueryRecord *v17; // rcx
  float v18; // xmm1_4
  float v19; // xmm0_4
  UFG::NavPath *v20; // rax
  UFG::NavPath *m_pNavPath; // rcx
  UFG::NavPath *v23; // rcx
  UFG::DaemonQueryOutput output; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v25; // [rsp+38h] [rbp-A0h]
  void *mem; // [rsp+40h] [rbp-98h]
  UFG::NavPath *v27; // [rsp+48h] [rbp-90h]
  UFG::FindPathMultiDestPrioritizedImmediateQuery v28; // [rsp+50h] [rbp-88h] BYREF

  *(_QWORD *)(&v28.m_npFrom.m_aiMeshUid + 1) = -2i64;
  m_pSearchParams = this->m_pSearchParams;
  if ( m_pSearchParams->m_bSkipPathfind )
  {
    this->vfptr[1].IsCompleted(this);
  }
  else
  {
    m_pPointer = (UFG::SimObjectGame *)m_pSearchParams->m_pInitiator.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    *(_QWORD *)&v28.m_internalType = 1i64;
    v28.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathMultiDestPrioritizedImmediateQuery::`vftable;
    v28.m_daemonType = LODWORD(UFG::qVector3::msZero.z);
    *(hkVector4f *)&v28.m_pOutput = (hkVector4f)hkvZero_13.m_quad;
    *(_QWORD *)&v28.m_npFrom.m_vPosition.x = -1i64;
    *(_QWORD *)&v28.m_npFrom.m_bValid = 0i64;
    v28.m_npFrom.m_hkvMeshPosition.m_quad.m128_i32[0] = -1;
    *(_QWORD *)&v28.m_npFrom.m_packedKey = 0i64;
    v28.m_npFrom.m_hkvMeshPosition.m_quad.m128_u64[1] = 0i64;
    output.m_id = DaemonType_Navigation;
    *(_QWORD *)&output.m_internalType = 1i64;
    output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathMultiDestPrioritizedOutput::`vftable;
    mem = 0i64;
    v25 = 0i64;
    v27 = 0i64;
    ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_npQueryCenter.vfptr->Validate)(&this->m_npQueryCenter);
    y = this->m_npQueryCenter.m_vPosition.y;
    z = this->m_npQueryCenter.m_vPosition.z;
    v28.m_npFrom.m_vPosition.x = this->m_npQueryCenter.m_vPosition.x;
    v28.m_npFrom.m_vPosition.y = y;
    *(float *)&v28.m_daemonType = z;
    if ( this->m_npQueryCenter.m_bValid )
    {
      LOBYTE(v28.m_mode) = this->m_npQueryCenter.m_bValid;
      *(hkVector4f *)&v28.m_pOutput = this->m_npQueryCenter.m_hkvMeshPosition;
      LODWORD(v28.m_npFrom.m_vPosition.x) = this->m_npQueryCenter.m_packedKey;
      LODWORD(v28.m_npFrom.m_vPosition.y) = this->m_npQueryCenter.m_aiMeshUid;
    }
    else
    {
      LOBYTE(v28.m_mode) = 0;
    }
    *(_QWORD *)&v28.m_npFrom.m_bValid = (char *)m_pComponent + 188;
    for ( i = 0; i < this->m_aQueryRecords.size; ++i )
    {
      v10 = &this->m_aQueryRecords.p[i];
      if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v10->m_pCoverPosition->vfptr->__vecDelDtor + 2))(v10->m_pCoverPosition) )
        goto LABEL_21;
      m_pCoverPosition = v10->m_pCoverPosition;
      v12 = m_pCoverPosition->vfptr->GetSyncPos(m_pCoverPosition, (UFG::qVector3 *)&v28.m_pNavParams);
      v13 = v12->y;
      v14 = v12->z;
      m_pCoverPosition->m_NavPosition.m_vPosition.x = v12->x;
      m_pCoverPosition->m_NavPosition.m_vPosition.y = v13;
      m_pCoverPosition->m_NavPosition.m_vPosition.z = v14;
      m_pCoverPosition->m_NavPosition.m_bValid = 0;
      ((void (__fastcall *)(UFG::HavokNavPosition *))m_pCoverPosition->m_NavPosition.vfptr->Validate)(&m_pCoverPosition->m_NavPosition);
      if ( v10->m_pCoverPosition->m_NavPosition.vfptr->IsMeshPositionValid(&v10->m_pCoverPosition->m_NavPosition) )
        UFG::FindPathMultiDestPrioritizedImmediateQuery::AddDestination(
          &v28,
          &v10->m_pCoverPosition->m_NavPosition,
          v10->m_pCoverPosition->m_fPriority / this->m_pSearchParams->m_fPathWeight);
      else
LABEL_21:
        UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0>::FastDelete(&this->m_aQueryRecords, i--);
    }
    v15 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::SubmitQuery(v15, &v28, &output);
    if ( output.m_status == Status_Completed )
    {
      for ( j = 0; j < this->m_aQueryRecords.size; ++j )
      {
        v17 = &this->m_aQueryRecords.p[j];
        v18 = this->m_pSearchParams->m_fPathWeight * *((float *)mem + j);
        v17->m_bPathFound = 1;
        v17->m_fPathCost = v18;
        v19 = v17->m_pCoverPosition->m_fPriority - v18;
        if ( v19 > this->m_fBestCoverScore )
        {
          this->m_iBestCoverIndex = j;
          this->m_fBestCoverScore = v19;
        }
      }
      v20 = v27;
      if ( this->m_pFoundPath.m_pNavPath != v27 )
      {
        if ( v27 )
        {
          ++v27->m_uRefCount;
          v20 = v27;
        }
        m_pNavPath = this->m_pFoundPath.m_pNavPath;
        if ( m_pNavPath )
        {
          if ( m_pNavPath->m_uRefCount-- == 1 )
            m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
          v20 = v27;
        }
        this->m_pFoundPath.m_pNavPath = v20;
      }
    }
    this->vfptr[1].IsCompleted(this);
    v23 = v27;
    if ( v27 )
    {
      --v27->m_uRefCount;
      if ( !v23->m_uRefCount )
        v23->vfptr->__vecDelDtor(v23, 1u);
    }
    if ( mem )
      operator delete[](mem);
    mem = 0i64;
    v25 = 0i64;
    output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
    if ( *(_QWORD *)&v28.m_npFrom.m_packedKey )
      operator delete[](*(void **)&v28.m_npFrom.m_packedKey);
  }
}

// File Line: 1097
// RVA: 0x34E680
void __fastcall UFG::AICoverQuery::ChooseBest(UFG::AICoverQuery *this)
{
  unsigned int i; // edi
  UFG::AICoverQuery::CoverQueryRecord *v3; // rsi
  float m_fPriority; // xmm0_4
  int m_iBestCoverIndex; // eax
  UFG::CoverPosition *m_pCoverPosition; // rdi

  if ( this->m_pSearchParams->m_bSkipPathfind )
  {
    for ( i = 0; i < this->m_aQueryRecords.size; ++i )
    {
      v3 = &this->m_aQueryRecords.p[i];
      if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v3->m_pCoverPosition->vfptr->__vecDelDtor + 2))(v3->m_pCoverPosition) )
      {
        m_fPriority = v3->m_pCoverPosition->m_fPriority;
        if ( m_fPriority > this->m_fBestCoverScore )
        {
          this->m_fBestCoverScore = m_fPriority;
          this->m_iBestCoverIndex = i;
        }
      }
    }
  }
  m_iBestCoverIndex = this->m_iBestCoverIndex;
  if ( m_iBestCoverIndex >= 0
    && (m_pCoverPosition = this->m_aQueryRecords.p[m_iBestCoverIndex].m_pCoverPosition,
        (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&m_pCoverPosition->vfptr->__vecDelDtor + 2))(m_pCoverPosition))
    && m_pCoverPosition->vfptr->CanUse(m_pCoverPosition, this->m_pSearchParams->m_pInitiator.m_pPointer) )
  {
    this->m_pBestCoverPosition = m_pCoverPosition;
    ++m_pCoverPosition->m_iRefCount;
    this->vfptr[1].IsCompleted(this);
  }
  else
  {
    this->m_uState = 14;
  }
}

// File Line: 1137
// RVA: 0x35EED0
float __fastcall UFG::AICoverQuery::GetDistancePriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector3 *v6; // rax
  __m128 x_low; // xmm2
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  char v12[24]; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = this->m_pSearchParams->m_pInitiator.m_pPointer;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v6 = coverPosition->vfptr->GetSyncPos(coverPosition, v12);
  x_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.x);
  v8 = m_pTransformNodeComponent->mWorldTransform.v3.y - v6->y;
  v9 = m_pTransformNodeComponent->mWorldTransform.v3.z - v6->z;
  x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - v6->x) * (float)(x_low.m128_f32[0] - v6->x))
                            + (float)(v8 * v8))
                    + (float)(v9 * v9);
  v10 = _mm_sqrt_ps(x_low).m128_f32[0] / this->m_pSearchParams->m_fMaxDistance;
  if ( v10 >= 1.0 )
    v10 = *(float *)&FLOAT_1_0;
  return 1.0 - v10;
}

// File Line: 1151
// RVA: 0x35EF80
float __fastcall UFG::AICoverQuery::GetDistanceToTargetPriority(
        UFG::AICoverQuery *this,
        UFG::CoverPosition *coverPosition)
{
  UFG::AICoverSearchParams::HostileTarget *p; // rbx
  UFG::qVector3 *v4; // rax
  __m128 y_low; // xmm2
  float v6; // xmm0_4
  UFG::SimObjectCVBase *m_pPointer; // rcx
  float v8; // xmm6_4
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedBaseComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v11; // rcx
  __int16 v12; // dx
  UFG::SimComponent *ComponentOfType; // rax
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax
  float *v15; // rdx
  float v16; // xmm1_4
  float v17; // xmm6_4
  float result; // xmm0_4
  char v19[16]; // [rsp+20h] [rbp-28h] BYREF

  p = this->m_pSearchParams->m_aHostileTargets.p;
  v4 = coverPosition->vfptr->GetPosition(coverPosition, v19);
  y_low = (__m128)LODWORD(p->m_vPosition.y);
  v6 = p->m_vPosition.z - v4->z;
  m_pPointer = (UFG::SimObjectCVBase *)this->m_pSearchParams->m_pInitiator.m_pPointer;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v4->y) * (float)(y_low.m128_f32[0] - v4->y))
                            + (float)((float)(p->m_vPosition.x - v4->x) * (float)(p->m_vPosition.x - v4->x)))
                    + (float)(v6 * v6);
  LODWORD(v8) = _mm_sqrt_ps(y_low).m128_u32[0];
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID)),
        ComponentOfTypeHK
     && (v11 = (UFG::SimObjectGame *)ComponentOfTypeHK->m_pTargets[(unsigned __int8)ComponentOfTypeHK->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer) != 0i64
     && ((v12 = v11->m_Flags, (v12 & 0x4000) == 0) && v12 >= 0 && (v12 & 0x2000) == 0 && (v12 & 0x1000) == 0
       ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::GunComponent::_TypeUID))
       : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::GunComponent::_TypeUID)),
         ComponentOfType)) )
  {
    SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)ComponentOfType);
    v15 = *(float **)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                    + 8i64 * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                    + 8);
    v16 = v15[114];
    if ( v8 >= v16 )
      v17 = (float)(v15[113] - v8) / (float)(v15[113] - v16);
    else
      v17 = (float)(v8 - v15[112]) / (float)(v16 - v15[112]);
    if ( v17 <= 0.0 )
      return 0.0;
    return v17;
  }
  else
  {
    result = this->m_pSearchParams->m_fMaxDistanceToTarget - v8;
    if ( result <= 0.0 )
    {
      return 0.0;
    }
    else if ( result >= 1.0 )
    {
      return *(float *)&FLOAT_1_0;
    }
  }
  return result;
}

// File Line: 1206
// RVA: 0x360980
float __fastcall UFG::AICoverQuery::GetLineOfSightPriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  char v2; // bp
  __int64 v5; // rbx
  UFG::CoverPosition::FiringPositionEnum i; // edi
  UFG::AICoverSearchParams::HostileTarget *p; // r8
  char v8; // al
  UFG::qVector3 vResultPosition; // [rsp+20h] [rbp-108h] BYREF
  UFG::RayCastData data; // [rsp+30h] [rbp-F8h] BYREF

  v2 = 0;
  v5 = 1i64;
  for ( i = FP_Left; (unsigned int)i < FP_NUM_FIRING_POSITIONS; ++i )
  {
    if ( UFG::CoverPosition::GetFiringPosition(coverPosition, i, &vResultPosition) )
    {
      p = this->m_pSearchParams->m_aHostileTargets.p;
      data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      data.mInput.m_filterInfo = 0;
      data.mInput.m_userData = 0i64;
      data.mOutput.m_hitFraction = 1.0;
      data.mOutput.m_extraInfo = -1;
      data.mOutput.m_shapeKeyIndex = 0;
      data.mOutput.m_shapeKeys[0] = -1;
      data.mOutput.m_rootCollidable = 0i64;
      data.mDebugName = "GetLineOfSightPriority";
      data.mCollisionModelName.mUID = -1;
      UFG::RayCastData::Init(&data, &vResultPosition, &p->m_vPosition, 0xCu);
      v8 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      if ( v2 || !v8 )
        v2 = 1;
      if ( v8 )
        coverPosition->m_bfFiringPositionClear.mBits[(__int64)(int)i >> 6] &= ~v5;
      else
        coverPosition->m_bfFiringPositionClear.mBits[(__int64)(int)i >> 6] |= v5;
    }
    v5 = __ROL8__(v5, 1);
  }
  if ( v2 )
    return *(float *)&FLOAT_1_0;
  else
    return 0.0;
}

// File Line: 1247
// RVA: 0x35EAE0
float __fastcall UFG::AICoverQuery::GetDirectLineOfSightPriority(
        UFG::AICoverQuery *this,
        UFG::CoverPosition *coverPosition)
{
  char v2; // bp
  __int64 v5; // rbx
  UFG::CoverPosition::FiringPositionEnum i; // edi
  UFG::AICoverSearchParams::HostileTarget *p; // r8
  char v8; // al
  UFG::qVector3 vResultPosition; // [rsp+20h] [rbp-108h] BYREF
  UFG::RayCastData data; // [rsp+30h] [rbp-F8h] BYREF

  v2 = 0;
  v5 = 1i64;
  for ( i = FP_Left; (unsigned int)i < FP_NUM_FIRING_POSITIONS; ++i )
  {
    if ( UFG::CoverPosition::GetFiringPosition(coverPosition, i, &vResultPosition) )
    {
      p = this->m_pSearchParams->m_aHostileTargets.p;
      data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      data.mInput.m_filterInfo = 0;
      data.mInput.m_userData = 0i64;
      data.mOutput.m_hitFraction = 1.0;
      data.mOutput.m_extraInfo = -1;
      data.mOutput.m_shapeKeyIndex = 0;
      data.mOutput.m_shapeKeys[0] = -1;
      data.mOutput.m_rootCollidable = 0i64;
      data.mDebugName = "GetDirectLineOfSightPriority";
      data.mCollisionModelName.mUID = -1;
      UFG::RayCastData::Init(&data, &vResultPosition, &p->m_vDirectTarget, 0xCu);
      v8 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      if ( v2 || !v8 )
        v2 = 1;
      if ( v8 )
        coverPosition->m_bfFiringPositionClear.mBits[(__int64)(int)i >> 6] &= ~v5;
      else
        coverPosition->m_bfFiringPositionClear.mBits[(__int64)(int)i >> 6] |= v5;
    }
    v5 = __ROL8__(v5, 1);
  }
  if ( v2 )
    return *(float *)&FLOAT_1_0;
  else
    return 0.0;
}

// File Line: 1288
// RVA: 0x35F3F0
float __fastcall UFG::AICoverQuery::GetExposure(
        UFG::AICoverQuery *this,
        UFG::qVector3 *vHostilePosition,
        UFG::qVector3 *vInCoverPosition,
        UFG::qVector3 *vAlongEdge,
        UFG::qVector3 *vEdgePosition,
        UFG::qVector3 *vEdgeDirection)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float y; // xmm9_4
  float v11; // xmm1_4
  float v12; // xmm9_4
  float v13; // xmm8_4
  __m128 z_low; // xmm7
  __m128 v15; // xmm2
  float v16; // xmm1_4
  float v17; // xmm2_4

  v6 = vHostilePosition->x - vEdgePosition->x;
  v7 = vHostilePosition->y - vEdgePosition->y;
  v8 = vHostilePosition->z - vEdgePosition->z;
  if ( (float)((float)((float)(v7 * vEdgeDirection->y) + (float)(v6 * vEdgeDirection->x))
             + (float)(v8 * vEdgeDirection->z)) < 0.0 )
    return 0.0;
  z_low = (__m128)LODWORD(vAlongEdge->z);
  y = vAlongEdge->y;
  v11 = y * v6;
  v12 = (float)(y * v8) - (float)(z_low.m128_f32[0] * v7);
  v13 = (float)(vAlongEdge->x * v7) - v11;
  z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v6) - (float)(vAlongEdge->x * v8);
  v15 = z_low;
  v15.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v12 * v12)) + (float)(v13 * v13);
  if ( v15.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
  v17 = (float)((float)((float)((float)((float)(vInCoverPosition->y - vHostilePosition->y)
                                      * (float)(z_low.m128_f32[0] * v16))
                              + (float)((float)(vInCoverPosition->x - vHostilePosition->x) * (float)(v12 * v16)))
                      + (float)((float)(vInCoverPosition->z - vHostilePosition->z) * (float)(v13 * v16)))
              + 0.30000001)
      * 1.6666666;
  if ( v17 <= 0.0 )
    return 0.0;
  if ( v17 >= 1.0 )
    return *(float *)&FLOAT_1_0;
  return v17;
}

// File Line: 1311
// RVA: 0x361000
float __fastcall UFG::AICoverQuery::GetNotExposedPriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  UFG::CoverCorner *v4; // r13
  UFG::CoverCorner *v5; // r12
  float v6; // xmm0_4
  float v7; // xmm10_4
  float v8; // xmm11_4
  float v9; // xmm9_4
  float v10; // xmm12_4
  float v11; // xmm15_4
  float v12; // xmm6_4
  float v13; // xmm8_4
  float v14; // xmm7_4
  UFG::qVector3 *v15; // rax
  float v16; // xmm6_4
  float v17; // xmm8_4
  UFG::ParkourHandle *m_pPointer; // rbx
  __int64 v19; // r14
  UFG::AICoverSearchParams *m_pSearchParams; // rdx
  float v21; // xmm8_4
  UFG::qVector3 *p_m_vPosition; // r15
  float y; // xmm4_4
  float z; // xmm2_4
  float Exposure; // xmm0_4
  UFG::ParkourHandle *v26; // rcx
  float v27; // xmm0_4
  UFG::ParkourHandle *v28; // rcx
  float v29; // xmm12_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm11_4
  float v33; // xmm9_4
  float v34; // xmm10_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm8_4
  UFG::qVector3 *v38; // rax
  float v39; // xmm7_4
  float v40; // xmm8_4
  float v41; // xmm6_4
  UFG::AICoverSearchParams::HostileTarget *p; // rdx
  float result; // xmm0_4
  float v44; // [rsp+30h] [rbp-90h] BYREF
  float v45; // [rsp+34h] [rbp-8Ch]
  float v46; // [rsp+38h] [rbp-88h]
  UFG::qVector3 p0; // [rsp+40h] [rbp-80h] BYREF
  UFG::qVector3 p1; // [rsp+4Ch] [rbp-74h] BYREF
  UFG::qVector3 v49; // [rsp+58h] [rbp-68h] BYREF
  UFG::qVector3 vAlongEdge; // [rsp+68h] [rbp-58h] BYREF
  UFG::qVector3 vEdgeDirection; // [rsp+78h] [rbp-48h] BYREF
  UFG::qVector3 vEdgePosition; // [rsp+88h] [rbp-38h] BYREF
  UFG::qVector3 rayEnd; // [rsp+98h] [rbp-28h] BYREF
  UFG::qVector3 v54; // [rsp+A8h] [rbp-18h] BYREF
  UFG::qVector3 vInCoverPosition; // [rsp+B8h] [rbp-8h] BYREF
  UFG::qVector3 out; // [rsp+C8h] [rbp+8h] BYREF
  UFG::qVector3 v57; // [rsp+D8h] [rbp+18h] BYREF
  UFG::qVector3 v2; // [rsp+E8h] [rbp+28h] BYREF
  UFG::qVector3 v59; // [rsp+F8h] [rbp+38h] BYREF
  UFG::qVector3 v60; // [rsp+108h] [rbp+48h] BYREF
  __int64 v61; // [rsp+118h] [rbp+58h]
  char v62[16]; // [rsp+120h] [rbp+60h] BYREF
  UFG::RayCastData data; // [rsp+130h] [rbp+70h] BYREF
  float v64; // [rsp+300h] [rbp+240h]
  float v65; // [rsp+308h] [rbp+248h]
  float v66; // [rsp+310h] [rbp+250h]
  float v67; // [rsp+318h] [rbp+258h]

  v61 = -2i64;
  v4 = UFG::CoverCornerHandle::Get(&coverPosition->m_LeftCorner);
  v5 = UFG::CoverCornerHandle::Get(&coverPosition->m_RightCorner);
  coverPosition->vfptr->GetWallNormal(coverPosition, (UFG::qVector3 *)&v44);
  if ( coverPosition->vfptr->GetHeight(coverPosition) >= 1.5 )
    v6 = FLOAT_1_55;
  else
    v6 = *(float *)&FLOAT_1_0;
  v67 = v6 - 0.30000001;
  v7 = (float)(v44 * UFG::qVector3::msDirUp.y) - (float)(v45 * UFG::qVector3::msDirUp.x);
  v65 = v7;
  v8 = (float)(v46 * UFG::qVector3::msDirUp.x) - (float)(v44 * UFG::qVector3::msDirUp.z);
  v66 = v8;
  v9 = (float)(v45 * UFG::qVector3::msDirUp.z) - (float)(v46 * UFG::qVector3::msDirUp.y);
  v64 = v9;
  vEdgeDirection.x = v9;
  vEdgeDirection.y = v8;
  p0.x = v7;
  v10 = 0.0;
  v11 = 0.0;
  v12 = UFG::qVector3::msDirUp.z * 0.64999998;
  v13 = UFG::qVector3::msDirUp.y * 0.64999998;
  v14 = UFG::qVector3::msDirUp.x * 0.64999998;
  v15 = coverPosition->vfptr->GetSyncPos(coverPosition, &v57);
  v16 = v12 + v15->z;
  v17 = v13 + v15->y;
  rayEnd.x = v14 + v15->x;
  rayEnd.y = v17;
  rayEnd.z = v16;
  m_pPointer = coverPosition->m_pParkourHandle.m_pPointer;
  if ( m_pPointer )
  {
    UFG::ParkourHandle::GetEndpoints(coverPosition->m_pParkourHandle.m_pPointer, &p0, &p1);
    UFG::ParkourHandle::GetNormal(m_pPointer, &out);
  }
  v19 = 0i64;
  m_pSearchParams = this->m_pSearchParams;
  if ( m_pSearchParams->m_aHostileTargets.size )
  {
    v21 = *(float *)&FLOAT_1_0;
    while ( 1 )
    {
      p_m_vPosition = &m_pSearchParams->m_aHostileTargets.p[v19].m_vPosition;
      if ( (_S35 & 1) == 0 )
      {
        _S35 |= 1u;
        kfAngleToIgnoreParkourSideExposure = 0.34906587;
      }
      if ( v4 )
        break;
      if ( m_pPointer )
      {
        v26 = m_pPointer->mCachedLeftNeighbor.m_pPointer;
        if ( !v26
          || (UFG::ParkourHandle::GetNormal(v26, &v2),
              v21 = *(float *)&FLOAT_1_0,
              UFG::qHeadingDifference2D(&out, &v2) <= kfAngleToIgnoreParkourSideExposure) )
        {
          vInCoverPosition.x = (float)(p0.x - (float)(v9 * 0.34999999)) + (float)(v44 * 0.25);
          vInCoverPosition.y = (float)(p0.y - (float)(v8 * 0.34999999)) + (float)(v45 * 0.25);
          vInCoverPosition.z = (float)(p0.z - (float)(v7 * 0.34999999)) + (float)(v46 * 0.25);
          Exposure = UFG::AICoverQuery::GetExposure(
                       this,
                       p_m_vPosition,
                       &vInCoverPosition,
                       &UFG::qVector3::msDirUp,
                       &p0,
                       &vEdgeDirection);
          goto LABEL_16;
        }
      }
LABEL_17:
      if ( v5 )
      {
        vEdgePosition = v5->m_vCornerPosition;
        coverPosition->vfptr->GetSyncPos(coverPosition, &v59);
        LODWORD(v54.x) = LODWORD(v9) ^ _xmm[0];
        LODWORD(v54.y) = LODWORD(v8) ^ _xmm[0];
        LODWORD(v54.z) = LODWORD(v7) ^ _xmm[0];
        v27 = UFG::AICoverQuery::GetExposure(this, p_m_vPosition, &v59, &UFG::qVector3::msDirDown, &vEdgePosition, &v54);
        goto LABEL_23;
      }
      if ( m_pPointer )
      {
        v28 = m_pPointer->mCachedRightNeighbor.m_pPointer;
        if ( !v28
          || (UFG::ParkourHandle::GetNormal(v28, &v60),
              UFG::qHeadingDifference2D(&out, &v60) >= COERCE_FLOAT(LODWORD(kfAngleToIgnoreParkourSideExposure) ^ _xmm[0])) )
        {
          p0.z = p1.x;
          p1.x = p1.y;
          p1.y = p1.z;
          coverPosition->vfptr->GetSyncPos(coverPosition, &v57);
          LODWORD(v49.x) = LODWORD(v9) ^ _xmm[0];
          LODWORD(v49.y) = LODWORD(v8) ^ _xmm[0];
          LODWORD(v49.z) = LODWORD(v7) ^ _xmm[0];
          v27 = UFG::AICoverQuery::GetExposure(
                  this,
                  p_m_vPosition,
                  &v57,
                  &UFG::qVector3::msDirDown,
                  (UFG::qVector3 *)&p0.z,
                  &v49);
LABEL_23:
          v10 = v10 + v27;
        }
        v21 = *(float *)&FLOAT_1_0;
      }
      v29 = v10 * 1.3333334;
      if ( v29 >= v21 )
        v29 = v21;
      v30 = 0.0;
      if ( m_pPointer )
      {
        vAlongEdge.x = p1.x - p0.x;
        vAlongEdge.y = p1.y - p0.y;
        vAlongEdge.z = p1.z - p0.z;
        v49.x = (float)(v45 * (float)(p1.z - p0.z)) - (float)(v46 * (float)(p1.y - p0.y));
        v49.y = (float)(v46 * (float)(p1.x - p0.x)) - (float)(v44 * (float)(p1.z - p0.z));
        v31 = (float)(v44 * (float)(p1.y - p0.y)) - (float)(v45 * (float)(p1.x - p0.x));
        v49.z = v31;
        if ( v31 < 0.0 )
        {
          v49.x = (float)((float)(v45 * (float)(p1.z - p0.z)) - (float)(v46 * (float)(p1.y - p0.y))) * -1.0;
          v49.y = (float)((float)(v46 * (float)(p1.x - p0.x)) - (float)(v44 * (float)(p1.z - p0.z))) * -1.0;
          v49.z = v31 * -1.0;
          vAlongEdge.x = (float)(p1.x - p0.x) * -1.0;
          vAlongEdge.y = (float)(p1.y - p0.y) * -1.0;
          vAlongEdge.z = (float)(p1.z - p0.z) * -1.0;
        }
        v32 = v44 * 0.25;
        v33 = v45 * 0.25;
        v34 = v46 * 0.25;
        v35 = UFG::qVector3::msDirUp.x * v67;
        v36 = UFG::qVector3::msDirUp.y * v67;
        v37 = UFG::qVector3::msDirUp.z * v67;
        v38 = coverPosition->vfptr->GetSyncPos(coverPosition, v62);
        v39 = v36 + v38->y;
        v40 = v37 + v38->z;
        vEdgeDirection.x = (float)(v35 + v38->x) - v32;
        vEdgeDirection.y = v39 - v33;
        vEdgeDirection.z = v40 - v34;
        v30 = UFG::AICoverQuery::GetExposure(this, p_m_vPosition, &vEdgeDirection, &vAlongEdge, &p0, &v49) * 2.0;
        v21 = *(float *)&FLOAT_1_0;
        v9 = v64;
        v7 = v65;
        v8 = v66;
        if ( v30 >= 1.0 )
          v30 = *(float *)&FLOAT_1_0;
      }
      v41 = v21 - (float)((float)(v21 - v30) * (float)(v21 - v29));
      if ( v41 < 0.89999998 )
      {
        p = this->m_pSearchParams->m_aHostileTargets.p;
        data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
        data.mInput.m_filterInfo = 0;
        data.mInput.m_userData = 0i64;
        data.mOutput.m_hitFraction = 1.0;
        data.mOutput.m_extraInfo = -1;
        data.mOutput.m_shapeKeyIndex = 0;
        data.mOutput.m_shapeKeys[0] = -1;
        data.mOutput.m_rootCollidable = 0i64;
        data.mDebugName = "GetNotExposedPriority";
        data.mCollisionModelName.mUID = -1;
        UFG::RayCastData::Init(&data, &p->m_vPosition, &rayEnd, 0xCu);
        v21 = *(float *)&FLOAT_1_0;
        if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
          v41 = *(float *)&FLOAT_1_0;
      }
      v11 = v11 + v41;
      v19 = (unsigned int)(v19 + 1);
      m_pSearchParams = this->m_pSearchParams;
      v10 = 0.0;
      if ( (unsigned int)v19 >= m_pSearchParams->m_aHostileTargets.size )
        goto LABEL_36;
    }
    y = v4->m_vCornerPosition.y;
    z = v4->m_vCornerPosition.z;
    vAlongEdge.x = (float)(v4->m_vCornerPosition.x - (float)(v9 * 0.34999999)) + (float)(v44 * 0.25);
    vAlongEdge.y = (float)(y - (float)(v8 * 0.34999999)) + (float)(v45 * 0.25);
    vAlongEdge.z = (float)(z - (float)(v7 * 0.34999999)) + (float)(v46 * 0.25);
    Exposure = UFG::AICoverQuery::GetExposure(
                 this,
                 p_m_vPosition,
                 &vAlongEdge,
                 &UFG::qVector3::msDirUp,
                 &v4->m_vCornerPosition,
                 &vEdgeDirection);
LABEL_16:
    v10 = Exposure;
    goto LABEL_17;
  }
LABEL_36:
  LODWORD(result) = LODWORD(v11) ^ _xmm[0];
  return result;
}

// File Line: 1496
// RVA: 0x35EE00
float __fastcall UFG::AICoverQuery::GetDistanceFromAlliesPriority(
        UFG::AICoverQuery *this,
        UFG::CoverPosition *coverPosition)
{
  __int64 v3; // rdx
  unsigned int size; // r8d
  UFG::qVector3 *p; // r9
  float v6; // xmm0_4
  int v8[8]; // [rsp+28h] [rbp-20h] BYREF

  if ( (_S36 & 1) == 0 )
  {
    _S36 |= 1u;
    kfMinRange2 = kfMinRange * kfMinRange;
  }
  coverPosition->vfptr->GetSyncPos(coverPosition, (UFG::qVector3 *)v8);
  v3 = 0i64;
  size = this->m_vAllyAvoidancePositions.size;
  if ( !size )
    return 0.0;
  p = this->m_vAllyAvoidancePositions.p;
  while ( 1 )
  {
    v6 = *(float *)&v8[1] - p[v3].y;
    if ( (float)((float)(v6 * v6) + (float)((float)(*(float *)v8 - p[v3].x) * (float)(*(float *)v8 - p[v3].x))) < kfMinRange2 )
      break;
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= size )
      return 0.0;
  }
  return FLOAT_N1_0;
}

// File Line: 1518
// RVA: 0x3622E0
float __fastcall UFG::AICoverQuery::GetRadialSpreadFromAlliesPriority(
        UFG::AICoverQuery *this,
        UFG::CoverPosition *coverPosition)
{
  UFG::AICoverSearchParams::HostileTarget *p; // rdx
  float z; // xmm3_4
  float x; // xmm14_4
  float y; // xmm15_4
  float v7; // xmm10_4
  __m128 v8; // xmm11
  float v9; // xmm12_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  unsigned int size; // eax
  float v13; // xmm10_4
  float v14; // xmm11_4
  float v15; // xmm7_4
  float v16; // xmm12_4
  UFG::qVector3 *v17; // rbx
  __int64 v18; // rdi
  float v19; // xmm5_4
  float v20; // xmm4_4
  __m128 y_low; // xmm2
  __m128 v22; // xmm3
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v27; // [rsp+20h] [rbp-B8h] BYREF
  float v28; // [rsp+24h] [rbp-B4h]
  float v29; // [rsp+28h] [rbp-B0h]
  float v30; // [rsp+E0h] [rbp+8h]

  coverPosition->vfptr->GetSyncPos(coverPosition, (UFG::qVector3 *)&v27);
  v8 = (__m128)LODWORD(v28);
  p = this->m_pSearchParams->m_aHostileTargets.p;
  z = p->m_vPosition.z;
  x = p->m_vPosition.x;
  y = p->m_vPosition.y;
  v7 = v27 - p->m_vPosition.x;
  v8.m128_f32[0] = v28 - y;
  v9 = v29 - z;
  v10 = v8;
  v30 = z;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  size = this->m_vAllyAvoidancePositions.size;
  v13 = v7 * v11;
  v14 = v8.m128_f32[0] * v11;
  v15 = *(float *)&FLOAT_1_0;
  v16 = v9 * v11;
  if ( size )
  {
    v17 = this->m_vAllyAvoidancePositions.p;
    v18 = size;
    do
    {
      y_low = (__m128)LODWORD(v17->y);
      v19 = v17->z - z;
      v20 = v17->x - x;
      y_low.m128_f32[0] = y_low.m128_f32[0] - y;
      v22 = y_low;
      v22.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v20 * v20))
                      + (float)(v19 * v19);
      if ( v22.m128_f32[0] == 0.0 )
        v23 = 0.0;
      else
        v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
      LODWORD(v24) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)(y_low.m128_f32[0] * v23) * v14) + (float)((float)(v20 * v23) * v13))
                     + (float)((float)(v19 * v23) * v16)) & _xmm;
      if ( v24 <= -1.0 )
      {
        v24 = FLOAT_N1_0;
      }
      else if ( v24 >= 1.0 )
      {
        v24 = *(float *)&FLOAT_1_0;
      }
      v25 = acosf(v24) * 0.63661975;
      if ( v15 >= v25 )
        v15 = v25;
      z = v30;
      ++v17;
      --v18;
    }
    while ( v18 );
  }
  return v15;
}

// File Line: 1975
// RVA: 0x341980
void __fastcall UFG::PlayerCoverQuery::AdvanceState(UFG::PlayerCoverQuery *this)
{
  unsigned int v1; // eax

  v1 = *((_DWORD *)&unk_14206DA90 + 10 * this->m_uState);
  this->m_bStateNeedsInit = 1;
  if ( v1 == 6 )
    v1 = 13;
  this->m_uState = v1;
}

