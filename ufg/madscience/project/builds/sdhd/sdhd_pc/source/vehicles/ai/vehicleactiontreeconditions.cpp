// File Line: 38
// RVA: 0x157B330
__int64 dynamic_initializer_for__CarModeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarModeCondition", 0xFFFFFFFF);
  CarModeCondition::sClassNameUID = result;
  return result;
}

// File Line: 44
// RVA: 0x667750
void __fastcall CarModeCondition::CarModeCondition(CarModeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarModeCondition::`vftable;
  this->mMode.mValue = 0;
}

// File Line: 49
// RVA: 0x680E30
bool __fastcall CarModeCondition::Match(CarModeCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
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
        && ComponentOfTypeHK->m_DrivingMode == (unsigned __int8)this->mMode.mValue;
  return result;
}

// File Line: 71
// RVA: 0x157B110
__int64 dynamic_initializer_for__CarEscortMode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarEscortMode", 0xFFFFFFFF);
  CarEscortMode::sClassNameUID = result;
  return result;
}

// File Line: 76
// RVA: 0x6671F0
void __fastcall CarEscortMode::CarEscortMode(CarEscortMode *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarEscortMode::`vftable;
  this->mEscortMode.mValue = 0;
}

// File Line: 80
// RVA: 0x680600
bool __fastcall CarEscortMode::Match(CarEscortMode *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
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
        && ComponentOfTypeHK->m_EscortInfo.eEscortMode == (unsigned __int8)this->mEscortMode.mValue;
  return result;
}

// File Line: 99
// RVA: 0x157B070
__int64 dynamic_initializer_for__CarAtOffset::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarAtOffset", 0xFFFFFFFF);
  CarAtOffset::sClassNameUID = result;
  return result;
}

// File Line: 109
// RVA: 0x667090
void __fastcall CarAtOffset::CarAtOffset(CarAtOffset *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarAtOffset::`vftable;
  this->mTime = 0.0;
  *(_WORD *)&this->mPosition.mValue = 768;
}

// File Line: 114
// RVA: 0x680310
bool __fastcall CarAtOffset::Match(CarAtOffset *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
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
        && UFG::AiDriverComponent::GetTimeAtOffset(
             ComponentOfTypeHK,
             (CarCombat::Position)(unsigned __int8)this->mPosition.mValue) > this->mTime;
  return result;
}

// File Line: 136
// RVA: 0x157B090
__int64 dynamic_initializer_for__CarAttackStat::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarAttackStat", 0xFFFFFFFF);
  CarAttackStat::sClassNameUID = result;
  return result;
}

// File Line: 144
// RVA: 0x6670D0
void __fastcall CarAttackStat::CarAttackStat(CarAttackStat *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarAttackStat::`vftable;
  this->mAttackType.mValue = 0;
  this->mNumAttacks = 0;
}

// File Line: 149
// RVA: 0x6803B0
bool __fastcall CarAttackStat::Match(CarAttackStat *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
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
        && ComponentOfTypeHK->m_CombatStats.mNumAttacks[(unsigned __int8)this->mAttackType.mValue] >= this->mNumAttacks;
  return result;
}

// File Line: 169
// RVA: 0x157B2F0
__int64 dynamic_initializer_for__CarLastAttack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarLastAttack", 0xFFFFFFFF);
  CarLastAttack::sClassNameUID = result;
  return result;
}

// File Line: 177
// RVA: 0x6676D0
void __fastcall CarLastAttack::CarLastAttack(CarLastAttack *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarLastAttack::`vftable;
  this->mAttackType.mValue = 0;
  this->mAttackTime = 0.0;
}

// File Line: 182
// RVA: 0x680CD0
bool __fastcall CarLastAttack::Match(CarLastAttack *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
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
        && this->mAttackTime < ComponentOfTypeHK->m_CombatStats.mLastAttack[(unsigned __int8)this->mAttackType.mValue];
  return result;
}

// File Line: 202
// RVA: 0x157B190
__int64 dynamic_initializer_for__CarFormationAttackStat::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationAttackStat", 0xFFFFFFFF);
  CarFormationAttackStat::sClassNameUID = result;
  return result;
}

// File Line: 210
// RVA: 0x667270
void __fastcall CarFormationAttackStat::CarFormationAttackStat(CarFormationAttackStat *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAttackStat::`vftable;
  this->mAttackType.mValue = 0;
  this->mNumAttacks = 0;
}

