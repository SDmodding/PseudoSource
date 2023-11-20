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
  ReceivedScriptCommandCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ReceivedScriptCommandCondition::`vftable';
}

// File Line: 91
// RVA: 0x371D90
char __fastcall ReceivedScriptCommandCondition::Match(ReceivedScriptCommandCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = v2->m_Components.p[5].m_pComponent;
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID);
    else
      v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[5].m_pComponent;
  }
  if ( !v4 )
    return 0;
  if ( v4[1].m_TypeUID || HIDWORD(v4[1].m_SafePointerList.mNode.mNext) )
    return 1;
  return 0;
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
void __fastcall CollisionAvoidanceIsActiveCondition::CollisionAvoidanceIsActiveCondition(CollisionAvoidanceIsActiveCondition *this)
{
  CollisionAvoidanceIsActiveCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollisionAvoidanceIsActiveCondition::`vftable';
}

// File Line: 124
// RVA: 0x36F0E0
bool __fastcall CollisionAvoidanceIsActiveCondition::Match(CollisionAvoidanceIsActiveCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      else
        v4 = (UFG::ActiveAIEntityComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v2->vfptr,
                                                                 UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    if ( v4 )
      result = 1;
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
void __fastcall HasRangedWeaponEquippedWithAmmoCondition::HasRangedWeaponEquippedWithAmmoCondition(HasRangedWeaponEquippedWithAmmoCondition *this)
{
  HasRangedWeaponEquippedWithAmmoCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HasRangedWeaponEquippedWithAmmoCondition::`vftable';
}

// File Line: 162
// RVA: 0x370560
bool __fastcall HasRangedWeaponEquippedWithAmmoCondition::Match(HasRangedWeaponEquippedWithAmmoCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v4; // dx
  unsigned int v5; // edx
  UFG::TargetingSystemBaseComponent *v6; // rax
  bool v7; // zf
  UFG::TargetingSystemBaseComponent *v8; // rax

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !v2 )
    return UFG::HasRangedWeaponEquippedWithAmmo(0i64);
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 || (v4 & 0x8000u) != 0 )
    return UFG::HasRangedWeaponEquippedWithAmmo((UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent);
  if ( (v4 >> 13) & 1 )
  {
    v5 = UFG::TargetingSystemBaseComponent::_TypeUID;
LABEL_8:
    v6 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, v5);
    return UFG::HasRangedWeaponEquippedWithAmmo(v6);
  }
  v7 = ((v4 >> 12) & 1) == 0;
  v5 = UFG::TargetingSystemBaseComponent::_TypeUID;
  if ( !v7 )
    goto LABEL_8;
  v8 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v2->vfptr,
                                              UFG::TargetingSystemBaseComponent::_TypeUID);
  return UFG::HasRangedWeaponEquippedWithAmmo(v8);
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
void __fastcall HasAnyDangerousEntitiesOrPointsCondition::HasAnyDangerousEntitiesOrPointsCondition(HasAnyDangerousEntitiesOrPointsCondition *this)
{
  HasAnyDangerousEntitiesOrPointsCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HasAnyDangerousEntitiesOrPointsCondition::`vftable';
}

// File Line: 192
// RVA: 0x3702D0
bool __fastcall HasAnyDangerousEntitiesOrPointsCondition::Match(HasAnyDangerousEntitiesOrPointsCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      else
        v4 = (UFG::ActiveAIEntityComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v2->vfptr,
                                                                 UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    if ( v4 && (signed int)v4->m_ThreatTargets.size > 0 )
      result = 1;
  }
  return result;
}

// File Line: 218
// RVA: 0x14B6D80
__int64 dynamic_initializer_for__geAIStimulusTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&geAIStimulusTypeEnum, UFG::g_StimulusName, 116, 0i64);
  return atexit(dynamic_atexit_destructor_for__geAIStimulusTypeEnum__);
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
  return atexit(dynamic_atexit_destructor_for__geAIStimulusHandlerTypeEnum__);
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
  ReceivedStimulusCondition *v1; // rbx
  IConditionInit *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rax

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v2 = (IConditionInit *)&v1->vfptr;
  v3 = (UFG::qNode<IConditionInit,IConditionInit> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ReceivedStimulusCondition::`vftable'{for `Condition'};
  v2->vfptr = (IConditionInitVtbl *)&ReceivedStimulusCondition::`vftable'{for `IConditionInit'};
  *(_DWORD *)&v1->m_Stimulus.mValue = 1441792;
  *(_WORD *)&v1->m_OnlyCareAboutStimuliFromFactionStandingType.mValue = 258;
  v1->m_MyRoot.mOffset = 0i64;
  v1->m_MinSecondsSinceReceived = 0.25;
  v1->m_MaxSecondsSinceReceived = 0.25;
  *(_QWORD *)&v1->m_SecondsSinceReceivedUID = 0i64;
  v1->m_EnteredUID = 0;
}

// File Line: 252
// RVA: 0x33A4A0
void __fastcall ReceivedStimulusCondition::~ReceivedStimulusCondition(ReceivedStimulusCondition *this)
{
  ReceivedStimulusCondition *v1; // r8
  UFG::qNode<IConditionInit,IConditionInit> *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v4; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ReceivedStimulusCondition::`vftable'{for `Condition'};
  this->vfptr = (IConditionInitVtbl *)&ReceivedStimulusCondition::`vftable'{for `IConditionInit'};
  v2 = (UFG::qNode<IConditionInit,IConditionInit> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 259
// RVA: 0x3836F0
void __fastcall ReceivedStimulusCondition::ResolveReferences(ReceivedStimulusCondition *this, ActionNode *action_node)
{
  ReceivedStimulusCondition *v2; // rdi
  ActionNode *v3; // rbx
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *v5; // rcx
  signed __int64 v6; // rax
  ActionNodeRoot *v7; // rax
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  hkSeekableStreamReader *v12; // rax
  hkSeekableStreamReader *v13; // [rsp+20h] [rbp-18h]
  void (__fastcall *v14)(ReceivedStimulusCondition *, ActionNode *, ActionContext *); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = action_node;
  v4 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v5 = &v2->m_MyRoot;
  if ( v4 )
    v6 = (char *)v4 - (char *)v5;
  else
    v6 = 0i64;
  v5->mOffset = v6;
  v7 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))v3->vfptr[1].SetResourceOwner)(v3);
  ActionNodeRoot::AddToInitList(v7, (IConditionInit *)&v2->vfptr);
  v8 = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_SecondsSinceReceivedUID, 0);
  v9 = v2->m_StimulusProducerTargetUID;
  v2->m_SecondsSinceReceivedUID = v8;
  v10 = UFG::ActionTreeComponentBase::MakeValueUID(v9, eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  v11 = v2->m_EnteredUID;
  v2->m_StimulusProducerTargetUID = v10;
  v2->m_EnteredUID = UFG::ActionTreeComponentBase::MakeValueUID(v11, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  v14 = ReceivedStimulusCondition::OnEnterCallback;
  v13 = Assembly::GetRCX(v2);
  ActionNode::AddOnEnterCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v13);
  v12 = Assembly::GetRCX(v2);
  v14 = ReceivedStimulusCondition::OnExitCallback;
  v13 = v12;
  ActionNode::AddOnExitCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v13);
}

// File Line: 285
// RVA: 0x3662B0
void __fastcall ReceivedStimulusCondition::Init(ReceivedStimulusCondition *this, ActionContext *action_context)
{
  ReceivedStimulusCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  char v7; // cl
  signed __int64 v8; // rax
  char v9; // cl

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[11].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StimulusReceiverComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StimulusReceiverComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::StimulusReceiverComponent::_TypeUID);
      }
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[11].m_pComponent;
    }
    if ( v5 )
    {
      v7 = (_QWORD)v2->vfptr & 0x3F;
      v8 = (signed __int64)LOBYTE(v2->vfptr) >> 6;
      if ( !((1i64 << v7) & *((_QWORD *)&v5[1].m_Flags + v8)) )
      {
        *((_QWORD *)&v5[1].m_Flags + v8) |= 1i64 << v7;
        ++LOBYTE(v5[16].m_Flags);
        v9 = UFG::StimulusReceiverComponent::s_MaxStimuliRegistered;
        if ( UFG::StimulusReceiverComponent::s_MaxStimuliRegistered <= SLOBYTE(v5[16].m_Flags) )
          v9 = v5[16].m_Flags;
        UFG::StimulusReceiverComponent::s_MaxStimuliRegistered = v9;
      }
    }
  }
}

// File Line: 305
// RVA: 0x3749B0
signed __int64 __fastcall ReceivedStimulusCondition::MatchTargetType(ReceivedStimulusCondition *this, ActionContext *action_context, UFG::SimObject *stimulus_producer)
{
  UFG::SimObjectGame *v3; // rbx
  ActionContext *v4; // r15
  ReceivedStimulusCondition *v5; // r14
  unsigned __int8 v6; // si
  signed __int64 result; // rax
  UFG::SimObjectCharacterPropertiesComponent *v8; // rbp
  UFG::SimObjectCharacterPropertiesComponent *v9; // rdi
  unsigned __int16 v10; // cx
  UFG::SimObjectCharacterPropertiesComponent *v11; // rax
  unsigned __int16 v12; // cx
  UFG::InventoryItemComponent *v13; // rax
  UFG::SimObjectCVBase *v14; // rax
  unsigned __int16 v15; // dx
  UFG::SimObjectCharacterPropertiesComponent *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // r8
  UFG::SimComponent *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  UFG::SimObjectCVBase *v22; // rcx
  unsigned __int16 v23; // dx
  UFG::SimObjectCharacterPropertiesComponent *v24; // rax
  unsigned int v25; // edx
  bool v26; // zf
  __int64 v27; // rbx
  __int64 v28; // rdi
  UFG::GameStatTracker *v29; // r8

  v3 = (UFG::SimObjectGame *)stimulus_producer;
  v4 = action_context;
  v5 = this;
  v6 = 1;
  if ( !this->m_OnlyCareAboutStimuliFromTarget && !this->m_OnlyCareAboutStimuliFromFactionStanding )
    return 1i64;
  v8 = 0i64;
  if ( stimulus_producer )
  {
    v10 = stimulus_producer->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)stimulus_producer);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)stimulus_producer,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)stimulus_producer,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                              stimulus_producer,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)stimulus_producer);
    }
    v9 = v11;
    if ( !v11 )
    {
      v12 = v3->m_Flags;
      if ( !((v12 >> 14) & 1) && (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
          v13 = (UFG::InventoryItemComponent *)v3->m_Components.p[11].m_pComponent;
        else
          v13 = (UFG::InventoryItemComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v3,
                                                                    UFG::InventoryItemComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InventoryItemComponent::_TypeUID));
        if ( v13 )
        {
          v14 = (UFG::SimObjectCVBase *)UFG::InventoryItemComponent::GetOwnerSimObject(v13);
          v3 = (UFG::SimObjectGame *)&v14->vfptr;
          if ( v14 )
          {
            v15 = v14->m_Flags;
            if ( (v15 >> 14) & 1 )
            {
              v16 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v14);
            }
            else if ( (v15 & 0x8000u) == 0 )
            {
              if ( (v15 >> 13) & 1 )
              {
                v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v14->vfptr,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
              else if ( (v15 >> 12) & 1 )
              {
                v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v14->vfptr,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
              else
              {
                v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                      (UFG::SimObject *)&v14->vfptr,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
            }
            else
            {
              v16 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v14);
            }
            v9 = v16;
          }
        }
      }
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( v5->m_OnlyCareAboutStimuliFromTarget )
  {
    if ( v9 )
    {
      v17 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
      v6 = 0;
      if ( v17 )
      {
        v18 = v17->m_Flags;
        if ( (v18 >> 14) & 1 )
        {
          v19 = v17->m_Components.p[20].m_pComponent;
        }
        else if ( (v18 & 0x8000u) == 0 )
        {
          if ( (v18 >> 13) & 1 )
          {
            v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v18 >> 12) & 1 )
          {
            v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v20 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v17->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v19 = v20;
        }
        else
        {
          v19 = v17->m_Components.p[20].m_pComponent;
        }
        if ( v19 )
        {
          v21 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)v5->m_OnlyCareAboutStimuliFromTargetType.mValue
                                                            + *(_QWORD *)&v19[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v19[1].m_TypeUID
                                       + 40);
          if ( v21 )
          {
            v6 = 0;
            if ( v21 == v3 )
              v6 = 1;
          }
        }
      }
    }
  }
  if ( !v5->m_OnlyCareAboutStimuliFromFactionStanding || !v9 || !v6 )
    return v6;
  v22 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
  if ( v22 )
  {
    v23 = v22->m_Flags;
    if ( (v23 >> 14) & 1 || (v23 & 0x8000u) != 0 )
    {
      v24 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v22);
    }
    else
    {
      if ( (v23 >> 13) & 1 )
      {
        v25 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
      }
      else
      {
        v26 = ((v23 >> 12) & 1) == 0;
        v25 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
        if ( v26 )
        {
          v24 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                (UFG::SimObject *)&v22->vfptr,
                                                                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          goto LABEL_64;
        }
      }
      v24 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v22->vfptr,
                                                            v25);
    }
LABEL_64:
    v8 = v24;
  }
  v27 = v8->m_eFactionClass;
  v28 = v9->m_eFactionClass;
  v29 = UFG::GameStatTracker::Instance();
  result = 0i64;
  if ( v29->mFactionInterface.mStandings[0][v28 + 39 * v27] == (unsigned __int8)v5->m_OnlyCareAboutStimuliFromFactionStandingType.mValue )
    result = 1i64;
  return result;
}

// File Line: 378
// RVA: 0x371E30
_BOOL8 __fastcall ReceivedStimulusCondition::Match(ReceivedStimulusCondition *this, ActionContext *action_context)
{
  float v2; // xmm0_4
  signed __int64 v3; // rsi
  float v4; // xmm8_4
  ActionContext *v5; // rbp
  ReceivedStimulusCondition *v6; // rbx
  bool v7; // zf
  __int64 v8; // rax
  UFG::ActionTreeComponentBase *v9; // rdx
  char *v10; // rcx
  UFG::ActionTreeComponentBase *v11; // rcx
  unsigned int v12; // er9
  float v13; // xmm6_4
  float v14; // xmm7_4
  unsigned int v15; // xmm0_4
  __int64 v16; // rax
  UFG::ActionTreeComponentBase *v17; // rdx
  signed __int64 v18; // rcx
  UFG::ActionTreeComponentBase *v19; // rcx
  float v20; // xmm6_4
  UFG::SimObjectGame *v21; // rcx
  UFG::SimComponent *v22; // rdx
  unsigned __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  float v25; // xmm0_4
  UFG::SimObject *v26; // r14
  __int64 v27; // rax
  signed __int64 v28; // rax
  bool v29; // r15
  __int64 v30; // r12
  UFG::SimObjectGame *v31; // rcx
  unsigned __int16 v32; // dx
  UFG::TargetingSystemBaseComponent *v33; // rdi
  UFG::SimComponent *v34; // rax
  __int64 v35; // rax
  UFG::ActionTreeComponentBase *v36; // rdx
  signed __int64 v37; // rcx
  UFG::ActionTreeComponentBase *v38; // rcx
  __int64 v39; // rax
  UFG::ActionTreeComponentBase *v40; // rdx
  UFG::ActionTreeComponentBase *v41; // rcx
  unsigned int v43; // [rsp+80h] [rbp+8h]
  unsigned int value_uid; // [rsp+88h] [rbp+10h]

  v2 = this->m_MinSecondsSinceReceived;
  v3 = 0i64;
  v4 = UFG::Metrics::msInstance.mSimTime_Temp;
  v5 = action_context;
  v6 = this;
  v7 = v2 == this->m_MaxSecondsSinceReceived;
  value_uid = LODWORD(this->m_MinSecondsSinceReceived);
  if ( !v7 )
  {
    v8 = this->m_MyRoot.mOffset;
    if ( v8 )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v8);
    else
      v9 = 0i64;
    if ( v8 )
      v10 = (char *)&this->m_MyRoot + v8;
    else
      v10 = 0i64;
    v11 = v5->mActionTreeComponentBase[v10[236]];
    if ( !v11 )
      v11 = v5->mActionTreeComponentBase[1];
    if ( !UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
            v11,
            v9,
            (ActionNodeRoot *)v6->m_SecondsSinceReceivedUID,
            (__int64)&value_uid) )
    {
      v13 = v6->m_MaxSecondsSinceReceived;
      v14 = v6->m_MinSecondsSinceReceived;
      *(float *)&v15 = v13;
      if ( v13 > v14 )
      {
        *(float *)&v15 = UFG::qRandom(v13 - v14, &UFG::qDefaultSeed) + v14;
        if ( *(float *)&v15 <= v14 )
          *(float *)&v15 = v14;
        if ( *(float *)&v15 >= v13 )
          *(float *)&v15 = v13;
      }
      v16 = v6->m_MyRoot.mOffset;
      value_uid = v15;
      if ( v16 )
        v17 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v16);
      else
        v17 = 0i64;
      if ( v16 )
        v18 = (signed __int64)&v6->m_MyRoot + v16;
      else
        v18 = 0i64;
      v19 = v5->mActionTreeComponentBase[*(char *)(v18 + 236)];
      if ( !v19 )
        v19 = v5->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
        v19,
        v17,
        (ActionNodeRoot *)v6->m_SecondsSinceReceivedUID,
        v12,
        v15);
    }
    v2 = *(float *)&value_uid;
  }
  v20 = *((float *)&unk_1423BF9D4 + 18 * (unsigned __int8)v6->m_Stimulus.mValue) * 2.0;
  if ( v20 <= v2 )
    v20 = v2;
  v21 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v21 )
  {
    v23 = v21->m_Flags;
    if ( (v23 >> 14) & 1 )
    {
      v22 = v21->m_Components.p[11].m_pComponent;
    }
    else if ( (v23 & 0x8000u) == 0 )
    {
      if ( (v23 >> 13) & 1 )
      {
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::StimulusReceiverComponent::_TypeUID);
      }
      else if ( (v23 >> 12) & 1 )
      {
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::StimulusReceiverComponent::_TypeUID);
      }
      else
      {
        v24 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v21->vfptr,
                UFG::StimulusReceiverComponent::_TypeUID);
      }
      v22 = v24;
    }
    else
    {
      v22 = v21->m_Components.p[11].m_pComponent;
    }
  }
  else
  {
    v22 = 0i64;
  }
  v25 = FLOAT_N99999_0;
  v26 = 0i64;
  if ( v22 )
  {
    v27 = *((_QWORD *)&v22[1].m_BoundComponentHandles.mNode.mPrev + (unsigned __int8)v6->m_Stimulus.mValue);
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
  v29 = (float)(v4 - v25) <= v20 && ReceivedStimulusCondition::MatchTargetType(v6, v5, v26);
  v30 = 0i64;
  if ( v29 )
  {
    v31 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
    if ( v31 )
    {
      v32 = v31->m_Flags;
      if ( (v32 >> 14) & 1 )
      {
        v33 = (UFG::TargetingSystemBaseComponent *)v31->m_Components.p[20].m_pComponent;
      }
      else if ( (v32 & 0x8000u) == 0 )
      {
        if ( (v32 >> 13) & 1 )
          v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v34 = (v32 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v31,
                                    UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v31->vfptr,
                                                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
        v33 = (UFG::TargetingSystemBaseComponent *)v34;
      }
      else
      {
        v33 = (UFG::TargetingSystemBaseComponent *)v31->m_Components.p[20].m_pComponent;
      }
      if ( v33 )
      {
        if ( v6->m_UpdateTargetAfterEntering )
        {
          v35 = v6->m_MyRoot.mOffset;
          LOBYTE(v43) = 0;
          if ( v35 )
            v36 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v35);
          else
            v36 = 0i64;
          if ( v35 )
            v37 = (signed __int64)&v6->m_MyRoot + v35;
          else
            v37 = 0i64;
          v38 = v5->mActionTreeComponentBase[*(char *)(v37 + 236)];
          if ( !v38 )
            v38 = v5->mActionTreeComponentBase[1];
          UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
            v38,
            v36,
            (ActionNodeRoot *)v6->m_EnteredUID,
            (__int64)&v43);
          if ( (_BYTE)v43 )
            UFG::TargetingSystemBaseComponent::SetTarget(v33, eTARGET_TYPE_STIMULUS_PRODUCER, v26);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(v33, eTARGET_TYPE_CONDITION_STIMULUS_PRODUCER, v26);
        v30 = (__int64)v26;
      }
    }
  }
  v39 = v6->m_MyRoot.mOffset;
  if ( v39 )
    v40 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v39);
  else
    v40 = 0i64;
  if ( v39 )
    v3 = (signed __int64)&v6->m_MyRoot + v39;
  v41 = v5->mActionTreeComponentBase[*(char *)(v3 + 236)];
  if ( !v41 )
    v41 = v5->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
    v41,
    v40,
    (ActionNodeRoot *)v6->m_StimulusProducerTargetUID,
    v30);
  return v29;
}

// File Line: 466
// RVA: 0x37B320
void __fastcall ReceivedStimulusCondition::OnEnterCallback(ReceivedStimulusCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  ReceivedStimulusCondition *v3; // rbp
  UFG::SimObjectGame *v4; // rcx
  signed __int64 v5; // rdi
  ActionContext *v6; // rsi
  unsigned __int16 v7; // dx
  UFG::TargetingSystemBaseComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  __int64 v10; // rax
  UFG::ActionTreeComponentBase *v11; // rdx
  signed __int64 v12; // rcx
  UFG::ActionTreeComponentBase *v13; // rcx
  __int64 v14; // rax
  UFG::ActionTreeComponentBase *v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  UFG::SimObject *value_uid; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v5 = 0i64;
  v6 = action_context;
  if ( v4 )
  {
    v7 = v4->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = (UFG::TargetingSystemBaseComponent *)v9;
    }
    else
    {
      v8 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
    }
    if ( v8 )
    {
      v10 = v3->m_MyRoot.mOffset;
      value_uid = 0i64;
      if ( v10 )
        v11 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v10);
      else
        v11 = 0i64;
      if ( v10 )
        v12 = (signed __int64)&v3->m_MyRoot + v10;
      else
        v12 = 0i64;
      v13 = v6->mActionTreeComponentBase[*(char *)(v12 + 236)];
      if ( !v13 )
        v13 = v6->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
        v13,
        v11,
        (ActionNodeRoot *)v3->m_StimulusProducerTargetUID,
        (__int64)&value_uid);
      UFG::TargetingSystemBaseComponent::SetTarget(v8, eTARGET_TYPE_STIMULUS_PRODUCER, value_uid);
    }
  }
  v14 = v3->m_MyRoot.mOffset;
  if ( v14 )
    v15 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v14);
  else
    v15 = 0i64;
  if ( v14 )
    v5 = (signed __int64)&v3->m_MyRoot + v14;
  v16 = v6->mActionTreeComponentBase[*(char *)(v5 + 236)];
  if ( !v16 )
    v16 = v6->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v16, v15, (ActionNodeRoot *)v3->m_EnteredUID, 1u);
}

// File Line: 483
// RVA: 0x37B470
void __fastcall ReceivedStimulusCondition::OnExitCallback(ReceivedStimulusCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  __int64 v3; // rax
  char *v4; // rdx
  ReceivedStimulusCondition *v5; // r11
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx

  v3 = this->m_MyRoot.mOffset;
  v4 = 0i64;
  v5 = this;
  if ( v3 )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v3);
  else
    v6 = 0i64;
  if ( v3 )
    v4 = (char *)&this->m_MyRoot + v3;
  v7 = action_context->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v7, v6, (ActionNodeRoot *)v5->m_EnteredUID, 0);
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
  ReceivedHeatEventCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ReceivedHeatEventCondition::`vftable';
  v1->m_HeatEvent.mValue = 0;
}

// File Line: 528
// RVA: 0x33A460
void __fastcall ReceivedHeatEventCondition::~ReceivedHeatEventCondition(ReceivedHeatEventCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&ReceivedHeatEventCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 535
// RVA: 0x371D60
bool __fastcall ReceivedHeatEventCondition::Match(ReceivedHeatEventCondition *this, ActionContext *action_context)
{
  ReceivedHeatEventCondition *v2; // rbx
  UFG::CopSystem *v3; // rax

  v2 = this;
  v3 = UFG::CopSystem::Instance();
  LODWORD(v2) = (unsigned __int8)v2->m_HeatEvent.mValue;
  return ((unsigned int (__fastcall *)(UFG::CopSystem *))v3->vfptr[107].__vecDelDtor)(v3) == (_DWORD)v2;
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
void __fastcall AIPlayerInsideAIMeshHeuristicCondition::AIPlayerInsideAIMeshHeuristicCondition(AIPlayerInsideAIMeshHeuristicCondition *this)
{
  AIPlayerInsideAIMeshHeuristicCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIPlayerInsideAIMeshHeuristicCondition::`vftable';
}

// File Line: 561
// RVA: 0x36ED80
__int64 __fastcall AIPlayerInsideAIMeshHeuristicCondition::Match(AIPlayerInsideAIMeshHeuristicCondition *this, ActionContext *action_context)
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
void __fastcall AICopAcquireArrestRightCondition::AICopAcquireArrestRightCondition(AICopAcquireArrestRightCondition *this)
{
  AICopAcquireArrestRightCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopAcquireArrestRightCondition::`vftable';
}

// File Line: 588
// RVA: 0x36DEA0
__int64 __fastcall AICopAcquireArrestRightCondition::Match(AICopAcquireArrestRightCondition *this, ActionContext *action_context)
{
  ActionContext *v2; // rbx
  UFG::CopSystem *v3; // rax

  v2 = action_context;
  v3 = UFG::CopSystem::Instance();
  return v3->vfptr[104].__vecDelDtor(
           (UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr,
           (unsigned int)v2->mSimObject.m_pPointer);
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
void __fastcall AICopPlayerInsideUnlockedSafehouseCondition::AICopPlayerInsideUnlockedSafehouseCondition(AICopPlayerInsideUnlockedSafehouseCondition *this)
{
  AICopPlayerInsideUnlockedSafehouseCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopPlayerInsideUnlockedSafehouseCondition::`vftable';
}

// File Line: 614
// RVA: 0x36E000
UFG::UIHKScreenHud *__fastcall AICopPlayerInsideUnlockedSafehouseCondition::Match(AICopPlayerInsideUnlockedSafehouseCondition *this, ActionContext *action_context)
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
  AICopOnFootNoSprintCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopOnFootNoSprintCondition::`vftable';
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
  AICopIsSoloOnSceneCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopIsSoloOnSceneCondition::`vftable';
}

// File Line: 666
// RVA: 0x36DF30
__int64 __fastcall AICopIsSoloOnSceneCondition::Match(AICopIsSoloOnSceneCondition *this, ActionContext *action_context)
{
  ActionContext *v2; // rbx
  UFG::CopSystem *v3; // rax

  v2 = action_context;
  v3 = UFG::CopSystem::Instance();
  return v3->vfptr[106].__vecDelDtor(
           (UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr,
           (unsigned int)v2->mSimObject.m_pPointer);
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
  AICopNumArrestAttemptCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopNumArrestAttemptCondition::`vftable';
  v1->m_InEqualityOperator.mValue = 4;
  v1->m_NumAttempts = 0;
}

// File Line: 698
// RVA: 0x36DFA0
bool __fastcall AICopNumArrestAttemptCondition::Match(AICopNumArrestAttemptCondition *this, ActionContext *action_context)
{
  AICopNumArrestAttemptCondition *v2; // rdi
  UFG::CopSystem *v3; // rax
  UFG::InEqualityOperator v4; // ebx
  int v5; // eax

  v2 = this;
  v3 = UFG::CopSystem::Instance();
  v4 = (unsigned __int8)v2->m_InEqualityOperator.mValue;
  v5 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[91].__vecDelDtor)(v3);
  return CompareInt(v4, v2->m_NumAttempts, v5);
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
void __fastcall AICopIsSuspectInsideInteriorCondition::AICopIsSuspectInsideInteriorCondition(AICopIsSuspectInsideInteriorCondition *this)
{
  AICopIsSuspectInsideInteriorCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopIsSuspectInsideInteriorCondition::`vftable';
}

// File Line: 725
// RVA: 0x36DF80
__int64 __fastcall AICopIsSuspectInsideInteriorCondition::Match(AICopIsSuspectInsideInteriorCondition *this, ActionContext *action_context)
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
  AICopIsSuspectInWaterCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopIsSuspectInWaterCondition::`vftable';
}

// File Line: 750
// RVA: 0x36DF60
__int64 __fastcall AICopIsSuspectInWaterCondition::Match(AICopIsSuspectInWaterCondition *this, ActionContext *action_context)
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
void __fastcall AICopHasSuspectOpenedFiredCondition::AICopHasSuspectOpenedFiredCondition(AICopHasSuspectOpenedFiredCondition *this)
{
  AICopHasSuspectOpenedFiredCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopHasSuspectOpenedFiredCondition::`vftable';
  v1->m_OpenFiredContext.mValue = 0;
}

// File Line: 778
// RVA: 0x36DED0
__int64 __fastcall AICopHasSuspectOpenedFiredCondition::Match(AICopHasSuspectOpenedFiredCondition *this, ActionContext *action_context)
{
  UFG::CopSystem *v2; // rax
  __int64 result; // rax
  UFG::CopSystem *v4; // rax

  if ( this->m_OpenFiredContext.mValue == 1 )
  {
    v2 = UFG::CopSystem::Instance();
    result = ((__int64 (__fastcall *)(UFG::CopSystem *))v2->vfptr[15].__vecDelDtor)(v2);
  }
  else
  {
    v4 = UFG::CopSystem::Instance();
    result = ((__int64 (__fastcall *)(UFG::CopSystem *))v4->vfptr[14].__vecDelDtor)(v4);
  }
  return result;
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
void __fastcall AICopHasVehicleToDefendCondition::AICopHasVehicleToDefendCondition(AICopHasVehicleToDefendCondition *this)
{
  AICopHasVehicleToDefendCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopHasVehicleToDefendCondition::`vftable';
}

// File Line: 813
// RVA: 0x36DF00
bool __fastcall AICopHasVehicleToDefendCondition::Match(AICopHasVehicleToDefendCondition *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // rax
  UFG::SimComponent *v3; // rcx
  bool result; // al

  v2 = action_context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Components.p[16].m_pComponent;
    if ( v3 )
    {
      if ( v3[2].m_BoundComponentHandles.mNode.mPrev )
        result = 1;
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
  return atexit(dynamic_atexit_destructor_for__gEncounterUnitRoleTypeNames__);
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
  AIEncounterRoleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIEncounterRoleCondition::`vftable';
  v1->mRole.mValue = 0;
}

// File Line: 851
// RVA: 0x36E500
bool __fastcall AIEncounterRoleCondition::Match(AIEncounterRoleCondition *this, ActionContext *action_context)
{
  AIEncounterRoleCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::EncounterUnitComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::EncounterUnitComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::EncounterUnitComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[16].m_pComponent)) : (v5 = v3->m_Components.p[16].m_pComponent),
        v5) )
  {
    result = LODWORD(v5[1].vfptr) == (unsigned __int8)v2->mRole.mValue;
  }
  else
  {
    result = 0;
  }
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
void __fastcall AIEncounterUnitGotStuckCondition::AIEncounterUnitGotStuckCondition(AIEncounterUnitGotStuckCondition *this)
{
  AIEncounterUnitGotStuckCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIEncounterUnitGotStuckCondition::`vftable';
}

// File Line: 883
// RVA: 0x36E5A0
bool __fastcall AIEncounterUnitGotStuckCondition::Match(AIEncounterUnitGotStuckCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // rbx
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rax
  bool result; // al
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rax

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v3 = action_context;
  result = 0;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v2->m_Components.p[16].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::EncounterUnitComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::EncounterUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::EncounterUnitComponent::_TypeUID);
    }
    else
    {
      v5 = v2->m_Components.p[16].m_pComponent;
    }
    if ( v5 && HIBYTE(v5[2].m_SafePointerList.mNode.mPrev)
      || (v7 = (UFG::SimObjectCVBase *)v3->mSimObject.m_pPointer) != 0i64
      && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7)),
          v9 && UFG::AiDriverComponent::GetUnstuckFailed(v9)) )
    {
      result = 1;
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
void __fastcall CanBeginSinglePersonConversationCondition::CanBeginSinglePersonConversationCondition(CanBeginSinglePersonConversationCondition *this)
{
  CanBeginSinglePersonConversationCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CanBeginSinglePersonConversationCondition::`vftable';
}

