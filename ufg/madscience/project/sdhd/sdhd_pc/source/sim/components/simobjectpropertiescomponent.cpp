// File Line: 32
// RVA: 0x1544020
__int64 dynamic_initializer_for__UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList__);
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
void __fastcall UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(UFG::SimObjectPropertiesComponent *this, unsigned int name_uid, component_SimObjectProperties *dataPtr)
{
  component_SimObjectProperties *v3; // r14
  UFG::SimObjectPropertiesComponent *v4; // rdi
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v5; // rbx
  UFG::qBaseTreeRB *v6; // rsi
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v7; // rax
  unsigned int v8; // eax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  unsigned int v10; // edx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+38h] [rbp-28h]

  v3 = dataPtr;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectPropertiesComponent::`vftable;
  v6 = 0i64;
  v4->m_eSimObjectType = 0;
  v4->m_pSubTargetingProfile = 0i64;
  v4->m_BitField.mBits[0] = 0i64;
  `eh vector constructor iterator(
    v4->m_FlagSetLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  v4->m_ClassTypeListArray.p = 0i64;
  *(_QWORD *)&v4->m_ClassTypeListArray.size = 0i64;
  v7 = UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mPrev;
  UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *)&v4->mPrev;
  v5->mPrev = v7;
  v4->mNext = (UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *)&UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList;
  UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentList.mNode.mPrev = (UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::SimObjectPropertiesComponent::_SimObjectPropertiesComponentTypeUID,
    "SimObjectPropertiesComponent");
  if ( v3 )
  {
    v8 = v3->simObjectType.mUID;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = v8;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gSimObjectTypeTracksEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectTypeTracksEnum, &pTrackEnumBinding);
    }
    else
    {
      v9 = UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v9;
      pTrackEnumBinding.mNext = &UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v4->m_eSimObjectType = pTrackEnumBinding.m_EnumValue;
    v10 = v3->subTargetingProfile.mUID;
    if ( v10 != UFG::gNullQSymbol.mUID )
    {
      if ( v10 )
        v6 = UFG::qBaseTreeRB::Get(&UFG::SubTargetingProfiles::ms_SubTargetingProfiles.mTree, v10);
      v4->m_pSubTargetingProfile = (UFG::SubTargetingProfile *)v6;
    }
    v11 = pTrackEnumBinding.mPrev;
    v12 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v12->mPrev = v11;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  UFG::SimObjectPropertiesComponent::UpdateCachedValues(v4);
}

