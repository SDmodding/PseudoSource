// File Line: 44
// RVA: 0x14AEAE0
__int64 dynamic_initializer_for__UFG::FormationManagerComponent::s_FormationManagerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::FormationManagerComponent::s_FormationManagerComponentList__);
}

// File Line: 45
// RVA: 0x363360
const char *__fastcall UFG::FormationManagerComponent::GetTypeName(UFG::FormationManagerComponent *this)
{
  return "FormationManagerComponent";
}

// File Line: 50
// RVA: 0x14AEC20
hkSeekableStreamReader *dynamic_initializer_for__UFG::FormationManagerComponent::s_Profiles__()
{
  ActionID *v0; // rbx
  signed int v1; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::FormationManagerComponent::s_Profiles;
  v1 = 15;
  do
  {
    result = Assembly::GetRCX(v0);
    v0 += 29;
    --v1;
  }
  while ( v1 >= 0 );
  return result;
}

// File Line: 83
// RVA: 0x3688E0
void __fastcall UFG::FormationSlot::InitWithDefaults(UFG::FormationSlot *this, UFG::FormationManagerComponent *parent, int range_index, int slot_index)
{
  UFG::FormationManagerComponent *v4; // r11
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v5; // rdx
  UFG::FormationSlot *v6; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  signed __int64 v12; // r10
  __int64 v13; // rcx
  _QWORD *v14; // rax

  *(_QWORD *)&this->m_Direction.x = 1065353216i64;
  v4 = parent;
  this->m_Direction.z = 0.0;
  *(_QWORD *)&this->m_FacingDirection.x = 1065353216i64;
  *(_QWORD *)&this->m_FacingDirection.z = 0i64;
  v5 = &this->m_pFormationManagerComponent;
  this->m_Angle = 0;
  this->m_DesiredSpeed = 2;
  this->m_TimeGotIntoPosition = -99999.0;
  this->m_NextTimeToChangePosition = -99999.0;
  this->m_TimeFinishUsingLargeHysteresis = -1.0;
  *(_WORD *)&this->m_CurrentlyInRange = 0;
  this->m_RequestedToChangePosition = 0;
  this->m_Fixed = 0;
  *(_QWORD *)&this->m_RadialHysteresisModifierMin = 0i64;
  *(_QWORD *)&this->m_RadialHysteresisModifier = 0i64;
  this->m_CurrentlyStayingClose = 0;
  v6 = this;
  if ( this->m_pFormationManagerComponent.m_pPointer )
  {
    v7 = v5->mPrev;
    v8 = v5->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = (UFG::SimComponent *)&v4->vfptr;
  if ( v4 )
  {
    v9 = v4->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mPrev = v9;
    v5->mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v6->m_RangeIndex = range_index;
  v6->m_SlotIndex = slot_index;
  v6->m_UseAbsolutePosition = 0;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  v12 = (signed __int64)&v6->m_pMember;
  *(float *)(v12 + 52) = UFG::qVector3::msZero.x;
  *(float *)(v12 + 56) = v10;
  *(float *)(v12 + 60) = v11;
  if ( *(_QWORD *)(v12 + 16) )
  {
    v13 = *(_QWORD *)v12;
    v14 = *(_QWORD **)(v12 + 8);
    *(_QWORD *)(v13 + 8) = v14;
    *v14 = v13;
    *(_QWORD *)v12 = v12;
    *(_QWORD *)(v12 + 8) = v12;
  }
  *(_QWORD *)(v12 + 16) = 0i64;
}

// File Line: 111
// RVA: 0x387AD0
void __fastcall UFG::FormationSlot::SetRadialHysteresisModifier(UFG::FormationSlot *this)
{
  float v1; // xmm6_4
  float v2; // xmm7_4
  UFG::FormationSlot *v3; // rbx
  float v4; // xmm0_4

  v1 = this->m_RadialHysteresisModifierMax;
  v2 = this->m_RadialHysteresisModifierMin;
  v3 = this;
  if ( v1 <= v2 )
  {
    this->m_RadialHysteresisModifier = v1;
  }
  else
  {
    v4 = UFG::qRandom(v1 - v2, &UFG::qDefaultSeed) + v2;
    if ( v4 <= v2 )
      v4 = v2;
    if ( v4 >= v1 )
      v3->m_RadialHysteresisModifier = v1;
    else
      v3->m_RadialHysteresisModifier = v4;
  }
}

// File Line: 116
// RVA: 0x362FB0
float __fastcall UFG::FormationSlot::GetTimeUntilNextChangePosition(UFG::FormationSlot *this)
{
  UFG::FormationSlot *v1; // rbx
  UFG::SimComponent *v2; // rax
  __int64 v3; // rcx
  char v4; // al
  UFG::SimObject *v5; // rcx
  char v6; // di
  UFG::SimComponent *v7; // rax
  char v8; // al
  float v9; // xmm1_4
  float result; // xmm0_4

  v1 = this;
  if ( !this->m_RangeIndex )
  {
    v2 = this->m_pFormationManagerComponent.m_pPointer;
    if ( v2 )
    {
      v3 = *(_QWORD *)&v2[2].m_Flags;
      if ( v3 )
      {
        v4 = (*(__int64 (**)(void))(*(_QWORD *)v3 + 112i64))();
        v5 = v1->m_pMemberSimObject.m_pPointer;
        v6 = v4;
        if ( v5 && (v7 = UFG::SimObject::GetComponentOfType(v5, UFG::ActiveAIEntityComponent::_TypeUID)) != 0i64 )
          v8 = ((__int64 (__fastcall *)(UFG::SimComponent *))v7->vfptr[14].__vecDelDtor)(v7);
        else
          v8 = 0;
        if ( v6 && v8 )
        {
          v9 = FLOAT_3_0;
          result = UFG::qRandom(2.0, &UFG::qDefaultSeed) + 3.0;
          if ( result > 3.0 )
          {
            if ( result >= 5.0 )
              result = FLOAT_5_0;
            return result;
          }
          return v9;
        }
      }
    }
  }
  v9 = *(float *)&FLOAT_1_0;
  result = UFG::qRandom(2.0, &UFG::qDefaultSeed) + 1.0;
  if ( result <= 1.0 )
    return v9;
  if ( result >= 3.0 )
    result = FLOAT_3_0;
  return result;
}

// File Line: 153
// RVA: 0x386680
void __fastcall UFG::FormationSlot::SetInPosition(UFG::FormationSlot *this, UFG::eInFormationPositionType in_position)
{
  UFG::eInFormationPositionType v2; // edi
  UFG::FormationSlot *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm0_4
  UFG::SimComponent *v6; // rax

  v2 = in_position;
  v3 = this;
  if ( this->m_InPosition == eIN_POSITION || in_position )
  {
    this->m_InPosition = in_position;
  }
  else
  {
    v4 = UFG::Metrics::msInstance.mSimTime_Temp;
    this->m_TimeGotIntoPosition = UFG::Metrics::msInstance.mSimTime_Temp;
    this->m_NextTimeToChangePosition = UFG::FormationSlot::GetTimeUntilNextChangePosition(this) + v4;
    v5 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
    v3->m_Fixed = v2;
    v3->m_UseAbsolutePosition = v2;
    v3->m_DesiredSpeed = (v5 < 0.5) + 1;
    v6 = v3->m_pFormationManagerComponent.m_pPointer;
    if ( v6 )
      v3->m_FacingType = HIDWORD(v6[5].m_BoundComponentHandles.mNode.mNext);
    else
      v3->m_FacingType = 0;
    UFG::FormationSlot::SetRadialHysteresisModifier(v3);
    v3->m_InPosition = v2;
  }
}

// File Line: 197
// RVA: 0x385490
void __fastcall UFG::FormationManagerComponent::SetDefaultProfile(UFG::FormationProfile *profile)
{
  UFG::FormationProfile *v1; // rdx
  unsigned __int16 *v2; // rcx
  signed __int64 v3; // r8

  v1 = profile;
  if ( !(_S12_1 & 1) )
    _S12_1 |= 1u;
  dword_1423C1AC0 = profile->m_NameID.mUID;
  dword_1423C1AC4 = profile->m_RingType[0];
  dword_1423C1AC8 = profile->m_RingType[1];
  dword_1423C1ACC = profile->m_RingType[2];
  dword_1423C1AD0 = profile->m_RingType[3];
  dword_1423C1AD4 = LODWORD(profile->m_MaxDistanceOverride[0]);
  dword_1423C1AD8 = LODWORD(profile->m_MaxDistanceOverride[1]);
  dword_1423C1ADC = LODWORD(profile->m_MaxDistanceOverride[2]);
  dword_1423C1AE0 = LODWORD(profile->m_MaxDistanceOverride[3]);
  v2 = &profile->m_RingAngle[0][1];
  v3 = 16i64;
  do
  {
    *(unsigned __int16 *)((char *)v2 + &unk_1423C1AE4 - (_UNKNOWN *)v1 - 38) = *(v2 - 1);
    *(unsigned __int16 *)((char *)v2 + (char *)&dword_1423C1AC0 - (char *)v1) = *v2;
    v2 += 2;
    --v3;
  }
  while ( v3 );
  dword_1423C1B24 = v1->m_NumRingAngles[0];
  dword_1423C1B28 = v1->m_NumRingAngles[1];
  dword_1423C1B2C = v1->m_NumRingAngles[2];
  dword_1423C1B30 = v1->m_NumRingAngles[3];
}

// File Line: 203
// RVA: 0x37EC70
UFG::SimComponent *__fastcall UFG::FormationManagerComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
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
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-40h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_FormationManager::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v7 = 0i64;
  if ( !v2 && !v7 )
    return 0i64;
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x1B88ui64, "FormationManagerComponent", 0i64, 1u);
  if ( v10 )
  {
    v11 = v3->mpWritableProperties;
    if ( !v11 )
      v11 = v3->mpConstProperties;
    UFG::FormationManagerComponent::FormationManagerComponent(
      (UFG::FormationManagerComponent *)v10,
      v3->m_NameUID,
      v11,
      (component_FormationManager *)v7);
    v6 = v12;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v13, v3->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  return v6;
}

// File Line: 223
// RVA: 0x32E8F0
void __fastcall UFG::FormationManagerComponent::FormationManagerComponent(UFG::FormationManagerComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, component_FormationManager *data)
{
  component_FormationManager *v4; // rdi
  UFG::qPropertySet *v5; // rsi
  UFG::FormationManagerComponent *v6; // r14
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v7; // rbx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v8; // rax

  v4 = data;
  v5 = properties;
  v6 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v7 = (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)&v6->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FormationManagerComponent::`vftable';
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v6->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::RebindingComponentHandle<UFG::AIEntityComponent,0>(&v6->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v6->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v6->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::RebindingComponentHandle<UFG::AttackRightsComponent,0>(&v6->m_pAttackRightsComponent);
  `eh vector constructor iterator'(
    v6->mStateVariables.m_FormationSlot,
    0xC8ui64,
    32,
    (void (__fastcall *)(void *))UFG::FormationSlot::FormationSlot);
  v8 = UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mPrev;
  UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)&v6->mPrev;
  v7->mPrev = v8;
  v6->mNext = (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)&UFG::FormationManagerComponent::s_FormationManagerComponentList;
  UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mPrev = (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)&v6->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v6->vfptr,
    UFG::FormationManagerComponent::_FormationManagerComponentTypeUID,
    "FormationManagerComponent");
  v6->mStateVariables.m_pCurrentProfile = 0i64;
  v6->mStateVariables.m_RangeSwitchesFrozen = 0;
  v6->m_DebugDrawEnabled = 0;
  UFG::FormationManagerComponent::Clear(v6);
  UFG::FormationManagerComponent::InitFromProperties(v6, v5, v4);
}

