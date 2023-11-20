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
  MotionPhase *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase::`vftable;
  *(_QWORD *)&v1->mPlayPriority = 0i64;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 52
// RVA: 0x312850
bool __usercall MotionPhase::Match@<al>(MotionPhase *this@<rcx>, ActionContext *context@<rdx>, float a3@<xmm0>)
{
  MotionPhase *v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *v7; // rcx
  signed __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdi
  float v12; // xmm1_4

  v3 = this;
  v4 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v4);
    else
      v6 = (UFG::CharacterAnimationComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                                   UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
  }
  if ( !v6 )
    return 0;
  v7 = v6->mCreature;
  if ( !v7 )
    return 0;
  v8 = (signed __int64)&v7->mBlendTree;
  if ( !v8 )
    return 0;
  v9 = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v8 + 88i64))(v8, 0i64);
  if ( !v9 )
    return 0;
  v10 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 312i64))(v9, (unsigned int)v3->mPlayPriority);
  v11 = v10;
  if ( !v10 )
    return 0;
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 192i64))(v10);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 192i64))(v11);
  v12 = v3->mPhase;
  return a3 <= v12 || v12 <= a3;
}

// File Line: 134
// RVA: 0x311970
char __fastcall ComparePhaseUtil(ActionContext *context, PhaseMark comparePhaseMark, float comparePhase, UFG::InEqualityOperator inEqualityOperator)
{
  UFG::InEqualityOperator v4; // edi
  PhaseMark v5; // esi
  UFG::SimObjectCVBase *v6; // rcx
  unsigned __int16 v7; // r8
  UFG::CharacterAnimationComponent *v8; // rax
  Creature *v9; // rcx
  signed __int64 v10; // rcx
  __int64 v11; // rbx
  char result; // al
  MotionPhase2 v13; // [rsp+28h] [rbp-40h]

  v4 = inEqualityOperator;
  v5 = comparePhaseMark;
  v6 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !v6 )
    return 0;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
      v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v6);
    else
      v8 = (UFG::CharacterAnimationComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v6->vfptr,
                                                                   UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
  }
  if ( !v8 )
    return 0;
  v9 = v8->mCreature;
  if ( !v9 )
    return 0;
  v10 = (signed __int64)&v9->mBlendTree;
  if ( !v10 )
    return 0;
  v11 = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v10 + 88i64))(v10, 0i64);
  if ( !v11 )
    return 0;
  MotionPhase2::MotionPhase2(&v13);
  (*(void (__fastcall **)(__int64, MotionPhase2 *))(*(_QWORD *)v11 + 184i64))(v11, &v13);
  if ( v13.mPhaseMark.mValue == v5 )
    result = CompareFloat(v4, comparePhase, v13.mPhase);
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
  FootStepLeftCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FootStepLeftCondition::`vftable;
  v1->mPhase = 0.5;
  v1->mInEqualityOperator.mValue = 4;
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
  FootStepRightCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FootStepRightCondition::`vftable;
  v1->mPhase = 0.5;
  v1->mInEqualityOperator.mValue = 4;
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
  AnimationFrameCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationFrameCondition::`vftable;
  v1->mFrame = 0.0;
  v1->mInEqualityOperator.mValue = 4;
}

