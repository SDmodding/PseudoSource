// File Line: 37
// RVA: 0x149F290
__int64 dynamic_initializer_for__MotionPhase::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionPhase", 0xFFFFFFFF);
  MotionPhase::sClassNameUID = result;
  return result;
}

// File Line: 47
// RVA: 0x30F8C0
void __fastcall MotionPhase::MotionPhase(MotionPhase *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase::`vftable;
  *(_QWORD *)&this->mPlayPriority = 0i64;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 52
// RVA: 0x312850
char __fastcall MotionPhase::Match(MotionPhase *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v5; // rax
  Creature *mCreature; // rcx
  PoseNodeParent *p_mBlendTree; // rcx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdi
  double v11; // xmm0_8
  float v12; // xmm7_4
  double v13; // xmm0_8
  float v14; // xmm2_4
  float v15; // xmm1_4
  float mPhase; // xmm0_4

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
  }
  else
  {
    v5 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::CharacterAnimationComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v5 )
    return 0;
  mCreature = v5->mCreature;
  if ( !mCreature )
    return 0;
  p_mBlendTree = &mCreature->mBlendTree;
  if ( !p_mBlendTree )
    return 0;
  v8 = (__int64)p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr[1].__vecDelDtor(p_mBlendTree, 0);
  if ( !v8 )
    return 0;
  v9 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v8 + 312i64))(v8, (unsigned int)this->mPlayPriority);
  v10 = v9;
  if ( !v9 )
    return 0;
  v11 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v9 + 192i64))(v9);
  v12 = *(float *)&v11;
  v13 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v10 + 192i64))(v10);
  v14 = *(float *)&v13;
  if ( v12 < *(float *)&v13 )
  {
    mPhase = this->mPhase;
    if ( v12 <= mPhase && mPhase <= v14 )
      return 1;
  }
  else
  {
    v15 = this->mPhase;
    if ( v12 <= v15 || v15 <= *(float *)&v13 )
      return 1;
  }
  return 0;
}

// File Line: 134
// RVA: 0x311970
char __fastcall ComparePhaseUtil(
        ActionContext *context,
        PhaseMark comparePhaseMark,
        float comparePhase,
        UFG::InEqualityOperator inEqualityOperator)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::CharacterAnimationComponent *v8; // rax
  Creature *mCreature; // rcx
  PoseNodeParent *p_mBlendTree; // rcx
  __int64 v11; // rbx
  char result; // al
  MotionPhase2 v13; // [rsp+28h] [rbp-40h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
  }
  else
  {
    v8 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::CharacterAnimationComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v8 )
    return 0;
  mCreature = v8->mCreature;
  if ( !mCreature )
    return 0;
  p_mBlendTree = &mCreature->mBlendTree;
  if ( !p_mBlendTree )
    return 0;
  v11 = (__int64)p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr[1].__vecDelDtor(p_mBlendTree, 0);
  if ( !v11 )
    return 0;
  MotionPhase2::MotionPhase2(&v13);
  (*(void (__fastcall **)(__int64, MotionPhase2 *))(*(_QWORD *)v11 + 184i64))(v11, &v13);
  if ( v13.mPhaseMark.mValue == comparePhaseMark )
    result = CompareFloat(inEqualityOperator, comparePhase, v13.mPhase);
  else
    result = 0;
  v13.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  return result;
}

// File Line: 176
// RVA: 0x149F250
__int64 dynamic_initializer_for__FootStepLeftCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FootStepLeftCondition", 0xFFFFFFFF);
  FootStepLeftCondition::sClassNameUID = result;
  return result;
}

// File Line: 184
// RVA: 0x30F840
void __fastcall FootStepLeftCondition::FootStepLeftCondition(FootStepLeftCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FootStepLeftCondition::`vftable;
  this->mPhase = 0.5;
  this->mInEqualityOperator.mValue = 4;
}

// File Line: 188
// RVA: 0x312810
char __fastcall FootStepLeftCondition::Match(FootStepLeftCondition *this, ActionContext *context)
{
  return ComparePhaseUtil(
           context,
           PM_LEFT,
           this->mPhase,
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue);
}

// File Line: 204
// RVA: 0x149F270
__int64 dynamic_initializer_for__FootStepRightCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FootStepRightCondition", 0xFFFFFFFF);
  FootStepRightCondition::sClassNameUID = result;
  return result;
}

// File Line: 212
// RVA: 0x30F880
void __fastcall FootStepRightCondition::FootStepRightCondition(FootStepRightCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FootStepRightCondition::`vftable;
  this->mPhase = 0.5;
  this->mInEqualityOperator.mValue = 4;
}

// File Line: 216
// RVA: 0x312830
char __fastcall FootStepRightCondition::Match(FootStepRightCondition *this, ActionContext *context)
{
  return ComparePhaseUtil(
           context,
           PM_RIGHT,
           this->mPhase,
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue);
}

// File Line: 232
// RVA: 0x149F110
__int64 dynamic_initializer_for__AnimationFrameCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationFrameCondition", 0xFFFFFFFF);
  AnimationFrameCondition::sClassNameUID = result;
  return result;
}

// File Line: 240
// RVA: 0x30F040
void __fastcall AnimationFrameCondition::AnimationFrameCondition(AnimationFrameCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationFrameCondition::`vftable;
  this->mFrame = 0.0;
  this->mInEqualityOperator.mValue = 4;
}