// File Line: 75
// RVA: 0x51C550
void __fastcall UFG::SimObjectPropertiesComponent::~SimObjectPropertiesComponent(UFG::SimObjectPropertiesComponent *this)
{
  UFG::SimObjectPropertiesComponent *v1; // rdi
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v2; // rsi
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v3; // rcx
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v4; // rax
  unsigned __int16 v5; // cx
  UFG::TargetingSystemPedPlayerComponent *v6; // rcx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // er9
  UFG::SimComponentHolder *v11; // rbx
  signed __int64 v12; // r8
  unsigned int v13; // ecx
  unsigned int v14; // er9
  UFG::qSymbol *v15; // rcx
  UFG::qSymbol *v16; // rbx
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v17; // rcx
  UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *v18; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectPropertiesComponent::`vftable;
  if ( this == UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentpCurrentIterator )
    UFG::SimObjectPropertiesComponent::s_SimObjectPropertiesComponentpCurrentIterator = (UFG::SimObjectPropertiesComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( LocalPlayer )
  {
    v5 = LocalPlayer->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::TargetingSystemPedPlayerComponent *)LocalPlayer->m_Components.p[20].m_pComponent;
      if ( !v6 )
        goto LABEL_8;
      v7 = v6->m_TypeUID;
      if ( (v7 ^ UFG::TargetingSystemPedPlayerComponent::_TypeUID) & 0xFE000000
        || UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v7 & 0x1FFFFFF )
      {
        goto LABEL_8;
      }
LABEL_30:
      if ( v6 )
        UFG::TargetingSystemPedPlayerComponent::RemoveCloseTarget(v6, v1);
      goto LABEL_32;
    }
    if ( (v5 & 0x8000u) != 0 )
    {
      v6 = (UFG::TargetingSystemPedPlayerComponent *)LocalPlayer->m_Components.p[20].m_pComponent;
      if ( v6 )
      {
        v8 = v6->m_TypeUID;
        if ( !((v8 ^ UFG::TargetingSystemPedPlayerComponent::_TypeUID) & 0xFE000000) )
        {
          if ( UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v8 & 0x1FFFFFF )
            v6 = 0i64;
          goto LABEL_30;
        }
      }
      goto LABEL_8;
    }
    if ( (v5 >> 13) & 1 )
    {
      v9 = LocalPlayer->mComponentTableEntryCount;
      v10 = LocalPlayer->m_Components.size;
      if ( v9 < v10 )
      {
        v11 = LocalPlayer->m_Components.p;
        while ( 1 )
        {
          v12 = v9;
          if ( (v11[v9].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedPlayerComponent::_TypeUID & 0xFE000000)
            && !(UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v11[v9].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v9 >= v10 )
            goto LABEL_8;
        }
LABEL_21:
        v6 = (UFG::TargetingSystemPedPlayerComponent *)v11[v12].m_pComponent;
        goto LABEL_30;
      }
    }
    else
    {
      if ( !((v5 >> 12) & 1) )
      {
        v6 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&LocalPlayer->vfptr,
                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID);
        goto LABEL_30;
      }
      v13 = LocalPlayer->mComponentTableEntryCount;
      v14 = LocalPlayer->m_Components.size;
      if ( v13 < v14 )
      {
        v11 = LocalPlayer->m_Components.p;
        do
        {
          v12 = v13;
          if ( (v11[v13].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemPedPlayerComponent::_TypeUID & 0xFE000000)
            && !(UFG::TargetingSystemPedPlayerComponent::_TypeUID & ~v11[v13].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_21;
          }
        }
        while ( ++v13 < v14 );
      }
    }
LABEL_8:
    v6 = 0i64;
    goto LABEL_30;
  }
LABEL_32:
  v15 = v1->m_ClassTypeListArray.p;
  if ( v15 )
  {
    v16 = v15 - 1;
    `eh vector destructor iterator(v15, 4ui64, v15[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v16);
  }
  v1->m_ClassTypeListArray.p = 0i64;
  *(_QWORD *)&v1->m_ClassTypeListArray.size = 0i64;
  `eh vector destructor iterator(
    v1->m_FlagSetLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0>::~qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0>);
  v17 = v2->mPrev;
  v18 = v2->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 90
// RVA: 0x546BF0
UFG::SimComponent *__fastcall UFG::SimObjectPropertiesComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rdx
  unsigned __int16 v13; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_SimObjectProperties::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x98ui64, "SimObjectPropertiesComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(
      (UFG::SimObjectPropertiesComponent *)v10,
      v3->m_NameUID,
      (component_SimObjectProperties *)v7);
    v6 = v11;
  }
  v12 = v3->m_pSimObject;
  v13 = v12->m_Flags;
  if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
  {
    v14 = 3;
  }
  else if ( (v13 >> 13) & 1 )
  {
    v14 = 4;
  }
  else
  {
    v14 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v15, v12, 1);
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
void __fastcall UFG::SimObjectPropertiesComponent::OnAttach(UFG::SimObjectPropertiesComponent *this, UFG::SimObject *pObject)
{
  UFG::SceneObjectProperties *v2; // rax
  UFG::SimObjectPropertiesComponent *v3; // rdi
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  char *v6; // rax
  char *v7; // rcx
  __int64 v8; // rax
  UFG::qPropertyList *v9; // rcx
  __int64 v10; // rbp
  UFG::qSymbol *v11; // rsi
  UFG::qArray<UFG::qSymbol,0> *v12; // rdi
  __int64 v13; // r15
  __int64 v14; // r14
  unsigned int v15; // edx
  unsigned int v16; // ebx
  unsigned int v17; // edx
  UFG::qSymbol *v18; // rdx
  unsigned int v19; // eax

  v2 = pObject->m_pSceneObj;
  v3 = this;
  v4 = v2->mpWritableProperties;
  if ( !v4 )
    v4 = v2->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&schema_classlist::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v5 )
  {
    v6 = UFG::qPropertySet::GetMemImagePtr(v5);
    v7 = v6;
    if ( v6 )
    {
      v8 = *((_QWORD *)v6 + 1);
      if ( v8 )
      {
        v9 = (UFG::qPropertyList *)&v7[v8 + 8];
        if ( v9 )
        {
          v10 = v9->mNumElements;
          if ( (_DWORD)v10 )
            v11 = UFG::qPropertyList::Get<UFG::qSymbol>(v9, 0);
          else
            v11 = 0i64;
          v12 = &v3->m_ClassTypeListArray;
          if ( (unsigned int)v10 > v12->capacity )
            UFG::qArray<UFG::qSymbol,0>::Reallocate(v12, v10, "qArray.Reallocate(Reserve)");
          if ( (_DWORD)v10 )
          {
            v13 = v10;
            do
            {
              v14 = v12->size;
              v15 = v12->capacity;
              v16 = v14 + 1;
              if ( (signed int)v14 + 1 > v15 )
              {
                if ( v15 )
                  v17 = 2 * v15;
                else
                  v17 = 1;
                for ( ; v17 < v16; v17 *= 2 )
                  ;
                if ( v17 <= 4 )
                  v17 = 4;
                if ( v17 - v16 > 0x10000 )
                  v17 = v14 + 65537;
                UFG::qArray<UFG::qSymbol,0>::Reallocate(v12, v17, "m_ClassTypeListArray");
              }
              v18 = v12->p;
              v12->size = v16;
              v19 = v11->mUID;
              ++v11;
              v18[v14].mUID = v19;
              --v13;
            }
            while ( v13 );
          }
          if ( (unsigned int)v10 > 1 )
            UFG::qArray<UFG::qSymbol,0>::BubbleSortCorrect(v12, UFG::SortSymbolPtrByUID);
        }
      }
    }
  }
}

// File Line: 196
// RVA: 0x56AA40
bool __fastcall UFG::SimObjectPropertiesComponent::isFlagSet(UFG::SimObjectPropertiesComponent *this, UFG::eSimObjectFlagEnum eSimObjectFlag)
{
  return &this->m_FlagSetLists[eSimObjectFlag].mNode.mNext[-3].mNext != (UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> **)&(&this->mPrev)[2 * eSimObjectFlag];
}

// File Line: 203
// RVA: 0x5213D0
void __fastcall UFG::SimObjectPropertiesComponent::AddSimObjectFlagSetTask(UFG::SimObjectPropertiesComponent *this, UFG::eSimObjectFlagEnum eSimObjectFlag, SimObjectFlagSetTask *pSimObjectFlagSetTask)
{
  __int64 v3; // rax
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v4; // rdx
  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *v5; // r9
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v6; // rax

  v3 = eSimObjectFlag;
  v4 = (UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *)&pSimObjectFlagSetTask->mPrev;
  v5 = &this->m_FlagSetLists[v3];
  v6 = v5->mNode.mPrev;
  v6->mNext = (UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *)&pSimObjectFlagSetTask->mPrev;
  v4->mPrev = v6;
  v4->mNext = &v5->mNode;
  v5->mNode.mPrev = (UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *)&pSimObjectFlagSetTask->mPrev;
  UFG::SimObjectPropertiesComponent::UpdateCachedValues(this);
}

// File Line: 211
// RVA: 0x55E740
void __fastcall UFG::SimObjectPropertiesComponent::UpdateCachedValues(UFG::SimObjectPropertiesComponent *this)
{
  this->m_BitField.mBits[0] = 0i64;
  if ( this->m_eSimObjectType == 1 )
    this->m_BitField.mBits[0] |= 1ui64;
  if ( this->m_eSimObjectType == 4 )
    this->m_BitField.mBits[0] |= 2ui64;
  if ( this->m_eSimObjectType == 2 )
    this->m_BitField.mBits[0] |= 4ui64;
  if ( this->m_eSimObjectType == 3 )
    this->m_BitField.mBits[0] |= 8ui64;
  if ( this->m_eSimObjectType == 5 )
    this->m_BitField.mBits[0] |= 0x10ui64;
  if ( (UFG::qNode<UFG::SimObjectPropertiesComponent,UFG::SimObjectPropertiesComponent> **)&this->m_FlagSetLists[0].mNode.mNext[-3].mNext != &this->mPrev )
    this->m_BitField.mBits[0] |= 0x20ui64;
  if ( (UFG::eSimObjectTypeEnum *)&this->m_FlagSetLists[1].mNode.mNext[-3].mNext != &this->m_eSimObjectType )
    this->m_BitField.mBits[0] |= 0x40ui64;
}

// File Line: 228
// RVA: 0x52AF20
__int64 __fastcall UFG::SimObjectPropertiesComponent::GetChildType(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::SimObject *v2; // r8
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  unsigned int v5; // ecx
  unsigned int v6; // er9
  UFG::SimComponentHolder *v7; // rdi
  UFG::qPropertySet *v9; // rcx
  UFG::qPropertySet *v10; // rax
  unsigned int *v11; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rax
  unsigned int v13; // er8
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v1 = pSceneObj;
  if ( !pSceneObj )
    return 0i64;
  v2 = pSceneObj->m_pSimObject;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[3].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = v2->m_Components.p[4].m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = (unsigned int)v2[1].vfptr;
        v6 = v2->m_Components.size;
        if ( v5 >= v6 )
        {
LABEL_17:
          v4 = 0i64;
        }
        else
        {
          v7 = v2->m_Components.p;
          while ( (v7[v5].m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
               || UFG::SimObjectPropertiesComponent::_TypeUID & ~v7[v5].m_TypeUID & 0x1FFFFFF )
          {
            if ( ++v5 >= v6 )
              goto LABEL_17;
          }
          v4 = v7[v5].m_pComponent;
        }
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(pSceneObj->m_pSimObject, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v2->m_Components.p[3].m_pComponent;
    }
    if ( v4 )
      return LODWORD(v4[1].m_SafePointerList.mNode.mNext);
  }
  v9 = v1->mpWritableProperties;
  if ( !v9 )
    v9 = v1->mpConstProperties;
  v10 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          v9,
          (UFG::qSymbol *)&component_SimObjectProperties::sPropertyName.mUID,
          DEPTH_RECURSE);
  if ( !v10 )
    return 0i64;
  v11 = (unsigned int *)UFG::qPropertySet::GetMemImagePtr(v10);
  if ( !v11 || *v11 == UFG::gNullQSymbol.mUID )
    return 0i64;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = *v11;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gSimObjectTypeTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectTypeTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    v12 = UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v12;
    pTrackEnumBinding.mNext = &UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gSimObjectTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v13 = pTrackEnumBinding.m_EnumValue;
  v14 = pTrackEnumBinding.mPrev;
  v15 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v15->mPrev = v14;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  return v13;
}

