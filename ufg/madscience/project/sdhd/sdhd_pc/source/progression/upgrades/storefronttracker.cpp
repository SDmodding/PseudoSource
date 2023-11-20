// File Line: 38
// RVA: 0x152E1F0
__int64 UFG::_dynamic_initializer_for__qSymbol_ActBaseName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ActBaseName", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_ActBaseName, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_ActBaseName__);
}

// File Line: 42
// RVA: 0x151D110
__int64 UFG::_dynamic_initializer_for__StoreItemSymbol_Price__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Price", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::StoreItemSymbol_Price, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__StoreItemSymbol_Price__);
}

// File Line: 46
// RVA: 0x151CDD0
__int64 UFG::_dynamic_initializer_for__StoreFrontSymbol_ClothingSets__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ClothingSets", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&StoreFrontSymbol_ClothingSets, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__StoreFrontSymbol_ClothingSets__);
}

// File Line: 50
// RVA: 0x151C710
__int64 UFG::_dynamic_initializer_for__ItemCategorySymbol_RIGHTWRIST__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RIGHTWRIST", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::ItemCategorySymbol_RIGHTWRIST, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__ItemCategorySymbol_RIGHTWRIST__);
}

// File Line: 61
// RVA: 0x151C250
__int64 UFG::_dynamic_initializer_for__ItemBrandSymbol_BeautifulCorpse__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BeautifulCorpse", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::ItemBrandSymbol_BeautifulCorpse, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__ItemBrandSymbol_BeautifulCorpse__);
}

// File Line: 72
// RVA: 0x151B5D0
__int64 UFG::_dynamic_initializer_for__ClothingSetSymbol_ActiveDesc__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ActiveDesc", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::ClothingSetSymbol_ActiveDesc, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__ClothingSetSymbol_ActiveDesc__);
}

// File Line: 89
// RVA: 0x48DE10
void __fastcall UFG::StoreFront::StoreFront(UFG::StoreFront *this, UFG::StoreFront::StoreType type, UFG::StoreFront::InventoryType inventoryType, UFG::qPropertySet *pParameters, UFG::qPropertySet *pPropertySet)
{
  UFG::StoreFront *v5; // rbx
  UFG::qPropertySet *pPropertySeta; // [rsp+60h] [rbp+28h]

  v5 = this;
  this->mpStoreParameters = pParameters;
  this->mpPropertySet = pPropertySet;
  this->mpStoreOwner = 0i64;
  this->mStoreType = type;
  this->mStoreName.mUID = -1;
  this->mInventoryType = 0;
  this->mCategoryFilter = 14;
  UFG::qString::qString(&this->mCategoryHeading);
  UFG::qString::qString(&v5->mStoreTitle);
  UFG::qString::qString(&v5->mStoreDesc);
  v5->mItemTypeFilter.mUID = -1;
  UFG::qString::qString(&v5->mItemTierFilter);
  pPropertySeta = (UFG::qPropertySet *)&v5->m_Items;
  *(_QWORD *)&pPropertySeta->mFlags = pPropertySeta;
  pPropertySeta->mOwner.mOffset = (__int64)pPropertySeta;
  *(_QWORD *)v5->mCategoryCount = 0i64;
  *(_QWORD *)&v5->mCategoryCount[2] = 0i64;
  *(_QWORD *)&v5->mCategoryCount[4] = 0i64;
  *(_QWORD *)&v5->mCategoryCount[6] = 0i64;
  *(_QWORD *)&v5->mCategoryCount[8] = 0i64;
  *(_QWORD *)&v5->mCategoryCount[10] = 0i64;
  *(_QWORD *)&v5->mCategoryCount[12] = 0i64;
  v5->mCategoryCount[14] = 0;
}

// File Line: 97
// RVA: 0x4915D0
void __fastcall UFG::StoreFront::~StoreFront(UFG::StoreFront *this)
{
  UFG::StoreFront *v1; // rdi
  UFG::qList<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem,1,0> *v2; // rbx
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *v3; // rcx
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *v4; // rax

  v1 = this;
  v2 = &this->m_Items;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_Items);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qString::~qString(&v1->mItemTierFilter);
  UFG::qString::~qString(&v1->mStoreDesc);
  UFG::qString::~qString(&v1->mStoreTitle);
  UFG::qString::~qString(&v1->mCategoryHeading);
}

// File Line: 112
// RVA: 0x4B0C00
signed __int64 __fastcall UFG::StoreFront::MapItemCategory(UFG::qSymbol *itemCategory)
{
  unsigned int v1; // edx
  signed __int64 result; // rax

  v1 = itemCategory->mUID;
  result = Num_ItemCategories;
  if ( itemCategory->mUID == UFG::ItemCategorySymbol_BODY.mUID )
    return ItemCategory_BODY;
  if ( v1 == UFG::ItemCategorySymbol_LOWER_BODY.mUID )
    return ItemCategory_LOWER_BODY;
  if ( v1 == UFG::ItemCategorySymbol_FOOTWEAR.mUID )
    return ItemCategory_FOOTWEAR;
  if ( v1 == UFG::ItemCategorySymbol_HEADGEAR.mUID )
    return ItemCategory_HEADGEAR;
  if ( v1 == UFG::ItemCategorySymbol_HEAD.mUID )
    return ItemCategory_HEAD;
  if ( v1 == UFG::ItemCategorySymbol_ACCESSORIES.mUID )
    return ItemCategory_ACCESSORIES;
  if ( v1 == UFG::ItemCategorySymbol_GLASSES.mUID )
    return ItemCategory_GLASSES;
  if ( v1 == UFG::ItemCategorySymbol_NECK.mUID )
    return ItemCategory_NECK;
  if ( v1 == UFG::ItemCategorySymbol_LEFTWRIST.mUID )
    return ItemCategory_LEFTWRIST;
  if ( v1 == UFG::ItemCategorySymbol_RIGHTWRIST.mUID )
    return ItemCategory_RIGHTWRIST;
  if ( v1 == UFG::ItemCategorySymbol_OUTFIT.mUID )
    return ItemCategory_OUTFIT;
  if ( v1 == UFG::ItemCategorySymbol_CUSTOM_OUTFIT.mUID )
    return ItemCategory_CUSTOM_OUTFIT;
  if ( v1 == UFG::ItemCategorySymbol_VEHICLE.mUID )
    return ItemCategory_VEHICLE;
  if ( v1 == UFG::ItemCategorySymbol_BOAT.mUID )
    result = ItemCategory_BOAT;
  return result;
}

// File Line: 125
// RVA: 0x4930D0
void __fastcall UFG::StoreFront::AddItemToStore(UFG::StoreFront *this, UFG::qPropertySet *pItemPropertySet, int iIndex, bool bRetail)
{
  bool v4; // si
  __int16 v5; // bp
  UFG::StoreFront *v6; // rbx
  UFG::qSymbol *v7; // rax
  __int64 v8; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rdx
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *v11; // rax

  v4 = bRetail;
  v5 = iIndex;
  v6 = this;
  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pItemPropertySet,
         (UFG::qSymbol *)&UFG::StoreItemSymbol_Category.mUID,
         DEPTH_RECURSE);
  v8 = (signed int)UFG::StoreFront::MapItemCategory(v7);
  v9 = UFG::qMalloc(0x18ui64, "StoreItem", 0i64);
  v10 = v9;
  if ( v9 )
  {
    v9->mNext = v9;
    v9[1].mNext = v9;
  }
  else
  {
    v10 = 0i64;
  }
  BYTE2(v10[2].mNext) = v4;
  LOWORD(v10[2].mNext) = v5;
  WORD2(v10[2].mNext) = v8;
  v11 = v6->m_Items.mNode.mPrev;
  v11->mNext = (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)v10;
  v10->mNext = (UFG::allocator::free_link *)v11;
  v10[1].mNext = (UFG::allocator::free_link *)&v6->m_Items;
  v6->m_Items.mNode.mPrev = (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)v10;
  ++v6->mCategoryCount[v8];
}

// File Line: 142
// RVA: 0x4959F0
void __fastcall UFG::StoreFront::BuildCategories(UFG::StoreFront *this)
{
  UFG::qList<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem,1,0> *v1; // r8
  UFG::StoreFront *v2; // rdx
  UFG::StoreFront *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  int v6; // edi
  int v7; // er14
  UFG::qPropertySet *v8; // rax
  UFG::qPropertySet *v9; // rsi
  UFG::qSymbol *v10; // rax
  unsigned int v11; // ecx
  unsigned int v12; // eax
  char *v13; // rax
  const char *v14; // rbp
  UFG::qPropertySet *v15; // rcx
  UFG::qPropertyList *v16; // rax
  signed int v17; // er12
  signed int i; // er15
  UFG::qPropertyList *v19; // rax
  char *v20; // rax
  __int64 v21; // rcx
  UFG::qPropertySet *v22; // r14
  unsigned int v23; // ecx
  char *v24; // rax
  const char *v25; // rdi
  UFG::qPropertyList *v26; // rax
  UFG::qPropertyList *v27; // rbp
  unsigned int v28; // esi
  unsigned int v29; // edi
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]
  UFG::qSymbol propName; // [rsp+68h] [rbp+10h]

  this->mCategoryFilter = 14;
  v1 = &this->m_Items;
  *(_QWORD *)this->mCategoryCount = 0i64;
  *(_QWORD *)&this->mCategoryCount[2] = 0i64;
  *(_QWORD *)&this->mCategoryCount[4] = 0i64;
  *(_QWORD *)&this->mCategoryCount[6] = 0i64;
  *(_QWORD *)&this->mCategoryCount[8] = 0i64;
  *(_QWORD *)&this->mCategoryCount[10] = 0i64;
  *(_QWORD *)&this->mCategoryCount[12] = 0i64;
  this->mCategoryCount[14] = 0;
  v2 = (UFG::StoreFront *)this->m_Items.mNode.mNext;
  v3 = this;
  if ( v2 != (UFG::StoreFront *)&this->m_Items )
  {
    do
    {
      v4 = v2->mpStoreParameters;
      v5 = v2->mpPropertySet;
      v4->mOwner.mOffset = (__int64)v5;
      *(_QWORD *)&v5->mFlags = v4;
      v2->mpStoreParameters = (UFG::qPropertySet *)v2;
      v2->mpPropertySet = (UFG::qPropertySet *)v2;
      v2 = (UFG::StoreFront *)v1->mNode.mNext;
    }
    while ( v2 != (UFG::StoreFront *)v1 );
  }
  UFG::qSymbol::create_from_string(&result, "Type");
  UFG::qSymbol::create_from_string(&propName, "Tier");
  if ( (unsigned int)(v3->mStoreType - 2) <= 1 )
  {
    v6 = 0;
    v7 = UFG::StoreFront::GetNumStorageItems(v3);
    if ( v7 > 0 )
    {
      do
      {
        v8 = UFG::StoreFront::GetStorageItem(v3, v6);
        v9 = v8;
        if ( v8 )
        {
          v10 = PropertyUtils::Get<UFG::qSymbol>(v8, &result, DEPTH_RECURSE);
          v11 = v3->mItemTypeFilter.mUID;
          if ( v11 == -1 || (v12 = v10->mUID, v12 == -1) || v11 == v12 )
          {
            if ( v3->mItemTierFilter.mLength <= 0
              || (v13 = PropertyUtils::Get<char const *>(v9, &propName, DEPTH_RECURSE), (v14 = v13) == 0i64)
              || (signed int)UFG::qStringLength(v13) <= 0
              || !(unsigned int)UFG::qStringCompare(v3->mItemTierFilter.mData, v14, -1) )
            {
              UFG::StoreFront::AddItemToStore(v3, v9, v6, 0);
            }
          }
        }
        ++v6;
      }
      while ( v6 < v7 );
    }
  }
  if ( v3->mStoreType == 1 )
  {
    v15 = v3->mpPropertySet;
    if ( v15
      && (v16 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  v15,
                  (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
                  DEPTH_RECURSE)) != 0i64 )
    {
      v17 = v16->mNumElements;
    }
    else
    {
      v17 = 0;
    }
    for ( i = 0; i < v17; ++i )
    {
      v19 = UFG::qPropertySet::Get<UFG::qPropertyList>(
              v3->mpPropertySet,
              (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
              DEPTH_RECURSE);
      if ( v19 )
      {
        v20 = UFG::qPropertyList::GetValuePtr(v19, 0x1Au, i);
        if ( v20 )
        {
          v21 = *(_QWORD *)v20;
          if ( *(_QWORD *)v20 )
          {
            v22 = (UFG::qPropertySet *)&v20[v21];
            if ( &v20[v21] )
            {
              if ( v3->mItemTypeFilter.mUID == -1
                || (v23 = PropertyUtils::Get<UFG::qSymbol>((UFG::qPropertySet *)&v20[v21], &result, DEPTH_RECURSE)->mUID,
                    v23 == -1)
                || v3->mItemTypeFilter.mUID == v23 )
              {
                if ( v3->mItemTierFilter.mLength <= 0
                  || (v24 = PropertyUtils::Get<char const *>(v22, &propName, DEPTH_RECURSE), (v25 = v24) == 0i64)
                  || (signed int)UFG::qStringLength(v24) <= 0
                  || !(unsigned int)UFG::qStringCompare(v3->mItemTierFilter.mData, v25, -1) )
                {
                  v26 = PropertyUtils::Get<UFG::qPropertyList>(
                          v22,
                          (UFG::qSymbol *)&StoreFrontSymbol_Stores.mUID,
                          DEPTH_RECURSE);
                  v27 = v26;
                  if ( v26 )
                  {
                    v28 = v26->mNumElements;
                    v29 = 0;
                    if ( v28 )
                    {
                      while ( v3->mStoreName.mUID != UFG::qPropertyList::Get<UFG::qSymbol>(v27, v29)->mUID )
                      {
                        if ( ++v29 >= v28 )
                          goto LABEL_38;
                      }
                      UFG::StoreFront::AddItemToStore(v3, v22, i, 1);
                    }
                  }
                }
              }
            }
          }
        }
      }
LABEL_38:
      ;
    }
  }
  v3->mCategoryFilter = 13;
  UFG::StoreFront::SetNextCategory(v3);
}

// File Line: 262
// RVA: 0x4C59C0
void __fastcall UFG::StoreFront::UpdateCategoryHeading(UFG::StoreFront *this)
{
  UFG::StoreFront *v1; // rbx
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v3; // rax
  char *v4; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this;
  UFG::qString::Set(&this->mCategoryHeading, &customWorldMapCaption);
  if ( v1->mCategoryFilter != 14 )
  {
    v2 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-categories");
    v3 = UFG::PropertySetManager::GetPropertySet(v2);
    v4 = PropertyUtils::Get<char const *>(v3, ItemCategorySymbols[v1->mCategoryFilter], DEPTH_RECURSE);
    UFG::qString::Set(&v1->mCategoryHeading, v4);
  }
}

// File Line: 295
// RVA: 0x4BCEE0
void __fastcall UFG::StoreFront::SetNextCategory(UFG::StoreFront *this)
{
  UFG::StoreFront *v1; // rbx
  int v2; // er8
  __int32 v3; // er9
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *v5; // rax
  char *v6; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v1 = this;
  v2 = 0;
  while ( 1 )
  {
    v3 = (this->mCategoryFilter + 1) % 14;
    this->mCategoryFilter = v3;
    if ( this->mCategoryCount[v3] )
      break;
    if ( ++v2 >= 14 )
    {
      this->mCategoryFilter = 14;
      break;
    }
  }
  UFG::qString::Set(&this->mCategoryHeading, &customWorldMapCaption);
  if ( v1->mCategoryFilter != 14 )
  {
    v4 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-categories");
    v5 = UFG::PropertySetManager::GetPropertySet(v4);
    v6 = PropertyUtils::Get<char const *>(v5, ItemCategorySymbols[v1->mCategoryFilter], DEPTH_RECURSE);
    UFG::qString::Set(&v1->mCategoryHeading, v6);
  }
}

// File Line: 314
// RVA: 0x4A4310
__int64 __fastcall UFG::StoreFront::GetItemCount(UFG::StoreFront *this, UFG::StoreFront::ItemCategory category)
{
  return this->mCategoryCount[category];
}

// File Line: 320
// RVA: 0x4ACBA0
bool __fastcall UFG::StoreFront::IsOwnedClothingCategoryEmpty(UFG::StoreFront *this, UFG::StoreFront::ItemCategory category)
{
  bool result; // al

  if ( category == 5 || category == 10 )
    result = this->mCategoryCount[category] < 1;
  else
    result = this->mCategoryCount[category] < 2;
  return result;
}

// File Line: 332
// RVA: 0x4BBE60
void __fastcall UFG::StoreFront::SetCurrentCategory(UFG::StoreFront *this, UFG::StoreFront::ItemCategory category)
{
  this->mCategoryFilter = category;
  UFG::StoreFront::UpdateCategoryHeading(this);
}

// File Line: 339
// RVA: 0x4A1EF0
char *__fastcall UFG::StoreFront::GetCategoryHeading(UFG::StoreFront *this, UFG::StoreFront::ItemCategory category)
{
  __int64 v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v2 = category;
  if ( (signed int)category >= 14 )
    return &customWorldMapCaption;
  v3 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-categories");
  v4 = UFG::PropertySetManager::GetPropertySet(v3);
  return PropertyUtils::Get<char const *>(v4, ItemCategorySymbols[v2], DEPTH_RECURSE);
}

// File Line: 359
// RVA: 0x4BBFD0
void __fastcall UFG::StoreFront::SetData(UFG::StoreFront *this, UFG::StoreFront::StoreType storeType, UFG::StoreFront::InventoryType inventoryType, UFG::qPropertySet *pParameters, UFG::qPropertySet *pPropertySet)
{
  char *v5; // r15
  unsigned int v6; // ebx
  UFG::StoreFront::InventoryType v7; // er13
  UFG::StoreFront::StoreType v8; // ebp
  UFG::StoreFront *v9; // rdi
  char *v10; // r12
  UFG::qSymbol *v11; // rax
  char *v12; // rax
  const char *v13; // rsi

  v5 = 0i64;
  this->mpStoreParameters = pParameters;
  v6 = UFG::gNullQSymbol.mUID;
  v7 = inventoryType;
  v8 = storeType;
  v9 = this;
  v10 = 0i64;
  if ( !((storeType - 1) & 0xFFFFFFFD) )
  {
    v6 = PropertyUtils::Get<UFG::qSymbol>(pParameters, (UFG::qSymbol *)&qSymbol_StoreId.mUID, DEPTH_RECURSE)->mUID;
    v5 = PropertyUtils::Get<char const *>(
           v9->mpStoreParameters,
           (UFG::qSymbol *)&qSymbol_StoreTitle.mUID,
           DEPTH_RECURSE);
    v10 = PropertyUtils::Get<char const *>(
            v9->mpStoreParameters,
            (UFG::qSymbol *)&qSymbol_StoreDesc.mUID,
            DEPTH_RECURSE);
  }
  UFG::qSymbol::set_null(&v9->mItemTypeFilter);
  UFG::qString::Set(&v9->mItemTierFilter, &customWorldMapCaption);
  if ( v9->mpStoreParameters )
  {
    v11 = PropertyUtils::Get<UFG::qSymbol>(
            v9->mpStoreParameters,
            (UFG::qSymbol *)&qSymbol_StoreItemFilter.mUID,
            DEPTH_RECURSE);
    if ( v11 )
      v9->mItemTypeFilter = (UFG::qSymbol)v11->mUID;
    v12 = PropertyUtils::Get<char const *>(
            v9->mpStoreParameters,
            (UFG::qSymbol *)&qSymbol_StoreTierFilter.mUID,
            DEPTH_RECURSE);
    v13 = v12;
    if ( v12 && (signed int)UFG::qStringLength(v12) > 0 )
      UFG::qString::Set(&v9->mItemTierFilter, v13);
  }
  v9->mStoreType = v8;
  v9->mInventoryType = v7;
  v9->mpPropertySet = pPropertySet;
  UFG::qString::Set(&v9->mStoreTitle, v5);
  UFG::qString::Set(&v9->mStoreDesc, v10);
  v9->mStoreName.mUID = v6;
  if ( v8 )
    UFG::StoreFront::BuildCategories(v9);
}

