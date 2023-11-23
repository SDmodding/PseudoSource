// File Line: 58
// RVA: 0x1549B70
__int64 UFG::_dynamic_initializer_for__inventoryEquipSlotAttachments__()
{
  UFG::qSymbolUC::create_from_string(&inventoryEquipSlotAttachments, "Grip R Hand");
  UFG::qSymbolUC::create_from_string(&stru_14240E4C4, "Bip01 R Prop");
  UFG::qSymbolUC::create_from_string(&stru_14240E4C8, "Grip L Hand");
  UFG::qSymbolUC::create_from_string(&stru_14240E4CC, "Bip01 L Hand");
  UFG::qSymbolUC::create_from_string(&stru_14240E4D0, "HeadSync");
  UFG::qSymbolUC::create_from_string(&stru_14240E4D4, "Bip01 Head");
  UFG::qSymbolUC::create_from_string(&stru_14240E4D8, "HeadSync");
  UFG::qSymbolUC::create_from_string(&stru_14240E4DC, "Bip01 Head");
  UFG::qSymbolUC::create_from_string(&stru_14240E4E0, "Grip R Hand");
  UFG::qSymbolUC::create_from_string(&stru_14240E4E4, "Bip01 R Thigh");
  UFG::qSymbolUC::create_from_string(&stru_14240E4E8, "Grip R Hand");
  UFG::qSymbolUC::create_from_string(&stru_14240E4EC, "Bip01 L Thigh");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__inventoryEquipSlotAttachments__);
}

// File Line: 70
// RVA: 0x1543F20
__int64 dynamic_initializer_for__UFG::InventoryComponent::s_InventoryComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InventoryComponent::s_InventoryComponentList__);
}

// File Line: 71
// RVA: 0x52CA70
UFG::ComponentIDDesc *__fastcall UFG::InventoryComponent::GetDesc(UFG::InventoryComponent *this)
{
  return &UFG::InventoryComponent::_TypeIDesc;
}

// File Line: 74
// RVA: 0x5361C0
void UFG::InventoryComponent::Init(void)
{
  UFG::InventoryItemInfo *v0; // rax
  __int64 v1; // rcx

  v0 = UFG::InventoryComponent::ms_InventoryItemInfos;
  v1 = 13i64;
  do
  {
    *(_QWORD *)&v0->m_iCapacity = 0x100000001i64;
    *(_QWORD *)&v0[2].m_iCapacity = 0x100000001i64;
    *(_QWORD *)&v0[4].m_iCapacity = 0x100000001i64;
    v0 += 16;
    *(_QWORD *)&v0[-10].m_iCapacity = 0x100000001i64;
    *(_QWORD *)&v0[-8].m_iCapacity = 0x100000001i64;
    *(_QWORD *)&v0[-6].m_iCapacity = 0x100000001i64;
    *(_QWORD *)&v0[-4].m_iCapacity = 0x100000001i64;
    *(_QWORD *)&v0[-2].m_iCapacity = 0x100000001i64;
    --v1;
  }
  while ( v1 );
  v0->m_iCapacity = 1;
  UFG::InventoryComponent::ms_InventoryItemInfos[18].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[19].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[20].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[21].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[22].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[26].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[27].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[28].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[31].m_iCapacity = 1000;
  UFG::InventoryComponent::ms_InventoryItemInfos[33].m_iCapacity = 90;
  UFG::InventoryComponent::ms_InventoryItemInfos[35].m_iCapacity = 90;
  UFG::InventoryComponent::ms_InventoryItemInfos[38].m_iCapacity = 90;
  UFG::InventoryComponent::ms_InventoryItemInfos[44].m_iCapacity = 120;
  UFG::InventoryComponent::ms_InventoryItemInfos[47].m_iCapacity = 120;
  UFG::InventoryComponent::ms_InventoryItemInfos[48].m_iCapacity = 4;
  UFG::InventoryComponent::ms_InventoryItemInfos[51].m_iCapacity = 60;
  UFG::InventoryComponent::ms_InventoryItemInfos[54].m_iCapacity = 60;
  UFG::InventoryComponent::ms_InventoryItemInfos[56].m_iCapacity = 160;
  UFG::InventoryComponent::ms_InventoryItemInfos[60].m_iCapacity = 100;
  UFG::InventoryComponent::ms_InventoryItemInfos[68].m_iCapacity = 0x7FFFFFFF;
}

// File Line: 114
// RVA: 0x518060
void __fastcall UFG::InventoryComponent::InventoryComponent(UFG::InventoryComponent *this, unsigned int name_uid)
{
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent>;
  this->mNext = &this->UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InventoryComponent::`vftable;
  *(_DWORD *)&this->m_EquipSlots.p[0].mCanDrop = 16843009;
  *(_WORD *)&this->m_EquipSlots.p[4].mCanDrop = 257;
  this->m_EquipSlots.size = 0;
  this->m_SellableItem = eINVENTORY_ITEM_INVALID;
  this->m_SellableItemProp = UFG::gNullQSymbol;
  *(_WORD *)&this->m_InfiniteSellableItem = 0;
  this->m_bDebugDrawInventory = 0;
  mPrev = UFG::InventoryComponent::s_InventoryComponentList.mNode.mPrev;
  UFG::InventoryComponent::s_InventoryComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *)&UFG::InventoryComponent::s_InventoryComponentList;
  UFG::InventoryComponent::s_InventoryComponentList.mNode.mPrev = &this->UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent>;
  UFG::SimComponent::AddType(this, UFG::InventoryComponent::_InventoryComponentTypeUID, "InventoryComponent");
  this->m_EquipSlots.size = 6;
  UFG::qMemSet(this->m_InventoryItems, 0, 0x344u);
  if ( !s_bIsInitialized )
  {
    UFG::InventoryComponent::Init();
    s_bIsInitialized = 1;
  }
}

// File Line: 133
// RVA: 0x51BEE0
void __fastcall UFG::InventoryComponent::~InventoryComponent(UFG::InventoryComponent *this)
{
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v2; // rdx
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *mPrev; // rcx
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *mNext; // rax
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v5; // rcx
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InventoryComponent::`vftable;
  if ( this == UFG::InventoryComponent::s_InventoryComponentpCurrentIterator )
    UFG::InventoryComponent::s_InventoryComponentpCurrentIterator = (UFG::InventoryComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->m_EquipSlots.size = 0;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 145
// RVA: 0x1549A40
__int64 UFG::_dynamic_initializer_for__gsymInventory__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Inventory", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymInventory, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymInventory__);
}

// File Line: 146
// RVA: 0x1549A80
__int64 UFG::_dynamic_initializer_for__gsymRange__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Range", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymRange, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymRange__);
}

// File Line: 147
// RVA: 0x1549B00
__int64 UFG::_dynamic_initializer_for__gsymValue__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Value", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymValue, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymValue__);
}

// File Line: 151
// RVA: 0x546780
UFG::InventoryComponent *__fastcall UFG::InventoryComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::InventoryComponent *v3; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::InventoryComponent *v6; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::InventoryComponent *v10; // rax
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v12; // edi
  UFG::qPropertySet *mpWritableProperties; // rdx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h] BYREF

  v3 = 0i64;
  if ( required )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x3B0ui64, "InventoryComponent", 0i64, 1u);
    if ( v5 )
    {
      UFG::InventoryComponent::InventoryComponent((UFG::InventoryComponent *)v5, pSceneObj->m_NameUID);
      v3 = v6;
    }
LABEL_10:
    if ( v3 )
    {
      m_pSimObject = pSceneObj->m_pSimObject;
      if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
        v12 = 39;
      else
        v12 = -1;
      UFG::SimObjectModifier::SimObjectModifier(&v15, m_pSimObject, 1);
      UFG::SimObjectModifier::AttachComponent(&v15, v3, v12);
      UFG::SimObjectModifier::Close(&v15);
      UFG::SimObjectModifier::~SimObjectModifier(&v15);
      mpWritableProperties = pSceneObj->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = pSceneObj->mpConstProperties;
      UFG::InventoryComponent::ResetFromProperties(v3, mpWritableProperties);
    }
    return v3;
  }
  mpConstProperties = pSceneObj->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = pSceneObj->mpConstProperties;
  if ( UFG::qPropertySet::GetParentFromName(
         mpConstProperties,
         (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentInventory,
         DEPTH_RECURSE) )
  {
    v8 = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(v8, 0x3B0ui64, "InventoryComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::InventoryComponent::InventoryComponent((UFG::InventoryComponent *)v9, pSceneObj->m_NameUID);
      v3 = v10;
    }
    goto LABEL_10;
  }
  return v3;
}

// File Line: 197
// RVA: 0x520AB0
void __fastcall UFG::InventoryComponent::AddInventoryList(
        UFG::InventoryComponent *this,
        UFG::qPropertyList *inventory_list)
{
  unsigned int mNumElements; // r12d
  unsigned int v3; // r15d
  char *ValuePtr; // rax
  UFG::qPropertySet *v7; // rbp
  UFG::eInventoryItemEnum v8; // edi
  __int64 v9; // rbx
  int *v10; // r14
  int *v11; // rax
  float v12; // xmm0_4
  int v13; // ecx
  float v14; // xmm0_4
  int RandomNumberInRange; // edx

  mNumElements = inventory_list->mNumElements;
  v3 = 0;
  if ( mNumElements )
  {
    while ( 1 )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(inventory_list, 0x1Au, v3);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v7 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v7 = 0i64;
      v8 = eINVENTORY_ITEM_INVALID;
      v9 = 0i64;
      while ( v7->mName.mUID != UFG::InventoryItemEnumSymbols[v9].mUID )
      {
        ++v9;
        ++v8;
        if ( v9 >= 209 )
          goto LABEL_29;
      }
      if ( v8 == NUM_INVENTORY_ITEMS )
        goto LABEL_29;
      v10 = UFG::qPropertySet::Get<long>(v7, (UFG::qArray<unsigned long,0> *)&UFG::gsymRange, DEPTH_RECURSE);
      v11 = UFG::qPropertySet::Get<long>(v7, (UFG::qArray<unsigned long,0> *)&UFG::gsymValue, DEPTH_RECURSE);
      if ( v10 )
        break;
      if ( v11 )
      {
        RandomNumberInRange = *v11;
        this->m_InventoryItems[v9].m_iQuantity = *v11;
        goto LABEL_17;
      }
      this->m_InventoryItems[v9].m_iQuantity = 0;
      if ( this->m_pSimObject == LocalPlayer )
      {
        RandomNumberInRange = this->m_InfiniteSellableItem && v8 == this->m_SellableItem;
        goto LABEL_28;
      }
LABEL_29:
      if ( ++v3 >= mNumElements )
        return;
    }
    v12 = (float)(*v11 - *v10 / 2);
    if ( v12 <= 0.0 )
      v12 = 0.0;
    v13 = (int)v12;
    v14 = (float)(*v11 + *v10 / 2);
    if ( v14 <= 0.0 )
      v14 = 0.0;
    RandomNumberInRange = UFG::GetRandomNumberInRange(v13, (int)v14);
    this->m_InventoryItems[v9].m_iQuantity = RandomNumberInRange;
LABEL_17:
    if ( this->m_pSimObject == LocalPlayer )
    {
      if ( this->m_InfiniteSellableItem && v8 == this->m_SellableItem )
        RandomNumberInRange = 1;
LABEL_28:
      UFG::GameStatAction::Inventory::UpdateItem(v8, RandomNumberInRange);
      goto LABEL_29;
    }
    goto LABEL_29;
  }
}

