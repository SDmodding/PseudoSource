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
  IsNISPlayingCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsNISPlayingCondition::`vftable';
}

// File Line: 29
// RVA: 0x3E36F0
_BOOL8 __fastcall IsNISPlayingCondition::Match(IsNISPlayingCondition *this, ActionContext *pContext)
{
  return NISManager::sInstance->mState != 0;
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
  IsNISPlayingActionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsNISPlayingActionCondition::`vftable';
}

// File Line: 55
// RVA: 0x3E36E0
bool __fastcall IsNISPlayingActionCondition::Match(IsNISPlayingActionCondition *this, ActionContext *pContext)
{
  return NISManager::sInstance->mState == 4;
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
  IsNISControlledCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsNISControlledCondition::`vftable';
}

// File Line: 81
// RVA: 0x3E35E0
char __fastcall IsNISControlledCondition::Match(IsNISControlledCondition *this, ActionContext *pContext)
{
  NISInstance *v2; // rax
  char v3; // cl
  char v4; // al
  char result; // al
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax

  if ( NISManager::sInstance->mState != 4 )
    goto LABEL_30;
  v2 = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( v2 )
    v2 = (NISInstance *)v2->mpNISNode;
  v3 = v2 && BYTE2(v2->mAnimationGroupHandle.mNext) ? 1 : 0;
  v4 = v2 && BYTE3(v2->mAnimationGroupHandle.mNext) ? 1 : 0;
  if ( v3 && v4
    || (v6 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v7 = v6->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::ActionTreeComponent::_TypeUID)) : (v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::ActionTreeComponent::_TypeUID))) : (v8 = v6->m_Components.p[6].m_pComponent)) : (v8 = v6->m_Components.p[7].m_pComponent)) : (v8 = v6->m_Components.p[7].m_pComponent),
        v8 && LOBYTE(v8[2].m_pSimObject)) )
  {
    result = 1;
  }
  else
  {
LABEL_30:
    result = 0;
  }
  return result;
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
  IsNISSeamlessInCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsNISSeamlessInCondition::`vftable';
}

// File Line: 124
// RVA: 0x3E3700
char __fastcall IsNISSeamlessInCondition::Match(IsNISSeamlessInCondition *this, ActionContext *pContext)
{
  NISInstance *v2; // rax
  char result; // al

  if ( NISManager::sInstance->mState != 4 )
    goto LABEL_10;
  v2 = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( v2 )
    v2 = (NISInstance *)v2->mpNISNode;
  if ( v2 && BYTE6(v2->mAnimationGroupHandle.mNext) )
    result = 1;
  else
LABEL_10:
    result = 0;
  return result;
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
  IsNISSeamlessOutCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsNISSeamlessOutCondition::`vftable';
}

// File Line: 159
// RVA: 0x3E3730
char __fastcall IsNISSeamlessOutCondition::Match(IsNISSeamlessOutCondition *this, ActionContext *pContext)
{
  NISInstance *v2; // rax
  char result; // al

  if ( NISManager::sInstance->mState != 4 )
    goto LABEL_10;
  v2 = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( v2 )
    v2 = (NISInstance *)v2->mpNISNode;
  if ( v2 && HIBYTE(v2->mAnimationGroupHandle.mNext) )
    result = 1;
  else
LABEL_10:
    result = 0;
  return result;
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
void __fastcall IsNISPlayerControllableCondition::IsNISPlayerControllableCondition(IsNISPlayerControllableCondition *this)
{
  IsNISPlayerControllableCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsNISPlayerControllableCondition::`vftable';
}

// File Line: 194
// RVA: 0x3E36B0
bool __fastcall IsNISPlayerControllableCondition::Match(IsNISPlayerControllableCondition *this, ActionContext *pContext)
{
  NISInstance *v2; // rax
  bool result; // al

  result = 0;
  if ( NISManager::sInstance->mState == 4 )
  {
    v2 = NISManager::sInstance->mpActiveInstance.m_pPointer;
    if ( v2 )
    {
      if ( v2->mpNISAllowPlayerControlTask )
        result = 1;
    }
  }
  return result;
}

