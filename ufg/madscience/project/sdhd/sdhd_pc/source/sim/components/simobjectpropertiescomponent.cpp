// File Line: 32
// RVA: 0x1544020
__int64 dynamic_initializer_for__UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList__);
}

// File Line: 33
// RVA: 0x15434F0
__int64 dynamic_initializer_for__UFG::SimObjectPropertiesComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::SimObjectPropertiesComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::SimObjectPropertiesComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 44
// RVA: 0x518A90
void __fastcall UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(
        UFG::SimObjectPropertiesComponent *this,
        unsigned int name_uid,
        component_SimObjectProperties *dataPtr)
{
  UFG::qBaseTreeRB *v5; // rsi
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *mPrev; // rax
  unsigned int mUID; // eax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  unsigned int v9; // edx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+38h] [rbp-28h] BYREF

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent>;
  this->mNext = &this->UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectPropertiesComponent::`vftable;
  v5 = 0i64;
  this->m_eSimObjectType = eSIM_OBJ_TYPE_INVALID;
  this->m_pSubTargetingProfile = 0i64;
  this->m_BitField.mBits[0] = 0i64;
  `eh vector constructor iterator(
    this->m_FlagSetLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  this->m_ClassTypeListArray.p = 0i64;
  *(_QWORD *)&this->m_ClassTypeListArray.size = 0i64;
  mPrev = UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mPrev;
  UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *)&UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList;
  UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mPrev = &this->UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::SimObjectPropertiesComponent::_SimObjectPropertiesComponentTypeUID,
    "SimObjectPropertiesComponent");
  if ( dataPtr )
  {
    mUID = dataPtr->simObjectType.mUID;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gSimObjectTypeTracksEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectTypeTracksEnum, &pTrackEnumBinding);
    }
    else
    {
      v8 = UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v8;
      pTrackEnumBinding.mNext = &UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    this->m_eSimObjectType = pTrackEnumBinding.m_EnumValue;
    v9 = dataPtr->subTargetingProfile.mUID;
    if ( v9 != UFG::gNullQSymbol.mUID )
    {
      if ( v9 )
        v5 = UFG::qBaseTreeRB::Get(&UFG::SubTargetingProfiles::ms_SubTargetingProfiles.mTree, v9);
      this->m_pSubTargetingProfile = (UFG::SubTargetingProfile *)v5;
    }
    v10 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v10;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
  }
  UFG::SimObjectPropertiesComponent::UpdateCachedValues(this);
}

