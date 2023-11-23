// File Line: 71
// RVA: 0x3291B0
void __fastcall UFG::qInsertionSort<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
        UFG::InterestPointQuery::Candidate *array,
        int size,
        bool (__fastcall *predicate)(UFG::InterestPointQuery::Candidate *, UFG::InterestPointQuery::Candidate *))
{
  int v4; // edi
  int v6; // r15d
  UFG::InterestPointQuery::Candidate *v7; // r12
  int v8; // ebx
  int v9; // edi
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::NavPath *m_pNavPath; // rcx
  UFG::InterestPointQuery::Candidate __that; // [rsp+40h] [rbp-C0h] BYREF

  if ( size > 1 )
  {
    v4 = size;
    v6 = 0;
    v7 = array + 1;
    do
    {
      UFG::InterestPointQuery::Candidate::Candidate(&__that, v7);
      v8 = v6;
      if ( v6 >= 0 )
      {
        v9 = v6 + 1;
        do
        {
          if ( !predicate(&__that, &array[v8]) )
            break;
          UFG::InterestPointQuery::Candidate::operator=(&array[v9--], &array[v8--]);
        }
        while ( v8 >= 0 );
        v4 = size;
      }
      UFG::InterestPointQuery::Candidate::operator=(&array[v8 + 1], &__that);
      if ( __that.mInterestPoint.m_pPointer )
      {
        mPrev = __that.mInterestPoint.mPrev;
        mNext = __that.mInterestPoint.mNext;
        __that.mInterestPoint.mPrev->mNext = __that.mInterestPoint.mNext;
        mNext->mPrev = mPrev;
        __that.mInterestPoint.mPrev = &__that.mInterestPoint;
        __that.mInterestPoint.mNext = &__that.mInterestPoint;
      }
      __that.mInterestPoint.m_pPointer = 0i64;
      v12 = __that.mInterestPoint.mPrev;
      v13 = __that.mInterestPoint.mNext;
      __that.mInterestPoint.mPrev->mNext = __that.mInterestPoint.mNext;
      v13->mPrev = v12;
      __that.mInterestPoint.mPrev = &__that.mInterestPoint;
      __that.mInterestPoint.mNext = &__that.mInterestPoint;
      m_pNavPath = __that.output.m_pPath.m_pNavPath;
      if ( __that.output.m_pPath.m_pNavPath )
      {
        --__that.output.m_pPath.m_pNavPath->m_uRefCount;
        if ( !m_pNavPath->m_uRefCount )
          m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
      }
      __that.output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
      __that.input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
      ++v7;
      ++v6;
    }
    while ( v6 + 1 < v4 );
  }
}