// File Line: 244
// RVA: 0x3126A0
char __fastcall AnimationFrameCondition::Match(AnimationFrameCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v5; // rax
  Creature *mCreature; // rcx
  PoseNodeParent *p_mBlendTree; // rcx
  Expression::IMemberMapVtbl *vfptr; // rax
  float v9; // xmm0_4
  void **v11; // [rsp+20h] [rbp-28h] BYREF
  char v12; // [rsp+28h] [rbp-20h]
  __int64 v13; // [rsp+30h] [rbp-18h]

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
  }
  else
  {
    v5 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::CharacterAnimationComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v5 )
    return 0;
  mCreature = v5->mCreature;
  if ( !mCreature )
    return 0;
  p_mBlendTree = &mCreature->mBlendTree;
  if ( !p_mBlendTree )
    return 0;
  v12 = 1;
  v11 = &FirstAnimationNode::`vftable;
  vfptr = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
  v13 = 0i64;
  vfptr[1].FindWithOldPath(p_mBlendTree, (const char *)&v11);
  if ( !v13 )
    return 0;
  v9 = (*(float (__fastcall **)(__int64))(*(_QWORD *)v13 + 392i64))(v13);
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mFrame, v9);
}

// File Line: 294
// RVA: 0x149F0F0
__int64 dynamic_initializer_for__AnimationBankRequestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationBankRequestCondition", 0xFFFFFFFF);
  AnimationBankRequestCondition::sClassNameUID = result;
  return result;
}

// File Line: 309
// RVA: 0x30EFE0
void __fastcall AnimationBankRequestCondition::AnimationBankRequestCondition(AnimationBankRequestCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationBankRequestCondition::`vftable;
  this->mAnimationBankName = UFG::gNullQSymbolUC;
  *(_WORD *)&this->mRequestStream = 2561;
  this->mNonPlayerAnimPriority.mValue = 7;
  this->mThisNodePath.mPath.mCount = 0;
  this->mThisNodePath.mPath.mData.mOffset = 0i64;
  this->mOwnerNode = 0i64;
}

// File Line: 313
// RVA: 0x3129E0
void __fastcall AnimationBankRequestCondition::ResolveReferences(
        AnimationBankRequestCondition *this,
        ActionNode *ownerNode)
{
  this->mOwnerNode = ownerNode;
  if ( ownerNode )
    ActionNode::GetNameFullPath(ownerNode, &this->mThisNodePath);
}

// File Line: 322
// RVA: 0x312590
bool __fastcall AnimationBankRequestCondition::Match(AnimationBankRequestCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::ActionTreeResourcesComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ActionNode *mOwnerNode; // r14
  bool v9; // zf
  qEnum<enum UFG::eAnimationPriorityEnum,unsigned char> *p_mPlayerAnimPriority; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::ActionTreeResourcesComponent *)m_pPointer->m_Components.p[30].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::ActionTreeResourcesComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeResourcesComponent::_TypeUID);
      m_pComponent = (UFG::ActionTreeResourcesComponent *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( (this->mThisNodePath.mPath.mCount & 0x7FFFFFFF) == 0 || !m_pComponent )
    return 0;
  mOwnerNode = this->mOwnerNode;
  v9 = !UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer);
  p_mPlayerAnimPriority = &this->mPlayerAnimPriority;
  if ( v9 )
    p_mPlayerAnimPriority = &this->mNonPlayerAnimPriority;
  return UFG::ActionTreeResourcesComponent::RequestAnimationBank(
           m_pComponent,
           &this->mThisNodePath,
           mOwnerNode,
           this->mRequestStream != 0,
           &this->mAnimationBankName,
           (UFG::eAnimationPriorityEnum)(unsigned __int8)p_mPlayerAnimPriority->mValue);
}

// File Line: 363
// RVA: 0x149F170
__int64 dynamic_initializer_for__AnimationRequiredIsLoadedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationRequiredIsLoadedCondition", 0xFFFFFFFF);
  AnimationRequiredIsLoadedCondition::sClassNameUID = result;
  return result;
}

// File Line: 367
// RVA: 0x30F1F0
void __fastcall AnimationRequiredIsLoadedCondition::AnimationRequiredIsLoadedCondition(
        AnimationRequiredIsLoadedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationRequiredIsLoadedCondition::`vftable;
}

// File Line: 371
// RVA: 0x312780
char __fastcall AnimationRequiredIsLoadedCondition::Match(
        AnimationRequiredIsLoadedCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::BaseAnimationComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) == 0
        ? ((m_Flags & 0x1000) == 0
         ? (ComponentOfType = (UFG::BaseAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                               m_pPointer,
                                                               UFG::BaseAnimationComponent::_TypeUID))
         : (ComponentOfType = (UFG::BaseAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               m_pPointer,
                                                               UFG::BaseAnimationComponent::_TypeUID)))
        : (ComponentOfType = (UFG::BaseAnimationComponent *)m_pPointer->m_Components.p[8].m_pComponent))
       : (ComponentOfType = (UFG::BaseAnimationComponent *)m_pPointer->m_Components.p[9].m_pComponent))
      : (ComponentOfType = (UFG::BaseAnimationComponent *)m_pPointer->m_Components.p[9].m_pComponent),
        ComponentOfType) )
  {
    return UFG::BaseAnimationComponent::AreResourcesAvailable(ComponentOfType);
  }
  else
  {
    return 0;
  }
}