// File Line: 245
// RVA: 0x549E90
void __fastcall UFG::InventoryComponent::ResetFromProperties(UFG::InventoryComponent *this, UFG::qPropertySet *pProps)
{
  UFG::qPropertyList *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::qSymbol *v9; // rax
  unsigned int mUID; // eax
  bool *v11; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  UFG::qMemSet(this->m_InventoryItems, 0, 0x344u);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         pProps,
         (UFG::qArray<unsigned long,0> *)&UFG::gsymInventory,
         DEPTH_RECURSE);
  if ( v4 )
    UFG::InventoryComponent::AddInventoryList(this, v4);
  v5 = UFG::qPropertySet::Get<UFG::qSymbol>(pProps, (UFG::qArray<unsigned long,0> *)&SimSym_SellableItem, DEPTH_RECURSE);
  if ( v5 )
  {
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v5->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    this->m_SellableItem = pTrackEnumBinding.m_EnumValue;
    v7 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v7;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
  }
  v9 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pProps,
         (UFG::qArray<unsigned long,0> *)&SimSym_SellableItemProp,
         DEPTH_RECURSE);
  if ( v9 )
    mUID = v9->mUID;
  else
    mUID = UFG::gNullQSymbol.mUID;
  this->m_SellableItemProp.mUID = mUID;
  v11 = UFG::qPropertySet::Get<bool>(
          pProps,
          (UFG::qArray<unsigned long,0> *)&SimSym_InfiniteSellableItem,
          DEPTH_RECURSE);
  if ( v11 )
    this->m_InfiniteSellableItem = *v11;
}

// File Line: 303
// RVA: 0x53E410
void __fastcall UFG::InventoryComponent::OnAttach(UFG::InventoryComponent *this, UFG::SimObjectCharacter *pObject)
{
  UFG::IsAnyLocalPlayer(pObject);
}

// File Line: 377
// RVA: 0x521290
char __fastcall UFG::InventoryComponent::AddQuantity(
        UFG::InventoryComponent *this,
        UFG::eInventoryItemEnum eInventoryItem,
        const int iQuantity)
{
  int m_iCapacity; // edi
  __int64 v6; // r12
  int v7; // r14d
  char v8; // r15
  int v9; // esi
  const char *v10; // rdx
  bool v11; // cc
  const char *v12; // rdx

  if ( eInventoryItem == eINVENTORY_ITEM_INVALID || eInventoryItem >= NUM_INVENTORY_ITEMS )
    return 0;
  m_iCapacity = UFG::InventoryComponent::ms_InventoryItemInfos[eInventoryItem].m_iCapacity;
  v6 = eInventoryItem;
  v7 = 0;
  v8 = 1;
  v9 = iQuantity + this->m_InventoryItems[v6].m_iQuantity;
  if ( v9 > m_iCapacity )
  {
    if ( (UFG::gInventoryItemTracksEnum.m_enumLists.size & 0x80000000) != 0 )
      v10 = 0i64;
    else
      v10 = (*UFG::gInventoryItemTracksEnum.m_enumLists.p)->m_enumName.p[eInventoryItem];
    UFG::qPrintf(
      "WARNING: InventoryItem: %s -> More Quantity than Capacity! (%d/%d)\n",
      v10,
      (unsigned int)v9,
      (unsigned int)m_iCapacity);
LABEL_13:
    v8 = 0;
    v11 = v9 <= 0;
    goto LABEL_14;
  }
  v11 = v9 <= 0;
  if ( v9 < 0 )
  {
    if ( (UFG::gInventoryItemTracksEnum.m_enumLists.size & 0x80000000) != 0 )
      v12 = 0i64;
    else
      v12 = (*UFG::gInventoryItemTracksEnum.m_enumLists.p)->m_enumName.p[eInventoryItem];
    UFG::qPrintf("WARNING: InventoryItem: %s -> Less Than Zero Quantity! (%d)\n", v12, (unsigned int)v9);
    goto LABEL_13;
  }
LABEL_14:
  if ( !v11 )
    v7 = v9;
  if ( v7 < m_iCapacity )
    m_iCapacity = v7;
  this->m_InventoryItems[v6].m_iQuantity = m_iCapacity;
  if ( this->m_pSimObject == LocalPlayer )
  {
    if ( this->m_InfiniteSellableItem && eInventoryItem == this->m_SellableItem )
      m_iCapacity = 1;
    UFG::GameStatAction::Inventory::UpdateItem(eInventoryItem, m_iCapacity);
  }
  return v8;
}

// File Line: 417
// RVA: 0x5495C0
__int64 __fastcall UFG::InventoryComponent::RemoveQuantity(
        UFG::InventoryComponent *this,
        UFG::eInventoryItemEnum eInventoryItem,
        int iQuantity)
{
  UFG::eInventoryItemEnum m_SellableItem; // ecx
  unsigned int v5; // ebx
  int m_iQuantity; // ecx

  m_SellableItem = this->m_SellableItem;
  v5 = iQuantity;
  if ( eInventoryItem == m_SellableItem )
  {
    if ( this->m_InfiniteSellableItem )
      return 0i64;
    goto LABEL_7;
  }
  if ( !this->m_InfiniteSellableItem || eInventoryItem != m_SellableItem )
  {
LABEL_7:
    m_iQuantity = this->m_InventoryItems[eInventoryItem].m_iQuantity;
    goto LABEL_8;
  }
  m_iQuantity = 1;
LABEL_8:
  if ( m_iQuantity < iQuantity )
    v5 = m_iQuantity;
  UFG::InventoryComponent::AddQuantity(this, eInventoryItem, -v5);
  return v5;
}

// File Line: 430
// RVA: 0x55F840
void __fastcall UFG::InventoryComponent::UpdateGameStat(
        UFG::InventoryComponent *this,
        UFG::eInventoryItemEnum eInventoryItem)
{
  __int64 v2; // r8
  int m_iQuantity; // edx

  v2 = eInventoryItem;
  if ( this->m_pSimObject == LocalPlayer )
  {
    if ( !this->m_InfiniteSellableItem || (m_iQuantity = 1, (_DWORD)v2 != this->m_SellableItem) )
      m_iQuantity = this->m_InventoryItems[v2].m_iQuantity;
    UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)v2, m_iQuantity);
  }
}