// File Line: 415
// RVA: 0x498720
void __fastcall UFG::StoreFront::ClosePreviewShutter(UFG::StoreFront *this)
{
  UFG::StoreFront *v1; // rbx
  UFG::qSymbol *v2; // rax
  UFG::SimObjectGame *v3; // rax
  UFG::SimObjectGame *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rdi
  UFG::SimComponent *v7; // rax
  UFG::qPropertySet *v8; // rax
  ActionNode *v9; // rbx
  int v10; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-40h]
  UFG::qString v12; // [rsp+38h] [rbp-30h]

  v1 = this;
  if ( !(_S7_13 & 1) )
  {
    _S7_13 |= 1u;
    UIDClosed.mUID = UFG::qStringHashUpper32("Closed", 0xFFFFFFFF);
  }
  v2 = PropertyUtils::Get<UFG::qSymbol>(
         v1->mpStoreParameters,
         (UFG::qSymbol *)&qSymbol_StorePreviewShutter.mUID,
         DEPTH_RECURSE);
  if ( v2 )
  {
    if ( v2->mUID != -1 )
    {
      v3 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v2);
      v4 = v3;
      if ( v3 )
      {
        v5 = v3->m_Flags;
        if ( (v5 >> 14) & 1 )
        {
          v6 = v3->m_Components.p[7].m_pComponent;
        }
        else if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
          {
            v6 = v3->m_Components.p[6].m_pComponent;
          }
          else
          {
            if ( (v5 >> 12) & 1 )
              v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID);
            else
              v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
            v6 = v7;
          }
        }
        else
        {
          v6 = v3->m_Components.p[7].m_pComponent;
        }
        v8 = PropertyUtils::Get<char const *>(v4->m_pSceneObj, (UFG::qSymbol *)&qSymbol_ActBaseName.mUID);
        UFG::qString::qString(&v12, "\\Global\\%s\\Object\\Animation\\Closing", v8);
        absolutePath.mPath.mCount = 0;
        absolutePath.mPath.mData.mOffset = 0i64;
        ActionPath::Append(&absolutePath, v12.mData);
        v9 = ActionNode::Find(&absolutePath, 0i64);
        if ( v9 && !ActionController::IsPlaying((ActionController *)&v6[3], &UIDClosed, 0xFFFFFFFF, 1) )
          ActionController::Play((ActionController *)&v6[3], v9, 0);
        v10 = absolutePath.mPath.mCount;
        if ( absolutePath.mPath.mCount >= 0 )
        {
          if ( absolutePath.mPath.mData.mOffset )
          {
            if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
            {
              operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
              v10 = absolutePath.mPath.mCount;
            }
          }
          absolutePath.mPath.mData.mOffset = 0i64;
          absolutePath.mPath.mCount = v10 & 0x80000000;
        }
        UFG::qString::~qString(&v12);
      }
    }
  }
}

// File Line: 449
// RVA: 0x4B1E30
void __fastcall UFG::StoreFront::OpenPreviewShutter(UFG::StoreFront *this)
{
  UFG::qSymbol *v1; // rax
  UFG::SimObjectGame *v2; // rax
  UFG::SimObjectGame *v3; // rbx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdi
  UFG::SimComponent *v6; // rax
  UFG::qPropertySet *v7; // rax
  __int64 v8; // rax
  const char *v9; // rdx
  ActionNode *v10; // rax
  ActionPath absolutePath; // [rsp+28h] [rbp-40h]
  UFG::qString v12; // [rsp+38h] [rbp-30h]

  v1 = PropertyUtils::Get<UFG::qSymbol>(
         this->mpStoreParameters,
         (UFG::qSymbol *)&qSymbol_StorePreviewShutter.mUID,
         DEPTH_RECURSE);
  if ( v1 )
  {
    if ( v1->mUID != -1 )
    {
      v2 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v1);
      v3 = v2;
      if ( v2 )
      {
        v4 = v2->m_Flags;
        if ( (v4 >> 14) & 1 )
        {
          v5 = v2->m_Components.p[7].m_pComponent;
        }
        else if ( (v4 & 0x8000u) == 0 )
        {
          if ( (v4 >> 13) & 1 )
          {
            v5 = v2->m_Components.p[6].m_pComponent;
          }
          else
          {
            if ( (v4 >> 12) & 1 )
              v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::ActionTreeComponent::_TypeUID);
            else
              v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
            v5 = v6;
          }
        }
        else
        {
          v5 = v2->m_Components.p[7].m_pComponent;
        }
        v7 = PropertyUtils::Get<char const *>(v3->m_pSceneObj, (UFG::qSymbol *)&qSymbol_ActBaseName.mUID);
        UFG::qString::qString(&v12, "\\Global\\%s\\Object\\Animation\\Opening", v7);
        v9 = *(const char **)(v8 + 24);
        absolutePath.mPath.mCount = 0;
        absolutePath.mPath.mData.mOffset = 0i64;
        ActionPath::Append(&absolutePath, v9);
        UFG::qString::~qString(&v12);
        v10 = ActionNode::Find(&absolutePath, 0i64);
        if ( v10 )
          ActionController::Play((ActionController *)&v5[3], v10, 0);
        if ( absolutePath.mPath.mCount >= 0 && absolutePath.mPath.mData.mOffset )
        {
          if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
            operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
        }
      }
    }
  }
}

// File Line: 476
// RVA: 0x4A05D0
char __fastcall UFG::StoreFront::FindItemIndex(UFG::StoreFront *this, UFG::qSymbol *spawnInfo, unsigned int *itemIndexOut)
{
  __int64 v3; // rax
  int v4; // ebx
  unsigned int *v5; // r14
  UFG::qSymbol *v6; // rbp
  UFG::StoreFront *v7; // rsi
  unsigned int v8; // edi
  UFG::StoreFront *i; // rax
  UFG::qPropertySet *v10; // rax

  v3 = this->mCategoryFilter;
  v4 = 0;
  v5 = itemIndexOut;
  v6 = spawnInfo;
  v7 = this;
  if ( (_DWORD)v3 == 14 )
  {
    v8 = 0;
    for ( i = (UFG::StoreFront *)this->m_Items.mNode.mNext; i != (UFG::StoreFront *)&this->m_Items; ++v8 )
      i = (UFG::StoreFront *)i->mpPropertySet;
  }
  else
  {
    v8 = this->mCategoryCount[v3];
  }
  if ( !v8 )
    return 0;
  while ( 1 )
  {
    v10 = UFG::StoreFront::GetItem(v7, v4);
    if ( v10 )
    {
      if ( v6->mUID == PropertyUtils::Get<UFG::qSymbol>(
                         v10,
                         (UFG::qSymbol *)&UFG::StoreItemSymbol_SpawnObjectInfo.mUID,
                         DEPTH_RECURSE)->mUID )
        break;
    }
    if ( ++v4 >= v8 )
      return 0;
  }
  *v5 = v4;
  return 1;
}

// File Line: 497
// RVA: 0x4BECF0
UFG::SimObjectCVBase *__fastcall UFG::StoreFront::SpawnItem(UFG::StoreFront *this, int filterIndex)
{
  UFG::StoreFront *v2; // rdi
  UFG::qPropertySet *v3; // rax
  UFG::qPropertySet *v4; // rbp
  UFG::qSymbol *v5; // rbx
  char *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::SimObject *v8; // rax
  UFG::SimObjectCVBase *v9; // rdi
  unsigned __int16 v10; // cx
  UFG::TSActorComponent *v11; // rbx
  SSActorClass *v12; // rsi
  SSClass *v13; // rcx
  SSClass *v14; // rcx
  UFG::TSVehicle *v15; // rax
  unsigned __int16 v16; // cx
  UFG::SimObjectVehiclePropertiesComponent *v17; // rax
  UFG::SimObjectVehiclePropertiesComponent *v18; // rbx
  float *v19; // rax
  float v20; // xmm0_4
  UFG::qBaseTreeRB *v21; // rax
  UFG::qMatrix44 *v22; // rbx
  UFG::qSymbol v24; // [rsp+30h] [rbp-28h]
  UFG::qSymbol result; // [rsp+70h] [rbp+18h]
  UFG::qSymbol objName; // [rsp+78h] [rbp+20h]

  v2 = this;
  v3 = UFG::StoreFront::GetItem(this, filterIndex);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  v5 = PropertyUtils::Get<UFG::qSymbol>(v3, (UFG::qSymbol *)&UFG::StoreItemSymbol_SpawnObjectInfo.mUID, DEPTH_RECURSE);
  v6 = PropertyUtils::Get<char const *>(
         v2->mpStoreParameters,
         (UFG::qSymbol *)&qSymbol_StorePreviewMarker.mUID,
         DEPTH_RECURSE);
  UFG::qSymbol::create_from_string(&result, v6);
  if ( !v5 || v5->mUID == -1 || result.mUID == -1 )
    return 0i64;
  v7 = UFG::qSymbol::create_from_string(&v24, sStoreItemPrefix);
  UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v7);
  v8 = UFG::SpawnInfoInterface::SpawnObject(&objName, v5, 0, 0i64, 0i64, 0i64);
  v9 = (UFG::SimObjectCVBase *)v8;
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = (UFG::TSActorComponent *)v8->m_Components.p[4].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = (UFG::TSActorComponent *)v8->m_Components.p[3].m_pComponent;
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = (UFG::TSActorComponent *)v8->m_Components.p[2].m_pComponent;
      }
      else
      {
        v11 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v8, UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      v11 = (UFG::TSActorComponent *)v8->m_Components.p[4].m_pComponent;
    }
    if ( v11 )
    {
      v12 = UFG::TSVehicle::mClass;
      v13 = UFG::TSActorComponent::GetActor(v11)->i_class_p;
      if ( v12 == (SSActorClass *)v13
        || (v14 = v13->i_superclass_p) != 0i64 && SSClass::is_class(v14, (SSClass *)&v12->vfptr) )
      {
        v15 = (UFG::TSVehicle *)UFG::TSActorComponent::GetActor(v11);
        UFG::TSVehicle::UnlockDoors(v15, 1);
      }
    }
    v16 = v9->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v17 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v9);
    }
    else if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
      {
        v17 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v9->vfptr,
                                                            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
      else if ( (v16 >> 12) & 1 )
      {
        v17 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v9->vfptr,
                                                            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
      else
      {
        v17 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v9->vfptr,
                                                            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v17 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v9);
    }
    v18 = v17;
    if ( v17 )
    {
      v19 = PropertyUtils::Get<float>(v4, (UFG::qSymbol *)&qSymbol_FaceReplenishMultiplier.mUID, DEPTH_RECURSE);
      if ( v19 )
        v20 = *v19;
      else
        v20 = *(float *)&FLOAT_1_0;
      v18->mFaceReplenishMultiplier = v20;
    }
  }
  v21 = UFG::MarkerBase::GetNamed(&result);
  if ( v21 )
  {
    v22 = (UFG::qMatrix44 *)v21[1].mNULL.mParent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v21[1].mNULL.mParent);
    UFG::SimObjectUtility::Teleport((UFG::SimObject *)&v9->vfptr, v22 + 2);
  }
  return v9;
}

// File Line: 547
// RVA: 0x4A1CD0
UFG::qBaseNodeRB *__fastcall UFG::StoreFront::GetCameraMarker(UFG::StoreFront *this)
{
  UFG::qPropertySet *v1; // rcx
  char *v2; // rax
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseNodeRB *v4; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this->mpStoreParameters;
  if ( v1
    && (v2 = PropertyUtils::Get<char const *>(v1, (UFG::qSymbol *)&qSymbol_StoreCameraMarker.mUID, DEPTH_RECURSE),
        UFG::qSymbol::create_from_string(&result, v2),
        (v3 = UFG::MarkerBase::GetNamed(&result)) != 0i64) )
  {
    v4 = v3->mNULL.mChild[0];
  }
  else
  {
    v4 = 0i64;
  }
  return v4;
}

// File Line: 567
// RVA: 0x4A5E70
UFG::qBaseNodeRB *__fastcall UFG::StoreFront::GetPlayerMarker(UFG::StoreFront *this)
{
  UFG::qPropertySet *v1; // rcx
  char *v2; // rax
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseNodeRB *v4; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this->mpStoreParameters;
  if ( v1
    && (v2 = PropertyUtils::Get<char const *>(v1, (UFG::qSymbol *)&qSymbol_StorePlayerMarker.mUID, DEPTH_RECURSE),
        UFG::qSymbol::create_from_string(&result, v2),
        (v3 = UFG::MarkerBase::GetNamed(&result)) != 0i64) )
  {
    v4 = v3->mNULL.mChild[0];
  }
  else
  {
    v4 = 0i64;
  }
  return v4;
}

// File Line: 578
// RVA: 0x4A5E20
UFG::qBaseNodeRB *__fastcall UFG::StoreFront::GetPlayerExitMarker(UFG::StoreFront *this)
{
  UFG::qPropertySet *v1; // rcx
  char *v2; // rax
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseNodeRB *v4; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this->mpStoreParameters;
  if ( v1
    && (v2 = PropertyUtils::Get<char const *>(v1, (UFG::qSymbol *)&qSymbol_StorePlayerExitMarker.mUID, DEPTH_RECURSE),
        UFG::qSymbol::create_from_string(&result, v2),
        (v3 = UFG::MarkerBase::GetNamed(&result)) != 0i64) )
  {
    v4 = v3->mNULL.mChild[0];
  }
  else
  {
    v4 = 0i64;
  }
  return v4;
}

// File Line: 589
// RVA: 0x4A59E0
__int64 __fastcall UFG::StoreFront::GetNumStorageItems(UFG::StoreFront *this)
{
  __int64 v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  UFG::PersistentData::MapBool *v3; // rdx

  v1 = this->mInventoryType;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = v2->mpSnapshots[0]->mpMapBools[v1];
  if ( v3->mKeepType == KEEP_BOTH )
    return v3->mValues.size;
  if ( (unsigned int)(v3->mKeepType - 1) > 1 )
    return 0i64;
  return v3->mNames.size;
}

// File Line: 610
// RVA: 0x4A58F0
__int64 __fastcall UFG::StoreFront::GetNumItems(UFG::StoreFront *this)
{
  __int64 v1; // rax
  UFG::qList<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem,1,0> *v2; // rdx
  __int64 result; // rax
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *i; // rcx

  v1 = this->mCategoryFilter;
  if ( (_DWORD)v1 != 14 )
    return this->mCategoryCount[v1];
  v2 = &this->m_Items;
  result = 0i64;
  for ( i = this->m_Items.mNode.mNext;
        i != (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)v2;
        result = (unsigned int)(result + 1) )
  {
    i = i->mNext;
  }
  return result;
}

// File Line: 654
// RVA: 0x4A6950
UFG::qPropertySet *__fastcall UFG::StoreFront::GetStorageItem(UFG::StoreFront *this, int index)
{
  __int64 v2; // rdi
  __int64 v3; // rsi
  UFG::GameStatTracker *v4; // rbx
  UFG::PersistentData::MapBool *v5; // rdx
  UFG::qSymbol *v6; // rdx
  UFG::StoreFrontTracker *v7; // rbx
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rbp
  unsigned int v10; // esi
  unsigned int v11; // edi
  char *v12; // rax
  char *v13; // rbx
  char *v14; // rax
  UFG::qSymbolUC v16; // [rsp+40h] [rbp+8h]

  v2 = (unsigned int)index;
  v3 = this->mInventoryType;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  v5 = v4->mpSnapshots[0]->mpMapBools[v3];
  if ( v5->mKeepType )
  {
    if ( (unsigned int)(v5->mKeepType - 1) > 1 )
      v6 = &UFG::gNullQSymbol;
    else
      v6 = &v5->mNames.p[v2];
  }
  else
  {
    v6 = (UFG::qSymbol *)&v5->mValues.p[v2];
  }
  v16.mUID = v6->mUID;
  if ( v16.mUID == -1 )
    return 0i64;
  v7 = UFG::StoreFrontTracker::Instance();
  UFG::PropertySetHandle::Bind(&v7->mProperties);
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v7->mProperties.mpPropSet,
         (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
         DEPTH_RECURSE);
  v9 = v8;
  if ( v8 && (v10 = v8->mNumElements, v11 = 0, v10) )
  {
    while ( 1 )
    {
      v12 = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
      if ( v12 && *(_QWORD *)v12 )
        v13 = &v12[*(_QWORD *)v12];
      else
        v13 = 0i64;
      if ( *((_DWORD *)v13 + 16) == v16.mUID )
        break;
      if ( ++v11 >= v10 )
        goto LABEL_19;
    }
  }
  else
  {
LABEL_19:
    v13 = 0i64;
    v14 = UFG::qSymbol::as_cstr_dbg(&v16);
    UFG::qPrintf("Warning: Could not find property set for item <%s> in StoreFront\n", v14);
  }
  return (UFG::qPropertySet *)v13;
}

// File Line: 685
// RVA: 0x4A41F0
UFG::qPropertySet *__fastcall UFG::StoreFront::GetItem(UFG::StoreFront *this, int filterIndex)
{
  UFG::StoreFront::ItemCategory v2; // edi
  char *v3; // rbx
  UFG::StoreFront *v4; // r10
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *v5; // rcx
  int v6; // er9
  int v7; // er8
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *i; // rax
  unsigned int v9; // edi
  UFG::qPropertyList *v10; // rax
  char *v11; // rax

  v2 = this->mCategoryFilter;
  v3 = 0i64;
  v4 = this;
  if ( v2 != 14 )
  {
    v5 = this->m_Items.mNode.mNext;
    v6 = 0;
    v7 = 0;
    if ( v5 == (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)&v4->m_Items )
    {
LABEL_7:
      filterIndex = -1;
      goto LABEL_8;
    }
    while ( 1 )
    {
      if ( WORD2(v5[1].mPrev) == v2 )
      {
        if ( v7 == filterIndex )
        {
          filterIndex = v6;
          break;
        }
        ++v7;
      }
      v5 = v5->mNext;
      ++v6;
      if ( v5 == (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)&v4->m_Items )
        goto LABEL_7;
    }
  }
LABEL_8:
  for ( i = v4->m_Items.mNode.mNext; filterIndex > 0; --filterIndex )
  {
    if ( i == (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)&v4->m_Items )
      break;
    i = i->mNext;
  }
  if ( !BYTE2(i[1].mPrev) )
    return UFG::StoreFront::GetStorageItem(v4, LOWORD(i[1].mPrev));
  v9 = LOWORD(i[1].mPrev);
  v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v4->mpPropertySet,
          (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
          DEPTH_RECURSE);
  if ( v10 )
  {
    v11 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v9);
    if ( v11 )
    {
      if ( *(_QWORD *)v11 )
        v3 = &v11[*(_QWORD *)v11];
    }
  }
  return (UFG::qPropertySet *)v3;
}

