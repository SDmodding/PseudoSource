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
  UFG::CollectibleHidingSpotComponent *v2; // rbx
  unsigned __int8 v3; // di
  __int64 v4; // rsi
  UFG::CopSystem *v5; // rax
  UFG::SimObject *v6; // rax
  void *v7; // rdx
  const char *v8; // rdx

  v2 = this;
  v3 = 0;
  v4 = ((unsigned __int8 (*)(void))this->vfptr[19].__vecDelDtor)();
  v5 = UFG::CopSystem::Instance();
  if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v5->vfptr[89].__vecDelDtor)(v5) )
  {
    v3 = 1;
    if ( (_BYTE)v4 && v2->mUsableHidingSpot == 1 )
      goto LABEL_7;
  }
  else
  {
    LOBYTE(v4) = 0;
  }
  ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *))v2->vfptr[29].__vecDelDtor)(v2);
  if ( v2->mBlipAttached )
  {
    UFG::SimObjectUtility::DetachHudSymbol(v2->m_pSimObject);
    v2->mBlipAttached = 0;
    return;
  }
LABEL_7:
  if ( v2->mUsableHidingSpot != v3 )
  {
    v6 = v2->m_pSimObject;
    if ( v6 )
      v6 = (UFG::SimObject *)v6->m_pSceneObj;
    v7 = v6[1].m_SafePointerList.mNode.mNext;
    if ( !v7 )
      v7 = v6[1].m_SafePointerWithCallbackList.mNode.mPrev;
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *, void *, _QWORD))v2->vfptr[28].__vecDelDtor)(v2, v7, v3);
  }
  v2->mUsableHidingSpot = v3;
  if ( (_BYTE)v4 && !v2->mBlipAttached )
  {
    v8 = "whitedot_symbol";
    if ( v3 )
      v8 = "hiding_spot";
    UFG::SimObjectUtility::AttachHudSymbol(v2->m_pSimObject, v8, 0, 0.0, &customWorldMapCaption);
    v2->mBlipAttached = 1;
  }
}

// File Line: 187
// RVA: 0x534570
void __fastcall UFG::CollectibleHidingSpotComponent::HandleModelSwap(UFG::CollectibleHidingSpotComponent *this, bool status)
{
  bool v2; // di
  UFG::CollectibleHidingSpotComponent *v3; // rbx
  UFG::SimObject *v4; // rax
  UFG::SceneObjectProperties *v5; // rax
  UFG::qPropertySet *v6; // rsi

  v2 = status;
  v3 = this;
  if ( this->mPreviousStatus == status )
  {
    this->mPreviousStatus = status;
    return;
  }
  v4 = this->m_pSimObject;
  if ( !v4 || (v5 = v4->m_pSceneObj) == 0i64 )
  {
    v6 = 0i64;
LABEL_7:
    if ( !v6 )
    {
      this->mPreviousStatus = status;
      return;
    }
    goto LABEL_8;
  }
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v6 = v5->mpConstProperties;
    goto LABEL_7;
  }
LABEL_8:
  if ( UFG::qPropertySet::Get<UFG::qSymbol>(
         v6,
         (UFG::qSymbol *)&qSymbol_CollectibleSpawnInfo_Collected.mUID,
         DEPTH_RECURSE)->mUID != -1 )
  {
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *))v3->vfptr[27].__vecDelDtor)(v3);
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *, UFG::qPropertySet *, bool))v3->vfptr[26].__vecDelDtor)(
      v3,
      v6,
      v2);
  }
  v3->mPreviousStatus = v2;
}

// File Line: 207
// RVA: 0x523090
void __fastcall UFG::CollectibleHidingSpotComponent::Collect(UFG::CollectibleHidingSpotComponent *this, bool status)
{
  bool v2; // bl
  UFG::CollectibleHidingSpotComponent *v3; // rdi
  UFG::GameStatTracker *v4; // rax

  v2 = status;
  v3 = this;
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v4, v3->mType, &v3->m_pSimObject->m_Name, v2);
}

// File Line: 217
// RVA: 0x53C2C0
bool __fastcall UFG::CollectibleHidingSpotComponent::IsUsable(UFG::CollectibleHidingSpotComponent *this)
{
  UFG::CollectibleHidingSpotComponent *v1; // rbx

  v1 = this;
  return ((unsigned __int8 (*)(void))this->vfptr[19].__vecDelDtor)() && v1->mUsableHidingSpot;
}