// File Line: 438
// RVA: 0x520C70
char __fastcall UFG::InventoryComponent::AddObjectToInventory(
        UFG::InventoryComponent *this,
        UFG::SimObjectProp *pObject,
        const bool bForceObjectToInventory)
{
  __int64 v3; // r15
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  unsigned int mComponentTableEntryCount; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rdi
  UFG::eInventoryItemEnum m_pSimObject; // edx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNext; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  signed __int16 v17; // cx
  unsigned int v18; // ecx
  unsigned int v19; // r9d
  UFG::SimComponentHolder *v20; // rdi
  __int64 v21; // r8
  UFG::SimObjectWeaponPropertiesComponent *v22; // rdi
  unsigned int v23; // ecx
  unsigned int v24; // r9d
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  unsigned int v26; // ecx
  unsigned int v27; // r9d
  signed __int16 v28; // cx
  unsigned int v29; // ecx
  unsigned int v30; // r9d
  UFG::SimComponentHolder *v31; // rsi
  __int64 v32; // r8
  UFG::GunComponent *v33; // rax
  unsigned int v34; // ecx
  unsigned int v35; // r9d
  unsigned int v36; // ecx
  unsigned int v37; // r9d
  unsigned int v38; // ecx
  unsigned int v39; // r9d
  signed __int16 v40; // cx
  UFG::SimComponent *v41; // rcx
  UFG::qPropertySet *mNext; // rax
  UFG::qWiseSymbol *v43; // rbx
  unsigned int v44; // ecx
  UFG::qSymbolUC *WeaponID; // rax
  char *v46; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF

  if ( !pObject )
    return 0;
  m_Flags = pObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    return 0;
  if ( (m_Flags & 0x2000) != 0 )
  {
    m_pComponent = pObject->m_Components.p[11].m_pComponent;
  }
  else if ( (m_Flags & 0x1000) != 0 )
  {
    mComponentTableEntryCount = pObject->mComponentTableEntryCount;
    size = pObject->m_Components.size;
    if ( mComponentTableEntryCount >= size )
    {
LABEL_14:
      m_pComponent = 0i64;
    }
    else
    {
      p = pObject->m_Components.p;
      while ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
           || (UFG::InventoryItemComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) != 0 )
      {
        if ( ++mComponentTableEntryCount >= size )
          goto LABEL_14;
      }
      m_pComponent = p[mComponentTableEntryCount].m_pComponent;
    }
  }
  else
  {
    m_pComponent = UFG::SimObject::GetComponentOfType(pObject, UFG::InventoryItemComponent::_TypeUID);
  }
  if ( !m_pComponent )
    return 0;
  m_pSimObject = (UFG::eInventoryItemEnum)m_pComponent[1].m_pSimObject;
  if ( m_pSimObject == eINVENTORY_ITEM_INVALID
    || !UFG::InventoryComponent::AddQuantity(
          this,
          m_pSimObject,
          (const int)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev,
          v3)
    && !bForceObjectToInventory )
  {
    return 0;
  }
  p_mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&m_pComponent[1].m_SafePointerList.mNode.mNext;
  if ( *(_QWORD *)&m_pComponent[1].m_Flags )
  {
    mPrev = p_mNext->mPrev;
    v15 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&m_pComponent[1].m_TypeUID;
    mPrev->mNext = v15;
    v15->mPrev = mPrev;
    p_mNext->mPrev = p_mNext;
    *(_QWORD *)&m_pComponent[1].m_TypeUID = (char *)m_pComponent + 80;
  }
  *(_QWORD *)&m_pComponent[1].m_Flags = this;
  if ( this )
  {
    v16 = this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v16->mNext = p_mNext;
    p_mNext->mPrev = v16;
    *(_QWORD *)&m_pComponent[1].m_TypeUID = &this->m_SafePointerList;
    this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mNext;
  }
  v17 = pObject->m_Flags;
  if ( (v17 & 0x4000) == 0 )
  {
    if ( v17 < 0 )
    {
      v23 = pObject->mComponentTableEntryCount;
      v24 = pObject->m_Components.size;
      if ( v23 < v24 )
      {
        v20 = pObject->m_Components.p;
        do
        {
          v21 = v23;
          if ( (v20[v23].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
            && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v20[v23].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_31;
          }
        }
        while ( ++v23 < v24 );
      }
LABEL_32:
      v22 = 0i64;
      goto LABEL_51;
    }
    if ( (v17 & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(pObject);
    }
    else
    {
      if ( (v17 & 0x1000) != 0 )
      {
        v26 = pObject->mComponentTableEntryCount;
        v27 = pObject->m_Components.size;
        if ( v26 < v27 )
        {
          v20 = pObject->m_Components.p;
          while ( 1 )
          {
            v21 = v26;
            if ( (v20[v26].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
              && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v20[v26].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_31;
            }
            if ( ++v26 >= v27 )
              goto LABEL_32;
          }
        }
        goto LABEL_32;
      }
      ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     pObject,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    v22 = ComponentOfType;
    goto LABEL_51;
  }
  v18 = pObject->mComponentTableEntryCount;
  v19 = pObject->m_Components.size;
  if ( v18 >= v19 )
    goto LABEL_32;
  v20 = pObject->m_Components.p;
  while ( 1 )
  {
    v21 = v18;
    if ( (v20[v18].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
      && (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v20[v18].m_TypeUID & 0x1FFFFFF) == 0 )
    {
      break;
    }
    if ( ++v18 >= v19 )
      goto LABEL_32;
  }
LABEL_31:
  v22 = (UFG::SimObjectWeaponPropertiesComponent *)v20[v21].m_pComponent;
LABEL_51:
  if ( v22 && v22->mWeaponTypeInfo->mFireModes[v22->mFireMode]->mAmmoInventoryItem )
  {
    v28 = pObject->m_Flags;
    if ( (v28 & 0x4000) != 0 )
    {
      v29 = pObject->mComponentTableEntryCount;
      v30 = pObject->m_Components.size;
      if ( v29 < v30 )
      {
        v31 = pObject->m_Components.p;
        while ( 1 )
        {
          v32 = v29;
          if ( (v31[v29].m_TypeUID & 0xFE000000) == (UFG::GunComponent::_TypeUID & 0xFE000000)
            && (UFG::GunComponent::_TypeUID & ~v31[v29].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v29 >= v30 )
            goto LABEL_61;
        }
LABEL_60:
        v33 = (UFG::GunComponent *)v31[v32].m_pComponent;
        goto LABEL_84;
      }
    }
    else if ( v28 >= 0 )
    {
      if ( (v28 & 0x2000) != 0 )
      {
        v36 = pObject->mComponentTableEntryCount;
        v37 = pObject->m_Components.size;
        if ( v36 < v37 )
        {
          v31 = pObject->m_Components.p;
          do
          {
            v32 = v36;
            if ( (v31[v36].m_TypeUID & 0xFE000000) == (UFG::GunComponent::_TypeUID & 0xFE000000)
              && (UFG::GunComponent::_TypeUID & ~v31[v36].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_60;
            }
          }
          while ( ++v36 < v37 );
        }
      }
      else
      {
        if ( (v28 & 0x1000) == 0 )
        {
          v33 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(pObject, UFG::GunComponent::_TypeUID);
LABEL_84:
          if ( v33 )
            UFG::GunComponent::InitializeGunIntoInventory(v33);
          goto LABEL_86;
        }
        v38 = pObject->mComponentTableEntryCount;
        v39 = pObject->m_Components.size;
        if ( v38 < v39 )
        {
          v31 = pObject->m_Components.p;
          do
          {
            v32 = v38;
            if ( (v31[v38].m_TypeUID & 0xFE000000) == (UFG::GunComponent::_TypeUID & 0xFE000000)
              && (UFG::GunComponent::_TypeUID & ~v31[v38].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_60;
            }
          }
          while ( ++v38 < v39 );
        }
      }
    }
    else
    {
      v34 = pObject->mComponentTableEntryCount;
      v35 = pObject->m_Components.size;
      if ( v34 < v35 )
      {
        v31 = pObject->m_Components.p;
        do
        {
          v32 = v34;
          if ( (v31[v34].m_TypeUID & 0xFE000000) == (UFG::GunComponent::_TypeUID & 0xFE000000)
            && (UFG::GunComponent::_TypeUID & ~v31[v34].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_60;
          }
        }
        while ( ++v34 < v35 );
      }
    }
LABEL_61:
    v33 = 0i64;
    goto LABEL_84;
  }
LABEL_86:
  if ( this->m_pSimObject == LocalPlayer )
  {
    v40 = pObject->m_Flags;
    if ( (v40 & 0x4000) != 0 )
    {
      v41 = pObject->m_Components.p[1].m_pComponent;
    }
    else if ( v40 >= 0 )
    {
      if ( (v40 & 0x2000) != 0 )
        v41 = pObject->m_Components.p[1].m_pComponent;
      else
        v41 = (v40 & 0x1000) != 0 ? pObject->m_Components.p->m_pComponent : pObject->m_pSceneObj;
    }
    else
    {
      v41 = pObject->m_Components.p[1].m_pComponent;
    }
    if ( v41 )
    {
      mNext = (UFG::qPropertySet *)v41[2].m_SafePointerList.mNode.mNext;
      if ( !mNext )
        mNext = *(UFG::qPropertySet **)&v41[2].m_TypeUID;
      v43 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
              mNext,
              (UFG::qArray<unsigned long,0> *)&qSymbol_AudioWeaponType,
              DEPTH_RECURSE);
      if ( v43 )
      {
        v44 = _S66;
        if ( (_S66 & 1) == 0 )
        {
          _S66 |= 1u;
          attack_type_switch = UFG::TiDo::CalcWwiseUid("attack_types");
          v44 = _S66;
        }
        if ( (v44 & 2) == 0 )
        {
          _S66 = v44 | 2;
          play_weapon_pickup = UFG::TiDo::CalcWwiseUid("Play_pickups");
        }
        UFG::AudioEntity::SetWwiseSwitch(UFG::HudAudio::m_instance, attack_type_switch, v43->mUID);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, play_weapon_pickup, 0i64, 0, 0i64);
      }
      else if ( v22 )
      {
        WeaponID = (UFG::qSymbolUC *)UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v22, &result);
        v46 = UFG::qSymbol::as_cstr_dbg(WeaponID);
        UFG::qPrintf("AudioWeaponType not defined for: %s\n", v46);
      }
    }
  }
  return 1;
}

// File Line: 499
// RVA: 0x549120
void __fastcall UFG::InventoryComponent::RemoveObjectFromInventory(
        UFG::InventoryComponent *this,
        UFG::SimObjectProp *pObject)
{
  __int64 v2; // r15
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v9; // rdx
  signed __int16 v10; // dx
  unsigned int v11; // r8d
  unsigned int v12; // r9d
  UFG::SimComponentHolder *v13; // rdx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  unsigned int v17; // r8d
  unsigned int v18; // r9d
  signed __int16 v19; // cx
  unsigned int v20; // r8d
  unsigned int v21; // r9d
  UFG::SimComponentHolder *v22; // rdx
  UFG::GunComponent *v23; // rax
  unsigned int v24; // r8d
  unsigned int v25; // r9d
  unsigned int v26; // r8d
  unsigned int v27; // r9d
  unsigned int v28; // r8d
  unsigned int v29; // r9d
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **p_mNext; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax

  if ( pObject )
  {
    m_Flags = pObject->m_Flags;
    if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = pObject->m_Components.p[11].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        mComponentTableEntryCount = pObject->mComponentTableEntryCount;
        size = pObject->m_Components.size;
        if ( mComponentTableEntryCount >= size )
        {
LABEL_12:
          m_pComponent = 0i64;
        }
        else
        {
          v9 = &pObject->m_Components.p[mComponentTableEntryCount];
          while ( (v9->m_TypeUID & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
               || (UFG::InventoryItemComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            ++v9;
            if ( mComponentTableEntryCount >= size )
              goto LABEL_12;
          }
          m_pComponent = v9->m_pComponent;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pObject, UFG::InventoryItemComponent::_TypeUID);
      }
      if ( m_pComponent && LODWORD(m_pComponent[1].m_pSimObject) )
      {
        v10 = pObject->m_Flags;
        if ( (v10 & 0x4000) != 0 )
        {
          v11 = pObject->mComponentTableEntryCount;
          v12 = pObject->m_Components.size;
          if ( v11 < v12 )
          {
            v13 = &pObject->m_Components.p[v11];
            while ( (v13->m_TypeUID & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                 || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              ++v11;
              ++v13;
              if ( v11 >= v12 )
                goto LABEL_23;
            }
LABEL_24:
            ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)v13->m_pComponent;
            goto LABEL_42;
          }
        }
        else if ( v10 >= 0 )
        {
          if ( (v10 & 0x2000) != 0 )
          {
            ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(pObject);
            goto LABEL_42;
          }
          if ( (v10 & 0x1000) == 0 )
          {
            ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                           pObject,
                                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
            goto LABEL_42;
          }
          v17 = pObject->mComponentTableEntryCount;
          v18 = pObject->m_Components.size;
          if ( v17 < v18 )
          {
            v13 = &pObject->m_Components.p[v17];
            while ( (v13->m_TypeUID & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                 || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              ++v17;
              ++v13;
              if ( v17 >= v18 )
              {
                ComponentOfType = 0i64;
                goto LABEL_42;
              }
            }
            goto LABEL_24;
          }
        }
        else
        {
          v15 = pObject->mComponentTableEntryCount;
          v16 = pObject->m_Components.size;
          if ( v15 < v16 )
          {
            v13 = &pObject->m_Components.p[v15];
            while ( (v13->m_TypeUID & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                 || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              ++v15;
              ++v13;
              if ( v15 >= v16 )
              {
                ComponentOfType = 0i64;
                goto LABEL_42;
              }
            }
            goto LABEL_24;
          }
        }
LABEL_23:
        ComponentOfType = 0i64;
LABEL_42:
        if ( !ComponentOfType
          || ComponentOfType->mWeaponTypeInfo->mFireModes[ComponentOfType->mFireMode]->mAmmoInventoryItem == eINVENTORY_ITEM_INVALID )
        {
LABEL_76:
          UFG::InventoryComponent::RemoveQuantity(
            this,
            (UFG::eInventoryItemEnum)m_pComponent[1].m_pSimObject,
            (const int)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev,
            v2);
          p_mNext = &m_pComponent[1].m_SafePointerList.mNode.mNext;
          if ( *(_QWORD *)&m_pComponent[1].m_Flags )
          {
            v31 = *p_mNext;
            v32 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&m_pComponent[1].m_TypeUID;
            v31->mNext = v32;
            v32->mPrev = v31;
            *p_mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)p_mNext;
            *(_QWORD *)&m_pComponent[1].m_TypeUID = (char *)m_pComponent + 80;
          }
          *(_QWORD *)&m_pComponent[1].m_Flags = 0i64;
          return;
        }
        v19 = pObject->m_Flags;
        if ( (v19 & 0x4000) != 0 )
        {
          v20 = pObject->mComponentTableEntryCount;
          v21 = pObject->m_Components.size;
          if ( v20 < v21 )
          {
            v22 = &pObject->m_Components.p[v20];
            while ( (v22->m_TypeUID & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
                 || (UFG::GunComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              ++v20;
              ++v22;
              if ( v20 >= v21 )
                goto LABEL_50;
            }
LABEL_51:
            v23 = (UFG::GunComponent *)v22->m_pComponent;
            goto LABEL_74;
          }
        }
        else if ( v19 >= 0 )
        {
          if ( (v19 & 0x2000) != 0 )
          {
            v26 = pObject->mComponentTableEntryCount;
            v27 = pObject->m_Components.size;
            if ( v26 < v27 )
            {
              v22 = &pObject->m_Components.p[v26];
              while ( (v22->m_TypeUID & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
                   || (UFG::GunComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
              {
                ++v26;
                ++v22;
                if ( v26 >= v27 )
                {
                  v23 = 0i64;
                  goto LABEL_74;
                }
              }
              goto LABEL_51;
            }
          }
          else
          {
            if ( (v19 & 0x1000) == 0 )
            {
              v23 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(pObject, UFG::GunComponent::_TypeUID);
LABEL_74:
              if ( v23 )
                UFG::GunComponent::RemoveGunFromInventory(v23);
              goto LABEL_76;
            }
            v28 = pObject->mComponentTableEntryCount;
            v29 = pObject->m_Components.size;
            if ( v28 < v29 )
            {
              v22 = &pObject->m_Components.p[v28];
              while ( (v22->m_TypeUID & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
                   || (UFG::GunComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
              {
                ++v28;
                ++v22;
                if ( v28 >= v29 )
                {
                  v23 = 0i64;
                  goto LABEL_74;
                }
              }
              goto LABEL_51;
            }
          }
        }
        else
        {
          v24 = pObject->mComponentTableEntryCount;
          v25 = pObject->m_Components.size;
          if ( v24 < v25 )
          {
            v22 = &pObject->m_Components.p[v24];
            while ( (v22->m_TypeUID & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
                 || (UFG::GunComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              ++v24;
              ++v22;
              if ( v24 >= v25 )
              {
                v23 = 0i64;
                goto LABEL_74;
              }
            }
            goto LABEL_51;
          }
        }
LABEL_50:
        v23 = 0i64;
        goto LABEL_74;
      }
    }
  }
}

// File Line: 625
// RVA: 0x52FCD0
signed __int64 __fastcall UFG::InventoryComponent::GetSlotTarget(UFG::eInventoryEquipSlot slot)
{
  UFG::eTargetTypeEnum v1; // edx
  signed __int64 result; // rax

  v1 = eTARGET_TYPE_EQUIPPED;
  switch ( slot )
  {
    case 1:
      result = eTARGET_TYPE_EQUIPPED_LEFT_HAND;
      break;
    case 2:
      result = eTARGET_TYPE_EQUIPPED_HAT;
      break;
    case 3:
      result = eTARGET_TYPE_EQUIPPED_GLASSES;
      break;
    case 4:
      result = eTARGET_TYPE_STOWED_WEAPON;
      break;
    case 5:
      v1 = eTARGET_TYPE_STOWED_2H_WEAPON;
      goto $LN1_19;
    default:
$LN1_19:
      result = (unsigned int)v1;
      break;
  }
  return result;
}

// File Line: 657
// RVA: 0x527860
bool __fastcall UFG::InventoryComponent::Equip(UFG::SimObject *pSimObject, UFG::SimObjectProp *pObjectToEquip)
{
  signed __int16 m_Flags; // r8
  UFG::InventoryComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v7; // rdx
  unsigned int v8; // r8d
  unsigned int v9; // r9d
  unsigned int v10; // r8d
  unsigned int v11; // r9d

  if ( !pSimObject || !pObjectToEquip )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::InventoryComponent *)pSimObject->m_Components.p[39].m_pComponent;
    goto LABEL_28;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)pSimObject[1].vfptr;
    size = pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v7 = &pSimObject->m_Components.p[vfptr];
      while ( (v7->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
           || (UFG::InventoryComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        ++v7;
        if ( vfptr >= size )
          goto LABEL_11;
      }
LABEL_12:
      m_pComponent = (UFG::InventoryComponent *)v7->m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_11;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v8 = (unsigned int)pSimObject[1].vfptr;
    v9 = pSimObject->m_Components.size;
    if ( v8 < v9 )
    {
      v7 = &pSimObject->m_Components.p[v8];
      while ( (v7->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
           || (UFG::InventoryComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v8;
        ++v7;
        if ( v8 >= v9 )
        {
          m_pComponent = 0i64;
          goto LABEL_28;
        }
      }
      goto LABEL_12;
    }
LABEL_11:
    m_pComponent = 0i64;
    goto LABEL_28;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v10 = (unsigned int)pSimObject[1].vfptr;
    v11 = pSimObject->m_Components.size;
    if ( v10 < v11 )
    {
      v7 = &pSimObject->m_Components.p[v10];
      while ( (v7->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
           || (UFG::InventoryComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v10;
        ++v7;
        if ( v10 >= v11 )
        {
          m_pComponent = 0i64;
          goto LABEL_28;
        }
      }
      goto LABEL_12;
    }
    goto LABEL_11;
  }
  m_pComponent = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                              pSimObject,
                                              UFG::InventoryComponent::_TypeUID);
LABEL_28:
  if ( m_pComponent )
    return UFG::InventoryComponent::Equip(m_pComponent, pObjectToEquip, 0, eINVENTORY_EQUIP_SLOT_RIGHT_HAND);
  return 0;
}

// File Line: 680
// RVA: 0x526F80
__int64 __fastcall UFG::InventoryComponent::Equip(UFG::InventoryComponent *this, UFG::SimObject *pObjectToEquip)
{
  return UFG::InventoryComponent::Equip(this, pObjectToEquip, 0, eINVENTORY_EQUIP_SLOT_RIGHT_HAND);
}

// File Line: 685
// RVA: 0x526F90
__int64 __fastcall UFG::InventoryComponent::Equip(
        UFG::InventoryComponent *this,
        UFG::SimObjectProp *pObjectToEquip,
        bool useEquipSlot,
        UFG::eInventoryEquipSlot inventoryEquipSlot)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectWeaponPropertiesComponent *v8; // rbx
  UFG::TargetingSystemBaseComponent *m_pComponent; // r14
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v12; // rdx
  unsigned int v13; // r8d
  unsigned int v14; // r9d
  UFG::eTargetTypeEnum mEquipTarget; // r12d
  UFG::SimObjectProp *v16; // rcx
  UFG::CharacterAnimationComponent *v17; // rdi
  __int16 v18; // dx
  unsigned int v19; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  bool v21; // zf
  unsigned int mComponentTableEntryCount; // r9d
  unsigned int v23; // r10d
  __int64 v24; // r8
  signed __int16 v25; // cx
  UFG::SimComponent *v26; // rcx
  UFG::CharacterAnimationComponent *v27; // rax
  unsigned int v28; // r9d
  unsigned int v29; // r10d
  UFG::SimComponentHolder *v30; // r8
  Creature *mCreature; // rdi
  __int64 v32; // rcx
  int BoneID; // ebp
  int attachmentBoneID; // r15d
  UFG::SimObject *v35; // rcx
  UFG::TriadWarsComponent *v36; // rdi
  __int16 v37; // dx
  unsigned int v38; // r8d
  unsigned int v39; // r9d
  __int64 v40; // rdx
  unsigned int v41; // r8d
  unsigned int v42; // r9d
  unsigned int v43; // r8d
  unsigned int v44; // r9d
  unsigned int v45; // r8d
  unsigned int v46; // r9d
  signed __int16 v47; // cx
  unsigned int v48; // r8d
  unsigned int v49; // r10d
  UFG::SimComponentHolder *v50; // rdx
  unsigned int v51; // r8d
  unsigned int v52; // r10d
  UFG::SimObjectWeaponPropertiesComponent *v53; // rax
  unsigned int v54; // r8d
  unsigned int v55; // r10d
  UFG::InventoryComponent::EquipInfo v57; // [rsp+40h] [rbp-48h] BYREF
  unsigned __int8 v58; // [rsp+98h] [rbp+10h]

  v58 = 0;
  if ( !pObjectToEquip )
    return v58;
  *(_QWORD *)&v57.mPropBoneUID.mUID = -1i64;
  UFG::InventoryComponent::EquipInfo::init(&v57, pObjectToEquip, useEquipSlot, inventoryEquipSlot);
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return v58;
  m_Flags = m_pSimObject->m_Flags;
  v8 = 0i64;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
      goto LABEL_23;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v12 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v12 += 16i64;
          if ( vfptr >= size )
            goto LABEL_13;
        }
LABEL_14:
        m_pComponent = *(UFG::TargetingSystemBaseComponent **)v12;
        goto LABEL_23;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pSimObject,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_23;
      }
      v13 = (unsigned int)m_pSimObject[1].vfptr;
      v14 = m_pSimObject->m_Components.size;
      if ( v13 < v14 )
      {
        v12 = (__int64)&m_pSimObject->m_Components.p[v13];
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v13;
          v12 += 16i64;
          if ( v13 >= v14 )
          {
            m_pComponent = 0i64;
            goto LABEL_23;
          }
        }
        goto LABEL_14;
      }
    }
LABEL_13:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
  m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
LABEL_23:
  if ( !m_pComponent )
    return v58;
  mEquipTarget = v57.mEquipTarget;
  if ( m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[v57.mEquipTarget]].m_pTarget.m_pPointer )
    return v58;
  v16 = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !v16 )
  {
    v17 = 0i64;
LABEL_49:
    v19 = UFG::CharacterAnimationComponent::_TypeUID;
    goto LABEL_50;
  }
  v18 = v16->m_Flags;
  if ( (v18 & 0x4000) != 0 )
  {
    v19 = UFG::CharacterAnimationComponent::_TypeUID;
    v17 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v17
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_31;
    }
    goto LABEL_50;
  }
  if ( v18 < 0 )
  {
    v19 = UFG::CharacterAnimationComponent::_TypeUID;
    v17 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v17 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_31;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
      v17 = 0i64;
    goto LABEL_50;
  }
  if ( (v18 & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v16);
LABEL_48:
    v17 = ComponentOfType;
    goto LABEL_49;
  }
  v21 = (v18 & 0x1000) == 0;
  v19 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( v21 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            v16,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_48;
  }
  mComponentTableEntryCount = v16->mComponentTableEntryCount;
  v23 = v16->m_Components.size;
  if ( mComponentTableEntryCount >= v23 )
  {
LABEL_31:
    v17 = 0i64;
    goto LABEL_50;
  }
  v24 = (__int64)&v16->m_Components.p[mComponentTableEntryCount];
  while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    v24 += 16i64;
    if ( mComponentTableEntryCount >= v23 )
    {
      v17 = 0i64;
      goto LABEL_50;
    }
  }
  v17 = *(UFG::CharacterAnimationComponent **)v24;
LABEL_50:
  v25 = pObjectToEquip->m_Flags;
  if ( (v25 & 0x4000) != 0 )
  {
    v26 = pObjectToEquip->m_Components.p[9].m_pComponent;
    if ( !v26 || ((v19 ^ v26->m_TypeUID) & 0xFE000000) != 0 || (v19 & ~v26->m_TypeUID & 0x1FFFFFF) != 0 )
      goto LABEL_54;
    goto LABEL_72;
  }
  if ( v25 < 0 )
  {
    v26 = pObjectToEquip->m_Components.p[9].m_pComponent;
    if ( !v26 || ((v19 ^ v26->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_54;
    if ( (v19 & ~v26->m_TypeUID & 0x1FFFFFF) != 0 )
      v26 = 0i64;
    goto LABEL_72;
  }
  if ( (v25 & 0x2000) != 0 )
  {
    v27 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pObjectToEquip);
LABEL_71:
    v26 = v27;
    goto LABEL_72;
  }
  if ( (v25 & 0x1000) == 0 )
  {
    v27 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(pObjectToEquip, v19);
    goto LABEL_71;
  }
  v28 = pObjectToEquip->mComponentTableEntryCount;
  v29 = pObjectToEquip->m_Components.size;
  if ( v28 >= v29 )
  {
LABEL_54:
    v26 = 0i64;
    goto LABEL_72;
  }
  v30 = &pObjectToEquip->m_Components.p[v28];
  while ( (v30->m_TypeUID & 0xFE000000) != (v19 & 0xFE000000) || (v19 & ~v30->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    ++v28;
    ++v30;
    if ( v28 >= v29 )
    {
      v26 = 0i64;
      goto LABEL_72;
    }
  }
  v26 = v30->m_pComponent;
LABEL_72:
  if ( v17 )
    mCreature = v17->mCreature;
  else
    mCreature = 0i64;
  if ( v26 )
    v32 = *(_QWORD *)&v26[2].m_TypeUID;
  else
    v32 = 0i64;
  if ( mCreature && v32 )
  {
    BoneID = -1;
    if ( *(_QWORD *)(v32 + 440) )
      attachmentBoneID = Skeleton::GetBoneID(*(Skeleton **)(v32 + 480), v57.mPropBoneUID.mUID);
    else
      attachmentBoneID = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, v57.mCharacterBoneUID.mUID);
    if ( attachmentBoneID >= 0 && BoneID >= 0 && UFG::InventoryComponent::AddObjectToInventory(this, pObjectToEquip, 1) )
    {
      Creature::AddAttachment(
        mCreature,
        this->m_pSimObject,
        BoneID,
        (UFG::SimObjectCVBase *)pObjectToEquip,
        attachmentBoneID,
        0,
        0.0);
      UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, mEquipTarget, pObjectToEquip);
      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, __int64))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
        m_pComponent,
        (unsigned int)mEquipTarget,
        1i64);
      v58 = 1;
      if ( this->m_pSimObject == LocalPlayer && mEquipTarget == eTARGET_TYPE_EQUIPPED )
        UFG::GameStatAction::Inventory::Equip(pObjectToEquip);
      v35 = this->m_pSimObject;
      if ( !v35 )
        goto LABEL_92;
      v37 = v35->m_Flags;
      if ( (v37 & 0x4000) != 0 )
      {
        v38 = (unsigned int)v35[1].vfptr;
        v39 = v35->m_Components.size;
        if ( v38 < v39 )
        {
          v40 = (__int64)&v35->m_Components.p[v38];
          while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
               || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v38;
            v40 += 16i64;
            if ( v38 >= v39 )
            {
              v36 = 0i64;
              goto LABEL_123;
            }
          }
LABEL_100:
          v36 = *(UFG::TriadWarsComponent **)v40;
          goto LABEL_123;
        }
      }
      else if ( v37 >= 0 )
      {
        if ( (v37 & 0x2000) != 0 )
        {
          v43 = (unsigned int)v35[1].vfptr;
          v44 = v35->m_Components.size;
          if ( v43 < v44 )
          {
            v40 = (__int64)&v35->m_Components.p[v43];
            while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                 || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v43;
              v40 += 16i64;
              if ( v43 >= v44 )
              {
                v36 = 0i64;
                goto LABEL_123;
              }
            }
            goto LABEL_100;
          }
        }
        else
        {
          if ( (v37 & 0x1000) == 0 )
          {
            v36 = (UFG::TriadWarsComponent *)UFG::SimObject::GetComponentOfType(v35, UFG::TriadWarsComponent::_TypeUID);
LABEL_123:
            v47 = pObjectToEquip->m_Flags;
            if ( (v47 & 0x4000) != 0 )
            {
              v48 = pObjectToEquip->mComponentTableEntryCount;
              v49 = pObjectToEquip->m_Components.size;
              if ( v48 >= v49 )
              {
LABEL_149:
                if ( v36 && v8 )
                  UFG::TriadWarsComponent::OnEquip(v36, v8);
                return v58;
              }
              v50 = &pObjectToEquip->m_Components.p[v48];
              while ( (v50->m_TypeUID & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                   || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) != 0 )
              {
                ++v48;
                ++v50;
                if ( v48 >= v49 )
                  goto LABEL_149;
              }
LABEL_130:
              v8 = (UFG::SimObjectWeaponPropertiesComponent *)v50->m_pComponent;
              goto LABEL_149;
            }
            if ( v47 < 0 )
            {
              v51 = pObjectToEquip->mComponentTableEntryCount;
              v52 = pObjectToEquip->m_Components.size;
              if ( v51 >= v52 )
                goto LABEL_149;
              v50 = &pObjectToEquip->m_Components.p[v51];
              while ( (v50->m_TypeUID & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                   || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) != 0 )
              {
                ++v51;
                ++v50;
                if ( v51 >= v52 )
                  goto LABEL_149;
              }
              goto LABEL_130;
            }
            if ( (v47 & 0x2000) != 0 )
            {
              v53 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(pObjectToEquip);
            }
            else
            {
              if ( (v47 & 0x1000) != 0 )
              {
                v54 = pObjectToEquip->mComponentTableEntryCount;
                v55 = pObjectToEquip->m_Components.size;
                if ( v54 >= v55 )
                  goto LABEL_149;
                v50 = &pObjectToEquip->m_Components.p[v54];
                while ( (v50->m_TypeUID & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                     || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v50->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  ++v54;
                  ++v50;
                  if ( v54 >= v55 )
                    goto LABEL_149;
                }
                goto LABEL_130;
              }
              v53 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                 pObjectToEquip,
                                                                 UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
            }
            v8 = v53;
            goto LABEL_149;
          }
          v45 = (unsigned int)v35[1].vfptr;
          v46 = v35->m_Components.size;
          if ( v45 < v46 )
          {
            v40 = (__int64)&v35->m_Components.p[v45];
            while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                 || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v45;
              v40 += 16i64;
              if ( v45 >= v46 )
              {
                v36 = 0i64;
                goto LABEL_123;
              }
            }
            goto LABEL_100;
          }
        }
      }
      else
      {
        v41 = (unsigned int)v35[1].vfptr;
        v42 = v35->m_Components.size;
        if ( v41 < v42 )
        {
          v40 = (__int64)&v35->m_Components.p[v41];
          while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
               || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v41;
            v40 += 16i64;
            if ( v41 >= v42 )
            {
              v36 = 0i64;
              goto LABEL_123;
            }
          }
          goto LABEL_100;
        }
      }
LABEL_92:
      v36 = 0i64;
      goto LABEL_123;
    }
  }
  return v58;
}

// File Line: 781
// RVA: 0x557A40
void __fastcall UFG::InventoryComponent::UnEquip(
        UFG::InventoryComponent *this,
        UFG::eInventoryEquipSlot slot,
        const bool bDeleteFromWorld)
{
  UFG::eTargetTypeEnum v4; // r12d
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectWeaponPropertiesComponent *v7; // rdi
  UFG::TargetingSystemBaseComponent *m_pComponent; // r14
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v11; // rdx
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  UFG::TargetingSimObject *m_pTargets; // rcx
  __int64 v15; // r8
  UFG::SimObjectProp *m_pPointer; // r15
  bool v17; // al
  UFG::SimObjectProp *v18; // rcx
  UFG::CharacterAnimationComponent *v19; // rbx
  __int16 v20; // dx
  unsigned int v21; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  bool v23; // zf
  unsigned int mComponentTableEntryCount; // r9d
  unsigned int v25; // r10d
  __int64 v26; // r8
  __int16 v27; // cx
  UFG::CharacterAnimationComponent *v28; // rcx
  UFG::CharacterAnimationComponent *v29; // rax
  unsigned int v30; // r9d
  unsigned int v31; // r10d
  __int64 v32; // r8
  Creature *mCreature; // rsi
  Creature *v34; // rbx
  int v35; // ebp
  int BoneID; // ebx
  UFG::SimObject *v37; // rcx
  __int16 v38; // dx
  UFG::InventoryComponent *v39; // rax
  unsigned int v40; // r8d
  unsigned int v41; // r9d
  __int64 v42; // rdx
  unsigned int v43; // r8d
  unsigned int v44; // r9d
  unsigned int v45; // r8d
  unsigned int v46; // r9d
  __int64 v47; // r9
  UFG::SimObject *v48; // rcx
  __int16 v49; // dx
  UFG::CompositeDrawableComponent *v50; // rax
  unsigned int v51; // r8d
  unsigned int v52; // r9d
  __int64 v53; // rdx
  UFG::SimObject *v54; // rcx
  UFG::TriadWarsComponent *v55; // rbx
  __int16 v56; // dx
  unsigned int v57; // r8d
  unsigned int v58; // r9d
  __int64 v59; // rdx
  unsigned int v60; // r8d
  unsigned int v61; // r9d
  unsigned int v62; // r8d
  unsigned int v63; // r9d
  unsigned int v64; // r8d
  unsigned int v65; // r9d
  __int16 v66; // dx
  unsigned int v67; // r8d
  unsigned int v68; // r9d
  __int64 v69; // rdx
  unsigned int v70; // r8d
  unsigned int v71; // r9d
  UFG::SimObjectWeaponPropertiesComponent *v72; // rax
  unsigned int v73; // r8d
  unsigned int v74; // r9d
  UFG::InventoryComponent::EquipInfo v75; // [rsp+40h] [rbp-38h] BYREF

  v4 = eTARGET_TYPE_EQUIPPED;
  switch ( slot )
  {
    case eINVENTORY_EQUIP_SLOT_LEFT_HAND:
      v4 = eTARGET_TYPE_EQUIPPED_LEFT_HAND;
      break;
    case eINVENTORY_EQUIP_SLOT_HAT:
      v4 = eTARGET_TYPE_EQUIPPED_HAT;
      break;
    case eINVENTORY_EQUIP_SLOT_GLASSES:
      v4 = eTARGET_TYPE_EQUIPPED_GLASSES;
      break;
    case eINVENTORY_EQUIP_SLOT_STOWED_1H:
      v4 = eTARGET_TYPE_STOWED_WEAPON;
      break;
    case eINVENTORY_EQUIP_SLOT_STOWED_2H:
      v4 = eTARGET_TYPE_STOWED_2H_WEAPON;
      break;
    default:
      break;
  }
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return;
  m_Flags = m_pSimObject->m_Flags;
  v7 = 0i64;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
      goto LABEL_28;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v11 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v11 += 16i64;
          if ( vfptr >= size )
            goto LABEL_18;
        }
LABEL_19:
        m_pComponent = *(UFG::TargetingSystemBaseComponent **)v11;
        goto LABEL_28;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pSimObject,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_28;
      }
      v12 = (unsigned int)m_pSimObject[1].vfptr;
      v13 = m_pSimObject->m_Components.size;
      if ( v12 < v13 )
      {
        v11 = (__int64)&m_pSimObject->m_Components.p[v12];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v12;
          v11 += 16i64;
          if ( v12 >= v13 )
          {
            m_pComponent = 0i64;
            goto LABEL_28;
          }
        }
        goto LABEL_19;
      }
    }
LABEL_18:
    m_pComponent = 0i64;
    goto LABEL_28;
  }
  m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
