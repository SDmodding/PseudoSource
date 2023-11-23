// File Line: 40
// RVA: 0x1544000
__int64 dynamic_initializer_for__UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList__);
}

// File Line: 41
// RVA: 0x532530
const char *__fastcall UFG::SimObjectCharacterPropertiesComponent::GetTypeName(
        UFG::SimObjectCharacterPropertiesComponent *this)
{
  return "SimObjectCharacterPropertiesComponent";
}

// File Line: 55
// RVA: 0x518850
void __fastcall UFG::SimObjectCharacterPropertiesComponent::SimObjectCharacterPropertiesComponent(
        UFG::SimObjectCharacterPropertiesComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        component_CharacterProperties *dataPtr)
{
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *mPrev; // rax

  UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(this, name_uid, dataPtr);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>::mPrev = &this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>;
  this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>::mNext = &this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>;
  this->UFG::SimObjectPropertiesComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectCharacterPropertiesComponent::`vftable{for `UFG::SimObjectPropertiesComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::SimObjectCharacterPropertiesComponent::`vftable{for `UFG::UpdateInterface};
  this->mIsTired = 0;
  *(_QWORD *)&this->m_eGender = 0i64;
  *(_QWORD *)&this->m_eFightingClass = 0i64;
  this->m_symFactionClass = UFG::gNullQSymbol;
  *(_QWORD *)&this->m_CharacterStats[0].m_fStat = 0i64;
  *(_QWORD *)&this->m_CharacterStats[2].m_fStat = 0i64;
  *(_QWORD *)&this->m_CharacterStats[4].m_fStat = 0i64;
  this->m_CharacterStats[6].m_fStat = 0.0;
  this->mBooleans.mBits[0] = 0i64;
  *((_BYTE *)this + 248) &= ~1u;
  mPrev = UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mPrev;
  UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>;
  this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>::mNext = (UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *)&UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList;
  UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mPrev = &this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::SimObjectCharacterPropertiesComponent::_SimObjectCharacterPropertiesComponentTypeUID,
    "SimObjectCharacterPropertiesComponent");
  this->m_CharacterStats[3].m_fStat = UFG::qRandom(0.30000001, (unsigned int *)&UFG::qDefaultSeed) + 0.85000002;
  UFG::SimObjectCharacterPropertiesComponent::ResetFromProperties(this, dataPtr);
  this->mBooleans.mBits[0] |= 0x3FFui64;
}

// File Line: 79
// RVA: 0x51C4C0
void __fastcall UFG::SimObjectCharacterPropertiesComponent::~SimObjectCharacterPropertiesComponent(
        UFG::SimObjectCharacterPropertiesComponent *this)
{
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v2; // rdx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *mPrev; // rcx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *mNext; // rax
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v5; // rcx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v6; // rax

  this->UFG::SimObjectPropertiesComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectCharacterPropertiesComponent::`vftable{for `UFG::SimObjectPropertiesComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::SimObjectCharacterPropertiesComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentpCurrentIterator )
    UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentpCurrentIterator = (UFG::SimObjectCharacterPropertiesComponent *)&this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>::mPrev[-10];
  v2 = &this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>;
  mPrev = this->UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimObjectPropertiesComponent::~SimObjectPropertiesComponent(this);
}

// File Line: 93
// RVA: 0x546AB0
UFG::SimComponent *__fastcall UFG::SimObjectCharacterPropertiesComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
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

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CharacterProperties::sPropertyName,
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
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x100ui64, "SimObjectCharacterPropertiesComponent", 0i64, 1u);
  if ( v10 )
  {
    mpConstProperties = pSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSceneObj->mpConstProperties;
    UFG::SimObjectCharacterPropertiesComponent::SimObjectCharacterPropertiesComponent(
      (UFG::SimObjectCharacterPropertiesComponent *)v10,
      pSceneObj->m_NameUID,
      mpConstProperties,
      (component_CharacterProperties *)MemImagePtr);
    v6 = v12;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v15 = 3;
  else
    v15 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v16, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v6;
}

// File Line: 110
// RVA: 0x53E670
void __fastcall UFG::SimObjectCharacterPropertiesComponent::OnAttach(
        UFG::SimObjectCharacterPropertiesComponent *this,
        UFG::SimObject *pObject)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v6; // rax
  UFG::SceneObjectProperties *v7; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  bool *v9; // rax
  bool v10; // al

  UFG::SimObjectPropertiesComponent::OnAttach(this, pObject);
  *(_QWORD *)this->m_ActionTreeStateFlag = 0i64;
  *(_WORD *)&this->m_ActionTreeStateFlag[8] = 0;
  m_pSceneObj = pObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v6 = UFG::qPropertySet::Get<bool>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_IgnoreAmbientStimuli,
         DEPTH_RECURSE);
  if ( v6 && *v6 )
    this->mBooleans.mBits[0] |= 0x400ui64;
  else
    this->mBooleans.mBits[0] &= ~0x400ui64;
  v7 = pObject->m_pSceneObj;
  mpConstProperties = v7->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = v7->mpConstProperties;
  v9 = UFG::qPropertySet::Get<bool>(
         mpConstProperties,
         (UFG::qArray<unsigned long,0> *)&qSymbol_IsPossessed,
         DEPTH_RECURSE);
  if ( v9 )
  {
    v10 = *v9;
    *((_BYTE *)this + 248) &= ~1u;
    *((_BYTE *)this + 248) |= v10;
  }
  else
  {
    *((_BYTE *)this + 248) ^= (*((_BYTE *)this + 248) ^ UFG::ProgressionTracker::Instance()->mIsPossessedPedsEnabled) & 1;
  }
}

