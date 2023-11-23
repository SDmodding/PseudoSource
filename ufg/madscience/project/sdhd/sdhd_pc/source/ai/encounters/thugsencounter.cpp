// File Line: 39
// RVA: 0x14D92B0
__int64 dynamic_initializer_for__UFG::ThugsEncounter::s_ThugsEncounterList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ThugsEncounter::s_ThugsEncounterList__);
}

// File Line: 49
// RVA: 0x3F2660
void __fastcall UFG::ThugsEncounter::ThugsEncounter(UFG::ThugsEncounter *this)
{
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *mPrev; // rax

  UFG::EncounterBase::EncounterBase(this);
  this->mPrev = &this->UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter>;
  this->mNext = &this->UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter>;
  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::ThugsEncounter::`vftable;
  this->mpOwnerGameSlice = 0i64;
  *(_DWORD *)&this->mIsStarted = 0;
  this->mCanEnterExitVehicle = 2;
  mPrev = UFG::ThugsEncounter::s_ThugsEncounterList.mNode.mPrev;
  UFG::ThugsEncounter::s_ThugsEncounterList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *)&UFG::ThugsEncounter::s_ThugsEncounterList;
  UFG::ThugsEncounter::s_ThugsEncounterList.mNode.mPrev = &this->UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter>;
}

// File Line: 54
// RVA: 0x3F2AA0
void __fastcall UFG::ThugsEncounter::~ThugsEncounter(UFG::ThugsEncounter *this)
{
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v2; // rbx
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *mPrev; // rcx
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *mNext; // rax
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v5; // rcx
  UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::ThugsEncounter::`vftable;
  if ( this == UFG::ThugsEncounter::s_ThugsEncounterpCurrentIterator )
    UFG::ThugsEncounter::s_ThugsEncounterpCurrentIterator = (UFG::ThugsEncounter *)&this->mPrev[-201];
  v2 = &this->UFG::qNode<UFG::ThugsEncounter,UFG::ThugsEncounter>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::ThugsEncounter::Cleanup(this);
  UFG::EncounterBase::Shutdown(this);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::EncounterBase::~EncounterBase(this);
}

// File Line: 61
// RVA: 0x3F98D0
void __fastcall UFG::ThugsEncounter::Shutdown(UFG::ThugsEncounter *this)
{
  UFG::ThugsEncounter::Cleanup(this);
  UFG::EncounterBase::Shutdown(this);
}

// File Line: 67
// RVA: 0x3F98F0
void __fastcall UFG::ThugsEncounter::Start(UFG::ThugsEncounter *this, UFG::qSymbol *firstWave, bool startRunning)
{
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rax
  UFG::qPropertyList *v5; // rax
  char *ValuePtr; // rax
  UFG::qPropertySet *v7; // rcx

  this->mIsStarted = startRunning;
  *(_WORD *)&this->mIsPaused = 256;
  this->mStartTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  vfptr = this->vfptr;
  if ( firstWave->mUID == -1 )
  {
    this->mHeatLevel = HEATLEVEL_ONE;
    if ( !((__int64 (*)(void))vfptr[33].__vecDelDtor)() )
    {
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             this->mProperties.mpPropSet,
             (UFG::qArray<unsigned long,0> *)&EncounterSym_wave_definitions,
             DEPTH_RECURSE);
      ValuePtr = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, 0);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v7 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v7 = 0i64;
      this->mHeatLevelProperties[this->mHeatLevel] = v7;
      this->mWaterHeatLevelProperties[this->mHeatLevel] = this->mHeatLevelProperties[this->mHeatLevel];
      ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[33].__vecDelDtor)(this);
    }
    ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[23].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[50].__vecDelDtor)(this);
  }
  else
  {
    ((void (*)(void))vfptr[25].__vecDelDtor)();
  }
}

// File Line: 106
// RVA: 0x3F99E0
void __fastcall UFG::ThugsEncounter::Stop(UFG::ThugsEncounter *this)
{
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rax

  vfptr = this->vfptr;
  *(_WORD *)&this->mIsStarted = 0;
  this->mIsInside = 0;
  this->mHeatLevel = HEATLEVEL_NONE;
  ((void (*)(void))vfptr[50].__vecDelDtor)();
}

