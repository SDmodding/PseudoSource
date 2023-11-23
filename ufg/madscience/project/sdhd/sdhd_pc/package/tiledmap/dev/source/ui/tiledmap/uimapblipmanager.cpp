// File Line: 26
// RVA: 0x14595B0
__int64 dynamic_initializer_for__UFG::UIMapBlipManager::gPrintChannel__()
{
  UFG::qString::qString(&stru_142033FA0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIMapBlipManager::gPrintChannel__);
}

// File Line: 27
// RVA: 0x14595E0
__int64 dynamic_initializer_for__UFG::UIMapBlipManager::gSpamChannel__()
{
  UFG::qString::qString(&stru_142033FF0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIMapBlipManager::gSpamChannel__);
}

// File Line: 37
// RVA: 0xBD750
void __fastcall UFG::UIMapBlipList::~UIMapBlipList(UFG::UIMapBlipList *this)
{
  UFG::UIMapBlip **p; // rcx

  this->vfptr = (UFG::UIMapBlipListVtbl *)&UFG::UIMapBlipList::`vftable;
  UFG::UIMapBlipList::DeleteAll(this);
  p = this->mSortedIcons.p;
  if ( p )
    operator delete[](p);
  this->mSortedIcons.p = 0i64;
  *(_QWORD *)&this->mSortedIcons.size = 0i64;
  UFG::qTreeRB<UFG::UIMapBlip,UFG::UIMapBlip,1>::~qTreeRB<UFG::UIMapBlip,UFG::UIMapBlip,1>(&this->mIconData);
}

// File Line: 43
// RVA: 0xC0B60
UFG::qBaseTreeRB *__fastcall UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem *this, unsigned int guid)
{
  if ( guid )
    return UFG::qBaseTreeRB::Get(&this->mCollisionModels.mTree, guid);
  else
    return 0i64;
}

// File Line: 49
// RVA: 0xBE100
void __fastcall UFG::UIMapBlipList::Add(UFG::UIMapBlipList *this, UFG::UIMapBlip *icon)
{
  __int64 size; // r14
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::UIMapBlip **p; // rax

  UFG::qBaseTreeRB::Add(&this->mIconData.mTree, &icon->mNode);
  size = this->mSortedIcons.size;
  capacity = this->mSortedIcons.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mSortedIcons,
      v7,
      "qArray.Add");
  }
  p = this->mSortedIcons.p;
  this->mSortedIcons.size = v6;
  p[size] = icon;
  this->mNeedToSort = 1;
}

// File Line: 57
// RVA: 0xC7110
void __fastcall UFG::UIMapBlipList::Remove(UFG::UIMapBlipList *this, UFG::qBaseNodeVariableRB<unsigned __int64> *icon)
{
  unsigned int size; // ecx
  __int64 v5; // r8
  UFG::UIMapBlip **i; // rax
  unsigned int v7; // eax

  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mIconData,
    icon);
  size = this->mSortedIcons.size;
  v5 = 0i64;
  if ( size )
  {
    for ( i = this->mSortedIcons.p; icon != (UFG::qBaseNodeVariableRB<unsigned __int64> *)*i; ++i )
    {
      v5 = (unsigned int)(v5 + 1);
      if ( (unsigned int)v5 >= size )
        return;
    }
    if ( (_DWORD)v5 != -1 )
    {
      this->mSortedIcons.p[v5] = this->mSortedIcons.p[size - 1];
      v7 = this->mSortedIcons.size;
      if ( v7 > 1 )
        this->mSortedIcons.size = v7 - 1;
      else
        this->mSortedIcons.size = 0;
      this->mNeedToSort = 1;
    }
  }
}

// File Line: 76
// RVA: 0xBEDD0
void __fastcall UFG::UIMapBlipList::DeleteAll(UFG::UIMapBlipList *this)
{
  Render::SkinningCacheNode *Head; // rbx
  UFG::UIMapBlip **p; // rcx

  while ( this->mIconData.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mIconData);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mIconData,
      &Head->mNode);
    if ( Head )
    {
      UFG::UIMapBlip::~UIMapBlip((UFG::UIMapBlip *)Head);
      operator delete[](Head);
    }
  }
  p = this->mSortedIcons.p;
  if ( p )
    operator delete[](p);
  this->mSortedIcons.p = 0i64;
  *(_QWORD *)&this->mSortedIcons.size = 0i64;
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
  this->mIconList.vfptr = (UFG::UIMapBlipListVtbl *)&UFG::UIMapBlipList::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mIconList.mIconData.mTree);
  this->mIconList.mSortedIcons.p = 0i64;
  *(_QWORD *)&this->mIconList.mSortedIcons.size = 0i64;
  this->mIconList.mNeedToSort = 1;
  this->mMaxNumIcons = 500;
  this->mAmbientBlipsPopulated = 0;
  this->mPlayerArrowIcon = 0i64;
}

// File Line: 109
// RVA: 0xBD7A0
void __fastcall UFG::UIMapBlipManager::~UIMapBlipManager(UFG::UIMapBlipManager *this)
{
  UFG::UIMapBlipGraphic *mPlayerArrowIcon; // r14
  void **v3; // rbx
  __int64 v4; // rsi
  UFG::UIMapBlip **p; // rcx

  UFG::UIMapBlipList::DeleteAll(&this->mIconList);
  mPlayerArrowIcon = this->mPlayerArrowIcon;
  if ( mPlayerArrowIcon )
  {
    mPlayerArrowIcon->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable;
    v3 = (void **)&mPlayerArrowIcon->mPolys[1];
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
    operator delete[](mPlayerArrowIcon);
  }
  this->mIconList.vfptr = (UFG::UIMapBlipListVtbl *)&UFG::UIMapBlipList::`vftable;
  UFG::UIMapBlipList::DeleteAll(&this->mIconList);
  p = this->mIconList.mSortedIcons.p;
  if ( p )
    operator delete[](p);
  this->mIconList.mSortedIcons.p = 0i64;
  *(_QWORD *)&this->mIconList.mSortedIcons.size = 0i64;
  UFG::qTreeRB<UFG::UIMapBlip,UFG::UIMapBlip,1>::~qTreeRB<UFG::UIMapBlip,UFG::UIMapBlip,1>(&this->mIconList.mIconData);
}

