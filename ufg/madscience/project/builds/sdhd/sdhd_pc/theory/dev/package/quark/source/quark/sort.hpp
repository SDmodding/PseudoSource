// File Line: 71
// RVA: 0x3291B0
void __fastcall UFG::qInsertionSort<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(UFG::InterestPointQuery::Candidate *array, int size, bool (__fastcall *predicate)(UFG::InterestPointQuery::Candidate *, UFG::InterestPointQuery::Candidate *))
{
  bool (__fastcall *v3)(UFG::InterestPointQuery::Candidate *, UFG::InterestPointQuery::Candidate *); // r13
  int v4; // edi
  UFG::InterestPointQuery::Candidate *v5; // r14
  int v6; // er15
  UFG::InterestPointQuery::Candidate *v7; // r12
  int v8; // ebx
  int v9; // edi
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::NavPath *v14; // rcx
  UFG::InterestPointQuery::Candidate __that; // [rsp+40h] [rbp-C0h]
  int v16; // [rsp+178h] [rbp+78h]

  if ( size > 1 )
  {
    v16 = size;
    v3 = predicate;
    v4 = size;
    v5 = array;
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
          if ( !v3(&__that, &v5[v8]) )
            break;
          UFG::InterestPointQuery::Candidate::operator=(&v5[v9--], &v5[v8--]);
        }
        while ( v8 >= 0 );
        v4 = v16;
      }
      UFG::InterestPointQuery::Candidate::operator=(&v5[v8 + 1], &__that);
      if ( __that.mInterestPoint.m_pPointer )
      {
        v10 = __that.mInterestPoint.mPrev;
        v11 = __that.mInterestPoint.mNext;
        __that.mInterestPoint.mPrev->mNext = __that.mInterestPoint.mNext;
        v11->mPrev = v10;
        __that.mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&__that.mInterestPoint.mPrev;
        __that.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&__that.mInterestPoint.mPrev;
      }
      __that.mInterestPoint.m_pPointer = 0i64;
      v12 = __that.mInterestPoint.mPrev;
      v13 = __that.mInterestPoint.mNext;
      __that.mInterestPoint.mPrev->mNext = __that.mInterestPoint.mNext;
      v13->mPrev = v12;
      __that.mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&__that.mInterestPoint.mPrev;
      __that.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&__that.mInterestPoint.mPrev;
      v14 = __that.output.m_pPath.m_pNavPath;
      if ( __that.output.m_pPath.m_pNavPath )
      {
        --__that.output.m_pPath.m_pNavPath->m_uRefCount;
        if ( !v14->m_uRefCount )
          v14->vfptr->__vecDelDtor(v14, 1u);
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
void __fastcall UFG::qQuickSortImpl<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(UFG::InterestPointQuery::Candidate *left, UFG::InterestPointQuery::Candidate *right, bool (__fastcall *predicate)(UFG::InterestPointQuery::Candidate *, UFG::InterestPointQuery::Candidate *))
{
  bool (__fastcall *v3)(UFG::InterestPointQuery::Candidate *, UFG::InterestPointQuery::Candidate *); // rsi
  UFG::InterestPointQuery::Candidate *v4; // rbx
  unsigned __int64 v5; // rdx
  signed __int64 v6; // rdx
  int v7; // eax
  UFG::InterestPointQuery::Candidate *v8; // rdi
  UFG::InterestPointQuery::Candidate *v9; // rdi
  UFG::InterestPointQuery::Candidate *v10; // rax
  UFG::InterestPointQuery::Candidate *v11; // rdi
  UFG::InterestPointQuery::Candidate *v12; // rbx
  __int64 v13; // rcx
  _QWORD *v14; // rax
  __int64 v15; // rcx
  _QWORD *v16; // rax
  UFG::DaemonQueryOutputVtbl *v17; // rcx
  UFG::InterestPointQuery::Candidate *v18; // [rsp+20h] [rbp-C8h]
  UFG::InterestPointQuery::Candidate v19; // [rsp+30h] [rbp-B8h]
  UFG::InterestPointQuery::Candidate *__that; // [rsp+228h] [rbp+140h]
  UFG::InterestPointQuery::Candidate *righta; // [rsp+230h] [rbp+148h]
  UFG::InterestPointQuery::Candidate *v22; // [rsp+240h] [rbp+158h]

  v19.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)-2i64;
  v3 = predicate;
  v4 = left;
  v5 = (signed __int64)((char *)right
                      - (char *)left
                      + ((unsigned __int128)(((char *)right - (char *)left) * (signed __int128)-8608480567731124087i64) >> 64)) >> 7;
  v6 = (v5 >> 63) + v5;
  v7 = v6 + 1;
  if ( (signed int)v6 + 1 < 32 )
  {
    if ( v7 > 1 )
      UFG::qInsertionSort<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
        left,
        v7,
        predicate);
  }
  else
  {
    v8 = &left[v6 / 2];
    if ( predicate(v8, left) )
    {
      UFG::InterestPointQuery::Candidate::Candidate(&v19, v8);
      UFG::InterestPointQuery::Candidate::operator=(v8, v4);
      UFG::InterestPointQuery::Candidate::operator=(v4, &v19);
      UFG::InterestPointQuery::Candidate::~Candidate(&v19);
    }
    if ( v3(righta, v8) )
    {
      UFG::InterestPointQuery::Candidate::Candidate(&v19, righta);
      UFG::InterestPointQuery::Candidate::operator=(righta, v8);
      UFG::InterestPointQuery::Candidate::operator=(v8, &v19);
      UFG::InterestPointQuery::Candidate::~Candidate(&v19);
    }
    if ( v3(v8, v4) )
    {
      UFG::InterestPointQuery::Candidate::Candidate(&v19, v8);
      UFG::InterestPointQuery::Candidate::operator=(v8, v4);
      UFG::InterestPointQuery::Candidate::operator=(v4, &v19);
      UFG::InterestPointQuery::Candidate::~Candidate(&v19);
    }
    UFG::InterestPointQuery::Candidate::Candidate((UFG::InterestPointQuery::Candidate *)((char *)&v19 + 232), v8);
    v22 = v4;
    v9 = righta;
    v18 = righta;
    v10 = __that;
    if ( __that <= righta )
    {
      do
      {
        if ( v3(v4, (UFG::InterestPointQuery::Candidate *)((char *)&v19 + 232)) )
        {
          v11 = righta;
          do
          {
            if ( v4 >= v11 )
              break;
            ++v4;
          }
          while ( v3(v4, (UFG::InterestPointQuery::Candidate *)((char *)&v19 + 232)) );
          v22 = v4;
          v9 = v18;
        }
        if ( v3((UFG::InterestPointQuery::Candidate *)((char *)&v19 + 232), v9) )
        {
          v12 = __that;
          do
          {
            if ( v12 >= v9 )
              break;
            --v9;
          }
          while ( v3((UFG::InterestPointQuery::Candidate *)((char *)&v19 + 232), v9) );
          v4 = v22;
        }
        if ( v4 > v9 )
          break;
        UFG::InterestPointQuery::Candidate::Candidate(&v19, v4);
        UFG::InterestPointQuery::Candidate::operator=(v4, v9);
        UFG::InterestPointQuery::Candidate::operator=(v9, &v19);
        if ( v19.output.m_pPath.m_pNavPath )
        {
          v13 = *(_QWORD *)&v19.output.m_id;
          v14 = *(_QWORD **)&v19.output.m_status;
          *(_QWORD *)(*(_QWORD *)&v19.output.m_id + 8i64) = *(_QWORD *)&v19.output.m_status;
          *v14 = v13;
          *(_QWORD *)&v19.output.m_id = (char *)&v19 + 184;
          *(_QWORD *)&v19.output.m_status = (char *)&v19 + 184;
        }
        v19.output.m_pPath.m_pNavPath = 0i64;
        v15 = *(_QWORD *)&v19.output.m_id;
        v16 = *(_QWORD **)&v19.output.m_status;
        *(_QWORD *)(*(_QWORD *)&v19.output.m_id + 8i64) = *(_QWORD *)&v19.output.m_status;
        *v16 = v15;
        *(_QWORD *)&v19.output.m_id = (char *)&v19 + 184;
        *(_QWORD *)&v19.output.m_status = (char *)&v19 + 184;
        v17 = v19.output.vfptr;
        if ( v19.output.vfptr )
        {
          --LODWORD(v19.output.vfptr[5].__vecDelDtor);
          if ( !LODWORD(v17[5].__vecDelDtor) )
            (*(void (__fastcall **)(UFG::DaemonQueryOutputVtbl *, signed __int64))v17->__vecDelDtor)(v17, 1i64);
        }
        *(_QWORD *)(&v19.input.m_npTo.m_aiMeshUid + 1) = &UFG::DaemonQueryOutput::`vftable;
        v19.input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
        ++v4;
        v22 = v4;
        --v9;
        v18 = v9;
      }
      while ( v4 <= v9 );
      v10 = __that;
    }
    if ( v10 < v9 )
      UFG::qQuickSortImpl<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
        v10,
        v9,
        v3);
    if ( v4 < righta )
      UFG::qQuickSortImpl<UFG::InterestPointQuery::Candidate,bool (*)(UFG::InterestPointQuery::Candidate const &,UFG::InterestPointQuery::Candidate const &)>(
        v4,
        righta,
        v3);
    UFG::InterestPointQuery::Candidate::~Candidate((UFG::InterestPointQuery::Candidate *)((char *)&v19 + 232));
  }
}

