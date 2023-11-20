// File Line: 27
// RVA: 0x5325D0
const char *__fastcall UFG::TargetingSystemPedNPCAmbientComponent::GetTypeName(UFG::TargetingSystemPedNPCAmbientComponent *this)
{
  return "TargetingSystemPedNPCAmbientComponent";
}

// File Line: 29
// RVA: 0x1543AD0
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap__()
{
  signed __int64 v0; // rcx
  __int64 v1; // rax

  v0 = 91i64;
  v1 = UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.size;
  do
  {
    UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[v1] = 0;
    v1 = UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.size++ + 1;
    --v0;
  }
  while ( v0 );
  UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_Map.p[0] = UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  ++UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap__);
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
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentTargetingSystemPedNPCAmbient.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 90
// RVA: 0x545780
UFG::SimComponent *__fastcall UFG::TargetingSystemPedNPCAmbientComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::SimObject *v2; // rcx
  UFG::qMemoryPool *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::qPropertySet *v7; // r9
  UFG::SimObject *v8; // rdx
  unsigned __int16 v9; // cx
  unsigned int v10; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = pSceneObj->m_pSimObject;
  if ( v2 && UFG::SimObject::GetComponentOfType(v2, UFG::TargetingSystemBaseComponent::_TypeUID) )
    return 0i64;
  v4 = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(v4, 0xB18ui64, "TargetingSystemPedNPCAmbientComponent", 0i64, 1u);
  v6 = (UFG::SimComponent *)v5;
  if ( v5 )
  {
    v7 = v1->mpWritableProperties;
    if ( !v7 )
      v7 = v1->mpConstProperties;
    UFG::TargetingSystemPedNPCBaseComponent::TargetingSystemPedNPCBaseComponent(
      (UFG::TargetingSystemPedNPCBaseComponent *)v5,
      &UFG::TargetingSystemPedNPCAmbientComponent::ms_TargetingMap,
      v1->m_NameUID,
      v7);
    v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCAmbientComponent::`vftable'{for `UFG::SimComponent'};
    v6[1].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCAmbientComponent::`vftable'{for `UFG::UpdateInterface'};
    UFG::SimComponent::AddType(
      v6,
      UFG::TargetingSystemPedNPCAmbientComponent::_TargetingSystemPedNPCAmbientComponentTypeUID,
      "TargetingSystemPedNPCAmbientComponent");
  }
  else
  {
    v6 = 0i64;
  }
  v8 = v1->m_pSimObject;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 || (v9 & 0x8000u) != 0 )
    v10 = 20;
  else
    v10 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v8, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v10);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v6;
}

// File Line: 136
// RVA: 0x53EEC0
void __fastcall UFG::TargetingSystemPedNPCAmbientComponent::OnAttach(UFG::TargetingSystemPedNPCAmbientComponent *this, UFG::SimObject *pSimObject)
{
  UFG::TargetingSystemPedNPCBaseComponent::OnAttach((UFG::TargetingSystemPedNPCBaseComponent *)&this->vfptr, pSimObject);
}

// File Line: 143
// RVA: 0x541050
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::OnDetach(UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *v1; // r8
  UFG::TargetingSystemPedNPCBaseComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx

  v1 = &this->m_pAIActionTreeComponent;
  v2 = this;
  if ( this->m_pAIActionTreeComponent.m_pSimComponent )
  {
    v3 = this->m_pAIActionTreeComponent.mNext;
    v4 = v1->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    this->m_pAIActionTreeComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pAIActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *)this->m_pAIActionTreeComponent.mNext != &this->m_pAIActionTreeComponent) )
  {
    v5 = this->m_pAIActionTreeComponent.mNext;
    v6 = v1->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    goto LABEL_7;
  }
LABEL_8:
  v1->m_Changed = 1;
  UFG::TargetingSystemPedBaseComponent::OnDetach((UFG::TargetingSystemPedBaseComponent *)&v2->vfptr);
}

// File Line: 160
// RVA: 0x571710
void __fastcall UFG::TargetingSystemPedNPCAmbientComponent::updateFocusTarget(UFG::TargetingSystemPedNPCAmbientComponent *this)
{
  UFG::TargetingSystemPedNPCAmbientComponent *v1; // rbx
  UFG::TargetingSimObject *v2; // rax
  signed __int64 v3; // rdx
  bool v4; // di
  bool v5; // al
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rdx
  unsigned __int8 v8; // cl

  v1 = this;
  v2 = this->m_pTargets;
  v3 = (unsigned __int8)this->m_pTargetingMap->m_Map.p[22];
  v4 = v2[v3].m_pTarget.m_pPointer && v2[v3].m_bLock;
  v5 = UFG::TargetingSystemPedNPCBaseComponent::isScriptControlled((UFG::TargetingSystemPedNPCBaseComponent *)&this->vfptr);
  if ( !v4 && v5 )
  {
    v6 = v1->m_pActiveAIEntityComponent.m_pSimComponent;
    if ( v6 )
    {
      v7 = (UFG::SimObject *)v6[38].m_BoundComponentHandles.mNode.mNext;
      if ( v7 )
      {
        v8 = v1->m_pTargetingMap->m_Map.p[22];
        if ( v8 )
          UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v8], v7);
      }
    }
  }
}

