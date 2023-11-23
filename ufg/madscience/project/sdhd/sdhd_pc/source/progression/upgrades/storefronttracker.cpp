// File Line: 38
// RVA: 0x152E1F0
__int64 UFG::_dynamic_initializer_for__qSymbol_ActBaseName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ActBaseName", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_ActBaseName, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_ActBaseName__);
}

// File Line: 42
// RVA: 0x151D110
__int64 UFG::_dynamic_initializer_for__StoreItemSymbol_Price__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Price", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::StoreItemSymbol_Price, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__StoreItemSymbol_Price__);
}

// File Line: 46
// RVA: 0x151CDD0
__int64 UFG::_dynamic_initializer_for__StoreFrontSymbol_ClothingSets__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ClothingSets", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&StoreFrontSymbol_ClothingSets, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__StoreFrontSymbol_ClothingSets__);
}

// File Line: 50
// RVA: 0x151C710
__int64 UFG::_dynamic_initializer_for__ItemCategorySymbol_RIGHTWRIST__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RIGHTWRIST", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::ItemCategorySymbol_RIGHTWRIST, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__ItemCategorySymbol_RIGHTWRIST__);
}

// File Line: 61
// RVA: 0x151C250
__int64 UFG::_dynamic_initializer_for__ItemBrandSymbol_BeautifulCorpse__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BeautifulCorpse", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::ItemBrandSymbol_BeautifulCorpse, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__ItemBrandSymbol_BeautifulCorpse__);
}

// File Line: 72
// RVA: 0x151B5D0
__int64 UFG::_dynamic_initializer_for__ClothingSetSymbol_ActiveDesc__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ActiveDesc", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::ClothingSetSymbol_ActiveDesc, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__ClothingSetSymbol_ActiveDesc__);
}

// File Line: 89
// RVA: 0x48DE10
void __fastcall UFG::StoreFront::StoreFront(
        UFG::StoreFront *this,
        UFG::StoreFront::StoreType type,
        UFG::StoreFront::InventoryType inventoryType,
        UFG::qPropertySet *pParameters,
        UFG::qPropertySet *pPropertySet)
{
  this->mpStoreParameters = pParameters;
  this->mpPropertySet = pPropertySet;
  this->mpStoreOwner = 0i64;
  this->mStoreType = type;
  this->mStoreName.mUID = -1;
  this->mInventoryType = InventoryType_None;
  this->mCategoryFilter = Num_ItemCategories;
  UFG::qString::qString(&this->mCategoryHeading);
  UFG::qString::qString(&this->mStoreTitle);
  UFG::qString::qString(&this->mStoreDesc);
  this->mItemTypeFilter.mUID = -1;
  UFG::qString::qString(&this->mItemTierFilter);
  this->m_Items.mNode.mPrev = &this->m_Items.mNode;
  this->m_Items.mNode.mNext = &this->m_Items.mNode;
  *(_QWORD *)this->mCategoryCount = 0i64;
  *(_QWORD *)&this->mCategoryCount[2] = 0i64;
  *(_QWORD *)&this->mCategoryCount[4] = 0i64;
  *(_QWORD *)&this->mCategoryCount[6] = 0i64;
  *(_QWORD *)&this->mCategoryCount[8] = 0i64;
  *(_QWORD *)&this->mCategoryCount[10] = 0i64;
  *(_QWORD *)&this->mCategoryCount[12] = 0i64;
  this->mCategoryCount[14] = 0;
}

// File Line: 97
// RVA: 0x4915D0
void __fastcall UFG::StoreFront::~StoreFront(UFG::StoreFront *this)
{
  UFG::qList<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem,1,0> *p_m_Items; // rbx
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *mPrev; // rcx
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *mNext; // rax

  p_m_Items = &this->m_Items;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_Items);
  mPrev = p_m_Items->mNode.mPrev;
  mNext = p_m_Items->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_Items->mNode.mPrev = &p_m_Items->mNode;
  p_m_Items->mNode.mNext = &p_m_Items->mNode;
  UFG::qString::~qString(&this->mItemTierFilter);
  UFG::qString::~qString(&this->mStoreDesc);
  UFG::qString::~qString(&this->mStoreTitle);
  UFG::qString::~qString(&this->mCategoryHeading);
}

// File Line: 112
// RVA: 0x4B0C00
signed __int64 __fastcall UFG::StoreFront::MapItemCategory(UFG::qSymbol *itemCategory)
{
  unsigned int mUID; // edx
  signed __int64 result; // rax

  mUID = itemCategory->mUID;
  result = Num_ItemCategories;
  if ( itemCategory->mUID == UFG::ItemCategorySymbol_BODY.mUID )
    return ItemCategory_BODY;
  if ( mUID == UFG::ItemCategorySymbol_LOWER_BODY.mUID )
    return ItemCategory_LOWER_BODY;
  if ( mUID == UFG::ItemCategorySymbol_FOOTWEAR.mUID )
    return ItemCategory_FOOTWEAR;
  if ( mUID == UFG::ItemCategorySymbol_HEADGEAR.mUID )
    return ItemCategory_HEADGEAR;
  if ( mUID == UFG::ItemCategorySymbol_HEAD.mUID )
    return ItemCategory_HEAD;
  if ( mUID == UFG::ItemCategorySymbol_ACCESSORIES.mUID )
    return ItemCategory_ACCESSORIES;
  if ( mUID == UFG::ItemCategorySymbol_GLASSES.mUID )
    return ItemCategory_GLASSES;
  if ( mUID == UFG::ItemCategorySymbol_NECK.mUID )
    return ItemCategory_NECK;
  if ( mUID == UFG::ItemCategorySymbol_LEFTWRIST.mUID )
    return ItemCategory_LEFTWRIST;
  if ( mUID == UFG::ItemCategorySymbol_RIGHTWRIST.mUID )
    return ItemCategory_RIGHTWRIST;
  if ( mUID == UFG::ItemCategorySymbol_OUTFIT.mUID )
    return ItemCategory_OUTFIT;
  if ( mUID == UFG::ItemCategorySymbol_CUSTOM_OUTFIT.mUID )
    return ItemCategory_CUSTOM_OUTFIT;
  if ( mUID == UFG::ItemCategorySymbol_VEHICLE.mUID )
    return ItemCategory_VEHICLE;
  if ( mUID == UFG::ItemCategorySymbol_BOAT.mUID )
    return ItemCategory_BOAT;
  return result;
}

// File Line: 125
// RVA: 0x4930D0
void __fastcall UFG::StoreFront::AddItemToStore(
        UFG::StoreFront *this,
        UFG::qPropertySet *pItemPropertySet,
        __int16 iIndex,
        bool bRetail)
{
  UFG::qSymbol *v7; // rax
  __int64 v8; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rdx
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *mPrev; // rax

  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pItemPropertySet,
         (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Category,
         DEPTH_RECURSE);
  v8 = (int)UFG::StoreFront::MapItemCategory(v7);
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
  BYTE2(v10[2].mNext) = bRetail;
  LOWORD(v10[2].mNext) = iIndex;
  WORD2(v10[2].mNext) = v8;
  mPrev = this->m_Items.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)v10;
  v10->mNext = (UFG::allocator::free_link *)mPrev;
  v10[1].mNext = (UFG::allocator::free_link *)&this->m_Items;
  this->m_Items.mNode.mPrev = (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)v10;
  ++this->mCategoryCount[v8];
}