// File Line: 143
// RVA: 0x540B90
void __fastcall UFG::SimObjectCharacterPropertiesComponent::OnDetach(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v3; // rbx

  p = this->m_ClassTypeListArray.p;
  if ( p )
  {
    v3 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  this->m_ClassTypeListArray.p = 0i64;
  *(_QWORD *)&this->m_ClassTypeListArray.size = 0i64;
}

// File Line: 149
// RVA: 0x53CBA0
void __fastcall UFG::SimObjectCharacterPropertiesComponent::NotifyProxyModeChanged(
        UFG::SimObjectCharacterPropertiesComponent *this,
        UFG::SimObject::eProxyMode proxyMode)
{
  if ( proxyMode )
  {
    if ( this->m_eCharacterType == eCHARACTER_TYPE_PLAYER )
      this->m_eCharacterType = eCHARACTER_TYPE_NET_REMOTE_PLAYER;
  }
}

// File Line: 193
// RVA: 0x54C960
void __fastcall UFG::SimObjectCharacterPropertiesComponent::SetFactionClass(
        UFG::SimObjectCharacterPropertiesComponent *this,
        UFG::eFactionClassEnum faction)
{
  UFG::GameStatTracker *v4; // rax

  v4 = UFG::FactionInterface::Get();
  this->m_symFactionClass.mUID = UFG::FactionInterface::MapFactionToSymbol(&v4->mFactionInterface, faction)->mUID;
  this->m_eFactionClass = faction;
}

// File Line: 205
// RVA: 0x54A020
void __fastcall UFG::SimObjectCharacterPropertiesComponent::ResetFromProperties(
        UFG::SimObjectCharacterPropertiesComponent *this,
        component_CharacterProperties *dataPtr)
{
  unsigned int mUID; // eax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  unsigned int v6; // eax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  UFG::eFactionClassEnum v8; // ebx
  UFG::GameStatTracker *v9; // rax
  unsigned int v10; // eax
  UFG::eGenderEnum v11; // ecx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rax
  TracksEnumBinding<unsigned long> v16; // [rsp+28h] [rbp-48h] BYREF
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+48h] [rbp-28h] BYREF
  UFG::qSymbol symbol; // [rsp+98h] [rbp+28h] BYREF

  if ( dataPtr )
  {
    mUID = dataPtr->simObjectCharacterType.mUID;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gCharacterTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gCharacterTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gCharacterTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gCharacterTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gCharacterTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gCharacterTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    this->m_eCharacterType = pTrackEnumBinding.m_EnumValue;
    v6 = dataPtr->simObjectCharacterFightingClass.mUID;
    v16.mPrev = &v16;
    v16.mNext = &v16;
    v16.m_EnumSymbol.mUID = v6;
    *(_QWORD *)&v16.m_EnumValue = 0i64;
    v16.m_uEnumUID = 0;
    if ( UFG::gFightingClassEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gFightingClassEnum, &v16);
    }
    else
    {
      v7 = UFG::gFightingClassEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gFightingClassEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &v16;
      v16.mPrev = v7;
      v16.mNext = &UFG::gFightingClassEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gFightingClassEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &v16;
    }
    this->m_eFightingClass = v16.m_EnumValue;
    this->m_CharacterStats[1].m_fStat = (float)dataPtr->Stamina;
    this->mIsTired = dataPtr->IsTired;
    symbol.mUID = dataPtr->FactionClass.mUID;
    if ( symbol.mUID != UFG::gNullQSymbol.mUID )
    {
      v8 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(&symbol);
      v9 = UFG::FactionInterface::Get();
      this->m_symFactionClass.mUID = UFG::FactionInterface::MapFactionToSymbol(&v9->mFactionInterface, v8)->mUID;
      this->m_eFactionClass = v8;
    }
    this->m_eGender = eGENDER_INVALID;
    v10 = dataPtr->Gender.mUID;
    if ( v10 != UFG::gNullQSymbol.mUID )
    {
      if ( v10 == qSymbol_Male.mUID )
      {
        this->m_eGender = eGENDER_MALE;
      }
      else
      {
        v11 = eGENDER_INVALID;
        if ( v10 == qSymbol_Female.mUID )
          v11 = eGENDER_FEMALE;
        this->m_eGender = v11;
      }
    }
    v12 = v16.mPrev;
    mNext = v16.mNext;
    v16.mPrev->mNext = v16.mNext;
    mNext->mPrev = v12;
    v14 = pTrackEnumBinding.mPrev;
    v15 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v15->mPrev = v14;
  }
};
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v15->mPrev = v14;

// File Line: 255
// RVA: 0x549C00
void __fastcall UFG::SimObjectCharacterPropertiesComponent::Reset(
        UFG::SimObjectCharacterPropertiesComponent *this,
        bool soft_reset)
{
  UFG::SimObject *m_pSimObject; // rsi
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v7; // rax
  char *MemImagePtr; // rdi

  m_pSimObject = this->m_pSimObject;
  m_pSceneObj = m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CharacterProperties::sPropertyName,
         DEPTH_RECURSE);
  if ( v7 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v7);
  else
    MemImagePtr = 0i64;
  ((void (__fastcall *)(UFG::SimObjectCharacterPropertiesComponent *))this->UFG::SimObjectPropertiesComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[10].__vecDelDtor)(this);
  this->UFG::SimObjectPropertiesComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[6].__vecDelDtor(
    this,
    (unsigned int)m_pSimObject);
  UFG::SimObjectCharacterPropertiesComponent::ResetFromProperties(this, (component_CharacterProperties *)MemImagePtr);
  if ( !soft_reset )
  {
    this->mBooleans.mBits[0] = 0i64;
    this->mBooleans.mBits[0] |= 0x3FFui64;
  }
}