LABEL_28:
  if ( !m_pComponent )
    return;
  m_pTargets = m_pComponent->m_pTargets;
  v15 = (unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[v4];
  m_pPointer = (UFG::SimObjectProp *)m_pTargets[v15].m_pTarget.m_pPointer;
  v17 = m_pPointer && m_pTargets[v15].m_bLock;
  if ( !m_pPointer || !v17 )
    return;
  v18 = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !v18 )
  {
    v19 = 0i64;
LABEL_59:
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    goto LABEL_60;
  }
  v20 = v18->m_Flags;
  if ( (v20 & 0x4000) != 0 )
  {
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    v19 = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
    if ( !v19
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ v19->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~v19->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_41;
    }
    goto LABEL_60;
  }
  if ( v20 < 0 )
  {
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    v19 = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
    if ( !v19 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v19->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_41;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v19->m_TypeUID & 0x1FFFFFF) != 0 )
      v19 = 0i64;
    goto LABEL_60;
  }
  if ( (v20 & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v18);
LABEL_58:
    v19 = ComponentOfType;
    goto LABEL_59;
  }
  v23 = (v20 & 0x1000) == 0;
  v21 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( v23 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            v18,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_58;
  }
  mComponentTableEntryCount = v18->mComponentTableEntryCount;
  v25 = v18->m_Components.size;
  if ( mComponentTableEntryCount >= v25 )
  {
LABEL_41:
    v19 = 0i64;
    goto LABEL_60;
  }
  v26 = (__int64)&v18->m_Components.p[mComponentTableEntryCount];
  while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    v26 += 16i64;
    if ( mComponentTableEntryCount >= v25 )
    {
      v19 = 0i64;
      goto LABEL_60;
    }
  }
  v19 = *(UFG::CharacterAnimationComponent **)v26;
