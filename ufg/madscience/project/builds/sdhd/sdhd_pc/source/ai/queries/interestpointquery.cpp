// File Line: 42
// RVA: 0x32D110
void __fastcall UFG::InterestPointQuery::Candidate::Candidate(UFG::InterestPointQuery::Candidate *this)
{
  UFG::InterestPointQuery::Candidate *v1; // rbx
  signed __int64 v2; // rax
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&this->input);
  v2 = (signed __int64)&v1->output;
  *(_QWORD *)v2 = &UFG::DaemonQueryOutput::`vftable;
  *(_QWORD *)(v2 + 8) = 0i64;
  *(_DWORD *)(v2 + 16) = 0;
  *(_QWORD *)v2 = &UFG::FindPathOutput::`vftable;
  v1->output.m_pPath.m_pNavPath = 0i64;
  v3 = &v1->mInterestPoint;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->mInterestPoint.m_pPointer = 0i64;
  v1->mAppealScore = 0.0;
  *((_BYTE *)v1 + 236) &= 0xF8u;
}

// File Line: 48
// RVA: 0x365AA0
void __fastcall UFG::InterestPointQuery::Candidate::Init(UFG::InterestPointQuery::Candidate *this, UFG::InterestPoint *pInterestPoint, const float appealScore)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v3; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rax

  v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
  if ( this->mInterestPoint.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = this->mInterestPoint.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    this->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
  }
  this->mInterestPoint.m_pPointer = pInterestPoint;
  if ( pInterestPoint )
  {
    v6 = pInterestPoint->m_SafePointerList.mNode.mPrev;
    v6->mNext = v3;
    v3->mPrev = v6;
    this->mInterestPoint.mNext = &pInterestPoint->m_SafePointerList.mNode;
    pInterestPoint->m_SafePointerList.mNode.mPrev = v3;
  }
  *((_BYTE *)this + 236) &= 0xFBu;
  this->mAppealScore = appealScore;
}

// File Line: 70
// RVA: 0x3388D0
void __fastcall UFG::InterestPointQuery::~InterestPointQuery(UFG::InterestPointQuery *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rbx
  UFG::qSafePointerNode<UFG::ParkourHandle> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointerNode<UFG::ParkourHandle> *v13; // rdx
  UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v15; // rax

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::InterestPointQuery>Vtbl *)&UFG::InterestPointQuery::`vftable;
  UFG::InterestPointQuery::End(this, 0);
  v2 = v1[2].m_SafePointerList.mNode.mPrev;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator(
      v2,
      0xF0ui64,
      (int)v2[-1].mPrev,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](v3);
  }
  v1[2].m_SafePointerList.mNode.mPrev = 0i64;
  v1[2].vfptr = 0i64;
  v4 = v1 + 3;
  if ( v1[3].m_SafePointerList.mNode.mNext )
  {
    v5 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v4->vfptr;
    v6 = v1[3].m_SafePointerList.mNode.mPrev;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v4;
    v1[3].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[3];
  }
  v1[3].m_SafePointerList.mNode.mNext = 0i64;
  v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v4->vfptr;
  v8 = v1[3].m_SafePointerList.mNode.mPrev;
  v7->mNext = v8;
  v8->mPrev = v7;
  v4->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v4;
  v1[3].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1[3];
  v9 = v1[2].m_SafePointerList.mNode.mPrev;
  if ( v9 )
  {
    v10 = v9 - 1;
    `eh vector destructor iterator(
      v9,
      0xF0ui64,
      (int)v9[-1].mPrev,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](v10);
  }
  v1[2].m_SafePointerList.mNode.mPrev = 0i64;
  v1[2].vfptr = 0i64;
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::InterestPointQuery>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v11 = v1->m_SafePointerList.mNode.mPrev;
  v12 = v1->m_SafePointerList.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
  v13 = v1 + 1;
  v14 = v1[1].vfptr;
  v15 = v1[1].m_SafePointerList.mNode.mPrev;
  v14[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::ParkourHandle> *, unsigned int))v15;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v14;
  v13->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)v13;
  v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v13;
}

// File Line: 80
// RVA: 0x341B50
bool __fastcall UFG::AppealCompare(UFG::InterestPointQuery::Candidate *a, UFG::InterestPointQuery::Candidate *b)
{
  return b->mAppealScore <= a->mAppealScore;
}

