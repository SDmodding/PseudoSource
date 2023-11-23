// File Line: 38
// RVA: 0x5323F0
const char *__fastcall UFG::CollectibleHidingSpotComponent::GetTypeName(UFG::CollectibleHidingSpotComponent *this)
{
  return "CollectibleHidingSpotComponent";
}

// File Line: 121
// RVA: 0x55A970
void __fastcall UFG::CollectibleHidingSpotComponent::Update(UFG::CollectibleHidingSpotComponent *this, float deltaTime)
{
  bool v3; // di
  char v4; // si
  UFG::CopSystem *v5; // rax
  UFG::SimObject *m_pSimObject; // rax
  void *mNext; // rdx
  const char *v8; // rdx

  v3 = 0;
  v4 = ((__int64 (__fastcall *)(UFG::CollectibleHidingSpotComponent *))this->vfptr[19].__vecDelDtor)(this);
  v5 = UFG::CopSystem::Instance();
  if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v5->vfptr[89].__vecDelDtor)(v5) )
  {
    v3 = 1;
    if ( v4 && this->mUsableHidingSpot )
      goto LABEL_7;
  }
  else
  {
    v4 = 0;
  }
  ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *))this->vfptr[29].__vecDelDtor)(this);
  if ( this->mBlipAttached )
  {
    UFG::SimObjectUtility::DetachHudSymbol(this->m_pSimObject);
    this->mBlipAttached = 0;
    return;
  }
LABEL_7:
  if ( this->mUsableHidingSpot != v3 )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pSceneObj;
    mNext = m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
    if ( !mNext )
      mNext = m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *, void *, bool))this->vfptr[28].__vecDelDtor)(
      this,
      mNext,
      v3);
  }
  this->mUsableHidingSpot = v3;
  if ( v4 && !this->mBlipAttached )
  {
    v8 = "whitedot_symbol";
    if ( v3 )
      v8 = "hiding_spot";
    UFG::SimObjectUtility::AttachHudSymbol(this->m_pSimObject, v8, 0, 0.0, &customCaption);
    this->mBlipAttached = 1;
  }
}

// File Line: 187
// RVA: 0x534570
void __fastcall UFG::CollectibleHidingSpotComponent::HandleModelSwap(
        UFG::CollectibleHidingSpotComponent *this,
        bool status)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rsi

  if ( this->mPreviousStatus == status )
  {
    this->mPreviousStatus = status;
    return;
  }
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSceneObj = m_pSimObject->m_pSceneObj) == 0i64 )
  {
    mpWritableProperties = 0i64;
LABEL_7:
    if ( !mpWritableProperties )
    {
      this->mPreviousStatus = status;
      return;
    }
    goto LABEL_8;
  }
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_7;
  }
LABEL_8:
  if ( UFG::qPropertySet::Get<UFG::qSymbol>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&qSymbol_CollectibleSpawnInfo_Collected,
         DEPTH_RECURSE)->mUID != -1 )
  {
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *))this->vfptr[27].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *, UFG::qPropertySet *, bool))this->vfptr[26].__vecDelDtor)(
      this,
      mpWritableProperties,
      status);
  }
  this->mPreviousStatus = status;
}

// File Line: 207
// RVA: 0x523090
void __fastcall UFG::CollectibleHidingSpotComponent::Collect(UFG::CollectibleHidingSpotComponent *this, bool status)
{
  UFG::GameStatTracker *v4; // rax

  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v4, this->mType, &this->m_pSimObject->m_Name, status);
}

// File Line: 217
// RVA: 0x53C2C0
bool __fastcall UFG::CollectibleHidingSpotComponent::IsUsable(UFG::CollectibleHidingSpotComponent *this)
{
  return ((unsigned __int8 (__fastcall *)(UFG::CollectibleHidingSpotComponent *))this->vfptr[19].__vecDelDtor)(this)
      && this->mUsableHidingSpot;
}

