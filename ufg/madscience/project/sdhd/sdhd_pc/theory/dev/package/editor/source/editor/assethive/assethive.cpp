// File Line: 48
// RVA: 0x20DB60
UFG::AssetHive *__fastcall UFG::AssetHive::Instance()
{
  UFG::AssetHive *result; // rax

  if ( _S1_26 & 1 )
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
  UFG::HiveAsset *v2; // rbx
  UFG::AssetHive *v3; // rbp
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rsi
  signed __int64 i; // r14
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rbx
  const char *v8; // rdi
  unsigned __int64 v9; // rax

  v2 = asset;
  v3 = this;
  UFG::qTree64Base::Add(&this->mAssets.mTree, &asset->mBaseNode);
  v4 = v2->mTags.mNode.mNext;
  for ( i = (signed __int64)&v2->mTags; v4 != (UFG::qNode<UFG::qString,UFG::qString> *)i; v4 = v4->mNext )
  {
    v6 = UFG::qStringHash64((const char *)v4[1].mNext, 0xFFFFFFFFFFFFFFFFui64);
    if ( !UFG::qTree64Base::Get(&v3->mTags.mTree, v6) )
    {
      v7 = UFG::qMalloc(0x58ui64, UFG::gGlobalNewName, 0i64);
      if ( v7 )
      {
        v8 = (const char *)v4[1].mNext;
        v9 = UFG::qStringHash64((const char *)v4[1].mNext, 0xFFFFFFFFFFFFFFFFui64);
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
      UFG::qTree64Base::Add(&v3->mTags.mTree, (UFG::qTree64Base::BaseNode *)v7);
    }
  }
}

// File Line: 78
// RVA: 0x20D0E0
void __fastcall UFG::AssetHive::IndexAssets(UFG::AssetHive *this)
{
  UFG::AssetHive *v1; // r14
  UFG::qTree64Base *v2; // rax
  UFG::qTree64Base *v3; // rsi
  UFG::qString *v4; // rdi
  UFG::qString *v5; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qTree64Base *v10; // rax
  UFG::qTree64Base *v11; // rbx
  UFG::qTree64Base *v12; // rax
  signed __int64 v13; // rbx
  UFG::qTree64Base *v14; // rax

  v1 = this;
  while ( v1->mAssets.mTree.mCount )
  {
    v2 = UFG::qTree64Base::GetHead(&v1->mAssets.mTree);
    v3 = v2;
    if ( v2 )
      UFG::qTree64Base::Remove(&v1->mAssets.mTree, &v2->mHead);
    if ( v3 )
    {
      v4 = (UFG::qString *)&v3[4].mCount;
      v5 = (UFG::qString *)v3[5].mHead.mUID;
      if ( v5 != (UFG::qString *)&v3[4].mCount )
      {
        do
        {
          v6 = v5->mPrev;
          v7 = v5->mNext;
          v6->mNext = v7;
          v7->mPrev = v6;
          v5->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v5->mPrev;
          v5->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v5->mPrev;
          UFG::qString::~qString(v5);
          operator delete[](v5);
          v5 = (UFG::qString *)v3[5].mHead.mUID;
        }
        while ( v5 != v4 );
      }
      v8 = v4->mPrev;
      v9 = (UFG::qNode<UFG::qString,UFG::qString> *)v3[5].mHead.mUID;
      v8->mNext = v9;
      v9->mPrev = v8;
      v4->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
      v3[5].mHead.mUID = (unsigned __int64)&v3[4].mCount;
      UFG::qString::~qString((UFG::qString *)&v3[4].mHead.mParent);
      UFG::qString::~qString((UFG::qString *)&v3[3].mHead.mChildren[1]);
      UFG::qString::~qString((UFG::qString *)&v3[2].mHead.mNeighbours[1]);
      UFG::qString::~qString((UFG::qString *)&v3[2]);
      operator delete[](v3);
    }
  }
  while ( v1->mTags.mTree.mCount )
  {
    v10 = UFG::qTree64Base::GetHead(&v1->mTags.mTree);
    v11 = v10;
    if ( v10 )
      UFG::qTree64Base::Remove(&v1->mTags.mTree, &v10->mHead);
    if ( v11 )
    {
      UFG::qString::~qString((UFG::qString *)&v11->mCount);
      operator delete[](v11);
    }
  }
  v12 = UFG::qTree64Base::GetHead(&v1->mFactories.mTree);
  if ( v12 )
  {
    v13 = (signed __int64)&v12[-1].mCount;
    if ( v12 != (UFG::qTree64Base *)8 )
    {
      do
      {
        (**(void (__fastcall ***)(signed __int64, UFG::AssetHive *))v13)(v13, v1);
        v14 = UFG::qTree64Base::GetNext(&v1->mFactories.mTree, (UFG::qTree64Base::BaseNode *)(v13 + 8));
        if ( !v14 )
          break;
        v13 = (signed __int64)&v14[-1].mCount;
      }
      while ( v14 != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 111
// RVA: 0x209500
void __fastcall UFG::AssetHive::EditAssets(UFG::AssetHive *this, UFG::qArray<UFG::HiveAsset *,0> *assets)
{
  UFG::qArray<UFG::HiveAsset *,0> *v2; // rsi
  UFG::AssetHive *v3; // rdi
  unsigned int v4; // er12
  signed __int64 v5; // rdi
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
  __int64 v17; // r9
  __int64 **v18; // rbx
  unsigned __int64 v19; // rax
  UFG::qTree64Base *v20; // rax
  signed __int64 v21; // rcx
  __int64 *i; // rbx
  __int64 v23; // rcx
  _QWORD *v24; // rax
  void *v25; // rcx
  __int64 v26; // rdx
  _QWORD *v27; // rax
  __int64 *v28; // rcx
  _QWORD *v29; // rax
  __int64 *v30; // [rsp+28h] [rbp-18h]
  void *mem; // [rsp+30h] [rbp-10h]
  UFG::AssetHive *v32; // [rsp+80h] [rbp+40h]
  UFG::qArray<UFG::HiveAsset *,0> *v33; // [rsp+88h] [rbp+48h]

  v33 = assets;
  v32 = this;
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
      if ( (signed int)v10 + 1 > v12 )
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
            v17 = 0i64;
            if ( *((_DWORD *)v6 + 4) )
            {
              do
              {
                v15[v17].mNext = (UFG::allocator::free_link *)v6[3][v17];
                v17 = (unsigned int)(v17 + 1);
              }
              while ( (unsigned int)v17 < *((_DWORD *)v6 + 4) );
            }
            operator delete[](v6[3]);
          }
          v6[3] = (__int64 *)v16;
          *((_DWORD *)v6 + 5) = v13;
        }
      }
      *((_DWORD *)v6 + 4) = v11;
      v6[3][v10] = (__int64)*v9;
      ++v4;
      v2 = v33;
    }
    while ( v4 < v33->size );
    v3 = v32;
  }
  v18 = (__int64 **)mem;
  if ( mem != &v30 )
  {
    do
    {
      v19 = UFG::qStringHash64(*(const char **)(*v18[3] + 216), 0xFFFFFFFFFFFFFFFFui64);
      v20 = UFG::qTree64Base::Get(&v3->mFactories.mTree, v19);
      v21 = (signed __int64)&v20[-1].mCount;
      if ( !v20 )
        v21 = 0i64;
      (*(void (__fastcall **)(signed __int64, __int64 **))(*(_QWORD *)v21 + 16i64))(v21, v18 + 2);
      v18 = (__int64 **)v18[1];
    }
    while ( v18 != &v30 );
  }
  for ( i = (__int64 *)mem; mem != &v30; i = (__int64 *)mem )
  {
    v23 = *i;
    v24 = (_QWORD *)i[1];
    *(_QWORD *)(v23 + 8) = v24;
    *v24 = v23;
    *i = (__int64)i;
    i[1] = (__int64)i;
    v25 = (void *)i[3];
    if ( v25 )
      operator delete[](v25);
    i[3] = 0i64;
    i[2] = 0i64;
    v26 = *i;
    v27 = (_QWORD *)i[1];
    *(_QWORD *)(v26 + 8) = v27;
    *v27 = v26;
    *i = (__int64)i;
    i[1] = (__int64)i;
    operator delete[](i);
  }
  v28 = v30;
  v29 = mem;
  v30[1] = (__int64)mem;
  *v29 = v28;
}