// File Line: 75
// RVA: 0x51C550
void __fastcall UFG::SimObjectPropertiesComponent::~SimObjectPropertiesComponent(
        UFG::SimObjectPropertiesComponent *this)
{
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v2; // rsi
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *mPrev; // rcx
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *mNext; // rax
  signed __int16 m_Flags; // cx
  UFG::TargetingSystemPedPlayerComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v8; // edx
  unsigned int mComponentTableEntryCount; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v12; // r8
  unsigned int v13; // ecx
  unsigned int v14; // r9d
  UFG::qSymbol *v15; // rcx
  UFG::qSymbol *v16; // rbx
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v17; // rcx
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v18; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectPropertiesComponent::`vftable;
  if ( this == UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentpCurrentIterator )
    UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentpCurrentIterator = (UFG::SimObjectPropertiesComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemPedPlayerComponent *)LocalPlayer->m_Components.p[20].m_pComponent;
      if ( !m_pComponent )
        goto LABEL_8;
      m_TypeUID = m_pComponent->m_TypeUID;
      if ( ((m_TypeUID ^ UFG::TargetingSystemPedPlayerComponent::_TypeUID) & 0xFE000000) != 0
        || (UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
      {
        goto LABEL_8;
      }
LABEL_30:
      if ( m_pComponent )
        UFG::TargetingSystemPedPlayerComponent::RemoveCloseTarget(m_pComponent, this);
      goto LABEL_32;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = (UFG::TargetingSystemPedPlayerComponent *)LocalPlayer->m_Components.p[20].m_pComponent;
      if ( m_pComponent )
      {
        v8 = m_pComponent->m_TypeUID;
        if ( ((v8 ^ UFG::TargetingSystemPedPlayerComponent::_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v8 & 0x1FFFFFF) != 0 )
            m_pComponent = 0i64;
          goto LABEL_30;
        }
      }
      goto LABEL_8;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      mComponentTableEntryCount = LocalPlayer->mComponentTableEntryCount;
      size = LocalPlayer->m_Components.size;
      if ( mComponentTableEntryCount < size )
      {
        p = LocalPlayer->m_Components.p;
        while ( 1 )
        {
          v12 = mComponentTableEntryCount;
          if ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedPlayerComponent::_TypeUID & 0xFE000000)
            && (UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++mComponentTableEntryCount >= size )
            goto LABEL_8;
        }
LABEL_21:
        m_pComponent = (UFG::TargetingSystemPedPlayerComponent *)p[v12].m_pComponent;
        goto LABEL_30;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                   LocalPlayer,
                                                                   UFG::TargetingSystemPedPlayerComponent::_TypeUID);
        goto LABEL_30;
      }
      v13 = LocalPlayer->mComponentTableEntryCount;
      v14 = LocalPlayer->m_Components.size;
      if ( v13 < v14 )
      {
        p = LocalPlayer->m_Components.p;
        do
        {
          v12 = v13;
          if ( (p[v13].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedPlayerComponent::_TypeUID & 0xFE000000)
            && (UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~p[v13].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_21;
          }
        }
        while ( ++v13 < v14 );
      }
    }
LABEL_8:
    m_pComponent = 0i64;
    goto LABEL_30;
  }
LABEL_32:
  v15 = this->m_ClassTypeListArray.p;
  if ( v15 )
  {
    v16 = v15 - 1;
    `eh vector destructor iterator(v15, 4ui64, v15[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v16);
  }
  this->m_ClassTypeListArray.p = 0i64;
  *(_QWORD *)&this->m_ClassTypeListArray.size = 0i64;
  `eh vector destructor iterator(
    this->m_FlagSetLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0>::~qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0>);
  v17 = v2->mPrev;
  v18 = v2->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 90
// RVA: 0x546BF0
UFG::SimComponent *__fastcall UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_SimObjectProperties::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x98ui64, "SimObjectPropertiesComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(
      (UFG::SimObjectPropertiesComponent *)v10,
      pSceneObj->m_NameUID,
      (component_SimObjectProperties *)MemImagePtr);
    v6 = v11;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v14 = 3;
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v14 = 4;
  }
  else
  {
    v14 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v15, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
  return v6;
}

// File Line: 147
// RVA: 0x54FDB0
bool __fastcall UFG::SortSymbolPtrByUID(UFG::qSymbol *a, UFG::qSymbol *b)
{
  return a->mUID <= b->mUID;
}

// File Line: 152
// RVA: 0x53E760
void __fastcall UFG::SimObjectPropertiesComponent::OnAttach(
        UFG::SimObjectPropertiesComponent *this,
        UFG::SimObject *pObject)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  char *MemImagePtr; // rax
  char *v7; // rcx
  __int64 v8; // rax
  UFG::qPropertyList *v9; // rcx
  __int64 mNumElements; // rbp
  UFG::qSymbol *v11; // rsi
  UFG::qArray<UFG::qSymbol,0> *p_m_ClassTypeListArray; // rdi
  __int64 v13; // r15
  __int64 size; // r14
  unsigned int capacity; // edx
  unsigned int v16; // ebx
  unsigned int v17; // edx
  UFG::qSymbol *p; // rdx
  unsigned int mUID; // eax

  m_pSceneObj = pObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&schema_classlist::sPropertyName,
         DEPTH_RECURSE);
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    v7 = MemImagePtr;
    if ( MemImagePtr )
    {
      v8 = *((_QWORD *)MemImagePtr + 1);
      if ( v8 )
      {
        v9 = (UFG::qPropertyList *)&v7[v8 + 8];
        if ( v9 )
        {
          mNumElements = v9->mNumElements;
          if ( (_DWORD)mNumElements )
            v11 = UFG::qPropertyList::Get<UFG::qSymbol>(v9, 0);
          else
            v11 = 0i64;
          p_m_ClassTypeListArray = &this->m_ClassTypeListArray;
          if ( (unsigned int)mNumElements > p_m_ClassTypeListArray->capacity )
            UFG::qArray<UFG::qSymbol,0>::Reallocate(p_m_ClassTypeListArray, mNumElements, "qArray.Reallocate(Reserve)");
          if ( (_DWORD)mNumElements )
          {
            v13 = mNumElements;
            do
            {
              size = p_m_ClassTypeListArray->size;
              capacity = p_m_ClassTypeListArray->capacity;
              v16 = size + 1;
              if ( (int)size + 1 > capacity )
              {
                if ( capacity )
                  v17 = 2 * capacity;
                else
                  v17 = 1;
                for ( ; v17 < v16; v17 *= 2 )
                  ;
                if ( v17 <= 4 )
                  v17 = 4;
                if ( v17 - v16 > 0x10000 )
                  v17 = size + 65537;
                UFG::qArray<UFG::qSymbol,0>::Reallocate(p_m_ClassTypeListArray, v17, "m_ClassTypeListArray");
              }
              p = p_m_ClassTypeListArray->p;
              p_m_ClassTypeListArray->size = v16;
              mUID = v11->mUID;
              ++v11;
              p[size].mUID = mUID;
              --v13;
            }
            while ( v13 );
          }
          if ( (unsigned int)mNumElements > 1 )
            UFG::qArray<UFG::qSymbol,0>::BubbleSortCorrect(p_m_ClassTypeListArray, UFG::SortSymbolPtrByUID);
        }
      }
    }
  }
}

// File Line: 196
// RVA: 0x56AA40
bool __fastcall UFG::SimObjectPropertiesComponent::isFlagSet(
        UFG::SimObjectPropertiesComponent *this,
        int eSimObjectFlag)
{
  return &this->m_FlagSetLists[eSimObjectFlag].mNode.mNext[-3].mNext != (UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> **)((UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *)&this->UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> + eSimObjectFlag);
}

// File Line: 203
// RVA: 0x5213D0
void __fastcall UFG::SimObjectPropertiesComponent::AddSimObjectFlagSetTask(
        UFG::SimObjectPropertiesComponent *this,
        UFG::eSimObjectFlagEnum eSimObjectFlag,
        SimObjectFlagSetTask *pSimObjectFlagSetTask)
{
  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *v3; // r9
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *mPrev; // rax

  v3 = &this->m_FlagSetLists[eSimObjectFlag];
  mPrev = v3->mNode.mPrev;
  mPrev->mNext = &pSimObjectFlagSetTask->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>;
  pSimObjectFlagSetTask->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>::mPrev = mPrev;
  pSimObjectFlagSetTask->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>::mNext = &v3->mNode;
  v3->mNode.mPrev = &pSimObjectFlagSetTask->UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList>;
  UFG::SimObjectPropertiesComponent::UpdateCachedValues(this);
}

// File Line: 211
// RVA: 0x55E740
void __fastcall UFG::SimObjectPropertiesComponent::UpdateCachedValues(UFG::SimObjectPropertiesComponent *this)
{
  this->m_BitField.mBits[0] = 0i64;
  if ( this->m_eSimObjectType == eSIM_OBJ_TYPE_CHARACTER )
    this->m_BitField.mBits[0] |= 1ui64;
  if ( this->m_eSimObjectType == eSIM_OBJ_TYPE_VEHICLE )
    this->m_BitField.mBits[0] |= 2ui64;
  if ( this->m_eSimObjectType == eSIM_OBJ_TYPE_PICKUP )
    this->m_BitField.mBits[0] |= 4ui64;
  if ( this->m_eSimObjectType == eSIM_OBJ_TYPE_WEAPON )
    this->m_BitField.mBits[0] |= 8ui64;
  if ( this->m_eSimObjectType == eSIM_OBJ_TYPE_INTERACTIVE_PROP )
    this->m_BitField.mBits[0] |= 0x10ui64;
  if ( (UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *)&this->m_FlagSetLists[0].mNode.mNext[-3].mNext != &this->UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> )
    this->m_BitField.mBits[0] |= 0x20ui64;
  if ( (UFG::eSimObjectTypeEnum *)&this->m_FlagSetLists[1].mNode.mNext[-3].mNext != &this->m_eSimObjectType )
    this->m_BitField.mBits[0] |= 0x40ui64;
}

// File Line: 228
// RVA: 0x52AF20
__int64 __fastcall UFG::SimObjectPropertiesComponent::GetChildType(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimObject *m_pSimObject; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rdi
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v10; // rax
  unsigned int *MemImagePtr; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  unsigned int m_EnumValue; // r8d
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  if ( !pSceneObj )
    return 0i64;
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[3].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[4].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_17:
          m_pComponent = 0i64;
        }
        else
        {
          p = m_pSimObject->m_Components.p;
          while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || (UFG::SimObjectPropertiesComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
          {
            if ( ++vfptr >= size )
              goto LABEL_17;
          }
          m_pComponent = p[vfptr].m_pComponent;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(
                         pSceneObj->m_pSimObject,
                         UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[3].m_pComponent;
    }
    if ( m_pComponent )
      return LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext);
  }
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v10 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&component_SimObjectProperties::sPropertyName,
          DEPTH_RECURSE);
  if ( !v10 )
    return 0i64;
  MemImagePtr = (unsigned int *)UFG::qPropertySet::GetMemImagePtr(v10);
  if ( !MemImagePtr || *MemImagePtr == UFG::gNullQSymbol.mUID )
    return 0i64;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = *MemImagePtr;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gSimObjectTypeTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectTypeTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  m_EnumValue = pTrackEnumBinding.m_EnumValue;
  v14 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v14;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  return m_EnumValue;
}ing.mPrev = &pTrackEnumBinding

