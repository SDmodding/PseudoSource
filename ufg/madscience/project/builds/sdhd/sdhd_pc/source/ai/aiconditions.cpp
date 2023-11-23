// File Line: 83
// RVA: 0x14AE580
__int64 dynamic_initializer_for__ReceivedScriptCommandCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ReceivedScriptCommandCondition", 0xFFFFFFFF);
  ReceivedScriptCommandCondition::sClassNameUID = result;
  return result;
}

// File Line: 86
// RVA: 0x331600
void __fastcall ReceivedScriptCommandCondition::ReceivedScriptCommandCondition(ReceivedScriptCommandCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ReceivedScriptCommandCondition::`vftable;
}

// File Line: 91
// RVA: 0x371D90
bool __fastcall ReceivedScriptCommandCondition::Match(
        ReceivedScriptCommandCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  return m_pComponent[1].m_TypeUID || HIDWORD(m_pComponent[1].m_SafePointerList.mNode.mNext);
}

// File Line: 116
// RVA: 0x14ADB20
__int64 dynamic_initializer_for__CollisionAvoidanceIsActiveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionAvoidanceIsActiveCondition", 0xFFFFFFFF);
  CollisionAvoidanceIsActiveCondition::sClassNameUID = result;
  return result;
}

// File Line: 119
// RVA: 0x32D2E0
void __fastcall CollisionAvoidanceIsActiveCondition::CollisionAvoidanceIsActiveCondition(
        CollisionAvoidanceIsActiveCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionAvoidanceIsActiveCondition::`vftable;
}

// File Line: 124
// RVA: 0x36F0E0
bool __fastcall CollisionAvoidanceIsActiveCondition::Match(
        CollisionAvoidanceIsActiveCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *v4; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    else
      v4 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              m_pPointer,
                                              UFG::ActiveAIEntityComponent::_TypeUID)
                                          : UFG::SimObject::GetComponentOfType(
                                              m_pPointer,
                                              UFG::ActiveAIEntityComponent::_TypeUID));
    if ( v4 )
      return 1;
  }
  return result;
}

// File Line: 154
// RVA: 0x14AE040
__int64 dynamic_initializer_for__HasRangedWeaponEquippedWithAmmoCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasRangedWeaponEquippedWithAmmoCondition", 0xFFFFFFFF);
  HasRangedWeaponEquippedWithAmmoCondition::sClassNameUID = result;
  return result;
}

// File Line: 157
// RVA: 0x32FAD0
void __fastcall HasRangedWeaponEquippedWithAmmoCondition::HasRangedWeaponEquippedWithAmmoCondition(
        HasRangedWeaponEquippedWithAmmoCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HasRangedWeaponEquippedWithAmmoCondition::`vftable;
}

// File Line: 162
// RVA: 0x370560
bool __fastcall HasRangedWeaponEquippedWithAmmoCondition::Match(
        HasRangedWeaponEquippedWithAmmoCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  UFG::TargetingSystemBaseComponent *ComponentOfTypeHK; // rax
  bool v7; // zf
  UFG::TargetingSystemBaseComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return UFG::HasRangedWeaponEquippedWithAmmo(0i64);
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    return UFG::HasRangedWeaponEquippedWithAmmo((UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent);
  if ( (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::TargetingSystemBaseComponent::_TypeUID;
LABEL_8:
    ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5);
    return UFG::HasRangedWeaponEquippedWithAmmo(ComponentOfTypeHK);
  }
  v7 = (m_Flags & 0x1000) == 0;
  v5 = UFG::TargetingSystemBaseComponent::_TypeUID;
  if ( !v7 )
    goto LABEL_8;
  ComponentOfType = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::TargetingSystemBaseComponent::_TypeUID);
  return UFG::HasRangedWeaponEquippedWithAmmo(ComponentOfType);
}

// File Line: 184
// RVA: 0x14ADFE0
__int64 dynamic_initializer_for__HasAnyDangerousEntitiesOrPointsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasAnyDangerousEntitiesOrPointsCondition", 0xFFFFFFFF);
  HasAnyDangerousEntitiesOrPointsCondition::sClassNameUID = result;
  return result;
}

// File Line: 187
// RVA: 0x32F740
void __fastcall HasAnyDangerousEntitiesOrPointsCondition::HasAnyDangerousEntitiesOrPointsCondition(
        HasAnyDangerousEntitiesOrPointsCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HasAnyDangerousEntitiesOrPointsCondition::`vftable;
}

// File Line: 192
// RVA: 0x3702D0
bool __fastcall HasAnyDangerousEntitiesOrPointsCondition::Match(
        HasAnyDangerousEntitiesOrPointsCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *v4; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    else
      v4 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              m_pPointer,
                                              UFG::ActiveAIEntityComponent::_TypeUID)
                                          : UFG::SimObject::GetComponentOfType(
                                              m_pPointer,
                                              UFG::ActiveAIEntityComponent::_TypeUID));
    if ( v4 && (int)v4->m_ThreatTargets.size > 0 )
      return 1;
  }
  return result;
}

// File Line: 218
// RVA: 0x14B6D80
__int64 dynamic_initializer_for__geAIStimulusTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&geAIStimulusTypeEnum, UFG::g_StimulusName, 116, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__geAIStimulusTypeEnum__);
}

// File Line: 219
// RVA: 0x14B6D50
__int64 dynamic_initializer_for__geAIStimulusHandlerTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &geAIStimulusHandlerTypeEnum,
    UFG::g_StimulusHandlerTypeName,
    3,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__geAIStimulusHandlerTypeEnum__);
}

// File Line: 221
// RVA: 0x14AE5A0
__int64 dynamic_initializer_for__ReceivedStimulusCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ReceivedStimulusCondition", 0xFFFFFFFF);
  ReceivedStimulusCondition::sClassNameUID = result;
  return result;
}

// File Line: 237
// RVA: 0x331630
void __fastcall ReceivedStimulusCondition::ReceivedStimulusCondition(ReceivedStimulusCondition *this)
{
  Condition::Condition(this);
  this->mPrev = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->mNext = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&ReceivedStimulusCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&ReceivedStimulusCondition::`vftable{for `IConditionInit};
  *(_DWORD *)&this->m_Stimulus.mValue = 1441792;
  *(_WORD *)&this->m_OnlyCareAboutStimuliFromFactionStandingType.mValue = 258;
  this->m_MyRoot.mOffset = 0i64;
  this->m_MinSecondsSinceReceived = 0.25;
  this->m_MaxSecondsSinceReceived = 0.25;
  *(_QWORD *)&this->m_SecondsSinceReceivedUID = 0i64;
  this->m_EnteredUID = 0;
}

// File Line: 252
// RVA: 0x33A4A0
void __fastcall ReceivedStimulusCondition::~ReceivedStimulusCondition(ReceivedStimulusCondition *this)
{
  UFG::qNode<IConditionInit,IConditionInit> *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mNext; // rax

  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&ReceivedStimulusCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&ReceivedStimulusCondition::`vftable{for `IConditionInit};
  v2 = &this->UFG::qNode<IConditionInit,IConditionInit>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 259
// RVA: 0x3836F0
void __fastcall ReceivedStimulusCondition::ResolveReferences(ReceivedStimulusCondition *this, ActionNode *action_node)
{
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  __int64 v6; // rax
  ActionNodeRoot *v7; // rax
  unsigned int ValueUID; // eax
  unsigned int m_StimulusProducerTargetUID; // ecx
  unsigned int v10; // eax
  unsigned int m_EnteredUID; // ecx
  fastdelegate::detail::GenericClass *RCX; // rax
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v13; // [rsp+20h] [rbp-18h] BYREF

  v4 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v4 )
    v6 = (char *)v4 - (char *)p_m_MyRoot;
  else
    v6 = 0i64;
  p_m_MyRoot->mOffset = v6;
  v7 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  ActionNodeRoot::AddToInitList(v7, &this->IConditionInit);
  ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(
               this->m_SecondsSinceReceivedUID,
               eACTION_TREE_MEMORY_ELEMENT_FLOAT);
  m_StimulusProducerTargetUID = this->m_StimulusProducerTargetUID;
  this->m_SecondsSinceReceivedUID = ValueUID;
  v10 = UFG::ActionTreeComponentBase::MakeValueUID(
          m_StimulusProducerTargetUID,
          eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  m_EnteredUID = this->m_EnteredUID;
  this->m_StimulusProducerTargetUID = v10;
  this->m_EnteredUID = UFG::ActionTreeComponentBase::MakeValueUID(m_EnteredUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  v13.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))ReceivedStimulusCondition::OnEnterCallback;
  v13.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  ActionNode::AddOnEnterCallback(action_node, &v13);
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v13.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))ReceivedStimulusCondition::OnExitCallback;
  v13.m_Closure.m_pthis = RCX;
  ActionNode::AddOnExitCallback(action_node, &v13);
}

// File Line: 285
// RVA: 0x3662B0
void __fastcall ReceivedStimulusCondition::Init(ReceivedStimulusCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  char v7; // cl
  __int64 v8; // rax
  char v9; // cl

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[11].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::StimulusReceiverComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::StimulusReceiverComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[11].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = (__int64)this->IConditionInit::vfptr & 0x3F;
      v8 = (__int64)LOBYTE(this->IConditionInit::vfptr) >> 6;
      if ( ((1i64 << v7) & *((_QWORD *)&m_pComponent[1].m_Flags + v8)) == 0 )
      {
        *((_QWORD *)&m_pComponent[1].m_Flags + v8) |= 1i64 << v7;
        ++LOBYTE(m_pComponent[16].m_Flags);
        v9 = UFG::StimulusReceiverComponent::s_MaxStimuliRegistered;
        if ( UFG::StimulusReceiverComponent::s_MaxStimuliRegistered <= SLOBYTE(m_pComponent[16].m_Flags) )
          v9 = m_pComponent[16].m_Flags;
        UFG::StimulusReceiverComponent::s_MaxStimuliRegistered = v9;
      }
    }
  }
}

// File Line: 305
// RVA: 0x3749B0
__int64 __fastcall ReceivedStimulusCondition::MatchTargetType(
        ReceivedStimulusCondition *this,
        ActionContext *action_context,
        UFG::SimObjectCVBase *stimulus_producer)
{
  UFG::SimObjectGame *v3; // rbx
  bool v6; // si
  UFG::SimObjectCharacterPropertiesComponent *v8; // rbp
  UFG::SimObjectCharacterPropertiesComponent *v9; // rdi
  signed __int16 m_Flags; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  __int16 v12; // cx
  UFG::InventoryItemComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *OwnerSimObject; // rax
  __int16 v15; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 v18; // dx
  UFG::SimComponent *v19; // r8
  UFG::SimComponent *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  UFG::SimObjectCVBase *v22; // rcx
  __int16 v23; // dx
  UFG::SimObjectCharacterPropertiesComponent *v24; // rax
  unsigned int v25; // edx
  bool v26; // zf
  __int64 m_eFactionClass; // rbx
  __int64 v28; // rdi

  v3 = stimulus_producer;
  v6 = 1;
  if ( !this->m_OnlyCareAboutStimuliFromTarget && !this->m_OnlyCareAboutStimuliFromFactionStanding )
    return 1i64;
  v8 = 0i64;
  if ( stimulus_producer )
  {
    m_Flags = stimulus_producer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(stimulus_producer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          stimulus_producer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          stimulus_producer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    v9 = ComponentOfTypeHK;
    if ( !ComponentOfTypeHK )
    {
      v12 = v3->m_Flags;
      if ( (v12 & 0x4000) == 0 && v12 >= 0 )
      {
        if ( (v12 & 0x2000) != 0 )
          m_pComponent = (UFG::InventoryItemComponent *)v3->m_Components.p[11].m_pComponent;
        else
          m_pComponent = (UFG::InventoryItemComponent *)((v12 & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v3,
                                                           UFG::InventoryItemComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           v3,
                                                           UFG::InventoryItemComponent::_TypeUID));
        if ( m_pComponent )
        {
          OwnerSimObject = (UFG::SimObjectCVBase *)UFG::InventoryItemComponent::GetOwnerSimObject(m_pComponent);
          v3 = OwnerSimObject;
          if ( OwnerSimObject )
          {
            v15 = OwnerSimObject->m_Flags;
            if ( (v15 & 0x4000) != 0 || v15 < 0 )
            {
              ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(OwnerSimObject);
            }
            else if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
            {
              ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                OwnerSimObject,
                                                                                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
            }
            else
            {
              ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                OwnerSimObject,
                                                                                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
            }
            v9 = ComponentOfType;
          }
        }
      }
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( this->m_OnlyCareAboutStimuliFromTarget )
  {
    if ( v9 )
    {
      m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
      v6 = 0;
      if ( m_pPointer )
      {
        v18 = m_pPointer->m_Flags;
        if ( (v18 & 0x4000) != 0 )
        {
          v19 = m_pPointer->m_Components.p[20].m_pComponent;
        }
        else if ( v18 >= 0 )
        {
          if ( (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
            v20 = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v20 = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
          v19 = v20;
        }
        else
        {
          v19 = m_pPointer->m_Components.p[20].m_pComponent;
        }
        if ( v19 )
        {
          v21 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)this->m_OnlyCareAboutStimuliFromTargetType.mValue
                                                            + *(_QWORD *)&v19[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v19[1].m_TypeUID
                                       + 40);
          if ( v21 )
            v6 = v21 == v3;
        }
      }
    }
  }
  if ( this->m_OnlyCareAboutStimuliFromFactionStanding && v9 && v6 )
  {
    v22 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( !v22 )
    {
LABEL_59:
      m_eFactionClass = v8->m_eFactionClass;
      v28 = v9->m_eFactionClass;
      return UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[m_eFactionClass][v28] == (unsigned __int8)this->m_OnlyCareAboutStimuliFromFactionStandingType.mValue;
    }
    v23 = v22->m_Flags;
    if ( (v23 & 0x4000) != 0 || v23 < 0 )
    {
      v24 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v22);
    }
    else
    {
      if ( (v23 & 0x2000) != 0 )
      {
        v25 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
      }
      else
      {
        v26 = (v23 & 0x1000) == 0;
        v25 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
        if ( v26 )
        {
          v24 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                v22,
                                                                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          goto LABEL_58;
        }
      }
      v24 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v22, v25);
    }
LABEL_58:
    v8 = v24;
    goto LABEL_59;
  }
  return v6;
}

// File Line: 378
// RVA: 0x371E30
_BOOL8 __fastcall ReceivedStimulusCondition::Match(ReceivedStimulusCondition *this, ActionContext *action_context)
{
  unsigned int m_MinSecondsSinceReceived_low; // xmm0_4
  char *v3; // rsi
  float mSimTime_Temp; // xmm8_4
  bool v7; // zf
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v9; // rdx
  char *v10; // rcx
  UFG::ActionTreeComponentBase *v11; // rcx
  unsigned int v12; // r9d
  float m_MaxSecondsSinceReceived; // xmm6_4
  float m_MinSecondsSinceReceived; // xmm7_4
  float v15; // xmm0_4
  __int64 v16; // rax
  UFG::ActionTreeComponentBase *v17; // rdx
  char *v18; // rcx
  UFG::ActionTreeComponentBase *v19; // rcx
  float v20; // xmm6_4
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v25; // xmm0_4
  UFG::SimObject *v26; // r14
  __int64 v27; // rax
  __int64 v28; // rax
  bool v29; // r15
  UFG::SimObject *v30; // r12
  UFG::SimObjectGame *v31; // rcx
  __int16 v32; // dx
  UFG::TargetingSystemBaseComponent *v33; // rdi
  UFG::SimComponent *v34; // rax
  __int64 v35; // rax
  UFG::ActionTreeComponentBase *v36; // rdx
  char *v37; // rcx
  UFG::ActionTreeComponentBase *v38; // rcx
  __int64 v39; // rax
  UFG::ActionTreeComponentBase *v40; // rdx
  UFG::ActionTreeComponentBase *v41; // rcx
  unsigned int v43; // [rsp+80h] [rbp+8h] BYREF
  unsigned int value_uid; // [rsp+88h] [rbp+10h] BYREF

  m_MinSecondsSinceReceived_low = LODWORD(this->m_MinSecondsSinceReceived);
  v3 = 0i64;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v7 = *(float *)&m_MinSecondsSinceReceived_low == this->m_MaxSecondsSinceReceived;
  value_uid = m_MinSecondsSinceReceived_low;
  if ( !v7 )
  {
    mOffset = this->m_MyRoot.mOffset;
    if ( mOffset )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v9 = 0i64;
    if ( mOffset )
      v10 = (char *)&this->m_MyRoot + mOffset;
    else
      v10 = 0i64;
    v11 = action_context->mActionTreeComponentBase[v10[236]];
    if ( !v11 )
      v11 = action_context->mActionTreeComponentBase[1];
    if ( !UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
            v11,
            v9,
            (ActionNodeRoot *)this->m_SecondsSinceReceivedUID,
            &value_uid) )
    {
      m_MaxSecondsSinceReceived = this->m_MaxSecondsSinceReceived;
      m_MinSecondsSinceReceived = this->m_MinSecondsSinceReceived;
      v15 = m_MaxSecondsSinceReceived;
      if ( m_MaxSecondsSinceReceived > m_MinSecondsSinceReceived )
      {
        v15 = UFG::qRandom(m_MaxSecondsSinceReceived - m_MinSecondsSinceReceived, (unsigned int *)&UFG::qDefaultSeed)
            + m_MinSecondsSinceReceived;
        if ( v15 <= m_MinSecondsSinceReceived )
          v15 = m_MinSecondsSinceReceived;
        if ( v15 >= m_MaxSecondsSinceReceived )
          v15 = m_MaxSecondsSinceReceived;
      }
      v16 = this->m_MyRoot.mOffset;
      value_uid = LODWORD(v15);
      if ( v16 )
        v17 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v16);
      else
        v17 = 0i64;
      if ( v16 )
        v18 = (char *)&this->m_MyRoot + v16;
      else
        v18 = 0i64;
      v19 = action_context->mActionTreeComponentBase[v18[236]];
      if ( !v19 )
        v19 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
        v19,
        v17,
        (ActionNodeRoot *)this->m_SecondsSinceReceivedUID,
        v12);
    }
    m_MinSecondsSinceReceived_low = value_uid;
  }
  v20 = *((float *)&unk_1423BF9D4 + 18 * (unsigned __int8)this->m_Stimulus.mValue) * 2.0;
  if ( v20 <= *(float *)&m_MinSecondsSinceReceived_low )
    v20 = *(float *)&m_MinSecondsSinceReceived_low;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[11].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::StimulusReceiverComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::StimulusReceiverComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[11].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v25 = FLOAT_N99999_0;
  v26 = 0i64;
  if ( m_pComponent )
  {
    v27 = *((_QWORD *)&m_pComponent[1].m_BoundComponentHandles.mNode.mPrev + (unsigned __int8)this->m_Stimulus.mValue);
    if ( v27 )
    {
      v28 = v27 + 32;
      if ( v28 )
      {
        v25 = *(float *)v28;
        v26 = *(UFG::SimObject **)(v28 + 24);
      }
    }
  }
  v29 = (float)(mSimTime_Temp - v25) <= v20 && ReceivedStimulusCondition::MatchTargetType(this, action_context, v26);
  v30 = 0i64;
  if ( v29 )
  {
    v31 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    if ( v31 )
    {
      v32 = v31->m_Flags;
      if ( (v32 & 0x4000) != 0 )
      {
        v33 = (UFG::TargetingSystemBaseComponent *)v31->m_Components.p[20].m_pComponent;
      }
      else if ( v32 >= 0 )
      {
        v34 = (v32 & 0x2000) != 0 || (v32 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::TargetingSystemBaseComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v31, UFG::TargetingSystemBaseComponent::_TypeUID);
        v33 = (UFG::TargetingSystemBaseComponent *)v34;
      }
      else
      {
        v33 = (UFG::TargetingSystemBaseComponent *)v31->m_Components.p[20].m_pComponent;
      }
      if ( v33 )
      {
        if ( this->m_UpdateTargetAfterEntering )
        {
          v35 = this->m_MyRoot.mOffset;
          LOBYTE(v43) = 0;
          if ( v35 )
            v36 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v35);
          else
            v36 = 0i64;
          if ( v35 )
            v37 = (char *)&this->m_MyRoot + v35;
          else
            v37 = 0i64;
          v38 = action_context->mActionTreeComponentBase[v37[236]];
          if ( !v38 )
            v38 = action_context->mActionTreeComponentBase[1];
          UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
            v38,
            v36,
            (ActionNodeRoot *)this->m_EnteredUID,
            (bool *)&v43);
          if ( (_BYTE)v43 )
            UFG::TargetingSystemBaseComponent::SetTarget(v33, eTARGET_TYPE_STIMULUS_PRODUCER, v26);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(v33, eTARGET_TYPE_CONDITION_STIMULUS_PRODUCER, v26);
        v30 = v26;
      }
    }
  }
  v39 = this->m_MyRoot.mOffset;
  if ( v39 )
    v40 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v39);
  else
    v40 = 0i64;
  if ( v39 )
    v3 = (char *)&this->m_MyRoot + v39;
  v41 = action_context->mActionTreeComponentBase[v3[236]];
  if ( !v41 )
    v41 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
    v41,
    v40,
    (ActionNodeRoot *)this->m_StimulusProducerTargetUID,
    v30);
  return v29;
}

// File Line: 466
// RVA: 0x37B320
void __fastcall ReceivedStimulusCondition::OnEnterCallback(
        ReceivedStimulusCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  char *v5; // rdi
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rbx
  UFG::SimComponent *v9; // rax
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v11; // rdx
  char *v12; // rcx
  UFG::ActionTreeComponentBase *v13; // rcx
  __int64 v14; // rax
  UFG::ActionTreeComponentBase *v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  UFG::SimObject *value_uid; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v5 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v9 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = (UFG::TargetingSystemBaseComponent *)v9;
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      mOffset = this->m_MyRoot.mOffset;
      value_uid = 0i64;
      if ( mOffset )
        v11 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v11 = 0i64;
      if ( mOffset )
        v12 = (char *)&this->m_MyRoot + mOffset;
      else
        v12 = 0i64;
      v13 = action_context->mActionTreeComponentBase[v12[236]];
      if ( !v13 )
        v13 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
        v13,
        v11,
        (ActionNodeRoot *)this->m_StimulusProducerTargetUID,
        &value_uid);
      UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, eTARGET_TYPE_STIMULUS_PRODUCER, value_uid);
    }
  }
  v14 = this->m_MyRoot.mOffset;
  if ( v14 )
    v15 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v14);
  else
    v15 = 0i64;
  if ( v14 )
    v5 = (char *)&this->m_MyRoot + v14;
  v16 = action_context->mActionTreeComponentBase[v5[236]];
  if ( !v16 )
    v16 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v16, v15, (ActionNodeRoot *)this->m_EnteredUID, 1);
}

// File Line: 483
// RVA: 0x37B470
void __fastcall ReceivedStimulusCondition::OnExitCallback(
        ReceivedStimulusCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v4; // rdx
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx

  mOffset = this->m_MyRoot.mOffset;
  v4 = 0i64;
  if ( mOffset )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v6 = 0i64;
  if ( mOffset )
    v4 = (char *)&this->m_MyRoot + mOffset;
  v7 = action_context->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v7, v6, (ActionNodeRoot *)this->m_EnteredUID, 0);
}

// File Line: 517
// RVA: 0x14AE560
__int64 dynamic_initializer_for__ReceivedHeatEventCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ReceivedHeatEventCondition", 0xFFFFFFFF);
  ReceivedHeatEventCondition::sClassNameUID = result;
  return result;
}

// File Line: 523
// RVA: 0x3315C0
void __fastcall ReceivedHeatEventCondition::ReceivedHeatEventCondition(ReceivedHeatEventCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ReceivedHeatEventCondition::`vftable;
  this->m_HeatEvent.mValue = 0;
}

// File Line: 528
// RVA: 0x33A460
void __fastcall ReceivedHeatEventCondition::~ReceivedHeatEventCondition(ReceivedHeatEventCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&ReceivedHeatEventCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 535
// RVA: 0x371D60
bool __fastcall ReceivedHeatEventCondition::Match(ReceivedHeatEventCondition *this, ActionContext *action_context)
{
  UFG::CopSystem *v3; // rax

  v3 = UFG::CopSystem::Instance();
  LODWORD(this) = (unsigned __int8)this->m_HeatEvent.mValue;
  return ((unsigned int (__fastcall *)(UFG::CopSystem *))v3->vfptr[107].__vecDelDtor)(v3) == (_DWORD)this;
}

// File Line: 554
// RVA: 0x14AD8E0
__int64 dynamic_initializer_for__AIPlayerInsideAIMeshHeuristicCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIPlayerInsideAIMeshHeuristicCondition", 0xFFFFFFFF);
  AIPlayerInsideAIMeshHeuristicCondition::sClassNameUID = result;
  return result;
}

// File Line: 557
// RVA: 0x32BB50
void __fastcall AIPlayerInsideAIMeshHeuristicCondition::AIPlayerInsideAIMeshHeuristicCondition(
        AIPlayerInsideAIMeshHeuristicCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIPlayerInsideAIMeshHeuristicCondition::`vftable;
}

// File Line: 561
// RVA: 0x36ED80
__int64 __fastcall AIPlayerInsideAIMeshHeuristicCondition::Match(
        AIPlayerInsideAIMeshHeuristicCondition *this,
        ActionContext *action_context)
{
  UFG::CopSystem *v2; // rax

  v2 = UFG::CopSystem::Instance();
  return ((__int64 (__fastcall *)(UFG::CopSystem *))v2->vfptr[11].__vecDelDtor)(v2);
}

// File Line: 581
// RVA: 0x14AD520
__int64 dynamic_initializer_for__AICopAcquireArrestRightCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopAcquireArrestRightCondition", 0xFFFFFFFF);
  AICopAcquireArrestRightCondition::sClassNameUID = result;
  return result;
}

// File Line: 584
// RVA: 0x32AB10
void __fastcall AICopAcquireArrestRightCondition::AICopAcquireArrestRightCondition(
        AICopAcquireArrestRightCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopAcquireArrestRightCondition::`vftable;
}

// File Line: 588
// RVA: 0x36DEA0
__int64 __fastcall AICopAcquireArrestRightCondition::Match(
        AICopAcquireArrestRightCondition *this,
        ActionContext *action_context)
{
  UFG::CopSystem *v3; // rax

  v3 = UFG::CopSystem::Instance();
  return (__int64)v3->vfptr[104].__vecDelDtor(v3, (unsigned int)action_context->mSimObject.m_pPointer);
}

// File Line: 607
// RVA: 0x14AD640
__int64 dynamic_initializer_for__AICopPlayerInsideUnlockedSafehouseCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopPlayerInsideUnlockedSafehouseCondition", 0xFFFFFFFF);
  AICopPlayerInsideUnlockedSafehouseCondition::sClassNameUID = result;
  return result;
}

// File Line: 610
// RVA: 0x32AD00
void __fastcall AICopPlayerInsideUnlockedSafehouseCondition::AICopPlayerInsideUnlockedSafehouseCondition(
        AICopPlayerInsideUnlockedSafehouseCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopPlayerInsideUnlockedSafehouseCondition::`vftable;
}

// File Line: 614
// RVA: 0x36E000
UFG::UIHKScreenHud *__fastcall AICopPlayerInsideUnlockedSafehouseCondition::Match(
        AICopPlayerInsideUnlockedSafehouseCondition *this,
        ActionContext *action_context)
{
  UFG::CopSystem *v2; // rax

  v2 = UFG::CopSystem::Instance();
  return UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(v2, 0i64);
}

// File Line: 633
// RVA: 0x14AD620
__int64 dynamic_initializer_for__AICopOnFootNoSprintCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopOnFootNoSprintCondition", 0xFFFFFFFF);
  AICopOnFootNoSprintCondition::sClassNameUID = result;
  return result;
}

// File Line: 636
// RVA: 0x32ACD0
void __fastcall AICopOnFootNoSprintCondition::AICopOnFootNoSprintCondition(AICopOnFootNoSprintCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopOnFootNoSprintCondition::`vftable;
}

// File Line: 640
// RVA: 0x36DFE0
char __fastcall AICopOnFootNoSprintCondition::Match(AICopOnFootNoSprintCondition *this, ActionContext *action_context)
{
  UFG::CopSystem *v2; // rax

  v2 = UFG::CopSystem::Instance();
  return UFG::CopSystem::IsOnFootNoSprintActive(v2);
}

// File Line: 659
// RVA: 0x14AD5A0
__int64 dynamic_initializer_for__AICopIsSoloOnSceneCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopIsSoloOnSceneCondition", 0xFFFFFFFF);
  AICopIsSoloOnSceneCondition::sClassNameUID = result;
  return result;
}

// File Line: 662
// RVA: 0x32AC00
void __fastcall AICopIsSoloOnSceneCondition::AICopIsSoloOnSceneCondition(AICopIsSoloOnSceneCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopIsSoloOnSceneCondition::`vftable;
}

// File Line: 666
// RVA: 0x36DF30
__int64 __fastcall AICopIsSoloOnSceneCondition::Match(AICopIsSoloOnSceneCondition *this, ActionContext *action_context)
{
  UFG::CopSystem *v3; // rax

  v3 = UFG::CopSystem::Instance();
  return (__int64)v3->vfptr[106].__vecDelDtor(v3, (unsigned int)action_context->mSimObject.m_pPointer);
}

// File Line: 685
// RVA: 0x14AD600
__int64 dynamic_initializer_for__AICopNumArrestAttemptCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopNumArrestAttemptCondition", 0xFFFFFFFF);
  AICopNumArrestAttemptCondition::sClassNameUID = result;
  return result;
}

// File Line: 693
// RVA: 0x32AC90
void __fastcall AICopNumArrestAttemptCondition::AICopNumArrestAttemptCondition(AICopNumArrestAttemptCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopNumArrestAttemptCondition::`vftable;
  this->m_InEqualityOperator.mValue = 4;
  this->m_NumAttempts = 0;
}

// File Line: 698
// RVA: 0x36DFA0
bool __fastcall AICopNumArrestAttemptCondition::Match(
        AICopNumArrestAttemptCondition *this,
        ActionContext *action_context)
{
  UFG::CopSystem *v3; // rax
  UFG::InEqualityOperator mValue; // ebx
  int v5; // eax

  v3 = UFG::CopSystem::Instance();
  mValue = (unsigned __int8)this->m_InEqualityOperator.mValue;
  v5 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[91].__vecDelDtor)(v3);
  return CompareInt(mValue, this->m_NumAttempts, v5);
}

// File Line: 718
// RVA: 0x14AD5E0
__int64 dynamic_initializer_for__AICopIsSuspectInsideInteriorCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopIsSuspectInsideInteriorCondition", 0xFFFFFFFF);
  AICopIsSuspectInsideInteriorCondition::sClassNameUID = result;
  return result;
}

// File Line: 721
// RVA: 0x32AC60
void __fastcall AICopIsSuspectInsideInteriorCondition::AICopIsSuspectInsideInteriorCondition(
        AICopIsSuspectInsideInteriorCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopIsSuspectInsideInteriorCondition::`vftable;
}

// File Line: 725
// RVA: 0x36DF80
__int64 __fastcall AICopIsSuspectInsideInteriorCondition::Match(
        AICopIsSuspectInsideInteriorCondition *this,
        ActionContext *action_context)
{
  UFG::CopSystem *v2; // rax

  v2 = UFG::CopSystem::Instance();
  return ((__int64 (__fastcall *)(UFG::CopSystem *))v2->vfptr[12].__vecDelDtor)(v2);
}

// File Line: 743
// RVA: 0x14AD5C0
__int64 dynamic_initializer_for__AICopIsSuspectInWaterCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopIsSuspectInWaterCondition", 0xFFFFFFFF);
  AICopIsSuspectInWaterCondition::sClassNameUID = result;
  return result;
}

// File Line: 746
// RVA: 0x32AC30
void __fastcall AICopIsSuspectInWaterCondition::AICopIsSuspectInWaterCondition(AICopIsSuspectInWaterCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopIsSuspectInWaterCondition::`vftable;
}

// File Line: 750
// RVA: 0x36DF60
__int64 __fastcall AICopIsSuspectInWaterCondition::Match(
        AICopIsSuspectInWaterCondition *this,
        ActionContext *action_context)
{
  UFG::CopSystem *v2; // rax

  v2 = UFG::CopSystem::Instance();
  return ((__int64 (__fastcall *)(UFG::CopSystem *))v2->vfptr[13].__vecDelDtor)(v2);
}

// File Line: 768
// RVA: 0x14AD560
__int64 dynamic_initializer_for__AICopHasSuspectOpenedFiredCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopHasSuspectOpenedFiredCondition", 0xFFFFFFFF);
  AICopHasSuspectOpenedFiredCondition::sClassNameUID = result;
  return result;
}

// File Line: 774
// RVA: 0x32AB90
void __fastcall AICopHasSuspectOpenedFiredCondition::AICopHasSuspectOpenedFiredCondition(
        AICopHasSuspectOpenedFiredCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopHasSuspectOpenedFiredCondition::`vftable;
  this->m_OpenFiredContext.mValue = 0;
}

