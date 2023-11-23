// File Line: 48
// RVA: 0x20DB60
UFG::AssetHive *__fastcall UFG::AssetHive::Instance()
{
  UFG::AssetHive *result; // rax

  if ( (_S1_26 & 1) != 0 )
    return &sInstance;
  _S1_26 |= 1u;
  sInstance.mFactories.mTree.mHead.mUID = 0i64;
  result = &sInstance;
  sInstance.mFactories.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sInstance;
  sInstance.mFactories.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sInstance;
  sInstance.mFactories.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sInstance;
  sInstance.mFactories.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sInstance;
  sInstance.mFactories.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sInstance;
  sInstance.mFactories.mTree.mCount = 0i64;
  sInstance.mAssets.mTree.mHead.mUID = 0i64;
  sInstance.mAssets.mTree.mHead.mParent = &sInstance.mAssets.mTree.mHead;
  sInstance.mAssets.mTree.mHead.mChildren[0] = &sInstance.mAssets.mTree.mHead;
  sInstance.mAssets.mTree.mHead.mChildren[1] = &sInstance.mAssets.mTree.mHead;
  sInstance.mAssets.mTree.mHead.mNeighbours[0] = &sInstance.mAssets.mTree.mHead;
  sInstance.mAssets.mTree.mHead.mNeighbours[1] = &sInstance.mAssets.mTree.mHead;
  sInstance.mAssets.mTree.mCount = 0i64;
  sInstance.mTags.mTree.mHead.mUID = 0i64;
  sInstance.mTags.mTree.mHead.mParent = &sInstance.mTags.mTree.mHead;
  sInstance.mTags.mTree.mHead.mChildren[0] = &sInstance.mTags.mTree.mHead;
  sInstance.mTags.mTree.mHead.mChildren[1] = &sInstance.mTags.mTree.mHead;
  sInstance.mTags.mTree.mHead.mNeighbours[0] = &sInstance.mTags.mTree.mHead;
  sInstance.mTags.mTree.mHead.mNeighbours[1] = &sInstance.mTags.mTree.mHead;
  sInstance.mTags.mTree.mCount = 0i64;
  return result;
}

// File Line: 54
// RVA: 0x204B90
void __fastcall UFG::AssetHive::AddAsset(UFG::AssetHive *this, UFG::HiveAsset *asset)
{
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rsi
  UFG::qList<UFG::qString,UFG::qString,1,0> *i; // r14
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rbx
  const char *v8; // rdi
  unsigned __int64 v9; // rax

  UFG::qTree64Base::Add(&this->mAssets.mTree, &asset->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode);
  mNext = asset->mTags.mNode.mNext;
  for ( i = &asset->mTags; mNext != (UFG::qNode<UFG::qString,UFG::qString> *)i; mNext = mNext->mNext )
  {
    v6 = UFG::qStringHash64((const char *)mNext[1].mNext, 0xFFFFFFFFFFFFFFFFui64);
    if ( !UFG::qTree64Base::Get(&this->mTags.mTree, v6) )
    {
      v7 = UFG::qMalloc(0x58ui64, UFG::gGlobalNewName, 0i64);
      if ( v7 )
      {
        v8 = (const char *)mNext[1].mNext;
        v9 = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
        v7[1].mNext = v7;
        v7[2].mNext = v7;
        v7[3].mNext = v7;
        v7[4].mNext = v7;
        v7[5].mNext = v7;
        v7->mNext = (UFG::allocator::free_link *)v9;
        UFG::qString::qString((UFG::qString *)&v7[6], v8);
      }
      else
      {
        v7 = 0i64;
      }
      UFG::qTree64Base::Add(&this->mTags.mTree, (UFG::qTree64Base::BaseNode *)v7);
    }
  }
}