// File Line: 215
// RVA: 0x680780
bool __fastcall CarFormationAttackStat::Match(CarFormationAttackStat *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID))
            : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID)))
           : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent))
          : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent),
            ComponentOfTypeHK
         && (CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(ComponentOfTypeHK)) != 0i64)
        && *((_DWORD *)&CarChaseTargetFormation[35].mPrev + (unsigned __int8)this->mAttackType.mValue + 1) >= this->mNumAttacks;
  return result;
}

// File Line: 239
// RVA: 0x157B0F0
__int64 dynamic_initializer_for__CarDistanceToEscortEnemy::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarDistanceToEscortEnemy", 0xFFFFFFFF);
  CarDistanceToEscortEnemy::sClassNameUID = result;
  return result;
}

// File Line: 247
// RVA: 0x6671B0
void __fastcall CarDistanceToEscortEnemy::CarDistanceToEscortEnemy(CarDistanceToEscortEnemy *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarDistanceToEscortEnemy::`vftable;
  this->mInEqualityOperator.mValue = 4;
  this->mDistance = 10.0;
}

// File Line: 252
// RVA: 0x6804E0
char __fastcall CarDistanceToEscortEnemy::Match(CarDistanceToEscortEnemy *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::AiDriverComponent *v6; // rax
  UFG::qBaseNodeRB *EscortEnemy; // rbx
  UFG::qVector3 v9; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
  else
    v6 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      m_pPointer,
                                      UFG::AiDriverComponent::_TypeUID)
                                  : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AiDriverComponent::_TypeUID));
  if ( !v6 )
    return 0;
  EscortEnemy = UFG::AiDriverComponent::GetEscortEnemy(v6);
  if ( !EscortEnemy )
    return 0;
  UFG::GetPosition(&result, (UFG::SimObjectGame *)context->mSimObject.m_pPointer);
  UFG::GetPosition(&v9, (UFG::SimObjectGame *)EscortEnemy);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mDistance * this->mDistance,
           (float)((float)((float)(v9.y - result.y) * (float)(v9.y - result.y))
                 + (float)((float)(v9.x - result.x) * (float)(v9.x - result.x)))
         + (float)((float)(v9.z - result.z) * (float)(v9.z - result.z)));
}

// File Line: 280
// RVA: 0x157B310
__int64 dynamic_initializer_for__CarLastFormationAttack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarLastFormationAttack", 0xFFFFFFFF);
  CarLastFormationAttack::sClassNameUID = result;
  return result;
}

// File Line: 288
// RVA: 0x667710
void __fastcall CarLastFormationAttack::CarLastFormationAttack(CarLastFormationAttack *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarLastFormationAttack::`vftable;
  this->mAttackType.mValue = 0;
  this->mAttackTime = 0.0;
}

// File Line: 293
// RVA: 0x680D70
bool __fastcall CarLastFormationAttack::Match(CarLastFormationAttack *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID))
            : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID)))
           : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent))
          : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent),
            ComponentOfTypeHK
         && (CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(ComponentOfTypeHK)) != 0i64)
        && this->mAttackTime < *((float *)&CarChaseTargetFormation[34].mPrev
                               + (unsigned __int8)this->mAttackType.mValue
                               + 1);
  return result;
}

// File Line: 315
// RVA: 0x157B570
__int64 dynamic_initializer_for__CarWithinRange::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarWithinRange", 0xFFFFFFFF);
  CarWithinRange::sClassNameUID = result;
  return result;
}