// File Line: 778
// RVA: 0x36DED0
__int64 __fastcall AICopHasSuspectOpenedFiredCondition::Match(
        AICopHasSuspectOpenedFiredCondition *this,
        ActionContext *action_context)
{
  UFG::CopSystem *v2; // rax
  UFG::CopSystem *v4; // rax

  if ( this->m_OpenFiredContext.mValue == 1 )
  {
    v2 = UFG::CopSystem::Instance();
    return ((__int64 (__fastcall *)(UFG::CopSystem *))v2->vfptr[15].__vecDelDtor)(v2);
  }
  else
  {
    v4 = UFG::CopSystem::Instance();
    return ((__int64 (__fastcall *)(UFG::CopSystem *))v4->vfptr[14].__vecDelDtor)(v4);
  }
}

// File Line: 806
// RVA: 0x14AD580
__int64 dynamic_initializer_for__AICopHasVehicleToDefendCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopHasVehicleToDefendCondition", 0xFFFFFFFF);
  AICopHasVehicleToDefendCondition::sClassNameUID = result;
  return result;
}

// File Line: 809
// RVA: 0x32ABD0
void __fastcall AICopHasVehicleToDefendCondition::AICopHasVehicleToDefendCondition(
        AICopHasVehicleToDefendCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopHasVehicleToDefendCondition::`vftable;
}

// File Line: 813
// RVA: 0x36DF00
bool __fastcall AICopHasVehicleToDefendCondition::Match(
        AICopHasVehicleToDefendCondition *this,
        ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx
  bool result; // al

  m_pPointer = action_context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[16].m_pComponent;
    if ( m_pComponent )
    {
      if ( m_pComponent[2].m_BoundComponentHandles.mNode.mPrev )
        return 1;
    }
  }
  return result;
}

// File Line: 840
// RVA: 0x14B2F50
__int64 dynamic_initializer_for__gEncounterUnitRoleTypeNames__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gEncounterUnitRoleTypeNames,
    UFG::EncounterUnitRoleTypeNames,
    3,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gEncounterUnitRoleTypeNames__);
}

// File Line: 842
// RVA: 0x14AD7A0
__int64 dynamic_initializer_for__AIEncounterRoleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIEncounterRoleCondition", 0xFFFFFFFF);
  AIEncounterRoleCondition::sClassNameUID = result;
  return result;
}

// File Line: 847
// RVA: 0x32B400
void __fastcall AIEncounterRoleCondition::AIEncounterRoleCondition(AIEncounterRoleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIEncounterRoleCondition::`vftable;
  this->mRole.mValue = 0;
}

// File Line: 851
// RVA: 0x36E500
bool __fastcall AIEncounterRoleCondition::Match(AIEncounterRoleCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::EncounterUnitComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::EncounterUnitComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[16].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[16].m_pComponent),
            m_pComponent)
        && LODWORD(m_pComponent[1].vfptr) == (unsigned __int8)this->mRole.mValue;
  return result;
}

// File Line: 876
// RVA: 0x14AD7C0
__int64 dynamic_initializer_for__AIEncounterUnitGotStuckCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIEncounterUnitGotStuckCondition", 0xFFFFFFFF);
  AIEncounterUnitGotStuckCondition::sClassNameUID = result;
  return result;
}

// File Line: 879
// RVA: 0x32B440
void __fastcall AIEncounterUnitGotStuckCondition::AIEncounterUnitGotStuckCondition(
        AIEncounterUnitGotStuckCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIEncounterUnitGotStuckCondition::`vftable;
}

// File Line: 883
// RVA: 0x36E5A0
bool __fastcall AIEncounterUnitGotStuckCondition::Match(
        AIEncounterUnitGotStuckCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[16].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::EncounterUnitComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::EncounterUnitComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[16].m_pComponent;
    }
    if ( m_pComponent && HIBYTE(m_pComponent[2].m_SafePointerList.mNode.mPrev) )
      return 1;
    v7 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v7 )
    {
      v8 = v7->m_Flags;
      if ( (v8 & 0x4000) != 0 || v8 < 0 )
        v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
      else
        v9 = (UFG::AiDriverComponent *)((v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AiDriverComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(v7, UFG::AiDriverComponent::_TypeUID));
      if ( v9 && UFG::AiDriverComponent::GetUnstuckFailed(v9) )
        return 1;
    }
  }
  return result;
}

// File Line: 918
// RVA: 0x14ADAE0
__int64 dynamic_initializer_for__CanBeginSinglePersonConversationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CanBeginSinglePersonConversationCondition", 0xFFFFFFFF);
  CanBeginSinglePersonConversationCondition::sClassNameUID = result;
  return result;
}

// File Line: 920
// RVA: 0x32CFD0
void __fastcall CanBeginSinglePersonConversationCondition::CanBeginSinglePersonConversationCondition(
        CanBeginSinglePersonConversationCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CanBeginSinglePersonConversationCondition::`vftable;
}

// File Line: 925
// RVA: 0x36F070
bool __fastcall CanBeginSinglePersonConversationCondition::Match(
        CanBeginSinglePersonConversationCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  bool v6; // zf

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
      return 0;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      v5 = UFG::ActiveAIEntityComponent::_TypeUID;
LABEL_7:
      UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5);
      return 0;
    }
    v6 = (m_Flags & 0x1000) == 0;
    v5 = UFG::ActiveAIEntityComponent::_TypeUID;
    if ( !v6 )
      goto LABEL_7;
    UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActiveAIEntityComponent::_TypeUID);
  }
  return 0;
}

// File Line: 958
// RVA: 0x14AE420
__int64 dynamic_initializer_for__OneShotCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("OneShotCondition", 0xFFFFFFFF);
  OneShotCondition::sClassNameUID = result;
  return result;
}

// File Line: 961
// RVA: 0x330BB0
void __fastcall OneShotCondition::OneShotCondition(OneShotCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&OneShotCondition::`vftable;
  this->m_HasFiredUID = 0;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 967
// RVA: 0x3834D0
void __fastcall OneShotCondition::ResolveReferences(OneShotCondition *this, ActionNode *action_node)
{
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  __int64 mOffset; // rax
  ActionNode *v7; // rcx
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v8; // [rsp+20h] [rbp-18h] BYREF

  v4 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v4;
  v8.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v8.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))OneShotCondition::OnMyEnterCallback;
  ActionNode::AddOnEnterCallback(action_node, &v8);
  mOffset = action_node->mParent.mOffset;
  if ( mOffset )
  {
    v7 = (ActionNode *)((char *)&action_node->mParent + mOffset);
    if ( v7 )
    {
      v8.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
      v8.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))_;
      ActionNode::AddOnExitCallback(v7, &v8);
    }
  }
  this->m_HasFiredUID = UFG::ActionTreeComponentBase::MakeValueUID(
                          this->m_HasFiredUID,
                          eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 992
// RVA: 0x37B610
void __fastcall OneShotCondition::OnMyEnterCallback(
        OneShotCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v4; // rdx
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx

  mOffset = this->m_MyRoot.mOffset;
  v4 = 0i64;
  if ( mOffset )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v6 = 0i64;
  if ( mOffset )
    v4 = (char *)&this->m_MyRoot + mOffset;
  v7 = action_context->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v7, v6, (ActionNodeRoot *)this->m_HasFiredUID, 1);
}

// File Line: 1006
// RVA: 0x371690
bool __fastcall OneShotCondition::Match(OneShotCondition *this, ActionContext *action_context)
{
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v4; // r10
  char *v5; // rcx
  UFG::ActionTreeComponentBase *v6; // rcx
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  LOBYTE(value_uid) = 0;
  if ( mOffset )
    v4 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v4 = 0i64;
  if ( mOffset )
    v5 = (char *)&this->m_MyRoot + mOffset;
  else
    v5 = 0i64;
  v6 = action_context->mActionTreeComponentBase[v5[236]];
  if ( !v6 )
    v6 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v6,
    v4,
    (ActionNodeRoot *)this->m_HasFiredUID,
    (bool *)&value_uid);
  return (_BYTE)value_uid == 0;
}

// File Line: 1033
// RVA: 0x14ADC60
__int64 dynamic_initializer_for__CooldownCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CooldownCondition", 0xFFFFFFFF);
  CooldownCondition::sClassNameUID = result;
  return result;
}

// File Line: 1039
// RVA: 0x32D560
void __fastcall CooldownCondition::CooldownCondition(CooldownCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CooldownCondition::`vftable;
  *(_QWORD *)&this->m_NextTimeCanEnterUID = 0i64;
  this->m_MaxTimeUntilCanEnterAgain = 0.0;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 1049
// RVA: 0x3830B0
void __fastcall CooldownCondition::ResolveReferences(CooldownCondition *this, ActionNode *action_node)
{
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v6; // [rsp+20h] [rbp-18h] BYREF

  v4 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v4;
  v6.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v6.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))CooldownCondition::OnMyExitCallback;
  ActionNode::AddOnExitCallback(action_node, &v6);
  this->m_NextTimeCanEnterUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                  this->m_NextTimeCanEnterUID,
                                  eACTION_TREE_MEMORY_ELEMENT_FLOAT);
}

// File Line: 1091
// RVA: 0x36F800
bool __fastcall CooldownCondition::Match(CooldownCondition *this, ActionContext *action_context)
{
  __int64 mOffset; // rax
  float mSimTime_Temp; // xmm6_4
  UFG::ActionTreeComponentBase *v5; // r10
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  unsigned int value_uid; // [rsp+40h] [rbp+8h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  *(float *)&value_uid = FLOAT_N99999_0;
  if ( mOffset )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v5 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->m_MyRoot + mOffset;
  else
    v6 = 0i64;
  v7 = action_context->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v7,
    v5,
    (ActionNodeRoot *)this->m_NextTimeCanEnterUID,
    &value_uid);
  return mSimTime_Temp >= *(float *)&value_uid;
}

// File Line: 1131
// RVA: 0x14B6DB0
__int64 dynamic_initializer_for__geCooldownTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&geCooldownTypeEnum, UFG::GlobalCooldownNames, 19, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__geCooldownTypeEnum__);
}

// File Line: 1133
// RVA: 0x14ADF40
__int64 dynamic_initializer_for__GlobalCooldownCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GlobalCooldownCondition", 0xFFFFFFFF);
  GlobalCooldownCondition::sClassNameUID = result;
  return result;
}

// File Line: 1141
// RVA: 0x32F2C0
void __fastcall GlobalCooldownCondition::GlobalCooldownCondition(GlobalCooldownCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&GlobalCooldownCondition::`vftable;
  this->m_CooldownType.mValue = 0;
  *(_QWORD *)&this->m_MinTimeUntilCanEnterAgain = 0i64;
}

// File Line: 1149
// RVA: 0x383340
void __fastcall GlobalCooldownCondition::ResolveReferences(GlobalCooldownCondition *this, ActionNode *action_node)
{
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v4; // [rsp+20h] [rbp-18h] BYREF

  v4.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v4.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))GlobalCooldownCondition::OnMyEnterCallback;
  ActionNode::AddOnEnterCallback(action_node, &v4);
  v4.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))GlobalCooldownCondition::OnMyExitCallback;
  v4.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  ActionNode::AddOnExitCallback(action_node, &v4);
}

// File Line: 1164
// RVA: 0x37B5C0
void __fastcall GlobalCooldownCondition::OnMyEnterCallback(
        GlobalCooldownCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  __int64 mValue; // rcx

  mValue = (unsigned __int8)this->m_CooldownType.mValue;
  UFG::GlobalCooldownManager::s_pInstance->m_LastTimeFired[mValue] = UFG::Metrics::msInstance.mSimTime_Temp;
  UFG::GlobalCooldownManager::s_pInstance->m_TimeUntilNextCanFire[mValue] = 9999.0;
}

// File Line: 1173
// RVA: 0x37B730
void __fastcall GlobalCooldownCondition::OnMyExitCallback(
        GlobalCooldownCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  UFG::GlobalCooldownManager::SetLastTimeFired(
    UFG::GlobalCooldownManager::s_pInstance,
    (UFG::eGlobalCooldownType)(unsigned __int8)this->m_CooldownType.mValue,
    this->m_MinTimeUntilCanEnterAgain,
    this->m_MaxTimeUntilCanEnterAgain);
}

// File Line: 1182
// RVA: 0x370180
bool __fastcall GlobalCooldownCondition::Match(GlobalCooldownCondition *this, ActionContext *action_context)
{
  return UFG::Metrics::msInstance.mSimTime_Temp >= (float)(UFG::GlobalCooldownManager::s_pInstance->m_TimeUntilNextCanFire[(unsigned __int8)this->m_CooldownType.mValue]
                                                         + UFG::GlobalCooldownManager::s_pInstance->m_LastTimeFired[(unsigned __int8)this->m_CooldownType.mValue]);
}

// File Line: 1207
// RVA: 0x14AE540
__int64 dynamic_initializer_for__RandomStartTimeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RandomStartTimeCondition", 0xFFFFFFFF);
  RandomStartTimeCondition::sClassNameUID = result;
  return result;
}

// File Line: 1213
// RVA: 0x331580
void __fastcall RandomStartTimeCondition::RandomStartTimeCondition(RandomStartTimeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&RandomStartTimeCondition::`vftable;
  *(_QWORD *)&this->m_TimeCanEnterUID = 0i64;
  *(_QWORD *)&this->m_MinTimeUntilCanEnter = 0i64;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 1224
// RVA: 0x383670
void __fastcall RandomStartTimeCondition::ResolveReferences(RandomStartTimeCondition *this, ActionNode *action_node)
{
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  unsigned int ValueUID; // eax
  unsigned int m_NeedToSetTimeCanEnterUID; // ecx
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v8; // [rsp+20h] [rbp-18h] BYREF

  v4 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v4;
  v8.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v8.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))RandomStartTimeCondition::OnMyExitCallback;
  ActionNode::AddOnExitCallback(action_node, &v8);
  ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(this->m_TimeCanEnterUID, eACTION_TREE_MEMORY_ELEMENT_FLOAT);
  m_NeedToSetTimeCanEnterUID = this->m_NeedToSetTimeCanEnterUID;
  this->m_TimeCanEnterUID = ValueUID;
  this->m_NeedToSetTimeCanEnterUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                       m_NeedToSetTimeCanEnterUID,
                                       eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 1242
// RVA: 0x37B9C0
void __fastcall RandomStartTimeCondition::OnMyExitCallback(
        RandomStartTimeCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v4; // rdx
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx

  mOffset = this->m_MyRoot.mOffset;
  v4 = 0i64;
  if ( mOffset )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v6 = 0i64;
  if ( mOffset )
    v4 = (char *)&this->m_MyRoot + mOffset;
  v7 = action_context->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v7, v6, (ActionNodeRoot *)this->m_NeedToSetTimeCanEnterUID, 1);
}

// File Line: 1251
// RVA: 0x371B80
bool __fastcall RandomStartTimeCondition::Match(RandomStartTimeCondition *this, ActionContext *action_context)
{
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v5; // rdx
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  unsigned int v8; // r9d
  float m_MaxTimeUntilCanEnter; // xmm6_4
  float m_MinTimeUntilCanEnter; // xmm7_4
  __int64 v11; // rax
  UFG::ActionTreeComponentBase *v12; // rdx
  char *v13; // rcx
  UFG::ActionTreeComponentBase *v14; // rcx
  __int64 v15; // rax
  UFG::ActionTreeComponentBase *v16; // rdx
  char *v17; // rcx
  UFG::ActionTreeComponentBase *v18; // rcx
  __int64 v19; // rax
  float mSimTime_Temp; // xmm6_4
  UFG::ActionTreeComponentBase *v21; // rdx
  char *v22; // rcx
  UFG::ActionTreeComponentBase *v23; // rcx
  unsigned int value_uid; // [rsp+60h] [rbp+8h] BYREF
  unsigned int v26; // [rsp+68h] [rbp+10h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  LOBYTE(value_uid) = 1;
  if ( mOffset )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v5 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->m_MyRoot + mOffset;
  else
    v6 = 0i64;
  v7 = action_context->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v7,
    v5,
    (ActionNodeRoot *)this->m_NeedToSetTimeCanEnterUID,
    (bool *)&value_uid);
  if ( (_BYTE)value_uid )
  {
    m_MaxTimeUntilCanEnter = this->m_MaxTimeUntilCanEnter;
    m_MinTimeUntilCanEnter = this->m_MinTimeUntilCanEnter;
    if ( m_MaxTimeUntilCanEnter > m_MinTimeUntilCanEnter )
      UFG::qRandom(m_MaxTimeUntilCanEnter - m_MinTimeUntilCanEnter, (unsigned int *)&UFG::qDefaultSeed);
    v11 = this->m_MyRoot.mOffset;
    if ( v11 )
      v12 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v11);
    else
      v12 = 0i64;
    if ( v11 )
      v13 = (char *)&this->m_MyRoot + v11;
    else
      v13 = 0i64;
    v14 = action_context->mActionTreeComponentBase[v13[236]];
    if ( !v14 )
      v14 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(v14, v12, (ActionNodeRoot *)this->m_TimeCanEnterUID, v8);
    v15 = this->m_MyRoot.mOffset;
    if ( v15 )
      v16 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v15);
    else
      v16 = 0i64;
    if ( v15 )
      v17 = (char *)&this->m_MyRoot + v15;
    else
      v17 = 0i64;
    v18 = action_context->mActionTreeComponentBase[v17[236]];
    if ( !v18 )
      v18 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v18,
      v16,
      (ActionNodeRoot *)this->m_NeedToSetTimeCanEnterUID,
      0);
  }
  v19 = this->m_MyRoot.mOffset;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  *(float *)&v26 = FLOAT_N99999_0;
  if ( v19 )
    v21 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v19);
  else
    v21 = 0i64;
  if ( v19 )
    v22 = (char *)&this->m_MyRoot + v19;
  else
    v22 = 0i64;
  v23 = action_context->mActionTreeComponentBase[v22[236]];
  if ( !v23 )
    v23 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(v23, v21, (ActionNodeRoot *)this->m_TimeCanEnterUID, &v26);
  return mSimTime_Temp >= *(float *)&v26;
}

// File Line: 1311
// RVA: 0x14B6D20
__int64 dynamic_initializer_for__geAIObjectiveEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&geAIObjectiveEnum, UFG::AIObjectiveNames, 36, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__geAIObjectiveEnum__);
}

// File Line: 1313
// RVA: 0x14AD840
__int64 dynamic_initializer_for__AIObjectiveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIObjectiveCondition", 0xFFFFFFFF);
  AIObjectiveCondition::sClassNameUID = result;
  return result;
}

// File Line: 1319
// RVA: 0x32B7E0
void __fastcall AIObjectiveCondition::AIObjectiveCondition(AIObjectiveCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveCondition::`vftable;
  this->m_AIObjective.mValue = 0;
}

// File Line: 1324
// RVA: 0x36EBA0
bool __fastcall AIObjectiveCondition::Match(AIObjectiveCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   m_pPointer,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_CurrentObjective == (unsigned __int8)this->m_AIObjective.mValue;
  return result;
}

// File Line: 1353
// RVA: 0x14AD820
__int64 dynamic_initializer_for__AIObjectiveAnyCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIObjectiveAnyCondition", 0xFFFFFFFF);
  AIObjectiveAnyCondition::sClassNameUID = result;
  return result;
}

// File Line: 1356
// RVA: 0x32B7B0
void __fastcall AIObjectiveAnyCondition::AIObjectiveAnyCondition(AIObjectiveAnyCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveAnyCondition::`vftable;
}

// File Line: 1361
// RVA: 0x36EB10
bool __fastcall AIObjectiveAnyCondition::Match(AIObjectiveAnyCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   m_pPointer,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_CurrentObjective != eAI_OBJECTIVE_NONE;
  return result;
}

// File Line: 1390
// RVA: 0x14AD860
__int64 dynamic_initializer_for__AIObjectiveIsHostileCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIObjectiveIsHostileCondition", 0xFFFFFFFF);
  AIObjectiveIsHostileCondition::sClassNameUID = result;
  return result;
}

// File Line: 1393
// RVA: 0x32B820
void __fastcall AIObjectiveIsHostileCondition::AIObjectiveIsHostileCondition(AIObjectiveIsHostileCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveIsHostileCondition::`vftable;
}

// File Line: 1398
// RVA: 0x36EC40
bool __fastcall AIObjectiveIsHostileCondition::Match(
        AIObjectiveIsHostileCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               m_pPointer,
                                                               UFG::ActiveAIEntityComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pPointer,
                                                               UFG::ActiveAIEntityComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return UFG::g_AIObjectiveParams[ComponentOfTypeHK->m_CurrentObjective].m_IsHostile;
  }
  else
  {
    return 0;
  }
}

// File Line: 1429
// RVA: 0x14AD8A0
__int64 dynamic_initializer_for__AIOnMeshCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIOnMeshCondition", 0xFFFFFFFF);
  AIOnMeshCondition::sClassNameUID = result;
  return result;
}

// File Line: 1432
// RVA: 0x32B8F0
void __fastcall AIOnMeshCondition::AIOnMeshCondition(AIOnMeshCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIOnMeshCondition::`vftable;
}

// File Line: 1437
// RVA: 0x36ECD0
bool __fastcall AIOnMeshCondition::Match(AIOnMeshCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
    if ( m_pComponent
      && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))m_pComponent[1].m_SafePointerList.mNode.mNext[1].mNext)(&m_pComponent[1].m_SafePointerList.mNode.mNext) )
    {
      return 1;
    }
  }
  return result;
}

// File Line: 1466
// RVA: 0x14AD4C0
__int64 dynamic_initializer_for__AIAtDestinationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIAtDestinationCondition", 0xFFFFFFFF);
  AIAtDestinationCondition::sClassNameUID = result;
  return result;
}

// File Line: 1472
// RVA: 0x32A920
void __fastcall AIAtDestinationCondition::AIAtDestinationCondition(AIAtDestinationCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIAtDestinationCondition::`vftable;
  this->m_Tolerance = 0.5;
}

// File Line: 1477
// RVA: 0x36DE10
bool __fastcall AIAtDestinationCondition::Match(AIAtDestinationCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::NavComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::NavComponent::_TypeUID))
       : (ComponentOfType = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::NavComponent::_TypeUID)))
      : (ComponentOfType = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent),
        ComponentOfType) )
  {
    return UFG::NavComponent::IsAtDestination(ComponentOfType);
  }
  else
  {
    return 0;
  }
}

// File Line: 1505
// RVA: 0x14AD7E0
__int64 dynamic_initializer_for__AIHasValidPathCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIHasValidPathCondition", 0xFFFFFFFF);
  AIHasValidPathCondition::sClassNameUID = result;
  return result;
}

// File Line: 1508
// RVA: 0x32B680
void __fastcall AIHasValidPathCondition::AIHasValidPathCondition(AIHasValidPathCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIHasValidPathCondition::`vftable;
}

// File Line: 1513
// RVA: 0x36E6B0
bool __fastcall AIHasValidPathCondition::Match(AIHasValidPathCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::NavComponent *m_pComponent; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
    else
      m_pComponent = (UFG::NavComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                             m_pPointer,
                                             UFG::NavComponent::_TypeUID)
                                         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID));
    if ( m_pComponent && !UFG::NavComponent::IsDestinationUnreachable(m_pComponent) )
      return 1;
  }
  return result;
}

// File Line: 1538
// RVA: 0x14AD780
__int64 dynamic_initializer_for__AIDestinationObstructedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIDestinationObstructedCondition", 0xFFFFFFFF);
  AIDestinationObstructedCondition::sClassNameUID = result;
  return result;
}

// File Line: 1541
// RVA: 0x32B3D0
void __fastcall AIDestinationObstructedCondition::AIDestinationObstructedCondition(
        AIDestinationObstructedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIDestinationObstructedCondition::`vftable;
}

// File Line: 1546
// RVA: 0x36E460
bool __fastcall AIDestinationObstructedCondition::Match(
        AIDestinationObstructedCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::NavComponent *m_pComponent; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
    else
      m_pComponent = (UFG::NavComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                             m_pPointer,
                                             UFG::NavComponent::_TypeUID)
                                         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID));
    if ( m_pComponent && UFG::NavComponent::IsDestinationObstructed(m_pComponent) )
      return 1;
  }
  return result;
}

// File Line: 1571
// RVA: 0x14AE4A0
__int64 dynamic_initializer_for__POIUseTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIUseTypeCondition", 0xFFFFFFFF);
  POIUseTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 1577
// RVA: 0x330D40
void __fastcall POIUseTypeCondition::POIUseTypeCondition(POIUseTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&POIUseTypeCondition::`vftable;
  this->m_POIUseType.mValue = 0;
}

// File Line: 1582
// RVA: 0x371AF0
bool __fastcall POIUseTypeCondition::Match(POIUseTypeCondition *this, ActionContext *context)
{
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[43].m_pComponent;
  }
  else
  {
    if ( m_Flags < 0 )
      return 0;
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[12].m_pComponent;
    }
    else
    {
      if ( (m_Flags & 0x1000) != 0 )
        return 0;
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InterestPointUserComponent::_TypeUID);
    }
  }
  if ( m_pComponent )
    return LODWORD(m_pComponent[7].m_BoundComponentHandles.mNode.mNext) == (unsigned __int8)this->m_POIUseType.mValue;
  return 0;
}

// File Line: 1607
// RVA: 0x14AE080
__int64 dynamic_initializer_for__HasRequestedSpeechCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasRequestedSpeechCondition", 0xFFFFFFFF);
  HasRequestedSpeechCondition::sClassNameUID = result;
  return result;
}

// File Line: 1610
// RVA: 0x370690
bool __fastcall HasRequestedSpeechCondition::Match(HasRequestedSpeechCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::ActorAudioComponent::_TypeUID))
           : (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::ActorAudioComponent::_TypeUID)))
          : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer)),
            ComponentOfType)
        && (*((_BYTE *)ComponentOfType + 552) & 1) != 0;
  return result;
}

// File Line: 1647
// RVA: 0x14AE0C0
__int64 dynamic_initializer_for__HasSpecificSpeechAnimationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasSpecificSpeechAnimationCondition", 0xFFFFFFFF);
  HasSpecificSpeechAnimationCondition::sClassNameUID = result;
  return result;
}

// File Line: 1650
// RVA: 0x370740
bool __fastcall HasSpecificSpeechAnimationCondition::Match(
        HasSpecificSpeechAnimationCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  m_pPointer,
                                  UFG::DialogueAnimationComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::DialogueAnimationComponent::_TypeUID)))
          : (ComponentOfType = m_pPointer->m_Components.p[41].m_pComponent),
            ComponentOfType)
        && ((__int64)ComponentOfType[2].m_pSimObject & 4) != 0;
  return result;
}

// File Line: 1688
// RVA: 0x14ADE20
__int64 dynamic_initializer_for__FailedSpeechCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FailedSpeechCondition", 0xFFFFFFFF);
  FailedSpeechCondition::sClassNameUID = result;
  return result;
}

// File Line: 1691
// RVA: 0x36FBA0
bool __fastcall FailedSpeechCondition::Match(FailedSpeechCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::ActorAudioComponent::_TypeUID))
       : (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::ActorAudioComponent::_TypeUID)))
      : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer)),
        ComponentOfType) )
  {
    return *((_BYTE *)ComponentOfType + 553) & 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 1725
// RVA: 0x14AE0A0
__int64 dynamic_initializer_for__HasScriptedConversationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasScriptedConversationCondition", 0xFFFFFFFF);
  HasScriptedConversationCondition::sClassNameUID = result;
  return result;
}

// File Line: 1730
// RVA: 0x370730
bool __fastcall HasScriptedConversationCondition::Match(HasScriptedConversationCondition *this, ActionContext *context)
{
  return UFG::ConversationManager::IsInConversationWithTopic(
           context->mSimObject.m_pPointer,
           (UFG::eConversationTopic)this->m_topic);
}

// File Line: 1756
// RVA: 0x14AE060
__int64 dynamic_initializer_for__HasRemainingLinesCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasRemainingLinesCondition", 0xFFFFFFFF);
  HasRemainingLinesCondition::sClassNameUID = result;
  return result;
}

// File Line: 1758
// RVA: 0x3705F0
bool __fastcall HasRemainingLinesCondition::Match(HasRemainingLinesCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v4; // rax
  UFG::Conversation *ActiveAmbientConversation; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v4 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID));
    if ( v4 )
    {
      ActiveAmbientConversation = UFG::ActorAudioComponent::GetActiveAmbientConversation(v4);
      if ( ActiveAmbientConversation )
      {
        if ( ActiveAmbientConversation->m_numElements - ActiveAmbientConversation->m_curLine != 1 )
          return 1;
      }
    }
  }
  return result;
}

// File Line: 1794
// RVA: 0x14ADFC0
__int64 dynamic_initializer_for__HasActiveConversationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasActiveConversationCondition", 0xFFFFFFFF);
  HasActiveConversationCondition::sClassNameUID = result;
  return result;
}

// File Line: 1797
// RVA: 0x370240
bool __fastcall HasActiveConversationCondition::Match(HasActiveConversationCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v4 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID));
    if ( v4 && UFG::ActorAudioComponent::GetActiveAmbientConversation(v4) )
      return 1;
  }
  return result;
}

// File Line: 1828
// RVA: 0x14ADBE0
__int64 dynamic_initializer_for__ConversationFinishedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationFinishedCondition", 0xFFFFFFFF);
  ConversationFinishedCondition::sClassNameUID = result;
  return result;
}

// File Line: 1831
// RVA: 0x36F510
bool __fastcall ConversationFinishedCondition::Match(ConversationFinishedCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool result; // al
  UFG::Conversation *ActiveAmbientConversation; // rax

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    else
      v4 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::ActorAudioComponent::_TypeUID));
    if ( !v4 )
      return 1;
    ActiveAmbientConversation = UFG::ActorAudioComponent::GetActiveAmbientConversation(v4);
    if ( !ActiveAmbientConversation || ActiveAmbientConversation->m_state == eConversationState_Finished )
      return 1;
  }
  return result;
}

// File Line: 1870
// RVA: 0x14AE240
__int64 dynamic_initializer_for__IsSpeakingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsSpeakingCondition", 0xFFFFFFFF);
  IsSpeakingCondition::sClassNameUID = result;
  return result;
}

// File Line: 1873
// RVA: 0x3710C0
bool __fastcall IsSpeakingCondition::Match(IsSpeakingCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *v4; // rax

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
  else
    v4 = (UFG::ActorAudioComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        m_pPointer,
                                        UFG::ActorAudioComponent::_TypeUID)
                                    : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActorAudioComponent::_TypeUID));
  if ( !v4 )
    return 0;
  return v4->m_isSpeakingCnt > 0 && v4->m_controller.m_pEvent;
}

// File Line: 1908
// RVA: 0x14ADC40
__int64 dynamic_initializer_for__ConversationIsSpeakingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationIsSpeakingCondition", 0xFFFFFFFF);
  ConversationIsSpeakingCondition::sClassNameUID = result;
  return result;
}

// File Line: 1911
// RVA: 0x36F770
bool __fastcall ConversationIsSpeakingCondition::Match(ConversationIsSpeakingCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::ActorAudioComponent::_TypeUID))
       : (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::ActorAudioComponent::_TypeUID)))
      : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer)),
        ComponentOfType) )
  {
    return *((_BYTE *)ComponentOfType + 552) & 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 1947
// RVA: 0x14ADC20
__int64 dynamic_initializer_for__ConversationIsListeningCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationIsListeningCondition", 0xFFFFFFFF);
  ConversationIsListeningCondition::sClassNameUID = result;
  return result;
}

// File Line: 1950
// RVA: 0x36F6E0
bool __fastcall ConversationIsListeningCondition::Match(ConversationIsListeningCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::ActorAudioComponent::_TypeUID))
           : (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::ActorAudioComponent::_TypeUID)))
          : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer)),
            ComponentOfType)
        && (*((_BYTE *)ComponentOfType + 552) & 2) != 0;
  return result;
}

// File Line: 1984
// RVA: 0x14ADC00
__int64 dynamic_initializer_for__ConversationHasActionRequestsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationHasActionRequestsCondition", 0xFFFFFFFF);
  ConversationHasActionRequestsCondition::sClassNameUID = result;
  return result;
}

// File Line: 1987
// RVA: 0x36F5B0
bool __fastcall ConversationHasActionRequestsCondition::Match(
        ConversationHasActionRequestsCondition *this,
        ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v6; // rcx
  char v7; // di
  UFG::ActorAudioComponent *v8; // rbx
  UFG::SimComponent *m_pComponent; // rax
  __int16 v10; // dx

  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    v6 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    v7 = 0;
    v8 = ComponentOfTypeHK;
    if ( v6 )
    {
      v10 = v6->m_Flags;
      if ( (v10 & 0x4000) != 0 )
      {
        m_pComponent = v6->m_Components.p[45].m_pComponent;
      }
      else if ( v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FaceActionComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v6, UFG::FaceActionComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    if ( v8 )
    {
      if ( (*((_BYTE *)v8 + 553) & 0x20) != 0 )
        v7 = 1;
    }
    else if ( !m_pComponent )
    {
      return (char)m_pComponent;
    }
    LOBYTE(m_pComponent) = v7;
  }
  else
  {
    LOBYTE(m_pComponent) = 0;
  }
  return (char)m_pComponent;
}

// File Line: 2026
// RVA: 0x14AE7E0
__int64 dynamic_initializer_for__TargetPOIIsValidCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPOIIsValidCondition", 0xFFFFFFFF);
  TargetPOIIsValidCondition::sClassNameUID = result;
  return result;
}

