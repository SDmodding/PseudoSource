// File Line: 27
// RVA: 0x5325D0
const char *__fastcall UFG::TargetingSystemPedNPCAmbientComponent::GetTypeName(
        UFG::TargetingSystemPedNPCAmbientComponent *this)
{
  return "TargetingSystemPedNPCAmbientComponent";
}

// File Line: 29
// RVA: 0x1543AD0
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap__()
{
  __int64 v0; // rcx
  __int64 size; // rax

  v0 = 91i64;
  size = UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[size] = 0;
    size = ++UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.size;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap__);
}

// File Line: 33
// RVA: 0x5507F0
void UFG::TargetingSystemPedNPCAmbientComponent::StaticInit(void)
{
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[2] = UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[4] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                         + 1;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[5] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                         + 2;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[6] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                         + 3;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[7] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                         + 4;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[8] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                         + 5;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[9] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                         + 6;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[13] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 7;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[14] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 8;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[15] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 9;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[16] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 10;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[17] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 11;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[18] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 12;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[19] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 13;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[20] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 14;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[21] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 15;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[22] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 16;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[23] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 17;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[24] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 18;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[25] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 19;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[26] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 20;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[79] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 21;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[27] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 22;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[28] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 23;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[55] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 24;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[56] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 25;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[61] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 26;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[68] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 27;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[69] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 28;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[70] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 29;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[71] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 30;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[36] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 31;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[76] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 32;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[80] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 33;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[29] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 34;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[31] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 35;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[33] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 36;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[35] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 37;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[32] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 38;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[30] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                          + 39;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[1] = LOBYTE(UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                         + 40;
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes += 41;
}

// File Line: 84
// RVA: 0x535860
bool __fastcall UFG::TargetingSystemPedNPCAmbientComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTargetingSystemPedNPCAmbient,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 90
// RVA: 0x545780
UFG::TargetingSystemPedNPCAmbientComponent *__fastcall UFG::TargetingSystemPedNPCAmbientComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::qPropertySet *mpWritableProperties; // r9
  UFG::SimObject *v8; // rdx
  __int16 m_Flags; // cx
  unsigned int v10; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  m_pSimObject = pSceneObj->m_pSimObject;
  if ( m_pSimObject && UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID) )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xB18ui64, "TargetingSystemPedNPCAmbientComponent", 0i64, 1u);
  v6 = (UFG::SimComponent *)v5;
  if ( v5 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::TargetingSystemPedNPCBaseComponent::TargetingSystemPedNPCBaseComponent(
      (UFG::TargetingSystemPedNPCBaseComponent *)v5,
      &UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap,
      pSceneObj->m_NameUID,
      mpWritableProperties);
    v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCAmbientComponent::`vftable{for `UFG::SimComponent};
    v6[1].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCAmbientComponent::`vftable{for `UFG::UpdateInterface};
    UFG::SimComponent::AddType(
      v6,
      UFG::TargetingSystemPedNPCAmbientComponent::_TargetingSystemPedNPCAmbientComponentTypeUID,
      "TargetingSystemPedNPCAmbientComponent");
  }
  else
  {
    v6 = 0i64;
  }
  v8 = pSceneObj->m_pSimObject;
  m_Flags = v8->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v10 = 20;
  else
    v10 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v8, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v10);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::TargetingSystemPedNPCAmbientComponent *)v6;
}

// File Line: 136
// RVA: 0x53EEC0
// attributes: thunk
void __fastcall UFG::TargetingSystemPedNPCAmbientComponent::OnAttach(
        UFG::TargetingSystemPedNPCAmbientComponent *this,
        UFG::SimObject *pSimObject)
{
  UFG::TargetingSystemPedNPCBaseComponent::OnAttach(this, pSimObject);
}

// File Line: 143
// RVA: 0x541050
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::OnDetach(UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *p_m_pAIActionTreeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx

  p_m_pAIActionTreeComponent = &this->m_pAIActionTreeComponent;
  if ( this->m_pAIActionTreeComponent.m_pSimComponent )
  {
    mNext = this->m_pAIActionTreeComponent.mNext;
    mPrev = p_m_pAIActionTreeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAIActionTreeComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAIActionTreeComponent->m_pSimObject = 0i64;
    p_m_pAIActionTreeComponent->mNext = p_m_pAIActionTreeComponent;
    p_m_pAIActionTreeComponent->mPrev = p_m_pAIActionTreeComponent;
    goto LABEL_8;
  }
  if ( this->m_pAIActionTreeComponent.m_pSimObject
    && (p_m_pAIActionTreeComponent->mPrev != p_m_pAIActionTreeComponent
     || this->m_pAIActionTreeComponent.mNext != &this->m_pAIActionTreeComponent) )
  {
    v5 = this->m_pAIActionTreeComponent.mNext;
    v6 = p_m_pAIActionTreeComponent->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIActionTreeComponent->m_Changed = 1;
  UFG::TargetingSystemPedBaseComponent::OnDetach(this);
}

// File Line: 160
// RVA: 0x571710
void __fastcall UFG::TargetingSystemPedNPCAmbientComponent::updateFocusTarget(
        UFG::TargetingSystemPedNPCAmbientComponent *this)
{
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v3; // rdx
  bool v4; // di
  bool isScriptControlled; // al
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::SimObject *mNext; // rdx
  unsigned __int8 v8; // cl

  m_pTargets = this->m_pTargets;
  v3 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
  v4 = m_pTargets[v3].m_pTarget.m_pPointer && m_pTargets[v3].m_bLock;
  isScriptControlled = UFG::TargetingSystemPedNPCBaseComponent::isScriptControlled(this);
  if ( !v4 && isScriptControlled )
  {
    m_pSimComponent = this->m_pActiveAIEntityComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      mNext = (UFG::SimObject *)m_pSimComponent[38].m_BoundComponentHandles.mNode.mNext;
      if ( mNext )
      {
        v8 = this->m_pTargetingMap->m_Map.p[22];
        if ( v8 )
          UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v8], mNext);
      }
    }
  }
}