// File Line: 321
// RVA: 0x667C10
void __fastcall CarWithinRange::CarWithinRange(CarWithinRange *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarWithinRange::`vftable;
  this->mRange = 0.0;
}

// File Line: 326
// RVA: 0x6816E0
char __fastcall CarWithinRange::Match(CarWithinRange *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdi
  UFG::SimObjectGame *m_pSimObject; // rcx
  char v9; // bl
  __int16 v10; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  float v13; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  mPrev = m_pComponent[26].m_SafePointerList.mNode.mPrev;
  if ( !mPrev )
    return *(float *)&m_pComponent[29].m_pSimObject < this->mRange;
  m_pSimObject = (UFG::SimObjectGame *)m_pComponent[26].m_pSimObject;
  v9 = 0;
  if ( m_pSimObject
    && ((v10 = m_pSimObject->m_Flags, (v10 & 0x4000) == 0)
      ? (v10 >= 0
       ? ((v10 & 0x2000) != 0 || (v10 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RoadSpaceComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pSimObject->m_Components.p[24].m_pComponent))
      : (ComponentOfTypeHK = m_pSimObject->m_Components.p[24].m_pComponent),
        ComponentOfTypeHK) )
  {
    v12 = ComponentOfTypeHK[26].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    v12 = 0i64;
  }
  if ( !v12 )
    return 0;
  v13 = *(float *)&v12[3].mPrev - *(float *)&mPrev[3].mPrev;
  if ( v13 >= -5.0 && v13 <= this->mRange )
    return 1;
  return v9;
}

// File Line: 354
// RVA: 0x157B1D0
__int64 dynamic_initializer_for__CarFormationAvailable::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationAvailable", 0xFFFFFFFF);
  CarFormationAvailable::sClassNameUID = result;
  return result;
}

// File Line: 360
// RVA: 0x667350
void __fastcall CarFormationAvailable::CarFormationAvailable(CarFormationAvailable *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAvailable::`vftable;
  this->mAvailable = 0;
}

// File Line: 364
// RVA: 0x680840
bool __fastcall CarFormationAvailable::Match(CarFormationAvailable *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::RoadSpaceComponent::_TypeUID))
        : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::RoadSpaceComponent::_TypeUID)))
       : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent))
      : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent),
        ComponentOfTypeHK
     && (CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(ComponentOfTypeHK)) != 0i64) )
  {
    return HIBYTE(CarChaseTargetFormation[38].mPrev);
  }
  else
  {
    return 0;
  }
}

// File Line: 385
// RVA: 0x157B170
__int64 dynamic_initializer_for__CarFormationAssignedPosition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationAssignedPosition", 0xFFFFFFFF);
  CarFormationAssignedPosition::sClassNameUID = result;
  return result;
}

// File Line: 391
// RVA: 0x667230
void __fastcall CarFormationAssignedPosition::CarFormationAssignedPosition(CarFormationAssignedPosition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAssignedPosition::`vftable;
  this->mPosition.mValue = 0;
}

// File Line: 395
// RVA: 0x6806A0
bool __fastcall CarFormationAssignedPosition::Match(CarFormationAssignedPosition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::RoadSpaceComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  UFG::SimObject *v8; // r8

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (UFG::RoadSpaceComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::RoadSpaceComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::RoadSpaceComponent::_TypeUID));
  }
  else
  {
    m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(m_pComponent);
  if ( !CarChaseTargetFormation )
    return 0;
  v8 = context->mSimObject.m_pPointer;
  return v8 == *((UFG::SimObject **)&CarChaseTargetFormation[5].mNext + 3 * (unsigned __int8)this->mPosition.mValue)
      || v8 == *((UFG::SimObject **)&CarChaseTargetFormation[16].mPrev + 3 * (unsigned __int8)this->mPosition.mValue);
}

// File Line: 416
// RVA: 0x157B050
__int64 dynamic_initializer_for__CarAtFormation::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarAtFormation", 0xFFFFFFFF);
  CarAtFormation::sClassNameUID = result;
  return result;
}

// File Line: 422
// RVA: 0x667050
void __fastcall CarAtFormation::CarAtFormation(CarAtFormation *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarAtFormation::`vftable;
  this->mGroupWaitTime = 0.0;
}

// File Line: 427
// RVA: 0x680250
bool __fastcall CarAtFormation::Match(CarAtFormation *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID))
            : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID)))
           : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent))
          : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent),
            ComponentOfTypeHK
         && (CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(ComponentOfTypeHK)) != 0i64)
        && this->mGroupWaitTime < *((float *)&CarChaseTargetFormation[37].mNext + 1);
  return result;
}

// File Line: 448
// RVA: 0x157B270
__int64 dynamic_initializer_for__CarFormationTimeout::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationTimeout", 0xFFFFFFFF);
  CarFormationTimeout::sClassNameUID = result;
  return result;
}