// File Line: 2029
// RVA: 0x3733F0
char __fastcall TargetPOIIsValidCondition::Match(TargetPOIIsValidCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rbx
  UFG::SimObject *v8; // rcx
  UFG::InterestPoint *ComponentOfType; // rdi
  __int16 v10; // dx
  UFG::SimObject *v11; // rcx
  __int16 v12; // dx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  int v15; // ecx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = 0i64;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      ComponentOfType = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
    }
    else if ( v10 >= 0 )
    {
      if ( (v10 & 0x2000) != 0 )
      {
        ComponentOfType = (UFG::InterestPoint *)v8->m_Components.p[10].m_pComponent;
      }
      else if ( (v10 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::InterestPoint *)v8->m_Components.p[3].m_pComponent;
      }
      else
      {
        ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v8, UFG::InterestPoint::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
  v11 = context->mSimObject.m_pPointer;
  if ( v11 )
  {
    v12 = v11->m_Flags;
    if ( (v12 & 0x4000) != 0 )
    {
      v7 = v11->m_Components.p[43].m_pComponent;
    }
    else if ( v12 >= 0 )
    {
      if ( (v12 & 0x2000) != 0 )
      {
        v7 = v11->m_Components.p[12].m_pComponent;
      }
      else if ( (v12 & 0x1000) == 0 )
      {
        v7 = UFG::SimObject::GetComponentOfType(v11, UFG::InterestPointUserComponent::_TypeUID);
      }
    }
  }
  if ( !ComponentOfType )
    return 0;
  if ( !v7 )
    return 0;
  if ( UFG::InterestPoint::IsAutoInteractable(ComponentOfType) )
    return 0;
  mNext = v7[8].m_SafePointerList.mNode.mNext;
  if ( mNext )
  {
    if ( mNext != (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)ComponentOfType )
      return 0;
    mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v7[7].m_BoundComponentHandles.mNode.mPrev;
    if ( mPrev )
    {
      v15 = (int)v7[7].m_BoundComponentHandles.mNode.mNext;
      if ( v15 )
      {
        if ( mPrev != v7[8].m_SafePointerList.mNode.mNext
          || v7[8].m_TypeUID != v15
          || v7[8].m_NameUID != HIDWORD(v7[7].m_BoundComponentHandles.mNode.mNext) )
        {
          return 0;
        }
      }
    }
  }
  if ( ComponentOfType->mpUser.m_pPointer == context->mSimObject.m_pPointer )
    return 1;
  if ( UFG::InterestPoint::IsReservationMatch(ComponentOfType, 8u, ReserveReason_normal) )
    return UFG::InterestPoint::IsAvailable(ComponentOfType, context->mSimObject.m_pPointer, 1);
  else
    return 0;
}

// File Line: 2108
// RVA: 0x14AE800
__int64 dynamic_initializer_for__TargetPOIRequiresSyncCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPOIRequiresSyncCondition", 0xFFFFFFFF);
  TargetPOIRequiresSyncCondition::sClassNameUID = result;
  return result;
}

// File Line: 2111
// RVA: 0x373640
bool __fastcall TargetPOIRequiresSyncCondition::Match(TargetPOIRequiresSyncCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v6; // rcx
  __int16 v7; // dx
  UFG::InterestPoint *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                     + 40)) != 0i64
         && ((v7 = v6->m_Flags, (v7 & 0x4000) == 0)
           ? (v7 >= 0
            ? ((v7 & 0x2000) == 0
             ? ((v7 & 0x1000) == 0
              ? (ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(
                                                           v6,
                                                           UFG::InterestPoint::_TypeUID))
              : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent))
             : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent))
            : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent))
           : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent),
             ComponentOfType))
        && UFG::InterestPoint::GetRequiresSync(ComponentOfType);
  return result;
}

// File Line: 2143
// RVA: 0x14AE820
__int64 dynamic_initializer_for__TargetPOISyncRequiredCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPOISyncRequiredCondition", 0xFFFFFFFF);
  TargetPOISyncRequiredCondition::sClassNameUID = result;
  return result;
}

// File Line: 2149
// RVA: 0x373760
bool __fastcall TargetPOISyncRequiredCondition::Match(TargetPOISyncRequiredCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rcx
  __int16 v9; // dx
  UFG::InterestPoint *v10; // rbx

  if ( !this->m_Position && !this->m_Rotation )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
  {
    v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
  }
  else if ( v9 >= 0 )
  {
    if ( (v9 & 0x2000) != 0 )
      v10 = (UFG::InterestPoint *)v8->m_Components.p[10].m_pComponent;
    else
      v10 = (UFG::InterestPoint *)((v9 & 0x1000) != 0
                                 ? v8->m_Components.p[3].m_pComponent
                                 : UFG::SimObject::GetComponentOfType(v8, UFG::InterestPoint::_TypeUID));
  }
  else
  {
    v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
  }
  if ( !v10 )
    return 0;
  return (!this->m_Position || UFG::InterestPoint::GetPositionSyncRequired(v10))
      && (!this->m_Rotation || UFG::InterestPoint::GetRotationSyncRequired(v10));
}

// File Line: 2185
// RVA: 0x14AE7C0
__int64 dynamic_initializer_for__TargetPOIAllowsSocialCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPOIAllowsSocialCondition", 0xFFFFFFFF);
  TargetPOIAllowsSocialCondition::sClassNameUID = result;
  return result;
}

// File Line: 2188
// RVA: 0x3732D0
bool __fastcall TargetPOIAllowsSocialCondition::Match(TargetPOIAllowsSocialCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v6; // rcx
  __int16 v7; // dx
  UFG::InterestPoint *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                     + 40)) != 0i64
         && ((v7 = v6->m_Flags, (v7 & 0x4000) == 0)
           ? (v7 >= 0
            ? ((v7 & 0x2000) == 0
             ? ((v7 & 0x1000) == 0
              ? (ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(
                                                           v6,
                                                           UFG::InterestPoint::_TypeUID))
              : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent))
             : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent))
            : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent))
           : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent),
             ComponentOfType))
        && UFG::InterestPoint::GetAllowSocialInteraction(ComponentOfType);
  return result;
}

// File Line: 2222
// RVA: 0x14AE740
__int64 dynamic_initializer_for__TargetDistanceHysteresis::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDistanceHysteresis", 0xFFFFFFFF);
  TargetDistanceHysteresis::sClassNameUID = result;
  return result;
}

// File Line: 2245
// RVA: 0x332540
void __fastcall TargetDistanceHysteresis::TargetDistanceHysteresis(TargetDistanceHysteresis *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDistanceHysteresis::`vftable;
  *(_QWORD *)&this->m_TargetType = 0i64;
  *(_QWORD *)&this->m_ZDistanceBegin = 0x40000000i64;
  this->m_ZDistanceEnd = 2.0;
  *(_QWORD *)&this->m_InEqualityOperatorBegin.mValue = 50529284i64;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 2250
// RVA: 0x383C00
void __fastcall TargetDistanceHysteresis::ResolveReferences(TargetDistanceHysteresis *this, ActionNode *action_node)
{
  Expression::IMemberMap *v3; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx

  v3 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v3 )
    v3 = (Expression::IMemberMap *)((char *)v3 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v3;
  this->m_HasBegunUID = UFG::ActionTreeComponentBase::MakeValueUID(
                          this->m_HasBegunUID,
                          eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 2259
// RVA: 0x372B50
bool __fastcall TargetDistanceHysteresis::Match(TargetDistanceHysteresis *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  char *v4; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v9; // r14
  UFG::SimObject *v10; // rbp
  __int64 v11; // r14
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  __m128 v13; // xmm1
  float v14; // xmm7_4
  __int64 mOffset; // rax
  float v16; // xmm6_4
  UFG::ActionTreeComponentBase *v17; // rdx
  char *v18; // rcx
  UFG::ActionTreeComponentBase *v19; // rcx
  bool v20; // bp
  __int64 v21; // rax
  UFG::ActionTreeComponentBase *v22; // rdx
  UFG::ActionTreeComponentBase *v23; // rcx
  __int64 v25; // rax
  UFG::ActionTreeComponentBase *v26; // rdx
  UFG::ActionTreeComponentBase *v27; // rcx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
      : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
        m_pComponent
     && (v9 = *(_QWORD *)(56i64
                        * *(unsigned __int8 *)((unsigned int)this->m_TargetType
                                             + *(_QWORD *)&m_pComponent[1].m_Flags
                                             + 8i64)
                        + *(_QWORD *)&m_pComponent[1].m_TypeUID
                        + 40)) != 0
     && ((v10 = context->mSimObject.m_pPointer, v11 = *(_QWORD *)(v9 + 88), v10)
       ? (m_pTransformNodeComponent = v10->m_pTransformNodeComponent)
       : (m_pTransformNodeComponent = 0i64),
         v11 && m_pTransformNodeComponent)) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
    v13 = (__m128)*(unsigned int *)(v11 + 180);
    v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y)
                            * (float)(v13.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y))
                    + (float)((float)(*(float *)(v11 + 176) - m_pTransformNodeComponent->mWorldTransform.v3.x)
                            * (float)(*(float *)(v11 + 176) - m_pTransformNodeComponent->mWorldTransform.v3.x));
    LODWORD(v14) = _mm_sqrt_ps(v13).m128_u32[0];
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    mOffset = this->m_MyRoot.mOffset;
    LODWORD(v16) = COERCE_UNSIGNED_INT(*(float *)(v11 + 184) - m_pTransformNodeComponent->mWorldTransform.v3.z) & _xmm;
    if ( mOffset )
      v17 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v17 = 0i64;
    if ( mOffset )
      v18 = (char *)&this->m_MyRoot + mOffset;
    else
      v18 = 0i64;
    v19 = context->mActionTreeComponentBase[v18[236]];
    if ( !v19 )
      v19 = context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v19, v17, (ActionNodeRoot *)this->m_HasBegunUID, 0);
    v20 = CompareFloat(
            (UFG::InEqualityOperator)(unsigned __int8)this->m_InEqualityOperatorBegin.mValue,
            this->m_DistanceBegin,
            v14)
       && CompareFloat(
            (UFG::InEqualityOperator)(unsigned __int8)this->m_ZInEqualityOperatorBegin.mValue,
            this->m_ZDistanceBegin,
            v16);
    v21 = this->m_MyRoot.mOffset;
    if ( v21 )
      v22 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v21);
    else
      v22 = 0i64;
    if ( v21 )
      v4 = (char *)&this->m_MyRoot + v21;
    v23 = context->mActionTreeComponentBase[v4[236]];
    if ( !v23 )
      v23 = context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v23, v22, (ActionNodeRoot *)this->m_HasBegunUID, v20);
    return v20;
  }
  else
  {
    v25 = this->m_MyRoot.mOffset;
    if ( v25 )
      v26 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v25);
    else
      v26 = 0i64;
    if ( v25 )
      v4 = (char *)&this->m_MyRoot + v25;
    v27 = context->mActionTreeComponentBase[v4[236]];
    if ( !v27 )
      v27 = context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v27, v26, (ActionNodeRoot *)this->m_HasBegunUID, 0);
    return 0;
  }
}

// File Line: 2338
// RVA: 0x14AE840
__int64 dynamic_initializer_for__TargetVisibleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetVisibleCondition", 0xFFFFFFFF);
  TargetVisibleCondition::sClassNameUID = result;
  return result;
}

// File Line: 2362
// RVA: 0x332660
void __fastcall TargetVisibleCondition::TargetVisibleCondition(TargetVisibleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetVisibleCondition::`vftable;
  this->m_TargetType = 0;
  this->m_NumSecondsToContinueAfterTargetFirstVisible = 2.0;
  this->m_MinTimeBetweenChecks = 0.5;
  this->m_MaxTimeBetweenChecks = 1.0;
  *(_WORD *)&this->m_FixZForCharacter = 1;
  this->m_DebugDrawColour = UFG::qColour::Red;
  this->m_MyRoot.mOffset = 0i64;
  *(_QWORD *)&this->m_TargetIsVisibleUID = 0i64;
  *(_QWORD *)&this->m_NextTimeToCheckTargetIsVisibleUID = 0i64;
  this->m_TargetObjectUID = 0;
}

// File Line: 2371
// RVA: 0x383C40
void __fastcall TargetVisibleCondition::ResolveReferences(TargetVisibleCondition *this, ActionNode *action_node)
{
  unsigned int ValueUID; // eax
  unsigned int m_TimeTargetBecameVisibleUID; // ecx
  unsigned int v6; // eax
  unsigned int m_NextTimeToCheckTargetIsVisibleUID; // ecx
  unsigned int v8; // eax
  unsigned int m_PreviousTargetUID; // ecx
  unsigned int v10; // eax
  unsigned int m_TargetObjectUID; // ecx
  Expression::IMemberMap *v12; // rax

  ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(this->m_TargetIsVisibleUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  m_TimeTargetBecameVisibleUID = this->m_TimeTargetBecameVisibleUID;
  this->m_TargetIsVisibleUID = ValueUID;
  v6 = UFG::ActionTreeComponentBase::MakeValueUID(m_TimeTargetBecameVisibleUID, eACTION_TREE_MEMORY_ELEMENT_FLOAT);
  m_NextTimeToCheckTargetIsVisibleUID = this->m_NextTimeToCheckTargetIsVisibleUID;
  this->m_TimeTargetBecameVisibleUID = v6;
  v8 = UFG::ActionTreeComponentBase::MakeValueUID(
         m_NextTimeToCheckTargetIsVisibleUID,
         eACTION_TREE_MEMORY_ELEMENT_FLOAT);
  m_PreviousTargetUID = this->m_PreviousTargetUID;
  this->m_NextTimeToCheckTargetIsVisibleUID = v8;
  v10 = UFG::ActionTreeComponentBase::MakeValueUID(m_PreviousTargetUID, eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  m_TargetObjectUID = this->m_TargetObjectUID;
  this->m_PreviousTargetUID = v10;
  this->m_TargetObjectUID = UFG::ActionTreeComponentBase::MakeValueUID(
                              m_TargetObjectUID,
                              eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  v12 = action_node->vfptr[1].GetResourceOwner(action_node);
  if ( v12 )
    this->m_MyRoot.mOffset = (char *)v12 - (char *)&this->m_MyRoot;
}

// File Line: 2399
// RVA: 0x3423D0
void __fastcall TargetVisibleCondition::AsyncRayCallback(
        UFG::RayCastData *raycastData,
        UFG::SimComponent *simComponent,
        TargetVisibleCondition *callbackUserData)
{
  __int64 mOffset; // rax
  char *v6; // r8
  char *v7; // rcx
  UFG::ActionTreeComponentBase *p_mNext; // rsi
  UFG::ActionTreeComponentBase *v9; // rdx
  bool IsVisible; // bl
  float x; // xmm1_4
  float y; // xmm0_4
  float z; // xmm1_4
  Render::DebugDrawContext *Context; // rax
  UFG::qVector3 point; // [rsp+30h] [rbp-38h] BYREF
  UFG::qColour colour; // [rsp+40h] [rbp-28h] BYREF
  UFG::SimObject *value_uid; // [rsp+78h] [rbp+10h] BYREF
  UFG::SimObject *ray_hit_object; // [rsp+88h] [rbp+20h] BYREF

  if ( simComponent )
  {
    mOffset = callbackUserData->m_MyRoot.mOffset;
    if ( mOffset )
      v6 = (char *)&callbackUserData->m_MyRoot + mOffset;
    else
      v6 = 0i64;
    if ( v6[236] == 1
      || (!mOffset ? (v7 = 0i64) : (v7 = (char *)&callbackUserData->m_MyRoot + mOffset),
          p_mNext = (UFG::ActionTreeComponentBase *)&simComponent[1].m_SafePointerList.mNode.mNext,
          v7[236] != 2) )
    {
      p_mNext = (UFG::ActionTreeComponentBase *)&simComponent[1];
    }
    value_uid = 0i64;
    if ( mOffset )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&callbackUserData->m_MyRoot + mOffset);
    else
      v9 = 0i64;
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
      p_mNext,
      v9,
      (ActionNodeRoot *)callbackUserData->m_TargetObjectUID,
      &value_uid);
    ray_hit_object = 0i64;
    IsVisible = UFG::TargetIsVisible(raycastData, value_uid, &ray_hit_object);
    TargetVisibleCondition::DealWithRayCastResult(callbackUserData, IsVisible, p_mNext);
    if ( !IsVisible )
    {
      if ( callbackUserData->m_DebugDraw )
      {
        x = raycastData->point.x;
        colour = callbackUserData->m_DebugDrawColour;
        y = raycastData->point.y;
        point.x = x;
        z = raycastData->point.z;
        point.y = y;
        point.z = z;
        Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                1u);
        Render::DebugDrawContext::DrawPoint(Context, &point, &colour, &UFG::qMatrix44::msIdentity, 0i64);
      }
    }
  }
}

// File Line: 2459
// RVA: 0x3519E0
void __fastcall TargetVisibleCondition::DealWithRayCastResult(
        TargetVisibleCondition *this,
        char target_is_visible,
        UFG::ActionTreeComponentBase *action_tree_memory_component)
{
  UFG::ActionTreeComponentBase *v3; // rdi
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v8; // rdx
  unsigned int v9; // r9d
  __int64 v10; // rax
  UFG::ActionTreeComponentBase *v11; // rdx
  float m_MaxTimeBetweenChecks; // xmm7_4
  float m_MinTimeBetweenChecks; // xmm8_4
  __int64 v14; // rax
  UFG::ActionTreeComponentBase *v15; // rdx
  unsigned int v16; // r9d
  __int64 v17; // rax
  unsigned int value_uid; // [rsp+80h] [rbp+18h] BYREF

  if ( action_tree_memory_component )
  {
    LOBYTE(value_uid) = 0;
    v3 = 0i64;
    mOffset = this->m_MyRoot.mOffset;
    if ( mOffset )
      v8 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v8 = 0i64;
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
      action_tree_memory_component,
      v8,
      (ActionNodeRoot *)this->m_TargetIsVisibleUID,
      (bool *)&value_uid);
    if ( target_is_visible && !(_BYTE)value_uid )
    {
      v10 = this->m_MyRoot.mOffset;
      if ( v10 )
        v11 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v10);
      else
        v11 = 0i64;
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
        action_tree_memory_component,
        v11,
        (ActionNodeRoot *)this->m_TimeTargetBecameVisibleUID,
        v9);
    }
    m_MaxTimeBetweenChecks = this->m_MaxTimeBetweenChecks;
    m_MinTimeBetweenChecks = this->m_MinTimeBetweenChecks;
    if ( m_MaxTimeBetweenChecks > m_MinTimeBetweenChecks )
      UFG::qRandom(m_MaxTimeBetweenChecks - m_MinTimeBetweenChecks, (unsigned int *)&UFG::qDefaultSeed);
    v14 = this->m_MyRoot.mOffset;
    if ( v14 )
      v15 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v14);
    else
      v15 = 0i64;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      action_tree_memory_component,
      v15,
      (ActionNodeRoot *)this->m_TargetIsVisibleUID,
      target_is_visible);
    v17 = this->m_MyRoot.mOffset;
    if ( v17 )
      v3 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v17);
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      action_tree_memory_component,
      v3,
      (ActionNodeRoot *)this->m_NextTimeToCheckTargetIsVisibleUID,
      v16);
  }
}

// File Line: 2493
// RVA: 0x35FDC0
char __fastcall TargetVisibleCondition::GetHeadPosition(
        TargetVisibleCondition *this,
        UFG::SimObjectGame *pSimObject,
        UFG::qVector3 *vHeadPosOut)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  __int64 v7; // rbx
  int BoneID; // eax
  hkQsTransformf *TranslationMS; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4

  if ( (_S23_0 & 1) == 0 )
  {
    _S23_0 |= 1u;
    s_uidHeadBone = UFG::qStringHashUpper32("Bip01 Head", -1);
  }
  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pSimObject->m_Components.p[9].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      m_pComponent = pSimObject->m_Components.p[8].m_pComponent;
    else
      m_pComponent = (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::BaseAnimationComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(pSimObject, UFG::BaseAnimationComponent::_TypeUID);
  }
  else
  {
    m_pComponent = pSimObject->m_Components.p[9].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(_QWORD *)&m_pComponent[2].m_TypeUID;
  if ( !v7 )
    return 0;
  if ( !*(_QWORD *)(v7 + 440) )
    return 0;
  BoneID = Skeleton::GetBoneID(*(Skeleton **)(v7 + 480), s_uidHeadBone);
  if ( BoneID < 0 )
    return 0;
  TranslationMS = SkeletalPose::GetTranslationMS((SkeletalPose *)(v7 + 240), BoneID);
  v10 = TranslationMS->m_translation.m_quad.m128_f32[1];
  v11 = TranslationMS->m_translation.m_quad.m128_f32[2];
  LODWORD(vHeadPosOut->x) = TranslationMS->m_translation.m_quad.m128_i32[0];
  vHeadPosOut->y = v10;
  vHeadPosOut->z = v11;
  return 1;
}

// File Line: 2519
// RVA: 0x3738E0
char __fastcall TargetVisibleCondition::Match(TargetVisibleCondition *this, ActionContext *context)
{
  float mSimTime_Temp; // xmm6_4
  UFG::SimObjectGame *m_pPointer; // rcx
  char v6; // r14
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v9; // rax
  UFG::SimObjectGame *v10; // rdi
  UFG::SimObjectCVBase *v11; // rcx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  __int16 v13; // dx
  int v14; // ecx
  unsigned int size; // edx
  UFG::PedKnowledgeRecord *p; // r8
  UFG::PedKnowledgeRecord *v17; // rax
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v20; // rdx
  char *v21; // rcx
  UFG::ActionTreeComponentBase *v22; // rcx
  __int64 v23; // rax
  UFG::ActionTreeComponentBase *v24; // rdx
  char *v25; // rcx
  UFG::ActionTreeComponentBase *v26; // rcx
  unsigned int v27; // r9d
  char v28; // bl
  __int64 v29; // rax
  UFG::ActionTreeComponentBase *v30; // rdx
  char *v31; // rcx
  UFG::ActionTreeComponentBase *v32; // rcx
  __int64 v33; // rax
  UFG::ActionTreeComponentBase *v34; // rdx
  char *v35; // rcx
  UFG::ActionTreeComponentBase *v36; // rcx
  __int64 v37; // rax
  char *v38; // rcx
  UFG::ActionTreeComponentBase *v39; // rax
  char *v40; // rcx
  UFG::SimComponent *p_mActionTreeMemoryDataStructs; // rdx
  __int64 v42; // rax
  UFG::ActionTreeComponentBase *v43; // rdx
  char *v44; // rcx
  UFG::ActionTreeComponentBase *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  unsigned __int64 m_pTransformNodeComponent; // rsi
  UFG::SimObject *v49; // rax
  UFG::TransformNodeComponent *v50; // r12
  __int64 v51; // rax
  char *v52; // rcx
  UFG::ActionTreeComponentBase *v53; // rax
  char *v54; // rcx
  UFG::SimComponent *p_mChild1; // rdx
  __int64 v56; // rax
  UFG::ActionTreeComponentBase *v57; // rdx
  char *v58; // rcx
  UFG::ActionTreeComponentBase *v59; // rcx
  bool v60; // bl
  bool v61; // di
  UFG::SimObject *v62; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v63; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v64; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v65; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v66; // rax
  __int64 v67; // rax
  UFG::ActionTreeComponentBase *v68; // rdx
  char *v69; // rcx
  UFG::ActionTreeComponentBase *v70; // rcx
  __int64 v71; // rax
  UFG::ActionTreeComponentBase *v72; // rdx
  char *v73; // rcx
  UFG::ActionTreeComponentBase *v74; // rcx
  UFG::AsyncRayCastData ray_hit_object; // [rsp+48h] [rbp-80h] BYREF
  UFG::qVector3 to_position; // [rsp+158h] [rbp+90h] BYREF
  UFG::qVector3 vHeadPosOut; // [rsp+168h] [rbp+A0h] BYREF
  __int64 v78; // [rsp+178h] [rbp+B0h]
  unsigned int value_uid; // [rsp+1E0h] [rbp+118h] BYREF
  unsigned int v80; // [rsp+1E8h] [rbp+120h] BYREF
  unsigned int v81[4]; // [rsp+1F0h] [rbp+128h] BYREF

  v78 = -2i64;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v6 = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v9 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v9;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v10 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)((unsigned int)this->m_TargetType
                                                        + *(_QWORD *)&m_pComponent[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40);
      v11 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
      if ( v11 )
      {
        v13 = v11->m_Flags;
        if ( (v13 & 0x4000) != 0 || v13 < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v11);
        }
        else if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v11,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                v11,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        ComponentOfTypeHK = 0i64;
      }
      v14 = 0;
      size = ComponentOfTypeHK->m_KnowledgeBase.m_aHostilePedRecords.size;
      if ( size )
      {
        p = ComponentOfTypeHK->m_KnowledgeBase.m_aHostilePedRecords.p;
        while ( 1 )
        {
          v17 = &p[v14];
          if ( v10 == v17->pSimObject.m_pPointer )
            break;
          if ( ++v14 >= size )
            goto LABEL_25;
        }
      }
      else
      {
LABEL_25:
        v17 = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
      }
      if ( v17->pSimObject.m_pPointer )
        return *((_BYTE *)v17 + 48) & 1;
      ray_hit_object.mInput.m_userData = 0i64;
      *(float *)&v80 = -99999.0;
      mOffset = this->m_MyRoot.mOffset;
      if ( mOffset )
        v20 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v20 = 0i64;
      if ( mOffset )
        v21 = (char *)&this->m_MyRoot + mOffset;
      else
        v21 = 0i64;
      v22 = context->mActionTreeComponentBase[v21[236]];
      if ( !v22 )
        v22 = context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
        v22,
        v20,
        (ActionNodeRoot *)this->m_PreviousTargetUID,
        &ray_hit_object.mInput.m_userData);
      v23 = this->m_MyRoot.mOffset;
      if ( v23 )
        v24 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v23);
      else
        v24 = 0i64;
      if ( v23 )
        v25 = (char *)&this->m_MyRoot + v23;
      else
        v25 = 0i64;
      v26 = context->mActionTreeComponentBase[v25[236]];
      if ( !v26 )
        v26 = context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
        v26,
        v24,
        (ActionNodeRoot *)this->m_NextTimeToCheckTargetIsVisibleUID,
        &v80);
      if ( mSimTime_Temp <= *(float *)&v80 && v10 == (UFG::SimObjectGame *)ray_hit_object.mInput.m_userData )
      {
        v28 = 0;
      }
      else
      {
        v28 = 1;
        if ( v10 != (UFG::SimObjectGame *)ray_hit_object.mInput.m_userData )
        {
          v29 = this->m_MyRoot.mOffset;
          if ( v29 )
            v30 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v29);
          else
            v30 = 0i64;
          if ( v29 )
            v31 = (char *)&this->m_MyRoot + v29;
          else
            v31 = 0i64;
          v32 = context->mActionTreeComponentBase[v31[236]];
          if ( !v32 )
            v32 = context->mActionTreeComponentBase[1];
          UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
            v32,
            v30,
            (ActionNodeRoot *)this->m_TimeTargetBecameVisibleUID,
            v27);
        }
      }
      if ( v10 && v28 )
      {
        v33 = this->m_MyRoot.mOffset;
        if ( v33 )
          v34 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v33);
        else
          v34 = 0i64;
        if ( v33 )
          v35 = (char *)&this->m_MyRoot + v33;
        else
          v35 = 0i64;
        v36 = context->mActionTreeComponentBase[v35[236]];
        if ( !v36 )
          v36 = context->mActionTreeComponentBase[1];
        UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
          v36,
          v34,
          (ActionNodeRoot *)this->m_PreviousTargetUID,
          v10);
        TargetVisibleCondition::GetHeadPosition(
          this,
          (UFG::SimObjectGame *)context->mSimObject.m_pPointer,
          &vHeadPosOut);
        if ( TargetVisibleCondition::GetHeadPosition(this, v10, &to_position) )
        {
          ray_hit_object.mInput.m_from.m_quad.m128_u64[1] = 0i64;
          ray_hit_object.mInput.m_userData = 0i64;
          LODWORD(ray_hit_object.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
          ray_hit_object.mOutput.m_extraInfo = -1;
          ray_hit_object.mOutput.m_shapeKeyIndex = 0;
          ray_hit_object.mOutput.m_shapeKeys[0] = -1;
          ray_hit_object.mOutput.m_rootCollidable = 0i64;
          ray_hit_object.mDebugName = 0i64;
          ray_hit_object.mCollisionModelName.mUID = -1;
          *(_QWORD *)&ray_hit_object.mInput.m_enableShapeCollectionFilter.m_bool = &ray_hit_object.UFG::CastData;
          ray_hit_object.mInput.m_to.m_quad.m128_u64[0] = (unsigned __int64)&ray_hit_object.UFG::CastData;
          ray_hit_object.simComponent.mPrev = &ray_hit_object.simComponent;
          ray_hit_object.simComponent.mNext = &ray_hit_object.simComponent;
          ray_hit_object.simComponent.m_pPointer = 0i64;
          ray_hit_object.raycastCallback = 0i64;
          ray_hit_object.callbackUserData = this;
          v37 = this->m_MyRoot.mOffset;
          if ( v37 )
            v38 = (char *)&this->m_MyRoot + v37;
          else
            v38 = 0i64;
          if ( v38[236] == 1 )
          {
            v39 = context->mActionTreeComponentBase[1];
          }
          else
          {
            if ( v37 )
              v40 = (char *)&this->m_MyRoot + v37;
            else
              v40 = 0i64;
            if ( v40[236] == 2 )
            {
              v39 = context->mActionTreeComponentBase[2];
              p_mActionTreeMemoryDataStructs = (UFG::SimComponent *)&v39[-1].mActionTreeMemoryDataStructs;
LABEL_80:
              if ( !v39 )
                p_mActionTreeMemoryDataStructs = 0i64;
              UFG::qSafePointer<Creature,Creature>::operator=(
                &ray_hit_object.simComponent,
                p_mActionTreeMemoryDataStructs);
              ray_hit_object.raycastCallback = (void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, void *))TargetVisibleCondition::AsyncRayCallback;
              v42 = this->m_MyRoot.mOffset;
              if ( v42 )
                v43 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v42);
              else
                v43 = 0i64;
              if ( v42 )
                v44 = (char *)&this->m_MyRoot + v42;
              else
                v44 = 0i64;
              v45 = context->mActionTreeComponentBase[v44[236]];
              if ( !v45 )
                v45 = context->mActionTreeComponentBase[1];
              UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
                v45,
                v43,
                (ActionNodeRoot *)this->m_TargetObjectUID,
                v10);
              UFG::DoRaycast(
                &vHeadPosOut,
                &to_position,
                v10,
                0i64,
                (UFG::SimObject **)&ray_hit_object.mInput.m_from.m_quad.m128_u64[1],
                &ray_hit_object,
                this->m_DebugDraw != 0,
                &this->m_DebugDrawColour);
              ray_hit_object.mInput.m_to.m_quad.m128_u64[0] = (unsigned __int64)&ray_hit_object.UFG::CastData;
              if ( ray_hit_object.simComponent.m_pPointer )
              {
                mPrev = ray_hit_object.simComponent.mPrev;
                mNext = ray_hit_object.simComponent.mNext;
                ray_hit_object.simComponent.mPrev->mNext = ray_hit_object.simComponent.mNext;
                mNext->mPrev = mPrev;
                ray_hit_object.simComponent.mPrev = &ray_hit_object.simComponent;
                ray_hit_object.simComponent.mNext = &ray_hit_object.simComponent;
              }
              ray_hit_object.simComponent.m_pPointer = 0i64;
LABEL_122:
              v65 = ray_hit_object.simComponent.mPrev;
              v66 = ray_hit_object.simComponent.mNext;
              ray_hit_object.simComponent.mPrev->mNext = ray_hit_object.simComponent.mNext;
              v66->mPrev = v65;
              ray_hit_object.simComponent.mPrev = &ray_hit_object.simComponent;
              ray_hit_object.simComponent.mNext = &ray_hit_object.simComponent;
              goto LABEL_123;
            }
            v39 = context->mActionTreeComponentBase[3];
          }
          p_mActionTreeMemoryDataStructs = (UFG::SimComponent *)&v39[-1].mActionTreeMemoryDataStructs.mTree.mRoot.mChild1;
          goto LABEL_80;
        }
        m_pTransformNodeComponent = (unsigned __int64)v10->m_pTransformNodeComponent;
        ray_hit_object.mInput.m_from.m_quad.m128_u64[1] = m_pTransformNodeComponent;
        v49 = context->mSimObject.m_pPointer;
        v50 = 0i64;
        if ( v49 )
          v50 = v49->m_pTransformNodeComponent;
        if ( !m_pTransformNodeComponent || !v50 )
          goto LABEL_123;
        *(_DWORD *)&ray_hit_object.mInput.m_enableShapeCollectionFilter.m_bool = 0;
        ray_hit_object.mInput.m_filterInfo = 0;
        ray_hit_object.mInput.m_userData = 0i64;
        LODWORD(ray_hit_object.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
        ray_hit_object.mOutput.m_extraInfo = -1;
        ray_hit_object.mOutput.m_shapeKeyIndex = 0;
        ray_hit_object.mOutput.m_shapeKeys[0] = -1;
        ray_hit_object.mOutput.m_rootCollidable = 0i64;
        ray_hit_object.mDebugName = 0i64;
        ray_hit_object.mCollisionModelName.mUID = -1;
        ray_hit_object.mInput.m_to.m_quad.m128_u64[0] = (unsigned __int64)&ray_hit_object.UFG::CastData;
        ray_hit_object.mInput.m_to.m_quad.m128_u64[1] = (unsigned __int64)&ray_hit_object.UFG::CastData;
        ray_hit_object.simComponent.mPrev = &ray_hit_object.simComponent;
        ray_hit_object.simComponent.mNext = &ray_hit_object.simComponent;
        ray_hit_object.simComponent.m_pPointer = 0i64;
        ray_hit_object.raycastCallback = 0i64;
        ray_hit_object.callbackUserData = this;
        v51 = this->m_MyRoot.mOffset;
        if ( v51 )
          v52 = (char *)&this->m_MyRoot + v51;
        else
          v52 = 0i64;
        if ( v52[236] == 1 )
        {
          v53 = context->mActionTreeComponentBase[1];
        }
        else
        {
          if ( v51 )
            v54 = (char *)&this->m_MyRoot + v51;
          else
            v54 = 0i64;
          if ( v54[236] == 2 )
          {
            v53 = context->mActionTreeComponentBase[2];
            p_mChild1 = (UFG::SimComponent *)&v53[-1].mActionTreeMemoryDataStructs;
LABEL_109:
            if ( !v53 )
              p_mChild1 = 0i64;
            UFG::qSafePointer<Creature,Creature>::operator=(&ray_hit_object.simComponent, p_mChild1);
            ray_hit_object.raycastCallback = (void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, void *))TargetVisibleCondition::AsyncRayCallback;
            v56 = this->m_MyRoot.mOffset;
            if ( v56 )
              v57 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v56);
            else
              v57 = 0i64;
            if ( v56 )
              v58 = (char *)&this->m_MyRoot + v56;
            else
              v58 = 0i64;
            v59 = context->mActionTreeComponentBase[v58[236]];
            if ( !v59 )
              v59 = context->mActionTreeComponentBase[1];
            UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
              v59,
              v57,
              (ActionNodeRoot *)this->m_TargetObjectUID,
              v10);
            v60 = this->m_DebugDraw != 0;
            v61 = this->m_FixZForCharacter != 0;
            v62 = *(UFG::SimObject **)(m_pTransformNodeComponent + 40);
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)ray_hit_object.mInput.m_from.m_quad.m128_u64[1]);
            UFG::DoRaycast(
              v50,
              (UFG::qVector3 *)(ray_hit_object.mInput.m_from.m_quad.m128_u64[1] + 176),
              v62,
              1.5,
              v61,
              0i64,
              (UFG::SimObject **)&ray_hit_object.mInput.m_enableShapeCollectionFilter,
              &ray_hit_object,
              v60,
              &this->m_DebugDrawColour);
            ray_hit_object.mInput.m_to.m_quad.m128_u64[1] = (unsigned __int64)&ray_hit_object.UFG::CastData;
            if ( ray_hit_object.simComponent.m_pPointer )
            {
              v63 = ray_hit_object.simComponent.mPrev;
              v64 = ray_hit_object.simComponent.mNext;
              ray_hit_object.simComponent.mPrev->mNext = ray_hit_object.simComponent.mNext;
              v64->mPrev = v63;
              ray_hit_object.simComponent.mPrev = &ray_hit_object.simComponent;
              ray_hit_object.simComponent.mNext = &ray_hit_object.simComponent;
            }
            ray_hit_object.simComponent.m_pPointer = 0i64;
            goto LABEL_122;
          }
          v53 = context->mActionTreeComponentBase[3];
        }
        p_mChild1 = (UFG::SimComponent *)&v53[-1].mActionTreeMemoryDataStructs.mTree.mRoot.mChild1;
        goto LABEL_109;
      }
    }
  }