// File Line: 925
// RVA: 0x36F070
bool __fastcall CanBeginSinglePersonConversationCondition::Match(CanBeginSinglePersonConversationCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  unsigned int v5; // edx
  bool v6; // zf

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 || (v3 & 0x8000u) != 0 )
    {
      UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
      return 0;
    }
    if ( (v3 >> 13) & 1 )
    {
      v5 = UFG::ActiveAIEntityComponent::_TypeUID;
LABEL_7:
      UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, v5);
      return 0;
    }
    v6 = ((v3 >> 12) & 1) == 0;
    v5 = UFG::ActiveAIEntityComponent::_TypeUID;
    if ( !v6 )
      goto LABEL_7;
    UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID);
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
  OneShotCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&OneShotCondition::`vftable';
  v1->m_HasFiredUID = 0;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 967
// RVA: 0x3834D0
void __fastcall OneShotCondition::ResolveReferences(OneShotCondition *this, ActionNode *action_node)
{
  OneShotCondition *v2; // rbx
  ActionNode *v3; // rdi
  Expression::IMemberMap *v4; // rax
  signed __int64 v5; // rcx
  __int64 v6; // rax
  ActionNode *v7; // rcx
  OneShotCondition *v8; // [rsp+20h] [rbp-18h]
  void (__fastcall *v9)(AMD_HD3D *); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = action_node;
  v4 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v5 = (signed __int64)&v2->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - v5);
  *(_QWORD *)v5 = v4;
  v8 = v2;
  v9 = (void (__fastcall *)(AMD_HD3D *))OneShotCondition::OnMyEnterCallback;
  ActionNode::AddOnEnterCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v8);
  v6 = v3->mParent.mOffset;
  if ( v6 )
  {
    v7 = (ActionNode *)((char *)v3 + v6 + 16);
    if ( v7 )
    {
      v8 = v2;
      v9 = _;
      ActionNode::AddOnExitCallback(v7, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v8);
    }
  }
  v2->m_HasFiredUID = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_HasFiredUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 992
// RVA: 0x37B610
void __fastcall OneShotCondition::OnMyEnterCallback(OneShotCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  __int64 v3; // rax
  char *v4; // rdx
  OneShotCondition *v5; // r11
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx

  v3 = this->m_MyRoot.mOffset;
  v4 = 0i64;
  v5 = this;
  if ( v3 )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v3);
  else
    v6 = 0i64;
  if ( v3 )
    v4 = (char *)&this->m_MyRoot + v3;
  v7 = action_context->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v7, v6, (ActionNodeRoot *)v5->m_HasFiredUID, 1u);
}

// File Line: 1006
// RVA: 0x371690
bool __fastcall OneShotCondition::Match(OneShotCondition *this, ActionContext *action_context)
{
  __int64 v2; // rax
  OneShotCondition *v3; // r8
  UFG::ActionTreeComponentBase *v4; // r10
  char *v5; // rcx
  UFG::ActionTreeComponentBase *v6; // rcx
  unsigned int value_uid; // [rsp+30h] [rbp+8h]

  v2 = this->m_MyRoot.mOffset;
  v3 = this;
  LOBYTE(value_uid) = 0;
  if ( v2 )
    v4 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v4 = 0i64;
  if ( v2 )
    v5 = (char *)&this->m_MyRoot + v2;
  else
    v5 = 0i64;
  v6 = action_context->mActionTreeComponentBase[v5[236]];
  if ( !v6 )
    v6 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v6,
    v4,
    (ActionNodeRoot *)v3->m_HasFiredUID,
    (__int64)&value_uid);
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
  CooldownCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CooldownCondition::`vftable';
  *(_QWORD *)&v1->m_NextTimeCanEnterUID = 0i64;
  v1->m_MaxTimeUntilCanEnterAgain = 0.0;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 1049
// RVA: 0x3830B0
void __fastcall CooldownCondition::ResolveReferences(CooldownCondition *this, ActionNode *action_node)
{
  CooldownCondition *v2; // rbx
  ActionNode *v3; // rdi
  Expression::IMemberMap *v4; // rax
  signed __int64 v5; // rcx
  CooldownCondition *v6; // [rsp+20h] [rbp-18h]
  void (__fastcall *v7)(CooldownCondition *, ActionNode *, ActionContext *, unsigned int); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = action_node;
  v4 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v5 = (signed __int64)&v2->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - v5);
  *(_QWORD *)v5 = v4;
  v6 = v2;
  v7 = CooldownCondition::OnMyExitCallback;
  ActionNode::AddOnExitCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v6);
  v2->m_NextTimeCanEnterUID = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_NextTimeCanEnterUID, 0);
}

// File Line: 1091
// RVA: 0x36F800
bool __fastcall CooldownCondition::Match(CooldownCondition *this, ActionContext *action_context)
{
  __int64 v2; // rax
  float v3; // xmm6_4
  CooldownCondition *v4; // r8
  UFG::ActionTreeComponentBase *v5; // r10
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  unsigned int value_uid; // [rsp+40h] [rbp+8h]

  v2 = this->m_MyRoot.mOffset;
  v3 = UFG::Metrics::msInstance.mSimTime_Temp;
  v4 = this;
  *(float *)&value_uid = FLOAT_N99999_0;
  if ( v2 )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v5 = 0i64;
  if ( v2 )
    v6 = (char *)&this->m_MyRoot + v2;
  else
    v6 = 0i64;
  v7 = action_context->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v7,
    v5,
    (ActionNodeRoot *)v4->m_NextTimeCanEnterUID,
    (__int64)&value_uid);
  return v3 >= *(float *)&value_uid;
}

// File Line: 1131
// RVA: 0x14B6DB0
__int64 dynamic_initializer_for__geCooldownTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&geCooldownTypeEnum, UFG::GlobalCooldownNames, 19, 0i64);
  return atexit(dynamic_atexit_destructor_for__geCooldownTypeEnum__);
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
  GlobalCooldownCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&GlobalCooldownCondition::`vftable';
  v1->m_CooldownType.mValue = 0;
  *(_QWORD *)&v1->m_MinTimeUntilCanEnterAgain = 0i64;
}

// File Line: 1149
// RVA: 0x383340
void __fastcall GlobalCooldownCondition::ResolveReferences(GlobalCooldownCondition *this, ActionNode *action_node)
{
  ActionNode *v2; // rdi
  GlobalCooldownCondition *v3; // rbx
  GlobalCooldownCondition *v4; // [rsp+20h] [rbp-18h]
  void (__fastcall *v5)(GlobalCooldownCondition *, ActionNode *, ActionContext *); // [rsp+28h] [rbp-10h]

  v2 = action_node;
  v3 = this;
  v4 = this;
  v5 = GlobalCooldownCondition::OnMyEnterCallback;
  ActionNode::AddOnEnterCallback(action_node, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v4);
  v5 = GlobalCooldownCondition::OnMyExitCallback;
  v4 = v3;
  ActionNode::AddOnExitCallback(v2, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v4);
}

// File Line: 1164
// RVA: 0x37B5C0
void __fastcall GlobalCooldownCondition::OnMyEnterCallback(GlobalCooldownCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  __int64 v3; // rcx

  v3 = (unsigned __int8)this->m_CooldownType.mValue;
  UFG::GlobalCooldownManager::s_pInstance->m_LastTimeFired[v3] = UFG::Metrics::msInstance.mSimTime_Temp;
  UFG::GlobalCooldownManager::s_pInstance->m_TimeUntilNextCanFire[v3] = 9999.0;
}

// File Line: 1173
// RVA: 0x37B730
void __fastcall GlobalCooldownCondition::OnMyExitCallback(GlobalCooldownCondition *this, ActionNode *action_node, ActionContext *action_context)
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
  RandomStartTimeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&RandomStartTimeCondition::`vftable';
  *(_QWORD *)&v1->m_TimeCanEnterUID = 0i64;
  *(_QWORD *)&v1->m_MinTimeUntilCanEnter = 0i64;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 1224
// RVA: 0x383670
void __fastcall RandomStartTimeCondition::ResolveReferences(RandomStartTimeCondition *this, ActionNode *action_node)
{
  RandomStartTimeCondition *v2; // rbx
  ActionNode *v3; // rdi
  Expression::IMemberMap *v4; // rax
  signed __int64 v5; // rcx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  RandomStartTimeCondition *v8; // [rsp+20h] [rbp-18h]
  void (__fastcall *v9)(RandomStartTimeCondition *, ActionNode *, ActionContext *); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = action_node;
  v4 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v5 = (signed __int64)&v2->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - v5);
  *(_QWORD *)v5 = v4;
  v8 = v2;
  v9 = RandomStartTimeCondition::OnMyExitCallback;
  ActionNode::AddOnExitCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v8);
  v6 = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_TimeCanEnterUID, 0);
  v7 = v2->m_NeedToSetTimeCanEnterUID;
  v2->m_TimeCanEnterUID = v6;
  v2->m_NeedToSetTimeCanEnterUID = UFG::ActionTreeComponentBase::MakeValueUID(v7, eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 1242
// RVA: 0x37B9C0
void __fastcall RandomStartTimeCondition::OnMyExitCallback(RandomStartTimeCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  __int64 v3; // rax
  char *v4; // rdx
  RandomStartTimeCondition *v5; // r11
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx

  v3 = this->m_MyRoot.mOffset;
  v4 = 0i64;
  v5 = this;
  if ( v3 )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v3);
  else
    v6 = 0i64;
  if ( v3 )
    v4 = (char *)&this->m_MyRoot + v3;
  v7 = action_context->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v7, v6, (ActionNodeRoot *)v5->m_NeedToSetTimeCanEnterUID, 1u);
}

// File Line: 1251
// RVA: 0x371B80
bool __fastcall RandomStartTimeCondition::Match(RandomStartTimeCondition *this, ActionContext *action_context)
{
  __int64 v2; // rax
  ActionContext *v3; // rsi
  RandomStartTimeCondition *v4; // rbx
  UFG::ActionTreeComponentBase *v5; // rdx
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  unsigned int v8; // er9
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm8_4
  __int64 v13; // rax
  int v14; // xmm0_4
  UFG::ActionTreeComponentBase *v15; // rdx
  signed __int64 v16; // rcx
  UFG::ActionTreeComponentBase *v17; // rcx
  __int64 v18; // rax
  UFG::ActionTreeComponentBase *v19; // rdx
  signed __int64 v20; // rcx
  UFG::ActionTreeComponentBase *v21; // rcx
  __int64 v22; // rax
  float v23; // xmm6_4
  UFG::ActionTreeComponentBase *v24; // rdx
  signed __int64 v25; // rcx
  UFG::ActionTreeComponentBase *v26; // rcx
  unsigned int value_uid; // [rsp+60h] [rbp+8h]
  unsigned int v29; // [rsp+68h] [rbp+10h]

  v2 = this->m_MyRoot.mOffset;
  v3 = action_context;
  v4 = this;
  LOBYTE(value_uid) = 1;
  if ( v2 )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v5 = 0i64;
  if ( v2 )
    v6 = (char *)&this->m_MyRoot + v2;
  else
    v6 = 0i64;
  v7 = v3->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v7,
    v5,
    (ActionNodeRoot *)v4->m_NeedToSetTimeCanEnterUID,
    (__int64)&value_uid);
  if ( (_BYTE)value_uid )
  {
    v9 = v4->m_MaxTimeUntilCanEnter;
    v10 = v4->m_MinTimeUntilCanEnter;
    v11 = v9;
    v12 = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( v9 > v10 )
    {
      v11 = UFG::qRandom(v9 - v10, &UFG::qDefaultSeed) + v10;
      if ( v11 <= v10 )
        v11 = v10;
      if ( v11 >= v9 )
        v11 = v9;
    }
    v13 = v4->m_MyRoot.mOffset;
    *(float *)&v14 = v11 + v12;
    if ( v13 )
      v15 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v13);
    else
      v15 = 0i64;
    if ( v13 )
      v16 = (signed __int64)&v4->m_MyRoot + v13;
    else
      v16 = 0i64;
    v17 = v3->mActionTreeComponentBase[*(char *)(v16 + 236)];
    if ( !v17 )
      v17 = v3->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(v17, v15, (ActionNodeRoot *)v4->m_TimeCanEnterUID, v8, v14);
    v18 = v4->m_MyRoot.mOffset;
    if ( v18 )
      v19 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v18);
    else
      v19 = 0i64;
    if ( v18 )
      v20 = (signed __int64)&v4->m_MyRoot + v18;
    else
      v20 = 0i64;
    v21 = v3->mActionTreeComponentBase[*(char *)(v20 + 236)];
    if ( !v21 )
      v21 = v3->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v21,
      v19,
      (ActionNodeRoot *)v4->m_NeedToSetTimeCanEnterUID,
      0);
  }
  v22 = v4->m_MyRoot.mOffset;
  v23 = UFG::Metrics::msInstance.mSimTime_Temp;
  *(float *)&v29 = FLOAT_N99999_0;
  if ( v22 )
    v24 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v22);
  else
    v24 = 0i64;
  if ( v22 )
    v25 = (signed __int64)&v4->m_MyRoot + v22;
  else
    v25 = 0i64;
  v26 = v3->mActionTreeComponentBase[*(char *)(v25 + 236)];
  if ( !v26 )
    v26 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v26,
    v24,
    (ActionNodeRoot *)v4->m_TimeCanEnterUID,
    (__int64)&v29);
  return v23 >= *(float *)&v29;
}

// File Line: 1311
// RVA: 0x14B6D20
__int64 dynamic_initializer_for__geAIObjectiveEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&geAIObjectiveEnum, UFG::AIObjectiveNames, 36, 0i64);
  return atexit(dynamic_atexit_destructor_for__geAIObjectiveEnum__);
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
  AIObjectiveCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveCondition::`vftable';
  v1->m_AIObjective.mValue = 0;
}

// File Line: 1324
// RVA: 0x36EBA0
bool __fastcall AIObjectiveCondition::Match(AIObjectiveCondition *this, ActionContext *action_context)
{
  AIObjectiveCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::ActiveAIEntityComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID)) : (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3)),
        v5) )
  {
    result = v5->m_CurrentObjective == (unsigned __int8)v2->m_AIObjective.mValue;
  }
  else
  {
    result = 0;
  }
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
  AIObjectiveAnyCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveAnyCondition::`vftable';
}

// File Line: 1361
// RVA: 0x36EB10
bool __fastcall AIObjectiveAnyCondition::Match(AIObjectiveAnyCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID)) : (v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2)),
        v4) )
  {
    result = v4->m_CurrentObjective != 0;
  }
  else
  {
    result = 0;
  }
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
  AIObjectiveIsHostileCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveIsHostileCondition::`vftable';
}

// File Line: 1398
// RVA: 0x36EC40
bool __fastcall AIObjectiveIsHostileCondition::Match(AIObjectiveIsHostileCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID)) : (v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2)),
        v4) )
  {
    result = UFG::g_AIObjectiveParams[v4->m_CurrentObjective].m_IsHostile;
  }
  else
  {
    result = 0;
  }
  return result;
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
  AIOnMeshCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIOnMeshCondition::`vftable';
}

// File Line: 1437
// RVA: 0x36ECD0
bool __fastcall AIOnMeshCondition::Match(AIOnMeshCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[36].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::NavComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
    }
    if ( v4
      && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))v4[1].m_SafePointerList.mNode.mNext[1].mNext)(&v4[1].m_SafePointerList.mNode.mNext) )
    {
      result = 1;
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
  AIAtDestinationCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIAtDestinationCondition::`vftable';
  v1->m_Tolerance = 0.5;
}

// File Line: 1477
// RVA: 0x36DE10
bool __fastcall AIAtDestinationCondition::Match(AIAtDestinationCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::NavComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::NavComponent::_TypeUID)) : (v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID))) : (v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID))) : (v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID))) : (v4 = (UFG::NavComponent *)v2->m_Components.p[36].m_pComponent),
        v4) )
  {
    result = UFG::NavComponent::IsAtDestination(v4);
  }
  else
  {
    result = 0;
  }
  return result;
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
  AIHasValidPathCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIHasValidPathCondition::`vftable';
}

// File Line: 1513
// RVA: 0x36E6B0
bool __fastcall AIHasValidPathCondition::Match(AIHasValidPathCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::NavComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::NavComponent *)v2->m_Components.p[36].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
      else
        v4 = (UFG::NavComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v2,
                                                      UFG::NavComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v2->vfptr,
                                                                                       UFG::NavComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
    }
    if ( v4 && !UFG::NavComponent::IsDestinationUnreachable(v4) )
      result = 1;
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
void __fastcall AIDestinationObstructedCondition::AIDestinationObstructedCondition(AIDestinationObstructedCondition *this)
{
  AIDestinationObstructedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIDestinationObstructedCondition::`vftable';
}

// File Line: 1546
// RVA: 0x36E460
bool __fastcall AIDestinationObstructedCondition::Match(AIDestinationObstructedCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::NavComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::NavComponent *)v2->m_Components.p[36].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
      else
        v4 = (UFG::NavComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v2,
                                                      UFG::NavComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v2->vfptr,
                                                                                       UFG::NavComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
    }
    if ( v4 && UFG::NavComponent::IsDestinationObstructed(v4) )
      result = 1;
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
  POIUseTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&POIUseTypeCondition::`vftable';
  v1->m_POIUseType.mValue = 0;
}

// File Line: 1582
// RVA: 0x371AF0
bool __fastcall POIUseTypeCondition::Match(POIUseTypeCondition *this, ActionContext *context)
{
  POIUseTypeCondition *v2; // rbx
  UFG::SimObject *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rcx

  v2 = this;
  v3 = context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[43].m_pComponent;
  }
  else
  {
    if ( (v4 & 0x8000u) != 0 )
      return 0;
    if ( (v4 >> 13) & 1 )
    {
      v5 = v3->m_Components.p[12].m_pComponent;
    }
    else
    {
      if ( (v4 >> 12) & 1 )
        return 0;
      v5 = UFG::SimObject::GetComponentOfType(v3, UFG::InterestPointUserComponent::_TypeUID);
    }
  }
  if ( v5 )
    return LODWORD(v5[7].m_BoundComponentHandles.mNode.mNext) == (unsigned __int8)v2->m_POIUseType.mValue;
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
char __fastcall HasRequestedSpeechCondition::Match(HasRequestedSpeechCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool v5; // zf
  char result; // al

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    else
      v4 = (UFG::ActorAudioComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v2->vfptr,
                                                           UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                   (UFG::SimObject *)&v2->vfptr,
                                                                                                   UFG::ActorAudioComponent::_TypeUID));
  }
  else
  {
    v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                       (UFG::SimObjectGame *)&v2->vfptr,
                                       UFG::ActorAudioComponent::_TypeUID);
  }
  if ( !v4 )
    return 0;
  v5 = (*((_BYTE *)v4 + 552) & 1) == 0;
  result = 0;
  if ( !v5 )
    result = 1;
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
char __fastcall HasSpecificSpeechAnimationCondition::Match(HasSpecificSpeechAnimationCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool v5; // zf
  char result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = v2->m_Components.p[41].m_pComponent;
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::DialogueAnimationComponent::_TypeUID);
    else
      v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::DialogueAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::DialogueAnimationComponent::_TypeUID);
  }
  else
  {
    v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::DialogueAnimationComponent::_TypeUID);
  }
  if ( !v4 )
    return 0;
  v5 = ((_QWORD)v4[2].m_pSimObject & 4) == 0;
  result = 0;
  if ( !v5 )
    result = 1;
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
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID)) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2)),
        v4) )
  {
    result = *((_BYTE *)v4 + 553) & 1;
  }
  else
  {
    result = 0;
  }
  return result;
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
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax
  UFG::Conversation *v5; // rax
  bool result; // al

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      else
        v4 = (UFG::ActorAudioComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v2->vfptr,
                                                                                                     UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    if ( v4 )
    {
      v5 = UFG::ActorAudioComponent::GetActiveAmbientConversation(v4);
      if ( v5 )
      {
        if ( v5->m_numElements - v5->m_curLine != 1 )
          result = 1;
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
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      else
        v4 = (UFG::ActorAudioComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v2->vfptr,
                                                                                                     UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    if ( v4 && UFG::ActorAudioComponent::GetActiveAmbientConversation(v4) )
      result = 1;
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
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool result; // al
  UFG::Conversation *v6; // rax

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      else
        v4 = (UFG::ActorAudioComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v2->vfptr,
                                                             UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v2->vfptr,
                                                                                                     UFG::ActorAudioComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    if ( !v4 || (v6 = UFG::ActorAudioComponent::GetActiveAmbientConversation(v4)) == 0i64 || v6->m_state == 7 )
      result = 1;
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
char __fastcall IsSpeakingCondition::Match(IsSpeakingCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    else
      v4 = (UFG::ActorAudioComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v2->vfptr,
                                                           UFG::ActorAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                   (UFG::SimObject *)&v2->vfptr,
                                                                                                   UFG::ActorAudioComponent::_TypeUID));
  }
  else
  {
    v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                       (UFG::SimObjectGame *)&v2->vfptr,
                                       UFG::ActorAudioComponent::_TypeUID);
  }
  if ( !v4 )
    return 0;
  if ( v4->m_isSpeakingCnt > 0 && v4->m_controller.m_pEvent )
    return 1;
  return 0;
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
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID)) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2)),
        v4) )
  {
    result = *((_BYTE *)v4 + 552) & 1;
  }
  else
  {
    result = 0;
  }
  return result;
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
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID)) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2)),
        v4) )
  {
    result = (*((_BYTE *)v4 + 552) >> 1) & 1;
  }
  else
  {
    result = 0;
  }
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
bool __fastcall ConversationHasActionRequestsCondition::Match(ConversationHasActionRequestsCondition *this, ActionContext *context)
{
  UFG::SimObjectCharacter *v2; // rcx
  ActionContext *v3; // rdi
  unsigned __int16 v4; // r8
  UFG::ActorAudioComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  char v7; // di
  UFG::ActorAudioComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  unsigned __int16 v10; // dx

  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  v3 = context;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
    v6 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
    v7 = 0;
    v8 = v5;
    if ( v6 )
    {
      v10 = v6->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v9 = v6->m_Components.p[45].m_pComponent;
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FaceActionComponent::_TypeUID);
        }
        else if ( (v10 >> 12) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FaceActionComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::FaceActionComponent::_TypeUID);
        }
      }
      else
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FaceActionComponent::_TypeUID);
      }
    }
    else
    {
      v9 = 0i64;
    }
    if ( v8 )
    {
      if ( (*((_BYTE *)v8 + 553) >> 5) & 1 )
        v7 = 1;
    }
    else if ( !v9 )
    {
      return (char)v9;
    }
    LOBYTE(v9) = v7;
  }
  else
  {
    LOBYTE(v9) = 0;
  }
  return (char)v9;
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
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // rsi
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rbx
  UFG::SimObject *v8; // rcx
  UFG::InterestPoint *v9; // rdi
  unsigned __int16 v10; // dx
  UFG::SimObject *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  int v15; // ecx
  char result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = context;
  if ( !v2 )
    goto LABEL_49;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v2->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v2->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    goto LABEL_49;
  v7 = 0i64;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 34i64)
                          + *(_QWORD *)&v5[1].m_TypeUID
                          + 40);
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v9 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v9 = (UFG::InterestPoint *)v8->m_Components.p[10].m_pComponent;
      }
      else if ( (v10 >> 12) & 1 )
      {
        v9 = (UFG::InterestPoint *)v8->m_Components.p[3].m_pComponent;
      }
      else
      {
        v9 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v8, UFG::InterestPoint::_TypeUID);
      }
    }
    else
    {
      v9 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
    }
  }
  else
  {
    v9 = 0i64;
  }
  v11 = v3->mSimObject.m_pPointer;
  if ( v11 )
  {
    v12 = v11->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v7 = v11->m_Components.p[43].m_pComponent;
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v7 = v11->m_Components.p[12].m_pComponent;
      }
      else if ( !((v12 >> 12) & 1) )
      {
        v7 = UFG::SimObject::GetComponentOfType(v11, UFG::InterestPointUserComponent::_TypeUID);
      }
    }
  }
  if ( !v9 )
    goto LABEL_49;
  if ( !v7 )
    goto LABEL_49;
  if ( UFG::InterestPoint::IsAutoInteractable(v9) )
    goto LABEL_49;
  v13 = v7[8].m_SafePointerList.mNode.mNext;
  if ( v13 )
  {
    if ( v13 != (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v9 )
      goto LABEL_49;
    v14 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v7[7].m_BoundComponentHandles.mNode.mPrev;
    if ( v14 )
    {
      v15 = (int)v7[7].m_BoundComponentHandles.mNode.mNext;
      if ( v15 )
      {
        if ( v14 != v7[8].m_SafePointerList.mNode.mNext
          || v7[8].m_TypeUID != v15
          || v7[8].m_NameUID != HIDWORD(v7[7].m_BoundComponentHandles.mNode.mNext) )
        {
          goto LABEL_49;
        }
      }
    }
  }
  if ( v9->mpUser.m_pPointer == v3->mSimObject.m_pPointer )
    return 1;
  if ( UFG::InterestPoint::IsReservationMatch(v9, 8u, ReserveReason_normal) )
    result = UFG::InterestPoint::IsAvailable(v9, v3->mSimObject.m_pPointer, 1);
  else
LABEL_49:
    result = 0;
  return result;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::InterestPoint *v8; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v4 = v5) : (v4 = v2->m_Components.p[20].m_pComponent)) : (v4 = v2->m_Components.p[20].m_pComponent),
        v4
     && (v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 34i64)
                                 + *(_QWORD *)&v4[1].m_TypeUID
                                 + 40)) != 0i64
     && ((v7 = v6->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent),
         v8)) )
  {
    result = UFG::InterestPoint::GetRequiresSync(v8);
  }
  else
  {
    result = 0;
  }
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
char __fastcall TargetPOISyncRequiredCondition::Match(TargetPOISyncRequiredCondition *this, ActionContext *context)
{
  TargetPOISyncRequiredCondition *v2; // rdi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rdx
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::InterestPoint *v10; // rbx

  v2 = this;
  if ( !*(_WORD *)&this->m_Position )
    return 0;
  v4 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v4->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 34i64)
                          + *(_QWORD *)&v6[1].m_TypeUID
                          + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = (UFG::InterestPoint *)v8->m_Components.p[10].m_pComponent;
    else
      v10 = (UFG::InterestPoint *)((v9 >> 12) & 1 ? v8->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                           v8,
                                                                                           UFG::InterestPoint::_TypeUID));
  }
  else
  {
    v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
  }
  if ( !v10 )
    return 0;
  if ( (!v2->m_Position || UFG::InterestPoint::GetPositionSyncRequired(v10))
    && (!v2->m_Rotation || UFG::InterestPoint::GetRotationSyncRequired(v10)) )
  {
    return 1;
  }
  return 0;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::InterestPoint *v8; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v4 = v5) : (v4 = v2->m_Components.p[20].m_pComponent)) : (v4 = v2->m_Components.p[20].m_pComponent),
        v4
     && (v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 34i64)
                                 + *(_QWORD *)&v4[1].m_TypeUID
                                 + 40)) != 0i64
     && ((v7 = v6->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent),
         v8)) )
  {
    result = UFG::InterestPoint::GetAllowSocialInteraction(v8);
  }
  else
  {
    result = 0;
  }
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
  TargetDistanceHysteresis *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetDistanceHysteresis::`vftable';
  *(_QWORD *)&v1->m_TargetType = 0i64;
  *(_QWORD *)&v1->m_ZDistanceBegin = 0x40000000i64;
  v1->m_ZDistanceEnd = 2.0;
  *(_QWORD *)&v1->m_InEqualityOperatorBegin.mValue = 50529284i64;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 2250
// RVA: 0x383C00
void __fastcall TargetDistanceHysteresis::ResolveReferences(TargetDistanceHysteresis *this, ActionNode *action_node)
{
  TargetDistanceHysteresis *v2; // rbx
  Expression::IMemberMap *v3; // rax
  signed __int64 v4; // rcx

  v2 = this;
  v3 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v4 = (signed __int64)&v2->m_MyRoot;
  if ( v3 )
    v3 = (Expression::IMemberMap *)((char *)v3 - v4);
  *(_QWORD *)v4 = v3;
  v2->m_HasBegunUID = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_HasBegunUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 2259
// RVA: 0x372B50
bool __fastcall TargetDistanceHysteresis::Match(TargetDistanceHysteresis *this, ActionContext *context)
{
  TargetDistanceHysteresis *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  signed __int64 v4; // rdi
  ActionContext *v5; // rsi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // r8
  UFG::SimComponent *v8; // rax
  __int64 v9; // r14
  UFG::SimObject *v10; // rbp
  __int64 v11; // r14
  UFG::TransformNodeComponent *v12; // rbp
  __m128 v13; // xmm1
  float v14; // xmm7_4
  __int64 v15; // rax
  float v16; // xmm6_4
  UFG::ActionTreeComponentBase *v17; // rdx
  signed __int64 v18; // rcx
  UFG::ActionTreeComponentBase *v19; // rcx
  bool v20; // bp
  __int64 v21; // rax
  UFG::ActionTreeComponentBase *v22; // rdx
  UFG::ActionTreeComponentBase *v23; // rcx
  bool result; // al
  __int64 v25; // rax
  UFG::ActionTreeComponentBase *v26; // rdx
  UFG::ActionTreeComponentBase *v27; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = context;
  if ( v3
    && ((v6 = v3->m_Flags, !((v6 >> 14) & 1)) ? ((v6 & 0x8000u) == 0 ? (!((v6 >> 13) & 1) ? (!((v6 >> 12) & 1) ? (v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v7 = v8) : (v7 = v3->m_Components.p[20].m_pComponent)) : (v7 = v3->m_Components.p[20].m_pComponent),
        v7
     && (v9 = *(_QWORD *)(56i64
                        * *(unsigned __int8 *)((unsigned int)v2->m_TargetType + *(_QWORD *)&v7[1].m_Flags + 8i64)
                        + *(_QWORD *)&v7[1].m_TypeUID
                        + 40)) != 0
     && ((v10 = v5->mSimObject.m_pPointer, v11 = *(_QWORD *)(v9 + 88), v10) ? (v12 = v10->m_pTransformNodeComponent) : (v12 = 0i64),
         v11 && v12)) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v12);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
    v13 = (__m128)*(unsigned int *)(v11 + 180);
    v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] - v12->mWorldTransform.v3.y)
                            * (float)(v13.m128_f32[0] - v12->mWorldTransform.v3.y))
                    + (float)((float)(*(float *)(v11 + 176) - v12->mWorldTransform.v3.x)
                            * (float)(*(float *)(v11 + 176) - v12->mWorldTransform.v3.x));
    LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v13);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
    UFG::TransformNodeComponent::UpdateWorldTransform(v12);
    v15 = v2->m_MyRoot.mOffset;
    LODWORD(v16) = COERCE_UNSIGNED_INT(*(float *)(v11 + 184) - v12->mWorldTransform.v3.z) & _xmm;
    if ( v15 )
      v17 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v15);
    else
      v17 = 0i64;
    if ( v15 )
      v18 = (signed __int64)&v2->m_MyRoot + v15;
    else
      v18 = 0i64;
    v19 = v5->mActionTreeComponentBase[*(char *)(v18 + 236)];
    if ( !v19 )
      v19 = v5->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v19, v17, (ActionNodeRoot *)v2->m_HasBegunUID, 0);
    v20 = CompareFloat(
            (UFG::InEqualityOperator)(unsigned __int8)v2->m_InEqualityOperatorBegin.mValue,
            v2->m_DistanceBegin,
            v14)
       && CompareFloat(
            (UFG::InEqualityOperator)(unsigned __int8)v2->m_ZInEqualityOperatorBegin.mValue,
            v2->m_ZDistanceBegin,
            v16);
    v21 = v2->m_MyRoot.mOffset;
    if ( v21 )
      v22 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v21);
    else
      v22 = 0i64;
    if ( v21 )
      v4 = (signed __int64)&v2->m_MyRoot + v21;
    v23 = v5->mActionTreeComponentBase[*(char *)(v4 + 236)];
    if ( !v23 )
      v23 = v5->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v23, v22, (ActionNodeRoot *)v2->m_HasBegunUID, v20);
    result = v20;
  }
  else
  {
    v25 = v2->m_MyRoot.mOffset;
    if ( v25 )
      v26 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v25);
    else
      v26 = 0i64;
    if ( v25 )
      v4 = (signed __int64)&v2->m_MyRoot + v25;
    v27 = v5->mActionTreeComponentBase[*(char *)(v4 + 236)];
    if ( !v27 )
      v27 = v5->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v27, v26, (ActionNodeRoot *)v2->m_HasBegunUID, 0);
    result = 0;
  }
  return result;
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
  TargetVisibleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetVisibleCondition::`vftable';
  v1->m_TargetType = 0;
  v1->m_NumSecondsToContinueAfterTargetFirstVisible = 2.0;
  v1->m_MinTimeBetweenChecks = 0.5;
  v1->m_MaxTimeBetweenChecks = 1.0;
  *(_WORD *)&v1->m_FixZForCharacter = 1;
  v1->m_DebugDrawColour.r = UFG::qColour::Red.r;
  v1->m_DebugDrawColour.g = UFG::qColour::Red.g;
  v1->m_DebugDrawColour.b = UFG::qColour::Red.b;
  v1->m_DebugDrawColour.a = UFG::qColour::Red.a;
  v1->m_MyRoot.mOffset = 0i64;
  *(_QWORD *)&v1->m_TargetIsVisibleUID = 0i64;
  *(_QWORD *)&v1->m_NextTimeToCheckTargetIsVisibleUID = 0i64;
  v1->m_TargetObjectUID = 0;
}

