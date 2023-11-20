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
  CarModeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarModeCondition::`vftable;
  v1->mMode.mValue = 0;
}

// File Line: 49
// RVA: 0x680E30
bool __fastcall CarModeCondition::Match(CarModeCondition *this, ActionContext *context)
{
  CarModeCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v5->m_DrivingMode == (unsigned __int8)v2->mMode.mValue;
  }
  else
  {
    result = 0;
  }
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
  CarEscortMode *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarEscortMode::`vftable;
  v1->mEscortMode.mValue = 0;
}

// File Line: 80
// RVA: 0x680600
bool __fastcall CarEscortMode::Match(CarEscortMode *this, ActionContext *context)
{
  CarEscortMode *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v5->m_EscortInfo.eEscortMode == (unsigned __int8)v2->mEscortMode.mValue;
  }
  else
  {
    result = 0;
  }
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
  CarAtOffset *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarAtOffset::`vftable;
  v1->mTime = 0.0;
  *(_WORD *)&v1->mPosition.mValue = 768;
}

// File Line: 114
// RVA: 0x680310
bool __fastcall CarAtOffset::Match(CarAtOffset *this, ActionContext *context)
{
  CarAtOffset *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = UFG::AiDriverComponent::GetTimeAtOffset(v5, (CarCombat::Position)(unsigned __int8)v2->mPosition.mValue) > v2->mTime;
  }
  else
  {
    result = 0;
  }
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
  CarAttackStat *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarAttackStat::`vftable;
  v1->mAttackType.mValue = 0;
  v1->mNumAttacks = 0;
}

// File Line: 149
// RVA: 0x6803B0
bool __fastcall CarAttackStat::Match(CarAttackStat *this, ActionContext *context)
{
  CarAttackStat *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v5->m_CombatStats.mNumAttacks[(unsigned __int8)v2->mAttackType.mValue] >= v2->mNumAttacks;
  }
  else
  {
    result = 0;
  }
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
  CarLastAttack *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarLastAttack::`vftable;
  v1->mAttackType.mValue = 0;
  v1->mAttackTime = 0.0;
}

// File Line: 182
// RVA: 0x680CD0
bool __fastcall CarLastAttack::Match(CarLastAttack *this, ActionContext *context)
{
  CarLastAttack *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v2->mAttackTime < v5->m_CombatStats.mLastAttack[(unsigned __int8)v2->mAttackType.mValue];
  }
  else
  {
    result = 0;
  }
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
  CarFormationAttackStat *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAttackStat::`vftable;
  v1->mAttackType.mValue = 0;
  v1->mNumAttacks = 0;
}

// File Line: 215
// RVA: 0x680780
bool __fastcall CarFormationAttackStat::Match(CarFormationAttackStat *this, ActionContext *context)
{
  CarFormationAttackStat *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RoadSpaceComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent)) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent),
        v5 && (v6 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v5)) != 0i64) )
  {
    result = *((_DWORD *)&v6[35].mPrev + (unsigned __int8)v2->mAttackType.mValue + 1) >= (unsigned int)v2->mNumAttacks;
  }
  else
  {
    result = 0;
  }
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
  CarDistanceToEscortEnemy *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarDistanceToEscortEnemy::`vftable;
  v1->mInEqualityOperator.mValue = 4;
  v1->mDistance = 10.0;
}

// File Line: 252
// RVA: 0x6804E0
char __fastcall CarDistanceToEscortEnemy::Match(CarDistanceToEscortEnemy *this, ActionContext *context)
{
  CarDistanceToEscortEnemy *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::AiDriverComponent *v6; // rax
  UFG::SimObject *v7; // rbx
  UFG::qVector3 v9; // [rsp+20h] [rbp-28h]
  UFG::qVector3 result; // [rsp+30h] [rbp-18h]

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                       (UFG::SimObjectGame *)&v3->vfptr,
                                       UFG::AiDriverComponent::_TypeUID);
    else
      v6 = (UFG::AiDriverComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v3->vfptr,
                                                         UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v3->vfptr,
                                                                                               UFG::AiDriverComponent::_TypeUID));
  }
  else
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
  }
  if ( !v6 )
    return 0;
  v7 = UFG::AiDriverComponent::GetEscortEnemy(v6);
  if ( !v7 )
    return 0;
  UFG::GetPosition(&result, v4->mSimObject.m_pPointer);
  UFG::GetPosition(&v9, v7);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
           v2->mDistance * v2->mDistance,
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
  CarLastFormationAttack *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarLastFormationAttack::`vftable;
  v1->mAttackType.mValue = 0;
  v1->mAttackTime = 0.0;
}

