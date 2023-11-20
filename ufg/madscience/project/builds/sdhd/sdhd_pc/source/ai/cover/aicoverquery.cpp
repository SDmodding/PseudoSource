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
  void (***v1)(void); // rbx
  UFG::AICoverQuery::CoverQueryRecord *v2; // rdi
  _DWORD *v3; // rax
  signed __int64 v4; // rcx
  int v5; // xmm1_4
  int v6; // xmm0_4
  char v8; // [rsp+20h] [rbp-18h]

  v1 = (void (***)(void))this->m_pCoverPosition;
  v2 = this;
  v3 = (_DWORD *)((__int64 (__fastcall *)(UFG::CoverPosition *, char *))(*v1)[15])(this->m_pCoverPosition, &v8);
  v4 = (signed __int64)(v1 + 32);
  v5 = v3[2];
  v6 = v3[1];
  *(_DWORD *)(v4 + 8) = *v3;
  *(_DWORD *)(v4 + 16) = v5;
  *(_DWORD *)(v4 + 12) = v6;
  *(_BYTE *)(v4 + 24) = 0;
  (*v1[32])();
  return ((__int64 (*)(void))v2->m_pCoverPosition->m_NavPosition.vfptr->IsMeshPositionValid)();
}

// File Line: 120
// RVA: 0x32B170
void __fastcall UFG::AICoverQuery::AICoverQuery(UFG::AICoverQuery *this)
{
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4

  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AIQuery::`vftable';
  this->m_bStateNeedsInit = 1;
  *(_QWORD *)&this->m_iRefCount = 0i64;
  v1 = (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AICoverQuery::`vftable';
  this->m_npQueryCenter.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->m_npQueryCenter.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npQueryCenter.m_vPosition.y = v2;
  this->m_npQueryCenter.m_vPosition.z = v3;
  this->m_npQueryCenter.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
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
  UFG::AICoverQuery *v1; // rbx
  UFG::AICoverSearchParams *v2; // rdi
  bool v3; // zf
  UFG::ParkourQuery *v4; // rdi
  unsigned int i; // edi
  UFG::CoverObjectBase *v6; // rcx
  unsigned int j; // edi
  UFG::CoverPosition *v8; // rcx
  unsigned int k; // edi
  UFG::CoverObjectGroup *v10; // rcx
  unsigned int l; // edi
  UFG::CoverPosition *v12; // rcx
  UFG::CoverPosition *v13; // rcx
  UFG::NavPath *v14; // rcx
  UFG::qVector3 *v15; // rcx
  UFG::AICoverQuery::CoverQueryRecord *v16; // rcx
  UFG::CoverObjectGroup **v17; // rcx
  UFG::CoverPosition **v18; // rcx
  UFG::CoverPosition **v19; // rcx
  UFG::CoverObjectBase **v20; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v21; // rdx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v22; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v23; // rax

  v1 = this;
  this->vfptr = (UFG::AIQueryVtbl *)&UFG::AICoverQuery::`vftable';
  v2 = this->m_pSearchParams;
  if ( v2 )
  {
    v3 = v2->m_iRefCount-- == 1;
    if ( v3 )
    {
      UFG::AICoverSearchParams::~AICoverSearchParams(v2);
      operator delete[](v2);
    }
    v1->m_pSearchParams = 0i64;
  }
  v4 = v1->m_pParkourQuery;
  if ( v4 )
  {
    UFG::ParkourQuery::~ParkourQuery(v1->m_pParkourQuery);
    operator delete[](v4);
    v1->m_pParkourQuery = 0i64;
  }
  for ( i = 0; i < v1->m_aCoverObjects.size; ++i )
  {
    v6 = v1->m_aCoverObjects.p[i];
    v3 = v6->m_iRefCount-- == 1;
    if ( v3 )
      v6->vfptr->__vecDelDtor(v6, 1u);
  }
  for ( j = 0; j < v1->m_aCulledObjects.size; ++j )
  {
    v8 = v1->m_aCulledObjects.p[j];
    v3 = v8->m_iRefCount-- == 1;
    if ( v3 )
      v8->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v8->vfptr, 1u);
  }
  for ( k = 0; k < v1->m_aCoverGroups.size; ++k )
  {
    v10 = v1->m_aCoverGroups.p[k];
    v3 = v10->m_iRefCount-- == 1;
    if ( v3 )
      v10->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v10->vfptr, 1u);
  }
  for ( l = 0; l < v1->m_aCoverPositions.size; ++l )
  {
    v12 = v1->m_aCoverPositions.p[l];
    v3 = v12->m_iRefCount-- == 1;
    if ( v3 )
      v12->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v12->vfptr, 1u);
  }
  v13 = v1->m_pBestCoverPosition;
  if ( v13 )
  {
    v3 = v13->m_iRefCount-- == 1;
    if ( v3 )
      v13->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v13->vfptr, 1u);
  }
  v14 = v1->m_pFoundPath.m_pNavPath;
  if ( v14 )
  {
    v3 = v14->m_uRefCount-- == 1;
    if ( v3 )
      v14->vfptr->__vecDelDtor(v14, 1u);
  }
  v15 = v1->m_vAllyAvoidancePositions.p;
  if ( v15 )
    operator delete[](v15);
  v1->m_vAllyAvoidancePositions.p = 0i64;
  *(_QWORD *)&v1->m_vAllyAvoidancePositions.size = 0i64;
  v16 = v1->m_aQueryRecords.p;
  if ( v16 )
  {
    if ( LODWORD(v16[-1].m_fDistanceFromAlliesPriority) )
      v16->vfptr->__vecDelDtor(v16, 3u);
    else
      operator delete[](&v16[-1].m_fDistanceFromAlliesPriority);
  }
  v1->m_aQueryRecords.p = 0i64;
  *(_QWORD *)&v1->m_aQueryRecords.size = 0i64;
  v17 = v1->m_aCoverGroups.p;
  if ( v17 )
    operator delete[](v17);
  v1->m_aCoverGroups.p = 0i64;
  *(_QWORD *)&v1->m_aCoverGroups.size = 0i64;
  v18 = v1->m_aCulledObjects.p;
  if ( v18 )
    operator delete[](v18);
  v1->m_aCulledObjects.p = 0i64;
  *(_QWORD *)&v1->m_aCulledObjects.size = 0i64;
  v19 = v1->m_aCoverPositions.p;
  if ( v19 )
    operator delete[](v19);
  v1->m_aCoverPositions.p = 0i64;
  *(_QWORD *)&v1->m_aCoverPositions.size = 0i64;
  v20 = v1->m_aCoverObjects.p;
  if ( v20 )
    operator delete[](v20);
  v1->m_aCoverObjects.p = 0i64;
  *(_QWORD *)&v1->m_aCoverObjects.size = 0i64;
  v21 = (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)&v1->mPrev;
  v22 = v1->mPrev;
  v23 = v1->mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  v21->mPrev = v21;
  v21->mNext = v21;
  v1->vfptr = (UFG::AIQueryVtbl *)&UFG::AIQuery::`vftable';
}

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
  UFG::ParkourQuery *v1; // rdx
  unsigned __int64 v2; // r8
  UFG::ParkourHandle *v3; // rdx
  UFG::ParkourHandle *v4; // rax
  UFG::ParkourHandle *v5; // rax

  v1 = this->m_pParkourQuery;
  if ( v1 )
  {
    v2 = 0i64;
    if ( v1->handlesOut.size )
    {
      do
      {
        v3 = v1->handlesOut.p[(unsigned int)v2].m_pPointer;
        if ( v3 )
        {
          v4 = v3->mCachedLeftNeighbor.m_pPointer;
          v3->mFramesUntilDeleted = 10;
          if ( v4 )
            v4->mFramesUntilDeleted = 10;
          v5 = v3->mCachedRightNeighbor.m_pPointer;
          if ( v5 )
            v5->mFramesUntilDeleted = 10;
        }
        v1 = this->m_pParkourQuery;
        ++v2;
      }
      while ( v2 < v1->handlesOut.size );
    }
  }
}

// File Line: 250
// RVA: 0x368F70
void __fastcall UFG::AICoverQuery::InitializeQuery(UFG::AICoverQuery *this)
{
  UFG::AICoverQuery *v1; // r12
  UFG::SimObjectCVBase *v2; // r13
  UFG::SimObjectCharacterPropertiesComponent *v3; // rax
  unsigned __int16 v4; // cx
  __int64 v5; // rbx
  UFG::TransformNodeComponent *v6; // rcx
  UFG::NearbyCharacterManager *v7; // r8
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 **i; // r15
  _QWORD *v11; // rdx
  __int64 v12; // rcx
  _QWORD *v13; // rax
  UFG::NearbyCharacterManager *v14; // rcx
  __int64 *v15; // rdx
  __int64 **v16; // rax
  signed __int64 v17; // r14
  __int64 v18; // rsi
  _QWORD *v19; // rdi
  UFG::SimObjectGame *v20; // rdi
  __int64 v21; // rbx
  signed __int64 v22; // rbp
  unsigned int v23; // ebx
  unsigned int v24; // edx
  unsigned int v25; // edx
  signed __int64 v26; // rbp
  UFG::qVector3 *v27; // rsi
  unsigned __int16 v28; // cx
  UFG::SimComponent *v29; // rax
  __int64 v30; // rbx
  float *v31; // rax
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  UFG::TransformNodeComponent *v35; // rbx
  __int64 j; // rax
  _QWORD *v37; // rdx
  __int64 v38; // rcx
  _QWORD *v39; // rax
  __int64 *v40; // rcx
  __int64 **v41; // rax
  __int64 v42; // [rsp+0h] [rbp-78h]
  __int64 v43; // [rsp+20h] [rbp-58h]
  char v44; // [rsp+28h] [rbp-50h]
  __int64 *v45; // [rsp+38h] [rbp-40h]
  __int64 **v46; // [rsp+40h] [rbp-38h]
  __int64 v47; // [rsp+80h] [rbp+8h]

  v43 = -2i64;
  v1 = this;
  UFG::AICoverQuery::AcquireQueryCenter(this);
  v2 = (UFG::SimObjectCVBase *)v1->m_pSearchParams->m_pInitiator.m_pPointer;
  v45 = (__int64 *)&v45;
  v46 = &v45;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v2->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2);
    }
  }
  else
  {
    v3 = 0i64;
  }
  v5 = v3->m_eFactionClass;
  v6 = (UFG::TransformNodeComponent *)v1->m_pSearchParams->m_pInitiator.m_pPointer;
  if ( v6 )
    v6 = (UFG::TransformNodeComponent *)v6->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v7 = UFG::NearbyCharacterManager::s_pInstance;
  v8 = (__int64)v46;
  v9 = (__int64)(v46 - 2);
  for ( i = (__int64 **)(&v42 + 5); v46 - 2 != i; v9 = (__int64)(v46 - 2) )
  {
    v11 = (_QWORD *)(v9 + 16);
    v12 = *(_QWORD *)(v9 + 16);
    v13 = (_QWORD *)v11[1];
    *(_QWORD *)(v12 + 8) = v13;
    *v13 = v12;
    *v11 = v11;
    v11[1] = v11;
    v8 = (__int64)v46;
  }
  v14 = (UFG::NearbyCharacterManager *)v7->m_Characters[0].mNode.mNext;
  if ( v14 != v7 )
  {
    v15 = v45;
    do
    {
      v16 = (__int64 **)&v14->m_Characters[1];
      v15[1] = (__int64)&v14->m_Characters[1];
      *v16 = v15;
      v16[1] = (__int64 *)&v45;
      v15 = (__int64 *)&v14->m_Characters[1];
      v45 = (__int64 *)&v14->m_Characters[1];
      v14 = (UFG::NearbyCharacterManager *)v14->m_Characters[0].mNode.mNext;
    }
    while ( v14 != v7 );
    v8 = (__int64)v46;
  }
  v17 = v8 - 16;
  v18 = v5;
  v47 = v5;
  if ( (__int64 **)(v8 - 16) != i )
  {
    while ( 1 )
    {
      v19 = *(_QWORD **)(v17 + 48);
      if ( !v19 )
        goto LABEL_52;
      if ( !(*(unsigned __int8 (__fastcall **)(_QWORD))(*v19 + 112i64))(*(_QWORD *)(v17 + 48)) )
        goto LABEL_52;
      v20 = (UFG::SimObjectGame *)v19[5];
      if ( v20 == (UFG::SimObjectGame *)v2 )
        goto LABEL_52;
      v21 = *(signed int *)(*(_QWORD *)(*(_QWORD *)(v17 + 48) + 280i64) + 200i64);
      if ( UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[0][v21 + 39 * v18] )
        goto LABEL_52;
      v22 = v1->m_vAllyAvoidancePositions.size;
      v23 = v22 + 1;
      v24 = v1->m_vAllyAvoidancePositions.capacity;
      if ( (signed int)v22 + 1 > v24 )
      {
        if ( v24 )
          v25 = 2 * v24;
        else
          v25 = 1;
        for ( ; v25 < v23; v25 *= 2 )
          ;
        if ( v25 - v23 > 0x10000 )
          v25 = v22 + 65537;
        UFG::qArray<UFG::qVector3,0>::Reallocate(&v1->m_vAllyAvoidancePositions, v25, "qArray.Add");
      }
      v1->m_vAllyAvoidancePositions.size = v23;
      v26 = v22;
      v27 = v1->m_vAllyAvoidancePositions.p;
      if ( !v20 )
        break;
      v28 = v20->m_Flags;
      if ( (v28 >> 14) & 1 )
      {
        v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v28 & 0x8000u) == 0 )
      {
        if ( (v28 >> 13) & 1 )
        {
          v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AICoverComponent::_TypeUID);
        }
        else if ( (v28 >> 12) & 1 )
        {
          v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AICoverComponent::_TypeUID);
        }
        else
        {
          v29 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v20->vfptr, UFG::AICoverComponent::_TypeUID);
        }
      }
      else
      {
        v29 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AICoverComponent::_TypeUID);
      }
      if ( !v29
        || (v30 = *(_QWORD *)&v29[1].m_Flags) == 0
        || !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v30 + 16i64))(v30) )
      {
        v35 = v20->m_pTransformNodeComponent;
LABEL_50:
        UFG::TransformNodeComponent::UpdateWorldTransform(v35);
        v32 = v35->mWorldTransform.v3.x;
        v33 = v35->mWorldTransform.v3.y;
        v34 = v35->mWorldTransform.v3.z;
        goto LABEL_51;
      }
      v31 = (float *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v30 + 120i64))(v30, &v44);
      v32 = *v31;
      v33 = v31[1];
      v34 = v31[2];