// File Line: 2371
// RVA: 0x383C40
void __fastcall TargetVisibleCondition::ResolveReferences(TargetVisibleCondition *this, ActionNode *action_node)
{
  TargetVisibleCondition *v2; // rdi
  ActionNode *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  __int64 v12; // rax

  v2 = this;
  v3 = action_node;
  v4 = UFG::ActionTreeComponentBase::MakeValueUID(this->m_TargetIsVisibleUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  v5 = v2->m_TimeTargetBecameVisibleUID;
  v2->m_TargetIsVisibleUID = v4;
  v6 = UFG::ActionTreeComponentBase::MakeValueUID(v5, 0);
  v7 = v2->m_NextTimeToCheckTargetIsVisibleUID;
  v2->m_TimeTargetBecameVisibleUID = v6;
  v8 = UFG::ActionTreeComponentBase::MakeValueUID(v7, 0);
  v9 = v2->m_PreviousTargetUID;
  v2->m_NextTimeToCheckTargetIsVisibleUID = v8;
  v10 = UFG::ActionTreeComponentBase::MakeValueUID(v9, eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  v11 = v2->m_TargetObjectUID;
  v2->m_PreviousTargetUID = v10;
  v2->m_TargetObjectUID = UFG::ActionTreeComponentBase::MakeValueUID(
                            v11,
                            eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  v12 = (__int64)v3->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v3->vfptr);
  if ( v12 )
    v2->m_MyRoot.mOffset = v12 - ((_QWORD)v2 + 80);
}

// File Line: 2399
// RVA: 0x3423D0
void __fastcall TargetVisibleCondition::AsyncRayCallback(UFG::RayCastData *raycastData, UFG::SimComponent *simComponent, void *callbackUserData)
{
  __int64 v3; // rax
  TargetVisibleCondition *v4; // rdi
  UFG::RayCastData *v5; // rbp
  char *v6; // r8
  signed __int64 v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rsi
  UFG::ActionTreeComponentBase *v9; // rdx
  bool v10; // bl
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  Render::DebugDrawContext *v14; // rax
  UFG::qVector3 point; // [rsp+30h] [rbp-38h]
  UFG::qColour colour; // [rsp+40h] [rbp-28h]
  UFG::SimObject *value_uid; // [rsp+78h] [rbp+10h]
  UFG::SimObject *ray_hit_object; // [rsp+88h] [rbp+20h]

  if ( simComponent )
  {
    v3 = *((_QWORD *)callbackUserData + 10);
    v4 = (TargetVisibleCondition *)callbackUserData;
    v5 = raycastData;
    if ( v3 )
      v6 = (char *)callbackUserData + v3 + 80;
    else
      v6 = 0i64;
    if ( v6[236] == 1
      || (!v3 ? (v7 = 0i64) : (v7 = (signed __int64)&v4->m_MyRoot + v3),
          v8 = (UFG::ActionTreeComponentBase *)&simComponent[1].m_SafePointerList.mNode.mNext,
          *(_BYTE *)(v7 + 236) != 2) )
    {
      v8 = (UFG::ActionTreeComponentBase *)&simComponent[1];
    }
    value_uid = 0i64;
    if ( v3 )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v3);
    else
      v9 = 0i64;
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
      v8,
      v9,
      (ActionNodeRoot *)v4->m_TargetObjectUID,
      (__int64)&value_uid);
    ray_hit_object = 0i64;
    v10 = UFG::TargetIsVisible(v5, value_uid, &ray_hit_object);
    TargetVisibleCondition::DealWithRayCastResult(v4, v10, v8);
    if ( !v10 )
    {
      if ( v4->m_DebugDraw )
      {
        v11 = v5->point.x;
        colour = v4->m_DebugDrawColour;
        v12 = v5->point.y;
        point.x = v11;
        v13 = v5->point.z;
        point.y = v12;
        point.z = v13;
        v14 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
        Render::DebugDrawContext::DrawPoint(v14, &point, &colour, &UFG::qMatrix44::msIdentity, 0i64);
      }
    }
  }
}

// File Line: 2459
// RVA: 0x3519E0
void __fastcall TargetVisibleCondition::DealWithRayCastResult(TargetVisibleCondition *this, bool target_is_visible, UFG::ActionTreeComponentBase *action_tree_memory_component)
{
  UFG::ActionTreeComponentBase *v3; // rdi
  UFG::ActionTreeComponentBase *v4; // rsi
  bool v5; // bp
  TargetVisibleCondition *v6; // rbx
  __int64 v7; // rax
  int v8; // xmm9_4
  UFG::ActionTreeComponentBase *v9; // rdx
  unsigned int v10; // er9
  __int64 v11; // rax
  UFG::ActionTreeComponentBase *v12; // rdx
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  __int64 v17; // rax
  int v18; // xmm6_4
  UFG::ActionTreeComponentBase *v19; // rdx
  unsigned int v20; // er9
  __int64 v21; // rax
  unsigned int value_uid; // [rsp+80h] [rbp+18h]

  if ( action_tree_memory_component )
  {
    LOBYTE(value_uid) = 0;
    v3 = 0i64;
    v4 = action_tree_memory_component;
    v5 = target_is_visible;
    v6 = this;
    v7 = this->m_MyRoot.mOffset;
    v8 = SLODWORD(UFG::Metrics::msInstance.mSimTime_Temp);
    if ( v7 )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v7);
    else
      v9 = 0i64;
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
      action_tree_memory_component,
      v9,
      (ActionNodeRoot *)this->m_TargetIsVisibleUID,
      (__int64)&value_uid);
    if ( v5 && !(_BYTE)value_uid )
    {
      v11 = v6->m_MyRoot.mOffset;
      if ( v11 )
        v12 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v11);
      else
        v12 = 0i64;
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
        v4,
        v12,
        (ActionNodeRoot *)v6->m_TimeTargetBecameVisibleUID,
        v10,
        v8);
    }
    v13 = v6->m_MaxTimeBetweenChecks;
    v14 = v6->m_MinTimeBetweenChecks;
    if ( v13 <= v14 )
      goto LABEL_24;
    v15 = UFG::qRandom(v13 - v14, &UFG::qDefaultSeed);
    v16 = v15 + v14;
    if ( (float)(v15 + v14) <= v14 )
      v16 = v14;
    if ( v16 >= v13 )
LABEL_24:
      v16 = v13;
    v17 = v6->m_MyRoot.mOffset;
    *(float *)&v18 = v16 + *(float *)&v8;
    if ( v17 )
      v19 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v17);
    else
      v19 = 0i64;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v4, v19, (ActionNodeRoot *)v6->m_TargetIsVisibleUID, v5);
    v21 = v6->m_MyRoot.mOffset;
    if ( v21 )
      v3 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v21);
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v4,
      v3,
      (ActionNodeRoot *)v6->m_NextTimeToCheckTargetIsVisibleUID,
      v20,
      v18);
  }
}

// File Line: 2493
// RVA: 0x35FDC0
char __fastcall TargetVisibleCondition::GetHeadPosition(TargetVisibleCondition *this, UFG::SimObject *pSimObject, UFG::qVector3 *vHeadPosOut)
{
  UFG::qVector3 *v3; // rdi
  UFG::SimObjectGame *v4; // rbx
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  __int64 v7; // rbx
  int v8; // eax
  hkQsTransformf *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4

  v3 = vHeadPosOut;
  v4 = (UFG::SimObjectGame *)pSimObject;
  if ( !(_S23_0 & 1) )
  {
    _S23_0 |= 1u;
    s_uidHeadBone = UFG::qStringHashUpper32("Bip01 Head", 0xFFFFFFFF);
  }
  if ( !v4 )
    return 0;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[9].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = v4->m_Components.p[8].m_pComponent;
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::BaseAnimationComponent::_TypeUID);
  }
  else
  {
    v6 = v4->m_Components.p[9].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v7 = *(_QWORD *)&v6[2].m_TypeUID;
  if ( !v7 )
    return 0;
  if ( !*(_QWORD *)(v7 + 440) )
    return 0;
  v8 = Skeleton::GetBoneID(*(Skeleton **)(v7 + 480), s_uidHeadBone);
  if ( v8 < 0 )
    return 0;
  v9 = SkeletalPose::GetTranslationMS((SkeletalPose *)(v7 + 240), v8);
  v10 = v9->m_translation.m_quad.m128_f32[1];
  v11 = v9->m_translation.m_quad.m128_f32[2];
  LODWORD(v3->x) = v9->m_translation.m_quad.m128_i32[0];
  v3->y = v10;
  v3->z = v11;
  return 1;
}

// File Line: 2519
// RVA: 0x3738E0
char __fastcall TargetVisibleCondition::Match(TargetVisibleCondition *this, ActionContext *context)
{
  ActionContext *v2; // r13
  TargetVisibleCondition *v3; // r15
  float v4; // xmm6_4
  UFG::SimObjectGame *v5; // rcx
  char v6; // r14
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // r8
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // rdi
  UFG::SimObjectCVBase *v11; // rcx
  UFG::ActiveAIEntityComponent *v12; // rax
  unsigned __int16 v13; // dx
  int v14; // ecx
  unsigned int v15; // edx
  UFG::PedKnowledgeRecord *v16; // r8
  UFG::PedKnowledgeRecord *v17; // rax
  __int64 v19; // rax
  UFG::ActionTreeComponentBase *v20; // rdx
  signed __int64 v21; // rcx
  UFG::ActionTreeComponentBase *v22; // rcx
  __int64 v23; // rax
  UFG::ActionTreeComponentBase *v24; // rdx
  signed __int64 v25; // rcx
  UFG::ActionTreeComponentBase *v26; // rcx
  unsigned int v27; // er9
  bool v28; // al
  char v29; // bl
  __int64 v30; // rax
  UFG::ActionTreeComponentBase *v31; // rdx
  signed __int64 v32; // rcx
  UFG::ActionTreeComponentBase *v33; // rcx
  __int64 v34; // rax
  UFG::ActionTreeComponentBase *v35; // rdx
  signed __int64 v36; // rcx
  UFG::ActionTreeComponentBase *v37; // rcx
  __int64 v38; // rax
  signed __int64 v39; // rcx
  UFG::ActionTreeComponentBase *v40; // rax
  signed __int64 v41; // rcx
  UFG::SimComponent *v42; // rdx
  __int64 v43; // rax
  UFG::ActionTreeComponentBase *v44; // rdx
  signed __int64 v45; // rcx
  UFG::ActionTreeComponentBase *v46; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v47; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v48; // rax
  UFG::TransformNodeComponent *v49; // rsi
  UFG::SimObject *v50; // rax
  UFG::TransformNodeComponent *v51; // r12
  __int64 v52; // rax
  signed __int64 v53; // rcx
  UFG::ActionTreeComponentBase *v54; // rax
  signed __int64 v55; // rcx
  UFG::SimComponent *v56; // rdx
  __int64 v57; // rax
  UFG::ActionTreeComponentBase *v58; // rdx
  signed __int64 v59; // rcx
  UFG::ActionTreeComponentBase *v60; // rcx
  bool v61; // bl
  bool v62; // di
  UFG::SimObject *v63; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v64; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v65; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v66; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v67; // rax
  __int64 v68; // rax
  UFG::ActionTreeComponentBase *v69; // rdx
  signed __int64 v70; // rcx
  UFG::ActionTreeComponentBase *v71; // rcx
  __int64 v72; // rax
  UFG::ActionTreeComponentBase *v73; // rdx
  signed __int64 v74; // rcx
  UFG::ActionTreeComponentBase *v75; // rcx
  UFG::AsyncRayCastData ray_hit_object; // [rsp+48h] [rbp-80h]
  UFG::qVector3 to_position; // [rsp+158h] [rbp+90h]
  UFG::qVector3 vHeadPosOut; // [rsp+168h] [rbp+A0h]
  __int64 v79; // [rsp+178h] [rbp+B0h]
  unsigned int value_uid; // [rsp+1E0h] [rbp+118h]
  unsigned int v81; // [rsp+1E8h] [rbp+120h]
  unsigned int v82; // [rsp+1F0h] [rbp+128h]

  v79 = -2i64;
  v2 = context;
  v3 = this;
  v4 = UFG::Metrics::msInstance.mSimTime_Temp;
  v5 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v6 = 0;
  if ( v5 )
  {
    v7 = v5->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = v9;
    }
    else
    {
      v8 = v5->m_Components.p[20].m_pComponent;
    }
    if ( v8 )
    {
      v10 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)((unsigned int)v3->m_TargetType + *(_QWORD *)&v8[1].m_Flags + 8i64)
                               + *(_QWORD *)&v8[1].m_TypeUID
                               + 40);
      v11 = (UFG::SimObjectCVBase *)v2->mSimObject.m_pPointer;
      if ( v11 )
      {
        v13 = v11->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v12 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v11);
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
          {
            v12 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v11->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else if ( (v13 >> 12) & 1 )
          {
            v12 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v11->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else
          {
            v12 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v11->vfptr,
                                                    UFG::ActiveAIEntityComponent::_TypeUID);
          }
        }
        else
        {
          v12 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v11);
        }
      }
      else
      {
        v12 = 0i64;
      }
      v14 = 0;
      v15 = v12->m_KnowledgeBase.m_aHostilePedRecords.size;
      if ( v15 )
      {
        v16 = v12->m_KnowledgeBase.m_aHostilePedRecords.p;
        while ( 1 )
        {
          v17 = &v16[v14];
          if ( v10 == v17->pSimObject.m_pPointer )
            break;
          if ( ++v14 >= v15 )
            goto LABEL_28;
        }
      }
      else
      {
LABEL_28:
        v17 = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
      }
      if ( v17->pSimObject.m_pPointer )
        return *((_BYTE *)v17 + 48) & 1;
      ray_hit_object.mInput.m_userData = 0i64;
      *(float *)&v81 = -99999.0;
      v19 = v3->m_MyRoot.mOffset;
      if ( v19 )
        v20 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v19);
      else
        v20 = 0i64;
      if ( v19 )
        v21 = (signed __int64)&v3->m_MyRoot + v19;
      else
        v21 = 0i64;
      v22 = v2->mActionTreeComponentBase[*(char *)(v21 + 236)];
      if ( !v22 )
        v22 = v2->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
        v22,
        v20,
        (ActionNodeRoot *)v3->m_PreviousTargetUID,
        (__int64)&ray_hit_object.mInput.m_userData);
      v23 = v3->m_MyRoot.mOffset;
      if ( v23 )
        v24 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v23);
      else
        v24 = 0i64;
      if ( v23 )
        v25 = (signed __int64)&v3->m_MyRoot + v23;
      else
        v25 = 0i64;
      v26 = v2->mActionTreeComponentBase[*(char *)(v25 + 236)];
      if ( !v26 )
        v26 = v2->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
        v26,
        v24,
        (ActionNodeRoot *)v3->m_NextTimeToCheckTargetIsVisibleUID,
        (__int64)&v81);
      v28 = v10 != (UFG::SimObject *)ray_hit_object.mInput.m_userData;
      if ( v4 > *(float *)&v81 || v28 )
      {
        v29 = 1;
        if ( v28 )
        {
          v30 = v3->m_MyRoot.mOffset;
          if ( v30 )
            v31 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v30);
          else
            v31 = 0i64;
          if ( v30 )
            v32 = (signed __int64)&v3->m_MyRoot + v30;
          else
            v32 = 0i64;
          v33 = v2->mActionTreeComponentBase[*(char *)(v32 + 236)];
          if ( !v33 )
            v33 = v2->mActionTreeComponentBase[1];
          UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
            v33,
            v31,
            (ActionNodeRoot *)v3->m_TimeTargetBecameVisibleUID,
            v27,
            SLODWORD(FLOAT_N99999_0));
        }
      }
      else
      {
        v29 = 0;
      }
      if ( v10 && v29 )
      {
        v34 = v3->m_MyRoot.mOffset;
        if ( v34 )
          v35 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v34);
        else
          v35 = 0i64;
        if ( v34 )
          v36 = (signed __int64)&v3->m_MyRoot + v34;
        else
          v36 = 0i64;
        v37 = v2->mActionTreeComponentBase[*(char *)(v36 + 236)];
        if ( !v37 )
          v37 = v2->mActionTreeComponentBase[1];
        UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
          v37,
          v35,
          (ActionNodeRoot *)v3->m_PreviousTargetUID,
          (__int64)v10);
        TargetVisibleCondition::GetHeadPosition(v3, v2->mSimObject.m_pPointer, &vHeadPosOut);
        if ( TargetVisibleCondition::GetHeadPosition(v3, v10, &to_position) )
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
          *(_QWORD *)&ray_hit_object.mInput.m_enableShapeCollectionFilter.m_bool = (char *)&ray_hit_object + 224;
          ray_hit_object.mInput.m_to.m_quad.m128_u64[0] = (unsigned __int64)&ray_hit_object.simComponent;
          ray_hit_object.simComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
          ray_hit_object.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
          ray_hit_object.simComponent.m_pPointer = 0i64;
          ray_hit_object.raycastCallback = 0i64;
          ray_hit_object.callbackUserData = v3;
          v38 = v3->m_MyRoot.mOffset;
          if ( v38 )
            v39 = (signed __int64)&v3->m_MyRoot + v38;
          else
            v39 = 0i64;
          if ( *(_BYTE *)(v39 + 236) == 1 )
          {
            v40 = v2->mActionTreeComponentBase[1];
          }
          else
          {
            if ( v38 )
              v41 = (signed __int64)&v3->m_MyRoot + v38;
            else
              v41 = 0i64;
            if ( *(_BYTE *)(v41 + 236) == 2 )
            {
              v40 = v2->mActionTreeComponentBase[2];
              v42 = (UFG::SimComponent *)&v40[-1].mActionTreeMemoryDataStructs;
LABEL_83:
              if ( !v40 )
                v42 = 0i64;
              UFG::qSafePointer<Creature,Creature>::operator=(&ray_hit_object.simComponent, v42);
              ray_hit_object.raycastCallback = TargetVisibleCondition::AsyncRayCallback;
              v43 = v3->m_MyRoot.mOffset;
              if ( v43 )
                v44 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v43);
              else
                v44 = 0i64;
              if ( v43 )
                v45 = (signed __int64)&v3->m_MyRoot + v43;
              else
                v45 = 0i64;
              v46 = v2->mActionTreeComponentBase[*(char *)(v45 + 236)];
              if ( !v46 )
                v46 = v2->mActionTreeComponentBase[1];
              UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
                v46,
                v44,
                (ActionNodeRoot *)v3->m_TargetObjectUID,
                (__int64)v10);
              UFG::DoRaycast(
                &vHeadPosOut,
                &to_position,
                v10,
                0i64,
                (UFG::SimObject **)&ray_hit_object.mInput.m_from.m_quad.m128_u64[1],
                &ray_hit_object,
                v3->m_DebugDraw != 0,
                &v3->m_DebugDrawColour);
              ray_hit_object.mInput.m_to.m_quad.m128_u64[0] = (unsigned __int64)&ray_hit_object.simComponent;
              if ( ray_hit_object.simComponent.m_pPointer )
              {
                v47 = ray_hit_object.simComponent.mPrev;
                v48 = ray_hit_object.simComponent.mNext;
                ray_hit_object.simComponent.mPrev->mNext = ray_hit_object.simComponent.mNext;
                v48->mPrev = v47;
                ray_hit_object.simComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
                ray_hit_object.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
              }
              ray_hit_object.simComponent.m_pPointer = 0i64;
LABEL_125:
              v66 = ray_hit_object.simComponent.mPrev;
              v67 = ray_hit_object.simComponent.mNext;
              ray_hit_object.simComponent.mPrev->mNext = ray_hit_object.simComponent.mNext;
              v67->mPrev = v66;
              ray_hit_object.simComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
              ray_hit_object.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
              goto LABEL_126;
            }
            v40 = v2->mActionTreeComponentBase[3];
          }
          v42 = (UFG::SimComponent *)&v40[-1].mActionTreeMemoryDataStructs.mTree.mRoot.mChild1;
          goto LABEL_83;
        }
        v49 = v10->m_pTransformNodeComponent;
        ray_hit_object.mInput.m_from.m_quad.m128_u64[1] = (unsigned __int64)v10->m_pTransformNodeComponent;
        v50 = v2->mSimObject.m_pPointer;
        v51 = 0i64;
        if ( v50 )
          v51 = v50->m_pTransformNodeComponent;
        if ( !v49 || !v51 )
          goto LABEL_126;
        *(_QWORD *)&ray_hit_object.mInput.m_enableShapeCollectionFilter.m_bool = 0i64;
        ray_hit_object.mInput.m_enableShapeCollectionFilter.m_bool = 0;
        ray_hit_object.mInput.m_filterInfo = 0;
        ray_hit_object.mInput.m_userData = 0i64;
        LODWORD(ray_hit_object.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
        ray_hit_object.mOutput.m_extraInfo = -1;
        ray_hit_object.mOutput.m_shapeKeyIndex = 0;
        ray_hit_object.mOutput.m_shapeKeys[0] = -1;
        ray_hit_object.mOutput.m_rootCollidable = 0i64;
        ray_hit_object.mDebugName = 0i64;
        ray_hit_object.mCollisionModelName.mUID = -1;
        ray_hit_object.mInput.m_to.m_quad.m128_u64[0] = (unsigned __int64)&ray_hit_object.simComponent;
        ray_hit_object.mInput.m_to.m_quad.m128_u64[1] = (unsigned __int64)&ray_hit_object.simComponent;
        ray_hit_object.simComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
        ray_hit_object.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
        ray_hit_object.simComponent.m_pPointer = 0i64;
        ray_hit_object.raycastCallback = 0i64;
        ray_hit_object.callbackUserData = v3;
        v52 = v3->m_MyRoot.mOffset;
        if ( v52 )
          v53 = (signed __int64)&v3->m_MyRoot + v52;
        else
          v53 = 0i64;
        if ( *(_BYTE *)(v53 + 236) == 1 )
        {
          v54 = v2->mActionTreeComponentBase[1];
        }
        else
        {
          if ( v52 )
            v55 = (signed __int64)&v3->m_MyRoot + v52;
          else
            v55 = 0i64;
          if ( *(_BYTE *)(v55 + 236) == 2 )
          {
            v54 = v2->mActionTreeComponentBase[2];
            v56 = (UFG::SimComponent *)&v54[-1].mActionTreeMemoryDataStructs;
LABEL_112:
            if ( !v54 )
              v56 = 0i64;
            UFG::qSafePointer<Creature,Creature>::operator=(&ray_hit_object.simComponent, v56);
            ray_hit_object.raycastCallback = TargetVisibleCondition::AsyncRayCallback;
            v57 = v3->m_MyRoot.mOffset;
            if ( v57 )
              v58 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v57);
            else
              v58 = 0i64;
            if ( v57 )
              v59 = (signed __int64)&v3->m_MyRoot + v57;
            else
              v59 = 0i64;
            v60 = v2->mActionTreeComponentBase[*(char *)(v59 + 236)];
            if ( !v60 )
              v60 = v2->mActionTreeComponentBase[1];
            UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
              v60,
              v58,
              (ActionNodeRoot *)v3->m_TargetObjectUID,
              (__int64)v10);
            v61 = v3->m_DebugDraw != 0;
            v62 = v3->m_FixZForCharacter != 0;
            v63 = v49->m_pSimObject;
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)ray_hit_object.mInput.m_from.m_quad.m128_u64[1]);
            UFG::DoRaycast(
              v51,
              (UFG::qVector3 *)(ray_hit_object.mInput.m_from.m_quad.m128_u64[1] + 176),
              v63,
              1.5,
              v62,
              0i64,
              (UFG::SimObject **)&ray_hit_object.mInput.m_enableShapeCollectionFilter,
              &ray_hit_object,
              v61,
              &v3->m_DebugDrawColour);
            ray_hit_object.mInput.m_to.m_quad.m128_u64[1] = (unsigned __int64)&ray_hit_object.simComponent;
            if ( ray_hit_object.simComponent.m_pPointer )
            {
              v64 = ray_hit_object.simComponent.mPrev;
              v65 = ray_hit_object.simComponent.mNext;
              ray_hit_object.simComponent.mPrev->mNext = ray_hit_object.simComponent.mNext;
              v65->mPrev = v64;
              ray_hit_object.simComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
              ray_hit_object.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&ray_hit_object.simComponent.mPrev;
            }
            ray_hit_object.simComponent.m_pPointer = 0i64;
            goto LABEL_125;
          }
          v54 = v2->mActionTreeComponentBase[3];
        }
        v56 = (UFG::SimComponent *)&v54[-1].mActionTreeMemoryDataStructs.mTree.mRoot.mChild1;
        goto LABEL_112;
      }
    }
  }
LABEL_126:
  LOBYTE(value_uid) = 0;
  *(float *)&v82 = -99999.0;
  v68 = v3->m_MyRoot.mOffset;
  if ( v68 )
    v69 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v68);
  else
    v69 = 0i64;
  if ( v68 )
    v70 = (signed __int64)&v3->m_MyRoot + v68;
  else
    v70 = 0i64;
  v71 = v2->mActionTreeComponentBase[*(char *)(v70 + 236)];
  if ( !v71 )
    v71 = v2->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v71,
    v69,
    (ActionNodeRoot *)v3->m_TargetIsVisibleUID,
    (__int64)&value_uid);
  v72 = v3->m_MyRoot.mOffset;
  if ( v72 )
    v73 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v72);
  else
    v73 = 0i64;
  if ( v72 )
    v74 = (signed __int64)&v3->m_MyRoot + v72;
  else
    v74 = 0i64;
  v75 = v2->mActionTreeComponentBase[*(char *)(v74 + 236)];
  if ( !v75 )
    v75 = v2->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v75,
    v73,
    (ActionNodeRoot *)v3->m_TimeTargetBecameVisibleUID,
    (__int64)&v82);
  if ( (_BYTE)value_uid || v4 < (float)(*(float *)&v82 + v3->m_NumSecondsToContinueAfterTargetFirstVisible) )
    v6 = 1;
  return v6;
})(*(float *)&v82 + v3->m_NumSecondsToContinueAfterTargetFirstVisible) )
    v6 = 1;
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
  TargetKnowledgeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetKnowledgeCondition::`vftable';
  v1->m_TargetType = 0;
  *(_WORD *)&v1->m_HasEverSeen = 0;
  v1->m_CanPathTo = 0;
}

// File Line: 2730
// RVA: 0x373130
char __fastcall TargetKnowledgeCondition::Match(TargetKnowledgeCondition *this, ActionContext *context)
{
  TargetKnowledgeCondition *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rdi
  UFG::SimObjectCVBase *v9; // rcx
  unsigned int v10; // ebx
  UFG::ActiveAIEntityComponent *v11; // rax
  unsigned __int16 v12; // dx
  unsigned int v13; // ecx
  UFG::PedKnowledgeRecord *v14; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    goto LABEL_41;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    goto LABEL_41;
  v8 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)((unsigned int)v2->m_TargetType + *(_QWORD *)&v6[1].m_Flags + 8i64)
                          + *(_QWORD *)&v6[1].m_TypeUID
                          + 40);
  if ( !v8 )
    goto LABEL_41;
  v9 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
  v10 = 0;
  if ( v9 )
  {
    v12 = v9->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      else
        v11 = (UFG::ActiveAIEntityComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v9->vfptr,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    }
  }
  else
  {
    v11 = 0i64;
  }
  v13 = v11->m_KnowledgeBase.m_aHostilePedRecords.size;
  if ( v13 )
  {
    v14 = v11->m_KnowledgeBase.m_aHostilePedRecords.p;
    while ( v8 != v14->pSimObject.m_pPointer )
    {
      ++v10;
      ++v14;
      if ( v10 >= v13 )
        goto LABEL_29;
    }
  }
  else
  {
LABEL_29:
    v14 = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
  }
  if ( v14->pSimObject.m_pPointer
    && (v2->m_CanSee && *((_BYTE *)v14 + 48) & 1
     || v2->m_HasEverSeen && *((_BYTE *)v14 + 48) & 2
     || v2->m_CanPathTo && *((_BYTE *)v14 + 48) & 4) )
  {
    result = 1;
  }
  else
  {
LABEL_41:
    result = 0;
  }
  return result;
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
  UFG::SimObject *v2; // rbx
  UFG::TransformNodeComponent *v3; // rbx
  UFG::Camera *v4; // rcx
  UFG::qVector3 result; // [rsp+30h] [rbp-18h]
  bool is_on_screen; // [rsp+58h] [rbp+10h]
  UFG::qVector2 viewport_scale; // [rsp+60h] [rbp+18h]

  v2 = context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_pTransformNodeComponent;
  if ( !v3 )
    return 0;
  viewport_scale.x = 1.0;
  viewport_scale.y = 1.0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v4 = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
  if ( v4 )
    v4 = (UFG::Camera *)((char *)v4 + 80);
  UFG::Camera::GetScreenCoord(v4, &result, (UFG::qVector3 *)&v3->mWorldTransform.v3, &viewport_scale, &is_on_screen);
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
  return atexit(dynamic_atexit_destructor_for__gRangePerferenceEnum__);
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
  GetInFormationCondition *v1; // rbx
  IConditionInit *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rax
  signed __int64 v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v2 = (IConditionInit *)&v1->vfptr;
  v3 = (UFG::qNode<IConditionInit,IConditionInit> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&GetInFormationCondition::`vftable'{for `Condition'};
  v2->vfptr = (IConditionInitVtbl *)&GetInFormationCondition::`vftable'{for `IConditionInit'};
  *(_WORD *)&v1->m_TargetType.mValue = 22;
  v1->m_AttackType.mValue = 0;
  v4 = (signed __int64)&v1->m_ActionPath;
  *(_DWORD *)v4 = 0;
  *(_QWORD *)(v4 + 8) = 0i64;
  v1->m_GetInFormationNodeUID = 0;
}

