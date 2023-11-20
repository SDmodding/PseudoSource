// File Line: 41
// RVA: 0x2694F0
void __fastcall TracksEnumBinding<unsigned long>::~TracksEnumBinding<unsigned long>(TracksEnumBinding<unsigned long> *this)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v2; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v3; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v4; // rax

  v1 = this->mPrev;
  v2 = this->mNext;
  v1->mNext = v2;
  v2->mPrev = v1;
  this->mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&this->mPrev;
  this->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&this->mPrev;
  v3 = this->mPrev;
  v4 = this->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  this->mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&this->mPrev;
  this->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&this->mPrev;
}

// File Line: 92
// RVA: 0x2693D0
void __fastcall TracksEnum<unsigned long>::~TracksEnum<unsigned long>(TracksEnum<unsigned long> *this)
{
  UFG::qList<TracksEnumBinding<float>,TracksEnumBinding<float>,1,0> *v1; // rdi
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v2; // rcx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v3; // rax
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v4; // rcx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > **v5; // rdx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v7; // rax

  v1 = (UFG::qList<TracksEnumBinding<float>,TracksEnumBinding<float>,1,0> *)this;
  this->vfptr = (TracksEnum<unsigned long>Vtbl *)&TracksEnum<unsigned long>::`vftable;
  TracksEnum<unsigned long>::Unload((TracksEnum<float> *)this);
  UFG::qList<TracksEnumBinding<float>,TracksEnumBinding<float>,1,0>::DeleteNodes(v1 + 3);
  v2 = v1[3].mNode.mPrev;
  v3 = v1[3].mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1[3].mNode.mPrev = &v1[3].mNode;
  v1[3].mNode.mNext = &v1[3].mNode;
  v4 = v1[2].mNode.mPrev;
  if ( v4 )
    operator delete[](v4);
  v1[2].mNode.mPrev = 0i64;
  v1[1].mNode.mNext = 0i64;
  v5 = &v1->mNode.mNext;
  v6 = v1->mNode.mNext;
  v7 = v1[1].mNode.mPrev;
  v6->mNext = v7;
  v7->mPrev = v6;
  *v5 = (UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *)v5;
  v5[1] = (UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *)v5;
}

// File Line: 154
// RVA: 0x268640
void __fastcall TracksEnum<float>::TracksEnum<float>(TracksEnum<float> *this, const char *pFileName)
{
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v3; // rax
  UFG::qList<TracksEnumBinding<float>,TracksEnumBinding<float>,1,0> *v4; // [rsp+48h] [rbp+10h]

  v2 = (UFG::qNode<UFG::qString,UFG::qString> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (TracksEnum<float>Vtbl *)&TracksEnum<float>::`vftable;
  this->m_enumLists.p = 0i64;
  *(_QWORD *)&this->m_enumLists.size = 0i64;
  this->m_fileName = pFileName;
  v4 = &this->m_UnresolvedTracksEnumBindingList;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  if ( !(`TracksEnum<float>::GetTracksEnumList::`2::`local static guard & 1) )
  {
    `TracksEnum<float>::GetTracksEnumList::`2::`local static guard |= 1u;
    `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = &`TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList;
    `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mNext = &`TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList;
    atexit(TracksEnum_float_::GetTracksEnumList_::_2_::_dynamic_atexit_destructor_for__m_TracksEnumList__);
  }
  v3 = `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mPrev;
  `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mPrev->mNext = v2;
  v2->mPrev = v3;
  v2->mNext = &`TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList;
  `TracksEnum<float>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = v2;
}

// File Line: 162
// RVA: 0x267F60
void __fastcall TracksEnum<unsigned long>::TracksEnum<unsigned long>(TracksEnum<unsigned long> *this, const char **pArray, const int arraySize, const unsigned int *pIds)
{
  signed __int64 v4; // rbx
  TracksEnum<unsigned long> *v5; // rbp
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rdi
  unsigned int v7; // er15
  UFG::qList<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long>,1,0> *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  unsigned int *v12; // r13
  signed __int64 v13; // rsi
  unsigned int v14; // er12
  unsigned int v15; // er14
  __int64 v16; // rbp
  unsigned int v17; // edi
  unsigned int v18; // ebx
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rsi
  unsigned int i; // er9
  signed __int64 v24; // rax
  signed __int64 v25; // rbx
  char *v26; // r14
  UFG::allocator::free_link *v27; // rax
  const char *v28; // rcx
  char *v29; // rdx
  char v30; // al
  unsigned int *v31; // r10
  __int64 v32; // rbp
  unsigned int v33; // edi
  unsigned int v34; // ebx
  unsigned int v35; // ebx
  unsigned __int64 v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::allocator::free_link *v38; // rsi
  unsigned int j; // er9
  unsigned int *v40; // r10
  __int64 v41; // rbp
  unsigned int v42; // edi
  unsigned int v43; // ebx
  unsigned int v44; // ebx
  unsigned __int64 v45; // rax
  UFG::allocator::free_link *v46; // rax
  UFG::allocator::free_link *v47; // rsi
  unsigned int k; // er9
  _DWORD *v49; // rbx
  __int64 v50; // rbp
  unsigned int v51; // edi
  unsigned int v52; // ebx
  unsigned int v53; // ebx
  unsigned __int64 v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::allocator::free_link *v56; // rsi
  unsigned int l; // er9
  __int64 v58; // rsi
  unsigned int v59; // ebx
  unsigned int v60; // eax
  unsigned __int64 v61; // rax
  UFG::allocator::free_link *v62; // rax
  EnumList<unsigned long> **v63; // rdi
  UFG::allocator::free_link *v64; // [rsp+20h] [rbp-68h]
  UFG::allocator::free_link *v65; // [rsp+28h] [rbp-60h]
  signed __int64 v66; // [rsp+30h] [rbp-58h]
  EnumList<unsigned long> *v67; // [rsp+38h] [rbp-50h]
  signed __int64 v68; // [rsp+40h] [rbp-48h]
  TracksEnum<unsigned long> *v69; // [rsp+90h] [rbp+8h]
  const char **v70; // [rsp+98h] [rbp+10h]
  const unsigned int *v71; // [rsp+A8h] [rbp+20h]

  v71 = pIds;
  v70 = pArray;
  v69 = this;
  v4 = arraySize;
  v5 = this;
  v6 = (UFG::qNode<UFG::qString,UFG::qString> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  this->vfptr = (TracksEnum<unsigned long>Vtbl *)&TracksEnum<unsigned long>::`vftable;
  v7 = 0;
  this->m_enumLists.p = 0i64;
  *(_QWORD *)&this->m_enumLists.size = 0i64;
  this->m_fileName = 0i64;
  v8 = &this->m_UnresolvedTracksEnumBindingList;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  if ( !(`TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard & 1) )
  {
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard |= 1u;
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
    `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mNext = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
    atexit(TracksEnum_unsigned_long_::GetTracksEnumList_::_2_::_dynamic_atexit_destructor_for__m_TracksEnumList__);
  }
  v9 = `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev;
  `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev->mNext = v6;
  v6->mPrev = v9;
  v6->mNext = &`TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList;
  `TracksEnum<unsigned long>::GetTracksEnumList::`2::m_TracksEnumList.mPrev = v6;
  v10 = UFG::qMalloc(0x48ui64, "TRACKSENUM", 0i64);
  v11 = v10;
  v67 = (EnumList<unsigned long> *)v10;
  if ( v10 )
  {
    LODWORD(v10->mNext) = -1;
    v10[2].mNext = 0i64;
    v10[1].mNext = 0i64;
    v10[4].mNext = 0i64;
    v10[3].mNext = 0i64;
    v10[6].mNext = 0i64;
    v10[5].mNext = 0i64;
    v10[8].mNext = 0i64;
    v10[7].mNext = 0i64;
  }
  else
  {
    v11 = 0i64;
    v67 = 0i64;
  }
  v64 = v11 + 1;
  if ( (unsigned int)v4 > HIDWORD(v11[1].mNext) )
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v11[1],
      v4,
      "qArray.Reserve.TracksEnum");
  v65 = v11 + 3;
  if ( (unsigned int)v4 > HIDWORD(v11[3].mNext) )
    UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v11[3], v4, "qArray.Reserve.TracksEnum");
  v12 = (unsigned int *)&v11[7];
  if ( (unsigned int)v4 > HIDWORD(v11[7].mNext) )
    UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v11[7], v4, "qArray.Reserve.TracksEnum");
  if ( (unsigned int)v4 > HIDWORD(v11[5].mNext) )
    UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v11[5], v4, "qArray.Reserve.TracksEnum");
  v13 = 0i64;
  v66 = 0i64;
  v68 = v4;
  v14 = 1;
  if ( (signed int)v4 > 0 )
  {
    do
    {
      if ( v71 )
        v15 = v71[v13];
      else
        v15 = *v12;
      v16 = *v12;
      v17 = v16 + 1;
      v18 = v12[1];
      if ( (signed int)v16 + 1 > v18 )
      {
        if ( v18 )
          v19 = 2 * v18;
        else
          v19 = 1;
        for ( ; v19 < v17; v19 *= 2 )
          ;
        if ( v19 <= 4 )
          v19 = 4;
        if ( v19 - v17 > 0x10000 )
          v19 = v16 + 65537;
        if ( v19 != (_DWORD)v16 )
        {
          v20 = 4i64 * v19;
          if ( !is_mul_ok(v19, 4ui64) )
            v20 = -1i64;
          v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
          v22 = v21;
          if ( *((_QWORD *)v12 + 1) )
          {
            for ( i = 0; i < *v12; ++i )
              *((_DWORD *)&v21->mNext + i) = *(_DWORD *)(4i64 * i + *((_QWORD *)v12 + 1));
            operator delete[](*((void **)v12 + 1));
          }
          *((_QWORD *)v12 + 1) = v22;
          v12[1] = v19;
          v13 = v66;
        }
      }
      *v12 = v17;
      *(_DWORD *)(*((_QWORD *)v12 + 1) + 4 * v16) = v15;
      if ( !(`UFG::qStaticInitAllocator::Instance::`2::`local static guard & 1) )
      {
        `UFG::qStaticInitAllocator::Instance::`2::`local static guard |= 1u;
        UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance::`2::instance);
        atexit(`UFG::qStaticInitAllocator::Instance::`2::`dynamic atexit destructor for instance);
      }
      v24 = -1i64;
      do
        ++v24;
      while ( v70[v13][v24] );
      v25 = v24 + 1;
      v26 = `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc;
      if ( !`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks
        || &`UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc[v25] > `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock )
      {
        v27 = UFG::qMalloc(0x1FF0ui64, "gStaticInitAllocator", 1ui64);
        v27->mNext = (UFG::allocator::free_link *)`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks;
        `UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks = (UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *)v27;
        v26 = (char *)&v27[1];
        `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock = (char *)&v27[1022];
      }
      `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc = &v26[v25];
      ++`UFG::qStaticInitAllocator::Instance::`2::instance.mTotalAlloc;
      v28 = v70[v13];
      v29 = v26;
      do
      {
        v30 = *v28;
        *v29++ = *v28++;
      }
      while ( v30 );
      v31 = (unsigned int *)v64;
      v32 = LODWORD(v64->mNext);
      v33 = v32 + 1;
      v34 = HIDWORD(v64->mNext);
      if ( (signed int)v32 + 1 > v34 )
      {
        if ( v34 )
          v35 = 2 * v34;
        else
          v35 = 1;
        for ( ; v35 < v33; v35 *= 2 )
          ;
        if ( v35 <= 2 )
          v35 = 2;
        if ( v35 - v33 > 0x10000 )
          v35 = v32 + 65537;
        if ( v35 != (_DWORD)v32 )
        {
          v36 = 8i64 * v35;
          if ( !is_mul_ok(v35, 8ui64) )
            v36 = -1i64;
          v37 = UFG::qMalloc(v36, "qArray.Add", 0i64);
          v38 = v37;
          v31 = (unsigned int *)v64;
          if ( v64[1].mNext )
          {
            for ( j = 0; j < LODWORD(v64->mNext); ++j )
              v37[j] = v64[1].mNext[j];
            operator delete[](v64[1].mNext);
            v31 = (unsigned int *)v64;
          }
          *((_QWORD *)v31 + 1) = v38;
          v31[1] = v35;
        }
      }
      *v31 = v33;
      *(_QWORD *)(*((_QWORD *)v31 + 1) + 8 * v32) = v26;
      v40 = (unsigned int *)v65;
      v41 = LODWORD(v65->mNext);
      v42 = v41 + 1;
      v43 = HIDWORD(v65->mNext);
      if ( (signed int)v41 + 1 > v43 )
      {
        if ( v43 )
          v44 = 2 * v43;
        else
          v44 = 1;
        for ( ; v44 < v42; v44 *= 2 )
          ;
        if ( v44 <= 4 )
          v44 = 4;
        if ( v44 - v42 > 0x10000 )
          v44 = v41 + 65537;
        if ( v44 != (_DWORD)v41 )
        {
          v45 = 4i64 * v44;
          if ( !is_mul_ok(v44, 4ui64) )
            v45 = -1i64;
          v46 = UFG::qMalloc(v45, "qArray.Add", 0i64);
          v47 = v46;
          v40 = (unsigned int *)v65;
          if ( v65[1].mNext )
          {
            for ( k = 0; k < LODWORD(v65->mNext); ++k )
              *((_DWORD *)&v46->mNext + k) = *((_DWORD *)&v65[1].mNext->mNext + k);
            operator delete[](v65[1].mNext);
            v40 = (unsigned int *)v65;
          }
          *((_QWORD *)v40 + 1) = v47;
          v40[1] = v44;
        }
      }
      *v40 = v42;
      v49 = (_DWORD *)(*((_QWORD *)v40 + 1) + 4 * v41);
      *v49 = UFG::qStringHash32(v26, 0xFFFFFFFF);
      v50 = v67->m_uid.size;
      v51 = v50 + 1;
      v52 = v67->m_uid.capacity;
      if ( (signed int)v50 + 1 > v52 )
      {
        if ( v52 )
          v53 = 2 * v52;
        else
          v53 = 1;
        for ( ; v53 < v51; v53 *= 2 )
          ;
        if ( v53 <= 4 )
          v53 = 4;
        if ( v53 - v51 > 0x10000 )
          v53 = v50 + 65537;
        if ( v53 != (_DWORD)v50 )
        {
          v54 = 4i64 * v53;
          if ( !is_mul_ok(v53, 4ui64) )
            v54 = -1i64;
          v55 = UFG::qMalloc(v54, "qArray.Add", 0i64);
          v56 = v55;
          if ( v67->m_uid.p )
          {
            for ( l = 0; l < v67->m_uid.size; ++l )
              *((_DWORD *)&v55->mNext + l) = v67->m_uid.p[l];
            operator delete[](v67->m_uid.p);
          }
          v67->m_uid.p = (unsigned int *)v56;
          v67->m_uid.capacity = v53;
        }
      }
      v67->m_uid.size = v51;
      v67->m_uid.p[v50] = 0;
      v13 = v66 + 1;
      v66 = v13;
    }
    while ( v13 < v68 );
    v5 = v69;
  }
  v58 = v5->m_enumLists.size;
  v59 = v58 + 1;
  v60 = v5->m_enumLists.capacity;
  if ( (signed int)v58 + 1 > v60 )
  {
    if ( v60 )
      v14 = 2 * v60;
    for ( ; v14 < v59; v14 *= 2 )
      ;
    if ( v14 <= 2 )
      v14 = 2;
    if ( v14 - v59 > 0x10000 )
      v14 = v58 + 65537;
    if ( v14 != (_DWORD)v58 )
    {
      v61 = 8i64 * v14;
      if ( !is_mul_ok(v14, 8ui64) )
        v61 = -1i64;
      v62 = UFG::qMalloc(v61, "qArray.Add", 0i64);
      v63 = (EnumList<unsigned long> **)v62;
      if ( v5->m_enumLists.p )
      {
        if ( v5->m_enumLists.size )
        {
          do
          {
            v62[v7] = (UFG::allocator::free_link)v5->m_enumLists.p[v7];
            ++v7;
          }
          while ( v7 < v5->m_enumLists.size );
        }
        operator delete[](v5->m_enumLists.p);
      }
      v5->m_enumLists.p = v63;
      v5->m_enumLists.capacity = v14;
    }
  }
  v5->m_enumLists.size = v59;
  v5->m_enumLists.p[v58] = v67;
}         v62[v7] = (UFG::allocator::free_link)v5->m_enumLists.p[v7];
            ++v7;
          }
          while ( v7 < v5->m_enumLists.size );
        }
        operator delete[](v5->m_enumLists.p);
      }
      v5->m_enumLists.p = v63;
      v5->m_enumLists.capacity = v14;
    }
  }
  v5->m_enumLists