// File Line: 142
// RVA: 0x4959F0
void __fastcall UFG::StoreFront::BuildCategories(UFG::StoreFront *this)
{
  UFG::qList<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem,1,0> *p_m_Items; // r8
  UFG::StoreFront *mNext; // rdx
  UFG::qPropertySet *mpStoreParameters; // rcx
  UFG::qPropertySet *mpPropertySet; // rax
  int v6; // edi
  int NumStorageItems; // r14d
  UFG::qPropertySet *StorageItem; // rax
  UFG::qPropertySet *v9; // rsi
  UFG::qSymbol *v10; // rax
  unsigned int mUID; // ecx
  unsigned int v12; // eax
  char *v13; // rax
  const char *v14; // rbp
  UFG::qPropertySet *v15; // rcx
  UFG::qPropertyList *v16; // rax
  signed int mNumElements; // r12d
  signed int i; // r15d
  UFG::qPropertyList *v19; // rax
  char *ValuePtr; // rax
  __int64 v21; // rcx
  UFG::qPropertySet *v22; // r14
  unsigned int v23; // ecx
  char *v24; // rax
  const char *v25; // rdi
  UFG::qPropertyList *v26; // rax
  UFG::qPropertyList *v27; // rbp
  unsigned int v28; // esi
  unsigned int v29; // edi
  UFG::qArray<unsigned long,0> result; // [rsp+60h] [rbp+8h] BYREF

  this->mCategoryFilter = Num_ItemCategories;
  p_m_Items = &this->m_Items;
  *(_QWORD *)this->mCategoryCount = 0i64;
  *(_QWORD *)&this->mCategoryCount[2] = 0i64;
  *(_QWORD *)&this->mCategoryCount[4] = 0i64;
  *(_QWORD *)&this->mCategoryCount[6] = 0i64;
  *(_QWORD *)&this->mCategoryCount[8] = 0i64;
  *(_QWORD *)&this->mCategoryCount[10] = 0i64;
  *(_QWORD *)&this->mCategoryCount[12] = 0i64;
  this->mCategoryCount[14] = 0;
  mNext = (UFG::StoreFront *)this->m_Items.mNode.mNext;
  if ( mNext != (UFG::StoreFront *)&this->m_Items )
  {
    do
    {
      mpStoreParameters = mNext->mpStoreParameters;
      mpPropertySet = mNext->mpPropertySet;
      mpStoreParameters->mOwner.mOffset = (__int64)mpPropertySet;
      *(_QWORD *)&mpPropertySet->mFlags = mpStoreParameters;
      mNext->mpStoreParameters = (UFG::qPropertySet *)mNext;
      mNext->mpPropertySet = (UFG::qPropertySet *)mNext;
      mNext = (UFG::StoreFront *)p_m_Items->mNode.mNext;
    }
    while ( mNext != (UFG::StoreFront *)p_m_Items );
  }
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "Type");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&result.p, "Tier");
  if ( (unsigned int)(this->mStoreType - 2) <= 1 )
  {
    v6 = 0;
    NumStorageItems = UFG::StoreFront::GetNumStorageItems(this);
    if ( NumStorageItems > 0 )
    {
      do
      {
        StorageItem = UFG::StoreFront::GetStorageItem(this, v6);
        v9 = StorageItem;
        if ( StorageItem )
        {
          v10 = PropertyUtils::Get<UFG::qSymbol>(StorageItem, &result, DEPTH_RECURSE);
          mUID = this->mItemTypeFilter.mUID;
          if ( mUID == -1 || (v12 = v10->mUID, v12 == -1) || mUID == v12 )
          {
            if ( this->mItemTierFilter.mLength <= 0
              || (v13 = PropertyUtils::Get<char const *>(v9, (UFG::qArray<unsigned long,0> *)&result.p, DEPTH_RECURSE),
                  (v14 = v13) == 0i64)
              || (int)UFG::qStringLength(v13) <= 0
              || !(unsigned int)UFG::qStringCompare(this->mItemTierFilter.mData, v14, -1) )
            {
              UFG::StoreFront::AddItemToStore(this, v9, v6, 0);
            }
          }
        }
        ++v6;
      }
      while ( v6 < NumStorageItems );
    }
  }
  if ( this->mStoreType == StoreType_Retail )
  {
    v15 = this->mpPropertySet;
    if ( v15
      && (v16 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                  v15,
                  (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
                  DEPTH_RECURSE)) != 0i64 )
    {
      mNumElements = v16->mNumElements;
    }
    else
    {
      mNumElements = 0;
    }
    for ( i = 0; i < mNumElements; ++i )
    {
      v19 = UFG::qPropertySet::Get<UFG::qPropertyList>(
              this->mpPropertySet,
              (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
              DEPTH_RECURSE);
      if ( v19 )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v19, 0x1Au, i);
        if ( ValuePtr )
        {
          v21 = *(_QWORD *)ValuePtr;
          if ( *(_QWORD *)ValuePtr )
          {
            v22 = (UFG::qPropertySet *)&ValuePtr[v21];
            if ( &ValuePtr[v21] )
            {
              if ( this->mItemTypeFilter.mUID == -1
                || (v23 = PropertyUtils::Get<UFG::qSymbol>((UFG::qPropertySet *)&ValuePtr[v21], &result, DEPTH_RECURSE)->mUID,
                    v23 == -1)
                || this->mItemTypeFilter.mUID == v23 )
              {
                if ( this->mItemTierFilter.mLength <= 0
                  || (v24 = PropertyUtils::Get<char const *>(
                              v22,
                              (UFG::qArray<unsigned long,0> *)&result.p,
                              DEPTH_RECURSE),
                      (v25 = v24) == 0i64)
                  || (int)UFG::qStringLength(v24) <= 0
                  || !(unsigned int)UFG::qStringCompare(this->mItemTierFilter.mData, v25, -1) )
                {
                  v26 = PropertyUtils::Get<UFG::qPropertyList>(
                          v22,
                          (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Stores,
                          DEPTH_RECURSE);
                  v27 = v26;
                  if ( v26 )
                  {
                    v28 = v26->mNumElements;
                    v29 = 0;
                    if ( v28 )
                    {
                      while ( this->mStoreName.mUID != UFG::qPropertyList::Get<UFG::qSymbol>(v27, v29)->mUID )
                      {
                        if ( ++v29 >= v28 )
                          goto LABEL_38;
                      }
                      UFG::StoreFront::AddItemToStore(this, v22, i, 1);
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
  this->mCategoryFilter = ItemCategory_BOAT;
  UFG::StoreFront::SetNextCategory(this);
}

// File Line: 262
// RVA: 0x4C59C0
void __fastcall UFG::StoreFront::UpdateCategoryHeading(UFG::StoreFront *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rax
  char *v4; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  UFG::qString::Set(&this->mCategoryHeading, &customCaption);
  if ( this->mCategoryFilter != Num_ItemCategories )
  {
    v2 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-categories");
    PropertySet = UFG::PropertySetManager::GetPropertySet(v2);
    v4 = PropertyUtils::Get<char const *>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)ItemCategorySymbols[this->mCategoryFilter],
           DEPTH_RECURSE);
    UFG::qString::Set(&this->mCategoryHeading, v4);
  }
}

// File Line: 295
// RVA: 0x4BCEE0
void __fastcall UFG::StoreFront::SetNextCategory(UFG::StoreFront *this)
{
  int v2; // r8d
  __int32 v3; // r9d
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *PropertySet; // rax
  char *v6; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  v2 = 0;
  while ( 1 )
  {
    v3 = (this->mCategoryFilter + 1) % 14;
    this->mCategoryFilter = v3;
    if ( this->mCategoryCount[v3] )
      break;
    if ( ++v2 >= 14 )
    {
      this->mCategoryFilter = Num_ItemCategories;
      break;
    }
  }
  UFG::qString::Set(&this->mCategoryHeading, &customCaption);
  if ( this->mCategoryFilter != Num_ItemCategories )
  {
    v4 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-categories");
    PropertySet = UFG::PropertySetManager::GetPropertySet(v4);
    v6 = PropertyUtils::Get<char const *>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)ItemCategorySymbols[this->mCategoryFilter],
           DEPTH_RECURSE);
    UFG::qString::Set(&this->mCategoryHeading, v6);
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
bool __fastcall UFG::StoreFront::IsOwnedClothingCategoryEmpty(
        UFG::StoreFront *this,
        UFG::StoreFront::ItemCategory category)
{
  if ( category == ItemCategory_ACCESSORIES || category == ItemCategory_OUTFIT )
    return this->mCategoryCount[category] == 0;
  else
    return this->mCategoryCount[category] < 2;
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
char *__fastcall UFG::StoreFront::GetCategoryHeading(UFG::StoreFront *this, int category)
{
  __int64 v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  v2 = category;
  if ( category >= 14 )
    return &customCaption;
  v3 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-categories");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v3);
  return PropertyUtils::Get<char const *>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)ItemCategorySymbols[v2],
           DEPTH_RECURSE);
}

// File Line: 359
// RVA: 0x4BBFD0
void __fastcall UFG::StoreFront::SetData(
        UFG::StoreFront *this,
        UFG::StoreFront::StoreType storeType,
        UFG::StoreFront::InventoryType inventoryType,
        UFG::qPropertySet *pParameters,
        UFG::qPropertySet *pPropertySet)
{
  char *v5; // r15
  unsigned int mUID; // ebx
  char *v10; // r12
  UFG::qSymbol *v11; // rax
  char *v12; // rax
  const char *v13; // rsi

  v5 = 0i64;
  this->mpStoreParameters = pParameters;
  mUID = UFG::gNullQSymbol.mUID;
  v10 = 0i64;
  if ( ((storeType - 1) & 0xFFFFFFFD) == 0 )
  {
    mUID = PropertyUtils::Get<UFG::qSymbol>(
             pParameters,
             (UFG::qArray<unsigned long,0> *)&qSymbol_StoreId,
             DEPTH_RECURSE)->mUID;
    v5 = PropertyUtils::Get<char const *>(
           this->mpStoreParameters,
           (UFG::qArray<unsigned long,0> *)&qSymbol_StoreTitle,
           DEPTH_RECURSE);
    v10 = PropertyUtils::Get<char const *>(
            this->mpStoreParameters,
            (UFG::qArray<unsigned long,0> *)&qSymbol_StoreDesc,
            DEPTH_RECURSE);
  }
  UFG::qSymbol::set_null(&this->mItemTypeFilter);
  UFG::qString::Set(&this->mItemTierFilter, &customCaption);
  if ( this->mpStoreParameters )
  {
    v11 = PropertyUtils::Get<UFG::qSymbol>(
            this->mpStoreParameters,
            (UFG::qArray<unsigned long,0> *)&qSymbol_StoreItemFilter,
            DEPTH_RECURSE);
    if ( v11 )
      this->mItemTypeFilter = (UFG::qSymbol)v11->mUID;
    v12 = PropertyUtils::Get<char const *>(
            this->mpStoreParameters,
            (UFG::qArray<unsigned long,0> *)&qSymbol_StoreTierFilter,
            DEPTH_RECURSE);
    v13 = v12;
    if ( v12 && (int)UFG::qStringLength(v12) > 0 )
      UFG::qString::Set(&this->mItemTierFilter, v13);
  }
  this->mStoreType = storeType;
  this->mInventoryType = inventoryType;
  this->mpPropertySet = pPropertySet;
  UFG::qString::Set(&this->mStoreTitle, v5);
  UFG::qString::Set(&this->mStoreDesc, v10);
  this->mStoreName.mUID = mUID;
  if ( storeType )
    UFG::StoreFront::BuildCategories(this);
}

// File Line: 415
// RVA: 0x498720
void __fastcall UFG::StoreFront::ClosePreviewShutter(UFG::StoreFront *this)
{
  UFG::qSymbol *v2; // rax
  UFG::SimObjectGame *SimObject; // rax
  UFG::SimObjectGame *v4; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qPropertySet *v8; // rax
  ActionNodePlayable *v9; // rbx
  int mCount; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-40h] BYREF
  UFG::qString v12; // [rsp+38h] [rbp-30h] BYREF

  if ( (_S7_13 & 1) == 0 )
  {
    _S7_13 |= 1u;
    UIDClosed.mUID = UFG::qStringHashUpper32("Closed", -1);
  }
  v2 = PropertyUtils::Get<UFG::qSymbol>(
         this->mpStoreParameters,
         (UFG::qArray<unsigned long,0> *)&qSymbol_StorePreviewShutter,
         DEPTH_RECURSE);
  if ( v2 )
  {
    if ( v2->mUID != -1 )
    {
      SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v2);
      v4 = SimObject;
      if ( SimObject )
      {
        m_Flags = SimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = SimObject->m_Components.p[7].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = SimObject->m_Components.p[6].m_pComponent;
          }
          else
          {
            if ( (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    SimObject,
                                    UFG::ActionTreeComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(SimObject, UFG::ActionTreeComponent::_TypeUID);
            m_pComponent = ComponentOfTypeHK;
          }
        }
        else
        {
          m_pComponent = SimObject->m_Components.p[7].m_pComponent;
        }
        v8 = PropertyUtils::Get<char const *>(v4->m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_ActBaseName);
        UFG::qString::qString(&v12, "\\Global\\%s\\Object\\Animation\\Closing", (const char *)v8);
        absolutePath.mPath.mCount = 0;
        absolutePath.mPath.mData.mOffset = 0i64;
        ActionPath::Append(&absolutePath, v12.mData);
        v9 = (ActionNodePlayable *)ActionNode::Find(&absolutePath, 0i64);
        if ( v9 && !ActionController::IsPlaying((ActionController *)&m_pComponent[3], &UIDClosed, 0xFFFFFFFF, 1) )
          ActionController::Play((ActionController *)&m_pComponent[3], v9, 0);
        mCount = absolutePath.mPath.mCount;
        if ( absolutePath.mPath.mCount >= 0 )
        {
          if ( absolutePath.mPath.mData.mOffset )
          {
            if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
            {
              operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
              mCount = absolutePath.mPath.mCount;
            }
          }
          absolutePath.mPath.mData.mOffset = 0i64;
          absolutePath.mPath.mCount = mCount & 0x80000000;
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
  UFG::SimObjectGame *SimObject; // rax
  UFG::SimObjectGame *v3; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qPropertySet *v7; // rax
  __int64 v8; // rax
  const char *v9; // rdx
  ActionNodePlayable *v10; // rax
  ActionPath absolutePath; // [rsp+28h] [rbp-40h] BYREF
  UFG::qString v12; // [rsp+38h] [rbp-30h] BYREF

  v1 = PropertyUtils::Get<UFG::qSymbol>(
         this->mpStoreParameters,
         (UFG::qArray<unsigned long,0> *)&qSymbol_StorePreviewShutter,
         DEPTH_RECURSE);
  if ( v1 )
  {
    if ( v1->mUID != -1 )
    {
      SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v1);
      v3 = SimObject;
      if ( SimObject )
      {
        m_Flags = SimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = SimObject->m_Components.p[7].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = SimObject->m_Components.p[6].m_pComponent;
          }
          else
          {
            if ( (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    SimObject,
                                    UFG::ActionTreeComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(SimObject, UFG::ActionTreeComponent::_TypeUID);
            m_pComponent = ComponentOfTypeHK;
          }
        }
        else
        {
          m_pComponent = SimObject->m_Components.p[7].m_pComponent;
        }
        v7 = PropertyUtils::Get<char const *>(v3->m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_ActBaseName);
        UFG::qString::qString(&v12, "\\Global\\%s\\Object\\Animation\\Opening", (const char *)v7);
        v9 = *(const char **)(v8 + 24);
        absolutePath.mPath.mCount = 0;
        absolutePath.mPath.mData.mOffset = 0i64;
        ActionPath::Append(&absolutePath, v9);
        UFG::qString::~qString(&v12);
        v10 = (ActionNodePlayable *)ActionNode::Find(&absolutePath, 0i64);
        if ( v10 )
          ActionController::Play((ActionController *)&m_pComponent[3], v10, 0);
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
char __fastcall UFG::StoreFront::FindItemIndex(
        UFG::StoreFront *this,
        UFG::qSymbol *spawnInfo,
        unsigned int *itemIndexOut)
{
  __int64 mCategoryFilter; // rax
  int v4; // ebx
  unsigned int v8; // edi
  UFG::StoreFront *i; // rax
  UFG::qPropertySet *Item; // rax

  mCategoryFilter = this->mCategoryFilter;
  v4 = 0;
  if ( (_DWORD)mCategoryFilter == 14 )
  {
    v8 = 0;
    for ( i = (UFG::StoreFront *)this->m_Items.mNode.mNext; i != (UFG::StoreFront *)&this->m_Items; ++v8 )
      i = (UFG::StoreFront *)i->mpPropertySet;
  }
  else
  {
    v8 = this->mCategoryCount[mCategoryFilter];
  }
  if ( !v8 )
    return 0;
  while ( 1 )
  {
    Item = UFG::StoreFront::GetItem(this, v4);
    if ( Item )
    {
      if ( spawnInfo->mUID == PropertyUtils::Get<UFG::qSymbol>(
                                Item,
                                (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_SpawnObjectInfo,
                                DEPTH_RECURSE)->mUID )
        break;
    }
    if ( ++v4 >= v8 )
      return 0;
  }
  *itemIndexOut = v4;
  return 1;
}

// File Line: 497
// RVA: 0x4BECF0
UFG::SimObjectCVBase *__fastcall UFG::StoreFront::SpawnItem(UFG::StoreFront *this, int filterIndex)
{
  UFG::qPropertySet *Item; // rax
  UFG::qPropertySet *v4; // rbp
  UFG::qSymbol *v5; // rbx
  char *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::SimObject *v8; // rax
  UFG::SimObjectCVBase *v9; // rdi
  __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rbx
  SSActorClass *v12; // rsi
  SSClass *i_class_p; // rcx
  SSClass *i_superclass_p; // rcx
  UFG::TSVehicle *Actor; // rax
  __int16 v16; // cx
  UFG::SimObjectVehiclePropertiesComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectVehiclePropertiesComponent *v18; // rbx
  float *v19; // rax
  float v20; // xmm0_4
  UFG::qBaseTreeRB *Named; // rax
  UFG::TransformNodeComponent *mParent; // rbx
  UFG::qSymbol v24; // [rsp+30h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+18h] BYREF
  UFG::qSymbol objName; // [rsp+78h] [rbp+20h] BYREF

  Item = UFG::StoreFront::GetItem(this, filterIndex);
  v4 = Item;
  if ( !Item )
    return 0i64;
  v5 = PropertyUtils::Get<UFG::qSymbol>(
         Item,
         (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_SpawnObjectInfo,
         DEPTH_RECURSE);
  v6 = PropertyUtils::Get<char const *>(
         this->mpStoreParameters,
         (UFG::qArray<unsigned long,0> *)&qSymbol_StorePreviewMarker,
         DEPTH_RECURSE);
  UFG::qSymbol::create_from_string(&result, v6);
  if ( !v5 || v5->mUID == -1 || result.mUID == -1 )
    return 0i64;
  v7 = UFG::qSymbol::create_from_string(&v24, sStoreItemPrefix);
  UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v7);
  v8 = UFG::SpawnInfoInterface::SpawnObject(&objName, v5, UnReferenced, 0i64, 0i64, 0i64);
  v9 = (UFG::SimObjectCVBase *)v8;
  if ( v8 )
  {
    m_Flags = v8->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TSActorComponent *)v8->m_Components.p[4].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::TSActorComponent *)v8->m_Components.p[3].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::TSActorComponent *)v8->m_Components.p[2].m_pComponent;
      }
      else
      {
        m_pComponent = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v8, UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::TSActorComponent *)v8->m_Components.p[4].m_pComponent;
    }
    if ( m_pComponent )
    {
      v12 = UFG::TSVehicle::mClass;
      i_class_p = UFG::TSActorComponent::GetActor(m_pComponent)->i_class_p;
      if ( v12 == i_class_p
        || (i_superclass_p = i_class_p->i_superclass_p) != 0i64 && SSClass::is_class(i_superclass_p, v12) )
      {
        Actor = (UFG::TSVehicle *)UFG::TSActorComponent::GetActor(m_pComponent);
        UFG::TSVehicle::UnlockDoors(Actor, 1);
      }
    }
    v16 = v9->m_Flags;
    if ( (v16 & 0x4000) != 0 || v16 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v9);
    }
    else if ( (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v9,
                                                                        UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                        v9,
                                                                        UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    }
    v18 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      v19 = PropertyUtils::Get<float>(
              v4,
              (UFG::qArray<unsigned long,0> *)&qSymbol_FaceReplenishMultiplier,
              DEPTH_RECURSE);
      if ( v19 )
        v20 = *v19;
      else
        v20 = *(float *)&FLOAT_1_0;
      v18->mFaceReplenishMultiplier = v20;
    }
  }
  Named = UFG::MarkerBase::GetNamed(&result);
  if ( Named )
  {
    mParent = (UFG::TransformNodeComponent *)Named[1].mNULL.mParent;
    UFG::TransformNodeComponent::UpdateWorldTransform(mParent);
    UFG::SimObjectUtility::Teleport(v9, &mParent->mWorldTransform);
  }
  return v9;
}

// File Line: 547
// RVA: 0x4A1CD0
UFG::qBaseNodeRB *__fastcall UFG::StoreFront::GetCameraMarker(UFG::StoreFront *this)
{
  UFG::qPropertySet *mpStoreParameters; // rcx
  char *v2; // rax
  UFG::qBaseTreeRB *Named; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  mpStoreParameters = this->mpStoreParameters;
  if ( mpStoreParameters
    && (v2 = PropertyUtils::Get<char const *>(
               mpStoreParameters,
               (UFG::qArray<unsigned long,0> *)&qSymbol_StoreCameraMarker,
               DEPTH_RECURSE),
        UFG::qSymbol::create_from_string(&result, v2),
        (Named = UFG::MarkerBase::GetNamed(&result)) != 0i64) )
  {
    return Named->mNULL.mChild[0];
  }
  else
  {
    return 0i64;
  }
}

// File Line: 567
// RVA: 0x4A5E70
UFG::qBaseNodeRB *__fastcall UFG::StoreFront::GetPlayerMarker(UFG::StoreFront *this)
{
  UFG::qPropertySet *mpStoreParameters; // rcx
  char *v2; // rax
  UFG::qBaseTreeRB *Named; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  mpStoreParameters = this->mpStoreParameters;
  if ( mpStoreParameters
    && (v2 = PropertyUtils::Get<char const *>(
               mpStoreParameters,
               (UFG::qArray<unsigned long,0> *)&qSymbol_StorePlayerMarker,
               DEPTH_RECURSE),
        UFG::qSymbol::create_from_string(&result, v2),
        (Named = UFG::MarkerBase::GetNamed(&result)) != 0i64) )
  {
    return Named->mNULL.mChild[0];
  }
  else
  {
    return 0i64;
  }
}

// File Line: 578
// RVA: 0x4A5E20
UFG::qBaseNodeRB *__fastcall UFG::StoreFront::GetPlayerExitMarker(UFG::StoreFront *this)
{
  UFG::qPropertySet *mpStoreParameters; // rcx
  char *v2; // rax
  UFG::qBaseTreeRB *Named; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  mpStoreParameters = this->mpStoreParameters;
  if ( mpStoreParameters
    && (v2 = PropertyUtils::Get<char const *>(
               mpStoreParameters,
               (UFG::qArray<unsigned long,0> *)&qSymbol_StorePlayerExitMarker,
               DEPTH_RECURSE),
        UFG::qSymbol::create_from_string(&result, v2),
        (Named = UFG::MarkerBase::GetNamed(&result)) != 0i64) )
  {
    return Named->mNULL.mChild[0];
  }
  else
  {
    return 0i64;
  }
}

// File Line: 589
// RVA: 0x4A59E0
__int64 __fastcall UFG::StoreFront::GetNumStorageItems(UFG::StoreFront *this)
{
  __int64 mInventoryType; // rdi
  UFG::GameStatTracker *v2; // rbx
  UFG::PersistentData::MapBool *v3; // rdx

  mInventoryType = this->mInventoryType;
  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = v2->mpSnapshots[0]->mpMapBools[mInventoryType];
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
  __int64 mCategoryFilter; // rax
  UFG::qList<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem,1,0> *p_m_Items; // rdx
  __int64 result; // rax
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *i; // rcx

  mCategoryFilter = this->mCategoryFilter;
  if ( (_DWORD)mCategoryFilter != 14 )
    return this->mCategoryCount[mCategoryFilter];
  p_m_Items = &this->m_Items;
  result = 0i64;
  for ( i = this->m_Items.mNode.mNext;
        i != (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)p_m_Items;
        result = (unsigned int)(result + 1) )
  {
    i = i->mNext;
  }
  return result;
}

// File Line: 654
// RVA: 0x4A6950
UFG::qPropertySet *__fastcall UFG::StoreFront::GetStorageItem(UFG::StoreFront *this, unsigned int index)
{
  __int64 v2; // rdi
  __int64 mInventoryType; // rsi
  UFG::GameStatTracker *v4; // rbx
  UFG::PersistentData::MapBool *v5; // rdx
  UFG::qSymbol *v6; // rdx
  UFG::StoreFrontTracker *v7; // rbx
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rbp
  unsigned int mNumElements; // esi
  unsigned int v11; // edi
  char *ValuePtr; // rax
  char *v13; // rbx
  char *v14; // rax
  UFG::qSymbolUC v16; // [rsp+40h] [rbp+8h] BYREF

  v2 = index;
  mInventoryType = this->mInventoryType;
  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  v5 = v4->mpSnapshots[0]->mpMapBools[mInventoryType];
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
         (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
         DEPTH_RECURSE);
  v9 = v8;
  if ( v8 && (mNumElements = v8->mNumElements, v11 = 0, mNumElements) )
  {
    while ( 1 )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v13 = &ValuePtr[*(_QWORD *)ValuePtr];
      else
        v13 = 0i64;
      if ( *((_DWORD *)v13 + 16) == v16.mUID )
        break;
      if ( ++v11 >= mNumElements )
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
  UFG::StoreFront::ItemCategory mCategoryFilter; // edi
  __int64 v3; // rbx
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *mNext; // rcx
  int v6; // r9d
  int v7; // r8d
  UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *i; // rax
  unsigned int mPrev_low; // edi
  UFG::qPropertyList *v10; // rax
  char *ValuePtr; // rax

  mCategoryFilter = this->mCategoryFilter;
  v3 = 0i64;
  if ( mCategoryFilter != Num_ItemCategories )
  {
    mNext = this->m_Items.mNode.mNext;
    v6 = 0;
    v7 = 0;
    if ( mNext == (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)&this->m_Items )
    {
LABEL_7:
      filterIndex = -1;
      goto LABEL_8;
    }
    while ( 1 )
    {
      if ( WORD2(mNext[1].mPrev) == mCategoryFilter )
      {
        if ( v7 == filterIndex )
        {
          filterIndex = v6;
          break;
        }
        ++v7;
      }
      mNext = mNext->mNext;
      ++v6;
      if ( mNext == (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)&this->m_Items )
        goto LABEL_7;
    }
  }
LABEL_8:
  for ( i = this->m_Items.mNode.mNext; filterIndex > 0; --filterIndex )
  {
    if ( i == (UFG::qNode<UFG::StoreFront::StoreItem,UFG::StoreFront::StoreItem> *)&this->m_Items )
      break;
    i = i->mNext;
  }
  if ( !BYTE2(i[1].mPrev) )
    return UFG::StoreFront::GetStorageItem(this, LOWORD(i[1].mPrev));
  mPrev_low = LOWORD(i[1].mPrev);
  v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          this->mpPropertySet,
          (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
          DEPTH_RECURSE);
  if ( v10 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, mPrev_low);
    if ( ValuePtr )
    {
      if ( *(_QWORD *)ValuePtr )
        return (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    }
  }
  return (UFG::qPropertySet *)v3;
}

// File Line: 704
// RVA: 0x496890
bool __fastcall UFG::StoreFront::CanPurchase(UFG::StoreFront *this, int filterIndex)
{
  UFG::qPropertySet *Item; // rax
  float ItemPriceBasedOnClothes; // xmm6_4

  if ( this->mStoreType != StoreType_Retail )
    return 0;
  Item = UFG::StoreFront::GetItem(this, filterIndex);
  if ( !Item )
    return 0;
  ItemPriceBasedOnClothes = UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(Item);
  return (float)UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[62].mValue >= ItemPriceBasedOnClothes;
}

// File Line: 726
// RVA: 0x4B3750
char __fastcall UFG::StoreFront::PurchaseItem(UFG::StoreFront *this, int filterIndex)
{
  UFG::qPropertySet *Item; // rsi
  UFG::qPropertySet *v5; // rax
  float ItemPriceBasedOnClothes; // xmm6_4
  UFG::StoreFront::InventoryType mInventoryType; // ebx
  UFG::StoreFrontTracker *v8; // rax

  Item = UFG::StoreFront::GetItem(this, filterIndex);
  if ( !Item )
    return 0;
  if ( this->mStoreType != StoreType_Retail )
    return 0;
  v5 = UFG::StoreFront::GetItem(this, filterIndex);
  if ( !v5 )
    return 0;
  ItemPriceBasedOnClothes = UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v5);
  if ( (float)UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[62].mValue < ItemPriceBasedOnClothes )
    return 0;
  mInventoryType = this->mInventoryType;
  v8 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::AddItemToInventory(v8, Item, mInventoryType, 1, 0);
  return 1;
}

// File Line: 740
// RVA: 0x4AD160
bool __fastcall UFG::StoreFront::IsWeiWearingAnPrefinedOutfit()
{
  UFG::GameStatTracker *v0; // rbx

  v0 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
__int64 __fastcall UFG::StoreFront::ValidateCustomOutfitItem(unsigned int itemId, unsigned int *defaultSymbol)
{
  UFG::GameStatTracker *v4; // rbx
  UFG::PersistentData::MapBool *v5; // r8
  __int64 v6; // rcx
  unsigned int v7; // r9d
  bool mBoolValue; // al
  __int64 v9; // rcx
  unsigned int size; // r9d
  unsigned int v11; // r9d
  __int64 v12; // rcx
  UFG::PersistentData::KeyValue *i; // rdx
  bool v14; // zf
  __int64 v15; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h] BYREF

  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  UFG::qSymbol::qSymbol(&result, itemId);
  v5 = v4->mpSnapshots[0]->mpMapBools[Asset_Clothing];
  if ( v5->mKeepType )
  {
    if ( v5->mKeepType == KEEP_TRUE )
    {
      v9 = 0i64;
      size = v5->mNames.size;
      if ( size )
      {
        while ( result.mUID != v5->mNames.p[v9].mUID )
        {
          v9 = (unsigned int)(v9 + 1);
          if ( (unsigned int)v9 >= size )
            goto LABEL_16;
        }
      }
      else
      {
LABEL_16:
        LODWORD(v9) = -1;
      }
      mBoolValue = (_DWORD)v9 != -1;
LABEL_25:
      v14 = mBoolValue;
      v15 = itemId;
      if ( v14 )
        return v15;
      return *defaultSymbol;
    }
    v6 = (unsigned int)(v5->mKeepType - 2);
    if ( v5->mKeepType == KEEP_FALSE )
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
      mBoolValue = (_DWORD)v6 == -1;
      goto LABEL_25;
    }
  }
  else
  {
    v11 = v5->mValues.size;
    v12 = 0i64;
    if ( v11 )
    {
      for ( i = v5->mValues.p; i->mKey.mUID != result.mUID; ++i )
      {
        v12 = (unsigned int)(v12 + 1);
        if ( (unsigned int)v12 >= v11 )
          return *defaultSymbol;
      }
      if ( (_DWORD)v12 != -1 )
      {
        mBoolValue = v5->mValues.p[v12].mBoolValue;
        goto LABEL_25;
      }
    }
  }
  return *defaultSymbol;
}

// File Line: 765
// RVA: 0x49E350
char __fastcall UFG::StoreFront::EquipCustomOutfit(
        UFG::StoreFront::OutfitNum a_eOutfitNum,
        bool bSaveToStats,
        bool bUpdateLastEquipItem)
{
  UFG::GameStatTracker *v5; // rdi
  unsigned int mUID; // ebx
  UFG::qSymbol *v7; // rax
  UFG::PersistentData::MapInt *v8; // r9
  unsigned int size; // r8d
  __int64 v10; // rcx
  UFG::PersistentData::KeyValue *p; // r9
  UFG::PersistentData::KeyValue *v12; // rdx
  unsigned int mIntValue; // ecx
  UFG::qSymbol *v14; // rax
  UFG::PersistentData::MapInt *v15; // r9
  unsigned int v16; // r8d
  __int64 v17; // rcx
  UFG::PersistentData::KeyValue *v18; // r9
  UFG::PersistentData::KeyValue *v19; // rdx
  unsigned int v20; // ecx
  UFG::qSymbol *v21; // rax
  UFG::PersistentData::MapInt *v22; // r9
  unsigned int v23; // r8d
  __int64 v24; // rcx
  UFG::PersistentData::KeyValue *v25; // r9
  UFG::PersistentData::KeyValue *v26; // rdx
  unsigned int v27; // ecx
  UFG::qSymbol *v28; // rax
  UFG::PersistentData::MapInt *v29; // r9
  unsigned int v30; // r8d
  __int64 v31; // rcx
  UFG::PersistentData::KeyValue *v32; // r9
  UFG::PersistentData::KeyValue *v33; // rdx
  unsigned int v34; // ecx
  UFG::qSymbol *v35; // rax
  UFG::PersistentData::MapInt *v36; // r9
  unsigned int v37; // r8d
  __int64 v38; // rcx
  UFG::PersistentData::KeyValue *v39; // r9
  UFG::PersistentData::KeyValue *v40; // rdx
  unsigned int v41; // ecx
  UFG::qSymbol *v42; // rax
  UFG::PersistentData::MapInt *v43; // r9
  unsigned int v44; // r8d
  __int64 v45; // rcx
  UFG::PersistentData::KeyValue *v46; // r9
  UFG::PersistentData::KeyValue *v47; // rdx
  unsigned int v48; // ecx
  UFG::qSymbol *v49; // rax
  UFG::PersistentData::MapInt *v50; // r9
  unsigned int v51; // r8d
  __int64 v52; // rcx
  UFG::PersistentData::KeyValue *v53; // r9
  UFG::PersistentData::KeyValue *v54; // rdx
  unsigned int v55; // ecx
  UFG::qSymbol *v56; // rax
  UFG::PersistentData::MapInt *v57; // r9
  unsigned int v58; // r8d
  __int64 v59; // rcx
  UFG::PersistentData::KeyValue *v60; // r9
  UFG::PersistentData::KeyValue *v61; // rdx
  unsigned int v62; // ecx
  UFG::qSymbol *v63; // rax
  UFG::PersistentData::MapInt *v64; // r9
  unsigned int v65; // r8d
  __int64 v66; // rcx
  UFG::PersistentData::KeyValue *v67; // r9
  UFG::PersistentData::KeyValue *v68; // rdx
  unsigned int v69; // ecx
  unsigned int *v70; // r15
  __int64 v71; // r12
  unsigned int v72; // ebx
  UFG::StoreFrontTracker *v73; // rdi
  UFG::qPropertyList *v74; // rax
  UFG::qPropertyList *v75; // r14
  unsigned int mNumElements; // esi
  unsigned int v77; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v79; // rcx
  UFG::StoreFront::ItemCategory v80; // eax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  int dest[14]; // [rsp+38h] [rbp-38h] BYREF
  UFG::qWiseSymbol result; // [rsp+B0h] [rbp+40h] BYREF
  bool v85; // [rsp+C0h] [rbp+50h]
  UFG::qWiseSymbol *p_result; // [rsp+C8h] [rbp+58h]

  v85 = bUpdateLastEquipItem;
  UFG::qMemSet(dest, 0, 0x38u);
  v5 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  mUID = UFG::qSymbol::qSymbol(&result, a_eOutfitNum + 1)->mUID;
  p_result = &result;
  v7 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "P_JeansBase");
  v8 = v5->mpSnapshots[0]->mpMapInts[11];
  size = v8->mValues.size;
  v10 = 0i64;
  if ( !v8->mValues.size )
    goto LABEL_12;
  p = v8->mValues.p;
  v12 = p;
  while ( v12->mKey.mUID != mUID )
  {
    v10 = (unsigned int)(v10 + 1);
    ++v12;
    if ( (unsigned int)v10 >= size )
      goto LABEL_12;
  }
  if ( (_DWORD)v10 == -1 )
LABEL_12:
    mIntValue = 0;
  else
    mIntValue = p[v10].mIntValue;
  dest[1] = UFG::StoreFront::ValidateCustomOutfitItem(mIntValue, (__int64)v7);
  p_result = &result;
  v14 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "S_SleekBase");
  v15 = v5->mpSnapshots[0]->mpMapInts[12];
  v16 = v15->mValues.size;
  v17 = 0i64;
  if ( !v15->mValues.size )
    goto LABEL_20;
  v18 = v15->mValues.p;
  v19 = v18;
  while ( v19->mKey.mUID != mUID )
  {
    v17 = (unsigned int)(v17 + 1);
    ++v19;
    if ( (unsigned int)v17 >= v16 )
      goto LABEL_20;
  }
  if ( (_DWORD)v17 == -1 )
LABEL_20:
    v20 = 0;
  else
    v20 = v18[v17].mIntValue;
  dest[2] = UFG::StoreFront::ValidateCustomOutfitItem(v20, (__int64)v14);
  p_result = &result;
  v21 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "DefaultHair");
  v22 = v5->mpSnapshots[0]->mpMapInts[5];
  v23 = v22->mValues.size;
  v24 = 0i64;
  if ( !v22->mValues.size )
    goto LABEL_28;
  v25 = v22->mValues.p;
  v26 = v25;
  while ( v26->mKey.mUID != mUID )
  {
    v24 = (unsigned int)(v24 + 1);
    ++v26;
    if ( (unsigned int)v24 >= v23 )
      goto LABEL_28;
  }
  if ( (_DWORD)v24 == -1 )
LABEL_28:
    v27 = 0;
  else
    v27 = v25[v24].mIntValue;
  dest[3] = UFG::StoreFront::ValidateCustomOutfitItem(v27, (__int64)v21);
  p_result = &result;
  v28 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "T_JacketBase");
  v29 = v5->mpSnapshots[0]->mpMapInts[8];
  v30 = v29->mValues.size;
  v31 = 0i64;
  if ( !v29->mValues.size )
    goto LABEL_36;
  v32 = v29->mValues.p;
  v33 = v32;
  while ( v33->mKey.mUID != mUID )
  {
    v31 = (unsigned int)(v31 + 1);
    ++v33;
    if ( (unsigned int)v31 >= v30 )
      goto LABEL_36;
  }
  if ( (_DWORD)v31 == -1 )
LABEL_36:
    v34 = 0;
  else
    v34 = v32[v31].mIntValue;
  dest[0] = UFG::StoreFront::ValidateCustomOutfitItem(v34, (__int64)v28);
  p_result = &result;
  v35 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoChain");
  v36 = v5->mpSnapshots[0]->mpMapInts[13];
  v37 = v36->mValues.size;
  v38 = 0i64;
  if ( !v36->mValues.size )
    goto LABEL_44;
  v39 = v36->mValues.p;
  v40 = v39;
  while ( v40->mKey.mUID != mUID )
  {
    v38 = (unsigned int)(v38 + 1);
    ++v40;
    if ( (unsigned int)v38 >= v37 )
      goto LABEL_44;
  }
  if ( (_DWORD)v38 == -1 )
LABEL_44:
    v41 = 0;
  else
    v41 = v39[v38].mIntValue;
  dest[5] = UFG::StoreFront::ValidateCustomOutfitItem(v41, (__int64)v35);
  p_result = &result;
  v42 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoGlasses");
  v43 = v5->mpSnapshots[0]->mpMapInts[6];
  v44 = v43->mValues.size;
  v45 = 0i64;
  if ( !v43->mValues.size )
    goto LABEL_52;
  v46 = v43->mValues.p;
  v47 = v46;
  while ( v47->mKey.mUID != mUID )
  {
    v45 = (unsigned int)(v45 + 1);
    ++v47;
    if ( (unsigned int)v45 >= v44 )
      goto LABEL_52;
  }
  if ( (_DWORD)v45 == -1 )
LABEL_52:
    v48 = 0;
  else
    v48 = v46[v45].mIntValue;
  dest[6] = UFG::StoreFront::ValidateCustomOutfitItem(v48, (__int64)v42);
  p_result = &result;
  v49 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoChain");
  v50 = v5->mpSnapshots[0]->mpMapInts[7];
  v51 = v50->mValues.size;
  v52 = 0i64;
  if ( !v50->mValues.size )
    goto LABEL_60;
  v53 = v50->mValues.p;
  v54 = v53;
  while ( v54->mKey.mUID != mUID )
  {
    v52 = (unsigned int)(v52 + 1);
    ++v54;
    if ( (unsigned int)v52 >= v51 )
      goto LABEL_60;
  }
  if ( (_DWORD)v52 == -1 )
LABEL_60:
    v55 = 0;
  else
    v55 = v53[v52].mIntValue;
  dest[7] = UFG::StoreFront::ValidateCustomOutfitItem(v55, (__int64)v49);
  p_result = &result;
  v56 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoWatch");
  v57 = v5->mpSnapshots[0]->mpMapInts[9];
  v58 = v57->mValues.size;
  v59 = 0i64;
  if ( !v57->mValues.size )
    goto LABEL_68;
  v60 = v57->mValues.p;
  v61 = v60;
  while ( v61->mKey.mUID != mUID )
  {
    v59 = (unsigned int)(v59 + 1);
    ++v61;
    if ( (unsigned int)v59 >= v58 )
      goto LABEL_68;
  }
  if ( (_DWORD)v59 == -1 )
LABEL_68:
    v62 = 0;
  else
    v62 = v60[v59].mIntValue;
  dest[8] = UFG::StoreFront::ValidateCustomOutfitItem(v62, (__int64)v56);
  p_result = &result;
  v63 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "NoRightWrist");
  v64 = v5->mpSnapshots[0]->mpMapInts[10];
  v65 = v64->mValues.size;
  v66 = 0i64;
  if ( !v64->mValues.size )
    goto LABEL_76;
  v67 = v64->mValues.p;
  v68 = v67;
  while ( v68->mKey.mUID != mUID )
  {
    v66 = (unsigned int)(v66 + 1);
    ++v68;
    if ( (unsigned int)v66 >= v65 )
      goto LABEL_76;
  }
  if ( (_DWORD)v66 == -1 )
LABEL_76:
    v69 = 0;
  else
    v69 = v67[v66].mIntValue;
  dest[9] = UFG::StoreFront::ValidateCustomOutfitItem(v69, (__int64)v63);
  v70 = (unsigned int *)dest;
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
              (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
              DEPTH_RECURSE);
      v75 = v74;
      if ( v74 )
      {
        mNumElements = v74->mNumElements;
        v77 = 0;
        if ( mNumElements )
        {
          while ( 1 )
          {
            ValuePtr = UFG::qPropertyList::GetValuePtr(v75, 0x1Au, v77);
            if ( ValuePtr && *(_QWORD *)ValuePtr )
              v79 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
            else
              v79 = 0i64;
            if ( v79->mName.mUID == v72 )
              break;
            if ( ++v77 >= mNumElements )
              goto LABEL_89;
          }
          UFG::StoreFront::EquipItem(v79, bSaveToStats, 0, 1, 1, 0);
        }
      }
    }