// File Line: 2834
// RVA: 0x3373C0
void __fastcall GetInFormationCondition::~GetInFormationCondition(GetInFormationCondition *this)
{
  GetInFormationCondition *v1; // rdi
  IConditionInit *v2; // rsi
  ActionPath *v3; // rbx
  __int64 v4; // rax
  __int64 v5; // rax
  char *v6; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v7; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v8; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v9; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GetInFormationCondition::`vftable'{for `Condition'};
  v2 = (IConditionInit *)&this->vfptr;
  this->vfptr = (IConditionInitVtbl *)&GetInFormationCondition::`vftable'{for `IConditionInit'};
  v3 = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    v4 = this->m_ActionPath.mPath.mData.mOffset;
    if ( v4 && (UFG::qOffset64<ActionID *> *)((char *)&v3->mPath.mData + v4) )
    {
      v5 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v5 )
        v6 = (char *)&this->m_ActionPath.mPath.mData + v5;
      else
        v6 = 0i64;
      operator delete[](v6);
    }
    v3->mPath.mData.mOffset = 0i64;
    v3->mPath.mCount &= 0x80000000;
  }
  v7 = (UFG::qNode<IConditionInit,IConditionInit> *)&v2->mPrev;
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 2839
// RVA: 0x383120
void __fastcall GetInFormationCondition::ResolveReferences(GetInFormationCondition *this, ActionNode *action_node)
{
  GetInFormationCondition *v2; // rbx
  ActionNodeRoot *v3; // rax
  ActionNodeRoot *v4; // rdi
  IConditionInit *v5; // rdx
  __int64 v6; // rax
  signed __int64 v7; // rcx

  v2 = this;
  v3 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  v4 = v3;
  if ( v2 )
    v5 = (IConditionInit *)&v2->vfptr;
  else
    v5 = 0i64;
  ActionNodeRoot::AddToInitList(v3, v5);
  v6 = (__int64)v4->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v4->vfptr);
  v7 = (signed __int64)&v2->m_MyRoot;
  if ( v6 )
    v6 -= v7;
  *(_QWORD *)v7 = v6;
  v2->m_GetInFormationNodeUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                  v2->m_GetInFormationNodeUID,
                                  eACTION_TREE_MEMORY_ELEMENT_GET_IN_FORMATION_NODE_POINTER);
}

// File Line: 2862
// RVA: 0x365C60
void __fastcall GetInFormationCondition::Init(GetInFormationCondition *this, ActionContext *action_context)
{
  ActionContext *v2; // rbp
  GetInFormationCondition *v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::GetInFormationComponent *v6; // rsi
  UFG::SimComponent *v7; // rax
  signed __int64 v8; // rbx
  __int64 v9; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  signed __int64 v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  UFG::GetInFormationNode *v13; // r9
  __int64 v14; // rcx
  UFG::ActionTreeComponentBase *v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  UFG::GetInFormationNode *value_uid; // [rsp+48h] [rbp+10h]

  v2 = action_context;
  v3 = this;
  v4 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::GetInFormationComponent *)v4->m_Components.p[32].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GetInFormationComponent::_TypeUID);
        else
          v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GetInFormationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::GetInFormationComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GetInFormationComponent::_TypeUID);
      }
      v6 = (UFG::GetInFormationComponent *)v7;
    }
    if ( v6 )
    {
      v8 = 0i64;
      value_uid = 0i64;
      v9 = *(_QWORD *)&v3->m_TargetType.mValue;
      if ( v9 )
        v10 = (UFG::ActionTreeComponentBase *)(&v3->m_TargetType.mValue + v9);
      else
        v10 = 0i64;
      if ( v9 )
        v11 = (signed __int64)(&v3->m_TargetType + v9);
      else
        v11 = 0i64;
      v12 = v2->mActionTreeComponentBase[*(char *)(v11 + 236)];
      if ( !v12 )
        v12 = v2->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInFormationNode *>(
        v12,
        v10,
        (ActionNodeRoot *)HIDWORD(v3->vfptr),
        (__int64)&value_uid);
      if ( value_uid )
      {
        UFG::GetInFormationNode::ReInit(
          value_uid,
          (UFG::eFormationRangePreference)BYTE1(v3->vfptr),
          (UFG::eAttackType)BYTE2(v3->vfptr),
          (UFG::eTargetTypeEnum)LOBYTE(v3->vfptr));
      }
      else
      {
        if ( !(_S24 & 1) )
        {
          _S24 |= 1u;
          name_uid = UFG::qStringHash32("GetInFormationComponent", 0xFFFFFFFF);
        }
        v13 = UFG::GetInFormationComponent::MakeNewNode(
                v6,
                (UFG::eFormationRangePreference)BYTE1(v3->vfptr),
                (UFG::eAttackType)BYTE2(v3->vfptr),
                (UFG::eTargetTypeEnum)LOBYTE(v3->vfptr));
        v14 = *(_QWORD *)&v3->m_TargetType.mValue;
        if ( v14 )
          v15 = (UFG::ActionTreeComponentBase *)(&v3->m_TargetType.mValue + v14);
        else
          v15 = 0i64;
        if ( v14 )
          v8 = (signed __int64)(&v3->m_TargetType + v14);
        v16 = v2->mActionTreeComponentBase[*(char *)(v8 + 236)];
        if ( !v16 )
          v16 = v2->mActionTreeComponentBase[1];
        UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::GetInFormationNode *>(
          v16,
          v15,
          (ActionNodeRoot *)HIDWORD(v3->vfptr),
          (__int64)v13);
      }
    }
  }
}

// File Line: 2909
// RVA: 0x34C0E0
bool __fastcall GetInPedFormationCondition::CanGetInPedFormation(GetInPedFormationCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // rdi
  UFG::ActionTreeComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  UFG::HealthComponent *v8; // rax
  unsigned __int16 v9; // dx

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = context;
  if ( v2 )
  {
    v5 = v2->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = (UFG::ActionTreeComponent *)v2->m_Components.p[7].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = (UFG::ActionTreeComponent *)v2->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::ActionTreeComponent::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v4 = (UFG::ActionTreeComponent *)v6;
      }
    }
    else
    {
      v4 = (UFG::ActionTreeComponent *)v2->m_Components.p[7].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v8 = (UFG::HealthComponent *)v7->m_Components.p[6].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v8 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HealthComponent::_TypeUID);
      }
      else if ( (v9 >> 12) & 1 )
      {
        v8 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                       (UFG::SimObject *)&v7->vfptr,
                                       UFG::HealthComponent::_TypeUID);
      }
    }
    else
    {
      v8 = (UFG::HealthComponent *)v7->m_Components.p[6].m_pComponent;
    }
  }
  else
  {
    v8 = 0i64;
  }
  return !UFG::IsDowned(v4, v8) && !UFG::IsStunned(v4);
}

// File Line: 2925
// RVA: 0x36FC30
bool __fastcall GetInFormationCondition::Match(GetInFormationCondition *this, ActionContext *context)
{
  __int64 v2; // rax
  ActionContext *v3; // rdi
  GetInFormationCondition *v4; // rbp
  UFG::ActionTreeComponentBase *v5; // rdx
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::GetInFormationNode *v8; // r8
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // r9
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::FormationManagerComponent *v16; // rbx
  UFG::FormationManagerComponent *v17; // rax
  UFG::GetInFormationNode *v18; // rdi
  char v19; // al
  UFG::GetInFormationNode *v20; // rdi
  int v21; // edi
  UFG::GetInFormationNode *value_uid; // [rsp+30h] [rbp+8h]

  v2 = this->m_MyRoot.mOffset;
  v3 = context;
  v4 = this;
  value_uid = 0i64;
  if ( v2 )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v5 = 0i64;
  if ( v2 )
    v6 = (char *)&this->m_MyRoot + v2;
  else
    v6 = 0i64;
  v7 = v3->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInFormationNode *>(
    v7,
    v5,
    (ActionNodeRoot *)v4->m_GetInFormationNodeUID,
    (__int64)&value_uid);
  v8 = value_uid;
  if ( !value_uid )
    return 0;
  v9 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( !v9 )
    goto LABEL_53;
  v10 = v9->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = v9->m_Components.p[20].m_pComponent;
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v12 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v8 = value_uid;
    v11 = v12;
  }
  else
  {
    v11 = v9->m_Components.p[20].m_pComponent;
  }
  if ( !v11
    || (v13 = *(UFG::SimObjectGame **)(56i64
                                     * *(unsigned __int8 *)((unsigned __int8)v4->m_TargetType.mValue
                                                          + *(_QWORD *)&v11[1].m_Flags
                                                          + 8i64)
                                     + *(_QWORD *)&v11[1].m_TypeUID
                                     + 40)) == 0i64
    || ((v14 = v13->m_Flags, !((v14 >> 14) & 1)) ? ((v14 & 0x8000u) == 0 ? (!((v14 >> 13) & 1) ? (!((v14 >> 12) & 1) ? (v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::FormationManagerComponent::_TypeUID)) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID))) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID))) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID))) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID)),
        (v8 = value_uid, (v16 = (UFG::FormationManagerComponent *)v15) == 0i64) || !value_uid) )
  {
LABEL_53:
    UFG::GetInFormationNode::UnregisterFromFormationManager(v8);
    return 0;
  }
  v17 = (UFG::FormationManagerComponent *)value_uid->m_pTargetFormationManagerComponent.m_pPointer;
  if ( v17 && v16 != v17 )
    UFG::GetInFormationNode::UnregisterFromFormationManager(value_uid);
  if ( !GetInPedFormationCondition::CanGetInPedFormation((GetInPedFormationCondition *)v4, v3) )
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
    goto LABEL_45;
  v20 = value_uid;
  if ( value_uid->m_AllowedToSwitchToRangePreference )
  {
    v21 = UFG::FormationManagerComponent::GetDesiredRange(v16, value_uid);
    if ( UFG::FormationManagerComponent::RangeMeetsPreference(
           v16,
           v21,
           (UFG::eFormationRangePreference)(unsigned __int8)v4->m_RangePreference.mValue) )
    {
      UFG::FormationManagerComponent::Reregister(v16, value_uid, v21, 1);
    }
LABEL_45:
    v20 = value_uid;
  }
  if ( UFG::FormationManagerComponent::IsRegistered(v16, v20) )
  {
    UFG::GetInFormationNode::SetTargetFormationManagerComponent(v20, v16);
    return UFG::FormationManagerComponent::IsInFormation(v16, value_uid) == 0;
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
  GetInPedFormationCondition *v1; // rbx
  IConditionInit *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rax
  signed __int64 v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v2 = (IConditionInit *)&v1->vfptr;
  v3 = (UFG::qNode<IConditionInit,IConditionInit> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&GetInPedFormationCondition::`vftable'{for `Condition'};
  v2->vfptr = (IConditionInitVtbl *)&GetInPedFormationCondition::`vftable'{for `IConditionInit'};
  v1->m_TargetType.mValue = 62;
  v4 = (signed __int64)&v1->m_ActionPath;
  *(_DWORD *)v4 = 0;
  *(_QWORD *)(v4 + 8) = 0i64;
  v1->m_MyRoot.mOffset = 0i64;
  v1->m_GetInPedFormationNodeUID = 0;
}

// File Line: 3068
// RVA: 0x337910
void __fastcall GetInPedFormationCondition::~GetInPedFormationCondition(GetInPedFormationCondition *this)
{
  GetInPedFormationCondition *v1; // rdi
  IConditionInit *v2; // rsi
  ActionPath *v3; // rbx
  __int64 v4; // rax
  __int64 v5; // rax
  char *v6; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v7; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v8; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v9; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GetInPedFormationCondition::`vftable'{for `Condition'};
  v2 = (IConditionInit *)&this->vfptr;
  this->vfptr = (IConditionInitVtbl *)&GetInPedFormationCondition::`vftable'{for `IConditionInit'};
  v3 = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    v4 = this->m_ActionPath.mPath.mData.mOffset;
    if ( v4 && (UFG::qOffset64<ActionID *> *)((char *)&v3->mPath.mData + v4) )
    {
      v5 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v5 )
        v6 = (char *)&this->m_ActionPath.mPath.mData + v5;
      else
        v6 = 0i64;
      operator delete[](v6);
    }
    v3->mPath.mData.mOffset = 0i64;
    v3->mPath.mCount &= 0x80000000;
  }
  v7 = (UFG::qNode<IConditionInit,IConditionInit> *)&v2->mPrev;
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 3073
// RVA: 0x383230
void __fastcall GetInPedFormationCondition::ResolveReferences(GetInPedFormationCondition *this, ActionNode *action_node)
{
  GetInPedFormationCondition *v2; // rbx
  ActionNodeRoot *v3; // rax
  ActionNodeRoot *v4; // rdi
  IConditionInit *v5; // rdx
  __int64 v6; // rax
  signed __int64 v7; // rcx

  v2 = this;
  v3 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  v4 = v3;
  if ( v2 )
    v5 = (IConditionInit *)&v2->vfptr;
  else
    v5 = 0i64;
  ActionNodeRoot::AddToInitList(v3, v5);
  v6 = (__int64)v4->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v4->vfptr);
  v7 = (signed __int64)&v2->m_MyRoot;
  if ( v6 )
    v6 -= v7;
  *(_QWORD *)v7 = v6;
  v2->m_GetInPedFormationNodeUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                     v2->m_GetInPedFormationNodeUID,
                                     eACTION_TREE_MEMORY_ELEMENT_GET_IN_PED_FORMATION_NODE_POINTER);
}

// File Line: 3096
// RVA: 0x365E10
void __fastcall GetInPedFormationCondition::Init(GetInPedFormationCondition *this, ActionContext *action_context)
{
  ActionContext *v2; // rbp
  GetInPedFormationCondition *v3; // r14
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::GetInPedFormationComponent *v6; // rdi
  UFG::SimComponent *v7; // rax
  signed __int64 v8; // rbx
  __int64 v9; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  signed __int64 v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  UFG::GetInPedFormationNode *v13; // rsi
  UFG::GetInPedFormationNode *v14; // r9
  __int64 v15; // rcx
  UFG::ActionTreeComponentBase *v16; // rdx
  UFG::ActionTreeComponentBase *v17; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::GetInPedFormationNode *value_uid; // [rsp+58h] [rbp+10h]

  v2 = action_context;
  v3 = this;
  v4 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::GetInPedFormationComponent *)v4->m_Components.p[34].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GetInPedFormationComponent::_TypeUID);
        else
          v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GetInPedFormationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::GetInPedFormationComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::GetInPedFormationComponent::_TypeUID);
      }
      v6 = (UFG::GetInPedFormationComponent *)v7;
    }
    if ( v6 )
    {
      v8 = 0i64;
      value_uid = 0i64;
      v9 = *(_QWORD *)&v3->m_TargetType.mValue;
      if ( v9 )
        v10 = (UFG::ActionTreeComponentBase *)(&v3->m_TargetType.mValue + v9);
      else
        v10 = 0i64;
      if ( v9 )
        v11 = (signed __int64)(&v3->m_TargetType + v9);
      else
        v11 = 0i64;
      v12 = v2->mActionTreeComponentBase[*(char *)(v11 + 236)];
      if ( !v12 )
        v12 = v2->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInPedFormationNode *>(
        v12,
        v10,
        (ActionNodeRoot *)HIDWORD(v3->vfptr),
        (__int64)&value_uid);
      v13 = value_uid;
      if ( value_uid )
      {
        value_uid->m_Registrator = 0i64;
        UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(v13);
        v13->m_SlotIndex = -1;
        v18 = &v13->m_pTargetPedFormationManagerComponent;
        if ( v13->m_pTargetPedFormationManagerComponent.m_pPointer )
        {
          v19 = v18->mPrev;
          v20 = v13->m_pTargetPedFormationManagerComponent.mNext;
          v19->mNext = v20;
          v20->mPrev = v19;
          v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
          v13->m_pTargetPedFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->m_pTargetPedFormationManagerComponent.mPrev;
        }
        v13->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
      }
      else
      {
        if ( !(_S25 & 1) )
        {
          _S25 |= 1u;
          name_uid_0 = UFG::qStringHash32("GetInPedFormationComponent", 0xFFFFFFFF);
        }
        v14 = UFG::GetInPedFormationComponent::MakeNewNode(v6);
        v15 = *(_QWORD *)&v3->m_TargetType.mValue;
        if ( v15 )
          v16 = (UFG::ActionTreeComponentBase *)(&v3->m_TargetType.mValue + v15);
        else
          v16 = 0i64;
        if ( v15 )
          v8 = (signed __int64)(&v3->m_TargetType + v15);
        v17 = v2->mActionTreeComponentBase[*(char *)(v8 + 236)];
        if ( !v17 )
          v17 = v2->mActionTreeComponentBase[1];
        UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::GetInPedFormationNode *>(
          v17,
          v16,
          (ActionNodeRoot *)HIDWORD(v3->vfptr),
          (__int64)v14);
      }
    }
  }
}

// File Line: 3159
// RVA: 0x36FEC0
bool __fastcall GetInPedFormationCondition::Match(GetInPedFormationCondition *this, ActionContext *context)
{
  __int64 v2; // rax
  ActionContext *v3; // rdi
  GetInPedFormationCondition *v4; // rbp
  UFG::ActionTreeComponentBase *v5; // rdx
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v11; // rax
  void *(__fastcall *v12)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  __int64 v13; // rdx
  UFG::SimObjectGame *v14; // rcx
  __int64 v15; // rdx
  unsigned __int16 v16; // dx
  UFG::PedFormationManagerComponent *v17; // rbx
  UFG::SimComponent *v18; // rax
  UFG::GetInPedFormationNode *v19; // rcx
  UFG::PedFormationManagerComponent *v20; // rax
  __int64 v21; // rcx
  UFG::SimComponent *v23; // rax
  UFG::SimObject *v24; // rcx
  UFG::GetInPedFormationNode *value_uid; // [rsp+30h] [rbp+8h]

  v2 = this->m_MyRoot.mOffset;
  v3 = context;
  v4 = this;
  value_uid = 0i64;
  if ( v2 )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v5 = 0i64;
  if ( v2 )
    v6 = (char *)&this->m_MyRoot + v2;
  else
    v6 = 0i64;
  v7 = v3->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInPedFormationNode *>(
    v7,
    v5,
    (ActionNodeRoot *)v4->m_GetInPedFormationNodeUID,
    (__int64)&value_uid);
  if ( !value_uid )
    return 0;
  v8 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( !v8 )
    goto LABEL_63;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  if ( !v10 )
    goto LABEL_63;
  v11 = UFG::GroupComponent::GetGroupComponent(v3->mSimObject.m_pPointer);
  if ( !v11 )
    goto LABEL_63;
  v12 = v11[32].__vecDelDtor;
  if ( !v12 )
    goto LABEL_63;
  v13 = *((_QWORD *)v12 + 33);
  v14 = 0i64;
  if ( v13 )
    v14 = *(UFG::SimObjectGame **)(v13 + 192);
  if ( (v15 = *((_QWORD *)v12 + 28), !v14)
    || !v15
    || !*(_BYTE *)(v15 + 928)
    || ((v16 = v14->m_Flags, !((v16 >> 14) & 1)) ? ((v16 & 0x8000u) == 0 ? (!((v16 >> 13) & 1) ? (!((v16 >> 12) & 1) ? (v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::PedFormationManagerComponent::_TypeUID)) : (v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::PedFormationManagerComponent::_TypeUID))) : (v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::PedFormationManagerComponent::_TypeUID))) : (v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::PedFormationManagerComponent::_TypeUID)),
                                                    v17 = (UFG::PedFormationManagerComponent *)v18) : (v17 = (UFG::PedFormationManagerComponent *)v14->m_Components.p[33].m_pComponent),
        !v17) )
  {
LABEL_63:
    v19 = value_uid;
    goto LABEL_59;
  }
  v19 = value_uid;
  if ( !value_uid )
  {
LABEL_59:
    UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(v19);
    return 0;
  }
  v20 = (UFG::PedFormationManagerComponent *)value_uid->m_pTargetPedFormationManagerComponent.m_pPointer;
  if ( v20 && v17 != v20 )
    UFG::GetInPedFormationNode::UnregisterFromPedFormationManager(value_uid);
  if ( GetInPedFormationCondition::CanGetInPedFormation(v4, v3) )
  {
    if ( !value_uid )
      goto LABEL_64;
    v21 = (unsigned int)value_uid->m_SlotIndex;
    if ( (_DWORD)v21 == -1 )
      goto LABEL_64;
    if ( (unsigned int)v21 < v17->m_Slots.size && v17->m_Slots.p[v21].m_pMember.m_pPointer == value_uid )
    {
      UFG::GetInPedFormationNode::SetTargetPedFormationManagerComponent(value_uid, v17);
      return UFG::PedFormationManagerComponent::IsInPedFormation(v17, value_uid) == 0;
    }
    if ( (_DWORD)v21 == -1
      || (unsigned int)v21 >= v17->m_Slots.size
      || v17->m_Slots.p[v21].m_pMember.m_pPointer != value_uid )
    {
LABEL_64:
      if ( v17->m_pTransformNodeComponent.m_pSimComponent )
      {
        v23 = value_uid->m_pOwner.m_pPointer;
        if ( v23 )
        {
          v24 = v23->m_pSimObject;
          if ( v24 )
          {
            if ( v24->m_pTransformNodeComponent )
            {
              if ( v17->m_NumFreeSlots > 0 )
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
void __fastcall AIIsStandingBetweenAttackerAndTarget::AIIsStandingBetweenAttackerAndTarget(AIIsStandingBetweenAttackerAndTarget *this)
{
  AIIsStandingBetweenAttackerAndTarget *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIIsStandingBetweenAttackerAndTarget::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
  v1->m_MaxDistance = 8.0;
  v1->m_MaxAngle = 0.89999998;
}

// File Line: 3284
// RVA: 0x36E750
char __fastcall AIIsStandingBetweenAttackerAndTarget::Match(AIIsStandingBetweenAttackerAndTarget *this, ActionContext *context)
{
  AIIsStandingBetweenAttackerAndTarget *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbp
  unsigned __int16 v5; // r8
  __int64 v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rbx
  unsigned __int16 v9; // cx
  UFG::AttackRightsComponent *v10; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v11; // rax
  UFG::TransformNodeComponent *v12; // rdi
  void *(__fastcall *v13)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::SimObject *v14; // rax
  UFG::SimObject *v15; // rcx
  UFG::TransformNodeComponent *v16; // rbp
  UFG::TransformNodeComponent *v17; // rbx
  float v18; // xmm12_4
  float v19; // xmm13_4
  float v20; // xmm14_4
  float v21; // xmm8_4
  __m128 v22; // xmm9
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
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    goto LABEL_48;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = (__int64)v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = (__int64)v7;
  }
  else
  {
    v6 = (__int64)v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    goto LABEL_48;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                   + *(_QWORD *)(v6 + 96)
                                                   + 8i64)
                              + *(_QWORD *)(v6 + 88)
                              + 40);
  if ( !v8 )
    goto LABEL_48;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::AttackRightsComponent *)v8->m_Components.p[46].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v8,
                                            UFG::AttackRightsComponent::_TypeUID);
    else
      v10 = (UFG::AttackRightsComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v8,
                                                              UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::AttackRightsComponent::_TypeUID));
  }
  else
  {
    v10 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v8,
                                          UFG::AttackRightsComponent::_TypeUID);
  }
  if ( !v10 )
    goto LABEL_48;
  v11 = UFG::AttackRightsComponent::GetNextAttacker(v10, (UFG::eAttackType)(unsigned __int8)v2->m_AttackType.mValue, v6);
  v12 = 0i64;
  if ( v11 && (v13 = v11[27].__vecDelDtor) != 0i64 )
    v14 = (UFG::SimObject *)*((_QWORD *)v13 + 5);
  else
    v14 = 0i64;
  if ( !v14 )
    goto LABEL_48;
  v15 = v4->mSimObject.m_pPointer;
  if ( v14 == v15 )
    goto LABEL_48;
  if ( v15 )
    v12 = v15->m_pTransformNodeComponent;
  v16 = v14->m_pTransformNodeComponent;
  v17 = v8->m_pTransformNodeComponent;
  if ( !v12 )
    goto LABEL_48;
  if ( !v16 )
    goto LABEL_48;
  if ( !v17 )
    goto LABEL_48;
  UFG::TransformNodeComponent::UpdateWorldTransform(v12);
  UFG::TransformNodeComponent::UpdateWorldTransform(v16);
  UFG::TransformNodeComponent::UpdateWorldTransform(v17);
  v18 = v16->mWorldTransform.v3.x;
  v19 = v16->mWorldTransform.v3.y;
  v20 = v16->mWorldTransform.v3.z;
  v21 = v12->mWorldTransform.v3.x;
  v22 = (__m128)LODWORD(v12->mWorldTransform.v3.y);
  v23 = v17->mWorldTransform.v3.x;
  v24 = (__m128)LODWORD(v17->mWorldTransform.v3.y);
  v25 = v12->mWorldTransform.v3.z;
  v26 = v17->mWorldTransform.v3.z;
  v27 = (float)((float)((float)(v16->mWorldTransform.v3.y - v24.m128_f32[0])
                      * (float)(v16->mWorldTransform.v3.y - v24.m128_f32[0]))
              + (float)((float)(v16->mWorldTransform.v3.x - v23) * (float)(v16->mWorldTransform.v3.x - v23)))
      + (float)((float)(v16->mWorldTransform.v3.z - v26) * (float)(v16->mWorldTransform.v3.z - v26));
  if ( (float)((float)((float)((float)(v19 - v22.m128_f32[0]) * (float)(v19 - v22.m128_f32[0]))
                     + (float)((float)(v16->mWorldTransform.v3.x - v21) * (float)(v16->mWorldTransform.v3.x - v21)))
             + (float)((float)(v20 - v25) * (float)(v20 - v25))) > v27
    || v27 > (float)(v2->m_MaxDistance * v2->m_MaxDistance) )
  {
    goto LABEL_48;
  }
  v28 = v21 - v18;
  v22.m128_f32[0] = v22.m128_f32[0] - v19;
  v30 = v22;
  v29 = v25 - v20;
  v30.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v28 * v28)) + (float)(v29 * v29);
  v31 = v30.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
  v32 = v23 - v18;
  v24.m128_f32[0] = v24.m128_f32[0] - v19;
  v33 = v26 - v20;
  v34 = v28 * v31;
  v35 = v22.m128_f32[0] * v31;
  v36 = v29 * v31;
  v37 = v24;
  v37.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v32 * v32)) + (float)(v33 * v33);
  v38 = v37.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
  if ( (float)((float)((float)((float)(v24.m128_f32[0] * v38) * v35) + (float)((float)(v32 * v38) * v34))
             + (float)((float)(v33 * v38) * v36)) > v2->m_MaxAngle )
    result = 1;
  else
LABEL_48:
    result = 0;
  return result;
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
  return atexit(dynamic_atexit_destructor_for__gNextAttackerWeaponTypeEnum__);
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
  NextAttackerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&NextAttackerCondition::`vftable';
  v1->m_WeaponType.mValue = 0;
}

// File Line: 3388
// RVA: 0x371380
char __fastcall NextAttackerCondition::Match(NextAttackerCondition *this, ActionContext *context)
{
  NextAttackerCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rdx
  char v9; // bl
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::SimObjectProp *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::SimObjectWeaponPropertiesComponent *v13; // rax
  bool v14; // si
  bool v15; // al
  char v16; // cl

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[46].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AttackRightsComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AttackRightsComponent::_TypeUID);
  }
  else
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AttackRightsComponent::_TypeUID);
  }
  if ( !v5 )
    return 0;
  v6 = v5[160].m_SafePointerList.mNode.mPrev;
  if ( !v6 )
    return 0;
  if ( !v2->m_WeaponType.mValue )
    return 1;
  v8 = v6[13].mNext;
  v9 = 0;
  if ( v8 )
    v10 = v8[9].mNext;
  else
    v10 = 0i64;
  v11 = (UFG::SimObjectProp *)*((_QWORD *)&v10[5].mNext[2].mNext + 7 * BYTE1(v10[6].mPrev[1].mNext));
  if ( !v11 )
    return v2->m_WeaponType.mValue == 1;
  v12 = v11->m_Flags;
  if ( (v12 >> 14) & 1 )
  {
    v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v11->vfptr,
                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  }
  else if ( (v12 & 0x8000u) == 0 )
  {
    if ( (v12 >> 13) & 1 )
      v13 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v11);
    else
      v13 = (UFG::SimObjectWeaponPropertiesComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            (UFG::SimObjectGame *)&v11->vfptr,
                                                                            UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
  }
  else
  {
    v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v11->vfptr,
                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  }
  if ( !v13 )
    return v2->m_WeaponType.mValue == 1;
  v14 = v13->mIsBladed;
  v15 = v13->mWeaponTypeInfo->mFireModes[v13->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID
     && UFG::SimObjectWeaponPropertiesComponent::HasAmmo(v13);
  v16 = v2->m_WeaponType.mValue;
  if ( v16 == 2 && v14 || v16 == 3 && v15 )
    v9 = 1;
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
  return atexit(dynamic_atexit_destructor_for__gCanAttackConditionFactory__);
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
  IsNextAttackerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsNextAttackerCondition::`vftable';
  *(_WORD *)&v1->m_AttackType.mValue = 5632;
}

