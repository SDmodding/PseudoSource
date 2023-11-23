// File Line: 44
// RVA: 0x14AEAE0
__int64 dynamic_initializer_for__UFG::FormationManagerComponent::s_FormationManagerComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::FormationManagerComponent::s_FormationManagerComponentList__);
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
  int i; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::FormationManagerComponent::s_Profiles;
  for ( i = 15; i >= 0; --i )
  {
    result = Assembly::GetRCX(v0);
    v0 += 29;
  }
  return result;
}

// File Line: 83
// RVA: 0x3688E0
void __fastcall UFG::FormationSlot::InitWithDefaults(
        UFG::FormationSlot *this,
        UFG::FormationManagerComponent *parent,
        int range_index,
        int slot_index)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *p_m_pMember; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v14; // rax

  *(_QWORD *)&this->m_Direction.x = 1065353216i64;
  this->m_Direction.z = 0.0;
  *(_QWORD *)&this->m_FacingDirection.x = 1065353216i64;
  *(_QWORD *)&this->m_FacingDirection.z = 0i64;
  p_m_pFormationManagerComponent = &this->m_pFormationManagerComponent;
  this->m_Angle = 0;
  this->m_DesiredSpeed = eMoveType_Jog;
  this->m_TimeGotIntoPosition = -99999.0;
  this->m_NextTimeToChangePosition = -99999.0;
  this->m_TimeFinishUsingLargeHysteresis = -1.0;
  *(_WORD *)&this->m_CurrentlyInRange = 0;
  this->m_RequestedToChangePosition = 0;
  this->m_Fixed = 0;
  *(_QWORD *)&this->m_RadialHysteresisModifierMin = 0i64;
  *(_QWORD *)&this->m_RadialHysteresisModifier = 0i64;
  this->m_CurrentlyStayingClose = 0;
  if ( this->m_pFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pFormationManagerComponent->mPrev;
    mNext = p_m_pFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pFormationManagerComponent->mPrev = p_m_pFormationManagerComponent;
    p_m_pFormationManagerComponent->mNext = p_m_pFormationManagerComponent;
  }
  p_m_pFormationManagerComponent->m_pPointer = parent;
  if ( parent )
  {
    v9 = parent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v9->mNext = p_m_pFormationManagerComponent;
    p_m_pFormationManagerComponent->mPrev = v9;
    p_m_pFormationManagerComponent->mNext = &parent->m_SafePointerList.mNode;
    parent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pFormationManagerComponent;
  }
  this->m_RangeIndex = range_index;
  this->m_SlotIndex = slot_index;
  this->m_UseAbsolutePosition = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  p_m_pMember = &this->m_pMember;
  HIDWORD(p_m_pMember[2].mPrev) = LODWORD(UFG::qVector3::msZero.x);
  *(float *)&p_m_pMember[2].mNext = y;
  *((float *)&p_m_pMember[2].mNext + 1) = z;
  if ( p_m_pMember->m_pPointer )
  {
    v13 = p_m_pMember->mPrev;
    v14 = p_m_pMember->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pMember->mPrev = p_m_pMember;
    p_m_pMember->mNext = p_m_pMember;
  }
  p_m_pMember->m_pPointer = 0i64;
}

// File Line: 111
// RVA: 0x387AD0
void __fastcall UFG::FormationSlot::SetRadialHysteresisModifier(UFG::FormationSlot *this)
{
  float m_RadialHysteresisModifierMax; // xmm6_4
  float m_RadialHysteresisModifierMin; // xmm7_4
  float v4; // xmm0_4

  m_RadialHysteresisModifierMax = this->m_RadialHysteresisModifierMax;
  m_RadialHysteresisModifierMin = this->m_RadialHysteresisModifierMin;
  if ( m_RadialHysteresisModifierMax <= m_RadialHysteresisModifierMin )
  {
    this->m_RadialHysteresisModifier = m_RadialHysteresisModifierMax;
  }
  else
  {
    v4 = UFG::qRandom(m_RadialHysteresisModifierMax - m_RadialHysteresisModifierMin, (unsigned int *)&UFG::qDefaultSeed)
       + m_RadialHysteresisModifierMin;
    if ( v4 <= m_RadialHysteresisModifierMin )
      v4 = m_RadialHysteresisModifierMin;
    if ( v4 >= m_RadialHysteresisModifierMax )
      this->m_RadialHysteresisModifier = m_RadialHysteresisModifierMax;
    else
      this->m_RadialHysteresisModifier = v4;
  }
}