// File Line: 187
// RVA: 0x422E20
void __fastcall TracksEnum<unsigned long>::Initialize(const char *dataPath)
{
  int v1; // ecx
  UFG::qNode<UFG::qString,UFG::qString> *i; // rbx

  UFG::qString::Set(&TracksEnum<unsigned long>::mDataPath, dataPath);
  v1 = `TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard;
  if ( !(`TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard & 1) )
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
    if ( !(v1 & 1) )
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
    if ( !(`TracksEnum<unsigned long>::GetTracksEnumList::`2::`local static guard & 1) )
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
void __usercall TracksEnum<float>::LoadFromFile(TracksEnum<float> *this@<rcx>, int a2@<xmm0>)
{
  TracksEnum<float> *v2; // rbp
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v3; // r14
  SimpleXML::XMLDocument *v4; // rax
  SimpleXML::XMLDocument *v5; // rsi
  SimpleXML::XMLNode *v6; // rax
  SimpleXML::XMLNode *v7; // rbp
  SimpleXML::XMLNode *v8; // rax
  SimpleXML::XMLNode *v9; // rbx
  SimpleXML::XMLNode *v10; // rax
  SimpleXML::XMLNode *v11; // r12
  char *v12; // rax
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v13; // rbp
  UFG::qArray<unsigned long,0> *v14; // r15
  UFG::qArray<unsigned long,0> *v15; // r14
  char *v16; // r13
  SimpleXML::XMLNode *v17; // rsi
  char *v18; // rdi
  signed __int64 v19; // rax
  signed __int64 v20; // rcx
  signed __int64 v21; // rbx
  char *v22; // r14
  UFG::allocator::free_link *v23; // rax
  char *v24; // rcx
  char v25; // al
  char *v26; // rcx
  char *v27; // rcx
  unsigned int v28; // er15
  signed __int64 v29; // r10
  __int64 v30; // rbp
  unsigned int v31; // esi
  unsigned int v32; // ebx
  unsigned int v33; // ebx
  unsigned __int64 v34; // rax
  UFG::allocator::free_link *v35; // rax
  UFG::allocator::free_link *v36; // rdi
  __int64 v37; // r9
  int v38; // er14
  signed __int64 v39; // r10
  __int64 v40; // rbp
  unsigned int v41; // esi
  unsigned int v42; // ebx
  unsigned int v43; // ebx
  unsigned __int64 v44; // rax
  UFG::allocator::free_link *v45; // rax
  UFG::allocator::free_link *v46; // rdi
  __int64 v47; // r9
  __int64 v48; // rbp
  unsigned int v49; // edi
  unsigned int v50; // ebx
  unsigned int v51; // ebx
  unsigned __int64 v52; // rax
  UFG::allocator::free_link *v53; // rax
  UFG::allocator::free_link *v54; // rsi
  __int64 v55; // r9
  __int64 v56; // rbp
  unsigned int v57; // edi
  unsigned int v58; // ebx
  unsigned int v59; // ebx
  unsigned __int64 v60; // rax
  UFG::allocator::free_link *v61; // rax
  UFG::allocator::free_link *v62; // rsi
  __int64 v63; // r9
  signed __int64 v64; // rbx
  char *v65; // rdi
  UFG::allocator::free_link *v66; // rax
  signed __int64 v67; // rcx
  char v68; // al
  __int64 v69; // rsi
  unsigned int v70; // ebx
  unsigned int v71; // edx
  unsigned int v72; // edx
  unsigned int v73; // esi
  __int64 v74; // rdi
  unsigned int v75; // ebx
  unsigned int v76; // edx
  unsigned int v77; // edx
  __int64 v78; // rdi
  unsigned int v79; // ebx
  unsigned int v80; // edx
  unsigned int v81; // edx
  __int64 v82; // rbp
  unsigned int v83; // edi
  unsigned int v84; // ebx
  unsigned int v85; // ebx
  unsigned __int64 v86; // rax
  UFG::allocator::free_link *v87; // rax
  UFG::allocator::free_link *v88; // rsi
  unsigned int j; // er9
  __int64 v90; // rdi
  unsigned int v91; // ebx
  unsigned int v92; // edx
  unsigned int v93; // edx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v94; // rbx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v95; // rcx
  UFG::qNode<TracksEnumBinding<float>,TracksEnumBinding<float> > *v96; // rax
  char *v97; // rax
  SimpleXML::XMLDocument *v98; // [rsp+20h] [rbp-A8h]
  SimpleXML::XMLNode *i; // [rsp+28h] [rbp-A0h]
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v100; // [rsp+30h] [rbp-98h]
  UFG::qString v101; // [rsp+40h] [rbp-88h]
  TracksEnum<float> *v102; // [rsp+D0h] [rbp+8h]
  UFG::qSymbol result; // [rsp+D8h] [rbp+10h]
  SimpleXML::XMLNode *v104; // [rsp+E0h] [rbp+18h]
  SimpleXML::XMLNode *prev_node; // [rsp+E8h] [rbp+20h]

  v102 = this;
  v2 = this;
  if ( this->m_fileName )
  {
    v3 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_enumLists;
    v100 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_enumLists;
    if ( !this->m_enumLists.size )
    {
      UFG::qString::qString(&v101, &TracksEnum<float>::mDataPath);
      UFG::qString::operator+=(&v101, v2->m_fileName);
      v4 = SimpleXML::XMLDocument::Open(v101.mData, 1ui64, 0i64);
      v5 = v4;
      v98 = v4;
      if ( v4 )
      {
        v6 = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, 0i64);
        if ( v6 )
        {
          v7 = SimpleXML::XMLDocument::GetChildNode(v5, 0i64, v6);
          for ( i = v7; v7; i = v7 )
          {
            if ( (signed int)SimpleXML::XMLNode::GetChildCount(v7) > 0 )
            {
              v8 = SimpleXML::XMLDocument::GetChildNode(v5, 0i64, v7);
              v9 = v8;
              v104 = v8;
              v10 = (SimpleXML::XMLNode *)UFG::qMalloc(0x48ui64, "TRACKSENUMXML", 0i64);
              v11 = v10;
              prev_node = v10;
              if ( v10 )
              {
                LODWORD(v10->mPrev) = -1;
                v10->mData = 0i64;
                v10->mNext = 0i64;
                v10[1].mNext = 0i64;
                v10[1].mPrev = 0i64;
                v10[2].mPrev = 0i64;
                v10[1].mData = 0i64;
                v10[2].mData = 0i64;
                v10[2].mNext = 0i64;
              }
              else
              {
                v11 = 0i64;
              }
              v12 = SimpleXML::XMLNode::GetName(v7);
              LODWORD(v11->mPrev) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, v12)->mUID;
              if ( v9 )
              {
                v13 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v11->mNext;
                v14 = (UFG::qArray<unsigned long,0> *)&v11[1];
                v15 = (UFG::qArray<unsigned long,0> *)&v11[1].mData;
                do
                {
                  v16 = SimpleXML::XMLNode::GetAttribute(v9, "name");
                  v17 = SimpleXML::XMLDocument::GetChildNode(v5, 0i64, v9);
                  prev_node = v17;
                  if ( v17 )
                  {
                    do
                    {
                      v18 = SimpleXML::XMLNode::GetAttribute(v17, "name");
                      if ( !(`UFG::qStaticInitAllocator::Instance::`2::`local static guard & 1) )
                      {
                        `UFG::qStaticInitAllocator::Instance::`2::`local static guard |= 1u;
                        UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance::`2::instance);
                        atexit(`UFG::qStaticInitAllocator::Instance::`2::`dynamic atexit destructor for instance);
                      }
                      v19 = -1i64;
                      v20 = -1i64;
                      do
                        ++v20;
                      while ( v18[v20] );
                      do
                        ++v19;
                      while ( v16[v19] );
                      v21 = v20 + v19 + 2;
                      v22 = `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc;
                      if ( !`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks
                        || &`UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc[v21] > `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock )
                      {
                        v23 = UFG::qMalloc(0x1FF0ui64, "gStaticInitAllocator", 1ui64);
                        v23->mNext = (UFG::allocator::free_link *)`UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks;
                        `UFG::qStaticInitAllocator::Instance::`2::instance.mBlocks = (UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *)v23;
                        v22 = (char *)&v23[1];
                        `UFG::qStaticInitAllocator::Instance::`2::instance.mEndBlock = (char *)&v23[1022];
                      }
                      `UFG::qStaticInitAllocator::Instance::`2::instance.mNextAlloc = &v22[v21];
                      ++`UFG::qStaticInitAllocator::Instance::`2::instance.mTotalAlloc;
                      v24 = v16;
                      do
                      {
                        v25 = *v24;
                        v24[v22 - v16] = *v24;
                        ++v24;
                      }
                      while ( v25 );
                      v26 = v22 - 1;
                      do
                        ++v26;
                      while ( *v26 );
                      strcpy(v26, "_");
                      v27 = v22 - 1;
                      do
                        ++v27;
                      while ( *v27 );
                      strcpy(v27, v18);
                      v28 = SimpleXML::XMLNode::GetAttribute(v17, "id", 0);
                      SimpleXML::XMLNode::GetAttribute(v104, "id", (float)(signed int)v13->size);
                      v29 = (signed __int64)&v11->mNext;
                      v30 = LODWORD(v11->mNext);
                      v31 = v30 + 1;
                      v32 = HIDWORD(v11->mNext);
                      if ( (signed int)v30 + 1 > v32 )
                      {
                        if ( v32 )
                          v33 = 2 * v32;
                        else
                          v33 = 1;
                        for ( ; v33 < v31; v33 *= 2 )
                          ;
                        if ( v33 <= 2 )
                          v33 = 2;
                        if ( v33 - v31 > 0x10000 )
                          v33 = v30 + 65537;
                        if ( v33 != (_DWORD)v30 )
                        {
                          v34 = 8i64 * v33;
                          if ( !is_mul_ok(v33, 8ui64) )
                            v34 = -1i64;
                          v35 = UFG::qMalloc(v34, "qArray.Add", 0i64);
                          v36 = v35;
                          v29 = (signed __int64)&v11->mNext;
                          if ( v11->mData )
                          {
                            v37 = 0i64;
                            if ( *(_DWORD *)v29 )
                            {
                              do
                              {
                                v35[v37] = (UFG::allocator::free_link)v11->mData[v37].mNode._root;
                                v37 = (unsigned int)(v37 + 1);
                              }
                              while ( (unsigned int)v37 < *(_DWORD *)v29 );
                            }
                            operator delete[](v11->mData);
                            v29 = (signed __int64)&v11->mNext;
                          }
                          *(_QWORD *)(v29 + 8) = v36;
                          *(_DWORD *)(v29 + 4) = v33;
                        }
                      }
                      *(_DWORD *)v29 = v31;
                      *(_QWORD *)(*(_QWORD *)(v29 + 8) + 8 * v30) = v22;
                      v38 = UFG::qStringHash32(v22, 0xFFFFFFFF);
                      v39 = (signed __int64)&v11[1];
                      v40 = LODWORD(v11[1].mPrev);
                      v41 = v40 + 1;
                      v42 = HIDWORD(v11[1].mPrev);
                      if ( (signed int)v40 + 1 > v42 )
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
                          v39 = (signed __int64)&v11[1];
                          if ( v11[1].mNext )
                          {
                            v47 = 0i64;
                            if ( *(_DWORD *)v39 )
                            {
                              do
                              {
                                *((_DWORD *)&v45->mNext + v47) = *((_DWORD *)&v11[1].mNext->mPrev + v47);
                                v47 = (unsigned int)(v47 + 1);
                              }
                              while ( (unsigned int)v47 < *(_DWORD *)v39 );
                            }
                            operator delete[](v11[1].mNext);
                            v39 = (signed __int64)&v11[1];
                          }
                          *(_QWORD *)(v39 + 8) = v46;
                          *(_DWORD *)(v39 + 4) = v43;
                        }
                      }
                      *(_DWORD *)v39 = v41;
                      *(_DWORD *)(*(_QWORD *)(v39 + 8) + 4 * v40) = v38;
                      v15 = (UFG::qArray<unsigned long,0> *)&v11[1].mData;
                      v48 = LODWORD(v11[1].mData);
                      v49 = v48 + 1;
                      v50 = HIDWORD(v11[1].mData);
                      if ( (signed int)v48 + 1 > v50 )
                      {
                        if ( v50 )
                          v51 = 2 * v50;
                        else
                          v51 = 1;
                        for ( ; v51 < v49; v51 *= 2 )
                          ;
                        if ( v51 <= 4 )
                          v51 = 4;
                        if ( v51 - v49 > 0x10000 )
                          v51 = v48 + 65537;
                        if ( v51 != (_DWORD)v48 )
                        {
                          v52 = 4i64 * v51;
                          if ( !is_mul_ok(v51, 4ui64) )
                            v52 = -1i64;
                          v53 = UFG::qMalloc(v52, "qArray.Add", 0i64);
                          v54 = v53;
                          if ( v11[2].mPrev )
                          {
                            v55 = 0i64;
                            if ( v15->size )
                            {
                              do
                              {
                                *((_DWORD *)&v53->mNext + v55) = *((_DWORD *)&v11[2].mPrev->mPrev + v55);
                                v55 = (unsigned int)(v55 + 1);
                              }
                              while ( (unsigned int)v55 < v15->size );
                            }
                            operator delete[](v11[2].mPrev);
                          }
                          v11[2].mPrev = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v54;
                          HIDWORD(v11[1].mData) = v51;
                        }
                      }
                      v15->size = v49;
                      *((_DWORD *)&v11[2].mPrev->mPrev + v48) = v28;
                      v56 = LODWORD(v11[2].mNext);
                      v57 = v56 + 1;
                      v58 = HIDWORD(v11[2].mNext);
                      if ( (signed int)v56 + 1 > v58 )
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
                          if ( v11[2].mData )
                          {
                            v63 = 0i64;
                            if ( LODWORD(v11[2].mNext) )
                            {
                              do
                              {
                                *((_DWORD *)&v61->mNext + v63) = *((_DWORD *)&v11[2].mData->mNode._root + v63);
                                v63 = (unsigned int)(v63 + 1);
                              }
                              while ( (unsigned int)v63 < LODWORD(v11[2].mNext) );
                            }
                            operator delete[](v11[2].mData);
                          }
                          v11[2].mData = (SimpleXML::XMLNodeData *)v62;
                          HIDWORD(v11[2].mNext) = v59;
                        }
                      }
                      LODWORD(v11[2].mNext) = v57;
                      *((_DWORD *)&v11[2].mData->mNode._root + v56) = a2;
                      v17 = SimpleXML::XMLDocument::GetNode(v98, 0i64, prev_node);
                      prev_node = v17;
                      v13 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v11->mNext;
                    }
                    while ( v17 );
                    v14 = (UFG::qArray<unsigned long,0> *)&v11[1];
                  }
                  else
                  {
                    if ( !(`UFG::qStaticInitAllocator::Instance::`2::`local static guard & 1) )
                    {
                      `UFG::qStaticInitAllocator::Instance::`2::`local static guard |= 1u;
                      UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance::`2::instance);
                      atexit(`UFG::qStaticInitAllocator::Instance::`2::`dynamic atexit destructor for instance);
                    }
                    v64 = -1i64;
                    do
                      ++v64;
                    while ( v16[v64] );
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
                    v67 = v65 - v16;
                    do
                    {
                      v68 = *v16;
                      v16[v67] = *v16;
                      ++v16;
                    }
                    while ( v68 );
                    SimpleXML::XMLNode::GetAttribute(v104, "id", (float)(signed int)v13->size);
                    v69 = v13->size;
                    v70 = v69 + 1;
                    v71 = v13->capacity;
                    if ( (signed int)v69 + 1 > v71 )
                    {
                      if ( v71 )
                        v72 = 2 * v71;
                      else
                        v72 = 1;
                      for ( ; v72 < v70; v72 *= 2 )
                        ;
                      if ( v72 <= 2 )
                        v72 = 2;
                      if ( v72 - v70 > 0x10000 )
                        v72 = v69 + 65537;
                      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v13, v72, "qArray.Add");
                    }
                    v13->size = v70;
                    v13->p[v69] = (UFG::qReflectInventoryBase *)v65;
                    v73 = UFG::qStringHash32(v65, 0xFFFFFFFF);
                    v74 = v14->size;
                    v75 = v74 + 1;
                    v76 = v14->capacity;
                    if ( (signed int)v74 + 1 > v76 )
                    {
                      if ( v76 )
                        v77 = 2 * v76;
                      else
                        v77 = 1;
                      for ( ; v77 < v75; v77 *= 2 )
                        ;
                      if ( v77 <= 4 )
                        v77 = 4;
                      if ( v77 - v75 > 0x10000 )
                        v77 = v74 + 65537;
                      UFG::qArray<long,0>::Reallocate(v14, v77, "qArray.Add");
                    }
                    v14->size = v75;
                    v14->p[v74] = v73;
                    v78 = v15->size;
                    v79 = v78 + 1;
                    v80 = v15->capacity;
                    if ( (signed int)v78 + 1 > v80 )
                    {
                      if ( v80 )
                        v81 = 2 * v80;
                      else
                        v81 = 1;
                      for ( ; v81 < v79; v81 *= 2 )
                        ;
                      if ( v81 <= 4 )
                        v81 = 4;
                      if ( v81 - v79 > 0x10000 )
                        v81 = v78 + 65537;
                      UFG::qArray<long,0>::Reallocate(v15, v81, "qArray.Add");
                    }
                    v15->size = v79;
                    v15->p[v78] = 0;
                    v82 = LODWORD(v11[2].mNext);
                    v83 = v82 + 1;
                    v84 = HIDWORD(v11[2].mNext);
                    if ( (signed int)v82 + 1 > v84 )
                    {
                      if ( v84 )
                        v85 = 2 * v84;
                      else
                        v85 = 1;
                      for ( ; v85 < v83; v85 *= 2 )
                        ;
                      if ( v85 <= 4 )
                        v85 = 4;
                      if ( v85 - v83 > 0x10000 )
                        v85 = v82 + 65537;
                      if ( v85 != (_DWORD)v82 )
                      {
                        v86 = 4i64 * v85;
                        if ( !is_mul_ok(v85, 4ui64) )
                          v86 = -1i64;
                        v87 = UFG::qMalloc(v86, "qArray.Add", 0i64);
                        v88 = v87;
                        if ( v11[2].mData )
                        {
                          for ( j = 0; j < LODWORD(v11[2].mNext); ++j )
                            *((_DWORD *)&v87->mNext + j) = *((_DWORD *)&v11[2].mData->mNode._root + j);
                          operator delete[](v11[2].mData);
                        }
                        v11[2].mData = (SimpleXML::XMLNodeData *)v88;
                        HIDWORD(v11[2].mNext) = v85;
                      }
                    }
                    LODWORD(v11[2].mNext) = v83;
                    *((_DWORD *)&v11[2].mData->mNode._root + v82) = a2;
                  }
                  v5 = v98;
                  v9 = SimpleXML::XMLDocument::GetNode(v98, 0i64, v104);
                  v104 = v9;
                  v13 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v11->mNext;
                }
                while ( v9 );
                v7 = i;
                v3 = v100;
              }
              v90 = v3->size;
              v91 = v90 + 1;
              v92 = v3->capacity;
              if ( (signed int)v90 + 1 > v92 )
              {
                if ( v92 )
                  v93 = 2 * v92;
                else
                  v93 = 1;
                for ( ; v93 < v91; v93 *= 2 )
                  ;
                if ( v93 <= 2 )
                  v93 = 2;
                if ( v93 - v91 > 0x10000 )
                  v93 = v90 + 65537;
                UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v3, v93, "qArray.Add");
              }
              v3->size = v91;
              v3->p[v90] = (UFG::qReflectInventoryBase *)v11;
            }
            v7 = SimpleXML::XMLDocument::GetNode(v5, 0i64, v7);
          }
          v2 = v102;
        }
        SimpleXML::XMLDocument::~XMLDocument(v5);
        operator delete[](v5);
      }
      while ( (UFG::qList<TracksEnumBinding<float>,TracksEnumBinding<float>,1,0> *)v2->m_UnresolvedTracksEnumBindingList.mNode.mNext != &v2->m_UnresolvedTracksEnumBindingList )
      {
        v94 = v2->m_UnresolvedTracksEnumBindingList.mNode.mNext;
        v95 = v94->mPrev;
        v96 = v94->mNext;
        v95->mNext = v96;
        v96->mPrev = v95;
        v94->mPrev = v94;
        v94->mNext = v94;
        if ( !TracksEnum<float>::ResolveBinding(v2, (TracksEnumBinding<float> *)v94) )
        {
          v97 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v94[1]);
          UFG::qPrintf("TracksEnum<T>::LoadFromFile(): Couldnt resolve enum %s\n", v97);
        }
      }
      UFG::qString::~qString(&v101);
    }
  }
}