LABEL_51:
      v27[v26].x = v32;
      v27[v26].y = v33;
      v27[v26].z = v34;
      v18 = v47;
LABEL_52:
      v17 = *(_QWORD *)(v17 + 24) - 16i64;
      if ( (__int64 **)v17 == i )
        goto LABEL_53;
    }
    v35 = 0i64;
    goto LABEL_50;
  }
LABEL_53:
  v1->vfptr[1].IsCompleted((UFG::AIQuery *)&v1->vfptr);
  for ( j = (__int64)(v46 - 2); v46 - 2 != i; j = (__int64)(v46 - 2) )
  {
    v37 = (_QWORD *)(j + 16);
    v38 = *(_QWORD *)(j + 16);
    v39 = *(_QWORD **)(j + 24);
    *(_QWORD *)(v38 + 8) = v39;
    *v39 = v38;
    *v37 = v37;
    v37[1] = v37;
  }
  v40 = v45;
  v41 = v46;
  v45[1] = (__int64)v46;
  *v41 = v40;
}

// File Line: 327
// RVA: 0x3882B0
void __fastcall UFG::AICoverQuery::SetupSensor(UFG::AICoverQuery *this)
{
  UFG::AICoverQuery *v1; // rbx
  float v2; // xmm6_4
  UFG::allocator::free_link *v3; // rax
  float v4; // xmm1_4
  float v5; // xmm2_4
  UFG::ParkourQuery *v6; // rax

  v1 = this;
  if ( this->m_pParkourQuery )
  {
    ((void (__cdecl *)(UFG::AICoverQuery *))this->vfptr[1].IsCompleted)(this);
  }
  else
  {
    v2 = this->m_pSearchParams->m_fMaxDistance;
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
    v1->m_pParkourQuery = (UFG::ParkourQuery *)v3;
    LODWORD(v3[7].mNext) = 0;
    v1->m_pParkourQuery->userData = v1;
    v1->m_pParkourQuery->callback = 0i64;
    v4 = v1->m_npQueryCenter.m_vPosition.y;
    v5 = v1->m_npQueryCenter.m_vPosition.z;
    v6 = v1->m_pParkourQuery;
    v6->mCentre.x = v1->m_npQueryCenter.m_vPosition.x;
    v6->mCentre.y = v4;
    v6->mCentre.z = v5;
    v6->mCentre.w = 1.0;
    v1->m_pParkourQuery->mRadius = v2;
    UFG::ParkourQueryManager::AddAsyncQuery(UFG::ParkourQueryManager::mInstance, v1->m_pParkourQuery);
    v1->m_bCanContinue = 0;
  }
}

// File Line: 352
// RVA: 0x33F760
void __fastcall UFG::AICoverQuery::AcquireQueryCenter(UFG::AICoverQuery *this)
{
  UFG::AICoverQuery *v1; // rdi
  UFG::AICoverSearchParams *v2; // rcx
  hkVector4f *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  UFG::SimComponent *v5; // rax
  unsigned __int16 v6; // dx
  float v7; // xmm2_4
  int v8; // xmm1_4
  int v9; // xmm0_4
  signed __int64 v10; // rcx
  UFG::SimObjectGame *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  float v14; // eax
  float v15; // xmm1_4
  signed __int64 v16; // rcx
  char v17; // al

  v1 = this;
  v2 = this->m_pSearchParams;
  v3 = 0i64;
  if ( v2->m_bUseCombatRegionDestination )
  {
    v4 = (UFG::SimObjectGame *)v2->m_pInitiator.m_pPointer;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v5 = v4->m_Components.p[22].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIEntityComponent::_TypeUID);
        else
          v5 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        v5 = v4->m_Components.p[22].m_pComponent;
      }
    }
    else
    {
      v5 = 0i64;
    }
    v7 = *(float *)&v5[20].m_pSimObject;
    if ( v7 != UFG::qVector3::msZero.x
      || UFG::qVector3::msZero.y != *((float *)&v5[20].m_pSimObject + 1)
      || UFG::qVector3::msZero.z != *(float *)&v5[20].m_BoundComponentHandles.mNode.mPrev )
    {
      v8 = (int)v5[20].m_BoundComponentHandles.mNode.mPrev;
      v9 = HIDWORD(v5[20].m_pSimObject);
      v10 = (signed __int64)&v1->m_npQueryCenter;
      *(float *)(v10 + 8) = v7;
      *(_DWORD *)(v10 + 16) = v8;
      *(_DWORD *)(v10 + 12) = v9;
      *(_BYTE *)(v10 + 24) = 0;
      ((void (*)(void))v1->m_npQueryCenter.vfptr->Validate)();
    }
  }
  v11 = (UFG::SimObjectGame *)v1->m_pSearchParams->m_pInitiator.m_pPointer;
  if ( v11 )
  {
    v12 = v11->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v3 = (hkVector4f *)v11->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
        }
        else if ( (v12 >> 12) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
      }
      v3 = (hkVector4f *)v13;
    }
  }
  v14 = v3[5].m_quad.m128_f32[2];
  v15 = v3[6].m_quad.m128_f32[0];
  v16 = (signed __int64)&v1->m_npQueryCenter;
  *(float *)(v16 + 12) = v3[5].m_quad.m128_f32[3];
  *(float *)(v16 + 16) = v15;
  *(float *)(v16 + 8) = v14;
  v17 = v3[6].m_quad.m128_i8[8];
  if ( v17 )
  {
    v1->m_npQueryCenter.m_bValid = v17;
    v1->m_npQueryCenter.m_hkvMeshPosition = (hkVector4f)v3[7].m_quad;
    v1->m_npQueryCenter.m_packedKey = v3[8].m_quad.m128_u32[0];
    v1->m_npQueryCenter.m_aiMeshUid = v3[8].m_quad.m128_u32[1];
  }
  else
  {
    v1->m_npQueryCenter.m_bValid = 0;
  }
  (**(void (***)(void))v16)();
}