LABEL_123:
  LOBYTE(value_uid) = 0;
  *(float *)v81 = -99999.0;
  v67 = this->m_MyRoot.mOffset;
  if ( v67 )
    v68 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v67);
  else
    v68 = 0i64;
  if ( v67 )
    v69 = (char *)&this->m_MyRoot + v67;
  else
    v69 = 0i64;
  v70 = context->mActionTreeComponentBase[v69[236]];
  if ( !v70 )
    v70 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v70,
    v68,
    (ActionNodeRoot *)this->m_TargetIsVisibleUID,
    (bool *)&value_uid);
  v71 = this->m_MyRoot.mOffset;
  if ( v71 )
    v72 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v71);
  else
    v72 = 0i64;
  if ( v71 )
    v73 = (char *)&this->m_MyRoot + v71;
  else
    v73 = 0i64;
  v74 = context->mActionTreeComponentBase[v73[236]];
  if ( !v74 )
    v74 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v74,
    v72,
    (ActionNodeRoot *)this->m_TimeTargetBecameVisibleUID,
    v81);
  if ( (_BYTE)value_uid || mSimTime_Temp < (float)(*(float *)v81 + this->m_NumSecondsToContinueAfterTargetFirstVisible) )
    return 1;
  return v6;
}

// File Line: 2713
// RVA: 0x14AE7A0
__int64 dynamic_initializer_for__TargetKnowledgeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetKnowledgeCondition", 0xFFFFFFFF);
  TargetKnowledgeCondition::sClassNameUID = result;
  return result;
}

// File Line: 2726
// RVA: 0x332620
void __fastcall TargetKnowledgeCondition::TargetKnowledgeCondition(TargetKnowledgeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetKnowledgeCondition::`vftable;
  this->m_TargetType = 0;
  *(_WORD *)&this->m_HasEverSeen = 0;
  this->m_CanPathTo = 0;
}

// File Line: 2730
// RVA: 0x373130
bool __fastcall TargetKnowledgeCondition::Match(TargetKnowledgeCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rdi
  UFG::SimObjectCVBase *v9; // rcx
  unsigned int v10; // ebx
  UFG::ActiveAIEntityComponent *v11; // rax
  __int16 v12; // dx
  unsigned int size; // ecx
  UFG::PedKnowledgeRecord *p; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)((unsigned int)this->m_TargetType
                                               + *(_QWORD *)&m_pComponent[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  if ( !v8 )
    return 0;
  v9 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v10 = 0;
  if ( v9 )
  {
    v12 = v9->m_Flags;
    if ( (v12 & 0x4000) != 0 || v12 < 0 )
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    else
      v11 = (UFG::ActiveAIEntityComponent *)((v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v9,
                                               UFG::ActiveAIEntityComponent::_TypeUID)
                                           : UFG::SimObject::GetComponentOfType(
                                               v9,
                                               UFG::ActiveAIEntityComponent::_TypeUID));
  }
  else
  {
    v11 = 0i64;
  }
  size = v11->m_KnowledgeBase.m_aHostilePedRecords.size;
  if ( size )
  {
    p = v11->m_KnowledgeBase.m_aHostilePedRecords.p;
    while ( v8 != p->pSimObject.m_pPointer )
    {
      ++v10;
      ++p;
      if ( v10 >= size )
        goto LABEL_26;
    }
  }
  else
  {
LABEL_26:
    p = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
  }
  return p->pSimObject.m_pPointer
      && (this->m_CanSee && (*((_BYTE *)p + 48) & 1) != 0
       || this->m_HasEverSeen && (*((_BYTE *)p + 48) & 2) != 0
       || this->m_CanPathTo && (*((_BYTE *)p + 48) & 4) != 0);
}

// File Line: 2788
// RVA: 0x14AE220
__int64 dynamic_initializer_for__IsOnScreenCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsOnScreenCondition", 0xFFFFFFFF);
  IsOnScreenCondition::sClassNameUID = result;
  return result;
}

// File Line: 2791
// RVA: 0x371040
bool __fastcall IsOnScreenCondition::Match(IsOnScreenCondition *this, ActionContext *context)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::Camera *mCurrentCamera; // rcx
  UFG::qVector3 result; // [rsp+30h] [rbp-18h] BYREF
  bool is_on_screen; // [rsp+58h] [rbp+10h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+60h] [rbp+18h] BYREF

  m_pPointer = context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  viewport_scale.x = 1.0;
  viewport_scale.y = 1.0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  mCurrentCamera = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::Camera *)((char *)mCurrentCamera + 80);
  UFG::Camera::GetScreenCoord(
    mCurrentCamera,
    &result,
    (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
    &viewport_scale,
    &is_on_screen);
  return is_on_screen;
}

// File Line: 2816
// RVA: 0x14B3070
__int64 dynamic_initializer_for__gRangePerferenceEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gRangePerferenceEnum,
    UFG::FormationRangePreferenceNames,
    5,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gRangePerferenceEnum__);
}

// File Line: 2818
// RVA: 0x14ADEC0
__int64 dynamic_initializer_for__GetInFormationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GetInFormationCondition", 0xFFFFFFFF);
  GetInFormationCondition::sClassNameUID = result;
  return result;
}

// File Line: 2829
// RVA: 0x32EBD0
void __fastcall GetInFormationCondition::GetInFormationCondition(GetInFormationCondition *this)
{
  Condition::Condition(this);
  this->mPrev = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->mNext = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&GetInFormationCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&GetInFormationCondition::`vftable{for `IConditionInit};
  *(_WORD *)&this->m_TargetType.mValue = 22;
  this->m_AttackType.mValue = 0;
  this->m_ActionPath.mPath.mCount = 0;
  this->m_ActionPath.mPath.mData.mOffset = 0i64;
  this->m_GetInFormationNodeUID = 0;
}

// File Line: 2834
// RVA: 0x3373C0
void __fastcall GetInFormationCondition::~GetInFormationCondition(GetInFormationCondition *this)
{
  IConditionInit *v2; // rsi
  ActionPath *p_m_ActionPath; // rbx
  __int64 mOffset; // rax
  __int64 v5; // rax
  char *v6; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mNext; // rax

  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&GetInFormationCondition::`vftable{for `Condition};
  v2 = &this->IConditionInit;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&GetInFormationCondition::`vftable{for `IConditionInit};
  p_m_ActionPath = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    mOffset = this->m_ActionPath.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_m_ActionPath->mPath.mData + mOffset) )
    {
      v5 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v5 )
        v6 = (char *)&this->m_ActionPath.mPath.mData + v5;
      else
        v6 = 0i64;
      operator delete[](v6);
    }
    p_m_ActionPath->mPath.mData.mOffset = 0i64;
    p_m_ActionPath->mPath.mCount &= 0x80000000;
  }
  mPrev = v2->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = &v2->UFG::qNode<IConditionInit,IConditionInit>;
  v2->mNext = &v2->UFG::qNode<IConditionInit,IConditionInit>;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 2839
// RVA: 0x383120
void __fastcall GetInFormationCondition::ResolveReferences(GetInFormationCondition *this, ActionNode *action_node)
{
  ActionNodeRoot *v3; // rax
  ActionNodeRoot *v4; // rdi
  IConditionInit *v5; // rdx
  __int64 v6; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx

  v3 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  v4 = v3;
  if ( this )
    v5 = &this->IConditionInit;
  else
    v5 = 0i64;
  ActionNodeRoot::AddToInitList(v3, v5);
  v6 = (__int64)v4->vfptr[1].GetResourceOwner(v4);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v6 )
    v6 -= (__int64)p_m_MyRoot;
  p_m_MyRoot->mOffset = v6;
  this->m_GetInFormationNodeUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                    this->m_GetInFormationNodeUID,
                                    eACTION_TREE_MEMORY_ELEMENT_GET_IN_FORMATION_NODE_POINTER);
}

// File Line: 2862
// RVA: 0x365C60
void __fastcall GetInFormationCondition::Init(GetInFormationCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::GetInFormationComponent *m_pComponent; // rsi
  UFG::SimComponent *v7; // rax
  qEnum<enum UFG::eTargetTypeEnum,unsigned char> *v8; // rbx
  __int64 v9; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  qEnum<enum UFG::eTargetTypeEnum,unsigned char> *v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  UFG::GetInFormationNode *NewNode; // r9
  __int64 v14; // rcx
  UFG::ActionTreeComponentBase *v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  UFG::GetInFormationNode *value_uid; // [rsp+48h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::GetInFormationComponent *)m_pPointer->m_Components.p[32].m_pComponent;
    }
    else
    {
      v7 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GetInFormationComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GetInFormationComponent::_TypeUID);
      m_pComponent = (UFG::GetInFormationComponent *)v7;
    }
    if ( m_pComponent )
    {
      v8 = 0i64;
      value_uid = 0i64;
      v9 = *(_QWORD *)&this->m_TargetType.mValue;
      if ( v9 )
        v10 = (UFG::ActionTreeComponentBase *)(&this->m_TargetType.mValue + v9);
      else
        v10 = 0i64;
      if ( v9 )
        v11 = &this->m_TargetType + v9;
      else
        v11 = 0i64;
      v12 = action_context->mActionTreeComponentBase[v11[236].mValue];
      if ( !v12 )
        v12 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInFormationNode *>(
        v12,
        v10,
        (ActionNodeRoot *)HIDWORD(this->IConditionInit::vfptr),
        &value_uid);
      if ( value_uid )
      {
        UFG::GetInFormationNode::ReInit(
          value_uid,
          (UFG::eFormationRangePreference)BYTE1(this->IConditionInit::vfptr),
          (UFG::eAttackType)BYTE2(this->IConditionInit::vfptr),
          (UFG::eTargetTypeEnum)LOBYTE(this->IConditionInit::vfptr));
      }
      else
      {
        if ( (_S24 & 1) == 0 )
        {
          _S24 |= 1u;
          name_uid = UFG::qStringHash32("GetInFormationComponent", 0xFFFFFFFF);
        }
        NewNode = UFG::GetInFormationComponent::MakeNewNode(
                    m_pComponent,
                    (UFG::eFormationRangePreference)BYTE1(this->IConditionInit::vfptr),
                    (UFG::eAttackType)BYTE2(this->IConditionInit::vfptr),
                    (UFG::eTargetTypeEnum)LOBYTE(this->IConditionInit::vfptr));
        v14 = *(_QWORD *)&this->m_TargetType.mValue;
        if ( v14 )
          v15 = (UFG::ActionTreeComponentBase *)(&this->m_TargetType.mValue + v14);
        else
          v15 = 0i64;
        if ( v14 )
          v8 = &this->m_TargetType + v14;
        v16 = action_context->mActionTreeComponentBase[v8[236].mValue];
        if ( !v16 )
          v16 = action_context->mActionTreeComponentBase[1];
        UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::GetInFormationNode *>(
          v16,
          v15,
          (ActionNodeRoot *)HIDWORD(this->IConditionInit::vfptr),
          NewNode);
      }
    }
  }
}

// File Line: 2909
// RVA: 0x34C0E0
bool __fastcall GetInPedFormationCondition::CanGetInPedFormation(
        GetInPedFormationCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::ActionTreeComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v7; // rcx
  UFG::HealthComponent *ComponentOfType; // rax
  __int16 v9; // dx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::ActionTreeComponent *)m_pPointer->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::ActionTreeComponent *)m_pPointer->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
        m_pComponent = (UFG::ActionTreeComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = (UFG::ActionTreeComponent *)m_pPointer->m_Components.p[7].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v7 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 & 0x4000) != 0 )
    {
      ComponentOfType = (UFG::HealthComponent *)v7->m_Components.p[6].m_pComponent;
    }
    else if ( v9 >= 0 )
    {
      if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
        ComponentOfType = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v7,
                                                    UFG::HealthComponent::_TypeUID);
      else
        ComponentOfType = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(v7, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::HealthComponent *)v7->m_Components.p[6].m_pComponent;
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
  return !UFG::IsDowned(m_pComponent, ComponentOfType) && !UFG::IsStunned(m_pComponent);
}

// File Line: 2925
// RVA: 0x36FC30
bool __fastcall GetInFormationCondition::Match(GetInFormationCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v5; // rdx
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::GetInFormationNode *v8; // r8
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r9
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::FormationManagerComponent *v16; // rbx
  UFG::SimComponent *v17; // rax
  UFG::GetInFormationNode *v18; // rdi
  char v19; // al
  UFG::GetInFormationNode *v20; // rdi
  int DesiredRange; // edi
  UFG::GetInFormationNode *value_uid; // [rsp+30h] [rbp+8h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  value_uid = 0i64;
  if ( mOffset )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v5 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->m_MyRoot + mOffset;
  else
    v6 = 0i64;
  v7 = context->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInFormationNode *>(
    v7,
    v5,
    (ActionNodeRoot *)this->m_GetInFormationNodeUID,
    &value_uid);
  v8 = value_uid;
  if ( !value_uid )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_46;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v12 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    v8 = value_uid;
    m_pComponent = v12;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent
    || (v13 = *(UFG::SimObjectGame **)(56i64
                                     * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                          + *(_QWORD *)&m_pComponent[1].m_Flags
                                                          + 8i64)
                                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                     + 40)) == 0i64
    || ((v14 = v13->m_Flags, (v14 & 0x4000) == 0) && v14 >= 0 && (v14 & 0x2000) == 0 && (v14 & 0x1000) == 0
      ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::FormationManagerComponent::_TypeUID))
      : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID)),
        (v8 = value_uid, (v16 = (UFG::FormationManagerComponent *)ComponentOfType) == 0i64) || !value_uid) )
  {
LABEL_46:
    UFG::GetInFormationNode::UnregisterFromFormationManager(v8);
    return 0;
  }
  v17 = value_uid->m_pTargetFormationManagerComponent.m_pPointer;
  if ( v17 && v16 != v17 )
    UFG::GetInFormationNode::UnregisterFromFormationManager(value_uid);
  if ( !GetInPedFormationCondition::CanGetInPedFormation((GetInPedFormationCondition *)this, context) )
    return 0;
  v18 = value_uid;
  v19 = UFG::GetInFormationNode::IsAtRangePreference(value_uid);
  if ( v19 && !v18->m_PrevIsAtRangePreference )
  {
    v18->m_JustGotToRangePreference = 1;
    v18 = value_uid;
  }
  v18->m_PrevIsAtRangePreference = v19;
  if ( v19 )
    goto LABEL_42;
  v20 = value_uid;
  if ( value_uid->m_AllowedToSwitchToRangePreference )
  {
    DesiredRange = UFG::FormationManagerComponent::GetDesiredRange(v16, value_uid);
    if ( UFG::FormationManagerComponent::RangeMeetsPreference(
           v16,
           DesiredRange,
           (UFG::eFormationRangePreference)(unsigned __int8)this->m_RangePreference.mValue) )
    {
      UFG::FormationManagerComponent::Reregister(v16, value_uid, DesiredRange, 1);
    }
LABEL_42:
    v20 = value_uid;
  }
  if ( UFG::FormationManagerComponent::IsRegistered(v16, v20) )
  {
    UFG::GetInFormationNode::SetTargetFormationManagerComponent(v20, v16);
    return !UFG::FormationManagerComponent::IsInFormation(v16, value_uid);
  }
  UFG::FormationManagerComponent::RequestRegistration(v16, v20);
  return 0;
}

// File Line: 3054
// RVA: 0x14ADF00
__int64 dynamic_initializer_for__GetInPedFormationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GetInPedFormationCondition", 0xFFFFFFFF);
  GetInPedFormationCondition::sClassNameUID = result;
  return result;
}

// File Line: 3062
// RVA: 0x32EFC0
void __fastcall GetInPedFormationCondition::GetInPedFormationCondition(GetInPedFormationCondition *this)
{
  Condition::Condition(this);
  this->mPrev = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->mNext = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&GetInPedFormationCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&GetInPedFormationCondition::`vftable{for `IConditionInit};
  this->m_TargetType.mValue = 62;
  this->m_ActionPath.mPath.mCount = 0;
  this->m_ActionPath.mPath.mData.mOffset = 0i64;
  this->m_MyRoot.mOffset = 0i64;
  this->m_GetInPedFormationNodeUID = 0;
}

// File Line: 3068
// RVA: 0x337910
void __fastcall GetInPedFormationCondition::~GetInPedFormationCondition(GetInPedFormationCondition *this)
{
  IConditionInit *v2; // rsi
  ActionPath *p_m_ActionPath; // rbx
  __int64 mOffset; // rax
  __int64 v5; // rax
  char *v6; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mNext; // rax

  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&GetInPedFormationCondition::`vftable{for `Condition};
  v2 = &this->IConditionInit;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&GetInPedFormationCondition::`vftable{for `IConditionInit};
  p_m_ActionPath = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    mOffset = this->m_ActionPath.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_m_ActionPath->mPath.mData + mOffset) )
    {
      v5 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v5 )
        v6 = (char *)&this->m_ActionPath.mPath.mData + v5;
      else
        v6 = 0i64;
      operator delete[](v6);
    }
    p_m_ActionPath->mPath.mData.mOffset = 0i64;
    p_m_ActionPath->mPath.mCount &= 0x80000000;
  }
  mPrev = v2->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = &v2->UFG::qNode<IConditionInit,IConditionInit>;
  v2->mNext = &v2->UFG::qNode<IConditionInit,IConditionInit>;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 3073
// RVA: 0x383230
void __fastcall GetInPedFormationCondition::ResolveReferences(
        GetInPedFormationCondition *this,
        ActionNode *action_node)
{
  ActionNodeRoot *v3; // rax
  ActionNodeRoot *v4; // rdi
  IConditionInit *v5; // rdx
  __int64 v6; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx

  v3 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  v4 = v3;
  if ( this )
    v5 = &this->IConditionInit;
  else
    v5 = 0i64;
  ActionNodeRoot::AddToInitList(v3, v5);
  v6 = (__int64)v4->vfptr[1].GetResourceOwner(v4);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v6 )
    v6 -= (__int64)p_m_MyRoot;
  p_m_MyRoot->mOffset = v6;
  this->m_GetInPedFormationNodeUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                       this->m_GetInPedFormationNodeUID,
                                       eACTION_TREE_MEMORY_ELEMENT_GET_IN_PED_FORMATION_NODE_POINTER);
}

// File Line: 3096
// RVA: 0x365E10
void __fastcall GetInPedFormationCondition::Init(GetInPedFormationCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::GetInPedFormationComponent *m_pComponent; // rdi
  UFG::SimComponent *v7; // rax
  qEnum<enum UFG::eTargetTypeEnum,unsigned char> *v8; // rbx
  __int64 v9; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  qEnum<enum UFG::eTargetTypeEnum,unsigned char> *v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  UFG::GetInPedFormationNode *v13; // rsi
  UFG::GetInPedFormationNode *NewNode; // r9
  __int64 v15; // rcx
  UFG::ActionTreeComponentBase *v16; // rdx
  UFG::ActionTreeComponentBase *v17; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pTargetPedFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::GetInPedFormationNode *value_uid; // [rsp+58h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::GetInPedFormationComponent *)m_pPointer->m_Components.p[34].m_pComponent;
    }
    else
    {
      v7 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GetInPedFormationComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GetInPedFormationComponent::_TypeUID);
      m_pComponent = (UFG::GetInPedFormationComponent *)v7;
    }
    if ( m_pComponent )
    {
      v8 = 0i64;
      value_uid = 0i64;
      v9 = *(_QWORD *)&this->m_TargetType.mValue;
      if ( v9 )
        v10 = (UFG::ActionTreeComponentBase *)(&this->m_TargetType.mValue + v9);
      else
        v10 = 0i64;
      if ( v9 )
        v11 = &this->m_TargetType + v9;
      else
        v11 = 0i64;
      v12 = action_context->mActionTreeComponentBase[v11[236].mValue];
      if ( !v12 )
        v12 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInPedFormationNode *>(
        v12,
        v10,
        (ActionNodeRoot *)HIDWORD(this->IConditionInit::vfptr),
        (UFG::qBaseNodeVariableRB<unsigned __int64> **)&value_uid);
      v13 = value_uid;
      if ( value_uid )
      {
        value_uid->m_Registrator = 0i64;
        UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(v13);
        v13->m_SlotIndex = -1;
        p_m_pTargetPedFormationManagerComponent = &v13->m_pTargetPedFormationManagerComponent;
        if ( v13->m_pTargetPedFormationManagerComponent.m_pPointer )
        {
          mPrev = p_m_pTargetPedFormationManagerComponent->mPrev;
          mNext = v13->m_pTargetPedFormationManagerComponent.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
          v13->m_pTargetPedFormationManagerComponent.mNext = &v13->m_pTargetPedFormationManagerComponent;
        }
        v13->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
      }
      else
      {
        if ( (_S25 & 1) == 0 )
        {
          _S25 |= 1u;
          name_uid_0 = UFG::qStringHash32("GetInPedFormationComponent", 0xFFFFFFFF);
        }
        NewNode = UFG::GetInPedFormationComponent::MakeNewNode(m_pComponent);
        v15 = *(_QWORD *)&this->m_TargetType.mValue;
        if ( v15 )
          v16 = (UFG::ActionTreeComponentBase *)(&this->m_TargetType.mValue + v15);
        else
          v16 = 0i64;
        if ( v15 )
          v8 = &this->m_TargetType + v15;
        v17 = action_context->mActionTreeComponentBase[v8[236].mValue];
        if ( !v17 )
          v17 = action_context->mActionTreeComponentBase[1];
        UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::GetInPedFormationNode *>(
          v17,
          v16,
          (ActionNodeRoot *)HIDWORD(this->IConditionInit::vfptr),
          NewNode);
      }
    }
  }
}

// File Line: 3159
// RVA: 0x36FEC0
bool __fastcall GetInPedFormationCondition::Match(GetInPedFormationCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v5; // rdx
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax
  void *(__fastcall *vecDelDtor)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  __int64 v13; // rdx
  UFG::SimObjectGame *v14; // rcx
  __int64 v15; // rdx
  __int16 v16; // dx
  UFG::PedFormationManagerComponent *v17; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::GetInPedFormationNode *v19; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v20; // rax
  __int64 m_SlotIndex; // rcx
  unsigned __int64 v23; // rax
  __int64 v24; // rcx
  UFG::GetInPedFormationNode *value_uid; // [rsp+30h] [rbp+8h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  value_uid = 0i64;
  if ( mOffset )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v5 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->m_MyRoot + mOffset;
  else
    v6 = 0i64;
  v7 = context->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInPedFormationNode *>(
    v7,
    v5,
    (ActionNodeRoot *)this->m_GetInPedFormationNodeUID,
    (UFG::qBaseNodeVariableRB<unsigned __int64> **)&value_uid);
  if ( !value_uid )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_55;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    goto LABEL_55;
  GroupComponent = UFG::GroupComponent::GetGroupComponent((UFG::SimObjectGame *)context->mSimObject.m_pPointer);
  if ( !GroupComponent )
    goto LABEL_55;
  vecDelDtor = GroupComponent[32].__vecDelDtor;
  if ( !vecDelDtor )
    goto LABEL_55;
  v13 = *((_QWORD *)vecDelDtor + 33);
  v14 = 0i64;
  if ( v13 )
    v14 = *(UFG::SimObjectGame **)(v13 + 192);
  if ( (v15 = *((_QWORD *)vecDelDtor + 28), !v14)
    || !v15
    || !*(_BYTE *)(v15 + 928)
    || ((v16 = v14->m_Flags, (v16 & 0x4000) == 0)
      ? (v16 >= 0 && (v16 & 0x2000) == 0 && (v16 & 0x1000) == 0
       ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v14, UFG::PedFormationManagerComponent::_TypeUID))
       : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::PedFormationManagerComponent::_TypeUID)),
         v17 = (UFG::PedFormationManagerComponent *)ComponentOfType)
      : (v17 = (UFG::PedFormationManagerComponent *)v14->m_Components.p[33].m_pComponent),
        !v17) )
  {
LABEL_55:
    v19 = value_uid;
    goto LABEL_56;
  }
  v19 = value_uid;
  if ( !value_uid )
  {
LABEL_56:
    UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(v19);
    return 0;
  }
  v20 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)value_uid->m_pTargetPedFormationManagerComponent.m_pPointer;
  if ( v20 && v17 != (UFG::PedFormationManagerComponent *)v20 )
    UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(value_uid);
  if ( GetInPedFormationCondition::CanGetInPedFormation(this, context) )
  {
    if ( !value_uid )
      goto LABEL_60;
    m_SlotIndex = (unsigned int)value_uid->m_SlotIndex;
    if ( (_DWORD)m_SlotIndex == -1 )
      goto LABEL_60;
    if ( (unsigned int)m_SlotIndex < v17->m_Slots.size && v17->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer == value_uid )
    {
      UFG::GetInPedFormationNode::SetTargetPedFormationManagerComponent(value_uid, v17);
      return !UFG::PedFormationManagerComponent::IsInPedFormation(v17, value_uid);
    }
    if ( (unsigned int)m_SlotIndex >= v17->m_Slots.size || v17->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer != value_uid )
    {
LABEL_60:
      if ( v17->m_pTransformNodeComponent.m_pSimComponent )
      {
        v23 = (unsigned __int64)value_uid->m_pOwner.m_pPointer;
        if ( v23 )
        {
          v24 = *(_QWORD *)(v23 + 40);
          if ( v24 )
          {
            if ( *(_QWORD *)(v24 + 88) )
            {
              if ( v17->m_NumFreeSlots )
                UFG::PedFormationManagerComponent::Register(v17, value_uid);
            }
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 3267
// RVA: 0x14AD800
__int64 dynamic_initializer_for__AIIsStandingBetweenAttackerAndTarget::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIIsStandingBetweenAttackerAndTarget", 0xFFFFFFFF);
  AIIsStandingBetweenAttackerAndTarget::sClassNameUID = result;
  return result;
}

// File Line: 3279
// RVA: 0x32B6B0
void __fastcall AIIsStandingBetweenAttackerAndTarget::AIIsStandingBetweenAttackerAndTarget(
        AIIsStandingBetweenAttackerAndTarget *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AIIsStandingBetweenAttackerAndTarget::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 22;
  this->m_MaxDistance = 8.0;
  this->m_MaxAngle = 0.89999998;
}

// File Line: 3284
// RVA: 0x36E750
bool __fastcall AIIsStandingBetweenAttackerAndTarget::Match(
        AIIsStandingBetweenAttackerAndTarget *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  __int64 m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rbx
  __int16 v9; // cx
  UFG::AttackRightsComponent *v10; // rax
  UFG::HasAttackRequestNode *NextAttacker; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimComponent *v13; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimObject *v15; // rcx
  UFG::TransformNodeComponent *v16; // rbp
  UFG::TransformNodeComponent *v17; // rbx
  float x; // xmm12_4
  float y; // xmm13_4
  float z; // xmm14_4
  float v21; // xmm8_4
  __m128 y_low; // xmm9
  float v23; // xmm6_4
  __m128 v24; // xmm5
  float v25; // xmm10_4
  float v26; // xmm7_4
  float v27; // xmm11_4
  float v28; // xmm8_4
  float v29; // xmm10_4
  __m128 v30; // xmm3
  float v31; // xmm1_4
  float v32; // xmm6_4
  float v33; // xmm7_4
  float v34; // xmm8_4
  float v35; // xmm9_4
  float v36; // xmm10_4
  __m128 v37; // xmm3
  float v38; // xmm2_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (__int64)m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = (__int64)v7;
  }
  else
  {
    m_pComponent = (__int64)m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                   + *(_QWORD *)(m_pComponent + 96)
                                                   + 8i64)
                              + *(_QWORD *)(m_pComponent + 88)
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    v10 = (UFG::AttackRightsComponent *)v8->m_Components.p[46].m_pComponent;
  else
    v10 = (UFG::AttackRightsComponent *)(v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v8,
                                           UFG::AttackRightsComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(v8, UFG::AttackRightsComponent::_TypeUID));
  if ( !v10 )
    return 0;
  NextAttacker = UFG::AttackRightsComponent::GetNextAttacker(
                   v10,
                   (UFG::eAttackType)(unsigned __int8)this->m_AttackType.mValue,
                   m_pComponent);
  m_pTransformNodeComponent = 0i64;
  if ( NextAttacker && (v13 = NextAttacker->m_pOwner.m_pPointer) != 0i64 )
    m_pSimObject = v13->m_pSimObject;
  else
    m_pSimObject = 0i64;
  if ( !m_pSimObject )
    return 0;
  v15 = context->mSimObject.m_pPointer;
  if ( m_pSimObject == v15 )
    return 0;
  if ( v15 )
    m_pTransformNodeComponent = v15->m_pTransformNodeComponent;
  v16 = m_pSimObject->m_pTransformNodeComponent;
  v17 = v8->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  if ( !v16 )
    return 0;
  if ( !v17 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  UFG::TransformNodeComponent::UpdateWorldTransform(v16);
  UFG::TransformNodeComponent::UpdateWorldTransform(v17);
  x = v16->mWorldTransform.v3.x;
  y = v16->mWorldTransform.v3.y;
  z = v16->mWorldTransform.v3.z;
  v21 = m_pTransformNodeComponent->mWorldTransform.v3.x;
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
  v23 = v17->mWorldTransform.v3.x;
  v24 = (__m128)LODWORD(v17->mWorldTransform.v3.y);
  v25 = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v26 = v17->mWorldTransform.v3.z;
  v27 = (float)((float)((float)(y - v24.m128_f32[0]) * (float)(y - v24.m128_f32[0]))
              + (float)((float)(x - v23) * (float)(x - v23)))
      + (float)((float)(z - v26) * (float)(z - v26));
  if ( (float)((float)((float)((float)(y - y_low.m128_f32[0]) * (float)(y - y_low.m128_f32[0]))
                     + (float)((float)(x - v21) * (float)(x - v21)))
             + (float)((float)(z - v25) * (float)(z - v25))) > v27
    || v27 > (float)(this->m_MaxDistance * this->m_MaxDistance) )
  {
    return 0;
  }
  v28 = v21 - x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - y;
  v30 = y_low;
  v29 = v25 - z;
  v30.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v28 * v28)) + (float)(v29 * v29);
  v31 = v30.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
  v32 = v23 - x;
  v24.m128_f32[0] = v24.m128_f32[0] - y;
  v33 = v26 - z;
  v34 = v28 * v31;
  v35 = y_low.m128_f32[0] * v31;
  v36 = v29 * v31;
  v37 = v24;
  v37.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v32 * v32)) + (float)(v33 * v33);
  v38 = v37.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v37).m128_f32[0];
  return (float)((float)((float)((float)(v24.m128_f32[0] * v38) * v35) + (float)((float)(v32 * v38) * v34))
               + (float)((float)(v33 * v38) * v36)) > this->m_MaxAngle;
}

// File Line: 3375
// RVA: 0x14B3040
__int64 dynamic_initializer_for__gNextAttackerWeaponTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gNextAttackerWeaponTypeEnum,
    NextAttackerWeaponTypeNames,
    4,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gNextAttackerWeaponTypeEnum__);
}

// File Line: 3377
// RVA: 0x14AE380
__int64 dynamic_initializer_for__NextAttackerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NextAttackerCondition", 0xFFFFFFFF);
  NextAttackerCondition::sClassNameUID = result;
  return result;
}

// File Line: 3383
// RVA: 0x3309A0
void __fastcall NextAttackerCondition::NextAttackerCondition(NextAttackerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&NextAttackerCondition::`vftable;
  this->m_WeaponType.mValue = 0;
}

// File Line: 3388
// RVA: 0x371380
char __fastcall NextAttackerCondition::Match(NextAttackerCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rdx
  char v9; // bl
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::SimObjectProp *v11; // rcx
  __int16 v12; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  bool mIsBladed; // si
  bool v15; // al
  char mValue; // cl

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = m_pPointer->m_Components.p[46].m_pComponent;
  else
    m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AttackRightsComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AttackRightsComponent::_TypeUID);
  if ( !m_pComponent )
    return 0;
  mPrev = m_pComponent[160].m_SafePointerList.mNode.mPrev;
  if ( !mPrev )
    return 0;
  if ( !this->m_WeaponType.mValue )
    return 1;
  mNext = mPrev[13].mNext;
  v9 = 0;
  if ( mNext )
    v10 = mNext[9].mNext;
  else
    v10 = 0i64;
  v11 = (UFG::SimObjectProp *)*((_QWORD *)&v10[5].mNext[2].mNext + 7 * BYTE1(v10[6].mPrev[1].mNext));
  if ( !v11 )
    return this->m_WeaponType.mValue == 1;
  v12 = v11->m_Flags;
  if ( (v12 & 0x4000) != 0 || v12 < 0 )
    goto LABEL_24;
  if ( (v12 & 0x2000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v11);
    goto LABEL_26;
  }
  if ( (v12 & 0x1000) != 0 )
LABEL_24:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v11,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v11,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_26:
  if ( !ComponentOfTypeHK )
    return this->m_WeaponType.mValue == 1;
  mIsBladed = ComponentOfTypeHK->mIsBladed;
  v15 = ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID
     && UFG::SimObjectWeaponPropertiesComponent::HasAmmo(ComponentOfTypeHK);
  mValue = this->m_WeaponType.mValue;
  if ( mValue == 2 && mIsBladed || mValue == 3 && v15 )
    return 1;
  return v9;
}

// File Line: 3448
// RVA: 0x14B8FB0
const char *dynamic_initializer_for__sCanAttackConditionGroupFactoryList__()
{
  const char *result; // rax

  sCanAttackConditionGroupFactoryList[0].mClassName = FalseCondition::sClassName;
  sCanAttackConditionGroupFactoryList[1].mClassName = NotCondition::sClassName;
  sCanAttackConditionGroupFactoryList[2].mClassName = ORCondition::sClassName;
  sCanAttackConditionGroupFactoryList[3].mClassName = ConditionGroup::sClassName;
  sCanAttackConditionGroupFactoryList[4].mClassName = IsPlayingCondition::sClassName;
  sCanAttackConditionGroupFactoryList[5].mClassName = IsPlayingThisCondition::sClassName;
  sCanAttackConditionGroupFactoryList[6].mClassName = IsPlayingNodeCondition::sClassName;
  sCanAttackConditionGroupFactoryList[7].mClassName = TargetDistance::sClassName;
  sCanAttackConditionGroupFactoryList[8].mClassName = TargetConditionGroup::sClassName;
  sCanAttackConditionGroupFactoryList[9].mClassName = TargetRelativePosition::sClassName;
  sCanAttackConditionGroupFactoryList[10].mClassName = TargetRelativeOrientationCondition::sClassName;
  sCanAttackConditionGroupFactoryList[11].mClassName = TargetValidCondition::sClassName;
  sCanAttackConditionGroupFactoryList[12].mClassName = TargetDistanceHysteresis::sClassName;
  sCanAttackConditionGroupFactoryList[13].mClassName = TargetVisibleCondition::sClassName;
  sCanAttackConditionGroupFactoryList[14].mClassName = TargetVisibleInAIDataCondition::sClassName;
  sCanAttackConditionGroupFactoryList[15].mClassName = TargetIsPlayingCondition::sClassName;
  sCanAttackConditionGroupFactoryList[16].mClassName = TargetIsLockedCondition::sClassName;
  sCanAttackConditionGroupFactoryList[17].mClassName = CooldownCondition::sClassName;
  sCanAttackConditionGroupFactoryList[18].mClassName = ReceivedStimulusCondition::sClassName;
  sCanAttackConditionGroupFactoryList[19].mClassName = IsOnScreenCondition::sClassName;
  sCanAttackConditionGroupFactoryList[20].mClassName = IsAtRangePreferenceCondition::sClassName;
  sCanAttackConditionGroupFactoryList[21].mClassName = SkookumCondition::sClassName;
  sCanAttackConditionGroupFactoryList[22].mClassName = HasRangedWeaponEquippedWithAmmoCondition::sClassName;
  result = AiBehaviourCondition::sClassName;
  sCanAttackConditionGroupFactoryList[23].mClassName = AiBehaviourCondition::sClassName;
  return result;
}

// File Line: 3452
// RVA: 0x14B2F20
__int64 dynamic_initializer_for__gCanAttackConditionFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gCanAttackConditionFactory, sCanAttackConditionGroupFactoryList, 24);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gCanAttackConditionFactory__);
}

// File Line: 3454
// RVA: 0x14ADAC0
__int64 dynamic_initializer_for__CanAttackConditionGroup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CanAttackConditionGroup", 0xFFFFFFFF);
  CanAttackConditionGroup::sClassNameUID = result;
  return result;
}

// File Line: 3468
// RVA: 0x14AE200
__int64 dynamic_initializer_for__IsNextAttackerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsNextAttackerCondition", 0xFFFFFFFF);
  IsNextAttackerCondition::sClassNameUID = result;
  return result;
}