// File Line: 3482
// RVA: 0x338FD0
void __fastcall IsNextAttackerCondition::~IsNextAttackerCondition(IsNextAttackerCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNextAttackerCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 3492
// RVA: 0x359E20
UFG::SimComponent *__fastcall IsNextAttackerCondition::GetAttackTarget(IsNextAttackerCondition *this, ActionContext *context)
{
  IsNextAttackerCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // r9
  unsigned __int16 v7; // cx
  unsigned int v9; // edx
  UFG::SimObjectGame *v10; // rcx
  bool v11; // zf

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v6 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                   + *(_QWORD *)&v5[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
          return v6->m_Components.p[46].m_pComponent;
        if ( (v7 & 0x8000u) != 0 || (v7 >> 13) & 1 )
        {
          v9 = UFG::AttackRightsComponent::_TypeUID;
          v10 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                            + *(_QWORD *)&v5[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v5[1].m_TypeUID
                                       + 40);
        }
        else
        {
          v9 = UFG::AttackRightsComponent::_TypeUID;
          v11 = ((v7 >> 12) & 1) == 0;
          v10 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                            + *(_QWORD *)&v5[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v5[1].m_TypeUID
                                       + 40);
          if ( v11 )
            return UFG::SimObject::GetComponentOfType(v6, UFG::AttackRightsComponent::_TypeUID);
        }
        return UFG::SimObjectGame::GetComponentOfTypeHK(v10, v9);
      }
    }
  }
  return 0i64;
}

// File Line: 3511
// RVA: 0x370FD0
UFG::AttackRightsComponent *__fastcall IsNextAttackerCondition::Match(IsNextAttackerCondition *this, ActionContext *context)
{
  ActionContext *v2; // rbx
  IsNextAttackerCondition *v3; // rdi
  UFG::AttackRightsComponent *result; // rax
  __int64 v5; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v6; // rcx
  void *(__fastcall *v7)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  UFG::SimObject *v8; // rcx

  v2 = context;
  v3 = this;
  result = (UFG::AttackRightsComponent *)IsNextAttackerCondition::GetAttackTarget(this, context);
  if ( result )
  {
    v6 = UFG::AttackRightsComponent::GetNextAttacker(
           result,
           (UFG::eAttackType)(unsigned __int8)v3->m_AttackType.mValue,
           v5);
    result = 0i64;
    if ( v6 )
    {
      v7 = v6[27].__vecDelDtor;
      if ( v7 )
        v8 = (UFG::SimObject *)*((_QWORD *)v7 + 5);
      else
        v8 = 0i64;
      if ( v8 == v2->mSimObject.m_pPointer )
        result = (UFG::AttackRightsComponent *)1;
    }
  }
  return result;
}

// File Line: 3543
// RVA: 0x350CA0
ConditionGroup *__fastcall CanAttackConditionGroup::CreateClone(CanAttackConditionGroup *this)
{
  CanAttackConditionGroup *v1; // rdi
  char *v2; // rax
  ConditionGroup *v3; // rax
  ConditionGroup *v4; // rbx

  v1 = this;
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
  ConditionGroup::CopyFrom(v4, (ConditionGroup *)&v1->vfptr);
  return v4;
}

// File Line: 3562
// RVA: 0x14B2FB0
__int64 dynamic_initializer_for__gInCoverTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gInCoverTypeEnum, UFG::InCoverTypeNames, 2, 0i64);
  return atexit(dynamic_atexit_destructor_for__gInCoverTypeEnum__);
}

// File Line: 3563
// RVA: 0x14B2EF0
__int64 dynamic_initializer_for__gAttackerTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gAttackerTypeEnum, UFG::AttackerTypeNames, 2, 0i64);
  return atexit(dynamic_atexit_destructor_for__gAttackerTypeEnum__);
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
  HasAttackRequestCondition *v1; // rbx
  IConditionInit *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rax
  char *v4; // rax
  __int64 v5; // rax
  UFG::qOffset64<CanAttackConditionGroup *> *v6; // rcx
  __int64 v7; // rax
  signed __int64 v8; // [rsp+58h] [rbp+10h]

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v2 = (IConditionInit *)&v1->vfptr;
  v3 = (UFG::qNode<IConditionInit,IConditionInit> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HasAttackRequestCondition::`vftable'{for `Condition'};
  v2->vfptr = (IConditionInitVtbl *)&HasAttackRequestCondition::`vftable'{for `IConditionInit'};
  *(_DWORD *)&v1->m_AttackType.mValue = 1441792;
  v1->m_CopySecondaryCharacterToTargetType.mValue = 37;
  v8 = (signed __int64)&v1->m_ActionPath;
  *(_DWORD *)v8 = 0;
  *(_QWORD *)(v8 + 8) = 0i64;
  v1->m_MyRoot.mOffset = 0i64;
  v1->m_TimeoutToBeginAttacking = 1.0;
  v1->m_HasAttackRequestNodeUID = 0;
  v4 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x48ui64,
         "HasAttackRequestCondition.m_CanAttackConditions",
         0i64,
         1u);
  if ( v4 )
    CanAttackConditionGroup::CanAttackConditionGroup((CanAttackConditionGroup *)v4);
  else
    v5 = 0i64;
  v6 = &v1->m_pCanAttackConditions;
  if ( v5 )
    v7 = v5 - (_QWORD)v6;
  else
    v7 = 0i64;
  v6->mOffset = v7;
}

// File Line: 3604
// RVA: 0x3382B0
void __fastcall HasAttackRequestCondition::~HasAttackRequestCondition(HasAttackRequestCondition *this)
{
  HasAttackRequestCondition *v1; // rdi
  IConditionInit *v2; // rsi
  __int64 v3; // rax
  char *v4; // rcx
  ActionPath *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  char *v8; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v9; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v10; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v11; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&HasAttackRequestCondition::`vftable'{for `Condition'};
  v2 = (IConditionInit *)&this->vfptr;
  this->vfptr = (IConditionInitVtbl *)&HasAttackRequestCondition::`vftable'{for `IConditionInit'};
  v3 = this->m_pCanAttackConditions.mOffset;
  if ( v3 )
  {
    v4 = (char *)&this->m_pCanAttackConditions + v3;
    if ( v4 )
      (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
  }
  v1->m_pCanAttackConditions.mOffset = 0i64;
  v5 = &v1->m_ActionPath;
  if ( v1->m_ActionPath.mPath.mCount >= 0 )
  {
    v6 = v1->m_ActionPath.mPath.mData.mOffset;
    if ( v6 && (UFG::qOffset64<ActionID *> *)((char *)&v5->mPath.mData + v6) )
    {
      v7 = v1->m_ActionPath.mPath.mData.mOffset;
      if ( v7 )
        v8 = (char *)&v1->m_ActionPath.mPath.mData + v7;
      else
        v8 = 0i64;
      operator delete[](v8);
    }
    v1->m_ActionPath.mPath.mData.mOffset = 0i64;
    v5->mPath.mCount &= 0x80000000;
  }
  v9 = (UFG::qNode<IConditionInit,IConditionInit> *)&v2->mPrev;
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 3615
// RVA: 0x350D10
HasAttackRequestCondition *__fastcall HasAttackRequestCondition::CreateClone(HasAttackRequestCondition *this)
{
  HasAttackRequestCondition *v1; // rdi
  char *v2; // rax
  HasAttackRequestCondition *v3; // rax
  HasAttackRequestCondition *v4; // rbx
  __int64 v5; // rax
  signed __int64 v6; // rcx
  __int64 v7; // rax
  signed __int64 v8; // rcx

  v1 = this;
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
  HasAttackRequestCondition::operator=(v4, v1);
  v5 = v1->m_pCanAttackConditions.mOffset;
  if ( v5 && (v6 = (signed __int64)&v1->m_pCanAttackConditions + v5) != 0 )
  {
    v7 = (*(__int64 (**)(void))(*(_QWORD *)v6 + 16i64))();
    v8 = (signed __int64)&v4->m_pCanAttackConditions;
    if ( v7 )
      v7 -= v8;
    *(_QWORD *)v8 = v7;
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
  __int64 v2; // rax
  ActionNode *v3; // rsi
  HasAttackRequestCondition *v4; // rbp
  char *v5; // rdi
  unsigned int v6; // ebx
  signed __int64 v7; // r14
  signed __int64 v8; // rcx
  ActionNodeRoot *v9; // rbx
  __int64 v10; // rax
  UFG::qOffset64<ActionNodeRoot *> *v11; // rcx
  __int64 v12; // rax
  hkSeekableStreamReader *v13; // rax
  hkSeekableStreamReader *v14; // [rsp+20h] [rbp-28h]
  void (__fastcall *v15)(HasAttackRequestCondition *, ActionNode *, ActionContext *); // [rsp+28h] [rbp-20h]

  v2 = this->m_pCanAttackConditions.mOffset;
  v3 = action_node;
  v4 = this;
  if ( v2 )
  {
    v5 = (char *)&this->m_pCanAttackConditions + v2;
    if ( v5 )
    {
      v6 = 0;
      v7 = (signed __int64)&v5[*((_QWORD *)v5 + 5) + 40];
      if ( *((_DWORD *)v5 + 8) & 0x7FFFFFFF )
      {
        do
        {
          v8 = *(_QWORD *)(v7 + 8i64 * v6) + v7 + 8i64 * v6;
          (*(void (__fastcall **)(signed __int64, ActionNode *))(*(_QWORD *)v8 + 120i64))(v8, v3);
          ++v6;
        }
        while ( v6 < (*((_DWORD *)v5 + 8) & 0x7FFFFFFFu) );
      }
    }
  }
  v9 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))v3->vfptr[1].SetResourceOwner)(v3);
  ActionNodeRoot::AddToInitList(v9, (IConditionInit *)&v4->vfptr);
  v10 = (__int64)v9->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v9->vfptr);
  v11 = &v4->m_MyRoot;
  if ( v10 )
    v12 = v10 - (_QWORD)v11;
  else
    v12 = 0i64;
  v11->mOffset = v12;
  v15 = HasAttackRequestCondition::OnMyEnterCallback;
  v14 = Assembly::GetRCX(v4);
  ActionNode::AddOnEnterCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v14);
  v13 = Assembly::GetRCX(v4);
  v15 = HasAttackRequestCondition::OnMyExitCallback;
  v14 = v13;
  ActionNode::AddOnExitCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v14);
  v4->m_HasAttackRequestNodeUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                    v4->m_HasAttackRequestNodeUID,
                                    eACTION_TREE_MEMORY_ELEMENT_HAS_ATTACK_REQUEST_NODE_POINTER);
}

// File Line: 3700
// RVA: 0x377AC0
UFG::HasAttackRequestNode *__fastcall HasAttackRequestCondition::ObtainHasAttackRequestNode(HasAttackRequestCondition *this, ActionContext *action_context)
{
  ActionContext *v2; // rsi
  HasAttackRequestCondition *v3; // rbp
  signed __int64 v4; // rdi
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // r8
  UFG::HasAttackRequestComponent *v7; // rbx
  UFG::SimComponent *v8; // rax
  __int64 v9; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  signed __int64 v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  UFG::HasAttackRequestNode *result; // rax
  UFG::HasAttackRequestNode *v14; // r9
  __int64 v15; // rcx
  UFG::ActionTreeComponentBase *v16; // rdx
  UFG::ActionTreeComponentBase *v17; // rcx
  UFG::HasAttackRequestNode *value_uid; // [rsp+48h] [rbp+10h]

  v2 = action_context;
  v3 = this;
  v4 = 0i64;
  value_uid = 0i64;
  v5 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !v5 )
    return value_uid;
  v6 = v5->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = (UFG::HasAttackRequestComponent *)v5->m_Components.p[35].m_pComponent;
  }
  else
  {
    if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::HasAttackRequestComponent::_TypeUID);
      else
        v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::HasAttackRequestComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::HasAttackRequestComponent::_TypeUID);
    }
    else
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::HasAttackRequestComponent::_TypeUID);
    }
    v7 = (UFG::HasAttackRequestComponent *)v8;
  }
  if ( !v7 )
    return value_uid;
  v9 = v3->m_MyRoot.mOffset;
  if ( v9 )
    v10 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v9);
  else
    v10 = 0i64;
  if ( v9 )
    v11 = (signed __int64)&v3->m_MyRoot + v9;
  else
    v11 = 0i64;
  v12 = v2->mActionTreeComponentBase[*(char *)(v11 + 236)];
  if ( !v12 )
    v12 = v2->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::HasAttackRequestNode *>(
    v12,
    v10,
    (ActionNodeRoot *)v3->m_HasAttackRequestNodeUID,
    (__int64)&value_uid);
  result = value_uid;
  if ( !value_uid )
  {
    if ( !(_S26_0 & 1) )
    {
      _S26_0 |= 1u;
      name_uid_1 = UFG::qStringHash32("HasAttackRequestNode", 0xFFFFFFFF);
    }
    v14 = UFG::HasAttackRequestComponent::MakeNewNode(v7, v2, v3);
    value_uid = v14;
    v15 = v3->m_MyRoot.mOffset;
    if ( v15 )
      v16 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v15);
    else
      v16 = 0i64;
    if ( v15 )
      v4 = (signed __int64)&v3->m_MyRoot + v15;
    v17 = v2->mActionTreeComponentBase[*(char *)(v4 + 236)];
    if ( !v17 )
      v17 = v2->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::HasAttackRequestNode *>(
      v17,
      v16,
      (ActionNodeRoot *)v3->m_HasAttackRequestNodeUID,
      (__int64)v14);
    return value_uid;
  }
  return result;
}

// File Line: 3731
// RVA: 0x366090
void __fastcall HasAttackRequestCondition::Init(HasAttackRequestCondition *this, ActionContext *action_context)
{
  HasAttackRequestCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rdx
  UFG::ActionTreeComponentBase *v10; // rcx
  UFG::HasAttackRequestNode *value_uid; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v4 = action_context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[35].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID);
      else
        v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HasAttackRequestComponent::_TypeUID);
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID);
    }
    if ( v6 )
    {
      v7 = *(_QWORD *)&v2->m_HasAttackRequestNodeUID;
      v8 = 0i64;
      value_uid = 0i64;
      if ( v7 )
        v9 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_HasAttackRequestNodeUID + v7);
      else
        v9 = 0i64;
      if ( v7 )
        v8 = (signed __int64)&v2->m_HasAttackRequestNodeUID + v7;
      v10 = v4->mActionTreeComponentBase[*(char *)(v8 + 236)];
      if ( !v10 )
        v10 = v4->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::HasAttackRequestNode *>(
        v10,
        v9,
        (ActionNodeRoot *)*(unsigned int *)&v2->m_AttackType.mValue,
        (__int64)&value_uid);
      if ( value_uid )
        UFG::HasAttackRequestNode::ReInit(value_uid, v4, (HasAttackRequestCondition *)((char *)v2 - 24));
    }
  }
}

// File Line: 3758
// RVA: 0x37B5F0
void __fastcall HasAttackRequestCondition::OnMyEnterCallback(HasAttackRequestCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  UFG::HasAttackRequestNode *v3; // rax

  v3 = HasAttackRequestCondition::ObtainHasAttackRequestNode(this, action_context);
  if ( v3 )
    v3->m_CurrentlyAttacking = 1;
}

// File Line: 3772
// RVA: 0x37B750
void __fastcall HasAttackRequestCondition::OnMyExitCallback(HasAttackRequestCondition *this, ActionNode *action_node, ActionContext *action_context)
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
UFG::SimComponent *__fastcall HasAttackRequestCondition::GetAttackTarget(HasAttackRequestCondition *this, ActionContext *action_context)
{
  HasAttackRequestCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // r9
  unsigned __int16 v7; // cx
  unsigned int v9; // edx
  UFG::SimObjectGame *v10; // rcx
  bool v11; // zf

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v6 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                   + *(_QWORD *)&v5[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
          return v6->m_Components.p[46].m_pComponent;
        if ( (v7 & 0x8000u) != 0 || (v7 >> 13) & 1 )
        {
          v9 = UFG::AttackRightsComponent::_TypeUID;
          v10 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                            + *(_QWORD *)&v5[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v5[1].m_TypeUID
                                       + 40);
        }
        else
        {
          v9 = UFG::AttackRightsComponent::_TypeUID;
          v11 = ((v7 >> 12) & 1) == 0;
          v10 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                            + *(_QWORD *)&v5[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v5[1].m_TypeUID
                                       + 40);
          if ( v11 )
            return UFG::SimObject::GetComponentOfType(v6, UFG::AttackRightsComponent::_TypeUID);
        }
        return UFG::SimObjectGame::GetComponentOfTypeHK(v10, v9);
      }
    }
  }
  return 0i64;
}

// File Line: 3816
// RVA: 0x370360
char __fastcall HasAttackRequestCondition::Match(HasAttackRequestCondition *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  HasAttackRequestCondition *v3; // rdi
  __int64 v4; // rax
  char *v5; // rcx
  char result; // al
  UFG::HasAttackRequestNode *v7; // rax
  UFG::HasAttackRequestNode *v8; // rbx
  CanAttackConditionGroup *v9; // rcx
  char v10; // al
  float v11; // xmm6_4
  UFG::SimComponent *v12; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::AttackRightsComponent *v16; // rax
  char v17; // cl

  v2 = context;
  v3 = this;
  if ( UFG::AttackRightsComponent::s_DisableRangedAttackRights && this->m_AttackType.mValue == 1 )
  {
    v4 = this->m_pCanAttackConditions.mOffset;
    if ( !v4
      || (v5 = (char *)&this->m_pCanAttackConditions + v4) == 0i64
      || (result = (*(__int64 (**)(void))(*(_QWORD *)v5 + 80i64))()) != 0 )
    {
      result = 1;
    }
  }
  else
  {
    v7 = HasAttackRequestCondition::ObtainHasAttackRequestNode(this, context);
    v8 = v7;
    if ( v7 )
    {
      v7->m_LastTimePolled = UFG::Metrics::msInstance.mSimTime_Temp;
      v7->m_LastFramePolled = UFG::Metrics::msInstance.mSimFrameCount;
      v9 = v7->m_pCanAttackConditions.m_pPointer;
      v10 = 0;
      v11 = UFG::Metrics::msInstance.mSimTime_Temp;
      if ( v9 && v8->m_pActionContextCopy )
        v10 = ((__int64 (*)(void))v9->vfptr[1].FindWithOldPath)();
      v12 = v8->m_pAttackeeRequest.m_pPointer;
      if ( v12
        && (UFG::HasAttackRequestNode *)(&v12->vfptr)[3
                                                    * ((signed int)UFG::AttackRightsComponent::s_AttackTypeToDebug
                                                     + 428i64)] == v8 )
      {
        if ( (float)(v11 - v8->m_AttackeeRequestTime) < v3->m_TimeoutToBeginAttacking || v10 )
          return 1;
        UFG::HasAttackRequestNode::FinishedAttacking(v8);
      }
      else
      {
        v13 = &v8->m_pAttackeeRequest;
        if ( v8->m_pAttackeeRequest.m_pPointer )
        {
          v14 = v13->mPrev;
          v15 = v8->m_pAttackeeRequest.mNext;
          v14->mNext = v15;
          v15->mPrev = v14;
          v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
          v8->m_pAttackeeRequest.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->m_pAttackeeRequest.mPrev;
        }
        v8->m_pAttackeeRequest.m_pPointer = 0i64;
        v16 = (UFG::AttackRightsComponent *)HasAttackRequestCondition::GetAttackTarget(v3, v2);
        v17 = v3->m_AttackerType.mValue;
        if ( v17 )
        {
          if ( v16 && v17 == 1 )
            UFG::AttackRightsComponent::AddToFollowerAttackSlotQueue(v16, v8);
        }
        else if ( v16 )
        {
          UFG::AttackRightsComponent::RequestAttackSlot(v16, v8);
        }
      }
    }
    result = 0;
  }
  return result;
}

// File Line: 3906
// RVA: 0x384B50
void __fastcall HasAttackRequestCondition::Serialize(HasAttackRequestCondition *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  IActionTreeSerializer *v3; // r8
  Expression::IMemberMap *v4; // rdx

  v2 = this->m_pCanAttackConditions.mOffset;
  v3 = serializer;
  if ( v2 )
  {
    v4 = (Expression::IMemberMap *)((char *)&this->m_pCanAttackConditions + v2);
    if ( v4 )
      IActionTreeSerializer::PushObjectToSerialize(v3, v4);
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
  IsAtRangePreferenceCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsAtRangePreferenceCondition::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
}

// File Line: 3948
// RVA: 0x338ED0
void __fastcall IsAtRangePreferenceCondition::~IsAtRangePreferenceCondition(IsAtRangePreferenceCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsAtRangePreferenceCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 3953
// RVA: 0x3707F0
char __fastcall IsAtRangePreferenceCondition::Match(IsAtRangePreferenceCondition *this, ActionContext *context)
{
  IsAtRangePreferenceCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::FormationManagerComponent *v10; // rax
  UFG::FormationManagerComponent *v11; // rbx
  int v12; // eax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                   + *(_QWORD *)&v6[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&v6[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v8,
                                              UFG::FormationManagerComponent::_TypeUID);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v8,
                                                UFG::FormationManagerComponent::_TypeUID);
    else
      v10 = (UFG::FormationManagerComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v8,
                                                                  UFG::FormationManagerComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::FormationManagerComponent::_TypeUID));
  }
  else
  {
    v10 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v8,
                                              UFG::FormationManagerComponent::_TypeUID);
  }
  v11 = v10;
  if ( !v10 )
    return 0;
  v12 = UFG::FormationManagerComponent::FindRangeIndex(v10, v4->mSimObject.m_pPointer);
  if ( v12 == -1 )
    return 0;
  if ( v2->m_RangePreference.mValue )
  {
    switch ( v2->m_RangePreference.mValue )
    {
      case 1:
        return v12 == 0;
      case 2:
        return v12 == v11->m_NumRanges - 2;
      case 3:
        return v12 != 0;
    }
    if ( v2->m_RangePreference.mValue != 4 )
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
  TimeoutCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TimeoutCondition::`vftable';
  *(_QWORD *)&v1->m_TimeoutTimeUID = 0i64;
  v1->m_MaxTimeUntilTimeout = 0.0;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 4002
// RVA: 0x383D20
void __fastcall TimeoutCondition::ResolveReferences(TimeoutCondition *this, ActionNode *action_node)
{
  TimeoutCondition *v2; // rbx
  ActionNode *v3; // rdi
  Expression::IMemberMap *v4; // rax
  signed __int64 v5; // rcx
  __int64 v6; // rax
  ActionNode *v7; // rcx
  TimeoutCondition *v8; // [rsp+20h] [rbp-18h]
  void (__fastcall *v9)(CooldownCondition *, ActionNode *, ActionContext *, unsigned int); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = action_node;
  v4 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v5 = (signed __int64)&v2->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - v5);
  *(_QWORD *)v5 = v4;
  v8 = v2;
  v9 = CooldownCondition::OnMyExitCallback;
  ActionNode::AddOnEnterCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v8);
  v6 = v3->mParent.mOffset;
  if ( v6 )
  {
    v7 = (ActionNode *)((char *)v3 + v6 + 16);
    if ( v7 )
    {
      v8 = v2;
      v9 = (void (__fastcall *)(CooldownCondition *, ActionNode *, ActionContext *, unsigned int))TimeoutCondition::OnParentExitCallback;
      ActionNode::AddOnExitCallback(v7, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v8);
    }
  }
  v2->m_TimeoutTimeUID = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_TimeoutTimeUID, 0);
}

// File Line: 4027
// RVA: 0x37B660
void __fastcall CooldownCondition::OnMyExitCallback(CooldownCondition *this, ActionNode *action_node, ActionContext *action_context, unsigned int a4)
{
  float v4; // xmm6_4
  float v5; // xmm7_4
  ActionContext *v6; // rdi
  CooldownCondition *v7; // rbx
  float v8; // xmm8_4
  float v9; // xmm0_4
  __int64 v10; // rax
  signed __int64 v11; // rcx
  int v12; // xmm0_4
  UFG::ActionTreeComponentBase *v13; // rdx
  UFG::ActionTreeComponentBase *v14; // rcx

  v4 = this->m_MaxTimeUntilCanEnterAgain;
  v5 = this->m_MinTimeUntilCanEnterAgain;
  v6 = action_context;
  v7 = this;
  v8 = UFG::Metrics::msInstance.mSimTime_Temp;
  v9 = this->m_MaxTimeUntilCanEnterAgain;
  if ( v4 > v5 )
  {
    v9 = UFG::qRandom(v9 - v5, &UFG::qDefaultSeed) + v5;
    if ( v9 <= v5 )
      v9 = v5;
    if ( v9 >= v4 )
      v9 = v4;
  }
  v10 = v7->m_MyRoot.mOffset;
  v11 = 0i64;
  *(float *)&v12 = v9 + v8;
  if ( v10 )
    v13 = (UFG::ActionTreeComponentBase *)((char *)&v7->m_MyRoot + v10);
  else
    v13 = 0i64;
  if ( v10 )
    v11 = (signed __int64)&v7->m_MyRoot + v10;
  v14 = v6->mActionTreeComponentBase[*(char *)(v11 + 236)];
  if ( !v14 )
    v14 = v6->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
    v14,
    v13,
    (ActionNodeRoot *)v7->m_NextTimeCanEnterUID,
    a4,
    v12);
}

// File Line: 4040
// RVA: 0x37BBB0
void __fastcall TimeoutCondition::OnParentExitCallback(TimeoutCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  __int64 v3; // rax
  TimeoutCondition *v4; // rdx
  signed __int64 v5; // rcx
  UFG::ActionTreeComponentBase *v6; // r9
  UFG::ActionTreeComponentBase *v7; // rcx

  v3 = this->m_MyRoot.mOffset;
  v4 = this;
  v5 = 0i64;
  if ( v3 )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v3);
  else
    v6 = 0i64;
  if ( v3 )
    v5 = (signed __int64)&v4->m_MyRoot + v3;
  v7 = action_context->mActionTreeComponentBase[*(char *)(v5 + 236)];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
    v7,
    v6,
    (ActionNodeRoot *)v4->m_TimeoutTimeUID,
    (unsigned int)v6,
    SLODWORD(FLOAT_3_4028235e38));
}

// File Line: 4049
// RVA: 0x374920
bool __fastcall TimeoutCondition::Match(TimeoutCondition *this, ActionContext *action_context)
{
  __int64 v2; // rax
  float v3; // xmm6_4
  TimeoutCondition *v4; // r8
  UFG::ActionTreeComponentBase *v5; // r10
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  unsigned int value_uid; // [rsp+40h] [rbp+8h]

  v2 = this->m_MyRoot.mOffset;
  v3 = UFG::Metrics::msInstance.mSimTime_Temp;
  v4 = this;
  *(float *)&value_uid = FLOAT_3_4028235e38;
  if ( v2 )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v5 = 0i64;
  if ( v2 )
    v6 = (char *)&this->m_MyRoot + v2;
  else
    v6 = 0i64;
  v7 = action_context->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v7,
    v5,
    (ActionNodeRoot *)v4->m_TimeoutTimeUID,
    (__int64)&value_uid);
  return *(float *)&value_uid > v3;
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
  RunningAttackCooldownCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&RunningAttackCooldownCondition::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->m_MyRoot.mOffset = 0i64;
  v1->m_HasBegunUID = 0;
}

// File Line: 4093
// RVA: 0x33A940
void __fastcall RunningAttackCooldownCondition::~RunningAttackCooldownCondition(RunningAttackCooldownCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&RunningAttackCooldownCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4098
// RVA: 0x3837D0
void __fastcall RunningAttackCooldownCondition::ResolveReferences(RunningAttackCooldownCondition *this, ActionNode *action_node)
{
  RunningAttackCooldownCondition *v2; // rbx
  ActionNode *v3; // rdi
  Expression::IMemberMap *v4; // rax
  signed __int64 v5; // rcx
  RunningAttackCooldownCondition *v6; // [rsp+20h] [rbp-18h]
  void (__fastcall *v7)(RunningAttackCooldownCondition *, ActionNode *, ActionContext *); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = action_node;
  v4 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v5 = (signed __int64)&v2->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - v5);
  *(_QWORD *)v5 = v4;
  v6 = v2;
  v7 = RunningAttackCooldownCondition::OnMyExitCallback;
  ActionNode::AddOnExitCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v6);
  v2->m_HasBegunUID = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_HasBegunUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 4115
// RVA: 0x37BA10
void __fastcall RunningAttackCooldownCondition::OnMyExitCallback(RunningAttackCooldownCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  __int64 v3; // rax
  RunningAttackCooldownCondition *v4; // rbx
  signed __int64 v5; // rcx
  ActionContext *v6; // rdi
  UFG::ActionTreeComponentBase *v7; // rdx
  UFG::ActionTreeComponentBase *v8; // rcx
  UFG::SimObject *v9; // r8
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // r8
  UFG::SimComponent *v12; // rax
  bool v13; // zf
  UFG::SimObjectGame *v14; // rcx
  UFG::SimObjectGame *v15; // r8
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  float v18; // xmm0_4

  v3 = this->m_MyRoot.mOffset;
  v4 = this;
  v5 = 0i64;
  v6 = action_context;
  if ( v3 )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v3);
  else
    v7 = 0i64;
  if ( v3 )
    v5 = (signed __int64)&v4->m_MyRoot + v3;
  v8 = action_context->mActionTreeComponentBase[*(char *)(v5 + 236)];
  if ( !v8 )
    v8 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v8, v7, (ActionNodeRoot *)v4->m_HasBegunUID, 0);
  v9 = v6->mSimObject.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = v9->m_Components.p[20].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)v6->mSimObject.m_pPointer,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v13 = ((v10 >> 12) & 1) == 0;
        v14 = (UFG::SimObjectGame *)v6->mSimObject.m_pPointer;
        if ( v13 )
          v12 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v14->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v11 = v12;
    }
    else
    {
      v11 = v9->m_Components.p[20].m_pComponent;
    }
    if ( v11 )
    {
      v15 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)((unsigned __int8)v4->m_TargetType.mValue
                                                        + *(_QWORD *)&v11[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v11[1].m_TypeUID
                                   + 40);
      if ( v15 )
      {
        v16 = v15->m_Flags;
        if ( (v16 >> 14) & 1 )
        {
          v17 = v15->m_Components.p[46].m_pComponent;
        }
        else if ( (v16 & 0x8000u) == 0 )
        {
          if ( (v16 >> 13) & 1 )
          {
            v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::AttackRightsComponent::_TypeUID);
          }
          else if ( (v16 >> 12) & 1 )
          {
            v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::AttackRightsComponent::_TypeUID);
          }
          else
          {
            v17 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v15->vfptr,
                    UFG::AttackRightsComponent::_TypeUID);
          }
        }
        else
        {
          v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::AttackRightsComponent::_TypeUID);
        }
        if ( v17 )
        {
          v18 = UFG::Metrics::msInstance.mSimTime_Temp;
          LOBYTE(v17[149].m_Flags) = 1;
          *(float *)&v17[149].m_NameUID = v18;
          *(float *)&v17[149].m_NameUID = UFG::Metrics::msInstance.mSimTime_Temp + 3.0;
        }
      }
    }
  }
}

// File Line: 4139
// RVA: 0x3721E0
char __fastcall RunningAttackCooldownCondition::Match(RunningAttackCooldownCondition *this, ActionContext *context)
{
  __int64 v2; // rax
  ActionContext *v3; // rbx
  char *v4; // rdx
  RunningAttackCooldownCondition *v5; // rdi
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // r8
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  float v15; // xmm0_4
  unsigned int value_uid; // [rsp+30h] [rbp+8h]

  v2 = this->m_MyRoot.mOffset;
  v3 = context;
  v4 = 0i64;
  v5 = this;
  LOBYTE(value_uid) = 0;
  if ( v2 )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v6 = 0i64;
  if ( v2 )
    v4 = (char *)&this->m_MyRoot + v2;
  v7 = v3->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v7,
    v6,
    (ActionNodeRoot *)v5->m_HasBegunUID,
    (__int64)&value_uid);
  if ( (_BYTE)value_uid )
    return 1;
  v8 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = v8->m_Components.p[20].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v10 = v11;
    }
    else
    {
      v10 = v8->m_Components.p[20].m_pComponent;
    }
    if ( v10 )
    {
      v12 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)((unsigned __int8)v5->m_TargetType.mValue
                                                        + *(_QWORD *)&v10[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v10[1].m_TypeUID
                                   + 40);
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = v12->m_Components.p[46].m_pComponent;
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID);
          else
            v14 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::AttackRightsComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID);
        }
        if ( v14 )
        {
          if ( LOBYTE(v14[149].m_Flags) )
          {
            v15 = UFG::Metrics::msInstance.mSimTime_Temp;
            if ( UFG::Metrics::msInstance.mSimTime_Temp >= *(float *)&v14[149].m_NameUID )
            {
              LOBYTE(v14[149].m_Flags) = 0;
              *(float *)&v14[149].m_NameUID = v15 + 5.0;
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
void __fastcall OpportunityAttackCooldownCondition::OpportunityAttackCooldownCondition(OpportunityAttackCooldownCondition *this)
{
  OpportunityAttackCooldownCondition *v1; // rbx
  IConditionInit *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rax

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v2 = (IConditionInit *)&v1->vfptr;
  v3 = (UFG::qNode<IConditionInit,IConditionInit> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&OpportunityAttackCooldownCondition::`vftable'{for `Condition'};
  v2->vfptr = (IConditionInitVtbl *)&OpportunityAttackCooldownCondition::`vftable'{for `IConditionInit'};
  *(_WORD *)&v1->m_TargetType.mValue = 22;
  *(_QWORD *)&v1->m_MinTimeUntilNextOpportunityAttackPropertySymbol.mUID = -1i64;
  v1->m_MyRoot.mOffset = 0i64;
  *(_QWORD *)&v1->m_HasBegunUID = 0i64;
  v1->m_MaxTimeUntilNextOpportunityAttackUID = 0;
}