// File Line: 454
// RVA: 0x667530
void __fastcall CarFormationTimeout::CarFormationTimeout(CarFormationTimeout *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationTimeout::`vftable;
  this->mTimeout = 0.0;
}

// File Line: 459
// RVA: 0x680B70
bool __fastcall CarFormationTimeout::Match(CarFormationTimeout *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID))
            : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID)))
           : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent))
          : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent),
            ComponentOfTypeHK
         && (CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(ComponentOfTypeHK)) != 0i64)
        && this->mTimeout < *(float *)&CarChaseTargetFormation[37].mNext;
  return result;
}

// File Line: 480
// RVA: 0x157B230
__int64 dynamic_initializer_for__CarFormationNumChasers::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationNumChasers", 0xFFFFFFFF);
  CarFormationNumChasers::sClassNameUID = result;
  return result;
}

// File Line: 488
// RVA: 0x667460
void __fastcall CarFormationNumChasers::CarFormationNumChasers(CarFormationNumChasers *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationNumChasers::`vftable;
  this->mCount = 0;
  this->mInEqualityOperator.mValue = 0;
}

// File Line: 493
// RVA: 0x680980
bool __fastcall CarFormationNumChasers::Match(CarFormationNumChasers *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID))
            : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::RoadSpaceComponent::_TypeUID)))
           : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent))
          : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent),
            ComponentOfTypeHK
         && (CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(ComponentOfTypeHK)) != 0i64)
        && CompareInt(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mCount,
             (int)CarChaseTargetFormation[38].mPrev);
  return result;
}

// File Line: 515
// RVA: 0x157B250
__int64 dynamic_initializer_for__CarFormationNumChasersInRange::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationNumChasersInRange", 0xFFFFFFFF);
  CarFormationNumChasersInRange::sClassNameUID = result;
  return result;
}