// File Line: 222
// RVA: 0x54FED0
void __fastcall UFG::CollectibleHidingSpotComponent::Spawn(
        UFG::CollectibleHidingSpotComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  bool v2; // zf
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qPropertySet *mpWritableProperties; // rsi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rbx
  unsigned __int8 v8; // al

  v2 = !this->mEnabled;
  m_pSimObject = this->m_pSimObject;
  if ( v2 )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "@@@@@@@@@@@@@@@@@@@@@@@@@@@@ - Collectible [%s] ENABLED - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    vfptr = this->vfptr;
    v8 = ((__int64 (__fastcall *)(UFG::CollectibleHidingSpotComponent *))this->vfptr[19].__vecDelDtor)(this);
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *, UFG::qPropertySet *, _QWORD))vfptr[26].__vecDelDtor)(
      this,
      mpWritableProperties,
      v8);
    this->mEnabled = 1;
  }
  else
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "Skipped spawn for collectible, already spawned [%s]\n");
  }
}

// File Line: 238
// RVA: 0x525380
void __fastcall UFG::CollectibleHidingSpotComponent::Despawn(UFG::CollectibleHidingSpotComponent *this)
{
  bool v1; // zf
  UFG::SimObject *m_pSimObject; // rcx

  v1 = !this->mEnabled;
  m_pSimObject = this->m_pSimObject;
  if ( v1 )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "Skipped spawn for collectible, already spawned [%s]\n");
  }
  else
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "**************************** - Collectible [%s] DISABLED - ****************************\n");
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *))this->vfptr[27].__vecDelDtor)(this);
    this->mEnabled = 0;
  }
}

// File Line: 255
// RVA: 0x535520
bool __fastcall UFG::CollectibleHidingSpotComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentCollectibleHidingSpot,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 261
// RVA: 0x544890
UFG::allocator::free_link *__fastcall UFG::CollectibleHidingSpotComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // edx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v7; // r8
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v9; // edx
  unsigned int v10; // r9d
  unsigned int v11; // edx
  unsigned int v12; // r9d
  unsigned int v13; // edx
  unsigned int v14; // r9d
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v17; // rdi
  UFG::SimObject *v18; // rbx
  UFG::qSymbol *v19; // rax
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::allocator::free_link *v21; // [rsp+68h] [rbp+10h]

  m_pSimObject = pSceneObj->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_35;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_10;
      }
LABEL_9:
      m_pComponent = p[v7].m_pComponent;
      goto LABEL_33;
    }
    goto LABEL_10;
  }
  if ( m_Flags < 0 )
  {
    v9 = (unsigned int)m_pSimObject[1].vfptr;
    v10 = m_pSimObject->m_Components.size;
    if ( v9 < v10 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = v9;
        if ( (p[v9].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v9].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
        if ( ++v9 >= v10 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v11 = (unsigned int)m_pSimObject[1].vfptr;
    v12 = m_pSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = v11;
        if ( (p[v11].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v11].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
        if ( ++v11 >= v12 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v13 = (unsigned int)m_pSimObject[1].vfptr;
    v14 = m_pSimObject->m_Components.size;
    if ( v13 < v14 )
    {
      p = m_pSimObject->m_Components.p;
      do
      {
        v7 = v13;
        if ( (p[v13].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v13].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
      }
      while ( ++v13 < v14 );
    }
LABEL_10:
    m_pComponent = 0i64;
    goto LABEL_33;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CollectibleComponent::_TypeUID);
LABEL_33:
  if ( m_pComponent )
    return 0i64;
LABEL_35:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v17 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xD0ui64, "CollectibleHidingSpotComponent", 0i64, 1u);
  v21 = v17;
  if ( v17 )
  {
    v18 = pSceneObj->m_pSimObject;
    v19 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(
                            pSceneObj,
                            (UFG::qWiseSymbol *)&result);
    UFG::CollectibleComponent::CollectibleComponent((UFG::CollectibleComponent *)v17, v19, v18);
    v17->mNext = (UFG::allocator::free_link *)&UFG::CollectibleHidingSpotComponent::`vftable;
    LOWORD(v17[25].mNext) = 0;
    UFG::SimComponent::AddType(
      (UFG::SimComponent *)v17,
      UFG::CollectibleHidingSpotComponent::_CollectibleHidingSpotComponentTypeUID,
      "CollectibleHidingSpotComponent");
  }
  else
  {
    v17 = 0i64;
  }
  BYTE2(v17[24].mNext) = ((__int64 (__fastcall *)(UFG::allocator::free_link *))v17->mNext[19].mNext)(v17);
  return v17;
}

