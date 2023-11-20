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
  return atexit(UFG::_dynamic_atexit_destructor_for__inventoryEquipSlotAttachments__);
}

// File Line: 70
// RVA: 0x1543F20
__int64 dynamic_initializer_for__UFG::InventoryComponent::s_InventoryComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::InventoryComponent::s_InventoryComponentList__);
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
  signed __int64 v1; // rcx

  v0 = UFG::InventoryComponent::ms_InventoryItemInfos;
  v1 = 13i64;
  do
  {
    *(_QWORD *)&v0->m_iCapacity = 4294967297i64;
    *(_QWORD *)&v0[2].m_iCapacity = 4294967297i64;
    *(_QWORD *)&v0[4].m_iCapacity = 4294967297i64;
    v0 += 16;
    *(_QWORD *)&v0[-10].m_iCapacity = 4294967297i64;
    *(_QWORD *)&v0[-8].m_iCapacity = 4294967297i64;
    *(_QWORD *)&v0[-6].m_iCapacity = 4294967297i64;
    *(_QWORD *)&v0[-4].m_iCapacity = 4294967297i64;
    *(_QWORD *)&v0[-2].m_iCapacity = 4294967297i64;
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
  UFG::InventoryComponent *v2; // rbx
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v3; // rdx
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InventoryComponent::`vftable';
  *(_DWORD *)&v2->m_EquipSlots.p[0].mCanDrop = 16843009;
  *(_WORD *)&v2->m_EquipSlots.p[4].mCanDrop = 257;
  v2->m_EquipSlots.size = 0;
  v2->m_SellableItem = 0;
  v2->m_SellableItemProp = UFG::gNullQSymbol;
  *(_WORD *)&v2->m_InfiniteSellableItem = 0;
  v2->m_bDebugDrawInventory = 0;
  v4 = UFG::InventoryComponent::s_InventoryComponentList.mNode.mPrev;
  UFG::InventoryComponent::s_InventoryComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *)&UFG::InventoryComponent::s_InventoryComponentList;
  UFG::InventoryComponent::s_InventoryComponentList.mNode.mPrev = (UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::InventoryComponent::_InventoryComponentTypeUID,
    "InventoryComponent");
  v2->m_EquipSlots.size = 6;
  UFG::qMemSet(v2->m_InventoryItems, 0, 0x344u);
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
  UFG::InventoryComponent *v1; // r8
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v2; // rdx
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v3; // rcx
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v4; // rax
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v5; // rcx
  UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InventoryComponent::`vftable';
  if ( this == UFG::InventoryComponent::s_InventoryComponentpCurrentIterator )
    UFG::InventoryComponent::s_InventoryComponentpCurrentIterator = (UFG::InventoryComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::InventoryComponent,UFG::InventoryComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->m_EquipSlots.size = 0;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 145
// RVA: 0x1549A40
__int64 UFG::_dynamic_initializer_for__gsymInventory__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Inventory", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymInventory, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymInventory__);
}

// File Line: 146
// RVA: 0x1549A80
__int64 UFG::_dynamic_initializer_for__gsymRange__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Range", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymRange, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymRange__);
}

// File Line: 147
// RVA: 0x1549B00
__int64 UFG::_dynamic_initializer_for__gsymValue__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Value", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymValue, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymValue__);
}

// File Line: 151
// RVA: 0x546780
UFG::InventoryComponent *__fastcall UFG::InventoryComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rsi
  UFG::InventoryComponent *v3; // rbx
  UFG::qMemoryPool *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::InventoryComponent *v6; // rax
  UFG::qPropertySet *v7; // rcx
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::InventoryComponent *v10; // rax
  UFG::SimObject *v11; // rdx
  unsigned int v12; // edi
  UFG::qPropertySet *v13; // rdx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = 0i64;
  if ( required )
  {
    v4 = UFG::GetSimulationMemoryPool();
    v5 = UFG::qMemoryPool::Allocate(v4, 0x3B0ui64, "InventoryComponent", 0i64, 1u);
    if ( v5 )
    {
      UFG::InventoryComponent::InventoryComponent((UFG::InventoryComponent *)v5, v2->m_NameUID);
      v3 = v6;
    }
LABEL_10:
    if ( v3 )
    {
      v11 = v2->m_pSimObject;
      if ( (v11->m_Flags >> 14) & 1 )
        v12 = 39;
      else
        v12 = -1;
      UFG::SimObjectModifier::SimObjectModifier(&v15, v11, 1);
      UFG::SimObjectModifier::AttachComponent(&v15, (UFG::SimComponent *)&v3->vfptr, v12);
      UFG::SimObjectModifier::Close(&v15);
      UFG::SimObjectModifier::~SimObjectModifier(&v15);
      v13 = v2->mpWritableProperties;
      if ( !v13 )
        v13 = v2->mpConstProperties;
      UFG::InventoryComponent::ResetFromProperties(v3, v13);
    }
    return v3;
  }
  v7 = pSceneObj->mpWritableProperties;
  if ( !v7 )
    v7 = v2->mpConstProperties;
  if ( UFG::qPropertySet::GetParentFromName(v7, (UFG::qSymbol *)&SimSymX_propset_componentInventory.mUID, DEPTH_RECURSE) )
  {
    v8 = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(v8, 0x3B0ui64, "InventoryComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::InventoryComponent::InventoryComponent((UFG::InventoryComponent *)v9, v2->m_NameUID);
      v3 = v10;
    }
    goto LABEL_10;
  }
  return v3;
}

// File Line: 197
// RVA: 0x520AB0
void __fastcall UFG::InventoryComponent::AddInventoryList(UFG::InventoryComponent *this, UFG::qPropertyList *inventory_list)
{
  unsigned int v2; // er12
  unsigned int v3; // er15
  UFG::qPropertyList *v4; // r13
  UFG::InventoryComponent *v5; // rsi
  char *v6; // rax
  UFG::qPropertySet *v7; // rbp
  UFG::eInventoryItemEnum v8; // edi
  signed __int64 v9; // rbx
  int *v10; // r14
  int *v11; // rax
  float v12; // xmm0_4
  int v13; // ecx
  float v14; // xmm0_4
  int v15; // edx

  v2 = inventory_list->mNumElements;
  v3 = 0;
  v4 = inventory_list;
  v5 = this;
  if ( v2 )
  {
    while ( 1 )
    {
      v6 = UFG::qPropertyList::GetValuePtr(v4, 0x1Au, v3);
      if ( v6 && *(_QWORD *)v6 )
        v7 = (UFG::qPropertySet *)&v6[*(_QWORD *)v6];
      else
        v7 = 0i64;
      v8 = 0;
      v9 = 0i64;
      while ( v7->mName.mUID != UFG::InventoryItemEnumSymbols[v9].mUID )
      {
        ++v9;
        ++v8;
        if ( v9 >= 209 )
          goto LABEL_29;
      }
      if ( v8 == 209 )
        goto LABEL_29;
      v10 = UFG::qPropertySet::Get<long>(v7, (UFG::qSymbol *)&UFG::gsymRange.mUID, DEPTH_RECURSE);
      v11 = UFG::qPropertySet::Get<long>(v7, (UFG::qSymbol *)&UFG::gsymValue.mUID, DEPTH_RECURSE);
      if ( v10 )
        break;
      if ( v11 )
      {
        v15 = *v11;
        v5->m_InventoryItems[v9].m_iQuantity = *v11;
        goto LABEL_17;
      }
      v5->m_InventoryItems[v9].m_iQuantity = 0;
      if ( (UFG::SimObjectCharacter *)v5->m_pSimObject == LocalPlayer )
      {
        v15 = v5->m_InfiniteSellableItem && v8 == v5->m_SellableItem;
        goto LABEL_28;
      }
LABEL_29:
      if ( ++v3 >= v2 )
        return;
    }
    v12 = (float)(*v11 - *v10 / 2);
    if ( v12 <= 0.0 )
      v12 = 0.0;
    v13 = (signed int)v12;
    v14 = (float)(*v11 + *v10 / 2);
    if ( v14 <= 0.0 )
      v14 = 0.0;
    v15 = UFG::GetRandomNumberInRange(v13, (signed int)v14);
    v5->m_InventoryItems[v9].m_iQuantity = v15;
LABEL_17:
    if ( (UFG::SimObjectCharacter *)v5->m_pSimObject == LocalPlayer )
    {
      if ( v5->m_InfiniteSellableItem )
      {
        if ( v8 == v5->m_SellableItem )
          v15 = 1;
      }
LABEL_28:
      UFG::GameStatAction::Inventory::UpdateItem(v8, v15);
      goto LABEL_29;
    }
    goto LABEL_29;
  }
}

// File Line: 245
// RVA: 0x549E90
void __fastcall UFG::InventoryComponent::ResetFromProperties(UFG::InventoryComponent *this, UFG::qPropertySet *pProps)
{
  UFG::qPropertySet *v2; // rdi
  UFG::InventoryComponent *v3; // rbx
  UFG::qPropertyList *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  UFG::qSymbol *v9; // rax
  unsigned int v10; // eax
  bool *v11; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v2 = pProps;
  v3 = this;
  UFG::qMemSet(this->m_InventoryItems, 0, 0x344u);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&UFG::gsymInventory.mUID, DEPTH_RECURSE);
  if ( v4 )
    UFG::InventoryComponent::AddInventoryList(v3, v4);
  v5 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&SimSym_SellableItem.mUID, DEPTH_RECURSE);
  if ( v5 )
  {
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v6 = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v6;
      pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v3->m_SellableItem = pTrackEnumBinding.m_EnumValue;
    v7 = pTrackEnumBinding.mPrev;
    v8 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v8->mPrev = v7;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v9 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&SimSym_SellableItemProp.mUID, DEPTH_RECURSE);
  if ( v9 )
    v10 = v9->mUID;
  else
    v10 = UFG::gNullQSymbol.mUID;
  v3->m_SellableItemProp.mUID = v10;
  v11 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_InfiniteSellableItem.mUID, DEPTH_RECURSE);
  if ( v11 )
    v3->m_InfiniteSellableItem = *v11;
}

