// File Line: 39
// RVA: 0x14D92B0
__int64 dynamic_initializer_for__UFG::ThugsEncounter::s_ThugsEncounterList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ThugsEncounter::s_ThugsEncounterList__);
}

// File Line: 49
// RVA: 0x3F2660
void __fastcall UFG::ThugsEncounter::ThugsEncounter(UFG::ThugsEncounter *this)
{
  UFG::ThugsEncounter *v1; // rbx
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v2; // rdx
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v3; // rax

  v1 = this;
  UFG::EncounterBase::EncounterBase((UFG::EncounterBase *)&this->vfptr);
  v2 = (UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::ThugsEncounter::`vftable';
  v1->mpOwnerGameSlice = 0i64;
  *(_DWORD *)&v1->mIsStarted = 0;
  v1->mCanEnterExitVehicle = 2;
  v3 = UFG::ThugsEncounter::s_ThugsEncounterList.mNode.mPrev;
  UFG::ThugsEncounter::s_ThugsEncounterList.mNode.mPrev->mNext = (UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *)&v1->mPrev;
  v2->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *)&UFG::ThugsEncounter::s_ThugsEncounterList;
  UFG::ThugsEncounter::s_ThugsEncounterList.mNode.mPrev = (UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *)&v1->mPrev;
}

// File Line: 54
// RVA: 0x3F2AA0
void __fastcall UFG::ThugsEncounter::~ThugsEncounter(UFG::ThugsEncounter *this)
{
  UFG::ThugsEncounter *v1; // rdi
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v2; // rbx
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v3; // rcx
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v4; // rax
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v5; // rcx
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::ThugsEncounter::`vftable';
  if ( this == UFG::ThugsEncounter::s_ThugsEncounterpCurrentIterator )
    UFG::ThugsEncounter::s_ThugsEncounterpCurrentIterator = (UFG::ThugsEncounter *)&this->mPrev[-201];
  v2 = (UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::ThugsEncounter::Cleanup(v1);
  UFG::EncounterBase::Shutdown((UFG::EncounterBase *)&v1->vfptr);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::EncounterBase::~EncounterBase((UFG::EncounterBase *)&v1->vfptr);
}

// File Line: 61
// RVA: 0x3F98D0
void __fastcall UFG::ThugsEncounter::Shutdown(UFG::ThugsEncounter *this)
{
  UFG::ThugsEncounter *v1; // rbx

  v1 = this;
  UFG::ThugsEncounter::Cleanup(this);
  UFG::EncounterBase::Shutdown((UFG::EncounterBase *)&v1->vfptr);
}

// File Line: 67
// RVA: 0x3F98F0
void __fastcall UFG::ThugsEncounter::Start(UFG::ThugsEncounter *this, UFG::qSymbol *firstWave, bool startRunning)
{
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v3; // rax
  UFG::ThugsEncounter *v4; // rdi
  UFG::qPropertyList *v5; // rax
  char *v6; // rax
  UFG::qPropertySet *v7; // rcx

  this->mIsStarted = startRunning;
  *(_WORD *)&this->mIsPaused = 256;
  this->mStartTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  v3 = this->vfptr;
  v4 = this;
  if ( firstWave->mUID == -1 )
  {
    this->mHeatLevel = 1;
    if ( !((__int64 (*)(void))v3[33].__vecDelDtor)() )
    {
      UFG::PropertySetHandle::Bind(&v4->mProperties);
      v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             v4->mProperties.mpPropSet,
             (UFG::qSymbol *)&EncounterSym_wave_definitions.mUID,
             DEPTH_RECURSE);
      v6 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, 0);
      if ( v6 && *(_QWORD *)v6 )
        v7 = (UFG::qPropertySet *)&v6[*(_QWORD *)v6];
      else
        v7 = 0i64;
      v4->mHeatLevelProperties[v4->mHeatLevel] = v7;
      v4->mWaterHeatLevelProperties[v4->mHeatLevel] = v4->mHeatLevelProperties[v4->mHeatLevel];
      ((void (__fastcall *)(UFG::ThugsEncounter *))v4->vfptr[33].__vecDelDtor)(v4);
    }
    ((void (__fastcall *)(UFG::ThugsEncounter *))v4->vfptr[23].__vecDelDtor)(v4);
    ((void (__fastcall *)(UFG::ThugsEncounter *))v4->vfptr[50].__vecDelDtor)(v4);
  }
  else
  {
    ((void (*)(void))v3[25].__vecDelDtor)();
  }
}