// File Line: 162
// RVA: 0x329350
void __fastcall UFG::qQuickSortImpl<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
        UFG::InterestPointQuery::Candidate *left,
        UFG::InterestPointQuery::Candidate *right,
        bool (__fastcall *predicate)(UFG::InterestPointQuery::Candidate *, UFG::InterestPointQuery::Candidate *))
{
  UFG::InterestPointQuery::Candidate *v4; // rbx
  __int64 v5; // rdx
  int v6; // eax
  UFG::InterestPointQuery::Candidate *v7; // rdi
  UFG::InterestPointQuery::Candidate *v8; // rdi
  UFG::InterestPointQuery::Candidate *v9; // rax
  UFG::InterestPointQuery::Candidate *v10; // rdi
  UFG::InterestPointQuery::Candidate *v11; // rbx
  __int64 v12; // rcx
  _QWORD *v13; // rax
  __int64 v14; // rcx
  _QWORD *v15; // rax
  UFG::DaemonQueryOutputVtbl *vfptr; // rcx
  UFG::InterestPointQuery::Candidate *v17; // [rsp+20h] [rbp-C8h]
  UFG::InterestPointQuery::Candidate v18; // [rsp+30h] [rbp-B8h] BYREF
  UFG::InterestPointQuery::Candidate *__that; // [rsp+228h] [rbp+140h]
  UFG::InterestPointQuery::Candidate *righta; // [rsp+230h] [rbp+148h]
  UFG::InterestPointQuery::Candidate *v21; // [rsp+240h] [rbp+158h]

  v18.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)-2i64;
  v4 = left;
  v5 = right - left;
  v6 = v5 + 1;
  if ( (int)v5 + 1 < 32 )
  {
    if ( v6 > 1 )
      UFG::qInsertionSort<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
        left,
        v6,
        predicate);
  }
  else
  {
    v7 = &left[v5 / 2];
    if ( predicate(v7, left) )
    {
      UFG::InterestPointQuery::Candidate::Candidate(&v18, v7);
      UFG::InterestPointQuery::Candidate::operator=(v7, v4);
      UFG::InterestPointQuery::Candidate::operator=(v4, &v18);
      UFG::InterestPointQuery::Candidate::~Candidate(&v18);
    }
    if ( predicate(righta, v7) )
    {
      UFG::InterestPointQuery::Candidate::Candidate(&v18, righta);
      UFG::InterestPointQuery::Candidate::operator=(righta, v7);
      UFG::InterestPointQuery::Candidate::operator=(v7, &v18);
      UFG::InterestPointQuery::Candidate::~Candidate(&v18);
    }
    if ( predicate(v7, v4) )
    {
      UFG::InterestPointQuery::Candidate::Candidate(&v18, v7);
      UFG::InterestPointQuery::Candidate::operator=(v7, v4);
      UFG::InterestPointQuery::Candidate::operator=(v4, &v18);
      UFG::InterestPointQuery::Candidate::~Candidate(&v18);
    }
    UFG::InterestPointQuery::Candidate::Candidate((UFG::InterestPointQuery::Candidate *)&v18.mAppealScore, v7);
    v21 = v4;
    v8 = righta;
    v17 = righta;
    v9 = __that;
    if ( __that <= righta )
    {
      do
      {
        if ( predicate(v4, (UFG::InterestPointQuery::Candidate *)&v18.mAppealScore) )
        {
          v10 = righta;
          do
          {
            if ( v4 >= v10 )
              break;
            ++v4;
          }
          while ( predicate(v4, (UFG::InterestPointQuery::Candidate *)&v18.mAppealScore) );
          v21 = v4;
          v8 = v17;
        }
        if ( predicate((UFG::InterestPointQuery::Candidate *)&v18.mAppealScore, v8) )
        {
          v11 = __that;
          do
          {
            if ( v11 >= v8 )
              break;
            --v8;
          }
          while ( predicate((UFG::InterestPointQuery::Candidate *)&v18.mAppealScore, v8) );
          v4 = v21;
        }
        if ( v4 > v8 )
          break;
        UFG::InterestPointQuery::Candidate::Candidate(&v18, v4);
        UFG::InterestPointQuery::Candidate::operator=(v4, v8);
        UFG::InterestPointQuery::Candidate::operator=(v8, &v18);
        if ( v18.output.m_pPath.m_pNavPath )
        {
          v12 = *(_QWORD *)&v18.output.m_id;
          v13 = *(_QWORD **)&v18.output.m_status;
          *(_QWORD *)(*(_QWORD *)&v18.output.m_id + 8i64) = *(_QWORD *)&v18.output.m_status;
          *v13 = v12;
          *(_QWORD *)&v18.output.m_id = &v18.output.m_id;
          *(_QWORD *)&v18.output.m_status = &v18.output.m_id;
        }
        v18.output.m_pPath.m_pNavPath = 0i64;
        v14 = *(_QWORD *)&v18.output.m_id;
        v15 = *(_QWORD **)&v18.output.m_status;
        *(_QWORD *)(*(_QWORD *)&v18.output.m_id + 8i64) = *(_QWORD *)&v18.output.m_status;
        *v15 = v14;
        *(_QWORD *)&v18.output.m_id = &v18.output.m_id;
        *(_QWORD *)&v18.output.m_status = &v18.output.m_id;
        vfptr = v18.output.vfptr;
        if ( v18.output.vfptr )
        {
          --LODWORD(v18.output.vfptr[5].__vecDelDtor);
          if ( !LODWORD(vfptr[5].__vecDelDtor) )
            (*(void (__fastcall **)(UFG::DaemonQueryOutputVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
        }
        *(_QWORD *)(&v18.input.m_npTo.m_aiMeshUid + 1) = &UFG::DaemonQueryOutput::`vftable;
        v18.input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
        v21 = ++v4;
        v17 = --v8;
      }
      while ( v4 <= v8 );
      v9 = __that;
    }
    if ( v9 < v8 )
      UFG::qQuickSortImpl<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
        v9,
        v8,
        predicate);
    if ( v4 < righta )
      UFG::qQuickSortImpl<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
        v4,
        righta,
        predicate);
    UFG::InterestPointQuery::Candidate::~Candidate((UFG::InterestPointQuery::Candidate *)&v18.mAppealScore);
  }
}

