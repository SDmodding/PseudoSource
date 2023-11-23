// File Line: 42
// RVA: 0x32D110
void __fastcall UFG::InterestPointQuery::Candidate::Candidate(UFG::InterestPointQuery::Candidate *this)
{
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&this->input);
  this->output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  *(_QWORD *)&this->output.m_id = 0i64;
  this->output.m_status = Status_Undefined;
  this->output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathOutput::`vftable;
  this->output.m_pPath.m_pNavPath = 0i64;
  this->mInterestPoint.mPrev = &this->mInterestPoint;
  this->mInterestPoint.mNext = &this->mInterestPoint;
  this->mInterestPoint.m_pPointer = 0i64;
  this->mAppealScore = 0.0;
  *((_BYTE *)this + 236) &= 0xF8u;
}

// File Line: 48
// RVA: 0x365AA0
void __fastcall UFG::InterestPointQuery::Candidate::Init(
        UFG::InterestPointQuery::Candidate *this,
        UFG::InterestPoint *pInterestPoint,
        float appealScore)
{
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *p_mInterestPoint; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rax

  p_mInterestPoint = &this->mInterestPoint;
  if ( this->mInterestPoint.m_pPointer )
  {
    mPrev = p_mInterestPoint->mPrev;
    mNext = this->mInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mInterestPoint->mPrev = p_mInterestPoint;
    this->mInterestPoint.mNext = &this->mInterestPoint;
  }
  this->mInterestPoint.m_pPointer = pInterestPoint;
  if ( pInterestPoint )
  {
    v6 = pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev;
    v6->mNext = p_mInterestPoint;
    p_mInterestPoint->mPrev = v6;
    this->mInterestPoint.mNext = &pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode;
    pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev = p_mInterestPoint;
  }
  *((_BYTE *)this + 236) &= ~4u;
  this->mAppealScore = appealScore;
}

// File Line: 70
// RVA: 0x3388D0
void __fastcall UFG::InterestPointQuery::~InterestPointQuery(UFG::InterestPointQuery *this)
{
  UFG::InterestPointQuery::Candidate *p; // rcx
  UFG::InterestPoint **p_m_pPointer; // rbx
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *p_mBestInterestPoint; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::InterestPointQuery::Candidate *v9; // rcx
  UFG::InterestPoint **v10; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPointQuery>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPointQuery>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::InterestPointQuery,UFG::InterestPointQuery> *v13; // rcx
  UFG::qNode<UFG::InterestPointQuery,UFG::InterestPointQuery> *v14; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::InterestPointQuery>Vtbl *)&UFG::InterestPointQuery::`vftable;
  UFG::InterestPointQuery::End(this, QueryState_None);
  p = this->mCandidates.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].mInterestPoint.m_pPointer;
    `eh vector destructor iterator(
      p,
      0xF0ui64,
      (int)p[-1].mInterestPoint.m_pPointer,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](p_m_pPointer);
  }
  this->mCandidates.p = 0i64;
  *(_QWORD *)&this->mCandidates.size = 0i64;
  p_mBestInterestPoint = &this->mBestInterestPoint;
  if ( this->mBestInterestPoint.m_pPointer )
  {
    mPrev = p_mBestInterestPoint->mPrev;
    mNext = this->mBestInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mBestInterestPoint->mPrev = p_mBestInterestPoint;
    this->mBestInterestPoint.mNext = &this->mBestInterestPoint;
  }
  this->mBestInterestPoint.m_pPointer = 0i64;
  v7 = p_mBestInterestPoint->mPrev;
  v8 = this->mBestInterestPoint.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_mBestInterestPoint->mPrev = p_mBestInterestPoint;
  this->mBestInterestPoint.mNext = &this->mBestInterestPoint;
  v9 = this->mCandidates.p;
  if ( v9 )
  {
    v10 = &v9[-1].mInterestPoint.m_pPointer;
    `eh vector destructor iterator(
      v9,
      0xF0ui64,
      (int)v9[-1].mInterestPoint.m_pPointer,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](v10);
  }
  this->mCandidates.p = 0i64;
  *(_QWORD *)&this->mCandidates.size = 0i64;
  this->vfptr = (UFG::qSafePointerNode<UFG::InterestPointQuery>Vtbl *)&UFG::qSafePointerNode<UFG::InterestPointQuery>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v11 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::InterestPointQuery>::mPrev;
  v12 = this->m_SafePointerList.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::InterestPointQuery>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v13 = this->mPrev;
  v14 = this->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  this->mPrev = &this->UFG::qNode<UFG::InterestPointQuery,UFG::InterestPointQuery>;
  this->mNext = &this->UFG::qNode<UFG::InterestPointQuery,UFG::InterestPointQuery>;
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
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *p_mBestInterestPoint; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v10; // rax
  __int64 size; // rax
  __int64 v12; // rbx
  __int64 v13; // rsi
  UFG::InterestPointQuery::Candidate *v14; // rbp
  char v15; // al
  UFG::DaemonManager *v16; // rax

  if ( this->mNavComponent )
  {
    p_mBestInterestPoint = &this->mBestInterestPoint;
    if ( this->mBestInterestPoint.m_pPointer )
    {
      mPrev = p_mBestInterestPoint->mPrev;
      mNext = this->mBestInterestPoint.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mBestInterestPoint->mPrev = p_mBestInterestPoint;
      this->mBestInterestPoint.mNext = &this->mBestInterestPoint;
    }
    this->mBestInterestPoint.m_pPointer = 0i64;
    if ( pBestPOI
      && ((m_pSimObject = (UFG::SimObjectCharacter *)this->mNavComponent->m_pSimObject) != 0i64
       && m_pSimObject == LocalPlayer
       || !UFG::InterestPoint::IsTraversalsEnabled()) )
    {
      if ( p_mBestInterestPoint->m_pPointer )
      {
        v8 = p_mBestInterestPoint->mPrev;
        v9 = p_mBestInterestPoint->mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        p_mBestInterestPoint->mPrev = p_mBestInterestPoint;
        p_mBestInterestPoint->mNext = p_mBestInterestPoint;
      }
      p_mBestInterestPoint->m_pPointer = pBestPOI;
      v10 = pBestPOI->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev;
      v10->mNext = p_mBestInterestPoint;
      p_mBestInterestPoint->mNext = &pBestPOI->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode;
      p_mBestInterestPoint->mPrev = v10;
      pBestPOI->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev = p_mBestInterestPoint;
      UFG::InterestPointQuery::End(this, QueryState_Succeeded);
    }
    else
    {
      size = (int)this->mCandidates.size;
      if ( (_DWORD)size )
      {
        if ( (int)size > 1 )
          UFG::qQuickSortImpl<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
            this->mCandidates.p,
            &this->mCandidates.p[size - 1],
            UFG::AppealCompare);
        this->mQueryState = QueryState_InProgress;
      }
      else
      {
        UFG::InterestPointQuery::End(this, QueryState_Failed);
      }
    }
  }
  else
  {
    v12 = this->mCandidates.size;
    if ( this->mCandidates.size )
    {
      v13 = 0i64;
      do
      {
        v14 = &this->mCandidates.p[v13];
        v15 = *((_BYTE *)v14 + 236);
        if ( (v15 & 1) != 0 && (v15 & 2) == 0 )
        {
          v16 = UFG::DaemonManager::Instance();
          UFG::DaemonManager::CancelQuery(v16, &v14->input);
        }
        ++v13;
        --v12;
      }
      while ( v12 );
    }
    this->mQueryState = QueryState_Failed;
  }
}