// File Line: 4211
// RVA: 0x3398B0
void __fastcall OpportunityAttackCooldownCondition::~OpportunityAttackCooldownCondition(OpportunityAttackCooldownCondition *this)
{
  OpportunityAttackCooldownCondition *v1; // r8
  UFG::qNode<IConditionInit,IConditionInit> *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v4; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&OpportunityAttackCooldownCondition::`vftable'{for `Condition'};
  this->vfptr = (IConditionInitVtbl *)&OpportunityAttackCooldownCondition::`vftable'{for `IConditionInit'};
  v2 = (UFG::qNode<IConditionInit,IConditionInit> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4226
// RVA: 0x383570
void __fastcall OpportunityAttackCooldownCondition::ResolveReferences(OpportunityAttackCooldownCondition *this, ActionNode *action_node)
{
  OpportunityAttackCooldownCondition *v2; // rdi
  ActionNode *v3; // rbx
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *v5; // rcx
  signed __int64 v6; // rax
  ActionNodeRoot *v7; // rax
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  hkSeekableStreamReader *v12; // [rsp+20h] [rbp-18h]
  void (__fastcall *v13)(OpportunityAttackCooldownCondition *, ActionNode *, ActionContext *); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = action_node;
  v4 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v5 = &v2->m_MyRoot;
  if ( v4 )
    v6 = (char *)v4 - (char *)v5;
  else
    v6 = 0i64;
  v5->mOffset = v6;
  Assembly::GetRCX(v2);
  v13 = OpportunityAttackCooldownCondition::OnMyExitCallback;
  v12 = Assembly::GetRCX(v2);
  ActionNode::AddOnExitCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v12);
  v7 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))v3->vfptr[1].SetResourceOwner)(v3);
  ActionNodeRoot::AddToInitList(v7, (IConditionInit *)&v2->vfptr);
  v8 = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_HasBegunUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  v9 = v2->m_MinTimeUntilNextOpportunityAttackUID;
  v2->m_HasBegunUID = v8;
  v10 = UFG::ActionTreeComponentBase::MakeValueUID(v9, 0);
  v11 = v2->m_MaxTimeUntilNextOpportunityAttackUID;
  v2->m_MinTimeUntilNextOpportunityAttackUID = v10;
  v2->m_MaxTimeUntilNextOpportunityAttackUID = UFG::ActionTreeComponentBase::MakeValueUID(v11, 0);
}

// File Line: 4253
// RVA: 0x366180
void __fastcall OpportunityAttackCooldownCondition::Init(OpportunityAttackCooldownCondition *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // rax
  signed __int64 v3; // rsi
  ActionContext *v4; // rbp
  OpportunityAttackCooldownCondition *v5; // rbx
  UFG::SceneObjectProperties *v6; // rax
  UFG::qPropertySet *v7; // rdi
  unsigned int v8; // er9
  __int64 v9; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  signed __int64 v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  unsigned int v13; // er9
  __int64 v14; // rax
  UFG::ActionTreeComponentBase *v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  float value; // [rsp+38h] [rbp+10h]

  v2 = action_context->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = action_context;
  v5 = this;
  if ( !v2 || (v6 = v2->m_pSceneObj) == 0i64 )
  {
    v7 = 0i64;
LABEL_6:
    if ( !v7 )
      return;
    goto LABEL_7;
  }
  v7 = v6->mpWritableProperties;
  if ( !v7 )
  {
    v7 = v6->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  value = 0.0;
  if ( UFG::TSCharacter::get_attack_param_real(v7, (UFG::qSymbol *)&this->vfptr + 1, &value) )
  {
    v9 = *(_QWORD *)&v5->m_TargetType.mValue;
    if ( v9 )
      v10 = (UFG::ActionTreeComponentBase *)(&v5->m_TargetType.mValue + v9);
    else
      v10 = 0i64;
    if ( v9 )
      v11 = (signed __int64)(&v5->m_TargetType + v9);
    else
      v11 = 0i64;
    v12 = v4->mActionTreeComponentBase[*(char *)(v11 + 236)];
    if ( !v12 )
      v12 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v12,
      v10,
      (ActionNodeRoot *)LODWORD(v5->mNext),
      v8,
      SLODWORD(value));
  }
  if ( UFG::TSCharacter::get_attack_param_real(v7, (UFG::qSymbol *)&v5->mPrev, &value) )
  {
    v14 = *(_QWORD *)&v5->m_TargetType.mValue;
    if ( v14 )
      v15 = (UFG::ActionTreeComponentBase *)(&v5->m_TargetType.mValue + v14);
    else
      v15 = 0i64;
    if ( v14 )
      v3 = (signed __int64)(&v5->m_TargetType + v14);
    v16 = v4->mActionTreeComponentBase[*(char *)(v3 + 236)];
    if ( !v16 )
      v16 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v16,
      v15,
      (ActionNodeRoot *)HIDWORD(v5->mNext),
      v13,
      SLODWORD(value));
  }
}

// File Line: 4295
// RVA: 0x37B790
void __fastcall OpportunityAttackCooldownCondition::OnMyExitCallback(OpportunityAttackCooldownCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  __int64 v3; // rax
  signed __int64 v4; // rsi
  ActionContext *v5; // rbp
  OpportunityAttackCooldownCondition *v6; // rbx
  UFG::ActionTreeComponentBase *v7; // rdx
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  UFG::SimObject *v10; // r8
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // r8
  UFG::SimComponent *v13; // rax
  bool v14; // zf
  UFG::SimObjectGame *v15; // rcx
  UFG::SimObjectGame *v16; // r8
  unsigned __int16 v17; // cx
  UFG::AttackRightsComponent *v18; // rdi
  UFG::SimComponent *v19; // rax
  __int64 v20; // rax
  UFG::ActionTreeComponentBase *v21; // rdx
  signed __int64 v22; // rcx
  UFG::ActionTreeComponentBase *v23; // rcx
  __int64 v24; // rax
  UFG::ActionTreeComponentBase *v25; // rdx
  UFG::ActionTreeComponentBase *v26; // rcx
  float max_time_until_next_one; // [rsp+40h] [rbp+8h]
  unsigned int value_uid; // [rsp+50h] [rbp+18h]

  v3 = this->m_MyRoot.mOffset;
  v4 = 0i64;
  v5 = action_context;
  v6 = this;
  if ( v3 )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v3);
  else
    v7 = 0i64;
  if ( v3 )
    v8 = (char *)&this->m_MyRoot + v3;
  else
    v8 = 0i64;
  v9 = action_context->mActionTreeComponentBase[v8[236]];
  if ( !v9 )
    v9 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v9, v7, (ActionNodeRoot *)v6->m_HasBegunUID, 0);
  v10 = v5->mSimObject.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v10->m_Components.p[20].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)v5->mSimObject.m_pPointer,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v14 = ((v11 >> 12) & 1) == 0;
        v15 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
        v13 = v14 ? UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v15->vfptr,
                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v15,
                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v12 = v13;
    }
    else
    {
      v12 = v10->m_Components.p[20].m_pComponent;
    }
    if ( v12 )
    {
      v16 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)((unsigned __int8)v6->m_TargetType.mValue
                                                        + *(_QWORD *)&v12[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v12[1].m_TypeUID
                                   + 40);
      if ( v16 )
      {
        v17 = v16->m_Flags;
        if ( (v17 >> 14) & 1 )
        {
          v18 = (UFG::AttackRightsComponent *)v16->m_Components.p[46].m_pComponent;
        }
        else
        {
          if ( (v17 & 0x8000u) == 0 )
          {
            if ( (v17 >> 13) & 1 )
              v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::AttackRightsComponent::_TypeUID);
            else
              v19 = (v17 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v16,
                                        UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                  (UFG::SimObject *)&v16->vfptr,
                                                                                  UFG::AttackRightsComponent::_TypeUID);
          }
          else
          {
            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::AttackRightsComponent::_TypeUID);
          }
          v18 = (UFG::AttackRightsComponent *)v19;
        }
        if ( v18 )
        {
          v20 = v6->m_MyRoot.mOffset;
          value_uid = 0;
          max_time_until_next_one = 0.0;
          if ( v20 )
            v21 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v20);
          else
            v21 = 0i64;
          if ( v20 )
            v22 = (signed __int64)&v6->m_MyRoot + v20;
          else
            v22 = 0i64;
          v23 = v5->mActionTreeComponentBase[*(char *)(v22 + 236)];
          if ( !v23 )
            v23 = v5->mActionTreeComponentBase[1];
          UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
            v23,
            v21,
            (ActionNodeRoot *)v6->m_MinTimeUntilNextOpportunityAttackUID,
            (__int64)&value_uid);
          v24 = v6->m_MyRoot.mOffset;
          if ( v24 )
            v25 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v24);
          else
            v25 = 0i64;
          if ( v24 )
            v4 = (signed __int64)&v6->m_MyRoot + v24;
          v26 = v5->mActionTreeComponentBase[*(char *)(v4 + 236)];
          if ( !v26 )
            v26 = v5->mActionTreeComponentBase[1];
          UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
            v26,
            v25,
            (ActionNodeRoot *)v6->m_MaxTimeUntilNextOpportunityAttackUID,
            (__int64)&max_time_until_next_one);
          UFG::AttackRightsComponent::JustPerformedOpportunityAttack(
            v18,
            (UFG::eAttackType)(unsigned __int8)v6->m_AttackType.mValue,
            *(float *)&value_uid,
            max_time_until_next_one);
        }
      }
    }
  }
}

// File Line: 4333
// RVA: 0x371700
char __fastcall OpportunityAttackCooldownCondition::Match(OpportunityAttackCooldownCondition *this, ActionContext *context)
{
  __int64 v2; // rax
  ActionContext *v3; // rbx
  char *v4; // rdx
  OpportunityAttackCooldownCondition *v5; // rdi
  UFG::ActionTreeComponentBase *v6; // r10
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // r8
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  __int64 v15; // rdx
  bool v16; // cl
  unsigned int value_uid; // [rsp+30h] [rbp+8h]

  v2 = this->m_MyRoot.mOffset;
  v3 = context;
  v4 = 0i64;
  v5 = this;
  LOBYTE(value_uid) = 0;
  if ( v2 )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v6 = 0i64;
  if ( v2 )
    v4 = (char *)&this->m_MyRoot + v2;
  v7 = v3->mActionTreeComponentBase[v4[236]];
  if ( !v7 )
    v7 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v7,
    v6,
    (ActionNodeRoot *)v5->m_HasBegunUID,
    (__int64)&value_uid);
  if ( (_BYTE)value_uid )
    return 1;
  v8 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v10 = v11;
  }
  else
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  if ( !v10 )
    return 0;
  v12 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)v5->m_TargetType.mValue
                                                    + *(_QWORD *)&v10[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v10[1].m_TypeUID
                               + 40);
  if ( !v12 )
    return 0;
  v13 = v12->m_Flags;
  if ( (v13 >> 14) & 1 )
  {
    v14 = v12->m_Components.p[46].m_pComponent;
  }
  else if ( (v13 & 0x8000u) == 0 )
  {
    if ( (v13 >> 13) & 1 )
      v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID);
    else
      v14 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::AttackRightsComponent::_TypeUID);
  }
  else
  {
    v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID);
  }
  if ( !v14 )
    return 0;
  v15 = (unsigned __int8)v5->m_AttackType.mValue;
  v16 = UFG::Metrics::msInstance.mSimTime_Temp >= *(float *)(&v14[149].m_SimObjIndex + 2 * v15 + 1);
  if ( UFG::Metrics::msInstance.mSimTime_Temp >= *(float *)(&v14[149].m_SimObjIndex + 2 * v15 + 1) )
    *(float *)(&v14[149].m_SimObjIndex + 2 * v15 + 1) = UFG::Metrics::msInstance.mSimTime_Temp + 5.0;
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
  TimeToInterceptCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TimeToInterceptCondition::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->m_InEqualityOperator.mValue = 4;
  v1->m_TimeToIntercept = 1.0;
  v1->m_MaxAngleRadians = 0.17453294;
  v1->m_MaxAngleCosine = cosf(0.17453294);
}

// File Line: 4414
// RVA: 0x33B6F0
void __fastcall TimeToInterceptCondition::~TimeToInterceptCondition(TimeToInterceptCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TimeToInterceptCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4425
// RVA: 0x374600
bool __fastcall TimeToInterceptCondition::Match(TimeToInterceptCondition *this, ActionContext *context)
{
  TimeToInterceptCondition *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  __int64 v8; // rdi
  __int64 v9; // rdi
  UFG::SimObject *v10; // rbx
  UFG::TransformNodeComponent *v11; // rbx
  __m128 v12; // xmm10
  float v13; // xmm11_4
  float v14; // xmm9_4
  __m128 v15; // xmm12
  __m128 v16; // xmm8
  float v17; // xmm3_4
  float v18; // xmm5_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm5_4
  __m128 v22; // xmm4
  float v23; // xmm3_4
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

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(_QWORD *)(56i64
                 * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue + *(_QWORD *)&v6[1].m_Flags + 8i64)
                 + *(_QWORD *)&v6[1].m_TypeUID
                 + 40);
  v9 = v8 ? *(_QWORD *)(v8 + 88) : 0i64;
  v10 = v4->mSimObject.m_pPointer;
  v11 = v10 ? v10->m_pTransformNodeComponent : 0i64;
  if ( !v9 || !v11 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
  UFG::TransformNodeComponent::UpdateWorldTransform(v11);
  v12 = (__m128)LODWORD(v11->mWorldVelocity.x);
  v12.m128_f32[0] = v12.m128_f32[0] - *(float *)(v9 + 256);
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
    v21 = UFG::qVector3::msZero.x;
    v22 = (__m128)LODWORD(UFG::qVector3::msZero.y);
    v23 = UFG::qVector3::msZero.z;
  }
  else
  {
    v17 = v16.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
    v22 = v15;
    v18 = v14 * v17;
    v22.m128_f32[0] = v15.m128_f32[0] * v17;
    v19 = v17 * 0.0;
    v20 = (float)((float)(v18 * v12.m128_f32[0]) + (float)(v22.m128_f32[0] * v13)) + (float)(v19 * 0.0);
    v21 = v18 * v20;
    v22.m128_f32[0] = v22.m128_f32[0] * v20;
    v23 = v19 * v20;
  }
  v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21)) + (float)(v23 * v23);
  LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v22);
  LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v16);
  if ( v24 <= 1.0
    || v25 <= 0.001
    || !CompareFloat(
          (UFG::InEqualityOperator)(unsigned __int8)v2->m_InEqualityOperator.mValue,
          v2->m_TimeToIntercept,
          v25 / v24) )
  {
    return 0;
  }
  v26 = v12;
  v26.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v13 * v13);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
  v28 = v27;
  v29 = v27;
  v30 = v27 * 0.0;
  v31 = v28 * v12.m128_f32[0];
  v32 = v29 * v13;
  if ( v16.m128_f32[0] == 0.0 )
    v33 = 0.0;
  else
    v33 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
  return (float)((float)((float)((float)(v14 * v33) * v31) + (float)((float)(v15.m128_f32[0] * v33) * v32))
               + (float)((float)(v33 * 0.0) * v30)) > v2->m_MaxAngleCosine;
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
  TargetCanBeAttackedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetCanBeAttackedCondition::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
}

// File Line: 4497
// RVA: 0x33B630
void __fastcall TargetCanBeAttackedCondition::~TargetCanBeAttackedCondition(TargetCanBeAttackedCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetCanBeAttackedCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4502
// RVA: 0x372A00
bool __fastcall TargetCanBeAttackedCondition::Match(TargetCanBeAttackedCondition *this, ActionContext *context)
{
  TargetCanBeAttackedCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::TargetingSystemBaseComponent *v5; // r8
  UFG::TargetingSystemBaseComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::AttackRightsComponent *v9; // rdx
  UFG::AttackRightsComponent *v10; // rax
  __int64 v11; // rcx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    goto LABEL_32;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v3,
                                                  UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (UFG::TargetingSystemBaseComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v3,
                                                                    UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID));
    v5 = v6;
  }
  else
  {
    v5 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    goto LABEL_32;
  v7 = (UFG::SimObjectGame *)v5->m_pTargets[(unsigned __int8)v5->m_pTargetingMap->m_Map.p[(unsigned __int8)v2->m_TargetType.mValue]].m_pTarget.m_pPointer;
  if ( !v7 )
    goto LABEL_32;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = (UFG::AttackRightsComponent *)v7->m_Components.p[46].m_pComponent;
  }
  else
  {
    if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v10 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v7,
                                              UFG::AttackRightsComponent::_TypeUID);
      else
        v10 = (UFG::AttackRightsComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v7,
                                                                UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AttackRightsComponent::_TypeUID));
    }
    else
    {
      v10 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v7,
                                            UFG::AttackRightsComponent::_TypeUID);
    }
    v9 = v10;
  }
  if ( !v9 )
    goto LABEL_32;
  v11 = (unsigned __int8)v2->m_AttackType.mValue;
  result = v9->m_AttackingEnabled[v11];
  if ( (_DWORD)v11 != 1 )
    return result;
  if ( result && !v9->m_InCombatWithSomeone )
    result = 1;
  else
LABEL_32:
    result = 0;
  return result;
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
  HasPositionToDefendCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HasPositionToDefendCondition::`vftable';
}

// File Line: 4541
// RVA: 0x3385B0
void __fastcall HasPositionToDefendCondition::~HasPositionToDefendCondition(HasPositionToDefendCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&HasPositionToDefendCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4546
// RVA: 0x3704D0
bool __fastcall HasPositionToDefendCondition::Match(HasPositionToDefendCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = v2->m_Components.p[5].m_pComponent)) : (v4 = v2->m_Components.p[5].m_pComponent),
        v4) )
  {
    result = (LOBYTE(v4[32].m_BoundComponentHandles.mNode.mPrev) >> 6) & 1;
  }
  else
  {
    result = 0;
  }
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
void __fastcall OutsideOfPositionToDefendCondition::OutsideOfPositionToDefendCondition(OutsideOfPositionToDefendCondition *this)
{
  OutsideOfPositionToDefendCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&OutsideOfPositionToDefendCondition::`vftable';
  *(_QWORD *)&v1->m_HowCloseToGet = 0x40000000i64;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 4582
// RVA: 0x339920
void __fastcall OutsideOfPositionToDefendCondition::~OutsideOfPositionToDefendCondition(OutsideOfPositionToDefendCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&OutsideOfPositionToDefendCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4596
// RVA: 0x3718D0
bool __fastcall OutsideOfPositionToDefendCondition::Match(OutsideOfPositionToDefendCondition *this, ActionContext *context)
{
  OutsideOfPositionToDefendCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbp
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rsi
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rax
  UFG::TransformNodeComponent *v9; // r14
  __int64 v10; // rax
  signed __int64 v11; // rdi
  float v12; // xmm6_4
  UFG::ActionTreeComponentBase *v13; // rdx
  signed __int64 v14; // rcx
  UFG::ActionTreeComponentBase *v15; // rcx
  UFG::qVector3 *v16; // rax
  __m128 v17; // xmm1
  float v18; // xmm0_4
  __int64 v19; // rax
  bool v20; // si
  UFG::ActionTreeComponentBase *v21; // rdx
  UFG::ActionTreeComponentBase *v22; // rcx
  bool result; // al
  __int64 v24; // rax
  signed __int64 v25; // rdi
  UFG::ActionTreeComponentBase *v26; // rdx
  UFG::ActionTreeComponentBase *v27; // rcx
  unsigned int value_uid; // [rsp+58h] [rbp+10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3
    && ((v5 = v3->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID)) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIScriptInterfaceComponent::_TypeUID)),
                                                                        v6 = v7) : (v6 = v3->m_Components.p[5].m_pComponent)) : (v6 = v3->m_Components.p[5].m_pComponent),
        v6
     && (_QWORD)v6[32].m_BoundComponentHandles.mNode.mPrev & 0x40
     && (v8 = v4->mSimObject.m_pPointer) != 0i64
     && (v9 = v8->m_pTransformNodeComponent) != 0i64) )
  {
    v10 = v2->m_MyRoot.mOffset;
    v11 = 0i64;
    v12 = *((float *)&v6[10].m_BoundComponentHandles.mNode.mNext + 1);
    LOBYTE(value_uid) = 0;
    if ( v10 )
      v13 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v10);
    else
      v13 = 0i64;
    if ( v10 )
      v14 = (signed __int64)&v2->m_MyRoot + v10;
    else
      v14 = 0i64;
    v15 = v4->mActionTreeComponentBase[*(char *)(v14 + 236)];
    if ( !v15 )
      v15 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
      v15,
      v13,
      (ActionNodeRoot *)v2->m_HasBegunUID,
      (__int64)&value_uid);
    if ( (_BYTE)value_uid && v2->m_HowCloseToGet < v12 )
      v12 = v2->m_HowCloseToGet;
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    v16 = UFG::AIScriptInterfaceComponent::GetPositionToDefend((UFG::AIScriptInterfaceComponent *)v6);
    v17 = (__m128)LODWORD(v9->mWorldTransform.v3.y);
    v17.m128_f32[0] = v17.m128_f32[0] - v16->y;
    v18 = v9->mWorldTransform.v3.x - v16->x;
    v19 = v2->m_MyRoot.mOffset;
    v17.m128_f32[0] = (float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v18 * v18);
    v20 = COERCE_FLOAT(_mm_sqrt_ps(v17)) > v12;
    if ( v19 )
      v21 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v19);
    else
      v21 = 0i64;
    if ( v19 )
      v11 = (signed __int64)&v2->m_MyRoot + v19;
    v22 = v4->mActionTreeComponentBase[*(char *)(v11 + 236)];
    if ( !v22 )
      v22 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v22, v21, (ActionNodeRoot *)v2->m_HasBegunUID, v20);
    result = v20;
  }
  else
  {
    v24 = v2->m_MyRoot.mOffset;
    v25 = 0i64;
    if ( v24 )
      v26 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v24);
    else
      v26 = 0i64;
    if ( v24 )
      v25 = (signed __int64)&v2->m_MyRoot + v24;
    v27 = v4->mActionTreeComponentBase[*(char *)(v25 + 236)];
    if ( !v27 )
      v27 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v27, v26, (ActionNodeRoot *)v2->m_HasBegunUID, 0);
    result = 0;
  }
  return result;
}<bool>(v27, v26, (ActionNodeRoot *)v2->m_HasBegunUID, 0);
    resul

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
void __fastcall AbandonPositionToDefendCondition::AbandonPositionToDefendCondition(AbandonPositionToDefendCondition *this)
{
  AbandonPositionToDefendCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AbandonPositionToDefendCondition::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->m_PositionToDefendHasBeenCompromisedUID = 0;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 4669
// RVA: 0x334C70
void __fastcall AbandonPositionToDefendCondition::~AbandonPositionToDefendCondition(AbandonPositionToDefendCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AbandonPositionToDefendCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4674
// RVA: 0x383630
void __fastcall AbandonPositionToDefendCondition::ResolveReferences(OutsideOfPositionToDefendCondition *this, ActionNode *action_node)
{
  OutsideOfPositionToDefendCondition *v2; // rbx
  Expression::IMemberMap *v3; // rax
  signed __int64 v4; // rcx

  v2 = this;
  v3 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v4 = (signed __int64)&v2->m_MyRoot;
  if ( v3 )
    v3 = (Expression::IMemberMap *)((char *)v3 - v4);
  *(_QWORD *)v4 = v3;
  v2->m_HasBegunUID = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_HasBegunUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 4683
// RVA: 0x36EDA0
char __fastcall AbandonPositionToDefendCondition::Match(AbandonPositionToDefendCondition *this, ActionContext *context)
{
  AbandonPositionToDefendCondition *v2; // r14
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rsi
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::TargetingSystemBaseComponent *v10; // rdi
  UFG::SimComponent *v11; // rax
  __int64 v12; // rax
  signed __int64 v13; // rbp
  UFG::ActionTreeComponentBase *v14; // rdx
  signed __int64 v15; // rcx
  UFG::ActionTreeComponentBase *v16; // rcx
  unsigned int v17; // er9
  __int64 v18; // rax
  UFG::ActionTreeComponentBase *v19; // rdx
  UFG::ActionTreeComponentBase *v20; // rcx
  unsigned __int8 v21; // bl
  bool v22; // al
  char result; // al
  unsigned int value_uid; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    goto LABEL_52;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[5].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIScriptInterfaceComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIScriptInterfaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[5].m_pComponent;
  }
  if ( !v6 )
    goto LABEL_52;
  v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( !v8 )
    goto LABEL_52;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v10 = (UFG::TargetingSystemBaseComponent *)v11;
  }
  else
  {
    v10 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
  }
  if ( !v10 )
    goto LABEL_52;
  v12 = v2->m_MyRoot.mOffset;
  v13 = 0i64;
  LOBYTE(value_uid) = 0;
  if ( v12 )
    v14 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v12);
  else
    v14 = 0i64;
  if ( v12 )
    v15 = (signed __int64)&v2->m_MyRoot + v12;
  else
    v15 = 0i64;
  v16 = v4->mActionTreeComponentBase[*(char *)(v15 + 236)];
  if ( !v16 )
    v16 = v4->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v16,
    v14,
    (ActionNodeRoot *)v2->m_PositionToDefendHasBeenCompromisedUID,
    (__int64)&value_uid);
  LOBYTE(v17) = (_BYTE)value_uid || AbandonPositionToDefendCondition::PositionToDefendIsCompromised(v2, v4);
  v18 = v2->m_MyRoot.mOffset;
  LOBYTE(value_uid) = v17;
  if ( v18 )
    v19 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v18);
  else
    v19 = 0i64;
  if ( v18 )
    v13 = (signed __int64)&v2->m_MyRoot + v18;
  v20 = v4->mActionTreeComponentBase[*(char *)(v13 + 236)];
  if ( !v20 )
    v20 = v4->mActionTreeComponentBase[1];
  if ( (UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
          v20,
          v19,
          (ActionNodeRoot *)v2->m_PositionToDefendHasBeenCompromisedUID,
          v17),
        v21 = BYTE1(v6[32].m_BoundComponentHandles.mNode.mPrev),
        v22 = UFG::HasRangedWeaponEquippedWithAmmo(v10),
        v21 & 1)
    && v2->m_PositionToDefendHasBeenCompromised
    || (v21 >> 1) & 1 && !v22 )
  {
    result = 1;
  }
  else
  {
LABEL_52:
    result = 0;
  }
  return result;
}

// File Line: 4719
// RVA: 0x37C690
bool __fastcall AbandonPositionToDefendCondition::PositionToDefendIsCompromised(AbandonPositionToDefendCondition *this, ActionContext *context)
{
  AbandonPositionToDefendCondition *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  UFG::SimComponent *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  UFG::SimComponent *v9; // rdx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  __int64 v12; // r8
  __int64 v13; // rbx
  __int64 v14; // rsi
  __int64 v15; // rsi
  __int64 v16; // rbx
  UFG::TransformNodeComponent *v17; // rbx
  float v18; // xmm6_4
  __m128 v19; // xmm1
  float v20; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v7;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v9 = v8->m_Components.p[5].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else
      {
        v11 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v8->vfptr,
                UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      v9 = v11;
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
  if ( !v5 || !v9 )
    return 0;
  v12 = *(_QWORD *)&v5[1].m_Flags;
  v13 = *(_QWORD *)&v5[1].m_TypeUID;
  v14 = *(_QWORD *)(56i64 * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue + v12 + 8) + v13 + 40);
  v15 = v14 ? *(_QWORD *)(v14 + 88) : 0i64;
  v16 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(v12 + 40) + v13 + 40);
  v17 = (UFG::TransformNodeComponent *)(v16 ? *(_QWORD *)(v16 + 88) : 0i64);
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
  return v18 > COERCE_FLOAT(_mm_sqrt_ps(v19));
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
void __fastcall CrouchWhileDefendingPositionCondition::CrouchWhileDefendingPositionCondition(CrouchWhileDefendingPositionCondition *this)
{
  CrouchWhileDefendingPositionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CrouchWhileDefendingPositionCondition::`vftable';
}

// File Line: 4775
// RVA: 0x336000
void __fastcall CrouchWhileDefendingPositionCondition::~CrouchWhileDefendingPositionCondition(CrouchWhileDefendingPositionCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&CrouchWhileDefendingPositionCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4780
// RVA: 0x36F890
bool __fastcall CrouchWhileDefendingPositionCondition::Match(CrouchWhileDefendingPositionCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = v2->m_Components.p[5].m_pComponent)) : (v4 = v2->m_Components.p[5].m_pComponent),
        v4) )
  {
    result = LOBYTE(v4[32].m_BoundComponentHandles.mNode.mPrev) >> 7;
  }
  else
  {
    result = 0;
  }
  return result;
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
  NodeRequestCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestCondition::`vftable';
  v1->m_pActionNode = 0i64;
}