// File Line: 525
// RVA: 0x6674A0
void __fastcall CarFormationNumChasersInRange::CarFormationNumChasersInRange(CarFormationNumChasersInRange *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationNumChasersInRange::`vftable;
  this->mCount = 0;
  this->mInEqualityOperator.mValue = 0;
  this->mRange = 0.0;
}

// File Line: 530
// RVA: 0x680A30
bool __fastcall CarFormationNumChasersInRange::Match(CarFormationNumChasersInRange *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectVehicle *m_pSimObject; // rcx
  __int16 v7; // dx
  UFG::VehicleSubjectComponent *ComponentOfTypeHK; // rax
  int mCount; // ebx
  UFG::InEqualityOperator mValue; // edi
  int v11; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  m_pSimObject = (UFG::SimObjectVehicle *)m_pComponent[26].m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  v7 = m_pSimObject->m_Flags;
  if ( (v7 & 0x4000) != 0 )
    goto LABEL_18;
  if ( v7 < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(m_pSimObject);
    goto LABEL_20;
  }
  if ( (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
LABEL_18:
    ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pSimObject,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
LABEL_20:
  if ( ComponentOfTypeHK )
  {
    mCount = this->mCount;
    mValue = (unsigned __int8)this->mInEqualityOperator.mValue;
    v11 = UFG::VehicleSubjectComponent::NumChasersCloserThan(ComponentOfTypeHK, this->mRange);
    return CompareInt(mValue, mCount, v11);
  }
  return 0;
}

// File Line: 553
// RVA: 0x157B210
__int64 dynamic_initializer_for__CarFormationIsCustom::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationIsCustom", 0xFFFFFFFF);
  CarFormationIsCustom::sClassNameUID = result;
  return result;
}

// File Line: 556
// RVA: 0x6808E0
bool __fastcall CarFormationIsCustom::Match(CarFormationIsCustom *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::RoadSpaceComponent::_TypeUID))
        : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::RoadSpaceComponent::_TypeUID)))
       : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent))
      : (ComponentOfTypeHK = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent),
        ComponentOfTypeHK
     && (CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(ComponentOfTypeHK)) != 0i64) )
  {
    return BYTE4(CarChaseTargetFormation[38].mPrev);
  }
  else
  {
    return 0;
  }
}

// File Line: 576
// RVA: 0x157B390
__int64 dynamic_initializer_for__CarOccupantHasGun::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarOccupantHasGun", 0xFFFFFFFF);
  CarOccupantHasGun::sClassNameUID = result;
  return result;
}

// File Line: 580
// RVA: 0x680ED0
bool __fastcall CarOccupantHasGun::Match(CarOccupantHasGun *this, ActionContext *context)
{
  UFG::SimObjectGame *Target; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectProp *v6; // rcx
  __int16 v7; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax

  Target = (UFG::SimObjectGame *)UFG::getTarget(
                                   context->mSimObject.m_pPointer,
                                   (unsigned __int8)this->m_eTargetType.mValue);
  if ( !Target )
    return 0;
  m_Flags = Target->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = Target->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(Target, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v5;
  }
  else
  {
    m_pComponent = Target->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v6 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 25i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v6 )
    return 0;
  v7 = v6->m_Flags;
  if ( (v7 & 0x4000) != 0 || v7 < 0 )
  {
LABEL_19:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v6,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    return ComponentOfTypeHK
        && ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mAmmoInventoryItem;
  }
  if ( (v7 & 0x2000) == 0 )
  {
    if ( (v7 & 0x1000) == 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v6,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      return ComponentOfTypeHK
          && ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mAmmoInventoryItem;
    }
    goto LABEL_19;
  }
  ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v6);
  return ComponentOfTypeHK
      && ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mAmmoInventoryItem;
}

// File Line: 615
// RVA: 0x157B3B0
__int64 dynamic_initializer_for__CarOccupantHasTarget::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarOccupantHasTarget", 0xFFFFFFFF);
  CarOccupantHasTarget::sClassNameUID = result;
  return result;
}

// File Line: 619
// RVA: 0x681020
bool __fastcall CarOccupantHasTarget::Match(CarOccupantHasTarget *this, ActionContext *context)
{
  UFG::SimObjectGame *Target; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rcx
  bool result; // al

  Target = (UFG::SimObjectGame *)UFG::getTarget(
                                   context->mSimObject.m_pPointer,
                                   (unsigned __int8)this->m_eTargetType.mValue);
  result = 0;
  if ( Target )
  {
    m_Flags = Target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = Target->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(Target, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v5;
    }
    else
    {
      m_pComponent = Target->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v6 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
      v7 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 30i64);
      if ( *(_QWORD *)(v7 + v6 + 40) )
      {
        if ( *(_BYTE *)(v7 + v6 + 49) )
          return 1;
      }
    }
  }
  return result;
}

// File Line: 650
// RVA: 0x157B410
__int64 dynamic_initializer_for__CarOccupantTargetInFrustum::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarOccupantTargetInFrustum", 0xFFFFFFFF);
  CarOccupantTargetInFrustum::sClassNameUID = result;
  return result;
}

// File Line: 662
// RVA: 0x6810E0
bool __fastcall CarOccupantTargetInFrustum::Match(CarOccupantTargetInFrustum *this, ActionContext *context)
{
  UFG::SimObjectGame *Target; // rax
  UFG::SimObjectGame *v5; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rbp
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __m128 v14; // xmm10
  float v15; // xmm11_4
  __m128 v16; // xmm1
  float v17; // xmm2_4
  float v18; // xmm10_4
  float v19; // xmm11_4
  float v20; // xmm2_4
  __int16 v21; // cx
  UFG::AimingBaseComponent *v22; // rax
  __m128 y_low; // xmm1
  float x; // xmm3_4
  double v25; // xmm2_8
  float z; // xmm8_4
  float v27; // xmm8_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  double v30; // xmm0_8
  float m_fAngleStartCW; // xmm2_4
  float m_fAngleEndCW; // xmm1_4
  bool v33; // cc
  bool v34; // al
  UFG::qVector3 vAimDirection; // [rsp+58h] [rbp-90h] BYREF
  UFG::SimObject *ray_hit_object; // [rsp+F0h] [rbp+8h] BYREF

  if ( (_S30_2 & 1) == 0 )
  {
    _S30_2 |= 1u;
    UFG::qSharedString::qSharedString(&s_sEmptyString, &customCaption);
    atexit(CarOccupantTargetInFrustum::Match_::_2_::_dynamic_atexit_destructor_for__s_sEmptyString__);
  }
  Target = (UFG::SimObjectGame *)UFG::getTarget(
                                   context->mSimObject.m_pPointer,
                                   (unsigned __int8)this->m_eTargetType.mValue);
  v5 = Target;
  if ( !Target )
    return 0;
  m_Flags = Target->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = Target->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(Target, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v8;
  }
  else
  {
    m_pComponent = Target->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v9 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 30i64);
  v10 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
  v11 = *(_QWORD *)(v9 + v10 + 40);
  if ( !v11 )
    return 0;
  if ( !*(_BYTE *)(v9 + v10 + 49) )
    return 0;
  v12 = *(_QWORD *)(v11 + 88);
  m_pTransformNodeComponent = v5->m_pTransformNodeComponent;
  if ( !v12 )
    return 0;
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5->m_pTransformNodeComponent);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
  v14 = (__m128)*(unsigned int *)(v12 + 176);
  v14.m128_f32[0] = v14.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.x;
  v15 = *(float *)(v12 + 180) - m_pTransformNodeComponent->mWorldTransform.v3.y;
  v16 = v14;
  v16.m128_f32[0] = (float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v15 * v15);
  v17 = (float)((float)(*(float *)(v12 + 184) - m_pTransformNodeComponent->mWorldTransform.v3.z)
              * (float)(*(float *)(v12 + 184) - m_pTransformNodeComponent->mWorldTransform.v3.z))
      + v16.m128_f32[0];
  if ( (float)(this->m_fNearDistance * this->m_fNearDistance) > v17
    || v17 > (float)(this->m_fFarDistance * this->m_fFarDistance) )
  {
    return 0;
  }
  if ( v16.m128_f32[0] >= 0.000099999997 )
  {
    if ( v16.m128_f32[0] == 0.0 )
      v20 = 0.0;
    else
      v20 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
    v18 = v14.m128_f32[0] * v20;
    v19 = v15 * v20;
  }
  else
  {
    v18 = *(float *)&FLOAT_1_0;
    v19 = 0.0;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  vAimDirection = *(UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v0.x;
  if ( this->m_bUseAimDirection )
  {
    v21 = v5->m_Flags;
    if ( (v21 & 0x4000) != 0 )
      v22 = (UFG::AimingBaseComponent *)v5->m_Components.p[47].m_pComponent;
    else
      v22 = (UFG::AimingBaseComponent *)(v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v5,
                                           UFG::AimingBaseComponent::_TypeUID)
                                       : UFG::SimObject::GetComponentOfType(v5, UFG::AimingBaseComponent::_TypeUID));
    if ( v22 )
      UFG::AimingBaseComponent::GetAimDirection(v22, &vAimDirection, 0i64);
  }
  y_low = (__m128)LODWORD(vAimDirection.y);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(vAimDirection.x * vAimDirection.x);
  if ( y_low.m128_f32[0] >= 0.000099999997 )
  {
    if ( y_low.m128_f32[0] == 0.0 )
      v27 = 0.0;
    else
      v27 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
    x = vAimDirection.x * v27;
    *(_QWORD *)&v25 = LODWORD(vAimDirection.y);
    *(float *)&v25 = vAimDirection.y * v27;
    z = v27 * 0.0;
  }
  else
  {
    x = UFG::qVector3::msDirFront.x;
    *(_QWORD *)&v25 = LODWORD(UFG::qVector3::msDirFront.y);
    z = UFG::qVector3::msDirFront.z;
  }
  vAimDirection.z = z;
  vAimDirection.y = *(float *)&v25;
  vAimDirection.x = x;
  v28 = (float)(UFG::qVector3::msDirUp.y * z) - (float)(*(float *)&v25 * UFG::qVector3::msDirUp.z);
  v29 = (float)(x * UFG::qVector3::msDirUp.z) - (float)(UFG::qVector3::msDirUp.x * z);
  *(float *)&v25 = (float)(*(float *)&v25 * v19) + (float)(x * v18);
  v30 = UFG::qACos(v25);
  if ( (float)((float)(v29 * v19) + (float)(v28 * v18)) > 0.0 )
    *(float *)&v30 = 6.2831855 - *(float *)&v30;
  m_fAngleStartCW = this->m_fAngleStartCW;
  m_fAngleEndCW = this->m_fAngleEndCW;
  if ( m_fAngleStartCW > m_fAngleEndCW )
  {
    if ( *(float *)&v30 >= 0.0 && *(float *)&v30 <= m_fAngleEndCW )
      goto LABEL_53;
    if ( m_fAngleStartCW <= *(float *)&v30 )
    {
      v33 = *(float *)&v30 <= 6.2831855;
      goto LABEL_52;
    }
    return 0;
  }
  if ( m_fAngleStartCW > *(float *)&v30 )
    return 0;
  v33 = *(float *)&v30 <= m_fAngleEndCW;
LABEL_52:
  if ( !v33 )
    return 0;
LABEL_53:
  if ( !this->m_bTestLOS )
    return 1;
  v34 = UFG::DoRaycast(
          m_pTransformNodeComponent,
          (UFG::TransformNodeComponent *)v12,
          1.5,
          1,
          0i64,
          &ray_hit_object,
          0i64,
          0,
          &UFG::qColour::Red);
  return ray_hit_object == context->mSimObject.m_pPointer || v34;
}

// File Line: 840
// RVA: 0x157B2D0
__int64 dynamic_initializer_for__CarIsRacing::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarIsRacing", 0xFFFFFFFF);
  CarIsRacing::sClassNameUID = result;
  return result;
}

// File Line: 843
// RVA: 0x680C30
bool __fastcall CarIsRacing::Match(CarIsRacing *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent && m_pComponent[26].m_SafePointerList.mNode.mPrev )
      return 1;
  }
  return result;
}

// File Line: 861
// RVA: 0x157B0D0
__int64 dynamic_initializer_for__CarCanShoveCargo::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarCanShoveCargo", 0xFFFFFFFF);
  CarCanShoveCargo::sClassNameUID = result;
  return result;
}

// File Line: 864
// RVA: 0x680450
bool __fastcall CarCanShoveCargo::Match(CarCanShoveCargo *this, ActionContext *context)
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
        && (BYTE1(ComponentOfTypeHK[32].m_BoundComponentHandles.mNode.mPrev) & 8) != 0;
  return result;
}

// File Line: 882
// RVA: 0x157B490
__int64 dynamic_initializer_for__CarRacingLongerThan::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarRacingLongerThan", 0xFFFFFFFF);
  CarRacingLongerThan::sClassNameUID = result;
  return result;
}

// File Line: 887
// RVA: 0x681570
bool __fastcall CarRacingLongerThan::Match(CarRacingLongerThan *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[24].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[24].m_pComponent),
        ComponentOfTypeHK) )
  {
    mPrev = ComponentOfTypeHK[26].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    mPrev = 0i64;
  }
  if ( mPrev )
    return *((float *)&mPrev[3].mNext + 1) > this->mSeconds;
  else
    return this->mSeconds < 0.0;
}

// File Line: 908
// RVA: 0x157B4B0
__int64 dynamic_initializer_for__CarRoleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarRoleCondition", 0xFFFFFFFF);
  CarRoleCondition::sClassNameUID = result;
  return result;
}

// File Line: 914
// RVA: 0x667B50
void __fastcall CarRoleCondition::CarRoleCondition(CarRoleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarRoleCondition::`vftable;
  this->mRole.mValue = 6;
}