// File Line: 704
// RVA: 0x496890
bool __fastcall UFG::StoreFront::CanPurchase(UFG::StoreFront *this, int filterIndex)
{
  UFG::qPropertySet *v2; // rax
  float v3; // xmm6_4

  if ( this->mStoreType != 1 )
    return 0;
  v2 = UFG::StoreFront::GetItem(this, filterIndex);
  if ( !v2 )
    return 0;
  v3 = UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v2);
  return (float)UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[62].mValue >= v3;
}

// File Line: 726
// RVA: 0x4B3750
char __fastcall UFG::StoreFront::PurchaseItem(UFG::StoreFront *this, int filterIndex)
{
  int v2; // edi
  UFG::StoreFront *v3; // rbx
  UFG::qPropertySet *v4; // rsi
  UFG::qPropertySet *v5; // rax
  float v6; // xmm6_4
  UFG::StoreFront::InventoryType v7; // ebx
  UFG::StoreFrontTracker *v8; // rax

  v2 = filterIndex;
  v3 = this;
  v4 = UFG::StoreFront::GetItem(this, filterIndex);
  if ( !v4 )
    return 0;
  if ( v3->mStoreType != 1 )
    return 0;
  v5 = UFG::StoreFront::GetItem(v3, v2);
  if ( !v5 )
    return 0;
  v6 = UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v5);
  if ( (float)UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[62].mValue < v6 )
    return 0;
  v7 = v3->mInventoryType;
  v8 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::AddItemToInventory(v8, v4, v7, 1, 0);
  return 1;
}

// File Line: 740
// RVA: 0x4AD160
bool __fastcall UFG::StoreFront::IsWeiWearingAnPrefinedOutfit()
{
  UFG::GameStatTracker *v0; // rbx

  v0 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v0 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v0;
  return v0->mpSnapshots[0]->mIDs[21].mValue.mUID != -1;
}

// File Line: 751
// RVA: 0x4C8E10
__int64 __fastcall UFG::StoreFront::ValidateCustomOutfitItem(unsigned int itemId, __int64 defaultSymbol)
{
  unsigned int *v2; // rsi
  unsigned int v3; // edi
  UFG::GameStatTracker *v4; // rbx
  UFG::PersistentData::MapBool *v5; // r8
  __int64 v6; // rcx
  unsigned int v7; // er9
  bool v8; // al
  __int64 v9; // rcx
  unsigned int v10; // er9
  unsigned int v11; // er9
  __int64 v12; // rcx
  UFG::PersistentData::KeyValue *v13; // rdx
  bool v14; // zf
  __int64 v15; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h]

  v2 = (unsigned int *)defaultSymbol;
  v3 = itemId;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  UFG::qSymbol::qSymbol(&result, v3);
  v5 = v4->mpSnapshots[0]->mpMapBools[Asset_Clothing];
  if ( v5->mKeepType )
  {
    if ( v5->mKeepType == 1 )
    {
      v9 = 0i64;
      v10 = v5->mNames.size;
      if ( v10 )
      {
        while ( result.mUID != v5->mNames.p[v9].mUID )
        {
          v9 = (unsigned int)(v9 + 1);
          if ( (unsigned int)v9 >= v10 )
            goto LABEL_16;
        }
      }
      else
      {
LABEL_16:
        LODWORD(v9) = -1;
      }
      v8 = (_DWORD)v9 != -1;
LABEL_25:
      v14 = v8 == 1;
      v15 = v3;
      if ( v14 )
        return v15;
      return *v2;
    }
    v6 = (unsigned int)(v5->mKeepType - 2);
    if ( v5->mKeepType == 2 )
    {
      v7 = v5->mNames.size;
      if ( v7 )
      {
        while ( result.mUID != v5->mNames.p[v6].mUID )
        {
          v6 = (unsigned int)(v6 + 1);
          if ( (unsigned int)v6 >= v7 )
            goto LABEL_11;
        }
      }
      else
      {
LABEL_11:
        LODWORD(v6) = -1;
      }
      v8 = (_DWORD)v6 == -1;
      goto LABEL_25;
    }
  }
  else
  {
    v11 = v5->mValues.size;
    v12 = 0i64;
    if ( v11 )
    {
      v13 = v5->mValues.p;
      while ( v13->mKey.mUID != result.mUID )
      {
        v12 = (unsigned int)(v12 + 1);
        ++v13;
        if ( (unsigned int)v12 >= v11 )
          return *v2;
      }
      if ( (_DWORD)v12 != -1 )
      {
        v8 = v5->mValues.p[v12].mBoolValue;
        goto LABEL_25;
      }
    }
  }
  return *v2;
}

// File Line: 765
// RVA: 0x49E350
char __fastcall UFG::StoreFront::EquipCustomOutfit(UFG::StoreFront::OutfitNum a_eOutfitNum, bool bSaveToStats, bool bUpdateLastEquipItem)
{
  bool v3; // r13
  UFG::StoreFront::OutfitNum v4; // ebx
  UFG::GameStatTracker *v5; // rdi
  unsigned int v6; // ebx
  UFG::qSymbol *v7; // rax
  UFG::PersistentData::MapInt *v8; // r9
  unsigned int v9; // er8
  __int64 v10; // rcx
  UFG::PersistentData::KeyValue *v11; // r9
  UFG::PersistentData::KeyValue *v12; // rdx
  unsigned int v13; // ecx
  UFG::qSymbol *v14; // rax
  UFG::PersistentData::MapInt *v15; // r9
  unsigned int v16; // er8
  __int64 v17; // rcx
  UFG::PersistentData::KeyValue *v18; // r9
  UFG::PersistentData::KeyValue *v19; // rdx
  unsigned int v20; // ecx
  UFG::qSymbol *v21; // rax
  UFG::PersistentData::MapInt *v22; // r9
  unsigned int v23; // er8
  __int64 v24; // rcx
  UFG::PersistentData::KeyValue *v25; // r9
  UFG::PersistentData::KeyValue *v26; // rdx
  unsigned int v27; // ecx
  UFG::qSymbol *v28; // rax
  UFG::PersistentData::MapInt *v29; // r9
  unsigned int v30; // er8
  __int64 v31; // rcx
  UFG::PersistentData::KeyValue *v32; // r9
  UFG::PersistentData::KeyValue *v33; // rdx
  unsigned int v34; // ecx
  UFG::qSymbol *v35; // rax
  UFG::PersistentData::MapInt *v36; // r9
  unsigned int v37; // er8
  __int64 v38; // rcx
  UFG::PersistentData::KeyValue *v39; // r9
  UFG::PersistentData::KeyValue *v40; // rdx
  unsigned int v41; // ecx
  UFG::qSymbol *v42; // rax
  UFG::PersistentData::MapInt *v43; // r9
  unsigned int v44; // er8
  __int64 v45; // rcx
  UFG::PersistentData::KeyValue *v46; // r9
  UFG::PersistentData::KeyValue *v47; // rdx
  unsigned int v48; // ecx
  UFG::qSymbol *v49; // rax
  UFG::PersistentData::MapInt *v50; // r9
  unsigned int v51; // er8
  __int64 v52; // rcx
  UFG::PersistentData::KeyValue *v53; // r9
  UFG::PersistentData::KeyValue *v54; // rdx
  unsigned int v55; // ecx
  UFG::qSymbol *v56; // rax
  UFG::PersistentData::MapInt *v57; // r9
  unsigned int v58; // er8
  __int64 v59; // rcx
  UFG::PersistentData::KeyValue *v60; // r9
  UFG::PersistentData::KeyValue *v61; // rdx
  unsigned int v62; // ecx
  UFG::qSymbol *v63; // rax
  UFG::PersistentData::MapInt *v64; // r9
  unsigned int v65; // er8
  __int64 v66; // rcx
  UFG::PersistentData::KeyValue *v67; // r9
  UFG::PersistentData::KeyValue *v68; // rdx
  unsigned int v69; // ecx
  unsigned int *v70; // r15
  signed __int64 v71; // r12
  unsigned int v72; // ebx
  UFG::StoreFrontTracker *v73; // rdi
  UFG::qPropertyList *v74; // rax
  UFG::qPropertyList *v75; // r14
  unsigned int v76; // esi
  unsigned int v77; // edi
  char *v78; // rax
  UFG::qPropertySet *v79; // rcx
  UFG::StoreFront::ItemCategory v80; // eax
  UFG::SimObjectCharacter *v81; // rax
  int dest; // [rsp+38h] [rbp-38h]
  int v84; // [rsp+3Ch] [rbp-34h]
  int v85; // [rsp+40h] [rbp-30h]
  int v86; // [rsp+44h] [rbp-2Ch]
  int v87; // [rsp+4Ch] [rbp-24h]
  int v88; // [rsp+50h] [rbp-20h]
  int v89; // [rsp+54h] [rbp-1Ch]
  int v90; // [rsp+58h] [rbp-18h]
  int v91; // [rsp+5Ch] [rbp-14h]
  UFG::qWiseSymbol result; // [rsp+B0h] [rbp+40h]
  bool v93; // [rsp+C0h] [rbp+50h]
  UFG::qWiseSymbol *v94; // [rsp+C8h] [rbp+58h]

  v93 = bUpdateLastEquipItem;
  v3 = bSaveToStats;
  v4 = a_eOutfitNum;
  UFG::qMemSet(&dest, 0, 0x38u);
  v5 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  v6 = UFG::qSymbol::qSymbol(&result, v4 + 1)->mUID;
  v94 = &result;
  v7 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "P_JeansBase");
  v8 = v5->mpSnapshots[0]->mpMapInts[11];
  v9 = v8->mValues.size;
  v10 = 0i64;
  if ( !v8->mValues.size )
    goto LABEL_12;
  v11 = v8->mValues.p;
  v12 = v11;
  while ( v12->mKey.mUID != v6 )
  {
    v10 = (unsigned int)(v10 + 1);
    ++v12;
    if ( (unsigned int)v10 >= v9 )
      goto LABEL_12;
  }
  if ( (_DWORD)v10 != -1 )
    v13 = v11[v10].mIntValue;
  else
LABEL_12:
    v13 = 0;
  v84 = UFG::StoreFront::ValidateCustomOutfitItem(v13, (__int64)v7);
  v94 = &result;
  v14 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "S_SleekBase");
  v15 = v5->mpSnapshots[0]->mpMapInts[12];
  v16 = v15->mValues.size;
  v17 = 0i64;
  if ( !v15->mValues.size )
    goto LABEL_20;
  v18 = v15->mValues.p;
  v19 = v18;
  while ( v19->mKey.mUID != v6 )
  {
    v17 = (unsigned int)(v17 + 1);
    ++v19;
    if ( (unsigned int)v17 >= v16 )
      goto LABEL_20;
  }
  if ( (_DWORD)v17 != -1 )
    v20 = v18[v17].mIntValue;
  else
LABEL_20:
    v20 = 0;
  v85 = UFG::StoreFront::ValidateCustomOutfitItem(v20, (__int64)v14);
  v94 = &result;
  v21 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "DefaultHair");
  v22 = v5->mpSnapshots[0]->mpMapInts[5];
  v23 = v22->mValues.size;
  v24 = 0i64;
  if ( !v22->mValues.size )
    goto LABEL_28;
  v25 = v22->mValues.p;
  v26 = v25;
  while ( v26->mKey.mUID != v6 )
  {
    v24 = (unsigned int)(v24 + 1);
    ++v26;
    if ( (unsigned int)v24 >= v23 )
      goto LABEL_28;
  }
  if ( (_DWORD)v24 != -1 )
    v27 = v25[v24].mIntValue;
  else
LABEL_28:
    v27 = 0;
  v86 = UFG::StoreFront::ValidateCustomOutfitItem(v27, (__int64)v21);
  v94 = &result;
  v28 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "T_JacketBase");
  v29 = v5->mpSnapshots[0]->mpMapInts[8];
  v30 = v29->mValues.size;
  v31 = 0i64;
  if ( !v29->mValues.size )
    goto LABEL_36;
  v32 = v29->mValues.p;
  v33 = v32;
  while ( v33->mKey.mUID != v6 )
  {
    v31 = (unsigned int)(v31 + 1);
    ++v33;
    if ( (unsigned int)v31 >= v30 )
      goto LABEL_36;
  }
  if ( (_DWORD)v31 != -1 )
    v34 = v32[v31].mIntValue;
  else
LABEL_36:
    v34 = 0;
  dest = UFG::StoreFront::ValidateCustomOutfitItem(v34, (__int64)v28);
  v94 = &result;
  v35 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoChain");
  v36 = v5->mpSnapshots[0]->mpMapInts[13];
  v37 = v36->mValues.size;
  v38 = 0i64;
  if ( !v36->mValues.size )
    goto LABEL_44;
  v39 = v36->mValues.p;
  v40 = v39;
  while ( v40->mKey.mUID != v6 )
  {
    v38 = (unsigned int)(v38 + 1);
    ++v40;
    if ( (unsigned int)v38 >= v37 )
      goto LABEL_44;
  }
  if ( (_DWORD)v38 != -1 )
    v41 = v39[v38].mIntValue;
  else
LABEL_44:
    v41 = 0;
  v87 = UFG::StoreFront::ValidateCustomOutfitItem(v41, (__int64)v35);
  v94 = &result;
  v42 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoGlasses");
  v43 = v5->mpSnapshots[0]->mpMapInts[6];
  v44 = v43->mValues.size;
  v45 = 0i64;
  if ( !v43->mValues.size )
    goto LABEL_52;
  v46 = v43->mValues.p;
  v47 = v46;
  while ( v47->mKey.mUID != v6 )
  {
    v45 = (unsigned int)(v45 + 1);
    ++v47;
    if ( (unsigned int)v45 >= v44 )
      goto LABEL_52;
  }
  if ( (_DWORD)v45 != -1 )
    v48 = v46[v45].mIntValue;
  else
LABEL_52:
    v48 = 0;
  v88 = UFG::StoreFront::ValidateCustomOutfitItem(v48, (__int64)v42);
  v94 = &result;
  v49 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoChain");
  v50 = v5->mpSnapshots[0]->mpMapInts[7];
  v51 = v50->mValues.size;
  v52 = 0i64;
  if ( !v50->mValues.size )
    goto LABEL_60;
  v53 = v50->mValues.p;
  v54 = v53;
  while ( v54->mKey.mUID != v6 )
  {
    v52 = (unsigned int)(v52 + 1);
    ++v54;
    if ( (unsigned int)v52 >= v51 )
      goto LABEL_60;
  }
  if ( (_DWORD)v52 != -1 )
    v55 = v53[v52].mIntValue;
  else
LABEL_60:
    v55 = 0;
  v89 = UFG::StoreFront::ValidateCustomOutfitItem(v55, (__int64)v49);
  v94 = &result;
  v56 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoWatch");
  v57 = v5->mpSnapshots[0]->mpMapInts[9];
  v58 = v57->mValues.size;
  v59 = 0i64;
  if ( !v57->mValues.size )
    goto LABEL_68;
  v60 = v57->mValues.p;
  v61 = v60;
  while ( v61->mKey.mUID != v6 )
  {
    v59 = (unsigned int)(v59 + 1);
    ++v61;
    if ( (unsigned int)v59 >= v58 )
      goto LABEL_68;
  }
  if ( (_DWORD)v59 != -1 )
    v62 = v60[v59].mIntValue;
  else
LABEL_68:
    v62 = 0;
  v90 = UFG::StoreFront::ValidateCustomOutfitItem(v62, (__int64)v56);
  v94 = &result;
  v63 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoRightWrist");
  v64 = v5->mpSnapshots[0]->mpMapInts[10];
  v65 = v64->mValues.size;
  v66 = 0i64;
  if ( !v64->mValues.size )
    goto LABEL_76;
  v67 = v64->mValues.p;
  v68 = v67;
  while ( v68->mKey.mUID != v6 )
  {
    v66 = (unsigned int)(v66 + 1);
    ++v68;
    if ( (unsigned int)v66 >= v65 )
      goto LABEL_76;
  }
  if ( (_DWORD)v66 != -1 )
    v69 = v67[v66].mIntValue;
  else
LABEL_76:
    v69 = 0;
  v91 = UFG::StoreFront::ValidateCustomOutfitItem(v69, (__int64)v63);
  v70 = (unsigned int *)&dest;
  v71 = 14i64;
  do
  {
    if ( *v70 )
    {
      v72 = UFG::qSymbol::qSymbol(&result, *v70)->mUID;
      v73 = UFG::StoreFrontTracker::Instance();
      UFG::PropertySetHandle::Bind(&v73->mProperties);
      v74 = UFG::qPropertySet::Get<UFG::qPropertyList>(
              v73->mProperties.mpPropSet,
              (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
              DEPTH_RECURSE);
      v75 = v74;
      if ( v74 )
      {
        v76 = v74->mNumElements;
        v77 = 0;
        if ( v76 )
        {
          while ( 1 )
          {
            v78 = UFG::qPropertyList::GetValuePtr(v75, 0x1Au, v77);
            if ( v78 && *(_QWORD *)v78 )
              v79 = (UFG::qPropertySet *)&v78[*(_QWORD *)v78];
            else
              v79 = 0i64;
            if ( v79->mName.mUID == v72 )
              break;
            if ( ++v77 >= v76 )
              goto LABEL_89;
          }
          UFG::StoreFront::EquipItem(v79, v3, 0, 1, 1, 0);
        }
      }
    }
LABEL_89:
    ++v70;
    --v71;
  }
  while ( v71 );
  v80 = UFG::StoreFront::mLastEquipedItemCategory;
  if ( v93 )
    v80 = 11;
  UFG::StoreFront::mLastEquipedItemCategory = v80;
  v81 = UFG::GetLocalPlayer();
  UFG::StoreMeshHelper::QueueSwapping((UFG::SimObject *)&v81->vfptr);
  return 1;
}