LABEL_89:
    ++v70;
    --v71;
  }
  while ( v71 );
  v80 = UFG::StoreFront::mLastEquipedItemCategory;
  if ( v85 )
    v80 = ItemCategory_CUSTOM_OUTFIT;
  UFG::StoreFront::mLastEquipedItemCategory = v80;
  LocalPlayer = UFG::GetLocalPlayer();
  UFG::StoreMeshHelper::QueueSwapping(LocalPlayer);
  return 1;
}

// File Line: 818
// RVA: 0x4B7470
void __fastcall UFG::StoreFront::ResolveItemEquip(
        UFG::qPropertySet *pItem,
        UFG::SimObject *pPlayer,
        UFG::StreamedResourceComponent *pSrc,
        UFG::qArray<UFG::StoreFront::EquippedItemResolution,0> *resolvedEquipment)
{
  UFG::qSymbol *v7; // rbx
  UFG::StoreFront::EquippedItemResolution *v8; // rcx
  UFG::qPropertyList *v9; // rax
  UFG::qPropertyList *v10; // rsi
  unsigned int v11; // edi
  UFG::qSymbol *v12; // rbx
  UFG::StoreFront::EquippedItemResolution *v13; // rdx
  __int64 mExcludedByCount; // rax
  UFG::qArray<unsigned long,0> result; // [rsp+50h] [rbp+18h] BYREF

  v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pItem,
         (UFG::qArray<unsigned long,0> *)&qSymbol_ComponentType,
         DEPTH_RECURSE);
  UFG::TrueCrowdDataBase::Instance();
  v8 = &resolvedEquipment->p[(unsigned int)UFG::TrueCrowdDefinition::GetEntityComponentIndex(
                                             &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
                                             pSrc->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex,
                                             v7)];
  if ( !v8->mItem )
  {
    v8->mItem = pItem;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "ComponentExclusions");
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(pItem, &result, DEPTH_RECURSE);
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
          v13 = &resolvedEquipment->p[(unsigned int)UFG::TrueCrowdDefinition::GetEntityComponentIndex(
                                                      &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
                                                      pSrc->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex,
                                                      v12)];
          mExcludedByCount = v13->mExcludedByCount;
          v13->mIsExcluded = 1;
          v13->mExcludedBy[mExcludedByCount] = pItem;
          ++v13->mExcludedByCount;
        }
        while ( v11 < v10->mNumElements );
      }
    }
  }
}

