// File Line: 40
// RVA: 0x1544000
__int64 dynamic_initializer_for__UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList__);
}

// File Line: 41
// RVA: 0x532530
const char *__fastcall UFG::SimObjectCharacterPropertiesComponent::GetTypeName(UFG::SimObjectCharacterPropertiesComponent *this)
{
  return "SimObjectCharacterPropertiesComponent";
}

// File Line: 55
// RVA: 0x518850
void __fastcall UFG::SimObjectCharacterPropertiesComponent::SimObjectCharacterPropertiesComponent(UFG::SimObjectCharacterPropertiesComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, component_CharacterProperties *dataPtr)
{
  component_CharacterProperties *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rdi
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v6; // rdx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v7; // rax

  v4 = dataPtr;
  v5 = this;
  UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(
    (UFG::SimObjectPropertiesComponent *)&this->vfptr,
    name_uid,
    &dataPtr->0);
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable';
  v6 = (UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectCharacterPropertiesComponent::`vftable'{for `UFG::SimObjectPropertiesComponent'};
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::SimObjectCharacterPropertiesComponent::`vftable'{for `UFG::UpdateInterface'};
  v5->mIsTired = 0;
  *(_QWORD *)&v5->m_eGender = 0i64;
  *(_QWORD *)&v5->m_eFightingClass = 0i64;
  v5->m_symFactionClass = UFG::gNullQSymbol;
  *(_QWORD *)&v5->m_CharacterStats[0].m_fStat = 0i64;
  *(_QWORD *)&v5->m_CharacterStats[2].m_fStat = 0i64;
  *(_QWORD *)&v5->m_CharacterStats[4].m_fStat = 0i64;
  v5->m_CharacterStats[6].m_fStat = 0.0;
  v5->mBooleans.mBits[0] = 0i64;
  *((_BYTE *)v5 + 248) &= 0xFEu;
  v7 = UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mPrev;
  UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *)&v5->mPrev;
  v6->mPrev = v7;
  v5->mNext = (UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *)&UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList;
  UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mPrev = (UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::SimObjectCharacterPropertiesComponent::_SimObjectCharacterPropertiesComponentTypeUID,
    "SimObjectCharacterPropertiesComponent");
  v5->m_CharacterStats[3].m_fStat = UFG::qRandom(0.30000001, &UFG::qDefaultSeed) + 0.85000002;
  UFG::SimObjectCharacterPropertiesComponent::ResetFromProperties(v5, v4);
  v5->mBooleans.mBits[0] |= 0x3FFui64;
}

// File Line: 79
// RVA: 0x51C4C0
void __fastcall UFG::SimObjectCharacterPropertiesComponent::~SimObjectCharacterPropertiesComponent(UFG::SimObjectCharacterPropertiesComponent *this)
{
  UFG::SimObjectCharacterPropertiesComponent *v1; // r8
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v2; // rdx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v3; // rcx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v4; // rax
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v5; // rcx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectCharacterPropertiesComponent::`vftable'{for `UFG::SimObjectPropertiesComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::SimObjectCharacterPropertiesComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentpCurrentIterator )
    UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentpCurrentIterator = (UFG::SimObjectCharacterPropertiesComponent *)&this->mPrev[-10];
  v2 = (UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimObjectPropertiesComponent::~SimObjectPropertiesComponent((UFG::SimObjectPropertiesComponent *)&v1->vfptr);
}

// File Line: 93
// RVA: 0x546AB0
UFG::SimComponent *__fastcall UFG::SimObjectCharacterPropertiesComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
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
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_CharacterProperties::sPropertyName.mUID,
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
  v10 = UFG::qMemoryPool::Allocate(v9, 0x100ui64, "SimObjectCharacterPropertiesComponent", 0i64, 1u);
  if ( v10 )
  {
    v11 = v3->mpWritableProperties;
    if ( !v11 )
      v11 = v3->mpConstProperties;
    UFG::SimObjectCharacterPropertiesComponent::SimObjectCharacterPropertiesComponent(
      (UFG::SimObjectCharacterPropertiesComponent *)v10,
      v3->m_NameUID,
      v11,
      (component_CharacterProperties *)v7);
    v6 = v12;
  }
  v13 = v3->m_pSimObject;
  v14 = v13->m_Flags;
  if ( (v14 >> 14) & 1 || (v14 & 0x8000u) != 0 )
    v15 = 3;
  else
    v15 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v16, v13, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v6;
}

