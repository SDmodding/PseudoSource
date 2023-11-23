// File Line: 41
// RVA: 0x2694F0
void __fastcall TracksEnumBinding<unsigned long>::~TracksEnumBinding<unsigned long>(
        TracksEnumBinding<unsigned long> *this)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v3; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v4; // rax

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
  v3 = this->mPrev;
  v4 = this->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 92
// RVA: 0x2693D0
void __fastcall TracksEnum<unsigned long>::~TracksEnum<unsigned long>(TracksEnum<unsigned long> *this)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  EnumList<unsigned long> **p; // rcx
  UFG::qNode<TracksEnum<unsigned long>,TracksEnum<unsigned long> > *v5; // rcx
  UFG::qNode<TracksEnum<unsigned long>,TracksEnum<unsigned long> > *v6; // rax

  this->vfptr = (TracksEnum<unsigned long>Vtbl *)&TracksEnum<unsigned long>::`vftable;
  TracksEnum<unsigned long>::Unload((TracksEnum<float> *)this);
  UFG::qList<TracksEnumBinding<float>,TracksEnumBinding<float>,1,0>::DeleteNodes((UFG::qList<TracksEnumBinding<float>,TracksEnumBinding<float>,1,0> *)&this->m_UnresolvedTracksEnumBindingList);
  mPrev = this->m_UnresolvedTracksEnumBindingList.mNode.mPrev;
  mNext = this->m_UnresolvedTracksEnumBindingList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_UnresolvedTracksEnumBindingList.mNode.mPrev = &this->m_UnresolvedTracksEnumBindingList.mNode;
  this->m_UnresolvedTracksEnumBindingList.mNode.mNext = &this->m_UnresolvedTracksEnumBindingList.mNode;
  p = this->m_enumLists.p;
  if ( p )
    operator delete[](p);
  this->m_enumLists.p = 0i64;
  *(_QWORD *)&this->m_enumLists.size = 0i64;
  v5 = this->mPrev;
  v6 = this->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPrev = &this->UFG::qNode<TracksEnum<unsigned long>,TracksEnum<unsigned long> >;
  this->mNext = &this->UFG::qNode<TracksEnum<unsigned long>,TracksEnum<unsigned long> >;
}

// File Line: 154
// RVA: 0x268640
void __fastcall TracksEnum<float>::TracksEnum<float>(TracksEnum<float> *this, const char *pFileName)
{
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax

  v2 = (UFG::qNode<UFG::qString,UFG::qString> *)&this->UFG::qNode<TracksEnum<float>,TracksEnum<float> >;
  this->mPrev = &this->UFG::qNode<TracksEnum<float>,TracksEnum<float> >;
  this->mNext = &this->UFG::qNode<TracksEnum<float>,TracksEnum<float> >;
  this->vfptr = (TracksEnum<float>Vtbl *)&TracksEnum<float>::`vftable;
  this->m_enumLists.p = 0i64;
  *(_QWORD *)&this->m_enumLists.size = 0i64;
  this->m_fileName = pFileName;
  this->m_UnresolvedTracksEnumBindingList.mNode.mPrev = &this->m_UnresolvedTracksEnumBindingList.mNode;
  this->m_UnresolvedTracksEnumBindingList.mNode.mNext = &this->m_UnresolvedTracksEnumBindingList.mNode;
  if ( (`TracksEnum<float>::GetTracksEnumList::`2::`local static guard & 1) == 0 )
  {
    `TracksEnum<float>::GetTracksEnumList::`2::`local static guard |= 1u;
    `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = &`TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList;
    `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mNext = &`TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList;
    atexit(TracksEnum_float_::GetTracksEnumList_::_2_::_dynamic_atexit_destructor_for__m_TracksEnumList__);
  }
  mPrev = `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mPrev;
  `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &`TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList;
  `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = v2;
}