// File Line: 117
// RVA: 0x3F3520
void __fastcall UFG::ThugsEncounter::Cleanup(UFG::ThugsEncounter *this)
{
  bool v1; // zf

  v1 = this->mHumans.size == 0;
  *(_WORD *)&this->mIsStarted = 0;
  this->mIsInside = 0;
  this->mHeatLevel = HEATLEVEL_NONE;
  if ( !v1 )
  {
    do
    {
      this->vfptr[37].__vecDelDtor(this, (unsigned int)this->mHumans.p[0]);
      this->mHumans.p[0] = this->mHumans.p[--this->mHumans.size];
    }
    while ( this->mHumans.size );
  }
  for ( ; this->mVehicles.size; this->mVehicles.p[0] = this->mVehicles.p[this->mVehicles.size] )
  {
    this->vfptr[37].__vecDelDtor(this, (unsigned int)this->mVehicles.p[0]);
    --this->mVehicles.size;
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
void __fastcall UFG::ThugsEncounter::AttachIndicator(
        UFG::ThugsEncounter *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  char v3; // di
  UFG::SimObject *m_pSimObject; // rbp
  UFG::PropertySetHandle *p_mProperties; // rbx
  UFG::qPropertySet *mpPropSet; // rbx
  char *v7; // r14
  char *v8; // r15
  UFG::allocator::free_link *v9; // rbx
  UFG::ObjectiveIndicator *v10; // rax
  UFG::qString blip; // [rsp+40h] [rbp-68h] BYREF
  UFG::qString corona; // [rsp+68h] [rbp-40h] BYREF

  v3 = 0;
  m_pSimObject = pEncounterUnitComponent->m_pSimObject;
  if ( m_pSimObject )
  {
    p_mProperties = &this->mProperties;
    UFG::PropertySetHandle::Bind(&this->mProperties);
    mpPropSet = p_mProperties->mpPropSet;
    v7 = UFG::qPropertySet::Get<char const *>(
           mpPropSet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_BlipName,
           DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<char const *>(
           mpPropSet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_CoronaName,
           DEPTH_RECURSE);
    if ( v7 )
    {
      if ( *v7 )
      {
        UFG::SimObjectUtility::AttachHudSymbol(m_pSimObject, v7, 0, 0.0, &customCaption);
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
              UFG::ObjectiveIndicator::ObjectiveIndicator(
                (UFG::ObjectiveIndicator *)v9,
                &m_pSimObject->m_Name,
                &blip,
                &corona,
                1);
            }
            else
            {
              v10 = 0i64;
            }
            pEncounterUnitComponent->mpObjectiveIndicator = v10;
            if ( (v3 & 2) != 0 )
            {
              v3 &= ~2u;
              UFG::qString::~qString(&blip);
            }
            if ( (v3 & 1) != 0 )
              UFG::qString::~qString(&corona);
            UFG::ObjectiveIndicator::SetEnabled(pEncounterUnitComponent->mpObjectiveIndicator, 1);
          }
        }
      }
    }
  }
}