// File Line: 880
// RVA: 0x49E860
void __fastcall UFG::StoreFront::EquipItem(
        UFG::qPropertySet *pItem,
        bool bSaveToStats,
        bool bRefreshPlayer,
        bool bRemoveAnyPredefinedOutfit,
        bool bUpdateLastEquipItem,
        bool bPreviewing)
{
  bool v6; // r14
  UFG::SimObjectCharacter *LocalPlayer; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // r9
  UFG::qSymbol *v11; // rax
  int v12; // edi
  UFG::StreamedResourceComponent *m_pComponent; // r15
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSymbol *v16; // rbx
  UFG::StoreFrontTracker *v17; // rbx
  UFG::qPropertyList *v18; // rax
  UFG::qPropertyList *v19; // rsi
  unsigned int mNumElements; // edi
  unsigned int v21; // ebx
  char *ValuePtr; // rax
  UFG::qPropertySet *v23; // rcx
  UFG::qPropertyList *v24; // r13
  unsigned int v25; // r12d
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
  UFG::StoreFront::EquippedItemResolution *p; // rbx
  bool v37; // si
  int v38; // r13d
  UFG::qPropertyList *v39; // r12
  unsigned int v40; // r15d
  UFG::qSymbol *v41; // r14
  UFG::qPropertyList *v42; // rax
  UFG::qPropertyList *v43; // rsi
  unsigned int v44; // edi
  unsigned int v45; // ebx
  char *v46; // rax
  UFG::qPropertySet *v47; // rcx
  unsigned int v48; // esi
  UFG::qPropertySet **p_mDefaultItem; // r14
  UFG::qSymbol *v50; // rax
  __int64 v51; // rdi
  UFG::qPropertySet *v52; // rbx
  UFG::GameStatTracker *v53; // rcx
  unsigned int v54; // edx
  UFG::GameStatTracker *v55; // rcx
  UFG::GameStatTracker *v56; // r8
  __int64 v57; // r13
  int *v58; // r12
  __int64 v59; // rbx
  UFG::GameStatTracker *v60; // rax
  __int64 v61; // r15
  UFG::qPropertyList *v62; // rax
  UFG::qPropertyList *v63; // r14
  unsigned int v64; // esi
  unsigned int v65; // edi
  char *v66; // rax
  UFG::qPropertySet *v67; // rbx
  UFG::StoreFront::EquippedItemResolution *v68; // r14
  int v69; // r9d
  UFG::StoreFront::EquippedItemResolution *v70; // rbx
  UFG::StoreFront::EquippedItemResolution *v71; // r11
  __int64 v72; // rdi
  int v73; // ecx
  unsigned int mExcludedByCount; // edx
  unsigned int v75; // r10d
  unsigned int *p_mExcludedByCount; // rdx
  int v77; // ecx
  unsigned int v78; // r12d
  UFG::qPropertySet **v79; // r14
  __int64 v80; // r13
  UFG::qPropertySet *v81; // rdi
  UFG::qSymbol *v82; // rax
  int v83; // eax
  __int64 v84; // rsi
  __int64 v85; // rbx
  __int64 v86; // r15
  UFG::GameStatTracker *v87; // rcx
  int *v88; // rax
  int v89; // ebx
  unsigned int mUID; // eax
  UFG::GameStatTracker *v91; // rcx
  int *v92; // rax
  int v93; // ebx
  unsigned int v94; // edx
  UFG::GameStatTracker *v95; // rbx
  UFG::GameStatTracker *v96; // rcx
  int v97; // eax
  int v98; // [rsp+30h] [rbp-69h]
  UFG::GameStat::IDStat equipmentType; // [rsp+34h] [rbp-65h]
  int EntityComponentIndex; // [rsp+38h] [rbp-61h]
  unsigned int mNumParts; // [rsp+3Ch] [rbp-5Dh]
  UFG::StreamedResourceComponent *pSrc; // [rsp+40h] [rbp-59h]
  UFG::qArray<UFG::StoreFront::EquippedItemResolution,0> resolvedEquipment; // [rsp+48h] [rbp-51h] BYREF
  UFG::SimObject *pPlayer; // [rsp+58h] [rbp-41h]
  int v105; // [rsp+60h] [rbp-39h]
  UFG::qSymbol result; // [rsp+64h] [rbp-35h] BYREF
  int v107[3]; // [rsp+68h] [rbp-31h] BYREF
  __int64 v108; // [rsp+74h] [rbp-25h]
  int v109; // [rsp+7Ch] [rbp-1Dh]
  int v110; // [rsp+80h] [rbp-19h]
  int v111; // [rsp+84h] [rbp-15h]
  int v112; // [rsp+88h] [rbp-11h]
  __int64 v113; // [rsp+90h] [rbp-9h]

  v113 = -2i64;
  v6 = bRemoveAnyPredefinedOutfit;
  LocalPlayer = UFG::GetLocalPlayer();
  pPlayer = LocalPlayer;
  UFG::MeshResourceLoader::Unload(&UFG::StoreMeshHelper::sMeshLoader);
  UFG::StoreMeshHelper::sSwapQueued = 0;
  if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
  {
    mPrev = UFG::StoreMeshHelper::sSwapTarget.mPrev;
    mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    UFG::StoreMeshHelper::sSwapTarget.mPrev->mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    mNext->mPrev = mPrev;
    UFG::StoreMeshHelper::sSwapTarget.mPrev = &UFG::StoreMeshHelper::sSwapTarget;
    UFG::StoreMeshHelper::sSwapTarget.mNext = &UFG::StoreMeshHelper::sSwapTarget;
  }
  UFG::StoreMeshHelper::sSwapTarget.m_pPointer = 0i64;
  v11 = PropertyUtils::Get<UFG::qSymbol>(
          pItem,
          (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Category,
          DEPTH_RECURSE);
  v105 = UFG::StoreFront::MapItemCategory(v11);
  v12 = 4;
  v98 = 4;
  equipmentType = CurrentBody;
  switch ( v105 )
  {
    case 0:
      equipmentType = CurrentBody;
      goto LABEL_14;
    case 1:
      v12 = 7;
      equipmentType = CurrentLowerBody;
      goto LABEL_14;
    case 2:
      v12 = 8;
      equipmentType = CurrentFootwear;
      goto LABEL_14;
    case 3:
      v12 = 0;
      equipmentType = CurrentHeadgear;
      goto LABEL_14;
    case 4:
      v12 = 1;
      equipmentType = CurrentHead;
      goto LABEL_14;
    case 6:
      v12 = 2;
      equipmentType = CurrentGlasses;
      goto LABEL_14;
    case 7:
      v12 = 3;
      equipmentType = CurrentNeck;
      goto LABEL_14;
    case 8:
      v12 = 5;
      equipmentType = CurrentLeftWrist;
      goto LABEL_14;
    case 9:
      v12 = 6;
      equipmentType = CurrentRightWrist;
      goto LABEL_14;
    case 10:
      v12 = 10;
      equipmentType = CurrentOutfit;
LABEL_14:
      v98 = v12;
      break;
    default:
      break;
  }
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)LocalPlayer->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)LocalPlayer->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                LocalPlayer,
                                UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)LocalPlayer->m_Components.p[10].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  pSrc = m_pComponent;
  mNumParts = m_pComponent->mMeshLoader.mTrueCrowdInstance.mNumParts;
  resolvedEquipment.p = 0i64;
  *(_QWORD *)&resolvedEquipment.size = 0i64;
  UFG::qArray<UFG::StoreFront::EquippedItemResolution,0>::Reallocate(
    &resolvedEquipment,
    mNumParts,
    "qArray.Reallocate(Constructor)");
  resolvedEquipment.size = mNumParts;
  if ( v12 == 10 )
  {
    EntityComponentIndex = -1;
  }
  else
  {
    v16 = UFG::qPropertySet::Get<UFG::qSymbol>(
            pItem,
            (UFG::qArray<unsigned long,0> *)&qSymbol_ComponentType,
            DEPTH_RECURSE);
    UFG::TrueCrowdDataBase::Instance();
    EntityComponentIndex = UFG::TrueCrowdDefinition::GetEntityComponentIndex(
                             &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
                             m_pComponent->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex,
                             v16);
  }
  UFG::qSymbol::create_from_string(&result, "OutfitDefault");
  v17 = UFG::StoreFrontTracker::Instance();
  UFG::PropertySetHandle::Bind(&v17->mProperties);
  v18 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v17->mProperties.mpPropSet,
          (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
          DEPTH_RECURSE);
  v19 = v18;
  if ( v18 && (mNumElements = v18->mNumElements, v21 = 0, mNumElements) )
  {
    while ( 1 )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v19, 0x1Au, v21);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v23 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v23 = 0i64;
      if ( v23->mName.mUID == result.mUID )
        break;
      if ( ++v21 >= mNumElements )
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
          (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_ClothingItemList,
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
              (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
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
      v34 = UFG::qPropertySet::Get<UFG::qSymbol>(
              v33,
              (UFG::qArray<unsigned long,0> *)&qSymbol_ComponentType,
              DEPTH_RECURSE);
      UFG::TrueCrowdDataBase::Instance();
      m_pComponent = pSrc;
      v35 = UFG::TrueCrowdDefinition::GetEntityComponentIndex(
              &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
              pSrc->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex,
              v34);
      p = resolvedEquipment.p;
      resolvedEquipment.p[v35].mDefaultItem = v33;
      ++v25;
    }
    while ( v25 < v24->mNumElements );
    v6 = bRemoveAnyPredefinedOutfit;
  }
  else
  {
    p = resolvedEquipment.p;
  }
  v37 = bPreviewing;
  v38 = v98;
  if ( v98 != ItemCategory_OUTFIT )
  {
    UFG::StoreFront::ResolveItemEquip(pItem, pPlayer, m_pComponent, &resolvedEquipment);
    if ( !bPreviewing && v6 && UFG::StoreFront::IsWeiWearingAnPrefinedOutfit() )
    {
      v48 = 0;
      if ( mNumParts )
      {
        p_mDefaultItem = &p->mDefaultItem;
        do
        {
          if ( v48 != EntityComponentIndex )
          {
            v50 = PropertyUtils::Get<UFG::qSymbol>(
                    *p_mDefaultItem,
                    (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Category,
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
            v52 = *p_mDefaultItem;
            if ( (_S12_6 & 1) == 0 )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            }
            v53 = &sGameStatTracker;
            if ( UFG::GameStatTracker::mspInstance )
              v53 = UFG::GameStatTracker::mspInstance;
            UFG::GameStatTracker::mspInstance = v53;
            if ( (*((_BYTE *)v53 + 6216) & 1) == 0 )
              v53->mpSnapshots[0]->mIDs[v51].mValue.mUID = v52->mName.mUID;
          }
          ++v48;
          p_mDefaultItem += 20;
        }
        while ( v48 < mNumParts );
      }
      UFG::StoreFrontTracker::Instance()->mClothingFashionValue[10] = 0;
      v54 = _S12_6;
      if ( (_S12_6 & 1) == 0 )
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
      if ( (*((_BYTE *)v55 + 6216) & 1) == 0 )
      {
        v55->mpSnapshots[0]->mIDs[21].mValue = UFG::gNullQSymbol;
        v55 = UFG::GameStatTracker::mspInstance;
      }
      if ( (v54 & 1) == 0 )
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
      if ( (*((_BYTE *)v56 + 6216) & 1) != 0 )
      {
LABEL_104:
        v107[0] = 3;
        v107[1] = 4;
        v107[2] = 6;
        v108 = 7i64;
        v109 = 8;
        v57 = 9i64;
        v110 = 9;
        v111 = 1;
        v112 = 2;
        v58 = v107;
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
          if ( (v54 & 1) == 0 )
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
          v61 = (__int64)v60->mpSnapshots[0] + 4 * v59;
          if ( *(_DWORD *)(v61 + 480) != -1 )
          {
            if ( (_S8_13 & 1) == 0 )
            {
              _S8_13 |= 1u;
              UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
              UFG::StoreFront::StoreFront(&stru_142408290, StoreType_None, InventoryType_None, 0i64, 0i64);
              dword_1424083B8 = 0;
              UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
              atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
            }
            UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
            UFG::PropertySetHandle::Bind(&sStoreFrontTracker.mProperties);
            v62 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                    qword_142408288,
                    (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
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
            PropertyUtils::Get<UFG::qSymbol>(
              v67,
              (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Category,
              DEPTH_RECURSE);
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
          pItem,
          (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_ClothingItemList,
          DEPTH_RECURSE);
  v40 = 0;
  if ( v39->mNumElements )
  {
    do
    {
      v41 = UFG::qPropertyList::Get<UFG::qSymbol>(v39, v40);
      if ( (_S8_13 & 1) == 0 )
      {
        _S8_13 |= 1u;
        UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
        UFG::StoreFront::StoreFront(&stru_142408290, StoreType_None, InventoryType_None, 0i64, 0i64);
        dword_1424083B8 = 0;
        UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
        atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
      }
      UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
      UFG::PropertySetHandle::Bind(&sStoreFrontTracker.mProperties);
      v42 = UFG::qPropertySet::Get<UFG::qPropertyList>(
              qword_142408288,
              (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
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
    v38 = v98;
    v37 = bPreviewing;
  }
  if ( !v37 || v38 == 10 )
  {
    v68 = resolvedEquipment.p;
  }
  else
  {
    v68 = resolvedEquipment.p;
    if ( mNumParts )
    {
      v69 = EntityComponentIndex;
      v70 = &resolvedEquipment.p[EntityComponentIndex];
      v71 = resolvedEquipment.p;
      v72 = mNumParts;
      do
      {
        v73 = 0;
        mExcludedByCount = v70->mExcludedByCount;
        if ( mExcludedByCount )
        {
          while ( v70->mExcludedBy[v73] != v71->mItem )
          {
            if ( ++v73 >= mExcludedByCount )
              goto LABEL_153;
          }
          v75 = 0;
          p_mExcludedByCount = &v68->mExcludedByCount;
          do
          {
            if ( v69 == v75 )
            {
              *((_BYTE *)p_mExcludedByCount - 152) = 0;
            }
            else
            {
              v77 = 0;
              if ( *p_mExcludedByCount )
              {
                while ( *(UFG::qPropertySet **)&p_mExcludedByCount[2 * v77 - 32] != v71->mItem )
                {
                  if ( ++v77 >= *p_mExcludedByCount )
                    goto LABEL_150;
                }
                *((_WORD *)p_mExcludedByCount - 76) = 0;
                *((_QWORD *)p_mExcludedByCount - 18) = 0i64;
LABEL_150:
                v69 = EntityComponentIndex;
              }
            }
            ++v75;
            p_mExcludedByCount += 40;
          }
          while ( v75 < mNumParts );
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
  v78 = 0;
  if ( mNumParts )
  {
    v79 = &v68->mDefaultItem;
    v80 = 0i64;
    do
    {
      v81 = *(v79 - 1);
      if ( !v81 )
        v81 = *v79;
      v82 = PropertyUtils::Get<UFG::qSymbol>(
              v81,
              (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Category,
              DEPTH_RECURSE);
      v83 = UFG::StoreFront::MapItemCategory(v82);
      v84 = v83;
      v85 = 15i64;
      v86 = 4i64;
      switch ( v83 )
      {
        case 1:
          v85 = 18i64;
          v86 = 7i64;
          break;
        case 2:
          v85 = 19i64;
          v86 = 8i64;
          break;
        case 3:
          v86 = 0i64;
          v85 = 11i64;
          break;
        case 4:
          v85 = 12i64;
          v86 = 1i64;
          break;
        case 6:
          v85 = 13i64;
          v86 = 2i64;
          break;
        case 7:
          v85 = CurrentNeck;
          v86 = Neck;
          break;
        case 8:
          v85 = 16i64;
          v86 = 5i64;
          break;
        case 9:
          v85 = 17i64;
          v86 = 6i64;
          break;
        case 10:
          v85 = 21i64;
          v86 = 10i64;
          break;
        default:
          break;
      }
      PropertyUtils::Get<UFG::qSymbol>(v81, (UFG::qArray<unsigned long,0> *)&qSymbol_ComponentType, DEPTH_RECURSE);
      if ( *((_BYTE *)v79 - 15) )
      {
        if ( (_S12_6 & 1) == 0 )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        v87 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v87 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v87;
        if ( (*((_BYTE *)v87 + 6216) & 1) == 0 )
          v87->mpSnapshots[0]->mIDs[v85].mValue.mUID = v81->mName.mUID;
      }
      v88 = UFG::qPropertySet::Get<long>(
              v81,
              (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_FashionValue,
              DEPTH_RECURSE);
      if ( v88 )
        v89 = *v88;
      else
        v89 = 0;
      if ( (_S8_13 & 1) == 0 )
      {
        _S8_13 |= 1u;
        UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
        UFG::StoreFront::StoreFront(&stru_142408290, StoreType_None, InventoryType_None, 0i64, 0i64);
        dword_1424083B8 = 0;
        UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
        atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
      }
      UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
      sStoreFrontTracker.mClothingFashionValue[v84] = v89;
      if ( *((_BYTE *)v79 - 16) )
      {
        if ( v78 != -1 )
        {
          mUID = UFG::gNullQSymbol.mUID;
          UFG::StoreMeshHelper::sModelPaths[v80] = UFG::gNullQSymbol;
          UFG::StoreMeshHelper::sTextureSetPaths[v80].mUID = mUID;
          UFG::StoreMeshHelper::sColourTintIndices[v80] = 0;
        }
      }
      else
      {
        UFG::StoreMeshHelper::CommitResource((UFG::SimObjectGame *)pPlayer, v81);
      }
      if ( bSaveToStats )
      {
        if ( (_S12_6 & 1) == 0 )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        v91 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v91 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v91;
        if ( (*((_BYTE *)v91 + 6216) & 1) == 0 )
          v91->mpSnapshots[0]->mIDs[v86].mValue.mUID = v81->mName.mUID;
      }
      v37 = bPreviewing;
      if ( !bPreviewing )
        UFG::StoreFront::ProcessClothingSetBonuses(equipmentType);
      ++v78;
      v79 += 20;
      ++v80;
    }
    while ( v78 < mNumParts );
  }
  if ( v98 == 10 )
  {
    v92 = UFG::qPropertySet::Get<long>(
            pItem,
            (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_FashionValue,
            DEPTH_RECURSE);
    if ( v92 )
      v93 = *v92;
    else
      v93 = 0;
    if ( (_S8_13 & 1) == 0 )
    {
      _S8_13 |= 1u;
      UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
      UFG::StoreFront::StoreFront(&stru_142408290, StoreType_None, InventoryType_None, 0i64, 0i64);
      dword_1424083B8 = 0;
      UFG::qMemSet(&unk_1424083BC, 0, 0x38u);
      atexit(UFG::StoreFrontTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sStoreFrontTracker__);
    }
    UFG::StoreFrontTracker::mspInstance = &sStoreFrontTracker;
    dword_1424083E4 = v93;
    v94 = _S12_6;
    if ( (_S12_6 & 1) != 0 )
    {
      v95 = &sGameStatTracker;
    }
    else
    {
      _S12_6 |= 1u;
      v95 = &sGameStatTracker;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      v94 = _S12_6;
    }
    v96 = &sGameStatTracker;
    if ( UFG::GameStatTracker::mspInstance )
      v96 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v96;
    if ( (*((_BYTE *)v96 + 6216) & 1) == 0 )
    {
      v96->mpSnapshots[0]->mIDs[21].mValue.mUID = pItem->mName.mUID;
      v96 = UFG::GameStatTracker::mspInstance;
    }
    if ( bSaveToStats )
    {
      if ( (v94 & 1) == 0 )
      {
        _S12_6 = v94 | 1;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        v96 = UFG::GameStatTracker::mspInstance;
      }
      if ( v96 )
        v95 = v96;
      UFG::GameStatTracker::mspInstance = v95;
      if ( (*((_BYTE *)v95 + 6216) & 1) == 0 )
        v95->mpSnapshots[0]->mIDs[10].mValue.mUID = pItem->mName.mUID;
    }
    if ( !v37 )
      UFG::StoreFront::ProcessClothingSetBonuses(CurrentOutfit);
  }
  v97 = UFG::StoreFront::mLastEquipedItemCategory;
  if ( bUpdateLastEquipItem )
    v97 = v105;
  UFG::StoreFront::mLastEquipedItemCategory = v97;
  if ( bRefreshPlayer )
    UFG::StoreMeshHelper::QueueSwapping(pPlayer);
  if ( resolvedEquipment.p )
    operator delete[](resolvedEquipment.p);
}:QueueSwapping(pPlayer);
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
  unsigned int mNumElements; // edi
  unsigned int v4; // ebx
  char *ValuePtr; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r13
  signed int v9; // r15d
  signed int i; // ebp
  UFG::qSymbol *v11; // r14
  UFG::StoreFrontTracker *v12; // rbx
  UFG::qPropertyList *v13; // rax
  UFG::qPropertyList *v14; // rsi
  unsigned int v15; // edi
  unsigned int v16; // ebx
  char *v17; // rax
  UFG::qPropertySet *v18; // rcx
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string(&result, "OutfitDefault");
  v0 = UFG::StoreFrontTracker::Instance();
  UFG::PropertySetHandle::Bind(&v0->mProperties);
  v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v0->mProperties.mpPropSet,
         (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
         DEPTH_RECURSE);
  v2 = v1;
  if ( v1 )
  {
    mNumElements = v1->mNumElements;
    v4 = 0;
    if ( mNumElements )
    {
      while ( 1 )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v2, 0x1Au, v4);
        if ( ValuePtr && *(_QWORD *)ValuePtr )
          v6 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
        else
          v6 = 0i64;
        if ( v6->mName.mUID == result.mUID )
          break;
        if ( ++v4 >= mNumElements )
          return;
      }
      v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             v6,
             (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_ClothingItemList,
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
                  (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
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
  UFG::qPropertySet *ItemSlow; // rbx
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
  int v14; // r8d
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

  if ( (unsigned int)(equipmentType - 18) > 1 && equipmentType != CurrentBody )
  {
    switch ( equipmentType )
    {
      case CurrentOutfit:
        v1 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v2 = UFG::StoreFrontTracker::Instance();
        ItemSlow = UFG::StoreFrontTracker::FindItemSlow(v2, &v1->mIDs[21].mValue);
        if ( ItemSlow )
        {
          v4 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v4, ClothingSetBuff, 0);
          v5 = PropertyUtils::Get<UFG::qSymbol>(
                 ItemSlow,
                 (UFG::qArray<unsigned long,0> *)&SimSym_ClothingSetBuff,
                 DEPTH_RECURSE);
          if ( v5 )
          {
            v6 = (unsigned int)UFG::StoreFront::LookupClothingBuff(v5);
            UFG::StoreFront::SetClothingSetBuff(v6);
          }
        }
        return;
      case CurrentHeadgear:
        v7 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v7, ClothingBuffHat, 0);
        v8 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v9 = UFG::StoreFrontTracker::Instance();
        v10 = UFG::StoreFrontTracker::FindItemSlow(v9, &v8->mIDs[11].mValue);
        if ( !v10 )
          return;
        v11 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v10,
                (UFG::qArray<unsigned long,0> *)&SimSym_ClothingItemBuff,
                DEPTH_RECURSE);
        if ( !v11 )
          return;
        v12 = UFG::StoreFront::LookupClothingBuff(v11);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v12;
        v15 = ClothingBuffHat;
        break;
      case CurrentNeck:
        v16 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v16, ClothingBuffNeck, 0);
        v17 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v18 = UFG::StoreFrontTracker::Instance();
        v19 = UFG::StoreFrontTracker::FindItemSlow(v18, &v17->mIDs[14].mValue);
        if ( !v19 )
          return;
        v20 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v19,
                (UFG::qArray<unsigned long,0> *)&SimSym_ClothingItemBuff,
                DEPTH_RECURSE);
        if ( !v20 )
          return;
        v21 = UFG::StoreFront::LookupClothingBuff(v20);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v21;
        v15 = ClothingBuffNeck;
        break;
      case CurrentGlasses:
        v22 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v22, ClothingBuffGlasses, 0);
        v23 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v24 = UFG::StoreFrontTracker::Instance();
        v25 = UFG::StoreFrontTracker::FindItemSlow(v24, &v23->mIDs[13].mValue);
        if ( !v25 )
          return;
        v26 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v25,
                (UFG::qArray<unsigned long,0> *)&SimSym_ClothingItemBuff,
                DEPTH_RECURSE);
        if ( !v26 )
          return;
        v27 = UFG::StoreFront::LookupClothingBuff(v26);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v27;
        v15 = ClothingBuffGlasses;
        break;
      case CurrentLeftWrist:
        v28 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v28, ClothingBuffLeftWrist, 0);
        v29 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v30 = UFG::StoreFrontTracker::Instance();
        v31 = UFG::StoreFrontTracker::FindItemSlow(v30, &v29->mIDs[16].mValue);
        if ( !v31 )
          return;
        v32 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v31,
                (UFG::qArray<unsigned long,0> *)&SimSym_ClothingItemBuff,
                DEPTH_RECURSE);
        if ( !v32 )
          return;
        v33 = UFG::StoreFront::LookupClothingBuff(v32);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v33;
        v15 = ClothingBuffLeftWrist;
        break;
      case CurrentRightWrist:
        v34 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v34, ClothingBuffRightWrist, 0);
        v35 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
        v36 = UFG::StoreFrontTracker::Instance();
        v37 = UFG::StoreFrontTracker::FindItemSlow(v36, &v35->mIDs[17].mValue);
        if ( !v37 )
          return;
        v38 = UFG::qPropertySet::Get<UFG::qSymbol>(
                v37,
                (UFG::qArray<unsigned long,0> *)&SimSym_ClothingItemBuff,
                DEPTH_RECURSE);
        if ( !v38 )
          return;
        v39 = UFG::StoreFront::LookupClothingBuff(v38);
        v13 = UFG::GameStatTracker::Instance();
        v14 = v39;
        v15 = ClothingBuffRightWrist;
        break;
      default:
        return;
    }
LABEL_50:
    UFG::GameStatTracker::SetStat(v13, v15, v14);
    return;
  }
  v40 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  if ( (_S12_6 & 1) == 0 )
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
  if ( (_S12_6 & 1) == 0 )
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
        v53 = PropertyUtils::Get<UFG::qSymbol>(
                v44,
                (UFG::qArray<unsigned long,0> *)&SimSym_ClothingSetBuff,
                DEPTH_RECURSE);
        v54 = PropertyUtils::Get<UFG::qSymbol>(
                v48,
                (UFG::qArray<unsigned long,0> *)&SimSym_ClothingSetBuff,
                DEPTH_RECURSE);
        v55 = PropertyUtils::Get<UFG::qSymbol>(
                v52,
                (UFG::qArray<unsigned long,0> *)&SimSym_ClothingSetBuff,
                DEPTH_RECURSE);
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
              v15 = ClothingSetBuff;
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
void __fastcall UFG::StoreFront::SetClothingSetBuff(int buffType)
{
  UFG::GameStatTracker *v2; // rax
  UFG::qSymbol mapid; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_mapid; // [rsp+48h] [rbp+10h]

  if ( buffType > 0 && (buffType <= 25 || (unsigned int)(buffType - 30) <= 0x34) )
  {
    v2 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v2 + 6216) & 1) == 0 )
    {
      v2->mpSnapshots[0]->mInts[37].mValue = buffType;
      p_mapid = &mapid;
      mapid.mUID = UFG::gNullQSymbol.mUID;
      UFG::GameStatAction::PostStat::Achieve(PDT_INT, ClothingSetBuff, &mapid.mUID);
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
    if ( (__int64)v2 >= (__int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_CAMERA )
      return 0i64;
  }
  return v1;
}

// File Line: 1461
// RVA: 0x4B0BE0
UFG::qSymbol *__fastcall UFG::StoreFront::LookupClothingBuffSymbol(UFG::qSymbol *result, UFG::eClothingBuffEnum eBuff)
{
  result->mUID = (unsigned int)UFG::ClothingBuffEnumSymbols[eBuff];
  return result;
}

// File Line: 1468
// RVA: 0x4A1F60
UFG::qSymbol *__fastcall UFG::StoreFront::GetClothingBuffFromItem(
        UFG::StoreFront *this,
        UFG::qSymbol *result,
        UFG::qPropertySet *pItem)
{
  UFG::qSymbol *v4; // rax

  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pItem,
         (UFG::qArray<unsigned long,0> *)&SimSym_ClothingSetBuff,
         DEPTH_RECURSE);
  if ( v4 )
    result->mUID = v4->mUID;
  else
    result->mUID = -1;
  return result;
}

// File Line: 1480
// RVA: 0x4A42D0
UFG::qSymbol *__fastcall UFG::StoreFront::GetItemBuffFromItem(
        UFG::StoreFront *this,
        UFG::qSymbol *result,
        UFG::qPropertySet *pItem)
{
  UFG::qSymbol *v4; // rax

  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pItem,
         (UFG::qArray<unsigned long,0> *)&SimSym_ClothingItemBuff,
         DEPTH_RECURSE);
  if ( v4 )
    result->mUID = v4->mUID;
  else
    result->mUID = -1;
  return result;
}

// File Line: 1493
// RVA: 0x4ACB80
bool __fastcall UFG::StoreFront::IsOwned(UFG::StoreFront *this, int filterIndex)
{
  UFG::qPropertySet *Item; // rax

  Item = UFG::StoreFront::GetItem(this, filterIndex);
  return UFG::StoreFront::IsOwned(this, Item);
}

// File Line: 1506
// RVA: 0x4ACAF0
bool __fastcall UFG::StoreFront::IsOwned(UFG::StoreFront *this, UFG::qPropertySet *pItem)
{
  __int64 mInventoryType; // rsi
  UFG::GameStatTracker *v4; // rbx

  mInventoryType = this->mInventoryType;
  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  return UFG::PersistentData::MapBool::GetStatus(v4->mpSnapshots[0]->mpMapBools[mInventoryType], &pItem->mName);
}

// File Line: 1515
// RVA: 0x4ABBD0
char __fastcall UFG::StoreFront::IsClothingSetItemOwned(
        UFG::StoreFront *this,
        UFG::StoreFront::ItemCategory eItemSearchCategory,
        _DWORD *itemClothingSet)
{
  __int64 mInventoryType; // rdi
  UFG::GameStatTracker *v5; // rbx
  UFG::PersistentData::MapFloat *mList; // r12
  unsigned int i; // r14d
  unsigned int size; // edx
  bool v9; // cf
  UFG::qSymbol *v10; // rdx
  unsigned int mUID; // ebx
  UFG::StoreFrontTracker *v12; // rdi
  UFG::qPropertyList *v13; // rax
  UFG::qPropertyList *v14; // r15
  unsigned int mNumElements; // ebp
  unsigned int v16; // esi
  char *ValuePtr; // rax
  UFG::qPropertySet *v18; // rdi
  UFG::qSymbol *v19; // rax
  int v20; // eax
  UFG::qSymbol *ClothingBuffFromItem; // rax
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-50h] BYREF
  UFG::qSymbol v24; // [rsp+80h] [rbp+8h] BYREF
  UFG::StoreFront::ItemCategory v25; // [rsp+88h] [rbp+10h]
  _DWORD *v26; // [rsp+90h] [rbp+18h]

  v26 = itemClothingSet;
  v25 = eItemSearchCategory;
  mInventoryType = this->mInventoryType;
  v5 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  UFG::PersistentData::MapInt::GetIterator(
    (UFG::PersistentData::MapFloat *)v5->mpSnapshots[0]->mpMapBools[mInventoryType],
    &result);
  mList = result.mList;
  for ( i = result.mIndex; ; ++i )
  {
    size = mList->mValues.size;
    if ( mList->mValues.size )
    {
      if ( size - 1 > 1 )
        return 0;
      v9 = i < mList[1].mValues.size;
    }
    else
    {
      v9 = i < LODWORD(mList->mValues.p);
    }
    if ( !v9 )
      break;
    if ( size )
    {
      if ( size != 1 )
        continue;
    }
    else if ( !*(_BYTE *)(*(_QWORD *)&mList->mPersistentDataType + 8i64 * i + 4) )
    {
      continue;
    }
    if ( size )
    {
      if ( size - 1 > 1 )
        v10 = &UFG::gNullQSymbol;
      else
        v10 = (UFG::qSymbol *)mList[1].mValues.p + i;
    }
    else
    {
      v10 = (UFG::qSymbol *)(*(_QWORD *)&mList->mPersistentDataType + 8i64 * i);
    }
    mUID = v10->mUID;
    v12 = UFG::StoreFrontTracker::Instance();
    UFG::PropertySetHandle::Bind(&v12->mProperties);
    v13 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            v12->mProperties.mpPropSet,
            (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
            DEPTH_RECURSE);
    v14 = v13;
    if ( v13 )
    {
      mNumElements = v13->mNumElements;
      v16 = 0;
      if ( mNumElements )
      {
        while ( 1 )
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v14, 0x1Au, v16);
          if ( ValuePtr && *(_QWORD *)ValuePtr )
            v18 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
          else
            v18 = 0i64;
          if ( v18->mName.mUID == mUID )
            break;
          if ( ++v16 >= mNumElements )
            goto LABEL_31;
        }
        v19 = PropertyUtils::Get<UFG::qSymbol>(
                v18,
                (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Category,
                DEPTH_RECURSE);
        v20 = UFG::StoreFront::MapItemCategory(v19);
        if ( v20 == v25 )
        {
          ClothingBuffFromItem = UFG::StoreFront::GetClothingBuffFromItem(this, &v24, v18);
          if ( ClothingBuffFromItem->mUID == *v26 )
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
  UFG::SimObjectCharacter *LocalPlayer; // rbx
  UFG::qSymbol *v1; // rax
  UFG::qPropertySet *PropertySet; // rsi
  UFG::GameStatTracker *v3; // rdi
  UFG::GameStat::IDStat *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF

  LocalPlayer = UFG::GetLocalPlayer();
  v1 = UFG::qSymbol::create_from_string(&result, UFG::StoreFront_SaveGameDefaults);
  PropertySet = UFG::PropertySetManager::GetPropertySet(v1);
  if ( LocalPlayer )
  {
    v3 = UFG::GameStatTracker::Instance();
    if ( (_S19_1 & 1) == 0 )
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
        v5 = PropertyUtils::Get<UFG::qSymbol>(
               PropertySet,
               (UFG::qArray<unsigned long,0> *)IDSymbols[*(int *)v4],
               DEPTH_RECURSE);
        if ( v5 )
        {
          if ( v5->mUID == v3->mpSnapshots[0]->mIDs[*(int *)v4].mValue.mUID )
            break;
        }
        if ( (__int64)++v4 >= (__int64)"default-unlockables-merchantdatabase-clothing" )
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
  if ( (_S8_13 & 1) == 0 )
  {
    _S8_13 |= 1u;
    UFG::PropertySetHandle::PropertySetHandle(&sStoreFrontTracker.mProperties);
    UFG::StoreFront::StoreFront(&stru_142408290, StoreType_None, InventoryType_None, 0i64, 0i64);
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
  unsigned int mUID; // eax
  unsigned int v2; // ecx
  __int64 v3; // rdx

  mUID = UFG::gNullQSymbol.mUID;
  v2 = 0;
  v3 = 0i64;
  do
  {
    UFG::StoreMeshHelper::sModelPaths[v3].mUID = mUID;
    UFG::StoreMeshHelper::sTextureSetPaths[v3].mUID = mUID;
    UFG::StoreMeshHelper::sColourTintIndices[v3] = 0;
    ++v2;
    ++v3;
  }
  while ( v2 < 0x10 );
}

// File Line: 1632
// RVA: 0x4AF140
void __fastcall UFG::StoreFrontTracker::LoadStoreData(
        UFG::StoreFrontTracker *this,
        UFG::StoreFront::InventoryType inventoryType)
{
  int v3; // edx
  int v4; // edx
  const char *v5; // rdx
  char *p_result; // rcx
  UFG::qSymbol *v7; // rax
  char v8; // [rsp+38h] [rbp+10h] BYREF
  char v9; // [rsp+40h] [rbp+18h] BYREF
  UFG::qSymbol result; // [rsp+48h] [rbp+20h] BYREF

  v3 = inventoryType - 0x3D;
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      if ( v4 != 1 )
        return;
      v5 = "Boat";
      p_result = &v8;
    }
    else
    {
      v5 = "Vehicle";
      p_result = &v9;
    }
  }
  else
  {
    v5 = "Clothing";
    p_result = (char *)&result;
  }
  v7 = UFG::qSymbol::create_from_string((UFG::qSymbol *)p_result, v5);
  UFG::StoreFrontTracker::LoadStoreData(this, v7);
}

// File Line: 1652
// RVA: 0x4AEFF0
void __fastcall UFG::StoreFrontTracker::LoadStoreData(UFG::StoreFrontTracker *this, UFG::qSymbol *inventoryType)
{
  unsigned int mUID; // eax
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol v12; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol v13; // [rsp+50h] [rbp+18h] BYREF

  UFG::PropertySetHandle::Null(&this->mProperties);
  this->mInventoryType = InventoryType_None;
  UFG::StoreFront::SetData(&this->mCurrentStore, StoreType_None, InventoryType_None, 0i64, 0i64);
  UFG::PropertySetHandle::Null(&this->mProperties);
  mUID = inventoryType->mUID;
  if ( inventoryType->mUID == 0x9773EC16 )
  {
    v9 = UFG::qSymbol::create_from_string(&v13, "default-unlockables-merchantdatabase-clothing");
    PropertySet = UFG::PropertySetManager::GetPropertySet(v9);
    UFG::PropertySetHandle::SetPropSet(&this->mProperties, PropertySet);
    UFG::PropertySetHandle::Bind(&this->mProperties);
    UFG::qPropertySet::Get<UFG::qPropertyList>(
      this->mProperties.mpPropSet,
      (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
      DEPTH_RECURSE);
    this->mInventoryType = InventoryType_Clothing;
  }
  else if ( mUID == 0x9B06086B )
  {
    v7 = UFG::qSymbol::create_from_string(&v12, "default-unlockables-merchantdatabase-vehicles");
    v8 = UFG::PropertySetManager::GetPropertySet(v7);
    UFG::PropertySetHandle::SetPropSet(&this->mProperties, v8);
    UFG::PropertySetHandle::Bind(&this->mProperties);
    UFG::qPropertySet::Get<UFG::qPropertyList>(
      this->mProperties.mpPropSet,
      (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
      DEPTH_RECURSE);
    this->mInventoryType = InventoryType_Vehicle;
  }
  else if ( mUID == 0xACB107F7 )
  {
    v5 = UFG::qSymbol::create_from_string(&result, "default-unlockables-merchantdatabase-boats");
    v6 = UFG::PropertySetManager::GetPropertySet(v5);
    UFG::PropertySetHandle::SetPropSet(&this->mProperties, v6);
    this->mInventoryType = InventoryType_Boat;
  }
}

// File Line: 1681
// RVA: 0x4C3EE0
void __fastcall UFG::StoreFrontTracker::UnloadStoreData(UFG::StoreFrontTracker *this)
{
  UFG::PropertySetHandle::Null(&this->mProperties);
  this->mInventoryType = InventoryType_None;
  UFG::StoreFront::SetData(&this->mCurrentStore, StoreType_None, InventoryType_None, 0i64, 0i64);
}

// File Line: 1689
// RVA: 0x4A0810
char __fastcall UFG::StoreFrontTracker::FindStore(
        UFG::StoreFrontTracker *this,
        UFG::qPropertySet *pStoreParameters,
        UFG::qSymbol *storeName,
        UFG::StoreFront *pResult,
        UFG::StoreFront::StoreType eStoreType)
{
  UFG::qPropertyList *v9; // rax
  char *v10; // r14
  UFG::qPropertyList *v11; // rbp
  unsigned int mNumElements; // esi
  unsigned int v13; // ebx
  UFG::StoreFront::InventoryType mInventoryType; // r13d
  unsigned int mUID; // ebx
  char *v17; // r12
  UFG::qSymbol *v18; // rax
  char *v19; // rax
  const char *v20; // rsi
  UFG::qPropertySet *mpPropSet; // [rsp+70h] [rbp+8h]

  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = this->mProperties.mpPropSet;
  v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         mpPropSet,
         (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Stores,
         DEPTH_RECURSE);
  v10 = 0i64;
  v11 = v9;
  if ( v9 && (mNumElements = v9->mNumElements, v13 = 0, mNumElements) )
  {
    while ( storeName->mUID != UFG::qPropertyList::Get<UFG::qSymbol>(v11, v13)->mUID )
    {
      if ( ++v13 >= mNumElements )
        goto LABEL_5;
    }
    mInventoryType = this->mInventoryType;
    pResult->mpStoreParameters = pStoreParameters;
    mUID = UFG::gNullQSymbol.mUID;
    v17 = 0i64;
    if ( ((eStoreType - 1) & 0xFFFFFFFD) == 0 )
    {
      mUID = PropertyUtils::Get<UFG::qSymbol>(
               pStoreParameters,
               (UFG::qArray<unsigned long,0> *)&qSymbol_StoreId,
               DEPTH_RECURSE)->mUID;
      v10 = PropertyUtils::Get<char const *>(
              pResult->mpStoreParameters,
              (UFG::qArray<unsigned long,0> *)&qSymbol_StoreTitle,
              DEPTH_RECURSE);
      v17 = PropertyUtils::Get<char const *>(
              pResult->mpStoreParameters,
              (UFG::qArray<unsigned long,0> *)&qSymbol_StoreDesc,
              DEPTH_RECURSE);
    }
    UFG::qSymbol::set_null(&pResult->mItemTypeFilter);
    UFG::qString::Set(&pResult->mItemTierFilter, &customCaption);
    if ( pResult->mpStoreParameters )
    {
      v18 = PropertyUtils::Get<UFG::qSymbol>(
              pResult->mpStoreParameters,
              (UFG::qArray<unsigned long,0> *)&qSymbol_StoreItemFilter,
              DEPTH_RECURSE);
      if ( v18 )
        pResult->mItemTypeFilter = (UFG::qSymbol)v18->mUID;
      v19 = PropertyUtils::Get<char const *>(
              pResult->mpStoreParameters,
              (UFG::qArray<unsigned long,0> *)&qSymbol_StoreTierFilter,
              DEPTH_RECURSE);
      v20 = v19;
      if ( v19 && (int)UFG::qStringLength(v19) > 0 )
        UFG::qString::Set(&pResult->mItemTierFilter, v20);
    }
    pResult->mStoreType = eStoreType;
    pResult->mInventoryType = mInventoryType;
    pResult->mpPropertySet = mpPropSet;
    UFG::qString::Set(&pResult->mStoreTitle, v10);
    UFG::qString::Set(&pResult->mStoreDesc, v17);
    pResult->mStoreName.mUID = mUID;
    if ( eStoreType )
      UFG::StoreFront::BuildCategories(pResult);
    return 1;
  }
  else
  {
LABEL_5:
    UFG::StoreFront::SetData(pResult, StoreType_None, InventoryType_None, 0i64, 0i64);
    return 0;
  }
}

// File Line: 1710
// RVA: 0x4BBE70
void __fastcall UFG::StoreFrontTracker::SetCurrentStore(
        UFG::StoreFrontTracker *this,
        UFG::qPropertySet *pStoreParameters)
{
  UFG::qArray<unsigned long,0> *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+18h] BYREF

  v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "StoreType");
  v5 = PropertyUtils::Get<UFG::qSymbol>(pStoreParameters, v4, DEPTH_RECURSE);
  if ( v5->mUID == StoreFrontSymbol_Storage.mUID )
  {
    UFG::StoreFront::SetData(&this->mCurrentStore, StoreType_Storage, this->mInventoryType, pStoreParameters, 0i64);
  }
  else if ( v5->mUID == StoreFrontSymbol_Race.mUID )
  {
    UFG::StoreFront::SetData(&this->mCurrentStore, StoreType_Race, this->mInventoryType, pStoreParameters, 0i64);
  }
  else
  {
    v6 = PropertyUtils::Get<UFG::qSymbol>(
           pStoreParameters,
           (UFG::qArray<unsigned long,0> *)&qSymbol_StoreId,
           DEPTH_RECURSE);
    UFG::StoreFrontTracker::FindStore(this, pStoreParameters, v6, &this->mCurrentStore, StoreType_Retail);
  }
}

// File Line: 1734
// RVA: 0x4BBF50
void __fastcall UFG::StoreFrontTracker::SetCurrentStore(
        UFG::StoreFrontTracker *this,
        UFG::StoreFront::InventoryType inventorytype,
        unsigned int *storeName,
        const char *pStoreTitle,
        const char *pStoreDesc)
{
  UFG::qPropertySet *mpPropSet; // rax

  UFG::PropertySetHandle::Bind(&this->mProperties);
  mpPropSet = this->mProperties.mpPropSet;
  this->mCurrentStore.mStoreType = StoreType_Retail;
  this->mCurrentStore.mpPropertySet = mpPropSet;
  this->mCurrentStore.mInventoryType = inventorytype;
  UFG::qString::Set(&this->mCurrentStore.mStoreTitle, pStoreTitle);
  UFG::qString::Set(&this->mCurrentStore.mStoreDesc, pStoreDesc);
  this->mCurrentStore.mStoreName.mUID = *storeName;
  UFG::StoreFront::BuildCategories(&this->mCurrentStore);
}

// File Line: 1758
// RVA: 0x4AEBD0
void __fastcall UFG::StoreFrontTracker::LoadMissionItem(
        UFG::StoreFrontTracker *this,
        UFG::qSymbol *itemName,
        bool isPermanent)
{
  UFG::StoreFront::InventoryType mInventoryType; // r15d
  UFG::StoreFront::StoreType mStoreType; // ebp
  UFG::StoreFront::InventoryType v8; // r12d
  UFG::qPropertySet *mpStoreParameters; // r13
  UFG::qSymbol *v10; // rax
  UFG::qPropertySet *ItemSlow; // rax
  char *v12; // rax
  UFG::qPropertySet *pPropertySet; // [rsp+30h] [rbp-48h]
  UFG::PropertySetHandle handle; // [rsp+40h] [rbp-38h] BYREF
  UFG::qSymbol result; // [rsp+98h] [rbp+20h] BYREF

  if ( UFG::GetLocalPlayer() )
  {
    UFG::PropertySetHandle::PropertySetHandle(&handle, &this->mProperties);
    mInventoryType = this->mInventoryType;
    mStoreType = this->mCurrentStore.mStoreType;
    v8 = this->mCurrentStore.mInventoryType;
    mpStoreParameters = this->mCurrentStore.mpStoreParameters;
    pPropertySet = this->mCurrentStore.mpPropertySet;
    v10 = UFG::qSymbol::create_from_string(&result, "Clothing");
    UFG::StoreFrontTracker::LoadStoreData(this, v10);
    ItemSlow = UFG::StoreFrontTracker::FindItemSlow(this, itemName);
    if ( ItemSlow )
    {
      UFG::StoreFront::EquipItem(ItemSlow, isPermanent, 1, 1, 1, 0);
      UFG::StoreFront::CheckAchievement();
      UFG::PropertySetHandle::Null(&this->mProperties);
      this->mInventoryType = InventoryType_None;
      UFG::StoreFront::SetData(&this->mCurrentStore, StoreType_None, InventoryType_None, 0i64, 0i64);
      if ( mStoreType )
      {
        UFG::PropertySetHandle::SetPropSet(&this->mProperties, &handle);
        this->mInventoryType = mInventoryType;
        UFG::StoreFront::SetData(&this->mCurrentStore, mStoreType, v8, mpStoreParameters, pPropertySet);
      }
    }
    else
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)itemName);
      UFG::qPrintf("Cannot find mission item %s.", v12);
    }
    UFG::PropertySetHandle::~PropertySetHandle(&handle);
  }
}

// File Line: 1811
// RVA: 0x492EF0
void __fastcall UFG::StoreFrontTracker::AddItemToInventory(
        UFG::StoreFrontTracker *this,
        UFG::qPropertySet *pItemPropertySet,
        UFG::StoreFront::InventoryType inventoryType,
        bool bApplyFace,
        bool bIsFree)
{
  __int64 v5; // rdi
  UFG::GameStatTracker *v8; // rax
  char *v9; // rax
  const char *v10; // rbx
  UFG::qSymbol *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  unsigned int v13; // ecx
  UFG::GameStatTracker *v14; // rbx
  UFG::GameStatTracker *v15; // r8
  float ItemPriceBasedOnClothes; // xmm0_4
  UFG::SimObject *mpStoreOwner; // rcx
  UFG::qSymbol keyname; // [rsp+40h] [rbp+8h] BYREF

  v5 = inventoryType;
  if ( this->mProperties.mName.mUID != -1 )
  {
    v8 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v8->mpSnapshots[0]->mpMapBools[v5], &pItemPropertySet->mName, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        keyname.mUID = pItemPropertySet->mName.mUID;
        UFG::GameStatAction::PostStat::AchieveMapBool((UFG::GameStat::MapBoolStat)v5, (UFG::qSymbol)&keyname);
      }
    }
    if ( (_DWORD)v5 == 62 )
    {
      v9 = PropertyUtils::Get<char const *>(
             pItemPropertySet,
             (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Tier,
             DEPTH_RECURSE);
      v10 = v9;
      if ( v9 )
      {
        if ( (int)UFG::qStringLength(v9) > 0 )
        {
          v11 = UFG::qSymbol::create_from_string(&keyname, v10);
          v12 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v12 + 6216) & 1) == 0 )
          {
            UFG::PersistentData::MapBool::SetStatus(v12->mpSnapshots[0]->mpMapBools[65], v11, 1);
            if ( UFG::GameStatAction::PostStat::sIsEnabled )
            {
              v13 = _S12_6;
              v14 = &sGameStatTracker;
              if ( (_S12_6 & 1) == 0 )
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
              if ( (v13 & 1) == 0 )
              {
                _S12_6 = v13 | 1;
                UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
                atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
                v15 = UFG::GameStatTracker::mspInstance;
              }
              if ( v15 )
                v14 = v15;
              UFG::GameStatTracker::mspInstance = v14;
            }
          }
        }
      }
    }
    if ( !bIsFree )
    {
      ItemPriceBasedOnClothes = UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(pItemPropertySet);
      if ( this == (UFG::StoreFrontTracker *)-16i64 )
        mpStoreOwner = 0i64;
      else
        mpStoreOwner = this->mCurrentStore.mpStoreOwner;
      UFG::GameStatAction::Money::PurchaseItem(
        mpStoreOwner,
        (UFG::StoreFront::InventoryType)v5,
        (int)ItemPriceBasedOnClothes);
    }
  }
}