// File Line: 818
// RVA: 0x4B7470
void __fastcall UFG::StoreFront::ResolveItemEquip(UFG::qPropertySet *pItem, UFG::SimObject *pPlayer, UFG::StreamedResourceComponent *pSrc, UFG::qArray<UFG::StoreFront::EquippedItemResolution,0> *resolvedEquipment)
{
  UFG::StreamedResourceComponent *v4; // r15
  UFG::qArray<UFG::StoreFront::EquippedItemResolution,0> *v5; // r14
  UFG::qPropertySet *v6; // rbp
  UFG::qSymbol *v7; // rbx
  signed __int64 v8; // rcx
  UFG::qPropertyList *v9; // rax
  UFG::qPropertyList *v10; // rsi
  unsigned int v11; // edi
  UFG::qSymbol *v12; // rbx
  signed __int64 v13; // rdx
  __int64 v14; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+18h]

  v4 = pSrc;
  v5 = resolvedEquipment;
  v6 = pItem;
  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(pItem, (UFG::qSymbol *)&qSymbol_ComponentType.mUID, DEPTH_RECURSE);
  UFG::TrueCrowdDataBase::Instance();
  v8 = (signed __int64)&v5->p[(unsigned int)UFG::TrueCrowdDefinition::GetEntityComponentIndex(
                                              &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
                                              v4->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex,
                                              v7)];
  if ( !*(_QWORD *)(v8 + 8) )
  {
    *(_QWORD *)(v8 + 8) = v6;
    UFG::qSymbol::create_from_string(&result, "ComponentExclusions");
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, &result, DEPTH_RECURSE);
    v10 = v9;
    if ( v9 )
    {
      v11 = 0;
      if ( v9->mNumElements )
      {
        do
        {
          v12 = UFG::qPropertyList::Get<UFG::qSymbol>(v10, v11);
          UFG::TrueCrowdDataBase::Instance();
          ++v11;
          v13 = (signed __int64)&v5->p[(unsigned int)UFG::TrueCrowdDefinition::GetEntityComponentIndex(
                                                       &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
                                                       v4->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex,
                                                       v12)];
          v14 = *(unsigned int *)(v13 + 152);
          *(_BYTE *)v13 = 1;
          *(_QWORD *)(v13 + 8 * v14 + 24) = v6;
          ++*(_DWORD *)(v13 + 152);
        }
        while ( v11 < v10->mNumElements );
      }
    }
  }
}

// File Line: 880
// RVA: 0x49E860
void __fastcall UFG::StoreFront::EquipItem(UFG::qPropertySet *pItem, bool bSaveToStats, bool bRefreshPlayer, bool bRemoveAnyPredefinedOutfit, bool bUpdateLastEquipItem, bool bPreviewing)
{
  bool v6; // r14
  UFG::qPropertySet *v7; // rsi
  UFG::SimObjectCharacter *v8; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // r9
  UFG::qSymbol *v11; // rax
  signed int v12; // edi
  UFG::StreamedResourceComponent *v13; // r15
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rax
  UFG::qSymbol *v16; // rbx
  UFG::StoreFrontTracker *v17; // rbx
  UFG::qPropertyList *v18; // rax
  UFG::qPropertyList *v19; // rsi
  unsigned int v20; // edi
  unsigned int v21; // ebx
  char *v22; // rax
  UFG::qPropertySet *v23; // rcx
  UFG::qPropertyList *v24; // r13
  unsigned int v25; // er12
  UFG::qSymbol *v26; // r15
  UFG::StoreFrontTracker *v27; // rbx
  UFG::qPropertyList *v28; // rax
  UFG::qPropertyList *v29; // r14
  unsigned int v30; // esi
  unsigned int v31; // ebx
  char *v32; // rax
  UFG::qPropertySet *v33; // rdi
  UFG::qSymbol *v34; // rbx
  int v35; // eax
  UFG::StoreFront::EquippedItemResolution *v36; // rbx
  bool v37; // si
  signed int v38; // er13
  UFG::qPropertyList *v39; // r12
  unsigned int v40; // er15
  UFG::qSymbol *v41; // r14
  UFG::qPropertyList *v42; // rax
  UFG::qPropertyList *v43; // rsi
  unsigned int v44; // edi
  unsigned int v45; // ebx
  char *v46; // rax
  UFG::qPropertySet *v47; // rcx
  unsigned int v48; // esi
  UFG::qPropertySet **v49; // r14
  UFG::qSymbol *v50; // rax
  __int64 v51; // rdi
  UFG::qPropertySet *v52; // rbx
  UFG::GameStatTracker *v53; // rcx
  unsigned int v54; // edx
  UFG::GameStatTracker *v55; // rcx
  UFG::GameStatTracker *v56; // r8
  signed __int64 v57; // r13
  int *v58; // r12
  signed __int64 v59; // rbx
  UFG::GameStatTracker *v60; // rax
  signed __int64 v61; // r15
  UFG::qPropertyList *v62; // rax
  UFG::qPropertyList *v63; // r14
  unsigned int v64; // esi
  unsigned int v65; // edi
  char *v66; // rax
  UFG::qPropertySet *v67; // rbx
  UFG::StoreFront::EquippedItemResolution *v68; // r14
  signed int v69; // er9
  UFG::StoreFront::EquippedItemResolution *v70; // rbx
  UFG::StoreFront::EquippedItemResolution *v71; // r11
  __int64 v72; // rdi
  int v73; // ecx
  unsigned int v74; // edx
  unsigned int v75; // er10
  unsigned int *v76; // rdx
  int v77; // ecx
  unsigned int v78; // er12
  UFG::qPropertySet **v79; // r14
  UFG::qSymbol *v80; // r13
  UFG::qPropertySet *v81; // rdi
  UFG::qSymbol *v82; // rax
  __int64 v83; // rsi
  signed __int64 v84; // rbx
  signed __int64 v85; // r15
  UFG::GameStatTracker *v86; // rcx
  int *v87; // rax
  int v88; // ebx
  unsigned int v89; // eax
  UFG::GameStatTracker *v90; // rcx
  int *v91; // rax
  int v92; // ebx
  unsigned int v93; // edx
  UFG::GameStatTracker *v94; // rbx
  UFG::GameStatTracker *v95; // rcx
  int v96; // eax
  signed int v97; // [rsp+30h] [rbp-69h]
  UFG::GameStat::IDStat equipmentType; // [rsp+34h] [rbp-65h]
  signed int v99; // [rsp+38h] [rbp-61h]
  unsigned int v100; // [rsp+3Ch] [rbp-5Dh]
  UFG::StreamedResourceComponent *pSrc; // [rsp+40h] [rbp-59h]
  UFG::qArray<UFG::StoreFront::EquippedItemResolution,0> resolvedEquipment; // [rsp+48h] [rbp-51h]
  UFG::SimObject *pPlayer; // [rsp+58h] [rbp-41h]
  int v104; // [rsp+60h] [rbp-39h]
  UFG::qSymbol result; // [rsp+64h] [rbp-35h]
  int v106; // [rsp+68h] [rbp-31h]
  int v107; // [rsp+6Ch] [rbp-2Dh]
  int v108; // [rsp+70h] [rbp-29h]
  __int64 v109; // [rsp+74h] [rbp-25h]
  int v110; // [rsp+7Ch] [rbp-1Dh]
  int v111; // [rsp+80h] [rbp-19h]
  int v112; // [rsp+84h] [rbp-15h]
  int v113; // [rsp+88h] [rbp-11h]
  __int64 v114; // [rsp+90h] [rbp-9h]
  UFG::qPropertySet *pItema; // [rsp+F0h] [rbp+57h]
  bool v116; // [rsp+F8h] [rbp+5Fh]
  bool v117; // [rsp+100h] [rbp+67h]
  bool v118; // [rsp+108h] [rbp+6Fh]

  v118 = bRemoveAnyPredefinedOutfit;
  v117 = bRefreshPlayer;
  v116 = bSaveToStats;
  pItema = pItem;
  v114 = -2i64;
  v6 = bRemoveAnyPredefinedOutfit;
  v7 = pItem;
  v8 = UFG::GetLocalPlayer();
  pPlayer = (UFG::SimObject *)&v8->vfptr;
  UFG::MeshResourceLoader::Unload(&UFG::StoreMeshHelper::sMeshLoader);
  UFG::StoreMeshHelper::sSwapQueued = 0;
  if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
  {
    v9 = UFG::StoreMeshHelper::sSwapTarget.mPrev;
    v10 = UFG::StoreMeshHelper::sSwapTarget.mNext;
    UFG::StoreMeshHelper::sSwapTarget.mPrev->mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    v10->mPrev = v9;
    UFG::StoreMeshHelper::sSwapTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
    UFG::StoreMeshHelper::sSwapTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
  }
  UFG::StoreMeshHelper::sSwapTarget.m_pPointer = 0i64;
  v11 = PropertyUtils::Get<UFG::qSymbol>(v7, (UFG::qSymbol *)&UFG::StoreItemSymbol_Category.mUID, DEPTH_RECURSE);
  v104 = UFG::StoreFront::MapItemCategory(v11);
  v12 = 4;
  v97 = 4;
  equipmentType = 15;
  switch ( v104 )
  {
    case 0:
      equipmentType = 15;
      goto LABEL_14;
    case 1:
      v12 = 7;
      equipmentType = 18;
      goto LABEL_14;
    case 2:
      v12 = 8;
      equipmentType = 19;
      goto LABEL_14;
    case 3:
      v12 = 0;
      equipmentType = 11;
      goto LABEL_14;
    case 4:
      v12 = 1;
      equipmentType = 12;
      goto LABEL_14;
    case 6:
      v12 = 2;
      equipmentType = 13;
      goto LABEL_14;
    case 7:
      v12 = 3;
      equipmentType = 14;
      goto LABEL_14;
    case 8:
      v12 = 5;
      equipmentType = 16;
      goto LABEL_14;
    case 9:
      v12 = 6;
      equipmentType = 17;
      goto LABEL_14;
    case 10:
      v12 = 10;
      equipmentType = 21;
LABEL_14:
      v97 = v12;
      break;
    default:
      break;
  }
  if ( v8 )
  {
    v14 = v8->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v13 = (UFG::StreamedResourceComponent *)v8->m_Components.p[10].m_pComponent;
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v13 = (UFG::StreamedResourceComponent *)v8->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v14 >> 12) & 1 )
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v8->vfptr,
                  UFG::StreamedResourceComponent::_TypeUID);
        else
          v15 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v8->vfptr,
                  UFG::StreamedResourceComponent::_TypeUID);
        v13 = (UFG::StreamedResourceComponent *)v15;
      }
    }
    else
    {
      v13 = (UFG::StreamedResourceComponent *)v8->m_Components.p[10].m_pComponent;
    }
  }
  else
  {
    v13 = 0i64;
  }
  pSrc = v13;
  v100 = v13->mMeshLoader.mTrueCrowdInstance.mNumParts;
  resolvedEquipment.p = 0i64;
  *(_QWORD *)&resolvedEquipment.size = 0i64;
  UFG::qArray<UFG::StoreFront::EquippedItemResolution,0>::Reallocate(
    &resolvedEquipment,
    v100,
    "qArray.Reallocate(Constructor)");
  resolvedEquipment.size = v100;
  if ( v12 == 10 )
  {
    v99 = -1;
  }
  else
  {
    v16 = UFG::qPropertySet::Get<UFG::qSymbol>(v7, (UFG::qSymbol *)&qSymbol_ComponentType.mUID, DEPTH_RECURSE);
    UFG::TrueCrowdDataBase::Instance();
    v99 = UFG::TrueCrowdDefinition::GetEntityComponentIndex(
            &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
            v13->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex,
            v16);
  }
  UFG::qSymbol::create_from_string(&result, "OutfitDefault");
  v17 = UFG::StoreFrontTracker::Instance();
  UFG::PropertySetHandle::Bind(&v17->mProperties);
  v18 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v17->mProperties.mpPropSet,
          (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
          DEPTH_RECURSE);
  v19 = v18;
  if ( v18 && (v20 = v18->mNumElements, v21 = 0, v20) )
  {
    while ( 1 )
    {
      v22 = UFG::qPropertyList::GetValuePtr(v19, 0x1Au, v21);
      if ( v22 && *(_QWORD *)v22 )
        v23 = (UFG::qPropertySet *)&v22[*(_QWORD *)v22];
      else
        v23 = 0i64;
      if ( v23->mName.mUID == result.mUID )
        break;
      if ( ++v21 >= v20 )
        goto LABEL_38;
    }
  }
  else
  {
LABEL_38:
    v23 = 0i64;
  }
  v24 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v23,
          (UFG::qSymbol *)&UFG::StoreItemSymbol_ClothingItemList.mUID,
          DEPTH_RECURSE);
  v25 = 0;
  if ( v24->mNumElements )
  {
    do
    {
      v26 = UFG::qPropertyList::Get<UFG::qSymbol>(v24, v25);
      v27 = UFG::StoreFrontTracker::Instance();
      UFG::PropertySetHandle::Bind(&v27->mProperties);
      v28 = UFG::qPropertySet::Get<UFG::qPropertyList>(
              v27->mProperties.mpPropSet,
              (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
              DEPTH_RECURSE);
      v29 = v28;
      if ( v28 && (v30 = v28->mNumElements, v31 = 0, v30) )
      {
        while ( 1 )
        {
          v32 = UFG::qPropertyList::GetValuePtr(v29, 0x1Au, v31);
          if ( v32 && *(_QWORD *)v32 )
            v33 = (UFG::qPropertySet *)&v32[*(_QWORD *)v32];
          else
            v33 = 0i64;
          if ( v33->mName.mUID == v26->mUID )
            break;
          if ( ++v31 >= v30 )
            goto LABEL_48;
        }
      }
      else
      {
LABEL_48:
        v33 = 0i64;
      }
      v34 = UFG::qPropertySet::Get<UFG::qSymbol>(v33, (UFG::qSymbol *)&qSymbol_ComponentType.mUID, DEPTH_RECURSE);
      UFG::TrueCrowdDataBase::Instance();
      v13 = pSrc;
      v35 = UFG::TrueCrowdDefinition::GetEntityComponentIndex(
              &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
              pSrc->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex,
              v34);
      v36 = resolvedEquipment.p;
      resolvedEquipment.p[v35].mDefaultItem = v33;
      ++v25;
    }
    while ( v25 < v24->mNumElements );
    v6 = v118;
  }
  else
  {
    v36 = resolvedEquipment.p;
  }
  v37 = bPreviewing;
  v38 = v97;
  if ( v97 != ItemCategory_OUTFIT )
  {
    UFG::StoreFront::ResolveItemEquip(pItema, pPlayer, v13, &resolvedEquipment);
    if ( !bPreviewing && v6 && UFG::StoreFront::IsWeiWearingAnPrefinedOutfit() )
    {
      v48 = 0;
      if ( v100 )
      {
        v49 = &v36->mDefaultItem;
        do
        {
          if ( v48 != v99 )
          {
            v50 = PropertyUtils::Get<UFG::qSymbol>(
                    *v49,
                    (UFG::qSymbol *)&UFG::StoreItemSymbol_Category.mUID,
                    DEPTH_RECURSE);
            v51 = CurrentBody;
            switch ( (unsigned int)UFG::StoreFront::MapItemCategory(v50) )
            {
              case 1u:
                v51 = CurrentLowerBody;
                break;
              case 2u:
                v51 = CurrentFootwear;
                break;
              case 3u:
                v51 = CurrentHeadgear;
                break;
              case 4u:
                v51 = CurrentHead;
                break;
              case 6u:
                v51 = CurrentGlasses;
                break;
              case 7u:
                v51 = CurrentNeck;
                break;
              case 8u:
                v51 = CurrentLeftWrist;
                break;
              case 9u:
                v51 = CurrentRightWrist;
                break;
              case 0xAu:
                v51 = CurrentOutfit;
                break;
              default:
                break;
            }
            v52 = *v49;
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            v53 = &sGameStatTracker;
            if ( UFG::GameStatTracker::mspInstance )
              v53 = UFG::GameStatTracker::mspInstance;
            UFG::GameStatTracker::mspInstance = v53;
            if ( !(*((_BYTE *)v53 + 6216) & 1) )
              v53->mpSnapshots[0]->mIDs[v51].mValue.mUID = v52->mName.mUID;
          }
          ++v48;
          v49 += 20;
        }
        while ( v48 < v100 );
      }
      UFG::StoreFrontTracker::Instance()->mClothingFashionValue[10] = 0;
      v54 = _S12_6;
      if ( !(_S12_6 & 1) )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v54 = _S12_6;
      }
      v55 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v55 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v55;
      if ( !(*((_BYTE *)v55 + 6216) & 1) )
      {
        v55->mpSnapshots[0]->mIDs[21].mValue = UFG::gNullQSymbol;
        v55 = UFG::GameStatTracker::mspInstance;
      }
      if ( !(v54 & 1) )
      {
        _S12_6 = v54 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v54 = _S12_6;
        v55 = UFG::GameStatTracker::mspInstance;
      }
      v56 = &sGameStatTracker;
      if ( v55 )
        v56 = v55;
      UFG::GameStatTracker::mspInstance = v56;
      if ( *((_BYTE *)v56 + 6216) & 1 )
      {
LABEL_104:
        v106 = 3;
        v107 = 4;
        v108 = 6;
        v109 = 7i64;
        v110 = 8;
        v57 = 9i64;
        v111 = 9;
        v112 = 1;
        v113 = 2;
        v58 = &v106;
        do
        {
          v59 = 15i64;
          switch ( *v58 )
          {
            case 1:
              v59 = 18i64;
              break;
            case 2:
              v59 = 19i64;
              break;
            case 3:
              v59 = 11i64;
              break;
            case 4:
              v59 = 12i64;
              break;
            case 6:
              v59 = 13i64;
              break;
            case 7:
              v59 = 14i64;
              break;
            case 8:
              v59 = 16i64;
              break;
            case 9:
              v59 = 17i64;
              break;
            case 10:
              v59 = 21i64;
              break;
            default:
              break;
          }
          if ( !(v54 & 1) )
          {
            _S12_6 = v54 | 1;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v54 = _S12_6;
            v56 = UFG::GameStatTracker::mspInstance;
          }
          v60 = &sGameStatTracker;
          if ( v56 )
            v60 = v56;
          v56 = v60;
          UFG::GameStatTracker::mspInstance = v60;
          v61 = (signed __int64)v60->mpSnapshots[0] + 4 * v59;
          if ( *(_DWORD *)(v61 + 480) != -1 )
          {
            if ( !(_S8_13 & 1) )
            {
              _S8_13 |= 1u;
              UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
              UFG::StoreFront::StoreFront(&stru_142408290, 0, 0, 0i64, 0i64);
              dword_1424083B8 = 0;
              UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
              atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
            }
            UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
            UFG::PropertySetHandle::Bind(&sStoreFrontTracker.mProperties);
            v62 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                    qword_142408288,
                    (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
                    DEPTH_RECURSE);
            v63 = v62;
            if ( v62 && (v64 = v62->mNumElements, v65 = 0, v64) )
            {
              while ( 1 )
              {
                v66 = UFG::qPropertyList::GetValuePtr(v63, 0x1Au, v65);
                if ( v66 && *(_QWORD *)v66 )
                  v67 = (UFG::qPropertySet *)&v66[*(_QWORD *)v66];
                else
                  v67 = 0i64;
                if ( v67->mName.mUID == *(_DWORD *)(v61 + 480) )
                  break;
                if ( ++v65 >= v64 )
                  goto LABEL_130;
              }
            }
            else
            {
LABEL_130:
              v67 = 0i64;
            }
            PropertyUtils::Get<UFG::qSymbol>(v67, (UFG::qSymbol *)&UFG::StoreItemSymbol_Category.mUID, DEPTH_RECURSE);
            UFG::StoreFront::ResolveItemEquip(v67, pPlayer, pSrc, &resolvedEquipment);
            v54 = _S12_6;
            v56 = UFG::GameStatTracker::mspInstance;
          }
          ++v58;
          --v57;
        }
        while ( v57 );
        goto LABEL_133;
      }
      v56->mpSnapshots[0]->mIDs[10].mValue = UFG::gNullQSymbol;
    }
    else
    {
      v54 = _S12_6;
    }
    v56 = UFG::GameStatTracker::mspInstance;
    goto LABEL_104;
  }
  v39 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          pItema,
          (UFG::qSymbol *)&UFG::StoreItemSymbol_ClothingItemList.mUID,
          (UFG::qPropertyDepth)(v97 - 9));
  v40 = 0;
  if ( v39->mNumElements )
  {
    do
    {
      v41 = UFG::qPropertyList::Get<UFG::qSymbol>(v39, v40);
      if ( !(_S8_13 & 1) )
      {
        _S8_13 |= 1u;
        UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
        UFG::StoreFront::StoreFront(&stru_142408290, 0, 0, 0i64, 0i64);
        dword_1424083B8 = 0;
        UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
        atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
      }
      UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
      UFG::PropertySetHandle::Bind(&sStoreFrontTracker.mProperties);
      v42 = UFG::qPropertySet::Get<UFG::qPropertyList>(
              qword_142408288,
              (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
              DEPTH_RECURSE);
      v43 = v42;
      if ( v42 && (v44 = v42->mNumElements, v45 = 0, v44) )
      {
        while ( 1 )
        {
          v46 = UFG::qPropertyList::GetValuePtr(v43, 0x1Au, v45);
          if ( v46 && *(_QWORD *)v46 )
            v47 = (UFG::qPropertySet *)&v46[*(_QWORD *)v46];
          else
            v47 = 0i64;
          if ( v47->mName.mUID == v41->mUID )
            break;
          if ( ++v45 >= v44 )
            goto LABEL_64;
        }
      }
      else
      {
LABEL_64:
        v47 = 0i64;
      }
      UFG::StoreFront::ResolveItemEquip(v47, pPlayer, pSrc, &resolvedEquipment);
      ++v40;
    }
    while ( v40 < v39->mNumElements );
LABEL_133:
    v38 = v97;
    v37 = bPreviewing;
  }
  if ( v37 && v38 != 10 )
  {
    v68 = resolvedEquipment.p;
    if ( v100 )
    {
      v69 = v99;
      v70 = &resolvedEquipment.p[v99];
      v71 = resolvedEquipment.p;
      v72 = v100;
      do
      {
        v73 = 0;
        v74 = v70->mExcludedByCount;
        if ( v74 )
        {
          while ( v70->mExcludedBy[v73] != v71->mItem )
          {
            if ( ++v73 >= v74 )
              goto LABEL_153;
          }
          v75 = 0;
          v76 = &v68->mExcludedByCount;
          do
          {
            if ( v69 == v75 )
            {
              *((_BYTE *)v76 - 152) = 0;
            }
            else
            {
              v77 = 0;
              if ( *v76 )
              {
                while ( *(UFG::qPropertySet **)&v76[2 * v77 - 32] != v71->mItem )
                {
                  if ( ++v77 >= *v76 )
                    goto LABEL_150;
                }
                *((_WORD *)v76 - 76) = 0;
                *((_QWORD *)v76 - 18) = 0i64;
LABEL_150:
                v69 = v99;
              }
            }
            ++v75;
            v76 += 40;
          }
          while ( v75 < v100 );
          v71->mItem = 0i64;
          v71->mSetCurrentStat = 0;
        }
LABEL_153:
        ++v71;
        --v72;
      }
      while ( v72 );
    }
  }
  else
  {
    v68 = resolvedEquipment.p;
  }
  v78 = 0;
  if ( v100 )
  {
    v79 = &v68->mDefaultItem;
    v80 = 0i64;
    do
    {
      v81 = *(v79 - 1);
      if ( !v81 )
        v81 = *v79;
      v82 = PropertyUtils::Get<UFG::qSymbol>(v81, (UFG::qSymbol *)&UFG::StoreItemSymbol_Category.mUID, DEPTH_RECURSE);
      v83 = (signed int)UFG::StoreFront::MapItemCategory(v82);
      v84 = 15i64;
      v85 = 4i64;
      switch ( (_DWORD)v83 )
      {
        case 1:
          v84 = 18i64;
          v85 = 7i64;
          break;
        case 2:
          v84 = 19i64;
          v85 = 8i64;
          break;
        case 3:
          v85 = 0i64;
          v84 = 11i64;
          break;
        case 4:
          v84 = 12i64;
          v85 = 1i64;
          break;
        case 6:
          v84 = 13i64;
          v85 = 2i64;
          break;
        case 7:
          v84 = CurrentNeck;
          v85 = Neck;
          break;
        case 8:
          v84 = 16i64;
          v85 = 5i64;
          break;
        case 9:
          v84 = 17i64;
          v85 = 6i64;
          break;
        case 0xA:
          v84 = 21i64;
          v85 = 10i64;
          break;
        default:
          break;
      }
      PropertyUtils::Get<UFG::qSymbol>(v81, (UFG::qSymbol *)&qSymbol_ComponentType.mUID, DEPTH_RECURSE);
      if ( *((_BYTE *)v79 - 15) )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        v86 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v86 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v86;
        if ( !(*((_BYTE *)v86 + 6216) & 1) )
          v86->mpSnapshots[0]->mIDs[v84].mValue.mUID = v81->mName.mUID;
      }
      v87 = UFG::qPropertySet::Get<long>(v81, (UFG::qSymbol *)&UFG::StoreItemSymbol_FashionValue.mUID, DEPTH_RECURSE);
      if ( v87 )
        v88 = *v87;
      else
        v88 = 0;
      if ( !(_S8_13 & 1) )
      {
        _S8_13 |= 1u;
        UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
        UFG::StoreFront::StoreFront(&stru_142408290, 0, 0, 0i64, 0i64);
        dword_1424083B8 = 0;
        UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
        atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
      }
      UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
      sStoreFrontTracker.mClothingFashionValue[v83] = v88;
      if ( *((_BYTE *)v79 - 16) )
      {
        if ( v78 != -1 )
        {
          v89 = UFG::gNullQSymbol.mUID;
          v80[1351621648].mUID = UFG::gNullQSymbol.mUID;
          v80[1351622268].mUID = v89;
          v80[1351619876].mUID = 0;
        }
      }
      else
      {
        UFG::StoreMeshHelper::CommitResource(pPlayer, v81);
      }
      if ( v116 )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        v90 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v90 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v90;
        if ( !(*((_BYTE *)v90 + 6216) & 1) )
          v90->mpSnapshots[0]->mIDs[v85].mValue.mUID = v81->mName.mUID;
      }
      v37 = bPreviewing;
      if ( !bPreviewing )
        UFG::StoreFront::ProcessClothingSetBonuses(equipmentType);
      ++v78;
      v79 += 20;
      ++v80;
    }
    while ( v78 < v100 );
  }
  if ( v97 == 10 )
  {
    v91 = UFG::qPropertySet::Get<long>(pItema, (UFG::qSymbol *)&UFG::StoreItemSymbol_FashionValue.mUID, DEPTH_RECURSE);
    if ( v91 )
      v92 = *v91;
    else
      v92 = 0;
    if ( !(_S8_13 & 1) )
    {
      _S8_13 |= 1u;
      UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
      UFG::StoreFront::StoreFront(&stru_142408290, 0, 0, 0i64, 0i64);
      dword_1424083B8 = 0;
      UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
      atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
    }
    UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
    dword_1424083E4 = v92;
    v93 = _S12_6;
    if ( _S12_6 & 1 )
    {
      v94 = &sGameStatTracker;
    }
    else
    {
      _S12_6 |= 1u;
      v94 = &sGameStatTracker;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      v93 = _S12_6;
    }
    v95 = &sGameStatTracker;
    if ( UFG::GameStatTracker::mspInstance )
      v95 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v95;
    if ( !(*((_BYTE *)v95 + 6216) & 1) )
    {
      v95->mpSnapshots[0]->mIDs[21].mValue.mUID = pItema->mName.mUID;
      v95 = UFG::GameStatTracker::mspInstance;
    }
    if ( v116 )
    {
      if ( !(v93 & 1) )
      {
        _S12_6 = v93 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v95 = UFG::GameStatTracker::mspInstance;
      }
      if ( v95 )
        v94 = v95;
      UFG::GameStatTracker::mspInstance = v94;
      if ( !(*((_BYTE *)v94 + 6216) & 1) )
        v94->mpSnapshots[0]->mIDs[10].mValue.mUID = pItema->mName.mUID;
    }
    if ( !v37 )
      UFG::StoreFront::ProcessClothingSetBonuses(CurrentOutfit);
  }
  v96 = UFG::StoreFront::mLastEquipedItemCategory;
  if ( bUpdateLastEquipItem )
    v96 = v104;
  UFG::StoreFront::mLastEquipedItemCategory = v96;
  if ( v117 )
    UFG::StoreMeshHelper::QueueSwapping(pPlayer);
  if ( resolvedEquipment.p )
    operator delete[](resolvedEquipment.p);
}

