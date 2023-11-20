// File Line: 31
// RVA: 0x1543F40
__int64 dynamic_initializer_for__UFG::InventoryItemComponent::s_InventoryItemComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::InventoryItemComponent::s_InventoryItemComponentList__);
}

// File Line: 32
// RVA: 0x52CA80
UFG::ComponentIDDesc *__fastcall UFG::InventoryItemComponent::GetDesc(UFG::InventoryItemComponent *this)
{
  return &UFG::InventoryItemComponent::_TypeIDesc;
}

// File Line: 38
// RVA: 0x518140
void __fastcall UFG::InventoryItemComponent::InventoryItemComponent(UFG::InventoryItemComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, component_InventoryItem *data_ptr)
{
  component_InventoryItem *v4; // rbp
  UFG::qPropertySet *v5; // rsi
  UFG::InventoryItemComponent *v6; // rdi
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v7; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryComponent> *v8; // rbx
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax

  v4 = data_ptr;
  v5 = properties;
  v6 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v7 = (UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *)&v6->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InventoryItemComponent::`vftable;
  v8 = &v6->m_pOwnerInventoryComponent;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v6->m_pOwnerInventoryComponent.m_pPointer = 0i64;
  v6->m_eInventoryItem = 0;
  v6->m_symInventoryItem.mUID = -1;
  v6->m_iQuantity = 0;
  v9 = UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mPrev;
  UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *)&v6->mPrev;
  v7->mPrev = v9;
  v6->mNext = (UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *)&UFG::InventoryItemComponent::s_InventoryItemComponentList;
  UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mPrev = (UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *)&v6->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v6->vfptr,
    UFG::InventoryItemComponent::_InventoryItemComponentTypeUID,
    "InventoryItemComponent");
  if ( v6->m_pOwnerInventoryComponent.m_pPointer )
  {
    v10 = v8->mPrev;
    v11 = v6->m_pOwnerInventoryComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v6->m_pOwnerInventoryComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->m_pOwnerInventoryComponent.mPrev;
  }
  v6->m_pOwnerInventoryComponent.m_pPointer = 0i64;
  if ( v5 )
    UFG::InventoryItemComponent::PropertiesLoad(v6, v5, v4);
}

// File Line: 53
// RVA: 0x51BF60
void __fastcall UFG::InventoryItemComponent::~InventoryItemComponent(UFG::InventoryItemComponent *this)
{
  UFG::InventoryItemComponent *v1; // r8
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v2; // r9
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v3; // rcx
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v10; // rcx
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InventoryItemComponent::`vftable;
  if ( this == UFG::InventoryItemComponent::s_InventoryItemComponentpCurrentIterator )
    UFG::InventoryItemComponent::s_InventoryItemComponentpCurrentIterator = (UFG::InventoryItemComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->m_pOwnerInventoryComponent;
  if ( v1->m_pOwnerInventoryComponent.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->m_pOwnerInventoryComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_pOwnerInventoryComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pOwnerInventoryComponent.mPrev;
  }
  v1->m_pOwnerInventoryComponent.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->m_pOwnerInventoryComponent.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_pOwnerInventoryComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pOwnerInventoryComponent.mPrev;
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 61
// RVA: 0x5441D0
void __fastcall UFG::InventoryItemComponent::PropertiesLoad(UFG::InventoryItemComponent *this, UFG::qPropertySet *properties, component_InventoryItem *data_ptr)
{
  component_InventoryItem *v3; // rbx
  UFG::InventoryItemComponent *v4; // rdi
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v3 = data_ptr;
  v4 = this;
  this->m_eInventoryItem = 0;
  this->m_symInventoryItem = UFG::gNullQSymbol;
  if ( data_ptr->simObjectInventoryItem.mUID != UFG::gNullQSymbol.mUID )
  {
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol.mUID = data_ptr->simObjectInventoryItem.mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
    }
    else
    {
      v5 = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v5;
      pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v4->m_eInventoryItem = pTrackEnumBinding.m_EnumValue;
    v4->m_symInventoryItem.mUID = v3->simObjectInventoryItem.mUID;
    v6 = pTrackEnumBinding.mPrev;
    v7 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v7->mPrev = v6;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v4->m_iQuantity = UFG::GetRandomNumberInRange(v3->InventoryItemQuantityMin, v3->InventoryItemQuantityMax);
}

// File Line: 88
// RVA: 0x5468F0
UFG::SimComponent *__fastcall UFG::InventoryItemComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *v11; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *v13; // rdx
  unsigned __int16 v14; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_InventoryItem::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v7 = 0i64;
  if ( !v2 && !v7 )
    return 0i64;
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x78ui64, "InventoryItemComponent", 0i64, 1u);
  if ( v10 )
  {
    v11 = v3->mpWritableProperties;
    if ( !v11 )
      v11 = v3->mpConstProperties;
    UFG::InventoryItemComponent::InventoryItemComponent(
      (UFG::InventoryItemComponent *)v10,
      v3->m_NameUID,
      v11,
      (component_InventoryItem *)v7);
    v6 = v12;
  }
  v13 = v3->m_pSimObject;
  v14 = v13->m_Flags;
  if ( (v14 >> 14) & 1 || (v14 & 0x8000u) != 0 || !((v14 >> 13) & 1) )
    v15 = -1;
  else
    v15 = 11;
  UFG::SimObjectModifier::SimObjectModifier(&v16, v13, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v6;
}

// File Line: 108
// RVA: 0x53E420
void __fastcall UFG::InventoryItemComponent::OnAttach(UFG::InventoryItemComponent *this, UFG::SimObject *pObject)
{
  UFG::InventoryItemComponent *v2; // rsi
  UFG::SimObject *v3; // r8
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  unsigned int v6; // ecx
  unsigned int v7; // er9
  UFG::SimComponentHolder *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rdi
  hkSeekableStreamReader *v11; // rax

  v2 = this;
  v3 = this->m_pSimObject;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p->m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = v3->m_Components.p->m_pComponent;
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = (unsigned int)v3[1].vfptr;
        v7 = v3->m_Components.size;
        if ( v6 >= v7 )
        {
LABEL_16:
          v5 = 0i64;
        }
        else
        {
          v8 = v3->m_Components.p;
          while ( (v8[v6].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~v8[v6].m_TypeUID & 0x1FFFFFF )
          {
            if ( ++v6 >= v7 )
              goto LABEL_16;
          }
          v5 = v8[v6].m_pComponent;
        }
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType(this->m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v5 = v3->m_Components.p->m_pComponent;
    }
    if ( v5 )
    {
      v9 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
      v10 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v9;
      if ( v9 )
      {
        v9->mNext = 0i64;
        v9[1].mNext = 0i64;
      }
      else
      {
        v10 = 0i64;
      }
      v5[3].m_SafePointerList.mNode.mPrev = v10;
      v11 = Assembly::GetRCX(v2);
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)UFG::InventoryItemComponent::GetOwnerSimObject_UEL;
      v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v11;
    }
  }
}

// File Line: 120
// RVA: 0x540990
void __usercall UFG::InventoryItemComponent::OnDetach(UFG::InventoryItemComponent *this@<rcx>, __int64 a2@<r15>)
{
  UFG::InventoryItemComponent *v2; // rbx
  UFG::InventoryComponent *v3; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObject *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rbx
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx

  v2 = this;
  v3 = (UFG::InventoryComponent *)this->m_pOwnerInventoryComponent.m_pPointer;
  if ( v3 )
  {
    UFG::InventoryComponent::RemoveObjectFromInventory(v3, v2->m_pSimObject, a2);
    v4 = &v2->m_pOwnerInventoryComponent;
    if ( v2->m_pOwnerInventoryComponent.m_pPointer )
    {
      v5 = v4->mPrev;
      v6 = v2->m_pOwnerInventoryComponent.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v2->m_pOwnerInventoryComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pOwnerInventoryComponent.mPrev;
    }
    v2->m_pOwnerInventoryComponent.m_pPointer = 0i64;
  }
  v7 = v2->m_pSimObject;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = v7->m_Components.p->m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = v7->m_Components.p->m_pComponent;
      }
      else if ( (v8 >> 12) & 1 )
      {
        v10 = (unsigned int)v7[1].vfptr;
        v11 = v7->m_Components.size;
        if ( v10 >= v11 )
        {
LABEL_18:
          v9 = 0i64;
        }
        else
        {
          v12 = (signed __int64)&v7->m_Components.p[v10];
          while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
          {
            ++v10;
            v12 += 16i64;
            if ( v10 >= v11 )
              goto LABEL_18;
          }
          v9 = *(UFG::SimComponent **)v12;
        }
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType(v7, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v9 = v7->m_Components.p->m_pComponent;
    }
    if ( v9 )
    {
      operator delete[](v9[3].m_SafePointerList.mNode.mPrev);
      v9[3].m_SafePointerList.mNode.mPrev = 0i64;
    }
  }
}

