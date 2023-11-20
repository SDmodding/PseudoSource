// File Line: 26
// RVA: 0x14595B0
__int64 dynamic_initializer_for__UFG::UIMapBlipManager::gPrintChannel__()
{
  UFG::qString::qString(&stru_142033FA0);
  return atexit(dynamic_atexit_destructor_for__UFG::UIMapBlipManager::gPrintChannel__);
}

// File Line: 27
// RVA: 0x14595E0
__int64 dynamic_initializer_for__UFG::UIMapBlipManager::gSpamChannel__()
{
  UFG::qString::qString(&stru_142033FF0);
  return atexit(dynamic_atexit_destructor_for__UFG::UIMapBlipManager::gSpamChannel__);
}

// File Line: 37
// RVA: 0xBD750
void __fastcall UFG::UIMapBlipList::~UIMapBlipList(UFG::UIMapBlipList *this)
{
  UFG::UIMapBlipList *v1; // rbx
  UFG::UIMapBlip **v2; // rcx

  v1 = this;
  this->vfptr = (UFG::UIMapBlipListVtbl *)&UFG::UIMapBlipList::`vftable';
  UFG::UIMapBlipList::DeleteAll(this);
  v2 = v1->mSortedIcons.p;
  if ( v2 )
    operator delete[](v2);
  v1->mSortedIcons.p = 0i64;
  *(_QWORD *)&v1->mSortedIcons.size = 0i64;
  UFG::qTreeRB<UFG::UIMapBlip,UFG::UIMapBlip,1>::~qTreeRB<UFG::UIMapBlip,UFG::UIMapBlip,1>(&v1->mIconData);
}

// File Line: 43
// RVA: 0xC0B60
UFG::qBaseTreeRB *__fastcall UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem *this, unsigned int guid)
{
  UFG::qBaseTreeRB *result; // rax

  if ( guid )
    result = UFG::qBaseTreeRB::Get(&this->mCollisionModels.mTree, guid);
  else
    result = 0i64;
  return result;
}

// File Line: 49
// RVA: 0xBE100
void __fastcall UFG::UIMapBlipList::Add(UFG::UIMapBlipList *this, UFG::UIMapBlip *icon)
{
  UFG::UIMapBlipList *v2; // rsi
  UFG::UIMapBlip *v3; // rbp
  __int64 v4; // r14
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::UIMapBlip **v8; // rax

  v2 = this;
  v3 = icon;
  UFG::qBaseTreeRB::Add(&this->mIconData.mTree, &icon->mNode);
  v4 = v2->mSortedIcons.size;
  v5 = v2->mSortedIcons.capacity;
  v6 = v4 + 1;
  if ( (signed int)v4 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v4 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v2->mSortedIcons,
      v7,
      "qArray.Add");
  }
  v8 = v2->mSortedIcons.p;
  v2->mSortedIcons.size = v6;
  v8[v4] = v3;
  v2->mNeedToSort = 1;
}

// File Line: 57
// RVA: 0xC7110
void __fastcall UFG::UIMapBlipList::Remove(UFG::UIMapBlipList *this, UFG::UIMapBlip *icon)
{
  UFG::UIMapBlipList *v2; // rbx
  UFG::UIMapBlip *v3; // rdi
  unsigned int v4; // ecx
  __int64 v5; // r8
  UFG::UIMapBlip **v6; // rax
  unsigned int v7; // eax

  v2 = this;
  v3 = icon;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mIconData,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)icon);
  v4 = v2->mSortedIcons.size;
  v5 = 0i64;
  if ( v4 )
  {
    v6 = v2->mSortedIcons.p;
    while ( v3 != *v6 )
    {
      v5 = (unsigned int)(v5 + 1);
      ++v6;
      if ( (unsigned int)v5 >= v4 )
        return;
    }
    if ( (_DWORD)v5 != -1 )
    {
      v2->mSortedIcons.p[v5] = v2->mSortedIcons.p[v4 - 1];
      v7 = v2->mSortedIcons.size;
      if ( v7 > 1 )
        v2->mSortedIcons.size = v7 - 1;
      else
        v2->mSortedIcons.size = 0;
      v2->mNeedToSort = 1;
    }
  }
}

// File Line: 76
// RVA: 0xBEDD0
void __fastcall UFG::UIMapBlipList::DeleteAll(UFG::UIMapBlipList *this)
{
  UFG::UIMapBlipList *v1; // rsi
  Render::SkinningCacheNode *v2; // rbx
  UFG::UIMapBlip **v3; // rcx

  v1 = this;
  while ( v1->mIconData.mTree.mCount )
  {
    v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mIconData);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mIconData,
      &v2->mNode);
    if ( v2 )
    {
      UFG::UIMapBlip::~UIMapBlip((UFG::UIMapBlip *)v2);
      operator delete[](v2);
    }
  }
  v3 = v1->mSortedIcons.p;
  if ( v3 )
    operator delete[](v3);
  v1->mSortedIcons.p = 0i64;
  *(_QWORD *)&v1->mSortedIcons.size = 0i64;
}

// File Line: 82
// RVA: 0xCEEE0
bool __fastcall UFG::fnDrawDepth(UFG::UIMapBlip *const *a, UFG::UIMapBlip *const *b)
{
  return (*a)->mType->DrawDepth < (*b)->mType->DrawDepth;
}

// File Line: 104
// RVA: 0xBBE40
void __fastcall UFG::UIMapBlipManager::UIMapBlipManager(UFG::UIMapBlipManager *this)
{
  UFG::UIMapBlipManager *v1; // rbx

  v1 = this;
  this->mIconList.vfptr = (UFG::UIMapBlipListVtbl *)&UFG::UIMapBlipList::`vftable';
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mIconList.mIconData.mTree);
  v1->mIconList.mSortedIcons.p = 0i64;
  *(_QWORD *)&v1->mIconList.mSortedIcons.size = 0i64;
  v1->mIconList.mNeedToSort = 1;
  v1->mMaxNumIcons = 500;
  v1->mAmbientBlipsPopulated = 0;
  v1->mPlayerArrowIcon = 0i64;
}