// File Line: 1844
// RVA: 0x4B6A50
void __fastcall UFG::StoreFrontTracker::ResetEquipment(UFG::StoreFrontTracker *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // r14
  UFG::qSymbol *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r13
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v9; // rbx
  UFG::qSymbol *p_entityComponentName; // r15
  __int64 v11; // r12
  unsigned int v12; // edx
  UFG::GameStatTracker *v13; // r8
  UFG::qSymbol *v14; // rdi
  UFG::GameStatTracker *v15; // rax
  __int64 v16; // rsi
  UFG::StoreFrontTracker *v17; // rax
  UFG::qPropertySet *ItemSlow; // rdi
  __int64 v19; // rsi
  int *v20; // rax
  int v21; // edi
  unsigned int EntityComponentIndex; // eax
  __int64 v23; // rcx
  unsigned int mUID; // eax
  UFG::GameSnapshot *v25; // rbx
  UFG::StoreFrontTracker *v26; // rax
  UFG::qPropertySet *v27; // rbx
  UFG::GameStatTracker *v28; // rax
  UFG::qSymbol *v29; // rax
  UFG::eClothingBuffEnum v30; // eax
  UFG::qSymbol entityComponentName; // [rsp+30h] [rbp-99h] BYREF
  UFG::qSymbol v32; // [rsp+34h] [rbp-95h] BYREF
  UFG::qSymbol v33; // [rsp+38h] [rbp-91h] BYREF
  UFG::qSymbol v34; // [rsp+3Ch] [rbp-8Dh] BYREF
  UFG::qSymbol v35; // [rsp+40h] [rbp-89h] BYREF
  UFG::qSymbol v36; // [rsp+44h] [rbp-85h] BYREF
  UFG::qSymbol v37; // [rsp+48h] [rbp-81h] BYREF
  UFG::qSymbol v38; // [rsp+4Ch] [rbp-7Dh] BYREF
  UFG::qSymbol v39; // [rsp+50h] [rbp-79h] BYREF
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
  __int128 v51[5]; // [rsp+90h] [rbp-39h]
  int v52; // [rsp+E0h] [rbp+17h]
  int v53; // [rsp+E4h] [rbp+1Bh]
  UFG::qSymbol result; // [rsp+138h] [rbp+6Fh] BYREF

  v50 = -2i64;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    v3 = UFG::qSymbol::create_from_string(&result, "Clothing");
    UFG::StoreFrontTracker::LoadStoreData(this, v3);
    v51[0] = (__int128)_mm_load_si128((const __m128i *)&_xmm);
    v51[1] = (__int128)_mm_load_si128((const __m128i *)&_xmm);
    v51[2] = (__int128)_mm_load_si128((const __m128i *)&_xmm);
    v51[3] = (__int128)_mm_load_si128((const __m128i *)&_xmm);
    v51[4] = (__int128)_mm_load_si128((const __m128i *)&_xmm);
    v52 = 10;
    v53 = 21;
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
      mPrev = UFG::StoreMeshHelper::sSwapTarget.mPrev;
      mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
      UFG::StoreMeshHelper::sSwapTarget.mPrev->mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
      mNext->mPrev = mPrev;
      UFG::StoreMeshHelper::sSwapTarget.mPrev = &UFG::StoreMeshHelper::sSwapTarget;
      UFG::StoreMeshHelper::sSwapTarget.mNext = &UFG::StoreMeshHelper::sSwapTarget;
    }
    UFG::StoreMeshHelper::sSwapTarget.m_pPointer = 0i64;
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = LocalPlayer->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                LocalPlayer,
                                UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = LocalPlayer->m_Components.p[10].m_pComponent;
    }
    v9 = 0i64;
    p_entityComponentName = &entityComponentName;
    v11 = 11i64;
    do
    {
      v12 = _S12_6;
      if ( (_S12_6 & 1) == 0 )
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
      v14 = (UFG::qSymbol *)((char *)v13->mpSnapshots[0] + 4 * *((int *)v51 + 2 * v9));
      if ( (v12 & 1) == 0 )
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
      v16 = *((int *)v51 + 2 * v9 + 1);
      if ( (*((_BYTE *)v15 + 6216) & 1) == 0 )
        v15->mpSnapshots[0]->mIDs[v16].mValue = v14[120];
      v17 = UFG::StoreFrontTracker::Instance();
      ItemSlow = UFG::StoreFrontTracker::FindItemSlow(v17, v14 + 120);
      UFG::StoreFront::ProcessClothingSetBonuses((UFG::GameStat::IDStat)v16);
      v19 = *(&v40 + v9);
      if ( ItemSlow )
      {
        UFG::StoreMeshHelper::CommitResource(LocalPlayer, ItemSlow);
        v20 = UFG::qPropertySet::Get<long>(
                ItemSlow,
                (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_FashionValue,
                DEPTH_RECURSE);
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
          EntityComponentIndex = UFG::TrueCrowdDefinition::GetEntityComponentIndex(
                                   &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
                                   HIDWORD(m_pComponent[4].m_SafePointerList.mNode.mNext[2].mPrev),
                                   p_entityComponentName);
          if ( EntityComponentIndex != -1 )
          {
            v23 = EntityComponentIndex;
            mUID = UFG::gNullQSymbol.mUID;
            UFG::StoreMeshHelper::sModelPaths[v23] = UFG::gNullQSymbol;
            UFG::StoreMeshHelper::sTextureSetPaths[v23].mUID = mUID;
            UFG::StoreMeshHelper::sColourTintIndices[v23] = 0;
          }
        }
        UFG::StoreFrontTracker::Instance()->mClothingFashionValue[v19] = 0;
      }
      ++p_entityComponentName;
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
      v29 = PropertyUtils::Get<UFG::qSymbol>(
              v27,
              (UFG::qArray<unsigned long,0> *)&SimSym_ClothingSetBuff,
              DEPTH_RECURSE);
      if ( v29 )
      {
        v30 = (unsigned int)UFG::StoreFront::LookupClothingBuff(v29);
        UFG::StoreFront::SetClothingSetBuff(v30);
      }
    }
    UFG::StoreMeshHelper::QueueSwapping(LocalPlayer);
    UFG::PropertySetHandle::Null(&this->mProperties);
    this->mInventoryType = InventoryType_None;
    UFG::StoreFront::SetData(&this->mCurrentStore, StoreType_None, InventoryType_None, 0i64, 0i64);
    `eh vector destructor iterator(&entityComponentName, 4ui64, 9, (void (__fastcall *)(void *))_);
  }
}

// File Line: 1945
// RVA: 0x4A04B0
UFG::qPropertySet *__fastcall UFG::StoreFrontTracker::FindClothingSetSlow(
        UFG::StoreFrontTracker *this,
        UFG::qSymbol *clothingSetName)
{
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rsi
  unsigned int mNumElements; // edi
  unsigned int v7; // ebx
  char *ValuePtr; // rax
  char *v9; // rcx

  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         this->mProperties.mpPropSet,
         (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_ClothingSets,
         DEPTH_RECURSE);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  mNumElements = v4->mNumElements;
  v7 = 0;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v7);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v9 = &ValuePtr[*(_QWORD *)ValuePtr];
    else
      v9 = 0i64;
    if ( *((_DWORD *)v9 + 16) == clothingSetName->mUID )
      break;
    if ( ++v7 >= mNumElements )
      return 0i64;
  }
  return (UFG::qPropertySet *)v9;
}

// File Line: 1963
// RVA: 0x4A0690
UFG::qPropertySet *__fastcall UFG::StoreFrontTracker::FindItemSlow(
        UFG::StoreFrontTracker *this,
        UFG::qSymbol *itemName)
{
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rsi
  unsigned int mNumElements; // edi
  unsigned int v7; // ebx
  char *ValuePtr; // rax
  char *v9; // rcx

  UFG::PropertySetHandle::Bind(&this->mProperties);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         this->mProperties.mpPropSet,
         (UFG::qArray<unsigned long,0> *)&StoreFrontSymbol_Items,
         DEPTH_RECURSE);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  mNumElements = v4->mNumElements;
  v7 = 0;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v7);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v9 = &ValuePtr[*(_QWORD *)ValuePtr];
    else
      v9 = 0i64;
    if ( *((_DWORD *)v9 + 0x10) == itemName->mUID )
      break;
    if ( ++v7 >= mNumElements )
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

  v1 = PropertyUtils::Get<float>(
         pItemPropertySet,
         (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Price,
         DEPTH_RECURSE);
  if ( !v1 )
    return 0.0;
  v2 = *v1;
  v3 = v2 - (float)((float)(UFG::StoreFrontTracker::GetDiscount() * v2) * 0.0099999998);
  if ( v3 < 0.0 )
    return 0.0;
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
    return v1;
  return result;
}

// File Line: 2008
// RVA: 0x4A43C0
float __fastcall UFG::StoreFrontTracker::GetItemPriceWithoutDiscount(UFG::qPropertySet *pItemPropertySet)
{
  float *v1; // rax

  v1 = PropertyUtils::Get<float>(
         pItemPropertySet,
         (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Price,
         DEPTH_RECURSE);
  if ( v1 )
    return *v1;
  else
    return 0.0;
}

// File Line: 2019
// RVA: 0x4A2390
float __fastcall UFG::StoreFrontTracker::GetDiscount()
{
  float mValue; // xmm6_4
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // r8
  UFG::GameStatTracker *v4; // rdx

  mValue = 0.0;
  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
    mValue = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[52].mValue;
    v1 = _S12_6;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  if ( (v1 & 1) == 0 )
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
    mValue = mValue + UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[53].mValue;
    v1 = _S12_6;
    v4 = UFG::GameStatTracker::mspInstance;
  }
  if ( (v1 & 1) == 0 )
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
    mValue = mValue + UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[54].mValue;
  }
  else if ( UFG::GameStatTracker::Instance()->mpSnapshots[0]->mInts[37].mValue == 14 )
  {
    mValue = mValue - UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[60].mValue;
  }
  return UFG::StoreFrontTracker::GetDiscountForFaceLevel() + (float)(mValue * 100.0);
}

// File Line: 2046
// RVA: 0x4A25B0
float __fastcall UFG::StoreFrontTracker::GetDiscountForFaceLevel()
{
  UFG::GameStatTracker *v0; // rbx
  UFG::GameStatTracker *v1; // rcx
  signed int FaceLevelFromExperience; // edi
  int m_iMaxFaceLevel; // ecx
  char *ValuePtr; // rax
  UFG::qPropertySet *v5; // rcx
  __m128i v6; // xmm0
  float result; // xmm0_4

  v0 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v1 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v1 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v1;
  FaceLevelFromExperience = UFG::GameStatTracker::GetFaceLevelFromExperience(v1, v1->mpSnapshots[0]->mInts[29].mValue);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v0 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v0;
  m_iMaxFaceLevel = v0->m_iMaxFaceLevel;
  if ( FaceLevelFromExperience >= m_iMaxFaceLevel - 1 )
    FaceLevelFromExperience = m_iMaxFaceLevel - 1;
  if ( FaceLevelFromExperience < 0 || FaceLevelFromExperience >= m_iMaxFaceLevel )
  {
    v6 = _mm_cvtsi32_si128(0xFFFFFFFF);
  }
  else
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v0->mpFaceLevelPropertyList, 0x1Au, FaceLevelFromExperience);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v5 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v5 = 0i64;
    v6 = _mm_cvtsi32_si128(*UFG::qPropertySet::Get<long>(
                              v5,
                              (UFG::qArray<unsigned long,0> *)&GameStatsSymbol_PriceDiscount,
                              DEPTH_RECURSE));
  }
  LODWORD(result) = _mm_cvtepi32_ps(v6).m128_u32[0];
  return result;
}

// File Line: 2059
// RVA: 0x4A1FA0
__int64 __fastcall UFG::StoreFrontTracker::GetClothingFashionValueTotal(UFG::StoreFrontTracker *this)
{
  if ( UFG::StoreFront::IsWeiWearingAnPrefinedOutfit() )
    return (unsigned int)this->mClothingFashionValue[10];
  else
    return (unsigned int)(this->mClothingFashionValue[0]
                        + this->mClothingFashionValue[1]
                        + this->mClothingFashionValue[2]
                        + this->mClothingFashionValue[3]
                        + this->mClothingFashionValue[4]
                        + this->mClothingFashionValue[5]
                        + this->mClothingFashionValue[6]
                        + this->mClothingFashionValue[7]
                        + this->mClothingFashionValue[8]
                        + this->mClothingFashionValue[9]);
}

// File Line: 2075
// RVA: 0x151B560
__int64 dynamic_initializer_for__UFG::StoreMeshHelper::sSwapTarget__()
{
  UFG::StoreMeshHelper::sSwapTarget.m_pPointer = 0i64;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StoreMeshHelper::sSwapTarget__);
}

// File Line: 2076
// RVA: 0x151B500
__int64 dynamic_initializer_for__UFG::StoreMeshHelper::sMeshLoader__()
{
  UFG::MeshResourceLoader::MeshResourceLoader(&UFG::StoreMeshHelper::sMeshLoader);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StoreMeshHelper::sMeshLoader__);
}

// File Line: 2077
// RVA: 0x151B520
__int64 dynamic_initializer_for__UFG::StoreMeshHelper::sModelPaths__()
{
  `eh vector constructor iterator(
    (char *)UFG::StoreMeshHelper::sModelPaths,
    4ui64,
    16,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StoreMeshHelper::sModelPaths__);
}