// File Line: 293
// RVA: 0x680D70
bool __fastcall CarLastFormationAttack::Match(CarLastFormationAttack *this, ActionContext *context)
{
  CarLastFormationAttack *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RoadSpaceComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent)) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent),
        v5 && (v6 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v5)) != 0i64) )
  {
    result = v2->mAttackTime < *((float *)&v6[34].mPrev + (unsigned __int8)v2->mAttackType.mValue + 1);
  }
  else
  {
    result = 0;
  }
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
  CarWithinRange *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarWithinRange::`vftable;
  v1->mRange = 0.0;
}

// File Line: 326
// RVA: 0x6816E0
char __fastcall CarWithinRange::Match(CarWithinRange *this, ActionContext *context)
{
  CarWithinRange *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rdi
  UFG::SimObjectGame *v8; // rcx
  char v9; // bl
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  float v13; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[24].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[24].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = v5[26].m_SafePointerList.mNode.mPrev;
  if ( !v6 )
    return *(float *)&v5[29].m_pSimObject < v2->mRange;
  v8 = (UFG::SimObjectGame *)v5[26].m_pSimObject;
  v9 = 0;
  if ( v8
    && ((v10 = v8->m_Flags, !((v10 >> 14) & 1)) ? ((v10 & 0x8000u) == 0 ? (!((v10 >> 13) & 1) ? (!((v10 >> 12) & 1) ? (v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RoadSpaceComponent::_TypeUID))) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RoadSpaceComponent::_TypeUID))) : (v11 = v8->m_Components.p[24].m_pComponent)) : (v11 = v8->m_Components.p[24].m_pComponent),
        v11) )
  {
    v12 = v11[26].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    v12 = 0i64;
  }
  if ( !v12 )
    return 0;
  v13 = *(float *)&v12[3].mPrev - *(float *)&v6[3].mPrev;
  if ( v13 >= -5.0 && v13 <= v2->mRange )
    v9 = 1;
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
  CarFormationAvailable *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAvailable::`vftable;
  v1->mAvailable = 0;
}

// File Line: 364
// RVA: 0x680840
bool __fastcall CarFormationAvailable::Match(CarFormationAvailable *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::RoadSpaceComponent *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v4 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID))) : (v4 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID))) : (v4 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent)) : (v4 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent),
        v4 && (v5 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v4)) != 0i64) )
  {
    result = HIBYTE(v5[38].mPrev);
  }
  else
  {
    result = 0;
  }
  return result;
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
  CarFormationAssignedPosition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAssignedPosition::`vftable;
  v1->mPosition.mValue = 0;
}

// File Line: 395
// RVA: 0x6806A0
bool __fastcall CarFormationAssignedPosition::Match(CarFormationAssignedPosition *this, ActionContext *context)
{
  CarFormationAssignedPosition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::RoadSpaceComponent *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::SimObject *v8; // r8

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
    else
      v6 = (UFG::RoadSpaceComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v3,
                                                          UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v3->vfptr,
                                                                                                 UFG::RoadSpaceComponent::_TypeUID));
  }
  else
  {
    v6 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v7 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v6);
  if ( !v7 )
    return 0;
  v8 = v4->mSimObject.m_pPointer;
  return v8 == *((UFG::SimObject **)&v7[5].mNext + 3 * (unsigned __int8)v2->mPosition.mValue)
      || v8 == *((UFG::SimObject **)&v7[16].mPrev + 3 * (unsigned __int8)v2->mPosition.mValue);
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
  CarAtFormation *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarAtFormation::`vftable;
  v1->mGroupWaitTime = 0.0;
}