// File Line: 3477
// RVA: 0x330280
void __fastcall IsNextAttackerCondition::IsNextAttackerCondition(IsNextAttackerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNextAttackerCondition::`vftable;
  *(_WORD *)&this->m_AttackType.mValue = 5632;
}

// File Line: 3482
// RVA: 0x338FD0
void __fastcall IsNextAttackerCondition::~IsNextAttackerCondition(IsNextAttackerCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNextAttackerCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 3492
// RVA: 0x359E20
UFG::AttackRightsComponent *__fastcall IsNextAttackerCondition::GetAttackTarget(
        IsNextAttackerCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObject *v6; // r9
  __int16 v7; // cx
  unsigned int v9; // edx
  UFG::SimObjectGame *v10; // rcx
  bool v11; // zf

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v6 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 & 0x4000) != 0 )
          return (UFG::AttackRightsComponent *)v6->m_Components.p[46].m_pComponent;
        if ( v7 < 0 || (v7 & 0x2000) != 0 )
        {
          v9 = UFG::AttackRightsComponent::_TypeUID;
          v10 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                       + 40);
        }
        else
        {
          v9 = UFG::AttackRightsComponent::_TypeUID;
          v11 = (v7 & 0x1000) == 0;
          v10 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                       + 40);
          if ( v11 )
            return (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                                   v6,
                                                   UFG::AttackRightsComponent::_TypeUID);
        }
        return (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v10, v9);
      }
    }
  }
  return 0i64;
}

// File Line: 3511
// RVA: 0x370FD0
UFG::AttackRightsComponent *__fastcall IsNextAttackerCondition::Match(
        IsNextAttackerCondition *this,
        ActionContext *context)
{
  UFG::AttackRightsComponent *result; // rax
  __int64 v5; // r8
  UFG::HasAttackRequestNode *NextAttacker; // rcx
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimObject *m_pSimObject; // rcx

  result = IsNextAttackerCondition::GetAttackTarget(this, context);
  if ( result )
  {
    NextAttacker = UFG::AttackRightsComponent::GetNextAttacker(
                     result,
                     (UFG::eAttackType)(unsigned __int8)this->m_AttackType.mValue,
                     v5);
    result = 0i64;
    if ( NextAttacker )
    {
      m_pPointer = NextAttacker->m_pOwner.m_pPointer;
      if ( m_pPointer )
        m_pSimObject = m_pPointer->m_pSimObject;
      else
        m_pSimObject = 0i64;
      if ( m_pSimObject == context->mSimObject.m_pPointer )
        return (UFG::AttackRightsComponent *)1;
    }
  }
  return result;
}

// File Line: 3543
// RVA: 0x350CA0
ConditionGroup *__fastcall CanAttackConditionGroup::CreateClone(CanAttackConditionGroup *this)
{
  char *v2; // rax
  ConditionGroup *v3; // rax
  ConditionGroup *v4; // rbx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "CanAttackConditionGroup", 0i64, 1u);
  if ( v2 )
  {
    CanAttackConditionGroup::CanAttackConditionGroup((CanAttackConditionGroup *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  ConditionGroup::CopyFrom(v4, this);
  return v4;
}

// File Line: 3562
// RVA: 0x14B2FB0
__int64 dynamic_initializer_for__gInCoverTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gInCoverTypeEnum, UFG::InCoverTypeNames, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gInCoverTypeEnum__);
}

// File Line: 3563
// RVA: 0x14B2EF0
__int64 dynamic_initializer_for__gAttackerTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gAttackerTypeEnum, UFG::AttackerTypeNames, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAttackerTypeEnum__);
}

// File Line: 3565
// RVA: 0x14AE000
__int64 dynamic_initializer_for__HasAttackRequestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasAttackRequestCondition", 0xFFFFFFFF);
  HasAttackRequestCondition::sClassNameUID = result;
  return result;
}

// File Line: 3584
// RVA: 0x32F870
void __fastcall HasAttackRequestCondition::HasAttackRequestCondition(HasAttackRequestCondition *this)
{
  char *v2; // rax
  __int64 v3; // rax
  UFG::qOffset64<CanAttackConditionGroup *> *p_m_pCanAttackConditions; // rcx
  __int64 v5; // rax

  Condition::Condition(this);
  this->mPrev = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->mNext = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&HasAttackRequestCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&HasAttackRequestCondition::`vftable{for `IConditionInit};
  *(_DWORD *)&this->m_AttackType.mValue = 1441792;
  this->m_CopySecondaryCharacterToTargetType.mValue = 37;
  this->m_ActionPath.mPath.mCount = 0;
  this->m_ActionPath.mPath.mData.mOffset = 0i64;
  this->m_MyRoot.mOffset = 0i64;
  this->m_TimeoutToBeginAttacking = 1.0;
  this->m_HasAttackRequestNodeUID = 0;
  v2 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x48ui64,
         "HasAttackRequestCondition.m_CanAttackConditions",
         0i64,
         1u);
  if ( v2 )
    CanAttackConditionGroup::CanAttackConditionGroup((CanAttackConditionGroup *)v2);
  else
    v3 = 0i64;
  p_m_pCanAttackConditions = &this->m_pCanAttackConditions;
  if ( v3 )
    v5 = v3 - (_QWORD)p_m_pCanAttackConditions;
  else
    v5 = 0i64;
  p_m_pCanAttackConditions->mOffset = v5;
}

// File Line: 3604
// RVA: 0x3382B0
void __fastcall HasAttackRequestCondition::~HasAttackRequestCondition(HasAttackRequestCondition *this)
{
  IConditionInit *v2; // rsi
  __int64 mOffset; // rax
  char *v4; // rcx
  ActionPath *p_m_ActionPath; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  char *v8; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mNext; // rax

  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&HasAttackRequestCondition::`vftable{for `Condition};
  v2 = &this->IConditionInit;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&HasAttackRequestCondition::`vftable{for `IConditionInit};
  mOffset = this->m_pCanAttackConditions.mOffset;
  if ( mOffset )
  {
    v4 = (char *)&this->m_pCanAttackConditions + mOffset;
    if ( v4 )
      (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
  }
  this->m_pCanAttackConditions.mOffset = 0i64;
  p_m_ActionPath = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    v6 = this->m_ActionPath.mPath.mData.mOffset;
    if ( v6 && (UFG::qOffset64<ActionID *> *)((char *)&p_m_ActionPath->mPath.mData + v6) )
    {
      v7 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v7 )
        v8 = (char *)&this->m_ActionPath.mPath.mData + v7;
      else
        v8 = 0i64;
      operator delete[](v8);
    }
    this->m_ActionPath.mPath.mData.mOffset = 0i64;
    p_m_ActionPath->mPath.mCount &= 0x80000000;
  }
  mPrev = v2->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = &v2->UFG::qNode<IConditionInit,IConditionInit>;
  v2->mNext = &v2->UFG::qNode<IConditionInit,IConditionInit>;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 3615
// RVA: 0x350D10
HasAttackRequestCondition *__fastcall HasAttackRequestCondition::CreateClone(HasAttackRequestCondition *this)
{
  char *v2; // rax
  HasAttackRequestCondition *v3; // rax
  HasAttackRequestCondition *v4; // rbx
  __int64 mOffset; // rax
  char *v6; // rcx
  __int64 v7; // rax
  UFG::qOffset64<CanAttackConditionGroup *> *p_m_pCanAttackConditions; // rcx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x68ui64, "HasAttackRequestCondition::CreateClone", 0i64, 1u);
  if ( v2 )
  {
    HasAttackRequestCondition::HasAttackRequestCondition((HasAttackRequestCondition *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  HasAttackRequestCondition::operator=(v4, this);
  mOffset = this->m_pCanAttackConditions.mOffset;
  if ( mOffset && (v6 = (char *)&this->m_pCanAttackConditions + mOffset) != 0i64 )
  {
    v7 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 16i64))(v6);
    p_m_pCanAttackConditions = &v4->m_pCanAttackConditions;
    if ( v7 )
      v7 -= (__int64)p_m_pCanAttackConditions;
    p_m_pCanAttackConditions->mOffset = v7;
  }
  else
  {
    v4->m_pCanAttackConditions.mOffset = 0i64;
  }
  return v4;
}

// File Line: 3652
// RVA: 0x3833A0
void __fastcall HasAttackRequestCondition::ResolveReferences(HasAttackRequestCondition *this, ActionNode *action_node)
{
  __int64 mOffset; // rax
  char *v5; // rdi
  unsigned int v6; // ebx
  char *v7; // r14
  __int64 v8; // rcx
  ActionNodeRoot *v9; // rbx
  __int64 v10; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  __int64 v12; // rax
  fastdelegate::detail::GenericClass *RCX; // rax
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v14[2]; // [rsp+20h] [rbp-28h] BYREF

  mOffset = this->m_pCanAttackConditions.mOffset;
  if ( mOffset )
  {
    v5 = (char *)&this->m_pCanAttackConditions + mOffset;
    if ( v5 )
    {
      v6 = 0;
      v7 = &v5[*((_QWORD *)v5 + 5) + 40];
      if ( (*((_DWORD *)v5 + 8) & 0x7FFFFFFF) != 0 )
      {
        do
        {
          v8 = (__int64)&v7[8 * v6 + *(_QWORD *)&v7[8 * v6]];
          (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v8 + 120i64))(v8, action_node);
          ++v6;
        }
        while ( v6 < (*((_DWORD *)v5 + 8) & 0x7FFFFFFFu) );
      }
    }
  }
  v9 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  ActionNodeRoot::AddToInitList(v9, &this->IConditionInit);
  v10 = (__int64)v9->vfptr[1].GetResourceOwner(v9);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v10 )
    v12 = v10 - (_QWORD)p_m_MyRoot;
  else
    v12 = 0i64;
  p_m_MyRoot->mOffset = v12;
  v14[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))HasAttackRequestCondition::OnMyEnterCallback;
  v14[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  ActionNode::AddOnEnterCallback(action_node, v14);
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v14[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))HasAttackRequestCondition::OnMyExitCallback;
  v14[0].m_Closure.m_pthis = RCX;
  ActionNode::AddOnExitCallback(action_node, v14);
  this->m_HasAttackRequestNodeUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                      this->m_HasAttackRequestNodeUID,
                                      eACTION_TREE_MEMORY_ELEMENT_HAS_ATTACK_REQUEST_NODE_POINTER);
}

// File Line: 3700
// RVA: 0x377AC0
UFG::HasAttackRequestNode *__fastcall HasAttackRequestCondition::ObtainHasAttackRequestNode(
        HasAttackRequestCondition *this,
        ActionContext *action_context)
{
  char *v4; // rdi
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::HasAttackRequestComponent *m_pComponent; // rbx
  UFG::SimComponent *v8; // rax
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  char *v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  UFG::HasAttackRequestNode *result; // rax
  UFG::HasAttackRequestNode *NewNode; // r9
  __int64 v15; // rcx
  UFG::ActionTreeComponentBase *v16; // rdx
  UFG::ActionTreeComponentBase *v17; // rcx
  UFG::HasAttackRequestNode *value_uid; // [rsp+48h] [rbp+10h] BYREF

  v4 = 0i64;
  value_uid = 0i64;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return value_uid;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::HasAttackRequestComponent *)m_pPointer->m_Components.p[35].m_pComponent;
  }
  else
  {
    v8 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HasAttackRequestComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HasAttackRequestComponent::_TypeUID);
    m_pComponent = (UFG::HasAttackRequestComponent *)v8;
  }
  if ( !m_pComponent )
    return value_uid;
  mOffset = this->m_MyRoot.mOffset;
  if ( mOffset )
    v10 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v10 = 0i64;
  if ( mOffset )
    v11 = (char *)&this->m_MyRoot + mOffset;
  else
    v11 = 0i64;
  v12 = action_context->mActionTreeComponentBase[v11[236]];
  if ( !v12 )
    v12 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::HasAttackRequestNode *>(
    v12,
    v10,
    (ActionNodeRoot *)this->m_HasAttackRequestNodeUID,
    &value_uid);
  result = value_uid;
  if ( !value_uid )
  {
    if ( (_S26_0 & 1) == 0 )
    {
      _S26_0 |= 1u;
      name_uid_1 = UFG::qStringHash32("HasAttackRequestNode", 0xFFFFFFFF);
    }
    NewNode = UFG::HasAttackRequestComponent::MakeNewNode(m_pComponent, action_context, this);
    value_uid = NewNode;
    v15 = this->m_MyRoot.mOffset;
    if ( v15 )
      v16 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v15);
    else
      v16 = 0i64;
    if ( v15 )
      v4 = (char *)&this->m_MyRoot + v15;
    v17 = action_context->mActionTreeComponentBase[v4[236]];
    if ( !v17 )
      v17 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::HasAttackRequestNode *>(
      v17,
      v16,
      (ActionNodeRoot *)this->m_HasAttackRequestNodeUID,
      NewNode);
    return value_uid;
  }
  return result;
}

// File Line: 3731
// RVA: 0x366090
void __fastcall HasAttackRequestCondition::Init(HasAttackRequestCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  __int64 v7; // rax
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rdx
  UFG::ActionTreeComponentBase *v10; // rcx
  UFG::HasAttackRequestNode *value_uid; // [rsp+38h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[35].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HasAttackRequestComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HasAttackRequestComponent::_TypeUID);
    if ( m_pComponent )
    {
      v7 = *(_QWORD *)&this->m_HasAttackRequestNodeUID;
      v8 = 0i64;
      value_uid = 0i64;
      if ( v7 )
        v9 = (UFG::ActionTreeComponentBase *)((char *)&this->m_HasAttackRequestNodeUID + v7);
      else
        v9 = 0i64;
      if ( v7 )
        v8 = (char *)&this->m_HasAttackRequestNodeUID + v7;
      v10 = action_context->mActionTreeComponentBase[v8[236]];
      if ( !v10 )
        v10 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::HasAttackRequestNode *>(
        v10,
        v9,
        (ActionNodeRoot *)*(unsigned int *)&this->m_AttackType.mValue,
        &value_uid);
      if ( value_uid )
        UFG::HasAttackRequestNode::ReInit(value_uid, action_context, (HasAttackRequestCondition *)((char *)this - 24));
    }
  }
}

// File Line: 3758
// RVA: 0x37B5F0
void __fastcall HasAttackRequestCondition::OnMyEnterCallback(
        HasAttackRequestCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  UFG::HasAttackRequestNode *v3; // rax

  v3 = HasAttackRequestCondition::ObtainHasAttackRequestNode(this, action_context);
  if ( v3 )
    v3->m_CurrentlyAttacking = 1;
}

// File Line: 3772
// RVA: 0x37B750
void __fastcall HasAttackRequestCondition::OnMyExitCallback(
        HasAttackRequestCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  UFG::HasAttackRequestNode *v3; // rax
  UFG::HasAttackRequestNode *v4; // rbx

  v3 = HasAttackRequestCondition::ObtainHasAttackRequestNode(this, action_context);
  v4 = v3;
  if ( v3 )
  {
    UFG::HasAttackRequestNode::FinishedAttacking(v3);
    v4->m_CurrentlyAttacking = 0;
    v4->m_TimeFinishedAttacking = UFG::Metrics::msInstance.mSimTime_Temp;
  }
}

// File Line: 3786
// RVA: 0x359C60
UFG::AttackRightsComponent *__fastcall HasAttackRequestCondition::GetAttackTarget(
        HasAttackRequestCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObject *v6; // r9
  __int16 v7; // cx
  unsigned int v9; // edx
  UFG::SimObjectGame *v10; // rcx
  bool v11; // zf

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v6 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 & 0x4000) != 0 )
          return (UFG::AttackRightsComponent *)v6->m_Components.p[46].m_pComponent;
        if ( v7 < 0 || (v7 & 0x2000) != 0 )
        {
          v9 = UFG::AttackRightsComponent::_TypeUID;
          v10 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                       + 40);
        }
        else
        {
          v9 = UFG::AttackRightsComponent::_TypeUID;
          v11 = (v7 & 0x1000) == 0;
          v10 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                       + 40);
          if ( v11 )
            return (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                                   v6,
                                                   UFG::AttackRightsComponent::_TypeUID);
        }
        return (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v10, v9);
      }
    }
  }
  return 0i64;
}

// File Line: 3816
// RVA: 0x370360
char __fastcall HasAttackRequestCondition::Match(HasAttackRequestCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  char *v5; // rcx
  char result; // al
  UFG::HasAttackRequestNode *v7; // rax
  UFG::HasAttackRequestNode *v8; // rbx
  CanAttackConditionGroup *m_pPointer; // rcx
  char v10; // al
  float mSimTime_Temp; // xmm6_4
  UFG::SimComponent *v12; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_m_pAttackeeRequest; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::AttackRightsComponent *AttackTarget; // rax
  char mValue; // cl

  if ( UFG::AttackRightsComponent::s_DisableRangedAttackRights && this->m_AttackType.mValue == 1 )
  {
    mOffset = this->m_pCanAttackConditions.mOffset;
    if ( !mOffset )
      return 1;
    v5 = (char *)&this->m_pCanAttackConditions + mOffset;
    if ( !v5 )
      return 1;
    result = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 80i64))(v5);
    if ( result )
      return 1;
  }
  else
  {
    v7 = HasAttackRequestCondition::ObtainHasAttackRequestNode(this, context);
    v8 = v7;
    if ( v7 )
    {
      v7->m_LastTimePolled = UFG::Metrics::msInstance.mSimTime_Temp;
      v7->m_LastFramePolled = UFG::Metrics::msInstance.mSimFrameCount;
      m_pPointer = v7->m_pCanAttackConditions.m_pPointer;
      v10 = 0;
      mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
      if ( m_pPointer && v8->m_pActionContextCopy )
        v10 = ((__int64 (__fastcall *)(CanAttackConditionGroup *))m_pPointer->ConditionGroup::Condition::Expression::IMemberMap::vfptr[1].FindWithOldPath)(m_pPointer);
      v12 = v8->m_pAttackeeRequest.m_pPointer;
      if ( v12
        && *((UFG::HasAttackRequestNode **)&v12[160].m_Flags + 3 * UFG::AttackRightsComponent::s_AttackTypeToDebug) == v8 )
      {
        if ( (float)(mSimTime_Temp - v8->m_AttackeeRequestTime) < this->m_TimeoutToBeginAttacking || v10 )
          return 1;
        UFG::HasAttackRequestNode::FinishedAttacking(v8);
      }
      else
      {
        p_m_pAttackeeRequest = &v8->m_pAttackeeRequest;
        if ( v8->m_pAttackeeRequest.m_pPointer )
        {
          mPrev = p_m_pAttackeeRequest->mPrev;
          mNext = v8->m_pAttackeeRequest.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_pAttackeeRequest->mPrev = p_m_pAttackeeRequest;
          v8->m_pAttackeeRequest.mNext = &v8->m_pAttackeeRequest;
        }
        v8->m_pAttackeeRequest.m_pPointer = 0i64;
        AttackTarget = HasAttackRequestCondition::GetAttackTarget(this, context);
        mValue = this->m_AttackerType.mValue;
        if ( mValue )
        {
          if ( AttackTarget && mValue == 1 )
            UFG::AttackRightsComponent::AddToFollowerAttackSlotQueue(AttackTarget, v8);
        }
        else if ( AttackTarget )
        {
          UFG::AttackRightsComponent::RequestAttackSlot(AttackTarget, v8);
        }
      }
    }
    return 0;
  }
  return result;
}

// File Line: 3906
// RVA: 0x384B50
void __fastcall HasAttackRequestCondition::Serialize(
        HasAttackRequestCondition *this,
        IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  Expression::IMemberMap *v4; // rdx

  mOffset = this->m_pCanAttackConditions.mOffset;
  if ( mOffset )
  {
    v4 = (Expression::IMemberMap *)((char *)&this->m_pCanAttackConditions + mOffset);
    if ( v4 )
      IActionTreeSerializer::PushObjectToSerialize(serializer, v4);
  }
}

// File Line: 3935
// RVA: 0x14AE180
__int64 dynamic_initializer_for__IsAtRangePreferenceCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsAtRangePreferenceCondition", 0xFFFFFFFF);
  IsAtRangePreferenceCondition::sClassNameUID = result;
  return result;
}

// File Line: 3943
// RVA: 0x330190
void __fastcall IsAtRangePreferenceCondition::IsAtRangePreferenceCondition(IsAtRangePreferenceCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsAtRangePreferenceCondition::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 22;
}

// File Line: 3948
// RVA: 0x338ED0
void __fastcall IsAtRangePreferenceCondition::~IsAtRangePreferenceCondition(IsAtRangePreferenceCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsAtRangePreferenceCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 3953
// RVA: 0x3707F0
char __fastcall IsAtRangePreferenceCondition::Match(IsAtRangePreferenceCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::FormationManagerComponent *ComponentOfTypeHK; // rax
  UFG::FormationManagerComponent *v11; // rbx
  int RangeIndex; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
    ComponentOfTypeHK = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v8,
                                                            UFG::FormationManagerComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::FormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                            v8,
                                                            UFG::FormationManagerComponent::_TypeUID);
  v11 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  RangeIndex = UFG::FormationManagerComponent::FindRangeIndex(ComponentOfTypeHK, context->mSimObject.m_pPointer);
  if ( RangeIndex == -1 )
    return 0;
  if ( this->m_RangePreference.mValue )
  {
    switch ( this->m_RangePreference.mValue )
    {
      case 1:
        return RangeIndex == 0;
      case 2:
        return RangeIndex == v11->m_NumRanges - 2;
      case 3:
        return RangeIndex != 0;
    }
    if ( this->m_RangePreference.mValue != 4 )
      return 0;
  }
  return 1;
}

// File Line: 3988
// RVA: 0x14AE8C0
__int64 dynamic_initializer_for__TimeoutCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TimeoutCondition", 0xFFFFFFFF);
  TimeoutCondition::sClassNameUID = result;
  return result;
}

// File Line: 3994
// RVA: 0x3327A0
void __fastcall TimeoutCondition::TimeoutCondition(TimeoutCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TimeoutCondition::`vftable;
  *(_QWORD *)&this->m_TimeoutTimeUID = 0i64;
  this->m_MaxTimeUntilTimeout = 0.0;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 4002
// RVA: 0x383D20
void __fastcall TimeoutCondition::ResolveReferences(TimeoutCondition *this, ActionNode *action_node)
{
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  __int64 mOffset; // rax
  ActionNode *v7; // rcx
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v8; // [rsp+20h] [rbp-18h] BYREF

  v4 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v4;
  v8.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v8.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))CooldownCondition::OnMyExitCallback;
  ActionNode::AddOnEnterCallback(action_node, &v8);
  mOffset = action_node->mParent.mOffset;
  if ( mOffset )
  {
    v7 = (ActionNode *)((char *)&action_node->mParent + mOffset);
    if ( v7 )
    {
      v8.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
      v8.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))TimeoutCondition::OnParentExitCallback;
      ActionNode::AddOnExitCallback(v7, &v8);
    }
  }
  this->m_TimeoutTimeUID = UFG::ActionTreeComponentBase::MakeValueUID(
                             this->m_TimeoutTimeUID,
                             eACTION_TREE_MEMORY_ELEMENT_FLOAT);
}

// File Line: 4027
// RVA: 0x37B660
void __fastcall CooldownCondition::OnMyExitCallback(
        CooldownCondition *this,
        ActionNode *action_node,
        ActionContext *action_context,
        unsigned int a4)
{
  float m_MaxTimeUntilCanEnterAgain; // xmm6_4
  float m_MinTimeUntilCanEnterAgain; // xmm7_4
  __int64 mOffset; // rax
  char *v9; // rcx
  UFG::ActionTreeComponentBase *v10; // rdx
  UFG::ActionTreeComponentBase *v11; // rcx

  m_MaxTimeUntilCanEnterAgain = this->m_MaxTimeUntilCanEnterAgain;
  m_MinTimeUntilCanEnterAgain = this->m_MinTimeUntilCanEnterAgain;
  if ( m_MaxTimeUntilCanEnterAgain > m_MinTimeUntilCanEnterAgain )
    UFG::qRandom(this->m_MaxTimeUntilCanEnterAgain - m_MinTimeUntilCanEnterAgain, (unsigned int *)&UFG::qDefaultSeed);
  mOffset = this->m_MyRoot.mOffset;
  v9 = 0i64;
  if ( mOffset )
    v10 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v10 = 0i64;
  if ( mOffset )
    v9 = (char *)&this->m_MyRoot + mOffset;
  v11 = action_context->mActionTreeComponentBase[v9[236]];
  if ( !v11 )
    v11 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(v11, v10, (ActionNodeRoot *)this->m_NextTimeCanEnterUID, a4);
}

// File Line: 4040
// RVA: 0x37BBB0
void __fastcall TimeoutCondition::OnParentExitCallback(
        TimeoutCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v5; // rcx
  UFG::ActionTreeComponentBase *v6; // r9
  UFG::ActionTreeComponentBase *v7; // rcx

  mOffset = this->m_MyRoot.mOffset;
  v5 = 0i64;
  if ( mOffset )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v6 = 0i64;
  if ( mOffset )
    v5 = (char *)&this->m_MyRoot + mOffset;
  v7 = action_context->mActionTreeComponentBase[v5[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
    v7,
    v6,
    (ActionNodeRoot *)this->m_TimeoutTimeUID,
    (unsigned int)v6);
}

// File Line: 4049
// RVA: 0x374920
bool __fastcall TimeoutCondition::Match(TimeoutCondition *this, ActionContext *action_context)
{
  __int64 mOffset; // rax
  float mSimTime_Temp; // xmm6_4
  UFG::ActionTreeComponentBase *v5; // r10
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  unsigned int value_uid; // [rsp+40h] [rbp+8h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  *(float *)&value_uid = FLOAT_3_4028235e38;
  if ( mOffset )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v5 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->m_MyRoot + mOffset;
  else
    v6 = 0i64;
  v7 = action_context->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(v7, v5, (ActionNodeRoot *)this->m_TimeoutTimeUID, &value_uid);
  return *(float *)&value_uid > mSimTime_Temp;
}

// File Line: 4081
// RVA: 0x14AE600
__int64 dynamic_initializer_for__RunningAttackCooldownCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RunningAttackCooldownCondition", 0xFFFFFFFF);
  RunningAttackCooldownCondition::sClassNameUID = result;
  return result;
}