// File Line: 183
// RVA: 0x579D00
void __fastcall UFG::TargetingSystemPedNPCAmbientComponent::updateTargets(
        UFG::TargetingSystemPedNPCAmbientComponent *this)
{
  UFG::SimComponent *m_pPointer; // rax
  float v3; // xmm0_4
  float m_fMaximumTargetDistanceSquared; // xmm0_4
  float m_fMinimumTargetDistanceSquared; // xmm3_4
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePickupsList; // [rsp+48h] [rbp-4250h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePropsList; // [rsp+78h] [rbp-4220h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,20> filteredCloseVehiclesList; // [rsp+B0h] [rbp-41E8h] BYREF
  UFG::qFixedArray<UFG::CloseTarget *,80> filteredClosePedsList; // [rsp+160h] [rbp-4138h] BYREF
  UFG::qFixedArray<UFG::CloseTarget,100> closeTargetsList; // [rsp+3F0h] [rbp-3EA8h] BYREF
  UFG::qFixedArray<UFG::CloseTarget,100> filteredCloseTargetsList; // [rsp+2340h] [rbp-1F58h] BYREF

  closeTargetsList.size = 0;
  filteredClosePedsList.size = 0;
  filteredCloseTargetsList.size = 0;
  filteredClosePickupsList.size = 0;
  filteredClosePropsList.size = 0;
  filteredCloseVehiclesList.size = 0;
  m_pPointer = this->m_pEquippedSOWPC.m_pPointer;
  if ( m_pPointer )
  {
    v3 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                    + HIDWORD(m_pPointer[2].m_pSimObject))
                  + 40i64);
    m_fMaximumTargetDistanceSquared = v3 * v3;
  }
  else
  {
    m_fMaximumTargetDistanceSquared = this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  m_fMinimumTargetDistanceSquared = this->m_fMinimumTargetDistanceSquared;
  if ( m_fMinimumTargetDistanceSquared <= m_fMaximumTargetDistanceSquared )
    m_fMinimumTargetDistanceSquared = m_fMaximumTargetDistanceSquared;
  UFG::TargetingSystemPedBaseComponent::findCloseTargets(
    &closeTargetsList,
    this->m_pSimObject,
    &this->m_vTargetingPosition,
    m_fMinimumTargetDistanceSquared);
  UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
    &closeTargetsList,
    &this->m_CachedPedsList,
    &filteredClosePedsList,
    &filteredClosePickupsList,
    &filteredClosePropsList,
    &filteredCloseVehiclesList,
    &filteredCloseTargetsList);
  UFG::TargetingSystemPedNPCAmbientComponent::updateFocusTarget(this);
  UFG::TargetingSystemPedBaseComponent::updateClosestPedTarget(this, &filteredClosePedsList);
  UFG::TargetingSystemPedBaseComponent::updatePickupTarget(this, &filteredClosePickupsList);
  UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(this);
  UFG::TargetingSystemBaseComponent::updateMySpawnPointTarget(this);
}

// File Line: 217
// RVA: 0x549D20
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::Reset(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  unsigned int *m_pBucketList; // rcx

  UFG::TargetingSystemBaseComponent::shutdown(this);
  UFG::TargetingSystemBaseComponent::initialize(this);
  m_pBucketList = this->m_pBucketList;
  this->m_CachedPedsList.size = 0;
  if ( m_pBucketList )
  {
    --m_pBucketList[this->m_uUpdateBucket];
    this->m_pBucketList = 0i64;
  }
  UFG::TargetingSystemPedBaseComponent::initialize(this);
  UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate(this);
}

// File Line: 227
// RVA: 0x55CD20
void __fastcall UFG::TargetingSystemPedNPCAmbientComponent::Update(
        UFG::TargetingSystemPedNPCAmbientComponent *this,
        float delta_sec)
{
  __int64 v3; // rdi

  UFG::TargetingSystemPedBaseComponent::UpdateCommon((UFG::TargetingSystemPedNPCAmbientComponent *)((char *)this - 64));
  UFG::TargetingSystemPedNPCBaseComponent::updateTargetingIntentions((UFG::TargetingSystemPedNPCAmbientComponent *)((char *)this - 64));
  if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *))this[-1].UFG::TargetingSystemPedNPCBaseComponent::UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>::mPrev[11].mPrev)(&this[-1].UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>) )
    UFG::TargetingSystemPedNPCAmbientComponent::updateTargets((UFG::TargetingSystemPedNPCAmbientComponent *)((char *)this - 64));
  v3 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&this->m_Flags + 30i64) + *(_QWORD *)&this->m_TypeUID + 40);
  if ( v3 != *(_QWORD *)&this->m_vTargetingPosition.z )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))this->m_pTransformNodeComponent.mNext->mPrev[11].mPrev)(this->m_pTransformNodeComponent.mNext);
    *(_QWORD *)&this->m_vTargetingPosition.z = v3;
  }
  LOBYTE(this->m_pInterestPointUserComponent.m_Changed) = 0;
}