// File Line: 106
// RVA: 0x3F99E0
void __fastcall UFG::ThugsEncounter::Stop(UFG::ThugsEncounter *this)
{
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v1; // rax

  v1 = this->vfptr;
  *(_WORD *)&this->mIsStarted = 0;
  this->mIsInside = 0;
  this->mHeatLevel = 0;
  ((void (*)(void))v1[50].__vecDelDtor)();
}

// File Line: 117
// RVA: 0x3F3520
void __fastcall UFG::ThugsEncounter::Cleanup(UFG::ThugsEncounter *this)
{
  bool v1; // zf
  UFG::ThugsEncounter *v2; // rbx

  v1 = this->mHumans.size == 0;
  v2 = this;
  *(_WORD *)&this->mIsStarted = 0;
  this->mIsInside = 0;
  this->mHeatLevel = 0;
  if ( !v1 )
  {
    do
    {
      v2->vfptr[37].__vecDelDtor(
        (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
        (unsigned int)v2->mHumans.p[0]);
      v2->mHumans.p[0] = v2->mHumans.p[--v2->mHumans.size];
    }
    while ( v2->mHumans.size );
  }
  for ( ; v2->mVehicles.size; v2->mVehicles.p[0] = v2->mVehicles.p[v2->mVehicles.size] )
  {
    v2->vfptr[37].__vecDelDtor(
      (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
      (unsigned int)v2->mVehicles.p[0]);
    --v2->mVehicles.size;
  }
}

// File Line: 137
// RVA: 0x3F9420
void __fastcall UFG::ThugsEncounter::SetOwnerGameSlice(UFG::ThugsEncounter *this, UFG::GameSlice *pGameSlice)
{
  this->mpOwnerGameSlice = pGameSlice;
}

// File Line: 142
// RVA: 0x3F3390
void __fastcall UFG::ThugsEncounter::AttachIndicator(UFG::ThugsEncounter *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::EncounterUnitComponent *v2; // rsi
  char v3; // di
  UFG::SimObject *v4; // rbp
  UFG::PropertySetHandle *v5; // rbx
  UFG::qPropertySet *v6; // rbx
  char *v7; // r14
  char *v8; // r15
  UFG::allocator::free_link *v9; // rbx
  UFG::ObjectiveIndicator *v10; // rax
  UFG::qString blip; // [rsp+40h] [rbp-68h]
  UFG::qString corona; // [rsp+68h] [rbp-40h]

  v2 = pEncounterUnitComponent;
  v3 = 0;
  v4 = pEncounterUnitComponent->m_pSimObject;
  if ( v4 )
  {
    v5 = &this->mProperties;
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v6 = v5->mpPropSet;
    v7 = UFG::qPropertySet::Get<char const *>(v6, (UFG::qSymbol *)&qSymbol_BlipName.mUID, DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<char const *>(v6, (UFG::qSymbol *)&qSymbol_CoronaName.mUID, DEPTH_RECURSE);
    if ( v7 )
    {
      if ( *v7 )
      {
        UFG::SimObjectUtility::AttachHudSymbol(v4, v7, 0, 0.0, &customWorldMapCaption);
        if ( v8 )
        {
          if ( *v8 )
          {
            v9 = UFG::qMalloc(0x60ui64, "ThugsEncounter::ObjectiveIndicator", 0i64);
            if ( v9 )
            {
              UFG::qString::qString(&corona, v8);
              UFG::qString::qString(&blip, v7);
              v3 = 3;
              UFG::ObjectiveIndicator::ObjectiveIndicator((UFG::ObjectiveIndicator *)v9, &v4->m_Name, &blip, &corona, 1);
            }
            else
            {
              v10 = 0i64;
            }
            v2->mpObjectiveIndicator = v10;
            if ( v3 & 2 )
            {
              v3 &= 0xFDu;
              UFG::qString::~qString(&blip);
            }
            if ( v3 & 1 )
              UFG::qString::~qString(&corona);
            UFG::ObjectiveIndicator::SetEnabled(v2->mpObjectiveIndicator, 1);
          }
        }
      }
    }
  }
}

// File Line: 173
// RVA: 0x3F6B80
UFG::EncounterUnitComponent *__fastcall UFG::ThugsEncounter::HandleOnFootSpawn(UFG::ThugsEncounter *this, UFG::qMatrix44 *pSpawnTransform, UFG::qPropertySet *pGroupPropertySet, UFG::qSymbol *pSpecificCharacterResource)
{
  UFG::ThugsEncounter *v4; // rdi
  UFG::EncounterUnitComponent *v5; // rbx

  v4 = this;
  v5 = (UFG::EncounterUnitComponent *)UFG::EncounterBase::HandleOnFootSpawn(
                                        (UFG::EncounterBase *)&this->vfptr,
                                        pSpawnTransform,
                                        pGroupPropertySet,
                                        pSpecificCharacterResource);
  if ( ((unsigned __int8 (__fastcall *)(UFG::ThugsEncounter *))v4->vfptr[61].__vecDelDtor)(v4) )
    UFG::ThugsEncounter::AttachIndicator(v4, v5);
  return v5;
}

// File Line: 186
// RVA: 0x3F6F00
void __fastcall UFG::ThugsEncounter::HandleOnFootSpawnPost(UFG::ThugsEncounter *this, UFG::SimObject *pOnFootSpawn)
{
  UFG::SimObject *v2; // rdi
  UFG::ThugsEncounter *v3; // rbx
  UFG::qPropertySet *v4; // rax

  v2 = pOnFootSpawn;
  v3 = this;
  UFG::EncounterBase::HandleOnFootSpawnPost((UFG::EncounterBase *)&this->vfptr, pOnFootSpawn);
  if ( v3->mCanEnterExitVehicle != 2 )
  {
    v4 = UFG::SceneObjectProperties::GetWritableProperties(v2->m_pSceneObj);
    UFG::qPropertySet::Set<bool>(v4, (UFG::qSymbol *)&qSymbol_CanEnterExitVehicle.mUID, v3->mCanEnterExitVehicle == 1);
  }
}

// File Line: 199
// RVA: 0x3F31A0
UFG::EncounterUnitComponent *__fastcall UFG::ThugsEncounter::AddExternalCharacterIntoSystem(UFG::ThugsEncounter *this, UFG::SimObject *pCharacter)
{
  UFG::ThugsEncounter *v2; // rdi
  UFG::EncounterUnitComponent *v3; // rbx

  v2 = this;
  v3 = (UFG::EncounterUnitComponent *)UFG::EncounterBase::AddExternalCharacterIntoSystem(
                                        (UFG::EncounterBase *)&this->vfptr,
                                        pCharacter);
  if ( ((unsigned __int8 (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[61].__vecDelDtor)(v2) )
    UFG::ThugsEncounter::AttachIndicator(v2, v3);
  return v3;
}

// File Line: 211
// RVA: 0x3F7220
void __fastcall UFG::ThugsEncounter::HandleVehicleAcquired(UFG::ThugsEncounter *this, UFG::EncounterUnitComponent *pEncounterUnitComponent, UFG::qPropertySet *pEncounterPropertySet, UFG::qPropertySet *pGroupPropertySet)
{
  UFG::EncounterUnitComponent *v4; // rdi
  UFG::ThugsEncounter *v5; // rbx

  v4 = pEncounterUnitComponent;
  v5 = this;
  UFG::EncounterBase::HandleVehicleAcquired(
    (UFG::EncounterBase *)&this->vfptr,
    pEncounterUnitComponent,
    pEncounterPropertySet,
    pGroupPropertySet);
  if ( !((unsigned __int8 (__fastcall *)(UFG::ThugsEncounter *))v5->vfptr[61].__vecDelDtor)(v5) )
    UFG::ThugsEncounter::AttachIndicator(v5, v4);
}

// File Line: 221
// RVA: 0x3F2E00
void __fastcall UFG::ThugsEncounter::Acquire(UFG::ThugsEncounter *this, UFG::EncounterUnitComponent *pEncounterUnitComponent, UFG::qPropertySet *pGroupPropertySet)
{
  UFG::EncounterUnitComponent *v3; // rdi
  UFG::ThugsEncounter *v4; // rbx
  UFG::GameSlice *v5; // rbx
  UFG::TSActor *v6; // rax
  UFG::TSActor *v7; // [rsp+40h] [rbp+8h]

  v3 = pEncounterUnitComponent;
  v4 = this;
  UFG::EncounterUnitComponent::AcquireBy(pEncounterUnitComponent, (UFG::EncounterBase *)&this->vfptr, pGroupPropertySet);
  v5 = v4->mpOwnerGameSlice;
  if ( v5 )
    v5 = (UFG::GameSlice *)v5->mScript;
  v6 = UFG::TSActor::FromSimObject(v3->m_pSimObject);
  if ( v5 )
  {
    if ( v6 )
    {
      ++v6->i_ref_count;
      v7 = v6;
      (*(void (__fastcall **)(unsigned int *, UFG::qStaticSymbol *, UFG::TSActor **, signed __int64, _QWORD, _QWORD))(*(_QWORD *)&v5->mNode.mUID + 104i64))(
        &v5->mNode.mUID,
        &qSymbol_gameslice_register_physical_actor,
        &v7,
        1i64,
        0i64,
        0i64);
    }
  }
}

// File Line: 235
// RVA: 0x3FADC0
void __usercall UFG::ThugsEncounter::UpdatePopulation(UFG::ThugsEncounter *this@<rcx>, float deltaTime@<xmm1>, float a3@<xmm0>)
{
  UFG::ThugsEncounter *v3; // rsi
  UFG::BasePhysicsSystem *v4; // r13
  __int64 v5; // r14
  _BOOL8 v6; // r12
  unsigned int v7; // ebp
  signed int v8; // edx
  UFG::SimObjectGame *v9; // rbx
  unsigned __int16 v10; // cx
  char v11; // di
  UFG::SimComponent *v12; // rax
  unsigned int v13; // ecx
  unsigned __int16 v14; // cx
  UFG::HudComponent *v15; // rax
  unsigned int v16; // eax
  UFG::qBaseTreeRB *v17; // rdi
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rdx
  UFG::SimComponent *v20; // rax
  UFG::SimObjectGame *v21; // rbx
  unsigned __int16 v22; // cx
  UFG::HudComponent *v23; // rax
  unsigned int v24; // eax
  UFG::qBaseTreeRB *v25; // rdi
  unsigned __int16 v26; // cx
  UFG::VehicleOccupantComponent *v27; // rax
  float v28; // xmm2_4

  v3 = this;
  UFG::EncounterBase::UpdatePopulation((UFG::EncounterBase *)&this->vfptr, deltaTime);
  v4 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    UFG::PropertySetHandle::Bind(&v3->mProperties);
    v5 = 0i64;
    v6 = *UFG::qPropertySet::Get<bool>(
            v3->mProperties.mpPropSet,
            (UFG::qSymbol *)&EncounterSym_show_blip_radius.mUID,
            DEPTH_RECURSE);
    v7 = 0;
    if ( v3->mHumans.size )
    {
      v8 = 8720;
      do
      {
        v9 = (UFG::SimObjectGame *)v3->mHumans.p[v7]->m_pSimObject;
        if ( v9 )
        {
          v10 = v9->m_Flags;
          v11 = 0;
          if ( (v10 >> 14) & 1 )
          {
            v12 = v9->m_Components.p[44].m_pComponent;
          }
          else
          {
            if ( (v10 & 0x8000u) == 0 )
            {
              if ( (v10 >> 13) & 1 )
              {
                v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
              }
              else if ( (v10 >> 12) & 1 )
              {
                v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
              }
              else
              {
                v12 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v9->vfptr,
                        UFG::CharacterOccupantComponent::_TypeUID);
              }
            }
            else
            {
              v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
            }
            v8 = 8720;
          }
          if ( v12 )
          {
            v13 = (unsigned int)v12[1].m_SafePointerList.mNode.mNext;
            if ( v13 > 0xD || !_bittest(&v8, v13) )
            {
              v11 = 1;
              UFG::SimObjectUtility::DetachHudSymbol((UFG::SimObject *)&v9->vfptr);
            }
          }
          if ( (_BYTE)v6 && !v11 )
          {
            v14 = v9->m_Flags;
            if ( (v14 >> 14) & 1 )
            {
              v15 = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HudComponent::_TypeUID);
            }
            else if ( (v14 & 0x8000u) == 0 )
            {
              if ( (v14 >> 13) & 1 )
                v15 = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HudComponent::_TypeUID);
              else
                v15 = (UFG::HudComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v9,
                                                                UFG::HudComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v9->vfptr,
                                                                                                 UFG::HudComponent::_TypeUID));
            }
            else
            {
              v15 = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HudComponent::_TypeUID);
            }
            if ( v15 )
            {
              v16 = UFG::HudComponent::GetBlipGuid(v15);
              v17 = UFG::BasePhysicsSystem::GetCollisionModel(v4, v16);
              if ( v17 )
              {
                v18 = v9->m_Flags;
                if ( (v18 >> 14) & 1 )
                {
                  v19 = v9->m_Components.p[44].m_pComponent;
                }
                else
                {
                  if ( (v18 & 0x8000u) == 0 )
                  {
                    if ( (v18 >> 13) & 1 )
                    {
                      v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
                    }
                    else if ( (v18 >> 12) & 1 )
                    {
                      v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
                    }
                    else
                    {
                      v20 = UFG::SimObject::GetComponentOfType(
                              (UFG::SimObject *)&v9->vfptr,
                              UFG::CharacterOccupantComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  v19 = v20;
                }
                LOBYTE(v19) = v19 == 0i64;
                ((void (__fastcall *)(UFG::ThugsEncounter *, UFG::SimComponent *, UFG::EncounterUnitComponent *))v3->vfptr[17].__vecDelDtor)(
                  v3,
                  v19,
                  v3->mHumans.p[v7]);
                UFG::UIMapBlip::SetRange((UFG::UIMapBlip *)v17, 1, a3);
              }
            }
          }
          v8 = 8720;
        }
        ++v7;
      }
      while ( v7 < v3->mHumans.size );
    }
    if ( (_BYTE)v6 && v3->mVehicles.size > 0 )
    {
      do
      {
        v21 = (UFG::SimObjectGame *)v3->mVehicles.p[v5]->m_pSimObject;
        if ( v21 )
        {
          v22 = v21->m_Flags;
          if ( (v22 >> 14) & 1 )
          {
            v23 = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::HudComponent::_TypeUID);
          }
          else if ( (v22 & 0x8000u) == 0 )
          {
            if ( (v22 >> 13) & 1 )
              v23 = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::HudComponent::_TypeUID);
            else
              v23 = (UFG::HudComponent *)((v22 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v21,
                                                              UFG::HudComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v21->vfptr,
                                                                                               UFG::HudComponent::_TypeUID));
          }
          else
          {
            v23 = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::HudComponent::_TypeUID);
          }
          if ( v23 )
          {
            v24 = UFG::HudComponent::GetBlipGuid(v23);
            v25 = UFG::BasePhysicsSystem::GetCollisionModel(v4, v24);
            if ( v25 )
            {
              v26 = v21->m_Flags;
              if ( (v26 >> 14) & 1 )
              {
                v27 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v21,
                                                         UFG::VehicleOccupantComponent::_TypeUID);
              }
              else if ( (v26 & 0x8000u) == 0 )
              {
                if ( (v26 >> 13) & 1 )
                {
                  v27 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v21,
                                                           UFG::VehicleOccupantComponent::_TypeUID);
                }
                else if ( (v26 >> 12) & 1 )
                {
                  v27 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v21,
                                                           UFG::VehicleOccupantComponent::_TypeUID);
                }
                else
                {
                  v27 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)&v21->vfptr,
                                                           UFG::VehicleOccupantComponent::_TypeUID);
                }
              }
              else
              {
                v27 = (UFG::VehicleOccupantComponent *)v21->m_Components.p[30].m_pComponent;
              }
              if ( v27 && (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v27) )
              {
                ((void (__fastcall *)(UFG::ThugsEncounter *, _QWORD, UFG::EncounterUnitComponent *))v3->vfptr[17].__vecDelDtor)(
                  v3,
                  0i64,
                  v3->mVehicles.p[v5]);
                v28 = a3;
              }
              else
              {
                v28 = 0.0;
              }
              UFG::UIMapBlip::SetRange((UFG::UIMapBlip *)v25, 1, v28);
            }
          }
        }
        v5 = (unsigned int)(v5 + 1);
      }
      while ( (unsigned int)v5 < v3->mVehicles.size );
    }
  }
}