LABEL_60:
  v27 = m_pPointer->m_Flags;
  if ( (v27 & 0x4000) != 0 )
  {
    v28 = (UFG::CharacterAnimationComponent *)m_pPointer->m_Components.p[9].m_pComponent;
    if ( !v28 || ((v21 ^ v28->m_TypeUID) & 0xFE000000) != 0 || (v21 & ~v28->m_TypeUID & 0x1FFFFFF) != 0 )
      goto LABEL_64;
    goto LABEL_82;
  }
  if ( v27 < 0 )
  {
    v28 = (UFG::CharacterAnimationComponent *)m_pPointer->m_Components.p[9].m_pComponent;
    if ( !v28 || ((v21 ^ v28->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_64;
    if ( (v21 & ~v28->m_TypeUID & 0x1FFFFFF) != 0 )
      v28 = 0i64;
    goto LABEL_82;
  }
  if ( (v27 & 0x2000) != 0 )
  {
    v29 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
LABEL_81:
    v28 = v29;
    goto LABEL_82;
  }
  if ( (v27 & 0x1000) == 0 )
  {
    v29 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(m_pPointer, v21);
    goto LABEL_81;
  }
  v30 = m_pPointer->mComponentTableEntryCount;
  v31 = m_pPointer->m_Components.size;
  if ( v30 >= v31 )
  {
LABEL_64:
    v28 = 0i64;
    goto LABEL_82;
  }
  v32 = (__int64)&m_pPointer->m_Components.p[v30];
  while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (v21 & 0xFE000000) || (v21 & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF) != 0 )
  {
    ++v30;
    v32 += 16i64;
    if ( v30 >= v31 )
    {
      v28 = 0i64;
      goto LABEL_82;
    }
  }
  v28 = *(UFG::CharacterAnimationComponent **)v32;
LABEL_82:
  if ( v19 )
    mCreature = v19->mCreature;
  else
    mCreature = 0i64;
  if ( v28 )
    v34 = v28->mCreature;
  else
    v34 = 0i64;
  if ( mCreature && v34 )
  {
    *(_QWORD *)&v75.mPropBoneUID.mUID = -1i64;
    UFG::InventoryComponent::EquipInfo::init(&v75, m_pPointer, 0, eINVENTORY_EQUIP_SLOT_RIGHT_HAND);
    v35 = -1;
    if ( v34->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(v34->mPose.mRigHandle.mUFGSkeleton, v75.mPropBoneUID.mUID);
    else
      BoneID = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      v35 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, v75.mCharacterBoneUID.mUID);
    if ( BoneID >= 0 && v35 >= 0 )
    {
      v37 = this->m_pSimObject;
      if ( v37 )
      {
        v38 = v37->m_Flags;
        if ( (v38 & 0x4000) != 0 )
        {
          v39 = (UFG::InventoryComponent *)v37->m_Components.p[39].m_pComponent;
          goto LABEL_123;
        }
        if ( v38 >= 0 )
        {
          if ( (v38 & 0x2000) != 0 )
          {
            v43 = (unsigned int)v37[1].vfptr;
            v44 = v37->m_Components.size;
            if ( v43 < v44 )
            {
              v42 = (__int64)&v37->m_Components.p[v43];
              while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                   || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v43;
                v42 += 16i64;
                if ( v43 >= v44 )
                {
                  v39 = 0i64;
                  goto LABEL_123;
                }
              }
              goto LABEL_107;
            }
          }
          else
          {
            if ( (v38 & 0x1000) == 0 )
            {
              v39 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                 v37,
                                                 UFG::InventoryComponent::_TypeUID);
LABEL_123:
              if ( !v39 )
                return;
              UFG::InventoryComponent::RemoveObjectFromInventory(v39, m_pPointer);
              Creature::RemoveAttachment(mCreature, this->m_pSimObject, v35, m_pPointer);
              LOBYTE(v47) = 1;
              ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
                m_pComponent,
                (unsigned int)v4,
                0i64,
                v47,
                0,
                "InventoryComponent::UnEquip",
                0i64,
                0i64);
              UFG::TargetingSystemBaseComponent::ClearTarget(m_pComponent, v4);
              v48 = this->m_pSimObject;
              if ( v48 )
              {
                v49 = v48->m_Flags;
                if ( (v49 & 0x4000) != 0 )
                {
                  v50 = (UFG::CompositeDrawableComponent *)v48->m_Components.p[14].m_pComponent;
                }
                else if ( v49 >= 0 )
                {
                  if ( (v49 & 0x2000) != 0 )
                  {
                    v50 = (UFG::CompositeDrawableComponent *)v48->m_Components.p[9].m_pComponent;
                  }
                  else if ( (v49 & 0x1000) != 0 )
                  {
                    v51 = (unsigned int)v48[1].vfptr;
                    v52 = v48->m_Components.size;
                    if ( v51 >= v52 )
                    {
LABEL_137:
                      v50 = 0i64;
                    }
                    else
                    {
                      v53 = (__int64)&v48->m_Components.p[v51];
                      while ( (*(_DWORD *)(v53 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
                           || (UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) != 0 )
                      {
                        ++v51;
                        v53 += 16i64;
                        if ( v51 >= v52 )
                          goto LABEL_137;
                      }
                      v50 = *(UFG::CompositeDrawableComponent **)v53;
                    }
                  }
                  else
                  {
                    v50 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                               v48,
                                                               UFG::CompositeDrawableComponent::_TypeUID);
                  }
                }
                else
                {
                  v50 = (UFG::CompositeDrawableComponent *)v48->m_Components.p[14].m_pComponent;
                }
                if ( v50 )
                  UFG::CompositeDrawableComponent::SetIsHidden(v50, 0);
              }
              if ( this->m_pSimObject == LocalPlayer && v4 == eTARGET_TYPE_EQUIPPED )
                UFG::GameStatAction::Inventory::UnEquip(0);
              v54 = this->m_pSimObject;
              if ( !v54 )
                goto LABEL_146;
              v56 = v54->m_Flags;
              if ( (v56 & 0x4000) != 0 )
              {
                v57 = (unsigned int)v54[1].vfptr;
                v58 = v54->m_Components.size;
                if ( v57 < v58 )
                {
                  v59 = (__int64)&v54->m_Components.p[v57];
                  while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                       || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF) != 0 )
                  {
                    ++v57;
                    v59 += 16i64;
                    if ( v57 >= v58 )
                    {
                      v55 = 0i64;
                      goto LABEL_177;
                    }
                  }
LABEL_154:
                  v55 = *(UFG::TriadWarsComponent **)v59;
                  goto LABEL_177;
                }
              }
              else if ( v56 >= 0 )
              {
                if ( (v56 & 0x2000) != 0 )
                {
                  v62 = (unsigned int)v54[1].vfptr;
                  v63 = v54->m_Components.size;
                  if ( v62 < v63 )
                  {
                    v59 = (__int64)&v54->m_Components.p[v62];
                    while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF) != 0 )
                    {
                      ++v62;
                      v59 += 16i64;
                      if ( v62 >= v63 )
                      {
                        v55 = 0i64;
                        goto LABEL_177;
                      }
                    }
                    goto LABEL_154;
                  }
                }
                else
                {
                  if ( (v56 & 0x1000) == 0 )
                  {
                    v55 = (UFG::TriadWarsComponent *)UFG::SimObject::GetComponentOfType(
                                                       v54,
                                                       UFG::TriadWarsComponent::_TypeUID);
LABEL_177:
                    v66 = m_pPointer->m_Flags;
                    if ( (v66 & 0x4000) != 0 )
                    {
                      v67 = m_pPointer->mComponentTableEntryCount;
                      v68 = m_pPointer->m_Components.size;
                      if ( v67 >= v68 )
                        goto LABEL_203;
                      v69 = (__int64)&m_pPointer->m_Components.p[v67];
                      while ( (*(_DWORD *)(v69 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                           || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v69 + 8) & 0x1FFFFFF) != 0 )
                      {
                        ++v67;
                        v69 += 16i64;
                        if ( v67 >= v68 )
                          goto LABEL_203;
                      }
                      goto LABEL_184;
                    }
                    if ( v66 < 0 )
                    {
                      v70 = m_pPointer->mComponentTableEntryCount;
                      v71 = m_pPointer->m_Components.size;
                      if ( v70 < v71 )
                      {
                        v69 = (__int64)&m_pPointer->m_Components.p[v70];
                        while ( (*(_DWORD *)(v69 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                             || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v69 + 8) & 0x1FFFFFF) != 0 )
                        {
                          ++v70;
                          v69 += 16i64;
                          if ( v70 >= v71 )
                            goto LABEL_203;
                        }
LABEL_184:
                        v7 = *(UFG::SimObjectWeaponPropertiesComponent **)v69;
                        goto LABEL_203;
                      }
                      goto LABEL_203;
                    }
                    if ( (v66 & 0x2000) != 0 )
                    {
                      v72 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(m_pPointer);
                    }
                    else
                    {
                      if ( (v66 & 0x1000) != 0 )
                      {
                        v73 = m_pPointer->mComponentTableEntryCount;
                        v74 = m_pPointer->m_Components.size;
                        if ( v73 < v74 )
                        {
                          v69 = (__int64)&m_pPointer->m_Components.p[v73];
                          while ( (*(_DWORD *)(v69 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                               || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v69 + 8) & 0x1FFFFFF) != 0 )
                          {
                            ++v73;
                            v69 += 16i64;
                            if ( v73 >= v74 )
                              goto LABEL_203;
                          }
                          goto LABEL_184;
                        }
LABEL_203:
                        if ( v55 && v7 )
                          UFG::TriadWarsComponent::OnUnEquip(v55, v7);
                        if ( bDeleteFromWorld )
                          UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
                        return;
                      }
                      v72 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                         m_pPointer,
                                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                    }
                    v7 = v72;
                    goto LABEL_203;
                  }
                  v64 = (unsigned int)v54[1].vfptr;
                  v65 = v54->m_Components.size;
                  if ( v64 < v65 )
                  {
                    v59 = (__int64)&v54->m_Components.p[v64];
                    while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF) != 0 )
                    {
                      ++v64;
                      v59 += 16i64;
                      if ( v64 >= v65 )
                      {
                        v55 = 0i64;
                        goto LABEL_177;
                      }
                    }
                    goto LABEL_154;
                  }
                }
              }
              else
              {
                v60 = (unsigned int)v54[1].vfptr;
                v61 = v54->m_Components.size;
                if ( v60 < v61 )
                {
                  v59 = (__int64)&v54->m_Components.p[v60];
                  while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                       || (UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF) != 0 )
                  {
                    ++v60;
                    v59 += 16i64;
                    if ( v60 >= v61 )
                    {
                      v55 = 0i64;
                      goto LABEL_177;
                    }
                  }
                  goto LABEL_154;
                }
              }