// File Line: 1175
// RVA: 0x4B2460
void UFG::StoreFront::PreviewRemoveCustomOutfit(void)
{
  UFG::StoreFrontTracker *v0; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // rsi
  unsigned int v3; // edi
  unsigned int v4; // ebx
  char *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r13
  signed int v9; // er15
  signed int i; // ebp
  UFG::qSymbol *v11; // r14
  UFG::StoreFrontTracker *v12; // rbx
  UFG::qPropertyList *v13; // rax
  UFG::qPropertyList *v14; // rsi
  unsigned int v15; // edi
  unsigned int v16; // ebx
  char *v17; // rax
  UFG::qPropertySet *v18; // rcx
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]

  UFG::qSymbol::create_from_string(&result, "OutfitDefault");
  v0 = UFG::StoreFrontTracker::Instance();
  UFG::PropertySetHandle::Bind(&v0->mProperties);
  v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v0->mProperties.mpPropSet,
         (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
         DEPTH_RECURSE);
  v2 = v1;
  if ( v1 )
  {
    v3 = v1->mNumElements;
    v4 = 0;
    if ( v3 )
    {
      while ( 1 )
      {
        v5 = UFG::qPropertyList::GetValuePtr(v2, 0x1Au, v4);
        if ( v5 && *(_QWORD *)v5 )
          v6 = (UFG::qPropertySet *)&v5[*(_QWORD *)v5];
        else
          v6 = 0i64;
        if ( v6->mName.mUID == result.mUID )
          break;
        if ( ++v4 >= v3 )
          return;
      }
      v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             v6,
             (UFG::qSymbol *)&UFG::StoreItemSymbol_ClothingItemList.mUID,
             DEPTH_RECURSE);
      v8 = v7;
      if ( v7 )
      {
        v9 = v7->mNumElements;
        for ( i = 0; i < v9; ++i )
        {
          v11 = UFG::qPropertyList::Get<UFG::qSymbol>(v8, i);
          v12 = UFG::StoreFrontTracker::Instance();
          UFG::PropertySetHandle::Bind(&v12->mProperties);
          v13 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  v12->mProperties.mpPropSet,
                  (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
                  DEPTH_RECURSE);
          v14 = v13;
          if ( v13 )
          {
            v15 = v13->mNumElements;
            v16 = 0;
            if ( v15 )
            {
              while ( 1 )
              {
                v17 = UFG::qPropertyList::GetValuePtr(v14, 0x1Au, v16);
                if ( v17 && *(_QWORD *)v17 )
                  v18 = (UFG::qPropertySet *)&v17[*(_QWORD *)v17];
                else
                  v18 = 0i64;
                if ( v18->mName.mUID == v11->mUID )
                  break;
                if ( ++v16 >= v15 )
                  goto LABEL_22;
              }
              UFG::StoreFront::EquipItem(v18, 0, 1, 1, 1, 1);
            }
          }
LABEL_22:
          ;
        }
      }
    }
  }
}

// File Line: 1210
// RVA: 0x4B2610
void __fastcall UFG::StoreFront::ProcessClothingSetBonuses(UFG::GameStat::IDStat equipmentType)
{
  UFG::GameSnapshot *v1; // rbx
  UFG::StoreFrontTracker *v2; // rax
  UFG::qPropertySet *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::eClothingBuffEnum v6; // eax
  UFG::GameStatTracker *v7; // rax
  UFG::GameSnapshot *v8; // rbx
  UFG::StoreFrontTracker *v9; // rax
  UFG::qPropertySet *v10; // rax
  UFG::qSymbol *v11; // rax
  int v12; // ebx
  UFG::GameStatTracker *v13; // rax
  int v14; // er8
  UFG::GameStat::Int32Stat v15; // edx
  UFG::GameStatTracker *v16; // rax
  UFG::GameSnapshot *v17; // rbx
  UFG::StoreFrontTracker *v18; // rax
  UFG::qPropertySet *v19; // rax
  UFG::qSymbol *v20; // rax
  int v21; // ebx
  UFG::GameStatTracker *v22; // rax
  UFG::GameSnapshot *v23; // rbx
  UFG::StoreFrontTracker *v24; // rax
  UFG::qPropertySet *v25; // rax
  UFG::qSymbol *v26; // rax
  int v27; // ebx
  UFG::GameStatTracker *v28; // rax
  UFG::GameSnapshot *v29; // rbx
  UFG::StoreFrontTracker *v30; // rax
  UFG::qPropertySet *v31; // rax
  UFG::qSymbol *v32; // rax
  int v33; // ebx
  UFG::GameStatTracker *v34; // rax
  UFG::GameSnapshot *v35; // rbx
  UFG::StoreFrontTracker *v36; // rax
  UFG::qPropertySet *v37; // rax
  UFG::qSymbol *v38; // rax
  int v39; // ebx
  UFG::GameStatTracker *v40; // rdi
  UFG::GameStatTracker *v41; // rbx
  UFG::qSymbol *v42; // rbx
  UFG::StoreFrontTracker *v43; // rax
  UFG::qPropertySet *v44; // rbp
  UFG::GameStatTracker *v45; // rbx
  UFG::qSymbol *v46; // rbx
  UFG::StoreFrontTracker *v47; // rax
  UFG::qPropertySet *v48; // rsi
  UFG::qSymbol *v49; // rbx
  UFG::StoreFrontTracker *v50; // rax
  UFG::qPropertySet *v51; // rax
  UFG::qPropertySet *v52; // rbx
  UFG::qSymbol *v53; // rbp
  UFG::qSymbol *v54; // rsi
  UFG::qSymbol *v55; // rax
  UFG::qSymbol *v56; // rdi
  UFG::eClothingBuffEnum v57; // ebx

  if ( (unsigned int)(equipmentType - 18) > 1 && equipmentType != 15 )
  {
    switch ( equipmentType )
    {
      case 21:
        v1 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v2 = UFG::StoreFrontTracker::Instance();
        v3 = UFG::StoreFrontTracker::FindItemSlow(v2, &v1->mIDs[21].mValue);
        if ( v3 )
        {
          v4 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v4, ClothingSetBuff, 0);
          v5 = PropertyUtils::Get<UFG::qSymbol>(v3, (UFG::qSymbol *)&SimSym_ClothingSetBuff.mUID, DEPTH_RECURSE);
          if ( v5 )
          {
            v6 = (unsigned int)UFG::StoreFront::LookupClothingBuff(v5);
            UFG::StoreFront::SetClothingSetBuff(v6);
          }
        }
        return;
      case 11:
        v7 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v7, ClothingBuffHat, 0);
        v8 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v9 = UFG::StoreFrontTracker::Instance();
        v10 = UFG::StoreFrontTracker::FindItemSlow(v9, &v8->mIDs[11].mValue);
        if ( !v10 )
          return;
        v11 = UFG::qPropertySet::Get<UFG::qSymbol>(v10, (UFG::qSymbol *)&SimSym_ClothingItemBuff.mUID, DEPTH_RECURSE);
        if ( !v11 )
          return;
        v12 = UFG::StoreFront::LookupClothingBuff(v11);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v12;
        v15 = 38;
        break;
      case 14:
        v16 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v16, ClothingBuffNeck, 0);
        v17 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v18 = UFG::StoreFrontTracker::Instance();
        v19 = UFG::StoreFrontTracker::FindItemSlow(v18, &v17->mIDs[14].mValue);
        if ( !v19 )
          return;
        v20 = UFG::qPropertySet::Get<UFG::qSymbol>(v19, (UFG::qSymbol *)&SimSym_ClothingItemBuff.mUID, DEPTH_RECURSE);
        if ( !v20 )
          return;
        v21 = UFG::StoreFront::LookupClothingBuff(v20);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v21;
        v15 = 39;
        break;
      case 13:
        v22 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v22, ClothingBuffGlasses, 0);
        v23 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v24 = UFG::StoreFrontTracker::Instance();
        v25 = UFG::StoreFrontTracker::FindItemSlow(v24, &v23->mIDs[13].mValue);
        if ( !v25 )
          return;
        v26 = UFG::qPropertySet::Get<UFG::qSymbol>(v25, (UFG::qSymbol *)&SimSym_ClothingItemBuff.mUID, DEPTH_RECURSE);
        if ( !v26 )
          return;
        v27 = UFG::StoreFront::LookupClothingBuff(v26);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v27;
        v15 = 40;
        break;
      case 16:
        v28 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v28, ClothingBuffLeftWrist, 0);
        v29 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v30 = UFG::StoreFrontTracker::Instance();
        v31 = UFG::StoreFrontTracker::FindItemSlow(v30, &v29->mIDs[16].mValue);
        if ( !v31 )
          return;
        v32 = UFG::qPropertySet::Get<UFG::qSymbol>(v31, (UFG::qSymbol *)&SimSym_ClothingItemBuff.mUID, DEPTH_RECURSE);
        if ( !v32 )
          return;
        v33 = UFG::StoreFront::LookupClothingBuff(v32);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v33;
        v15 = 41;
        break;
      case 17:
        v34 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v34, ClothingBuffRightWrist, 0);
        v35 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v36 = UFG::StoreFrontTracker::Instance();
        v37 = UFG::StoreFrontTracker::FindItemSlow(v36, &v35->mIDs[17].mValue);
        if ( !v37 )
          return;
        v38 = UFG::qPropertySet::Get<UFG::qSymbol>(v37, (UFG::qSymbol *)&SimSym_ClothingItemBuff.mUID, DEPTH_RECURSE);
        if ( !v38 )
          return;
        v39 = UFG::StoreFront::LookupClothingBuff(v38);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v39;
        v15 = 42;
        break;
      default:
        return;
    }
LABEL_50:
    UFG::GameStatTracker::SetStat(v13, v15, v14);
    return;
  }
  v40 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v41 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v41 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v41;
  v42 = (UFG::qSymbol *)v41->mpSnapshots[0];
  v43 = UFG::StoreFrontTracker::Instance();
  v44 = UFG::StoreFrontTracker::FindItemSlow(v43, v42 + 138);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v45 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v45 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v45;
  v46 = (UFG::qSymbol *)v45->mpSnapshots[0];
  v47 = UFG::StoreFrontTracker::Instance();
  v48 = UFG::StoreFrontTracker::FindItemSlow(v47, v46 + 135);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v40 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v40;
  v49 = (UFG::qSymbol *)v40->mpSnapshots[0];
  v50 = UFG::StoreFrontTracker::Instance();
  v51 = UFG::StoreFrontTracker::FindItemSlow(v50, v49 + 139);
  v52 = v51;
  if ( v44 )
  {
    if ( v48 )
    {
      if ( v51 )
      {
        v53 = PropertyUtils::Get<UFG::qSymbol>(v44, (UFG::qSymbol *)&SimSym_ClothingSetBuff.mUID, DEPTH_RECURSE);
        v54 = PropertyUtils::Get<UFG::qSymbol>(v48, (UFG::qSymbol *)&SimSym_ClothingSetBuff.mUID, DEPTH_RECURSE);
        v55 = PropertyUtils::Get<UFG::qSymbol>(v52, (UFG::qSymbol *)&SimSym_ClothingSetBuff.mUID, DEPTH_RECURSE);
        v56 = v55;
        if ( v53 )
        {
          if ( v54 && v55 )
          {
            v57 = (unsigned int)UFG::StoreFront::LookupClothingBuff(v53);
            if ( v57 == (unsigned int)UFG::StoreFront::LookupClothingBuff(v54)
              && v57 == (unsigned int)UFG::StoreFront::LookupClothingBuff(v56) )
            {
              UFG::StoreFront::SetClothingSetBuff(v57);
              return;
            }
            if ( UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[37].mValue )
            {
              v13 = UFG::GameStatTracker::Instance();
              v14 = 0;
              v15 = 37;
              goto LABEL_50;
            }
          }
        }
      }
    }
  }
}

