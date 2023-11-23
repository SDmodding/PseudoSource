// File Line: 22
// RVA: 0x14C9F80
__int64 dynamic_initializer_for__IsNISPlayingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsNISPlayingCondition", 0xFFFFFFFF);
  IsNISPlayingCondition::sClassNameUID = result;
  return result;
}

// File Line: 25
// RVA: 0x3DFCD0
void __fastcall IsNISPlayingCondition::IsNISPlayingCondition(IsNISPlayingCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNISPlayingCondition::`vftable;
}

// File Line: 29
// RVA: 0x3E36F0
_BOOL8 __fastcall IsNISPlayingCondition::Match(IsNISPlayingCondition *this, ActionContext *pContext)
{
  return NISManager::sInstance->mState != STATE_INVALID;
}

// File Line: 48
// RVA: 0x14C9F60
__int64 dynamic_initializer_for__IsNISPlayingActionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsNISPlayingActionCondition", 0xFFFFFFFF);
  IsNISPlayingActionCondition::sClassNameUID = result;
  return result;
}

// File Line: 51
// RVA: 0x3DFCA0
void __fastcall IsNISPlayingActionCondition::IsNISPlayingActionCondition(IsNISPlayingActionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNISPlayingActionCondition::`vftable;
}

// File Line: 55
// RVA: 0x3E36E0
bool __fastcall IsNISPlayingActionCondition::Match(IsNISPlayingActionCondition *this, ActionContext *pContext)
{
  return NISManager::sInstance->mState == STATE_INCOMPLETE;
}

// File Line: 74
// RVA: 0x14C9F20
__int64 dynamic_initializer_for__IsNISControlledCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsNISControlledCondition", 0xFFFFFFFF);
  IsNISControlledCondition::sClassNameUID = result;
  return result;
}

// File Line: 77
// RVA: 0x3DFC40
void __fastcall IsNISControlledCondition::IsNISControlledCondition(IsNISControlledCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNISControlledCondition::`vftable;
}

// File Line: 81
// RVA: 0x3E35E0
char __fastcall IsNISControlledCondition::Match(IsNISControlledCondition *this, ActionContext *pContext)
{
  NISInstance *m_pPointer; // rax
  bool v3; // cl
  bool v4; // al
  UFG::SimObjectGame *v6; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax

  if ( NISManager::sInstance->mState != STATE_INCOMPLETE )
    return 0;
  m_pPointer = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( m_pPointer )
    m_pPointer = (NISInstance *)m_pPointer->mpNISNode;
  v3 = m_pPointer && BYTE2(m_pPointer->mAnimationGroupHandle.mNext);
  v4 = m_pPointer && BYTE3(m_pPointer->mAnimationGroupHandle.mNext);
  if ( v3 && v4 )
    return 1;
  v6 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v6
    && ((m_Flags = v6->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) == 0
        ? ((m_Flags & 0x1000) == 0
         ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v6, UFG::ActionTreeComponent::_TypeUID))
         : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::ActionTreeComponent::_TypeUID)))
        : (ComponentOfType = v6->m_Components.p[6].m_pComponent))
       : (ComponentOfType = v6->m_Components.p[7].m_pComponent))
      : (ComponentOfType = v6->m_Components.p[7].m_pComponent),
        ComponentOfType && LOBYTE(ComponentOfType[2].m_pSimObject)) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 117
// RVA: 0x14C9FA0
__int64 dynamic_initializer_for__IsNISSeamlessInCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsNISSeamlessInCondition", 0xFFFFFFFF);
  IsNISSeamlessInCondition::sClassNameUID = result;
  return result;
}

// File Line: 120
// RVA: 0x3DFD00
void __fastcall IsNISSeamlessInCondition::IsNISSeamlessInCondition(IsNISSeamlessInCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNISSeamlessInCondition::`vftable;
}

// File Line: 124
// RVA: 0x3E3700
bool __fastcall IsNISSeamlessInCondition::Match(IsNISSeamlessInCondition *this, ActionContext *pContext)
{
  NISInstance *m_pPointer; // rax

  if ( NISManager::sInstance->mState != STATE_INCOMPLETE )
    return 0;
  m_pPointer = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( m_pPointer )
    m_pPointer = (NISInstance *)m_pPointer->mpNISNode;
  return m_pPointer && BYTE6(m_pPointer->mAnimationGroupHandle.mNext);
}

// File Line: 152
// RVA: 0x14C9FC0
__int64 dynamic_initializer_for__IsNISSeamlessOutCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsNISSeamlessOutCondition", 0xFFFFFFFF);
  IsNISSeamlessOutCondition::sClassNameUID = result;
  return result;
}

// File Line: 155
// RVA: 0x3DFD30
void __fastcall IsNISSeamlessOutCondition::IsNISSeamlessOutCondition(IsNISSeamlessOutCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNISSeamlessOutCondition::`vftable;
}

// File Line: 159
// RVA: 0x3E3730
bool __fastcall IsNISSeamlessOutCondition::Match(IsNISSeamlessOutCondition *this, ActionContext *pContext)
{
  NISInstance *m_pPointer; // rax

  if ( NISManager::sInstance->mState != STATE_INCOMPLETE )
    return 0;
  m_pPointer = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( m_pPointer )
    m_pPointer = (NISInstance *)m_pPointer->mpNISNode;
  return m_pPointer && HIBYTE(m_pPointer->mAnimationGroupHandle.mNext);
}

// File Line: 187
// RVA: 0x14C9F40
__int64 dynamic_initializer_for__IsNISPlayerControllableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsNISPlayerControllableCondition", 0xFFFFFFFF);
  IsNISPlayerControllableCondition::sClassNameUID = result;
  return result;
}

// File Line: 190
// RVA: 0x3DFC70
void __fastcall IsNISPlayerControllableCondition::IsNISPlayerControllableCondition(
        IsNISPlayerControllableCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsNISPlayerControllableCondition::`vftable;
}

// File Line: 194
// RVA: 0x3E36B0
bool __fastcall IsNISPlayerControllableCondition::Match(
        IsNISPlayerControllableCondition *this,
        ActionContext *pContext)
{
  NISInstance *m_pPointer; // rax
  bool result; // al

  result = 0;
  if ( NISManager::sInstance->mState == STATE_INCOMPLETE )
  {
    m_pPointer = NISManager::sInstance->mpActiveInstance.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->mpNISAllowPlayerControlTask )
        return 1;
    }
  }
  return result;
}