// File Line: 109
// RVA: 0xBD7A0
void __fastcall UFG::UIMapBlipManager::~UIMapBlipManager(UFG::UIMapBlipManager *this)
{
  UFG::UIMapBlipManager *v1; // rdi
  UFG::UIMapBlipGraphic *v2; // r14
  void **v3; // rbx
  signed __int64 v4; // rsi
  UFG::UIMapBlip **v5; // rcx

  v1 = this;
  UFG::UIMapBlipList::DeleteAll(&this->mIconList);
  v2 = v1->mPlayerArrowIcon;
  if ( v2 )
  {
    v2->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable';
    v3 = (void **)&v2->mPolys[1];
    v4 = 4i64;
    do
    {
      if ( *v3 )
      {
        operator delete[](*v3);
        *v3 = 0i64;
      }
      ++v3;
      --v4;
    }
    while ( v4 );
    operator delete[](v2);
  }
  v1->mIconList.vfptr = (UFG::UIMapBlipListVtbl *)&UFG::UIMapBlipList::`vftable';
  UFG::UIMapBlipList::DeleteAll(&v1->mIconList);
  v5 = v1->mIconList.mSortedIcons.p;
  if ( v5 )
    operator delete[](v5);
  v1->mIconList.mSortedIcons.p = 0i64;
  *(_QWORD *)&v1->mIconList.mSortedIcons.size = 0i64;
  UFG::qTreeRB<UFG::UIMapBlip,UFG::UIMapBlip,1>::~qTreeRB<UFG::UIMapBlip,UFG::UIMapBlip,1>(&v1->mIconList.mIconData);
}

// File Line: 189
// RVA: 0xBE930
void __fastcall UFG::UIMapBlipManager::Clear(UFG::UIMapBlipManager *this)
{
  UFG::UIMapBlipManager *v1; // rbx

  v1 = this;
  UFG::UIMapBlipList::DeleteAll(&this->mIconList);
  v1->mAmbientBlipsPopulated = 0;
}

// File Line: 196
// RVA: 0xC6410
void __usercall UFG::UIMapBlipManager::PopulateWorldMap(UFG::UIMapBlipManager *this@<rcx>, UFG::UIScreen *screen@<rdx>, UFG::UIMapBlipManager *clone@<r8>, UFG::qArray<UFG::qSymbolUC,0> *validTypes@<r9>, float a5@<xmm0>)
{
  UFG::UIMapBlipManager *v5; // rbp
  UFG::UIMapBlipManager *v6; // r13
  __int64 i; // r15
  UFG::qSymbolUC *v8; // r12
  __int64 v9; // r14
  UFG::qPropertySet **v10; // r10
  UFG::qPropertySet **v11; // rdi
  signed __int64 v12; // rax
  signed int v13; // ecx
  signed __int64 v14; // r8
  UFG::qPropertySet *v15; // r9
  UFG::qPropertySet *v16; // r9
  UFG::qPropertySet *v17; // r11
  UFG::qPropertySet *v18; // r9
  UFG::qPropertySet *v19; // r11
  UFG::qPropertySet **v20; // rbx
  UFG::qPropertySet **k; // r9
  unsigned int v22; // edx
  UFG::qPropertySet *v23; // rax
  __int64 v24; // rax
  UFG::qPropertySet *v25; // rax
  UFG::qPropertySet *v26; // rdx
  signed __int64 v27; // r11
  int v28; // edi
  UFG::qPropertySet *v29; // rbx
  int v30; // er8
  signed __int64 j; // rdx
  UFG::qPropertySet *v32; // r9
  UFG::UIMapBlip *v33; // rdx
  UFG::UIHKMinimapBlipType *v34; // rbx
  UFG::qBaseTreeRB *v35; // rax
  UFG::qArray<UFG::qSymbolUC,0> *v36; // [rsp+68h] [rbp+20h]

  if ( clone )
  {
    v36 = validTypes;
    v5 = clone;
    clone->mAmbientBlipsPopulated |= this->mAmbientBlipsPopulated;
    v6 = this;
    for ( i = validTypes->size - 1; i >= 0; --i )
    {
      v8 = validTypes->p;
      v9 = 0i64;
      if ( (signed int)v5->mIconList.mSortedIcons.size > 0 )
      {
        do
        {
          if ( v5->mIconList.mNeedToSort )
          {
            v10 = (UFG::qPropertySet **)v5->mIconList.mSortedIcons.p;
            v11 = &v10[(signed int)v5->mIconList.mSortedIcons.size - 1i64];
            v12 = 8 * ((signed int)v5->mIconList.mSortedIcons.size - 1i64) >> 3;
            v13 = v12 + 1;
            if ( (signed int)v12 + 1 < 32 )
            {
              if ( v13 > 1 )
              {
                v27 = 1i64;
                if ( v13 > 1i64 )
                {
                  v28 = 0;
                  do
                  {
                    v29 = v10[v27];
                    v30 = v28;
                    for ( j = v27 - 1; v30 >= 0; --v30 )
                    {
                      v32 = v10[j];
                      if ( *(_DWORD *)(v29->mDefaultBits.mOffset + 96) >= *(_DWORD *)(v32->mDefaultBits.mOffset + 96) )
                        break;
                      v10[j-- + 1] = v32;
                    }
                    ++v27;
                    ++v28;
                    v10[j + 1] = v29;
                  }
                  while ( v27 < v13 );
                }
              }
            }
            else
            {
              v14 = v12 / 2;
              v15 = v10[v12 / 2];
              if ( *(_DWORD *)(v15->mDefaultBits.mOffset + 96) < *(_DWORD *)((*v10)->mDefaultBits.mOffset + 96) )
              {
                v10[v14] = *v10;
                *v10 = v15;
              }
              v16 = v10[v14];
              v17 = *v11;
              if ( *(_DWORD *)((*v11)->mDefaultBits.mOffset + 96) < *(_DWORD *)(v16->mDefaultBits.mOffset + 96) )
              {
                *v11 = v16;
                v10[v14] = v17;
              }
              v18 = v10[v14];
              if ( *(_DWORD *)(v18->mDefaultBits.mOffset + 96) < *(_DWORD *)((*v10)->mDefaultBits.mOffset + 96) )
              {
                v10[v14] = *v10;
                *v10 = v18;
              }
              v19 = v10[v14];
              v20 = v10;
              for ( k = v11; v20 <= k; ++v20 )
              {
                v22 = *(_DWORD *)(v19->mDefaultBits.mOffset + 96);
                if ( *(_DWORD *)((*v20)->mDefaultBits.mOffset + 96) < v22 )
                {
                  do
                  {
                    if ( v20 >= v11 )
                      break;
                    v23 = v20[1];
                    ++v20;
                  }
                  while ( *(_DWORD *)(v23->mDefaultBits.mOffset + 96) < v22 );
                }
                if ( v22 < *(_DWORD *)((*k)->mDefaultBits.mOffset + 96) )
                {
                  do
                  {
                    if ( v10 >= k )
                      break;
                    v24 = (__int64)*(k - 1);
                    --k;
                  }
                  while ( v22 < *(_DWORD *)(*(_QWORD *)(v24 + 48) + 96i64) );
                }
                if ( v20 > k )
                  break;
                v25 = *k;
                v26 = *v20;
                --k;
                *v20 = v25;
                k[1] = v26;
              }
              if ( v10 < k )
                UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
                  v10,
                  k,
                  (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
              if ( v20 < v11 )
                UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
                  v20,
                  v11,
                  (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
            }
            v5->mIconList.mNeedToSort = 0;
          }
          v33 = v5->mIconList.mSortedIcons.p[v9];
          if ( v33 )
          {
            v34 = v33->mType;
            if ( v34 )
            {
              if ( v8[i].mUID == v34->TypeNameSymbol.mUID )
              {
                v35 = UFG::UIMapBlipManager::CreateIconFromClone(v6, v33, a5);
                LOBYTE(v35->mNULL.mParent) = 0;
                if ( !v34->IsDistanceFilteredOnWorldMap )
                {
                  BYTE3(v35->mNULL.mParent) = 1;
                  HIDWORD(v35->mNULL.mParent) = 1232348160;
                }
              }
            }
          }
          v9 = (unsigned int)(v9 + 1);
        }
        while ( (signed int)v9 < (signed int)v5->mIconList.mSortedIcons.size );
        validTypes = v36;
      }
    }
  }
}

// File Line: 241
// RVA: 0xC4BA0
void __fastcall UFG::UIMapBlipManager::HandleScreenInit(UFG::UIMapBlipManager *this)
{
  signed int v1; // eax
  __int64 v2; // rbp
  UFG::UIMapBlipManager *v3; // rsi
  UFG::qPropertySet **v4; // r9
  UFG::qPropertySet **v5; // rdi
  signed __int64 v6; // rax
  int v7; // edx
  signed __int64 v8; // r8
  UFG::qPropertySet *v9; // r10
  UFG::qPropertySet *v10; // r11
  UFG::qPropertySet *v11; // r10
  UFG::qPropertySet *v12; // r10
  UFG::qPropertySet **v13; // rbx
  UFG::qPropertySet **i; // rdx
  unsigned int v15; // er8
  UFG::qPropertySet *v16; // rax
  __int64 v17; // rax
  UFG::qPropertySet *v18; // rax
  UFG::qPropertySet *v19; // r8
  UFG::UIMapBlip *v20; // rdx

  v1 = this->mIconList.mSortedIcons.size;
  v2 = 0i64;
  v3 = this;
  if ( v1 > 0 )
  {
    do
    {
      if ( v3->mIconList.mNeedToSort )
      {
        v4 = (UFG::qPropertySet **)v3->mIconList.mSortedIcons.p;
        v5 = &v4[v1 - 1i64];
        v6 = 8 * (v1 - 1i64) >> 3;
        v7 = v6 + 1;
        if ( (signed int)v6 + 1 < 32 )
        {
          if ( v7 > 1 )
            UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
              (UFG::qPropertySet **)v3->mIconList.mSortedIcons.p,
              v7,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        }
        else
        {
          v8 = (signed __int64)&v4[v6 / 2];
          v9 = *(UFG::qPropertySet **)v8;
          if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) < *(_DWORD *)((*v4)->mDefaultBits.mOffset + 96) )
          {
            *(_QWORD *)v8 = *v4;
            *v4 = v9;
          }
          v10 = *v5;
          if ( *(_DWORD *)((*v5)->mDefaultBits.mOffset + 96) < *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) )
          {
            *v5 = *(UFG::qPropertySet **)v8;
            *(_QWORD *)v8 = v10;
          }
          v11 = *(UFG::qPropertySet **)v8;
          if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) < *(_DWORD *)((*v4)->mDefaultBits.mOffset + 96) )
          {
            *(_QWORD *)v8 = *v4;
            *v4 = v11;
          }
          v12 = *(UFG::qPropertySet **)v8;
          v13 = v4;
          for ( i = v5; v13 <= i; ++v13 )
          {
            v15 = *(_DWORD *)(v12->mDefaultBits.mOffset + 96);
            if ( *(_DWORD *)((*v13)->mDefaultBits.mOffset + 96) < v15 )
            {
              do
              {
                if ( v13 >= v5 )
                  break;
                v16 = v13[1];
                ++v13;
              }
              while ( *(_DWORD *)(v16->mDefaultBits.mOffset + 96) < v15 );
            }
            if ( v15 < *(_DWORD *)((*i)->mDefaultBits.mOffset + 96) )
            {
              do
              {
                if ( v4 >= i )
                  break;
                v17 = (__int64)*(i - 1);
                --i;
              }
              while ( v15 < *(_DWORD *)(*(_QWORD *)(v17 + 48) + 96i64) );
            }
            if ( v13 > i )
              break;
            v18 = *i;
            v19 = *v13;
            --i;
            *v13 = v18;
            i[1] = v19;
          }
          if ( v4 < i )
            UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
              v4,
              i,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
          if ( v13 < v5 )
            UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
              v13,
              v5,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        }
        v3->mIconList.mNeedToSort = 0;
      }
      v20 = v3->mIconList.mSortedIcons.p[v2];
      if ( v20 )
        v20->mAltitudeStateChanged = 1;
      v1 = v3->mIconList.mSortedIcons.size;
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (signed int)v2 < v1 );
  }
}= v3-

// File Line: 300
// RVA: 0xCC1B0
void __fastcall UFG::UIMapBlipManager::Update(UFG::UIMapBlipManager *this, UFG::UIScreen *screen, float elapsed, UFG::qVector3 *playerPos, UFG::UITiledMapMath *mapGeo, UFG::UITiledMapMath *mapIconGeo, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeClipped, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeNotClipped, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeDoubleClipped, bool isIndoors, bool forceUpdate)
{
  __int64 v11; // rax
  int v12; // ebp
  UFG::qVector3 *v13; // r12
  UFG::UIMapBlipManager *v14; // rbx
  __int64 v15; // rsi
  __int64 v16; // r15
  UFG::UIMapBlip **v17; // rax
  UFG::UIMapBlip *v18; // rdi
  UFG::UIHKMinimapBlipType *v19; // rax
  UFG::UIMapBlipGraphic *v20; // rcx
  int v21; // [rsp+40h] [rbp-38h]
  UFG::UIScreen *screena; // [rsp+88h] [rbp+10h]

  if ( screen )
  {
    screena = screen;
    v11 = this->mIconList.mSortedIcons.size;
    v12 = 0;
    v13 = playerPos;
    v14 = this;
    v15 = 0i64;
    v16 = (unsigned int)v11;
    if ( v11 > 0 )
    {
      v21 = v11 - 1;
      do
      {
        if ( v14->mIconList.mNeedToSort )
        {
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            (UFG::qPropertySet **)v14->mIconList.mSortedIcons.p,
            (UFG::qPropertySet **)&v14->mIconList.mSortedIcons.p[(signed int)v14->mIconList.mSortedIcons.size - 1i64],
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
          v14->mIconList.mNeedToSort = 0;
        }
        v17 = v14->mIconList.mSortedIcons.p;
        v18 = v17[v15];
        if ( v12 < v21 && v14->mIconList.mNeedToSort )
        {
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            (UFG::qPropertySet **)v14->mIconList.mSortedIcons.p,
            (UFG::qPropertySet **)&v17[(signed int)v14->mIconList.mSortedIcons.size - 1i64],
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
          v14->mIconList.mNeedToSort = 0;
        }
        if ( v18 )
        {
          if ( forceUpdate )
            v18->mChanged = 1;
          UFG::UIMapBlip::Update(v18, screena, v13, mapGeo);
          v19 = v18->mType;
          if ( v19
            && (!isIndoors || mapGeo->IsWorldMap || !v19->IsHiddenIndoors)
            && v18->mVisible
            && v19
            && v19->IsVisible )
          {
            UFG::UIMapBlip::UpdateNative(
              v18,
              v13,
              mapGeo,
              mapIconGeo,
              polyListNativeClipped,
              polyListNativeNotClipped,
              polyListNativeDoubleClipped);
          }
        }
        ++v15;
        ++v12;
      }
      while ( v15 < v16 );
    }
    v20 = v14->mPlayerArrowIcon;
    if ( v20 )
      UFG::UIMapBlipGraphic::QueueIconToRender(
        v20,
        polyListNativeClipped,
        polyListNativeNotClipped,
        polyListNativeDoubleClipped);
  }
}

// File Line: 358
// RVA: 0xBEA40
UFG::UIMapBlip *__usercall UFG::UIMapBlipManager::CreateIcon@<rax>(UFG::UIMapBlipManager *this@<rcx>, unsigned int uid@<edx>, const char *iconType@<r8>, float xPos@<xmm3>, float a5@<xmm0>, float yPos)
{
  float v6; // xmm6_4
  const char *v7; // r14
  unsigned int v8; // ebp
  UFG::UIMapBlipManager *v9; // rsi
  UFG::UIMapBlip *v10; // rax
  UFG::UIMapBlip *v11; // rbx
  UFG::UIMapBlipTypeManager *v12; // rax
  UFG::UIHKMinimapBlipType *v13; // rax
  __m128 v14; // xmm2
  float v15; // xmm3_4
  UFG::qSymbolUC result; // [rsp+68h] [rbp+10h]

  v6 = xPos;
  v7 = iconType;
  v8 = uid;
  v9 = this;
  if ( uid - 1 > 0xFFFFFFFD
    || !iconType
    || !*iconType
    || UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, uid)
    || (signed int)v9->mIconList.mSortedIcons.size >= v9->mMaxNumIcons )
  {
    return 0i64;
  }
  v10 = (UFG::UIMapBlip *)UFG::qMalloc(0x80ui64, "UIMapBlip", 0i64);
  v11 = v10;
  if ( v10 )
  {
    v10->mNode.mParent = 0i64;
    v10->mNode.mChild[0] = 0i64;
    v10->mNode.mChild[1] = 0i64;
    v10->mNode.mUID = v8;
    *(_DWORD *)&v10->mBoundIcon = 257;
    *(_QWORD *)&v10->mCustomFilterDistance = 0i64;
    *(_DWORD *)&v10->mIsAmbient = 16777472;
    v10->mType = 0i64;
    v10->mObjective = 0i64;
    *(_QWORD *)&v10->pos.x = 0i64;
    *(_QWORD *)&v10->pos.z = 0i64;
    *(_QWORD *)&v10->mAltitudeDiff = 0i64;
    *(_DWORD *)&v10->mAltitudeStateChanged = 0;
    v10->mTouchesEdge = 0;
    *(_QWORD *)&v10->radiusScale = 0i64;
    *(_WORD *)&v10->mShouldStopHighlight = 0;
    v10->mProximityUnlockDone = 0;
    v10->mWorldMapCaption = 0i64;
    v10->mNativeIcon = 0i64;
  }
  else
  {
    v11 = 0i64;
  }
  if ( !v11 )
    return 0i64;
  UFG::qSymbolUC::create_from_string(&result, v7);
  v12 = UFG::UIMapBlipTypeManager::getInstance();
  v13 = UFG::UIMapBlipTypeManager::GetType(v12, &result);
  UFG::UIMapBlip::SetType(v11, v13, a5);
  v14 = (__m128)LODWORD(v11->pos.y);
  v15 = yPos;
  v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] - yPos) * (float)(v14.m128_f32[0] - yPos))
                          + (float)((float)(v11->pos.x - v6) * (float)(v11->pos.x - v6)))
                  + (float)(v11->pos.z * v11->pos.z);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v14)) > UFG::gSymbolPosDiff )
  {
    v11->pos.x = v6;
    v11->pos.y = v15;
    v11->pos.z = 0.0;
    v11->mChanged = 1;
  }
  UFG::UIMapBlipList::Add(&v9->mIconList, v11);
  return v11;
}

// File Line: 410
// RVA: 0xBEBD0
UFG::qBaseTreeRB *__usercall UFG::UIMapBlipManager::CreateIconFromClone@<rax>(UFG::UIMapBlipManager *this@<rcx>, UFG::UIMapBlip *clone@<rdx>, float a3@<xmm0>)
{
  UFG::UIMapBlip *v3; // rsi
  UFG::UIMapBlipManager *v4; // rdi
  unsigned int v6; // ebp
  char *v7; // rbx

  v3 = clone;
  v4 = this;
  if ( !clone )
    return 0i64;
  v6 = clone->mNode.mUID;
  if ( v6 && UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, v6) )
  {
    v7 = (char *)UFG::qBaseTreeRB::Get(&v4->mIconList.mIconData.mTree, v6);
    UFG::UIMapBlip::Clone((UFG::UIMapBlip *)v7, v3, a3);
  }
  else
  {
    if ( (signed int)v4->mIconList.mSortedIcons.size >= v4->mMaxNumIcons )
      return 0i64;
    v7 = UFG::qMalloc(0x80ui64, "UIMapBlip", 0i64);
    if ( v7 )
    {
      *(_QWORD *)v7 = 0i64;
      *((_QWORD *)v7 + 1) = 0i64;
      *((_QWORD *)v7 + 2) = 0i64;
      *((_DWORD *)v7 + 6) = v6;
      *((_DWORD *)v7 + 8) = 257;
      *(_QWORD *)(v7 + 36) = 0i64;
      *((_DWORD *)v7 + 11) = 16777472;
      *((_QWORD *)v7 + 6) = 0i64;
      *((_QWORD *)v7 + 7) = 0i64;
      *((_QWORD *)v7 + 8) = 0i64;
      *((_QWORD *)v7 + 9) = 0i64;
      *((_QWORD *)v7 + 10) = 0i64;
      *((_DWORD *)v7 + 22) = 0;
      v7[92] = 0;
      *((_QWORD *)v7 + 12) = 0i64;
      *((_WORD *)v7 + 52) = 0;
      v7[106] = 0;
      *((_QWORD *)v7 + 14) = 0i64;
      *((_QWORD *)v7 + 15) = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
    if ( !v7 )
      return 0i64;
    UFG::UIMapBlip::Clone((UFG::UIMapBlip *)v7, v3, a3);
    UFG::UIMapBlipList::Add(&v4->mIconList, (UFG::UIMapBlip *)v7);
  }
  return (UFG::qBaseTreeRB *)v7;
}

// File Line: 443
// RVA: 0xC71A0
void __fastcall UFG::UIMapBlipManager::RemoveIcon(UFG::UIMapBlipManager *this, unsigned int uid)
{
  UFG::UIMapBlipManager *v2; // rdi
  UFG::qBaseTreeRB *v3; // rax
  UFG::UIMapBlip *v4; // rbx

  if ( uid )
  {
    v2 = this;
    v3 = UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, uid);
    v4 = (UFG::UIMapBlip *)v3;
    if ( v3 )
    {
      UFG::UIMapBlipList::Remove(&v2->mIconList, (UFG::UIMapBlip *)v3);
      UFG::UIMapBlip::~UIMapBlip(v4);
      operator delete[](v4);
    }
  }
}

// File Line: 473
// RVA: 0xBE360
void __fastcall UFG::UIMapBlipManager::AddIconRadius(UFG::UIMapBlipManager *this, unsigned int blip_id, float radius, unsigned int color, float alpha)
{
  unsigned int v5; // edi
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseTreeRB *v7; // rbx
  UFG::qColour *v8; // r9
  UFG::UIMapBlip *v9; // rcx
  float alphaFactor; // xmm0_4
  UFG::UIMapBlipGraphic *v11; // rcx
  bool v12; // al
  float v13; // [rsp+30h] [rbp-28h]
  float v14; // [rsp+34h] [rbp-24h]
  float v15; // [rsp+38h] [rbp-20h]
  float v16; // [rsp+3Ch] [rbp-1Ch]

  if ( blip_id )
  {
    v5 = color;
    v6 = UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, blip_id);
    v7 = v6;
    if ( v6 )
    {
      if ( v5 )
      {
        v8 = (UFG::qColour *)&v13;
        v9 = (UFG::UIMapBlip *)v6;
        v13 = (float)(v5 >> 24) * 0.0039215689;
        v14 = (float)BYTE2(v5) * 0.0039215689;
        v15 = (float)BYTE1(v5) * 0.0039215689;
        alphaFactor = alpha;
        v16 = (float)(unsigned __int8)v5 * 0.0039215689;
      }
      else
      {
        alphaFactor = *(float *)&FLOAT_1_0;
        v9 = (UFG::UIMapBlip *)v6;
        v8 = (UFG::qColour *)&v6->mNULL.mChild[1][2];
      }
      UFG::UIMapBlip::SetRange(v9, 1, radius, v8, alphaFactor);
      v11 = (UFG::UIMapBlipGraphic *)v7[1].mNULL.mChild[1];
      v12 = BYTE3(v7[1].mRoot.mChild[1]) != 0;
      BYTE3(v7[1].mRoot.mChild[1]) = 0;
      BYTE5(v7->mNULL.mChild[0]) |= v12;
      if ( v11 )
        UFG::UIMapBlipGraphic::RemovePoly(v11, InteriorRangePoly);
    }
  }
}

// File Line: 498
// RVA: 0xBE1E0
void __fastcall UFG::UIMapBlipManager::AddIconDonutRadius(UFG::UIMapBlipManager *this, unsigned int blip_id, float radius, float interiorRadius, unsigned int outerColor, unsigned int innerColor)
{
  UFG::qBaseTreeRB *v6; // rax
  UFG::UIMapBlip *v7; // rbx
  UFG::qColour *v8; // r9
  UFG::UIMapBlip *v9; // rcx
  UFG::qColour *v10; // r9
  float v11; // [rsp+30h] [rbp-48h]
  float v12; // [rsp+34h] [rbp-44h]
  float v13; // [rsp+38h] [rbp-40h]
  float v14; // [rsp+3Ch] [rbp-3Ch]

  if ( blip_id )
  {
    v6 = UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, blip_id);
    v7 = (UFG::UIMapBlip *)v6;
    if ( v6 )
    {
      if ( outerColor )
      {
        v8 = (UFG::qColour *)&v11;
        v9 = (UFG::UIMapBlip *)v6;
        v11 = (float)(outerColor >> 24) * 0.0039215689;
        v12 = (float)BYTE2(outerColor) * 0.0039215689;
        v13 = (float)BYTE1(outerColor) * 0.0039215689;
        v14 = (float)(unsigned __int8)outerColor * 0.0039215689;
      }
      else
      {
        v9 = (UFG::UIMapBlip *)v6;
        v8 = (UFG::qColour *)&v6->mNULL.mChild[1][2];
      }
      UFG::UIMapBlip::SetRange(v9, 1, radius, v8, 1.0);
      if ( innerColor )
      {
        v10 = (UFG::qColour *)&v11;
        v11 = (float)(innerColor >> 24) * 0.0039215689;
        v12 = (float)BYTE2(innerColor) * 0.0039215689;
        v13 = (float)BYTE1(innerColor) * 0.0039215689;
        v14 = (float)(unsigned __int8)innerColor * 0.0039215689;
      }
      else
      {
        v10 = &v7->mType->InnerRadiusColor;
      }
      UFG::UIMapBlip::SetInteriorRange(v7, 1, interiorRadius, v10);
    }
  }
}

// File Line: 532
// RVA: 0xC71F0
void __fastcall UFG::UIMapBlipManager::RemoveIconRadius(UFG::UIMapBlipManager *this, unsigned int blip_id)
{
  UFG::qBaseTreeRB *v2; // rax
  UFG::qBaseTreeRB *v3; // rbx
  unsigned int v4; // xmm2_4
  UFG::UIMapBlipGraphic *v5; // rcx
  bool v6; // zf
  UFG::UIMapBlipGraphic *v7; // rcx

  if ( blip_id )
  {
    v2 = UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, blip_id);
    v3 = v2;
    if ( v2 )
    {
      *(float *)&v4 = (float)(0.0
                            / (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX
                                                    - UFG::UITiledMapMath::WorldGeo.MinX)
                                            / UFG::UITiledMapMath::WorldGeo.TextureWidth)
                                    * 88.0))
                    * UFG::UITiledMapMath::MapRangeScaleAdjustment;
      BYTE5(v2->mNULL.mChild[0]) |= BYTE2(v2[1].mRoot.mChild[1]) != 0;
      BYTE2(v2[1].mRoot.mChild[1]) = 0;
      v5 = (UFG::UIMapBlipGraphic *)v2[1].mNULL.mChild[1];
      BYTE5(v2->mNULL.mChild[0]) |= *(float *)&v4 != *(float *)&v2[1].mRoot.mUID;
      v2[1].mRoot.mUID = v4;
      if ( v5 )
        UFG::UIMapBlipGraphic::RemovePoly(v5, RangePoly);
      v6 = BYTE3(v3[1].mRoot.mChild[1]) == 0;
      v7 = (UFG::UIMapBlipGraphic *)v3[1].mNULL.mChild[1];
      BYTE3(v3[1].mRoot.mChild[1]) = 0;
      BYTE5(v3->mNULL.mChild[0]) |= !v6;
      if ( v7 )
        UFG::UIMapBlipGraphic::RemovePoly(v7, InteriorRangePoly);
    }
  }
}

// File Line: 553
// RVA: 0xBE7C0
void __fastcall UFG::UIMapBlipManager::ChangeIconRadius(UFG::UIMapBlipManager *this, unsigned int blip_id, float radius, unsigned int color, float alpha)
{
  unsigned int v5; // ebx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qColour *v7; // r9
  UFG::UIMapBlip *v8; // rcx
  float alphaFactor; // xmm0_4
  float v10; // [rsp+30h] [rbp-28h]
  float v11; // [rsp+34h] [rbp-24h]
  float v12; // [rsp+38h] [rbp-20h]
  float v13; // [rsp+3Ch] [rbp-1Ch]

  if ( blip_id )
  {
    v5 = color;
    v6 = UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, blip_id);
    if ( v6 )
    {
      if ( v5 )
      {
        v7 = (UFG::qColour *)&v10;
        v8 = (UFG::UIMapBlip *)v6;
        v10 = (float)(v5 >> 24) * 0.0039215689;
        v11 = (float)BYTE2(v5) * 0.0039215689;
        v12 = (float)BYTE1(v5) * 0.0039215689;
        alphaFactor = alpha;
        v13 = (float)(unsigned __int8)v5 * 0.0039215689;
      }
      else
      {
        alphaFactor = *(float *)&FLOAT_1_0;
        v8 = (UFG::UIMapBlip *)v6;
        v7 = (UFG::qColour *)&v6->mNULL.mChild[1][2];
      }
      UFG::UIMapBlip::SetRange(v8, 1, radius, v7, alphaFactor);
    }
  }
}

// File Line: 599
// RVA: 0xCBDB0
void __fastcall UFG::UIMapBlipManager::UnselectAllObjectiveBlips(UFG::UIMapBlipManager *this)
{
  signed int v1; // eax
  __int64 v2; // rbp
  UFG::UIMapBlipManager *v3; // rsi
  UFG::qPropertySet **v4; // r9
  UFG::qPropertySet **v5; // rdi
  signed __int64 v6; // rax
  int v7; // edx
  signed __int64 v8; // r8
  UFG::qPropertySet *v9; // r10
  UFG::qPropertySet *v10; // r11
  UFG::qPropertySet *v11; // r10
  UFG::qPropertySet *v12; // r10
  UFG::qPropertySet **v13; // rbx
  UFG::qPropertySet **i; // rdx
  unsigned int v15; // er8
  UFG::qPropertySet *v16; // rax
  __int64 v17; // rax
  UFG::qPropertySet *v18; // rax
  UFG::qPropertySet *v19; // r8
  UFG::UIMapBlip *v20; // rdx
  bool v21; // zf

  v1 = this->mIconList.mSortedIcons.size;
  v2 = 0i64;
  v3 = this;
  if ( v1 > 0 )
  {
    do
    {
      if ( v3->mIconList.mNeedToSort )
      {
        v4 = (UFG::qPropertySet **)v3->mIconList.mSortedIcons.p;
        v5 = &v4[v1 - 1i64];
        v6 = 8 * (v1 - 1i64) >> 3;
        v7 = v6 + 1;
        if ( (signed int)v6 + 1 < 32 )
        {
          if ( v7 > 1 )
            UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
              (UFG::qPropertySet **)v3->mIconList.mSortedIcons.p,
              v7,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        }
        else
        {
          v8 = (signed __int64)&v4[v6 / 2];
          v9 = *(UFG::qPropertySet **)v8;
          if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) < *(_DWORD *)((*v4)->mDefaultBits.mOffset + 96) )
          {
            *(_QWORD *)v8 = *v4;
            *v4 = v9;
          }
          v10 = *v5;
          if ( *(_DWORD *)((*v5)->mDefaultBits.mOffset + 96) < *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) )
          {
            *v5 = *(UFG::qPropertySet **)v8;
            *(_QWORD *)v8 = v10;
          }
          v11 = *(UFG::qPropertySet **)v8;
          if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) < *(_DWORD *)((*v4)->mDefaultBits.mOffset + 96) )
          {
            *(_QWORD *)v8 = *v4;
            *v4 = v11;
          }
          v12 = *(UFG::qPropertySet **)v8;
          v13 = v4;
          for ( i = v5; v13 <= i; ++v13 )
          {
            v15 = *(_DWORD *)(v12->mDefaultBits.mOffset + 96);
            if ( *(_DWORD *)((*v13)->mDefaultBits.mOffset + 96) < v15 )
            {
              do
              {
                if ( v13 >= v5 )
                  break;
                v16 = v13[1];
                ++v13;
              }
              while ( *(_DWORD *)(v16->mDefaultBits.mOffset + 96) < v15 );
            }
            if ( v15 < *(_DWORD *)((*i)->mDefaultBits.mOffset + 96) )
            {
              do
              {
                if ( v4 >= i )
                  break;
                v17 = (__int64)*(i - 1);
                --i;
              }
              while ( v15 < *(_DWORD *)(*(_QWORD *)(v17 + 48) + 96i64) );
            }
            if ( v13 > i )
              break;
            v18 = *i;
            v19 = *v13;
            --i;
            *v13 = v18;
            i[1] = v19;
          }
          if ( v4 < i )
            UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
              v4,
              i,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
          if ( v13 < v5 )
            UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
              v13,
              v5,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        }
        v3->mIconList.mNeedToSort = 0;
      }
      v20 = v3->mIconList.mSortedIcons.p[v2];
      if ( v20 )
      {
        v21 = v20->mShouldStopBlink == 0;
        v20->mShouldStopBlink = 1;
        v20->mChanged |= v21;
        v21 = v20->mIsSelectedObjective == 0;
        v20->mIsSelectedObjective = 0;
        v20->mChanged |= !v21;
      }
      v1 = v3->mIconList.mSortedIcons.size;
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (signed int)v2 < v1 );
  }
}

// File Line: 614
// RVA: 0xCA250
void __fastcall UFG::UIMapBlipManager::ResetObjectiveHighlight(UFG::UIMapBlipManager *this)
{
  signed int v1; // eax
  __int64 v2; // rbp
  UFG::UIMapBlipManager *v3; // rsi
  UFG::qPropertySet **v4; // r9
  UFG::qPropertySet **v5; // rdi
  signed __int64 v6; // rax
  int v7; // edx
  signed __int64 v8; // r8
  UFG::qPropertySet *v9; // r10
  UFG::qPropertySet *v10; // r11
  UFG::qPropertySet *v11; // r10
  UFG::qPropertySet *v12; // r10
  UFG::qPropertySet **v13; // rbx
  UFG::qPropertySet **i; // rdx
  unsigned int v15; // er8
  UFG::qPropertySet *v16; // rax
  __int64 v17; // rax
  UFG::qPropertySet *v18; // rax
  UFG::qPropertySet *v19; // r8
  UFG::UIMapBlip *v20; // rdx

  v1 = this->mIconList.mSortedIcons.size;
  v2 = 0i64;
  v3 = this;
  if ( v1 > 0 )
  {
    do
    {
      if ( v3->mIconList.mNeedToSort )
      {
        v4 = (UFG::qPropertySet **)v3->mIconList.mSortedIcons.p;
        v5 = &v4[v1 - 1i64];
        v6 = 8 * (v1 - 1i64) >> 3;
        v7 = v6 + 1;
        if ( (signed int)v6 + 1 < 32 )
        {
          if ( v7 > 1 )
            UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
              (UFG::qPropertySet **)v3->mIconList.mSortedIcons.p,
              v7,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        }
        else
        {
          v8 = (signed __int64)&v4[v6 / 2];
          v9 = *(UFG::qPropertySet **)v8;
          if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) < *(_DWORD *)((*v4)->mDefaultBits.mOffset + 96) )
          {
            *(_QWORD *)v8 = *v4;
            *v4 = v9;
          }
          v10 = *v5;
          if ( *(_DWORD *)((*v5)->mDefaultBits.mOffset + 96) < *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) )
          {
            *v5 = *(UFG::qPropertySet **)v8;
            *(_QWORD *)v8 = v10;
          }
          v11 = *(UFG::qPropertySet **)v8;
          if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v8 + 48i64) + 96i64) < *(_DWORD *)((*v4)->mDefaultBits.mOffset + 96) )
          {
            *(_QWORD *)v8 = *v4;
            *v4 = v11;
          }
          v12 = *(UFG::qPropertySet **)v8;
          v13 = v4;
          for ( i = v5; v13 <= i; ++v13 )
          {
            v15 = *(_DWORD *)(v12->mDefaultBits.mOffset + 96);
            if ( *(_DWORD *)((*v13)->mDefaultBits.mOffset + 96) < v15 )
            {
              do
              {
                if ( v13 >= v5 )
                  break;
                v16 = v13[1];
                ++v13;
              }
              while ( *(_DWORD *)(v16->mDefaultBits.mOffset + 96) < v15 );
            }
            if ( v15 < *(_DWORD *)((*i)->mDefaultBits.mOffset + 96) )
            {
              do
              {
                if ( v4 >= i )
                  break;
                v17 = (__int64)*(i - 1);
                --i;
              }
              while ( v15 < *(_DWORD *)(*(_QWORD *)(v17 + 48) + 96i64) );
            }
            if ( v13 > i )
              break;
            v18 = *i;
            v19 = *v13;
            --i;
            *v13 = v18;
            i[1] = v19;
          }
          if ( v4 < i )
            UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
              v4,
              i,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
          if ( v13 < v5 )
            UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
              v13,
              v5,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        }
        v3->mIconList.mNeedToSort = 0;
      }
      v20 = v3->mIconList.mSortedIcons.p[v2];
      if ( v20 )
        v20->mHasObjectiveHighlight = 0;
      v1 = v3->mIconList.mSortedIcons.size;
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (signed int)v2 < v1 );
  }
}

// File Line: 628
// RVA: 0xCAE20
void __fastcall UFG::UIMapBlipManager::SetMaxNumIcons(UFG::UIMapBlipManager *this, int iconLimit)
{
  if ( iconLimit > 0 && iconLimit > (signed int)this->mIconList.mSortedIcons.size )
    this->mMaxNumIcons = iconLimit;
}

// File Line: 639
// RVA: 0xC6370
void __fastcall UFG::UIMapBlipManager::PopulateAmbientBlips(UFG::UIMapBlipManager *this)
{
  UFG::UIMapBlipManager *v1; // r14
  UFG::UIAmbientMapBlipManager *v2; // rbp
  __int64 v3; // rsi
  __int64 v4; // rbx
  UFG::UIAmbientMapBlipData *v5; // rdi
  const char *v6; // rax
  UFG::UIMapBlip *v7; // rax

  v1 = this;
  if ( !this->mAmbientBlipsPopulated )
  {
    this->mAmbientBlipsPopulated = 1;
    v2 = UFG::UIAmbientMapBlipManager::getInstance();
    v3 = v2->mCount;
    if ( v3 > 0 )
    {
      v4 = 0i64;
      do
      {
        v5 = &v2->mData.p[v4];
        if ( v5 )
        {
          v6 = UFG::UIAmbientMapBlipData::GetType(v5);
          v7 = UFG::UIMapBlipManager::CreateIcon(
                 v1,
                 v5->mID.mUID,
                 v6,
                 v5->mPosition.x,
                 v5->mPosition.y,
                 v5->mPosition.y);
          if ( v7 )
            v7->mIsAmbient = 1;
        }
        ++v4;
        --v3;
      }
      while ( v3 );
    }
  }
}

// File Line: 663
// RVA: 0xC4D90
char __fastcall UFG::UIMapBlipManager::HasBlipType(UFG::UIMapBlipManager *this, UFG::qSymbolUC *iconType)
{
  signed int v2; // eax
  __int64 v3; // rbp
  UFG::qSymbolUC *v4; // r14
  UFG::UIMapBlipManager *v5; // rsi
  UFG::qPropertySet **v6; // r9
  UFG::qPropertySet **v7; // rdi
  signed __int64 v8; // rax
  int v9; // edx
  signed __int64 v10; // r8
  UFG::qPropertySet *v11; // r10
  UFG::qPropertySet *v12; // r11
  UFG::qPropertySet *v13; // r10
  UFG::qPropertySet *v14; // r10
  UFG::qPropertySet **v15; // rbx
  UFG::qPropertySet **i; // rdx
  unsigned int v17; // er8
  UFG::qPropertySet *v18; // rax
  __int64 v19; // rax
  UFG::qPropertySet *v20; // rax
  UFG::qPropertySet *v21; // r8
  UFG::UIMapBlip *v22; // rcx

  v2 = this->mIconList.mSortedIcons.size;
  v3 = 0i64;
  v4 = iconType;
  v5 = this;
  if ( v2 <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v5->mIconList.mNeedToSort )
    {
      v6 = (UFG::qPropertySet **)v5->mIconList.mSortedIcons.p;
      v7 = &v6[v2 - 1i64];
      v8 = 8 * (v2 - 1i64) >> 3;
      v9 = v8 + 1;
      if ( (signed int)v8 + 1 < 32 )
      {
        if ( v9 > 1 )
          UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
            (UFG::qPropertySet **)v5->mIconList.mSortedIcons.p,
            v9,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      else
      {
        v10 = (signed __int64)&v6[v8 / 2];
        v11 = *(UFG::qPropertySet **)v10;
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v10 + 48i64) + 96i64) < *(_DWORD *)((*v6)->mDefaultBits.mOffset + 96) )
        {
          *(_QWORD *)v10 = *v6;
          *v6 = v11;
        }
        v12 = *v7;
        if ( *(_DWORD *)((*v7)->mDefaultBits.mOffset + 96) < *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v10 + 48i64) + 96i64) )
        {
          *v7 = *(UFG::qPropertySet **)v10;
          *(_QWORD *)v10 = v12;
        }
        v13 = *(UFG::qPropertySet **)v10;
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v10 + 48i64) + 96i64) < *(_DWORD *)((*v6)->mDefaultBits.mOffset + 96) )
        {
          *(_QWORD *)v10 = *v6;
          *v6 = v13;
        }
        v14 = *(UFG::qPropertySet **)v10;
        v15 = v6;
        for ( i = v7; v15 <= i; ++v15 )
        {
          v17 = *(_DWORD *)(v14->mDefaultBits.mOffset + 96);
          if ( *(_DWORD *)((*v15)->mDefaultBits.mOffset + 96) < v17 )
          {
            do
            {
              if ( v15 >= v7 )
                break;
              v18 = v15[1];
              ++v15;
            }
            while ( *(_DWORD *)(v18->mDefaultBits.mOffset + 96) < v17 );
          }
          if ( v17 < *(_DWORD *)((*i)->mDefaultBits.mOffset + 96) )
          {
            do
            {
              if ( v6 >= i )
                break;
              v19 = (__int64)*(i - 1);
              --i;
            }
            while ( v17 < *(_DWORD *)(*(_QWORD *)(v19 + 48) + 96i64) );
          }
          if ( v15 > i )
            break;
          v20 = *i;
          v21 = *v15;
          --i;
          *v15 = v20;
          i[1] = v21;
        }
        if ( v6 < i )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v6,
            i,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        if ( v15 < v7 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v15,
            v7,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      v5->mIconList.mNeedToSort = 0;
    }
    v22 = v5->mIconList.mSortedIcons.p[v3];
    if ( v22 )
    {
      if ( v22->mType->TypeNameSymbol.mUID == v4->mUID )
        break;
    }
    v2 = v5->mIconList.mSortedIcons.size;
    v3 = (unsigned int)(v3 + 1);
    if ( (signed int)v3 >= v2 )
      return 0;
  }
  return 1;
}ist.mSortedIcons.s

// File Line: 683
// RVA: 0xCDFE0
void __fastcall UFG::UIMapBlipManager::UpdatePlayerArrow(UFG::UIMapBlipManager *this, int x, int y, float rot, bool pulseAnimation)
{
  unsigned int v5; // edi
  unsigned int v6; // esi
  UFG::UIMapBlipManager *v7; // rbx
  void (***v8)(void); // rcx
  __int64 v9; // rdx

  v5 = y;
  v6 = x;
  v7 = this;
  if ( !this->mPlayerArrowIcon )
    this->mPlayerArrowIcon = UFG::UIMapBlipGraphicFactory::GetNativeIconInstance(
                               &UFG::UIMapBlipGraphicFactory::Singleton,
                               (UFG::qSymbol *)&UIBlipIcon_Player_Arrow.mUID);
  v8 = (void (***)(void))v7->mPlayerArrowIcon;
  if ( v8 )
  {
    (**v8)();
    ((void (__fastcall *)(UFG::UIMapBlipGraphic *, __int64, _QWORD, _QWORD))v7->mPlayerArrowIcon->vfptr->UpdateTransform)(
      v7->mPlayerArrowIcon,
      v9,
      v6,
      v5);
    if ( pulseAnimation )
    {
      ((void (*)(void))v7->mPlayerArrowIcon->vfptr->SetBlink)();
      ((void (*)(void))v7->mPlayerArrowIcon->vfptr->UpdateAnimation)();
    }
  }
}

// File Line: 705
// RVA: 0xC0550
UFG::UIMapBlip *__fastcall UFG::UIMapBlipManager::FindNearestVisibleIcon(UFG::UIMapBlipManager *this, UFG::qVector3 *pos, UFG::UITiledMapMath *geo)
{
  UFG::qVector3 *v3; // r12
  UFG::UIMapBlipManager *v4; // rsi
  UFG::UITiledMapMath *v5; // r15
  float *v6; // rbp
  signed int v7; // eax
  signed int i; // er14
  UFG::qPropertySet **v9; // r9
  UFG::qPropertySet **v10; // rdi
  signed __int64 v11; // rax
  int v12; // edx
  signed __int64 v13; // r8
  UFG::qPropertySet *v14; // r10
  UFG::qPropertySet *v15; // r10
  UFG::qPropertySet *v16; // r11
  UFG::qPropertySet *v17; // r10
  UFG::qPropertySet *v18; // r10
  UFG::qPropertySet **v19; // rbx
  UFG::qPropertySet **j; // rdx
  unsigned int v21; // er8
  UFG::qPropertySet *v22; // rax
  __int64 v23; // rax
  UFG::qPropertySet *v24; // rax
  UFG::qPropertySet *v25; // r8
  UFG::UIMapBlip **v26; // rax
  UFG::UIMapBlip *v27; // rbx
  float v28; // xmm3_4
  UFG::UIHKMinimapBlipType *v29; // rax
  UFG::qVector3 posa; // [rsp+20h] [rbp-68h]
  UFG::qVector3 dir; // [rsp+30h] [rbp-58h]

  v3 = pos;
  v4 = this;
  v5 = geo;
  v6 = 0i64;
  UFG::UI::GetPlayerWorldPosition(&posa, &dir);
  v7 = v4->mIconList.mSortedIcons.size;
  for ( i = 0; i < v7; ++i )
  {
    if ( v4->mIconList.mNeedToSort )
    {
      v9 = (UFG::qPropertySet **)v4->mIconList.mSortedIcons.p;
      v10 = &v9[v7 - 1i64];
      v11 = 8 * (v7 - 1i64) >> 3;
      v12 = v11 + 1;
      if ( (signed int)v11 + 1 < 32 )
      {
        if ( v12 > 1 )
          UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
            (UFG::qPropertySet **)v4->mIconList.mSortedIcons.p,
            v12,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      else
      {
        v13 = v11 / 2;
        v14 = v9[v11 / 2];
        if ( *(_DWORD *)(v14->mDefaultBits.mOffset + 96) < *(_DWORD *)((*v9)->mDefaultBits.mOffset + 96) )
        {
          v9[v13] = *v9;
          *v9 = v14;
        }
        v15 = v9[v13];
        v16 = *v10;
        if ( *(_DWORD *)((*v10)->mDefaultBits.mOffset + 96) < *(_DWORD *)(v15->mDefaultBits.mOffset + 96) )
        {
          *v10 = v15;
          v9[v13] = v16;
        }
        v17 = v9[v13];
        if ( *(_DWORD *)(v17->mDefaultBits.mOffset + 96) < *(_DWORD *)((*v9)->mDefaultBits.mOffset + 96) )
        {
          v9[v13] = *v9;
          *v9 = v17;
        }
        v18 = v9[v13];
        v19 = v9;
        for ( j = v10; v19 <= j; ++v19 )
        {
          v21 = *(_DWORD *)(v18->mDefaultBits.mOffset + 96);
          if ( *(_DWORD *)((*v19)->mDefaultBits.mOffset + 96) < v21 )
          {
            do
            {
              if ( v19 >= v10 )
                break;
              v22 = v19[1];
              ++v19;
            }
            while ( *(_DWORD *)(v22->mDefaultBits.mOffset + 96) < v21 );
          }
          if ( v21 < *(_DWORD *)((*j)->mDefaultBits.mOffset + 96) )
          {
            do
            {
              if ( v9 >= j )
                break;
              v23 = (__int64)*(j - 1);
              --j;
            }
            while ( v21 < *(_DWORD *)(*(_QWORD *)(v23 + 48) + 96i64) );
          }
          if ( v19 > j )
            break;
          v24 = *j;
          v25 = *v19;
          --j;
          *v19 = v24;
          j[1] = v25;
        }
        if ( v9 < j )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v9,
            j,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        if ( v19 < v10 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v19,
            v10,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      v4->mIconList.mNeedToSort = 0;
    }
    v26 = v4->mIconList.mSortedIcons.p;
    v27 = v26[i];
    if ( v27 )
    {
      if ( !v6 )
        v6 = (float *)v26[i];
      v28 = v27->pos.z;
      if ( (float)((float)((float)((float)(v27->pos.y - v3->y) * (float)(v27->pos.y - v3->y))
                         + (float)((float)(v27->pos.x - v3->x) * (float)(v27->pos.x - v3->x)))
                 + (float)((float)(v28 - v3->z) * (float)(v28 - v3->z))) < (float)((float)((float)((float)(v6[17] - v3->y)
                                                                                                 * (float)(v6[17] - v3->y))
                                                                                         + (float)((float)(v6[16] - v3->x)
                                                                                                 * (float)(v6[16] - v3->x)))
                                                                                 + (float)((float)(v6[18] - v3->z)
                                                                                         * (float)(v6[18] - v3->z))) )
      {
        if ( v27->mVisible )
        {
          v29 = v27->mType;
          if ( v29 )
          {
            if ( v29->IsVisible && UFG::UIMapBlip::GetAlpha(v27, &posa, v5) > 0.0099999998 )
              v6 = (float *)v27;
          }
        }
      }
    }
    v7 = v4->mIconList.mSortedIcons.size;
  }
  return (UFG::UIMapBlip *)v6;
}