// File Line: 85
// RVA: 0x388B80
void __fastcall UFG::InterestPointQuery::Start(UFG::InterestPointQuery *this, UFG::InterestPoint *pBestPOI)
{
  UFG::InterestPoint *v2; // rbp
  UFG::InterestPointQuery *v3; // rdi
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObjectCharacter *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rbx
  __int64 v13; // rsi
  UFG::InterestPointQuery::Candidate *v14; // rbp
  char v15; // al
  UFG::DaemonManager *v16; // rax

  v2 = pBestPOI;
  v3 = this;
  if ( this->mNavComponent )
  {
    v4 = &this->mBestInterestPoint;
    if ( this->mBestInterestPoint.m_pPointer )
    {
      v5 = v4->mPrev;
      v6 = this->mBestInterestPoint.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      this->mBestInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mBestInterestPoint.mPrev;
    }
    this->mBestInterestPoint.m_pPointer = 0i64;
    if ( pBestPOI
      && ((v7 = (UFG::SimObjectCharacter *)this->mNavComponent->m_pSimObject) != 0i64 && v7 == LocalPlayer
       || !UFG::InterestPoint::IsTraversalsEnabled()) )
    {
      if ( v4->m_pPointer )
      {
        v8 = v4->mPrev;
        v9 = v4->mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      }
      v4->m_pPointer = v2;
      v10 = v2->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v4->mNext = &v2->m_SafePointerList.mNode;
      v4->mPrev = v10;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      UFG::InterestPointQuery::End(v3, QueryState_Succeeded);
    }
    else
    {
      v11 = (signed int)v3->mCandidates.size;
      if ( (_DWORD)v11 )
      {
        if ( (signed int)v11 > 1 )
          UFG::qQuickSortImpl<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
            v3->mCandidates.p,
            &v3->mCandidates.p[v11 - 1],
            UFG::AppealCompare);
        v3->mQueryState = 1;
      }
      else
      {
        UFG::InterestPointQuery::End(v3, QueryState_Failed);
      }
    }
  }
  else
  {
    v12 = this->mCandidates.size;
    if ( v12 > 0 )
    {
      v13 = 0i64;
      do
      {
        v14 = &v3->mCandidates.p[v13];
        v15 = *((_BYTE *)v14 + 236);
        if ( v15 & 1 && !(v15 & 2) )
        {
          v16 = UFG::DaemonManager::Instance();
          UFG::DaemonManager::CancelQuery(v16, (UFG::DaemonQueryInput *)&v14->input.vfptr);
        }
        ++v13;
        --v12;
      }
      while ( v12 );
    }
    v3->mQueryState = 2;
  }
}