LABEL_146:
              v55 = 0i64;
              goto LABEL_177;
            }
            v45 = (unsigned int)v37[1].vfptr;
            v46 = v37->m_Components.size;
            if ( v45 < v46 )
            {
              v42 = (__int64)&v37->m_Components.p[v45];
              while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                   || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) != 0 )
              {
                ++v45;
                v42 += 16i64;
                if ( v45 >= v46 )
                {
                  v39 = 0i64;
                  goto LABEL_123;
                }
              }
              goto LABEL_107;
            }
          }
        }
        else
        {
          v40 = (unsigned int)v37[1].vfptr;
          v41 = v37->m_Components.size;
          if ( v40 < v41 )
          {
            v42 = (__int64)&v37->m_Components.p[v40];
            while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v40;
              v42 += 16i64;
              if ( v40 >= v41 )
                goto LABEL_106;
            }
LABEL_107:
            v39 = *(UFG::InventoryComponent **)v42;
            goto LABEL_123;
          }
        }
LABEL_106:
        v39 = 0i64;
        goto LABEL_123;
      }
    }
  }
}

// File Line: 871
// RVA: 0x552A40
void __fastcall UFG::InventoryComponent::Stow(UFG::InventoryComponent *this, int sourceSlot, int destinationSlot)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int64 v5; // rdi
  __int64 v6; // r14
  __int16 m_Flags; // r9
  UFG::CompositeDrawableComponent *v8; // rsi
  UFG::TargetingSystemBaseComponent *m_pComponent; // r15
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v12; // rdx
  unsigned int v13; // r8d
  unsigned int v14; // r9d
  UFG::SimObject *m_pPointer; // r13
  UFG::SimObjectProp *v16; // rcx
  __int16 v17; // dx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int v19; // r9d
  __int64 v20; // rdx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  unsigned int v22; // r8d
  unsigned int v23; // r9d
  unsigned int v24; // r8d
  unsigned int v25; // r9d
  char *v26; // rax
  __int64 SlotTarget; // r12
  UFG::qSymbolUC *v28; // rcx
  char *v29; // rax
  UFG::SimObjectProp *v30; // rcx
  __int16 v31; // dx
  UFG::CharacterAnimationComponent *v32; // rcx
  UFG::CharacterAnimationComponent *v33; // rax
  unsigned int v34; // r8d
  unsigned int v35; // r9d
  __int64 v36; // rdx
  Creature *mCreature; // rbx
  int v38; // ebp
  int BoneID; // r14d
  char *v40; // rbx
  char *v41; // rax
  __int64 v42; // r8
  __int16 v43; // cx
  unsigned int v44; // r8d
  unsigned int v45; // r9d
  __int64 v46; // rdx
  UFG::eTargetTypeEnum eTargetType; // [rsp+80h] [rbp+8h]

  m_pSimObject = this->m_pSimObject;
  v5 = destinationSlot;
  v6 = sourceSlot;
  if ( !m_pSimObject )
    return;
  m_Flags = m_pSimObject->m_Flags;
  v8 = 0i64;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
    goto LABEL_22;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
    goto LABEL_22;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v12 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v12 += 16i64;
        if ( vfptr >= size )
          goto LABEL_12;
      }