// File Line: 1358
// RVA: 0x4BBCD0
void __fastcall UFG::StoreFront::SetClothingSetBuff(UFG::eClothingBuffEnum buffType)
{
  UFG::eClothingBuffEnum v1; // ebx
  UFG::GameStatTracker *v2; // rax
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v4; // [rsp+48h] [rbp+10h]

  if ( (signed int)buffType > 0 )
  {
    v1 = buffType;
    if ( (signed int)buffType <= 25 || (unsigned int)(buffType - 30) <= 0x34 )
    {
      v2 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v2 + 6216) & 1) )
      {
        v2->mpSnapshots[0]->mInts[37].mValue = v1;
        v4 = &mapid;
        mapid.mUID = UFG::gNullQSymbol.mUID;
        UFG::GameStatAction::PostStat::Achieve(PDT_INT, 37, (__int64)&mapid);
      }
    }
  }
}

// File Line: 1446
// RVA: 0x4B0BB0
__int64 __fastcall UFG::StoreFront::LookupClothingBuff(UFG::qSymbol *sym)
{
  unsigned int v1; // edx
  UFG::qStaticSymbol *v2; // rax

  v1 = 0;
  v2 = UFG::ClothingBuffEnumSymbols;
  while ( sym->mUID != v2->mUID )
  {
    ++v2;
    ++v1;
    if ( (signed __int64)v2 >= (signed __int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_CAMERA )
      return 0i64;
  }
  return v1;
}

// File Line: 1461
// RVA: 0x4B0BE0
UFG::qSymbol *__fastcall UFG::StoreFront::LookupClothingBuffSymbol(UFG::qSymbol *result, UFG::eClothingBuffEnum eBuff)
{
  result->mUID = UFG::ClothingBuffEnumSymbols[eBuff].mUID;
  return result;
}

// File Line: 1468
// RVA: 0x4A1F60
UFG::qSymbol *__fastcall UFG::StoreFront::GetClothingBuffFromItem(UFG::StoreFront *this, UFG::qSymbol *result, UFG::qPropertySet *pItem)
{
  UFG::qSymbol *v3; // rbx
  UFG::qSymbol *v4; // rax

  v3 = result;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(pItem, (UFG::qSymbol *)&SimSym_ClothingSetBuff.mUID, DEPTH_RECURSE);
  if ( v4 )
    v3->mUID = v4->mUID;
  else
    v3->mUID = -1;
  return v3;
}

// File Line: 1480
// RVA: 0x4A42D0
UFG::qSymbol *__fastcall UFG::StoreFront::GetItemBuffFromItem(UFG::StoreFront *this, UFG::qSymbol *result, UFG::qPropertySet *pItem)
{
  UFG::qSymbol *v3; // rbx
  UFG::qSymbol *v4; // rax

  v3 = result;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(pItem, (UFG::qSymbol *)&SimSym_ClothingItemBuff.mUID, DEPTH_RECURSE);
  if ( v4 )
    v3->mUID = v4->mUID;
  else
    v3->mUID = -1;
  return v3;
}

// File Line: 1493
// RVA: 0x4ACB80
bool __fastcall UFG::StoreFront::IsOwned(UFG::StoreFront *this, int filterIndex)
{
  UFG::StoreFront *v2; // rbx
  UFG::qPropertySet *v3; // rax

  v2 = this;
  v3 = UFG::StoreFront::GetItem(this, filterIndex);
  return UFG::StoreFront::IsOwned(v2, v3);
}

// File Line: 1506
// RVA: 0x4ACAF0
bool __fastcall UFG::StoreFront::IsOwned(UFG::StoreFront *this, UFG::qPropertySet *pItem)
{
  UFG::qPropertySet *v2; // rdi
  __int64 v3; // rsi
  UFG::GameStatTracker *v4; // rbx

  v2 = pItem;
  v3 = this->mInventoryType;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  return UFG::PersistentData::MapBool::GetStatus(v4->mpSnapshots[0]->mpMapBools[v3], &v2->mName);
}

// File Line: 1515
// RVA: 0x4ABBD0
char __fastcall UFG::StoreFront::IsClothingSetItemOwned(UFG::StoreFront *this, UFG::StoreFront::ItemCategory eItemSearchCategory, __int64 itemClothingSet)
{
  UFG::StoreFront *v3; // r13
  __int64 v4; // rdi
  UFG::GameStatTracker *v5; // rbx
  UFG::PersistentData::MapFloat *v6; // r12
  unsigned int i; // er14
  unsigned int v8; // edx
  bool v9; // cf
  UFG::qSymbol *v10; // rdx
  unsigned int v11; // ebx
  UFG::StoreFrontTracker *v12; // rdi
  UFG::qPropertyList *v13; // rax
  UFG::qPropertyList *v14; // r15
  unsigned int v15; // ebp
  unsigned int v16; // esi
  char *v17; // rax
  UFG::qPropertySet *v18; // rdi
  UFG::qSymbol *v19; // rax
  int v20; // eax
  UFG::qSymbol *v21; // rax
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-50h]
  UFG::qSymbol v24; // [rsp+80h] [rbp+8h]
  UFG::StoreFront::ItemCategory v25; // [rsp+88h] [rbp+10h]
  _DWORD *v26; // [rsp+90h] [rbp+18h]

  v26 = (_DWORD *)itemClothingSet;
  v25 = eItemSearchCategory;
  v3 = this;
  v4 = this->mInventoryType;
  v5 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  UFG::PersistentData::MapInt::GetIterator((UFG::PersistentData::MapFloat *)v5->mpSnapshots[0]->mpMapBools[v4], &result);
  v6 = result.mList;
  for ( i = result.mIndex; ; ++i )
  {
    v8 = v6->mValues.size;
    if ( v6->mValues.size )
    {
      if ( v8 - 1 > 1 )
        return 0;
      v9 = i < v6[1].mValues.size;
    }
    else
    {
      v9 = i < LODWORD(v6->mValues.p);
    }
    if ( !v9 )
      break;
    if ( v8 )
    {
      if ( v8 != 1 )
        continue;
    }
    else if ( !*(_BYTE *)(*(_QWORD *)&v6->mPersistentDataType + 8i64 * i + 4) )
    {
      continue;
    }
    if ( v8 )
    {
      if ( v8 - 1 > 1 )
        v10 = &UFG::gNullQSymbol;
      else
        v10 = (UFG::qSymbol *)((char *)v6[1].mValues.p + 4 * i);
    }
    else
    {
      v10 = (UFG::qSymbol *)(*(_QWORD *)&v6->mPersistentDataType + 8i64 * i);
    }
    v11 = v10->mUID;
    v12 = UFG::StoreFrontTracker::Instance();
    UFG::PropertySetHandle::Bind(&v12->mProperties);
    v13 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v12->mProperties.mpPropSet,
            (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
            DEPTH_RECURSE);
    v14 = v13;
    if ( v13 )
    {
      v15 = v13->mNumElements;
      v16 = 0;
      if ( v15 )
      {
        while ( 1 )
        {
          v17 = UFG::qPropertyList::GetValuePtr(v14, 0x1Au, v16);
          if ( v17 && *(_QWORD *)v17 )
            v18 = (UFG::qPropertySet *)&v17[*(_QWORD *)v17];
          else
            v18 = 0i64;
          if ( v18->mName.mUID == v11 )
            break;
          if ( ++v16 >= v15 )
            goto LABEL_31;
        }
        v19 = PropertyUtils::Get<UFG::qSymbol>(v18, (UFG::qSymbol *)&UFG::StoreItemSymbol_Category.mUID, DEPTH_RECURSE);
        v20 = UFG::StoreFront::MapItemCategory(v19);
        if ( v20 == v25 )
        {
          v21 = UFG::StoreFront::GetClothingBuffFromItem(v3, &v24, v18);
          if ( v21->mUID == *v26 )
            return 1;
        }
      }
    }
LABEL_31:
    ;
  }
  return 0;
}

// File Line: 1562
// RVA: 0x496B60
void UFG::StoreFront::CheckAchievement(void)
{
  UFG::SimObjectCharacter *v0; // rbx
  UFG::qSymbol *v1; // rax
  UFG::qPropertySet *v2; // rsi
  UFG::GameStatTracker *v3; // rdi
  UFG::GameStat::IDStat *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]

  v0 = UFG::GetLocalPlayer();
  v1 = UFG::qSymbol::create_from_string(&result, UFG::StoreFront_SaveGameDefaults);
  v2 = UFG::PropertySetManager::GetPropertySet(v1);
  if ( v0 )
  {
    v3 = UFG::GameStatTracker::Instance();
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( unk_14240BAE0 == gDefaultFlowId.mUID )
    {
      v4 = equipmentTypes;
      while ( 1 )
      {
        v5 = PropertyUtils::Get<UFG::qSymbol>(v2, IDSymbols[*(signed int *)v4], DEPTH_RECURSE);
        if ( v5 )
        {
          if ( v5->mUID == v3->mpSnapshots[0]->mIDs[*(signed int *)v4].mValue.mUID )
            break;
        }
        ++v4;
        if ( (signed __int64)v4 >= (signed __int64)"default-unlockables-merchantdatabase-clothing" )
        {
          UFG::AchievementTrophyManager::UnlockAchievementTrophy(8);
          return;
        }
      }
    }
  }
}

// File Line: 1611
// RVA: 0x4AB900
UFG::StoreFrontTracker *__fastcall UFG::StoreFrontTracker::Instance()
{
  if ( !(_S8_13 & 1) )
  {
    _S8_13 |= 1u;
    UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
    UFG::StoreFront::StoreFront(&stru_142408290, 0, 0, 0i64, 0i64);
    dword_1424083B8 = 0;
    UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
    atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
  }
  UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
  return &sStoreFrontTracker;
}

// File Line: 1621
// RVA: 0x4AA870
void __fastcall UFG::StoreFrontTracker::Init(UFG::StoreFrontTracker *this)
{
  unsigned int v1; // eax
  unsigned int v2; // ecx
  _DWORD *v3; // rdx

  v1 = UFG::gNullQSymbol.mUID;
  v2 = 0;
  v3 = 0i64;
  do
  {
    if ( v2 != -1 )
    {
      v3[1351621648] = v1;
      v3[1351622268] = v1;
      v3[1351619876] = 0;
    }
    ++v2;
    ++v3;
  }
  while ( v2 < 0x10 );
}

// File Line: 1632
// RVA: 0x4AF140
void __fastcall UFG::StoreFrontTracker::LoadStoreData(UFG::StoreFrontTracker *this, UFG::StoreFront::InventoryType inventoryType)
{
  UFG::StoreFrontTracker *v2; // rbx
  __int32 v3; // edx
  int v4; // edx
  const char *v5; // rdx
  char *v6; // rcx
  UFG::qSymbol *v7; // rax
  char v8; // [rsp+38h] [rbp+10h]
  char v9; // [rsp+40h] [rbp+18h]
  UFG::qSymbol result; // [rsp+48h] [rbp+20h]

  v2 = this;
  v3 = inventoryType - 0x3D;
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      if ( v4 != 1 )
        return;
      v5 = "Boat";
      v6 = &v8;
    }
    else
    {
      v5 = "Vehicle";
      v6 = &v9;
    }
  }
  else
  {
    v5 = "Clothing";
    v6 = (char *)&result;
  }
  v7 = UFG::qSymbol::create_from_string((UFG::qSymbol *)v6, v5);
  UFG::StoreFrontTracker::LoadStoreData(v2, v7);
}

// File Line: 1652
// RVA: 0x4AEFF0
void __fastcall UFG::StoreFrontTracker::LoadStoreData(UFG::StoreFrontTracker *this, UFG::qSymbol *inventoryType)
{
  UFG::qSymbol *v2; // rbx
  UFG::StoreFrontTracker *v3; // rdi
  unsigned int v4; // eax
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *v10; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  UFG::qSymbol v12; // [rsp+48h] [rbp+10h]
  UFG::qSymbol v13; // [rsp+50h] [rbp+18h]

  v2 = inventoryType;
  v3 = this;
  UFG::PropertySetHandle::Null(&this->mProperties);
  v3->mInventoryType = 0;
  UFG::StoreFront::SetData(&v3->mCurrentStore, 0, 0, 0i64, 0i64);
  UFG::PropertySetHandle::Null(&v3->mProperties);
  v4 = v2->mUID;
  if ( v2->mUID == 0x9773EC16 )
  {
    v9 = UFG::qSymbol::create_from_string(&v13, "default-unlockables-merchantdatabase-clothing");
    v10 = UFG::PropertySetManager::GetPropertySet(v9);
    UFG::PropertySetHandle::SetPropSet(&v3->mProperties, v10);
    UFG::PropertySetHandle::Bind(&v3->mProperties);
    UFG::qPropertySet::Get<UFG::qPropertyList>(
      v3->mProperties.mpPropSet,
      (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
      DEPTH_RECURSE);
    v3->mInventoryType = InventoryType_Clothing;
  }
  else if ( v4 == 0x9B06086B )
  {
    v7 = UFG::qSymbol::create_from_string(&v12, "default-unlockables-merchantdatabase-vehicles");
    v8 = UFG::PropertySetManager::GetPropertySet(v7);
    UFG::PropertySetHandle::SetPropSet(&v3->mProperties, v8);
    UFG::PropertySetHandle::Bind(&v3->mProperties);
    UFG::qPropertySet::Get<UFG::qPropertyList>(
      v3->mProperties.mpPropSet,
      (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
      DEPTH_RECURSE);
    v3->mInventoryType = InventoryType_Vehicle;
  }
  else if ( v4 == 0xACB107F7 )
  {
    v5 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-boats");
    v6 = UFG::PropertySetManager::GetPropertySet(v5);
    UFG::PropertySetHandle::SetPropSet(&v3->mProperties, v6);
    v3->mInventoryType = InventoryType_Boat;
  }
}

// File Line: 1681
// RVA: 0x4C3EE0
void __fastcall UFG::StoreFrontTracker::UnloadStoreData(UFG::StoreFrontTracker *this)
{
  UFG::StoreFrontTracker *v1; // rbx

  v1 = this;
  UFG::PropertySetHandle::Null(&this->mProperties);
  v1->mInventoryType = 0;
  UFG::StoreFront::SetData(&v1->mCurrentStore, 0, 0, 0i64, 0i64);
}

// File Line: 1689
// RVA: 0x4A0810
char __fastcall UFG::StoreFrontTracker::FindStore(UFG::StoreFrontTracker *this, UFG::qPropertySet *pStoreParameters, UFG::qSymbol *storeName, UFG::StoreFront *pResult, UFG::StoreFront::StoreType eStoreType)
{
  UFG::StoreFront *v5; // rdi
  UFG::qSymbol *v6; // r15
  UFG::qPropertySet *v7; // r12
  UFG::StoreFrontTracker *v8; // r13
  UFG::qPropertyList *v9; // rax
  char *v10; // r14
  UFG::qPropertyList *v11; // rbp
  unsigned int v12; // esi
  unsigned int v13; // ebx
  char result; // al
  UFG::StoreFront::InventoryType v15; // er13
  unsigned int v16; // ebx
  char *v17; // r12
  UFG::qSymbol *v18; // rax
  char *v19; // rax
  const char *v20; // rsi
  UFG::qPropertySet *v21; // [rsp+70h] [rbp+8h]
  UFG::qPropertySet *set; // [rsp+78h] [rbp+10h]

  set = pStoreParameters;
  v5 = pResult;
  v6 = storeName;
  v7 = pStoreParameters;
  v8 = this;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v21 = v8->mProperties.mpPropSet;
  v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v8->mProperties.mpPropSet,
         (UFG::qSymbol *)&StoreFrontSymbol_Stores.mUID,
         DEPTH_RECURSE);
  v10 = 0i64;
  v11 = v9;
  if ( v9 && (v12 = v9->mNumElements, v13 = 0, v12) )
  {
    while ( v6->mUID != UFG::qPropertyList::Get<UFG::qSymbol>(v11, v13)->mUID )
    {
      if ( ++v13 >= v12 )
        goto LABEL_5;
    }
    v15 = v8->mInventoryType;
    v5->mpStoreParameters = v7;
    v16 = UFG::gNullQSymbol.mUID;
    v17 = 0i64;
    if ( !((eStoreType - 1) & 0xFFFFFFFD) )
    {
      v16 = PropertyUtils::Get<UFG::qSymbol>(set, (UFG::qSymbol *)&qSymbol_StoreId.mUID, DEPTH_RECURSE)->mUID;
      v10 = PropertyUtils::Get<char const *>(
              v5->mpStoreParameters,
              (UFG::qSymbol *)&qSymbol_StoreTitle.mUID,
              DEPTH_RECURSE);
      v17 = PropertyUtils::Get<char const *>(
              v5->mpStoreParameters,
              (UFG::qSymbol *)&qSymbol_StoreDesc.mUID,
              DEPTH_RECURSE);
    }
    UFG::qSymbol::set_null(&v5->mItemTypeFilter);
    UFG::qString::Set(&v5->mItemTierFilter, &customWorldMapCaption);
    if ( v5->mpStoreParameters )
    {
      v18 = PropertyUtils::Get<UFG::qSymbol>(
              v5->mpStoreParameters,
              (UFG::qSymbol *)&qSymbol_StoreItemFilter.mUID,
              DEPTH_RECURSE);
      if ( v18 )
        v5->mItemTypeFilter = (UFG::qSymbol)v18->mUID;
      v19 = PropertyUtils::Get<char const *>(
              v5->mpStoreParameters,
              (UFG::qSymbol *)&qSymbol_StoreTierFilter.mUID,
              DEPTH_RECURSE);
      v20 = v19;
      if ( v19 && (signed int)UFG::qStringLength(v19) > 0 )
        UFG::qString::Set(&v5->mItemTierFilter, v20);
    }
    v5->mStoreType = eStoreType;
    v5->mInventoryType = v15;
    v5->mpPropertySet = v21;
    UFG::qString::Set(&v5->mStoreTitle, v10);
    UFG::qString::Set(&v5->mStoreDesc, v17);
    v5->mStoreName.mUID = v16;
    if ( eStoreType )
      UFG::StoreFront::BuildCategories(v5);
    result = 1;
  }
  else
  {
LABEL_5:
    UFG::StoreFront::SetData(v5, 0, 0, 0i64, 0i64);
    result = 0;
  }
  return result;
}

// File Line: 1710
// RVA: 0x4BBE70
void __fastcall UFG::StoreFrontTracker::SetCurrentStore(UFG::StoreFrontTracker *this, UFG::qPropertySet *pStoreParameters)
{
  UFG::qPropertySet *v2; // rdi
  UFG::StoreFrontTracker *v3; // rbx
  UFG::qSymbol *v4; // rax
  unsigned int v5; // ecx
  UFG::qSymbol *v6; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+18h]

  v2 = pStoreParameters;
  v3 = this;
  v4 = UFG::qSymbol::create_from_string(&result, "StoreType");
  v5 = PropertyUtils::Get<UFG::qSymbol>(v2, v4, DEPTH_RECURSE)->mUID;
  if ( v5 == StoreFrontSymbol_Storage.mUID )
  {
    UFG::StoreFront::SetData(&v3->mCurrentStore, StoreType_Storage, v3->mInventoryType, v2, 0i64);
  }
  else if ( v5 == StoreFrontSymbol_Race.mUID )
  {
    UFG::StoreFront::SetData(&v3->mCurrentStore, StoreType_Race, v3->mInventoryType, v2, 0i64);
  }
  else
  {
    v6 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_StoreId.mUID, DEPTH_RECURSE);
    UFG::StoreFrontTracker::FindStore(v3, v2, v6, &v3->mCurrentStore, StoreType_Retail);
  }
}