// File Line: 123
// RVA: 0x38FC00
void __fastcall UFG::InterestPointQuery::Update(UFG::InterestPointQuery *this)
{
  UFG::InterestPointQuery *v1; // rsi
  unsigned int v2; // er14
  unsigned int v3; // ebp
  signed __int64 v4; // rbx
  UFG::InterestPointQuery::Candidate *v5; // rdi
  char v6; // al
  signed __int64 v7; // rcx
  UFG::NavComponent *v8; // rdx
  float v9; // xmm0_4
  float v10; // xmm1_4
  bool v11; // al
  UFG::qVector3 *v12; // rax
  signed __int64 v13; // rcx
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::DaemonManager *v16; // rax
  char v17; // al
  UFG::DaemonOutputStatus v18; // ecx
  char v19; // al
  UFG::InterestPointQuery::QueryState v20; // edx
  UFG::DaemonManager *v21; // rax
  unsigned int v22; // eax

  v1 = this;
  if ( this->mQueryState == 1 && this->mNavComponent )
  {
    v2 = this->mCandidates.size;
    v3 = 0;
    if ( v2 )
    {
      do
      {
        v4 = v3;
        v5 = &v1->mCandidates.p[v4];
        if ( v5->mInterestPoint.m_pPointer )
        {
          v6 = *((_BYTE *)v5 + 236);
          if ( !(v6 & 1) && !(v6 & 2) )
          {
            v7 = (signed __int64)&v5->input.m_npFrom;
            v5->input.m_pNavParams = &v1->mNavComponent->m_navParams;
            v8 = v1->mNavComponent;
            v9 = v8->m_navPosition.m_vPosition.y;
            v10 = v8->m_navPosition.m_vPosition.z;
            *(float *)(v7 + 8) = v8->m_navPosition.m_vPosition.x;
            *(float *)(v7 + 12) = v9;
            *(float *)(v7 + 16) = v10;
            v11 = v8->m_navPosition.m_bValid;
            if ( v11 )
            {
              v5->input.m_npFrom.m_bValid = v11;
              v5->input.m_npFrom.m_hkvMeshPosition = v8->m_navPosition.m_hkvMeshPosition;
              v5->input.m_npFrom.m_packedKey = v8->m_navPosition.m_packedKey;
              v5->input.m_npFrom.m_aiMeshUid = v8->m_navPosition.m_aiMeshUid;
            }
            else
            {
              v5->input.m_npFrom.m_bValid = 0;
            }
            (**(void (***)(void))v7)();
            v12 = UFG::InterestPoint::GetPosition(v5->mInterestPoint.m_pPointer);
            v13 = (signed __int64)&v5->input.m_npTo;
            v14 = v12->z;
            v15 = v12->y;
            *(float *)(v13 + 8) = v12->x;
            *(float *)(v13 + 16) = v14;
            *(float *)(v13 + 12) = v15;
            *(_BYTE *)(v13 + 24) = 0;
            ((void (*)(void))v5->input.m_npTo.vfptr->Validate)();
            v16 = UFG::DaemonManager::Instance();
            UFG::DaemonManager::SubmitQuery(
              v16,
              (UFG::DaemonQueryInput *)&v5->input.vfptr,
              (UFG::DaemonQueryOutput *)&v5->output.vfptr);
            *((_BYTE *)v5 + 236) |= 1u;
          }
          v17 = *((_BYTE *)v5 + 236);
          if ( v17 & 1 && !(v17 & 2) )
          {
            v18 = v5->output.m_status;
            if ( v18 == 3 )
            {
              v19 = v17 & 0xFE | 2;
              *((_BYTE *)v5 + 236) = v19;
              if ( v5->output.m_pPath.m_pNavPath )
              {
                *((_BYTE *)v5 + 236) = v19 | 4;
                UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint>::operator=(
                  &v1->mBestInterestPoint,
                  &v5->mInterestPoint);
                UFG::NavComponent::InjectPath(
                  v1->mNavComponent,
                  &v1->mNavComponent->m_navPosition,
                  &v5->input.m_npTo,
                  v5->output.m_pPath.m_pNavPath);
                v20 = 3;
                goto LABEL_16;
              }
            }
            else
            {
              if ( v18 != 4 )
                break;
              *((_BYTE *)v5 + 236) = v17 & 0xFE | 2;
            }
          }
        }
        else
        {
          v21 = UFG::DaemonManager::Instance();
          UFG::DaemonManager::CancelQuery(v21, (UFG::DaemonQueryInput *)&v5->input.vfptr);
          UFG::InterestPointQuery::Candidate::operator=(
            &v1->mCandidates.p[v4],
            &v1->mCandidates.p[v1->mCandidates.size - 1]);
          v22 = v1->mCandidates.size;
          if ( v22 > 1 )
            v1->mCandidates.size = v22 - 1;
          else
            v1->mCandidates.size = 0;
        }
        ++v3;
      }
      while ( v3 < v1->mCandidates.size );
    }
    if ( v3 == v2 )
    {
      v20 = 2;
LABEL_16:
      UFG::InterestPointQuery::End(v1, v20);
    }
  }
  else
  {
    UFG::InterestPointQuery::End(this, QueryState_Failed);
  }
}

// File Line: 236
// RVA: 0x355170
void __fastcall UFG::InterestPointQuery::End(UFG::InterestPointQuery *this, UFG::InterestPointQuery::QueryState queryState)
{
  UFG::InterestPointQuery::QueryState v2; // er14
  UFG::InterestPointQuery *v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rbx
  UFG::InterestPointQuery::Candidate *v6; // rbp
  char v7; // al
  UFG::DaemonManager *v8; // rax

  v2 = queryState;
  v3 = this;
  if ( queryState == 1 )
  {
    this->mQueryState = 1;
  }
  else
  {
    v4 = this->mCandidates.size;
    if ( v4 <= 0 )
    {
      this->mQueryState = queryState;
    }
    else
    {
      v5 = 0i64;
      do
      {
        v6 = &v3->mCandidates.p[v5];
        v7 = *((_BYTE *)v6 + 236);
        if ( v7 & 1 )
        {
          if ( !(v7 & 2) )
          {
            v8 = UFG::DaemonManager::Instance();
            UFG::DaemonManager::CancelQuery(v8, (UFG::DaemonQueryInput *)&v6->input.vfptr);
          }
        }
        ++v5;
        --v4;
      }
      while ( v4 );
      v3->mQueryState = v2;
    }
  }
}