LABEL_13:
      m_pComponent = *(UFG::TargetingSystemBaseComponent **)v12;
      goto LABEL_22;
    }
    goto LABEL_12;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v13 = (unsigned int)m_pSimObject[1].vfptr;
    v14 = m_pSimObject->m_Components.size;
    if ( v13 < v14 )
    {
      v12 = (__int64)&m_pSimObject->m_Components.p[v13];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v13;
        v12 += 16i64;
        if ( v13 >= v14 )
        {
          m_pComponent = 0i64;
          goto LABEL_22;
        }
      }
      goto LABEL_13;
    }
LABEL_12:
    m_pComponent = 0i64;
    goto LABEL_22;
  }
  m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pSimObject,
                                                        UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_22:
  if ( !m_pComponent )
    return;
  eTargetType = (unsigned int)UFG::InventoryComponent::GetSlotTarget((UFG::eInventoryEquipSlot)v6);
  m_pPointer = m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[eTargetType]].m_pTarget.m_pPointer;
  if ( !m_pPointer )
  {
    UFG::qPrintf(
      "InventoryComponent::Stow: Source Stow Slot (%s) not found.  Not Stowing!\n",
      UFG::InventoryEquipSlotEnumNames[v6]);
    return;
  }
  v16 = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !v16 )
    goto LABEL_54;
  v17 = v16->m_Flags;
  if ( (v17 & 0x4000) != 0 )
  {
    mComponentTableEntryCount = v16->mComponentTableEntryCount;
    v19 = v16->m_Components.size;
    if ( mComponentTableEntryCount < v19 )
    {
      v20 = (__int64)&v16->m_Components.p[mComponentTableEntryCount];
      while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
      {
        ++mComponentTableEntryCount;
        v20 += 16i64;
        if ( mComponentTableEntryCount >= v19 )
          goto LABEL_32;
      }
LABEL_33:
      ComponentOfType = *(UFG::SimObjectWeaponPropertiesComponent **)v20;
      goto LABEL_51;
    }
  }
  else if ( v17 >= 0 )
  {
    if ( (v17 & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v16);
      goto LABEL_51;
    }
    if ( (v17 & 0x1000) == 0 )
    {
      ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v16,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_51;
    }
    v24 = v16->mComponentTableEntryCount;
    v25 = v16->m_Components.size;
    if ( v24 < v25 )
    {
      v20 = (__int64)&v16->m_Components.p[v24];
      while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v24;
        v20 += 16i64;
        if ( v24 >= v25 )
        {
          ComponentOfType = 0i64;
          goto LABEL_51;
        }
      }
      goto LABEL_33;
    }
  }
  else
  {
    v22 = v16->mComponentTableEntryCount;
    v23 = v16->m_Components.size;
    if ( v22 < v23 )
    {
      v20 = (__int64)&v16->m_Components.p[v22];
      while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v22;
        v20 += 16i64;
        if ( v22 >= v23 )
        {
          ComponentOfType = 0i64;
          goto LABEL_51;
        }
      }
      goto LABEL_33;
    }
  }