// File Line: 183
// RVA: 0x579D00
void __fastcall UFG::TargetingSystemPedNPCAmbientComponent::updateTargets(UFG::TargetingSystemPedNPCAmbientComponent *this)
{
  UFG::TargetingSystemPedNPCAmbientComponent *v1; // rbx
  UFG::SimComponent *v2; // rax
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm3_4
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePickupsList; // [rsp+48h] [rbp-4250h]
  UFG::qFixedArray<UFG::CloseTarget *,5> filteredClosePropsList; // [rsp+78h] [rbp-4220h]
  UFG::qFixedArray<UFG::CloseTarget *,20> filteredCloseVehiclesList; // [rsp+B0h] [rbp-41E8h]
  UFG::qFixedArray<UFG::CloseTarget *,80> filteredClosePedsList; // [rsp+160h] [rbp-4138h]
  UFG::qFixedArray<UFG::CloseTarget,100> closeTargetsList; // [rsp+3F0h] [rbp-3EA8h]
  UFG::qFixedArray<UFG::CloseTarget,100> filteredCloseTargetsList; // [rsp+2340h] [rbp-1F58h]

  v1 = this;
  closeTargetsList.size = 0;
  filteredClosePedsList.size = 0;
  filteredCloseTargetsList.size = 0;
  filteredClosePickupsList.size = 0;
  filteredClosePropsList.size = 0;
  filteredCloseVehiclesList.size = 0;
  v2 = this->m_pEquippedSOWPC.m_pPointer;
  if ( v2 )
  {
    v3 = *(float *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject)) + 40i64);
    v4 = v3 * v3;
  }
  else
  {
    v4 = this->m_pActiveTargetingProfile->m_fMaximumTargetDistanceSquared;
  }
  v5 = this->m_fMinimumTargetDistanceSquared;
  if ( v5 <= v4 )
    v5 = v4;
  UFG::TargetingSystemPedBaseComponent::findCloseTargets(
    &closeTargetsList,
    this->m_pSimObject,
    &this->m_vTargetingPosition,
    v5);
  UFG::TargetingSystemPedBaseComponent::filterCloseTargets(
    &closeTargetsList,
    &v1->m_CachedPedsList,
    &filteredClosePedsList,
    &filteredClosePickupsList,
    &filteredClosePropsList,
    &filteredCloseVehiclesList,
    &filteredCloseTargetsList);
  UFG::TargetingSystemPedNPCAmbientComponent::updateFocusTarget(v1);
  UFG::TargetingSystemPedBaseComponent::updateClosestPedTarget(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &filteredClosePedsList);
  UFG::TargetingSystemPedBaseComponent::updatePickupTarget(
    (UFG::TargetingSystemPedBaseComponent *)&v1->vfptr,
    &filteredClosePickupsList);
  UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets((UFG::TargetingSystemPedBaseComponent *)&v1->vfptr);
  UFG::TargetingSystemBaseComponent::updateMySpawnPointTarget((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
}

// File Line: 217
// RVA: 0x549D20
void __fastcall UFG::TargetingSystemPedNPCCombatantComponent::Reset(UFG::TargetingSystemPedNPCCombatantComponent *this)
{
  UFG::TargetingSystemPedNPCCombatantComponent *v1; // rbx
  unsigned int *v2; // rcx

  v1 = this;
  UFG::TargetingSystemBaseComponent::shutdown((UFG::TargetingSystemBaseComponent *)&this->vfptr);
  UFG::TargetingSystemBaseComponent::initialize((UFG::TargetingSystemBaseComponent *)&v1->vfptr);
  v2 = v1->m_pBucketList;
  v1->m_CachedPedsList.size = 0;
  if ( v2 )
  {
    --v2[v1->m_uUpdateBucket];
    v1->m_pBucketList = 0i64;
  }
  UFG::TargetingSystemPedBaseComponent::initialize((UFG::TargetingSystemPedBaseComponent *)&v1->vfptr);
  UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate((UFG::TargetingSystemPedBaseComponent *)&v1->vfptr);
}

// File Line: 227
// RVA: 0x55CD20
void __fastcall UFG::TargetingSystemPedNPCAmbientComponent::Update(UFG::TargetingSystemPedNPCAmbientComponent *this, float delta_sec)
{
  UFG::TargetingSystemPedNPCAmbientComponent *v2; // rbx
  __int64 v3; // rdi

  v2 = this;
  UFG::TargetingSystemPedBaseComponent::UpdateCommon((UFG::TargetingSystemPedBaseComponent *)&this[-1].mPrev);
  UFG::TargetingSystemPedNPCBaseComponent::updateTargetingIntentions((UFG::TargetingSystemPedNPCBaseComponent *)&v2[-1].mPrev);
  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> **))v2[-1].mPrev[11].mPrev)(&v2[-1].mPrev) )
    UFG::TargetingSystemPedNPCAmbientComponent::updateTargets((UFG::TargetingSystemPedNPCAmbientComponent *)((char *)v2 - 64));
  v3 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v2->m_Flags + 30i64) + *(_QWORD *)&v2->m_TypeUID + 40);
  if ( v3 != *(_QWORD *)&v2->m_vTargetingPosition.z )
  {
    ((void (*)(void))v2->m_pTransformNodeComponent.mNext->mPrev[11].mPrev)();
    *(_QWORD *)&v2->m_vTargetingPosition.z = v3;
  }
  LOBYTE(v2->m_pInterestPointUserComponent.m_Changed) = 0;
}