// File Line: 4088
// RVA: 0x331920
void __fastcall RunningAttackCooldownCondition::RunningAttackCooldownCondition(RunningAttackCooldownCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&RunningAttackCooldownCondition::`vftable;
  this->m_TargetType.mValue = 22;
  this->m_MyRoot.mOffset = 0i64;
  this->m_HasBegunUID = 0;
}

// File Line: 4093
// RVA: 0x33A940
void __fastcall RunningAttackCooldownCondition::~RunningAttackCooldownCondition(RunningAttackCooldownCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&RunningAttackCooldownCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4098
// RVA: 0x3837D0
void __fastcall RunningAttackCooldownCondition::ResolveReferences(
        RunningAttackCooldownCondition *this,
        ActionNode *action_node)
{
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v6; // [rsp+20h] [rbp-18h] BYREF

  v4 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v4;
  v6.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v6.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))RunningAttackCooldownCondition::OnMyExitCallback;
  ActionNode::AddOnExitCallback(action_node, &v6);
  this->m_HasBegunUID = UFG::ActionTreeComponentBase::MakeValueUID(
                          this->m_HasBegunUID,
                          eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 4115
// RVA: 0x37BA10
void __fastcall RunningAttackCooldownCondition::OnMyExitCallback(
        RunningAttackCooldownCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v5; // rcx
  UFG::ActionTreeComponentBase *v7; // rdx
  UFG::ActionTreeComponentBase *v8; // rcx
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v13; // zf
  UFG::SimObjectGame *v14; // rcx
  UFG::SimObjectGame *v15; // r8
  __int16 v16; // cx
  UFG::SimComponent *ComponentOfType; // rax
  float mSimTime_Temp; // xmm0_4

  mOffset = this->m_MyRoot.mOffset;
  v5 = 0i64;
  if ( mOffset )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v7 = 0i64;
  if ( mOffset )
    v5 = (char *)&this->m_MyRoot + mOffset;
  v8 = action_context->mActionTreeComponentBase[v5[236]];
  if ( !v8 )
    v8 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v8, v7, (ActionNodeRoot *)this->m_HasBegunUID, 0);
  m_pPointer = action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v13 = (m_Flags & 0x1000) == 0;
        v14 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
        ComponentOfTypeHK = v13
                          ? UFG::SimObject::GetComponentOfType(v14, UFG::TargetingSystemBaseComponent::_TypeUID)
                          : UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v15 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                        + *(_QWORD *)&m_pComponent[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40);
      if ( v15 )
      {
        v16 = v15->m_Flags;
        if ( (v16 & 0x4000) != 0 )
        {
          ComponentOfType = v15->m_Components.p[46].m_pComponent;
        }
        else if ( v16 < 0 || (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
        {
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::AttackRightsComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(v15, UFG::AttackRightsComponent::_TypeUID);
        }
        if ( ComponentOfType )
        {
          mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
          LOBYTE(ComponentOfType[149].m_Flags) = 1;
          *(float *)&ComponentOfType[149].m_NameUID = mSimTime_Temp;
          *(float *)&ComponentOfType[149].m_NameUID = UFG::Metrics::msInstance.mSimTime_Temp + 3.0;
        }
      }
    }
  }
}

// File Line: 4139
// RVA: 0x3721E0
char __fastcall RunningAttackCooldownCondition::Match(RunningAttackCooldownCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  char *v4; // rdx
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // r8
  __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  float mSimTime_Temp; // xmm0_4
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  v4 = 0i64;
  LOBYTE(value_uid) = 0;
  if ( mOffset )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v6 = 0i64;
  if ( mOffset )
    v4 = (char *)&this->m_MyRoot + mOffset;
  v7 = context->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v7,
    v6,
    (ActionNodeRoot *)this->m_HasBegunUID,
    (bool *)&value_uid);
  if ( (_BYTE)value_uid )
    return 1;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v11 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v11;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v12 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                        + *(_QWORD *)&m_pComponent[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40);
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 & 0x4000) != 0 )
          v14 = v12->m_Components.p[46].m_pComponent;
        else
          v14 = v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v12, UFG::AttackRightsComponent::_TypeUID);
        if ( v14 )
        {
          if ( LOBYTE(v14[149].m_Flags) )
          {
            mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
            if ( UFG::Metrics::msInstance.mSimTime_Temp >= *(float *)&v14[149].m_NameUID )
            {
              LOBYTE(v14[149].m_Flags) = 0;
              *(float *)&v14[149].m_NameUID = mSimTime_Temp + 5.0;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 4193
// RVA: 0x14AE440
__int64 dynamic_initializer_for__OpportunityAttackCooldownCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("OpportunityAttackCooldownCondition", 0xFFFFFFFF);
  OpportunityAttackCooldownCondition::sClassNameUID = result;
  return result;
}

// File Line: 4204
// RVA: 0x330BF0
void __fastcall OpportunityAttackCooldownCondition::OpportunityAttackCooldownCondition(
        OpportunityAttackCooldownCondition *this)
{
  Condition::Condition(this);
  this->mPrev = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->mNext = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&OpportunityAttackCooldownCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&OpportunityAttackCooldownCondition::`vftable{for `IConditionInit};
  *(_WORD *)&this->m_TargetType.mValue = 22;
  *(_QWORD *)&this->m_MinTimeUntilNextOpportunityAttackPropertySymbol.mUID = -1i64;
  this->m_MyRoot.mOffset = 0i64;
  *(_QWORD *)&this->m_HasBegunUID = 0i64;
  this->m_MaxTimeUntilNextOpportunityAttackUID = 0;
}

// File Line: 4211
// RVA: 0x3398B0
void __fastcall OpportunityAttackCooldownCondition::~OpportunityAttackCooldownCondition(
        OpportunityAttackCooldownCondition *this)
{
  UFG::qNode<IConditionInit,IConditionInit> *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mNext; // rax

  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&OpportunityAttackCooldownCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&OpportunityAttackCooldownCondition::`vftable{for `IConditionInit};
  v2 = &this->UFG::qNode<IConditionInit,IConditionInit>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4226
// RVA: 0x383570
void __fastcall OpportunityAttackCooldownCondition::ResolveReferences(
        OpportunityAttackCooldownCondition *this,
        ActionNode *action_node)
{
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  __int64 v6; // rax
  ActionNodeRoot *v7; // rax
  unsigned int ValueUID; // eax
  unsigned int m_MinTimeUntilNextOpportunityAttackUID; // ecx
  unsigned int v10; // eax
  unsigned int m_MaxTimeUntilNextOpportunityAttackUID; // ecx
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v12; // [rsp+20h] [rbp-18h] BYREF

  v4 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v4 )
    v6 = (char *)v4 - (char *)p_m_MyRoot;
  else
    v6 = 0i64;
  p_m_MyRoot->mOffset = v6;
  Assembly::GetRCX(this);
  v12.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))OpportunityAttackCooldownCondition::OnMyExitCallback;
  v12.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  ActionNode::AddOnExitCallback(action_node, &v12);
  v7 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  ActionNodeRoot::AddToInitList(v7, &this->IConditionInit);
  ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(this->m_HasBegunUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  m_MinTimeUntilNextOpportunityAttackUID = this->m_MinTimeUntilNextOpportunityAttackUID;
  this->m_HasBegunUID = ValueUID;
  v10 = UFG::ActionTreeComponentBase::MakeValueUID(
          m_MinTimeUntilNextOpportunityAttackUID,
          eACTION_TREE_MEMORY_ELEMENT_FLOAT);
  m_MaxTimeUntilNextOpportunityAttackUID = this->m_MaxTimeUntilNextOpportunityAttackUID;
  this->m_MinTimeUntilNextOpportunityAttackUID = v10;
  this->m_MaxTimeUntilNextOpportunityAttackUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                                   m_MaxTimeUntilNextOpportunityAttackUID,
                                                   eACTION_TREE_MEMORY_ELEMENT_FLOAT);
}

// File Line: 4253
// RVA: 0x366180
void __fastcall OpportunityAttackCooldownCondition::Init(
        OpportunityAttackCooldownCondition *this,
        ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  qEnum<enum UFG::eTargetTypeEnum,unsigned char> *v3; // rsi
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rdi
  unsigned int v8; // r9d
  __int64 v9; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  qEnum<enum UFG::eTargetTypeEnum,unsigned char> *v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  unsigned int v13; // r9d
  __int64 v14; // rax
  UFG::ActionTreeComponentBase *v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  float value; // [rsp+38h] [rbp+10h] BYREF

  m_pPointer = action_context->mSimObject.m_pPointer;
  v3 = 0i64;
  if ( !m_pPointer || (m_pSceneObj = m_pPointer->m_pSceneObj) == 0i64 )
  {
    mpWritableProperties = 0i64;
LABEL_6:
    if ( !mpWritableProperties )
      return;
    goto LABEL_7;
  }
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  value = 0.0;
  if ( UFG::TSCharacter::get_attack_param_real(
         mpWritableProperties,
         (UFG::qSymbol *)&this->IConditionInit::vfptr + 1,
         &value) )
  {
    v9 = *(_QWORD *)&this->m_TargetType.mValue;
    if ( v9 )
      v10 = (UFG::ActionTreeComponentBase *)(&this->m_TargetType.mValue + v9);
    else
      v10 = 0i64;
    if ( v9 )
      v11 = &this->m_TargetType + v9;
    else
      v11 = 0i64;
    v12 = action_context->mActionTreeComponentBase[v11[236].mValue];
    if ( !v12 )
      v12 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(v12, v10, (ActionNodeRoot *)LODWORD(this->mNext), v8);
  }
  if ( UFG::TSCharacter::get_attack_param_real(
         mpWritableProperties,
         (UFG::qSymbol *)&this->UFG::qNode<IConditionInit,IConditionInit>,
         &value) )
  {
    v14 = *(_QWORD *)&this->m_TargetType.mValue;
    if ( v14 )
      v15 = (UFG::ActionTreeComponentBase *)(&this->m_TargetType.mValue + v14);
    else
      v15 = 0i64;
    if ( v14 )
      v3 = &this->m_TargetType + v14;
    v16 = action_context->mActionTreeComponentBase[v3[236].mValue];
    if ( !v16 )
      v16 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(v16, v15, (ActionNodeRoot *)HIDWORD(this->mNext), v13);
  }
}

// File Line: 4295
// RVA: 0x37B790
void __fastcall OpportunityAttackCooldownCondition::OnMyExitCallback(
        OpportunityAttackCooldownCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v4; // rsi
  UFG::ActionTreeComponentBase *v7; // rdx
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v14; // zf
  UFG::SimObjectGame *v15; // rcx
  UFG::SimObjectGame *v16; // r8
  __int16 v17; // cx
  UFG::AttackRightsComponent *v18; // rdi
  UFG::SimComponent *v19; // rax
  __int64 v20; // rax
  UFG::ActionTreeComponentBase *v21; // rdx
  char *v22; // rcx
  UFG::ActionTreeComponentBase *v23; // rcx
  __int64 v24; // rax
  UFG::ActionTreeComponentBase *v25; // rdx
  UFG::ActionTreeComponentBase *v26; // rcx
  float max_time_until_next_one; // [rsp+40h] [rbp+8h] BYREF
  unsigned int value_uid; // [rsp+50h] [rbp+18h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  v4 = 0i64;
  if ( mOffset )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v7 = 0i64;
  if ( mOffset )
    v8 = (char *)&this->m_MyRoot + mOffset;
  else
    v8 = 0i64;
  v9 = action_context->mActionTreeComponentBase[v8[236]];
  if ( !v9 )
    v9 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v9, v7, (ActionNodeRoot *)this->m_HasBegunUID, 0);
  m_pPointer = action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v14 = (m_Flags & 0x1000) == 0;
        v15 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
        ComponentOfTypeHK = v14
                          ? UFG::SimObject::GetComponentOfType(v15, UFG::TargetingSystemBaseComponent::_TypeUID)
                          : UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v16 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                        + *(_QWORD *)&m_pComponent[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40);
      if ( v16 )
      {
        v17 = v16->m_Flags;
        if ( (v17 & 0x4000) != 0 )
        {
          v18 = (UFG::AttackRightsComponent *)v16->m_Components.p[46].m_pComponent;
        }
        else
        {
          v19 = v17 < 0 || (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::AttackRightsComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v16, UFG::AttackRightsComponent::_TypeUID);
          v18 = (UFG::AttackRightsComponent *)v19;
        }
        if ( v18 )
        {
          v20 = this->m_MyRoot.mOffset;
          value_uid = 0;
          max_time_until_next_one = 0.0;
          if ( v20 )
            v21 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v20);
          else
            v21 = 0i64;
          if ( v20 )
            v22 = (char *)&this->m_MyRoot + v20;
          else
            v22 = 0i64;
          v23 = action_context->mActionTreeComponentBase[v22[236]];
          if ( !v23 )
            v23 = action_context->mActionTreeComponentBase[1];
          UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
            v23,
            v21,
            (ActionNodeRoot *)this->m_MinTimeUntilNextOpportunityAttackUID,
            &value_uid);
          v24 = this->m_MyRoot.mOffset;
          if ( v24 )
            v25 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v24);
          else
            v25 = 0i64;
          if ( v24 )
            v4 = (char *)&this->m_MyRoot + v24;
          v26 = action_context->mActionTreeComponentBase[v4[236]];
          if ( !v26 )
            v26 = action_context->mActionTreeComponentBase[1];
          UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
            v26,
            v25,
            (ActionNodeRoot *)this->m_MaxTimeUntilNextOpportunityAttackUID,
            &max_time_until_next_one);
          UFG::AttackRightsComponent::JustPerformedOpportunityAttack(
            v18,
            (UFG::eAttackType)(unsigned __int8)this->m_AttackType.mValue,
            *(float *)&value_uid,
            max_time_until_next_one);
        }
      }
    }
  }
}

// File Line: 4333
// RVA: 0x371700
char __fastcall OpportunityAttackCooldownCondition::Match(
        OpportunityAttackCooldownCondition *this,
        ActionContext *context)
{
  __int64 mOffset; // rax
  char *v4; // rdx
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // r8
  __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  __int64 mValue; // rdx
  bool v16; // cl
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  v4 = 0i64;
  LOBYTE(value_uid) = 0;
  if ( mOffset )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v6 = 0i64;
  if ( mOffset )
    v4 = (char *)&this->m_MyRoot + mOffset;
  v7 = context->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v7,
    v6,
    (ActionNodeRoot *)this->m_HasBegunUID,
    (bool *)&value_uid);
  if ( (_BYTE)value_uid )
    return 1;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v11 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v11;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v12 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
  if ( !v12 )
    return 0;
  v13 = v12->m_Flags;
  if ( (v13 & 0x4000) != 0 )
    v14 = v12->m_Components.p[46].m_pComponent;
  else
    v14 = v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v12, UFG::AttackRightsComponent::_TypeUID);
  if ( !v14 )
    return 0;
  mValue = (unsigned __int8)this->m_AttackType.mValue;
  v16 = UFG::Metrics::msInstance.mSimTime_Temp >= *(float *)(&v14[149].m_SimObjIndex + 2 * mValue + 1);
  if ( UFG::Metrics::msInstance.mSimTime_Temp >= *(float *)(&v14[149].m_SimObjIndex + 2 * mValue + 1) )
    *(float *)(&v14[149].m_SimObjIndex + 2 * mValue + 1) = UFG::Metrics::msInstance.mSimTime_Temp + 5.0;
  return v16;
}

// File Line: 4395
// RVA: 0x14AE8A0
__int64 dynamic_initializer_for__TimeToInterceptCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TimeToInterceptCondition", 0xFFFFFFFF);
  TimeToInterceptCondition::sClassNameUID = result;
  return result;
}

// File Line: 4405
// RVA: 0x332740
void __fastcall TimeToInterceptCondition::TimeToInterceptCondition(TimeToInterceptCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TimeToInterceptCondition::`vftable;
  this->m_TargetType.mValue = 22;
  this->m_InEqualityOperator.mValue = 4;
  this->m_TimeToIntercept = 1.0;
  this->m_MaxAngleRadians = 0.17453294;
  this->m_MaxAngleCosine = cosf(0.17453294);
}

// File Line: 4414
// RVA: 0x33B6F0
void __fastcall TimeToInterceptCondition::~TimeToInterceptCondition(TimeToInterceptCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TimeToInterceptCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4425
// RVA: 0x374600
bool __fastcall TimeToInterceptCondition::Match(TimeToInterceptCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  __int64 v8; // rdi
  __int64 v9; // rdi
  UFG::SimObject *v10; // rbx
  UFG::TransformNodeComponent *v11; // rbx
  __m128 x_low; // xmm10
  float v13; // xmm11_4
  float v14; // xmm9_4
  __m128 v15; // xmm12
  __m128 v16; // xmm8
  float v17; // xmm3_4
  float v18; // xmm5_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float x; // xmm5_4
  __m128 y_low; // xmm4
  float z; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  __m128 v26; // xmm1
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm6_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(_QWORD *)(56i64
                 * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                      + *(_QWORD *)&m_pComponent[1].m_Flags
                                      + 8i64)
                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                 + 40);
  v9 = v8 ? *(_QWORD *)(v8 + 88) : 0i64;
  v10 = context->mSimObject.m_pPointer;
  v11 = v10 ? v10->m_pTransformNodeComponent : 0i64;
  if ( !v9 || !v11 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
  UFG::TransformNodeComponent::UpdateWorldTransform(v11);
  x_low = (__m128)LODWORD(v11->mWorldVelocity.x);
  x_low.m128_f32[0] = x_low.m128_f32[0] - *(float *)(v9 + 256);
  v13 = v11->mWorldVelocity.y - *(float *)(v9 + 260);
  UFG::TransformNodeComponent::UpdateWorldTransform(v11);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
  v15 = (__m128)*(unsigned int *)(v9 + 180);
  v14 = *(float *)(v9 + 176) - v11->mWorldTransform.v3.x;
  v15.m128_f32[0] = v15.m128_f32[0] - v11->mWorldTransform.v3.y;
  v16 = v15;
  v16.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14);
  if ( v16.m128_f32[0] <= 0.001 )
  {
    x = UFG::qVector3::msZero.x;
    y_low = (__m128)LODWORD(UFG::qVector3::msZero.y);
    z = UFG::qVector3::msZero.z;
  }
  else
  {
    v17 = v16.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
    y_low = v15;
    v18 = v14 * v17;
    y_low.m128_f32[0] = v15.m128_f32[0] * v17;
    v19 = v17 * 0.0;
    v20 = (float)((float)(v18 * x_low.m128_f32[0]) + (float)(y_low.m128_f32[0] * v13)) + (float)(v19 * 0.0);
    x = v18 * v20;
    y_low.m128_f32[0] = y_low.m128_f32[0] * v20;
    z = v19 * v20;
  }
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(z * z);
  v24 = _mm_sqrt_ps(y_low).m128_f32[0];
  LODWORD(v25) = _mm_sqrt_ps(v16).m128_u32[0];
  if ( v24 <= 1.0
    || v25 <= 0.001
    || !CompareFloat(
          (UFG::InEqualityOperator)(unsigned __int8)this->m_InEqualityOperator.mValue,
          this->m_TimeToIntercept,
          v25 / v24) )
  {
    return 0;
  }
  v26 = x_low;
  v26.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v13 * v13);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
  v28 = v27;
  v29 = v27;
  v30 = v27 * 0.0;
  v31 = v28 * x_low.m128_f32[0];
  v32 = v29 * v13;
  if ( v16.m128_f32[0] == 0.0 )
    v33 = 0.0;
  else
    v33 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
  return (float)((float)((float)((float)(v14 * v33) * v31) + (float)((float)(v15.m128_f32[0] * v33) * v32))
               + (float)((float)(v33 * 0.0) * v30)) > this->m_MaxAngleCosine;
}

// File Line: 4484
// RVA: 0x14AE720
__int64 dynamic_initializer_for__TargetCanBeAttackedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetCanBeAttackedCondition", 0xFFFFFFFF);
  TargetCanBeAttackedCondition::sClassNameUID = result;
  return result;
}

// File Line: 4492
// RVA: 0x332500
void __fastcall TargetCanBeAttackedCondition::TargetCanBeAttackedCondition(TargetCanBeAttackedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetCanBeAttackedCondition::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 22;
}

// File Line: 4497
// RVA: 0x33B630
void __fastcall TargetCanBeAttackedCondition::~TargetCanBeAttackedCondition(TargetCanBeAttackedCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetCanBeAttackedCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4502
// RVA: 0x372A00
bool __fastcall TargetCanBeAttackedCondition::Match(TargetCanBeAttackedCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // r8
  UFG::TargetingSystemBaseComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::AttackRightsComponent *v9; // rdx
  UFG::AttackRightsComponent *v10; // rax
  __int64 mValue; // rcx
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (UFG::TargetingSystemBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::TargetingSystemBaseComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::TargetingSystemBaseComponent::_TypeUID));
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = (UFG::SimObjectGame *)m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[(unsigned __int8)this->m_TargetType.mValue]].m_pTarget.m_pPointer;
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 )
  {
    v9 = (UFG::AttackRightsComponent *)v7->m_Components.p[46].m_pComponent;
  }
  else
  {
    v10 = (UFG::AttackRightsComponent *)(v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v7,
                                           UFG::AttackRightsComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(v7, UFG::AttackRightsComponent::_TypeUID));
    v9 = v10;
  }
  if ( !v9 )
    return 0;
  mValue = (unsigned __int8)this->m_AttackType.mValue;
  result = v9->m_AttackingEnabled[mValue];
  if ( (_DWORD)mValue != 1 )
    return result;
  return result && !v9->m_InCombatWithSomeone;
}

// File Line: 4533
// RVA: 0x14AE020
__int64 dynamic_initializer_for__HasPositionToDefendCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasPositionToDefendCondition", 0xFFFFFFFF);
  HasPositionToDefendCondition::sClassNameUID = result;
  return result;
}

// File Line: 4536
// RVA: 0x32FAA0
void __fastcall HasPositionToDefendCondition::HasPositionToDefendCondition(HasPositionToDefendCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HasPositionToDefendCondition::`vftable;
}

// File Line: 4541
// RVA: 0x3385B0
void __fastcall HasPositionToDefendCondition::~HasPositionToDefendCondition(HasPositionToDefendCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&HasPositionToDefendCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4546
// RVA: 0x3704D0
bool __fastcall HasPositionToDefendCondition::Match(HasPositionToDefendCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::AIScriptInterfaceComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::AIScriptInterfaceComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[5].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[5].m_pComponent),
            ComponentOfTypeHK)
        && ((__int64)ComponentOfTypeHK[32].m_BoundComponentHandles.mNode.mPrev & 0x40) != 0;
  return result;
}

// File Line: 4569
// RVA: 0x14AE460
__int64 dynamic_initializer_for__OutsideOfPositionToDefendCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("OutsideOfPositionToDefendCondition", 0xFFFFFFFF);
  OutsideOfPositionToDefendCondition::sClassNameUID = result;
  return result;
}

// File Line: 4574
// RVA: 0x330C70
void __fastcall OutsideOfPositionToDefendCondition::OutsideOfPositionToDefendCondition(
        OutsideOfPositionToDefendCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&OutsideOfPositionToDefendCondition::`vftable;
  *(_QWORD *)&this->m_HowCloseToGet = 0x40000000i64;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 4582
// RVA: 0x339920
void __fastcall OutsideOfPositionToDefendCondition::~OutsideOfPositionToDefendCondition(
        OutsideOfPositionToDefendCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&OutsideOfPositionToDefendCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4596
// RVA: 0x3718D0
bool __fastcall OutsideOfPositionToDefendCondition::Match(
        OutsideOfPositionToDefendCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v8; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  __int64 mOffset; // rax
  char *v11; // rdi
  float m_HowCloseToGet; // xmm6_4
  UFG::ActionTreeComponentBase *v13; // rdx
  char *v14; // rcx
  UFG::ActionTreeComponentBase *v15; // rcx
  UFG::qVector3 *PositionToDefend; // rax
  __m128 y_low; // xmm1
  float v18; // xmm0_4
  __int64 v19; // rax
  bool v20; // si
  UFG::ActionTreeComponentBase *v21; // rdx
  UFG::ActionTreeComponentBase *v22; // rcx
  __int64 v24; // rax
  char *v25; // rdi
  UFG::ActionTreeComponentBase *v26; // rdx
  UFG::ActionTreeComponentBase *v27; // rcx
  unsigned int value_uid; // [rsp+58h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pPointer,
                                 UFG::AIScriptInterfaceComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = m_pPointer->m_Components.p[5].m_pComponent))
      : (m_pComponent = m_pPointer->m_Components.p[5].m_pComponent),
        m_pComponent
     && ((__int64)m_pComponent[32].m_BoundComponentHandles.mNode.mPrev & 0x40) != 0
     && (v8 = context->mSimObject.m_pPointer) != 0i64
     && (m_pTransformNodeComponent = v8->m_pTransformNodeComponent) != 0i64) )
  {
    mOffset = this->m_MyRoot.mOffset;
    v11 = 0i64;
    m_HowCloseToGet = *((float *)&m_pComponent[10].m_BoundComponentHandles.mNode.mNext + 1);
    LOBYTE(value_uid) = 0;
    if ( mOffset )
      v13 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v13 = 0i64;
    if ( mOffset )
      v14 = (char *)&this->m_MyRoot + mOffset;
    else
      v14 = 0i64;
    v15 = context->mActionTreeComponentBase[v14[236]];
    if ( !v15 )
      v15 = context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
      v15,
      v13,
      (ActionNodeRoot *)this->m_HasBegunUID,
      (bool *)&value_uid);
    if ( (_BYTE)value_uid && this->m_HowCloseToGet < m_HowCloseToGet )
      m_HowCloseToGet = this->m_HowCloseToGet;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    PositionToDefend = UFG::AIScriptInterfaceComponent::GetPositionToDefend((UFG::AIScriptInterfaceComponent *)m_pComponent);
    y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
    y_low.m128_f32[0] = y_low.m128_f32[0] - PositionToDefend->y;
    v18 = m_pTransformNodeComponent->mWorldTransform.v3.x - PositionToDefend->x;
    v19 = this->m_MyRoot.mOffset;
    y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v18 * v18);
    v20 = _mm_sqrt_ps(y_low).m128_f32[0] > m_HowCloseToGet;
    if ( v19 )
      v21 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v19);
    else
      v21 = 0i64;
    if ( v19 )
      v11 = (char *)&this->m_MyRoot + v19;
    v22 = context->mActionTreeComponentBase[v11[236]];
    if ( !v22 )
      v22 = context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v22, v21, (ActionNodeRoot *)this->m_HasBegunUID, v20);
    return v20;
  }
  else
  {
    v24 = this->m_MyRoot.mOffset;
    v25 = 0i64;
    if ( v24 )
      v26 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v24);
    else
      v26 = 0i64;
    if ( v24 )
      v25 = (char *)&this->m_MyRoot + v24;
    v27 = context->mActionTreeComponentBase[v25[236]];
    if ( !v27 )
      v27 = context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v27, v26, (ActionNodeRoot *)this->m_HasBegunUID, 0);
    return 0;
  }
}

// File Line: 4656
// RVA: 0x14AD940
__int64 dynamic_initializer_for__AbandonPositionToDefendCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AbandonPositionToDefendCondition", 0xFFFFFFFF);
  AbandonPositionToDefendCondition::sClassNameUID = result;
  return result;
}

// File Line: 4662
// RVA: 0x32C060
void __fastcall AbandonPositionToDefendCondition::AbandonPositionToDefendCondition(
        AbandonPositionToDefendCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AbandonPositionToDefendCondition::`vftable;
  this->m_TargetType.mValue = 22;
  this->m_PositionToDefendHasBeenCompromisedUID = 0;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 4669
// RVA: 0x334C70
void __fastcall AbandonPositionToDefendCondition::~AbandonPositionToDefendCondition(
        AbandonPositionToDefendCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AbandonPositionToDefendCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4674
// RVA: 0x383630
void __fastcall AbandonPositionToDefendCondition::ResolveReferences(
        OutsideOfPositionToDefendCondition *this,
        ActionNode *action_node)
{
  Expression::IMemberMap *v3; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx

  v3 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v3 )
    v3 = (Expression::IMemberMap *)((char *)v3 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v3;
  this->m_HasBegunUID = UFG::ActionTreeComponentBase::MakeValueUID(
                          this->m_HasBegunUID,
                          eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 4683
// RVA: 0x36EDA0
bool __fastcall AbandonPositionToDefendCondition::Match(AbandonPositionToDefendCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::TargetingSystemBaseComponent *v10; // rdi
  UFG::SimComponent *v11; // rax
  __int64 mOffset; // rax
  char *v13; // rbp
  UFG::ActionTreeComponentBase *v14; // rdx
  char *v15; // rcx
  UFG::ActionTreeComponentBase *v16; // rcx
  bool v17; // r9
  __int64 v18; // rax
  UFG::ActionTreeComponentBase *v19; // rdx
  UFG::ActionTreeComponentBase *v20; // rcx
  char v21; // bl
  bool HasRangedWeaponEquippedWithAmmo; // al
  unsigned int value_uid; // [rsp+48h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
  {
    v10 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
  }
  else if ( v9 >= 0 )
  {
    v11 = (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
    v10 = (UFG::TargetingSystemBaseComponent *)v11;
  }
  else
  {
    v10 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
  }
  if ( !v10 )
    return 0;
  mOffset = this->m_MyRoot.mOffset;
  v13 = 0i64;
  LOBYTE(value_uid) = 0;
  if ( mOffset )
    v14 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v14 = 0i64;
  if ( mOffset )
    v15 = (char *)&this->m_MyRoot + mOffset;
  else
    v15 = 0i64;
  v16 = context->mActionTreeComponentBase[v15[236]];
  if ( !v16 )
    v16 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v16,
    v14,
    (ActionNodeRoot *)this->m_PositionToDefendHasBeenCompromisedUID,
    (bool *)&value_uid);
  v17 = (_BYTE)value_uid || AbandonPositionToDefendCondition::PositionToDefendIsCompromised(this, context);
  v18 = this->m_MyRoot.mOffset;
  LOBYTE(value_uid) = v17;
  if ( v18 )
    v19 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v18);
  else
    v19 = 0i64;
  if ( v18 )
    v13 = (char *)&this->m_MyRoot + v18;
  v20 = context->mActionTreeComponentBase[v13[236]];
  if ( !v20 )
    v20 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
    v20,
    v19,
    (ActionNodeRoot *)this->m_PositionToDefendHasBeenCompromisedUID,
    v17);
  v21 = BYTE1(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev);
  HasRangedWeaponEquippedWithAmmo = UFG::HasRangedWeaponEquippedWithAmmo(v10);
  if ( (v21 & 1) != 0 )
  {
    if ( this->m_PositionToDefendHasBeenCompromised )
      return 1;
  }
  return (v21 & 2) != 0 && !HasRangedWeaponEquippedWithAmmo;
}

// File Line: 4719
// RVA: 0x37C690
bool __fastcall AbandonPositionToDefendCondition::PositionToDefendIsCompromised(
        AbandonPositionToDefendCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v8; // rcx
  UFG::SimComponent *v9; // rdx
  __int16 v10; // dx
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v12; // r8
  __int64 v13; // rbx
  __int64 v14; // rsi
  __int64 v15; // rsi
  __int64 v16; // rbx
  UFG::TransformNodeComponent *v17; // rbx
  float v18; // xmm6_4
  __m128 v19; // xmm1
  float v20; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v8 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      v9 = v8->m_Components.p[5].m_pComponent;
    }
    else if ( v10 >= 0 )
    {
      if ( (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIScriptInterfaceComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::AIScriptInterfaceComponent::_TypeUID);
      v9 = ComponentOfType;
    }
    else
    {
      v9 = v8->m_Components.p[5].m_pComponent;
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( !m_pComponent || !v9 )
    return 0;
  v12 = *(_QWORD *)&m_pComponent[1].m_Flags;
  v13 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
  v14 = *(_QWORD *)(56i64 * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue + v12 + 8) + v13 + 40);
  v15 = v14 ? *(_QWORD *)(v14 + 88) : 0i64;
  v16 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(v12 + 40) + v13 + 40);
  v17 = v16 ? *(UFG::TransformNodeComponent **)(v16 + 88) : 0i64;
  if ( !v15 || !v17 )
    return 0;
  v18 = *((float *)&v9[10].m_BoundComponentHandles.mNode.mNext + 1);
  UFG::TransformNodeComponent::UpdateWorldTransform(v17);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v15);
  v19 = (__m128)*(unsigned int *)(v15 + 180);
  v20 = *(float *)(v15 + 176) - v17->mWorldTransform.v3.x;
  v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] - v17->mWorldTransform.v3.y)
                          * (float)(v19.m128_f32[0] - v17->mWorldTransform.v3.y))
                  + (float)(v20 * v20);
  return v18 > _mm_sqrt_ps(v19).m128_f32[0];
}

// File Line: 4767
// RVA: 0x14ADC80
__int64 dynamic_initializer_for__CrouchWhileDefendingPositionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CrouchWhileDefendingPositionCondition", 0xFFFFFFFF);
  CrouchWhileDefendingPositionCondition::sClassNameUID = result;
  return result;
}

// File Line: 4770
// RVA: 0x32DB10
void __fastcall CrouchWhileDefendingPositionCondition::CrouchWhileDefendingPositionCondition(
        CrouchWhileDefendingPositionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CrouchWhileDefendingPositionCondition::`vftable;
}

