// File Line: 31
// RVA: 0x1543F40
__int64 dynamic_initializer_for__UFG::InventoryItemComponent::s_InventoryItemComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InventoryItemComponent::s_InventoryItemComponentList__);
}

// File Line: 32
// RVA: 0x52CA80
UFG::ComponentIDDesc *__fastcall UFG::InventoryItemComponent::GetDesc(UFG::InventoryItemComponent *this)
{
  return &UFG::InventoryItemComponent::_TypeIDesc;
}

// File Line: 38
// RVA: 0x518140
void __fastcall UFG::InventoryItemComponent::InventoryItemComponent(
        UFG::InventoryItemComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        component_InventoryItem *data_ptr)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryComponent> *p_m_pOwnerInventoryComponent; // rbx
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent>;
  this->mNext = &this->UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InventoryItemComponent::`vftable;
  p_m_pOwnerInventoryComponent = &this->m_pOwnerInventoryComponent;
  this->m_pOwnerInventoryComponent.mPrev = &this->m_pOwnerInventoryComponent;
  this->m_pOwnerInventoryComponent.mNext = &this->m_pOwnerInventoryComponent;
  this->m_pOwnerInventoryComponent.m_pPointer = 0i64;
  this->m_eInventoryItem = eINVENTORY_ITEM_INVALID;
  this->m_symInventoryItem.mUID = -1;
  this->m_iQuantity = 0;
  mPrev = UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mPrev;
  UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *)&UFG::InventoryItemComponent::s_InventoryItemComponentList;
  UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mPrev = &this->UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::InventoryItemComponent::_InventoryItemComponentTypeUID,
    "InventoryItemComponent");
  if ( this->m_pOwnerInventoryComponent.m_pPointer )
  {
    v9 = p_m_pOwnerInventoryComponent->mPrev;
    mNext = this->m_pOwnerInventoryComponent.mNext;
    v9->mNext = mNext;
    mNext->mPrev = v9;
    p_m_pOwnerInventoryComponent->mPrev = p_m_pOwnerInventoryComponent;
    this->m_pOwnerInventoryComponent.mNext = &this->m_pOwnerInventoryComponent;
  }
  this->m_pOwnerInventoryComponent.m_pPointer = 0i64;
  if ( properties )
    UFG::InventoryItemComponent::PropertiesLoad(this, properties, data_ptr);
}

// File Line: 53
// RVA: 0x51BF60
void __fastcall UFG::InventoryItemComponent::~InventoryItemComponent(UFG::InventoryItemComponent *this)
{
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v2; // r9
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *mPrev; // rcx
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryComponent> *p_m_pOwnerInventoryComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v10; // rcx
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InventoryItemComponent::`vftable;
  if ( this == UFG::InventoryItemComponent::s_InventoryItemComponentpCurrentIterator )
    UFG::InventoryItemComponent::s_InventoryItemComponentpCurrentIterator = (UFG::InventoryItemComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_m_pOwnerInventoryComponent = &this->m_pOwnerInventoryComponent;
  if ( this->m_pOwnerInventoryComponent.m_pPointer )
  {
    v6 = p_m_pOwnerInventoryComponent->mPrev;
    v7 = this->m_pOwnerInventoryComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pOwnerInventoryComponent->mPrev = p_m_pOwnerInventoryComponent;
    this->m_pOwnerInventoryComponent.mNext = &this->m_pOwnerInventoryComponent;
  }
  this->m_pOwnerInventoryComponent.m_pPointer = 0i64;
  v8 = p_m_pOwnerInventoryComponent->mPrev;
  v9 = this->m_pOwnerInventoryComponent.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_m_pOwnerInventoryComponent->mPrev = p_m_pOwnerInventoryComponent;
  this->m_pOwnerInventoryComponent.mNext = &this->m_pOwnerInventoryComponent;
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 61
// RVA: 0x5441D0
void __fastcall UFG::InventoryItemComponent::PropertiesLoad(
        UFG::InventoryItemComponent *this,
        UFG::qPropertySet *properties,
        component_InventoryItem *data_ptr)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  this->m_eInventoryItem = eINVENTORY_ITEM_INVALID;
  this->m_symInventoryItem = UFG::gNullQSymbol;
  if ( data_ptr->simObjectInventoryItem.mUID != UFG::gNullQSymbol.mUID )
  {
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
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
      mPrev = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    this->m_eInventoryItem = pTrackEnumBinding.m_EnumValue;
    this->m_symInventoryItem.mUID = data_ptr->simObjectInventoryItem.mUID;
    v6 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v6;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
  }
  this->m_iQuantity = UFG::GetRandomNumberInRange(
                        data_ptr->InventoryItemQuantityMin,
                        data_ptr->InventoryItemQuantityMax);
}