LABEL_32:
  ComponentOfType = 0i64;
LABEL_51:
  if ( ComponentOfType && !ComponentOfType->mWeaponTypeInfo->mFireModes[ComponentOfType->mFireMode]->mStowable )
  {
    v26 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pPointer->m_Name);
    UFG::qPrintf(
      "InventoryComponent::Stow: Source Stow Slot (%s-%s) is not Stowable!",
      UFG::InventoryEquipSlotEnumNames[v6],
      v26);
    return;
  }
LABEL_54:
  SlotTarget = (unsigned int)UFG::InventoryComponent::GetSlotTarget((UFG::eInventoryEquipSlot)v5);
  v28 = (UFG::qSymbolUC *)m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[SlotTarget]].m_pTarget.m_pPointer;
  if ( v28 )
  {
    v29 = UFG::qSymbol::as_cstr_dbg(v28 + 18);
    UFG::qPrintf(
      "InventoryComponent::Stow: Destination Stow Slot (%s) is not empty.  Contains: %s.  Not Stowing!\n",
      UFG::InventoryEquipSlotEnumNames[v5],
      v29);
    return;
  }
  v30 = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !v30 )
    goto LABEL_81;
  v31 = v30->m_Flags;
  if ( (v31 & 0x4000) != 0 )
  {
    v32 = (UFG::CharacterAnimationComponent *)v30->m_Components.p[9].m_pComponent;
    if ( !v32
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_61;
    }
    goto LABEL_79;
  }
  if ( v31 < 0 )
  {
    v32 = (UFG::CharacterAnimationComponent *)v30->m_Components.p[9].m_pComponent;
    if ( !v32 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_61;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
      v32 = 0i64;
    goto LABEL_79;
  }
  if ( (v31 & 0x2000) != 0 )
  {
    v33 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v30);
LABEL_78:
    v32 = v33;
    goto LABEL_79;
  }
  if ( (v31 & 0x1000) == 0 )
  {
    v33 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                v30,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_78;
  }
  v34 = v30->mComponentTableEntryCount;
  v35 = v30->m_Components.size;
  if ( v34 >= v35 )
  {
LABEL_61:
    v32 = 0i64;
    goto LABEL_79;
  }
  v36 = (__int64)&v30->m_Components.p[v34];
  while ( (*(_DWORD *)(v36 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v36 + 8) & 0x1FFFFFF) != 0 )
  {
    ++v34;
    v36 += 16i64;
    if ( v34 >= v35 )
    {
      v32 = 0i64;
      goto LABEL_79;
    }
  }
  v32 = *(UFG::CharacterAnimationComponent **)v36;
LABEL_79:
  if ( v32 )
  {
    mCreature = v32->mCreature;
    goto LABEL_82;
  }
LABEL_81:
  mCreature = 0i64;
LABEL_82:
  if ( mCreature )
  {
    v38 = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, *(&stru_14240E4C4.mUID + 2 * v6));
    else
      BoneID = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      v38 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, *(&stru_14240E4C4.mUID + 2 * destinationSlot));
    if ( BoneID >= 0 && v38 >= 0 && !Creature::TransferAttachment(mCreature, BoneID, v38, &gStaticSymbolUC_none) )
    {
      v40 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(0x140000000i64 + 8i64 * destinationSlot + 37807300));
      v41 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(0x140000000i64 + 8i64 * sourceSlot + 37807300));
      UFG::qPrintf("Attachment Was Not Transferred! (%s -> %s)", v41, v40);
    }
    UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, SlotTarget, m_pPointer);
    LOBYTE(v42) = 1;
    ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, __int64, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
      m_pComponent,
      (unsigned int)SlotTarget,
      v42,
      0i64,
      0,
      0i64,
      0i64,
      0i64);
    UFG::TargetingSystemBaseComponent::ClearTarget(m_pComponent, eTargetType);
    v43 = m_pPointer->m_Flags;
    if ( (v43 & 0x4000) != 0 )
    {
      v8 = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[14].m_pComponent;
    }
    else if ( v43 >= 0 )
    {
      if ( (v43 & 0x2000) != 0 )
      {
        v8 = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[9].m_pComponent;
      }
      else if ( (v43 & 0x1000) != 0 )
      {
        v44 = (unsigned int)m_pPointer[1].vfptr;
        v45 = m_pPointer->m_Components.size;
        if ( v44 < v45 )
        {
          v46 = (__int64)&m_pPointer->m_Components.p[v44];
          while ( (*(_DWORD *)(v46 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
               || (UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v46 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v44;
            v46 += 16i64;
            if ( v44 >= v45 )
              goto LABEL_107;
          }
          v8 = *(UFG::CompositeDrawableComponent **)v46;
        }
      }
      else
      {
        v8 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      v8 = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[14].m_pComponent;
    }
LABEL_107:
    if ( v8 )
      UFG::CompositeDrawableComponent::SetIsHidden(v8, 1);
  }
}                                m_pPointer,
                                         

// File Line: 935
// RVA: 0x52AEC0
_BOOL8 __fastcall UFG::InventoryComponent::GetCanDrop(UFG::InventoryComponent *this, UFG::eInventoryEquipSlot slot)
{
  return this->m_EquipSlots.p[slot].mCanDrop;
}

// File Line: 941
// RVA: 0x54BF30
void __fastcall UFG::InventoryComponent::SetCanDrop(
        UFG::InventoryComponent *this,
        UFG::eInventoryEquipSlot slot,
        bool canDrop)
{
  this->m_EquipSlots.p[slot].mCanDrop = canDrop;
}

// File Line: 964
// RVA: 0x569EB0
void __fastcall UFG::InventoryComponent::EquipInfo::init(
        UFG::InventoryComponent::EquipInfo *this,
        UFG::SimObject *pProp,
        bool useEquipSlot,
        UFG::eInventoryEquipSlot inventoryEquipSlot)
{
  __int64 v5; // rdx
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rdi
  char *v8; // rax
  char *v9; // rax
  UFG::qSymbol *v10; // rax
  UFG::qSymbolUC *v11; // rdi
  UFG::eTargetTypeEnum EnumFromSymbol; // eax
  char *v13; // rax
  UFG::qSymbolUC result; // [rsp+40h] [rbp+18h] BYREF

  if ( useEquipSlot )
  {
    v5 = 8i64 * (int)inventoryEquipSlot;
    this->mPropBoneUID = *(UFG::qSymbolUC *)((char *)&inventoryEquipSlotAttachments + v5);
    this->mCharacterBoneUID = *(UFG::qSymbolUC *)((char *)&inventoryEquipSlotAttachments + v5 + 4);
    this->mEquipTarget = UFG::InventoryComponent::GetSlotTarget(inventoryEquipSlot);
  }
  else
  {
    this->mPropBoneUID = inventoryEquipSlotAttachments;
    this->mCharacterBoneUID = stru_14240E4C4;
    this->mEquipTarget = eTARGET_TYPE_EQUIPPED;
    if ( pProp )
    {
      m_pSceneObj = pProp->m_pSceneObj;
      if ( m_pSceneObj )
      {
        mpWritableProperties = m_pSceneObj->mpWritableProperties;
        if ( !mpWritableProperties )
          mpWritableProperties = m_pSceneObj->mpConstProperties;
      }
      else
      {
        mpWritableProperties = 0i64;
      }
      v8 = UFG::qPropertySet::Get<char const *>(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&qSymbol_PropBone,
             DEPTH_RECURSE);
      if ( v8 )
        this->mPropBoneUID = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, v8)->mUID;
      v9 = UFG::qPropertySet::Get<char const *>(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&qSymbol_AttachBone,
             DEPTH_RECURSE);
      if ( v9 )
        this->mCharacterBoneUID = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, v9)->mUID;
      v10 = UFG::qPropertySet::Get<UFG::qSymbol>(
              mpWritableProperties,
              (UFG::qArray<unsigned long,0> *)&qSymbol_EquipTarget,
              DEPTH_RECURSE);
      v11 = (UFG::qSymbolUC *)v10;
      if ( v10 )
      {
        EnumFromSymbol = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gTargetTypeEnum, v10);
        if ( EnumFromSymbol < eTARGET_TYPE_EQUIPPED
          || EnumFromSymbol > eTARGET_TYPE_EQUIPPED_GLASSES
          && (unsigned int)(EnumFromSymbol - eTARGET_TYPE_STOWED_WEAPON) > 1 )
        {
          v13 = UFG::qSymbol::as_cstr_dbg(v11);
          UFG::qPrintf("InventoryComponent::GetAttachmentInfo: Invalid EquipTarget: %s", v13);
        }
        else
        {
          this->mEquipTarget = EnumFromSymbol;
        }
      }
    }
  }
}