// File Line: 78
// RVA: 0x20D0E0
void __fastcall UFG::AssetHive::IndexAssets(UFG::AssetHive *this)
{
  UFG::qTree64Base *Head; // rax
  UFG::qTree64Base *v3; // rsi
  UFG::qString *p_mCount; // rdi
  UFG::qString *mUID; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qTree64Base *v10; // rax
  UFG::qTree64Base *v11; // rbx
  UFG::qTree64Base *v12; // rax
  __int64 *v13; // rbx
  UFG::qTree64Base *Next; // rax

  while ( this->mAssets.mTree.mCount )
  {
    Head = UFG::qTree64Base::GetHead(&this->mAssets.mTree);
    v3 = Head;
    if ( Head )
      UFG::qTree64Base::Remove(&this->mAssets.mTree, Head);
    if ( v3 )
    {
      p_mCount = (UFG::qString *)&v3[4].mCount;
      mUID = (UFG::qString *)v3[5].mHead.mUID;
      if ( mUID != (UFG::qString *)&v3[4].mCount )
      {
        do
        {
          mPrev = mUID->mPrev;
          mNext = mUID->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          mUID->mPrev = mUID;
          mUID->mNext = mUID;
          UFG::qString::~qString(mUID);
          operator delete[](mUID);
          mUID = (UFG::qString *)v3[5].mHead.mUID;
        }
        while ( mUID != p_mCount );
      }
      v8 = p_mCount->mPrev;
      v9 = (UFG::qNode<UFG::qString,UFG::qString> *)v3[5].mHead.mUID;
      v8->mNext = v9;
      v9->mPrev = v8;
      p_mCount->mPrev = p_mCount;
      v3[5].mHead.mUID = (unsigned __int64)&v3[4].mCount;
      UFG::qString::~qString((UFG::qString *)&v3[4].mHead.mParent);
      UFG::qString::~qString((UFG::qString *)&v3[3].mHead.mChildren[1]);
      UFG::qString::~qString((UFG::qString *)&v3[2].mHead.mNeighbours[1]);
      UFG::qString::~qString((UFG::qString *)&v3[2]);
      operator delete[](v3);
    }
  }
  while ( this->mTags.mTree.mCount )
  {
    v10 = UFG::qTree64Base::GetHead(&this->mTags.mTree);
    v11 = v10;
    if ( v10 )
      UFG::qTree64Base::Remove(&this->mTags.mTree, v10);
    if ( v11 )
    {
      UFG::qString::~qString((UFG::qString *)&v11->mCount);
      operator delete[](v11);
    }
  }
  v12 = UFG::qTree64Base::GetHead(&this->mFactories.mTree);
  if ( v12 )
  {
    v13 = &v12[-1].mCount;
    if ( v12 != (UFG::qTree64Base *)8 )
    {
      do
      {
        (*(void (__fastcall **)(__int64 *, UFG::AssetHive *))*v13)(v13, this);
        Next = UFG::qTree64Base::GetNext(&this->mFactories.mTree, (UFG::qTree64Base::BaseNode *)(v13 + 1));
        if ( !Next )
          break;
        v13 = &Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 111
// RVA: 0x209500
void __fastcall UFG::AssetHive::EditAssets(UFG::AssetHive *this, UFG::qArray<UFG::HiveAsset *,0> *assets)
{
  UFG::qArray<UFG::HiveAsset *,0> *v2; // rsi
  UFG::AssetHive *v3; // rdi
  unsigned int v4; // r12d
  __int64 v5; // rdi
  __int64 **v6; // rbx
  UFG::allocator::free_link *v7; // rax
  __int64 *v8; // rax
  UFG::HiveAsset **v9; // r13
  __int64 v10; // r15
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // edi
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // r14
  __int64 i; // r9
  __int64 **v18; // rbx
  unsigned __int64 v19; // rax
  UFG::qTree64Base *v20; // rax
  __int64 *p_mCount; // rcx
  __int64 *j; // rbx
  __int64 v23; // rcx
  _QWORD *v24; // rax
  void *v25; // rcx
  __int64 v26; // rdx
  _QWORD *v27; // rax
  __int64 *v28; // rcx
  _QWORD *v29; // rax
  __int64 *v30; // [rsp+28h] [rbp-18h] BYREF
  void *mem; // [rsp+30h] [rbp-10h]

  v2 = assets;
  v3 = this;
  v30 = (__int64 *)&v30;
  mem = &v30;
  v4 = 0;
  if ( assets->size )
  {
    do
    {
      v5 = v4;
      v6 = (__int64 **)mem;
      if ( mem == &v30 )
      {
LABEL_5:
        v7 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
        v6 = (__int64 **)v7;
        if ( v7 )
        {
          v7->mNext = v7;
          v7[1].mNext = v7;
          v7[3].mNext = 0i64;
          v7[2].mNext = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v8 = v30;
        v30[1] = (__int64)v6;
        *v6 = v8;
        v6[1] = (__int64 *)&v30;
        v30 = (__int64 *)v6;
      }
      else
      {
        while ( *(char **)(*v6[3] + 216) != v2->p[v5]->mTypeName.mData )
        {
          v6 = (__int64 **)v6[1];
          if ( v6 == &v30 )
            goto LABEL_5;
        }
      }
      v9 = &v2->p[v5];
      v10 = *((unsigned int *)v6 + 4);
      v11 = v10 + 1;
      v12 = *((_DWORD *)v6 + 5);
      if ( (int)v10 + 1 > v12 )
      {
        if ( v12 )
          v13 = 2 * v12;
        else
          v13 = 1;
        for ( ; v13 < v11; v13 *= 2 )
          ;
        if ( v13 <= 2 )
          v13 = 2;
        if ( v13 - v11 > 0x10000 )
          v13 = v10 + 65537;
        if ( v13 != (_DWORD)v10 )
        {
          v14 = 8i64 * v13;
          if ( !is_mul_ok(v13, 8ui64) )
            v14 = -1i64;
          v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
          v16 = v15;
          if ( v6[3] )
          {
            for ( i = 0i64; (unsigned int)i < *((_DWORD *)v6 + 4); i = (unsigned int)(i + 1) )
              v15[i].mNext = (UFG::allocator::free_link *)v6[3][i];
            operator delete[](v6[3]);
          }
          v6[3] = (__int64 *)v16;
          *((_DWORD *)v6 + 5) = v13;
        }
      }
      *((_DWORD *)v6 + 4) = v11;
      v6[3][v10] = (__int64)*v9;
      ++v4;
      v2 = assets;
    }
    while ( v4 < assets->size );
    v3 = this;
  }
  v18 = (__int64 **)mem;
  if ( mem != &v30 )
  {
    do
    {
      v19 = UFG::qStringHash64(*(const char **)(*v18[3] + 216), 0xFFFFFFFFFFFFFFFFui64);
      v20 = UFG::qTree64Base::Get(&v3->mFactories.mTree, v19);
      p_mCount = &v20[-1].mCount;
      if ( !v20 )
        p_mCount = 0i64;
      (*(void (__fastcall **)(__int64 *, __int64 **))(*p_mCount + 16))(p_mCount, v18 + 2);
      v18 = (__int64 **)v18[1];
    }
    while ( v18 != &v30 );
  }
  for ( j = (__int64 *)mem; mem != &v30; j = (__int64 *)mem )
  {
    v23 = *j;
    v24 = (_QWORD *)j[1];
    *(_QWORD *)(v23 + 8) = v24;
    *v24 = v23;
    *j = (__int64)j;
    j[1] = (__int64)j;
    v25 = (void *)j[3];
    if ( v25 )
      operator delete[](v25);
    j[3] = 0i64;
    j[2] = 0i64;
    v26 = *j;
    v27 = (_QWORD *)j[1];
    *(_QWORD *)(v26 + 8) = v27;
    *v27 = v26;
    *j = (__int64)j;
    j[1] = (__int64)j;
    operator delete[](j);
  }
  v28 = v30;
  v29 = mem;
  v30[1] = (__int64)mem;
  *v29 = v28;
}

