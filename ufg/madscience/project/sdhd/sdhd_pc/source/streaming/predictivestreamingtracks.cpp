// File Line: 31
// RVA: 0x3E8B30
void __fastcall UFG::PredictiveSubPriorityModifierTrack::PredictiveSubPriorityModifierTrack(UFG::PredictiveSubPriorityModifierTrack *this)
{
  UFG::PredictiveSubPriorityModifierTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, UFG::PredictiveSubPriorityModifierTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<UFG::PredictiveSubPriorityModifierTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&UFG::PredictiveSubPriorityModifierTrack::`vftable;
  v1->m_SubPriorityModifierConditions.mCount = 0;
  v1->m_SubPriorityModifierConditions.mData.mOffset = 0i64;
}

// File Line: 34
// RVA: 0x14D1800
__int64 dynamic_initializer_for__UFG::PredictiveSubPriorityModifierTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PredictiveSubPriorityModifierTrack", 0xFFFFFFFF);
  UFG::PredictiveSubPriorityModifierTrack::sClassNameUID = result;
  return result;
}

// File Line: 101
// RVA: 0x3E8FC0
void __fastcall UFG::PredictiveSubPriorityModifierTask::Begin(UFG::PredictiveSubPriorityModifierTask *this, ActionContext *pContext)
{
  this->m_pContext = pContext;
  this->m_ePreviousAnimationPriority = SubPriorityModifierCondition::ms_ePredictivePriority;
  this->m_uPreviousSubPriority = -1;
}

// File Line: 110
// RVA: 0x3EADA0
void __fastcall UFG::PredictiveSubPriorityModifierTask::UpdateActionControllerRecursive(UFG::PredictiveSubPriorityModifierTask *this, ActionController *pAC, UFG::eAnimationPriorityEnum eAnimationPriority, unsigned __int16 uSubPriority)
{
  unsigned __int16 v4; // si
  ActionNodePlayable **v5; // rbx
  UFG::eAnimationPriorityEnum v6; // ebp
  signed __int64 v7; // rdi
  int v8; // eax
  UFG::PredictiveSubPriorityModifierTask *v9; // [rsp+40h] [rbp+8h]
  ActionNodePlayable **v10; // [rsp+48h] [rbp+10h]

  v9 = this;
  v4 = uSubPriority;
  v5 = (ActionNodePlayable **)&pAC->m_RunningTasks.mNode.mNext[-1].mNext;
  v6 = eAnimationPriority;
  v10 = &pAC->m_SequenceNode;
  if ( v5 != &pAC->m_SequenceNode )
  {
    do
    {
      v7 = (signed __int64)&v5[2][-1].mChildren.mData;
      v8 = ((__int64 (*)(void))v5[3]->vfptr->GetClassNameUID)();
      if ( v8 == AnimationBankReferenceTrack::sClassNameUID )
      {
        AnimationGroupHandle::SetAnimationPriority((AnimationGroupHandle *)(v5 + 8), v6, v4);
      }
      else if ( v8 == SpawnTrack::sClassNameUID )
      {
        UFG::PredictiveSubPriorityModifierTask::UpdateActionControllerRecursive(
          v9,
          (ActionController *)(v5 + 36),
          v6,
          v4);
      }
      v5 = (ActionNodePlayable **)v7;
    }
    while ( (ActionNodePlayable **)v7 != v10 );
  }
}

// File Line: 133
// RVA: 0x3EAD20
char __fastcall UFG::PredictiveSubPriorityModifierTask::Update(UFG::PredictiveSubPriorityModifierTask *this, float timeDelta)
{
  ITrack *v2; // rdx
  signed int v3; // er8
  unsigned __int16 v4; // r9
  UFG::PredictiveSubPriorityModifierTask *v5; // r11
  __int64 *v6; // r10
  unsigned int v7; // eax
  __int64 v8; // rdx
  __int64 v9; // rcx

  v2 = this->m_Track;
  v3 = SubPriorityModifierCondition::ms_ePredictivePriority;
  v4 = 0;
  v5 = this;
  v6 = (__int64 *)((char *)&v2[1] + (unsigned __int64)&v2[1].mResourceOwner->mResourceOwner);
  v7 = (_QWORD)v2[1].vfptr & 0x7FFFFFFF;
  if ( v7 )
  {
    v8 = v7;
    do
    {
      v9 = *v6;
      ++v6;
      if ( v3 <= *((unsigned __int8 *)v6 + v9 + 16) )
        v3 = *((unsigned __int8 *)v6 + v9 + 16);
      if ( v4 <= *(_WORD *)((char *)v6 + v9 + 18) )
        v4 = *(_WORD *)((char *)v6 + v9 + 18);
      --v8;
    }
    while ( v8 );
  }
  if ( v3 != v5->m_ePreviousAnimationPriority || v4 != v5->m_uPreviousSubPriority )
    UFG::PredictiveSubPriorityModifierTask::UpdateActionControllerRecursive(
      v5,
      v5->m_pContext->mActionController,
      (UFG::eAnimationPriorityEnum)v3,
      v4);
  return 1;
}