// File Line: 173
// RVA: 0x3F6B80
UFG::EncounterUnitComponent *__fastcall UFG::ThugsEncounter::HandleOnFootSpawn(
        UFG::ThugsEncounter *this,
        UFG::qMatrix44 *pSpawnTransform,
        UFG::qPropertySet *pGroupPropertySet,
        UFG::qSymbol *pSpecificCharacterResource)
{
  UFG::EncounterUnitComponent *v5; // rbx

  v5 = UFG::EncounterBase::HandleOnFootSpawn(this, pSpawnTransform, pGroupPropertySet, pSpecificCharacterResource);
  if ( ((unsigned __int8 (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[61].__vecDelDtor)(this) )
    UFG::ThugsEncounter::AttachIndicator(this, v5);
  return v5;
}

// File Line: 186
// RVA: 0x3F6F00
void __fastcall UFG::ThugsEncounter::HandleOnFootSpawnPost(
        UFG::ThugsEncounter *this,
        UFG::SimObjectCVBase *pOnFootSpawn)
{
  UFG::qPropertySet *WritableProperties; // rax

  UFG::EncounterBase::HandleOnFootSpawnPost(this, pOnFootSpawn);
  if ( this->mCanEnterExitVehicle != 2 )
  {
    WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(pOnFootSpawn->m_pSceneObj);
    UFG::qPropertySet::Set<bool>(
      WritableProperties,
      (UFG::qArray<unsigned long,0> *)&qSymbol_CanEnterExitVehicle,
      this->mCanEnterExitVehicle == 1);
  }
}

// File Line: 199
// RVA: 0x3F31A0
UFG::EncounterUnitComponent *__fastcall UFG::ThugsEncounter::AddExternalCharacterIntoSystem(
        UFG::ThugsEncounter *this,
        UFG::SimObjectCVBase *pCharacter)
{
  UFG::EncounterUnitComponent *v3; // rbx

  v3 = UFG::EncounterBase::AddExternalCharacterIntoSystem(this, pCharacter);
  if ( ((unsigned __int8 (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[61].__vecDelDtor)(this) )
    UFG::ThugsEncounter::AttachIndicator(this, v3);
  return v3;
}

// File Line: 211
// RVA: 0x3F7220
void __fastcall UFG::ThugsEncounter::HandleVehicleAcquired(
        UFG::ThugsEncounter *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent,
        UFG::qPropertySet *pEncounterPropertySet,
        UFG::qPropertySet *pGroupPropertySet)
{
  UFG::EncounterBase::HandleVehicleAcquired(this, pEncounterUnitComponent, pEncounterPropertySet, pGroupPropertySet);
  if ( !((unsigned __int8 (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[61].__vecDelDtor)(this) )
    UFG::ThugsEncounter::AttachIndicator(this, pEncounterUnitComponent);
}

// File Line: 221
// RVA: 0x3F2E00
void __fastcall UFG::ThugsEncounter::Acquire(
        UFG::ThugsEncounter *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent,
        UFG::qPropertySet *pGroupPropertySet)
{
  UFG::GameSlice *mpOwnerGameSlice; // rbx
  UFG::TSActor *v6; // rax
  UFG::TSActor *v7; // [rsp+40h] [rbp+8h] BYREF

  UFG::EncounterUnitComponent::AcquireBy(pEncounterUnitComponent, this, pGroupPropertySet);
  mpOwnerGameSlice = this->mpOwnerGameSlice;
  if ( mpOwnerGameSlice )
    mpOwnerGameSlice = (UFG::GameSlice *)mpOwnerGameSlice->mScript;
  v6 = UFG::TSActor::FromSimObject(pEncounterUnitComponent->m_pSimObject);
  if ( mpOwnerGameSlice )
  {
    if ( v6 )
    {
      ++v6->i_ref_count;
      v7 = v6;
      (*(void (__fastcall **)(unsigned int *, UFG::qStaticSymbol *, UFG::TSActor **, __int64, _QWORD, _QWORD))(*(_QWORD *)&mpOwnerGameSlice->mNode.mUID + 104i64))(
        &mpOwnerGameSlice->mNode.mUID,
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
void __fastcall UFG::ThugsEncounter::UpdatePopulation(UFG::ThugsEncounter *this, float deltaTime)
{
  UFG::BasePhysicsSystem *v3; // r13
  __int64 v4; // r14
  bool v5; // r12
  unsigned int v6; // ebp
  int v7; // edx
  UFG::SimObjectGame *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  char v10; // di
  UFG::SimComponent *m_pComponent; // rax
  unsigned int mNext; // ecx
  __int16 v13; // cx
  UFG::HudComponent *ComponentOfTypeHK; // rax
  unsigned int BlipGuid; // eax
  UFG::qBaseTreeRB *CollisionModel; // rdi
  __int16 v17; // dx
  UFG::SimComponent *v18; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  double v20; // xmm0_8
  UFG::SimObjectGame *v21; // rbx
  __int16 v22; // cx
  UFG::HudComponent *v23; // rax
  unsigned int v24; // eax
  UFG::qBaseTreeRB *v25; // rdi
  __int16 v26; // cx
  UFG::VehicleOccupantComponent *v27; // rax
  double v28; // xmm0_8
  float v29; // xmm2_4

  UFG::EncounterBase::UpdatePopulation(this, deltaTime);
  v3 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v4 = 0i64;
    v5 = *UFG::qPropertySet::Get<bool>(
            this->mProperties.mpPropSet,
            (UFG::qArray<unsigned long,0> *)&EncounterSym_show_blip_radius,
            DEPTH_RECURSE);
    v6 = 0;
    if ( this->mHumans.size )
    {
      v7 = 8720;
      do
      {
        m_pSimObject = (UFG::SimObjectGame *)this->mHumans.p[v6]->m_pSimObject;
        if ( m_pSimObject )
        {
          m_Flags = m_pSimObject->m_Flags;
          v10 = 0;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = m_pSimObject->m_Components.p[44].m_pComponent;
          }
          else
          {
            if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                               m_pSimObject,
                               UFG::CharacterOccupantComponent::_TypeUID);
            else
              m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
            v7 = 8720;
          }
          if ( m_pComponent )
          {
            mNext = (unsigned int)m_pComponent[1].m_SafePointerList.mNode.mNext;
            if ( mNext > 0xD || !_bittest(&v7, mNext) )
            {
              v10 = 1;
              UFG::SimObjectUtility::DetachHudSymbol(m_pSimObject);
            }
          }
          if ( v5 && !v10 )
          {
            v13 = m_pSimObject->m_Flags;
            if ( (v13 & 0x4000) != 0 || v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
              ComponentOfTypeHK = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pSimObject,
                                                         UFG::HudComponent::_TypeUID);
            else
              ComponentOfTypeHK = (UFG::HudComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pSimObject,
                                                         UFG::HudComponent::_TypeUID);
            if ( ComponentOfTypeHK )
            {
              BlipGuid = UFG::HudComponent::GetBlipGuid(ComponentOfTypeHK);
              CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(v3, BlipGuid);
              if ( CollisionModel )
              {
                v17 = m_pSimObject->m_Flags;
                if ( (v17 & 0x4000) != 0 )
                {
                  v18 = m_pSimObject->m_Components.p[44].m_pComponent;
                }
                else
                {
                  if ( v17 < 0 || (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
                    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                        m_pSimObject,
                                        UFG::CharacterOccupantComponent::_TypeUID);
                  else
                    ComponentOfType = UFG::SimObject::GetComponentOfType(
                                        m_pSimObject,
                                        UFG::CharacterOccupantComponent::_TypeUID);
                  v18 = ComponentOfType;
                }
                LOBYTE(v18) = v18 == 0i64;
                v20 = ((double (__fastcall *)(UFG::ThugsEncounter *, UFG::SimComponent *, UFG::EncounterUnitComponent *))this->vfptr[17].__vecDelDtor)(
                        this,
                        v18,
                        this->mHumans.p[v6]);
                UFG::UIMapBlip::SetRange((UFG::UIMapBlip *)CollisionModel, 1, *(float *)&v20);
              }
            }
          }
          v7 = 8720;
        }
        ++v6;
      }
      while ( v6 < this->mHumans.size );
    }
    if ( v5 && this->mVehicles.size )
    {
      do
      {
        v21 = (UFG::SimObjectGame *)this->mVehicles.p[v4]->m_pSimObject;
        if ( !v21 )
          goto LABEL_66;
        v22 = v21->m_Flags;
        if ( (v22 & 0x4000) != 0 || v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
          v23 = (UFG::HudComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::HudComponent::_TypeUID);
        else
          v23 = (UFG::HudComponent *)UFG::SimObject::GetComponentOfType(v21, UFG::HudComponent::_TypeUID);
        if ( !v23 )
          goto LABEL_66;
        v24 = UFG::HudComponent::GetBlipGuid(v23);
        v25 = UFG::BasePhysicsSystem::GetCollisionModel(v3, v24);
        if ( !v25 )
          goto LABEL_66;
        v26 = v21->m_Flags;
        if ( (v26 & 0x4000) != 0 )
          goto LABEL_59;
        if ( v26 < 0 )
        {
          v27 = (UFG::VehicleOccupantComponent *)v21->m_Components.p[30].m_pComponent;
          goto LABEL_61;
        }
        if ( (v26 & 0x2000) != 0 || (v26 & 0x1000) != 0 )
LABEL_59:
          v27 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v21,
                                                   UFG::VehicleOccupantComponent::_TypeUID);
        else
          v27 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                   v21,
                                                   UFG::VehicleOccupantComponent::_TypeUID);
LABEL_61:
        if ( v27 && (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v27) )
        {
          v28 = ((double (__fastcall *)(UFG::ThugsEncounter *, _QWORD, UFG::EncounterUnitComponent *))this->vfptr[17].__vecDelDtor)(
                  this,
                  0i64,
                  this->mVehicles.p[v4]);
          v29 = *(float *)&v28;
        }
        else
        {
          v29 = 0.0;
        }
        UFG::UIMapBlip::SetRange((UFG::UIMapBlip *)v25, 1, v29);
LABEL_66:
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < this->mVehicles.size );
    }
  }
}

// File Line: 310
// RVA: 0x3FB470
void __fastcall UFG::ThugsEncounter::UpdateStatus(UFG::ThugsEncounter *this)
{
  char v2; // al
  bool v3; // zf
  bool v4; // al
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rax

  v2 = ((__int64 (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[8].__vecDelDtor)(this);
  v3 = this->mHeatLevel == HEATLEVEL_NONE;
  this->mIsInside = v2 == 0;
  v4 = v3;
  v3 = !v3 && !this->mIsCompleted;
  this->mIsCompleted |= v4;
  if ( !v3 )
  {
    vfptr = this->vfptr;
    *(_WORD *)&this->mIsStarted = 0;
    this->mIsInside = 0;
    this->mHeatLevel = HEATLEVEL_NONE;
    ((void (__fastcall *)(UFG::ThugsEncounter *))vfptr[50].__vecDelDtor)(this);
    UFG::ThugsEncounter::Cleanup(this);
  }
}

// File Line: 325
// RVA: 0x3F9F70
void __fastcall UFG::ThugsEncounter::Update(UFG::ThugsEncounter *this, float deltaTime)
{
  __int64 v4; // rax
  __int64 v5; // rdi
  UFG::qVector3 *v6; // rdi
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::SimObjectGame *v9; // rax

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
    y = v6->y;
    z = v6->z;
    this->mFocusTargetPosition.x = v6->x;
    this->mFocusTargetPosition.y = y;
    this->mFocusTargetPosition.z = z;
    v9 = (UFG::SimObjectGame *)((__int64 (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[18].__vecDelDtor)(this);
    UFG::EncounterUnitContext::Update(&this->mFocusTargetContext, v9, deltaTime);
    ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[38].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[40].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[39].__vecDelDtor)(this);
    UFG::ThugsEncounter::UpdateStatus(this);
    ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[76].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[41].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[83].__vecDelDtor)(this);
  }
}

// File Line: 355
// RVA: 0x3FC0B0
__int64 __fastcall UFG::ThugsEncounter::VisualizeEncounterUnitsInfo(UFG::ThugsEncounter *this, int x, int startY)
{
  Render::DebugDrawContext *Context; // r10
  const char *v7; // r8
  const char *v8; // rdx
  const char *v9; // rcx
  const char *v10; // rax

  if ( UFG::EncounterBase::sVisualizeWavesInfo )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    v7 = "No";
    v8 = "No";
    v9 = "No";
    v10 = "No";
    if ( this->mIsInside )
      v8 = "Yes";
    if ( this->mIsCompleted )
      v9 = "Yes";
    if ( this->mIsPaused )
      v10 = "Yes";
    if ( this->mIsStarted )
      v7 = "Yes";
    Render::DebugDrawContext::DrawTextA(
      Context,
      x,
      startY,
      &UFG::qColour::White,
      "IsStarted:%s  IsPaused:%s  IsCompleted:%s  IsInside:%s",
      v7,
      v10,
      v9,
      v8);
    startY += 10;
  }
  return startY + (unsigned int)UFG::EncounterBase::VisualizeEncounterUnitsInfo(this, x, startY);
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
    v3 = ((__int64 (__fastcall *)(UFG::qList<UFG::ThugsEncounter,UFG::ThugsEncounter,1,0> *, __int64, _QWORD))v1->mNode.mPrev[32].mNext)(
           v1,
           150i64,
           i);
    v1 = (UFG::qList<UFG::ThugsEncounter,UFG::ThugsEncounter,1,0> *)&v1[201].mNode.mNext[-201];
  }
}

// File Line: 387
// RVA: 0x3F49E0
void __fastcall UFG::ThugsEncounter::Forget(
        UFG::ThugsEncounter *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::ObjectiveIndicator *mpObjectiveIndicator; // rcx
  unsigned int v5; // ebx

  mpObjectiveIndicator = pEncounterUnitComponent->mpObjectiveIndicator;
  if ( mpObjectiveIndicator )
  {
    mpObjectiveIndicator->vfptr->__vecDelDtor(mpObjectiveIndicator, 1u);
    pEncounterUnitComponent->mpObjectiveIndicator = 0i64;
  }
  UFG::SimObjectUtility::DetachHudSymbol(pEncounterUnitComponent->m_pSimObject);
  UFG::EncounterBase::Forget(this, pEncounterUnitComponent);
  UFG::PropertySetHandle::Bind(&this->mProperties);
  v5 = *UFG::qPropertySet::Get<unsigned long>(
          this->mProperties.mpPropSet,
          (UFG::qArray<unsigned long,0> *)&EncounterSym_kills_required,
          DEPTH_RECURSE);
  if ( v5 )
  {
    if ( ((unsigned int (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[31].__vecDelDtor)(this) >= v5 )
    {
      ((void (__fastcall *)(UFG::ThugsEncounter *))this->vfptr[31].__vecDelDtor)(this);
      this->mIsCompleted = 1;
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
    return "thug_en_char_";
  return result;
}

// File Line: 409
// RVA: 0x3F92F0
void __fastcall UFG::ThugsEncounter::SetCharacterCanEnterExitVehicle(UFG::ThugsEncounter *this, char flag)
{
  this->mCanEnterExitVehicle = flag != 0;
}