// File Line: 427
// RVA: 0x680250
bool __fastcall CarAtFormation::Match(CarAtFormation *this, ActionContext *context)
{
  CarAtFormation *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RoadSpaceComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent)) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent),
        v5 && (v6 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v5)) != 0i64) )
  {
    result = v2->mGroupWaitTime < *((float *)&v6[37].mNext + 1);
  }
  else
  {
    result = 0;
  }
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
  CarFormationTimeout *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationTimeout::`vftable;
  v1->mTimeout = 0.0;
}

// File Line: 459
// RVA: 0x680B70
bool __fastcall CarFormationTimeout::Match(CarFormationTimeout *this, ActionContext *context)
{
  CarFormationTimeout *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RoadSpaceComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent)) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent),
        v5 && (v6 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v5)) != 0i64) )
  {
    result = v2->mTimeout < *(float *)&v6[37].mNext;
  }
  else
  {
    result = 0;
  }
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
  CarFormationNumChasers *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationNumChasers::`vftable;
  v1->mCount = 0;
  v1->mInEqualityOperator.mValue = 0;
}

// File Line: 493
// RVA: 0x680980
bool __fastcall CarFormationNumChasers::Match(CarFormationNumChasers *this, ActionContext *context)
{
  CarFormationNumChasers *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RoadSpaceComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent)) : (v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent),
        v5 && (v6 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v5)) != 0i64) )
  {
    result = CompareInt(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mCount,
               (int)v6[38].mPrev);
  }
  else
  {
    result = 0;
  }
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
  CarFormationNumChasersInRange *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationNumChasersInRange::`vftable;
  v1->mCount = 0;
  v1->mInEqualityOperator.mValue = 0;
  v1->mRange = 0.0;
}

// File Line: 530
// RVA: 0x680A30
bool __fastcall CarFormationNumChasersInRange::Match(CarFormationNumChasersInRange *this, ActionContext *context)
{
  CarFormationNumChasersInRange *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectVehicle *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::VehicleSubjectComponent *v8; // rax
  int v9; // ebx
  UFG::InEqualityOperator v10; // edi
  int v11; // eax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[24].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[24].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = (UFG::SimObjectVehicle *)v5[26].m_pSimObject;
  if ( !v6 )
    return 0;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v6->vfptr,
                                           UFG::VehicleSubjectComponent::_TypeUID);
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
      v8 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::VehicleSubjectComponent::_TypeUID);
    else
      v8 = (UFG::VehicleSubjectComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v6->vfptr,
                                                               UFG::VehicleSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::VehicleSubjectComponent::_TypeUID));
  }
  else
  {
    v8 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v6);
  }
  if ( !v8 )
    return 0;
  v9 = v2->mCount;
  v10 = (unsigned __int8)v2->mInEqualityOperator.mValue;
  v11 = UFG::VehicleSubjectComponent::NumChasersCloserThan(v8, v2->mRange);
  return CompareInt(v10, v9, v11);
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::RoadSpaceComponent *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v4 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID))) : (v4 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID))) : (v4 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent)) : (v4 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent),
        v4 && (v5 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v4)) != 0i64) )
  {
    result = BYTE4(v5[38].mPrev);
  }
  else
  {
    result = 0;
  }
  return result;
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
  UFG::SimObjectGame *v2; // rax
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectProp *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimObjectWeaponPropertiesComponent *v8; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)UFG::getTarget(
                               context->mSimObject.m_pPointer,
                               (UFG::eTargetTypeEnum)(unsigned __int8)this->m_eTargetType.mValue);
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v4 = v5;
    }
    else
    {
      v4 = v2->m_Components.p[20].m_pComponent;
    }
    if ( v4 )
    {
      v6 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 25i64)
                                  + *(_QWORD *)&v4[1].m_TypeUID
                                  + 40);
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v6->vfptr,
                                                            UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
            v8 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v6);
          else
            v8 = (UFG::SimObjectWeaponPropertiesComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                (UFG::SimObjectGame *)&v6->vfptr,
                                                                                UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
        }
        else
        {
          v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v6->vfptr,
                                                            UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        if ( v8 && v8->mWeaponTypeInfo->mFireModes[v8->mFireMode]->mAmmoInventoryItem )
          result = 1;
      }
    }
  }
  return result;
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
  UFG::SimObjectGame *v2; // rax
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rax
  __int64 v6; // rax
  signed __int64 v7; // rcx
  bool result; // al

  v2 = (UFG::SimObjectGame *)UFG::getTarget(
                               context->mSimObject.m_pPointer,
                               (UFG::eTargetTypeEnum)(unsigned __int8)this->m_eTargetType.mValue);
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v4 = v5;
    }
    else
    {
      v4 = v2->m_Components.p[20].m_pComponent;
    }
    if ( v4 )
    {
      v6 = *(_QWORD *)&v4[1].m_TypeUID;
      v7 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 30i64);
      if ( *(_QWORD *)(v7 + v6 + 40) )
      {
        if ( *(_BYTE *)(v7 + v6 + 49) )
          result = 1;
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
  ActionContext *v2; // r14
  CarOccupantTargetInFrustum *v3; // rsi
  UFG::SimObjectGame *v4; // rax
  UFG::SimObjectGame *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rdx
  UFG::SimComponent *v8; // rax
  signed __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rbp
  UFG::TransformNodeComponent *v13; // rdi
  __m128 v14; // xmm10
  float v15; // xmm11_4
  __m128 v16; // xmm1
  float v17; // xmm2_4
  float v18; // xmm10_4
  float v19; // xmm11_4
  float v20; // xmm2_4
  unsigned __int16 v21; // cx
  UFG::AimingBaseComponent *v22; // rax
  __m128 v23; // xmm1
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm8_4
  float v27; // xmm8_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  bool v34; // cf
  bool v35; // zf
  bool v36; // al
  UFG::qVector3 vAimDirection; // [rsp+58h] [rbp-90h]
  UFG::SimObject *ray_hit_object; // [rsp+F0h] [rbp+8h]

  v2 = context;
  v3 = this;
  if ( !(_S30_2 & 1) )
  {
    _S30_2 |= 1u;
    UFG::qSharedString::qSharedString(&s_sEmptyString, &customWorldMapCaption);
    atexit(CarOccupantTargetInFrustum::Match_::_2_::_dynamic_atexit_destructor_for__s_sEmptyString__);
  }
  v4 = (UFG::SimObjectGame *)UFG::getTarget(
                               v2->mSimObject.m_pPointer,
                               (UFG::eTargetTypeEnum)(unsigned __int8)v3->m_eTargetType.mValue);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = v4->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = v4->m_Components.p[20].m_pComponent;
  }
  else if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v7 = v8;
  }
  else
  {
    v7 = v4->m_Components.p[20].m_pComponent;
  }
  if ( !v7 )
    return 0;
  v9 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + 30i64);
  v10 = *(_QWORD *)&v7[1].m_TypeUID;
  v11 = *(_QWORD *)(v9 + v10 + 40);
  if ( !v11 )
    return 0;
  if ( !*(_BYTE *)(v9 + v10 + 49) )
    return 0;
  v12 = *(_QWORD *)(v11 + 88);
  v13 = v5->m_pTransformNodeComponent;
  if ( !v12 )
    return 0;
  if ( !v13 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5->m_pTransformNodeComponent);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
  v14 = (__m128)*(unsigned int *)(v12 + 176);
  v14.m128_f32[0] = v14.m128_f32[0] - v13->mWorldTransform.v3.x;
  v15 = *(float *)(v12 + 180) - v13->mWorldTransform.v3.y;
  v16 = v14;
  v16.m128_f32[0] = (float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v15 * v15);
  v17 = (float)((float)(*(float *)(v12 + 184) - v13->mWorldTransform.v3.z)
              * (float)(*(float *)(v12 + 184) - v13->mWorldTransform.v3.z))
      + v16.m128_f32[0];
  if ( (float)(v3->m_fNearDistance * v3->m_fNearDistance) > v17
    || v17 > (float)(v3->m_fFarDistance * v3->m_fFarDistance) )
  {
    return 0;
  }
  if ( v16.m128_f32[0] >= 0.000099999997 )
  {
    if ( v16.m128_f32[0] == 0.0 )
      v20 = 0.0;
    else
      v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
    v18 = v14.m128_f32[0] * v20;
    v19 = v15 * v20;
  }
  else
  {
    v18 = *(float *)&FLOAT_1_0;
    v19 = 0.0;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
  vAimDirection.x = v13->mWorldTransform.v0.x;
  vAimDirection.y = v13->mWorldTransform.v0.y;
  vAimDirection.z = v13->mWorldTransform.v0.z;
  if ( v3->m_bUseAimDirection )
  {
    v21 = v5->m_Flags;
    if ( (v21 >> 14) & 1 )
    {
      v22 = (UFG::AimingBaseComponent *)v5->m_Components.p[47].m_pComponent;
    }
    else if ( (v21 & 0x8000u) == 0 )
    {
      if ( (v21 >> 13) & 1 )
        v22 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v5,
                                            UFG::AimingBaseComponent::_TypeUID);
      else
        v22 = (UFG::AimingBaseComponent *)((v21 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v5,
                                                               UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::AimingBaseComponent::_TypeUID));
    }
    else
    {
      v22 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::AimingBaseComponent::_TypeUID);
    }
    if ( v22 )
      UFG::AimingBaseComponent::GetAimDirection(v22, &vAimDirection, 0i64);
  }
  v23 = (__m128)LODWORD(vAimDirection.y);
  v23.m128_f32[0] = (float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(vAimDirection.x * vAimDirection.x);
  if ( v23.m128_f32[0] >= 0.000099999997 )
  {
    if ( v23.m128_f32[0] == 0.0 )
      v27 = 0.0;
    else
      v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
    v24 = vAimDirection.x * v27;
    v25 = vAimDirection.y * v27;
    v26 = v27 * 0.0;
  }
  else
  {
    v24 = UFG::qVector3::msDirFront.x;
    v25 = UFG::qVector3::msDirFront.y;
    v26 = UFG::qVector3::msDirFront.z;
  }
  vAimDirection.z = v26;
  vAimDirection.y = v25;
  vAimDirection.x = v24;
  v28 = (float)(UFG::qVector3::msDirUp.y * v26) - (float)(v25 * UFG::qVector3::msDirUp.z);
  v29 = (float)(v24 * UFG::qVector3::msDirUp.z) - (float)(UFG::qVector3::msDirUp.x * v26);
  v30 = (float)(v25 * v19) + (float)(v24 * v18);
  v31 = v30;
  UFG::qACos(v30);
  if ( (float)((float)(v29 * v19) + (float)(v28 * v18)) > 0.0 )
    v31 = 6.2831855 - v30;
  v32 = v3->m_fAngleStartCW;
  v33 = v3->m_fAngleEndCW;
  if ( v32 > v33 )
  {
    if ( v31 >= 0.0 && v31 <= v33 )
      goto LABEL_55;
    if ( v32 <= v31 )
    {
      v34 = v31 < 6.2831855;
      v35 = v31 == 6.2831855;
      goto LABEL_54;
    }
    return 0;
  }
  if ( v32 > v31 )
    return 0;
  v34 = v31 < v33;
  v35 = v31 == v33;
LABEL_54:
  if ( !v34 && !v35 )
    return 0;
LABEL_55:
  if ( !v3->m_bTestLOS )
    return 1;
  v36 = UFG::DoRaycast(
          v13,
          (UFG::TransformNodeComponent *)v12,
          1.5,
          1,
          0i64,
          &ray_hit_object,
          0i64,
          0,
          &UFG::qColour::Red);
  return ray_hit_object == v2->mSimObject.m_pPointer || v36;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[24].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      v4 = v2->m_Components.p[24].m_pComponent;
    }
    if ( v4 && v4[26].m_SafePointerList.mNode.mPrev )
      result = 1;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = v2->m_Components.p[5].m_pComponent)) : (v4 = v2->m_Components.p[5].m_pComponent),
        v4) )
  {
    result = (BYTE1(v4[32].m_BoundComponentHandles.mNode.mPrev) >> 3) & 1;
  }
  else
  {
    result = 0;
  }
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
  CarRacingLongerThan *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID))) : (v5 = v3->m_Components.p[24].m_pComponent)) : (v5 = v3->m_Components.p[24].m_pComponent),
        v5) )
  {
    v6 = v5[26].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
    result = *((float *)&v6[3].mNext + 1) > v2->mSeconds;
  else
    result = v2->mSeconds < 0.0;
  return result;
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
  CarRoleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarRoleCondition::`vftable;
  v1->mRole.mValue = 6;
}