// File Line: 2078
// RVA: 0x151B590
__int64 dynamic_initializer_for__UFG::StoreMeshHelper::sTextureSetPaths__()
{
  `eh vector constructor iterator(
    (char *)UFG::StoreMeshHelper::sTextureSetPaths,
    4ui64,
    16,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StoreMeshHelper::sTextureSetPaths__);
}

// File Line: 2090
// RVA: 0x4C23F0
_BOOL8 __fastcall UFG::StoreMeshHelper::SwapInProgress()
{
  return UFG::StoreMeshHelper::sSwapQueued;
}

// File Line: 2102
// RVA: 0x499570
void __fastcall UFG::StoreMeshHelper::CommitResource(UFG::SimObjectGame *object, UFG::qPropertySet *pSet)
{
  int v3; // edi
  UFG::SimComponent *m_pComponent; // rbx
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSymbol *v7; // rbp
  unsigned int EntityComponentIndex; // eax
  __int64 v9; // rbx
  int *v10; // rax
  __int64 v11; // rdx
  UFG::qSymbol defaultValue; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol *result; // [rsp+70h] [rbp+18h] BYREF
  UFG::qSymbol *p_defaultValue; // [rsp+78h] [rbp+20h] BYREF

  v3 = 0;
  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = object->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = object->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = object->m_Components.p[10].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  result = &defaultValue;
  defaultValue.mUID = UFG::gNullQSymbol.mUID;
  PropertyUtils::GetWithDefault<UFG::qSymbol>(
    (UFG::qSymbol *)&result,
    pSet,
    (UFG::qArray<unsigned long,0> *)&qSymbol_Model,
    &defaultValue.mUID,
    DEPTH_RECURSE);
  p_defaultValue = &defaultValue;
  defaultValue.mUID = UFG::gNullQSymbol.mUID;
  PropertyUtils::GetWithDefault<UFG::qSymbol>(
    (UFG::qSymbol *)&p_defaultValue,
    pSet,
    (UFG::qArray<unsigned long,0> *)&qSymbol_TextureSet,
    &defaultValue.mUID,
    DEPTH_RECURSE);
  v7 = PropertyUtils::Get<UFG::qSymbol>(pSet, (UFG::qArray<unsigned long,0> *)&qSymbol_ComponentType, DEPTH_RECURSE);
  if ( v7 )
  {
    UFG::TrueCrowdDataBase::Instance();
    EntityComponentIndex = UFG::TrueCrowdDefinition::GetEntityComponentIndex(
                             &UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition,
                             HIDWORD(m_pComponent[4].m_SafePointerList.mNode.mNext[2].mPrev),
                             v7);
    v9 = EntityComponentIndex;
    if ( EntityComponentIndex != -1 )
    {
      v10 = PropertyUtils::Get<long>(pSet, (UFG::qArray<unsigned long,0> *)&qSymbol_ColorTintIndex, DEPTH_RECURSE);
      v11 = v9;
      UFG::StoreMeshHelper::sModelPaths[v11].mUID = (unsigned int)result;
      UFG::StoreMeshHelper::sTextureSetPaths[v11].mUID = (unsigned int)p_defaultValue;
      if ( v10 )
        v3 = *v10;
      UFG::StoreMeshHelper::sColourTintIndices[v11] = v3;
    }
  }
}

// File Line: 2141
// RVA: 0x4B3AC0
void __fastcall UFG::StoreMeshHelper::QueueSwapping(UFG::SimObjectGame *object)
{
  UFG::StreamedResourceComponent *m_pComponent; // rdi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qPropertySet *mpWritableProperties; // rdx
  unsigned int mEntityIndex; // r15d
  unsigned int mComponentCount; // r14d
  unsigned int v12; // edi
  UFG::qSymbol *v13; // rsi
  UFG::qSymbol *v14; // rbp
  UFG::TrueCrowdDataBase *v15; // rax
  UFG::TrueCrowdModel *ModelFromPath; // rax
  UFG::TrueCrowdModel *v17; // rbx
  __int64 v18; // r8
  unsigned int mNumTextureSets; // r10d
  __int64 mOffset; // r9
  __int64 v21; // rcx
  _QWORD *v22; // rdx
  UFG::TrueCrowdResource *v23; // rdx
  __int64 *v24; // rax
  __int64 v25; // rcx
  UFG::qSymbol priority; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol *p_priority; // [rsp+68h] [rbp+10h]

  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)object->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)object->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)object->m_Components.p[10].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  UFG::StoreMeshHelper::sSwapQueued = 1;
  if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
  {
    mPrev = UFG::StoreMeshHelper::sSwapTarget.mPrev;
    mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    UFG::StoreMeshHelper::sSwapTarget.mPrev->mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    mNext->mPrev = mPrev;
    UFG::StoreMeshHelper::sSwapTarget.mPrev = &UFG::StoreMeshHelper::sSwapTarget;
    UFG::StoreMeshHelper::sSwapTarget.mNext = &UFG::StoreMeshHelper::sSwapTarget;
  }
  UFG::StoreMeshHelper::sSwapTarget.m_pPointer = object;
  if ( object )
  {
    v7 = object->m_SafePointerList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v7->mNext = &UFG::StoreMeshHelper::sSwapTarget;
    UFG::StoreMeshHelper::sSwapTarget.mPrev = v7;
    UFG::StoreMeshHelper::sSwapTarget.mNext = &object->m_SafePointerList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    object->m_SafePointerList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &UFG::StoreMeshHelper::sSwapTarget;
  }
  UFG::MeshResourceLoader::Unload(&UFG::StoreMeshHelper::sMeshLoader);
  p_priority = &priority;
  priority.mUID = UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64)->mUID;
  m_pSceneObj = UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  UFG::MeshResourceLoader::Init(
    &UFG::StoreMeshHelper::sMeshLoader,
    mpWritableProperties,
    &priority.mUID,
    m_pComponent->mMeshLoader.mHighDefinition);
  mEntityIndex = m_pComponent->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex;
  UFG::TrueCrowdDataBase::Instance();
  mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mEntityIndex].mComponentCount;
  v12 = 0;
  if ( mComponentCount )
  {
    v13 = UFG::StoreMeshHelper::sTextureSetPaths;
    v14 = UFG::StoreMeshHelper::sModelPaths;
    do
    {
      v15 = UFG::TrueCrowdDataBase::Instance();
      ModelFromPath = UFG::TrueCrowdDataBase::QueryModelFromPath(v15, mEntityIndex, v12, v14);
      v17 = ModelFromPath;
      if ( ModelFromPath )
      {
        UFG::MeshResourceLoader::AddResource(&UFG::StoreMeshHelper::sMeshLoader, ModelFromPath, 0);
        v18 = 0i64;
        mNumTextureSets = v17->mNumTextureSets;
        if ( v17->mNumTextureSets )
        {
          mOffset = v17->mTextureSets.mOffset;
          while ( 1 )
          {
            v21 = mOffset ? (__int64)&v17->mTextureSets + mOffset : 0i64;
            v22 = (_QWORD *)(v21 + 8 * v18);
            v23 = *v22 ? (UFG::TrueCrowdResource *)((char *)v22 + *v22) : 0i64;
            if ( v23->mPathSymbol.mUID == v13->mUID )
              break;
            v18 = (unsigned int)(v18 + 1);
            if ( (unsigned int)v18 >= mNumTextureSets )
              goto LABEL_32;
          }
        }
        else
        {
LABEL_32:
          if ( !(_WORD)mNumTextureSets )
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
    while ( v12 < mComponentCount );
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
  signed __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned int v3; // esi
  unsigned int mComponentCount; // ebp
  __int64 v5; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx

  if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
  {
    m_Flags = UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_Components.p[7].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)UFG::StoreMeshHelper::sSwapTarget.m_pPointer,
                                UFG::StreamedResourceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                UFG::StoreMeshHelper::sSwapTarget.m_pPointer,
                                UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)UFG::StoreMeshHelper::sSwapTarget.m_pPointer->m_Components.p[10].m_pComponent;
    }
    UFG::MeshResourceLoader::Unload(&m_pComponent->mMeshLoader);
    UFG::TrueCrowdDataBase::Instance();
    v3 = 0;
    mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[m_pComponent->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex].mComponentCount;
    if ( mComponentCount )
    {
      v5 = 0i64;
      do
      {
        UFG::StreamedResourceComponent::SwapResource(
          m_pComponent,
          v3++,
          &UFG::StoreMeshHelper::sModelPaths[v5],
          &UFG::StoreMeshHelper::sTextureSetPaths[v5],
          (unsigned int *)&UFG::StoreMeshHelper::sColourTintIndices[v5]);
        ++v5;
      }
      while ( v3 < mComponentCount );
    }
    UFG::MeshResourceLoader::QueueLoad(&m_pComponent->mMeshLoader);
  }
  UFG::MeshResourceLoader::Unload(&UFG::StoreMeshHelper::sMeshLoader);
  UFG::StoreMeshHelper::sSwapQueued = 0;
  if ( UFG::StoreMeshHelper::sSwapTarget.m_pPointer )
  {
    mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    mPrev = UFG::StoreMeshHelper::sSwapTarget.mPrev;
    UFG::StoreMeshHelper::sSwapTarget.mPrev->mNext = UFG::StoreMeshHelper::sSwapTarget.mNext;
    mNext->mPrev = mPrev;
    UFG::StoreMeshHelper::sSwapTarget.mPrev = &UFG::StoreMeshHelper::sSwapTarget;
    UFG::StoreMeshHelper::sSwapTarget.mNext = &UFG::StoreMeshHelper::sSwapTarget;
  }
  UFG::StoreMeshHelper::sSwapTarget.m_pPointer = 0i64;
}