// File Line: 4811
// RVA: 0x339800
void __fastcall NodeRequestCondition::~NodeRequestCondition(NodeRequestCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4825
// RVA: 0x3715E0
bool __fastcall NodeRequestCondition::Match(NodeRequestCondition *this, ActionContext *context)
{
  NodeRequestCondition *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AICharacterControllerBaseComponent *v4; // rax
  unsigned __int16 v5; // dx
  ActionNode *v6; // rdx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = v2->m_pActionNode;
  if ( v6 && v4 )
    result = v6->mID.mUID == v4->m_Intention.mNodeRequestHash;
  else
    result = 0;
  return result;
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
  NodeRequestAnyCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestAnyCondition::`vftable';
}

// File Line: 4866
// RVA: 0x3397C0
void __fastcall NodeRequestAnyCondition::~NodeRequestAnyCondition(NodeRequestAnyCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestAnyCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4871
// RVA: 0x371550
bool __fastcall NodeRequestAnyCondition::Match(NodeRequestAnyCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AICharacterControllerBaseComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID)) : (v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v4 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2)),
        v4) )
  {
    result = v4->m_Intention.mNodeRequestHash != 0;
  }
  else
  {
    result = 0;
  }
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
  LeaderHasFollowersCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&LeaderHasFollowersCondition::`vftable';
}

// File Line: 4910
// RVA: 0x3390E0
void __fastcall LeaderHasFollowersCondition::~LeaderHasFollowersCondition(LeaderHasFollowersCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&LeaderHasFollowersCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4915
// RVA: 0x371170
char __fastcall LeaderHasFollowersCondition::Match(LeaderHasFollowersCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  signed __int64 v3; // rbx
  ActionContext *v4; // rbp
  UFG::SimComponent *v5; // rsi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectCVBase *v8; // rcx
  UFG::ActiveAIEntityComponent *v9; // rdi
  unsigned __int16 v10; // dx
  UFG::ActiveAIEntityComponent *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // r8
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **v16; // r8
  UFG::ActiveAIEntityComponent *v17; // rdx
  UFG::SimComponent *v18; // rax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = context;
  if ( v2 )
  {
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v2->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v7;
    }
    else
    {
      v5 = v2->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v8);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v8->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v8->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v8->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v8);
    }
    v9 = v11;
  }
  else
  {
    v9 = 0i64;
  }
  v12 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v13 = v12->m_Components.p[5].m_pComponent;
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else
      {
        v15 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v12->vfptr,
                UFG::AIScriptInterfaceComponent::_TypeUID);
      }
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
  if ( !v5 || !v9 || !v13 )
    return 0;
  v16 = &v13[29].m_SafePointerList.mNode.mNext;
  while ( 1 )
  {
    v17 = (UFG::ActiveAIEntityComponent *)*v16;
    if ( *v16 )
    {
      v18 = v17->m_pHealthComponent.m_pSimComponent;
      if ( v18 )
      {
        if ( !BYTE4(v18[1].m_BoundComponentHandles.mNode.mPrev)
          && *(_QWORD *)(56i64
                       * *(unsigned __int8 *)(*(_QWORD *)&v17->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                            + 30i64)
                       + *(_QWORD *)&v17->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                       + 40) == *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 30i64)
                                          + *(_QWORD *)&v5[1].m_TypeUID
                                          + 40)
          && v17 != v9 )
        {
          break;
        }
      }
    }
    ++v3;
    v16 += 3;
    if ( v3 >= 10 )
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
  AICoverIsValidCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICoverIsValidCondition::`vftable';
  v1->m_iTargetType = 0;
  v1->m_fMinDistance = 5.0;
  v1->m_fFacingAngle = 1.0471976;
}

// File Line: 4983
// RVA: 0x333E70
void __fastcall AICoverIsValidCondition::~AICoverIsValidCondition(AICoverIsValidCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverIsValidCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 4988
// RVA: 0x36E120
char __fastcall AICoverIsValidCondition::Match(AICoverIsValidCondition *this, ActionContext *pContext)
{
  unsigned int *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 *v7; // rdi
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  __int64 v12; // rbx
  UFG::TransformNodeComponent *v13; // rbx
  __int64 v14; // rax
  float v15; // xmm1_4
  float v16; // xmm0_4
  __int128 v17; // xmm2
  __int128 v18; // xmm2
  char result; // al
  float v20; // [rsp+20h] [rbp-18h]
  float v21; // [rsp+24h] [rbp-14h]
  float v22; // [rsp+28h] [rbp-10h]

  v2 = (unsigned int *)this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    goto LABEL_33;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
  }
  else
  {
    v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
  }
  if ( !v6 )
    goto LABEL_33;
  v7 = *(__int64 **)&v6[1].m_TypeUID;
  if ( !v7 )
    goto LABEL_33;
  if ( !(*(unsigned __int8 (__fastcall **)(__int64 *))(*v7 + 16))(v7) )
    goto LABEL_33;
  v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( !v8 )
    goto LABEL_33;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v10 = v11;
  }
  else
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  if ( !v10 )
    goto LABEL_33;
  v12 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(v2[6] + *(_QWORD *)&v10[1].m_Flags + 8i64)
                  + *(_QWORD *)&v10[1].m_TypeUID
                  + 40);
  if ( !v12 )
    goto LABEL_33;
  v13 = *(UFG::TransformNodeComponent **)(v12 + 88);
  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
  v14 = *v7;
  v15 = UFG::qVector3::msAxisZ.y + v13->mWorldTransform.v3.y;
  v16 = UFG::qVector3::msAxisZ.x + v13->mWorldTransform.v3.x;
  v22 = UFG::qVector3::msAxisZ.z + v13->mWorldTransform.v3.z;
  v17 = v2[7];
  v20 = v16;
  v21 = v15;
  if ( (*(unsigned __int8 (__fastcall **)(__int64 *, float *))(v14 + 56))(v7, &v20) )
    goto LABEL_33;
  v18 = v2[8];
  if ( (*(unsigned __int8 (__fastcall **)(__int64 *, float *))(*v7 + 64))(v7, &v20) )
    result = 1;
  else
LABEL_33:
    result = 0;
  return result;
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
  AICoverTargetIsLatched *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICoverTargetIsLatched::`vftable';
}

// File Line: 5048
// RVA: 0x334280
void __fastcall AICoverTargetIsLatched::~AICoverTargetIsLatched(AICoverTargetIsLatched *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverTargetIsLatched::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5052
// RVA: 0x36E310
char __fastcall AICoverTargetIsLatched::Match(AICoverTargetIsLatched *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // rsi
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  __int64 v7; // rdi
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  char result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = pContext;
  if ( !v2 )
    goto LABEL_29;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AICoverComponent::_TypeUID);
  }
  else
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
  }
  v6 = v5;
  if ( !v5 )
    goto LABEL_29;
  v7 = *(_QWORD *)&v5[1].m_TypeUID;
  if ( !v7 || !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7) )
    goto LABEL_29;
  v8 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( !((v9 >> 14) & 1) )
    {
      if ( (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID);
        }
        else if ( (v9 >> 12) & 1 )
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID);
        }
        else
        {
          UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::WorldContextComponent::_TypeUID);
        }
      }
      else
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID);
      }
    }
  }
  v10 = v6[1].m_BoundComponentHandles.mNode.mNext;
  if ( v10
    && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, __int64))v10->mPrev[13].mPrev)(
         v10,
         v7) )
  {
    result = 1;
  }
  else
  {
LABEL_29:
    result = 0;
  }
  return result;
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
  AICoverFiringPositionClear *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICoverFiringPositionClear::`vftable';
  *(_WORD *)&v1->m_Left = 0;
  v1->m_Top = 0;
}

// File Line: 5100
// RVA: 0x333E30
void __fastcall AICoverFiringPositionClear::~AICoverFiringPositionClear(AICoverFiringPositionClear *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverFiringPositionClear::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5104
// RVA: 0x36E020
bool __fastcall AICoverFiringPositionClear::Match(AICoverFiringPositionClear *this, ActionContext *pContext)
{
  AICoverFiringPositionClear *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  _BYTE *v6; // rbx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = *(_BYTE **)&v5[1].m_TypeUID;
      if ( v6 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(_BYTE *))(*(_QWORD *)v6 + 16i64))(v6)
          && (*(unsigned __int8 (__fastcall **)(_BYTE *))(*(_QWORD *)v6 + 32i64))(v6)
          && (v2->m_Left && v6[320] & 1 || v2->m_Right && (v6[320] >> 1) & 1 || v2->m_Top && (v6[320] >> 2) & 1) )
        {
          result = 1;
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
void __fastcall IsClosestFormationMemberCondition::IsClosestFormationMemberCondition(IsClosestFormationMemberCondition *this)
{
  IsClosestFormationMemberCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsClosestFormationMemberCondition::`vftable';
  v1->m_TargetType.mValue = 22;
}

// File Line: 5170
// RVA: 0x338F10
void __fastcall IsClosestFormationMemberCondition::~IsClosestFormationMemberCondition(IsClosestFormationMemberCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsClosestFormationMemberCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5175
// RVA: 0x3709B0
char __fastcall IsClosestFormationMemberCondition::Match(IsClosestFormationMemberCondition *this, ActionContext *action_context)
{
  IsClosestFormationMemberCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::TransformNodeComponent *v10; // r13
  UFG::SimComponent *v11; // rax
  __int64 v12; // rcx
  float v13; // xmm6_4
  UFG::SimObject *v14; // r14
  signed __int64 v15; // r12
  signed int *v16; // r15
  __int64 v17; // rbp
  __int64 *v18; // rsi
  __int64 v19; // rbx
  __int64 v20; // rax
  __int64 v21; // rcx
  UFG::TransformNodeComponent *v22; // rdi
  __int64 v23; // rax
  char result; // al
  ActionContext *v25; // [rsp+88h] [rbp+10h]
  __int64 v26; // [rsp+90h] [rbp+18h]

  v25 = action_context;
  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !v3 )
    goto LABEL_53;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    action_context = v25;
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    goto LABEL_53;
  v7 = action_context->mSimObject.m_pPointer;
  if ( !v7 )
    goto LABEL_53;
  if ( !v7->m_pTransformNodeComponent )
    goto LABEL_53;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                   + *(_QWORD *)&v5[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v8 )
    goto LABEL_53;
  v9 = v8->m_Flags;
  v10 = v8->m_pTransformNodeComponent;
  if ( (v9 >> 14) & 1 )
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FormationManagerComponent::_TypeUID);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FormationManagerComponent::_TypeUID);
    else
      v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FormationManagerComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::FormationManagerComponent::_TypeUID);
  }
  else
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FormationManagerComponent::_TypeUID);
  }
  if ( !v11 )
    goto LABEL_53;
  if ( !v10 )
    goto LABEL_53;
  v12 = SLODWORD(v11[5].m_SafePointerList.mNode.mPrev);
  v13 = FLOAT_N1_0;
  v14 = 0i64;
  v26 = v12;
  if ( v12 <= 0 )
    goto LABEL_53;
  v15 = (signed __int64)&v11[10].m_BoundComponentHandles;
  v16 = (signed int *)((char *)&v11[5].m_SafePointerList.mNode.mPrev + 4);
  do
  {
    v17 = *v16;
    if ( v17 > 0 )
    {
      v18 = (__int64 *)v15;
      do
      {
        v19 = *v18;
        if ( *v18 )
        {
          v20 = *(_QWORD *)(v19 + 104);
          if ( v20 )
          {
            v21 = *(_QWORD *)(v20 + 40);
            if ( v21 )
            {
              if ( *(_QWORD *)(v21 + 88) )
              {
                v22 = (UFG::TransformNodeComponent *)(v21 ? *(_QWORD *)(v21 + 88) : 0i64);
                UFG::TransformNodeComponent::UpdateWorldTransform(v22);
                UFG::TransformNodeComponent::UpdateWorldTransform(v10);
                if ( v13 < 0.0
                  || (float)((float)((float)(v10->mWorldTransform.v3.y - v22->mWorldTransform.v3.y)
                                   * (float)(v10->mWorldTransform.v3.y - v22->mWorldTransform.v3.y))
                           + (float)((float)(v10->mWorldTransform.v3.x - v22->mWorldTransform.v3.x)
                                   * (float)(v10->mWorldTransform.v3.x - v22->mWorldTransform.v3.x))) < v13 )
                {
                  v23 = *(_QWORD *)(v19 + 104);
                  if ( v23 )
                    v14 = *(UFG::SimObject **)(v23 + 40);
                  else
                    v14 = 0i64;
                  v13 = (float)((float)(v10->mWorldTransform.v3.y - v22->mWorldTransform.v3.y)
                              * (float)(v10->mWorldTransform.v3.y - v22->mWorldTransform.v3.y))
                      + (float)((float)(v10->mWorldTransform.v3.x - v22->mWorldTransform.v3.x)
                              * (float)(v10->mWorldTransform.v3.x - v22->mWorldTransform.v3.x));
                }
              }
            }
          }
        }
        v18 += 25;
        --v17;
      }
      while ( v17 );
      v12 = v26;
    }
    ++v16;
    v15 += 1600i64;
    v26 = --v12;
  }
  while ( v12 );
  if ( v14 && v14 == v25->mSimObject.m_pPointer )
    result = 1;
  else
LABEL_53:
    result = 0;
  return result;
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
  IsClosestGroupMemberCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsClosestGroupMemberCondition::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
  v1->m_ExcludeTarget2.mValue = 0;
}

// File Line: 5261
// RVA: 0x338F50
void __fastcall IsClosestGroupMemberCondition::~IsClosestGroupMemberCondition(IsClosestGroupMemberCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsClosestGroupMemberCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5266
// RVA: 0x370C90
_BOOL8 __fastcall IsClosestGroupMemberCondition::Match(IsClosestGroupMemberCondition *this, ActionContext *action_context)
{
  IsClosestGroupMemberCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  bool v4; // di
  ActionContext *v5; // rbp
  unsigned __int16 v6; // r8
  UFG::SimComponent *v7; // rax
  __int64 v8; // rdx
  __int64 v9; // r8
  __int64 v10; // rsi
  UFG::SimObject *v11; // r14
  UFG::SimObject *v12; // r15
  __int64 v13; // rsi
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v14; // rax
  void *(__fastcall *v15)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  UFG::SimObjectGame *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::PedFormationManagerComponent *v18; // rbx
  UFG::SimComponent *v19; // rax
  UFG::SimObject *v20; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v4 = 0;
  v5 = action_context;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v7 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v7 )
    {
      v8 = *(_QWORD *)&v7[1].m_Flags;
      v9 = *(_QWORD *)&v7[1].m_TypeUID;
      v10 = *(_QWORD *)(56i64 * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue + v8 + 8) + v9 + 40);
      v11 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)((unsigned __int8)v2->m_ExcludeTarget1.mValue + v8 + 8)
                               + v9
                               + 40);
      v12 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)((unsigned __int8)v2->m_ExcludeTarget2.mValue + v8 + 8)
                               + v9
                               + 40);
      if ( v10 )
      {
        v13 = *(_QWORD *)(v10 + 88);
        if ( v13 )
        {
          v14 = UFG::GroupComponent::GetGroupComponent(v5->mSimObject.m_pPointer);
          if ( v14 )
          {
            if ( !v14[28].__vecDelDtor || !LODWORD(v14[15].__vecDelDtor) )
              v14 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v14[32].__vecDelDtor;
            if ( v14 )
            {
              v15 = v14[33].__vecDelDtor;
              if ( v15 )
              {
                v16 = (UFG::SimObjectGame *)*((_QWORD *)v15 + 24);
                if ( v16 )
                {
                  v17 = v16->m_Flags;
                  if ( (v17 >> 14) & 1 )
                  {
                    v18 = (UFG::PedFormationManagerComponent *)v16->m_Components.p[33].m_pComponent;
                  }
                  else
                  {
                    if ( (v17 & 0x8000u) == 0 )
                    {
                      if ( (v17 >> 13) & 1 )
                      {
                        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::PedFormationManagerComponent::_TypeUID);
                      }
                      else if ( (v17 >> 12) & 1 )
                      {
                        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::PedFormationManagerComponent::_TypeUID);
                      }
                      else
                      {
                        v19 = UFG::SimObject::GetComponentOfType(
                                (UFG::SimObject *)&v16->vfptr,
                                UFG::PedFormationManagerComponent::_TypeUID);
                      }
                    }
                    else
                    {
                      v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::PedFormationManagerComponent::_TypeUID);
                    }
                    v18 = (UFG::PedFormationManagerComponent *)v19;
                  }
                  if ( v18 )
                  {
                    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v13);
                    v20 = UFG::PedFormationManagerComponent::GetClosestMember(
                            v18,
                            (UFG::qVector3 *)(v13 + 176),
                            v11,
                            v12);
                    v4 = v20 && v20 == v5->mSimObject.m_pPointer;
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
  SelectSuitableVehicleCondition *v1; // rbx
  IConditionInit *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rax

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v2 = (IConditionInit *)&v1->vfptr;
  v3 = (UFG::qNode<IConditionInit,IConditionInit> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&SelectSuitableVehicleCondition::`vftable'{for `Condition'};
  v2->vfptr = (IConditionInitVtbl *)&SelectSuitableVehicleCondition::`vftable'{for `IConditionInit'};
  v1->m_TimeBeforeReset = 3.0;
  v1->m_MinTimeBetweenUpdates = 0.25;
  v1->m_MaxTimeBetweenUpdates = 0.75;
  v1->m_IgnoreMeshTest = 0;
  v1->m_MaxSearchRadius = 0.0;
  v1->m_FilterClassSymbol.mUID = -1;
  v1->m_MyRoot.mOffset = 0i64;
  *(_QWORD *)&v1->m_VehicleUID = 0i64;
  *(_QWORD *)&v1->m_LastTimeUpdateCalledUID = 0i64;
  v1->m_TimeBetweenUpdatesUID = 0;
}

// File Line: 5342
// RVA: 0x33AA30
void __fastcall SelectSuitableVehicleCondition::~SelectSuitableVehicleCondition(SelectSuitableVehicleCondition *this)
{
  SelectSuitableVehicleCondition *v1; // r8
  UFG::qNode<IConditionInit,IConditionInit> *v2; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v3; // rcx
  UFG::qNode<IConditionInit,IConditionInit> *v4; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SelectSuitableVehicleCondition::`vftable'{for `Condition'};
  this->vfptr = (IConditionInitVtbl *)&SelectSuitableVehicleCondition::`vftable'{for `IConditionInit'};
  v2 = (UFG::qNode<IConditionInit,IConditionInit> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5352
// RVA: 0x383840
void __fastcall SelectSuitableVehicleCondition::ResolveReferences(SelectSuitableVehicleCondition *this, ActionNode *action_node)
{
  SelectSuitableVehicleCondition *v2; // rbx
  ActionNode *v3; // rsi
  ActionNodeRoot *v4; // rax
  IConditionInit *v5; // rdx
  ActionNodeRoot *v6; // rdi
  __int64 v7; // rax
  UFG::qOffset64<ActionNodeRoot *> *v8; // rcx
  __int64 v9; // rax
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  hkSeekableStreamReader *v18; // [rsp+20h] [rbp-18h]
  void (__fastcall *v19)(SelectSuitableVehicleCondition *, ActionNode *, ActionContext *); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = action_node;
  v4 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  v5 = (IConditionInit *)&v2->vfptr;
  v6 = v4;
  if ( !v2 )
    v5 = 0i64;
  ActionNodeRoot::AddToInitList(v4, v5);
  v7 = (__int64)v6->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v6->vfptr);
  v8 = &v2->m_MyRoot;
  if ( v7 )
    v9 = v7 - (_QWORD)v8;
  else
    v9 = 0i64;
  v8->mOffset = v9;
  v19 = SelectSuitableVehicleCondition::OnExitCallback;
  v18 = Assembly::GetRCX(v2);
  ActionNode::AddOnExitCallback(v3, (fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *)&v18);
  v10 = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_VehicleUID, eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  v11 = v2->m_LastTimeMatchCalledUID;
  v2->m_VehicleUID = v10;
  v12 = UFG::ActionTreeComponentBase::MakeValueUID(v11, 0);
  v13 = v2->m_LastTimeUpdateCalledUID;
  v2->m_LastTimeMatchCalledUID = v12;
  v14 = UFG::ActionTreeComponentBase::MakeValueUID(v13, 0);
  v15 = v2->m_PreviousReturnValueUID;
  v2->m_LastTimeUpdateCalledUID = v14;
  v16 = UFG::ActionTreeComponentBase::MakeValueUID(v15, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  v17 = v2->m_TimeBetweenUpdatesUID;
  v2->m_PreviousReturnValueUID = v16;
  v2->m_TimeBetweenUpdatesUID = UFG::ActionTreeComponentBase::MakeValueUID(v17, 0);
}

// File Line: 5381
// RVA: 0x366390
void __fastcall SelectSuitableVehicleCondition::Init(SelectSuitableVehicleCondition *this, ActionContext *action_context, __int64 a3, unsigned int a4)
{
  float v4; // xmm6_4
  float v5; // xmm7_4
  ActionContext *v6; // rdi
  SelectSuitableVehicleCondition *v7; // rbx
  int v8; // xmm0_4
  __int64 v9; // rax
  signed __int64 v10; // rcx
  UFG::ActionTreeComponentBase *v11; // rdx
  UFG::ActionTreeComponentBase *v12; // rcx

  v4 = *(float *)&this->m_LastTimeMatchCalledUID;
  v5 = *(float *)&this->m_VehicleUID;
  v6 = action_context;
  v7 = this;
  v8 = this->m_LastTimeMatchCalledUID;
  if ( v4 > v5 )
  {
    *(float *)&v8 = UFG::qRandom(*(float *)&v8 - v5, &UFG::qDefaultSeed) + v5;
    if ( *(float *)&v8 <= v5 )
      *(float *)&v8 = v5;
    if ( *(float *)&v8 >= v4 )
      *(float *)&v8 = v4;
  }
  v9 = *(_QWORD *)&v7->m_MinTimeBetweenUpdates;
  v10 = 0i64;
  if ( v9 )
    v11 = (UFG::ActionTreeComponentBase *)((char *)&v7->m_MinTimeBetweenUpdates + v9);
  else
    v11 = 0i64;
  if ( v9 )
    v10 = (signed __int64)&v7->m_MinTimeBetweenUpdates + v9;
  v12 = v6->mActionTreeComponentBase[*(char *)(v10 + 236)];
  if ( !v12 )
    v12 = v6->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(v12, v11, (ActionNodeRoot *)LODWORD(v7->mNext), a4, v8);
}

// File Line: 5392
// RVA: 0x37B4C0
void __fastcall SelectSuitableVehicleCondition::OnExitCallback(SelectSuitableVehicleCondition *this, ActionNode *action_node, ActionContext *action_context)
{
  __int64 v3; // rax
  signed __int64 v4; // rdi
  ActionContext *v5; // rsi
  SelectSuitableVehicleCondition *v6; // rbx
  UFG::ActionTreeComponentBase *v7; // rdx
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  __int64 v10; // rbp
  unsigned int v11; // eax
  bool v12; // zf
  __int64 v13; // rax
  UFG::ActionTreeComponentBase *v14; // rdx
  UFG::ActionTreeComponentBase *v15; // rcx
  UFG::SelectSuitableVehicle::Params params; // [rsp+20h] [rbp-28h]
  UFG::SimObject *value_uid; // [rsp+50h] [rbp+8h]

  v3 = this->m_MyRoot.mOffset;
  v4 = 0i64;
  v5 = action_context;
  v6 = this;
  value_uid = 0i64;
  if ( v3 )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v3);
  else
    v7 = 0i64;
  if ( v3 )
    v8 = (char *)&this->m_MyRoot + v3;
  else
    v8 = 0i64;
  v9 = action_context->mActionTreeComponentBase[v8[236]];
  if ( !v9 )
    v9 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
    v9,
    v7,
    (ActionNodeRoot *)v6->m_VehicleUID,
    (__int64)&value_uid);
  v10 = (__int64)value_uid;
  v11 = v6->m_FilterClassSymbol.mUID;
  params.maxSearchRadius = v6->m_MaxSearchRadius;
  v12 = v6->m_IgnoreMeshTest == 0;
  params.pVehicle = value_uid;
  params.filterClassSymbol.mUID = v11;
  params.pActionContext = v5;
  params.ignoreMeshTest = !v12;
  UFG::SelectSuitableVehicle::Cleanup(&params);
  v13 = v6->m_MyRoot.mOffset;
  if ( v13 )
    v14 = (UFG::ActionTreeComponentBase *)((char *)&v6->m_MyRoot + v13);
  else
    v14 = 0i64;
  if ( v13 )
    v4 = (signed __int64)&v6->m_MyRoot + v13;
  v15 = v5->mActionTreeComponentBase[*(char *)(v4 + 236)];
  if ( !v15 )
    v15 = v5->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(v15, v14, (ActionNodeRoot *)v6->m_VehicleUID, v10);
}

// File Line: 5417
// RVA: 0x372440
__int64 __fastcall SelectSuitableVehicleCondition::Match(SelectSuitableVehicleCondition *this, ActionContext *action_context)
{
  __int64 v2; // rax
  signed __int64 v3; // rdi
  ActionContext *v4; // rsi
  SelectSuitableVehicleCondition *v5; // rbx
  UFG::ActionTreeComponentBase *v6; // rdx
  char *v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rcx
  bool v9; // zf
  int v10; // xmm6_4
  unsigned int v11; // eax
  __int64 v12; // rax
  UFG::ActionTreeComponentBase *v13; // rdx
  signed __int64 v14; // rcx
  UFG::ActionTreeComponentBase *v15; // rcx
  unsigned int v16; // er9
  __int64 v17; // rax
  UFG::ActionTreeComponentBase *v18; // rdx
  signed __int64 v19; // rcx
  UFG::ActionTreeComponentBase *v20; // rcx
  __int64 v21; // rax
  UFG::ActionTreeComponentBase *v22; // rdx
  signed __int64 v23; // rcx
  UFG::ActionTreeComponentBase *v24; // rcx
  __int64 v25; // rax
  UFG::ActionTreeComponentBase *v26; // rdx
  signed __int64 v27; // rcx
  UFG::ActionTreeComponentBase *v28; // rcx
  unsigned __int8 v29; // al
  __int64 v30; // rcx
  unsigned int v31; // er9
  UFG::ActionTreeComponentBase *v32; // rdx
  signed __int64 v33; // rax
  UFG::ActionTreeComponentBase *v34; // rcx
  unsigned int v35; // er9
  __int64 v36; // rax
  UFG::ActionTreeComponentBase *v37; // rdx
  signed __int64 v38; // rcx
  UFG::ActionTreeComponentBase *v39; // rcx
  __int64 v40; // rax
  UFG::ActionTreeComponentBase *v41; // rdx
  signed __int64 v42; // rcx
  UFG::ActionTreeComponentBase *v43; // rcx
  __int64 v44; // rax
  UFG::ActionTreeComponentBase *v45; // rdx
  UFG::ActionTreeComponentBase *v46; // rcx
  unsigned int value_uid[2]; // [rsp+20h] [rbp-48h]
  UFG::SelectSuitableVehicle::Params params; // [rsp+28h] [rbp-40h]
  unsigned int v50; // [rsp+90h] [rbp+28h]
  unsigned int v51; // [rsp+98h] [rbp+30h]
  unsigned int v52; // [rsp+A0h] [rbp+38h]
  unsigned int v53; // [rsp+A8h] [rbp+40h]

  v2 = this->m_MyRoot.mOffset;
  v3 = 0i64;
  v4 = action_context;
  v5 = this;
  *(_QWORD *)value_uid = 0i64;
  if ( v2 )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v2);
  else
    v6 = 0i64;
  if ( v2 )
    v7 = (char *)&this->m_MyRoot + v2;
  else
    v7 = 0i64;
  v8 = v4->mActionTreeComponentBase[v7[236]];
  if ( !v8 )
    v8 = v4->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
    v8,
    v6,
    (ActionNodeRoot *)v5->m_VehicleUID,
    (__int64)value_uid);
  v9 = v5->m_IgnoreMeshTest == 0;
  v10 = SLODWORD(UFG::Metrics::msInstance.mSimTime_Temp);
  params.maxSearchRadius = v5->m_MaxSearchRadius;
  params.pVehicle = *(UFG::SimObject **)value_uid;
  v11 = v5->m_FilterClassSymbol.mUID;
  params.ignoreMeshTest = !v9;
  params.filterClassSymbol.mUID = v11;
  v12 = v5->m_MyRoot.mOffset;
  params.pActionContext = v4;
  *(float *)&v51 = -99999.0;
  if ( v12 )
    v13 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v12);
  else
    v13 = 0i64;
  if ( v12 )
    v14 = (signed __int64)&v5->m_MyRoot + v12;
  else
    v14 = 0i64;
  v15 = v4->mActionTreeComponentBase[*(char *)(v14 + 236)];
  if ( !v15 )
    v15 = v4->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v15,
    v13,
    (ActionNodeRoot *)v5->m_LastTimeMatchCalledUID,
    (__int64)&v51);
  if ( (float)(*(float *)&v10 - *(float *)&v51) > v5->m_TimeBeforeReset )
  {
    UFG::SelectSuitableVehicle::Cleanup(&params);
    UFG::SelectSuitableVehicle::SelectVehicle(&params);
  }
  v17 = v5->m_MyRoot.mOffset;
  if ( v17 )
    v18 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v17);
  else
    v18 = 0i64;
  if ( v17 )
    v19 = (signed __int64)&v5->m_MyRoot + v17;
  else
    v19 = 0i64;
  v20 = v4->mActionTreeComponentBase[*(char *)(v19 + 236)];
  if ( !v20 )
    v20 = v4->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
    v20,
    v18,
    (ActionNodeRoot *)v5->m_LastTimeMatchCalledUID,
    v16,
    v10);
  v21 = v5->m_MyRoot.mOffset;
  *(float *)&v52 = -99999.0;
  *(float *)&v53 = -99999.0;
  if ( v21 )
    v22 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v21);
  else
    v22 = 0i64;
  if ( v21 )
    v23 = (signed __int64)&v5->m_MyRoot + v21;
  else
    v23 = 0i64;
  v24 = v4->mActionTreeComponentBase[*(char *)(v23 + 236)];
  if ( !v24 )
    v24 = v4->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v24,
    v22,
    (ActionNodeRoot *)v5->m_LastTimeUpdateCalledUID,
    (__int64)&v52);
  v25 = v5->m_MyRoot.mOffset;
  if ( v25 )
    v26 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v25);
  else
    v26 = 0i64;
  if ( v25 )
    v27 = (signed __int64)&v5->m_MyRoot + v25;
  else
    v27 = 0i64;
  v28 = v4->mActionTreeComponentBase[*(char *)(v27 + 236)];
  if ( !v28 )
    v28 = v4->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v28,
    v26,
    (ActionNodeRoot *)v5->m_TimeBetweenUpdatesUID,
    (__int64)&v53);
  LOBYTE(v50) = 0;
  if ( (float)(*(float *)&v10 - *(float *)&v52) <= *(float *)&v53 )
  {
    v40 = v5->m_MyRoot.mOffset;
    if ( v40 )
      v41 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v40);
    else
      v41 = 0i64;
    if ( v40 )
      v42 = (signed __int64)&v5->m_MyRoot + v40;
    else
      v42 = 0i64;
    v43 = v4->mActionTreeComponentBase[*(char *)(v42 + 236)];
    if ( !v43 )
      v43 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
      v43,
      v41,
      (ActionNodeRoot *)v5->m_PreviousReturnValueUID,
      (__int64)&v50);
  }
  else
  {
    v29 = UFG::SelectSuitableVehicle::Update(&params);
    v30 = v5->m_MyRoot.mOffset;
    v31 = v29;
    LOBYTE(v50) = v29;
    if ( v30 )
      v32 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v30);
    else
      v32 = 0i64;
    if ( v30 )
      v33 = (signed __int64)&v5->m_MyRoot + v30;
    else
      v33 = 0i64;
    v34 = v4->mActionTreeComponentBase[*(char *)(v33 + 236)];
    if ( !v34 )
      v34 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v34,
      v32,
      (ActionNodeRoot *)v5->m_PreviousReturnValueUID,
      v31);
    v36 = v5->m_MyRoot.mOffset;
    if ( v36 )
      v37 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v36);
    else
      v37 = 0i64;
    if ( v36 )
      v38 = (signed __int64)&v5->m_MyRoot + v36;
    else
      v38 = 0i64;
    v39 = v4->mActionTreeComponentBase[*(char *)(v38 + 236)];
    if ( !v39 )
      v39 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v39,
      v37,
      (ActionNodeRoot *)v5->m_LastTimeUpdateCalledUID,
      v35,
      v10);
  }
  v44 = v5->m_MyRoot.mOffset;
  if ( v44 )
    v45 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v44);
  else
    v45 = 0i64;
  if ( v44 )
    v3 = (signed __int64)&v5->m_MyRoot + v44;
  v46 = v4->mActionTreeComponentBase[*(char *)(v3 + 236)];
  if ( !v46 )
    v46 = v4->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
    v46,
    v45,
    (ActionNodeRoot *)v5->m_VehicleUID,
    (__int64)params.pVehicle);
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
  ScriptFakeHasHostageCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ScriptFakeHasHostageCondition::`vftable';
}

// File Line: 5534
// RVA: 0x33A9F0
void __fastcall ScriptFakeHasHostageCondition::~ScriptFakeHasHostageCondition(ScriptFakeHasHostageCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&ScriptFakeHasHostageCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5539
// RVA: 0x3723B0
bool __fastcall ScriptFakeHasHostageCondition::Match(ScriptFakeHasHostageCondition *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = v2->m_Components.p[5].m_pComponent)) : (v4 = v2->m_Components.p[5].m_pComponent),
        v4) )
  {
    result = (BYTE1(v4[32].m_BoundComponentHandles.mNode.mPrev) >> 5) & 1;
  }
  else
  {
    result = 0;
  }
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
  TargetVisibleInAIDataCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetVisibleInAIDataCondition::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 278;
  v1->m_MyRoot.mOffset = 0i64;
  v1->m_MinTimeBetweenChecks = 0.2;
  *(_QWORD *)&v1->m_MaxTimeBetweenChecks = 1053609165i64;
  *(_QWORD *)&v1->m_NextTimeToCheckTargetIsVisibleUID = 0i64;
}

// File Line: 5583
// RVA: 0x33B6B0
void __fastcall TargetVisibleInAIDataCondition::~TargetVisibleInAIDataCondition(TargetVisibleInAIDataCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetVisibleInAIDataCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5588
// RVA: 0x383CC0
void __fastcall TargetVisibleInAIDataCondition::ResolveReferences(TargetVisibleInAIDataCondition *this, ActionNode *action_node)
{
  TargetVisibleInAIDataCondition *v2; // rbx
  Expression::IMemberMap *v3; // rax
  signed __int64 v4; // rcx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx

  v2 = this;
  v3 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v4 = (signed __int64)&v2->m_MyRoot;
  if ( v3 )
    v3 = (Expression::IMemberMap *)((char *)v3 - v4);
  *(_QWORD *)v4 = v3;
  v5 = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_TargetIsVisibleUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  v6 = v2->m_NextTimeToCheckTargetIsVisibleUID;
  v2->m_TargetIsVisibleUID = v5;
  v7 = UFG::ActionTreeComponentBase::MakeValueUID(v6, 0);
  v8 = v2->m_PreviousTargetUID;
  v2->m_NextTimeToCheckTargetIsVisibleUID = v7;
  v2->m_PreviousTargetUID = UFG::ActionTreeComponentBase::MakeValueUID(
                              v8,
                              eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
}

// File Line: 5602
// RVA: 0x3740C0
__int64 __fastcall TargetVisibleInAIDataCondition::Match(TargetVisibleInAIDataCondition *this, ActionContext *action_context)
{
  TargetVisibleInAIDataCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  signed __int64 v4; // rdi
  ActionContext *v5; // rsi
  float v6; // xmm6_4
  UFG::ActiveAIEntityComponent *v7; // r15
  unsigned __int16 v8; // dx
  UFG::ActiveAIEntityComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  UFG::SimComponent *v11; // r14
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  __int64 v14; // r12
  __int64 v15; // rax
  UFG::ActionTreeComponentBase *v16; // rdx
  signed __int64 v17; // rcx
  UFG::ActionTreeComponentBase *v18; // rcx
  __int64 v19; // rax
  UFG::ActionTreeComponentBase *v20; // rdx
  signed __int64 v21; // rcx
  UFG::ActionTreeComponentBase *v22; // rcx
  bool v23; // al
  unsigned int v24; // er9
  float v25; // xmm0_4
  __int64 v26; // rax
  int v27; // xmm0_4
  UFG::ActionTreeComponentBase *v28; // rdx
  signed __int64 v29; // rcx
  UFG::ActionTreeComponentBase *v30; // rcx
  __int64 v31; // rax
  UFG::ActionTreeComponentBase *v32; // rdx
  signed __int64 v33; // rcx
  UFG::ActionTreeComponentBase *v34; // rcx
  __int64 v35; // r14
  __int64 v36; // r14
  unsigned int v37; // xmm1_4
  UFG::SimObject *v38; // rcx
  int v39; // er14
  UFG::SimComponent *v40; // rdx
  UFG::NavManagerVtbl *v41; // rax
  bool v42; // zf
  unsigned int v43; // er9
  __int64 v44; // rax
  UFG::ActionTreeComponentBase *v45; // rdx
  signed __int64 v46; // rcx
  UFG::ActionTreeComponentBase *v47; // rcx
  __m128 v48; // xmm0
  signed __int64 v49; // rcx
  __int64 v50; // rax
  UFG::ActionTreeComponentBase *v51; // rdx
  UFG::ActionTreeComponentBase *v52; // rcx
  float v54; // [rsp+18h] [rbp-19h]
  unsigned __int64 v55; // [rsp+1Ch] [rbp-15h]
  UFG::qVector3 v56; // [rsp+28h] [rbp-9h]
  UFG::qVector3 v57; // [rsp+38h] [rbp+7h]
  unsigned int v58; // [rsp+98h] [rbp+67h]
  unsigned int vars0; // [rsp+A0h] [rbp+6Fh]
  __int64 retaddr; // [rsp+A8h] [rbp+77h]
  __int64 value_uid; // [rsp+B0h] [rbp+7Fh]

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = action_context;
  v6 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v3 )
  {
    v8 = v3->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v7 = v9;
  }
  else
  {
    v7 = 0i64;
  }
  v10 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v10 )
  {
    v12 = v10->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v11 = v10->m_Components.p[20].m_pComponent;
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v13 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v10->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v11 = v13;
    }
    else
    {
      v11 = v10->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v11 = 0i64;
  }
  if ( v7 && v11 )
  {
    v14 = *(_QWORD *)(56i64
                    * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue + *(_QWORD *)&v11[1].m_Flags + 8i64)
                    + *(_QWORD *)&v11[1].m_TypeUID
                    + 40);
    v15 = v2->m_MyRoot.mOffset;
    *(float *)&vars0 = FLOAT_N99999_0;
    value_uid = 0i64;
    if ( v15 )
      v16 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v15);
    else
      v16 = 0i64;
    if ( v15 )
      v17 = (signed __int64)&v2->m_MyRoot + v15;
    else
      v17 = 0i64;
    v18 = v5->mActionTreeComponentBase[*(char *)(v17 + 236)];
    if ( !v18 )
      v18 = v5->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
      v18,
      v16,
      (ActionNodeRoot *)v2->m_PreviousTargetUID,
      (__int64)&value_uid);
    v19 = v2->m_MyRoot.mOffset;
    if ( v19 )
      v20 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v19);
    else
      v20 = 0i64;
    if ( v19 )
      v21 = (signed __int64)&v2->m_MyRoot + v19;
    else
      v21 = 0i64;
    v22 = v5->mActionTreeComponentBase[*(char *)(v21 + 236)];
    if ( !v22 )
      v22 = v5->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
      v22,
      v20,
      (ActionNodeRoot *)v2->m_NextTimeToCheckTargetIsVisibleUID,
      (__int64)&vars0);
    v23 = v6 > *(float *)&vars0 || v14 != value_uid;
    if ( v14 && v23 )
    {
      v25 = UFG::GetRandomNumberInRange(v2->m_MinTimeBetweenChecks, v2->m_MaxTimeBetweenChecks);
      v26 = v2->m_MyRoot.mOffset;
      *(float *)&v27 = v25 + v6;
      if ( v26 )
        v28 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v26);
      else
        v28 = 0i64;
      if ( v26 )
        v29 = (signed __int64)&v2->m_MyRoot + v26;
      else
        v29 = 0i64;
      v30 = v5->mActionTreeComponentBase[*(char *)(v29 + 236)];
      if ( !v30 )
        v30 = v5->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
        v30,
        v28,
        (ActionNodeRoot *)v2->m_NextTimeToCheckTargetIsVisibleUID,
        v24,
        v27);
      v31 = v2->m_MyRoot.mOffset;
      if ( v31 )
        v32 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v31);
      else
        v32 = 0i64;
      if ( v31 )
        v33 = (signed __int64)&v2->m_MyRoot + v31;
      else
        v33 = 0i64;
      v34 = v5->mActionTreeComponentBase[*(char *)(v33 + 236)];
      if ( !v34 )
        v34 = v5->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
        v34,
        v32,
        (ActionNodeRoot *)v2->m_PreviousTargetUID,
        v14);
      v35 = *(_QWORD *)(56i64
                      * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue + *(_QWORD *)&v11[1].m_Flags + 8i64)
                      + *(_QWORD *)&v11[1].m_TypeUID
                      + 40);
      if ( v35 )
      {
        v36 = *(_QWORD *)(v35 + 88);
        if ( v36 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v36);
          v37 = *(_DWORD *)(v36 + 180);
          v54 = *(float *)(v36 + 176);
          v55 = __PAIR__(*(_DWORD *)(v36 + 184), v37);
          if ( use_nearest_point )
          {
            v56 = UFG::qVector3::msZero;
            if ( ((unsigned __int8 (__fastcall *)(UFG::NavManager *, float *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->GetClosestAIMesh)(
                   UFG::NavManager::ms_pInstance,
                   &v54,
                   &v56) )
            {
              v54 = v56.x;
              v55 = *(_QWORD *)&v56.y;
            }
          }
          v38 = v7->m_pSimObject;
          v39 = (unsigned __int8)v2->m_ConstrainToSidewalks.mValue;
          v57 = UFG::qVector3::msZero;
          if ( v38 )
            v40 = UFG::SimObject::GetComponentOfType(v38, UFG::NavComponent::_TypeUID);
          else
            v40 = 0i64;
          retaddr = *(__int64 *)((char *)&v40[2].m_BoundComponentHandles.mNode.mNext + 4);
          if ( v39 )
            HIDWORD(retaddr) |= 0x200u;
          else
            HIDWORD(retaddr) = (*(_QWORD *)((char *)&v40[2].m_BoundComponentHandles.mNode.mNext + 4) >> 32) & 0xFFFFFDFF;
          v41 = UFG::NavManager::ms_pInstance->vfptr;
          *(unsigned __int64 *)((char *)&v55 + 4) = (unsigned __int64)&v57;
          v42 = ((unsigned __int8 (__fastcall *)(UFG::NavManager *, UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **, float *, __int64 *))v41->AIRayCastHits)(
                  UFG::NavManager::ms_pInstance,
                  &v40[1].m_SafePointerList.mNode.mNext,
                  &v54,
                  &retaddr) == 0;
          v44 = v2->m_MyRoot.mOffset;
          if ( v42 )
          {
            if ( v44 )
              v45 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v44);
            else
              v45 = 0i64;
            if ( v44 )
              v46 = (signed __int64)&v2->m_MyRoot + v44;
            else
              v46 = 0i64;
            v47 = v5->mActionTreeComponentBase[*(char *)(v46 + 236)];
            if ( !v47 )
              v47 = v5->mActionTreeComponentBase[1];
            LOBYTE(v43) = 1;
          }
          else
          {
            v48 = (__m128)(unsigned int)v55;
            v48.m128_f32[0] = (float)((float)(*(float *)&v55 - v57.y) * (float)(*(float *)&v55 - v57.y))
                            + (float)((float)(v54 - v57.x) * (float)(v54 - v57.x));
            LOBYTE(v43) = COERCE_FLOAT(_mm_sqrt_ps(v48)) < 0.30000001;
            if ( v44 )
              v45 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v44);
            else
              v45 = 0i64;
            if ( v44 )
              v49 = (signed __int64)&v2->m_MyRoot + v44;
            else
              v49 = 0i64;
            v47 = v5->mActionTreeComponentBase[*(char *)(v49 + 236)];
            if ( !v47 )
              v47 = v5->mActionTreeComponentBase[1];
          }
          UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
            v47,
            v45,
            (ActionNodeRoot *)v2->m_TargetIsVisibleUID,
            v43);
        }
      }
    }
  }
  v50 = v2->m_MyRoot.mOffset;
  LOBYTE(v58) = 0;
  if ( v50 )
    v51 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v50);
  else
    v51 = 0i64;
  if ( v50 )
    v4 = (signed __int64)&v2->m_MyRoot + v50;
  v52 = v5->mActionTreeComponentBase[*(char *)(v4 + 236)];
  if ( !v52 )
    v52 = v5->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v52,
    v51,
    (ActionNodeRoot *)v2->m_TargetIsVisibleUID,
    (__int64)&v58);
  return (unsigned __int8)v58;
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
  TargetIsEnemyOfMineCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetIsEnemyOfMineCondition::`vftable';
  v1->m_TargetType.mValue = 22;
}