// File Line: 310
// RVA: 0x3FB470
void __fastcall UFG::ThugsEncounter::UpdateStatus(UFG::ThugsEncounter *this)
{
  UFG::ThugsEncounter *v1; // rbx
  char v2; // al
  bool v3; // zf
  bool v4; // al
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v5; // rax

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[8].__vecDelDtor)();
  v3 = v1->mHeatLevel == 0;
  v1->mIsInside = v2 == 0;
  v4 = v3;
  v3 = (v3 || v1->mIsCompleted) == 0;
  v1->mIsCompleted |= v4;
  if ( !v3 )
  {
    v5 = v1->vfptr;
    *(_WORD *)&v1->mIsStarted = 0;
    v1->mIsInside = 0;
    v1->mHeatLevel = 0;
    ((void (__fastcall *)(UFG::ThugsEncounter *))v5[50].__vecDelDtor)(v1);
    UFG::ThugsEncounter::Cleanup(v1);
  }
}

// File Line: 325
// RVA: 0x3F9F70
void __fastcall UFG::ThugsEncounter::Update(UFG::ThugsEncounter *this, float deltaTime)
{
  UFG::ThugsEncounter *v2; // rbx
  float v3; // xmm7_4
  __int64 v4; // rax
  __int64 v5; // rdi
  UFG::qVector3 *v6; // rdi
  float v7; // xmm0_4
  float v8; // xmm1_4
  UFG::SimObject *v9; // rax

  v2 = this;
  v3 = deltaTime;
  if ( this->mIsStarted && !this->mIsPaused )
  {
    v4 = ((__int64 (*)(void))this->vfptr[18].__vecDelDtor)();
    if ( v4 && (v5 = *(_QWORD *)(v4 + 88)) != 0 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v4 + 88));
      v6 = (UFG::qVector3 *)(v5 + 176);
    }
    else
    {
      v6 = &UFG::qVector3::msZero;
    }
    v7 = v6->y;
    v8 = v6->z;
    v2->mFocusTargetPosition.x = v6->x;
    v2->mFocusTargetPosition.y = v7;
    v2->mFocusTargetPosition.z = v8;
    v9 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[18].__vecDelDtor)(v2);
    UFG::EncounterUnitContext::Update(&v2->mFocusTargetContext, v9, v3);
    ((void (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[38].__vecDelDtor)(v2);
    ((void (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[40].__vecDelDtor)(v2);
    ((void (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[39].__vecDelDtor)(v2);
    UFG::ThugsEncounter::UpdateStatus(v2);
    ((void (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[76].__vecDelDtor)(v2);
    ((void (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[41].__vecDelDtor)(v2);
    ((void (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[83].__vecDelDtor)(v2);
  }
}

// File Line: 355
// RVA: 0x3FC0B0
__int64 __fastcall UFG::ThugsEncounter::VisualizeEncounterUnitsInfo(UFG::ThugsEncounter *this, int x, int startY)
{
  int v3; // ebx
  int v4; // esi
  UFG::ThugsEncounter *v5; // rdi
  Render::DebugDrawContext *v6; // r10
  const char *v7; // r8
  const char *v8; // rdx
  const char *v9; // rcx
  const char *v10; // rax

  v3 = startY;
  v4 = x;
  v5 = this;
  if ( UFG::EncounterBase::sVisualizeWavesInfo )
  {
    v6 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    v7 = "No";
    v8 = "No";
    v9 = "No";
    v10 = "No";
    if ( v5->mIsInside )
      v8 = "Yes";
    if ( v5->mIsCompleted )
      v9 = "Yes";
    if ( v5->mIsPaused )
      v10 = "Yes";
    if ( v5->mIsStarted )
      v7 = "Yes";
    Render::DebugDrawContext::DrawTextA(
      v6,
      v4,
      v3,
      &UFG::qColour::White,
      "IsStarted:%s  IsPaused:%s  IsCompleted:%s  IsInside:%s",
      v7,
      v10,
      v9,
      v8);
    v3 += 10;
  }
  return v3 + (unsigned int)UFG::EncounterBase::VisualizeEncounterUnitsInfo((UFG::EncounterBase *)&v5->vfptr, v4, v3);
}

// File Line: 374
// RVA: 0x3FA090
void __fastcall UFG::ThugsEncounter::UpdateAll(float deltaTime)
{
  UFG::qList<UFG::ThugsEncounter,UFG::ThugsEncounter,1,0> *v1; // rbx
  unsigned int i; // edi
  int v3; // eax

  v1 = (UFG::qList<UFG::ThugsEncounter,UFG::ThugsEncounter,1,0> *)&UFG::ThugsEncounter::s_ThugsEncounterList.mNode.mNext[-201];
  for ( i = 150; v1 != &UFG::ThugsEncounter::s_ThugsEncounterList - 201; i += v3 )
  {
    ((void (__fastcall *)(UFG::qList<UFG::ThugsEncounter,UFG::ThugsEncounter,1,0> *))v1->mNode.mPrev[5].mPrev)(v1);
    v3 = ((__int64 (__fastcall *)(UFG::qList<UFG::ThugsEncounter,UFG::ThugsEncounter,1,0> *, signed __int64, _QWORD))v1->mNode.mPrev[32].mNext)(
           v1,
           150i64,
           i);
    v1 = (UFG::qList<UFG::ThugsEncounter,UFG::ThugsEncounter,1,0> *)&v1[201].mNode.mNext[-201];
  }
}

// File Line: 387
// RVA: 0x3F49E0
void __fastcall UFG::ThugsEncounter::Forget(UFG::ThugsEncounter *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::ThugsEncounter *v2; // rdi
  UFG::ObjectiveIndicator *v3; // rcx
  UFG::EncounterUnitComponent *v4; // rbx
  unsigned int v5; // ebx

  v2 = this;
  v3 = pEncounterUnitComponent->mpObjectiveIndicator;
  v4 = pEncounterUnitComponent;
  if ( v3 )
  {
    v3->vfptr->__vecDelDtor(v3, 1u);
    v4->mpObjectiveIndicator = 0i64;
  }
  UFG::SimObjectUtility::DetachHudSymbol(v4->m_pSimObject);
  UFG::EncounterBase::Forget((UFG::EncounterBase *)&v2->vfptr, v4);
  UFG::PropertySetHandle::Bind(&v2->mProperties);
  v5 = *UFG::qPropertySet::Get<unsigned long>(
          v2->mProperties.mpPropSet,
          (UFG::qSymbol *)&EncounterSym_kills_required.mUID,
          DEPTH_RECURSE);
  if ( v5 )
  {
    if ( ((unsigned int (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[31].__vecDelDtor)(v2) >= v5 )
    {
      ((void (__fastcall *)(UFG::ThugsEncounter *))v2->vfptr[31].__vecDelDtor)(v2);
      v2->mIsCompleted = 1;
    }
  }
}

// File Line: 404
// RVA: 0x3F60D0
const char *__fastcall UFG::ThugsEncounter::GetSpawningPrefix(UFG::ThugsEncounter *this, bool isCharacter)
{
  const char *result; // rax

  result = "thug_en_vehi_";
  if ( isCharacter )
    result = "thug_en_char_";
  return result;
}

// File Line: 409
// RVA: 0x3F92F0
void __fastcall UFG::ThugsEncounter::SetCharacterCanEnterExitVehicle(UFG::ThugsEncounter *this, bool flag)
{
  this->mCanEnterExitVehicle = flag != 0;
}