// File Line: 1734
// RVA: 0x4BBF50
void __fastcall UFG::StoreFrontTracker::SetCurrentStore(UFG::StoreFrontTracker *this, UFG::StoreFront::InventoryType inventorytype, __int64 storeName, const char *pStoreTitle, const char *pStoreDesc)
{
  const char *v5; // rsi
  unsigned int *v6; // r14
  UFG::StoreFront::InventoryType v7; // edi
  UFG::StoreFrontTracker *v8; // rbx
  UFG::qPropertySet *v9; // rax

  v5 = pStoreTitle;
  v6 = (unsigned int *)storeName;
  v7 = inventorytype;
  v8 = this;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v9 = v8->mProperties.mpPropSet;
  v8->mCurrentStore.mStoreType = 1;
  v8->mCurrentStore.mpPropertySet = v9;
  v8->mCurrentStore.mInventoryType = v7;
  UFG::qString::Set(&v8->mCurrentStore.mStoreTitle, v5);
  UFG::qString::Set(&v8->mCurrentStore.mStoreDesc, pStoreDesc);
  v8->mCurrentStore.mStoreName.mUID = *v6;
  UFG::StoreFront::BuildCategories(&v8->mCurrentStore);
}

// File Line: 1758
// RVA: 0x4AEBD0
void __fastcall UFG::StoreFrontTracker::LoadMissionItem(UFG::StoreFrontTracker *this, UFG::qSymbol *itemName, bool isPermanent)
{
  bool v3; // r14
  UFG::qSymbol *v4; // rdi
  UFG::StoreFrontTracker *v5; // rbx
  UFG::StoreFront::InventoryType v6; // er15
  UFG::StoreFront::StoreType v7; // ebp
  UFG::StoreFront::InventoryType v8; // er12
  UFG::qPropertySet *v9; // r13
  UFG::qSymbol *v10; // rax
  UFG::qPropertySet *v11; // rax
  char *v12; // rax
  UFG::qPropertySet *pPropertySet; // [rsp+30h] [rbp-48h]
  UFG::PropertySetHandle handle; // [rsp+40h] [rbp-38h]
  UFG::qSymbol result; // [rsp+98h] [rbp+20h]

  v3 = isPermanent;
  v4 = itemName;
  v5 = this;
  if ( UFG::GetLocalPlayer() )
  {
    UFG::PropertySetHandle::PropertySetHandle(&handle, &v5->mProperties);
    v6 = v5->mInventoryType;
    v7 = v5->mCurrentStore.mStoreType;
    v8 = v5->mCurrentStore.mInventoryType;
    v9 = v5->mCurrentStore.mpStoreParameters;
    pPropertySet = v5->mCurrentStore.mpPropertySet;
    v10 = UFG::qSymbol::create_from_string(&result, "Clothing");
    UFG::StoreFrontTracker::LoadStoreData(v5, v10);
    v11 = UFG::StoreFrontTracker::FindItemSlow(v5, v4);
    if ( v11 )
    {
      UFG::StoreFront::EquipItem(v11, v3, 1, 1, 1, 0);
      UFG::StoreFront::CheckAchievement();
      UFG::PropertySetHandle::Null(&v5->mProperties);
      v5->mInventoryType = 0;
      UFG::StoreFront::SetData(&v5->mCurrentStore, 0, 0, 0i64, 0i64);
      if ( v7 )
      {
        UFG::PropertySetHandle::SetPropSet(&v5->mProperties, &handle);
        v5->mInventoryType = v6;
        UFG::StoreFront::SetData(&v5->mCurrentStore, v7, v8, v9, pPropertySet);
      }
    }
    else
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v4);
      UFG::qPrintf("Cannot find mission item %s.", v12);
    }
    UFG::PropertySetHandle::~PropertySetHandle(&handle);
  }
}

// File Line: 1811
// RVA: 0x492EF0
void __fastcall UFG::StoreFrontTracker::AddItemToInventory(UFG::StoreFrontTracker *this, UFG::qPropertySet *pItemPropertySet, UFG::StoreFront::InventoryType inventoryType, bool bApplyFace, bool bIsFree)
{
  __int64 v5; // rdi
  UFG::qPropertySet *v6; // rbp
  UFG::StoreFrontTracker *v7; // rsi
  UFG::GameStatTracker *v8; // rax
  char *v9; // rax
  const char *v10; // rbx
  UFG::qSymbol *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  unsigned int v13; // ecx
  UFG::GameStatTracker *v14; // rbx
  UFG::GameStatTracker *v15; // r8
  __int64 v16; // rax
  float v17; // xmm0_4
  UFG::SimObject *v18; // rcx
  UFG::qSymbol keyname; // [rsp+40h] [rbp+8h]

  v5 = inventoryType;
  v6 = pItemPropertySet;
  v7 = this;
  if ( this->mProperties.mName.mUID != -1 )
  {
    v8 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v8 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v8->mpSnapshots[0]->mpMapBools[v5], &v6->mName, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        keyname.mUID = v6->mName.mUID;
        UFG::GameStatAction::PostStat::AchieveMapBool((UFG::GameStat::MapBoolStat)v5, (UFG::qSymbol)&keyname);
      }
    }
    if ( (_DWORD)v5 == 62 )
    {
      v9 = PropertyUtils::Get<char const *>(v6, (UFG::qSymbol *)&UFG::StoreItemSymbol_Tier.mUID, DEPTH_RECURSE);
      v10 = v9;
      if ( v9 )
      {
        if ( (signed int)UFG::qStringLength(v9) > 0 )
        {
          v11 = UFG::qSymbol::create_from_string(&keyname, v10);
          v12 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v12 + 6216) & 1) )
          {
            UFG::PersistentData::MapBool::SetStatus(v12->mpSnapshots[0]->mpMapBools[65], v11, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              v13 = _S12_6;
              v14 = &sGameStatTracker;
              if ( !(_S12_6 & 1) )
              {
                _S12_6 |= 1u;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                v13 = _S12_6;
              }
              v15 = &sGameStatTracker;
              if ( UFG::GameStatTracker::mspInstance )
                v15 = UFG::GameStatTracker::mspInstance;
              UFG::GameStatTracker::mspInstance = v15;
              if ( !(v13 & 1) )
              {
                _S12_6 = v13 | 1;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                v15 = UFG::GameStatTracker::mspInstance;
              }
              if ( v15 )
                v14 = v15;
              UFG::GameStatTracker::mspInstance = v14;
              v16 = v14->mpSnapshots[0]->mpMapBools[65]->mKeepType;
            }
          }
        }
      }
    }
    if ( !bIsFree )
    {
      v17 = UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v6);
      if ( v7 == (UFG::StoreFrontTracker *)-16i64 )
        v18 = 0i64;
      else
        v18 = v7->mCurrentStore.mpStoreOwner;
      UFG::GameStatAction::Money::PurchaseItem(v18, (UFG::StoreFront::InventoryType)v5, (signed int)v17);
    }
  }
}

// File Line: 1844
// RVA: 0x4B6A50
void __fastcall UFG::StoreFrontTracker::ResetEquipment(UFG::StoreFrontTracker *this)
{
  UFG::StoreFrontTracker *v1; // rbx
  UFG::SimObjectCharacter *v2; // r14
  UFG::qSymbol *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // r13
  UFG::SimComponent *v8; // rax
  signed __int64 v9; // rbx
  UFG::qSymbol *v10; // r15
  signed __int64 v11; // r12
  unsigned int v12; // edx
  UFG::GameStatTracker *v13; // r8
  UFG::qSymbol *v14; // rdi
  UFG::GameStatTracker *v15; // rax
  __int64 v16; // rsi
  UFG::StoreFrontTracker *v17; // rax
  UFG::qPropertySet *v18; // rdi
  __int64 v19; // rsi
  int *v20; // rax
  int v21; // edi
  unsigned int v22; // eax
  UFG::qSymbol *v23; // rcx
  unsigned int v24; // eax
  UFG::GameSnapshot *v25; // rbx
  UFG::StoreFrontTracker *v26; // rax
  UFG::qPropertySet *v27; // rbx
  UFG::GameStatTracker *v28; // rax
  UFG::qSymbol *v29; // rax
  UFG::eClothingBuffEnum v30; // eax
  UFG::qSymbol entityComponentName; // [rsp+30h] [rbp-99h]
  UFG::qSymbol v32; // [rsp+34h] [rbp-95h]
  UFG::qSymbol v33; // [rsp+38h] [rbp-91h]
  UFG::qSymbol v34; // [rsp+3Ch] [rbp-8Dh]
  UFG::qSymbol v35; // [rsp+40h] [rbp-89h]
  UFG::qSymbol v36; // [rsp+44h] [rbp-85h]
  UFG::qSymbol v37; // [rsp+48h] [rbp-81h]
  UFG::qSymbol v38; // [rsp+4Ch] [rbp-7Dh]
  UFG::qSymbol v39; // [rsp+50h] [rbp-79h]
  int v40; // [rsp+58h] [rbp-71h]
  __int64 v41; // [rsp+5Ch] [rbp-6Dh]
  int v42; // [rsp+64h] [rbp-65h]
  int v43; // [rsp+68h] [rbp-61h]
  int v44; // [rsp+6Ch] [rbp-5Dh]
  int v45; // [rsp+70h] [rbp-59h]
  int v46; // [rsp+74h] [rbp-55h]
  int v47; // [rsp+78h] [rbp-51h]
  int v48; // [rsp+7Ch] [rbp-4Dh]
  int v49; // [rsp+80h] [rbp-49h]
  __int64 v50; // [rsp+88h] [rbp-41h]
  __int128 v51; // [rsp+90h] [rbp-39h]
  __int128 v52; // [rsp+A0h] [rbp-29h]
  __int128 v53; // [rsp+B0h] [rbp-19h]
  __int128 v54; // [rsp+C0h] [rbp-9h]
  __int128 v55; // [rsp+D0h] [rbp+7h]
  int v56; // [rsp+E0h] [rbp+17h]
  int v57; // [rsp+E4h] [rbp+1Bh]
  UFG::StoreFrontTracker *v58; // [rsp+130h] [rbp+67h]
  UFG::qSymbol result; // [rsp+138h] [rbp+6Fh]

  v58 = this;
  v50 = -2i64;
  v1 = this;
  v2 = UFG::GetLocalPlayer();
  if ( v2 )
  {
    v3 = UFG::qSymbol::create_from_string(&result, "Clothing");
    UFG::StoreFrontTracker::LoadStoreData(v1, v3);
    _mm_store_si128((__m128i *)&v51, _mm_load_si128((const __m128i *)&_xmm));
    _mm_store_si128((__m128i *)&v52, _mm_load_si128((const __m128i *)&_xmm));
    _mm_store_si128((__m128i *)&v53, _mm_load_si128((const __m128i *)&_xmm));
    _mm_store_si128((__m128i *)&v54, _mm_load_si128((const __m128i *)&_xmm));
    _mm_store_si128((__m128i *)&v55, _mm_load_si128((const __m128i *)&_xmm));
    v56 = 10;
    v57 = 21;
    v40 = 3;
    v41 = 4i64;
    v42 = 1;
    v43 = 2;
    v44 = 6;
    v45 = 7;
    v46 = 8;
    v47 = 9;
    v48 = 5;
    v49 = 10;
    UFG::qSymbol::create_from_string(&entityComponentName, "Hat");
    UFG::qSymbol::create_from_string(&v32, "Head");
    UFG::qSymbol::create_from_string(&v33, "Body");
    UFG::qSymbol::create_from_string(&v34, "Pants");
    UFG::qSymbol::create_from_string(&v35, "Shoes");
    UFG::qSymbol::create_from_string(&v36, "Glasses");
    UFG::qSymbol::create_from_string(&v37, "Neck");
    UFG::qSymbol::create_from_string(&v38, "LeftWrist");
    UFG::qSymbol::create_from_string(&v39, "RightWrist");
    UFG::MeshResourceLoader::Unload(&UFG::StoreMeshHelper::sMeshLoader);
    UFG::StoreMeshHelper::sSwapQueued = 0;
    if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
    {
      v4 = UFG::StoreMeshHelper::sSwapTarget.mPrev;
      v5 = UFG::StoreMeshHelper::sSwapTarget.mNext;
      UFG::StoreMeshHelper::sSwapTarget.mPrev->mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
      v5->mPrev = v4;
      UFG::StoreMeshHelper::sSwapTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
      UFG::StoreMeshHelper::sSwapTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
    }
    UFG::StoreMeshHelper::sSwapTarget.m_pPointer = 0i64;
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v2->m_Components.p[10].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = v2->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v6 >> 12) & 1 )
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v2->vfptr,
                 UFG::StreamedResourceComponent::_TypeUID);
        else
          v8 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v2->vfptr,
                 UFG::StreamedResourceComponent::_TypeUID);
        v7 = v8;
      }
    }
    else
    {
      v7 = v2->m_Components.p[10].m_pComponent;
    }
    v9 = 0i64;
    v10 = &entityComponentName;
    v11 = 11i64;
    do
    {
      v12 = _S12_6;
      if ( !(_S12_6 & 1) )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v12 = _S12_6;
      }
      v13 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v13 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v13;
      v14 = (UFG::qSymbol *)((char *)v13->mpSnapshots[0] + 4 * *((signed int *)&v51 + 2 * v9));
      if ( !(v12 & 1) )
      {
        _S12_6 = v12 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v13 = UFG::GameStatTracker::mspInstance;
      }
      v15 = &sGameStatTracker;
      if ( v13 )
        v15 = v13;
      UFG::GameStatTracker::mspInstance = v15;
      v16 = *((signed int *)&v51 + 2 * v9 + 1);
      if ( !(*((_BYTE *)v15 + 6216) & 1) )
        v15->mpSnapshots[0]->mIDs[v16].mValue = v14[120];
      v17 = UFG::StoreFrontTracker::Instance();
      v18 = UFG::StoreFrontTracker::FindItemSlow(v17, v14 + 120);
      UFG::StoreFront::ProcessClothingSetBonuses((UFG::GameStat::IDStat)v16);
      v19 = *(&v40 + v9);
      if ( v18 )
      {
        UFG::StoreMeshHelper::CommitResource((UFG::SimObject *)&v2->vfptr, v18);
        v20 = UFG::qPropertySet::Get<long>(v18, (UFG::qSymbol *)&UFG::StoreItemSymbol_FashionValue.mUID, DEPTH_RECURSE);
        if ( v20 )
          v21 = *v20;
        else
          v21 = 0;
        UFG::StoreFrontTracker::Instance()->mClothingFashionValue[v19] = v21;
      }
      else
      {
        if ( v9 < 9 )
        {
          UFG::TrueCrowdDataBase::Instance();
          v22 = UFG::TrueCrowdDefinition::GetEntityComponentIndex(
                  &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
                  HIDWORD(v7[4].m_SafePointerList.mNode.mNext[2].mPrev),
                  v10);
          if ( v22 != -1 )
          {
            v23 = (UFG::qSymbol *)(4i64 * v22);
            v24 = UFG::gNullQSymbol.mUID;
            v23[1351621648].mUID = UFG::gNullQSymbol.mUID;
            v23[1351622268].mUID = v24;
            v23[1351619876].mUID = 0;
          }
        }
        UFG::StoreFrontTracker::Instance()->mClothingFashionValue[v19] = 0;
      }
      ++v10;
      ++v9;
      --v11;
    }
    while ( v11 );
    v25 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
    v26 = UFG::StoreFrontTracker::Instance();
    v27 = UFG::StoreFrontTracker::FindItemSlow(v26, &v25->mIDs[21].mValue);
    if ( v27 )
    {
      v28 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v28, ClothingSetBuff, 0);
      v29 = PropertyUtils::Get<UFG::qSymbol>(v27, (UFG::qSymbol *)&SimSym_ClothingSetBuff.mUID, DEPTH_RECURSE);
      if ( v29 )
      {
        v30 = (unsigned int)UFG::StoreFront::LookupClothingBuff(v29);
        UFG::StoreFront::SetClothingSetBuff(v30);
      }
    }
    UFG::StoreMeshHelper::QueueSwapping((UFG::SimObject *)&v2->vfptr);
    UFG::PropertySetHandle::Null(&v58->mProperties);
    v58->mInventoryType = 0;
    UFG::StoreFront::SetData(&v58->mCurrentStore, 0, 0, 0i64, 0i64);
    `eh vector destructor iterator(&entityComponentName, 4ui64, 9, (void (__fastcall *)(void *))_);
  }
}

// File Line: 1945
// RVA: 0x4A04B0
UFG::qPropertySet *__fastcall UFG::StoreFrontTracker::FindClothingSetSlow(UFG::StoreFrontTracker *this, UFG::qSymbol *clothingSetName)
{
  UFG::qSymbol *v2; // r14
  UFG::StoreFrontTracker *v3; // rbx
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rsi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  char *v8; // rax
  char *v9; // rcx

  v2 = clothingSetName;
  v3 = this;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v3->mProperties.mpPropSet,
         (UFG::qSymbol *)&StoreFrontSymbol_ClothingSets.mUID,
         DEPTH_RECURSE);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = v4->mNumElements;
  v7 = 0;
  if ( !v6 )
    return 0i64;
  while ( 1 )
  {
    v8 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v7);
    if ( v8 && *(_QWORD *)v8 )
      v9 = &v8[*(_QWORD *)v8];
    else
      v9 = 0i64;
    if ( *((_DWORD *)v9 + 16) == v2->mUID )
      break;
    if ( ++v7 >= v6 )
      return 0i64;
  }
  return (UFG::qPropertySet *)v9;
}

// File Line: 1963
// RVA: 0x4A0690
UFG::qPropertySet *__fastcall UFG::StoreFrontTracker::FindItemSlow(UFG::StoreFrontTracker *this, UFG::qSymbol *itemName)
{
  UFG::qSymbol *v2; // r14
  UFG::StoreFrontTracker *v3; // rbx
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rsi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  char *v8; // rax
  char *v9; // rcx

  v2 = itemName;
  v3 = this;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v3->mProperties.mpPropSet,
         (UFG::qSymbol *)&StoreFrontSymbol_Items.mUID,
         DEPTH_RECURSE);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = v4->mNumElements;
  v7 = 0;
  if ( !v6 )
    return 0i64;
  while ( 1 )
  {
    v8 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v7);
    if ( v8 && *(_QWORD *)v8 )
      v9 = &v8[*(_QWORD *)v8];
    else
      v9 = 0i64;
    if ( *((_DWORD *)v9 + 0x10) == v2->mUID )
      break;
    if ( ++v7 >= v6 )
      return 0i64;
  }
  return (UFG::qPropertySet *)v9;
}

// File Line: 1982
// RVA: 0x4A4360
float __fastcall UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(UFG::qPropertySet *pItemPropertySet)
{
  float *v1; // rax
  float v2; // xmm6_4
  float v3; // xmm6_4

  v1 = PropertyUtils::Get<float>(pItemPropertySet, (UFG::qSymbol *)&UFG::StoreItemSymbol_Price.mUID, DEPTH_RECURSE);
  if ( !v1 )
    return 0.0;
  v2 = *v1;
  v3 = v2 - (float)((float)(UFG::StoreFrontTracker::GetDiscount() * v2) * 0.0099999998);
  if ( v3 < 0.0 )
    v3 = 0.0;
  return v3;
}

// File Line: 1993
// RVA: 0x4A4320
float __fastcall UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(float fCurrentPrice)
{
  float v1; // xmm6_4
  float result; // xmm0_4

  v1 = fCurrentPrice - (float)((float)(UFG::StoreFrontTracker::GetDiscount() * fCurrentPrice) * 0.0099999998);
  result = 0.0;
  if ( v1 >= 0.0 )
    result = v1;
  return result;
}

// File Line: 2008
// RVA: 0x4A43C0
float __fastcall UFG::StoreFrontTracker::GetItemPriceWithoutDiscount(UFG::qPropertySet *pItemPropertySet)
{
  float *v1; // rax
  float result; // xmm0_4

  v1 = PropertyUtils::Get<float>(pItemPropertySet, (UFG::qSymbol *)&UFG::StoreItemSymbol_Price.mUID, DEPTH_RECURSE);
  if ( v1 )
    result = *v1;
  else
    result = 0.0;
  return result;
}

// File Line: 2019
// RVA: 0x4A2390
float __fastcall UFG::StoreFrontTracker::GetDiscount()
{
  float v0; // xmm6_4
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // r8
  UFG::GameStatTracker *v4; // rdx

  v0 = 0.0;
  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
  }
  v3 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  if ( v3->mpSnapshots[0]->mInts[37].mValue == 7 )
  {
    v0 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[52].mValue;
    v1 = _S12_6;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  if ( !(v1 & 1) )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  v4 = &sGameStatTracker;
  if ( v3 )
    v4 = v3;
  UFG::GameStatTracker::mspInstance = v4;
  if ( v4->mpSnapshots[0]->mInts[37].mValue == 8 )
  {
    v0 = v0 + UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[53].mValue;
    v1 = _S12_6;
    v4 = UFG::GameStatTracker::mspInstance;
  }
  if ( !(v1 & 1) )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v4 = UFG::GameStatTracker::mspInstance;
  }
  if ( v4 )
    v2 = v4;
  UFG::GameStatTracker::mspInstance = v2;
  if ( v2->mpSnapshots[0]->mInts[37].mValue == 9 )
  {
    v0 = v0 + UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[54].mValue;
  }
  else if ( UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[37].mValue == 14 )
  {
    v0 = v0 - UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[60].mValue;
  }
  return UFG::StoreFrontTracker::GetDiscountForFaceLevel() + (float)(v0 * 100.0);
}

// File Line: 2046
// RVA: 0x4A25B0
float __fastcall UFG::StoreFrontTracker::GetDiscountForFaceLevel()
{
  UFG::GameStatTracker *v0; // rbx
  UFG::GameStatTracker *v1; // rcx
  signed int v2; // edi
  int v3; // ecx
  char *v4; // rax
  UFG::qPropertySet *v5; // rcx
  __m128i v6; // xmm0
  float result; // xmm0_4

  v0 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v1 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v1 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v1;
  v2 = UFG::GameStatTracker::GetFaceLevelFromExperience(v1, v1->mpSnapshots[0]->mInts[29].mValue);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v0 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v0;
  v3 = v0->m_iMaxFaceLevel;
  if ( v2 >= v3 - 1 )
    v2 = v3 - 1;
  if ( v2 < 0 || v2 >= v3 )
  {
    v6 = _mm_cvtsi32_si128(0xFFFFFFFF);
  }
  else
  {
    v4 = UFG::qPropertyList::GetValuePtr(v0->mpFaceLevelPropertyList, 0x1Au, v2);
    if ( v4 && *(_QWORD *)v4 )
      v5 = (UFG::qPropertySet *)&v4[*(_QWORD *)v4];
    else
      v5 = 0i64;
    v6 = _mm_cvtsi32_si128(*UFG::qPropertySet::Get<long>(
                              v5,
                              (UFG::qSymbol *)&GameStatsSymbol_PriceDiscount.mUID,
                              DEPTH_RECURSE));
  }
  LODWORD(result) = (unsigned __int128)_mm_cvtepi32_ps(v6);
  return result;
}

// File Line: 2059
// RVA: 0x4A1FA0
__int64 __fastcall UFG::StoreFrontTracker::GetClothingFashionValueTotal(UFG::StoreFrontTracker *this)
{
  UFG::StoreFrontTracker *v1; // rbx
  __int64 result; // rax

  v1 = this;
  if ( UFG::StoreFront::IsWeiWearingAnPrefinedOutfit() )
    result = (unsigned int)v1->mClothingFashionValue[10];
  else
    result = (unsigned int)(v1->mClothingFashionValue[0]
                          + v1->mClothingFashionValue[1]
                          + v1->mClothingFashionValue[2]
                          + v1->mClothingFashionValue[3]
                          + v1->mClothingFashionValue[4]
                          + v1->mClothingFashionValue[5]
                          + v1->mClothingFashionValue[6]
                          + v1->mClothingFashionValue[7]
                          + v1->mClothingFashionValue[8]
                          + v1->mClothingFashionValue[9]);
  return result;
}

// File Line: 2075
// RVA: 0x151B560
__int64 dynamic_initializer_for__UFG::StoreMeshHelper::sSwapTarget__()
{
  UFG::StoreMeshHelper::sSwapTarget.m_pPointer = 0i64;
  return atexit(dynamic_atexit_destructor_for__UFG::StoreMeshHelper::sSwapTarget__);
}

// File Line: 2076
// RVA: 0x151B500
__int64 dynamic_initializer_for__UFG::StoreMeshHelper::sMeshLoader__()
{
  UFG::MeshResourceLoader::MeshResourceLoader(&UFG::StoreMeshHelper::sMeshLoader);
  return atexit(dynamic_atexit_destructor_for__UFG::StoreMeshHelper::sMeshLoader__);
}

// File Line: 2077
// RVA: 0x151B520
__int64 dynamic_initializer_for__UFG::StoreMeshHelper::sModelPaths__()
{
  `eh vector constructor iterator(
    UFG::StoreMeshHelper::sModelPaths,
    4ui64,
    16,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit(dynamic_atexit_destructor_for__UFG::StoreMeshHelper::sModelPaths__);
}