// File Line: 383
// RVA: 0x3584E0
void __fastcall UFG::AICoverQuery::GatherInRange(UFG::AICoverQuery *this)
{
  UFG::AICoverQuery *v1; // r15
  UFG::qVector3 *v2; // rbp
  UFG::AICoverSearchParams *v3; // rax
  float v4; // xmm9_4
  float v5; // xmm10_4
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v6; // rdi
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::qReflectInventoryBase **v9; // rbx
  unsigned int i; // er9
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  UFG::CoverDataInventory *v14; // rax
  UFG::CoverDataInventory *v15; // rsi
  float v16; // xmm1_4
  float v17; // xmm2_4
  signed int v18; // er10
  signed int v19; // er11
  __int64 v20; // rbx
  float v21; // xmm1_4
  signed int v22; // er8
  int v23; // ecx
  int v24; // eax
  unsigned int v25; // edx
  signed __int64 v26; // r9
  signed __int64 v27; // rbp
  __int64 v28; // rbx
  __int64 v29; // rcx
  __int64 v30; // r8
  __int64 *v31; // rax
  __int64 v32; // rcx
  UFG::CoverCorner *v33; // r12
  UFG::CoverCorner *v34; // r15
  float v35; // xmm2_4
  float v36; // xmm0_4
  UFG::allocator::free_link *v37; // rax
  UFG::allocator::free_link *v38; // rsi
  __int64 v39; // r13
  unsigned int v40; // ebp
  unsigned int v41; // ebx
  unsigned int v42; // ebx
  unsigned __int64 v43; // rax
  UFG::allocator::free_link *v44; // rax
  UFG::qReflectInventoryBase **v45; // r14
  __int64 v46; // r9
  UFG::ParkourQuery *v47; // rsi
  unsigned int j; // eax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v49; // rdx
  UFG::ParkourHandle *v50; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v51; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v52; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v53; // rax
  unsigned int v54; // eax
  bool v55; // r12
  UFG::SimObject *v56; // rbx
  UFG::TransformNodeComponent *v57; // rbx
  unsigned int v58; // er14
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v59; // rax
  UFG::ParkourHandle *v60; // rbx
  UFG::qVector3 *v61; // rax
  float v62; // xmm0_4
  __m128 v63; // xmm1
  UFG::allocator::free_link *v64; // rax
  __int64 v65; // rax
  __int64 v66; // rbp
  __int64 v67; // r15
  unsigned int v68; // ebx
  unsigned int v69; // edx
  unsigned int v70; // edx
  UFG::ParkourQuery *v71; // rdi
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v72; // rcx
  char *v73; // rbx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v74; // rdx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v75; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-198h]
  UFG::qVector3 p0; // [rsp+30h] [rbp-188h]
  UFG::qVector3 p1; // [rsp+3Ch] [rbp-17Ch]
  __int64 v79; // [rsp+48h] [rbp-170h]
  __int64 v80[25]; // [rsp+50h] [rbp-168h]
  int v81; // [rsp+118h] [rbp-A0h]
  UFG::AICoverQuery *v82; // [rsp+1C0h] [rbp+8h]
  UFG::qVector3 *v83; // [rsp+1C8h] [rbp+10h]
  __int64 *v84; // [rsp+1D0h] [rbp+18h]
  __int64 v85; // [rsp+1D8h] [rbp+20h]

  v82 = this;
  v79 = -2i64;
  v1 = this;
  v2 = &this->m_npQueryCenter.m_vPosition;
  v83 = &this->m_npQueryCenter.m_vPosition;
  v3 = this->m_pSearchParams;
  v4 = v3->m_fMaxZDistance;
  v5 = v3->m_fMaxDistance * v3->m_fMaxDistance;
  v6 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_aCoverObjects;
  if ( this->m_aCoverObjects.capacity < 0x80 && v6->size != 128 )
  {
    v7 = 1024i64;
    if ( !is_mul_ok(0x80ui64, 8ui64) )
      v7 = -1i64;
    v8 = UFG::qMalloc(v7, "AICoverQuery::m_aCoverObjects", 0i64);
    v9 = (UFG::qReflectInventoryBase **)v8;
    if ( v6->p )
    {
      for ( i = 0; i < v6->size; ++i )
        v8[i] = (UFG::allocator::free_link)v6->p[i];
      operator delete[](v6->p);
    }
    v6->p = v9;
    v6->capacity = 128;
  }
  v11 = v1->m_pSearchParams->m_fMaxDistance;
  v12 = v2->y;
  v13 = v2->x;
  v14 = UFG::CoverDataInventory::GetInstance();
  v15 = v14;
  v16 = v14->m_CornerGrid.mXMin;
  v17 = v14->m_CornerGrid.mGridSizeInv;
  v18 = (signed int)(float)((float)((float)(v13 - v11) - v16) * v17);
  if ( v18 < 0 )
    v18 = 0;
  v19 = (signed int)(float)((float)((float)(v13 + v11) - v16) * v17);
  v20 = v14->m_CornerGrid.mXDim;
  if ( v19 >= (signed int)v20 )
    v19 = v20 - 1;
  v21 = v14->m_CornerGrid.mYMin;
  v22 = (signed int)(float)((float)((float)(v12 - v11) - v21) * v17);
  if ( v22 < 0 )
    v22 = 0;
  v23 = (signed int)(float)((float)((float)(v12 + v11) - v21) * v17);
  v24 = v14->m_CornerGrid.mYDim;
  if ( v23 >= v24 )
    v23 = v24 - 1;
  v25 = 0;
  v81 = 0;
  if ( v22 <= v23 )
  {
    v26 = 16i64 * (v18 + v22 * (signed int)v20);
    v27 = 16 * v20;
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
            v25 = v81++ + 1;
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
    v2 = v83;
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
      v34 = *(UFG::CoverCorner **)(*v31 + 8);
      if ( v34 != (UFG::CoverCorner *)*v31 )
      {
        do
        {
          v35 = v34->m_vCornerPosition.z - v2->z;
          v36 = v34->m_vCornerPosition.y - v2->y;
          if ( (float)((float)((float)((float)(v34->m_vCornerPosition.x - v2->x)
                                     * (float)(v34->m_vCornerPosition.x - v2->x))
                             + (float)(v36 * v36))
                     + (float)(v35 * v35)) < v5
            && COERCE_FLOAT(LODWORD(v35) & _xmm) < v4 )
          {
            v37 = UFG::qMalloc(0x68ui64, "CoverObjectCorner", 0i64);
            v38 = v37;
            *(_QWORD *)&result.x = v37;
            if ( v37 )
            {
              v37->mNext = (UFG::allocator::free_link *)&UFG::CoverObjectBase::`vftable';
              LODWORD(v37[1].mNext) = 0;
              v37[2].mNext = 0i64;
              LODWORD(v37[3].mNext) = 0;
              v37->mNext = (UFG::allocator::free_link *)&UFG::CoverObjectCorner::`vftable';
              UFG::CoverCornerHandle::CoverCornerHandle((UFG::CoverCornerHandle *)&v37[4], v34);
              v38[12].mNext = 0i64;
            }
            else
            {
              v38 = 0i64;
            }
            ++LODWORD(v38[1].mNext);
            v39 = v6->size;
            v40 = v39 + 1;
            v41 = v6->capacity;
            if ( (signed int)v39 + 1 > v41 )
            {
              if ( v41 )
                v42 = 2 * v41;
              else
                v42 = 1;
              for ( ; v42 < v40; v42 *= 2 )
                ;
              if ( v42 <= 2 )
                v42 = 2;
              if ( v42 - v40 > 0x10000 )
                v42 = v39 + 65537;
              if ( v42 != (_DWORD)v39 )
              {
                v43 = 8i64 * v42;
                if ( !is_mul_ok(v42, 8ui64) )
                  v43 = -1i64;
                v44 = UFG::qMalloc(v43, "qArray.Add", 0i64);
                v45 = (UFG::qReflectInventoryBase **)v44;
                if ( v6->p )
                {
                  v46 = 0i64;
                  if ( v6->size )
                  {
                    do
                    {
                      v44[v46] = (UFG::allocator::free_link)v6->p[v46];
                      v46 = (unsigned int)(v46 + 1);
                    }
                    while ( (unsigned int)v46 < v6->size );
                  }
                  operator delete[](v6->p);
                }
                v6->p = v45;
                v6->capacity = v42;
              }
            }
            v6->size = v40;
            v6->p[v39] = (UFG::qReflectInventoryBase *)v38;
            v2 = v83;
          }
          v34 = (UFG::CoverCorner *)v34->mNext;
        }
        while ( v34 != v33 );
        v31 = v84;
        v32 = v85;
      }
      ++v31;
      v84 = v31;
      v85 = --v32;
    }
    while ( v32 );
    v1 = v82;
  }
  v47 = v1->m_pParkourQuery;
  for ( j = v47->handlesOut.size; j; j = v47->handlesOut.size )
  {
    v49 = v47->handlesOut.p;
    if ( v49->m_pPointer )
      break;
    v50 = v49[j - 1].m_pPointer;
    if ( v49->m_pPointer )
    {
      v51 = v49->mPrev;
      v52 = v49->mNext;
      v51->mNext = v52;
      v52->mPrev = v51;
      v49->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v49->mPrev;
      v49->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v49->mPrev;
    }
    v49->m_pPointer = v50;
    if ( v50 )
    {
      v53 = v50->m_SafePointerList.mNode.mPrev;
      v53->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v49->mPrev;
      v49->mPrev = v53;
      v49->mNext = &v50->m_SafePointerList.mNode;
      v50->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v49->mPrev;
    }
    v54 = v47->handlesOut.size;
    v47->handlesOut.size = v54 > 1 ? v54 - 1 : 0;
  }
  v55 = 1;
  if ( v47->handlesOut.size )
  {
    v56 = v47->handlesOut.p->m_pPointer->mSimObject.m_pPointer;
    if ( v56 )
    {
      v57 = v56->m_pTransformNodeComponent;
      if ( v57 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v57);
        v55 = (float)(UFG::CoverObjectBase::ms_fMaxCoverVelocity * UFG::CoverObjectBase::ms_fMaxCoverVelocity) > (float)((float)((float)(v57->mWorldVelocity.x * v57->mWorldVelocity.x) + (float)(v57->mWorldVelocity.y * v57->mWorldVelocity.y)) + (float)(v57->mWorldVelocity.z * v57->mWorldVelocity.z));
      }
    }
  }
  v58 = 0;
  if ( v47->handlesOut.size )
  {
    do
    {
      v59 = v47->handlesOut.p;
      v60 = v59[v58].m_pPointer;
      if ( v60 )
      {
        if ( UFG::ParkourHandle::IsEnabled(v59[v58].m_pPointer) && v55 )
        {
          UFG::ParkourHandle::GetEndpoints(v60, &p0, &p1);
          v61 = UFG::qNearestSegPoint(&result, &p0, &p1, v2);
          v62 = v2->y - v61->y;
          v63 = (__m128)LODWORD(v2->x);
          v63.m128_f32[0] = (float)((float)((float)(v63.m128_f32[0] - v61->x) * (float)(v63.m128_f32[0] - v61->x))
                                  + (float)(v62 * v62))
                          + (float)((float)(v2->z - v61->z) * (float)(v2->z - v61->z));
          if ( COERCE_FLOAT(_mm_sqrt_ps(v63)) < v1->m_pSearchParams->m_fMaxDistance
            && !UFG::ParkourHandle::IsType(v60, 0x10u)
            && !UFG::ParkourHandle::IsType(v60, 0x20u)
            && (!UFG::ParkourHandle::IsAttachedToVehicle(v60) || UFG::ParkourHandle::IsType(v60, 0x40u)) )
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
            v67 = v6->size;
            v68 = v67 + 1;
            v69 = v6->capacity;
            if ( (signed int)v67 + 1 > v69 )
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
              UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v6, v70, "qArray.Add");
            }
            v6->size = v68;
            v6->p[v67] = (UFG::qReflectInventoryBase *)v66;
            v1 = v82;
          }
        }
      }
      ++v58;
      v2 = v83;
    }
    while ( v58 < v47->handlesOut.size );
  }
  v71 = v1->m_pParkourQuery;
  if ( v71 )
  {
    v72 = v71->handlesOut.p;
    if ( v72 )
    {
      v73 = (char *)&v72[-1].m_pPointer;
      `eh vector destructor iterator'(
        v72,
        0x18ui64,
        (int)v72[-1].m_pPointer,
        (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
      operator delete[](v73);
    }
    v71->handlesOut.p = 0i64;
    *(_QWORD *)&v71->handlesOut.size = 0i64;
    v74 = v71->mPrev;
    v75 = v71->mNext;
    v74->mNext = v75;
    v75->mPrev = v74;
    v71->mPrev = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&v71->mPrev;
    v71->mNext = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&v71->mPrev;
    operator delete[](v71);
    v1->m_pParkourQuery = 0i64;
  }
  v1->vfptr[1].IsCompleted((UFG::AIQuery *)&v1->vfptr);
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
  UFG::AICoverQuery *v1; // rbx
  float v2; // xmm6_4
  unsigned __int64 v3; // rax
  unsigned int v4; // eax
  UFG::CoverObjectBase *v5; // rdi
  bool v6; // zf
  unsigned int v7; // eax
  char v8; // [rsp+20h] [rbp-38h]
  float v9; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = this->m_pSearchParams->m_fMaxZDistance;
  while ( v1->m_bCanContinue )
  {
    v3 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(v1->m_uStartTicks, v3) >= v1->m_fDuration )
      break;
    v4 = v1->m_uCurrentSyncFinding;
    if ( v4 >= v1->m_aCoverObjects.size )
      break;
    v5 = v1->m_aCoverObjects.p[v4];
    if ( v5->vfptr->IsCorner(v5)
      || (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v5->vfptr->__vecDelDtor + 2))(v5)
      && v5->vfptr->IsParkour(v5)
      && (unsigned __int8)v1->vfptr[1].__vecDelDtor((UFG::AIQuery *)&v1->vfptr, (unsigned int)v5)
      && (v5->vfptr->GetSyncPos(v5, (UFG::qVector3 *)&v8),
          v2 > COERCE_FLOAT(COERCE_UNSIGNED_INT(v9 - v1->m_npQueryCenter.m_vPosition.z) & _xmm)) )
    {
LABEL_15:
      ++v1->m_uCurrentSyncFinding;
    }
    else
    {
      v6 = v5->m_iRefCount-- == 1;
      if ( v6 )
        v5->vfptr->__vecDelDtor(v5, 1u);
      v1->m_aCoverObjects.p[v1->m_uCurrentSyncFinding] = v1->m_aCoverObjects.p[v1->m_aCoverObjects.size - 1];
      v7 = v1->m_aCoverObjects.size;
      if ( v7 > 1 )
      {
        v1->m_aCoverObjects.size = v7 - 1;
        --v1->m_uCurrentSyncFinding;
        goto LABEL_15;
      }
      v1->m_aCoverObjects.size = 0;
      --v1->m_uCurrentSyncFinding;
      ++v1->m_uCurrentSyncFinding;
    }
  }
  if ( v1->m_uCurrentSyncFinding == v1->m_aCoverObjects.size )
    v1->vfptr[1].IsCompleted((UFG::AIQuery *)&v1->vfptr);
}

// File Line: 530
// RVA: 0x36B8F0
bool __fastcall UFG::AICoverQuery::IsParkourSyncValid(UFG::AICoverQuery *this, UFG::CoverObjectParkour *pCoverObject)
{
  UFG::CoverObjectParkour *v2; // rdi
  __int64 v3; // rbx
  bool result; // al
  char v5; // [rsp+20h] [rbp-28h]
  char v6; // [rsp+2Ch] [rbp-1Ch]

  v2 = pCoverObject;
  result = 0;
  if ( UFG::CoverObjectParkour::FindParkourSyncPos(pCoverObject) )
  {
    v3 = (__int64)v2->vfptr->GetPosition((UFG::CoverObjectBase *)&v2->vfptr, (UFG::qVector3 *)&v5);
    if ( (float)(*(float *)(v3 + 8)
               - *(float *)((__int64)v2->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v2->vfptr, (UFG::qVector3 *)&v6) + 8)) < 1.4 )
      result = 1;
  }
  return result;
}

// File Line: 548
// RVA: 0x36B960
char __fastcall UFG::PlayerCoverQuery::IsParkourSyncValid(UFG::PlayerCoverQuery *this, UFG::CoverObjectParkour *pCoverObject)
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
  UFG::AICoverQuery *i; // rbx
  unsigned __int64 v2; // rax
  float v3; // xmm0_4
  unsigned int v4; // eax
  UFG::CoverObjectCorner *v5; // r14
  __int64 v6; // rsi
  UFG::CoverObjectParkour *v7; // rdi
  UFG::CoverObjectBaseVtbl *v8; // rax
  bool v9; // zf
  UFG::CoverObjectBaseVtbl *v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  UFG::CoverObjectBaseVtbl *v15; // rax
  UFG::CoverObjectBase *v16; // rcx
  unsigned int v17; // eax
  unsigned int uObstructed; // [rsp+40h] [rbp+8h]

LABEL_2:
  for ( i = this; i->m_bCanContinue; ++i->m_uCurrentObstructionTest )
  {
    v2 = UFG::qGetTicks();
    v3 = UFG::qGetTickTime(i->m_uStartTicks, v2);
    if ( v3 >= i->m_fDuration )
      break;
    v4 = i->m_uCurrentObstructionTest;
    if ( v4 >= i->m_aCoverObjects.size )
      break;
    v5 = (UFG::CoverObjectCorner *)i->m_aCoverObjects.p[v4];
    if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectCorner *))&v5->vfptr->__vecDelDtor + 2))(v5) )
      continue;
    v6 = i->m_uCurrentObstructionTest + 1;
    if ( (unsigned int)v6 >= i->m_aCoverObjects.size )
      continue;
    while ( 1 )
    {
      v7 = (UFG::CoverObjectParkour *)i->m_aCoverObjects.p[v6];
      if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectParkour *))&v7->vfptr->__vecDelDtor + 2))(v7) )
        goto LABEL_26;
      v8 = v5->vfptr;
      uObstructed = 0;
      v9 = v8->IsParkour((UFG::CoverObjectBase *)&v5->vfptr) == 0;
      v10 = v7->vfptr;
      if ( v9 )
      {
        if ( !v10->IsParkour((UFG::CoverObjectBase *)&v7->vfptr) )
          goto LABEL_26;
        UFG::CoverObjectBase::CheckObstructionLineCorner(v7, v5, &uObstructed, v3);
        v11 = uObstructed;
        if ( uObstructed && uObstructed != 3 )
          v11 = uObstructed ^ 3;
      }
      else
      {
        if ( v10->IsParkour((UFG::CoverObjectBase *)&v7->vfptr) )
          UFG::CoverObjectBase::CheckObstructionLineLine((UFG::CoverObjectParkour *)v5, v7, &uObstructed);
        else
          UFG::CoverObjectBase::CheckObstructionLineCorner(
            (UFG::CoverObjectParkour *)v5,
            (UFG::CoverObjectCorner *)v7,
            &uObstructed,
            v3);
        v11 = uObstructed;
      }
      if ( v11 == 1 )
        break;
      if ( v11 == 2 )
      {
        i->m_aCoverObjects.p[v6] = i->m_aCoverObjects.p[i->m_aCoverObjects.size - 1];
        v12 = i->m_aCoverObjects.size;
        if ( v12 > 1 )
          i->m_aCoverObjects.size = v12 - 1;
        else
          i->m_aCoverObjects.size = 0;
        v9 = v7->m_iRefCount-- == 1;
        if ( v9 )
          v7->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v7->vfptr, 1u);
        LODWORD(v6) = v6 - 1;
      }
      else if ( v11 == 3 )
      {
        i->m_aCoverObjects.p[v6] = i->m_aCoverObjects.p[i->m_aCoverObjects.size - 1];
        v13 = i->m_aCoverObjects.size;
        if ( v13 > 1 )
          i->m_aCoverObjects.size = v13 - 1;
        else
          i->m_aCoverObjects.size = 0;
        i->m_aCoverObjects.p[i->m_uCurrentObstructionTest] = i->m_aCoverObjects.p[i->m_aCoverObjects.size - 1];
        v14 = i->m_aCoverObjects.size;
        if ( v14 > 1 )
          i->m_aCoverObjects.size = v14 - 1;
        else
          i->m_aCoverObjects.size = 0;
        v9 = v5->m_iRefCount-- == 1;
        if ( v9 )
          v5->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v5->vfptr, 1u);
        v9 = v7->m_iRefCount-- == 1;
        if ( v9 )
        {
          v15 = v7->vfptr;
          v16 = (UFG::CoverObjectBase *)&v7->vfptr;
LABEL_43:
          v15->__vecDelDtor(v16, 1u);
          goto LABEL_44;
        }
        goto LABEL_44;
      }
LABEL_26:
      v6 = (unsigned int)(v6 + 1);
      if ( (unsigned int)v6 >= i->m_aCoverObjects.size )
      {
        ++i->m_uCurrentObstructionTest;
        goto LABEL_2;
      }
    }
    i->m_aCoverObjects.p[i->m_uCurrentObstructionTest] = i->m_aCoverObjects.p[i->m_aCoverObjects.size - 1];
    v17 = i->m_aCoverObjects.size;
    if ( v17 > 1 )
      i->m_aCoverObjects.size = v17 - 1;
    else
      i->m_aCoverObjects.size = 0;
    v9 = v5->m_iRefCount-- == 1;
    if ( v9 )
    {
      v15 = v5->vfptr;
      v16 = (UFG::CoverObjectBase *)&v5->vfptr;
      goto LABEL_43;
    }
LABEL_44:
    --i->m_uCurrentObstructionTest;
  }
  if ( i->m_uCurrentObstructionTest == i->m_aCoverObjects.size )
    i->vfptr[1].IsCompleted((UFG::AIQuery *)&i->vfptr);
}

// File Line: 620
// RVA: 0x368880
void __fastcall UFG::AICoverQuery::InitProcessConnections(UFG::AICoverQuery *this)
{
  this->m_uCurrentConnecting = 0;
}

// File Line: 625
// RVA: 0x37DA20
void __usercall UFG::AICoverQuery::ProcessConnections(UFG::AICoverQuery *this@<rcx>, float a2@<xmm0>)
{
  UFG::AICoverQuery *i; // rdi
  unsigned __int64 v3; // rax
  unsigned int v4; // eax
  UFG::CoverObjectBase *v5; // r13
  __int64 j; // r12
  UFG::CoverObjectBase *v7; // r14
  UFG::CoverObjectGroup *v8; // rsi
  UFG::CoverObjectGroup *v9; // rax
  UFG::CoverObjectGroup *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::CoverObjectGroup *v12; // rbx
  __int64 v13; // rbp
  unsigned int v14; // esi
  unsigned int v15; // edx
  unsigned int v16; // edx
  __int64 v17; // rcx
  unsigned int v18; // edx
  UFG::CoverObjectGroup **v19; // r8
  unsigned int v20; // eax
  bool v21; // zf
  unsigned int v22; // eax
  unsigned int v23; // ebx
  UFG::CoverObjectBase *v24; // rsi
  unsigned int v25; // eax
  unsigned int v26; // er12
  UFG::CoverObjectGroup *v27; // rsi
  __int64 v28; // r15
  unsigned int v29; // ebp
  unsigned int v30; // ebx
  unsigned int v31; // ebx
  unsigned __int64 v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::CoverObjectBase **v34; // r14
  __int64 v35; // r9
  unsigned int v36; // ebx
  UFG::ParkourHandle **v37; // r14
  unsigned int v38; // esi
  UFG::CoverObjectBase *v39; // rbx
  UFG::ParkourHandle *v40; // r14
  float v41; // xmm6_4
  unsigned int v42; // eax

  for ( i = this; i->m_bCanContinue; ++i->m_uCurrentConnecting )
  {
    v3 = UFG::qGetTicks();
    a2 = UFG::qGetTickTime(i->m_uStartTicks, v3);
    if ( a2 >= i->m_fDuration )
      break;
    v4 = i->m_uCurrentConnecting;
    if ( v4 >= i->m_aCoverObjects.size )
      break;
    v5 = i->m_aCoverObjects.p[v4];
    if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v5->vfptr->__vecDelDtor + 2))(v5) )
    {
      for ( j = i->m_uCurrentConnecting + 1; (unsigned int)j < i->m_aCoverObjects.size; j = (unsigned int)(j + 1) )
      {
        v7 = i->m_aCoverObjects.p[j];
        if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v7->vfptr->__vecDelDtor + 2))(i->m_aCoverObjects.p[j])
          && v5->vfptr->IsConnectedTo(v5, v7) )
        {
          v8 = v5->vfptr->GetCoverObjectGroup(v5);
          v9 = v7->vfptr->GetCoverObjectGroup(v7);
          v10 = v9;
          if ( v8 )
          {
            if ( v9 )
            {
              if ( v8 != v9 )
              {
                UFG::CoverObjectGroup::AddGroup(v8, (UFG::CoverObjectBase *)&v9->vfptr);
                v17 = 0i64;
                v18 = i->m_aCoverGroups.size;
                if ( v18 )
                {
                  v19 = i->m_aCoverGroups.p;
                  while ( v10 != v19[v17] )
                  {
                    v17 = (unsigned int)(v17 + 1);
                    if ( (unsigned int)v17 >= v18 )
                      goto LABEL_39;
                  }
                  if ( (signed int)v17 >= 0 )
                  {
                    v19[v17] = v19[v18 - 1];
                    v20 = i->m_aCoverGroups.size;
                    if ( v20 > 1 )
                      i->m_aCoverGroups.size = v20 - 1;
                    else
                      i->m_aCoverGroups.size = 0;
                  }
                }
LABEL_39:
                v21 = v10->m_iRefCount-- == 1;
                if ( v21 )
                  v10->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v10->vfptr, 1u);
              }
            }
            else
            {
              UFG::CoverObjectGroup::AddObject(v8, v7);
            }
          }
          else if ( v9 )
          {
            UFG::CoverObjectGroup::AddObject(v9, v5);
          }
          else
          {
            v11 = UFG::qMalloc(0x38ui64, "CoverObjectGroup", 0i64);
            v12 = (UFG::CoverObjectGroup *)v11;
            if ( v11 )
            {
              v11->mNext = (UFG::allocator::free_link *)&UFG::CoverObjectBase::`vftable';
              LODWORD(v11[1].mNext) = 0;
              v11[2].mNext = 0i64;
              LODWORD(v11[3].mNext) = 0;
              v11->mNext = (UFG::allocator::free_link *)&UFG::CoverObjectGroup::`vftable';
              v11[5].mNext = 0i64;
              v11[4].mNext = 0i64;
            }
            else
            {
              v12 = 0i64;
            }
            ++v12->m_iRefCount;
            v13 = i->m_aCoverGroups.size;
            v14 = v13 + 1;
            v15 = i->m_aCoverGroups.capacity;
            if ( (signed int)v13 + 1 > v15 )
            {
              if ( v15 )
                v16 = 2 * v15;
              else
                v16 = 1;
              for ( ; v16 < v14; v16 *= 2 )
                ;
              if ( v16 <= 2 )
                v16 = 2;
              if ( v16 - v14 > 0x10000 )
                v16 = v13 + 65537;
              UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
                (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&i->m_aCoverGroups,
                v16,
                "qArray.Add");
            }
            i->m_aCoverGroups.size = v14;
            i->m_aCoverGroups.p[v13] = v12;
            UFG::CoverObjectGroup::AddObject(v12, v5);
            UFG::CoverObjectGroup::AddObject(v12, v7);
          }
        }
      }
    }
  }
  v22 = i->m_aCoverObjects.size;
  if ( i->m_uCurrentConnecting == v22 )
  {
    v23 = 0;
    if ( v22 )
    {
      do
      {
        v24 = i->m_aCoverObjects.p[v23];
        if ( v24->vfptr->GetCoverObjectGroup(i->m_aCoverObjects.p[v23]) )
        {
          v21 = v24->m_iRefCount-- == 1;
          if ( v21 )
            v24->vfptr->__vecDelDtor(v24, 1u);
          i->m_aCoverObjects.p[v23] = i->m_aCoverObjects.p[i->m_aCoverObjects.size - 1];
          v25 = i->m_aCoverObjects.size;
          if ( v25 > 1 )
            i->m_aCoverObjects.size = v25 - 1;
          else
            i->m_aCoverObjects.size = 0;
          --v23;
        }
        ++v23;
      }
      while ( v23 < i->m_aCoverObjects.size );
    }
    v26 = 0;
    if ( i->m_aCoverGroups.size )
    {
      do
      {
        v27 = i->m_aCoverGroups.p[v26];
        if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectGroup *))&v27->vfptr->__vecDelDtor + 2))(i->m_aCoverGroups.p[v26]) )
        {
          ++v27->m_iRefCount;
          v28 = i->m_aCoverObjects.size;
          v29 = v28 + 1;
          v30 = i->m_aCoverObjects.capacity;
          if ( (signed int)v28 + 1 > v30 )
          {
            if ( v30 )
              v31 = 2 * v30;
            else
              v31 = 1;
            for ( ; v31 < v29; v31 *= 2 )
              ;
            if ( v31 <= 2 )
              v31 = 2;
            if ( v31 - v29 > 0x10000 )
              v31 = v28 + 65537;
            if ( v31 != (_DWORD)v28 )
            {
              v32 = 8i64 * v31;
              if ( !is_mul_ok(v31, 8ui64) )
                v32 = -1i64;
              v33 = UFG::qMalloc(v32, "qArray.Add", 0i64);
              v34 = (UFG::CoverObjectBase **)v33;
              if ( i->m_aCoverObjects.p )
              {
                v35 = 0i64;
                if ( i->m_aCoverObjects.size )
                {
                  do
                  {
                    v33[v35] = (UFG::allocator::free_link)i->m_aCoverObjects.p[v35];
                    v35 = (unsigned int)(v35 + 1);
                  }
                  while ( (unsigned int)v35 < i->m_aCoverObjects.size );
                }
                operator delete[](i->m_aCoverObjects.p);
              }
              i->m_aCoverObjects.p = v34;
              i->m_aCoverObjects.capacity = v31;
            }
          }
          i->m_aCoverObjects.size = v29;
          i->m_aCoverObjects.p[v28] = (UFG::CoverObjectBase *)&v27->vfptr;
          v27->m_fTotalLength = 0.0;
          v36 = 0;
          if ( v27->m_aChildObjects.size )
          {
            do
            {
              v37 = (UFG::ParkourHandle **)v27->m_aChildObjects.p[v36];
              if ( ((__int64 (__fastcall *)(UFG::CoverObjectBase *))(*v37)->mSimObject.mNext)(v27->m_aChildObjects.p[v36]) )
              {
                a2 = (float)(UFG::ParkourHandle::GetHalfLength(v37[6]) * 2.0) + v27->m_fTotalLength;
                v27->m_fTotalLength = a2;
              }
              ++v36;
            }
            while ( v36 < v27->m_aChildObjects.size );
          }
        }
        ++v26;
      }
      while ( v26 < i->m_aCoverGroups.size );
    }
    v38 = 0;
    if ( i->m_aCoverObjects.size )
    {
      do
      {
        v39 = i->m_aCoverObjects.p[v38];
        if ( v39->vfptr->IsParkour(i->m_aCoverObjects.p[v38])
          && (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v39->vfptr->__vecDelDtor + 2))(v39) )
        {
          v40 = (UFG::ParkourHandle *)v39[1].m_pCoverObjectGroup;
          v39->vfptr->GetHeight(v39);
          if ( a2 <= 0.5 || a2 >= 1.6 )
            v41 = UFG::CoverObjectBase::ms_fHighSideOffset;
          else
            v41 = UFG::CoverObjectBase::ms_fLowSideOffset;
          a2 = UFG::ParkourHandle::GetHalfLength(v40);
          if ( a2 < v41 )
          {
            v21 = v39->m_iRefCount-- == 1;
            if ( v21 )
              v39->vfptr->__vecDelDtor(v39, 1u);
            i->m_aCoverObjects.p[v38] = i->m_aCoverObjects.p[i->m_aCoverObjects.size - 1];
            v42 = i->m_aCoverObjects.size;
            if ( v42 > 1 )
              i->m_aCoverObjects.size = v42 - 1;
            else
              i->m_aCoverObjects.size = 0;
            --v38;
          }
        }
        ++v38;
      }
      while ( v38 < i->m_aCoverObjects.size );
    }
    i->vfptr[1].IsCompleted((UFG::AIQuery *)&i->vfptr);
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
  UFG::AICoverQuery *i; // rdi
  unsigned __int64 v2; // rax
  unsigned int v3; // eax
  UFG::CoverObjectBase *v4; // rbx
  unsigned int j; // ebp
  UFG::CoverPosition *v6; // r12
  __int64 v7; // r15
  unsigned int v8; // esi
  unsigned int v9; // ebx
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::CoverPosition **v13; // r14
  unsigned int k; // er9
  __int64 v15; // [rsp+28h] [rbp-40h]
  void *mem; // [rsp+30h] [rbp-38h]

  for ( i = this; i->m_bCanContinue; ++i->m_uCurrentGetCoverPositions )
  {
    v2 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(i->m_uStartTicks, v2) >= i->m_fDuration )
      break;
    v3 = i->m_uCurrentGetCoverPositions;
    if ( v3 >= i->m_aCoverObjects.size )
      break;
    v4 = i->m_aCoverObjects.p[v3];
    if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v4->vfptr->__vecDelDtor + 2))(v4) )
    {
      mem = 0i64;
      v15 = 0i64;
      if ( v4->vfptr->GetCoverPositions(v4, (UFG::qArray<UFG::CoverPosition *,0> *)&v15) )
      {
        for ( j = 0; j < (unsigned int)v15; ++j )
        {
          v6 = (UFG::CoverPosition *)*((_QWORD *)mem + j);
          v7 = i->m_aCoverPositions.size;
          v8 = v7 + 1;
          v9 = i->m_aCoverPositions.capacity;
          if ( (signed int)v7 + 1 > v9 )
          {
            if ( v9 )
              v10 = 2 * v9;
            else
              v10 = 1;
            for ( ; v10 < v8; v10 *= 2 )
              ;
            if ( v10 <= 2 )
              v10 = 2;
            if ( v10 - v8 > 0x10000 )
              v10 = v7 + 65537;
            if ( v10 != (_DWORD)v7 )
            {
              v11 = 8i64 * v10;
              if ( !is_mul_ok(v10, 8ui64) )
                v11 = -1i64;
              v12 = UFG::qMalloc(v11, "qArray.Add", 0i64);
              v13 = (UFG::CoverPosition **)v12;
              if ( i->m_aCoverPositions.p )
              {
                for ( k = 0; k < i->m_aCoverPositions.size; ++k )
                  v12[k] = (UFG::allocator::free_link)i->m_aCoverPositions.p[k];
                operator delete[](i->m_aCoverPositions.p);
              }
              i->m_aCoverPositions.p = v13;
              i->m_aCoverPositions.capacity = v10;
            }
          }
          i->m_aCoverPositions.size = v8;
          i->m_aCoverPositions.p[v7] = v6;
          ++v6->m_iRefCount;
        }
      }
      if ( mem )
        operator delete[](mem);
      mem = 0i64;
      v15 = 0i64;
    }
  }
  if ( i->m_uCurrentGetCoverPositions == i->m_aCoverObjects.size )
    i->vfptr[1].IsCompleted((UFG::AIQuery *)&i->vfptr);
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
  UFG::AICoverQuery *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  UFG::SimComponent *v3; // rax
  unsigned __int16 v4; // dx
  UFG::CombatRegion *v5; // r15
  unsigned __int64 v6; // rax
  unsigned int v7; // eax
  UFG::CoverPosition *v8; // rsi
  UFG::AICoverSearchParams *v9; // rdx
  __int64 v10; // rdi
  UFG::AICoverSearchParams *v11; // rdx
  float *v12; // rax
  float v13; // xmm2_4
  float v14; // xmm1_4
  __int64 v15; // rbp
  unsigned int v16; // edi
  unsigned int v17; // edx
  unsigned int v18; // edx
  UFG::qVector3 vPoint; // [rsp+28h] [rbp-40h]
  char v20; // [rsp+34h] [rbp-34h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSearchParams->m_pInitiator.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = v2->m_Components.p[22].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIEntityComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v3 = v2->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    v3 = 0i64;
  }
  v5 = *(UFG::CombatRegion **)&v3[15].m_TypeUID;
  if ( !(_S33 & 1) )
  {
    _S33 |= 1u;
    *(_QWORD *)&vOffset.x = 0i64;
    LODWORD(vOffset.z) = (_DWORD)FLOAT_1_0;
  }
  while ( v1->m_bCanContinue )
  {
    v6 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(v1->m_uStartTicks, v6) >= v1->m_fDuration )
      break;
    v7 = v1->m_uCurrentCulling;
    if ( v7 >= v1->m_aCoverPositions.size )
      break;
    v8 = v1->m_aCoverPositions.p[v7];
    if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v8->vfptr->__vecDelDtor + 2))(v8) )
    {
      if ( v8->vfptr->CanUse((UFG::CoverObjectBase *)&v8->vfptr, v1->m_pSearchParams->m_pInitiator.m_pPointer) )
      {
        v9 = v1->m_pSearchParams;
        if ( !v9->m_bConstrainMaxDistance
          || ((unsigned __int8 (__fastcall *)(UFG::CoverPosition *, UFG::AICoverSearchParams::HostileTarget *))v8->vfptr->InRange2)(
               v8,
               v9->m_aHostileTargets.p) )
        {
          v10 = 0i64;
          if ( v1->m_pSearchParams->m_aHostileTargets.size )
          {
            while ( !((unsigned __int8 (__fastcall *)(UFG::CoverPosition *, UFG::AICoverSearchParams::HostileTarget *))v8->vfptr->InRange2)(
                       v8,
                       &v1->m_pSearchParams->m_aHostileTargets.p[v10]) )
            {
              v10 = (unsigned int)(v10 + 1);
              if ( (unsigned int)v10 >= v1->m_pSearchParams->m_aHostileTargets.size )
                goto LABEL_24;
            }
          }
          else
          {
LABEL_24:
            v11 = v1->m_pSearchParams;
            if ( v11->m_bIgnoreDirection
              || ((unsigned __int8 (__fastcall *)(UFG::CoverPosition *, UFG::AICoverSearchParams::HostileTarget *))v8->vfptr->FacesPosition)(
                   v8,
                   v11->m_aHostileTargets.p) )
            {
              if ( !v5
                || (v12 = (float *)v8->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v8->vfptr, (UFG::qVector3 *)&v20),
                    v13 = vOffset.z + v12[2],
                    v14 = vOffset.y + v12[1],
                    vPoint.x = vOffset.x + *v12,
                    vPoint.y = v14,
                    vPoint.z = v13,
                    UFG::CombatRegion::IsHitPoint(v5, &vPoint)) )
              {
                ++v8->m_iRefCount;
                v15 = v1->m_aCulledObjects.size;
                v16 = v15 + 1;
                v17 = v1->m_aCulledObjects.capacity;
                if ( (signed int)v15 + 1 > v17 )
                {
                  if ( v17 )
                    v18 = 2 * v17;
                  else
                    v18 = 1;
                  for ( ; v18 < v16; v18 *= 2 )
                    ;
                  if ( v18 <= 2 )
                    v18 = 2;
                  if ( v18 - v16 > 0x10000 )
                    v18 = v15 + 65537;
                  UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
                    (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v1->m_aCulledObjects,
                    v18,
                    "qArray.Add");
                }
                v1->m_aCulledObjects.size = v16;
                v1->m_aCulledObjects.p[v15] = v8;
              }
            }
          }
        }
      }
    }
    ++v1->m_uCurrentCulling;
  }
  if ( v1->m_uCurrentCulling == v1->m_aCoverPositions.size )
    v1->vfptr[1].IsCompleted((UFG::AIQuery *)&v1->vfptr);
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
  UFG::AICoverQuery *v1; // rbx
  unsigned __int64 v2; // rax
  unsigned int v3; // eax
  UFG::CoverPosition *v4; // rsi
  UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0> *v5; // r14
  __int64 v6; // rbp
  unsigned int v7; // edx
  unsigned int v8; // edi
  unsigned int v9; // edx
  signed __int64 v10; // rdi
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float *v14; // rax
  float v15; // xmm4_4
  UFG::AICoverSearchParams *v16; // rax
  float v17; // xmm0_4
  __int64 v18; // rcx
  bool v19; // zf

  v1 = this;
  while ( v1->m_bCanContinue )
  {
    v2 = UFG::qGetTicks();
    if ( UFG::qGetTickTime(v1->m_uStartTicks, v2) >= v1->m_fDuration )
      break;
    v3 = v1->m_uCurrentPrioritizing;
    if ( v3 >= v1->m_aCulledObjects.size )
      break;
    v4 = v1->m_aCulledObjects.p[v3];
    if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v4->vfptr->__vecDelDtor + 2))(v4)
      || !v4->vfptr->CanUse((UFG::CoverObjectBase *)&v4->vfptr, v1->m_pSearchParams->m_pInitiator.m_pPointer) )
    {
      goto LABEL_32;
    }
    v5 = &v1->m_aQueryRecords;
    v6 = v1->m_aQueryRecords.size;
    v7 = v1->m_aQueryRecords.capacity;
    v8 = v6 + 1;
    if ( (signed int)v6 + 1 > v7 )
    {
      if ( v7 )
        v9 = 2 * v7;
      else
        v9 = 1;
      for ( ; v9 < v8; v9 *= 2 )
        ;
      if ( v9 - v8 > 0x10000 )
        v9 = v6 + 65537;
      UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0>::Reallocate(&v1->m_aQueryRecords, v9, "qArray.Add");
    }
    v5->size = v8;
    v10 = (signed __int64)&v1->m_aQueryRecords.p[v6];
    *(float *)(v10 + 24) = UFG::AICoverQuery::GetDistancePriority(v1, v4);
    v11 = UFG::AICoverQuery::GetDistanceToTargetPriority(v1, v4);
    *(_DWORD *)(v10 + 32) = 0;
    *(float *)(v10 + 28) = v11;
    *(float *)(v10 + 36) = UFG::AICoverQuery::GetLineOfSightPriority(v1, v4);
    v12 = v1->m_pSearchParams->m_fDirectLineOfSightWeight <= 0.0 ? 0.0 : UFG::AICoverQuery::GetDirectLineOfSightPriority(
                                                                           v1,
                                                                           v4);
    *(float *)(v10 + 40) = v12;
    *(float *)(v10 + 44) = UFG::AICoverQuery::GetNotExposedPriority(v1, v4, v12);
    *(float *)(v10 + 48) = UFG::AICoverQuery::GetDistanceFromAlliesPriority(v1, v4);
    v13 = UFG::AICoverQuery::GetRadialSpreadFromAlliesPriority(v1, v4);
    *(float *)(v10 + 52) = v13;
    v14 = (float *)v1->m_pSearchParams;
    v15 = (float)((float)((float)((float)((float)((float)((float)(v14[9] * *(float *)(v10 + 28))
                                                        + (float)(v14[8] * *(float *)(v10 + 24)))
                                                + (float)(v14[12] * *(float *)(v10 + 32)))
                                        + (float)(v14[17] * *(float *)(v10 + 36)))
                                + (float)(v14[19] * *(float *)(v10 + 40)))
                        + (float)(v14[14] * *(float *)(v10 + 44)))
                + (float)(v14[15] * *(float *)(v10 + 48)))
        + (float)(v13 * v14[16]);
    v4->m_fPriority = v15;
    v16 = v1->m_pSearchParams;
    v17 = v16->m_fMinimumPriority;
    if ( v17 >= 0.0 && v15 <= v17 )
      goto LABEL_39;
    if ( *(float *)(v10 + 36) <= 0.0 && *(float *)(v10 + 40) <= 0.0 && v16->m_bLineOfSightRequired
      || (*(_QWORD *)(v10 + 8) = v4,
          ++v4->m_iRefCount,
          !(unsigned __int8)UFG::AICoverQuery::CoverQueryRecord::FindMeshPos((UFG::AICoverQuery::CoverQueryRecord *)v10)) )
    {
LABEL_39:
      v18 = *(_QWORD *)(v10 + 8);
      if ( v18 )
      {
        v19 = (*(_DWORD *)(v18 + 8))-- == 1;
        if ( v19 )
          (**(void (__fastcall ***)(__int64, signed __int64))v18)(v18, 1i64);
        *(_QWORD *)(v10 + 8) = 0i64;
      }
      *(_BYTE *)(v10 + 16) = 0;
      if ( v5->size > 1 )
      {
        --v5->size;
        goto LABEL_32;
      }
      v5->size = 0;
      ++v1->m_uCurrentPrioritizing;
    }
    else
    {
LABEL_32:
      ++v1->m_uCurrentPrioritizing;
    }
  }
  if ( v1->m_uCurrentPrioritizing == v1->m_aCulledObjects.size )
  {
    if ( v1->m_aQueryRecords.size )
      v1->vfptr[1].IsCompleted((UFG::AIQuery *)&v1->vfptr);
    else
      v1->m_uState = 14;
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
  ((void (*)(void))this->vfptr[1].IsCompleted)();
}

// File Line: 1039
// RVA: 0x37BE60
void __fastcall UFG::AICoverQuery::PathTest(UFG::AICoverQuery *this)
{
  UFG::AICoverQuery *v1; // rdi
  UFG::AICoverSearchParams *v2; // rcx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  __int64 v7; // rdx
  float v8; // xmm1_4
  UFG::DaemonType v9; // xmm2_4
  unsigned int i; // esi
  signed __int64 v11; // r14
  void (__cdecl ***v12)(_QWORD, _QWORD); // rbx
  _DWORD *v13; // rax
  signed __int64 v14; // rcx
  int v15; // xmm1_4
  int v16; // xmm2_4
  __int64 v17; // rdx
  __int64 v18; // rdx
  UFG::DaemonManager *v19; // rax
  unsigned int j; // edx
  signed __int64 v21; // rcx
  float v22; // xmm1_4
  float v23; // xmm0_4
  __int64 v24; // rax
  UFG::NavPath *v25; // rcx
  bool v26; // zf
  __int64 v27; // rcx
  UFG::DaemonQueryOutput output; // [rsp+20h] [rbp-B8h]
  __int64 v29; // [rsp+38h] [rbp-A0h]
  void *mem; // [rsp+40h] [rbp-98h]
  UFG::NavPath *v31; // [rsp+48h] [rbp-90h]
  UFG::FindPathMultiDestPrioritizedImmediateQuery v32; // [rsp+50h] [rbp-88h]

  *(_QWORD *)(&v32.m_npFrom.m_aiMeshUid + 1) = -2i64;
  v1 = this;
  v2 = this->m_pSearchParams;
  if ( v2->m_bSkipPathfind )
  {
    v1->vfptr[1].IsCompleted((UFG::AIQuery *)&v1->vfptr);
  }
  else
  {
    v3 = (UFG::SimObjectGame *)v2->m_pInitiator.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v4 = v3->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
          {
            v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
          }
          else if ( (v5 >> 12) & 1 )
          {
            v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
          }
          else
          {
            v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::NavComponent::_TypeUID);
          }
        }
        else
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        v4 = v6;
      }
    }
    else
    {
      v4 = 0i64;
    }
    *(_QWORD *)&v32.m_internalType = 1i64;
    v32.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathMultiDestPrioritizedImmediateQuery::`vftable';
    v32.m_daemonType = LODWORD(UFG::qVector3::msZero.z);
    LOBYTE(v32.m_mode) = 0;
    *(hkVector4f *)&v32.m_pOutput = (hkVector4f)hkvZero_13.m_quad;
    *(_QWORD *)&v32.m_npFrom.m_vPosition.x = -1i64;
    *(_QWORD *)&v32.m_npFrom.m_bValid = 0i64;
    v32.m_npFrom.m_hkvMeshPosition.m_quad.m128_i32[0] = -1;
    *(_QWORD *)&v32.m_npFrom.m_packedKey = 0i64;
    v32.m_npFrom.m_hkvMeshPosition.m_quad.m128_u64[1] = 0i64;
    output.m_id = 0;
    *(_QWORD *)&output.m_internalType = 1i64;
    output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathMultiDestPrioritizedOutput::`vftable';
    mem = 0i64;
    v29 = 0i64;
    v31 = 0i64;
    ((void (__fastcall *)(UFG::HavokNavPosition *))v1->m_npQueryCenter.vfptr->Validate)(&v1->m_npQueryCenter);
    v8 = v1->m_npQueryCenter.m_vPosition.y;
    v9 = LODWORD(v1->m_npQueryCenter.m_vPosition.z);
    v32.m_npFrom.m_vPosition.x = v1->m_npQueryCenter.m_vPosition.x;
    v32.m_npFrom.m_vPosition.y = v8;
    v32.m_daemonType = v9;
    if ( v1->m_npQueryCenter.m_bValid )
    {
      LOBYTE(v32.m_mode) = v1->m_npQueryCenter.m_bValid;
      *(hkVector4f *)&v32.m_pOutput = v1->m_npQueryCenter.m_hkvMeshPosition;
      LODWORD(v32.m_npFrom.m_vPosition.x) = v1->m_npQueryCenter.m_packedKey;
      LODWORD(v32.m_npFrom.m_vPosition.y) = v1->m_npQueryCenter.m_aiMeshUid;
    }
    else
    {
      LOBYTE(v32.m_mode) = 0;
    }
    *(_QWORD *)&v32.m_npFrom.m_bValid = (char *)v4 + 188;
    for ( i = 0; i < v1->m_aQueryRecords.size; ++i )
    {
      v11 = (signed __int64)&v1->m_aQueryRecords.p[i];
      if ( !(*(unsigned __int8 (__cdecl **)(_QWORD, __int64))(**(_QWORD **)(v11 + 8) + 16i64))(*(_QWORD *)(v11 + 8), v7) )
        goto LABEL_46;
      v12 = *(void (__cdecl ****)(_QWORD, _QWORD))(v11 + 8);
      v13 = (_DWORD *)((__int64 (__fastcall *)(_QWORD, UFG::NavParams **))(*v12)[15])(
                        *(_QWORD *)(v11 + 8),
                        &v32.m_pNavParams);
      v14 = (signed __int64)(v12 + 32);
      v15 = v13[1];
      v16 = v13[2];
      *(_DWORD *)(v14 + 8) = *v13;
      *(_DWORD *)(v14 + 12) = v15;
      *(_DWORD *)(v14 + 16) = v16;
      *(_BYTE *)(v14 + 24) = 0;
      (*v12[32])(v12 + 32, v17);
      if ( (*(unsigned __int8 (__cdecl **)(signed __int64, __int64))(*(_QWORD *)(*(_QWORD *)(v11 + 8) + 256i64) + 32i64))(
             *(_QWORD *)(v11 + 8) + 256i64,
             v18) )
      {
        UFG::FindPathMultiDestPrioritizedImmediateQuery::AddDestination(
          &v32,
          (UFG::HavokNavPosition *)(*(_QWORD *)(v11 + 8) + 256i64),
          *(float *)(*(_QWORD *)(v11 + 8) + 24i64) / v1->m_pSearchParams->m_fPathWeight);
      }
      else
      {
LABEL_46:
        UFG::qArray<UFG::AICoverQuery::CoverQueryRecord,0>::FastDelete(&v1->m_aQueryRecords, i--);
      }
    }
    v19 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::SubmitQuery(v19, (UFG::DaemonQueryInput *)&v32.vfptr, &output);
    if ( output.m_status == 3 )
    {
      for ( j = 0; j < v1->m_aQueryRecords.size; ++j )
      {
        v21 = (signed __int64)&v1->m_aQueryRecords.p[j];
        v22 = v1->m_pSearchParams->m_fPathWeight * *((float *)mem + j);
        *(_BYTE *)(v21 + 16) = 1;
        *(float *)(v21 + 20) = v22;
        v23 = *(float *)(*(_QWORD *)(v21 + 8) + 24i64) - v22;
        if ( v23 > v1->m_fBestCoverScore )
        {
          v1->m_iBestCoverIndex = j;
          v1->m_fBestCoverScore = v23;
        }
      }
      v24 = (__int64)v31;
      if ( v1->m_pFoundPath.m_pNavPath != v31 )
      {
        if ( v31 )
        {
          ++v31->m_uRefCount;
          v24 = (__int64)v31;
        }
        v25 = v1->m_pFoundPath.m_pNavPath;
        if ( v25 )
        {
          v26 = v25->m_uRefCount-- == 1;
          if ( v26 )
            v25->vfptr->__vecDelDtor(v25, 1u);
          v24 = (__int64)v31;
        }
        v1->m_pFoundPath.m_pNavPath = (UFG::NavPath *)v24;
      }
    }
    v1->vfptr[1].IsCompleted((UFG::AIQuery *)&v1->vfptr);
    v27 = (__int64)v31;
    if ( v31 )
    {
      --v31->m_uRefCount;
      if ( !*(_DWORD *)(v27 + 40) )
        (**(void (__fastcall ***)(__int64, signed __int64))v27)(v27, 1i64);
    }
    if ( mem )
      operator delete[](mem);
    mem = 0i64;
    v29 = 0i64;
    output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable';
    if ( *(_QWORD *)&v32.m_npFrom.m_packedKey )
      operator delete[](*(void **)&v32.m_npFrom.m_packedKey);
  }
}

// File Line: 1097
// RVA: 0x34E680
void __fastcall UFG::AICoverQuery::ChooseBest(UFG::AICoverQuery *this)
{
  UFG::AICoverQuery *v1; // rbx
  unsigned int v2; // edi
  signed __int64 v3; // rsi
  float v4; // xmm0_4
  int v5; // eax
  UFG::CoverPosition *v6; // rdi

  v1 = this;
  if ( this->m_pSearchParams->m_bSkipPathfind )
  {
    v2 = 0;
    if ( this->m_aQueryRecords.size )
    {
      do
      {
        v3 = (signed __int64)&v1->m_aQueryRecords.p[v2];
        if ( (*(unsigned __int8 (**)(void))(**(_QWORD **)(v3 + 8) + 16i64))() )
        {
          v4 = *(float *)(*(_QWORD *)(v3 + 8) + 24i64);
          if ( v4 > v1->m_fBestCoverScore )
          {
            v1->m_fBestCoverScore = v4;
            v1->m_iBestCoverIndex = v2;
          }
        }
        ++v2;
      }
      while ( v2 < v1->m_aQueryRecords.size );
    }
  }
  v5 = v1->m_iBestCoverIndex;
  if ( v5 >= 0
    && (v6 = v1->m_aQueryRecords.p[v5].m_pCoverPosition,
        (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v6->vfptr->__vecDelDtor + 2))(v6))
    && v6->vfptr->CanUse((UFG::CoverObjectBase *)&v6->vfptr, v1->m_pSearchParams->m_pInitiator.m_pPointer) )
  {
    v1->m_pBestCoverPosition = v6;
    ++v6->m_iRefCount;
    v1->vfptr[1].IsCompleted((UFG::AIQuery *)&v1->vfptr);
  }
  else
  {
    v1->m_uState = 14;
  }
}

// File Line: 1137
// RVA: 0x35EED0
float __fastcall UFG::AICoverQuery::GetDistancePriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  UFG::CoverPosition *v2; // rsi
  UFG::AICoverQuery *v3; // rdi
  UFG::SimObject *v4; // r8
  UFG::TransformNodeComponent *v5; // rbx
  float *v6; // rax
  __m128 v7; // xmm2
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  char v12; // [rsp+20h] [rbp-18h]

  v2 = coverPosition;
  v3 = this;
  v4 = this->m_pSearchParams->m_pInitiator.m_pPointer;
  if ( v4 )
    v5 = v4->m_pTransformNodeComponent;
  else
    v5 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v6 = (float *)v2->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v2->vfptr, (UFG::qVector3 *)&v12);
  v7 = (__m128)LODWORD(v5->mWorldTransform.v3.x);
  v8 = v5->mWorldTransform.v3.y - v6[1];
  v9 = v5->mWorldTransform.v3.z - v6[2];
  v7.m128_f32[0] = (float)((float)((float)(v7.m128_f32[0] - *v6) * (float)(v7.m128_f32[0] - *v6)) + (float)(v8 * v8))
                 + (float)(v9 * v9);
  v10 = COERCE_FLOAT(_mm_sqrt_ps(v7)) / v3->m_pSearchParams->m_fMaxDistance;
  if ( v10 >= 1.0 )
    v10 = *(float *)&FLOAT_1_0;
  return 1.0 - v10;
}

// File Line: 1151
// RVA: 0x35EF80
float __fastcall UFG::AICoverQuery::GetDistanceToTargetPriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  UFG::AICoverQuery *v2; // rdi
  UFG::AICoverSearchParams::HostileTarget *v3; // rbx
  UFG::qVector3 *v4; // rax
  __m128 v5; // xmm2
  float v6; // xmm0_4
  UFG::SimObjectCVBase *v7; // rcx
  float v8; // xmm6_4
  unsigned __int16 v9; // dx
  UFG::TargetingSystemPedBaseComponent *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  CAkScheduledItem *v14; // rax
  float *v15; // rdx
  float v16; // xmm1_4
  float v17; // xmm6_4
  float result; // xmm0_4
  char v19; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = this->m_pSearchParams->m_aHostileTargets.p;
  v4 = coverPosition->vfptr->GetPosition((UFG::CoverObjectBase *)coverPosition, (UFG::qVector3 *)&v19);
  v5 = (__m128)LODWORD(v3->m_vPosition.y);
  v6 = v3->m_vPosition.z - v4->z;
  v7 = (UFG::SimObjectCVBase *)v2->m_pSearchParams->m_pInitiator.m_pPointer;
  v5.m128_f32[0] = (float)((float)((float)(v5.m128_f32[0] - v4->y) * (float)(v5.m128_f32[0] - v4->y))
                         + (float)((float)(v3->m_vPosition.x - v4->x) * (float)(v3->m_vPosition.x - v4->x)))
                 + (float)(v6 * v6);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v5);
  if ( v7
    && ((v9 = v7->m_Flags, !((v9 >> 14) & 1)) ? ((v9 & 0x8000u) == 0 ? (!((v9 >> 13) & 1) ? (!((v9 >> 12) & 1) ? (v10 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::TargetingSystemPedBaseComponent::_TypeUID)) : (v10 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::TargetingSystemPedBaseComponent::_TypeUID))) : (v10 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::TargetingSystemPedBaseComponent::_TypeUID))) : (v10 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v7))) : (v10 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v7)),
        v10
     && (v11 = (UFG::SimObjectGame *)v10->m_pTargets[(unsigned __int8)v10->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer) != 0i64
     && ((v12 = v11->m_Flags, !((v12 >> 14) & 1)) ? ((v12 & 0x8000u) == 0 ? (!((v12 >> 13) & 1) ? (!((v12 >> 12) & 1) ? (v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::GunComponent::_TypeUID)) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::GunComponent::_TypeUID))) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::GunComponent::_TypeUID))) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::GunComponent::_TypeUID))) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::GunComponent::_TypeUID)),
         v13)) )
  {
    v14 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v13);
    v15 = *(float **)(*(_QWORD *)&v14[2].m_cmdStop.iRelativeTime
                    + 8i64 * (unsigned int)v14[2].m_cmdPlay.fadeParams.iFadeOffset
                    + 8);
    v16 = v15[114];
    if ( v8 >= v16 )
      v17 = (float)(v15[113] - v8) / (float)(v15[113] - v16);
    else
      v17 = (float)(v8 - v15[112]) / (float)(v16 - v15[112]);
    if ( v17 <= 0.0 )
      v17 = 0.0;
    result = v17;
  }
  else
  {
    result = v2->m_pSearchParams->m_fMaxDistanceToTarget - v8;
    if ( result <= 0.0 )
    {
      result = 0.0;
    }
    else if ( result >= 1.0 )
    {
      result = *(float *)&FLOAT_1_0;
    }
  }
  return result;
}

// File Line: 1206
// RVA: 0x360980
float __fastcall UFG::AICoverQuery::GetLineOfSightPriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  char v2; // bp
  UFG::CoverPosition *v3; // rsi
  UFG::AICoverQuery *v4; // r14
  signed __int64 v5; // rbx
  UFG::CoverPosition::FiringPositionEnum v6; // edi
  UFG::qVector3 *v7; // r8
  char v8; // al
  float result; // xmm0_4
  UFG::qVector3 vResultPosition; // [rsp+20h] [rbp-108h]
  UFG::RayCastData data; // [rsp+30h] [rbp-F8h]

  v2 = 0;
  v3 = coverPosition;
  v4 = this;
  v5 = 1i64;
  v6 = 0;
  do
  {
    if ( UFG::CoverPosition::GetFiringPosition(v3, v6, &vResultPosition) )
    {
      v7 = &v4->m_pSearchParams->m_aHostileTargets.p->m_vPosition;
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
      UFG::RayCastData::Init(&data, &vResultPosition, v7, 0xCu);
      v8 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      if ( v2 || !v8 )
        v2 = 1;
      if ( v8 )
        v3->m_bfFiringPositionClear.mBits[(signed __int64)(signed int)v6 >> 6] &= ~v5;
      else
        v3->m_bfFiringPositionClear.mBits[(signed __int64)(signed int)v6 >> 6] |= v5;
    }
    v5 = __ROL8__(v5, 1);
    ++v6;
  }
  while ( (unsigned int)v6 < 3 );
  if ( v2 )
    result = *(float *)&FLOAT_1_0;
  else
    result = 0.0;
  return result;
}

// File Line: 1247
// RVA: 0x35EAE0
float __fastcall UFG::AICoverQuery::GetDirectLineOfSightPriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  char v2; // bp
  UFG::CoverPosition *v3; // rsi
  UFG::AICoverQuery *v4; // r14
  signed __int64 v5; // rbx
  UFG::CoverPosition::FiringPositionEnum v6; // edi
  UFG::qVector3 *v7; // r8
  char v8; // al
  float result; // xmm0_4
  UFG::qVector3 vResultPosition; // [rsp+20h] [rbp-108h]
  UFG::RayCastData data; // [rsp+30h] [rbp-F8h]

  v2 = 0;
  v3 = coverPosition;
  v4 = this;
  v5 = 1i64;
  v6 = 0;
  do
  {
    if ( UFG::CoverPosition::GetFiringPosition(v3, v6, &vResultPosition) )
    {
      v7 = &v4->m_pSearchParams->m_aHostileTargets.p->m_vPosition;
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
      UFG::RayCastData::Init(&data, &vResultPosition, v7 + 1, 0xCu);
      v8 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      if ( v2 || !v8 )
        v2 = 1;
      if ( v8 )
        v3->m_bfFiringPositionClear.mBits[(signed __int64)(signed int)v6 >> 6] &= ~v5;
      else
        v3->m_bfFiringPositionClear.mBits[(signed __int64)(signed int)v6 >> 6] |= v5;
    }
    v5 = __ROL8__(v5, 1);
    ++v6;
  }
  while ( (unsigned int)v6 < 3 );
  if ( v2 )
    result = *(float *)&FLOAT_1_0;
  else
    result = 0.0;
  return result;
}

// File Line: 1288
// RVA: 0x35F3F0
float __fastcall UFG::AICoverQuery::GetExposure(UFG::AICoverQuery *this, UFG::qVector3 *vHostilePosition, UFG::qVector3 *vInCoverPosition, UFG::qVector3 *vAlongEdge, UFG::qVector3 *vEdgePosition, UFG::qVector3 *vEdgeDirection)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  __m128 v12; // xmm7
  __m128 v13; // xmm2
  float v14; // xmm1_4
  float v15; // xmm2_4

  v6 = vHostilePosition->x - vEdgePosition->x;
  v7 = vHostilePosition->y - vEdgePosition->y;
  v8 = vHostilePosition->z - vEdgePosition->z;
  if ( (float)((float)((float)(v7 * vEdgeDirection->y) + (float)(v6 * vEdgeDirection->x))
             + (float)(v8 * vEdgeDirection->z)) < 0.0 )
    return 0.0;
  v12 = (__m128)LODWORD(vAlongEdge->z);
  v10 = (float)(vAlongEdge->y * v8) - (float)(v12.m128_f32[0] * v7);
  v11 = (float)(vAlongEdge->x * v7) - (float)(vAlongEdge->y * v6);
  v12.m128_f32[0] = (float)(v12.m128_f32[0] * v6) - (float)(vAlongEdge->x * v8);
  v13 = v12;
  v13.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v10 * v10)) + (float)(v11 * v11);
  if ( v13.m128_f32[0] == 0.0 )
    v14 = 0.0;
  else
    v14 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
  v15 = (float)((float)((float)((float)((float)(vInCoverPosition->y - vHostilePosition->y)
                                      * (float)(v12.m128_f32[0] * v14))
                              + (float)((float)(vInCoverPosition->x - vHostilePosition->x) * (float)(v10 * v14)))
                      + (float)((float)(vInCoverPosition->z - vHostilePosition->z) * (float)(v11 * v14)))
              + 0.30000001)
      * 1.6666666;
  if ( v15 <= 0.0 )
    return 0.0;
  if ( v15 >= 1.0 )
    return *(float *)&FLOAT_1_0;
  return v15;
}

// File Line: 1311
// RVA: 0x361000
float __usercall UFG::AICoverQuery::GetNotExposedPriority@<xmm0>(UFG::AICoverQuery *this@<rcx>, UFG::CoverPosition *coverPosition@<rdx>, float a3@<xmm0>)
{
  UFG::CoverPosition *v3; // rdi
  UFG::AICoverQuery *v4; // rsi
  signed __int64 v5; // r13
  float *v6; // r12
  float v7; // xmm0_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  float v10; // xmm9_4
  float v11; // xmm12_4
  float v12; // xmm15_4
  float v13; // xmm6_4
  float v14; // xmm8_4
  float v15; // xmm7_4
  float *v16; // rax
  float v17; // xmm6_4
  float v18; // xmm8_4
  UFG::ParkourHandle *v19; // rbx
  __int64 v20; // r14
  UFG::AICoverSearchParams *v21; // rdx
  float v22; // xmm8_4
  UFG::qVector3 *v23; // r15
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  UFG::ParkourHandle *v27; // rcx
  float v28; // xmm0_4
  UFG::ParkourHandle *v29; // rcx
  float v30; // xmm12_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm11_4
  float v34; // xmm9_4
  float v35; // xmm10_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm8_4
  float *v39; // rax
  float v40; // xmm7_4
  float v41; // xmm8_4
  float v42; // xmm6_4
  UFG::qVector3 *v43; // rdx
  float result; // xmm0_4
  float v45; // [rsp+30h] [rbp-90h]
  float v46; // [rsp+34h] [rbp-8Ch]
  float v47; // [rsp+38h] [rbp-88h]
  UFG::qVector3 p0; // [rsp+40h] [rbp-80h]
  UFG::qVector3 p1; // [rsp+4Ch] [rbp-74h]
  UFG::qVector3 v50; // [rsp+58h] [rbp-68h]
  UFG::qVector3 vAlongEdge; // [rsp+68h] [rbp-58h]
  UFG::qVector3 vEdgeDirection; // [rsp+78h] [rbp-48h]
  UFG::qVector3 vEdgePosition; // [rsp+88h] [rbp-38h]
  UFG::qVector3 rayEnd; // [rsp+98h] [rbp-28h]
  int v55; // [rsp+A8h] [rbp-18h]
  int v56; // [rsp+ACh] [rbp-14h]
  int v57; // [rsp+B0h] [rbp-10h]
  UFG::qVector3 vInCoverPosition; // [rsp+B8h] [rbp-8h]
  UFG::qVector3 out; // [rsp+C8h] [rbp+8h]
  UFG::qVector3 v60; // [rsp+D8h] [rbp+18h]
  UFG::qVector3 v2; // [rsp+E8h] [rbp+28h]
  char v62; // [rsp+F8h] [rbp+38h]
  UFG::qVector3 v63; // [rsp+108h] [rbp+48h]
  __int64 v64; // [rsp+118h] [rbp+58h]
  char v65; // [rsp+120h] [rbp+60h]
  UFG::RayCastData data; // [rsp+130h] [rbp+70h]
  float v67; // [rsp+300h] [rbp+240h]
  float v68; // [rsp+308h] [rbp+248h]
  float v69; // [rsp+310h] [rbp+250h]
  float v70; // [rsp+318h] [rbp+258h]

  v64 = -2i64;
  v3 = coverPosition;
  v4 = this;
  v5 = UFG::CoverCornerHandle::Get(&coverPosition->m_LeftCorner);
  v6 = (float *)UFG::CoverCornerHandle::Get(&v3->m_RightCorner);
  v3->vfptr->GetWallNormal((UFG::CoverObjectBase *)&v3->vfptr, (UFG::qVector3 *)&v45);
  v3->vfptr->GetHeight((UFG::CoverObjectBase *)&v3->vfptr);
  if ( a3 >= 1.5 )
    v7 = FLOAT_1_55;
  else
    v7 = *(float *)&FLOAT_1_0;
  v70 = v7 - 0.30000001;
  v8 = (float)(v45 * UFG::qVector3::msDirUp.y) - (float)(v46 * UFG::qVector3::msDirUp.x);
  v68 = (float)(v45 * UFG::qVector3::msDirUp.y) - (float)(v46 * UFG::qVector3::msDirUp.x);
  v9 = (float)(v47 * UFG::qVector3::msDirUp.x) - (float)(v45 * UFG::qVector3::msDirUp.z);
  v69 = (float)(v47 * UFG::qVector3::msDirUp.x) - (float)(v45 * UFG::qVector3::msDirUp.z);
  v10 = (float)(v46 * UFG::qVector3::msDirUp.z) - (float)(v47 * UFG::qVector3::msDirUp.y);
  v67 = (float)(v46 * UFG::qVector3::msDirUp.z) - (float)(v47 * UFG::qVector3::msDirUp.y);
  vEdgeDirection.x = (float)(v46 * UFG::qVector3::msDirUp.z) - (float)(v47 * UFG::qVector3::msDirUp.y);
  vEdgeDirection.y = (float)(v47 * UFG::qVector3::msDirUp.x) - (float)(v45 * UFG::qVector3::msDirUp.z);
  p0.x = (float)(v45 * UFG::qVector3::msDirUp.y) - (float)(v46 * UFG::qVector3::msDirUp.x);
  v11 = 0.0;
  v12 = 0.0;
  v13 = UFG::qVector3::msDirUp.z * 0.64999998;
  v14 = UFG::qVector3::msDirUp.y * 0.64999998;
  v15 = UFG::qVector3::msDirUp.x * 0.64999998;
  v16 = (float *)v3->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v3->vfptr, &v60);
  v17 = v13 + v16[2];
  v18 = v14 + v16[1];
  rayEnd.x = v15 + *v16;
  rayEnd.y = v18;
  rayEnd.z = v17;
  v19 = v3->m_pParkourHandle.m_pPointer;
  if ( v19 )
  {
    UFG::ParkourHandle::GetEndpoints(v3->m_pParkourHandle.m_pPointer, &p0, &p1);
    UFG::ParkourHandle::GetNormal(v19, &out);
  }
  v20 = 0i64;
  v21 = v4->m_pSearchParams;
  if ( v21->m_aHostileTargets.size )
  {
    v22 = *(float *)&FLOAT_1_0;
    while ( 1 )
    {
      v23 = &v21->m_aHostileTargets.p[v20].m_vPosition;
      if ( !(_S35 & 1) )
      {
        _S35 |= 1u;
        kfAngleToIgnoreParkourSideExposure = 0.34906587;
      }
      if ( v5 )
        break;
      if ( v19 )
      {
        v27 = v19->mCachedLeftNeighbor.m_pPointer;
        if ( !v27
          || (UFG::ParkourHandle::GetNormal(v27, &v2),
              v22 = *(float *)&FLOAT_1_0,
              UFG::qHeadingDifference2D(&out, &v2) <= kfAngleToIgnoreParkourSideExposure) )
        {
          vInCoverPosition.x = (float)(p0.x - (float)(v10 * 0.34999999)) + (float)(v45 * 0.25);
          vInCoverPosition.y = (float)(p0.y - (float)(v9 * 0.34999999)) + (float)(v46 * 0.25);
          vInCoverPosition.z = (float)(p0.z - (float)(v8 * 0.34999999)) + (float)(v47 * 0.25);
          v26 = UFG::AICoverQuery::GetExposure(
                  v4,
                  v23,
                  &vInCoverPosition,
                  &UFG::qVector3::msDirUp,
                  &p0,
                  &vEdgeDirection);
          goto LABEL_16;
        }
      }
LABEL_17:
      if ( v6 )
      {
        vEdgePosition.x = v6[4];
        vEdgePosition.y = v6[5];
        vEdgePosition.z = v6[6];
        v3->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v3->vfptr, (UFG::qVector3 *)&v62);
        v55 = LODWORD(v10) ^ _xmm[0];
        v56 = LODWORD(v9) ^ _xmm[0];
        v57 = LODWORD(v8) ^ _xmm[0];
        v28 = UFG::AICoverQuery::GetExposure(
                v4,
                v23,
                (UFG::qVector3 *)&v62,
                &UFG::qVector3::msDirDown,
                &vEdgePosition,
                (UFG::qVector3 *)&v55);
        goto LABEL_23;
      }
      if ( v19 )
      {
        v29 = v19->mCachedRightNeighbor.m_pPointer;
        if ( !v29
          || (UFG::ParkourHandle::GetNormal(v29, &v63),
              UFG::qHeadingDifference2D(&out, &v63) >= COERCE_FLOAT(LODWORD(kfAngleToIgnoreParkourSideExposure) ^ _xmm[0])) )
        {
          p0.z = p1.x;
          p1.x = p1.y;
          p1.y = p1.z;
          v3->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v3->vfptr, &v60);
          LODWORD(v50.x) = LODWORD(v10) ^ _xmm[0];
          LODWORD(v50.y) = LODWORD(v9) ^ _xmm[0];
          LODWORD(v50.z) = LODWORD(v8) ^ _xmm[0];
          v28 = UFG::AICoverQuery::GetExposure(
                  v4,
                  v23,
                  &v60,
                  &UFG::qVector3::msDirDown,
                  (UFG::qVector3 *)((char *)&p0 + 8),
                  &v50);
LABEL_23:
          v11 = v11 + v28;
        }
        v22 = *(float *)&FLOAT_1_0;
      }
      v30 = v11 * 1.3333334;
      if ( v30 >= v22 )
        v30 = v22;
      v31 = 0.0;
      if ( v19 )
      {
        vAlongEdge.x = p1.x - p0.x;
        vAlongEdge.y = p1.y - p0.y;
        vAlongEdge.z = p1.z - p0.z;
        v50.x = (float)(v46 * (float)(p1.z - p0.z)) - (float)(v47 * (float)(p1.y - p0.y));
        v50.y = (float)(v47 * (float)(p1.x - p0.x)) - (float)(v45 * (float)(p1.z - p0.z));
        v32 = (float)(v45 * (float)(p1.y - p0.y)) - (float)(v46 * (float)(p1.x - p0.x));
        v50.z = v32;
        if ( v32 < 0.0 )
        {
          v50.x = (float)((float)(v46 * (float)(p1.z - p0.z)) - (float)(v47 * (float)(p1.y - p0.y))) * -1.0;
          v50.y = (float)((float)(v47 * (float)(p1.x - p0.x)) - (float)(v45 * (float)(p1.z - p0.z))) * -1.0;
          v50.z = v32 * -1.0;
          vAlongEdge.x = (float)(p1.x - p0.x) * -1.0;
          vAlongEdge.y = (float)(p1.y - p0.y) * -1.0;
          vAlongEdge.z = (float)(p1.z - p0.z) * -1.0;
        }
        v33 = v45 * 0.25;
        v34 = v46 * 0.25;
        v35 = v47 * 0.25;
        v36 = UFG::qVector3::msDirUp.x * v70;
        v37 = UFG::qVector3::msDirUp.y * v70;
        v38 = UFG::qVector3::msDirUp.z * v70;
        v39 = (float *)v3->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v3->vfptr, (UFG::qVector3 *)&v65);
        v40 = v37 + v39[1];
        v41 = v38 + v39[2];
        vEdgeDirection.x = (float)(v36 + *v39) - v33;
        vEdgeDirection.y = v40 - v34;
        vEdgeDirection.z = v41 - v35;
        v31 = UFG::AICoverQuery::GetExposure(v4, v23, &vEdgeDirection, &vAlongEdge, &p0, &v50) * 2.0;
        v22 = *(float *)&FLOAT_1_0;
        v10 = v67;
        v8 = v68;
        v9 = v69;
        if ( v31 >= 1.0 )
          v31 = *(float *)&FLOAT_1_0;
      }
      v42 = v22 - (float)((float)(v22 - v31) * (float)(v22 - v30));
      if ( v42 < 0.89999998 )
      {
        v43 = &v4->m_pSearchParams->m_aHostileTargets.p->m_vPosition;
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
        UFG::RayCastData::Init(&data, v43, &rayEnd, 0xCu);
        v22 = *(float *)&FLOAT_1_0;
        if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
          v42 = *(float *)&FLOAT_1_0;
      }
      v12 = v12 + v42;
      v20 = (unsigned int)(v20 + 1);
      v21 = v4->m_pSearchParams;
      v11 = 0.0;
      if ( (unsigned int)v20 >= v21->m_aHostileTargets.size )
        goto LABEL_36;
    }
    v24 = *(float *)(v5 + 20);
    v25 = *(float *)(v5 + 24);
    vAlongEdge.x = (float)(*(float *)(v5 + 16) - (float)(v10 * 0.34999999)) + (float)(v45 * 0.25);
    vAlongEdge.y = (float)(v24 - (float)(v9 * 0.34999999)) + (float)(v46 * 0.25);
    vAlongEdge.z = (float)(v25 - (float)(v8 * 0.34999999)) + (float)(v47 * 0.25);
    v26 = UFG::AICoverQuery::GetExposure(
            v4,
            v23,
            &vAlongEdge,
            &UFG::qVector3::msDirUp,
            (UFG::qVector3 *)(v5 + 16),
            &vEdgeDirection);
LABEL_16:
    v11 = v26;
    goto LABEL_17;
  }
LABEL_36:
  LODWORD(result) = LODWORD(v12) ^ _xmm[0];
  return result;
}

// File Line: 1496
// RVA: 0x35EE00
float __fastcall UFG::AICoverQuery::GetDistanceFromAlliesPriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  UFG::AICoverQuery *v2; // rbx
  __int64 v3; // rdx
  unsigned int v4; // er8
  UFG::qVector3 *v5; // r9
  float v6; // xmm0_4
  float v8; // [rsp+28h] [rbp-20h]
  float v9; // [rsp+2Ch] [rbp-1Ch]

  v2 = this;
  if ( !(_S36 & 1) )
  {
    _S36 |= 1u;
    kfMinRange2 = kfMinRange * kfMinRange;
  }
  coverPosition->vfptr->GetSyncPos((UFG::CoverObjectBase *)coverPosition, (UFG::qVector3 *)&v8);
  v3 = 0i64;
  v4 = v2->m_vAllyAvoidancePositions.size;
  if ( !v4 )
    return 0.0;
  v5 = v2->m_vAllyAvoidancePositions.p;
  while ( 1 )
  {
    v6 = v9 - v5[v3].y;
    if ( (float)((float)(v6 * v6) + (float)((float)(v8 - v5[v3].x) * (float)(v8 - v5[v3].x))) < kfMinRange2 )
      break;
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= v4 )
      return 0.0;
  }
  return FLOAT_N1_0;
}

// File Line: 1518
// RVA: 0x3622E0
float __fastcall UFG::AICoverQuery::GetRadialSpreadFromAlliesPriority(UFG::AICoverQuery *this, UFG::CoverPosition *coverPosition)
{
  UFG::AICoverQuery *v2; // rbx
  float *v3; // rdx
  float v4; // xmm3_4
  float v5; // xmm14_4
  float v6; // xmm15_4
  float v7; // xmm10_4
  __m128 v8; // xmm11
  float v9; // xmm12_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  unsigned int v12; // eax
  float v13; // xmm10_4
  float v14; // xmm11_4
  float v15; // xmm7_4
  float v16; // xmm12_4
  UFG::qVector3 *v17; // rbx
  __int64 v18; // rdi
  float v19; // xmm5_4
  float v20; // xmm4_4
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v27; // [rsp+20h] [rbp-B8h]
  float v28; // [rsp+24h] [rbp-B4h]
  float v29; // [rsp+28h] [rbp-B0h]
  float v30; // [rsp+E0h] [rbp+8h]

  v2 = this;
  coverPosition->vfptr->GetSyncPos((UFG::CoverObjectBase *)coverPosition, (UFG::qVector3 *)&v27);
  v8 = (__m128)LODWORD(v28);
  v3 = &v2->m_pSearchParams->m_aHostileTargets.p->m_vPosition.x;
  v4 = v3[2];
  v5 = *v3;
  v6 = v3[1];
  v7 = v27 - *v3;
  v8.m128_f32[0] = v28 - v6;
  v9 = v29 - v4;
  v10 = v8;
  v30 = v3[2];
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v12 = v2->m_vAllyAvoidancePositions.size;
  v13 = v7 * v11;
  v14 = v8.m128_f32[0] * v11;
  v15 = *(float *)&FLOAT_1_0;
  v16 = v9 * v11;
  if ( v12 )
  {
    v17 = v2->m_vAllyAvoidancePositions.p;
    v18 = v12;
    do
    {
      v21 = (__m128)LODWORD(v17->y);
      v19 = v17->z - v4;
      v20 = v17->x - v5;
      v21.m128_f32[0] = v21.m128_f32[0] - v6;
      v22 = v21;
      v22.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v19 * v19);
      if ( v22.m128_f32[0] == 0.0 )
        v23 = 0.0;
      else
        v23 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v22));
      LODWORD(v24) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)(v21.m128_f32[0] * v23) * v14) + (float)((float)(v20 * v23) * v13))
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
      v4 = v30;
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