// File Line: 189
// RVA: 0xBE930
void __fastcall UFG::UIMapBlipManager::Clear(UFG::UIMapBlipManager *this)
{
  UFG::UIMapBlipList::DeleteAll(&this->mIconList);
  this->mAmbientBlipsPopulated = 0;
}

// File Line: 196
// RVA: 0xC6410
void __fastcall UFG::UIMapBlipManager::PopulateWorldMap(
        UFG::UIMapBlipManager *this,
        UFG::UIScreen *screen,
        UFG::UIMapBlipManager *clone,
        UFG::qArray<UFG::qSymbolUC,0> *validTypes)
{
  __int64 i; // r15
  UFG::qSymbolUC *p; // r12
  __int64 v8; // r14
  UFG::qPropertySet **v9; // r10
  UFG::qPropertySet **v10; // rdi
  __int64 v11; // rax
  int v12; // ecx
  __int64 v13; // r8
  UFG::qPropertySet *v14; // r9
  UFG::qPropertySet *v15; // r9
  UFG::qPropertySet *v16; // r11
  UFG::qPropertySet *v17; // r9
  UFG::qPropertySet *v18; // r11
  UFG::qPropertySet **v19; // rbx
  UFG::qPropertySet **k; // r9
  unsigned int v21; // edx
  UFG::qPropertySet *v22; // rax
  __int64 v23; // rax
  UFG::qPropertySet *v24; // rax
  UFG::qPropertySet *v25; // rdx
  __int64 v26; // r11
  int v27; // edi
  UFG::qPropertySet *v28; // rbx
  int v29; // r8d
  __int64 j; // rdx
  UFG::qPropertySet *v31; // r9
  UFG::UIMapBlip *v32; // rdx
  UFG::UIHKMinimapBlipType *mType; // rbx
  UFG::qBaseTreeRB *IconFromClone; // rax
  UFG::qArray<UFG::qSymbolUC,0> *v35; // [rsp+68h] [rbp+20h]

  if ( clone )
  {
    v35 = validTypes;
    clone->mAmbientBlipsPopulated |= this->mAmbientBlipsPopulated;
    for ( i = validTypes->size - 1; i >= 0; --i )
    {
      p = validTypes->p;
      v8 = 0i64;
      if ( (int)clone->mIconList.mSortedIcons.size > 0 )
      {
        do
        {
          if ( clone->mIconList.mNeedToSort )
          {
            v9 = (UFG::qPropertySet **)clone->mIconList.mSortedIcons.p;
            v10 = &v9[(int)clone->mIconList.mSortedIcons.size - 1];
            v11 = (8 * ((int)clone->mIconList.mSortedIcons.size - 1i64)) >> 3;
            v12 = v11 + 1;
            if ( (int)v11 + 1 < 32 )
            {
              if ( v12 > 1 )
              {
                v26 = 1i64;
                if ( v12 > 1i64 )
                {
                  v27 = 0;
                  do
                  {
                    v28 = v9[v26];
                    v29 = v27;
                    for ( j = v26 - 1; v29 >= 0; --v29 )
                    {
                      v31 = v9[j];
                      if ( *(_DWORD *)(v28->mDefaultBits.mOffset + 96) >= *(_DWORD *)(v31->mDefaultBits.mOffset + 96) )
                        break;
                      v9[j-- + 1] = v31;
                    }
                    ++v26;
                    ++v27;
                    v9[j + 1] = v28;
                  }
                  while ( v26 < v12 );
                }
              }
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
              for ( k = v10; v19 <= k; ++v19 )
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
                if ( v21 < *(_DWORD *)((*k)->mDefaultBits.mOffset + 96) )
                {
                  do
                  {
                    if ( v9 >= k )
                      break;
                    v23 = (__int64)*--k;
                  }
                  while ( v21 < *(_DWORD *)(*(_QWORD *)(v23 + 48) + 96i64) );
                }
                if ( v19 > k )
                  break;
                v24 = *k;
                v25 = *v19;
                --k;
                *v19 = v24;
                k[1] = v25;
              }
              if ( v9 < k )
                UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
                  v9,
                  k,
                  (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
              if ( v19 < v10 )
                UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
                  v19,
                  v10,
                  (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
            }
            clone->mIconList.mNeedToSort = 0;
          }
          v32 = clone->mIconList.mSortedIcons.p[v8];
          if ( v32 )
          {
            mType = v32->mType;
            if ( mType )
            {
              if ( p[i].mUID == mType->TypeNameSymbol.mUID )
              {
                IconFromClone = UFG::UIMapBlipManager::CreateIconFromClone(this, v32);
                LOBYTE(IconFromClone->mNULL.mParent) = 0;
                if ( !mType->IsDistanceFilteredOnWorldMap )
                {
                  BYTE3(IconFromClone->mNULL.mParent) = 1;
                  HIDWORD(IconFromClone->mNULL.mParent) = 1232348160;
                }
              }
            }
          }
          v8 = (unsigned int)(v8 + 1);
        }
        while ( (int)v8 < (signed int)clone->mIconList.mSortedIcons.size );
        validTypes = v35;
      }
    }
  }
}

// File Line: 241
// RVA: 0xC4BA0
void __fastcall UFG::UIMapBlipManager::HandleScreenInit(UFG::UIMapBlipManager *this)
{
  signed int size; // eax
  __int64 i; // rbp
  UFG::qPropertySet **p; // r9
  UFG::qPropertySet **v5; // rdi
  __int64 v6; // rax
  int v7; // edx
  UFG::qPropertySet **v8; // r8
  UFG::qPropertySet *v9; // r10
  UFG::qPropertySet *v10; // r11
  UFG::qPropertySet *v11; // r10
  UFG::qPropertySet *v12; // r10
  UFG::qPropertySet **v13; // rbx
  UFG::qPropertySet **j; // rdx
  unsigned int v15; // r8d
  UFG::qPropertySet *v16; // rax
  __int64 v17; // rax
  UFG::qPropertySet *v18; // rax
  UFG::qPropertySet *v19; // r8
  UFG::UIMapBlip *v20; // rdx

  size = this->mIconList.mSortedIcons.size;
  for ( i = 0i64; (int)i < size; i = (unsigned int)(i + 1) )
  {
    if ( this->mIconList.mNeedToSort )
    {
      p = (UFG::qPropertySet **)this->mIconList.mSortedIcons.p;
      v5 = &p[size - 1];
      v6 = (8 * (size - 1i64)) >> 3;
      v7 = v6 + 1;
      if ( (int)v6 + 1 < 32 )
      {
        if ( v7 > 1 )
          UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
            (UFG::qPropertySet **)this->mIconList.mSortedIcons.p,
            v7,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      else
      {
        v8 = &p[v6 / 2];
        v9 = *v8;
        if ( *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          *v8 = *p;
          *p = v9;
        }
        v10 = *v5;
        if ( *(_DWORD *)((*v5)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) )
        {
          *v5 = *v8;
          *v8 = v10;
        }
        v11 = *v8;
        if ( *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          *v8 = *p;
          *p = v11;
        }
        v12 = *v8;
        v13 = p;
        for ( j = v5; v13 <= j; ++v13 )
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
          if ( v15 < *(_DWORD *)((*j)->mDefaultBits.mOffset + 96) )
          {
            do
            {
              if ( p >= j )
                break;
              v17 = (__int64)*--j;
            }
            while ( v15 < *(_DWORD *)(*(_QWORD *)(v17 + 48) + 96i64) );
          }
          if ( v13 > j )
            break;
          v18 = *j;
          v19 = *v13;
          --j;
          *v13 = v18;
          j[1] = v19;
        }
        if ( p < j )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            p,
            j,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        if ( v13 < v5 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v13,
            v5,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      this->mIconList.mNeedToSort = 0;
    }
    v20 = this->mIconList.mSortedIcons.p[i];
    if ( v20 )
      v20->mAltitudeStateChanged = 1;
    size = this->mIconList.mSortedIcons.size;
  }
}

// File Line: 300
// RVA: 0xCC1B0
void __fastcall UFG::UIMapBlipManager::Update(
        UFG::UIMapBlipManager *this,
        UFG::UIScreen *screen,
        float elapsed,
        UFG::qVector3 *playerPos,
        UFG::UITiledMapMath *mapGeo,
        UFG::UITiledMapMath *mapIconGeo,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeClipped,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeNotClipped,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeDoubleClipped,
        bool isIndoors,
        bool forceUpdate)
{
  unsigned int size; // eax
  signed int v12; // ebp
  __int64 v15; // rsi
  __int64 v16; // r15
  UFG::UIMapBlip **p; // rax
  UFG::UIMapBlip *v18; // rdi
  UFG::UIHKMinimapBlipType *mType; // rax
  UFG::UIMapBlipGraphic *mPlayerArrowIcon; // rcx
  signed int v21; // [rsp+40h] [rbp-38h]

  if ( screen )
  {
    size = this->mIconList.mSortedIcons.size;
    v12 = 0;
    v15 = 0i64;
    v16 = size;
    if ( size )
    {
      v21 = size - 1;
      do
      {
        if ( this->mIconList.mNeedToSort )
        {
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            (UFG::qPropertySet **)this->mIconList.mSortedIcons.p,
            (UFG::qPropertySet **)&this->mIconList.mSortedIcons.p[(int)this->mIconList.mSortedIcons.size - 1],
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
          this->mIconList.mNeedToSort = 0;
        }
        p = this->mIconList.mSortedIcons.p;
        v18 = p[v15];
        if ( v12 < v21 && this->mIconList.mNeedToSort )
        {
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            (UFG::qPropertySet **)this->mIconList.mSortedIcons.p,
            (UFG::qPropertySet **)&p[(int)this->mIconList.mSortedIcons.size - 1],
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
          this->mIconList.mNeedToSort = 0;
        }
        if ( v18 )
        {
          if ( forceUpdate )
            v18->mChanged = 1;
          UFG::UIMapBlip::Update(v18, screen, playerPos, mapGeo);
          mType = v18->mType;
          if ( mType
            && (!isIndoors || mapGeo->IsWorldMap || !mType->IsHiddenIndoors)
            && v18->mVisible
            && mType->IsVisible )
          {
            UFG::UIMapBlip::UpdateNative(
              v18,
              playerPos,
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
    mPlayerArrowIcon = this->mPlayerArrowIcon;
    if ( mPlayerArrowIcon )
      UFG::UIMapBlipGraphic::QueueIconToRender(
        mPlayerArrowIcon,
        polyListNativeClipped,
        polyListNativeNotClipped,
        polyListNativeDoubleClipped);
  }
}

// File Line: 358
// RVA: 0xBEA40
UFG::UIMapBlip *__fastcall UFG::UIMapBlipManager::CreateIcon(
        UFG::UIMapBlipManager *this,
        unsigned int uid,
        const char *iconType,
        float xPos,
        float yPos)
{
  float v5; // xmm0_4
  UFG::UIMapBlip *v10; // rax
  UFG::UIMapBlip *v11; // rbx
  UFG::UIMapBlipTypeManager *Instance; // rax
  UFG::UIHKMinimapBlipType *Type; // rax
  __m128 y_low; // xmm2
  float v15; // xmm3_4
  UFG::qSymbolUC v17; // [rsp+68h] [rbp+10h] BYREF

  if ( uid - 1 > 0xFFFFFFFD
    || !iconType
    || !*iconType
    || UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, uid)
    || (signed int)this->mIconList.mSortedIcons.size >= this->mMaxNumIcons )
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
    v10->mNode.mUID = uid;
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
  UFG::qSymbolUC::create_from_string(&v17, iconType);
  Instance = UFG::UIMapBlipTypeManager::getInstance();
  Type = UFG::UIMapBlipTypeManager::GetType(Instance, &v17);
  UFG::UIMapBlip::SetType(v11, Type, v5);
  y_low = (__m128)LODWORD(v11->pos.y);
  v15 = yPos;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - yPos) * (float)(y_low.m128_f32[0] - yPos))
                            + (float)((float)(v11->pos.x - xPos) * (float)(v11->pos.x - xPos)))
                    + (float)(v11->pos.z * v11->pos.z);
  if ( _mm_sqrt_ps(y_low).m128_f32[0] > UFG::gSymbolPosDiff )
  {
    v11->pos.x = xPos;
    v11->pos.y = v15;
    v11->pos.z = 0.0;
    v11->mChanged = 1;
  }
  UFG::UIMapBlipList::Add(&this->mIconList, v11);
  return v11;
}

// File Line: 410
// RVA: 0xBEBD0
UFG::qBaseTreeRB *__fastcall UFG::UIMapBlipManager::CreateIconFromClone(
        UFG::UIMapBlipManager *this,
        UFG::UIMapBlip *clone)
{
  unsigned int mUID; // ebp
  char *v6; // rbx

  if ( !clone )
    return 0i64;
  mUID = clone->mNode.mUID;
  if ( mUID && UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, mUID) )
  {
    v6 = (char *)UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, mUID);
    UFG::UIMapBlip::Clone((UFG::UIMapBlip *)v6, clone);
  }
  else
  {
    if ( (signed int)this->mIconList.mSortedIcons.size >= this->mMaxNumIcons )
      return 0i64;
    v6 = UFG::qMalloc(0x80ui64, "UIMapBlip", 0i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *((_QWORD *)v6 + 1) = 0i64;
      *((_QWORD *)v6 + 2) = 0i64;
      *((_DWORD *)v6 + 6) = mUID;
      *((_DWORD *)v6 + 8) = 257;
      *(_QWORD *)(v6 + 36) = 0i64;
      *((_DWORD *)v6 + 11) = 16777472;
      *((_QWORD *)v6 + 6) = 0i64;
      *((_QWORD *)v6 + 7) = 0i64;
      *((_QWORD *)v6 + 8) = 0i64;
      *((_QWORD *)v6 + 9) = 0i64;
      *((_QWORD *)v6 + 10) = 0i64;
      *((_DWORD *)v6 + 22) = 0;
      v6[92] = 0;
      *((_QWORD *)v6 + 12) = 0i64;
      *((_WORD *)v6 + 52) = 0;
      v6[106] = 0;
      *((_QWORD *)v6 + 14) = 0i64;
      *((_QWORD *)v6 + 15) = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    if ( !v6 )
      return 0i64;
    UFG::UIMapBlip::Clone((UFG::UIMapBlip *)v6, clone);
    UFG::UIMapBlipList::Add(&this->mIconList, (UFG::UIMapBlip *)v6);
  }
  return (UFG::qBaseTreeRB *)v6;
}

// File Line: 443
// RVA: 0xC71A0
void __fastcall UFG::UIMapBlipManager::RemoveIcon(UFG::UIMapBlipManager *this, unsigned int uid)
{
  UFG::qBaseTreeRB *v3; // rax
  UFG::UIMapBlip *v4; // rbx

  if ( uid )
  {
    v3 = UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, uid);
    v4 = (UFG::UIMapBlip *)v3;
    if ( v3 )
    {
      UFG::UIMapBlipList::Remove(&this->mIconList, (UFG::qBaseNodeVariableRB<unsigned __int64> *)v3);
      UFG::UIMapBlip::~UIMapBlip(v4);
      operator delete[](v4);
    }
  }
}

// File Line: 473
// RVA: 0xBE360
void __fastcall UFG::UIMapBlipManager::AddIconRadius(
        UFG::UIMapBlipManager *this,
        unsigned int blip_id,
        float radius,
        unsigned int color,
        float alpha)
{
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseTreeRB *v7; // rbx
  UFG::qColour *v8; // r9
  UFG::UIMapBlip *v9; // rcx
  UFG::UIMapBlipGraphic *v11; // rcx
  bool v12; // al
  int v13[4]; // [rsp+30h] [rbp-28h] BYREF

  if ( blip_id )
  {
    v6 = UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, blip_id);
    v7 = v6;
    if ( v6 )
    {
      if ( color )
      {
        v8 = (UFG::qColour *)v13;
        v9 = (UFG::UIMapBlip *)v6;
        *(float *)v13 = (float)HIBYTE(color) * 0.0039215689;
        *(float *)&v13[1] = (float)BYTE2(color) * 0.0039215689;
        *(float *)&v13[2] = (float)BYTE1(color) * 0.0039215689;
        *(float *)&v13[3] = (float)(unsigned __int8)color * 0.0039215689;
      }
      else
      {
        alpha = *(float *)&FLOAT_1_0;
        v9 = (UFG::UIMapBlip *)v6;
        v8 = (UFG::qColour *)&v6->mNULL.mChild[1][2];
      }
      UFG::UIMapBlip::SetRange(v9, 1, radius, v8, alpha);
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
void __fastcall UFG::UIMapBlipManager::AddIconDonutRadius(
        UFG::UIMapBlipManager *this,
        unsigned int blip_id,
        float radius,
        float interiorRadius,
        unsigned int outerColor,
        unsigned int innerColor)
{
  UFG::qBaseTreeRB *v6; // rax
  UFG::UIMapBlip *v7; // rbx
  UFG::qColour *v8; // r9
  UFG::UIMapBlip *v9; // rcx
  UFG::qColour *p_InnerRadiusColor; // r9
  float v11; // [rsp+30h] [rbp-48h] BYREF
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
        v11 = (float)HIBYTE(outerColor) * 0.0039215689;
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
        p_InnerRadiusColor = (UFG::qColour *)&v11;
        v11 = (float)HIBYTE(innerColor) * 0.0039215689;
        v12 = (float)BYTE2(innerColor) * 0.0039215689;
        v13 = (float)BYTE1(innerColor) * 0.0039215689;
        v14 = (float)(unsigned __int8)innerColor * 0.0039215689;
      }
      else
      {
        p_InnerRadiusColor = &v7->mType->InnerRadiusColor;
      }
      UFG::UIMapBlip::SetInteriorRange(v7, 1, interiorRadius, p_InnerRadiusColor);
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
void __fastcall UFG::UIMapBlipManager::ChangeIconRadius(
        UFG::UIMapBlipManager *this,
        unsigned int blip_id,
        float radius,
        unsigned int color,
        float alpha)
{
  UFG::qBaseTreeRB *v6; // rax
  UFG::qColour *v7; // r9
  UFG::UIMapBlip *v8; // rcx
  int v10[4]; // [rsp+30h] [rbp-28h] BYREF

  if ( blip_id )
  {
    v6 = UFG::qBaseTreeRB::Get(&this->mIconList.mIconData.mTree, blip_id);
    if ( v6 )
    {
      if ( color )
      {
        v7 = (UFG::qColour *)v10;
        v8 = (UFG::UIMapBlip *)v6;
        *(float *)v10 = (float)HIBYTE(color) * 0.0039215689;
        *(float *)&v10[1] = (float)BYTE2(color) * 0.0039215689;
        *(float *)&v10[2] = (float)BYTE1(color) * 0.0039215689;
        *(float *)&v10[3] = (float)(unsigned __int8)color * 0.0039215689;
      }
      else
      {
        alpha = *(float *)&FLOAT_1_0;
        v8 = (UFG::UIMapBlip *)v6;
        v7 = (UFG::qColour *)&v6->mNULL.mChild[1][2];
      }
      UFG::UIMapBlip::SetRange(v8, 1, radius, v7, alpha);
    }
  }
}

// File Line: 599
// RVA: 0xCBDB0
void __fastcall UFG::UIMapBlipManager::UnselectAllObjectiveBlips(UFG::UIMapBlipManager *this)
{
  signed int size; // eax
  __int64 i; // rbp
  UFG::qPropertySet **p; // r9
  UFG::qPropertySet **v5; // rdi
  __int64 v6; // rax
  int v7; // edx
  UFG::qPropertySet **v8; // r8
  UFG::qPropertySet *v9; // r10
  UFG::qPropertySet *v10; // r11
  UFG::qPropertySet *v11; // r10
  UFG::qPropertySet *v12; // r10
  UFG::qPropertySet **v13; // rbx
  UFG::qPropertySet **j; // rdx
  unsigned int v15; // r8d
  UFG::qPropertySet *v16; // rax
  __int64 v17; // rax
  UFG::qPropertySet *v18; // rax
  UFG::qPropertySet *v19; // r8
  UFG::UIMapBlip *v20; // rdx
  bool v21; // zf

  size = this->mIconList.mSortedIcons.size;
  for ( i = 0i64; (int)i < size; i = (unsigned int)(i + 1) )
  {
    if ( this->mIconList.mNeedToSort )
    {
      p = (UFG::qPropertySet **)this->mIconList.mSortedIcons.p;
      v5 = &p[size - 1];
      v6 = (8 * (size - 1i64)) >> 3;
      v7 = v6 + 1;
      if ( (int)v6 + 1 < 32 )
      {
        if ( v7 > 1 )
          UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
            (UFG::qPropertySet **)this->mIconList.mSortedIcons.p,
            v7,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      else
      {
        v8 = &p[v6 / 2];
        v9 = *v8;
        if ( *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          *v8 = *p;
          *p = v9;
        }
        v10 = *v5;
        if ( *(_DWORD *)((*v5)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) )
        {
          *v5 = *v8;
          *v8 = v10;
        }
        v11 = *v8;
        if ( *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          *v8 = *p;
          *p = v11;
        }
        v12 = *v8;
        v13 = p;
        for ( j = v5; v13 <= j; ++v13 )
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
          if ( v15 < *(_DWORD *)((*j)->mDefaultBits.mOffset + 96) )
          {
            do
            {
              if ( p >= j )
                break;
              v17 = (__int64)*--j;
            }
            while ( v15 < *(_DWORD *)(*(_QWORD *)(v17 + 48) + 96i64) );
          }
          if ( v13 > j )
            break;
          v18 = *j;
          v19 = *v13;
          --j;
          *v13 = v18;
          j[1] = v19;
        }
        if ( p < j )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            p,
            j,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        if ( v13 < v5 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v13,
            v5,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      this->mIconList.mNeedToSort = 0;
    }
    v20 = this->mIconList.mSortedIcons.p[i];
    if ( v20 )
    {
      v21 = !v20->mShouldStopBlink;
      v20->mShouldStopBlink = 1;
      v20->mChanged |= v21;
      v21 = !v20->mIsSelectedObjective;
      v20->mIsSelectedObjective = 0;
      v20->mChanged |= !v21;
    }
    size = this->mIconList.mSortedIcons.size;
  }
}

// File Line: 614
// RVA: 0xCA250
void __fastcall UFG::UIMapBlipManager::ResetObjectiveHighlight(UFG::UIMapBlipManager *this)
{
  signed int size; // eax
  __int64 i; // rbp
  UFG::qPropertySet **p; // r9
  UFG::qPropertySet **v5; // rdi
  __int64 v6; // rax
  int v7; // edx
  UFG::qPropertySet **v8; // r8
  UFG::qPropertySet *v9; // r10
  UFG::qPropertySet *v10; // r11
  UFG::qPropertySet *v11; // r10
  UFG::qPropertySet *v12; // r10
  UFG::qPropertySet **v13; // rbx
  UFG::qPropertySet **j; // rdx
  unsigned int v15; // r8d
  UFG::qPropertySet *v16; // rax
  __int64 v17; // rax
  UFG::qPropertySet *v18; // rax
  UFG::qPropertySet *v19; // r8
  UFG::UIMapBlip *v20; // rdx

  size = this->mIconList.mSortedIcons.size;
  for ( i = 0i64; (int)i < size; i = (unsigned int)(i + 1) )
  {
    if ( this->mIconList.mNeedToSort )
    {
      p = (UFG::qPropertySet **)this->mIconList.mSortedIcons.p;
      v5 = &p[size - 1];
      v6 = (8 * (size - 1i64)) >> 3;
      v7 = v6 + 1;
      if ( (int)v6 + 1 < 32 )
      {
        if ( v7 > 1 )
          UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
            (UFG::qPropertySet **)this->mIconList.mSortedIcons.p,
            v7,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      else
      {
        v8 = &p[v6 / 2];
        v9 = *v8;
        if ( *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          *v8 = *p;
          *p = v9;
        }
        v10 = *v5;
        if ( *(_DWORD *)((*v5)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) )
        {
          *v5 = *v8;
          *v8 = v10;
        }
        v11 = *v8;
        if ( *(_DWORD *)((*v8)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          *v8 = *p;
          *p = v11;
        }
        v12 = *v8;
        v13 = p;
        for ( j = v5; v13 <= j; ++v13 )
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
          if ( v15 < *(_DWORD *)((*j)->mDefaultBits.mOffset + 96) )
          {
            do
            {
              if ( p >= j )
                break;
              v17 = (__int64)*--j;
            }
            while ( v15 < *(_DWORD *)(*(_QWORD *)(v17 + 48) + 96i64) );
          }
          if ( v13 > j )
            break;
          v18 = *j;
          v19 = *v13;
          --j;
          *v13 = v18;
          j[1] = v19;
        }
        if ( p < j )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            p,
            j,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        if ( v13 < v5 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v13,
            v5,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      this->mIconList.mNeedToSort = 0;
    }
    v20 = this->mIconList.mSortedIcons.p[i];
    if ( v20 )
      v20->mHasObjectiveHighlight = 0;
    size = this->mIconList.mSortedIcons.size;
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
  UFG::UIAmbientMapBlipManager *Instance; // rbp
  __int64 mCount; // rsi
  __int64 v4; // rbx
  UFG::UIAmbientMapBlipData *v5; // rdi
  const char *Type; // rax
  UFG::UIMapBlip *Icon; // rax

  if ( !this->mAmbientBlipsPopulated )
  {
    this->mAmbientBlipsPopulated = 1;
    Instance = UFG::UIAmbientMapBlipManager::getInstance();
    mCount = Instance->mCount;
    if ( mCount > 0 )
    {
      v4 = 0i64;
      do
      {
        v5 = &Instance->mData.p[v4];
        if ( v5 )
        {
          Type = UFG::UIAmbientMapBlipData::GetType(v5);
          Icon = UFG::UIMapBlipManager::CreateIcon(this, v5->mID.mUID, Type, v5->mPosition.x, v5->mPosition.y);
          if ( Icon )
            Icon->mIsAmbient = 1;
        }
        ++v4;
        --mCount;
      }
      while ( mCount );
    }
  }
}

// File Line: 663
// RVA: 0xC4D90
char __fastcall UFG::UIMapBlipManager::HasBlipType(UFG::UIMapBlipManager *this, UFG::qSymbolUC *iconType)
{
  signed int size; // eax
  __int64 v3; // rbp
  UFG::qPropertySet **p; // r9
  UFG::qPropertySet **v7; // rdi
  __int64 v8; // rax
  int v9; // edx
  UFG::qPropertySet **v10; // r8
  UFG::qPropertySet *v11; // r10
  UFG::qPropertySet *v12; // r11
  UFG::qPropertySet *v13; // r10
  UFG::qPropertySet *v14; // r10
  UFG::qPropertySet **v15; // rbx
  UFG::qPropertySet **i; // rdx
  unsigned int v17; // r8d
  UFG::qPropertySet *v18; // rax
  __int64 v19; // rax
  UFG::qPropertySet *v20; // rax
  UFG::qPropertySet *v21; // r8
  UFG::UIMapBlip *v22; // rcx

  size = this->mIconList.mSortedIcons.size;
  v3 = 0i64;
  if ( size <= 0 )
    return 0;
  while ( 1 )
  {
    if ( this->mIconList.mNeedToSort )
    {
      p = (UFG::qPropertySet **)this->mIconList.mSortedIcons.p;
      v7 = &p[size - 1];
      v8 = (8 * (size - 1i64)) >> 3;
      v9 = v8 + 1;
      if ( (int)v8 + 1 < 32 )
      {
        if ( v9 > 1 )
          UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
            (UFG::qPropertySet **)this->mIconList.mSortedIcons.p,
            v9,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      else
      {
        v10 = &p[v8 / 2];
        v11 = *v10;
        if ( *(_DWORD *)((*v10)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          *v10 = *p;
          *p = v11;
        }
        v12 = *v7;
        if ( *(_DWORD *)((*v7)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*v10)->mDefaultBits.mOffset + 96) )
        {
          *v7 = *v10;
          *v10 = v12;
        }
        v13 = *v10;
        if ( *(_DWORD *)((*v10)->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          *v10 = *p;
          *p = v13;
        }
        v14 = *v10;
        v15 = p;
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
              if ( p >= i )
                break;
              v19 = (__int64)*--i;
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
        if ( p < i )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            p,
            i,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        if ( v15 < v7 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v15,
            v7,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      this->mIconList.mNeedToSort = 0;
    }
    v22 = this->mIconList.mSortedIcons.p[v3];
    if ( v22 )
    {
      if ( v22->mType->TypeNameSymbol.mUID == iconType->mUID )
        break;
    }
    size = this->mIconList.mSortedIcons.size;
    v3 = (unsigned int)(v3 + 1);
    if ( (int)v3 >= size )
      return 0;
  }
  return 1;
}

// File Line: 683
// RVA: 0xCDFE0
void __fastcall UFG::UIMapBlipManager::UpdatePlayerArrow(
        UFG::UIMapBlipManager *this,
        unsigned int x,
        unsigned int y,
        float rot,
        bool pulseAnimation)
{
  UFG::UIMapBlipGraphic *mPlayerArrowIcon; // rcx
  __int64 v9; // rdx

  if ( !this->mPlayerArrowIcon )
    this->mPlayerArrowIcon = UFG::UIMapBlipGraphicFactory::GetNativeIconInstance(
                               &UFG::UIMapBlipGraphicFactory::Singleton,
                               &UIBlipIcon_Player_Arrow);
  mPlayerArrowIcon = this->mPlayerArrowIcon;
  if ( mPlayerArrowIcon )
  {
    ((void (__fastcall *)(UFG::UIMapBlipGraphic *))mPlayerArrowIcon->vfptr->UpdateLocation)(mPlayerArrowIcon);
    ((void (__fastcall *)(UFG::UIMapBlipGraphic *, __int64, _QWORD, _QWORD))this->mPlayerArrowIcon->vfptr->UpdateTransform)(
      this->mPlayerArrowIcon,
      v9,
      x,
      y);
    if ( pulseAnimation )
    {
      this->mPlayerArrowIcon->vfptr->SetBlink(this->mPlayerArrowIcon);
      this->mPlayerArrowIcon->vfptr->UpdateAnimation(this->mPlayerArrowIcon);
    }
  }
}

// File Line: 705
// RVA: 0xC0550
UFG::UIMapBlip *__fastcall UFG::UIMapBlipManager::FindNearestVisibleIcon(
        UFG::UIMapBlipManager *this,
        UFG::qVector3 *pos,
        UFG::UITiledMapMath *geo)
{
  float *v6; // rbp
  signed int size; // eax
  signed int i; // r14d
  UFG::qPropertySet **p; // r9
  UFG::qPropertySet **v10; // rdi
  __int64 v11; // rax
  int v12; // edx
  __int64 v13; // r8
  UFG::qPropertySet *v14; // r10
  UFG::qPropertySet *v15; // r10
  UFG::qPropertySet *v16; // r11
  UFG::qPropertySet *v17; // r10
  UFG::qPropertySet *v18; // r10
  UFG::qPropertySet **v19; // rbx
  UFG::qPropertySet **j; // rdx
  unsigned int v21; // r8d
  UFG::qPropertySet *v22; // rax
  __int64 v23; // rax
  UFG::qPropertySet *v24; // rax
  UFG::qPropertySet *v25; // r8
  UFG::UIMapBlip **v26; // rax
  UFG::UIMapBlip *v27; // rbx
  float z; // xmm3_4
  UFG::UIHKMinimapBlipType *mType; // rax
  UFG::qVector3 posa; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector3 dir; // [rsp+30h] [rbp-58h] BYREF

  v6 = 0i64;
  UFG::UI::GetPlayerWorldPosition(&posa, &dir);
  size = this->mIconList.mSortedIcons.size;
  for ( i = 0; i < size; ++i )
  {
    if ( this->mIconList.mNeedToSort )
    {
      p = (UFG::qPropertySet **)this->mIconList.mSortedIcons.p;
      v10 = &p[size - 1];
      v11 = (8 * (size - 1i64)) >> 3;
      v12 = v11 + 1;
      if ( (int)v11 + 1 < 32 )
      {
        if ( v12 > 1 )
          UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
            (UFG::qPropertySet **)this->mIconList.mSortedIcons.p,
            v12,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      else
      {
        v13 = v11 / 2;
        v14 = p[v11 / 2];
        if ( *(_DWORD *)(v14->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          p[v13] = *p;
          *p = v14;
        }
        v15 = p[v13];
        v16 = *v10;
        if ( *(_DWORD *)((*v10)->mDefaultBits.mOffset + 96) < *(_DWORD *)(v15->mDefaultBits.mOffset + 96) )
        {
          *v10 = v15;
          p[v13] = v16;
        }
        v17 = p[v13];
        if ( *(_DWORD *)(v17->mDefaultBits.mOffset + 96) < *(_DWORD *)((*p)->mDefaultBits.mOffset + 96) )
        {
          p[v13] = *p;
          *p = v17;
        }
        v18 = p[v13];
        v19 = p;
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
              if ( p >= j )
                break;
              v23 = (__int64)*--j;
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
        if ( p < j )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            p,
            j,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
        if ( v19 < v10 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v19,
            v10,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::fnDrawDepth);
      }
      this->mIconList.mNeedToSort = 0;
    }
    v26 = this->mIconList.mSortedIcons.p;
    v27 = v26[i];
    if ( v27 )
    {
      if ( !v6 )
        v6 = (float *)v26[i];
      z = v27->pos.z;
      if ( (float)((float)((float)((float)(v27->pos.y - pos->y) * (float)(v27->pos.y - pos->y))
                         + (float)((float)(v27->pos.x - pos->x) * (float)(v27->pos.x - pos->x)))
                 + (float)((float)(z - pos->z) * (float)(z - pos->z))) < (float)((float)((float)((float)(v6[17] - pos->y)
                                                                                               * (float)(v6[17] - pos->y))
                                                                                       + (float)((float)(v6[16] - pos->x)
                                                                                               * (float)(v6[16] - pos->x)))
                                                                               + (float)((float)(v6[18] - pos->z)
                                                                                       * (float)(v6[18] - pos->z)))
        && v27->mVisible )
      {
        mType = v27->mType;
        if ( mType )
        {
          if ( mType->IsVisible && UFG::UIMapBlip::GetAlpha(v27, &posa, geo) > 0.0099999998 )
            v6 = (float *)v27;
        }
      }
    }
    size = this->mIconList.mSortedIcons.size;
  }
  return (UFG::UIMapBlip *)v6;
}