// File Line: 2078
// RVA: 0x151B590
__int64 dynamic_initializer_for__UFG::StoreMeshHelper::sTextureSetPaths__()
{
  `eh vector constructor iterator(
    UFG::StoreMeshHelper::sTextureSetPaths,
    4ui64,
    16,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit(dynamic_atexit_destructor_for__UFG::StoreMeshHelper::sTextureSetPaths__);
}

// File Line: 2090
// RVA: 0x4C23F0
_BOOL8 __fastcall UFG::StoreMeshHelper::SwapInProgress()
{
  return UFG::StoreMeshHelper::sSwapQueued;
}

// File Line: 2102
// RVA: 0x499570
void __fastcall UFG::StoreMeshHelper::CommitResource(UFG::SimObject *object, UFG::qPropertySet *pSet)
{
  UFG::qPropertySet *v2; // rsi
  int v3; // edi
  UFG::SimComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qSymbol *v7; // rbp
  unsigned int v8; // eax
  __int64 v9; // rbx
  int *v10; // rax
  signed __int64 v11; // rdx
  UFG::qSymbol defaultValue; // [rsp+60h] [rbp+8h]
  UFG::qSymbol *result; // [rsp+70h] [rbp+18h]
  UFG::qSymbol *v14; // [rsp+78h] [rbp+20h]

  v2 = pSet;
  v3 = 0;
  if ( object )
  {
    v5 = object->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = object->m_Components.p[10].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = object->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)object,
                 UFG::StreamedResourceComponent::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType(object, UFG::StreamedResourceComponent::_TypeUID);
        v4 = v6;
      }
    }
    else
    {
      v4 = object->m_Components.p[10].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  result = &defaultValue;
  defaultValue.mUID = UFG::gNullQSymbol.mUID;
  PropertyUtils::GetWithDefault<UFG::qSymbol>(
    (UFG::qSymbol *)&result,
    v2,
    (UFG::qSymbol *)&qSymbol_Model.mUID,
    (__int64)&defaultValue,
    DEPTH_RECURSE);
  v14 = &defaultValue;
  defaultValue.mUID = UFG::gNullQSymbol.mUID;
  PropertyUtils::GetWithDefault<UFG::qSymbol>(
    (UFG::qSymbol *)&v14,
    v2,
    (UFG::qSymbol *)&qSymbol_TextureSet.mUID,
    (__int64)&defaultValue,
    DEPTH_RECURSE);
  v7 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_ComponentType.mUID, DEPTH_RECURSE);
  if ( v7 )
  {
    UFG::TrueCrowdDataBase::Instance();
    v8 = UFG::TrueCrowdDefinition::GetEntityComponentIndex(
           &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
           HIDWORD(v4[4].m_SafePointerList.mNode.mNext[2].mPrev),
           v7);
    v9 = v8;
    if ( v8 != -1 )
    {
      v10 = PropertyUtils::Get<long>(v2, (UFG::qSymbol *)&qSymbol_ColorTintIndex.mUID, DEPTH_RECURSE);
      v11 = 4 * v9;
      *(_DWORD *)(v11 + 5406486592i64) = (_DWORD)result;
      *(_DWORD *)(v11 + 5406489072i64) = (_DWORD)v14;
      if ( v10 )
        v3 = *v10;
      UFG::StoreMeshHelper::sColourTintIndices[v9] = v3;
    }
  }
}

// File Line: 2141
// RVA: 0x4B3AC0
void __fastcall UFG::StoreMeshHelper::QueueSwapping(UFG::SimObject *object)
{
  UFG::SimObjectGame *v1; // rbx
  UFG::StreamedResourceComponent *v2; // rdi
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SceneObjectProperties *v8; // rcx
  UFG::qPropertySet *v9; // rdx
  unsigned int v10; // er15
  unsigned int v11; // er14
  unsigned int v12; // edi
  UFG::qSymbol *v13; // rsi
  UFG::qSymbol *v14; // rbp
  UFG::TrueCrowdDataBase *v15; // rax
  UFG::TrueCrowdModel *v16; // rax
  UFG::TrueCrowdModel *v17; // rbx
  __int64 v18; // r8
  unsigned int v19; // er10
  __int64 v20; // r9
  signed __int64 v21; // rcx
  _QWORD *v22; // rdx
  UFG::TrueCrowdResource *v23; // rdx
  __int64 *v24; // rax
  __int64 v25; // rcx
  UFG::qSymbol priority; // [rsp+60h] [rbp+8h]
  UFG::qSymbol *v27; // [rsp+68h] [rbp+10h]

  v1 = (UFG::SimObjectGame *)object;
  if ( object )
  {
    v3 = object->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v2 = (UFG::StreamedResourceComponent *)v1->m_Components.p[10].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v2 = (UFG::StreamedResourceComponent *)v1->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v3 >> 12) & 1 )
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::StreamedResourceComponent::_TypeUID);
        else
          v4 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v1->vfptr,
                 UFG::StreamedResourceComponent::_TypeUID);
        v2 = (UFG::StreamedResourceComponent *)v4;
      }
    }
    else
    {
      v2 = (UFG::StreamedResourceComponent *)v1->m_Components.p[10].m_pComponent;
    }
  }
  else
  {
    v2 = 0i64;
  }
  UFG::StoreMeshHelper::sSwapQueued = 1;
  if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
  {
    v5 = UFG::StoreMeshHelper::sSwapTarget.mPrev;
    v6 = UFG::StoreMeshHelper::sSwapTarget.mNext;
    UFG::StoreMeshHelper::sSwapTarget.mPrev->mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    v6->mPrev = v5;
    UFG::StoreMeshHelper::sSwapTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
    UFG::StoreMeshHelper::sSwapTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
  }
  UFG::StoreMeshHelper::sSwapTarget.m_pPointer = (UFG::SimObject *)&v1->vfptr;
  if ( v1 )
  {
    v7 = v1->m_SafePointerList.mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
    UFG::StoreMeshHelper::sSwapTarget.mPrev = v7;
    UFG::StoreMeshHelper::sSwapTarget.mNext = &v1->m_SafePointerList.mNode;
    v1->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
  }
  UFG::MeshResourceLoader::Unload(&UFG::StoreMeshHelper::sMeshLoader);
  v27 = &priority;
  priority.mUID = UFG::StreamedResourceComponent::GetSpawnPriority(v2, 0i64)->mUID;
  v8 = UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_pSceneObj;
  v9 = v8->mpWritableProperties;
  if ( !v9 )
    v9 = v8->mpConstProperties;
  UFG::MeshResourceLoader::Init(
    &UFG::StoreMeshHelper::sMeshLoader,
    v9,
    (__int64)&priority,
    v2->mMeshLoader.mHighDefinition);
  v10 = v2->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex;
  UFG::TrueCrowdDataBase::Instance();
  v11 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v10].mComponentCount;
  v12 = 0;
  if ( v11 )
  {
    v13 = UFG::StoreMeshHelper::sTextureSetPaths;
    v14 = UFG::StoreMeshHelper::sModelPaths;
    do
    {
      v15 = UFG::TrueCrowdDataBase::Instance();
      v16 = UFG::TrueCrowdDataBase::QueryModelFromPath(v15, v10, v12, v14);
      v17 = v16;
      if ( v16 )
      {
        UFG::MeshResourceLoader::AddResource(
          &UFG::StoreMeshHelper::sMeshLoader,
          (UFG::TrueCrowdResource *)&v16->mName,
          0);
        v18 = 0i64;
        v19 = v17->mNumTextureSets;
        if ( v17->mNumTextureSets )
        {
          v20 = v17->mTextureSets.mOffset;
          while ( 1 )
          {
            v21 = (signed __int64)(v20 ? (UFG::qOffset64<UFG::qOffset64<UFG::TrueCrowdTextureSet *> *> *)((char *)&v17->mTextureSets + v20) : 0i64);
            v22 = (_QWORD *)(v21 + 8 * v18);
            v23 = (UFG::TrueCrowdResource *)(*v22 ? (_QWORD *)((char *)v22 + *v22) : 0i64);
            if ( v23->mPathSymbol.mUID == v13->mUID )
              break;
            v18 = (unsigned int)(v18 + 1);
            if ( (unsigned int)v18 >= v19 )
              goto LABEL_32;
          }
        }
        else
        {
LABEL_32:
          if ( !(_WORD)v19 )
            goto LABEL_38;
          v24 = (__int64 *)v17->mTextureSets.mOffset;
          if ( v24 )
            v24 = (__int64 *)((char *)v24 + (_QWORD)v17 + 72);
          v25 = *v24;
          if ( !*v24 )
            goto LABEL_38;
          v23 = (UFG::TrueCrowdResource *)((char *)v24 + v25);
          if ( !(__int64 *)((char *)v24 + v25) )
            goto LABEL_38;
        }
        UFG::MeshResourceLoader::AddResource(&UFG::StoreMeshHelper::sMeshLoader, v23, 1);
      }
LABEL_38:
      ++v12;
      ++v14;
      ++v13;
    }
    while ( v12 < v11 );
  }
}

// File Line: 2190
// RVA: 0x4C4A70
void UFG::StoreMeshHelper::Update(void)
{
  if ( UFG::StoreMeshHelper::sSwapQueued )
  {
    if ( UFG::MeshResourceLoader::IsLoaded(&UFG::StoreMeshHelper::sMeshLoader) )
      UFG::StoreMeshHelper::CompleteSwap();
  }
}

// File Line: 2198
// RVA: 0x4999C0
void UFG::StoreMeshHelper::CompleteSwap(void)
{
  unsigned __int16 v0; // dx
  UFG::StreamedResourceComponent *v1; // rbx
  UFG::SimComponent *v2; // rax
  unsigned int v3; // esi
  unsigned int v4; // ebp
  __int64 v5; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx

  if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
  {
    v0 = UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_Flags;
    if ( (v0 >> 14) & 1 )
    {
      v1 = (UFG::StreamedResourceComponent *)UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_Components.p[10].m_pComponent;
    }
    else if ( (v0 & 0x8000u) == 0 )
    {
      if ( (v0 >> 13) & 1 )
      {
        v1 = (UFG::StreamedResourceComponent *)UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (v0 >> 12) & 1 )
          v2 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)UFG::StoreMeshHelper::sSwapTarget.m_pPointer,
                 UFG::StreamedResourceComponent::_TypeUID);
        else
          v2 = UFG::SimObject::GetComponentOfType(
                 UFG::StoreMeshHelper::sSwapTarget.m_pPointer,
                 UFG::StreamedResourceComponent::_TypeUID);
        v1 = (UFG::StreamedResourceComponent *)v2;
      }
    }
    else
    {
      v1 = (UFG::StreamedResourceComponent *)UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_Components.p[10].m_pComponent;
    }
    UFG::MeshResourceLoader::Unload(&v1->mMeshLoader);
    UFG::TrueCrowdDataBase::Instance();
    v3 = 0;
    v4 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v1->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex].mComponentCount;
    if ( v4 )
    {
      v5 = 0i64;
      do
      {
        UFG::StreamedResourceComponent::SwapResource(
          v1,
          v3++,
          &UFG::StoreMeshHelper::sModelPaths[v5],
          &UFG::StoreMeshHelper::sTextureSetPaths[v5],
          &UFG::StoreMeshHelper::sColourTintIndices[v5]);
        ++v5;
      }
      while ( v3 < v4 );
    }
    UFG::MeshResourceLoader::QueueLoad(&v1->mMeshLoader);
  }
  UFG::MeshResourceLoader::Unload(&UFG::StoreMeshHelper::sMeshLoader);
  UFG::StoreMeshHelper::sSwapQueued = 0;
  if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
  {
    v6 = UFG::StoreMeshHelper::sSwapTarget.mNext;
    v7 = UFG::StoreMeshHelper::sSwapTarget.mPrev;
    UFG::StoreMeshHelper::sSwapTarget.mPrev->mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    v6->mPrev = v7;
    UFG::StoreMeshHelper::sSwapTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
    UFG::StoreMeshHelper::sSwapTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&UFG::StoreMeshHelper::sSwapTarget;
  }
  UFG::StoreMeshHelper::sSwapTarget.m_pPointer = 0i64;
}