// File Line: 303
// RVA: 0x53E410
void __fastcall UFG::InventoryComponent::OnAttach(UFG::InventoryComponent *this, UFG::SimObject *pObject)
{
  UFG::IsAnyLocalPlayer(pObject);
}

// File Line: 377
// RVA: 0x521290
char __usercall UFG::InventoryComponent::AddQuantity@<al>(UFG::InventoryComponent *this@<rcx>, UFG::eInventoryItemEnum eInventoryItem@<edx>, const int iQuantity@<r8d>, __int64 a4@<r15>)
{
  UFG::eInventoryItemEnum v4; // ebx
  UFG::InventoryComponent *v5; // rbp
  signed int v6; // edi
  __int64 v7; // r12
  int v8; // er14
  char v9; // r15
  int v10; // esi
  char *v11; // rdx
  bool v12; // zf
  bool v13; // sf
  char *v14; // rdx
  __int64 v16; // [rsp+20h] [rbp-18h]

  v4 = eInventoryItem;
  v5 = this;
  if ( eInventoryItem == eINVENTORY_ITEM_INVALID || (signed int)eInventoryItem >= 209 )
    return 0;
  v6 = UFG::InventoryComponent::ms_InventoryItemInfos[eInventoryItem].m_iCapacity;
  v7 = eInventoryItem;
  v8 = 0;
  v16 = a4;
  v9 = 1;
  v10 = iQuantity + this->m_InventoryItems[v7].m_iQuantity;
  if ( v10 > v6 )
  {
    if ( (UFG::gInventoryItemTracksEnum.m_enumLists.size & 0x80000000) != 0 )
      v11 = 0i64;
    else
      v11 = (*UFG::gInventoryItemTracksEnum.m_enumLists.p)->m_enumName.p[eInventoryItem];
    UFG::qPrintf(
      "WARNING: InventoryItem: %s -> More Quantity than Capacity! (%d/%d)\n",
      v11,
      (unsigned int)v10,
      (unsigned int)v6,
      v16);
LABEL_13:
    v9 = 0;
    v12 = v10 == 0;
    v13 = v10 < 0;
    goto LABEL_14;
  }
  v12 = v10 == 0;
  v13 = v10 < 0;
  if ( v10 < 0 )
  {
    if ( (UFG::gInventoryItemTracksEnum.m_enumLists.size & 0x80000000) != 0 )
      v14 = 0i64;
    else
      v14 = (*UFG::gInventoryItemTracksEnum.m_enumLists.p)->m_enumName.p[eInventoryItem];
    UFG::qPrintf("WARNING: InventoryItem: %s -> Less Than Zero Quantity! (%d)\n", v14, (unsigned int)v10);
    goto LABEL_13;
  }
LABEL_14:
  if ( !v13 && !v12 )
    v8 = v10;
  if ( v8 < v6 )
    v6 = v8;
  v5->m_InventoryItems[v7].m_iQuantity = v6;
  if ( (UFG::SimObjectCharacter *)v5->m_pSimObject == LocalPlayer )
  {
    if ( v5->m_InfiniteSellableItem )
    {
      if ( v4 == v5->m_SellableItem )
        v6 = 1;
    }
    UFG::GameStatAction::Inventory::UpdateItem(v4, v6);
  }
  return v9;
}

// File Line: 417
// RVA: 0x5495C0
__int64 __usercall UFG::InventoryComponent::RemoveQuantity@<rax>(UFG::InventoryComponent *this@<rcx>, UFG::eInventoryItemEnum eInventoryItem@<edx>, const int iQuantity@<r8d>, __int64 a4@<r15>)
{
  UFG::InventoryComponent *v4; // rax
  UFG::eInventoryItemEnum v5; // ecx
  unsigned int v6; // ebx
  int v8; // ecx

  v4 = this;
  v5 = this->m_SellableItem;
  v6 = iQuantity;
  if ( eInventoryItem == v5 )
  {
    if ( v4->m_InfiniteSellableItem )
      return 0i64;
    goto LABEL_7;
  }
  if ( !v4->m_InfiniteSellableItem || eInventoryItem != v5 )
  {
LABEL_7:
    v8 = v4->m_InventoryItems[eInventoryItem].m_iQuantity;
    goto LABEL_8;
  }
  v8 = 1;
LABEL_8:
  if ( v8 < iQuantity )
    v6 = v8;
  UFG::InventoryComponent::AddQuantity(v4, eInventoryItem, -v6, a4);
  return v6;
}

// File Line: 430
// RVA: 0x55F840
void __fastcall UFG::InventoryComponent::UpdateGameStat(UFG::InventoryComponent *this, UFG::eInventoryItemEnum eInventoryItem)
{
  __int64 v2; // r8
  signed int v3; // edx

  v2 = eInventoryItem;
  if ( (UFG::SimObjectCharacter *)this->m_pSimObject == LocalPlayer )
  {
    if ( !this->m_InfiniteSellableItem || (v3 = 1, (_DWORD)v2 != this->m_SellableItem) )
      v3 = this->m_InventoryItems[v2].m_iQuantity;
    UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)v2, v3);
  }
}

