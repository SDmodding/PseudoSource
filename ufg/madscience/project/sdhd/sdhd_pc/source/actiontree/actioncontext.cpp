// File Line: 162
// RVA: 0x26E770
signed __int64 __fastcall GetMostUsedIndex(unsigned int uid)
{
  signed __int64 result; // rax
  unsigned int *i; // rdx

  result = 0i64;
  for ( i = gMostUsedTable; *i != uid; ++i )
  {
    result = (unsigned int)(result + 1);
    if ( (unsigned int)result >= 0x40 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 206
// RVA: 0x2687C0
void __fastcall ActionContext::ActionContext(ActionContext *this)
{
  this->mSimObject.mPrev = &this->mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
  this->mSimObject.m_pPointer = 0i64;
  this->m_OpeningBranch = 0i64;
  this->mActionController = 0i64;
  this->mParentContext = 0i64;
  this->mDebugBreak = 0;
  this->mSignals = -1i64;
  this->m_ActionTreeType.mValue = 0;
  this->mProbabilitiesValid = 0;
  UFG::qMemSet(this->mProbabilitys, 0, 0x28u);
  UFG::qMemSet(this->mMostUsedPlayCount, 0, 0x40u);
  this->mActionTreeComponentBase[1] = 0i64;
  this->mActionTreeComponentBase[2] = 0i64;
  this->mActionTreeComponentBase[3] = 0i64;
}

// File Line: 240
// RVA: 0x268740
void __fastcall ActionContext::ActionContext(
        ActionContext *this,
        UFG::eActionTreeType action_tree_type,
        UFG::SimObject *object)
{
  this->mSimObject.mPrev = &this->mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
  this->mSimObject.m_pPointer = 0i64;
  this->m_OpeningBranch = 0i64;
  this->mActionController = 0i64;
  this->mParentContext = 0i64;
  this->mDebugBreak = 0;
  this->mSignals = -1i64;
  this->m_ActionTreeType.mValue = 0;
  this->mProbabilitiesValid = 0;
  ActionContext::Reset(this, action_tree_type, object);
  this->mProbabilitiesValid = 0;
  UFG::qMemSet(this->mProbabilitys, 0, 0x28u);
  UFG::qMemSet(this->mMostUsedPlayCount, 0, 0x40u);
}

// File Line: 255
// RVA: 0x268700
void __fastcall ActionContext::ActionContext(ActionContext *this, ActionContext *rhs)
{
  this->mSimObject.mPrev = &this->mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
  this->mSimObject.m_pPointer = 0i64;
  this->m_ActionTreeType.mValue = 0;
  ActionContext::operator=(this, rhs);
}

// File Line: 260
// RVA: 0x26A100
ActionContext *__fastcall ActionContext::operator=(ActionContext *this, ActionContext *rhs)
{
  if ( this != rhs )
  {
    ActionContext::Reset(this, (UFG::eActionTreeType)rhs->m_ActionTreeType.mValue, rhs->mSimObject.m_pPointer);
    this->m_ActionTreeType.mValue = rhs->m_ActionTreeType.mValue;
    this->m_OpeningBranch = rhs->m_OpeningBranch;
    this->mActionController = rhs->mActionController;
    this->mParentContext = rhs->mParentContext;
    this->mDebugBreak = rhs->mDebugBreak;
    this->mProbabilitiesValid = rhs->mProbabilitiesValid;
    this->mProbabilitys[0] = rhs->mProbabilitys[0];
    this->mProbabilitys[1] = rhs->mProbabilitys[1];
    this->mProbabilitys[2] = rhs->mProbabilitys[2];
    this->mProbabilitys[3] = rhs->mProbabilitys[3];
    this->mProbabilitys[4] = rhs->mProbabilitys[4];
    this->mProbabilitys[5] = rhs->mProbabilitys[5];
    this->mProbabilitys[6] = rhs->mProbabilitys[6];
    this->mProbabilitys[7] = rhs->mProbabilitys[7];
    this->mProbabilitys[8] = rhs->mProbabilitys[8];
    this->mProbabilitys[9] = rhs->mProbabilitys[9];
    UFG::qMemSet(this->mMostUsedPlayCount, 0, 0x40u);
    this->mActionTreeComponentBase[1] = rhs->mActionTreeComponentBase[1];
    this->mActionTreeComponentBase[2] = rhs->mActionTreeComponentBase[2];
    this->mActionTreeComponentBase[3] = rhs->mActionTreeComponentBase[3];
  }
  return this;
}

// File Line: 302
// RVA: 0x26EC60
float __fastcall ActionContext::GetRunningMasterRate(ActionContext *this)
{
  ActionContext *mParentContext; // rcx

  mParentContext = this->mParentContext;
  if ( mParentContext )
    return ActionContext::GetRunningMasterRate(mParentContext) * this->mActionController->mRunningMasterRate;
  else
    return 1.0 * this->mActionController->mRunningMasterRate;
}

// File Line: 309
// RVA: 0x271140
void __fastcall ActionContext::Reset(
        ActionContext *this,
        UFG::eActionTreeType action_tree_type,
        UFG::SimObjectGame *object)
{
  UFG::SimObject *m_pPointer; // rax
  unsigned __int16 v5; // bp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::ActionTreeComponentBase *v10; // rsi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::ActionTreeComponentBase *v13; // rax
  signed __int16 v14; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::ActionTreeComponentBase *p_mNext; // rax
  signed __int16 v17; // cx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = this->mSimObject.m_pPointer;
  v5 = action_tree_type;
  if ( m_pPointer != object )
  {
    if ( m_pPointer )
    {
      mPrev = this->mSimObject.mPrev;
      mNext = this->mSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      this->mSimObject.mPrev = &this->mSimObject;
      this->mSimObject.mNext = &this->mSimObject;
    }
    this->mSimObject.m_pPointer = object;
    if ( object )
    {
      v9 = object->m_SafePointerList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v9->mNext = &this->mSimObject;
      this->mSimObject.mPrev = v9;
      this->mSimObject.mNext = &object->m_SafePointerList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      object->m_SafePointerList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &this->mSimObject;
    }
    v10 = 0i64;
    this->m_OpeningBranch = 0i64;
    this->mActionController = 0i64;
    this->mParentContext = 0i64;
    this->mDebugBreak = 0;
    this->mProbabilitiesValid = 0;
    if ( object
      && ((m_Flags = object->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0
         ? ((m_Flags & 0x2000) == 0
          ? ((m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(object, UFG::ActionTreeComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::ActionTreeComponent::_TypeUID)))
          : (ComponentOfType = object->m_Components.p[6].m_pComponent))
         : (ComponentOfType = object->m_Components.p[7].m_pComponent))
        : (ComponentOfType = object->m_Components.p[7].m_pComponent),
          ComponentOfType) )
    {
      v13 = (UFG::ActionTreeComponentBase *)&ComponentOfType[1];
    }
    else
    {
      v13 = 0i64;
    }
    this->mActionTreeComponentBase[1] = v13;
    if ( object
      && ((v14 = object->m_Flags, (v14 & 0x4000) == 0)
        ? (v14 >= 0
         ? ((v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
          ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::AIActionTreeComponent::_TypeUID))
          : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::AIActionTreeComponent::_TypeUID)))
         : (ComponentOfTypeHK = object->m_Components.p[19].m_pComponent))
        : (ComponentOfTypeHK = object->m_Components.p[19].m_pComponent),
          ComponentOfTypeHK) )
    {
      p_mNext = (UFG::ActionTreeComponentBase *)&ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext;
    }
    else
    {
      p_mNext = 0i64;
    }
    this->mActionTreeComponentBase[2] = p_mNext;
    if ( !object )
      goto LABEL_41;
    v17 = object->m_Flags;
    if ( (v17 & 0x4000) != 0 )
    {
      m_pComponent = object->m_Components.p[31].m_pComponent;
    }
    else
    {
      if ( v17 < 0 || (v17 & 0x2000) != 0 )
        goto LABEL_41;
      if ( (v17 & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::FacialActionTreeComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(object, UFG::FacialActionTreeComponent::_TypeUID);
    }
    if ( m_pComponent )
      v10 = (UFG::ActionTreeComponentBase *)&m_pComponent[1];
LABEL_41:
    this->mActionTreeComponentBase[3] = v10;
    this->m_ActionTreeType.mValue = v5;
    return;
  }
  this->m_ActionTreeType.mValue = action_tree_type;
}

// File Line: 343
// RVA: 0x273A60
void __fastcall ActionContext::UpdateSignalsAndConditions(ActionContext *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mSimObject.m_pPointer;
  if ( m_pPointer
    && (m_pPointer->m_Flags & 0x4000) != 0
    && (v3 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer)) != 0i64 )
  {
    this->mSignals = v3->m_Intention.mSignals;
  }
  else
  {
    this->mSignals = 0i64;
  }
}