// File Line: 319
// RVA: 0x426140
__int64 __fastcall TracksEnum<float>::ResolveBinding(TracksEnum<float> *this, TracksEnumBinding<float> *pTrackEnumBinding)
{
  __int64 v2; // rbp
  unsigned int v3; // ebx
  unsigned __int8 v4; // di
  signed int v5; // er11
  __int64 v6; // r9
  UFG::qSymbolUC *v7; // r14
  TracksEnum<float> *v8; // r10
  signed int v9; // eax
  __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rdx
  EnumList<float> *v13; // rsi
  unsigned int *v14; // rax
  unsigned int v15; // ecx
  char *v16; // rax

  v2 = this->m_enumLists.size;
  v3 = pTrackEnumBinding->m_EnumSymbol.mUID;
  v4 = 0;
  v5 = 0;
  v6 = 0i64;
  v7 = (UFG::qSymbolUC *)pTrackEnumBinding;
  v8 = this;
  if ( v2 <= 0 )
  {
LABEL_14:
    if ( v3 != -1 )
    {
      v16 = UFG::qSymbol::as_cstr_dbg(v7 + 4);
      UFG::qPrintf(
        "WARNING: TracksEnum<T>::ResolveBinding: Could Not Resolve Binding for Enum %s UID: 0x%X\n",
        v16,
        v3);
    }
  }
  else
  {
    while ( !v4 )
    {
      if ( (signed int)v8->m_enumLists.size < v5 )
        v9 = 0;
      else
        v9 = v8->m_enumLists.p[v6]->m_enumName.size;
      v10 = 0i64;
      v11 = 0i64;
      v12 = v9;
      if ( v9 > 0 )
      {
        v13 = v8->m_enumLists.p[v6];
        v14 = v13->m_enumNameHash.p;
        while ( v3 != *v14 )
        {
          ++v11;
          v10 = (unsigned int)(v10 + 1);
          ++v14;
          if ( v11 >= v12 )
            goto LABEL_12;
        }
        v4 = 1;
        v15 = LODWORD(v13->m_enumValue.p[v10]);
        v7[6].mUID = v10;
        v7[5].mUID = v15;
        v7[7].mUID = v8->m_enumLists.p[v6]->m_uid.p[v10];
      }
LABEL_12:
      ++v6;
      ++v5;
      if ( v6 >= v2 )
      {
        if ( v4 )
          return v4;
        goto LABEL_14;
      }
    }
  }
  return v4;
}