// File Line: 236
// RVA: 0x337090
void __fastcall UFG::FormationManagerComponent::~FormationManagerComponent(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rdi
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v2; // rbx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v3; // rcx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v4; // rax
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v5; // rcx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FormationManagerComponent::`vftable';
  if ( this == UFG::FormationManagerComponent::s_FormationManagerComponentpCurrentIterator )
    UFG::FormationManagerComponent::s_FormationManagerComponentpCurrentIterator = (UFG::FormationManagerComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  `eh vector destructor iterator'(
    v1->mStateVariables.m_FormationSlot,
    0xC8ui64,
    32,
    (void (__fastcall *)(void *))UFG::FormationSlot::~FormationSlot);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAttackRightsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->m_pTransformNodeComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 241
// RVA: 0x34EA30
void __fastcall UFG::FormationManagerComponent::Clear(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rbp
  int v2; // er14
  _DWORD *v3; // rbx
  UFG::FormationSlot *v4; // rsi
  int v5; // edi
  signed __int64 v6; // rdx
  signed __int64 v7; // rbp
  _DWORD *v8; // rax
  signed __int64 v9; // rcx

  v1 = this;
  if ( !(_S12_1 & 1) )
    _S12_1 |= 1u;
  this->mStateVariables.m_pCurrentProfile = (UFG::FormationProfile *)&dword_1423C1AC0;
  this->m_NumRanges = 4;
  this->m_FormationFacingType = 0;
  this->mStateVariables.m_UseClosestGuyInsteadOfMyTarget = 1;
  *(_WORD *)&this->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus = 0;
  *(_QWORD *)&this->mStateVariables.m_MyID = 0i64;
  this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeCheckPlayersTarget = -1.0;
  this->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeCheckPlayersTarget = -1.0;
  this->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeCheckPlayersTarget = -1.0;
  this->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeCheckPlayersTarget = -1.0;
  this->mStateVariables.m_NextTimeToCheckPlayersTarget = -1.0;
  this->m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = -1.0;
  v2 = 0;
  v3 = (_DWORD *)this->m_BattleTypeSpecificParameters[1].m_MaxDistance;
  v4 = (UFG::FormationSlot *)this->mStateVariables.m_FormationSlot;
  do
  {
    *(v3 - 12) = 1203982208;
    *v3 = 1203982208;
    *(v3 - 62) = 8;
    *(v3 - 58) = 8;
    *(v3 - 54) = 8;
    *(v3 - 49) = 0;
    *(v3 - 45) = 0;
    *(v3 - 41) = 0;
    *(v3 - 37) = 0;
    *(v3 - 33) = 0;
    *(v3 - 28) = 1065353216;
    *(v3 - 24) = 1065353216;
    v5 = 0;
    do
    {
      UFG::FormationSlot::InitWithDefaults(v4, v1, v2, v5++);
      ++v4;
    }
    while ( v5 < 8 );
    ++v2;
    ++v3;
  }
  while ( v2 < 4 );
  v6 = 22i64;
  v7 = (signed __int64)v1->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange;
  do
  {
    v8 = (_DWORD *)v7;
    v9 = 3i64;
    do
    {
      *(v8 - 3) = -1082130432;
      *v8 = -1082130432;
      v8[v6] = -1082130432;
      ++v8;
      --v9;
    }
    while ( v9 );
    v7 += 48i64;
    v6 -= 12i64;
  }
  while ( v6 > -2 );
}

// File Line: 299
// RVA: 0x3671E0
void __fastcall UFG::FormationManagerComponent::InitFromProperties(UFG::FormationManagerComponent *this, UFG::qPropertySet *property_set, component_FormationManager *data)
{
  int v3; // ebx
  component_FormationManager *v4; // rsi
  UFG::qPropertySet *v5; // rbp
  UFG::FormationManagerComponent *v6; // rdi
  signed __int64 v7; // rcx
  unsigned __int16 (*v8)[8]; // rax
  int v9; // er11
  float v10; // xmm0_4
  float v11; // xmm1_4
  signed __int64 v12; // r8
  ActionID *v13; // rdx
  float v14; // xmm0_4
  signed __int64 v15; // rcx
  float v16; // xmm1_4
  __int16 v17; // ax
  UFG::qPropertySet *v18; // rax
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // eax
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm7_4
  float v44; // xmm8_4
  float v45; // xmm9_4
  float v46; // xmm0_4
  float v47; // xmm7_4
  float v48; // xmm8_4
  float v49; // xmm9_4
  float v50; // xmm0_4
  float v51; // xmm7_4
  float v52; // xmm8_4
  float v53; // xmm9_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  float v56; // xmm9_4
  __int64 v57; // rcx
  float v58; // xmm7_4
  float v59; // xmm8_4
  float v60; // xmm0_4
  float v61; // xmm7_4
  float v62; // xmm8_4
  float v63; // xmm9_4
  float v64; // xmm0_4
  float v65; // xmm7_4
  float v66; // xmm8_4
  float v67; // xmm9_4
  float v68; // xmm0_4
  float v69; // xmm7_4
  float v70; // xmm8_4
  float v71; // xmm9_4
  float v72; // xmm0_4
  float v73; // xmm0_4
  float v74; // xmm9_4
  __int64 v75; // rcx
  float v76; // xmm7_4
  float v77; // xmm8_4
  float v78; // xmm0_4
  __int64 v79; // rax
  const char *v80; // rbp
  const char **v81; // rsi
  UFG::FormationProfile profile; // [rsp+20h] [rbp-C8h]

  v3 = 0;
  v4 = data;
  v5 = property_set;
  v6 = this;
  if ( !once_8 )
  {
    profile.m_NameID.mUID = 0;
    v7 = 0i64;
    v8 = profile.m_RingAngle;
    do
    {
      profile.m_RingType[v7] = 0;
      profile.m_MaxDistanceOverride[v7] = -1.0;
      profile.m_NumRingAngles[v7] = 0;
      *(_QWORD *)v8 = 0i64;
      ++v7;
      *(_QWORD *)&(*v8)[4] = 0i64;
      ++v8;
    }
    while ( v7 < 4 );
    v9 = UFG::FormationManagerComponent::s_NumProfiles;
    *(_QWORD *)profile.m_RingType = 0i64;
    *(_QWORD *)&profile.m_RingType[2] = 0i64;
    if ( UFG::FormationManagerComponent::s_NumProfiles < 16 )
    {
      v10 = profile.m_MaxDistanceOverride[0];
      v11 = profile.m_MaxDistanceOverride[1];
      v12 = 16i64;
      v13 = &UFG::FormationManagerComponent::s_Profiles + 29 * UFG::FormationManagerComponent::s_NumProfiles;
      v13->mUID = (unsigned int)profile.m_NameID;
      *(_QWORD *)&v13[1].mUID = 0i64;
      *(_QWORD *)&v13[3].mUID = 0i64;
      *(float *)&v13[5].mUID = v10;
      v14 = profile.m_MaxDistanceOverride[2];
      *(float *)&v13[6].mUID = v11;
      v15 = (signed __int64)&v13[9].mUID + 2;
      v16 = profile.m_MaxDistanceOverride[3];
      *(float *)&v13[7].mUID = v14;
      *(float *)&v13[8].mUID = v16;
      do
      {
        v17 = *(_WORD *)((char *)profile.m_RingAngle - (char *)v13 + v15 - 38);
        v15 += 4i64;
        *(_WORD *)(v15 - 6) = v17;
        *(_WORD *)(v15 - 4) = *(_WORD *)((char *)&profile - (char *)v13 + v15 - 4);
        --v12;
      }
      while ( v12 );
      v13[25].mUID = profile.m_NumRingAngles[0];
      UFG::FormationManagerComponent::s_NumProfiles = v9 + 1;
      v13[26].mUID = profile.m_NumRingAngles[1];
      v13[27].mUID = profile.m_NumRingAngles[2];
      v13[28].mUID = profile.m_NumRingAngles[3];
    }
    UFG::FormationManagerComponent::SetDefaultProfile(&profile);
    once_8 = 1;
  }
  if ( !v4 )
  {
    v18 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v5,
            (UFG::qSymbol *)&component_FormationManager::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v18 )
      v4 = (component_FormationManager *)UFG::qPropertySet::GetMemImagePtr(v18);
    else
      v4 = 0i64;
  }
  if ( v4->NumRanges <= 4 )
    v6->m_NumRanges = v4->NumRanges;
  UFG::FormationManagerComponent::SetNumSlotsPerRange(v6, 0, v4->NumSlotsInRange0);
  UFG::FormationManagerComponent::SetNumSlotsPerRange(v6, 1, v4->NumSlotsInRange1);
  UFG::FormationManagerComponent::SetNumSlotsPerRange(v6, 2, v4->NumSlotsInRange2);
  UFG::FormationManagerComponent::SetNumSlotsPerRange(v6, 3, v4->NumSlotsInRange3);
  v19 = v4->MaxRadialDistanceFromDesiredPositionHysteresisLarge0;
  v20 = v4->MaxRadialDistanceFromDesiredPositionHysteresis0;
  v6->m_MaxRadialDistanceFromDesiredPosition[0] = v4->MaxRadialDistanceFromDesiredPosition0;
  v6->m_MaxRadialDistanceFromDesiredPositionHysteresis[0] = v20;
  v6->m_MaxRadialDistanceFromDesiredPositionHysteresisLarge[0] = v19;
  v21 = v4->MaxRadialDistanceFromDesiredPositionHysteresisLarge1;
  v22 = v4->MaxRadialDistanceFromDesiredPositionHysteresis1;
  v6->m_MaxRadialDistanceFromDesiredPosition[1] = v4->MaxRadialDistanceFromDesiredPosition1;
  v6->m_MaxRadialDistanceFromDesiredPositionHysteresis[1] = v22;
  v6->m_MaxRadialDistanceFromDesiredPositionHysteresisLarge[1] = v21;
  v23 = v4->MaxRadialDistanceFromDesiredPositionHysteresisLarge2;
  v24 = v4->MaxRadialDistanceFromDesiredPositionHysteresis2;
  v6->m_MaxRadialDistanceFromDesiredPosition[2] = v4->MaxRadialDistanceFromDesiredPosition2;
  v6->m_MaxRadialDistanceFromDesiredPositionHysteresis[2] = v24;
  v6->m_MaxRadialDistanceFromDesiredPositionHysteresisLarge[2] = v23;
  v25 = v4->MaxRadialDistanceFromDesiredPosition3;
  v26 = v4->MaxRadialDistanceFromDesiredPositionHysteresis3;
  v6->m_MaxRadialDistanceFromDesiredPositionHysteresisLarge[3] = v4->MaxRadialDistanceFromDesiredPositionHysteresisLarge3;
  v6->m_MaxRadialDistanceFromDesiredPosition[3] = v25;
  v6->m_MaxRadialDistanceFromDesiredPositionHysteresis[3] = v26;
  v27 = v4->MaxLateralDistanceFromDesiredPositionHysteresis0;
  v6->m_MaxLateralDistanceFromDesiredPosition[0] = v4->MaxLateralDistanceFromDesiredPosition0;
  v6->m_MaxLateralDistanceFromDesiredPositionHysteresis[0] = v27;
  v28 = v4->MaxLateralDistanceFromDesiredPositionHysteresis1;
  v6->m_MaxLateralDistanceFromDesiredPosition[1] = v4->MaxLateralDistanceFromDesiredPosition1;
  v6->m_MaxLateralDistanceFromDesiredPositionHysteresis[1] = v28;
  v29 = v4->MaxLateralDistanceFromDesiredPositionHysteresis2;
  v6->m_MaxLateralDistanceFromDesiredPosition[2] = v4->MaxLateralDistanceFromDesiredPosition2;
  v6->m_MaxLateralDistanceFromDesiredPositionHysteresis[2] = v29;
  v30 = v4->MaxLateralDistanceFromDesiredPositionHysteresis3;
  v6->m_MaxLateralDistanceFromDesiredPosition[3] = v4->MaxLateralDistanceFromDesiredPosition3;
  v6->m_MaxLateralDistanceFromDesiredPositionHysteresis[3] = v30;
  v31 = v4->MaxFacingDifferenceHysteresis0;
  v6->m_MinFacingDifference[0] = v4->MaxFacingDifference0;
  v6->m_MinFacingDifferenceHysteresis[0] = v31;
  v32 = v4->MaxFacingDifferenceHysteresis1;
  v6->m_MinFacingDifference[1] = v4->MaxFacingDifference1;
  v6->m_MinFacingDifferenceHysteresis[1] = v32;
  v33 = v4->MaxFacingDifferenceHysteresis2;
  v6->m_MinFacingDifference[2] = v4->MaxFacingDifference2;
  v6->m_MinFacingDifferenceHysteresis[2] = v33;
  v34 = v4->MaxFacingDifferenceHysteresis3;
  v6->m_MinFacingDifference[3] = v4->MaxFacingDifference3;
  v6->m_MinFacingDifferenceHysteresis[3] = v34;
  v35 = v4->RadialHysteresisModifierMax0;
  v36 = v4->RadialHysteresisModifierMin0;
  v6->mStateVariables.m_FormationSlot[0][0].m_RadialHysteresisModifierMin = v36;
  v6->mStateVariables.m_FormationSlot[0][0].m_RadialHysteresisModifierMax = v35;
  v6->mStateVariables.m_FormationSlot[0][1].m_RadialHysteresisModifierMin = v36;
  v6->mStateVariables.m_FormationSlot[0][1].m_RadialHysteresisModifierMax = v35;
  v6->mStateVariables.m_FormationSlot[0][2].m_RadialHysteresisModifierMin = v36;
  v6->mStateVariables.m_FormationSlot[0][2].m_RadialHysteresisModifierMax = v35;
  v6->mStateVariables.m_FormationSlot[0][3].m_RadialHysteresisModifierMin = v36;
  v6->mStateVariables.m_FormationSlot[0][3].m_RadialHysteresisModifierMax = v35;
  v6->mStateVariables.m_FormationSlot[0][4].m_RadialHysteresisModifierMin = v36;
  v6->mStateVariables.m_FormationSlot[0][4].m_RadialHysteresisModifierMax = v35;
  v6->mStateVariables.m_FormationSlot[0][5].m_RadialHysteresisModifierMin = v36;
  v6->mStateVariables.m_FormationSlot[0][5].m_RadialHysteresisModifierMax = v35;
  v6->mStateVariables.m_FormationSlot[0][6].m_RadialHysteresisModifierMin = v36;
  v6->mStateVariables.m_FormationSlot[0][6].m_RadialHysteresisModifierMax = v35;
  v6->mStateVariables.m_FormationSlot[0][7].m_RadialHysteresisModifierMin = v36;
  v6->mStateVariables.m_FormationSlot[0][7].m_RadialHysteresisModifierMax = v35;
  v37 = v4->RadialHysteresisModifierMin1;
  v38 = v4->RadialHysteresisModifierMax1;
  v6->mStateVariables.m_FormationSlot[1][0].m_RadialHysteresisModifierMin = v37;
  v6->mStateVariables.m_FormationSlot[1][0].m_RadialHysteresisModifierMax = v38;
  v6->mStateVariables.m_FormationSlot[1][1].m_RadialHysteresisModifierMin = v37;
  v6->mStateVariables.m_FormationSlot[1][1].m_RadialHysteresisModifierMax = v38;
  v6->mStateVariables.m_FormationSlot[1][2].m_RadialHysteresisModifierMin = v37;
  v6->mStateVariables.m_FormationSlot[1][2].m_RadialHysteresisModifierMax = v38;
  v6->mStateVariables.m_FormationSlot[1][3].m_RadialHysteresisModifierMin = v37;
  v6->mStateVariables.m_FormationSlot[1][3].m_RadialHysteresisModifierMax = v38;
  v6->mStateVariables.m_FormationSlot[1][4].m_RadialHysteresisModifierMin = v37;
  v6->mStateVariables.m_FormationSlot[1][4].m_RadialHysteresisModifierMax = v38;
  v6->mStateVariables.m_FormationSlot[1][5].m_RadialHysteresisModifierMin = v37;
  v6->mStateVariables.m_FormationSlot[1][5].m_RadialHysteresisModifierMax = v38;
  v6->mStateVariables.m_FormationSlot[1][6].m_RadialHysteresisModifierMin = v37;
  v6->mStateVariables.m_FormationSlot[1][6].m_RadialHysteresisModifierMax = v38;
  v6->mStateVariables.m_FormationSlot[1][7].m_RadialHysteresisModifierMin = v37;
  v6->mStateVariables.m_FormationSlot[1][7].m_RadialHysteresisModifierMax = v38;
  v39 = v4->RadialHysteresisModifierMin2;
  v40 = v4->RadialHysteresisModifierMax2;
  v6->mStateVariables.m_FormationSlot[2][0].m_RadialHysteresisModifierMin = v39;
  v6->mStateVariables.m_FormationSlot[2][0].m_RadialHysteresisModifierMax = v40;
  v6->mStateVariables.m_FormationSlot[2][1].m_RadialHysteresisModifierMin = v39;
  v6->mStateVariables.m_FormationSlot[2][1].m_RadialHysteresisModifierMax = v40;
  v6->mStateVariables.m_FormationSlot[2][2].m_RadialHysteresisModifierMin = v39;
  v6->mStateVariables.m_FormationSlot[2][2].m_RadialHysteresisModifierMax = v40;
  v6->mStateVariables.m_FormationSlot[2][3].m_RadialHysteresisModifierMin = v39;
  v6->mStateVariables.m_FormationSlot[2][3].m_RadialHysteresisModifierMax = v40;
  v6->mStateVariables.m_FormationSlot[2][4].m_RadialHysteresisModifierMin = v39;
  v6->mStateVariables.m_FormationSlot[2][4].m_RadialHysteresisModifierMax = v40;
  v6->mStateVariables.m_FormationSlot[2][5].m_RadialHysteresisModifierMin = v39;
  v6->mStateVariables.m_FormationSlot[2][5].m_RadialHysteresisModifierMax = v40;
  v6->mStateVariables.m_FormationSlot[2][6].m_RadialHysteresisModifierMin = v39;
  v6->mStateVariables.m_FormationSlot[2][6].m_RadialHysteresisModifierMax = v40;
  v6->mStateVariables.m_FormationSlot[2][7].m_RadialHysteresisModifierMin = v39;
  v6->mStateVariables.m_FormationSlot[2][7].m_RadialHysteresisModifierMax = v40;
  v41 = v4->RadialHysteresisModifierMax3;
  v42 = v4->RadialHysteresisModifierMin3;
  v6->mStateVariables.m_FormationSlot[3][0].m_RadialHysteresisModifierMin = v42;
  v6->mStateVariables.m_FormationSlot[3][0].m_RadialHysteresisModifierMax = v41;
  v6->mStateVariables.m_FormationSlot[3][1].m_RadialHysteresisModifierMin = v42;
  v6->mStateVariables.m_FormationSlot[3][1].m_RadialHysteresisModifierMax = v41;
  v6->mStateVariables.m_FormationSlot[3][2].m_RadialHysteresisModifierMin = v42;
  v6->mStateVariables.m_FormationSlot[3][2].m_RadialHysteresisModifierMax = v41;
  v6->mStateVariables.m_FormationSlot[3][3].m_RadialHysteresisModifierMin = v42;
  v6->mStateVariables.m_FormationSlot[3][3].m_RadialHysteresisModifierMax = v41;
  v6->mStateVariables.m_FormationSlot[3][4].m_RadialHysteresisModifierMin = v42;
  v6->mStateVariables.m_FormationSlot[3][4].m_RadialHysteresisModifierMax = v41;
  v6->mStateVariables.m_FormationSlot[3][5].m_RadialHysteresisModifierMin = v42;
  v6->mStateVariables.m_FormationSlot[3][5].m_RadialHysteresisModifierMax = v41;
  v6->mStateVariables.m_FormationSlot[3][6].m_RadialHysteresisModifierMin = v42;
  v6->mStateVariables.m_FormationSlot[3][6].m_RadialHysteresisModifierMax = v41;
  v6->mStateVariables.m_FormationSlot[3][7].m_RadialHysteresisModifierMin = v42;
  v6->mStateVariables.m_FormationSlot[3][7].m_RadialHysteresisModifierMax = v41;
  v6->m_BattleTypeSpecificParameters[0].m_MaxDistance[0] = v4->NormalMaxDistance0;
  v6->m_BattleTypeSpecificParameters[0].m_MaxDistance[1] = v4->NormalMaxDistance1;
  v6->m_BattleTypeSpecificParameters[0].m_MaxDistance[2] = v4->NormalMaxDistance2;
  v6->m_BattleTypeSpecificParameters[0].m_MaxDistance[3] = v4->NormalMaxDistance3;
  v43 = v4->NormalMaxTimeBeforeSwitchFromRange0;
  v6->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[0] = v4->NormalMinTimeBeforeSwitchFromRange0;
  v6->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[0] = v43;
  v44 = v6->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[0];
  v45 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v44 < 0.0 || v43 <= 0.0 )
  {
    v6->mStateVariables.m_NextTimeToSwitchFromRange[0] = -1.0;
  }
  else
  {
    v46 = v43;
    if ( v43 > v44 )
    {
      v46 = UFG::qRandom(v43 - v44, &UFG::qDefaultSeed) + v44;
      if ( v46 <= v44 )
        v46 = v44;
      if ( v46 >= v43 )
        v46 = v43;
    }
    v6->mStateVariables.m_NextTimeToSwitchFromRange[0] = v46 + v45;
  }
  v47 = v4->NormalMaxTimeBeforeSwitchFromRange1;
  v6->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[1] = v4->NormalMinTimeBeforeSwitchFromRange1;
  v6->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[1] = v47;
  v48 = v6->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[1];
  v49 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v48 < 0.0 || v47 <= 0.0 )
  {
    v6->mStateVariables.m_NextTimeToSwitchFromRange[1] = -1.0;
  }
  else
  {
    v50 = v47;
    if ( v47 > v48 )
    {
      v50 = UFG::qRandom(v47 - v48, &UFG::qDefaultSeed) + v48;
      if ( v50 <= v48 )
        v50 = v48;
      if ( v50 >= v47 )
        v50 = v47;
    }
    v6->mStateVariables.m_NextTimeToSwitchFromRange[1] = v50 + v49;
  }
  v51 = v4->NormalMaxTimeBeforeSwitchFromRange2;
  v6->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[2] = v4->NormalMinTimeBeforeSwitchFromRange2;
  v6->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[2] = v51;
  v52 = v6->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[2];
  v53 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v52 < 0.0 || v51 <= 0.0 )
  {
    v6->mStateVariables.m_NextTimeToSwitchFromRange[2] = -1.0;
  }
  else
  {
    v54 = v51;
    if ( v51 > v52 )
    {
      v54 = UFG::qRandom(v51 - v52, &UFG::qDefaultSeed) + v52;
      if ( v54 <= v52 )
        v54 = v52;
      if ( v54 >= v51 )
        v54 = v51;
    }
    v6->mStateVariables.m_NextTimeToSwitchFromRange[2] = v54 + v53;
  }
  v55 = v4->NormalMaxTimeBeforeCheckPlayersTarget;
  v6->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeCheckPlayersTarget = v4->NormalMinTimeBeforeCheckPlayersTarget;
  v6->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeCheckPlayersTarget = v55;
  v56 = UFG::Metrics::msInstance.mSimTime_Temp;
  v57 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v58 = *(float *)&(&v6->vfptr)[6 * (v57 + 11)];
  v59 = v6->m_BattleTypeSpecificParameters[v57].m_MinTimeBeforeCheckPlayersTarget;
  if ( v59 < 0.0 || v58 <= 0.0 )
  {
    v6->mStateVariables.m_NextTimeToCheckPlayersTarget = -1.0;
  }
  else
  {
    v60 = *(float *)&(&v6->vfptr)[6 * (v57 + 11)];
    if ( v58 > v59 )
    {
      v60 = UFG::qRandom(v58 - v59, &UFG::qDefaultSeed) + v59;
      if ( v60 <= v59 )
        v60 = v59;
      if ( v60 >= v58 )
        v60 = v58;
    }
    v6->mStateVariables.m_NextTimeToCheckPlayersTarget = v60 + v56;
  }
  v6->m_BattleTypeSpecificParameters[1].m_MaxDistance[0] = v4->MobMaxDistance0;
  v6->m_BattleTypeSpecificParameters[1].m_MaxDistance[1] = v4->MobMaxDistance1;
  v6->m_BattleTypeSpecificParameters[1].m_MaxDistance[2] = v4->MobMaxDistance2;
  v6->m_BattleTypeSpecificParameters[1].m_MaxDistance[3] = v4->MobMaxDistance3;
  v61 = v4->MobMaxTimeBeforeSwitchFromRange0;
  v6->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[0] = v4->MobMinTimeBeforeSwitchFromRange0;
  v6->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeSwitchFromRange[0] = v61;
  v62 = v6->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[0];
  v63 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v62 < 0.0 || v61 <= 0.0 )
  {
    v6->mStateVariables.m_NextTimeToSwitchFromRange[0] = -1.0;
  }
  else
  {
    v64 = v61;
    if ( v61 > v62 )
    {
      v64 = UFG::qRandom(v61 - v62, &UFG::qDefaultSeed) + v62;
      if ( v64 <= v62 )
        v64 = v62;
      if ( v64 >= v61 )
        v64 = v61;
    }
    v6->mStateVariables.m_NextTimeToSwitchFromRange[0] = v64 + v63;
  }
  v65 = v4->MobMaxTimeBeforeSwitchFromRange1;
  v6->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[1] = v4->MobMinTimeBeforeSwitchFromRange1;
  v6->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeSwitchFromRange[1] = v65;
  v66 = v6->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[1];
  v67 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v66 < 0.0 || v65 <= 0.0 )
  {
    v6->mStateVariables.m_NextTimeToSwitchFromRange[1] = -1.0;
  }
  else
  {
    v68 = v65;
    if ( v65 > v66 )
    {
      v68 = UFG::qRandom(v65 - v66, &UFG::qDefaultSeed) + v66;
      if ( v68 <= v66 )
        v68 = v66;
      if ( v68 >= v65 )
        v68 = v65;
    }
    v6->mStateVariables.m_NextTimeToSwitchFromRange[1] = v68 + v67;
  }
  v69 = v4->MobMaxTimeBeforeSwitchFromRange2;
  v6->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[2] = v4->MobMinTimeBeforeSwitchFromRange2;
  v6->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeSwitchFromRange[2] = v69;
  v70 = v6->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[2];
  v71 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v70 < 0.0 || v69 <= 0.0 )
  {
    v6->mStateVariables.m_NextTimeToSwitchFromRange[2] = -1.0;
  }
  else
  {
    v72 = v69;
    if ( v69 > v70 )
    {
      v72 = UFG::qRandom(v69 - v70, &UFG::qDefaultSeed) + v70;
      if ( v72 <= v70 )
        v72 = v70;
      if ( v72 >= v69 )
        v72 = v69;
    }
    v6->mStateVariables.m_NextTimeToSwitchFromRange[2] = v72 + v71;
  }
  v73 = v4->MobMaxTimeBeforeCheckPlayersTarget;
  v6->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeCheckPlayersTarget = v4->MobMinTimeBeforeCheckPlayersTarget;
  v6->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeCheckPlayersTarget = v73;
  v74 = UFG::Metrics::msInstance.mSimTime_Temp;
  v75 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v76 = *(float *)&(&v6->vfptr)[6 * (v75 + 11)];
  v77 = v6->m_BattleTypeSpecificParameters[v75].m_MinTimeBeforeCheckPlayersTarget;
  if ( v77 < 0.0 || v76 <= 0.0 )
  {
    v6->mStateVariables.m_NextTimeToCheckPlayersTarget = -1.0;
  }
  else
  {
    v78 = *(float *)&(&v6->vfptr)[6 * (v75 + 11)];
    if ( v76 > v77 )
    {
      v78 = UFG::qRandom(v76 - v77, &UFG::qDefaultSeed) + v77;
      if ( v78 <= v77 )
        v78 = v77;
      if ( v78 >= v76 )
        v78 = v76;
    }
    v6->mStateVariables.m_NextTimeToCheckPlayersTarget = v78 + v74;
  }
  v6->m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = v4->MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
  v79 = v4->FacingTypeEnumString.mOffset;
  if ( v79 )
  {
    v80 = (char *)&v4->FacingTypeEnumString + v79;
    if ( v80 )
    {
      if ( *v80 )
      {
        v81 = UFG::FormationFacingTypeNames;
        while ( (unsigned int)UFG::qStringCompareInsensitive(*v81, v80, -1) )
        {
          ++v81;
          ++v3;
          if ( (signed __int64)v81 >= (signed __int64)UFG::FormationMovementDirectionNames )
            return;
        }
        v6->m_FormationFacingType = v3;
      }
    }
  }
}

// File Line: 425
// RVA: 0x378A90
void __fastcall UFG::FormationManagerComponent::OnAttach(UFG::FormationManagerComponent *this, UFG::SimObject *object)
{
  UFG::FormationManagerComponent *v2; // rdi
  UFG::SimObject *v3; // rbx
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *v19; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax

  v2 = this;
  v3 = object;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->m_pTransformNodeComponent,
    object);
  v4 = &v2->m_pAIEntityComponent;
  if ( v2->m_pAIEntityComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v2->m_pAIEntityComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    v2->m_pAIEntityComponent.m_pSimObject = 0i64;
    v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAIEntityComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v2->m_pAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v2->m_pAIEntityComponent.mNext != &v2->m_pAIEntityComponent) )
  {
    v7 = v4->mPrev;
    v8 = v2->m_pAIEntityComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v2->m_pAIEntityComponent.m_Changed = 1;
  v2->m_pAIEntityComponent.m_pSimObject = v3;
  v2->m_pAIEntityComponent.m_TypeUID = UFG::AIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::BindInternal<UFG::SimObject>(v4, v3);
  v9 = &v2->m_pActionTreeComponent;
  if ( v2->m_pActionTreeComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pActionTreeComponent.m_pSimObject = 0i64;
    v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pActionTreeComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->m_pActionTreeComponent.mNext != &v2->m_pActionTreeComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->m_pActionTreeComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pActionTreeComponent.m_Changed = 1;
  v2->m_pActionTreeComponent.m_pSimObject = v3;
  v2->m_pActionTreeComponent.m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    &v2->m_pActionTreeComponent,
    v3);
  v14 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v2->m_pTargetingSystemBaseComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v2->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v2->m_pTargetingSystemBaseComponent.mNext != &v2->m_pTargetingSystemBaseComponent) )
  {
    v17 = v14->mPrev;
    v18 = v2->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pTargetingSystemBaseComponent.m_Changed = 1;
  v2->m_pTargetingSystemBaseComponent.m_pSimObject = v3;
  v2->m_pTargetingSystemBaseComponent.m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(
    &v2->m_pTargetingSystemBaseComponent,
    v3);
  v19 = &v2->m_pAttackRightsComponent;
  if ( v2->m_pAttackRightsComponent.m_pSimComponent )
  {
    v20 = v19->mPrev;
    v21 = v2->m_pAttackRightsComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v2->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->m_pAttackRightsComponent.m_pSimObject = 0i64;
    v2->m_pAttackRightsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAttackRightsComponent.mPrev;
    v19->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v19->mPrev;
    goto LABEL_29;
  }
  if ( v2->m_pAttackRightsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v19->mPrev != v19
     || (UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v2->m_pAttackRightsComponent.mNext != &v2->m_pAttackRightsComponent) )
  {
    v22 = v19->mPrev;
    v23 = v2->m_pAttackRightsComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pAttackRightsComponent.m_Changed = 1;
  v2->m_pAttackRightsComponent.m_pSimObject = v3;
  v2->m_pAttackRightsComponent.m_TypeUID = UFG::AttackRightsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::BindInternal<UFG::SimObject>(
    &v2->m_pAttackRightsComponent,
    v3);
}

// File Line: 434
// RVA: 0x37A4C0
void __fastcall UFG::FormationManagerComponent::OnDetach(UFG::FormationManagerComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v1; // r8
  UFG::FormationManagerComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax

  v1 = &this->m_pTransformNodeComponent;
  v2 = this;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pTransformNodeComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pAIEntityComponent;
  v1->m_Changed = 1;
  if ( v2->m_pAIEntityComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pAIEntityComponent.m_pSimObject = 0i64;
    v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAIEntityComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v2->m_pAIEntityComponent.mNext != &v2->m_pAIEntityComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pAIEntityComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pAIEntityComponent.m_Changed = 1;
  v12 = &v2->m_pActionTreeComponent;
  if ( v2->m_pActionTreeComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pActionTreeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pActionTreeComponent.m_pSimObject = 0i64;
    v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pActionTreeComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->m_pActionTreeComponent.mNext != &v2->m_pActionTreeComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->m_pActionTreeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pActionTreeComponent.m_Changed = 1;
  v17 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v2->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v2->m_pTargetingSystemBaseComponent.mNext != &v2->m_pTargetingSystemBaseComponent) )
  {
    v20 = v17->mPrev;
    v21 = v2->m_pTargetingSystemBaseComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pTargetingSystemBaseComponent.m_Changed = 1;
  v22 = &v2->m_pAttackRightsComponent;
  if ( v2->m_pAttackRightsComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v2->m_pAttackRightsComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v2->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_35:
    v2->m_pAttackRightsComponent.m_pSimObject = 0i64;
    v2->m_pAttackRightsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAttackRightsComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v2->m_pAttackRightsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v2->m_pAttackRightsComponent.mNext != &v2->m_pAttackRightsComponent) )
  {
    v25 = v22->mPrev;
    v26 = v2->m_pAttackRightsComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v2->m_pAttackRightsComponent.m_Changed = 1;
  UFG::FormationManagerComponent::Clear(v2);
}

// File Line: 445
// RVA: 0x349BD0
void UFG::FormationManagerComponent::BeginFrame(void)
{
  int v0; // eax
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v1; // rdx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v2; // rcx

  v0 = 0;
  v1 = UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mNext - 4;
  UFG::FormationManagerComponent::s_TotalFormationManagerComponents = 0;
  if ( (UFG::qList<UFG::FormationManagerComponent,UFG::FormationManagerComponent,1,0> *)&UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mNext[-4] != &UFG::FormationManagerComponent::s_FormationManagerComponentList - 4 )
  {
    do
    {
      v2 = v1[4].mNext;
      HIDWORD(v1[439].mNext) = v0;
      v0 = UFG::FormationManagerComponent::s_TotalFormationManagerComponents++ + 1;
      v1 = v2 - 4;
    }
    while ( &v2[-4] != (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)(&UFG::FormationManagerComponent::s_FormationManagerComponentList - 4) );
  }
}

// File Line: 472
// RVA: 0x3878D0
char __fastcall UFG::FormationManagerComponent::SetNumSlotsPerRange(UFG::FormationManagerComponent *this, int range_index, int num_slots)
{
  int v3; // ebp
  UFG::FormationManagerComponent *v4; // rdi
  __int64 v5; // r14
  signed __int64 v6; // rsi
  UFG::GetInFormationNode **v7; // rbx
  UFG::GetInFormationNode *v8; // rax
  __int64 v9; // rdx
  __int64 v10; // r8

  v3 = num_slots;
  v4 = this;
  if ( num_slots > 8 )
    return 0;
  v5 = range_index;
  v6 = 8i64;
  v7 = &this->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer + 200 * range_index;
  do
  {
    v8 = *v7;
    if ( *v7 )
    {
      v9 = v8->m_RangeIndex;
      v10 = v8->m_SlotIndex;
      if ( (_DWORD)v9 != -1
        && (_DWORD)v10 != -1
        && v4->mStateVariables.m_FormationSlot[0][v10 + 8 * v9].m_pMember.m_pPointer == v8 )
      {
        UFG::FormationManagerComponent::Unregister(v4, v9, v10);
      }
    }
    v7 += 25;
    --v6;
  }
  while ( v6 );
  v4->m_NumSlotsPerRange[v5] = v3;
  v4->m_PrevNumSlotsPerRange[v5] = v3;
  v4->m_NumFreeSlotsPerRange[v5] = v3;
  return 1;
}

// File Line: 518
// RVA: 0x38F230
void __fastcall UFG::FormationManagerComponent::Update(UFG::FormationManagerComponent *this, float delta_sec)
{
  UFG::FormationManagerComponent *v2; // rdi
  bool v3; // bl
  __int64 v4; // rdx
  __int64 v5; // r8

  v2 = this;
  v3 = UFG::Metrics::msInstance.mSimFrameCount % UFG::FormationManagerComponent::s_TotalFormationManagerComponents == this->mStateVariables.m_MyID;
  UFG::FormationManagerComponent::CheckIfSprinting(this);
  UFG::FormationManagerComponent::DecideCurrentProfile(v2);
  UFG::FormationManagerComponent::UnregisterIncorrectlyRegisteredPeople(v2);
  UFG::FormationManagerComponent::UnregisterDownedPeople(v2);
  UFG::FormationManagerComponent::CountNumFreeSlots(v2);
  UFG::FormationManagerComponent::MaybeSendMeleeFightStimulus(v2);
  UFG::FormationManagerComponent::MaybeSwitchRanges(v2, v4, v5);
  UFG::FormationManagerComponent::UpdateAbsolutePositions(v2);
  UFG::FormationManagerComponent::UpdateDesiredFacing(v2);
  UFG::FormationManagerComponent::CheckIfInDesiredPosition(v2);
  UFG::FormationManagerComponent::MaybeSetDesiredPositionFromProfile(v2);
  UFG::FormationManagerComponent::UpdateDesiredPositionsIfLocked(v2);
  if ( v3 )
  {
    UFG::FormationManagerComponent::UpdateDesiredPositionIfNotInRange(v2);
    UFG::FormationManagerComponent::UpdateDesiredPositionIfNotAtCorrectAngle(v2);
    UFG::FormationManagerComponent::UpdateDesiredPositionIfInsideWall(v2);
    UFG::FormationManagerComponent::SpreadOutDesiredPositions(v2, delta_sec);
    ++v2->mStateVariables.m_ExpensiveUpdateCount;
  }
  UFG::FormationManagerComponent::MaybeShuffleLaterally(v2);
}

// File Line: 562
// RVA: 0x34DCF0
void __fastcall UFG::FormationManagerComponent::CheckIfSprinting(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // eax

  v1 = this;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v2 = _S17_1;
    if ( !(_S17_1 & 1) )
    {
      _S17_1 |= 1u;
      SprintingUID.mUID = UFG::qStringHashUpper32("Sprinting", 0xFFFFFFFF);
      v2 = _S17_1;
    }
    if ( v2 & 2 )
    {
      v3 = mostUsedIndex_Sprinting;
    }
    else
    {
      _S17_1 = v2 | 2;
      v3 = GetMostUsedIndex(SprintingUID.mUID);
      mostUsedIndex_Sprinting = v3;
    }
    v1->mStateVariables.m_CurrentlySprinting = ActionController::IsPlaying(
                                                 (ActionController *)&v1->m_pActionTreeComponent.m_pSimComponent[3],
                                                 &SprintingUID,
                                                 v3,
                                                 1);
  }
}

// File Line: 601
// RVA: 0x351B40
void __fastcall UFG::FormationManagerComponent::DecideCurrentProfile(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rsi
  int v2; // edi
  int v3; // eax
  ActionID *v4; // rbx

  v1 = this;
  if ( !(_S12_1 & 1) )
    _S12_1 |= 1u;
  this->mStateVariables.m_pCurrentProfile = (UFG::FormationProfile *)&dword_1423C1AC0;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v2 = 0;
    v3 = UFG::FormationManagerComponent::s_NumProfiles;
    if ( UFG::FormationManagerComponent::s_NumProfiles > 0 )
    {
      v4 = &UFG::FormationManagerComponent::s_Profiles;
      do
      {
        if ( v4->mUID )
        {
          if ( ActionController::IsPlaying(
                 (ActionController *)&v1->m_pActionTreeComponent.m_pSimComponent[3],
                 v4,
                 0xFFFFFFFF,
                 1) )
          {
            v1->mStateVariables.m_pCurrentProfile = (UFG::FormationProfile *)v4;
            return;
          }
          v3 = UFG::FormationManagerComponent::s_NumProfiles;
        }
        ++v2;
        v4 += 29;
      }
      while ( v2 < v3 );
    }
  }
}

// File Line: 623
// RVA: 0x38AA30
void __fastcall UFG::FormationManagerComponent::UnregisterIncorrectlyRegisteredPeople(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rsi
  int v2; // ebx
  int *v3; // r11
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **v4; // rdi
  int v5; // er10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **v6; // rax
  __int64 v7; // r9
  __int64 v8; // rdx
  _QWORD *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  __int64 *v12; // r8
  __int64 v13; // rdx
  _QWORD *v14; // rcx
  __int64 v15; // r8
  __int64 v16; // r8
  __int64 *v17; // r8
  __int64 v18; // rdx
  _QWORD *v19; // rcx

  v1 = this;
  v2 = 0;
  if ( this->m_NumRanges > 0 )
  {
    v3 = this->m_NumFreeSlotsPerRange;
    v4 = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.mNext;
    do
    {
      v5 = 0;
      if ( *(v3 - 8) > 0 )
      {
        v6 = v4;
        do
        {
          v7 = (__int64)*(v6 - 2);
          if ( v7 && (*(_DWORD *)(v7 + 40) != v2 || *(_DWORD *)(v7 + 44) != v5) )
          {
            if ( v7 )
            {
              v8 = (__int64)*(v6 - 4);
              v9 = *(v6 - 3);
              *(_QWORD *)(v8 + 8) = v9;
              *v9 = v8;
              *(v6 - 4) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v6 - 4);
              *(v6 - 3) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v6 - 4);
            }
            *(v6 - 2) = 0i64;
            if ( v6[1] )
            {
              v10 = *(v6 - 1);
              v11 = *v6;
              v10->mNext = *v6;
              v11->mPrev = v10;
              *(v6 - 1) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v6 - 1);
              *v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v6 - 1);
            }
            v6[1] = 0i64;
            if ( v7 )
            {
              v12 = (__int64 *)(v7 + 64);
              *(_QWORD *)(v7 + 40) = -1i64;
              if ( *(_QWORD *)(v7 + 80) )
              {
                v13 = *v12;
                v14 = *(_QWORD **)(v7 + 72);
                *(_QWORD *)(v13 + 8) = v14;
                *v14 = v13;
                *v12 = (__int64)v12;
                *(_QWORD *)(v7 + 72) = v7 + 64;
              }
              *(_QWORD *)(v7 + 80) = 0i64;
              v15 = *(_QWORD *)(v7 + 104);
              if ( v15 )
                v16 = *(_QWORD *)(v15 + 128);
              else
                v16 = 0i64;
              v17 = (__int64 *)(v16 + 1656);
              if ( v17[2] )
              {
                v18 = *v17;
                v19 = (_QWORD *)v17[1];
                *(_QWORD *)(v18 + 8) = v19;
                *v19 = v18;
                *v17 = (__int64)v17;
                v17[1] = (__int64)v17;
              }
              v17[2] = 0i64;
              ++*v3;
            }
          }
          ++v5;
          v6 += 25;
        }
        while ( v5 < *(v3 - 8) );
      }
      ++v2;
      v4 += 200;
      ++v3;
    }
    while ( v2 < v1->m_NumRanges );
  }
}

// File Line: 649
// RVA: 0x38A4A0
void __fastcall UFG::FormationManagerComponent::UnregisterDownedPeople(UFG::FormationManagerComponent *this)
{
  int v1; // er14
  UFG::FormationManagerComponent *v2; // rsi
  int *v3; // rbp
  UFG::GetInFormationNode **v4; // r15
  int v5; // edi
  UFG::GetInFormationNode **v6; // rbx
  UFG::SimObject *v7; // rcx
  UFG::SimComponent *v8; // rax
  bool v9; // r8
  UFG::SimObject *v10; // rcx
  bool v11; // dl
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v12; // rcx
  bool v13; // al
  UFG::GetInFormationNode *v14; // r10
  __int64 v15; // rdx
  __int64 v16; // r8

  v1 = 0;
  v2 = this;
  if ( this->m_NumRanges > 0 )
  {
    v3 = this->m_NumSlotsPerRange;
    v4 = &this->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer;
    do
    {
      v5 = 0;
      if ( *v3 > 0 )
      {
        v6 = v4;
        do
        {
          v7 = (UFG::SimObject *)v6[3];
          if ( v7 )
          {
            v8 = UFG::SimObject::GetComponentOfType(v7, UFG::ActiveAIEntityComponent::_TypeUID);
            v9 = v8 && (v8->m_Flags & 3) == 1;
            v11 = 0;
            if ( v8 )
            {
              v10 = v8[6].m_pSimObject;
              if ( v10 )
              {
                if ( !BYTE4(v10->m_UnboundComponentHandles.mNode.mPrev) )
                  v11 = 1;
              }
            }
            v13 = 0;
            if ( v8 )
            {
              v12 = v8[30].vfptr;
              if ( v12 )
              {
                if ( (UFG::FormationManagerComponent *)v12[1216].__vecDelDtor == v2 )
                  v13 = 1;
              }
            }
            if ( !v9 || !v11 || !v13 )
            {
              v14 = *v6;
              if ( *v6 )
              {
                v15 = v14->m_RangeIndex;
                v16 = v14->m_SlotIndex;
                if ( (_DWORD)v15 != -1
                  && (_DWORD)v16 != -1
                  && v2->mStateVariables.m_FormationSlot[0][v16 + 8 * v15].m_pMember.m_pPointer == v14 )
                {
                  UFG::FormationManagerComponent::Unregister(v2, v15, v16);
                }
              }
            }
          }
          ++v5;
          v6 += 25;
        }
        while ( v5 < *v3 );
      }
      ++v1;
      ++v3;
      v4 += 200;
    }
    while ( v1 < v2->m_NumRanges );
  }
}

// File Line: 668
// RVA: 0x350890
void __fastcall UFG::FormationManagerComponent::CountNumFreeSlots(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // r11
  int v2; // er9
  UFG::SimObject **v3; // r10
  int *v4; // rdx
  __int64 v5; // r8
  int v6; // ecx
  UFG::SimObject **v7; // rax

  v1 = this;
  v2 = 0;
  if ( this->m_NumRanges > 0 )
  {
    v3 = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
    v4 = this->m_NumSlotsPerRange;
    do
    {
      v5 = (unsigned int)*v4;
      v6 = 0;
      v4[8] = 0;
      if ( (signed int)v5 > 0 )
      {
        v7 = v3;
        do
        {
          if ( !*v7 )
            v4[8] = ++v6;
          v7 += 25;
          --v5;
        }
        while ( v5 );
      }
      ++v2;
      ++v4;
      v3 += 200;
    }
    while ( v2 < v1->m_NumRanges );
  }
}

// File Line: 689
// RVA: 0x375170
void __fastcall UFG::FormationManagerComponent::MaybeSendMeleeFightStimulus(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // r15
  int v2; // ecx
  char v3; // r9
  int v4; // er8
  int *v5; // rdx
  char v6; // bl
  char v7; // r12
  UFG::TransformNodeComponent *v8; // rdi
  float v9; // xmm6_4
  int v10; // er13
  signed __int64 v11; // rax
  int *v12; // r14
  int v13; // ebp
  UFG::SimObject **v14; // rsi
  UFG::SimObject *v15; // rbx
  UFG::TransformNodeComponent *v16; // rdi
  __m128 v17; // xmm1
  UFG::SimComponent *v18; // rax
  UFG::SimObjectCharacter *v19; // rdi
  UFG::StimulusManager *v20; // rbx
  UFG::SimObject *v21; // rsi
  UFG::StimulusManager *v22; // rbp
  UFG::SimComponent *v23; // rbx
  UFG::TransformNodeComponent *v24; // rdi
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-68h]
  char v26; // [rsp+A0h] [rbp+8h]
  signed __int64 v27; // [rsp+A8h] [rbp+10h]
  UFG::TransformNodeComponent *v28; // [rsp+B0h] [rbp+18h]

  v1 = this;
  v2 = this->m_NumRanges;
  v3 = 0;
  v4 = 0;
  if ( v2 > 0 )
  {
    v5 = v1->m_NumSlotsPerRange;
    while ( v5[8] == *v5 )
    {
      ++v4;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_7;
    }
    v3 = 1;
  }
LABEL_7:
  v6 = 0;
  v7 = 0;
  v26 = 0;
  if ( !v3 )
    goto LABEL_32;
  v8 = (UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent;
  v28 = v8;
  if ( !v8 )
    goto LABEL_32;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v9 = FLOAT_10_0;
  if ( v1->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus
    || v1->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus )
  {
    v9 = FLOAT_15_0;
  }
  v10 = 0;
  if ( v1->m_NumRanges <= 0 )
    goto LABEL_32;
  v11 = (signed __int64)&v1->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  v12 = v1->m_NumSlotsPerRange;
  v27 = (signed __int64)&v1->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  while ( 1 )
  {
    v13 = 0;
    if ( *v12 > 0 )
      break;
LABEL_27:
    v11 += 1600i64;
    ++v10;
    ++v12;
    v27 = v11;
    if ( v10 >= v1->m_NumRanges )
    {
      v6 = 0;
      goto $done_1;
    }
  }
  v14 = (UFG::SimObject **)v11;
  while ( 1 )
  {
    v15 = *v14;
    if ( *v14 )
      v16 = v15->m_pTransformNodeComponent;
    else
      v16 = 0i64;
    if ( !v15 )
      goto LABEL_25;
    if ( !v16 )
      goto LABEL_25;
    UFG::TransformNodeComponent::UpdateWorldTransform(v16);
    v17 = (__m128)LODWORD(v16->mWorldTransform.v3.y);
    v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] - v28->mWorldTransform.v3.y)
                            * (float)(v17.m128_f32[0] - v28->mWorldTransform.v3.y))
                    + (float)((float)(v16->mWorldTransform.v3.x - v28->mWorldTransform.v3.x)
                            * (float)(v16->mWorldTransform.v3.x - v28->mWorldTransform.v3.x));
    if ( COERCE_FLOAT(_mm_sqrt_ps(v17)) > v9 )
      goto LABEL_25;
    v18 = UFG::SimObject::GetComponentOfType(v15, UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    if ( !v18 )
      goto LABEL_25;
    if ( LODWORD(v18[3].m_SafePointerList.mNode.mPrev) != 17 )
      break;
    v7 = 1;
LABEL_25:
    ++v13;
    v14 += 25;
    if ( v13 >= *v12 )
    {
      v11 = v27;
      goto LABEL_27;
    }
  }
  v6 = 1;
  v26 = 1;
$done_1:
  if ( !v7 )
  {
LABEL_32:
    if ( v1->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus )
    {
      UFG::StimulusManager::EndStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_MELEE_FIGHT_VS_INNOCENT,
        v1->m_pSimObject);
      v1->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus = 0;
    }
    goto LABEL_34;
  }
  if ( v6 )
  {
    v6 = 1;
    goto LABEL_32;
  }
  if ( !v1->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus )
  {
    v21 = v1->m_pSimObject;
    v22 = UFG::StimulusManager::s_pInstance;
    stimulus_parameters.m_MaxStimulusDuration = -1.0;
    stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_StimulusEmissionType = 1;
    if ( v21 )
    {
      v23 = UFG::SimObject::GetComponentOfType(v21, UFG::StimulusEmitterComponent::_TypeUID);
      if ( v23 )
      {
        do
        {
          v24 = UFG::SimObject::GetComponentOfType(
                  v23->m_pSimObject,
                  UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
                  0,
                  v23);
          if ( LODWORD(v23[1].m_SafePointerList.mNode.mNext) == 10
            && BYTE4(v23[6].m_BoundComponentHandles.mNode.mPrev)
            && !LODWORD(v23[7].m_pSimObject) )
          {
            UFG::Simulation::DestroySimComponent(&UFG::gSim, v23);
          }
          v23 = (UFG::SimComponent *)&v24->vfptr;
        }
        while ( v24 );
      }
      v6 = v26;
    }
    UFG::StimulusManager::AttachStimulusEmitterComponent(v22, &stru_1423BFC70, &stimulus_parameters, v21, 0);
    v1->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus = 1;
  }
LABEL_34:
  v19 = (UFG::SimObjectCharacter *)v1->m_pSimObject;
  if ( v19 != LocalPlayer )
  {
    if ( v6 )
    {
      if ( !v1->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus )
      {
        v20 = UFG::StimulusManager::s_pInstance;
        stimulus_parameters.m_MaxStimulusDuration = -1.0;
        stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
        stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
        stimulus_parameters.m_StimulusEmissionType = 1;
        UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_MELEE_FIGHT_VS_COMBATANT,
          (UFG::SimObject *)&v19->vfptr,
          0);
        UFG::StimulusManager::AttachStimulusEmitterComponent(
          v20,
          &stru_1423BFC28,
          &stimulus_parameters,
          (UFG::SimObject *)&v19->vfptr,
          0);
        v1->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus = 1;
      }
    }
    else if ( v1->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus )
    {
      UFG::StimulusManager::EndStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_MELEE_FIGHT_VS_COMBATANT,
        (UFG::SimObject *)&v19->vfptr);
      v1->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus = 0;
    }
  }
}

// File Line: 884
// RVA: 0x387F20
void __fastcall UFG::FormationManagerComponent::SetTimeToDoSomething(UFG::FormationManagerComponent *this, float min_time, float max_time, float *next_time)
{
  float *v4; // rbx
  float v5; // xmm8_4
  float v6; // xmm0_4

  v4 = next_time;
  v5 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( min_time < 0.0 || max_time <= 0.0 )
  {
    *next_time = -1.0;
  }
  else
  {
    v6 = max_time;
    if ( max_time > min_time )
    {
      v6 = UFG::qRandom(max_time - min_time, &UFG::qDefaultSeed) + min_time;
      if ( v6 <= min_time )
        v6 = min_time;
      if ( v6 >= max_time )
        v6 = max_time;
    }
    *v4 = v6 + v5;
  }
}

// File Line: 1098
// RVA: 0x3770B0
void __fastcall UFG::FormationManagerComponent::MaybeSwitchRanges(UFG::FormationManagerComponent *this, __int64 a2, __int64 a3)
{
  float v3; // xmm10_4
  UFG::FormationManagerComponent *v4; // rbx
  __int64 v5; // rbp
  int v6; // er15
  UFG::HasAttackRequestNode *v7; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v8; // rax
  UFG::GetInFormationNode *v9; // rdi
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rcx
  int v13; // er14
  UFG::GetInFormationNode *v14; // rsi
  __int64 v15; // r9
  __int64 v16; // r8
  __int64 v17; // r9
  __int64 v18; // r8
  int v19; // er8
  __int64 v20; // rdx
  __int64 v21; // r8
  int v22; // er15
  signed __int64 v23; // r12
  signed __int64 v24; // r13
  signed __int64 v25; // r14
  float v26; // xmm0_4
  int v27; // ecx
  int v28; // edi
  int v29; // esi
  int v30; // eax
  int v31; // edx
  int v32; // ebp
  int v33; // eax
  signed __int64 v34; // rdx
  int v35; // ecx
  int v36; // ecx
  signed __int64 v37; // r8
  _QWORD *v38; // rax
  int v39; // edx
  signed __int64 v40; // rcx
  signed __int64 v41; // r9
  _QWORD *v42; // rax
  UFG::GetInFormationNode *v43; // rsi
  UFG::GetInFormationNode *v44; // rdi
  __int64 v45; // rdx
  __int64 v46; // r8
  __int64 v47; // rdx
  __int64 v48; // r8
  float v49; // xmm8_4
  signed __int64 v50; // rcx
  float v51; // xmm7_4
  float v52; // xmm6_4
  float v53; // xmm0_4
  int range_index; // [rsp+B0h] [rbp+8h]
  int slot_index; // [rsp+B8h] [rbp+10h]

  v3 = UFG::Metrics::msInstance.mSimTime_Temp;
  v4 = this;
  if ( !this->mStateVariables.m_RangeSwitchesFrozen )
  {
    if ( this->m_pAttackRightsComponent.m_pSimComponent )
    {
      v5 = 0i64;
      v6 = 0;
      if ( this->m_NumSlotsPerRange[0] > 0 )
      {
        do
        {
          v7 = 0i64;
          if ( v5 )
          {
            if ( v5 != 1 )
              goto LABEL_9;
            v8 = UFG::AttackRightsComponent::GetNextAttacker(
                   (UFG::AttackRightsComponent *)v4->m_pAttackRightsComponent.m_pSimComponent,
                   0,
                   a3);
          }
          else
          {
            v8 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)UFG::AttackRightsComponent::GetCurrentAttacker(
                                                                   (UFG::AttackRightsComponent *)v4->m_pAttackRightsComponent.m_pSimComponent,
                                                                   0);
          }
          v7 = (UFG::HasAttackRequestNode *)v8;
LABEL_9:
          v9 = v4->mStateVariables.m_FormationSlot[0][v5].m_pMember.m_pPointer;
          if ( v7 )
          {
            if ( v9 )
            {
              v10 = v7->m_pOwner.m_pPointer;
              if ( v10 )
                a3 = (__int64)v10->m_pSimObject;
              else
                a3 = 0i64;
              v11 = v9->m_pOwner.m_pPointer;
              if ( v11 )
                v12 = v11->m_pSimObject;
              else
                v12 = 0i64;
              if ( (UFG::SimObject *)a3 == v12 )
                goto LABEL_37;
              range_index = -1;
              slot_index = -1;
              if ( !UFG::FormationManagerComponent::FindRangeAndSlotIndex(v4, v7, &range_index, &slot_index) )
                goto LABEL_37;
              v13 = range_index;
              v14 = v4->mStateVariables.m_FormationSlot[0][slot_index + 8i64 * range_index].m_pMember.m_pPointer;
              if ( v14 )
              {
                v15 = v14->m_RangeIndex;
                v16 = v14->m_SlotIndex;
                if ( (_DWORD)v15 != -1
                  && (_DWORD)v16 != -1
                  && v4->mStateVariables.m_FormationSlot[0][v16 + 8 * v15].m_pMember.m_pPointer == v14 )
                {
                  UFG::FormationManagerComponent::Unregister(v4, v15, v16);
                }
              }
              v17 = v9->m_RangeIndex;
              v18 = v9->m_SlotIndex;
              if ( (_DWORD)v17 != -1
                && (_DWORD)v18 != -1
                && v4->mStateVariables.m_FormationSlot[0][v18 + 8 * v17].m_pMember.m_pPointer == v9 )
              {
                UFG::FormationManagerComponent::Unregister(v4, v17, v18);
              }
              UFG::FormationManagerComponent::Register(v4, v14, 0, 1);
              v19 = v13;
              goto LABEL_36;
            }
            range_index = -1;
            slot_index = -1;
            if ( UFG::FormationManagerComponent::FindRangeAndSlotIndex(v4, v7, &range_index, &slot_index) )
            {
              v9 = v4->mStateVariables.m_FormationSlot[0][slot_index + 8i64 * range_index].m_pMember.m_pPointer;
              if ( v9 )
              {
                v20 = v9->m_RangeIndex;
                v21 = v9->m_SlotIndex;
                if ( (_DWORD)v20 != -1
                  && (_DWORD)v21 != -1
                  && v4->mStateVariables.m_FormationSlot[0][v21 + 8 * v20].m_pMember.m_pPointer == v9 )
                {
                  UFG::FormationManagerComponent::Unregister(v4, v20, v21);
                }
              }
              v19 = 0;
LABEL_36:
              UFG::FormationManagerComponent::Register(v4, v9, v19, 1);
              goto LABEL_37;
            }
          }
LABEL_37:
          ++v6;
          ++v5;
        }
        while ( v6 < v4->m_NumSlotsPerRange[0] );
      }
    }
  }
  v22 = 1;
  v23 = 1i64;
  if ( v4->m_NumRanges - 1 > 1 )
  {
    v24 = (signed __int64)&v4->mStateVariables.m_FormationSlot[1][0].m_pMemberSimObject.m_pPointer;
    v25 = (signed __int64)&v4->m_NumSlotsPerRange[2];
    *(_QWORD *)&range_index = -332i64 - (_QWORD)v4;
    do
    {
      v26 = *(float *)(v25 + 264);
      if ( v26 > 0.0 && v3 >= v26 )
      {
        v27 = *(_DWORD *)(v25 - 4) - *(_DWORD *)(v25 + 28);
        v28 = *(_DWORD *)v25 - *(_DWORD *)(v25 + 32);
        if ( v27 > 0 && v28 > 0 )
        {
          v29 = v27 - 1;
          v30 = UFG::qRandom(v27, &UFG::qDefaultSeed);
          v31 = 0;
          v32 = v28 - 1;
          if ( v30 > 0 )
            v31 = v30;
          if ( v31 < v29 )
            v29 = v31;
          v33 = UFG::qRandom(v28, &UFG::qDefaultSeed);
          v34 = *(signed int *)(v25 - 4);
          v35 = 0;
          if ( v33 > 0 )
            v35 = v33;
          if ( v35 < v32 )
            v32 = v35;
          v36 = 0;
          v37 = 0i64;
          if ( v34 > 0 )
          {
            v38 = (_QWORD *)v24;
            do
            {
              if ( *v38 )
              {
                if ( v36 == v29 )
                  goto LABEL_59;
                ++v36;
              }
              ++v37;
              v38 += 25;
            }
            while ( v37 < v34 );
          }
          v37 = -1i64;
LABEL_59:
          v39 = 0;
          v40 = 0i64;
          v41 = *(int *)((char *)v4->m_NumSlotsPerRange + v25 + *(_QWORD *)&range_index);
          if ( v41 > 0 )
          {
            v42 = (_QWORD *)(v24 + 1600);
            do
            {
              if ( *v42 )
              {
                if ( v39 == v32 )
                  goto LABEL_66;
                ++v39;
              }
              ++v40;
              v42 += 25;
            }
            while ( v40 < v41 );
          }
          v40 = -1i64;
LABEL_66:
          v43 = v4->mStateVariables.m_FormationSlot[0][v37 + 8 * v23].m_pMember.m_pPointer;
          v44 = v4->mStateVariables.m_FormationSlot[1][v40 + 8 * v23].m_pMember.m_pPointer;
          if ( v43 )
          {
            v45 = v43->m_RangeIndex;
            v46 = v43->m_SlotIndex;
            if ( (_DWORD)v45 != -1
              && (_DWORD)v46 != -1
              && v4->mStateVariables.m_FormationSlot[0][v46 + 8 * v45].m_pMember.m_pPointer == v43 )
            {
              UFG::FormationManagerComponent::Unregister(v4, v45, v46);
            }
          }
          if ( v44 )
          {
            v47 = v44->m_RangeIndex;
            v48 = v44->m_SlotIndex;
            if ( (_DWORD)v47 != -1
              && (_DWORD)v48 != -1
              && v4->mStateVariables.m_FormationSlot[0][v48 + 8 * v47].m_pMember.m_pPointer == v44 )
            {
              UFG::FormationManagerComponent::Unregister(v4, v47, v48);
            }
          }
          UFG::FormationManagerComponent::Register(v4, v43, v22 + 1, 1);
          UFG::FormationManagerComponent::Register(v4, v44, v22, 1);
        }
        v49 = UFG::Metrics::msInstance.mSimTime_Temp;
        v50 = v23 + 12i64 * (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
        v51 = v4->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[v50];
        v52 = v4->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[v50];
        if ( v51 < 0.0 || v52 <= 0.0 )
        {
          *(_DWORD *)(v25 + 264) = -1082130432;
        }
        else
        {
          v53 = v4->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[v50];
          if ( v52 > v51 )
          {
            v53 = UFG::qRandom(v52 - v51, &UFG::qDefaultSeed) + v51;
            if ( v53 <= v51 )
              v53 = v51;
            if ( v53 >= v52 )
              v53 = v52;
          }
          *(float *)(v25 + 264) = v53 + v49;
        }
      }
      ++v22;
      ++v23;
      v25 += 4i64;
      v24 += 1600i64;
    }
    while ( v22 < v4->m_NumRanges - 1 );
  }
}

// File Line: 1243
// RVA: 0x377710
char __fastcall UFG::FormationManagerComponent::NewAngleDoesntCrossOverSomeone(UFG::FormationManagerComponent *this, int range_index, int slot_index, unsigned __int16 new_angle)
{
  __int64 v4; // r14
  __int64 v5; // rsi
  char *v6; // r15
  int v7; // ebp
  unsigned __int16 v8; // r12
  unsigned __int16 v9; // r13
  unsigned __int16 *v10; // rbx
  __int16 v11; // di
  __int16 v12; // ax

  v4 = slot_index;
  v5 = 0i64;
  v6 = (char *)this + 4 * range_index;
  v7 = 0;
  v8 = new_angle;
  v9 = this->mStateVariables.m_FormationSlot[0][slot_index + 8i64 * range_index].m_Angle;
  if ( *((_DWORD *)v6 + 83) <= 0 )
    return 1;
  v10 = &this->mStateVariables.m_FormationSlot[range_index][0].m_Angle;
  while ( 1 )
  {
    if ( v5 != v4 )
    {
      if ( *(_QWORD *)(v10 + 38) )
      {
        v11 = UFG::qAngleDiff(v9, *v10);
        v12 = UFG::qAngleDiff(v8, *v10);
        if ( v11 > 0 != v12 > 0 || !v12 )
          break;
      }
    }
    ++v7;
    ++v5;
    v10 += 100;
    if ( v7 >= *((_DWORD *)v6 + 83) )
      return 1;
  }
  return 0;
}

// File Line: 1311
// RVA: 0x376570
void __fastcall UFG::FormationManagerComponent::MaybeShuffleLaterally(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rbx
  __int64 v2; // rax
  float v3; // xmm1_4
  int v4; // er13
  __int64 v5; // rcx
  bool v6; // r15
  signed __int64 v7; // rdi
  bool v8; // si
  UFG::SimObject *v9; // r14
  bool v10; // r9
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rcx
  UFG::GetInFormationNode *v13; // rax
  UFG::SimComponent *v14; // rdx
  char v15; // r8
  __int64 v16; // rdx
  bool v17; // zf
  char v18; // al
  unsigned __int16 v19; // r14
  int v20; // esi
  signed int v21; // er12
  float v22; // xmm0_4
  bool v23; // r15
  signed int v24; // er10
  bool v25; // cl
  int v26; // ecx
  int v27; // er8
  int v28; // edx
  unsigned __int16 v29; // r12
  signed int v30; // eax
  unsigned __int16 v31; // r12
  float v32; // xmm8_4
  float v33; // xmm7_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm9_4
  float v37; // xmm8_4
  float v38; // xmm7_4
  UFG::GetInFormationNode *v39; // r15
  UFG::SimComponent *v40; // rax
  UFG::SimObject *v41; // r14
  UFG::SimComponent *v42; // rax
  UFG::TransformNodeComponent *v43; // rsi
  UFG::SimComponent *v44; // r13
  UFG::eAttackType v45; // er12
  UFG::CombatRegion *v46; // rcx
  float v47; // xmm4_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  bool v54; // sf
  unsigned __int8 v55; // of
  UFG::SimObject *v56; // rcx
  UFG::SimComponent *v57; // rax
  bool v58; // r14
  UFG::SimComponent *v59; // rax
  UFG::SimComponent *v60; // r15
  UFG::SimObject *v61; // rcx
  __m128 v62; // xmm2
  float v63; // xmm1_4
  float v64; // xmm3_4
  float v65; // xmm0_4
  bool v66; // al
  float v67; // xmm5_4
  float v68; // xmm6_4
  float v69; // xmm2_4
  float v70; // xmm3_4
  float v71; // xmm4_4
  float v72; // xmm0_4
  UFG::SimObject *v73; // rcx
  UFG::SimComponent *v74; // rax
  bool v75; // al
  bool v76; // al
  float v77; // xmm4_4
  float v78; // xmm5_4
  float v79; // xmm6_4
  float v80; // xmm2_4
  float v81; // xmm3_4
  UFG::eFormationFacingType v82; // eax
  bool v83; // [rsp+40h] [rbp-C0h]
  int range_index; // [rsp+44h] [rbp-BCh]
  signed __int16 v85; // [rsp+48h] [rbp-B8h]
  unsigned __int16 v86; // [rsp+4Ch] [rbp-B4h]
  UFG::qVector3 last_valid_position; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 vPoint; // [rsp+60h] [rbp-A0h]
  int v89; // [rsp+70h] [rbp-90h]
  int slot_index; // [rsp+74h] [rbp-8Ch]
  int v91; // [rsp+78h] [rbp-88h]
  float v92; // [rsp+7Ch] [rbp-84h]
  int v93; // [rsp+80h] [rbp-80h]
  int v94; // [rsp+84h] [rbp-7Ch]
  int v95; // [rsp+88h] [rbp-78h]
  int v96; // [rsp+8Ch] [rbp-74h]
  __int64 v97; // [rsp+90h] [rbp-70h]
  UFG::qVector3 from_position; // [rsp+98h] [rbp-68h]
  UFG::qVector3 to_position; // [rsp+A8h] [rbp-58h]
  __int64 v100; // [rsp+B8h] [rbp-48h]
  __int64 v101; // [rsp+C0h] [rbp-40h]
  __int64 v102; // [rsp+C8h] [rbp-38h]
  UFG::SimObject *ray_hit_object; // [rsp+D0h] [rbp-30h]
  UFG::TransformNodeComponent *v104; // [rsp+D8h] [rbp-28h]
  bool v105; // [rsp+1D0h] [rbp+D0h]
  char v106; // [rsp+1D8h] [rbp+D8h]
  bool v107; // [rsp+1E0h] [rbp+E0h]
  bool v108; // [rsp+1E8h] [rbp+E8h]

  v1 = this;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v104 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v104);
    v2 = 0i64;
    v3 = UFG::Metrics::msInstance.mSimTime_Temp;
    v92 = UFG::Metrics::msInstance.mSimTime_Temp;
    v4 = 0;
    v97 = 0i64;
    range_index = 0;
    while ( v4 < v1->m_NumRanges )
    {
      v5 = 0i64;
      slot_index = 0;
      v102 = 0i64;
      if ( v1->m_NumSlotsPerRange[v2] <= 0 )
        goto LABEL_65;
      do
      {
        v6 = 0;
        v7 = v5 + 8 * v2;
        v8 = v1->mStateVariables.m_FormationSlot[0][v7].m_InPosition == eIN_POSITION
          && v3 > v1->mStateVariables.m_FormationSlot[0][v7].m_NextTimeToChangePosition;
        v9 = v1->mStateVariables.m_FormationSlot[0][v7].m_pMemberSimObject.m_pPointer;
        v10 = v1->mStateVariables.m_FormationSlot[0][v7].m_RequestedToChangePosition;
        v105 = v1->mStateVariables.m_FormationSlot[0][v7].m_RequestedToChangePosition;
        if ( v9 )
        {
          v11 = UFG::SimObject::GetComponentOfType(v9, UFG::ActiveAIEntityComponent::_TypeUID);
          v10 = v105;
          v12 = v11;
        }
        else
        {
          v12 = 0i64;
        }
        v13 = v1->mStateVariables.m_FormationSlot[0][v7].m_pMember.m_pPointer;
        if ( v12 && v13 )
        {
          v14 = v13->m_pOwner.m_pPointer;
          if ( v14 )
            v15 = v14[1].m_Flags;
          else
            v15 = 0;
          v16 = SHIDWORD(v12[65].vfptr);
          v6 = v15 == 0;
          if ( v13->m_AttackType )
          {
            if ( v8 )
            {
              v17 = UFG::g_AIObjectiveParams[v16].m_CircleAroundTargetWhenRanged == 0;
              goto LABEL_21;
            }
          }
          else if ( v8 )
          {
            v17 = UFG::g_AIObjectiveParams[v16].m_CircleAroundTargetWhenMelee == 0;
LABEL_21:
            if ( !v17 )
            {
              v8 = 1;
              goto LABEL_24;
            }
          }
          v8 = 0;
        }
LABEL_24:
        if ( !v9 || !v6 || !v8 && !v10 )
          goto LABEL_64;
        v18 = 0;
        v106 = 0;
        if ( v10 )
        {
          v25 = v1->mStateVariables.m_FormationSlot[0][v7].m_PositionChangeRequest.m_AbsolutePosition;
          v23 = v1->mStateVariables.m_FormationSlot[0][v7].m_PositionChangeRequest.m_Clockwise;
          LOWORD(v20) = 7281;
          v19 = 10922;
          v21 = 5;
          v89 = 7281;
          v83 = v25;
          v108 = 1;
          v24 = 2;
          v85 = 10922;
          v93 = 5;
        }
        else
        {
          v19 = 12743;
          LOWORD(v20) = 9102;
          v21 = 2;
          v89 = 9102;
          v85 = 12743;
          v93 = 2;
          v108 = v4 == 0;
          v22 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
          v18 = 0;
          v10 = v105;
          v23 = v22 < 0.5;
          v83 = 0;
          v24 = 1;
        }
        v26 = 0;
        v94 = v24;
        v107 = v23;
        v91 = 0;
        if ( v24 <= 0 )
          goto LABEL_64;
        do
        {
          if ( v18 )
            break;
          v95 = 0;
          if ( v21 <= 0 )
            goto LABEL_63;
          v27 = v21 - 1;
          v28 = v21 - 1;
          v96 = v21 - 1;
          while ( !v18 )
          {
            v29 = v1->mStateVariables.m_FormationSlot[0][v7].m_Angle;
            if ( v10 )
            {
              v30 = (signed int)(float)((float)((float)((float)((float)((float)((float)((float)v19 * 360.0)
                                                                              * 0.000015258789)
                                                                      - (float)((float)((float)(unsigned __int16)v20
                                                                                      * 360.0)
                                                                              * 0.000015258789))
                                                              * (float)((float)v28 / (float)v27))
                                                      + (float)((float)((float)(unsigned __int16)v20 * 360.0)
                                                              * 0.000015258789))
                                              * 65536.0)
                                      * 0.0027777778);
            }
            else
            {
              LOWORD(v30) = v19;
              v20 = (unsigned __int16)v20;
              if ( v19 > (signed int)(unsigned __int16)v20 )
                v30 = v20 + (unsigned __int64)UFG::qRandom((unsigned int)v19 - v20 + 1, &UFG::qDefaultSeed);
            }
            if ( v23 )
              v31 = v29 - v30;
            else
              v31 = v29 + v30;
            v86 = v31;
            v32 = UFG::qVector3::msZero.z;
            v33 = (float)((float)v31 * 3.1415927) * 0.000030517578;
            v34 = sinf(v33);
            v35 = v1->mStateVariables.m_FormationSlot[0][v7].m_Distance;
            v36 = v34 * v35;
            v37 = v32 * v35;
            v38 = cosf(v33) * v35;
            if ( !v108 && !UFG::FormationManagerComponent::NewAngleDoesntCrossOverSomeone(v1, v4, slot_index, v31) )
            {
              v18 = v106;
              v10 = v105;
              goto LABEL_61;
            }
            v39 = v1->mStateVariables.m_FormationSlot[0][v7].m_pMember.m_pPointer;
            v40 = v39->m_pOwner.m_pPointer;
            if ( !v40 )
            {
              v41 = 0i64;
LABEL_49:
              v44 = 0i64;
              v43 = 0i64;
              goto LABEL_50;
            }
            v41 = v40->m_pSimObject;
            if ( !v41 )
              goto LABEL_49;
            v42 = UFG::SimObject::GetComponentOfType(v40->m_pSimObject, UFG::ActiveAIEntityComponent::_TypeUID);
            v43 = v41->m_pTransformNodeComponent;
            v44 = v42;
LABEL_50:
            if ( v1->m_pAIEntityComponent.m_pSimComponent
              && v1->m_pTransformNodeComponent.m_pSimComponent
              && v41
              && v44
              && v43 )
            {
              v45 = v39->m_AttackType;
              UFG::TransformNodeComponent::UpdateWorldTransform(v43);
              v46 = *(UFG::CombatRegion **)&v44[15].m_TypeUID;
              v47 = v38 + v43->mWorldTransform.v3.x;
              v48 = v36 + v43->mWorldTransform.v3.y;
              v49 = v37 + v43->mWorldTransform.v3.z;
              v50 = v47;
              v51 = v48;
              last_valid_position.x = v38 + v43->mWorldTransform.v3.x;
              last_valid_position.y = v48;
              vPoint.x = v47;
              vPoint.y = v48;
              vPoint.z = v49;
              last_valid_position.z = v49;
              if ( v46 )
              {
                if ( !UFG::CombatRegion::IsHitPoint(v46, &vPoint) )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform(v43);
                  v52 = v43->mWorldTransform.v3.y;
                  last_valid_position.x = v43->mWorldTransform.v3.x;
                  v53 = v43->mWorldTransform.v3.z;
                  last_valid_position.y = v52;
                  last_valid_position.z = v53;
LABEL_58:
                  v4 = range_index;
                  v10 = v105;
                  goto LABEL_59;
                }
                v49 = vPoint.z;
                v48 = vPoint.y;
                v47 = vPoint.x;
                v51 = last_valid_position.y;
                v50 = last_valid_position.x;
              }
              if ( v45 )
              {
                v59 = v39->m_pOwner.m_pPointer;
                if ( v59 && LOBYTE(v59[1].m_Flags) )
                  goto LABEL_109;
                v60 = v1->m_pTransformNodeComponent.m_pSimComponent;
                v61 = 0i64;
                if ( v60 )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
                  v61 = 0i64;
                  v62 = (__m128)HIDWORD(v60[2].m_BoundComponentHandles.mNode.mPrev);
                  v63 = *(float *)&v60[2].m_BoundComponentHandles.mNode.mPrev;
                  v47 = vPoint.x;
                  ray_hit_object = 0i64;
                  v48 = vPoint.y;
                  v64 = *(float *)&v60[2].m_BoundComponentHandles.mNode.mNext;
                  v49 = vPoint.z;
                  v65 = *(float *)&v60[2].m_BoundComponentHandles.mNode.mNext;
                  LODWORD(from_position.y) = v62.m128_i32[0];
                  from_position.x = v63;
                  from_position.z = v64;
                  to_position = vPoint;
                  v62.m128_f32[0] = (float)((float)((float)(v62.m128_f32[0] - vPoint.y)
                                                  * (float)(v62.m128_f32[0] - vPoint.y))
                                          + (float)((float)(v63 - vPoint.x) * (float)(v63 - vPoint.x)))
                                  + (float)((float)(v65 - vPoint.z) * (float)(v65 - vPoint.z));
                  if ( COERCE_FLOAT(_mm_sqrt_ps(v62)) <= 100.0 )
                  {
                    from_position.z = v64 + 1.5;
                    to_position.z = vPoint.z + 1.5;
                    v66 = UFG::DoRaycast(
                            &from_position,
                            &to_position,
                            v41,
                            &last_valid_position,
                            &ray_hit_object,
                            0i64,
                            0,
                            &UFG::qColour::Yellow);
                    v61 = ray_hit_object;
                    v49 = vPoint.z;
                    v48 = vPoint.y;
                    v47 = vPoint.x;
                    v51 = last_valid_position.y;
                    v50 = last_valid_position.x;
                  }
                  else
                  {
                    v51 = last_valid_position.y;
                    v50 = last_valid_position.x;
                    v66 = 0;
                  }
                }
                else
                {
                  v66 = 0;
                }
                if ( v66
                  || !v61
                  && fsqrt(
                       (float)((float)((float)(v51 - v48) * (float)(v51 - v48))
                             + (float)((float)(v50 - v47) * (float)(v50 - v47)))
                     + (float)((float)(last_valid_position.z - v49) * (float)(last_valid_position.z - v49))) < 0.1 )
                {
LABEL_109:
                  v58 = 1;
                }
                else
                {
                  v67 = v43->mWorldTransform.v3.x;
                  v68 = v43->mWorldTransform.v3.y;
                  v58 = 0;
                  v69 = v50 - v67;
                  v70 = v51 - v68;
                  v71 = fsqrt((float)(v70 * v70) + (float)(v69 * v69));
                  if ( v71 > 1.0 )
                  {
                    v72 = (float)(v71 - 1.0) / v71;
                    last_valid_position.z = (float)(v72 * 0.0) + v43->mWorldTransform.v3.z;
                    last_valid_position.x = (float)(v69 * v72) + v67;
                    last_valid_position.y = (float)(v70 * v72) + v68;
                  }
                }
                if ( v45 - 1 > 1 )
                  goto LABEL_87;
                v73 = v44->m_pSimObject;
                if ( v73 )
                  v74 = UFG::SimObject::GetComponentOfType(v73, UFG::NavComponent::_TypeUID);
                else
                  v74 = 0i64;
                v100 = *(__int64 *)((char *)&v74[2].m_BoundComponentHandles.mNode.mNext + 4);
                HIDWORD(v100) |= 0x200u;
                v75 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                        UFG::NavManager::ms_pInstance,
                        (UFG::HavokNavPosition *)&v74[1].m_SafePointerList.mNode.mNext,
                        &vPoint,
                        (UFG::NavParams *)&v100,
                        &last_valid_position);
                if ( !v58 || v75 )
                  goto LABEL_58;
              }
              else
              {
                v56 = v1->m_pAIEntityComponent.m_pSimComponent->m_pSimObject;
                if ( v56 )
                  v57 = UFG::SimObject::GetComponentOfType(v56, UFG::NavComponent::_TypeUID);
                else
                  v57 = 0i64;
                v101 = *(__int64 *)((char *)&v57[2].m_BoundComponentHandles.mNode.mNext + 4);
                HIDWORD(v101) |= 0x200u;
                v58 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                        UFG::NavManager::ms_pInstance,
                        (UFG::HavokNavPosition *)&v57[1].m_SafePointerList.mNode.mNext,
                        &vPoint,
                        (UFG::NavParams *)&v101,
                        &last_valid_position) == 0;
LABEL_87:
                if ( !v58 )
                  goto LABEL_58;
              }
              v31 = v86;
            }
            v10 = v105;
            v4 = range_index;
            if ( !v105
              || (v76 = UFG::FormationManagerComponent::NoOneIsTooCloseToAngle(v1, v31, range_index), v10 = v105, v76) )
            {
              v77 = v38 + v104->mWorldTransform.v3.x;
              v78 = v36 + v104->mWorldTransform.v3.y;
              v79 = v37 + v104->mWorldTransform.v3.z;
              v80 = (float)((float)(v38 * v38) + (float)(v36 * v36)) + (float)(v37 * v37);
              v1->mStateVariables.m_FormationSlot[0][v7].m_Angle = v31;
              v1->mStateVariables.m_FormationSlot[0][v7].m_Direction.x = v38;
              v1->mStateVariables.m_FormationSlot[0][v7].m_Direction.y = v36;
              v1->mStateVariables.m_FormationSlot[0][v7].m_Direction.z = v37;
              if ( v80 == 0.0 )
                v81 = 0.0;
              else
                v81 = 1.0 / fsqrt(v80);
              LODWORD(v1->mStateVariables.m_FormationSlot[0][v7].m_FacingDirection.z) = COERCE_UNSIGNED_INT(v37 * v81) ^ _xmm[0];
              LODWORD(v1->mStateVariables.m_FormationSlot[0][v7].m_FacingDirection.x) = COERCE_UNSIGNED_INT(v81 * v38) ^ _xmm[0];
              LODWORD(v1->mStateVariables.m_FormationSlot[0][v7].m_FacingDirection.y) = COERCE_UNSIGNED_INT(v81 * v36) ^ _xmm[0];
              if ( v83 )
              {
                v1->mStateVariables.m_FormationSlot[0][v7].m_AbsolutePosition.x = v77;
                v1->mStateVariables.m_FormationSlot[0][v7].m_AbsolutePosition.y = v78;
                v1->mStateVariables.m_FormationSlot[0][v7].m_AbsolutePosition.z = v79;
                v1->mStateVariables.m_FormationSlot[0][v7].m_UseAbsolutePosition = 1;
              }
              else
              {
                v1->mStateVariables.m_FormationSlot[0][v7].m_UseAbsolutePosition = 0;
              }
              if ( v10 )
              {
                v1->mStateVariables.m_FormationSlot[0][v7].m_DesiredSpeed = v1->mStateVariables.m_FormationSlot[0][v7].m_PositionChangeRequest.m_DesiredSpeed;
                v82 = v1->mStateVariables.m_FormationSlot[0][v7].m_PositionChangeRequest.m_FacingType;
                v1->mStateVariables.m_FormationSlot[0][v7].m_Fixed = 1;
                v1->mStateVariables.m_FormationSlot[0][v7].m_FacingType = v82;
              }
              v18 = 1;
              v1->mStateVariables.m_FormationSlot[0][v7].m_RequestedToChangePosition = 0;
              v1->mStateVariables.m_FormationSlot[0][v7].m_InPosition = 2;
              v106 = 1;
              goto LABEL_60;
            }
LABEL_59:
            v18 = v106;
LABEL_60:
            v23 = v107;
            v19 = v85;
LABEL_61:
            v21 = v93;
            LOWORD(v20) = v89;
            v28 = v96 - 1;
            ++v95;
            --v96;
            v27 = v93 - 1;
            if ( v95 >= v93 )
              break;
          }
          v26 = v91;
          v24 = v94;
LABEL_63:
          LOWORD(v20) = v89;
          v23 = v23 == 0;
          ++v26;
          v107 = v23;
          v91 = v26;
        }
        while ( v26 < v24 );
LABEL_64:
        v3 = v92;
        v5 = v102 + 1;
        v55 = __OFSUB__(slot_index + 1, v1->m_NumSlotsPerRange[v97]);
        v54 = slot_index++ + 1 - v1->m_NumSlotsPerRange[v97] < 0;
        v2 = v97;
        ++v102;
      }
      while ( v54 ^ v55 );
LABEL_65:
      ++v4;
      ++v2;
      range_index = v4;
      v97 = v2;
    }
  }
});
LABEL_65:
      ++v4;
      ++v2;
      range_index = v4;
      v97 = v2;
    }
  }
}

// File Line: 1445
// RVA: 0x3777F0
char __fastcall UFG::FormationManagerComponent::NoOneIsTooCloseToAngle(UFG::FormationManagerComponent *this, unsigned __int16 angle, int range_index)
{
  int v3; // edi
  char *v4; // rsi
  unsigned __int16 v5; // bp
  unsigned __int16 *v6; // rbx
  unsigned __int16 v7; // ax

  v3 = 0;
  v4 = (char *)this + 4 * range_index;
  v5 = angle;
  if ( *((_DWORD *)v4 + 83) <= 0 )
    return 1;
  v6 = &this->mStateVariables.m_FormationSlot[range_index][0].m_Angle;
  while ( 1 )
  {
    if ( *(_QWORD *)(v6 + 38) )
    {
      v7 = UFG::qAngleDiff(v5, *v6);
      if ( (v7 & 0x8000u) != 0 )
        v7 = -v7;
      if ( (float)((float)((float)v7 * 360.0) * 0.000015258789) < 15.0 )
        break;
    }
    ++v3;
    v6 += 100;
    if ( v3 >= *((_DWORD *)v4 + 83) )
      return 1;
  }
  return 0;
}

// File Line: 1534
// RVA: 0x393F30
void __fastcall UFG::FormationManagerComponent::UpdateAbsolutePositions(UFG::FormationManagerComponent *this)
{
  UFG::SimComponent *v1; // r14
  UFG::FormationManagerComponent *v2; // r13
  int v3; // er15
  int *v4; // rbp
  signed __int64 v5; // r12
  int v6; // esi
  _BYTE *v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rdi
  float v10; // xmm4_4
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  float v13; // xmm1_4

  v1 = this->m_pTransformNodeComponent.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
    v3 = 0;
    if ( v2->m_NumRanges > 0 )
    {
      v4 = v2->m_NumSlotsPerRange;
      v5 = (signed __int64)&v2->mStateVariables.m_FormationSlot[0][0].m_UseAbsolutePosition;
      do
      {
        v6 = 0;
        if ( *v4 > 0 )
        {
          v7 = (_BYTE *)v5;
          do
          {
            v8 = *((_QWORD *)v7 - 1);
            if ( v8 )
              v9 = *(_QWORD *)(v8 + 88);
            else
              v9 = 0i64;
            if ( v8 )
            {
              if ( v9 )
              {
                if ( *v7 )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
                  v11 = (__m128)*(unsigned int *)(v9 + 180);
                  v10 = *(float *)(v9 + 176) - *(float *)&v1[2].m_BoundComponentHandles.mNode.mPrev;
                  v11.m128_f32[0] = v11.m128_f32[0] - *((float *)&v1[2].m_BoundComponentHandles.mNode.mPrev + 1);
                  v12 = v11;
                  v12.m128_f32[0] = (float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10);
                  if ( COERCE_FLOAT(_mm_sqrt_ps(v12)) > 0.001 )
                  {
                    if ( v12.m128_f32[0] == 0.0 )
                      v13 = 0.0;
                    else
                      v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
                    *((float *)v7 - 22) = v13 * 0.0;
                    *((float *)v7 - 24) = v13 * v10;
                    *((float *)v7 - 23) = v13 * v11.m128_f32[0];
                    *((_WORD *)v7 - 42) = (signed int)(float)((float)(atan2f(v11.m128_f32[0], v10) * 32768.0)
                                                            * 0.31830987);
                  }
                }
              }
            }
            ++v6;
            v7 += 200;
          }
          while ( v6 < *v4 );
        }
        ++v3;
        ++v4;
        v5 += 1600i64;
      }
      while ( v3 < v2->m_NumRanges );
    }
  }
}

// File Line: 1578
// RVA: 0x394FD0
void __fastcall UFG::FormationManagerComponent::UpdateDesiredFacing(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rbp
  UFG::TransformNodeComponent *v2; // rcx
  float v3; // xmm7_4
  float v4; // xmm8_4
  UFG::SimComponent *v5; // rbx
  int v6; // er15
  signed __int64 v7; // r12
  int *v8; // r14
  int v9; // esi
  signed __int64 v10; // rbx
  __int64 v11; // rdi
  UFG::TransformNodeComponent *v12; // rdi
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4

  v1 = this;
  v2 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v3 = 0.0;
  v4 = 0.0;
  if ( v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v5 = v1->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
    v3 = *(float *)&v5[2].m_BoundComponentHandles.mNode.mPrev;
    v4 = *((float *)&v5[2].m_BoundComponentHandles.mNode.mPrev + 1);
  }
  v6 = 0;
  if ( v1->m_NumRanges > 0 )
  {
    v7 = (signed __int64)&v1->mStateVariables.m_FormationSlot[0][0].m_FacingDirection.z;
    v8 = v1->m_NumSlotsPerRange;
    do
    {
      v9 = 0;
      if ( *v8 > 0 )
      {
        v10 = v7;
        do
        {
          v11 = *(_QWORD *)(v10 + 60);
          if ( v11 )
          {
            if ( v1->m_FormationFacingType == 1 )
            {
              v12 = *(UFG::TransformNodeComponent **)(v11 + 88);
              if ( v12 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v12);
                v13 = v3 - v12->mWorldTransform.v3.x;
                v14 = v4 - v12->mWorldTransform.v3.y;
                v15 = fsqrt((float)(v14 * v14) + (float)(v13 * v13));
                if ( v15 > 0.001 )
                {
                  *(float *)v10 = (float)(1.0 / v15) * 0.0;
                  *(float *)(v10 - 8) = (float)(1.0 / v15) * v13;
                  *(float *)(v10 - 4) = (float)(1.0 / v15) * v14;
                }
              }
            }
          }
          ++v9;
          v10 += 200i64;
        }
        while ( v9 < *v8 );
      }
      ++v6;
      ++v8;
      v7 += 1600i64;
    }
    while ( v6 < v1->m_NumRanges );
  }
}

// File Line: 1664
// RVA: 0x34D080
void __fastcall UFG::FormationManagerComponent::CheckIfInDesiredPosition(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rbp
  float v2; // xmm15_4
  int v3; // er13
  signed __int64 v4; // rcx
  signed __int64 v5; // r12
  signed __int64 v6; // rsi
  int v7; // er14
  float *v8; // r15
  signed __int64 v9; // rbx
  __int64 v10; // rax
  UFG::TransformNodeComponent *v11; // rdi
  float v12; // xmm1_4
  float v13; // xmm0_4
  __m128 v14; // xmm0
  __int64 v15; // rdx
  float v16; // xmm9_4
  float v17; // xmm12_4
  float v18; // xmm10_4
  float v19; // xmm8_4
  bool v20; // zf
  bool v21; // di
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float max_lateral_offset; // xmm7_4
  float v27; // xmm9_4
  bool v28; // al
  int v29; // edx
  float v30; // xmm0_4
  float v31; // xmm2_4
  bool v32; // r8
  bool v33; // cl
  float v34; // xmm0_4
  bool v35; // al
  bool v36; // al
  UFG::qVector3 current_position; // [rsp+48h] [rbp-110h]
  UFG::qVector3 desired_position; // [rsp+58h] [rbp-100h]
  float current_radial_offset; // [rsp+160h] [rbp+8h]
  float current_lateral_offset; // [rsp+168h] [rbp+10h]
  __int64 v41; // [rsp+170h] [rbp+18h]
  UFG::TransformNodeComponent *v42; // [rsp+178h] [rbp+20h]

  v1 = this;
  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return;
  v2 = UFG::Metrics::msInstance.mSimTime_Temp;
  v42 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v42);
  v3 = 0;
  if ( v1->m_NumRanges <= 0 )
    return;
  v4 = (signed __int64)&v1->mStateVariables.m_FormationSlot[0][0].m_InPosition;
  v5 = -1i64;
  v41 = (__int64)&v1->mStateVariables.m_FormationSlot[0][0].m_InPosition;
  v6 = (signed __int64)v1->m_NumSlotsPerRange;
  do
  {
    v7 = 0;
    if ( *(_DWORD *)v6 <= 0 )
      goto LABEL_66;
    v8 = v1->m_MaxLateralDistanceFromDesiredPosition;
    v9 = v4;
    do
    {
      v10 = *(_QWORD *)(v9 + 56);
      if ( !v10
        || (v11 = *(UFG::TransformNodeComponent **)(v10 + 88)) == 0i64
        || !UFG::FormationManagerComponent::GetDesiredPosition(
              v1,
              *(UFG::GetInFormationNode **)(v9 + 32),
              &desired_position) )
      {
        *(_DWORD *)v9 = 2;
        *(_WORD *)(v9 + 8) = 0;
        goto LABEL_64;
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      v12 = v11->mWorldTransform.v3.y;
      current_position.x = v11->mWorldTransform.v3.x;
      v13 = v11->mWorldTransform.v3.z;
      current_position.y = v12;
      current_position.z = v13;
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      v14 = (__m128)LODWORD(current_position.y);
      v15 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      v16 = *(float *)(v6 + 136);
      v14.m128_f32[0] = (float)((float)(current_position.y - v42->mWorldTransform.v3.y)
                              * (float)(current_position.y - v42->mWorldTransform.v3.y))
                      + (float)((float)(current_position.x - v42->mWorldTransform.v3.x)
                              * (float)(current_position.x - v42->mWorldTransform.v3.x));
      v17 = (float)((float)(v11->mWorldTransform.v0.y * *(float *)(v9 - 8))
                  + (float)(v11->mWorldTransform.v0.x * *(float *)(v9 - 12)))
          + (float)(v11->mWorldTransform.v0.z * *(float *)(v9 - 4));
      LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v14);
      if ( v5 < 0 || (_DWORD)v15 == -1 )
      {
        v19 = 0.0;
      }
      else
      {
        v19 = *(float *)((char *)&v1->mStateVariables.m_pCurrentProfile[-2] + v6 - (_QWORD)v1 - 84);
        if ( v19 < 0.0 )
          v19 = v1->m_BattleTypeSpecificParameters[0].m_MaxDistance[v5 + 12 * v15];
      }
      v20 = *(_DWORD *)v9 == 0;
      current_lateral_offset = 0.0;
      current_radial_offset = 0.0;
      if ( v20 )
      {
        v19 = v19 - 1.0;
        if ( v19 <= 0.0 )
          v19 = 0.0;
      }
      v21 = UFG::TheAIParameters.m_DistanceToBeConsideredNear > v18;
      if ( !*(_BYTE *)(v9 + 10) && UFG::TheAIParameters.m_DistanceToBeConsideredNear > v18 )
      {
        v22 = UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer;
        v23 = UFG::TheAIParameters.m_MinTimeForRangedAttackerToStayNearPlayer;
        v24 = UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer;
        if ( UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer > UFG::TheAIParameters.m_MinTimeForRangedAttackerToStayNearPlayer )
        {
          v24 = UFG::qRandom(
                  UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer
                - UFG::TheAIParameters.m_MinTimeForRangedAttackerToStayNearPlayer,
                  &UFG::qDefaultSeed)
              + v23;
          if ( v24 <= v23 )
            v24 = v23;
          if ( v24 >= v22 )
            v24 = v22;
        }
        *(float *)(v9 + 4) = v24 + v2;
      }
      v25 = *(float *)(v6 + 52);
      max_lateral_offset = *v8;
      if ( !v1->mStateVariables.m_CurrentlySprinting )
      {
        if ( *(_DWORD *)v9 )
        {
          if ( *(_DWORD *)v9 == 3 )
          {
            max_lateral_offset = max_lateral_offset + 4.0;
            v25 = v25 + 2.0;
          }
        }
        else if ( UFG::Metrics::msInstance.mSimTime_Temp > *(float *)(v9 + 4) )
        {
          max_lateral_offset = max_lateral_offset + *(float *)(v6 + 116);
          v25 = (float)(v25 + *(float *)(v6 + 68)) + *(float *)(v9 + 124);
        }
        else
        {
          max_lateral_offset = max_lateral_offset + *(float *)(v6 + 116);
          v25 = (float)(v25 + *(float *)(v6 + 84)) + *(float *)(v9 + 124);
        }
      }
      if ( *(_BYTE *)(v9 + 9) )
        v16 = v16 + *(float *)(v6 + 152);
      v27 = cosf((float)(v16 * 3.1415927) * 0.0055555557);
      v28 = UFG::FormationManagerComponent::IsInPosition(
              v1,
              &current_position,
              &desired_position,
              v25,
              max_lateral_offset,
              &current_radial_offset,
              &current_lateral_offset,
              0);
      v29 = *(_DWORD *)v9;
      v30 = *(float *)&FLOAT_1_0;
      v31 = *(float *)&FLOAT_1_0;
      v32 = v28;
      if ( *(_DWORD *)v9 <= 1u )
      {
        v30 = FLOAT_2_0;
        v31 = FLOAT_2_0;
      }
      v33 = current_radial_offset <= v30 && current_lateral_offset <= v31;
      if ( v1->mStateVariables.m_CurrentlySprinting )
        v34 = v1->m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
      else
        v34 = (float)(*(float *)(v6 + 68) + *(float *)(v6 + 52)) + 5.0;
      v35 = current_radial_offset >= v34 && v18 > (float)(current_radial_offset + 1.0);
      if ( v29 == 3 && v18 < v19 )
      {
        *(_DWORD *)v9 = 2;
        goto LABEL_57;
      }
      if ( v35 )
        goto LABEL_56;
      if ( v29 == 3 )
      {
        if ( v32 )
          goto LABEL_53;
LABEL_56:
        *(_DWORD *)v9 = 3;
        goto LABEL_57;
      }
      if ( v32 )
      {
LABEL_53:
        UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v9 - 32), 0);
        goto LABEL_57;
      }
      *(_DWORD *)v9 = 2 - (v33 != 0);
LABEL_57:
      v36 = v18 < UFG::FormationManagerComponent::GetMaxDistanceForRange(v1, v3) || !*(_DWORD *)v9;
      *(_BYTE *)(v9 + 8) = v36;
      *(_BYTE *)(v9 + 10) = v21;
      *(_BYTE *)(v9 + 9) = v17 > v27;
      if ( !v1->m_FormationFacingType )
        *(_BYTE *)(v9 + 9) = 1;
LABEL_64:
      ++v7;
      v9 += 200i64;
      ++v8;
    }
    while ( v7 < *(_DWORD *)v6 );
    v4 = v41;
LABEL_66:
    v4 += 1600i64;
    ++v3;
    v6 += 4i64;
    ++v5;
    v41 = v4;
  }
  while ( v3 < v1->m_NumRanges );
}

// File Line: 1841
// RVA: 0x36AEE0
bool __fastcall UFG::FormationManagerComponent::IsInPosition(UFG::FormationManagerComponent *this, UFG::qVector3 *current_position, UFG::qVector3 *desired_position, float max_radial_offset, float max_lateral_offset, float *current_radial_offset, float *current_lateral_offset, bool debug_print)
{
  UFG::SimComponent *v8; // rbx
  UFG::FormationManagerComponent *v9; // rdi
  UFG::qVector3 *v10; // rsi
  UFG::qVector3 *v11; // rbp
  float v12; // xmm9_4
  float v13; // xmm7_4
  float *v14; // rbx
  float v15; // xmm7_4
  __m128 v16; // xmm6
  float v17; // xmm5_4
  __m128 v18; // xmm3
  float v19; // xmm8_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  __m128 v26; // xmm0
  float v27; // xmm6_4
  float v28; // xmm7_4
  Render::DebugDrawContext *v29; // rax

  v8 = this->m_pTransformNodeComponent.m_pSimComponent;
  v9 = this;
  v10 = desired_position;
  v11 = current_position;
  v12 = max_radial_offset;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
  v13 = *(float *)&v8[2].m_BoundComponentHandles.mNode.mPrev;
  v16 = (__m128)HIDWORD(v8[2].m_BoundComponentHandles.mNode.mPrev);
  v14 = (float *)v9->m_pTransformNodeComponent.m_pSimComponent;
  v15 = v13 - v11->x;
  v16.m128_f32[0] = v16.m128_f32[0] - v11->y;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9->m_pTransformNodeComponent.m_pSimComponent);
  v18 = (__m128)LODWORD(v11->y);
  v17 = v11->x - v10->x;
  v18.m128_f32[0] = v18.m128_f32[0] - v10->y;
  v19 = v11->z - v10->z;
  v20 = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15);
  if ( v20 <= 0.001 )
  {
    v25 = UFG::qVector3::msZero.x;
    v16 = (__m128)LODWORD(UFG::qVector3::msZero.y);
  }
  else
  {
    if ( v20 == 0.0 )
      v21 = 0.0;
    else
      v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
    v22 = v15 * v21;
    v23 = v16.m128_f32[0] * v21;
    v24 = (float)((float)(v23 * v18.m128_f32[0]) + (float)(v22 * v17)) + (float)((float)(v21 * 0.0) * v19);
    v25 = v22 * v24;
    v16.m128_f32[0] = v23 * v24;
  }
  v26 = v18;
  v26.m128_f32[0] = (float)(v26.m128_f32[0] - v16.m128_f32[0]) * (float)(v26.m128_f32[0] - v16.m128_f32[0]);
  v16.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v25 * v25);
  LODWORD(v27) = (unsigned __int128)_mm_sqrt_ps(v16);
  v26.m128_f32[0] = v26.m128_f32[0] + (float)((float)(v17 - v25) * (float)(v17 - v25));
  LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v26);
  if ( (float)((float)((float)(v18.m128_f32[0] * (float)(v14[45] - v10->y)) + (float)(v17 * (float)(v14[44] - v10->x)))
             + (float)(v19 * (float)(v14[46] - v10->z))) > 0.0 )
    LODWORD(v27) ^= _xmm[0];
  if ( debug_print )
  {
    v29 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawText(v29, v11, &UFG::qColour::White, "R: %.1f L: %.1f", v27, v28);
  }
  *current_radial_offset = v27;
  *current_lateral_offset = v28;
  return v12 > COERCE_FLOAT(LODWORD(v27) & _xmm) && max_lateral_offset > COERCE_FLOAT(LODWORD(v28) & _xmm);
}

// File Line: 1895
// RVA: 0x375560
void __fastcall UFG::FormationManagerComponent::MaybeSetDesiredPositionFromProfile(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // r13
  UFG::TransformNodeComponent *v2; // r15
  UFG::SimComponent *v3; // rbx
  float v4; // xmm0_4
  int v5; // edx
  float v6; // xmm6_4
  float v7; // xmm7_4
  signed __int64 v8; // r9
  signed __int64 v9; // rsi
  signed __int64 v10; // r8
  signed __int64 v11; // rax
  signed __int64 v12; // r14
  __int64 v13; // rax
  __int64 v14; // rbx
  __int64 v15; // rdi
  float v16; // xmm0_4
  UFG::TransformNodeComponent *v17; // rbx
  float v18; // xmm8_4
  unsigned __int16 v19; // r12
  signed int v20; // er15
  UFG::FormationProfile *v21; // rax
  __int64 v22; // rcx
  unsigned __int16 v23; // si
  float v24; // xmm7_4
  float v25; // xmm0_4
  float v26; // xmm6_4
  float v27; // xmm9_4
  float v28; // xmm0_4
  __int64 v29; // rdi
  float v30; // xmm9_4
  float v31; // xmm8_4
  float v32; // xmm7_4
  UFG::SimObject *v33; // rdi
  UFG::SimComponent *v34; // rax
  UFG::SimComponent *v35; // r14
  int v36; // er15
  UFG::CombatRegion *v37; // rcx
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm4_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  signed int v45; // ebx
  UFG::SimObject *v46; // rcx
  UFG::SimComponent *v47; // rax
  bool v48; // di
  __int64 v49; // rax
  UFG::SimComponent *v50; // rsi
  UFG::SimObject *v51; // rcx
  bool v52; // al
  __m128 v53; // xmm2
  float v54; // xmm1_4
  float v55; // xmm3_4
  float v56; // xmm0_4
  float v57; // xmm5_4
  float v58; // xmm6_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // xmm4_4
  float v62; // xmm0_4
  UFG::SimObject *v63; // rcx
  UFG::SimComponent *v64; // rax
  bool v65; // al
  int v66; // eax
  unsigned __int16 v67; // dx
  UFG::eInFormationPositionType v68; // ebx
  bool v69; // zf
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm3_4
  float v73; // xmm1_4
  float v74; // xmm0_4
  float v75; // xmm1_4
  int v76; // eax
  bool v77; // al
  float v78; // xmm1_4
  float v79; // xmm2_4
  bool v80; // cl
  bool v81; // al
  UFG::qVector3 last_valid_position; // [rsp+40h] [rbp-B0h]
  UFG::qVector3 vPoint; // [rsp+50h] [rbp-A0h]
  int range_index; // [rsp+60h] [rbp-90h]
  float current_lateral_offset; // [rsp+64h] [rbp-8Ch]
  float current_radial_offset; // [rsp+68h] [rbp-88h]
  __int128 desired_direction; // [rsp+70h] [rbp-80h]
  float *v88; // [rsp+80h] [rbp-70h]
  __int64 v89; // [rsp+88h] [rbp-68h]
  float *v90; // [rsp+90h] [rbp-60h]
  UFG::qVector3 from_position; // [rsp+98h] [rbp-58h]
  UFG::qVector3 to_position; // [rsp+A8h] [rbp-48h]
  __int64 v93; // [rsp+B8h] [rbp-38h]
  UFG::SimObject *ray_hit_object; // [rsp+C0h] [rbp-30h]
  UFG::FormationManagerComponent *v95; // [rsp+C8h] [rbp-28h]
  __int64 v96; // [rsp+D0h] [rbp-20h]
  __int64 v97; // [rsp+D8h] [rbp-18h]
  __int64 v98; // [rsp+E0h] [rbp-10h]
  __int64 v99; // [rsp+E8h] [rbp-8h]
  UFG::qVector3 desired_position; // [rsp+F0h] [rbp+0h]
  __int64 v101; // [rsp+100h] [rbp+10h]
  UFG::qVector3 *current_position; // [rsp+108h] [rbp+18h]
  __int64 v103; // [rsp+110h] [rbp+20h]
  __int64 v104; // [rsp+118h] [rbp+28h]
  unsigned __int16 vars0; // [rsp+210h] [rbp+120h]
  signed int retaddr; // [rsp+218h] [rbp+128h]
  signed int v107; // [rsp+220h] [rbp+130h]
  int slot_index; // [rsp+228h] [rbp+138h]

  v1 = this;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v2 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    v90 = (float *)v2;
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v3 = v1->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
    v4 = atan2f(*((float *)&v3[2].vfptr + 1), *(float *)&v3[2].vfptr);
    v5 = 0;
    v6 = FLOAT_32768_0;
    v7 = FLOAT_0_31830987;
    range_index = 0;
    v103 = (unsigned int)(signed int)(float)((float)(v4 * 32768.0) * 0.31830987);
    if ( v1->m_NumRanges > 0 )
    {
      v8 = (signed __int64)&v1->mStateVariables.m_FormationSlot[0][0].m_Direction.z;
      v9 = (signed __int64)v1->m_NumSlotsPerRange;
      v93 = -232i64 - (_QWORD)v1;
      v10 = 36i64;
      v11 = -332i64 - (_QWORD)v1;
      v95 = (UFG::FormationManagerComponent *)((char *)v1 + 632);
      v99 = (__int64)v1->m_NumSlotsPerRange;
      v104 = -332i64 - (_QWORD)v1;
      v89 = 36i64;
      while ( 1 )
      {
        if ( *(UFG::eFormationManagerRingType *)((char *)v1->mStateVariables.m_pCurrentProfile->m_RingType + v11 + v9) == 1 )
        {
          slot_index = 0;
          if ( *(_DWORD *)v9 > 0 )
            break;
        }
LABEL_89:
        v11 = v104;
        ++v5;
        v9 += 4i64;
        v8 += 1600i64;
        v10 += 16i64;
        range_index = v5;
        v99 = v9;
        v95 = (UFG::FormationManagerComponent *)v8;
        v89 = v10;
        if ( v5 >= v1->m_NumRanges )
          return;
      }
      v12 = v8;
      *((_QWORD *)&desired_direction + 1) = v8;
      v88 = v1->m_MaxLateralDistanceFromDesiredPosition;
LABEL_7:
      v13 = *(_QWORD *)(v12 + 80);
      if ( v13 )
        v14 = *(_QWORD *)(v13 + 88);
      else
        v14 = 0i64;
      if ( !v13 || !v14 )
        goto LABEL_87;
      v15 = *(_QWORD *)(v12 + 56);
      *(_QWORD *)&desired_direction = *(_QWORD *)(v12 + 56);
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14);
      current_position = (UFG::qVector3 *)(v14 + 176);
      v16 = atan2f(*(float *)(v14 + 180) - v2->mWorldTransform.v3.y, *(float *)(v14 + 176) - v2->mWorldTransform.v3.x);
      v17 = 0i64;
      v18 = UFG::qVector3::msZero.z;
      v107 = -1;
      v19 = 0;
      v20 = 0;
      retaddr = 0;
      v101 = (unsigned int)(signed int)(float)((float)(v16 * v6) * v7);
      v21 = v1->mStateVariables.m_pCurrentProfile;
      *(UFG::qVector3 *)&desired_direction = UFG::qVector3::msZero;
      if ( *(signed int *)((char *)&v21->m_NameID.mUID + v9 + v93) <= 0 )
        goto LABEL_86;
      v22 = v89;
      v97 = v89;
      while ( 1 )
      {
        v23 = v103 + *(_WORD *)((char *)&v21->m_NameID.mUID + v22);
        vars0 = v23;
        v24 = (float)((float)v23 * 3.1415927) * 0.000030517578;
        v25 = sinf(v24);
        v26 = *(float *)(v12 + 8);
        v27 = v25;
        v28 = cosf(v24);
        v29 = *(_QWORD *)(v15 + 104);
        v30 = v27 * v26;
        v31 = v18 * v26;
        v32 = v28 * v26;
        if ( !v29 )
          break;
        v33 = *(UFG::SimObject **)(v29 + 40);
        if ( !v33 )
          goto LABEL_18;
        v34 = UFG::SimObject::GetComponentOfType(v33, UFG::ActiveAIEntityComponent::_TypeUID);
        v17 = v33->m_pTransformNodeComponent;
        v35 = v34;
LABEL_19:
        if ( !v1->m_pAIEntityComponent.m_pSimComponent
          || !v1->m_pTransformNodeComponent.m_pSimComponent
          || !v33
          || !v35
          || !v17 )
        {
          goto LABEL_60;
        }
        v36 = *(_DWORD *)(desired_direction + 52);
        UFG::TransformNodeComponent::UpdateWorldTransform(v17);
        v37 = *(UFG::CombatRegion **)&v35[15].m_TypeUID;
        v38 = v32 + v17->mWorldTransform.v3.x;
        v39 = v30 + v17->mWorldTransform.v3.y;
        v40 = v31 + v17->mWorldTransform.v3.z;
        v41 = v38;
        v42 = v39;
        last_valid_position.x = v32 + v17->mWorldTransform.v3.x;
        last_valid_position.y = v39;
        vPoint.x = v38;
        vPoint.y = v39;
        vPoint.z = v40;
        last_valid_position.z = v40;
        if ( v37 )
        {
          if ( !UFG::CombatRegion::IsHitPoint(v37, &vPoint) )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v17);
            v43 = v17->mWorldTransform.v3.y;
            last_valid_position.x = v17->mWorldTransform.v3.x;
            v44 = v17->mWorldTransform.v3.z;
            last_valid_position.y = v43;
            last_valid_position.z = v44;
LABEL_27:
            v20 = retaddr;
LABEL_28:
            v45 = v107;
            goto LABEL_29;
          }
          v40 = vPoint.z;
          v39 = vPoint.y;
          v38 = vPoint.x;
          v42 = last_valid_position.y;
          v41 = last_valid_position.x;
        }
        if ( !v36 )
        {
          v46 = v1->m_pAIEntityComponent.m_pSimComponent->m_pSimObject;
          if ( v46 )
            v47 = UFG::SimObject::GetComponentOfType(v46, UFG::NavComponent::_TypeUID);
          else
            v47 = 0i64;
          v98 = *(__int64 *)((char *)&v47[2].m_BoundComponentHandles.mNode.mNext + 4);
          HIDWORD(v98) |= 0x200u;
          v48 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                  UFG::NavManager::ms_pInstance,
                  (UFG::HavokNavPosition *)&v47[1].m_SafePointerList.mNode.mNext,
                  &vPoint,
                  (UFG::NavParams *)&v98,
                  &last_valid_position) == 0;
LABEL_52:
          v20 = retaddr;
          if ( !v48 )
            goto LABEL_28;
          goto LABEL_60;
        }
        v49 = *(_QWORD *)(desired_direction + 104);
        if ( v49 && *(_BYTE *)(v49 + 96) )
          goto LABEL_50;
        v50 = v1->m_pTransformNodeComponent.m_pSimComponent;
        v51 = 0i64;
        if ( v50 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
          v52 = 0;
          v53 = (__m128)HIDWORD(v50[2].m_BoundComponentHandles.mNode.mPrev);
          v54 = *(float *)&v50[2].m_BoundComponentHandles.mNode.mPrev;
          v38 = vPoint.x;
          v51 = 0i64;
          ray_hit_object = 0i64;
          v39 = vPoint.y;
          v55 = *(float *)&v50[2].m_BoundComponentHandles.mNode.mNext;
          v40 = vPoint.z;
          v56 = *(float *)&v50[2].m_BoundComponentHandles.mNode.mNext;
          LODWORD(from_position.y) = v53.m128_i32[0];
          from_position.x = v54;
          from_position.z = v55;
          to_position = vPoint;
          v53.m128_f32[0] = (float)((float)((float)(v53.m128_f32[0] - vPoint.y) * (float)(v53.m128_f32[0] - vPoint.y))
                                  + (float)((float)(v54 - vPoint.x) * (float)(v54 - vPoint.x)))
                          + (float)((float)(v56 - vPoint.z) * (float)(v56 - vPoint.z));
          if ( COERCE_FLOAT(_mm_sqrt_ps(v53)) <= 100.0 )
          {
            from_position.z = v55 + 1.5;
            to_position.z = vPoint.z + 1.5;
            v52 = UFG::DoRaycast(
                    &from_position,
                    &to_position,
                    v33,
                    &last_valid_position,
                    &ray_hit_object,
                    0i64,
                    0,
                    &UFG::qColour::Yellow);
            v51 = ray_hit_object;
            v40 = vPoint.z;
            v39 = vPoint.y;
            v38 = vPoint.x;
          }
          v42 = last_valid_position.y;
          v41 = last_valid_position.x;
        }
        else
        {
          v52 = 0;
        }
        if ( v52
          || !v51
          && fsqrt(
               (float)((float)((float)(v42 - v39) * (float)(v42 - v39))
                     + (float)((float)(v41 - v38) * (float)(v41 - v38)))
             + (float)((float)(last_valid_position.z - v40) * (float)(last_valid_position.z - v40))) < 0.1 )
        {
          v23 = vars0;
LABEL_50:
          v48 = 1;
          goto LABEL_51;
        }
        v57 = v17->mWorldTransform.v3.x;
        v58 = v17->mWorldTransform.v3.y;
        v23 = vars0;
        v48 = 0;
        v59 = v41 - v57;
        v60 = v42 - v58;
        v61 = fsqrt((float)(v60 * v60) + (float)(v59 * v59));
        if ( v61 > 1.0 )
        {
          v62 = (float)(v61 - 1.0) / v61;
          last_valid_position.z = (float)(v62 * 0.0) + v17->mWorldTransform.v3.z;
          last_valid_position.x = (float)(v59 * v62) + v57;
          last_valid_position.y = (float)(v60 * v62) + v58;
        }
LABEL_51:
        if ( (unsigned int)(v36 - 1) > 1 )
          goto LABEL_52;
        v63 = v35->m_pSimObject;
        if ( v63 )
          v64 = UFG::SimObject::GetComponentOfType(v63, UFG::NavComponent::_TypeUID);
        else
          v64 = 0i64;
        v96 = *(__int64 *)((char *)&v64[2].m_BoundComponentHandles.mNode.mNext + 4);
        HIDWORD(v96) |= 0x200u;
        v65 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                UFG::NavManager::ms_pInstance,
                (UFG::HavokNavPosition *)&v64[1].m_SafePointerList.mNode.mNext,
                &vPoint,
                (UFG::NavParams *)&v96,
                &last_valid_position);
        if ( !v48 || v65 )
          goto LABEL_27;
        v20 = retaddr;
LABEL_60:
        LOWORD(v66) = UFG::qAngleDiff(v101, v23);
        v45 = v107;
        v67 = v66;
        if ( v107 < 0 )
          goto LABEL_92;
        v66 = (signed __int16)v66;
        if ( (v66 & 0x8000u) != 0 )
          v66 = -v66;
        if ( (signed __int16)v66 < (signed int)v19 )
        {
LABEL_92:
          v45 = v20;
          v19 = v67;
          v107 = v20;
          if ( (v67 & 0x8000u) != 0 )
            v19 = -v67;
          *(_QWORD *)&desired_direction = __PAIR__(LODWORD(v30), LODWORD(v32));
          *((float *)&desired_direction + 2) = v31;
        }
LABEL_29:
        v9 = v99;
        v21 = v1->mStateVariables.m_pCurrentProfile;
        v12 = *((_QWORD *)&desired_direction + 1);
        ++v20;
        v22 = v97 + 2;
        retaddr = v20;
        v97 += 2i64;
        if ( v20 >= *(signed int *)((char *)&v21->m_NameID.mUID + v99 + v93) )
        {
          if ( v45 < 0 )
          {
            v6 = FLOAT_32768_0;
            v7 = FLOAT_0_31830987;
LABEL_86:
            v2 = (UFG::TransformNodeComponent *)v90;
            goto LABEL_87;
          }
          v68 = *(_DWORD *)(*((_QWORD *)&desired_direction + 1) + 24i64);
          UFG::FormationManagerComponent::SetDesiredDirection(
            v1,
            range_index,
            slot_index,
            (UFG::GetInFormationNode *)desired_direction,
            (UFG::qVector3 *)&desired_direction);
          UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v12 - 8), v68);
          v69 = v1->mStateVariables.m_CurrentlySprinting == 0;
          v2 = (UFG::TransformNodeComponent *)v90;
          v70 = *(float *)(v12 - 8);
          v71 = *(float *)(v12 - 4);
          v72 = *(float *)(v9 + 52);
          current_lateral_offset = 0.0;
          current_radial_offset = 0.0;
          v73 = v71 + v90[45];
          desired_position.x = v70 + v90[44];
          v74 = v90[46];
          desired_position.y = v73;
          v75 = *v88;
          desired_position.z = v74 + *(float *)v12;
          if ( v69 )
          {
            v76 = *(_DWORD *)(v12 + 24);
            if ( v76 )
            {
              if ( v76 == 3 )
              {
                v75 = v75 + 4.0;
                v72 = v72 + 2.0;
              }
            }
            else if ( UFG::Metrics::msInstance.mSimTime_Temp > *(float *)(v12 + 28) )
            {
              v75 = v75 + *(float *)(v9 + 116);
              v72 = (float)(v72 + *(float *)(v9 + 68)) + *(float *)(v12 + 148);
            }
            else
            {
              v75 = v75 + *(float *)(v9 + 116);
              v72 = (float)(v72 + *(float *)(v9 + 84)) + *(float *)(v12 + 148);
            }
          }
          v77 = UFG::FormationManagerComponent::IsInPosition(
                  v1,
                  current_position,
                  &desired_position,
                  v72,
                  v75,
                  &current_radial_offset,
                  &current_lateral_offset,
                  0);
          v78 = *(float *)&FLOAT_1_0;
          v79 = *(float *)&FLOAT_1_0;
          v80 = v77;
          if ( *(_DWORD *)(v12 + 24) <= 1u )
          {
            v78 = FLOAT_2_0;
            v79 = FLOAT_2_0;
          }
          v81 = current_radial_offset <= v78 && current_lateral_offset <= v79;
          if ( v80 )
          {
            UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v12 - 8), 0);
            v6 = FLOAT_32768_0;
            v7 = FLOAT_0_31830987;
          }
          else
          {
            v6 = FLOAT_32768_0;
            v7 = FLOAT_0_31830987;
            if ( v81 )
              *(_DWORD *)(v12 + 24) = 1;
          }
LABEL_87:
          ++v88;
          v12 += 200i64;
          *((_QWORD *)&desired_direction + 1) = v12;
          if ( ++slot_index >= *(_DWORD *)v9 )
          {
            v5 = range_index;
            v10 = v89;
            v8 = (signed __int64)v95;
            goto LABEL_89;
          }
          goto LABEL_7;
        }
        v18 = UFG::qVector3::msZero.z;
        v15 = desired_direction;
        v17 = 0i64;
      }
      v33 = 0i64;
LABEL_18:
      v35 = 0i64;
      goto LABEL_19;
    }
  }
}

// File Line: 2003
// RVA: 0x396360
void __fastcall UFG::FormationManagerComponent::UpdateDesiredPositionsIfLocked(UFG::FormationManagerComponent *this)
{
  int v1; // er14
  UFG::FormationManagerComponent *v2; // rbp
  UFG::FormationSlot (*v3)[8]; // r15
  int *v4; // rsi
  signed __int64 v5; // r12
  int v6; // edi
  UFG::FormationSlot *v7; // rbx
  UFG::GetInFormationNode *v8; // r9
  UFG::SimComponent *v9; // rax

  v1 = 0;
  v2 = this;
  if ( this->m_NumRanges > 0 )
  {
    v3 = this->mStateVariables.m_FormationSlot;
    v4 = this->m_NumSlotsPerRange;
    v5 = -332i64 - (_QWORD)this;
    do
    {
      if ( *(UFG::eFormationManagerRingType *)((char *)v2->mStateVariables.m_pCurrentProfile->m_RingType
                                             + v5
                                             + (unsigned __int64)v4) == eRING_TYPE_FLUID )
      {
        v6 = 0;
        if ( *v4 > 0 )
        {
          v7 = (UFG::FormationSlot *)v3;
          do
          {
            v8 = v7->m_pMember.m_pPointer;
            if ( v8 )
            {
              v9 = v8->m_pOwner.m_pPointer;
              if ( v9 )
              {
                if ( LOBYTE(v9[1].m_Flags) )
                {
                  UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(v2, v1, v6, v8);
                  UFG::FormationSlot::SetInPosition(v7, 0);
                }
              }
            }
            ++v6;
            ++v7;
          }
          while ( v6 < *v4 );
        }
      }
      ++v1;
      ++v4;
      ++v3;
    }
    while ( v1 < v2->m_NumRanges );
  }
}

// File Line: 2035
// RVA: 0x395FB0
void __fastcall UFG::FormationManagerComponent::UpdateDesiredPositionIfNotInRange(UFG::FormationManagerComponent *this)
{
  UFG::FormationManagerComponent *v1; // rbp
  int v2; // er14
  unsigned int v3; // ebx
  unsigned int v4; // edi
  int v5; // eax
  int *v6; // rdx
  __int64 v7; // r8
  int v8; // er15
  signed __int64 v9; // r8
  int *v10; // r13
  signed __int64 v11; // rcx
  int v12; // esi
  int v13; // eax
  signed __int64 v14; // rdi
  bool v15; // cl
  __int64 v16; // rax
  __int64 v17; // rbx
  float v18; // xmm6_4
  __m128 v19; // xmm9
  float v20; // xmm10_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  __m128 v23; // xmm8
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  float v26; // xmm7_4
  float v27; // xmm11_4
  float v28; // xmm10_4
  float v29; // xmm7_4
  float v30; // xmm1_4
  float v31; // xmm9_4
  float v32; // xmm6_4
  float v33; // xmm8_4
  float v34; // xmm0_4
  UFG::eInFormationPositionType v35; // ebx
  UFG::TransformNodeComponent *v36; // [rsp+20h] [rbp-108h]
  unsigned int v37; // [rsp+130h] [rbp+8h]
  int v38; // [rsp+138h] [rbp+10h]
  unsigned int v39; // [rsp+140h] [rbp+18h]
  signed __int64 v40; // [rsp+148h] [rbp+20h]

  v1 = this;
  v2 = 0;
  v3 = 0;
  v37 = 0;
  v4 = this->mStateVariables.m_ExpensiveUpdateCount;
  v39 = this->mStateVariables.m_ExpensiveUpdateCount;
  v5 = this->m_NumRanges;
  if ( v5 > 0 )
  {
    v6 = this->m_NumSlotsPerRange;
    v7 = (unsigned int)v5;
    do
    {
      v3 += *v6 - v6[8];
      ++v6;
      --v7;
    }
    while ( v7 );
    v37 = v3;
  }
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    if ( v3 )
    {
      v36 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v36);
      v8 = 0;
      if ( v1->m_NumRanges > 0 )
      {
        v9 = (signed __int64)&v1->mStateVariables.m_FormationSlot[0][0].m_CurrentlyInRange;
        v40 = (signed __int64)&v1->mStateVariables.m_FormationSlot[0][0].m_CurrentlyInRange;
        v10 = v1->m_NumSlotsPerRange;
        v11 = -332i64 - (_QWORD)v1;
        do
        {
          if ( *(UFG::eFormationManagerRingType *)((char *)v1->mStateVariables.m_pCurrentProfile->m_RingType
                                                 + v11
                                                 + (unsigned __int64)v10) == eRING_TYPE_FLUID )
          {
            v12 = 0;
            if ( *v10 > 0 )
            {
              v13 = v4 % v3;
              v38 = v4 % v3;
              v14 = v9;
              do
              {
                v15 = v13 == v2;
                v16 = *(_QWORD *)(v14 + 48);
                if ( v16 )
                  v17 = *(_QWORD *)(v16 + 88);
                else
                  v17 = 0i64;
                if ( v16 )
                {
                  if ( v17 )
                  {
                    ++v2;
                    if ( v15 && !*(_BYTE *)v14 && v8 == v1->m_NumRanges - 1 )
                    {
                      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v17);
                      v18 = *(float *)(v14 - 40);
                      v19 = (__m128)*(unsigned int *)(v14 - 36);
                      v20 = *(float *)(v14 - 32);
                      v21 = *(float *)(v17 + 184) - v36->mWorldTransform.v3.z;
                      v22 = *(float *)(v17 + 180) - v36->mWorldTransform.v3.y;
                      v23 = (__m128)*(unsigned int *)(v17 + 176);
                      v23.m128_f32[0] = v23.m128_f32[0] - v36->mWorldTransform.v3.x;
                      v24 = v19;
                      v24.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18))
                                      + (float)(v20 * v20);
                      if ( v24.m128_f32[0] > 0.001 )
                      {
                        v25 = v23;
                        v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22))
                                        + (float)(v21 * v21);
                        if ( v25.m128_f32[0] > 0.001 )
                        {
                          if ( v24.m128_f32[0] == 0.0 )
                            v26 = 0.0;
                          else
                            v26 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
                          v27 = v26 * v20;
                          v28 = v26 * v19.m128_f32[0];
                          v29 = v26 * v18;
                          if ( v25.m128_f32[0] == 0.0 )
                            v30 = 0.0;
                          else
                            v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25));
                          v31 = v30 * v21;
                          v32 = v30 * v22;
                          v33 = v23.m128_f32[0] * v30;
                          if ( _S18_0 & 1 )
                          {
                            v34 = MIN_ANGLE_DIFF;
                          }
                          else
                          {
                            _S18_0 |= 1u;
                            v34 = cosf(0.17453294);
                            MIN_ANGLE_DIFF = v34;
                          }
                          if ( (float)((float)((float)(v32 * v28) + (float)(v33 * v29)) + (float)(v31 * v27)) < v34 )
                          {
                            v35 = *(_DWORD *)(v14 - 8);
                            UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
                              v1,
                              v8,
                              v12,
                              *(UFG::GetInFormationNode **)(v14 + 24));
                            UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v14 - 40), v35);
                          }
                        }
                      }
                    }
                  }
                }
                ++v12;
                v14 += 200i64;
                v13 = v38;
              }
              while ( v12 < *v10 );
              v3 = v37;
              v9 = v40;
              v4 = v39;
            }
          }
          ++v8;
          ++v10;
          v9 += 1600i64;
          v40 = v9;
          v11 = -332i64 - (_QWORD)v1;
        }
        while ( v8 < v1->m_NumRanges );
      }
    }
  }
}

// File Line: 2137
// RVA: 0x395BC0
void __fastcall UFG::FormationManagerComponent::UpdateDesiredPositionIfNotAtCorrectAngle(UFG::FormationManagerComponent *this)
{
  signed __int64 v1; // r11
  unsigned int v2; // edi
  signed __int64 v3; // r12
  unsigned int v4; // ebx
  int v5; // er8
  int v6; // er9
  int v7; // er15
  UFG::FormationManagerComponent *v8; // rsi
  signed __int64 v9; // r10
  int *v10; // rcx
  unsigned __int64 v11; // rdx
  int v12; // eax
  signed __int64 v13; // rcx
  __int64 v14; // r13
  signed __int64 v15; // r14
  int v16; // ebp
  unsigned int v17; // eax
  signed __int64 v18; // rdi
  int v19; // eax
  bool v20; // zf
  __int64 v21; // rax
  __int64 v22; // rbx
  __int64 v23; // rcx
  float v24; // xmm3_4
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  float v27; // xmm9_4
  float v28; // xmm2_4
  float v29; // xmm8_4
  __m128 v30; // xmm5
  float v31; // xmm7_4
  float v32; // xmm10_4
  float v33; // xmm4_4
  float v34; // xmm2_4
  float v35; // xmm10_4
  __m128 v36; // xmm3
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm7_4
  float v40; // xmm0_4
  __int64 v41; // rcx
  float v42; // xmm1_4
  UFG::eInFormationPositionType v43; // ebx
  signed __int64 v44; // [rsp+20h] [rbp-C8h]
  UFG::SimComponent *v45; // [rsp+28h] [rbp-C0h]
  unsigned int v46; // [rsp+F0h] [rbp+8h]
  int v47; // [rsp+F8h] [rbp+10h]
  unsigned int v48; // [rsp+100h] [rbp+18h]
  signed __int64 range_index; // [rsp+108h] [rbp+20h]

  v1 = this->m_NumRanges;
  v2 = this->mStateVariables.m_ExpensiveUpdateCount;
  LODWORD(v3) = 1;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = this;
  v48 = this->mStateVariables.m_ExpensiveUpdateCount;
  v46 = 0;
  range_index = 1i64;
  v9 = 1i64;
  if ( v1 > 1 )
  {
    if ( v1 - 1 >= 2 )
    {
      v10 = &this->m_NumSlotsPerRange[1];
      v11 = ((unsigned __int64)(v1 - 3) >> 1) + 1;
      v9 = 2 * v11 + 1;
      do
      {
        v12 = *v10;
        v10 += 2;
        v5 += v12 - v10[6];
        v6 += *(v10 - 1) - v10[7];
        --v11;
      }
      while ( v11 );
    }
    if ( v9 < v1 )
      v4 = v8->m_NumSlotsPerRange[v9] - v8->m_NumFreeSlotsPerRange[v9];
    v4 += v5 + v6;
    v46 = v4;
  }
  if ( v8->m_pTransformNodeComponent.m_pSimComponent )
  {
    if ( v4 )
    {
      v45 = v8->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8->m_pTransformNodeComponent.m_pSimComponent);
      if ( v8->m_NumRanges > 1 )
      {
        v13 = (signed __int64)&v8->mStateVariables.m_FormationSlot[1][0].m_Direction.y;
        v14 = 0i64;
        v15 = 20i64;
        v44 = (signed __int64)&v8->mStateVariables.m_FormationSlot[1][0].m_Direction.y;
        do
        {
          if ( !*(_DWORD *)((char *)v8->mStateVariables.m_pCurrentProfile + v15 - 12) )
          {
            v16 = 0;
            if ( *(_DWORD *)((char *)&v8->m_pAttackRightsComponent.m_pSimObject + v15 + 4) > 0 )
            {
              v17 = v2;
              v18 = v13;
              v19 = v17 % v4;
              v47 = v19;
              do
              {
                v20 = v19 == v7;
                v21 = *(_QWORD *)(v18 + 84);
                if ( v21 )
                  v22 = *(_QWORD *)(v21 + 88);
                else
                  v22 = 0i64;
                v23 = *(_QWORD *)(v18 + 60);
                if ( v21 )
                {
                  if ( v22 )
                  {
                    if ( v23 )
                    {
                      if ( *(_DWORD *)(v23 + 52) )
                      {
                        ++v7;
                        if ( v20 )
                        {
                          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v22);
                          v25 = (__m128)*(unsigned int *)(v22 + 180);
                          v24 = *(float *)(v22 + 176) - *(float *)&v45[2].m_BoundComponentHandles.mNode.mPrev;
                          v25.m128_f32[0] = v25.m128_f32[0]
                                          - *((float *)&v45[2].m_BoundComponentHandles.mNode.mPrev + 1);
                          v26 = v25;
                          v26.m128_f32[0] = (float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24);
                          LODWORD(v27) = (unsigned __int128)_mm_sqrt_ps(v26);
                          if ( v27 > 0.001 )
                          {
                            if ( v26.m128_f32[0] == 0.0 )
                              v28 = 0.0;
                            else
                              v28 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
                            v29 = *(float *)v18;
                            v30 = (__m128)*(unsigned int *)(v18 - 4);
                            v31 = *(float *)(v18 + 4);
                            v32 = v28;
                            v33 = v25.m128_f32[0] * v28;
                            v34 = v28 * 0.0;
                            v35 = v32 * v24;
                            v36 = v30;
                            v36.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v29 * v29))
                                            + (float)(v31 * v31);
                            if ( v36.m128_f32[0] == 0.0 )
                              v37 = 0.0;
                            else
                              v37 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v36));
                            v38 = v30.m128_f32[0] * v37;
                            v39 = v31 * v37;
                            v40 = v37 * v29;
                            v41 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
                            if ( v14 < 0 || (_DWORD)v41 == -1 )
                            {
                              v42 = 0.0;
                            }
                            else
                            {
                              v42 = *(float *)((char *)&v8->mStateVariables.m_pCurrentProfile->m_NameID.mUID + v15);
                              if ( v42 < 0.0 )
                                v42 = v8->m_BattleTypeSpecificParameters[0].m_MaxDistance[v14 + 12 * v41];
                            }
                            if ( (float)((float)((float)(v40 * v33) + (float)(v38 * v35)) + (float)(v39 * v34)) < 0.0
                              || v27 < v42 )
                            {
                              v43 = *(_DWORD *)(v18 + 28);
                              UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
                                v8,
                                range_index,
                                v16,
                                *(UFG::GetInFormationNode **)(v18 + 60));
                              UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v18 - 4), v43);
                            }
                          }
                        }
                      }
                    }
                  }
                }
                v19 = v47;
                ++v16;
                v18 += 200i64;
              }
              while ( v16 < *(_DWORD *)((char *)&v8->m_pAttackRightsComponent.m_pSimObject + v15 + 4) );
              LODWORD(v3) = range_index;
              v13 = v44;
              v4 = v46;
              v2 = v48;
            }
          }
          v3 = (unsigned int)(v3 + 1);
          v13 += 1600i64;
          ++v14;
          v15 += 4i64;
          range_index = v3;
          v44 = v13;
        }
        while ( (signed int)v3 < v8->m_NumRanges );
      }
    }
  }
}

// File Line: 2221
// RVA: 0x395790
void __fastcall UFG::FormationManagerComponent::UpdateDesiredPositionIfInsideWall(UFG::FormationManagerComponent *this)
{
  signed __int64 v1; // r11
  unsigned int v2; // esi
  UFG::FormationManagerComponent *v3; // r13
  int v4; // er8
  int v5; // er9
  int v6; // ebx
  int v7; // edi
  signed __int64 v8; // r10
  int *v9; // rcx
  unsigned __int64 v10; // rdx
  int v11; // eax
  UFG::TransformNodeComponent *v12; // rcx
  unsigned int v13; // edi
  int v14; // er9
  signed __int64 v15; // r8
  int *v16; // rdx
  signed __int64 v17; // rax
  signed __int64 v18; // r14
  int v19; // eax
  bool v20; // zf
  __int64 v21; // rax
  __int64 v22; // rcx
  __int64 v23; // rsi
  __int64 v24; // rax
  bool v25; // r15
  signed int v26; // eax
  signed int v27; // er12
  signed int v28; // ebx
  __int16 v29; // ax
  unsigned __int16 v30; // bp
  unsigned __int16 v31; // di
  float v32; // xmm9_4
  float v33; // xmm8_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm0_4
  int v38; // [rsp+30h] [rbp-E8h]
  unsigned int v39; // [rsp+34h] [rbp-E4h]
  unsigned int v40; // [rsp+38h] [rbp-E0h]
  signed __int64 v41; // [rsp+40h] [rbp-D8h]
  signed __int64 v42; // [rsp+48h] [rbp-D0h]
  UFG::qVector3 desired_direction; // [rsp+58h] [rbp-C0h]
  int v44; // [rsp+120h] [rbp+8h]
  int slot_index; // [rsp+128h] [rbp+10h]
  int range_index; // [rsp+130h] [rbp+18h]
  signed int v47; // [rsp+138h] [rbp+20h]

  v1 = this->m_NumRanges;
  v2 = this->mStateVariables.m_ExpensiveUpdateCount;
  v3 = this;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v40 = this->mStateVariables.m_ExpensiveUpdateCount;
  v8 = 0i64;
  if ( v1 >= 2 )
  {
    v9 = this->m_NumSlotsPerRange;
    v10 = ((unsigned __int64)(v1 - 2) >> 1) + 1;
    v8 = 2 * v10;
    do
    {
      v11 = *v9;
      v9 += 2;
      v4 += v11 - v9[6];
      v5 += *(v9 - 1) - v9[7];
      --v10;
    }
    while ( v10 );
  }
  if ( v8 < v1 )
    v7 = v3->m_NumSlotsPerRange[v8] - v3->m_NumFreeSlotsPerRange[v8];
  v12 = (UFG::TransformNodeComponent *)v3->m_pTransformNodeComponent.m_pSimComponent;
  v13 = v5 + v4 + v7;
  v39 = v13;
  if ( v12 )
  {
    if ( v13 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v12);
      v14 = 0;
      range_index = 0;
      if ( v3->m_NumRanges > 0 )
      {
        v15 = (signed __int64)&v3->mStateVariables.m_FormationSlot[0][0].m_Angle;
        v16 = v3->m_NumSlotsPerRange;
        v17 = -332i64 - (_QWORD)v3;
        v42 = (signed __int64)&v3->mStateVariables.m_FormationSlot[0][0].m_Angle;
        v41 = (signed __int64)v3->m_NumSlotsPerRange;
        do
        {
          if ( !*(int *)((char *)v16 + v17 + (unsigned __int64)v3->mStateVariables.m_pCurrentProfile + 4) )
          {
            slot_index = 0;
            if ( *v16 > 0 )
            {
              v18 = v15;
              v19 = v2 % v13;
              v38 = v2 % v13;
              v16 = (int *)v41;
              do
              {
                v20 = v19 == v6;
                v21 = *(_QWORD *)(v18 + 76);
                if ( v21 )
                  v22 = *(_QWORD *)(v21 + 88);
                else
                  v22 = 0i64;
                v23 = *(_QWORD *)(v18 + 52);
                if ( v21 )
                {
                  if ( v22 )
                  {
                    if ( v23 )
                    {
                      v24 = *(_QWORD *)(v23 + 104);
                      if ( !v24 || !*(_BYTE *)(v24 + 96) )
                      {
                        v44 = ++v6;
                        if ( v20 )
                        {
                          if ( !UFG::FormationManagerComponent::DirectionIsClear(
                                  v3,
                                  (UFG::qVector3 *)(v18 - 12),
                                  (UFG::GetInFormationNode *)v23,
                                  0i64,
                                  0i64,
                                  0) )
                          {
                            v25 = 0;
                            v26 = 2;
                            if ( *(_DWORD *)(v23 + 52) == 1 )
                              v26 = 1;
                            v27 = 0;
                            v47 = v26;
                            if ( v26 > 0 )
                            {
                              do
                              {
                                v28 = 0;
                                do
                                {
                                  v29 = 3276 * (v28 + 1);
                                  v30 = v29 + *(_WORD *)v18;
                                  v31 = *(_WORD *)v18 - 3276 * (v28 + 1);
                                  if ( UFG::FormationManagerComponent::AngleIsClear(
                                         v3,
                                         v29 + *(_WORD *)v18,
                                         (UFG::GetInFormationNode *)v23,
                                         *(float *)(v18 + 4),
                                         v25) )
                                  {
                                    v31 = v30;
LABEL_34:
                                    v32 = UFG::qVector3::msZero.z;
                                    v33 = (float)((float)v31 * 3.1415927) * 0.000030517578;
                                    v34 = sinf(v33);
                                    v35 = *(float *)(v18 + 4);
                                    v36 = v34;
                                    v37 = cosf(v33);
                                    desired_direction.y = v36 * v35;
                                    desired_direction.z = v32 * v35;
                                    desired_direction.x = v37 * v35;
                                    UFG::FormationManagerComponent::SetDesiredDirection(
                                      v3,
                                      range_index,
                                      slot_index,
                                      (UFG::GetInFormationNode *)v23,
                                      &desired_direction);
                                    goto LABEL_35;
                                  }
                                  if ( UFG::FormationManagerComponent::AngleIsClear(
                                         v3,
                                         v31,
                                         (UFG::GetInFormationNode *)v23,
                                         *(float *)(v18 + 4),
                                         v25) )
                                  {
                                    goto LABEL_34;
                                  }
                                  ++v28;
                                }
                                while ( v28 < 10 );
                                v25 = 1;
                                if ( UFG::FormationManagerComponent::DirectionIsClear(
                                       v3,
                                       (UFG::qVector3 *)(v18 - 12),
                                       (UFG::GetInFormationNode *)v23,
                                       0i64,
                                       0i64,
                                       1) )
                                {
                                  break;
                                }
                                ++v27;
                              }
                              while ( v27 < v47 );
LABEL_35:
                              v6 = v44;
                            }
                          }
                          v16 = (int *)v41;
                        }
                      }
                    }
                  }
                }
                v19 = v38;
                v18 += 200i64;
                ++slot_index;
              }
              while ( slot_index < *v16 );
              v14 = range_index;
              v15 = v42;
              v13 = v39;
              v2 = v40;
            }
          }
          v17 = -332i64 - (_QWORD)v3;
          ++v14;
          ++v16;
          v15 += 1600i64;
          range_index = v14;
          v41 = (signed __int64)v16;
          v42 = v15;
        }
        while ( v14 < v3->m_NumRanges );
      }
    }
  }
}

// File Line: 2360
// RVA: 0x352570
bool __fastcall UFG::FormationManagerComponent::DirectionIsClear(UFG::FormationManagerComponent *this, UFG::qVector3 *direction, UFG::GetInFormationNode *get_in_formation, float *max_clear_distance, bool *outside_combat_region, bool force_physics_raycast)
{
  bool *v6; // rdi
  UFG::GetInFormationNode *v7; // r13
  UFG::FormationManagerComponent *v8; // r15
  UFG::SimComponent *v9; // r14
  UFG::SimComponent *v10; // rbx
  UFG::SimObject *v11; // r14
  UFG::SimComponent *v12; // rax
  UFG::TransformNodeComponent *v13; // rsi
  UFG::SimComponent *v14; // r12
  UFG::CombatRegion *v15; // rcx
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  int v20; // edx
  UFG::SimObject *v21; // rcx
  bool v22; // di
  UFG::SimComponent *v23; // rax
  float v24; // xmm6_4
  UFG::SimComponent *v25; // rdi
  UFG::SimObject *v26; // rcx
  __m128 v27; // xmm2
  float v28; // xmm1_4
  float v29; // xmm8_4
  float v30; // xmm0_4
  bool v31; // al
  __m128 v32; // xmm0
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm2_4
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  float v38; // xmm0_4
  float v39; // xmm1_4
  UFG::SimObject *v40; // rcx
  bool v41; // al
  __m128 v42; // xmm1
  float v43; // xmm2_4
  UFG::qVector3 last_valid_position; // [rsp+40h] [rbp-59h]
  UFG::qVector3 vPoint; // [rsp+50h] [rbp-49h]
  UFG::qVector3 to_position; // [rsp+60h] [rbp-39h]
  UFG::qVector3 from_position; // [rsp+70h] [rbp-29h]
  UFG::SimObject *ray_hit_object; // [rsp+F0h] [rbp+57h]
  UFG::qVector3 *v49; // [rsp+F8h] [rbp+5Fh]
  float *v50; // [rsp+108h] [rbp+6Fh]

  v50 = max_clear_distance;
  v49 = direction;
  v6 = outside_combat_region;
  v7 = get_in_formation;
  v8 = this;
  if ( outside_combat_region )
    *outside_combat_region = 0;
  v9 = get_in_formation->m_pOwner.m_pPointer;
  v10 = 0i64;
  if ( !v9 )
  {
    v11 = 0i64;
    goto LABEL_7;
  }
  v11 = v9->m_pSimObject;
  if ( !v11 )
  {
LABEL_7:
    v14 = 0i64;
    v13 = 0i64;
    goto LABEL_8;
  }
  v12 = UFG::SimObject::GetComponentOfType(v11, UFG::ActiveAIEntityComponent::_TypeUID);
  v13 = v11->m_pTransformNodeComponent;
  v14 = v12;
LABEL_8:
  if ( !v8->m_pAIEntityComponent.m_pSimComponent
    || !v8->m_pTransformNodeComponent.m_pSimComponent
    || !v11
    || !v14
    || !v13 )
  {
    return 1;
  }
  LODWORD(outside_combat_region) = v7->m_AttackType;
  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
  v15 = *(UFG::CombatRegion **)&v14[15].m_TypeUID;
  v16 = v49->x + v13->mWorldTransform.v3.x;
  v17 = v49->y + v13->mWorldTransform.v3.y;
  v18 = v49->z + v13->mWorldTransform.v3.z;
  vPoint.x = v16;
  vPoint.y = v17;
  vPoint.z = v18;
  last_valid_position.x = v16;
  last_valid_position.y = v17;
  last_valid_position.z = v18;
  if ( v15 )
  {
    if ( !UFG::CombatRegion::IsHitPoint(v15, &vPoint) )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v13);
      if ( v6 )
        *v6 = 1;
      return 0;
    }
    v18 = vPoint.z;
    v17 = vPoint.y;
    v16 = vPoint.x;
  }
  v20 = (signed int)outside_combat_region;
  if ( (_DWORD)outside_combat_region || force_physics_raycast )
  {
    v23 = v7->m_pOwner.m_pPointer;
    if ( v23 && LOBYTE(v23[1].m_Flags) )
      goto LABEL_54;
    v24 = FLOAT_1_5;
    if ( !(_DWORD)outside_combat_region )
      v24 = FLOAT_0_5;
    v25 = v8->m_pTransformNodeComponent.m_pSimComponent;
    v26 = 0i64;
    if ( v25 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8->m_pTransformNodeComponent.m_pSimComponent);
      v26 = 0i64;
      ray_hit_object = 0i64;
      v27 = (__m128)HIDWORD(v25[2].m_BoundComponentHandles.mNode.mPrev);
      v28 = *(float *)&v25[2].m_BoundComponentHandles.mNode.mPrev;
      v16 = vPoint.x;
      v17 = vPoint.y;
      v18 = vPoint.z;
      v29 = *(float *)&v25[2].m_BoundComponentHandles.mNode.mNext;
      v30 = *(float *)&v25[2].m_BoundComponentHandles.mNode.mNext;
      LODWORD(from_position.y) = v27.m128_i32[0];
      from_position.x = v28;
      to_position = vPoint;
      v27.m128_f32[0] = (float)((float)((float)(v27.m128_f32[0] - vPoint.y) * (float)(v27.m128_f32[0] - vPoint.y))
                              + (float)((float)(v28 - vPoint.x) * (float)(v28 - vPoint.x)))
                      + (float)((float)(v30 - vPoint.z) * (float)(v30 - vPoint.z));
      if ( COERCE_FLOAT(_mm_sqrt_ps(v27)) <= 100.0 )
      {
        from_position.z = v29 + v24;
        to_position.z = vPoint.z + v24;
        v31 = UFG::DoRaycast(
                &from_position,
                &to_position,
                v11,
                &last_valid_position,
                &ray_hit_object,
                0i64,
                0,
                &UFG::qColour::Yellow);
        v26 = ray_hit_object;
        v20 = (signed int)outside_combat_region;
        v18 = vPoint.z;
        v17 = vPoint.y;
        v16 = vPoint.x;
      }
      else
      {
        v20 = (signed int)outside_combat_region;
        v31 = 0;
      }
    }
    else
    {
      v31 = 0;
    }
    v32 = (__m128)LODWORD(last_valid_position.y);
    v32.m128_f32[0] = last_valid_position.y - v17;
    if ( v31
      || !v26
      && (v32.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0])
                                  + (float)((float)(last_valid_position.x - v16) * (float)(last_valid_position.x - v16)))
                          + (float)((float)(last_valid_position.z - v18) * (float)(last_valid_position.z - v18)),
          COERCE_FLOAT(_mm_sqrt_ps(v32)) < 0.1) )
    {
LABEL_54:
      v22 = 1;
    }
    else
    {
      v36 = (__m128)LODWORD(last_valid_position.y);
      v33 = v13->mWorldTransform.v3.x;
      v22 = 0;
      v34 = v13->mWorldTransform.v3.y;
      v35 = last_valid_position.x - v33;
      v36.m128_f32[0] = last_valid_position.y - v34;
      v37 = v36;
      v37.m128_f32[0] = (float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v35 * v35);
      LODWORD(v38) = (unsigned __int128)_mm_sqrt_ps(v37);
      if ( v38 > 1.0 )
      {
        v39 = (float)(v38 - 1.0) / v38;
        last_valid_position.z = (float)(v39 * 0.0) + v13->mWorldTransform.v3.z;
        last_valid_position.x = v33 + (float)(v35 * v39);
        last_valid_position.y = v34 + (float)(v36.m128_f32[0] * v39);
      }
    }
    if ( (unsigned int)(v20 - 1) <= 1 )
    {
      v40 = v14->m_pSimObject;
      if ( v40 )
        v10 = UFG::SimObject::GetComponentOfType(v40, UFG::NavComponent::_TypeUID);
      outside_combat_region = *(bool **)((char *)&v10[2].m_BoundComponentHandles.mNode.mNext + 4);
      HIDWORD(outside_combat_region) |= 0x200u;
      v41 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
              UFG::NavManager::ms_pInstance,
              (UFG::HavokNavPosition *)&v10[1].m_SafePointerList.mNode.mNext,
              &vPoint,
              (UFG::NavParams *)&outside_combat_region,
              &last_valid_position);
      v22 = v22 && !v41;
    }
  }
  else
  {
    v21 = v8->m_pAIEntityComponent.m_pSimComponent->m_pSimObject;
    if ( v21 )
      v10 = UFG::SimObject::GetComponentOfType(v21, UFG::NavComponent::_TypeUID);
    outside_combat_region = *(bool **)((char *)&v10[2].m_BoundComponentHandles.mNode.mNext + 4);
    HIDWORD(outside_combat_region) |= 0x200u;
    v22 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
            UFG::NavManager::ms_pInstance,
            (UFG::HavokNavPosition *)&v10[1].m_SafePointerList.mNode.mNext,
            &vPoint,
            (UFG::NavParams *)&outside_combat_region,
            &last_valid_position) == 0;
  }
  if ( v50 )
  {
    v42 = (__m128)LODWORD(v13->mWorldTransform.v3.y);
    v42.m128_f32[0] = (float)((float)(v42.m128_f32[0] - last_valid_position.y)
                            * (float)(v42.m128_f32[0] - last_valid_position.y))
                    + (float)((float)(v13->mWorldTransform.v3.x - last_valid_position.x)
                            * (float)(v13->mWorldTransform.v3.x - last_valid_position.x));
    LODWORD(v43) = (unsigned __int128)_mm_sqrt_ps(v42);
    if ( v43 <= 1.0 )
      v43 = *(float *)&FLOAT_1_0;
    *v50 = v43;
  }
  return v22;
}                     * (float)(v13->mWorldTransform.v3.x - last_valid_position.x));
    LODWORD(v43) = 

// File Line: 2504
// RVA: 0x341A90
char __fastcall UFG::FormationManagerComponent::AngleIsClear(UFG::FormationManagerComponent *this, unsigned __int16 angle, UFG::GetInFormationNode *get_in_formation, float distance, bool force_physics_raycast)
{
  UFG::GetInFormationNode *v5; // rbx
  UFG::FormationManagerComponent *v6; // rdi
  float v7; // xmm7_4
  UFG::qVector3 direction; // [rsp+30h] [rbp-48h]

  v5 = get_in_formation;
  v6 = this;
  v7 = (float)((float)angle * 3.1415927) * 0.000030517578;
  direction.y = sinf(v7) * distance;
  direction.x = cosf(v7) * distance;
  direction.z = distance * 0.0;
  return UFG::FormationManagerComponent::DirectionIsClear(v6, &direction, v5, 0i64, 0i64, force_physics_raycast);
}

// File Line: 2519
// RVA: 0x388660
void __fastcall UFG::FormationManagerComponent::SpreadOutDesiredPositions(UFG::FormationManagerComponent *this, float delta_sec)
{
  int v2; // eax
  float v3; // xmm7_4
  UFG::FormationManagerComponent *v4; // r10
  int v5; // er11
  __int64 v6; // r13
  signed __int64 v7; // rbx
  signed __int64 v8; // rdi
  char *v9; // rdx
  signed __int64 v10; // rcx
  signed __int64 v11; // rsi
  int *v12; // r9
  __int64 v13; // rcx
  int v14; // er8
  float *v15; // rbp
  signed __int64 v16; // r12
  __int64 v17; // rdx
  __int64 v18; // rax
  __int64 v19; // r15
  signed __int64 v20; // rax
  _DWORD *v21; // r14
  int v22; // esi
  __int64 v23; // rdi
  signed __int64 v24; // rbx
  bool v25; // al
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm6_4
  int v29; // er12
  float v30; // xmm8_4
  char *v31; // r14
  signed __int64 v32; // r15
  int *v33; // rbp
  int v34; // esi
  float *v35; // rdi
  unsigned __int16 *v36; // rbx
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm7_4
  float v40; // xmm0_4
  float v41; // xmm3_4
  int v42; // [rsp+30h] [rbp-198h]
  __int64 v43; // [rsp+38h] [rbp-190h]
  signed __int64 v44; // [rsp+40h] [rbp-188h]
  char *v45; // [rsp+48h] [rbp-180h]
  signed __int64 v46; // [rsp+50h] [rbp-178h]
  __int64 v47; // [rsp+58h] [rbp-170h]
  signed __int64 v48; // [rsp+60h] [rbp-168h]
  char dest; // [rsp+70h] [rbp-158h]
  UFG::FormationManagerComponent *v50; // [rsp+1D0h] [rbp+8h]
  int v51; // [rsp+1E0h] [rbp+18h]
  int v52; // [rsp+1E8h] [rbp+20h]

  v50 = this;
  v2 = 0;
  v42 = 0;
  do
  {
    if ( v2 >= 10 )
      break;
    v3 = 0.0;
    UFG::qMemSet(&dest, 0, 0x80u);
    v4 = v50;
    v5 = 0;
    v6 = 0i64;
    v52 = 0;
    if ( v50->m_NumRanges > 0 )
    {
      v7 = (signed __int64)&v50->mStateVariables.m_FormationSlot[0][0].m_Angle;
      v8 = (signed __int64)v50->m_NumSlotsPerRange;
      v9 = &dest;
      v10 = -332i64 - (_QWORD)v50;
      v11 = (signed __int64)&v50->mStateVariables.m_FormationSlot[0][0].m_Angle;
      v46 = (signed __int64)&v50->mStateVariables.m_FormationSlot[0][0].m_Angle;
      v12 = v50->m_NumSlotsPerRange;
      v44 = (signed __int64)v50->m_NumSlotsPerRange;
      v45 = &dest;
      do
      {
        if ( *(UFG::eFormationManagerRingType *)((char *)v4->mStateVariables.m_pCurrentProfile->m_RingType
                                               + v10
                                               + (unsigned __int64)v12) == eRING_TYPE_FLUID )
        {
          v13 = 0i64;
          v14 = 0;
          v51 = 0;
          v43 = 0i64;
          if ( *v12 > 0 )
          {
            v15 = (float *)v9;
            v16 = v11;
            do
            {
              v17 = *(_QWORD *)(v16 + 52);
              v47 = v17;
              if ( v17 )
              {
                if ( *(_QWORD *)(v16 + 76) )
                {
                  if ( !*(_BYTE *)(v16 + 132) )
                  {
                    v18 = *(_QWORD *)(v17 + 104);
                    if ( !v18 || !*(_BYTE *)(v18 + 96) )
                    {
                      v19 = 0i64;
                      if ( v6 >= 0 )
                      {
                        v20 = v7;
                        v48 = v7;
                        v21 = (_DWORD *)v8;
                        do
                        {
                          v22 = 0;
                          v23 = 0i64;
                          if ( *v21 > 0 )
                          {
                            v24 = v20;
                            do
                            {
                              v25 = v19 == v6 && v23 == v13;
                              if ( *(_QWORD *)(v24 + 76) && !v25 )
                              {
                                v26 = (float)((float)(unsigned __int16)(*(_WORD *)v16 - *(_WORD *)v24) * 360.0)
                                    * 0.000015258789;
                                LODWORD(v27) = LODWORD(v26) & _xmm;
                                if ( COERCE_FLOAT(LODWORD(v26) & _xmm) < 45.0 )
                                {
                                  if ( v3 <= v27 )
                                    LODWORD(v3) = LODWORD(v26) & _xmm;
                                  if ( v27 <= 1.0 )
                                    v27 = *(float *)&FLOAT_1_0;
                                  v28 = 20.0 / v27;
                                  if ( v26 < 0.0 )
                                    LODWORD(v28) ^= _xmm[0];
                                  if ( *(_QWORD *)(v16 + 76) && !*(_DWORD *)(v17 + 52)
                                    || UFG::FormationManagerComponent::NewAngleDoesntCrossOverSomeone(
                                         v4,
                                         v5,
                                         v14,
                                         *(_WORD *)v16
                                       + (signed int)(float)((float)((float)(v28 + *v15) * 65536.0) * 0.0027777778)) )
                                  {
                                    *v15 = v28 + *v15;
                                  }
                                }
                                v13 = v43;
                              }
                              v17 = v47;
                              v14 = v51;
                              v4 = v50;
                              v5 = v52;
                              ++v22;
                              ++v23;
                              v24 += 200i64;
                            }
                            while ( v22 < *v21 );
                            v20 = v48;
                          }
                          v20 += 1600i64;
                          ++v19;
                          ++v21;
                          v48 = v20;
                        }
                        while ( v19 <= v6 );
                        v12 = (int *)v44;
                        v7 = (signed __int64)&v4->mStateVariables.m_FormationSlot[0][0].m_Angle;
                        v8 = (signed __int64)v4->m_NumSlotsPerRange;
                      }
                    }
                  }
                }
              }
              ++v14;
              ++v13;
              v16 += 200i64;
              ++v15;
              v51 = v14;
              v43 = v13;
            }
            while ( v14 < *v12 );
            v9 = v45;
            v11 = v46;
          }
        }
        v10 = -332i64 - (_QWORD)v50;
        ++v5;
        ++v12;
        v9 += 32;
        v11 += 1600i64;
        ++v6;
        v52 = v5;
        v44 = (signed __int64)v12;
        v45 = v9;
        v46 = v11;
      }
      while ( v5 < v4->m_NumRanges );
    }
    v29 = 0;
    v30 = 0.0;
    if ( v4->m_NumRanges > 0 )
    {
      v31 = &dest;
      v32 = (signed __int64)&v4->mStateVariables.m_FormationSlot[0][0].m_Angle;
      v33 = v4->m_NumSlotsPerRange;
      do
      {
        v34 = 0;
        if ( *v33 > 0 )
        {
          v35 = (float *)v31;
          v36 = (unsigned __int16 *)v32;
          do
          {
            v37 = *v35;
            if ( v30 <= *v35 )
              v30 = *v35;
            if ( v37 > 0.1 )
            {
              if ( UFG::FormationManagerComponent::AngleIsClear(
                     v4,
                     *v36 + (signed int)(float)((float)(v37 * 65536.0) * 0.0027777778),
                     *(UFG::GetInFormationNode **)(v36 + 26),
                     *((float *)v36 + 1),
                     0) )
              {
                *v36 += (signed int)(float)((float)(*v35 * 65536.0) * 0.0027777778);
                v38 = (float)((float)*v36 * 3.1415927) * 0.000030517578;
                v39 = sinf(v38);
                v40 = cosf(v38);
                v41 = *((float *)v36 + 1) / fsqrt((float)(v40 * v40) + (float)(v39 * v39));
                *((float *)v36 - 1) = v41 * 0.0;
                *((float *)v36 - 3) = v40 * v41;
                *((float *)v36 - 2) = v39 * v41;
              }
              v4 = v50;
            }
            ++v34;
            v36 += 100;
            ++v35;
          }
          while ( v34 < *v33 );
        }
        ++v29;
        ++v33;
        v31 += 32;
        v32 += 1600i64;
      }
      while ( v29 < v4->m_NumRanges );
    }
    v2 = v42++ + 1;
  }
  while ( v30 > 2.0 );
}

// File Line: 2650
// RVA: 0x358100
signed __int64 __fastcall UFG::FormationManagerComponent::FindRangeIndex(UFG::FormationManagerComponent *this, UFG::SimObject *sim_object)
{
  __int64 v2; // rsi
  unsigned int v3; // edi
  __int64 v4; // r10
  UFG::SimObject **v5; // r11
  int *v6; // rbx
  __int64 v7; // r8
  __int64 v8; // rcx
  UFG::SimObject **v9; // rax

  if ( !sim_object )
    return 0xFFFFFFFFi64;
  v2 = this->m_NumRanges;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v5 = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  v6 = this->m_NumSlotsPerRange;
  while ( 1 )
  {
    v7 = *v6;
    v8 = 0i64;
    if ( v7 > 0 )
      break;
LABEL_9:
    ++v4;
    ++v3;
    ++v6;
    v5 += 200;
    if ( v4 >= v2 )
      return 0xFFFFFFFFi64;
  }
  v9 = v5;
  while ( !*v9 || *v9 != sim_object )
  {
    ++v8;
    v9 += 25;
    if ( v8 >= v7 )
      goto LABEL_9;
  }
  return v3;
}

// File Line: 2672
// RVA: 0x357FC0
char __fastcall UFG::FormationManagerComponent::FindRangeAndSlotIndex(UFG::FormationManagerComponent *this, UFG::HasAttackRequestNode *has_attack_request_node, int *range_index, int *slot_index)
{
  UFG::HasAttackRequestNode *v4; // r15
  int v5; // edx
  __int64 v6; // r13
  __int64 v7; // r8
  UFG::SimObject **v8; // rax
  int *v9; // rcx
  __int64 v10; // r12
  int v11; // er14
  __int64 v12; // rdi
  UFG::SimObject **v13; // rbx
  UFG::SimObject *v14; // rbp
  __int64 v15; // rsi
  __int64 v17; // [rsp+20h] [rbp-58h]
  int *v18; // [rsp+28h] [rbp-50h]
  UFG::SimObject **v19; // [rsp+30h] [rbp-48h]
  int v20; // [rsp+88h] [rbp+10h]
  int *v21; // [rsp+90h] [rbp+18h]
  int *v22; // [rsp+98h] [rbp+20h]

  v22 = slot_index;
  v21 = range_index;
  v4 = has_attack_request_node;
  if ( !has_attack_request_node )
    return 0;
  v5 = 0;
  v6 = 0i64;
  v20 = 0;
  v17 = this->m_NumRanges;
  if ( v17 <= 0 )
    return 0;
  v7 = this->m_NumRanges;
  v8 = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  v9 = this->m_NumSlotsPerRange;
  v19 = v8;
  v18 = v9;
  while ( 1 )
  {
    v10 = *v9;
    v11 = 0;
    v12 = 0i64;
    if ( v10 > 0 )
      break;
LABEL_12:
    ++v5;
    ++v9;
    v8 += 200;
    ++v6;
    v20 = v5;
    v18 = v9;
    v19 = v8;
    if ( v6 >= v7 )
      return 0;
  }
  v13 = v8;
  while ( 1 )
  {
    v15 = (__int64)*(v13 - 3);
    if ( *v13 )
    {
      v14 = *v13;
      if ( v14 == UFG::HasAttackRequestNode::GetSimObject(v4) && v15 && *(_DWORD *)(v15 + 52) == v4->m_AttackType )
        break;
    }
    ++v12;
    ++v11;
    v13 += 25;
    if ( v12 >= v10 )
    {
      v8 = v19;
      v9 = v18;
      v5 = v20;
      v7 = v17;
      goto LABEL_12;
    }
  }
  *v21 = v20;
  *v22 = v11;
  return 1;
}

// File Line: 2701
// RVA: 0x36B9B0
bool __fastcall UFG::FormationManagerComponent::IsRegistered(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation)
{
  __int64 v2; // r8
  __int64 v3; // rax

  if ( !get_in_formation )
    return 0;
  v2 = get_in_formation->m_RangeIndex;
  v3 = get_in_formation->m_SlotIndex;
  return (_DWORD)v2 != -1
      && (_DWORD)v3 != -1
      && this->mStateVariables.m_FormationSlot[0][v3 + 8 * v2].m_pMember.m_pPointer == get_in_formation;
}

// File Line: 2740
// RVA: 0x35DDF0
__int64 __fastcall UFG::FormationManagerComponent::GetDesiredRange(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation)
{
  UFG::SimComponent *v2; // r15
  UFG::eFormationRangePreference v3; // ebp
  UFG::FormationManagerComponent *v4; // rsi
  UFG::GetInFormationNode *v5; // rbx
  unsigned int v6; // edi
  UFG::SimComponent *v7; // r14
  int v8; // ebx
  UFG::SimObject *v9; // r14
  UFG::TransformNodeComponent *v10; // r14
  __m128 v11; // xmm0
  float v12; // xmm2_4
  int v13; // ebp
  int v14; // ebp
  int v15; // ebp
  signed int v16; // ebp
  __int64 v17; // r10
  signed int v18; // er11
  int *v19; // r8
  __int64 v20; // rdx
  float v21; // xmm0_4
  __int64 v22; // r9
  float v23; // xmm0_4
  __int64 v24; // rdx
  float v25; // xmm0_4
  __int64 v26; // rdx
  float v27; // xmm0_4
  signed __int64 v28; // rdx
  __int64 v29; // rcx
  float v30; // xmm0_4
  int v31; // eax
  _DWORD *v32; // rcx
  int v33; // edx
  int v34; // eax
  _DWORD *v35; // rcx
  int v36; // ecx
  int *v37; // rax

  v2 = this->m_pTransformNodeComponent.m_pSimComponent;
  v3 = get_in_formation->m_RangePreference;
  v4 = this;
  v5 = get_in_formation;
  v6 = -1;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
  v7 = v5->m_pOwner.m_pPointer;
  v8 = 0;
  if ( v7 && (v9 = v7->m_pSimObject) != 0i64 )
    v10 = v9->m_pTransformNodeComponent;
  else
    v10 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v10);
  v11 = (__m128)LODWORD(v10->mWorldTransform.v3.y);
  v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] - *((float *)&v2[2].m_BoundComponentHandles.mNode.mPrev + 1))
                          * (float)(v11.m128_f32[0] - *((float *)&v2[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                  + (float)((float)(v10->mWorldTransform.v3.x - *(float *)&v2[2].m_BoundComponentHandles.mNode.mPrev)
                          * (float)(v10->mWorldTransform.v3.x - *(float *)&v2[2].m_BoundComponentHandles.mNode.mPrev));
  LODWORD(v12) = (unsigned __int128)_mm_sqrt_ps(v11);
  v13 = v3 - 1;
  if ( !v13 )
  {
    v36 = v4->m_NumRanges;
    if ( v36 > 0 )
    {
      v37 = v4->m_NumFreeSlotsPerRange;
      do
      {
        if ( v6 != -1 )
          break;
        if ( *v37 > 0 )
          v6 = v8;
        ++v8;
        ++v37;
      }
      while ( v8 < v36 );
    }
    return v6;
  }
  v14 = v13 - 1;
  if ( !v14 )
  {
    v33 = v4->m_NumRanges;
    v34 = v33 - 2;
    if ( v33 - 2 < v33 )
    {
      v35 = (_DWORD *)((char *)v4 + 4 * (v34 + 91i64));
      do
      {
        if ( v6 != -1 )
          break;
        if ( *v35 > 0 )
          v6 = v34;
        ++v34;
        ++v35;
      }
      while ( v34 < v33 );
    }
    return v6;
  }
  v15 = v14 - 1;
  if ( !v15 )
    goto LABEL_58;
  if ( v15 != 1 )
    return v6;
  v16 = v4->m_NumRanges;
  v17 = 0i64;
  if ( v16 < 4 )
  {
LABEL_45:
    if ( v8 < v16 )
    {
      v28 = 4 * v17 + 20;
      while ( v6 == -1 )
      {
        if ( *(int *)((char *)&v4->m_NumSlotsPerRange[3] + v28) > 0 )
        {
          v29 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
          if ( v8 < 0 || (_DWORD)v29 == -1 )
          {
            v30 = 0.0;
          }
          else
          {
            v30 = *(float *)((char *)&v4->mStateVariables.m_pCurrentProfile->m_NameID.mUID + v28);
            if ( v30 < 0.0 )
              v30 = v4->m_BattleTypeSpecificParameters[0].m_MaxDistance[v17 + 12 * v29];
          }
          if ( v30 > v12 )
            v6 = v8;
        }
        ++v8;
        ++v17;
        v28 += 4i64;
        if ( v8 >= v16 )
          goto LABEL_57;
      }
      return v6;
    }
LABEL_57:
    if ( v6 != -1 )
      return v6;
LABEL_58:
    v31 = v4->m_NumRanges - 1;
    if ( v31 >= 0 )
    {
      v32 = (_DWORD *)((char *)v4 + 4 * (v31 + 91i64));
      do
      {
        if ( v6 != -1 )
          break;
        if ( *v32 > 0 )
          v6 = v31;
        --v32;
        --v31;
      }
      while ( v31 >= 0 );
    }
    return v6;
  }
  v18 = 2;
  v19 = &v4->m_NumFreeSlotsPerRange[1];
  while ( v6 == -1 )
  {
    if ( *(v19 - 1) > 0 )
    {
      v20 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      if ( v8 < 0 || (_DWORD)v20 == -1 )
      {
        v21 = 0.0;
      }
      else
      {
        v21 = *(float *)((char *)&v4->mStateVariables.m_pCurrentProfile[-3].m_NameID.mUID
                       + (unsigned __int64)v19
                       - (_QWORD)v4);
        if ( v21 < 0.0 )
          v21 = v4->m_BattleTypeSpecificParameters[0].m_MaxDistance[v17 + 12 * v20];
      }
      if ( v12 < v21 )
      {
        v6 = v8;
        if ( v8 != -1 )
          break;
      }
    }
    if ( *v19 > 0 )
    {
      v22 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      if ( v18 - 1 < 0 || (_DWORD)v22 == -1 )
      {
        v23 = 0.0;
      }
      else
      {
        v23 = *(float *)((char *)&v4->mStateVariables.m_pCurrentProfile[-2] + (unsigned __int64)v19 - (_QWORD)v4 - 112);
        if ( v23 < 0.0 )
          v23 = v4->m_BattleTypeSpecificParameters[0].m_MaxDistance[v17 + 12 * v22 + 1];
      }
      if ( v12 < v23 )
      {
        v6 = v18 - 1;
        if ( v18 != 0 )
          break;
      }
    }
    if ( v19[1] > 0 )
    {
      v24 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      if ( v18 < 0 || (_DWORD)v24 == -1 )
      {
        v25 = 0.0;
      }
      else
      {
        v25 = *(float *)((char *)&v4->mStateVariables.m_pCurrentProfile[-2] + (unsigned __int64)v19 - (_QWORD)v4 - 108);
        if ( v25 < 0.0 )
          v25 = v4->m_BattleTypeSpecificParameters[0].m_MaxDistance[v17 + 12 * v24 + 2];
      }
      if ( v12 < v25 )
      {
        v6 = v18;
        if ( v18 != -1 )
          break;
      }
    }
    if ( v19[2] > 0 )
    {
      v26 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      if ( v18 + 1 < 0 || (_DWORD)v26 == -1 )
      {
        v27 = 0.0;
      }
      else
      {
        v27 = *(float *)((char *)&v4->mStateVariables.m_pCurrentProfile[-2] + (unsigned __int64)v19 - (_QWORD)v4 - 104);
        if ( v27 < 0.0 )
          v27 = v4->m_BattleTypeSpecificParameters[0].m_MaxDistance[v17 + 12 * v26 + 3];
      }
      if ( v27 > v12 )
        v6 = v18 + 1;
    }
    v8 += 4;
    v17 += 4i64;
    v19 += 4;
    v18 += 4;
    if ( v8 >= v16 - 3 )
      goto LABEL_45;
  }
  return v6;
}

// File Line: 2827
// RVA: 0x37F370
char __fastcall UFG::FormationManagerComponent::RangeMeetsPreference(UFG::FormationManagerComponent *this, int range_index, UFG::eFormationRangePreference range_preference)
{
  __int32 v3; // er8
  int v4; // er8
  int v5; // er8

  if ( range_index == -1 )
    return 0;
  if ( range_preference )
  {
    v3 = range_preference - 1;
    if ( !v3 )
      return range_index == 0;
    v4 = v3 - 1;
    if ( !v4 )
      return range_index == this->m_NumRanges - 2;
    v5 = v4 - 1;
    if ( !v5 )
      return range_index != 0;
    if ( v5 != 1 )
      return 0;
  }
  return 1;
}

// File Line: 2885
// RVA: 0x382570
char __fastcall UFG::FormationManagerComponent::RequestRegistration(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation)
{
  UFG::GetInFormationNode *v2; // rbx
  UFG::FormationManagerComponent *v3; // rdi
  __int64 v4; // rcx
  __int64 v5; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  int v8; // eax

  v2 = get_in_formation;
  v3 = this;
  if ( get_in_formation )
  {
    v4 = get_in_formation->m_RangeIndex;
    v5 = get_in_formation->m_SlotIndex;
    if ( (_DWORD)v4 != -1
      && (_DWORD)v5 != -1
      && v3->mStateVariables.m_FormationSlot[0][v5 + 8 * v4].m_pMember.m_pPointer == get_in_formation )
    {
      return 0;
    }
  }
  if ( !v3->m_pTransformNodeComponent.m_pSimComponent )
    return 0;
  v6 = get_in_formation->m_pOwner.m_pPointer;
  if ( !v6 )
    return 0;
  v7 = v6->m_pSimObject;
  if ( !v7 )
    return 0;
  if ( !v7->m_pTransformNodeComponent )
    return 0;
  v8 = UFG::FormationManagerComponent::GetDesiredRange(v3, get_in_formation);
  if ( v8 == -1 )
    return 0;
  UFG::FormationManagerComponent::Register(v3, v2, v8, 1);
  return 1;
}

// File Line: 2912
// RVA: 0x3806D0
void __fastcall UFG::FormationManagerComponent::Register(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation, int range_index, bool allowed_to_switch_to_range_preference)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v4; // rsi
  __int64 v5; // r12
  UFG::FormationManagerComponent *v6; // rdi
  int v7; // ecx
  int v8; // er14
  bool v9; // r13
  UFG::GetInFormationNode *v10; // r15
  int v11; // er10
  UFG::GetInFormationNode **v12; // r9
  signed __int64 v13; // rbx
  UFG::SimComponent *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx

  v4 = 0i64;
  v5 = range_index;
  v6 = this;
  v7 = this->m_NumSlotsPerRange[range_index];
  v8 = -1;
  v9 = allowed_to_switch_to_range_preference;
  v10 = get_in_formation;
  v11 = 0;
  if ( v7 > 0 )
  {
    v12 = &v6->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer + 200 * range_index;
    while ( *v12 )
    {
      ++v11;
      v12 += 25;
      if ( v11 >= v7 )
        goto LABEL_7;
    }
    v8 = v11;
  }
LABEL_7:
  UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(v6, range_index, v8, get_in_formation);
  v13 = 200 * (v8 + 8 * v5);
  UFG::FormationSlot::SetFormationMember((UFG::FormationSlot *)((char *)v6->mStateVariables.m_FormationSlot + v13), v10);
  v6->mStateVariables.m_FormationSlot[0][(unsigned __int64)v13 / 0xC8].m_FacingType = v6->m_FormationFacingType;
  UFG::FormationSlot::SetRadialHysteresisModifier((UFG::FormationSlot *)((char *)v6->mStateVariables.m_FormationSlot
                                                                       + v13));
  v14 = v10->m_pOwner.m_pPointer;
  v10->m_RangeIndex = v5;
  v10->m_SlotIndex = v8;
  v10->m_AllowedToSwitchToRangePreference = v9;
  if ( v14 )
    v4 = v14[2].vfptr;
  v15 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4[207];
  if ( v4[209].__vecDelDtor )
  {
    v16 = v15->mPrev;
    v17 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v4[208].__vecDelDtor;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = v15;
    v4[208].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v4[207];
  }
  v4[209].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v6;
  v18 = v6->m_SafePointerList.mNode.mPrev;
  v18->mNext = v15;
  v15->mPrev = v18;
  v4[208].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v6->m_SafePointerList;
  v6->m_SafePointerList.mNode.mPrev = v15;
  --v6->m_NumFreeSlotsPerRange[v5];
}

// File Line: 2950
// RVA: 0x382660
void __fastcall UFG::FormationManagerComponent::Reregister(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation, int new_range_index, bool allowed_to_switch_to_range_preference)
{
  bool v4; // bp
  __int64 v5; // rsi
  UFG::GetInFormationNode *v6; // rbx
  UFG::FormationManagerComponent *v7; // rdi
  __int64 v8; // rdx
  __int64 v9; // r8

  v4 = allowed_to_switch_to_range_preference;
  v5 = new_range_index;
  v6 = get_in_formation;
  v7 = this;
  if ( get_in_formation )
  {
    v8 = get_in_formation->m_RangeIndex;
    v9 = v6->m_SlotIndex;
    if ( (_DWORD)v8 != -1
      && (_DWORD)v9 != -1
      && this->mStateVariables.m_FormationSlot[0][v9 + 8 * v8].m_pMember.m_pPointer == v6 )
    {
      UFG::FormationManagerComponent::Unregister(this, v8, v9);
    }
  }
  UFG::FormationManagerComponent::Register(v7, v6, v5, v4);
  UFG::FormationManagerComponent::SetTimeToDoSomething(
    v7,
    v7->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[v5
                                                                       + 12i64
                                                                       * (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType],
    v7->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[v5
                                                                       + 12i64
                                                                       * (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType],
    &v7->mStateVariables.m_NextTimeToSwitchFromRange[v5]);
}

// File Line: 2958
// RVA: 0x385F30
void __fastcall UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation)
{
  __int64 v2; // r10
  __int64 v3; // r8

  if ( get_in_formation )
  {
    v2 = get_in_formation->m_RangeIndex;
    v3 = get_in_formation->m_SlotIndex;
    if ( (_DWORD)v2 != -1
      && (_DWORD)v3 != -1
      && this->mStateVariables.m_FormationSlot[0][v3 + 8 * v2].m_pMember.m_pPointer == get_in_formation )
    {
      UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(this, v2, v3, get_in_formation);
    }
  }
}

// File Line: 2967
// RVA: 0x385E30
void __fastcall UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(UFG::FormationManagerComponent *this, int range_index, int slot_index, UFG::GetInFormationNode *get_in_formation)
{
  UFG::TransformNodeComponent *v4; // rsi
  UFG::GetInFormationNode *v5; // rdi
  int v6; // er14
  int v7; // er15
  UFG::FormationManagerComponent *v8; // rbp
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // rcx
  UFG::SimComponent *v11; // rbx
  UFG::SimObject *v12; // rbx
  UFG::TransformNodeComponent *v13; // rbx
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qVector3 desired_direction; // [rsp+30h] [rbp-28h]

  v4 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v5 = get_in_formation;
  v6 = slot_index;
  v7 = range_index;
  v8 = this;
  if ( v4 )
  {
    if ( get_in_formation )
    {
      v9 = get_in_formation->m_pOwner.m_pPointer;
      if ( v9 )
      {
        v10 = v9->m_pSimObject;
        if ( v10 )
        {
          if ( v10->m_pTransformNodeComponent )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v4);
            v11 = v5->m_pOwner.m_pPointer;
            if ( v11 && (v12 = v11->m_pSimObject) != 0i64 )
              v13 = v12->m_pTransformNodeComponent;
            else
              v13 = 0i64;
            UFG::TransformNodeComponent::UpdateWorldTransform(v13);
            v14 = v13->mWorldTransform.v3.y - v4->mWorldTransform.v3.y;
            desired_direction.x = v13->mWorldTransform.v3.x - v4->mWorldTransform.v3.x;
            v15 = v13->mWorldTransform.v3.z;
            desired_direction.y = v14;
            desired_direction.z = v15 - v4->mWorldTransform.v3.z;
            UFG::FormationManagerComponent::SetDesiredDirection(v8, v7, v6, v5, &desired_direction);
          }
        }
      }
    }
  }
}

// File Line: 2980
// RVA: 0x385580
void __fastcall UFG::FormationManagerComponent::SetDesiredDirection(UFG::FormationManagerComponent *this, int range_index, int slot_index, UFG::GetInFormationNode *get_in_formation, UFG::qVector3 *desired_direction)
{
  UFG::SimComponent *v5; // rax
  UFG::GetInFormationNode *v6; // r15
  __int64 v7; // r13
  __int64 v8; // rsi
  UFG::FormationManagerComponent *v9; // rbx
  __int64 v10; // rdi
  UFG::TransformNodeComponent *v11; // rbp
  UFG::qVector3 *v12; // r12
  __m128 v13; // xmm0
  __int64 v14; // rdx
  float v15; // xmm1_4
  int v16; // ecx
  float v17; // xmm9_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  UFG::qVector3 *v22; // r14
  float v23; // xmm8_4
  __m128 v24; // xmm7
  __m128 v25; // xmm1
  signed __int64 v26; // rdi
  float v27; // xmm2_4
  float v28; // xmm7_4
  float v29; // xmm8_4
  float v30; // xmm10_4
  float v31; // xmm11_4
  float v32; // xmm8_4
  __m128 v33; // xmm7
  __m128 v34; // xmm1
  float v35; // xmm0_4
  float v36; // xmm10_4
  float v37; // xmm11_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  bool v40; // al
  unsigned int v41; // er8
  bool v42; // dl
  float v43; // xmm0_4
  float v44; // xmm2_4
  bool v45; // al
  float v46; // xmm0_4
  bool v47; // cl
  int v48; // ebx
  float v49; // xmm0_4
  float current_lateral_offset; // [rsp+40h] [rbp-B8h]
  UFG::qVector3 direction; // [rsp+48h] [rbp-B0h]
  char v52; // [rsp+100h] [rbp+8h]
  float max_clear_distance; // [rsp+118h] [rbp+20h]

  v5 = get_in_formation->m_pOwner.m_pPointer;
  v6 = get_in_formation;
  v7 = slot_index;
  v8 = range_index;
  v9 = this;
  if ( v5 )
    v5 = (UFG::SimComponent *)v5->m_pSimObject;
  v10 = *(_QWORD *)&v5[1].m_TypeUID;
  if ( this->m_pTransformNodeComponent.m_pSimComponent && v10 )
  {
    v11 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v11);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10);
    v12 = (UFG::qVector3 *)(v10 + 176);
    v13 = (__m128)*(unsigned int *)(v10 + 180);
    v14 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
    v15 = *(float *)(v10 + 176) - v11->mWorldTransform.v3.x;
    v16 = v8 - 1;
    v52 = 1;
    v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] - v11->mWorldTransform.v3.y)
                            * (float)(v13.m128_f32[0] - v11->mWorldTransform.v3.y))
                    + (float)(v15 * v15);
    LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v13);
    v18 = v17;
    if ( (signed int)v8 - 1 < 0 || (_DWORD)v14 == -1 )
    {
      v19 = 0.0;
    }
    else
    {
      v19 = v9->mStateVariables.m_pCurrentProfile->m_MaxDistanceOverride[v16];
      if ( v19 < 0.0 )
        v19 = v9->m_BattleTypeSpecificParameters[0].m_MaxDistance[v16 + 12 * v14];
    }
    if ( (signed int)v8 < 0 || (_DWORD)v14 == -1 )
    {
      v20 = 0.0;
    }
    else
    {
      v20 = v9->mStateVariables.m_pCurrentProfile->m_MaxDistanceOverride[v8];
      if ( v20 < 0.0 )
        v20 = v9->m_BattleTypeSpecificParameters[0].m_MaxDistance[v8 + 12 * v14];
    }
    if ( v17 <= v19 )
      v21 = v19;
    else
      v21 = v17;
    if ( v21 >= v20 )
      v21 = v20;
    if ( v17 != v21 )
    {
      v52 = 0;
      v18 = (float)(v20 + v19) * 0.5;
    }
    v22 = desired_direction;
    v23 = desired_direction->y;
    v24 = (__m128)LODWORD(desired_direction->x);
    v25 = v24;
    v26 = (signed __int64)v9->mStateVariables.m_FormationSlot + 200 * (v7 + 8 * v8);
    v25.m128_f32[0] = (float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23);
    direction.z = 0.0;
    max_clear_distance = 0.0;
    v27 = v18 / COERCE_FLOAT(_mm_sqrt_ps(v25));
    v28 = v24.m128_f32[0] * v27;
    v29 = v23 * v27;
    v30 = v28;
    v31 = v29;
    direction.x = v28;
    direction.y = v29;
    if ( !UFG::FormationManagerComponent::DirectionIsClear(v9, &direction, v6, &max_clear_distance, 0i64, 0) )
    {
      v32 = v22->y;
      v33 = (__m128)LODWORD(v22->x);
      v18 = max_clear_distance;
      v34 = v33;
      v34.m128_f32[0] = (float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32);
      v35 = max_clear_distance / COERCE_FLOAT(_mm_sqrt_ps(v34));
      v28 = v33.m128_f32[0] * v35;
      v29 = v32 * v35;
      v30 = v28;
      v31 = v29;
    }
    v36 = v30 + v11->mWorldTransform.v3.x;
    v37 = v31 + v11->mWorldTransform.v3.y;
    v38 = v9->m_MaxRadialDistanceFromDesiredPosition[v8];
    direction.z = v11->mWorldTransform.v3.z;
    v39 = v9->m_MaxLateralDistanceFromDesiredPosition[v8];
    current_lateral_offset = 0.0;
    max_clear_distance = 0.0;
    direction.x = v36;
    direction.y = v37;
    v40 = UFG::FormationManagerComponent::IsInPosition(
            v9,
            v12,
            &direction,
            v38,
            v39,
            &max_clear_distance,
            &current_lateral_offset,
            0);
    v41 = *(_DWORD *)(v26 + 32);
    v42 = v40;
    v43 = *(float *)&FLOAT_1_0;
    v44 = *(float *)&FLOAT_1_0;
    if ( v41 <= 1 )
    {
      v43 = FLOAT_2_0;
      v44 = FLOAT_2_0;
    }
    v45 = max_clear_distance <= v43 && current_lateral_offset <= v44;
    if ( v9->mStateVariables.m_CurrentlySprinting )
      v46 = v9->m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
    else
      v46 = (float)(v9->m_MaxRadialDistanceFromDesiredPositionHysteresis[v8]
                  + v9->m_MaxRadialDistanceFromDesiredPosition[v8])
          + 5.0;
    v47 = max_clear_distance >= v46 && v17 > (float)(max_clear_distance + 1.0);
    v48 = 0;
    if ( v47 )
      goto LABEL_47;
    if ( v41 != 3 )
    {
      if ( !v42 )
        v48 = 2 - (v45 != 0);
      goto LABEL_41;
    }
    if ( !v42 )
LABEL_47:
      v48 = 3;
LABEL_41:
    *(float *)v26 = v28;
    *(float *)(v26 + 4) = v29;
    *(_DWORD *)(v26 + 8) = 0;
    v49 = atan2f(v29, v28);
    *(float *)(v26 + 16) = v18;
    *(_WORD *)(v26 + 12) = (signed int)(float)((float)(v49 * 32768.0) * 0.31830987);
    *(_BYTE *)(v26 + 40) = v52;
    UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)v26, (UFG::eInFormationPositionType)v48);
  }
}

// File Line: 3103
// RVA: 0x38A2F0
void __fastcall UFG::FormationManagerComponent::Unregister(UFG::FormationManagerComponent *this, int range_index, int slot_index)
{
  __int64 v3; // rsi
  UFG::FormationManagerComponent *v4; // rdi
  UFG::FormationSlot (*v5)[8]; // rcx
  signed __int64 v6; // rdx
  UFG::GetInFormationNode *v7; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v12; // rdx
  __int64 *v13; // rdx
  __int64 v14; // rcx
  _QWORD *v15; // rax

  v3 = range_index;
  v4 = this;
  v5 = this->mStateVariables.m_FormationSlot;
  v6 = slot_index + 8i64 * range_index;
  v7 = (*v5)[v6].m_pMember.m_pPointer;
  UFG::FormationSlot::SetFormationMember(&(*v5)[v6], 0i64);
  if ( v7 )
  {
    v8 = &v7->m_pTargetFormationManagerComponent;
    *(_QWORD *)&v7->m_RangeIndex = -1i64;
    if ( v7->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v7->m_pTargetFormationManagerComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v7->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->m_pTargetFormationManagerComponent.mPrev;
    }
    v7->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
    v11 = v7->m_pOwner.m_pPointer;
    if ( v11 )
      v12 = v11[2].vfptr;
    else
      v12 = 0i64;
    v13 = (__int64 *)&v12[207];
    if ( v13[2] )
    {
      v14 = *v13;
      v15 = (_QWORD *)v13[1];
      *(_QWORD *)(v14 + 8) = v15;
      *v15 = v14;
      *v13 = (__int64)v13;
      v13[1] = (__int64)v13;
    }
    v13[2] = 0i64;
    ++v4->m_NumFreeSlotsPerRange[v3];
  }
}

// File Line: 3125
// RVA: 0x382360
char __fastcall UFG::FormationManagerComponent::RequestChangePosition(UFG::FormationManagerComponent *this, UFG::SimObject *sim_object, UFG::FormationPositionChangeRequest *request)
{
  __int64 v3; // rbp
  int v4; // esi
  __int64 v5; // r11
  UFG::FormationPositionChangeRequest *v6; // r15
  UFG::SimObject *v7; // r9
  UFG::FormationManagerComponent *v8; // r14
  UFG::GetInFormationNode **v9; // rbx
  int *v10; // rdi
  __int64 v11; // r10
  int v12; // er8
  __int64 v13; // rdx
  UFG::GetInFormationNode **v14; // rcx
  UFG::GetInFormationNode *v15; // rax
  UFG::SimObject *v16; // rax
  signed __int64 v18; // rdi
  UFG::eInFormationPositionType v19; // ebx

  v3 = this->m_NumRanges;
  v4 = 0;
  v5 = 0i64;
  v6 = request;
  v7 = sim_object;
  v8 = this;
  if ( v3 <= 0 )
    return 0;
  v9 = &this->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer;
  v10 = this->m_NumSlotsPerRange;
  while ( 1 )
  {
    v11 = *v10;
    v12 = 0;
    v13 = 0i64;
    if ( v11 > 0 )
      break;
LABEL_11:
    ++v5;
    ++v4;
    ++v10;
    v9 += 200;
    if ( v5 >= v3 )
      return 0;
  }
  v14 = v9;
  while ( 1 )
  {
    v15 = *v14;
    if ( v7 && v15 )
    {
      v16 = (UFG::SimObject *)v15->m_pOwner.m_pPointer;
      if ( v16 )
        v16 = (UFG::SimObject *)v16->mNode.mParent;
      if ( v16 == v7 )
        break;
    }
    ++v13;
    ++v12;
    v14 += 25;
    if ( v13 >= v11 )
      goto LABEL_11;
  }
  v18 = (signed __int64)v8->mStateVariables.m_FormationSlot + 200 * (v12 + 8i64 * v4);
  v19 = *(_DWORD *)(v18 + 32);
  UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
    v8,
    v4,
    v12,
    *(UFG::GetInFormationNode **)(v18 + 64));
  UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)v18, v19);
  *(_BYTE *)(v18 + 120) = 1;
  *(_DWORD *)(v18 + 124) = v6->m_DesiredSpeed;
  *(_DWORD *)(v18 + 128) = *(_DWORD *)&v6->m_Clockwise;
  *(_DWORD *)(v18 + 132) = v6->m_FacingType;
  *(_DWORD *)(v18 + 136) = *(_DWORD *)&v6->m_AbsolutePosition;
  return 1;
}

// File Line: 3151
// RVA: 0x382480
char __fastcall UFG::FormationManagerComponent::RequestInvalidatePosition(UFG::FormationManagerComponent *this, UFG::SimObject *sim_object)
{
  __int64 v2; // r14
  int v3; // esi
  __int64 v4; // r11
  UFG::SimObject *v5; // r9
  UFG::FormationManagerComponent *v6; // rbp
  UFG::GetInFormationNode **v7; // rbx
  int *v8; // rdi
  __int64 v9; // r10
  int v10; // er8
  __int64 v11; // rdx
  UFG::GetInFormationNode **v12; // rcx
  UFG::GetInFormationNode *v13; // rax
  UFG::SimObject *v14; // rax
  signed __int64 v16; // rbx

  v2 = this->m_NumRanges;
  v3 = 0;
  v4 = 0i64;
  v5 = sim_object;
  v6 = this;
  if ( v2 <= 0 )
    return 0;
  v7 = &this->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer;
  v8 = this->m_NumSlotsPerRange;
  while ( 1 )
  {
    v9 = *v8;
    v10 = 0;
    v11 = 0i64;
    if ( v9 > 0 )
      break;
LABEL_11:
    ++v4;
    ++v3;
    ++v8;
    v7 += 200;
    if ( v4 >= v2 )
      return 0;
  }
  v12 = v7;
  while ( 1 )
  {
    v13 = *v12;
    if ( v5 && v13 )
    {
      v14 = (UFG::SimObject *)v13->m_pOwner.m_pPointer;
      if ( v14 )
        v14 = (UFG::SimObject *)v14->mNode.mParent;
      if ( v14 == v5 )
        break;
    }
    ++v11;
    ++v10;
    v12 += 25;
    if ( v11 >= v9 )
      goto LABEL_11;
  }
  v16 = v10 + 8i64 * v3;
  UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
    v6,
    v3,
    v10,
    v6->mStateVariables.m_FormationSlot[0][v16].m_pMember.m_pPointer);
  v6->mStateVariables.m_FormationSlot[0][v16].m_InPosition = 2;
  return 1;
}

// File Line: 3173
// RVA: 0x35FFD0
signed __int64 __fastcall UFG::FormationManagerComponent::GetInPositionType(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation)
{
  __int64 v2; // r10
  __int64 v3; // r9
  signed __int64 result; // rax

  if ( get_in_formation
    && (v2 = get_in_formation->m_RangeIndex, v3 = get_in_formation->m_SlotIndex, (_DWORD)v2 != -1)
    && (_DWORD)v3 != -1
    && this->mStateVariables.m_FormationSlot[0][v3 + 8 * v2].m_pMember.m_pPointer == get_in_formation )
  {
    result = (unsigned int)this->mStateVariables.m_FormationSlot[0][v3 + 8 * v2].m_InPosition;
  }
  else
  {
    result = 2i64;
  }
  return result;
}

// File Line: 3191
// RVA: 0x3867B0
void __fastcall UFG::FormationManagerComponent::SetInPositionType(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation, UFG::eInFormationPositionType in_position)
{
  __int64 v3; // r11
  __int64 v4; // r10

  if ( get_in_formation )
  {
    v3 = get_in_formation->m_RangeIndex;
    v4 = get_in_formation->m_SlotIndex;
    if ( (_DWORD)v3 != -1
      && (_DWORD)v4 != -1
      && this->mStateVariables.m_FormationSlot[0][v4 + 8 * v3].m_pMember.m_pPointer == get_in_formation )
    {
      UFG::FormationSlot::SetInPosition(
        (UFG::FormationSlot *)this->mStateVariables.m_FormationSlot + v4 + 8 * v3,
        in_position);
    }
  }
}

// File Line: 3204
// RVA: 0x35D9D0
char __fastcall UFG::FormationManagerComponent::GetDesiredPosition(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation, UFG::qVector3 *desired_position)
{
  UFG::qVector3 *v3; // rsi
  UFG::GetInFormationNode *v4; // rdi
  UFG::FormationManagerComponent *v5; // rbx
  __int64 v6; // rcx
  __int64 v7; // rax
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // rcx
  float *v10; // rbp
  signed __int64 v11; // rdx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  UFG::SimComponent *v15; // rax
  UFG::TransformNodeComponent *v16; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v17; // rcx
  UFG::CombatRegion *v18; // rcx
  UFG::SimComponent *v19; // rax
  UFG::SimObject *v20; // rcx
  float v21; // xmm0_4
  float v22; // xmm1_4

  v3 = desired_position;
  v4 = get_in_formation;
  v5 = this;
  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0;
  if ( !get_in_formation )
    return 0;
  v6 = get_in_formation->m_RangeIndex;
  v7 = get_in_formation->m_SlotIndex;
  if ( (_DWORD)v6 == -1 )
    return 0;
  if ( (_DWORD)v7 == -1 )
    return 0;
  if ( v5->mStateVariables.m_FormationSlot[0][v7 + 8 * v6].m_pMember.m_pPointer != get_in_formation )
    return 0;
  v8 = get_in_formation->m_pOwner.m_pPointer;
  if ( !v8 )
    return 0;
  if ( !v8[2].vfptr )
    return 0;
  v9 = v8->m_pSimObject;
  if ( !v9 || !v9->m_pTransformNodeComponent )
    return 0;
  v10 = (float *)v5->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent);
  v11 = v4->m_SlotIndex + 8i64 * v4->m_RangeIndex;
  if ( v5->mStateVariables.m_FormationSlot[0][v11].m_UseAbsolutePosition )
  {
    v12 = v5->mStateVariables.m_FormationSlot[0][v11].m_AbsolutePosition.z;
    v13 = v5->mStateVariables.m_FormationSlot[0][v11].m_AbsolutePosition.y;
    v3->x = v5->mStateVariables.m_FormationSlot[0][v11].m_AbsolutePosition.x;
    v3->z = v12;
  }
  else
  {
    v14 = v5->mStateVariables.m_FormationSlot[0][v11].m_Direction.z + v10[46];
    v13 = v5->mStateVariables.m_FormationSlot[0][v11].m_Direction.y + v10[45];
    v3->x = v5->mStateVariables.m_FormationSlot[0][v11].m_Direction.x + v10[44];
    v3->z = v14;
  }
  v3->y = v13;
  v15 = v4->m_pOwner.m_pPointer;
  v16 = 0i64;
  if ( v15 )
    v17 = v15[2].vfptr;
  else
    v17 = 0i64;
  v18 = (UFG::CombatRegion *)v17[123].__vecDelDtor;
  if ( v18 && !UFG::CombatRegion::IsHitPoint(v18, v3) )
  {
    v19 = v4->m_pOwner.m_pPointer;
    if ( v19 )
    {
      v20 = v19->m_pSimObject;
      if ( v20 )
        v16 = v20->m_pTransformNodeComponent;
    }
    UFG::TransformNodeComponent::UpdateWorldTransform(v16);
    v21 = v16->mWorldTransform.v3.y;
    v22 = v16->mWorldTransform.v3.z;
    v3->x = v16->mWorldTransform.v3.x;
    v3->y = v21;
    v3->z = v22;
  }
  return 1;
}

// File Line: 3242
// RVA: 0x35E300
bool __fastcall UFG::FormationManagerComponent::GetDesiredSpeed(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation, UFG::eMoveType *move_type)
{
  __int64 v3; // r10
  __int64 v4; // r11
  signed __int64 v5; // rdx
  UFG::eInFormationPositionType v6; // eax

  if ( get_in_formation
    && (v3 = get_in_formation->m_RangeIndex, v4 = get_in_formation->m_SlotIndex, (_DWORD)v3 != -1)
    && (_DWORD)v4 != -1
    && this->mStateVariables.m_FormationSlot[0][v4 + 8 * v3].m_pMember.m_pPointer == get_in_formation )
  {
    v5 = v4 + 8 * v3;
    v6 = this->mStateVariables.m_FormationSlot[0][v5].m_InPosition;
    if ( v6 == 3 )
    {
      *move_type = 3;
      LOBYTE(v6) = 1;
    }
    else if ( v6 == 1 )
    {
      *move_type = 1;
    }
    else
    {
      if ( (_DWORD)v3 )
        *move_type = this->mStateVariables.m_FormationSlot[0][v5].m_DesiredSpeed;
      else
        *move_type = 2;
      LOBYTE(v6) = 1;
    }
  }
  else
  {
    LOBYTE(v6) = 0;
  }
  return v6;
}

// File Line: 3340
// RVA: 0x36ACF0
bool __fastcall UFG::FormationManagerComponent::IsInFormation(UFG::FormationManagerComponent *this, UFG::GetInFormationNode *get_in_formation)
{
  __int64 v2; // r10
  __int64 v3; // r9
  signed __int64 v4; // rbx
  bool result; // al

  result = 0;
  if ( get_in_formation )
  {
    v2 = get_in_formation->m_RangeIndex;
    v3 = get_in_formation->m_SlotIndex;
    if ( (_DWORD)v2 != -1
      && (_DWORD)v3 != -1
      && this->mStateVariables.m_FormationSlot[0][v3 + 8 * v2].m_pMember.m_pPointer == get_in_formation )
    {
      v4 = v3 + 8 * v2;
      if ( this->mStateVariables.m_FormationSlot[0][v4].m_InPosition == eIN_POSITION
        && (_DWORD)v2 != -1
        && (_DWORD)v3 != -1
        && this->mStateVariables.m_FormationSlot[0][v3 + 8 * v2].m_pMember.m_pPointer == get_in_formation
        && this->mStateVariables.m_FormationSlot[0][v4].m_CurrentlyFacingCorrectly )
      {
        result = 1;
      }
    }
  }
  return result;
}

// File Line: 3358
// RVA: 0x3778C0
__int64 __fastcall UFG::FormationManagerComponent::NumAttackersCloserThan(UFG::FormationManagerComponent *this, float distance, int stopCount)
{
  UFG::FormationManagerComponent *v3; // rbx
  UFG::TransformNodeComponent *v4; // rcx
  unsigned int v5; // er15
  int v6; // esi
  int v7; // ecx
  __int64 v8; // rdi
  __int64 v9; // r13
  signed __int64 v10; // rax
  int *v11; // r12
  int v12; // ebp
  UFG::SimObject **v13; // r14
  UFG::SimObject *v14; // rbx
  UFG::TransformNodeComponent *v15; // rax
  float *v16; // rsi
  UFG::SimComponent *v17; // rsi
  UFG::SimComponent *v18; // rax
  __int64 v19; // rax
  signed __int64 v21; // [rsp+20h] [rbp-88h]
  float *v22; // [rsp+28h] [rbp-80h]
  __int64 v23[6]; // [rsp+30h] [rbp-78h]
  UFG::FormationManagerComponent *v24; // [rsp+B0h] [rbp+8h]
  unsigned int v25; // [rsp+C0h] [rbp+18h]
  int v26; // [rsp+C8h] [rbp+20h]

  v24 = this;
  v3 = this;
  v4 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v5 = 0;
  v6 = stopCount;
  v22 = (float *)v4;
  if ( !v4 )
    return v5;
  if ( stopCount >= 5 )
    v6 = 5;
  v25 = v6;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v7 = 0;
  v8 = 0i64;
  v26 = 0;
  v9 = v6;
  if ( v3->m_NumRanges <= 0 )
    return v5;
  v10 = (signed __int64)&v3->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  v11 = v3->m_NumSlotsPerRange;
  v21 = (signed __int64)&v3->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  while ( 1 )
  {
    v12 = 0;
    if ( *v11 > 0 )
      break;
LABEL_21:
    ++v7;
    v10 += 1600i64;
    ++v11;
    v26 = v7;
    v21 = v10;
    if ( v7 >= v3->m_NumRanges )
      return v5;
  }
  v13 = (UFG::SimObject **)v10;
  while ( 1 )
  {
    v14 = *v13;
    if ( *v13 )
    {
      v15 = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                             *v13,
                                             UFG::TransformNodeComponent::_TypeUID);
      v16 = (float *)v15;
      if ( v15 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v15);
        if ( (float)((float)((float)((float)(v22[45] - v16[45]) * (float)(v22[45] - v16[45]))
                           + (float)((float)(v22[44] - v16[44]) * (float)(v22[44] - v16[44])))
                   + (float)((float)(v22[46] - v16[46]) * (float)(v22[46] - v16[46]))) < (float)(distance * distance) )
        {
          v17 = UFG::SimObject::GetComponentOfType(v14, UFG::ActiveAIEntityComponent::_TypeUID);
          if ( !v17
            || ((v18 = UFG::SimObject::GetComponentOfType(v14, UFG::CharacterOccupantComponent::_TypeUID)) == 0i64
             || LODWORD(v18[1].m_SafePointerList.mNode.mNext) != 13)
            && UFG::g_AIObjectiveParams[SHIDWORD(v17[65].vfptr)].m_IsHostile )
          {
            v19 = 0i64;
            if ( v8 > 0 )
            {
              while ( (UFG::SimObject *)v23[v19] != v14 )
              {
                if ( ++v19 >= v8 )
                  goto LABEL_18;
              }
              goto LABEL_19;
            }
LABEL_18:
            v23[v8++] = (__int64)v14;
            ++v5;
            if ( v8 >= v9 )
              return v25;
          }
        }
      }
    }
LABEL_19:
    ++v12;
    v13 += 25;
    if ( v12 >= *v11 )
    {
      v10 = v21;
      v7 = v26;
      v3 = v24;
      goto LABEL_21;
    }
  }
}

// File Line: 3464
// RVA: 0x360C30
float __fastcall UFG::FormationManagerComponent::GetMaxDistanceForRange(UFG::FormationManagerComponent *this, int range_index)
{
  __int64 v2; // r8
  float result; // xmm0_4

  v2 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  if ( range_index < 0 || (_DWORD)v2 == -1 )
    return 0.0;
  result = this->mStateVariables.m_pCurrentProfile->m_MaxDistanceOverride[range_index];
  if ( result < 0.0 )
    result = this->m_BattleTypeSpecificParameters[0].m_MaxDistance[range_index + 12 * v2];
  return result;
}

// File Line: 3488
// RVA: 0x3541A0
void __fastcall UFG::FormationManagerComponent::DrawDebugInfo(UFG::FormationManagerComponent *this, Render::View *view)
{
  UFG::FormationManagerComponent *v2; // r15
  UFG::SimComponent *v3; // r12
  __int64 v4; // r13
  signed __int64 v5; // rbx
  signed __int64 v6; // rcx
  signed __int64 v7; // r14
  __int64 v8; // rdx
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  Render::DebugDrawContext *v12; // rax
  int v13; // esi
  __int64 v14; // rax
  __int64 v15; // rdi
  float v16; // xmm7_4
  float v17; // xmm8_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  Render::DebugDrawContext *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  Render::DebugDrawContext *v27; // rax
  int v28; // eax
  __m128i v29; // xmm0
  Render::DebugDrawManager *v30; // rcx
  Render::DebugDrawContext *v31; // rax
  bool v32; // sf
  unsigned __int8 v33; // of
  __int64 v34; // [rsp+40h] [rbp-B0h]
  signed __int64 v35; // [rsp+48h] [rbp-A8h]
  UFG::qVector3 v36; // [rsp+50h] [rbp-A0h]
  UFG::qVector3 point; // [rsp+60h] [rbp-90h]
  UFG::qVector3 centre; // [rsp+70h] [rbp-80h]
  UFG::qVector3 p0; // [rsp+80h] [rbp-70h]
  UFG::qVector3 p1; // [rsp+90h] [rbp-60h]
  UFG::qVector3 v41; // [rsp+A0h] [rbp-50h]
  __int64 v42; // [rsp+B0h] [rbp-40h]
  UFG::qColour colour; // [rsp+C0h] [rbp-30h]
  UFG::qColour v44; // [rsp+D0h] [rbp-20h]
  UFG::qColour v45; // [rsp+E0h] [rbp-10h]
  UFG::qColour v46; // [rsp+F0h] [rbp+0h]
  int vars0; // [rsp+190h] [rbp+A0h]
  float current_lateral_offset; // [rsp+1A0h] [rbp+B0h]
  float current_radial_offset; // [rsp+1A8h] [rbp+B8h]

  v2 = this;
  if ( this->m_DebugDrawEnabled )
  {
    if ( this->m_pTransformNodeComponent.m_pSimComponent )
    {
      v3 = this->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
      v4 = 0i64;
      vars0 = 0;
      v34 = 0i64;
      if ( v2->m_NumRanges > 0 )
      {
        v5 = (signed __int64)&v2->mStateVariables.m_FormationSlot[0][0].m_Direction.y;
        v6 = -312i64 - (_QWORD)v2;
        v7 = (signed __int64)v2->m_NumSlotsPerRange;
        v35 = (signed __int64)&v2->mStateVariables.m_FormationSlot[0][0].m_Direction.y;
        v42 = -312i64 - (_QWORD)v2;
        do
        {
          v8 = (signed int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
          colour = UFG::qColour::Red;
          if ( v4 < 0 || (_DWORD)v8 == -1 )
          {
            v9 = 0.0;
          }
          else
          {
            v9 = *(float *)((char *)&v2->mStateVariables.m_pCurrentProfile->m_NameID.mUID + v6 + v7);
            if ( v9 < 0.0 )
              v9 = v2->m_BattleTypeSpecificParameters[0].m_MaxDistance[v4 + 12 * v8];
          }
          v10 = *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1);
          centre.x = *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev;
          v11 = *(float *)&v3[2].m_BoundComponentHandles.mNode.mNext;
          centre.y = v10;
          centre.z = v11 + 0.25;
          v12 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
          Render::DebugDrawContext::DrawCircle(v12, &centre, v9, &colour, &UFG::qMatrix44::msIdentity, 0i64);
          v13 = 0;
          if ( *(_DWORD *)v7 > 0 )
          {
            do
            {
              v14 = *(_QWORD *)(v5 + 84);
              if ( v14 )
                v15 = *(_QWORD *)(v14 + 88);
              else
                v15 = 0i64;
              if ( v14 && v15 )
              {
                v17 = *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1) + *(float *)v5;
                v18 = *(float *)(v5 + 4) + *(float *)&v3[2].m_BoundComponentHandles.mNode.mNext;
                centre.x = *(float *)(v5 - 4) + *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev;
                v16 = centre.x;
                centre.y = v17;
                centre.z = v18;
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v15);
                v19 = *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev;
                v20 = v18 + 0.25;
                v45 = UFG::qColour::Green;
                v21 = *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1);
                p0.x = v19;
                p1.x = v16;
                p0.y = v21;
                v22 = *(float *)&v3[2].m_BoundComponentHandles.mNode.mNext;
                p1.y = v17;
                p1.z = v20;
                p0.z = v22 + 0.25;
                v23 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                    Render::DebugDrawManager::mInstance,
                                                    1u);
                Render::DebugDrawContext::DrawLine(
                  v23,
                  &p0,
                  &p1,
                  &v45,
                  &UFG::qMatrix44::msIdentity,
                  (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
                  0);
                v24 = *(float *)(v15 + 176);
                v36.x = v16;
                v44 = UFG::qColour::Red;
                v25 = *(float *)(v15 + 180);
                v41.x = v24;
                v36.y = v17;
                v41.y = v25;
                v26 = *(float *)(v15 + 184);
                v36.z = v20;
                v41.z = v26 + 0.25;
                v27 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                    Render::DebugDrawManager::mInstance,
                                                    1u);
                Render::DebugDrawContext::DrawLine(
                  v27,
                  &v41,
                  &v36,
                  &v44,
                  &UFG::qMatrix44::msIdentity,
                  (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
                  0);
                v28 = *(_DWORD *)(v5 + 28);
                v29 = (__m128i)UFG::qColour::White;
                if ( v28 == 3 )
                {
                  v29 = (__m128i)UFG::qColour::Red;
                }
                else if ( !v28 )
                {
                  v29 = (__m128i)UFG::qColour::Blue;
                  if ( *(_BYTE *)(v5 + 37) )
                    v29 = (__m128i)UFG::qColour::Green;
                }
                v30 = Render::DebugDrawManager::mInstance;
                point.x = v16;
                point.y = v17;
                point.z = v20;
                _mm_store_si128((__m128i *)&v46, v29);
                v31 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(v30, 1u);
                Render::DebugDrawContext::DrawPoint(v31, &point, &v46, &UFG::qMatrix44::msIdentity, 0i64);
                UFG::FormationManagerComponent::IsInPosition(
                  v2,
                  (UFG::qVector3 *)(v15 + 176),
                  &centre,
                  *(float *)(v7 + 52),
                  *(float *)(v7 + 100),
                  &current_radial_offset,
                  &current_lateral_offset,
                  1);
              }
              ++v13;
              v5 += 200i64;
            }
            while ( v13 < *(_DWORD *)v7 );
            v4 = v34;
            v5 = v35;
          }
          ++v4;
          v5 += 1600i64;
          v7 += 4i64;
          v34 = v4;
          v33 = __OFSUB__(vars0 + 1, v2->m_NumRanges);
          v32 = vars0++ + 1 - v2->m_NumRanges < 0;
          v6 = v42;
          v35 = v5;
        }
        while ( v32 ^ v33 );
      }
    }
  }
}  v6 = v42;
          v35 = v5;
        }
        while ( v32 ^ v33 );
      }
    }
  }
}