// File Line: 88
// RVA: 0x5468F0
UFG::InventoryItemComponent *__fastcall UFG::InventoryItemComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *mpConstProperties; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_InventoryItem::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    MemImagePtr = 0i64;
  if ( !required && !MemImagePtr )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x78ui64, "InventoryItemComponent", 0i64, 1u);
  if ( v10 )
  {
    mpConstProperties = sceneObject->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sceneObject->mpConstProperties;
    UFG::InventoryItemComponent::InventoryItemComponent(
      (UFG::InventoryItemComponent *)v10,
      sceneObject->m_NameUID,
      mpConstProperties,
      (component_InventoryItem *)MemImagePtr);
    v6 = v12;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) == 0 )
    v15 = -1;
  else
    v15 = 11;
  UFG::SimObjectModifier::SimObjectModifier(&v16, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return (UFG::InventoryItemComponent *)v6;
}

// File Line: 108
// RVA: 0x53E420
void __fastcall UFG::InventoryItemComponent::OnAttach(UFG::InventoryItemComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *m_pSimObject; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rdi
  hkSeekableStreamReader *RCX; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_16:
          m_pComponent = 0i64;
        }
        else
        {
          p = m_pSimObject->m_Components.p;
          while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
          {
            if ( ++vfptr >= size )
              goto LABEL_16;
          }
          m_pComponent = p[vfptr].m_pComponent;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(this->m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
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
      m_pComponent[3].m_SafePointerList.mNode.mPrev = v10;
      RCX = Assembly::GetRCX(this);
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)UFG::InventoryItemComponent::GetOwnerSimObject_UEL;
      v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)RCX;
    }
  }
}

// File Line: 120
// RVA: 0x540990
void __fastcall UFG::InventoryItemComponent::OnDetach(UFG::InventoryItemComponent *this)
{
  __int64 v1; // r15
  UFG::InventoryComponent *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryComponent> *p_m_pOwnerInventoryComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v12; // rdx

  m_pPointer = (UFG::InventoryComponent *)this->m_pOwnerInventoryComponent.m_pPointer;
  if ( m_pPointer )
  {
    UFG::InventoryComponent::RemoveObjectFromInventory(m_pPointer, this->m_pSimObject, v1);
    p_m_pOwnerInventoryComponent = &this->m_pOwnerInventoryComponent;
    if ( this->m_pOwnerInventoryComponent.m_pPointer )
    {
      mPrev = p_m_pOwnerInventoryComponent->mPrev;
      mNext = this->m_pOwnerInventoryComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pOwnerInventoryComponent->mPrev = p_m_pOwnerInventoryComponent;
      this->m_pOwnerInventoryComponent.mNext = &this->m_pOwnerInventoryComponent;
    }
    this->m_pOwnerInventoryComponent.m_pPointer = 0i64;
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_18:
          m_pComponent = 0i64;
        }
        else
        {
          v12 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v12 += 16i64;
            if ( vfptr >= size )
              goto LABEL_18;
          }
          m_pComponent = *(UFG::SimComponent **)v12;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
    {
      operator delete[](m_pComponent[3].m_SafePointerList.mNode.mPrev);
      m_pComponent[3].m_SafePointerList.mNode.mPrev = 0i64;
    }
  }
}

// File Line: 139
// RVA: 0x52F310
UFG::qBaseNodeRB *__fastcall UFG::InventoryItemComponent::GetOwnerSimObject(UFG::InventoryItemComponent *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->m_pOwnerInventoryComponent.m_pPointer;
  if ( result )
    return result[1].mChild[0];
  return result;
}

// File Line: 145
// RVA: 0x52F320
UEL::Value *__fastcall UFG::InventoryItemComponent::GetOwnerSimObject_UEL(
        UFG::InventoryItemComponent *this,
        UEL::Value *result)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rcx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx
  unsigned int mUID; // eax

  m_pPointer = this->m_pOwnerInventoryComponent.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_15;
  m_pSimObject = m_pPointer->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_15;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    goto LABEL_16;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    goto LABEL_16;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    goto LABEL_16;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
    goto LABEL_16;
  }
  vfptr = (unsigned int)m_pSimObject[1].vfptr;
  size = m_pSimObject->m_Components.size;
  if ( vfptr >= size )
  {
LABEL_15:
    m_pComponent = 0i64;
    goto LABEL_16;
  }
  v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
  while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
       || (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
  {
    ++vfptr;
    v9 += 16i64;
    if ( vfptr >= size )
      goto LABEL_15;
  }
  m_pComponent = *(UFG::SimComponent **)v9;
LABEL_16:
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  if ( m_pComponent )
  {
    mUID = UFG::gNullQSymbol.mUID;
    result->type.mBaseType.mValue = 8;
    result->type.mDetailedType.mUID = mUID;
    result->integer = (__int64)&m_pComponent[1].m_TypeUID;
  }
  return result;
}

// File Line: 157
// RVA: 0x54E560
void __fastcall UFG::InventoryItemComponent::SetQuantity(UFG::InventoryItemComponent *this, int value)
{
  if ( !this->m_pOwnerInventoryComponent.m_pPointer )
    this->m_iQuantity = value;
}