// File Line: 123
// RVA: 0x38FC00
void __fastcall UFG::InterestPointQuery::Update(UFG::InterestPointQuery *this)
{
  unsigned int size; // r14d
  unsigned int v3; // ebp
  __int64 v4; // rbx
  UFG::InterestPointQuery::Candidate *v5; // rdi
  char v6; // al
  UFG::NavComponent *mNavComponent; // rdx
  float y; // xmm0_4
  float z; // xmm1_4
  bool m_bValid; // al
  UFG::qVector3 *Position; // rax
  float v12; // xmm1_4
  float v13; // xmm0_4
  UFG::DaemonManager *v14; // rax
  char v15; // al
  UFG::DaemonOutputStatus m_status; // ecx
  char v17; // al
  UFG::InterestPointQuery::QueryState v18; // edx
  UFG::DaemonManager *v19; // rax
  unsigned int v20; // eax

  if ( this->mQueryState == QueryState_InProgress && this->mNavComponent )
  {
    size = this->mCandidates.size;
    v3 = 0;
    if ( size )
    {
      do
      {
        v4 = v3;
        v5 = &this->mCandidates.p[v4];
        if ( v5->mInterestPoint.m_pPointer )
        {
          v6 = *((_BYTE *)v5 + 236);
          if ( (v6 & 1) == 0 && (v6 & 2) == 0 )
          {
            v5->input.m_pNavParams = &this->mNavComponent->m_navParams;
            mNavComponent = this->mNavComponent;
            y = mNavComponent->m_navPosition.m_vPosition.y;
            z = mNavComponent->m_navPosition.m_vPosition.z;
            v5->input.m_npFrom.m_vPosition.x = mNavComponent->m_navPosition.m_vPosition.x;
            v5->input.m_npFrom.m_vPosition.y = y;
            v5->input.m_npFrom.m_vPosition.z = z;
            m_bValid = mNavComponent->m_navPosition.m_bValid;
            if ( m_bValid )
            {
              v5->input.m_npFrom.m_bValid = m_bValid;
              v5->input.m_npFrom.m_hkvMeshPosition = mNavComponent->m_navPosition.m_hkvMeshPosition;
              v5->input.m_npFrom.m_packedKey = mNavComponent->m_navPosition.m_packedKey;
              v5->input.m_npFrom.m_aiMeshUid = mNavComponent->m_navPosition.m_aiMeshUid;
            }
            else
            {
              v5->input.m_npFrom.m_bValid = 0;
            }
            ((void (__fastcall *)(UFG::HavokNavPosition *))v5->input.m_npFrom.vfptr->Validate)(&v5->input.m_npFrom);
            Position = UFG::InterestPoint::GetPosition(v5->mInterestPoint.m_pPointer);
            v12 = Position->z;
            v13 = Position->y;
            v5->input.m_npTo.m_vPosition.x = Position->x;
            v5->input.m_npTo.m_vPosition.z = v12;
            v5->input.m_npTo.m_vPosition.y = v13;
            v5->input.m_npTo.m_bValid = 0;
            ((void (__fastcall *)(UFG::HavokNavPosition *))v5->input.m_npTo.vfptr->Validate)(&v5->input.m_npTo);
            v14 = UFG::DaemonManager::Instance();
            UFG::DaemonManager::SubmitQuery(v14, &v5->input, &v5->output);
            *((_BYTE *)v5 + 236) |= 1u;
          }
          v15 = *((_BYTE *)v5 + 236);
          if ( (v15 & 1) != 0 && (v15 & 2) == 0 )
          {
            m_status = v5->output.m_status;
            if ( m_status == Status_Completed )
            {
              v17 = v15 & 0xFC | 2;
              *((_BYTE *)v5 + 236) = v17;
              if ( v5->output.m_pPath.m_pNavPath )
              {
                *((_BYTE *)v5 + 236) = v17 | 4;
                UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint>::operator=(
                  &this->mBestInterestPoint,
                  &v5->mInterestPoint);
                UFG::NavComponent::InjectPath(
                  this->mNavComponent,
                  &this->mNavComponent->m_navPosition,
                  &v5->input.m_npTo,
                  v5->output.m_pPath.m_pNavPath);
                v18 = QueryState_Succeeded;
                goto LABEL_16;
              }
            }
            else
            {
              if ( m_status != Status_Failed )
                break;
              *((_BYTE *)v5 + 236) = v15 & 0xFC | 2;
            }
          }
        }
        else
        {
          v19 = UFG::DaemonManager::Instance();
          UFG::DaemonManager::CancelQuery(v19, &v5->input);
          UFG::InterestPointQuery::Candidate::operator=(
            &this->mCandidates.p[v4],
            &this->mCandidates.p[this->mCandidates.size - 1]);
          v20 = this->mCandidates.size;
          if ( v20 > 1 )
            this->mCandidates.size = v20 - 1;
          else
            this->mCandidates.size = 0;
        }
        ++v3;
      }
      while ( v3 < this->mCandidates.size );
    }
    if ( v3 == size )
    {
      v18 = QueryState_Failed;
LABEL_16:
      UFG::InterestPointQuery::End(this, v18);
    }
  }
  else
  {
    UFG::InterestPointQuery::End(this, QueryState_Failed);
  }
}

// File Line: 236
// RVA: 0x355170
void __fastcall UFG::InterestPointQuery::End(
        UFG::InterestPointQuery *this,
        UFG::InterestPointQuery::QueryState queryState)
{
  __int64 size; // rdi
  __int64 v5; // rbx
  UFG::InterestPointQuery::Candidate *v6; // rbp
  char v7; // al
  UFG::DaemonManager *v8; // rax

  if ( queryState == QueryState_InProgress )
  {
    this->mQueryState = QueryState_InProgress;
  }
  else
  {
    size = this->mCandidates.size;
    if ( this->mCandidates.size )
    {
      v5 = 0i64;
      do
      {
        v6 = &this->mCandidates.p[v5];
        v7 = *((_BYTE *)v6 + 236);
        if ( (v7 & 1) != 0 && (v7 & 2) == 0 )
        {
          v8 = UFG::DaemonManager::Instance();
          UFG::DaemonManager::CancelQuery(v8, &v6->input);
        }
        ++v5;
        --size;
      }
      while ( size );
      this->mQueryState = queryState;
    }
    else
    {
      this->mQueryState = queryState;
    }
  }
}