// File Line: 244
// RVA: 0x3126A0
char __usercall AnimationFrameCondition::Match@<al>(AnimationFrameCondition *this@<rcx>, ActionContext *context@<rdx>, float a3@<xmm0>)
{
  AnimationFrameCondition *v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *v7; // rcx
  PoseNodeParent *v8; // rcx
  Expression::IMemberMapVtbl *v9; // rax
  void **v11; // [rsp+20h] [rbp-28h]
  char v12; // [rsp+28h] [rbp-20h]
  __int64 v13; // [rsp+30h] [rbp-18h]

  v3 = this;
  v4 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v4);
    else
      v6 = (UFG::CharacterAnimationComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                                   UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
  }
  if ( !v6 )
    return 0;
  v7 = v6->mCreature;
  if ( !v7 )
    return 0;
  v8 = &v7->mBlendTree;
  if ( !v8 )
    return 0;
  v12 = 1;
  v11 = &FirstAnimationNode::`vftable;
  v9 = v8->vfptr;
  v13 = 0i64;
  v9[1].FindWithOldPath((Expression::IMemberMap *)&v8->vfptr, (const char *)&v11);
  if ( !v13 )
    return 0;
  (*(void (**)(void))(*(_QWORD *)v13 + 392i64))();
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v3->mInEqualityOperator.mValue, v3->mFrame, a3);
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
  AnimationBankRequestCondition *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationBankRequestCondition::`vftable;
  v1->mAnimationBankName = UFG::gNullQSymbolUC;
  *(_WORD *)&v1->mRequestStream = 2561;
  v1->mNonPlayerAnimPriority.mValue = 7;
  v2 = (signed __int64)&v1->mThisNodePath;
  *(_DWORD *)v2 = 0;
  *(_QWORD *)(v2 + 8) = 0i64;
  v1->mOwnerNode = 0i64;
}

// File Line: 313
// RVA: 0x3129E0
void __fastcall AnimationBankRequestCondition::ResolveReferences(AnimationBankRequestCondition *this, ActionNode *ownerNode)
{
  this->mOwnerNode = ownerNode;
  if ( ownerNode )
    ActionNode::GetNameFullPath(ownerNode, &this->mThisNodePath);
}

// File Line: 322
// RVA: 0x312590
bool __fastcall AnimationBankRequestCondition::Match(AnimationBankRequestCondition *this, ActionContext *pContext)
{
  AnimationBankRequestCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbp
  UFG::ActionTreeResourcesComponent *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  ActionNode *v8; // r14
  bool v9; // zf
  qEnum<enum UFG::eAnimationPriorityEnum,unsigned char> *v10; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = (UFG::ActionTreeResourcesComponent *)v3->m_Components.p[30].m_pComponent;
    }
    else
    {
      if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeResourcesComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeResourcesComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::ActionTreeResourcesComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeResourcesComponent::_TypeUID);
      }
      v5 = (UFG::ActionTreeResourcesComponent *)v7;
    }
  }
  else
  {
    v5 = 0i64;
  }
  if ( !(v2->mThisNodePath.mPath.mCount & 0x7FFFFFFF) || !v5 )
    return 0;
  v8 = v2->mOwnerNode;
  v9 = UFG::IsAnyLocalPlayer(v4->mSimObject.m_pPointer) == 0;
  v10 = &v2->mPlayerAnimPriority;
  if ( v9 )
    v10 = &v2->mNonPlayerAnimPriority;
  return UFG::ActionTreeResourcesComponent::RequestAnimationBank(
           v5,
           &v2->mThisNodePath,
           v8,
           v2->mRequestStream != 0,
           &v2->mAnimationBankName,
           (UFG::eAnimationPriorityEnum)(unsigned __int8)v10->mValue);
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
void __fastcall AnimationRequiredIsLoadedCondition::AnimationRequiredIsLoadedCondition(AnimationRequiredIsLoadedCondition *this)
{
  AnimationRequiredIsLoadedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationRequiredIsLoadedCondition::`vftable;
}

// File Line: 371
// RVA: 0x312780
char __fastcall AnimationRequiredIsLoadedCondition::Match(AnimationRequiredIsLoadedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::BaseAnimationComponent *v4; // rax
  char result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::BaseAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::BaseAnimationComponent::_TypeUID)) : (v4 = (UFG::BaseAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::BaseAnimationComponent::_TypeUID))) : (v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[8].m_pComponent)) : (v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[9].m_pComponent)) : (v4 = (UFG::BaseAnimationComponent *)v2->m_Components.p[9].m_pComponent),
        v4) )
  {
    result = UFG::BaseAnimationComponent::AreResourcesAvailable(v4);
  }
  else
  {
    result = 0;
  }
  return result;
}