// File Line: 222
// RVA: 0x54FED0
void __fastcall UFG::CollectibleHidingSpotComponent::Spawn(UFG::CollectibleHidingSpotComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  bool v2; // zf
  UFG::CollectibleHidingSpotComponent *v3; // rdi
  UFG::SimObject *v4; // rcx
  UFG::SceneObjectProperties *v5; // rbx
  UFG::qPropertySet *v6; // rsi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v7; // rbx
  unsigned __int8 v8; // al

  v2 = this->mEnabled == 0;
  v3 = this;
  v4 = this->m_pSimObject;
  v5 = pSceneObj;
  if ( v2 )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "@@@@@@@@@@@@@@@@@@@@@@@@@@@@ - Collectible [%s] ENABLED - @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    v6 = v5->mpWritableProperties;
    if ( !v6 )
      v6 = v5->mpConstProperties;
    v7 = v3->vfptr;
    v8 = ((__int64 (__fastcall *)(UFG::CollectibleHidingSpotComponent *))v3->vfptr[19].__vecDelDtor)(v3);
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *, UFG::qPropertySet *, _QWORD))v7[26].__vecDelDtor)(
      v3,
      v6,
      v8);
    v3->mEnabled = 1;
  }
  else
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->m_Name);
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
  UFG::CollectibleHidingSpotComponent *v2; // rbx
  UFG::SimObject *v3; // rcx

  v1 = this->mEnabled == 0;
  v2 = this;
  v3 = this->m_pSimObject;
  if ( v1 )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "Skipped spawn for collectible, already spawned [%s]\n");
  }
  else
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Collectibles,
      OUTPUT_LEVEL_DEBUG,
      "**************************** - Collectible [%s] DISABLED - ****************************\n");
    ((void (__fastcall *)(UFG::CollectibleHidingSpotComponent *))v2->vfptr[27].__vecDelDtor)(v2);
    v2->mEnabled = 0;
  }
}

// File Line: 255
// RVA: 0x535520
bool __fastcall UFG::CollectibleHidingSpotComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentCollectibleHidingSpot.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 261
// RVA: 0x544890
UFG::allocator::free_link *__fastcall UFG::CollectibleHidingSpotComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  unsigned int v4; // edx
  unsigned int v5; // er9
  UFG::SimComponentHolder *v6; // rbx
  signed __int64 v7; // r8
  UFG::SimComponent *v8; // rax
  unsigned int v9; // edx
  unsigned int v10; // er9
  unsigned int v11; // edx
  unsigned int v12; // er9
  unsigned int v13; // edx
  unsigned int v14; // er9
  UFG::qMemoryPool *v16; // rax
  UFG::allocator::free_link *v17; // rdi
  UFG::SimObject *v18; // rbx
  UFG::qSymbol *v19; // rax
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v21; // [rsp+68h] [rbp+10h]

  v1 = pSceneObj;
  v2 = pSceneObj->m_pSimObject;
  if ( !v2 )
    goto LABEL_35;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = (unsigned int)v2[1].vfptr;
    v5 = v2->m_Components.size;
    if ( v4 < v5 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v4;
        if ( (v6[v4].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v4].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v4 >= v5 )
          goto LABEL_10;
      }
LABEL_9:
      v8 = v6[v7].m_pComponent;
      goto LABEL_33;
    }
    goto LABEL_10;
  }
  if ( (v3 & 0x8000u) != 0 )
  {
    v9 = (unsigned int)v2[1].vfptr;
    v10 = v2->m_Components.size;
    if ( v9 < v10 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v9;
        if ( (v6[v9].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v9].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
        if ( ++v9 >= v10 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (v3 >> 13) & 1 )
  {
    v11 = (unsigned int)v2[1].vfptr;
    v12 = v2->m_Components.size;
    if ( v11 < v12 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v11;
        if ( (v6[v11].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v11].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
        if ( ++v11 >= v12 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (v3 >> 12) & 1 )
  {
    v13 = (unsigned int)v2[1].vfptr;
    v14 = v2->m_Components.size;
    if ( v13 < v14 )
    {
      v6 = v2->m_Components.p;
      do
      {
        v7 = v13;
        if ( (v6[v13].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v13].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
      }
      while ( ++v13 < v14 );
    }
LABEL_10:
    v8 = 0i64;
    goto LABEL_33;
  }
  v8 = UFG::SimObject::GetComponentOfType(v2, UFG::CollectibleComponent::_TypeUID);
LABEL_33:
  if ( v8 )
    return 0i64;
LABEL_35:
  v16 = UFG::GetSimulationMemoryPool();
  v17 = UFG::qMemoryPool::Allocate(v16, 0xD0ui64, "CollectibleHidingSpotComponent", 0i64, 1u);
  v21 = v17;
  if ( v17 )
  {
    v18 = v1->m_pSimObject;
    v19 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::CollectibleComponent::CollectibleComponent((UFG::CollectibleComponent *)v17, v19, v18);
    v17->mNext = (UFG::allocator::free_link *)&UFG::CollectibleHidingSpotComponent::`vftable';
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
}v17 = 0i64;
  }
  BYTE2(v17[24].mNext) = ((__int64 (__fastcall *)(UFG::allocator::free_link *))v17->mNext[19].mNext)(

