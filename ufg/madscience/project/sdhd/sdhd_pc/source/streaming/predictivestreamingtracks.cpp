// File Line: 31
// RVA: 0x3E8B30
void __fastcall UFG::PredictiveSubPriorityModifierTrack::PredictiveSubPriorityModifierTrack(
        UFG::PredictiveSubPriorityModifierTrack *this)
{
  ITrack::ITrack(this, UFG::PredictiveSubPriorityModifierTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<UFG::PredictiveSubPriorityModifierTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&UFG::PredictiveSubPriorityModifierTrack::`vftable;
  this->m_SubPriorityModifierConditions.mCount = 0;
  this->m_SubPriorityModifierConditions.mData.mOffset = 0i64;
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
void __fastcall UFG::PredictiveSubPriorityModifierTask::Begin(
        UFG::PredictiveSubPriorityModifierTask *this,
        ActionContext *pContext)
{
  this->m_pContext = pContext;
  this->m_ePreviousAnimationPriority = SubPriorityModifierCondition::ms_ePredictivePriority;
  this->m_uPreviousSubPriority = -1;
}

// File Line: 110
// RVA: 0x3EADA0
void __fastcall UFG::PredictiveSubPriorityModifierTask::UpdateActionControllerRecursive(
        UFG::PredictiveSubPriorityModifierTask *this,
        ActionController *pAC,
        UFG::eAnimationPriorityEnum eAnimationPriority,
        unsigned __int16 uSubPriority)
{
  ActionNodePlayable **p_mNext; // rbx
  __int64 p_mData; // rdi
  unsigned int v8; // eax
  ActionNodePlayable **p_m_SequenceNode; // [rsp+48h] [rbp+10h]

  p_mNext = (ActionNodePlayable **)&pAC->m_RunningTasks.mNode.mNext[-1].mNext;
  p_m_SequenceNode = &pAC->m_SequenceNode;
  if ( p_mNext != &pAC->m_SequenceNode )
  {
    do
    {
      p_mData = (__int64)&p_mNext[2][-1].mChildren.mData;
      v8 = p_mNext[3]->vfptr->GetClassNameUID(p_mNext[3]);
      if ( v8 == AnimationBankReferenceTrack::sClassNameUID )
      {
        AnimationGroupHandle::SetAnimationPriority(
          (AnimationGroupHandle *)(p_mNext + 8),
          eAnimationPriority,
          uSubPriority);
      }
      else if ( v8 == SpawnTrack::sClassNameUID )
      {
        UFG::PredictiveSubPriorityModifierTask::UpdateActionControllerRecursive(
          this,
          (ActionController *)(p_mNext + 36),
          eAnimationPriority,
          uSubPriority);
      }
      p_mNext = (ActionNodePlayable **)p_mData;
    }
    while ( (ActionNodePlayable **)p_mData != p_m_SequenceNode );
  }
}

// File Line: 133
// RVA: 0x3EAD20
char __fastcall UFG::PredictiveSubPriorityModifierTask::Update(
        UFG::PredictiveSubPriorityModifierTask *this,
        float timeDelta)
{
  ITrack *m_Track; // rdx
  int v3; // r8d
  unsigned __int16 v4; // r9
  __int64 *v6; // r10
  unsigned int v7; // eax
  __int64 v8; // rdx
  __int64 v9; // rcx

  m_Track = this->m_Track;
  v3 = SubPriorityModifierCondition::ms_ePredictivePriority;
  v4 = 0;
  v6 = (__int64 *)((char *)&m_Track[1] + (unsigned __int64)&m_Track[1].mResourceOwner->mResourceOwner);
  v7 = (__int64)m_Track[1].vfptr & 0x7FFFFFFF;
  if ( v7 )
  {
    v8 = v7;
    do
    {
      v9 = *v6++;
      if ( v3 <= *((unsigned __int8 *)v6 + v9 + 16) )
        v3 = *((unsigned __int8 *)v6 + v9 + 16);
      if ( v4 <= *(_WORD *)((char *)v6 + v9 + 18) )
        v4 = *(_WORD *)((char *)v6 + v9 + 18);
      --v8;
    }
    while ( v8 );
  }
  if ( v3 != this->m_ePreviousAnimationPriority || v4 != this->m_uPreviousSubPriority )
    UFG::PredictiveSubPriorityModifierTask::UpdateActionControllerRecursive(
      this,
      this->m_pContext->mActionController,
      (UFG::eAnimationPriorityEnum)v3,
      v4);
  return 1;
}