// File Line: 918
// RVA: 0x681640
bool __fastcall CarRoleCondition::Match(CarRoleCondition *this, ActionContext *context)
{
  CarRoleCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = v5->m_DrivingRole == (unsigned __int8)v2->mRole.mValue;
  }
  else
  {
    result = 0;
  }
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
  VehicleInTrafficJamCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleInTrafficJamCondition::`vftable;
}

// File Line: 947
// RVA: 0x681880
bool __fastcall VehicleInTrafficJamCondition::Match(VehicleInTrafficJamCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AiDriverComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2)),
        v4) )
  {
    result = UFG::AiDriverComponent::IsInTrafficJam(v4);
  }
  else
  {
    result = 0;
  }
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
  VehicleIsAvoidingCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleIsAvoidingCondition::`vftable;
  v1->mTypeSet.mValue = 0;
}

// File Line: 973
// RVA: 0x681900
char __fastcall VehicleIsAvoidingCondition::Match(VehicleIsAvoidingCondition *this, ActionContext *context)
{
  VehicleIsAvoidingCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5) )
  {
    result = UFG::AiDriverComponent::IsBlockedByAvoidable(v5, (unsigned __int8)v2->mTypeSet.mValue);
  }
  else
  {
    result = 0;
  }
  return result;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rcx

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    if ( (v3 & 0x8000u) != 0 )
    {
      v5 = v2->m_Components.p[30].m_pComponent;
      goto LABEL_12;
    }
    if ( (v3 >> 13) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v3 >> 12) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
  }
  v5 = v4;