// File Line: 110
// RVA: 0x53E670
void __fastcall UFG::SimObjectCharacterPropertiesComponent::OnAttach(UFG::SimObjectCharacterPropertiesComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *v2; // rdi
  UFG::SimObjectCharacterPropertiesComponent *v3; // rbx
  UFG::SceneObjectProperties *v4; // rax
  UFG::qPropertySet *v5; // rcx
  bool *v6; // rax
  UFG::SceneObjectProperties *v7; // rax
  UFG::qPropertySet *v8; // rcx
  bool *v9; // rax
  bool v10; // al

  v2 = pObject;
  v3 = this;
  UFG::SimObjectPropertiesComponent::OnAttach((UFG::SimObjectPropertiesComponent *)&this->vfptr, pObject);
  *(_QWORD *)v3->m_ActionTreeStateFlag = 0i64;
  *(_WORD *)&v3->m_ActionTreeStateFlag[8] = 0;
  v4 = v2->m_pSceneObj;
  v5 = v4->mpWritableProperties;
  if ( !v5 )
    v5 = v4->mpConstProperties;
  v6 = UFG::qPropertySet::Get<bool>(v5, (UFG::qSymbol *)&SimSym_IgnoreAmbientStimuli.mUID, DEPTH_RECURSE);
  if ( v6 && *v6 )
    v3->mBooleans.mBits[0] |= 0x400ui64;
  else
    v3->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFBFFui64;
  v7 = v2->m_pSceneObj;
  v8 = v7->mpWritableProperties;
  if ( !v8 )
    v8 = v7->mpConstProperties;
  v9 = UFG::qPropertySet::Get<bool>(v8, (UFG::qSymbol *)&qSymbol_IsPossessed.mUID, DEPTH_RECURSE);
  if ( v9 )
  {
    v10 = *v9;
    *((_BYTE *)v3 + 248) &= 0xFEu;
    *((_BYTE *)v3 + 248) |= v10;
  }
  else
  {
    *((_BYTE *)v3 + 248) ^= (*((_BYTE *)v3 + 248) ^ UFG::ProgressionTracker::Instance()->mIsPossessedPedsEnabled) & 1;
  }
}

// File Line: 143
// RVA: 0x540B90
void __fastcall UFG::SimObjectCharacterPropertiesComponent::OnDetach(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::SimObjectWeaponPropertiesComponent *v1; // rdi
  UFG::qSymbol *v2; // rcx
  UFG::qSymbol *v3; // rbx

  v1 = this;
  v2 = this->m_ClassTypeListArray.p;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator'(v2, 4ui64, v2[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  v1->m_ClassTypeListArray.p = 0i64;
  *(_QWORD *)&v1->m_ClassTypeListArray.size = 0i64;
}

// File Line: 149
// RVA: 0x53CBA0
void __fastcall UFG::SimObjectCharacterPropertiesComponent::NotifyProxyModeChanged(UFG::SimObjectCharacterPropertiesComponent *this, UFG::SimObject::eProxyMode proxyMode)
{
  if ( proxyMode )
  {
    if ( this->m_eCharacterType == 1 )
      this->m_eCharacterType = 15;
  }
}

// File Line: 193
// RVA: 0x54C960
void __fastcall UFG::SimObjectCharacterPropertiesComponent::SetFactionClass(UFG::SimObjectCharacterPropertiesComponent *this, UFG::eFactionClassEnum faction)
{
  UFG::eFactionClassEnum v2; // edi
  UFG::qStaticSymbol *v3; // rbx
  UFG::GameStatTracker *v4; // rax

  v2 = faction;
  v3 = (UFG::qStaticSymbol *)this;
  v4 = UFG::FactionInterface::Get();
  v3[51].mUID = UFG::FactionInterface::MapFactionToSymbol(&v4->mFactionInterface, v2)->mUID;
  v3[50].mUID = v2;
}