// File Line: 362
// RVA: 0x272D30
void __fastcall TracksEnum<unsigned long>::Unload(TracksEnum<float> *this)
{
  TracksEnum<float> *v1; // rbp
  signed int i; // esi
  EnumList<float> *v3; // rbx
  signed int v4; // edi
  int v5; // eax
  float *v6; // rcx
  unsigned int *v7; // rcx
  unsigned int *v8; // rcx
  char **v9; // rcx

  v1 = this;
  for ( i = 0; i < (signed int)v1->m_enumLists.size; ++i )
  {
    v3 = v1->m_enumLists.p[i];
    v4 = 0;
    if ( (signed int)v3->m_enumName.size > 0 )
    {
      v5 = `UFG::qStaticInitAllocator::Instance::`2::`local static guard;
      do
      {
        if ( !(v5 & 1) )
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
    v6 = v3->m_enumValue.p;
    if ( v6 )
      operator delete[](v6);
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
  if ( v1->m_enumLists.size )
    v1->m_enumLists.size = 0;
}

// File Line: 399
// RVA: 0x26E5F0
__int64 __fastcall TracksEnum<unsigned long>::GetEnumFromSymbol(TracksEnum<unsigned long> *this, UFG::qSymbol *symbol)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v2; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v3; // rax
  unsigned int v4; // er8
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
    v2 = &this->m_UnresolvedTracksEnumBindingList.mNode;
    v3 = v2->mPrev;
    v3->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v3;
    pTrackEnumBinding.mNext = v2;
    v2->mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v4 = pTrackEnumBinding.m_EnumValue;
  v5 = pTrackEnumBinding.mPrev;
  v6 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v6->mPrev = v5;
  return v4;
}