LABEL_12:
  if ( v5 )
    return v5[1].m_SafePointerList.mNode.mNext != 0i64;
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
bool __fastcall VehicleIsParkedWithDriverCondition::Match(VehicleIsParkedWithDriverCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AiDriverComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2)),
        v4) )
  {
    result = v4->m_bIsParked;
  }
  else
  {
    result = 0;
  }
  return result;
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
void __fastcall VehicleNumberOfPassengersCondition::VehicleNumberOfPassengersCondition(VehicleNumberOfPassengersCondition *this)
{
  VehicleNumberOfPassengersCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleNumberOfPassengersCondition::`vftable;
  v1->mInEqualityOperator.mValue = 1;
  v1->mQuantity = 0;
}

// File Line: 1041
// RVA: 0x681AB0
bool __fastcall VehicleNumberOfPassengersCondition::Match(VehicleNumberOfPassengersCondition *this, ActionContext *context)
{
  VehicleNumberOfPassengersCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::VehicleOccupantComponent *v5; // rax
  UFG::VehicleOccupantComponent *v6; // rcx
  UFG::CharacterOccupantComponent *v7; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v8; // rcx
  int v9; // er8
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> **i; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v3,
                                            UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    if ( (v4 & 0x8000u) != 0 )
    {
      v6 = (UFG::VehicleOccupantComponent *)v3->m_Components.p[30].m_pComponent;
      goto LABEL_12;
    }
    if ( (v4 >> 13) & 1 )
    {
      v5 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v3,
                                              UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v3,
                                              UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v5 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v3->vfptr,
                                              UFG::VehicleOccupantComponent::_TypeUID);
    }
  }
  v6 = v5;
LABEL_12:
  if ( !v6 )
    return 0;
  v7 = (UFG::CharacterOccupantComponent *)v6->mPassengers.mNode.mNext;
  v8 = &v6->m_BoundComponentHandles;
  v9 = 0;
  for ( i = &v7[-1].mNext;
        i != (UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> **)v8;
        i = &i[9][-4].mPrev )
  {
    ++v9;
  }
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mQuantity, v9);
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
void __fastcall TransitDistanceToGoalLocationCondition::TransitDistanceToGoalLocationCondition(TransitDistanceToGoalLocationCondition *this)
{
  TransitDistanceToGoalLocationCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TransitDistanceToGoalLocationCondition::`vftable;
  v1->mInEqualityOperator.mValue = 2;
  v1->mDistance = 20.0;
}