// File Line: 918
// RVA: 0x681640
bool __fastcall CarRoleCondition::Match(CarRoleCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
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
        && ComponentOfTypeHK->m_DrivingRole == (unsigned __int8)this->mRole.mValue;
  return result;
}

// File Line: 941
// RVA: 0x157B630
__int64 dynamic_initializer_for__VehicleInTrafficJamCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleInTrafficJamCondition", 0xFFFFFFFF);
  VehicleInTrafficJamCondition::sClassNameUID = result;
  return result;
}

// File Line: 943
// RVA: 0x66B560
void __fastcall VehicleInTrafficJamCondition::VehicleInTrafficJamCondition(VehicleInTrafficJamCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleInTrafficJamCondition::`vftable;
}

// File Line: 947
// RVA: 0x681880
bool __fastcall VehicleInTrafficJamCondition::Match(VehicleInTrafficJamCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
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
        && UFG::AiDriverComponent::IsInTrafficJam(ComponentOfTypeHK);
  return result;
}

// File Line: 964
// RVA: 0x157B650
__int64 dynamic_initializer_for__VehicleIsAvoidingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleIsAvoidingCondition", 0xFFFFFFFF);
  VehicleIsAvoidingCondition::sClassNameUID = result;
  return result;
}

// File Line: 969
// RVA: 0x66B590
void __fastcall VehicleIsAvoidingCondition::VehicleIsAvoidingCondition(VehicleIsAvoidingCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleIsAvoidingCondition::`vftable;
  this->mTypeSet.mValue = 0;
}