// File Line: 4775
// RVA: 0x336000
void __fastcall CrouchWhileDefendingPositionCondition::~CrouchWhileDefendingPositionCondition(
        CrouchWhileDefendingPositionCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&CrouchWhileDefendingPositionCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4780
// RVA: 0x36F890
bool __fastcall CrouchWhileDefendingPositionCondition::Match(
        CrouchWhileDefendingPositionCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pPointer,
                                 UFG::AIScriptInterfaceComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[5].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[5].m_pComponent),
        ComponentOfTypeHK) )
  {
    return LOBYTE(ComponentOfTypeHK[32].m_BoundComponentHandles.mNode.mPrev) >> 7;
  }
  else
  {
    return 0;
  }
}

// File Line: 4803
// RVA: 0x14AE3E0
__int64 dynamic_initializer_for__NodeRequestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NodeRequestCondition", 0xFFFFFFFF);
  NodeRequestCondition::sClassNameUID = result;
  return result;
}

// File Line: 4806
// RVA: 0x330B20
void __fastcall NodeRequestCondition::NodeRequestCondition(NodeRequestCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestCondition::`vftable;
  this->m_pActionNode = 0i64;
}

// File Line: 4811
// RVA: 0x339800
void __fastcall NodeRequestCondition::~NodeRequestCondition(NodeRequestCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4825
// RVA: 0x3715E0
bool __fastcall NodeRequestCondition::Match(NodeRequestCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  ActionNode *m_pActionNode; // rdx

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  m_pActionNode = this->m_pActionNode;
  return m_pActionNode
      && ComponentOfTypeHK
      && m_pActionNode->mID.mUID == ComponentOfTypeHK->m_Intention.mNodeRequestHash;
}

// File Line: 4858
// RVA: 0x14AE3C0
__int64 dynamic_initializer_for__NodeRequestAnyCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NodeRequestAnyCondition", 0xFFFFFFFF);
  NodeRequestAnyCondition::sClassNameUID = result;
  return result;
}

// File Line: 4861
// RVA: 0x330AF0
void __fastcall NodeRequestAnyCondition::NodeRequestAnyCondition(NodeRequestAnyCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestAnyCondition::`vftable;
}

// File Line: 4866
// RVA: 0x3397C0
void __fastcall NodeRequestAnyCondition::~NodeRequestAnyCondition(NodeRequestAnyCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestAnyCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4871
// RVA: 0x371550
bool __fastcall NodeRequestAnyCondition::Match(NodeRequestAnyCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                              m_pPointer,
                                                                              UFG::AICharacterControllerBaseComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                              m_pPointer,
                                                                              UFG::AICharacterControllerBaseComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_Intention.mNodeRequestHash != 0;
  return result;
}

// File Line: 4902
// RVA: 0x14AE280
__int64 dynamic_initializer_for__LeaderHasFollowersCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LeaderHasFollowersCondition", 0xFFFFFFFF);
  LeaderHasFollowersCondition::sClassNameUID = result;
  return result;
}

// File Line: 4905
// RVA: 0x330360
void __fastcall LeaderHasFollowersCondition::LeaderHasFollowersCondition(LeaderHasFollowersCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&LeaderHasFollowersCondition::`vftable;
}

// File Line: 4910
// RVA: 0x3390E0
void __fastcall LeaderHasFollowersCondition::~LeaderHasFollowersCondition(LeaderHasFollowersCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&LeaderHasFollowersCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4915
// RVA: 0x371170
char __fastcall LeaderHasFollowersCondition::Match(LeaderHasFollowersCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int64 v3; // rbx
  UFG::SimComponent *m_pComponent; // rsi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v8; // rcx
  UFG::ActiveAIEntityComponent *v9; // rdi
  __int16 v10; // dx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // r8
  __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **i; // r8
  UFG::ActiveAIEntityComponent *v17; // rdx
  UFG::SimComponent *m_pSimComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v8 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 & 0x4000) != 0 || v10 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v8);
    }
    else if ( (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v8,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                          v8,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v9 = ComponentOfType;
  }
  else
  {
    v9 = 0i64;
  }
  v12 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 & 0x4000) != 0 )
    {
      v13 = v12->m_Components.p[5].m_pComponent;
    }
    else if ( v14 >= 0 )
    {
      if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AIScriptInterfaceComponent::_TypeUID);
      else
        v15 = UFG::SimObject::GetComponentOfType(v12, UFG::AIScriptInterfaceComponent::_TypeUID);
      v13 = v15;
    }
    else
    {
      v13 = v12->m_Components.p[5].m_pComponent;
    }
  }
  else
  {
    v13 = 0i64;
  }
  if ( !m_pComponent || !v9 || !v13 )
    return 0;
  for ( i = &v13[29].m_SafePointerList.mNode.mNext; ; i += 3 )
  {
    v17 = (UFG::ActiveAIEntityComponent *)*i;
    if ( *i )
    {
      m_pSimComponent = v17->m_pHealthComponent.m_pSimComponent;
      if ( m_pSimComponent )
      {
        if ( !BYTE4(m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev)
          && *(_QWORD *)(56i64
                       * *(unsigned __int8 *)(*(_QWORD *)&v17->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                            + 30i64)
                       + *(_QWORD *)&v17->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                       + 40) == *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 30i64)
                                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                          + 40)
          && v17 != v9 )
        {
          break;
        }
      }
    }
    if ( ++v3 >= 10 )
      return 0;
  }
  return 1;
}

// File Line: 4969
// RVA: 0x14AD700
__int64 dynamic_initializer_for__AICoverIsValidCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICoverIsValidCondition", 0xFFFFFFFF);
  AICoverIsValidCondition::sClassNameUID = result;
  return result;
}

// File Line: 4976
// RVA: 0x32B080
void __fastcall AICoverIsValidCondition::AICoverIsValidCondition(AICoverIsValidCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverIsValidCondition::`vftable;
  this->m_iTargetType = 0;
  this->m_fMinDistance = 5.0;
  this->m_fFacingAngle = 1.0471976;
}

// File Line: 4983
// RVA: 0x333E70
void __fastcall AICoverIsValidCondition::~AICoverIsValidCondition(AICoverIsValidCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverIsValidCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 4988
// RVA: 0x36E120
bool __fastcall AICoverIsValidCondition::Match(AICoverIsValidCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 *v7; // rdi
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v11; // rax
  __int64 v12; // rbx
  UFG::TransformNodeComponent *v13; // rbx
  __int64 v14; // rax
  int v15; // xmm1_4
  float v16; // xmm0_4
  int v18[6]; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
  if ( !ComponentOfTypeHK )
    return 0;
  v7 = *(__int64 **)&ComponentOfTypeHK[1].m_TypeUID;
  if ( !v7 )
    return 0;
  if ( !(*(unsigned __int8 (__fastcall **)(__int64 *))(*v7 + 16))(v7) )
    return 0;
  v8 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
  {
    m_pComponent = v8->m_Components.p[20].m_pComponent;
  }
  else if ( v9 >= 0 )
  {
    v11 = (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v11;
  }
  else
  {
    m_pComponent = v8->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v12 = *(_QWORD *)(56i64
                  * *(unsigned __int8 *)((unsigned int)this->m_iTargetType + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64)
                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                  + 40);
  if ( !v12 )
    return 0;
  v13 = *(UFG::TransformNodeComponent **)(v12 + 88);
  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
  v14 = *v7;
  *(float *)&v15 = UFG::qVector3::msAxisZ.y + v13->mWorldTransform.v3.y;
  v16 = UFG::qVector3::msAxisZ.x + v13->mWorldTransform.v3.x;
  *(float *)&v18[2] = UFG::qVector3::msAxisZ.z + v13->mWorldTransform.v3.z;
  *(float *)v18 = v16;
  v18[1] = v15;
  if ( (*(unsigned __int8 (__fastcall **)(__int64 *, int *))(v14 + 56))(v7, v18) )
    return 0;
  return (*(unsigned __int8 (__fastcall **)(__int64 *, int *))(*v7 + 64))(v7, v18) != 0;
}

// File Line: 5041
// RVA: 0x14AD760
__int64 dynamic_initializer_for__AICoverTargetIsLatched::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICoverTargetIsLatched", 0xFFFFFFFF);
  AICoverTargetIsLatched::sClassNameUID = result;
  return result;
}

// File Line: 5044
// RVA: 0x32B3A0
void __fastcall AICoverTargetIsLatched::AICoverTargetIsLatched(AICoverTargetIsLatched *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverTargetIsLatched::`vftable;
}

// File Line: 5048
// RVA: 0x334280
void __fastcall AICoverTargetIsLatched::~AICoverTargetIsLatched(AICoverTargetIsLatched *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverTargetIsLatched::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5052
// RVA: 0x36E310
bool __fastcall AICoverTargetIsLatched::Match(AICoverTargetIsLatched *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v6; // rbx
  __int64 v7; // rdi
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
  v6 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  v7 = *(_QWORD *)&ComponentOfTypeHK[1].m_TypeUID;
  if ( !v7 || !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7) )
    return 0;
  v8 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 & 0x4000) == 0 )
    {
      if ( v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
        UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID);
      else
        UFG::SimObject::GetComponentOfType(v8, UFG::WorldContextComponent::_TypeUID);
    }
  }
  mNext = v6[1].m_BoundComponentHandles.mNode.mNext;
  return mNext
      && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, __int64))mNext->mPrev[13].mPrev)(
           mNext,
           v7);
}

// File Line: 5086
// RVA: 0x14AD6E0
__int64 dynamic_initializer_for__AICoverFiringPositionClear::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICoverFiringPositionClear", 0xFFFFFFFF);
  AICoverFiringPositionClear::sClassNameUID = result;
  return result;
}

// File Line: 5096
// RVA: 0x32B040
void __fastcall AICoverFiringPositionClear::AICoverFiringPositionClear(AICoverFiringPositionClear *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverFiringPositionClear::`vftable;
  *(_WORD *)&this->m_Left = 0;
  this->m_Top = 0;
}

// File Line: 5100
// RVA: 0x333E30
void __fastcall AICoverFiringPositionClear::~AICoverFiringPositionClear(AICoverFiringPositionClear *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverFiringPositionClear::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5104
// RVA: 0x36E020
bool __fastcall AICoverFiringPositionClear::Match(AICoverFiringPositionClear *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  _BYTE *v6; // rbx
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      v6 = *(_BYTE **)&ComponentOfTypeHK[1].m_TypeUID;
      if ( v6 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(_BYTE *))(*(_QWORD *)v6 + 16i64))(v6)
          && (*(unsigned __int8 (__fastcall **)(_BYTE *))(*(_QWORD *)v6 + 32i64))(v6)
          && (this->m_Left && (v6[320] & 1) != 0
           || this->m_Right && (v6[320] & 2) != 0
           || this->m_Top && (v6[320] & 4) != 0) )
        {
          return 1;
        }
      }
    }
  }
  return result;
}

// File Line: 5158
// RVA: 0x14AE1A0
__int64 dynamic_initializer_for__IsClosestFormationMemberCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsClosestFormationMemberCondition", 0xFFFFFFFF);
  IsClosestFormationMemberCondition::sClassNameUID = result;
  return result;
}

// File Line: 5165
// RVA: 0x3301D0
void __fastcall IsClosestFormationMemberCondition::IsClosestFormationMemberCondition(
        IsClosestFormationMemberCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsClosestFormationMemberCondition::`vftable;
  this->m_TargetType.mValue = 22;
}

// File Line: 5170
// RVA: 0x338F10
void __fastcall IsClosestFormationMemberCondition::~IsClosestFormationMemberCondition(
        IsClosestFormationMemberCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsClosestFormationMemberCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5175
// RVA: 0x3709B0
bool __fastcall IsClosestFormationMemberCondition::Match(
        IsClosestFormationMemberCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r13
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 mPrev_low; // rcx
  float v13; // xmm6_4
  UFG::SimObject *v14; // r14
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // r12
  int *v16; // r15
  __int64 v17; // rbp
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v18; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rcx
  UFG::TransformNodeComponent *v22; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax
  ActionContext *v25; // [rsp+88h] [rbp+10h]
  __int64 v26; // [rsp+90h] [rbp+18h]

  v25 = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    action_context = v25;
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = action_context->mSimObject.m_pPointer;
  if ( !v7 )
    return 0;
  if ( !v7->m_pTransformNodeComponent )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  m_pTransformNodeComponent = v8->m_pTransformNodeComponent;
  if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FormationManagerComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::FormationManagerComponent::_TypeUID);
  if ( !ComponentOfTypeHK )
    return 0;
  if ( !m_pTransformNodeComponent )
    return 0;
  mPrev_low = SLODWORD(ComponentOfTypeHK[5].m_SafePointerList.mNode.mPrev);
  v13 = FLOAT_N1_0;
  v14 = 0i64;
  v26 = mPrev_low;
  if ( mPrev_low <= 0 )
    return 0;
  p_m_BoundComponentHandles = &ComponentOfTypeHK[10].m_BoundComponentHandles;
  v16 = (int *)&ComponentOfTypeHK[5].m_SafePointerList.mNode.mPrev + 1;
  do
  {
    v17 = *v16;
    if ( v17 > 0 )
    {
      v18 = p_m_BoundComponentHandles;
      do
      {
        mPrev = v18->mNode.mPrev;
        if ( v18->mNode.mPrev )
        {
          mNext = mPrev[6].mNext;
          if ( mNext )
          {
            v21 = mNext[2].mNext;
            if ( v21 )
            {
              if ( v21[5].mNext )
              {
                v22 = (UFG::TransformNodeComponent *)v21[5].mNext;
                UFG::TransformNodeComponent::UpdateWorldTransform(v22);
                UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                if ( v13 < 0.0
                  || (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v22->mWorldTransform.v3.y)
                                   * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v22->mWorldTransform.v3.y))
                           + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v22->mWorldTransform.v3.x)
                                   * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v22->mWorldTransform.v3.x))) < v13 )
                {
                  v23 = mPrev[6].mNext;
                  if ( v23 )
                    v14 = (UFG::SimObject *)v23[2].mNext;
                  else
                    v14 = 0i64;
                  v13 = (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v22->mWorldTransform.v3.y)
                              * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v22->mWorldTransform.v3.y))
                      + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v22->mWorldTransform.v3.x)
                              * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v22->mWorldTransform.v3.x));
                }
              }
            }
          }
        }
        v18 = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)((char *)v18 + 200);
        --v17;
      }
      while ( v17 );
      mPrev_low = v26;
    }
    ++v16;
    p_m_BoundComponentHandles += 100;
    v26 = --mPrev_low;
  }
  while ( mPrev_low );
  return v14 && v14 == v25->mSimObject.m_pPointer;
}

// File Line: 5245
// RVA: 0x14AE1C0
__int64 dynamic_initializer_for__IsClosestGroupMemberCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsClosestGroupMemberCondition", 0xFFFFFFFF);
  IsClosestGroupMemberCondition::sClassNameUID = result;
  return result;
}

// File Line: 5256
// RVA: 0x330210
void __fastcall IsClosestGroupMemberCondition::IsClosestGroupMemberCondition(IsClosestGroupMemberCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsClosestGroupMemberCondition::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 22;
  this->m_ExcludeTarget2.mValue = 0;
}

// File Line: 5261
// RVA: 0x338F50
void __fastcall IsClosestGroupMemberCondition::~IsClosestGroupMemberCondition(IsClosestGroupMemberCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsClosestGroupMemberCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5266
// RVA: 0x370C90
__int64 __fastcall IsClosestGroupMemberCondition::Match(
        IsClosestGroupMemberCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  unsigned __int8 v4; // di
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  __int64 v8; // rdx
  __int64 v9; // r8
  __int64 v10; // rsi
  UFG::SimObject *v11; // r14
  UFG::SimObject *v12; // r15
  __int64 v13; // rsi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax
  void *(__fastcall *vecDelDtor)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  UFG::SimObjectGame *v16; // rcx
  __int16 v17; // dx
  UFG::PedFormationManagerComponent *v18; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *ClosestMember; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v4 = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v8 = *(_QWORD *)&m_pComponent[1].m_Flags;
      v9 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
      v10 = *(_QWORD *)(56i64 * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue + v8 + 8) + v9 + 40);
      v11 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)((unsigned __int8)this->m_ExcludeTarget1.mValue + v8 + 8)
                               + v9
                               + 40);
      v12 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)((unsigned __int8)this->m_ExcludeTarget2.mValue + v8 + 8)
                               + v9
                               + 40);
      if ( v10 )
      {
        v13 = *(_QWORD *)(v10 + 88);
        if ( v13 )
        {
          GroupComponent = UFG::GroupComponent::GetGroupComponent((UFG::SimObjectGame *)action_context->mSimObject.m_pPointer);
          if ( GroupComponent )
          {
            if ( !GroupComponent[28].__vecDelDtor || !LODWORD(GroupComponent[15].__vecDelDtor) )
              GroupComponent = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)GroupComponent[32].__vecDelDtor;
            if ( GroupComponent )
            {
              vecDelDtor = GroupComponent[33].__vecDelDtor;
              if ( vecDelDtor )
              {
                v16 = (UFG::SimObjectGame *)*((_QWORD *)vecDelDtor + 24);
                if ( v16 )
                {
                  v17 = v16->m_Flags;
                  if ( (v17 & 0x4000) != 0 )
                  {
                    v18 = (UFG::PedFormationManagerComponent *)v16->m_Components.p[33].m_pComponent;
                  }
                  else
                  {
                    if ( v17 < 0 || (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
                      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v16,
                                            UFG::PedFormationManagerComponent::_TypeUID);
                    else
                      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                            v16,
                                            UFG::PedFormationManagerComponent::_TypeUID);
                    v18 = (UFG::PedFormationManagerComponent *)ComponentOfTypeHK;
                  }
                  if ( v18 )
                  {
                    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v13);
                    ClosestMember = UFG::PedFormationManagerComponent::GetClosestMember(
                                      v18,
                                      (UFG::qVector3 *)(v13 + 176),
                                      v11,
                                      v12);
                    return ClosestMember && ClosestMember == action_context->mSimObject.m_pPointer;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return v4;
}

// File Line: 5317
// RVA: 0x14AE640
__int64 dynamic_initializer_for__SelectSuitableVehicleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SelectSuitableVehicleCondition", 0xFFFFFFFF);
  SelectSuitableVehicleCondition::sClassNameUID = result;
  return result;
}

// File Line: 5333
// RVA: 0x331A00
void __fastcall SelectSuitableVehicleCondition::SelectSuitableVehicleCondition(SelectSuitableVehicleCondition *this)
{
  Condition::Condition(this);
  this->mPrev = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->mNext = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&SelectSuitableVehicleCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&SelectSuitableVehicleCondition::`vftable{for `IConditionInit};
  this->m_TimeBeforeReset = 3.0;
  this->m_MinTimeBetweenUpdates = 0.25;
  this->m_MaxTimeBetweenUpdates = 0.75;
  this->m_IgnoreMeshTest = 0;
  this->m_MaxSearchRadius = 0.0;
  this->m_FilterClassSymbol.mUID = -1;
  this->m_MyRoot.mOffset = 0i64;
  *(_QWORD *)&this->m_VehicleUID = 0i64;
  *(_QWORD *)&this->m_LastTimeUpdateCalledUID = 0i64;
  this->m_TimeBetweenUpdatesUID = 0;
}

// File Line: 5342
// RVA: 0x33AA30
void __fastcall SelectSuitableVehicleCondition::~SelectSuitableVehicleCondition(SelectSuitableVehicleCondition *this)
{
  UFG::qNode<IConditionInit,IConditionInit> *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *mNext; // rax

  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&SelectSuitableVehicleCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&SelectSuitableVehicleCondition::`vftable{for `IConditionInit};
  v2 = &this->UFG::qNode<IConditionInit,IConditionInit>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5352
// RVA: 0x383840
void __fastcall SelectSuitableVehicleCondition::ResolveReferences(
        SelectSuitableVehicleCondition *this,
        ActionNode *action_node)
{
  ActionNodeRoot *v4; // rax
  IConditionInit *v5; // rdx
  ActionNodeRoot *v6; // rdi
  __int64 v7; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  __int64 v9; // rax
  unsigned int ValueUID; // eax
  unsigned int m_LastTimeMatchCalledUID; // ecx
  unsigned int v12; // eax
  unsigned int m_LastTimeUpdateCalledUID; // ecx
  unsigned int v14; // eax
  unsigned int m_PreviousReturnValueUID; // ecx
  unsigned int v16; // eax
  unsigned int m_TimeBetweenUpdatesUID; // ecx
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> v18; // [rsp+20h] [rbp-18h] BYREF

  v4 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  v5 = &this->IConditionInit;
  v6 = v4;
  if ( !this )
    v5 = 0i64;
  ActionNodeRoot::AddToInitList(v4, v5);
  v7 = (__int64)v6->vfptr[1].GetResourceOwner(v6);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v7 )
    v9 = v7 - (_QWORD)p_m_MyRoot;
  else
    v9 = 0i64;
  p_m_MyRoot->mOffset = v9;
  v18.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))SelectSuitableVehicleCondition::OnExitCallback;
  v18.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  ActionNode::AddOnExitCallback(action_node, &v18);
  ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(
               this->m_VehicleUID,
               eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  m_LastTimeMatchCalledUID = this->m_LastTimeMatchCalledUID;
  this->m_VehicleUID = ValueUID;
  v12 = UFG::ActionTreeComponentBase::MakeValueUID(m_LastTimeMatchCalledUID, eACTION_TREE_MEMORY_ELEMENT_FLOAT);
  m_LastTimeUpdateCalledUID = this->m_LastTimeUpdateCalledUID;
  this->m_LastTimeMatchCalledUID = v12;
  v14 = UFG::ActionTreeComponentBase::MakeValueUID(m_LastTimeUpdateCalledUID, eACTION_TREE_MEMORY_ELEMENT_FLOAT);
  m_PreviousReturnValueUID = this->m_PreviousReturnValueUID;
  this->m_LastTimeUpdateCalledUID = v14;
  v16 = UFG::ActionTreeComponentBase::MakeValueUID(m_PreviousReturnValueUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  m_TimeBetweenUpdatesUID = this->m_TimeBetweenUpdatesUID;
  this->m_PreviousReturnValueUID = v16;
  this->m_TimeBetweenUpdatesUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                    m_TimeBetweenUpdatesUID,
                                    eACTION_TREE_MEMORY_ELEMENT_FLOAT);
}

// File Line: 5381
// RVA: 0x366390
void __fastcall SelectSuitableVehicleCondition::Init(
        SelectSuitableVehicleCondition *this,
        ActionContext *action_context,
        __int64 a3,
        unsigned int a4)
{
  float v4; // xmm6_4
  float v5; // xmm7_4
  __int64 v8; // rax
  char *v9; // rcx
  UFG::ActionTreeComponentBase *v10; // rdx
  UFG::ActionTreeComponentBase *v11; // rcx

  v4 = *(float *)&this->m_LastTimeMatchCalledUID;
  v5 = *(float *)&this->m_VehicleUID;
  if ( v4 > v5 )
    UFG::qRandom(*(float *)&this->m_LastTimeMatchCalledUID - v5, (unsigned int *)&UFG::qDefaultSeed);
  v8 = *(_QWORD *)&this->m_MinTimeBetweenUpdates;
  v9 = 0i64;
  if ( v8 )
    v10 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MinTimeBetweenUpdates + v8);
  else
    v10 = 0i64;
  if ( v8 )
    v9 = (char *)&this->m_MinTimeBetweenUpdates + v8;
  v11 = action_context->mActionTreeComponentBase[v9[236]];
  if ( !v11 )
    v11 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(v11, v10, (ActionNodeRoot *)LODWORD(this->mNext), a4);
}

// File Line: 5392
// RVA: 0x37B4C0
void __fastcall SelectSuitableVehicleCondition::OnExitCallback(
        SelectSuitableVehicleCondition *this,
        ActionNode *action_node,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v4; // rdi
  UFG::ActionTreeComponentBase *v7; // rdx
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  UFG::SimObject *v10; // rbp
  unsigned int mUID; // eax
  bool v12; // zf
  __int64 v13; // rax
  UFG::ActionTreeComponentBase *v14; // rdx
  UFG::ActionTreeComponentBase *v15; // rcx
  UFG::SelectSuitableVehicle::Params params; // [rsp+20h] [rbp-28h] BYREF
  UFG::SimObject *value_uid; // [rsp+50h] [rbp+8h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  v4 = 0i64;
  value_uid = 0i64;
  if ( mOffset )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v7 = 0i64;
  if ( mOffset )
    v8 = (char *)&this->m_MyRoot + mOffset;
  else
    v8 = 0i64;
  v9 = action_context->mActionTreeComponentBase[v8[236]];
  if ( !v9 )
    v9 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
    v9,
    v7,
    (ActionNodeRoot *)this->m_VehicleUID,
    &value_uid);
  v10 = value_uid;
  mUID = this->m_FilterClassSymbol.mUID;
  params.maxSearchRadius = this->m_MaxSearchRadius;
  v12 = this->m_IgnoreMeshTest == 0;
  params.pVehicle = value_uid;
  params.filterClassSymbol.mUID = mUID;
  params.pActionContext = action_context;
  params.ignoreMeshTest = !v12;
  UFG::SelectSuitableVehicle::Cleanup(&params);
  v13 = this->m_MyRoot.mOffset;
  if ( v13 )
    v14 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v13);
  else
    v14 = 0i64;
  if ( v13 )
    v4 = (char *)&this->m_MyRoot + v13;
  v15 = action_context->mActionTreeComponentBase[v4[236]];
  if ( !v15 )
    v15 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
    v15,
    v14,
    (ActionNodeRoot *)this->m_VehicleUID,
    v10);
}

// File Line: 5417
// RVA: 0x372440
__int64 __fastcall SelectSuitableVehicleCondition::Match(
        SelectSuitableVehicleCondition *this,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v3; // rdi
  UFG::ActionTreeComponentBase *v6; // rdx
  char *v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rcx
  bool v9; // zf
  float mSimTime_Temp; // xmm6_4
  unsigned int mUID; // eax
  __int64 v12; // rax
  UFG::ActionTreeComponentBase *v13; // rdx
  char *v14; // rcx
  UFG::ActionTreeComponentBase *v15; // rcx
  unsigned int v16; // r9d
  __int64 v17; // rax
  UFG::ActionTreeComponentBase *v18; // rdx
  char *v19; // rcx
  UFG::ActionTreeComponentBase *v20; // rcx
  __int64 v21; // rax
  UFG::ActionTreeComponentBase *v22; // rdx
  char *v23; // rcx
  UFG::ActionTreeComponentBase *v24; // rcx
  __int64 v25; // rax
  UFG::ActionTreeComponentBase *v26; // rdx
  char *v27; // rcx
  UFG::ActionTreeComponentBase *v28; // rcx
  char v29; // al
  __int64 v30; // rcx
  char v31; // r9
  UFG::ActionTreeComponentBase *v32; // rdx
  char *v33; // rax
  UFG::ActionTreeComponentBase *v34; // rcx
  unsigned int v35; // r9d
  __int64 v36; // rax
  UFG::ActionTreeComponentBase *v37; // rdx
  char *v38; // rcx
  UFG::ActionTreeComponentBase *v39; // rcx
  __int64 v40; // rax
  UFG::ActionTreeComponentBase *v41; // rdx
  char *v42; // rcx
  UFG::ActionTreeComponentBase *v43; // rcx
  __int64 v44; // rax
  UFG::ActionTreeComponentBase *v45; // rdx
  UFG::ActionTreeComponentBase *v46; // rcx
  unsigned int value_uid[2]; // [rsp+20h] [rbp-48h] BYREF
  UFG::SelectSuitableVehicle::Params params; // [rsp+28h] [rbp-40h] BYREF
  unsigned int v50; // [rsp+90h] [rbp+28h] BYREF
  unsigned int v51; // [rsp+98h] [rbp+30h] BYREF
  unsigned int v52; // [rsp+A0h] [rbp+38h] BYREF
  unsigned int v53; // [rsp+A8h] [rbp+40h] BYREF

  mOffset = this->m_MyRoot.mOffset;
  v3 = 0i64;
  *(_QWORD *)value_uid = 0i64;
  if ( mOffset )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v6 = 0i64;
  if ( mOffset )
    v7 = (char *)&this->m_MyRoot + mOffset;
  else
    v7 = 0i64;
  v8 = action_context->mActionTreeComponentBase[v7[236]];
  if ( !v8 )
    v8 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
    v8,
    v6,
    (ActionNodeRoot *)this->m_VehicleUID,
    value_uid);
  v9 = this->m_IgnoreMeshTest == 0;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  params.maxSearchRadius = this->m_MaxSearchRadius;
  params.pVehicle = *(UFG::SimObject **)value_uid;
  mUID = this->m_FilterClassSymbol.mUID;
  params.ignoreMeshTest = !v9;
  params.filterClassSymbol.mUID = mUID;
  v12 = this->m_MyRoot.mOffset;
  params.pActionContext = action_context;
  *(float *)&v51 = -99999.0;
  if ( v12 )
    v13 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v12);
  else
    v13 = 0i64;
  if ( v12 )
    v14 = (char *)&this->m_MyRoot + v12;
  else
    v14 = 0i64;
  v15 = action_context->mActionTreeComponentBase[v14[236]];
  if ( !v15 )
    v15 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v15,
    v13,
    (ActionNodeRoot *)this->m_LastTimeMatchCalledUID,
    &v51);
  if ( (float)(mSimTime_Temp - *(float *)&v51) > this->m_TimeBeforeReset )
  {
    UFG::SelectSuitableVehicle::Cleanup(&params);
    UFG::SelectSuitableVehicle::SelectVehicle(&params);
  }
  v17 = this->m_MyRoot.mOffset;
  if ( v17 )
    v18 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v17);
  else
    v18 = 0i64;
  if ( v17 )
    v19 = (char *)&this->m_MyRoot + v17;
  else
    v19 = 0i64;
  v20 = action_context->mActionTreeComponentBase[v19[236]];
  if ( !v20 )
    v20 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
    v20,
    v18,
    (ActionNodeRoot *)this->m_LastTimeMatchCalledUID,
    v16);
  v21 = this->m_MyRoot.mOffset;
  *(float *)&v52 = -99999.0;
  *(float *)&v53 = -99999.0;
  if ( v21 )
    v22 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v21);
  else
    v22 = 0i64;
  if ( v21 )
    v23 = (char *)&this->m_MyRoot + v21;
  else
    v23 = 0i64;
  v24 = action_context->mActionTreeComponentBase[v23[236]];
  if ( !v24 )
    v24 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v24,
    v22,
    (ActionNodeRoot *)this->m_LastTimeUpdateCalledUID,
    &v52);
  v25 = this->m_MyRoot.mOffset;
  if ( v25 )
    v26 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v25);
  else
    v26 = 0i64;
  if ( v25 )
    v27 = (char *)&this->m_MyRoot + v25;
  else
    v27 = 0i64;
  v28 = action_context->mActionTreeComponentBase[v27[236]];
  if ( !v28 )
    v28 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v28,
    v26,
    (ActionNodeRoot *)this->m_TimeBetweenUpdatesUID,
    &v53);
  LOBYTE(v50) = 0;
  if ( (float)(mSimTime_Temp - *(float *)&v52) <= *(float *)&v53 )
  {
    v40 = this->m_MyRoot.mOffset;
    if ( v40 )
      v41 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v40);
    else
      v41 = 0i64;
    if ( v40 )
      v42 = (char *)&this->m_MyRoot + v40;
    else
      v42 = 0i64;
    v43 = action_context->mActionTreeComponentBase[v42[236]];
    if ( !v43 )
      v43 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
      v43,
      v41,
      (ActionNodeRoot *)this->m_PreviousReturnValueUID,
      (bool *)&v50);
  }
  else
  {
    v29 = UFG::SelectSuitableVehicle::Update(&params);
    v30 = this->m_MyRoot.mOffset;
    v31 = v29;
    LOBYTE(v50) = v29;
    if ( v30 )
      v32 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v30);
    else
      v32 = 0i64;
    if ( v30 )
      v33 = (char *)&this->m_MyRoot + v30;
    else
      v33 = 0i64;
    v34 = action_context->mActionTreeComponentBase[v33[236]];
    if ( !v34 )
      v34 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v34,
      v32,
      (ActionNodeRoot *)this->m_PreviousReturnValueUID,
      v31);
    v36 = this->m_MyRoot.mOffset;
    if ( v36 )
      v37 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v36);
    else
      v37 = 0i64;
    if ( v36 )
      v38 = (char *)&this->m_MyRoot + v36;
    else
      v38 = 0i64;
    v39 = action_context->mActionTreeComponentBase[v38[236]];
    if ( !v39 )
      v39 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v39,
      v37,
      (ActionNodeRoot *)this->m_LastTimeUpdateCalledUID,
      v35);
  }
  v44 = this->m_MyRoot.mOffset;
  if ( v44 )
    v45 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v44);
  else
    v45 = 0i64;
  if ( v44 )
    v3 = (char *)&this->m_MyRoot + v44;
  v46 = action_context->mActionTreeComponentBase[v3[236]];
  if ( !v46 )
    v46 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
    v46,
    v45,
    (ActionNodeRoot *)this->m_VehicleUID,
    params.pVehicle);
  return (unsigned __int8)v50;
}

// File Line: 5526
// RVA: 0x14AE620
__int64 dynamic_initializer_for__ScriptFakeHasHostageCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ScriptFakeHasHostageCondition", 0xFFFFFFFF);
  ScriptFakeHasHostageCondition::sClassNameUID = result;
  return result;
}

// File Line: 5529
// RVA: 0x3319D0
void __fastcall ScriptFakeHasHostageCondition::ScriptFakeHasHostageCondition(ScriptFakeHasHostageCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ScriptFakeHasHostageCondition::`vftable;
}

// File Line: 5534
// RVA: 0x33A9F0
void __fastcall ScriptFakeHasHostageCondition::~ScriptFakeHasHostageCondition(ScriptFakeHasHostageCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&ScriptFakeHasHostageCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5539
// RVA: 0x3723B0
bool __fastcall ScriptFakeHasHostageCondition::Match(
        ScriptFakeHasHostageCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::AIScriptInterfaceComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::AIScriptInterfaceComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[5].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[5].m_pComponent),
            ComponentOfTypeHK)
        && (BYTE1(ComponentOfTypeHK[32].m_BoundComponentHandles.mNode.mPrev) & 0x20) != 0;
  return result;
}

// File Line: 5562
// RVA: 0x14AE860
__int64 dynamic_initializer_for__TargetVisibleInAIDataCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetVisibleInAIDataCondition", 0xFFFFFFFF);
  TargetVisibleInAIDataCondition::sClassNameUID = result;
  return result;
}