// File Line: 116
// RVA: 0x362FB0
float __fastcall UFG::FormationSlot::GetTimeUntilNextChangePosition(UFG::FormationSlot *this)
{
  UFG::SimComponent *m_pPointer; // rax
  __int64 v3; // rcx
  char v4; // al
  UFG::SimObject *v5; // rcx
  char v6; // di
  UFG::SimComponent *ComponentOfType; // rax
  char v8; // al
  float v9; // xmm1_4
  float result; // xmm0_4

  if ( !this->m_RangeIndex )
  {
    m_pPointer = this->m_pFormationManagerComponent.m_pPointer;
    if ( m_pPointer )
    {
      v3 = *(_QWORD *)&m_pPointer[2].m_Flags;
      if ( v3 )
      {
        v4 = (*(__int64 (**)(void))(*(_QWORD *)v3 + 112i64))();
        v5 = this->m_pMemberSimObject.m_pPointer;
        v6 = v4;
        if ( v5
          && (ComponentOfType = UFG::SimObject::GetComponentOfType(v5, UFG::ActiveAIEntityComponent::_TypeUID)) != 0i64 )
        {
          v8 = ((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[14].__vecDelDtor)(ComponentOfType);
        }
        else
        {
          v8 = 0;
        }
        if ( v6 && v8 )
        {
          v9 = FLOAT_3_0;
          result = UFG::qRandom(2.0, (unsigned int *)&UFG::qDefaultSeed) + 3.0;
          if ( result > 3.0 )
          {
            if ( result >= 5.0 )
              return FLOAT_5_0;
            return result;
          }
          return v9;
        }
      }
    }
  }
  v9 = *(float *)&FLOAT_1_0;
  result = UFG::qRandom(2.0, (unsigned int *)&UFG::qDefaultSeed) + 1.0;
  if ( result <= 1.0 )
    return v9;
  if ( result >= 3.0 )
    return FLOAT_3_0;
  return result;
}

// File Line: 153
// RVA: 0x386680
void __fastcall UFG::FormationSlot::SetInPosition(UFG::FormationSlot *this, __int32 in_position)
{
  float mSimTime_Temp; // xmm6_4
  float v5; // xmm0_4
  UFG::SimComponent *m_pPointer; // rax

  if ( this->m_InPosition == eIN_POSITION || in_position )
  {
    this->m_InPosition = in_position;
  }
  else
  {
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    this->m_TimeGotIntoPosition = UFG::Metrics::msInstance.mSimTime_Temp;
    this->m_NextTimeToChangePosition = UFG::FormationSlot::GetTimeUntilNextChangePosition(this) + mSimTime_Temp;
    v5 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
    this->m_Fixed = in_position;
    this->m_UseAbsolutePosition = in_position;
    this->m_DesiredSpeed = (v5 < 0.5) + 1;
    m_pPointer = this->m_pFormationManagerComponent.m_pPointer;
    if ( m_pPointer )
      this->m_FacingType = HIDWORD(m_pPointer[5].m_BoundComponentHandles.mNode.mNext);
    else
      this->m_FacingType = eFORMATION_FACING_NONE;
    UFG::FormationSlot::SetRadialHysteresisModifier(this);
    this->m_InPosition = in_position;
  }
}

// File Line: 197
// RVA: 0x385490
void __fastcall UFG::FormationManagerComponent::SetDefaultProfile(UFG::FormationProfile *profile)
{
  unsigned __int16 *v2; // rcx
  __int64 v3; // r8

  if ( (_S12_1 & 1) == 0 )
    _S12_1 |= 1u;
  dword_1423C1AC0 = profile->m_NameID.mUID;
  xmmword_1423C1AC4 = *(_OWORD *)profile->m_RingType;
  xmmword_1423C1AD4 = *(_OWORD *)profile->m_MaxDistanceOverride;
  v2 = &profile->m_RingAngle[0][1];
  v3 = 16i64;
  do
  {
    *(unsigned __int16 *)((char *)v2 + &unk_1423C1AE4 - (_UNKNOWN *)profile - 38) = *(v2 - 1);
    *(unsigned __int16 *)((char *)v2 + (char *)&dword_1423C1AC0 - (char *)profile) = *v2;
    v2 += 2;
    --v3;
  }
  while ( v3 );
  dword_1423C1B24 = profile->m_NumRingAngles[0];
  dword_1423C1B28 = profile->m_NumRingAngles[1];
  dword_1423C1B2C = profile->m_NumRingAngles[2];
  dword_1423C1B30 = profile->m_NumRingAngles[3];
}

// File Line: 203
// RVA: 0x37EC70
UFG::FormationManagerComponent *__fastcall UFG::FormationManagerComponent::PropertiesOnActivateNew(
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
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-40h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_FormationManager::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    MemImagePtr = 0i64;
  if ( !required && !MemImagePtr )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x1B88ui64, "FormationManagerComponent", 0i64, 1u);
  if ( v10 )
  {
    mpConstProperties = pSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSceneObj->mpConstProperties;
    UFG::FormationManagerComponent::FormationManagerComponent(
      (UFG::FormationManagerComponent *)v10,
      pSceneObj->m_NameUID,
      mpConstProperties,
      (component_FormationManager *)MemImagePtr);
    v6 = v12;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v13, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  return (UFG::FormationManagerComponent *)v6;
}

// File Line: 223
// RVA: 0x32E8F0
void __fastcall UFG::FormationManagerComponent::FormationManagerComponent(
        UFG::FormationManagerComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        component_FormationManager *data)
{
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent>;
  this->mNext = &this->UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FormationManagerComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::RebindingComponentHandle<UFG::AIEntityComponent,0>(&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::RebindingComponentHandle<UFG::AttackRightsComponent,0>(&this->m_pAttackRightsComponent);
  `eh vector constructor iterator(
    this->mStateVariables.m_FormationSlot,
    0xC8ui64,
    32,
    (void (__fastcall *)(void *))UFG::FormationSlot::FormationSlot);
  mPrev = UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mPrev;
  UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)&UFG::FormationManagerComponent::s_FormationManagerComponentList;
  UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mPrev = &this->UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::FormationManagerComponent::_FormationManagerComponentTypeUID,
    "FormationManagerComponent");
  this->mStateVariables.m_pCurrentProfile = 0i64;
  this->mStateVariables.m_RangeSwitchesFrozen = 0;
  this->m_DebugDrawEnabled = 0;
  UFG::FormationManagerComponent::Clear(this);
  UFG::FormationManagerComponent::InitFromProperties(this, properties, data);
}

// File Line: 236
// RVA: 0x337090
void __fastcall UFG::FormationManagerComponent::~FormationManagerComponent(UFG::FormationManagerComponent *this)
{
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v2; // rbx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *mPrev; // rcx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *mNext; // rax
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v5; // rcx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FormationManagerComponent::`vftable;
  if ( this == UFG::FormationManagerComponent::s_FormationManagerComponentpCurrentIterator )
    UFG::FormationManagerComponent::s_FormationManagerComponentpCurrentIterator = (UFG::FormationManagerComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  `eh vector destructor iterator(
    this->mStateVariables.m_FormationSlot,
    0xC8ui64,
    32,
    (void (__fastcall *)(void *))UFG::FormationSlot::~FormationSlot);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAttackRightsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->m_pTransformNodeComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 241
// RVA: 0x34EA30
void __fastcall UFG::FormationManagerComponent::Clear(UFG::FormationManagerComponent *this)
{
  int v2; // r14d
  float *m_MaxDistance; // rbx
  UFG::FormationSlot (*m_FormationSlot)[8]; // rsi
  int i; // edi
  __int64 v6; // rdx
  float *m_MaxTimeBeforeSwitchFromRange; // rbp
  float *v8; // rax
  __int64 v9; // rcx

  if ( (_S12_1 & 1) == 0 )
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
  m_MaxDistance = this->m_BattleTypeSpecificParameters[1].m_MaxDistance;
  m_FormationSlot = this->mStateVariables.m_FormationSlot;
  do
  {
    *(m_MaxDistance - 12) = 99999.0;
    *m_MaxDistance = 99999.0;
    *((_DWORD *)m_MaxDistance - 62) = 8;
    *((_DWORD *)m_MaxDistance - 58) = 8;
    *((_DWORD *)m_MaxDistance - 54) = 8;
    *(m_MaxDistance - 49) = 0.0;
    *(m_MaxDistance - 45) = 0.0;
    *(m_MaxDistance - 41) = 0.0;
    *(m_MaxDistance - 37) = 0.0;
    *(m_MaxDistance - 33) = 0.0;
    *(m_MaxDistance - 28) = 1.0;
    *(m_MaxDistance - 24) = 1.0;
    for ( i = 0; i < 8; ++i )
    {
      UFG::FormationSlot::InitWithDefaults((UFG::FormationSlot *)m_FormationSlot, this, v2, i);
      m_FormationSlot = (UFG::FormationSlot (*)[8])((char *)m_FormationSlot + 200);
    }
    ++v2;
    ++m_MaxDistance;
  }
  while ( v2 < 4 );
  v6 = 22i64;
  m_MaxTimeBeforeSwitchFromRange = this->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange;
  do
  {
    v8 = m_MaxTimeBeforeSwitchFromRange;
    v9 = 3i64;
    do
    {
      *(v8 - 3) = -1.0;
      *v8 = -1.0;
      v8[v6] = -1.0;
      ++v8;
      --v9;
    }
    while ( v9 );
    m_MaxTimeBeforeSwitchFromRange += 12;
    v6 -= 12i64;
  }
  while ( v6 > -2 );
}

// File Line: 299
// RVA: 0x3671E0
void __fastcall UFG::FormationManagerComponent::InitFromProperties(
        UFG::FormationManagerComponent *this,
        UFG::qPropertySet *property_set,
        component_FormationManager *data)
{
  int v3; // ebx
  __int64 v7; // rcx
  unsigned __int16 (*m_RingAngle)[8]; // rax
  int v9; // r11d
  float v10; // xmm0_4
  float v11; // xmm1_4
  __int64 v12; // r8
  ActionID *v13; // rdx
  float v14; // xmm0_4
  char *v15; // rcx
  float v16; // xmm1_4
  __int16 v17; // ax
  UFG::qPropertySet *v18; // rax
  float MaxRadialDistanceFromDesiredPositionHysteresisLarge0; // xmm1_4
  float MaxRadialDistanceFromDesiredPositionHysteresis0; // xmm0_4
  float MaxRadialDistanceFromDesiredPositionHysteresisLarge1; // xmm2_4
  float MaxRadialDistanceFromDesiredPositionHysteresis1; // xmm0_4
  float MaxRadialDistanceFromDesiredPositionHysteresisLarge2; // xmm1_4
  float MaxRadialDistanceFromDesiredPositionHysteresis2; // xmm0_4
  float MaxRadialDistanceFromDesiredPosition3; // eax
  float MaxRadialDistanceFromDesiredPositionHysteresis3; // xmm0_4
  float MaxLateralDistanceFromDesiredPositionHysteresis0; // xmm1_4
  float MaxLateralDistanceFromDesiredPositionHysteresis1; // xmm0_4
  float MaxLateralDistanceFromDesiredPositionHysteresis2; // xmm1_4
  float MaxLateralDistanceFromDesiredPositionHysteresis3; // xmm0_4
  float MaxFacingDifferenceHysteresis0; // xmm1_4
  float MaxFacingDifferenceHysteresis1; // xmm0_4
  float MaxFacingDifferenceHysteresis2; // xmm1_4
  float MaxFacingDifferenceHysteresis3; // xmm0_4
  float RadialHysteresisModifierMax0; // xmm2_4
  float RadialHysteresisModifierMin0; // xmm1_4
  float RadialHysteresisModifierMin1; // xmm0_4
  float RadialHysteresisModifierMax1; // xmm3_4
  float RadialHysteresisModifierMin2; // xmm0_4
  float RadialHysteresisModifierMax2; // xmm1_4
  float RadialHysteresisModifierMax3; // xmm2_4
  float RadialHysteresisModifierMin3; // xmm0_4
  float NormalMaxTimeBeforeSwitchFromRange0; // xmm7_4
  float v44; // xmm8_4
  float mSimTime_Temp; // xmm9_4
  float v46; // xmm0_4
  float NormalMaxTimeBeforeSwitchFromRange1; // xmm7_4
  float v48; // xmm8_4
  float v49; // xmm9_4
  float v50; // xmm0_4
  float NormalMaxTimeBeforeSwitchFromRange2; // xmm7_4
  float v52; // xmm8_4
  float v53; // xmm9_4
  float v54; // xmm0_4
  float NormalMaxTimeBeforeCheckPlayersTarget; // xmm0_4
  float v56; // xmm9_4
  __int64 m_CurrentBattleType; // rcx
  float m_MaxTimeBeforeCheckPlayersTarget; // xmm7_4
  float m_MinTimeBeforeCheckPlayersTarget; // xmm8_4
  float v60; // xmm0_4
  float MobMaxTimeBeforeSwitchFromRange0; // xmm7_4
  float v62; // xmm8_4
  float v63; // xmm9_4
  float v64; // xmm0_4
  float MobMaxTimeBeforeSwitchFromRange1; // xmm7_4
  float v66; // xmm8_4
  float v67; // xmm9_4
  float v68; // xmm0_4
  float MobMaxTimeBeforeSwitchFromRange2; // xmm7_4
  float v70; // xmm8_4
  float v71; // xmm9_4
  float v72; // xmm0_4
  float MobMaxTimeBeforeCheckPlayersTarget; // xmm0_4
  float v74; // xmm9_4
  __int64 v75; // rcx
  float v76; // xmm7_4
  float v77; // xmm8_4
  float v78; // xmm0_4
  __int64 mOffset; // rax
  const char *v80; // rbp
  const char **v81; // rsi
  UFG::FormationProfile profile; // [rsp+20h] [rbp-C8h] BYREF

  v3 = 0;
  if ( !once_8 )
  {
    profile.m_NameID.mUID = 0;
    v7 = 0i64;
    m_RingAngle = profile.m_RingAngle;
    do
    {
      profile.m_RingType[v7] = eRING_TYPE_FLUID;
      profile.m_MaxDistanceOverride[v7] = -1.0;
      profile.m_NumRingAngles[v7] = 0;
      *(_QWORD *)m_RingAngle = 0i64;
      ++v7;
      *(_QWORD *)&(*m_RingAngle++)[4] = 0i64;
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
      v15 = (char *)&v13[9].mUID + 2;
      v16 = profile.m_MaxDistanceOverride[3];
      *(float *)&v13[7].mUID = v14;
      *(float *)&v13[8].mUID = v16;
      do
      {
        v17 = *(_WORD *)&v15[(char *)profile.m_RingAngle - (char *)v13 - 38];
        v15 += 4;
        *((_WORD *)v15 - 3) = v17;
        *((_WORD *)v15 - 2) = *(_WORD *)&v15[(char *)&profile - (char *)v13 - 4];
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
  if ( !data )
  {
    v18 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            property_set,
            (UFG::qArray<unsigned long,0> *)&component_FormationManager::sPropertyName,
            DEPTH_RECURSE);
    if ( v18 )
      data = (component_FormationManager *)UFG::qPropertySet::GetMemImagePtr(v18);
    else
      data = 0i64;
  }
  if ( data->NumRanges <= 4 )
    this->m_NumRanges = data->NumRanges;
  UFG::FormationManagerComponent::SetNumSlotsPerRange(this, 0, data->NumSlotsInRange0);
  UFG::FormationManagerComponent::SetNumSlotsPerRange(this, 1, data->NumSlotsInRange1);
  UFG::FormationManagerComponent::SetNumSlotsPerRange(this, 2, data->NumSlotsInRange2);
  UFG::FormationManagerComponent::SetNumSlotsPerRange(this, 3, data->NumSlotsInRange3);
  MaxRadialDistanceFromDesiredPositionHysteresisLarge0 = data->MaxRadialDistanceFromDesiredPositionHysteresisLarge0;
  MaxRadialDistanceFromDesiredPositionHysteresis0 = data->MaxRadialDistanceFromDesiredPositionHysteresis0;
  this->m_MaxRadialDistanceFromDesiredPosition[0] = data->MaxRadialDistanceFromDesiredPosition0;
  this->m_MaxRadialDistanceFromDesiredPositionHysteresis[0] = MaxRadialDistanceFromDesiredPositionHysteresis0;
  this->m_MaxRadialDistanceFromDesiredPositionHysteresisLarge[0] = MaxRadialDistanceFromDesiredPositionHysteresisLarge0;
  MaxRadialDistanceFromDesiredPositionHysteresisLarge1 = data->MaxRadialDistanceFromDesiredPositionHysteresisLarge1;
  MaxRadialDistanceFromDesiredPositionHysteresis1 = data->MaxRadialDistanceFromDesiredPositionHysteresis1;
  this->m_MaxRadialDistanceFromDesiredPosition[1] = data->MaxRadialDistanceFromDesiredPosition1;
  this->m_MaxRadialDistanceFromDesiredPositionHysteresis[1] = MaxRadialDistanceFromDesiredPositionHysteresis1;
  this->m_MaxRadialDistanceFromDesiredPositionHysteresisLarge[1] = MaxRadialDistanceFromDesiredPositionHysteresisLarge1;
  MaxRadialDistanceFromDesiredPositionHysteresisLarge2 = data->MaxRadialDistanceFromDesiredPositionHysteresisLarge2;
  MaxRadialDistanceFromDesiredPositionHysteresis2 = data->MaxRadialDistanceFromDesiredPositionHysteresis2;
  this->m_MaxRadialDistanceFromDesiredPosition[2] = data->MaxRadialDistanceFromDesiredPosition2;
  this->m_MaxRadialDistanceFromDesiredPositionHysteresis[2] = MaxRadialDistanceFromDesiredPositionHysteresis2;
  this->m_MaxRadialDistanceFromDesiredPositionHysteresisLarge[2] = MaxRadialDistanceFromDesiredPositionHysteresisLarge2;
  MaxRadialDistanceFromDesiredPosition3 = data->MaxRadialDistanceFromDesiredPosition3;
  MaxRadialDistanceFromDesiredPositionHysteresis3 = data->MaxRadialDistanceFromDesiredPositionHysteresis3;
  this->m_MaxRadialDistanceFromDesiredPositionHysteresisLarge[3] = data->MaxRadialDistanceFromDesiredPositionHysteresisLarge3;
  this->m_MaxRadialDistanceFromDesiredPosition[3] = MaxRadialDistanceFromDesiredPosition3;
  this->m_MaxRadialDistanceFromDesiredPositionHysteresis[3] = MaxRadialDistanceFromDesiredPositionHysteresis3;
  MaxLateralDistanceFromDesiredPositionHysteresis0 = data->MaxLateralDistanceFromDesiredPositionHysteresis0;
  this->m_MaxLateralDistanceFromDesiredPosition[0] = data->MaxLateralDistanceFromDesiredPosition0;
  this->m_MaxLateralDistanceFromDesiredPositionHysteresis[0] = MaxLateralDistanceFromDesiredPositionHysteresis0;
  MaxLateralDistanceFromDesiredPositionHysteresis1 = data->MaxLateralDistanceFromDesiredPositionHysteresis1;
  this->m_MaxLateralDistanceFromDesiredPosition[1] = data->MaxLateralDistanceFromDesiredPosition1;
  this->m_MaxLateralDistanceFromDesiredPositionHysteresis[1] = MaxLateralDistanceFromDesiredPositionHysteresis1;
  MaxLateralDistanceFromDesiredPositionHysteresis2 = data->MaxLateralDistanceFromDesiredPositionHysteresis2;
  this->m_MaxLateralDistanceFromDesiredPosition[2] = data->MaxLateralDistanceFromDesiredPosition2;
  this->m_MaxLateralDistanceFromDesiredPositionHysteresis[2] = MaxLateralDistanceFromDesiredPositionHysteresis2;
  MaxLateralDistanceFromDesiredPositionHysteresis3 = data->MaxLateralDistanceFromDesiredPositionHysteresis3;
  this->m_MaxLateralDistanceFromDesiredPosition[3] = data->MaxLateralDistanceFromDesiredPosition3;
  this->m_MaxLateralDistanceFromDesiredPositionHysteresis[3] = MaxLateralDistanceFromDesiredPositionHysteresis3;
  MaxFacingDifferenceHysteresis0 = data->MaxFacingDifferenceHysteresis0;
  this->m_MinFacingDifference[0] = data->MaxFacingDifference0;
  this->m_MinFacingDifferenceHysteresis[0] = MaxFacingDifferenceHysteresis0;
  MaxFacingDifferenceHysteresis1 = data->MaxFacingDifferenceHysteresis1;
  this->m_MinFacingDifference[1] = data->MaxFacingDifference1;
  this->m_MinFacingDifferenceHysteresis[1] = MaxFacingDifferenceHysteresis1;
  MaxFacingDifferenceHysteresis2 = data->MaxFacingDifferenceHysteresis2;
  this->m_MinFacingDifference[2] = data->MaxFacingDifference2;
  this->m_MinFacingDifferenceHysteresis[2] = MaxFacingDifferenceHysteresis2;
  MaxFacingDifferenceHysteresis3 = data->MaxFacingDifferenceHysteresis3;
  this->m_MinFacingDifference[3] = data->MaxFacingDifference3;
  this->m_MinFacingDifferenceHysteresis[3] = MaxFacingDifferenceHysteresis3;
  RadialHysteresisModifierMax0 = data->RadialHysteresisModifierMax0;
  RadialHysteresisModifierMin0 = data->RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][0].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][0].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax0;
  this->mStateVariables.m_FormationSlot[0][1].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][1].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax0;
  this->mStateVariables.m_FormationSlot[0][2].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][2].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax0;
  this->mStateVariables.m_FormationSlot[0][3].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][3].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax0;
  this->mStateVariables.m_FormationSlot[0][4].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][4].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax0;
  this->mStateVariables.m_FormationSlot[0][5].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][5].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax0;
  this->mStateVariables.m_FormationSlot[0][6].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][6].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax0;
  this->mStateVariables.m_FormationSlot[0][7].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin0;
  this->mStateVariables.m_FormationSlot[0][7].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax0;
  RadialHysteresisModifierMin1 = data->RadialHysteresisModifierMin1;
  RadialHysteresisModifierMax1 = data->RadialHysteresisModifierMax1;
  this->mStateVariables.m_FormationSlot[1][0].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin1;
  this->mStateVariables.m_FormationSlot[1][0].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax1;
  this->mStateVariables.m_FormationSlot[1][1].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin1;
  this->mStateVariables.m_FormationSlot[1][1].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax1;
  this->mStateVariables.m_FormationSlot[1][2].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin1;
  this->mStateVariables.m_FormationSlot[1][2].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax1;
  this->mStateVariables.m_FormationSlot[1][3].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin1;
  this->mStateVariables.m_FormationSlot[1][3].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax1;
  this->mStateVariables.m_FormationSlot[1][4].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin1;
  this->mStateVariables.m_FormationSlot[1][4].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax1;
  this->mStateVariables.m_FormationSlot[1][5].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin1;
  this->mStateVariables.m_FormationSlot[1][5].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax1;
  this->mStateVariables.m_FormationSlot[1][6].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin1;
  this->mStateVariables.m_FormationSlot[1][6].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax1;
  this->mStateVariables.m_FormationSlot[1][7].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin1;
  this->mStateVariables.m_FormationSlot[1][7].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax1;
  RadialHysteresisModifierMin2 = data->RadialHysteresisModifierMin2;
  RadialHysteresisModifierMax2 = data->RadialHysteresisModifierMax2;
  this->mStateVariables.m_FormationSlot[2][0].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin2;
  this->mStateVariables.m_FormationSlot[2][0].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax2;
  this->mStateVariables.m_FormationSlot[2][1].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin2;
  this->mStateVariables.m_FormationSlot[2][1].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax2;
  this->mStateVariables.m_FormationSlot[2][2].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin2;
  this->mStateVariables.m_FormationSlot[2][2].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax2;
  this->mStateVariables.m_FormationSlot[2][3].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin2;
  this->mStateVariables.m_FormationSlot[2][3].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax2;
  this->mStateVariables.m_FormationSlot[2][4].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin2;
  this->mStateVariables.m_FormationSlot[2][4].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax2;
  this->mStateVariables.m_FormationSlot[2][5].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin2;
  this->mStateVariables.m_FormationSlot[2][5].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax2;
  this->mStateVariables.m_FormationSlot[2][6].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin2;
  this->mStateVariables.m_FormationSlot[2][6].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax2;
  this->mStateVariables.m_FormationSlot[2][7].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin2;
  this->mStateVariables.m_FormationSlot[2][7].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax2;
  RadialHysteresisModifierMax3 = data->RadialHysteresisModifierMax3;
  RadialHysteresisModifierMin3 = data->RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][0].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][0].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax3;
  this->mStateVariables.m_FormationSlot[3][1].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][1].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax3;
  this->mStateVariables.m_FormationSlot[3][2].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][2].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax3;
  this->mStateVariables.m_FormationSlot[3][3].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][3].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax3;
  this->mStateVariables.m_FormationSlot[3][4].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][4].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax3;
  this->mStateVariables.m_FormationSlot[3][5].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][5].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax3;
  this->mStateVariables.m_FormationSlot[3][6].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][6].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax3;
  this->mStateVariables.m_FormationSlot[3][7].m_RadialHysteresisModifierMin = RadialHysteresisModifierMin3;
  this->mStateVariables.m_FormationSlot[3][7].m_RadialHysteresisModifierMax = RadialHysteresisModifierMax3;
  this->m_BattleTypeSpecificParameters[0].m_MaxDistance[0] = data->NormalMaxDistance0;
  this->m_BattleTypeSpecificParameters[0].m_MaxDistance[1] = data->NormalMaxDistance1;
  this->m_BattleTypeSpecificParameters[0].m_MaxDistance[2] = data->NormalMaxDistance2;
  this->m_BattleTypeSpecificParameters[0].m_MaxDistance[3] = data->NormalMaxDistance3;
  NormalMaxTimeBeforeSwitchFromRange0 = data->NormalMaxTimeBeforeSwitchFromRange0;
  this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[0] = data->NormalMinTimeBeforeSwitchFromRange0;
  this->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[0] = NormalMaxTimeBeforeSwitchFromRange0;
  v44 = this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[0];
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v44 < 0.0 || NormalMaxTimeBeforeSwitchFromRange0 <= 0.0 )
  {
    this->mStateVariables.m_NextTimeToSwitchFromRange[0] = -1.0;
  }
  else
  {
    v46 = NormalMaxTimeBeforeSwitchFromRange0;
    if ( NormalMaxTimeBeforeSwitchFromRange0 > v44 )
    {
      v46 = UFG::qRandom(NormalMaxTimeBeforeSwitchFromRange0 - v44, (unsigned int *)&UFG::qDefaultSeed) + v44;
      if ( v46 <= v44 )
        v46 = v44;
      if ( v46 >= NormalMaxTimeBeforeSwitchFromRange0 )
        v46 = NormalMaxTimeBeforeSwitchFromRange0;
    }
    this->mStateVariables.m_NextTimeToSwitchFromRange[0] = v46 + mSimTime_Temp;
  }
  NormalMaxTimeBeforeSwitchFromRange1 = data->NormalMaxTimeBeforeSwitchFromRange1;
  this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[1] = data->NormalMinTimeBeforeSwitchFromRange1;
  this->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[1] = NormalMaxTimeBeforeSwitchFromRange1;
  v48 = this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[1];
  v49 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v48 < 0.0 || NormalMaxTimeBeforeSwitchFromRange1 <= 0.0 )
  {
    this->mStateVariables.m_NextTimeToSwitchFromRange[1] = -1.0;
  }
  else
  {
    v50 = NormalMaxTimeBeforeSwitchFromRange1;
    if ( NormalMaxTimeBeforeSwitchFromRange1 > v48 )
    {
      v50 = UFG::qRandom(NormalMaxTimeBeforeSwitchFromRange1 - v48, (unsigned int *)&UFG::qDefaultSeed) + v48;
      if ( v50 <= v48 )
        v50 = v48;
      if ( v50 >= NormalMaxTimeBeforeSwitchFromRange1 )
        v50 = NormalMaxTimeBeforeSwitchFromRange1;
    }
    this->mStateVariables.m_NextTimeToSwitchFromRange[1] = v50 + v49;
  }
  NormalMaxTimeBeforeSwitchFromRange2 = data->NormalMaxTimeBeforeSwitchFromRange2;
  this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[2] = data->NormalMinTimeBeforeSwitchFromRange2;
  this->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[2] = NormalMaxTimeBeforeSwitchFromRange2;
  v52 = this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[2];
  v53 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v52 < 0.0 || NormalMaxTimeBeforeSwitchFromRange2 <= 0.0 )
  {
    this->mStateVariables.m_NextTimeToSwitchFromRange[2] = -1.0;
  }
  else
  {
    v54 = NormalMaxTimeBeforeSwitchFromRange2;
    if ( NormalMaxTimeBeforeSwitchFromRange2 > v52 )
    {
      v54 = UFG::qRandom(NormalMaxTimeBeforeSwitchFromRange2 - v52, (unsigned int *)&UFG::qDefaultSeed) + v52;
      if ( v54 <= v52 )
        v54 = v52;
      if ( v54 >= NormalMaxTimeBeforeSwitchFromRange2 )
        v54 = NormalMaxTimeBeforeSwitchFromRange2;
    }
    this->mStateVariables.m_NextTimeToSwitchFromRange[2] = v54 + v53;
  }
  NormalMaxTimeBeforeCheckPlayersTarget = data->NormalMaxTimeBeforeCheckPlayersTarget;
  this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeCheckPlayersTarget = data->NormalMinTimeBeforeCheckPlayersTarget;
  this->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeCheckPlayersTarget = NormalMaxTimeBeforeCheckPlayersTarget;
  v56 = UFG::Metrics::msInstance.mSimTime_Temp;
  m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  m_MaxTimeBeforeCheckPlayersTarget = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxTimeBeforeCheckPlayersTarget;
  m_MinTimeBeforeCheckPlayersTarget = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MinTimeBeforeCheckPlayersTarget;
  if ( m_MinTimeBeforeCheckPlayersTarget < 0.0 || m_MaxTimeBeforeCheckPlayersTarget <= 0.0 )
  {
    this->mStateVariables.m_NextTimeToCheckPlayersTarget = -1.0;
  }
  else
  {
    v60 = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxTimeBeforeCheckPlayersTarget;
    if ( m_MaxTimeBeforeCheckPlayersTarget > m_MinTimeBeforeCheckPlayersTarget )
    {
      v60 = UFG::qRandom(
              m_MaxTimeBeforeCheckPlayersTarget - m_MinTimeBeforeCheckPlayersTarget,
              (unsigned int *)&UFG::qDefaultSeed)
          + m_MinTimeBeforeCheckPlayersTarget;
      if ( v60 <= m_MinTimeBeforeCheckPlayersTarget )
        v60 = m_MinTimeBeforeCheckPlayersTarget;
      if ( v60 >= m_MaxTimeBeforeCheckPlayersTarget )
        v60 = m_MaxTimeBeforeCheckPlayersTarget;
    }
    this->mStateVariables.m_NextTimeToCheckPlayersTarget = v60 + v56;
  }
  this->m_BattleTypeSpecificParameters[1].m_MaxDistance[0] = data->MobMaxDistance0;
  this->m_BattleTypeSpecificParameters[1].m_MaxDistance[1] = data->MobMaxDistance1;
  this->m_BattleTypeSpecificParameters[1].m_MaxDistance[2] = data->MobMaxDistance2;
  this->m_BattleTypeSpecificParameters[1].m_MaxDistance[3] = data->MobMaxDistance3;
  MobMaxTimeBeforeSwitchFromRange0 = data->MobMaxTimeBeforeSwitchFromRange0;
  this->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[0] = data->MobMinTimeBeforeSwitchFromRange0;
  this->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeSwitchFromRange[0] = MobMaxTimeBeforeSwitchFromRange0;
  v62 = this->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[0];
  v63 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v62 < 0.0 || MobMaxTimeBeforeSwitchFromRange0 <= 0.0 )
  {
    this->mStateVariables.m_NextTimeToSwitchFromRange[0] = -1.0;
  }
  else
  {
    v64 = MobMaxTimeBeforeSwitchFromRange0;
    if ( MobMaxTimeBeforeSwitchFromRange0 > v62 )
    {
      v64 = UFG::qRandom(MobMaxTimeBeforeSwitchFromRange0 - v62, (unsigned int *)&UFG::qDefaultSeed) + v62;
      if ( v64 <= v62 )
        v64 = v62;
      if ( v64 >= MobMaxTimeBeforeSwitchFromRange0 )
        v64 = MobMaxTimeBeforeSwitchFromRange0;
    }
    this->mStateVariables.m_NextTimeToSwitchFromRange[0] = v64 + v63;
  }
  MobMaxTimeBeforeSwitchFromRange1 = data->MobMaxTimeBeforeSwitchFromRange1;
  this->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[1] = data->MobMinTimeBeforeSwitchFromRange1;
  this->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeSwitchFromRange[1] = MobMaxTimeBeforeSwitchFromRange1;
  v66 = this->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[1];
  v67 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v66 < 0.0 || MobMaxTimeBeforeSwitchFromRange1 <= 0.0 )
  {
    this->mStateVariables.m_NextTimeToSwitchFromRange[1] = -1.0;
  }
  else
  {
    v68 = MobMaxTimeBeforeSwitchFromRange1;
    if ( MobMaxTimeBeforeSwitchFromRange1 > v66 )
    {
      v68 = UFG::qRandom(MobMaxTimeBeforeSwitchFromRange1 - v66, (unsigned int *)&UFG::qDefaultSeed) + v66;
      if ( v68 <= v66 )
        v68 = v66;
      if ( v68 >= MobMaxTimeBeforeSwitchFromRange1 )
        v68 = MobMaxTimeBeforeSwitchFromRange1;
    }
    this->mStateVariables.m_NextTimeToSwitchFromRange[1] = v68 + v67;
  }
  MobMaxTimeBeforeSwitchFromRange2 = data->MobMaxTimeBeforeSwitchFromRange2;
  this->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[2] = data->MobMinTimeBeforeSwitchFromRange2;
  this->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeSwitchFromRange[2] = MobMaxTimeBeforeSwitchFromRange2;
  v70 = this->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeSwitchFromRange[2];
  v71 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v70 < 0.0 || MobMaxTimeBeforeSwitchFromRange2 <= 0.0 )
  {
    this->mStateVariables.m_NextTimeToSwitchFromRange[2] = -1.0;
  }
  else
  {
    v72 = MobMaxTimeBeforeSwitchFromRange2;
    if ( MobMaxTimeBeforeSwitchFromRange2 > v70 )
    {
      v72 = UFG::qRandom(MobMaxTimeBeforeSwitchFromRange2 - v70, (unsigned int *)&UFG::qDefaultSeed) + v70;
      if ( v72 <= v70 )
        v72 = v70;
      if ( v72 >= MobMaxTimeBeforeSwitchFromRange2 )
        v72 = MobMaxTimeBeforeSwitchFromRange2;
    }
    this->mStateVariables.m_NextTimeToSwitchFromRange[2] = v72 + v71;
  }
  MobMaxTimeBeforeCheckPlayersTarget = data->MobMaxTimeBeforeCheckPlayersTarget;
  this->m_BattleTypeSpecificParameters[1].m_MinTimeBeforeCheckPlayersTarget = data->MobMinTimeBeforeCheckPlayersTarget;
  this->m_BattleTypeSpecificParameters[1].m_MaxTimeBeforeCheckPlayersTarget = MobMaxTimeBeforeCheckPlayersTarget;
  v74 = UFG::Metrics::msInstance.mSimTime_Temp;
  v75 = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  v76 = this->m_BattleTypeSpecificParameters[v75].m_MaxTimeBeforeCheckPlayersTarget;
  v77 = this->m_BattleTypeSpecificParameters[v75].m_MinTimeBeforeCheckPlayersTarget;
  if ( v77 < 0.0 || v76 <= 0.0 )
  {
    this->mStateVariables.m_NextTimeToCheckPlayersTarget = -1.0;
  }
  else
  {
    v78 = this->m_BattleTypeSpecificParameters[v75].m_MaxTimeBeforeCheckPlayersTarget;
    if ( v76 > v77 )
    {
      v78 = UFG::qRandom(v76 - v77, (unsigned int *)&UFG::qDefaultSeed) + v77;
      if ( v78 <= v77 )
        v78 = v77;
      if ( v78 >= v76 )
        v78 = v76;
    }
    this->mStateVariables.m_NextTimeToCheckPlayersTarget = v78 + v74;
  }
  this->m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = data->MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
  mOffset = data->FacingTypeEnumString.mOffset;
  if ( mOffset )
  {
    v80 = (char *)&data->FacingTypeEnumString + mOffset;
    if ( v80 )
    {
      if ( *v80 )
      {
        v81 = UFG::FormationFacingTypeNames;
        while ( (unsigned int)UFG::qStringCompareInsensitive(*v81, v80, -1) )
        {
          ++v81;
          ++v3;
          if ( (__int64)v81 >= (__int64)UFG::FormationMovementDirectionNames )
            return;
        }
        this->m_FormationFacingType = v3;
      }
    }
  }
}   return;
        }
        this->m_FormationFacingType = v3;
      }
    }
  }
}

// File Line: 425
// RVA: 0x378A90
void __fastcall UFG::FormationManagerComponent::OnAttach(UFG::FormationManagerComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *p_m_pAIEntityComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *p_m_pAttackRightsComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax

  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->m_pTransformNodeComponent,
    object);
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = this->m_pAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pAIEntityComponent.m_pSimObject = 0i64;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    goto LABEL_8;
  }
  if ( this->m_pAIEntityComponent.m_pSimObject
    && (p_m_pAIEntityComponent->mPrev != p_m_pAIEntityComponent
     || this->m_pAIEntityComponent.mNext != &this->m_pAIEntityComponent) )
  {
    v7 = p_m_pAIEntityComponent->mPrev;
    v8 = this->m_pAIEntityComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  this->m_pAIEntityComponent.m_Changed = 1;
  this->m_pAIEntityComponent.m_pSimObject = object;
  this->m_pAIEntityComponent.m_TypeUID = UFG::AIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::BindInternal<UFG::SimObject>(p_m_pAIEntityComponent, object);
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v10 = p_m_pActionTreeComponent->mPrev;
    v11 = this->m_pActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_15;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v12 = p_m_pActionTreeComponent->mPrev;
    v13 = this->m_pActionTreeComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pActionTreeComponent.m_Changed = 1;
  this->m_pActionTreeComponent.m_pSimObject = object;
  this->m_pActionTreeComponent.m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pActionTreeComponent,
    object);
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v15 = p_m_pTargetingSystemBaseComponent->mPrev;
    v16 = this->m_pTargetingSystemBaseComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    goto LABEL_22;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
     || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v17 = p_m_pTargetingSystemBaseComponent->mPrev;
    v18 = this->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  this->m_pTargetingSystemBaseComponent.m_pSimObject = object;
  this->m_pTargetingSystemBaseComponent.m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pTargetingSystemBaseComponent,
    object);
  p_m_pAttackRightsComponent = &this->m_pAttackRightsComponent;
  if ( this->m_pAttackRightsComponent.m_pSimComponent )
  {
    v20 = p_m_pAttackRightsComponent->mPrev;
    v21 = this->m_pAttackRightsComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    this->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pAttackRightsComponent.m_pSimObject = 0i64;
    this->m_pAttackRightsComponent.mNext = &this->m_pAttackRightsComponent;
    p_m_pAttackRightsComponent->mPrev = p_m_pAttackRightsComponent;
    goto LABEL_29;
  }
  if ( this->m_pAttackRightsComponent.m_pSimObject
    && (p_m_pAttackRightsComponent->mPrev != p_m_pAttackRightsComponent
     || this->m_pAttackRightsComponent.mNext != &this->m_pAttackRightsComponent) )
  {
    v22 = p_m_pAttackRightsComponent->mPrev;
    v23 = this->m_pAttackRightsComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pAttackRightsComponent.m_Changed = 1;
  this->m_pAttackRightsComponent.m_pSimObject = object;
  this->m_pAttackRightsComponent.m_TypeUID = UFG::AttackRightsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pAttackRightsComponent,
    object);
}

// File Line: 434
// RVA: 0x37A4C0
void __fastcall UFG::FormationManagerComponent::OnDetach(UFG::FormationManagerComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_m_pTransformNodeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *p_m_pAttackRightsComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax

  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = this->m_pTransformNodeComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pTransformNodeComponent->m_pSimObject = 0i64;
    p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    goto LABEL_8;
  }
  if ( this->m_pTransformNodeComponent.m_pSimObject
    && (p_m_pTransformNodeComponent->mPrev != p_m_pTransformNodeComponent
     || this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
  {
    v5 = p_m_pTransformNodeComponent->mPrev;
    v6 = p_m_pTransformNodeComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  p_m_pTransformNodeComponent->m_Changed = 1;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    v8 = p_m_pAIEntityComponent->mPrev;
    v9 = this->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pAIEntityComponent.m_pSimObject = 0i64;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    goto LABEL_15;
  }
  if ( this->m_pAIEntityComponent.m_pSimObject
    && (p_m_pAIEntityComponent->mPrev != p_m_pAIEntityComponent
     || this->m_pAIEntityComponent.mNext != &this->m_pAIEntityComponent) )
  {
    v10 = p_m_pAIEntityComponent->mPrev;
    v11 = this->m_pAIEntityComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pAIEntityComponent.m_Changed = 1;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v13 = p_m_pActionTreeComponent->mPrev;
    v14 = this->m_pActionTreeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_22;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v15 = p_m_pActionTreeComponent->mPrev;
    v16 = this->m_pActionTreeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pActionTreeComponent.m_Changed = 1;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v18 = p_m_pTargetingSystemBaseComponent->mPrev;
    v19 = this->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    goto LABEL_29;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
     || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v20 = p_m_pTargetingSystemBaseComponent->mPrev;
    v21 = this->m_pTargetingSystemBaseComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  p_m_pAttackRightsComponent = &this->m_pAttackRightsComponent;
  if ( this->m_pAttackRightsComponent.m_pSimComponent )
  {
    v23 = p_m_pAttackRightsComponent->mPrev;
    v24 = this->m_pAttackRightsComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pAttackRightsComponent.m_pSimObject = 0i64;
    this->m_pAttackRightsComponent.mNext = &this->m_pAttackRightsComponent;
    p_m_pAttackRightsComponent->mPrev = p_m_pAttackRightsComponent;
    goto LABEL_36;
  }
  if ( this->m_pAttackRightsComponent.m_pSimObject
    && (p_m_pAttackRightsComponent->mPrev != p_m_pAttackRightsComponent
     || this->m_pAttackRightsComponent.mNext != &this->m_pAttackRightsComponent) )
  {
    v25 = p_m_pAttackRightsComponent->mPrev;
    v26 = this->m_pAttackRightsComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pAttackRightsComponent.m_Changed = 1;
  UFG::FormationManagerComponent::Clear(this);
}

// File Line: 445
// RVA: 0x349BD0
void UFG::FormationManagerComponent::BeginFrame(void)
{
  int v0; // eax
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v1; // rdx
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *mNext; // rcx

  v0 = 0;
  v1 = UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mNext - 4;
  UFG::FormationManagerComponent::s_TotalFormationManagerComponents = 0;
  if ( (UFG::qList<UFG::FormationManagerComponent,UFG::FormationManagerComponent,1,0> *)&UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mNext[-4] != &UFG::FormationManagerComponent::s_FormationManagerComponentList - 4 )
  {
    do
    {
      mNext = v1[4].mNext;
      HIDWORD(v1[439].mNext) = v0;
      v0 = ++UFG::FormationManagerComponent::s_TotalFormationManagerComponents;
      v1 = mNext - 4;
    }
    while ( &mNext[-4] != (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)(&UFG::FormationManagerComponent::s_FormationManagerComponentList - 4) );
  }
}

// File Line: 472
// RVA: 0x3878D0
char __fastcall UFG::FormationManagerComponent::SetNumSlotsPerRange(
        UFG::FormationManagerComponent *this,
        int range_index,
        int num_slots)
{
  __int64 v5; // r14
  __int64 v6; // rsi
  UFG::GetInFormationNode **v7; // rbx
  UFG::GetInFormationNode *v8; // rax
  __int64 m_RangeIndex; // rdx
  __int64 m_SlotIndex; // r8

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
      m_RangeIndex = v8->m_RangeIndex;
      m_SlotIndex = v8->m_SlotIndex;
      if ( (_DWORD)m_RangeIndex != -1
        && (_DWORD)m_SlotIndex != -1
        && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == v8 )
      {
        UFG::FormationManagerComponent::Unregister(this, m_RangeIndex, m_SlotIndex);
      }
    }
    v7 += 25;
    --v6;
  }
  while ( v6 );
  this->m_NumSlotsPerRange[v5] = num_slots;
  this->m_PrevNumSlotsPerRange[v5] = num_slots;
  this->m_NumFreeSlotsPerRange[v5] = num_slots;
  return 1;
}

// File Line: 518
// RVA: 0x38F230
void __fastcall UFG::FormationManagerComponent::Update(UFG::FormationManagerComponent *this, float delta_sec)
{
  bool v3; // bl
  __int64 v4; // rdx
  __int64 v5; // r8

  v3 = UFG::Metrics::msInstance.mSimFrameCount % UFG::FormationManagerComponent::s_TotalFormationManagerComponents == this->mStateVariables.m_MyID;
  UFG::FormationManagerComponent::CheckIfSprinting(this);
  UFG::FormationManagerComponent::DecideCurrentProfile(this);
  UFG::FormationManagerComponent::UnregisterIncorrectlyRegisteredPeople(this);
  UFG::FormationManagerComponent::UnregisterDownedPeople(this);
  UFG::FormationManagerComponent::CountNumFreeSlots(this);
  UFG::FormationManagerComponent::MaybeSendMeleeFightStimulus(this);
  UFG::FormationManagerComponent::MaybeSwitchRanges(this, v4, v5);
  UFG::FormationManagerComponent::UpdateAbsolutePositions(this);
  UFG::FormationManagerComponent::UpdateDesiredFacing(this);
  UFG::FormationManagerComponent::CheckIfInDesiredPosition(this);
  UFG::FormationManagerComponent::MaybeSetDesiredPositionFromProfile(this);
  UFG::FormationManagerComponent::UpdateDesiredPositionsIfLocked(this);
  if ( v3 )
  {
    UFG::FormationManagerComponent::UpdateDesiredPositionIfNotInRange(this);
    UFG::FormationManagerComponent::UpdateDesiredPositionIfNotAtCorrectAngle(this);
    UFG::FormationManagerComponent::UpdateDesiredPositionIfInsideWall(this);
    UFG::FormationManagerComponent::SpreadOutDesiredPositions(this, delta_sec);
    ++this->mStateVariables.m_ExpensiveUpdateCount;
  }
  UFG::FormationManagerComponent::MaybeShuffleLaterally(this);
}

// File Line: 562
// RVA: 0x34DCF0
void __fastcall UFG::FormationManagerComponent::CheckIfSprinting(UFG::FormationManagerComponent *this)
{
  unsigned int v2; // eax
  unsigned int MostUsedIndex; // eax

  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v2 = _S17_1;
    if ( (_S17_1 & 1) == 0 )
    {
      _S17_1 |= 1u;
      SprintingUID.mUID = UFG::qStringHashUpper32("Sprinting", -1);
      v2 = _S17_1;
    }
    if ( (v2 & 2) != 0 )
    {
      MostUsedIndex = mostUsedIndex_Sprinting;
    }
    else
    {
      _S17_1 = v2 | 2;
      MostUsedIndex = GetMostUsedIndex(SprintingUID.mUID);
      mostUsedIndex_Sprinting = MostUsedIndex;
    }
    this->mStateVariables.m_CurrentlySprinting = ActionController::IsPlaying(
                                                   (ActionController *)&this->m_pActionTreeComponent.m_pSimComponent[3],
                                                   &SprintingUID,
                                                   MostUsedIndex,
                                                   1);
  }
}

// File Line: 601
// RVA: 0x351B40
void __fastcall UFG::FormationManagerComponent::DecideCurrentProfile(UFG::FormationManagerComponent *this)
{
  int v2; // edi
  int v3; // eax
  UFG::FormationProfile *v4; // rbx

  if ( (_S12_1 & 1) == 0 )
    _S12_1 |= 1u;
  this->mStateVariables.m_pCurrentProfile = (UFG::FormationProfile *)&dword_1423C1AC0;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v2 = 0;
    v3 = UFG::FormationManagerComponent::s_NumProfiles;
    if ( UFG::FormationManagerComponent::s_NumProfiles > 0 )
    {
      v4 = (UFG::FormationProfile *)&UFG::FormationManagerComponent::s_Profiles;
      do
      {
        if ( v4->m_NameID.mUID )
        {
          if ( ActionController::IsPlaying(
                 (ActionController *)&this->m_pActionTreeComponent.m_pSimComponent[3],
                 &v4->m_NameID,
                 0xFFFFFFFF,
                 1) )
          {
            this->mStateVariables.m_pCurrentProfile = v4;
            return;
          }
          v3 = UFG::FormationManagerComponent::s_NumProfiles;
        }
        ++v2;
        ++v4;
      }
      while ( v2 < v3 );
    }
  }
}

// File Line: 623
// RVA: 0x38AA30
void __fastcall UFG::FormationManagerComponent::UnregisterIncorrectlyRegisteredPeople(
        UFG::FormationManagerComponent *this)
{
  int v2; // ebx
  int *m_NumFreeSlotsPerRange; // r11
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **p_mNext; // rdi
  int v5; // r10d
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

  v2 = 0;
  if ( this->m_NumRanges > 0 )
  {
    m_NumFreeSlotsPerRange = this->m_NumFreeSlotsPerRange;
    p_mNext = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.mNext;
    do
    {
      v5 = 0;
      if ( *(m_NumFreeSlotsPerRange - 8) > 0 )
      {
        v6 = p_mNext;
        do
        {
          v7 = (__int64)*(v6 - 2);
          if ( v7 && (*(_DWORD *)(v7 + 40) != v2 || *(_DWORD *)(v7 + 44) != v5) )
          {
            v8 = (__int64)*(v6 - 4);
            v9 = *(v6 - 3);
            *(_QWORD *)(v8 + 8) = v9;
            *v9 = v8;
            *(v6 - 4) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v6 - 4);
            *(v6 - 3) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v6 - 4);
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
            ++*m_NumFreeSlotsPerRange;
          }
          ++v5;
          v6 += 25;
        }
        while ( v5 < *(m_NumFreeSlotsPerRange - 8) );
      }
      ++v2;
      p_mNext += 200;
      ++m_NumFreeSlotsPerRange;
    }
    while ( v2 < this->m_NumRanges );
  }
}

// File Line: 649
// RVA: 0x38A4A0
void __fastcall UFG::FormationManagerComponent::UnregisterDownedPeople(UFG::FormationManagerComponent *this)
{
  int v1; // r14d
  int *m_NumSlotsPerRange; // rbp
  UFG::GetInFormationNode **p_m_pPointer; // r15
  int v5; // edi
  UFG::GetInFormationNode **v6; // rbx
  UFG::SimObject *v7; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  bool v9; // r8
  UFG::SimObject *m_pSimObject; // rcx
  bool v11; // dl
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  bool v13; // al
  UFG::GetInFormationNode *v14; // r10
  __int64 m_RangeIndex; // rdx
  __int64 m_SlotIndex; // r8

  v1 = 0;
  if ( this->m_NumRanges > 0 )
  {
    m_NumSlotsPerRange = this->m_NumSlotsPerRange;
    p_m_pPointer = &this->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer;
    do
    {
      v5 = 0;
      if ( *m_NumSlotsPerRange > 0 )
      {
        v6 = p_m_pPointer;
        do
        {
          v7 = (UFG::SimObject *)v6[3];
          if ( v7 )
          {
            ComponentOfType = UFG::SimObject::GetComponentOfType(v7, UFG::ActiveAIEntityComponent::_TypeUID);
            v9 = ComponentOfType && (ComponentOfType->m_Flags & 3) == 1;
            v11 = 0;
            if ( ComponentOfType )
            {
              m_pSimObject = ComponentOfType[6].m_pSimObject;
              if ( m_pSimObject )
              {
                if ( !BYTE4(m_pSimObject->m_UnboundComponentHandles.mNode.mPrev) )
                  v11 = 1;
              }
            }
            v13 = 0;
            if ( ComponentOfType )
            {
              vfptr = ComponentOfType[30].vfptr;
              if ( vfptr )
              {
                if ( (UFG::FormationManagerComponent *)vfptr[1216].__vecDelDtor == this )
                  v13 = 1;
              }
            }
            if ( !v9 || !v11 || !v13 )
            {
              v14 = *v6;
              if ( *v6 )
              {
                m_RangeIndex = v14->m_RangeIndex;
                m_SlotIndex = v14->m_SlotIndex;
                if ( (_DWORD)m_RangeIndex != -1
                  && (_DWORD)m_SlotIndex != -1
                  && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == v14 )
                {
                  UFG::FormationManagerComponent::Unregister(this, m_RangeIndex, m_SlotIndex);
                }
              }
            }
          }
          ++v5;
          v6 += 25;
        }
        while ( v5 < *m_NumSlotsPerRange );
      }
      ++v1;
      ++m_NumSlotsPerRange;
      p_m_pPointer += 200;
    }
    while ( v1 < this->m_NumRanges );
  }
}

// File Line: 668
// RVA: 0x350890
void __fastcall UFG::FormationManagerComponent::CountNumFreeSlots(UFG::FormationManagerComponent *this)
{
  int v2; // r9d
  UFG::SimObject **p_m_pPointer; // r10
  int *m_NumSlotsPerRange; // rdx
  __int64 v5; // r8
  int v6; // ecx
  UFG::SimObject **v7; // rax

  v2 = 0;
  if ( this->m_NumRanges > 0 )
  {
    p_m_pPointer = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
    m_NumSlotsPerRange = this->m_NumSlotsPerRange;
    do
    {
      v5 = (unsigned int)*m_NumSlotsPerRange;
      v6 = 0;
      m_NumSlotsPerRange[8] = 0;
      if ( (int)v5 > 0 )
      {
        v7 = p_m_pPointer;
        do
        {
          if ( !*v7 )
            m_NumSlotsPerRange[8] = ++v6;
          v7 += 25;
          --v5;
        }
        while ( v5 );
      }
      ++v2;
      ++m_NumSlotsPerRange;
      p_m_pPointer += 200;
    }
    while ( v2 < this->m_NumRanges );
  }
}

// File Line: 689
// RVA: 0x375170
void __fastcall UFG::FormationManagerComponent::MaybeSendMeleeFightStimulus(UFG::FormationManagerComponent *this)
{
  int m_NumRanges; // ecx
  char v3; // r9
  int v4; // r8d
  int *m_NumSlotsPerRange; // rdx
  char v6; // bl
  char v7; // r12
  UFG::TransformNodeComponent *m_pSimComponent; // rdi
  float v9; // xmm6_4
  int v10; // r13d
  UFG::SimObject **p_m_pPointer; // rax
  int *v12; // r14
  int v13; // ebp
  UFG::SimObject **v14; // rsi
  UFG::SimObject *v15; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __m128 y_low; // xmm1
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectCharacter *v19; // rdi
  UFG::StimulusManager *v20; // rbx
  UFG::SimObject *m_pSimObject; // rsi
  UFG::StimulusManager *v22; // rbp
  UFG::SimComponent *v23; // rbx
  UFG::TransformNodeComponent *v24; // rdi
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-68h] BYREF
  char v26; // [rsp+A0h] [rbp+8h]
  UFG::SimObject **v27; // [rsp+A8h] [rbp+10h]
  UFG::TransformNodeComponent *v28; // [rsp+B0h] [rbp+18h]

  m_NumRanges = this->m_NumRanges;
  v3 = 0;
  v4 = 0;
  if ( m_NumRanges > 0 )
  {
    m_NumSlotsPerRange = this->m_NumSlotsPerRange;
    while ( m_NumSlotsPerRange[8] == *m_NumSlotsPerRange )
    {
      ++v4;
      ++m_NumSlotsPerRange;
      if ( v4 >= m_NumRanges )
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
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v28 = m_pSimComponent;
  if ( !m_pSimComponent )
    goto LABEL_32;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  v9 = FLOAT_10_0;
  if ( this->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus
    || this->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus )
  {
    v9 = FLOAT_15_0;
  }
  v10 = 0;
  if ( this->m_NumRanges <= 0 )
    goto LABEL_32;
  p_m_pPointer = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  v12 = this->m_NumSlotsPerRange;
  v27 = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  while ( 1 )
  {
    v13 = 0;
    if ( *v12 > 0 )
      break;
LABEL_27:
    p_m_pPointer += 200;
    ++v10;
    ++v12;
    v27 = p_m_pPointer;
    if ( v10 >= this->m_NumRanges )
    {
      v6 = 0;
      goto $done_1;
    }
  }
  v14 = p_m_pPointer;
  while ( 1 )
  {
    v15 = *v14;
    if ( *v14 )
      m_pTransformNodeComponent = v15->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    if ( !v15 )
      goto LABEL_25;
    if ( !m_pTransformNodeComponent )
      goto LABEL_25;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - v28->mWorldTransform.v3.y)
                              * (float)(y_low.m128_f32[0] - v28->mWorldTransform.v3.y))
                      + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v28->mWorldTransform.v3.x)
                              * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v28->mWorldTransform.v3.x));
    if ( _mm_sqrt_ps(y_low).m128_f32[0] > v9 )
      goto LABEL_25;
    ComponentOfType = UFG::SimObject::GetComponentOfType(v15, UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    if ( !ComponentOfType )
      goto LABEL_25;
    if ( LODWORD(ComponentOfType[3].m_SafePointerList.mNode.mPrev) != 17 )
      break;
    v7 = 1;
LABEL_25:
    ++v13;
    v14 += 25;
    if ( v13 >= *v12 )
    {
      p_m_pPointer = v27;
      goto LABEL_27;
    }
  }
  v6 = 1;
  v26 = 1;
$done_1:
  if ( !v7 )
  {
LABEL_32:
    if ( this->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus )
    {
      UFG::StimulusManager::EndStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_MELEE_FIGHT_VS_INNOCENT,
        this->m_pSimObject);
      this->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus = 0;
    }
    goto LABEL_34;
  }
  if ( v6 )
  {
    v6 = 1;
    goto LABEL_32;
  }
  if ( !this->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus )
  {
    m_pSimObject = this->m_pSimObject;
    v22 = UFG::StimulusManager::s_pInstance;
    stimulus_parameters.m_MaxStimulusDuration = -1.0;
    stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
    if ( m_pSimObject )
    {
      v23 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::StimulusEmitterComponent::_TypeUID);
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
          v23 = v24;
        }
        while ( v24 );
      }
      v6 = v26;
    }
    UFG::StimulusManager::AttachStimulusEmitterComponent(v22, &stru_1423BFC70, &stimulus_parameters, m_pSimObject, 0);
    this->mStateVariables.m_CurrentlyEmittingFightVSInnocentStimulus = 1;
  }
LABEL_34:
  v19 = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( v19 != LocalPlayer )
  {
    if ( v6 )
    {
      if ( !this->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus )
      {
        v20 = UFG::StimulusManager::s_pInstance;
        stimulus_parameters.m_MaxStimulusDuration = -1.0;
        stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
        stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
        stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
        UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_MELEE_FIGHT_VS_COMBATANT,
          v19,
          eTARGET_TYPE_INVALID);
        UFG::StimulusManager::AttachStimulusEmitterComponent(v20, &stru_1423BFC28, &stimulus_parameters, v19, 0);
        this->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus = 1;
      }
    }
    else if ( this->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus )
    {
      UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_MELEE_FIGHT_VS_COMBATANT, v19);
      this->mStateVariables.m_CurrentlyEmittingFightVSCombatantStimulus = 0;
    }
  }
}

// File Line: 884
// RVA: 0x387F20
void __fastcall UFG::FormationManagerComponent::SetTimeToDoSomething(
        UFG::FormationManagerComponent *this,
        float min_time,
        float max_time,
        float *next_time)
{
  float mSimTime_Temp; // xmm8_4
  float v6; // xmm0_4

  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( min_time < 0.0 || max_time <= 0.0 )
  {
    *next_time = -1.0;
  }
  else
  {
    v6 = max_time;
    if ( max_time > min_time )
    {
      v6 = UFG::qRandom(max_time - min_time, (unsigned int *)&UFG::qDefaultSeed) + min_time;
      if ( v6 <= min_time )
        v6 = min_time;
      if ( v6 >= max_time )
        v6 = max_time;
    }
    *next_time = v6 + mSimTime_Temp;
  }
}

// File Line: 1098
// RVA: 0x3770B0
void __fastcall UFG::FormationManagerComponent::MaybeSwitchRanges(
        UFG::FormationManagerComponent *this,
        __int64 a2,
        __int64 m_pSimObject)
{
  float mSimTime_Temp; // xmm10_4
  __int64 v5; // rbp
  int i; // r15d
  UFG::HasAttackRequestNode *v7; // rdx
  UFG::HasAttackRequestNode *NextAttacker; // rax
  UFG::GetInFormationNode *m_pPointer; // rdi
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rcx
  int v13; // r14d
  UFG::GetInFormationNode *v14; // rsi
  __int64 m_RangeIndex; // r9
  __int64 m_SlotIndex; // r8
  __int64 v17; // r9
  __int64 v18; // r8
  int v19; // r8d
  __int64 v20; // rdx
  __int64 v21; // r8
  int v22; // r15d
  __int64 v23; // r12
  UFG::SimObject **p_m_pPointer; // r13
  int *v25; // r14
  float v26; // xmm0_4
  signed int v27; // ecx
  signed int v28; // edi
  int v29; // esi
  int v30; // eax
  int v31; // edx
  int v32; // ebp
  int v33; // eax
  __int64 v34; // rdx
  int v35; // ecx
  int v36; // ecx
  __int64 v37; // r8
  UFG::SimObject **v38; // rax
  int v39; // edx
  __int64 v40; // rcx
  __int64 v41; // r9
  _QWORD *v42; // rax
  UFG::GetInFormationNode *v43; // rsi
  UFG::GetInFormationNode *v44; // rdi
  __int64 v45; // rdx
  __int64 v46; // r8
  __int64 v47; // rdx
  __int64 v48; // r8
  float v49; // xmm8_4
  __int64 v50; // rcx
  float v51; // xmm7_4
  float v52; // xmm6_4
  float v53; // xmm0_4
  __int64 range_index; // [rsp+B0h] [rbp+8h] BYREF
  int slot_index; // [rsp+B8h] [rbp+10h] BYREF

  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( !this->mStateVariables.m_RangeSwitchesFrozen )
  {
    if ( this->m_pAttackRightsComponent.m_pSimComponent )
    {
      v5 = 0i64;
      for ( i = 0; i < this->m_NumSlotsPerRange[0]; ++i )
      {
        v7 = 0i64;
        if ( v5 )
        {
          if ( v5 != 1 )
            goto LABEL_9;
          NextAttacker = UFG::AttackRightsComponent::GetNextAttacker(
                           (UFG::AttackRightsComponent *)this->m_pAttackRightsComponent.m_pSimComponent,
                           eATTACK_TYPE_MELEE,
                           m_pSimObject);
        }
        else
        {
          NextAttacker = UFG::AttackRightsComponent::GetCurrentAttacker(
                           (UFG::AttackRightsComponent *)this->m_pAttackRightsComponent.m_pSimComponent,
                           eATTACK_TYPE_MELEE);
        }
        v7 = NextAttacker;
LABEL_9:
        m_pPointer = this->mStateVariables.m_FormationSlot[0][v5].m_pMember.m_pPointer;
        if ( v7 )
        {
          if ( m_pPointer )
          {
            v10 = v7->m_pOwner.m_pPointer;
            if ( v10 )
              m_pSimObject = (__int64)v10->m_pSimObject;
            else
              m_pSimObject = 0i64;
            v11 = m_pPointer->m_pOwner.m_pPointer;
            if ( v11 )
              v12 = v11->m_pSimObject;
            else
              v12 = 0i64;
            if ( (UFG::SimObject *)m_pSimObject == v12 )
              goto LABEL_37;
            LODWORD(range_index) = -1;
            slot_index = -1;
            if ( !UFG::FormationManagerComponent::FindRangeAndSlotIndex(this, v7, (int *)&range_index, &slot_index) )
              goto LABEL_37;
            v13 = range_index;
            v14 = this->mStateVariables.m_FormationSlot[(int)range_index][slot_index].m_pMember.m_pPointer;
            if ( v14 )
            {
              m_RangeIndex = v14->m_RangeIndex;
              m_SlotIndex = v14->m_SlotIndex;
              if ( (_DWORD)m_RangeIndex != -1
                && (_DWORD)m_SlotIndex != -1
                && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == v14 )
              {
                UFG::FormationManagerComponent::Unregister(this, m_RangeIndex, m_SlotIndex);
              }
            }
            v17 = m_pPointer->m_RangeIndex;
            v18 = m_pPointer->m_SlotIndex;
            if ( (_DWORD)v17 != -1
              && (_DWORD)v18 != -1
              && this->mStateVariables.m_FormationSlot[v17][v18].m_pMember.m_pPointer == m_pPointer )
            {
              UFG::FormationManagerComponent::Unregister(this, v17, v18);
            }
            UFG::FormationManagerComponent::Register(this, v14, 0, 1);
            v19 = v13;
            goto LABEL_36;
          }
          LODWORD(range_index) = -1;
          slot_index = -1;
          if ( UFG::FormationManagerComponent::FindRangeAndSlotIndex(this, v7, (int *)&range_index, &slot_index) )
          {
            m_pPointer = this->mStateVariables.m_FormationSlot[(int)range_index][slot_index].m_pMember.m_pPointer;
            if ( m_pPointer )
            {
              v20 = m_pPointer->m_RangeIndex;
              v21 = m_pPointer->m_SlotIndex;
              if ( (_DWORD)v20 != -1
                && (_DWORD)v21 != -1
                && this->mStateVariables.m_FormationSlot[v20][v21].m_pMember.m_pPointer == m_pPointer )
              {
                UFG::FormationManagerComponent::Unregister(this, v20, v21);
              }
            }
            v19 = 0;
LABEL_36:
            UFG::FormationManagerComponent::Register(this, m_pPointer, v19, 1);
          }
        }
LABEL_37:
        ++v5;
      }
    }
  }
  v22 = 1;
  v23 = 1i64;
  if ( this->m_NumRanges - 1 > 1 )
  {
    p_m_pPointer = &this->mStateVariables.m_FormationSlot[1][0].m_pMemberSimObject.m_pPointer;
    v25 = &this->m_NumSlotsPerRange[2];
    range_index = -332i64 - (_QWORD)this;
    do
    {
      v26 = *((float *)v25 + 66);
      if ( v26 > 0.0 && mSimTime_Temp >= v26 )
      {
        v27 = *(v25 - 1) - v25[7];
        v28 = *v25 - v25[8];
        if ( v27 > 0 && v28 > 0 )
        {
          v29 = v27 - 1;
          v30 = UFG::qRandom(v27, (unsigned int *)&UFG::qDefaultSeed);
          v31 = 0;
          v32 = v28 - 1;
          if ( v30 > 0 )
            v31 = v30;
          if ( v31 < v29 )
            v29 = v31;
          v33 = UFG::qRandom(v28, (unsigned int *)&UFG::qDefaultSeed);
          v34 = *(v25 - 1);
          v35 = 0;
          if ( v33 > 0 )
            v35 = v33;
          if ( v35 < v32 )
            v32 = v35;
          v36 = 0;
          v37 = 0i64;
          if ( v34 > 0 )
          {
            v38 = p_m_pPointer;
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
          v41 = *(int *)((char *)this->m_NumSlotsPerRange + (_QWORD)v25 + range_index);
          if ( v41 > 0 )
          {
            v42 = p_m_pPointer + 200;
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
          v43 = this->mStateVariables.m_FormationSlot[v23][v37].m_pMember.m_pPointer;
          v44 = this->mStateVariables.m_FormationSlot[v23 + 1][v40].m_pMember.m_pPointer;
          if ( v43 )
          {
            v45 = v43->m_RangeIndex;
            v46 = v43->m_SlotIndex;
            if ( (_DWORD)v45 != -1
              && (_DWORD)v46 != -1
              && this->mStateVariables.m_FormationSlot[v45][v46].m_pMember.m_pPointer == v43 )
            {
              UFG::FormationManagerComponent::Unregister(this, v45, v46);
            }
          }
          if ( v44 )
          {
            v47 = v44->m_RangeIndex;
            v48 = v44->m_SlotIndex;
            if ( (_DWORD)v47 != -1
              && (_DWORD)v48 != -1
              && this->mStateVariables.m_FormationSlot[v47][v48].m_pMember.m_pPointer == v44 )
            {
              UFG::FormationManagerComponent::Unregister(this, v47, v48);
            }
          }
          UFG::FormationManagerComponent::Register(this, v43, v22 + 1, 1);
          UFG::FormationManagerComponent::Register(this, v44, v22, 1);
        }
        v49 = UFG::Metrics::msInstance.mSimTime_Temp;
        v50 = v23 + 12i64 * (int)UFG::BattleManager::s_pInstance->m_CurrentBattleType;
        v51 = this->m_BattleTypeSpecificParameters[0].m_MinTimeBeforeSwitchFromRange[v50];
        v52 = this->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[v50];
        if ( v51 < 0.0 || v52 <= 0.0 )
        {
          v25[66] = -1082130432;
        }
        else
        {
          v53 = this->m_BattleTypeSpecificParameters[0].m_MaxTimeBeforeSwitchFromRange[v50];
          if ( v52 > v51 )
          {
            v53 = UFG::qRandom(v52 - v51, (unsigned int *)&UFG::qDefaultSeed) + v51;
            if ( v53 <= v51 )
              v53 = v51;
            if ( v53 >= v52 )
              v53 = v52;
          }
          *((float *)v25 + 66) = v53 + v49;
        }
      }
      ++v22;
      ++v23;
      ++v25;
      p_m_pPointer += 200;
    }
    while ( v22 < this->m_NumRanges - 1 );
  }
}

// File Line: 1243
// RVA: 0x377710
char __fastcall UFG::FormationManagerComponent::NewAngleDoesntCrossOverSomeone(
        UFG::FormationManagerComponent *this,
        int range_index,
        int slot_index,
        unsigned __int16 new_angle)
{
  __int64 v4; // r14
  __int64 v5; // rsi
  int *v6; // r15
  int v7; // ebp
  unsigned __int16 m_Angle; // r13
  unsigned __int16 *i; // rbx
  __int16 v11; // di
  __int16 v12; // ax

  v4 = slot_index;
  v5 = 0i64;
  v6 = (int *)((char *)this + 4 * range_index);
  v7 = 0;
  m_Angle = this->mStateVariables.m_FormationSlot[range_index][slot_index].m_Angle;
  if ( v6[83] <= 0 )
    return 1;
  for ( i = &this->mStateVariables.m_FormationSlot[range_index][0].m_Angle; ; i += 100 )
  {
    if ( v5 != v4 )
    {
      if ( *(_QWORD *)(i + 38) )
      {
        v11 = UFG::qAngleDiff(m_Angle, *i);
        v12 = UFG::qAngleDiff(new_angle, *i);
        if ( v11 > 0 != v12 > 0 || !v12 )
          break;
      }
    }
    ++v7;
    ++v5;
    if ( v7 >= v6[83] )
      return 1;
  }
  return 0;
}

// File Line: 1311
// RVA: 0x376570
void __fastcall UFG::FormationManagerComponent::MaybeShuffleLaterally(UFG::FormationManagerComponent *this)
{
  __int64 v2; // rax
  float mSimTime_Temp; // xmm1_4
  int v4; // r13d
  __int64 v5; // rcx
  bool v6; // r15
  __int64 v7; // rdi
  bool v8; // si
  UFG::SimObject *m_pPointer; // r14
  bool m_RequestedToChangePosition; // r9
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v12; // rcx
  UFG::GetInFormationNode *v13; // rax
  UFG::SimComponent *v14; // rdx
  char m_Flags; // r8
  __int64 vfptr_high; // rdx
  bool v17; // zf
  char v18; // al
  unsigned __int16 v19; // r14
  unsigned __int16 v20; // si
  int v21; // r12d
  float v22; // xmm0_4
  bool m_Clockwise; // r15
  int v24; // r10d
  bool m_AbsolutePosition; // cl
  int v26; // ecx
  int v27; // r8d
  int v28; // edx
  unsigned __int16 m_Angle; // r12
  int v30; // eax
  unsigned __int16 v31; // r12
  float z; // xmm8_4
  float v33; // xmm7_4
  float v34; // xmm0_4
  float m_Distance; // xmm6_4
  float v36; // xmm9_4
  float v37; // xmm8_4
  float v38; // xmm7_4
  UFG::GetInFormationNode *v39; // r15
  UFG::SimComponent *v40; // rax
  UFG::SimObject *m_pSimObject; // r14
  UFG::SimComponent *v42; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimComponent *v44; // r13
  UFG::eAttackType m_AttackType; // r12d
  UFG::CombatRegion *v46; // rcx
  float x; // xmm4_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  float y; // xmm1_4
  float v53; // xmm0_4
  bool v54; // cc
  UFG::SimObject *v55; // rcx
  UFG::SimComponent *v56; // rax
  __int64 v57; // rcx
  bool v58; // r14
  UFG::SimComponent *v59; // rax
  UFG::SimComponent *v60; // r15
  UFG::SimObject *v61; // rcx
  __m128 mPrev_high; // xmm2
  float v63; // xmm1_4
  float v64; // xmm3_4
  bool v65; // al
  float v66; // xmm5_4
  float v67; // xmm6_4
  float v68; // xmm2_4
  float v69; // xmm3_4
  float v70; // xmm4_4
  float v71; // xmm0_4
  UFG::SimObject *v72; // rcx
  UFG::SimComponent *v73; // rax
  __int64 v74; // rcx
  bool v75; // al
  bool IsTooCloseToAngle; // al
  float v77; // xmm4_4
  float v78; // xmm5_4
  float v79; // xmm6_4
  float v80; // xmm2_4
  float v81; // xmm3_4
  UFG::eFormationFacingType m_FacingType; // eax
  bool v83; // [rsp+40h] [rbp-C0h]
  int range_index; // [rsp+44h] [rbp-BCh]
  __int16 v85; // [rsp+48h] [rbp-B8h]
  unsigned __int16 v86; // [rsp+4Ch] [rbp-B4h]
  UFG::qVector3 last_valid_position; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 vPoint; // [rsp+60h] [rbp-A0h] BYREF
  int v89; // [rsp+70h] [rbp-90h]
  int slot_index; // [rsp+74h] [rbp-8Ch]
  int v91; // [rsp+78h] [rbp-88h]
  float v92; // [rsp+7Ch] [rbp-84h]
  int v93; // [rsp+80h] [rbp-80h]
  int v94; // [rsp+84h] [rbp-7Ch]
  int v95; // [rsp+88h] [rbp-78h]
  int v96; // [rsp+8Ch] [rbp-74h]
  __int64 v97; // [rsp+90h] [rbp-70h]
  UFG::qVector3 from_position; // [rsp+98h] [rbp-68h] BYREF
  UFG::qVector3 to_position; // [rsp+A8h] [rbp-58h] BYREF
  __int64 v100; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v101; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v102; // [rsp+C8h] [rbp-38h]
  UFG::SimObject *ray_hit_object; // [rsp+D0h] [rbp-30h] BYREF
  UFG::TransformNodeComponent *m_pSimComponent; // [rsp+D8h] [rbp-28h]
  bool v105; // [rsp+1D0h] [rbp+D0h]
  char v106; // [rsp+1D8h] [rbp+D8h]
  bool v107; // [rsp+1E0h] [rbp+E0h]
  bool v108; // [rsp+1E8h] [rbp+E8h]

  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    v2 = 0i64;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v92 = UFG::Metrics::msInstance.mSimTime_Temp;
    v4 = 0;
    v97 = 0i64;
    range_index = 0;
    while ( v4 < this->m_NumRanges )
    {
      v5 = 0i64;
      slot_index = 0;
      v102 = 0i64;
      if ( this->m_NumSlotsPerRange[v2] <= 0 )
        goto LABEL_65;
      do
      {
        v6 = 0;
        v7 = v5 + 8 * v2;
        v8 = this->mStateVariables.m_FormationSlot[0][v7].m_InPosition == eIN_POSITION
          && mSimTime_Temp > this->mStateVariables.m_FormationSlot[0][v7].m_NextTimeToChangePosition;
        m_pPointer = this->mStateVariables.m_FormationSlot[0][v7].m_pMemberSimObject.m_pPointer;
        m_RequestedToChangePosition = this->mStateVariables.m_FormationSlot[0][v7].m_RequestedToChangePosition;
        v105 = m_RequestedToChangePosition;
        if ( m_pPointer )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActiveAIEntityComponent::_TypeUID);
          m_RequestedToChangePosition = v105;
          v12 = ComponentOfType;
        }
        else
        {
          v12 = 0i64;
        }
        v13 = this->mStateVariables.m_FormationSlot[0][v7].m_pMember.m_pPointer;
        if ( !v12 || !v13 )
          goto LABEL_24;
        v14 = v13->m_pOwner.m_pPointer;
        if ( v14 )
          m_Flags = v14[1].m_Flags;
        else
          m_Flags = 0;
        vfptr_high = SHIDWORD(v12[65].vfptr);
        v6 = m_Flags == 0;
        if ( v13->m_AttackType )
        {
          if ( !v8 )
            goto LABEL_23;
          v17 = !UFG::g_AIObjectiveParams[vfptr_high].m_CircleAroundTargetWhenRanged;
        }
        else
        {
          if ( !v8 )
            goto LABEL_23;
          v17 = !UFG::g_AIObjectiveParams[vfptr_high].m_CircleAroundTargetWhenMelee;
        }
        if ( !v17 )
        {
          v8 = 1;
          goto LABEL_24;
        }
LABEL_23:
        v8 = 0;
LABEL_24:
        if ( !m_pPointer || !v6 || !v8 && !m_RequestedToChangePosition )
          goto LABEL_64;
        v18 = 0;
        v106 = 0;
        if ( m_RequestedToChangePosition )
        {
          m_AbsolutePosition = this->mStateVariables.m_FormationSlot[0][v7].m_PositionChangeRequest.m_AbsolutePosition;
          m_Clockwise = this->mStateVariables.m_FormationSlot[0][v7].m_PositionChangeRequest.m_Clockwise;
          v20 = 7281;
          v19 = 10922;
          v21 = 5;
          v89 = 7281;
          v83 = m_AbsolutePosition;
          v108 = 1;
          v24 = 2;
          v85 = 10922;
          v93 = 5;
        }
        else
        {
          v19 = 12743;
          v20 = 9102;
          v21 = 2;
          v89 = 9102;
          v85 = 12743;
          v93 = 2;
          v108 = v4 == 0;
          v22 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
          v18 = 0;
          m_RequestedToChangePosition = v105;
          m_Clockwise = v22 < 0.5;
          v83 = 0;
          v24 = 1;
        }
        v26 = 0;
        v94 = v24;
        v107 = m_Clockwise;
        v91 = 0;
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
            m_Angle = this->mStateVariables.m_FormationSlot[0][v7].m_Angle;
            if ( m_RequestedToChangePosition )
            {
              v30 = (int)(float)((float)((float)((float)((float)((float)((float)((float)v19 * 360.0) * 0.000015258789)
                                                               - (float)((float)((float)v20 * 360.0) * 0.000015258789))
                                                       * (float)((float)v28 / (float)v27))
                                               + (float)((float)((float)v20 * 360.0) * 0.000015258789))
                                       * 65536.0)
                               * 0.0027777778);
            }
            else
            {
              LOWORD(v30) = v19;
              if ( v19 > (int)v20 )
                LOWORD(v30) = v20 + UFG::qRandom(v19 - (unsigned int)v20 + 1, (unsigned int *)&UFG::qDefaultSeed);
            }
            if ( m_Clockwise )
              v31 = m_Angle - v30;
            else
              v31 = m_Angle + v30;
            v86 = v31;
            z = UFG::qVector3::msZero.z;
            v33 = (float)((float)v31 * 3.1415927) * 0.000030517578;
            v34 = sinf(v33);
            m_Distance = this->mStateVariables.m_FormationSlot[0][v7].m_Distance;
            v36 = v34 * m_Distance;
            v37 = z * m_Distance;
            v38 = cosf(v33) * m_Distance;
            if ( !v108 && !UFG::FormationManagerComponent::NewAngleDoesntCrossOverSomeone(this, v4, slot_index, v31) )
            {
              v18 = v106;
              m_RequestedToChangePosition = v105;
              goto LABEL_61;
            }
            v39 = this->mStateVariables.m_FormationSlot[0][v7].m_pMember.m_pPointer;
            v40 = v39->m_pOwner.m_pPointer;
            if ( !v40 )
            {
              m_pSimObject = 0i64;
LABEL_49:
              v44 = 0i64;
              m_pTransformNodeComponent = 0i64;
              goto LABEL_50;
            }
            m_pSimObject = v40->m_pSimObject;
            if ( !m_pSimObject )
              goto LABEL_49;
            v42 = UFG::SimObject::GetComponentOfType(v40->m_pSimObject, UFG::ActiveAIEntityComponent::_TypeUID);
            m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
            v44 = v42;
LABEL_50:
            if ( this->m_pAIEntityComponent.m_pSimComponent
              && this->m_pTransformNodeComponent.m_pSimComponent
              && m_pSimObject
              && v44
              && m_pTransformNodeComponent )
            {
              m_AttackType = v39->m_AttackType;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              v46 = *(UFG::CombatRegion **)&v44[15].m_TypeUID;
              x = v38 + m_pTransformNodeComponent->mWorldTransform.v3.x;
              v48 = v36 + m_pTransformNodeComponent->mWorldTransform.v3.y;
              v49 = v37 + m_pTransformNodeComponent->mWorldTransform.v3.z;
              v50 = x;
              v51 = v48;
              last_valid_position.x = x;
              last_valid_position.y = v48;
              vPoint.x = x;
              vPoint.y = v48;
              vPoint.z = v49;
              last_valid_position.z = v49;
              if ( v46 )
              {
                if ( !UFG::CombatRegion::IsHitPoint(v46, &vPoint) )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
                  last_valid_position.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
                  v53 = m_pTransformNodeComponent->mWorldTransform.v3.z;
                  last_valid_position.y = y;
                  last_valid_position.z = v53;
LABEL_58:
                  v4 = range_index;
                  m_RequestedToChangePosition = v105;
                  goto LABEL_59;
                }
                v49 = vPoint.z;
                v48 = vPoint.y;
                x = vPoint.x;
                v51 = last_valid_position.y;
                v50 = last_valid_position.x;
              }
              if ( m_AttackType )
              {
                v59 = v39->m_pOwner.m_pPointer;
                if ( v59 && LOBYTE(v59[1].m_Flags) )
                  goto LABEL_85;
                v60 = this->m_pTransformNodeComponent.m_pSimComponent;
                v61 = 0i64;
                if ( v60 )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
                  v61 = 0i64;
                  mPrev_high = (__m128)HIDWORD(v60[2].m_BoundComponentHandles.mNode.mPrev);
                  v63 = *(float *)&v60[2].m_BoundComponentHandles.mNode.mPrev;
                  x = vPoint.x;
                  ray_hit_object = 0i64;
                  v48 = vPoint.y;
                  v64 = *(float *)&v60[2].m_BoundComponentHandles.mNode.mNext;
                  v49 = vPoint.z;
                  LODWORD(from_position.y) = mPrev_high.m128_i32[0];
                  from_position.x = v63;
                  from_position.z = v64;
                  to_position = vPoint;
                  mPrev_high.m128_f32[0] = (float)((float)((float)(mPrev_high.m128_f32[0] - vPoint.y)
                                                         * (float)(mPrev_high.m128_f32[0] - vPoint.y))
                                                 + (float)((float)(v63 - vPoint.x) * (float)(v63 - vPoint.x)))
                                         + (float)((float)(v64 - vPoint.z) * (float)(v64 - vPoint.z));
                  if ( _mm_sqrt_ps(mPrev_high).m128_f32[0] <= 100.0 )
                  {
                    from_position.z = v64 + 1.5;
                    to_position.z = vPoint.z + 1.5;
                    v65 = UFG::DoRaycast(
                            &from_position,
                            &to_position,
                            m_pSimObject,
                            &last_valid_position,
                            &ray_hit_object,
                            0i64,
                            0,
                            &UFG::qColour::Yellow);
                    v61 = ray_hit_object;
                    v49 = vPoint.z;
                    v48 = vPoint.y;
                    x = vPoint.x;
                    v51 = last_valid_position.y;
                    v50 = last_valid_position.x;
                  }
                  else
                  {
                    v51 = last_valid_position.y;
                    v50 = last_valid_position.x;
                    v65 = 0;
                  }
                }
                else
                {
                  v65 = 0;
                }
                if ( v65
                  || !v61
                  && fsqrt(
                       (float)((float)((float)(v51 - v48) * (float)(v51 - v48))
                             + (float)((float)(v50 - x) * (float)(v50 - x)))
                     + (float)((float)(last_valid_position.z - v49) * (float)(last_valid_position.z - v49))) < 0.1 )
                {
LABEL_85:
                  v58 = 1;
                }
                else
                {
                  v66 = m_pTransformNodeComponent->mWorldTransform.v3.x;
                  v67 = m_pTransformNodeComponent->mWorldTransform.v3.y;
                  v58 = 0;
                  v68 = v50 - v66;
                  v69 = v51 - v67;
                  v70 = fsqrt((float)(v69 * v69) + (float)(v68 * v68));
                  if ( v70 > 1.0 )
                  {
                    v71 = (float)(v70 - 1.0) / v70;
                    last_valid_position.z = (float)(v71 * 0.0) + m_pTransformNodeComponent->mWorldTransform.v3.z;
                    last_valid_position.x = (float)(v68 * v71) + v66;
                    last_valid_position.y = (float)(v69 * v71) + v67;
                  }
                }
                if ( (unsigned int)(m_AttackType - 1) > 1 )
                  goto LABEL_87;
                v72 = v44->m_pSimObject;
                if ( v72 )
                  v73 = UFG::SimObject::GetComponentOfType(v72, UFG::NavComponent::_TypeUID);
                else
                  v73 = 0i64;
                v74 = *(__int64 *)((char *)&v73[2].m_BoundComponentHandles.mNode.mNext + 4);
                v100 = v74 | 0x20000000000i64;
                v75 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                        UFG::NavManager::ms_pInstance,
                        (UFG::HavokNavPosition *)&v73[1].m_SafePointerList.mNode.mNext,
                        &vPoint,
                        (UFG::NavParams *)&v100,
                        &last_valid_position);
                if ( !v58 || v75 )
                  goto LABEL_58;
              }
              else
              {
                v55 = this->m_pAIEntityComponent.m_pSimComponent->m_pSimObject;
                if ( v55 )
                  v56 = UFG::SimObject::GetComponentOfType(v55, UFG::NavComponent::_TypeUID);
                else
                  v56 = 0i64;
                v57 = *(__int64 *)((char *)&v56[2].m_BoundComponentHandles.mNode.mNext + 4);
                v101 = v57 | 0x20000000000i64;
                v58 = !UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                         UFG::NavManager::ms_pInstance,
                         (UFG::HavokNavPosition *)&v56[1].m_SafePointerList.mNode.mNext,
                         &vPoint,
                         (UFG::NavParams *)&v101,
                         &last_valid_position);
LABEL_87:
                if ( !v58 )
                  goto LABEL_58;
              }
              v31 = v86;
            }
            m_RequestedToChangePosition = v105;
            v4 = range_index;
            if ( !v105
              || (IsTooCloseToAngle = UFG::FormationManagerComponent::NoOneIsTooCloseToAngle(this, v31, range_index),
                  m_RequestedToChangePosition = v105,
                  IsTooCloseToAngle) )
            {
              v77 = v38 + m_pSimComponent->mWorldTransform.v3.x;
              v78 = v36 + m_pSimComponent->mWorldTransform.v3.y;
              v79 = v37 + m_pSimComponent->mWorldTransform.v3.z;
              v80 = (float)((float)(v38 * v38) + (float)(v36 * v36)) + (float)(v37 * v37);
              this->mStateVariables.m_FormationSlot[0][v7].m_Angle = v31;
              this->mStateVariables.m_FormationSlot[0][v7].m_Direction.x = v38;
              this->mStateVariables.m_FormationSlot[0][v7].m_Direction.y = v36;
              this->mStateVariables.m_FormationSlot[0][v7].m_Direction.z = v37;
              if ( v80 == 0.0 )
                v81 = 0.0;
              else
                v81 = 1.0 / fsqrt(v80);
              LODWORD(this->mStateVariables.m_FormationSlot[0][v7].m_FacingDirection.z) = COERCE_UNSIGNED_INT(v37 * v81) ^ _xmm[0];
              LODWORD(this->mStateVariables.m_FormationSlot[0][v7].m_FacingDirection.x) = COERCE_UNSIGNED_INT(v81 * v38) ^ _xmm[0];
              LODWORD(this->mStateVariables.m_FormationSlot[0][v7].m_FacingDirection.y) = COERCE_UNSIGNED_INT(v81 * v36) ^ _xmm[0];
              if ( v83 )
              {
                this->mStateVariables.m_FormationSlot[0][v7].m_AbsolutePosition.x = v77;
                this->mStateVariables.m_FormationSlot[0][v7].m_AbsolutePosition.y = v78;
                this->mStateVariables.m_FormationSlot[0][v7].m_AbsolutePosition.z = v79;
                this->mStateVariables.m_FormationSlot[0][v7].m_UseAbsolutePosition = 1;
              }
              else
              {
                this->mStateVariables.m_FormationSlot[0][v7].m_UseAbsolutePosition = 0;
              }
              if ( m_RequestedToChangePosition )
              {
                this->mStateVariables.m_FormationSlot[0][v7].m_DesiredSpeed = this->mStateVariables.m_FormationSlot[0][v7].m_PositionChangeRequest.m_DesiredSpeed;
                m_FacingType = this->mStateVariables.m_FormationSlot[0][v7].m_PositionChangeRequest.m_FacingType;
                this->mStateVariables.m_FormationSlot[0][v7].m_Fixed = 1;
                this->mStateVariables.m_FormationSlot[0][v7].m_FacingType = m_FacingType;
              }
              v18 = 1;
              this->mStateVariables.m_FormationSlot[0][v7].m_RequestedToChangePosition = 0;
              this->mStateVariables.m_FormationSlot[0][v7].m_InPosition = eNOT_IN_POSITION;
              v106 = 1;
              goto LABEL_60;
            }
LABEL_59:
            v18 = v106;
LABEL_60:
            m_Clockwise = v107;
            v19 = v85;
LABEL_61:
            v21 = v93;
            v20 = v89;
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
          v20 = v89;
          m_Clockwise = !m_Clockwise;
          ++v26;
          v107 = m_Clockwise;
          v91 = v26;
        }
        while ( v26 < v24 );
LABEL_64:
        mSimTime_Temp = v92;
        v5 = v102 + 1;
        v54 = ++slot_index < this->m_NumSlotsPerRange[v97];
        v2 = v97;
        ++v102;
      }
      while ( v54 );
LABEL_65:
      ++v4;
      ++v2;
      range_index = v4;
      v97 = v2;
    }
  }
}          }
          v26 = v91;
          v24 = v94;
LABEL_63:
          v20 = v89;
          m_Clockwise = !m_Clockwise;
          ++v26;
          v107 = m_Clockwise;
          v91 = v26;
        }
        whi

// File Line: 1445
// RVA: 0x3777F0
char __fastcall UFG::FormationManagerComponent::NoOneIsTooCloseToAngle(
        UFG::FormationManagerComponent *this,
        unsigned __int16 angle,
        int range_index)
{
  int v3; // edi
  int *v4; // rsi
  unsigned __int16 *i; // rbx
  __int16 v7; // ax

  v3 = 0;
  v4 = (int *)((char *)this + 4 * range_index);
  if ( v4[83] <= 0 )
    return 1;
  for ( i = &this->mStateVariables.m_FormationSlot[range_index][0].m_Angle; ; i += 100 )
  {
    if ( *(_QWORD *)(i + 38) )
    {
      v7 = UFG::qAngleDiff(angle, *i);
      if ( v7 < 0 )
        v7 = -v7;
      if ( (float)((float)((float)(unsigned __int16)v7 * 360.0) * 0.000015258789) < 15.0 )
        break;
    }
    if ( ++v3 >= v4[83] )
      return 1;
  }
  return 0;
}

// File Line: 1534
// RVA: 0x393F30
void __fastcall UFG::FormationManagerComponent::UpdateAbsolutePositions(UFG::FormationManagerComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // r14
  int v3; // r15d
  int *m_NumSlotsPerRange; // rbp
  bool *p_m_UseAbsolutePosition; // r12
  int v6; // esi
  bool *v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rdi
  float v10; // xmm4_4
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  float v13; // xmm1_4

  m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
    v3 = 0;
    if ( this->m_NumRanges > 0 )
    {
      m_NumSlotsPerRange = this->m_NumSlotsPerRange;
      p_m_UseAbsolutePosition = &this->mStateVariables.m_FormationSlot[0][0].m_UseAbsolutePosition;
      do
      {
        v6 = 0;
        if ( *m_NumSlotsPerRange > 0 )
        {
          v7 = p_m_UseAbsolutePosition;
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
                  v10 = *(float *)(v9 + 176) - *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
                  v11.m128_f32[0] = v11.m128_f32[0]
                                  - *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
                  v12 = v11;
                  v12.m128_f32[0] = (float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10);
                  if ( _mm_sqrt_ps(v12).m128_f32[0] > 0.001 )
                  {
                    if ( v12.m128_f32[0] == 0.0 )
                      v13 = 0.0;
                    else
                      v13 = 1.0 / _mm_sqrt_ps(v12).m128_f32[0];
                    *((float *)v7 - 22) = v13 * 0.0;
                    *((float *)v7 - 24) = v13 * v10;
                    *((float *)v7 - 23) = v13 * v11.m128_f32[0];
                    *((_WORD *)v7 - 42) = (int)(float)((float)(atan2f(v11.m128_f32[0], v10) * 32768.0) * 0.31830987);
                  }
                }
              }
            }
            ++v6;
            v7 += 200;
          }
          while ( v6 < *m_NumSlotsPerRange );
        }
        ++v3;
        ++m_NumSlotsPerRange;
        p_m_UseAbsolutePosition += 1600;
      }
      while ( v3 < this->m_NumRanges );
    }
  }
}

// File Line: 1578
// RVA: 0x394FD0
void __fastcall UFG::FormationManagerComponent::UpdateDesiredFacing(UFG::FormationManagerComponent *this)
{
  UFG::TransformNodeComponent *m_pSimComponent; // rcx
  float x; // xmm7_4
  float y; // xmm8_4
  UFG::TransformNodeComponent *v5; // rbx
  int v6; // r15d
  float *p_z; // r12
  int *m_NumSlotsPerRange; // r14
  int v9; // esi
  float *v10; // rbx
  __int64 v11; // rdi
  UFG::TransformNodeComponent *v12; // rdi
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4

  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  x = 0.0;
  y = 0.0;
  if ( m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    v5 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    x = v5->mWorldTransform.v3.x;
    y = v5->mWorldTransform.v3.y;
  }
  v6 = 0;
  if ( this->m_NumRanges > 0 )
  {
    p_z = &this->mStateVariables.m_FormationSlot[0][0].m_FacingDirection.z;
    m_NumSlotsPerRange = this->m_NumSlotsPerRange;
    do
    {
      v9 = 0;
      if ( *m_NumSlotsPerRange > 0 )
      {
        v10 = p_z;
        do
        {
          v11 = *(_QWORD *)(v10 + 15);
          if ( v11 )
          {
            if ( this->m_FormationFacingType == 1 )
            {
              v12 = *(UFG::TransformNodeComponent **)(v11 + 88);
              if ( v12 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v12);
                v13 = x - v12->mWorldTransform.v3.x;
                v14 = y - v12->mWorldTransform.v3.y;
                v15 = fsqrt((float)(v14 * v14) + (float)(v13 * v13));
                if ( v15 > 0.001 )
                {
                  *v10 = (float)(1.0 / v15) * 0.0;
                  *(v10 - 2) = (float)(1.0 / v15) * v13;
                  *(v10 - 1) = (float)(1.0 / v15) * v14;
                }
              }
            }
          }
          ++v9;
          v10 += 50;
        }
        while ( v9 < *m_NumSlotsPerRange );
      }
      ++v6;
      ++m_NumSlotsPerRange;
      p_z += 400;
    }
    while ( v6 < this->m_NumRanges );
  }
}

// File Line: 1664
// RVA: 0x34D080
void __fastcall UFG::FormationManagerComponent::CheckIfInDesiredPosition(UFG::FormationManagerComponent *this)
{
  float mSimTime_Temp; // xmm15_4
  int v3; // r13d
  UFG::eInFormationPositionType *p_m_InPosition; // rcx
  __int64 v5; // r12
  int *m_NumSlotsPerRange; // rsi
  int v7; // r14d
  float *m_MaxLateralDistanceFromDesiredPosition; // r15
  UFG::eInFormationPositionType *v9; // rbx
  __int64 v10; // rax
  UFG::TransformNodeComponent *v11; // rdi
  float y; // xmm1_4
  float z; // xmm0_4
  __m128 y_low; // xmm0
  __int64 m_CurrentBattleType; // rdx
  float v16; // xmm9_4
  float v17; // xmm12_4
  float v18; // xmm10_4
  float v19; // xmm8_4
  bool v20; // zf
  bool v21; // di
  float m_MaxTimeForRangedAttackerToStayNearPlayer; // xmm6_4
  float m_MinTimeForRangedAttackerToStayNearPlayer; // xmm7_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float max_lateral_offset; // xmm7_4
  float v27; // xmm9_4
  bool v28; // al
  UFG::eInFormationPositionType v29; // edx
  float v30; // xmm0_4
  float v31; // xmm2_4
  bool v32; // r8
  bool v33; // cl
  float m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting; // xmm0_4
  bool v35; // al
  bool v36; // al
  UFG::qVector3 current_position; // [rsp+48h] [rbp-110h] BYREF
  UFG::qVector3 desired_position; // [rsp+58h] [rbp-100h] BYREF
  float current_radial_offset; // [rsp+160h] [rbp+8h] BYREF
  float current_lateral_offset; // [rsp+168h] [rbp+10h] BYREF
  UFG::eInFormationPositionType *v41; // [rsp+170h] [rbp+18h]
  UFG::TransformNodeComponent *m_pSimComponent; // [rsp+178h] [rbp+20h]

  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  v3 = 0;
  if ( this->m_NumRanges <= 0 )
    return;
  p_m_InPosition = &this->mStateVariables.m_FormationSlot[0][0].m_InPosition;
  v5 = -1i64;
  v41 = &this->mStateVariables.m_FormationSlot[0][0].m_InPosition;
  m_NumSlotsPerRange = this->m_NumSlotsPerRange;
  do
  {
    v7 = 0;
    if ( *m_NumSlotsPerRange <= 0 )
      goto LABEL_66;
    m_MaxLateralDistanceFromDesiredPosition = this->m_MaxLateralDistanceFromDesiredPosition;
    v9 = p_m_InPosition;
    do
    {
      v10 = *((_QWORD *)v9 + 7);
      if ( !v10
        || (v11 = *(UFG::TransformNodeComponent **)(v10 + 88)) == 0i64
        || !UFG::FormationManagerComponent::GetDesiredPosition(
              this,
              *((UFG::GetInFormationNode **)v9 + 4),
              &desired_position) )
      {
        *v9 = eNOT_IN_POSITION;
        *((_WORD *)v9 + 4) = 0;
        goto LABEL_64;
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      y = v11->mWorldTransform.v3.y;
      current_position.x = v11->mWorldTransform.v3.x;
      z = v11->mWorldTransform.v3.z;
      current_position.y = y;
      current_position.z = z;
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      y_low = (__m128)LODWORD(current_position.y);
      m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      v16 = *((float *)m_NumSlotsPerRange + 34);
      y_low.m128_f32[0] = (float)((float)(current_position.y - m_pSimComponent->mWorldTransform.v3.y)
                                * (float)(current_position.y - m_pSimComponent->mWorldTransform.v3.y))
                        + (float)((float)(current_position.x - m_pSimComponent->mWorldTransform.v3.x)
                                * (float)(current_position.x - m_pSimComponent->mWorldTransform.v3.x));
      v17 = (float)((float)(v11->mWorldTransform.v0.y * *((float *)v9 - 2))
                  + (float)(v11->mWorldTransform.v0.x * *((float *)v9 - 3)))
          + (float)(v11->mWorldTransform.v0.z * *((float *)v9 - 1));
      LODWORD(v18) = _mm_sqrt_ps(y_low).m128_u32[0];
      if ( v5 < 0 || (_DWORD)m_CurrentBattleType == -1 )
      {
        v19 = 0.0;
      }
      else
      {
        v19 = *(float *)((char *)&this->mStateVariables.m_pCurrentProfile[-2]
                       + (unsigned __int64)m_NumSlotsPerRange
                       - (_QWORD)this
                       - 84);
        if ( v19 < 0.0 )
          v19 = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxDistance[v5];
      }
      v20 = *v9 == eIN_POSITION;
      current_lateral_offset = 0.0;
      current_radial_offset = 0.0;
      if ( v20 )
      {
        v19 = v19 - 1.0;
        if ( v19 <= 0.0 )
          v19 = 0.0;
      }
      v21 = UFG::TheAIParameters.m_DistanceToBeConsideredNear > v18;
      if ( !*((_BYTE *)v9 + 10) && UFG::TheAIParameters.m_DistanceToBeConsideredNear > v18 )
      {
        m_MaxTimeForRangedAttackerToStayNearPlayer = UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer;
        m_MinTimeForRangedAttackerToStayNearPlayer = UFG::TheAIParameters.m_MinTimeForRangedAttackerToStayNearPlayer;
        v24 = UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer;
        if ( UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer > UFG::TheAIParameters.m_MinTimeForRangedAttackerToStayNearPlayer )
        {
          v24 = UFG::qRandom(
                  UFG::TheAIParameters.m_MaxTimeForRangedAttackerToStayNearPlayer
                - UFG::TheAIParameters.m_MinTimeForRangedAttackerToStayNearPlayer,
                  (unsigned int *)&UFG::qDefaultSeed)
              + m_MinTimeForRangedAttackerToStayNearPlayer;
          if ( v24 <= m_MinTimeForRangedAttackerToStayNearPlayer )
            v24 = m_MinTimeForRangedAttackerToStayNearPlayer;
          if ( v24 >= m_MaxTimeForRangedAttackerToStayNearPlayer )
            v24 = m_MaxTimeForRangedAttackerToStayNearPlayer;
        }
        *((float *)v9 + 1) = v24 + mSimTime_Temp;
      }
      v25 = *((float *)m_NumSlotsPerRange + 13);
      max_lateral_offset = *m_MaxLateralDistanceFromDesiredPosition;
      if ( !this->mStateVariables.m_CurrentlySprinting )
      {
        if ( *v9 )
        {
          if ( *v9 == eFAR_FROM_POSITION )
          {
            max_lateral_offset = max_lateral_offset + 4.0;
            v25 = v25 + 2.0;
          }
        }
        else
        {
          max_lateral_offset = max_lateral_offset + *((float *)m_NumSlotsPerRange + 29);
          if ( UFG::Metrics::msInstance.mSimTime_Temp > *((float *)v9 + 1) )
            v25 = (float)(v25 + *((float *)m_NumSlotsPerRange + 17)) + *((float *)v9 + 31);
          else
            v25 = (float)(v25 + *((float *)m_NumSlotsPerRange + 21)) + *((float *)v9 + 31);
        }
      }
      if ( *((_BYTE *)v9 + 9) )
        v16 = v16 + *((float *)m_NumSlotsPerRange + 38);
      v27 = cosf((float)(v16 * 3.1415927) * 0.0055555557);
      v28 = UFG::FormationManagerComponent::IsInPosition(
              this,
              &current_position,
              &desired_position,
              v25,
              max_lateral_offset,
              &current_radial_offset,
              &current_lateral_offset,
              0);
      v29 = *v9;
      v30 = *(float *)&FLOAT_1_0;
      v31 = *(float *)&FLOAT_1_0;
      v32 = v28;
      if ( *v9 <= (unsigned int)eCLOSE_TO_POSITION )
      {
        v30 = FLOAT_2_0;
        v31 = FLOAT_2_0;
      }
      v33 = current_radial_offset <= v30 && current_lateral_offset <= v31;
      if ( this->mStateVariables.m_CurrentlySprinting )
        m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = this->m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
      else
        m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = (float)(*((float *)m_NumSlotsPerRange
                                                                                            + 17)
                                                                                          + *((float *)m_NumSlotsPerRange
                                                                                            + 13))
                                                                                  + 5.0;
      v35 = current_radial_offset >= m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting
         && v18 > (float)(current_radial_offset + 1.0);
      if ( v29 == eFAR_FROM_POSITION && v18 < v19 )
      {
        *v9 = eNOT_IN_POSITION;
        goto LABEL_57;
      }
      if ( v35 )
        goto LABEL_56;
      if ( v29 == eFAR_FROM_POSITION )
      {
        if ( v32 )
          goto LABEL_53;
LABEL_56:
        *v9 = eFAR_FROM_POSITION;
        goto LABEL_57;
      }
      if ( v32 )
      {
LABEL_53:
        UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v9 - 8), eIN_POSITION);
        goto LABEL_57;
      }
      *v9 = 2 - v33;
LABEL_57:
      v36 = v18 < UFG::FormationManagerComponent::GetMaxDistanceForRange(this, v3) || *v9 == eIN_POSITION;
      *((_BYTE *)v9 + 8) = v36;
      *((_BYTE *)v9 + 10) = v21;
      *((_BYTE *)v9 + 9) = v17 > v27;
      if ( !this->m_FormationFacingType )
        *((_BYTE *)v9 + 9) = 1;
LABEL_64:
      ++v7;
      v9 += 50;
      ++m_MaxLateralDistanceFromDesiredPosition;
    }
    while ( v7 < *m_NumSlotsPerRange );
    p_m_InPosition = v41;
LABEL_66:
    p_m_InPosition += 400;
    ++v3;
    ++m_NumSlotsPerRange;
    ++v5;
    v41 = p_m_InPosition;
  }
  while ( v3 < this->m_NumRanges );
}

// File Line: 1841
// RVA: 0x36AEE0
bool __fastcall UFG::FormationManagerComponent::IsInPosition(
        UFG::FormationManagerComponent *this,
        UFG::qVector3 *current_position,
        UFG::qVector3 *desired_position,
        float max_radial_offset,
        float max_lateral_offset,
        float *current_radial_offset,
        float *current_lateral_offset,
        bool debug_print)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  float v13; // xmm7_4
  UFG::TransformNodeComponent *v14; // rbx
  float v15; // xmm7_4
  __m128 mPrev_high; // xmm6
  float v17; // xmm5_4
  __m128 y_low; // xmm3
  float v19; // xmm8_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm1_4
  float x; // xmm7_4
  __m128 v26; // xmm0
  float v27; // xmm6_4
  float v28; // xmm7_4
  Render::DebugDrawContext *Context; // rax

  m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
  v13 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
  mPrev_high = (__m128)HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
  v14 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v15 = v13 - current_position->x;
  mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - current_position->y;
  UFG::TransformNodeComponent::UpdateWorldTransform(v14);
  y_low = (__m128)LODWORD(current_position->y);
  v17 = current_position->x - desired_position->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - desired_position->y;
  v19 = current_position->z - desired_position->z;
  v20 = (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(v15 * v15);
  if ( v20 <= 0.001 )
  {
    x = UFG::qVector3::msZero.x;
    mPrev_high = (__m128)LODWORD(UFG::qVector3::msZero.y);
  }
  else
  {
    if ( v20 == 0.0 )
      v21 = 0.0;
    else
      v21 = 1.0 / _mm_sqrt_ps(mPrev_high).m128_f32[0];
    v22 = v15 * v21;
    v23 = mPrev_high.m128_f32[0] * v21;
    v24 = (float)((float)(v23 * y_low.m128_f32[0]) + (float)(v22 * v17)) + (float)((float)(v21 * 0.0) * v19);
    x = v22 * v24;
    mPrev_high.m128_f32[0] = v23 * v24;
  }
  v26 = y_low;
  v26.m128_f32[0] = (float)(v26.m128_f32[0] - mPrev_high.m128_f32[0])
                  * (float)(v26.m128_f32[0] - mPrev_high.m128_f32[0]);
  mPrev_high.m128_f32[0] = (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(x * x);
  LODWORD(v27) = _mm_sqrt_ps(mPrev_high).m128_u32[0];
  v26.m128_f32[0] = v26.m128_f32[0] + (float)((float)(v17 - x) * (float)(v17 - x));
  LODWORD(v28) = _mm_sqrt_ps(v26).m128_u32[0];
  if ( (float)((float)((float)(y_low.m128_f32[0] * (float)(v14->mWorldTransform.v3.y - desired_position->y))
                     + (float)(v17 * (float)(v14->mWorldTransform.v3.x - desired_position->x)))
             + (float)(v19 * (float)(v14->mWorldTransform.v3.z - desired_position->z))) > 0.0 )
    LODWORD(v27) ^= _xmm[0];
  if ( debug_print )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawText(Context, current_position, &UFG::qColour::White, "R: %.1f L: %.1f", v27, v28);
  }
  *current_radial_offset = v27;
  *current_lateral_offset = v28;
  return max_radial_offset > COERCE_FLOAT(LODWORD(v27) & _xmm) && max_lateral_offset > COERCE_FLOAT(LODWORD(v28) & _xmm);
}

// File Line: 1895
// RVA: 0x375560
void __fastcall UFG::FormationManagerComponent::MaybeSetDesiredPositionFromProfile(
        UFG::FormationManagerComponent *this)
{
  UFG::TransformNodeComponent *m_pSimComponent; // r15
  UFG::TransformNodeComponent *v3; // rbx
  float v4; // xmm0_4
  int v5; // edx
  float v6; // xmm6_4
  float v7; // xmm7_4
  float *p_z; // r9
  int *m_NumSlotsPerRange; // rsi
  __int64 v10; // r8
  __int64 v11; // rax
  float *v12; // r14
  __int64 v13; // rax
  __int64 v14; // rbx
  UFG::GetInFormationNode *v15; // rdi
  float v16; // xmm0_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float z; // xmm8_4
  unsigned __int16 v19; // r12
  int v20; // r15d
  UFG::FormationProfile *m_pCurrentProfile; // rax
  __int64 v22; // rcx
  unsigned __int16 v23; // si
  float v24; // xmm7_4
  float v25; // xmm0_4
  float v26; // xmm6_4
  float v27; // xmm9_4
  float v28; // xmm0_4
  UFG::SimComponent *m_pPointer; // rdi
  float v30; // xmm9_4
  float v31; // xmm8_4
  float v32; // xmm7_4
  UFG::SimObject *m_pSimObject; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v35; // r14
  UFG::eAttackType m_AttackType; // r15d
  UFG::CombatRegion *v37; // rcx
  float x; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm4_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float y; // xmm1_4
  float v44; // xmm0_4
  int v45; // ebx
  UFG::SimObject *v46; // rcx
  UFG::SimComponent *v47; // rax
  __int64 v48; // rcx
  bool v49; // di
  UFG::SimComponent *v50; // rax
  UFG::SimComponent *v51; // rsi
  UFG::SimObject *v52; // rcx
  bool v53; // al
  __m128 mPrev_high; // xmm2
  float v55; // xmm1_4
  float v56; // xmm3_4
  float v57; // xmm5_4
  float v58; // xmm6_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // xmm4_4
  float v62; // xmm0_4
  UFG::SimObject *v63; // rcx
  UFG::SimComponent *v64; // rax
  __int64 v65; // rcx
  bool v66; // al
  int v67; // eax
  __int16 v68; // dx
  UFG::eInFormationPositionType v69; // ebx
  bool v70; // zf
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm3_4
  float v74; // xmm1_4
  float v75; // xmm0_4
  float v76; // xmm1_4
  int v77; // eax
  bool v78; // al
  float v79; // xmm1_4
  float v80; // xmm2_4
  bool v81; // cl
  bool v82; // al
  UFG::qVector3 last_valid_position; // [rsp+40h] [rbp-B0h] BYREF
  UFG::qVector3 vPoint; // [rsp+50h] [rbp-A0h] BYREF
  int range_index; // [rsp+60h] [rbp-90h]
  float current_lateral_offset; // [rsp+64h] [rbp-8Ch] BYREF
  float current_radial_offset; // [rsp+68h] [rbp-88h] BYREF
  UFG::GetInFormationNode *desired_direction; // [rsp+70h] [rbp-80h] BYREF
  float *desired_direction_8; // [rsp+78h] [rbp-78h]
  float *m_MaxLateralDistanceFromDesiredPosition; // [rsp+80h] [rbp-70h]
  __int64 v91; // [rsp+88h] [rbp-68h]
  float *v92; // [rsp+90h] [rbp-60h]
  UFG::qVector3 from_position; // [rsp+98h] [rbp-58h] BYREF
  UFG::qVector3 to_position; // [rsp+A8h] [rbp-48h] BYREF
  __int64 v95; // [rsp+B8h] [rbp-38h]
  UFG::SimObject *ray_hit_object; // [rsp+C0h] [rbp-30h] BYREF
  float *v97; // [rsp+C8h] [rbp-28h]
  __int64 v98; // [rsp+D0h] [rbp-20h] BYREF
  __int64 v99; // [rsp+D8h] [rbp-18h]
  __int64 v100; // [rsp+E0h] [rbp-10h] BYREF
  int *v101; // [rsp+E8h] [rbp-8h]
  UFG::qVector3 desired_position; // [rsp+F0h] [rbp+0h] BYREF
  __int64 v103; // [rsp+100h] [rbp+10h]
  UFG::qVector3 *current_position; // [rsp+108h] [rbp+18h]
  __int64 v105; // [rsp+110h] [rbp+20h]
  __int64 v106; // [rsp+118h] [rbp+28h]
  unsigned __int16 vars0; // [rsp+210h] [rbp+120h]
  void *retaddr; // [rsp+218h] [rbp+128h]
  int v109; // [rsp+220h] [rbp+130h]
  int slot_index; // [rsp+228h] [rbp+138h]

  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    v92 = (float *)m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    v3 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v4 = atan2f(v3->mWorldTransform.v0.y, v3->mWorldTransform.v0.x);
    v5 = 0;
    v6 = FLOAT_32768_0;
    v7 = FLOAT_0_31830987;
    range_index = 0;
    v105 = (unsigned int)(int)(float)((float)(v4 * 32768.0) * 0.31830987);
    if ( this->m_NumRanges > 0 )
    {
      p_z = &this->mStateVariables.m_FormationSlot[0][0].m_Direction.z;
      m_NumSlotsPerRange = this->m_NumSlotsPerRange;
      v95 = -232i64 - (_QWORD)this;
      v10 = 36i64;
      v11 = -332i64 - (_QWORD)this;
      v97 = &this->mStateVariables.m_FormationSlot[0][0].m_Direction.z;
      v101 = this->m_NumSlotsPerRange;
      v106 = -332i64 - (_QWORD)this;
      v91 = 36i64;
      while ( 1 )
      {
        if ( *(int *)((char *)m_NumSlotsPerRange + v11 + (unsigned __int64)this->mStateVariables.m_pCurrentProfile + 4) == 1 )
        {
          slot_index = 0;
          if ( *m_NumSlotsPerRange > 0 )
            break;
        }
LABEL_89:
        v11 = v106;
        ++v5;
        ++m_NumSlotsPerRange;
        p_z += 400;
        v10 += 16i64;
        range_index = v5;
        v101 = m_NumSlotsPerRange;
        v97 = p_z;
        v91 = v10;
        if ( v5 >= this->m_NumRanges )
          return;
      }
      v12 = p_z;
      desired_direction_8 = p_z;
      m_MaxLateralDistanceFromDesiredPosition = this->m_MaxLateralDistanceFromDesiredPosition;
LABEL_7:
      v13 = *((_QWORD *)v12 + 10);
      if ( v13 )
        v14 = *(_QWORD *)(v13 + 88);
      else
        v14 = 0i64;
      if ( !v13 || !v14 )
        goto LABEL_87;
      v15 = (UFG::GetInFormationNode *)*((_QWORD *)v12 + 7);
      desired_direction = v15;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14);
      current_position = (UFG::qVector3 *)(v14 + 176);
      v16 = atan2f(
              *(float *)(v14 + 180) - m_pSimComponent->mWorldTransform.v3.y,
              *(float *)(v14 + 176) - m_pSimComponent->mWorldTransform.v3.x);
      m_pTransformNodeComponent = 0i64;
      z = UFG::qVector3::msZero.z;
      v109 = -1;
      v19 = 0;
      v20 = 0;
      LODWORD(retaddr) = 0;
      v103 = (unsigned int)(int)(float)((float)(v16 * v6) * v7);
      m_pCurrentProfile = this->mStateVariables.m_pCurrentProfile;
      desired_direction = *(UFG::GetInFormationNode **)&UFG::qVector3::msZero.x;
      *(float *)&desired_direction_8 = UFG::qVector3::msZero.z;
      if ( *(int *)((char *)&m_pCurrentProfile->m_NameID.mUID + (_QWORD)m_NumSlotsPerRange + v95) <= 0 )
        goto LABEL_86;
      v22 = v91;
      v99 = v91;
      while ( 1 )
      {
        v23 = v105 + *(_WORD *)((char *)&m_pCurrentProfile->m_NameID.mUID + v22);
        vars0 = v23;
        v24 = (float)((float)v23 * 3.1415927) * 0.000030517578;
        v25 = sinf(v24);
        v26 = v12[2];
        v27 = v25;
        v28 = cosf(v24);
        m_pPointer = v15->m_pOwner.m_pPointer;
        v30 = v27 * v26;
        v31 = z * v26;
        v32 = v28 * v26;
        if ( !m_pPointer )
          break;
        m_pSimObject = m_pPointer->m_pSimObject;
        if ( !m_pSimObject )
          goto LABEL_18;
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActiveAIEntityComponent::_TypeUID);
        m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
        v35 = ComponentOfType;
LABEL_19:
        if ( !this->m_pAIEntityComponent.m_pSimComponent
          || !this->m_pTransformNodeComponent.m_pSimComponent
          || !m_pSimObject
          || !v35
          || !m_pTransformNodeComponent )
        {
          goto LABEL_60;
        }
        m_AttackType = desired_direction->m_AttackType;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v37 = *(UFG::CombatRegion **)&v35[15].m_TypeUID;
        x = v32 + m_pTransformNodeComponent->mWorldTransform.v3.x;
        v39 = v30 + m_pTransformNodeComponent->mWorldTransform.v3.y;
        v40 = v31 + m_pTransformNodeComponent->mWorldTransform.v3.z;
        v41 = x;
        v42 = v39;
        last_valid_position.x = x;
        last_valid_position.y = v39;
        vPoint.x = x;
        vPoint.y = v39;
        vPoint.z = v40;
        last_valid_position.z = v40;
        if ( v37 )
        {
          if ( !UFG::CombatRegion::IsHitPoint(v37, &vPoint) )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
            y = m_pTransformNodeComponent->mWorldTransform.v3.y;
            last_valid_position.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
            v44 = m_pTransformNodeComponent->mWorldTransform.v3.z;
            last_valid_position.y = y;
            last_valid_position.z = v44;
LABEL_27:
            v20 = (int)retaddr;
LABEL_28:
            v45 = v109;
            goto LABEL_29;
          }
          v40 = vPoint.z;
          v39 = vPoint.y;
          x = vPoint.x;
          v42 = last_valid_position.y;
          v41 = last_valid_position.x;
        }
        if ( m_AttackType == eATTACK_TYPE_MELEE )
        {
          v46 = this->m_pAIEntityComponent.m_pSimComponent->m_pSimObject;
          if ( v46 )
            v47 = UFG::SimObject::GetComponentOfType(v46, UFG::NavComponent::_TypeUID);
          else
            v47 = 0i64;
          v48 = *(__int64 *)((char *)&v47[2].m_BoundComponentHandles.mNode.mNext + 4);
          v100 = v48 | 0x20000000000i64;
          v49 = !UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                   UFG::NavManager::ms_pInstance,
                   (UFG::HavokNavPosition *)&v47[1].m_SafePointerList.mNode.mNext,
                   &vPoint,
                   (UFG::NavParams *)&v100,
                   &last_valid_position);
LABEL_52:
          v20 = (int)retaddr;
          if ( !v49 )
            goto LABEL_28;
          goto LABEL_60;
        }
        v50 = desired_direction->m_pOwner.m_pPointer;
        if ( v50 && LOBYTE(v50[1].m_Flags) )
          goto LABEL_50;
        v51 = this->m_pTransformNodeComponent.m_pSimComponent;
        v52 = 0i64;
        if ( v51 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
          v53 = 0;
          mPrev_high = (__m128)HIDWORD(v51[2].m_BoundComponentHandles.mNode.mPrev);
          v55 = *(float *)&v51[2].m_BoundComponentHandles.mNode.mPrev;
          x = vPoint.x;
          v52 = 0i64;
          ray_hit_object = 0i64;
          v39 = vPoint.y;
          v56 = *(float *)&v51[2].m_BoundComponentHandles.mNode.mNext;
          v40 = vPoint.z;
          LODWORD(from_position.y) = mPrev_high.m128_i32[0];
          from_position.x = v55;
          from_position.z = v56;
          to_position = vPoint;
          mPrev_high.m128_f32[0] = (float)((float)((float)(mPrev_high.m128_f32[0] - vPoint.y)
                                                 * (float)(mPrev_high.m128_f32[0] - vPoint.y))
                                         + (float)((float)(v55 - vPoint.x) * (float)(v55 - vPoint.x)))
                                 + (float)((float)(v56 - vPoint.z) * (float)(v56 - vPoint.z));
          if ( _mm_sqrt_ps(mPrev_high).m128_f32[0] <= 100.0 )
          {
            from_position.z = v56 + 1.5;
            to_position.z = vPoint.z + 1.5;
            v53 = UFG::DoRaycast(
                    &from_position,
                    &to_position,
                    m_pSimObject,
                    &last_valid_position,
                    &ray_hit_object,
                    0i64,
                    0,
                    &UFG::qColour::Yellow);
            v52 = ray_hit_object;
            v40 = vPoint.z;
            v39 = vPoint.y;
            x = vPoint.x;
          }
          v42 = last_valid_position.y;
          v41 = last_valid_position.x;
        }
        else
        {
          v53 = 0;
        }
        if ( v53
          || !v52
          && fsqrt(
               (float)((float)((float)(v42 - v39) * (float)(v42 - v39)) + (float)((float)(v41 - x) * (float)(v41 - x)))
             + (float)((float)(last_valid_position.z - v40) * (float)(last_valid_position.z - v40))) < 0.1 )
        {
          v23 = vars0;
LABEL_50:
          v49 = 1;
          goto LABEL_51;
        }
        v57 = m_pTransformNodeComponent->mWorldTransform.v3.x;
        v58 = m_pTransformNodeComponent->mWorldTransform.v3.y;
        v23 = vars0;
        v49 = 0;
        v59 = v41 - v57;
        v60 = v42 - v58;
        v61 = fsqrt((float)(v60 * v60) + (float)(v59 * v59));
        if ( v61 > 1.0 )
        {
          v62 = (float)(v61 - 1.0) / v61;
          last_valid_position.z = (float)(v62 * 0.0) + m_pTransformNodeComponent->mWorldTransform.v3.z;
          last_valid_position.x = (float)(v59 * v62) + v57;
          last_valid_position.y = (float)(v60 * v62) + v58;
        }
LABEL_51:
        if ( (unsigned int)(m_AttackType - 1) > 1 )
          goto LABEL_52;
        v63 = v35->m_pSimObject;
        if ( v63 )
          v64 = UFG::SimObject::GetComponentOfType(v63, UFG::NavComponent::_TypeUID);
        else
          v64 = 0i64;
        v65 = *(__int64 *)((char *)&v64[2].m_BoundComponentHandles.mNode.mNext + 4);
        v98 = v65 | 0x20000000000i64;
        v66 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                UFG::NavManager::ms_pInstance,
                (UFG::HavokNavPosition *)&v64[1].m_SafePointerList.mNode.mNext,
                &vPoint,
                (UFG::NavParams *)&v98,
                &last_valid_position);
        if ( !v49 || v66 )
          goto LABEL_27;
        v20 = (int)retaddr;
LABEL_60:
        LOWORD(v67) = UFG::qAngleDiff(v103, v23);
        v45 = v109;
        v68 = v67;
        if ( v109 < 0 )
          goto LABEL_64;
        if ( (v67 & 0x8000u) != 0 )
          v67 = -(__int16)v67;
        if ( (__int16)v67 < (int)v19 )
        {
LABEL_64:
          v45 = v20;
          v19 = v68;
          v109 = v20;
          if ( v68 < 0 )
            v19 = -v68;
          desired_direction = (UFG::GetInFormationNode *)__PAIR64__(LODWORD(v30), LODWORD(v32));
          *(float *)&desired_direction_8 = v31;
        }
LABEL_29:
        m_NumSlotsPerRange = v101;
        m_pCurrentProfile = this->mStateVariables.m_pCurrentProfile;
        v12 = desired_direction_8;
        ++v20;
        v22 = v99 + 2;
        LODWORD(retaddr) = v20;
        v99 += 2i64;
        if ( v20 >= *(signed int *)((char *)&m_pCurrentProfile->m_NameID.mUID + (_QWORD)v101 + v95) )
        {
          if ( v45 < 0 )
          {
            v6 = FLOAT_32768_0;
            v7 = FLOAT_0_31830987;
LABEL_86:
            m_pSimComponent = (UFG::TransformNodeComponent *)v92;
            goto LABEL_87;
          }
          v69 = *((_DWORD *)desired_direction_8 + 6);
          UFG::FormationManagerComponent::SetDesiredDirection(
            this,
            range_index,
            slot_index,
            desired_direction,
            (UFG::qVector3 *)&desired_direction);
          UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v12 - 2), v69);
          v70 = !this->mStateVariables.m_CurrentlySprinting;
          m_pSimComponent = (UFG::TransformNodeComponent *)v92;
          v71 = *(v12 - 2);
          v72 = *(v12 - 1);
          v73 = *((float *)m_NumSlotsPerRange + 13);
          current_lateral_offset = 0.0;
          current_radial_offset = 0.0;
          v74 = v72 + v92[45];
          desired_position.x = v71 + v92[44];
          v75 = v92[46];
          desired_position.y = v74;
          v76 = *m_MaxLateralDistanceFromDesiredPosition;
          desired_position.z = v75 + *v12;
          if ( v70 )
          {
            v77 = *((_DWORD *)v12 + 6);
            if ( v77 )
            {
              if ( v77 == 3 )
              {
                v76 = v76 + 4.0;
                v73 = v73 + 2.0;
              }
            }
            else
            {
              v76 = v76 + *((float *)m_NumSlotsPerRange + 29);
              if ( UFG::Metrics::msInstance.mSimTime_Temp > v12[7] )
                v73 = (float)(v73 + *((float *)m_NumSlotsPerRange + 17)) + v12[37];
              else
                v73 = (float)(v73 + *((float *)m_NumSlotsPerRange + 21)) + v12[37];
            }
          }
          v78 = UFG::FormationManagerComponent::IsInPosition(
                  this,
                  current_position,
                  &desired_position,
                  v73,
                  v76,
                  &current_radial_offset,
                  &current_lateral_offset,
                  0);
          v79 = *(float *)&FLOAT_1_0;
          v80 = *(float *)&FLOAT_1_0;
          v81 = v78;
          if ( *((_DWORD *)v12 + 6) <= 1u )
          {
            v79 = FLOAT_2_0;
            v80 = FLOAT_2_0;
          }
          v82 = current_radial_offset <= v79 && current_lateral_offset <= v80;
          if ( v81 )
          {
            UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v12 - 2), eIN_POSITION);
            v6 = FLOAT_32768_0;
            v7 = FLOAT_0_31830987;
          }
          else
          {
            v6 = FLOAT_32768_0;
            v7 = FLOAT_0_31830987;
            if ( v82 )
              *((_DWORD *)v12 + 6) = 1;
          }
LABEL_87:
          ++m_MaxLateralDistanceFromDesiredPosition;
          v12 += 50;
          desired_direction_8 = v12;
          if ( ++slot_index >= *m_NumSlotsPerRange )
          {
            v5 = range_index;
            v10 = v91;
            p_z = v97;
            goto LABEL_89;
          }
          goto LABEL_7;
        }
        z = UFG::qVector3::msZero.z;
        v15 = desired_direction;
        m_pTransformNodeComponent = 0i64;
      }
      m_pSimObject = 0i64;
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
  int v1; // r14d
  UFG::FormationSlot (*m_FormationSlot)[8]; // r15
  int *m_NumSlotsPerRange; // rsi
  __int64 v5; // r12
  int v6; // edi
  UFG::FormationSlot *v7; // rbx
  UFG::GetInFormationNode *m_pPointer; // r9
  UFG::SimComponent *v9; // rax

  v1 = 0;
  if ( this->m_NumRanges > 0 )
  {
    m_FormationSlot = this->mStateVariables.m_FormationSlot;
    m_NumSlotsPerRange = this->m_NumSlotsPerRange;
    v5 = -332i64 - (_QWORD)this;
    do
    {
      if ( *(UFG::eFormationManagerRingType *)((char *)this->mStateVariables.m_pCurrentProfile->m_RingType
                                             + v5
                                             + (unsigned __int64)m_NumSlotsPerRange) == eRING_TYPE_FLUID )
      {
        v6 = 0;
        if ( *m_NumSlotsPerRange > 0 )
        {
          v7 = (UFG::FormationSlot *)m_FormationSlot;
          do
          {
            m_pPointer = v7->m_pMember.m_pPointer;
            if ( m_pPointer )
            {
              v9 = m_pPointer->m_pOwner.m_pPointer;
              if ( v9 )
              {
                if ( LOBYTE(v9[1].m_Flags) )
                {
                  UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(this, v1, v6, m_pPointer);
                  UFG::FormationSlot::SetInPosition(v7, 0);
                }
              }
            }
            ++v6;
            ++v7;
          }
          while ( v6 < *m_NumSlotsPerRange );
        }
      }
      ++v1;
      ++m_NumSlotsPerRange;
      ++m_FormationSlot;
    }
    while ( v1 < this->m_NumRanges );
  }
}

// File Line: 2035
// RVA: 0x395FB0
void __fastcall UFG::FormationManagerComponent::UpdateDesiredPositionIfNotInRange(UFG::FormationManagerComponent *this)
{
  int v2; // r14d
  unsigned int v3; // ebx
  unsigned int m_ExpensiveUpdateCount; // edi
  int m_NumRanges; // eax
  int *m_NumSlotsPerRange; // rdx
  __int64 v7; // r8
  int v8; // r15d
  bool *p_m_CurrentlyInRange; // r8
  int *v10; // r13
  __int64 v11; // rcx
  int v12; // esi
  int v13; // eax
  bool *v14; // rdi
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
  __int32 v35; // ebx
  UFG::TransformNodeComponent *m_pSimComponent; // [rsp+20h] [rbp-108h]
  unsigned int v37; // [rsp+130h] [rbp+8h]
  int v38; // [rsp+138h] [rbp+10h]
  unsigned int v39; // [rsp+140h] [rbp+18h]
  bool *v40; // [rsp+148h] [rbp+20h]

  v2 = 0;
  v3 = 0;
  v37 = 0;
  m_ExpensiveUpdateCount = this->mStateVariables.m_ExpensiveUpdateCount;
  v39 = m_ExpensiveUpdateCount;
  m_NumRanges = this->m_NumRanges;
  if ( m_NumRanges > 0 )
  {
    m_NumSlotsPerRange = this->m_NumSlotsPerRange;
    v7 = (unsigned int)m_NumRanges;
    do
    {
      v3 += *m_NumSlotsPerRange - m_NumSlotsPerRange[8];
      ++m_NumSlotsPerRange;
      --v7;
    }
    while ( v7 );
    v37 = v3;
  }
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    if ( v3 )
    {
      m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
      v8 = 0;
      if ( this->m_NumRanges > 0 )
      {
        p_m_CurrentlyInRange = &this->mStateVariables.m_FormationSlot[0][0].m_CurrentlyInRange;
        v40 = &this->mStateVariables.m_FormationSlot[0][0].m_CurrentlyInRange;
        v10 = this->m_NumSlotsPerRange;
        v11 = -332i64 - (_QWORD)this;
        do
        {
          if ( *(UFG::eFormationManagerRingType *)((char *)this->mStateVariables.m_pCurrentProfile->m_RingType
                                                 + v11
                                                 + (unsigned __int64)v10) == eRING_TYPE_FLUID )
          {
            v12 = 0;
            if ( *v10 > 0 )
            {
              v13 = m_ExpensiveUpdateCount % v3;
              v38 = m_ExpensiveUpdateCount % v3;
              v14 = p_m_CurrentlyInRange;
              do
              {
                v15 = v13 == v2;
                v16 = *((_QWORD *)v14 + 6);
                if ( v16 )
                  v17 = *(_QWORD *)(v16 + 88);
                else
                  v17 = 0i64;
                if ( v16 )
                {
                  if ( v17 )
                  {
                    ++v2;
                    if ( v15 && !*v14 && v8 == this->m_NumRanges - 1 )
                    {
                      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v17);
                      v18 = *((float *)v14 - 10);
                      v19 = (__m128)*((unsigned int *)v14 - 9);
                      v20 = *((float *)v14 - 8);
                      v21 = *(float *)(v17 + 184) - m_pSimComponent->mWorldTransform.v3.z;
                      v22 = *(float *)(v17 + 180) - m_pSimComponent->mWorldTransform.v3.y;
                      v23 = (__m128)*(unsigned int *)(v17 + 176);
                      v23.m128_f32[0] = v23.m128_f32[0] - m_pSimComponent->mWorldTransform.v3.x;
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
                            v26 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
                          v27 = v26 * v20;
                          v28 = v26 * v19.m128_f32[0];
                          v29 = v26 * v18;
                          if ( v25.m128_f32[0] == 0.0 )
                            v30 = 0.0;
                          else
                            v30 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
                          v31 = v30 * v21;
                          v32 = v30 * v22;
                          v33 = v23.m128_f32[0] * v30;
                          if ( (_S18_0 & 1) != 0 )
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
                            v35 = *((_DWORD *)v14 - 2);
                            UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
                              this,
                              v8,
                              v12,
                              *((UFG::GetInFormationNode **)v14 + 3));
                            UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v14 - 40), v35);
                          }
                        }
                      }
                    }
                  }
                }
                ++v12;
                v14 += 200;
                v13 = v38;
              }
              while ( v12 < *v10 );
              v3 = v37;
              p_m_CurrentlyInRange = v40;
              m_ExpensiveUpdateCount = v39;
            }
          }
          ++v8;
          ++v10;
          p_m_CurrentlyInRange += 1600;
          v40 = p_m_CurrentlyInRange;
          v11 = -332i64 - (_QWORD)this;
        }
        while ( v8 < this->m_NumRanges );
      }
    }
  }
}

// File Line: 2137
// RVA: 0x395BC0
void __fastcall UFG::FormationManagerComponent::UpdateDesiredPositionIfNotAtCorrectAngle(
        UFG::FormationManagerComponent *this)
{
  __int64 m_NumRanges; // r11
  unsigned int m_ExpensiveUpdateCount; // edi
  int v3; // r12d
  unsigned int v4; // ebx
  int v5; // r8d
  int v6; // r9d
  int v7; // r15d
  __int64 v9; // r10
  int *v10; // rcx
  unsigned __int64 v11; // rdx
  int v12; // eax
  float *p_y; // rcx
  __int64 v14; // r13
  __int64 v15; // r14
  int v16; // ebp
  unsigned int v17; // eax
  float *v18; // rdi
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
  __int64 m_CurrentBattleType; // rcx
  float v42; // xmm1_4
  __int32 v43; // ebx
  float *v44; // [rsp+20h] [rbp-C8h]
  UFG::TransformNodeComponent *m_pSimComponent; // [rsp+28h] [rbp-C0h]
  unsigned int v46; // [rsp+F0h] [rbp+8h]
  int v47; // [rsp+F8h] [rbp+10h]
  unsigned int v48; // [rsp+100h] [rbp+18h]
  int range_index; // [rsp+108h] [rbp+20h]

  m_NumRanges = this->m_NumRanges;
  m_ExpensiveUpdateCount = this->mStateVariables.m_ExpensiveUpdateCount;
  v3 = 1;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v48 = m_ExpensiveUpdateCount;
  v46 = 0;
  range_index = 1;
  v9 = 1i64;
  if ( m_NumRanges > 1 )
  {
    if ( m_NumRanges - 1 >= 2 )
    {
      v10 = &this->m_NumSlotsPerRange[1];
      v11 = ((unsigned __int64)(m_NumRanges - 3) >> 1) + 1;
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
    if ( v9 < m_NumRanges )
      v4 = this->m_NumSlotsPerRange[v9] - this->m_NumFreeSlotsPerRange[v9];
    v4 += v5 + v6;
    v46 = v4;
  }
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    if ( v4 )
    {
      m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
      if ( this->m_NumRanges > 1 )
      {
        p_y = &this->mStateVariables.m_FormationSlot[1][0].m_Direction.y;
        v14 = 0i64;
        v15 = 20i64;
        v44 = &this->mStateVariables.m_FormationSlot[1][0].m_Direction.y;
        do
        {
          if ( !*(_DWORD *)((char *)this->mStateVariables.m_pCurrentProfile + v15 - 12) )
          {
            v16 = 0;
            if ( *(int *)((char *)&this->m_pAttackRightsComponent.m_pSimObject + v15 + 4) > 0 )
            {
              v17 = m_ExpensiveUpdateCount;
              v18 = p_y;
              v19 = v17 % v4;
              v47 = v19;
              do
              {
                v20 = v19 == v7;
                v21 = *(_QWORD *)(v18 + 21);
                if ( v21 )
                  v22 = *(_QWORD *)(v21 + 88);
                else
                  v22 = 0i64;
                v23 = *(_QWORD *)(v18 + 15);
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
                          v24 = *(float *)(v22 + 176) - m_pSimComponent->mWorldTransform.v3.x;
                          v25.m128_f32[0] = v25.m128_f32[0] - m_pSimComponent->mWorldTransform.v3.y;
                          v26 = v25;
                          v26.m128_f32[0] = (float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24);
                          v27 = _mm_sqrt_ps(v26).m128_f32[0];
                          if ( v27 > 0.001 )
                          {
                            if ( v26.m128_f32[0] == 0.0 )
                              v28 = 0.0;
                            else
                              v28 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
                            v29 = *v18;
                            v30 = (__m128)*((unsigned int *)v18 - 1);
                            v31 = v18[1];
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
                              v37 = 1.0 / _mm_sqrt_ps(v36).m128_f32[0];
                            v38 = v30.m128_f32[0] * v37;
                            v39 = v31 * v37;
                            v40 = v37 * v29;
                            m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
                            if ( v14 < 0 || (_DWORD)m_CurrentBattleType == -1 )
                            {
                              v42 = 0.0;
                            }
                            else
                            {
                              v42 = *(float *)((char *)&this->mStateVariables.m_pCurrentProfile->m_NameID.mUID + v15);
                              if ( v42 < 0.0 )
                                v42 = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxDistance[v14];
                            }
                            if ( (float)((float)((float)(v40 * v33) + (float)(v38 * v35)) + (float)(v39 * v34)) < 0.0
                              || v27 < v42 )
                            {
                              v43 = *((_DWORD *)v18 + 7);
                              UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
                                this,
                                range_index,
                                v16,
                                *(UFG::GetInFormationNode **)(v18 + 15));
                              UFG::FormationSlot::SetInPosition((UFG::FormationSlot *)(v18 - 1), v43);
                            }
                          }
                        }
                      }
                    }
                  }
                }
                v19 = v47;
                ++v16;
                v18 += 50;
              }
              while ( v16 < *(_DWORD *)((char *)&this->m_pAttackRightsComponent.m_pSimObject + v15 + 4) );
              v3 = range_index;
              p_y = v44;
              v4 = v46;
              m_ExpensiveUpdateCount = v48;
            }
          }
          ++v3;
          p_y += 400;
          ++v14;
          v15 += 4i64;
          range_index = v3;
          v44 = p_y;
        }
        while ( v3 < this->m_NumRanges );
      }
    }
  }
}

// File Line: 2221
// RVA: 0x395790
void __fastcall UFG::FormationManagerComponent::UpdateDesiredPositionIfInsideWall(UFG::FormationManagerComponent *this)
{
  __int64 m_NumRanges; // r11
  unsigned int m_ExpensiveUpdateCount; // esi
  int v4; // r8d
  int v5; // r9d
  int v6; // ebx
  int v7; // edi
  __int64 v8; // r10
  int *m_NumSlotsPerRange; // rcx
  unsigned __int64 v10; // rdx
  int v11; // eax
  UFG::TransformNodeComponent *m_pSimComponent; // rcx
  unsigned int v13; // edi
  int v14; // r9d
  unsigned __int16 *p_m_Angle; // r8
  int *v16; // rdx
  __int64 v17; // rax
  unsigned __int16 *v18; // r14
  int v19; // eax
  bool v20; // zf
  __int64 v21; // rax
  __int64 v22; // rcx
  __int64 v23; // rsi
  __int64 v24; // rax
  bool v25; // r15
  int v26; // eax
  int v27; // r12d
  int i; // ebx
  unsigned __int16 v29; // bp
  unsigned __int16 v30; // di
  float z; // xmm9_4
  float v32; // xmm8_4
  float v33; // xmm0_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm0_4
  int v37; // [rsp+30h] [rbp-E8h]
  unsigned int v38; // [rsp+34h] [rbp-E4h]
  unsigned int v39; // [rsp+38h] [rbp-E0h]
  int *v40; // [rsp+40h] [rbp-D8h]
  unsigned __int16 *v41; // [rsp+48h] [rbp-D0h]
  UFG::qVector3 desired_direction; // [rsp+58h] [rbp-C0h] BYREF
  int v43; // [rsp+120h] [rbp+8h]
  int slot_index; // [rsp+128h] [rbp+10h]
  int range_index; // [rsp+130h] [rbp+18h]
  int v46; // [rsp+138h] [rbp+20h]

  m_NumRanges = this->m_NumRanges;
  m_ExpensiveUpdateCount = this->mStateVariables.m_ExpensiveUpdateCount;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v39 = m_ExpensiveUpdateCount;
  v8 = 0i64;
  if ( m_NumRanges >= 2 )
  {
    m_NumSlotsPerRange = this->m_NumSlotsPerRange;
    v10 = ((unsigned __int64)(m_NumRanges - 2) >> 1) + 1;
    v8 = 2 * v10;
    do
    {
      v11 = *m_NumSlotsPerRange;
      m_NumSlotsPerRange += 2;
      v4 += v11 - m_NumSlotsPerRange[6];
      v5 += *(m_NumSlotsPerRange - 1) - m_NumSlotsPerRange[7];
      --v10;
    }
    while ( v10 );
  }
  if ( v8 < m_NumRanges )
    v7 = this->m_NumSlotsPerRange[v8] - this->m_NumFreeSlotsPerRange[v8];
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v13 = v5 + v4 + v7;
  v38 = v13;
  if ( m_pSimComponent )
  {
    if ( v13 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
      v14 = 0;
      range_index = 0;
      if ( this->m_NumRanges > 0 )
      {
        p_m_Angle = &this->mStateVariables.m_FormationSlot[0][0].m_Angle;
        v16 = this->m_NumSlotsPerRange;
        v17 = -332i64 - (_QWORD)this;
        v41 = &this->mStateVariables.m_FormationSlot[0][0].m_Angle;
        v40 = this->m_NumSlotsPerRange;
        do
        {
          if ( !*(int *)((char *)v16 + v17 + (unsigned __int64)this->mStateVariables.m_pCurrentProfile + 4) )
          {
            slot_index = 0;
            if ( *v16 > 0 )
            {
              v18 = p_m_Angle;
              v19 = m_ExpensiveUpdateCount % v13;
              v37 = m_ExpensiveUpdateCount % v13;
              v16 = v40;
              do
              {
                v20 = v19 == v6;
                v21 = *(_QWORD *)(v18 + 38);
                if ( v21 )
                  v22 = *(_QWORD *)(v21 + 88);
                else
                  v22 = 0i64;
                v23 = *(_QWORD *)(v18 + 26);
                if ( v21 )
                {
                  if ( v22 )
                  {
                    if ( v23 )
                    {
                      v24 = *(_QWORD *)(v23 + 104);
                      if ( !v24 || !*(_BYTE *)(v24 + 96) )
                      {
                        v43 = ++v6;
                        if ( v20 )
                        {
                          if ( !UFG::FormationManagerComponent::DirectionIsClear(
                                  this,
                                  (UFG::qVector3 *)v18 - 1,
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
                            v46 = v26;
                            do
                            {
                              for ( i = 0; i < 10; ++i )
                              {
                                v29 = 3276 * (i + 1) + *v18;
                                v30 = *v18 - 3276 * (i + 1);
                                if ( UFG::FormationManagerComponent::AngleIsClear(
                                       this,
                                       v29,
                                       (UFG::GetInFormationNode *)v23,
                                       *((float *)v18 + 1),
                                       v25) )
                                {
                                  v30 = v29;
LABEL_34:
                                  z = UFG::qVector3::msZero.z;
                                  v32 = (float)((float)v30 * 3.1415927) * 0.000030517578;
                                  v33 = sinf(v32);
                                  v34 = *((float *)v18 + 1);
                                  v35 = v33;
                                  v36 = cosf(v32);
                                  desired_direction.y = v35 * v34;
                                  desired_direction.z = z * v34;
                                  desired_direction.x = v36 * v34;
                                  UFG::FormationManagerComponent::SetDesiredDirection(
                                    this,
                                    range_index,
                                    slot_index,
                                    (UFG::GetInFormationNode *)v23,
                                    &desired_direction);
                                  goto LABEL_35;
                                }
                                if ( UFG::FormationManagerComponent::AngleIsClear(
                                       this,
                                       v30,
                                       (UFG::GetInFormationNode *)v23,
                                       *((float *)v18 + 1),
                                       v25) )
                                {
                                  goto LABEL_34;
                                }
                              }
                              v25 = 1;
                              if ( UFG::FormationManagerComponent::DirectionIsClear(
                                     this,
                                     (UFG::qVector3 *)v18 - 1,
                                     (UFG::GetInFormationNode *)v23,
                                     0i64,
                                     0i64,
                                     1) )
                              {
                                break;
                              }
                              ++v27;
                            }
                            while ( v27 < v46 );
LABEL_35:
                            v6 = v43;
                          }
                          v16 = v40;
                        }
                      }
                    }
                  }
                }
                v19 = v37;
                v18 += 100;
                ++slot_index;
              }
              while ( slot_index < *v16 );
              v14 = range_index;
              p_m_Angle = v41;
              v13 = v38;
              m_ExpensiveUpdateCount = v39;
            }
          }
          v17 = -332i64 - (_QWORD)this;
          ++v14;
          ++v16;
          p_m_Angle += 800;
          range_index = v14;
          v40 = v16;
          v41 = p_m_Angle;
        }
        while ( v14 < this->m_NumRanges );
      }
    }
  }
}   v41 = p_m_Angle;
        }
        while ( v14 < this->m_NumRanges );
      }
    }
  }
}

// File Line: 2360
// RVA: 0x352570
bool __fastcall UFG::FormationManagerComponent::DirectionIsClear(
        UFG::FormationManagerComponent *this,
        UFG::qVector3 *direction,
        UFG::GetInFormationNode *get_in_formation,
        float *max_clear_distance,
        bool *outside_combat_region,
        bool force_physics_raycast)
{
  bool *v6; // rdi
  UFG::SimComponent *m_pPointer; // r14
  UFG::SimComponent *v10; // rbx
  UFG::SimObject *m_pSimObject; // r14
  UFG::SimComponent *ComponentOfType; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimComponent *v14; // r12
  UFG::CombatRegion *v15; // rcx
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm3_4
  int v20; // edx
  UFG::SimObject *v21; // rcx
  bool v22; // di
  UFG::SimComponent *v23; // rax
  float v24; // xmm6_4
  UFG::SimComponent *m_pSimComponent; // rdi
  UFG::SimObject *v26; // rcx
  __m128 mPrev_high; // xmm2
  float v28; // xmm1_4
  float v29; // xmm8_4
  bool v30; // al
  __m128 y_low; // xmm0
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm2_4
  __m128 v35; // xmm3
  __m128 v36; // xmm1
  float v37; // xmm0_4
  float v38; // xmm1_4
  UFG::SimObject *v39; // rcx
  bool v40; // al
  __m128 v41; // xmm1
  float v42; // xmm2_4
  UFG::qVector3 last_valid_position; // [rsp+40h] [rbp-59h] BYREF
  UFG::qVector3 vPoint; // [rsp+50h] [rbp-49h] BYREF
  UFG::qVector3 to_position; // [rsp+60h] [rbp-39h] BYREF
  UFG::qVector3 from_position; // [rsp+70h] [rbp-29h] BYREF
  UFG::SimObject *ray_hit_object; // [rsp+F0h] [rbp+57h] BYREF
  UFG::qVector3 *v48; // [rsp+F8h] [rbp+5Fh]
  float *v49; // [rsp+108h] [rbp+6Fh]

  v49 = max_clear_distance;
  v48 = direction;
  v6 = outside_combat_region;
  if ( outside_combat_region )
    *outside_combat_region = 0;
  m_pPointer = get_in_formation->m_pOwner.m_pPointer;
  v10 = 0i64;
  if ( !m_pPointer )
  {
    m_pSimObject = 0i64;
    goto LABEL_7;
  }
  m_pSimObject = m_pPointer->m_pSimObject;
  if ( !m_pSimObject )
  {
LABEL_7:
    v14 = 0i64;
    m_pTransformNodeComponent = 0i64;
    goto LABEL_8;
  }
  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActiveAIEntityComponent::_TypeUID);
  m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  v14 = ComponentOfType;
LABEL_8:
  if ( !this->m_pAIEntityComponent.m_pSimComponent
    || !this->m_pTransformNodeComponent.m_pSimComponent
    || !m_pSimObject
    || !v14
    || !m_pTransformNodeComponent )
  {
    return 1;
  }
  LODWORD(outside_combat_region) = get_in_formation->m_AttackType;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v15 = *(UFG::CombatRegion **)&v14[15].m_TypeUID;
  x = v48->x + m_pTransformNodeComponent->mWorldTransform.v3.x;
  y = v48->y + m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = v48->z + m_pTransformNodeComponent->mWorldTransform.v3.z;
  vPoint.x = x;
  vPoint.y = y;
  vPoint.z = z;
  last_valid_position.x = x;
  last_valid_position.y = y;
  last_valid_position.z = z;
  if ( v15 )
  {
    if ( !UFG::CombatRegion::IsHitPoint(v15, &vPoint) )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      if ( v6 )
        *v6 = 1;
      return 0;
    }
    z = vPoint.z;
    y = vPoint.y;
    x = vPoint.x;
  }
  v20 = (int)outside_combat_region;
  if ( (_DWORD)outside_combat_region || force_physics_raycast )
  {
    v23 = get_in_formation->m_pOwner.m_pPointer;
    if ( v23 && LOBYTE(v23[1].m_Flags) )
      goto LABEL_38;
    v24 = FLOAT_1_5;
    if ( !(_DWORD)outside_combat_region )
      v24 = FLOAT_0_5;
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    v26 = 0i64;
    if ( m_pSimComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
      v26 = 0i64;
      ray_hit_object = 0i64;
      mPrev_high = (__m128)HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
      v28 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
      x = vPoint.x;
      y = vPoint.y;
      z = vPoint.z;
      v29 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
      LODWORD(from_position.y) = mPrev_high.m128_i32[0];
      from_position.x = v28;
      to_position = vPoint;
      mPrev_high.m128_f32[0] = (float)((float)((float)(mPrev_high.m128_f32[0] - vPoint.y)
                                             * (float)(mPrev_high.m128_f32[0] - vPoint.y))
                                     + (float)((float)(v28 - vPoint.x) * (float)(v28 - vPoint.x)))
                             + (float)((float)(v29 - vPoint.z) * (float)(v29 - vPoint.z));
      if ( _mm_sqrt_ps(mPrev_high).m128_f32[0] <= 100.0 )
      {
        from_position.z = v29 + v24;
        to_position.z = vPoint.z + v24;
        v30 = UFG::DoRaycast(
                &from_position,
                &to_position,
                m_pSimObject,
                &last_valid_position,
                &ray_hit_object,
                0i64,
                0,
                &UFG::qColour::Yellow);
        v26 = ray_hit_object;
        v20 = (int)outside_combat_region;
        z = vPoint.z;
        y = vPoint.y;
        x = vPoint.x;
      }
      else
      {
        v20 = (int)outside_combat_region;
        v30 = 0;
      }
    }
    else
    {
      v30 = 0;
    }
    y_low = (__m128)LODWORD(last_valid_position.y);
    y_low.m128_f32[0] = last_valid_position.y - y;
    if ( v30
      || !v26
      && (y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                                    + (float)((float)(last_valid_position.x - x) * (float)(last_valid_position.x - x)))
                            + (float)((float)(last_valid_position.z - z) * (float)(last_valid_position.z - z)),
          _mm_sqrt_ps(y_low).m128_f32[0] < 0.1) )
    {
LABEL_38:
      v22 = 1;
    }
    else
    {
      v35 = (__m128)LODWORD(last_valid_position.y);
      v32 = m_pTransformNodeComponent->mWorldTransform.v3.x;
      v22 = 0;
      v33 = m_pTransformNodeComponent->mWorldTransform.v3.y;
      v34 = last_valid_position.x - v32;
      v35.m128_f32[0] = last_valid_position.y - v33;
      v36 = v35;
      v36.m128_f32[0] = (float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v34 * v34);
      v37 = _mm_sqrt_ps(v36).m128_f32[0];
      if ( v37 > 1.0 )
      {
        v38 = (float)(v37 - 1.0) / v37;
        last_valid_position.z = (float)(v38 * 0.0) + m_pTransformNodeComponent->mWorldTransform.v3.z;
        last_valid_position.x = v32 + (float)(v34 * v38);
        last_valid_position.y = v33 + (float)(v35.m128_f32[0] * v38);
      }
    }
    if ( (unsigned int)(v20 - 1) <= 1 )
    {
      v39 = v14->m_pSimObject;
      if ( v39 )
        v10 = UFG::SimObject::GetComponentOfType(v39, UFG::NavComponent::_TypeUID);
      outside_combat_region = *(bool **)((char *)&v10[2].m_BoundComponentHandles.mNode.mNext + 4);
      HIDWORD(outside_combat_region) |= 0x200u;
      v40 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
              UFG::NavManager::ms_pInstance,
              (UFG::HavokNavPosition *)&v10[1].m_SafePointerList.mNode.mNext,
              &vPoint,
              (UFG::NavParams *)&outside_combat_region,
              &last_valid_position);
      v22 = v22 && !v40;
    }
  }
  else
  {
    v21 = this->m_pAIEntityComponent.m_pSimComponent->m_pSimObject;
    if ( v21 )
      v10 = UFG::SimObject::GetComponentOfType(v21, UFG::NavComponent::_TypeUID);
    outside_combat_region = *(bool **)((char *)&v10[2].m_BoundComponentHandles.mNode.mNext + 4);
    HIDWORD(outside_combat_region) |= 0x200u;
    v22 = !UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
             UFG::NavManager::ms_pInstance,
             (UFG::HavokNavPosition *)&v10[1].m_SafePointerList.mNode.mNext,
             &vPoint,
             (UFG::NavParams *)&outside_combat_region,
             &last_valid_position);
  }
  if ( v49 )
  {
    v41 = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
    v41.m128_f32[0] = (float)((float)(v41.m128_f32[0] - last_valid_position.y)
                            * (float)(v41.m128_f32[0] - last_valid_position.y))
                    + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - last_valid_position.x)
                            * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - last_valid_position.x));
    v42 = _mm_sqrt_ps(v41).m128_f32[0];
    if ( v42 <= 1.0 )
      v42 = *(float *)&FLOAT_1_0;
    *v49 = v42;
  }
  return v22;
}

// File Line: 2504
// RVA: 0x341A90
char __fastcall UFG::FormationManagerComponent::AngleIsClear(
        UFG::FormationManagerComponent *this,
        unsigned __int16 angle,
        UFG::GetInFormationNode *get_in_formation,
        float distance,
        bool force_physics_raycast)
{
  float v7; // xmm7_4
  UFG::qVector3 direction; // [rsp+30h] [rbp-48h] BYREF

  v7 = (float)((float)angle * 3.1415927) * 0.000030517578;
  direction.y = sinf(v7) * distance;
  direction.x = cosf(v7) * distance;
  direction.z = distance * 0.0;
  return UFG::FormationManagerComponent::DirectionIsClear(
           this,
           &direction,
           get_in_formation,
           0i64,
           0i64,
           force_physics_raycast);
}

// File Line: 2519
// RVA: 0x388660
void __fastcall UFG::FormationManagerComponent::SpreadOutDesiredPositions(
        UFG::FormationManagerComponent *this,
        float delta_sec)
{
  int v2; // eax
  float v3; // xmm7_4
  UFG::FormationManagerComponent *v4; // r10
  int v5; // r11d
  __int64 v6; // r13
  unsigned __int16 *p_m_Angle; // rbx
  int *m_NumSlotsPerRange; // rdi
  char *v9; // rdx
  __int64 v10; // rcx
  unsigned __int16 *v11; // rsi
  int *v12; // r9
  __int64 v13; // rcx
  int v14; // r8d
  float *v15; // rbp
  unsigned __int16 *v16; // r12
  __int64 v17; // rdx
  __int64 v18; // rax
  __int64 v19; // r15
  unsigned __int16 *v20; // rax
  int *v21; // r14
  int v22; // esi
  __int64 v23; // rdi
  unsigned __int16 *v24; // rbx
  bool v25; // al
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm6_4
  int v29; // r12d
  float v30; // xmm8_4
  char *v31; // r14
  unsigned __int16 *v32; // r15
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
  int *v44; // [rsp+40h] [rbp-188h]
  char *v45; // [rsp+48h] [rbp-180h]
  unsigned __int16 *v46; // [rsp+50h] [rbp-178h]
  __int64 v47; // [rsp+58h] [rbp-170h]
  unsigned __int16 *v48; // [rsp+60h] [rbp-168h]
  char dest[288]; // [rsp+70h] [rbp-158h] BYREF
  int v51; // [rsp+1E0h] [rbp+18h]
  int v52; // [rsp+1E8h] [rbp+20h]

  v2 = 0;
  v42 = 0;
  do
  {
    if ( v2 >= 10 )
      break;
    v3 = 0.0;
    UFG::qMemSet(dest, 0, 0x80u);
    v4 = this;
    v5 = 0;
    v6 = 0i64;
    v52 = 0;
    if ( this->m_NumRanges > 0 )
    {
      p_m_Angle = &this->mStateVariables.m_FormationSlot[0][0].m_Angle;
      m_NumSlotsPerRange = this->m_NumSlotsPerRange;
      v9 = dest;
      v10 = -332i64 - (_QWORD)this;
      v11 = &this->mStateVariables.m_FormationSlot[0][0].m_Angle;
      v46 = &this->mStateVariables.m_FormationSlot[0][0].m_Angle;
      v12 = this->m_NumSlotsPerRange;
      v44 = this->m_NumSlotsPerRange;
      v45 = dest;
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
              v17 = *(_QWORD *)(v16 + 26);
              v47 = v17;
              if ( v17 )
              {
                if ( *(_QWORD *)(v16 + 38) )
                {
                  if ( !*((_BYTE *)v16 + 132) )
                  {
                    v18 = *(_QWORD *)(v17 + 104);
                    if ( !v18 || !*(_BYTE *)(v18 + 96) )
                    {
                      v19 = 0i64;
                      if ( v6 >= 0 )
                      {
                        v20 = p_m_Angle;
                        v48 = p_m_Angle;
                        v21 = m_NumSlotsPerRange;
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
                              if ( *(_QWORD *)(v24 + 38) && !v25 )
                              {
                                v26 = (float)((float)(unsigned __int16)(*v16 - *v24) * 360.0) * 0.000015258789;
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
                                  if ( *(_QWORD *)(v16 + 38) && !*(_DWORD *)(v17 + 52)
                                    || UFG::FormationManagerComponent::NewAngleDoesntCrossOverSomeone(
                                         v4,
                                         v5,
                                         v14,
                                         *v16 + (int)(float)((float)((float)(v28 + *v15) * 65536.0) * 0.0027777778)) )
                                  {
                                    *v15 = v28 + *v15;
                                  }
                                }
                                v13 = v43;
                              }
                              v17 = v47;
                              v14 = v51;
                              v4 = this;
                              v5 = v52;
                              ++v22;
                              ++v23;
                              v24 += 100;
                            }
                            while ( v22 < *v21 );
                            v20 = v48;
                          }
                          v20 += 800;
                          ++v19;
                          ++v21;
                          v48 = v20;
                        }
                        while ( v19 <= v6 );
                        v12 = v44;
                        p_m_Angle = &v4->mStateVariables.m_FormationSlot[0][0].m_Angle;
                        m_NumSlotsPerRange = v4->m_NumSlotsPerRange;
                      }
                    }
                  }
                }
              }
              ++v14;
              ++v13;
              v16 += 100;
              ++v15;
              v51 = v14;
              v43 = v13;
            }
            while ( v14 < *v12 );
            v9 = v45;
            v11 = v46;
          }
        }
        v10 = -332i64 - (_QWORD)this;
        ++v5;
        ++v12;
        v9 += 32;
        v11 += 800;
        ++v6;
        v52 = v5;
        v44 = v12;
        v45 = v9;
        v46 = v11;
      }
      while ( v5 < v4->m_NumRanges );
    }
    v29 = 0;
    v30 = 0.0;
    if ( v4->m_NumRanges > 0 )
    {
      v31 = dest;
      v32 = &v4->mStateVariables.m_FormationSlot[0][0].m_Angle;
      v33 = v4->m_NumSlotsPerRange;
      do
      {
        v34 = 0;
        if ( *v33 > 0 )
        {
          v35 = (float *)v31;
          v36 = v32;
          do
          {
            v37 = *v35;
            if ( v30 <= *v35 )
              v30 = *v35;
            if ( v37 > 0.1 )
            {
              if ( UFG::FormationManagerComponent::AngleIsClear(
                     v4,
                     *v36 + (int)(float)((float)(v37 * 65536.0) * 0.0027777778),
                     *(UFG::GetInFormationNode **)(v36 + 26),
                     *((float *)v36 + 1),
                     0) )
              {
                *v36 += (int)(float)((float)(*v35 * 65536.0) * 0.0027777778);
                v38 = (float)((float)*v36 * 3.1415927) * 0.000030517578;
                v39 = sinf(v38);
                v40 = cosf(v38);
                v41 = *((float *)v36 + 1) / fsqrt((float)(v40 * v40) + (float)(v39 * v39));
                *((float *)v36 - 1) = v41 * 0.0;
                *((float *)v36 - 3) = v40 * v41;
                *((float *)v36 - 2) = v39 * v41;
              }
              v4 = this;
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
        v32 += 800;
      }
      while ( v29 < v4->m_NumRanges );
    }
    v2 = ++v42;
  }
  while ( v30 > 2.0 );
}          ++v35;
          }
          while ( v34 < *v33 );
        }
        ++v29;
        ++v33;
        v31 += 32;
        v32 += 800;
      }
      while ( v29 

// File Line: 2650
// RVA: 0x358100
__int64 __fastcall UFG::FormationManagerComponent::FindRangeIndex(
        UFG::FormationManagerComponent *this,
        UFG::SimObject *sim_object)
{
  __int64 m_NumRanges; // rsi
  unsigned int v3; // edi
  __int64 v4; // r10
  UFG::SimObject **p_m_pPointer; // r11
  int *i; // rbx
  __int64 v7; // r8
  __int64 v8; // rcx
  UFG::SimObject **v9; // rax

  if ( !sim_object )
    return 0xFFFFFFFFi64;
  m_NumRanges = this->m_NumRanges;
  v3 = 0;
  v4 = 0i64;
  if ( m_NumRanges <= 0 )
    return 0xFFFFFFFFi64;
  p_m_pPointer = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  for ( i = this->m_NumSlotsPerRange; ; ++i )
  {
    v7 = *i;
    v8 = 0i64;
    if ( v7 > 0 )
      break;
LABEL_9:
    ++v4;
    ++v3;
    p_m_pPointer += 200;
    if ( v4 >= m_NumRanges )
      return 0xFFFFFFFFi64;
  }
  v9 = p_m_pPointer;
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
char __fastcall UFG::FormationManagerComponent::FindRangeAndSlotIndex(
        UFG::FormationManagerComponent *this,
        UFG::HasAttackRequestNode *has_attack_request_node,
        int *range_index,
        int *slot_index)
{
  int v5; // edx
  __int64 v6; // r13
  __int64 v7; // r8
  UFG::SimObject **p_m_pPointer; // rax
  int *m_NumSlotsPerRange; // rcx
  __int64 v10; // r12
  int v11; // r14d
  __int64 v12; // rdi
  UFG::SimObject **v13; // rbx
  UFG::SimObject *v14; // rbp
  __int64 v15; // rsi
  __int64 m_NumRanges; // [rsp+20h] [rbp-58h]
  int *v18; // [rsp+28h] [rbp-50h]
  UFG::SimObject **v19; // [rsp+30h] [rbp-48h]
  int v20; // [rsp+88h] [rbp+10h]

  if ( !has_attack_request_node )
    return 0;
  v5 = 0;
  v6 = 0i64;
  v20 = 0;
  m_NumRanges = this->m_NumRanges;
  if ( m_NumRanges <= 0 )
    return 0;
  v7 = this->m_NumRanges;
  p_m_pPointer = &this->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  m_NumSlotsPerRange = this->m_NumSlotsPerRange;
  v19 = p_m_pPointer;
  v18 = m_NumSlotsPerRange;
  while ( 1 )
  {
    v10 = *m_NumSlotsPerRange;
    v11 = 0;
    v12 = 0i64;
    if ( v10 > 0 )
      break;
LABEL_12:
    ++v5;
    ++m_NumSlotsPerRange;
    p_m_pPointer += 200;
    ++v6;
    v20 = v5;
    v18 = m_NumSlotsPerRange;
    v19 = p_m_pPointer;
    if ( v6 >= v7 )
      return 0;
  }
  v13 = p_m_pPointer;
  while ( 1 )
  {
    v15 = (__int64)*(v13 - 3);
    if ( *v13 )
    {
      v14 = *v13;
      if ( v14 == UFG::HasAttackRequestNode::GetSimObject(has_attack_request_node)
        && v15
        && *(_DWORD *)(v15 + 52) == has_attack_request_node->m_AttackType )
      {
        break;
      }
    }
    ++v12;
    ++v11;
    v13 += 25;
    if ( v12 >= v10 )
    {
      p_m_pPointer = v19;
      m_NumSlotsPerRange = v18;
      v5 = v20;
      v7 = m_NumRanges;
      goto LABEL_12;
    }
  }
  *range_index = v20;
  *slot_index = v11;
  return 1;
}

// File Line: 2701
// RVA: 0x36B9B0
bool __fastcall UFG::FormationManagerComponent::IsRegistered(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation)
{
  __int64 m_RangeIndex; // r8
  __int64 m_SlotIndex; // rax

  if ( !get_in_formation )
    return 0;
  m_RangeIndex = get_in_formation->m_RangeIndex;
  m_SlotIndex = get_in_formation->m_SlotIndex;
  return (_DWORD)m_RangeIndex != -1
      && (_DWORD)m_SlotIndex != -1
      && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == get_in_formation;
}

// File Line: 2740
// RVA: 0x35DDF0
__int64 __fastcall UFG::FormationManagerComponent::GetDesiredRange(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation)
{
  UFG::TransformNodeComponent *m_pSimComponent; // r15
  UFG::eFormationRangePreference m_RangePreference; // ebp
  unsigned int v6; // edi
  UFG::SimComponent *m_pPointer; // r14
  int v8; // ebx
  UFG::SimObject *m_pSimObject; // r14
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  __m128 y_low; // xmm0
  float v12; // xmm2_4
  __int32 v13; // ebp
  __int32 v14; // ebp
  __int32 v15; // ebp
  int v16; // ebp
  __int64 v17; // r10
  int v18; // r11d
  int *v19; // r8
  __int64 v20; // rdx
  float v21; // xmm0_4
  __int64 v22; // r9
  float v23; // xmm0_4
  __int64 v24; // rdx
  float v25; // xmm0_4
  __int64 v26; // rdx
  float v27; // xmm0_4
  __int64 v28; // rdx
  __int64 m_CurrentBattleType; // rcx
  float v30; // xmm0_4
  int v31; // eax
  int *v32; // rcx
  int v33; // edx
  int v34; // eax
  int *v35; // rcx
  int m_NumRanges; // ecx
  int *m_NumFreeSlotsPerRange; // rax

  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  m_RangePreference = get_in_formation->m_RangePreference;
  v6 = -1;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  m_pPointer = get_in_formation->m_pOwner.m_pPointer;
  v8 = 0;
  if ( m_pPointer && (m_pSimObject = m_pPointer->m_pSimObject) != 0i64 )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - m_pSimComponent->mWorldTransform.v3.y)
                            * (float)(y_low.m128_f32[0] - m_pSimComponent->mWorldTransform.v3.y))
                    + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                    - m_pSimComponent->mWorldTransform.v3.x)
                            * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                    - m_pSimComponent->mWorldTransform.v3.x));
  LODWORD(v12) = _mm_sqrt_ps(y_low).m128_u32[0];
  v13 = m_RangePreference - 1;
  if ( !v13 )
  {
    m_NumRanges = this->m_NumRanges;
    if ( m_NumRanges > 0 )
    {
      m_NumFreeSlotsPerRange = this->m_NumFreeSlotsPerRange;
      do
      {
        if ( v6 != -1 )
          break;
        if ( *m_NumFreeSlotsPerRange > 0 )
          v6 = v8;
        ++v8;
        ++m_NumFreeSlotsPerRange;
      }
      while ( v8 < m_NumRanges );
    }
    return v6;
  }
  v14 = v13 - 1;
  if ( !v14 )
  {
    v33 = this->m_NumRanges;
    v34 = v33 - 2;
    if ( v33 - 2 < v33 )
    {
      v35 = &this->m_NumFreeSlotsPerRange[v34];
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
  v16 = this->m_NumRanges;
  v17 = 0i64;
  if ( v16 < 4 )
  {
LABEL_45:
    if ( v8 < v16 )
    {
      v28 = 4 * v17 + 20;
      while ( v6 == -1 )
      {
        if ( *(int *)((char *)&this->m_NumSlotsPerRange[3] + v28) > 0 )
        {
          m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
          if ( v8 < 0 || (_DWORD)m_CurrentBattleType == -1 )
          {
            v30 = 0.0;
          }
          else
          {
            v30 = *(float *)((char *)&this->mStateVariables.m_pCurrentProfile->m_NameID.mUID + v28);
            if ( v30 < 0.0 )
              v30 = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxDistance[v17];
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
    v31 = this->m_NumRanges - 1;
    if ( v31 >= 0 )
    {
      v32 = &this->m_NumFreeSlotsPerRange[v31];
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
  v19 = &this->m_NumFreeSlotsPerRange[1];
  while ( v6 == -1 )
  {
    if ( *(v19 - 1) > 0 )
    {
      v20 = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      if ( v8 < 0 || (_DWORD)v20 == -1 )
      {
        v21 = 0.0;
      }
      else
      {
        v21 = *(float *)((char *)&this->mStateVariables.m_pCurrentProfile[-3].m_NameID.mUID
                       + (unsigned __int64)v19
                       - (_QWORD)this);
        if ( v21 < 0.0 )
          v21 = this->m_BattleTypeSpecificParameters[v20].m_MaxDistance[v17];
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
      v22 = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      if ( v18 - 1 < 0 || (_DWORD)v22 == -1 )
      {
        v23 = 0.0;
      }
      else
      {
        v23 = *(float *)((char *)&this->mStateVariables.m_pCurrentProfile[-2]
                       + (unsigned __int64)v19
                       - (_QWORD)this
                       - 112);
        if ( v23 < 0.0 )
          v23 = this->m_BattleTypeSpecificParameters[v22].m_MaxDistance[v17 + 1];
      }
      if ( v12 < v23 )
      {
        v6 = v18 - 1;
        if ( v18 )
          break;
      }
    }
    if ( v19[1] > 0 )
    {
      v24 = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      if ( v18 < 0 || (_DWORD)v24 == -1 )
      {
        v25 = 0.0;
      }
      else
      {
        v25 = *(float *)((char *)&this->mStateVariables.m_pCurrentProfile[-2]
                       + (unsigned __int64)v19
                       - (_QWORD)this
                       - 108);
        if ( v25 < 0.0 )
          v25 = this->m_BattleTypeSpecificParameters[v24].m_MaxDistance[v17 + 2];
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
      v26 = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
      if ( v18 + 1 < 0 || (_DWORD)v26 == -1 )
      {
        v27 = 0.0;
      }
      else
      {
        v27 = *(float *)((char *)&this->mStateVariables.m_pCurrentProfile[-2]
                       + (unsigned __int64)v19
                       - (_QWORD)this
                       - 104);
        if ( v27 < 0.0 )
          v27 = this->m_BattleTypeSpecificParameters[v26].m_MaxDistance[v17 + 3];
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
char __fastcall UFG::FormationManagerComponent::RangeMeetsPreference(
        UFG::FormationManagerComponent *this,
        int range_index,
        UFG::eFormationRangePreference range_preference)
{
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d

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
char __fastcall UFG::FormationManagerComponent::RequestRegistration(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation)
{
  __int64 m_RangeIndex; // rcx
  __int64 m_SlotIndex; // rax
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *m_pSimObject; // rcx
  int DesiredRange; // eax

  if ( get_in_formation )
  {
    m_RangeIndex = get_in_formation->m_RangeIndex;
    m_SlotIndex = get_in_formation->m_SlotIndex;
    if ( (_DWORD)m_RangeIndex != -1
      && (_DWORD)m_SlotIndex != -1
      && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == get_in_formation )
    {
      return 0;
    }
  }
  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0;
  m_pPointer = get_in_formation->m_pOwner.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_pSimObject = m_pPointer->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  if ( !m_pSimObject->m_pTransformNodeComponent )
    return 0;
  DesiredRange = UFG::FormationManagerComponent::GetDesiredRange(this, get_in_formation);
  if ( DesiredRange == -1 )
    return 0;
  UFG::FormationManagerComponent::Register(this, get_in_formation, DesiredRange, 1);
  return 1;
}

// File Line: 2912
// RVA: 0x3806D0
void __fastcall UFG::FormationManagerComponent::Register(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation,
        int range_index,
        bool allowed_to_switch_to_range_preference)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rsi
  __int64 v5; // r12
  int v7; // ecx
  int v8; // r14d
  int v11; // r10d
  UFG::GetInFormationNode **v12; // r9
  __int64 v13; // rbx
  UFG::SimComponent *m_pPointer; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *vecDelDtor; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx

  vfptr = 0i64;
  v5 = range_index;
  v7 = this->m_NumSlotsPerRange[range_index];
  v8 = -1;
  v11 = 0;
  if ( v7 > 0 )
  {
    v12 = &this->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer + 200 * range_index;
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
  UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(this, range_index, v8, get_in_formation);
  v13 = v8 + 8 * v5;
  UFG::FormationSlot::SetFormationMember(&this->mStateVariables.m_FormationSlot[0][v13], get_in_formation);
  this->mStateVariables.m_FormationSlot[0][v13].m_FacingType = this->m_FormationFacingType;
  UFG::FormationSlot::SetRadialHysteresisModifier(&this->mStateVariables.m_FormationSlot[0][v13]);
  m_pPointer = get_in_formation->m_pOwner.m_pPointer;
  get_in_formation->m_RangeIndex = v5;
  get_in_formation->m_SlotIndex = v8;
  get_in_formation->m_AllowedToSwitchToRangePreference = allowed_to_switch_to_range_preference;
  if ( m_pPointer )
    vfptr = m_pPointer[2].vfptr;
  v15 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&vfptr[207];
  if ( vfptr[209].__vecDelDtor )
  {
    mPrev = v15->mPrev;
    vecDelDtor = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)vfptr[208].__vecDelDtor;
    mPrev->mNext = vecDelDtor;
    vecDelDtor->mPrev = mPrev;
    v15->mPrev = v15;
    vfptr[208].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&vfptr[207];
  }
  vfptr[209].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))this;
  v18 = this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
  v18->mNext = v15;
  v15->mPrev = v18;
  vfptr[208].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&this->m_SafePointerList;
  this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v15;
  --this->m_NumFreeSlotsPerRange[v5];
}

// File Line: 2950
// RVA: 0x382660
void __fastcall UFG::FormationManagerComponent::Reregister(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation,
        int new_range_index,
        bool allowed_to_switch_to_range_preference)
{
  __int64 v5; // rsi
  __int64 m_RangeIndex; // rdx
  __int64 m_SlotIndex; // r8

  v5 = new_range_index;
  if ( get_in_formation )
  {
    m_RangeIndex = get_in_formation->m_RangeIndex;
    m_SlotIndex = get_in_formation->m_SlotIndex;
    if ( (_DWORD)m_RangeIndex != -1
      && (_DWORD)m_SlotIndex != -1
      && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == get_in_formation )
    {
      UFG::FormationManagerComponent::Unregister(this, m_RangeIndex, m_SlotIndex);
    }
  }
  UFG::FormationManagerComponent::Register(this, get_in_formation, v5, allowed_to_switch_to_range_preference);
  UFG::FormationManagerComponent::SetTimeToDoSomething(
    this,
    this->m_BattleTypeSpecificParameters[UFG::BattleManager::s_pInstance->m_CurrentBattleType].m_MinTimeBeforeSwitchFromRange[v5],
    this->m_BattleTypeSpecificParameters[UFG::BattleManager::s_pInstance->m_CurrentBattleType].m_MaxTimeBeforeSwitchFromRange[v5],
    &this->mStateVariables.m_NextTimeToSwitchFromRange[v5]);
}

// File Line: 2958
// RVA: 0x385F30
void __fastcall UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation)
{
  __int64 m_RangeIndex; // r10
  __int64 m_SlotIndex; // r8

  if ( get_in_formation )
  {
    m_RangeIndex = get_in_formation->m_RangeIndex;
    m_SlotIndex = get_in_formation->m_SlotIndex;
    if ( (_DWORD)m_RangeIndex != -1
      && (_DWORD)m_SlotIndex != -1
      && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == get_in_formation )
    {
      UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
        this,
        m_RangeIndex,
        m_SlotIndex,
        get_in_formation);
    }
  }
}

// File Line: 2967
// RVA: 0x385E30
void __fastcall UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
        UFG::FormationManagerComponent *this,
        int range_index,
        int slot_index,
        UFG::GetInFormationNode *get_in_formation)
{
  UFG::TransformNodeComponent *m_pSimComponent; // rsi
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *v11; // rbx
  UFG::SimObject *v12; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v14; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 desired_direction; // [rsp+30h] [rbp-28h] BYREF

  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( get_in_formation )
    {
      m_pPointer = get_in_formation->m_pOwner.m_pPointer;
      if ( m_pPointer )
      {
        m_pSimObject = m_pPointer->m_pSimObject;
        if ( m_pSimObject )
        {
          if ( m_pSimObject->m_pTransformNodeComponent )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
            v11 = get_in_formation->m_pOwner.m_pPointer;
            if ( v11 && (v12 = v11->m_pSimObject) != 0i64 )
              m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
            else
              m_pTransformNodeComponent = 0i64;
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
            v14 = m_pTransformNodeComponent->mWorldTransform.v3.y - m_pSimComponent->mWorldTransform.v3.y;
            desired_direction.x = m_pTransformNodeComponent->mWorldTransform.v3.x
                                - m_pSimComponent->mWorldTransform.v3.x;
            z = m_pTransformNodeComponent->mWorldTransform.v3.z;
            desired_direction.y = v14;
            desired_direction.z = z - m_pSimComponent->mWorldTransform.v3.z;
            UFG::FormationManagerComponent::SetDesiredDirection(
              this,
              range_index,
              slot_index,
              get_in_formation,
              &desired_direction);
          }
        }
      }
    }
  }
}

// File Line: 2980
// RVA: 0x385580
void __fastcall UFG::FormationManagerComponent::SetDesiredDirection(
        UFG::FormationManagerComponent *this,
        int range_index,
        int slot_index,
        UFG::GetInFormationNode *get_in_formation,
        UFG::qVector3 *desired_direction)
{
  UFG::SimComponent *m_pPointer; // rax
  __int64 v7; // r13
  __int64 v8; // rsi
  __int64 v10; // rdi
  UFG::TransformNodeComponent *m_pSimComponent; // rbp
  UFG::qVector3 *v12; // r12
  __m128 v13; // xmm0
  __int64 m_CurrentBattleType; // rdx
  float v15; // xmm1_4
  int v16; // ecx
  float v17; // xmm9_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  UFG::qVector3 *v22; // r14
  float y; // xmm8_4
  __m128 x_low; // xmm7
  __m128 v25; // xmm1
  UFG::FormationSlot *v26; // rdi
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
  unsigned int m_InPosition; // r8d
  bool v42; // dl
  float v43; // xmm0_4
  float v44; // xmm2_4
  bool v45; // al
  float m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting; // xmm0_4
  bool v47; // cl
  int v48; // ebx
  float v49; // xmm0_4
  float current_lateral_offset; // [rsp+40h] [rbp-B8h] BYREF
  UFG::qVector3 direction; // [rsp+48h] [rbp-B0h] BYREF
  char v52; // [rsp+100h] [rbp+8h]
  float max_clear_distance; // [rsp+118h] [rbp+20h] BYREF

  m_pPointer = get_in_formation->m_pOwner.m_pPointer;
  v7 = slot_index;
  v8 = range_index;
  if ( m_pPointer )
    m_pPointer = (UFG::SimComponent *)m_pPointer->m_pSimObject;
  v10 = *(_QWORD *)&m_pPointer[1].m_TypeUID;
  if ( this->m_pTransformNodeComponent.m_pSimComponent && v10 )
  {
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10);
    v12 = (UFG::qVector3 *)(v10 + 176);
    v13 = (__m128)*(unsigned int *)(v10 + 180);
    m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
    v15 = *(float *)(v10 + 176) - m_pSimComponent->mWorldTransform.v3.x;
    v16 = v8 - 1;
    v52 = 1;
    v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] - m_pSimComponent->mWorldTransform.v3.y)
                            * (float)(v13.m128_f32[0] - m_pSimComponent->mWorldTransform.v3.y))
                    + (float)(v15 * v15);
    LODWORD(v17) = _mm_sqrt_ps(v13).m128_u32[0];
    v18 = v17;
    if ( (int)v8 - 1 < 0 || (_DWORD)m_CurrentBattleType == -1 )
    {
      v19 = 0.0;
    }
    else
    {
      v19 = this->mStateVariables.m_pCurrentProfile->m_MaxDistanceOverride[v16];
      if ( v19 < 0.0 )
        v19 = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxDistance[v16];
    }
    if ( (int)v8 < 0 || (_DWORD)m_CurrentBattleType == -1 )
    {
      v20 = 0.0;
    }
    else
    {
      v20 = this->mStateVariables.m_pCurrentProfile->m_MaxDistanceOverride[v8];
      if ( v20 < 0.0 )
        v20 = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxDistance[v8];
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
    y = desired_direction->y;
    x_low = (__m128)LODWORD(desired_direction->x);
    v25 = x_low;
    v26 = &this->mStateVariables.m_FormationSlot[v8][v7];
    v25.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y);
    direction.z = 0.0;
    max_clear_distance = 0.0;
    v27 = v18 / _mm_sqrt_ps(v25).m128_f32[0];
    v28 = x_low.m128_f32[0] * v27;
    v29 = y * v27;
    v30 = v28;
    v31 = v29;
    direction.x = v28;
    direction.y = v29;
    if ( !UFG::FormationManagerComponent::DirectionIsClear(
            this,
            &direction,
            get_in_formation,
            &max_clear_distance,
            0i64,
            0) )
    {
      v32 = v22->y;
      v33 = (__m128)LODWORD(v22->x);
      v18 = max_clear_distance;
      v34 = v33;
      v34.m128_f32[0] = (float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32);
      v35 = max_clear_distance / _mm_sqrt_ps(v34).m128_f32[0];
      v28 = v33.m128_f32[0] * v35;
      v29 = v32 * v35;
      v30 = v28;
      v31 = v29;
    }
    v36 = v30 + m_pSimComponent->mWorldTransform.v3.x;
    v37 = v31 + m_pSimComponent->mWorldTransform.v3.y;
    v38 = this->m_MaxRadialDistanceFromDesiredPosition[v8];
    direction.z = m_pSimComponent->mWorldTransform.v3.z;
    v39 = this->m_MaxLateralDistanceFromDesiredPosition[v8];
    current_lateral_offset = 0.0;
    max_clear_distance = 0.0;
    direction.x = v36;
    direction.y = v37;
    v40 = UFG::FormationManagerComponent::IsInPosition(
            this,
            v12,
            &direction,
            v38,
            v39,
            &max_clear_distance,
            &current_lateral_offset,
            0);
    m_InPosition = v26->m_InPosition;
    v42 = v40;
    v43 = *(float *)&FLOAT_1_0;
    v44 = *(float *)&FLOAT_1_0;
    if ( m_InPosition <= 1 )
    {
      v43 = FLOAT_2_0;
      v44 = FLOAT_2_0;
    }
    v45 = max_clear_distance <= v43 && current_lateral_offset <= v44;
    if ( this->mStateVariables.m_CurrentlySprinting )
      m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = this->m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
    else
      m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = (float)(this->m_MaxRadialDistanceFromDesiredPositionHysteresis[v8]
                                                                                        + this->m_MaxRadialDistanceFromDesiredPosition[v8])
                                                                                + 5.0;
    v47 = max_clear_distance >= m_MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting
       && v17 > (float)(max_clear_distance + 1.0);
    v48 = 0;
    if ( v47 )
      goto LABEL_40;
    if ( m_InPosition != 3 )
    {
      if ( !v42 )
        v48 = 2 - v45;
      goto LABEL_41;
    }
    if ( !v42 )
LABEL_40:
      v48 = 3;
LABEL_41:
    v26->m_Direction.x = v28;
    v26->m_Direction.y = v29;
    v26->m_Direction.z = 0.0;
    v49 = atan2f(v29, v28);
    v26->m_Distance = v18;
    v26->m_Angle = (int)(float)((float)(v49 * 32768.0) * 0.31830987);
    v26->m_CurrentlyInRange = v52;
    UFG::FormationSlot::SetInPosition(v26, (UFG::eInFormationPositionType)v48);
  }
}

// File Line: 3103
// RVA: 0x38A2F0
void __fastcall UFG::FormationManagerComponent::Unregister(
        UFG::FormationManagerComponent *this,
        int range_index,
        int slot_index)
{
  __int64 v3; // rsi
  UFG::FormationSlot (*m_FormationSlot)[8]; // rcx
  __int64 v6; // rdx
  UFG::GetInFormationNode *m_pPointer; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimComponent *v11; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v13; // rdx
  void *(__fastcall *vecDelDtor)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  void *(__fastcall *v15)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax

  v3 = range_index;
  m_FormationSlot = this->mStateVariables.m_FormationSlot;
  v6 = slot_index + 8i64 * range_index;
  m_pPointer = (*m_FormationSlot)[v6].m_pMember.m_pPointer;
  UFG::FormationSlot::SetFormationMember(&(*m_FormationSlot)[v6], 0i64);
  if ( m_pPointer )
  {
    p_m_pTargetFormationManagerComponent = &m_pPointer->m_pTargetFormationManagerComponent;
    *(_QWORD *)&m_pPointer->m_RangeIndex = -1i64;
    if ( m_pPointer->m_pTargetFormationManagerComponent.m_pPointer )
    {
      mPrev = p_m_pTargetFormationManagerComponent->mPrev;
      mNext = m_pPointer->m_pTargetFormationManagerComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
      m_pPointer->m_pTargetFormationManagerComponent.mNext = &m_pPointer->m_pTargetFormationManagerComponent;
    }
    m_pPointer->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
    v11 = m_pPointer->m_pOwner.m_pPointer;
    if ( v11 )
      vfptr = v11[2].vfptr;
    else
      vfptr = 0i64;
    v13 = vfptr + 207;
    if ( v13[2].__vecDelDtor )
    {
      vecDelDtor = v13->__vecDelDtor;
      v15 = v13[1].__vecDelDtor;
      *((_QWORD *)vecDelDtor + 1) = v15;
      *(_QWORD *)v15 = vecDelDtor;
      v13->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v13;
      v13[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v13;
    }
    v13[2].__vecDelDtor = 0i64;
    ++this->m_NumFreeSlotsPerRange[v3];
  }
}

// File Line: 3125
// RVA: 0x382360
char __fastcall UFG::FormationManagerComponent::RequestChangePosition(
        UFG::FormationManagerComponent *this,
        UFG::SimObject *sim_object,
        UFG::FormationPositionChangeRequest *request)
{
  __int64 m_NumRanges; // rbp
  int v4; // esi
  __int64 v5; // r11
  UFG::GetInFormationNode **p_m_pPointer; // rbx
  int *i; // rdi
  __int64 v11; // r10
  int v12; // r8d
  __int64 v13; // rdx
  UFG::GetInFormationNode **v14; // rcx
  UFG::GetInFormationNode *v15; // rax
  UFG::SimObject *m_pPointer; // rax
  UFG::FormationSlot *v18; // rdi
  UFG::eInFormationPositionType m_InPosition; // ebx

  m_NumRanges = this->m_NumRanges;
  v4 = 0;
  v5 = 0i64;
  if ( m_NumRanges <= 0 )
    return 0;
  p_m_pPointer = &this->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer;
  for ( i = this->m_NumSlotsPerRange; ; ++i )
  {
    v11 = *i;
    v12 = 0;
    v13 = 0i64;
    if ( v11 > 0 )
      break;
LABEL_11:
    ++v5;
    ++v4;
    p_m_pPointer += 200;
    if ( v5 >= m_NumRanges )
      return 0;
  }
  v14 = p_m_pPointer;
  while ( 1 )
  {
    v15 = *v14;
    if ( sim_object && v15 )
    {
      m_pPointer = (UFG::SimObject *)v15->m_pOwner.m_pPointer;
      if ( m_pPointer )
        m_pPointer = (UFG::SimObject *)m_pPointer->mNode.mParent;
      if ( m_pPointer == sim_object )
        break;
    }
    ++v13;
    ++v12;
    v14 += 25;
    if ( v13 >= v11 )
      goto LABEL_11;
  }
  v18 = &this->mStateVariables.m_FormationSlot[v4][v12];
  m_InPosition = v18->m_InPosition;
  UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(this, v4, v12, v18->m_pMember.m_pPointer);
  UFG::FormationSlot::SetInPosition(v18, m_InPosition);
  v18->m_RequestedToChangePosition = 1;
  v18->m_PositionChangeRequest.m_DesiredSpeed = request->m_DesiredSpeed;
  *(_DWORD *)&v18->m_PositionChangeRequest.m_Clockwise = *(_DWORD *)&request->m_Clockwise;
  v18->m_PositionChangeRequest.m_FacingType = request->m_FacingType;
  *(_DWORD *)&v18->m_PositionChangeRequest.m_AbsolutePosition = *(_DWORD *)&request->m_AbsolutePosition;
  return 1;
}

// File Line: 3151
// RVA: 0x382480
char __fastcall UFG::FormationManagerComponent::RequestInvalidatePosition(
        UFG::FormationManagerComponent *this,
        UFG::SimObject *sim_object)
{
  __int64 m_NumRanges; // r14
  int v3; // esi
  __int64 v4; // r11
  UFG::GetInFormationNode **p_m_pPointer; // rbx
  int *i; // rdi
  __int64 v9; // r10
  int v10; // r8d
  __int64 v11; // rdx
  UFG::GetInFormationNode **v12; // rcx
  UFG::GetInFormationNode *v13; // rax
  UFG::SimObject *m_pPointer; // rax
  __int64 v16; // rbx

  m_NumRanges = this->m_NumRanges;
  v3 = 0;
  v4 = 0i64;
  if ( m_NumRanges <= 0 )
    return 0;
  p_m_pPointer = &this->mStateVariables.m_FormationSlot[0][0].m_pMember.m_pPointer;
  for ( i = this->m_NumSlotsPerRange; ; ++i )
  {
    v9 = *i;
    v10 = 0;
    v11 = 0i64;
    if ( v9 > 0 )
      break;
LABEL_11:
    ++v4;
    ++v3;
    p_m_pPointer += 200;
    if ( v4 >= m_NumRanges )
      return 0;
  }
  v12 = p_m_pPointer;
  while ( 1 )
  {
    v13 = *v12;
    if ( sim_object && v13 )
    {
      m_pPointer = (UFG::SimObject *)v13->m_pOwner.m_pPointer;
      if ( m_pPointer )
        m_pPointer = (UFG::SimObject *)m_pPointer->mNode.mParent;
      if ( m_pPointer == sim_object )
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
    this,
    v3,
    v10,
    this->mStateVariables.m_FormationSlot[0][v16].m_pMember.m_pPointer);
  this->mStateVariables.m_FormationSlot[0][v16].m_InPosition = eNOT_IN_POSITION;
  return 1;
}

// File Line: 3173
// RVA: 0x35FFD0
__int64 __fastcall UFG::FormationManagerComponent::GetInPositionType(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation)
{
  __int64 m_RangeIndex; // r10
  __int64 m_SlotIndex; // r9

  if ( !get_in_formation )
    return 2i64;
  m_RangeIndex = get_in_formation->m_RangeIndex;
  m_SlotIndex = get_in_formation->m_SlotIndex;
  if ( (_DWORD)m_RangeIndex == -1
    || (_DWORD)m_SlotIndex == -1
    || this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer != get_in_formation )
  {
    return 2i64;
  }
  else
  {
    return (unsigned int)this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_InPosition;
  }
}

// File Line: 3191
// RVA: 0x3867B0
void __fastcall UFG::FormationManagerComponent::SetInPositionType(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation,
        __int32 in_position)
{
  __int64 m_RangeIndex; // r11
  __int64 m_SlotIndex; // r10

  if ( get_in_formation )
  {
    m_RangeIndex = get_in_formation->m_RangeIndex;
    m_SlotIndex = get_in_formation->m_SlotIndex;
    if ( (_DWORD)m_RangeIndex != -1
      && (_DWORD)m_SlotIndex != -1
      && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == get_in_formation )
    {
      UFG::FormationSlot::SetInPosition(&this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex], in_position);
    }
  }
}

// File Line: 3204
// RVA: 0x35D9D0
char __fastcall UFG::FormationManagerComponent::GetDesiredPosition(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation,
        UFG::qVector3 *desired_position)
{
  __int64 m_RangeIndex; // rcx
  __int64 m_SlotIndex; // rax
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pSimComponent; // rbp
  __int64 v11; // rdx
  float z; // xmm2_4
  float y; // xmm1_4
  float v14; // xmm0_4
  UFG::SimComponent *v15; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  UFG::CombatRegion *vecDelDtor; // rcx
  UFG::SimComponent *v19; // rax
  UFG::SimObject *v20; // rcx
  float v21; // xmm0_4
  float v22; // xmm1_4

  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0;
  if ( !get_in_formation )
    return 0;
  m_RangeIndex = get_in_formation->m_RangeIndex;
  m_SlotIndex = get_in_formation->m_SlotIndex;
  if ( (_DWORD)m_RangeIndex == -1 )
    return 0;
  if ( (_DWORD)m_SlotIndex == -1 )
    return 0;
  if ( this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer != get_in_formation )
    return 0;
  m_pPointer = get_in_formation->m_pOwner.m_pPointer;
  if ( !m_pPointer )
    return 0;
  if ( !m_pPointer[2].vfptr )
    return 0;
  m_pSimObject = m_pPointer->m_pSimObject;
  if ( !m_pSimObject || !m_pSimObject->m_pTransformNodeComponent )
    return 0;
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  v11 = get_in_formation->m_SlotIndex + 8i64 * get_in_formation->m_RangeIndex;
  if ( this->mStateVariables.m_FormationSlot[0][v11].m_UseAbsolutePosition )
  {
    z = this->mStateVariables.m_FormationSlot[0][v11].m_AbsolutePosition.z;
    y = this->mStateVariables.m_FormationSlot[0][v11].m_AbsolutePosition.y;
    desired_position->x = this->mStateVariables.m_FormationSlot[0][v11].m_AbsolutePosition.x;
    desired_position->z = z;
  }
  else
  {
    v14 = this->mStateVariables.m_FormationSlot[0][v11].m_Direction.z + m_pSimComponent->mWorldTransform.v3.z;
    y = this->mStateVariables.m_FormationSlot[0][v11].m_Direction.y + m_pSimComponent->mWorldTransform.v3.y;
    desired_position->x = this->mStateVariables.m_FormationSlot[0][v11].m_Direction.x
                        + m_pSimComponent->mWorldTransform.v3.x;
    desired_position->z = v14;
  }
  desired_position->y = y;
  v15 = get_in_formation->m_pOwner.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( v15 )
    vfptr = v15[2].vfptr;
  else
    vfptr = 0i64;
  vecDelDtor = (UFG::CombatRegion *)vfptr[123].__vecDelDtor;
  if ( vecDelDtor && !UFG::CombatRegion::IsHitPoint(vecDelDtor, desired_position) )
  {
    v19 = get_in_formation->m_pOwner.m_pPointer;
    if ( v19 )
    {
      v20 = v19->m_pSimObject;
      if ( v20 )
        m_pTransformNodeComponent = v20->m_pTransformNodeComponent;
    }
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v21 = m_pTransformNodeComponent->mWorldTransform.v3.y;
    v22 = m_pTransformNodeComponent->mWorldTransform.v3.z;
    desired_position->x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    desired_position->y = v21;
    desired_position->z = v22;
  }
  return 1;
}

// File Line: 3242
// RVA: 0x35E300
bool __fastcall UFG::FormationManagerComponent::GetDesiredSpeed(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation,
        UFG::eMoveType *move_type)
{
  __int64 m_RangeIndex; // r10
  __int64 m_SlotIndex; // r11
  __int64 v5; // rdx
  UFG::eInFormationPositionType m_InPosition; // eax

  if ( !get_in_formation
    || (m_RangeIndex = get_in_formation->m_RangeIndex,
        m_SlotIndex = get_in_formation->m_SlotIndex,
        (_DWORD)m_RangeIndex == -1)
    || (_DWORD)m_SlotIndex == -1
    || this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer != get_in_formation )
  {
    LOBYTE(m_InPosition) = 0;
  }
  else
  {
    v5 = m_SlotIndex + 8 * m_RangeIndex;
    m_InPosition = this->mStateVariables.m_FormationSlot[0][v5].m_InPosition;
    if ( m_InPosition == eFAR_FROM_POSITION )
    {
      *move_type = eMoveType_Run;
      LOBYTE(m_InPosition) = 1;
    }
    else if ( m_InPosition == eCLOSE_TO_POSITION )
    {
      *move_type = eMoveType_Walk;
    }
    else
    {
      if ( (_DWORD)m_RangeIndex )
        *move_type = this->mStateVariables.m_FormationSlot[0][v5].m_DesiredSpeed;
      else
        *move_type = eMoveType_Jog;
      LOBYTE(m_InPosition) = 1;
    }
  }
  return m_InPosition;
}

// File Line: 3340
// RVA: 0x36ACF0
bool __fastcall UFG::FormationManagerComponent::IsInFormation(
        UFG::FormationManagerComponent *this,
        UFG::GetInFormationNode *get_in_formation)
{
  __int64 m_RangeIndex; // r10
  __int64 m_SlotIndex; // r9
  __int64 v4; // rbx
  bool result; // al

  result = 0;
  if ( get_in_formation )
  {
    m_RangeIndex = get_in_formation->m_RangeIndex;
    m_SlotIndex = get_in_formation->m_SlotIndex;
    if ( (_DWORD)m_RangeIndex != -1
      && (_DWORD)m_SlotIndex != -1
      && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == get_in_formation )
    {
      v4 = m_SlotIndex + 8 * m_RangeIndex;
      if ( this->mStateVariables.m_FormationSlot[0][v4].m_InPosition == eIN_POSITION
        && this->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == get_in_formation
        && this->mStateVariables.m_FormationSlot[0][v4].m_CurrentlyFacingCorrectly )
      {
        return 1;
      }
    }
  }
  return result;
}

// File Line: 3358
// RVA: 0x3778C0
__int64 __fastcall UFG::FormationManagerComponent::NumAttackersCloserThan(
        UFG::FormationManagerComponent *this,
        float distance,
        int stopCount)
{
  UFG::FormationManagerComponent *v3; // rbx
  UFG::TransformNodeComponent *m_pSimComponent; // rcx
  unsigned int v5; // r15d
  int v6; // esi
  int v7; // ecx
  __int64 v8; // rdi
  __int64 v9; // r13
  UFG::SimObject **p_m_pPointer; // rax
  int *m_NumSlotsPerRange; // r12
  int v12; // ebp
  UFG::SimObject **v13; // r14
  UFG::SimObject *v14; // rbx
  UFG::TransformNodeComponent *ComponentOfType; // rax
  float *v16; // rsi
  UFG::SimComponent *v17; // rsi
  UFG::SimComponent *v18; // rax
  __int64 v19; // rax
  UFG::SimObject **v21; // [rsp+20h] [rbp-88h]
  float *v22; // [rsp+28h] [rbp-80h]
  __int64 v23[6]; // [rsp+30h] [rbp-78h]
  unsigned int v25; // [rsp+C0h] [rbp+18h]
  int v26; // [rsp+C8h] [rbp+20h]

  v3 = this;
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v5 = 0;
  v6 = stopCount;
  v22 = (float *)m_pSimComponent;
  if ( !m_pSimComponent )
    return v5;
  if ( stopCount >= 5 )
    v6 = 5;
  v25 = v6;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  v7 = 0;
  v8 = 0i64;
  v26 = 0;
  v9 = v6;
  if ( v3->m_NumRanges <= 0 )
    return v5;
  p_m_pPointer = &v3->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  m_NumSlotsPerRange = v3->m_NumSlotsPerRange;
  v21 = &v3->mStateVariables.m_FormationSlot[0][0].m_pMemberSimObject.m_pPointer;
  while ( 1 )
  {
    v12 = 0;
    if ( *m_NumSlotsPerRange > 0 )
      break;
LABEL_21:
    ++v7;
    p_m_pPointer += 200;
    ++m_NumSlotsPerRange;
    v26 = v7;
    v21 = p_m_pPointer;
    if ( v7 >= v3->m_NumRanges )
      return v5;
  }
  v13 = p_m_pPointer;
  while ( 1 )
  {
    v14 = *v13;
    if ( *v13 )
    {
      ComponentOfType = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                                         *v13,
                                                         UFG::TransformNodeComponent::_TypeUID);
      v16 = (float *)ComponentOfType;
      if ( ComponentOfType )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(ComponentOfType);
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
    if ( v12 >= *m_NumSlotsPerRange )
    {
      p_m_pPointer = v21;
      v7 = v26;
      v3 = this;
      goto LABEL_21;
    }
  }
}

// File Line: 3464
// RVA: 0x360C30
float __fastcall UFG::FormationManagerComponent::GetMaxDistanceForRange(
        UFG::FormationManagerComponent *this,
        int range_index)
{
  __int64 m_CurrentBattleType; // r8
  float result; // xmm0_4

  m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
  if ( range_index < 0 || (_DWORD)m_CurrentBattleType == -1 )
    return 0.0;
  result = this->mStateVariables.m_pCurrentProfile->m_MaxDistanceOverride[range_index];
  if ( result < 0.0 )
    return this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxDistance[range_index];
  return result;
}

// File Line: 3488
// RVA: 0x3541A0
void __fastcall UFG::FormationManagerComponent::DrawDebugInfo(UFG::FormationManagerComponent *this, Render::View *view)
{
  UFG::SimComponent *m_pSimComponent; // r12
  __int64 v4; // r13
  float *p_y; // rbx
  __int64 v6; // rcx
  int *m_NumSlotsPerRange; // r14
  __int64 m_CurrentBattleType; // rdx
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  Render::DebugDrawContext *Context; // rax
  int v13; // esi
  __int64 v14; // rax
  __int64 v15; // rdi
  float x; // xmm7_4
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
  UFG::qColour v29; // xmm0
  Render::DebugDrawContext *v30; // rax
  bool v31; // cc
  __int64 v32; // [rsp+40h] [rbp-B0h]
  float *v33; // [rsp+48h] [rbp-A8h]
  UFG::qVector3 v34; // [rsp+50h] [rbp-A0h] BYREF
  UFG::qVector3 point; // [rsp+60h] [rbp-90h] BYREF
  UFG::qVector3 centre; // [rsp+70h] [rbp-80h] BYREF
  UFG::qVector3 p0; // [rsp+80h] [rbp-70h] BYREF
  UFG::qVector3 p1; // [rsp+90h] [rbp-60h] BYREF
  UFG::qVector3 v39; // [rsp+A0h] [rbp-50h] BYREF
  __int64 v40; // [rsp+B0h] [rbp-40h]
  UFG::qColour colour; // [rsp+C0h] [rbp-30h] BYREF
  UFG::qColour v42; // [rsp+D0h] [rbp-20h] BYREF
  UFG::qColour v43; // [rsp+E0h] [rbp-10h] BYREF
  UFG::qColour v44; // [rsp+F0h] [rbp+0h] BYREF
  int vars0; // [rsp+190h] [rbp+A0h]
  float current_lateral_offset; // [rsp+1A0h] [rbp+B0h] BYREF
  float current_radial_offset; // [rsp+1A8h] [rbp+B8h] BYREF

  if ( this->m_DebugDrawEnabled )
  {
    if ( this->m_pTransformNodeComponent.m_pSimComponent )
    {
      m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
      v4 = 0i64;
      vars0 = 0;
      v32 = 0i64;
      if ( this->m_NumRanges > 0 )
      {
        p_y = &this->mStateVariables.m_FormationSlot[0][0].m_Direction.y;
        v6 = -312i64 - (_QWORD)this;
        m_NumSlotsPerRange = this->m_NumSlotsPerRange;
        v33 = &this->mStateVariables.m_FormationSlot[0][0].m_Direction.y;
        v40 = -312i64 - (_QWORD)this;
        do
        {
          m_CurrentBattleType = UFG::BattleManager::s_pInstance->m_CurrentBattleType;
          colour = UFG::qColour::Red;
          if ( v4 < 0 || (_DWORD)m_CurrentBattleType == -1 )
          {
            v9 = 0.0;
          }
          else
          {
            v9 = *(float *)((char *)&this->mStateVariables.m_pCurrentProfile->m_NameID.mUID
                          + v6
                          + (unsigned __int64)m_NumSlotsPerRange);
            if ( v9 < 0.0 )
              v9 = this->m_BattleTypeSpecificParameters[m_CurrentBattleType].m_MaxDistance[v4];
          }
          v10 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
          centre.x = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
          v11 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
          centre.y = v10;
          centre.z = v11 + 0.25;
          Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                  Render::DebugDrawManager::mInstance,
                                                  1u);
          Render::DebugDrawContext::DrawCircle(Context, &centre, v9, &colour, &UFG::qMatrix44::msIdentity, 0i64);
          v13 = 0;
          if ( *m_NumSlotsPerRange > 0 )
          {
            do
            {
              v14 = *(_QWORD *)(p_y + 21);
              if ( v14 )
                v15 = *(_QWORD *)(v14 + 88);
              else
                v15 = 0i64;
              if ( v14 && v15 )
              {
                v17 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1) + *p_y;
                v18 = p_y[1] + *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
                centre.x = *(p_y - 1) + *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
                x = centre.x;
                centre.y = v17;
                centre.z = v18;
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v15);
                v19 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
                v20 = v18 + 0.25;
                v43 = UFG::qColour::Green;
                v21 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
                p0.x = v19;
                p1.x = x;
                p0.y = v21;
                v22 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
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
                  &v43,
                  &UFG::qMatrix44::msIdentity,
                  (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
                  0);
                v24 = *(float *)(v15 + 176);
                v34.x = x;
                v42 = UFG::qColour::Red;
                v25 = *(float *)(v15 + 180);
                v39.x = v24;
                v34.y = v17;
                v39.y = v25;
                v26 = *(float *)(v15 + 184);
                v34.z = v20;
                v39.z = v26 + 0.25;
                v27 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                    Render::DebugDrawManager::mInstance,
                                                    1u);
                Render::DebugDrawContext::DrawLine(
                  v27,
                  &v39,
                  &v34,
                  &v42,
                  &UFG::qMatrix44::msIdentity,
                  (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
                  0);
                v28 = *((_DWORD *)p_y + 7);
                v29 = UFG::qColour::White;
                if ( v28 == 3 )
                {
                  v29 = UFG::qColour::Red;
                }
                else if ( !v28 )
                {
                  v29 = UFG::qColour::Blue;
                  if ( *((_BYTE *)p_y + 37) )
                    v29 = UFG::qColour::Green;
                }
                point.x = x;
                point.y = v17;
                point.z = v20;
                v44 = v29;
                v30 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                    Render::DebugDrawManager::mInstance,
                                                    1u);
                Render::DebugDrawContext::DrawPoint(v30, &point, &v44, &UFG::qMatrix44::msIdentity, 0i64);
                UFG::FormationManagerComponent::IsInPosition(
                  this,
                  (UFG::qVector3 *)(v15 + 176),
                  &centre,
                  *((float *)m_NumSlotsPerRange + 13),
                  *((float *)m_NumSlotsPerRange + 25),
                  &current_radial_offset,
                  &current_lateral_offset,
                  1);
              }
              ++v13;
              p_y += 50;
            }
            while ( v13 < *m_NumSlotsPerRange );
            v4 = v32;
            p_y = v33;
          }
          ++v4;
          p_y += 400;
          ++m_NumSlotsPerRange;
          v32 = v4;
          v31 = ++vars0 < this->m_NumRanges;
          v6 = v40;
          v33 = p_y;
        }
        while ( v31 );
      }
    }
  }
}          ++m_NumSl