// File Line: 438
// RVA: 0x520C70
char __usercall UFG::InventoryComponent::AddObjectToInventory@<al>(UFG::InventoryComponent *this@<rcx>, UFG::SimObject *pObject@<rdx>, const bool bForceObjectToInventory@<r8b>, __int64 a4@<r15>)
{
  bool v4; // si
  UFG::SimObjectProp *v5; // rbx
  UFG::InventoryComponent *v6; // rbp
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rdi
  unsigned int v9; // ecx
  unsigned int v10; // er9
  UFG::SimComponentHolder *v11; // rdi
  UFG::eInventoryItemEnum v12; // edx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  unsigned __int16 v17; // cx
  unsigned int v18; // ecx
  unsigned int v19; // er9
  UFG::SimComponentHolder *v20; // rdi
  signed __int64 v21; // r8
  UFG::SimObjectWeaponPropertiesComponent *v22; // rdi
  unsigned int v23; // ecx
  unsigned int v24; // er9
  UFG::SimObjectWeaponPropertiesComponent *v25; // rax
  unsigned int v26; // ecx
  unsigned int v27; // er9
  unsigned __int16 v28; // cx
  unsigned int v29; // ecx
  unsigned int v30; // er9
  UFG::SimComponentHolder *v31; // rsi
  signed __int64 v32; // r8
  UFG::GunComponent *v33; // rax
  unsigned int v34; // ecx
  unsigned int v35; // er9
  unsigned int v36; // ecx
  unsigned int v37; // er9
  unsigned int v38; // ecx
  unsigned int v39; // er9
  unsigned __int16 v40; // cx
  UFG::SimComponent *v41; // rcx
  UFG::qPropertySet *v42; // rax
  UFG::qWiseSymbol *v43; // rbx
  unsigned int v44; // ecx
  UFG::qSymbolUC *v45; // rax
  char *v46; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp+10h]

  v4 = bForceObjectToInventory;
  v5 = (UFG::SimObjectProp *)pObject;
  v6 = this;
  if ( !pObject )
    return 0;
  v7 = pObject->m_Flags;
  if ( (v7 >> 14) & 1 || (v7 & 0x8000u) != 0 )
    return 0;
  if ( (v7 >> 13) & 1 )
  {
    v8 = v5->m_Components.p[11].m_pComponent;
  }
  else if ( (v7 >> 12) & 1 )
  {
    v9 = v5->mComponentTableEntryCount;
    v10 = v5->m_Components.size;
    if ( v9 >= v10 )
    {
LABEL_14:
      v8 = 0i64;
    }
    else
    {
      v11 = v5->m_Components.p;
      while ( (v11[v9].m_TypeUID & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
           || UFG::InventoryItemComponent::_TypeUID & ~v11[v9].m_TypeUID & 0x1FFFFFF )
      {
        if ( ++v9 >= v10 )
          goto LABEL_14;
      }
      v8 = v11[v9].m_pComponent;
    }
  }
  else
  {
    v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::InventoryItemComponent::_TypeUID);
  }
  if ( !v8 )
    return 0;
  v12 = (UFG::eInventoryItemEnum)v8[1].m_pSimObject;
  if ( v12 == eINVENTORY_ITEM_INVALID
    || !UFG::InventoryComponent::AddQuantity(v6, v12, (const int)v8[1].m_BoundComponentHandles.mNode.mPrev, a4) && !v4 )
  {
    return 0;
  }
  v13 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)((char *)&v8[1].m_SafePointerList.mNode
                                                                                         + 8);
  if ( *(_QWORD *)&v8[1].m_Flags )
  {
    v14 = v13->mPrev;
    v15 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&v8[1].m_TypeUID;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = v13;
    *(_QWORD *)&v8[1].m_TypeUID = (char *)v8 + 80;
  }
  *(_QWORD *)&v8[1].m_Flags = v6;
  if ( v6 )
  {
    v16 = v6->m_SafePointerList.mNode.mPrev;
    v16->mNext = v13;
    v13->mPrev = v16;
    *(_QWORD *)&v8[1].m_TypeUID = (char *)v6 + 8;
    v6->m_SafePointerList.mNode.mPrev = v13;
  }
  v17 = v5->m_Flags;
  if ( !((v17 >> 14) & 1) )
  {
    if ( (v17 & 0x8000u) != 0 )
    {
      v23 = v5->mComponentTableEntryCount;
      v24 = v5->m_Components.size;
      if ( v23 < v24 )
      {
        v20 = v5->m_Components.p;
        do
        {
          v21 = v23;
          if ( (v20[v23].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
            && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v20[v23].m_TypeUID & 0x1FFFFFF) )
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
    if ( (v17 >> 13) & 1 )
    {
      v25 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v5);
    }
    else
    {
      if ( (v17 >> 12) & 1 )
      {
        v26 = v5->mComponentTableEntryCount;
        v27 = v5->m_Components.size;
        if ( v26 < v27 )
        {
          v20 = v5->m_Components.p;
          while ( 1 )
          {
            v21 = v26;
            if ( (v20[v26].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
              && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v20[v26].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_31;
            }
            if ( ++v26 >= v27 )
              goto LABEL_32;
          }
        }
        goto LABEL_32;
      }
      v25 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v5->vfptr,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    }
    v22 = v25;
    goto LABEL_51;
  }
  v18 = v5->mComponentTableEntryCount;
  v19 = v5->m_Components.size;
  if ( v18 >= v19 )
    goto LABEL_32;
  v20 = v5->m_Components.p;
  while ( 1 )
  {
    v21 = v18;
    if ( (v20[v18].m_TypeUID & 0xFE000000) == (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
      && !(UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~v20[v18].m_TypeUID & 0x1FFFFFF) )
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
    v28 = v5->m_Flags;
    if ( (v28 >> 14) & 1 )
    {
      v29 = v5->mComponentTableEntryCount;
      v30 = v5->m_Components.size;
      if ( v29 < v30 )
      {
        v31 = v5->m_Components.p;
        while ( 1 )
        {
          v32 = v29;
          if ( (v31[v29].m_TypeUID & 0xFE000000) == (UFG::GunComponent::_TypeUID & 0xFE000000)
            && !(UFG::GunComponent::_TypeUID & ~v31[v29].m_TypeUID & 0x1FFFFFF) )
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
    else if ( (v28 & 0x8000u) == 0 )
    {
      if ( (v28 >> 13) & 1 )
      {
        v36 = v5->mComponentTableEntryCount;
        v37 = v5->m_Components.size;
        if ( v36 < v37 )
        {
          v31 = v5->m_Components.p;
          do
          {
            v32 = v36;
            if ( (v31[v36].m_TypeUID & 0xFE000000) == (UFG::GunComponent::_TypeUID & 0xFE000000)
              && !(UFG::GunComponent::_TypeUID & ~v31[v36].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_60;
            }
          }
          while ( ++v36 < v37 );
        }
      }
      else
      {
        if ( !((v28 >> 12) & 1) )
        {
          v33 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                       (UFG::SimObject *)&v5->vfptr,
                                       UFG::GunComponent::_TypeUID);
LABEL_84:
          if ( v33 )
            UFG::GunComponent::InitializeGunIntoInventory(v33);
          goto LABEL_86;
        }
        v38 = v5->mComponentTableEntryCount;
        v39 = v5->m_Components.size;
        if ( v38 < v39 )
        {
          v31 = v5->m_Components.p;
          do
          {
            v32 = v38;
            if ( (v31[v38].m_TypeUID & 0xFE000000) == (UFG::GunComponent::_TypeUID & 0xFE000000)
              && !(UFG::GunComponent::_TypeUID & ~v31[v38].m_TypeUID & 0x1FFFFFF) )
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
      v34 = v5->mComponentTableEntryCount;
      v35 = v5->m_Components.size;
      if ( v34 < v35 )
      {
        v31 = v5->m_Components.p;
        do
        {
          v32 = v34;
          if ( (v31[v34].m_TypeUID & 0xFE000000) == (UFG::GunComponent::_TypeUID & 0xFE000000)
            && !(UFG::GunComponent::_TypeUID & ~v31[v34].m_TypeUID & 0x1FFFFFF) )
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
  if ( (UFG::SimObjectCharacter *)v6->m_pSimObject == LocalPlayer )
  {
    v40 = v5->m_Flags;
    if ( (v40 >> 14) & 1 )
    {
      v41 = v5->m_Components.p[1].m_pComponent;
    }
    else if ( (v40 & 0x8000u) == 0 )
    {
      if ( (v40 >> 13) & 1 )
        v41 = v5->m_Components.p[1].m_pComponent;
      else
        v41 = (v40 >> 12) & 1 ? v5->m_Components.p->m_pComponent : v5->m_pSceneObj;
    }
    else
    {
      v41 = v5->m_Components.p[1].m_pComponent;
    }
    if ( v41 )
    {
      v42 = (UFG::qPropertySet *)v41[2].m_SafePointerList.mNode.mNext;
      if ( !v42 )
        v42 = *(UFG::qPropertySet **)&v41[2].m_TypeUID;
      v43 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v42, (UFG::qSymbol *)&qSymbol_AudioWeaponType.mUID, DEPTH_RECURSE);
      if ( v43 )
      {
        v44 = _S66;
        if ( !(_S66 & 1) )
        {
          _S66 |= 1u;
          attack_type_switch = UFG::TiDo::CalcWwiseUid("attack_types");
          v44 = _S66;
        }
        if ( !(v44 & 2) )
        {
          _S66 = v44 | 2;
          play_weapon_pickup = UFG::TiDo::CalcWwiseUid("Play_pickups");
        }
        UFG::AudioEntity::SetWwiseSwitch(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          attack_type_switch,
          v43->mUID);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            play_weapon_pickup,
            0i64,
            0,
            0i64);
      }
      else if ( v22 )
      {
        v45 = (UFG::qSymbolUC *)UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(v22, &result);
        v46 = UFG::qSymbol::as_cstr_dbg(v45);
        UFG::qPrintf("AudioWeaponType not defined for: '%s'\n", v46);
      }
    }
  }
  return 1;
}

// File Line: 499
// RVA: 0x549120
void __usercall UFG::InventoryComponent::RemoveObjectFromInventory(UFG::InventoryComponent *this@<rcx>, UFG::SimObject *pObject@<rdx>, __int64 a3@<r15>)
{
  UFG::SimObjectProp *v3; // rbx
  unsigned __int16 v4; // dx
  UFG::InventoryComponent *v5; // rsi
  UFG::SimComponent *v6; // rdi
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx
  unsigned __int16 v10; // dx
  unsigned int v11; // er8
  unsigned int v12; // er9
  signed __int64 v13; // rdx
  UFG::SimObjectWeaponPropertiesComponent *v14; // rax
  unsigned int v15; // er8
  unsigned int v16; // er9
  unsigned int v17; // er8
  unsigned int v18; // er9
  unsigned __int16 v19; // cx
  unsigned int v20; // er8
  unsigned int v21; // er9
  signed __int64 v22; // rdx
  UFG::GunComponent *v23; // rax
  unsigned int v24; // er8
  unsigned int v25; // er9
  unsigned int v26; // er8
  unsigned int v27; // er9
  unsigned int v28; // er8
  unsigned int v29; // er9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **v30; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax

  if ( pObject )
  {
    v3 = (UFG::SimObjectProp *)pObject;
    v4 = pObject->m_Flags;
    v5 = this;
    if ( !((v4 >> 14) & 1) && (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = v3->m_Components.p[11].m_pComponent;
      }
      else if ( (v4 >> 12) & 1 )
      {
        v7 = v3->mComponentTableEntryCount;
        v8 = v3->m_Components.size;
        if ( v7 >= v8 )
        {
LABEL_12:
          v6 = 0i64;
        }
        else
        {
          v9 = (signed __int64)&v3->m_Components.p[v7];
          while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
               || UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
          {
            ++v7;
            v9 += 16i64;
            if ( v7 >= v8 )
              goto LABEL_12;
          }
          v6 = *(UFG::SimComponent **)v9;
        }
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InventoryItemComponent::_TypeUID);
      }
      if ( v6 && LODWORD(v6[1].m_pSimObject) )
      {
        v10 = v3->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v11 = v3->mComponentTableEntryCount;
          v12 = v3->m_Components.size;
          if ( v11 < v12 )
          {
            v13 = (signed __int64)&v3->m_Components.p[v11];
            while ( (*(_DWORD *)(v13 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                 || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v13 + 8) & 0x1FFFFFF )
            {
              ++v11;
              v13 += 16i64;
              if ( v11 >= v12 )
                goto LABEL_23;
            }
LABEL_24:
            v14 = *(UFG::SimObjectWeaponPropertiesComponent **)v13;
            goto LABEL_42;
          }
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
          {
            v14 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v3);
            goto LABEL_42;
          }
          if ( !((v10 >> 12) & 1) )
          {
            v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v3->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
            goto LABEL_42;
          }
          v17 = v3->mComponentTableEntryCount;
          v18 = v3->m_Components.size;
          if ( v17 < v18 )
          {
            v13 = (signed __int64)&v3->m_Components.p[v17];
            while ( (*(_DWORD *)(v13 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                 || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v13 + 8) & 0x1FFFFFF )
            {
              ++v17;
              v13 += 16i64;
              if ( v17 >= v18 )
              {
                v14 = 0i64;
                goto LABEL_42;
              }
            }
            goto LABEL_24;
          }
        }
        else
        {
          v15 = v3->mComponentTableEntryCount;
          v16 = v3->m_Components.size;
          if ( v15 < v16 )
          {
            v13 = (signed __int64)&v3->m_Components.p[v15];
            while ( (*(_DWORD *)(v13 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                 || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v13 + 8) & 0x1FFFFFF )
            {
              ++v15;
              v13 += 16i64;
              if ( v15 >= v16 )
              {
                v14 = 0i64;
                goto LABEL_42;
              }
            }
            goto LABEL_24;
          }
        }
LABEL_23:
        v14 = 0i64;
LABEL_42:
        if ( !v14 || v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mAmmoInventoryItem == eINVENTORY_ITEM_INVALID )
        {
LABEL_76:
          UFG::InventoryComponent::RemoveQuantity(
            v5,
            (UFG::eInventoryItemEnum)v6[1].m_pSimObject,
            (const int)v6[1].m_BoundComponentHandles.mNode.mPrev,
            a3);
          v30 = &v6[1].m_SafePointerList.mNode.mNext;
          if ( *(_QWORD *)&v6[1].m_Flags )
          {
            v31 = *v30;
            v32 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&v6[1].m_TypeUID;
            v31->mNext = v32;
            v32->mPrev = v31;
            *v30 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v30;
            *(_QWORD *)&v6[1].m_TypeUID = (char *)v6 + 80;
          }
          *(_QWORD *)&v6[1].m_Flags = 0i64;
          return;
        }
        v19 = v3->m_Flags;
        if ( (v19 >> 14) & 1 )
        {
          v20 = v3->mComponentTableEntryCount;
          v21 = v3->m_Components.size;
          if ( v20 < v21 )
          {
            v22 = (signed __int64)&v3->m_Components.p[v20];
            while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
                 || UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
            {
              ++v20;
              v22 += 16i64;
              if ( v20 >= v21 )
                goto LABEL_50;
            }
LABEL_51:
            v23 = *(UFG::GunComponent **)v22;
            goto LABEL_74;
          }
        }
        else if ( (v19 & 0x8000u) == 0 )
        {
          if ( (v19 >> 13) & 1 )
          {
            v26 = v3->mComponentTableEntryCount;
            v27 = v3->m_Components.size;
            if ( v26 < v27 )
            {
              v22 = (signed __int64)&v3->m_Components.p[v26];
              while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
                   || UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
              {
                ++v26;
                v22 += 16i64;
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
            if ( !((v19 >> 12) & 1) )
            {
              v23 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::GunComponent::_TypeUID);
LABEL_74:
              if ( v23 )
                UFG::GunComponent::RemoveGunFromInventory(v23);
              goto LABEL_76;
            }
            v28 = v3->mComponentTableEntryCount;
            v29 = v3->m_Components.size;
            if ( v28 < v29 )
            {
              v22 = (signed __int64)&v3->m_Components.p[v28];
              while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
                   || UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
              {
                ++v28;
                v22 += 16i64;
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
          v24 = v3->mComponentTableEntryCount;
          v25 = v3->m_Components.size;
          if ( v24 < v25 )
          {
            v22 = (signed __int64)&v3->m_Components.p[v24];
            while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
                 || UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
            {
              ++v24;
              v22 += 16i64;
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
bool __fastcall UFG::InventoryComponent::Equip(UFG::SimObject *pSimObject, UFG::SimObject *pObjectToEquip)
{
  UFG::SimObject *v2; // rbx
  unsigned __int16 v3; // r8
  UFG::InventoryComponent *v4; // rax
  unsigned int v5; // er8
  unsigned int v6; // er9
  UFG::SimComponentHolder *v7; // rdx
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned int v10; // er8
  unsigned int v11; // er9

  v2 = pObjectToEquip;
  if ( !pSimObject || !pObjectToEquip )
    return 0;
  v3 = pSimObject->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = (UFG::InventoryComponent *)pSimObject->m_Components.p[39].m_pComponent;
    goto LABEL_28;
  }
  if ( (v3 & 0x8000u) != 0 )
  {
    v5 = (unsigned int)pSimObject[1].vfptr;
    v6 = pSimObject->m_Components.size;
    if ( v5 < v6 )
    {
      v7 = &pSimObject->m_Components.p[v5];
      while ( (v7->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
           || UFG::InventoryComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF )
      {
        ++v5;
        ++v7;
        if ( v5 >= v6 )
          goto LABEL_11;
      }
LABEL_12:
      v4 = (UFG::InventoryComponent *)v7->m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_11;
  }
  if ( (v3 >> 13) & 1 )
  {
    v8 = (unsigned int)pSimObject[1].vfptr;
    v9 = pSimObject->m_Components.size;
    if ( v8 < v9 )
    {
      v7 = &pSimObject->m_Components.p[v8];
      while ( (v7->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
           || UFG::InventoryComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF )
      {
        ++v8;
        ++v7;
        if ( v8 >= v9 )
        {
          v4 = 0i64;
          goto LABEL_28;
        }
      }
      goto LABEL_12;
    }
LABEL_11:
    v4 = 0i64;
    goto LABEL_28;
  }
  if ( (v3 >> 12) & 1 )
  {
    v10 = (unsigned int)pSimObject[1].vfptr;
    v11 = pSimObject->m_Components.size;
    if ( v10 < v11 )
    {
      v7 = &pSimObject->m_Components.p[v10];
      while ( (v7->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
           || UFG::InventoryComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF )
      {
        ++v10;
        ++v7;
        if ( v10 >= v11 )
        {
          v4 = 0i64;
          goto LABEL_28;
        }
      }
      goto LABEL_12;
    }
    goto LABEL_11;
  }
  v4 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(pSimObject, UFG::InventoryComponent::_TypeUID);
LABEL_28:
  if ( v4 )
    return UFG::InventoryComponent::Equip(v4, v2, 0, 0);
  return 0;
}

// File Line: 680
// RVA: 0x526F80
__int64 __fastcall UFG::InventoryComponent::Equip(UFG::InventoryComponent *this, UFG::SimObject *pObjectToEquip)
{
  return UFG::InventoryComponent::Equip(this, pObjectToEquip, 0, 0);
}

// File Line: 685
// RVA: 0x526F90
__int64 __fastcall UFG::InventoryComponent::Equip(UFG::InventoryComponent *this, UFG::SimObject *pObjectToEquip, bool useEquipSlot, UFG::eInventoryEquipSlot inventoryEquipSlot)
{
  UFG::SimObjectProp *v4; // rsi
  UFG::InventoryComponent *v5; // r13
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimObjectWeaponPropertiesComponent *v8; // rbx
  UFG::TargetingSystemBaseComponent *v9; // r14
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  unsigned int v13; // er8
  unsigned int v14; // er9
  UFG::eTargetTypeEnum v15; // er12
  UFG::SimObjectProp *v16; // rcx
  UFG::CharacterAnimationComponent *v17; // rdi
  unsigned __int16 v18; // dx
  unsigned int v19; // edx
  UFG::CharacterAnimationComponent *v20; // rax
  bool v21; // zf
  unsigned int v22; // er9
  unsigned int v23; // er10
  signed __int64 v24; // r8
  unsigned __int16 v25; // cx
  UFG::CharacterAnimationComponent *v26; // rcx
  UFG::CharacterAnimationComponent *v27; // rax
  unsigned int v28; // er9
  unsigned int v29; // er10
  signed __int64 v30; // r8
  Creature *v31; // rdi
  Creature *v32; // rcx
  int v33; // ebp
  signed __int64 attachmentBoneID; // r15
  UFG::SimObject *v35; // rcx
  UFG::TriadWarsComponent *v36; // rdi
  unsigned __int16 v37; // dx
  unsigned int v38; // er8
  unsigned int v39; // er9
  signed __int64 v40; // rdx
  unsigned int v41; // er8
  unsigned int v42; // er9
  unsigned int v43; // er8
  unsigned int v44; // er9
  unsigned int v45; // er8
  unsigned int v46; // er9
  unsigned __int16 v47; // cx
  unsigned int v48; // er8
  unsigned int v49; // er10
  signed __int64 v50; // rdx
  unsigned int v51; // er8
  unsigned int v52; // er10
  UFG::SimObjectWeaponPropertiesComponent *v53; // rax
  unsigned int v54; // er8
  unsigned int v55; // er10
  UFG::InventoryComponent::EquipInfo v57; // [rsp+40h] [rbp-48h]
  unsigned __int8 v58; // [rsp+98h] [rbp+10h]

  v4 = (UFG::SimObjectProp *)pObjectToEquip;
  v5 = this;
  v58 = 0;
  if ( !pObjectToEquip )
    return v58;
  *(_QWORD *)&v57.mPropBoneUID.mUID = -1i64;
  UFG::InventoryComponent::EquipInfo::init(&v57, pObjectToEquip, useEquipSlot, inventoryEquipSlot);
  v6 = v5->m_pSimObject;
  if ( !v6 )
    return v58;
  v7 = v6->m_Flags;
  v8 = 0i64;
  if ( !((v7 >> 14) & 1) )
  {
    if ( (v7 & 0x8000u) != 0 )
    {
      v9 = (UFG::TargetingSystemBaseComponent *)v6->m_Components.p[20].m_pComponent;
      goto LABEL_23;
    }
    if ( (v7 >> 13) & 1 )
    {
      v10 = (unsigned int)v6[1].vfptr;
      v11 = v6->m_Components.size;
      if ( v10 < v11 )
      {
        v12 = (signed __int64)&v6->m_Components.p[v10];
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
        {
          ++v10;
          v12 += 16i64;
          if ( v10 >= v11 )
            goto LABEL_13;
        }
LABEL_14:
        v9 = *(UFG::TargetingSystemBaseComponent **)v12;
        goto LABEL_23;
      }
    }
    else
    {
      if ( !((v7 >> 12) & 1) )
      {
        v9 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                    v6,
                                                    UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_23;
      }
      v13 = (unsigned int)v6[1].vfptr;
      v14 = v6->m_Components.size;
      if ( v13 < v14 )
      {
        v12 = (signed __int64)&v6->m_Components.p[v13];
        while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
        {
          ++v13;
          v12 += 16i64;
          if ( v13 >= v14 )
          {
            v9 = 0i64;
            goto LABEL_23;
          }
        }
        goto LABEL_14;
      }
    }
LABEL_13:
    v9 = 0i64;
    goto LABEL_23;
  }
  v9 = (UFG::TargetingSystemBaseComponent *)v6->m_Components.p[20].m_pComponent;
LABEL_23:
  if ( !v9 )
    return v58;
  v15 = v57.mEquipTarget;
  if ( v9->m_pTargets[(unsigned __int8)v9->m_pTargetingMap->m_Map.p[v57.mEquipTarget]].m_pTarget.m_pPointer )
    return v58;
  v16 = (UFG::SimObjectProp *)v5->m_pSimObject;
  if ( !v16 )
  {
    v17 = 0i64;
LABEL_49:
    v19 = UFG::CharacterAnimationComponent::_TypeUID;
    goto LABEL_50;
  }
  v18 = v16->m_Flags;
  if ( (v18 >> 14) & 1 )
  {
    v19 = UFG::CharacterAnimationComponent::_TypeUID;
    v17 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v17
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_31;
    }
    goto LABEL_50;
  }
  if ( (v18 & 0x8000u) != 0 )
  {
    v19 = UFG::CharacterAnimationComponent::_TypeUID;
    v17 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v17 || (UFG::CharacterAnimationComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000 )
      goto LABEL_31;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF )
      v17 = 0i64;
    goto LABEL_50;
  }
  if ( (v18 >> 13) & 1 )
  {
    v20 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v16);
LABEL_48:
    v17 = v20;
    goto LABEL_49;
  }
  v21 = ((v18 >> 12) & 1) == 0;
  v19 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( v21 )
  {
    v20 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v16->vfptr,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_48;
  }
  v22 = v16->mComponentTableEntryCount;
  v23 = v16->m_Components.size;
  if ( v22 >= v23 )
  {
LABEL_31:
    v17 = 0i64;
    goto LABEL_50;
  }
  v24 = (signed __int64)&v16->m_Components.p[v22];
  while ( (*(_DWORD *)(v24 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v24 + 8) & 0x1FFFFFF )
  {
    ++v22;
    v24 += 16i64;
    if ( v22 >= v23 )
    {
      v17 = 0i64;
      goto LABEL_50;
    }
  }
  v17 = *(UFG::CharacterAnimationComponent **)v24;
LABEL_50:
  v25 = v4->m_Flags;
  if ( (v25 >> 14) & 1 )
  {
    v26 = (UFG::CharacterAnimationComponent *)v4->m_Components.p[9].m_pComponent;
    if ( !v26 || (v19 ^ v26->m_TypeUID) & 0xFE000000 || v19 & ~v26->m_TypeUID & 0x1FFFFFF )
      goto LABEL_54;
    goto LABEL_72;
  }
  if ( (v25 & 0x8000u) != 0 )
  {
    v26 = (UFG::CharacterAnimationComponent *)v4->m_Components.p[9].m_pComponent;
    if ( !v26 || (v19 ^ v26->m_TypeUID) & 0xFE000000 )
      goto LABEL_54;
    if ( v19 & ~v26->m_TypeUID & 0x1FFFFFF )
      v26 = 0i64;
    goto LABEL_72;
  }
  if ( (v25 >> 13) & 1 )
  {
    v27 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v4);
LABEL_71:
    v26 = v27;
    goto LABEL_72;
  }
  if ( !((v25 >> 12) & 1) )
  {
    v27 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, v19);
    goto LABEL_71;
  }
  v28 = v4->mComponentTableEntryCount;
  v29 = v4->m_Components.size;
  if ( v28 >= v29 )
  {
LABEL_54:
    v26 = 0i64;
    goto LABEL_72;
  }
  v30 = (signed __int64)&v4->m_Components.p[v28];
  while ( (*(_DWORD *)(v30 + 8) & 0xFE000000) != (v19 & 0xFE000000) || v19 & ~*(_DWORD *)(v30 + 8) & 0x1FFFFFF )
  {
    ++v28;
    v30 += 16i64;
    if ( v28 >= v29 )
    {
      v26 = 0i64;
      goto LABEL_72;
    }
  }
  v26 = *(UFG::CharacterAnimationComponent **)v30;
LABEL_72:
  if ( v17 )
    v31 = v17->mCreature;
  else
    v31 = 0i64;
  if ( v26 )
    v32 = v26->mCreature;
  else
    v32 = 0i64;
  if ( v31 && v32 )
  {
    v33 = -1;
    if ( v32->mPose.mRigHandle.mData )
      attachmentBoneID = (unsigned int)Skeleton::GetBoneID(v32->mPose.mRigHandle.mUFGSkeleton, v57.mPropBoneUID.mUID);
    else
      attachmentBoneID = 0xFFFFFFFFi64;
    if ( v31->mPose.mRigHandle.mData )
      v33 = Skeleton::GetBoneID(v31->mPose.mRigHandle.mUFGSkeleton, v57.mCharacterBoneUID.mUID);
    if ( (signed int)attachmentBoneID >= 0
      && v33 >= 0
      && UFG::InventoryComponent::AddObjectToInventory(v5, (UFG::SimObject *)&v4->vfptr, 1, attachmentBoneID) )
    {
      Creature::AddAttachment(v31, v5->m_pSimObject, v33, (UFG::SimObject *)&v4->vfptr, attachmentBoneID, 0, 0.0);
      UFG::TargetingSystemBaseComponent::SetTarget(v9, v15, (UFG::SimObject *)&v4->vfptr);
      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, signed __int64))v9->vfptr[14].__vecDelDtor)(
        v9,
        (unsigned int)v15,
        1i64);
      v58 = 1;
      if ( (UFG::SimObjectCharacter *)v5->m_pSimObject == LocalPlayer && v15 == eTARGET_TYPE_EQUIPPED )
        UFG::GameStatAction::Inventory::Equip((UFG::SimObject *)&v4->vfptr);
      v35 = v5->m_pSimObject;
      if ( !v35 )
        goto LABEL_92;
      v37 = v35->m_Flags;
      if ( (v37 >> 14) & 1 )
      {
        v38 = (unsigned int)v35[1].vfptr;
        v39 = v35->m_Components.size;
        if ( v38 < v39 )
        {
          v40 = (signed __int64)&v35->m_Components.p[v38];
          while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
               || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF )
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
      else if ( (v37 & 0x8000u) == 0 )
      {
        if ( (v37 >> 13) & 1 )
        {
          v43 = (unsigned int)v35[1].vfptr;
          v44 = v35->m_Components.size;
          if ( v43 < v44 )
          {
            v40 = (signed __int64)&v35->m_Components.p[v43];
            while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                 || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF )
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
          if ( !((v37 >> 12) & 1) )
          {
            v36 = (UFG::TriadWarsComponent *)UFG::SimObject::GetComponentOfType(v35, UFG::TriadWarsComponent::_TypeUID);
LABEL_123:
            v47 = v4->m_Flags;
            if ( (v47 >> 14) & 1 )
            {
              v48 = v4->mComponentTableEntryCount;
              v49 = v4->m_Components.size;
              if ( v48 >= v49 )
              {
LABEL_149:
                if ( v36 && v8 )
                  UFG::TriadWarsComponent::OnEquip(v36, v8);
                return v58;
              }
              v50 = (signed __int64)&v4->m_Components.p[v48];
              while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                   || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF )
              {
                ++v48;
                v50 += 16i64;
                if ( v48 >= v49 )
                  goto LABEL_149;
              }
LABEL_130:
              v8 = *(UFG::SimObjectWeaponPropertiesComponent **)v50;
              goto LABEL_149;
            }
            if ( (v47 & 0x8000u) != 0 )
            {
              v51 = v4->mComponentTableEntryCount;
              v52 = v4->m_Components.size;
              if ( v51 >= v52 )
                goto LABEL_149;
              v50 = (signed __int64)&v4->m_Components.p[v51];
              while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                   || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF )
              {
                ++v51;
                v50 += 16i64;
                if ( v51 >= v52 )
                  goto LABEL_149;
              }
              goto LABEL_130;
            }
            if ( (v47 >> 13) & 1 )
            {
              v53 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v4);
            }
            else
            {
              if ( (v47 >> 12) & 1 )
              {
                v54 = v4->mComponentTableEntryCount;
                v55 = v4->m_Components.size;
                if ( v54 >= v55 )
                  goto LABEL_149;
                v50 = (signed __int64)&v4->m_Components.p[v54];
                while ( (*(_DWORD *)(v50 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                     || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v50 + 8) & 0x1FFFFFF )
                {
                  ++v54;
                  v50 += 16i64;
                  if ( v54 >= v55 )
                    goto LABEL_149;
                }
                goto LABEL_130;
              }
              v53 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                 (UFG::SimObject *)&v4->vfptr,
                                                                 UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
            }
            v8 = v53;
            goto LABEL_149;
          }
          v45 = (unsigned int)v35[1].vfptr;
          v46 = v35->m_Components.size;
          if ( v45 < v46 )
          {
            v40 = (signed __int64)&v35->m_Components.p[v45];
            while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                 || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF )
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
          v40 = (signed __int64)&v35->m_Components.p[v41];
          while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
               || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF )
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
void __fastcall UFG::InventoryComponent::UnEquip(UFG::InventoryComponent *this, UFG::eInventoryEquipSlot slot, const bool bDeleteFromWorld)
{
  UFG::InventoryComponent *v3; // r13
  UFG::eTargetTypeEnum v4; // er12
  UFG::SimObject *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimObjectWeaponPropertiesComponent *v7; // rdi
  UFG::TargetingSystemBaseComponent *v8; // r14
  unsigned int v9; // er8
  unsigned int v10; // er9
  signed __int64 v11; // rdx
  unsigned int v12; // er8
  unsigned int v13; // er9
  UFG::TargetingSimObject *v14; // rcx
  signed __int64 v15; // r8
  UFG::SimObjectProp *v16; // r15
  bool v17; // al
  UFG::SimObjectProp *v18; // rcx
  UFG::CharacterAnimationComponent *v19; // rbx
  unsigned __int16 v20; // dx
  unsigned int v21; // edx
  UFG::CharacterAnimationComponent *v22; // rax
  bool v23; // zf
  unsigned int v24; // er9
  unsigned int v25; // er10
  signed __int64 v26; // r8
  unsigned __int16 v27; // cx
  UFG::CharacterAnimationComponent *v28; // rcx
  UFG::CharacterAnimationComponent *v29; // rax
  unsigned int v30; // er9
  unsigned int v31; // er10
  signed __int64 v32; // r8
  Creature *v33; // rsi
  Creature *v34; // rbx
  int v35; // ebp
  signed int v36; // ebx
  UFG::SimObject *v37; // rcx
  unsigned __int16 v38; // dx
  UFG::InventoryComponent *v39; // rax
  unsigned int v40; // er8
  unsigned int v41; // er9
  signed __int64 v42; // rdx
  unsigned int v43; // er8
  unsigned int v44; // er9
  unsigned int v45; // er8
  unsigned int v46; // er9
  __int64 v47; // r9
  UFG::SimObject *v48; // rcx
  unsigned __int16 v49; // dx
  UFG::CompositeDrawableComponent *v50; // rax
  unsigned int v51; // er8
  unsigned int v52; // er9
  signed __int64 v53; // rdx
  UFG::SimObject *v54; // rcx
  UFG::TriadWarsComponent *v55; // rbx
  unsigned __int16 v56; // dx
  unsigned int v57; // er8
  unsigned int v58; // er9
  signed __int64 v59; // rdx
  unsigned int v60; // er8
  unsigned int v61; // er9
  unsigned int v62; // er8
  unsigned int v63; // er9
  unsigned int v64; // er8
  unsigned int v65; // er9
  unsigned __int16 v66; // dx
  unsigned int v67; // er8
  unsigned int v68; // er9
  signed __int64 v69; // rdx
  unsigned int v70; // er8
  unsigned int v71; // er9
  UFG::SimObjectWeaponPropertiesComponent *v72; // rax
  unsigned int v73; // er8
  unsigned int v74; // er9
  UFG::InventoryComponent::EquipInfo v75; // [rsp+40h] [rbp-38h]
  bool v76; // [rsp+90h] [rbp+18h]

  v76 = bDeleteFromWorld;
  v3 = this;
  v4 = eTARGET_TYPE_EQUIPPED;
  switch ( slot )
  {
    case 1:
      v4 = 18;
      break;
    case 2:
      v4 = 19;
      break;
    case 3:
      v4 = 20;
      break;
    case 4:
      v4 = 42;
      break;
    case 5:
      v4 = 43;
      break;
    default:
      break;
  }
  v5 = this->m_pSimObject;
  if ( !v5 )
    return;
  v6 = v5->m_Flags;
  v7 = 0i64;
  if ( !((v6 >> 14) & 1) )
  {
    if ( (v6 & 0x8000u) != 0 )
    {
      v8 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
      goto LABEL_28;
    }
    if ( (v6 >> 13) & 1 )
    {
      v9 = (unsigned int)v5[1].vfptr;
      v10 = v5->m_Components.size;
      if ( v9 < v10 )
      {
        v11 = (signed __int64)&v5->m_Components.p[v9];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
        {
          ++v9;
          v11 += 16i64;
          if ( v9 >= v10 )
            goto LABEL_18;
        }
LABEL_19:
        v8 = *(UFG::TargetingSystemBaseComponent **)v11;
        goto LABEL_28;
      }
    }
    else
    {
      if ( !((v6 >> 12) & 1) )
      {
        v8 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                    v5,
                                                    UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_28;
      }
      v12 = (unsigned int)v5[1].vfptr;
      v13 = v5->m_Components.size;
      if ( v12 < v13 )
      {
        v11 = (signed __int64)&v5->m_Components.p[v12];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
        {
          ++v12;
          v11 += 16i64;
          if ( v12 >= v13 )
          {
            v8 = 0i64;
            goto LABEL_28;
          }
        }
        goto LABEL_19;
      }
    }
LABEL_18:
    v8 = 0i64;
    goto LABEL_28;
  }
  v8 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
LABEL_28:
  if ( !v8 )
    return;
  v14 = v8->m_pTargets;
  v15 = (unsigned __int8)v8->m_pTargetingMap->m_Map.p[v4];
  v16 = (UFG::SimObjectProp *)v14[v15].m_pTarget.m_pPointer;
  v17 = v16 && v14[v15].m_bLock;
  if ( !v16 || !v17 )
    return;
  v18 = (UFG::SimObjectProp *)v3->m_pSimObject;
  if ( !v18 )
  {
    v19 = 0i64;
LABEL_59:
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    goto LABEL_60;
  }
  v20 = v18->m_Flags;
  if ( (v20 >> 14) & 1 )
  {
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    v19 = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
    if ( !v19
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v19->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v19->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_41;
    }
    goto LABEL_60;
  }
  if ( (v20 & 0x8000u) != 0 )
  {
    v21 = UFG::CharacterAnimationComponent::_TypeUID;
    v19 = (UFG::CharacterAnimationComponent *)v18->m_Components.p[9].m_pComponent;
    if ( !v19 || (UFG::CharacterAnimationComponent::_TypeUID ^ v19->m_TypeUID) & 0xFE000000 )
      goto LABEL_41;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v19->m_TypeUID & 0x1FFFFFF )
      v19 = 0i64;
    goto LABEL_60;
  }
  if ( (v20 >> 13) & 1 )
  {
    v22 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v18);
LABEL_58:
    v19 = v22;
    goto LABEL_59;
  }
  v23 = ((v20 >> 12) & 1) == 0;
  v21 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( v23 )
  {
    v22 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v18->vfptr,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_58;
  }
  v24 = v18->mComponentTableEntryCount;
  v25 = v18->m_Components.size;
  if ( v24 >= v25 )
  {
LABEL_41:
    v19 = 0i64;
    goto LABEL_60;
  }
  v26 = (signed __int64)&v18->m_Components.p[v24];
  while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF )
  {
    ++v24;
    v26 += 16i64;
    if ( v24 >= v25 )
    {
      v19 = 0i64;
      goto LABEL_60;
    }
  }
  v19 = *(UFG::CharacterAnimationComponent **)v26;
LABEL_60:
  v27 = v16->m_Flags;
  if ( (v27 >> 14) & 1 )
  {
    v28 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v28 || (v21 ^ v28->m_TypeUID) & 0xFE000000 || v21 & ~v28->m_TypeUID & 0x1FFFFFF )
      goto LABEL_64;
    goto LABEL_82;
  }
  if ( (v27 & 0x8000u) != 0 )
  {
    v28 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v28 || (v21 ^ v28->m_TypeUID) & 0xFE000000 )
      goto LABEL_64;
    if ( v21 & ~v28->m_TypeUID & 0x1FFFFFF )
      v28 = 0i64;
    goto LABEL_82;
  }
  if ( (v27 >> 13) & 1 )
  {
    v29 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v16);
LABEL_81:
    v28 = v29;
    goto LABEL_82;
  }
  if ( !((v27 >> 12) & 1) )
  {
    v29 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v16->vfptr, v21);
    goto LABEL_81;
  }
  v30 = v16->mComponentTableEntryCount;
  v31 = v16->m_Components.size;
  if ( v30 >= v31 )
  {
LABEL_64:
    v28 = 0i64;
    goto LABEL_82;
  }
  v32 = (signed __int64)&v16->m_Components.p[v30];
  while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (v21 & 0xFE000000) || v21 & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
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
    v33 = v19->mCreature;
  else
    v33 = 0i64;
  if ( v28 )
    v34 = v28->mCreature;
  else
    v34 = 0i64;
  if ( v33 && v34 )
  {
    *(_QWORD *)&v75.mPropBoneUID.mUID = -1i64;
    UFG::InventoryComponent::EquipInfo::init(&v75, (UFG::SimObject *)&v16->vfptr, 0, 0);
    v35 = -1;
    if ( v34->mPose.mRigHandle.mData )
      v36 = Skeleton::GetBoneID(v34->mPose.mRigHandle.mUFGSkeleton, v75.mPropBoneUID.mUID);
    else
      v36 = -1;
    if ( v33->mPose.mRigHandle.mData )
      v35 = Skeleton::GetBoneID(v33->mPose.mRigHandle.mUFGSkeleton, v75.mCharacterBoneUID.mUID);
    if ( v36 >= 0 && v35 >= 0 )
    {
      v37 = v3->m_pSimObject;
      if ( v37 )
      {
        v38 = v37->m_Flags;
        if ( (v38 >> 14) & 1 )
        {
          v39 = (UFG::InventoryComponent *)v37->m_Components.p[39].m_pComponent;
          goto LABEL_123;
        }
        if ( (v38 & 0x8000u) == 0 )
        {
          if ( (v38 >> 13) & 1 )
          {
            v43 = (unsigned int)v37[1].vfptr;
            v44 = v37->m_Components.size;
            if ( v43 < v44 )
            {
              v42 = (signed __int64)&v37->m_Components.p[v43];
              while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                   || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF )
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
            if ( !((v38 >> 12) & 1) )
            {
              v39 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                 v37,
                                                 UFG::InventoryComponent::_TypeUID);
LABEL_123:
              if ( !v39 )
                return;
              UFG::InventoryComponent::RemoveObjectFromInventory(v39, (UFG::SimObject *)&v16->vfptr, (__int64)v16);
              Creature::RemoveAttachment(v33, v3->m_pSimObject, v35, (UFG::SimObject *)&v16->vfptr);
              LOBYTE(v47) = 1;
              ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))v8->vfptr[14].__vecDelDtor)(
                v8,
                (unsigned int)v4,
                0i64,
                v47,
                0,
                "InventoryComponent::UnEquip",
                0i64,
                0i64);
              UFG::TargetingSystemBaseComponent::ClearTarget(v8, v4);
              v48 = v3->m_pSimObject;
              if ( v48 )
              {
                v49 = v48->m_Flags;
                if ( (v49 >> 14) & 1 )
                {
                  v50 = (UFG::CompositeDrawableComponent *)v48->m_Components.p[14].m_pComponent;
                }
                else if ( (v49 & 0x8000u) == 0 )
                {
                  if ( (v49 >> 13) & 1 )
                  {
                    v50 = (UFG::CompositeDrawableComponent *)v48->m_Components.p[9].m_pComponent;
                  }
                  else if ( (v49 >> 12) & 1 )
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
                      v53 = (signed __int64)&v48->m_Components.p[v51];
                      while ( (*(_DWORD *)(v53 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
                           || UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF )
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
              if ( (UFG::SimObjectCharacter *)v3->m_pSimObject == LocalPlayer && v4 == 17 )
                UFG::GameStatAction::Inventory::UnEquip(0);
              v54 = v3->m_pSimObject;
              if ( !v54 )
                goto LABEL_146;
              v56 = v54->m_Flags;
              if ( (v56 >> 14) & 1 )
              {
                v57 = (unsigned int)v54[1].vfptr;
                v58 = v54->m_Components.size;
                if ( v57 < v58 )
                {
                  v59 = (signed __int64)&v54->m_Components.p[v57];
                  while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                       || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF )
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
              else if ( (v56 & 0x8000u) == 0 )
              {
                if ( (v56 >> 13) & 1 )
                {
                  v62 = (unsigned int)v54[1].vfptr;
                  v63 = v54->m_Components.size;
                  if ( v62 < v63 )
                  {
                    v59 = (signed __int64)&v54->m_Components.p[v62];
                    while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF )
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
                  if ( !((v56 >> 12) & 1) )
                  {
                    v55 = (UFG::TriadWarsComponent *)UFG::SimObject::GetComponentOfType(
                                                       v54,
                                                       UFG::TriadWarsComponent::_TypeUID);
LABEL_177:
                    v66 = v16->m_Flags;
                    if ( (v66 >> 14) & 1 )
                    {
                      v67 = v16->mComponentTableEntryCount;
                      v68 = v16->m_Components.size;
                      if ( v67 >= v68 )
                        goto LABEL_203;
                      v69 = (signed __int64)&v16->m_Components.p[v67];
                      while ( (*(_DWORD *)(v69 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                           || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v69 + 8) & 0x1FFFFFF )
                      {
                        ++v67;
                        v69 += 16i64;
                        if ( v67 >= v68 )
                          goto LABEL_203;
                      }
                      goto LABEL_184;
                    }
                    if ( (v66 & 0x8000u) != 0 )
                    {
                      v70 = v16->mComponentTableEntryCount;
                      v71 = v16->m_Components.size;
                      if ( v70 < v71 )
                      {
                        v69 = (signed __int64)&v16->m_Components.p[v70];
                        while ( (*(_DWORD *)(v69 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                             || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v69 + 8) & 0x1FFFFFF )
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
                    if ( (v66 >> 13) & 1 )
                    {
                      v72 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v16);
                    }
                    else
                    {
                      if ( (v66 >> 12) & 1 )
                      {
                        v73 = v16->mComponentTableEntryCount;
                        v74 = v16->m_Components.size;
                        if ( v73 < v74 )
                        {
                          v69 = (signed __int64)&v16->m_Components.p[v73];
                          while ( (*(_DWORD *)(v69 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
                               || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v69 + 8) & 0x1FFFFFF )
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
                        if ( v76 )
                          UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v16->vfptr);
                        return;
                      }
                      v72 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                         (UFG::SimObject *)&v16->vfptr,
                                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                    }
                    v7 = v72;
                    goto LABEL_203;
                  }
                  v64 = (unsigned int)v54[1].vfptr;
                  v65 = v54->m_Components.size;
                  if ( v64 < v65 )
                  {
                    v59 = (signed __int64)&v54->m_Components.p[v64];
                    while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                         || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF )
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
                  v59 = (signed __int64)&v54->m_Components.p[v60];
                  while ( (*(_DWORD *)(v59 + 8) & 0xFE000000) != (UFG::TriadWarsComponent::_TypeUID & 0xFE000000)
                       || UFG::TriadWarsComponent::_TypeUID & ~*(_DWORD *)(v59 + 8) & 0x1FFFFFF )
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
              v42 = (signed __int64)&v37->m_Components.p[v45];
              while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                   || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF )
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
            v42 = (signed __int64)&v37->m_Components.p[v40];
            while ( (*(_DWORD *)(v42 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v42 + 8) & 0x1FFFFFF )
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
void __fastcall UFG::InventoryComponent::Stow(UFG::InventoryComponent *this, UFG::eInventoryEquipSlot sourceSlot, UFG::eInventoryEquipSlot destinationSlot)
{
  UFG::InventoryComponent *v3; // rbx
  UFG::SimObject *v4; // rcx
  __int64 v5; // rdi
  __int64 v6; // r14
  unsigned __int16 v7; // r9
  UFG::CompositeDrawableComponent *v8; // rsi
  UFG::TargetingSystemBaseComponent *v9; // r15
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  unsigned int v13; // er8
  unsigned int v14; // er9
  UFG::SimObject *v15; // r13
  UFG::SimObjectProp *v16; // rcx
  unsigned __int16 v17; // dx
  unsigned int v18; // er8
  unsigned int v19; // er9
  signed __int64 v20; // rdx
  UFG::SimObjectWeaponPropertiesComponent *v21; // rax
  unsigned int v22; // er8
  unsigned int v23; // er9
  unsigned int v24; // er8
  unsigned int v25; // er9
  char *v26; // rax
  __int64 v27; // r12
  UFG::qSymbolUC *v28; // rcx
  char *v29; // rax
  UFG::SimObjectProp *v30; // rcx
  unsigned __int16 v31; // dx
  UFG::CharacterAnimationComponent *v32; // rcx
  UFG::CharacterAnimationComponent *v33; // rax
  unsigned int v34; // er8
  unsigned int v35; // er9
  signed __int64 v36; // rdx
  Creature *v37; // rbx
  int v38; // ebp
  int v39; // er14
  char *v40; // rbx
  char *v41; // rax
  __int64 v42; // r8
  unsigned __int16 v43; // cx
  unsigned int v44; // er8
  unsigned int v45; // er9
  signed __int64 v46; // rdx
  UFG::eTargetTypeEnum eTargetType; // [rsp+80h] [rbp+8h]
  UFG::eInventoryEquipSlot v48; // [rsp+88h] [rbp+10h]
  UFG::eInventoryEquipSlot v49; // [rsp+90h] [rbp+18h]

  v49 = destinationSlot;
  v48 = sourceSlot;
  v3 = this;
  v4 = this->m_pSimObject;
  v5 = destinationSlot;
  v6 = sourceSlot;
  if ( !v4 )
    return;
  v7 = v4->m_Flags;
  v8 = 0i64;
  if ( (v7 >> 14) & 1 )
  {
    v9 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
    goto LABEL_22;
  }
  if ( (v7 & 0x8000u) != 0 )
  {
    v9 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
    goto LABEL_22;
  }
  if ( (v7 >> 13) & 1 )
  {
    v10 = (unsigned int)v4[1].vfptr;
    v11 = v4->m_Components.size;
    if ( v10 < v11 )
    {
      v12 = (signed __int64)&v4->m_Components.p[v10];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
      {
        ++v10;
        v12 += 16i64;
        if ( v10 >= v11 )
          goto LABEL_12;
      }
LABEL_13:
      v9 = *(UFG::TargetingSystemBaseComponent **)v12;
      goto LABEL_22;
    }
    goto LABEL_12;
  }
  if ( (v7 >> 12) & 1 )
  {
    v13 = (unsigned int)v4[1].vfptr;
    v14 = v4->m_Components.size;
    if ( v13 < v14 )
    {
      v12 = (signed __int64)&v4->m_Components.p[v13];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
      {
        ++v13;
        v12 += 16i64;
        if ( v13 >= v14 )
        {
          v9 = 0i64;
          goto LABEL_22;
        }
      }
      goto LABEL_13;
    }
LABEL_12:
    v9 = 0i64;
    goto LABEL_22;
  }
  v9 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                              v4,
                                              UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_22:
  if ( !v9 )
    return;
  eTargetType = (unsigned int)UFG::InventoryComponent::GetSlotTarget((UFG::eInventoryEquipSlot)v6);
  v15 = v9->m_pTargets[(unsigned __int8)v9->m_pTargetingMap->m_Map.p[eTargetType]].m_pTarget.m_pPointer;
  if ( !v15 )
  {
    UFG::qPrintf(
      "InventoryComponent::Stow: Source Stow Slot (%s) not found.  Not Stowing!\n",
      UFG::InventoryEquipSlotEnumNames[v6]);
    return;
  }
  v16 = (UFG::SimObjectProp *)v3->m_pSimObject;
  if ( !v16 )
    goto LABEL_54;
  v17 = v16->m_Flags;
  if ( (v17 >> 14) & 1 )
  {
    v18 = v16->mComponentTableEntryCount;
    v19 = v16->m_Components.size;
    if ( v18 < v19 )
    {
      v20 = (signed __int64)&v16->m_Components.p[v18];
      while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF )
      {
        ++v18;
        v20 += 16i64;
        if ( v18 >= v19 )
          goto LABEL_32;
      }
LABEL_33:
      v21 = *(UFG::SimObjectWeaponPropertiesComponent **)v20;
      goto LABEL_51;
    }
  }
  else if ( (v17 & 0x8000u) == 0 )
  {
    if ( (v17 >> 13) & 1 )
    {
      v21 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v16);
      goto LABEL_51;
    }
    if ( !((v17 >> 12) & 1) )
    {
      v21 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v16->vfptr,
                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_51;
    }
    v24 = v16->mComponentTableEntryCount;
    v25 = v16->m_Components.size;
    if ( v24 < v25 )
    {
      v20 = (signed __int64)&v16->m_Components.p[v24];
      while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF )
      {
        ++v24;
        v20 += 16i64;
        if ( v24 >= v25 )
        {
          v21 = 0i64;
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
      v20 = (signed __int64)&v16->m_Components.p[v22];
      while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::SimObjectWeaponPropertiesComponent::_TypeUID & 0xFE000000)
           || UFG::SimObjectWeaponPropertiesComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF )
      {
        ++v22;
        v20 += 16i64;
        if ( v22 >= v23 )
        {
          v21 = 0i64;
          goto LABEL_51;
        }
      }
      goto LABEL_33;
    }
  }
LABEL_32:
  v21 = 0i64;
LABEL_51:
  if ( v21 && !v21->mWeaponTypeInfo->mFireModes[v21->mFireMode]->mStowable )
  {
    v26 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v15->m_Name);
    UFG::qPrintf(
      "InventoryComponent::Stow: Source Stow Slot (%s-%s) is not Stowable!",
      UFG::InventoryEquipSlotEnumNames[v6],
      v26);
    return;
  }
LABEL_54:
  v27 = (unsigned int)UFG::InventoryComponent::GetSlotTarget((UFG::eInventoryEquipSlot)v5);
  v28 = (UFG::qSymbolUC *)v9->m_pTargets[(unsigned __int8)v9->m_pTargetingMap->m_Map.p[v27]].m_pTarget.m_pPointer;
  if ( v28 )
  {
    v29 = UFG::qSymbol::as_cstr_dbg(v28 + 18);
    UFG::qPrintf(
      "InventoryComponent::Stow: Destination Stow Slot (%s) is not empty.  Contains: %s.  Not Stowing!\n",
      UFG::InventoryEquipSlotEnumNames[v5],
      v29);
    return;
  }
  v30 = (UFG::SimObjectProp *)v3->m_pSimObject;
  if ( !v30 )
    goto LABEL_81;
  v31 = v30->m_Flags;
  if ( (v31 >> 14) & 1 )
  {
    v32 = (UFG::CharacterAnimationComponent *)v30->m_Components.p[9].m_pComponent;
    if ( !v32
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_61;
    }
    goto LABEL_79;
  }
  if ( (v31 & 0x8000u) != 0 )
  {
    v32 = (UFG::CharacterAnimationComponent *)v30->m_Components.p[9].m_pComponent;
    if ( !v32 || (UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000 )
      goto LABEL_61;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF )
      v32 = 0i64;
    goto LABEL_79;
  }
  if ( (v31 >> 13) & 1 )
  {
    v33 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v30);
LABEL_78:
    v32 = v33;
    goto LABEL_79;
  }
  if ( !((v31 >> 12) & 1) )
  {
    v33 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v30->vfptr,
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
  v36 = (signed __int64)&v30->m_Components.p[v34];
  while ( (*(_DWORD *)(v36 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v36 + 8) & 0x1FFFFFF )
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
    v37 = v32->mCreature;
    goto LABEL_82;
  }
LABEL_81:
  v37 = 0i64;
LABEL_82:
  if ( v37 )
  {
    v38 = -1;
    if ( v37->mPose.mRigHandle.mData )
      v39 = Skeleton::GetBoneID(v37->mPose.mRigHandle.mUFGSkeleton, *(&stru_14240E4C4.mUID + 2 * v6));
    else
      v39 = -1;
    if ( v37->mPose.mRigHandle.mData )
      v38 = Skeleton::GetBoneID(v37->mPose.mRigHandle.mUFGSkeleton, *(&stru_14240E4C4.mUID + 2 * v49));
    if ( v39 >= 0
      && v38 >= 0
      && !Creature::TransferAttachment(v37, v39, v38, (UFG::qSymbolUC *)&gStaticSymbolUC_none.mUID) )
    {
      v40 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(8i64 * (signed int)v49 + 5406516420i64));
      v41 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(8i64 * (signed int)v48 + 5406516420i64));
      UFG::qPrintf("Attachment Was Not Transferred! (%s -> %s)", v41, v40);
    }
    UFG::TargetingSystemBaseComponent::SetTarget(v9, (UFG::eTargetTypeEnum)v27, v15);
    LOBYTE(v42) = 1;
    ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, __int64, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD))v9->vfptr[14].__vecDelDtor)(
      v9,
      (unsigned int)v27,
      v42,
      0i64,
      0,
      0i64,
      0i64,
      0i64);
    UFG::TargetingSystemBaseComponent::ClearTarget(v9, eTargetType);
    v43 = v15->m_Flags;
    if ( (v43 >> 14) & 1 )
    {
      v8 = (UFG::CompositeDrawableComponent *)v15->m_Components.p[14].m_pComponent;
    }
    else if ( (v43 & 0x8000u) == 0 )
    {
      if ( (v43 >> 13) & 1 )
      {
        v8 = (UFG::CompositeDrawableComponent *)v15->m_Components.p[9].m_pComponent;
      }
      else if ( (v43 >> 12) & 1 )
      {
        v44 = (unsigned int)v15[1].vfptr;
        v45 = v15->m_Components.size;
        if ( v44 < v45 )
        {
          v46 = (signed __int64)&v15->m_Components.p[v44];
          while ( (*(_DWORD *)(v46 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
               || UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v46 + 8) & 0x1FFFFFF )
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
                                                  v15,
                                                  UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      v8 = (UFG::CompositeDrawableComponent *)v15->m_Components.p[14].m_pComponent;
    }
LABEL_107:
    if ( v8 )
      UFG::CompositeDrawableComponent::SetIsHidden(v8, 1);
  }
}4].m_pComponent;
    }
LABEL_107:
    if ( v8 )
      UFG::CompositeDrawableComponent::SetIsHidden(v8, 1);
  }
}

// File Line: 935
// RVA: 0x52AEC0
_BOOL8 __fastcall UFG::InventoryComponent::GetCanDrop(UFG::InventoryComponent *this, UFG::eInventoryEquipSlot slot)
{
  return this->m_EquipSlots.p[slot].mCanDrop;
}

// File Line: 941
// RVA: 0x54BF30
void __fastcall UFG::InventoryComponent::SetCanDrop(UFG::InventoryComponent *this, UFG::eInventoryEquipSlot slot, const bool canDrop)
{
  this->m_EquipSlots.p[slot].mCanDrop = canDrop;
}

// File Line: 964
// RVA: 0x569EB0
void __fastcall UFG::InventoryComponent::EquipInfo::init(UFG::InventoryComponent::EquipInfo *this, UFG::SimObject *pProp, bool useEquipSlot, UFG::eInventoryEquipSlot inventoryEquipSlot)
{
  UFG::InventoryComponent::EquipInfo *v4; // rbx
  signed __int64 v5; // rdx
  UFG::SceneObjectProperties *v6; // rax
  UFG::qPropertySet *v7; // rdi
  char *v8; // rax
  char *v9; // rax
  UFG::qSymbol *v10; // rax
  UFG::qSymbolUC *v11; // rdi
  UFG::eTargetTypeEnum v12; // eax
  char *v13; // rax
  UFG::qSymbolUC result; // [rsp+40h] [rbp+18h]

  v4 = this;
  if ( useEquipSlot )
  {
    v5 = 8i64 * (signed int)inventoryEquipSlot;
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
      v6 = pProp->m_pSceneObj;
      if ( v6 )
      {
        v7 = v6->mpWritableProperties;
        if ( !v7 )
          v7 = v6->mpConstProperties;
      }
      else
      {
        v7 = 0i64;
      }
      v8 = UFG::qPropertySet::Get<char const *>(v7, (UFG::qSymbol *)&qSymbol_PropBone.mUID, DEPTH_RECURSE);
      if ( v8 )
        v4->mPropBoneUID = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, v8)->mUID;
      v9 = UFG::qPropertySet::Get<char const *>(v7, (UFG::qSymbol *)&qSymbol_AttachBone.mUID, DEPTH_RECURSE);
      if ( v9 )
        v4->mCharacterBoneUID = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, v9)->mUID;
      v10 = UFG::qPropertySet::Get<UFG::qSymbol>(v7, (UFG::qSymbol *)&qSymbol_EquipTarget.mUID, DEPTH_RECURSE);
      v11 = (UFG::qSymbolUC *)v10;
      if ( v10 )
      {
        v12 = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gTargetTypeEnum, v10);
        if ( v12 < eTARGET_TYPE_EQUIPPED
          || v12 > eTARGET_TYPE_EQUIPPED_GLASSES && (unsigned int)(v12 - eTARGET_TYPE_STOWED_WEAPON) > 1 )
        {
          v13 = UFG::qSymbol::as_cstr_dbg(v11);
          UFG::qPrintf("InventoryComponent::GetAttachmentInfo: Invalid EquipTarget: %s", v13);
        }
        else
        {
          v4->mEquipTarget = v12;
        }
      }
    }
  }
}