// File Line: 5573
// RVA: 0x3326F0
void __fastcall TargetVisibleInAIDataCondition::TargetVisibleInAIDataCondition(TargetVisibleInAIDataCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetVisibleInAIDataCondition::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 278;
  this->m_MyRoot.mOffset = 0i64;
  this->m_MinTimeBetweenChecks = 0.2;
  *(_QWORD *)&this->m_MaxTimeBetweenChecks = 1053609165i64;
  *(_QWORD *)&this->m_NextTimeToCheckTargetIsVisibleUID = 0i64;
}

// File Line: 5583
// RVA: 0x33B6B0
void __fastcall TargetVisibleInAIDataCondition::~TargetVisibleInAIDataCondition(TargetVisibleInAIDataCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetVisibleInAIDataCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5588
// RVA: 0x383CC0
void __fastcall TargetVisibleInAIDataCondition::ResolveReferences(
        TargetVisibleInAIDataCondition *this,
        ActionNode *action_node)
{
  Expression::IMemberMap *v3; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  unsigned int ValueUID; // eax
  unsigned int m_NextTimeToCheckTargetIsVisibleUID; // ecx
  unsigned int v7; // eax
  unsigned int m_PreviousTargetUID; // ecx

  v3 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v3 )
    v3 = (Expression::IMemberMap *)((char *)v3 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v3;
  ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(this->m_TargetIsVisibleUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  m_NextTimeToCheckTargetIsVisibleUID = this->m_NextTimeToCheckTargetIsVisibleUID;
  this->m_TargetIsVisibleUID = ValueUID;
  v7 = UFG::ActionTreeComponentBase::MakeValueUID(
         m_NextTimeToCheckTargetIsVisibleUID,
         eACTION_TREE_MEMORY_ELEMENT_FLOAT);
  m_PreviousTargetUID = this->m_PreviousTargetUID;
  this->m_NextTimeToCheckTargetIsVisibleUID = v7;
  this->m_PreviousTargetUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                m_PreviousTargetUID,
                                eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
}

// File Line: 5602
// RVA: 0x3740C0
__int64 __fastcall TargetVisibleInAIDataCondition::Match(
        TargetVisibleInAIDataCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  char *v4; // rdi
  float mSimTime_Temp; // xmm6_4
  UFG::ActiveAIEntityComponent *v7; // r15
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v10; // rcx
  UFG::SimComponent *m_pComponent; // r14
  __int16 v12; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v14; // r12
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v16; // rdx
  char *v17; // rcx
  UFG::ActionTreeComponentBase *v18; // rcx
  __int64 v19; // rax
  UFG::ActionTreeComponentBase *v20; // rdx
  char *v21; // rcx
  UFG::ActionTreeComponentBase *v22; // rcx
  bool v23; // al
  unsigned int v24; // r9d
  __int64 v25; // rax
  UFG::ActionTreeComponentBase *v26; // rdx
  char *v27; // rcx
  UFG::ActionTreeComponentBase *v28; // rcx
  __int64 v29; // rax
  UFG::ActionTreeComponentBase *v30; // rdx
  char *v31; // rcx
  UFG::ActionTreeComponentBase *v32; // rcx
  __int64 v33; // r14
  __int64 v34; // r14
  int v35; // xmm1_4
  int v36; // xmm0_4
  UFG::SimObject *m_pSimObject; // rcx
  int mValue; // r14d
  UFG::SimComponent *v39; // rdx
  UFG::NavManagerVtbl *vfptr; // rax
  bool v41; // zf
  __int64 v42; // rax
  UFG::ActionTreeComponentBase *v43; // rdx
  char *v44; // rcx
  UFG::ActionTreeComponentBase *v45; // rcx
  bool v46; // r9
  __m128 v47; // xmm0
  char *v48; // rcx
  __int64 v49; // rax
  UFG::ActionTreeComponentBase *v50; // rdx
  UFG::ActionTreeComponentBase *v51; // rcx
  float x; // [rsp+18h] [rbp-19h] BYREF
  char v54[12]; // [rsp+1Ch] [rbp-15h]
  UFG::qVector3 v55; // [rsp+28h] [rbp-9h] BYREF
  UFG::qVector3 v56[3]; // [rsp+38h] [rbp+7h] BYREF
  unsigned int v57; // [rsp+98h] [rbp+67h] BYREF
  unsigned int vars0; // [rsp+A0h] [rbp+6Fh] BYREF
  void *retaddr; // [rsp+A8h] [rbp+77h] BYREF
  UFG::SimObject *value_uid; // [rsp+B0h] [rbp+7Fh] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v7 = ComponentOfTypeHK;
  }
  else
  {
    v7 = 0i64;
  }
  v10 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v10 )
  {
    v12 = v10->m_Flags;
    if ( (v12 & 0x4000) != 0 )
    {
      m_pComponent = v10->m_Components.p[20].m_pComponent;
    }
    else if ( v12 >= 0 )
    {
      if ( (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v10->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( v7 && m_pComponent )
  {
    v14 = *(UFG::SimObject **)(56i64
                             * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                  + *(_QWORD *)&m_pComponent[1].m_Flags
                                                  + 8i64)
                             + *(_QWORD *)&m_pComponent[1].m_TypeUID
                             + 40);
    mOffset = this->m_MyRoot.mOffset;
    *(float *)&vars0 = FLOAT_N99999_0;
    value_uid = 0i64;
    if ( mOffset )
      v16 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v16 = 0i64;
    if ( mOffset )
      v17 = (char *)&this->m_MyRoot + mOffset;
    else
      v17 = 0i64;
    v18 = action_context->mActionTreeComponentBase[v17[236]];
    if ( !v18 )
      v18 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
      v18,
      v16,
      (ActionNodeRoot *)this->m_PreviousTargetUID,
      &value_uid);
    v19 = this->m_MyRoot.mOffset;
    if ( v19 )
      v20 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v19);
    else
      v20 = 0i64;
    if ( v19 )
      v21 = (char *)&this->m_MyRoot + v19;
    else
      v21 = 0i64;
    v22 = action_context->mActionTreeComponentBase[v21[236]];
    if ( !v22 )
      v22 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
      v22,
      v20,
      (ActionNodeRoot *)this->m_NextTimeToCheckTargetIsVisibleUID,
      &vars0);
    v23 = mSimTime_Temp > *(float *)&vars0 || v14 != value_uid;
    if ( v14 && v23 )
    {
      UFG::GetRandomNumberInRange(this->m_MinTimeBetweenChecks, this->m_MaxTimeBetweenChecks);
      v25 = this->m_MyRoot.mOffset;
      if ( v25 )
        v26 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v25);
      else
        v26 = 0i64;
      if ( v25 )
        v27 = (char *)&this->m_MyRoot + v25;
      else
        v27 = 0i64;
      v28 = action_context->mActionTreeComponentBase[v27[236]];
      if ( !v28 )
        v28 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
        v28,
        v26,
        (ActionNodeRoot *)this->m_NextTimeToCheckTargetIsVisibleUID,
        v24);
      v29 = this->m_MyRoot.mOffset;
      if ( v29 )
        v30 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v29);
      else
        v30 = 0i64;
      if ( v29 )
        v31 = (char *)&this->m_MyRoot + v29;
      else
        v31 = 0i64;
      v32 = action_context->mActionTreeComponentBase[v31[236]];
      if ( !v32 )
        v32 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
        v32,
        v30,
        (ActionNodeRoot *)this->m_PreviousTargetUID,
        v14);
      v33 = *(_QWORD *)(56i64
                      * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                           + *(_QWORD *)&m_pComponent[1].m_Flags
                                           + 8i64)
                      + *(_QWORD *)&m_pComponent[1].m_TypeUID
                      + 40);
      if ( v33 )
      {
        v34 = *(_QWORD *)(v33 + 88);
        if ( v34 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v34);
          v35 = *(_DWORD *)(v34 + 180);
          x = *(float *)(v34 + 176);
          v36 = *(_DWORD *)(v34 + 184);
          *(_DWORD *)v54 = v35;
          *(_DWORD *)&v54[4] = v36;
          if ( use_nearest_point )
          {
            v55 = UFG::qVector3::msZero;
            if ( ((unsigned __int8 (__fastcall *)(UFG::NavManager *, float *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->GetClosestAIMesh)(
                   UFG::NavManager::ms_pInstance,
                   &x,
                   &v55) )
            {
              x = v55.x;
              *(_QWORD *)v54 = *(_QWORD *)&v55.y;
            }
          }
          m_pSimObject = v7->m_pSimObject;
          mValue = (unsigned __int8)this->m_ConstrainToSidewalks.mValue;
          v56[0] = UFG::qVector3::msZero;
          if ( m_pSimObject )
            v39 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
          else
            v39 = 0i64;
          retaddr = *(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)((char *)&v39[2].m_BoundComponentHandles.mNode.mNext + 4);
          if ( mValue )
            HIDWORD(retaddr) |= 0x200u;
          else
            HIDWORD(retaddr) = HIDWORD(*(unsigned __int64 *)((char *)&v39[2].m_BoundComponentHandles.mNode.mNext + 4)) & 0xFFFFFDFF;
          vfptr = UFG::NavManager::ms_pInstance->vfptr;
          *(_QWORD *)&v54[4] = v56;
          v41 = ((unsigned __int8 (__fastcall *)(UFG::NavManager *, UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **, float *, void **))vfptr->AIRayCastHits)(
                  UFG::NavManager::ms_pInstance,
                  &v39[1].m_SafePointerList.mNode.mNext,
                  &x,
                  &retaddr) == 0;
          v42 = this->m_MyRoot.mOffset;
          if ( v41 )
          {
            if ( v42 )
              v43 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v42);
            else
              v43 = 0i64;
            if ( v42 )
              v44 = (char *)&this->m_MyRoot + v42;
            else
              v44 = 0i64;
            v45 = action_context->mActionTreeComponentBase[v44[236]];
            if ( !v45 )
              v45 = action_context->mActionTreeComponentBase[1];
            v46 = 1;
          }
          else
          {
            v47 = (__m128)*(unsigned int *)v54;
            v47.m128_f32[0] = (float)((float)(*(float *)v54 - v56[0].y) * (float)(*(float *)v54 - v56[0].y))
                            + (float)((float)(x - v56[0].x) * (float)(x - v56[0].x));
            v46 = _mm_sqrt_ps(v47).m128_f32[0] < 0.30000001;
            if ( v42 )
              v43 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v42);
            else
              v43 = 0i64;
            if ( v42 )
              v48 = (char *)&this->m_MyRoot + v42;
            else
              v48 = 0i64;
            v45 = action_context->mActionTreeComponentBase[v48[236]];
            if ( !v45 )
              v45 = action_context->mActionTreeComponentBase[1];
          }
          UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
            v45,
            v43,
            (ActionNodeRoot *)this->m_TargetIsVisibleUID,
            v46);
        }
      }
    }
  }
  v49 = this->m_MyRoot.mOffset;
  LOBYTE(v57) = 0;
  if ( v49 )
    v50 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v49);
  else
    v50 = 0i64;
  if ( v49 )
    v4 = (char *)&this->m_MyRoot + v49;
  v51 = action_context->mActionTreeComponentBase[v4[236]];
  if ( !v51 )
    v51 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v51,
    v50,
    (ActionNodeRoot *)this->m_TargetIsVisibleUID,
    (bool *)&v57);
  return (unsigned __int8)v57;
}

// File Line: 5708
// RVA: 0x14AE780
__int64 dynamic_initializer_for__TargetIsEnemyOfMineCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsEnemyOfMineCondition", 0xFFFFFFFF);
  TargetIsEnemyOfMineCondition::sClassNameUID = result;
  return result;
}

// File Line: 5714
// RVA: 0x3325E0
void __fastcall TargetIsEnemyOfMineCondition::TargetIsEnemyOfMineCondition(TargetIsEnemyOfMineCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsEnemyOfMineCondition::`vftable;
  this->m_TargetType.mValue = 22;
}

// File Line: 5719
// RVA: 0x33B670
void __fastcall TargetIsEnemyOfMineCondition::~TargetIsEnemyOfMineCondition(TargetIsEnemyOfMineCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsEnemyOfMineCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5724
// RVA: 0x372FF0
bool __fastcall TargetIsEnemyOfMineCondition::Match(TargetIsEnemyOfMineCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::ActiveAIEntityComponent *v6; // rdi
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  m_pComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v6 = ComponentOfTypeHK;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      m_pComponent = v9->m_Components.p[20].m_pComponent;
    }
    else if ( v10 >= 0 )
    {
      if ( (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v9->m_Components.p[20].m_pComponent;
    }
  }
  return v6
      && m_pComponent
      && UFG::ActiveAIEntityComponent::IsEnemyOfMine(
           v6,
           *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40));
}

// File Line: 5752
// RVA: 0x14ADB60
__int64 dynamic_initializer_for__CombatRegionExistsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CombatRegionExistsCondition", 0xFFFFFFFF);
  CombatRegionExistsCondition::sClassNameUID = result;
  return result;
}

// File Line: 5755
// RVA: 0x32D3F0
void __fastcall CombatRegionExistsCondition::CombatRegionExistsCondition(CombatRegionExistsCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionExistsCondition::`vftable;
}

// File Line: 5759
// RVA: 0x335C60
void __fastcall CombatRegionExistsCondition::~CombatRegionExistsCondition(CombatRegionExistsCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionExistsCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5763
// RVA: 0x36F160
bool __fastcall CombatRegionExistsCondition::Match(CombatRegionExistsCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  bool v6; // zf

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return MEMORY[0x3D8] != 0i64;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    return UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer)->m_pCombatRegion.m_pPointer != 0i64;
  if ( (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::ActiveAIEntityComponent::_TypeUID;
    return *(_QWORD *)&UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5)[15].m_TypeUID != 0i64;
  }
  v6 = (m_Flags & 0x1000) == 0;
  v5 = UFG::ActiveAIEntityComponent::_TypeUID;
  if ( !v6 )
    return *(_QWORD *)&UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5)[15].m_TypeUID != 0i64;
  return *(_QWORD *)&UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActiveAIEntityComponent::_TypeUID)[15].m_TypeUID != 0i64;
}

// File Line: 5788
// RVA: 0x14ADB80
__int64 dynamic_initializer_for__CombatRegionIsInsideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CombatRegionIsInsideCondition", 0xFFFFFFFF);
  CombatRegionIsInsideCondition::sClassNameUID = result;
  return result;
}

// File Line: 5791
// RVA: 0x32D420
void __fastcall CombatRegionIsInsideCondition::CombatRegionIsInsideCondition(CombatRegionIsInsideCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionIsInsideCondition::`vftable;
}

// File Line: 5795
// RVA: 0x335CA0
void __fastcall CombatRegionIsInsideCondition::~CombatRegionIsInsideCondition(CombatRegionIsInsideCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionIsInsideCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5799
// RVA: 0x36F200
bool __fastcall CombatRegionIsInsideCondition::Match(
        CombatRegionIsInsideCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __int16 m_Flags; // dx
  UFG::CombatRegion *v6; // rdi
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  UFG::qVector3 vPoint; // [rsp+20h] [rbp-48h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  ComponentOfTypeHK = 0i64;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
  }
  v6 = ComponentOfTypeHK->m_pCombatRegion.m_pPointer;
  if ( !v6 )
    return 1;
  x = UFG::qVector3::msAxisZ.x;
  y = UFG::qVector3::msAxisZ.y;
  z = UFG::qVector3::msAxisZ.z;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v10 = y + m_pTransformNodeComponent->mWorldTransform.v3.y;
  v11 = z + m_pTransformNodeComponent->mWorldTransform.v3.z;
  vPoint.x = x + m_pTransformNodeComponent->mWorldTransform.v3.x;
  vPoint.y = v10;
  vPoint.z = v11;
  return UFG::CombatRegion::IsHitPoint(v6, &vPoint);
}

// File Line: 5835
// RVA: 0x14ADBC0
__int64 dynamic_initializer_for__CombatRegionTargetIsInsideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CombatRegionTargetIsInsideCondition", 0xFFFFFFFF);
  CombatRegionTargetIsInsideCondition::sClassNameUID = result;
  return result;
}

// File Line: 5842
// RVA: 0x32D520
void __fastcall CombatRegionTargetIsInsideCondition::CombatRegionTargetIsInsideCondition(
        CombatRegionTargetIsInsideCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionTargetIsInsideCondition::`vftable;
  this->m_TargetType.mValue = 22;
  this->m_FixZForCharacter = 1;
}

// File Line: 5847
// RVA: 0x335CE0
void __fastcall CombatRegionTargetIsInsideCondition::~CombatRegionTargetIsInsideCondition(
        CombatRegionTargetIsInsideCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionTargetIsInsideCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5851
// RVA: 0x36F320
bool __fastcall CombatRegionTargetIsInsideCondition::Match(
        CombatRegionTargetIsInsideCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::ActiveAIEntityComponent *v4; // rbx
  UFG::SimComponent *m_pComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v9; // rcx
  __int16 v10; // dx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax
  UFG::CombatRegion *v12; // rsi
  __int64 v13; // rbx
  UFG::RegionComponent *mpRegion; // rax
  UFG::TransformNodeComponent *v15; // rbx
  bool v16; // zf
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 vPoint; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v9 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 || v10 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    }
    else if ( (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v9,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                          v9,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v4 = ComponentOfType;
  }
  if ( !m_pComponent )
    return 0;
  if ( !v4 )
    return 0;
  v12 = v4->m_pCombatRegion.m_pPointer;
  v13 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(this->m_TargetType.mValue + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64)
                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                  + 40);
  if ( !v13 )
    return 0;
  if ( !v12 )
    return 1;
  mpRegion = v12->mpRegion;
  if ( !mpRegion || !mpRegion->mpRegion.mPtr )
    return 1;
  v15 = *(UFG::TransformNodeComponent **)(v13 + 88);
  if ( !v15 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v15);
  v16 = this->m_FixZForCharacter == 0;
  x = v15->mWorldTransform.v3.x;
  y = v15->mWorldTransform.v3.y;
  z = v15->mWorldTransform.v3.z;
  vPoint.x = x;
  vPoint.y = y;
  vPoint.z = z;
  if ( !v16 )
  {
    vPoint.x = x + UFG::qVector3::msAxisZ.x;
    vPoint.y = y + UFG::qVector3::msAxisZ.y;
    vPoint.z = z + UFG::qVector3::msAxisZ.z;
  }
  return UFG::CombatRegion::IsHitPoint(v12, &vPoint);
}

// File Line: 5905
// RVA: 0x14AE1E0
__int64 dynamic_initializer_for__IsInCrosswalkCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsInCrosswalkCondition", 0xFFFFFFFF);
  IsInCrosswalkCondition::sClassNameUID = result;
  return result;
}

// File Line: 5908
// RVA: 0x330250
void __fastcall IsInCrosswalkCondition::IsInCrosswalkCondition(IsInCrosswalkCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsInCrosswalkCondition::`vftable;
}

// File Line: 5912
// RVA: 0x338F90
void __fastcall IsInCrosswalkCondition::~IsInCrosswalkCondition(IsInCrosswalkCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsInCrosswalkCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5916
// RVA: 0x370E90
bool __fastcall IsInCrosswalkCondition::Match(IsInCrosswalkCondition *this, ActionContext *action_context)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax
  void *(__fastcall *vecDelDtor)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  __int64 v5; // rcx
  UFG::SimObjectGame *v6; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 v11; // dx

  GroupComponent = UFG::GroupComponent::GetGroupComponent((UFG::SimObjectGame *)action_context->mSimObject.m_pPointer);
  if ( GroupComponent )
  {
    vecDelDtor = GroupComponent[32].__vecDelDtor;
    if ( vecDelDtor )
    {
      v5 = *((_QWORD *)vecDelDtor + 33);
      if ( v5 )
      {
        v6 = *(UFG::SimObjectGame **)(v5 + 192);
        if ( v6 )
        {
          m_Flags = v6->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::ActiveAIEntityComponent *)v6->m_Components.p[22].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            m_pComponent = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v6,
                                                              UFG::AIEntityComponent::_TypeUID)
                                                          : UFG::SimObject::GetComponentOfType(
                                                              v6,
                                                              UFG::AIEntityComponent::_TypeUID));
          }
          else
          {
            m_pComponent = (UFG::ActiveAIEntityComponent *)v6->m_Components.p[22].m_pComponent;
          }
          if ( m_pComponent )
            return m_pComponent->m_WanderData.mAtCrossWalk;
        }
      }
    }
  }
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((v11 = m_pPointer->m_Flags, (v11 & 0x4000) != 0) || v11 < 0
      ? (m_pComponent = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer))
      : (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
      ? (m_pComponent = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::ActiveAIEntityComponent::_TypeUID))
      : (m_pComponent = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::ActiveAIEntityComponent::_TypeUID)),
        m_pComponent) )
  {
    return m_pComponent->m_WanderData.mAtCrossWalk;
  }
  else
  {
    return 0;
  }
}

// File Line: 5964
// RVA: 0x14AD9E0
__int64 dynamic_initializer_for__AttackRequestCanceledCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackRequestCanceledCondition", 0xFFFFFFFF);
  AttackRequestCanceledCondition::sClassNameUID = result;
  return result;
}

// File Line: 5970
// RVA: 0x32C780
void __fastcall AttackRequestCanceledCondition::AttackRequestCanceledCondition(AttackRequestCanceledCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRequestCanceledCondition::`vftable;
  this->m_AttackType.mValue = 0;
}

// File Line: 5975
// RVA: 0x335330
void __fastcall AttackRequestCanceledCondition::~AttackRequestCanceledCondition(AttackRequestCanceledCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRequestCanceledCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 5980
// RVA: 0x36EFC0
bool __fastcall AttackRequestCanceledCondition::Match(
        AttackRequestCanceledCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HasAttackRequestComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::HasAttackRequestComponent::_TypeUID)),
             m_pComponent = ComponentOfType)
          : (m_pComponent = m_pPointer->m_Components.p[35].m_pComponent),
            m_pComponent)
        && UFG::Metrics::msInstance.mSimTime_Temp < *((float *)&m_pComponent[1].m_BoundComponentHandles.mNode.mPrev
                                                    + (unsigned __int8)this->m_AttackType.mValue);
  return result;
}

// File Line: 6005
// RVA: 0x14ADFA0
__int64 dynamic_initializer_for__HasAIDriverCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasAIDriverCondition", 0xFFFFFFFF);
  HasAIDriverCondition::sClassNameUID = result;
  return result;
}

// File Line: 6008
// RVA: 0x32F710
void __fastcall HasAIDriverCondition::HasAIDriverCondition(HasAIDriverCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HasAIDriverCondition::`vftable;
}

// File Line: 6013
// RVA: 0x338150
void __fastcall HasAIDriverCondition::~HasAIDriverCondition(HasAIDriverCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&HasAIDriverCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 6018
// RVA: 0x3701B0
bool __fastcall HasAIDriverCondition::Match(HasAIDriverCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  bool v6; // zf

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    return UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer) != 0i64;
  if ( (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::AiDriverComponent::_TypeUID;
    return UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5) != 0i64;
  }
  v6 = (m_Flags & 0x1000) == 0;
  v5 = UFG::AiDriverComponent::_TypeUID;
  if ( !v6 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5) != 0i64;
  return UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AiDriverComponent::_TypeUID) != 0i64;
}

// File Line: 6039
// RVA: 0x14ADD20
__int64 dynamic_initializer_for__DriverFlagAvoidPedsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverFlagAvoidPedsCondition", 0xFFFFFFFF);
  DriverFlagAvoidPedsCondition::sClassNameUID = result;
  return result;
}

// File Line: 6044
// RVA: 0x32DD40
void __fastcall DriverFlagAvoidPedsCondition::DriverFlagAvoidPedsCondition(DriverFlagAvoidPedsCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagAvoidPedsCondition::`vftable;
  this->m_FlagSet = 1;
}

// File Line: 6049
// RVA: 0x336330
void __fastcall DriverFlagAvoidPedsCondition::~DriverFlagAvoidPedsCondition(DriverFlagAvoidPedsCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagAvoidPedsCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 6054
// RVA: 0x36F9C0
bool __fastcall DriverFlagAvoidPedsCondition::Match(DriverFlagAvoidPedsCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::AiDriverComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::AiDriverComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_bAvoidPeds == (this->m_FlagSet != 0);
  return result;
}

// File Line: 6079
// RVA: 0x14ADD00
__int64 dynamic_initializer_for__DriverFlagAllowedToPassCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverFlagAllowedToPassCondition", 0xFFFFFFFF);
  DriverFlagAllowedToPassCondition::sClassNameUID = result;
  return result;
}

// File Line: 6084
// RVA: 0x32DD00
void __fastcall DriverFlagAllowedToPassCondition::DriverFlagAllowedToPassCondition(
        DriverFlagAllowedToPassCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagAllowedToPassCondition::`vftable;
  this->m_FlagSet = 1;
}

// File Line: 6089
// RVA: 0x3362F0
void __fastcall DriverFlagAllowedToPassCondition::~DriverFlagAllowedToPassCondition(
        DriverFlagAllowedToPassCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagAllowedToPassCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 6094
// RVA: 0x36F920
bool __fastcall DriverFlagAllowedToPassCondition::Match(
        DriverFlagAllowedToPassCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::AiDriverComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::AiDriverComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_bAllowedToPass == (this->m_FlagSet != 0);
  return result;
}

// File Line: 6119
// RVA: 0x14ADD60
__int64 dynamic_initializer_for__DriverFlagStayOffSidewalkCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverFlagStayOffSidewalkCondition", 0xFFFFFFFF);
  DriverFlagStayOffSidewalkCondition::sClassNameUID = result;
  return result;
}

// File Line: 6124
// RVA: 0x32DDC0
void __fastcall DriverFlagStayOffSidewalkCondition::DriverFlagStayOffSidewalkCondition(
        DriverFlagStayOffSidewalkCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagStayOffSidewalkCondition::`vftable;
  this->m_FlagSet = 1;
}

// File Line: 6129
// RVA: 0x3363B0
void __fastcall DriverFlagStayOffSidewalkCondition::~DriverFlagStayOffSidewalkCondition(
        DriverFlagStayOffSidewalkCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagStayOffSidewalkCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 6134
// RVA: 0x36FB00
bool __fastcall DriverFlagStayOffSidewalkCondition::Match(
        DriverFlagStayOffSidewalkCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::AiDriverComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::AiDriverComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_bStayOffSidewalk == (this->m_FlagSet != 0);
  return result;
}

// File Line: 6159
// RVA: 0x14ADD40
__int64 dynamic_initializer_for__DriverFlagRespectSpeedLimitCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverFlagRespectSpeedLimitCondition", 0xFFFFFFFF);
  DriverFlagRespectSpeedLimitCondition::sClassNameUID = result;
  return result;
}

// File Line: 6164
// RVA: 0x32DD80
void __fastcall DriverFlagRespectSpeedLimitCondition::DriverFlagRespectSpeedLimitCondition(
        DriverFlagRespectSpeedLimitCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagRespectSpeedLimitCondition::`vftable;
  this->m_FlagSet = 1;
}

// File Line: 6169
// RVA: 0x336370
void __fastcall DriverFlagRespectSpeedLimitCondition::~DriverFlagRespectSpeedLimitCondition(
        DriverFlagRespectSpeedLimitCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagRespectSpeedLimitCondition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 6174
// RVA: 0x36FA60
bool __fastcall DriverFlagRespectSpeedLimitCondition::Match(
        DriverFlagRespectSpeedLimitCondition *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::AiDriverComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::AiDriverComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_bRespectSpeedLimit == (this->m_FlagSet != 0);
  return result;
}

// File Line: 6202
// RVA: 0x14AE760
__int64 dynamic_initializer_for__TargetDistanceRelativeDesiredRangeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDistanceRelativeDesiredRangeCondition", 0xFFFFFFFF);
  TargetDistanceRelativeDesiredRangeCondition::sClassNameUID = result;
  return result;
}

// File Line: 6218
// RVA: 0x332590
void __fastcall TargetDistanceRelativeDesiredRangeCondition::TargetDistanceRelativeDesiredRangeCondition(
        TargetDistanceRelativeDesiredRangeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDistanceRelativeDesiredRangeCondition::`vftable;
  this->m_eTargetType.mValue = 22;
  *(_QWORD *)&this->m_eInEqualityOperator.mValue = 3i64;
  this->m_fBuffer = 0.0;
  *(_WORD *)&this->m_2DOnly = 0;
}

// File Line: 6223
// RVA: 0x372DE0
char __fastcall TargetDistanceRelativeDesiredRangeCondition::Match(
        TargetDistanceRelativeDesiredRangeCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::TransformNodeComponent *mNext; // rdi
  float x; // xmm0_4
  float y; // xmm6_4
  float z; // xmm1_4
  float v14; // xmm6_4
  unsigned int mValue; // eax
  float v16; // xmm1_4
  signed int v17; // ecx
  UFG::qMatrix44 matSimObject; // [rsp+20h] [rbp-68h] BYREF
  float outMinimumDesired; // [rsp+98h] [rbp+10h] BYREF
  float outMaximumDesired; // [rsp+A0h] [rbp+18h] BYREF
  float outDesired; // [rsp+A8h] [rbp+20h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(this->m_eTargetType.mValue + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  if ( !v8 )
    return 0;
  UFG::TargetingSystemBaseComponent::FindMatrix(v8, &matSimObject);
  mNext = (UFG::TransformNodeComponent *)pContext->mSimObject.m_pPointer;
  if ( mNext )
    mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
  x = mNext->mWorldTransform.v3.x;
  y = mNext->mWorldTransform.v3.y;
  z = mNext->mWorldTransform.v3.z;
  if ( this->m_2DOnly )
  {
    if ( this->m_ZOnly )
      return 0;
    v14 = (float)((float)(y - matSimObject.v3.y) * (float)(y - matSimObject.v3.y))
        + (float)((float)(x - matSimObject.v3.x) * (float)(x - matSimObject.v3.x));
  }
  else if ( this->m_ZOnly )
  {
    v14 = COERCE_FLOAT(COERCE_UNSIGNED_INT(z - matSimObject.v3.z) & _xmm)
        * COERCE_FLOAT(COERCE_UNSIGNED_INT(z - matSimObject.v3.z) & _xmm);
  }
  else
  {
    v14 = (float)((float)((float)(y - matSimObject.v3.y) * (float)(y - matSimObject.v3.y))
                + (float)((float)(x - matSimObject.v3.x) * (float)(x - matSimObject.v3.x)))
        + (float)((float)(z - matSimObject.v3.z) * (float)(z - matSimObject.v3.z));
  }
  UFG::GetDesiredRanges(
    (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer,
    &outMinimumDesired,
    &outMaximumDesired,
    &outDesired);
  mValue = this->m_eAIDesiredRange.mValue;
  if ( mValue )
  {
    if ( mValue == 1 )
      v16 = outMaximumDesired;
    else
      v16 = outDesired;
  }
  else
  {
    v16 = outMinimumDesired;
  }
  v17 = this->m_eInEqualityOperator.mValue;
  if ( ((v17 - 2) & 0xFFFFFFFD) != 0 )
    return CompareFloat(
             (UFG::InEqualityOperator)v17,
             (float)(v16 - this->m_fBuffer) * (float)(v16 - this->m_fBuffer),
             v14);
  else
    return CompareFloat(
             (UFG::InEqualityOperator)v17,
             (float)(v16 + this->m_fBuffer) * (float)(v16 + this->m_fBuffer),
             v14);
}