// File Line: 973
// RVA: 0x681900
char __fastcall VehicleIsAvoidingCondition::Match(VehicleIsAvoidingCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::AiDriverComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::AiDriverComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return UFG::AiDriverComponent::IsBlockedByAvoidable(ComponentOfTypeHK, (unsigned __int8)this->mTypeSet.mValue);
  }
  else
  {
    return 0;
  }
}

// File Line: 991
// RVA: 0x157B670
__int64 dynamic_initializer_for__VehicleIsParkedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleIsParkedCondition", 0xFFFFFFFF);
  VehicleIsParkedCondition::sClassNameUID = result;
  return result;
}

// File Line: 993
// RVA: 0x681990
bool __fastcall VehicleIsParkedCondition::Match(VehicleIsParkedCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[30].m_pComponent;
    goto LABEL_11;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleOccupantComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleOccupantComponent::_TypeUID);
  m_pComponent = ComponentOfTypeHK;
LABEL_11:
  if ( m_pComponent )
    return m_pComponent[1].m_SafePointerList.mNode.mNext != 0i64;
  return 0;
}

// File Line: 1009
// RVA: 0x157B690
__int64 dynamic_initializer_for__VehicleIsParkedWithDriverCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleIsParkedWithDriverCondition", 0xFFFFFFFF);
  VehicleIsParkedWithDriverCondition::sClassNameUID = result;
  return result;
}