// File Line: 162
// RVA: 0x267F60
void __fastcall TracksEnum<unsigned long>::TracksEnum<unsigned long>(
        TracksEnum<unsigned long> *this,
        const char **pArray,
        const int arraySize,
        const unsigned int *pIds)
{
  __int64 v4; // rbx
  TracksEnum<unsigned long> *v5; // rbp
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rdi
  unsigned int v7; // r15d
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rdi
  unsigned int *v11; // r13
  __int64 v12; // rsi
  unsigned int v13; // r12d
  unsigned int v14; // r14d
  __int64 v15; // rbp
  unsigned int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // ebx
  unsigned __int64 v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rsi
  unsigned int i; // r9d
  __int64 v23; // rax
  __int64 v24; // rbx
  char *mNextAlloc; // r14
  UFG::allocator::free_link *v26; // rax
  const char *v27; // rcx
  char *v28; // rdx
  char v29; // al
  unsigned int *v30; // r10
  __int64 mNext_low; // rbp
  unsigned int v32; // edi
  unsigned int mNext_high; // ebx
  unsigned int v34; // ebx
  unsigned __int64 v35; // rax
  UFG::allocator::free_link *v36; // rax
  UFG::allocator::free_link *v37; // rsi
  unsigned int j; // r9d
  unsigned int *v39; // r10
  __int64 v40; // rbp
  unsigned int v41; // edi
  unsigned int v42; // ebx
  unsigned int v43; // ebx
  unsigned __int64 v44; // rax
  UFG::allocator::free_link *v45; // rax
  UFG::allocator::free_link *v46; // rsi
  unsigned int k; // r9d
  _DWORD *v48; // rbx
  __int64 size; // rbp
  unsigned int v50; // edi
  unsigned int capacity; // ebx
  unsigned int v52; // ebx
  unsigned __int64 v53; // rax
  UFG::allocator::free_link *v54; // rax
  UFG::allocator::free_link *v55; // rsi
  unsigned int m; // r9d
  __int64 v57; // rsi
  unsigned int v58; // ebx
  unsigned int v59; // eax
  unsigned __int64 v60; // rax
  UFG::allocator::free_link *v61; // rax
  EnumList<unsigned long> **v62; // rdi
  UFG::allocator::free_link *v63; // [rsp+20h] [rbp-68h]
  UFG::allocator::free_link *v64; // [rsp+28h] [rbp-60h]
  __int64 v65; // [rsp+30h] [rbp-58h]
  EnumList<unsigned long> *v66; // [rsp+38h] [rbp-50h]
  __int64 v67; // [rsp+40h] [rbp-48h]

  v4 = arraySize;
  v5 = this;
  v6 = (UFG::qNode<UFG::qString,UFG::qString> *)&this->UFG::qNode<TracksEnum<unsigned long>,TracksEnum<unsigned long> >;
  this->mPrev = &this->UFG::qNode<TracksEnum<unsigned long>,TracksEnum<unsigned long> >;
  this->mNext = &this->UFG::qNode<TracksEnum<unsigned long>,TracksEnum<unsigned long> >;
  this->vfptr = (TracksEnum<unsigned long>Vtbl *)&TracksEnum<unsigned long>::`vftable;
  v7 = 0;
  this->m_enumLists.p = 0i64;
  *(_QWORD *)&this->m_enumLists.size = 0i64;
  this->m_fileName = 0i64;
  this->m_UnresolvedTracksEnumBindingList.mNode.mPrev = &this->m_UnresolvedTracksEnumBindingList.mNode;
  this->m_UnresolvedTracksEnumBindingList.mNode.mNext = &this->m_UnresolvedTracksEnumBindingList.mNode;
  if ( (`TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard & 1) == 0 )
  {
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard |= 1u;
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mNext = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
    atexit(TracksEnum_unsigned_long_::GetTracksEnumList_::_2_::_dynamic_atexit_destructor_for__m_TracksEnumList__);
  }
  mPrev = `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev;
  `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev->mNext = v6;
  v6->mPrev = mPrev;
  v6->mNext = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
  `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = v6;
  v9 = UFG::qMalloc(0x48ui64, "TRACKSENUM", 0i64);
  v10 = v9;
  v66 = (EnumList<unsigned long> *)v9;
  if ( v9 )
  {
    LODWORD(v9->mNext) = -1;
    v9[2].mNext = 0i64;
    v9[1].mNext = 0i64;
    v9[4].mNext = 0i64;
    v9[3].mNext = 0i64;
    v9[6].mNext = 0i64;
    v9[5].mNext = 0i64;
    v9[8].mNext = 0i64;
    v9[7].mNext = 0i64;
  }
  else
  {
    v10 = 0i64;
    v66 = 0i64;
  }
  v63 = v10 + 1;
  if ( (unsigned int)v4 > HIDWORD(v10[1].mNext) )
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v10[1],
      v4,
      "qArray.Reserve.TracksEnum");
  v64 = v10 + 3;
  if ( (unsigned int)v4 > HIDWORD(v10[3].mNext) )
    UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v10[3], v4, "qArray.Reserve.TracksEnum");
  v11 = (unsigned int *)&v10[7];
  if ( (unsigned int)v4 > HIDWORD(v10[7].mNext) )
    UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v10[7], v4, "qArray.Reserve.TracksEnum");
  if ( (unsigned int)v4 > HIDWORD(v10[5].mNext) )
    UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v10[5], v4, "qArray.Reserve.TracksEnum");
  v12 = 0i64;
  v65 = 0i64;
  v67 = v4;
  v13 = 1;
  if ( (int)v4 > 0 )
  {
    do
    {
      if ( pIds )
        v14 = pIds[v12];
      else
        v14 = *v11;
      v15 = *v11;
      v16 = v15 + 1;
      v17 = v11[1];
      if ( (int)v15 + 1 > v17 )
      {
        if ( v17 )
          v18 = 2 * v17;
        else
          v18 = 1;
        for ( ; v18 < v16; v18 *= 2 )
          ;
        if ( v18 <= 4 )
          v18 = 4;
        if ( v18 - v16 > 0x10000 )
          v18 = v15 + 65537;
        if ( v18 != (_DWORD)v15 )
        {
          v19 = 4i64 * v18;
          if ( !is_mul_ok(v18, 4ui64) )
            v19 = -1i64;
          v20 = UFG::qMalloc(v19, "qArray.Add", 0i64);
          v21 = v20;
          if ( *((_QWORD *)v11 + 1) )
          {
            for ( i = 0; i < *v11; ++i )
              *((_DWORD *)&v20->mNext + i) = *(_DWORD *)(4i64 * i + *((_QWORD *)v11 + 1));
            operator delete[](*((void **)v11 + 1));
          }
          *((_QWORD *)v11 + 1) = v21;
          v11[1] = v18;
          v12 = v65;
        }
      }
      *v11 = v16;
      *(_DWORD *)(*((_QWORD *)v11 + 1) + 4 * v15) = v14;
      if ( (`UFG::qStaticInitAllocator::Instance::`2::`local static guard & 1) == 0 )
      {
        `UFG::qStaticInitAllocator::Instance::`2::`local static guard |= 1u;
        UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance::`2::instance);
        atexit(`UFG::qStaticInitAllocator::Instance::`2::`dynamic atexit destructor for instance);
      }
      v23 = -1i64;
      do
        ++v23;
      while ( pArray[v12][v23] );
      v24 = v23 + 1;
      mNextAlloc = `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc;
      if ( !`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks
        || &`UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc[v24] > `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock )
      {
        v26 = UFG::qMalloc(0x1FF0ui64, "gStaticInitAllocator", 1ui64);
        v26->mNext = (UFG::allocator::free_link *)`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks;
        `UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks = (UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *)v26;
        mNextAlloc = (char *)&v26[1];
        `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock = (char *)&v26[1022];
      }
      `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc = &mNextAlloc[v24];
      ++`UFG::qStaticInitAllocator::Instance::`2::instance.mTotalAlloc;
      v27 = pArray[v12];
      v28 = mNextAlloc;
      do
      {
        v29 = *v27;
        *v28++ = *v27++;
      }
      while ( v29 );
      v30 = (unsigned int *)v63;
      mNext_low = LODWORD(v63->mNext);
      v32 = mNext_low + 1;
      mNext_high = HIDWORD(v63->mNext);
      if ( (int)mNext_low + 1 > mNext_high )
      {
        if ( mNext_high )
          v34 = 2 * mNext_high;
        else
          v34 = 1;
        for ( ; v34 < v32; v34 *= 2 )
          ;
        if ( v34 <= 2 )
          v34 = 2;
        if ( v34 - v32 > 0x10000 )
          v34 = mNext_low + 65537;
        if ( v34 != (_DWORD)mNext_low )
        {
          v35 = 8i64 * v34;
          if ( !is_mul_ok(v34, 8ui64) )
            v35 = -1i64;
          v36 = UFG::qMalloc(v35, "qArray.Add", 0i64);
          v37 = v36;
          v30 = (unsigned int *)v63;
          if ( v63[1].mNext )
          {
            for ( j = 0; j < LODWORD(v63->mNext); ++j )
              v36[j] = v63[1].mNext[j];
            operator delete[](v63[1].mNext);
            v30 = (unsigned int *)v63;
          }
          *((_QWORD *)v30 + 1) = v37;
          v30[1] = v34;
        }
      }
      *v30 = v32;
      *(_QWORD *)(*((_QWORD *)v30 + 1) + 8 * mNext_low) = mNextAlloc;
      v39 = (unsigned int *)v64;
      v40 = LODWORD(v64->mNext);
      v41 = v40 + 1;
      v42 = HIDWORD(v64->mNext);
      if ( (int)v40 + 1 > v42 )
      {
        if ( v42 )
          v43 = 2 * v42;
        else
          v43 = 1;
        for ( ; v43 < v41; v43 *= 2 )
          ;
        if ( v43 <= 4 )
          v43 = 4;
        if ( v43 - v41 > 0x10000 )
          v43 = v40 + 65537;
        if ( v43 != (_DWORD)v40 )
        {
          v44 = 4i64 * v43;
          if ( !is_mul_ok(v43, 4ui64) )
            v44 = -1i64;
          v45 = UFG::qMalloc(v44, "qArray.Add", 0i64);
          v46 = v45;
          v39 = (unsigned int *)v64;
          if ( v64[1].mNext )
          {
            for ( k = 0; k < LODWORD(v64->mNext); ++k )
              *((_DWORD *)&v45->mNext + k) = *((_DWORD *)&v64[1].mNext->mNext + k);
            operator delete[](v64[1].mNext);
            v39 = (unsigned int *)v64;
          }
          *((_QWORD *)v39 + 1) = v46;
          v39[1] = v43;
        }
      }
      *v39 = v41;
      v48 = (_DWORD *)(*((_QWORD *)v39 + 1) + 4 * v40);
      *v48 = UFG::qStringHash32(mNextAlloc, 0xFFFFFFFF);
      size = v66->m_uid.size;
      v50 = size + 1;
      capacity = v66->m_uid.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v52 = 2 * capacity;
        else
          v52 = 1;
        for ( ; v52 < v50; v52 *= 2 )
          ;
        if ( v52 <= 4 )
          v52 = 4;
        if ( v52 - v50 > 0x10000 )
          v52 = size + 65537;
        if ( v52 != (_DWORD)size )
        {
          v53 = 4i64 * v52;
          if ( !is_mul_ok(v52, 4ui64) )
            v53 = -1i64;
          v54 = UFG::qMalloc(v53, "qArray.Add", 0i64);
          v55 = v54;
          if ( v66->m_uid.p )
          {
            for ( m = 0; m < v66->m_uid.size; ++m )
              *((_DWORD *)&v54->mNext + m) = v66->m_uid.p[m];
            operator delete[](v66->m_uid.p);
          }
          v66->m_uid.p = (unsigned int *)v55;
          v66->m_uid.capacity = v52;
        }
      }
      v66->m_uid.size = v50;
      v66->m_uid.p[size] = 0;
      v12 = v65 + 1;
      v65 = v12;
    }
    while ( v12 < v67 );
    v5 = this;
  }
  v57 = v5->m_enumLists.size;
  v58 = v57 + 1;
  v59 = v5->m_enumLists.capacity;
  if ( (int)v57 + 1 > v59 )
  {
    if ( v59 )
      v13 = 2 * v59;
    for ( ; v13 < v58; v13 *= 2 )
      ;
    if ( v13 <= 2 )
      v13 = 2;
    if ( v13 - v58 > 0x10000 )
      v13 = v57 + 65537;
    if ( v13 != (_DWORD)v57 )
    {
      v60 = 8i64 * v13;
      if ( !is_mul_ok(v13, 8ui64) )
        v60 = -1i64;
      v61 = UFG::qMalloc(v60, "qArray.Add", 0i64);
      v62 = (EnumList<unsigned long> **)v61;
      if ( v5->m_enumLists.p )
      {
        if ( v5->m_enumLists.size )
        {
          do
          {
            v61[v7] = (UFG::allocator::free_link)v5->m_enumLists.p[v7];
            ++v7;
          }
          while ( v7 < v5->m_enumLists.size );
        }
        operator delete[](v5->m_enumLists.p);
      }
      v5->m_enumLists.p = v62;
      v5->m_enumLists.capacity = v13;
    }
  }
  v5->m_enumLists.size = v58;
  v5->m_enumLists.p[v57] = v66;
}     v61[v7] = (UFG::allocator::free_link)v5->m_enumLists.p[v7];
            ++v7;
          }
          while ( v7 < v5->m_enumLists.size );
        }
        operator delete[](v5->m_en

// File Line: 187
// RVA: 0x422E20
void __fastcall TracksEnum<unsigned long>::Initialize(const char *dataPath)
{
  int v1; // ecx
  UFG::qNode<UFG::qString,UFG::qString> *i; // rbx

  UFG::qString::Set(&TracksEnum<unsigned long>::mDataPath, dataPath);
  v1 = `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard;
  if ( (`TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard & 1) == 0 )
  {
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard |= 1u;
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mNext = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
    atexit(TracksEnum_unsigned_long_::GetTracksEnumList_::_2_::_dynamic_atexit_destructor_for__m_TracksEnumList___0);
    v1 = `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard;
  }
  for ( i = (UFG::qNode<UFG::qString,UFG::qString> *)((char *)`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mNext
                                                    - 8);
        ;
        i = (UFG::qNode<UFG::qString,UFG::qString> *)((char *)i[1].mPrev - 8) )
  {
    if ( (v1 & 1) == 0 )
    {
      `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard = v1 | 1;
      `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
      `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mNext = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
      atexit(TracksEnum_unsigned_long_::GetTracksEnumList_::_2_::_dynamic_atexit_destructor_for__m_TracksEnumList___0);
    }
    if ( i == (UFG::qNode<UFG::qString,UFG::qString> *)((char *)&`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList
                                                      - 8) )
      break;
    TracksEnum<unsigned long>::LoadFromFile((TracksEnum<unsigned long> *)i);
    v1 = `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard;
    if ( (`TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard & 1) == 0 )
    {
      `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard |= 1u;
      `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
      `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mNext = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
      atexit(TracksEnum_unsigned_long_::GetTracksEnumList_::_2_::_dynamic_atexit_destructor_for__m_TracksEnumList___0);
      v1 = `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard;
    }
  }
}

// File Line: 205
// RVA: 0x423BA0
void __fastcall TracksEnum<float>::LoadFromFile(TracksEnum<float> *this)
{
  TracksEnum<float> *v1; // rbp
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_m_enumLists; // r14
  SimpleXML::XMLDocument *v3; // rax
  SimpleXML::XMLDocument *v4; // rsi
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *v6; // rbp
  SimpleXML::XMLNode *v7; // rbx
  SimpleXML::XMLNode *v8; // rax
  SimpleXML::XMLNode *v9; // r12
  char *Name; // rax
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mNext; // rbp
  UFG::qArray<unsigned long,0> *v12; // r15
  UFG::qArray<unsigned long,0> *p_mData; // r14
  char *Attribute; // r13
  SimpleXML::XMLNode *Node; // rsi
  char *v16; // rdi
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rbx
  char *mNextAlloc; // r14
  UFG::allocator::free_link *v21; // rax
  char *v22; // rcx
  char v23; // al
  char *v24; // rcx
  char *v25; // rcx
  unsigned int v26; // r15d
  double v27; // xmm2_8
  double v28; // xmm0_8
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> **v29; // r10
  __int64 mNext_low; // rbp
  unsigned int v31; // esi
  unsigned int mNext_high; // ebx
  unsigned int v33; // ebx
  unsigned __int64 v34; // rax
  UFG::allocator::free_link *v35; // rax
  UFG::allocator::free_link *v36; // rdi
  __int64 j; // r9
  int v38; // r14d
  SimpleXML::XMLNode *v39; // r10
  __int64 mPrev_low; // rbp
  unsigned int v41; // esi
  unsigned int mPrev_high; // ebx
  unsigned int v43; // ebx
  unsigned __int64 v44; // rax
  UFG::allocator::free_link *v45; // rax
  UFG::allocator::free_link *v46; // rdi
  __int64 k; // r9
  __int64 mData_low; // rbp
  unsigned int v49; // edi
  unsigned int mData_high; // ebx
  unsigned int v51; // ebx
  unsigned __int64 v52; // rax
  UFG::allocator::free_link *v53; // rax
  UFG::allocator::free_link *v54; // rsi
  __int64 m; // r9
  __int64 v56; // rbp
  unsigned int v57; // edi
  unsigned int v58; // ebx
  unsigned int v59; // ebx
  unsigned __int64 v60; // rax
  UFG::allocator::free_link *v61; // rax
  UFG::allocator::free_link *v62; // rsi
  __int64 n; // r9
  __int64 v64; // rbx
  char *v65; // rdi
  UFG::allocator::free_link *v66; // rax
  signed __int64 v67; // rcx
  char v68; // al
  double v69; // xmm2_8
  double v70; // xmm0_8
  __int64 size; // rsi
  unsigned int v72; // ebx
  unsigned int capacity; // edx
  unsigned int v74; // edx
  unsigned int v75; // esi
  __int64 v76; // rdi
  unsigned int v77; // ebx
  unsigned int v78; // edx
  unsigned int v79; // edx
  __int64 v80; // rdi
  unsigned int v81; // ebx
  unsigned int v82; // edx
  unsigned int v83; // edx
  __int64 v84; // rbp
  unsigned int v85; // edi
  unsigned int v86; // ebx
  unsigned int v87; // ebx
  unsigned __int64 v88; // rax
  UFG::allocator::free_link *v89; // rax
  UFG::allocator::free_link *v90; // rsi
  unsigned int ii; // r9d
  __int64 v92; // rdi
  unsigned int v93; // ebx
  unsigned int v94; // edx
  unsigned int v95; // edx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *mNext; // rbx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *mPrev; // rcx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v98; // rax
  char *v99; // rax
  SimpleXML::XMLDocument *v100; // [rsp+20h] [rbp-A8h]
  SimpleXML::XMLNode *i; // [rsp+28h] [rbp-A0h]
  UFG::qArray<EnumList<float> *,0> *v102; // [rsp+30h] [rbp-98h]
  UFG::qString v103; // [rsp+40h] [rbp-88h] BYREF
  UFG::qSymbol result; // [rsp+D8h] [rbp+10h] BYREF
  SimpleXML::XMLNode *v106; // [rsp+E0h] [rbp+18h]
  SimpleXML::XMLNode *prev_node; // [rsp+E8h] [rbp+20h]

  v1 = this;
  if ( this->m_fileName )
  {
    p_m_enumLists = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_enumLists;
    v102 = &this->m_enumLists;
    if ( !this->m_enumLists.size )
    {
      UFG::qString::qString(&v103, &TracksEnum<float>::mDataPath);
      UFG::qString::operator+=(&v103, v1->m_fileName);
      v3 = SimpleXML::XMLDocument::Open(v103.mData, 1ui64, 0i64);
      v4 = v3;
      v100 = v3;
      if ( v3 )
      {
        ChildNode = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, 0i64);
        if ( ChildNode )
        {
          v6 = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, ChildNode);
          for ( i = v6; v6; i = v6 )
          {
            if ( (int)SimpleXML::XMLNode::GetChildCount(v6) > 0 )
            {
              v7 = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, v6);
              v106 = v7;
              v8 = (SimpleXML::XMLNode *)UFG::qMalloc(0x48ui64, "TRACKSENUMXML", 0i64);
              v9 = v8;
              prev_node = v8;
              if ( v8 )
              {
                LODWORD(v8->mPrev) = -1;
                v8->mData = 0i64;
                v8->mNext = 0i64;
                v8[1].mNext = 0i64;
                v8[1].mPrev = 0i64;
                v8[2].mPrev = 0i64;
                v8[1].mData = 0i64;
                v8[2].mData = 0i64;
                v8[2].mNext = 0i64;
              }
              else
              {
                v9 = 0i64;
              }
              Name = SimpleXML::XMLNode::GetName(v6);
              LODWORD(v9->mPrev) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, Name)->mUID;
              if ( v7 )
              {
                p_mNext = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v9->mNext;
                v12 = (UFG::qArray<unsigned long,0> *)&v9[1];
                p_mData = (UFG::qArray<unsigned long,0> *)&v9[1].mData;
                do
                {
                  Attribute = SimpleXML::XMLNode::GetAttribute(v7, "name");
                  Node = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, v7);
                  prev_node = Node;
                  if ( Node )
                  {
                    do
                    {
                      v16 = SimpleXML::XMLNode::GetAttribute(Node, "name");
                      if ( (`UFG::qStaticInitAllocator::Instance::`2::`local static guard & 1) == 0 )
                      {
                        `UFG::qStaticInitAllocator::Instance::`2::`local static guard |= 1u;
                        UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance::`2::instance);
                        atexit(`UFG::qStaticInitAllocator::Instance::`2::`dynamic atexit destructor for instance);
                      }
                      v17 = -1i64;
                      v18 = -1i64;
                      do
                        ++v18;
                      while ( v16[v18] );
                      do
                        ++v17;
                      while ( Attribute[v17] );
                      v19 = v18 + v17 + 2;
                      mNextAlloc = `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc;
                      if ( !`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks
                        || &`UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc[v19] > `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock )
                      {
                        v21 = UFG::qMalloc(0x1FF0ui64, "gStaticInitAllocator", 1ui64);
                        v21->mNext = (UFG::allocator::free_link *)`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks;
                        `UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks = (UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *)v21;
                        mNextAlloc = (char *)&v21[1];
                        `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock = (char *)&v21[1022];
                      }
                      `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc = &mNextAlloc[v19];
                      ++`UFG::qStaticInitAllocator::Instance::`2::instance.mTotalAlloc;
                      v22 = Attribute;
                      do
                      {
                        v23 = *v22;
                        v22[mNextAlloc - Attribute] = *v22;
                        ++v22;
                      }
                      while ( v23 );
                      v24 = mNextAlloc - 1;
                      do
                        ++v24;
                      while ( *v24 );
                      strcpy(v24, "_");
                      v25 = mNextAlloc - 1;
                      do
                        ++v25;
                      while ( *v25 );
                      strcpy(v25, v16);
                      v26 = SimpleXML::XMLNode::GetAttribute(Node, "id", 0);
                      HIDWORD(v27) = 0;
                      *(float *)&v27 = (float)(int)p_mNext->size;
                      v28 = SimpleXML::XMLNode::GetAttribute(v106, "id", v27);
                      v29 = &v9->mNext;
                      mNext_low = LODWORD(v9->mNext);
                      v31 = mNext_low + 1;
                      mNext_high = HIDWORD(v9->mNext);
                      if ( (int)mNext_low + 1 > mNext_high )
                      {
                        if ( mNext_high )
                          v33 = 2 * mNext_high;
                        else
                          v33 = 1;
                        for ( ; v33 < v31; v33 *= 2 )
                          ;
                        if ( v33 <= 2 )
                          v33 = 2;
                        if ( v33 - v31 > 0x10000 )
                          v33 = mNext_low + 65537;
                        if ( v33 != (_DWORD)mNext_low )
                        {
                          v34 = 8i64 * v33;
                          if ( !is_mul_ok(v33, 8ui64) )
                            v34 = -1i64;
                          v35 = UFG::qMalloc(v34, "qArray.Add", 0i64);
                          v36 = v35;
                          v29 = &v9->mNext;
                          if ( v9->mData )
                          {
                            for ( j = 0i64; (unsigned int)j < *(_DWORD *)v29; j = (unsigned int)(j + 1) )
                              v35[j] = (UFG::allocator::free_link)v9->mData[j].mNode._root;
                            operator delete[](v9->mData);
                            v29 = &v9->mNext;
                          }
                          v29[1] = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v36;
                          *((_DWORD *)v29 + 1) = v33;
                        }
                      }
                      *(_DWORD *)v29 = v31;
                      *((_QWORD *)&v29[1]->mPrev + mNext_low) = mNextAlloc;
                      v38 = UFG::qStringHash32(mNextAlloc, 0xFFFFFFFF);
                      v39 = v9 + 1;
                      mPrev_low = LODWORD(v9[1].mPrev);
                      v41 = mPrev_low + 1;
                      mPrev_high = HIDWORD(v9[1].mPrev);
                      if ( (int)mPrev_low + 1 > mPrev_high )
                      {
                        if ( mPrev_high )
                          v43 = 2 * mPrev_high;
                        else
                          v43 = 1;
                        for ( ; v43 < v41; v43 *= 2 )
                          ;
                        if ( v43 <= 4 )
                          v43 = 4;
                        if ( v43 - v41 > 0x10000 )
                          v43 = mPrev_low + 65537;
                        if ( v43 != (_DWORD)mPrev_low )
                        {
                          v44 = 4i64 * v43;
                          if ( !is_mul_ok(v43, 4ui64) )
                            v44 = -1i64;
                          v45 = UFG::qMalloc(v44, "qArray.Add", 0i64);
                          v46 = v45;
                          v39 = v9 + 1;
                          if ( v9[1].mNext )
                          {
                            for ( k = 0i64; (unsigned int)k < LODWORD(v39->mPrev); k = (unsigned int)(k + 1) )
                              *((_DWORD *)&v45->mNext + k) = *((_DWORD *)&v9[1].mNext->UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode>::mPrev
                                                             + k);
                            operator delete[](v9[1].mNext);
                            v39 = v9 + 1;
                          }
                          v39->mNext = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v46;
                          HIDWORD(v39->mPrev) = v43;
                        }
                      }
                      LODWORD(v39->mPrev) = v41;
                      *((_DWORD *)&v39->mNext->UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode>::mPrev + mPrev_low) = v38;
                      p_mData = (UFG::qArray<unsigned long,0> *)&v9[1].mData;
                      mData_low = LODWORD(v9[1].mData);
                      v49 = mData_low + 1;
                      mData_high = HIDWORD(v9[1].mData);
                      if ( (int)mData_low + 1 > mData_high )
                      {
                        if ( mData_high )
                          v51 = 2 * mData_high;
                        else
                          v51 = 1;
                        for ( ; v51 < v49; v51 *= 2 )
                          ;
                        if ( v51 <= 4 )
                          v51 = 4;
                        if ( v51 - v49 > 0x10000 )
                          v51 = mData_low + 65537;
                        if ( v51 != (_DWORD)mData_low )
                        {
                          v52 = 4i64 * v51;
                          if ( !is_mul_ok(v51, 4ui64) )
                            v52 = -1i64;
                          v53 = UFG::qMalloc(v52, "qArray.Add", 0i64);
                          v54 = v53;
                          if ( v9[2].mPrev )
                          {
                            for ( m = 0i64; (unsigned int)m < p_mData->size; m = (unsigned int)(m + 1) )
                              *((_DWORD *)&v53->mNext + m) = *((_DWORD *)&v9[2].mPrev->mPrev + m);
                            operator delete[](v9[2].mPrev);
                          }
                          v9[2].mPrev = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v54;
                          HIDWORD(v9[1].mData) = v51;
                        }
                      }
                      p_mData->size = v49;
                      *((_DWORD *)&v9[2].mPrev->mPrev + mData_low) = v26;
                      v56 = LODWORD(v9[2].mNext);
                      v57 = v56 + 1;
                      v58 = HIDWORD(v9[2].mNext);
                      if ( (int)v56 + 1 > v58 )
                      {
                        if ( v58 )
                          v59 = 2 * v58;
                        else
                          v59 = 1;
                        for ( ; v59 < v57; v59 *= 2 )
                          ;
                        if ( v59 <= 4 )
                          v59 = 4;
                        if ( v59 - v57 > 0x10000 )
                          v59 = v56 + 65537;
                        if ( v59 != (_DWORD)v56 )
                        {
                          v60 = 4i64 * v59;
                          if ( !is_mul_ok(v59, 4ui64) )
                            v60 = -1i64;
                          v61 = UFG::qMalloc(v60, "qArray.Add", 0i64);
                          v62 = v61;
                          if ( v9[2].mData )
                          {
                            for ( n = 0i64; (unsigned int)n < LODWORD(v9[2].mNext); n = (unsigned int)(n + 1) )
                              *((_DWORD *)&v61->mNext + n) = *((_DWORD *)&v9[2].mData->mNode._root + n);
                            operator delete[](v9[2].mData);
                          }
                          v9[2].mData = (SimpleXML::XMLNodeData *)v62;
                          HIDWORD(v9[2].mNext) = v59;
                        }
                      }
                      LODWORD(v9[2].mNext) = v57;
                      *((_DWORD *)&v9[2].mData->mNode._root + v56) = LODWORD(v28);
                      Node = SimpleXML::XMLDocument::GetNode(v100, 0i64, prev_node);
                      prev_node = Node;
                      p_mNext = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v9->mNext;
                    }
                    while ( Node );
                    v12 = (UFG::qArray<unsigned long,0> *)&v9[1];
                  }
                  else
                  {
                    if ( (`UFG::qStaticInitAllocator::Instance::`2::`local static guard & 1) == 0 )
                    {
                      `UFG::qStaticInitAllocator::Instance::`2::`local static guard |= 1u;
                      UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance::`2::instance);
                      atexit(`UFG::qStaticInitAllocator::Instance::`2::`dynamic atexit destructor for instance);
                    }
                    v64 = -1i64;
                    do
                      ++v64;
                    while ( Attribute[v64] );
                    v65 = `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc;
                    if ( !`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks
                      || &`UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc[v64 + 1] > `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock )
                    {
                      v66 = UFG::qMalloc(0x1FF0ui64, "gStaticInitAllocator", 1ui64);
                      v66->mNext = (UFG::allocator::free_link *)`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks;
                      `UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks = (UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *)v66;
                      v65 = (char *)&v66[1];
                      `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock = (char *)&v66[1022];
                    }
                    `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc = &v65[v64 + 1];
                    ++`UFG::qStaticInitAllocator::Instance::`2::instance.mTotalAlloc;
                    v67 = v65 - Attribute;
                    do
                    {
                      v68 = *Attribute;
                      Attribute[v67] = *Attribute;
                      ++Attribute;
                    }
                    while ( v68 );
                    HIDWORD(v69) = 0;
                    *(float *)&v69 = (float)(int)p_mNext->size;
                    v70 = SimpleXML::XMLNode::GetAttribute(v106, "id", v69);
                    size = p_mNext->size;
                    v72 = size + 1;
                    capacity = p_mNext->capacity;
                    if ( (int)size + 1 > capacity )
                    {
                      if ( capacity )
                        v74 = 2 * capacity;
                      else
                        v74 = 1;
                      for ( ; v74 < v72; v74 *= 2 )
                        ;
                      if ( v74 <= 2 )
                        v74 = 2;
                      if ( v74 - v72 > 0x10000 )
                        v74 = size + 65537;
                      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mNext, v74, "qArray.Add");
                    }
                    p_mNext->size = v72;
                    p_mNext->p[size] = (UFG::qReflectInventoryBase *)v65;
                    v75 = UFG::qStringHash32(v65, 0xFFFFFFFF);
                    v76 = v12->size;
                    v77 = v76 + 1;
                    v78 = v12->capacity;
                    if ( (int)v76 + 1 > v78 )
                    {
                      if ( v78 )
                        v79 = 2 * v78;
                      else
                        v79 = 1;
                      for ( ; v79 < v77; v79 *= 2 )
                        ;
                      if ( v79 <= 4 )
                        v79 = 4;
                      if ( v79 - v77 > 0x10000 )
                        v79 = v76 + 65537;
                      UFG::qArray<long,0>::Reallocate(v12, v79, "qArray.Add");
                    }
                    v12->size = v77;
                    v12->p[v76] = v75;
                    v80 = p_mData->size;
                    v81 = v80 + 1;
                    v82 = p_mData->capacity;
                    if ( (int)v80 + 1 > v82 )
                    {
                      if ( v82 )
                        v83 = 2 * v82;
                      else
                        v83 = 1;
                      for ( ; v83 < v81; v83 *= 2 )
                        ;
                      if ( v83 <= 4 )
                        v83 = 4;
                      if ( v83 - v81 > 0x10000 )
                        v83 = v80 + 65537;
                      UFG::qArray<long,0>::Reallocate(p_mData, v83, "qArray.Add");
                    }
                    p_mData->size = v81;
                    p_mData->p[v80] = 0;
                    v84 = LODWORD(v9[2].mNext);
                    v85 = v84 + 1;
                    v86 = HIDWORD(v9[2].mNext);
                    if ( (int)v84 + 1 > v86 )
                    {
                      if ( v86 )
                        v87 = 2 * v86;
                      else
                        v87 = 1;
                      for ( ; v87 < v85; v87 *= 2 )
                        ;
                      if ( v87 <= 4 )
                        v87 = 4;
                      if ( v87 - v85 > 0x10000 )
                        v87 = v84 + 65537;
                      if ( v87 != (_DWORD)v84 )
                      {
                        v88 = 4i64 * v87;
                        if ( !is_mul_ok(v87, 4ui64) )
                          v88 = -1i64;
                        v89 = UFG::qMalloc(v88, "qArray.Add", 0i64);
                        v90 = v89;
                        if ( v9[2].mData )
                        {
                          for ( ii = 0; ii < LODWORD(v9[2].mNext); ++ii )
                            *((_DWORD *)&v89->mNext + ii) = *((_DWORD *)&v9[2].mData->mNode._root + ii);
                          operator delete[](v9[2].mData);
                        }
                        v9[2].mData = (SimpleXML::XMLNodeData *)v90;
                        HIDWORD(v9[2].mNext) = v87;
                      }
                    }
                    LODWORD(v9[2].mNext) = v85;
                    *((_DWORD *)&v9[2].mData->mNode._root + v84) = LODWORD(v70);
                  }
                  v4 = v100;
                  v7 = SimpleXML::XMLDocument::GetNode(v100, 0i64, v106);
                  v106 = v7;
                  p_mNext = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v9->mNext;
                }
                while ( v7 );
                v6 = i;
                p_m_enumLists = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)v102;
              }
              v92 = p_m_enumLists->size;
              v93 = v92 + 1;
              v94 = p_m_enumLists->capacity;
              if ( (int)v92 + 1 > v94 )
              {
                if ( v94 )
                  v95 = 2 * v94;
                else
                  v95 = 1;
                for ( ; v95 < v93; v95 *= 2 )
                  ;
                if ( v95 <= 2 )
                  v95 = 2;
                if ( v95 - v93 > 0x10000 )
                  v95 = v92 + 65537;
                UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_m_enumLists, v95, "qArray.Add");
              }
              p_m_enumLists->size = v93;
              p_m_enumLists->p[v92] = (UFG::qReflectInventoryBase *)v9;
            }
            v6 = SimpleXML::XMLDocument::GetNode(v4, 0i64, v6);
          }
          v1 = this;
        }
        SimpleXML::XMLDocument::~XMLDocument(v4);
        operator delete[](v4);
      }
      while ( (UFG::qList<TracksEnumBinding<float>,TracksEnumBinding<float>,1,0> *)v1->m_UnresolvedTracksEnumBindingList.mNode.mNext != &v1->m_UnresolvedTracksEnumBindingList )
      {
        mNext = v1->m_UnresolvedTracksEnumBindingList.mNode.mNext;
        mPrev = mNext->mPrev;
        v98 = mNext->mNext;
        mPrev->mNext = v98;
        v98->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        if ( !TracksEnum<float>::ResolveBinding(v1, (TracksEnumBinding<float> *)mNext) )
        {
          v99 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&mNext[1]);
          UFG::qPrintf("TracksEnum<T>::LoadFromFile(): Couldnt resolve enum %s\n", v99);
        }
      }
      UFG::qString::~qString(&v103);
    }
  }
}TracksEnumBindingList.mNode.mNext;
        mPrev = mNext->mPrev;
        v98 = mNext->mNext;
        mPrev->mNext = v98;
        v98->mPrev = mPrev;
        mNext->mPrev = mNex

// File Line: 319
// RVA: 0x426140
__int64 __fastcall TracksEnum<float>::ResolveBinding(
        TracksEnum<float> *this,
        TracksEnumBinding<float> *pTrackEnumBinding)
{
  __int64 size; // rbp
  unsigned int mUID; // ebx
  unsigned __int8 v4; // di
  signed int v5; // r11d
  __int64 v6; // r9
  signed int v9; // eax
  __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rdx
  EnumList<float> *v13; // rsi
  unsigned int *p; // rax
  float v15; // ecx
  char *v16; // rax

  size = this->m_enumLists.size;
  mUID = pTrackEnumBinding->m_EnumSymbol.mUID;
  v4 = 0;
  v5 = 0;
  v6 = 0i64;
  if ( this->m_enumLists.size )
  {
    while ( !v4 )
    {
      if ( (signed int)this->m_enumLists.size < v5 )
        v9 = 0;
      else
        v9 = this->m_enumLists.p[v6]->m_enumName.size;
      v10 = 0i64;
      v11 = 0i64;
      v12 = v9;
      if ( v9 > 0 )
      {
        v13 = this->m_enumLists.p[v6];
        p = v13->m_enumNameHash.p;
        while ( mUID != *p )
        {
          ++v11;
          v10 = (unsigned int)(v10 + 1);
          ++p;
          if ( v11 >= v12 )
            goto LABEL_12;
        }
        v4 = 1;
        v15 = v13->m_enumValue.p[v10];
        pTrackEnumBinding->m_uEnumIndex = v10;
        pTrackEnumBinding->m_EnumValue = v15;
        pTrackEnumBinding->m_uEnumUID = this->m_enumLists.p[v6]->m_uid.p[v10];
      }
LABEL_12:
      ++v6;
      ++v5;
      if ( v6 >= size )
      {
        if ( v4 )
          return v4;
        goto LABEL_14;
      }
    }
  }
  else
  {
LABEL_14:
    if ( mUID != -1 )
    {
      v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pTrackEnumBinding->m_EnumSymbol);
      UFG::qPrintf(
        "WARNING: TracksEnum<T>::ResolveBinding: Could Not Resolve Binding for Enum %s UID: 0x%X\n",
        v16,
        mUID);
    }
  }
  return v4;
}

// File Line: 362
// RVA: 0x272D30
void __fastcall TracksEnum<unsigned long>::Unload(TracksEnum<float> *this)
{
  signed int i; // esi
  EnumList<float> *v3; // rbx
  signed int v4; // edi
  int v5; // eax
  float *p; // rcx
  unsigned int *v7; // rcx
  unsigned int *v8; // rcx
  char **v9; // rcx

  for ( i = 0; i < (signed int)this->m_enumLists.size; ++i )
  {
    v3 = this->m_enumLists.p[i];
    v4 = 0;
    if ( (int)v3->m_enumName.size > 0 )
    {
      v5 = `UFG::qStaticInitAllocator::Instance::`2::`local static guard;
      do
      {
        if ( (v5 & 1) == 0 )
        {
          `UFG::qStaticInitAllocator::Instance::`2::`local static guard = v5 | 1;
          UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance::`2::instance);
          atexit(`UFG::qStaticInitAllocator::Instance::`2::`dynamic atexit destructor for instance);
          v5 = `UFG::qStaticInitAllocator::Instance::`2::`local static guard;
        }
        ++v4;
      }
      while ( v4 < (signed int)v3->m_enumName.size );
    }
    p = v3->m_enumValue.p;
    if ( p )
      operator delete[](p);
    v3->m_enumValue.p = 0i64;
    *(_QWORD *)&v3->m_enumValue.size = 0i64;
    v7 = v3->m_uid.p;
    if ( v7 )
      operator delete[](v7);
    v3->m_uid.p = 0i64;
    *(_QWORD *)&v3->m_uid.size = 0i64;
    v8 = v3->m_enumNameHash.p;
    if ( v8 )
      operator delete[](v8);
    v3->m_enumNameHash.p = 0i64;
    *(_QWORD *)&v3->m_enumNameHash.size = 0i64;
    v9 = v3->m_enumName.p;
    if ( v9 )
      operator delete[](v9);
    v3->m_enumName.p = 0i64;
    *(_QWORD *)&v3->m_enumName.size = 0i64;
    operator delete[](v3);
  }
  if ( this->m_enumLists.size )
    this->m_enumLists.size = 0;
}

// File Line: 399
// RVA: 0x26E5F0
__int64 __fastcall TracksEnum<unsigned long>::GetEnumFromSymbol(TracksEnum<unsigned long> *this, UFG::qSymbol *symbol)
{
  UFG::qList<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long>,1,0> *p_m_UnresolvedTracksEnumBindingList; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  unsigned int m_EnumValue; // r8d
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)symbol->mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( this->m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(this, &pTrackEnumBinding);
  }
  else
  {
    p_m_UnresolvedTracksEnumBindingList = &this->m_UnresolvedTracksEnumBindingList;
    mPrev = p_m_UnresolvedTracksEnumBindingList->mNode.mPrev;
    mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &p_m_UnresolvedTracksEnumBindingList->mNode;
    p_m_UnresolvedTracksEnumBindingList->mNode.mPrev = &pTrackEnumBinding;
  }
  m_EnumValue = pTrackEnumBinding.m_EnumValue;
  v5 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v5;
  return m_EnumValue;
}