// File Line: 5719
// RVA: 0x33B670
void __fastcall TargetIsEnemyOfMineCondition::~TargetIsEnemyOfMineCondition(TargetIsEnemyOfMineCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsEnemyOfMineCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5724
// RVA: 0x372FF0
bool __fastcall TargetIsEnemyOfMineCondition::Match(TargetIsEnemyOfMineCondition *this, ActionContext *action_context)
{
  TargetIsEnemyOfMineCondition *v2; // rbp
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  ActionContext *v5; // rsi
  UFG::ActiveAIEntityComponent *v6; // rdi
  unsigned __int16 v7; // dx
  UFG::ActiveAIEntityComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = action_context;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v6 = v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v4 = v9->m_Components.p[20].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v11 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v9->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v4 = v11;
    }
    else
    {
      v4 = v9->m_Components.p[20].m_pComponent;
    }
  }
  if ( v6 && v4 )
    result = UFG::ActiveAIEntityComponent::IsEnemyOfMine(
               v6,
               *(UFG::SimObject **)(56i64
                                  * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                                       + *(_QWORD *)&v4[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v4[1].m_TypeUID
                                  + 40));
  else
    result = 0;
  return result;
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
  CombatRegionExistsCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionExistsCondition::`vftable';
}

// File Line: 5759
// RVA: 0x335C60
void __fastcall CombatRegionExistsCondition::~CombatRegionExistsCondition(CombatRegionExistsCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionExistsCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5763
// RVA: 0x36F160
bool __fastcall CombatRegionExistsCondition::Match(CombatRegionExistsCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v4; // dx
  unsigned int v5; // edx
  bool v6; // zf

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( !v2 )
    return MEMORY[0x3D8] != 0i64;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 || (v4 & 0x8000u) != 0 )
    return UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2)->m_pCombatRegion.m_pPointer != 0i64;
  if ( (v4 >> 13) & 1 )
  {
    v5 = UFG::ActiveAIEntityComponent::_TypeUID;
    return *(_QWORD *)&UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, v5)[15].m_TypeUID != 0i64;
  }
  v6 = ((v4 >> 12) & 1) == 0;
  v5 = UFG::ActiveAIEntityComponent::_TypeUID;
  if ( !v6 )
    return *(_QWORD *)&UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, v5)[15].m_TypeUID != 0i64;
  return *(_QWORD *)&UFG::SimObject::GetComponentOfType(
                       (UFG::SimObject *)&v2->vfptr,
                       UFG::ActiveAIEntityComponent::_TypeUID)[15].m_TypeUID != 0i64;
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
  CombatRegionIsInsideCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionIsInsideCondition::`vftable';
}

// File Line: 5795
// RVA: 0x335CA0
void __fastcall CombatRegionIsInsideCondition::~CombatRegionIsInsideCondition(CombatRegionIsInsideCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionIsInsideCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5799
// RVA: 0x36F200
bool __fastcall CombatRegionIsInsideCondition::Match(CombatRegionIsInsideCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  UFG::ActiveAIEntityComponent *v3; // rax
  UFG::TransformNodeComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::CombatRegion *v6; // rdi
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  UFG::qVector3 vPoint; // [rsp+20h] [rbp-48h]

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = 0i64;
  if ( v2 )
  {
    v5 = v2->m_Flags;
    v4 = v2->m_pTransformNodeComponent;
    if ( (v5 >> 14) & 1 )
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v3 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v3 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
  }
  v6 = v3->m_pCombatRegion.m_pPointer;
  if ( !v6 )
    return 1;
  v7 = UFG::qVector3::msAxisZ.x;
  v8 = UFG::qVector3::msAxisZ.y;
  v9 = UFG::qVector3::msAxisZ.z;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v10 = v8 + v4->mWorldTransform.v3.y;
  v11 = v9 + v4->mWorldTransform.v3.z;
  vPoint.x = v7 + v4->mWorldTransform.v3.x;
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
void __fastcall CombatRegionTargetIsInsideCondition::CombatRegionTargetIsInsideCondition(CombatRegionTargetIsInsideCondition *this)
{
  CombatRegionTargetIsInsideCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionTargetIsInsideCondition::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->m_FixZForCharacter = 1;
}

// File Line: 5847
// RVA: 0x335CE0
void __fastcall CombatRegionTargetIsInsideCondition::~CombatRegionTargetIsInsideCondition(CombatRegionTargetIsInsideCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionTargetIsInsideCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5851
// RVA: 0x36F320
bool __fastcall CombatRegionTargetIsInsideCondition::Match(CombatRegionTargetIsInsideCondition *this, ActionContext *action_context)
{
  CombatRegionTargetIsInsideCondition *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  UFG::ActiveAIEntityComponent *v4; // rbx
  ActionContext *v5; // rsi
  UFG::SimComponent *v6; // rdi
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::SimObjectCVBase *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::ActiveAIEntityComponent *v11; // rax
  UFG::CombatRegion *v12; // rsi
  __int64 v13; // rbx
  UFG::RegionComponent *v14; // rax
  UFG::TransformNodeComponent *v15; // rbx
  bool v16; // zf
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qVector3 vPoint; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = action_context;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v6 = v8;
    }
    else
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v6 = 0i64;
  }
  v9 = (UFG::SimObjectCVBase *)v5->mSimObject.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v9->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    }
    v4 = v11;
  }
  if ( !v6 )
    return 0;
  if ( !v4 )
    return 0;
  v12 = v4->m_pCombatRegion.m_pPointer;
  v13 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(v2->m_TargetType.mValue + *(_QWORD *)&v6[1].m_Flags + 8i64)
                  + *(_QWORD *)&v6[1].m_TypeUID
                  + 40);
  if ( !v13 )
    return 0;
  if ( !v12 )
    return 1;
  v14 = v12->mpRegion;
  if ( !v14 || !v14->mpRegion.mPtr )
    return 1;
  v15 = *(UFG::TransformNodeComponent **)(v13 + 88);
  if ( !v15 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v15);
  v16 = v2->m_FixZForCharacter == 0;
  v17 = v15->mWorldTransform.v3.x;
  v18 = v15->mWorldTransform.v3.y;
  v19 = v15->mWorldTransform.v3.z;
  vPoint.x = v15->mWorldTransform.v3.x;
  vPoint.y = v18;
  vPoint.z = v19;
  if ( !v16 )
  {
    vPoint.x = v17 + UFG::qVector3::msAxisZ.x;
    vPoint.y = v18 + UFG::qVector3::msAxisZ.y;
    vPoint.z = v19 + UFG::qVector3::msAxisZ.z;
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
  IsInCrosswalkCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsInCrosswalkCondition::`vftable';
}

// File Line: 5912
// RVA: 0x338F90
void __fastcall IsInCrosswalkCondition::~IsInCrosswalkCondition(IsInCrosswalkCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&IsInCrosswalkCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5916
// RVA: 0x370E90
bool __fastcall IsInCrosswalkCondition::Match(IsInCrosswalkCondition *this, ActionContext *action_context)
{
  ActionContext *v2; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v3; // rax
  void *(__fastcall *v4)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  __int64 v5; // rcx
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::ActiveAIEntityComponent *v8; // rax
  bool result; // al
  UFG::SimObjectCVBase *v10; // rcx
  unsigned __int16 v11; // dx

  v2 = action_context;
  v3 = UFG::GroupComponent::GetGroupComponent(action_context->mSimObject.m_pPointer);
  if ( v3 )
  {
    v4 = v3[32].__vecDelDtor;
    if ( v4 )
    {
      v5 = *((_QWORD *)v4 + 33);
      if ( v5 )
      {
        v6 = *(UFG::SimObjectGame **)(v5 + 192);
        if ( v6 )
        {
          v7 = v6->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = (UFG::ActiveAIEntityComponent *)v6->m_Components.p[22].m_pComponent;
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
              v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v6,
                                                     UFG::AIEntityComponent::_TypeUID);
            else
              v8 = (UFG::ActiveAIEntityComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v6,
                                                                       UFG::AIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AIEntityComponent::_TypeUID));
          }
          else
          {
            v8 = (UFG::ActiveAIEntityComponent *)v6->m_Components.p[22].m_pComponent;
          }
          if ( v8 )
            goto LABEL_30;
        }
      }
    }
  }
  v10 = (UFG::SimObjectCVBase *)v2->mSimObject.m_pPointer;
  if ( v10
    && ((v11 = v10->m_Flags, !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::ActiveAIEntityComponent::_TypeUID)) : (v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v10->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v10->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v10))) : (v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v10)),
        v8) )
  {
LABEL_30:
    result = v8->m_WanderData.mAtCrossWalk;
  }
  else
  {
    result = 0;
  }
  return result;
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
  AttackRequestCanceledCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackRequestCanceledCondition::`vftable';
  v1->m_AttackType.mValue = 0;
}

// File Line: 5975
// RVA: 0x335330
void __fastcall AttackRequestCanceledCondition::~AttackRequestCanceledCondition(AttackRequestCanceledCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRequestCanceledCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 5980
// RVA: 0x36EFC0
bool __fastcall AttackRequestCanceledCondition::Match(AttackRequestCanceledCondition *this, ActionContext *action_context)
{
  AttackRequestCanceledCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HasAttackRequestComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID)),
                                                 v5 = v6) : (v5 = v3->m_Components.p[35].m_pComponent),
        v5) )
  {
    result = UFG::Metrics::msInstance.mSimTime_Temp < *((float *)&v5[1].m_BoundComponentHandles.mNode.mPrev
                                                      + (unsigned __int8)v2->m_AttackType.mValue);
  }
  else
  {
    result = 0;
  }
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
  HasAIDriverCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HasAIDriverCondition::`vftable';
}

// File Line: 6013
// RVA: 0x338150
void __fastcall HasAIDriverCondition::~HasAIDriverCondition(HasAIDriverCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&HasAIDriverCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 6018
// RVA: 0x3701B0
bool __fastcall HasAIDriverCondition::Match(HasAIDriverCondition *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v4; // dx
  unsigned int v5; // edx
  bool v6; // zf

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 || (v4 & 0x8000u) != 0 )
    return UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2) != 0i64;
  if ( (v4 >> 13) & 1 )
  {
    v5 = UFG::AiDriverComponent::_TypeUID;
    return UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, v5) != 0i64;
  }
  v6 = ((v4 >> 12) & 1) == 0;
  v5 = UFG::AiDriverComponent::_TypeUID;
  if ( !v6 )
    return UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, v5) != 0i64;
  return UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID) != 0i64;
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
  DriverFlagAvoidPedsCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagAvoidPedsCondition::`vftable';
  v1->m_FlagSet = 1;
}

// File Line: 6049
// RVA: 0x336330
void __fastcall DriverFlagAvoidPedsCondition::~DriverFlagAvoidPedsCondition(DriverFlagAvoidPedsCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagAvoidPedsCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 6054
// RVA: 0x36F9C0
bool __fastcall DriverFlagAvoidPedsCondition::Match(DriverFlagAvoidPedsCondition *this, ActionContext *action_context)
{
  DriverFlagAvoidPedsCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v5->m_bAvoidPeds == (v2->m_FlagSet != 0);
  }
  else
  {
    result = 0;
  }
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
void __fastcall DriverFlagAllowedToPassCondition::DriverFlagAllowedToPassCondition(DriverFlagAllowedToPassCondition *this)
{
  DriverFlagAllowedToPassCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagAllowedToPassCondition::`vftable';
  v1->m_FlagSet = 1;
}

// File Line: 6089
// RVA: 0x3362F0
void __fastcall DriverFlagAllowedToPassCondition::~DriverFlagAllowedToPassCondition(DriverFlagAllowedToPassCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagAllowedToPassCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 6094
// RVA: 0x36F920
bool __fastcall DriverFlagAllowedToPassCondition::Match(DriverFlagAllowedToPassCondition *this, ActionContext *action_context)
{
  DriverFlagAllowedToPassCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v5->m_bAllowedToPass == (v2->m_FlagSet != 0);
  }
  else
  {
    result = 0;
  }
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
void __fastcall DriverFlagStayOffSidewalkCondition::DriverFlagStayOffSidewalkCondition(DriverFlagStayOffSidewalkCondition *this)
{
  DriverFlagStayOffSidewalkCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagStayOffSidewalkCondition::`vftable';
  v1->m_FlagSet = 1;
}

// File Line: 6129
// RVA: 0x3363B0
void __fastcall DriverFlagStayOffSidewalkCondition::~DriverFlagStayOffSidewalkCondition(DriverFlagStayOffSidewalkCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagStayOffSidewalkCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 6134
// RVA: 0x36FB00
bool __fastcall DriverFlagStayOffSidewalkCondition::Match(DriverFlagStayOffSidewalkCondition *this, ActionContext *action_context)
{
  DriverFlagStayOffSidewalkCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v5->m_bStayOffSidewalk == (v2->m_FlagSet != 0);
  }
  else
  {
    result = 0;
  }
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
void __fastcall DriverFlagRespectSpeedLimitCondition::DriverFlagRespectSpeedLimitCondition(DriverFlagRespectSpeedLimitCondition *this)
{
  DriverFlagRespectSpeedLimitCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagRespectSpeedLimitCondition::`vftable';
  v1->m_FlagSet = 1;
}

// File Line: 6169
// RVA: 0x336370
void __fastcall DriverFlagRespectSpeedLimitCondition::~DriverFlagRespectSpeedLimitCondition(DriverFlagRespectSpeedLimitCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFlagRespectSpeedLimitCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 6174
// RVA: 0x36FA60
bool __fastcall DriverFlagRespectSpeedLimitCondition::Match(DriverFlagRespectSpeedLimitCondition *this, ActionContext *action_context)
{
  DriverFlagRespectSpeedLimitCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v5->m_bRespectSpeedLimit == (v2->m_FlagSet != 0);
  }
  else
  {
    result = 0;
  }
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
void __fastcall TargetDistanceRelativeDesiredRangeCondition::TargetDistanceRelativeDesiredRangeCondition(TargetDistanceRelativeDesiredRangeCondition *this)
{
  TargetDistanceRelativeDesiredRangeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetDistanceRelativeDesiredRangeCondition::`vftable';
  v1->m_eTargetType.mValue = 22;
  *(_QWORD *)&v1->m_eInEqualityOperator.mValue = 3i64;
  v1->m_fBuffer = 0.0;
  *(_WORD *)&v1->m_2DOnly = 0;
}

// File Line: 6223
// RVA: 0x372DE0
char __fastcall TargetDistanceRelativeDesiredRangeCondition::Match(TargetDistanceRelativeDesiredRangeCondition *this, ActionContext *pContext)
{
  TargetDistanceRelativeDesiredRangeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::TransformNodeComponent *v9; // rdi
  char v10; // al
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  char result; // al
  float v15; // xmm6_4
  unsigned int v16; // eax
  float v17; // xmm1_4
  UFG::InEqualityOperator v18; // ecx
  UFG::qMatrix44 matSimObject; // [rsp+20h] [rbp-68h]
  float outMinimumDesired; // [rsp+98h] [rbp+10h]
  float outMaximumDesired; // [rsp+A0h] [rbp+18h]
  float outDesired; // [rsp+A8h] [rbp+20h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(v2->m_eTargetType.mValue + *(_QWORD *)&v6[1].m_Flags + 8i64)
                          + *(_QWORD *)&v6[1].m_TypeUID
                          + 40);
  if ( !v8 )
    return 0;
  UFG::TargetingSystemBaseComponent::FindMatrix(v8, &matSimObject);
  v9 = (UFG::TransformNodeComponent *)v4->mSimObject.m_pPointer;
  if ( v9 )
    v9 = (UFG::TransformNodeComponent *)v9->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v10 = v2->m_2DOnly;
  v11 = v9->mWorldTransform.v3.x;
  v12 = v9->mWorldTransform.v3.y;
  v13 = v9->mWorldTransform.v3.z;
  if ( !v10 )
    goto LABEL_35;
  if ( v2->m_ZOnly )
    return 0;
  if ( v10 )
  {
    v15 = (float)((float)(v12 - matSimObject.v3.y) * (float)(v12 - matSimObject.v3.y))
        + (float)((float)(v11 - matSimObject.v3.x) * (float)(v11 - matSimObject.v3.x));
  }
  else
  {
LABEL_35:
    if ( v2->m_ZOnly )
      v15 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v13 - matSimObject.v3.z) & _xmm)
          * COERCE_FLOAT(COERCE_UNSIGNED_INT(v13 - matSimObject.v3.z) & _xmm);
    else
      v15 = (float)((float)((float)(v12 - matSimObject.v3.y) * (float)(v12 - matSimObject.v3.y))
                  + (float)((float)(v11 - matSimObject.v3.x) * (float)(v11 - matSimObject.v3.x)))
          + (float)((float)(v13 - matSimObject.v3.z) * (float)(v13 - matSimObject.v3.z));
  }
  UFG::GetDesiredRanges(v4->mSimObject.m_pPointer, &outMinimumDesired, &outMaximumDesired, &outDesired);
  v16 = v2->m_eAIDesiredRange.mValue;
  if ( v16 )
  {
    if ( v16 == 1 )
      v17 = outMaximumDesired;
    else
      v17 = outDesired;
  }
  else
  {
    v17 = outMinimumDesired;
  }
  v18 = v2->m_eInEqualityOperator.mValue;
  if ( (v18 - 2) & 0xFFFFFFFD )
    result = CompareFloat(v18, (float)(v17 - v2->m_fBuffer) * (float)(v17 - v2->m_fBuffer), v15);
  else
    result = CompareFloat(v18, (float)(v17 + v2->m_fBuffer) * (float)(v17 + v2->m_fBuffer), v15);
  return result;
}