// File Line: 139
// RVA: 0x52F310
UFG::SimObject *__fastcall UFG::InventoryItemComponent::GetOwnerSimObject(UFG::InventoryItemComponent *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->m_pOwnerInventoryComponent.m_pPointer;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

// File Line: 145
// RVA: 0x52F320
UEL::Value *__fastcall UFG::InventoryItemComponent::GetOwnerSimObject_UEL(UFG::InventoryItemComponent *this, UEL::Value *result)
{
  UFG::SimComponent *v2; // rcx
  UEL::Value *v3; // rbx
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rcx
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx
  unsigned int v10; // eax

  v2 = this->m_pOwnerInventoryComponent.m_pPointer;
  v3 = result;
  if ( !v2 )
    goto LABEL_15;
  v4 = v2->m_pSimObject;
  if ( !v4 )
    goto LABEL_15;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p->m_pComponent;
    goto LABEL_16;
  }
  if ( (v5 & 0x8000u) != 0 )
  {
    v6 = v4->m_Components.p->m_pComponent;
    goto LABEL_16;
  }
  if ( (v5 >> 13) & 1 )
  {
    v6 = v4->m_Components.p->m_pComponent;
    goto LABEL_16;
  }
  if ( !((v5 >> 12) & 1) )
  {
    v6 = UFG::SimObject::GetComponentOfType(v4, UFG::UELComponent::_TypeUID);
    goto LABEL_16;
  }
  v7 = (unsigned int)v4[1].vfptr;
  v8 = v4->m_Components.size;
  if ( v7 >= v8 )
  {
LABEL_15:
    v6 = 0i64;
    goto LABEL_16;
  }
  v9 = (signed __int64)&v4->m_Components.p[v7];
  while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
       || UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
  {
    ++v7;
    v9 += 16i64;
    if ( v7 >= v8 )
      goto LABEL_15;
  }
  v6 = *(UFG::SimComponent **)v9;
LABEL_16:
  v3->type.mBaseType.mValue = 0;
  v3->type.mDetailedType = UFG::gNullQSymbol;
  if ( v6 )
  {
    v10 = UFG::gNullQSymbol.mUID;
    v3->type.mBaseType.mValue = 8;
    v3->type.mDetailedType.mUID = v10;
    v3->integer = (__int64)&v6[1].m_TypeUID;
  }
  return v3;
}

// File Line: 157
// RVA: 0x54E560
void __fastcall UFG::InventoryItemComponent::SetQuantity(UFG::InventoryItemComponent *this, int value)
{
  if ( !this->m_pOwnerInventoryComponent.m_pPointer )
    this->m_iQuantity = value;
}

