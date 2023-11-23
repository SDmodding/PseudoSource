// File Line: 248
// RVA: 0x1491AB0
__int64 dynamic_initializer_for__gCollisionLayerEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gCollisionLayerEnum,
    gCollisionLayerStrings,
    gCollisionLayerStringsCount,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gCollisionLayerEnum__);
}

// File Line: 298
// RVA: 0x148C910
__int64 dynamic_initializer_for__UELExpressionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UELExpressionCondition", 0xFFFFFFFF);
  UELExpressionCondition::sClassNameUID = result;
  return result;
}

// File Line: 307
// RVA: 0x2793E0
void __fastcall UELExpressionCondition::UELExpressionCondition(UELExpressionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&UELExpressionCondition::`vftable;
  this->mExpressionText.mOffset = 1i64;
  BinString::Set(&this->mExpressionText, &customCaption);
  this->mExpression.mOffset = 0i64;
}

// File Line: 311
// RVA: 0x2799A0
void __fastcall UELExpressionCondition::~UELExpressionCondition(UELExpressionCondition *this)
{
  __int64 mOffset; // rax
  _QWORD *v3; // rcx
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&UELExpressionCondition::`vftable;
  mOffset = this->mExpression.mOffset;
  if ( mOffset )
  {
    v3 = (__int64 *)((char *)&this->mExpression.mOffset + mOffset);
    if ( v3 )
    {
      *v3 = &UEL::Expression::`vftable;
      operator delete[](v3);
    }
  }
  if ( (this->mExpressionText.mOffset & 1) != 0 && (this->mExpressionText.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v4 = (char *)&this->mExpressionText + (this->mExpressionText.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v4 != BinString::sEmptyString )
      operator delete[](v4);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 331
// RVA: 0x290A30
bool __fastcall UELExpressionCondition::Match(UELExpressionCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 mOffset; // rax
  char *v8; // rcx
  char v10[40]; // [rsp+30h] [rbp-28h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p->m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::UELComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::UELComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p->m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  mOffset = this->mExpression.mOffset;
  if ( !mOffset )
    return 0;
  v8 = (char *)&this->mExpression + mOffset;
  if ( !v8 || !m_pComponent )
    return 0;
  (*(void (__fastcall **)(char *, char *, unsigned int *, _QWORD, _QWORD))(*(_QWORD *)v8 + 24i64))(
    v8,
    v10,
    &m_pComponent[1].m_TypeUID,
    0i64,
    0i64);
  return v10[0] != 0;
}

// File Line: 360
// RVA: 0x2942E0
void __fastcall UELExpressionCondition::Serialize(UELExpressionCondition *this, IActionTreeSerializer *serializer)
{
  BinString::Set(&this->mExpressionText, &customCaption);
}

// File Line: 376
// RVA: 0x148CE90
__int64 dynamic_initializer_for__WasBittenCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WasBittenCondition", 0xFFFFFFFF);
  WasBittenCondition::sClassNameUID = result;
  return result;
}

// File Line: 379
// RVA: 0x293700
bool __fastcall WasBittenCondition::Match(WasBittenCondition *this, ActionContext *context)
{
  return *((_BYTE *)UFG::LocalPlayerIsInCombatManager::s_pInstance + 120) & 1;
}

// File Line: 396
// RVA: 0x148A7D0
__int64 dynamic_initializer_for__ActiveProgressionFlowCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActiveProgressionFlowCondition", 0xFFFFFFFF);
  ActiveProgressionFlowCondition::sClassNameUID = result;
  return result;
}

// File Line: 401
// RVA: 0x27E270
bool __fastcall ActiveProgressionFlowCondition::Match(ActiveProgressionFlowCondition *this, ActionContext *context)
{
  UFG::ProgressionTracker *v3; // rax

  v3 = UFG::ProgressionTracker::Instance();
  return UFG::ProgressionTracker::GetActiveFlow(v3)->mUID == this->m_FlowName.mUID;
}

// File Line: 420
// RVA: 0x14919D0
__int64 dynamic_initializer_for__actionEnumState__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &actionEnumState,
    gActionRequestStatesStrings,
    gActionRequestStatesStringsCount,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__actionEnumState__);
}

// File Line: 422
// RVA: 0x148ADD0
__int64 dynamic_initializer_for__FacialRequestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FacialRequestCondition", 0xFFFFFFFF);
  FacialRequestCondition::sClassNameUID = result;
  return result;
}

// File Line: 431
// RVA: 0x276E90
void __fastcall FacialRequestCondition::FacialRequestCondition(FacialRequestCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FacialRequestCondition::`vftable;
  *(_DWORD *)&this->mFacialRequest = 0;
}

// File Line: 435
// RVA: 0x2819F0
unsigned __int8 __fastcall FacialRequestCondition::Match(FacialRequestCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v4; // rax
  Intention *p_m_Intention; // r8
  unsigned __int64 v6; // rax
  unsigned __int8 result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( (m_pPointer->m_Flags & 0x4000) == 0 )
    return 0;
  if ( m_pPointer )
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
  else
    v4 = 0i64;
  p_m_Intention = &v4->m_Intention;
  v6 = v4->m_Intention.mFacialRequests.mBits[(__int64)this->mFacialRequest >> 6];
  result = _bittest64((const __int64 *)&v6, this->mFacialRequest & 0x3F);
  if ( !this->mRequestState.mValue )
  {
    if ( result )
      return p_m_Intention->mFacialRequestChargeTimes[this->mFacialRequest] == 0;
  }
  return result;
}

// File Line: 475
// RVA: 0x148A7B0
__int64 dynamic_initializer_for__ActionRequestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionRequestCondition", 0xFFFFFFFF);
  ActionRequestCondition::sClassNameUID = result;
  return result;
}

// File Line: 484
// RVA: 0x276370
void __fastcall ActionRequestCondition::ActionRequestCondition(ActionRequestCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestCondition::`vftable;
  this->mActionRequest = gActionRequest_INVALID.m_EnumValue;
  this->mRequestState.mValue = 0;
}

// File Line: 488
// RVA: 0x27E1F0
unsigned __int8 __fastcall ActionRequestCondition::Match(ActionRequestCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v4; // rax
  Intention *p_m_Intention; // r8
  unsigned __int64 v6; // rax
  unsigned __int8 result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( (m_pPointer->m_Flags & 0x4000) == 0 )
    return 0;
  if ( m_pPointer )
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
  else
    v4 = 0i64;
  p_m_Intention = &v4->m_Intention;
  v6 = v4->m_Intention.mActionRequests.mBits[(__int64)this->mActionRequest >> 6];
  result = _bittest64((const __int64 *)&v6, this->mActionRequest & 0x3F);
  if ( !this->mRequestState.mValue )
  {
    if ( result )
      return p_m_Intention->mActionRequestChargeTimes[this->mActionRequest] == 0;
  }
  return result;
}

// File Line: 523
// RVA: 0x1491A40
__int64 dynamic_initializer_for__clothingPurchaseEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &clothingPurchaseEnum,
    gClothingPurchaseStatesStrings,
    gClothingPurchaseStatesStringsCount,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__clothingPurchaseEnum__);
}

// File Line: 529
// RVA: 0x148AAD0
__int64 dynamic_initializer_for__ClothingPurchaseCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ClothingPurchaseCondition", 0xFFFFFFFF);
  ClothingPurchaseCondition::sClassNameUID = result;
  return result;
}

// File Line: 536
// RVA: 0x2768B0
void __fastcall ClothingPurchaseCondition::ClothingPurchaseCondition(ClothingPurchaseCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ClothingPurchaseCondition::`vftable;
  this->mClothingPurchase = gActionRequest_Action.m_EnumValue;
}

// File Line: 540
// RVA: 0x27FFD0
char __fastcall ClothingPurchaseCondition::Match(ClothingPurchaseCondition *this, ActionContext *context)
{
  hkpNullContactMgrFactory *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  hkpNullContactMgr *ContactMgr; // rax

  v3 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  ContactMgr = hkpNullContactMgrFactory::createContactMgr(v3, v4, v5, v6);
  if ( !ContactMgr
    || !LODWORD(ContactMgr[1].vfptr)
    || this->mClothingPurchase != UFG::StoreFront::mLastEquipedItemCategory )
  {
    return 0;
  }
  UFG::StoreFront::mLastEquipedItemCategory = Num_ItemCategories;
  return 1;
}

// File Line: 569
// RVA: 0x148B630
__int64 dynamic_initializer_for__IsPlayingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayingCondition", 0xFFFFFFFF);
  IsPlayingCondition::sClassNameUID = result;
  return result;
}

// File Line: 576
// RVA: 0x284530
unsigned __int8 __fastcall IsPlayingCondition::Match(IsPlayingCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  ActionContext *v4; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rax
  ActionContext *i; // rax
  bool v11; // r9
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  ActionController *mActionController; // rcx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( (m_pPointer->m_Flags & 0x8000u) != 0 && m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[19].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIActionTreeComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIActionTreeComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[19].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 )
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        else
          v9 = (UFG::AiDriverComponent *)((v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AiDriverComponent::_TypeUID)
                                        : UFG::SimObject::GetComponentOfType(v7, UFG::AiDriverComponent::_TypeUID));
        if ( v9 )
        {
          for ( i = v4->mParentContext; i; i = i->mParentContext )
            v4 = i;
          v11 = this->mCheckSpawn != 0;
          goto LABEL_39;
        }
      }
    }
  }
  if ( !this->mCheckSpawn )
  {
    v11 = 0;
    goto LABEL_39;
  }
  v12 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( !v12
    || ((v13 = v12->m_Flags, (v13 & 0x4000) == 0)
      ? (v13 >= 0
       ? ((v13 & 0x2000) == 0
        ? ((v13 & 0x1000) == 0
         ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::ActionTreeComponent::_TypeUID))
         : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID)))
        : (ComponentOfType = v12->m_Components.p[6].m_pComponent))
       : (ComponentOfType = v12->m_Components.p[7].m_pComponent))
      : (ComponentOfType = v12->m_Components.p[7].m_pComponent),
        !ComponentOfType) )
  {
    v11 = 1;
LABEL_39:
    mActionController = v4->mActionController;
    return ActionController::IsPlaying(mActionController, &this->mActionNodeName, this->mMostUsedIndex, v11);
  }
  mActionController = (ActionController *)&ComponentOfType[3];
  v11 = 1;
  return ActionController::IsPlaying(mActionController, &this->mActionNodeName, this->mMostUsedIndex, v11);
}

// File Line: 641
// RVA: 0x148B6F0
__int64 dynamic_initializer_for__IsPlayingThisCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayingThisCondition", 0xFFFFFFFF);
  IsPlayingThisCondition::sClassNameUID = result;
  return result;
}

// File Line: 646
// RVA: 0x284B80
bool __fastcall IsPlayingThisCondition::Match(IsPlayingThisCondition *this, ActionContext *context)
{
  __int64 mOffset; // r8

  mOffset = this->mThisNode.mOffset;
  if ( mOffset )
    return context->mActionController->m_currentNode == (ActionNodePlayable *)((char *)&this->mThisNode + mOffset);
  else
    return context->mActionController->m_currentNode == 0i64;
}

// File Line: 662
// RVA: 0x148B710
__int64 dynamic_initializer_for__IsPlayingThisInPathCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayingThisInPathCondition", 0xFFFFFFFF);
  IsPlayingThisInPathCondition::sClassNameUID = result;
  return result;
}

// File Line: 667
// RVA: 0x284BB0
char __fastcall IsPlayingThisInPathCondition::Match(IsPlayingThisInPathCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  ActionNodePlayable *v3; // rcx
  ActionNodePlayable *m_currentNode; // rax
  __int64 v5; // rdx

  mOffset = this->mThisNode.mOffset;
  if ( mOffset )
    v3 = (ActionNodePlayable *)((char *)&this->mThisNode + mOffset);
  else
    v3 = 0i64;
  m_currentNode = context->mActionController->m_currentNode;
  if ( m_currentNode )
  {
    while ( 1 )
    {
      v5 = m_currentNode->mParent.mOffset;
      if ( !v5 || !(UFG::qOffset64<ActionNode *> *)((char *)&m_currentNode->mParent + v5) )
        break;
      if ( (unsigned int)v3 >= (unsigned int)m_currentNode )
      {
        if ( v3 == m_currentNode )
          return 1;
        if ( (unsigned int)v3 > (unsigned int)m_currentNode )
          return 0;
      }
      m_currentNode = (ActionNodePlayable *)((char *)m_currentNode + v5 + 16);
    }
  }
  return 0;
}

// File Line: 683
// RVA: 0x148B690
__int64 dynamic_initializer_for__IsPlayingNodeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayingNodeCondition", 0xFFFFFFFF);
  IsPlayingNodeCondition::sClassNameUID = result;
  return result;
}

// File Line: 690
// RVA: 0x284850
char __fastcall IsPlayingNodeCondition::Match(IsPlayingNodeCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  __int64 v5; // rcx
  ActionNodePlayable *v6; // r10
  char mCheckSpawn; // cl
  bool v8; // zf
  ActionContext *i; // rax

  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    mOffset += (__int64)&this->mActionNodeReference;
  v5 = *(_QWORD *)(mOffset + 72);
  if ( !v5 )
    return 0;
  v6 = (ActionNodePlayable *)(v5 + mOffset + 72);
  if ( !v6 )
    return 0;
  mCheckSpawn = this->mCheckSpawn;
  v8 = mCheckSpawn == 0;
  if ( mCheckSpawn )
  {
    for ( i = context->mParentContext; i; i = i->mParentContext )
      context = i;
    v8 = mCheckSpawn == 0;
  }
  return ActionController::IsPlayingFullPath(context->mActionController, v6, !v8);
}

// File Line: 713
// RVA: 0x27AE60
Expression::IMemberMap *__fastcall IsPlayingNodeCondition::CreateClone(IsPlayingNodeCondition *this)
{
  char *v2; // rax
  char *v3; // rbx
  ActionNodeReference *v4; // rdi
  __int64 mOffset; // rax
  ActionNodeReference *v6; // rdx
  __int64 v7; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "IsPlayingNodeCondition::CreateClone", 0i64, 1u);
  v3 = v2;
  v4 = 0i64;
  if ( v2 )
  {
    NodeRefCondition::NodeRefCondition((NodeRefCondition *)v2);
    *(_QWORD *)v3 = &IsPlayingNodeCondition::`vftable;
    v3[32] = 0;
  }
  else
  {
    v3 = 0i64;
  }
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    v6 = (ActionNodeReference *)((char *)&this->mActionNodeReference + mOffset);
  else
    v6 = 0i64;
  v7 = *((_QWORD *)v3 + 3);
  if ( v7 )
    v4 = (ActionNodeReference *)&v3[v7 + 24];
  ActionNodeReference::CopyFrom(v4, v6);
  return (Expression::IMemberMap *)v3;
}

// File Line: 737
// RVA: 0x148B6D0
__int64 dynamic_initializer_for__IsPlayingPreviousCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayingPreviousCondition", 0xFFFFFFFF);
  IsPlayingPreviousCondition::sClassNameUID = result;
  return result;
}

// File Line: 744
// RVA: 0x284920
char __fastcall IsPlayingPreviousCondition::Match(IsPlayingPreviousCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  ActionContext *v4; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rax
  ActionContext *i; // rax
  bool v11; // r8
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v15; // rcx
  __int64 mActionController; // rcx
  __int16 v17; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[19].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIActionTreeComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIActionTreeComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[19].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 )
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        else
          v9 = (UFG::AiDriverComponent *)((v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AiDriverComponent::_TypeUID)
                                        : UFG::SimObject::GetComponentOfType(v7, UFG::AiDriverComponent::_TypeUID));
        if ( v9 )
        {
          for ( i = v4->mParentContext; i; i = i->mParentContext )
            v4 = i;
          v11 = this->mCheckSpawn != 0;
          goto LABEL_48;
        }
      }
    }
  }
  if ( !this->mCheckSpawn )
  {
    v11 = 0;
    goto LABEL_48;
  }
  v12 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( !v12
    || ((v13 = v12->m_Flags, (v13 & 0x4000) == 0)
      ? (v13 >= 0
       ? ((v13 & 0x2000) == 0
        ? ((v13 & 0x1000) == 0
         ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::ActionTreeComponent::_TypeUID))
         : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID)))
        : (ComponentOfType = v12->m_Components.p[6].m_pComponent))
       : (ComponentOfType = v12->m_Components.p[7].m_pComponent))
      : (ComponentOfType = v12->m_Components.p[7].m_pComponent),
        !ComponentOfType) )
  {
    v11 = 1;
LABEL_48:
    mActionController = (__int64)v4->mActionController;
    return ActionController::WasPlaying((ActionController *)mActionController, &this->mActionNodeName, v11);
  }
  v15 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v15 )
  {
    v17 = v15->m_Flags;
    if ( (v17 & 0x4000) != 0 || v17 < 0 )
    {
      v11 = 1;
      mActionController = (__int64)&v15->m_Components.p[7].m_pComponent[3];
    }
    else if ( (v17 & 0x2000) != 0 )
    {
      v11 = 1;
      mActionController = (__int64)&v15->m_Components.p[6].m_pComponent[3];
    }
    else
    {
      if ( (v17 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::ActionTreeComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v15, UFG::ActionTreeComponent::_TypeUID);
      v11 = 1;
      mActionController = (__int64)&ComponentOfTypeHK[3];
    }
  }
  else
  {
    v11 = 1;
    mActionController = 192i64;
  }
  return ActionController::WasPlaying((ActionController *)mActionController, &this->mActionNodeName, v11);
}

// File Line: 792
// RVA: 0x148B6B0
__int64 dynamic_initializer_for__IsPlayingNodePreviousCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayingNodePreviousCondition", 0xFFFFFFFF);
  IsPlayingNodePreviousCondition::sClassNameUID = result;
  return result;
}

// File Line: 799
// RVA: 0x2848C0
char __fastcall IsPlayingNodePreviousCondition::Match(IsPlayingNodePreviousCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  __int64 v5; // rcx
  ActionNodePlayable *v6; // r9
  ActionContext *i; // rax

  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    mOffset += (__int64)&this->mActionNodeReference;
  v5 = *(_QWORD *)(mOffset + 72);
  if ( !v5 )
    return 0;
  v6 = (ActionNodePlayable *)(v5 + mOffset + 72);
  if ( !v6 )
    return 0;
  if ( this->mCheckSpawn )
  {
    for ( i = context->mParentContext; i; i = i->mParentContext )
      context = i;
  }
  return ActionController::WasPlayingFullPath(context->mActionController, v6);
}

// File Line: 822
// RVA: 0x27AF10
Expression::IMemberMap *__fastcall IsPlayingNodePreviousCondition::CreateClone(IsPlayingNodePreviousCondition *this)
{
  char *v2; // rax
  char *v3; // rbx
  ActionNodeReference *v4; // rdi
  __int64 mOffset; // rax
  ActionNodeReference *v6; // rdx
  __int64 v7; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "IsPlayingNodeCondition::CreateClone", 0i64, 1u);
  v3 = v2;
  v4 = 0i64;
  if ( v2 )
  {
    NodeRefCondition::NodeRefCondition((NodeRefCondition *)v2);
    *(_QWORD *)v3 = &IsPlayingNodePreviousCondition::`vftable;
    v3[32] = 1;
  }
  else
  {
    v3 = 0i64;
  }
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    v6 = (ActionNodeReference *)((char *)&this->mActionNodeReference + mOffset);
  else
    v6 = 0i64;
  v7 = *((_QWORD *)v3 + 3);
  if ( v7 )
    v4 = (ActionNodeReference *)&v3[v7 + 24];
  ActionNodeReference::CopyFrom(v4, v6);
  return (Expression::IMemberMap *)v3;
}

// File Line: 846
// RVA: 0x148B670
__int64 dynamic_initializer_for__IsPlayingNextCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayingNextCondition", 0xFFFFFFFF);
  IsPlayingNextCondition::sClassNameUID = result;
  return result;
}

// File Line: 852
// RVA: 0x2847A0
char __fastcall IsPlayingNextCondition::Match(IsPlayingNextCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
    else
      m_pComponent = (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  mNext = m_pComponent[3].m_BoundComponentHandles.mNode.mNext;
  if ( !mNext )
    return 0;
  while ( LODWORD(mNext[2].mNext) != this->mActionNodeName.mUID )
  {
    mPrev = mNext[1].mPrev;
    v8 = mNext + 1;
    if ( mPrev )
    {
      mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)((char *)v8
                                                                                                + (_QWORD)mPrev);
      if ( mNext )
        continue;
    }
    return 0;
  }
  return 1;
}

// File Line: 888
// RVA: 0x148C3F0
__int64 dynamic_initializer_for__TargetIsPlayingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsPlayingCondition", 0xFFFFFFFF);
  TargetIsPlayingCondition::sClassNameUID = result;
  return result;
}

// File Line: 901
// RVA: 0x28CC90
unsigned __int8 __fastcall TargetIsPlayingCondition::Match(TargetIsPlayingCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned int mTargetType; // eax
  UFG::SimObjectGame *v9; // rcx
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  __int16 v13; // dx
  UFG::SimComponent *v14; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  mTargetType = this->mTargetType;
  if ( m_pComponent )
  {
    v9 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + mTargetType + 8i64)
                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                + 40);
  }
  else
  {
    if ( mTargetType != 2 )
      return 0;
    v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( !v10 )
      return 0;
    v11 = v10->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      v12 = v10->m_Components.p[15].m_pComponent;
    }
    else if ( v11 >= 0 )
    {
      v12 = (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HitReactionComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(v10, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      v12 = v10->m_Components.p[15].m_pComponent;
    }
    if ( !v12 )
      return 0;
    v9 = *(UFG::SimObjectGame **)&v12[3].m_TypeUID;
  }
  if ( v9 )
  {
    v13 = v9->m_Flags;
    if ( (v13 & 0x4000) != 0 )
    {
      v14 = v9->m_Components.p[7].m_pComponent;
    }
    else if ( v13 >= 0 )
    {
      if ( (v13 & 0x2000) != 0 )
        v14 = v9->m_Components.p[6].m_pComponent;
      else
        v14 = (v13 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::ActionTreeComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v9, UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v14 = v9->m_Components.p[7].m_pComponent;
    }
    if ( v14 )
      return ActionController::IsPlaying(
               (ActionController *)&v14[3],
               &this->mActionNodeName,
               this->mMostUsedIndex,
               this->mCheckSpawn != 0);
  }
  return 0;
}

// File Line: 942
// RVA: 0x2942C0
void __fastcall TargetIsPlayingCondition::Serialize(TargetIsPlayingCondition *this, IActionTreeSerializer *serializer)
{
  this->mMostUsedIndex = GetMostUsedIndex(this->mActionNodeName.mUID);
}

// File Line: 956
// RVA: 0x148C430
__int64 dynamic_initializer_for__TargetIsSubTargetValid::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsSubTargetValid", 0xFFFFFFFF);
  TargetIsSubTargetValid::sClassNameUID = result;
  return result;
}

// File Line: 968
// RVA: 0x28CFC0
bool __fastcall TargetIsSubTargetValid::Match(TargetIsSubTargetValid *this, ActionContext *context)
{
  int m_SubTargetType; // edx
  UFG::SimObject *Target; // rax
  UFG::SimObject *mNext; // rsi
  __int16 m_Flags; // dx
  UFG::InterestPoint *m_pComponent; // rbx
  UFG::SimObjectGame *Parent; // rax
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SceneObjectProperties *v16; // rcx
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  int m_AssignToTargetType; // ebx
  UFG::TargetingSystemBaseComponent *v22; // rax
  __int16 v23; // dx
  unsigned int v24; // edx
  bool v25; // zf
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol name; // [rsp+50h] [rbp+18h] BYREF

  m_SubTargetType = this->m_SubTargetType;
  if ( !m_SubTargetType )
    return 0;
  Target = UFG::getTarget(context->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)m_SubTargetType);
  mNext = 0i64;
  if ( Target )
  {
    m_Flags = Target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[25].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[10].m_pComponent;
      else
        m_pComponent = (UFG::InterestPoint *)((m_Flags & 0x1000) != 0
                                            ? Target->m_Components.p[3].m_pComponent
                                            : UFG::SimObject::GetComponentOfType(Target, UFG::InterestPoint::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[25].m_pComponent;
    }
    if ( m_pComponent )
    {
      TargetIsSubTargetValid::GetSubTargetName(this, &result);
      if ( this->m_RetrieveParent )
      {
        Parent = (UFG::SimObjectGame *)UFG::InterestPoint::GetParent(m_pComponent);
      }
      else if ( result.mUID == -1 )
      {
        Parent = (UFG::SimObjectGame *)UFG::InterestPoint::GetChild(m_pComponent, this->m_Index);
      }
      else
      {
        Parent = (UFG::SimObjectGame *)UFG::InterestPoint::GetChild(m_pComponent, &result);
      }
      if ( Parent )
      {
        if ( this->m_WantSubTargetUser )
        {
          v11 = Parent->m_Flags;
          if ( (v11 & 0x4000) != 0 )
          {
            ComponentOfType = Parent->m_Components.p[25].m_pComponent;
          }
          else if ( v11 >= 0 )
          {
            if ( (v11 & 0x2000) != 0 )
            {
              ComponentOfType = Parent->m_Components.p[10].m_pComponent;
            }
            else if ( (v11 & 0x1000) != 0 )
            {
              ComponentOfType = Parent->m_Components.p[3].m_pComponent;
            }
            else
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(Parent, UFG::InterestPoint::_TypeUID);
            }
          }
          else
          {
            ComponentOfType = Parent->m_Components.p[25].m_pComponent;
          }
          if ( ComponentOfType )
            mNext = (UFG::SimObject *)ComponentOfType[5].m_BoundComponentHandles.mNode.mNext;
        }
        else if ( this->m_AsSpawnpointSpawn )
        {
          v13 = Parent->m_Flags;
          if ( (v13 & 0x4000) != 0 || v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(Parent, UFG::SpawnPoint::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(Parent, UFG::SpawnPoint::_TypeUID);
          if ( ComponentOfTypeHK )
          {
            m_pSimObject = ComponentOfTypeHK->m_pSimObject;
            v16 = m_pSimObject ? m_pSimObject->m_pSceneObj : 0i64;
            ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(v16, 0);
            if ( ChildAsSceneObject )
            {
              mpWritableProperties = ChildAsSceneObject->mpWritableProperties;
              if ( !mpWritableProperties )
                mpWritableProperties = ChildAsSceneObject->mpConstProperties;
              name.mUID = mpWritableProperties->mName.mUID;
              SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
              if ( SimObject )
                mNext = (UFG::SimObject *)SimObject;
            }
          }
        }
        else
        {
          mNext = Parent;
        }
      }
      if ( this->m_AssignResult )
      {
        m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
        m_AssignToTargetType = this->m_AssignToTargetType;
        if ( m_pPointer )
        {
          v23 = m_pPointer->m_Flags;
          if ( (v23 & 0x4000) != 0 || v23 < 0 )
          {
            v22 = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
          }
          else
          {
            if ( (v23 & 0x2000) != 0 )
            {
              v24 = UFG::TargetingSystemBaseComponent::_TypeUID;
            }
            else
            {
              v25 = (v23 & 0x1000) == 0;
              v24 = UFG::TargetingSystemBaseComponent::_TypeUID;
              if ( v25 )
              {
                v22 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::TargetingSystemBaseComponent::_TypeUID);
                goto LABEL_61;
              }
            }
            v22 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v24);
          }
        }
        else
        {
          v22 = 0i64;
        }
LABEL_61:
        UFG::TargetingSystemBaseComponent::SetTarget(v22, (UFG::eTargetTypeEnum)m_AssignToTargetType, mNext);
      }
    }
  }
  return mNext != 0i64;
}

// File Line: 1067
// RVA: 0x148B590
__int64 dynamic_initializer_for__IsPlayerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayerCondition", 0xFFFFFFFF);
  IsPlayerCondition::sClassNameUID = result;
  return result;
}

// File Line: 1070
// RVA: 0x284450
bool __fastcall IsPlayerCondition::Match(IsPlayerCondition *this, ActionContext *context)
{
  return UFG::IsAnyLocalPlayer(context->mSimObject.m_pPointer);
}

// File Line: 1085
// RVA: 0x148B470
__int64 dynamic_initializer_for__IsHostCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsHostCondition", 0xFFFFFFFF);
  IsHostCondition::sClassNameUID = result;
  return result;
}

// File Line: 1107
// RVA: 0x148B5D0
__int64 dynamic_initializer_for__IsPlayerInClothingStore::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayerInClothingStore", 0xFFFFFFFF);
  IsPlayerInClothingStore::sClassNameUID = result;
  return result;
}

// File Line: 1110
// RVA: 0x2844A0
bool __fastcall IsPlayerInClothingStore::Match(IsPlayerInClothingStore *this, ActionContext *context)
{
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  hkpNullContactMgr *ContactMgr; // rax

  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  ContactMgr = hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
  return ContactMgr && LODWORD(ContactMgr[1].vfptr);
}

// File Line: 1134
// RVA: 0x148B3F0
__int64 dynamic_initializer_for__IsFemaleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsFemaleCondition", 0xFFFFFFFF);
  IsFemaleCondition::sClassNameUID = result;
  return result;
}

// File Line: 1138
// RVA: 0x283F10
bool __fastcall IsFemaleCondition::Match(IsFemaleCondition *this, ActionContext *pContext)
{
  return UFG::IsFemale(pContext->mSimObject.m_pPointer);
}

// File Line: 1155
// RVA: 0x148C330
__int64 dynamic_initializer_for__TargetIsFemaleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsFemaleCondition", 0xFFFFFFFF);
  TargetIsFemaleCondition::sClassNameUID = result;
  return result;
}

// File Line: 1161
// RVA: 0x278B50
void __fastcall TargetIsFemaleCondition::TargetIsFemaleCondition(TargetIsFemaleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsFemaleCondition::`vftable;
  this->mTargetType.mValue = 0;
}

// File Line: 1165
// RVA: 0x28C7C0
bool __fastcall TargetIsFemaleCondition::Match(TargetIsFemaleCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent)
        && UFG::IsFemale(*(UFG::SimObject **)(56i64
                                            * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                                 + *(_QWORD *)&m_pComponent[1].m_Flags
                                                                 + 8i64)
                                            + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                            + 40));
  return result;
}

// File Line: 1188
// RVA: 0x148B7D0
__int64 dynamic_initializer_for__IsTakingDamageCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsTakingDamageCondition", 0xFFFFFFFF);
  IsTakingDamageCondition::sClassNameUID = result;
  return result;
}

// File Line: 1191
// RVA: 0x284D30
bool __fastcall IsTakingDamageCondition::Match(IsTakingDamageCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[6].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[6].m_pComponent),
        ComponentOfTypeHK) )
  {
    return BYTE6(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    return 0;
  }
}

// File Line: 1215
// RVA: 0x148B4D0
__int64 dynamic_initializer_for__IsInvulnerableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsInvulnerableCondition", 0xFFFFFFFF);
  IsInvulnerableCondition::sClassNameUID = result;
  return result;
}

// File Line: 1218
// RVA: 0x283FE0
bool __fastcall IsInvulnerableCondition::Match(IsInvulnerableCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[6].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[6].m_pComponent),
        ComponentOfTypeHK) )
  {
    return BYTE5(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    return 0;
  }
}

// File Line: 1241
// RVA: 0x148AEF0
__int64 dynamic_initializer_for__HasRagdollCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasRagdollCondition", 0xFFFFFFFF);
  HasRagdollCondition::sClassNameUID = result;
  return result;
}

// File Line: 1247
// RVA: 0x281F70
bool __fastcall HasRagdollCondition::Match(HasRagdollCondition *this, ActionContext *pContext)
{
  return UFG::HasRagdoll(pContext->mSimObject.m_pPointer, this->mbActive != 0);
}

// File Line: 1265
// RVA: 0x148BE70
__int64 dynamic_initializer_for__RagdollHasConstraintsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollHasConstraintsCondition", 0xFFFFFFFF);
  RagdollHasConstraintsCondition::sClassNameUID = result;
  return result;
}

// File Line: 1268
// RVA: 0x2783D0
void __fastcall RagdollHasConstraintsCondition::RagdollHasConstraintsCondition(RagdollHasConstraintsCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollHasConstraintsCondition::`vftable;
  this->mAttachJointName.mUID = -1;
  this->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 1273
// RVA: 0x289340
bool __fastcall RagdollHasConstraintsCondition::Match(RagdollHasConstraintsCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::RagdollComponent::_TypeUID))
           : (ComponentOfType = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::RagdollComponent::_TypeUID)))
          : (ComponentOfType = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent),
            ComponentOfType)
        && UFG::RagdollComponent::HasConstraints(ComponentOfType);
  return result;
}

// File Line: 1306
// RVA: 0x1491B00
__int64 dynamic_initializer_for__gMinigameListEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gMinigameListEnum, gMinigameListNames, gMinigameListCount, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMinigameListEnum__);
}

// File Line: 1307
// RVA: 0x148B8B0
__int64 dynamic_initializer_for__MinigameSuccessCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MinigameSuccessCondition", 0xFFFFFFFF);
  MinigameSuccessCondition::sClassNameUID = result;
  return result;
}

// File Line: 1312
// RVA: 0x285310
_BOOL8 __fastcall MinigameSuccessCondition::Match(MinigameSuccessCondition *this, ActionContext *context)
{
  int mMinigame; // edx
  _BOOL8 result; // rax

  mMinigame = this->mMinigame;
  if ( !mMinigame )
    return UFG::UIHKScreenPickLockMinigame::m_bWon;
  if ( mMinigame == 1 )
    return UFG::UIHKScreenSafeCrackingMinigame::m_bWon;
  result = 0i64;
  if ( mMinigame == 2 )
    return UFG::UIHKScreenHackingMinigame::m_bWon;
  return result;
}

// File Line: 1350
// RVA: 0x148B970
__int64 dynamic_initializer_for__MotionIntentionSpeed::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionIntentionSpeed", 0xFFFFFFFF);
  MotionIntentionSpeed::sClassNameUID = result;
  return result;
}

// File Line: 1358
// RVA: 0x277B70
void __fastcall MotionIntentionSpeed::MotionIntentionSpeed(MotionIntentionSpeed *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionSpeed::`vftable;
  this->mSpeed = 0.0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 1363
// RVA: 0x285C40
char __fastcall MotionIntentionSpeed::Match(MotionVelocityMagnitude *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          m_pPointer,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mSpeed,
             ComponentOfTypeHK->m_Intention.mMotionIntentionSpeed);
  }
  else
  {
    return 0;
  }
}

// File Line: 1393
// RVA: 0x148B990
__int64 dynamic_initializer_for__MotionIntentionSpeedRaw::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionIntentionSpeedRaw", 0xFFFFFFFF);
  MotionIntentionSpeedRaw::sClassNameUID = result;
  return result;
}

// File Line: 1401
// RVA: 0x277BB0
void __fastcall MotionIntentionSpeedRaw::MotionIntentionSpeedRaw(MotionIntentionSpeedRaw *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionSpeedRaw::`vftable;
  this->mSpeed = 0.0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 1406
// RVA: 0x285CE0
char __fastcall MotionIntentionSpeedRaw::Match(MotionIntentionSpeedRaw *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          m_pPointer,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mSpeed,
             ComponentOfTypeHK->m_Intention.mMotionIntentionSpeedRaw);
  }
  else
  {
    return 0;
  }
}

// File Line: 1436
// RVA: 0x148ADF0
__int64 dynamic_initializer_for__FacingIntentionDirection::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FacingIntentionDirection", 0xFFFFFFFF);
  FacingIntentionDirection::sClassNameUID = result;
  return result;
}

// File Line: 1444
// RVA: 0x276ED0
void __fastcall FacingIntentionDirection::FacingIntentionDirection(FacingIntentionDirection *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FacingIntentionDirection::`vftable;
  this->mDirection = 0.0;
  this->mAngleRange = 1.5707964;
}

// File Line: 1449
// RVA: 0x281A70
bool __fastcall FacingIntentionDirection::Match(FacingIntentionDirection *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::AICharacterControllerBaseComponent *v6; // rax
  UFG::AICharacterControllerBaseComponent *v7; // rbx
  UFG::SimObject *v8; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
  else
    v6 = (UFG::AICharacterControllerBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID));
  v7 = v6;
  if ( !v6 )
    return 0;
  v8 = context->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  m_pTransformNodeComponent = v8->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  return UFG::qAngleBetween(
           &v7->m_Intention.mFacingIntentionDirection,
           (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform) <= this->mAngleRange;
}

// File Line: 1485
// RVA: 0x148AE10
__int64 dynamic_initializer_for__FacingPelvisDirection::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FacingPelvisDirection", 0xFFFFFFFF);
  FacingPelvisDirection::sClassNameUID = result;
  return result;
}

// File Line: 1493
// RVA: 0x276F10
void __fastcall FacingPelvisDirection::FacingPelvisDirection(FacingPelvisDirection *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FacingPelvisDirection::`vftable;
  this->mDirection = 0.0;
  this->mAngleRange = 1.5707964;
}

// File Line: 1497
// RVA: 0x1491A10
__int64 dynamic_initializer_for__bip01PelvisUC_UID__()
{
  UFG::qSymbolUC::create_from_string(&bip01PelvisUC_UID, "Bip01 Pelvis");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__bip01PelvisUC_UID__);
}

// File Line: 1500
// RVA: 0x281B60
bool __fastcall FacingPelvisDirection::Match(FacingPelvisDirection *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v5; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  UFG::qVector3 v1; // [rsp+20h] [rbp-58h] BYREF
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-48h] BYREF

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
  if ( !mCreature->mPose.mRigHandle.mData )
    return 0;
  BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, bip01PelvisUC_UID.mUID);
  if ( BoneID < 0 )
    return 0;
  *(_QWORD *)&v1.x = 0i64;
  LODWORD(v1.z) = (_DWORD)FLOAT_1_0;
  Creature::GetTransform(mCreature, BoneID, &transform);
  return UFG::qAngleBetween(&v1, (UFG::qVector3 *)&transform.v1) <= this->mAngleRange;
}

// File Line: 1542
// RVA: 0x148B8F0
__int64 dynamic_initializer_for__MotionIntentionDirection::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionIntentionDirection", 0xFFFFFFFF);
  MotionIntentionDirection::sClassNameUID = result;
  return result;
}

// File Line: 1552
// RVA: 0x277A20
void __fastcall MotionIntentionDirection::MotionIntentionDirection(MotionIntentionDirection *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionDirection::`vftable;
  *(_QWORD *)&this->mDirection = 0i64;
  this->mDirectionCos = 1.0;
  this->mAngleRange = 1.5707964;
}

// File Line: 1557
// RVA: 0x2853E0
bool __fastcall MotionIntentionDirection::Match(MotionIntentionDirection *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::AICharacterControllerBaseComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __int16 v9; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  float mDirectionCos; // xmm6_4
  float mDirectionSin; // xmm7_4
  UFG::qVector3 *p_mMotionIntentionDirection; // rbp
  UFG::SimObject *v14; // rax
  float v15; // xmm6_4
  float v16; // xmm7_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-38h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
  else
    v6 = (UFG::AICharacterControllerBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID));
  if ( !v6 )
    return 0;
  v7 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !v7 || !v7->m_pTransformNodeComponent )
    return 0;
  m_pTransformNodeComponent = 0i64;
  v9 = v7->m_Flags;
  if ( (v9 & 0x4000) != 0 || v9 < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v7);
  }
  else if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
  {
    ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v7,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v7,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
  }
  mDirectionCos = this->mDirectionCos;
  mDirectionSin = this->mDirectionSin;
  p_mMotionIntentionDirection = &ComponentOfTypeHK->m_Intention.mMotionIntentionDirection;
  v14 = context->mSimObject.m_pPointer;
  if ( v14 )
    m_pTransformNodeComponent = v14->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v2.x = (float)(mDirectionSin * m_pTransformNodeComponent->mWorldTransform.v0.y)
       + (float)(mDirectionCos * m_pTransformNodeComponent->mWorldTransform.v0.x);
  v15 = mDirectionCos * m_pTransformNodeComponent->mWorldTransform.v0.y;
  v16 = mDirectionSin * m_pTransformNodeComponent->mWorldTransform.v0.x;
  v2.z = 0.0;
  v2.y = v15 - v16;
  return UFG::qAngleBetween(p_mMotionIntentionDirection, &v2) <= this->mAngleRange;
}

// File Line: 1605
// RVA: 0x148B910
__int64 dynamic_initializer_for__MotionIntentionDirectionRaw::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionIntentionDirectionRaw", 0xFFFFFFFF);
  MotionIntentionDirectionRaw::sClassNameUID = result;
  return result;
}

// File Line: 1615
// RVA: 0x277A70
void __fastcall MotionIntentionDirectionRaw::MotionIntentionDirectionRaw(MotionIntentionDirectionRaw *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionDirectionRaw::`vftable;
  *(_QWORD *)&this->mDirection = 0i64;
  this->mDirectionCos = 1.0;
  this->mAngleRange = 1.5707964;
}

// File Line: 1620
// RVA: 0x2855A0
bool __fastcall MotionIntentionDirectionRaw::Match(MotionIntentionDirectionRaw *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::AICharacterControllerBaseComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __int16 v9; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  float mDirectionCos; // xmm6_4
  float mDirectionSin; // xmm7_4
  UFG::qVector3 *p_mMotionIntentionDirectionRaw; // rbp
  UFG::SimObject *v14; // rax
  float v15; // xmm6_4
  float v16; // xmm7_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-38h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
  else
    v6 = (UFG::AICharacterControllerBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID));
  if ( !v6 )
    return 0;
  v7 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !v7 || !v7->m_pTransformNodeComponent )
    return 0;
  m_pTransformNodeComponent = 0i64;
  v9 = v7->m_Flags;
  if ( (v9 & 0x4000) != 0 || v9 < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v7);
  }
  else if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
  {
    ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v7,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v7,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
  }
  mDirectionCos = this->mDirectionCos;
  mDirectionSin = this->mDirectionSin;
  p_mMotionIntentionDirectionRaw = &ComponentOfTypeHK->m_Intention.mMotionIntentionDirectionRaw;
  v14 = context->mSimObject.m_pPointer;
  if ( v14 )
    m_pTransformNodeComponent = v14->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v2.x = (float)(mDirectionSin * m_pTransformNodeComponent->mWorldTransform.v0.y)
       + (float)(mDirectionCos * m_pTransformNodeComponent->mWorldTransform.v0.x);
  v15 = mDirectionCos * m_pTransformNodeComponent->mWorldTransform.v0.y;
  v16 = mDirectionSin * m_pTransformNodeComponent->mWorldTransform.v0.x;
  v2.z = 0.0;
  v2.y = v15 - v16;
  return UFG::qAngleBetween(p_mMotionIntentionDirectionRaw, &v2) <= this->mAngleRange;
}

// File Line: 1667
// RVA: 0x148B930
__int64 dynamic_initializer_for__MotionIntentionDirectionRel::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionIntentionDirectionRel", 0xFFFFFFFF);
  MotionIntentionDirectionRel::sClassNameUID = result;
  return result;
}

// File Line: 1677
// RVA: 0x277AC0
void __fastcall MotionIntentionDirectionRel::MotionIntentionDirectionRel(MotionIntentionDirectionRel *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionDirectionRel::`vftable;
  *(_QWORD *)&this->mDirection = 0i64;
  this->mDirectionCos = 1.0;
  this->mAngleRange = 1.5707964;
}

// File Line: 1682
// RVA: 0x285760
bool __fastcall MotionIntentionDirectionRel::Match(MotionIntentionDirectionRel *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::AICharacterControllerBaseComponent *v6; // rax
  UFG::AICharacterControllerBaseComponent *v7; // rbx
  UFG::SimObjectCVBase *v8; // rcx
  __int16 v9; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  float *mCreature; // rcx
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
  else
    v6 = (UFG::AICharacterControllerBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID));
  v7 = v6;
  if ( !v6 )
    return 0;
  v8 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 || v9 < 0 )
  {
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
  }
  else if ( (v9 & 0x2000) != 0 )
  {
    v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
  }
  else
  {
    v10 = (UFG::CharacterAnimationComponent *)((v9 & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v8,
                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v8,
                                                 UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v10 )
    return 0;
  mCreature = (float *)v10->mCreature;
  if ( !mCreature || mCreature[51] <= 0.000099999997 )
    return 0;
  v12 = mCreature[49];
  v13 = mCreature[48];
  v14 = (float)(v13 * this->mDirectionCos) + (float)(v12 * this->mDirectionSin);
  v15 = (float)(v12 * this->mDirectionCos) - (float)(v13 * this->mDirectionSin);
  v2.x = v14;
  v2.y = v15;
  v2.z = 0.0;
  return UFG::qAngleBetween(&v7->m_Intention.mMotionIntentionDirection, &v2) <= this->mAngleRange;
}

// File Line: 1744
// RVA: 0x148B950
__int64 dynamic_initializer_for__MotionIntentionDirectionRelTarget::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionIntentionDirectionRelTarget", 0xFFFFFFFF);
  MotionIntentionDirectionRelTarget::sClassNameUID = result;
  return result;
}

// File Line: 1760
// RVA: 0x277B10
void __fastcall MotionIntentionDirectionRelTarget::MotionIntentionDirectionRelTarget(
        MotionIntentionDirectionRelTarget *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionDirectionRelTarget::`vftable;
  this->mTargetType.mValue = 22;
  *(_QWORD *)&this->mDirection = 0i64;
  this->mDirectionCos = 1.0;
  this->mAngleRange = 1.5707964;
  this->mUseTargetDirection = 0;
  this->mBoneName = UFG::gNullQSymbolUC;
}

// File Line: 1765
// RVA: 0x285900
bool __fastcall MotionIntentionDirectionRelTarget::Match(
        MotionIntentionDirectionRelTarget *this,
        ActionContext *pContext)
{
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  UFG::AICharacterControllerBaseComponent *v7; // rdi
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::TransformNodeComponent *v14; // rbx
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm0
  __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  Creature *v20; // rbx
  int BoneID; // eax
  float z; // xmm0_4
  float mDirectionCos; // xmm6_4
  float mDirectionSin; // xmm7_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-78h] BYREF
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-68h] BYREF

  m_pComponent = 0i64;
  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    v7 = ComponentOfTypeHK;
  }
  else
  {
    v7 = 0i64;
  }
  v10 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      m_pComponent = v10->m_Components.p[20].m_pComponent;
    }
    else if ( v11 >= 0 )
    {
      if ( (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v10->m_Components.p[20].m_pComponent;
    }
  }
  if ( !m_pTransformNodeComponent || !v7 || !m_pComponent )
    return 0;
  v13 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
  if ( this->mBoneName.mUID != UFG::gNullQSymbolUC.mUID )
  {
    if ( v13 )
    {
      v18 = v13->m_Flags;
      if ( (v18 & 0x4000) != 0 )
      {
        v19 = v13->m_Components.p[9].m_pComponent;
      }
      else if ( v18 >= 0 )
      {
        if ( (v18 & 0x2000) != 0 )
          v19 = v13->m_Components.p[8].m_pComponent;
        else
          v19 = (v18 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::BaseAnimationComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v13, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        v19 = v13->m_Components.p[9].m_pComponent;
      }
      if ( v19 )
      {
        v20 = *(Creature **)&v19[2].m_TypeUID;
        if ( v20 )
        {
          if ( v20->mPose.mRigHandle.mData )
            BoneID = Skeleton::GetBoneID(v20->mPose.mRigHandle.mUFGSkeleton, this->mBoneName.mUID);
          else
            BoneID = -1;
          Creature::GetTransform(v20, BoneID, &transform);
        }
        goto LABEL_46;
      }
    }
    return 0;
  }
  if ( !v13 )
    return 0;
  v14 = v13->m_pTransformNodeComponent;
  if ( !v14 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v13->m_pTransformNodeComponent);
  v15 = v14->mWorldTransform.v2;
  v16 = v14->mWorldTransform.v3;
  v17 = v14->mWorldTransform.v0;
  transform.v1 = v14->mWorldTransform.v1;
  transform.v2 = v15;
  transform.v0 = v17;
  transform.v3 = v16;
LABEL_46:
  if ( this->mUseTargetDirection )
  {
    v2.x = transform.v0.x;
    z = transform.v0.z;
    v2.y = transform.v0.y;
  }
  else
  {
    mDirectionCos = this->mDirectionCos;
    mDirectionSin = this->mDirectionSin;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v25 = transform.v3.y - m_pTransformNodeComponent->mWorldTransform.v3.y;
    v26 = (float)(transform.v3.x - m_pTransformNodeComponent->mWorldTransform.v3.x) * mDirectionSin;
    v2.x = (float)(v25 * mDirectionSin)
         + (float)((float)(transform.v3.x - m_pTransformNodeComponent->mWorldTransform.v3.x) * mDirectionCos);
    v2.y = (float)(v25 * mDirectionCos) - v26;
    z = 0.0;
  }
  v2.z = z;
  return UFG::qAngleBetween(&v7->m_Intention.mMotionIntentionDirection, &v2) <= this->mAngleRange;
}

// File Line: 1863
// RVA: 0x148A870
__int64 dynamic_initializer_for__AimIntentionRangeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AimIntentionRangeCondition", 0xFFFFFFFF);
  AimIntentionRangeCondition::sClassNameUID = result;
  return result;
}

// File Line: 1871
// RVA: 0x2764A0
void __fastcall AimIntentionRangeCondition::AimIntentionRangeCondition(AimIntentionRangeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AimIntentionRangeCondition::`vftable;
  this->m_fDirection = 0.0;
  this->m_fAngleRange = 1.5707964;
}

// File Line: 1875
// RVA: 0x27E700
bool __fastcall AimIntentionRangeCondition::Match(AimIntentionRangeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AimingBaseComponent *m_pComponent; // rax
  float v6; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = (UFG::AimingBaseComponent *)m_pPointer->m_Components.p[47].m_pComponent;
  else
    m_pComponent = (UFG::AimingBaseComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  m_pPointer,
                                                  UFG::AimingBaseComponent::_TypeUID)
                                              : UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::AimingBaseComponent::_TypeUID));
  if ( !m_pComponent )
    return 0;
  LODWORD(v6) = COERCE_UNSIGNED_INT(UFG::AimingBaseComponent::GetLocalAimDirectionXY(m_pComponent) - this->m_fDirection) & _xmm;
  if ( v6 >= 3.1415927 )
    v6 = 6.2831855 - v6;
  return v6 <= this->m_fAngleRange;
}

// File Line: 1917
// RVA: 0x148A850
__int64 dynamic_initializer_for__AimIntentionAngleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AimIntentionAngleCondition", 0xFFFFFFFF);
  AimIntentionAngleCondition::sClassNameUID = result;
  return result;
}

// File Line: 1925
// RVA: 0x276460
void __fastcall AimIntentionAngleCondition::AimIntentionAngleCondition(AimIntentionAngleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AimIntentionAngleCondition::`vftable;
  this->m_fDirection = 0.0;
  this->m_InEqualityOperator.mValue = 3;
}

// File Line: 1929
// RVA: 0x27E650
char __fastcall AimIntentionAngleCondition::Match(AimIntentionAngleCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AimingBaseComponent *m_pComponent; // rax
  float LocalAimDirectionXY; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = (UFG::AimingBaseComponent *)m_pPointer->m_Components.p[47].m_pComponent;
  else
    m_pComponent = (UFG::AimingBaseComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  m_pPointer,
                                                  UFG::AimingBaseComponent::_TypeUID)
                                              : UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::AimingBaseComponent::_TypeUID));
  if ( !m_pComponent )
    return 0;
  LocalAimDirectionXY = UFG::AimingBaseComponent::GetLocalAimDirectionXY(m_pComponent);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->m_InEqualityOperator.mValue,
           this->m_fDirection,
           LocalAimDirectionXY);
}

// File Line: 1971
// RVA: 0x148A890
__int64 dynamic_initializer_for__AimIntentionSpeedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AimIntentionSpeedCondition", 0xFFFFFFFF);
  AimIntentionSpeedCondition::sClassNameUID = result;
  return result;
}

// File Line: 1979
// RVA: 0x2764E0
void __fastcall AimIntentionSpeedCondition::AimIntentionSpeedCondition(AimIntentionSpeedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AimIntentionSpeedCondition::`vftable;
  this->m_fSpeed = 0.0;
  this->m_InEqualityOperator.mValue = 3;
}

// File Line: 1983
// RVA: 0x27E7D0
char __fastcall AimIntentionSpeedCondition::Match(AimIntentionSpeedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         m_pPointer,
                                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                         m_pPointer,
                                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->m_InEqualityOperator.mValue,
             this->m_fSpeed,
             ComponentOfTypeHK->m_fAimInputLength);
  }
  else
  {
    return 0;
  }
}

// File Line: 2013
// RVA: 0x148B9D0
__int64 dynamic_initializer_for__MotionVelocityMagnitude::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionVelocityMagnitude", 0xFFFFFFFF);
  MotionVelocityMagnitude::sClassNameUID = result;
  return result;
}

// File Line: 2021
// RVA: 0x277C30
void __fastcall MotionVelocityMagnitude::MotionVelocityMagnitude(MotionVelocityMagnitude *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionVelocityMagnitude::`vftable;
  this->mSpeed = 0.0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 2055
// RVA: 0x148B8D0
__int64 dynamic_initializer_for__MotionAngularVelocityMagnitude::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionAngularVelocityMagnitude", 0xFFFFFFFF);
  MotionAngularVelocityMagnitude::sClassNameUID = result;
  return result;
}

// File Line: 2063
// RVA: 0x2779E0
void __fastcall MotionAngularVelocityMagnitude::MotionAngularVelocityMagnitude(MotionAngularVelocityMagnitude *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionAngularVelocityMagnitude::`vftable;
  this->mSpeed = 0.0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 2068
// RVA: 0x285340
char __fastcall MotionAngularVelocityMagnitude::Match(MotionAngularVelocityMagnitude *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          m_pPointer,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mSpeed,
             ComponentOfTypeHK->m_Intention.mCurrentRotationAngularVel);
  }
  else
  {
    return 0;
  }
}

// File Line: 2098
// RVA: 0x148B9B0
__int64 dynamic_initializer_for__MotionRotationSignal::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionRotationSignal", 0xFFFFFFFF);
  MotionRotationSignal::sClassNameUID = result;
  return result;
}

// File Line: 2106
// RVA: 0x277BF0
void __fastcall MotionRotationSignal::MotionRotationSignal(MotionRotationSignal *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionRotationSignal::`vftable;
  this->mSpeed = 0.0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 2111
// RVA: 0x285D80
char __fastcall MotionRotationSignal::Match(MotionRotationSignal *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  float mCurrentRotationSignal; // xmm2_4

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
  else
    v5 = (UFG::AICharacterControllerBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::AICharacterControllerBaseComponent::_TypeUID));
  if ( !v5 )
    return 0;
  mCurrentRotationSignal = v5->m_Intention.mCurrentRotationSignal;
  if ( mCurrentRotationSignal < 0.0 )
    mCurrentRotationSignal = mCurrentRotationSignal + 6.2831855;
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mSpeed,
           mCurrentRotationSignal);
}

// File Line: 2146
// RVA: 0x148AF30
__int64 dynamic_initializer_for__HealthCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HealthCondition", 0xFFFFFFFF);
  HealthCondition::sClassNameUID = result;
  return result;
}

// File Line: 2156
// RVA: 0x277080
void __fastcall HealthCondition::HealthCondition(HealthCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HealthCondition::`vftable;
  this->mHealth.text.mOffset = 1i64;
  BinString::Set(&this->mHealth.text, &customCaption);
  this->mHealth.expression.mOffset = 0i64;
  this->mHealth.value = 0;
  this->mInEqualityOperator.mValue = 3;
  this->mUsePercentage = 0;
}

// File Line: 2160
// RVA: 0x282020
bool __fastcall HealthCondition::Match(HealthCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 v5; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v7; // xmm6_4
  int v8; // eax
  UFG::SimObjectGame *v10; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  float v14; // xmm6_4
  int v15; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((v5 = m_pPointer->m_Flags, (v5 & 0x4000) == 0)
      ? (v5 >= 0
       ? ((v5 & 0x2000) != 0 || (v5 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[6].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[6].m_pComponent),
        ComponentOfTypeHK) )
  {
    if ( this->mUsePercentage )
      v7 = (float)(*((float *)&ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext + 1)
                 / *(float *)&ComponentOfTypeHK[1].m_NameUID)
         * 100.0;
    else
      v7 = (float)(int)*((float *)&ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext + 1);
    v8 = ExpressionParameterInt::operator long(&this->mHealth);
    return CompareInt((UFG::InEqualityOperator)this->mInEqualityOperator.mValue, v8, (int)v7);
  }
  else
  {
    v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v10
      && ((m_Flags = v10->m_Flags, (m_Flags & 0x4000) == 0)
       && m_Flags >= 0
       && (m_Flags & 0x2000) == 0
       && (m_Flags & 0x1000) == 0
        ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v10, UFG::RigidBodyComponent::_TypeUID))
        : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID)),
          ComponentOfType) )
    {
      vfptr = ComponentOfType[6].vfptr;
      if ( vfptr )
        v14 = *((float *)&vfptr[33].__vecDelDtor + 1);
      else
        v14 = *(float *)&FLOAT_1_0;
      v15 = ExpressionParameterInt::operator long(&this->mHealth);
      return CompareInt((UFG::InEqualityOperator)this->mInEqualityOperator.mValue, v15, (int)(float)(v14 * 100.0));
    }
    else
    {
      return 0;
    }
  }
}

// File Line: 2214
// RVA: 0x148AF10
__int64 dynamic_initializer_for__HealthClampedToMinimumCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HealthClampedToMinimumCondition", 0xFFFFFFFF);
  HealthClampedToMinimumCondition::sClassNameUID = result;
  return result;
}

// File Line: 2217
// RVA: 0x277050
void __fastcall HealthClampedToMinimumCondition::HealthClampedToMinimumCondition(HealthClampedToMinimumCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HealthClampedToMinimumCondition::`vftable;
}

// File Line: 2221
// RVA: 0x281F90
bool __fastcall HealthClampedToMinimumCondition::Match(HealthClampedToMinimumCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HealthComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HealthComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[6].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[6].m_pComponent),
        ComponentOfTypeHK) )
  {
    return BYTE1(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mNext);
  }
  else
  {
    return 0;
  }
}

// File Line: 2247
// RVA: 0x148C2B0
__int64 dynamic_initializer_for__TargetDistance::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetDistance", 0xFFFFFFFF);
  TargetDistance::sClassNameUID = result;
  return result;
}

// File Line: 2274
// RVA: 0x278A50
void __fastcall TargetDistance::TargetDistance(TargetDistance *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDistance::`vftable;
  this->m_eTargetTypeOrigin.mValue = 1;
  *(_QWORD *)&this->m_eTargetType.mValue = 22i64;
  this->m_eInEqualityOperator.mValue = 3;
  *(_DWORD *)&this->m_2DOnly = 0x10000;
  this->mBoneName = UFG::gNullQSymbolUC;
  this->mTargetBoneName = UFG::gNullQSymbolUC;
  this->mDistancePropertyName = UFG::gNullQSymbol;
  this->m_MyRoot.mOffset = 0i64;
  *(_QWORD *)&this->m_PropertyValueUID = 0i64;
}

// File Line: 2280
// RVA: 0x294160
void __fastcall TargetDistance::ResolveReferences(TargetDistance *this, ActionNode *action_node)
{
  Expression::IMemberMap *v3; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  unsigned int ValueUID; // eax
  unsigned int m_PropertyValueHasBeenReadUID; // ecx

  v3 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v3 )
    v3 = (Expression::IMemberMap *)((char *)v3 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v3;
  if ( this->mDistancePropertyName.mUID != UFG::gNullQSymbol.mUID )
  {
    ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(this->m_PropertyValueUID, eACTION_TREE_MEMORY_ELEMENT_FLOAT);
    m_PropertyValueHasBeenReadUID = this->m_PropertyValueHasBeenReadUID;
    this->m_PropertyValueUID = ValueUID;
    this->m_PropertyValueHasBeenReadUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                            m_PropertyValueHasBeenReadUID,
                                            eACTION_TREE_MEMORY_ELEMENT_BOOL);
  }
}

// File Line: 2325
// RVA: 0x293BE0
float __fastcall TargetDistance::ReadValueFromPropertySet(TargetDistance *this, ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  char *v3; // rdi
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  unsigned int v8; // r9d
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  char *v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  unsigned int v13; // r9d
  __int64 v14; // rax
  UFG::ActionTreeComponentBase *v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  float v18; // [rsp+20h] [rbp-8h]
  bool v19; // [rsp+20h] [rbp-8h]
  float value; // [rsp+38h] [rbp+10h] BYREF

  m_pPointer = action_context->mSimObject.m_pPointer;
  v3 = 0i64;
  if ( m_pPointer && (m_pSceneObj = m_pPointer->m_pSceneObj) != 0i64 )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( mpWritableProperties )
      goto LABEL_7;
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  }
  else
  {
    mpWritableProperties = 0i64;
  }
  if ( !mpWritableProperties )
    return 0.0;
LABEL_7:
  value = 0.0;
  if ( !UFG::TSCharacter::get_attack_param_real(mpWritableProperties, &this->mDistancePropertyName, &value) )
    return 0.0;
  if ( this->m_CachePropertyValue )
  {
    mOffset = this->m_MyRoot.mOffset;
    if ( mOffset )
      v10 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v10 = 0i64;
    if ( mOffset )
      v11 = (char *)&this->m_MyRoot + mOffset;
    else
      v11 = 0i64;
    v12 = action_context->mActionTreeComponentBase[v11[236]];
    if ( !v12 )
      v12 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v12,
      v10,
      (ActionNodeRoot *)this->m_PropertyValueUID,
      v8,
      v18);
    v14 = this->m_MyRoot.mOffset;
    if ( v14 )
      v15 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v14);
    else
      v15 = 0i64;
    if ( v14 )
      v3 = (char *)&this->m_MyRoot + v14;
    v16 = action_context->mActionTreeComponentBase[v3[236]];
    if ( !v16 )
      v16 = action_context->mActionTreeComponentBase[1];
    LOBYTE(v13) = 1;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v16,
      v15,
      (ActionNodeRoot *)this->m_PropertyValueHasBeenReadUID,
      v13,
      v19);
  }
  return value;
}

// File Line: 2355
// RVA: 0x28BEF0
char __fastcall TargetDistance::Match(TargetDistance *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  __int64 mValue; // rax
  UFG::SimObjectCVBase *v9; // r9
  UFG::SimObjectCVBase *v10; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  char *v15; // r14
  __int16 v16; // cx
  __int16 v17; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  UFG::RigidBody *v22; // rax
  UFG::qVector4 v23; // xmm2
  UFG::qVector3 *CentreOfMass; // rax
  float y; // xmm4_4
  float z; // xmm2_4
  float x; // xmm3_4
  __int16 v28; // cx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *v30; // rbx
  int v31; // eax
  char m_2DOnly; // al
  float v33; // xmm0_4
  float v34; // xmm6_4
  float v35; // xmm6_4
  float m_fDistance; // xmm0_4
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v38; // rdx
  char *v39; // rcx
  UFG::ActionTreeComponentBase *v40; // rcx
  __int64 v41; // rax
  UFG::ActionTreeComponentBase *v42; // rdx
  UFG::ActionTreeComponentBase *v43; // rcx
  UFG::qMatrix44 matSimObject; // [rsp+20h] [rbp-69h] BYREF
  UFG::qMatrix44 transform; // [rsp+60h] [rbp-29h] BYREF
  UFG::qVector3 result; // [rsp+A0h] [rbp+17h] BYREF
  unsigned int value_uid; // [rsp+F8h] [rbp+6Fh] BYREF
  unsigned int v48; // [rsp+100h] [rbp+77h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  mValue = this->m_eTargetTypeOrigin.mValue;
  v9 = (_DWORD)mValue == 1
     ? (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer
     : *(UFG::SimObjectCVBase **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + mValue + 8)
                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                + 40);
  v10 = *(UFG::SimObjectCVBase **)(56i64
                                 * *(unsigned __int8 *)(this->m_eTargetType.mValue
                                                      + *(_QWORD *)&m_pComponent[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                 + 40);
  if ( !v9 || !v10 )
    return 0;
  if ( this->mBoneName.mUID == UFG::gNullQSymbolUC.mUID )
  {
    m_pTransformNodeComponent = v9->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v12 = m_pTransformNodeComponent->mWorldTransform.v2;
    v13 = m_pTransformNodeComponent->mWorldTransform.v3;
    v14 = m_pTransformNodeComponent->mWorldTransform.v0;
    transform.v1 = m_pTransformNodeComponent->mWorldTransform.v1;
    transform.v2 = v12;
    transform.v0 = v14;
    transform.v3 = v13;
  }
  else
  {
    v17 = v9->m_Flags;
    if ( (v17 & 0x4000) != 0 || v17 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    else if ( (v17 & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
    }
    else if ( (v17 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v9,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                v9,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    mCreature = ComponentOfTypeHK->mCreature;
    if ( mCreature )
    {
      if ( !mCreature->mPose.mRigHandle.mData )
        return 0;
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, this->mBoneName.mUID);
      if ( BoneID < 0 )
        return 0;
      Creature::GetTransform(mCreature, BoneID, &transform);
    }
  }
  v15 = 0i64;
  if ( this->m_UseCentreOfMass
    && ((v16 = v10->m_Flags, (v16 & 0x4000) == 0) && v16 >= 0 && (v16 & 0x2000) == 0 && (v16 & 0x1000) == 0
      ? (v22 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v10, UFG::RigidBodyComponent::_TypeUID))
      : (v22 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID)),
        v22) )
  {
    v23 = 0i64;
    v23.x = (float)1;
    matSimObject.v0 = v23;
    matSimObject.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 21);
    matSimObject.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 81);
    matSimObject.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 69);
    CentreOfMass = UFG::RigidBody::GetCentreOfMass(v22, &result);
    y = CentreOfMass->y;
    z = CentreOfMass->z;
    x = CentreOfMass->x;
    matSimObject.v3.x = CentreOfMass->x;
    matSimObject.v3.y = y;
    matSimObject.v3.z = z;
    LODWORD(matSimObject.v3.w) = (_DWORD)FLOAT_1_0;
  }
  else
  {
    if ( this->mTargetBoneName.mUID == UFG::gNullQSymbolUC.mUID )
    {
      UFG::TargetingSystemBaseComponent::FindMatrix(v10, &matSimObject);
    }
    else
    {
      v28 = v10->m_Flags;
      if ( (v28 & 0x4000) != 0 || v28 < 0 )
      {
        ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
      }
      else if ( (v28 & 0x2000) != 0 )
      {
        ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
      }
      else if ( (v28 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v10,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                v10,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
      }
      if ( ComponentOfType )
        v30 = ComponentOfType->mCreature;
      else
        v30 = 0i64;
      if ( v30 && v30->mPose.mRigHandle.mData )
        v31 = Skeleton::GetBoneID(v30->mPose.mRigHandle.mUFGSkeleton, this->mTargetBoneName.mUID);
      else
        v31 = -1;
      if ( v31 < 0 )
        return 0;
      Creature::GetTransform(v30, v31, &matSimObject);
    }
    x = matSimObject.v3.x;
    y = matSimObject.v3.y;
    z = matSimObject.v3.z;
  }
  m_2DOnly = this->m_2DOnly;
  if ( m_2DOnly && this->m_ZOnly )
    return 0;
  if ( m_2DOnly )
  {
    v33 = transform.v3.x - x;
    v34 = (float)(transform.v3.y - y) * (float)(transform.v3.y - y);
LABEL_69:
    v35 = v34 + (float)(v33 * v33);
    goto LABEL_70;
  }
  if ( !this->m_ZOnly )
  {
    v33 = transform.v3.z - z;
    v34 = (float)((float)(transform.v3.y - y) * (float)(transform.v3.y - y))
        + (float)((float)(transform.v3.x - x) * (float)(transform.v3.x - x));
    goto LABEL_69;
  }
  v35 = COERCE_FLOAT(COERCE_UNSIGNED_INT(transform.v3.z - z) & _xmm)
      * COERCE_FLOAT(COERCE_UNSIGNED_INT(transform.v3.z - z) & _xmm);
LABEL_70:
  m_fDistance = this->m_fDistance;
  v48 = LODWORD(m_fDistance);
  if ( this->mDistancePropertyName.mUID != UFG::gNullQSymbol.mUID )
  {
    mOffset = this->m_MyRoot.mOffset;
    LOBYTE(value_uid) = 0;
    if ( mOffset )
      v38 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v38 = 0i64;
    if ( mOffset )
      v39 = (char *)&this->m_MyRoot + mOffset;
    else
      v39 = 0i64;
    v40 = pContext->mActionTreeComponentBase[v39[236]];
    if ( !v40 )
      v40 = pContext->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
      v40,
      v38,
      (ActionNodeRoot *)this->m_PropertyValueHasBeenReadUID,
      (unsigned int)&value_uid,
      *(bool **)&matSimObject.v0.x);
    if ( (_BYTE)value_uid && this->m_CachePropertyValue )
    {
      v41 = this->m_MyRoot.mOffset;
      if ( v41 )
        v42 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v41);
      else
        v42 = 0i64;
      if ( v41 )
        v15 = (char *)&this->m_MyRoot + v41;
      v43 = pContext->mActionTreeComponentBase[v15[236]];
      if ( !v43 )
        v43 = pContext->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
        v43,
        v42,
        (ActionNodeRoot *)this->m_PropertyValueUID,
        (unsigned int)&v48,
        *(float **)&matSimObject.v0.x);
      m_fDistance = *(float *)&v48;
    }
    else
    {
      m_fDistance = TargetDistance::ReadValueFromPropertySet(this, pContext);
      v48 = LODWORD(m_fDistance);
    }
  }
  return CompareFloat((UFG::InEqualityOperator)this->m_eInEqualityOperator.mValue, m_fDistance * m_fDistance, v35);
}

// File Line: 2544
// RVA: 0x148C270
__int64 dynamic_initializer_for__TargetCloserThanTargetCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetCloserThanTargetCondition", 0xFFFFFFFF);
  TargetCloserThanTargetCondition::sClassNameUID = result;
  return result;
}

// File Line: 2558
// RVA: 0x278960
void __fastcall TargetCloserThanTargetCondition::TargetCloserThanTargetCondition(TargetCloserThanTargetCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetCloserThanTargetCondition::`vftable;
  *(_QWORD *)&this->m_eTargetTypeA.mValue = 0i64;
  *(_WORD *)&this->m_OrEqual = 1;
  this->m_ZOnly = 0;
}

// File Line: 2562
// RVA: 0x28B9F0
char __fastcall TargetCloserThanTargetCondition::Match(TargetCloserThanTargetCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  __int64 v7; // rdx
  __int64 v8; // r8
  UFG::TransformNodeComponent *v9; // rbx
  __int64 v10; // rsi
  __int64 v11; // rax
  UFG::TransformNodeComponent *v13; // rsi
  UFG::SimObject *v14; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm2_4

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(_QWORD *)&m_pComponent[1].m_Flags;
  v8 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
  v9 = 0i64;
  v10 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(this->m_eTargetTypeA.mValue + v7 + 8) + v8 + 40);
  v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(this->m_eTargetTypeB.mValue + v7 + 8) + v8 + 40);
  if ( v10 )
  {
    if ( !v11 )
      return 1;
    v13 = *(UFG::TransformNodeComponent **)(v10 + 88);
  }
  else
  {
    v13 = 0i64;
  }
  if ( v11 )
    v9 = *(UFG::TransformNodeComponent **)(v11 + 88);
  v14 = pContext->mSimObject.m_pPointer;
  if ( !v14 )
    return 0;
  m_pTransformNodeComponent = v14->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent || !v13 || !v9 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  if ( this->m_2DOnly )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v13);
    v16 = (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v13->mWorldTransform.v3.y)
                * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v13->mWorldTransform.v3.y))
        + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v13->mWorldTransform.v3.x)
                * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v13->mWorldTransform.v3.x));
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    v17 = m_pTransformNodeComponent->mWorldTransform.v3.x - v9->mWorldTransform.v3.x;
    v18 = (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v9->mWorldTransform.v3.y)
        * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v9->mWorldTransform.v3.y);
  }
  else
  {
    if ( this->m_ZOnly )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v13);
      LODWORD(v16) = COERCE_UNSIGNED_INT(m_pTransformNodeComponent->mWorldTransform.v3.z - v13->mWorldTransform.v3.z) & _xmm;
      UFG::TransformNodeComponent::UpdateWorldTransform(v9);
      LODWORD(v19) = COERCE_UNSIGNED_INT(m_pTransformNodeComponent->mWorldTransform.v3.z - v9->mWorldTransform.v3.z) & _xmm;
      goto LABEL_28;
    }
    UFG::TransformNodeComponent::UpdateWorldTransform(v13);
    v16 = (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v13->mWorldTransform.v3.y)
                        * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v13->mWorldTransform.v3.y))
                + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v13->mWorldTransform.v3.x)
                        * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v13->mWorldTransform.v3.x)))
        + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v13->mWorldTransform.v3.z)
                * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v13->mWorldTransform.v3.z));
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    v17 = m_pTransformNodeComponent->mWorldTransform.v3.z - v9->mWorldTransform.v3.z;
    v18 = (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v9->mWorldTransform.v3.y)
                * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - v9->mWorldTransform.v3.y))
        + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v9->mWorldTransform.v3.x)
                * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - v9->mWorldTransform.v3.x));
  }
  v19 = v18 + (float)(v17 * v17);
LABEL_28:
  if ( this->m_OrEqual )
    return v19 >= v16;
  else
    return v19 > v16;
}

// File Line: 2633
// RVA: 0x148AE90
__int64 dynamic_initializer_for__GroundDistance::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GroundDistance", 0xFFFFFFFF);
  GroundDistance::sClassNameUID = result;
  return result;
}

// File Line: 2641
// RVA: 0x276F90
void __fastcall GroundDistance::GroundDistance(GroundDistance *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&GroundDistance::`vftable;
  this->mDistance = 1.0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 2645
// RVA: 0x281DE0
char __fastcall GroundDistance::Match(GroundDistance *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID))
       : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterPhysicsComponent::_TypeUID)))
      : (ComponentOfType = m_pPointer->m_Components.p[27].m_pComponent),
        ComponentOfType) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)this->mInEqualityOperator.mValue,
             this->mDistance,
             *(float *)&ComponentOfType[5].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    return 0;
  }
}

// File Line: 2669
// RVA: 0x148C1D0
__int64 dynamic_initializer_for__SpeedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SpeedCondition", 0xFFFFFFFF);
  SpeedCondition::sClassNameUID = result;
  return result;
}

// File Line: 2678
// RVA: 0x2787D0
void __fastcall SpeedCondition::SpeedCondition(SpeedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SpeedCondition::`vftable;
  this->m_fSpeed = 0.0;
  this->m_InEqualityOperator.mValue = 3;
}

// File Line: 2682
// RVA: 0x28A850
char __fastcall SpeedCondition::Match(SpeedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::CharacterPhysicsComponent *m_pComponent; // rax
  __m128 x_low; // xmm2
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::SimObjectGame *v11; // rcx
  __int16 v12; // dx
  UFG::RigidBody *ComponentOfTypeHK; // rax
  UFG::SimObject *v14; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
    else
      m_pComponent = (UFG::CharacterPhysicsComponent *)(m_Flags < 0
                                                     || (m_Flags & 0x2000) != 0
                                                     || (m_Flags & 0x1000) != 0
                                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::CharacterPhysicsComponent::_TypeUID)
                                                      : UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::CharacterPhysicsComponent::_TypeUID));
    if ( m_pComponent )
    {
      UFG::CharacterPhysicsComponent::GetVelocity(m_pComponent, &result);
LABEL_12:
      x_low = (__m128)LODWORD(result.x);
      y = result.y;
      z = result.z;
LABEL_13:
      x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
      return CompareFloat(
               (UFG::InEqualityOperator)this->m_InEqualityOperator.mValue,
               this->m_fSpeed,
               _mm_sqrt_ps(x_low).m128_f32[0]);
    }
  }
  v11 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v11 )
  {
    v12 = v11->m_Flags;
    if ( (v12 & 0x4000) != 0 || v12 < 0 || (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v11,
                                              UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v11, UFG::RigidBodyComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      UFG::RigidBody::GetVelocity(ComponentOfTypeHK, &result);
      goto LABEL_12;
    }
  }
  v14 = pContext->mSimObject.m_pPointer;
  if ( v14 )
  {
    m_pTransformNodeComponent = v14->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v14->m_pTransformNodeComponent);
      y = m_pTransformNodeComponent->mWorldVelocity.x;
      x_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldVelocity.y);
      z = m_pTransformNodeComponent->mWorldVelocity.z;
      goto LABEL_13;
    }
  }
  return 0;
}

// File Line: 2735
// RVA: 0x148C510
__int64 dynamic_initializer_for__TargetPhysicalMassCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalMassCondition", 0xFFFFFFFF);
  TargetPhysicalMassCondition::sClassNameUID = result;
  return result;
}

// File Line: 2745
// RVA: 0x278E10
void __fastcall TargetPhysicalMassCondition::TargetPhysicalMassCondition(TargetPhysicalMassCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalMassCondition::`vftable;
  *(_QWORD *)&this->m_eTargetType.mValue = 49i64;
  this->m_eInEqualityOperator.mValue = 3;
}

// File Line: 2749
// RVA: 0x28E1E0
char __fastcall TargetPhysicalMassCondition::Match(TargetPhysicalMassCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::RigidBody *ComponentOfTypeHK; // rax
  double Mass; // xmm0_8

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(this->m_eTargetType.mValue
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
    ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v7,
                                            UFG::RigidBodyComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v7, UFG::RigidBodyComponent::_TypeUID);
  if ( !ComponentOfTypeHK )
    return 0;
  Mass = UFG::RigidBody::GetMass(ComponentOfTypeHK);
  return CompareFloat((UFG::InEqualityOperator)this->m_eInEqualityOperator.mValue, this->m_fMass, *(float *)&Mass);
}

// File Line: 2786
// RVA: 0x148C4B0
__int64 dynamic_initializer_for__TargetPhysicalCollisionLayerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalCollisionLayerCondition", 0xFFFFFFFF);
  TargetPhysicalCollisionLayerCondition::sClassNameUID = result;
  return result;
}

// File Line: 2794
// RVA: 0x278D50
void __fastcall TargetPhysicalCollisionLayerCondition::TargetPhysicalCollisionLayerCondition(
        TargetPhysicalCollisionLayerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalCollisionLayerCondition::`vftable;
  this->m_eTargetType.mValue = 49;
  this->m_eCollisionLayer.mValue = 19;
}

// File Line: 2798
// RVA: 0x28DD30
bool __fastcall TargetPhysicalCollisionLayerCondition::Match(
        TargetPhysicalCollisionLayerCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::RigidBody *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v7 = *(UFG::SimObjectGame **)(56i64
                                         * *(unsigned __int8 *)(this->m_eTargetType.mValue
                                                              + *(_QWORD *)&m_pComponent[1].m_Flags
                                                              + 8i64)
                                         + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                         + 40)) != 0i64
         && ((v8 = v7->m_Flags, (v8 & 0x4000) == 0) && v8 >= 0 && (v8 & 0x2000) == 0 && (v8 & 0x1000) == 0
           ? (ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                    v7,
                                                    UFG::RigidBodyComponent::_TypeUID))
           : (ComponentOfType = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v7,
                                                    UFG::RigidBodyComponent::_TypeUID)),
             ComponentOfType))
        && (unsigned int)UFG::RigidBody::GetCollisionLayer(ComponentOfType) == this->m_eCollisionLayer.mValue;
  return result;
}

// File Line: 2834
// RVA: 0x148C470
__int64 dynamic_initializer_for__TargetPhysicalAttackShootComboCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalAttackShootComboCondition", 0xFFFFFFFF);
  TargetPhysicalAttackShootComboCondition::sClassNameUID = result;
  return result;
}

// File Line: 2840
// RVA: 0x278CD0
void __fastcall TargetPhysicalAttackShootComboCondition::TargetPhysicalAttackShootComboCondition(
        TargetPhysicalAttackShootComboCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalAttackShootComboCondition::`vftable;
  this->m_eTargetType.mValue = 49;
}

// File Line: 2844
// RVA: 0x28D9E0
char __fastcall TargetPhysicalAttackShootComboCondition::Match(
        TargetPhysicalAttackShootComboCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *TypeName; // rax
  __int64 v13; // rdx
  char v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                       + this->m_eTargetType.mValue
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::RigidBodyComponent::_TypeUID);
        v10 = ComponentOfTypeHK;
        if ( ComponentOfTypeHK )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v16);
          TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
          v16.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
          v13 = *(_QWORD *)&v10[2].m_Flags;
          if ( v13 )
            UFG::qReflectHandleBase::operator=(&v16, (UFG::qReflectHandleBase *)(v13 + 224));
          if ( v16.mData )
          {
            v14 = BYTE2(v16.mData[1].mHandles.mNode.mPrev);
            UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
            return v14;
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
        }
      }
    }
  }
  return 0;
}

// File Line: 2881
// RVA: 0x148C490
__int64 dynamic_initializer_for__TargetPhysicalAttackVelocityCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalAttackVelocityCondition", 0xFFFFFFFF);
  TargetPhysicalAttackVelocityCondition::sClassNameUID = result;
  return result;
}

// File Line: 2891
// RVA: 0x278D10
void __fastcall TargetPhysicalAttackVelocityCondition::TargetPhysicalAttackVelocityCondition(
        TargetPhysicalAttackVelocityCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalAttackVelocityCondition::`vftable;
  this->m_eTargetType.mValue = 49;
  *(_QWORD *)&this->m_eInEqualityOperator.mValue = 3i64;
}

// File Line: 2895
// RVA: 0x28DB80
char __fastcall TargetPhysicalAttackVelocityCondition::Match(
        TargetPhysicalAttackVelocityCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *TypeName; // rax
  __int64 v13; // rdx
  char v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                       + this->m_eTargetType.mValue
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::RigidBodyComponent::_TypeUID);
        v10 = ComponentOfTypeHK;
        if ( ComponentOfTypeHK )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v16);
          TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
          v16.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
          v13 = *(_QWORD *)&v10[2].m_Flags;
          if ( v13 )
            UFG::qReflectHandleBase::operator=(&v16, (UFG::qReflectHandleBase *)(v13 + 224));
          if ( v16.mData )
          {
            v14 = CompareFloat(
                    (UFG::InEqualityOperator)this->m_eInEqualityOperator.mValue,
                    this->m_fAttackVelocity,
                    *(float *)&v16.mData[1].mBaseNode.mParent);
            UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
            return v14;
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
        }
      }
    }
  }
  return 0;
}

// File Line: 2937
// RVA: 0x148C4D0
__int64 dynamic_initializer_for__TargetPhysicalDamageMultiplierCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalDamageMultiplierCondition", 0xFFFFFFFF);
  TargetPhysicalDamageMultiplierCondition::sClassNameUID = result;
  return result;
}

// File Line: 2949
// RVA: 0x278D90
void __fastcall TargetPhysicalDamageMultiplierCondition::TargetPhysicalDamageMultiplierCondition(
        TargetPhysicalDamageMultiplierCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalDamageMultiplierCondition::`vftable;
  *(_QWORD *)&this->m_eTargetType.mValue = 49i64;
  *(_QWORD *)&this->m_eInEqualityOperator.mValue = 3i64;
}

// File Line: 2953
// RVA: 0x28DE70
char __fastcall TargetPhysicalDamageMultiplierCondition::Match(
        TargetPhysicalDamageMultiplierCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RigidBodyComponent *v10; // rbx
  const char *StaticTypeName; // rax
  float v12; // xmm2_4
  int m_iDamageType; // ecx
  int v14; // ecx
  int v15; // ecx
  char v16; // bl
  UFG::qReflectHandleBase v18; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                   + this->m_eTargetType.mValue
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::RigidBodyComponent::_TypeUID);
  v10 = (UFG::RigidBodyComponent *)ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  UFG::qReflectHandleBase::qReflectHandleBase(&v18);
  StaticTypeName = UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::GetStaticTypeName();
  v18.mTypeUID = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::RigidBodyComponent::GetStateMachineDefinition(v10, (UFG::qReflectHandle<UFG::StateMachineDefinition> *)&v18);
  if ( !v18.mData )
  {
    UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
    return 0;
  }
  v12 = FLOAT_100_0;
  m_iDamageType = this->m_iDamageType;
  if ( m_iDamageType )
  {
    v14 = m_iDamageType - 1;
    if ( v14 )
    {
      v15 = v14 - 1;
      if ( v15 )
      {
        if ( v15 == 1 )
          v12 = *((float *)&v18.mData[1].mBaseNode.mChildren[1] + 1);
      }
      else
      {
        v12 = *(float *)v18.mData[1].mBaseNode.mChildren;
      }
    }
    else
    {
      v12 = *((float *)&v18.mData[1].mBaseNode.mParent + 1);
    }
  }
  else
  {
    v12 = *((float *)v18.mData[1].mBaseNode.mChildren + 1);
  }
  v16 = CompareFloat((UFG::InEqualityOperator)this->m_eInEqualityOperator.mValue, this->m_fDamageMultiplier, v12);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
  return v16;
}

// File Line: 3017
// RVA: 0x148C4F0
__int64 dynamic_initializer_for__TargetPhysicalDodgeableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalDodgeableCondition", 0xFFFFFFFF);
  TargetPhysicalDodgeableCondition::sClassNameUID = result;
  return result;
}

// File Line: 3023
// RVA: 0x278DD0
void __fastcall TargetPhysicalDodgeableCondition::TargetPhysicalDodgeableCondition(
        TargetPhysicalDodgeableCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalDodgeableCondition::`vftable;
  this->m_eTargetType.mValue = 49;
}

// File Line: 3027
// RVA: 0x28E040
bool __fastcall TargetPhysicalDodgeableCondition::Match(
        TargetPhysicalDodgeableCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *TypeName; // rax
  __int64 v13; // rdx
  bool v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                   + this->m_eTargetType.mValue
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::RigidBodyComponent::_TypeUID);
  v10 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  UFG::qReflectHandleBase::qReflectHandleBase(&v16);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
  v16.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  v13 = *(_QWORD *)&v10[2].m_Flags;
  if ( v13 )
    UFG::qReflectHandleBase::operator=(&v16, (UFG::qReflectHandleBase *)(v13 + 224));
  v14 = v16.mData && BYTE3(v16.mData[2].vfptr);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
  return v14;
}

// File Line: 3061
// RVA: 0x148C530
__int64 dynamic_initializer_for__TargetPhysicalMeleeAttackableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPhysicalMeleeAttackableCondition", 0xFFFFFFFF);
  TargetPhysicalMeleeAttackableCondition::sClassNameUID = result;
  return result;
}

// File Line: 3067
// RVA: 0x278E50
void __fastcall TargetPhysicalMeleeAttackableCondition::TargetPhysicalMeleeAttackableCondition(
        TargetPhysicalMeleeAttackableCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalMeleeAttackableCondition::`vftable;
  this->m_eTargetType.mValue = 49;
}

// File Line: 3071
// RVA: 0x28E320
bool __fastcall TargetPhysicalMeleeAttackableCondition::Match(
        TargetPhysicalMeleeAttackableCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *TypeName; // rax
  __int64 v13; // rdx
  bool v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                   + this->m_eTargetType.mValue
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::RigidBodyComponent::_TypeUID);
  v10 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  UFG::qReflectHandleBase::qReflectHandleBase(&v16);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
  v16.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  v13 = *(_QWORD *)&v10[2].m_Flags;
  if ( v13 )
    UFG::qReflectHandleBase::operator=(&v16, (UFG::qReflectHandleBase *)(v13 + 224));
  v14 = v16.mData && BYTE4(v16.mData[2].vfptr);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
  return v14;
}

// File Line: 3107
// RVA: 0x148CD90
__int64 dynamic_initializer_for__VehicleSpeedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleSpeedCondition", 0xFFFFFFFF);
  VehicleSpeedCondition::sClassNameUID = result;
  return result;
}

// File Line: 3117
// RVA: 0x279600
void __fastcall VehicleSpeedCondition::VehicleSpeedCondition(VehicleSpeedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleSpeedCondition::`vftable;
  this->mSpeed = 0.0;
  *(_WORD *)&this->mInEqualityOperator.mValue = 259;
}

// File Line: 3121
// RVA: 0x292C20
char __fastcall VehicleSpeedCondition::Match(VehicleSpeedCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  float mSpeed; // xmm6_4
  float LinearVelocityMagnitudeKPH; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
    return 0;
  mSpeed = this->mSpeed;
  if ( this->mTestForwardSpeed )
    LinearVelocityMagnitudeKPH = 3.5999999 * ComponentOfTypeHK->mForwardSpeed;
  else
    LinearVelocityMagnitudeKPH = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(ComponentOfTypeHK);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           mSpeed,
           LinearVelocityMagnitudeKPH);
}

// File Line: 3154
// RVA: 0x148CA90
__int64 dynamic_initializer_for__VehicleCollisionShouldTriggerExplosion::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleCollisionShouldTriggerExplosion", 0xFFFFFFFF);
  VehicleCollisionShouldTriggerExplosion::sClassNameUID = result;
  return result;
}

// File Line: 3157
// RVA: 0x2794F0
void __fastcall VehicleCollisionShouldTriggerExplosion::VehicleCollisionShouldTriggerExplosion(
        VehicleCollisionShouldTriggerExplosion *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleCollisionShouldTriggerExplosion::`vftable;
}

// File Line: 3161
// RVA: 0x291840
bool __fastcall VehicleCollisionShouldTriggerExplosion::Match(
        VehicleCollisionShouldTriggerExplosion *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( ComponentOfTypeHK )
    return (BYTE4(ComponentOfTypeHK[14].vfptr) & 0x10) != 0;
  return 0;
}

// File Line: 3186
// RVA: 0x148CC30
__int64 dynamic_initializer_for__VehicleIsRammingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleIsRammingCondition", 0xFFFFFFFF);
  VehicleIsRammingCondition::sClassNameUID = result;
  return result;
}

// File Line: 3189
// RVA: 0x279560
void __fastcall VehicleIsRammingCondition::VehicleIsRammingCondition(VehicleIsRammingCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleIsRammingCondition::`vftable;
}

// File Line: 3193
// RVA: 0x2924E0
bool __fastcall VehicleIsRammingCondition::Match(VehicleIsRammingCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( ComponentOfTypeHK )
    return (BYTE4(ComponentOfTypeHK[14].vfptr) & 8) != 0;
  return 0;
}

// File Line: 3212
// RVA: 0x148CDB0
__int64 dynamic_initializer_for__VehicleTrunkTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleTrunkTypeCondition", 0xFFFFFFFF);
  VehicleTrunkTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 3218
// RVA: 0x279640
void __fastcall VehicleTrunkTypeCondition::VehicleTrunkTypeCondition(VehicleTrunkTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleTrunkTypeCondition::`vftable;
  this->mType.mValue = 0;
}

// File Line: 3222
// RVA: 0x292CE0
bool __fastcall VehicleTrunkTypeCondition::Match(VehicleTrunkTypeCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rdx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
    m_pComponent = ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( m_pComponent )
    return m_pComponent->mTrunkType == (unsigned __int8)this->mType.mValue;
  return 0;
}

// File Line: 3245
// RVA: 0x148CC50
__int64 dynamic_initializer_for__VehicleIsWreckedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleIsWreckedCondition", 0xFFFFFFFF);
  VehicleIsWreckedCondition::sClassNameUID = result;
  return result;
}

// File Line: 3248
// RVA: 0x279590
void __fastcall VehicleIsWreckedCondition::VehicleIsWreckedCondition(VehicleIsWreckedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleIsWreckedCondition::`vftable;
}

// File Line: 3252
// RVA: 0x292560
bool __fastcall VehicleIsWreckedCondition::Match(VehicleIsWreckedCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( ComponentOfTypeHK )
    return (unsigned int)(HIDWORD(ComponentOfTypeHK[2].m_BoundComponentHandles.mNode.mPrev) - 1) <= 1;
  return 0;
}

// File Line: 3275
// RVA: 0x148C9D0
__int64 dynamic_initializer_for__VehicleAngularSpeedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleAngularSpeedCondition", 0xFFFFFFFF);
  VehicleAngularSpeedCondition::sClassNameUID = result;
  return result;
}

// File Line: 3285
// RVA: 0x279470
void __fastcall VehicleAngularSpeedCondition::VehicleAngularSpeedCondition(VehicleAngularSpeedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleAngularSpeedCondition::`vftable;
  this->mComparison.mValue = 3;
  this->mSpeed = 0.0;
  this->mAboutZOnly = 0;
}

// File Line: 3289
// RVA: 0x290DE0
char __fastcall VehicleAngularSpeedCondition::Match(VehicleAngularSpeedCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  float x; // xmm0_4
  __m128 y_low; // xmm1
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
    return 0;
  UFG::PhysicsMoverInterface::GetAngularVelocity(ComponentOfTypeHK, &result);
  if ( this->mAboutZOnly )
  {
    x = 0.0;
    y_low = 0i64;
    result.x = 0.0;
    result.y = 0.0;
  }
  else
  {
    y_low = (__m128)LODWORD(result.y);
    x = result.x;
  }
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x))
                    + (float)(result.z * result.z);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->mComparison.mValue,
           this->mSpeed,
           _mm_sqrt_ps(y_low).m128_f32[0]);
}

// File Line: 3326
// RVA: 0x148CDF0
__int64 dynamic_initializer_for__VehicleVectorCompareCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleVectorCompareCondition", 0xFFFFFFFF);
  VehicleVectorCompareCondition::sClassNameUID = result;
  return result;
}

// File Line: 3344
// RVA: 0x279680
void __fastcall VehicleVectorCompareCondition::VehicleVectorCompareCondition(VehicleVectorCompareCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleVectorCompareCondition::`vftable;
  *(_WORD *)&this->mVector1.mValue = 1024;
  this->mAngleRadians = 3.1415927;
  *(_DWORD *)&this->mCheckMagnitude = 768;
}

// File Line: 3348
// RVA: 0x292DF0
char __fastcall VehicleVectorCompareCondition::Match(VehicleVectorCompareCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  hkpRigidBody *RigidBody; // rax
  hkpRigidBody *v8; // rdi
  __m128 m_quad; // xmm6
  __m128 v10; // xmm4
  __m128 v11; // xmm3
  __m128 v12; // xmm5
  float v13; // xmm7_4
  __m128 v14; // xmm4
  float v15; // xmm1_4
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm9
  __m128 v22; // xmm7
  __m128 v23; // xmm6
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  hkVector4f result; // [rsp+30h] [rbp-58h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) == 0 )
    {
      if ( (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::PhysicsMoverInterface::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::PhysicsMoverInterface::_TypeUID);
      goto LABEL_9;
    }
    return 0;
  }
  ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
LABEL_9:
  if ( !ComponentOfTypeHK )
    return 0;
  RigidBody = (hkpRigidBody *)UFG::PhysicsMoverInterface::GetRigidBody(ComponentOfTypeHK);
  v8 = RigidBody;
  if ( !RigidBody )
    return 0;
  VehicleVectorCompareCondition::GetVectorFromType(
    this,
    &result,
    RigidBody,
    (UFG::eVehicleVectorEnum)(unsigned __int8)this->mVector1.mValue,
    context);
  m_quad = result.m_quad;
  if ( this->mFlattenV1 )
    m_quad = _mm_shuffle_ps(result.m_quad, _mm_unpackhi_ps(result.m_quad, (__m128)0i64), 180);
  VehicleVectorCompareCondition::GetVectorFromType(
    this,
    &result,
    v8,
    (UFG::eVehicleVectorEnum)(unsigned __int8)this->mVector2.mValue,
    context);
  v10 = result.m_quad;
  if ( this->mFlattenV2 )
    v10 = _mm_shuffle_ps(result.m_quad, _mm_unpackhi_ps(result.m_quad, (__m128)0i64), 180);
  v11 = _mm_mul_ps(m_quad, m_quad);
  v12 = _mm_mul_ps(v10, v10);
  v13 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
      + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
  if ( (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
             + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) <= 0.001
    || v13 <= 0.001 )
  {
    return 0;
  }
  if ( this->mCheckMagnitude )
  {
    v14 = _mm_mul_ps(v10, m_quad);
    v15 = (float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0] + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
        + _mm_shuffle_ps(v14, v14, 170).m128_f32[0];
  }
  else
  {
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v17 = _mm_rsqrt_ps(v16);
    v18 = v16;
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170));
    v20 = _mm_mul_ps(
            _mm_mul_ps(v10, _mm_andnot_ps(_mm_cmple_ps(v19, (__m128)0i64), _mm_rsqrt_ps(v19))),
            _mm_mul_ps(m_quad, _mm_andnot_ps(_mm_cmple_ps(v18, (__m128)0i64), v17)));
    v21 = _mm_min_ps(
            _mm_max_ps(
              (__m128)COERCE_UNSIGNED_INT(
                        (float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                      + _mm_shuffle_ps(v20, v20, 170).m128_f32[0]),
              *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
            *(__m128 *)_xmm);
    v22 = _mm_andnot_ps(*(__m128 *)_xmm, v21);
    v23 = _mm_cmplt_ps(v22, *(__m128 *)_xmm);
    v24 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v22), *(__m128 *)_xmm);
    v25 = _mm_cmplt_ps(*(__m128 *)_xmm, v22);
    v26 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v24), v25), _mm_andnot_ps(v25, v22));
    v27 = _mm_or_ps(_mm_andnot_ps(v25, _mm_mul_ps(v22, v22)), _mm_and_ps(v25, v24));
    v28 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v27, *(__m128 *)coeff4), *(__m128 *)coeff3), v27),
                          *(__m128 *)coeff2),
                        v27),
                      *(__m128 *)coeff1),
                    v27),
                  *(__m128 *)coeff0),
                v27),
              v26),
            v26);
    v15 = 1.5707964
        - COERCE_FLOAT((_mm_andnot_ps(
                          v23,
                          _mm_or_ps(
                            _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v28, v28)), v25),
                            _mm_andnot_ps(v25, v28))).m128_u32[0] | v23.m128_i32[0] & v22.m128_i32[0]) ^ _xmm[0] & v21.m128_i32[0]);
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)this->mComparison.mValue, this->mAngleRadians, v15);
}

// File Line: 3401
// RVA: 0x27DD10
hkVector4f *__fastcall VehicleVectorCompareCondition::GetVectorFromType(
        VehicleVectorCompareCondition *this,
        hkVector4f *result,
        hkpRigidBody *pRigidBody,
        UFG::eVehicleVectorEnum eType,
        ActionContext *pContext)
{
  hkVector4f *v6; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int *m_pComponent; // rax
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  __m128 v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm2

  switch ( eType )
  {
    case eVehicleVector_Forward:
      v6 = result;
      *result = pRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
      break;
    case eVehicleVector_Up:
      v6 = result;
      *result = pRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
      break;
    case eVehicleVector_Left:
      v6 = result;
      *result = pRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
      break;
    case eVehicleVector_Right:
      v6 = result;
      result->m_quad = _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         pRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
      break;
    case eVehicleVector_LinearVelocity:
      v6 = result;
      *result = pRigidBody->m_motion.m_linearVelocity;
      break;
    case eVehicleVector_WorldUp:
      v6 = result;
      *result = (hkVector4f)stru_141A71280.m_quad;
      break;
    case eVehicleVector_CollisionNormal:
      m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
      if ( !m_pPointer )
        goto LABEL_30;
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (unsigned int *)m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        m_pComponent = (unsigned int *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::HitReactionComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::HitReactionComponent::_TypeUID));
      }
      else
      {
        m_pComponent = (unsigned int *)m_pPointer->m_Components.p[15].m_pComponent;
      }
      if ( !m_pComponent )
        goto LABEL_30;
      v10 = (__m128)m_pComponent[100];
      v11 = _mm_unpacklo_ps(
              _mm_xor_ps((__m128)m_pComponent[99], (__m128)(unsigned int)_xmm[0]),
              _mm_xor_ps((__m128)m_pComponent[101], (__m128)(unsigned int)_xmm[0]));
      v6 = result;
      result->m_quad = _mm_unpacklo_ps(
                         v11,
                         _mm_unpacklo_ps(_mm_xor_ps(v10, (__m128)(unsigned int)_xmm[0]), (__m128)0i64));
      break;
    case eVehicleVector_RelativeCollisionVelocity:
      v12 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
      if ( !v12 )
        goto LABEL_30;
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        v14 = v12->m_Components.p[15].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        v14 = (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::HitReactionComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v12, UFG::HitReactionComponent::_TypeUID);
      }
      else
      {
        v14 = v12->m_Components.p[15].m_pComponent;
      }
      if ( !v14 )
        goto LABEL_30;
      v15 = _mm_xor_ps((__m128)*(unsigned int *)(&v14[6].m_SimObjIndex + 1), *(__m128 *)_xmm);
      v16 = v15;
      v17 = v15;
      v15.m128_f32[0] = v15.m128_f32[0] * *((float *)&v14[6].m_SafePointerList.mNode.mNext + 1);
      v16.m128_f32[0] = v16.m128_f32[0] * *((float *)&v14[6].m_SafePointerList.mNode.mPrev + 1);
      v17.m128_f32[0] = v17.m128_f32[0] * *(float *)&v14[6].m_SafePointerList.mNode.mNext;
      v6 = result;
      result->m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v16, v15), _mm_unpacklo_ps(v17, (__m128)0i64));
      break;
    default:
LABEL_30:
      v6 = result;
      *result = 0i64;
      break;
  }
  return v6;
}

// File Line: 3466
// RVA: 0x148CB90
__int64 dynamic_initializer_for__VehicleDoorAngleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDoorAngleCondition", 0xFFFFFFFF);
  VehicleDoorAngleCondition::sClassNameUID = result;
  return result;
}

// File Line: 3476
// RVA: 0x279520
void __fastcall VehicleDoorAngleCondition::VehicleDoorAngleCondition(VehicleDoorAngleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleDoorAngleCondition::`vftable;
  *(_QWORD *)&this->mAngle = 0i64;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 3480
// RVA: 0x2921D0
char __fastcall VehicleDoorAngleCondition::Match(VehicleDoorAngleCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  float AttachmentAngle; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
    return 0;
  mPhysicsVehicle = ComponentOfTypeHK->mPhysicsVehicle;
  AttachmentAngle = 0.0;
  if ( mPhysicsVehicle )
  {
    if ( (*((_DWORD *)mPhysicsVehicle + 151) & 7) == 4 )
      AttachmentAngle = UFG::PhysicsCar::GetAttachmentAngle(
                          (UFG::PhysicsCar *)mPhysicsVehicle,
                          (UFG::VehicleAttachmentID)this->mDoor);
  }
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mAngle,
           AttachmentAngle);
}

// File Line: 3523
// RVA: 0x1493EA0
__int64 dynamic_initializer_for__vehicleWheelSurfaceConditionWheelTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &vehicleWheelSurfaceConditionWheelTypeEnum,
    VehicleWheelSurfaceConditionWheelType,
    3,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__vehicleWheelSurfaceConditionWheelTypeEnum__);
}

// File Line: 3525
// RVA: 0x148CE10
__int64 dynamic_initializer_for__VehicleWheelSurfaceCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleWheelSurfaceCondition", 0xFFFFFFFF);
  VehicleWheelSurfaceCondition::sClassNameUID = result;
  return result;
}

// File Line: 3533
// RVA: 0x2796D0
void __fastcall VehicleWheelSurfaceCondition::VehicleWheelSurfaceCondition(VehicleWheelSurfaceCondition *this)
{
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h] BYREF

  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleWheelSurfaceCondition::`vftable;
  *(_QWORD *)&this->mSurfacePropertyName.mUID = -1i64;
  this->mWheelType.mValue = 0;
  this->mSurfacePropertyName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "TerrainType")->mUID;
}

// File Line: 3548
// RVA: 0x293130
bool __fastcall VehicleWheelSurfaceCondition::Match(VehicleWheelSurfaceCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  int v7; // esi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // r14
  int v9; // r15d
  int v10; // edi
  int v11; // ebp
  unsigned __int64 SurfacePropertyHandleUidUnderWheel; // rbx
  bool IsWheelOnGround; // r12
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v14; // rcx
  const char *TypeName; // rax
  unsigned int mValue; // ecx
  unsigned int v17; // ecx
  UFG::qReflectHandleBase v19; // [rsp+28h] [rbp-50h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( ComponentOfTypeHK )
  {
    mPrev = ComponentOfTypeHK[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      v7 = 0;
      v8 = 0i64;
      if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
        v8 = ComponentOfTypeHK[10].m_SafePointerList.mNode.mPrev;
      if ( v8 )
      {
        v9 = HIDWORD(v8[37].mNext) & 7;
        v10 = 0;
        v11 = 0;
        if ( v9 )
        {
          while ( 1 )
          {
            SurfacePropertyHandleUidUnderWheel = UFG::PhysicsWheeledVehicle::GetSurfacePropertyHandleUidUnderWheel(
                                                   (UFG::PhysicsWheeledVehicle *)v8,
                                                   v11);
            IsWheelOnGround = UFG::PhysicsWheeledVehicle::IsWheelOnGround((UFG::PhysicsWheeledVehicle *)v8, v11);
            UFG::qReflectHandleBase::qReflectHandleBase(&v19);
            TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v14);
            v19.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
            UFG::qReflectHandleBase::Init(&v19, v19.mTypeUID, SurfacePropertyHandleUidUnderWheel);
            if ( v19.mData )
              break;
            if ( !IsWheelOnGround )
              goto LABEL_19;
LABEL_20:
            UFG::qReflectHandleBase::~qReflectHandleBase(&v19);
            if ( ++v11 >= v9 )
              goto LABEL_21;
          }
          if ( LODWORD(v19.mData[1].mHandles.mNode.mPrev) == this->mSurfacePropertyValue.mUID )
            ++v7;
LABEL_19:
          ++v10;
          goto LABEL_20;
        }
LABEL_21:
        mValue = this->mWheelType.mValue;
        if ( !mValue )
          return v7 > 0;
        v17 = mValue - 1;
        if ( !v17 )
          return v7 == v10;
        if ( v17 == 1 )
          return v7 > 2;
      }
    }
  }
  return 0;
}

// File Line: 3649
// RVA: 0x148AA90
__int64 dynamic_initializer_for__CharacterSurfaceCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CharacterSurfaceCondition", 0xFFFFFFFF);
  CharacterSurfaceCondition::sClassNameUID = result;
  return result;
}

// File Line: 3655
// RVA: 0x276870
void __fastcall CharacterSurfaceCondition::CharacterSurfaceCondition(CharacterSurfaceCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CharacterSurfaceCondition::`vftable;
  this->mSurfacePropertyValue = UFG::gNullQSymbolUC;
}

// File Line: 3665
// RVA: 0x27FE90
bool __fastcall CharacterSurfaceCondition::Match(CharacterSurfaceCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                                    m_pPointer,
                                                                    UFG::CharacterPhysicsComponent::_TypeUID))
           : (ComponentOfType = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    m_pPointer,
                                                                    UFG::CharacterPhysicsComponent::_TypeUID)))
          : (ComponentOfType = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent),
            ComponentOfType)
        && UFG::GetTerrainTypeHash(ComponentOfType) == this->mSurfacePropertyValue.mUID;
  return result;
}

// File Line: 3696
// RVA: 0x148CD30
__int64 dynamic_initializer_for__VehicleOffGroundCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOffGroundCondition", 0xFFFFFFFF);
  VehicleOffGroundCondition::sClassNameUID = result;
  return result;
}

// File Line: 3699
// RVA: 0x292A50
bool __fastcall VehicleOffGroundCondition::Match(VehicleOffGroundCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( ComponentOfTypeHK )
  {
    mPrev = ComponentOfTypeHK[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
      return ((__int64 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *))mPrev->mPrev[6].mNext)(mPrev);
  }
  return 0;
}

// File Line: 3721
// RVA: 0x148CDD0
__int64 dynamic_initializer_for__VehicleUntargetableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleUntargetableCondition", 0xFFFFFFFF);
  VehicleUntargetableCondition::sClassNameUID = result;
  return result;
}

// File Line: 3724
// RVA: 0x292D70
bool __fastcall VehicleUntargetableCondition::Match(VehicleUntargetableCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  return ComponentOfTypeHK && BYTE1(ComponentOfTypeHK[14].m_SafePointerList.mNode.mNext);
}

// File Line: 3742
// RVA: 0x148CC10
__int64 dynamic_initializer_for__VehicleInDeepWaterCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleInDeepWaterCondition", 0xFFFFFFFF);
  VehicleInDeepWaterCondition::sClassNameUID = result;
  return result;
}

// File Line: 3745
// RVA: 0x292440
bool __fastcall VehicleInDeepWaterCondition::Match(VehicleInDeepWaterCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::PhysicsWheeledVehicle *v6; // rcx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( ComponentOfTypeHK )
  {
    mPrev = ComponentOfTypeHK[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      v6 = 0i64;
      if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
        v6 = (UFG::PhysicsWheeledVehicle *)ComponentOfTypeHK[10].m_SafePointerList.mNode.mPrev;
      if ( v6 )
        return UFG::PhysicsWheeledVehicle::IsInDeepWater(v6);
    }
  }
  return 0;
}

// File Line: 3767
// RVA: 0x148CA10
__int64 dynamic_initializer_for__VehicleBurnoutCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleBurnoutCondition", 0xFFFFFFFF);
  VehicleBurnoutCondition::sClassNameUID = result;
  return result;
}

// File Line: 3770
// RVA: 0x291040
bool __fastcall VehicleBurnoutCondition::Match(VehicleBurnoutCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int v5; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_11;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_11;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
LABEL_11:
      LOBYTE(v5) = 0;
      return v5;
    }
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
    goto LABEL_11;
  return (LODWORD(ComponentOfTypeHK[1].m_pSimObject) >> 5) & 1;
}

// File Line: 3791
// RVA: 0x148CE30
__int64 dynamic_initializer_for__VehicleWheelieCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleWheelieCondition", 0xFFFFFFFF);
  VehicleWheelieCondition::sClassNameUID = result;
  return result;
}

// File Line: 3794
// RVA: 0x2932D0
bool __fastcall VehicleWheelieCondition::Match(VehicleWheelieCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int m_pSimObject; // ecx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
    return 0;
  m_pSimObject = (int)ComponentOfTypeHK[1].m_pSimObject;
  return (m_pSimObject & 8) != 0 && (m_pSimObject & 0x100) == 0;
}

// File Line: 3815
// RVA: 0x148CD50
__int64 dynamic_initializer_for__VehicleOneEightyCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOneEightyCondition", 0xFFFFFFFF);
  VehicleOneEightyCondition::sClassNameUID = result;
  return result;
}

// File Line: 3818
// RVA: 0x292AE0
bool __fastcall VehicleOneEightyCondition::Match(VehicleOneEightyCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int v5; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_11;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_11;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
LABEL_11:
      LOBYTE(v5) = 0;
      return v5;
    }
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
    goto LABEL_11;
  return (LODWORD(ComponentOfTypeHK[1].m_pSimObject) >> 4) & 1;
}

// File Line: 3837
// RVA: 0x148A790
__int64 dynamic_initializer_for__ActionDefLeanBackCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionDefLeanBackCondition", 0xFFFFFFFF);
  ActionDefLeanBackCondition::sClassNameUID = result;
  return result;
}

// File Line: 3840
// RVA: 0x27E1B0
bool __fastcall ActionDefLeanBackCondition::Match(ActionDefLeanBackCondition *this, ActionContext *context)
{
  UFG::Controller *v2; // rdx
  UFG::InputActionData *v3; // rcx

  v2 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  if ( !v2 )
    return 0;
  v3 = UFG::ActionDef_LeanBack.mDataPerController[v2->mControllerIndex];
  return v3 && v3->mActionTrue;
}

// File Line: 3861
// RVA: 0x148CBD0
__int64 dynamic_initializer_for__VehicleHandbrakeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleHandbrakeCondition", 0xFFFFFFFF);
  VehicleHandbrakeCondition::sClassNameUID = result;
  return result;
}

// File Line: 3864
// RVA: 0x292320
bool __fastcall VehicleHandbrakeCondition::Match(VehicleHandbrakeCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int v5; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_11;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_11;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
LABEL_11:
      LOBYTE(v5) = 0;
      return v5;
    }
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
    goto LABEL_11;
  return (LODWORD(ComponentOfTypeHK[1].m_pSimObject) >> 2) & 1;
}

// File Line: 3884
// RVA: 0x148CC90
__int64 dynamic_initializer_for__VehicleOccupantHasActiveRoleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOccupantHasActiveRoleCondition", 0xFFFFFFFF);
  VehicleOccupantHasActiveRoleCondition::sClassNameUID = result;
  return result;
}

// File Line: 3887
// RVA: 0x2926F0
bool __fastcall VehicleOccupantHasActiveRoleCondition::Match(
        VehicleOccupantHasActiveRoleCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  m_pPointer,
                                  UFG::CharacterOccupantComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::CharacterOccupantComponent::_TypeUID)))
          : (ComponentOfType = m_pPointer->m_Components.p[44].m_pComponent),
            ComponentOfType)
        && LODWORD(ComponentOfType[1].m_SafePointerList.mNode.mNext) != 13;
  return result;
}

// File Line: 3914
// RVA: 0x148CCF0
__int64 dynamic_initializer_for__VehicleOccupantIsPassengerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOccupantIsPassengerCondition", 0xFFFFFFFF);
  VehicleOccupantIsPassengerCondition::sClassNameUID = result;
  return result;
}

// File Line: 3917
// RVA: 0x292910
bool __fastcall VehicleOccupantIsPassengerCondition::Match(
        VehicleOccupantIsPassengerCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int mNext; // ecx
  int v6; // eax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterOccupantComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterOccupantComponent::_TypeUID);
    if ( m_pComponent )
    {
      mNext = (unsigned int)m_pComponent[1].m_SafePointerList.mNode.mNext;
      if ( mNext > 0xD )
        return 1;
      v6 = 8720;
      if ( !_bittest(&v6, mNext) )
        return 1;
    }
  }
  return result;
}

// File Line: 3943
// RVA: 0x148CCB0
__int64 dynamic_initializer_for__VehicleOccupantIsInBoatCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOccupantIsInBoatCondition", 0xFFFFFFFF);
  VehicleOccupantIsInBoatCondition::sClassNameUID = result;
  return result;
}

// File Line: 3946
// RVA: 0x292780
bool __fastcall VehicleOccupantIsInBoatCondition::Match(
        VehicleOccupantIsInBoatCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::VehicleOccupantComponent *CurrentVehicle; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        mNext = CurrentVehicle->mpDriver.m_pPointer[4].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
        if ( mNext )
        {
          if ( !LODWORD(mNext[51].mNext) )
            return 1;
        }
      }
    }
  }
  return result;
}

// File Line: 3983
// RVA: 0x148CCD0
__int64 dynamic_initializer_for__VehicleOccupantIsInSinkingBoatCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOccupantIsInSinkingBoatCondition", 0xFFFFFFFF);
  VehicleOccupantIsInSinkingBoatCondition::sClassNameUID = result;
  return result;
}

// File Line: 3986
// RVA: 0x292840
bool __fastcall VehicleOccupantIsInSinkingBoatCondition::Match(
        VehicleOccupantIsInSinkingBoatCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::VehicleOccupantComponent *CurrentVehicle; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        mNext = CurrentVehicle->mpDriver.m_pPointer[4].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
        if ( mNext )
        {
          v7 = mNext[40].mNext;
          if ( v7 )
          {
            if ( (BYTE4(v7[37].mNext) & 7) == 0 && ((__int64)v7[38].mPrev[3].mNext & 1) != 0 )
              return 1;
          }
        }
      }
    }
  }
  return result;
}

// File Line: 4028
// RVA: 0x148CD10
__int64 dynamic_initializer_for__VehicleOccupantTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOccupantTypeCondition", 0xFFFFFFFF);
  VehicleOccupantTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 4034
// RVA: 0x2795C0
void __fastcall VehicleOccupantTypeCondition::VehicleOccupantTypeCondition(VehicleOccupantTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleOccupantTypeCondition::`vftable;
  this->m_eTargetType.mValue = 4;
}

// File Line: 4039
// RVA: 0x2929B0
bool __fastcall VehicleOccupantTypeCondition::Match(VehicleOccupantTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  m_pPointer,
                                  UFG::CharacterOccupantComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::CharacterOccupantComponent::_TypeUID)),
             m_pComponent = ComponentOfType)
          : (m_pComponent = m_pPointer->m_Components.p[44].m_pComponent),
            m_pComponent)
        && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == (unsigned __int8)this->m_eTargetType.mValue;
  return result;
}

// File Line: 4069
// RVA: 0x148B550
__int64 dynamic_initializer_for__IsOccupantOfTargetVehicleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsOccupantOfTargetVehicleCondition", 0xFFFFFFFF);
  IsOccupantOfTargetVehicleCondition::sClassNameUID = result;
  return result;
}

// File Line: 4077
// RVA: 0x277840
void __fastcall IsOccupantOfTargetVehicleCondition::IsOccupantOfTargetVehicleCondition(
        IsOccupantOfTargetVehicleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsOccupantOfTargetVehicleCondition::`vftable;
  *(_WORD *)&this->m_eOccupantTargetType.mValue = 7172;
}

// File Line: 4081
// RVA: 0x284250
bool __fastcall IsOccupantOfTargetVehicleCondition::Match(
        IsOccupantOfTargetVehicleCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::VehicleOccupantComponent *v12; // rdi

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[44].m_pComponent;
  }
  else
  {
    v7 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterOccupantComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterOccupantComponent::_TypeUID);
    m_pComponent = v7;
  }
  if ( m_pComponent
    && (v8 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v9 = v8->m_Flags, (v9 & 0x4000) == 0)
      ? (v9 >= 0
       ? ((v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID)),
          v10 = ComponentOfTypeHK)
       : (v10 = v8->m_Components.p[20].m_pComponent))
      : (v10 = v8->m_Components.p[20].m_pComponent),
        v10
     && (v12 = *(UFG::VehicleOccupantComponent **)(56i64
                                                 * *(unsigned __int8 *)((unsigned __int8)this->m_eVehicleTargetType.mValue
                                                                      + *(_QWORD *)&v10[1].m_Flags
                                                                      + 8i64)
                                                 + *(_QWORD *)&v10[1].m_TypeUID
                                                 + 40)) != 0i64
     && v12 == UFG::CharacterOccupantComponent::GetCurrentVehicle((UFG::CharacterOccupantComponent *)m_pComponent)) )
  {
    return LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == (unsigned __int8)this->m_eOccupantTargetType.mValue;
  }
  else
  {
    return 0;
  }
}

// File Line: 4117
// RVA: 0x148B2D0
__int64 dynamic_initializer_for__IsBoatInsideWorldCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsBoatInsideWorldCondition", 0xFFFFFFFF);
  IsBoatInsideWorldCondition::sClassNameUID = result;
  return result;
}

// File Line: 4120
// RVA: 0x277640
void __fastcall IsBoatInsideWorldCondition::IsBoatInsideWorldCondition(IsBoatInsideWorldCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsBoatInsideWorldCondition::`vftable;
}

// File Line: 4124
// RVA: 0x283920
bool __fastcall IsBoatInsideWorldCondition::Match(IsBoatInsideWorldCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::VehicleOccupantComponent *CurrentVehicle; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  result = 1;
  if ( LocalPlayer == m_pPointer && m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        mNext = CurrentVehicle->mpDriver.m_pPointer[4].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
        if ( mNext )
        {
          v7 = mNext[40].mNext;
          if ( v7 )
          {
            if ( (BYTE4(v7[37].mNext) & 7) == 0 && LOBYTE(v7[50].mNext) )
              return 0;
          }
        }
      }
    }
  }
  return result;
}

// File Line: 4165
// RVA: 0x148CD70
__int64 dynamic_initializer_for__VehicleOrientationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOrientationCondition", 0xFFFFFFFF);
  VehicleOrientationCondition::sClassNameUID = result;
  return result;
}

// File Line: 4170
// RVA: 0x292B60
bool __fastcall VehicleOrientationCondition::Match(VehicleOrientationCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectVehicle *CurrentVehicle; // rax
  int m_iVehicleOrientation; // ebx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
  else
    m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::CharacterOccupantComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::CharacterOccupantComponent::_TypeUID));
  if ( !m_pComponent )
    return 0;
  CurrentVehicle = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
  if ( !CurrentVehicle )
    return 0;
  m_iVehicleOrientation = this->m_iVehicleOrientation;
  return (unsigned int)UFG::VehicleUtility::GetVehicleOrientation(CurrentVehicle, 0, 0i64) == m_iVehicleOrientation;
}

// File Line: 4204
// RVA: 0x148C810
__int64 dynamic_initializer_for__TargetVehicleDoorsLockedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetVehicleDoorsLockedCondition", 0xFFFFFFFF);
  TargetVehicleDoorsLockedCondition::sClassNameUID = result;
  return result;
}

// File Line: 4209
// RVA: 0x2903C0
char __fastcall TargetVehicleDoorsLockedCondition::Match(
        TargetVehicleDoorsLockedCondition *this,
        ActionContext *pContext)
{
  __int64 mValue; // rbx
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimObjectGame *v4; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  __int16 v8; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  mValue = (unsigned __int8)this->mTargetType.mValue;
  if ( (_DWORD)mValue == 1 )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  }
  else
  {
    v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( !v4 )
      return 0;
    m_Flags = v4->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v4->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v7;
    }
    else
    {
      m_pComponent = v4->m_Components.p[20].m_pComponent;
    }
    if ( !m_pComponent )
      return 0;
    m_pPointer = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + mValue + 8)
                                        + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                        + 40);
  }
  if ( m_pPointer )
  {
    v8 = m_pPointer->m_Flags;
    if ( (v8 & 0x4000) == 0 )
    {
      if ( v8 < 0 )
      {
        ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
        goto LABEL_23;
      }
      if ( (v8 & 0x2000) == 0 )
      {
        if ( (v8 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_23:
        if ( ComponentOfTypeHK && LOBYTE(ComponentOfTypeHK[14].m_SafePointerList.mNode.mNext) )
          return 1;
      }
    }
    return 0;
  }
  return 0;
}

// File Line: 4247
// RVA: 0x148C830
__int64 dynamic_initializer_for__TargetVehicleOrientationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetVehicleOrientationCondition", 0xFFFFFFFF);
  TargetVehicleOrientationCondition::sClassNameUID = result;
  return result;
}

// File Line: 4255
// RVA: 0x2904F0
bool __fastcall TargetVehicleOrientationCondition::Match(
        TargetVehicleOrientationCondition *this,
        ActionContext *pContext)
{
  __int64 mValue; // rbx
  UFG::SimObjectVehicle *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  int m_iVehicleOrientation; // ebx
  bool v9; // dl
  float mAndLessThanAngle; // xmm1_4
  bool result; // al
  float pfReturn; // [rsp+30h] [rbp+8h] BYREF

  mValue = (unsigned __int8)this->mTargetType.mValue;
  m_pPointer = (UFG::SimObjectVehicle *)pContext->mSimObject.m_pPointer;
  if ( (_DWORD)mValue != 1 )
  {
    if ( !m_pPointer )
      return 0;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v7;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( !m_pComponent )
      return 0;
    m_pPointer = *(UFG::SimObjectVehicle **)(56i64
                                           * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + mValue + 8)
                                           + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                           + 40);
  }
  if ( !m_pPointer || (m_pPointer->m_Flags & 0x8000u) == 0 )
    return 0;
  m_iVehicleOrientation = this->m_iVehicleOrientation;
  v9 = this->m_bIgnoreWheelState != 0;
  pfReturn = FLOAT_3_4028235e38;
  result = 0;
  if ( (unsigned int)UFG::VehicleUtility::GetVehicleOrientation(m_pPointer, v9, &pfReturn) == m_iVehicleOrientation )
  {
    mAndLessThanAngle = this->mAndLessThanAngle;
    if ( mAndLessThanAngle < 0.0 || pfReturn < mAndLessThanAngle )
      return 1;
  }
  return result;
}

// File Line: 4304
// RVA: 0x148CE50
__int64 dynamic_initializer_for__VehicleWindowBrokenCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleWindowBrokenCondition", 0xFFFFFFFF);
  VehicleWindowBrokenCondition::sClassNameUID = result;
  return result;
}

// File Line: 4309
// RVA: 0x293360
bool __fastcall VehicleWindowBrokenCondition::Match(VehicleWindowBrokenCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleEffectsComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::VehicleEffectsComponent *)m_pPointer->m_Components.p[32].m_pComponent;
    goto LABEL_10;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    m_pComponent = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::VehicleEffectsComponent::_TypeUID);
  else
    m_pComponent = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::VehicleEffectsComponent::_TypeUID);
LABEL_10:
  if ( m_pComponent )
    return UFG::VehicleEffectsComponent::IsGlassBroken(
             m_pComponent,
             (UFG::eVehicleWindowTypeEnum)this->m_eWindowType.mValue);
  return 0;
}

// File Line: 4337
// RVA: 0x148C850
__int64 dynamic_initializer_for__TargetVehicleWindowBrokenCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetVehicleWindowBrokenCondition", 0xFFFFFFFF);
  TargetVehicleWindowBrokenCondition::sClassNameUID = result;
  return result;
}

// File Line: 4343
// RVA: 0x290620
bool __fastcall TargetVehicleWindowBrokenCondition::Match(
        TargetVehicleWindowBrokenCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *Target; // rax
  __int16 m_Flags; // r8
  UFG::VehicleEffectsComponent *ComponentOfTypeHK; // rax

  Target = (UFG::SimObjectGame *)UFG::getTarget(
                                   pContext,
                                   (UFG::eTargetTypeEnum)(unsigned __int8)this->m_eTargetType.mValue);
  if ( !Target )
    return 0;
  m_Flags = Target->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_3;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
LABEL_3:
      ComponentOfTypeHK = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            Target,
                                                            UFG::VehicleEffectsComponent::_TypeUID);
      goto LABEL_10;
    }
    ComponentOfTypeHK = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                          Target,
                                                          UFG::VehicleEffectsComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::VehicleEffectsComponent *)Target->m_Components.p[32].m_pComponent;
  }
LABEL_10:
  if ( ComponentOfTypeHK )
    return UFG::VehicleEffectsComponent::IsGlassBroken(
             ComponentOfTypeHK,
             (UFG::eVehicleWindowTypeEnum)this->m_eWindowType.mValue);
  return 0;
}

// File Line: 4376
// RVA: 0x148CC70
__int64 dynamic_initializer_for__VehicleNumberOfTiresDamagedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleNumberOfTiresDamagedCondition", 0xFFFFFFFF);
  VehicleNumberOfTiresDamagedCondition::sClassNameUID = result;
  return result;
}

// File Line: 4384
// RVA: 0x2925E0
char __fastcall VehicleNumberOfTiresDamagedCondition::Match(
        VehicleNumberOfTiresDamagedCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int mNumWheels; // ebp
  int v8; // edi
  int i; // ebx
  float TireDamage; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    m_pComponent = (UFG::PhysicsMoverInterface *)ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  mNumWheels = m_pComponent->mNumWheels;
  v8 = 0;
  for ( i = 0; i < mNumWheels; ++i )
  {
    TireDamage = UFG::PhysicsMoverInterface::GetTireDamage(m_pComponent, i);
    if ( CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->m_eDamageComparison.mValue,
           this->m_fDamage,
           TireDamage) )
    {
      ++v8;
    }
  }
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->m_eNumberComparison.mValue,
           (float)this->m_iNumber,
           (float)v8);
}

// File Line: 4422
// RVA: 0x148CBB0
__int64 dynamic_initializer_for__VehicleEngineRipeForTakedownCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleEngineRipeForTakedownCondition", 0xFFFFFFFF);
  VehicleEngineRipeForTakedownCondition::sClassNameUID = result;
  return result;
}

// File Line: 4425
// RVA: 0x292280
bool __fastcall VehicleEngineRipeForTakedownCondition::Match(
        VehicleEngineRipeForTakedownCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfTypeHK )
    return 0;
  return (BYTE4(ComponentOfTypeHK[14].vfptr) & 4) != 0
      && (unsigned int)(HIDWORD(ComponentOfTypeHK[2].m_BoundComponentHandles.mNode.mPrev) - 1) > 1;
}

// File Line: 4445
// RVA: 0x148CAB0
__int64 dynamic_initializer_for__VehicleDamageCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDamageCondition", 0xFFFFFFFF);
  VehicleDamageCondition::sClassNameUID = result;
  return result;
}

// File Line: 4452
// RVA: 0x2918C0
char __fastcall VehicleDamageCondition::Match(VehicleDamageCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int mValue; // edx
  float EngineDamage; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::PhysicsMoverInterface::_TypeUID);
    m_pComponent = (UFG::PhysicsMoverInterface *)ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  mValue = (unsigned __int8)this->m_eVehicleDamageType.mValue;
  EngineDamage = 0.0;
  if ( mValue == 1 )
  {
    EngineDamage = UFG::PhysicsMoverInterface::GetEngineDamage(m_pComponent);
  }
  else if ( (unsigned int)(mValue - 2) <= 3 )
  {
    EngineDamage = UFG::PhysicsMoverInterface::GetTireDamage(m_pComponent, mValue - 2);
  }
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->m_eInEqualityOperator.mValue,
           this->m_fDamage,
           EngineDamage);
}

// File Line: 4515
// RVA: 0x148CBF0
__int64 dynamic_initializer_for__VehicleHasDriverOrPassengerOccupantCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleHasDriverOrPassengerOccupantCondition", 0xFFFFFFFF);
  VehicleHasDriverOrPassengerOccupantCondition::sClassNameUID = result;
  return result;
}

// File Line: 4517
// RVA: 0x2923A0
bool __fastcall VehicleHasDriverOrPassengerOccupantCondition::Match(
        VehicleHasDriverOrPassengerOccupantCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleOccupantComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::VehicleOccupantComponent *)m_pPointer->m_Components.p[30].m_pComponent;
    goto LABEL_10;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    m_pComponent = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::VehicleOccupantComponent::_TypeUID);
  else
    m_pComponent = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::VehicleOccupantComponent::_TypeUID);
LABEL_10:
  if ( m_pComponent )
    return (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(m_pComponent) != 0;
  return 0;
}

// File Line: 4537
// RVA: 0x148CAD0
__int64 dynamic_initializer_for__VehicleDeniesAllyDriverCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDeniesAllyDriverCondition", 0xFFFFFFFF);
  VehicleDeniesAllyDriverCondition::sClassNameUID = result;
  return result;
}

// File Line: 4542
// RVA: 0x291970
bool __fastcall VehicleDeniesAllyDriverCondition::Match(
        VehicleDeniesAllyDriverCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  bool *v9; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v7 = *(_QWORD *)(56i64
                            * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                 + *(_QWORD *)&m_pComponent[1].m_Flags
                                                 + 8i64)
                            + *(_QWORD *)&m_pComponent[1].m_TypeUID
                            + 40)) != 0
         && (v8 = *(UFG::SceneObjectProperties **)(v7 + 80)) != 0i64
         && (v9 = PropertyUtils::Get<bool>(v8, (UFG::qArray<unsigned long,0> *)&qSymbol_DeniesAllyDriver)) != 0i64)
        && *v9;
  return result;
}

// File Line: 4584
// RVA: 0x148CAF0
__int64 dynamic_initializer_for__VehicleDeniesAllyPassengerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDeniesAllyPassengerCondition", 0xFFFFFFFF);
  VehicleDeniesAllyPassengerCondition::sClassNameUID = result;
  return result;
}

// File Line: 4589
// RVA: 0x291A40
bool __fastcall VehicleDeniesAllyPassengerCondition::Match(
        VehicleDeniesAllyPassengerCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  bool *v9; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v7 = *(_QWORD *)(56i64
                            * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                 + *(_QWORD *)&m_pComponent[1].m_Flags
                                                 + 8i64)
                            + *(_QWORD *)&m_pComponent[1].m_TypeUID
                            + 40)) != 0
         && (v8 = *(UFG::SceneObjectProperties **)(v7 + 80)) != 0i64
         && (v9 = PropertyUtils::Get<bool>(v8, (UFG::qArray<unsigned long,0> *)&qSymbol_DeniesAllyPassenger)) != 0i64)
        && *v9;
  return result;
}

// File Line: 4631
// RVA: 0x148CB30
__int64 dynamic_initializer_for__VehicleDeniesGetInPassengerSideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDeniesGetInPassengerSideCondition", 0xFFFFFFFF);
  VehicleDeniesGetInPassengerSideCondition::sClassNameUID = result;
  return result;
}

// File Line: 4636
// RVA: 0x291BE0
bool __fastcall VehicleDeniesGetInPassengerSideCondition::Match(
        VehicleDeniesGetInPassengerSideCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  bool *v9; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v7 = *(_QWORD *)(56i64
                            * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                 + *(_QWORD *)&m_pComponent[1].m_Flags
                                                 + 8i64)
                            + *(_QWORD *)&m_pComponent[1].m_TypeUID
                            + 40)) != 0
         && (v8 = *(UFG::SceneObjectProperties **)(v7 + 80)) != 0i64
         && (v9 = PropertyUtils::Get<bool>(v8, (UFG::qArray<unsigned long,0> *)&qSymbol_DeniesGetInPassengerSide)) != 0i64)
        && *v9;
  return result;
}

// File Line: 4678
// RVA: 0x148CB10
__int64 dynamic_initializer_for__VehicleDeniesGetInDriverSideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDeniesGetInDriverSideCondition", 0xFFFFFFFF);
  VehicleDeniesGetInDriverSideCondition::sClassNameUID = result;
  return result;
}

// File Line: 4683
// RVA: 0x291B10
bool __fastcall VehicleDeniesGetInDriverSideCondition::Match(
        VehicleDeniesGetInDriverSideCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  bool *v9; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v7 = *(_QWORD *)(56i64
                            * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                 + *(_QWORD *)&m_pComponent[1].m_Flags
                                                 + 8i64)
                            + *(_QWORD *)&m_pComponent[1].m_TypeUID
                            + 40)) != 0
         && (v8 = *(UFG::SceneObjectProperties **)(v7 + 80)) != 0i64
         && (v9 = PropertyUtils::Get<bool>(v8, (UFG::qArray<unsigned long,0> *)&qSymbol_DeniesGetInDriverSide)) != 0i64)
        && *v9;
  return result;
}

// File Line: 4725
// RVA: 0x148CB50
__int64 dynamic_initializer_for__VehicleDeniesHijackCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDeniesHijackCondition", 0xFFFFFFFF);
  VehicleDeniesHijackCondition::sClassNameUID = result;
  return result;
}

// File Line: 4730
// RVA: 0x291CB0
bool __fastcall VehicleDeniesHijackCondition::Match(VehicleDeniesHijackCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qPropertySet *DriverProfile; // rax
  bool *v11; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( m_pComponent
    && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                      * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                           + *(_QWORD *)&m_pComponent[1].m_Flags
                                                           + 8i64)
                                      + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                      + 40)) != 0i64
    && ((v8 = v7->m_Flags, (v8 & 0x4000) != 0) || v8 < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7))
      : (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v7,
                                                         UFG::AiDriverComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                         v7,
                                                         UFG::AiDriverComponent::_TypeUID)),
        ComponentOfTypeHK
     && (DriverProfile = UFG::AiDriverComponent::GetDriverProfile(ComponentOfTypeHK)) != 0i64
     && (v11 = PropertyUtils::Get<bool>(
                 DriverProfile,
                 (UFG::qArray<unsigned long,0> *)&qSymbol_DeniesHijack,
                 DEPTH_RECURSE)) != 0i64) )
  {
    return *v11;
  }
  else
  {
    return 0;
  }
}

// File Line: 4780
// RVA: 0x148C9B0
__int64 dynamic_initializer_for__VehicleAimingShotBlockedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleAimingShotBlockedCondition", 0xFFFFFFFF);
  VehicleAimingShotBlockedCondition::sClassNameUID = result;
  return result;
}

// File Line: 4785
// RVA: 0x290B80
bool __fastcall VehicleAimingShotBlockedCondition::Match(
        VehicleAimingShotBlockedCondition *this,
        ActionContext *pContext)
{
  unsigned int v4; // eax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v8; // rax
  __int64 v9; // rbx
  UFG::SceneObjectProperties *v10; // rcx
  float *v11; // rsi
  float *v12; // rax
  float *v13; // rbx
  UFG::SimObject *v14; // r8
  __int16 v15; // dx
  UFG::AimingBaseComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v17; // rcx
  float LocalAimDirectionXY; // xmm0_4

  v4 = _S9_4;
  if ( (_S9_4 & 1) == 0 )
  {
    _S9_4 |= 1u;
    UFG::qSymbol::create_from_string(&symVehicleAimBlockedRangeStart, "VehicleAimBlockedRangeStart");
    atexit(VehicleAimingShotBlockedCondition::Match_::_2_::_dynamic_atexit_destructor_for__symVehicleAimBlockedRangeStart__);
    v4 = _S9_4;
  }
  if ( (v4 & 2) == 0 )
  {
    _S9_4 = v4 | 2;
    UFG::qSymbol::create_from_string(&symVehicleAimBlockedRangeEnd, "VehicleAimBlockedRangeEnd");
    atexit(VehicleAimingShotBlockedCondition::Match_::_2_::_dynamic_atexit_destructor_for__symVehicleAimBlockedRangeEnd__);
  }
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v8;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v9 = *(_QWORD *)(56i64
                     * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                          + *(_QWORD *)&m_pComponent[1].m_Flags
                                          + 8i64)
                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                     + 40);
      if ( v9 )
      {
        v10 = *(UFG::SceneObjectProperties **)(v9 + 80);
        if ( v10 )
        {
          v11 = PropertyUtils::Get<float>(v10, (UFG::qArray<unsigned long,0> *)&symVehicleAimBlockedRangeStart);
          v12 = PropertyUtils::Get<float>(
                  *(UFG::SceneObjectProperties **)(v9 + 80),
                  (UFG::qArray<unsigned long,0> *)&symVehicleAimBlockedRangeEnd);
          v13 = v12;
          if ( v11 )
          {
            if ( v12 )
            {
              v14 = pContext->mSimObject.m_pPointer;
              if ( v14 )
              {
                v15 = v14->m_Flags;
                if ( (v15 & 0x4000) != 0 )
                {
                  ComponentOfTypeHK = (UFG::AimingBaseComponent *)v14->m_Components.p[47].m_pComponent;
                }
                else
                {
                  v17 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
                  if ( v15 < 0 || (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
                    ComponentOfTypeHK = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v17,
                                                                      UFG::AimingBaseComponent::_TypeUID);
                  else
                    ComponentOfTypeHK = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v17,
                                                                      UFG::AimingBaseComponent::_TypeUID);
                }
                if ( ComponentOfTypeHK )
                {
                  LocalAimDirectionXY = UFG::AimingBaseComponent::GetLocalAimDirectionXY(ComponentOfTypeHK);
                  if ( *v11 >= *v13 )
                  {
                    if ( LocalAimDirectionXY > (float)((float)(*v11 * 3.1415927) * 0.0055555557) )
                      return 1;
                  }
                  else if ( LocalAimDirectionXY <= (float)((float)(*v11 * 3.1415927) * 0.0055555557) )
                  {
                    return 0;
                  }
                  return (float)((float)(*v13 * 3.1415927) * 0.0055555557) > LocalAimDirectionXY;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 4840
// RVA: 0x148CA50
__int64 dynamic_initializer_for__VehicleCanActionHijackCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleCanActionHijackCondition", 0xFFFFFFFF);
  VehicleCanActionHijackCondition::sClassNameUID = result;
  return result;
}

// File Line: 4845
// RVA: 0x2911F0
bool __fastcall VehicleCanActionHijackCondition::Match(VehicleCanActionHijackCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::TargetingSystemVehicleComponent *ComponentOfType; // rax
  UFG::ActionHijackProfile *m_pActionHijackProfile; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
      : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
        m_pComponent
     && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                       + 40)) != 0i64
     && ((v8 = v7->m_Flags, (v8 & 0x4000) != 0) || v8 < 0
       ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v7))
       : (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
       ? (ComponentOfType = (UFG::TargetingSystemVehicleComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v7,
                                                                      UFG::TargetingSystemVehicleComponent::_TypeUID))
       : (ComponentOfType = (UFG::TargetingSystemVehicleComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v7,
                                                                      UFG::TargetingSystemVehicleComponent::_TypeUID)),
         ComponentOfType && (m_pActionHijackProfile = ComponentOfType->m_pActionHijackProfile) != 0i64)) )
  {
    return m_pActionHijackProfile->m_bCanActionHijackTo;
  }
  else
  {
    return 0;
  }
}

// File Line: 4887
// RVA: 0x148CA30
__int64 dynamic_initializer_for__VehicleCanActionHijackClimbCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleCanActionHijackClimbCondition", 0xFFFFFFFF);
  VehicleCanActionHijackClimbCondition::sClassNameUID = result;
  return result;
}

// File Line: 4892
// RVA: 0x2910C0
bool __fastcall VehicleCanActionHijackClimbCondition::Match(
        VehicleCanActionHijackClimbCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::TargetingSystemVehicleComponent *ComponentOfType; // rax
  UFG::ActionHijackProfile *m_pActionHijackProfile; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
      : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
        m_pComponent
     && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                       + 40)) != 0i64
     && ((v8 = v7->m_Flags, (v8 & 0x4000) != 0) || v8 < 0
       ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v7))
       : (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
       ? (ComponentOfType = (UFG::TargetingSystemVehicleComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v7,
                                                                      UFG::TargetingSystemVehicleComponent::_TypeUID))
       : (ComponentOfType = (UFG::TargetingSystemVehicleComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v7,
                                                                      UFG::TargetingSystemVehicleComponent::_TypeUID)),
         ComponentOfType && (m_pActionHijackProfile = ComponentOfType->m_pActionHijackProfile) != 0i64)) )
  {
    return m_pActionHijackProfile->m_bCanActionHijackClimb;
  }
  else
  {
    return 0;
  }
}

// File Line: 4933
// RVA: 0x1491B80
__int64 dynamic_initializer_for__gVehicleDoorEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gVehicleDoorEnum, "Global/Act/VehicleDoor.xml");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gVehicleDoorEnum__);
}

// File Line: 4935
// RVA: 0x148CA70
__int64 dynamic_initializer_for__VehicleCanOpenDoorCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleCanOpenDoorCondition", 0xFFFFFFFF);
  VehicleCanOpenDoorCondition::sClassNameUID = result;
  return result;
}

// File Line: 4942
// RVA: 0x2794B0
void __fastcall VehicleCanOpenDoorCondition::VehicleCanOpenDoorCondition(VehicleCanOpenDoorCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleCanOpenDoorCondition::`vftable;
  this->m_Door = 0;
}

// File Line: 4947
// RVA: 0x291320
char __fastcall VehicleCanOpenDoorCondition::Match(VehicleCanOpenDoorCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *mCreature; // r14
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  const char *v9; // rdx
  UFG::SimObjectCVBase *v10; // rcx
  __int16 v11; // dx
  UFG::SimObjectVehiclePropertiesComponent *v12; // rax
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *DoorPhantomInfo; // rax
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *v14; // rdi
  __m128 extentX_low; // xmm6
  __m128 extentY_low; // xmm7
  UFG::SimObject *v17; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v20; // xmm4_4
  __m128 x_low; // xmm5
  float v22; // xmm3_4
  __m128 v23; // xmm2
  float v24; // xmm6_4
  float v25; // xmm4_4
  __m128 v26; // xmm5
  float v27; // xmm3_4
  __m128 v28; // xmm2
  float v29; // xmm7_4
  float v30; // xmm9_4
  float v31; // xmm10_4
  float v32; // xmm7_4
  int BoneID; // eax
  float heightOffset; // xmm6_4
  __m128 y_low; // xmm3
  float v36; // xmm6_4
  float x; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  UFG::SimObject *v46; // rax
  UFG::qVector3 translation; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 forward; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 up; // [rsp+50h] [rbp-B0h] BYREF
  UFG::SensorPhantomIterator v51; // [rsp+60h] [rbp-A0h] BYREF
  UFG::SensorPhantom sensor; // [rsp+78h] [rbp-88h] BYREF
  hkVector4f halfExtents; // [rsp+90h] [rbp-70h] BYREF
  __int64 v54; // [rsp+A0h] [rbp-60h]
  hkpBoxShape v55; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qMatrix44 dest; // [rsp+F0h] [rbp-10h] BYREF
  UFG::qSymbolUC v57; // [rsp+1A8h] [rbp+A8h] BYREF

  v54 = -2i64;
  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
  }
  else
  {
    v6 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::CharacterAnimationComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v6 )
    return 0;
  mCreature = v6->mCreature;
  if ( !mCreature )
    return 0;
  m_pTransformNodeComponent = 0i64;
  if ( (gVehicleDoorEnum.m_enumLists.size & 0x80000000) != 0 )
    v9 = 0i64;
  else
    v9 = (*gVehicleDoorEnum.m_enumLists.p)->m_enumName.p[this->m_Door];
  UFG::qSymbolUC::create_from_string(&v57, v9);
  v10 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 & 0x4000) != 0 || v11 < 0 )
      v12 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v10);
    else
      v12 = (UFG::SimObjectVehiclePropertiesComponent *)((v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v10,
                                                           UFG::SimObjectVehiclePropertiesComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           v10,
                                                           UFG::SimObjectVehiclePropertiesComponent::_TypeUID));
    if ( v12 )
    {
      DoorPhantomInfo = UFG::SimObjectVehiclePropertiesComponent::GetDoorPhantomInfo(v12, v57.mUID);
      v14 = DoorPhantomInfo;
      if ( DoorPhantomInfo )
      {
        extentX_low = (__m128)LODWORD(DoorPhantomInfo->extentX);
        extentX_low.m128_f32[0] = extentX_low.m128_f32[0] * 0.5;
        extentY_low = (__m128)LODWORD(DoorPhantomInfo->extentY);
        extentY_low.m128_f32[0] = extentY_low.m128_f32[0] * 0.5;
        halfExtents.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(extentX_low, (__m128)LODWORD(DoorPhantomInfo->height)),
                               _mm_unpacklo_ps(extentY_low, (__m128)0i64));
        hkpBoxShape::hkpBoxShape(&v55, &halfExtents, hkConvexShapeDefaultRadius);
        v17 = pContext->mSimObject.m_pPointer;
        if ( v17 )
          m_pTransformNodeComponent = v17->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        y = m_pTransformNodeComponent->mWorldTransform.v2.y;
        z = m_pTransformNodeComponent->mWorldTransform.v2.z;
        up.x = m_pTransformNodeComponent->mWorldTransform.v2.x;
        up.y = y;
        up.z = z;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v20 = m_pTransformNodeComponent->mWorldTransform.v0.y;
        x_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.x);
        v22 = m_pTransformNodeComponent->mWorldTransform.v0.z;
        v23 = x_low;
        v23.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v20 * v20))
                        + (float)(v22 * v22);
        v24 = extentX_low.m128_f32[0] / _mm_sqrt_ps(v23).m128_f32[0];
        forward.x = v24 * x_low.m128_f32[0];
        forward.y = v24 * v20;
        forward.z = v24 * v22;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v25 = m_pTransformNodeComponent->mWorldTransform.v1.y;
        v26 = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v1.x);
        v27 = m_pTransformNodeComponent->mWorldTransform.v1.z;
        v28 = v26;
        v28.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v27 * v27);
        v29 = extentY_low.m128_f32[0] / _mm_sqrt_ps(v28).m128_f32[0];
        v30 = v29 * v27;
        v31 = v29 * v25;
        v32 = v29 * v26.m128_f32[0];
        if ( mCreature->mPose.mRigHandle.mData )
          BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, v57.mUID);
        else
          BoneID = -1;
        Creature::GetTranslation(mCreature, &translation, BoneID);
        heightOffset = v14->heightOffset;
        if ( heightOffset == 0.0 )
        {
          v39 = translation.z;
          v38 = translation.y;
          x = translation.x;
        }
        else
        {
          y_low = (__m128)LODWORD(up.y);
          y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(up.x * up.x))
                            + (float)(up.z * up.z);
          v36 = heightOffset / _mm_sqrt_ps(y_low).m128_f32[0];
          x = translation.x + (float)(v36 * up.x);
          v38 = translation.y + (float)(v36 * up.y);
          v39 = translation.z + (float)(v36 * up.z);
          translation.x = x;
          translation.y = v38;
          translation.z = v39;
        }
        if ( v14->extendLeft )
        {
          v40 = x + v32;
          v41 = v38 + v31;
          v42 = v39 + v30;
        }
        else
        {
          v40 = x - v32;
          v41 = v38 - v31;
          v42 = v39 - v30;
        }
        translation.z = v42;
        translation.y = v41;
        translation.x = v40;
        if ( v14->extendForward )
        {
          v43 = v40 + forward.x;
          v44 = v41 + forward.y;
          v45 = v42 + forward.z;
        }
        else
        {
          v43 = v40 - forward.x;
          v44 = v41 - forward.y;
          v45 = v42 - forward.z;
        }
        translation.z = v45;
        translation.y = v44;
        translation.x = v43;
        UFG::qMakeMatrix(&dest, &forward, &up, &translation, 0.001);
        UFG::SensorPhantom::SensorPhantom(&sensor, &v55, &dest, 0x10u);
        UFG::SensorPhantomIterator::SensorPhantomIterator(&v51, &sensor, 0);
        while ( UFG::SensorPhantomIterator::operator*(&v51) )
        {
          v46 = (UFG::SimObject *)UFG::SensorPhantomIterator::operator*(&v51);
          if ( v46 != pContext->mSimObject.m_pPointer && (v46->m_Flags & 0x4000) == 0 )
          {
            UFG::SensorPhantomIterator::~SensorPhantomIterator(&v51);
            UFG::SensorPhantom::~SensorPhantom(&sensor);
            hkpBoxShape::~hkpBoxShape(&v55);
            return 0;
          }
          UFG::SensorPhantomIterator::operator++(&v51);
        }
        UFG::SensorPhantomIterator::~SensorPhantomIterator(&v51);
        UFG::SensorPhantom::~SensorPhantom(&sensor);
        hkpBoxShape::~hkpBoxShape(&v55);
      }
    }
  }
  return 1;
}

// File Line: 5032
// RVA: 0x148C9F0
__int64 dynamic_initializer_for__VehicleBoxSideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleBoxSideCondition", 0xFFFFFFFF);
  VehicleBoxSideCondition::sClassNameUID = result;
  return result;
}

// File Line: 5038
// RVA: 0x290EC0
bool __fastcall VehicleBoxSideCondition::Match(VehicleBoxSideCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectVehicle *v8; // rcx
  __int16 v9; // dx
  UFG::VehicleSubjectComponent *ComponentOfTypeHK; // rax
  UFG::VehicleSubjectComponent *v11; // rbx
  UFG::SimObject *v12; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObjectVehicle **)(56i64
                                 * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                      + *(_QWORD *)&m_pComponent[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                 + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    goto LABEL_19;
  if ( v9 < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v8);
    goto LABEL_21;
  }
  if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
LABEL_19:
    ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v8,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                          v8,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
LABEL_21:
  v11 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  v12 = pContext->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( v12 )
    m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  return (unsigned int)UFG::VehicleSubjectComponent::GetBoxSide(
                         v11,
                         (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3) == this->mBoxSide;
}

// File Line: 5079
// RVA: 0x148CB70
__int64 dynamic_initializer_for__VehicleDirectlyBehindCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDirectlyBehindCondition", 0xFFFFFFFF);
  VehicleDirectlyBehindCondition::sClassNameUID = result;
  return result;
}

// File Line: 5086
// RVA: 0x291E00
char __fastcall VehicleDirectlyBehindCondition::Match(VehicleDirectlyBehindCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectVehicle *v8; // rcx
  __int16 v9; // dx
  UFG::VehicleSubjectComponent *ComponentOfTypeHK; // rax
  UFG::VehicleSubjectComponent *v11; // rdi
  UFG::SimObject *v12; // rax
  char v13; // si
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  float *v15; // rbx
  float *v16; // rax
  float x; // xmm6_4
  float y; // xmm11_4
  float v19; // xmm10_4
  float v20; // xmm9_4
  float v21; // xmm8_4
  float z; // xmm7_4
  float *v23; // rax
  float v24; // xmm12_4
  float v25; // xmm5_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm11_4
  float v30; // xmm6_4
  float v31; // xmm11_4
  float v32; // xmm12_4
  float v33; // xmm4_4
  float v34; // xmm8_4
  float v35; // xmm2_4
  char result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObjectVehicle **)(56i64
                                 * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                      + *(_QWORD *)&m_pComponent[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                 + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    goto LABEL_19;
  if ( v9 < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v8);
    goto LABEL_21;
  }
  if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
LABEL_19:
    ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v8,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                          v8,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
LABEL_21:
  v11 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  v12 = pContext->mSimObject.m_pPointer;
  v13 = 0;
  m_pTransformNodeComponent = 0i64;
  if ( v12 )
    m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v15 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v11->vfptr[23].__vecDelDtor)(v11);
  v16 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v11->vfptr[24].__vecDelDtor)(v11);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  v19 = (float)(*v16 + *v15) * 0.5;
  v20 = (float)(v16[1] + v15[1]) * 0.5;
  v21 = (float)(v16[2] + v15[2]) * 0.5;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v23 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v11->vfptr[19].__vecDelDtor)(v11);
  v24 = y * v23[5];
  v25 = *v15 - v19;
  v26 = v15[1] - v20;
  v27 = (float)((float)(y * v23[4]) + (float)(x * *v23)) + (float)(z * v23[8]);
  v28 = x * v23[1];
  v29 = (float)(y * v23[6]) + (float)(x * v23[2]);
  v30 = v15[2] - v21;
  v31 = (float)((float)(v29 + (float)(z * v23[10])) + v23[14]) - v21;
  v32 = (float)((float)((float)(v24 + v28) + (float)(z * v23[9])) + v23[13]) - v20;
  v33 = (float)(v27 + v23[12]) - v19;
  if ( this->mPastRearEnd )
    LODWORD(v35) = COERCE_UNSIGNED_INT(
                     (float)((float)(v26 * UFG::qVector3::msAxisX.y) + (float)(v25 * UFG::qVector3::msAxisX.x))
                   + (float)(v30 * UFG::qVector3::msAxisX.z)) & _xmm;
  else
    v35 = 0.0;
  LODWORD(v34) = COERCE_UNSIGNED_INT(
                   (float)((float)(v33 * UFG::qVector3::msAxisX.x) + (float)(v32 * UFG::qVector3::msAxisX.y))
                 + (float)(v31 * UFG::qVector3::msAxisX.z)) & _xmm;
  result = v34 >= v35;
  if ( this->mNotPastLeftRightSides )
  {
    if ( v34 >= v35
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        (float)((float)(v33 * UFG::qVector3::msAxisY.x) + (float)(v32 * UFG::qVector3::msAxisY.y))
                      + (float)(v31 * UFG::qVector3::msAxisY.z)) & _xmm) < COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                                                          (float)((float)(v26 * UFG::qVector3::msAxisY.y)
                                                                                                + (float)(v25 * UFG::qVector3::msAxisY.x))
                                                                                        + (float)(v30
                                                                                                * UFG::qVector3::msAxisY.z)) & _xmm) )
    {
      return 1;
    }
    return v13;
  }
  return result;
}

// File Line: 5149
// RVA: 0x148ACF0
__int64 dynamic_initializer_for__DriverProfileTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverProfileTypeCondition", 0xFFFFFFFF);
  DriverProfileTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 5155
// RVA: 0x2815A0
_BOOL8 __fastcall DriverProfileTypeCondition::Match(DriverProfileTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  unsigned int *DriverProfileType; // rax
  int v7; // eax

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
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
        ComponentOfTypeHK
     && (DriverProfileType = UFG::AiDriverComponent::GetDriverProfileType(ComponentOfTypeHK)) != 0i64
     && (v7 = *DriverProfileType) != 0
     && v7 < 3) )
  {
    return this->mIsTrue != 0;
  }
  else
  {
    return this->mIsTrue == 0;
  }
}

// File Line: 5202
// RVA: 0x148C650
__int64 dynamic_initializer_for__TargetRelativePosition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetRelativePosition", 0xFFFFFFFF);
  TargetRelativePosition::sClassNameUID = result;
  return result;
}

// File Line: 5220
// RVA: 0x279000
void __fastcall TargetRelativePosition::TargetRelativePosition(TargetRelativePosition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetRelativePosition::`vftable;
  this->mTargetType.mValue = 0;
  this->mDirection = 0.0;
  *(_QWORD *)&this->mAngleRange = 1070141403i64;
}

// File Line: 5224
// RVA: 0x28EBB0
bool __fastcall TargetRelativePosition::Match(TargetRelativePosition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v7; // rcx
  UFG::SimComponent *v8; // r8
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned __int8 mValue; // al
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v15; // rbx
  __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  UFG::RigidBody *v18; // rdi
  UFG::SimObject *v19; // rdx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  __m128 v21; // xmm2
  UFG::qVector3 *CentreOfMass; // rax
  float y; // xmm1_4
  UFG::SimObject *v24; // rdx
  UFG::TransformNodeComponent *v25; // rcx
  UFG::SimObjectGame *v26; // rcx
  __int16 v27; // dx
  UFG::SimComponent *v28; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rdi
  _DWORD *v30; // rax
  float v31; // xmm9_4
  float v32; // xmm10_4
  float v33; // xmm11_4
  __int64 v34; // rax
  float v35; // xmm7_4
  float v36; // xmm4_4
  float v37; // xmm8_4
  float v38; // xmm3_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  float v43; // xmm7_4
  float v44; // xmm2_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  UFG::SimObject *v47; // rdx
  UFG::TransformNodeComponent *v48; // rcx
  __m128 y_low; // xmm0
  float v50; // xmm4_4
  float v51; // xmm4_4
  UFG::qVector3 v1; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qMatrix44 matSimObject; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qMatrix44 v55; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector3 result; // [rsp+B0h] [rbp-50h] BYREF
  char v57[20]; // [rsp+BCh] [rbp-44h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
    else
      m_pComponent = (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 & 0x4000) != 0 )
    {
      v8 = v7->m_Components.p[20].m_pComponent;
    }
    else if ( v9 >= 0 )
    {
      if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = ComponentOfTypeHK;
    }
    else
    {
      v8 = v7->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v8 = 0i64;
  }
  mValue = this->mTargetsTarget.mValue;
  if ( mValue )
  {
    v12 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + mValue + 8i64)
                                 + *(_QWORD *)&v8[1].m_TypeUID
                                 + 40);
    if ( !v12 )
      return 0;
    v13 = v12->m_Flags;
    if ( (v13 & 0x4000) != 0 )
    {
      v8 = v12->m_Components.p[20].m_pComponent;
    }
    else if ( v13 >= 0 )
    {
      if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = ComponentOfType;
    }
    else
    {
      v8 = v12->m_Components.p[20].m_pComponent;
    }
  }
  if ( !v8 )
    return 0;
  v15 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                    + *(_QWORD *)&v8[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v8[1].m_TypeUID
                               + 40);
  if ( !v15 )
    return 0;
  if ( this->mRelativeToCentreOfMass
    && ((v16 = v15->m_Flags, (v16 & 0x4000) == 0) && v16 >= 0 && (v16 & 0x2000) == 0 && (v16 & 0x1000) == 0
      ? (v17 = UFG::SimObject::GetComponentOfType(v15, UFG::RigidBodyComponent::_TypeUID))
      : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RigidBodyComponent::_TypeUID)),
        (v18 = (UFG::RigidBody *)v17) != 0i64) )
  {
    v19 = context->mSimObject.m_pPointer;
    m_pTransformNodeComponent = 0i64;
    if ( v19 )
      m_pTransformNodeComponent = v19->m_pTransformNodeComponent;
    UFG::TargetingSystemBaseComponent::FindMatrix(m_pTransformNodeComponent, v19, &matSimObject);
    v21 = 0i64;
    v21.m128_f32[0] = (float)1;
    v55.v0 = (UFG::qVector4)v21;
    v55.v3 = (UFG::qVector4)_mm_shuffle_ps(v21, v21, 21);
    v55.v1 = (UFG::qVector4)_mm_shuffle_ps(v21, v21, 81);
    v55.v2 = (UFG::qVector4)_mm_shuffle_ps(v21, v21, 69);
    CentreOfMass = UFG::RigidBody::GetCentreOfMass(v18, &result);
    y = CentreOfMass->y;
    v21.m128_i32[0] = LODWORD(CentreOfMass->z);
    v55.v3.x = CentreOfMass->x;
    v55.v3.y = y;
    LODWORD(v55.v3.w) = (_DWORD)FLOAT_1_0;
    LODWORD(v55.v3.z) = v21.m128_i32[0];
  }
  else if ( this->mRelativeToTarget )
  {
    UFG::TargetingSystemBaseComponent::FindMatrix(v15, &matSimObject);
    v24 = context->mSimObject.m_pPointer;
    v25 = 0i64;
    if ( v24 )
      v25 = v24->m_pTransformNodeComponent;
    UFG::TargetingSystemBaseComponent::FindMatrix(v25, v24, &v55);
  }
  else if ( this->mRelativeToCover )
  {
    v26 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( !v26 )
      return 0;
    v27 = v26->m_Flags;
    if ( (v27 & 0x4000) != 0 || v27 < 0 || (v27 & 0x2000) != 0 || (v27 & 0x1000) != 0 )
      v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::AICoverComponent::_TypeUID);
    else
      v28 = UFG::SimObject::GetComponentOfType(v26, UFG::AICoverComponent::_TypeUID);
    if ( !v28 )
      return 0;
    mNext = v28[1].m_BoundComponentHandles.mNode.mNext;
    if ( !mNext
      || !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))mNext->mPrev[1].mPrev)(mNext) )
    {
      return 0;
    }
    v30 = (_DWORD *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::qVector3 *))mNext->mPrev[10].mPrev)(
                      mNext,
                      &result);
    LODWORD(v31) = *v30 ^ _xmm[0];
    LODWORD(v32) = v30[1] ^ _xmm[0];
    LODWORD(v33) = v30[2] ^ _xmm[0];
    v34 = ((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, char *))mNext->mPrev[7].mNext)(
            mNext,
            v57);
    matSimObject.v0.x = v31;
    matSimObject.v0.y = v32;
    matSimObject.v0.z = v33;
    matSimObject.v0.w = 0.0;
    v35 = (float)(v33 * UFG::qVector3::msDirUp.y) - (float)(v32 * UFG::qVector3::msDirUp.z);
    v36 = (float)(v31 * UFG::qVector3::msDirUp.z) - (float)(v33 * UFG::qVector3::msDirUp.x);
    v37 = (float)(v32 * UFG::qVector3::msDirUp.x) - (float)(v31 * UFG::qVector3::msDirUp.y);
    v38 = (float)((float)(v36 * v36) + (float)(v35 * v35)) + (float)(v37 * v37);
    v39 = v38 == 0.0 ? 0.0 : 1.0 / fsqrt(v38);
    matSimObject.v1.w = 0.0;
    matSimObject.v1.x = v35 * v39;
    matSimObject.v1.z = v37 * v39;
    matSimObject.v1.y = v36 * v39;
    v40 = (float)((float)(v37 * v39) * v32) - (float)((float)(v36 * v39) * v33);
    v41 = (float)((float)(v36 * v39) * v31) - (float)((float)(v35 * v39) * v32);
    v42 = (float)((float)(v35 * v39) * v33) - (float)((float)(v37 * v39) * v31);
    v43 = (float)((float)(v42 * v42) + (float)(v40 * v40)) + (float)(v41 * v41);
    v44 = v43 == 0.0 ? 0.0 : 1.0 / fsqrt(v43);
    matSimObject.v2.w = 0.0;
    matSimObject.v2.x = v40 * v44;
    matSimObject.v2.y = v42 * v44;
    matSimObject.v2.z = v41 * v44;
    v45 = *(float *)(v34 + 8);
    v46 = *(float *)v34;
    matSimObject.v3.y = *(float *)(v34 + 4);
    matSimObject.v3.z = v45;
    matSimObject.v3.w = 1.0;
    matSimObject.v3.x = v46;
    UFG::TargetingSystemBaseComponent::FindMatrix(v15, &v55);
  }
  else
  {
    v47 = context->mSimObject.m_pPointer;
    v48 = 0i64;
    if ( v47 )
      v48 = v47->m_pTransformNodeComponent;
    UFG::TargetingSystemBaseComponent::FindMatrix(v48, v47, &matSimObject);
    UFG::TargetingSystemBaseComponent::FindMatrix(v15, &v55);
  }
  y_low = (__m128)LODWORD(v55.v3.y);
  v1.z = 0.0;
  v1.y = v55.v3.y - matSimObject.v3.y;
  v1.x = v55.v3.x - matSimObject.v3.x;
  y_low.m128_f32[0] = (float)(v1.y * v1.y) + (float)(v1.x * v1.x);
  if ( _mm_sqrt_ps(y_low).m128_f32[0] < 0.000099999997 )
    return 0;
  v50 = UFG::qAngleBetween(&v1, (UFG::qVector3 *)&matSimObject);
  if ( (float)((float)((float)(matSimObject.v1.y * v1.y) + (float)(matSimObject.v1.x * v1.x))
             + (float)(matSimObject.v1.z * v1.z)) > 0.0 )
    v50 = 6.2831855 - v50;
  v51 = v50 - this->mDirection;
  if ( v51 < 0.0 )
    v51 = v51 + 6.2831855;
  if ( v51 >= 3.1415927 )
    v51 = 6.2831855 - v51;
  return v51 <= this->mAngleRange;
}

// File Line: 5354
// RVA: 0x148C290
__int64 dynamic_initializer_for__TargetConditionGroup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetConditionGroup", 0xFFFFFFFF);
  TargetConditionGroup::sClassNameUID = result;
  return result;
}

// File Line: 5361
// RVA: 0x2789A0
void __fastcall TargetConditionGroup::TargetConditionGroup(TargetConditionGroup *this)
{
  char *v2; // rax
  char *v3; // rbx
  UFG::qOffset64<ConditionGroup *> *p_mConditions; // rax

  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetConditionGroup::`vftable;
  this->mTargetType.mValue = 0;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, "TargetConditionGroup.mConditions", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    Condition::Condition((Condition *)v2);
    *(_QWORD *)v3 = &ConditionGroup::`vftable;
    *((_QWORD *)v3 + 3) = -1i64;
    *((_DWORD *)v3 + 8) = 0;
    *((_QWORD *)v3 + 5) = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  p_mConditions = &this->mConditions;
  if ( v3 )
    v3 -= (__int64)p_mConditions;
  p_mConditions->mOffset = (__int64)v3;
}

// File Line: 5385
// RVA: 0x27AFC0
Expression::IMemberMap *__fastcall TargetConditionGroup::CreateClone(TargetConditionGroup *this)
{
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  char *v5; // rdi
  __int64 v6; // rax
  __int64 mOffset; // rax
  char *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  char *v11; // rcx
  __int64 v12; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "TargetConditionGroup::CreateClone", 0i64, 1u);
  if ( v2 )
  {
    TargetConditionGroup::TargetConditionGroup((TargetConditionGroup *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = (char *)(v4 + 24);
  v6 = *(_QWORD *)(v4 + 24);
  if ( v6 && &v5[v6] )
    (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)&v5[v6] + 8i64))(&v5[v6], 1i64);
  *(_QWORD *)(v4 + 8) = this->mResourceOwner;
  *(_DWORD *)(v4 + 16) = this->mPad0;
  *(_WORD *)(v4 + 20) = this->mPad1;
  *(_BYTE *)(v4 + 22) = this->mPad2;
  *(_BYTE *)(v4 + 23) = this->mBreakPoint;
  mOffset = this->mConditions.mOffset;
  if ( mOffset && (v8 = (char *)&this->mConditions + mOffset) != 0i64 )
    v9 = v8 - v5;
  else
    v9 = 0i64;
  *(_QWORD *)v5 = v9;
  *(_BYTE *)(v4 + 32) = this->mTargetType.mValue;
  v10 = this->mConditions.mOffset;
  if ( v10 )
    v11 = (char *)&this->mConditions + v10;
  else
    v11 = 0i64;
  v12 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v11 + 16i64))(v11);
  if ( v12 )
    *(_QWORD *)v5 = v12 - (_QWORD)v5;
  else
    *(_QWORD *)v5 = 0i64;
  return (Expression::IMemberMap *)v4;
}

// File Line: 5426
// RVA: 0x28BC90
UFG::SimObject *__fastcall TargetConditionGroup::Match(TargetConditionGroup *this, ActionContext *context)
{
  UFG::SimObject *result; // rax
  UFG::SimObjectGame *v5; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  ActionNodeRoot *v8; // rdi
  __int64 mValue; // rax
  __int64 v10; // rdx
  UFG::ActionTreeComponentBase *v11; // rcx
  UFG::ActionTreeComponentBase *v12; // r8
  UEL::ParametersBase *v13; // rdi
  __int16 v14; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 mOffset; // rax
  char *v17; // rcx
  unsigned __int8 v18; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  ActionContext pContext; // [rsp+30h] [rbp-C8h] BYREF
  ActionContext *p_pContext; // [rsp+118h] [rbp+20h]

  result = UFG::getTarget(context, (UFG::eTargetTypeEnum)(unsigned __int8)this->mTargetType.mValue);
  v5 = (UFG::SimObjectGame *)result;
  if ( result )
  {
    ActionContext::ActionContext(&pContext, (UFG::eActionTreeType)context->m_ActionTreeType.mValue, result);
    m_Flags = v5->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v5->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = v5->m_Components.p[6].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v5, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = v5->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
    {
      ActionContext::operator=(&pContext, (ActionContext *)m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
      pContext.m_ActionTreeType.mValue = context->m_ActionTreeType.mValue;
      v8 = (ActionNodeRoot *)context->m_OpeningBranch->vfptr[1].GetResourceOwner(context->m_OpeningBranch);
      mValue = v8->mActionTreeType.mValue;
      v10 = *(_QWORD *)&pContext.mMostUsedPlayCount[8 * mValue - 32];
      v11 = pContext.mActionTreeComponentBase[0];
      v12 = pContext.mActionTreeComponentBase[0];
      if ( v10 )
        v12 = *(UFG::ActionTreeComponentBase **)&pContext.mMostUsedPlayCount[8 * mValue - 32];
      if ( v12 )
      {
        if ( v10 )
          v11 = *(UFG::ActionTreeComponentBase **)&pContext.mMostUsedPlayCount[8 * mValue - 32];
        if ( UFG::ActionTreeComponentBase::AllocateFor(v11, v8) )
          ActionNodeRoot::Init(v8, &pContext);
      }
      v13 = UEL::gCurrentParameters;
      v14 = v5->m_Flags;
      if ( (v14 & 0x4000) != 0 )
      {
        ComponentOfTypeHK = v5->m_Components.p->m_pComponent;
      }
      else if ( v14 >= 0 )
      {
        if ( (v14 & 0x2000) != 0 )
        {
          ComponentOfTypeHK = v5->m_Components.p->m_pComponent;
        }
        else if ( (v14 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::UELComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v5, UFG::UELComponent::_TypeUID);
        }
      }
      else
      {
        ComponentOfTypeHK = v5->m_Components.p->m_pComponent;
      }
      if ( ComponentOfTypeHK )
        UEL::gCurrentParameters = (UEL::ParametersBase *)&ComponentOfTypeHK[1].m_TypeUID;
      else
        UEL::gCurrentParameters = 0i64;
      mOffset = this->mConditions.mOffset;
      if ( mOffset )
        v17 = (char *)&this->mConditions + mOffset;
      else
        v17 = 0i64;
      v18 = (*(__int64 (__fastcall **)(char *, ActionContext *))(*(_QWORD *)v17 + 80i64))(v17, &pContext);
      UEL::gCurrentParameters = v13;
    }
    else
    {
      v18 = 0;
    }
    p_pContext = &pContext;
    if ( pContext.mSimObject.m_pPointer )
    {
      mPrev = pContext.mSimObject.mPrev;
      mNext = pContext.mSimObject.mNext;
      pContext.mSimObject.mPrev->mNext = pContext.mSimObject.mNext;
      mNext->mPrev = mPrev;
      pContext.mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&pContext;
      pContext.mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&pContext;
    }
    v21 = pContext.mSimObject.mPrev;
    v22 = pContext.mSimObject.mNext;
    pContext.mSimObject.mPrev->mNext = pContext.mSimObject.mNext;
    v22->mPrev = v21;
    return (UFG::SimObject *)v18;
  }
  return result;
}

// File Line: 5508
// RVA: 0x294140
void __fastcall TargetConditionGroup::ResolveReferences(TargetConditionGroup *this, ActionNode *parent)
{
  __int64 mOffset; // rax

  mOffset = this->mConditions.mOffset;
  if ( mOffset )
    (*(void (__fastcall **)(char *, ActionNode *))(*(__int64 *)((char *)&this->mConditions.mOffset + mOffset) + 120))(
      (char *)&this->mConditions + mOffset,
      parent);
  else
    (*(void (__fastcall **)(_QWORD, ActionNode *))(MEMORY[0] + 120))(0i64, parent);
}

// File Line: 5513
// RVA: 0x294240
void __fastcall TargetConditionGroup::Serialize(TargetConditionGroup *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  char *v4; // rbx
  const char *v5; // rax

  mOffset = this->mConditions.mOffset;
  if ( mOffset )
  {
    v4 = (char *)&this->mConditions + mOffset;
    if ( v4 )
    {
      v5 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 32i64))(v4);
      serializer->vfptr->_PushObjectToSerialize(
        serializer,
        v4,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        v5,
        PRIORITY_MEDIUM,
        0,
        0i64,
        -1u,
        0i64);
    }
  }
}

// File Line: 5542
// RVA: 0x148BB90
__int64 dynamic_initializer_for__ParkourHandleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ParkourHandleCondition", 0xFFFFFFFF);
  ParkourHandleCondition::sClassNameUID = result;
  return result;
}

// File Line: 5608
// RVA: 0x277D90
void __fastcall ParkourHandleCondition::ParkourHandleCondition(ParkourHandleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleCondition::`vftable;
  this->mDirection = 0.0;
  *(_QWORD *)&this->mRelativeAngle = 1061752795i64;
  *(_QWORD *)&this->mDistanceXYMax = 0i64;
  *(_QWORD *)&this->mDistanceZMax = 0i64;
  *(_QWORD *)&this->mMinDropoffHeight = 0x40000000i64;
  *(_QWORD *)&this->mUseAimingDirection = 0x1000000i64;
  *(_DWORD *)&this->mCheckWall = 0;
  *(_QWORD *)&this->mCheckActionHijackClimb = 0x1000000i64;
  this->mInEqualityOperator.mValue = 1;
  *(_WORD *)&this->mCheckLeft = 0;
  this->mCheckAttachedToVehicleType = 0;
  this->mParentNode.mOffset = 0i64;
}

// File Line: 5682
// RVA: 0x294480
void __fastcall compareParkourHandles(
        __int16 checkTypes,
        UFG::qVector3 *position,
        UFG::qVector3 *orientation,
        float relativeAngle,
        float bufferZone,
        float distanceXYMin,
        float distanceXYMax,
        const float distanceZMin,
        const float distanceZMax,
        UFG::qVector3 *contactPosition,
        UFG::ParkourHandle *currentHandle,
        UFG::ParkourHandle **closestParkHandle,
        float *currentDistanceTo,
        bool *currentInSegment)
{
  UFG::ParkourHandle *v17; // r14
  __int16 Flags; // ax
  char v19; // si
  float v20; // xmm13_4
  float v21; // xmm14_4
  float v22; // xmm11_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float x; // xmm7_4
  bool v26; // r12
  float v27; // xmm7_4
  float v28; // xmm15_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  UFG::ParkourHandle *m_pPointer; // rcx
  float v33; // xmm2_4
  __m128 x_low; // xmm12
  int v35; // xmm14_4
  float v36; // xmm11_4
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  __m128 v39; // xmm9
  __int64 v40; // xmm10_8
  float v41; // xmm13_4
  float v42; // xmm10_4
  double v43; // xmm0_8
  double v44; // xmm0_8
  float v45; // xmm12_4
  __m128 z_low; // xmm3
  __m128 v47; // xmm2
  float v48; // xmm1_4
  float v49; // xmm12_4
  float v50; // xmm3_4
  float v51; // xmm5_4
  __m128 v52; // xmm4
  float v53; // xmm6_4
  float v54; // xmm3_4
  float v55; // xmm4_4
  bool v56; // al
  bool v57; // cl
  Render::DebugDrawContext *Context; // r13
  float v59; // xmm5_4
  float v60; // xmm12_4
  float v61; // xmm14_4
  __m128 v62; // xmm1
  float v63; // xmm1_4
  double v64; // xmm0_8
  double v65; // xmm0_8
  float v66; // xmm0_4
  UFG::qVector3 *v67; // rax
  UFG::qVector3 dest; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 p1; // [rsp+50h] [rbp-B0h] BYREF
  float v70; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 result; // [rsp+68h] [rbp-98h] BYREF
  UFG::qVector3 axis; // [rsp+78h] [rbp-88h] BYREF
  float v73; // [rsp+88h] [rbp-78h]
  float v74; // [rsp+8Ch] [rbp-74h]
  float v75; // [rsp+90h] [rbp-70h]
  float v76; // [rsp+94h] [rbp-6Ch]
  int v77; // [rsp+98h] [rbp-68h]
  UFG::qVector3 positiona; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qVector3 out; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v80; // [rsp+C0h] [rbp-40h]
  float halfLength; // [rsp+1B0h] [rbp+B0h] BYREF
  float radians; // [rsp+1C8h] [rbp+C8h]

  radians = relativeAngle;
  v80 = -2i64;
  v17 = currentHandle;
  Flags = UFG::ParkourHandle::GetFlags(currentHandle);
  v19 = Flags;
  if ( ((checkTypes & 4) == 0 || (Flags & 1) == 0)
    && ((checkTypes & 8) == 0 || (Flags & 4) == 0)
    && ((checkTypes & 0x10) == 0 || (Flags & 8) == 0)
    && ((checkTypes & 2) == 0 || (Flags & 2) == 0)
    && ((checkTypes & 0x20) == 0 || (Flags & 0x10) == 0)
    && ((checkTypes & 0x40) == 0 || (Flags & 0x20) == 0)
    && ((checkTypes & 0x80u) == 0 || (Flags & 2) == 0)
    && ((checkTypes & 0x100) == 0 || (Flags & 0x100) == 0)
    && ((checkTypes & 0x200) == 0 || (Flags & 0x40) == 0)
    || (checkTypes & 0x400) != 0 && UFG::ParkourHandle::IsAttachedToVehicle(v17) )
  {
    return;
  }
  halfLength = 0.0;
  UFG::ParkourHandle::GetLayout(v17, &positiona, &axis, &halfLength);
  v70 = halfLength * 2.0;
  v20 = axis.z * halfLength;
  v21 = axis.y * halfLength;
  v22 = axis.x * halfLength;
  v73 = positiona.z - (float)(axis.z * halfLength);
  v74 = positiona.y - (float)(axis.y * halfLength);
  v75 = positiona.x - (float)(axis.x * halfLength);
  v23 = position->z - v73;
  v24 = position->y - v74;
  x = position->x;
  p1.x = v75;
  p1.y = v74;
  p1.z = v73;
  v26 = 0;
  v27 = (float)((float)((float)(x - v75) * axis.x) + (float)(axis.y * v24)) + (float)(axis.z * v23);
  v28 = FLOAT_N1_0;
  v29 = halfLength * 2.0;
  if ( v27 >= 0.0 )
  {
    if ( v27 <= v29 )
    {
      v26 = 1;
      p1.x = (float)(axis.x * v27) + v75;
      p1.y = (float)(axis.y * v27) + v74;
      p1.z = (float)(axis.z * v27) + v73;
      goto LABEL_38;
    }
    goto LABEL_25;
  }
  if ( v27 > v29 )
  {
LABEL_25:
    v30 = positiona.z + v20;
    v31 = positiona.y + v21;
    p1.x = v22 + positiona.x;
    m_pPointer = v17->mCachedLeftNeighbor.m_pPointer;
    goto LABEL_28;
  }
  if ( v27 >= 0.0 )
    goto LABEL_37;
  v30 = positiona.z - v20;
  v31 = positiona.y - v21;
  p1.x = positiona.x - v22;
  m_pPointer = v17->mCachedRightNeighbor.m_pPointer;
LABEL_28:
  p1.z = v30;
  p1.y = v31;
  if ( !m_pPointer )
    goto LABEL_37;
  if ( (_S10_1 & 1) == 0 )
  {
    _S10_1 |= 1u;
    kfMaxNeighborAngleDiff = FLOAT_0_34906587;
  }
  UFG::ParkourHandle::GetAxis(m_pPointer, &result);
  v33 = (float)((float)(result.x * axis.x) + (float)(result.y * axis.y)) + (float)(result.z * axis.z);
  if ( v33 <= -1.0 )
  {
    v33 = FLOAT_N1_0;
  }
  else if ( v33 >= 1.0 )
  {
    v33 = *(float *)&FLOAT_1_0;
  }
  if ( acosf(v33) >= kfMaxNeighborAngleDiff )
  {
LABEL_37:
    if ( sInParkourSegmentOnly )
      return;
    goto LABEL_38;
  }
  v26 = 1;
LABEL_38:
  x_low = (__m128)LODWORD(p1.x);
  x_low.m128_f32[0] = p1.x - position->x;
  v70 = x_low.m128_f32[0];
  *(float *)&v35 = p1.y - position->y;
  v77 = v35;
  v36 = p1.z - position->z;
  if ( (float)(distanceZMin - 0.050000001) > v36 )
    return;
  if ( (float)(distanceZMax + 0.050000001) < v36 )
    return;
  v37 = x_low;
  v37.m128_f32[0] = x_low.m128_f32[0] * x_low.m128_f32[0];
  v38 = v37;
  v38.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(*(float *)&v35 * *(float *)&v35);
  v39 = _mm_sqrt_ps(v38);
  if ( v39.m128_f32[0] <= 0.000099999997 || distanceXYMin > v39.m128_f32[0] || distanceXYMax < v39.m128_f32[0] )
    return;
  v37.m128_f32[0] = v37.m128_f32[0] + (float)(*(float *)&v35 * *(float *)&v35);
  if ( v37.m128_f32[0] == 0.0 )
  {
    v40 = 0i64;
  }
  else
  {
    v40 = (unsigned int)FLOAT_1_0;
    *(float *)&v40 = 1.0 / _mm_sqrt_ps(v37).m128_f32[0];
  }
  v41 = *(float *)&v40 * x_low.m128_f32[0];
  *(float *)&v40 = *(float *)&v40 * *(float *)&v35;
  HIDWORD(v43) = HIDWORD(v40);
  *(float *)&v43 = (float)(v41 * orientation->x) + (float)(*(float *)&v40 * orientation->y);
  v44 = UFG::qACos(v43);
  v76 = *(float *)&v44;
  if ( radians < *(float *)&v44 )
  {
    if ( bufferZone <= 0.0 )
      return;
    UFG::qRotateVectorZ(&result, orientation, radians);
    UFG::qRotateVectorZ(&dest, orientation, COERCE_FLOAT(LODWORD(radians) ^ _xmm[0]));
    z_low = (__m128)LODWORD(result.z);
    v45 = (float)(result.y * UFG::qVector3::msDirUp.z) - (float)(result.z * UFG::qVector3::msDirUp.y);
    z_low.m128_f32[0] = (float)(result.z * UFG::qVector3::msDirUp.x) - (float)(result.x * UFG::qVector3::msDirUp.z);
    v47 = z_low;
    v47.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v45 * v45))
                    + (float)((float)((float)(result.x * UFG::qVector3::msDirUp.y)
                                    - (float)(result.y * UFG::qVector3::msDirUp.x))
                            * (float)((float)(result.x * UFG::qVector3::msDirUp.y)
                                    - (float)(result.y * UFG::qVector3::msDirUp.x)));
    v48 = v47.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v47).m128_f32[0];
    v49 = v45 * v48;
    v50 = z_low.m128_f32[0] * v48;
    v51 = (float)(dest.z * UFG::qVector3::msDirUp.y) - (float)(dest.y * UFG::qVector3::msDirUp.z);
    v52 = (__m128)LODWORD(dest.x);
    v52.m128_f32[0] = (float)(dest.x * UFG::qVector3::msDirUp.z) - (float)(dest.z * UFG::qVector3::msDirUp.x);
    v53 = (float)((float)((float)(v52.m128_f32[0] * v52.m128_f32[0]) + (float)(v51 * v51))
                + (float)((float)((float)(dest.y * UFG::qVector3::msDirUp.x) - (float)(dest.x * UFG::qVector3::msDirUp.y))
                        * (float)((float)(dest.y * UFG::qVector3::msDirUp.x) - (float)(dest.x * UFG::qVector3::msDirUp.y)))) == 0.0
        ? 0.0
        : 1.0 / _mm_sqrt_ps(v52).m128_f32[0];
    v54 = (float)(v50 * v42) + (float)(v49 * v41);
    v55 = (float)((float)(v52.m128_f32[0] * v53) * v42) + (float)((float)(v51 * v53) * v41);
    v56 = (float)((float)(result.y * v42) + (float)(result.x * v41)) > 0.0 && v54 > 0.0 && v54 < bufferZone;
    v57 = (float)((float)(dest.y * v42) + (float)(dest.x * v41)) > 0.0 && v55 > 0.0 && v55 < bufferZone;
    if ( !v57 && !v56 )
      return;
    x_low.m128_f32[0] = v70;
    v35 = v77;
    v28 = FLOAT_N1_0;
  }
  if ( gDebugPark && v26 )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawLine(
      Context,
      position,
      &p1,
      &UFG::qColour::Yellow,
      &UFG::qMatrix44::msIdentity,
      0i64,
      0);
    dest.x = position->x + orientation->x;
    dest.y = position->y + orientation->y;
    dest.z = orientation->z + position->z;
    Render::DebugDrawContext::DrawLine(
      Context,
      position,
      &dest,
      &UFG::qColour::Green,
      &UFG::qMatrix44::msIdentity,
      0i64,
      0);
    dest.x = x_low.m128_f32[0] + position->x;
    dest.y = *(float *)&v35 + position->y;
    dest.z = position->z;
    Render::DebugDrawContext::DrawLine(
      Context,
      position,
      &dest,
      &UFG::qColour::Red,
      &UFG::qMatrix44::msIdentity,
      0i64,
      0);
    result.x = p1.x;
    result.y = p1.y;
    result.z = position->z;
    Render::DebugDrawContext::DrawLine(Context, &result, &p1, &UFG::qColour::Blue, &UFG::qMatrix44::msIdentity, 0i64, 0);
    v59 = p1.z - position->z;
    dest.x = p1.x - (float)((float)(v59 * UFG::qVector3::msAxisZ.x) * 0.5);
    dest.y = p1.y - (float)((float)(v59 * UFG::qVector3::msAxisZ.y) * 0.5);
    dest.z = p1.z - (float)((float)(v59 * UFG::qVector3::msAxisZ.z) * 0.5);
    Render::DebugDrawContext::DrawText(Context, &dest, &UFG::qColour::Blue, "distZ:%0.3f", v59);
    v60 = x_low.m128_f32[0] * 0.5;
    v61 = *(float *)&v35 * 0.5;
    dest.x = v60 + position->x;
    dest.y = v61 + position->y;
    dest.z = position->z;
    Render::DebugDrawContext::DrawText(Context, &dest, &UFG::qColour::Red, "distXY:%0.3f", v39.m128_f32[0]);
    dest.x = v60 + position->x;
    dest.y = v61 + position->y;
    dest.z = (float)(v36 * 0.5) + position->z;
    v62 = v39;
    v62.m128_f32[0] = (float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v36 * v36);
    Render::DebugDrawContext::DrawText(
      Context,
      &dest,
      &UFG::qColour::Yellow,
      "dist:%0.3f",
      _mm_sqrt_ps(v62).m128_f32[0]);
    v63 = (float)(v76 * 180.0) * 0.31830987;
    if ( (float)((float)(v42 * orientation->x) + (float)(v41 * orientation->y)) < 0.0 )
      v63 = 360.0 - v63;
    Render::DebugDrawContext::DrawText(Context, &result, &UFG::qColour::Green, "Dir:%0.3f", v63);
  }
  if ( (checkTypes & 0x80u) != 0 && (v19 & 2) != 0 )
  {
    orientation->x = orientation->x * v28;
    orientation->y = orientation->y * v28;
    orientation->z = orientation->z * v28;
  }
  if ( !UFG::ParkourHandle::GetNormal(v17, &out)
    || (*(_QWORD *)&v64 = LODWORD(out.x),
        *(float *)&v64 = (float)(out.x * orientation->x) + (float)(out.y * orientation->y),
        v65 = UFG::qACos(v64),
        *(float *)&v65 > (float)(3.1415927 - radians)) )
  {
    v39.m128_f32[0] = (float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v36 * v36);
    LODWORD(v66) = _mm_sqrt_ps(v39).m128_u32[0];
    if ( v26 && v66 < *currentDistanceTo )
    {
      *currentDistanceTo = v66;
      *closestParkHandle = v17;
      *currentInSegment = v26;
      v67 = contactPosition;
      if ( contactPosition )
      {
        contactPosition->x = (float)(axis.x * v27) + v75;
        v67->y = (float)(axis.y * v27) + v74;
        v67->z = (float)(axis.z * v27) + v73;
      }
    }
  }
}

// File Line: 6020
// RVA: 0x294F40
void __fastcall getParkourEdgeConstraints(
        UFG::ParkourHandle *pParkourHandle,
        const bool constrainLeftEdge,
        const bool constrainRightEdge,
        float fDistToLeft,
        float fDistToRight,
        float *fLeftConstraint,
        float *fRightConstraint)
{
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4

  v9 = fDistToLeft;
  if ( constrainLeftEdge || constrainRightEdge )
  {
    v10 = fDistToRight;
    v11 = UFG::ParkourHandle::GetHalfLength(pParkourHandle) * 2.0;
    if ( constrainLeftEdge )
    {
      if ( constrainRightEdge )
      {
        if ( (float)(fDistToLeft + fDistToRight) > v11 )
        {
          v12 = fDistToLeft / (float)(fDistToLeft + fDistToRight);
          v9 = v12 * v11;
          v10 = (float)(1.0 - v12) * v11;
        }
      }
      else if ( fDistToLeft > v11 )
      {
        v9 = v11;
      }
    }
    else
    {
      if ( constrainRightEdge && fDistToRight > v11 )
        v10 = v11;
      v9 = 0.0;
    }
    *fLeftConstraint = v9;
    if ( !constrainRightEdge )
      v10 = 0.0;
    *fRightConstraint = v10;
  }
}

// File Line: 6087
// RVA: 0x27B370
UFG::ParkourHandle *__fastcall ParkourHandleCondition::FindClosestParkourHandle(
        UFG::SensorComponent *sensor_component,
        UFG::qVector3 *position,
        UFG::qVector3 *orientationVector,
        float relativeAngle,
        float bufferZone,
        float distanceXYMin,
        float distanceXYMax,
        float distanceZMin,
        float distanceZMax,
        UFG::eSimObjectVehicleTypeEnum checkAttachedToVehicleType,
        unsigned int check,
        UFG::qVector3 *contactPosition,
        bool debugMessageActive)
{
  UFG::ParkourHandle *v16; // rbx
  UFG::SimObject *m_pSimObject; // rax
  unsigned int v18; // r14d
  __int64 v19; // rdi
  bool v20; // r15
  UFG::qVector3 *v21; // r12
  UFG::eSimObjectVehicleTypeEnum v22; // esi
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm8_4
  float v26; // xmm9_4
  float v27; // xmm10_4
  UFG::ParkourHandle *v28; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectVehiclePropertiesComponent *ComponentOfTypeHK; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v35; // [rsp+80h] [rbp-48E8h] BYREF
  UFG::ParkourHandle *v36; // [rsp+88h] [rbp-48E0h] BYREF
  UFG::qVector3 v37; // [rsp+90h] [rbp-48D8h] BYREF
  __int64 v38; // [rsp+A0h] [rbp-48C8h]
  UFG::qVector3 vmax; // [rsp+A8h] [rbp-48C0h] BYREF
  UFG::qVector3 vmin; // [rsp+B8h] [rbp-48B0h] BYREF
  UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> out; // [rsp+D0h] [rbp-4898h] BYREF
  bool v42; // [rsp+4970h] [rbp+8h] BYREF

  v38 = -2i64;
  v16 = 0i64;
  v36 = 0i64;
  v35 = FLOAT_3_4028235e38;
  if ( !sensor_component )
    return 0i64;
  m_pSimObject = sensor_component->m_pSimObject;
  if ( m_pSimObject )
  {
    if ( (m_pSimObject->m_Flags & 0x400) != 0 )
      return 0i64;
  }
  UFG::SensorComponent::GetExtents(sensor_component, &vmin, &vmax);
  v18 = check;
  if ( (check & 1) == 0 )
    return 0i64;
  `eh vector constructor iterator(
    out.p,
    0x18ui64,
    768,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  out.size = 0;
  UFG::SensorComponent::GetParkourHandles(sensor_component, &out);
  v19 = 0i64;
  if ( out.size )
  {
    v20 = debugMessageActive;
    v21 = contactPosition;
    v22 = checkAttachedToVehicleType;
    v23 = distanceZMax;
    v24 = distanceZMin;
    v25 = distanceXYMax;
    v26 = distanceXYMin;
    v27 = bufferZone;
    do
    {
      v28 = (UFG::ParkourHandle *)*((_QWORD *)&out.p[0].m_pPointer + 3 * v19);
      if ( v28 && UFG::ParkourHandle::IsEnabled(*(&out.p[0].m_pPointer + 3 * v19)) )
      {
        if ( v22 == eSIM_OBJ_VEHICLE_TYPE_INVALID
          || !UFG::ParkourHandle::IsAttachedToVehicle(v28)
          || (m_pPointer = (UFG::SimObjectCVBase *)v28->mSimObject.m_pPointer) == 0i64
          || ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
            ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(m_pPointer))
            : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                 m_pPointer,
                                                                                 UFG::SimObjectVehiclePropertiesComponent::_TypeUID))
            : (ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                 m_pPointer,
                                                                                 UFG::SimObjectVehiclePropertiesComponent::_TypeUID)),
              !ComponentOfTypeHK || ComponentOfTypeHK->m_eSimObjectVehicleType == v22) )
        {
          y = orientationVector->y;
          z = orientationVector->z;
          v37.x = orientationVector->x;
          v37.y = y;
          v37.z = z;
          compareParkourHandles(
            v18,
            position,
            &v37,
            relativeAngle,
            v27,
            v26,
            v25,
            v24,
            v23,
            v21,
            v28,
            &v36,
            &v35,
            &v42,
            v20);
        }
      }
      v19 = (unsigned int)(v19 + 1);
    }
    while ( (unsigned int)v19 < out.size );
    v16 = v36;
  }
  out.size = 0;
  `eh vector destructor iterator(
    out.p,
    0x18ui64,
    768,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  if ( v16 )
    return v16;
  else
    return 0i64;
}

// File Line: 6163
// RVA: 0x2869E0
char __fastcall ParkourHandleCondition::Match(ParkourHandleCondition *this, ActionContext *context)
{
  char v4; // r12
  UFG::SimObjectGame *m_pPointer; // rcx
  ActionNode *v6; // rsi
  UFG::SensorComponent *m_pComponent; // r15
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v10; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  __int16 v12; // dx
  UFG::SimObject *v13; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::SimObjectGame *v19; // rcx
  UFG::AimingBaseComponent *v20; // rax
  __int16 v21; // dx
  __m128 y_low; // xmm1
  float v23; // xmm5_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  int v27; // xmm1_4
  float x; // xmm2_4
  UFG::SimObjectCVBase *v29; // rcx
  UFG::AICharacterControllerBaseComponent *v30; // rax
  __int16 v31; // dx
  UFG::SimObjectGame *v32; // rcx
  __int16 v33; // dx
  UFG::SimComponent *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r14
  _DWORD *v36; // rax
  float v38; // edx
  int mCheckAttachedToVehicleType; // eax
  UFG::ParkourHandle *ClosestParkourHandle; // r14
  float v41; // xmm8_4
  __m128 x_low; // xmm2
  float v43; // xmm3_4
  float v44; // xmm9_4
  float v45; // xmm10_4
  float v46; // xmm3_4
  __m128 v47; // xmm4
  __m128 v48; // xmm5
  float v49; // xmm1_4
  float v50; // xmm5_4
  float v51; // xmm15_4
  __m128 v52; // xmm11
  __m128 v53; // xmm5
  float v54; // xmm0_4
  __m128 v55; // xmm5
  float v56; // xmm1_4
  float v57; // xmm11_4
  float v58; // xmm5_4
  __m128 v59; // xmm15
  __m128 v60; // xmm3
  float v61; // xmm3_4
  float v62; // xmm15_4
  float v63; // xmm2_4
  float v64; // xmm5_4
  float v65; // xmm8_4
  float v66; // xmm2_4
  float v67; // xmm0_4
  __m128 v68; // xmm4
  float v69; // xmm1_4
  float v70; // xmm4_4
  float v71; // xmm10_4
  float v72; // xmm11_4
  __m128 v73; // xmm3
  __m128 v74; // xmm4
  float v75; // xmm4_4
  float v76; // xmm1_4
  float v77; // xmm4_4
  float v78; // xmm9_4
  __m128 v79; // xmm2
  float v80; // xmm7_4
  Render::DebugDrawContext *v81; // r15
  float v82; // xmm5_4
  float v83; // xmm3_4
  float v84; // xmm0_4
  __int64 mOffset; // rax
  __int64 v86; // rax
  ActionNode *v87; // rcx
  float mDistanceXYMax; // xmm0_4
  char *String_DBG; // rax
  int mCount; // edx
  float v91; // xmm2_4
  UFG::SimObjectGame *v92; // rcx
  __int16 v93; // dx
  UFG::WorldContextComponent *v94; // rax
  __int64 v95; // rcx
  float v96; // xmm9_4
  float v97; // xmm11_4
  float v98; // xmm10_4
  float HalfLength; // xmm0_4
  UFG::qVector3 *Axis; // rax
  float v101; // xmm6_4
  float v102; // xmm7_4
  float v103; // xmm8_4
  UFG::qVector3 *Position; // rax
  float v105; // xmm9_4
  float v106; // xmm11_4
  float v107; // xmm10_4
  UFG::qVector3 *v108; // rax
  float v109; // xmm11_4
  float v110; // xmm0_4
  UFG::qVector3 dest; // [rsp+48h] [rbp-80h] BYREF
  UFG::qVector3 vAimDirection; // [rsp+58h] [rbp-70h] BYREF
  UFG::qVector3 p1; // [rsp+68h] [rbp-60h] BYREF
  float v114; // [rsp+74h] [rbp-54h]
  UFG::qVector3 v115; // [rsp+78h] [rbp-50h] BYREF
  ActionPath pathToPopulate; // [rsp+88h] [rbp-40h] BYREF
  UFG::qColour colour; // [rsp+98h] [rbp-30h] BYREF
  UFG::qMatrix44 v118; // [rsp+A8h] [rbp-20h] BYREF
  UFG::qMatrix44 local_world; // [rsp+E8h] [rbp+20h] BYREF
  UFG::qVector3 contactPosition; // [rsp+128h] [rbp+60h] BYREF
  __int64 v121; // [rsp+138h] [rbp+70h]
  float v122; // [rsp+230h] [rbp+168h]
  float v123; // [rsp+238h] [rbp+170h]

  v121 = -2i64;
  v4 = 0;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v6 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::SensorComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SensorComponent::_TypeUID);
      m_pComponent = (UFG::SensorComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v10 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v10 )
  {
    v12 = v10->m_Flags;
    if ( (v12 & 0x4000) != 0 || v12 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
    }
    else if ( (v12 & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
    }
    else if ( (v12 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v10,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              v10,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
  v13 = context->mSimObject.m_pPointer;
  if ( v13 )
    m_pTransformNodeComponent = v13->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( !m_pComponent || !ComponentOfType || !m_pTransformNodeComponent )
    return v4;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v115.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  v115.y = y;
  v115.z = z;
  v17 = m_pTransformNodeComponent->mWorldTransform.v0.y;
  v18 = m_pTransformNodeComponent->mWorldTransform.v0.z;
  vAimDirection.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  vAimDirection.y = v17;
  vAimDirection.z = v18;
  if ( this->mUseAimingDirection )
  {
    v19 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v19 )
    {
      v21 = v19->m_Flags;
      if ( (v21 & 0x4000) != 0 )
      {
        v20 = (UFG::AimingBaseComponent *)v19->m_Components.p[47].m_pComponent;
      }
      else if ( v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
      {
        v20 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v19,
                                            UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v20 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(v19, UFG::AimingBaseComponent::_TypeUID);
      }
    }
    else
    {
      v20 = 0i64;
    }
    UFG::AimingBaseComponent::GetAimDirection(v20, &vAimDirection, 0i64);
    vAimDirection.z = 0.0;
    y_low = (__m128)LODWORD(vAimDirection.y);
    y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(vAimDirection.x * vAimDirection.x);
    v23 = _mm_sqrt_ps(y_low).m128_f32[0];
    if ( v23 <= 0.001 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v24 = m_pTransformNodeComponent->mWorldTransform.v0.y;
      v25 = m_pTransformNodeComponent->mWorldTransform.v0.z;
      p1.z = m_pTransformNodeComponent->mWorldTransform.v0.x;
      v114 = v24;
      v115.x = v25;
    }
    else
    {
      p1.z = (float)(1.0 / v23) * vAimDirection.x;
      v114 = (float)(1.0 / v23) * vAimDirection.y;
      v115.x = (float)(1.0 / v23) * 0.0;
    }
    v26 = p1.z;
    v27 = LODWORD(v114);
    x = v115.x;
  }
  else if ( this->mUseMotionIntention )
  {
    v29 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
    if ( v29 )
    {
      v31 = v29->m_Flags;
      if ( (v31 & 0x4000) != 0 || v31 < 0 )
      {
        v30 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v29);
      }
      else if ( (v31 & 0x2000) != 0 || (v31 & 0x1000) != 0 )
      {
        v30 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v29,
                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v30 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                           v29,
                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v30 = 0i64;
    }
    v26 = v30->m_Intention.mMotionIntentionDirection.x;
    v27 = LODWORD(v30->m_Intention.mMotionIntentionDirection.y);
    x = v30->m_Intention.mMotionIntentionDirection.z;
  }
  else
  {
    if ( !this->mUseCoverDirection )
      goto LABEL_71;
    v32 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v32
      && ((v33 = v32->m_Flags, (v33 & 0x4000) == 0) && v33 >= 0 && (v33 & 0x2000) == 0 && (v33 & 0x1000) == 0
        ? (v34 = UFG::SimObject::GetComponentOfType(v32, UFG::AICoverComponent::_TypeUID))
        : (v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v32, UFG::AICoverComponent::_TypeUID)),
          v34) )
    {
      mPrev = v34[1].m_BoundComponentHandles.mNode.mPrev;
    }
    else
    {
      mPrev = 0i64;
    }
    if ( !mPrev
      || !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))mPrev->mPrev[1].mPrev)(mPrev) )
    {
      return 0;
    }
    v36 = (_DWORD *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::qVector3 *))mPrev->mPrev[10].mPrev)(
                      mPrev,
                      &p1);
    LODWORD(x) = v36[2] ^ _xmm[0];
    v27 = v36[1] ^ _xmm[0];
    LODWORD(v26) = *v36 ^ _xmm[0];
  }
  vAimDirection.x = v26;
  LODWORD(vAimDirection.y) = v27;
  vAimDirection.z = x;
LABEL_71:
  UFG::qRotateVectorZ(&dest, &vAimDirection, this->mDirection);
  LODWORD(v38) = (this->mCheckLedgeDropoff != 0 ? 0x80 : 0) | (this->mCheckParkourHandle != 0) | (this->mCheckLedge != 0
                                                                                                ? 2
                                                                                                : 0) | (this->mCheckFence != 0 ? 4 : 0) | (this->mCheckVault != 0 ? 8 : 0) | (this->mCheckRail != 0 ? 0x10 : 0) | (this->mCheckWall != 0 ? 0x20 : 0) | (this->mCheckLeap != 0 ? 0x40 : 0) | (this->mCheckActionHijackClimb != 0 ? 0x100 : 0) | (this->mCheckCover != 0 ? 0x200 : 0) | (this->mCheckNotVehicle != 0 ? 0x400 : 0);
  mCheckAttachedToVehicleType = this->mCheckAttachedToVehicleType;
  LOBYTE(vAimDirection.z) = 0;
  *(_QWORD *)&vAimDirection.x = &contactPosition;
  dest.z = v38;
  LODWORD(dest.x) = mCheckAttachedToVehicleType;
  ClosestParkourHandle = ParkourHandleCondition::FindClosestParkourHandle(
                           m_pComponent,
                           &v115,
                           &dest,
                           this->mRelativeAngle,
                           this->mBufferZone,
                           this->mDistanceXYMin,
                           this->mDistanceXYMax,
                           this->mDistanceZMin,
                           this->mDistanceZMax,
                           (UFG::eSimObjectVehicleTypeEnum)mCheckAttachedToVehicleType,
                           LODWORD(v38),
                           &contactPosition,
                           0);
  if ( !UFG::WorldContextComponent::s_DrawParkourSensing )
    goto LABEL_113;
  if ( UFG::WorldContextComponent::s_DrawParkourSensingSuccessFilter )
  {
    if ( !ClosestParkourHandle )
      return v4;
  }
  else if ( UFG::WorldContextComponent::s_DrawParkourSensingSuccessFilter )
  {
    goto LABEL_113;
  }
  colour.r = 1.0;
  *(_QWORD *)&colour.g = 1065353216i64;
  colour.a = 0.5;
  pathToPopulate.mPath.mCount = 0;
  *((float *)&pathToPopulate.mPath.mCount + 1) = FLOAT_0_55000001;
  pathToPopulate.mPath.mData.mOffset = 0x3F00000000000000i64;
  if ( ClosestParkourHandle )
    colour = (UFG::qColour)pathToPopulate;
  v41 = (float)(sVertFudge + this->mDistanceZMin) + v115.z;
  x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( x_low.m128_f32[0] == 0.0 )
    v43 = 0.0;
  else
    v43 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
  v44 = v43 * UFG::qVector3::msDirUp.z;
  v45 = v43 * UFG::qVector3::msDirUp.y;
  v46 = v43 * UFG::qVector3::msDirUp.x;
  local_world.v0.x = v46;
  local_world.v0.y = v45;
  local_world.v0.z = v44;
  local_world.v0.w = 0.0;
  v47 = (__m128)LODWORD(dest.x);
  v47.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(dest.y * dest.y))
                  + (float)(dest.z * dest.z);
  if ( v47.m128_f32[0] == 0.0 )
  {
    v48 = 0i64;
  }
  else
  {
    v48 = (__m128)(unsigned int)FLOAT_1_0;
    v48.m128_f32[0] = 1.0 / _mm_sqrt_ps(v47).m128_f32[0];
  }
  v49 = v48.m128_f32[0] * dest.z;
  v52 = v48;
  v52.m128_f32[0] = v48.m128_f32[0] * dest.y;
  v50 = v48.m128_f32[0] * dest.x;
  v51 = (float)(v45 * v50) - (float)(v52.m128_f32[0] * v46);
  v123 = v51;
  v122 = (float)(v49 * v46) - (float)(v44 * v50);
  v52.m128_f32[0] = (float)(v52.m128_f32[0] * v44) - (float)(v49 * v45);
  v53 = v52;
  v53.m128_f32[0] = (float)((float)(v52.m128_f32[0] * v52.m128_f32[0]) + (float)(v122 * v122)) + (float)(v51 * v51);
  if ( v53.m128_f32[0] == 0.0 )
  {
    v55 = 0i64;
  }
  else
  {
    v54 = _mm_sqrt_ps(v53).m128_f32[0];
    v55 = (__m128)(unsigned int)FLOAT_1_0;
    v55.m128_f32[0] = 1.0 / v54;
  }
  v59 = v55;
  v56 = v55.m128_f32[0] * v122;
  local_world.v1.x = v55.m128_f32[0] * v52.m128_f32[0];
  local_world.v1.y = v55.m128_f32[0] * v122;
  local_world.v1.z = v55.m128_f32[0] * v123;
  local_world.v1.w = 0.0;
  v57 = (float)((float)(v55.m128_f32[0] * v122) * v46) - (float)((float)(v55.m128_f32[0] * v52.m128_f32[0]) * v45);
  v58 = (float)(local_world.v1.x * v44) - (float)((float)(v55.m128_f32[0] * v123) * v46);
  v59.m128_f32[0] = (float)(local_world.v1.z * v45) - (float)(v56 * v44);
  v60 = v59;
  v60.m128_f32[0] = (float)((float)(v59.m128_f32[0] * v59.m128_f32[0]) + (float)(v58 * v58)) + (float)(v57 * v57);
  if ( v60.m128_f32[0] == 0.0 )
    v61 = 0.0;
  else
    v61 = 1.0 / _mm_sqrt_ps(v60).m128_f32[0];
  local_world.v2.x = v61 * v59.m128_f32[0];
  local_world.v2.y = v61 * v58;
  local_world.v2.z = v61 * v57;
  local_world.v2.w = 0.0;
  local_world.v3.x = v115.x;
  local_world.v3.y = v115.y;
  local_world.v3.z = v41;
  local_world.v3.w = 1.0;
  v62 = (float)(sVertFudge + this->mDistanceZMax) + v115.z;
  if ( x_low.m128_f32[0] == 0.0 )
    v63 = 0.0;
  else
    v63 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
  v64 = v63 * UFG::qVector3::msDirUp.z;
  v65 = v63 * UFG::qVector3::msDirUp.y;
  v66 = v63 * UFG::qVector3::msDirUp.x;
  v118.v0.x = v66;
  v118.v0.y = v65;
  v118.v0.z = v64;
  v118.v0.w = 0.0;
  if ( v47.m128_f32[0] == 0.0 )
  {
    v68 = 0i64;
  }
  else
  {
    v67 = _mm_sqrt_ps(v47).m128_f32[0];
    v68 = (__m128)(unsigned int)FLOAT_1_0;
    v68.m128_f32[0] = 1.0 / v67;
  }
  v69 = v68.m128_f32[0] * dest.z;
  v73 = v68;
  v73.m128_f32[0] = v68.m128_f32[0] * dest.y;
  v70 = v68.m128_f32[0] * dest.x;
  v71 = (float)(v65 * v70) - (float)(v73.m128_f32[0] * v66);
  v72 = (float)(v69 * v66) - (float)(v64 * v70);
  v73.m128_f32[0] = (float)(v73.m128_f32[0] * v64) - (float)(v69 * v65);
  v74 = v73;
  v74.m128_f32[0] = (float)((float)(v73.m128_f32[0] * v73.m128_f32[0]) + (float)(v72 * v72)) + (float)(v71 * v71);
  if ( v74.m128_f32[0] == 0.0 )
    v75 = 0.0;
  else
    v75 = 1.0 / _mm_sqrt_ps(v74).m128_f32[0];
  v76 = v75 * v72;
  v118.v1.x = v73.m128_f32[0] * v75;
  v118.v1.y = v75 * v72;
  v118.v1.z = v75 * v71;
  v118.v1.w = 0.0;
  v77 = (float)((float)(v75 * v72) * v66) - (float)((float)(v73.m128_f32[0] * v75) * v65);
  v73.m128_f32[0] = (float)(v118.v1.x * v64) - (float)(v118.v1.z * v66);
  v78 = (float)(v118.v1.z * v65) - (float)(v76 * v64);
  v79 = v73;
  v79.m128_f32[0] = (float)((float)(v73.m128_f32[0] * v73.m128_f32[0]) + (float)(v78 * v78)) + (float)(v77 * v77);
  if ( v79.m128_f32[0] == 0.0 )
    v80 = 0.0;
  else
    v80 = 1.0 / _mm_sqrt_ps(v79).m128_f32[0];
  v118.v2.x = v80 * v78;
  v118.v2.y = v80 * v73.m128_f32[0];
  v118.v2.z = v80 * v77;
  v118.v2.w = 0.0;
  v118.v3.x = v115.x;
  v118.v3.y = v115.y;
  v118.v3.z = v62;
  v118.v3.w = 1.0;
  v81 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawContext::DrawArc(
    v81,
    this->mDistanceXYMax,
    COERCE_FLOAT(LODWORD(this->mRelativeAngle) ^ _xmm[0]),
    this->mRelativeAngle,
    &colour,
    &local_world,
    0i64);
  Render::DebugDrawContext::DrawArc(
    v81,
    this->mDistanceXYMax,
    COERCE_FLOAT(LODWORD(this->mRelativeAngle) ^ _xmm[0]),
    this->mRelativeAngle,
    &colour,
    &v118,
    0i64);
  v82 = (float)(sVertFudge + this->mDistanceZMin) + v115.z;
  p1.z = v115.x;
  v114 = v115.y;
  v115.x = v82;
  v83 = (float)(this->mDistanceXYMax * dest.z) + v82;
  v84 = (float)(this->mDistanceXYMax * dest.y) + v115.y;
  p1.x = (float)(this->mDistanceXYMax * dest.x) + p1.z;
  p1.y = v84;
  p1.z = v83;
  Render::DebugDrawContext::DrawLine(
    v81,
    (UFG::qVector3 *)&p1.z,
    &p1,
    &UFG::qColour::Blue,
    &UFG::qMatrix44::msIdentity,
    0i64,
    0);
  mOffset = this->mParentNode.mOffset;
  if ( mOffset && (UFG::qOffset64<ActionNode *> *)((char *)&this->mParentNode + mOffset) )
  {
    pathToPopulate.mPath.mCount = 0;
    pathToPopulate.mPath.mData.mOffset = 0i64;
    v86 = this->mParentNode.mOffset;
    if ( v86 )
      v87 = (ActionNode *)((char *)&this->mParentNode + v86);
    else
      v87 = 0i64;
    ActionNode::GetNameFullPath(v87, &pathToPopulate);
    mDistanceXYMax = this->mDistanceXYMax;
    p1.x = (float)(mDistanceXYMax * dest.x) + p1.z;
    p1.y = (float)(mDistanceXYMax * dest.y) + v114;
    p1.z = (float)(mDistanceXYMax * dest.z) + v115.x;
    String_DBG = ActionPath::GetString_DBG(&pathToPopulate);
    Render::DebugDrawContext::DrawText(v81, &p1, &colour, "match:%s", String_DBG);
    mCount = pathToPopulate.mPath.mCount;
    if ( pathToPopulate.mPath.mCount >= 0 )
    {
      if ( pathToPopulate.mPath.mData.mOffset
        && (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
        mCount = pathToPopulate.mPath.mCount;
      }
      pathToPopulate.mPath.mData.mOffset = 0i64;
      pathToPopulate.mPath.mCount = mCount & 0x80000000;
    }
  }
  else
  {
    v91 = this->mDistanceXYMax;
    p1.x = (float)(v91 * dest.x) + p1.z;
    p1.y = (float)(v91 * dest.y) + v114;
    p1.z = (float)(v91 * dest.z) + v115.x;
    Render::DebugDrawContext::DrawText(v81, &p1, &colour, "match:NULL NODE");
  }
LABEL_113:
  if ( ClosestParkourHandle )
  {
    if ( !this->mCheckLedgeDropoff
      || UFG::ParkourHandle::GetDropoffDistance(ClosestParkourHandle, &contactPosition, this->mDropoffCastRadius) >= this->mMinDropoffHeight )
    {
      v92 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v92 )
      {
        v93 = v92->m_Flags;
        if ( (v93 & 0x4000) != 0 )
          v94 = (UFG::WorldContextComponent *)v92->m_Components.p[28].m_pComponent;
        else
          v94 = (UFG::WorldContextComponent *)(v93 < 0 || (v93 & 0x2000) != 0 || (v93 & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v92,
                                                 UFG::WorldContextComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v92,
                                                 UFG::WorldContextComponent::_TypeUID));
        if ( v94 && this->mSetFocusHandle )
        {
          v95 = this->mParentNode.mOffset;
          if ( v95 )
            v6 = (ActionNode *)((char *)&this->mParentNode + v95);
          UFG::WorldContextComponent::SetFocusParkourHandle(v94, ClosestParkourHandle, v6);
        }
      }
      v4 = 1;
      if ( this->mCheckDistance )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v96 = m_pTransformNodeComponent->mWorldTransform.v3.x;
        v97 = m_pTransformNodeComponent->mWorldTransform.v3.y;
        v98 = m_pTransformNodeComponent->mWorldTransform.v3.z;
        HalfLength = UFG::ParkourHandle::GetHalfLength(ClosestParkourHandle);
        Axis = UFG::ParkourHandle::GetAxis(ClosestParkourHandle, &p1);
        v101 = HalfLength * Axis->x;
        v102 = HalfLength * Axis->y;
        v103 = HalfLength * Axis->z;
        Position = UFG::ParkourHandle::GetPosition(ClosestParkourHandle, (UFG::qVector3 *)&p1.z);
        v105 = v96 - (float)(Position->x - v101);
        v106 = v97 - (float)(Position->y - v102);
        v107 = v98 - (float)(Position->z - v103);
        v108 = UFG::ParkourHandle::GetAxis(ClosestParkourHandle, &p1);
        v109 = (float)((float)(v106 * v108->y) + (float)(v105 * v108->x)) + (float)(v107 * v108->z);
        if ( this->mCheckLeft )
          v4 = CompareFloat((UFG::InEqualityOperator)this->mInEqualityOperator.mValue, this->mEdgeDistance, v109);
        if ( this->mCheckRight )
        {
          v110 = UFG::ParkourHandle::GetHalfLength(ClosestParkourHandle);
          return CompareFloat(
                   (UFG::InEqualityOperator)this->mInEqualityOperator.mValue,
                   this->mEdgeDistance,
                   COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v110 * 2.0) - v109) & _xmm));
        }
      }
      return v4;
    }
    return 0;
  }
  return v4;
}

// File Line: 6417
// RVA: 0x148BBB0
__int64 dynamic_initializer_for__ParkourHandleInfoCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ParkourHandleInfoCondition", 0xFFFFFFFF);
  ParkourHandleInfoCondition::sClassNameUID = result;
  return result;
}

// File Line: 6427
// RVA: 0x277E10
void __fastcall ParkourHandleInfoCondition::ParkourHandleInfoCondition(ParkourHandleInfoCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleInfoCondition::`vftable;
  *(_WORD *)&this->mCheckFocusHandle = 0;
  this->mCheckLowCover = 0;
}

// File Line: 6431
// RVA: 0x287860
char __fastcall ParkourHandleInfoCondition::Match(ParkourHandleInfoCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  UFG::ParkourHandle *v7; // rbx
  bool v8; // r14
  bool v9; // bp
  UFG::SimObject *v10; // rax
  char v11; // di
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float x; // xmm9_4
  float y; // xmm10_4
  float z; // xmm13_4
  float HalfLength; // xmm0_4
  float v17; // xmm11_4
  UFG::qVector3 *Axis; // rax
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  UFG::qVector3 *Position; // rax
  float v23; // xmm1_4
  float v24; // xmm7_4
  float v25; // xmm9_4
  UFG::qVector3 *v26; // rax
  float v27; // xmm10_4
  float v28; // xmm7_4
  bool v29; // cl
  bool v30; // al
  float v31; // xmm7_4
  UFG::qVector3 result; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qVector3 v34; // [rsp+2Ch] [rbp-9Ch] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = m_pPointer->m_Components.p[28].m_pComponent;
  else
    m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::WorldContextComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID);
  if ( !m_pComponent )
    return 0;
  v7 = this->mCheckFocusHandle
     ? (UFG::ParkourHandle *)m_pComponent[5].vfptr
     : *(UFG::ParkourHandle **)&m_pComponent[5].m_TypeUID;
  if ( !v7 )
    return 0;
  v8 = this->mCheckHighCover != 0;
  v9 = this->mCheckLowCover != 0;
  if ( !this->mCheckHighCover && !this->mCheckLowCover )
    return 0;
  v10 = pContext->mSimObject.m_pPointer;
  v11 = 0;
  m_pTransformNodeComponent = 0i64;
  if ( v10 )
    m_pTransformNodeComponent = v10->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  HalfLength = UFG::ParkourHandle::GetHalfLength(v7);
  v17 = HalfLength * 2.0;
  Axis = UFG::ParkourHandle::GetAxis(v7, &result);
  v19 = HalfLength * Axis->x;
  v20 = HalfLength * Axis->y;
  v21 = HalfLength * Axis->z;
  Position = UFG::ParkourHandle::GetPosition(v7, &v34);
  v23 = Position->y - v20;
  v24 = Position->z - v21;
  v25 = x - (float)(Position->x - v19);
  v26 = UFG::ParkourHandle::GetAxis(v7, &v34);
  v27 = (float)((float)((float)(y - v23) * v26->y) + (float)(v25 * v26->x)) + (float)((float)(z - v24) * v26->z);
  if ( v27 < 0.0 )
  {
    if ( v27 <= v17 )
      goto LABEL_24;
  }
  else if ( v27 <= v17 )
  {
    v24 = (float)(v27 * UFG::ParkourHandle::GetAxis(v7, &v34)->z) + v24;
    goto LABEL_24;
  }
  v28 = HalfLength * UFG::ParkourHandle::GetAxis(v7, &v34)->z;
  v24 = v28 + UFG::ParkourHandle::GetPosition(v7, &result)->z;
LABEL_24:
  v29 = 0;
  v30 = 0;
  v31 = v24 - z;
  if ( v8 && v31 > 1.6 )
    v29 = v31 < 6.0;
  if ( v9 && v31 > 0.5 )
    v30 = v31 < 1.6;
  if ( v29 || v30 )
    return 1;
  return v11;
}

// File Line: 6544
// RVA: 0x148BBD0
__int64 dynamic_initializer_for__ParkourHandleLatchedCloseToEdgeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ParkourHandleLatchedCloseToEdgeCondition", 0xFFFFFFFF);
  ParkourHandleLatchedCloseToEdgeCondition::sClassNameUID = result;
  return result;
}

// File Line: 6556
// RVA: 0x277E50
void __fastcall ParkourHandleLatchedCloseToEdgeCondition::ParkourHandleLatchedCloseToEdgeCondition(
        ParkourHandleLatchedCloseToEdgeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleLatchedCloseToEdgeCondition::`vftable;
  this->mEdgeDistance = 0.0;
  *(_WORD *)&this->mInEqualityOperator.mValue = 1;
  this->mCheckRight = 0;
}

// File Line: 6561
// RVA: 0x287B50
char __fastcall ParkourHandleLatchedCloseToEdgeCondition::Match(
        ParkourHandleLatchedCloseToEdgeCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  UFG::ParkourHandle *v7; // rdi
  UFG::SimObject *v8; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float x; // xmm9_4
  float y; // xmm11_4
  float z; // xmm10_4
  float HalfLength; // xmm0_4
  UFG::qVector3 *Axis; // rax
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  UFG::qVector3 *Position; // rax
  float v19; // xmm9_4
  float v20; // xmm11_4
  float v21; // xmm10_4
  UFG::qVector3 *v22; // rax
  float v23; // xmm11_4
  float v25; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-88h] BYREF
  UFG::qVector3 v27; // [rsp+2Ch] [rbp-7Ch] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = m_pPointer->m_Components.p[28].m_pComponent;
  else
    m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::WorldContextComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID);
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::ParkourHandle **)&m_pComponent[5].m_TypeUID;
  if ( !v7 )
    return 0;
  v8 = context->mSimObject.m_pPointer;
  if ( v8 )
    m_pTransformNodeComponent = v8->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  HalfLength = UFG::ParkourHandle::GetHalfLength(v7);
  Axis = UFG::ParkourHandle::GetAxis(v7, &result);
  v15 = HalfLength * Axis->x;
  v16 = HalfLength * Axis->y;
  v17 = HalfLength * Axis->z;
  Position = UFG::ParkourHandle::GetPosition(v7, &v27);
  v19 = x - (float)(Position->x - v15);
  v20 = y - (float)(Position->y - v16);
  v21 = z - (float)(Position->z - v17);
  v22 = UFG::ParkourHandle::GetAxis(v7, &v27);
  v23 = (float)((float)(v20 * v22->y) + (float)(v19 * v22->x)) + (float)(v21 * v22->z);
  if ( this->mCheckLeft )
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mEdgeDistance,
             v23);
  if ( !this->mCheckRight )
    return 0;
  v25 = UFG::ParkourHandle::GetHalfLength(v7);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mEdgeDistance,
           COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v25 * 2.0) - v23) & _xmm));
}

// File Line: 6608
// RVA: 0x148BBF0
__int64 dynamic_initializer_for__ParkourHandleOwnerIsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ParkourHandleOwnerIsCondition", 0xFFFFFFFF);
  ParkourHandleOwnerIsCondition::sClassNameUID = result;
  return result;
}

// File Line: 6614
// RVA: 0x277E90
void __fastcall ParkourHandleOwnerIsCondition::ParkourHandleOwnerIsCondition(ParkourHandleOwnerIsCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleOwnerIsCondition::`vftable;
  this->mSimObjectType = 0;
}

// File Line: 6618
// RVA: 0x287D70
bool __fastcall ParkourHandleOwnerIsCondition::Match(ParkourHandleOwnerIsCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  UFG::SimObjectGame *vecDelDtor; // rcx
  __int16 v8; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::WorldContextComponent::_TypeUID)))
          : (ComponentOfType = m_pPointer->m_Components.p[28].m_pComponent),
            ComponentOfType
         && (vfptr = ComponentOfType[5].vfptr) != 0i64
         && (vecDelDtor = (UFG::SimObjectGame *)vfptr[7].__vecDelDtor) != 0i64
         && ((v8 = vecDelDtor->m_Flags, (v8 & 0x4000) == 0)
           ? (v8 >= 0
            ? ((v8 & 0x2000) == 0
             ? ((v8 & 0x1000) == 0
              ? (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                       vecDelDtor,
                                       UFG::SimObjectPropertiesComponent::_TypeUID))
              : (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                       vecDelDtor,
                                       UFG::SimObjectPropertiesComponent::_TypeUID)),
                m_pComponent = ComponentOfTypeHK)
             : (m_pComponent = vecDelDtor->m_Components.p[4].m_pComponent))
            : (m_pComponent = vecDelDtor->m_Components.p[3].m_pComponent))
           : (m_pComponent = vecDelDtor->m_Components.p[3].m_pComponent),
             m_pComponent))
        && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == this->mSimObjectType;
  return result;
}

// File Line: 6662
// RVA: 0x148BC10
__int64 dynamic_initializer_for__ParkourHandleSpeedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ParkourHandleSpeedCondition", 0xFFFFFFFF);
  ParkourHandleSpeedCondition::sClassNameUID = result;
  return result;
}

// File Line: 6670
// RVA: 0x277ED0
void __fastcall ParkourHandleSpeedCondition::ParkourHandleSpeedCondition(ParkourHandleSpeedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleSpeedCondition::`vftable;
  this->mSpeedInEqualityOperator.mValue = 1;
  this->mSpeed = 0.0;
}

// File Line: 6674
// RVA: 0x287E90
char __fastcall ParkourHandleSpeedCondition::Match(ParkourHandleSpeedCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  float v4; // xmm6_4
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  void *(__fastcall *vecDelDtor)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rbx
  __int64 v9; // rbx
  __m128 v10; // xmm2

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0.0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[28].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::WorldContextComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      vfptr = m_pComponent[5].vfptr;
      if ( vfptr )
      {
        vecDelDtor = vfptr[7].__vecDelDtor;
        if ( vecDelDtor )
        {
          v9 = *((_QWORD *)vecDelDtor + 11);
          if ( v9 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
            v10 = (__m128)*(unsigned int *)(v9 + 260);
            v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0])
                                    + (float)(*(float *)(v9 + 256) * *(float *)(v9 + 256)))
                            + (float)(*(float *)(v9 + 264) * *(float *)(v9 + 264));
            LODWORD(v4) = _mm_sqrt_ps(v10).m128_u32[0];
          }
        }
      }
    }
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)this->mSpeedInEqualityOperator.mValue, this->mSpeed, v4);
}

// File Line: 6725
// RVA: 0x148BC30
__int64 dynamic_initializer_for__ParkourSphereCastCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ParkourSphereCastCondition", 0xFFFFFFFF);
  ParkourSphereCastCondition::sClassNameUID = result;
  return result;
}

// File Line: 6754
// RVA: 0x277F10
void __fastcall ParkourSphereCastCondition::ParkourSphereCastCondition(ParkourSphereCastCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&ParkourSphereCastCondition::`vftable;
  *(_QWORD *)&this->mStart.x = 1056964608i64;
  this->mStart.z = 1.0;
  *(_QWORD *)&this->mEnd.x = 1075838976i64;
  this->mEnd.z = 1.0;
  this->mCollisionLayer = 12;
  this->mRadius = 0.30000001;
  *(_QWORD *)&this->mEdgeDistance = 1053609165i64;
  this->mClipAtPlayer = 0;
}

// File Line: 6760
// RVA: 0x287FA0
char __fastcall ParkourSphereCastCondition::Match(ParkourSphereCastCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SensorComponent *m_pComponent; // r14
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::ParkourHandle *vfptr; // rdi
  UFG::SimObject *v12; // rbx
  float v13; // xmm6_4
  float v14; // xmm15_4
  float v15; // xmm14_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float mEdgeDistance; // xmm10_4
  bool v19; // r15
  bool v20; // r12
  float v21; // xmm0_4
  float v22; // xmm1_4
  float x; // xmm10_4
  float y; // xmm11_4
  float z; // xmm12_4
  float v26; // xmm2_4
  float v27; // xmm7_4
  float v28; // xmm8_4
  float v29; // xmm13_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm5_4
  __m128 vfptr_high; // xmm6
  __m128 v34; // xmm1
  float v35; // xmm2_4
  UFG::qVector3 *Axis; // rax
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm10_4
  float v40; // xmm15_4
  float v41; // xmm11_4
  __int128 x_low; // xmm12
  float v43; // xmm13_4
  float v44; // xmm0_4
  float v45; // xmm7_4
  float v46; // xmm6_4
  float v47; // xmm8_4
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm4_4
  float v51; // xmm7_4
  float v52; // xmm6_4
  __m128 v53; // xmm5
  __m128 v54; // xmm8
  float v55; // xmm14_4
  float v56; // xmm7_4
  float v57; // xmm6_4
  float v58; // xmm5_4
  float v59; // xmm2_4
  char v60; // di
  float v61; // xmm13_4
  float v62; // xmm11_4
  float v63; // xmm15_4
  __int64 i; // rsi
  unsigned __int64 v65; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v66; // rcx
  const char *TypeName; // rax
  float v69; // [rsp+40h] [rbp-88h]
  float v70; // [rsp+40h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+48h] [rbp-80h] BYREF
  UFG::qVector3 start; // [rsp+88h] [rbp-40h] BYREF
  float v73; // [rsp+94h] [rbp-34h]
  UFG::qMatrix44 d; // [rsp+98h] [rbp-30h] BYREF
  UFG::qReflectHandleBase v75; // [rsp+D8h] [rbp+10h] BYREF
  __int64 v76; // [rsp+100h] [rbp+38h]
  float v77; // [rsp+1F0h] [rbp+128h]
  float v78; // [rsp+1F8h] [rbp+130h]
  float v79; // [rsp+200h] [rbp+138h]

  v76 = -2i64;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::SensorComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SensorComponent::_TypeUID);
    m_pComponent = (UFG::SensorComponent *)v7;
  }
  else
  {
    m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    v10 = v8->m_Components.p[28].m_pComponent;
  else
    v10 = v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v8, UFG::WorldContextComponent::_TypeUID);
  if ( !v10 )
    return 0;
  vfptr = (UFG::ParkourHandle *)v10[5].vfptr;
  if ( !vfptr )
    return 0;
  v12 = context->mSimObject.m_pPointer;
  if ( v12 )
    v12 = (UFG::SimObject *)v12->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
  v77 = *(float *)v12[1].mNode.mChild;
  v13 = *((float *)v12[1].mNode.mChild + 1);
  v14 = *(float *)&v12[1].mNode.mChild[1];
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
  v79 = *(float *)&v12[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
  v78 = *((float *)&v12[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext
        + 1);
  v69 = *(float *)&v12[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
  UFG::ParkourHandle::GetEndpoints(vfptr, (UFG::qVector3 *)&result.v2, (UFG::qVector3 *)&result.v1);
  v15 = *(float *)&FLOAT_1_0;
  if ( sConstrianEndpoints )
  {
    v16 = 0.0;
    v17 = 0.0;
    mEdgeDistance = this->mEdgeDistance;
    v19 = this->mCheckRight != 0;
    v20 = this->mCheckLeft != 0;
    if ( this->mCheckLeft || this->mCheckRight )
    {
      v21 = UFG::ParkourHandle::GetHalfLength(vfptr) * 2.0;
      v16 = mEdgeDistance;
      v17 = mEdgeDistance;
      if ( v20 )
      {
        if ( v19 )
        {
          v22 = mEdgeDistance + mEdgeDistance;
          if ( (float)(mEdgeDistance + mEdgeDistance) > v21 )
          {
            v16 = (float)(mEdgeDistance / v22) * v21;
            v17 = (float)(1.0 - (float)(mEdgeDistance / v22)) * v21;
          }
        }
        else if ( mEdgeDistance > v21 )
        {
          v16 = v21;
        }
      }
      else
      {
        if ( v19 && mEdgeDistance > v21 )
          v17 = v21;
        v16 = 0.0;
      }
      if ( !v19 )
        v17 = 0.0;
    }
    UFG::ParkourHandle::GetAxis(vfptr, (UFG::qVector3 *)&result);
    x = (float)(result.v0.x * v16) + result.v2.x;
    y = (float)(result.v0.y * v16) + result.v2.y;
    z = (float)(result.v0.z * v16) + result.v2.z;
    result.v2.x = x;
    result.v2.y = y;
    result.v2.z = z;
    v26 = result.v0.z * v17;
    v27 = result.v1.x - (float)(result.v0.x * v17);
    v28 = result.v1.y - (float)(result.v0.y * v17);
    v29 = result.v1.z - v26;
    result.v1.x = v27;
    result.v1.y = v28;
    result.v1.z = result.v1.z - v26;
  }
  else
  {
    z = result.v2.z;
    y = result.v2.y;
    x = result.v2.x;
    v29 = result.v1.z;
    v28 = result.v1.y;
    v27 = result.v1.x;
  }
  v30 = (float)((float)((float)(v28 - y) * v78) + (float)((float)(v27 - x) * v79)) + (float)((float)(v29 - z) * v69);
  if ( COERCE_FLOAT(LODWORD(v30) & _xmm) <= 0.001 )
  {
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        (float)((float)((float)(y - v13) * v78) + (float)((float)(x - v77) * v79))
                      + (float)((float)(z - v14) * v69)) & _xmm) >= COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                                                   (float)((float)((float)(v28 - v13)
                                                                                                 * v78)
                                                                                         + (float)((float)(v27 - v77)
                                                                                                 * v79))
                                                                                 + (float)((float)(v29 - v14) * v69)) & _xmm) )
    {
      result.v3.x = v27;
      result.v3.y = v28;
      result.v3.z = v29;
    }
    else
    {
      result.v3.x = x;
      result.v3.y = y;
      result.v3.z = z;
    }
  }
  else
  {
    v31 = (float)((float)((float)((float)(v13 - y) * v78) + (float)((float)(v77 - x) * v79))
                + (float)((float)(v14 - z) * v69))
        / v30;
    if ( v31 >= 0.0 )
    {
      if ( v31 > 1.0 )
        v31 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v31 = 0.0;
    }
    result.v3.x = (float)((float)(v27 - x) * v31) + x;
    result.v3.y = (float)((float)(v28 - y) * v31) + y;
    result.v3.z = (float)((float)(v29 - z) * v31) + z;
  }
  result.v3.w = 1.0;
  result.v2 = (UFG::qVector4)_xmm;
  if ( this->mUsePlayerHeading )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    v32 = *(float *)&v12[1].vfptr;
    vfptr_high = (__m128)HIDWORD(v12[1].vfptr);
    v34 = vfptr_high;
    v34.m128_f32[0] = (float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0]) + (float)(v32 * v32);
    if ( v34.m128_f32[0] == 0.0 )
      v35 = 0.0;
    else
      v35 = 1.0 / _mm_sqrt_ps(v34).m128_f32[0];
    result.v0.x = v35 * v32;
    result.v0.y = v35 * vfptr_high.m128_f32[0];
    result.v0.z = v35 * 0.0;
    result.v0.w = 0.0;
    result.v1.x = (float)(result.v2.y * 0.0) - (float)(result.v2.z * vfptr_high.m128_f32[0]);
    result.v1.y = (float)(result.v2.z * v32) - (float)(result.v2.x * 0.0);
    result.v1.z = (float)(result.v2.x * vfptr_high.m128_f32[0]) - (float)(result.v2.y * v32);
  }
  else
  {
    UFG::ParkourHandle::GetNormal(vfptr, (UFG::qVector3 *)&result);
    result.v0.x = result.v0.x * -1.0;
    result.v0.y = result.v0.y * -1.0;
    result.v0.z = result.v0.z * -1.0;
    result.v0.w = FLOAT_N0_0;
    Axis = UFG::ParkourHandle::GetAxis(vfptr, &start);
    v37 = Axis->y;
    v38 = Axis->z;
    result.v1.x = Axis->x;
    result.v1.y = v37;
    result.v1.z = v38;
  }
  result.v1.w = 0.0;
  v39 = this->mStart.x;
  v77 = v39;
  v40 = this->mStart.y;
  v41 = this->mStart.z;
  v78 = v41;
  x_low = LODWORD(this->mEnd.x);
  v73 = this->mEnd.x;
  v43 = this->mEnd.y;
  v70 = v43;
  v44 = this->mEnd.z;
  v79 = v44;
  if ( this->mClipAtPlayer )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    v45 = *(float *)v12[1].mNode.mChild;
    v46 = *((float *)v12[1].mNode.mChild + 1);
    v47 = *(float *)&v12[1].mNode.mChild[1];
    UFG::qInverseAffine(&d, &result);
    v48 = (float)((float)((float)(d.v1.x * v46) + (float)(d.v0.x * v45)) + (float)(d.v2.x * v47)) + d.v3.x;
    v49 = (float)((float)((float)(d.v1.y * v46) + (float)(d.v0.y * v45)) + (float)(d.v2.y * v47)) + d.v3.y;
    v50 = (float)((float)((float)(d.v1.z * v46) + (float)(d.v0.z * v45)) + (float)(d.v2.z * v47)) + d.v3.z;
    v51 = v79 - v41;
    v52 = v43 - v40;
    v53 = (__m128)x_low;
    v53.m128_f32[0] = *(float *)&x_low - v39;
    v54 = v53;
    v54.m128_f32[0] = (float)((float)(v53.m128_f32[0] * v53.m128_f32[0]) + (float)(v52 * v52)) + (float)(v51 * v51);
    if ( v54.m128_f32[0] == 0.0 )
      v55 = 0.0;
    else
      v55 = 1.0 / _mm_sqrt_ps(v54).m128_f32[0];
    v56 = v51 * v55;
    v57 = v52 * v55;
    v58 = v53.m128_f32[0] * v55;
    v59 = (float)((float)((float)(v49 - v40) * v57) + (float)((float)(v48 - v39) * v58))
        + (float)((float)(v50 - v41) * v56);
    v41 = v41 + (float)(v56 * v59);
    v78 = v41;
    v40 = v40 + (float)(v57 * v59);
    v39 = v39 + (float)(v58 * v59);
    v77 = v39;
    v15 = FLOAT_2_0;
    v44 = v79;
  }
  v60 = 0;
  if ( this->mUseVaultThroughTags )
  {
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)&d,
      this->mRadius,
      this->mCollisionLayer,
      PhantomBehaviour_Simple);
    v61 = (float)((float)((float)(v40 * result.v1.x) + (float)(v39 * result.v0.x)) + (float)(v41 * result.v2.x))
        + (float)(v15 * result.v3.x);
    v62 = (float)((float)((float)(v40 * result.v1.y) + (float)(v77 * result.v0.y)) + (float)(v78 * result.v2.y))
        + (float)(v15 * result.v3.y);
    v63 = (float)((float)((float)(v40 * result.v1.z) + (float)(v77 * result.v0.z)) + (float)(v78 * result.v2.z))
        + (float)(v15 * result.v3.z);
    result.v0.x = (float)((float)((float)(result.v1.x * v70) + (float)(result.v0.x * v73)) + (float)(result.v2.x * v79))
                + result.v3.x;
    result.v0.y = (float)((float)((float)(result.v1.y * v70) + (float)(result.v0.y * v73)) + (float)(result.v2.y * v79))
                + result.v3.y;
    result.v0.z = (float)((float)((float)(result.v1.z * v70) + (float)(result.v0.z * v73)) + (float)(result.v2.z * v79))
                + result.v3.z;
    start.x = v61;
    start.y = v62;
    start.z = v63;
    if ( UFG::BasePhysicsSystem::CastShape(
           UFG::BasePhysicsSystem::mInstance,
           (UFG::ShapeCasterCollector *)&d,
           &start,
           (UFG::qVector3 *)&result) )
    {
      for ( i = *(_QWORD *)&d.v1.x; (UFG::qMatrix44 *)i != (UFG::qMatrix44 *)&d.v0.z; i = *(_QWORD *)(i + 8) )
      {
        if ( v60 )
          break;
        if ( *(_QWORD *)(i + 40) )
        {
          v65 = *(_QWORD *)(i + 88);
          UFG::qReflectHandleBase::qReflectHandleBase(&v75);
          TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v66);
          v75.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
          UFG::qReflectHandleBase::Init(&v75, v75.mTypeUID, v65);
          if ( v75.mData )
          {
            if ( LOBYTE(v75.mData[2].vfptr) )
              v60 = 1;
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v75);
        }
      }
    }
    UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&d);
  }
  else
  {
    LODWORD(start.x) = x_low;
    start.y = v43;
    start.z = v44;
    result.v0.x = v39;
    result.v0.y = v40;
    result.v0.z = v41;
    return UFG::SensorComponent::CastSphere(
             m_pComponent,
             &result,
             this->mRadius,
             this->mCollisionLayer,
             (UFG::qVector3 *)&result,
             &start,
             0i64);
  }
  return v60;
}

// File Line: 6988
// RVA: 0x148C1F0
__int64 dynamic_initializer_for__SphereCastCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SphereCastCondition", 0xFFFFFFFF);
  SphereCastCondition::sClassNameUID = result;
  return result;
}

// File Line: 7025
// RVA: 0x278810
void __fastcall SphereCastCondition::SphereCastCondition(SphereCastCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SphereCastCondition::`vftable;
  this->mRadius = 0.30000001;
  *(_QWORD *)&this->mStart.x = 1056964608i64;
  this->mStart.z = 1.0;
  *(_QWORD *)&this->mEnd.x = 1075838976i64;
  this->mEnd.z = 1.0;
  this->mAttachLimbName = UFG::gNullQSymbolUC;
  this->mCollisionLayer = 12;
  *(_WORD *)&this->mUseAimOrigin = 0;
  this->mToTarget.mValue = 0;
  this->mToTargetBone = UFG::gNullQSymbolUC;
  *(_WORD *)&this->mReturnTrueIfHitTarget = 0;
}

// File Line: 7034
// RVA: 0x1493C80
__int64 dynamic_initializer_for__symWorldSpace__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("WORLD_SPACE", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symWorldSpace, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symWorldSpace__);
}

// File Line: 7035
// RVA: 0x1493C40
__int64 dynamic_initializer_for__symLocalSpace__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("LOCAL_SPACE", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symLocalSpace, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symLocalSpace__);
}

// File Line: 7038
// RVA: 0x28A9F0
char __fastcall SphereCastCondition::Match(SphereCastCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimObject *trueIfHits; // r15
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::SensorComponent *m_pComponent; // r14
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  unsigned int mUID; // eax
  UFG::SimObjectCVBase *v23; // rcx
  __int16 v24; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  UFG::SimObjectGame *v28; // rcx
  __int16 v29; // dx
  UFG::AimingBaseComponent *v30; // rbx
  UFG::SimComponent *v31; // rax
  __m128 y_low; // xmm2
  __int128 v33; // xmm3
  __int128 v34; // xmm11
  float v35; // xmm4_4
  float v36; // xmm3_4
  __m128 x_low; // xmm10
  float v38; // xmm9_4
  float v39; // xmm8_4
  __m128 v40; // xmm2
  float v41; // xmm0_4
  __m128 v42; // xmm2
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm13_4
  float v46; // xmm14_4
  __m128 v47; // xmm5
  __m128 v48; // xmm2
  float v49; // xmm12_4
  float v50; // xmm1_4
  float v51; // xmm12_4
  __m128 v52; // xmm13
  float v53; // xmm4_4
  __m128 v54; // xmm2
  float v55; // xmm2_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float x; // xmm5_4
  float v59; // xmm11_4
  float v60; // xmm12_4
  UFG::SimObjectCVBase *v61; // rsi
  UFG::SimObjectGame *v62; // rcx
  UFG::SimComponent *v63; // r8
  __int16 v64; // dx
  UFG::SimComponent *v65; // rax
  unsigned int v66; // eax
  __int16 v67; // cx
  UFG::CharacterAnimationComponent *v68; // rax
  Creature *v69; // rbx
  int v70; // eax
  float v71; // xmm8_4
  float v72; // xmm9_4
  float v73; // xmm10_4
  UFG::TransformNodeComponent *v74; // rbx
  __m128 v75; // xmm1
  __int128 v76; // xmm2
  __int128 v77; // xmm13
  float v78; // xmm3_4
  float v79; // xmm2_4
  __m128 v80; // xmm4
  float v81; // xmm0_4
  __m128 v82; // xmm4
  __m128 v83; // xmm1
  float v84; // xmm14_4
  float v85; // xmm4_4
  float v86; // xmm9_4
  __m128 v87; // xmm8
  float v88; // xmm14_4
  __m128 v89; // xmm4
  float v90; // xmm4_4
  float v91; // xmm9_4
  __m128 v92; // xmm10
  float v93; // xmm3_4
  __m128 v94; // xmm2
  float v95; // xmm7_4
  UFG::SimObject *m_pSimObject; // rax
  char v97; // bl
  float v99; // xmm2_4
  float v100; // xmm5_4
  float v101; // xmm15_4
  float v102; // xmm13_4
  __int64 v103; // rax
  char v104; // bl
  UFG::qVector3 vAimDirection; // [rsp+40h] [rbp-88h] BYREF
  float v106; // [rsp+4Ch] [rbp-7Ch]
  UFG::qMatrix44 transform; // [rsp+50h] [rbp-78h] BYREF
  float v108; // [rsp+90h] [rbp-38h]
  float v109; // [rsp+98h] [rbp-30h]
  float v110; // [rsp+9Ch] [rbp-2Ch]
  float v111; // [rsp+A0h] [rbp-28h]
  __int64 v112; // [rsp+A8h] [rbp-20h]
  UFG::qMatrix44 v113; // [rsp+B8h] [rbp-10h] BYREF
  float v114; // [rsp+1E0h] [rbp+118h]
  float v115; // [rsp+1E8h] [rbp+120h]
  float v116; // [rsp+1F0h] [rbp+128h]

  v112 = -2i64;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  trueIfHits = 0i64;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::SensorComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SensorComponent::_TypeUID);
      m_pComponent = (UFG::SensorComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v0.y;
  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  w = m_pTransformNodeComponent->mWorldTransform.v0.w;
  transform.v0.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  transform.v0.y = y;
  transform.v0.z = z;
  transform.v0.w = w;
  v13 = m_pTransformNodeComponent->mWorldTransform.v1.y;
  v14 = m_pTransformNodeComponent->mWorldTransform.v1.z;
  v15 = m_pTransformNodeComponent->mWorldTransform.v1.w;
  transform.v1.x = m_pTransformNodeComponent->mWorldTransform.v1.x;
  transform.v1.y = v13;
  transform.v1.z = v14;
  transform.v1.w = v15;
  v16 = m_pTransformNodeComponent->mWorldTransform.v2.y;
  v17 = m_pTransformNodeComponent->mWorldTransform.v2.z;
  v18 = m_pTransformNodeComponent->mWorldTransform.v2.w;
  transform.v2.x = m_pTransformNodeComponent->mWorldTransform.v2.x;
  transform.v2.y = v16;
  transform.v2.z = v17;
  transform.v2.w = v18;
  v19 = m_pTransformNodeComponent->mWorldTransform.v3.y;
  v20 = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v21 = m_pTransformNodeComponent->mWorldTransform.v3.w;
  vAimDirection.z = m_pTransformNodeComponent->mWorldTransform.v3.x;
  v106 = v19;
  transform.v0.x = v20;
  transform.v0.y = v21;
  mUID = this->mAttachLimbName.mUID;
  if ( mUID != -1
    && mUID != symWorldSpace.mUID
    && mUID != symLocalSpace.mUID
    && (v23 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer) != 0i64
    && ((v24 = v23->m_Flags, (v24 & 0x4000) != 0) || v24 < 0
      ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v23))
      : (v24 & 0x2000) == 0
      ? ((v24 & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v23,
                                                                  UFG::CharacterAnimationComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v23,
                                                                  UFG::CharacterAnimationComponent::_TypeUID)))
      : (ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v23)),
        ComponentOfType
     && (mCreature = ComponentOfType->mCreature) != 0i64
     && mCreature->mPose.mRigHandle.mData
     && (BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, this->mAttachLimbName.mUID), BoneID >= 0)) )
  {
    Creature::GetTransform(mCreature, BoneID, &transform);
  }
  else if ( this->mUseAimOrigin )
  {
    v28 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v28 )
    {
      v29 = v28->m_Flags;
      if ( (v29 & 0x4000) != 0 )
      {
        v30 = (UFG::AimingBaseComponent *)v28->m_Components.p[47].m_pComponent;
      }
      else
      {
        v31 = v29 < 0 || (v29 & 0x2000) != 0 || (v29 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::AimingBaseComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v28, UFG::AimingBaseComponent::_TypeUID);
        v30 = (UFG::AimingBaseComponent *)v31;
      }
      if ( v30 )
      {
        UFG::AimingBaseComponent::GetAimDirection(v30, &vAimDirection, 0i64);
        y_low = (__m128)LODWORD(vAimDirection.y);
        y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                                  + (float)(vAimDirection.x * vAimDirection.x))
                          + (float)(vAimDirection.z * vAimDirection.z);
        if ( y_low.m128_f32[0] == 0.0 )
        {
          v33 = 0i64;
        }
        else
        {
          v33 = (unsigned int)FLOAT_1_0;
          *(float *)&v33 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
        }
        v34 = v33;
        *(float *)&v34 = *(float *)&v33 * vAimDirection.z;
        v35 = *(float *)&v33 * vAimDirection.y;
        v36 = *(float *)&v33 * vAimDirection.x;
        transform.v0.x = v36;
        transform.v0.y = v35;
        LODWORD(transform.v0.z) = v34;
        transform.v0.w = 0.0;
        x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        v40 = x_low;
        v38 = UFG::qVector3::msDirUp.y;
        v39 = UFG::qVector3::msDirUp.z;
        v40.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v38 * v38))
                        + (float)(v39 * v39);
        if ( v40.m128_f32[0] == 0.0 )
        {
          v42 = 0i64;
        }
        else
        {
          v41 = _mm_sqrt_ps(v40).m128_f32[0];
          v42 = (__m128)(unsigned int)FLOAT_1_0;
          v42.m128_f32[0] = 1.0 / v41;
        }
        v43 = v42.m128_f32[0] * UFG::qVector3::msDirUp.z;
        v47 = v42;
        v47.m128_f32[0] = v42.m128_f32[0] * UFG::qVector3::msDirUp.y;
        v44 = v42.m128_f32[0] * UFG::qVector3::msDirUp.x;
        v45 = (float)(v35 * v44) - (float)(v47.m128_f32[0] * v36);
        v46 = (float)(v43 * v36) - (float)(*(float *)&v34 * v44);
        v47.m128_f32[0] = (float)(v47.m128_f32[0] * *(float *)&v34) - (float)(v43 * v35);
        v48 = v47;
        v48.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v46 * v46)) + (float)(v45 * v45);
        if ( v48.m128_f32[0] == 0.0 )
          v49 = 0.0;
        else
          v49 = 1.0 / _mm_sqrt_ps(v48).m128_f32[0];
        v50 = v49 * v46;
        transform.v1.x = v47.m128_f32[0] * v49;
        transform.v1.y = v49 * v46;
        transform.v1.z = v49 * v45;
        transform.v1.w = 0.0;
        v51 = (float)((float)(v49 * v46) * v36) - (float)(v35 * (float)(v47.m128_f32[0] * v49));
        v52 = (__m128)v34;
        v52.m128_f32[0] = (float)(*(float *)&v34 * transform.v1.x) - (float)(transform.v1.z * v36);
        v53 = (float)(v35 * transform.v1.z) - (float)(*(float *)&v34 * v50);
        v54 = v52;
        v54.m128_f32[0] = (float)((float)(v52.m128_f32[0] * v52.m128_f32[0]) + (float)(v53 * v53)) + (float)(v51 * v51);
        if ( v54.m128_f32[0] == 0.0 )
          v55 = 0.0;
        else
          v55 = 1.0 / _mm_sqrt_ps(v54).m128_f32[0];
        transform.v2.x = v55 * v53;
        transform.v2.y = v55 * v52.m128_f32[0];
        transform.v2.z = v55 * v51;
        transform.v2.w = 0.0;
        v56 = v30->m_vAimOriginPosition.y;
        v57 = v30->m_vAimOriginPosition.z;
        vAimDirection.z = v30->m_vAimOriginPosition.x;
        v106 = v56;
        transform.v0.x = v57;
        transform.v0.y = 1.0;
        goto LABEL_57;
      }
    }
  }
  x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v38 = UFG::qVector3::msDirUp.y;
  v39 = UFG::qVector3::msDirUp.z;
LABEL_57:
  x = this->mEnd.x;
  v116 = x;
  v59 = this->mEnd.y;
  v115 = v59;
  v60 = this->mEnd.z;
  transform.v0.z = v60;
  v61 = 0i64;
  if ( this->mToTarget.mValue < 2u )
    goto LABEL_88;
  v62 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v62 )
  {
    v64 = v62->m_Flags;
    if ( (v64 & 0x4000) != 0 )
    {
      v63 = v62->m_Components.p[20].m_pComponent;
    }
    else if ( v64 >= 0 )
    {
      if ( (v64 & 0x2000) != 0 || (v64 & 0x1000) != 0 )
        v65 = UFG::SimObjectGame::GetComponentOfTypeHK(v62, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v65 = UFG::SimObject::GetComponentOfType(v62, UFG::TargetingSystemBaseComponent::_TypeUID);
      v63 = v65;
    }
    else
    {
      v63 = v62->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v63 = 0i64;
  }
  v61 = *(UFG::SimObjectCVBase **)(56i64
                                 * *(unsigned __int8 *)(*(_QWORD *)&v63[1].m_Flags
                                                      + (unsigned __int8)this->mToTarget.mValue
                                                      + 8i64)
                                 + *(_QWORD *)&v63[1].m_TypeUID
                                 + 40);
  if ( !v61 )
    return 0;
  v66 = this->mToTargetBone.mUID;
  if ( v66 == -1 || v66 == symWorldSpace.mUID || v66 == symLocalSpace.mUID )
  {
    v74 = v61->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v74);
    v71 = v74->mWorldTransform.v3.x;
    v72 = v74->mWorldTransform.v3.y;
    v73 = v74->mWorldTransform.v3.z;
    goto LABEL_87;
  }
  v67 = v61->m_Flags;
  if ( (v67 & 0x4000) != 0 || v67 < 0 )
  {
    v68 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v61);
  }
  else if ( (v67 & 0x2000) != 0 )
  {
    v68 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v61);
  }
  else
  {
    v68 = (UFG::CharacterAnimationComponent *)((v67 & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v61,
                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v61,
                                                 UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v68 )
    return 0;
  v69 = v68->mCreature;
  if ( !v69 )
    return 0;
  if ( !v69->mPose.mRigHandle.mData )
    return 0;
  v70 = Skeleton::GetBoneID(v69->mPose.mRigHandle.mUFGSkeleton, this->mToTargetBone.mUID);
  if ( v70 < 0 )
    return 0;
  Creature::GetTransform(v69, v70, &v113);
  v71 = v113.v3.x;
  v72 = v113.v3.y;
  v73 = v113.v3.z;
LABEL_87:
  UFG::qInverseAffine((UFG::qMatrix44 *)&transform.v1.z, &transform);
  x = (float)((float)((float)(transform.v2.z * v72) + (float)(transform.v1.z * v71)) + (float)(transform.v3.z * v73))
    + v109;
  v116 = x;
  v59 = (float)((float)((float)(transform.v2.w * v72) + (float)(transform.v1.w * v71)) + (float)(transform.v3.w * v73))
      + v110;
  v115 = v59;
  v60 = (float)((float)((float)(transform.v3.x * v72) + (float)(transform.v2.x * v71)) + (float)(v108 * v73)) + v111;
  transform.v0.z = v60;
  v39 = UFG::qVector3::msDirUp.z;
  v38 = UFG::qVector3::msDirUp.y;
  x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
LABEL_88:
  if ( this->mMakeUpright )
  {
    v75 = (__m128)LODWORD(transform.v0.x);
    v75.m128_f32[0] = (float)(v75.m128_f32[0] * v75.m128_f32[0]) + (float)(transform.v0.y * transform.v0.y);
    if ( v75.m128_f32[0] == 0.0 )
    {
      v76 = 0i64;
    }
    else
    {
      v76 = (unsigned int)FLOAT_1_0;
      *(float *)&v76 = 1.0 / _mm_sqrt_ps(v75).m128_f32[0];
    }
    v77 = v76;
    *(float *)&v77 = *(float *)&v76 * 0.0;
    v78 = *(float *)&v76 * transform.v0.y;
    v79 = *(float *)&v76 * transform.v0.x;
    transform.v0.x = v79;
    transform.v0.y = v78;
    LODWORD(transform.v0.z) = v77;
    transform.v0.w = 0.0;
    v80 = x_low;
    v80.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v38 * v38)) + (float)(v39 * v39);
    if ( v80.m128_f32[0] == 0.0 )
    {
      v82 = 0i64;
    }
    else
    {
      v81 = _mm_sqrt_ps(v80).m128_f32[0];
      v82 = (__m128)(unsigned int)FLOAT_1_0;
      v82.m128_f32[0] = 1.0 / v81;
    }
    v83 = v82;
    v83.m128_f32[0] = v82.m128_f32[0] * v39;
    v84 = v82.m128_f32[0] * v38;
    v85 = v82.m128_f32[0] * x_low.m128_f32[0];
    v86 = (float)(v78 * v85) - (float)(v84 * v79);
    v87 = v83;
    v87.m128_f32[0] = (float)(v83.m128_f32[0] * v79) - (float)(*(float *)&v77 * v85);
    v88 = (float)(v84 * *(float *)&v77) - (float)(v83.m128_f32[0] * v78);
    v89 = v87;
    v89.m128_f32[0] = (float)((float)(v87.m128_f32[0] * v87.m128_f32[0]) + (float)(v88 * v88)) + (float)(v86 * v86);
    if ( v89.m128_f32[0] == 0.0 )
      v90 = 0.0;
    else
      v90 = 1.0 / _mm_sqrt_ps(v89).m128_f32[0];
    transform.v1.x = v90 * v88;
    transform.v1.y = v87.m128_f32[0] * v90;
    transform.v1.z = v90 * v86;
    transform.v1.w = 0.0;
    v91 = (float)((float)(v87.m128_f32[0] * v90) * v79) - (float)(v78 * (float)(v90 * v88));
    v92 = (__m128)v77;
    v92.m128_f32[0] = (float)(*(float *)&v77 * (float)(v90 * v88)) - (float)(transform.v1.z * v79);
    v93 = (float)(v78 * transform.v1.z) - (float)(*(float *)&v77 * (float)(v87.m128_f32[0] * v90));
    v94 = v92;
    v94.m128_f32[0] = (float)((float)(v92.m128_f32[0] * v92.m128_f32[0]) + (float)(v93 * v93)) + (float)(v91 * v91);
    if ( v94.m128_f32[0] == 0.0 )
      v95 = 0.0;
    else
      v95 = 1.0 / _mm_sqrt_ps(v94).m128_f32[0];
    transform.v2.x = v95 * v93;
    transform.v2.y = v95 * v92.m128_f32[0];
    transform.v2.z = v95 * v91;
    transform.v2.w = 0.0;
    transform.v0.y = 1.0;
  }
  if ( !m_pComponent || (m_pSimObject = m_pComponent->m_pSimObject) != 0i64 && (m_pSimObject->m_Flags & 0x400) != 0 )
  {
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)&transform.v1.z,
      this->mRadius,
      this->mCollisionLayer,
      PhantomBehaviour_Simple);
    v99 = this->mStart.y;
    v100 = this->mStart.z;
    v101 = (float)((float)((float)(v99 * transform.v1.x) + (float)(this->mStart.x * transform.v0.x))
                 + (float)(v100 * transform.v2.x))
         + vAimDirection.z;
    v102 = (float)((float)((float)(v99 * transform.v1.y) + (float)(this->mStart.x * transform.v0.y))
                 + (float)(v100 * transform.v2.y))
         + v106;
    v114 = this->mStart.x * transform.v0.z;
    v114 = v114 + (float)(v99 * transform.v1.z);
    vAimDirection.x = (float)((float)((float)(transform.v1.x * v115) + (float)(transform.v0.x * v116))
                            + (float)(transform.v2.x * transform.v0.z))
                    + vAimDirection.z;
    vAimDirection.y = (float)((float)((float)(transform.v1.y * v115) + (float)(transform.v0.y * v116))
                            + (float)(transform.v2.y * transform.v0.z))
                    + v106;
    vAimDirection.z = (float)((float)((float)(transform.v1.z * v115) + (float)(transform.v0.z * v116))
                            + (float)(transform.v2.z * transform.v0.z))
                    + transform.v0.x;
    transform.v0.w = v101;
    transform.v1.x = v102;
    transform.v1.y = (float)(v114 + (float)(v100 * transform.v2.z)) + transform.v0.x;
    if ( UFG::BasePhysicsSystem::CastShape(
           UFG::BasePhysicsSystem::mInstance,
           (UFG::ShapeCasterCollector *)&transform.v1.z,
           (UFG::qVector3 *)&transform.v0.w,
           &vAimDirection) )
    {
      if ( !this->mReturnTrueIfHitTarget )
      {
LABEL_114:
        v104 = 1;
LABEL_116:
        SphereCastCondition::AssignToTargetType(
          this,
          (UFG::SimObjectGame *)context->mSimObject.m_pPointer,
          (UFG::ShapeCasterCollector *)&transform.v1.z);
        UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&transform.v1.z);
        return v104;
      }
      v103 = *(_QWORD *)&transform.v2.z;
      if ( *(UFG::qMatrix44 **)&transform.v2.z != (UFG::qMatrix44 *)&transform.v2 )
      {
        while ( *(UFG::SimObjectCVBase **)(v103 + 80) != v61 )
        {
          v103 = *(_QWORD *)(v103 + 8);
          if ( (UFG::qVector4 *)v103 == &transform.v2 )
            goto LABEL_115;
        }
        goto LABEL_114;
      }
    }
LABEL_115:
    v104 = 0;
    goto LABEL_116;
  }
  vAimDirection.x = x;
  vAimDirection.y = v59;
  vAimDirection.z = v60;
  if ( this->mReturnTrueIfHitTarget )
    trueIfHits = v61;
  v97 = UFG::SensorComponent::CastSphere(
          m_pComponent,
          &transform,
          this->mRadius,
          this->mCollisionLayer,
          &this->mStart,
          &vAimDirection,
          trueIfHits);
  SphereCastCondition::AssignToTargetType(
    this,
    (UFG::SimObjectGame *)context->mSimObject.m_pPointer,
    m_pComponent->mSphereCaster);
  return v97;
}LABEL_116;
  }
  vAimDirection.x = x;
  vAimDirection.y = v59;
  vAimDirection.z = v60;
  if ( this->mReturnTrueIfHitTarget )
    trueIfHits = v61;
  v97 = UFG::SensorComponent::CastSphere(
          m_pComponent,
          &transform,
          this->mRadius,
          this->mCollisionLayer,
          &this->mStart,
          &vAimDirection,
          trueIfHits);
  SphereCastCondition::AssignToTargetType(
    this,
    (UFG::SimObjectGa

// File Line: 7200
// RVA: 0x27ABC0
void __fastcall SphereCastCondition::AssignToTargetType(
        SphereCastCondition *this,
        UFG::SimObjectGame *assignToSimObject,
        UFG::ShapeCasterCollector *collector)
{
  UFG::eTargetTypeEnum mValue; // edi
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mNext; // rax
  UFG::SimObject *mPrev; // rbx
  signed __int16 m_Flags; // cx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax

  mValue = (unsigned __int8)this->mAssignToTargetType.mValue;
  if ( this->mAssignToTargetType.mValue )
  {
    if ( collector )
    {
      if ( (UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *)collector->mHitList.mNode.mNext != &collector->mHitList )
      {
        mNext = collector->mHitList.mNode.mNext;
        if ( mNext )
        {
          mPrev = (UFG::SimObject *)mNext[5].mPrev;
          if ( mPrev )
          {
            if ( assignToSimObject )
            {
              m_Flags = assignToSimObject->m_Flags;
              if ( (m_Flags & 0x4000) != 0 )
              {
                m_pComponent = (UFG::TargetingSystemBaseComponent *)assignToSimObject->m_Components.p[20].m_pComponent;
              }
              else if ( m_Flags >= 0 )
              {
                if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                  m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        assignToSimObject,
                                                                        UFG::TargetingSystemBaseComponent::_TypeUID);
                else
                  m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                        assignToSimObject,
                                                                        UFG::TargetingSystemBaseComponent::_TypeUID);
              }
              else
              {
                m_pComponent = (UFG::TargetingSystemBaseComponent *)assignToSimObject->m_Components.p[20].m_pComponent;
              }
              if ( m_pComponent )
                UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, mValue, mPrev);
            }
          }
        }
      }
    }
  }
}

// File Line: 7247
// RVA: 0x148A9F0
__int64 dynamic_initializer_for__BrokenVehicleGlassSphereCastCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BrokenVehicleGlassSphereCastCondition", 0xFFFFFFFF);
  BrokenVehicleGlassSphereCastCondition::sClassNameUID = result;
  return result;
}

// File Line: 7281
// RVA: 0x276760
void __fastcall BrokenVehicleGlassSphereCastCondition::BrokenVehicleGlassSphereCastCondition(
        BrokenVehicleGlassSphereCastCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&BrokenVehicleGlassSphereCastCondition::`vftable;
  this->mRadius = 0.30000001;
  *(_QWORD *)&this->mStart.x = 1056964608i64;
  this->mStart.z = 1.0;
  *(_QWORD *)&this->mEnd.x = 1075838976i64;
  this->mEnd.z = 1.0;
  this->mAttachLimbName = UFG::gNullQSymbolUC;
  this->mCollisionLayer = 12;
  *(_WORD *)&this->mUseAimOrigin = 0;
  this->mToTarget.mValue = 0;
  this->mToTargetBone = UFG::gNullQSymbolUC;
  this->mReturnTrueIfHitTarget = 0;
}

// File Line: 7285
// RVA: 0x27EF80
char __fastcall BrokenVehicleGlassSphereCastCondition::Match(
        BrokenVehicleGlassSphereCastCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimObject *trueIfHits; // r15
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::SensorComponent *m_pComponent; // r14
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  unsigned int mUID; // eax
  UFG::SimObjectCVBase *v23; // rcx
  __int16 v24; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  UFG::SimObjectGame *v28; // rcx
  __int16 v29; // dx
  UFG::AimingBaseComponent *v30; // rbx
  UFG::SimComponent *v31; // rax
  __int128 z_low; // xmm5
  __m128 y_low; // xmm2
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  __m128 x_low; // xmm11
  float v38; // xmm10_4
  float v39; // xmm9_4
  __m128 v40; // xmm4
  __m128 v41; // xmm8
  float v42; // xmm1_4
  float v43; // xmm8_4
  float v44; // xmm13_4
  float v45; // xmm12_4
  __m128 v46; // xmm4
  __m128 v47; // xmm8
  float v48; // xmm1_4
  float v49; // xmm8_4
  __m128 v50; // xmm14
  float v51; // xmm3_4
  __m128 v52; // xmm2
  float v53; // xmm2_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float x; // xmm5_4
  float v57; // xmm8_4
  float v58; // xmm12_4
  UFG::SimObjectCVBase *v59; // rsi
  UFG::SimObjectGame *v60; // rcx
  UFG::SimComponent *v61; // r8
  __int16 v62; // dx
  UFG::SimComponent *v63; // rax
  unsigned int v64; // eax
  __int16 v65; // cx
  UFG::CharacterAnimationComponent *v66; // rax
  Creature *v67; // rbx
  int v68; // eax
  float v69; // xmm9_4
  float v70; // xmm10_4
  float v71; // xmm11_4
  UFG::TransformNodeComponent *v72; // rbx
  __m128 v73; // xmm1
  __int128 v74; // xmm2
  __int128 v75; // xmm13
  float v76; // xmm3_4
  float v77; // xmm2_4
  __m128 v78; // xmm4
  float v79; // xmm0_4
  __m128 v80; // xmm4
  __m128 v81; // xmm1
  float v82; // xmm14_4
  float v83; // xmm4_4
  float v84; // xmm10_4
  __m128 v85; // xmm9
  float v86; // xmm14_4
  __m128 v87; // xmm4
  float v88; // xmm1_4
  float v89; // xmm4_4
  __m128 v90; // xmm11
  float v91; // xmm3_4
  __m128 v92; // xmm2
  float v93; // xmm7_4
  char v94; // r12
  UFG::ShapeCasterCollector *mSphereCaster; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mNext; // rbx
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *p_mHitList; // rsi
  float v99; // xmm2_4
  float v100; // xmm5_4
  float v101; // xmm15_4
  float v102; // xmm13_4
  bool v103; // al
  __int64 v104; // rbx
  __int64 v105; // rax
  char v106; // al
  char v107; // si
  UFG::qVector3 vAimDirection; // [rsp+40h] [rbp-88h] BYREF
  float v109; // [rsp+4Ch] [rbp-7Ch]
  UFG::qMatrix44 transform; // [rsp+50h] [rbp-78h] BYREF
  float v111; // [rsp+90h] [rbp-38h]
  float v112; // [rsp+98h] [rbp-30h]
  float v113; // [rsp+9Ch] [rbp-2Ch]
  float v114; // [rsp+A0h] [rbp-28h]
  __int64 v115; // [rsp+A8h] [rbp-20h]
  UFG::qMatrix44 v116; // [rsp+B8h] [rbp-10h] BYREF
  float v117; // [rsp+1E0h] [rbp+118h]
  float v118; // [rsp+1E8h] [rbp+120h]
  float v119; // [rsp+1F0h] [rbp+128h]

  v115 = -2i64;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  trueIfHits = 0i64;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::SensorComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SensorComponent::_TypeUID);
      m_pComponent = (UFG::SensorComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::SensorComponent *)m_pPointer->m_Components.p[26].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v0.y;
  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  w = m_pTransformNodeComponent->mWorldTransform.v0.w;
  transform.v0.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  transform.v0.y = y;
  transform.v0.z = z;
  transform.v0.w = w;
  v13 = m_pTransformNodeComponent->mWorldTransform.v1.y;
  v14 = m_pTransformNodeComponent->mWorldTransform.v1.z;
  v15 = m_pTransformNodeComponent->mWorldTransform.v1.w;
  transform.v1.x = m_pTransformNodeComponent->mWorldTransform.v1.x;
  transform.v1.y = v13;
  transform.v1.z = v14;
  transform.v1.w = v15;
  v16 = m_pTransformNodeComponent->mWorldTransform.v2.y;
  v17 = m_pTransformNodeComponent->mWorldTransform.v2.z;
  v18 = m_pTransformNodeComponent->mWorldTransform.v2.w;
  transform.v2.x = m_pTransformNodeComponent->mWorldTransform.v2.x;
  transform.v2.y = v16;
  transform.v2.z = v17;
  transform.v2.w = v18;
  v19 = m_pTransformNodeComponent->mWorldTransform.v3.y;
  v20 = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v21 = m_pTransformNodeComponent->mWorldTransform.v3.w;
  vAimDirection.z = m_pTransformNodeComponent->mWorldTransform.v3.x;
  v109 = v19;
  transform.v0.x = v20;
  transform.v0.y = v21;
  mUID = this->mAttachLimbName.mUID;
  if ( mUID != -1
    && mUID != symWorldSpace.mUID
    && mUID != symLocalSpace.mUID
    && (v23 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer) != 0i64
    && ((v24 = v23->m_Flags, (v24 & 0x4000) != 0) || v24 < 0
      ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v23))
      : (v24 & 0x2000) == 0
      ? ((v24 & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v23,
                                                                  UFG::CharacterAnimationComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v23,
                                                                  UFG::CharacterAnimationComponent::_TypeUID)))
      : (ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v23)),
        ComponentOfType
     && (mCreature = ComponentOfType->mCreature) != 0i64
     && mCreature->mPose.mRigHandle.mData
     && (BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, this->mAttachLimbName.mUID), BoneID >= 0)) )
  {
    Creature::GetTransform(mCreature, BoneID, &transform);
  }
  else if ( this->mUseAimOrigin )
  {
    v28 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v28 )
    {
      v29 = v28->m_Flags;
      if ( (v29 & 0x4000) != 0 )
      {
        v30 = (UFG::AimingBaseComponent *)v28->m_Components.p[47].m_pComponent;
      }
      else
      {
        v31 = v29 < 0 || (v29 & 0x2000) != 0 || (v29 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::AimingBaseComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v28, UFG::AimingBaseComponent::_TypeUID);
        v30 = (UFG::AimingBaseComponent *)v31;
      }
      if ( v30 )
      {
        UFG::AimingBaseComponent::GetAimDirection(v30, &vAimDirection, 0i64);
        y_low = (__m128)LODWORD(vAimDirection.y);
        z_low = LODWORD(vAimDirection.z);
        y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                                  + (float)(vAimDirection.x * vAimDirection.x))
                          + (float)(*(float *)&z_low * *(float *)&z_low);
        if ( y_low.m128_f32[0] == 0.0 )
          v34 = 0.0;
        else
          v34 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
        *(float *)&z_low = vAimDirection.z * v34;
        v35 = v34 * vAimDirection.y;
        v36 = v34 * vAimDirection.x;
        transform.v0.x = v36;
        transform.v0.y = v35;
        LODWORD(transform.v0.z) = z_low;
        transform.v0.w = 0.0;
        x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        v40 = x_low;
        v38 = UFG::qVector3::msDirUp.y;
        v39 = UFG::qVector3::msDirUp.z;
        v40.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v38 * v38))
                        + (float)(v39 * v39);
        if ( v40.m128_f32[0] == 0.0 )
        {
          v41 = 0i64;
        }
        else
        {
          v41 = (__m128)(unsigned int)FLOAT_1_0;
          v41.m128_f32[0] = 1.0 / _mm_sqrt_ps(v40).m128_f32[0];
        }
        v42 = v41.m128_f32[0] * UFG::qVector3::msDirUp.z;
        v46 = v41;
        v46.m128_f32[0] = v41.m128_f32[0] * UFG::qVector3::msDirUp.y;
        v43 = v41.m128_f32[0] * UFG::qVector3::msDirUp.x;
        v44 = (float)(v35 * v43) - (float)(v46.m128_f32[0] * v36);
        v45 = (float)(v42 * v36) - (float)(*(float *)&z_low * v43);
        v46.m128_f32[0] = (float)(v46.m128_f32[0] * *(float *)&z_low) - (float)(v42 * v35);
        v47 = v46;
        v47.m128_f32[0] = (float)((float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v45 * v45)) + (float)(v44 * v44);
        if ( v47.m128_f32[0] == 0.0 )
          v48 = 0.0;
        else
          v48 = 1.0 / _mm_sqrt_ps(v47).m128_f32[0];
        transform.v1.x = v46.m128_f32[0] * v48;
        transform.v1.y = v45 * v48;
        transform.v1.z = v44 * v48;
        transform.v1.w = 0.0;
        v49 = (float)((float)(v45 * v48) * v36) - (float)(v35 * (float)(v46.m128_f32[0] * v48));
        v50 = (__m128)z_low;
        v50.m128_f32[0] = (float)(*(float *)&z_low * (float)(v46.m128_f32[0] * v48)) - (float)((float)(v44 * v48) * v36);
        v51 = (float)(v35 * (float)(v44 * v48)) - (float)(*(float *)&z_low * (float)(v45 * v48));
        v52 = v50;
        v52.m128_f32[0] = (float)((float)(v50.m128_f32[0] * v50.m128_f32[0]) + (float)(v51 * v51)) + (float)(v49 * v49);
        if ( v52.m128_f32[0] == 0.0 )
          v53 = 0.0;
        else
          v53 = 1.0 / _mm_sqrt_ps(v52).m128_f32[0];
        transform.v2.x = v53 * v51;
        transform.v2.y = v53 * v50.m128_f32[0];
        transform.v2.z = v53 * v49;
        transform.v2.w = 0.0;
        v54 = v30->m_vAimOriginPosition.y;
        v55 = v30->m_vAimOriginPosition.z;
        vAimDirection.z = v30->m_vAimOriginPosition.x;
        v109 = v54;
        transform.v0.x = v55;
        transform.v0.y = 1.0;
        goto LABEL_57;
      }
    }
  }
  x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v38 = UFG::qVector3::msDirUp.y;
  v39 = UFG::qVector3::msDirUp.z;
LABEL_57:
  x = this->mEnd.x;
  v119 = x;
  v57 = this->mEnd.y;
  v118 = v57;
  v58 = this->mEnd.z;
  transform.v0.z = v58;
  v59 = 0i64;
  if ( this->mToTarget.mValue < 2u )
    goto LABEL_87;
  v60 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v60 )
  {
    v62 = v60->m_Flags;
    if ( (v62 & 0x4000) != 0 )
    {
      v61 = v60->m_Components.p[20].m_pComponent;
    }
    else if ( v62 >= 0 )
    {
      if ( (v62 & 0x2000) != 0 || (v62 & 0x1000) != 0 )
        v63 = UFG::SimObjectGame::GetComponentOfTypeHK(v60, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v63 = UFG::SimObject::GetComponentOfType(v60, UFG::TargetingSystemBaseComponent::_TypeUID);
      v61 = v63;
    }
    else
    {
      v61 = v60->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v61 = 0i64;
  }
  v59 = *(UFG::SimObjectCVBase **)(56i64
                                 * *(unsigned __int8 *)(*(_QWORD *)&v61[1].m_Flags
                                                      + (unsigned __int8)this->mToTarget.mValue
                                                      + 8i64)
                                 + *(_QWORD *)&v61[1].m_TypeUID
                                 + 40);
  if ( !v59 )
    return 0;
  v64 = this->mToTargetBone.mUID;
  if ( v64 == -1 || v64 == symWorldSpace.mUID || v64 == symLocalSpace.mUID )
  {
    v72 = v59->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v72);
    v69 = v72->mWorldTransform.v3.x;
    v70 = v72->mWorldTransform.v3.y;
    v71 = v72->mWorldTransform.v3.z;
    goto LABEL_86;
  }
  v65 = v59->m_Flags;
  if ( (v65 & 0x4000) != 0 || v65 < 0 )
  {
    v66 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v59);
  }
  else if ( (v65 & 0x2000) != 0 )
  {
    v66 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v59);
  }
  else
  {
    v66 = (UFG::CharacterAnimationComponent *)((v65 & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v59,
                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v59,
                                                 UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v66 )
    return 0;
  v67 = v66->mCreature;
  if ( !v67->mPose.mRigHandle.mData )
    return 0;
  v68 = Skeleton::GetBoneID(v67->mPose.mRigHandle.mUFGSkeleton, this->mToTargetBone.mUID);
  if ( v68 < 0 )
    return 0;
  Creature::GetTransform(v67, v68, &v116);
  v69 = v116.v3.x;
  v70 = v116.v3.y;
  v71 = v116.v3.z;
LABEL_86:
  UFG::qInverseAffine((UFG::qMatrix44 *)&transform.v1.z, &transform);
  x = (float)((float)((float)(transform.v2.z * v70) + (float)(transform.v1.z * v69)) + (float)(transform.v3.z * v71))
    + v112;
  v119 = x;
  v57 = (float)((float)((float)(transform.v2.w * v70) + (float)(transform.v1.w * v69)) + (float)(transform.v3.w * v71))
      + v113;
  v118 = v57;
  v58 = (float)((float)((float)(transform.v3.x * v70) + (float)(transform.v2.x * v69)) + (float)(v111 * v71)) + v114;
  transform.v0.z = v58;
  v39 = UFG::qVector3::msDirUp.z;
  v38 = UFG::qVector3::msDirUp.y;
  x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
LABEL_87:
  if ( this->mMakeUpright )
  {
    v73 = (__m128)LODWORD(transform.v0.x);
    v73.m128_f32[0] = (float)(v73.m128_f32[0] * v73.m128_f32[0]) + (float)(transform.v0.y * transform.v0.y);
    if ( v73.m128_f32[0] == 0.0 )
    {
      v74 = 0i64;
    }
    else
    {
      v74 = (unsigned int)FLOAT_1_0;
      *(float *)&v74 = 1.0 / _mm_sqrt_ps(v73).m128_f32[0];
    }
    v75 = v74;
    *(float *)&v75 = *(float *)&v74 * 0.0;
    v76 = *(float *)&v74 * transform.v0.y;
    v77 = *(float *)&v74 * transform.v0.x;
    transform.v0.x = v77;
    transform.v0.y = v76;
    LODWORD(transform.v0.z) = v75;
    transform.v0.w = 0.0;
    v78 = x_low;
    v78.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v38 * v38)) + (float)(v39 * v39);
    if ( v78.m128_f32[0] == 0.0 )
    {
      v80 = 0i64;
    }
    else
    {
      v79 = _mm_sqrt_ps(v78).m128_f32[0];
      v80 = (__m128)(unsigned int)FLOAT_1_0;
      v80.m128_f32[0] = 1.0 / v79;
    }
    v81 = v80;
    v81.m128_f32[0] = v80.m128_f32[0] * v39;
    v82 = v80.m128_f32[0] * v38;
    v83 = v80.m128_f32[0] * x_low.m128_f32[0];
    v84 = (float)(v76 * v83) - (float)(v82 * v77);
    v85 = v81;
    v85.m128_f32[0] = (float)(v81.m128_f32[0] * v77) - (float)(*(float *)&v75 * v83);
    v86 = (float)(v82 * *(float *)&v75) - (float)(v81.m128_f32[0] * v76);
    v87 = v85;
    v87.m128_f32[0] = (float)((float)(v85.m128_f32[0] * v85.m128_f32[0]) + (float)(v86 * v86)) + (float)(v84 * v84);
    if ( v87.m128_f32[0] == 0.0 )
      v88 = 0.0;
    else
      v88 = 1.0 / _mm_sqrt_ps(v87).m128_f32[0];
    transform.v1.x = v88 * v86;
    transform.v1.y = v85.m128_f32[0] * v88;
    transform.v1.z = v84 * v88;
    transform.v1.w = 0.0;
    v89 = (float)((float)(v85.m128_f32[0] * v88) * v77) - (float)(v76 * (float)(v88 * v86));
    v90 = (__m128)v75;
    v90.m128_f32[0] = (float)(*(float *)&v75 * (float)(v88 * v86)) - (float)((float)(v84 * v88) * v77);
    v91 = (float)(v76 * (float)(v84 * v88)) - (float)(*(float *)&v75 * (float)(v85.m128_f32[0] * v88));
    v92 = v90;
    v92.m128_f32[0] = (float)((float)(v90.m128_f32[0] * v90.m128_f32[0]) + (float)(v91 * v91)) + (float)(v89 * v89);
    if ( v92.m128_f32[0] == 0.0 )
      v93 = 0.0;
    else
      v93 = 1.0 / _mm_sqrt_ps(v92).m128_f32[0];
    transform.v2.x = v93 * v91;
    transform.v2.y = v93 * v90.m128_f32[0];
    transform.v2.z = v93 * v89;
    transform.v2.w = 0.0;
    transform.v0.y = 1.0;
  }
  if ( m_pComponent )
  {
    v94 = 0;
    vAimDirection.x = x;
    vAimDirection.y = v57;
    vAimDirection.z = v58;
    if ( this->mReturnTrueIfHitTarget )
      trueIfHits = v59;
    if ( UFG::SensorComponent::CastSphere(
           m_pComponent,
           &transform,
           this->mRadius,
           this->mCollisionLayer,
           &this->mStart,
           &vAimDirection,
           trueIfHits) )
    {
      mSphereCaster = m_pComponent->mSphereCaster;
      mNext = mSphereCaster->mHitList.mNode.mNext;
      p_mHitList = &mSphereCaster->mHitList;
      if ( mNext != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)&mSphereCaster->mHitList )
      {
        while ( !BrokenVehicleGlassSphereCastCondition::IsBrokenVehicleGlass(this, (char *)mNext) )
        {
          mNext = mNext->mNext;
          if ( mNext == (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)p_mHitList )
            return v94;
        }
        return 1;
      }
    }
    return v94;
  }
  UFG::ShapeCasterCollector::ShapeCasterCollector(
    (UFG::ShapeCasterCollector *)&transform.v1.z,
    this->mRadius,
    this->mCollisionLayer,
    PhantomBehaviour_Simple);
  v99 = this->mStart.y;
  v100 = this->mStart.z;
  v101 = (float)((float)((float)(v99 * transform.v1.x) + (float)(this->mStart.x * transform.v0.x))
               + (float)(v100 * transform.v2.x))
       + vAimDirection.z;
  v102 = (float)((float)((float)(v99 * transform.v1.y) + (float)(this->mStart.x * transform.v0.y))
               + (float)(v100 * transform.v2.y))
       + v109;
  v117 = this->mStart.x * transform.v0.z;
  v117 = v117 + (float)(v99 * transform.v1.z);
  vAimDirection.x = (float)((float)((float)(transform.v1.x * v118) + (float)(transform.v0.x * v119))
                          + (float)(transform.v2.x * transform.v0.z))
                  + vAimDirection.z;
  vAimDirection.y = (float)((float)((float)(transform.v1.y * v118) + (float)(transform.v0.y * v119))
                          + (float)(transform.v2.y * transform.v0.z))
                  + v109;
  vAimDirection.z = (float)((float)((float)(transform.v1.z * v118) + (float)(transform.v0.z * v119))
                          + (float)(transform.v2.z * transform.v0.z))
                  + transform.v0.x;
  transform.v0.w = v101;
  transform.v1.x = v102;
  transform.v1.y = (float)(v117 + (float)(v100 * transform.v2.z)) + transform.v0.x;
  v103 = UFG::BasePhysicsSystem::CastShape(
           UFG::BasePhysicsSystem::mInstance,
           (UFG::ShapeCasterCollector *)&transform.v1.z,
           (UFG::qVector3 *)&transform.v0.w,
           &vAimDirection);
  v104 = *(_QWORD *)&transform.v2.z;
  if ( v103 )
  {
    if ( !this->mReturnTrueIfHitTarget )
    {
LABEL_117:
      v106 = 1;
      goto LABEL_119;
    }
    v105 = *(_QWORD *)&transform.v2.z;
    if ( *(UFG::qMatrix44 **)&transform.v2.z != (UFG::qMatrix44 *)&transform.v2 )
    {
      while ( *(UFG::SimObjectCVBase **)(v105 + 80) != v59 )
      {
        v105 = *(_QWORD *)(v105 + 8);
        if ( (UFG::qVector4 *)v105 == &transform.v2 )
          goto LABEL_118;
      }
      goto LABEL_117;
    }
  }
LABEL_118:
  v106 = 0;
LABEL_119:
  v107 = 0;
  if ( v106 && *(UFG::qMatrix44 **)&transform.v2.z != (UFG::qMatrix44 *)&transform.v2 )
  {
    while ( !BrokenVehicleGlassSphereCastCondition::IsBrokenVehicleGlass(this, (char *)v104) )
    {
      v104 = *(_QWORD *)(v104 + 8);
      if ( (UFG::qVector4 *)v104 == &transform.v2 )
        goto LABEL_125;
    }
    v107 = 1;
  }
LABEL_125:
  UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&transform.v1.z);
  return v107;
}

// File Line: 7465
// RVA: 0x27E010
char __fastcall BrokenVehicleGlassSphereCastCondition::IsBrokenVehicleGlass(
        BrokenVehicleGlassSphereCastCondition *this,
        char *fuckingToolsBuild)
{
  UFG::SimObjectGame *v3; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleEffectsComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  UFG::qReflectHandleBase v10; // [rsp+28h] [rbp-30h] BYREF

  if ( (_S13_0 & 1) == 0 )
  {
    _S13_0 |= 1u;
    vehicleGlassUID = UFG::qStringHashUpper32("Glass_Vehicle", -1);
  }
  v3 = (UFG::SimObjectGame *)*((_QWORD *)fuckingToolsBuild + 10);
  if ( !v3 )
    return 0;
  m_Flags = v3->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_10;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent;
    goto LABEL_13;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_10:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v3, UFG::VehicleEffectsComponent::_TypeUID);
  m_pComponent = (UFG::VehicleEffectsComponent *)ComponentOfTypeHK;
LABEL_13:
  if ( m_pComponent )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v10);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v7);
    v10.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v10, v10.mTypeUID, *((_QWORD *)fuckingToolsBuild + 12));
    if ( v10.mData
      && LODWORD(v10.mData[2].vfptr) == vehicleGlassUID
      && UFG::VehicleEffectsComponent::IsGlassBroken(m_pComponent, (UFG::qVector3 *)(fuckingToolsBuild + 16)) )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase(&v10);
      return 1;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v10);
  }
  return 0;
}

// File Line: 7508
// RVA: 0x148C450
__int64 dynamic_initializer_for__TargetParkourHandleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetParkourHandleCondition", 0xFFFFFFFF);
  TargetParkourHandleCondition::sClassNameUID = result;
  return result;
}

// File Line: 7539
// RVA: 0x278C90
void __fastcall TargetParkourHandleCondition::TargetParkourHandleCondition(TargetParkourHandleCondition *this)
{
  ParkourHandleCondition::ParkourHandleCondition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetParkourHandleCondition::`vftable;
  this->m_eTargetType.mValue = 0;
}

// File Line: 7558
// RVA: 0x27B6D0
UFG::ParkourHandle *__fastcall TargetParkourHandleCondition::FindClosestParkourHandle(
        UFG::ParkourComponent *parkourComponent,
        UFG::qVector3 *position,
        UFG::qVector3 *orientationVector,
        float relativeAngle,
        float bufferZone,
        float distanceXYMin,
        float distanceXYMax,
        float distanceZMin,
        float distanceZMax,
        unsigned int check,
        UFG::qVector3 *contactPosition)
{
  UFG::ParkourHandle *v13; // rdi
  unsigned int v14; // ebp
  unsigned int v15; // ebx
  UFG::qVector3 *v16; // r14
  UFG::ParkourHandle *v17; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  float v21; // [rsp+80h] [rbp-B8h] BYREF
  UFG::ParkourHandle *v22[2]; // [rsp+88h] [rbp-B0h] BYREF
  UFG::qVector3 v23; // [rsp+98h] [rbp-A0h] BYREF
  UFG::qArray<UFG::ParkourHandle *,0> v24; // [rsp+A8h] [rbp-90h] BYREF

  v22[1] = (UFG::ParkourHandle *)-2i64;
  v13 = 0i64;
  v22[0] = 0i64;
  v21 = FLOAT_3_4028235e38;
  v14 = check;
  if ( (check & 1) == 0 )
    return 0i64;
  v24.p = 0i64;
  *(_QWORD *)&v24.size = 0i64;
  UFG::ParkourQueryManager::UpdateOrCreateAllHandles(UFG::ParkourQueryManager::mInstance, parkourComponent, &v24);
  v15 = 0;
  if ( v24.size )
  {
    v16 = contactPosition;
    do
    {
      v17 = v24.p[v15];
      if ( v17 && UFG::ParkourHandle::IsEnabled(v24.p[v15]) )
      {
        y = orientationVector->y;
        z = orientationVector->z;
        v23.x = orientationVector->x;
        v23.y = y;
        v23.z = z;
        compareParkourHandles(
          v14,
          position,
          &v23,
          relativeAngle,
          bufferZone,
          distanceXYMin,
          distanceXYMax,
          distanceZMin,
          distanceZMax,
          v16,
          v17,
          v22,
          &v21,
          (bool *)&check,
          0);
      }
      ++v15;
    }
    while ( v15 < v24.size );
    v13 = v22[0];
  }
  if ( v24.p )
    operator delete[](v24.p);
  v24.p = 0i64;
  *(_QWORD *)&v24.size = 0i64;
  if ( v13 )
    return v13;
  else
    return 0i64;
}

// File Line: 7609
// RVA: 0x28D2B0
char __fastcall TargetParkourHandleCondition::Match(TargetParkourHandleCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  char v4; // r12
  ActionNode *v5; // r14
  UFG::SimComponent *m_pComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v10; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  __int16 v12; // dx
  UFG::SimObject *v13; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimObjectGame *v15; // rdi
  __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  __int16 v18; // cx
  UFG::SimComponent *v19; // rax
  UFG::ParkourComponent *v20; // rdi
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SimObjectGame *v23; // rcx
  UFG::AimingBaseComponent *v24; // rax
  __int16 v25; // dx
  __m128 x_low; // xmm1
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float mDirection; // xmm2_4
  UFG::ParkourHandle *ClosestParkourHandle; // rax
  UFG::ParkourHandle *v33; // rdi
  UFG::SimObjectGame *v35; // rcx
  __int16 v36; // dx
  UFG::WorldContextComponent *v37; // rax
  __int64 mOffset; // rcx
  float x; // xmm9_4
  float v40; // xmm11_4
  float v41; // xmm10_4
  float HalfLength; // xmm0_4
  UFG::qVector3 *Axis; // rax
  float v44; // xmm6_4
  float v45; // xmm7_4
  float v46; // xmm8_4
  UFG::qVector3 *v47; // rax
  float v48; // xmm9_4
  float v49; // xmm11_4
  float v50; // xmm10_4
  UFG::qVector3 *v51; // rax
  float v52; // xmm11_4
  float v53; // xmm0_4
  UFG::qVector3 vAimDirection; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qVector3 result; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector3 position; // [rsp+80h] [rbp-80h] BYREF
  UFG::qVector3 dest; // [rsp+90h] [rbp-70h] BYREF
  UFG::qVector3 pointAlongHandle; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qVector3 v59; // [rsp+B0h] [rbp-50h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0;
  v5 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v10 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v10 )
  {
    v12 = v10->m_Flags;
    if ( (v12 & 0x4000) != 0 || v12 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
    }
    else if ( (v12 & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
    }
    else if ( (v12 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v10,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              v10,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
  v13 = context->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( v13 )
    m_pTransformNodeComponent = v13->m_pTransformNodeComponent;
  if ( !m_pComponent )
    return v4;
  if ( !ComponentOfType )
    return v4;
  if ( !v13 )
    return v4;
  if ( !v13->m_pTransformNodeComponent )
    return v4;
  v15 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)this->m_eTargetType.mValue
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
  if ( !v15 )
    return v4;
  v16 = v15->m_Flags;
  if ( (v16 & 0x4000) != 0 )
    return v4;
  if ( v16 >= 0 )
  {
    if ( (v16 & 0x2000) != 0 )
      return v4;
    if ( (v16 & 0x1000) != 0 )
      v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v17 = UFG::SimObject::GetComponentOfType(v15, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v17 = v15->m_Components.p[34].m_pComponent;
  }
  if ( v17 )
  {
    v18 = v15->m_Flags;
    if ( (v18 & 0x4000) != 0 || v18 < 0 || (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
      v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::ParkourComponent::_TypeUID);
    else
      v19 = UFG::SimObject::GetComponentOfType(v15, UFG::ParkourComponent::_TypeUID);
    v20 = (UFG::ParkourComponent *)v19;
    if ( v19 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      position.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      position.y = y;
      position.z = z;
      if ( this->mUseAimingDirection )
      {
        v23 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
        if ( v23 )
        {
          v25 = v23->m_Flags;
          if ( (v25 & 0x4000) != 0 )
            v24 = (UFG::AimingBaseComponent *)v23->m_Components.p[47].m_pComponent;
          else
            v24 = (UFG::AimingBaseComponent *)(v25 < 0 || (v25 & 0x2000) != 0 || (v25 & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v23,
                                                 UFG::AimingBaseComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v23,
                                                 UFG::AimingBaseComponent::_TypeUID));
        }
        else
        {
          v24 = 0i64;
        }
        UFG::AimingBaseComponent::GetAimDirection(v24, &vAimDirection, 0i64);
        vAimDirection.z = 0.0;
        x_low = (__m128)LODWORD(vAimDirection.x);
        x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(vAimDirection.y * vAimDirection.y);
        v27 = _mm_sqrt_ps(x_low).m128_f32[0];
        if ( v27 <= 0.001 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          v29 = m_pTransformNodeComponent->mWorldTransform.v0.y;
          result.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
          v28 = m_pTransformNodeComponent->mWorldTransform.v0.z;
          result.y = v29;
        }
        else
        {
          v28 = (float)(1.0 / v27) * 0.0;
          result.x = vAimDirection.x * (float)(1.0 / v27);
          result.y = vAimDirection.y * (float)(1.0 / v27);
        }
        result.z = v28;
        v30 = result.y;
        vAimDirection.x = result.x;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v30 = m_pTransformNodeComponent->mWorldTransform.v0.y;
        vAimDirection.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
        v28 = m_pTransformNodeComponent->mWorldTransform.v0.z;
      }
      mDirection = this->mDirection;
      vAimDirection.z = v28;
      vAimDirection.y = v30;
      UFG::qRotateVectorZ(&dest, &vAimDirection, mDirection);
      ClosestParkourHandle = TargetParkourHandleCondition::FindClosestParkourHandle(
                               v20,
                               &position,
                               &dest,
                               this->mRelativeAngle,
                               this->mBufferZone,
                               this->mDistanceXYMin,
                               this->mDistanceXYMax,
                               this->mDistanceZMin,
                               this->mDistanceZMax,
                               (this->mCheckLedgeDropoff != 0 ? 0x80 : 0) | (this->mCheckParkourHandle != 0) | (this->mCheckLedge != 0 ? 2 : 0) | (this->mCheckFence != 0 ? 4 : 0) | (this->mCheckVault != 0 ? 8 : 0) | (this->mCheckRail != 0 ? 0x10 : 0) | (this->mCheckWall != 0 ? 0x20 : 0) | (this->mCheckLeap != 0 ? 0x40 : 0) | (this->mCheckActionHijackClimb != 0 ? 0x100 : 0) | (this->mCheckCover != 0 ? 0x200 : 0),
                               &pointAlongHandle);
      v33 = ClosestParkourHandle;
      if ( ClosestParkourHandle )
      {
        if ( this->mCheckLedgeDropoff
          && UFG::ParkourHandle::GetDropoffDistance(ClosestParkourHandle, &pointAlongHandle, this->mDropoffCastRadius) < this->mMinDropoffHeight )
        {
          return 0;
        }
        v35 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
        if ( v35 )
        {
          v36 = v35->m_Flags;
          if ( (v36 & 0x4000) != 0 )
            v37 = (UFG::WorldContextComponent *)v35->m_Components.p[28].m_pComponent;
          else
            v37 = (UFG::WorldContextComponent *)(v36 < 0 || (v36 & 0x2000) != 0 || (v36 & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v35,
                                                   UFG::WorldContextComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   v35,
                                                   UFG::WorldContextComponent::_TypeUID));
          if ( v37 && this->mSetFocusHandle )
          {
            mOffset = this->mParentNode.mOffset;
            if ( mOffset )
              v5 = (ActionNode *)((char *)&this->mParentNode + mOffset);
            UFG::WorldContextComponent::SetFocusParkourHandle(v37, v33, v5);
          }
        }
        v4 = 1;
        if ( this->mCheckDistance )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          x = m_pTransformNodeComponent->mWorldTransform.v3.x;
          v40 = m_pTransformNodeComponent->mWorldTransform.v3.y;
          v41 = m_pTransformNodeComponent->mWorldTransform.v3.z;
          HalfLength = UFG::ParkourHandle::GetHalfLength(v33);
          Axis = UFG::ParkourHandle::GetAxis(v33, &result);
          v44 = HalfLength * Axis->x;
          v45 = HalfLength * Axis->y;
          v46 = HalfLength * Axis->z;
          v47 = UFG::ParkourHandle::GetPosition(v33, &v59);
          v48 = x - (float)(v47->x - v44);
          v49 = v40 - (float)(v47->y - v45);
          v50 = v41 - (float)(v47->z - v46);
          v51 = UFG::ParkourHandle::GetAxis(v33, &v59);
          v52 = (float)((float)(v49 * v51->y) + (float)(v48 * v51->x)) + (float)(v50 * v51->z);
          if ( this->mCheckLeft )
            v4 = CompareFloat((UFG::InEqualityOperator)this->mInEqualityOperator.mValue, this->mEdgeDistance, v52);
          if ( this->mCheckRight )
          {
            v53 = UFG::ParkourHandle::GetHalfLength(v33);
            return CompareFloat(
                     (UFG::InEqualityOperator)this->mInEqualityOperator.mValue,
                     this->mEdgeDistance,
                     COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v53 * 2.0) - v52) & _xmm));
          }
        }
      }
    }
  }
  return v4;
}- v52) & _xmm));
          }
        }
      }
    }
  }
  return v4;
}

// File Line: 7754
// RVA: 0x148AD10
__int64 dynamic_initializer_for__DropoffCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DropoffCondition", 0xFFFFFFFF);
  DropoffCondition::sClassNameUID = result;
  return result;
}

// File Line: 7762
// RVA: 0x276D20
void __fastcall DropoffCondition::DropoffCondition(DropoffCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&DropoffCondition::`vftable;
  *(_WORD *)&this->mCheckDropoff = 1;
}

// File Line: 7788
// RVA: 0x148BAB0
__int64 dynamic_initializer_for__OnGround::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("OnGround", 0xFFFFFFFF);
  OnGround::sClassNameUID = result;
  return result;
}

// File Line: 7799
// RVA: 0x286120
bool __fastcall OnGround::Match(OnGround *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // rax
  char v7; // si
  char v8; // dl
  unsigned int v9; // ecx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
  }
  else
  {
    v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
    m_pComponent = v6;
  }
  if ( !m_pComponent )
    return 0;
  v7 = CompareFloat(
         (UFG::InEqualityOperator)(unsigned __int8)this->mDistanceInEqualityOperator.mValue,
         this->mFallDistance,
         *((float *)&m_pComponent[5].m_BoundComponentHandles.mNode.mNext + 1));
  v8 = CompareFloat(
         (UFG::InEqualityOperator)(unsigned __int8)this->mTimeInEqualityOperator.mValue,
         this->mFallTime,
         *(float *)&m_pComponent[6].vfptr);
  if ( this->mUseFiltered )
    v9 = m_pComponent[6].m_NameUID >> 1;
  else
    LOBYTE(v9) = m_pComponent[6].m_NameUID;
  return (v9 & 1) != 0 && v7 && v8;
}

// File Line: 7855
// RVA: 0x148BAF0
__int64 dynamic_initializer_for__OnGroundSurfaceType::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("OnGroundSurfaceType", 0xFFFFFFFF);
  OnGroundSurfaceType::sClassNameUID = result;
  return result;
}

// File Line: 7860
// RVA: 0x2863F0
char __fastcall OnGroundSurfaceType::Match(OnGroundSurfaceType *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  char v9; // bl
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
    }
    else
    {
      v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = v6;
    }
    if ( m_pComponent && this->mStairs )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v7);
      v11.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, (unsigned __int64)m_pComponent[6].m_SafePointerList.mNode.mNext);
      if ( v11.mData )
      {
        v9 = BYTE4(v11.mData[1].mBaseNode.mParent);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
        return v9;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
    }
  }
  return 0;
}

// File Line: 7893
// RVA: 0x148BAD0
__int64 dynamic_initializer_for__OnGroundSurfaceGrade::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("OnGroundSurfaceGrade", 0xFFFFFFFF);
  OnGroundSurfaceGrade::sClassNameUID = result;
  return result;
}

// File Line: 7899
// RVA: 0x286240
bool __fastcall OnGroundSurfaceGrade::Match(OnGroundSurfaceGrade *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  float *m_pComponent; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __m128 y_low; // xmm3
  float x; // xmm5_4
  float z; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  double v15; // xmm1_8
  double v16; // xmm0_8

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (float *)m_pPointer->m_Components.p[27].m_pComponent;
  }
  else
  {
    v7 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
    m_pComponent = (float *)v7;
  }
  if ( !m_pComponent )
    return 0;
  v8 = context->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  m_pTransformNodeComponent = v8->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y);
  x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  v13 = (float)((float)(m_pComponent[89] * x) + (float)(m_pComponent[90] * y_low.m128_f32[0]))
      + (float)(m_pComponent[91] * z);
  if ( v13 <= -0.94999999 || v13 >= 0.94999999 )
    return 0;
  v14 = z - (float)(m_pComponent[91] * v13);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - (float)(m_pComponent[90] * v13))
                                    * (float)(y_low.m128_f32[0] - (float)(m_pComponent[90] * v13)))
                            + (float)((float)(x - (float)(m_pComponent[89] * v13))
                                    * (float)(x - (float)(m_pComponent[89] * v13))))
                    + (float)(v14 * v14);
  v15 = 0.0;
  if ( y_low.m128_f32[0] != 0.0 )
  {
    *(_QWORD *)&v15 = (unsigned int)FLOAT_1_0;
    *(float *)&v15 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
  }
  *(float *)&v15 = *(float *)&v15 * v14;
  v16 = UFG::qASin(v15);
  return *(float *)&v16 >= this->mMinGrade && *(float *)&v16 < this->mMaxGrade;
}

// File Line: 7941
// RVA: 0x148B0D0
__int64 dynamic_initializer_for__HitTime::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitTime", 0xFFFFFFFF);
  HitTime::sClassNameUID = result;
  return result;
}

// File Line: 7949
// RVA: 0x277280
void __fastcall HitTime::HitTime(HitTime *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HitTime::`vftable;
  this->mHitTime = 0.0;
  this->mInEqualityOperator.mValue = 4;
}

// File Line: 7979
// RVA: 0x148A9D0
__int64 dynamic_initializer_for__AttackType::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackType", 0xFFFFFFFF);
  AttackType::sClassNameUID = result;
  return result;
}

// File Line: 7985
// RVA: 0x276720
void __fastcall AttackType::AttackType(AttackType *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackType::`vftable;
  this->mAttackTypeID = 0;
}

// File Line: 7988
// RVA: 0x27EED0
bool __fastcall AttackType::Match(AttackType *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && this->mAttackTypeID == HIDWORD(m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
  return result;
}

// File Line: 8008
// RVA: 0x148A950
__int64 dynamic_initializer_for__AttackLocationLateral::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackLocationLateral", 0xFFFFFFFF);
  AttackLocationLateral::sClassNameUID = result;
  return result;
}

// File Line: 8014
// RVA: 0x276620
void __fastcall AttackLocationLateral::AttackLocationLateral(AttackLocationLateral *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackLocationLateral::`vftable;
  this->mAttackLocationLateralID = 0;
}

// File Line: 8017
// RVA: 0x27EBC0
bool __fastcall AttackLocationLateral::Match(AttackLocationLateral *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && this->mAttackLocationLateralID == LODWORD(m_pComponent[3].m_pSimObject);
  return result;
}

// File Line: 8036
// RVA: 0x148A930
__int64 dynamic_initializer_for__AttackLocationHorizontal::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackLocationHorizontal", 0xFFFFFFFF);
  AttackLocationHorizontal::sClassNameUID = result;
  return result;
}

// File Line: 8042
// RVA: 0x2765E0
void __fastcall AttackLocationHorizontal::AttackLocationHorizontal(AttackLocationHorizontal *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackLocationHorizontal::`vftable;
  this->mAttackLocationHorizontalID = 0;
}

// File Line: 8045
// RVA: 0x27EB10
bool __fastcall AttackLocationHorizontal::Match(AttackLocationHorizontal *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && this->mAttackLocationHorizontalID == HIDWORD(m_pComponent[3].m_pSimObject);
  return result;
}

// File Line: 8065
// RVA: 0x148A970
__int64 dynamic_initializer_for__AttackLocationRagdoll::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackLocationRagdoll", 0xFFFFFFFF);
  AttackLocationRagdoll::sClassNameUID = result;
  return result;
}

// File Line: 8071
// RVA: 0x276660
void __fastcall AttackLocationRagdoll::AttackLocationRagdoll(AttackLocationRagdoll *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackLocationRagdoll::`vftable;
  this->m_iRagdollComponentID = 0;
}

// File Line: 8075
// RVA: 0x27EC70
bool __fastcall AttackLocationRagdoll::Match(AttackLocationRagdoll *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  bool v9; // bl
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
      v11.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, *(_QWORD *)&m_pComponent[5].m_Flags);
      if ( v11.mData )
      {
        v9 = this->m_iRagdollComponentID == LODWORD(v11.mData[2].mTypeUID);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
        return v9;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
    }
  }
  return 0;
}

// File Line: 8100
// RVA: 0x148AB90
__int64 dynamic_initializer_for__CollisionTime::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionTime", 0xFFFFFFFF);
  CollisionTime::sClassNameUID = result;
  return result;
}

// File Line: 8108
// RVA: 0x276A30
void __fastcall CollisionTime::CollisionTime(CollisionTime *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionTime::`vftable;
  this->mCollisionTime = 0.0;
  this->mInEqualityOperator.mValue = 4;
}

// File Line: 8113
// RVA: 0x282830
char __fastcall HitTime::Match(HitTime *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
        ComponentOfTypeHK) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mHitTime,
             *(float *)&ComponentOfTypeHK[3].m_Flags);
  }
  else
  {
    return 0;
  }
}

// File Line: 8135
// RVA: 0x148AB30
__int64 dynamic_initializer_for__CollisionLayer::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionLayer", 0xFFFFFFFF);
  CollisionLayer::sClassNameUID = result;
  return result;
}

// File Line: 8141
// RVA: 0x276970
void __fastcall CollisionLayer::CollisionLayer(CollisionLayer *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionLayer::`vftable;
  this->mCollisionLayer = 1;
}

// File Line: 8146
// RVA: 0x2802E0
bool __fastcall CollisionLayer::Match(CollisionLayer *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned __int64 m_pSimObject; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  bool v9; // bl
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_pSimObject = (unsigned __int64)m_pComponent[5].m_pSimObject;
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
      v11.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, m_pSimObject);
      if ( v11.mData )
      {
        v9 = LODWORD(v11.mData[2].mBaseNode.mChildren[0]) == this->mCollisionLayer;
        UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
        return v9;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
    }
  }
  return 0;
}

// File Line: 8172
// RVA: 0x148AB70
__int64 dynamic_initializer_for__CollisionSpeed::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionSpeed", 0xFFFFFFFF);
  CollisionSpeed::sClassNameUID = result;
  return result;
}

// File Line: 8182
// RVA: 0x2769F0
void __fastcall CollisionSpeed::CollisionSpeed(CollisionSpeed *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionSpeed::`vftable;
  this->mCollisionSpeed = 0.0;
  *(_WORD *)&this->mInEqualityOperator.mValue = 1;
}

// File Line: 8187
// RVA: 0x280500
char __fastcall CollisionSpeed::Match(CollisionSpeed *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  if ( this->mUseForwardSpeed )
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mCollisionSpeed,
             *(float *)&m_pComponent[6].m_pSimObject);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mCollisionSpeed,
           *(float *)(&m_pComponent[6].m_SimObjIndex + 1));
}

// File Line: 8214
// RVA: 0x148AB10
__int64 dynamic_initializer_for__CollisionEstimatedImpulseMagnitude::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionEstimatedImpulseMagnitude", 0xFFFFFFFF);
  CollisionEstimatedImpulseMagnitude::sClassNameUID = result;
  return result;
}

// File Line: 8222
// RVA: 0x276930
void __fastcall CollisionEstimatedImpulseMagnitude::CollisionEstimatedImpulseMagnitude(
        CollisionEstimatedImpulseMagnitude *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionEstimatedImpulseMagnitude::`vftable;
  this->mEstimatedImpulseMagnitude = 0.0;
  this->mInEqualityOperator.mValue = 1;
}

// File Line: 8227
// RVA: 0x280220
char __fastcall CollisionEstimatedImpulseMagnitude::Match(
        CollisionEstimatedImpulseMagnitude *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  float v6; // xmm2_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v6 = *((float *)&m_pComponent[6].m_pSimObject + 1);
  if ( v6 >= 0.0 )
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mEstimatedImpulseMagnitude,
             v6);
  else
    return 1;
}

// File Line: 8258
// RVA: 0x148AB50
__int64 dynamic_initializer_for__CollisionMass::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionMass", 0xFFFFFFFF);
  CollisionMass::sClassNameUID = result;
  return result;
}

// File Line: 8266
// RVA: 0x2769B0
void __fastcall CollisionMass::CollisionMass(CollisionMass *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionMass::`vftable;
  this->mCollisionMass = 0.0;
  this->mInEqualityOperator.mValue = 1;
}

// File Line: 8271
// RVA: 0x2803F0
char __fastcall CollisionMass::Match(CollisionMass *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned __int64 m_pSimObject; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  char v9; // bl
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_pSimObject = (unsigned __int64)m_pComponent[5].m_pSimObject;
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
      v11.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, m_pSimObject);
      if ( v11.mData )
      {
        v9 = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
               this->mCollisionMass,
               *(float *)&v11.mData[1].vfptr);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
        return v9;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v11);
    }
  }
  return 0;
}

// File Line: 8303
// RVA: 0x148A9B0
__int64 dynamic_initializer_for__AttackTimerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackTimerCondition", 0xFFFFFFFF);
  AttackTimerCondition::sClassNameUID = result;
  return result;
}

// File Line: 8311
// RVA: 0x2766E0
void __fastcall AttackTimerCondition::AttackTimerCondition(AttackTimerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackTimerCondition::`vftable;
  this->mAttackTime = 0.0;
  this->mInEqualityOperator.mValue = 4;
}

// File Line: 8316
// RVA: 0x27EE20
char __fastcall AttackTimerCondition::Match(AttackTimerCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
        ComponentOfTypeHK) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mAttackTime,
             *(float *)&ComponentOfTypeHK[1].m_TypeUID);
  }
  else
  {
    return 0;
  }
}

// File Line: 8343
// RVA: 0x148A990
__int64 dynamic_initializer_for__AttackPhaseCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackPhaseCondition", 0xFFFFFFFF);
  AttackPhaseCondition::sClassNameUID = result;
  return result;
}

// File Line: 8349
// RVA: 0x2766A0
void __fastcall AttackPhaseCondition::AttackPhaseCondition(AttackPhaseCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackPhaseCondition::`vftable;
  this->m_eAttackPhase.mValue = 1;
}

// File Line: 8353
// RVA: 0x27ED80
bool __fastcall AttackPhaseCondition::Match(AttackPhaseCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && m_pComponent[1].m_NameUID == (unsigned __int8)this->m_eAttackPhase.mValue;
  return result;
}

// File Line: 8378
// RVA: 0x148A8F0
__int64 dynamic_initializer_for__AttackInfoNumberHitsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackInfoNumberHitsCondition", 0xFFFFFFFF);
  AttackInfoNumberHitsCondition::sClassNameUID = result;
  return result;
}

// File Line: 8386
// RVA: 0x276560
void __fastcall AttackInfoNumberHitsCondition::AttackInfoNumberHitsCondition(AttackInfoNumberHitsCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackInfoNumberHitsCondition::`vftable;
  this->mInEqualityOperator.mValue = 1;
  this->mQuantity = 0;
}

// File Line: 8390
// RVA: 0x27E9B0
bool __fastcall AttackInfoNumberHitsCondition::Match(AttackInfoNumberHitsCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
            ComponentOfTypeHK)
        && CompareInt(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mQuantity,
             *(_DWORD *)&ComponentOfTypeHK[7].m_Flags);
  return result;
}

// File Line: 8416
// RVA: 0x148A910
__int64 dynamic_initializer_for__AttackIntensityCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackIntensityCondition", 0xFFFFFFFF);
  AttackIntensityCondition::sClassNameUID = result;
  return result;
}

// File Line: 8422
// RVA: 0x2765A0
void __fastcall AttackIntensityCondition::AttackIntensityCondition(AttackIntensityCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackIntensityCondition::`vftable;
  this->m_eAttackItensityType.mValue = 0;
}

// File Line: 8426
// RVA: 0x27EA60
bool __fastcall AttackIntensityCondition::Match(AttackIntensityCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && (unsigned __int8)this->m_eAttackItensityType.mValue == HIDWORD(m_pComponent[3].m_BoundComponentHandles.mNode.mNext);
  return result;
}

// File Line: 8448
// RVA: 0x148A8D0
__int64 dynamic_initializer_for__AttackDamageCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackDamageCondition", 0xFFFFFFFF);
  AttackDamageCondition::sClassNameUID = result;
  return result;
}

// File Line: 8456
// RVA: 0x276520
void __fastcall AttackDamageCondition::AttackDamageCondition(AttackDamageCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackDamageCondition::`vftable;
  this->mInEqualityOperator.mValue = 1;
  this->mAmount = 0;
}

// File Line: 8460
// RVA: 0x27E900
bool __fastcall AttackDamageCondition::Match(AttackDamageCondition *this, ActionContext *context)
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
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
            ComponentOfTypeHK)
        && CompareInt(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mAmount,
             (int)ComponentOfTypeHK[3].vfptr);
  return result;
}

// File Line: 8481
// RVA: 0x148B2B0
__int64 dynamic_initializer_for__InventoryQuantityCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InventoryQuantityCondition", 0xFFFFFFFF);
  InventoryQuantityCondition::sClassNameUID = result;
  return result;
}

// File Line: 8491
// RVA: 0x277600
void __fastcall InventoryQuantityCondition::InventoryQuantityCondition(InventoryQuantityCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InventoryQuantityCondition::`vftable;
  this->mInventoryItem = 0;
  this->mInEqualityOperator.mValue = 1;
  this->mQuantity = 0;
}

// File Line: 8496
// RVA: 0x283860
bool __fastcall InventoryQuantityCondition::Match(InventoryQuantityCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v6; // rax
  __int64 mInventoryItem; // rax
  int v8; // r8d

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[39].m_pComponent;
  }
  else
  {
    v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InventoryComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InventoryComponent::_TypeUID);
    m_pComponent = v6;
  }
  if ( !m_pComponent )
    return 0;
  mInventoryItem = this->mInventoryItem;
  if ( !LOBYTE(m_pComponent[14].m_pSimObject)
    || (v8 = 1, (_DWORD)mInventoryItem != *(_DWORD *)&m_pComponent[14].m_Flags) )
  {
    v8 = *(&m_pComponent[1].m_NameUID + mInventoryItem);
  }
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mQuantity, v8);
}

// File Line: 8531
// RVA: 0x148B290
__int64 dynamic_initializer_for__InventoryIsItemEquipped::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InventoryIsItemEquipped", 0xFFFFFFFF);
  InventoryIsItemEquipped::sClassNameUID = result;
  return result;
}

// File Line: 8537
// RVA: 0x2775C0
void __fastcall InventoryIsItemEquipped::InventoryIsItemEquipped(InventoryIsItemEquipped *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InventoryIsItemEquipped::`vftable;
  this->mInventoryItem = 0;
}

// File Line: 8542
// RVA: 0x283730
bool __fastcall InventoryIsItemEquipped::Match(InventoryIsItemEquipped *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  __int64 v6; // r8
  __int64 v7; // rdx
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  int m_pSimObject; // ecx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v6 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
  v7 = *(_QWORD *)&m_pComponent[1].m_Flags;
  v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v7 + 25) + v6 + 40);
  if ( !v8 )
  {
    v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v7 + 26) + v6 + 40);
    if ( !v8 )
      return 0;
  }
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 || v9 < 0 )
    return 0;
  if ( (v9 & 0x2000) != 0 )
    v10 = v8->m_Components.p[11].m_pComponent;
  else
    v10 = (v9 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::InventoryItemComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v8, UFG::InventoryItemComponent::_TypeUID);
  if ( !v10 )
    return 0;
  m_pSimObject = (int)v10[1].m_pSimObject;
  return m_pSimObject && this->mInventoryItem == m_pSimObject;
}

// File Line: 8579
// RVA: 0x148B250
__int64 dynamic_initializer_for__InventoryCanDrop::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InventoryCanDrop", 0xFFFFFFFF);
  InventoryCanDrop::sClassNameUID = result;
  return result;
}

// File Line: 8585
// RVA: 0x277580
void __fastcall InventoryCanDrop::InventoryCanDrop(InventoryCanDrop *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InventoryCanDrop::`vftable;
  this->mEquipSlot.mValue = 0;
}

// File Line: 8590
// RVA: 0x283680
bool __fastcall InventoryCanDrop::Match(InventoryCanDrop *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::InventoryComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::InventoryComponent::_TypeUID))
       : (ComponentOfType = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::InventoryComponent::_TypeUID)))
      : (ComponentOfType = (UFG::InventoryComponent *)m_pPointer->m_Components.p[39].m_pComponent),
        ComponentOfType) )
  {
    return UFG::InventoryComponent::GetCanDrop(
             ComponentOfType,
             (UFG::eInventoryEquipSlot)(unsigned __int8)this->mEquipSlot.mValue);
  }
  else
  {
    return 1;
  }
}

// File Line: 8617
// RVA: 0x148BE90
__int64 dynamic_initializer_for__RandomCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RandomCondition", 0xFFFFFFFF);
  RandomCondition::sClassNameUID = result;
  return result;
}

// File Line: 8627
// RVA: 0x278410
void __fastcall RandomCondition::RandomCondition(RandomCondition *this)
{
  Condition::Condition(this);
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&RandomCondition::`vftable{for `Condition};
  this->IWeightedCondition::vfptr = (IWeightedConditionVtbl *)&RandomCondition::`vftable{for `IWeightedCondition};
  this->m_pParentBank = 0i64;
  this->mWeight = 50.0;
  this->mNormalizedWeight = -1.0;
  this->mNormalizedWeightCorrectlySet = 1;
  this->mWeightLevel = 0;
}

// File Line: 8633
// RVA: 0x294100
void __fastcall RandomCondition::ResolveReferences(RandomCondition *this, ActionNode *action_node)
{
  __int64 mOffset; // rax
  ActionNodeBank *v4; // rbx

  mOffset = action_node->mParent.mOffset;
  if ( mOffset )
  {
    v4 = (ActionNodeBank *)((char *)&action_node->mParent + mOffset);
    if ( v4 )
    {
      if ( v4->vfptr->GetClassNameUID(v4) == ActionNodeBank::sClassNameUID )
        this->m_pParentBank = v4;
    }
  }
}

// File Line: 8643
// RVA: 0x2893D0
bool __fastcall RandomCondition::Match(RandomCondition *this, ActionContext *context)
{
  ActionNodePlayable *m_pParentBank; // rdx

  if ( this->mNormalizedWeight < 0.0 )
    this->mNormalizedWeightCorrectlySet = 0;
  if ( !this->mNormalizedWeightCorrectlySet )
  {
    ((void (__fastcall *)(IWeightedCondition *))this->IWeightedCondition::vfptr->GetWeightToBalance)(&this->IWeightedCondition);
    ((void (__fastcall *)(IWeightedCondition *))this->IWeightedCondition::vfptr->SetBalancedWeight)(&this->IWeightedCondition);
  }
  if ( !context->mProbabilitiesValid )
  {
    m_pParentBank = (ActionNodePlayable *)this->m_pParentBank;
    if ( !m_pParentBank || !ActionController::IsPlaying(context->mActionController, m_pParentBank) )
      ActionContext::UpdateProbabilites(context);
  }
  return context->mProbabilitys[this->mWeightLevel] < this->mNormalizedWeight;
}

// File Line: 8717
// RVA: 0x27D5D0
UFG::qPropertySet *__fastcall GetPersonalityPropertySet(ActionContext *action_context, Condition *condition)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rbx
  UFG::qSymbol *v4; // rdi
  UFG::qPropertyList *v5; // rax
  UFG::qPropertyList *v6; // rdi
  unsigned int RandomIndex; // eax

  m_pPointer = action_context->mSimObject.m_pPointer;
  m_pSceneObj = m_pPointer->m_pSceneObj;
  if ( !m_pSceneObj )
    return 0i64;
  v4 = (UFG::qSymbol *)PropertyUtils::Get<UFG::qSymbol>(
                         m_pPointer->m_pSceneObj,
                         (UFG::qArray<unsigned long,0> *)&qSymbol_PersonalityList_SelectedItem);
  if ( v4 )
    return UFG::PropertySetManager::GetPropertySet(v4);
  v5 = PropertyUtils::Get<UFG::qPropertyList>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_PersonalityList);
  v6 = v5;
  if ( v5
    && (RandomIndex = UFG::qPropertyList::GetRandomIndex(v5),
        v4 = UFG::qPropertyList::Get<UFG::qSymbol>(v6, RandomIndex),
        PropertyUtils::Set<UFG::qSymbol>(
          m_pSceneObj,
          (UFG::qArray<unsigned long,0> *)&qSymbol_PersonalityList_SelectedItem,
          v4),
        v4) )
  {
    return UFG::PropertySetManager::GetPropertySet(v4);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 8763
// RVA: 0x148BC50
__int64 dynamic_initializer_for__PersonalityTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PersonalityTypeCondition", 0xFFFFFFFF);
  PersonalityTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 8768
// RVA: 0x277F80
void __fastcall PersonalityTypeCondition::PersonalityTypeCondition(PersonalityTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PersonalityTypeCondition::`vftable;
  this->m_PersonalityTypeSymbol.mUID = -1;
  *(_QWORD *)&this->m_PropertyValueUID = 0i64;
  this->m_PersonalityTypeSymbol = UFG::gNullQSymbol;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 8786
// RVA: 0x294030
void __fastcall PersonalityTypeCondition::ResolveReferences(PersonalityTypeCondition *this, ActionNode *action_node)
{
  unsigned int ValueUID; // eax
  unsigned int m_PropertyValueHasBeenReadUID; // ecx

  ((void (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(this->m_PropertyValueUID, eACTION_TREE_MEMORY_ELEMENT_QSYMBOL);
  m_PropertyValueHasBeenReadUID = this->m_PropertyValueHasBeenReadUID;
  this->m_PropertyValueUID = ValueUID;
  this->m_PropertyValueHasBeenReadUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                          m_PropertyValueHasBeenReadUID,
                                          eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 8848
// RVA: 0x288AB0
bool __fastcall PersonalityTypeCondition::Match(PersonalityTypeCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v5; // rdx
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::qPropertySet *PersonalityPropertySet; // rax
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rcx
  int v11; // eax
  __int64 v12; // rax
  UFG::ActionTreeComponentBase *v13; // rdx
  char *v14; // rcx
  UFG::ActionTreeComponentBase *v15; // rcx
  ActionNodeRoot *m_PropertyValueUID; // r8
  unsigned int v17; // r9d
  __int64 v18; // rax
  UFG::ActionTreeComponentBase *v19; // rdx
  char *v20; // rcx
  UFG::ActionTreeComponentBase *v21; // rcx
  __int64 v22; // rax
  UFG::ActionTreeComponentBase *v23; // rdx
  char *v24; // rcx
  UFG::ActionTreeComponentBase *v25; // rcx
  bool *value; // [rsp+20h] [rbp-28h]
  bool valuea; // [rsp+20h] [rbp-28h]
  unsigned int value_uid; // [rsp+50h] [rbp+8h] BYREF
  unsigned int mUID; // [rsp+58h] [rbp+10h] BYREF
  int v31; // [rsp+60h] [rbp+18h] BYREF
  int *v32; // [rsp+68h] [rbp+20h] BYREF

  LOBYTE(value_uid) = 0;
  mOffset = this->m_MyRoot.mOffset;
  if ( mOffset )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v5 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->m_MyRoot + mOffset;
  else
    v6 = 0i64;
  v7 = context->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v7,
    v5,
    (ActionNodeRoot *)this->m_PropertyValueHasBeenReadUID,
    (unsigned int)&value_uid,
    (bool *)0xFFFFFFFFFFFFFFFEi64);
  mUID = UFG::gNullQSymbol.mUID;
  if ( (_BYTE)value_uid )
  {
    v22 = this->m_MyRoot.mOffset;
    if ( v22 )
      v23 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v22);
    else
      v23 = 0i64;
    if ( v22 )
      v24 = (char *)&this->m_MyRoot + v22;
    else
      v24 = 0i64;
    v25 = context->mActionTreeComponentBase[v24[236]];
    if ( !v25 )
      v25 = context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::qSymbol>(
      v25,
      v23,
      (ActionNodeRoot *)this->m_PropertyValueUID,
      (unsigned int)&mUID,
      (UFG::qSymbol *)value);
    goto LABEL_40;
  }
  PersonalityPropertySet = GetPersonalityPropertySet(context, this);
  if ( !PersonalityPropertySet )
  {
LABEL_40:
    v11 = mUID;
    return v11 == this->m_PersonalityTypeSymbol.mUID;
  }
  v9 = UFG::qPropertySet::Get<UFG::qSymbol>(
         PersonalityPropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_PersonalityType,
         DEPTH_RECURSE);
  v10 = &UFG::gNullQSymbol;
  if ( v9 )
    v10 = v9;
  v11 = v10->mUID;
  mUID = v11;
  if ( v11 != UFG::gNullQSymbol.mUID )
  {
    v32 = &v31;
    v31 = v11;
    v12 = this->m_MyRoot.mOffset;
    if ( v12 )
      v13 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v12);
    else
      v13 = 0i64;
    if ( v12 )
      v14 = (char *)&this->m_MyRoot + v12;
    else
      v14 = 0i64;
    v15 = context->mActionTreeComponentBase[v14[236]];
    if ( !v15 )
      v15 = context->mActionTreeComponentBase[1];
    m_PropertyValueUID = (ActionNodeRoot *)this->m_PropertyValueUID;
    LODWORD(v32) = v31;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::qSymbol>(
      v15,
      v13,
      m_PropertyValueUID,
      (unsigned int)&v32,
      (UFG::qSymbol)value);
    v18 = this->m_MyRoot.mOffset;
    if ( v18 )
      v19 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v18);
    else
      v19 = 0i64;
    if ( v18 )
      v20 = (char *)&this->m_MyRoot + v18;
    else
      v20 = 0i64;
    v21 = context->mActionTreeComponentBase[v20[236]];
    if ( !v21 )
      v21 = context->mActionTreeComponentBase[1];
    LOBYTE(v17) = 1;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v21,
      v19,
      (ActionNodeRoot *)this->m_PropertyValueHasBeenReadUID,
      v17,
      valuea);
    goto LABEL_40;
  }
  return v11 == this->m_PersonalityTypeSymbol.mUID;
}opertyValueHasBeenReadUID,
  

// File Line: 8905
// RVA: 0x148A7F0
__int64 dynamic_initializer_for__AiBehaviourCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AiBehaviourCondition", 0xFFFFFFFF);
  AiBehaviourCondition::sClassNameUID = result;
  return result;
}

// File Line: 8913
// RVA: 0x2763B0
void __fastcall AiBehaviourCondition::AiBehaviourCondition(AiBehaviourCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AiBehaviourCondition::`vftable;
  this->mMostUsedIndex = -1;
  this->mCheckSpawns = 0;
}

// File Line: 8922
// RVA: 0x27E2A0
unsigned __int8 __fastcall AiBehaviourCondition::Match(AiBehaviourCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 v5; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer
    || ((v5 = m_pPointer->m_Flags, (v5 & 0x4000) == 0)
      ? (v5 >= 0
       ? ((v5 & 0x2000) != 0 || (v5 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[22].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[22].m_pComponent),
        !ComponentOfTypeHK) )
  {
    v7 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
    if ( !v7 )
      return 0;
    m_Flags = v7->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
    else
      v9 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AiDriverComponent::_TypeUID)
                                    : UFG::SimObject::GetComponentOfType(v7, UFG::AiDriverComponent::_TypeUID));
    if ( !v9 )
      return 0;
  }
  v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v10
    && ((v11 = v10->m_Flags, (v11 & 0x4000) == 0)
      ? (v11 >= 0
       ? ((v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
        ? (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::AIActionTreeComponent::_TypeUID))
        : (ComponentOfType = UFG::SimObject::GetComponentOfType(v10, UFG::AIActionTreeComponent::_TypeUID)))
       : (ComponentOfType = v10->m_Components.p[19].m_pComponent))
      : (ComponentOfType = v10->m_Components.p[19].m_pComponent),
        ComponentOfType) )
  {
    return ActionController::IsPlaying(
             (ActionController *)&ComponentOfType[3].m_TypeUID,
             &this->mAIBehaviourID,
             this->mMostUsedIndex,
             this->mCheckSpawns != 0);
  }
  else
  {
    return 0;
  }
}

// File Line: 8945
// RVA: 0x294220
void __fastcall IsPlayingCondition::Serialize(IsPlayingCondition *this, IActionTreeSerializer *serializer)
{
  this->mMostUsedIndex = GetMostUsedIndex(this->mActionNodeName.mUID);
}

// File Line: 8963
// RVA: 0x148A810
__int64 dynamic_initializer_for__AiBehaviourTreeTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AiBehaviourTreeTypeCondition", 0xFFFFFFFF);
  AiBehaviourTreeTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 8968
// RVA: 0x2763F0
void __fastcall AiBehaviourTreeTypeCondition::AiBehaviourTreeTypeCondition(AiBehaviourTreeTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AiBehaviourTreeTypeCondition::`vftable;
}

// File Line: 8978
// RVA: 0x27E450
bool __fastcall AiBehaviourTreeTypeCondition::Match(AiBehaviourTreeTypeCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v9; // dx
  unsigned int v10; // edx
  bool v11; // zf

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v7 )
    return MEMORY[0xC8] == this->mAIBehaviourTreeID.mUID;
  v9 = v7->m_Flags;
  if ( (v9 & 0x4000) != 0 || v9 < 0 )
    return LODWORD(v7->m_Components.p[19].m_pComponent[3].m_SafePointerList.mNode.mPrev) == this->mAIBehaviourTreeID.mUID;
  if ( (v9 & 0x2000) != 0 )
  {
    v10 = UFG::AIActionTreeComponent::_TypeUID;
    return LODWORD(UFG::SimObjectGame::GetComponentOfTypeHK(v7, v10)[3].m_SafePointerList.mNode.mPrev) == this->mAIBehaviourTreeID.mUID;
  }
  v11 = (v9 & 0x1000) == 0;
  v10 = UFG::AIActionTreeComponent::_TypeUID;
  if ( !v11 )
    return LODWORD(UFG::SimObjectGame::GetComponentOfTypeHK(v7, v10)[3].m_SafePointerList.mNode.mPrev) == this->mAIBehaviourTreeID.mUID;
  return LODWORD(UFG::SimObject::GetComponentOfType(v7, UFG::AIActionTreeComponent::_TypeUID)[3].m_SafePointerList.mNode.mPrev) == this->mAIBehaviourTreeID.mUID;
}

// File Line: 9010
// RVA: 0x1491BB0
__int64 dynamic_initializer_for__geAIEmotionEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&geAIEmotionEnum, UFG::AIEmotionNames, 13, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__geAIEmotionEnum__);
}

// File Line: 9012
// RVA: 0x148A830
__int64 dynamic_initializer_for__AiEmotionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AiEmotionCondition", 0xFFFFFFFF);
  AiEmotionCondition::sClassNameUID = result;
  return result;
}

// File Line: 9018
// RVA: 0x276420
void __fastcall AiEmotionCondition::AiEmotionCondition(AiEmotionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&AiEmotionCondition::`vftable;
  this->mAIEmotion.mValue = 0;
}

// File Line: 9023
// RVA: 0x27E5B0
bool __fastcall AiEmotionCondition::Match(AiEmotionCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   m_pPointer,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_CurrentEmotion == (unsigned __int8)this->mAIEmotion.mValue;
  return result;
}

// File Line: 9056
// RVA: 0x148ADB0
__int64 dynamic_initializer_for__FacialEmotionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FacialEmotionCondition", 0xFFFFFFFF);
  FacialEmotionCondition::sClassNameUID = result;
  return result;
}

// File Line: 9062
// RVA: 0x276E50
void __fastcall FacialEmotionCondition::FacialEmotionCondition(FacialEmotionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FacialEmotionCondition::`vftable;
  this->mFacialEmotion.mValue = 0;
}

// File Line: 9067
// RVA: 0x281950
bool __fastcall FacialEmotionCondition::Match(FacialEmotionCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   m_pPointer,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_FacialEmotion == (unsigned __int8)this->mFacialEmotion.mValue;
  return result;
}

// File Line: 9096
// RVA: 0x148BEB0
__int64 dynamic_initializer_for__RelativeOrientationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RelativeOrientationCondition", 0xFFFFFFFF);
  RelativeOrientationCondition::sClassNameUID = result;
  return result;
}

// File Line: 9099
// RVA: 0x289460
bool __fastcall RelativeOrientationCondition::Match(RelativeOrientationCondition *this, ActionContext *pContext)
{
  char v4; // bl
  char v5; // al
  bool v6; // bl
  float v7; // xmm0_4
  float v8; // xmm0_4
  UFG::qVector3 v1; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qVector3 v2; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector3 v12; // [rsp+40h] [rbp-98h] BYREF
  float v13; // [rsp+50h] [rbp-88h]
  float v14; // [rsp+54h] [rbp-84h]
  float v15; // [rsp+58h] [rbp-80h]
  UFG::qVector3 v16; // [rsp+80h] [rbp-58h] BYREF

  v4 = ((__int64 (__fastcall *)(RelativeOrientationCondition *, ActionContext *, UFG::qVector3 *))this->vfptr[1].GetResourceOwner)(
         this,
         pContext,
         &v12);
  v5 = ((__int64 (__fastcall *)(RelativeOrientationCondition *, ActionContext *, UFG::qVector3 *))this->vfptr[2].FindWithOldPath)(
         this,
         pContext,
         &v16);
  if ( !v4 || !v5 )
    return 0;
  v1 = v12;
  v2 = v16;
  v6 = (float)((float)((float)(v16.y * v14) + (float)(v16.x * v13)) + (float)(v16.z * v15)) > 0.0;
  v7 = UFG::qAngleBetween(&v1, &v2);
  if ( v6 )
    v7 = 6.2831855 - v7;
  v8 = v7 - this->m_fOrientation;
  if ( v8 < 0.0 )
    v8 = v8 + 6.2831855;
  if ( v8 >= 3.1415927 )
    v8 = 6.2831855 - v8;
  return v8 <= this->m_fAngleRange;
}

// File Line: 9161
// RVA: 0x148C630
__int64 dynamic_initializer_for__TargetRelativeOrientationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetRelativeOrientationCondition", 0xFFFFFFFF);
  TargetRelativeOrientationCondition::sClassNameUID = result;
  return result;
}

// File Line: 9171
// RVA: 0x27BA80
bool __fastcall TargetRelativeOrientationCondition::GetBaseMatrix(
        TargetRelativeOrientationCondition *this,
        ActionContext *pContext,
        UFG::qMatrix44 *outBaseMatrix)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v8; // rax
  UFG::SimObjectCVBase *v9; // rbx
  __int16 v10; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  bool result; // al
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector4 v16; // xmm3
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm1

  if ( this->m_bRelativeToTarget )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( !m_pPointer )
      return 0;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v8;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( !m_pComponent )
      return 0;
    v9 = *(UFG::SimObjectCVBase **)(56i64
                                  * *(unsigned __int8 *)((unsigned int)this->m_iTargetType
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
  }
  else
  {
    v9 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  }
  if ( v9 )
  {
    if ( this->mBoneName.mUID == UFG::gNullQSymbolUC.mUID || !this->m_bRelativeToTarget )
    {
      m_pTransformNodeComponent = v9->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      result = 1;
      v16 = m_pTransformNodeComponent->mWorldTransform.v1;
      v17 = m_pTransformNodeComponent->mWorldTransform.v2;
      v18 = m_pTransformNodeComponent->mWorldTransform.v3;
      outBaseMatrix->v0 = m_pTransformNodeComponent->mWorldTransform.v0;
      outBaseMatrix->v1 = v16;
      outBaseMatrix->v2 = v17;
      outBaseMatrix->v3 = v18;
      return result;
    }
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 || v10 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    else if ( (v10 & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
    }
    else if ( (v10 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v9,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                v9,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    mCreature = ComponentOfTypeHK->mCreature;
    if ( mCreature )
    {
      if ( mCreature->mPose.mRigHandle.mData )
      {
        BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, this->mBoneName.mUID);
        if ( BoneID >= 0 )
        {
          Creature::GetTransform(mCreature, BoneID, outBaseMatrix);
          return 1;
        }
      }
    }
  }
  return 0;
}

// File Line: 9229
// RVA: 0x27DAE0
char __fastcall TargetRelativeOrientationCondition::GetRelativeToMatrix(
        TargetRelativeOrientationCondition *this,
        ActionContext *pContext,
        UFG::qMatrix44 *outRelativeToMatrix)
{
  bool v3; // zf
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v9; // rax
  __int16 v10; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector4 v16; // xmm3
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm1

  v3 = this->m_bRelativeToTarget == 0;
  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    if ( !m_pPointer )
      return 0;
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v9 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v9;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( !m_pComponent )
      return 0;
    m_pPointer = *(UFG::SimObjectCVBase **)(56i64
                                          * *(unsigned __int8 *)((unsigned int)this->m_iTargetType
                                                               + *(_QWORD *)&m_pComponent[1].m_Flags
                                                               + 8i64)
                                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                          + 40);
  }
  if ( !m_pPointer )
    return 0;
  if ( this->mBoneName.mUID == UFG::gNullQSymbolUC.mUID || this->m_bRelativeToTarget )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( !m_pTransformNodeComponent )
      return 0;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer->m_pTransformNodeComponent);
    v16 = m_pTransformNodeComponent->mWorldTransform.v1;
    v17 = m_pTransformNodeComponent->mWorldTransform.v2;
    v18 = m_pTransformNodeComponent->mWorldTransform.v3;
    outRelativeToMatrix->v0 = m_pTransformNodeComponent->mWorldTransform.v0;
    outRelativeToMatrix->v1 = v16;
    outRelativeToMatrix->v2 = v17;
    outRelativeToMatrix->v3 = v18;
    return 1;
  }
  v10 = m_pPointer->m_Flags;
  if ( (v10 & 0x4000) != 0 || v10 < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
  }
  else if ( (v10 & 0x2000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
  }
  else if ( (v10 & 0x1000) != 0 )
  {
    ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
  }
  mCreature = ComponentOfTypeHK->mCreature;
  if ( !mCreature )
    return 1;
  if ( mCreature->mPose.mRigHandle.mData )
  {
    BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, this->mBoneName.mUID);
    Creature::GetTransform(mCreature, BoneID, outRelativeToMatrix);
  }
  else
  {
    Creature::GetTransform(mCreature, -1, outRelativeToMatrix);
  }
  return 1;
}

// File Line: 9291
// RVA: 0x148BED0
__int64 dynamic_initializer_for__RelativePositionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RelativePositionCondition", 0xFFFFFFFF);
  RelativePositionCondition::sClassNameUID = result;
  return result;
}

// File Line: 9293
// RVA: 0x2895B0
bool __fastcall RelativePositionCondition::Match(RelativePositionCondition *this, ActionContext *pContext)
{
  char v4; // bl
  char v5; // al
  bool v6; // bl
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v10; // [rsp+20h] [rbp-88h] BYREF
  float v11; // [rsp+24h] [rbp-84h]
  float v12; // [rsp+28h] [rbp-80h]
  UFG::qVector3 v2; // [rsp+30h] [rbp-78h] BYREF
  UFG::qVector3 v1; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 v15; // [rsp+50h] [rbp-58h] BYREF
  float v16; // [rsp+60h] [rbp-48h]
  float v17; // [rsp+64h] [rbp-44h]
  float v18; // [rsp+68h] [rbp-40h]
  float v19; // [rsp+80h] [rbp-28h]
  float v20; // [rsp+84h] [rbp-24h]
  float v21; // [rsp+88h] [rbp-20h]

  v4 = ((__int64 (__fastcall *)(RelativePositionCondition *, ActionContext *, float *))this->vfptr[1].GetResourceOwner)(
         this,
         pContext,
         &v10);
  v5 = ((__int64 (__fastcall *)(RelativePositionCondition *, ActionContext *, UFG::qVector3 *))this->vfptr[2].FindWithOldPath)(
         this,
         pContext,
         &v15);
  if ( !v4 || !v5 )
    return 0;
  v2 = v15;
  v1.x = v10 - v19;
  v1.y = v11 - v20;
  v1.z = v12 - v21;
  v6 = (float)((float)((float)(v17 * (float)(v11 - v20)) + (float)(v16 * (float)(v10 - v19)))
             + (float)(v18 * (float)(v12 - v21))) > 0.0;
  v7 = UFG::qAngleBetween(&v1, &v2);
  if ( v6 )
    v7 = 6.2831855 - v7;
  v8 = v7 - this->m_fDirection;
  if ( v8 < 0.0 )
    v8 = v8 + 6.2831855;
  if ( v8 >= 3.1415927 )
    v8 = 6.2831855 - v8;
  return v8 <= this->m_fAngleRange;
}

// File Line: 9352
// RVA: 0x148AFD0
__int64 dynamic_initializer_for__HitLocation::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitLocation", 0xFFFFFFFF);
  HitLocation::sClassNameUID = result;
  return result;
}

// File Line: 9359
// RVA: 0x27D7A0
bool __fastcall HitLocation::GetPosition(HitLocation *this, ActionContext *pContext, UFG::qVector3 *outPosition)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *((float *)&m_pComponent[6].vfptr + 1);
  v8 = *(float *)&m_pComponent[6].m_SafePointerList.mNode.mPrev;
  outPosition->x = *(float *)&m_pComponent[6].vfptr;
  result = 1;
  outPosition->y = v7;
  outPosition->z = v8;
  return result;
}

// File Line: 9401
// RVA: 0x148AFB0
__int64 dynamic_initializer_for__HitImpulse::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitImpulse", 0xFFFFFFFF);
  HitImpulse::sClassNameUID = result;
  return result;
}

// File Line: 9408
// RVA: 0x27D670
bool __fastcall HitImpulse::GetPosition(HitImpulse *this, ActionContext *pContext, UFG::qVector3 *outPosition)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // rax
  UFG::TransformNodeComponent *mNext; // rbx
  int v9; // xmm6_4
  int v10; // xmm7_4
  int v11; // xmm8_4
  bool result; // al
  float v13; // xmm7_4
  float v14; // xmm8_4

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  mNext = (UFG::TransformNodeComponent *)pContext->mSimObject.m_pPointer;
  v9 = HIDWORD(m_pComponent[6].m_SafePointerList.mNode.mPrev) ^ _xmm[0];
  v10 = LODWORD(m_pComponent[6].m_SafePointerList.mNode.mNext) ^ _xmm[0];
  v11 = HIDWORD(m_pComponent[6].m_SafePointerList.mNode.mNext) ^ _xmm[0];
  if ( mNext )
    mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
  result = 1;
  v13 = *(float *)&v10 + mNext->mWorldTransform.v3.y;
  v14 = *(float *)&v11 + mNext->mWorldTransform.v3.z;
  outPosition->x = *(float *)&v9 + mNext->mWorldTransform.v3.x;
  outPosition->y = v13;
  outPosition->z = v14;
  return result;
}

// File Line: 9428
// RVA: 0x27DA80
bool __fastcall HitLocation::GetRelativeToMatrix(
        HitLocation *this,
        ActionContext *pContext,
        UFG::qMatrix44 *outRelativeToMatrix)
{
  UFG::SimObject *m_pPointer; // rbx
  bool result; // al
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1

  m_pPointer = pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
    m_pPointer = (UFG::SimObject *)m_pPointer->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
  result = 1;
  v6 = *(UFG::qVector4 *)&m_pPointer[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
  v7 = *(UFG::qVector4 *)&m_pPointer[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
  v8 = *(UFG::qVector4 *)m_pPointer[1].mNode.mChild;
  outRelativeToMatrix->v0 = *(UFG::qVector4 *)&m_pPointer[1].vfptr;
  outRelativeToMatrix->v1 = v6;
  outRelativeToMatrix->v2 = v7;
  outRelativeToMatrix->v3 = v8;
  return result;
}

// File Line: 9450
// RVA: 0x148C550
__int64 dynamic_initializer_for__TargetPropInteractAvailableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPropInteractAvailableCondition", 0xFFFFFFFF);
  TargetPropInteractAvailableCondition::sClassNameUID = result;
  return result;
}

// File Line: 9455
// RVA: 0x278E90
void __fastcall TargetPropInteractAvailableCondition::TargetPropInteractAvailableCondition(
        TargetPropInteractAvailableCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPropInteractAvailableCondition::`vftable;
}

// File Line: 9460
// RVA: 0x28E4C0
bool __fastcall TargetPropInteractAvailableCondition::Match(
        TargetPropInteractAvailableCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::PropInteractComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 48i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 )
    goto LABEL_14;
  if ( v8 >= 0 )
  {
    if ( (v8 & 0x2000) != 0 )
    {
      ComponentOfTypeHK = (UFG::PropInteractComponent *)v7->m_Components.p[13].m_pComponent;
    }
    else
    {
      if ( (v8 & 0x1000) != 0 )
      {
LABEL_14:
        ComponentOfTypeHK = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v7,
                                                            UFG::PropInteractComponent::_TypeUID);
        goto LABEL_21;
      }
      ComponentOfTypeHK = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                          v7,
                                                          UFG::PropInteractComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = (UFG::PropInteractComponent *)v7->m_Components.p[33].m_pComponent;
  }
LABEL_21:
  if ( ComponentOfTypeHK )
    return UFG::PropInteractComponent::IsInteractionAvailable(ComponentOfTypeHK, pContext);
  return 0;
}

// File Line: 9492
// RVA: 0x148C570
__int64 dynamic_initializer_for__TargetPropInteractOrientationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPropInteractOrientationCondition", 0xFFFFFFFF);
  TargetPropInteractOrientationCondition::sClassNameUID = result;
  return result;
}

// File Line: 9503
// RVA: 0x278EC0
void __fastcall TargetPropInteractOrientationCondition::TargetPropInteractOrientationCondition(
        TargetPropInteractOrientationCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPropInteractOrientationCondition::`vftable;
  this->m_SyncName.mUID = -1;
  *(_QWORD *)&this->m_fMaxDistance = 0i64;
}

// File Line: 9508
// RVA: 0x28E5F0
bool __fastcall TargetPropInteractOrientationCondition::Match(
        TargetPropInteractOrientationCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::PropInteractComponent *v11; // rbx
  float fMaxAngleBetween; // xmm6_4
  float m_fMaxDistance; // xmm7_4

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  m_pComponent = 0i64;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  if ( !m_pTransformNodeComponent )
    return 0;
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 48i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    goto LABEL_15;
  if ( v9 < 0 )
  {
    v11 = (UFG::PropInteractComponent *)v8->m_Components.p[33].m_pComponent;
    goto LABEL_23;
  }
  if ( (v9 & 0x2000) != 0 )
  {
    v11 = (UFG::PropInteractComponent *)v8->m_Components.p[13].m_pComponent;
    goto LABEL_23;
  }
  if ( (v9 & 0x1000) != 0 )
LABEL_15:
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::PropInteractComponent::_TypeUID);
  else
    ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::PropInteractComponent::_TypeUID);
  v11 = (UFG::PropInteractComponent *)ComponentOfType;
LABEL_23:
  if ( v11 )
  {
    fMaxAngleBetween = this->m_fMaxAngleBetween;
    m_fMaxDistance = this->m_fMaxDistance;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    return UFG::PropInteractComponent::IsOrientedToInteract(
             v11,
             &m_pTransformNodeComponent->mWorldTransform,
             &this->m_SyncName,
             m_fMaxDistance,
             fMaxAngleBetween);
  }
  return 0;
}

// File Line: 9545
// RVA: 0x148C3D0
__int64 dynamic_initializer_for__TargetIsLockedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsLockedCondition", 0xFFFFFFFF);
  TargetIsLockedCondition::sClassNameUID = result;
  return result;
}

// File Line: 9551
// RVA: 0x28CBD0
bool __fastcall TargetIsLockedCondition::Match(TargetIsLockedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v6; // rax
  __int64 v7; // r8
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(_QWORD *)&m_pComponent[1].m_TypeUID
         + 56i64
         * *(unsigned __int8 *)((unsigned __int8)this->m_eTargetType.mValue + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64);
      if ( *(_QWORD *)(v7 + 40) )
      {
        if ( *(_BYTE *)(v7 + 49) )
          return 1;
      }
    }
  }
  return result;
}

// File Line: 9576
// RVA: 0x148C870
__int64 dynamic_initializer_for__TargetVelocityRelativeToCollisionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetVelocityRelativeToCollisionCondition", 0xFFFFFFFF);
  TargetVelocityRelativeToCollisionCondition::sClassNameUID = result;
  return result;
}

// File Line: 9584
// RVA: 0x27BC70
bool __fastcall TargetVelocityRelativeToCollisionCondition::GetBaseMatrix(
        TargetVelocityRelativeToCollisionCondition *this,
        ActionContext *pContext,
        UFG::qMatrix44 *outBaseMatrix)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // rdx
  UFG::qVector3 result; // [rsp+30h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v8;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v9 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)((unsigned __int8)this->m_eTargetType.mValue
                                               + *(_QWORD *)&m_pComponent[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  if ( !v9 )
    return 0;
  UFG::GetVelocity(&result, v9);
  result.z = 0.0;
  return UFG::qMakeMatrix(outBaseMatrix, &result, &UFG::qVector3::msAxisZ, &UFG::qVector3::msZero, 0.001);
}

// File Line: 9661
// RVA: 0x148AF50
__int64 dynamic_initializer_for__HitCollisionVelocityRelativeToNormal::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitCollisionVelocityRelativeToNormal", 0xFFFFFFFF);
  HitCollisionVelocityRelativeToNormal::sClassNameUID = result;
  return result;
}

// File Line: 9668
// RVA: 0x27B9A0
bool __fastcall HitCollisionVelocityRelativeToNormal::GetBaseMatrix(
        HitCollisionVelocityRelativeToNormal *this,
        ActionContext *pContext,
        UFG::qMatrix44 *outBaseMatrix)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  float v7; // xmm1_4
  UFG::qVector3 forward; // [rsp+30h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(float *)&m_pComponent[6].m_NameUID;
  LODWORD(forward.x) = m_pComponent[6].m_TypeUID;
  forward.y = v7;
  forward.z = 0.0;
  return UFG::qMakeMatrix(outBaseMatrix, &forward, &UFG::qVector3::msAxisZ, &UFG::qVector3::msZero, 0.001);
}

// File Line: 9700
// RVA: 0x27D950
bool __fastcall TargetVelocityRelativeToCollisionCondition::GetRelativeToMatrix(
        TargetVelocityRelativeToCollisionCondition *this,
        ActionContext *pContext,
        UFG::qMatrix44 *outRelativeToMatrix)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v8; // rax
  float v9; // xmm1_4
  UFG::qVector3 forward; // [rsp+30h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
    m_pComponent = v8;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v9 = m_pTransformNodeComponent->mWorldTransform.v3.y - *((float *)&m_pComponent[6].vfptr + 1);
  forward.x = m_pTransformNodeComponent->mWorldTransform.v3.x - *(float *)&m_pComponent[6].vfptr;
  forward.y = v9;
  forward.z = 0.0;
  return UFG::qMakeMatrix(outRelativeToMatrix, &forward, &UFG::qVector3::msAxisZ, &UFG::qVector3::msZero, 0.001);
}

// File Line: 9742
// RVA: 0x148AFF0
__int64 dynamic_initializer_for__HitLocationTargettedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitLocationTargettedCondition", 0xFFFFFFFF);
  HitLocationTargettedCondition::sClassNameUID = result;
  return result;
}

// File Line: 9747
// RVA: 0x277160
void __fastcall HitLocationTargettedCondition::HitLocationTargettedCondition(HitLocationTargettedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HitLocationTargettedCondition::`vftable;
}

// File Line: 9752
// RVA: 0x282320
bool __fastcall HitLocationTargettedCondition::Match(HitLocationTargettedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
            ComponentOfTypeHK)
        && ComponentOfTypeHK[5].m_SafePointerList.mNode.mNext != 0i64;
  return result;
}

// File Line: 9778
// RVA: 0x148B030
__int64 dynamic_initializer_for__HitProjectileReactionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitProjectileReactionCondition", 0xFFFFFFFF);
  HitProjectileReactionCondition::sClassNameUID = result;
  return result;
}

// File Line: 9785
// RVA: 0x2771C0
void __fastcall HitProjectileReactionCondition::HitProjectileReactionCondition(HitProjectileReactionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HitProjectileReactionCondition::`vftable;
  this->m_eProjectileReaction.mValue = 0;
}

// File Line: 9790
// RVA: 0x282460
bool __fastcall HitProjectileReactionCondition::Match(HitProjectileReactionCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
            ComponentOfTypeHK && (mPrev = ComponentOfTypeHK[5].m_SafePointerList.mNode.mPrev) != 0i64)
        && (unsigned __int8)this->m_eProjectileReaction.mValue == *(_DWORD *)(*((_QWORD *)&mPrev[11].mPrev->mNext
                                                                              + HIDWORD(mPrev[10].mNext))
                                                                            + 152i64);
  return result;
}

// File Line: 9821
// RVA: 0x148B010
__int64 dynamic_initializer_for__HitProjectileIsExplosiveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitProjectileIsExplosiveCondition", 0xFFFFFFFF);
  HitProjectileIsExplosiveCondition::sClassNameUID = result;
  return result;
}

// File Line: 9825
// RVA: 0x277190
void __fastcall HitProjectileIsExplosiveCondition::HitProjectileIsExplosiveCondition(
        HitProjectileIsExplosiveCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HitProjectileIsExplosiveCondition::`vftable;
}

// File Line: 9830
// RVA: 0x2823B0
bool __fastcall HitProjectileIsExplosiveCondition::Match(
        HitProjectileIsExplosiveCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
            ComponentOfTypeHK && (mPrev = ComponentOfTypeHK[5].m_SafePointerList.mNode.mPrev) != 0i64)
        && *(_DWORD *)(*((_QWORD *)&mPrev[11].mPrev->mNext + HIDWORD(mPrev[10].mNext)) + 108i64) != -1;
  return result;
}

// File Line: 9859
// RVA: 0x148B070
__int64 dynamic_initializer_for__HitProjectileWeaponTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitProjectileWeaponTypeCondition", 0xFFFFFFFF);
  HitProjectileWeaponTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 9866
// RVA: 0x277240
void __fastcall HitProjectileWeaponTypeCondition::HitProjectileWeaponTypeCondition(
        HitProjectileWeaponTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HitProjectileWeaponTypeCondition::`vftable;
  this->m_eSimObjectWeaponType = 0;
}

// File Line: 9871
// RVA: 0x282640
bool __fastcall HitProjectileWeaponTypeCondition::Match(
        HitProjectileWeaponTypeCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
        ComponentOfTypeHK) )
  {
    mPrev = ComponentOfTypeHK[5].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    mPrev = 0i64;
  }
  if ( mPrev )
    LOBYTE(mPrev) = **((_DWORD **)&mPrev[11].mPrev->mNext + HIDWORD(mPrev[10].mNext)) == this->m_eSimObjectWeaponType;
  return (char)mPrev;
}

// File Line: 9899
// RVA: 0x148B050
__int64 dynamic_initializer_for__HitProjectileWeaponInventoryTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitProjectileWeaponInventoryTypeCondition", 0xFFFFFFFF);
  HitProjectileWeaponInventoryTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 9906
// RVA: 0x277200
void __fastcall HitProjectileWeaponInventoryTypeCondition::HitProjectileWeaponInventoryTypeCondition(
        HitProjectileWeaponInventoryTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HitProjectileWeaponInventoryTypeCondition::`vftable;
  this->m_eInventoryItemType.mValue = 0;
}

// File Line: 9911
// RVA: 0x282520
bool __fastcall HitProjectileWeaponInventoryTypeCondition::Match(
        HitProjectileWeaponInventoryTypeCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::SimObjectGame *mNext; // r8
  __int16 v9; // cx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  m_pComponent = 0i64;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
        ComponentOfTypeHK) )
  {
    mPrev = ComponentOfTypeHK[5].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    mPrev = 0i64;
  }
  if ( mPrev )
  {
    mNext = (UFG::SimObjectGame *)mPrev[2].mNext;
    if ( mNext )
    {
      v9 = mNext->m_Flags;
      if ( (v9 & 0x4000) == 0 && v9 >= 0 )
      {
        if ( (v9 & 0x2000) != 0 )
        {
          m_pComponent = mNext->m_Components.p[11].m_pComponent;
        }
        else
        {
          if ( (v9 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(mNext, UFG::InventoryItemComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(mNext, UFG::InventoryItemComponent::_TypeUID);
          m_pComponent = ComponentOfType;
        }
      }
    }
  }
  return m_pComponent && LODWORD(m_pComponent[1].m_pSimObject) == this->m_eInventoryItemType.mValue;
}

// File Line: 9940
// RVA: 0x148AF90
__int64 dynamic_initializer_for__HitExplosionCanTriggerVehicleExplosion::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitExplosionCanTriggerVehicleExplosion", 0xFFFFFFFF);
  HitExplosionCanTriggerVehicleExplosion::sClassNameUID = result;
  return result;
}

// File Line: 9944
// RVA: 0x277130
void __fastcall HitExplosionCanTriggerVehicleExplosion::HitExplosionCanTriggerVehicleExplosion(
        HitExplosionCanTriggerVehicleExplosion *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HitExplosionCanTriggerVehicleExplosion::`vftable;
}

// File Line: 9949
// RVA: 0x282280
bool __fastcall HitExplosionCanTriggerVehicleExplosion::Match(
        HitExplosionCanTriggerVehicleExplosion *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
            ComponentOfTypeHK && (mPrev = ComponentOfTypeHK[7].m_SafePointerList.mNode.mPrev) != 0i64)
        && (BYTE4(mPrev[11].mNext) & 2) != 0;
  return result;
}

// File Line: 9972
// RVA: 0x148AF70
__int64 dynamic_initializer_for__HitDistanceFromExplosionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitDistanceFromExplosionCondition", 0xFFFFFFFF);
  HitDistanceFromExplosionCondition::sClassNameUID = result;
  return result;
}

// File Line: 9981
// RVA: 0x2770F0
void __fastcall HitDistanceFromExplosionCondition::HitDistanceFromExplosionCondition(
        HitDistanceFromExplosionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HitDistanceFromExplosionCondition::`vftable;
  this->m_fDistance = 0.0;
  this->m_InEqualityOperator.mValue = 3;
}

// File Line: 9985
// RVA: 0x2821D0
char __fastcall HitDistanceFromExplosionCondition::Match(
        HitDistanceFromExplosionCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v6; // xmm2_4

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
        ComponentOfTypeHK && (v6 = *(float *)&ComponentOfTypeHK[7].vfptr, v6 >= 0.0)) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)this->m_InEqualityOperator.mValue,
             this->m_fDistance * this->m_fDistance,
             v6);
  }
  else
  {
    return 0;
  }
}

// File Line: 10010
// RVA: 0x148AAB0
__int64 dynamic_initializer_for__CharacterTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CharacterTypeCondition", 0xFFFFFFFF);
  CharacterTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 10015
// RVA: 0x27FF30
bool __fastcall CharacterTypeCondition::Match(CharacterTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) == 0
            ? ((m_Flags & 0x1000) == 0
             ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                    m_pPointer,
                                    UFG::SimObjectPropertiesComponent::_TypeUID))
             : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    m_pPointer,
                                    UFG::SimObjectPropertiesComponent::_TypeUID)),
               m_pComponent = ComponentOfType)
            : (m_pComponent = m_pPointer->m_Components.p[4].m_pComponent))
           : (m_pComponent = m_pPointer->m_Components.p[3].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[3].m_pComponent),
            m_pComponent && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 1)
        && LODWORD(m_pComponent[3].vfptr) == (unsigned __int8)this->m_eCharacterType.mValue;
  return result;
}

// File Line: 10043
// RVA: 0x148B350
__int64 dynamic_initializer_for__IsCopCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsCopCondition", 0xFFFFFFFF);
  IsCopCondition::sClassNameUID = result;
  return result;
}

// File Line: 10046
// RVA: 0x283B10
bool __fastcall IsCopCondition::Match(IsCopCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[17].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CopUnitComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CopUnitComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[17].m_pComponent;
    }
    if ( m_pComponent )
      return 1;
  }
  return result;
}

// File Line: 10068
// RVA: 0x148B2F0
__int64 dynamic_initializer_for__IsCameraCollidingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsCameraCollidingCondition", 0xFFFFFFFF);
  IsCameraCollidingCondition::sClassNameUID = result;
  return result;
}

// File Line: 10071
// RVA: 0x283A00
bool __fastcall IsCameraCollidingCondition::Match(IsCameraCollidingCondition *this, ActionContext *context)
{
  UFG::GameCameraComponent *CurrentGameCamera; // rax

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  if ( CurrentGameCamera )
    LOBYTE(CurrentGameCamera) = CurrentGameCamera->mInCollision;
  return (char)CurrentGameCamera;
}

// File Line: 10095
// RVA: 0x148B310
__int64 dynamic_initializer_for__IsCameraTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsCameraTypeCondition", 0xFFFFFFFF);
  IsCameraTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 10098
// RVA: 0x277670
void __fastcall IsCameraTypeCondition::IsCameraTypeCondition(IsCameraTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsCameraTypeCondition::`vftable;
  this->mCameraType.mValue = 0;
}

// File Line: 10101
// RVA: 0x283A30
bool __fastcall IsCameraTypeCondition::Match(IsCameraTypeCondition *this, ActionContext *context)
{
  UFG::GameCameraComponent *CurrentGameCamera; // r8
  unsigned int v4; // edx

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  if ( !CurrentGameCamera )
    return 0;
  switch ( this->mCameraType.mValue )
  {
    case 0:
      v4 = UFG::FollowCameraComponent::_FollowCameraComponentTypeUID;
      break;
    case 1:
      v4 = UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID;
      break;
    case 2:
      v4 = UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID;
      break;
    case 3:
      v4 = UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID;
      break;
    case 4:
      v4 = UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID;
      break;
    case 5:
      v4 = UFG::TurfCameraComponent::_TurfCameraComponentTypeUID;
      break;
    default:
      return 0;
  }
  return UFG::SimComponent::IsType(CurrentGameCamera, v4);
}

// File Line: 10157
// RVA: 0x148B330
__int64 dynamic_initializer_for__IsClassTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsClassTypeCondition", 0xFFFFFFFF);
  IsClassTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 10162
// RVA: 0x2776B0
void __fastcall IsClassTypeCondition::IsClassTypeCondition(IsClassTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsClassTypeCondition::`vftable;
  this->mClassType.mUID = -1;
  this->mClassType = UFG::gNullQSymbol;
}

// File Line: 10167
// RVA: 0x283AD0
char __fastcall IsClassTypeCondition::Match(IsClassTypeCondition *this, ActionContext *context)
{
  UFG::qSymbol *p_mClassType; // r8
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx

  p_mClassType = &this->mClassType;
  if ( this->mClassType.mUID == UFG::gNullQSymbol.mUID )
    return 0;
  m_pSceneObj = context->mSimObject.m_pPointer->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  return UFG::SimObjectUtility::IsClassType(mpWritableProperties, p_mClassType);
}

// File Line: 10190
// RVA: 0x148AE50
__int64 dynamic_initializer_for__FightingClassCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FightingClassCondition", 0xFFFFFFFF);
  FightingClassCondition::sClassNameUID = result;
  return result;
}

// File Line: 10195
// RVA: 0x281D00
bool __fastcall FightingClassCondition::Match(FightingClassCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) == 0
            ? ((m_Flags & 0x1000) == 0
             ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                    m_pPointer,
                                    UFG::SimObjectPropertiesComponent::_TypeUID))
             : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    m_pPointer,
                                    UFG::SimObjectPropertiesComponent::_TypeUID)),
               m_pComponent = ComponentOfType)
            : (m_pComponent = m_pPointer->m_Components.p[4].m_pComponent))
           : (m_pComponent = m_pPointer->m_Components.p[3].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[3].m_pComponent),
            m_pComponent && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 1)
        && HIDWORD(m_pComponent[3].vfptr) == (unsigned __int8)this->m_eFightingClass.mValue;
  return result;
}

// File Line: 10225
// RVA: 0x278290
void __fastcall PropertyConditionBase::PropertyConditionBase(PropertyConditionBase *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PropertyConditionBase::`vftable;
  this->m_PropertySymbol.mUID = -1;
  *(_WORD *)&this->m_PeriodicallyRecachePropertyValue = 0;
  *(_QWORD *)&this->m_PropertyValueUID = 0i64;
  this->m_NextTimeToCachePropertyValueUID = 0;
  this->m_CachePropertyValue = 1;
  this->m_MinTimeBeforeRecachePropertyValue = 1.0;
  this->m_MaxTimeBeforeRecachePropertyValue = 2.0;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 10242
// RVA: 0x294070
void __fastcall PropertyConditionBase::ResolveReferences(PropertyConditionBase *this, ActionNode *action_node)
{
  __int64 v3; // rax
  __int64 v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx
  UFG::eActionTreeMemoryElementType v6; // eax
  unsigned int ValueUID; // eax
  unsigned int m_PropertyValueHasBeenReadUID; // ecx
  unsigned int v9; // eax
  bool v10; // zf

  if ( !this->m_InitState.mValue )
  {
    v3 = ((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
    v4 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 152i64))(v3);
    p_m_MyRoot = &this->m_MyRoot;
    if ( v4 )
      v4 -= (__int64)p_m_MyRoot;
    p_m_MyRoot->mOffset = v4;
    if ( this->m_CachePropertyValue )
    {
      v6 = (UFG::eActionTreeMemoryElementType)this->vfptr[1].GetResourceOwner(this);
      ValueUID = UFG::ActionTreeComponentBase::MakeValueUID(this->m_PropertyValueUID, v6);
      m_PropertyValueHasBeenReadUID = this->m_PropertyValueHasBeenReadUID;
      this->m_PropertyValueUID = ValueUID;
      v9 = UFG::ActionTreeComponentBase::MakeValueUID(m_PropertyValueHasBeenReadUID, eACTION_TREE_MEMORY_ELEMENT_BOOL);
      v10 = this->m_PeriodicallyRecachePropertyValue == 0;
      this->m_PropertyValueHasBeenReadUID = v9;
      if ( !v10 )
        this->m_NextTimeToCachePropertyValueUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                                    this->m_NextTimeToCachePropertyValueUID,
                                                    eACTION_TREE_MEMORY_ELEMENT_FLOAT);
    }
    this->m_InitState.mValue = 1;
  }
}

// File Line: 10322
// RVA: 0x294390
void __fastcall PropertyConditionBase::ValueHasBeenReadFromPropertySet(
        PropertyConditionBase *this,
        ActionContext *action_context)
{
  float v2; // xmm6_4
  __int64 mOffset; // rax
  char *v6; // rdi
  UFG::ActionTreeComponentBase *v7; // rdx
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  unsigned int v10; // r9d
  __int64 v11; // rax
  UFG::ActionTreeComponentBase *v12; // rdx
  UFG::ActionTreeComponentBase *v13; // rcx
  bool value; // [rsp+20h] [rbp-18h]

  if ( this->m_CachePropertyValue )
  {
    mOffset = this->m_MyRoot.mOffset;
    v6 = 0i64;
    if ( mOffset )
      v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v7 = 0i64;
    if ( mOffset )
      v8 = (char *)&this->m_MyRoot + mOffset;
    else
      v8 = 0i64;
    v9 = action_context->mActionTreeComponentBase[v8[236]];
    if ( !v9 )
      v9 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v9,
      v7,
      (ActionNodeRoot *)this->m_PropertyValueHasBeenReadUID,
      1u,
      value);
    if ( this->m_PeriodicallyRecachePropertyValue )
    {
      UFG::GetRandomNumberInRange(this->m_MinTimeBeforeRecachePropertyValue, this->m_MaxTimeBeforeRecachePropertyValue);
      v11 = this->m_MyRoot.mOffset;
      if ( v11 )
        v12 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v11);
      else
        v12 = 0i64;
      if ( v11 )
        v6 = (char *)&this->m_MyRoot + v11;
      v13 = action_context->mActionTreeComponentBase[v6[236]];
      if ( !v13 )
        v13 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
        v13,
        v12,
        (ActionNodeRoot *)this->m_NextTimeToCachePropertyValueUID,
        v10,
        v2);
    }
  }
}

// File Line: 10344
// RVA: 0x27B0C0
bool __fastcall PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
        PropertyConditionBase *this,
        ActionContext *action_context)
{
  float *v2; // xmm6_8
  __int64 mOffset; // rax
  char *v6; // rdi
  UFG::ActionTreeComponentBase *v7; // rdx
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  bool v10; // bp
  __int64 v11; // rax
  float mSimTime_Temp; // xmm6_4
  UFG::ActionTreeComponentBase *v13; // rdx
  UFG::ActionTreeComponentBase *v14; // rcx
  bool result; // al
  bool *value; // [rsp+20h] [rbp-28h]
  float *valuea; // [rsp+20h] [rbp-28h]
  unsigned int value_uid; // [rsp+50h] [rbp+8h] BYREF
  unsigned int v19; // [rsp+60h] [rbp+18h] BYREF

  if ( !this->m_CachePropertyValue )
    return 1;
  mOffset = this->m_MyRoot.mOffset;
  v6 = 0i64;
  LOBYTE(value_uid) = 0;
  if ( mOffset )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v7 = 0i64;
  if ( mOffset )
    v8 = (char *)&this->m_MyRoot + mOffset;
  else
    v8 = 0i64;
  v9 = action_context->mActionTreeComponentBase[v8[236]];
  if ( !v9 )
    v9 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v9,
    v7,
    (ActionNodeRoot *)this->m_PropertyValueHasBeenReadUID,
    (unsigned int)&value_uid,
    value);
  v10 = (_BYTE)value_uid == 0;
  if ( !this->m_PeriodicallyRecachePropertyValue )
    return (_BYTE)value_uid == 0;
  v11 = this->m_MyRoot.mOffset;
  valuea = v2;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  *(float *)&v19 = FLOAT_N99999_0;
  if ( v11 )
    v13 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v11);
  else
    v13 = 0i64;
  if ( v11 )
    v6 = (char *)&this->m_MyRoot + v11;
  v14 = action_context->mActionTreeComponentBase[v6[236]];
  if ( !v14 )
    v14 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v14,
    v13,
    (ActionNodeRoot *)this->m_NextTimeToCachePropertyValueUID,
    (unsigned int)&v19,
    valuea);
  result = v10;
  if ( mSimTime_Temp > *(float *)&v19 )
    return 1;
  return result;
}

// File Line: 10378
// RVA: 0x1491AF0
__int64 dynamic_initializer_for__gMemImageWarnings__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMemImageWarnings__);
}

// File Line: 10423
// RVA: 0x278F00
void __fastcall TargetPropertyConditionBase::TargetPropertyConditionBase(TargetPropertyConditionBase *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PropertyConditionBase::`vftable;
  this->m_PropertySymbol.mUID = -1;
  *(_WORD *)&this->m_PeriodicallyRecachePropertyValue = 0;
  *(_QWORD *)&this->m_PropertyValueUID = 0i64;
  this->m_NextTimeToCachePropertyValueUID = 0;
  this->m_CachePropertyValue = 1;
  this->m_MinTimeBeforeRecachePropertyValue = 1.0;
  this->m_MaxTimeBeforeRecachePropertyValue = 2.0;
  this->m_MyRoot.mOffset = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPropertyConditionBase::`vftable;
  this->m_NestedPropertySet.mUID = -1;
  this->m_TargetType.mValue = 0;
  this->m_PreviousTargetUID = 0;
  this->m_MyRoot.mOffset = 0i64;
}

// File Line: 10434
// RVA: 0x2941C0
void __fastcall TargetPropertyConditionBase::ResolveReferences(
        TargetPropertyConditionBase *this,
        ActionNode *action_node)
{
  Expression::IMemberMap *v4; // rax
  UFG::qOffset64<ActionNodeRoot *> *p_m_MyRoot; // rcx

  v4 = action_node->vfptr[1].GetResourceOwner(action_node);
  p_m_MyRoot = &this->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - (__int64)p_m_MyRoot);
  p_m_MyRoot->mOffset = (__int64)v4;
  if ( this->m_CachePropertyValue )
    this->m_PreviousTargetUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                  this->m_PreviousTargetUID,
                                  eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  PropertyConditionBase::ResolveReferences(this, action_node);
}

// File Line: 10455
// RVA: 0x27B1F0
char __fastcall TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
        TargetPropertyConditionBase *this,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v5; // rbx
  UFG::ActionTreeComponentBase *v6; // rdx
  char *v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rcx
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v13; // zf
  UFG::SimObjectGame *v14; // rcx
  __int64 v15; // r9
  __int64 v16; // rax
  UFG::ActionTreeComponentBase *v17; // rdx
  UFG::ActionTreeComponentBase *v18; // rcx
  UFG::SimObject **v20; // [rsp+20h] [rbp-8h]
  UFG::SimObject *v21; // [rsp+20h] [rbp-8h]
  __int64 value_uid; // [rsp+30h] [rbp+8h] BYREF

  if ( !this->m_CachePropertyValue )
    return PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context);
  mOffset = this->m_MyRoot.mOffset;
  v5 = 0i64;
  value_uid = 0i64;
  if ( mOffset )
    v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v6 = 0i64;
  if ( mOffset )
    v7 = (char *)&this->m_MyRoot + mOffset;
  else
    v7 = 0i64;
  v8 = action_context->mActionTreeComponentBase[v7[236]];
  if ( !v8 )
    v8 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
    v8,
    v6,
    (ActionNodeRoot *)this->m_PreviousTargetUID,
    (unsigned int)&value_uid,
    v20);
  m_pPointer = action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context);
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer,
                            UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v13 = (m_Flags & 0x1000) == 0;
      v14 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
      ComponentOfTypeHK = v13
                        ? UFG::SimObject::GetComponentOfType(v14, UFG::TargetingSystemBaseComponent::_TypeUID)
                        : UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    m_pComponent = ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context);
  v15 = *(_QWORD *)(56i64
                  * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                       + 8i64)
                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                  + 40);
  if ( value_uid == v15 )
    return PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context);
  v16 = this->m_MyRoot.mOffset;
  if ( v16 )
    v17 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v16);
  else
    v17 = 0i64;
  if ( v16 )
    v5 = (char *)&this->m_MyRoot + v16;
  v18 = action_context->mActionTreeComponentBase[v5[236]];
  if ( !v18 )
    v18 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
    v18,
    v17,
    (ActionNodeRoot *)this->m_PreviousTargetUID,
    v15,
    v21);
  return 1;
}

// File Line: 10488
// RVA: 0x27D860
UFG::qPropertySet *__fastcall TargetPropertyConditionBase::GetPropertySet(
        TargetPropertyConditionBase *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rcx
  UFG::qPropertySet *result; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0i64;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0i64;
  v7 = *(_QWORD *)(56i64
                 * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                      + *(_QWORD *)&m_pComponent[1].m_Flags
                                      + 8i64)
                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                 + 40);
  if ( v7 && (v8 = *(_QWORD *)(v7 + 80)) != 0 )
  {
    result = *(UFG::qPropertySet **)(v8 + 144);
    if ( !result )
      result = *(UFG::qPropertySet **)(v8 + 152);
  }
  else
  {
    result = 0i64;
  }
  if ( this->m_NestedPropertySet.mUID != -1 )
  {
    if ( result )
      return PropertyUtils::Get<UFG::qPropertySet>(
               result,
               (UFG::qArray<unsigned long,0> *)&this->m_NestedPropertySet,
               DEPTH_RECURSE);
    return 0i64;
  }
  return result;
}

// File Line: 10543
// RVA: 0x148BDD0
__int64 dynamic_initializer_for__PropertyBooleanCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PropertyBooleanCondition", 0xFFFFFFFF);
  PropertyBooleanCondition::sClassNameUID = result;
  return result;
}

// File Line: 10552
// RVA: 0x293810
bool __fastcall PropertyBooleanCondition::ReadValueFromPropertySet(
        PropertyBooleanCondition *this,
        ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v7; // rsi
  __int64 mOffset; // rcx
  char *v9; // rdx
  UFG::ActionTreeComponentBase *v10; // r10
  UFG::ActionTreeComponentBase *v11; // rcx
  bool v13; // [rsp+20h] [rbp-8h]

  m_pPointer = action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_pSceneObj = m_pPointer->m_pSceneObj;
  if ( !m_pSceneObj )
    return 0;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    if ( !mpWritableProperties )
      return 0;
  }
  v7 = PropertyUtils::Get<bool>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&this->m_PropertySymbol,
         DEPTH_RECURSE);
  if ( !v7 )
    return 0;
  if ( this->m_CachePropertyValue )
  {
    mOffset = this->m_MyRoot.mOffset;
    v9 = 0i64;
    if ( mOffset )
      v10 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v10 = 0i64;
    if ( mOffset )
      v9 = (char *)&this->m_MyRoot + mOffset;
    v11 = action_context->mActionTreeComponentBase[v9[236]];
    if ( !v11 )
      v11 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v11,
      v10,
      (ActionNodeRoot *)this->m_PropertyValueUID,
      *v7,
      v13);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet(this, action_context);
  return *v7;
}

// File Line: 10580
// RVA: 0x288FC0
bool __fastcall PropertyBooleanCondition::Match(PropertyBooleanCondition *this, ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rdx
  UFG::ActionTreeComponentBase *v8; // rcx
  bool *v9; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+38h] [rbp+10h] BYREF

  LOBYTE(value_uid) = 0;
  if ( !action_context )
    return 0;
  if ( PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context) )
    return PropertyBooleanCondition::ReadValueFromPropertySet(this, action_context);
  mOffset = this->m_MyRoot.mOffset;
  v6 = 0i64;
  if ( mOffset )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v7 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->m_MyRoot + mOffset;
  v8 = action_context->mActionTreeComponentBase[v6[236]];
  if ( !v8 )
    v8 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v8,
    v7,
    (ActionNodeRoot *)this->m_PropertyValueUID,
    (unsigned int)&value_uid,
    v9);
  return value_uid;
}

// File Line: 10622
// RVA: 0x148C590
__int64 dynamic_initializer_for__TargetPropertyBooleanCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPropertyBooleanCondition", 0xFFFFFFFF);
  TargetPropertyBooleanCondition::sClassNameUID = result;
  return result;
}

// File Line: 10633
// RVA: 0x293D10
_BOOL8 __fastcall TargetPropertyBooleanCondition::ReadValueFromPropertySet(
        TargetPropertyBooleanCondition *this,
        ActionContext *action_context)
{
  bool v4; // si
  UFG::qPropertySet *PropertySet; // rax
  bool *v6; // rax
  __int64 mOffset; // rax
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rdx
  UFG::ActionTreeComponentBase *v10; // rcx
  bool v12; // [rsp+20h] [rbp-8h]

  v4 = 0;
  PropertySet = TargetPropertyConditionBase::GetPropertySet(this, action_context);
  if ( PropertySet )
  {
    v6 = PropertyUtils::Get<bool>(PropertySet, (UFG::qArray<unsigned long,0> *)&this->m_PropertySymbol, DEPTH_RECURSE);
    if ( v6 )
      v4 = *v6;
  }
  if ( this->m_CachePropertyValue )
  {
    mOffset = this->m_MyRoot.mOffset;
    v8 = 0i64;
    if ( mOffset )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v9 = 0i64;
    if ( mOffset )
      v8 = (char *)&this->m_MyRoot + mOffset;
    v10 = action_context->mActionTreeComponentBase[v8[236]];
    if ( !v10 )
      v10 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v10, v9, (ActionNodeRoot *)this->m_PropertyValueUID, v4, v12);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet(this, action_context);
  return v4;
}

// File Line: 10665
// RVA: 0x28E780
bool __fastcall TargetPropertyBooleanCondition::Match(
        TargetPropertyBooleanCondition *this,
        ActionContext *action_context)
{
  __int64 mOffset; // rax
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rdx
  UFG::ActionTreeComponentBase *v8; // rcx
  bool *v9; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+38h] [rbp+10h] BYREF

  LOBYTE(value_uid) = 0;
  if ( !action_context )
    return 0;
  if ( TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context) )
    return TargetPropertyBooleanCondition::ReadValueFromPropertySet(this, action_context);
  mOffset = this->m_MyRoot.mOffset;
  v6 = 0i64;
  if ( mOffset )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
  else
    v7 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->m_MyRoot + mOffset;
  v8 = action_context->mActionTreeComponentBase[v6[236]];
  if ( !v8 )
    v8 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v8,
    v7,
    (ActionNodeRoot *)this->m_PropertyValueUID,
    (unsigned int)&value_uid,
    v9);
  return value_uid;
}

// File Line: 10704
// RVA: 0x148BE10
__int64 dynamic_initializer_for__PropertyIntegerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PropertyIntegerCondition", 0xFFFFFFFF);
  PropertyIntegerCondition::sClassNameUID = result;
  return result;
}

// File Line: 10718
// RVA: 0x278360
void __fastcall PropertyIntegerCondition::PropertyIntegerCondition(PropertyIntegerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PropertyConditionBase::`vftable;
  this->m_PropertySymbol.mUID = -1;
  *(_WORD *)&this->m_PeriodicallyRecachePropertyValue = 0;
  *(_QWORD *)&this->m_PropertyValueUID = 0i64;
  this->m_NextTimeToCachePropertyValueUID = 0;
  this->m_CachePropertyValue = 1;
  this->m_MinTimeBeforeRecachePropertyValue = 1.0;
  this->m_MaxTimeBeforeRecachePropertyValue = 2.0;
  this->m_MyRoot.mOffset = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&PropertyIntegerCondition::`vftable;
  this->m_Value = 0;
  this->m_InEqualityOperator.mValue = 0;
}

// File Line: 10723
// RVA: 0x2939F0
__int64 __fastcall PropertyIntegerCondition::ReadValueFromPropertySet(
        PropertyIntegerCondition *this,
        ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  int *v7; // rax
  unsigned __int16 v8; // si
  __int64 mOffset; // rcx
  char *v10; // rax
  UFG::ActionTreeComponentBase *v11; // rdx
  UFG::ActionTreeComponentBase *v12; // rcx
  __int16 v14; // [rsp+20h] [rbp-8h]

  m_pPointer = action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0i64;
  m_pSceneObj = m_pPointer->m_pSceneObj;
  if ( !m_pSceneObj )
    return 0i64;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    if ( !mpWritableProperties )
      return 0i64;
  }
  v7 = PropertyUtils::Get<long>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&this->m_PropertySymbol,
         DEPTH_RECURSE);
  if ( !v7 )
    return 0i64;
  v8 = *(_WORD *)v7;
  if ( this->m_CachePropertyValue )
  {
    mOffset = this->m_MyRoot.mOffset;
    v10 = 0i64;
    if ( mOffset )
      v11 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v11 = 0i64;
    if ( mOffset )
      v10 = (char *)&this->m_MyRoot + mOffset;
    v12 = action_context->mActionTreeComponentBase[v10[236]];
    if ( !v12 )
      v12 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<short>(
      v12,
      v11,
      (ActionNodeRoot *)this->m_PropertyValueUID,
      v8,
      v14);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet(this, action_context);
  return v8;
}

// File Line: 10755
// RVA: 0x289110
bool __fastcall PropertyIntegerCondition::Match(PropertyIntegerCondition *this, ActionContext *action_context)
{
  char *v2; // rbx
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v6; // rdx
  UFG::ActionTreeComponentBase *v7; // rcx
  __int16 *v9; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0i64;
  LOWORD(value_uid) = 0;
  if ( action_context )
  {
    if ( PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context) )
    {
      LOWORD(v2) = PropertyIntegerCondition::ReadValueFromPropertySet(this, action_context);
      LOWORD(value_uid) = (_WORD)v2;
    }
    else
    {
      mOffset = this->m_MyRoot.mOffset;
      if ( mOffset )
        v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v6 = 0i64;
      if ( mOffset )
        v2 = (char *)&this->m_MyRoot + mOffset;
      v7 = action_context->mActionTreeComponentBase[v2[236]];
      if ( !v7 )
        v7 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<short>(
        v7,
        v6,
        (ActionNodeRoot *)this->m_PropertyValueUID,
        (unsigned int)&value_uid,
        v9);
      LOWORD(v2) = value_uid;
    }
  }
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)this->m_InEqualityOperator.mValue,
           this->m_Value,
           (__int16)v2);
}

// File Line: 10800
// RVA: 0x148C5D0
__int64 dynamic_initializer_for__TargetPropertyIntegerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPropertyIntegerCondition", 0xFFFFFFFF);
  TargetPropertyIntegerCondition::sClassNameUID = result;
  return result;
}

// File Line: 10816
// RVA: 0x278FC0
void __fastcall TargetPropertyIntegerCondition::TargetPropertyIntegerCondition(TargetPropertyIntegerCondition *this)
{
  TargetPropertyConditionBase::TargetPropertyConditionBase(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPropertyIntegerCondition::`vftable;
  this->m_Value = 0;
  this->m_InEqualityOperator.mValue = 0;
}

// File Line: 10821
// RVA: 0x293E70
__int64 __fastcall TargetPropertyIntegerCondition::ReadValueFromPropertySet(
        TargetPropertyIntegerCondition *this,
        ActionContext *action_context)
{
  char *v2; // rsi
  unsigned __int16 v5; // bp
  UFG::qPropertySet *PropertySet; // rax
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v8; // rdx
  UFG::ActionTreeComponentBase *v9; // rcx
  __int16 v11; // [rsp+20h] [rbp-8h]

  v2 = 0i64;
  v5 = 0;
  PropertySet = TargetPropertyConditionBase::GetPropertySet(this, action_context);
  if ( PropertySet )
    v5 = *(_WORD *)PropertyUtils::Get<long>(
                     PropertySet,
                     (UFG::qArray<unsigned long,0> *)&this->m_PropertySymbol,
                     DEPTH_RECURSE);
  if ( this->m_CachePropertyValue )
  {
    mOffset = this->m_MyRoot.mOffset;
    if ( mOffset )
      v8 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v8 = 0i64;
    if ( mOffset )
      v2 = (char *)&this->m_MyRoot + mOffset;
    v9 = action_context->mActionTreeComponentBase[v2[236]];
    if ( !v9 )
      v9 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<short>(v9, v8, (ActionNodeRoot *)this->m_PropertyValueUID, v5, v11);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet(this, action_context);
  return v5;
}

// File Line: 10855
// RVA: 0x28E8D0
bool __fastcall TargetPropertyIntegerCondition::Match(
        TargetPropertyIntegerCondition *this,
        ActionContext *action_context)
{
  char *v2; // rbx
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v6; // rdx
  UFG::ActionTreeComponentBase *v7; // rcx
  __int16 *v9; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0i64;
  LOWORD(value_uid) = 0;
  if ( action_context )
  {
    if ( TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context) )
    {
      LOWORD(v2) = TargetPropertyIntegerCondition::ReadValueFromPropertySet(this, action_context);
      LOWORD(value_uid) = (_WORD)v2;
    }
    else
    {
      mOffset = this->m_MyRoot.mOffset;
      if ( mOffset )
        v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v6 = 0i64;
      if ( mOffset )
        v2 = (char *)&this->m_MyRoot + mOffset;
      v7 = action_context->mActionTreeComponentBase[v2[236]];
      if ( !v7 )
        v7 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<short>(
        v7,
        v6,
        (ActionNodeRoot *)this->m_PropertyValueUID,
        (unsigned int)&value_uid,
        v9);
      LOWORD(v2) = value_uid;
    }
  }
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)this->m_InEqualityOperator.mValue,
           this->m_Value,
           (__int16)v2);
}

// File Line: 10897
// RVA: 0x148BDF0
__int64 dynamic_initializer_for__PropertyFloatCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PropertyFloatCondition", 0xFFFFFFFF);
  PropertyFloatCondition::sClassNameUID = result;
  return result;
}

// File Line: 10911
// RVA: 0x2782F0
void __fastcall PropertyFloatCondition::PropertyFloatCondition(PropertyFloatCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PropertyConditionBase::`vftable;
  this->m_PropertySymbol.mUID = -1;
  *(_WORD *)&this->m_PeriodicallyRecachePropertyValue = 0;
  *(_QWORD *)&this->m_PropertyValueUID = 0i64;
  this->m_NextTimeToCachePropertyValueUID = 0;
  this->m_CachePropertyValue = 1;
  this->m_MinTimeBeforeRecachePropertyValue = 1.0;
  this->m_MaxTimeBeforeRecachePropertyValue = 2.0;
  this->m_MyRoot.mOffset = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&PropertyFloatCondition::`vftable;
  this->m_Value = 0.0;
  this->m_InEqualityOperator.mValue = 0;
}

// File Line: 10916
// RVA: 0x293900
float __fastcall PropertyFloatCondition::ReadValueFromPropertySet(
        PropertyFloatCondition *this,
        ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  float *v7; // rsi
  __int64 mOffset; // rcx
  char *v9; // rdx
  UFG::ActionTreeComponentBase *v10; // r9
  UFG::ActionTreeComponentBase *v11; // rcx
  float v13; // [rsp+20h] [rbp-8h]

  m_pPointer = action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0.0;
  m_pSceneObj = m_pPointer->m_pSceneObj;
  if ( !m_pSceneObj )
    return 0.0;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    if ( !mpWritableProperties )
      return 0.0;
  }
  v7 = PropertyUtils::Get<float>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&this->m_PropertySymbol,
         DEPTH_RECURSE);
  if ( !v7 )
    return 0.0;
  if ( this->m_CachePropertyValue )
  {
    mOffset = this->m_MyRoot.mOffset;
    v9 = 0i64;
    if ( mOffset )
      v10 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v10 = 0i64;
    if ( mOffset )
      v9 = (char *)&this->m_MyRoot + mOffset;
    v11 = action_context->mActionTreeComponentBase[v9[236]];
    if ( !v11 )
      v11 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v11,
      v10,
      (ActionNodeRoot *)this->m_PropertyValueUID,
      (unsigned int)v10,
      v13);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet(this, action_context);
  return *v7;
}

// File Line: 10944
// RVA: 0x289060
char __fastcall PropertyFloatCondition::Match(PropertyFloatCondition *this, ActionContext *action_context)
{
  float ValueFromPropertySet; // xmm0_4
  __int64 mOffset; // rax
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rdx
  UFG::ActionTreeComponentBase *v8; // rcx
  float *v10; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF

  ValueFromPropertySet = 0.0;
  value_uid = 0;
  if ( action_context )
  {
    if ( PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context) )
    {
      ValueFromPropertySet = PropertyFloatCondition::ReadValueFromPropertySet(this, action_context);
      value_uid = LODWORD(ValueFromPropertySet);
    }
    else
    {
      mOffset = this->m_MyRoot.mOffset;
      v6 = 0i64;
      if ( mOffset )
        v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v7 = 0i64;
      if ( mOffset )
        v6 = (char *)&this->m_MyRoot + mOffset;
      v8 = action_context->mActionTreeComponentBase[v6[236]];
      if ( !v8 )
        v8 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
        v8,
        v7,
        (ActionNodeRoot *)this->m_PropertyValueUID,
        (unsigned int)&value_uid,
        v10);
      ValueFromPropertySet = *(float *)&value_uid;
    }
  }
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->m_InEqualityOperator.mValue,
           this->m_Value,
           ValueFromPropertySet);
}

// File Line: 10989
// RVA: 0x148C5B0
__int64 dynamic_initializer_for__TargetPropertyFloatCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPropertyFloatCondition", 0xFFFFFFFF);
  TargetPropertyFloatCondition::sClassNameUID = result;
  return result;
}

// File Line: 11005
// RVA: 0x278F80
void __fastcall TargetPropertyFloatCondition::TargetPropertyFloatCondition(TargetPropertyFloatCondition *this)
{
  TargetPropertyConditionBase::TargetPropertyConditionBase(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPropertyFloatCondition::`vftable;
  this->m_Value = 0.0;
  this->m_InEqualityOperator.mValue = 0;
}

// File Line: 11010
// RVA: 0x293DC0
float __fastcall TargetPropertyFloatCondition::ReadValueFromPropertySet(
        TargetPropertyFloatCondition *this,
        ActionContext *action_context)
{
  float v4; // xmm6_4
  UFG::qPropertySet *PropertySet; // rax
  unsigned int v6; // r9d
  float *v7; // rax
  __int64 mOffset; // rax
  char *v9; // rcx
  UFG::ActionTreeComponentBase *v10; // rdx
  UFG::ActionTreeComponentBase *v11; // rcx
  float value; // [rsp+20h] [rbp-18h]

  v4 = 0.0;
  PropertySet = TargetPropertyConditionBase::GetPropertySet(this, action_context);
  if ( PropertySet )
  {
    v7 = UFG::qPropertySet::Get<float>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&this->m_PropertySymbol,
           DEPTH_RECURSE);
    if ( v7 )
      v4 = *v7;
  }
  if ( this->m_CachePropertyValue )
  {
    mOffset = this->m_MyRoot.mOffset;
    v9 = 0i64;
    if ( mOffset )
      v10 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v10 = 0i64;
    if ( mOffset )
      v9 = (char *)&this->m_MyRoot + mOffset;
    v11 = action_context->mActionTreeComponentBase[v9[236]];
    if ( !v11 )
      v11 = action_context->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v11,
      v10,
      (ActionNodeRoot *)this->m_PropertyValueUID,
      v6,
      value);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet(this, action_context);
  return v4;
}

// File Line: 11038
// RVA: 0x28E820
char __fastcall TargetPropertyFloatCondition::Match(TargetPropertyFloatCondition *this, ActionContext *action_context)
{
  float ValueFromPropertySet; // xmm0_4
  __int64 mOffset; // rax
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rdx
  UFG::ActionTreeComponentBase *v8; // rcx
  float *v10; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF

  ValueFromPropertySet = 0.0;
  value_uid = 0;
  if ( action_context )
  {
    if ( TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context) )
    {
      ValueFromPropertySet = TargetPropertyFloatCondition::ReadValueFromPropertySet(this, action_context);
      value_uid = LODWORD(ValueFromPropertySet);
    }
    else
    {
      mOffset = this->m_MyRoot.mOffset;
      v6 = 0i64;
      if ( mOffset )
        v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v7 = 0i64;
      if ( mOffset )
        v6 = (char *)&this->m_MyRoot + mOffset;
      v8 = action_context->mActionTreeComponentBase[v6[236]];
      if ( !v8 )
        v8 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
        v8,
        v7,
        (ActionNodeRoot *)this->m_PropertyValueUID,
        (unsigned int)&value_uid,
        v10);
      ValueFromPropertySet = *(float *)&value_uid;
    }
  }
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->m_InEqualityOperator.mValue,
           this->m_Value,
           ValueFromPropertySet);
}

// File Line: 11081
// RVA: 0x148BE30
__int64 dynamic_initializer_for__PropertySymbolCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PropertySymbolCondition", 0xFFFFFFFF);
  PropertySymbolCondition::sClassNameUID = result;
  return result;
}

// File Line: 11096
// RVA: 0x293AD0
UFG::qSymbol *__fastcall PropertySymbolCondition::ReadValueFromPropertySet(
        PropertySymbolCondition *this,
        UFG::qSymbol *result,
        ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qSymbol *v9; // r14
  __int64 mOffset; // rcx
  char *v11; // rax
  UFG::ActionTreeComponentBase *v12; // rdx
  UFG::ActionTreeComponentBase *v13; // rcx
  ActionNodeRoot *m_PropertyValueUID; // r8
  unsigned int v15; // eax
  unsigned int mUID; // [rsp+60h] [rbp+18h] BYREF
  int *value_uid; // [rsp+68h] [rbp+20h] BYREF

  m_pPointer = action_context->mSimObject.m_pPointer;
  if ( m_pPointer
    && m_pPointer->m_pSceneObj
    && ((m_pSceneObj = m_pPointer->m_pSceneObj, (mpWritableProperties = m_pSceneObj->mpWritableProperties) != 0i64)
     || (mpWritableProperties = m_pSceneObj->mpConstProperties) != 0i64)
    && (v9 = PropertyUtils::Get<UFG::qSymbol>(
               mpWritableProperties,
               (UFG::qArray<unsigned long,0> *)&this->m_PropertySymbol,
               DEPTH_RECURSE)) != 0i64 )
  {
    if ( this->m_CachePropertyValue )
    {
      value_uid = (int *)&mUID;
      mUID = v9->mUID;
      mOffset = this->m_MyRoot.mOffset;
      v11 = 0i64;
      if ( mOffset )
        v12 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v12 = 0i64;
      if ( mOffset )
        v11 = (char *)&this->m_MyRoot + mOffset;
      v13 = action_context->mActionTreeComponentBase[v11[236]];
      if ( !v13 )
        v13 = action_context->mActionTreeComponentBase[1];
      m_PropertyValueUID = (ActionNodeRoot *)this->m_PropertyValueUID;
      LODWORD(value_uid) = mUID;
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::qSymbol>(
        v13,
        v12,
        m_PropertyValueUID,
        (unsigned int)&value_uid,
        (UFG::qSymbol)-2);
    }
    PropertyConditionBase::ValueHasBeenReadFromPropertySet(this, action_context);
    v15 = v9->mUID;
  }
  else
  {
    v15 = UFG::gNullQSymbol.mUID;
  }
  result->mUID = v15;
  return result;
}

// File Line: 11122
// RVA: 0x2891C0
bool __fastcall PropertySymbolCondition::Match(PropertySymbolCondition *this, ActionContext *action_context)
{
  unsigned int mUID; // eax
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v6; // rdx
  char *v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rcx
  UFG::qSymbol *v10; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  mUID = -1;
  value_uid = -1;
  if ( action_context )
  {
    if ( PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context) )
    {
      mUID = PropertySymbolCondition::ReadValueFromPropertySet(this, &result, action_context)->mUID;
    }
    else
    {
      mOffset = this->m_MyRoot.mOffset;
      if ( mOffset )
        v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v6 = 0i64;
      if ( mOffset )
        v7 = (char *)&this->m_MyRoot + mOffset;
      else
        v7 = 0i64;
      v8 = action_context->mActionTreeComponentBase[v7[236]];
      if ( !v8 )
        v8 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::qSymbol>(
        v8,
        v6,
        (ActionNodeRoot *)this->m_PropertyValueUID,
        (unsigned int)&value_uid,
        v10);
      mUID = value_uid;
    }
  }
  return this->m_Value.mUID == mUID;
}

// File Line: 11178
// RVA: 0x148C5F0
__int64 dynamic_initializer_for__TargetPropertySymbolCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPropertySymbolCondition", 0xFFFFFFFF);
  TargetPropertySymbolCondition::sClassNameUID = result;
  return result;
}

// File Line: 11195
// RVA: 0x293F20
UFG::qSymbol *__fastcall TargetPropertySymbolCondition::ReadValueFromPropertySet(
        TargetPropertySymbolCondition *this,
        UFG::qSymbol *result,
        ActionContext *action_context)
{
  UFG::qPropertySet *PropertySet; // rax
  __int64 mOffset; // rax
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rdx
  UFG::ActionTreeComponentBase *v10; // rcx
  ActionNodeRoot *m_PropertyValueUID; // r8
  UFG::qPropertyDepth depth; // [rsp+20h] [rbp-38h]
  UFG::qSymbol defaultValue; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol *resulta; // [rsp+68h] [rbp+10h] BYREF
  UFG::qSymbol *p_defaultValue; // [rsp+78h] [rbp+20h]

  result->mUID = UFG::gNullQSymbol.mUID;
  PropertySet = TargetPropertyConditionBase::GetPropertySet(this, action_context);
  if ( PropertySet )
  {
    p_defaultValue = &defaultValue;
    defaultValue.mUID = UFG::gNullQSymbol.mUID;
    result->mUID = PropertyUtils::GetWithDefault<UFG::qSymbol>(
                     (UFG::qSymbol *)&resulta,
                     PropertySet,
                     (UFG::qArray<unsigned long,0> *)&this->m_PropertySymbol,
                     &defaultValue.mUID,
                     DEPTH_RECURSE)->mUID;
  }
  if ( this->m_CachePropertyValue )
  {
    resulta = &defaultValue;
    defaultValue.mUID = result->mUID;
    mOffset = this->m_MyRoot.mOffset;
    v8 = 0i64;
    if ( mOffset )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
    else
      v9 = 0i64;
    if ( mOffset )
      v8 = (char *)&this->m_MyRoot + mOffset;
    v10 = action_context->mActionTreeComponentBase[v8[236]];
    if ( !v10 )
      v10 = action_context->mActionTreeComponentBase[1];
    m_PropertyValueUID = (ActionNodeRoot *)this->m_PropertyValueUID;
    p_defaultValue = (UFG::qSymbol *)&resulta;
    LODWORD(resulta) = defaultValue;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::qSymbol>(
      v10,
      v9,
      m_PropertyValueUID,
      (unsigned int)&resulta,
      (UFG::qSymbol)depth);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet(this, action_context);
  return result;
}

// File Line: 11223
// RVA: 0x28E980
bool __fastcall TargetPropertySymbolCondition::Match(
        TargetPropertySymbolCondition *this,
        ActionContext *action_context)
{
  unsigned int mUID; // eax
  __int64 mOffset; // rax
  UFG::ActionTreeComponentBase *v6; // rdx
  char *v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rcx
  UFG::qSymbol *v10; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  mUID = -1;
  value_uid = -1;
  if ( action_context )
  {
    if ( TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(this, action_context) )
    {
      mUID = TargetPropertySymbolCondition::ReadValueFromPropertySet(this, &result, action_context)->mUID;
    }
    else
    {
      mOffset = this->m_MyRoot.mOffset;
      if ( mOffset )
        v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + mOffset);
      else
        v6 = 0i64;
      if ( mOffset )
        v7 = (char *)&this->m_MyRoot + mOffset;
      else
        v7 = 0i64;
      v8 = action_context->mActionTreeComponentBase[v7[236]];
      if ( !v8 )
        v8 = action_context->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::qSymbol>(
        v8,
        v6,
        (ActionNodeRoot *)this->m_PropertyValueUID,
        (unsigned int)&value_uid,
        v10);
      mUID = value_uid;
    }
  }
  return this->m_Value.mUID == mUID;
}

// File Line: 11265
// RVA: 0x148BF90
__int64 dynamic_initializer_for__SkookumCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SkookumCondition", 0xFFFFFFFF);
  SkookumCondition::sClassNameUID = result;
  return result;
}

// File Line: 11275
// RVA: 0x278630
void __fastcall SkookumCondition::SkookumCondition(SkookumCondition *this)
{
  char *v2; // rdx

  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SkookumCondition::`vftable;
  v2 = (char *)SkookumCondition::sDefaultScope;
  this->mClassScopeText.mOffset = 1i64;
  BinString::Set(&this->mClassScopeText, v2);
  this->mSkookumScriptRaw.mOffset = 1i64;
  BinString::Set(&this->mSkookumScriptRaw, &customCaption);
  this->mpScript = 0i64;
}

// File Line: 11285
// RVA: 0x278570
void __fastcall SkookumCondition::SkookumCondition(SkookumCondition *this, MemImageLoadFlag flag)
{
  const char *v3; // rdi
  const char *v4; // rsi

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SkookumCondition::`vftable;
  v3 = BinString::sEmptyString;
  if ( (this->mClassScopeText.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v4 = (char *)&this->mClassScopeText + (this->mClassScopeText.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v4 = BinString::sEmptyString;
  if ( (this->mSkookumScriptRaw.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v3 = (char *)&this->mSkookumScriptRaw + (this->mSkookumScriptRaw.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  if ( (int)UFG::qStringLength(v3) > 0 )
    this->mpScript = (UFG::ScriptCache::Script *)UFG::ScriptCache::GetScript(
                                                   v3,
                                                   v4,
                                                   SkookumCondition::sDefaultScope,
                                                   "Track");
}

// File Line: 11301
// RVA: 0x2798C0
void __fastcall SkookumCondition::~SkookumCondition(SkookumCondition *this)
{
  UFG::ScriptCache::Script *mpScript; // rcx
  char *v3; // rcx
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&SkookumCondition::`vftable;
  mpScript = this->mpScript;
  if ( mpScript )
  {
    UFG::ScriptCache::ReleaseScript(mpScript);
    this->mpScript = 0i64;
  }
  if ( (this->mSkookumScriptRaw.mOffset & 1) != 0 && (this->mSkookumScriptRaw.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)&this->mSkookumScriptRaw + (this->mSkookumScriptRaw.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  if ( (this->mClassScopeText.mOffset & 1) != 0 && (this->mClassScopeText.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v4 = (char *)&this->mClassScopeText + (this->mClassScopeText.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v4 != BinString::sEmptyString )
      operator delete[](v4);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 11346
// RVA: 0x289B10
bool __fastcall SkookumCondition::Match(SkookumCondition *this, ActionContext *pContext)
{
  bool v3; // bl
  UFG::ScriptCache::Script *mpScript; // rcx
  UFG::SimObject *m_pPointer; // rax
  SSCode *ScriptCode; // rsi
  UFG::SimObject *v7; // rcx
  __int16 m_Flags; // dx
  UFG::TSActorComponent *ComponentOfType; // rax
  UFG::TSActor *Actor; // rax
  SSClass *i_class_p; // rdx
  ActionPath *PlayingFullPath; // rax
  char *String_DBG; // rax
  AString *v14; // rax
  AStringRef *i_str_ref_p; // rbx
  bool v16; // zf
  AObjReusePool<AStringRef> *pool; // r8
  AObjBlock<AStringRef> *i_block_p; // rax
  unsigned __int64 i_objects_a; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  int mCount; // edx
  SSInstance *v23; // rcx
  ActionPath result; // [rsp+38h] [rbp-20h] BYREF
  SSInstance *ppResult; // [rsp+60h] [rbp+8h] BYREF
  AString v26; // [rsp+70h] [rbp+18h] BYREF

  v3 = 0;
  mpScript = this->mpScript;
  if ( !mpScript )
    return 0;
  m_pPointer = pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 2) != 0 )
      return 0;
  }
  ScriptCode = UFG::ScriptCache::GetScriptCode(mpScript);
  if ( ScriptCode )
  {
    v7 = pContext->mSimObject.m_pPointer;
    if ( v7
      && ((m_Flags = v7->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0
         ? ((m_Flags & 0x2000) == 0
          ? ((m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                           v7,
                                                           UFG::TSActorComponent::_TypeUID))
           : (ComponentOfType = (UFG::TSActorComponent *)v7->m_Components.p[2].m_pComponent))
          : (ComponentOfType = (UFG::TSActorComponent *)v7->m_Components.p[3].m_pComponent))
         : (ComponentOfType = (UFG::TSActorComponent *)v7->m_Components.p[4].m_pComponent))
        : (ComponentOfType = (UFG::TSActorComponent *)v7->m_Components.p[4].m_pComponent),
          ComponentOfType) )
    {
      Actor = UFG::TSActorComponent::GetActor(ComponentOfType);
    }
    else
    {
      Actor = (UFG::TSActor *)SkookumScript::c_world_p;
    }
    i_class_p = Actor->i_class_p;
    ppResult = 0i64;
    if ( UFG::SkookumMgr::RunExternalCodeBlock(ScriptCode, i_class_p, Actor, 0i64, &ppResult) )
    {
      PlayingFullPath = ActionController::GetPlayingFullPath(pContext->mActionController, &result);
      String_DBG = ActionPath::GetString_DBG(PlayingFullPath);
      v14 = a_str_format(&v26, "Coroutine used instead of a method in SkookumCondition at %s", String_DBG);
      SSDebug::print_error(v14, 3);
      i_str_ref_p = v26.i_str_ref_p;
      v16 = v26.i_str_ref_p->i_ref_count-- == 1;
      if ( v16 )
      {
        if ( i_str_ref_p->i_deallocate )
          AMemory::c_free_func(i_str_ref_p->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)i_str_ref_p < i_objects_a
          || (p_i_exp_pool = &pool->i_pool, (unsigned __int64)i_str_ref_p >= i_objects_a + 24i64 * i_block_p->i_size) )
        {
          p_i_exp_pool = &pool->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
      }
      mCount = result.mPath.mCount;
      if ( result.mPath.mCount >= 0 )
      {
        if ( result.mPath.mData.mOffset )
        {
          if ( (UFG::qOffset64<ActionID *> *)((char *)&result.mPath.mData + result.mPath.mData.mOffset) )
          {
            operator delete[]((char *)&result.mPath.mData + result.mPath.mData.mOffset);
            mCount = result.mPath.mCount;
          }
        }
        result.mPath.mData.mOffset = 0i64;
        result.mPath.mCount = mCount & 0x80000000;
      }
      return 0;
    }
    v3 = 1;
    v23 = ppResult;
    if ( ppResult )
    {
      if ( ppResult->i_class_p == SSBrain::c_boolean_class_p )
        v3 = ppResult->i_user_data == 1;
      v16 = ppResult->i_ref_count-- == 1;
      if ( v16 )
      {
        v23->i_ref_count = 2147483648;
        v23->vfptr[1].get_scope_context(v23);
      }
    }
  }
  return v3;
}

// File Line: 11420
// RVA: 0x148AD50
__int64 dynamic_initializer_for__FaceActionRequestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FaceActionRequestCondition", 0xFFFFFFFF);
  FaceActionRequestCondition::sClassNameUID = result;
  return result;
}

// File Line: 11428
// RVA: 0x276DA0
void __fastcall FaceActionRequestCondition::FaceActionRequestCondition(FaceActionRequestCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FaceActionRequestCondition::`vftable;
  *(_WORD *)&this->mFaceAction.mValue = 5650;
}

// File Line: 11432
// RVA: 0x281720
bool __fastcall FaceActionRequestCondition::Match(FaceActionRequestCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::FaceActionComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          v9 = (UFG::FaceActionComponent *)v7->m_Components.p[45].m_pComponent;
        }
        else
        {
          v10 = v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FaceActionComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v7, UFG::FaceActionComponent::_TypeUID);
          v9 = (UFG::FaceActionComponent *)v10;
        }
        if ( v9
          && v9->mFaceActionSetup
          && UFG::FaceActionComponent::IsFaceActionAvailable(
               v9,
               (UFG::eFaceActionEnum)(unsigned __int8)this->mFaceAction.mValue,
               1)
          && UFG::FaceActionComponent::IsFaceActionRequirementMet(v9) )
        {
          return 1;
        }
      }
    }
  }
  return result;
}

// File Line: 11473
// RVA: 0x148AD30
__int64 dynamic_initializer_for__FaceActionAvailableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FaceActionAvailableCondition", 0xFFFFFFFF);
  FaceActionAvailableCondition::sClassNameUID = result;
  return result;
}

// File Line: 11481
// RVA: 0x276D60
void __fastcall FaceActionAvailableCondition::FaceActionAvailableCondition(FaceActionAvailableCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FaceActionAvailableCondition::`vftable;
  *(_WORD *)&this->mFaceAction.mValue = 274;
}

// File Line: 11485
// RVA: 0x281650
bool __fastcall FaceActionAvailableCondition::Match(FaceActionAvailableCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceActionComponent *m_pComponent; // rax
  char mCheckEnabled; // cl
  bool v7; // zf

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = (UFG::FaceActionComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    m_pPointer,
                                                    UFG::FaceActionComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    m_pPointer,
                                                    UFG::FaceActionComponent::_TypeUID));
    if ( m_pComponent )
    {
      mCheckEnabled = this->mCheckEnabled;
      v7 = mCheckEnabled == 0;
      if ( mCheckEnabled )
      {
        if ( !m_pComponent->mFaceActionSetup )
          return 0;
        v7 = mCheckEnabled == 0;
      }
      return UFG::FaceActionComponent::IsFaceActionAvailable(
               m_pComponent,
               (UFG::eFaceActionEnum)(unsigned __int8)this->mFaceAction.mValue,
               !v7);
    }
  }
  return 0;
}

// File Line: 11518
// RVA: 0x148AD90
__int64 dynamic_initializer_for__FaceMeterCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FaceMeterCondition", 0xFFFFFFFF);
  FaceMeterCondition::sClassNameUID = result;
  return result;
}

// File Line: 11526
// RVA: 0x276E10
void __fastcall FaceMeterCondition::FaceMeterCondition(FaceMeterCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FaceMeterCondition::`vftable;
  this->mFaceValue = 0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 11530
// RVA: 0x281910
bool __fastcall FaceMeterCondition::Match(FaceMeterCondition *this, ActionContext *pContext)
{
  UFG::GameStatTracker *v3; // rax
  float Stat; // xmm0_4

  v3 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v3, Face);
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mFaceValue,
           (int)Stat);
}

// File Line: 11550
// RVA: 0x148AD70
__int64 dynamic_initializer_for__FaceMeterActivatedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FaceMeterActivatedCondition", 0xFFFFFFFF);
  FaceMeterActivatedCondition::sClassNameUID = result;
  return result;
}

// File Line: 11553
// RVA: 0x276DE0
void __fastcall FaceMeterActivatedCondition::FaceMeterActivatedCondition(FaceMeterActivatedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&FaceMeterActivatedCondition::`vftable;
}

// File Line: 11557
// RVA: 0x281880
bool __fastcall FaceMeterActivatedCondition::Match(FaceMeterActivatedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
     && m_Flags >= 0
     && (m_Flags & 0x2000) == 0
     && (m_Flags & 0x1000) == 0
      ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceMeterComponent::_TypeUID))
      : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceMeterComponent::_TypeUID)),
        ComponentOfType) )
  {
    return BYTE1(ComponentOfType[135].m_SafePointerList.mNode.mPrev);
  }
  else
  {
    return 0;
  }
}

// File Line: 11581
// RVA: 0x148BC70
__int64 dynamic_initializer_for__PipLevelCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PipLevelCondition", 0xFFFFFFFF);
  PipLevelCondition::sClassNameUID = result;
  return result;
}

// File Line: 11589
// RVA: 0x277FD0
void __fastcall PipLevelCondition::PipLevelCondition(PipLevelCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PipLevelCondition::`vftable;
  this->mPipLevel = 0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 11593
// RVA: 0x288C90
bool __fastcall PipLevelCondition::Match(PipLevelCondition *this, ActionContext *pContext)
{
  UFG::GameStatTracker *v3; // rax
  int FaceLevel; // eax

  v3 = UFG::GameStatTracker::Instance();
  FaceLevel = UFG::GameStatTracker::GetFaceLevel(v3);
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mPipLevel,
           FaceLevel);
}

// File Line: 11613
// RVA: 0x148B3D0
__int64 dynamic_initializer_for__IsFactionStandingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsFactionStandingCondition", 0xFFFFFFFF);
  IsFactionStandingCondition::sClassNameUID = result;
  return result;
}

// File Line: 11621
// RVA: 0x277730
void __fastcall IsFactionStandingCondition::IsFactionStandingCondition(IsFactionStandingCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsFactionStandingCondition::`vftable;
  *(_WORD *)&this->mFactionStanding.mValue = 5632;
}

// File Line: 11625
// RVA: 0x283CE0
bool __fastcall IsFactionStandingCondition::Match(IsFactionStandingCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v7; // rax
  __int64 v8; // rax
  UFG::SimObjectCVBase *Texture; // rbx
  __int16 v10; // cx
  hkSimpleLocalFrame *v11; // rdi
  __int16 v12; // dx
  UFG::SimObjectCharacterPropertiesComponent *v13; // rax
  UFG::SimObjectCharacterPropertiesComponent *v14; // rbx
  UFG::SimObjectCVBase *v15; // rcx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  __int16 v17; // dx
  unsigned int v18; // edx
  bool v19; // zf
  UFG::eFactionClassEnum m_eFactionClass; // edi
  UFG::eFactionClassEnum v21; // ebx
  UFG::GameStatTracker *v22; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v7;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v8 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent);
      if ( v8 )
      {
        Texture = *(UFG::SimObjectCVBase **)(56i64
                                           * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                                + *(_QWORD *)(v8 + 96)
                                                                + 8i64)
                                           + *(_QWORD *)(v8 + 88)
                                           + 40);
        if ( Texture )
        {
          v10 = Texture->m_Flags;
          if ( v10 < 0 )
          {
            v11 = (hkSimpleLocalFrame *)((v10 & 0x4000) != 0
                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                           Texture,
                                           UFG::VehicleOccupantComponent::_TypeUID)
                                       : Texture->m_Components.p[30].m_pComponent);
            if ( v11 && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v11) )
              Texture = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v11);
          }
          if ( Texture )
          {
            v12 = Texture->m_Flags;
            if ( (v12 & 0x4000) != 0 || v12 < 0 )
              v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(Texture);
            else
              v13 = (UFG::SimObjectCharacterPropertiesComponent *)((v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
                                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     Texture,
                                                                     UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                                 : UFG::SimObject::GetComponentOfType(
                                                                     Texture,
                                                                     UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
            v14 = v13;
            if ( v13 )
            {
              v15 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
              if ( v15 )
              {
                v17 = v15->m_Flags;
                if ( (v17 & 0x4000) != 0 || v17 < 0 )
                {
                  ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v15);
                }
                else
                {
                  if ( (v17 & 0x2000) != 0 )
                  {
                    v18 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
                  }
                  else
                  {
                    v19 = (v17 & 0x1000) == 0;
                    v18 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
                    if ( v19 )
                    {
                      ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                        v15,
                                                                                        UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                      goto LABEL_40;
                    }
                  }
                  ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                    v15,
                                                                                    v18);
                }
              }
              else
              {
                ComponentOfType = 0i64;
              }
LABEL_40:
              m_eFactionClass = ComponentOfType->m_eFactionClass;
              v21 = v14->m_eFactionClass;
              v22 = UFG::FactionInterface::Get();
              return (unsigned __int8)this->mFactionStanding.mValue == (unsigned int)UFG::FactionInterface::GetStanding(
                                                                                       &v22->mFactionInterface,
                                                                                       m_eFactionClass,
                                                                                       v21);
            }
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 11679
// RVA: 0x148B830
__int64 dynamic_initializer_for__IsTargetsTargetFactionStandingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsTargetsTargetFactionStandingCondition", 0xFFFFFFFF);
  IsTargetsTargetFactionStandingCondition::sClassNameUID = result;
  return result;
}

// File Line: 11689
// RVA: 0x277930
void __fastcall IsTargetsTargetFactionStandingCondition::IsTargetsTargetFactionStandingCondition(
        IsTargetsTargetFactionStandingCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsTargetsTargetFactionStandingCondition::`vftable;
  *(_WORD *)&this->mFactionStanding.mValue = 5632;
  this->mTargetsTargetType.mValue = 23;
}

// File Line: 11694
// RVA: 0x284FF0
bool __fastcall IsTargetsTargetFactionStandingCondition::Match(
        IsTargetsTargetFactionStandingCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v7; // rax
  __int64 v8; // rax
  UFG::SimObjectCVBase *v9; // rcx
  __int16 v10; // dx
  UFG::TargetingSystemPedBaseComponent *v11; // rax
  UFG::SimObjectCVBase *v12; // rcx
  __int16 v13; // dx
  UFG::SimObjectCharacterPropertiesComponent *v14; // rax
  UFG::SimObjectCharacterPropertiesComponent *v15; // rbx
  UFG::SimObjectCVBase *v16; // rcx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfType; // rax
  __int16 v18; // dx
  unsigned int v19; // edx
  bool v20; // zf
  UFG::eFactionClassEnum m_eFactionClass; // edi
  UFG::eFactionClassEnum v22; // ebx
  UFG::GameStatTracker *v23; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v7;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v8 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent);
      if ( v8 )
      {
        v9 = *(UFG::SimObjectCVBase **)(56i64
                                      * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                           + *(_QWORD *)(v8 + 96)
                                                           + 8i64)
                                      + *(_QWORD *)(v8 + 88)
                                      + 40);
        if ( v9 )
        {
          v10 = v9->m_Flags;
          if ( (v10 & 0x4000) != 0 || v10 < 0 )
            v11 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v9);
          else
            v11 = (UFG::TargetingSystemPedBaseComponent *)((v10 & 0x2000) != 0 || (v10 & 0x1000) != 0
                                                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v9,
                                                             UFG::TargetingSystemPedBaseComponent::_TypeUID)
                                                         : UFG::SimObject::GetComponentOfType(
                                                             v9,
                                                             UFG::TargetingSystemPedBaseComponent::_TypeUID));
          if ( v11 )
          {
            v12 = (UFG::SimObjectCVBase *)v11->m_pTargets[(unsigned __int8)v11->m_pTargetingMap->m_Map.p[(unsigned __int8)this->mTargetsTargetType.mValue]].m_pTarget.m_pPointer;
            if ( v12 )
            {
              v13 = v12->m_Flags;
              if ( (v13 & 0x4000) != 0 || v13 < 0 )
                v14 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v12);
              else
                v14 = (UFG::SimObjectCharacterPropertiesComponent *)((v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
                                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v12,
                                                                       UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                                   : UFG::SimObject::GetComponentOfType(
                                                                       v12,
                                                                       UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
              v15 = v14;
              if ( v14 )
              {
                v16 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
                if ( v16 )
                {
                  v18 = v16->m_Flags;
                  if ( (v18 & 0x4000) != 0 || v18 < 0 )
                  {
                    ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v16);
                  }
                  else
                  {
                    if ( (v18 & 0x2000) != 0 )
                    {
                      v19 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
                    }
                    else
                    {
                      v20 = (v18 & 0x1000) == 0;
                      v19 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
                      if ( v20 )
                      {
                        ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                          v16,
                                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                        goto LABEL_41;
                      }
                    }
                    ComponentOfType = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                      v16,
                                                                                      v19);
                  }
                }
                else
                {
                  ComponentOfType = 0i64;
                }
LABEL_41:
                m_eFactionClass = ComponentOfType->m_eFactionClass;
                v22 = v15->m_eFactionClass;
                v23 = UFG::FactionInterface::Get();
                return (unsigned __int8)this->mFactionStanding.mValue == (unsigned int)UFG::FactionInterface::GetStanding(
                                                                                         &v23->mFactionInterface,
                                                                                         m_eFactionClass,
                                                                                         v22);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 11743
// RVA: 0x148B3B0
__int64 dynamic_initializer_for__IsExcludedFromScoring::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsExcludedFromScoring", 0xFFFFFFFF);
  IsExcludedFromScoring::sClassNameUID = result;
  return result;
}

// File Line: 11749
// RVA: 0x2776F0
void __fastcall IsExcludedFromScoring::IsExcludedFromScoring(IsExcludedFromScoring *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsExcludedFromScoring::`vftable;
  this->mTargetType.mValue = 22;
}

// File Line: 11753
// RVA: 0x283C40
bool __fastcall IsExcludedFromScoring::Match(IsExcludedFromScoring *this, ActionContext *pContext)
{
  UFG::SimObject *Target; // rbx
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  Target = UFG::getTarget(pContext, (UFG::eTargetTypeEnum)(unsigned __int8)this->mTargetType.mValue);
  return Target
      && (Target->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0xCD8AAA2A)->mUID
       || Target->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0x700708E6u)->mUID
       || Target->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0x28EB095Bu)->mUID
       || Target->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0xDB443529)->mUID
       || Target->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0x69BC658Au)->mUID);
}

// File Line: 11813
// RVA: 0x148B7F0
__int64 dynamic_initializer_for__IsTargetingStandingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsTargetingStandingCondition", 0xFFFFFFFF);
  IsTargetingStandingCondition::sClassNameUID = result;
  return result;
}

// File Line: 11821
// RVA: 0x2778F0
void __fastcall IsTargetingStandingCondition::IsTargetingStandingCondition(IsTargetingStandingCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsTargetingStandingCondition::`vftable;
  *(_WORD *)&this->mFactionStanding.mValue = 5632;
}

// File Line: 11825
// RVA: 0x284DC0
bool __fastcall IsTargetingStandingCondition::Match(IsTargetingStandingCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TargetingSystemPedBaseComponent *v7; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v7 = (UFG::TargetingSystemPedBaseComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent)) != 0i64)
        && (unsigned __int8)this->mFactionStanding.mValue == (unsigned int)UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
                                                                             v7,
                                                                             (UFG::eTargetTypeEnum)(unsigned __int8)this->mTargetType.mValue);
  return result;
}

// File Line: 11857
// RVA: 0x148C8F0
__int64 dynamic_initializer_for__TimeWarpCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TimeWarpCondition", 0xFFFFFFFF);
  TimeWarpCondition::sClassNameUID = result;
  return result;
}

// File Line: 11860
// RVA: 0x290A00
bool __fastcall TimeWarpCondition::Match(TimeWarpCondition *this, ActionContext *pContext)
{
  float v2; // xmm1_4

  v2 = UFG::Metrics::msInstance.mSimTimeScaleInGame - 1.0;
  if ( (float)(UFG::Metrics::msInstance.mSimTimeScaleInGame - 1.0) < 0.0 )
    LODWORD(v2) ^= _xmm[0];
  return v2 >= 0.001;
}

// File Line: 11882
// RVA: 0x148C7F0
__int64 dynamic_initializer_for__TargetValidCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetValidCondition", 0xFFFFFFFF);
  TargetValidCondition::sClassNameUID = result;
  return result;
}

// File Line: 11889
// RVA: 0x279360
void __fastcall TargetValidCondition::TargetValidCondition(TargetValidCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetValidCondition::`vftable;
  this->mTargetType = 0;
}

// File Line: 11894
// RVA: 0x2903A0
bool __fastcall TargetValidCondition::Match(TargetValidCondition *this, ActionContext *pContext)
{
  return UFG::getTarget(pContext, (UFG::eTargetTypeEnum)this->mTargetType) != 0i64;
}

// File Line: 11922
// RVA: 0x148C310
__int64 dynamic_initializer_for__TargetIsEqualCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsEqualCondition", 0xFFFFFFFF);
  TargetIsEqualCondition::sClassNameUID = result;
  return result;
}

// File Line: 11936
// RVA: 0x278B10
void __fastcall TargetIsEqualCondition::TargetIsEqualCondition(TargetIsEqualCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsEqualCondition::`vftable;
  *(_QWORD *)&this->mTarget1Owner.mValue = 1i64;
  *(_QWORD *)&this->mTarget2Owner.mValue = 1i64;
}

// File Line: 11941
// RVA: 0x28C590
bool __fastcall TargetIsEqualCondition::Match(TargetIsEqualCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::SimComponent *v9; // r8
  UFG::SimComponent *v10; // rax
  __int64 v11; // rdi
  UFG::SimObjectGame *v12; // r8
  __int16 v13; // cx
  UFG::SimComponent *v14; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v16; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(this->mTarget1Owner.mValue
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 )
  {
    v9 = v7->m_Components.p[20].m_pComponent;
  }
  else if ( v8 >= 0 )
  {
    v10 = (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
    v9 = v10;
  }
  else
  {
    v9 = v7->m_Components.p[20].m_pComponent;
  }
  if ( v9
    && (v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(this->mTarget1Type.mValue + *(_QWORD *)&v9[1].m_Flags + 8i64)
                        + *(_QWORD *)&v9[1].m_TypeUID
                        + 40)) != 0
    && (v12 = *(UFG::SimObjectGame **)(56i64
                                     * *(unsigned __int8 *)(this->mTarget2Owner.mValue
                                                          + *(_QWORD *)&m_pComponent[1].m_Flags
                                                          + 8i64)
                                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                     + 40)) != 0i64
    && ((v13 = v12->m_Flags, (v13 & 0x4000) == 0)
      ? (v13 >= 0
       ? ((v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 v12,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v12, UFG::TargetingSystemBaseComponent::_TypeUID)),
          v14 = ComponentOfTypeHK)
       : (v14 = v12->m_Components.p[20].m_pComponent))
      : (v14 = v12->m_Components.p[20].m_pComponent),
        v14
     && (v16 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(this->mTarget2Type.mValue + *(_QWORD *)&v14[1].m_Flags + 8i64)
                         + *(_QWORD *)&v14[1].m_TypeUID
                         + 40)) != 0) )
  {
    return v11 == v16;
  }
  else
  {
    return 0;
  }
}

// File Line: 11993
// RVA: 0x148C2F0
__int64 dynamic_initializer_for__TargetInventoryItemCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetInventoryItemCondition", 0xFFFFFFFF);
  TargetInventoryItemCondition::sClassNameUID = result;
  return result;
}

// File Line: 12001
// RVA: 0x278AD0
void __fastcall TargetInventoryItemCondition::TargetInventoryItemCondition(TargetInventoryItemCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetInventoryItemCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
}

// File Line: 12006
// RVA: 0x28C4F0
bool __fastcall TargetInventoryItemCondition::Match(TargetInventoryItemCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *Target; // rax
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  Target = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)this->mTargetType);
  result = Target
        && (m_Flags = Target->m_Flags, (m_Flags & 0x4000) == 0)
        && m_Flags >= 0
        && ((m_Flags & 0x2000) == 0
          ? ((m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(Target, UFG::InventoryItemComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::InventoryItemComponent::_TypeUID)),
             m_pComponent = ComponentOfType)
          : (m_pComponent = Target->m_Components.p[11].m_pComponent),
            m_pComponent)
        && LODWORD(m_pComponent[1].m_pSimObject) == this->mInventoryItemType;
  return result;
}

// File Line: 12034
// RVA: 0x148C6D0
__int64 dynamic_initializer_for__TargetSimObjectTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectTypeCondition", 0xFFFFFFFF);
  TargetSimObjectTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 12042
// RVA: 0x279110
void __fastcall TargetSimObjectTypeCondition::TargetSimObjectTypeCondition(TargetSimObjectTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectTypeCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
}

// File Line: 12047
// RVA: 0x28F6D0
bool __fastcall TargetSimObjectTypeCondition::Match(TargetSimObjectTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *Target; // rax
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  Target = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)this->mTargetType);
  result = Target
        && ((m_Flags = Target->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) == 0
            ? ((m_Flags & 0x1000) == 0
             ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                    Target,
                                    UFG::SimObjectPropertiesComponent::_TypeUID))
             : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    Target,
                                    UFG::SimObjectPropertiesComponent::_TypeUID)),
               m_pComponent = ComponentOfType)
            : (m_pComponent = Target->m_Components.p[4].m_pComponent))
           : (m_pComponent = Target->m_Components.p[3].m_pComponent))
          : (m_pComponent = Target->m_Components.p[3].m_pComponent),
            m_pComponent)
        && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == this->mSimObjectType;
  return result;
}

// File Line: 12080
// RVA: 0x148C7D0
__int64 dynamic_initializer_for__TargetSimObjectWeaponTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectWeaponTypeCondition", 0xFFFFFFFF);
  TargetSimObjectWeaponTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 12088
// RVA: 0x279320
void __fastcall TargetSimObjectWeaponTypeCondition::TargetSimObjectWeaponTypeCondition(
        TargetSimObjectWeaponTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponTypeCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
}

// File Line: 12093
// RVA: 0x290260
bool __fastcall TargetSimObjectWeaponTypeCondition::Match(
        TargetSimObjectWeaponTypeCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectProp *v7; // rcx
  __int16 v8; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectProp **)(56i64
                              * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 )
    goto LABEL_19;
  if ( (v8 & 0x2000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v7);
    goto LABEL_21;
  }
  if ( (v8 & 0x1000) != 0 )
LABEL_19:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v7,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v7,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_21:
  if ( ComponentOfTypeHK )
    return ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mSimObjectWeaponType == this->mSimObjectWeaponType;
  return 0;
}

// File Line: 12128
// RVA: 0x148C730
__int64 dynamic_initializer_for__TargetSimObjectWeaponAmmoInventoryItemCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectWeaponAmmoInventoryItemCondition", 0xFFFFFFFF);
  TargetSimObjectWeaponAmmoInventoryItemCondition::sClassNameUID = result;
  return result;
}

// File Line: 12137
// RVA: 0x2791E0
void __fastcall TargetSimObjectWeaponAmmoInventoryItemCondition::TargetSimObjectWeaponAmmoInventoryItemCondition(
        TargetSimObjectWeaponAmmoInventoryItemCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponAmmoInventoryItemCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
}

// File Line: 12141
// RVA: 0x28FB60
bool __fastcall TargetSimObjectWeaponAmmoInventoryItemCondition::Match(
        TargetSimObjectWeaponAmmoInventoryItemCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectProp *v7; // rbx
  __int16 v8; // cx
  CAkChainCtx *v9; // rax
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax
  __int16 v11; // cx
  __int64 iFadeOffset; // rdi
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectProp **)(56i64
                              * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x400) != 0 )
    return 0;
  v9 = (CAkChainCtx *)((v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
                     ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID)
                     : UFG::SimObject::GetComponentOfType(v7, UFG::GunComponent::_TypeUID));
  if ( !v9 )
    return 0;
  SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v9);
  v11 = v7->m_Flags;
  iFadeOffset = SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset;
  if ( (v11 & 0x4000) != 0 || v11 < 0 )
    goto LABEL_28;
  if ( (v11 & 0x2000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v7);
    goto LABEL_30;
  }
  if ( (v11 & 0x1000) != 0 )
LABEL_28:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v7,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v7,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_30:
  if ( ComponentOfTypeHK )
    return ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[iFadeOffset]->mAmmoInventoryItem == this->mAmmoItem;
  return 0;
}

// File Line: 12192
// RVA: 0x148C690
__int64 dynamic_initializer_for__TargetSimObjectBooleanCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectBooleanCondition", 0xFFFFFFFF);
  TargetSimObjectBooleanCondition::sClassNameUID = result;
  return result;
}

// File Line: 12202
// RVA: 0x279090
void __fastcall TargetSimObjectBooleanCondition::TargetSimObjectBooleanCondition(TargetSimObjectBooleanCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectBooleanCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
  this->mIsTrue = 1;
}

// File Line: 12207
// RVA: 0x28F410
bool __fastcall TargetSimObjectBooleanCondition::Match(TargetSimObjectBooleanCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  __int64 v12; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  if ( !*(_QWORD *)(56i64
                  * *(unsigned __int8 *)((unsigned int)this->mTargetType + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64)
                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                  + 40) )
    return 0;
  v8 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
  {
    v10 = v8->m_Components.p[3].m_pComponent;
  }
  else if ( v9 >= 0 )
  {
    if ( (v9 & 0x2000) != 0 )
    {
      v10 = v8->m_Components.p[4].m_pComponent;
    }
    else
    {
      v11 = (v9 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::SimObjectPropertiesComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(v8, UFG::SimObjectPropertiesComponent::_TypeUID);
      v10 = v11;
    }
  }
  else
  {
    v10 = v8->m_Components.p[3].m_pComponent;
  }
  if ( !v10 )
    return 0;
  v12 = *((_QWORD *)&v10[1].m_Flags + ((__int64)this->mSimObjectBoolean >> 6));
  return _bittest64(&v12, this->mSimObjectBoolean & 0x3F) == (this->mIsTrue != 0);
}

// File Line: 12249
// RVA: 0x148C750
__int64 dynamic_initializer_for__TargetSimObjectWeaponBooleanCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectWeaponBooleanCondition", 0xFFFFFFFF);
  TargetSimObjectWeaponBooleanCondition::sClassNameUID = result;
  return result;
}

// File Line: 12260
// RVA: 0x279220
void __fastcall TargetSimObjectWeaponBooleanCondition::TargetSimObjectWeaponBooleanCondition(
        TargetSimObjectWeaponBooleanCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponBooleanCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
  this->mIsTrue = 1;
}

// File Line: 12265
// RVA: 0x28FD50
bool __fastcall TargetSimObjectWeaponBooleanCondition::Match(
        TargetSimObjectWeaponBooleanCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectProp *v7; // rcx
  __int16 v8; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  bool v10; // bl

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectProp **)(56i64
                              * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 )
    goto LABEL_19;
  if ( (v8 & 0x2000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v7);
    goto LABEL_21;
  }
  if ( (v8 & 0x1000) != 0 )
LABEL_19:
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v7,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v7,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_21:
  if ( ComponentOfTypeHK )
  {
    v10 = this->mIsTrue != 0;
    return UFG::SimObjectWeaponPropertiesComponent::GetBooleanValue(
             ComponentOfTypeHK,
             (UFG::eSimObjectWeaponBooleanEnum)this->mSimObjectWeaponBoolean) == v10;
  }
  return 0;
}

// File Line: 12304
// RVA: 0x148C6B0
__int64 dynamic_initializer_for__TargetSimObjectCharacterBooleanCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectCharacterBooleanCondition", 0xFFFFFFFF);
  TargetSimObjectCharacterBooleanCondition::sClassNameUID = result;
  return result;
}

// File Line: 12314
// RVA: 0x2790D0
void __fastcall TargetSimObjectCharacterBooleanCondition::TargetSimObjectCharacterBooleanCondition(
        TargetSimObjectCharacterBooleanCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectCharacterBooleanCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
  this->mIsTrue = 1;
}

// File Line: 12327
// RVA: 0x28F580
bool __fastcall TargetSimObjectCharacterBooleanCondition::Match(
        TargetSimObjectCharacterBooleanCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::SimObjectCharacterPropertiesComponent *v9; // rax
  unsigned __int64 v10; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectCVBase **)(56i64
                                * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                     + *(_QWORD *)&m_pComponent[1].m_Flags
                                                     + 8i64)
                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 )
    v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v7);
  else
    v9 = (UFG::SimObjectCharacterPropertiesComponent *)((v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
                                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v7,
                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                      : UFG::SimObject::GetComponentOfType(
                                                          v7,
                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
  if ( !v9 )
    return 0;
  v10 = v9->mBooleans.mBits[(__int64)this->mSimObjectCharacterBoolean >> 6];
  return _bittest64((const __int64 *)&v10, this->mSimObjectCharacterBoolean & 0x3F) == (this->mIsTrue != 0);
}

// File Line: 12359
// RVA: 0x148BF30
__int64 dynamic_initializer_for__SimObjectCharacterBooleanCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SimObjectCharacterBooleanCondition", 0xFFFFFFFF);
  SimObjectCharacterBooleanCondition::sClassNameUID = result;
  return result;
}

// File Line: 12367
// RVA: 0x2784B0
void __fastcall SimObjectCharacterBooleanCondition::SimObjectCharacterBooleanCondition(
        SimObjectCharacterBooleanCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SimObjectCharacterBooleanCondition::`vftable;
  this->mSimObjectCharacterBoolean = 0;
  this->mIsTrue = 1;
}

// File Line: 12378
// RVA: 0x289920
bool __fastcall SimObjectCharacterBooleanCondition::Match(
        SimObjectCharacterBooleanCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax
  unsigned __int64 v6; // rax

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
  else
    v5 = (UFG::SimObjectCharacterPropertiesComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                      : UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
  if ( !v5 )
    return 0;
  v6 = v5->mBooleans.mBits[(__int64)this->mSimObjectCharacterBoolean >> 6];
  return _bittest64((const __int64 *)&v6, this->mSimObjectCharacterBoolean & 0x3F) == (this->mIsTrue != 0);
}

// File Line: 12401
// RVA: 0x148C710
__int64 dynamic_initializer_for__TargetSimObjectWeaponAmmoCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectWeaponAmmoCondition", 0xFFFFFFFF);
  TargetSimObjectWeaponAmmoCondition::sClassNameUID = result;
  return result;
}

// File Line: 12417
// RVA: 0x279190
void __fastcall TargetSimObjectWeaponAmmoCondition::TargetSimObjectWeaponAmmoCondition(
        TargetSimObjectWeaponAmmoCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponAmmoCondition::`vftable;
  this->mTargetType = 0;
  *(_QWORD *)&this->mInEqualityOperator.mValue = 1i64;
  *(_WORD *)&this->mCheckClip = 1;
  this->mUsePercentage = 0;
}

// File Line: 12422
// RVA: 0x28F8B0
char __fastcall TargetSimObjectWeaponAmmoCondition::Match(
        TargetSimObjectWeaponAmmoCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::GunComponent *ComponentOfTypeHK; // rax
  CAkChainCtx *v10; // rbx
  bool v11; // r14
  bool v12; // si
  int ClipAmmo; // eax
  int v14; // ebp
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax
  int v16; // r8d
  char v17; // bp
  int v18; // esi
  CAkScheduledItem *v19; // rax
  __int64 v20; // r15
  __int64 v21; // rcx
  CAkScheduledItem *v22; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
    ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(v7, UFG::GunComponent::_TypeUID);
  v10 = (CAkChainCtx *)ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  v11 = 1;
  v12 = 1;
  if ( this->mCheckClip )
  {
    ClipAmmo = UFG::GunComponent::GetClipAmmo(ComponentOfTypeHK);
    v14 = ClipAmmo;
    if ( this->mUsePercentage )
    {
      SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v10);
      v16 = (int)(float)((float)((float)v14
                               / (float)*(int *)(*(_QWORD *)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                                                           + 8i64
                                                           * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                                                           + 8)
                                               + 8i64))
                       * 100.0);
    }
    else
    {
      v16 = ClipAmmo;
    }
    v11 = CompareInt((UFG::InEqualityOperator)this->mInEqualityOperator.mValue, this->mQuantity, v16);
  }
  v17 = 1;
  if ( this->mCheckTotal )
  {
    v18 = 0;
    if ( UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v10) )
    {
      v19 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v10);
      v20 = *(int *)(*(_QWORD *)(*(_QWORD *)&v19[2].m_cmdStop.iRelativeTime
                               + 8i64 * (unsigned int)v19[2].m_cmdPlay.fadeParams.iFadeOffset
                               + 8)
                   + 4i64);
      if ( UFG::UIHKPlayerObjective::GetObjective((Render::SimpleDrawableComponent *)v10) )
      {
        if ( *(_QWORD *)&UFG::UIHKPlayerObjective::GetObjective((Render::SimpleDrawableComponent *)v10)->mAABBMin.x )
        {
          v21 = *(_QWORD *)&UFG::UIHKPlayerObjective::GetObjective((Render::SimpleDrawableComponent *)v10)->mAABBMin.x;
          if ( !*(_BYTE *)(v21 + 936) || (v18 = 1, (_DWORD)v20 != *(_DWORD *)(v21 + 928)) )
            v18 = *(_DWORD *)(v21 + 4 * v20 + 92);
        }
      }
      if ( this->mUsePercentage )
      {
        v22 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v10);
        v18 = (int)(float)((float)((float)v18
                                 / (float)*(int *)(*(_QWORD *)(*(_QWORD *)&v22[2].m_cmdStop.iRelativeTime
                                                             + 8i64
                                                             * (unsigned int)v22[2].m_cmdPlay.fadeParams.iFadeOffset
                                                             + 8)
                                                 + 12i64))
                         * 100.0);
      }
    }
    v12 = CompareInt((UFG::InEqualityOperator)this->mInEqualityOperator.mValue, this->mQuantity, v18);
  }
  if ( !v11 || !v12 )
    return 0;
  return v17;
}

// File Line: 12508
// RVA: 0x148C890
__int64 dynamic_initializer_for__TargetWeaponAmmoCompatibleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetWeaponAmmoCompatibleCondition", 0xFFFFFFFF);
  TargetWeaponAmmoCompatibleCondition::sClassNameUID = result;
  return result;
}

// File Line: 12516
// RVA: 0x2793A0
void __fastcall TargetWeaponAmmoCompatibleCondition::TargetWeaponAmmoCompatibleCondition(
        TargetWeaponAmmoCompatibleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetWeaponAmmoCompatibleCondition::`vftable;
  this->mFirstTargetType = 17;
  this->mSecondTargetType = 41;
}

// File Line: 12521
// RVA: 0x2906D0
char __fastcall TargetWeaponAmmoCompatibleCondition::Match(
        TargetWeaponAmmoCompatibleCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  __int64 v6; // rdx
  __int64 v7; // r8
  UFG::SimObjectGame *v8; // r9
  UFG::SimObjectGame *v9; // rbx
  __int16 v10; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v12; // dx
  CAkChainCtx *v13; // rsi
  UFG::SimComponent *ComponentOfType; // rax
  CAkChainCtx *v15; // rdi
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rbx
  CAkScheduledItem *v17; // rax
  __int64 v18; // r11
  __int64 v19; // rbx
  __int64 v20; // rdi
  __int64 v21; // r10
  __int64 i; // r11
  __int64 v23; // rcx
  __int64 v24; // rdx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v6 = *(_QWORD *)&m_pComponent[1].m_Flags;
  v7 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
  v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)((unsigned int)this->mFirstTargetType + v6 + 8) + v7 + 40);
  v9 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)((unsigned int)this->mSecondTargetType + v6 + 8) + v7 + 40);
  if ( !v8 || !v9 )
    return 0;
  v10 = v8->m_Flags;
  if ( (v10 & 0x4000) != 0 || v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::GunComponent::_TypeUID);
  v12 = v9->m_Flags;
  v13 = (CAkChainCtx *)ComponentOfTypeHK;
  if ( (v12 & 0x4000) != 0 || v12 < 0 || (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
  else
    ComponentOfType = UFG::SimObject::GetComponentOfType(v9, UFG::GunComponent::_TypeUID);
  v15 = (CAkChainCtx *)ComponentOfType;
  if ( !v13 )
    return 0;
  if ( !ComponentOfType )
    return 0;
  SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v13);
  v17 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v15);
  v18 = *(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime;
  v19 = *(unsigned int *)(v18 + 4);
  v20 = *(_QWORD *)&v17[2].m_cmdStop.iRelativeTime;
  v21 = 0i64;
  if ( !*(_DWORD *)(v18 + 4) )
    return 0;
  for ( i = v18 + 8; ; i += 8i64 )
  {
    v23 = 0i64;
    if ( *(_DWORD *)(v20 + 4) )
      break;
LABEL_35:
    if ( ++v21 >= v19 )
      return 0;
  }
  v24 = v20 + 8;
  while ( *(_DWORD *)(*(_QWORD *)i + 4i64) != *(_DWORD *)(*(_QWORD *)v24 + 4i64) )
  {
    ++v23;
    v24 += 8i64;
    if ( v23 >= *(unsigned int *)(v20 + 4) )
      goto LABEL_35;
  }
  return 1;
}

// File Line: 12581
// RVA: 0x148C770
__int64 dynamic_initializer_for__TargetSimObjectWeaponCanFireCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectWeaponCanFireCondition", 0xFFFFFFFF);
  TargetSimObjectWeaponCanFireCondition::sClassNameUID = result;
  return result;
}

// File Line: 12587
// RVA: 0x279260
void __fastcall TargetSimObjectWeaponCanFireCondition::TargetSimObjectWeaponCanFireCondition(
        TargetSimObjectWeaponCanFireCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponCanFireCondition::`vftable;
  this->mTargetType = 0;
}

// File Line: 12591
// RVA: 0x28FE90
bool __fastcall TargetSimObjectWeaponCanFireCondition::Match(
        TargetSimObjectWeaponCanFireCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::GunComponent *v11; // rbx
  bool IsAnyLocalPlayer; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::GunComponent::_TypeUID);
  v11 = (UFG::GunComponent *)ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return 0;
  IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(pContext->mSimObject.m_pPointer);
  return UFG::GunComponent::CanFireWeapon(v11, !IsAnyLocalPlayer);
}

// File Line: 12628
// RVA: 0x148C7B0
__int64 dynamic_initializer_for__TargetSimObjectWeaponIsAutomaticCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectWeaponIsAutomaticCondition", 0xFFFFFFFF);
  TargetSimObjectWeaponIsAutomaticCondition::sClassNameUID = result;
  return result;
}

// File Line: 12634
// RVA: 0x2792E0
void __fastcall TargetSimObjectWeaponIsAutomaticCondition::TargetSimObjectWeaponIsAutomaticCondition(
        TargetSimObjectWeaponIsAutomaticCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponIsAutomaticCondition::`vftable;
  this->mTargetType = 0;
}

// File Line: 12638
// RVA: 0x290110
bool __fastcall TargetSimObjectWeaponIsAutomaticCondition::Match(
        TargetSimObjectWeaponIsAutomaticCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::GunComponent::_TypeUID);
  if ( !ComponentOfTypeHK )
    return 0;
  SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)ComponentOfTypeHK);
  return *(_BYTE *)(*(_QWORD *)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                              + 8i64
                              * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                              + 8)
                  + 117i64);
}

// File Line: 12678
// RVA: 0x148C790
__int64 dynamic_initializer_for__TargetSimObjectWeaponCanReloadCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectWeaponCanReloadCondition", 0xFFFFFFFF);
  TargetSimObjectWeaponCanReloadCondition::sClassNameUID = result;
  return result;
}

// File Line: 12684
// RVA: 0x2792A0
void __fastcall TargetSimObjectWeaponCanReloadCondition::TargetSimObjectWeaponCanReloadCondition(
        TargetSimObjectWeaponCanReloadCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponCanReloadCondition::`vftable;
  this->mTargetType = 0;
}

// File Line: 12688
// RVA: 0x28FFE0
char __fastcall TargetSimObjectWeaponCanReloadCondition::Match(
        TargetSimObjectWeaponCanReloadCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::GunComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
      : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
        m_pComponent
     && (v7 = *(UFG::SimObjectGame **)(56i64
                                     * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                          + *(_QWORD *)&m_pComponent[1].m_Flags
                                                          + 8i64)
                                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                     + 40)) != 0i64
     && ((v8 = v7->m_Flags, (v8 & 0x4000) == 0) && v8 >= 0 && (v8 & 0x2000) == 0 && (v8 & 0x1000) == 0
       ? (ComponentOfType = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(v7, UFG::GunComponent::_TypeUID))
       : (ComponentOfType = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v7,
                                                   UFG::GunComponent::_TypeUID)),
         ComponentOfType)) )
  {
    return UFG::GunComponent::CanReload(ComponentOfType);
  }
  else
  {
    return 0;
  }
}

// File Line: 12728
// RVA: 0x148C6F0
__int64 dynamic_initializer_for__TargetSimObjectVehicleTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectVehicleTypeCondition", 0xFFFFFFFF);
  TargetSimObjectVehicleTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 12736
// RVA: 0x279150
void __fastcall TargetSimObjectVehicleTypeCondition::TargetSimObjectVehicleTypeCondition(
        TargetSimObjectVehicleTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectVehicleTypeCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 28i64;
}

// File Line: 12741
// RVA: 0x28F780
bool __fastcall TargetSimObjectVehicleTypeCondition::Match(
        TargetSimObjectVehicleTypeCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::SimObjectVehiclePropertiesComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                           * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                                + *(_QWORD *)&m_pComponent[1].m_Flags
                                                                + 8i64)
                                           + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                           + 40)) != 0i64
         && ((v8 = v7->m_Flags, (v8 & 0x4000) != 0) || v8 < 0
           ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v7))
           : (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
           ? (ComponentOfType = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                              v7,
                                                                              UFG::SimObjectVehiclePropertiesComponent::_TypeUID))
           : (ComponentOfType = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                              v7,
                                                                              UFG::SimObjectVehiclePropertiesComponent::_TypeUID)),
             ComponentOfType))
        && ComponentOfType->m_eSimObjectVehicleType == this->mSimObjectVehicleType;
  return result;
}

// File Line: 12777
// RVA: 0x148BF70
__int64 dynamic_initializer_for__SimObjectVehicleTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SimObjectVehicleTypeCondition", 0xFFFFFFFF);
  SimObjectVehicleTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 12783
// RVA: 0x278530
void __fastcall SimObjectVehicleTypeCondition::SimObjectVehicleTypeCondition(SimObjectVehicleTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SimObjectVehicleTypeCondition::`vftable;
  this->mSimObjectVehicleType = 0;
}

// File Line: 12788
// RVA: 0x289A70
bool __fastcall SimObjectVehicleTypeCondition::Match(SimObjectVehicleTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectVehiclePropertiesComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                               m_pPointer,
                                                                               UFG::SimObjectVehiclePropertiesComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                               m_pPointer,
                                                                               UFG::SimObjectVehiclePropertiesComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_eSimObjectVehicleType == this->mSimObjectVehicleType;
  return result;
}

// File Line: 12814
// RVA: 0x148C670
__int64 dynamic_initializer_for__TargetSimObjectBoatTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetSimObjectBoatTypeCondition", 0xFFFFFFFF);
  TargetSimObjectBoatTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 12822
// RVA: 0x279050
void __fastcall TargetSimObjectBoatTypeCondition::TargetSimObjectBoatTypeCondition(
        TargetSimObjectBoatTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectBoatTypeCondition::`vftable;
  *(_QWORD *)&this->mTargetType = 0i64;
}

// File Line: 12827
// RVA: 0x28F2D0
bool __fastcall TargetSimObjectBoatTypeCondition::Match(
        TargetSimObjectBoatTypeCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::SimObjectVehiclePropertiesComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent
         && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                           * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                                + *(_QWORD *)&m_pComponent[1].m_Flags
                                                                + 8i64)
                                           + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                           + 40)) != 0i64
         && ((v8 = v7->m_Flags, (v8 & 0x4000) != 0) || v8 < 0
           ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v7))
           : (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
           ? (ComponentOfType = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                              v7,
                                                                              UFG::SimObjectVehiclePropertiesComponent::_TypeUID))
           : (ComponentOfType = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                              v7,
                                                                              UFG::SimObjectVehiclePropertiesComponent::_TypeUID)),
             ComponentOfType && ComponentOfType->m_eSimObjectVehicleType == eSIM_OBJ_VEHICLE_TYPE_BOAT))
        && ComponentOfType->m_eSimObjectBoatType == this->mSimObjectBoatType;
  return result;
}

// File Line: 12865
// RVA: 0x148BF10
__int64 dynamic_initializer_for__SimObjectBoatTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SimObjectBoatTypeCondition", 0xFFFFFFFF);
  SimObjectBoatTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 12871
// RVA: 0x278470
void __fastcall SimObjectBoatTypeCondition::SimObjectBoatTypeCondition(SimObjectBoatTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SimObjectBoatTypeCondition::`vftable;
  this->mSimObjectBoatType = 0;
}

// File Line: 12876
// RVA: 0x289880
bool __fastcall SimObjectBoatTypeCondition::Match(SimObjectBoatTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectVehiclePropertiesComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                               m_pPointer,
                                                                               UFG::SimObjectVehiclePropertiesComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                               m_pPointer,
                                                                               UFG::SimObjectVehiclePropertiesComponent::_TypeUID)),
            ComponentOfTypeHK && ComponentOfTypeHK->m_eSimObjectVehicleType == eSIM_OBJ_VEHICLE_TYPE_BOAT)
        && ComponentOfTypeHK->m_eSimObjectBoatType == this->mSimObjectBoatType;
  return result;
}

// File Line: 12902
// RVA: 0x148BA10
__int64 dynamic_initializer_for__NumCharactersDeadCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NumCharactersDeadCondition", 0xFFFFFFFF);
  NumCharactersDeadCondition::sClassNameUID = result;
  return result;
}

// File Line: 12909
// RVA: 0x277CC0
void __fastcall NumCharactersDeadCondition::NumCharactersDeadCondition(NumCharactersDeadCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&NumCharactersDeadCondition::`vftable;
  this->m_Number = 0;
}

// File Line: 12928
// RVA: 0x148AA30
__int64 dynamic_initializer_for__CharacterIsAliveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CharacterIsAliveCondition", 0xFFFFFFFF);
  CharacterIsAliveCondition::sClassNameUID = result;
  return result;
}

// File Line: 12933
// RVA: 0x2767E0
void __fastcall CharacterIsAliveCondition::CharacterIsAliveCondition(CharacterIsAliveCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CharacterIsAliveCondition::`vftable;
  this->m_Name.mOffset = 1i64;
  BinString::Set(&this->m_Name, &customCaption);
}

// File Line: 12953
// RVA: 0x148B150
__int64 dynamic_initializer_for__IncomingAttackPhaseCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IncomingAttackPhaseCondition", 0xFFFFFFFF);
  IncomingAttackPhaseCondition::sClassNameUID = result;
  return result;
}

// File Line: 12959
// RVA: 0x277380
void __fastcall IncomingAttackPhaseCondition::IncomingAttackPhaseCondition(IncomingAttackPhaseCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IncomingAttackPhaseCondition::`vftable;
  this->m_eAttackPhase.mValue = 1;
}

// File Line: 12963
// RVA: 0x282C50
bool __fastcall IncomingAttackPhaseCondition::Match(IncomingAttackPhaseCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && LODWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev) == this->m_eAttackPhase.mValue;
  return result;
}

// File Line: 12988
// RVA: 0x148B170
__int64 dynamic_initializer_for__IncomingAttackTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IncomingAttackTypeCondition", 0xFFFFFFFF);
  IncomingAttackTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 12994
// RVA: 0x2773C0
void __fastcall IncomingAttackTypeCondition::IncomingAttackTypeCondition(IncomingAttackTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IncomingAttackTypeCondition::`vftable;
  this->mAttackTypeID = 0;
}

// File Line: 12998
// RVA: 0x282D00
bool __fastcall IncomingAttackTypeCondition::Match(IncomingAttackTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && HIDWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev) == this->mAttackTypeID;
  return result;
}

// File Line: 13022
// RVA: 0x148B130
__int64 dynamic_initializer_for__IncomingAttackLocationLateralCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IncomingAttackLocationLateralCondition", 0xFFFFFFFF);
  IncomingAttackLocationLateralCondition::sClassNameUID = result;
  return result;
}

// File Line: 13028
// RVA: 0x277340
void __fastcall IncomingAttackLocationLateralCondition::IncomingAttackLocationLateralCondition(
        IncomingAttackLocationLateralCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IncomingAttackLocationLateralCondition::`vftable;
  this->mAttackLocationLateralID = 0;
}

// File Line: 13032
// RVA: 0x282BA0
bool __fastcall IncomingAttackLocationLateralCondition::Match(
        IncomingAttackLocationLateralCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && this->mAttackLocationLateralID == LODWORD(m_pComponent[2].m_pSimObject);
  return result;
}

// File Line: 13057
// RVA: 0x148B110
__int64 dynamic_initializer_for__IncomingAttackLocationHorizontalCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IncomingAttackLocationHorizontalCondition", 0xFFFFFFFF);
  IncomingAttackLocationHorizontalCondition::sClassNameUID = result;
  return result;
}

// File Line: 13063
// RVA: 0x277300
void __fastcall IncomingAttackLocationHorizontalCondition::IncomingAttackLocationHorizontalCondition(
        IncomingAttackLocationHorizontalCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IncomingAttackLocationHorizontalCondition::`vftable;
  this->mAttackLocationHorizontalID = 0;
}

// File Line: 13067
// RVA: 0x282AF0
bool __fastcall IncomingAttackLocationHorizontalCondition::Match(
        IncomingAttackLocationHorizontalCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[15].m_pComponent),
            m_pComponent)
        && this->mAttackLocationHorizontalID == HIDWORD(m_pComponent[2].m_pSimObject);
  return result;
}

// File Line: 13090
// RVA: 0x148BA90
__int64 dynamic_initializer_for__ObjectRequestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ObjectRequestCondition", 0xFFFFFFFF);
  ObjectRequestCondition::sClassNameUID = result;
  return result;
}

// File Line: 13126
// RVA: 0x148BD90
__int64 dynamic_initializer_for__PlayerMeleeUpgradeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerMeleeUpgradeCondition", 0xFFFFFFFF);
  PlayerMeleeUpgradeCondition::sClassNameUID = result;
  return result;
}

// File Line: 13136
// RVA: 0x278210
void __fastcall PlayerMeleeUpgradeCondition::PlayerMeleeUpgradeCondition(PlayerMeleeUpgradeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerMeleeUpgradeCondition::`vftable;
  this->mLevel = 0;
  *(_WORD *)&this->mInEqualityOperator.mValue = 259;
}

// File Line: 13140
// RVA: 0x288F40
bool __fastcall PlayerMeleeUpgradeCondition::Match(PlayerMeleeUpgradeCondition *this, ActionContext *context)
{
  BOOL v3; // ebx
  UFG::GameStatTracker *v4; // rax
  int Stat; // eax

  v3 = this->mMoveType.mValue == 1;
  v4 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v4, (UFG::GameStat::Int32Stat)(v3 + 22));
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mLevel, Stat);
}

// File Line: 13162
// RVA: 0x148BCB0
__int64 dynamic_initializer_for__PlayerGunplayUpgradeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerGunplayUpgradeCondition", 0xFFFFFFFF);
  PlayerGunplayUpgradeCondition::sClassNameUID = result;
  return result;
}

// File Line: 13170
// RVA: 0x278050
void __fastcall PlayerGunplayUpgradeCondition::PlayerGunplayUpgradeCondition(PlayerGunplayUpgradeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerGunplayUpgradeCondition::`vftable;
  this->mLevel = 0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 13174
// RVA: 0x288D00
bool __fastcall PlayerGunplayUpgradeCondition::Match(PlayerGunplayUpgradeCondition *this, ActionContext *context)
{
  UFG::GameStatTracker *v3; // rax
  int Stat; // eax

  v3 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v3, GunplayUpgradeStage);
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mLevel, Stat);
}

// File Line: 13196
// RVA: 0x148BC90
__int64 dynamic_initializer_for__PlayerCopUpgradeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerCopUpgradeCondition", 0xFFFFFFFF);
  PlayerCopUpgradeCondition::sClassNameUID = result;
  return result;
}

// File Line: 13206
// RVA: 0x278010
void __fastcall PlayerCopUpgradeCondition::PlayerCopUpgradeCondition(PlayerCopUpgradeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerCopUpgradeCondition::`vftable;
  this->mLevel = 0;
  *(_WORD *)&this->mInEqualityOperator.mValue = 259;
}

// File Line: 13210
// RVA: 0x288CC0
bool __fastcall PlayerCopUpgradeCondition::Match(PlayerCopUpgradeCondition *this, ActionContext *context)
{
  BOOL v3; // ebx
  UFG::GameStatTracker *v4; // rax
  int Stat; // eax

  v3 = this->mCopUpgradeType.mValue != 1;
  v4 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v4, (UFG::GameStat::Int32Stat)(v3 + 27));
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mLevel, Stat);
}

// File Line: 13234
// RVA: 0x148BDB0
__int64 dynamic_initializer_for__PlayerTriadUpgradeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerTriadUpgradeCondition", 0xFFFFFFFF);
  PlayerTriadUpgradeCondition::sClassNameUID = result;
  return result;
}

// File Line: 13244
// RVA: 0x278250
void __fastcall PlayerTriadUpgradeCondition::PlayerTriadUpgradeCondition(PlayerTriadUpgradeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerTriadUpgradeCondition::`vftable;
  this->mLevel = 0;
  *(_WORD *)&this->mInEqualityOperator.mValue = 259;
}

// File Line: 13248
// RVA: 0x288F80
bool __fastcall PlayerTriadUpgradeCondition::Match(PlayerTriadUpgradeCondition *this, ActionContext *context)
{
  BOOL v3; // ebx
  UFG::GameStatTracker *v4; // rax
  int Stat; // eax

  v3 = this->mMoveType.mValue == 1;
  v4 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v4, (UFG::GameStat::Int32Stat)(v3 + 24));
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mLevel, Stat);
}

// File Line: 13272
// RVA: 0x148C230
__int64 dynamic_initializer_for__StruggleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("StruggleCondition", 0xFFFFFFFF);
  StruggleCondition::sClassNameUID = result;
  return result;
}

// File Line: 13280
// RVA: 0x2788D0
void __fastcall StruggleCondition::StruggleCondition(StruggleCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&StruggleCondition::`vftable;
  this->mLevel = 1.0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 13285
// RVA: 0x28B780
char __fastcall StruggleCondition::Match(StruggleCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
     && m_Flags >= 0
     && (m_Flags & 0x2000) == 0
     && (m_Flags & 0x1000) == 0
      ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SimObjectSignalMemoryComponent::_TypeUID))
      : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                             m_pPointer,
                             UFG::SimObjectSignalMemoryComponent::_TypeUID)),
        ComponentOfType) )
  {
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
             this->mLevel,
             *(float *)&ComponentOfType[1].m_TypeUID);
  }
  else
  {
    return 0;
  }
}

// File Line: 13314
// RVA: 0x148B190
__int64 dynamic_initializer_for__InputSignalCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InputSignalCondition", 0xFFFFFFFF);
  InputSignalCondition::sClassNameUID = result;
  return result;
}

// File Line: 13326
// RVA: 0x277400
void __fastcall InputSignalCondition::InputSignalCondition(InputSignalCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InputSignalCondition::`vftable;
  this->mValue = 1.0;
  *(_WORD *)&this->mInEqualityOperator.mValue = 3;
  this->mTargetType.mValue = 1;
}

// File Line: 13331
// RVA: 0x282DB0
char __fastcall InputSignalCondition::Match(InputSignalCondition *this, ActionContext *context)
{
  FloatInputSignal mValue; // ebx
  UFG::SimObjectCVBase *Target; // rax
  float SignalValue; // xmm0_4
  UFG::qVector3 v7; // [rsp+30h] [rbp-18h] BYREF

  mValue = (unsigned __int8)this->mFloatInputSignal.mValue;
  Target = (UFG::SimObjectCVBase *)UFG::getTarget(
                                     context->mSimObject.m_pPointer,
                                     (UFG::eTargetTypeEnum)(unsigned __int8)this->mTargetType.mValue);
  v7 = UFG::qVector3::msZero;
  SignalValue = getSignalValue(Target, mValue, 0.0, 6.2831855, &v7);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mValue,
           SignalValue);
}

// File Line: 13359
// RVA: 0x148CE70
__int64 dynamic_initializer_for__WantToUsePOICondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WantToUsePOICondition", 0xFFFFFFFF);
  WantToUsePOICondition::sClassNameUID = result;
  return result;
}

// File Line: 13362
// RVA: 0x293400
unsigned __int8 __fastcall WantToUsePOICondition::Match(WantToUsePOICondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rdi
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v8; // r8
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v10; // cx
  UFG::SimObject *v11; // rcx
  __int16 v12; // dx
  UFG::InterestPoint *v13; // rbx
  UFG::SimObjectGame *v15; // rcx
  __int16 v16; // dx
  UFG::SimComponent *v17; // rax
  UFG::SimObjectCVBase *v18; // rcx
  __int16 v19; // dx
  UFG::AICharacterControllerBaseComponent *v20; // rax
  unsigned int v21; // edx
  bool v22; // zf
  unsigned __int64 v23; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v8 = pContext->mSimObject.m_pPointer;
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      ComponentOfType = v8->m_Components.p[43].m_pComponent;
    }
    else if ( v10 >= 0 )
    {
      if ( (v10 & 0x2000) != 0 )
      {
        ComponentOfType = v8->m_Components.p[12].m_pComponent;
      }
      else if ( (v10 & 0x1000) != 0 )
      {
        ComponentOfType = 0i64;
      }
      else
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            pContext->mSimObject.m_pPointer,
                            UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = 0i64;
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
  if ( m_pComponent )
  {
    if ( ComponentOfType )
    {
      v11 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 & 0x4000) != 0 )
        {
          v13 = (UFG::InterestPoint *)v11->m_Components.p[25].m_pComponent;
        }
        else if ( v12 >= 0 )
        {
          if ( (v12 & 0x2000) != 0 )
            v13 = (UFG::InterestPoint *)v11->m_Components.p[10].m_pComponent;
          else
            v13 = (UFG::InterestPoint *)((v12 & 0x1000) != 0
                                       ? v11->m_Components.p[3].m_pComponent
                                       : UFG::SimObject::GetComponentOfType(v11, UFG::InterestPoint::_TypeUID));
        }
        else
        {
          v13 = (UFG::InterestPoint *)v11->m_Components.p[25].m_pComponent;
        }
        if ( v13 && !UFG::InterestPoint::IsReservationMatch(v13, 0x10u, ReserveReason_normal) )
        {
          if ( UFG::InterestPoint::IsAutoInteractable(v13) )
            return 1;
          v15 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
          if ( v15 )
          {
            v16 = v15->m_Flags;
            if ( (v16 & 0x4000) != 0 )
            {
              v17 = v15->m_Components.p[22].m_pComponent;
            }
            else if ( v16 >= 0 )
            {
              v17 = (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0
                  ? UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::AIEntityComponent::_TypeUID)
                  : UFG::SimObject::GetComponentOfType(v15, UFG::AIEntityComponent::_TypeUID);
            }
            else
            {
              v17 = v15->m_Components.p[22].m_pComponent;
            }
            if ( v17 )
            {
              v18 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
              if ( !v18 )
              {
LABEL_59:
                v23 = v3->m_Intention.mActionRequests.mBits[(__int64)(int)gActionRequest_POI_Use.m_EnumValue >> 6];
                return _bittest64((const __int64 *)&v23, gActionRequest_POI_Use.m_EnumValue & 0x3F);
              }
              v19 = v18->m_Flags;
              if ( (v19 & 0x4000) != 0 || v19 < 0 )
              {
                v20 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v18);
              }
              else
              {
                if ( (v19 & 0x2000) != 0 )
                {
                  v21 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                }
                else
                {
                  v22 = (v19 & 0x1000) == 0;
                  v21 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                  if ( v22 )
                  {
                    v20 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v18,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
                    goto LABEL_58;
                  }
                }
                v20 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v18, v21);
              }
LABEL_58:
              v3 = v20;
              goto LABEL_59;
            }
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 13417
// RVA: 0x148BB70
__int64 dynamic_initializer_for__POIWeatherFilterOnWithIsRainingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIWeatherFilterOnWithIsRainingCondition", 0xFFFFFFFF);
  POIWeatherFilterOnWithIsRainingCondition::sClassNameUID = result;
  return result;
}

// File Line: 13420
// RVA: 0x286880
bool __fastcall POIWeatherFilterOnWithIsRainingCondition::Match(
        POIWeatherFilterOnWithIsRainingCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  __int16 v7; // dx
  UFG::InterestPoint *ComponentOfType; // rbx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v5;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  if ( !v6 )
    return 0;
  v7 = v6->m_Flags;
  if ( (v7 & 0x4000) != 0 )
  {
    ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
  }
  else if ( v7 >= 0 )
  {
    if ( (v7 & 0x2000) != 0 )
    {
      ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent;
    }
    else if ( (v7 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent;
    }
    else
    {
      ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
  }
  return ComponentOfType
      && UFG::InterestPoint::GetWeatherFilterOn(ComponentOfType)
      && UFG::InterestPoint::GetWeatherFilterIsRaining(ComponentOfType);
}

// File Line: 13447
// RVA: 0x148BB10
__int64 dynamic_initializer_for__POIIgnoreStimuliCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIIgnoreStimuliCondition", 0xFFFFFFFF);
  POIIgnoreStimuliCondition::sClassNameUID = result;
  return result;
}

// File Line: 13450
// RVA: 0x286500
bool __fastcall POIIgnoreStimuliCondition::Match(POIIgnoreStimuliCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  __int16 v7; // dx
  UFG::InterestPoint *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v5;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  if ( !v6 )
    return 0;
  v7 = v6->m_Flags;
  if ( (v7 & 0x4000) != 0 )
  {
    ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
  }
  else if ( v7 >= 0 )
  {
    if ( (v7 & 0x2000) != 0 )
    {
      ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent;
    }
    else if ( (v7 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent;
    }
    else
    {
      ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
  }
  return ComponentOfType && UFG::InterestPoint::GetIgnoreStimuli(ComponentOfType);
}

// File Line: 13477
// RVA: 0x148BB50
__int64 dynamic_initializer_for__POIParentObjectHasOwner::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIParentObjectHasOwner", 0xFFFFFFFF);
  POIParentObjectHasOwner::sClassNameUID = result;
  return result;
}

// File Line: 13480
// RVA: 0x2866E0
bool __fastcall POIParentObjectHasOwner::Match(POIParentObjectHasOwner *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  __int16 v7; // dx
  UFG::InterestPoint *ComponentOfType; // rax
  UFG::SimObjectGame *ParentObject; // rax
  __int16 v10; // dx
  UFG::InventoryItemComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v5;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( m_pComponent
    && (v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                + 40)) != 0i64
    && ((v7 = v6->m_Flags, (v7 & 0x4000) == 0)
      ? (v7 >= 0
       ? ((v7 & 0x2000) == 0
        ? ((v7 & 0x1000) == 0
         ? (ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID))
         : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent))
        : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent))
       : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent))
      : (ComponentOfType = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent),
        ComponentOfType
     && (ParentObject = (UFG::SimObjectGame *)UFG::InterestPoint::GetParentObject(ComponentOfType)) != 0i64
     && (v10 = ParentObject->m_Flags, (v10 & 0x4000) == 0)
     && v10 >= 0
     && ((v10 & 0x2000) == 0
       ? ((v10 & 0x1000) == 0
        ? (ComponentOfTypeHK = (UFG::InventoryItemComponent *)UFG::SimObject::GetComponentOfType(
                                                                ParentObject,
                                                                UFG::InventoryItemComponent::_TypeUID))
        : (ComponentOfTypeHK = (UFG::InventoryItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                ParentObject,
                                                                UFG::InventoryItemComponent::_TypeUID)))
       : (ComponentOfTypeHK = (UFG::InventoryItemComponent *)ParentObject->m_Components.p[11].m_pComponent),
         ComponentOfTypeHK)) )
  {
    return UFG::InventoryItemComponent::GetOwnerSimObject(ComponentOfTypeHK) == 0i64;
  }
  else
  {
    return 0;
  }
}

// File Line: 13519
// RVA: 0x148BB30
__int64 dynamic_initializer_for__POIIsTimingOut::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIIsTimingOut", 0xFFFFFFFF);
  POIIsTimingOut::sClassNameUID = result;
  return result;
}

// File Line: 13522
// RVA: 0x286640
char __fastcall POIIsTimingOut::Match(POIIsTimingOut *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx

  m_pPointer = pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[43].m_pComponent;
  }
  else
  {
    if ( m_Flags < 0 )
      return 0;
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[12].m_pComponent;
    }
    else
    {
      if ( (m_Flags & 0x1000) != 0 )
        return 0;
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InterestPointUserComponent::_TypeUID);
    }
  }
  if ( m_pComponent )
  {
    if ( m_pComponent[8].m_TypeUID != 3 )
    {
      mNext = m_pComponent[8].m_SafePointerList.mNode.mNext;
      if ( mNext )
      {
        if ( BYTE5(mNext[26].mNext) )
          return 1;
      }
    }
  }
  return 0;
}

// File Line: 13547
// RVA: 0x148BCD0
__int64 dynamic_initializer_for__PlayerHeatLevelCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerHeatLevelCondition", 0xFFFFFFFF);
  PlayerHeatLevelCondition::sClassNameUID = result;
  return result;
}

// File Line: 13553
// RVA: 0x278090
void __fastcall PlayerHeatLevelCondition::PlayerHeatLevelCondition(PlayerHeatLevelCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerHeatLevelCondition::`vftable;
  *(_WORD *)&this->mHeatLevel.mValue = 0;
}

// File Line: 13567
// RVA: 0x288D30
bool __fastcall PlayerHeatLevelCondition::Match(PlayerHeatLevelCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::CopSystem *v6; // rax
  int v7; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
    else
      m_pComponent = (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v6 = UFG::CopSystem::Instance();
  v7 = ((__int64 (__fastcall *)(UFG::CopSystem *))v6->vfptr[89].__vecDelDtor)(v6);
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           (unsigned __int8)this->mHeatLevel.mValue,
           v7);
}

// File Line: 13593
// RVA: 0x148BCF0
__int64 dynamic_initializer_for__PlayerHeatLevelTimerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerHeatLevelTimerCondition", 0xFFFFFFFF);
  PlayerHeatLevelTimerCondition::sClassNameUID = result;
  return result;
}

// File Line: 13599
// RVA: 0x2780D0
void __fastcall PlayerHeatLevelTimerCondition::PlayerHeatLevelTimerCondition(PlayerHeatLevelTimerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerHeatLevelTimerCondition::`vftable;
  this->mTimer = 0.0;
  this->mInEqualityOperator.mValue = 3;
}

// File Line: 13603
// RVA: 0x288DE0
char __fastcall PlayerHeatLevelTimerCondition::Match(PlayerHeatLevelTimerCondition *this, ActionContext *context)
{
  UFG::InEqualityOperator mValue; // ebx
  UFG::CopSystem *v4; // rax
  float CurrentHeatLevelElapsedTime; // xmm0_4

  mValue = (unsigned __int8)this->mInEqualityOperator.mValue;
  v4 = UFG::CopSystem::Instance();
  CurrentHeatLevelElapsedTime = UFG::CopSystem::GetCurrentHeatLevelElapsedTime(v4);
  return CompareFloat(mValue, this->mTimer, CurrentHeatLevelElapsedTime);
}

// File Line: 13622
// RVA: 0x148AEB0
__int64 dynamic_initializer_for__HasAIAttackerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasAIAttackerCondition", 0xFFFFFFFF);
  HasAIAttackerCondition::sClassNameUID = result;
  return result;
}

// File Line: 13627
// RVA: 0x276FD0
void __fastcall HasAIAttackerCondition::HasAIAttackerCondition(HasAIAttackerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HasAIAttackerCondition::`vftable;
  this->mDistance = 10.0;
}

// File Line: 13632
// RVA: 0x281E90
bool __fastcall HasAIAttackerCondition::Match(HasAIAttackerCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FormationManagerComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
         && m_Flags >= 0
         && (m_Flags & 0x2000) == 0
         && (m_Flags & 0x1000) == 0
          ? (ComponentOfType = (UFG::FormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::FormationManagerComponent::_TypeUID))
          : (ComponentOfType = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   m_pPointer,
                                                                   UFG::FormationManagerComponent::_TypeUID)),
            ComponentOfType)
        && (int)UFG::FormationManagerComponent::NumAttackersCloserThan(ComponentOfType, this->mDistance, 1) > 0;
  return result;
}

// File Line: 13657
// RVA: 0x148B9F0
__int64 dynamic_initializer_for__NumAIAttackersCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NumAIAttackersCondition", 0xFFFFFFFF);
  NumAIAttackersCondition::sClassNameUID = result;
  return result;
}

// File Line: 13665
// RVA: 0x277C70
void __fastcall NumAIAttackersCondition::NumAIAttackersCondition(NumAIAttackersCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&NumAIAttackersCondition::`vftable;
  this->m_InEqualityOperator.mValue = 1;
  this->mDistance = 10.0;
  this->m_NumAttackers = 1;
}

// File Line: 13672
// RVA: 0x285E30
bool __fastcall NumAIAttackersCondition::Match(NumAIAttackersCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FormationManagerComponent *ComponentOfTypeHK; // rax
  int v6; // eax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::FormationManagerComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::FormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::FormationManagerComponent::_TypeUID);
  if ( !ComponentOfTypeHK )
    return 0;
  v6 = UFG::FormationManagerComponent::NumAttackersCloserThan(ComponentOfTypeHK, this->mDistance, this->m_NumAttackers);
  return CompareInt((UFG::InEqualityOperator)this->m_InEqualityOperator.mValue, this->m_NumAttackers, v6);
}

// File Line: 13712
// RVA: 0x1491A80
__int64 dynamic_initializer_for__combatTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&combatTypeEnum, gCombatTypeStringList, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__combatTypeEnum__);
}

// File Line: 13714
// RVA: 0x148BD10
__int64 dynamic_initializer_for__PlayerIsInCombatCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsInCombatCondition", 0xFFFFFFFF);
  PlayerIsInCombatCondition::sClassNameUID = result;
  return result;
}

// File Line: 13720
// RVA: 0x278110
void __fastcall PlayerIsInCombatCondition::PlayerIsInCombatCondition(PlayerIsInCombatCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInCombatCondition::`vftable;
  this->m_CombatType.mValue = 0;
}

// File Line: 13725
// RVA: 0x288E20
bool __fastcall PlayerIsInCombatCondition::Match(PlayerIsInCombatCondition *this, ActionContext *context)
{
  int mValue; // eax

  mValue = this->m_CombatType.mValue;
  if ( !mValue )
    return UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(
             UFG::LocalPlayerIsInCombatManager::s_pInstance,
             eCHARACTER_TYPE_INVALID);
  if ( mValue == 1 )
    return UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(
             UFG::LocalPlayerIsInCombatManager::s_pInstance,
             eCHARACTER_TYPE_INVALID);
  return 0;
}

// File Line: 13757
// RVA: 0x148BD30
__int64 dynamic_initializer_for__PlayerIsInCombatConditionTU::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsInCombatConditionTU", 0xFFFFFFFF);
  PlayerIsInCombatConditionTU::sClassNameUID = result;
  return result;
}

// File Line: 13765
// RVA: 0x278150
void __fastcall PlayerIsInCombatConditionTU::PlayerIsInCombatConditionTU(PlayerIsInCombatConditionTU *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInCombatConditionTU::`vftable;
  this->m_CombatType.mValue = 0;
  this->m_WithCharacterType.mValue = 0;
}

// File Line: 13770
// RVA: 0x288E50
bool __fastcall PlayerIsInCombatConditionTU::Match(PlayerIsInCombatConditionTU *this, ActionContext *context)
{
  int mValue; // eax

  mValue = this->m_CombatType.mValue;
  if ( !mValue )
    return UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(
             UFG::LocalPlayerIsInCombatManager::s_pInstance,
             (UFG::eCharacterTypeEnum)(unsigned __int8)this->m_WithCharacterType.mValue);
  if ( mValue == 1 )
    return UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(
             UFG::LocalPlayerIsInCombatManager::s_pInstance,
             (UFG::eCharacterTypeEnum)(unsigned __int8)this->m_WithCharacterType.mValue);
  return 0;
}

// File Line: 13803
// RVA: 0x148B850
__int64 dynamic_initializer_for__IsTiredCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsTiredCondition", 0xFFFFFFFF);
  IsTiredCondition::sClassNameUID = result;
  return result;
}

// File Line: 13806
// RVA: 0x277970
void __fastcall IsTiredCondition::IsTiredCondition(IsTiredCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsTiredCondition::`vftable;
}

// File Line: 13811
// RVA: 0x285260
bool __fastcall IsTiredCondition::Match(IsTiredCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             m_pPointer,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                             m_pPointer,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return ComponentOfTypeHK->mIsTired;
  }
  else
  {
    return 0;
  }
}

// File Line: 13835
// RVA: 0x148BD50
__int64 dynamic_initializer_for__PlayerIsInCombatWithNumEnemiesCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsInCombatWithNumEnemiesCondition", 0xFFFFFFFF);
  PlayerIsInCombatWithNumEnemiesCondition::sClassNameUID = result;
  return result;
}

// File Line: 13845
// RVA: 0x278190
void __fastcall PlayerIsInCombatWithNumEnemiesCondition::PlayerIsInCombatWithNumEnemiesCondition(
        PlayerIsInCombatWithNumEnemiesCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInCombatWithNumEnemiesCondition::`vftable;
  this->mCombatType.mValue = 0;
  this->mInEqualityOperator.mValue = 3;
  this->mCount = 0;
}

// File Line: 13849
// RVA: 0x288E80
bool __fastcall PlayerIsInCombatWithNumEnemiesCondition::Match(
        PlayerIsInCombatWithNumEnemiesCondition *this,
        ActionContext *context)
{
  int mValue; // eax
  UFG::LocalPlayerIsInCombatManager *v3; // rdi
  UFG::InEqualityOperator v5; // ebx
  int NumAttackersAny; // eax

  mValue = this->mCombatType.mValue;
  v3 = UFG::LocalPlayerIsInCombatManager::s_pInstance;
  if ( mValue )
  {
    if ( mValue != 1
      || !UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(
            UFG::LocalPlayerIsInCombatManager::s_pInstance,
            eCHARACTER_TYPE_INVALID) )
    {
      return 0;
    }
    v5 = (unsigned __int8)this->mInEqualityOperator.mValue;
    NumAttackersAny = UFG::LocalPlayerIsInCombatManager::GetNumAttackersAny(v3, 0);
  }
  else
  {
    if ( !UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(
            UFG::LocalPlayerIsInCombatManager::s_pInstance,
            eCHARACTER_TYPE_INVALID) )
      return 0;
    v5 = (unsigned __int8)this->mInEqualityOperator.mValue;
    NumAttackersAny = UFG::LocalPlayerIsInCombatManager::GetNumAttackersMelee(v3, 0);
  }
  return CompareInt(v5, this->mCount, NumAttackersAny);
}

// File Line: 13886
// RVA: 0x148B510
__int64 dynamic_initializer_for__IsMultiplayerActiveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsMultiplayerActiveCondition", 0xFFFFFFFF);
  IsMultiplayerActiveCondition::sClassNameUID = result;
  return result;
}

// File Line: 13909
// RVA: 0x148AA70
__int64 dynamic_initializer_for__CharacterStatIntCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CharacterStatIntCondition", 0xFFFFFFFF);
  CharacterStatIntCondition::sClassNameUID = result;
  return result;
}

// File Line: 13916
// RVA: 0x27FDF0
bool __fastcall CharacterStatIntCondition::Match(CharacterStatIntCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                 m_pPointer,
                                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                 m_pPointer,
                                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID)),
            ComponentOfTypeHK)
        && CompareInt(
             (UFG::InEqualityOperator)(unsigned __int8)this->m_eInEqualityOperator.mValue,
             this->m_Value,
             (int)ComponentOfTypeHK->m_CharacterStats[this->m_StatType].m_fStat);
  return result;
}

// File Line: 13940
// RVA: 0x148B650
__int64 dynamic_initializer_for__IsPlayingDialogueCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayingDialogueCondition", 0xFFFFFFFF);
  IsPlayingDialogueCondition::sClassNameUID = result;
  return result;
}

// File Line: 13943
// RVA: 0x284700
bool __fastcall IsPlayingDialogueCondition::Match(IsPlayingDialogueCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx

  m_pPointer = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::ActorAudioComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  return ComponentOfTypeHK->m_isSpeakingCnt > 0 && ComponentOfTypeHK->m_controller.m_pEvent;
}

// File Line: 13965
// RVA: 0x148AC30
__int64 dynamic_initializer_for__CoverIsInCoverZoneCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CoverIsInCoverZoneCondition", 0xFFFFFFFF);
  CoverIsInCoverZoneCondition::sClassNameUID = result;
  return result;
}

// File Line: 13968
// RVA: 0x276B80
void __fastcall CoverIsInCoverZoneCondition::CoverIsInCoverZoneCondition(CoverIsInCoverZoneCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CoverIsInCoverZoneCondition::`vftable;
}

// File Line: 13972
// RVA: 0x280C10
bool __fastcall CoverIsInCoverZoneCondition::Match(CoverIsInCoverZoneCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    if ( ComponentOfTypeHK && ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mNext )
      return 1;
  }
  return result;
}

// File Line: 13999
// RVA: 0x148AC50
__int64 dynamic_initializer_for__CoverPositionsEquivalentCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CoverPositionsEquivalentCondition", 0xFFFFFFFF);
  CoverPositionsEquivalentCondition::sClassNameUID = result;
  return result;
}

// File Line: 14007
// RVA: 0x276BB0
void __fastcall CoverPositionsEquivalentCondition::CoverPositionsEquivalentCondition(
        CoverPositionsEquivalentCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CoverPositionsEquivalentCondition::`vftable;
  *(_WORD *)&this->m_eCoverComponentObjectA.mValue = 769;
}

// File Line: 14012
// RVA: 0x280CA0
bool __fastcall CoverPositionsEquivalentCondition::Match(
        CoverPositionsEquivalentCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::AICoverComponent *v4; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::CoverObjectBase *CoverObjectFromEnum; // rdi
  UFG::CoverObjectBase *v8; // rbx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    v4 = (UFG::AICoverComponent *)ComponentOfTypeHK;
  }
  else
  {
    v4 = 0i64;
  }
  CoverObjectFromEnum = UFG::AICoverComponent::GetCoverObjectFromEnum(
                          v4,
                          (UFG::eCoverComponentObjectEnum)(unsigned __int8)this->m_eCoverComponentObjectA.mValue);
  v8 = UFG::AICoverComponent::GetCoverObjectFromEnum(
         v4,
         (UFG::eCoverComponentObjectEnum)(unsigned __int8)this->m_eCoverComponentObjectB.mValue);
  if ( !CoverObjectFromEnum || !CoverObjectFromEnum->vfptr->IsPosition(CoverObjectFromEnum) )
    CoverObjectFromEnum = 0i64;
  if ( !v8 || !v8->vfptr->IsPosition(v8) )
    v8 = 0i64;
  return CoverObjectFromEnum && v8 && CoverObjectFromEnum->vfptr->operator==(CoverObjectFromEnum, v8);
}

// File Line: 14047
// RVA: 0x148AC70
__int64 dynamic_initializer_for__CoverProbeForCoverZoneCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CoverProbeForCoverZoneCondition", 0xFFFFFFFF);
  CoverProbeForCoverZoneCondition::sClassNameUID = result;
  return result;
}

// File Line: 14076
// RVA: 0x276BF0
void __fastcall CoverProbeForCoverZoneCondition::CoverProbeForCoverZoneCondition(CoverProbeForCoverZoneCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CoverProbeForCoverZoneCondition::`vftable;
  this->m_MaxProbeDistance = 3.0;
  this->m_BufferRegionSize = 0.30000001;
  this->m_UseOffset = 0;
  *(_QWORD *)&this->m_OffsetX = 0i64;
  *(_DWORD *)&this->m_LatchBestCover = 16843009;
  *(_WORD *)&this->m_Line = 257;
  this->m_Low = 1;
}

// File Line: 14081
// RVA: 0x280DB0
char __fastcall CoverProbeForCoverZoneCondition::Match(CoverProbeForCoverZoneCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::PlayerCoverComponent *v6; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float m_OffsetX; // xmm1_4
  float m_OffsetY; // xmm0_4
  UFG::SimObject *v12; // rax
  UFG::CoverPosition *m_pCurrentCoverPosition; // r14
  UFG::qVector3 *v14; // rax
  int x_low; // xmm12_4
  int y_low; // xmm13_4
  int z_low; // xmm14_4
  __int64 v18; // r8
  __int64 v19; // r9
  float v20; // xmm9_4
  float v21; // xmm10_4
  float v22; // xmm11_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm10_4
  float v26; // xmm11_4
  float v27; // xmm9_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm6_4
  float y; // xmm8_4
  float z; // xmm15_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm7_4
  float x; // xmm6_4
  __int128 v39; // xmm1
  __int128 v40; // xmm0
  __int128 v41; // xmm1
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  __int64 bLatch; // [rsp+20h] [rbp-E0h]
  int v44[4]; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qVector3 v45; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector4 v46; // [rsp+80h] [rbp-80h]
  UFG::qVector4 v47; // [rsp+90h] [rbp-70h]
  __int128 v48; // [rsp+A0h] [rbp-60h]
  __int128 v49; // [rsp+B0h] [rbp-50h]
  __int128 v50; // [rsp+C0h] [rbp-40h]

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    v6 = (UFG::PlayerCoverComponent *)ComponentOfTypeHK;
  }
  else
  {
    v6 = 0i64;
  }
  m_OffsetX = this->m_OffsetX;
  m_OffsetY = this->m_OffsetY;
  v46.z = 0.0;
  v46.w = 1.0;
  v46.x = m_OffsetY;
  LODWORD(v46.y) = LODWORD(m_OffsetX) ^ _xmm[0];
  if ( v6->m_TypeUID == UFG::PlayerCoverComponent::_TypeUID )
  {
    LOBYTE(bLatch) = this->m_LatchBestCover != 0;
    return UFG::PlayerCoverComponent::ProbeForPlayerCover(
             v6,
             0.0,
             this->m_MaxProbeDistance,
             this->m_BufferRegionSize,
             bLatch);
  }
  else
  {
    if ( !this->m_UseOffset )
      return 0;
    v12 = pContext->mSimObject.m_pPointer;
    m_pCurrentCoverPosition = v6->m_pCurrentCoverPosition;
    if ( v12 )
      m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
    if ( m_pCurrentCoverPosition
      && (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&m_pCurrentCoverPosition->vfptr->__vecDelDtor + 2))(m_pCurrentCoverPosition) )
    {
      v14 = m_pCurrentCoverPosition->vfptr->GetWallNormal(m_pCurrentCoverPosition, &v45);
      x_low = LODWORD(v14->x) ^ _xmm[0];
      y_low = LODWORD(v14->y) ^ _xmm[0];
      z_low = LODWORD(v14->z) ^ _xmm[0];
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v20 = (float)(*(float *)&z_low * UFG::qVector3::msDirUp.y) - (float)(*(float *)&y_low * UFG::qVector3::msDirUp.z);
      v21 = (float)(*(float *)&x_low * UFG::qVector3::msDirUp.z) - (float)(*(float *)&z_low * UFG::qVector3::msDirUp.x);
      v22 = (float)(*(float *)&y_low * UFG::qVector3::msDirUp.x) - (float)(*(float *)&x_low * UFG::qVector3::msDirUp.y);
      v23 = (float)((float)(v21 * v21) + (float)(v20 * v20)) + (float)(v22 * v22);
      v24 = v23 == 0.0 ? 0.0 : 1.0 / fsqrt(v23);
      v25 = v21 * v24;
      v26 = v22 * v24;
      v27 = v20 * v24;
      v28 = (float)(v26 * *(float *)&y_low) - (float)(v25 * *(float *)&z_low);
      v29 = (float)(v27 * *(float *)&z_low) - (float)(v26 * *(float *)&x_low);
      v30 = (float)(v25 * *(float *)&x_low) - (float)(v27 * *(float *)&y_low);
      v31 = (float)((float)(v29 * v29) + (float)(v28 * v28)) + (float)(v30 * v30);
      v32 = v31 == 0.0 ? 0.0 : 1.0 / fsqrt(v31);
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      v35 = v28 * v32;
      v36 = v29 * v32;
      v37 = v30 * v32;
      x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v39 = (__int128)m_pTransformNodeComponent->mWorldTransform.v1;
      v47 = m_pTransformNodeComponent->mWorldTransform.v0;
      v40 = (__int128)m_pTransformNodeComponent->mWorldTransform.v2;
      z_low = SLODWORD(v47.z);
      y_low = SLODWORD(v47.y);
      x_low = SLODWORD(v47.x);
      v48 = v39;
      v41 = (__int128)m_pTransformNodeComponent->mWorldTransform.v3;
      v26 = *((float *)&v48 + 2);
      v25 = *((float *)&v48 + 1);
      v27 = *(float *)&v48;
      v49 = v40;
      v37 = *((float *)&v40 + 2);
      v36 = *((float *)&v40 + 1);
      v35 = *(float *)&v40;
      v50 = v41;
      z = *((float *)&v41 + 2);
      y = *((float *)&v41 + 1);
      x = *(float *)&v41;
    }
    vfptr = v6->vfptr;
    LOBYTE(v19) = this->m_StoreProbeCoverObject != 0;
    LOBYTE(v18) = this->m_LatchBestCover != 0;
    *(float *)v44 = (float)((float)((float)(v27 * v46.y) + (float)(*(float *)&x_low * v46.x)) + (float)(v35 * v46.z))
                  + (float)(x * v46.w);
    *(float *)&v44[1] = (float)((float)((float)(v25 * v46.y) + (float)(*(float *)&y_low * v46.x)) + (float)(v36 * v46.z))
                      + (float)(y * v46.w);
    *(float *)&v44[2] = (float)((float)((float)(v26 * v46.y) + (float)(*(float *)&z_low * v46.x)) + (float)(v37 * v46.z))
                      + (float)(z * v46.w);
    return ((unsigned __int8 (__fastcall *)(UFG::PlayerCoverComponent *, int *, __int64, __int64))vfptr[17].__vecDelDtor)(
             v6,
             v44,
             v18,
             v19) != 0;
  }
}

// File Line: 14153
// RVA: 0x148ABF0
__int64 dynamic_initializer_for__CoverDirectionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CoverDirectionCondition", 0xFFFFFFFF);
  CoverDirectionCondition::sClassNameUID = result;
  return result;
}

// File Line: 14171
// RVA: 0x276AF0
void __fastcall CoverDirectionCondition::CoverDirectionCondition(CoverDirectionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CoverDirectionCondition::`vftable;
  *(_DWORD *)&this->m_eCoverComponentObject.mValue = 65537;
  this->m_CheckFacingDirection = 0;
  this->m_Direction = 0.0;
  this->m_AngleRange = 1.5707964;
}

// File Line: 14175
// RVA: 0x280760
char __fastcall CoverDirectionCondition::Match(CoverDirectionCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::AICoverComponent *v6; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::CoverObjectBase *CoverObjectFromEnum; // rax
  UFG::CoverPosition *v10; // r14
  bool IsAnyLocalPlayer; // bl
  char result; // al
  UFG::SimObjectGame *v13; // rcx
  UFG::AimingBaseComponent *m_pComponent; // rax
  __int16 v15; // dx
  __m128 x_low; // xmm1
  float v17; // xmm4_4
  UFG::SimObjectCVBase *v18; // rcx
  UFG::AICharacterControllerBaseComponent *ComponentOfType; // rax
  __int16 v20; // dx
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  _DWORD *p_mFOVOffset; // rax
  int v23; // xmm1_4
  int v24; // xmm0_4
  UFG::SimObject *v25; // rax
  UFG::qVector3 vAimDirection; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    v6 = (UFG::AICoverComponent *)ComponentOfTypeHK;
  }
  else
  {
    v6 = 0i64;
  }
  CoverObjectFromEnum = UFG::AICoverComponent::GetCoverObjectFromEnum(
                          v6,
                          (UFG::eCoverComponentObjectEnum)(unsigned __int8)this->m_eCoverComponentObject.mValue);
  v10 = (UFG::CoverPosition *)CoverObjectFromEnum;
  if ( !CoverObjectFromEnum || !CoverObjectFromEnum->vfptr->IsPosition(CoverObjectFromEnum) )
    return 0;
  IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(v6->m_pSimObject);
  result = 1;
  if ( !this->m_CheckAimIntention && (IsAnyLocalPlayer || !this->m_CheckCameraDirection) )
    goto LABEL_56;
  v13 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v13 )
  {
    v15 = v13->m_Flags;
    if ( (v15 & 0x4000) != 0 )
      m_pComponent = (UFG::AimingBaseComponent *)v13->m_Components.p[47].m_pComponent;
    else
      m_pComponent = (UFG::AimingBaseComponent *)(v15 < 0 || (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v13,
                                                    UFG::AimingBaseComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    v13,
                                                    UFG::AimingBaseComponent::_TypeUID));
  }
  else
  {
    m_pComponent = 0i64;
  }
  UFG::AimingBaseComponent::GetAimDirection(m_pComponent, &vAimDirection, 0i64);
  x_low = (__m128)LODWORD(vAimDirection.x);
  x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(vAimDirection.y * vAimDirection.y);
  v17 = _mm_sqrt_ps(x_low).m128_f32[0];
  if ( v17 <= 0.001 )
  {
    vAimDirection = UFG::qVector3::msAxisX;
  }
  else
  {
    vAimDirection.z = (float)(1.0 / v17) * 0.0;
    vAimDirection.x = vAimDirection.x * (float)(1.0 / v17);
    vAimDirection.y = vAimDirection.y * (float)(1.0 / v17);
  }
  result = CoverDirectionCondition::CheckDirection(this, v10, &vAimDirection);
  if ( result )
  {
LABEL_56:
    if ( this->m_CheckMotionIntention )
    {
      v18 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
      if ( v18 )
      {
        v20 = v18->m_Flags;
        if ( (v20 & 0x4000) != 0 || v20 < 0 )
        {
          ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v18);
        }
        else if ( (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0 )
        {
          ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v18,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                         v18,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
      }
      else
      {
        ComponentOfType = 0i64;
      }
      result = CoverDirectionCondition::CheckDirection(
                 this,
                 v10,
                 &ComponentOfType->m_Intention.mMotionIntentionDirection);
    }
    if ( result )
    {
      if ( this->m_CheckCameraDirection && IsAnyLocalPlayer )
      {
        mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
        if ( mCurrentCamera )
          p_mFOVOffset = (_DWORD *)&mCurrentCamera->mCamera.mFOVOffset;
        else
          p_mFOVOffset = 0i64;
        v23 = p_mFOVOffset[42] ^ _xmm[0];
        LODWORD(vAimDirection.x) = p_mFOVOffset[40] ^ _xmm[0];
        v24 = p_mFOVOffset[41];
        LODWORD(vAimDirection.z) = v23;
        LODWORD(vAimDirection.y) = v24 ^ _xmm[0];
        result = CoverDirectionCondition::CheckDirection(this, v10, &vAimDirection);
      }
      if ( result && this->m_CheckFacingDirection )
      {
        v25 = pContext->mSimObject.m_pPointer;
        if ( v25 )
          m_pTransformNodeComponent = v25->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        return CoverDirectionCondition::CheckDirection(
                 this,
                 v10,
                 (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform);
      }
    }
  }
  return result;
}

// File Line: 14253
// RVA: 0x27AD70
char __fastcall CoverDirectionCondition::CheckDirection(
        CoverDirectionCondition *this,
        UFG::CoverPosition *pPosition,
        UFG::qVector3 *vDirection)
{
  UFG::ParkourHandle *m_pPointer; // rcx
  UFG::CoverCorner *v8; // rax
  float x; // xmm0_4
  float y; // xmm1_4
  UFG::CoverCorner *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  UFG::qVector3 out; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = pPosition->m_pParkourHandle.m_pPointer;
  if ( m_pPointer )
  {
    UFG::ParkourHandle::GetNormal(m_pPointer, &out);
    if ( !CoverDirectionCondition::CheckDirection(this, &out, vDirection) )
      return 0;
  }
  v8 = UFG::CoverCornerHandle::Get(&pPosition->m_LeftCorner);
  if ( v8 )
  {
    x = v8->m_vWallNormal.x;
    y = v8->m_vWallNormal.y;
    out.z = 0.0;
    out.x = x;
    out.y = y;
    if ( !CoverDirectionCondition::CheckDirection(this, &out, vDirection) )
      return 0;
  }
  v11 = UFG::CoverCornerHandle::Get(&pPosition->m_RightCorner);
  if ( v11
    && (v12 = v11->m_vWallNormal.x,
        v13 = v11->m_vWallNormal.y,
        out.z = 0.0,
        out.x = v12,
        out.y = v13,
        !CoverDirectionCondition::CheckDirection(this, &out, vDirection)) )
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

// File Line: 14289
// RVA: 0x27AC90
bool __fastcall CoverDirectionCondition::CheckDirection(
        CoverDirectionCondition *this,
        UFG::qVector3 *vNormal,
        UFG::qVector3 *vDirection)
{
  float x; // xmm1_4
  int v6; // xmm1_4
  float y; // xmm0_4
  float m_Direction; // xmm2_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  UFG::qVector3 v12; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 v13; // [rsp+30h] [rbp-18h] BYREF

  v12.y = UFG::qVector3::msZero.y;
  x = vNormal->x;
  v12.x = UFG::qVector3::msZero.x;
  LODWORD(v13.x) = LODWORD(x) ^ _xmm[0];
  v6 = LODWORD(vNormal->z) ^ _xmm[0];
  v12.z = UFG::qVector3::msZero.z;
  y = vNormal->y;
  LODWORD(v13.z) = v6;
  m_Direction = this->m_Direction;
  LODWORD(v13.y) = LODWORD(y) ^ _xmm[0];
  UFG::qRotateVectorZ(&v12, &v13, m_Direction);
  v9 = (float)((float)(v12.y * vDirection->y) + (float)(v12.x * vDirection->x)) + (float)(v12.z * vDirection->z);
  if ( v9 <= -1.0 )
  {
    v9 = FLOAT_N1_0;
  }
  else
  {
    v10 = *(float *)&FLOAT_1_0;
    if ( v9 >= 1.0 )
      return acosf(v10) <= this->m_AngleRange;
  }
  v10 = v9;
  return acosf(v10) <= this->m_AngleRange;
}

// File Line: 14325
// RVA: 0x148AC10
__int64 dynamic_initializer_for__CoverHeightCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CoverHeightCondition", 0xFFFFFFFF);
  CoverHeightCondition::sClassNameUID = result;
  return result;
}

// File Line: 14335
// RVA: 0x276B40
void __fastcall CoverHeightCondition::CoverHeightCondition(CoverHeightCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CoverHeightCondition::`vftable;
  *(_WORD *)&this->m_eCoverComponentObject.mValue = 257;
  this->m_Low = 0;
}

// File Line: 14339
// RVA: 0x280AB0
UFG::CoverObjectBase *__fastcall CoverHeightCondition::Match(CoverHeightCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  unsigned __int8 v4; // di
  UFG::AICoverComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::CoverObjectBase *result; // rax
  UFG::CoverObjectBase *v8; // rbx
  float v9; // xmm0_4
  bool v10; // bp
  double v11; // xmm0_8
  float v12; // xmm8_4
  float v13; // xmm0_4
  bool v14; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::AICoverComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  result = UFG::AICoverComponent::GetCoverObjectFromEnum(
             ComponentOfTypeHK,
             (UFG::eCoverComponentObjectEnum)(unsigned __int8)this->m_eCoverComponentObject.mValue);
  v8 = result;
  if ( result )
  {
    v9 = result->vfptr->GetHeight(result);
    v10 = v9 > 0.5 && v9 < 1.6;
    v11 = ((double (__fastcall *)(UFG::CoverObjectBase *))v8->vfptr->GetHeight)(v8);
    v12 = *(float *)&v11;
    v13 = v8->vfptr->GetHeight(v8);
    v14 = (v13 <= 0.5 || v13 >= 1.6) && v12 > 1.5;
    if ( v10 && this->m_Low || v14 && this->m_High )
      return (UFG::CoverObjectBase *)1;
    return (UFG::CoverObjectBase *)v4;
  }
  return result;
}

// File Line: 14375
// RVA: 0x148AC90
__int64 dynamic_initializer_for__CoverTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CoverTypeCondition", 0xFFFFFFFF);
  CoverTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 14387
// RVA: 0x276C50
void __fastcall CoverTypeCondition::CoverTypeCondition(CoverTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CoverTypeCondition::`vftable;
  *(_DWORD *)&this->m_eCoverComponentObject.mValue = 16777217;
}

// File Line: 14391
// RVA: 0x2812B0
bool __fastcall CoverTypeCondition::Match(CoverTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::AICoverComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::CoverObjectBase *CoverObjectFromEnum; // rax
  UFG::CoverObjectBase *v7; // rbx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::AICoverComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  CoverObjectFromEnum = UFG::AICoverComponent::GetCoverObjectFromEnum(
                          ComponentOfTypeHK,
                          (UFG::eCoverComponentObjectEnum)(unsigned __int8)this->m_eCoverComponentObject.mValue);
  v7 = CoverObjectFromEnum;
  return CoverObjectFromEnum
      && CoverObjectFromEnum->vfptr->IsPosition(CoverObjectFromEnum)
      && (this->m_LeftCorner && UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v7[2].m_iRefCount)
       || this->m_RightCorner && UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v7[4].m_iRefCount)
       || this->m_Line && v7->vfptr->IsParkour(v7));
}

// File Line: 14438
// RVA: 0x148ABD0
__int64 dynamic_initializer_for__CoverCanTraverseInDirectionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CoverCanTraverseInDirectionCondition", 0xFFFFFFFF);
  CoverCanTraverseInDirectionCondition::sClassNameUID = result;
  return result;
}

// File Line: 14446
// RVA: 0x276AB0
void __fastcall CoverCanTraverseInDirectionCondition::CoverCanTraverseInDirectionCondition(
        CoverCanTraverseInDirectionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CoverCanTraverseInDirectionCondition::`vftable;
  *(_WORD *)&this->m_bLeft = 0;
}

// File Line: 14450
// RVA: 0x280680
bool __fastcall CoverCanTraverseInDirectionCondition::Match(
        CoverCanTraverseInDirectionCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  float *mPrev; // rbx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  mPrev = (float *)ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev;
  return mPrev
      && (*(unsigned __int8 (__fastcall **)(float *))(*(_QWORD *)mPrev + 16i64))(mPrev)
      && (this->m_bLeft && mPrev[52] > 0.1 || this->m_bRight && mPrev[53] > 0.1);
}

// File Line: 14491
// RVA: 0x148CEB0
__int64 dynamic_initializer_for__WaterDepth::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WaterDepth", 0xFFFFFFFF);
  WaterDepth::sClassNameUID = result;
  return result;
}

// File Line: 14499
// RVA: 0x279730
void __fastcall WaterDepth::WaterDepth(WaterDepth *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&WaterDepth::`vftable;
  this->mWaterDepth = 0.0;
  this->mInEqualityOperator.mValue = 1;
}

// File Line: 14504
// RVA: 0x293710
char __fastcall WaterDepth::Match(WaterDepth *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  float v4; // xmm7_4
  __int16 m_Flags; // r8
  UFG::CharacterPhysicsComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v9; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float z; // xmm6_4

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = FLOAT_N1_0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = (UFG::CharacterPhysicsComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      if ( UFG::CharacterPhysicsComponent::IsInWater(m_pComponent) )
      {
        v9 = context->mSimObject.m_pPointer;
        m_pTransformNodeComponent = v9->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
          z = m_pTransformNodeComponent->mWorldTransform.v3.z;
          v4 = UFG::CharacterPhysicsComponent::GetWaterElevation(m_pComponent) - z;
        }
      }
    }
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mWaterDepth, v4);
}

// File Line: 14537
// RVA: 0x148C8B0
__int64 dynamic_initializer_for__TargetedByTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetedByTypeCondition", 0xFFFFFFFF);
  TargetedByTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 14543
// RVA: 0x290910
bool __fastcall TargetedByTypeCondition::Match(TargetedByTypeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax
  UFG::eTargetTypeEnum mValue; // edx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           m_pPointer,
                                                           UFG::TargetingSystemBaseComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           m_pPointer,
                                                           UFG::TargetingSystemBaseComponent::_TypeUID));
  }
  else
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  mValue = (unsigned __int8)this->m_eTargetType.mValue;
  if ( this->m_bIsLocked )
    return UFG::TargetingSystemBaseComponent::IsTargetedByTypeAndLocked(m_pComponent, mValue);
  else
    return UFG::TargetingSystemBaseComponent::IsTargetedByType(m_pComponent, mValue);
}

// File Line: 14575
// RVA: 0x148B810
__int64 dynamic_initializer_for__IsTargetsTargetCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsTargetsTargetCondition", 0xFFFFFFFF);
  IsTargetsTargetCondition::sClassNameUID = result;
  return result;
}

// File Line: 14581
// RVA: 0x284E80
bool __fastcall IsTargetsTargetCondition::Match(IsTargetsTargetCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // r8
  __int16 v9; // cx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v12; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( m_pComponent
    && (v8 = *(UFG::SimObjectGame **)(56i64
                                    * *(unsigned __int8 *)((unsigned __int8)this->m_eTargetType.mValue
                                                         + *(_QWORD *)&m_pComponent[1].m_Flags
                                                         + 8i64)
                                    + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                    + 40)) != 0i64
    && ((v9 = v8->m_Flags, (v9 & 0x4000) == 0)
      ? (v9 >= 0
       ? ((v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID)),
          v10 = ComponentOfTypeHK)
       : (v10 = v8->m_Components.p[20].m_pComponent))
      : (v10 = v8->m_Components.p[20].m_pComponent),
        v10
     && (v12 = *(UFG::SimObject **)(56i64
                                  * *(unsigned __int8 *)((unsigned __int8)this->m_eTargetsTargetType.mValue
                                                       + *(_QWORD *)&v10[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v10[1].m_TypeUID
                                  + 40)) != 0i64) )
  {
    return v12 == pContext->mSimObject.m_pPointer;
  }
  else
  {
    return 0;
  }
}

// File Line: 14632
// RVA: 0x27DF90
bool __fastcall InventoryCheckPropertyMatch(UFG::SimObjectGame *pSimObject, UFG::eItemPropertiesEnum eProperty)
{
  signed __int16 m_Flags; // r8
  UFG::SimComponent *ComponentOfType; // rax
  UFG::eInventoryItemEnum m_pSimObject; // ecx
  bool result; // al

  result = pSimObject
        && (m_Flags = pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
        && m_Flags >= 0
        && ((m_Flags & 0x2000) == 0
          ? ((m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(pSimObject, UFG::InventoryItemComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  pSimObject,
                                  UFG::InventoryItemComponent::_TypeUID)))
          : (ComponentOfType = pSimObject->m_Components.p[11].m_pComponent),
            ComponentOfType
         && (m_pSimObject = (UFG::eInventoryItemEnum)ComponentOfType[1].m_pSimObject) != eINVENTORY_ITEM_INVALID)
        && UFG::ItemProfiles::HasProperty(m_pSimObject, eProperty);
  return result;
}

// File Line: 14667
// RVA: 0x148B270
__int64 dynamic_initializer_for__InventoryCheckPropertyCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InventoryCheckPropertyCondition", 0xFFFFFFFF);
  InventoryCheckPropertyCondition::sClassNameUID = result;
  return result;
}

// File Line: 14673
// RVA: 0x283720
bool __fastcall InventoryCheckPropertyCondition::Match(InventoryCheckPropertyCondition *this, ActionContext *pContext)
{
  return InventoryCheckPropertyMatch(
           (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer,
           (UFG::eItemPropertiesEnum)(unsigned __int8)this->m_eProperty.mValue);
}

// File Line: 14688
// RVA: 0x148C2D0
__int64 dynamic_initializer_for__TargetInventoryCheckPropertyCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetInventoryCheckPropertyCondition", 0xFFFFFFFF);
  TargetInventoryCheckPropertyCondition::sClassNameUID = result;
  return result;
}

// File Line: 14695
// RVA: 0x28C430
bool __fastcall TargetInventoryCheckPropertyCondition::Match(
        TargetInventoryCheckPropertyCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent)
        && InventoryCheckPropertyMatch(
             *(UFG::SimObjectGame **)(56i64
                                    * *(unsigned __int8 *)((unsigned int)this->mTargetType
                                                         + *(_QWORD *)&m_pComponent[1].m_Flags
                                                         + 8i64)
                                    + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                    + 40),
             (UFG::eItemPropertiesEnum)(unsigned __int8)this->m_eProperty.mValue);
  return result;
}

// File Line: 14715
// RVA: 0x148C610
__int64 dynamic_initializer_for__TargetPurchaseItemFailCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetPurchaseItemFailCondition", 0xFFFFFFFF);
  TargetPurchaseItemFailCondition::sClassNameUID = result;
  return result;
}

// File Line: 14720
// RVA: 0x28EA30
bool __fastcall TargetPurchaseItemFailCondition::Match(TargetPurchaseItemFailCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *Target; // rax
  __int16 v8; // dx
  UFG::SimComponent *v9; // rcx
  UFG::SimComponent *v10; // rax
  __int64 v11; // rdx
  int Cost; // ebx
  UFG::GameStatTracker *v14; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  Target = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)this->mTargetType);
  if ( !Target )
    return 0;
  v8 = Target->m_Flags;
  if ( (v8 & 0x4000) != 0 )
  {
    v9 = Target->m_Components.p[39].m_pComponent;
  }
  else
  {
    v10 = v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::InventoryComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(Target, UFG::InventoryComponent::_TypeUID);
    v9 = v10;
  }
  if ( !v9 )
    return 0;
  v11 = *(int *)&v9[14].m_Flags;
  if ( !(_DWORD)v11 )
    return 0;
  if ( !LOBYTE(v9[14].m_pSimObject) && *((int *)&v9[1].m_NameUID + v11) <= 0 )
    return 1;
  Cost = UFG::ItemProfiles::GetCost((UFG::eInventoryItemEnum)v11);
  v14 = UFG::GameStatTracker::Instance();
  return (int)UFG::GameStatTracker::GetStat(v14, Money) < Cost;
}

// File Line: 14763
// RVA: 0x148BFB0
__int64 dynamic_initializer_for__SocialABKsLoadedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialABKsLoadedCondition", 0xFFFFFFFF);
  SocialABKsLoadedCondition::sClassNameUID = result;
  return result;
}

// File Line: 14765
// RVA: 0x289D40
char __fastcall SocialABKsLoadedCondition::Match(SocialABKsLoadedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceActionComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::FaceActionComponent::_TypeUID))
       : (ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::FaceActionComponent::_TypeUID)))
      : (ComponentOfType = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent),
        ComponentOfType) )
  {
    return UFG::FaceActionComponent::AreAnimsLoaded(ComponentOfType);
  }
  else
  {
    return 0;
  }
}

// File Line: 14786
// RVA: 0x148C1B0
__int64 dynamic_initializer_for__SocialSetEvaluatedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialSetEvaluatedCondition", 0xFFFFFFFF);
  SocialSetEvaluatedCondition::sClassNameUID = result;
  return result;
}

// File Line: 14791
// RVA: 0x28A7B0
char __fastcall SocialSetEvaluatedCondition::Match(SocialSetEvaluatedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceActionComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::FaceActionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::FaceActionComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::FaceActionComponent::SetFrameAITreeEvaluated(m_pComponent, this->m_Evaluated != 0);
  }
  return 1;
}

// File Line: 14813
// RVA: 0x148AA10
__int64 dynamic_initializer_for__CanWanderCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CanWanderCondition", 0xFFFFFFFF);
  CanWanderCondition::sClassNameUID = result;
  return result;
}

// File Line: 14816
// RVA: 0x27FCB0
bool __fastcall CanWanderCondition::Match(CanWanderCondition *this, ActionContext *context)
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
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
    if ( m_pComponent && BYTE5(m_pComponent[20].m_BoundComponentHandles.mNode.mPrev) )
      return 1;
  }
  return result;
}

// File Line: 14832
// RVA: 0x148C210
__int64 dynamic_initializer_for__StateFlagCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("StateFlagCondition", 0xFFFFFFFF);
  StateFlagCondition::sClassNameUID = result;
  return result;
}

// File Line: 14837
// RVA: 0x278890
void __fastcall StateFlagCondition::StateFlagCondition(StateFlagCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&StateFlagCondition::`vftable;
  this->m_FlagType.mValue = 0;
}

// File Line: 14841
// RVA: 0x28B6E0
bool __fastcall StateFlagCondition::Match(StateFlagCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) == 0
        ? ((m_Flags & 0x1000) == 0
         ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::SimObjectPropertiesComponent::_TypeUID))
         : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::SimObjectPropertiesComponent::_TypeUID)),
           m_pComponent = ComponentOfType)
        : (m_pComponent = m_pPointer->m_Components.p[4].m_pComponent))
       : (m_pComponent = m_pPointer->m_Components.p[3].m_pComponent))
      : (m_pComponent = m_pPointer->m_Components.p[3].m_pComponent),
        m_pComponent && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 1) )
  {
    return *((_BYTE *)&m_pComponent[2].m_BoundComponentHandles.mNode.mPrev + (int)this->m_FlagType.mValue + 1);
  }
  else
  {
    return 0;
  }
}

// File Line: 14864
// RVA: 0x148BF50
__int64 dynamic_initializer_for__SimObjectFlagCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SimObjectFlagCondition", 0xFFFFFFFF);
  SimObjectFlagCondition::sClassNameUID = result;
  return result;
}

// File Line: 14869
// RVA: 0x2784F0
void __fastcall SimObjectFlagCondition::SimObjectFlagCondition(SimObjectFlagCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SimObjectFlagCondition::`vftable;
  this->m_Flag.mValue = 0;
}

// File Line: 14873
// RVA: 0x2899E0
bool __fastcall SimObjectFlagCondition::Match(SimObjectFlagCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectPropertiesComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) == 0
            ? ((m_Flags & 0x1000) == 0
             ? (ComponentOfType = (UFG::SimObjectPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                         m_pPointer,
                                                                         UFG::SimObjectPropertiesComponent::_TypeUID))
             : (ComponentOfType = (UFG::SimObjectPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         m_pPointer,
                                                                         UFG::SimObjectPropertiesComponent::_TypeUID)))
            : (ComponentOfType = (UFG::SimObjectPropertiesComponent *)m_pPointer->m_Components.p[4].m_pComponent))
           : (ComponentOfType = (UFG::SimObjectPropertiesComponent *)m_pPointer->m_Components.p[3].m_pComponent))
          : (ComponentOfType = (UFG::SimObjectPropertiesComponent *)m_pPointer->m_Components.p[3].m_pComponent),
            ComponentOfType)
        && UFG::SimObjectPropertiesComponent::isFlagSet(ComponentOfType, (UFG::eSimObjectFlagEnum)this->m_Flag.mValue);
  return result;
}

// File Line: 14894
// RVA: 0x148B750
__int64 dynamic_initializer_for__IsRainingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsRainingCondition", 0xFFFFFFFF);
  IsRainingCondition::sClassNameUID = result;
  return result;
}

// File Line: 14897
// RVA: 0x284C20
UFG::TimeOfDayManager *__fastcall IsRainingCondition::Match(IsRainingCondition *this, ActionContext *pContext)
{
  UFG::TimeOfDayManager *result; // rax

  result = UFG::TimeOfDayManager::GetInstance();
  if ( result )
    return (UFG::TimeOfDayManager *)(result->m_WeatherState > 1.0);
  return result;
}

// File Line: 14918
// RVA: 0x148B4B0
__int64 dynamic_initializer_for__IsIndoorsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsIndoorsCondition", 0xFFFFFFFF);
  IsIndoorsCondition::sClassNameUID = result;
  return result;
}

// File Line: 14921
// RVA: 0x283F50
bool __fastcall IsIndoorsCondition::Match(IsIndoorsCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCharacter *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActorAudioComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::ActorAudioComponent::_TypeUID))
           : (ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::ActorAudioComponent::_TypeUID)))
          : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pPointer)),
            ComponentOfType)
        && ComponentOfType->m_interiorCount != 0;
  return result;
}

// File Line: 14948
// RVA: 0x148B490
__int64 dynamic_initializer_for__IsInInterior::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsInInterior", 0xFFFFFFFF);
  IsInInterior::sClassNameUID = result;
  return result;
}

// File Line: 15008
// RVA: 0x148BD70
__int64 dynamic_initializer_for__PlayerIsInSpecificInterior::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsInSpecificInterior", 0xFFFFFFFF);
  PlayerIsInSpecificInterior::sClassNameUID = result;
  return result;
}

// File Line: 15014
// RVA: 0x2781D0
void __fastcall PlayerIsInSpecificInterior::PlayerIsInSpecificInterior(PlayerIsInSpecificInterior *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInSpecificInterior::`vftable;
  this->mInterior.mValue = 0;
}

// File Line: 15018
// RVA: 0x288F20
bool __fastcall PlayerIsInSpecificInterior::Match(PlayerIsInSpecificInterior *this, ActionContext *context)
{
  return UFG::UIHKScreenHud::mInteriorManager
      && UFG::UIHKScreenHud::mInteriorManager->mActiveInterior == this->mInterior.mValue;
}

// File Line: 15046
// RVA: 0x148B370
__int64 dynamic_initializer_for__IsCriticalPriorityCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsCriticalPriorityCondition", 0xFFFFFFFF);
  IsCriticalPriorityCondition::sClassNameUID = result;
  return result;
}

// File Line: 15049
// RVA: 0x283BA0
bool __fastcall IsCriticalPriorityCondition::Match(IsCriticalPriorityCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  result = !m_pPointer
        || ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) == 0
            ? ((m_Flags & 0x1000) == 0
             ? (ComponentOfType = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                                      m_pPointer,
                                                                      UFG::StreamedResourceComponent::_TypeUID))
             : (ComponentOfType = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      m_pPointer,
                                                                      UFG::StreamedResourceComponent::_TypeUID)))
            : (ComponentOfType = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[7].m_pComponent))
           : (ComponentOfType = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent))
          : (ComponentOfType = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent),
            !ComponentOfType)
        || UFG::StreamedResourceComponent::GetSpawnPriority(ComponentOfType, 0i64)->mUID == qSymbol_Critical.mUID;
  return result;
}

// File Line: 15071
// RVA: 0x148B7B0
__int64 dynamic_initializer_for__IsSpawningCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsSpawningCondition", 0xFFFFFFFF);
  IsSpawningCondition::sClassNameUID = result;
  return result;
}

// File Line: 15074
// RVA: 0x284D20
bool __fastcall IsSpawningCondition::Match(IsSpawningCondition *this, ActionContext *context)
{
  return UFG::IsSpawning(context->mSimObject.m_pPointer);
}

// File Line: 15092
// RVA: 0x148B770
__int64 dynamic_initializer_for__IsSkippingIntoPOICondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsSkippingIntoPOICondition", 0xFFFFFFFF);
  IsSkippingIntoPOICondition::sClassNameUID = result;
  return result;
}

// File Line: 15095
// RVA: 0x284C50
bool __fastcall IsSkippingIntoPOICondition::Match(IsSkippingIntoPOICondition *this, ActionContext *context)
{
  return UFG::IsSkippingIntoPOI(context->mSimObject.m_pPointer);
}

// File Line: 15114
// RVA: 0x148B4F0
__int64 dynamic_initializer_for__IsLockboxContainingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsLockboxContainingCondition", 0xFFFFFFFF);
  IsLockboxContainingCondition::sClassNameUID = result;
  return result;
}

// File Line: 15120
// RVA: 0x277800
void __fastcall IsLockboxContainingCondition::IsLockboxContainingCondition(IsLockboxContainingCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsLockboxContainingCondition::`vftable;
  this->mInventoryItemType.mValue = 0;
}

// File Line: 15125
// RVA: 0x284070
bool __fastcall IsLockboxContainingCondition::Match(IsLockboxContainingCondition *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  bool v8; // r8
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  m_pPointer = pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  v4 = (UFG::qSymbol *)PropertyUtils::Get<UFG::qSymbol>(
                         m_pPointer->m_pSceneObj,
                         (UFG::qArray<unsigned long,0> *)&qSymbol_RewardsPropertySet);
  if ( !v4 )
    return 0;
  if ( v4->mUID == -1 )
    return 0;
  PropertySet = UFG::PropertySetManager::GetPropertySet(v4);
  if ( !PropertySet )
    return 0;
  v6 = PropertyUtils::Get<UFG::qSymbol>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_InventoryItemType,
         DEPTH_RECURSE);
  if ( !v6 || v6->mUID == -1 )
    return 0;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v6->mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  v8 = this->mInventoryItemType.mValue == pTrackEnumBinding.m_EnumValue;
  v9 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v9;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  return v8;
}

// File Line: 15178
// RVA: 0x148B430
__int64 dynamic_initializer_for__IsGroupLeaderCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsGroupLeaderCondition", 0xFFFFFFFF);
  IsGroupLeaderCondition::sClassNameUID = result;
  return result;
}

// File Line: 15181
// RVA: 0x2777A0
void __fastcall IsGroupLeaderCondition::IsGroupLeaderCondition(IsGroupLeaderCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsGroupLeaderCondition::`vftable;
}

// File Line: 15185
// RVA: 0x283F30
char __fastcall IsGroupLeaderCondition::Match(IsGroupLeaderCondition *this, ActionContext *action_context)
{
  return UFG::GroupComponent::IsLeader(action_context->mSimObject.m_pPointer);
}

// File Line: 15200
// RVA: 0x148C370
__int64 dynamic_initializer_for__TargetIsGroupLeaderCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsGroupLeaderCondition", 0xFFFFFFFF);
  TargetIsGroupLeaderCondition::sClassNameUID = result;
  return result;
}

// File Line: 15206
// RVA: 0x278BD0
void __fastcall TargetIsGroupLeaderCondition::TargetIsGroupLeaderCondition(TargetIsGroupLeaderCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsGroupLeaderCondition::`vftable;
  this->mTargetType.mValue = 0;
}

// File Line: 15210
// RVA: 0x28C940
char __fastcall TargetIsGroupLeaderCondition::Match(TargetIsGroupLeaderCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                 m_pPointer,
                                 UFG::TargetingSystemBaseComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
      : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
        m_pComponent) )
  {
    return UFG::GroupComponent::IsLeader(*(UFG::SimObject **)(56i64
                                                            * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                                                 + *(_QWORD *)&m_pComponent[1].m_Flags
                                                                                 + 8i64)
                                                            + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                                            + 40));
  }
  else
  {
    return 0;
  }
}

// File Line: 15232
// RVA: 0x148B410
__int64 dynamic_initializer_for__IsGroupFollowerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsGroupFollowerCondition", 0xFFFFFFFF);
  IsGroupFollowerCondition::sClassNameUID = result;
  return result;
}

// File Line: 15235
// RVA: 0x277770
void __fastcall IsGroupFollowerCondition::IsGroupFollowerCondition(IsGroupFollowerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsGroupFollowerCondition::`vftable;
}

// File Line: 15239
// RVA: 0x283F20
bool __fastcall IsGroupFollowerCondition::Match(IsGroupFollowerCondition *this, ActionContext *action_context)
{
  return UFG::GroupComponent::IsFollower(action_context->mSimObject.m_pPointer);
}

// File Line: 15255
// RVA: 0x148C350
__int64 dynamic_initializer_for__TargetIsGroupFollowerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsGroupFollowerCondition", 0xFFFFFFFF);
  TargetIsGroupFollowerCondition::sClassNameUID = result;
  return result;
}

// File Line: 15261
// RVA: 0x278B90
void __fastcall TargetIsGroupFollowerCondition::TargetIsGroupFollowerCondition(TargetIsGroupFollowerCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsGroupFollowerCondition::`vftable;
  this->mTargetType.mValue = 0;
}

// File Line: 15265
// RVA: 0x28C880
bool __fastcall TargetIsGroupFollowerCondition::Match(TargetIsGroupFollowerCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent)
        && UFG::GroupComponent::IsFollower(*(UFG::SimObject **)(56i64
                                                              * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                                                   + 8i64)
                                                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                                              + 40));
  return result;
}

// File Line: 15287
// RVA: 0x148B450
__int64 dynamic_initializer_for__IsGroupMemberCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsGroupMemberCondition", 0xFFFFFFFF);
  IsGroupMemberCondition::sClassNameUID = result;
  return result;
}

// File Line: 15290
// RVA: 0x2777D0
void __fastcall IsGroupMemberCondition::IsGroupMemberCondition(IsGroupMemberCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsGroupMemberCondition::`vftable;
}

// File Line: 15294
// RVA: 0x283F40
bool __fastcall IsGroupMemberCondition::Match(IsGroupMemberCondition *this, ActionContext *action_context)
{
  return UFG::GroupComponent::IsGroupMember(action_context->mSimObject.m_pPointer);
}

// File Line: 15310
// RVA: 0x148C390
__int64 dynamic_initializer_for__TargetIsGroupMemberCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsGroupMemberCondition", 0xFFFFFFFF);
  TargetIsGroupMemberCondition::sClassNameUID = result;
  return result;
}

// File Line: 15316
// RVA: 0x278C10
void __fastcall TargetIsGroupMemberCondition::TargetIsGroupMemberCondition(TargetIsGroupMemberCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsGroupMemberCondition::`vftable;
  this->mTargetType.mValue = 0;
}

// File Line: 15320
// RVA: 0x28CA00
bool __fastcall TargetIsGroupMemberCondition::Match(TargetIsGroupMemberCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                     m_pPointer,
                                     UFG::TargetingSystemBaseComponent::_TypeUID)),
              m_pComponent = ComponentOfTypeHK)
           : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent))
          : (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent),
            m_pComponent)
        && UFG::GroupComponent::IsGroupMember(*(UFG::SimObject **)(56i64
                                                                 * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                                                      + *(_QWORD *)&m_pComponent[1].m_Flags
                                                                                      + 8i64)
                                                                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                                                 + 40));
  return result;
}

// File Line: 15342
// RVA: 0x148C3B0
__int64 dynamic_initializer_for__TargetIsInMyGroupCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsInMyGroupCondition", 0xFFFFFFFF);
  TargetIsInMyGroupCondition::sClassNameUID = result;
  return result;
}

// File Line: 15348
// RVA: 0x278C50
void __fastcall TargetIsInMyGroupCondition::TargetIsInMyGroupCondition(TargetIsInMyGroupCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetIsInMyGroupCondition::`vftable;
  this->mTargetType.mValue = 0;
}

// File Line: 15352
// RVA: 0x28CAC0
bool __fastcall TargetIsInMyGroupCondition::Match(TargetIsInMyGroupCondition *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::GroupComponent *GroupComponent; // rdi
  UFG::SimObject *v6; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimObjectGame *v9; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v11; // rcx
  UFG::GroupComponent *v12; // rax

  m_pPointer = pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  GroupComponent = UFG::GroupComponent::GetGroupComponent(m_pPointer);
  if ( !GroupComponent )
    return 0;
  v6 = pContext->mSimObject.m_pPointer;
  if ( !v6 )
    return 0;
  m_Flags = v6->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = v6->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v9 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = v6->m_Components.p[20].m_pComponent;
  }
  return m_pComponent
      && (v11 = *(UFG::SimObject **)(56i64
                                   * *(unsigned __int8 *)((unsigned __int8)this->mTargetType.mValue
                                                        + *(_QWORD *)&m_pComponent[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40)) != 0i64
      && (v12 = UFG::GroupComponent::GetGroupComponent(v11)) != 0i64
      && UFG::GroupComponent::IsInGroup(GroupComponent, v12);
}

// File Line: 15389
// RVA: 0x148BA50
__int64 dynamic_initializer_for__NumGroupMemberAliveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NumGroupMemberAliveCondition", 0xFFFFFFFF);
  NumGroupMemberAliveCondition::sClassNameUID = result;
  return result;
}

// File Line: 15397
// RVA: 0x277D50
void __fastcall NumGroupMemberAliveCondition::NumGroupMemberAliveCondition(NumGroupMemberAliveCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&NumGroupMemberAliveCondition::`vftable;
  this->m_eInEqualityOperator.mValue = 4;
  this->m_Count = 1;
}

// File Line: 15401
// RVA: 0x285F40
bool __fastcall NumGroupMemberAliveCondition::Match(NumGroupMemberAliveCondition *this, ActionContext *pContext)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::GroupComponent *GroupComponent; // rax
  UFG::GroupComponent *v5; // rsi
  int v6; // edi
  signed int MeshVertexCount; // ebp
  signed int i; // ebx
  UFG::GroupComponent *Follower; // rax
  UFG::SimObjectGame *SimObjectPtr; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v13; // rax
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  GroupComponent = UFG::GroupComponent::GetGroupComponent(m_pPointer);
  v5 = GroupComponent;
  if ( !GroupComponent )
    return 0;
  v6 = 0;
  MeshVertexCount = Scaleform::Render::Hairliner::GetMeshVertexCount(GroupComponent);
  for ( i = 0; i < MeshVertexCount; ++i )
  {
    Follower = UFG::GroupComponent::GetFollower(v5, i);
    if ( Follower )
    {
      SimObjectPtr = (UFG::SimObjectGame *)UFG::GroupComponent::GetSimObjectPtr(Follower);
      if ( SimObjectPtr )
      {
        m_Flags = SimObjectPtr->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = SimObjectPtr->m_Components.p[6].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(SimObjectPtr, UFG::HealthComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(SimObjectPtr, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          m_pComponent = SimObjectPtr->m_Components.p[6].m_pComponent;
        }
        if ( !BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) )
          ++v6;
      }
    }
  }
  v13 = (UFG::SimObjectGame *)UFG::GroupComponent::GetSimObjectPtr(v5);
  if ( v13 )
  {
    v14 = v13->m_Flags;
    if ( (v14 & 0x4000) != 0 )
    {
      ComponentOfTypeHK = v13->m_Components.p[6].m_pComponent;
    }
    else if ( v14 >= 0 )
    {
      if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::HealthComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v13, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = v13->m_Components.p[6].m_pComponent;
    }
    if ( !BYTE4(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev) )
      ++v6;
  }
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)this->m_eInEqualityOperator.mValue, this->m_Count, v6);
}

// File Line: 15454
// RVA: 0x148B5B0
__int64 dynamic_initializer_for__IsPlayerInBerserkModeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayerInBerserkModeCondition", 0xFFFFFFFF);
  IsPlayerInBerserkModeCondition::sClassNameUID = result;
  return result;
}

// File Line: 15457
// RVA: 0x284460
bool __fastcall IsPlayerInBerserkModeCondition::Match(IsPlayerInBerserkModeCondition *this, ActionContext *pContext)
{
  UFG::GameStatTracker *v2; // rax
  bool result; // al

  result = 0;
  if ( pContext )
  {
    v2 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v2, Berserk_Activated) > 0.0 )
      return 1;
  }
  return result;
}

// File Line: 15479
// RVA: 0x148B5F0
__int64 dynamic_initializer_for__IsPlayerInCombatBuffModeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayerInCombatBuffModeCondition", 0xFFFFFFFF);
  IsPlayerInCombatBuffModeCondition::sClassNameUID = result;
  return result;
}

// File Line: 15482
// RVA: 0x2844D0
bool __fastcall IsPlayerInCombatBuffModeCondition::Match(
        IsPlayerInCombatBuffModeCondition *this,
        ActionContext *pContext)
{
  UFG::GameStatTracker *v2; // rax
  bool result; // al

  result = 0;
  if ( pContext )
  {
    v2 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v2, PlayerFaceMeterBuff_Activated) > 0.0 )
      return 1;
  }
  return result;
}

// File Line: 15504
// RVA: 0x148B0B0
__int64 dynamic_initializer_for__HitRecordProcessingCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitRecordProcessingCondition", 0xFFFFFFFF);
  HitRecordProcessingCondition::sClassNameUID = result;
  return result;
}

// File Line: 15507
// RVA: 0x2827A0
bool __fastcall HitRecordProcessingCondition::Match(HitRecordProcessingCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( pContext
    && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HitReactionComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
        ComponentOfTypeHK) )
  {
    return ComponentOfTypeHK[1].m_Flags;
  }
  else
  {
    return 0;
  }
}

// File Line: 15535
// RVA: 0x148B090
__int64 dynamic_initializer_for__HitRecordBerserkAttackFlagCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HitRecordBerserkAttackFlagCondition", 0xFFFFFFFF);
  HitRecordBerserkAttackFlagCondition::sClassNameUID = result;
  return result;
}

// File Line: 15538
// RVA: 0x282700
bool __fastcall HitRecordBerserkAttackFlagCondition::Match(
        HitRecordBerserkAttackFlagCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0
           ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
            ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                     m_pPointer,
                                     UFG::HitReactionComponent::_TypeUID))
            : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID)))
           : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent))
          : (ComponentOfTypeHK = m_pPointer->m_Components.p[15].m_pComponent),
            ComponentOfTypeHK)
        && UFG::HitReactionComponent::msBerserkAttackValidFlag;
  return result;
}

// File Line: 15560
// RVA: 0x148C930
__int64 dynamic_initializer_for__UICameraOverlayExistsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UICameraOverlayExistsCondition", 0xFFFFFFFF);
  UICameraOverlayExistsCondition::sClassNameUID = result;
  return result;
}

// File Line: 15563
// RVA: 0x290AF0
bool __fastcall UICameraOverlayExistsCondition::Match(UICameraOverlayExistsCondition *this, ActionContext *pContext)
{
  return pContext && UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Camera");
}

// File Line: 15587
// RVA: 0x148BEF0
__int64 dynamic_initializer_for__ResourceIsAvailableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ResourceIsAvailableCondition", 0xFFFFFFFF);
  ResourceIsAvailableCondition::sClassNameUID = result;
  return result;
}

// File Line: 15595
// RVA: 0x289720
char __fastcall ResourceIsAvailableCondition::Match(ResourceIsAvailableCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v7; // rax
  __int64 mValue; // r8
  UFG::SimObject *v9; // rcx
  __int16 v10; // dx
  UFG::InterestPoint *ComponentOfType; // rax

  if ( !this->m_bCheckTarget )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( m_pComponent
    && (mValue = (unsigned __int8)this->m_eTargetType.mValue,
        (v9 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + mValue + 8)
                                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                 + 40)) != 0i64)
    && (_BYTE)mValue == 26
    && ((v10 = v9->m_Flags, (v10 & 0x4000) == 0)
      ? (v10 >= 0
       ? ((v10 & 0x2000) == 0
        ? ((v10 & 0x1000) == 0
         ? (ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v9, UFG::InterestPoint::_TypeUID))
         : (ComponentOfType = (UFG::InterestPoint *)v9->m_Components.p[3].m_pComponent))
        : (ComponentOfType = (UFG::InterestPoint *)v9->m_Components.p[10].m_pComponent))
       : (ComponentOfType = (UFG::InterestPoint *)v9->m_Components.p[25].m_pComponent))
      : (ComponentOfType = (UFG::InterestPoint *)v9->m_Components.p[25].m_pComponent),
        ComponentOfType) )
  {
    return UFG::InterestPoint::IsAvailable(ComponentOfType, pContext->mSimObject.m_pPointer, 1);
  }
  else
  {
    return 0;
  }
}

// File Line: 15654
// RVA: 0x148BA70
__int64 dynamic_initializer_for__ObjectIsAvailableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ObjectIsAvailableCondition", 0xFFFFFFFF);
  ObjectIsAvailableCondition::sClassNameUID = result;
  return result;
}

// File Line: 15659
// RVA: 0x2860E0
bool __fastcall ObjectIsAvailableCondition::Match(ObjectIsAvailableCondition *this, ActionContext *pContext)
{
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v3; // rbx
  UFG::ObjectResourceManager *v4; // rax

  PropertySet = UFG::PropertySetManager::GetPropertySet(&this->m_PropertySetName);
  v3 = PropertySet;
  if ( PropertySet )
  {
    v4 = UFG::ObjectResourceManager::Instance();
    LOBYTE(PropertySet) = UFG::ObjectResourceManager::IsLoaded(v4, v3);
  }
  return (char)PropertySet;
}

// File Line: 15680
// RVA: 0x148BE50
__int64 dynamic_initializer_for__PurchasableItemAvailableCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PurchasableItemAvailableCondition", 0xFFFFFFFF);
  PurchasableItemAvailableCondition::sClassNameUID = result;
  return result;
}

// File Line: 15686
// RVA: 0x289270
bool __fastcall PurchasableItemAvailableCondition::Match(
        PurchasableItemAvailableCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v6; // rax
  char m_bCheck; // cl
  __int64 v8; // r8
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[39].m_pComponent;
    }
    else
    {
      v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InventoryComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InventoryComponent::_TypeUID);
      m_pComponent = v6;
    }
    if ( m_pComponent )
    {
      m_bCheck = this->m_bCheck;
      if ( !m_bCheck || this->m_eInventoryItem == *(_DWORD *)&m_pComponent[14].m_Flags )
      {
        v8 = *(int *)&m_pComponent[14].m_Flags;
        if ( LOBYTE(m_pComponent[14].m_pSimObject)
          || *((int *)&m_pComponent[1].m_NameUID + v8) > 0
          || !m_bCheck && this->m_eInventoryItem == (_DWORD)v8 )
        {
          return 1;
        }
      }
    }
  }
  return result;
}

// File Line: 15716
// RVA: 0x148B1B0
__int64 dynamic_initializer_for__InteractionPointFindBestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointFindBestCondition", 0xFFFFFFFF);
  InteractionPointFindBestCondition::sClassNameUID = result;
  return result;
}

// File Line: 15740
// RVA: 0x277440
void __fastcall InteractionPointFindBestCondition::InteractionPointFindBestCondition(
        InteractionPointFindBestCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointFindBestCondition::`vftable;
  *(_DWORD *)&this->m_eOriginTargetType.mValue = 16777217;
  *(_DWORD *)&this->m_bTEST_eTARGET_TYPE_INTERACTION_POINT2 = 16843009;
  this->m_bIgnoreMeshTest = 0;
}

// File Line: 15744
// RVA: 0x282E40
bool __fastcall InteractionPointFindBestCondition::Match(
        InteractionPointFindBestCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // rcx
  UFG::SimComponent *v11; // rax
  __int64 v12; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // dx
  UFG::InteractableComponent *v15; // rbx
  UFG::SimComponent *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  __int16 v18; // dx
  UFG::InteractorComponent *v19; // rdi
  UFG::SimComponent *v20; // rax
  UFG::SimObject *v21; // rdx
  bool v22; // r9
  UFG::InteractionPoint *BestInteractionPoint; // rbx
  UFG::qStaticBitField<6> bfTestIP; // [rsp+38h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  if ( !((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent) )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)this->m_eOriginTargetType.mValue
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  else if ( v9 >= 0 )
  {
    v11 = (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
    v10 = v11;
  }
  else
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  if ( !v10 )
    return 0;
  v12 = ((__int64 (__fastcall *)(UFG::SimComponent *))v10->vfptr[15].__vecDelDtor)(v10);
  if ( !v12 )
    return 0;
  v13 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)this->m_eTargetType.mValue
                                                    + *(_QWORD *)(v12 + 96)
                                                    + 8i64)
                               + *(_QWORD *)(v12 + 88)
                               + 40);
  if ( !v13 )
    return 0;
  v14 = v13->m_Flags;
  if ( (v14 & 0x4000) != 0 )
  {
    v15 = (UFG::InteractableComponent *)v13->m_Components.p[12].m_pComponent;
  }
  else if ( v14 >= 0 )
  {
    v16 = (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InteractableComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v13, UFG::InteractableComponent::_TypeUID);
    v15 = (UFG::InteractableComponent *)v16;
  }
  else
  {
    v15 = (UFG::InteractableComponent *)v13->m_Components.p[12].m_pComponent;
  }
  if ( !v15 )
    return 0;
  v17 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v17 )
    return 0;
  v18 = v17->m_Flags;
  if ( (v18 & 0x4000) != 0 )
  {
    v19 = (UFG::InteractorComponent *)v17->m_Components.p[29].m_pComponent;
  }
  else
  {
    v20 = v18 < 0 || (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::InteractorComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v17, UFG::InteractorComponent::_TypeUID);
    v19 = (UFG::InteractorComponent *)v20;
  }
  if ( !v19 )
    return 0;
  v21 = pContext->mSimObject.m_pPointer;
  v22 = this->m_bIgnoreMeshTest != 0;
  bfTestIP.mBits[0] = (this->m_bTEST_eTARGET_TYPE_INTERACTION_POINT5 != 0 ? 0x20 : 0) | (this->m_bTEST_eTARGET_TYPE_INTERACTION_POINT4 != 0
                                                                                       ? 0x10
                                                                                       : 0) | (this->m_bTEST_eTARGET_TYPE_INTERACTION_POINT3 != 0
                                                                                             ? 8
                                                                                             : 0) | (this->m_bTEST_eTARGET_TYPE_INTERACTION_POINT2 != 0 ? 4 : 0) | (this->m_bTEST_eTARGET_TYPE_INTERACTION_POINT1 != 0 ? 2 : 0) | (unsigned __int64)(this->m_bTEST_eTARGET_TYPE_INTERACTION_POINT0 != 0);
  BestInteractionPoint = UFG::InteractableComponent::FindBestInteractionPoint(v15, v21, &bfTestIP, v22);
  UFG::InteractorComponent::SetBestInteractionPoint(v19, BestInteractionPoint, 1);
  return BestInteractionPoint != 0i64;
}

// File Line: 15824
// RVA: 0x148B230
__int64 dynamic_initializer_for__InteractionPointValidCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointValidCondition", 0xFFFFFFFF);
  InteractionPointValidCondition::sClassNameUID = result;
  return result;
}

// File Line: 15838
// RVA: 0x277540
void __fastcall InteractionPointValidCondition::InteractionPointValidCondition(InteractionPointValidCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointValidCondition::`vftable;
  *(_WORD *)&this->m_eTargetType.mValue = 17664;
  this->m_bIgnoreMeshTest = 0;
}

// File Line: 15842
// RVA: 0x283460
bool __fastcall InteractionPointValidCondition::Match(InteractionPointValidCondition *this, ActionContext *pContext)
{
  __int64 mValue; // rdi
  UFG::eTargetTypeEnum v3; // r14d
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *v9; // rax
  __int64 v10; // rax
  UFG::SimObjectGame *v11; // rcx
  __int16 v12; // dx
  UFG::InteractableComponent *v13; // rsi
  UFG::SimComponent *v14; // rax
  UFG::SimObjectGame *v15; // rbx
  __int16 v16; // cx
  UFG::InteractorComponent *v17; // rdi
  UFG::SimComponent *v18; // rax
  UFG::InteractionPoint *InteractionPoint; // rbx

  mValue = (unsigned __int8)this->m_eTargetType.mValue;
  v3 = (unsigned __int8)this->m_eInteractionPointTargetType.mValue;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v9 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v9;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v10 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[15].__vecDelDtor)(m_pComponent);
  if ( !v10 )
    return 0;
  v11 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v10 + 96) + mValue + 8)
                               + *(_QWORD *)(v10 + 88)
                               + 40);
  if ( !v11 )
    return 0;
  v12 = v11->m_Flags;
  if ( (v12 & 0x4000) != 0 )
  {
    v13 = (UFG::InteractableComponent *)v11->m_Components.p[12].m_pComponent;
  }
  else if ( v12 >= 0 )
  {
    v14 = (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::InteractableComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v11, UFG::InteractableComponent::_TypeUID);
    v13 = (UFG::InteractableComponent *)v14;
  }
  else
  {
    v13 = (UFG::InteractableComponent *)v11->m_Components.p[12].m_pComponent;
  }
  if ( !v13 )
    return 0;
  v15 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v15 )
    return 0;
  v16 = v15->m_Flags;
  if ( (v16 & 0x4000) != 0 )
  {
    v17 = (UFG::InteractorComponent *)v15->m_Components.p[29].m_pComponent;
  }
  else
  {
    v18 = v16 < 0 || (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::InteractorComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v15, UFG::InteractorComponent::_TypeUID);
    v17 = (UFG::InteractorComponent *)v18;
  }
  if ( !v17 )
    return 0;
  InteractionPoint = UFG::InteractableComponent::FindInteractionPoint(v13, v15, v3, this->m_bIgnoreMeshTest != 0);
  UFG::InteractorComponent::SetBestInteractionPoint(v17, InteractionPoint, 1);
  return InteractionPoint != 0i64;
}

// File Line: 15896
// RVA: 0x148B1D0
__int64 dynamic_initializer_for__InteractionPointIsAccessable::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointIsAccessable", 0xFFFFFFFF);
  InteractionPointIsAccessable::sClassNameUID = result;
  return result;
}

// File Line: 15903
// RVA: 0x277490
void __fastcall InteractionPointIsAccessable::InteractionPointIsAccessable(InteractionPointIsAccessable *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointIsAccessable::`vftable;
  this->m_eInteractionPointTargetType.mValue = 69;
}

// File Line: 15907
// RVA: 0x283150
bool __fastcall InteractionPointIsAccessable::Match(InteractionPointIsAccessable *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  UFG::TransformNodeComponent *v9; // rbx
  float y; // xmm2_4
  float z; // xmm1_4
  float x; // xmm0_4
  UFG::HavokNavPosition v14; // [rsp+20h] [rbp-48h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 1;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[12].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractableComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractableComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[12].m_pComponent;
  }
  v7 = (unsigned int)(unsigned __int8)this->m_eInteractionPointTargetType.mValue - 69;
  if ( this->m_eInteractionPointTargetType.mValue == 69 )
  {
    v7 = 0i64;
  }
  else if ( (unsigned int)v7 >= 5 )
  {
    v7 = 5i64;
  }
  if ( !BYTE4((&m_pComponent[2].m_BoundComponentHandles.mNode.mPrev)[20 * v7]) )
    return 1;
  v8 = *((_QWORD *)&m_pComponent[2].m_Flags + 20 * v7);
  if ( !v8 )
    return 1;
  v9 = *(UFG::TransformNodeComponent **)(v8 + 88);
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v14.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = v9->mWorldTransform.v3.y;
  z = v9->mWorldTransform.v3.z;
  x = v9->mWorldTransform.v3.x;
  v14.m_bValid = 0;
  *(_QWORD *)&v14.m_packedKey = -1i64;
  v14.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v14.m_vPosition.z = z;
  v14.m_vPosition.y = y;
  v14.m_vPosition.x = x;
  v14.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(
                                     (__m128)LODWORD(v9->mWorldTransform.v3.x),
                                     (__m128)LODWORD(v9->mWorldTransform.v3.z)),
                                   _mm_unpacklo_ps(
                                     (__m128)LODWORD(v9->mWorldTransform.v3.y),
                                     (__m128)(unsigned int)FLOAT_1_0));
  UFG::HavokNavPosition::Validate(
    &v14,
    COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_050000001)),
    COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
    0.0);
  return v14.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(v14.m_packedKey, v14.m_aiMeshUid)
      && v14.m_packedKey != -1
      && v14.m_aiMeshUid != -1;
}

// File Line: 15948
// RVA: 0x148B1F0
__int64 dynamic_initializer_for__InteractionPointIsBestBusyCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointIsBestBusyCondition", 0xFFFFFFFF);
  InteractionPointIsBestBusyCondition::sClassNameUID = result;
  return result;
}

// File Line: 15952
// RVA: 0x2774D0
void __fastcall InteractionPointIsBestBusyCondition::InteractionPointIsBestBusyCondition(
        InteractionPointIsBestBusyCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointIsBestBusyCondition::`vftable;
}

// File Line: 15956
// RVA: 0x2832F0
bool __fastcall InteractionPointIsBestBusyCondition::Match(
        InteractionPointIsBestBusyCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractorComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractorComponent::_TypeUID)))
          : (ComponentOfType = m_pPointer->m_Components.p[29].m_pComponent),
            ComponentOfType && (mNext = ComponentOfType[1].m_SafePointerList.mNode.mNext) != 0i64)
        && LODWORD(mNext[2].mPrev) != 0;
  return result;
}

// File Line: 15988
// RVA: 0x148B210
__int64 dynamic_initializer_for__InteractionPointIsBestOfTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointIsBestOfTypeCondition", 0xFFFFFFFF);
  InteractionPointIsBestOfTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 15996
// RVA: 0x277500
void __fastcall InteractionPointIsBestOfTypeCondition::InteractionPointIsBestOfTypeCondition(
        InteractionPointIsBestOfTypeCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointIsBestOfTypeCondition::`vftable;
  this->m_eInteractionPointTargetType.mValue = 69;
}

// File Line: 16000
// RVA: 0x283390
bool __fastcall InteractionPointIsBestOfTypeCondition::Match(
        InteractionPointIsBestOfTypeCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // r8
  unsigned int v7; // eax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = m_pPointer->m_Components.p[29].m_pComponent;
  else
    m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractorComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractorComponent::_TypeUID);
  if ( !m_pComponent )
    return 0;
  mNext = m_pComponent[1].m_SafePointerList.mNode.mNext;
  if ( !mNext )
    return 0;
  v7 = (unsigned __int8)this->m_eInteractionPointTargetType.mValue - 69;
  if ( this->m_eInteractionPointTargetType.mValue == 69 )
  {
    v7 = 0;
  }
  else if ( v7 >= 5 )
  {
    v7 = 5;
  }
  return mNext == (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&mNext[1].mNext[10 * v7 + 5].mNext;
}

// File Line: 16036
// RVA: 0x148B0F0
__int64 dynamic_initializer_for__IfTargetsInteractionPointNotBusySetBestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IfTargetsInteractionPointNotBusySetBestCondition", 0xFFFFFFFF);
  IfTargetsInteractionPointNotBusySetBestCondition::sClassNameUID = result;
  return result;
}

// File Line: 16050
// RVA: 0x2772C0
void __fastcall IfTargetsInteractionPointNotBusySetBestCondition::IfTargetsInteractionPointNotBusySetBestCondition(
        IfTargetsInteractionPointNotBusySetBestCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IfTargetsInteractionPointNotBusySetBestCondition::`vftable;
  *(_WORD *)&this->m_eTargetType.mValue = 17692;
  this->m_bIgnoreMeshTest = 0;
}

// File Line: 16063
// RVA: 0x2828E0
_BOOL8 __fastcall IfTargetsInteractionPointNotBusySetBestCondition::Match(
        IfTargetsInteractionPointNotBusySetBestCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  bool v5; // bp
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::InteractableComponent *v11; // rsi
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rbx
  __int16 v14; // cx
  UFG::InteractorComponent *v15; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::InteractionPoint *InteractionPoint; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v5 = 1;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v8;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v9 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)((unsigned __int8)this->m_eTargetType.mValue
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 & 0x4000) != 0 )
        {
          v11 = (UFG::InteractableComponent *)v9->m_Components.p[12].m_pComponent;
        }
        else if ( v10 >= 0 )
        {
          v12 = (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::InteractableComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v9, UFG::InteractableComponent::_TypeUID);
          v11 = (UFG::InteractableComponent *)v12;
        }
        else
        {
          v11 = (UFG::InteractableComponent *)v9->m_Components.p[12].m_pComponent;
        }
        if ( v11 )
        {
          v13 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
          if ( v13 )
          {
            v14 = v13->m_Flags;
            if ( (v14 & 0x4000) != 0 )
            {
              v15 = (UFG::InteractorComponent *)v13->m_Components.p[29].m_pComponent;
            }
            else
            {
              if ( v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
                ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InteractorComponent::_TypeUID);
              else
                ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v13, UFG::InteractorComponent::_TypeUID);
              v15 = (UFG::InteractorComponent *)ComponentOfTypeHK;
            }
            if ( v15 )
            {
              InteractionPoint = UFG::InteractableComponent::FindInteractionPoint(
                                   v11,
                                   v13,
                                   (UFG::eTargetTypeEnum)(unsigned __int8)this->m_eInteractionPointTargetType.mValue,
                                   this->m_bIgnoreMeshTest != 0);
              if ( InteractionPoint )
              {
                v5 = InteractionPoint->m_InteractorList.size == 0;
                if ( !InteractionPoint->m_InteractorList.size )
                  UFG::InteractorComponent::SetBestInteractionPoint(v15, InteractionPoint, 1);
              }
            }
          }
        }
      }
    }
  }
  return v5;
}

// File Line: 16136
// RVA: 0x148C8D0
__int64 dynamic_initializer_for__TimeOfDayCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TimeOfDayCondition", 0xFFFFFFFF);
  TimeOfDayCondition::sClassNameUID = result;
  return result;
}

// File Line: 16150
// RVA: 0x2909C0
bool __fastcall TimeOfDayCondition::Match(TimeOfDayCondition *this, ActionContext *pContext)
{
  UFG::TimeOfDayManager *Instance; // rax

  Instance = UFG::TimeOfDayManager::GetInstance();
  if ( Instance )
    LOBYTE(Instance) = CompareFloat(
                         (UFG::InEqualityOperator)(unsigned __int8)this->m_eInEqualityOperator.mValue,
                         this->mTimeOfDay,
                         Instance->m_SecondsSinceMidnight);
  return (char)Instance;
}

// File Line: 16177
// RVA: 0x148AA50
__int64 dynamic_initializer_for__CharacterPhysicsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CharacterPhysicsCondition", 0xFFFFFFFF);
  CharacterPhysicsCondition::sClassNameUID = result;
  return result;
}

// File Line: 16183
// RVA: 0x276830
void __fastcall CharacterPhysicsCondition::CharacterPhysicsCondition(CharacterPhysicsCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CharacterPhysicsCondition::`vftable;
  this->mMode.mValue = 5;
}

// File Line: 16187
// RVA: 0x27FD40
bool __fastcall CharacterPhysicsCondition::Match(CharacterPhysicsCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::CharacterPhysicsComponent::_TypeUID)),
             m_pComponent = ComponentOfType)
          : (m_pComponent = m_pPointer->m_Components.p[27].m_pComponent),
            m_pComponent)
        && (unsigned __int8)this->mMode.mValue == HIDWORD(m_pComponent[8].m_BoundComponentHandles.mNode.mPrev);
  return result;
}

// File Line: 16215
// RVA: 0x148C110
__int64 dynamic_initializer_for__SocialGreetSuccessfulCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialGreetSuccessfulCondition", 0xFFFFFFFF);
  SocialGreetSuccessfulCondition::sClassNameUID = result;
  return result;
}

// File Line: 16218
// RVA: 0x278770
void __fastcall SocialGreetSuccessfulCondition::SocialGreetSuccessfulCondition(SocialGreetSuccessfulCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialGreetSuccessfulCondition::`vftable;
}

// File Line: 16222
// RVA: 0x28A450
bool __fastcall SocialGreetSuccessfulCondition::Match(SocialGreetSuccessfulCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
    if ( m_pComponent && (BYTE4(m_pComponent[12].m_pSimObject) & 2) != 0 )
      return 1;
  }
  return result;
}

// File Line: 16245
// RVA: 0x148C190
__int64 dynamic_initializer_for__SocialRequiresInteractionPointSyncCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialRequiresInteractionPointSyncCondition", 0xFFFFFFFF);
  SocialRequiresInteractionPointSyncCondition::sClassNameUID = result;
  return result;
}

// File Line: 16248
// RVA: 0x28A700
bool __fastcall SocialRequiresInteractionPointSyncCondition::Match(
        SocialRequiresInteractionPointSyncCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
    if ( m_pComponent && (BYTE4(m_pComponent[3].m_SafePointerList.mNode.mPrev) & 0x20) != 0 )
      return 1;
  }
  return result;
}

// File Line: 16269
// RVA: 0x148BFD0
__int64 dynamic_initializer_for__SocialChargeSuccessfulCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialChargeSuccessfulCondition", 0xFFFFFFFF);
  SocialChargeSuccessfulCondition::sClassNameUID = result;
  return result;
}

// File Line: 16272
// RVA: 0x2786A0
void __fastcall SocialChargeSuccessfulCondition::SocialChargeSuccessfulCondition(SocialChargeSuccessfulCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialChargeSuccessfulCondition::`vftable;
}

// File Line: 16276
// RVA: 0x289DD0
bool __fastcall SocialChargeSuccessfulCondition::Match(SocialChargeSuccessfulCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
    if ( m_pComponent && (BYTE4(m_pComponent[12].m_pSimObject) & 8) != 0 )
      return 1;
  }
  return result;
}

// File Line: 16296
// RVA: 0x148C150
__int64 dynamic_initializer_for__SocialRequiresFastTalkCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialRequiresFastTalkCondition", 0xFFFFFFFF);
  SocialRequiresFastTalkCondition::sClassNameUID = result;
  return result;
}

// File Line: 16299
// RVA: 0x2787A0
void __fastcall SocialRequiresFastTalkCondition::SocialRequiresFastTalkCondition(SocialRequiresFastTalkCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialRequiresFastTalkCondition::`vftable;
}

// File Line: 16303
// RVA: 0x28A5A0
bool __fastcall SocialRequiresFastTalkCondition::Match(SocialRequiresFastTalkCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
    if ( m_pComponent && BYTE4(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev) )
      return 1;
  }
  return result;
}

// File Line: 16323
// RVA: 0x148BFF0
__int64 dynamic_initializer_for__SocialCombatFastTalkSucceededCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialCombatFastTalkSucceededCondition", 0xFFFFFFFF);
  SocialCombatFastTalkSucceededCondition::sClassNameUID = result;
  return result;
}

// File Line: 16326
// RVA: 0x2786D0
void __fastcall SocialCombatFastTalkSucceededCondition::SocialCombatFastTalkSucceededCondition(
        SocialCombatFastTalkSucceededCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialCombatFastTalkSucceededCondition::`vftable;
}

// File Line: 16330
// RVA: 0x289E80
bool __fastcall SocialCombatFastTalkSucceededCondition::Match(
        SocialCombatFastTalkSucceededCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
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
        && (BYTE2(ComponentOfTypeHK[32].m_BoundComponentHandles.mNode.mPrev) & 2) != 0;
  return result;
}

// File Line: 16351
// RVA: 0x148C0F0
__int64 dynamic_initializer_for__SocialFastTalkOccurredCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialFastTalkOccurredCondition", 0xFFFFFFFF);
  SocialFastTalkOccurredCondition::sClassNameUID = result;
  return result;
}

// File Line: 16354
// RVA: 0x278740
void __fastcall SocialFastTalkOccurredCondition::SocialFastTalkOccurredCondition(SocialFastTalkOccurredCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialFastTalkOccurredCondition::`vftable;
}

// File Line: 16358
// RVA: 0x28A3A0
bool __fastcall SocialFastTalkOccurredCondition::Match(SocialFastTalkOccurredCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
    if ( m_pComponent && (BYTE5(m_pComponent[3].m_SafePointerList.mNode.mPrev) & 2) != 0 )
      return 1;
  }
  return result;
}

// File Line: 16378
// RVA: 0x148C090
__int64 dynamic_initializer_for__SocialFaceActionRequiresGreetCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialFaceActionRequiresGreetCondition", 0xFFFFFFFF);
  SocialFaceActionRequiresGreetCondition::sClassNameUID = result;
  return result;
}

// File Line: 16381
// RVA: 0x28A1A0
bool __fastcall SocialFaceActionRequiresGreetCondition::Match(
        SocialFaceActionRequiresGreetCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
  else
    m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
  if ( !m_pComponent )
    return 0;
  return (BYTE4(m_pComponent[12].m_pSimObject) & 1) != 0 || BYTE4(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev);
}

// File Line: 16405
// RVA: 0x148C030
__int64 dynamic_initializer_for__SocialFaceActionAutoChargeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialFaceActionAutoChargeCondition", 0xFFFFFFFF);
  SocialFaceActionAutoChargeCondition::sClassNameUID = result;
  return result;
}

// File Line: 16408
// RVA: 0x289FB0
bool __fastcall SocialFaceActionAutoChargeCondition::Match(
        SocialFaceActionAutoChargeCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)))
          : (ComponentOfType = m_pPointer->m_Components.p[45].m_pComponent),
            ComponentOfType)
        && (BYTE4(ComponentOfType[3].m_SafePointerList.mNode.mPrev) & 8) != 0;
  return result;
}

// File Line: 16431
// RVA: 0x148C0D0
__int64 dynamic_initializer_for__SocialFaceActionUseConfirmationDialogCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialFaceActionUseConfirmationDialogCondition", 0xFFFFFFFF);
  SocialFaceActionUseConfirmationDialogCondition::sClassNameUID = result;
  return result;
}

// File Line: 16434
// RVA: 0x28A300
bool __fastcall SocialFaceActionUseConfirmationDialogCondition::Match(
        SocialFaceActionUseConfirmationDialogCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)))
          : (ComponentOfType = m_pPointer->m_Components.p[45].m_pComponent),
            ComponentOfType)
        && (BYTE4(ComponentOfType[3].m_SafePointerList.mNode.mPrev) & 4) != 0;
  return result;
}

// File Line: 16457
// RVA: 0x148C070
__int64 dynamic_initializer_for__SocialFaceActionGetConfirmationDialogConfirmedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialFaceActionGetConfirmationDialogConfirmedCondition", 0xFFFFFFFF);
  SocialFaceActionGetConfirmationDialogConfirmedCondition::sClassNameUID = result;
  return result;
}

// File Line: 16460
// RVA: 0x28A100
bool __fastcall SocialFaceActionGetConfirmationDialogConfirmedCondition::Match(
        SocialFaceActionGetConfirmationDialogConfirmedCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)))
          : (ComponentOfType = m_pPointer->m_Components.p[45].m_pComponent),
            ComponentOfType)
        && (BYTE4(ComponentOfType[3].m_SafePointerList.mNode.mPrev) & 2) != 0;
  return result;
}

// File Line: 16486
// RVA: 0x148C0B0
__int64 dynamic_initializer_for__SocialFaceActionStateCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialFaceActionStateCondition", 0xFFFFFFFF);
  SocialFaceActionStateCondition::sClassNameUID = result;
  return result;
}

// File Line: 16491
// RVA: 0x28A250
bool __fastcall SocialFaceActionStateCondition::Match(SocialFaceActionStateCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)),
             m_pComponent = ComponentOfType)
          : (m_pComponent = m_pPointer->m_Components.p[45].m_pComponent),
            m_pComponent)
        && (unsigned __int8)this->mFaceActionState.mValue == LODWORD(m_pComponent[3].m_SafePointerList.mNode.mNext);
  return result;
}

// File Line: 16515
// RVA: 0x148C050
__int64 dynamic_initializer_for__SocialFaceActionEnabledCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialFaceActionEnabledCondition", 0xFFFFFFFF);
  SocialFaceActionEnabledCondition::sClassNameUID = result;
  return result;
}

// File Line: 16518
// RVA: 0x28A050
bool __fastcall SocialFaceActionEnabledCondition::Match(
        SocialFaceActionEnabledCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceActionComponent *m_pComponent; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = (UFG::FaceActionComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    m_pPointer,
                                                    UFG::FaceActionComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    m_pPointer,
                                                    UFG::FaceActionComponent::_TypeUID));
    if ( m_pComponent && UFG::FaceActionComponent::IsFaceActionEnabled(m_pComponent) )
      return 1;
  }
  return result;
}

// File Line: 16538
// RVA: 0x148C170
__int64 dynamic_initializer_for__SocialRequiresInteractionAreaCheckCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialRequiresInteractionAreaCheckCondition", 0xFFFFFFFF);
  SocialRequiresInteractionAreaCheckCondition::sClassNameUID = result;
  return result;
}

// File Line: 16541
// RVA: 0x28A650
bool __fastcall SocialRequiresInteractionAreaCheckCondition::Match(
        SocialRequiresInteractionAreaCheckCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceActionComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::FaceActionComponent::_TypeUID);
    if ( m_pComponent && (BYTE4(m_pComponent[3].m_SafePointerList.mNode.mPrev) & 0x40) != 0 )
      return 1;
  }
  return result;
}

// File Line: 16561
// RVA: 0x148C990
__int64 dynamic_initializer_for__UISocialChargeHappenedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UISocialChargeHappenedCondition", 0xFFFFFFFF);
  UISocialChargeHappenedCondition::sClassNameUID = result;
  return result;
}

// File Line: 16564
// RVA: 0x290B60
_BOOL8 __fastcall UISocialChargeHappenedCondition::Match(
        UISocialChargeHappenedCondition *this,
        ActionContext *pContext)
{
  _BOOL8 result; // rax

  result = 0i64;
  if ( UFG::UIHKSocialActionManager::mThis )
    return UFG::UIHKSocialActionManager::SocialAction.mChargeHappened;
  return result;
}

// File Line: 16584
// RVA: 0x148C130
__int64 dynamic_initializer_for__SocialIsTargetStandingSufficientCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialIsTargetStandingSufficientCondition", 0xFFFFFFFF);
  SocialIsTargetStandingSufficientCondition::sClassNameUID = result;
  return result;
}

// File Line: 16587
// RVA: 0x28A500
bool __fastcall SocialIsTargetStandingSufficientCondition::Match(
        SocialIsTargetStandingSufficientCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceActionComponent *ComponentOfType; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::FaceActionComponent::_TypeUID))
           : (ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::FaceActionComponent::_TypeUID)))
          : (ComponentOfType = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent),
            ComponentOfType)
        && UFG::FaceActionComponent::IsTargetStandingSufficient(ComponentOfType);
  return result;
}

// File Line: 16610
// RVA: 0x148AE30
__int64 dynamic_initializer_for__FactionClassCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FactionClassCondition", 0xFFFFFFFF);
  FactionClassCondition::sClassNameUID = result;
  return result;
}

// File Line: 16616
// RVA: 0x281C60
bool __fastcall FactionClassCondition::Match(FactionClassCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer) != 0i64
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
          ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer))
          : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                 m_pPointer,
                                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                 m_pPointer,
                                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID)),
            ComponentOfTypeHK)
        && ComponentOfTypeHK->m_eFactionClass == this->mFactionClass.mValue;
  return result;
}

// File Line: 16640
// RVA: 0x148AE70
__int64 dynamic_initializer_for__GameSliceIsActiveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GameSliceIsActiveCondition", 0xFFFFFFFF);
  GameSliceIsActiveCondition::sClassNameUID = result;
  return result;
}

// File Line: 16646
// RVA: 0x276F50
void __fastcall GameSliceIsActiveCondition::GameSliceIsActiveCondition(GameSliceIsActiveCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&GameSliceIsActiveCondition::`vftable;
  this->mGameSliceId.mUID = -1;
}

// File Line: 16650
// RVA: 0x281DA0
UFG::qBaseTreeRB *__fastcall GameSliceIsActiveCondition::Match(
        GameSliceIsActiveCondition *this,
        ActionContext *pContext)
{
  UFG::qSymbol *p_mGameSliceId; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::qBaseTreeRB *result; // rax

  p_mGameSliceId = &this->mGameSliceId;
  v3 = UFG::ProgressionTracker::Instance();
  result = UFG::ProgressionTracker::Find(v3, p_mGameSliceId, 0);
  if ( result )
    return (UFG::qBaseTreeRB *)(LODWORD(result[3].mNULL.mChild[1]) == 4);
  return result;
}

// File Line: 16671
// RVA: 0x148B870
__int64 dynamic_initializer_for__LastCompletedMissionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LastCompletedMissionCondition", 0xFFFFFFFF);
  LastCompletedMissionCondition::sClassNameUID = result;
  return result;
}

// File Line: 16677
// RVA: 0x2779A0
void __fastcall LastCompletedMissionCondition::LastCompletedMissionCondition(LastCompletedMissionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&LastCompletedMissionCondition::`vftable;
  this->mMissionId.mUID = -1;
}

// File Line: 16681
// RVA: 0x2852E0
bool __fastcall LastCompletedMissionCondition::Match(LastCompletedMissionCondition *this, ActionContext *context)
{
  UFG::GameStatTracker *v3; // rax

  v3 = UFG::GameStatTracker::Instance();
  return UFG::GameStatTracker::GetStat(v3, LastCompletedMission)->mValue.mUID == this->mMissionId.mUID;
}

// File Line: 16700
// RVA: 0x148C970
__int64 dynamic_initializer_for__UIPDAStateCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UIPDAStateCondition", 0xFFFFFFFF);
  UIPDAStateCondition::sClassNameUID = result;
  return result;
}

// File Line: 16706
// RVA: 0x279430
void __fastcall UIPDAStateCondition::UIPDAStateCondition(UIPDAStateCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&UIPDAStateCondition::`vftable;
  this->mState.mValue = 0;
}

// File Line: 16716
// RVA: 0x290B40
bool __fastcall UIPDAStateCondition::Match(UIPDAStateCondition *this, ActionContext *pContext)
{
  int mValue; // ebx

  mValue = this->mState.mValue;
  return mValue == (unsigned int)UFG::UIHK_PDAWidget::GetState();
}

// File Line: 16726
// RVA: 0x148C950
__int64 dynamic_initializer_for__UIPDAIsActiveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UIPDAIsActiveCondition", 0xFFFFFFFF);
  UIPDAIsActiveCondition::sClassNameUID = result;
  return result;
}

// File Line: 16734
// RVA: 0x290B20
bool __fastcall UIPDAIsActiveCondition::Match(UIPDAIsActiveCondition *this, ActionContext *pContext)
{
  return UFG::UIHK_PDAWidget::Get() != 0i64;
}

// File Line: 16744
// RVA: 0x148B610
__int64 dynamic_initializer_for__IsPlayerUsingKeyboardCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPlayerUsingKeyboardCondition", 0xFFFFFFFF);
  IsPlayerUsingKeyboardCondition::sClassNameUID = result;
  return result;
}

// File Line: 16747
// RVA: 0x277880
void __fastcall IsPlayerUsingKeyboardCondition::IsPlayerUsingKeyboardCondition(IsPlayerUsingKeyboardCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsPlayerUsingKeyboardCondition::`vftable;
}

// File Line: 16751
// RVA: 0x284510
_BOOL8 __fastcall IsPlayerUsingKeyboardCondition::Match(IsPlayerUsingKeyboardCondition *this, ActionContext *pContext)
{
  return UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
}

// File Line: 16766
// RVA: 0x148AAF0
__int64 dynamic_initializer_for__CollectibleIsCollectedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollectibleIsCollectedCondition", 0xFFFFFFFF);
  CollectibleIsCollectedCondition::sClassNameUID = result;
  return result;
}

// File Line: 16772
// RVA: 0x2768F0
void __fastcall CollectibleIsCollectedCondition::CollectibleIsCollectedCondition(CollectibleIsCollectedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CollectibleIsCollectedCondition::`vftable;
  this->mTargetType.mValue = 0;
}

// File Line: 16782
// RVA: 0x280020
bool __fastcall CollectibleIsCollectedCondition::Match(CollectibleIsCollectedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int64 mValue; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::CollectibleComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  mValue = this->mTargetType.mValue;
  if ( !m_pPointer )
    goto LABEL_33;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    goto LABEL_33;
  v7 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 & 0x4000) != 0 )
    {
      v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
    }
    else if ( v8 >= 0 )
    {
      if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      v7 = (UFG::SimObjectGame *)ComponentOfTypeHK;
    }
    else
    {
      v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
    }
  }
  v10 = ((__int64 (__fastcall *)(UFG::SimObjectGame *))v7->vfptr[15].__vecDelDtor)(v7);
  if ( v10 )
  {
    v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v10 + 96) + mValue + 8) + *(_QWORD *)(v10 + 88) + 40);
    if ( v11 )
    {
      v12 = *(UFG::SimObjectGame **)(*(_QWORD *)(v11 + 80) + 96i64);
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 & 0x4000) != 0 || v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = (UFG::CollectibleComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v12,
                                                           UFG::CollectibleComponent::_TypeUID);
        else
          ComponentOfType = (UFG::CollectibleComponent *)UFG::SimObject::GetComponentOfType(
                                                           v12,
                                                           UFG::CollectibleComponent::_TypeUID);
        if ( ComponentOfType )
          return ((__int64 (__fastcall *)(UFG::CollectibleComponent *))ComponentOfType->vfptr[19].__vecDelDtor)(ComponentOfType);
      }
    }
  }
  else
  {
LABEL_33:
    ComponentOfType = UFG::CollectibleComponent::GetCollectibleComponent(pContext->mSimObject.m_pPointer);
    if ( ComponentOfType )
      return ((__int64 (__fastcall *)(UFG::CollectibleComponent *))ComponentOfType->vfptr[19].__vecDelDtor)(ComponentOfType);
  }
  return 0;
}

// File Line: 16831
// RVA: 0x148AED0
__int64 dynamic_initializer_for__HasClothingBuffCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HasClothingBuffCondition", 0xFFFFFFFF);
  HasClothingBuffCondition::sClassNameUID = result;
  return result;
}

// File Line: 16837
// RVA: 0x277010
void __fastcall HasClothingBuffCondition::HasClothingBuffCondition(HasClothingBuffCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&HasClothingBuffCondition::`vftable;
  this->mBuffType.mValue = 0;
}

// File Line: 16847
// RVA: 0x281F40
bool __fastcall HasClothingBuffCondition::Match(HasClothingBuffCondition *this, ActionContext *pContext)
{
  int mValue; // ebx
  UFG::GameStatTracker *v3; // rax

  mValue = (unsigned __int8)this->mBuffType.mValue;
  v3 = UFG::GameStatTracker::Instance();
  return mValue == (unsigned int)UFG::GameStatTracker::GetStat(v3, ClothingSetBuff);
}

// File Line: 16871
// RVA: 0x148ABB0
__int64 dynamic_initializer_for__CouldShootSomeoneUnintendedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CouldShootSomeoneUnintendedCondition", 0xFFFFFFFF);
  CouldShootSomeoneUnintendedCondition::sClassNameUID = result;
  return result;
}

// File Line: 16879
// RVA: 0x276A70
void __fastcall CouldShootSomeoneUnintendedCondition::CouldShootSomeoneUnintendedCondition(
        CouldShootSomeoneUnintendedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CouldShootSomeoneUnintendedCondition::`vftable;
  *(_WORD *)&this->mIncludePedestrians = 256;
}

// File Line: 16891
// RVA: 0x2805D0
bool __fastcall CouldShootSomeoneUnintendedCondition::Match(
        CouldShootSomeoneUnintendedCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AimingBaseComponent *ComponentOfType; // rax
  bool result; // al

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = m_pPointer
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::AimingBaseComponent::_TypeUID))
           : (ComponentOfType = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::AimingBaseComponent::_TypeUID)))
          : (ComponentOfType = (UFG::AimingBaseComponent *)m_pPointer->m_Components.p[47].m_pComponent),
            ComponentOfType)
        && UFG::AimingBaseComponent::CouldShootSomeoneUnintended(
             ComponentOfType,
             this->mIncludePedestrians != 0,
             this->mIncludeHostages != 0);
  return result;
}

// File Line: 16915
// RVA: 0x148B790
__int64 dynamic_initializer_for__IsSocialConversationActiveCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsSocialConversationActiveCondition", 0xFFFFFFFF);
  IsSocialConversationActiveCondition::sClassNameUID = result;
  return result;
}

// File Line: 16921
// RVA: 0x2778B0
void __fastcall IsSocialConversationActiveCondition::IsSocialConversationActiveCondition(
        IsSocialConversationActiveCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&IsSocialConversationActiveCondition::`vftable;
  this->mFaceActionResult.mValue = 0;
}

// File Line: 16925
// RVA: 0x284C60
bool __fastcall IsSocialConversationActiveCondition::Match(
        IsSocialConversationActiveCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceActionComponent *m_pComponent; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = (UFG::FaceActionComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    m_pPointer,
                                                    UFG::FaceActionComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    m_pPointer,
                                                    UFG::FaceActionComponent::_TypeUID));
    if ( m_pComponent
      && UFG::FaceActionComponent::IsSocialConversationActive(
           m_pComponent,
           (UFG::eSocialInteractionResultEnum)(unsigned __int8)this->mFaceActionResult.mValue) )
    {
      return 1;
    }
  }
  return result;
}

// File Line: 16948
// RVA: 0x148C010
__int64 dynamic_initializer_for__SocialConversationHasActionRequestsCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SocialConversationHasActionRequestsCondition", 0xFFFFFFFF);
  SocialConversationHasActionRequestsCondition::sClassNameUID = result;
  return result;
}

// File Line: 16954
// RVA: 0x278700
void __fastcall SocialConversationHasActionRequestsCondition::SocialConversationHasActionRequestsCondition(
        SocialConversationHasActionRequestsCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialConversationHasActionRequestsCondition::`vftable;
  this->mFaceActionResult.mValue = 0;
}

// File Line: 16958
// RVA: 0x289F10
bool __fastcall SocialConversationHasActionRequestsCondition::Match(
        SocialConversationHasActionRequestsCondition *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::FaceActionComponent *ComponentOfType; // rax
  bool result; // al

  result = pContext
        && (m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
        && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::FaceActionComponent::_TypeUID))
           : (ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::FaceActionComponent::_TypeUID)))
          : (ComponentOfType = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent),
            ComponentOfType)
        && UFG::FaceActionComponent::SocialConversationHasActionRequests(
             ComponentOfType,
             (UFG::eSocialInteractionResultEnum)(unsigned __int8)this->mFaceActionResult.mValue);
  return result;
}

// File Line: 16982
// RVA: 0x148B570
__int64 dynamic_initializer_for__IsOnFireCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsOnFireCondition", 0xFFFFFFFF);
  IsOnFireCondition::sClassNameUID = result;
  return result;
}

// File Line: 16985
// RVA: 0x2843C0
bool __fastcall IsOnFireCondition::Match(IsOnFireCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterEffectsComponent::_TypeUID))
       : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterEffectsComponent::_TypeUID)))
      : (ComponentOfType = m_pPointer->m_Components.p[38].m_pComponent),
        ComponentOfType) )
  {
    return BYTE4(ComponentOfType[5].m_pSimObject);
  }
  else
  {
    return 0;
  }
}

// File Line: 17004
// RVA: 0x148C410
__int64 dynamic_initializer_for__TargetIsSittingConversationCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetIsSittingConversationCondition", 0xFFFFFFFF);
  TargetIsSittingConversationCondition::sClassNameUID = result;
  return result;
}

// File Line: 17009
// RVA: 0x28CE70
bool __fastcall TargetIsSittingConversationCondition::Match(
        TargetIsSittingConversationCondition *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  __int16 v8; // dx
  UFG::InterestPoint *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v7 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)((unsigned __int8)this->m_TargetType.mValue
                                               + *(_QWORD *)&m_pComponent[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 )
  {
    ComponentOfType = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
  }
  else if ( v8 >= 0 )
  {
    if ( (v8 & 0x2000) != 0 )
    {
      ComponentOfType = (UFG::InterestPoint *)v7->m_Components.p[10].m_pComponent;
    }
    else if ( (v8 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::InterestPoint *)v7->m_Components.p[3].m_pComponent;
    }
    else
    {
      ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v7, UFG::InterestPoint::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
  }
  return ComponentOfType && UFG::InterestPoint::GetIsSittingConversation(ComponentOfType);
}

// File Line: 17035
// RVA: 0x148B890
__int64 dynamic_initializer_for__LowViolenceEnabledCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LowViolenceEnabledCondition", 0xFFFFFFFF);
  LowViolenceEnabledCondition::sClassNameUID = result;
  return result;
}

// File Line: 17055
// RVA: 0x148B390
__int64 dynamic_initializer_for__IsDLCMoveUnlockedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsDLCMoveUnlockedCondition", 0xFFFFFFFF);
  IsDLCMoveUnlockedCondition::sClassNameUID = result;
  return result;
}

// File Line: 17075
// RVA: 0x148B730
__int64 dynamic_initializer_for__IsPossessedPedModeEnabledCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsPossessedPedModeEnabledCondition", 0xFFFFFFFF);
  IsPossessedPedModeEnabledCondition::sClassNameUID = result;
  return result;
}

// File Line: 17078
// RVA: 0x284C00
_BOOL8 __fastcall IsPossessedPedModeEnabledCondition::Match(
        IsPossessedPedModeEnabledCondition *this,
        ActionContext *context)
{
  return UFG::ProgressionTracker::Instance()->mIsPossessedPedsEnabled;
}

// File Line: 17096
// RVA: 0x148A8B0
__int64 dynamic_initializer_for__AmIPossessedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AmIPossessedCondition", 0xFFFFFFFF);
  AmIPossessedCondition::sClassNameUID = result;
  return result;
}

// File Line: 17099
// RVA: 0x27E870
bool __fastcall AmIPossessedCondition::Match(AmIPossessedCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
      ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer))
      : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             m_pPointer,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                             m_pPointer,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    return *((_BYTE *)ComponentOfTypeHK + 248) & 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 17121
// RVA: 0x148B530
__int64 dynamic_initializer_for__IsNavigationControlledCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IsNavigationControlledCondition", 0xFFFFFFFF);
  IsNavigationControlledCondition::sClassNameUID = result;
  return result;
}

// File Line: 17124
// RVA: 0x2841C0
bool __fastcall IsNavigationControlledCondition::Match(IsNavigationControlledCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::NavComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::NavComponent::_TypeUID))
       : (ComponentOfType = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::NavComponent::_TypeUID)))
      : (ComponentOfType = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent),
        ComponentOfType) )
  {
    return UFG::NavComponent::HasDestination(ComponentOfType);
  }
  else
  {
    return 0;
  }
}

// File Line: 17148
// RVA: 0x148C250
__int64 dynamic_initializer_for__TargetAimingDirectionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetAimingDirectionCondition", 0xFFFFFFFF);
  TargetAimingDirectionCondition::sClassNameUID = result;
  return result;
}

// File Line: 17160
// RVA: 0x278910
void __fastcall TargetAimingDirectionCondition::TargetAimingDirectionCondition(TargetAimingDirectionCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAimingDirectionCondition::`vftable;
  this->mOriginTargetType = 22;
  this->mTowardsTargetType = 1;
  this->mInEqualityOperator.mValue = 3;
  this->mAngle = 0.78539819;
}

// File Line: 17165
// RVA: 0x28B830
char __fastcall TargetAimingDirectionCondition::Match(TargetAimingDirectionCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  __int64 v6; // rdx
  __int64 v7; // r8
  UFG::SimObject *v8; // r9
  __int64 v9; // rbx
  __int16 v10; // cx
  UFG::AimingBaseComponent *v11; // rdi
  unsigned int v12; // edx
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  bool v15; // zf
  UFG::TransformNodeComponent *v16; // rbx
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 vAimDirection; // [rsp+30h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v6 = *(_QWORD *)&m_pComponent[1].m_Flags;
  v7 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)((unsigned int)this->mOriginTargetType + v6 + 8) + v7 + 40);
  v9 = *(_QWORD *)(56i64 * *(unsigned __int8 *)((unsigned int)this->mTowardsTargetType + v6 + 8) + v7 + 40);
  if ( v8 && v9 )
  {
    v10 = v8->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      v11 = (UFG::AimingBaseComponent *)v8->m_Components.p[47].m_pComponent;
LABEL_22:
      UFG::AimingBaseComponent::GetAimDirection(v11, &vAimDirection, 0i64);
      v16 = *(UFG::TransformNodeComponent **)(v9 + 88);
      UFG::TransformNodeComponent::UpdateWorldTransform(v16);
      v17 = v16->mWorldTransform.v3.z - v11->m_vAimOriginPosition.z;
      v18 = v16->mWorldTransform.v3.y - v11->m_vAimOriginPosition.y;
      v2.x = v16->mWorldTransform.v3.x - v11->m_vAimOriginPosition.x;
      v2.y = v18;
      v2.z = v17;
      v19 = UFG::qAngleBetween(&vAimDirection, &v2);
      return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue, this->mAngle, v19);
    }
    if ( v10 < 0 || (v10 & 0x2000) != 0 )
    {
      v12 = UFG::AimingBaseComponent::_TypeUID;
      v13 = (UFG::SimObjectGame *)v8;
    }
    else
    {
      v12 = UFG::AimingBaseComponent::_TypeUID;
      v15 = (v10 & 0x1000) == 0;
      v13 = (UFG::SimObjectGame *)v8;
      if ( v15 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::AimingBaseComponent::_TypeUID);
        goto LABEL_21;
      }
    }
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, v12);
LABEL_21:
    v11 = (UFG::AimingBaseComponent *)ComponentOfType;
    goto LABEL_22;
  }
  return 0;
}

// File Line: 17212
// RVA: 0x148BA30
__int64 dynamic_initializer_for__NumCollectiblesCollectedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NumCollectiblesCollectedCondition", 0xFFFFFFFF);
  NumCollectiblesCollectedCondition::sClassNameUID = result;
  return result;
}

// File Line: 17220
// RVA: 0x277D00
void __fastcall NumCollectiblesCollectedCondition::NumCollectiblesCollectedCondition(
        NumCollectiblesCollectedCondition *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&NumCollectiblesCollectedCondition::`vftable;
  this->mTypeName.mUID = -1;
  this->mInEqualityOperator.mValue = 3;
  this->mTarget = 0;
}

// File Line: 17225
// RVA: 0x285EE0
bool __fastcall NumCollectiblesCollectedCondition::Match(
        NumCollectiblesCollectedCondition *this,
        ActionContext *context)
{
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // edi
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  int TrueCount; // eax

  MapBoolStatEnum = UFG::GameStat::GetMapBoolStatEnum(&this->mTypeName, 1);
  if ( MapBoolStatEnum == Num_MapBool_Stats )
    return 0;
  v4 = UFG::GameStatTracker::Instance();
  MapBool = UFG::GameStatTracker::GetMapBool(v4, MapBoolStatEnum);
  TrueCount = UFG::PersistentData::MapBool::GetTrueCount(MapBool);
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)this->mInEqualityOperator.mValue,
           this->mTarget,
           TrueCount);
}