// File Line: 1011
// RVA: 0x681A30
bool __fastcall VehicleIsParkedWithDriverCondition::Match(
        VehicleIsParkedWithDriverCondition *this,
        ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::AiDriverComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::AiDriverComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return ComponentOfTypeHK->m_bIsParked;
  }
  else
  {
    return 0;
  }
}

// File Line: 1028
// RVA: 0x157B6B0
__int64 dynamic_initializer_for__VehicleNumberOfPassengersCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleNumberOfPassengersCondition", 0xFFFFFFFF);
  VehicleNumberOfPassengersCondition::sClassNameUID = result;
  return result;
}

// File Line: 1037
// RVA: 0x66B5D0
void __fastcall VehicleNumberOfPassengersCondition::VehicleNumberOfPassengersCondition(
        VehicleNumberOfPassengersCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleNumberOfPassengersCondition::`vftable;
  this->mInEqualityOperator.mValue = 1;
  this->mQuantity = 0;
}

// File Line: 1041
// RVA: 0x681AB0
bool __fastcall VehicleNumberOfPassengersCondition::Match(
        VehicleNumberOfPassengersCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleOccupantComponent *m_pComponent; // rcx
  UFG::VehicleOccupantComponent *ComponentOfTypeHK; // rax
  UFG::CharacterOccupantComponent *mNext; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rcx
  int v9; // r8d
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> **i; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::VehicleOccupantComponent *)m_pPointer->m_Components.p[30].m_pComponent;
    goto LABEL_11;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::VehicleOccupantComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::VehicleOccupantComponent::_TypeUID);
  m_pComponent = ComponentOfTypeHK;
LABEL_11:
  if ( !m_pComponent )
    return 0;
  mNext = (UFG::CharacterOccupantComponent *)m_pComponent->mPassengers.mNode.mNext;
  p_m_BoundComponentHandles = &m_pComponent->m_BoundComponentHandles;
  v9 = 0;
  for ( i = &mNext[-1].mNext;
        i != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> **)p_m_BoundComponentHandles;
        i = &i[9][-4].mPrev )
  {
    ++v9;
  }
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mQuantity, v9);
}

// File Line: 1063
// RVA: 0x157B5B0
__int64 dynamic_initializer_for__TransitDistanceToGoalLocationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TransitDistanceToGoalLocationCondition", 0xFFFFFFFF);
  TransitDistanceToGoalLocationCondition::sClassNameUID = result;
  return result;
}

// File Line: 1071
// RVA: 0x66A810
void __fastcall TransitDistanceToGoalLocationCondition::TransitDistanceToGoalLocationCondition(
        TransitDistanceToGoalLocationCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TransitDistanceToGoalLocationCondition::`vftable;
  this->mInEqualityOperator.mValue = 2;
  this->mDistance = 20.0;
}

