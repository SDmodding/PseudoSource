// File Line: 162
// RVA: 0x26E770
signed __int64 __fastcall GetMostUsedIndex(unsigned int uid)
{
  signed __int64 result; // rax
  unsigned int *v2; // rdx

  result = 0i64;
  v2 = gMostUsedTable;
  while ( *v2 != uid )
  {
    result = (unsigned int)(result + 1);
    ++v2;
    if ( (unsigned int)result >= 0x40 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 206
// RVA: 0x2687C0
void __fastcall ActionContext::ActionContext(ActionContext *this)
{
  ActionContext *v1; // rbx

  v1 = this;
  this->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
  this->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
  this->mSimObject.m_pPointer = 0i64;
  this->m_OpeningBranch = 0i64;
  this->mActionController = 0i64;
  this->mParentContext = 0i64;
  this->mDebugBreak = 0;
  this->mSignals = -1i64;
  this->m_ActionTreeType.mValue = 0;
  this->mProbabilitiesValid = 0;
  UFG::qMemSet(this->mProbabilitys, 0, 0x28u);
  UFG::qMemSet(v1->mMostUsedPlayCount, 0, 0x40u);
  v1->mActionTreeComponentBase[1] = 0i64;
  v1->mActionTreeComponentBase[2] = 0i64;
  v1->mActionTreeComponentBase[3] = 0i64;
}

// File Line: 240
// RVA: 0x268740
void __fastcall ActionContext::ActionContext(ActionContext *this, UFG::eActionTreeType action_tree_type, UFG::SimObject *object)
{
  ActionContext *v3; // rbx

  v3 = this;
  this->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
  this->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
  this->mSimObject.m_pPointer = 0i64;
  this->m_OpeningBranch = 0i64;
  this->mActionController = 0i64;
  this->mParentContext = 0i64;
  this->mDebugBreak = 0;
  this->mSignals = -1i64;
  this->m_ActionTreeType.mValue = 0;
  this->mProbabilitiesValid = 0;
  ActionContext::Reset(this, action_tree_type, object);
  v3->mProbabilitiesValid = 0;
  UFG::qMemSet(v3->mProbabilitys, 0, 0x28u);
  UFG::qMemSet(v3->mMostUsedPlayCount, 0, 0x40u);
}

// File Line: 255
// RVA: 0x268700
void __fastcall ActionContext::ActionContext(ActionContext *this, ActionContext *rhs)
{
  this->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
  this->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
  this->mSimObject.m_pPointer = 0i64;
  this->m_ActionTreeType.mValue = 0;
  ActionContext::operator=(this, rhs);
}

// File Line: 260
// RVA: 0x26A100
ActionContext *__fastcall ActionContext::operator=(ActionContext *this, ActionContext *rhs)
{
  ActionContext *v2; // rdi
  ActionContext *v3; // rbx

  v2 = rhs;
  v3 = this;
  if ( this != rhs )
  {
    ActionContext::Reset(this, (UFG::eActionTreeType)rhs->m_ActionTreeType.mValue, rhs->mSimObject.m_pPointer);
    v3->m_ActionTreeType.mValue = v2->m_ActionTreeType.mValue;
    v3->m_OpeningBranch = v2->m_OpeningBranch;
    v3->mActionController = v2->mActionController;
    v3->mParentContext = v2->mParentContext;
    v3->mDebugBreak = v2->mDebugBreak;
    v3->mProbabilitiesValid = v2->mProbabilitiesValid;
    v3->mProbabilitys[0] = v2->mProbabilitys[0];
    v3->mProbabilitys[1] = v2->mProbabilitys[1];
    v3->mProbabilitys[2] = v2->mProbabilitys[2];
    v3->mProbabilitys[3] = v2->mProbabilitys[3];
    v3->mProbabilitys[4] = v2->mProbabilitys[4];
    v3->mProbabilitys[5] = v2->mProbabilitys[5];
    v3->mProbabilitys[6] = v2->mProbabilitys[6];
    v3->mProbabilitys[7] = v2->mProbabilitys[7];
    v3->mProbabilitys[8] = v2->mProbabilitys[8];
    v3->mProbabilitys[9] = v2->mProbabilitys[9];
    UFG::qMemSet(v3->mMostUsedPlayCount, 0, 0x40u);
    v3->mActionTreeComponentBase[1] = v2->mActionTreeComponentBase[1];
    v3->mActionTreeComponentBase[2] = v2->mActionTreeComponentBase[2];
    v3->mActionTreeComponentBase[3] = v2->mActionTreeComponentBase[3];
  }
  return v3;
}

// File Line: 302
// RVA: 0x26EC60
float __fastcall ActionContext::GetRunningMasterRate(ActionContext *this)
{
  ActionContext *v1; // rbx
  ActionContext *v2; // rcx
  float result; // xmm0_4

  v1 = this;
  v2 = this->mParentContext;
  if ( v2 )
    result = ActionContext::GetRunningMasterRate(v2) * v1->mActionController->mRunningMasterRate;
  else
    result = 1.0 * v1->mActionController->mRunningMasterRate;
  return result;
}

// File Line: 309
// RVA: 0x271140
void __fastcall ActionContext::Reset(ActionContext *this, UFG::eActionTreeType action_tree_type, UFG::SimObject *object)
{
  UFG::SimObject *v3; // rax
  UFG::SimObjectGame *v4; // rdi
  unsigned __int16 v5; // bp
  ActionContext *v6; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  signed __int64 v10; // rsi
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  signed __int64 v13; // rax
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rax
  signed __int64 v16; // rax
  unsigned __int16 v17; // cx
  UFG::SimComponent *v18; // rax

  v3 = this->mSimObject.m_pPointer;
  v4 = (UFG::SimObjectGame *)object;
  v5 = action_tree_type;
  v6 = this;
  if ( v3 != object )
  {
    if ( v3 )
    {
      v7 = this->mSimObject.mPrev;
      v8 = this->mSimObject.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      this->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
      this->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
    }
    this->mSimObject.m_pPointer = object;
    if ( object )
    {
      v9 = object->m_SafePointerList.mNode.mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
      this->mSimObject.mPrev = v9;
      this->mSimObject.mNext = &object->m_SafePointerList.mNode;
      object->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
    }
    v10 = 0i64;
    this->m_OpeningBranch = 0i64;
    this->mActionController = 0i64;
    this->mParentContext = 0i64;
    this->mDebugBreak = 0;
    this->mProbabilitiesValid = 0;
    if ( object
      && ((v11 = object->m_Flags, !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v12 = UFG::SimObject::GetComponentOfType(object, UFG::ActionTreeComponent::_TypeUID)) : (v12 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)object, UFG::ActionTreeComponent::_TypeUID))) : (v12 = object->m_Components.p[6].m_pComponent)) : (v12 = object->m_Components.p[7].m_pComponent)) : (v12 = object->m_Components.p[7].m_pComponent),
          v12) )
    {
      v13 = (signed __int64)&v12[1];
    }
    else
    {
      v13 = 0i64;
    }
    v6->mActionTreeComponentBase[1] = (UFG::ActionTreeComponentBase *)v13;
    if ( v4
      && ((v14 = v4->m_Flags, !((v14 >> 14) & 1)) ? ((v14 & 0x8000u) == 0 ? (!((v14 >> 13) & 1) ? (!((v14 >> 12) & 1) ? (v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::AIActionTreeComponent::_TypeUID)) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIActionTreeComponent::_TypeUID))) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIActionTreeComponent::_TypeUID))) : (v15 = v4->m_Components.p[19].m_pComponent)) : (v15 = v4->m_Components.p[19].m_pComponent),
          v15) )
    {
      v16 = (signed __int64)&v15[1].m_SafePointerList.mNode.mNext;
    }
    else
    {
      v16 = 0i64;
    }
    v6->mActionTreeComponentBase[2] = (UFG::ActionTreeComponentBase *)v16;
    if ( !v4 )
      goto LABEL_42;
    v17 = v4->m_Flags;
    if ( (v17 >> 14) & 1 )
    {
      v18 = v4->m_Components.p[31].m_pComponent;
    }
    else
    {
      if ( (v17 & 0x8000u) != 0 || (v17 >> 13) & 1 )
        goto LABEL_42;
      if ( (v17 >> 12) & 1 )
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FacialActionTreeComponent::_TypeUID);
      else
        v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::FacialActionTreeComponent::_TypeUID);
    }
    if ( v18 )
      v10 = (signed __int64)&v18[1];
LABEL_42:
    v6->mActionTreeComponentBase[3] = (UFG::ActionTreeComponentBase *)v10;
    v6->m_ActionTreeType.mValue = v5;
    return;
  }
  this->m_ActionTreeType.mValue = action_tree_type;
}

// File Line: 343
// RVA: 0x273A60
void __fastcall ActionContext::UpdateSignalsAndConditions(ActionContext *this)
{
  ActionContext *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rax

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)this->mSimObject.m_pPointer;
  if ( v2
    && (v2->m_Flags >> 14) & 1
    && (v3 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2)) != 0i64 )
  {
    v1->mSignals = v3->m_Intention.mSignals;
  }
  else
  {
    v1->mSignals = 0i64;
  }
}