// File Line: 205
// RVA: 0x54A020
void __fastcall UFG::SimObjectCharacterPropertiesComponent::ResetFromProperties(UFG::SimObjectCharacterPropertiesComponent *this, component_CharacterProperties *dataPtr)
{
  component_CharacterProperties *v2; // rsi
  UFG::SimObjectCharacterPropertiesComponent *v3; // rdi
  unsigned int v4; // eax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rax
  unsigned int v6; // eax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  UFG::eFactionClassEnum v8; // ebx
  UFG::GameStatTracker *v9; // rax
  unsigned int v10; // eax
  signed int v11; // ecx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rax
  TracksEnumBinding<unsigned long> v16; // [rsp+28h] [rbp-48h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+48h] [rbp-28h]
  UFG::qSymbol symbol; // [rsp+98h] [rbp+28h]

  if ( dataPtr )
  {
    v2 = dataPtr;
    v3 = this;
    v4 = dataPtr->simObjectCharacterType.mUID;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = v4;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gCharacterTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gCharacterTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      v5 = UFG::gCharacterTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gCharacterTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v5;
      pTrackEnumBinding.mNext = &UFG::gCharacterTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gCharacterTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v3->m_eCharacterType = pTrackEnumBinding.m_EnumValue;
    v6 = v2->simObjectCharacterFightingClass.mUID;
    v16.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v16;
    v16.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v16;
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
      UFG::gFightingClassEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v16;
      v16.mPrev = v7;
      v16.mNext = &UFG::gFightingClassEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gFightingClassEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v16;
    }
    v3->m_eFightingClass = v16.m_EnumValue;
    v3->m_CharacterStats[1].m_fStat = (float)v2->Stamina;
    v3->mIsTired = v2->IsTired;
    symbol.mUID = v2->FactionClass.mUID;
    if ( symbol.mUID != UFG::gNullQSymbol.mUID )
    {
      v8 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(&symbol);
      v9 = UFG::FactionInterface::Get();
      v3->m_symFactionClass.mUID = UFG::FactionInterface::MapFactionToSymbol(&v9->mFactionInterface, v8)->mUID;
      v3->m_eFactionClass = v8;
    }
    v3->m_eGender = 0;
    v10 = v2->Gender.mUID;
    if ( v10 != UFG::gNullQSymbol.mUID )
    {
      if ( v10 == qSymbol_Male.mUID )
      {
        v3->m_eGender = 1;
      }
      else
      {
        v11 = 0;
        if ( v10 == qSymbol_Female.mUID )
          v11 = 2;
        v3->m_eGender = v11;
      }
    }
    v12 = v16.mPrev;
    v13 = v16.mNext;
    v16.mPrev->mNext = v16.mNext;
    v13->mPrev = v12;
    v14 = pTrackEnumBinding.mPrev;
    v15 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v15->mPrev = v14;
  }
}

// File Line: 255
// RVA: 0x549C00
void __fastcall UFG::SimObjectCharacterPropertiesComponent::Reset(UFG::SimObjectCharacterPropertiesComponent *this, bool soft_reset)
{
  UFG::SimObject *v2; // rsi
  UFG::SimObjectCharacterPropertiesComponent *v3; // rbx
  bool v4; // bp
  UFG::SceneObjectProperties *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax
  char *v8; // rdi

  v2 = this->m_pSimObject;
  v3 = this;
  v4 = soft_reset;
  v5 = v2->m_pSceneObj;
  v6 = v5->mpWritableProperties;
  if ( !v6 )
    v6 = v5->mpConstProperties;
  v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v6,
         (UFG::qSymbol *)&component_CharacterProperties::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v7 )
    v8 = UFG::qPropertySet::GetMemImagePtr(v7);
  else
    v8 = 0i64;
  ((void (__fastcall *)(UFG::SimObjectCharacterPropertiesComponent *))v3->vfptr[10].__vecDelDtor)(v3);
  v3->vfptr[6].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, (unsigned int)v2);
  UFG::SimObjectCharacterPropertiesComponent::ResetFromProperties(v3, (component_CharacterProperties *)v8);
  if ( !v4 )
  {
    v3->mBooleans.mBits[0] = 0i64;
    v3->mBooleans.mBits[0] |= 0x3FFui64;
  }
}

