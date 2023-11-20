// File Line: 248
// RVA: 0x1491AB0
__int64 dynamic_initializer_for__gCollisionLayerEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gCollisionLayerEnum,
    gCollisionLayerStrings,
    gCollisionLayerStringsCount,
    0i64);
  return atexit(dynamic_atexit_destructor_for__gCollisionLayerEnum__);
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
  UELExpressionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&UELExpressionCondition::`vftable;
  v1->mExpressionText.mOffset = 1i64;
  BinString::Set(&v1->mExpressionText, &customWorldMapCaption);
  v1->mExpression.mOffset = 0i64;
}

// File Line: 311
// RVA: 0x2799A0
void __fastcall UELExpressionCondition::~UELExpressionCondition(UELExpressionCondition *this)
{
  UELExpressionCondition *v1; // rbx
  __int64 v2; // rax
  _QWORD *v3; // rcx
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UELExpressionCondition::`vftable;
  v2 = this->mExpression.mOffset;
  if ( v2 )
  {
    v3 = (__int64 *)((char *)&this->mExpression.mOffset + v2);
    if ( v3 )
    {
      *v3 = &UEL::Expression::`vftable;
      operator delete[](v3);
    }
  }
  if ( !(~LOBYTE(v1->mExpressionText.mOffset) & 1) )
  {
    if ( v1->mExpressionText.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v4 = (char *)&v1->mExpressionText + (v1->mExpressionText.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v4 != BinString::sEmptyString )
        operator delete[](v4);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 331
// RVA: 0x290A30
bool __fastcall UELExpressionCondition::Match(UELExpressionCondition *this, ActionContext *context)
{
  UELExpressionCondition *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rcx
  char v10; // [rsp+30h] [rbp-28h]

  v2 = this;
  v3 = context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p->m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = v3->m_Components.p->m_pComponent;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v3, UFG::UELComponent::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType(v3, UFG::UELComponent::_TypeUID);
        v4 = v6;
      }
    }
    else
    {
      v4 = v3->m_Components.p->m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = v2->mExpression.mOffset;
  if ( !v7 )
    return 0;
  v8 = (signed __int64)&v2->mExpression + v7;
  if ( !v8 || !v4 )
    return 0;
  (*(void (__fastcall **)(signed __int64, char *, unsigned int *, _QWORD, _QWORD))(*(_QWORD *)v8 + 24i64))(
    v8,
    &v10,
    &v4[1].m_TypeUID,
    0i64,
    0i64);
  return v10 != 0;
}

// File Line: 360
// RVA: 0x2942E0
void __fastcall UELExpressionCondition::Serialize(UELExpressionCondition *this, IActionTreeSerializer *serializer)
{
  BinString::Set(&this->mExpressionText, &customWorldMapCaption);
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
  ActiveProgressionFlowCondition *v2; // rbx
  UFG::ProgressionTracker *v3; // rax

  v2 = this;
  v3 = UFG::ProgressionTracker::Instance();
  return UFG::ProgressionTracker::GetActiveFlow(v3)->mUID == v2->m_FlowName.mUID;
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
  return atexit(dynamic_atexit_destructor_for__actionEnumState__);
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
  FacialRequestCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FacialRequestCondition::`vftable;
  *(_DWORD *)&v1->mFacialRequest = 0;
}

// File Line: 435
// RVA: 0x2819F0
unsigned __int8 __fastcall FacialRequestCondition::Match(FacialRequestCondition *this, ActionContext *context)
{
  FacialRequestCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AICharacterControllerBaseComponent *v4; // rax
  signed __int64 v5; // r8
  unsigned __int64 v6; // rax
  unsigned __int8 result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !((v3->m_Flags >> 14) & 1) )
    return 0;
  if ( v3 )
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  else
    v4 = 0i64;
  v5 = (signed __int64)&v4->m_Intention;
  v6 = v4->m_Intention.mFacialRequests.mBits[(signed __int64)v2->mFacialRequest >> 6];
  result = _bittest64((const signed __int64 *)&v6, v2->mFacialRequest & 0x3F);
  if ( !v2->mRequestState.mValue )
  {
    if ( result )
      result = *(_BYTE *)(v2->mFacialRequest + v5 + 808) == 0;
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
  ActionRequestCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestCondition::`vftable;
  v1->mActionRequest = gActionRequest_INVALID.m_EnumValue;
  v1->mRequestState.mValue = 0;
}

// File Line: 488
// RVA: 0x27E1F0
unsigned __int8 __fastcall ActionRequestCondition::Match(ActionRequestCondition *this, ActionContext *context)
{
  ActionRequestCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AICharacterControllerBaseComponent *v4; // rax
  signed __int64 v5; // r8
  unsigned __int64 v6; // rax
  unsigned __int8 result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !((v3->m_Flags >> 14) & 1) )
    return 0;
  if ( v3 )
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  else
    v4 = 0i64;
  v5 = (signed __int64)&v4->m_Intention;
  v6 = v4->m_Intention.mActionRequests.mBits[(signed __int64)v2->mActionRequest >> 6];
  result = _bittest64((const signed __int64 *)&v6, v2->mActionRequest & 0x3F);
  if ( !v2->mRequestState.mValue )
  {
    if ( result )
      result = *(_BYTE *)(v2->mActionRequest + v5 + 248) == 0;
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
  return atexit(dynamic_atexit_destructor_for__clothingPurchaseEnum__);
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
  ClothingPurchaseCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ClothingPurchaseCondition::`vftable;
  v1->mClothingPurchase = gActionRequest_Action.m_EnumValue;
}

// File Line: 540
// RVA: 0x27FFD0
char __fastcall ClothingPurchaseCondition::Match(ClothingPurchaseCondition *this, ActionContext *context)
{
  ClothingPurchaseCondition *v2; // rbx
  hkpNullContactMgrFactory *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  hkpNullContactMgr *v7; // rax

  v2 = this;
  v3 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  v7 = hkpNullContactMgrFactory::createContactMgr(v3, v4, v5, v6);
  if ( !v7 || !LODWORD(v7[1].vfptr) || v2->mClothingPurchase != UFG::StoreFront::mLastEquipedItemCategory )
    return 0;
  UFG::StoreFront::mLastEquipedItemCategory = 14;
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
  IsPlayingCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rax
  ActionContext *i; // rax
  bool v11; // r9
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  ActionController *v15; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( (v3->m_Flags & 0x8000u) != 0 && v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[19].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIActionTreeComponent::_TypeUID);
      else
        v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIActionTreeComponent::_TypeUID);
    }
    else
    {
      v6 = v3->m_Components.p[19].m_pComponent;
    }
    if ( v6 )
    {
      v7 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v7->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          else
            v9 = (UFG::AiDriverComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v7->vfptr,
                                                               UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v7->vfptr,
                                                                                                     UFG::AiDriverComponent::_TypeUID));
        }
        else
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        }
        if ( v9 )
        {
          for ( i = v4->mParentContext; i; i = i->mParentContext )
            v4 = i;
          v11 = v2->mCheckSpawn != 0;
          goto LABEL_42;
        }
      }
    }
  }
  if ( !v2->mCheckSpawn )
  {
    v11 = 0;
    goto LABEL_42;
  }
  v12 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( !v12
    || ((v13 = v12->m_Flags, !((v13 >> 14) & 1)) ? ((v13 & 0x8000u) == 0 ? (!((v13 >> 13) & 1) ? (!((v13 >> 12) & 1) ? (v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::ActionTreeComponent::_TypeUID)) : (v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID))) : (v14 = v12->m_Components.p[6].m_pComponent)) : (v14 = v12->m_Components.p[7].m_pComponent)) : (v14 = v12->m_Components.p[7].m_pComponent),
        !v14) )
  {
    v11 = 1;
LABEL_42:
    v15 = v4->mActionController;
    return ActionController::IsPlaying(v15, &v2->mActionNodeName, v2->mMostUsedIndex, v11);
  }
  v15 = (ActionController *)&v14[3];
  v11 = 1;
  return ActionController::IsPlaying(v15, &v2->mActionNodeName, v2->mMostUsedIndex, v11);
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
  __int64 v2; // r8
  bool result; // al

  v2 = this->mThisNode.mOffset;
  if ( v2 )
    result = context->mActionController->m_currentNode == (ActionNodePlayable *)((char *)&this->mThisNode + v2);
  else
    result = context->mActionController->m_currentNode == 0i64;
  return result;
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
  __int64 v2; // rax
  ActionNodePlayable *v3; // rcx
  ActionNodePlayable *v4; // rax
  __int64 v5; // rdx

  v2 = this->mThisNode.mOffset;
  if ( v2 )
    v3 = (ActionNodePlayable *)((char *)&this->mThisNode + v2);
  else
    v3 = 0i64;
  v4 = context->mActionController->m_currentNode;
  if ( v4 )
  {
    while ( 1 )
    {
      v5 = v4->mParent.mOffset;
      if ( !v5 || !(UFG::qOffset64<ActionNode *> *)((char *)&v4->mParent + v5) )
        break;
      if ( (unsigned int)v3 >= (unsigned int)v4 )
      {
        if ( v3 == v4 )
          return 1;
        if ( (unsigned int)v3 > (unsigned int)v4 )
          return 0;
      }
      v4 = (ActionNodePlayable *)((char *)v4 + v5 + 16);
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
  __int64 v2; // rax
  ActionContext *v3; // r9
  IsPlayingNodeCondition *v4; // rdx
  __int64 v5; // rcx
  ActionNode *v6; // r10
  char v7; // cl
  bool v8; // zf
  ActionContext *i; // rax

  v2 = this->mActionNodeReference.mOffset;
  v3 = context;
  v4 = this;
  if ( v2 )
    v2 += (__int64)&this->mActionNodeReference;
  v5 = *(_QWORD *)(v2 + 72);
  if ( !v5 )
    return 0;
  v6 = (ActionNode *)(v5 + v2 + 72);
  if ( !v6 )
    return 0;
  v7 = v4->mCheckSpawn;
  v8 = v7 == 0;
  if ( v7 )
  {
    for ( i = v3->mParentContext; i; i = i->mParentContext )
      v3 = i;
    v8 = v7 == 0;
  }
  return ActionController::IsPlayingFullPath(v3->mActionController, v6, !v8);
}

// File Line: 713
// RVA: 0x27AE60
Expression::IMemberMap *__fastcall IsPlayingNodeCondition::CreateClone(IsPlayingNodeCondition *this)
{
  IsPlayingNodeCondition *v1; // rsi
  char *v2; // rax
  char *v3; // rbx
  ActionNodeReference *v4; // rdi
  __int64 v5; // rax
  ActionNodeReference *v6; // rdx
  __int64 v7; // rax

  v1 = this;
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
  v5 = v1->mActionNodeReference.mOffset;
  if ( v5 )
    v6 = (ActionNodeReference *)((char *)&v1->mActionNodeReference + v5);
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
  IsPlayingPreviousCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rax
  ActionContext *i; // rax
  bool v11; // r8
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::SimObjectGame *v15; // rcx
  ActionController *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[19].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIActionTreeComponent::_TypeUID);
      else
        v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIActionTreeComponent::_TypeUID);
    }
    else
    {
      v6 = v3->m_Components.p[19].m_pComponent;
    }
    if ( v6 )
    {
      v7 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v7->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          else
            v9 = (UFG::AiDriverComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v7->vfptr,
                                                               UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v7->vfptr,
                                                                                                     UFG::AiDriverComponent::_TypeUID));
        }
        else
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        }
        if ( v9 )
        {
          for ( i = v4->mParentContext; i; i = i->mParentContext )
            v4 = i;
          v11 = v2->mCheckSpawn != 0;
          goto LABEL_51;
        }
      }
    }
  }
  if ( !v2->mCheckSpawn )
  {
    v11 = 0;
    goto LABEL_51;
  }
  v12 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( !v12
    || ((v13 = v12->m_Flags, !((v13 >> 14) & 1)) ? ((v13 & 0x8000u) == 0 ? (!((v13 >> 13) & 1) ? (!((v13 >> 12) & 1) ? (v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::ActionTreeComponent::_TypeUID)) : (v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID))) : (v14 = v12->m_Components.p[6].m_pComponent)) : (v14 = v12->m_Components.p[7].m_pComponent)) : (v14 = v12->m_Components.p[7].m_pComponent),
        !v14) )
  {
    v11 = 1;
LABEL_51:
    v16 = v4->mActionController;
    return ActionController::WasPlaying(v16, &v2->mActionNodeName, v11);
  }
  v15 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v15 )
  {
    v17 = v15->m_Flags;
    if ( (v17 >> 14) & 1 || (v17 & 0x8000u) != 0 )
    {
      v11 = 1;
      v16 = (ActionController *)&v15->m_Components.p[7].m_pComponent[3];
    }
    else if ( (v17 >> 13) & 1 )
    {
      v11 = 1;
      v16 = (ActionController *)&v15->m_Components.p[6].m_pComponent[3];
    }
    else
    {
      if ( (v17 >> 12) & 1 )
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::ActionTreeComponent::_TypeUID);
      else
        v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::ActionTreeComponent::_TypeUID);
      v11 = 1;
      v16 = (ActionController *)&v18[3];
    }
  }
  else
  {
    v11 = 1;
    v16 = (ActionController *)192;
  }
  return ActionController::WasPlaying(v16, &v2->mActionNodeName, v11);
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
  __int64 v2; // rax
  ActionContext *v3; // r8
  IsPlayingNodePreviousCondition *v4; // rdx
  __int64 v5; // rcx
  ActionNode *v6; // r9
  ActionContext *i; // rax

  v2 = this->mActionNodeReference.mOffset;
  v3 = context;
  v4 = this;
  if ( v2 )
    v2 += (__int64)&this->mActionNodeReference;
  v5 = *(_QWORD *)(v2 + 72);
  if ( !v5 )
    return 0;
  v6 = (ActionNode *)(v5 + v2 + 72);
  if ( !v6 )
    return 0;
  if ( v4->mCheckSpawn )
  {
    for ( i = v3->mParentContext; i; i = i->mParentContext )
      v3 = i;
  }
  return ActionController::WasPlayingFullPath(v3->mActionController, v6);
}

// File Line: 822
// RVA: 0x27AF10
Expression::IMemberMap *__fastcall IsPlayingNodePreviousCondition::CreateClone(IsPlayingNodePreviousCondition *this)
{
  IsPlayingNodePreviousCondition *v1; // rsi
  char *v2; // rax
  char *v3; // rbx
  ActionNodeReference *v4; // rdi
  __int64 v5; // rax
  ActionNodeReference *v6; // rdx
  __int64 v7; // rax

  v1 = this;
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
  v5 = v1->mActionNodeReference.mOffset;
  if ( v5 )
    v6 = (ActionNodeReference *)((char *)&v1->mActionNodeReference + v5);
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
  IsPlayingNextCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  signed __int64 v8; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[7].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = v3->m_Components.p[6].m_pComponent;
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[7].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = v5[3].m_BoundComponentHandles.mNode.mNext;
  if ( !v6 )
    return 0;
  while ( LODWORD(v6[2].mNext) != v2->mActionNodeName.mUID )
  {
    v7 = v6[1].mPrev;
    v8 = (signed __int64)&v6[1];
    if ( v7 )
    {
      v6 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)((char *)v7 + v8);
      if ( v6 )
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
  TargetIsPlayingCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  UFG::SimComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // eax
  UFG::SimObjectGame *v9; // rcx
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v7;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = v2->mTargetType;
  if ( v5 )
  {
    v9 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + v8 + 8i64)
                                + *(_QWORD *)&v5[1].m_TypeUID
                                + 40);
  }
  else
  {
    if ( v8 != 2 )
      return 0;
    v10 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( !v10 )
      return 0;
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v10->m_Components.p[15].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HitReactionComponent::_TypeUID);
      else
        v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::HitReactionComponent::_TypeUID);
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
    if ( (v13 >> 14) & 1 )
    {
      v14 = v9->m_Components.p[7].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
        v14 = v9->m_Components.p[6].m_pComponent;
      else
        v14 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v14 = v9->m_Components.p[7].m_pComponent;
    }
    if ( v14 )
      return ActionController::IsPlaying(
               (ActionController *)&v14[3],
               &v2->mActionNodeName,
               v2->mMostUsedIndex,
               v2->mCheckSpawn != 0);
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
  ActionContext *v2; // r14
  int v3; // edx
  TargetIsSubTargetValid *v4; // rdi
  UFG::SimObject *v6; // rax
  UFG::SimObject *v7; // rsi
  unsigned __int16 v8; // dx
  UFG::InterestPoint *v9; // rbx
  UFG::SimObjectGame *v10; // rax
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::SimObject *v15; // rcx
  UFG::SceneObjectProperties *v16; // rcx
  UFG::SceneObjectProperties *v17; // rax
  UFG::qPropertySet *v18; // rcx
  UFG::qBaseNodeRB *v19; // rax
  UFG::SimObjectGame *v20; // rcx
  UFG::eTargetTypeEnum v21; // ebx
  UFG::TargetingSystemBaseComponent *v22; // rax
  unsigned __int16 v23; // dx
  unsigned int v24; // edx
  bool v25; // zf
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  UFG::qSymbol name; // [rsp+50h] [rbp+18h]

  v2 = context;
  v3 = this->m_SubTargetType;
  v4 = this;
  if ( !v3 )
    return 0;
  v6 = UFG::getTarget(v2->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)v3);
  v7 = 0i64;
  if ( v6 )
  {
    v8 = v6->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v9 = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent;
      else
        v9 = (UFG::InterestPoint *)((v8 >> 12) & 1 ? v6->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                            v6,
                                                                                            UFG::InterestPoint::_TypeUID));
    }
    else
    {
      v9 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
    }
    if ( v9 )
    {
      TargetIsSubTargetValid::GetSubTargetName(v4, &result);
      if ( v4->m_RetrieveParent )
      {
        v10 = (UFG::SimObjectGame *)UFG::InterestPoint::GetParent(v9);
      }
      else if ( result.mUID == -1 )
      {
        v10 = (UFG::SimObjectGame *)UFG::InterestPoint::GetChild(v9, v4->m_Index);
      }
      else
      {
        v10 = (UFG::SimObjectGame *)UFG::InterestPoint::GetChild(v9, &result);
      }
      if ( v10 )
      {
        if ( v4->m_WantSubTargetUser )
        {
          v11 = v10->m_Flags;
          if ( (v11 >> 14) & 1 )
          {
            v12 = v10->m_Components.p[25].m_pComponent;
          }
          else if ( (v11 & 0x8000u) == 0 )
          {
            if ( (v11 >> 13) & 1 )
            {
              v12 = v10->m_Components.p[10].m_pComponent;
            }
            else if ( (v11 >> 12) & 1 )
            {
              v12 = v10->m_Components.p[3].m_pComponent;
            }
            else
            {
              v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::InterestPoint::_TypeUID);
            }
          }
          else
          {
            v12 = v10->m_Components.p[25].m_pComponent;
          }
          if ( v12 )
            v7 = (UFG::SimObject *)v12[5].m_BoundComponentHandles.mNode.mNext;
        }
        else if ( v4->m_AsSpawnpointSpawn )
        {
          v13 = v10->m_Flags;
          if ( (v13 >> 14) & 1 )
          {
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::SpawnPoint::_TypeUID);
          }
          else if ( (v13 & 0x8000u) == 0 )
          {
            if ( (v13 >> 13) & 1 )
            {
              v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::SpawnPoint::_TypeUID);
            }
            else if ( (v13 >> 12) & 1 )
            {
              v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::SpawnPoint::_TypeUID);
            }
            else
            {
              v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::SpawnPoint::_TypeUID);
            }
          }
          else
          {
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::SpawnPoint::_TypeUID);
          }
          if ( v14 )
          {
            v15 = v14->m_pSimObject;
            v16 = v15 ? v15->m_pSceneObj : 0i64;
            v17 = UFG::SceneObjectProperties::GetChildAsSceneObject(v16, 0);
            if ( v17 )
            {
              v18 = v17->mpWritableProperties;
              if ( !v18 )
                v18 = v17->mpConstProperties;
              name.mUID = v18->mName.mUID;
              v19 = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
              if ( v19 )
                v7 = (UFG::SimObject *)v19;
            }
          }
        }
        else
        {
          v7 = (UFG::SimObject *)&v10->vfptr;
        }
      }
      if ( v4->m_AssignResult )
      {
        v20 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
        v21 = v4->m_AssignToTargetType;
        if ( v20 )
        {
          v23 = v20->m_Flags;
          if ( (v23 >> 14) & 1 || (v23 & 0x8000u) != 0 )
          {
            v22 = (UFG::TargetingSystemBaseComponent *)v20->m_Components.p[20].m_pComponent;
          }
          else
          {
            if ( (v23 >> 13) & 1 )
            {
              v24 = UFG::TargetingSystemBaseComponent::_TypeUID;
            }
            else
            {
              v25 = ((v23 >> 12) & 1) == 0;
              v24 = UFG::TargetingSystemBaseComponent::_TypeUID;
              if ( v25 )
              {
                v22 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v20->vfptr,
                                                             UFG::TargetingSystemBaseComponent::_TypeUID);
                goto LABEL_63;
              }
            }
            v22 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v20, v24);
          }
        }
        else
        {
          v22 = 0i64;
        }
LABEL_63:
        UFG::TargetingSystemBaseComponent::SetTarget(v22, v21, v7);
        return v7 != 0i64;
      }
    }
  }
  return v7 != 0i64;
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
  hkpNullContactMgr *v6; // rax

  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  v6 = hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
  return v6 && LODWORD(v6[1].vfptr);
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
  TargetIsFemaleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetIsFemaleCondition::`vftable;
  v1->mTargetType.mValue = 0;
}

// File Line: 1165
// RVA: 0x28C7C0
bool __fastcall TargetIsFemaleCondition::Match(TargetIsFemaleCondition *this, ActionContext *pContext)
{
  TargetIsFemaleCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5) )
  {
    result = UFG::IsFemale(*(UFG::SimObject **)(56i64
                                              * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                                   + *(_QWORD *)&v5[1].m_Flags
                                                                   + 8i64)
                                              + *(_QWORD *)&v5[1].m_TypeUID
                                              + 40));
  }
  else
  {
    result = 0;
  }
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID))) : (v4 = v2->m_Components.p[6].m_pComponent)) : (v4 = v2->m_Components.p[6].m_pComponent),
        v4) )
  {
    result = BYTE6(v4[1].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    result = 0;
  }
  return result;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID))) : (v4 = v2->m_Components.p[6].m_pComponent)) : (v4 = v2->m_Components.p[6].m_pComponent),
        v4) )
  {
    result = BYTE5(v4[1].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    result = 0;
  }
  return result;
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
  RagdollHasConstraintsCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollHasConstraintsCondition::`vftable;
  v1->mAttachJointName.mUID = -1;
  v1->mAttachJointName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 1273
// RVA: 0x289340
bool __fastcall RagdollHasConstraintsCondition::Match(RagdollHasConstraintsCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::RagdollComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RagdollComponent::_TypeUID)) : (v4 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID))) : (v4 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID))) : (v4 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID))) : (v4 = (UFG::RagdollComponent *)v2->m_Components.p[42].m_pComponent),
        v4) )
  {
    result = UFG::RagdollComponent::HasConstraints(v4);
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 1306
// RVA: 0x1491B00
__int64 dynamic_initializer_for__gMinigameListEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gMinigameListEnum, gMinigameListNames, gMinigameListCount, 0i64);
  return atexit(dynamic_atexit_destructor_for__gMinigameListEnum__);
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
  int v2; // edx
  _BOOL8 result; // rax

  v2 = this->mMinigame;
  if ( !v2 )
    return UFG::UIHKScreenPickLockMinigame::m_bWon;
  if ( v2 == 1 )
    return UFG::UIHKScreenSafeCrackingMinigame::m_bWon;
  result = 0i64;
  if ( v2 == 2 )
    result = UFG::UIHKScreenHackingMinigame::m_bWon;
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
  MotionIntentionSpeed *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionSpeed::`vftable;
  v1->mSpeed = 0.0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 1363
// RVA: 0x285C40
char __fastcall MotionIntentionSpeed::Match(MotionVelocityMagnitude *this, ActionContext *context)
{
  MotionVelocityMagnitude *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID)) : (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3)),
        v5) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mSpeed,
               v5->m_Intention.mMotionIntentionSpeed);
  }
  else
  {
    result = 0;
  }
  return result;
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
  MotionIntentionSpeedRaw *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionSpeedRaw::`vftable;
  v1->mSpeed = 0.0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 1406
// RVA: 0x285CE0
char __fastcall MotionIntentionSpeedRaw::Match(MotionIntentionSpeedRaw *this, ActionContext *context)
{
  MotionIntentionSpeedRaw *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID)) : (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3)),
        v5) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mSpeed,
               v5->m_Intention.mMotionIntentionSpeedRaw);
  }
  else
  {
    result = 0;
  }
  return result;
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
  FacingIntentionDirection *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FacingIntentionDirection::`vftable;
  v1->mDirection = 0.0;
  v1->mAngleRange = 1.5707964;
}

// File Line: 1449
// RVA: 0x281A70
bool __fastcall FacingIntentionDirection::Match(FacingIntentionDirection *this, ActionContext *context)
{
  FacingIntentionDirection *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::AICharacterControllerBaseComponent *v6; // rax
  UFG::AICharacterControllerBaseComponent *v7; // rbx
  UFG::SimObject *v8; // rdi
  UFG::TransformNodeComponent *v9; // rdi
  _BOOL8 v10; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3
    && ((v5 = v3->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID)) : (v6 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v6 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3))) : (v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3)),
        (v7 = v6) != 0i64 && (v8 = v4->mSimObject.m_pPointer) != 0i64 && (v9 = v8->m_pTransformNodeComponent) != 0i64) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    v10 = UFG::qAngleBetween(&v7->m_Intention.mFacingIntentionDirection, (UFG::qVector3 *)&v9->mWorldTransform) <= v2->mAngleRange;
  }
  else
  {
    LOBYTE(v10) = 0;
  }
  return v10;
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
  FacingPelvisDirection *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FacingPelvisDirection::`vftable;
  v1->mDirection = 0.0;
  v1->mAngleRange = 1.5707964;
}

// File Line: 1497
// RVA: 0x1491A10
__int64 dynamic_initializer_for__bip01PelvisUC_UID__()
{
  UFG::qSymbolUC::create_from_string(&bip01PelvisUC_UID, "Bip01 Pelvis");
  return atexit(dynamic_atexit_destructor_for__bip01PelvisUC_UID__);
}

// File Line: 1500
// RVA: 0x281B60
bool __fastcall FacingPelvisDirection::Match(FacingPelvisDirection *this, ActionContext *context)
{
  FacingPelvisDirection *v2; // rdi
  UFG::SimObjectProp *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterAnimationComponent *v5; // rax
  Creature *v6; // rbx
  int v7; // eax
  _BOOL8 v8; // rax
  UFG::qVector3 v1; // [rsp+20h] [rbp-58h]
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-48h]

  v2 = this;
  v3 = (UFG::SimObjectProp *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterAnimationComponent::_TypeUID)) : (v5 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::CharacterAnimationComponent::_TypeUID))) : (v5 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v3)),
        v5
     && (v6 = v5->mCreature) != 0i64
     && v6->mPose.mRigHandle.mData
     && (v7 = Skeleton::GetBoneID(v6->mPose.mRigHandle.mUFGSkeleton, bip01PelvisUC_UID.mUID), v7 >= 0)) )
  {
    *(_QWORD *)&v1.x = 0i64;
    LODWORD(v1.z) = (_DWORD)FLOAT_1_0;
    Creature::GetTransform(v6, v7, &transform);
    v8 = UFG::qAngleBetween(&v1, (UFG::qVector3 *)&transform.v1) <= v2->mAngleRange;
  }
  else
  {
    LOBYTE(v8) = 0;
  }
  return v8;
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
  MotionIntentionDirection *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionDirection::`vftable;
  *(_QWORD *)&v1->mDirection = 0i64;
  v1->mDirectionCos = 1.0;
  v1->mAngleRange = 1.5707964;
}

// File Line: 1557
// RVA: 0x2853E0
bool __fastcall MotionIntentionDirection::Match(MotionIntentionDirection *this, ActionContext *context)
{
  MotionIntentionDirection *rsi1; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::AICharacterControllerBaseComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  UFG::TransformNodeComponent *v8; // rbx
  UFG::AICharacterControllerBaseComponent *v9; // rax
  unsigned __int16 v10; // dx
  float v11; // xmm6_4
  float v12; // xmm7_4
  UFG::qVector3 *v13; // rbp
  UFG::SimObject *v14; // rax
  float v15; // xmm6_4
  float v16; // xmm7_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-38h]

  rsi1 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v3->vfptr,
                                                        UFG::AICharacterControllerBaseComponent::_TypeUID);
    else
      v6 = (UFG::AICharacterControllerBaseComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
  }
  else
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  }
  if ( !v6 )
    return 0;
  v7 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
  if ( !v7 || !v7->m_pTransformNodeComponent )
    return 0;
  v8 = 0i64;
  if ( v7 )
  {
    v10 = v7->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v7);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v7->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v7->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v7->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v7);
    }
  }
  else
  {
    v9 = 0i64;
  }
  v11 = rsi1->mDirectionCos;
  v12 = rsi1->mDirectionSin;
  v13 = &v9->m_Intention.mMotionIntentionDirection;
  v14 = v4->mSimObject.m_pPointer;
  if ( v14 )
    v8 = v14->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v2.x = (float)(v12 * v8->mWorldTransform.v0.y) + (float)(v11 * v8->mWorldTransform.v0.x);
  v15 = v11 * v8->mWorldTransform.v0.y;
  v16 = v12 * v8->mWorldTransform.v0.x;
  v2.z = 0.0;
  v2.y = v15 - v16;
  return UFG::qAngleBetween(v13, &v2) <= rsi1->mAngleRange;
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
  MotionIntentionDirectionRaw *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionDirectionRaw::`vftable;
  *(_QWORD *)&v1->mDirection = 0i64;
  v1->mDirectionCos = 1.0;
  v1->mAngleRange = 1.5707964;
}

// File Line: 1620
// RVA: 0x2855A0
bool __fastcall MotionIntentionDirectionRaw::Match(MotionIntentionDirectionRaw *this, ActionContext *context)
{
  MotionIntentionDirectionRaw *rsi1; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::AICharacterControllerBaseComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  UFG::TransformNodeComponent *v8; // rbx
  UFG::AICharacterControllerBaseComponent *v9; // rax
  unsigned __int16 v10; // dx
  float v11; // xmm6_4
  float v12; // xmm7_4
  UFG::qVector3 *v13; // rbp
  UFG::SimObject *v14; // rax
  float v15; // xmm6_4
  float v16; // xmm7_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-38h]

  rsi1 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v3->vfptr,
                                                        UFG::AICharacterControllerBaseComponent::_TypeUID);
    else
      v6 = (UFG::AICharacterControllerBaseComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
  }
  else
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  }
  if ( !v6 )
    return 0;
  v7 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
  if ( !v7 || !v7->m_pTransformNodeComponent )
    return 0;
  v8 = 0i64;
  if ( v7 )
  {
    v10 = v7->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v7);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v7->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v7->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v7->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v7);
    }
  }
  else
  {
    v9 = 0i64;
  }
  v11 = rsi1->mDirectionCos;
  v12 = rsi1->mDirectionSin;
  v13 = &v9->m_Intention.mMotionIntentionDirectionRaw;
  v14 = v4->mSimObject.m_pPointer;
  if ( v14 )
    v8 = v14->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v2.x = (float)(v12 * v8->mWorldTransform.v0.y) + (float)(v11 * v8->mWorldTransform.v0.x);
  v15 = v11 * v8->mWorldTransform.v0.y;
  v16 = v12 * v8->mWorldTransform.v0.x;
  v2.z = 0.0;
  v2.y = v15 - v16;
  return UFG::qAngleBetween(v13, &v2) <= rsi1->mAngleRange;
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
  MotionIntentionDirectionRel *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionDirectionRel::`vftable;
  *(_QWORD *)&v1->mDirection = 0i64;
  v1->mDirectionCos = 1.0;
  v1->mAngleRange = 1.5707964;
}

// File Line: 1682
// RVA: 0x285760
bool __fastcall MotionIntentionDirectionRel::Match(MotionIntentionDirectionRel *this, ActionContext *context)
{
  MotionIntentionDirectionRel *rsi1; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::AICharacterControllerBaseComponent *v6; // rax
  UFG::AICharacterControllerBaseComponent *v7; // rbx
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  float *v11; // rcx
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-18h]

  rsi1 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v3->vfptr,
                                                        UFG::AICharacterControllerBaseComponent::_TypeUID);
    else
      v6 = (UFG::AICharacterControllerBaseComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
  }
  else
  {
    v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  }
  v7 = v6;
  if ( !v6 )
    return 0;
  v8 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
    else
      v10 = (UFG::CharacterAnimationComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&v8->vfptr,
                                                                    UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
  }
  if ( !v10 )
    return 0;
  v11 = (float *)v10->mCreature;
  if ( !v11 || v11[51] <= 0.000099999997 )
    return 0;
  v12 = v11[49];
  v13 = v11[48];
  v14 = (float)(v13 * rsi1->mDirectionCos) + (float)(v12 * rsi1->mDirectionSin);
  v15 = (float)(v12 * rsi1->mDirectionCos) - (float)(v13 * rsi1->mDirectionSin);
  v2.x = v14;
  v2.y = v15;
  v2.z = 0.0;
  return UFG::qAngleBetween(&v7->m_Intention.mMotionIntentionDirection, &v2) <= rsi1->mAngleRange;
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
void __fastcall MotionIntentionDirectionRelTarget::MotionIntentionDirectionRelTarget(MotionIntentionDirectionRelTarget *this)
{
  MotionIntentionDirectionRelTarget *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionDirectionRelTarget::`vftable;
  v1->mTargetType.mValue = 22;
  *(_QWORD *)&v1->mDirection = 0i64;
  v1->mDirectionCos = 1.0;
  v1->mAngleRange = 1.5707964;
  v1->mUseTargetDirection = 0;
  v1->mBoneName = UFG::gNullQSymbolUC;
}

// File Line: 1765
// RVA: 0x285900
bool __fastcall MotionIntentionDirectionRelTarget::Match(MotionIntentionDirectionRelTarget *this, ActionContext *pContext)
{
  UFG::SimComponent *rbx1; // rbx
  MotionIntentionDirectionRelTarget *v3; // rsi
  UFG::SimObjectCVBase *v4; // rcx
  ActionContext *v5; // rbp
  UFG::TransformNodeComponent *v6; // r14
  UFG::AICharacterControllerBaseComponent *v7; // rdi
  unsigned __int16 v8; // dx
  UFG::AICharacterControllerBaseComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::TransformNodeComponent *v14; // rbx
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm0
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  Creature *v20; // rbx
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-78h]
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-68h]

  rbx1 = 0i64;
  v3 = this;
  v4 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  v5 = pContext;
  v6 = 0i64;
  if ( v4 )
    v6 = v4->m_pTransformNodeComponent;
  if ( v4 )
  {
    v8 = v4->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v4->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v4->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v4->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
    }
    v7 = v9;
  }
  else
  {
    v7 = 0i64;
  }
  v10 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      rbx1 = v10->m_Components.p[20].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v11 >> 12) & 1 )
      {
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v12 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v10->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      rbx1 = v12;
    }
    else
    {
      rbx1 = v10->m_Components.p[20].m_pComponent;
    }
  }
  if ( !v6 || !v7 || !rbx1 )
    return 0;
  v13 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)v3->mTargetType.mValue
                                                    + *(_QWORD *)&rbx1[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&rbx1[1].m_TypeUID
                               + 40);
  if ( v3->mBoneName.mUID != UFG::gNullQSymbolUC.mUID )
  {
    if ( v13 )
    {
      v18 = v13->m_Flags;
      if ( (v18 >> 14) & 1 )
      {
        v19 = v13->m_Components.p[9].m_pComponent;
      }
      else if ( (v18 & 0x8000u) == 0 )
      {
        if ( (v18 >> 13) & 1 )
          v19 = v13->m_Components.p[8].m_pComponent;
        else
          v19 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::BaseAnimationComponent::_TypeUID);
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
            v21 = Skeleton::GetBoneID(v20->mPose.mRigHandle.mUFGSkeleton, v3->mBoneName.mUID);
          else
            v21 = -1;
          Creature::GetTransform(v20, v21, &transform);
        }
        goto LABEL_49;
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
LABEL_49:
  if ( v3->mUseTargetDirection )
  {
    v2.x = transform.v0.x;
    v22 = transform.v0.z;
    v2.y = transform.v0.y;
  }
  else
  {
    v23 = v3->mDirectionCos;
    v24 = v3->mDirectionSin;
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    v25 = transform.v3.y - v6->mWorldTransform.v3.y;
    v26 = (float)(transform.v3.x - v6->mWorldTransform.v3.x) * v24;
    v2.x = (float)(v25 * v24) + (float)((float)(transform.v3.x - v6->mWorldTransform.v3.x) * v23);
    v2.y = (float)(v25 * v23) - v26;
    v22 = 0.0;
  }
  v2.z = v22;
  return UFG::qAngleBetween(&v7->m_Intention.mMotionIntentionDirection, &v2) <= v3->mAngleRange;
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
  AimIntentionRangeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AimIntentionRangeCondition::`vftable;
  v1->m_fDirection = 0.0;
  v1->m_fAngleRange = 1.5707964;
}

// File Line: 1875
// RVA: 0x27E700
bool __fastcall AimIntentionRangeCondition::Match(AimIntentionRangeCondition *this, ActionContext *pContext)
{
  AimIntentionRangeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AimingBaseComponent *v5; // rax
  float v6; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::AimingBaseComponent *)v3->m_Components.p[47].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
    else
      v5 = (UFG::AimingBaseComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v3,
                                                           UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                   (UFG::SimObject *)&v3->vfptr,
                                                                                                   UFG::AimingBaseComponent::_TypeUID));
  }
  else
  {
    v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
  }
  if ( !v5 )
    return 0;
  LODWORD(v6) = COERCE_UNSIGNED_INT(UFG::AimingBaseComponent::GetLocalAimDirectionXY(v5) - v2->m_fDirection) & _xmm;
  if ( v6 >= 3.1415927 )
    v6 = 6.2831855 - v6;
  return v6 <= v2->m_fAngleRange;
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
  AimIntentionAngleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AimIntentionAngleCondition::`vftable;
  v1->m_fDirection = 0.0;
  v1->m_InEqualityOperator.mValue = 3;
}

// File Line: 1929
// RVA: 0x27E650
char __fastcall AimIntentionAngleCondition::Match(AimIntentionAngleCondition *this, ActionContext *pContext)
{
  AimIntentionAngleCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AimingBaseComponent *v5; // rax
  float v6; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::AimingBaseComponent *)v3->m_Components.p[47].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
    else
      v5 = (UFG::AimingBaseComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v3,
                                                           UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                   (UFG::SimObject *)&v3->vfptr,
                                                                                                   UFG::AimingBaseComponent::_TypeUID));
  }
  else
  {
    v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID);
  }
  if ( !v5 )
    return 0;
  v6 = UFG::AimingBaseComponent::GetLocalAimDirectionXY(v5);
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v2->m_InEqualityOperator.mValue, v2->m_fDirection, v6);
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
  AimIntentionSpeedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AimIntentionSpeedCondition::`vftable;
  v1->m_fSpeed = 0.0;
  v1->m_InEqualityOperator.mValue = 3;
}

// File Line: 1983
// RVA: 0x27E7D0
char __fastcall AimIntentionSpeedCondition::Match(AimIntentionSpeedCondition *this, ActionContext *pContext)
{
  AimIntentionSpeedCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::TargetingSystemPedPlayerComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemPedPlayerComponent::_TypeUID)) : (v5 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::TargetingSystemPedPlayerComponent::_TypeUID))) : (v5 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::TargetingSystemPedPlayerComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v3)),
        v5) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->m_InEqualityOperator.mValue,
               v2->m_fSpeed,
               v5->m_fAimInputLength);
  }
  else
  {
    result = 0;
  }
  return result;
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
  MotionVelocityMagnitude *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionVelocityMagnitude::`vftable;
  v1->mSpeed = 0.0;
  v1->mInEqualityOperator.mValue = 3;
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
  MotionAngularVelocityMagnitude *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionAngularVelocityMagnitude::`vftable;
  v1->mSpeed = 0.0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 2068
// RVA: 0x285340
char __fastcall MotionAngularVelocityMagnitude::Match(MotionAngularVelocityMagnitude *this, ActionContext *context)
{
  MotionAngularVelocityMagnitude *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID)) : (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3)),
        v5) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mSpeed,
               v5->m_Intention.mCurrentRotationAngularVel);
  }
  else
  {
    result = 0;
  }
  return result;
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
  MotionRotationSignal *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MotionRotationSignal::`vftable;
  v1->mSpeed = 0.0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 2111
// RVA: 0x285D80
char __fastcall MotionRotationSignal::Match(MotionRotationSignal *this, ActionContext *context)
{
  MotionRotationSignal *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  float v6; // xmm2_4

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v3->vfptr,
                                                        UFG::AICharacterControllerBaseComponent::_TypeUID);
    else
      v5 = (UFG::AICharacterControllerBaseComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                                          UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
  }
  else
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
  }
  if ( !v5 )
    return 0;
  v6 = v5->m_Intention.mCurrentRotationSignal;
  if ( v6 < 0.0 )
    v6 = v6 + 6.2831855;
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mSpeed, v6);
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
  HealthCondition *v1; // rdi

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HealthCondition::`vftable;
  v1->mHealth.text.mOffset = 1i64;
  BinString::Set(&v1->mHealth.text, &customWorldMapCaption);
  v1->mHealth.expression.mOffset = 0i64;
  v1->mHealth.value = 0;
  v1->mInEqualityOperator.mValue = 3;
  v1->mUsePercentage = 0;
}

// File Line: 2160
// RVA: 0x282020
bool __fastcall HealthCondition::Match(HealthCondition *this, ActionContext *context)
{
  HealthCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  float v7; // xmm6_4
  int v8; // eax
  bool result; // al
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v13; // rcx
  float v14; // xmm6_4
  int v15; // eax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3
    && ((v5 = v3->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HealthComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID))) : (v6 = v3->m_Components.p[6].m_pComponent)) : (v6 = v3->m_Components.p[6].m_pComponent),
        v6) )
  {
    if ( v2->mUsePercentage )
      v7 = (float)(*((float *)&v6[1].m_SafePointerList.mNode.mNext + 1) / *(float *)&v6[1].m_NameUID) * 100.0;
    else
      v7 = (float)(signed int)*((float *)&v6[1].m_SafePointerList.mNode.mNext + 1);
    v8 = ExpressionParameterInt::operator long(&v2->mHealth);
    result = CompareInt((UFG::InEqualityOperator)v2->mInEqualityOperator.mValue, v8, (signed int)v7);
  }
  else
  {
    v10 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( v10
      && ((v11 = v10->m_Flags, !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::RigidBodyComponent::_TypeUID)) : (v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID))) : (v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID))) : (v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID))) : (v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::RigidBodyComponent::_TypeUID)),
          v12) )
    {
      v13 = v12[6].vfptr;
      if ( v13 )
        v14 = *((float *)&v13[33].__vecDelDtor + 1);
      else
        v14 = *(float *)&FLOAT_1_0;
      v15 = ExpressionParameterInt::operator long(&v2->mHealth);
      result = CompareInt(
                 (UFG::InEqualityOperator)v2->mInEqualityOperator.mValue,
                 v15,
                 (signed int)(float)(v14 * 100.0));
    }
    else
    {
      result = 0;
    }
  }
  return result;
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
  HealthClampedToMinimumCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HealthClampedToMinimumCondition::`vftable;
}

// File Line: 2221
// RVA: 0x281F90
bool __fastcall HealthClampedToMinimumCondition::Match(HealthClampedToMinimumCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HealthComponent::_TypeUID))) : (v4 = v2->m_Components.p[6].m_pComponent)) : (v4 = v2->m_Components.p[6].m_pComponent),
        v4) )
  {
    result = BYTE1(v4[1].m_BoundComponentHandles.mNode.mNext);
  }
  else
  {
    result = 0;
  }
  return result;
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
  TargetDistance *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetDistance::`vftable;
  v1->m_eTargetTypeOrigin.mValue = 1;
  *(_QWORD *)&v1->m_eTargetType.mValue = 22i64;
  v1->m_eInEqualityOperator.mValue = 3;
  *(_DWORD *)&v1->m_2DOnly = 0x10000;
  v1->mBoneName = UFG::gNullQSymbolUC;
  v1->mTargetBoneName = UFG::gNullQSymbolUC;
  v1->mDistancePropertyName = UFG::gNullQSymbol;
  v1->m_MyRoot.mOffset = 0i64;
  *(_QWORD *)&v1->m_PropertyValueUID = 0i64;
}

// File Line: 2280
// RVA: 0x294160
void __fastcall TargetDistance::ResolveReferences(TargetDistance *this, ActionNode *action_node)
{
  TargetDistance *v2; // rbx
  Expression::IMemberMap *v3; // rax
  signed __int64 v4; // rcx
  unsigned int v5; // eax
  unsigned int v6; // ecx

  v2 = this;
  v3 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v4 = (signed __int64)&v2->m_MyRoot;
  if ( v3 )
    v3 = (Expression::IMemberMap *)((char *)v3 - v4);
  *(_QWORD *)v4 = v3;
  if ( v2->mDistancePropertyName.mUID != UFG::gNullQSymbol.mUID )
  {
    v5 = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_PropertyValueUID, 0);
    v6 = v2->m_PropertyValueHasBeenReadUID;
    v2->m_PropertyValueUID = v5;
    v2->m_PropertyValueHasBeenReadUID = UFG::ActionTreeComponentBase::MakeValueUID(v6, eACTION_TREE_MEMORY_ELEMENT_BOOL);
  }
}

// File Line: 2325
// RVA: 0x293BE0
float __fastcall TargetDistance::ReadValueFromPropertySet(TargetDistance *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // rax
  signed __int64 v3; // rdi
  ActionContext *v4; // rsi
  TargetDistance *v5; // rbx
  UFG::SceneObjectProperties *v6; // rax
  UFG::qPropertySet *v7; // rcx
  unsigned int v8; // er9
  __int64 v9; // rax
  UFG::ActionTreeComponentBase *v10; // rdx
  signed __int64 v11; // rcx
  UFG::ActionTreeComponentBase *v12; // rcx
  unsigned int v13; // er9
  __int64 v14; // rax
  UFG::ActionTreeComponentBase *v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  float v18; // [rsp+20h] [rbp-8h]
  bool v19; // [rsp+20h] [rbp-8h]
  float value; // [rsp+38h] [rbp+10h]

  v2 = action_context->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = action_context;
  v5 = this;
  if ( v2 && (v6 = v2->m_pSceneObj) != 0i64 )
  {
    v7 = v6->mpWritableProperties;
    if ( v7 )
      goto LABEL_7;
    v7 = v6->mpConstProperties;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v7 )
    return 0.0;
LABEL_7:
  value = 0.0;
  if ( !UFG::TSCharacter::get_attack_param_real(v7, &v5->mDistancePropertyName, &value) )
    return 0.0;
  if ( v5->m_CachePropertyValue )
  {
    v9 = v5->m_MyRoot.mOffset;
    if ( v9 )
      v10 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v9);
    else
      v10 = 0i64;
    if ( v9 )
      v11 = (signed __int64)&v5->m_MyRoot + v9;
    else
      v11 = 0i64;
    v12 = v4->mActionTreeComponentBase[*(char *)(v11 + 236)];
    if ( !v12 )
      v12 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(v12, v10, (ActionNodeRoot *)v5->m_PropertyValueUID, v8, v18);
    v14 = v5->m_MyRoot.mOffset;
    if ( v14 )
      v15 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v14);
    else
      v15 = 0i64;
    if ( v14 )
      v3 = (signed __int64)&v5->m_MyRoot + v14;
    v16 = v4->mActionTreeComponentBase[*(char *)(v3 + 236)];
    if ( !v16 )
      v16 = v4->mActionTreeComponentBase[1];
    LOBYTE(v13) = 1;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v16,
      v15,
      (ActionNodeRoot *)v5->m_PropertyValueHasBeenReadUID,
      v13,
      v19);
  }
  return value;
}

// File Line: 2355
// RVA: 0x28BEF0
char __fastcall TargetDistance::Match(TargetDistance *this, ActionContext *pContext)
{
  TargetDistance *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // r15
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  __int64 v8; // rax
  UFG::SimObjectCVBase *v9; // r9
  UFG::SimObjectCVBase *v10; // rsi
  UFG::TransformNodeComponent *v11; // rbx
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  signed __int64 v15; // r14
  unsigned __int16 v16; // cx
  UFG::RigidBody *v17; // rax
  unsigned __int16 v18; // cx
  UFG::CharacterAnimationComponent *v19; // rax
  Creature *v20; // rbx
  int v21; // eax
  UFG::qVector4 v23; // xmm2
  UFG::qVector3 *v24; // rax
  float v25; // xmm4_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  unsigned __int16 v28; // cx
  UFG::CharacterAnimationComponent *v29; // rax
  Creature *v30; // rbx
  int v31; // eax
  char v32; // al
  float v33; // xmm0_4
  float v34; // xmm6_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  __int64 v37; // rax
  UFG::ActionTreeComponentBase *v38; // rdx
  signed __int64 v39; // rcx
  UFG::ActionTreeComponentBase *v40; // rcx
  __int64 v41; // rax
  UFG::ActionTreeComponentBase *v42; // rdx
  UFG::ActionTreeComponentBase *v43; // rcx
  UFG::qMatrix44 matSimObject; // [rsp+20h] [rbp-69h]
  UFG::qMatrix44 transform; // [rsp+60h] [rbp-29h]
  UFG::qVector3 result; // [rsp+A0h] [rbp+17h]
  unsigned int value_uid; // [rsp+F8h] [rbp+6Fh]
  unsigned int v48; // [rsp+100h] [rbp+77h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = v2->m_eTargetTypeOrigin.mValue;
  v9 = (UFG::SimObjectCVBase *)((_DWORD)v8 == 1 ? v4->mSimObject.m_pPointer : *(_QWORD *)(56i64
                                                                                        * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + v8 + 8)
                                                                                        + *(_QWORD *)&v6[1].m_TypeUID
                                                                                        + 40));
  v10 = *(UFG::SimObjectCVBase **)(56i64
                                 * *(unsigned __int8 *)(v2->m_eTargetType.mValue + *(_QWORD *)&v6[1].m_Flags + 8i64)
                                 + *(_QWORD *)&v6[1].m_TypeUID
                                 + 40);
  if ( !v9 || !v10 )
    return 0;
  if ( v2->mBoneName.mUID == UFG::gNullQSymbolUC.mUID )
  {
    v11 = v9->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
    v12 = v11->mWorldTransform.v2;
    v13 = v11->mWorldTransform.v3;
    v14 = v11->mWorldTransform.v0;
    transform.v1 = v11->mWorldTransform.v1;
    transform.v2 = v12;
    transform.v0 = v14;
    transform.v3 = v13;
  }
  else
  {
    v18 = v9->m_Flags;
    if ( (v18 >> 14) & 1 )
    {
      v19 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    else if ( (v18 & 0x8000u) == 0 )
    {
      if ( (v18 >> 13) & 1 )
      {
        v19 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
      }
      else if ( (v18 >> 12) & 1 )
      {
        v19 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v9->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v19 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v9->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v19 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    v20 = v19->mCreature;
    if ( v20 )
    {
      if ( !v20->mPose.mRigHandle.mData )
        return 0;
      v21 = Skeleton::GetBoneID(v20->mPose.mRigHandle.mUFGSkeleton, v2->mBoneName.mUID);
      if ( v21 < 0 )
        return 0;
      Creature::GetTransform(v20, v21, &transform);
    }
  }
  v15 = 0i64;
  if ( v2->m_UseCentreOfMass
    && ((v16 = v10->m_Flags, !((v16 >> 14) & 1)) ? ((v16 & 0x8000u) == 0 ? (!((v16 >> 13) & 1) ? (!((v16 >> 12) & 1) ? (v17 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::RigidBodyComponent::_TypeUID)) : (v17 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v10->vfptr, UFG::RigidBodyComponent::_TypeUID))) : (v17 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v10->vfptr, UFG::RigidBodyComponent::_TypeUID))) : (v17 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v10->vfptr, UFG::RigidBodyComponent::_TypeUID))) : (v17 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v10->vfptr, UFG::RigidBodyComponent::_TypeUID)),
        v17) )
  {
    v23 = 0i64;
    v23.x = (float)1;
    matSimObject.v0 = v23;
    matSimObject.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 21);
    matSimObject.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 81);
    matSimObject.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 69);
    v24 = UFG::RigidBody::GetCentreOfMass(v17, &result);
    v25 = v24->y;
    v26 = v24->z;
    v27 = v24->x;
    matSimObject.v3.x = v24->x;
    matSimObject.v3.y = v25;
    matSimObject.v3.z = v26;
    LODWORD(matSimObject.v3.w) = (_DWORD)FLOAT_1_0;
  }
  else
  {
    if ( v2->mTargetBoneName.mUID == UFG::gNullQSymbolUC.mUID )
    {
      UFG::TargetingSystemBaseComponent::FindMatrix((UFG::SimObject *)&v10->vfptr, &matSimObject);
    }
    else
    {
      v28 = v10->m_Flags;
      if ( (v28 >> 14) & 1 )
      {
        v29 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
      }
      else if ( (v28 & 0x8000u) == 0 )
      {
        if ( (v28 >> 13) & 1 )
        {
          v29 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
        }
        else if ( (v28 >> 12) & 1 )
        {
          v29 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v10->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v29 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v10->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v29 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
      }
      if ( v29 )
        v30 = v29->mCreature;
      else
        v30 = 0i64;
      if ( v30 && v30->mPose.mRigHandle.mData )
        v31 = Skeleton::GetBoneID(v30->mPose.mRigHandle.mUFGSkeleton, v2->mTargetBoneName.mUID);
      else
        v31 = -1;
      if ( v31 < 0 )
        return 0;
      Creature::GetTransform(v30, v31, &matSimObject);
    }
    v27 = matSimObject.v3.x;
    v25 = matSimObject.v3.y;
    v26 = matSimObject.v3.z;
  }
  v32 = v2->m_2DOnly;
  if ( v32 && v2->m_ZOnly )
    return 0;
  if ( v32 )
  {
    v33 = transform.v3.x - v27;
    v34 = (float)(transform.v3.y - v25) * (float)(transform.v3.y - v25);
LABEL_74:
    v35 = v34 + (float)(v33 * v33);
    goto LABEL_75;
  }
  if ( !v2->m_ZOnly )
  {
    v33 = transform.v3.z - v26;
    v34 = (float)((float)(transform.v3.y - v25) * (float)(transform.v3.y - v25))
        + (float)((float)(transform.v3.x - v27) * (float)(transform.v3.x - v27));
    goto LABEL_74;
  }
  v35 = COERCE_FLOAT(COERCE_UNSIGNED_INT(transform.v3.z - v26) & _xmm)
      * COERCE_FLOAT(COERCE_UNSIGNED_INT(transform.v3.z - v26) & _xmm);
LABEL_75:
  v36 = v2->m_fDistance;
  v48 = LODWORD(v2->m_fDistance);
  if ( v2->mDistancePropertyName.mUID != UFG::gNullQSymbol.mUID )
  {
    v37 = v2->m_MyRoot.mOffset;
    LOBYTE(value_uid) = 0;
    if ( v37 )
      v38 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v37);
    else
      v38 = 0i64;
    if ( v37 )
      v39 = (signed __int64)&v2->m_MyRoot + v37;
    else
      v39 = 0i64;
    v40 = v4->mActionTreeComponentBase[*(char *)(v39 + 236)];
    if ( !v40 )
      v40 = v4->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
      v40,
      v38,
      (ActionNodeRoot *)v2->m_PropertyValueHasBeenReadUID,
      (unsigned __int64)&value_uid,
      *(bool **)&matSimObject.v0.x);
    if ( (_BYTE)value_uid && v2->m_CachePropertyValue )
    {
      v41 = v2->m_MyRoot.mOffset;
      if ( v41 )
        v42 = (UFG::ActionTreeComponentBase *)((char *)&v2->m_MyRoot + v41);
      else
        v42 = 0i64;
      if ( v41 )
        v15 = (signed __int64)&v2->m_MyRoot + v41;
      v43 = v4->mActionTreeComponentBase[*(char *)(v15 + 236)];
      if ( !v43 )
        v43 = v4->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
        v43,
        v42,
        (ActionNodeRoot *)v2->m_PropertyValueUID,
        (unsigned __int64)&v48,
        *(float **)&matSimObject.v0.x);
      v36 = *(float *)&v48;
    }
    else
    {
      v36 = TargetDistance::ReadValueFromPropertySet(v2, v4);
      v48 = LODWORD(v36);
    }
  }
  return CompareFloat((UFG::InEqualityOperator)v2->m_eInEqualityOperator.mValue, v36 * v36, v35);
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
  TargetCloserThanTargetCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetCloserThanTargetCondition::`vftable;
  *(_QWORD *)&v1->m_eTargetTypeA.mValue = 0i64;
  *(_WORD *)&v1->m_OrEqual = 1;
  v1->m_ZOnly = 0;
}

// File Line: 2562
// RVA: 0x28B9F0
bool __fastcall TargetCloserThanTargetCondition::Match(TargetCloserThanTargetCondition *this, ActionContext *pContext)
{
  TargetCloserThanTargetCondition *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // r8
  UFG::TransformNodeComponent *v9; // rbx
  __int64 v10; // rsi
  __int64 v11; // rax
  bool result; // al
  UFG::TransformNodeComponent *v13; // rsi
  UFG::SimObject *v14; // rdi
  UFG::TransformNodeComponent *v15; // rdi
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm2_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v7 = *(_QWORD *)&v6[1].m_Flags;
  v8 = *(_QWORD *)&v6[1].m_TypeUID;
  v9 = 0i64;
  v10 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(v2->m_eTargetTypeA.mValue + v7 + 8) + v8 + 40);
  v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(v2->m_eTargetTypeB.mValue + v7 + 8) + v8 + 40);
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
  v14 = v4->mSimObject.m_pPointer;
  if ( !v14 )
    return 0;
  v15 = v14->m_pTransformNodeComponent;
  if ( !v15 || !v13 || !v9 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v15);
  if ( v2->m_2DOnly )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v13);
    v16 = (float)((float)(v15->mWorldTransform.v3.y - v13->mWorldTransform.v3.y)
                * (float)(v15->mWorldTransform.v3.y - v13->mWorldTransform.v3.y))
        + (float)((float)(v15->mWorldTransform.v3.x - v13->mWorldTransform.v3.x)
                * (float)(v15->mWorldTransform.v3.x - v13->mWorldTransform.v3.x));
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    v17 = v15->mWorldTransform.v3.x - v9->mWorldTransform.v3.x;
    v18 = (float)(v15->mWorldTransform.v3.y - v9->mWorldTransform.v3.y)
        * (float)(v15->mWorldTransform.v3.y - v9->mWorldTransform.v3.y);
  }
  else
  {
    if ( v2->m_ZOnly )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v13);
      LODWORD(v16) = COERCE_UNSIGNED_INT(v15->mWorldTransform.v3.z - v13->mWorldTransform.v3.z) & _xmm;
      UFG::TransformNodeComponent::UpdateWorldTransform(v9);
      LODWORD(v19) = COERCE_UNSIGNED_INT(v15->mWorldTransform.v3.z - v9->mWorldTransform.v3.z) & _xmm;
      goto LABEL_29;
    }
    UFG::TransformNodeComponent::UpdateWorldTransform(v13);
    v16 = (float)((float)((float)(v15->mWorldTransform.v3.y - v13->mWorldTransform.v3.y)
                        * (float)(v15->mWorldTransform.v3.y - v13->mWorldTransform.v3.y))
                + (float)((float)(v15->mWorldTransform.v3.x - v13->mWorldTransform.v3.x)
                        * (float)(v15->mWorldTransform.v3.x - v13->mWorldTransform.v3.x)))
        + (float)((float)(v15->mWorldTransform.v3.z - v13->mWorldTransform.v3.z)
                * (float)(v15->mWorldTransform.v3.z - v13->mWorldTransform.v3.z));
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    v17 = v15->mWorldTransform.v3.z - v9->mWorldTransform.v3.z;
    v18 = (float)((float)(v15->mWorldTransform.v3.y - v9->mWorldTransform.v3.y)
                * (float)(v15->mWorldTransform.v3.y - v9->mWorldTransform.v3.y))
        + (float)((float)(v15->mWorldTransform.v3.x - v9->mWorldTransform.v3.x)
                * (float)(v15->mWorldTransform.v3.x - v9->mWorldTransform.v3.x));
  }
  v19 = v18 + (float)(v17 * v17);
LABEL_29:
  if ( v2->m_OrEqual )
    result = v19 >= v16;
  else
    result = v19 > v16;
  return result;
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
  GroundDistance *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&GroundDistance::`vftable;
  v1->mDistance = 1.0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 2645
// RVA: 0x281DE0
char __fastcall GroundDistance::Match(GroundDistance *this, ActionContext *context)
{
  GroundDistance *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v5 = v3->m_Components.p[27].m_pComponent),
        v5) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)v2->mInEqualityOperator.mValue,
               v2->mDistance,
               *(float *)&v5[5].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    result = 0;
  }
  return result;
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
  SpeedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SpeedCondition::`vftable;
  v1->m_fSpeed = 0.0;
  v1->m_InEqualityOperator.mValue = 3;
}

// File Line: 2682
// RVA: 0x28A850
char __fastcall SpeedCondition::Match(SpeedCondition *this, ActionContext *pContext)
{
  SpeedCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::CharacterPhysicsComponent *v6; // rax
  __m128 v7; // xmm2
  float v8; // xmm0_4
  float v9; // xmm1_4
  UFG::SimObjectGame *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::RigidBody *v13; // rax
  UFG::SimObject *v14; // rax
  UFG::TransformNodeComponent *v15; // rbx
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::CharacterPhysicsComponent *)v3->m_Components.p[27].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v3,
                                                 UFG::CharacterPhysicsComponent::_TypeUID);
      else
        v6 = (UFG::CharacterPhysicsComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v3,
                                                                   UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID));
    }
    else
    {
      v6 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v3,
                                               UFG::CharacterPhysicsComponent::_TypeUID);
    }
    if ( v6 )
    {
      UFG::CharacterPhysicsComponent::GetVelocity(v6, &result);
LABEL_13:
      v7 = (__m128)LODWORD(result.x);
      v8 = result.y;
      v9 = result.z;
LABEL_14:
      v7.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8)) + (float)(v9 * v9);
      return CompareFloat(
               (UFG::InEqualityOperator)v2->m_InEqualityOperator.mValue,
               v2->m_fSpeed,
               COERCE_FLOAT(_mm_sqrt_ps(v7)));
    }
  }
  v11 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v11 )
  {
    v12 = v11->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
        v13 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RigidBodyComponent::_TypeUID);
      else
        v13 = (UFG::RigidBody *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v11,
                                                     UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                            (UFG::SimObject *)&v11->vfptr,
                                                                                            UFG::RigidBodyComponent::_TypeUID));
    }
    else
    {
      v13 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RigidBodyComponent::_TypeUID);
    }
    if ( v13 )
    {
      UFG::RigidBody::GetVelocity(v13, &result);
      goto LABEL_13;
    }
  }
  v14 = v4->mSimObject.m_pPointer;
  if ( v14 )
  {
    v15 = v14->m_pTransformNodeComponent;
    if ( v15 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v14->m_pTransformNodeComponent);
      v8 = v15->mWorldVelocity.x;
      v7 = (__m128)LODWORD(v15->mWorldVelocity.y);
      v9 = v15->mWorldVelocity.z;
      goto LABEL_14;
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
  TargetPhysicalMassCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalMassCondition::`vftable;
  *(_QWORD *)&v1->m_eTargetType.mValue = 49i64;
  v1->m_eInEqualityOperator.mValue = 3;
}

// File Line: 2749
// RVA: 0x28E1E0
char __usercall TargetPhysicalMassCondition::Match@<al>(TargetPhysicalMassCondition *this@<rcx>, ActionContext *pContext@<rdx>, float a3@<xmm0>)
{
  TargetPhysicalMassCondition *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::RigidBody *v10; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v4->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(v3->m_eTargetType.mValue + *(_QWORD *)&v6[1].m_Flags + 8i64)
                              + *(_QWORD *)&v6[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
    else
      v10 = (UFG::RigidBody *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v8,
                                                  UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v8->vfptr,
                                                                                         UFG::RigidBodyComponent::_TypeUID));
  }
  else
  {
    v10 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
  }
  if ( !v10 )
    return 0;
  UFG::RigidBody::GetMass(v10);
  return CompareFloat((UFG::InEqualityOperator)v3->m_eInEqualityOperator.mValue, v3->m_fMass, a3);
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
void __fastcall TargetPhysicalCollisionLayerCondition::TargetPhysicalCollisionLayerCondition(TargetPhysicalCollisionLayerCondition *this)
{
  TargetPhysicalCollisionLayerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalCollisionLayerCondition::`vftable;
  v1->m_eTargetType.mValue = 49;
  v1->m_eCollisionLayer.mValue = 19;
}

// File Line: 2798
// RVA: 0x28DD30
bool __fastcall TargetPhysicalCollisionLayerCondition::Match(TargetPhysicalCollisionLayerCondition *this, ActionContext *pContext)
{
  TargetPhysicalCollisionLayerCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::RigidBody *v9; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(UFG::SimObjectGame **)(56i64
                                     * *(unsigned __int8 *)(v2->m_eTargetType.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                     + *(_QWORD *)&v5[1].m_TypeUID
                                     + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID)) : (v9 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID))) : (v9 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID))) : (v9 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID))) : (v9 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID)),
         v9)) )
  {
    result = (unsigned int)UFG::RigidBody::GetCollisionLayer(v9) == v2->m_eCollisionLayer.mValue;
  }
  else
  {
    result = 0;
  }
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
void __fastcall TargetPhysicalAttackShootComboCondition::TargetPhysicalAttackShootComboCondition(TargetPhysicalAttackShootComboCondition *this)
{
  TargetPhysicalAttackShootComboCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalAttackShootComboCondition::`vftable;
  v1->m_eTargetType.mValue = 49;
}

// File Line: 2844
// RVA: 0x28D9E0
char __fastcall TargetPhysicalAttackShootComboCondition::Match(TargetPhysicalAttackShootComboCondition *this, ActionContext *pContext)
{
  TargetPhysicalAttackShootComboCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  __int64 v13; // rdx
  char v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + v2->m_eTargetType.mValue + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
          else
            v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        }
        v10 = v9;
        if ( v9 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v16);
          v12 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
          v16.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
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
void __fastcall TargetPhysicalAttackVelocityCondition::TargetPhysicalAttackVelocityCondition(TargetPhysicalAttackVelocityCondition *this)
{
  TargetPhysicalAttackVelocityCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalAttackVelocityCondition::`vftable;
  v1->m_eTargetType.mValue = 49;
  *(_QWORD *)&v1->m_eInEqualityOperator.mValue = 3i64;
}

// File Line: 2895
// RVA: 0x28DB80
char __fastcall TargetPhysicalAttackVelocityCondition::Match(TargetPhysicalAttackVelocityCondition *this, ActionContext *pContext)
{
  TargetPhysicalAttackVelocityCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  __int64 v13; // rdx
  char v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + v2->m_eTargetType.mValue + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
          else
            v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        }
        v10 = v9;
        if ( v9 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v16);
          v12 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
          v16.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
          v13 = *(_QWORD *)&v10[2].m_Flags;
          if ( v13 )
            UFG::qReflectHandleBase::operator=(&v16, (UFG::qReflectHandleBase *)(v13 + 224));
          if ( v16.mData )
          {
            v14 = CompareFloat(
                    (UFG::InEqualityOperator)v2->m_eInEqualityOperator.mValue,
                    v2->m_fAttackVelocity,
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
void __fastcall TargetPhysicalDamageMultiplierCondition::TargetPhysicalDamageMultiplierCondition(TargetPhysicalDamageMultiplierCondition *this)
{
  TargetPhysicalDamageMultiplierCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalDamageMultiplierCondition::`vftable;
  *(_QWORD *)&v1->m_eTargetType.mValue = 49i64;
  *(_QWORD *)&v1->m_eInEqualityOperator.mValue = 3i64;
}

// File Line: 2953
// RVA: 0x28DE70
char __fastcall TargetPhysicalDamageMultiplierCondition::Match(TargetPhysicalDamageMultiplierCondition *this, ActionContext *pContext)
{
  TargetPhysicalDamageMultiplierCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::RigidBodyComponent *v10; // rbx
  const char *v11; // rax
  float v12; // xmm2_4
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  char v16; // bl
  UFG::qReflectHandleBase v18; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + v2->m_eTargetType.mValue + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
    else
      v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
  }
  else
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  }
  v10 = (UFG::RigidBodyComponent *)v9;
  if ( !v9 )
    return 0;
  UFG::qReflectHandleBase::qReflectHandleBase(&v18);
  v11 = UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::GetStaticTypeName();
  v18.mTypeUID = UFG::qStringHash64(v11, 0xFFFFFFFFFFFFFFFFui64);
  UFG::RigidBodyComponent::GetStateMachineDefinition(v10, (UFG::qReflectHandle<UFG::StateMachineDefinition> *)&v18);
  if ( !v18.mData )
  {
    UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
    return 0;
  }
  v12 = FLOAT_100_0;
  v13 = v2->m_iDamageType;
  if ( v13 )
  {
    v14 = v13 - 1;
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
  v16 = CompareFloat((UFG::InEqualityOperator)v2->m_eInEqualityOperator.mValue, v2->m_fDamageMultiplier, v12);
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
void __fastcall TargetPhysicalDodgeableCondition::TargetPhysicalDodgeableCondition(TargetPhysicalDodgeableCondition *this)
{
  TargetPhysicalDodgeableCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalDodgeableCondition::`vftable;
  v1->m_eTargetType.mValue = 49;
}

// File Line: 3027
// RVA: 0x28E040
bool __fastcall TargetPhysicalDodgeableCondition::Match(TargetPhysicalDodgeableCondition *this, ActionContext *pContext)
{
  TargetPhysicalDodgeableCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  __int64 v13; // rdx
  bool v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + v2->m_eTargetType.mValue + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
    else
      v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
  }
  else
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  }
  v10 = v9;
  if ( !v9 )
    return 0;
  UFG::qReflectHandleBase::qReflectHandleBase(&v16);
  v12 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
  v16.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
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
void __fastcall TargetPhysicalMeleeAttackableCondition::TargetPhysicalMeleeAttackableCondition(TargetPhysicalMeleeAttackableCondition *this)
{
  TargetPhysicalMeleeAttackableCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPhysicalMeleeAttackableCondition::`vftable;
  v1->m_eTargetType.mValue = 49;
}

// File Line: 3071
// RVA: 0x28E320
bool __fastcall TargetPhysicalMeleeAttackableCondition::Match(TargetPhysicalMeleeAttackableCondition *this, ActionContext *pContext)
{
  TargetPhysicalMeleeAttackableCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  __int64 v13; // rdx
  bool v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + v2->m_eTargetType.mValue + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
    else
      v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
  }
  else
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
  }
  v10 = v9;
  if ( !v9 )
    return 0;
  UFG::qReflectHandleBase::qReflectHandleBase(&v16);
  v12 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v11);
  v16.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
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
  VehicleSpeedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleSpeedCondition::`vftable;
  v1->mSpeed = 0.0;
  *(_WORD *)&v1->mInEqualityOperator.mValue = 259;
}

// File Line: 3121
// RVA: 0x292C20
char __fastcall VehicleSpeedCondition::Match(VehicleSpeedCondition *this, ActionContext *context)
{
  VehicleSpeedCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rax
  float v6; // xmm6_4
  float v7; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
    return 0;
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      return 0;
    if ( (v4 >> 12) & 1 )
      v5 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::PhysicsMoverInterface::_TypeUID);
    else
      v5 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = v2->mSpeed;
  if ( v2->mTestForwardSpeed )
    v7 = 3.5999999 * v5->mForwardSpeed;
  else
    v7 = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v5);
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v6, v7);
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
void __fastcall VehicleCollisionShouldTriggerExplosion::VehicleCollisionShouldTriggerExplosion(VehicleCollisionShouldTriggerExplosion *this)
{
  VehicleCollisionShouldTriggerExplosion *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleCollisionShouldTriggerExplosion::`vftable;
}

// File Line: 3161
// RVA: 0x291840
bool __fastcall VehicleCollisionShouldTriggerExplosion::Match(VehicleCollisionShouldTriggerExplosion *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    return 0;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      return 0;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( v4 )
    return (BYTE4(v4[14].vfptr) >> 4) & 1;
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
  VehicleIsRammingCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleIsRammingCondition::`vftable;
}

// File Line: 3193
// RVA: 0x2924E0
bool __fastcall VehicleIsRammingCondition::Match(VehicleIsRammingCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    return 0;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      return 0;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( v4 )
    return (BYTE4(v4[14].vfptr) >> 3) & 1;
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
  VehicleTrunkTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleTrunkTypeCondition::`vftable;
  v1->mType.mValue = 0;
}

// File Line: 3222
// RVA: 0x292CE0
bool __fastcall VehicleTrunkTypeCondition::Match(VehicleTrunkTypeCondition *this, ActionContext *context)
{
  VehicleTrunkTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rdx
  UFG::PhysicsMoverInterface *v6; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
    return 0;
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      return 0;
    if ( (v4 >> 12) & 1 )
      v6 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::PhysicsMoverInterface::_TypeUID);
    else
      v6 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::PhysicsMoverInterface::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
  }
  if ( v5 )
    return v5->mTrunkType == (unsigned __int8)v2->mType.mValue;
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
  VehicleIsWreckedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleIsWreckedCondition::`vftable;
}

// File Line: 3252
// RVA: 0x292560
bool __fastcall VehicleIsWreckedCondition::Match(VehicleIsWreckedCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    return 0;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      return 0;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( v4 )
    return (unsigned int)(HIDWORD(v4[2].m_BoundComponentHandles.mNode.mPrev) - 1) <= 1;
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
  VehicleAngularSpeedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleAngularSpeedCondition::`vftable;
  v1->mComparison.mValue = 3;
  v1->mSpeed = 0.0;
  v1->mAboutZOnly = 0;
}

// File Line: 3289
// RVA: 0x290DE0
char __fastcall VehicleAngularSpeedCondition::Match(VehicleAngularSpeedCondition *this, ActionContext *context)
{
  VehicleAngularSpeedCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rax
  float v6; // xmm0_4
  __m128 v7; // xmm1
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
    return 0;
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      return 0;
    if ( (v4 >> 12) & 1 )
      v5 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::PhysicsMoverInterface::_TypeUID);
    else
      v5 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
  }
  if ( !v5 )
    return 0;
  UFG::PhysicsMoverInterface::GetAngularVelocity(v5, &result);
  if ( v2->mAboutZOnly )
  {
    v6 = 0.0;
    v7 = 0i64;
    result.x = 0.0;
    result.y = 0.0;
  }
  else
  {
    v7 = (__m128)LODWORD(result.y);
    v6 = result.x;
  }
  v7.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v6 * v6)) + (float)(result.z * result.z);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)v2->mComparison.mValue,
           v2->mSpeed,
           COERCE_FLOAT(_mm_sqrt_ps(v7)));
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
  VehicleVectorCompareCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleVectorCompareCondition::`vftable;
  *(_WORD *)&v1->mVector1.mValue = 1024;
  v1->mAngleRadians = 3.1415927;
  *(_DWORD *)&v1->mCheckMagnitude = 768;
}

// File Line: 3348
// RVA: 0x292DF0
char __fastcall VehicleVectorCompareCondition::Match(VehicleVectorCompareCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  ActionContext *pContext; // rsi
  VehicleVectorCompareCondition *v4; // rbx
  unsigned __int16 v5; // cx
  UFG::PhysicsMoverInterface *v6; // rax
  hkpRigidBody *v7; // rax
  hkpRigidBody *v8; // rdi
  __m128 v9; // xmm6
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
  hkVector4f result; // [rsp+30h] [rbp-58h]

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  pContext = context;
  v4 = this;
  if ( !v2 )
    return 0;
  v5 = v2->m_Flags;
  if ( (v5 >> 14) & 1 )
    return 0;
  if ( (v5 & 0x8000u) == 0 )
  {
    if ( !((v5 >> 13) & 1) )
    {
      if ( (v5 >> 12) & 1 )
        v6 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v2,
                                             UFG::PhysicsMoverInterface::_TypeUID);
      else
        v6 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v2->vfptr,
                                             UFG::PhysicsMoverInterface::_TypeUID);
      goto LABEL_9;
    }
    return 0;
  }
  v6 = (UFG::PhysicsMoverInterface *)v2->m_Components.p[34].m_pComponent;
LABEL_9:
  if ( !v6 )
    return 0;
  v7 = (hkpRigidBody *)UFG::PhysicsMoverInterface::GetRigidBody(v6);
  v8 = v7;
  if ( !v7 )
    return 0;
  VehicleVectorCompareCondition::GetVectorFromType(
    v4,
    &result,
    v7,
    (UFG::eVehicleVectorEnum)(unsigned __int8)v4->mVector1.mValue,
    pContext);
  v9 = result.m_quad;
  if ( v4->mFlattenV1 )
    v9 = _mm_shuffle_ps(result.m_quad, _mm_unpackhi_ps(result.m_quad, (__m128)0i64), 180);
  VehicleVectorCompareCondition::GetVectorFromType(
    v4,
    &result,
    v8,
    (UFG::eVehicleVectorEnum)(unsigned __int8)v4->mVector2.mValue,
    pContext);
  v10 = result.m_quad;
  if ( v4->mFlattenV2 )
    v10 = _mm_shuffle_ps(result.m_quad, _mm_unpackhi_ps(result.m_quad, (__m128)0i64), 180);
  v11 = _mm_mul_ps(v9, v9);
  v12 = _mm_mul_ps(v10, v10);
  v13 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) <= 0.001
    || v13 <= 0.001 )
  {
    return 0;
  }
  if ( v4->mCheckMagnitude )
  {
    v14 = _mm_mul_ps(v10, v9);
    v15 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170));
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
            _mm_mul_ps(v10, _mm_andnot_ps(_mm_cmpleps(v19, (__m128)0i64), _mm_rsqrt_ps(v19))),
            _mm_mul_ps(v9, _mm_andnot_ps(_mm_cmpleps(v18, (__m128)0i64), v17)));
    v21 = _mm_min_ps(
            _mm_max_ps(
              (__m128)COERCE_UNSIGNED_INT(
                        (float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170))),
              *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
            *(__m128 *)_xmm);
    v22 = _mm_andnot_ps(*(__m128 *)_xmm, v21);
    v23 = _mm_cmpltps(v22, *(__m128 *)_xmm);
    v24 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v22), *(__m128 *)_xmm);
    v25 = _mm_cmpltps(*(__m128 *)_xmm, v22);
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
        - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                 v23,
                                                 _mm_or_ps(
                                                   _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v28, v28)), v25),
                                                   _mm_andnot_ps(v25, v28))) | v23.m128_i32[0] & v22.m128_i32[0]) ^ _xmm[0] & v21.m128_i32[0]);
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v4->mComparison.mValue, v4->mAngleRadians, v15);
}

// File Line: 3401
// RVA: 0x27DD10
hkVector4f *__fastcall VehicleVectorCompareCondition::GetVectorFromType(VehicleVectorCompareCondition *this, hkVector4f *result, hkpRigidBody *pRigidBody, UFG::eVehicleVectorEnum eType, ActionContext *pContext)
{
  hkVector4f *v5; // rbx
  hkVector4f *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  unsigned int *v9; // rax
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  __m128 v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm2

  v5 = result;
  switch ( eType )
  {
    case 0:
      v6 = result;
      *result = pRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
      break;
    case 1:
      v6 = result;
      *result = pRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
      break;
    case 2:
      v6 = result;
      *result = pRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
      break;
    case 3:
      v6 = result;
      result->m_quad = _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         pRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
      break;
    case 4:
      v6 = result;
      *result = pRigidBody->m_motion.m_linearVelocity;
      break;
    case 5:
      v6 = result;
      *result = (hkVector4f)stru_141A71280.m_quad;
      break;
    case 6:
      v7 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
      if ( !v7 )
        goto LABEL_32;
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = (unsigned int *)v7->m_Components.p[15].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
          v9 = (unsigned int *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID);
        else
          v9 = (unsigned int *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v7,
                                                   UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                            (UFG::SimObject *)&v7->vfptr,
                                                                                            UFG::HitReactionComponent::_TypeUID));
      }
      else
      {
        v9 = (unsigned int *)v7->m_Components.p[15].m_pComponent;
      }
      if ( !v9 )
        goto LABEL_32;
      v10 = (__m128)v9[100];
      v11 = _mm_unpacklo_ps(
              _mm_xor_ps((__m128)v9[99], (__m128)(unsigned int)_xmm[0]),
              _mm_xor_ps((__m128)v9[101], (__m128)(unsigned int)_xmm[0]));
      v6 = v5;
      v5->m_quad = _mm_unpacklo_ps(v11, _mm_unpacklo_ps(_mm_xor_ps(v10, (__m128)(unsigned int)_xmm[0]), (__m128)0i64));
      break;
    case 7:
      v12 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
      if ( !v12 )
        goto LABEL_32;
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v14 = v12->m_Components.p[15].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::HitReactionComponent::_TypeUID);
        else
          v14 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::HitReactionComponent::_TypeUID);
      }
      else
      {
        v14 = v12->m_Components.p[15].m_pComponent;
      }
      if ( !v14 )
        goto LABEL_32;
      v15 = _mm_xor_ps((__m128)*(unsigned int *)(&v14[6].m_SimObjIndex + 1), *(__m128 *)_xmm);
      v16 = v15;
      v17 = v15;
      v15.m128_f32[0] = v15.m128_f32[0] * *((float *)&v14[6].m_SafePointerList.mNode.mNext + 1);
      v16.m128_f32[0] = v16.m128_f32[0] * *((float *)&v14[6].m_SafePointerList.mNode.mPrev + 1);
      v17.m128_f32[0] = v17.m128_f32[0] * *(float *)&v14[6].m_SafePointerList.mNode.mNext;
      v6 = v5;
      v5->m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v16, v15), _mm_unpacklo_ps(v17, (__m128)0i64));
      break;
    default:
LABEL_32:
      v6 = v5;
      *v5 = 0i64;
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
  VehicleDoorAngleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleDoorAngleCondition::`vftable;
  *(_QWORD *)&v1->mAngle = 0i64;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 3480
// RVA: 0x2921D0
char __fastcall VehicleDoorAngleCondition::Match(VehicleDoorAngleCondition *this, ActionContext *context)
{
  VehicleDoorAngleCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rax
  UFG::PhysicsVehicle *v6; // rcx
  float v7; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
    return 0;
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      return 0;
    if ( (v4 >> 12) & 1 )
      v5 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::PhysicsMoverInterface::_TypeUID);
    else
      v5 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = v5->mPhysicsVehicle;
  v7 = 0.0;
  if ( v6 )
  {
    if ( (*((_DWORD *)v6 + 151) & 7) == 4 )
      v7 = UFG::PhysicsCar::GetAttachmentAngle((UFG::PhysicsCar *)v6, (UFG::VehicleAttachmentID)v2->mDoor);
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mAngle, v7);
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
  return atexit(dynamic_atexit_destructor_for__vehicleWheelSurfaceConditionWheelTypeEnum__);
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
  VehicleWheelSurfaceCondition *v1; // rbx
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h]

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleWheelSurfaceCondition::`vftable;
  *(_QWORD *)&v1->mSurfacePropertyName.mUID = -1i64;
  v1->mWheelType.mValue = 0;
  v1->mSurfacePropertyName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "TerrainType")->mUID;
}

// File Line: 3548
// RVA: 0x293130
bool __fastcall VehicleWheelSurfaceCondition::Match(VehicleWheelSurfaceCondition *this, ActionContext *context)
{
  VehicleWheelSurfaceCondition *v2; // r13
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  signed int v7; // esi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // r14
  int v9; // er15
  int v10; // edi
  int v11; // ebp
  unsigned __int64 v12; // rbx
  bool v13; // r12
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v14; // rcx
  const char *v15; // rax
  unsigned int v16; // ecx
  int v17; // ecx
  UFG::qReflectHandleBase v19; // [rsp+28h] [rbp-50h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
    return 0;
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      return 0;
    if ( (v4 >> 12) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[34].m_pComponent;
  }
  if ( v5 )
  {
    v6 = v5[10].m_SafePointerList.mNode.mPrev;
    if ( v6 )
    {
      v7 = 0;
      v8 = 0i64;
      if ( BYTE4(v6[37].mNext) & 7 )
        v8 = v5[10].m_SafePointerList.mNode.mPrev;
      if ( v8 )
      {
        v9 = HIDWORD(v8[37].mNext) & 7;
        v10 = 0;
        v11 = 0;
        if ( v9 > 0 )
        {
          while ( 1 )
          {
            v12 = UFG::PhysicsWheeledVehicle::GetSurfacePropertyHandleUidUnderWheel(
                    (UFG::PhysicsWheeledVehicle *)v8,
                    v11);
            v13 = UFG::PhysicsWheeledVehicle::IsWheelOnGround((UFG::PhysicsWheeledVehicle *)v8, v11);
            UFG::qReflectHandleBase::qReflectHandleBase(&v19);
            v15 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v14);
            v19.mTypeUID = UFG::qStringHash64(v15, 0xFFFFFFFFFFFFFFFFui64);
            UFG::qReflectHandleBase::Init(&v19, v19.mTypeUID, v12);
            if ( v19.mData )
              break;
            if ( !v13 )
              goto LABEL_19;
LABEL_20:
            UFG::qReflectHandleBase::~qReflectHandleBase(&v19);
            if ( ++v11 >= v9 )
              goto LABEL_21;
          }
          if ( LODWORD(v19.mData[1].mHandles.mNode.mPrev) == v2->mSurfacePropertyValue.mUID )
            ++v7;
LABEL_19:
          ++v10;
          goto LABEL_20;
        }
LABEL_21:
        v16 = v2->mWheelType.mValue;
        if ( !v16 )
          return v7 > 0;
        v17 = v16 - 1;
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
  CharacterSurfaceCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CharacterSurfaceCondition::`vftable;
  v1->mSurfacePropertyValue = UFG::gNullQSymbolUC;
}

// File Line: 3665
// RVA: 0x27FE90
bool __fastcall CharacterSurfaceCondition::Match(CharacterSurfaceCondition *this, ActionContext *context)
{
  CharacterSurfaceCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterPhysicsComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID)) : (v5 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v5 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v5 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v5 = (UFG::CharacterPhysicsComponent *)v3->m_Components.p[27].m_pComponent),
        v5) )
  {
    result = UFG::GetTerrainTypeHash(v5) == v2->mSurfacePropertyValue.mUID;
  }
  else
  {
    result = 0;
  }
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
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    return 0;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      return 0;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( v4 )
  {
    v5 = v4[10].m_SafePointerList.mNode.mPrev;
    if ( v5 )
      return ((__int64 (*)(void))v5->mPrev[6].mNext)();
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
char __fastcall VehicleUntargetableCondition::Match(VehicleUntargetableCondition *this, ActionContext *context)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    return 0;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      return 0;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( v4 && BYTE1(v4[14].m_SafePointerList.mNode.mNext) )
    return 1;
  return 0;
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
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::PhysicsWheeledVehicle *v6; // rcx

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    return 0;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      return 0;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( v4 )
  {
    v5 = v4[10].m_SafePointerList.mNode.mPrev;
    if ( v5 )
    {
      v6 = 0i64;
      if ( BYTE4(v5[37].mNext) & 7 )
        v6 = (UFG::PhysicsWheeledVehicle *)v4[10].m_SafePointerList.mNode.mPrev;
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
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  int v5; // eax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    goto LABEL_11;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    goto LABEL_11;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
    {
LABEL_11:
      LOBYTE(v5) = 0;
      return v5;
    }
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( !v4 )
    goto LABEL_11;
  return (LODWORD(v4[1].m_pSimObject) >> 5) & 1;
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
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  int v5; // ecx

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    return 0;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      return 0;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( !v4 )
    return 0;
  v5 = (int)v4[1].m_pSimObject;
  return v5 & 8 && !_bittest(&v5, 8u);
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
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  int v5; // eax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    goto LABEL_11;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    goto LABEL_11;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
    {
LABEL_11:
      LOBYTE(v5) = 0;
      return v5;
    }
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( !v4 )
    goto LABEL_11;
  return (LODWORD(v4[1].m_pSimObject) >> 4) & 1;
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
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  int v5; // eax

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v2 )
    goto LABEL_11;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    goto LABEL_11;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
    {
LABEL_11:
      LOBYTE(v5) = 0;
      return v5;
    }
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( !v4 )
    goto LABEL_11;
  return (LODWORD(v4[1].m_pSimObject) >> 2) & 1;
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
bool __fastcall VehicleOccupantHasActiveRoleCondition::Match(VehicleOccupantHasActiveRoleCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterOccupantComponent::_TypeUID))) : (v4 = v2->m_Components.p[44].m_pComponent),
        v4) )
  {
    result = LODWORD(v4[1].m_SafePointerList.mNode.mNext) != 13;
  }
  else
  {
    result = 0;
  }
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
bool __fastcall VehicleOccupantIsPassengerCondition::Match(VehicleOccupantIsPassengerCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  unsigned int v5; // ecx
  signed int v6; // eax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[44].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterOccupantComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v4 )
    {
      v5 = (unsigned int)v4[1].m_SafePointerList.mNode.mNext;
      if ( v5 > 0xD || (v6 = 8720, !_bittest(&v6, v5)) )
        result = 1;
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
bool __fastcall VehicleOccupantIsInBoatCondition::Match(VehicleOccupantIsInBoatCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::VehicleOccupantComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CharacterOccupantComponent *)v2->m_Components.p[44].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v2,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v4 = (UFG::CharacterOccupantComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v2,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v2,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v4 )
    {
      v5 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v4);
      if ( v5 )
      {
        v6 = v5->mpDriver.m_pPointer[4].m_SafePointerWithCallbackList.mNode.mNext;
        if ( v6 )
        {
          if ( !LODWORD(v6[51].mNext) )
            result = 1;
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
bool __fastcall VehicleOccupantIsInSinkingBoatCondition::Match(VehicleOccupantIsInSinkingBoatCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::VehicleOccupantComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CharacterOccupantComponent *)v2->m_Components.p[44].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v2,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v4 = (UFG::CharacterOccupantComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v2,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v2,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v4 )
    {
      v5 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v4);
      if ( v5 )
      {
        v6 = v5->mpDriver.m_pPointer[4].m_SafePointerWithCallbackList.mNode.mNext;
        if ( v6 )
        {
          v7 = v6[40].mNext;
          if ( v7 )
          {
            if ( !(BYTE4(v7[37].mNext) & 7) && (_QWORD)v7[38].mPrev[3].mNext & 1 )
              result = 1;
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
  VehicleOccupantTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleOccupantTypeCondition::`vftable;
  v1->m_eTargetType.mValue = 4;
}

// File Line: 4039
// RVA: 0x2929B0
bool __fastcall VehicleOccupantTypeCondition::Match(VehicleOccupantTypeCondition *this, ActionContext *pContext)
{
  VehicleOccupantTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID)),
                                                 v5 = v6) : (v5 = v3->m_Components.p[44].m_pComponent),
        v5) )
  {
    result = LODWORD(v5[1].m_SafePointerList.mNode.mNext) == (unsigned __int8)v2->m_eTargetType.mValue;
  }
  else
  {
    result = 0;
  }
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
void __fastcall IsOccupantOfTargetVehicleCondition::IsOccupantOfTargetVehicleCondition(IsOccupantOfTargetVehicleCondition *this)
{
  IsOccupantOfTargetVehicleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsOccupantOfTargetVehicleCondition::`vftable;
  *(_WORD *)&v1->m_eOccupantTargetType.mValue = 7172;
}

// File Line: 4081
// RVA: 0x284250
bool __fastcall IsOccupantOfTargetVehicleCondition::Match(IsOccupantOfTargetVehicleCondition *this, ActionContext *pContext)
{
  IsOccupantOfTargetVehicleCondition *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::VehicleOccupantComponent *v12; // rdi
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    goto LABEL_31;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[44].m_pComponent;
  }
  else
  {
    if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID);
    }
    v6 = v7;
  }
  if ( v6
    && (v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer) != 0i64
    && ((v9 = v8->m_Flags, !((v9 >> 14) & 1)) ? ((v9 & 0x8000u) == 0 ? (!((v9 >> 13) & 1) ? (!((v9 >> 12) & 1) ? (v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v10 = v11) : (v10 = v8->m_Components.p[20].m_pComponent)) : (v10 = v8->m_Components.p[20].m_pComponent),
        v10
     && (v12 = *(UFG::VehicleOccupantComponent **)(56i64
                                                 * *(unsigned __int8 *)((unsigned __int8)v2->m_eVehicleTargetType.mValue
                                                                      + *(_QWORD *)&v10[1].m_Flags
                                                                      + 8i64)
                                                 + *(_QWORD *)&v10[1].m_TypeUID
                                                 + 40)) != 0i64
     && v12 == UFG::CharacterOccupantComponent::GetCurrentVehicle((UFG::CharacterOccupantComponent *)v6)) )
  {
    result = LODWORD(v6[1].m_SafePointerList.mNode.mNext) == (unsigned __int8)v2->m_eOccupantTargetType.mValue;
  }
  else
  {
LABEL_31:
    result = 0;
  }
  return result;
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
  IsBoatInsideWorldCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsBoatInsideWorldCondition::`vftable;
}

// File Line: 4124
// RVA: 0x283920
bool __fastcall IsBoatInsideWorldCondition::Match(IsBoatInsideWorldCondition *this, ActionContext *pContext)
{
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::VehicleOccupantComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  bool result; // al

  v2 = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  result = 1;
  if ( LocalPlayer == v2 && v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CharacterOccupantComponent *)v2->m_Components.p[44].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v2->vfptr,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v4 = (UFG::CharacterOccupantComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&v2->vfptr,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v2->vfptr,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v4 )
    {
      v5 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v4);
      if ( v5 )
      {
        v6 = v5->mpDriver.m_pPointer[4].m_SafePointerWithCallbackList.mNode.mNext;
        if ( v6 )
        {
          v7 = v6[40].mNext;
          if ( v7 )
          {
            if ( !(BYTE4(v7[37].mNext) & 7) && LOBYTE(v7[50].mNext) )
              result = 0;
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
  VehicleOrientationCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterOccupantComponent *v5; // rax
  UFG::SimObjectVehicle *v6; // rax
  int v7; // ebx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::CharacterOccupantComponent *)v3->m_Components.p[44].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v3,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    else
      v5 = (UFG::CharacterOccupantComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v3,
                                                                  UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
  }
  else
  {
    v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v3,
                                              UFG::CharacterOccupantComponent::_TypeUID);
  }
  if ( !v5 )
    return 0;
  v6 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v5);
  if ( !v6 )
    return 0;
  v7 = v2->m_iVehicleOrientation;
  return (unsigned int)UFG::VehicleUtility::GetVehicleOrientation(v6, 0, 0i64) == v7;
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
char __fastcall TargetVehicleDoorsLockedCondition::Match(TargetVehicleDoorsLockedCondition *this, ActionContext *pContext)
{
  __int64 v2; // rbx
  UFG::SimObjectGame *v3; // r8
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax

  v2 = (unsigned __int8)this->mTargetType.mValue;
  if ( (_DWORD)v2 == 1 )
  {
    v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  }
  else
  {
    v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( !v4 )
      return 0;
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v6 = v7;
    }
    else
    {
      v6 = v4->m_Components.p[20].m_pComponent;
    }
    if ( !v6 )
      return 0;
    v3 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + v2 + 8)
                                + *(_QWORD *)&v6[1].m_TypeUID
                                + 40);
  }
  if ( v3 )
  {
    v8 = v3->m_Flags;
    if ( !((v8 >> 14) & 1) )
    {
      if ( (v8 & 0x8000u) != 0 )
      {
        v9 = v3->m_Components.p[34].m_pComponent;
        goto LABEL_24;
      }
      if ( !((v8 >> 13) & 1) )
      {
        if ( (v8 >> 12) & 1 )
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_24:
        if ( v9 && LOBYTE(v9[14].m_SafePointerList.mNode.mNext) )
          return 1;
        return 0;
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
bool __fastcall TargetVehicleOrientationCondition::Match(TargetVehicleOrientationCondition *this, ActionContext *pContext)
{
  __int64 v2; // rbx
  TargetVehicleOrientationCondition *v3; // rdi
  UFG::SimObjectVehicle *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  int v8; // ebx
  bool v9; // dl
  float v10; // xmm1_4
  bool result; // al
  float pfReturn; // [rsp+30h] [rbp+8h]

  v2 = (unsigned __int8)this->mTargetType.mValue;
  v3 = this;
  v4 = (UFG::SimObjectVehicle *)pContext->mSimObject.m_pPointer;
  if ( (_DWORD)v2 != 1 )
  {
    if ( !v4 )
      return 0;
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v4->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)&v4->vfptr,
                                UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                 (UFG::SimObject *)&v4->vfptr,
                                                                                 UFG::TargetingSystemBaseComponent::_TypeUID);
      v6 = v7;
    }
    else
    {
      v6 = v4->m_Components.p[20].m_pComponent;
    }
    if ( !v6 )
      return 0;
    v4 = *(UFG::SimObjectVehicle **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + v2 + 8)
                                   + *(_QWORD *)&v6[1].m_TypeUID
                                   + 40);
  }
  if ( !v4 || (v4->m_Flags & 0x8000u) == 0 )
    return 0;
  v8 = v3->m_iVehicleOrientation;
  v9 = v3->m_bIgnoreWheelState != 0;
  pfReturn = FLOAT_3_4028235e38;
  result = 0;
  if ( (unsigned int)UFG::VehicleUtility::GetVehicleOrientation(v4, v9, &pfReturn) == v8 )
  {
    v10 = v3->mAndLessThanAngle;
    if ( v10 < 0.0 || pfReturn < v10 )
      result = 1;
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
  VehicleWindowBrokenCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::VehicleEffectsComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleEffectsComponent::_TypeUID)) : (v5 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID))) : (v5 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID))) : (v5 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent)) : (v5 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID)),
        v5) )
  {
    result = UFG::VehicleEffectsComponent::IsGlassBroken(v5, (UFG::eVehicleWindowTypeEnum)v2->m_eWindowType.mValue);
  }
  else
  {
    result = 0;
  }
  return result;
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
bool __fastcall TargetVehicleWindowBrokenCondition::Match(TargetVehicleWindowBrokenCondition *this, ActionContext *pContext)
{
  TargetVehicleWindowBrokenCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rax
  unsigned __int16 v4; // r8
  UFG::VehicleEffectsComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)(unsigned __int8)this->m_eTargetType.mValue);
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleEffectsComponent::_TypeUID)) : (v5 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID))) : (v5 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID))) : (v5 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent)) : (v5 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID)),
        v5) )
  {
    result = UFG::VehicleEffectsComponent::IsGlassBroken(v5, (UFG::eVehicleWindowTypeEnum)v2->m_eWindowType.mValue);
  }
  else
  {
    result = 0;
  }
  return result;
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
char __fastcall VehicleNumberOfTiresDamagedCondition::Match(VehicleNumberOfTiresDamagedCondition *this, ActionContext *pContext)
{
  VehicleNumberOfTiresDamagedCondition *v2; // r14
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rsi
  UFG::SimComponent *v6; // rax
  int v7; // ebp
  signed int v8; // edi
  int i; // ebx
  float v10; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
    return 0;
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      return 0;
    if ( (v4 >> 12) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
    v5 = (UFG::PhysicsMoverInterface *)v6;
  }
  else
  {
    v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = v5->mNumWheels;
  v8 = 0;
  for ( i = 0; i < v7; ++i )
  {
    v10 = UFG::PhysicsMoverInterface::GetTireDamage(v5, i);
    if ( CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v2->m_eDamageComparison.mValue, v2->m_fDamage, v10) )
      ++v8;
  }
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)v2->m_eNumberComparison.mValue,
           (float)v2->m_iNumber,
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
bool __fastcall VehicleEngineRipeForTakedownCondition::Match(VehicleEngineRipeForTakedownCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
    return 0;
  if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      return 0;
    if ( (v3 >> 12) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[34].m_pComponent;
  }
  if ( !v4 )
    return 0;
  return BYTE4(v4[14].vfptr) & 4 && (unsigned int)(HIDWORD(v4[2].m_BoundComponentHandles.mNode.mPrev) - 1) > 1;
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
  VehicleDamageCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rcx
  UFG::SimComponent *v6; // rax
  int v7; // edx
  float v8; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
    return 0;
  if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      return 0;
    if ( (v4 >> 12) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
    v5 = (UFG::PhysicsMoverInterface *)v6;
  }
  else
  {
    v5 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = (unsigned __int8)v2->m_eVehicleDamageType.mValue;
  v8 = 0.0;
  if ( v7 == 1 )
  {
    v8 = UFG::PhysicsMoverInterface::GetEngineDamage(v5);
  }
  else if ( (unsigned int)(v7 - 2) <= 3 )
  {
    v8 = UFG::PhysicsMoverInterface::GetTireDamage(v5, v7 - 2);
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v2->m_eInEqualityOperator.mValue, v2->m_fDamage, v8);
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
bool __fastcall VehicleHasDriverOrPassengerOccupantCondition::Match(VehicleHasDriverOrPassengerOccupantCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::VehicleOccupantComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::VehicleOccupantComponent::_TypeUID)) : (v4 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID))) : (v4 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID))) : (v4 = (UFG::VehicleOccupantComponent *)v2->m_Components.p[30].m_pComponent)) : (v4 = (UFG::VehicleOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::VehicleOccupantComponent::_TypeUID)),
        v4) )
  {
    result = (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v4) != 0;
  }
  else
  {
    result = 0;
  }
  return result;
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
bool __fastcall VehicleDeniesAllyDriverCondition::Match(VehicleDeniesAllyDriverCondition *this, ActionContext *pContext)
{
  VehicleDeniesAllyDriverCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  UFG::qPropertySet *v9; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(_QWORD *)(56i64
                        * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64)
                        + *(_QWORD *)&v5[1].m_TypeUID
                        + 40)) != 0
     && (v8 = *(UFG::SceneObjectProperties **)(v7 + 80)) != 0i64
     && (v9 = PropertyUtils::Get<bool>(v8, (UFG::qSymbol *)&qSymbol_DeniesAllyDriver.mUID)) != 0i64) )
  {
    result = v9->mFlags;
  }
  else
  {
    result = 0;
  }
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
bool __fastcall VehicleDeniesAllyPassengerCondition::Match(VehicleDeniesAllyPassengerCondition *this, ActionContext *pContext)
{
  VehicleDeniesAllyPassengerCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  UFG::qPropertySet *v9; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(_QWORD *)(56i64
                        * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64)
                        + *(_QWORD *)&v5[1].m_TypeUID
                        + 40)) != 0
     && (v8 = *(UFG::SceneObjectProperties **)(v7 + 80)) != 0i64
     && (v9 = PropertyUtils::Get<bool>(v8, (UFG::qSymbol *)&qSymbol_DeniesAllyPassenger.mUID)) != 0i64) )
  {
    result = v9->mFlags;
  }
  else
  {
    result = 0;
  }
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
bool __fastcall VehicleDeniesGetInPassengerSideCondition::Match(VehicleDeniesGetInPassengerSideCondition *this, ActionContext *pContext)
{
  VehicleDeniesGetInPassengerSideCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  UFG::qPropertySet *v9; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(_QWORD *)(56i64
                        * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64)
                        + *(_QWORD *)&v5[1].m_TypeUID
                        + 40)) != 0
     && (v8 = *(UFG::SceneObjectProperties **)(v7 + 80)) != 0i64
     && (v9 = PropertyUtils::Get<bool>(v8, (UFG::qSymbol *)&qSymbol_DeniesGetInPassengerSide.mUID)) != 0i64) )
  {
    result = v9->mFlags;
  }
  else
  {
    result = 0;
  }
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
bool __fastcall VehicleDeniesGetInDriverSideCondition::Match(VehicleDeniesGetInDriverSideCondition *this, ActionContext *pContext)
{
  VehicleDeniesGetInDriverSideCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  UFG::qPropertySet *v9; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(_QWORD *)(56i64
                        * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64)
                        + *(_QWORD *)&v5[1].m_TypeUID
                        + 40)) != 0
     && (v8 = *(UFG::SceneObjectProperties **)(v7 + 80)) != 0i64
     && (v9 = PropertyUtils::Get<bool>(v8, (UFG::qSymbol *)&qSymbol_DeniesGetInDriverSide.mUID)) != 0i64) )
  {
    result = v9->mFlags;
  }
  else
  {
    result = 0;
  }
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
  VehicleDeniesHijackCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rax
  UFG::qPropertySet *v10; // rax
  bool *v11; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    goto LABEL_30;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( v5
    && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                      * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                           + *(_QWORD *)&v5[1].m_Flags
                                                           + 8i64)
                                      + *(_QWORD *)&v5[1].m_TypeUID
                                      + 40)) != 0i64
    && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7)),
        v9
     && (v10 = UFG::AiDriverComponent::GetDriverProfile(v9)) != 0i64
     && (v11 = PropertyUtils::Get<bool>(v10, (UFG::qSymbol *)&qSymbol_DeniesHijack.mUID, DEPTH_RECURSE)) != 0i64) )
  {
    result = *v11;
  }
  else
  {
LABEL_30:
    result = 0;
  }
  return result;
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
char __fastcall VehicleAimingShotBlockedCondition::Match(VehicleAimingShotBlockedCondition *this, ActionContext *pContext)
{
  ActionContext *v2; // rdi
  VehicleAimingShotBlockedCondition *v3; // rbx
  unsigned int v4; // eax
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rdx
  UFG::SimComponent *v8; // rax
  __int64 v9; // rbx
  UFG::SceneObjectProperties *v10; // rcx
  UFG::qPropertySet *v11; // rsi
  UFG::qPropertySet *v12; // rax
  float *v13; // rbx
  UFG::SimObject *v14; // r8
  unsigned __int16 v15; // dx
  UFG::AimingBaseComponent *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  float v18; // xmm0_4

  v2 = pContext;
  v3 = this;
  v4 = _S9_4;
  if ( !(_S9_4 & 1) )
  {
    _S9_4 |= 1u;
    UFG::qSymbol::create_from_string(&symVehicleAimBlockedRangeStart, "VehicleAimBlockedRangeStart");
    atexit(VehicleAimingShotBlockedCondition::Match_::_2_::_dynamic_atexit_destructor_for__symVehicleAimBlockedRangeStart__);
    v4 = _S9_4;
  }
  if ( !(v4 & 2) )
  {
    _S9_4 = v4 | 2;
    UFG::qSymbol::create_from_string(&symVehicleAimBlockedRangeEnd, "VehicleAimBlockedRangeEnd");
    atexit(VehicleAimingShotBlockedCondition::Match_::_2_::_dynamic_atexit_destructor_for__symVehicleAimBlockedRangeEnd__);
  }
  v5 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
  if ( v5 )
  {
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v7 = v8;
    }
    else
    {
      v7 = v5->m_Components.p[20].m_pComponent;
    }
    if ( v7 )
    {
      v9 = *(_QWORD *)(56i64
                     * *(unsigned __int8 *)((unsigned __int8)v3->mTargetType.mValue + *(_QWORD *)&v7[1].m_Flags + 8i64)
                     + *(_QWORD *)&v7[1].m_TypeUID
                     + 40);
      if ( v9 )
      {
        v10 = *(UFG::SceneObjectProperties **)(v9 + 80);
        if ( v10 )
        {
          v11 = PropertyUtils::Get<float>(v10, &symVehicleAimBlockedRangeStart);
          v12 = PropertyUtils::Get<float>(*(UFG::SceneObjectProperties **)(v9 + 80), &symVehicleAimBlockedRangeEnd);
          v13 = (float *)&v12->mFlags;
          if ( v11 )
          {
            if ( v12 )
            {
              v14 = v2->mSimObject.m_pPointer;
              if ( v14 )
              {
                v15 = v14->m_Flags;
                if ( (v15 >> 14) & 1 )
                {
                  v16 = (UFG::AimingBaseComponent *)v14->m_Components.p[47].m_pComponent;
                }
                else
                {
                  v17 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
                  if ( (v15 & 0x8000u) == 0 )
                  {
                    if ( (v15 >> 13) & 1 )
                      v16 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v17,
                                                          UFG::AimingBaseComponent::_TypeUID);
                    else
                      v16 = (UFG::AimingBaseComponent *)((v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             v17,
                                                                             UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, UFG::AimingBaseComponent::_TypeUID));
                  }
                  else
                  {
                    v16 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v17,
                                                        UFG::AimingBaseComponent::_TypeUID);
                  }
                }
                if ( v16 )
                {
                  v18 = UFG::AimingBaseComponent::GetLocalAimDirectionXY(v16);
                  if ( *(float *)&v11->mFlags >= *v13 )
                  {
                    if ( v18 > (float)((float)(*(float *)&v11->mFlags * 3.1415927) * 0.0055555557) )
                      return 1;
                  }
                  else if ( v18 <= (float)((float)(*(float *)&v11->mFlags * 3.1415927) * 0.0055555557) )
                  {
                    return 0;
                  }
                  if ( (float)((float)(*v13 * 3.1415927) * 0.0055555557) <= v18 )
                    return 0;
                  return 1;
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
  VehicleCanActionHijackCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::TargetingSystemVehicleComponent *v9; // rax
  UFG::ActionHijackProfile *v10; // rcx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                            + *(_QWORD *)&v5[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v5[1].m_TypeUID
                                       + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::TargetingSystemVehicleComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::TargetingSystemVehicleComponent::_TypeUID)) : (v9 = (UFG::TargetingSystemVehicleComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::TargetingSystemVehicleComponent::_TypeUID))) : (v9 = (UFG::TargetingSystemVehicleComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::TargetingSystemVehicleComponent::_TypeUID))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v7))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v7)),
         v9 && (v10 = v9->m_pActionHijackProfile) != 0i64)) )
  {
    result = v10->m_bCanActionHijackTo;
  }
  else
  {
    result = 0;
  }
  return result;
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
bool __fastcall VehicleCanActionHijackClimbCondition::Match(VehicleCanActionHijackClimbCondition *this, ActionContext *pContext)
{
  VehicleCanActionHijackClimbCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::TargetingSystemVehicleComponent *v9; // rax
  UFG::ActionHijackProfile *v10; // rcx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                       * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                            + *(_QWORD *)&v5[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v5[1].m_TypeUID
                                       + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::TargetingSystemVehicleComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::TargetingSystemVehicleComponent::_TypeUID)) : (v9 = (UFG::TargetingSystemVehicleComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::TargetingSystemVehicleComponent::_TypeUID))) : (v9 = (UFG::TargetingSystemVehicleComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::TargetingSystemVehicleComponent::_TypeUID))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v7))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(v7)),
         v9 && (v10 = v9->m_pActionHijackProfile) != 0i64)) )
  {
    result = v10->m_bCanActionHijackClimb;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 4933
// RVA: 0x1491B80
__int64 dynamic_initializer_for__gVehicleDoorEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gVehicleDoorEnum, "Global/Act/VehicleDoor.xml");
  return atexit(dynamic_atexit_destructor_for__gVehicleDoorEnum__);
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
  VehicleCanOpenDoorCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleCanOpenDoorCondition::`vftable;
  v1->m_Door = 0;
}

// File Line: 4947
// RVA: 0x291320
char __fastcall VehicleCanOpenDoorCondition::Match(VehicleCanOpenDoorCondition *this, ActionContext *pContext)
{
  ActionContext *v2; // rbx
  VehicleCanOpenDoorCondition *v3; // rdi
  UFG::SimObjectCVBase *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *v7; // r14
  UFG::TransformNodeComponent *v8; // rsi
  const char *v9; // rdx
  UFG::SimObjectCVBase *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimObjectVehiclePropertiesComponent *v12; // rax
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *v13; // rax
  UFG::SimObjectVehiclePropertiesComponent::DoorPhantomInfo *v14; // rdi
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  UFG::SimObject *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  __m128 v21; // xmm5
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
  int v33; // eax
  float v34; // xmm6_4
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  float v37; // xmm6_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm6_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm4_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  float v49; // xmm4_4
  UFG::SimObject *v50; // rax
  UFG::qVector3 translation; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 forward; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 up; // [rsp+50h] [rbp-B0h]
  UFG::SensorPhantomIterator v55; // [rsp+60h] [rbp-A0h]
  UFG::SensorPhantom sensor; // [rsp+78h] [rbp-88h]
  hkVector4f halfExtents; // [rsp+90h] [rbp-70h]
  __int64 v58; // [rsp+A0h] [rbp-60h]
  hkpBoxShape v59; // [rsp+B0h] [rbp-50h]
  UFG::qMatrix44 dest; // [rsp+F0h] [rbp-10h]
  UFG::qSymbolUC result; // [rsp+1A8h] [rbp+A8h]

  v58 = -2i64;
  v2 = pContext;
  v3 = this;
  v4 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
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
  v8 = 0i64;
  if ( (gVehicleDoorEnum.m_enumLists.size & 0x80000000) != 0 )
    v9 = 0i64;
  else
    v9 = (*gVehicleDoorEnum.m_enumLists.p)->m_enumName.p[v3->m_Door];
  UFG::qSymbolUC::create_from_string(&result, v9);
  v10 = (UFG::SimObjectCVBase *)v2->mSimObject.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v10);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v10->vfptr,
                                                            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      else
        v12 = (UFG::SimObjectVehiclePropertiesComponent *)((v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                               (UFG::SimObjectGame *)&v10->vfptr,
                                                                               UFG::SimObjectVehiclePropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID));
    }
    else
    {
      v12 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v10);
    }
    if ( v12 )
    {
      v13 = UFG::SimObjectVehiclePropertiesComponent::GetDoorPhantomInfo(v12, result.mUID);
      v14 = v13;
      if ( v13 )
      {
        v15 = (__m128)LODWORD(v13->extentX);
        v15.m128_f32[0] = v15.m128_f32[0] * 0.5;
        v16 = (__m128)LODWORD(v13->extentY);
        v16.m128_f32[0] = v16.m128_f32[0] * 0.5;
        halfExtents.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(v15, (__m128)LODWORD(v13->height)),
                               _mm_unpacklo_ps(v16, (__m128)0i64));
        hkpBoxShape::hkpBoxShape(&v59, &halfExtents, hkConvexShapeDefaultRadius);
        v17 = v2->mSimObject.m_pPointer;
        if ( v17 )
          v8 = v17->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        v18 = v8->mWorldTransform.v2.y;
        v19 = v8->mWorldTransform.v2.z;
        up.x = v8->mWorldTransform.v2.x;
        up.y = v18;
        up.z = v19;
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        v20 = v8->mWorldTransform.v0.y;
        v21 = (__m128)LODWORD(v8->mWorldTransform.v0.x);
        v22 = v8->mWorldTransform.v0.z;
        v23 = v21;
        v23.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22);
        v24 = v15.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v23));
        forward.x = v24 * v21.m128_f32[0];
        forward.y = v24 * v20;
        forward.z = v24 * v22;
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        v25 = v8->mWorldTransform.v1.y;
        v26 = (__m128)LODWORD(v8->mWorldTransform.v1.x);
        v27 = v8->mWorldTransform.v1.z;
        v28 = v26;
        v28.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v27 * v27);
        v29 = v16.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v28));
        v30 = v29 * v27;
        v31 = v29 * v25;
        v32 = v29 * v26.m128_f32[0];
        if ( v7->mPose.mRigHandle.mData )
          v33 = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, result.mUID);
        else
          v33 = -1;
        Creature::GetTranslation(v7, &translation, v33);
        v34 = v14->heightOffset;
        if ( v34 == 0.0 )
        {
          v43 = translation.z;
          v42 = translation.y;
          v41 = translation.x;
        }
        else
        {
          v35 = (__m128)LODWORD(up.y);
          v36 = v35;
          v36.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(up.x * up.x))
                          + (float)(up.z * up.z);
          v37 = v34 / COERCE_FLOAT(_mm_sqrt_ps(v36));
          v38 = v37 * up.z;
          v39 = v37 * up.y;
          v40 = v37 * up.x;
          v41 = translation.x + v40;
          v42 = translation.y + v39;
          v43 = translation.z + v38;
          translation.x = translation.x + v40;
          translation.y = translation.y + v39;
          translation.z = translation.z + v38;
        }
        if ( v14->extendLeft )
        {
          v44 = v41 + v32;
          v45 = v42 + v31;
          v46 = v43 + v30;
        }
        else
        {
          v44 = v41 - v32;
          v45 = v42 - v31;
          v46 = v43 - v30;
        }
        translation.z = v46;
        translation.y = v45;
        translation.x = v44;
        if ( v14->extendForward )
        {
          v47 = v44 + forward.x;
          v48 = v45 + forward.y;
          v49 = v46 + forward.z;
        }
        else
        {
          v47 = v44 - forward.x;
          v48 = v45 - forward.y;
          v49 = v46 - forward.z;
        }
        translation.z = v49;
        translation.y = v48;
        translation.x = v47;
        UFG::qMakeMatrix(&dest, &forward, &up, &translation, 0.001);
        UFG::SensorPhantom::SensorPhantom(&sensor, (hkpShape *)&v59.vfptr, &dest, 0x10u);
        UFG::SensorPhantomIterator::SensorPhantomIterator(&v55, &sensor, 0);
        while ( UFG::SensorPhantomIterator::operator*(&v55) )
        {
          v50 = (UFG::SimObject *)UFG::SensorPhantomIterator::operator*(&v55);
          if ( v50 != v2->mSimObject.m_pPointer && !((v50->m_Flags >> 14) & 1) )
          {
            UFG::SensorPhantomIterator::~SensorPhantomIterator(&v55);
            UFG::SensorPhantom::~SensorPhantom(&sensor);
            hkpBoxShape::~hkpBoxShape(&v59);
            return 0;
          }
          UFG::SensorPhantomIterator::operator++(&v55);
        }
        UFG::SensorPhantomIterator::~SensorPhantomIterator(&v55);
        UFG::SensorPhantom::~SensorPhantom(&sensor);
        hkpBoxShape::~hkpBoxShape(&v59);
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
  VehicleBoxSideCondition *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectVehicle *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::VehicleSubjectComponent *v10; // rax
  UFG::VehicleSubjectComponent *v11; // rbx
  UFG::SimObject *v12; // rax
  UFG::TransformNodeComponent *v13; // rdi

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(UFG::SimObjectVehicle **)(56i64
                                 * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                      + *(_QWORD *)&v6[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&v6[1].m_TypeUID
                                 + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v8->vfptr,
                                            UFG::VehicleSubjectComponent::_TypeUID);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v8->vfptr,
                                              UFG::VehicleSubjectComponent::_TypeUID);
    else
      v10 = (UFG::VehicleSubjectComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v8->vfptr,
                                                                UFG::VehicleSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::VehicleSubjectComponent::_TypeUID));
  }
  else
  {
    v10 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v8);
  }
  v11 = v10;
  if ( !v10 )
    return 0;
  v12 = v4->mSimObject.m_pPointer;
  v13 = 0i64;
  if ( v12 )
    v13 = v12->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
  return (unsigned int)UFG::VehicleSubjectComponent::GetBoxSide(v11, (UFG::qVector3 *)&v13->mWorldTransform.v3) == v2->mBoxSide;
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
bool __fastcall VehicleDirectlyBehindCondition::Match(VehicleDirectlyBehindCondition *this, ActionContext *pContext)
{
  VehicleDirectlyBehindCondition *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectVehicle *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::VehicleSubjectComponent *v10; // rax
  UFG::VehicleSubjectComponent *v11; // rdi
  UFG::SimObject *v12; // rax
  char v13; // si
  UFG::TransformNodeComponent *v14; // r14
  float *v15; // rbx
  float *v16; // rax
  float v17; // xmm6_4
  float v18; // xmm11_4
  float v19; // xmm10_4
  float v20; // xmm9_4
  float v21; // xmm8_4
  float v22; // xmm7_4
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
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(UFG::SimObjectVehicle **)(56i64
                                 * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                      + *(_QWORD *)&v6[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&v6[1].m_TypeUID
                                 + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v8->vfptr,
                                            UFG::VehicleSubjectComponent::_TypeUID);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v8->vfptr,
                                              UFG::VehicleSubjectComponent::_TypeUID);
    else
      v10 = (UFG::VehicleSubjectComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v8->vfptr,
                                                                UFG::VehicleSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::VehicleSubjectComponent::_TypeUID));
  }
  else
  {
    v10 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v8);
  }
  v11 = v10;
  if ( !v10 )
    return 0;
  v12 = v4->mSimObject.m_pPointer;
  v13 = 0;
  v14 = 0i64;
  if ( v12 )
    v14 = v12->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v14);
  v15 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v11->vfptr[23].__vecDelDtor)(v11);
  v16 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v11->vfptr[24].__vecDelDtor)(v11);
  v17 = v14->mWorldTransform.v3.x;
  v18 = v14->mWorldTransform.v3.y;
  v19 = (float)(*v16 + *v15) * 0.5;
  v20 = (float)(v16[1] + v15[1]) * 0.5;
  v21 = (float)(v16[2] + v15[2]) * 0.5;
  v22 = v14->mWorldTransform.v3.z;
  v23 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v11->vfptr[19].__vecDelDtor)(v11);
  v24 = v18 * v23[5];
  v25 = *v15 - v19;
  v26 = v15[1] - v20;
  v27 = (float)((float)(v18 * v23[4]) + (float)(v17 * *v23)) + (float)(v22 * v23[8]);
  v28 = v17 * v23[1];
  v29 = (float)(v18 * v23[6]) + (float)(v17 * v23[2]);
  v30 = v15[2] - v21;
  v31 = (float)((float)(v29 + (float)(v22 * v23[10])) + v23[14]) - v21;
  v32 = (float)((float)((float)(v24 + v28) + (float)(v22 * v23[9])) + v23[13]) - v20;
  v33 = (float)(v27 + v23[12]) - v19;
  if ( v2->mPastRearEnd )
    LODWORD(v35) = COERCE_UNSIGNED_INT(
                     (float)((float)(v26 * UFG::qVector3::msAxisX.y) + (float)(v25 * UFG::qVector3::msAxisX.x))
                   + (float)(v30 * UFG::qVector3::msAxisX.z)) & _xmm;
  else
    v35 = 0.0;
  LODWORD(v34) = COERCE_UNSIGNED_INT(
                   (float)((float)(v33 * UFG::qVector3::msAxisX.x) + (float)(v32 * UFG::qVector3::msAxisX.y))
                 + (float)(v31 * UFG::qVector3::msAxisX.z)) & _xmm;
  result = v34 >= v35;
  if ( v2->mNotPastLeftRightSides )
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
      v13 = 1;
    }
    result = v13;
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
  DriverProfileTypeCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax
  unsigned int *v6; // rax
  signed int v7; // eax
  _BOOL8 result; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID)) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::AiDriverComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3)),
        v5 && (v6 = UFG::AiDriverComponent::GetDriverProfileType(v5)) != 0i64 && (v7 = *v6) != 0 && v7 < 3) )
  {
    result = v2->mIsTrue != 0;
  }
  else
  {
    result = v2->mIsTrue == 0;
  }
  return result;
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
  TargetRelativePosition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetRelativePosition::`vftable;
  v1->mTargetType.mValue = 0;
  v1->mDirection = 0.0;
  *(_QWORD *)&v1->mAngleRange = 1070141403i64;
}

// File Line: 5224
// RVA: 0x28EBB0
bool __fastcall TargetRelativePosition::Match(TargetRelativePosition *this, ActionContext *context)
{
  TargetRelativePosition *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // r14
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  UFG::SimComponent *v8; // r8
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  unsigned __int8 v11; // al
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::SimObjectGame *v15; // rbx
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  UFG::RigidBody *v18; // rdi
  UFG::SimObject *v19; // rdx
  UFG::TransformNodeComponent *v20; // rcx
  __m128 v21; // xmm2
  UFG::qVector3 *v22; // rax
  float v23; // xmm1_4
  UFG::SimObject *v24; // rdx
  UFG::TransformNodeComponent *v25; // rcx
  UFG::SimObjectGame *v26; // rcx
  unsigned __int16 v27; // dx
  UFG::SimComponent *v28; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rdi
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
  float v40; // xmm7_4
  float v41; // xmm4_4
  float v42; // xmm3_4
  float v43; // xmm4_4
  float v44; // xmm5_4
  float v45; // xmm7_4
  float v46; // xmm2_4
  float v47; // xmm2_4
  float v48; // xmm0_4
  UFG::SimObject *v49; // rdx
  UFG::TransformNodeComponent *v50; // rcx
  __m128 v51; // xmm0
  float v52; // xmm4_4
  float v53; // xmm4_4
  UFG::qVector3 v1; // [rsp+20h] [rbp-E0h]
  UFG::qMatrix44 matSimObject; // [rsp+30h] [rbp-D0h]
  UFG::qMatrix44 v57; // [rsp+70h] [rbp-90h]
  UFG::qVector3 result; // [rsp+B0h] [rbp-50h]
  char v59; // [rsp+BCh] [rbp-44h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[7].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = v3->m_Components.p[6].m_pComponent;
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
  }
  else
  {
    v6 = v3->m_Components.p[7].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v7 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v8 = v7->m_Components.p[20].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v9 >> 12) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v7->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v8 = v10;
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
  v11 = v2->mTargetsTarget.mValue;
  if ( v11 )
  {
    v12 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v8[1].m_Flags + v11 + 8i64)
                                 + *(_QWORD *)&v8[1].m_TypeUID
                                 + 40);
    if ( !v12 )
      return 0;
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v8 = v12->m_Components.p[20].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v13 >> 12) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v14 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v12->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v8 = v14;
    }
    else
    {
      v8 = v12->m_Components.p[20].m_pComponent;
    }
  }
  if ( !v8 )
    return 0;
  v15 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                    + *(_QWORD *)&v8[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v8[1].m_TypeUID
                               + 40);
  if ( !v15 )
    return 0;
  if ( v2->mRelativeToCentreOfMass
    && ((v16 = v15->m_Flags, !((v16 >> 14) & 1)) ? ((v16 & 0x8000u) == 0 ? (!((v16 >> 13) & 1) ? (!((v16 >> 12) & 1) ? (v17 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::RigidBodyComponent::_TypeUID)) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RigidBodyComponent::_TypeUID))) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RigidBodyComponent::_TypeUID))) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RigidBodyComponent::_TypeUID))) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RigidBodyComponent::_TypeUID)),
        (v18 = (UFG::RigidBody *)v17) != 0i64) )
  {
    v19 = v4->mSimObject.m_pPointer;
    v20 = 0i64;
    if ( v19 )
      v20 = v19->m_pTransformNodeComponent;
    UFG::TargetingSystemBaseComponent::FindMatrix(v20, v19, &matSimObject);
    v21 = 0i64;
    v21.m128_f32[0] = (float)1;
    v57.v0 = (UFG::qVector4)v21;
    v57.v3 = (UFG::qVector4)_mm_shuffle_ps(v21, v21, 21);
    v57.v1 = (UFG::qVector4)_mm_shuffle_ps(v21, v21, 81);
    v57.v2 = (UFG::qVector4)_mm_shuffle_ps(v21, v21, 69);
    v22 = UFG::RigidBody::GetCentreOfMass(v18, &result);
    v23 = v22->y;
    v21.m128_i32[0] = LODWORD(v22->z);
    v57.v3.x = v22->x;
    v57.v3.y = v23;
    LODWORD(v57.v3.w) = (_DWORD)FLOAT_1_0;
    LODWORD(v57.v3.z) = v21.m128_i32[0];
  }
  else if ( v2->mRelativeToTarget )
  {
    UFG::TargetingSystemBaseComponent::FindMatrix((UFG::SimObject *)&v15->vfptr, &matSimObject);
    v24 = v4->mSimObject.m_pPointer;
    v25 = 0i64;
    if ( v24 )
      v25 = v24->m_pTransformNodeComponent;
    UFG::TargetingSystemBaseComponent::FindMatrix(v25, v24, &v57);
  }
  else if ( v2->mRelativeToCover )
  {
    v26 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( !v26 )
      return 0;
    v27 = v26->m_Flags;
    if ( (v27 >> 14) & 1 )
    {
      v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v27 & 0x8000u) == 0 )
    {
      if ( (v27 >> 13) & 1 )
        v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::AICoverComponent::_TypeUID);
      else
        v28 = (v27 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::AICoverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v26->vfptr, UFG::AICoverComponent::_TypeUID);
    }
    else
    {
      v28 = UFG::SimObjectGame::GetComponentOfTypeHK(v26, UFG::AICoverComponent::_TypeUID);
    }
    if ( !v28 )
      return 0;
    v29 = v28[1].m_BoundComponentHandles.mNode.mNext;
    if ( !v29
      || !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v29->mPrev[1].mPrev)(v29) )
    {
      return 0;
    }
    v30 = (_DWORD *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::qVector3 *))v29->mPrev[10].mPrev)(
                      v29,
                      &result);
    LODWORD(v31) = *v30 ^ _xmm[0];
    LODWORD(v32) = v30[1] ^ _xmm[0];
    LODWORD(v33) = v30[2] ^ _xmm[0];
    v34 = ((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, char *))v29->mPrev[7].mNext)(
            v29,
            &v59);
    matSimObject.v0.x = v31;
    matSimObject.v0.y = v32;
    matSimObject.v0.z = v33;
    matSimObject.v0.w = 0.0;
    v35 = (float)(v33 * UFG::qVector3::msDirUp.y) - (float)(v32 * UFG::qVector3::msDirUp.z);
    v36 = (float)(v31 * UFG::qVector3::msDirUp.z) - (float)(v33 * UFG::qVector3::msDirUp.x);
    v37 = (float)(v32 * UFG::qVector3::msDirUp.x) - (float)(v31 * UFG::qVector3::msDirUp.y);
    v38 = (float)((float)(v36 * v36) + (float)(v35 * v35)) + (float)(v37 * v37);
    v39 = v38 == 0.0 ? 0.0 : 1.0 / fsqrt(v38);
    v40 = v35 * v39;
    v41 = v36 * v39;
    matSimObject.v1.w = 0.0;
    matSimObject.v1.x = v40;
    matSimObject.v1.z = v37 * v39;
    matSimObject.v1.y = v41;
    v42 = (float)((float)(v37 * v39) * v32) - (float)(v41 * v33);
    v43 = (float)(v41 * v31) - (float)(v40 * v32);
    v44 = (float)(v40 * v33) - (float)((float)(v37 * v39) * v31);
    v45 = (float)((float)(v44 * v44) + (float)(v42 * v42)) + (float)(v43 * v43);
    v46 = v45 == 0.0 ? 0.0 : 1.0 / fsqrt(v45);
    matSimObject.v2.w = 0.0;
    matSimObject.v2.x = v42 * v46;
    matSimObject.v2.y = v44 * v46;
    matSimObject.v2.z = v43 * v46;
    v47 = *(float *)(v34 + 8);
    v48 = *(float *)v34;
    matSimObject.v3.y = *(float *)(v34 + 4);
    matSimObject.v3.z = v47;
    matSimObject.v3.w = 1.0;
    matSimObject.v3.x = v48;
    UFG::TargetingSystemBaseComponent::FindMatrix((UFG::SimObject *)&v15->vfptr, &v57);
  }
  else
  {
    v49 = v4->mSimObject.m_pPointer;
    v50 = 0i64;
    if ( v49 )
      v50 = v49->m_pTransformNodeComponent;
    UFG::TargetingSystemBaseComponent::FindMatrix(v50, v49, &matSimObject);
    UFG::TargetingSystemBaseComponent::FindMatrix((UFG::SimObject *)&v15->vfptr, &v57);
  }
  v51 = (__m128)LODWORD(v57.v3.y);
  v1.z = 0.0;
  v51.m128_f32[0] = v57.v3.y - matSimObject.v3.y;
  LODWORD(v1.y) = v51.m128_i32[0];
  v1.x = v57.v3.x - matSimObject.v3.x;
  v51.m128_f32[0] = (float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v1.x * v1.x);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v51)) < 0.000099999997 )
    return 0;
  v52 = UFG::qAngleBetween(&v1, (UFG::qVector3 *)&matSimObject);
  if ( (float)((float)((float)(matSimObject.v1.y * v1.y) + (float)(matSimObject.v1.x * v1.x))
             + (float)(matSimObject.v1.z * v1.z)) > 0.0 )
    v52 = 6.2831855 - v52;
  v53 = v52 - v2->mDirection;
  if ( v53 < 0.0 )
    v53 = v53 + 6.2831855;
  if ( v53 >= 3.1415927 )
    v53 = 6.2831855 - v53;
  return v53 <= v2->mAngleRange;
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
  TargetConditionGroup *v1; // rdi
  char *v2; // rax
  char *v3; // rbx
  signed __int64 v4; // rax

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetConditionGroup::`vftable;
  v1->mTargetType.mValue = 0;
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
  v4 = (signed __int64)&v1->mConditions;
  if ( v3 )
    v3 -= v4;
  *(_QWORD *)v4 = v3;
}

// File Line: 5385
// RVA: 0x27AFC0
Expression::IMemberMap *__fastcall TargetConditionGroup::CreateClone(TargetConditionGroup *this)
{
  TargetConditionGroup *v1; // rsi
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  char *v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  __int64 v10; // rax
  signed __int64 v11; // rcx
  __int64 v12; // rax

  v1 = this;
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
    (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)&v5[v6] + 8i64))(&v5[v6], 1i64);
  *(_QWORD *)(v4 + 8) = v1->mResourceOwner;
  *(_DWORD *)(v4 + 16) = v1->mPad0;
  *(_WORD *)(v4 + 20) = v1->mPad1;
  *(_BYTE *)(v4 + 22) = v1->mPad2;
  *(_BYTE *)(v4 + 23) = v1->mBreakPoint;
  v7 = v1->mConditions.mOffset;
  if ( v7 && (v8 = (signed __int64)&v1->mConditions + v7) != 0 )
    v9 = v8 - (_QWORD)v5;
  else
    v9 = 0i64;
  *(_QWORD *)v5 = v9;
  *(_BYTE *)(v4 + 32) = v1->mTargetType.mValue;
  v10 = v1->mConditions.mOffset;
  if ( v10 )
    v11 = (signed __int64)&v1->mConditions + v10;
  else
    v11 = 0i64;
  v12 = (*(__int64 (**)(void))(*(_QWORD *)v11 + 16i64))();
  if ( v12 )
    *(_QWORD *)v5 = v12 - (_QWORD)v5;
  else
    *(_QWORD *)v5 = 0i64;
  return (Expression::IMemberMap *)v4;
}

// File Line: 5426
// RVA: 0x28BC90
UFG::SimObjectGame *__fastcall TargetConditionGroup::Match(TargetConditionGroup *this, ActionContext *context)
{
  ActionContext *v2; // rdi
  TargetConditionGroup *v3; // rsi
  UFG::SimObjectGame *result; // rax
  UFG::SimObjectGame *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  __int64 v8; // rax
  ActionNodeRoot *v9; // rdi
  __int64 v10; // rax
  UFG::ActionTreeComponentBase *v11; // rdx
  UFG::ActionTreeComponentBase *v12; // rcx
  UFG::ActionTreeComponentBase *v13; // r8
  UEL::ParametersBase *v14; // rdi
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  __int64 v17; // rax
  signed __int64 v18; // rcx
  unsigned __int8 v19; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  ActionContext pContext; // [rsp+30h] [rbp-C8h]
  ActionContext *retaddr; // [rsp+118h] [rbp+20h]

  v2 = context;
  v3 = this;
  result = (UFG::SimObjectGame *)UFG::getTarget(
                                   context,
                                   (UFG::eTargetTypeEnum)(unsigned __int8)this->mTargetType.mValue);
  v5 = result;
  if ( result )
  {
    ActionContext::ActionContext(
      &pContext,
      (UFG::eActionTreeType)v2->m_ActionTreeType.mValue,
      (UFG::SimObject *)&result->vfptr);
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[7].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = v5->m_Components.p[6].m_pComponent;
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v7 = v5->m_Components.p[7].m_pComponent;
    }
    if ( v7 )
    {
      ActionContext::operator=(&pContext, (ActionContext *)v7[2].m_BoundComponentHandles.mNode.mNext);
      pContext.m_ActionTreeType.mValue = v2->m_ActionTreeType.mValue;
      v8 = ((__int64 (__cdecl *)(ActionNode *))v2->m_OpeningBranch->vfptr[1].GetResourceOwner)(v2->m_OpeningBranch);
      v9 = (ActionNodeRoot *)v8;
      v10 = *(char *)(v8 + 236);
      v11 = pContext.mActionTreeComponentBase[v10];
      v12 = pContext.mActionTreeComponentBase[0];
      v13 = pContext.mActionTreeComponentBase[0];
      if ( v11 )
        v13 = pContext.mActionTreeComponentBase[v10];
      if ( v13 )
      {
        if ( v11 )
          v12 = pContext.mActionTreeComponentBase[v10];
        if ( UFG::ActionTreeComponentBase::AllocateFor(v12, v9) )
          ActionNodeRoot::Init(v9, &pContext);
      }
      v14 = UEL::gCurrentParameters;
      v15 = v5->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = v5->m_Components.p->m_pComponent;
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
        {
          v16 = v5->m_Components.p->m_pComponent;
        }
        else if ( (v15 >> 12) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::UELComponent::_TypeUID);
        }
        else
        {
          v16 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::UELComponent::_TypeUID);
        }
      }
      else
      {
        v16 = v5->m_Components.p->m_pComponent;
      }
      if ( v16 )
        UEL::gCurrentParameters = (UEL::ParametersBase *)&v16[1].m_TypeUID;
      else
        UEL::gCurrentParameters = 0i64;
      v17 = v3->mConditions.mOffset;
      if ( v17 )
        v18 = (signed __int64)&v3->mConditions + v17;
      else
        v18 = 0i64;
      v19 = (*(__int64 (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v18 + 80i64))(v18, &pContext);
      UEL::gCurrentParameters = v14;
    }
    else
    {
      v19 = 0;
    }
    retaddr = &pContext;
    if ( pContext.mSimObject.m_pPointer )
    {
      v20 = pContext.mSimObject.mPrev;
      v21 = pContext.mSimObject.mNext;
      pContext.mSimObject.mPrev->mNext = pContext.mSimObject.mNext;
      v21->mPrev = v20;
      pContext.mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&pContext;
      pContext.mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&pContext;
    }
    v22 = pContext.mSimObject.mPrev;
    v23 = pContext.mSimObject.mNext;
    pContext.mSimObject.mPrev->mNext = pContext.mSimObject.mNext;
    v23->mPrev = v22;
    result = (UFG::SimObjectGame *)v19;
  }
  return result;
}

// File Line: 5508
// RVA: 0x294140
void __fastcall TargetConditionGroup::ResolveReferences(TargetConditionGroup *this, ActionNode *parent)
{
  __int64 v2; // rax

  v2 = this->mConditions.mOffset;
  if ( v2 )
    (*(void (__fastcall **)(char *, ActionNode *))(*(__int64 *)((char *)&this->mConditions.mOffset + v2) + 120))(
      (char *)&this->mConditions + v2,
      parent);
  else
    (*(void (__fastcall **)(_QWORD, ActionNode *))(MEMORY[0] + 120))(0i64, parent);
}

// File Line: 5513
// RVA: 0x294240
void __fastcall TargetConditionGroup::Serialize(TargetConditionGroup *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  IActionTreeSerializer *v3; // rdi
  char *v4; // rbx
  __int64 v5; // rax
  signed int v6; // ST40_4
  unsigned int v7; // ST30_4
  signed int v8; // ST28_4

  v2 = this->mConditions.mOffset;
  v3 = serializer;
  if ( v2 )
  {
    v4 = (char *)&this->mConditions + v2;
    if ( v4 )
    {
      v5 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 32i64))(v4);
      v6 = -1;
      v7 = 0;
      v8 = 1;
      v3->vfptr->_PushObjectToSerialize(
        v3,
        v4,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        (const char *)v5,
        (QUEUE_PRIORITY)v8,
        v7,
        0i64,
        v6,
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
  ParkourHandleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleCondition::`vftable;
  v1->mDirection = 0.0;
  *(_QWORD *)&v1->mRelativeAngle = 1061752795i64;
  *(_QWORD *)&v1->mDistanceXYMax = 0i64;
  *(_QWORD *)&v1->mDistanceZMax = 0i64;
  *(_QWORD *)&v1->mMinDropoffHeight = 0x40000000i64;
  *(_QWORD *)&v1->mUseAimingDirection = 0x1000000i64;
  *(_DWORD *)&v1->mCheckWall = 0;
  *(_QWORD *)&v1->mCheckActionHijackClimb = 0x1000000i64;
  v1->mInEqualityOperator.mValue = 1;
  *(_WORD *)&v1->mCheckLeft = 0;
  v1->mCheckAttachedToVehicleType = 0;
  v1->mParentNode.mOffset = 0i64;
}

// File Line: 5682
// RVA: 0x294480
void __fastcall compareParkourHandles(unsigned int checkTypes, UFG::qVector3 *position, UFG::qVector3 *orientation, const float relativeAngle, const float bufferZone, const float distanceXYMin, const float distanceXYMax, const float distanceZMin, const float distanceZMax, UFG::qVector3 *contactPosition, UFG::ParkourHandle *currentHandle, UFG::ParkourHandle **closestParkHandle, float *currentDistanceTo, bool *currentInSegment)
{
  UFG::qVector3 *v14; // rdi
  UFG::qVector3 *v15; // r15
  unsigned int v16; // ebx
  UFG::ParkourHandle *v17; // r14
  int v18; // eax
  char v19; // si
  float v20; // xmm13_4
  float v21; // xmm14_4
  float v22; // xmm11_4
  float v23; // xmm0_4
  float v24; // xmm15_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm7_4
  bool v28; // r12
  float v29; // xmm7_4
  float v30; // xmm15_4
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  UFG::ParkourHandle *v34; // rcx
  float v35; // xmm2_4
  __m128 v36; // xmm12
  float v37; // xmm14_4
  float v38; // xmm11_4
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm9
  float v42; // xmm10_4
  float v43; // xmm13_4
  float v44; // xmm10_4
  float v45; // xmm0_4
  float v46; // xmm12_4
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  float v49; // xmm1_4
  float v50; // xmm12_4
  float v51; // xmm3_4
  float v52; // xmm5_4
  __m128 v53; // xmm4
  float v54; // xmm6_4
  float v55; // xmm3_4
  float v56; // xmm4_4
  bool v57; // al
  char v58; // cl
  Render::DebugDrawContext *v59; // r13
  float v60; // xmm5_4
  float v61; // xmm12_4
  float v62; // xmm14_4
  __m128 v63; // xmm1
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm0_4
  UFG::qVector3 *v67; // rax
  UFG::qVector3 dest; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 p1; // [rsp+50h] [rbp-B0h]
  float v70; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 result; // [rsp+68h] [rbp-98h]
  UFG::qVector3 axis; // [rsp+78h] [rbp-88h]
  float v73; // [rsp+88h] [rbp-78h]
  float v74; // [rsp+8Ch] [rbp-74h]
  float v75; // [rsp+90h] [rbp-70h]
  float v76; // [rsp+94h] [rbp-6Ch]
  float v77; // [rsp+98h] [rbp-68h]
  UFG::qVector3 positiona; // [rsp+A0h] [rbp-60h]
  UFG::qVector3 out; // [rsp+B0h] [rbp-50h]
  __int64 v80; // [rsp+C0h] [rbp-40h]
  float halfLength; // [rsp+1B0h] [rbp+B0h]
  float radians; // [rsp+1C8h] [rbp+C8h]

  radians = relativeAngle;
  v80 = -2i64;
  v14 = orientation;
  v15 = position;
  v16 = checkTypes;
  v17 = currentHandle;
  v18 = UFG::ParkourHandle::GetFlags(currentHandle);
  v19 = v18;
  if ( (!(v16 & 4) || !(v18 & 1))
    && (!(v16 & 8) || !(v18 & 4))
    && (!(v16 & 0x10) || !(v18 & 8))
    && (!(v16 & 2) || !(v18 & 2))
    && (!(v16 & 0x20) || !(v18 & 0x10))
    && (!(v16 & 0x40) || !(v18 & 0x20))
    && ((v16 & 0x80u) == 0 || !(v18 & 2))
    && (!_bittest((const signed int *)&v16, 8u) || !_bittest(&v18, 8u))
    && (!_bittest((const signed int *)&v16, 9u) || !(v18 & 0x40))
    || _bittest((const signed int *)&v16, 0xAu) && UFG::ParkourHandle::IsAttachedToVehicle(v17) )
  {
    return;
  }
  halfLength = 0.0;
  UFG::ParkourHandle::GetLayout(v17, &positiona, &axis, &halfLength);
  v70 = halfLength * 2.0;
  v20 = axis.z * halfLength;
  v21 = axis.y * halfLength;
  v22 = axis.x * halfLength;
  v23 = positiona.z - (float)(axis.z * halfLength);
  v73 = v23;
  v74 = positiona.y - (float)(axis.y * halfLength);
  v24 = positiona.x - (float)(axis.x * halfLength);
  v75 = v24;
  v25 = v15->z - v23;
  v26 = v15->y - v74;
  v27 = v15->x;
  p1.x = positiona.x - (float)(axis.x * halfLength);
  p1.y = positiona.y - (float)(axis.y * halfLength);
  p1.z = positiona.z - (float)(axis.z * halfLength);
  v28 = 0;
  v29 = (float)((float)((float)(v27 - v24) * axis.x) + (float)(axis.y * v26)) + (float)(axis.z * v25);
  v30 = FLOAT_N1_0;
  v31 = halfLength * 2.0;
  if ( v29 >= 0.0 )
  {
    if ( v29 <= v31 )
    {
      v28 = 1;
      p1.x = (float)(axis.x * v29) + v75;
      p1.y = (float)(axis.y * v29) + v74;
      p1.z = (float)(axis.z * v29) + v73;
      goto LABEL_38;
    }
    goto LABEL_25;
  }
  if ( v29 > v31 )
  {
LABEL_25:
    v32 = positiona.z + v20;
    v33 = positiona.y + v21;
    p1.x = v22 + positiona.x;
    v34 = v17->mCachedLeftNeighbor.m_pPointer;
    goto LABEL_28;
  }
  if ( v29 >= 0.0 )
    goto LABEL_37;
  v32 = positiona.z - v20;
  v33 = positiona.y - v21;
  p1.x = positiona.x - v22;
  v34 = v17->mCachedRightNeighbor.m_pPointer;
LABEL_28:
  p1.z = v32;
  p1.y = v33;
  if ( !v34 )
    goto LABEL_37;
  if ( !(_S10_1 & 1) )
  {
    _S10_1 |= 1u;
    kfMaxNeighborAngleDiff = FLOAT_0_34906587;
  }
  UFG::ParkourHandle::GetAxis(v34, &result);
  v35 = (float)((float)(result.x * axis.x) + (float)(result.y * axis.y)) + (float)(result.z * axis.z);
  if ( v35 <= -1.0 )
  {
    v35 = FLOAT_N1_0;
  }
  else if ( v35 >= 1.0 )
  {
    v35 = *(float *)&FLOAT_1_0;
  }
  if ( acosf(v35) >= kfMaxNeighborAngleDiff )
  {
LABEL_37:
    if ( sInParkourSegmentOnly )
      return;
    goto LABEL_38;
  }
  v28 = 1;
LABEL_38:
  v36 = (__m128)LODWORD(p1.x);
  v36.m128_f32[0] = p1.x - v15->x;
  v70 = p1.x - v15->x;
  v37 = p1.y - v15->y;
  v77 = p1.y - v15->y;
  v38 = p1.z - v15->z;
  if ( (float)(distanceZMin - 0.050000001) > v38 )
    return;
  if ( (float)(distanceZMax + 0.050000001) < v38 )
    return;
  v39 = v36;
  v39.m128_f32[0] = v36.m128_f32[0] * v36.m128_f32[0];
  v40 = v39;
  v40.m128_f32[0] = (float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v37 * v37);
  v41 = _mm_sqrt_ps(v40);
  if ( v41.m128_f32[0] <= 0.000099999997 || distanceXYMin > v41.m128_f32[0] || distanceXYMax < v41.m128_f32[0] )
    return;
  v39.m128_f32[0] = v39.m128_f32[0] + (float)(v37 * v37);
  if ( v39.m128_f32[0] == 0.0 )
    v42 = 0.0;
  else
    v42 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v39));
  v43 = v42 * v36.m128_f32[0];
  v44 = v42 * v37;
  v45 = (float)(v43 * v14->x) + (float)(v44 * v14->y);
  UFG::qACos(v45);
  v76 = v45;
  if ( radians < v45 )
  {
    if ( bufferZone <= 0.0 )
      return;
    UFG::qRotateVectorZ(&result, v14, radians);
    UFG::qRotateVectorZ(&dest, v14, COERCE_FLOAT(LODWORD(radians) ^ _xmm[0]));
    v47 = (__m128)LODWORD(result.z);
    v46 = (float)(result.y * UFG::qVector3::msDirUp.z) - (float)(result.z * UFG::qVector3::msDirUp.y);
    v47.m128_f32[0] = (float)(result.z * UFG::qVector3::msDirUp.x) - (float)(result.x * UFG::qVector3::msDirUp.z);
    v48 = v47;
    v48.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v46 * v46))
                    + (float)((float)((float)(result.x * UFG::qVector3::msDirUp.y)
                                    - (float)(result.y * UFG::qVector3::msDirUp.x))
                            * (float)((float)(result.x * UFG::qVector3::msDirUp.y)
                                    - (float)(result.y * UFG::qVector3::msDirUp.x)));
    v49 = v48.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v48));
    v50 = v46 * v49;
    v51 = v47.m128_f32[0] * v49;
    v52 = (float)(dest.z * UFG::qVector3::msDirUp.y) - (float)(dest.y * UFG::qVector3::msDirUp.z);
    v53 = (__m128)LODWORD(dest.x);
    v53.m128_f32[0] = (float)(dest.x * UFG::qVector3::msDirUp.z) - (float)(dest.z * UFG::qVector3::msDirUp.x);
    v54 = (float)((float)((float)(v53.m128_f32[0] * v53.m128_f32[0]) + (float)(v52 * v52))
                + (float)((float)((float)(dest.y * UFG::qVector3::msDirUp.x) - (float)(dest.x * UFG::qVector3::msDirUp.y))
                        * (float)((float)(dest.y * UFG::qVector3::msDirUp.x) - (float)(dest.x * UFG::qVector3::msDirUp.y)))) == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v53));
    v55 = (float)(v51 * v44) + (float)(v50 * v43);
    v56 = (float)((float)(v53.m128_f32[0] * v54) * v44) + (float)((float)(v52 * v54) * v43);
    v57 = (float)((float)(result.y * v44) + (float)(result.x * v43)) > 0.0 && v55 > 0.0 && v55 < bufferZone;
    v58 = (float)((float)(dest.y * v44) + (float)(dest.x * v43)) <= 0.0 || v56 <= 0.0 || v56 >= bufferZone ? 0 : 1;
    if ( !((unsigned __int8)v58 | v57) )
      return;
    v36.m128_f32[0] = v70;
    v37 = v77;
    v30 = FLOAT_N1_0;
  }
  if ( gDebugPark && v28 )
  {
    v59 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawLine(v59, v15, &p1, &UFG::qColour::Yellow, &UFG::qMatrix44::msIdentity, 0i64, 0);
    dest.x = v15->x + v14->x;
    dest.y = v15->y + v14->y;
    dest.z = v14->z + v15->z;
    Render::DebugDrawContext::DrawLine(v59, v15, &dest, &UFG::qColour::Green, &UFG::qMatrix44::msIdentity, 0i64, 0);
    dest.x = v36.m128_f32[0] + v15->x;
    dest.y = v37 + v15->y;
    dest.z = v15->z;
    Render::DebugDrawContext::DrawLine(v59, v15, &dest, &UFG::qColour::Red, &UFG::qMatrix44::msIdentity, 0i64, 0);
    result.x = p1.x;
    result.y = p1.y;
    result.z = v15->z;
    Render::DebugDrawContext::DrawLine(v59, &result, &p1, &UFG::qColour::Blue, &UFG::qMatrix44::msIdentity, 0i64, 0);
    v60 = p1.z - v15->z;
    dest.x = p1.x - (float)((float)((float)(p1.z - v15->z) * UFG::qVector3::msAxisZ.x) * 0.5);
    dest.y = p1.y - (float)((float)(v60 * UFG::qVector3::msAxisZ.y) * 0.5);
    dest.z = p1.z - (float)((float)(v60 * UFG::qVector3::msAxisZ.z) * 0.5);
    Render::DebugDrawContext::DrawText(v59, &dest, &UFG::qColour::Blue, "distZ:%0.3f", v60);
    v61 = v36.m128_f32[0] * 0.5;
    v62 = v37 * 0.5;
    dest.x = v61 + v15->x;
    dest.y = v62 + v15->y;
    dest.z = v15->z;
    Render::DebugDrawContext::DrawText(v59, &dest, &UFG::qColour::Red, "distXY:%0.3f", v41.m128_f32[0]);
    dest.x = v61 + v15->x;
    dest.y = v62 + v15->y;
    dest.z = (float)(v38 * 0.5) + v15->z;
    v63 = v41;
    v63.m128_f32[0] = (float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v38 * v38);
    Render::DebugDrawContext::DrawText(v59, &dest, &UFG::qColour::Yellow, "dist:%0.3f", COERCE_FLOAT(_mm_sqrt_ps(v63)));
    v64 = (float)(v76 * 180.0) * 0.31830987;
    if ( (float)((float)(v44 * v14->x) + (float)(v43 * v14->y)) < 0.0 )
      v64 = 360.0 - v64;
    Render::DebugDrawContext::DrawText(v59, &result, &UFG::qColour::Green, "Dir:%0.3f", v64);
  }
  if ( (v16 & 0x80u) != 0 && v19 & 2 )
  {
    v14->x = v14->x * v30;
    v14->y = v14->y * v30;
    v14->z = v14->z * v30;
  }
  if ( !UFG::ParkourHandle::GetNormal(v17, &out)
    || (v65 = (float)(out.x * v14->x) + (float)(out.y * v14->y), UFG::qACos(v65), v65 > (float)(3.1415927 - radians)) )
  {
    v41.m128_f32[0] = (float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v38 * v38);
    LODWORD(v66) = (unsigned __int128)_mm_sqrt_ps(v41);
    if ( v28 && v66 < *currentDistanceTo )
    {
      *currentDistanceTo = v66;
      *closestParkHandle = v17;
      *currentInSegment = v28;
      v67 = contactPosition;
      if ( contactPosition )
      {
        contactPosition->x = (float)(axis.x * v29) + v75;
        v67->y = (float)(axis.y * v29) + v74;
        v67->z = (float)(axis.z * v29) + v73;
      }
    }
  }
}

// File Line: 6020
// RVA: 0x294F40
void __fastcall getParkourEdgeConstraints(UFG::ParkourHandle *pParkourHandle, const bool constrainLeftEdge, const bool constrainRightEdge, const float fDistToLeft, const float fDistToRight, float *fLeftConstraint, float *fRightConstraint)
{
  bool v7; // bl
  bool v8; // di
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4

  v7 = constrainRightEdge;
  v8 = constrainLeftEdge;
  v9 = fDistToLeft;
  if ( constrainLeftEdge || constrainRightEdge )
  {
    v10 = fDistToRight;
    v11 = UFG::ParkourHandle::GetHalfLength(pParkourHandle) * 2.0;
    if ( v8 )
    {
      if ( v7 )
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
      if ( v7 && fDistToRight > v11 )
        v10 = v11;
      v9 = 0.0;
    }
    *fLeftConstraint = v9;
    if ( !v7 )
      v10 = 0.0;
    *fRightConstraint = v10;
  }
}

// File Line: 6087
// RVA: 0x27B370
UFG::ParkourHandle *__fastcall ParkourHandleCondition::FindClosestParkourHandle(UFG::SensorComponent *sensor_component, UFG::qVector3 *position, UFG::qVector3 *orientationVector, const float relativeAngle, const float bufferZone, const float distanceXYMin, const float distanceXYMax, const float distanceZMin, const float distanceZMax, UFG::eSimObjectVehicleTypeEnum checkAttachedToVehicleType, unsigned int check, UFG::qVector3 *contactPosition, bool debugMessageActive)
{
  int *v13; // rbp
  UFG::qVector3 *v14; // r13
  UFG::SensorComponent *v15; // rdi
  UFG::ParkourHandle *v16; // rbx
  UFG::SimObject *v17; // rax
  unsigned int v18; // er14
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
  UFG::SimObjectCVBase *v29; // rcx
  unsigned __int16 v30; // dx
  UFG::SimObjectVehiclePropertiesComponent *v31; // rax
  int v32; // xmm1_4
  int v33; // xmm2_4
  UFG::ParkourHandle *result; // rax
  float v35; // [rsp+80h] [rbp-48E8h]
  UFG::ParkourHandle *v36; // [rsp+88h] [rbp-48E0h]
  int v37; // [rsp+90h] [rbp-48D8h]
  int v38; // [rsp+94h] [rbp-48D4h]
  int v39; // [rsp+98h] [rbp-48D0h]
  __int64 v40; // [rsp+A0h] [rbp-48C8h]
  UFG::qVector3 vmax; // [rsp+A8h] [rbp-48C0h]
  UFG::qVector3 vmin; // [rsp+B8h] [rbp-48B0h]
  UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> out; // [rsp+D0h] [rbp-4898h]
  char v44; // [rsp+4970h] [rbp+8h]

  v40 = -2i64;
  v13 = (int *)orientationVector;
  v14 = position;
  v15 = sensor_component;
  v16 = 0i64;
  v36 = 0i64;
  v35 = FLOAT_3_4028235e38;
  if ( !sensor_component )
    goto LABEL_31;
  v17 = sensor_component->m_pSimObject;
  if ( v17 )
  {
    if ( (v17->m_Flags >> 10) & 1 )
      goto LABEL_31;
  }
  UFG::SensorComponent::GetExtents(sensor_component, &vmin, &vmax);
  v18 = check;
  if ( !(check & 1) )
    goto LABEL_31;
  `eh vector constructor iterator(
    out.p,
    0x18ui64,
    768,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  out.size = 0;
  UFG::SensorComponent::GetParkourHandles(v15, &out);
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
          || (v29 = (UFG::SimObjectCVBase *)v28->mSimObject.m_pPointer) == 0i64
          || ((v30 = v29->m_Flags, !((v30 >> 14) & 1)) ? ((v30 & 0x8000u) == 0 ? (!((v30 >> 13) & 1) ? (!((v30 >> 12) & 1) ? (v31 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v29->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID)) : (v31 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v29->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v31 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v29->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v31 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v29))) : (v31 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v29)),
              !v31 || v31->m_eSimObjectVehicleType == v22) )
        {
          v32 = v13[1];
          v33 = v13[2];
          v37 = *v13;
          v38 = v32;
          v39 = v33;
          compareParkourHandles(
            v18,
            v14,
            (UFG::qVector3 *)&v37,
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
            (bool *)&v44,
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
    result = v16;
  else
LABEL_31:
    result = 0i64;
  return result;
}

// File Line: 6163
// RVA: 0x2869E0
char __fastcall ParkourHandleCondition::Match(ParkourHandleCondition *this, ActionContext *context)
{
  ActionContext *v2; // r13
  ParkourHandleCondition *v3; // rbx
  char v4; // r12
  UFG::SimObjectGame *v5; // rcx
  ActionNode *v6; // rsi
  UFG::SensorComponent *v7; // r15
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectCVBase *v10; // rcx
  UFG::CharacterAnimationComponent *v11; // rax
  unsigned __int16 v12; // dx
  UFG::SimObject *v13; // rdi
  UFG::TransformNodeComponent *v14; // rdi
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::SimObjectGame *v19; // rcx
  UFG::AimingBaseComponent *v20; // rax
  unsigned __int16 v21; // dx
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  float v24; // xmm5_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  int v28; // xmm1_4
  float v29; // xmm2_4
  UFG::SimObjectCVBase *v30; // rcx
  UFG::AICharacterControllerBaseComponent *v31; // rax
  unsigned __int16 v32; // dx
  UFG::SimObjectGame *v33; // rcx
  unsigned __int16 v34; // dx
  UFG::SimComponent *v35; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // r14
  _DWORD *v37; // rax
  float v39; // edx
  float v40; // eax
  UFG::ParkourHandle *v41; // r14
  float v42; // xmm8_4
  __m128 v43; // xmm12
  __m128 v44; // xmm2
  float v45; // xmm3_4
  float v46; // xmm9_4
  float v47; // xmm10_4
  float v48; // xmm3_4
  __m128 v49; // xmm4
  __m128 v50; // xmm5
  float v51; // xmm1_4
  float v52; // xmm5_4
  float v53; // xmm15_4
  __m128 v54; // xmm11
  __m128 v55; // xmm5
  float v56; // xmm0_4
  __int128 v57; // xmm5
  float v58; // xmm1_4
  float v59; // xmm5_4
  float v60; // xmm11_4
  float v61; // xmm5_4
  __int128 v62; // xmm15
  __m128 v63; // xmm3
  float v64; // xmm3_4
  float v65; // xmm15_4
  float v66; // xmm2_4
  float v67; // xmm5_4
  float v68; // xmm8_4
  float v69; // xmm2_4
  float v70; // xmm0_4
  __int128 v71; // xmm4
  float v72; // xmm1_4
  float v73; // xmm4_4
  float v74; // xmm10_4
  float v75; // xmm11_4
  __int128 v76; // xmm3
  __m128 v77; // xmm4
  float v78; // xmm4_4
  float v79; // xmm9_4
  float v80; // xmm1_4
  float v81; // xmm4_4
  float v82; // xmm9_4
  __m128 v83; // xmm2
  float v84; // xmm7_4
  Render::DebugDrawContext *v85; // r15
  float v86; // xmm5_4
  float v87; // xmm3_4
  float v88; // xmm0_4
  __int64 v89; // rax
  __int64 v90; // rax
  ActionNode *v91; // rcx
  float v92; // xmm0_4
  float v93; // xmm2_4
  char *v94; // rax
  int v95; // edx
  float v96; // xmm2_4
  float v97; // xmm1_4
  UFG::SimObjectGame *v98; // rcx
  unsigned __int16 v99; // dx
  UFG::WorldContextComponent *v100; // rax
  __int64 v101; // rcx
  float v102; // xmm9_4
  float v103; // xmm11_4
  float v104; // xmm10_4
  float v105; // xmm0_4
  UFG::qVector3 *v106; // rax
  float v107; // xmm6_4
  float v108; // xmm7_4
  float v109; // xmm8_4
  UFG::qVector3 *v110; // rax
  float v111; // xmm9_4
  float v112; // xmm11_4
  float v113; // xmm10_4
  UFG::qVector3 *v114; // rax
  float v115; // xmm11_4
  float v116; // xmm0_4
  UFG::qVector3 dest; // [rsp+48h] [rbp-80h]
  UFG::qVector3 vAimDirection; // [rsp+58h] [rbp-70h]
  UFG::qVector3 p1; // [rsp+68h] [rbp-60h]
  float v120; // [rsp+74h] [rbp-54h]
  float v121; // [rsp+78h] [rbp-50h]
  float v122; // [rsp+7Ch] [rbp-4Ch]
  float v123; // [rsp+80h] [rbp-48h]
  ActionPath pathToPopulate; // [rsp+88h] [rbp-40h]
  UFG::qColour colour; // [rsp+98h] [rbp-30h]
  UFG::qMatrix44 v126; // [rsp+A8h] [rbp-20h]
  UFG::qMatrix44 local_world; // [rsp+E8h] [rbp+20h]
  UFG::qVector3 contactPosition; // [rsp+128h] [rbp+60h]
  __int64 v129; // [rsp+138h] [rbp+70h]
  float v130; // [rsp+230h] [rbp+168h]
  float v131; // [rsp+238h] [rbp+170h]

  v129 = -2i64;
  v2 = context;
  v3 = this;
  v4 = 0;
  v5 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v6 = 0i64;
  if ( v5 )
  {
    v8 = v5->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = (UFG::SensorComponent *)v5->m_Components.p[26].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::SensorComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::SensorComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::SensorComponent::_TypeUID);
      }
      v7 = (UFG::SensorComponent *)v9;
    }
    else
    {
      v7 = (UFG::SensorComponent *)v5->m_Components.p[26].m_pComponent;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v10 = (UFG::SimObjectCVBase *)v2->mSimObject.m_pPointer;
  if ( v10 )
  {
    v12 = v10->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v11 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v11 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v10->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v10->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
    }
  }
  else
  {
    v11 = 0i64;
  }
  v13 = v2->mSimObject.m_pPointer;
  if ( v13 )
    v14 = v13->m_pTransformNodeComponent;
  else
    v14 = 0i64;
  if ( !v7 || !v11 || !v14 )
    return v4;
  UFG::TransformNodeComponent::UpdateWorldTransform(v14);
  v15 = v14->mWorldTransform.v3.y;
  v16 = v14->mWorldTransform.v3.z;
  v121 = v14->mWorldTransform.v3.x;
  v122 = v15;
  v123 = v16;
  v17 = v14->mWorldTransform.v0.y;
  v18 = v14->mWorldTransform.v0.z;
  vAimDirection.x = v14->mWorldTransform.v0.x;
  vAimDirection.y = v17;
  vAimDirection.z = v18;
  if ( v3->mUseAimingDirection )
  {
    v19 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v19 )
    {
      v21 = v19->m_Flags;
      if ( (v21 >> 14) & 1 )
      {
        v20 = (UFG::AimingBaseComponent *)v19->m_Components.p[47].m_pComponent;
      }
      else if ( (v21 & 0x8000u) == 0 )
      {
        if ( (v21 >> 13) & 1 )
        {
          v20 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v19,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
        else if ( (v21 >> 12) & 1 )
        {
          v20 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v19,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v20 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v19->vfptr,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
      }
      else
      {
        v20 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v19,
                                            UFG::AimingBaseComponent::_TypeUID);
      }
    }
    else
    {
      v20 = 0i64;
    }
    UFG::AimingBaseComponent::GetAimDirection(v20, &vAimDirection, 0i64);
    vAimDirection.z = 0.0;
    v22 = (__m128)LODWORD(vAimDirection.y);
    v23 = v22;
    v23.m128_f32[0] = (float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(vAimDirection.x * vAimDirection.x);
    LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v23);
    if ( v24 <= 0.001 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v14);
      v25 = v14->mWorldTransform.v0.y;
      v26 = v14->mWorldTransform.v0.z;
      p1.z = v14->mWorldTransform.v0.x;
      v120 = v25;
      v121 = v26;
    }
    else
    {
      p1.z = (float)(1.0 / v24) * vAimDirection.x;
      v120 = (float)(1.0 / v24) * vAimDirection.y;
      v121 = (float)(1.0 / v24) * 0.0;
    }
    v27 = p1.z;
    v28 = LODWORD(v120);
    v29 = v121;
  }
  else if ( v3->mUseMotionIntention )
  {
    v30 = (UFG::SimObjectCVBase *)v2->mSimObject.m_pPointer;
    if ( v30 )
    {
      v32 = v30->m_Flags;
      if ( (v32 >> 14) & 1 )
      {
        v31 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v30);
      }
      else if ( (v32 & 0x8000u) == 0 )
      {
        if ( (v32 >> 13) & 1 )
        {
          v31 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v30->vfptr,
                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else if ( (v32 >> 12) & 1 )
        {
          v31 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v30->vfptr,
                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          v31 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v30->vfptr,
                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
      }
      else
      {
        v31 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v30);
      }
    }
    else
    {
      v31 = 0i64;
    }
    v27 = v31->m_Intention.mMotionIntentionDirection.x;
    v28 = LODWORD(v31->m_Intention.mMotionIntentionDirection.y);
    v29 = v31->m_Intention.mMotionIntentionDirection.z;
  }
  else
  {
    if ( !v3->mUseCoverDirection )
      goto LABEL_78;
    v33 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v33
      && ((v34 = v33->m_Flags, !((v34 >> 14) & 1)) ? ((v34 & 0x8000u) == 0 ? (!((v34 >> 13) & 1) ? (!((v34 >> 12) & 1) ? (v35 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v33->vfptr, UFG::AICoverComponent::_TypeUID)) : (v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::AICoverComponent::_TypeUID))) : (v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::AICoverComponent::_TypeUID))) : (v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::AICoverComponent::_TypeUID))) : (v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::AICoverComponent::_TypeUID)),
          v35) )
    {
      v36 = v35[1].m_BoundComponentHandles.mNode.mPrev;
    }
    else
    {
      v36 = 0i64;
    }
    if ( !v36
      || !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v36->mPrev[1].mPrev)(v36) )
    {
      return 0;
    }
    v37 = (_DWORD *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::qVector3 *))v36->mPrev[10].mPrev)(
                      v36,
                      &p1);
    LODWORD(v29) = v37[2] ^ _xmm[0];
    v28 = v37[1] ^ _xmm[0];
    LODWORD(v27) = *v37 ^ _xmm[0];
  }
  vAimDirection.x = v27;
  LODWORD(vAimDirection.y) = v28;
  vAimDirection.z = v29;
LABEL_78:
  UFG::qRotateVectorZ(&dest, &vAimDirection, v3->mDirection);
  LODWORD(v39) = (v3->mCheckLedgeDropoff != 0 ? 0x80 : 0) | (v3->mCheckParkourHandle != 0) | (v3->mCheckLedge != 0 ? 2 : 0) | (v3->mCheckFence != 0 ? 4 : 0) | (v3->mCheckVault != 0 ? 8 : 0) | (v3->mCheckRail != 0 ? 0x10 : 0) | (v3->mCheckWall != 0 ? 0x20 : 0) | (v3->mCheckLeap != 0 ? 0x40 : 0) | (v3->mCheckActionHijackClimb != 0 ? 0x100 : 0) | (v3->mCheckCover != 0 ? 0x200 : 0) | (v3->mCheckNotVehicle != 0 ? 0x400 : 0);
  v40 = *(float *)&v3->mCheckAttachedToVehicleType;
  LOBYTE(vAimDirection.z) = 0;
  *(_QWORD *)&vAimDirection.x = &contactPosition;
  dest.z = v39;
  dest.x = v40;
  v41 = ParkourHandleCondition::FindClosestParkourHandle(
          v7,
          (UFG::qVector3 *)&v121,
          &dest,
          v3->mRelativeAngle,
          v3->mBufferZone,
          v3->mDistanceXYMin,
          v3->mDistanceXYMax,
          v3->mDistanceZMin,
          v3->mDistanceZMax,
          SLODWORD(v40),
          LODWORD(v39),
          &contactPosition,
          0);
  if ( !UFG::WorldContextComponent::s_DrawParkourSensing )
    goto LABEL_120;
  if ( UFG::WorldContextComponent::s_DrawParkourSensingSuccessFilter == 1 )
  {
    if ( !v41 )
      return v4;
  }
  else if ( UFG::WorldContextComponent::s_DrawParkourSensingSuccessFilter )
  {
    goto LABEL_120;
  }
  colour.r = 1.0;
  *(_QWORD *)&colour.g = 1065353216i64;
  colour.a = 0.5;
  pathToPopulate.mPath.mCount = 0;
  *((float *)&pathToPopulate.mPath.mCount + 1) = FLOAT_0_55000001;
  pathToPopulate.mPath.mData.mOffset = 4539628424389459968i64;
  _mm_store_si128((__m128i *)&colour, (__m128i)colour);
  if ( v41 )
    _mm_store_si128((__m128i *)&colour, (__m128i)pathToPopulate);
  v42 = (float)(sVertFudge + v3->mDistanceZMin) + v123;
  v43 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v44 = v43;
  v44.m128_f32[0] = (float)((float)(v43.m128_f32[0] * v43.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v44.m128_f32[0] == 0.0 )
    v45 = 0.0;
  else
    v45 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
  v46 = v45 * UFG::qVector3::msDirUp.z;
  v47 = v45 * UFG::qVector3::msDirUp.y;
  v48 = v45 * UFG::qVector3::msDirUp.x;
  local_world.v0.x = v48;
  local_world.v0.y = v47;
  local_world.v0.z = v46;
  local_world.v0.w = 0.0;
  v49 = (__m128)LODWORD(dest.x);
  v49.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(dest.y * dest.y))
                  + (float)(dest.z * dest.z);
  if ( v49.m128_f32[0] == 0.0 )
  {
    v50 = 0i64;
  }
  else
  {
    v50 = (__m128)(unsigned int)FLOAT_1_0;
    v50.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v49));
  }
  v51 = v50.m128_f32[0] * dest.z;
  v54 = v50;
  v54.m128_f32[0] = v50.m128_f32[0] * dest.y;
  v52 = v50.m128_f32[0] * dest.x;
  v53 = (float)(v47 * v52) - (float)(v54.m128_f32[0] * v48);
  v131 = (float)(v47 * v52) - (float)(v54.m128_f32[0] * v48);
  v130 = (float)(v51 * v48) - (float)(v46 * v52);
  v54.m128_f32[0] = (float)(v54.m128_f32[0] * v46) - (float)(v51 * v47);
  v55 = v54;
  v55.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v130 * v130)) + (float)(v53 * v53);
  if ( v55.m128_f32[0] == 0.0 )
  {
    v57 = 0i64;
  }
  else
  {
    LODWORD(v56) = (unsigned __int128)_mm_sqrt_ps(v55);
    v57 = (unsigned int)FLOAT_1_0;
    *(float *)&v57 = 1.0 / v56;
  }
  v62 = v57;
  *(float *)&v62 = *(float *)&v57 * v131;
  v58 = *(float *)&v57 * v130;
  v59 = *(float *)&v57 * v54.m128_f32[0];
  local_world.v1.x = v59;
  local_world.v1.y = v58;
  LODWORD(local_world.v1.z) = v62;
  local_world.v1.w = 0.0;
  v60 = (float)(v58 * v48) - (float)(v59 * v47);
  v61 = (float)(v59 * v46) - (float)(*(float *)&v62 * v48);
  *(float *)&v62 = (float)(*(float *)&v62 * v47) - (float)(v58 * v46);
  v63 = (__m128)v62;
  v63.m128_f32[0] = (float)((float)(*(float *)&v62 * *(float *)&v62) + (float)(v61 * v61)) + (float)(v60 * v60);
  if ( v63.m128_f32[0] == 0.0 )
    v64 = 0.0;
  else
    v64 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v63));
  local_world.v2.x = v64 * *(float *)&v62;
  local_world.v2.y = v64 * v61;
  local_world.v2.z = v64 * v60;
  local_world.v2.w = 0.0;
  local_world.v3.x = v121;
  local_world.v3.y = v122;
  local_world.v3.z = v42;
  local_world.v3.w = 1.0;
  v65 = (float)(sVertFudge + v3->mDistanceZMax) + v123;
  if ( v44.m128_f32[0] == 0.0 )
    v66 = 0.0;
  else
    v66 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
  v67 = v66 * UFG::qVector3::msDirUp.z;
  v68 = v66 * UFG::qVector3::msDirUp.y;
  v69 = v66 * UFG::qVector3::msDirUp.x;
  v126.v0.x = v69;
  v126.v0.y = v68;
  v126.v0.z = v67;
  v126.v0.w = 0.0;
  if ( v49.m128_f32[0] == 0.0 )
  {
    v71 = 0i64;
  }
  else
  {
    LODWORD(v70) = (unsigned __int128)_mm_sqrt_ps(v49);
    v71 = (unsigned int)FLOAT_1_0;
    *(float *)&v71 = 1.0 / v70;
  }
  v72 = *(float *)&v71 * dest.z;
  v76 = v71;
  *(float *)&v76 = *(float *)&v71 * dest.y;
  v73 = *(float *)&v71 * dest.x;
  v74 = (float)(v68 * v73) - (float)(*(float *)&v76 * v69);
  v75 = (float)(v72 * v69) - (float)(v67 * v73);
  *(float *)&v76 = (float)(*(float *)&v76 * v67) - (float)(v72 * v68);
  v77 = (__m128)v76;
  v77.m128_f32[0] = (float)((float)(*(float *)&v76 * *(float *)&v76) + (float)(v75 * v75)) + (float)(v74 * v74);
  if ( v77.m128_f32[0] == 0.0 )
    v78 = 0.0;
  else
    v78 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v77));
  v79 = v78 * v74;
  v80 = v78 * v75;
  *(float *)&v76 = *(float *)&v76 * v78;
  LODWORD(v126.v1.x) = v76;
  v126.v1.y = v78 * v75;
  v126.v1.z = v79;
  v126.v1.w = 0.0;
  v81 = (float)((float)(v78 * v75) * v69) - (float)(*(float *)&v76 * v68);
  *(float *)&v76 = (float)(*(float *)&v76 * v67) - (float)(v79 * v69);
  v82 = (float)(v79 * v68) - (float)(v80 * v67);
  v83 = (__m128)v76;
  v83.m128_f32[0] = (float)((float)(*(float *)&v76 * *(float *)&v76) + (float)(v82 * v82)) + (float)(v81 * v81);
  if ( v83.m128_f32[0] == 0.0 )
    v84 = 0.0;
  else
    v84 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v83));
  v126.v2.x = v84 * v82;
  v126.v2.y = v84 * *(float *)&v76;
  v126.v2.z = v84 * v81;
  v126.v2.w = 0.0;
  v126.v3.x = v121;
  v126.v3.y = v122;
  v126.v3.z = v65;
  v126.v3.w = 1.0;
  v85 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawContext::DrawArc(
    v85,
    v3->mDistanceXYMax,
    COERCE_CONST_FLOAT(LODWORD(v3->mRelativeAngle) ^ _xmm[0]),
    v3->mRelativeAngle,
    &colour,
    &local_world,
    0i64);
  Render::DebugDrawContext::DrawArc(
    v85,
    v3->mDistanceXYMax,
    COERCE_CONST_FLOAT(LODWORD(v3->mRelativeAngle) ^ _xmm[0]),
    v3->mRelativeAngle,
    &colour,
    &v126,
    0i64);
  v86 = (float)(sVertFudge + v3->mDistanceZMin) + v123;
  p1.z = v121;
  v120 = v122;
  v121 = v86;
  v87 = (float)(v3->mDistanceXYMax * dest.z) + v86;
  v88 = (float)(v3->mDistanceXYMax * dest.y) + v122;
  p1.x = (float)(v3->mDistanceXYMax * dest.x) + p1.z;
  p1.y = v88;
  p1.z = v87;
  Render::DebugDrawContext::DrawLine(
    v85,
    (UFG::qVector3 *)((char *)&p1 + 8),
    &p1,
    &UFG::qColour::Blue,
    &UFG::qMatrix44::msIdentity,
    0i64,
    0);
  v89 = v3->mParentNode.mOffset;
  if ( v89 && (UFG::qOffset64<ActionNode *> *)((char *)&v3->mParentNode + v89) )
  {
    pathToPopulate.mPath.mCount = 0;
    pathToPopulate.mPath.mData.mOffset = 0i64;
    v90 = v3->mParentNode.mOffset;
    if ( v90 )
      v91 = (ActionNode *)((char *)&v3->mParentNode + v90);
    else
      v91 = 0i64;
    ActionNode::GetNameFullPath(v91, &pathToPopulate);
    v92 = v3->mDistanceXYMax;
    v93 = (float)(v3->mDistanceXYMax * dest.z) + v121;
    p1.x = (float)(v3->mDistanceXYMax * dest.x) + p1.z;
    p1.y = (float)(v92 * dest.y) + v120;
    p1.z = v93;
    v94 = ActionPath::GetString_DBG(&pathToPopulate);
    Render::DebugDrawContext::DrawText(v85, &p1, &colour, "match:%s", v94);
    v95 = pathToPopulate.mPath.mCount;
    if ( pathToPopulate.mPath.mCount >= 0 )
    {
      if ( pathToPopulate.mPath.mData.mOffset
        && (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
        v95 = pathToPopulate.mPath.mCount;
      }
      pathToPopulate.mPath.mData.mOffset = 0i64;
      pathToPopulate.mPath.mCount = v95 & 0x80000000;
    }
  }
  else
  {
    v96 = v3->mDistanceXYMax;
    v97 = v3->mDistanceXYMax;
    p1.x = (float)(v3->mDistanceXYMax * dest.x) + p1.z;
    p1.y = (float)(v97 * dest.y) + v120;
    p1.z = (float)(v96 * dest.z) + v121;
    Render::DebugDrawContext::DrawText(v85, &p1, &colour, "match:NULL NODE");
  }
LABEL_120:
  if ( v41 )
  {
    if ( !v3->mCheckLedgeDropoff
      || UFG::ParkourHandle::GetDropoffDistance(v41, &contactPosition, v3->mDropoffCastRadius) >= v3->mMinDropoffHeight )
    {
      v98 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
      if ( v98 )
      {
        v99 = v98->m_Flags;
        if ( (v99 >> 14) & 1 )
        {
          v100 = (UFG::WorldContextComponent *)v98->m_Components.p[28].m_pComponent;
        }
        else if ( (v99 & 0x8000u) == 0 )
        {
          if ( (v99 >> 13) & 1 )
            v100 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v98,
                                                   UFG::WorldContextComponent::_TypeUID);
          else
            v100 = (UFG::WorldContextComponent *)((v99 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v98,
                                                                      UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v98->vfptr, UFG::WorldContextComponent::_TypeUID));
        }
        else
        {
          v100 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v98,
                                                 UFG::WorldContextComponent::_TypeUID);
        }
        if ( v100 && v3->mSetFocusHandle )
        {
          v101 = v3->mParentNode.mOffset;
          if ( v101 )
            v6 = (ActionNode *)((char *)&v3->mParentNode + v101);
          UFG::WorldContextComponent::SetFocusParkourHandle(v100, v41, v6);
        }
      }
      v4 = 1;
      if ( v3->mCheckDistance )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v14);
        v102 = v14->mWorldTransform.v3.x;
        v103 = v14->mWorldTransform.v3.y;
        v104 = v14->mWorldTransform.v3.z;
        v105 = UFG::ParkourHandle::GetHalfLength(v41);
        v106 = UFG::ParkourHandle::GetAxis(v41, &p1);
        v107 = v105 * v106->x;
        v108 = v105 * v106->y;
        v109 = v105 * v106->z;
        v110 = UFG::ParkourHandle::GetPosition(v41, (UFG::qVector3 *)((char *)&p1 + 8));
        v111 = v102 - (float)(v110->x - v107);
        v112 = v103 - (float)(v110->y - v108);
        v113 = v104 - (float)(v110->z - v109);
        v114 = UFG::ParkourHandle::GetAxis(v41, &p1);
        v115 = (float)((float)(v112 * v114->y) + (float)(v111 * v114->x)) + (float)(v113 * v114->z);
        if ( v3->mCheckLeft )
          v4 = CompareFloat((UFG::InEqualityOperator)v3->mInEqualityOperator.mValue, v3->mEdgeDistance, v115);
        if ( v3->mCheckRight )
        {
          v116 = UFG::ParkourHandle::GetHalfLength(v41);
          v4 = CompareFloat(
                 (UFG::InEqualityOperator)v3->mInEqualityOperator.mValue,
                 v3->mEdgeDistance,
                 COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v116 * 2.0) - v115) & _xmm));
        }
      }
      return v4;
    }
    return 0;
  }
  return v4;
} & _xmm));
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
  ParkourHandleInfoCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleInfoCondition::`vftable;
  *(_WORD *)&v1->mCheckFocusHandle = 0;
  v1->mCheckLowCover = 0;
}

// File Line: 6431
// RVA: 0x287860
char __fastcall ParkourHandleInfoCondition::Match(ParkourHandleInfoCondition *this, ActionContext *pContext)
{
  ParkourHandleInfoCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::ParkourHandle *v7; // rbx
  bool v8; // r14
  bool v9; // bp
  UFG::SimObject *v10; // rax
  char v11; // di
  UFG::TransformNodeComponent *v12; // rsi
  float v13; // xmm9_4
  float v14; // xmm10_4
  float v15; // xmm13_4
  float v16; // xmm0_4
  float v17; // xmm11_4
  UFG::qVector3 *v18; // rax
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  UFG::qVector3 *v22; // rax
  float v23; // xmm1_4
  float v24; // xmm7_4
  float v25; // xmm9_4
  UFG::qVector3 *v26; // rax
  float v27; // xmm10_4
  float v28; // xmm7_4
  char v29; // cl
  char v30; // al
  float v31; // xmm7_4
  UFG::qVector3 result; // [rsp+20h] [rbp-A8h]
  UFG::qVector3 v34; // [rsp+2Ch] [rbp-9Ch]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[28].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::WorldContextComponent::_TypeUID);
  }
  else
  {
    v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
  }
  if ( !v6 )
    return 0;
  v7 = (UFG::ParkourHandle *)(v2->mCheckFocusHandle ? v6[5].vfptr : *(_QWORD *)&v6[5].m_TypeUID);
  if ( !v7 )
    return 0;
  v8 = v2->mCheckHighCover != 0;
  v9 = v2->mCheckLowCover != 0;
  if ( !v2->mCheckHighCover && !v2->mCheckLowCover )
    return 0;
  v10 = v4->mSimObject.m_pPointer;
  v11 = 0;
  v12 = 0i64;
  if ( v10 )
    v12 = v10->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v12);
  v13 = v12->mWorldTransform.v3.x;
  v14 = v12->mWorldTransform.v3.y;
  v15 = v12->mWorldTransform.v3.z;
  v16 = UFG::ParkourHandle::GetHalfLength(v7);
  v17 = v16 * 2.0;
  v18 = UFG::ParkourHandle::GetAxis(v7, &result);
  v19 = v16 * v18->x;
  v20 = v16 * v18->y;
  v21 = v16 * v18->z;
  v22 = UFG::ParkourHandle::GetPosition(v7, &v34);
  v23 = v22->y - v20;
  v24 = v22->z - v21;
  v25 = v13 - (float)(v22->x - v19);
  v26 = UFG::ParkourHandle::GetAxis(v7, &v34);
  v27 = (float)((float)((float)(v14 - v23) * v26->y) + (float)(v25 * v26->x)) + (float)((float)(v15 - v24) * v26->z);
  if ( v27 < 0.0 )
  {
    if ( v27 <= v17 )
      goto LABEL_25;
  }
  else if ( v27 <= v17 )
  {
    v24 = (float)(v27 * UFG::ParkourHandle::GetAxis(v7, &v34)->z) + v24;
    goto LABEL_25;
  }
  v28 = v16 * UFG::ParkourHandle::GetAxis(v7, &v34)->z;
  v24 = v28 + UFG::ParkourHandle::GetPosition(v7, &result)->z;
LABEL_25:
  v29 = 0;
  v30 = 0;
  v31 = v24 - v15;
  if ( v8 && v31 > 1.6 )
  {
    v29 = 0;
    if ( v31 < 6.0 )
      v29 = 1;
  }
  if ( v9 && v31 > 0.5 )
  {
    v30 = 0;
    if ( v31 < 1.6 )
      v30 = 1;
  }
  if ( v29 || v30 )
    v11 = 1;
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
void __fastcall ParkourHandleLatchedCloseToEdgeCondition::ParkourHandleLatchedCloseToEdgeCondition(ParkourHandleLatchedCloseToEdgeCondition *this)
{
  ParkourHandleLatchedCloseToEdgeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleLatchedCloseToEdgeCondition::`vftable;
  v1->mEdgeDistance = 0.0;
  *(_WORD *)&v1->mInEqualityOperator.mValue = 1;
  v1->mCheckRight = 0;
}

// File Line: 6561
// RVA: 0x287B50
char __fastcall ParkourHandleLatchedCloseToEdgeCondition::Match(ParkourHandleLatchedCloseToEdgeCondition *this, ActionContext *context)
{
  ParkourHandleLatchedCloseToEdgeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::ParkourHandle *v7; // rdi
  UFG::SimObject *v8; // rax
  UFG::TransformNodeComponent *v9; // rsi
  float v10; // xmm9_4
  float v11; // xmm11_4
  float v12; // xmm10_4
  float v13; // xmm0_4
  UFG::qVector3 *v14; // rax
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  UFG::qVector3 *v18; // rax
  float v19; // xmm9_4
  float v20; // xmm11_4
  float v21; // xmm10_4
  UFG::qVector3 *v22; // rax
  float v23; // xmm11_4
  float v25; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-88h]
  UFG::qVector3 v27; // [rsp+2Ch] [rbp-7Ch]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[28].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::WorldContextComponent::_TypeUID);
  }
  else
  {
    v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
  }
  if ( !v6 )
    return 0;
  v7 = *(UFG::ParkourHandle **)&v6[5].m_TypeUID;
  if ( !v7 )
    return 0;
  v8 = v4->mSimObject.m_pPointer;
  if ( v8 )
    v9 = v8->m_pTransformNodeComponent;
  else
    v9 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v10 = v9->mWorldTransform.v3.x;
  v11 = v9->mWorldTransform.v3.y;
  v12 = v9->mWorldTransform.v3.z;
  v13 = UFG::ParkourHandle::GetHalfLength(v7);
  v14 = UFG::ParkourHandle::GetAxis(v7, &result);
  v15 = v13 * v14->x;
  v16 = v13 * v14->y;
  v17 = v13 * v14->z;
  v18 = UFG::ParkourHandle::GetPosition(v7, &v27);
  v19 = v10 - (float)(v18->x - v15);
  v20 = v11 - (float)(v18->y - v16);
  v21 = v12 - (float)(v18->z - v17);
  v22 = UFG::ParkourHandle::GetAxis(v7, &v27);
  v23 = (float)((float)(v20 * v22->y) + (float)(v19 * v22->x)) + (float)(v21 * v22->z);
  if ( v2->mCheckLeft )
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
             v2->mEdgeDistance,
             v23);
  if ( !v2->mCheckRight )
    return 0;
  v25 = UFG::ParkourHandle::GetHalfLength(v7);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
           v2->mEdgeDistance,
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
  ParkourHandleOwnerIsCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleOwnerIsCondition::`vftable;
  v1->mSimObjectType = 0;
}

// File Line: 6618
// RVA: 0x287D70
bool __fastcall ParkourHandleOwnerIsCondition::Match(ParkourHandleOwnerIsCondition *this, ActionContext *context)
{
  ParkourHandleOwnerIsCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v6; // rcx
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rdx
  UFG::SimComponent *v10; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::WorldContextComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID))) : (v5 = v3->m_Components.p[28].m_pComponent),
        v5 && (v6 = v5[5].vfptr) != 0i64 && (v7 = (UFG::SimObjectGame *)v6[7].__vecDelDtor) != 0i64)
    && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::SimObjectPropertiesComponent::_TypeUID)) : (v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::SimObjectPropertiesComponent::_TypeUID)),
                                                                                             v9 = v10) : (v9 = v7->m_Components.p[4].m_pComponent)) : (v9 = v7->m_Components.p[3].m_pComponent)) : (v9 = v7->m_Components.p[3].m_pComponent),
        v9) )
  {
    result = LODWORD(v9[1].m_SafePointerList.mNode.mNext) == v2->mSimObjectType;
  }
  else
  {
    result = 0;
  }
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
  ParkourHandleSpeedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleSpeedCondition::`vftable;
  v1->mSpeedInEqualityOperator.mValue = 1;
  v1->mSpeed = 0.0;
}

// File Line: 6674
// RVA: 0x287E90
char __fastcall ParkourHandleSpeedCondition::Match(ParkourHandleSpeedCondition *this, ActionContext *context)
{
  ParkourHandleSpeedCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  float v4; // xmm6_4
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v7; // rcx
  void *(__fastcall *v8)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rbx
  __int64 v9; // rbx
  __m128 v10; // xmm2

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0.0;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[28].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::WorldContextComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
    }
    if ( v6 )
    {
      v7 = v6[5].vfptr;
      if ( v7 )
      {
        v8 = v7[7].__vecDelDtor;
        if ( v8 )
        {
          v9 = *((_QWORD *)v8 + 11);
          if ( v9 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
            v10 = (__m128)*(unsigned int *)(v9 + 260);
            v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0])
                                    + (float)(*(float *)(v9 + 256) * *(float *)(v9 + 256)))
                            + (float)(*(float *)(v9 + 264) * *(float *)(v9 + 264));
            LODWORD(v4) = (unsigned __int128)_mm_sqrt_ps(v10);
          }
        }
      }
    }
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v2->mSpeedInEqualityOperator.mValue, v2->mSpeed, v4);
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
  ParkourSphereCastCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ParkourSphereCastCondition::`vftable;
  *(_QWORD *)&v1->mStart.x = 1056964608i64;
  v1->mStart.z = 1.0;
  *(_QWORD *)&v1->mEnd.x = 1075838976i64;
  v1->mEnd.z = 1.0;
  v1->mCollisionLayer = 12;
  v1->mRadius = 0.30000001;
  *(_QWORD *)&v1->mEdgeDistance = 1053609165i64;
  v1->mClipAtPlayer = 0;
}

// File Line: 6760
// RVA: 0x287FA0
char __fastcall ParkourSphereCastCondition::Match(ParkourSphereCastCondition *this, ActionContext *context)
{
  ActionContext *v2; // rbx
  ParkourSphereCastCondition *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::SensorComponent *v6; // r14
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::ParkourHandle *v11; // rdi
  UFG::SimObject *v12; // rbx
  float v13; // xmm6_4
  float v14; // xmm15_4
  float v15; // xmm14_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float v18; // xmm10_4
  bool v19; // r15
  bool v20; // r12
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm10_4
  float v24; // xmm11_4
  float v25; // xmm12_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm7_4
  float v29; // xmm8_4
  float v30; // xmm13_4
  float v31; // xmm5_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  __m128 v34; // xmm6
  __m128 v35; // xmm1
  float v36; // xmm2_4
  UFG::qVector3 *v37; // rax
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm10_4
  float v41; // xmm15_4
  float v42; // xmm11_4
  __int128 v43; // xmm12
  float v44; // xmm13_4
  float v45; // xmm0_4
  float v46; // xmm7_4
  float v47; // xmm6_4
  float v48; // xmm8_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm4_4
  float v52; // xmm7_4
  float v53; // xmm6_4
  __m128 v54; // xmm5
  __m128 v55; // xmm8
  float v56; // xmm14_4
  float v57; // xmm7_4
  float v58; // xmm6_4
  float v59; // xmm5_4
  float v60; // xmm2_4
  char v61; // di
  float v62; // xmm13_4
  float v63; // xmm11_4
  float v64; // xmm15_4
  __int64 i; // rsi
  unsigned __int64 v66; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v67; // rcx
  const char *v68; // rax
  float v70; // [rsp+40h] [rbp-88h]
  float v71; // [rsp+40h] [rbp-88h]
  UFG::qVector3 result; // [rsp+48h] [rbp-80h]
  float v73; // [rsp+54h] [rbp-74h]
  UFG::qVector3 p1; // [rsp+58h] [rbp-70h]
  int v75; // [rsp+64h] [rbp-64h]
  __m128 v76; // [rsp+68h] [rbp-60h]
  float v77; // [rsp+78h] [rbp-50h]
  float v78; // [rsp+7Ch] [rbp-4Ch]
  float v79; // [rsp+80h] [rbp-48h]
  int v80; // [rsp+84h] [rbp-44h]
  UFG::qVector3 start; // [rsp+88h] [rbp-40h]
  float v82; // [rsp+94h] [rbp-34h]
  UFG::qMatrix44 d; // [rsp+98h] [rbp-30h]
  UFG::qReflectHandleBase v84; // [rsp+D8h] [rbp+10h]
  __int64 v85; // [rsp+100h] [rbp+38h]
  float v86; // [rsp+1F0h] [rbp+128h]
  float v87; // [rsp+1F8h] [rbp+130h]
  float v88; // [rsp+200h] [rbp+138h]

  v85 = -2i64;
  v2 = context;
  v3 = this;
  v4 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = (UFG::SensorComponent *)v4->m_Components.p[26].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SensorComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SensorComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::SensorComponent::_TypeUID);
    v6 = (UFG::SensorComponent *)v7;
  }
  else
  {
    v6 = (UFG::SensorComponent *)v4->m_Components.p[26].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = v8->m_Components.p[28].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID);
    else
      v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::WorldContextComponent::_TypeUID);
  }
  else
  {
    v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::WorldContextComponent::_TypeUID);
  }
  if ( !v10 )
    return 0;
  v11 = (UFG::ParkourHandle *)v10[5].vfptr;
  if ( !v11 )
    return 0;
  v12 = v2->mSimObject.m_pPointer;
  if ( v12 )
    v12 = (UFG::SimObject *)v12->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
  v86 = *(float *)v12[1].mNode.mChild;
  v13 = *((float *)v12[1].mNode.mChild + 1);
  v14 = *(float *)&v12[1].mNode.mChild[1];
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
  v88 = *(float *)&v12[1].m_SafePointerList.mNode.mNext;
  v87 = *((float *)&v12[1].m_SafePointerList.mNode.mNext + 1);
  v70 = *(float *)&v12[1].m_SafePointerWithCallbackList.mNode.mPrev;
  UFG::ParkourHandle::GetEndpoints(v11, (UFG::qVector3 *)&v76, &p1);
  v15 = *(float *)&FLOAT_1_0;
  if ( sConstrianEndpoints )
  {
    v16 = 0.0;
    v17 = 0.0;
    v18 = v3->mEdgeDistance;
    v19 = v3->mCheckRight != 0;
    v20 = v3->mCheckLeft != 0;
    if ( v3->mCheckLeft || v3->mCheckRight )
    {
      v21 = UFG::ParkourHandle::GetHalfLength(v11) * 2.0;
      v16 = v18;
      v17 = v18;
      if ( v20 )
      {
        if ( v19 )
        {
          v22 = v18 + v18;
          if ( (float)(v18 + v18) > v21 )
          {
            v16 = (float)(v18 / v22) * v21;
            v17 = (float)(1.0 - (float)(v18 / v22)) * v21;
          }
        }
        else if ( v18 > v21 )
        {
          v16 = v21;
        }
      }
      else
      {
        if ( v19 && v18 > v21 )
          v17 = v21;
        v16 = 0.0;
      }
      if ( !v19 )
        v17 = 0.0;
    }
    UFG::ParkourHandle::GetAxis(v11, &result);
    v23 = (float)(result.x * v16) + v76.m128_f32[0];
    v24 = (float)(result.y * v16) + v76.m128_f32[1];
    v25 = (float)(result.z * v16) + v76.m128_f32[2];
    v76.m128_f32[0] = (float)(result.x * v16) + v76.m128_f32[0];
    v76.m128_f32[1] = (float)(result.y * v16) + v76.m128_f32[1];
    v76.m128_f32[2] = (float)(result.z * v16) + v76.m128_f32[2];
    v26 = result.z * v17;
    v27 = result.y * v17;
    v28 = p1.x - (float)(result.x * v17);
    v29 = p1.y - (float)(result.y * v17);
    v30 = p1.z - v26;
    p1.x = v28;
    p1.y = p1.y - v27;
    p1.z = p1.z - v26;
  }
  else
  {
    v25 = v76.m128_f32[2];
    v24 = v76.m128_f32[1];
    v23 = v76.m128_f32[0];
    v30 = p1.z;
    v29 = p1.y;
    v28 = p1.x;
  }
  v31 = (float)((float)((float)(v29 - v24) * v87) + (float)((float)(v28 - v23) * v88))
      + (float)((float)(v30 - v25) * v70);
  if ( COERCE_FLOAT(LODWORD(v31) & _xmm) <= 0.001 )
  {
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        (float)((float)((float)(v24 - v13) * v87) + (float)((float)(v23 - v86) * v88))
                      + (float)((float)(v25 - v14) * v70)) & _xmm) >= COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                                                     (float)((float)((float)(v29 - v13) * v87)
                                                                                           + (float)((float)(v28 - v86) * v88))
                                                                                   + (float)((float)(v30 - v14) * v70)) & _xmm) )
    {
      v77 = v28;
      v78 = v29;
      v79 = v30;
    }
    else
    {
      v77 = v23;
      v78 = v24;
      v79 = v25;
    }
  }
  else
  {
    v32 = (float)((float)((float)((float)(v13 - v24) * v87) + (float)((float)(v86 - v23) * v88))
                + (float)((float)(v14 - v25) * v70))
        / v31;
    if ( v32 >= 0.0 )
    {
      if ( v32 > 1.0 )
        v32 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v32 = 0.0;
    }
    v77 = (float)((float)(v28 - v23) * v32) + v23;
    v78 = (float)((float)(v29 - v24) * v32) + v24;
    v79 = (float)((float)(v30 - v25) * v32) + v25;
  }
  v80 = 1065353216;
  v76 = _xmm;
  if ( v3->mUsePlayerHeading )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    v33 = *(float *)&v12[1].vfptr;
    v34 = (__m128)HIDWORD(v12[1].vfptr);
    v35 = v34;
    v35.m128_f32[0] = (float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v33 * v33);
    if ( v35.m128_f32[0] == 0.0 )
      v36 = 0.0;
    else
      v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
    result.x = v36 * v33;
    result.y = v36 * v34.m128_f32[0];
    result.z = v36 * 0.0;
    v73 = 0.0;
    p1.x = (float)(v76.m128_f32[1] * 0.0) - (float)(v76.m128_f32[2] * v34.m128_f32[0]);
    p1.y = (float)(v76.m128_f32[2] * v33) - (float)(v76.m128_f32[0] * 0.0);
    p1.z = (float)(v76.m128_f32[0] * v34.m128_f32[0]) - (float)(v76.m128_f32[1] * v33);
  }
  else
  {
    UFG::ParkourHandle::GetNormal(v11, &result);
    result.x = result.x * -1.0;
    result.y = result.y * -1.0;
    result.z = result.z * -1.0;
    v73 = FLOAT_N0_0;
    v37 = UFG::ParkourHandle::GetAxis(v11, &start);
    v38 = v37->y;
    v39 = v37->z;
    p1.x = v37->x;
    p1.y = v38;
    p1.z = v39;
  }
  v75 = 0;
  v40 = v3->mStart.x;
  v86 = v3->mStart.x;
  v41 = v3->mStart.y;
  v42 = v3->mStart.z;
  v87 = v3->mStart.z;
  v43 = LODWORD(v3->mEnd.x);
  v82 = v3->mEnd.x;
  v44 = v3->mEnd.y;
  v71 = v3->mEnd.y;
  v45 = v3->mEnd.z;
  v88 = v3->mEnd.z;
  if ( v3->mClipAtPlayer )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
    v46 = *(float *)v12[1].mNode.mChild;
    v47 = *((float *)v12[1].mNode.mChild + 1);
    v48 = *(float *)&v12[1].mNode.mChild[1];
    UFG::qInverseAffine(&d, (UFG::qMatrix44 *)&result);
    v49 = (float)((float)((float)(d.v1.x * v47) + (float)(d.v0.x * v46)) + (float)(d.v2.x * v48)) + d.v3.x;
    v50 = (float)((float)((float)(d.v1.y * v47) + (float)(d.v0.y * v46)) + (float)(d.v2.y * v48)) + d.v3.y;
    v51 = (float)((float)((float)(d.v1.z * v47) + (float)(d.v0.z * v46)) + (float)(d.v2.z * v48)) + d.v3.z;
    v52 = v88 - v42;
    v53 = v44 - v41;
    v54 = (__m128)v43;
    v54.m128_f32[0] = *(float *)&v43 - v40;
    v55 = v54;
    v55.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v53 * v53)) + (float)(v52 * v52);
    if ( v55.m128_f32[0] == 0.0 )
      v56 = 0.0;
    else
      v56 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v55));
    v57 = v52 * v56;
    v58 = v53 * v56;
    v59 = v54.m128_f32[0] * v56;
    v60 = (float)((float)((float)(v50 - v41) * v58) + (float)((float)(v49 - v40) * v59))
        + (float)((float)(v51 - v42) * v57);
    v42 = v42 + (float)(v57 * v60);
    v87 = v42;
    v41 = v41 + (float)(v58 * v60);
    v40 = v40 + (float)(v59 * v60);
    v86 = v40;
    v15 = FLOAT_2_0;
    v45 = v88;
  }
  v61 = 0;
  if ( v3->mUseVaultThroughTags )
  {
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)&d,
      v3->mRadius,
      v3->mCollisionLayer,
      0);
    v62 = (float)((float)((float)(v41 * p1.x) + (float)(v40 * result.x)) + (float)(v42 * v76.m128_f32[0]))
        + (float)(v15 * v77);
    v63 = (float)((float)((float)(v41 * p1.y) + (float)(v86 * result.y)) + (float)(v87 * v76.m128_f32[1]))
        + (float)(v15 * v78);
    v64 = (float)((float)((float)(v41 * p1.z) + (float)(v86 * result.z)) + (float)(v87 * v76.m128_f32[2]))
        + (float)(v15 * v79);
    result.x = (float)((float)((float)(p1.x * v71) + (float)(result.x * v82)) + (float)(v76.m128_f32[0] * v88)) + v77;
    result.y = (float)((float)((float)(p1.y * v71) + (float)(result.y * v82)) + (float)(v76.m128_f32[1] * v88)) + v78;
    result.z = (float)((float)((float)(p1.z * v71) + (float)(result.z * v82)) + (float)(v76.m128_f32[2] * v88)) + v79;
    start.x = v62;
    start.y = v63;
    start.z = v64;
    if ( UFG::BasePhysicsSystem::CastShape(
           UFG::BasePhysicsSystem::mInstance,
           (UFG::ShapeCasterCollector *)&d,
           &start,
           &result) )
    {
      for ( i = *(_QWORD *)&d.v1.x; (UFG::qMatrix44 *)i != (UFG::qMatrix44 *)&d.v0.z; i = *(_QWORD *)(i + 8) )
      {
        if ( v61 )
          break;
        if ( *(_QWORD *)(i + 40) )
        {
          v66 = *(_QWORD *)(i + 88);
          UFG::qReflectHandleBase::qReflectHandleBase(&v84);
          v68 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v67);
          v84.mTypeUID = UFG::qStringHash64(v68, 0xFFFFFFFFFFFFFFFFui64);
          UFG::qReflectHandleBase::Init(&v84, v84.mTypeUID, v66);
          if ( v84.mData )
          {
            if ( LOBYTE(v84.mData[2].vfptr) )
              v61 = 1;
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v84);
        }
      }
    }
    UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&d);
  }
  else
  {
    LODWORD(start.x) = v43;
    start.y = v44;
    start.z = v45;
    result.x = v40;
    result.y = v41;
    result.z = v42;
    v61 = UFG::SensorComponent::CastSphere(
            v6,
            (UFG::qMatrix44 *)&result,
            v3->mRadius,
            v3->mCollisionLayer,
            &result,
            &start,
            0i64);
  }
  return v61;
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
  SphereCastCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SphereCastCondition::`vftable;
  v1->mRadius = 0.30000001;
  *(_QWORD *)&v1->mStart.x = 1056964608i64;
  v1->mStart.z = 1.0;
  *(_QWORD *)&v1->mEnd.x = 1075838976i64;
  v1->mEnd.z = 1.0;
  v1->mAttachLimbName = UFG::gNullQSymbolUC;
  v1->mCollisionLayer = 12;
  *(_WORD *)&v1->mUseAimOrigin = 0;
  v1->mToTarget.mValue = 0;
  v1->mToTargetBone = UFG::gNullQSymbolUC;
  *(_WORD *)&v1->mReturnTrueIfHitTarget = 0;
}

// File Line: 7034
// RVA: 0x1493C80
__int64 dynamic_initializer_for__symWorldSpace__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("WORLD_SPACE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symWorldSpace, v0);
  return atexit(dynamic_atexit_destructor_for__symWorldSpace__);
}

// File Line: 7035
// RVA: 0x1493C40
__int64 dynamic_initializer_for__symLocalSpace__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("LOCAL_SPACE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symLocalSpace, v0);
  return atexit(dynamic_atexit_destructor_for__symLocalSpace__);
}

// File Line: 7038
// RVA: 0x28A9F0
char __fastcall SphereCastCondition::Match(SphereCastCondition *this, ActionContext *context)
{
  ActionContext *v2; // r13
  SphereCastCondition *v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  UFG::SimObject *trueIfHits; // r15
  UFG::TransformNodeComponent *v6; // rbx
  UFG::SensorComponent *v7; // r14
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  unsigned int v22; // eax
  UFG::SimObjectProp *v23; // rcx
  unsigned __int16 v24; // dx
  UFG::CharacterAnimationComponent *v25; // rax
  Creature *v26; // rbx
  int v27; // eax
  UFG::SimObjectGame *v28; // rcx
  unsigned __int16 v29; // dx
  UFG::AimingBaseComponent *v30; // rbx
  UFG::SimComponent *v31; // rax
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  __int128 v34; // xmm3
  __int128 v35; // xmm11
  float v36; // xmm4_4
  float v37; // xmm3_4
  __m128 v38; // xmm10
  float v39; // xmm9_4
  float v40; // xmm8_4
  __m128 v41; // xmm2
  float v42; // xmm0_4
  __m128 v43; // xmm2
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm13_4
  float v47; // xmm14_4
  __m128 v48; // xmm5
  __m128 v49; // xmm2
  float v50; // xmm12_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm12_4
  __m128 v54; // xmm13
  float v55; // xmm4_4
  __m128 v56; // xmm2
  float v57; // xmm2_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm5_4
  float v61; // xmm11_4
  float v62; // xmm12_4
  UFG::SimObjectCVBase *v63; // rsi
  UFG::SimObjectGame *v64; // rcx
  UFG::SimComponent *v65; // r8
  unsigned __int16 v66; // dx
  UFG::SimComponent *v67; // rax
  unsigned int v68; // eax
  unsigned __int16 v69; // cx
  UFG::CharacterAnimationComponent *v70; // rax
  Creature *v71; // rbx
  int v72; // eax
  float v73; // xmm8_4
  float v74; // xmm9_4
  float v75; // xmm10_4
  float *v76; // rbx
  __m128 v77; // xmm1
  __int128 v78; // xmm2
  __int128 v79; // xmm13
  float v80; // xmm3_4
  float v81; // xmm2_4
  __m128 v82; // xmm4
  float v83; // xmm0_4
  __m128 v84; // xmm4
  __m128 v85; // xmm1
  float v86; // xmm14_4
  float v87; // xmm4_4
  float v88; // xmm9_4
  __m128 v89; // xmm8
  float v90; // xmm14_4
  __m128 v91; // xmm4
  float v92; // xmm4_4
  float v93; // xmm9_4
  __m128 v94; // xmm10
  float v95; // xmm3_4
  __m128 v96; // xmm2
  float v97; // xmm7_4
  UFG::SimObject *v98; // rax
  char v99; // bl
  float v101; // xmm2_4
  float v102; // xmm5_4
  float v103; // xmm15_4
  float v104; // xmm13_4
  __int64 v105; // rax
  char v106; // bl
  UFG::qVector3 vAimDirection; // [rsp+40h] [rbp-88h]
  float v108; // [rsp+4Ch] [rbp-7Ch]
  UFG::qMatrix44 transform; // [rsp+50h] [rbp-78h]
  float v110; // [rsp+90h] [rbp-38h]
  float v111; // [rsp+98h] [rbp-30h]
  float v112; // [rsp+9Ch] [rbp-2Ch]
  float v113; // [rsp+A0h] [rbp-28h]
  __int64 v114; // [rsp+A8h] [rbp-20h]
  UFG::qMatrix44 v115; // [rsp+B8h] [rbp-10h]
  float v116; // [rsp+1E0h] [rbp+118h]
  float v117; // [rsp+1E8h] [rbp+120h]
  float v118; // [rsp+1F0h] [rbp+128h]

  v114 = -2i64;
  v2 = context;
  v3 = this;
  v4 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  trueIfHits = 0i64;
  v6 = 0i64;
  if ( v4 )
  {
    v6 = v4->m_pTransformNodeComponent;
    v8 = v4->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = (UFG::SensorComponent *)v4->m_Components.p[26].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SensorComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SensorComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::SensorComponent::_TypeUID);
      }
      v7 = (UFG::SensorComponent *)v9;
    }
    else
    {
      v7 = (UFG::SensorComponent *)v4->m_Components.p[26].m_pComponent;
    }
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v6 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v10 = v6->mWorldTransform.v0.y;
  v11 = v6->mWorldTransform.v0.z;
  v12 = v6->mWorldTransform.v0.w;
  transform.v0.x = v6->mWorldTransform.v0.x;
  transform.v0.y = v10;
  transform.v0.z = v11;
  transform.v0.w = v12;
  v13 = v6->mWorldTransform.v1.y;
  v14 = v6->mWorldTransform.v1.z;
  v15 = v6->mWorldTransform.v1.w;
  transform.v1.x = v6->mWorldTransform.v1.x;
  transform.v1.y = v13;
  transform.v1.z = v14;
  transform.v1.w = v15;
  v16 = v6->mWorldTransform.v2.y;
  v17 = v6->mWorldTransform.v2.z;
  v18 = v6->mWorldTransform.v2.w;
  transform.v2.x = v6->mWorldTransform.v2.x;
  transform.v2.y = v16;
  transform.v2.z = v17;
  transform.v2.w = v18;
  v19 = v6->mWorldTransform.v3.y;
  v20 = v6->mWorldTransform.v3.z;
  v21 = v6->mWorldTransform.v3.w;
  vAimDirection.z = v6->mWorldTransform.v3.x;
  v108 = v19;
  transform.v0.x = v20;
  transform.v0.y = v21;
  v22 = v3->mAttachLimbName.mUID;
  if ( v22 != -1
    && v22 != symWorldSpace.mUID
    && v22 != symLocalSpace.mUID
    && (v23 = (UFG::SimObjectProp *)v2->mSimObject.m_pPointer) != 0i64
    && ((v24 = v23->m_Flags, !((v24 >> 14) & 1)) ? ((v24 & 0x8000u) == 0 ? (!((v24 >> 13) & 1) ? (!((v24 >> 12) & 1) ? (v25 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v23->vfptr, UFG::CharacterAnimationComponent::_TypeUID)) : (v25 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v23->vfptr, UFG::CharacterAnimationComponent::_TypeUID))) : (v25 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v23))) : (v25 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v23))) : (v25 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v23)),
        v25
     && (v26 = v25->mCreature) != 0i64
     && v26->mPose.mRigHandle.mData
     && (v27 = Skeleton::GetBoneID(v26->mPose.mRigHandle.mUFGSkeleton, v3->mAttachLimbName.mUID), v27 >= 0)) )
  {
    Creature::GetTransform(v26, v27, &transform);
  }
  else if ( v3->mUseAimOrigin )
  {
    v28 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v28 )
    {
      v29 = v28->m_Flags;
      if ( (v29 >> 14) & 1 )
      {
        v30 = (UFG::AimingBaseComponent *)v28->m_Components.p[47].m_pComponent;
      }
      else
      {
        if ( (v29 & 0x8000u) == 0 )
        {
          if ( (v29 >> 13) & 1 )
            v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::AimingBaseComponent::_TypeUID);
          else
            v31 = (v29 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v28->vfptr, UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::AimingBaseComponent::_TypeUID);
        }
        v30 = (UFG::AimingBaseComponent *)v31;
      }
      if ( v30 )
      {
        UFG::AimingBaseComponent::GetAimDirection(v30, &vAimDirection, 0i64);
        v32 = (__m128)LODWORD(vAimDirection.y);
        v33 = v32;
        v33.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(vAimDirection.x * vAimDirection.x))
                        + (float)(vAimDirection.z * vAimDirection.z);
        if ( v33.m128_f32[0] == 0.0 )
        {
          v34 = 0i64;
        }
        else
        {
          v34 = (unsigned int)FLOAT_1_0;
          *(float *)&v34 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v33));
        }
        v35 = v34;
        *(float *)&v35 = *(float *)&v34 * vAimDirection.z;
        v36 = *(float *)&v34 * vAimDirection.y;
        v37 = *(float *)&v34 * vAimDirection.x;
        transform.v0.x = v37;
        transform.v0.y = v36;
        LODWORD(transform.v0.z) = v35;
        transform.v0.w = 0.0;
        v38 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        v41 = v38;
        v39 = UFG::qVector3::msDirUp.y;
        v40 = UFG::qVector3::msDirUp.z;
        v41.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v39 * v39)) + (float)(v40 * v40);
        if ( v41.m128_f32[0] == 0.0 )
        {
          v43 = 0i64;
        }
        else
        {
          LODWORD(v42) = (unsigned __int128)_mm_sqrt_ps(v41);
          v43 = (__m128)(unsigned int)FLOAT_1_0;
          v43.m128_f32[0] = 1.0 / v42;
        }
        v44 = v43.m128_f32[0] * UFG::qVector3::msDirUp.z;
        v48 = v43;
        v48.m128_f32[0] = v43.m128_f32[0] * UFG::qVector3::msDirUp.y;
        v45 = v43.m128_f32[0] * UFG::qVector3::msDirUp.x;
        v46 = (float)(v36 * v45) - (float)(v48.m128_f32[0] * v37);
        v47 = (float)(v44 * v37) - (float)(*(float *)&v35 * v45);
        v48.m128_f32[0] = (float)(v48.m128_f32[0] * *(float *)&v35) - (float)(v44 * v36);
        v49 = v48;
        v49.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v47 * v47)) + (float)(v46 * v46);
        if ( v49.m128_f32[0] == 0.0 )
          v50 = 0.0;
        else
          v50 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v49));
        v51 = v50 * v46;
        v52 = v50 * v47;
        transform.v1.x = v48.m128_f32[0] * v50;
        transform.v1.y = v50 * v47;
        transform.v1.z = v51;
        transform.v1.w = 0.0;
        v53 = (float)((float)(v50 * v47) * v37) - (float)(v36 * (float)(v48.m128_f32[0] * v50));
        v54 = (__m128)v35;
        v54.m128_f32[0] = (float)(*(float *)&v35 * transform.v1.x) - (float)(v51 * v37);
        v55 = (float)(v36 * v51) - (float)(*(float *)&v35 * v52);
        v56 = v54;
        v56.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v55 * v55)) + (float)(v53 * v53);
        if ( v56.m128_f32[0] == 0.0 )
          v57 = 0.0;
        else
          v57 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v56));
        transform.v2.x = v57 * v55;
        transform.v2.y = v57 * v54.m128_f32[0];
        transform.v2.z = v57 * v53;
        transform.v2.w = 0.0;
        v58 = v30->m_vAimOriginPosition.y;
        v59 = v30->m_vAimOriginPosition.z;
        vAimDirection.z = v30->m_vAimOriginPosition.x;
        v108 = v58;
        transform.v0.x = v59;
        transform.v0.y = 1.0;
        goto LABEL_60;
      }
    }
  }
  v38 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v39 = UFG::qVector3::msDirUp.y;
  v40 = UFG::qVector3::msDirUp.z;
LABEL_60:
  v60 = v3->mEnd.x;
  v118 = v3->mEnd.x;
  v61 = v3->mEnd.y;
  v117 = v3->mEnd.y;
  v62 = v3->mEnd.z;
  transform.v0.z = v3->mEnd.z;
  v63 = 0i64;
  if ( v3->mToTarget.mValue < 2u )
    goto LABEL_93;
  v64 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
  if ( v64 )
  {
    v66 = v64->m_Flags;
    if ( (v66 >> 14) & 1 )
    {
      v65 = v64->m_Components.p[20].m_pComponent;
    }
    else if ( (v66 & 0x8000u) == 0 )
    {
      if ( (v66 >> 13) & 1 )
      {
        v67 = UFG::SimObjectGame::GetComponentOfTypeHK(v64, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v66 >> 12) & 1 )
      {
        v67 = UFG::SimObjectGame::GetComponentOfTypeHK(v64, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v67 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v64->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v65 = v67;
    }
    else
    {
      v65 = v64->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v65 = 0i64;
  }
  v63 = *(UFG::SimObjectCVBase **)(56i64
                                 * *(unsigned __int8 *)(*(_QWORD *)&v65[1].m_Flags
                                                      + (unsigned __int8)v3->mToTarget.mValue
                                                      + 8i64)
                                 + *(_QWORD *)&v65[1].m_TypeUID
                                 + 40);
  if ( !v63 )
    return 0;
  v68 = v3->mToTargetBone.mUID;
  if ( v68 == -1 || v68 == symWorldSpace.mUID || v68 == symLocalSpace.mUID )
  {
    v76 = (float *)v63->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v63->m_pTransformNodeComponent);
    v73 = v76[44];
    v74 = v76[45];
    v75 = v76[46];
    goto LABEL_92;
  }
  v69 = v63->m_Flags;
  if ( (v69 >> 14) & 1 )
  {
    v70 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v63);
  }
  else if ( (v69 & 0x8000u) == 0 )
  {
    if ( (v69 >> 13) & 1 )
      v70 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v63);
    else
      v70 = (UFG::CharacterAnimationComponent *)((v69 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v63->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v63->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v70 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v63);
  }
  if ( !v70 )
    return 0;
  v71 = v70->mCreature;
  if ( !v71 )
    return 0;
  if ( !v71->mPose.mRigHandle.mData )
    return 0;
  v72 = Skeleton::GetBoneID(v71->mPose.mRigHandle.mUFGSkeleton, v3->mToTargetBone.mUID);
  if ( v72 < 0 )
    return 0;
  Creature::GetTransform(v71, v72, &v115);
  v73 = v115.v3.x;
  v74 = v115.v3.y;
  v75 = v115.v3.z;
LABEL_92:
  UFG::qInverseAffine((UFG::qMatrix44 *)((char *)&transform + 24), &transform);
  v60 = (float)((float)((float)(transform.v2.z * v74) + (float)(transform.v1.z * v73)) + (float)(transform.v3.z * v75))
      + v111;
  v118 = (float)((float)((float)(transform.v2.z * v74) + (float)(transform.v1.z * v73)) + (float)(transform.v3.z * v75))
       + v111;
  v61 = (float)((float)((float)(transform.v2.w * v74) + (float)(transform.v1.w * v73)) + (float)(transform.v3.w * v75))
      + v112;
  v117 = (float)((float)((float)(transform.v2.w * v74) + (float)(transform.v1.w * v73)) + (float)(transform.v3.w * v75))
       + v112;
  v62 = (float)((float)((float)(transform.v3.x * v74) + (float)(transform.v2.x * v73)) + (float)(v110 * v75)) + v113;
  transform.v0.z = (float)((float)((float)(transform.v3.x * v74) + (float)(transform.v2.x * v73)) + (float)(v110 * v75))
                 + v113;
  v40 = UFG::qVector3::msDirUp.z;
  v39 = UFG::qVector3::msDirUp.y;
  v38 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
LABEL_93:
  if ( v3->mMakeUpright )
  {
    v77 = (__m128)LODWORD(transform.v0.x);
    v77.m128_f32[0] = (float)(v77.m128_f32[0] * v77.m128_f32[0]) + (float)(transform.v0.y * transform.v0.y);
    if ( v77.m128_f32[0] == 0.0 )
    {
      v78 = 0i64;
    }
    else
    {
      v78 = (unsigned int)FLOAT_1_0;
      *(float *)&v78 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v77));
    }
    v79 = v78;
    *(float *)&v79 = *(float *)&v78 * 0.0;
    v80 = *(float *)&v78 * transform.v0.y;
    v81 = *(float *)&v78 * transform.v0.x;
    transform.v0.x = v81;
    transform.v0.y = v80;
    LODWORD(transform.v0.z) = v79;
    transform.v0.w = 0.0;
    v82 = v38;
    v82.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v39 * v39)) + (float)(v40 * v40);
    if ( v82.m128_f32[0] == 0.0 )
    {
      v84 = 0i64;
    }
    else
    {
      LODWORD(v83) = (unsigned __int128)_mm_sqrt_ps(v82);
      v84 = (__m128)(unsigned int)FLOAT_1_0;
      v84.m128_f32[0] = 1.0 / v83;
    }
    v85 = v84;
    v85.m128_f32[0] = v84.m128_f32[0] * v40;
    v86 = v84.m128_f32[0] * v39;
    v87 = v84.m128_f32[0] * v38.m128_f32[0];
    v88 = (float)(v80 * v87) - (float)(v86 * v81);
    v89 = v85;
    v89.m128_f32[0] = (float)(v85.m128_f32[0] * v81) - (float)(*(float *)&v79 * v87);
    v90 = (float)(v86 * *(float *)&v79) - (float)(v85.m128_f32[0] * v80);
    v91 = v89;
    v91.m128_f32[0] = (float)((float)(v89.m128_f32[0] * v89.m128_f32[0]) + (float)(v90 * v90)) + (float)(v88 * v88);
    if ( v91.m128_f32[0] == 0.0 )
      v92 = 0.0;
    else
      v92 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v91));
    transform.v1.x = v92 * v90;
    transform.v1.y = v89.m128_f32[0] * v92;
    transform.v1.z = v92 * v88;
    transform.v1.w = 0.0;
    v93 = (float)((float)(v89.m128_f32[0] * v92) * v81) - (float)(v80 * (float)(v92 * v90));
    v94 = (__m128)v79;
    v94.m128_f32[0] = (float)(*(float *)&v79 * (float)(v92 * v90)) - (float)(transform.v1.z * v81);
    v95 = (float)(v80 * transform.v1.z) - (float)(*(float *)&v79 * (float)(v89.m128_f32[0] * v92));
    v96 = v94;
    v96.m128_f32[0] = (float)((float)(v94.m128_f32[0] * v94.m128_f32[0]) + (float)(v95 * v95)) + (float)(v93 * v93);
    if ( v96.m128_f32[0] == 0.0 )
      v97 = 0.0;
    else
      v97 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v96));
    transform.v2.x = v97 * v95;
    transform.v2.y = v97 * v94.m128_f32[0];
    transform.v2.z = v97 * v93;
    transform.v2.w = 0.0;
    transform.v0.y = 1.0;
  }
  if ( !v7 || (v98 = v7->m_pSimObject) != 0i64 && (v98->m_Flags >> 10) & 1 )
  {
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)&transform.v1.z,
      v3->mRadius,
      v3->mCollisionLayer,
      0);
    v101 = v3->mStart.y;
    v102 = v3->mStart.z;
    v103 = (float)((float)((float)(v3->mStart.y * transform.v1.x) + (float)(v3->mStart.x * transform.v0.x))
                 + (float)(v3->mStart.z * transform.v2.x))
         + vAimDirection.z;
    v104 = (float)((float)((float)(v3->mStart.y * transform.v1.y) + (float)(v3->mStart.x * transform.v0.y))
                 + (float)(v3->mStart.z * transform.v2.y))
         + v108;
    v116 = v3->mStart.x * transform.v0.z;
    v116 = v116 + (float)(v101 * transform.v1.z);
    vAimDirection.x = (float)((float)((float)(transform.v1.x * v117) + (float)(transform.v0.x * v118))
                            + (float)(transform.v2.x * transform.v0.z))
                    + vAimDirection.z;
    vAimDirection.y = (float)((float)((float)(transform.v1.y * v117) + (float)(transform.v0.y * v118))
                            + (float)(transform.v2.y * transform.v0.z))
                    + v108;
    vAimDirection.z = (float)((float)((float)(transform.v1.z * v117) + (float)(transform.v0.z * v118))
                            + (float)(transform.v2.z * transform.v0.z))
                    + transform.v0.x;
    transform.v0.w = v103;
    transform.v1.x = v104;
    transform.v1.y = (float)(v116 + (float)(v102 * transform.v2.z)) + transform.v0.x;
    if ( UFG::BasePhysicsSystem::CastShape(
           UFG::BasePhysicsSystem::mInstance,
           (UFG::ShapeCasterCollector *)&transform.v1.z,
           (UFG::qVector3 *)&transform.v0.w,
           &vAimDirection) )
    {
      if ( !v3->mReturnTrueIfHitTarget )
      {
LABEL_119:
        v106 = 1;
LABEL_121:
        SphereCastCondition::AssignToTargetType(
          v3,
          v2->mSimObject.m_pPointer,
          (UFG::ShapeCasterCollector *)&transform.v1.z);
        UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&transform.v1.z);
        return v106;
      }
      v105 = *(_QWORD *)&transform.v2.z;
      if ( *(UFG::qMatrix44 **)&transform.v2.z != (UFG::qMatrix44 *)&transform.v2 )
      {
        while ( *(UFG::SimObjectCVBase **)(v105 + 80) != v63 )
        {
          v105 = *(_QWORD *)(v105 + 8);
          if ( (UFG::qVector4 *)v105 == &transform.v2 )
            goto LABEL_120;
        }
        goto LABEL_119;
      }
    }
LABEL_120:
    v106 = 0;
    goto LABEL_121;
  }
  vAimDirection.x = v60;
  vAimDirection.y = v61;
  vAimDirection.z = v62;
  if ( v3->mReturnTrueIfHitTarget )
    trueIfHits = (UFG::SimObject *)&v63->vfptr;
  v99 = UFG::SensorComponent::CastSphere(
          v7,
          &transform,
          v3->mRadius,
          v3->mCollisionLayer,
          &v3->mStart,
          &vAimDirection,
          trueIfHits);
  SphereCastCondition::AssignToTargetType(v3, v2->mSimObject.m_pPointer, v7->mSphereCaster);
  return v99;
}o LABEL_119;
      }
    }
LABEL_120:
    v106 = 0;
    goto LABEL_121;
  }
  vAimDirection.x = v60;
  vAimDirection.y = v61;
  vAimDirection.z = v62;
  if ( v3->mReturnTrueIfHitTarget )
    trueIfHits = (UFG::SimObject *)&v63->vfptr;
  v99 = UFG::SensorComponent::CastSphere(
          v7,
          &transform,
        

// File Line: 7200
// RVA: 0x27ABC0
void __fastcall SphereCastCondition::AssignToTargetType(SphereCastCondition *this, UFG::SimObject *assignToSimObject, UFG::ShapeCasterCollector *collector)
{
  UFG::eTargetTypeEnum v3; // edi
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v4; // rax
  UFG::SimObject *v5; // rbx
  unsigned __int16 v6; // cx
  UFG::TargetingSystemBaseComponent *v7; // rax

  v3 = (unsigned __int8)this->mAssignToTargetType.mValue;
  if ( this->mAssignToTargetType.mValue )
  {
    if ( collector )
    {
      if ( (UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *)collector->mHitList.mNode.mNext != &collector->mHitList )
      {
        v4 = collector->mHitList.mNode.mNext;
        if ( v4 )
        {
          v5 = (UFG::SimObject *)v4[5].mPrev;
          if ( v5 )
          {
            if ( assignToSimObject )
            {
              v6 = assignToSimObject->m_Flags;
              if ( (v6 >> 14) & 1 )
              {
                v7 = (UFG::TargetingSystemBaseComponent *)assignToSimObject->m_Components.p[20].m_pComponent;
              }
              else if ( (v6 & 0x8000u) == 0 )
              {
                if ( (v6 >> 13) & 1 )
                {
                  v7 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)assignToSimObject,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID);
                }
                else if ( (v6 >> 12) & 1 )
                {
                  v7 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)assignToSimObject,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID);
                }
                else
                {
                  v7 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                              assignToSimObject,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID);
                }
              }
              else
              {
                v7 = (UFG::TargetingSystemBaseComponent *)assignToSimObject->m_Components.p[20].m_pComponent;
              }
              if ( v7 )
                UFG::TargetingSystemBaseComponent::SetTarget(v7, v3, v5);
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
void __fastcall BrokenVehicleGlassSphereCastCondition::BrokenVehicleGlassSphereCastCondition(BrokenVehicleGlassSphereCastCondition *this)
{
  BrokenVehicleGlassSphereCastCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&BrokenVehicleGlassSphereCastCondition::`vftable;
  v1->mRadius = 0.30000001;
  *(_QWORD *)&v1->mStart.x = 1056964608i64;
  v1->mStart.z = 1.0;
  *(_QWORD *)&v1->mEnd.x = 1075838976i64;
  v1->mEnd.z = 1.0;
  v1->mAttachLimbName = UFG::gNullQSymbolUC;
  v1->mCollisionLayer = 12;
  *(_WORD *)&v1->mUseAimOrigin = 0;
  v1->mToTarget.mValue = 0;
  v1->mToTargetBone = UFG::gNullQSymbolUC;
  v1->mReturnTrueIfHitTarget = 0;
}

// File Line: 7285
// RVA: 0x27EF80
char __fastcall BrokenVehicleGlassSphereCastCondition::Match(BrokenVehicleGlassSphereCastCondition *this, ActionContext *context)
{
  ActionContext *v2; // r13
  BrokenVehicleGlassSphereCastCondition *v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  UFG::SimObject *trueIfHits; // r15
  UFG::TransformNodeComponent *v6; // rbx
  UFG::SensorComponent *v7; // r14
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  unsigned int v22; // eax
  UFG::SimObjectProp *v23; // rcx
  unsigned __int16 v24; // dx
  UFG::CharacterAnimationComponent *v25; // rax
  Creature *v26; // rbx
  int v27; // eax
  UFG::SimObjectGame *v28; // rcx
  unsigned __int16 v29; // dx
  UFG::AimingBaseComponent *v30; // rbx
  UFG::SimComponent *v31; // rax
  __m128 v32; // xmm4
  __int128 v33; // xmm5
  __m128 v34; // xmm2
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm2_4
  __m128 v38; // xmm11
  float v39; // xmm10_4
  float v40; // xmm9_4
  __m128 v41; // xmm4
  __m128 v42; // xmm8
  float v43; // xmm1_4
  float v44; // xmm8_4
  float v45; // xmm13_4
  float v46; // xmm12_4
  __m128 v47; // xmm4
  __m128 v48; // xmm8
  float v49; // xmm1_4
  float v50; // xmm8_4
  __m128 v51; // xmm14
  float v52; // xmm3_4
  __m128 v53; // xmm2
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm5_4
  float v58; // xmm8_4
  float v59; // xmm12_4
  UFG::SimObjectCVBase *v60; // rsi
  UFG::SimObjectGame *v61; // rcx
  UFG::SimComponent *v62; // r8
  unsigned __int16 v63; // dx
  UFG::SimComponent *v64; // rax
  unsigned int v65; // eax
  unsigned __int16 v66; // cx
  UFG::CharacterAnimationComponent *v67; // rax
  Creature *v68; // rbx
  int v69; // eax
  float v70; // xmm9_4
  float v71; // xmm10_4
  float v72; // xmm11_4
  float *v73; // rbx
  __m128 v74; // xmm1
  __int128 v75; // xmm2
  __int128 v76; // xmm13
  float v77; // xmm3_4
  float v78; // xmm2_4
  __m128 v79; // xmm4
  float v80; // xmm0_4
  __m128 v81; // xmm4
  __m128 v82; // xmm1
  float v83; // xmm14_4
  float v84; // xmm4_4
  float v85; // xmm10_4
  __m128 v86; // xmm9
  float v87; // xmm14_4
  __m128 v88; // xmm4
  float v89; // xmm1_4
  float v90; // xmm4_4
  __m128 v91; // xmm11
  float v92; // xmm3_4
  __m128 v93; // xmm2
  float v94; // xmm7_4
  char v95; // r12
  UFG::ShapeCasterCollector *v96; // rax
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *v97; // rbx
  signed __int64 v98; // rsi
  float v100; // xmm2_4
  float v101; // xmm5_4
  float v102; // xmm15_4
  float v103; // xmm13_4
  bool v104; // al
  __int64 v105; // rbx
  __int64 v106; // rax
  char v107; // al
  char v108; // si
  UFG::qVector3 vAimDirection; // [rsp+40h] [rbp-88h]
  float v110; // [rsp+4Ch] [rbp-7Ch]
  UFG::qMatrix44 transform; // [rsp+50h] [rbp-78h]
  float v112; // [rsp+90h] [rbp-38h]
  float v113; // [rsp+98h] [rbp-30h]
  float v114; // [rsp+9Ch] [rbp-2Ch]
  float v115; // [rsp+A0h] [rbp-28h]
  __int64 v116; // [rsp+A8h] [rbp-20h]
  UFG::qMatrix44 v117; // [rsp+B8h] [rbp-10h]
  float v118; // [rsp+1E0h] [rbp+118h]
  float v119; // [rsp+1E8h] [rbp+120h]
  float v120; // [rsp+1F0h] [rbp+128h]

  v116 = -2i64;
  v2 = context;
  v3 = this;
  v4 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  trueIfHits = 0i64;
  v6 = 0i64;
  if ( v4 )
  {
    v6 = v4->m_pTransformNodeComponent;
    v8 = v4->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = (UFG::SensorComponent *)v4->m_Components.p[26].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SensorComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::SensorComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::SensorComponent::_TypeUID);
      }
      v7 = (UFG::SensorComponent *)v9;
    }
    else
    {
      v7 = (UFG::SensorComponent *)v4->m_Components.p[26].m_pComponent;
    }
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v6 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v10 = v6->mWorldTransform.v0.y;
  v11 = v6->mWorldTransform.v0.z;
  v12 = v6->mWorldTransform.v0.w;
  transform.v0.x = v6->mWorldTransform.v0.x;
  transform.v0.y = v10;
  transform.v0.z = v11;
  transform.v0.w = v12;
  v13 = v6->mWorldTransform.v1.y;
  v14 = v6->mWorldTransform.v1.z;
  v15 = v6->mWorldTransform.v1.w;
  transform.v1.x = v6->mWorldTransform.v1.x;
  transform.v1.y = v13;
  transform.v1.z = v14;
  transform.v1.w = v15;
  v16 = v6->mWorldTransform.v2.y;
  v17 = v6->mWorldTransform.v2.z;
  v18 = v6->mWorldTransform.v2.w;
  transform.v2.x = v6->mWorldTransform.v2.x;
  transform.v2.y = v16;
  transform.v2.z = v17;
  transform.v2.w = v18;
  v19 = v6->mWorldTransform.v3.y;
  v20 = v6->mWorldTransform.v3.z;
  v21 = v6->mWorldTransform.v3.w;
  vAimDirection.z = v6->mWorldTransform.v3.x;
  v110 = v19;
  transform.v0.x = v20;
  transform.v0.y = v21;
  v22 = v3->mAttachLimbName.mUID;
  if ( v22 != -1
    && v22 != symWorldSpace.mUID
    && v22 != symLocalSpace.mUID
    && (v23 = (UFG::SimObjectProp *)v2->mSimObject.m_pPointer) != 0i64
    && ((v24 = v23->m_Flags, !((v24 >> 14) & 1)) ? ((v24 & 0x8000u) == 0 ? (!((v24 >> 13) & 1) ? (!((v24 >> 12) & 1) ? (v25 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v23->vfptr, UFG::CharacterAnimationComponent::_TypeUID)) : (v25 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v23->vfptr, UFG::CharacterAnimationComponent::_TypeUID))) : (v25 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v23))) : (v25 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v23))) : (v25 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v23)),
        v25
     && (v26 = v25->mCreature) != 0i64
     && v26->mPose.mRigHandle.mData
     && (v27 = Skeleton::GetBoneID(v26->mPose.mRigHandle.mUFGSkeleton, v3->mAttachLimbName.mUID), v27 >= 0)) )
  {
    Creature::GetTransform(v26, v27, &transform);
  }
  else if ( v3->mUseAimOrigin )
  {
    v28 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v28 )
    {
      v29 = v28->m_Flags;
      if ( (v29 >> 14) & 1 )
      {
        v30 = (UFG::AimingBaseComponent *)v28->m_Components.p[47].m_pComponent;
      }
      else
      {
        if ( (v29 & 0x8000u) == 0 )
        {
          if ( (v29 >> 13) & 1 )
            v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::AimingBaseComponent::_TypeUID);
          else
            v31 = (v29 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v28->vfptr, UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::AimingBaseComponent::_TypeUID);
        }
        v30 = (UFG::AimingBaseComponent *)v31;
      }
      if ( v30 )
      {
        UFG::AimingBaseComponent::GetAimDirection(v30, &vAimDirection, 0i64);
        v32 = (__m128)LODWORD(vAimDirection.y);
        v34 = v32;
        v33 = LODWORD(vAimDirection.z);
        v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(vAimDirection.x * vAimDirection.x))
                        + (float)(*(float *)&v33 * *(float *)&v33);
        if ( v34.m128_f32[0] == 0.0 )
          v35 = 0.0;
        else
          v35 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v34));
        *(float *)&v33 = vAimDirection.z * v35;
        v36 = v35 * vAimDirection.y;
        v37 = v35 * vAimDirection.x;
        transform.v0.x = v37;
        transform.v0.y = v36;
        LODWORD(transform.v0.z) = v33;
        transform.v0.w = 0.0;
        v38 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        v41 = v38;
        v39 = UFG::qVector3::msDirUp.y;
        v40 = UFG::qVector3::msDirUp.z;
        v41.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v39 * v39)) + (float)(v40 * v40);
        if ( v41.m128_f32[0] == 0.0 )
        {
          v42 = 0i64;
        }
        else
        {
          v42 = (__m128)(unsigned int)FLOAT_1_0;
          v42.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v41));
        }
        v43 = v42.m128_f32[0] * UFG::qVector3::msDirUp.z;
        v47 = v42;
        v47.m128_f32[0] = v42.m128_f32[0] * UFG::qVector3::msDirUp.y;
        v44 = v42.m128_f32[0] * UFG::qVector3::msDirUp.x;
        v45 = (float)(v36 * v44) - (float)(v47.m128_f32[0] * v37);
        v46 = (float)(v43 * v37) - (float)(*(float *)&v33 * v44);
        v47.m128_f32[0] = (float)(v47.m128_f32[0] * *(float *)&v33) - (float)(v43 * v36);
        v48 = v47;
        v48.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v46 * v46)) + (float)(v45 * v45);
        if ( v48.m128_f32[0] == 0.0 )
          v49 = 0.0;
        else
          v49 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v48));
        transform.v1.x = v47.m128_f32[0] * v49;
        transform.v1.y = v46 * v49;
        transform.v1.z = v45 * v49;
        transform.v1.w = 0.0;
        v50 = (float)((float)(v46 * v49) * v37) - (float)(v36 * (float)(v47.m128_f32[0] * v49));
        v51 = (__m128)v33;
        v51.m128_f32[0] = (float)(*(float *)&v33 * (float)(v47.m128_f32[0] * v49)) - (float)((float)(v45 * v49) * v37);
        v52 = (float)(v36 * (float)(v45 * v49)) - (float)(*(float *)&v33 * (float)(v46 * v49));
        v53 = v51;
        v53.m128_f32[0] = (float)((float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v52 * v52)) + (float)(v50 * v50);
        if ( v53.m128_f32[0] == 0.0 )
          v54 = 0.0;
        else
          v54 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v53));
        transform.v2.x = v54 * v52;
        transform.v2.y = v54 * v51.m128_f32[0];
        transform.v2.z = v54 * v50;
        transform.v2.w = 0.0;
        v55 = v30->m_vAimOriginPosition.y;
        v56 = v30->m_vAimOriginPosition.z;
        vAimDirection.z = v30->m_vAimOriginPosition.x;
        v110 = v55;
        transform.v0.x = v56;
        transform.v0.y = 1.0;
        goto LABEL_60;
      }
    }
  }
  v38 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  v39 = UFG::qVector3::msDirUp.y;
  v40 = UFG::qVector3::msDirUp.z;
LABEL_60:
  v57 = v3->mEnd.x;
  v120 = v3->mEnd.x;
  v58 = v3->mEnd.y;
  v119 = v3->mEnd.y;
  v59 = v3->mEnd.z;
  transform.v0.z = v3->mEnd.z;
  v60 = 0i64;
  if ( v3->mToTarget.mValue < 2u )
    goto LABEL_92;
  v61 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
  if ( v61 )
  {
    v63 = v61->m_Flags;
    if ( (v63 >> 14) & 1 )
    {
      v62 = v61->m_Components.p[20].m_pComponent;
    }
    else if ( (v63 & 0x8000u) == 0 )
    {
      if ( (v63 >> 13) & 1 )
      {
        v64 = UFG::SimObjectGame::GetComponentOfTypeHK(v61, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v63 >> 12) & 1 )
      {
        v64 = UFG::SimObjectGame::GetComponentOfTypeHK(v61, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v64 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v61->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v62 = v64;
    }
    else
    {
      v62 = v61->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v62 = 0i64;
  }
  v60 = *(UFG::SimObjectCVBase **)(56i64
                                 * *(unsigned __int8 *)(*(_QWORD *)&v62[1].m_Flags
                                                      + (unsigned __int8)v3->mToTarget.mValue
                                                      + 8i64)
                                 + *(_QWORD *)&v62[1].m_TypeUID
                                 + 40);
  if ( !v60 )
    return 0;
  v65 = v3->mToTargetBone.mUID;
  if ( v65 == -1 || v65 == symWorldSpace.mUID || v65 == symLocalSpace.mUID )
  {
    v73 = (float *)v60->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v60->m_pTransformNodeComponent);
    v70 = v73[44];
    v71 = v73[45];
    v72 = v73[46];
    goto LABEL_91;
  }
  v66 = v60->m_Flags;
  if ( (v66 >> 14) & 1 )
  {
    v67 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v60);
  }
  else if ( (v66 & 0x8000u) == 0 )
  {
    if ( (v66 >> 13) & 1 )
      v67 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v60);
    else
      v67 = (UFG::CharacterAnimationComponent *)((v66 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v60->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v60->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v67 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v60);
  }
  if ( !v67 )
    return 0;
  v68 = v67->mCreature;
  if ( !v68->mPose.mRigHandle.mData )
    return 0;
  v69 = Skeleton::GetBoneID(v68->mPose.mRigHandle.mUFGSkeleton, v3->mToTargetBone.mUID);
  if ( v69 < 0 )
    return 0;
  Creature::GetTransform(v68, v69, &v117);
  v70 = v117.v3.x;
  v71 = v117.v3.y;
  v72 = v117.v3.z;
LABEL_91:
  UFG::qInverseAffine((UFG::qMatrix44 *)((char *)&transform + 24), &transform);
  v57 = (float)((float)((float)(transform.v2.z * v71) + (float)(transform.v1.z * v70)) + (float)(transform.v3.z * v72))
      + v113;
  v120 = (float)((float)((float)(transform.v2.z * v71) + (float)(transform.v1.z * v70)) + (float)(transform.v3.z * v72))
       + v113;
  v58 = (float)((float)((float)(transform.v2.w * v71) + (float)(transform.v1.w * v70)) + (float)(transform.v3.w * v72))
      + v114;
  v119 = (float)((float)((float)(transform.v2.w * v71) + (float)(transform.v1.w * v70)) + (float)(transform.v3.w * v72))
       + v114;
  v59 = (float)((float)((float)(transform.v3.x * v71) + (float)(transform.v2.x * v70)) + (float)(v112 * v72)) + v115;
  transform.v0.z = (float)((float)((float)(transform.v3.x * v71) + (float)(transform.v2.x * v70)) + (float)(v112 * v72))
                 + v115;
  v40 = UFG::qVector3::msDirUp.z;
  v39 = UFG::qVector3::msDirUp.y;
  v38 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
LABEL_92:
  if ( v3->mMakeUpright )
  {
    v74 = (__m128)LODWORD(transform.v0.x);
    v74.m128_f32[0] = (float)(v74.m128_f32[0] * v74.m128_f32[0]) + (float)(transform.v0.y * transform.v0.y);
    if ( v74.m128_f32[0] == 0.0 )
    {
      v75 = 0i64;
    }
    else
    {
      v75 = (unsigned int)FLOAT_1_0;
      *(float *)&v75 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v74));
    }
    v76 = v75;
    *(float *)&v76 = *(float *)&v75 * 0.0;
    v77 = *(float *)&v75 * transform.v0.y;
    v78 = *(float *)&v75 * transform.v0.x;
    transform.v0.x = v78;
    transform.v0.y = v77;
    LODWORD(transform.v0.z) = v76;
    transform.v0.w = 0.0;
    v79 = v38;
    v79.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v39 * v39)) + (float)(v40 * v40);
    if ( v79.m128_f32[0] == 0.0 )
    {
      v81 = 0i64;
    }
    else
    {
      LODWORD(v80) = (unsigned __int128)_mm_sqrt_ps(v79);
      v81 = (__m128)(unsigned int)FLOAT_1_0;
      v81.m128_f32[0] = 1.0 / v80;
    }
    v82 = v81;
    v82.m128_f32[0] = v81.m128_f32[0] * v40;
    v83 = v81.m128_f32[0] * v39;
    v84 = v81.m128_f32[0] * v38.m128_f32[0];
    v85 = (float)(v77 * v84) - (float)(v83 * v78);
    v86 = v82;
    v86.m128_f32[0] = (float)(v82.m128_f32[0] * v78) - (float)(*(float *)&v76 * v84);
    v87 = (float)(v83 * *(float *)&v76) - (float)(v82.m128_f32[0] * v77);
    v88 = v86;
    v88.m128_f32[0] = (float)((float)(v86.m128_f32[0] * v86.m128_f32[0]) + (float)(v87 * v87)) + (float)(v85 * v85);
    if ( v88.m128_f32[0] == 0.0 )
      v89 = 0.0;
    else
      v89 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v88));
    transform.v1.x = v89 * v87;
    transform.v1.y = v86.m128_f32[0] * v89;
    transform.v1.z = v85 * v89;
    transform.v1.w = 0.0;
    v90 = (float)((float)(v86.m128_f32[0] * v89) * v78) - (float)(v77 * (float)(v89 * v87));
    v91 = (__m128)v76;
    v91.m128_f32[0] = (float)(*(float *)&v76 * (float)(v89 * v87)) - (float)((float)(v85 * v89) * v78);
    v92 = (float)(v77 * (float)(v85 * v89)) - (float)(*(float *)&v76 * (float)(v86.m128_f32[0] * v89));
    v93 = v91;
    v93.m128_f32[0] = (float)((float)(v91.m128_f32[0] * v91.m128_f32[0]) + (float)(v92 * v92)) + (float)(v90 * v90);
    if ( v93.m128_f32[0] == 0.0 )
      v94 = 0.0;
    else
      v94 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v93));
    transform.v2.x = v94 * v92;
    transform.v2.y = v94 * v91.m128_f32[0];
    transform.v2.z = v94 * v90;
    transform.v2.w = 0.0;
    transform.v0.y = 1.0;
  }
  if ( v7 )
  {
    v95 = 0;
    vAimDirection.x = v57;
    vAimDirection.y = v58;
    vAimDirection.z = v59;
    if ( v3->mReturnTrueIfHitTarget )
      trueIfHits = (UFG::SimObject *)&v60->vfptr;
    if ( UFG::SensorComponent::CastSphere(
           v7,
           &transform,
           v3->mRadius,
           v3->mCollisionLayer,
           &v3->mStart,
           &vAimDirection,
           trueIfHits) )
    {
      v96 = v7->mSphereCaster;
      v97 = (UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *)v96->mHitList.mNode.mNext;
      v98 = (signed __int64)&v96->mHitList;
      if ( v97 != &v96->mHitList )
      {
        while ( !BrokenVehicleGlassSphereCastCondition::IsBrokenVehicleGlass(v3, v97) )
        {
          v97 = (UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *)v97->mNode.mNext;
          if ( v97 == (UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *)v98 )
            return v95;
        }
        v95 = 1;
      }
    }
    return v95;
  }
  UFG::ShapeCasterCollector::ShapeCasterCollector(
    (UFG::ShapeCasterCollector *)&transform.v1.z,
    v3->mRadius,
    v3->mCollisionLayer,
    0);
  v100 = v3->mStart.y;
  v101 = v3->mStart.z;
  v102 = (float)((float)((float)(v3->mStart.y * transform.v1.x) + (float)(v3->mStart.x * transform.v0.x))
               + (float)(v3->mStart.z * transform.v2.x))
       + vAimDirection.z;
  v103 = (float)((float)((float)(v3->mStart.y * transform.v1.y) + (float)(v3->mStart.x * transform.v0.y))
               + (float)(v3->mStart.z * transform.v2.y))
       + v110;
  v118 = v3->mStart.x * transform.v0.z;
  v118 = v118 + (float)(v100 * transform.v1.z);
  vAimDirection.x = (float)((float)((float)(transform.v1.x * v119) + (float)(transform.v0.x * v120))
                          + (float)(transform.v2.x * transform.v0.z))
                  + vAimDirection.z;
  vAimDirection.y = (float)((float)((float)(transform.v1.y * v119) + (float)(transform.v0.y * v120))
                          + (float)(transform.v2.y * transform.v0.z))
                  + v110;
  vAimDirection.z = (float)((float)((float)(transform.v1.z * v119) + (float)(transform.v0.z * v120))
                          + (float)(transform.v2.z * transform.v0.z))
                  + transform.v0.x;
  transform.v0.w = v102;
  transform.v1.x = v103;
  transform.v1.y = (float)(v118 + (float)(v101 * transform.v2.z)) + transform.v0.x;
  v104 = UFG::BasePhysicsSystem::CastShape(
           UFG::BasePhysicsSystem::mInstance,
           (UFG::ShapeCasterCollector *)&transform.v1.z,
           (UFG::qVector3 *)&transform.v0.w,
           &vAimDirection);
  v105 = *(_QWORD *)&transform.v2.z;
  if ( v104 )
  {
    if ( !v3->mReturnTrueIfHitTarget )
    {
LABEL_122:
      v107 = 1;
      goto LABEL_124;
    }
    v106 = *(_QWORD *)&transform.v2.z;
    if ( *(UFG::qMatrix44 **)&transform.v2.z != (UFG::qMatrix44 *)&transform.v2 )
    {
      while ( *(UFG::SimObjectCVBase **)(v106 + 80) != v60 )
      {
        v106 = *(_QWORD *)(v106 + 8);
        if ( (UFG::qVector4 *)v106 == &transform.v2 )
          goto LABEL_123;
      }
      goto LABEL_122;
    }
  }
LABEL_123:
  v107 = 0;
LABEL_124:
  v108 = 0;
  if ( v107 && *(UFG::qMatrix44 **)&transform.v2.z != (UFG::qMatrix44 *)&transform.v2 )
  {
    while ( !BrokenVehicleGlassSphereCastCondition::IsBrokenVehicleGlass(v3, (void *)v105) )
    {
      v105 = *(_QWORD *)(v105 + 8);
      if ( (UFG::qVector4 *)v105 == &transform.v2 )
        goto LABEL_130;
    }
    v108 = 1;
  }
LABEL_130:
  UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&transform.v1.z);
  return v108;
}

// File Line: 7465
// RVA: 0x27E010
char __fastcall BrokenVehicleGlassSphereCastCondition::IsBrokenVehicleGlass(BrokenVehicleGlassSphereCastCondition *this, void *fuckingToolsBuild)
{
  char *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::VehicleEffectsComponent *v6; // rbx
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  UFG::qReflectHandleBase v10; // [rsp+28h] [rbp-30h]

  v2 = (char *)fuckingToolsBuild;
  if ( !(_S13_0 & 1) )
  {
    _S13_0 |= 1u;
    vehicleGlassUID = UFG::qStringHashUpper32("Glass_Vehicle", 0xFFFFFFFF);
  }
  v3 = (UFG::SimObjectGame *)*((_QWORD *)v2 + 10);
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
  }
  else
  {
    if ( (v4 & 0x8000u) != 0 )
    {
      v6 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent;
      goto LABEL_14;
    }
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleEffectsComponent::_TypeUID);
    }
  }
  v6 = (UFG::VehicleEffectsComponent *)v5;
LABEL_14:
  if ( v6 )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v10);
    v8 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v7);
    v10.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v10, v10.mTypeUID, *((_QWORD *)v2 + 12));
    if ( v10.mData
      && LODWORD(v10.mData[2].vfptr) == vehicleGlassUID
      && UFG::VehicleEffectsComponent::IsGlassBroken(v6, (UFG::qVector3 *)(v2 + 16)) )
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
  TargetParkourHandleCondition *v1; // rbx

  v1 = this;
  ParkourHandleCondition::ParkourHandleCondition((ParkourHandleCondition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetParkourHandleCondition::`vftable;
  v1->m_eTargetType.mValue = 0;
}

// File Line: 7558
// RVA: 0x27B6D0
UFG::ParkourHandle *__fastcall TargetParkourHandleCondition::FindClosestParkourHandle(UFG::ParkourComponent *parkourComponent, UFG::qVector3 *position, UFG::qVector3 *orientationVector, const float relativeAngle, const float bufferZone, const float distanceXYMin, const float distanceXYMax, const float distanceZMin, const float distanceZMax, unsigned int check, UFG::qVector3 *contactPosition)
{
  int *v11; // rsi
  UFG::qVector3 *v12; // r15
  UFG::ParkourHandle *v13; // rdi
  unsigned int v14; // ebp
  unsigned int v15; // ebx
  UFG::qVector3 *v16; // r14
  UFG::ParkourHandle *v17; // rdi
  int v18; // xmm1_4
  int v19; // xmm2_4
  UFG::ParkourHandle *result; // rax
  float v21; // [rsp+80h] [rbp-B8h]
  UFG::ParkourHandle *v22; // [rsp+88h] [rbp-B0h]
  __int64 v23; // [rsp+90h] [rbp-A8h]
  int v24; // [rsp+98h] [rbp-A0h]
  int v25; // [rsp+9Ch] [rbp-9Ch]
  int v26; // [rsp+A0h] [rbp-98h]
  __int64 v27; // [rsp+A8h] [rbp-90h]
  void *mem; // [rsp+B0h] [rbp-88h]

  v23 = -2i64;
  v11 = (int *)orientationVector;
  v12 = position;
  v13 = 0i64;
  v22 = 0i64;
  v21 = FLOAT_3_4028235e38;
  v14 = check;
  if ( !(check & 1) )
    goto LABEL_16;
  mem = 0i64;
  v27 = 0i64;
  UFG::ParkourQueryManager::UpdateOrCreateAllHandles(
    UFG::ParkourQueryManager::mInstance,
    parkourComponent,
    (UFG::qArray<UFG::ParkourHandle *,0> *)&v27);
  v15 = 0;
  if ( (unsigned int)v27 > 0 )
  {
    v16 = contactPosition;
    do
    {
      v17 = (UFG::ParkourHandle *)*((_QWORD *)mem + v15);
      if ( v17 && UFG::ParkourHandle::IsEnabled(*((UFG::ParkourHandle **)mem + v15)) )
      {
        v18 = v11[1];
        v19 = v11[2];
        v24 = *v11;
        v25 = v18;
        v26 = v19;
        compareParkourHandles(
          v14,
          v12,
          (UFG::qVector3 *)&v24,
          relativeAngle,
          bufferZone,
          distanceXYMin,
          distanceXYMax,
          distanceZMin,
          distanceZMax,
          v16,
          v17,
          &v22,
          &v21,
          (bool *)&check,
          0);
      }
      ++v15;
    }
    while ( v15 < (unsigned int)v27 );
    v13 = v22;
  }
  if ( mem )
    operator delete[](mem);
  mem = 0i64;
  v27 = 0i64;
  if ( v13 )
    result = v13;
  else
LABEL_16:
    result = 0i64;
  return result;
}

// File Line: 7609
// RVA: 0x28D2B0
char __fastcall TargetParkourHandleCondition::Match(TargetParkourHandleCondition *this, ActionContext *context)
{
  TargetParkourHandleCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  char v4; // r12
  ActionNode *v5; // r14
  ActionContext *v6; // r15
  UFG::SimComponent *v7; // rdi
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::SimObjectCVBase *v10; // rcx
  UFG::CharacterAnimationComponent *v11; // rax
  unsigned __int16 v12; // dx
  UFG::SimObject *v13; // rcx
  UFG::TransformNodeComponent *v14; // rsi
  UFG::SimObjectGame *v15; // rdi
  unsigned __int16 v16; // cx
  UFG::SimComponent *v17; // rax
  unsigned __int16 v18; // cx
  UFG::SimComponent *v19; // rax
  UFG::ParkourComponent *v20; // rdi
  float v21; // xmm1_4
  float v22; // xmm0_4
  UFG::SimObjectGame *v23; // rcx
  UFG::AimingBaseComponent *v24; // rax
  unsigned __int16 v25; // dx
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  float v28; // xmm4_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  UFG::ParkourHandle *v33; // rax
  UFG::ParkourHandle *v34; // rdi
  UFG::SimObjectGame *v36; // rcx
  unsigned __int16 v37; // dx
  UFG::WorldContextComponent *v38; // rax
  __int64 v39; // rcx
  float v40; // xmm9_4
  float v41; // xmm11_4
  float v42; // xmm10_4
  float v43; // xmm0_4
  UFG::qVector3 *v44; // rax
  float v45; // xmm6_4
  float v46; // xmm7_4
  float v47; // xmm8_4
  UFG::qVector3 *v48; // rax
  float v49; // xmm9_4
  float v50; // xmm11_4
  float v51; // xmm10_4
  UFG::qVector3 *v52; // rax
  float v53; // xmm11_4
  float v54; // xmm0_4
  UFG::qVector3 vAimDirection; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 result; // [rsp+70h] [rbp-90h]
  UFG::qVector3 position; // [rsp+80h] [rbp-80h]
  UFG::qVector3 dest; // [rsp+90h] [rbp-70h]
  UFG::qVector3 pointAlongHandle; // [rsp+A0h] [rbp-60h]
  UFG::qVector3 v60; // [rsp+B0h] [rbp-50h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0;
  v5 = 0i64;
  v6 = context;
  if ( v3 )
  {
    v8 = v3->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v7 = v9;
    }
    else
    {
      v7 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v10 = (UFG::SimObjectCVBase *)v6->mSimObject.m_pPointer;
  if ( v10 )
  {
    v12 = v10->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v11 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v11 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v10->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v10->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
    }
  }
  else
  {
    v11 = 0i64;
  }
  v13 = v6->mSimObject.m_pPointer;
  v14 = 0i64;
  if ( v13 )
    v14 = v13->m_pTransformNodeComponent;
  if ( !v7 )
    return v4;
  if ( !v11 )
    return v4;
  if ( !v13 )
    return v4;
  if ( !v13->m_pTransformNodeComponent )
    return v4;
  v15 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)v2->m_eTargetType.mValue
                                                    + *(_QWORD *)&v7[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v7[1].m_TypeUID
                               + 40);
  if ( !v15 )
    return v4;
  v16 = v15->m_Flags;
  if ( (v16 >> 14) & 1 )
    return v4;
  if ( (v16 & 0x8000u) == 0 )
  {
    if ( (v16 >> 13) & 1 )
      return v4;
    if ( (v16 >> 12) & 1 )
      v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::PhysicsMoverInterface::_TypeUID);
    else
      v17 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
  }
  else
  {
    v17 = v15->m_Components.p[34].m_pComponent;
  }
  if ( v17 )
  {
    v18 = v15->m_Flags;
    if ( (v18 >> 14) & 1 )
    {
      v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::ParkourComponent::_TypeUID);
    }
    else if ( (v18 & 0x8000u) == 0 )
    {
      if ( (v18 >> 13) & 1 )
        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::ParkourComponent::_TypeUID);
      else
        v19 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::ParkourComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::ParkourComponent::_TypeUID);
    }
    else
    {
      v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::ParkourComponent::_TypeUID);
    }
    v20 = (UFG::ParkourComponent *)v19;
    if ( v19 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v14);
      v21 = v14->mWorldTransform.v3.y;
      position.x = v14->mWorldTransform.v3.x;
      v22 = v14->mWorldTransform.v3.z;
      position.y = v21;
      position.z = v22;
      if ( v2->mUseAimingDirection )
      {
        v23 = (UFG::SimObjectGame *)v6->mSimObject.m_pPointer;
        if ( v23 )
        {
          v25 = v23->m_Flags;
          if ( (v25 >> 14) & 1 )
          {
            v24 = (UFG::AimingBaseComponent *)v23->m_Components.p[47].m_pComponent;
          }
          else if ( (v25 & 0x8000u) == 0 )
          {
            if ( (v25 >> 13) & 1 )
              v24 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v23,
                                                  UFG::AimingBaseComponent::_TypeUID);
            else
              v24 = (UFG::AimingBaseComponent *)((v25 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v23,
                                                                     UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v23->vfptr, UFG::AimingBaseComponent::_TypeUID));
          }
          else
          {
            v24 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v23,
                                                UFG::AimingBaseComponent::_TypeUID);
          }
        }
        else
        {
          v24 = 0i64;
        }
        UFG::AimingBaseComponent::GetAimDirection(v24, &vAimDirection, 0i64);
        vAimDirection.z = 0.0;
        v26 = (__m128)LODWORD(vAimDirection.x);
        v27 = v26;
        v27.m128_f32[0] = (float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(vAimDirection.y * vAimDirection.y);
        LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v27);
        if ( v28 <= 0.001 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v14);
          v30 = v14->mWorldTransform.v0.y;
          result.x = v14->mWorldTransform.v0.x;
          v29 = v14->mWorldTransform.v0.z;
          result.y = v30;
        }
        else
        {
          v29 = (float)(1.0 / v28) * 0.0;
          result.x = vAimDirection.x * (float)(1.0 / v28);
          result.y = vAimDirection.y * (float)(1.0 / v28);
        }
        result.z = v29;
        v31 = result.y;
        vAimDirection.x = result.x;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v14);
        v31 = v14->mWorldTransform.v0.y;
        vAimDirection.x = v14->mWorldTransform.v0.x;
        v29 = v14->mWorldTransform.v0.z;
      }
      v32 = v2->mDirection;
      vAimDirection.z = v29;
      vAimDirection.y = v31;
      UFG::qRotateVectorZ(&dest, &vAimDirection, v32);
      v33 = TargetParkourHandleCondition::FindClosestParkourHandle(
              v20,
              &position,
              &dest,
              v2->mRelativeAngle,
              v2->mBufferZone,
              v2->mDistanceXYMin,
              v2->mDistanceXYMax,
              v2->mDistanceZMin,
              v2->mDistanceZMax,
              (v2->mCheckLedgeDropoff != 0 ? 0x80 : 0) | (v2->mCheckParkourHandle != 0) | (v2->mCheckLedge != 0 ? 2 : 0) | (v2->mCheckFence != 0 ? 4 : 0) | (v2->mCheckVault != 0 ? 8 : 0) | (v2->mCheckRail != 0 ? 0x10 : 0) | (v2->mCheckWall != 0 ? 0x20 : 0) | (v2->mCheckLeap != 0 ? 0x40 : 0) | (v2->mCheckActionHijackClimb != 0 ? 0x100 : 0) | (v2->mCheckCover != 0 ? 0x200 : 0),
              &pointAlongHandle);
      v34 = v33;
      if ( v33 )
      {
        if ( v2->mCheckLedgeDropoff
          && UFG::ParkourHandle::GetDropoffDistance(v33, &pointAlongHandle, v2->mDropoffCastRadius) < v2->mMinDropoffHeight )
        {
          return 0;
        }
        v36 = (UFG::SimObjectGame *)v6->mSimObject.m_pPointer;
        if ( v36 )
        {
          v37 = v36->m_Flags;
          if ( (v37 >> 14) & 1 )
          {
            v38 = (UFG::WorldContextComponent *)v36->m_Components.p[28].m_pComponent;
          }
          else if ( (v37 & 0x8000u) == 0 )
          {
            if ( (v37 >> 13) & 1 )
              v38 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v36,
                                                    UFG::WorldContextComponent::_TypeUID);
            else
              v38 = (UFG::WorldContextComponent *)((v37 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v36,
                                                                       UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v36->vfptr, UFG::WorldContextComponent::_TypeUID));
          }
          else
          {
            v38 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v36,
                                                  UFG::WorldContextComponent::_TypeUID);
          }
          if ( v38 && v2->mSetFocusHandle )
          {
            v39 = v2->mParentNode.mOffset;
            if ( v39 )
              v5 = (ActionNode *)((char *)&v2->mParentNode + v39);
            UFG::WorldContextComponent::SetFocusParkourHandle(v38, v34, v5);
          }
        }
        v4 = 1;
        if ( v2->mCheckDistance )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v14);
          v40 = v14->mWorldTransform.v3.x;
          v41 = v14->mWorldTransform.v3.y;
          v42 = v14->mWorldTransform.v3.z;
          v43 = UFG::ParkourHandle::GetHalfLength(v34);
          v44 = UFG::ParkourHandle::GetAxis(v34, &result);
          v45 = v43 * v44->x;
          v46 = v43 * v44->y;
          v47 = v43 * v44->z;
          v48 = UFG::ParkourHandle::GetPosition(v34, &v60);
          v49 = v40 - (float)(v48->x - v45);
          v50 = v41 - (float)(v48->y - v46);
          v51 = v42 - (float)(v48->z - v47);
          v52 = UFG::ParkourHandle::GetAxis(v34, &v60);
          v53 = (float)((float)(v50 * v52->y) + (float)(v49 * v52->x)) + (float)(v51 * v52->z);
          if ( v2->mCheckLeft )
            v4 = CompareFloat((UFG::InEqualityOperator)v2->mInEqualityOperator.mValue, v2->mEdgeDistance, v53);
          if ( v2->mCheckRight )
          {
            v54 = UFG::ParkourHandle::GetHalfLength(v34);
            v4 = CompareFloat(
                   (UFG::InEqualityOperator)v2->mInEqualityOperator.mValue,
                   v2->mEdgeDistance,
                   COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v54 * 2.0) - v53) & _xmm));
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
  DropoffCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&DropoffCondition::`vftable;
  *(_WORD *)&v1->mCheckDropoff = 1;
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
  OnGround *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  char v7; // si
  char v8; // dl
  unsigned int v9; // ecx

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[27].m_pComponent;
  }
  else
  {
    if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    v5 = v6;
  }
  if ( !v5 )
    return 0;
  v7 = CompareFloat(
         (UFG::InEqualityOperator)(unsigned __int8)v2->mDistanceInEqualityOperator.mValue,
         v2->mFallDistance,
         *((float *)&v5[5].m_BoundComponentHandles.mNode.mNext + 1));
  v8 = CompareFloat(
         (UFG::InEqualityOperator)(unsigned __int8)v2->mTimeInEqualityOperator.mValue,
         v2->mFallTime,
         *(float *)&v5[6].vfptr);
  if ( v2->mUseFiltered )
    v9 = v5[6].m_NameUID >> 1;
  else
    LOBYTE(v9) = v5[6].m_NameUID;
  return v9 & 1 && v7 && v8;
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
  OnGroundSurfaceType *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  char v9; // bl
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        else
          v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 && v2->mStairs )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      v8 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v7);
      v11.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, (unsigned __int64)v5[6].m_SafePointerList.mNode.mNext);
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
  OnGroundSurfaceGrade *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  float *v6; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rdi
  UFG::TransformNodeComponent *v9; // rdi
  __m128 v10; // xmm3
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm1_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = (float *)v3->m_Components.p[27].m_pComponent;
  }
  else
  {
    if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    v6 = (float *)v7;
  }
  if ( !v6 )
    return 0;
  v8 = v4->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_pTransformNodeComponent;
  if ( !v9 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v10 = (__m128)LODWORD(v9->mWorldTransform.v0.y);
  v11 = v9->mWorldTransform.v0.x;
  v12 = v9->mWorldTransform.v0.z;
  v13 = (float)((float)(v6[89] * v11) + (float)(v6[90] * v10.m128_f32[0])) + (float)(v6[91] * v12);
  if ( v13 <= -0.94999999 || v13 >= 0.94999999 )
    return 0;
  v14 = v12 - (float)(v6[91] * v13);
  v10.m128_f32[0] = (float)((float)((float)(v10.m128_f32[0] - (float)(v6[90] * v13))
                                  * (float)(v10.m128_f32[0] - (float)(v6[90] * v13)))
                          + (float)((float)(v11 - (float)(v6[89] * v13)) * (float)(v11 - (float)(v6[89] * v13))))
                  + (float)(v14 * v14);
  v15 = 0.0;
  if ( v10.m128_f32[0] != 0.0 )
    v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v16 = v15 * v14;
  UFG::qASin(v16);
  return v16 >= v2->mMinGrade && v16 < v2->mMaxGrade;
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
  HitTime *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HitTime::`vftable;
  v1->mHitTime = 0.0;
  v1->mInEqualityOperator.mValue = 4;
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
  AttackType *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackType::`vftable;
  v1->mAttackTypeID = 0;
}

// File Line: 7988
// RVA: 0x27EED0
bool __fastcall AttackType::Match(AttackType *this, ActionContext *context)
{
  AttackType *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = v2->mAttackTypeID == HIDWORD(v5[2].m_BoundComponentHandles.mNode.mNext);
  }
  else
  {
    result = 0;
  }
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
  AttackLocationLateral *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackLocationLateral::`vftable;
  v1->mAttackLocationLateralID = 0;
}

// File Line: 8017
// RVA: 0x27EBC0
bool __fastcall AttackLocationLateral::Match(AttackLocationLateral *this, ActionContext *context)
{
  AttackLocationLateral *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = v2->mAttackLocationLateralID == LODWORD(v5[3].m_pSimObject);
  }
  else
  {
    result = 0;
  }
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
  AttackLocationHorizontal *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackLocationHorizontal::`vftable;
  v1->mAttackLocationHorizontalID = 0;
}

// File Line: 8045
// RVA: 0x27EB10
bool __fastcall AttackLocationHorizontal::Match(AttackLocationHorizontal *this, ActionContext *context)
{
  AttackLocationHorizontal *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = v2->mAttackLocationHorizontalID == HIDWORD(v5[3].m_pSimObject);
  }
  else
  {
    result = 0;
  }
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
  AttackLocationRagdoll *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackLocationRagdoll::`vftable;
  v1->m_iRagdollComponentID = 0;
}

// File Line: 8075
// RVA: 0x27EC70
bool __fastcall AttackLocationRagdoll::Match(AttackLocationRagdoll *this, ActionContext *pContext)
{
  AttackLocationRagdoll *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  bool v9; // bl
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[15].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[15].m_pComponent;
    }
    if ( v5 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
      v11.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, *(_QWORD *)&v5[5].m_Flags);
      if ( v11.mData )
      {
        v9 = v2->m_iRagdollComponentID == LODWORD(v11.mData[2].mTypeUID);
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
  CollisionTime *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollisionTime::`vftable;
  v1->mCollisionTime = 0.0;
  v1->mInEqualityOperator.mValue = 4;
}

// File Line: 8113
// RVA: 0x282830
char __fastcall HitTime::Match(HitTime *this, ActionContext *context)
{
  HitTime *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mHitTime,
               *(float *)&v5[3].m_Flags);
  }
  else
  {
    result = 0;
  }
  return result;
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
  CollisionLayer *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollisionLayer::`vftable;
  v1->mCollisionLayer = 1;
}

// File Line: 8146
// RVA: 0x2802E0
bool __fastcall CollisionLayer::Match(CollisionLayer *this, ActionContext *context)
{
  CollisionLayer *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  unsigned __int64 v6; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  bool v9; // bl
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[15].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      v5 = v3->m_Components.p[15].m_pComponent;
    }
    if ( v5 )
    {
      v6 = (unsigned __int64)v5[5].m_pSimObject;
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
      v11.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, v6);
      if ( v11.mData )
      {
        v9 = LODWORD(v11.mData[2].mBaseNode.mChildren[0]) == v2->mCollisionLayer;
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
  CollisionSpeed *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollisionSpeed::`vftable;
  v1->mCollisionSpeed = 0.0;
  *(_WORD *)&v1->mInEqualityOperator.mValue = 1;
}

// File Line: 8187
// RVA: 0x280500
char __fastcall CollisionSpeed::Match(CollisionSpeed *this, ActionContext *context)
{
  CollisionSpeed *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[15].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[15].m_pComponent;
  }
  if ( !v5 )
    return 0;
  if ( v2->mUseForwardSpeed )
    return CompareFloat(
             (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
             v2->mCollisionSpeed,
             *(float *)&v5[6].m_pSimObject);
  return CompareFloat(
           (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
           v2->mCollisionSpeed,
           *(float *)(&v5[6].m_SimObjIndex + 1));
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
void __fastcall CollisionEstimatedImpulseMagnitude::CollisionEstimatedImpulseMagnitude(CollisionEstimatedImpulseMagnitude *this)
{
  CollisionEstimatedImpulseMagnitude *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollisionEstimatedImpulseMagnitude::`vftable;
  v1->mEstimatedImpulseMagnitude = 0.0;
  v1->mInEqualityOperator.mValue = 1;
}

// File Line: 8227
// RVA: 0x280220
char __fastcall CollisionEstimatedImpulseMagnitude::Match(CollisionEstimatedImpulseMagnitude *this, ActionContext *context)
{
  CollisionEstimatedImpulseMagnitude *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  float v6; // xmm2_4
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[15].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[15].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = *((float *)&v5[6].m_pSimObject + 1);
  if ( v6 >= 0.0 )
    result = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mEstimatedImpulseMagnitude,
               v6);
  else
    result = 1;
  return result;
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
  CollisionMass *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollisionMass::`vftable;
  v1->mCollisionMass = 0.0;
  v1->mInEqualityOperator.mValue = 1;
}

// File Line: 8271
// RVA: 0x2803F0
char __fastcall CollisionMass::Match(CollisionMass *this, ActionContext *context)
{
  CollisionMass *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  unsigned __int64 v6; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  char v9; // bl
  UFG::qReflectHandleBase v11; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[15].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      v5 = v3->m_Components.p[15].m_pComponent;
    }
    if ( v5 )
    {
      v6 = (unsigned __int64)v5[5].m_pSimObject;
      UFG::qReflectHandleBase::qReflectHandleBase(&v11);
      v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
      v11.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v11, v11.mTypeUID, v6);
      if ( v11.mData )
      {
        v9 = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mCollisionMass,
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
  AttackTimerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackTimerCondition::`vftable;
  v1->mAttackTime = 0.0;
  v1->mInEqualityOperator.mValue = 4;
}

// File Line: 8316
// RVA: 0x27EE20
char __fastcall AttackTimerCondition::Match(AttackTimerCondition *this, ActionContext *context)
{
  AttackTimerCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mAttackTime,
               *(float *)&v5[1].m_TypeUID);
  }
  else
  {
    result = 0;
  }
  return result;
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
  AttackPhaseCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackPhaseCondition::`vftable;
  v1->m_eAttackPhase.mValue = 1;
}

// File Line: 8353
// RVA: 0x27ED80
bool __fastcall AttackPhaseCondition::Match(AttackPhaseCondition *this, ActionContext *pContext)
{
  AttackPhaseCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = v5[1].m_NameUID == (unsigned __int8)v2->m_eAttackPhase.mValue;
  }
  else
  {
    result = 0;
  }
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
  AttackInfoNumberHitsCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackInfoNumberHitsCondition::`vftable;
  v1->mInEqualityOperator.mValue = 1;
  v1->mQuantity = 0;
}

// File Line: 8390
// RVA: 0x27E9B0
bool __fastcall AttackInfoNumberHitsCondition::Match(AttackInfoNumberHitsCondition *this, ActionContext *pContext)
{
  AttackInfoNumberHitsCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = CompareInt(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mQuantity,
               *(_DWORD *)&v5[7].m_Flags);
  }
  else
  {
    result = 0;
  }
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
  AttackIntensityCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackIntensityCondition::`vftable;
  v1->m_eAttackItensityType.mValue = 0;
}

// File Line: 8426
// RVA: 0x27EA60
bool __fastcall AttackIntensityCondition::Match(AttackIntensityCondition *this, ActionContext *context)
{
  AttackIntensityCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = (unsigned __int8)v2->m_eAttackItensityType.mValue == HIDWORD(v5[3].m_BoundComponentHandles.mNode.mNext);
  }
  else
  {
    result = 0;
  }
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
  AttackDamageCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackDamageCondition::`vftable;
  v1->mInEqualityOperator.mValue = 1;
  v1->mAmount = 0;
}

// File Line: 8460
// RVA: 0x27E900
bool __fastcall AttackDamageCondition::Match(AttackDamageCondition *this, ActionContext *context)
{
  AttackDamageCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = CompareInt(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mAmount,
               (int)v5[3].vfptr);
  }
  else
  {
    result = 0;
  }
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
  InventoryQuantityCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InventoryQuantityCondition::`vftable;
  v1->mInventoryItem = 0;
  v1->mInEqualityOperator.mValue = 1;
  v1->mQuantity = 0;
}

// File Line: 8496
// RVA: 0x283860
bool __fastcall InventoryQuantityCondition::Match(InventoryQuantityCondition *this, ActionContext *context)
{
  InventoryQuantityCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  __int64 v7; // rax
  int v8; // er8

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[39].m_pComponent;
  }
  else
  {
    if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InventoryComponent::_TypeUID);
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID);
    }
    v5 = v6;
  }
  if ( !v5 )
    return 0;
  v7 = v2->mInventoryItem;
  if ( !LOBYTE(v5[14].m_pSimObject) || (v8 = 1, (_DWORD)v7 != *(_DWORD *)&v5[14].m_Flags) )
    v8 = *(&v5[1].m_NameUID + v7);
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mQuantity, v8);
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
  InventoryIsItemEquipped *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InventoryIsItemEquipped::`vftable;
  v1->mInventoryItem = 0;
}

// File Line: 8542
// RVA: 0x283730
bool __fastcall InventoryIsItemEquipped::Match(InventoryIsItemEquipped *this, ActionContext *context)
{
  InventoryIsItemEquipped *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  __int64 v6; // r8
  __int64 v7; // rdx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  int v11; // ecx

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = *(_QWORD *)&v5[1].m_TypeUID;
  v7 = *(_QWORD *)&v5[1].m_Flags;
  v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v7 + 25) + v6 + 40);
  if ( !v8 )
  {
    v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v7 + 26) + v6 + 40);
    if ( !v8 )
      return 0;
  }
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 || (v9 & 0x8000u) != 0 )
    return 0;
  if ( (v9 >> 13) & 1 )
    v10 = v8->m_Components.p[11].m_pComponent;
  else
    v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::InventoryItemComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::InventoryItemComponent::_TypeUID);
  if ( !v10 )
    return 0;
  v11 = (int)v10[1].m_pSimObject;
  return v11 && v2->mInventoryItem == v11;
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
  InventoryCanDrop *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InventoryCanDrop::`vftable;
  v1->mEquipSlot.mValue = 0;
}

// File Line: 8590
// RVA: 0x283680
bool __fastcall InventoryCanDrop::Match(InventoryCanDrop *this, ActionContext *context)
{
  InventoryCanDrop *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::InventoryComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InventoryComponent::_TypeUID)) : (v5 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID))) : (v5 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID))) : (v5 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID))) : (v5 = (UFG::InventoryComponent *)v3->m_Components.p[39].m_pComponent),
        v5) )
  {
    result = UFG::InventoryComponent::GetCanDrop(v5, (UFG::eInventoryEquipSlot)(unsigned __int8)v2->mEquipSlot.mValue);
  }
  else
  {
    result = 1;
  }
  return result;
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
  RandomCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&RandomCondition::`vftable{for `Condition};
  v1->vfptr = (IWeightedConditionVtbl *)&RandomCondition::`vftable{for `IWeightedCondition};
  v1->m_pParentBank = 0i64;
  v1->mWeight = 50.0;
  v1->mNormalizedWeight = -1.0;
  v1->mNormalizedWeightCorrectlySet = 1;
  v1->mWeightLevel = 0;
}

// File Line: 8633
// RVA: 0x294100
void __fastcall RandomCondition::ResolveReferences(RandomCondition *this, ActionNode *action_node)
{
  __int64 v2; // rax
  RandomCondition *v3; // rdi
  ActionNodeBank *v4; // rbx

  v2 = action_node->mParent.mOffset;
  v3 = this;
  if ( v2 )
  {
    v4 = (ActionNodeBank *)((char *)&action_node->mParent + v2);
    if ( v4 )
    {
      if ( v4->vfptr->GetClassNameUID((Expression::IMemberMap *)&v4->vfptr) == ActionNodeBank::sClassNameUID )
        v3->m_pParentBank = v4;
    }
  }
}

// File Line: 8643
// RVA: 0x2893D0
bool __fastcall RandomCondition::Match(RandomCondition *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  RandomCondition *v3; // rdi
  ActionNode *v4; // rdx

  v2 = context;
  v3 = this;
  if ( this->mNormalizedWeight < 0.0 )
    this->mNormalizedWeightCorrectlySet = 0;
  if ( !this->mNormalizedWeightCorrectlySet )
  {
    ((void (__fastcall *)(IWeightedConditionVtbl **))this->vfptr->GetWeightToBalance)(&this->vfptr);
    ((void (__fastcall *)(IWeightedConditionVtbl **))v3->vfptr->SetBalancedWeight)(&v3->vfptr);
  }
  if ( !v2->mProbabilitiesValid )
  {
    v4 = (ActionNode *)&v3->m_pParentBank->vfptr;
    if ( !v4 || !ActionController::IsPlaying(v2->mActionController, v4) )
      ActionContext::UpdateProbabilites(v2);
  }
  return v2->mProbabilitys[v3->mWeightLevel] < v3->mNormalizedWeight;
}

// File Line: 8717
// RVA: 0x27D5D0
UFG::qPropertySet *__fastcall GetPersonalityPropertySet(ActionContext *action_context, Condition *condition)
{
  UFG::SimObject *v2; // rax
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qSymbol *v4; // rdi
  UFG::qPropertySet *v5; // rax
  UFG::qPropertyList *v6; // rdi
  unsigned int v7; // eax
  UFG::qPropertySet *result; // rax

  v2 = action_context->mSimObject.m_pPointer;
  v3 = v2->m_pSceneObj;
  if ( !v3 )
    return 0i64;
  v4 = (UFG::qSymbol *)PropertyUtils::Get<UFG::qSymbol>(
                         v2->m_pSceneObj,
                         (UFG::qSymbol *)&qSymbol_PersonalityList_SelectedItem.mUID);
  if ( v4
    || (v5 = PropertyUtils::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&qSymbol_PersonalityList.mUID),
        (v6 = (UFG::qPropertyList *)v5) != 0i64)
    && (v7 = UFG::qPropertyList::GetRandomIndex((UFG::qPropertyList *)v5),
        v4 = UFG::qPropertyList::Get<UFG::qSymbol>(v6, v7),
        PropertyUtils::Set<UFG::qSymbol>(v3, (UFG::qSymbol *)&qSymbol_PersonalityList_SelectedItem.mUID, v4),
        v4) )
  {
    result = UFG::PropertySetManager::GetPropertySet(v4);
  }
  else
  {
    result = 0i64;
  }
  return result;
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
  PersonalityTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PersonalityTypeCondition::`vftable;
  v1->m_PersonalityTypeSymbol.mUID = -1;
  *(_QWORD *)&v1->m_PropertyValueUID = 0i64;
  v1->m_PersonalityTypeSymbol = UFG::gNullQSymbol;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 8786
// RVA: 0x294030
void __fastcall PersonalityTypeCondition::ResolveReferences(PersonalityTypeCondition *this, ActionNode *action_node)
{
  PersonalityTypeCondition *v2; // rbx
  unsigned int v3; // eax
  unsigned int v4; // ecx

  v2 = this;
  ((void (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  v3 = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_PropertyValueUID, eACTION_TREE_MEMORY_ELEMENT_QSYMBOL);
  v4 = v2->m_PropertyValueHasBeenReadUID;
  v2->m_PropertyValueUID = v3;
  v2->m_PropertyValueHasBeenReadUID = UFG::ActionTreeComponentBase::MakeValueUID(v4, eACTION_TREE_MEMORY_ELEMENT_BOOL);
}

// File Line: 8848
// RVA: 0x288AB0
bool __fastcall PersonalityTypeCondition::Match(PersonalityTypeCondition *this, ActionContext *context)
{
  ActionContext *v2; // rdi
  PersonalityTypeCondition *v3; // rsi
  __int64 v4; // rax
  UFG::ActionTreeComponentBase *v5; // rdx
  char *v6; // rcx
  UFG::ActionTreeComponentBase *v7; // rcx
  UFG::qPropertySet *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rcx
  int v11; // eax
  __int64 v12; // rax
  UFG::ActionTreeComponentBase *v13; // rdx
  signed __int64 v14; // rcx
  UFG::ActionTreeComponentBase *v15; // rcx
  ActionNodeRoot *v16; // r8
  unsigned int v17; // er9
  __int64 v18; // rax
  UFG::ActionTreeComponentBase *v19; // rdx
  signed __int64 v20; // rcx
  UFG::ActionTreeComponentBase *v21; // rcx
  __int64 v22; // rax
  UFG::ActionTreeComponentBase *v23; // rdx
  signed __int64 v24; // rcx
  UFG::ActionTreeComponentBase *v25; // rcx
  bool *value; // [rsp+20h] [rbp-28h]
  bool valuea; // [rsp+20h] [rbp-28h]
  unsigned int value_uid; // [rsp+50h] [rbp+8h]
  unsigned int v30; // [rsp+58h] [rbp+10h]
  int v31; // [rsp+60h] [rbp+18h]
  int *v32; // [rsp+68h] [rbp+20h]

  v2 = context;
  v3 = this;
  LOBYTE(value_uid) = 0;
  v4 = this->m_MyRoot.mOffset;
  if ( v4 )
    v5 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v4);
  else
    v5 = 0i64;
  if ( v4 )
    v6 = (char *)&this->m_MyRoot + v4;
  else
    v6 = 0i64;
  v7 = v2->mActionTreeComponentBase[v6[236]];
  if ( !v7 )
    v7 = v2->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v7,
    v5,
    (ActionNodeRoot *)v3->m_PropertyValueHasBeenReadUID,
    (unsigned __int64)&value_uid,
    (bool *)0xFFFFFFFFFFFFFFFEi64);
  v30 = UFG::gNullQSymbol.mUID;
  if ( (_BYTE)value_uid )
  {
    v22 = v3->m_MyRoot.mOffset;
    if ( v22 )
      v23 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v22);
    else
      v23 = 0i64;
    if ( v22 )
      v24 = (signed __int64)&v3->m_MyRoot + v22;
    else
      v24 = 0i64;
    v25 = v2->mActionTreeComponentBase[*(char *)(v24 + 236)];
    if ( !v25 )
      v25 = v2->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::qSymbol>(
      v25,
      v23,
      (ActionNodeRoot *)v3->m_PropertyValueUID,
      (unsigned __int64)&v30,
      (UFG::qSymbol *)value);
    goto LABEL_40;
  }
  v8 = GetPersonalityPropertySet(v2, (Condition *)&v3->vfptr);
  if ( !v8 )
  {
LABEL_40:
    v11 = v30;
    return v11 == v3->m_PersonalityTypeSymbol.mUID;
  }
  v9 = UFG::qPropertySet::Get<UFG::qSymbol>(v8, (UFG::qSymbol *)&qSymbol_PersonalityType.mUID, DEPTH_RECURSE);
  v10 = &UFG::gNullQSymbol;
  if ( v9 )
    v10 = v9;
  v11 = v10->mUID;
  v30 = v11;
  if ( v11 != UFG::gNullQSymbol.mUID )
  {
    v32 = &v31;
    v31 = v11;
    v12 = v3->m_MyRoot.mOffset;
    if ( v12 )
      v13 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v12);
    else
      v13 = 0i64;
    if ( v12 )
      v14 = (signed __int64)&v3->m_MyRoot + v12;
    else
      v14 = 0i64;
    v15 = v2->mActionTreeComponentBase[*(char *)(v14 + 236)];
    if ( !v15 )
      v15 = v2->mActionTreeComponentBase[1];
    v16 = (ActionNodeRoot *)v3->m_PropertyValueUID;
    LODWORD(v32) = v31;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::qSymbol>(
      v15,
      v13,
      v16,
      (unsigned __int64)&v32,
      (UFG::qSymbol)value);
    v18 = v3->m_MyRoot.mOffset;
    if ( v18 )
      v19 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v18);
    else
      v19 = 0i64;
    if ( v18 )
      v20 = (signed __int64)&v3->m_MyRoot + v18;
    else
      v20 = 0i64;
    v21 = v2->mActionTreeComponentBase[*(char *)(v20 + 236)];
    if ( !v21 )
      v21 = v2->mActionTreeComponentBase[1];
    LOBYTE(v17) = 1;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v21,
      v19,
      (ActionNodeRoot *)v3->m_PropertyValueHasBeenReadUID,
      v17,
      valuea);
    goto LABEL_40;
  }
  return v11 == v3->m_PersonalityTypeSymbol.mUID;
}_PropertyValueHasBeenReadUID,
      v17,
      valuea);
    goto LABEL_40;
  }
  return v11 == v3->m_Personal

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
  AiBehaviourCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AiBehaviourCondition::`vftable;
  v1->mMostUsedIndex = -1;
  v1->mCheckSpawns = 0;
}

// File Line: 8922
// RVA: 0x27E2A0
unsigned __int8 __fastcall AiBehaviourCondition::Match(AiBehaviourCondition *this, ActionContext *context)
{
  AiBehaviourCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  unsigned __int8 result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3
    || ((v5 = v3->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIEntityComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIEntityComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIEntityComponent::_TypeUID))) : (v6 = v3->m_Components.p[22].m_pComponent)) : (v6 = v3->m_Components.p[22].m_pComponent),
        !v6) )
  {
    v7 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
    if ( !v7 )
      goto LABEL_38;
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v7->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      else
        v9 = (UFG::AiDriverComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v7->vfptr,
                                                           UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v7->vfptr,
                                                                                                 UFG::AiDriverComponent::_TypeUID));
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
    }
    if ( !v9 )
      goto LABEL_38;
  }
  v10 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v10
    && ((v11 = v10->m_Flags, !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::AIActionTreeComponent::_TypeUID)) : (v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::AIActionTreeComponent::_TypeUID))) : (v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::AIActionTreeComponent::_TypeUID))) : (v12 = v10->m_Components.p[19].m_pComponent)) : (v12 = v10->m_Components.p[19].m_pComponent),
        v12) )
  {
    result = ActionController::IsPlaying(
               (ActionController *)&v12[3].m_TypeUID,
               &v2->mAIBehaviourID,
               v2->mMostUsedIndex,
               v2->mCheckSpawns != 0);
  }
  else
  {
LABEL_38:
    result = 0;
  }
  return result;
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
  AiBehaviourTreeTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AiBehaviourTreeTypeCondition::`vftable;
}

// File Line: 8978
// RVA: 0x27E450
bool __fastcall AiBehaviourTreeTypeCondition::Match(AiBehaviourTreeTypeCondition *this, ActionContext *context)
{
  AiBehaviourTreeTypeCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v9; // dx
  unsigned int v10; // edx
  bool v11; // zf

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[22].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIEntityComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIEntityComponent::_TypeUID);
  }
  else
  {
    v6 = v3->m_Components.p[22].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v7 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( !v7 )
    return MEMORY[0xC8] == v2->mAIBehaviourTreeID.mUID;
  v9 = v7->m_Flags;
  if ( (v9 >> 14) & 1 || (v9 & 0x8000u) != 0 )
    return LODWORD(v7->m_Components.p[19].m_pComponent[3].m_SafePointerList.mNode.mPrev) == v2->mAIBehaviourTreeID.mUID;
  if ( (v9 >> 13) & 1 )
  {
    v10 = UFG::AIActionTreeComponent::_TypeUID;
    return LODWORD(UFG::SimObjectGame::GetComponentOfTypeHK(v7, v10)[3].m_SafePointerList.mNode.mPrev) == v2->mAIBehaviourTreeID.mUID;
  }
  v11 = ((v9 >> 12) & 1) == 0;
  v10 = UFG::AIActionTreeComponent::_TypeUID;
  if ( !v11 )
    return LODWORD(UFG::SimObjectGame::GetComponentOfTypeHK(v7, v10)[3].m_SafePointerList.mNode.mPrev) == v2->mAIBehaviourTreeID.mUID;
  return LODWORD(UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AIActionTreeComponent::_TypeUID)[3].m_SafePointerList.mNode.mPrev) == v2->mAIBehaviourTreeID.mUID;
}

// File Line: 9010
// RVA: 0x1491BB0
__int64 dynamic_initializer_for__geAIEmotionEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&geAIEmotionEnum, UFG::AIEmotionNames, 13, 0i64);
  return atexit(dynamic_atexit_destructor_for__geAIEmotionEnum__);
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
  AiEmotionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AiEmotionCondition::`vftable;
  v1->mAIEmotion.mValue = 0;
}

// File Line: 9023
// RVA: 0x27E5B0
bool __fastcall AiEmotionCondition::Match(AiEmotionCondition *this, ActionContext *context)
{
  AiEmotionCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::ActiveAIEntityComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID)) : (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3)),
        v5) )
  {
    result = v5->m_CurrentEmotion == (unsigned __int8)v2->mAIEmotion.mValue;
  }
  else
  {
    result = 0;
  }
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
  FacialEmotionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FacialEmotionCondition::`vftable;
  v1->mFacialEmotion.mValue = 0;
}

// File Line: 9067
// RVA: 0x281950
bool __fastcall FacialEmotionCondition::Match(FacialEmotionCondition *this, ActionContext *context)
{
  FacialEmotionCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::ActiveAIEntityComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID)) : (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3)),
        v5) )
  {
    result = v5->m_FacialEmotion == (unsigned __int8)v2->mFacialEmotion.mValue;
  }
  else
  {
    result = 0;
  }
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
  ActionContext *rdi1; // rdi
  RelativeOrientationCondition *v3; // rsi
  __int64 v4; // rbx
  char v5; // al
  bool v6; // bl
  float v7; // xmm0_4
  float v8; // xmm0_4
  UFG::qVector3 v1; // [rsp+20h] [rbp-B8h]
  UFG::qVector3 v2; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 v12; // [rsp+40h] [rbp-98h]
  float v13; // [rsp+50h] [rbp-88h]
  float v14; // [rsp+54h] [rbp-84h]
  float v15; // [rsp+58h] [rbp-80h]
  float v16; // [rsp+80h] [rbp-58h]
  float v17; // [rsp+84h] [rbp-54h]
  float v18; // [rsp+88h] [rbp-50h]

  rdi1 = pContext;
  v3 = this;
  v4 = ((unsigned __int8 (__fastcall *)(RelativeOrientationCondition *, ActionContext *, UFG::qVector3 *))this->vfptr[1].GetResourceOwner)(
         this,
         pContext,
         &v12);
  v5 = ((__int64 (__fastcall *)(RelativeOrientationCondition *, ActionContext *, float *))v3->vfptr[2].FindWithOldPath)(
         v3,
         rdi1,
         &v16);
  if ( !(_BYTE)v4 || !v5 )
    return 0;
  v1 = v12;
  v2.y = v17;
  v2.x = v16;
  v2.z = v18;
  v6 = (float)((float)((float)(v17 * v14) + (float)(v16 * v13)) + (float)(v18 * v15)) > 0.0;
  v7 = UFG::qAngleBetween(&v1, &v2);
  if ( v6 )
    v7 = 6.2831855 - v7;
  v8 = v7 - v3->m_fOrientation;
  if ( v8 < 0.0 )
    v8 = v8 + 6.2831855;
  if ( v8 >= 3.1415927 )
    v8 = 6.2831855 - v8;
  return v8 <= v3->m_fAngleRange;
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
bool __fastcall TargetRelativeOrientationCondition::GetBaseMatrix(TargetRelativeOrientationCondition *this, ActionContext *pContext, UFG::qMatrix44 *outBaseMatrix)
{
  UFG::qMatrix44 *v3; // rsi
  TargetRelativeOrientationCondition *v4; // rdi
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // r8
  UFG::SimComponent *v8; // rax
  UFG::SimObjectCVBase *v9; // rbx
  unsigned __int16 v10; // cx
  UFG::CharacterAnimationComponent *v11; // rax
  Creature *v12; // rbx
  int v13; // eax
  bool result; // al
  UFG::TransformNodeComponent *v15; // rbx
  UFG::qVector4 v16; // xmm3
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm1

  v3 = outBaseMatrix;
  v4 = this;
  if ( this->m_bRelativeToTarget )
  {
    v5 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( !v5 )
      return 0;
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v7 = v8;
    }
    else
    {
      v7 = v5->m_Components.p[20].m_pComponent;
    }
    if ( !v7 )
      return 0;
    v9 = *(UFG::SimObjectCVBase **)(56i64
                                  * *(unsigned __int8 *)((unsigned int)v4->m_iTargetType
                                                       + *(_QWORD *)&v7[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v7[1].m_TypeUID
                                  + 40);
  }
  else
  {
    v9 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  }
  if ( v9 )
  {
    if ( v4->mBoneName.mUID == UFG::gNullQSymbolUC.mUID || !v4->m_bRelativeToTarget )
    {
      v15 = v9->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v15);
      result = 1;
      v16 = v15->mWorldTransform.v1;
      v17 = v15->mWorldTransform.v2;
      v18 = v15->mWorldTransform.v3;
      v3->v0 = v15->mWorldTransform.v0;
      v3->v1 = v16;
      v3->v2 = v17;
      v3->v3 = v18;
      return result;
    }
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v9->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v9->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    v12 = v11->mCreature;
    if ( v12 )
    {
      if ( v12->mPose.mRigHandle.mData )
      {
        v13 = Skeleton::GetBoneID(v12->mPose.mRigHandle.mUFGSkeleton, v4->mBoneName.mUID);
        if ( v13 >= 0 )
        {
          Creature::GetTransform(v12, v13, v3);
          return 1;
        }
      }
    }
  }
  return 0;
}

// File Line: 9229
// RVA: 0x27DAE0
char __fastcall TargetRelativeOrientationCondition::GetRelativeToMatrix(TargetRelativeOrientationCondition *this, ActionContext *pContext, UFG::qMatrix44 *outRelativeToMatrix)
{
  bool v3; // zf
  TargetRelativeOrientationCondition *v4; // rdi
  UFG::SimObjectCVBase *v5; // rcx
  UFG::qMatrix44 *v6; // rsi
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // r8
  UFG::SimComponent *v9; // rax
  unsigned __int16 v10; // dx
  UFG::CharacterAnimationComponent *v11; // rax
  Creature *v12; // rbx
  int v13; // eax
  UFG::TransformNodeComponent *v15; // rbx
  UFG::qVector4 v16; // xmm3
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm1

  v3 = this->m_bRelativeToTarget == 0;
  v4 = this;
  v5 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  v6 = outRelativeToMatrix;
  if ( v3 )
  {
    if ( !v5 )
      return 0;
    v7 = v5->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v5->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)&v5->vfptr,
                                UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                 (UFG::SimObject *)&v5->vfptr,
                                                                                 UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = v9;
    }
    else
    {
      v8 = v5->m_Components.p[20].m_pComponent;
    }
    if ( !v8 )
      return 0;
    v5 = *(UFG::SimObjectCVBase **)(56i64
                                  * *(unsigned __int8 *)((unsigned int)v4->m_iTargetType
                                                       + *(_QWORD *)&v8[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v8[1].m_TypeUID
                                  + 40);
  }
  if ( !v5 )
    return 0;
  if ( v4->mBoneName.mUID == UFG::gNullQSymbolUC.mUID || v4->m_bRelativeToTarget )
  {
    v15 = v5->m_pTransformNodeComponent;
    if ( !v15 )
      return 0;
    UFG::TransformNodeComponent::UpdateWorldTransform(v5->m_pTransformNodeComponent);
    v16 = v15->mWorldTransform.v1;
    v17 = v15->mWorldTransform.v2;
    v18 = v15->mWorldTransform.v3;
    v6->v0 = v15->mWorldTransform.v0;
    v6->v1 = v16;
    v6->v2 = v17;
    v6->v3 = v18;
    return 1;
  }
  v10 = v5->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
    {
      v11 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
    }
    else if ( (v10 >> 12) & 1 )
    {
      v11 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v5->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      v11 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v5->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
  }
  v12 = v11->mCreature;
  if ( !v12 )
    return 1;
  if ( v12->mPose.mRigHandle.mData )
  {
    v13 = Skeleton::GetBoneID(v12->mPose.mRigHandle.mUFGSkeleton, v4->mBoneName.mUID);
    Creature::GetTransform(v12, v13, v6);
  }
  else
  {
    Creature::GetTransform(v12, -1, v6);
  }
  return 1;
}eature::GetTransform(v12, v13, v6);
  }
  else
  {
    Creature::GetTransform(v12, -1, v6);
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
  ActionContext *rdi1; // rdi
  RelativePositionCondition *v3; // rsi
  __int64 v4; // rbx
  char v5; // al
  bool v6; // bl
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v10; // [rsp+20h] [rbp-88h]
  float v11; // [rsp+24h] [rbp-84h]
  float v12; // [rsp+28h] [rbp-80h]
  UFG::qVector3 v2; // [rsp+30h] [rbp-78h]
  UFG::qVector3 v1; // [rsp+40h] [rbp-68h]
  UFG::qVector3 v15; // [rsp+50h] [rbp-58h]
  float v16; // [rsp+60h] [rbp-48h]
  float v17; // [rsp+64h] [rbp-44h]
  float v18; // [rsp+68h] [rbp-40h]
  float v19; // [rsp+80h] [rbp-28h]
  float v20; // [rsp+84h] [rbp-24h]
  float v21; // [rsp+88h] [rbp-20h]

  rdi1 = pContext;
  v3 = this;
  v4 = ((unsigned __int8 (__fastcall *)(RelativePositionCondition *, ActionContext *, float *))this->vfptr[1].GetResourceOwner)(
         this,
         pContext,
         &v10);
  v5 = ((__int64 (__fastcall *)(RelativePositionCondition *, ActionContext *, UFG::qVector3 *))v3->vfptr[2].FindWithOldPath)(
         v3,
         rdi1,
         &v15);
  if ( !(_BYTE)v4 || !v5 )
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
  v8 = v7 - v3->m_fDirection;
  if ( v8 < 0.0 )
    v8 = v8 + 6.2831855;
  if ( v8 >= 3.1415927 )
    v8 = 6.2831855 - v8;
  return v8 <= v3->m_fAngleRange;
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
char __fastcall HitLocation::GetPosition(HitLocation *this, ActionContext *pContext, UFG::qVector3 *outPosition)
{
  UFG::SimObjectGame *v3; // rcx
  UFG::qVector3 *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4
  char result; // al

  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = outPosition;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[15].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    v6 = v3->m_Components.p[15].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v7 = *((float *)&v6[6].vfptr + 1);
  v8 = *(float *)&v6[6].m_SafePointerList.mNode.mPrev;
  v4->x = *(float *)&v6[6].vfptr;
  result = 1;
  v4->y = v7;
  v4->z = v8;
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
char __fastcall HitImpulse::GetPosition(HitImpulse *this, ActionContext *pContext, UFG::qVector3 *outPosition)
{
  UFG::SimObjectGame *v3; // rcx
  UFG::qVector3 *v4; // rdi
  ActionContext *v5; // rbx
  unsigned __int16 v6; // r9
  UFG::SimComponent *v7; // rax
  UFG::TransformNodeComponent *v8; // rbx
  int v9; // xmm6_4
  int v10; // xmm7_4
  int v11; // xmm8_4
  char result; // al
  float v13; // xmm7_4
  float v14; // xmm8_4

  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = outPosition;
  v5 = pContext;
  if ( !v3 )
    return 0;
  v6 = v3->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = v3->m_Components.p[15].m_pComponent;
  }
  else if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
    else
      v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    v7 = v3->m_Components.p[15].m_pComponent;
  }
  if ( !v7 )
    return 0;
  v8 = (UFG::TransformNodeComponent *)v5->mSimObject.m_pPointer;
  v9 = HIDWORD(v7[6].m_SafePointerList.mNode.mPrev) ^ _xmm[0];
  v10 = LODWORD(v7[6].m_SafePointerList.mNode.mNext) ^ _xmm[0];
  v11 = HIDWORD(v7[6].m_SafePointerList.mNode.mNext) ^ _xmm[0];
  if ( v8 )
    v8 = (UFG::TransformNodeComponent *)v8->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  result = 1;
  v13 = *(float *)&v10 + v8->mWorldTransform.v3.y;
  v14 = *(float *)&v11 + v8->mWorldTransform.v3.z;
  v4->x = *(float *)&v9 + v8->mWorldTransform.v3.x;
  v4->y = v13;
  v4->z = v14;
  return result;
}

// File Line: 9428
// RVA: 0x27DA80
char __fastcall HitLocation::GetRelativeToMatrix(HitLocation *this, ActionContext *pContext, UFG::qMatrix44 *outRelativeToMatrix)
{
  UFG::SimObject *v3; // rbx
  UFG::qMatrix44 *v4; // rdi
  char result; // al
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1

  v3 = pContext->mSimObject.m_pPointer;
  v4 = outRelativeToMatrix;
  if ( v3 )
    v3 = (UFG::SimObject *)v3->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
  result = 1;
  v6 = *(UFG::qVector4 *)&v3[1].m_SafePointerList.mNode.mNext;
  v7 = *(UFG::qVector4 *)&v3[1].m_SafePointerWithCallbackList.mNode.mNext;
  v8 = *(UFG::qVector4 *)v3[1].mNode.mChild;
  v4->v0 = *(UFG::qVector4 *)&v3[1].vfptr;
  v4->v1 = v6;
  v4->v2 = v7;
  v4->v3 = v8;
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
void __fastcall TargetPropInteractAvailableCondition::TargetPropInteractAvailableCondition(TargetPropInteractAvailableCondition *this)
{
  TargetPropInteractAvailableCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPropInteractAvailableCondition::`vftable;
}

// File Line: 9460
// RVA: 0x28E4C0
bool __fastcall TargetPropInteractAvailableCondition::Match(TargetPropInteractAvailableCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // rbx
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::PropInteractComponent *v9; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = pContext;
  if ( v2
    && ((v4 = v2->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v2->m_Components.p[20].m_pComponent)) : (v5 = v2->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 48i64)
                                     + *(_QWORD *)&v5[1].m_TypeUID
                                     + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::PropInteractComponent::_TypeUID)) : (v9 = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::PropInteractComponent::_TypeUID))) : (v9 = (UFG::PropInteractComponent *)v7->m_Components.p[13].m_pComponent)) : (v9 = (UFG::PropInteractComponent *)v7->m_Components.p[33].m_pComponent)) : (v9 = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::PropInteractComponent::_TypeUID)),
         v9)) )
  {
    result = UFG::PropInteractComponent::IsInteractionAvailable(v9, v3);
  }
  else
  {
    result = 0;
  }
  return result;
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
void __fastcall TargetPropInteractOrientationCondition::TargetPropInteractOrientationCondition(TargetPropInteractOrientationCondition *this)
{
  TargetPropInteractOrientationCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPropInteractOrientationCondition::`vftable;
  v1->m_SyncName.mUID = -1;
  *(_QWORD *)&v1->m_fMaxDistance = 0i64;
}

// File Line: 9508
// RVA: 0x28E5F0
bool __fastcall TargetPropInteractOrientationCondition::Match(TargetPropInteractOrientationCondition *this, ActionContext *pContext)
{
  UFG::qSymbolUC *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rdx
  UFG::TransformNodeComponent *v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::PropInteractComponent *v11; // rbx
  float fMaxAngleBetween; // xmm6_4
  float v13; // xmm7_4

  v2 = (UFG::qSymbolUC *)this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = 0i64;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    v5 = v3->m_pTransformNodeComponent;
    if ( (v6 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v4 = v7;
    }
    else
    {
      v4 = v3->m_Components.p[20].m_pComponent;
    }
  }
  if ( !v5 )
    return 0;
  if ( !v4 )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 48i64)
                              + *(_QWORD *)&v4[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::PropInteractComponent::_TypeUID);
  }
  else
  {
    if ( (v9 & 0x8000u) != 0 )
    {
      v11 = (UFG::PropInteractComponent *)v8->m_Components.p[33].m_pComponent;
      goto LABEL_25;
    }
    if ( (v9 >> 13) & 1 )
    {
      v11 = (UFG::PropInteractComponent *)v8->m_Components.p[13].m_pComponent;
      goto LABEL_25;
    }
    if ( (v9 >> 12) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::PropInteractComponent::_TypeUID);
    else
      v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::PropInteractComponent::_TypeUID);
  }
  v11 = (UFG::PropInteractComponent *)v10;
LABEL_25:
  if ( v11 )
  {
    fMaxAngleBetween = *(float *)&v2[8].mUID;
    v13 = *(float *)&v2[7].mUID;
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    return UFG::PropInteractComponent::IsOrientedToInteract(v11, &v5->mWorldTransform, v2 + 6, v13, fMaxAngleBetween);
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
  TargetIsLockedCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  signed __int64 v7; // r8
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(_QWORD *)&v5[1].m_TypeUID
         + 56i64 * *(unsigned __int8 *)((unsigned __int8)v2->m_eTargetType.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64);
      if ( *(_QWORD *)(v7 + 40) )
      {
        if ( *(_BYTE *)(v7 + 49) )
          result = 1;
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
char __fastcall TargetVelocityRelativeToCollisionCondition::GetBaseMatrix(TargetVelocityRelativeToCollisionCondition *this, ActionContext *pContext, UFG::qMatrix44 *outBaseMatrix)
{
  TargetVelocityRelativeToCollisionCondition *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  UFG::qMatrix44 *v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // r8
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // rdx
  UFG::qVector3 result; // [rsp+30h] [rbp-18h]

  v3 = this;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v5 = outBaseMatrix;
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
  v9 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)((unsigned __int8)v3->m_eTargetType.mValue
                                               + *(_QWORD *)&v7[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&v7[1].m_TypeUID
                          + 40);
  if ( !v9 )
    return 0;
  UFG::GetVelocity(&result, v9);
  result.z = 0.0;
  return UFG::qMakeMatrix(v5, &result, &UFG::qVector3::msAxisZ, &UFG::qVector3::msZero, 0.001);
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
char __fastcall HitCollisionVelocityRelativeToNormal::GetBaseMatrix(HitCollisionVelocityRelativeToNormal *this, ActionContext *pContext, UFG::qMatrix44 *outBaseMatrix)
{
  UFG::SimObjectGame *v3; // rcx
  UFG::qMatrix44 *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  float v7; // xmm1_4
  UFG::qVector3 forward; // [rsp+30h] [rbp-18h]

  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = outBaseMatrix;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[15].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    v6 = v3->m_Components.p[15].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v7 = *(float *)&v6[6].m_NameUID;
  LODWORD(forward.x) = v6[6].m_TypeUID;
  forward.y = v7;
  forward.z = 0.0;
  return UFG::qMakeMatrix(v4, &forward, &UFG::qVector3::msAxisZ, &UFG::qVector3::msZero, 0.001);
}

// File Line: 9700
// RVA: 0x27D950
char __fastcall TargetVelocityRelativeToCollisionCondition::GetRelativeToMatrix(TargetVelocityRelativeToCollisionCondition *this, ActionContext *pContext, UFG::qMatrix44 *outRelativeToMatrix)
{
  UFG::SimObjectGame *v3; // rcx
  UFG::qMatrix44 *v4; // rsi
  UFG::TransformNodeComponent *v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rbx
  UFG::SimComponent *v8; // rax
  float v9; // xmm1_4
  UFG::qVector3 forward; // [rsp+30h] [rbp-18h]

  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = outRelativeToMatrix;
  if ( !v3 )
    return 0;
  v5 = v3->m_pTransformNodeComponent;
  if ( !v5 || !v3 )
    return 0;
  v6 = v3->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = v3->m_Components.p[15].m_pComponent;
  }
  else if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
    else
      v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
    v7 = v8;
  }
  else
  {
    v7 = v3->m_Components.p[15].m_pComponent;
  }
  if ( !v7 )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v9 = v5->mWorldTransform.v3.y - *((float *)&v7[6].vfptr + 1);
  forward.x = v5->mWorldTransform.v3.x - *(float *)&v7[6].vfptr;
  forward.y = v9;
  forward.z = 0.0;
  return UFG::qMakeMatrix(v4, &forward, &UFG::qVector3::msAxisZ, &UFG::qVector3::msZero, 0.001);
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
  HitLocationTargettedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HitLocationTargettedCondition::`vftable;
}

// File Line: 9752
// RVA: 0x282320
bool __fastcall HitLocationTargettedCondition::Match(HitLocationTargettedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = v2->m_Components.p[15].m_pComponent)) : (v4 = v2->m_Components.p[15].m_pComponent),
        v4) )
  {
    result = v4[5].m_SafePointerList.mNode.mNext != 0i64;
  }
  else
  {
    result = 0;
  }
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
  HitProjectileReactionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HitProjectileReactionCondition::`vftable;
  v1->m_eProjectileReaction.mValue = 0;
}

// File Line: 9790
// RVA: 0x282460
bool __fastcall HitProjectileReactionCondition::Match(HitProjectileReactionCondition *this, ActionContext *pContext)
{
  HitProjectileReactionCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5 && (v6 = v5[5].m_SafePointerList.mNode.mPrev) != 0i64) )
  {
    result = (unsigned __int8)v2->m_eProjectileReaction.mValue == *(_DWORD *)(*((_QWORD *)&v6[11].mPrev->mNext
                                                                              + HIDWORD(v6[10].mNext))
                                                                            + 152i64);
  }
  else
  {
    result = 0;
  }
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
void __fastcall HitProjectileIsExplosiveCondition::HitProjectileIsExplosiveCondition(HitProjectileIsExplosiveCondition *this)
{
  HitProjectileIsExplosiveCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HitProjectileIsExplosiveCondition::`vftable;
}

// File Line: 9830
// RVA: 0x2823B0
bool __fastcall HitProjectileIsExplosiveCondition::Match(HitProjectileIsExplosiveCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = v2->m_Components.p[15].m_pComponent)) : (v4 = v2->m_Components.p[15].m_pComponent),
        v4 && (v5 = v4[5].m_SafePointerList.mNode.mPrev) != 0i64) )
  {
    result = *(_DWORD *)(*((_QWORD *)&v5[11].mPrev->mNext + HIDWORD(v5[10].mNext)) + 108i64) != -1;
  }
  else
  {
    result = 0;
  }
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
void __fastcall HitProjectileWeaponTypeCondition::HitProjectileWeaponTypeCondition(HitProjectileWeaponTypeCondition *this)
{
  HitProjectileWeaponTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HitProjectileWeaponTypeCondition::`vftable;
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 9871
// RVA: 0x282640
bool __fastcall HitProjectileWeaponTypeCondition::Match(HitProjectileWeaponTypeCondition *this, ActionContext *pContext)
{
  HitProjectileWeaponTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    v6 = v5[5].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
    LOBYTE(v6) = **((_DWORD **)&v6[11].mPrev->mNext + HIDWORD(v6[10].mNext)) == v2->m_eSimObjectWeaponType;
  return (char)v6;
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
void __fastcall HitProjectileWeaponInventoryTypeCondition::HitProjectileWeaponInventoryTypeCondition(HitProjectileWeaponInventoryTypeCondition *this)
{
  HitProjectileWeaponInventoryTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HitProjectileWeaponInventoryTypeCondition::`vftable;
  v1->m_eInventoryItemType.mValue = 0;
}

// File Line: 9911
// RVA: 0x282520
bool __fastcall HitProjectileWeaponInventoryTypeCondition::Match(HitProjectileWeaponInventoryTypeCondition *this, ActionContext *pContext)
{
  HitProjectileWeaponInventoryTypeCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // r8
  UFG::SimObjectGame *v8; // r8
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( v3
    && ((v5 = v3->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = v3->m_Components.p[15].m_pComponent)) : (v6 = v3->m_Components.p[15].m_pComponent),
        v6) )
  {
    v7 = v6[5].m_SafePointerList.mNode.mPrev;
  }
  else
  {
    v7 = 0i64;
  }
  if ( v7 )
  {
    v8 = (UFG::SimObjectGame *)v7[2].mNext;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( !((v9 >> 14) & 1) && (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
        {
          v4 = v8->m_Components.p[11].m_pComponent;
        }
        else
        {
          if ( (v9 >> 12) & 1 )
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::InventoryItemComponent::_TypeUID);
          else
            v10 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v8->vfptr,
                    UFG::InventoryItemComponent::_TypeUID);
          v4 = v10;
        }
      }
    }
  }
  if ( v4 )
    result = LODWORD(v4[1].m_pSimObject) == v2->m_eInventoryItemType.mValue;
  else
    result = 0;
  return result;
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
void __fastcall HitExplosionCanTriggerVehicleExplosion::HitExplosionCanTriggerVehicleExplosion(HitExplosionCanTriggerVehicleExplosion *this)
{
  HitExplosionCanTriggerVehicleExplosion *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HitExplosionCanTriggerVehicleExplosion::`vftable;
}

// File Line: 9949
// RVA: 0x282280
bool __fastcall HitExplosionCanTriggerVehicleExplosion::Match(HitExplosionCanTriggerVehicleExplosion *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = v2->m_Components.p[15].m_pComponent)) : (v4 = v2->m_Components.p[15].m_pComponent),
        v4 && (v5 = v4[7].m_SafePointerList.mNode.mPrev) != 0i64) )
  {
    result = (BYTE4(v5[11].mNext) >> 1) & 1;
  }
  else
  {
    result = 0;
  }
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
void __fastcall HitDistanceFromExplosionCondition::HitDistanceFromExplosionCondition(HitDistanceFromExplosionCondition *this)
{
  HitDistanceFromExplosionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HitDistanceFromExplosionCondition::`vftable;
  v1->m_fDistance = 0.0;
  v1->m_InEqualityOperator.mValue = 3;
}

// File Line: 9985
// RVA: 0x2821D0
char __fastcall HitDistanceFromExplosionCondition::Match(HitDistanceFromExplosionCondition *this, ActionContext *pContext)
{
  HitDistanceFromExplosionCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  float v6; // xmm2_4
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5 && (v6 = *(float *)&v5[7].vfptr, v6 >= 0.0)) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)v2->m_InEqualityOperator.mValue,
               v2->m_fDistance * v2->m_fDistance,
               v6);
  }
  else
  {
    result = 0;
  }
  return result;
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
  CharacterTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectPropertiesComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectPropertiesComponent::_TypeUID)),
                                                                                             v5 = v6) : (v5 = v3->m_Components.p[4].m_pComponent)) : (v5 = v3->m_Components.p[3].m_pComponent)) : (v5 = v3->m_Components.p[3].m_pComponent),
        v5 && LODWORD(v5[1].m_SafePointerList.mNode.mNext) == 1) )
  {
    result = LODWORD(v5[3].vfptr) == (unsigned __int8)v2->m_eCharacterType.mValue;
  }
  else
  {
    result = 0;
  }
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[17].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CopUnitComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CopUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CopUnitComponent::_TypeUID);
    }
    else
    {
      v4 = v2->m_Components.p[17].m_pComponent;
    }
    if ( v4 )
      result = 1;
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
  UFG::GameCameraComponent *v2; // rax

  v2 = UFG::GetCurrentGameCamera();
  if ( v2 )
    LOBYTE(v2) = v2->mInCollision != 0;
  return (char)v2;
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
  IsCameraTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsCameraTypeCondition::`vftable;
  v1->mCameraType.mValue = 0;
}

// File Line: 10101
// RVA: 0x283A30
char __fastcall IsCameraTypeCondition::Match(IsCameraTypeCondition *this, ActionContext *context)
{
  IsCameraTypeCondition *v2; // rbx
  UFG::GameCameraComponent *v3; // r8
  unsigned int v4; // edx
  char result; // al

  v2 = this;
  v3 = UFG::GetCurrentGameCamera();
  if ( !v3 )
    goto LABEL_11;
  switch ( v2->mCameraType.mValue )
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
      goto LABEL_11;
  }
  if ( UFG::SimComponent::IsType((UFG::SimComponent *)&v3->vfptr, v4) )
    result = 1;
  else
LABEL_11:
    result = 0;
  return result;
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
  IsClassTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsClassTypeCondition::`vftable;
  v1->mClassType.mUID = -1;
  v1->mClassType = UFG::gNullQSymbol;
}

// File Line: 10167
// RVA: 0x283AD0
char __fastcall IsClassTypeCondition::Match(IsClassTypeCondition *this, ActionContext *context)
{
  UFG::qSymbol *v2; // r8
  UFG::SceneObjectProperties *v3; // rdx
  UFG::qPropertySet *v4; // rcx

  v2 = &this->mClassType;
  if ( this->mClassType.mUID == UFG::gNullQSymbol.mUID )
    return 0;
  v3 = context->mSimObject.m_pPointer->m_pSceneObj;
  v4 = v3->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  return UFG::SimObjectUtility::IsClassType(v4, v2);
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
  FightingClassCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectPropertiesComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectPropertiesComponent::_TypeUID)),
                                                                                             v5 = v6) : (v5 = v3->m_Components.p[4].m_pComponent)) : (v5 = v3->m_Components.p[3].m_pComponent)) : (v5 = v3->m_Components.p[3].m_pComponent),
        v5 && LODWORD(v5[1].m_SafePointerList.mNode.mNext) == 1) )
  {
    result = HIDWORD(v5[3].vfptr) == (unsigned __int8)v2->m_eFightingClass.mValue;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 10225
// RVA: 0x278290
void __fastcall PropertyConditionBase::PropertyConditionBase(PropertyConditionBase *this)
{
  PropertyConditionBase *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PropertyConditionBase::`vftable;
  v1->m_PropertySymbol.mUID = -1;
  *(_WORD *)&v1->m_PeriodicallyRecachePropertyValue = 0;
  *(_QWORD *)&v1->m_PropertyValueUID = 0i64;
  v1->m_NextTimeToCachePropertyValueUID = 0;
  v1->m_CachePropertyValue = 1;
  v1->m_MinTimeBeforeRecachePropertyValue = 1.0;
  v1->m_MaxTimeBeforeRecachePropertyValue = 2.0;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 10242
// RVA: 0x294070
void __fastcall PropertyConditionBase::ResolveReferences(PropertyConditionBase *this, ActionNode *action_node)
{
  PropertyConditionBase *v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rax
  signed __int64 v5; // rcx
  UFG::eActionTreeMemoryElementType v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  bool v10; // zf

  v2 = this;
  if ( !this->m_InitState.mValue )
  {
    v3 = ((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
    v4 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 152i64))(v3);
    v5 = (signed __int64)&v2->m_MyRoot;
    if ( v4 )
      v4 -= v5;
    *(_QWORD *)v5 = v4;
    if ( v2->m_CachePropertyValue )
    {
      v6 = (unsigned int)v2->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v2->vfptr);
      v7 = UFG::ActionTreeComponentBase::MakeValueUID(v2->m_PropertyValueUID, v6);
      v8 = v2->m_PropertyValueHasBeenReadUID;
      v2->m_PropertyValueUID = v7;
      v9 = UFG::ActionTreeComponentBase::MakeValueUID(v8, eACTION_TREE_MEMORY_ELEMENT_BOOL);
      v10 = v2->m_PeriodicallyRecachePropertyValue == 0;
      v2->m_PropertyValueHasBeenReadUID = v9;
      if ( !v10 )
        v2->m_NextTimeToCachePropertyValueUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                                  v2->m_NextTimeToCachePropertyValueUID,
                                                  0);
    }
    v2->m_InitState.mValue = 1;
  }
}

// File Line: 10322
// RVA: 0x294390
void __fastcall PropertyConditionBase::ValueHasBeenReadFromPropertySet(PropertyConditionBase *this, ActionContext *action_context)
{
  ActionContext *v2; // rsi
  PropertyConditionBase *v3; // rbx
  __int64 v4; // rax
  signed __int64 v5; // rdi
  UFG::ActionTreeComponentBase *v6; // rdx
  char *v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rcx
  unsigned int v9; // er9
  __int64 v10; // rax
  UFG::ActionTreeComponentBase *v11; // rdx
  UFG::ActionTreeComponentBase *v12; // rcx
  bool value; // [rsp+20h] [rbp-18h]
  float valuea; // [rsp+20h] [rbp-18h]

  v2 = action_context;
  v3 = this;
  if ( this->m_CachePropertyValue )
  {
    v4 = this->m_MyRoot.mOffset;
    v5 = 0i64;
    if ( v4 )
      v6 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v4);
    else
      v6 = 0i64;
    if ( v4 )
      v7 = (char *)&this->m_MyRoot + v4;
    else
      v7 = 0i64;
    v8 = v2->mActionTreeComponentBase[v7[236]];
    if ( !v8 )
      v8 = v2->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
      v8,
      v6,
      (ActionNodeRoot *)v3->m_PropertyValueHasBeenReadUID,
      1u,
      value);
    if ( v3->m_PeriodicallyRecachePropertyValue )
    {
      UFG::GetRandomNumberInRange(v3->m_MinTimeBeforeRecachePropertyValue, v3->m_MaxTimeBeforeRecachePropertyValue);
      v10 = v3->m_MyRoot.mOffset;
      if ( v10 )
        v11 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v10);
      else
        v11 = 0i64;
      if ( v10 )
        v5 = (signed __int64)&v3->m_MyRoot + v10;
      v12 = v2->mActionTreeComponentBase[*(char *)(v5 + 236)];
      if ( !v12 )
        v12 = v2->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
        v12,
        v11,
        (ActionNodeRoot *)v3->m_NextTimeToCachePropertyValueUID,
        v9,
        valuea);
    }
  }
}

// File Line: 10344
// RVA: 0x27B0C0
bool __usercall PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet@<al>(PropertyConditionBase *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  ActionContext *v3; // rsi
  PropertyConditionBase *v4; // rbx
  __int64 v5; // rax
  signed __int64 v6; // rdi
  UFG::ActionTreeComponentBase *v7; // rdx
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  bool v10; // bp
  __int64 v11; // rax
  float v12; // xmm6_4
  UFG::ActionTreeComponentBase *v13; // rdx
  UFG::ActionTreeComponentBase *v14; // rcx
  bool result; // al
  bool *value; // [rsp+20h] [rbp-28h]
  float *valuea; // [rsp+20h] [rbp-28h]
  unsigned int value_uid; // [rsp+50h] [rbp+8h]
  unsigned int v19; // [rsp+60h] [rbp+18h]

  v3 = action_context;
  v4 = this;
  if ( !this->m_CachePropertyValue )
    return 1;
  v5 = this->m_MyRoot.mOffset;
  v6 = 0i64;
  LOBYTE(value_uid) = 0;
  if ( v5 )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v5);
  else
    v7 = 0i64;
  if ( v5 )
    v8 = (char *)&this->m_MyRoot + v5;
  else
    v8 = 0i64;
  v9 = v3->mActionTreeComponentBase[v8[236]];
  if ( !v9 )
    v9 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v9,
    v7,
    (ActionNodeRoot *)v4->m_PropertyValueHasBeenReadUID,
    (unsigned __int64)&value_uid,
    value);
  v10 = (_BYTE)value_uid == 0;
  if ( !v4->m_PeriodicallyRecachePropertyValue )
    return (_BYTE)value_uid == 0;
  v11 = v4->m_MyRoot.mOffset;
  valuea = a3;
  v12 = UFG::Metrics::msInstance.mSimTime_Temp;
  *(float *)&v19 = FLOAT_N99999_0;
  if ( v11 )
    v13 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v11);
  else
    v13 = 0i64;
  if ( v11 )
    v6 = (signed __int64)&v4->m_MyRoot + v11;
  v14 = v3->mActionTreeComponentBase[*(char *)(v6 + 236)];
  if ( !v14 )
    v14 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
    v14,
    v13,
    (ActionNodeRoot *)v4->m_NextTimeToCachePropertyValueUID,
    (unsigned __int64)&v19,
    valuea);
  result = v10;
  if ( v12 > *(float *)&v19 )
    result = 1;
  return result;
}

// File Line: 10378
// RVA: 0x1491AF0
__int64 dynamic_initializer_for__gMemImageWarnings__()
{
  return atexit(dynamic_atexit_destructor_for__gMemImageWarnings__);
}

// File Line: 10423
// RVA: 0x278F00
void __fastcall TargetPropertyConditionBase::TargetPropertyConditionBase(TargetPropertyConditionBase *this)
{
  TargetPropertyConditionBase *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PropertyConditionBase::`vftable;
  v1->m_PropertySymbol.mUID = -1;
  *(_WORD *)&v1->m_PeriodicallyRecachePropertyValue = 0;
  *(_QWORD *)&v1->m_PropertyValueUID = 0i64;
  v1->m_NextTimeToCachePropertyValueUID = 0;
  v1->m_CachePropertyValue = 1;
  v1->m_MinTimeBeforeRecachePropertyValue = 1.0;
  v1->m_MaxTimeBeforeRecachePropertyValue = 2.0;
  v1->m_MyRoot.mOffset = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPropertyConditionBase::`vftable;
  v1->m_NestedPropertySet.mUID = -1;
  v1->m_TargetType.mValue = 0;
  v1->m_PreviousTargetUID = 0;
  v1->m_MyRoot.mOffset = 0i64;
}

// File Line: 10434
// RVA: 0x2941C0
void __fastcall TargetPropertyConditionBase::ResolveReferences(TargetPropertyConditionBase *this, ActionNode *action_node)
{
  TargetPropertyConditionBase *v2; // rbx
  ActionNode *v3; // rdi
  Expression::IMemberMap *v4; // rax
  signed __int64 v5; // rcx

  v2 = this;
  v3 = action_node;
  v4 = action_node->vfptr[1].GetResourceOwner((Expression::IMemberMap *)action_node);
  v5 = (signed __int64)&v2->m_MyRoot;
  if ( v4 )
    v4 = (Expression::IMemberMap *)((char *)v4 - v5);
  *(_QWORD *)v5 = v4;
  if ( v2->m_CachePropertyValue )
    v2->m_PreviousTargetUID = UFG::ActionTreeComponentBase::MakeValueUID(
                                v2->m_PreviousTargetUID,
                                eACTION_TREE_MEMORY_ELEMENT_SIM_OBJECT_POINTER);
  PropertyConditionBase::ResolveReferences((PropertyConditionBase *)&v2->vfptr, v3);
}

// File Line: 10455
// RVA: 0x27B1F0
char __usercall TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet@<al>(TargetPropertyConditionBase *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  ActionContext *v3; // rdi
  TargetPropertyConditionBase *v4; // rsi
  __int64 v5; // rax
  signed __int64 v6; // rbx
  UFG::ActionTreeComponentBase *v7; // rdx
  char *v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  UFG::SimObject *v10; // r8
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // r8
  UFG::SimComponent *v13; // rax
  bool v14; // zf
  UFG::SimObjectGame *v15; // rcx
  __int64 v16; // r9
  __int64 v17; // rax
  UFG::ActionTreeComponentBase *v18; // rdx
  UFG::ActionTreeComponentBase *v19; // rcx
  UFG::SimObject **v21; // [rsp+20h] [rbp-8h]
  UFG::SimObject *v22; // [rsp+20h] [rbp-8h]
  __int64 value_uid; // [rsp+30h] [rbp+8h]

  v3 = action_context;
  v4 = this;
  if ( !this->m_CachePropertyValue )
    return PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
             (PropertyConditionBase *)&v4->vfptr,
             v3,
             a3);
  v5 = this->m_MyRoot.mOffset;
  v6 = 0i64;
  value_uid = 0i64;
  if ( v5 )
    v7 = (UFG::ActionTreeComponentBase *)((char *)&this->m_MyRoot + v5);
  else
    v7 = 0i64;
  if ( v5 )
    v8 = (char *)&this->m_MyRoot + v5;
  else
    v8 = 0i64;
  v9 = v3->mActionTreeComponentBase[v8[236]];
  if ( !v9 )
    v9 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::SimObject *>(
    v9,
    v7,
    (ActionNodeRoot *)v4->m_PreviousTargetUID,
    (unsigned __int64)&value_uid,
    v21);
  v10 = v3->mSimObject.m_pPointer;
  if ( !v10 )
    return PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
             (PropertyConditionBase *)&v4->vfptr,
             v3,
             a3);
  v11 = v10->m_Flags;
  if ( (v11 >> 14) & 1 )
  {
    v12 = v10->m_Components.p[20].m_pComponent;
  }
  else if ( (v11 & 0x8000u) == 0 )
  {
    if ( (v11 >> 13) & 1 )
    {
      v13 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)v3->mSimObject.m_pPointer,
              UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v14 = ((v11 >> 12) & 1) == 0;
      v15 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
      v13 = v14 ? UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v15->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v15,
                                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    v12 = v13;
  }
  else
  {
    v12 = v10->m_Components.p[20].m_pComponent;
  }
  if ( !v12 )
    return PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
             (PropertyConditionBase *)&v4->vfptr,
             v3,
             a3);
  v16 = *(_QWORD *)(56i64
                  * *(unsigned __int8 *)((unsigned __int8)v4->m_TargetType.mValue + *(_QWORD *)&v12[1].m_Flags + 8i64)
                  + *(_QWORD *)&v12[1].m_TypeUID
                  + 40);
  if ( value_uid == v16 )
    return PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
             (PropertyConditionBase *)&v4->vfptr,
             v3,
             a3);
  v17 = v4->m_MyRoot.mOffset;
  if ( v17 )
    v18 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v17);
  else
    v18 = 0i64;
  if ( v17 )
    v6 = (signed __int64)&v4->m_MyRoot + v17;
  v19 = v3->mActionTreeComponentBase[*(char *)(v6 + 236)];
  if ( !v19 )
    v19 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::SimObject *>(
    v19,
    v18,
    (ActionNodeRoot *)v4->m_PreviousTargetUID,
    v16,
    v22);
  return 1;
}

// File Line: 10488
// RVA: 0x27D860
UFG::qPropertySet *__fastcall TargetPropertyConditionBase::GetPropertySet(TargetPropertyConditionBase *this, ActionContext *action_context)
{
  TargetPropertyConditionBase *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rcx
  __int64 v8; // rcx
  UFG::qPropertySet *result; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0i64;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0i64;
  v7 = *(_QWORD *)(56i64
                 * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64)
                 + *(_QWORD *)&v5[1].m_TypeUID
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
  if ( v2->m_NestedPropertySet.mUID != -1 )
  {
    if ( result )
      return PropertyUtils::Get<UFG::qPropertySet>(result, &v2->m_NestedPropertySet, DEPTH_RECURSE);
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
bool __fastcall PropertyBooleanCondition::ReadValueFromPropertySet(PropertyBooleanCondition *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // rax
  ActionContext *v3; // rdi
  PropertyBooleanCondition *v4; // rbx
  UFG::SceneObjectProperties *v5; // rax
  UFG::qPropertySet *v6; // rcx
  bool *v7; // rsi
  __int64 v8; // rcx
  signed __int64 v9; // rdx
  UFG::ActionTreeComponentBase *v10; // r10
  UFG::ActionTreeComponentBase *v11; // rcx
  bool v13; // [rsp+20h] [rbp-8h]

  v2 = action_context->mSimObject.m_pPointer;
  v3 = action_context;
  v4 = this;
  if ( !v2 )
    return 0;
  v5 = v2->m_pSceneObj;
  if ( !v5 )
    return 0;
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v6 = v5->mpConstProperties;
    if ( !v6 )
      return 0;
  }
  v7 = PropertyUtils::Get<bool>(v6, &v4->m_PropertySymbol, DEPTH_RECURSE);
  if ( !v7 )
    return 0;
  if ( v4->m_CachePropertyValue )
  {
    v8 = v4->m_MyRoot.mOffset;
    v9 = 0i64;
    if ( v8 )
      v10 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v8);
    else
      v10 = 0i64;
    if ( v8 )
      v9 = (signed __int64)&v4->m_MyRoot + v8;
    v11 = v3->mActionTreeComponentBase[*(char *)(v9 + 236)];
    if ( !v11 )
      v11 = v3->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v11, v10, (ActionNodeRoot *)v4->m_PropertyValueUID, *v7, v13);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet((PropertyConditionBase *)&v4->vfptr, v3);
  return *v7;
}

// File Line: 10580
// RVA: 0x288FC0
bool __usercall PropertyBooleanCondition::Match@<al>(PropertyBooleanCondition *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  ActionContext *v3; // rbx
  PropertyBooleanCondition *v4; // rdi
  __int64 v6; // rax
  signed __int64 v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rdx
  UFG::ActionTreeComponentBase *v9; // rcx
  bool *v10; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+38h] [rbp+10h]

  v3 = action_context;
  v4 = this;
  LOBYTE(value_uid) = 0;
  if ( !action_context )
    return 0;
  if ( PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
         (PropertyConditionBase *)&this->vfptr,
         action_context,
         a3) )
  {
    return PropertyBooleanCondition::ReadValueFromPropertySet(v4, v3);
  }
  v6 = v4->m_MyRoot.mOffset;
  v7 = 0i64;
  if ( v6 )
    v8 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v6);
  else
    v8 = 0i64;
  if ( v6 )
    v7 = (signed __int64)&v4->m_MyRoot + v6;
  v9 = v3->mActionTreeComponentBase[*(char *)(v7 + 236)];
  if ( !v9 )
    v9 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v9,
    v8,
    (ActionNodeRoot *)v4->m_PropertyValueUID,
    (unsigned __int64)&value_uid,
    v10);
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
_BOOL8 __fastcall TargetPropertyBooleanCondition::ReadValueFromPropertySet(TargetPropertyBooleanCondition *this, ActionContext *action_context)
{
  ActionContext *v2; // rdi
  TargetPropertyBooleanCondition *v3; // rbx
  bool v4; // si
  UFG::qPropertySet *v5; // rax
  bool *v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rdx
  UFG::ActionTreeComponentBase *v10; // rcx
  bool v12; // [rsp+20h] [rbp-8h]

  v2 = action_context;
  v3 = this;
  v4 = 0;
  v5 = TargetPropertyConditionBase::GetPropertySet((TargetPropertyConditionBase *)&this->vfptr, action_context);
  if ( v5 )
  {
    v6 = PropertyUtils::Get<bool>(v5, &v3->m_PropertySymbol, DEPTH_RECURSE);
    if ( v6 )
      v4 = *v6;
  }
  if ( v3->m_CachePropertyValue )
  {
    v7 = v3->m_MyRoot.mOffset;
    v8 = 0i64;
    if ( v7 )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v7);
    else
      v9 = 0i64;
    if ( v7 )
      v8 = (signed __int64)&v3->m_MyRoot + v7;
    v10 = v2->mActionTreeComponentBase[*(char *)(v8 + 236)];
    if ( !v10 )
      v10 = v2->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(v10, v9, (ActionNodeRoot *)v3->m_PropertyValueUID, v4, v12);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet((PropertyConditionBase *)&v3->vfptr, v2);
  return v4;
}

// File Line: 10665
// RVA: 0x28E780
bool __usercall TargetPropertyBooleanCondition::Match@<al>(TargetPropertyBooleanCondition *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  ActionContext *v3; // rbx
  TargetPropertyBooleanCondition *v4; // rdi
  __int64 v6; // rax
  signed __int64 v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rdx
  UFG::ActionTreeComponentBase *v9; // rcx
  bool *v10; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+38h] [rbp+10h]

  v3 = action_context;
  v4 = this;
  LOBYTE(value_uid) = 0;
  if ( !action_context )
    return 0;
  if ( TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
         (TargetPropertyConditionBase *)&this->vfptr,
         action_context,
         a3) )
  {
    return TargetPropertyBooleanCondition::ReadValueFromPropertySet(v4, v3);
  }
  v6 = v4->m_MyRoot.mOffset;
  v7 = 0i64;
  if ( v6 )
    v8 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v6);
  else
    v8 = 0i64;
  if ( v6 )
    v7 = (signed __int64)&v4->m_MyRoot + v6;
  v9 = v3->mActionTreeComponentBase[*(char *)(v7 + 236)];
  if ( !v9 )
    v9 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<bool>(
    v9,
    v8,
    (ActionNodeRoot *)v4->m_PropertyValueUID,
    (unsigned __int64)&value_uid,
    v10);
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
  PropertyIntegerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PropertyConditionBase::`vftable;
  v1->m_PropertySymbol.mUID = -1;
  *(_WORD *)&v1->m_PeriodicallyRecachePropertyValue = 0;
  *(_QWORD *)&v1->m_PropertyValueUID = 0i64;
  v1->m_NextTimeToCachePropertyValueUID = 0;
  v1->m_CachePropertyValue = 1;
  v1->m_MinTimeBeforeRecachePropertyValue = 1.0;
  v1->m_MaxTimeBeforeRecachePropertyValue = 2.0;
  v1->m_MyRoot.mOffset = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PropertyIntegerCondition::`vftable;
  v1->m_Value = 0;
  v1->m_InEqualityOperator.mValue = 0;
}

// File Line: 10723
// RVA: 0x2939F0
__int64 __fastcall PropertyIntegerCondition::ReadValueFromPropertySet(PropertyIntegerCondition *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // rax
  ActionContext *v3; // rdi
  PropertyIntegerCondition *v4; // rbx
  UFG::SceneObjectProperties *v5; // rax
  UFG::qPropertySet *v6; // rcx
  int *v7; // rax
  unsigned __int16 v8; // si
  __int64 v9; // rcx
  signed __int64 v10; // rax
  UFG::ActionTreeComponentBase *v11; // rdx
  UFG::ActionTreeComponentBase *v12; // rcx
  __int16 v14; // [rsp+20h] [rbp-8h]

  v2 = action_context->mSimObject.m_pPointer;
  v3 = action_context;
  v4 = this;
  if ( !v2 )
    return 0i64;
  v5 = v2->m_pSceneObj;
  if ( !v5 )
    return 0i64;
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v6 = v5->mpConstProperties;
    if ( !v6 )
      return 0i64;
  }
  v7 = PropertyUtils::Get<long>(v6, &v4->m_PropertySymbol, DEPTH_RECURSE);
  if ( !v7 )
    return 0i64;
  v8 = *(_WORD *)v7;
  if ( v4->m_CachePropertyValue )
  {
    v9 = v4->m_MyRoot.mOffset;
    v10 = 0i64;
    if ( v9 )
      v11 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v9);
    else
      v11 = 0i64;
    if ( v9 )
      v10 = (signed __int64)&v4->m_MyRoot + v9;
    v12 = v3->mActionTreeComponentBase[*(char *)(v10 + 236)];
    if ( !v12 )
      v12 = v3->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<short>(v12, v11, (ActionNodeRoot *)v4->m_PropertyValueUID, v8, v14);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet((PropertyConditionBase *)&v4->vfptr, v3);
  return v8;
}

// File Line: 10755
// RVA: 0x289110
bool __usercall PropertyIntegerCondition::Match@<al>(PropertyIntegerCondition *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  signed __int64 v3; // rbx
  ActionContext *v4; // rdi
  PropertyIntegerCondition *v5; // rsi
  __int64 v6; // rax
  UFG::ActionTreeComponentBase *v7; // rdx
  UFG::ActionTreeComponentBase *v8; // rcx
  __int16 *v10; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h]

  v3 = 0i64;
  v4 = action_context;
  v5 = this;
  LOWORD(value_uid) = 0;
  if ( action_context )
  {
    if ( PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
           (PropertyConditionBase *)&this->vfptr,
           action_context,
           a3) )
    {
      LOWORD(v3) = PropertyIntegerCondition::ReadValueFromPropertySet(v5, v4);
      LOWORD(value_uid) = v3;
    }
    else
    {
      v6 = v5->m_MyRoot.mOffset;
      if ( v6 )
        v7 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v6);
      else
        v7 = 0i64;
      if ( v6 )
        v3 = (signed __int64)&v5->m_MyRoot + v6;
      v8 = v4->mActionTreeComponentBase[*(char *)(v3 + 236)];
      if ( !v8 )
        v8 = v4->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<short>(
        v8,
        v7,
        (ActionNodeRoot *)v5->m_PropertyValueUID,
        (unsigned __int64)&value_uid,
        v10);
      LOWORD(v3) = value_uid;
    }
  }
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)v5->m_InEqualityOperator.mValue,
           v5->m_Value,
           (signed __int16)v3);
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
  TargetPropertyIntegerCondition *v1; // rbx

  v1 = this;
  TargetPropertyConditionBase::TargetPropertyConditionBase((TargetPropertyConditionBase *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPropertyIntegerCondition::`vftable;
  v1->m_Value = 0;
  v1->m_InEqualityOperator.mValue = 0;
}

// File Line: 10821
// RVA: 0x293E70
__int64 __fastcall TargetPropertyIntegerCondition::ReadValueFromPropertySet(TargetPropertyIntegerCondition *this, ActionContext *action_context)
{
  signed __int64 v2; // rsi
  ActionContext *v3; // rdi
  TargetPropertyIntegerCondition *v4; // rbx
  unsigned __int16 v5; // bp
  UFG::qPropertySet *v6; // rax
  __int64 v7; // rax
  UFG::ActionTreeComponentBase *v8; // rdx
  UFG::ActionTreeComponentBase *v9; // rcx
  __int16 v11; // [rsp+20h] [rbp-8h]

  v2 = 0i64;
  v3 = action_context;
  v4 = this;
  v5 = 0;
  v6 = TargetPropertyConditionBase::GetPropertySet((TargetPropertyConditionBase *)&this->vfptr, action_context);
  if ( v6 )
    v5 = *(_WORD *)PropertyUtils::Get<long>(v6, &v4->m_PropertySymbol, DEPTH_RECURSE);
  if ( v4->m_CachePropertyValue )
  {
    v7 = v4->m_MyRoot.mOffset;
    if ( v7 )
      v8 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v7);
    else
      v8 = 0i64;
    if ( v7 )
      v2 = (signed __int64)&v4->m_MyRoot + v7;
    v9 = v3->mActionTreeComponentBase[*(char *)(v2 + 236)];
    if ( !v9 )
      v9 = v3->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<short>(v9, v8, (ActionNodeRoot *)v4->m_PropertyValueUID, v5, v11);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet((PropertyConditionBase *)&v4->vfptr, v3);
  return v5;
}

// File Line: 10855
// RVA: 0x28E8D0
bool __usercall TargetPropertyIntegerCondition::Match@<al>(TargetPropertyIntegerCondition *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  signed __int64 v3; // rbx
  ActionContext *v4; // rdi
  TargetPropertyIntegerCondition *v5; // rsi
  __int64 v6; // rax
  UFG::ActionTreeComponentBase *v7; // rdx
  UFG::ActionTreeComponentBase *v8; // rcx
  __int16 *v10; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h]

  v3 = 0i64;
  v4 = action_context;
  v5 = this;
  LOWORD(value_uid) = 0;
  if ( action_context )
  {
    if ( TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
           (TargetPropertyConditionBase *)&this->vfptr,
           action_context,
           a3) )
    {
      LOWORD(v3) = TargetPropertyIntegerCondition::ReadValueFromPropertySet(v5, v4);
      LOWORD(value_uid) = v3;
    }
    else
    {
      v6 = v5->m_MyRoot.mOffset;
      if ( v6 )
        v7 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v6);
      else
        v7 = 0i64;
      if ( v6 )
        v3 = (signed __int64)&v5->m_MyRoot + v6;
      v8 = v4->mActionTreeComponentBase[*(char *)(v3 + 236)];
      if ( !v8 )
        v8 = v4->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<short>(
        v8,
        v7,
        (ActionNodeRoot *)v5->m_PropertyValueUID,
        (unsigned __int64)&value_uid,
        v10);
      LOWORD(v3) = value_uid;
    }
  }
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)v5->m_InEqualityOperator.mValue,
           v5->m_Value,
           (signed __int16)v3);
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
  PropertyFloatCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PropertyConditionBase::`vftable;
  v1->m_PropertySymbol.mUID = -1;
  *(_WORD *)&v1->m_PeriodicallyRecachePropertyValue = 0;
  *(_QWORD *)&v1->m_PropertyValueUID = 0i64;
  v1->m_NextTimeToCachePropertyValueUID = 0;
  v1->m_CachePropertyValue = 1;
  v1->m_MinTimeBeforeRecachePropertyValue = 1.0;
  v1->m_MaxTimeBeforeRecachePropertyValue = 2.0;
  v1->m_MyRoot.mOffset = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PropertyFloatCondition::`vftable;
  v1->m_Value = 0.0;
  v1->m_InEqualityOperator.mValue = 0;
}

// File Line: 10916
// RVA: 0x293900
float __fastcall PropertyFloatCondition::ReadValueFromPropertySet(PropertyFloatCondition *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // rax
  ActionContext *v3; // rdi
  PropertyFloatCondition *v4; // rbx
  UFG::SceneObjectProperties *v5; // rax
  UFG::qPropertySet *v6; // rcx
  float *v7; // rsi
  __int64 v8; // rcx
  signed __int64 v9; // rdx
  UFG::ActionTreeComponentBase *v10; // r9
  UFG::ActionTreeComponentBase *v11; // rcx
  __int128 v12; // xmm3
  float v14; // [rsp+20h] [rbp-8h]

  v2 = action_context->mSimObject.m_pPointer;
  v3 = action_context;
  v4 = this;
  if ( !v2 )
    return 0.0;
  v5 = v2->m_pSceneObj;
  if ( !v5 )
    return 0.0;
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v6 = v5->mpConstProperties;
    if ( !v6 )
      return 0.0;
  }
  v7 = PropertyUtils::Get<float>(v6, &v4->m_PropertySymbol, DEPTH_RECURSE);
  if ( !v7 )
    return 0.0;
  if ( v4->m_CachePropertyValue )
  {
    v8 = v4->m_MyRoot.mOffset;
    v9 = 0i64;
    if ( v8 )
      v10 = (UFG::ActionTreeComponentBase *)((char *)&v4->m_MyRoot + v8);
    else
      v10 = 0i64;
    if ( v8 )
      v9 = (signed __int64)&v4->m_MyRoot + v8;
    v11 = v3->mActionTreeComponentBase[*(char *)(v9 + 236)];
    if ( !v11 )
      v11 = v3->mActionTreeComponentBase[1];
    v12 = *(unsigned int *)v7;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v11,
      v10,
      (ActionNodeRoot *)v4->m_PropertyValueUID,
      (unsigned int)v10,
      v14);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet((PropertyConditionBase *)&v4->vfptr, v3);
  return *v7;
}

// File Line: 10944
// RVA: 0x289060
char __usercall PropertyFloatCondition::Match@<al>(PropertyFloatCondition *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  float v3; // xmm0_4
  ActionContext *v4; // rdi
  PropertyFloatCondition *v5; // rbx
  __int64 v6; // rax
  signed __int64 v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rdx
  UFG::ActionTreeComponentBase *v9; // rcx
  float *v11; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h]

  v3 = 0.0;
  v4 = action_context;
  v5 = this;
  value_uid = 0;
  if ( action_context )
  {
    if ( PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
           (PropertyConditionBase *)&this->vfptr,
           action_context,
           a3) )
    {
      v3 = PropertyFloatCondition::ReadValueFromPropertySet(v5, v4);
      value_uid = LODWORD(v3);
    }
    else
    {
      v6 = v5->m_MyRoot.mOffset;
      v7 = 0i64;
      if ( v6 )
        v8 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v6);
      else
        v8 = 0i64;
      if ( v6 )
        v7 = (signed __int64)&v5->m_MyRoot + v6;
      v9 = v4->mActionTreeComponentBase[*(char *)(v7 + 236)];
      if ( !v9 )
        v9 = v4->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
        v9,
        v8,
        (ActionNodeRoot *)v5->m_PropertyValueUID,
        (unsigned __int64)&value_uid,
        v11);
      v3 = *(float *)&value_uid;
    }
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v5->m_InEqualityOperator.mValue, v5->m_Value, v3);
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
  TargetPropertyFloatCondition *v1; // rbx

  v1 = this;
  TargetPropertyConditionBase::TargetPropertyConditionBase((TargetPropertyConditionBase *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPropertyFloatCondition::`vftable;
  v1->m_Value = 0.0;
  v1->m_InEqualityOperator.mValue = 0;
}

// File Line: 11010
// RVA: 0x293DC0
float __fastcall TargetPropertyFloatCondition::ReadValueFromPropertySet(TargetPropertyFloatCondition *this, ActionContext *action_context)
{
  ActionContext *v2; // rdi
  TargetPropertyFloatCondition *v3; // rbx
  float v4; // xmm6_4
  UFG::qPropertySet *v5; // rax
  unsigned int v6; // er9
  float *v7; // rax
  __int64 v8; // rax
  signed __int64 v9; // rcx
  UFG::ActionTreeComponentBase *v10; // rdx
  UFG::ActionTreeComponentBase *v11; // rcx
  float value; // [rsp+20h] [rbp-18h]

  v2 = action_context;
  v3 = this;
  v4 = 0.0;
  v5 = TargetPropertyConditionBase::GetPropertySet((TargetPropertyConditionBase *)&this->vfptr, action_context);
  if ( v5 )
  {
    v7 = UFG::qPropertySet::Get<float>(v5, &v3->m_PropertySymbol, DEPTH_RECURSE);
    if ( v7 )
      v4 = *v7;
  }
  if ( v3->m_CachePropertyValue )
  {
    v8 = v3->m_MyRoot.mOffset;
    v9 = 0i64;
    if ( v8 )
      v10 = (UFG::ActionTreeComponentBase *)((char *)&v3->m_MyRoot + v8);
    else
      v10 = 0i64;
    if ( v8 )
      v9 = (signed __int64)&v3->m_MyRoot + v8;
    v11 = v2->mActionTreeComponentBase[*(char *)(v9 + 236)];
    if ( !v11 )
      v11 = v2->mActionTreeComponentBase[1];
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<float>(
      v11,
      v10,
      (ActionNodeRoot *)v3->m_PropertyValueUID,
      v6,
      value);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet((PropertyConditionBase *)&v3->vfptr, v2);
  return v4;
}

// File Line: 11038
// RVA: 0x28E820
char __usercall TargetPropertyFloatCondition::Match@<al>(TargetPropertyFloatCondition *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  float v3; // xmm0_4
  ActionContext *v4; // rdi
  TargetPropertyFloatCondition *v5; // rbx
  __int64 v6; // rax
  signed __int64 v7; // rcx
  UFG::ActionTreeComponentBase *v8; // rdx
  UFG::ActionTreeComponentBase *v9; // rcx
  float *v11; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h]

  v3 = 0.0;
  v4 = action_context;
  v5 = this;
  value_uid = 0;
  if ( action_context )
  {
    if ( TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
           (TargetPropertyConditionBase *)&this->vfptr,
           action_context,
           a3) )
    {
      v3 = TargetPropertyFloatCondition::ReadValueFromPropertySet(v5, v4);
      value_uid = LODWORD(v3);
    }
    else
    {
      v6 = v5->m_MyRoot.mOffset;
      v7 = 0i64;
      if ( v6 )
        v8 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v6);
      else
        v8 = 0i64;
      if ( v6 )
        v7 = (signed __int64)&v5->m_MyRoot + v6;
      v9 = v4->mActionTreeComponentBase[*(char *)(v7 + 236)];
      if ( !v9 )
        v9 = v4->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<float>(
        v9,
        v8,
        (ActionNodeRoot *)v5->m_PropertyValueUID,
        (unsigned __int64)&value_uid,
        v11);
      v3 = *(float *)&value_uid;
    }
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v5->m_InEqualityOperator.mValue, v5->m_Value, v3);
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
UFG::qSymbol *__fastcall PropertySymbolCondition::ReadValueFromPropertySet(PropertySymbolCondition *this, UFG::qSymbol *result, ActionContext *action_context)
{
  ActionContext *v3; // rsi
  UFG::qSymbol *v4; // rbx
  PropertySymbolCondition *v5; // rdi
  UFG::SimObject *v6; // rax
  UFG::SceneObjectProperties *v7; // rdx
  UFG::qPropertySet *v8; // rcx
  UFG::qSymbol *v9; // r14
  __int64 v10; // rcx
  signed __int64 v11; // rax
  UFG::ActionTreeComponentBase *v12; // rdx
  UFG::ActionTreeComponentBase *v13; // rcx
  ActionNodeRoot *v14; // r8
  unsigned int v15; // eax
  unsigned int v17; // [rsp+60h] [rbp+18h]
  int *value_uid; // [rsp+68h] [rbp+20h]

  v3 = action_context;
  v4 = result;
  v5 = this;
  v6 = action_context->mSimObject.m_pPointer;
  if ( v6
    && v6->m_pSceneObj
    && ((v7 = v6->m_pSceneObj, (v8 = v7->mpWritableProperties) != 0i64) || (v8 = v7->mpConstProperties) != 0i64)
    && (v9 = PropertyUtils::Get<UFG::qSymbol>(v8, &v5->m_PropertySymbol, DEPTH_RECURSE)) != 0i64 )
  {
    if ( v5->m_CachePropertyValue )
    {
      value_uid = (int *)&v17;
      v17 = v9->mUID;
      v10 = v5->m_MyRoot.mOffset;
      v11 = 0i64;
      if ( v10 )
        v12 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v10);
      else
        v12 = 0i64;
      if ( v10 )
        v11 = (signed __int64)&v5->m_MyRoot + v10;
      v13 = v3->mActionTreeComponentBase[*(char *)(v11 + 236)];
      if ( !v13 )
        v13 = v3->mActionTreeComponentBase[1];
      v14 = (ActionNodeRoot *)v5->m_PropertyValueUID;
      LODWORD(value_uid) = v17;
      UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::qSymbol>(
        v13,
        v12,
        v14,
        (unsigned __int64)&value_uid,
        (UFG::qSymbol)-2);
    }
    PropertyConditionBase::ValueHasBeenReadFromPropertySet((PropertyConditionBase *)&v5->vfptr, v3);
    v15 = v9->mUID;
  }
  else
  {
    v15 = UFG::gNullQSymbol.mUID;
  }
  v4->mUID = v15;
  return v4;
}

// File Line: 11122
// RVA: 0x2891C0
bool __usercall PropertySymbolCondition::Match@<al>(PropertySymbolCondition *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  unsigned int v3; // eax
  ActionContext *v4; // rbx
  PropertySymbolCondition *v5; // rdi
  __int64 v6; // rax
  UFG::ActionTreeComponentBase *v7; // rdx
  signed __int64 v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  UFG::qSymbol *v11; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h]
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v3 = -1;
  v4 = action_context;
  v5 = this;
  value_uid = -1;
  if ( action_context )
  {
    if ( PropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
           (PropertyConditionBase *)&this->vfptr,
           action_context,
           a3) )
    {
      v3 = PropertySymbolCondition::ReadValueFromPropertySet(v5, &result, v4)->mUID;
    }
    else
    {
      v6 = v5->m_MyRoot.mOffset;
      if ( v6 )
        v7 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v6);
      else
        v7 = 0i64;
      if ( v6 )
        v8 = (signed __int64)&v5->m_MyRoot + v6;
      else
        v8 = 0i64;
      v9 = v4->mActionTreeComponentBase[*(char *)(v8 + 236)];
      if ( !v9 )
        v9 = v4->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::qSymbol>(
        v9,
        v7,
        (ActionNodeRoot *)v5->m_PropertyValueUID,
        (unsigned __int64)&value_uid,
        v11);
      v3 = value_uid;
    }
  }
  return v5->m_Value.mUID == v3;
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
UFG::qSymbol *__fastcall TargetPropertySymbolCondition::ReadValueFromPropertySet(TargetPropertySymbolCondition *this, UFG::qSymbol *result, ActionContext *action_context)
{
  ActionContext *v3; // rdi
  UFG::qSymbol *v4; // rsi
  TargetPropertySymbolCondition *v5; // rbx
  UFG::qPropertySet *v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rdx
  UFG::ActionTreeComponentBase *v10; // rcx
  ActionNodeRoot *v11; // r8
  UFG::qPropertyDepth depth; // [rsp+20h] [rbp-38h]
  UFG::qSymbol defaultValue; // [rsp+60h] [rbp+8h]
  UFG::qSymbol resulta; // [rsp+68h] [rbp+10h]
  UFG::qSymbol *v16; // [rsp+78h] [rbp+20h]

  v3 = action_context;
  v4 = result;
  v5 = this;
  result->mUID = UFG::gNullQSymbol.mUID;
  v6 = TargetPropertyConditionBase::GetPropertySet((TargetPropertyConditionBase *)&this->vfptr, action_context);
  if ( v6 )
  {
    v16 = &defaultValue;
    defaultValue.mUID = UFG::gNullQSymbol.mUID;
    v4->mUID = PropertyUtils::GetWithDefault<UFG::qSymbol>(
                 &resulta,
                 v6,
                 &v5->m_PropertySymbol,
                 (__int64)&defaultValue,
                 DEPTH_RECURSE)->mUID;
  }
  if ( v5->m_CachePropertyValue )
  {
    *(_QWORD *)&resulta.mUID = &defaultValue;
    defaultValue.mUID = v4->mUID;
    v7 = v5->m_MyRoot.mOffset;
    v8 = 0i64;
    if ( v7 )
      v9 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v7);
    else
      v9 = 0i64;
    if ( v7 )
      v8 = (signed __int64)&v5->m_MyRoot + v7;
    v10 = v3->mActionTreeComponentBase[*(char *)(v8 + 236)];
    if ( !v10 )
      v10 = v3->mActionTreeComponentBase[1];
    v11 = (ActionNodeRoot *)v5->m_PropertyValueUID;
    v16 = &resulta;
    resulta.mUID = defaultValue.mUID;
    UFG::ActionTreeComponentBase::SetMemoryValueImpl<UFG::qSymbol>(
      v10,
      v9,
      v11,
      (unsigned __int64)&resulta,
      (UFG::qSymbol)depth);
  }
  PropertyConditionBase::ValueHasBeenReadFromPropertySet((PropertyConditionBase *)&v5->vfptr, v3);
  return v4;
}

// File Line: 11223
// RVA: 0x28E980
bool __usercall TargetPropertySymbolCondition::Match@<al>(TargetPropertySymbolCondition *this@<rcx>, ActionContext *action_context@<rdx>, float *a3@<xmm6>)
{
  unsigned int v3; // eax
  ActionContext *v4; // rbx
  TargetPropertySymbolCondition *v5; // rdi
  __int64 v6; // rax
  UFG::ActionTreeComponentBase *v7; // rdx
  signed __int64 v8; // rcx
  UFG::ActionTreeComponentBase *v9; // rcx
  UFG::qSymbol *v11; // [rsp+20h] [rbp-8h]
  unsigned int value_uid; // [rsp+30h] [rbp+8h]
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v3 = -1;
  v4 = action_context;
  v5 = this;
  value_uid = -1;
  if ( action_context )
  {
    if ( TargetPropertyConditionBase::DetermineIfValueNeedsToBeReadFromPropertySet(
           (TargetPropertyConditionBase *)&this->vfptr,
           action_context,
           a3) )
    {
      v3 = TargetPropertySymbolCondition::ReadValueFromPropertySet(v5, &result, v4)->mUID;
    }
    else
    {
      v6 = v5->m_MyRoot.mOffset;
      if ( v6 )
        v7 = (UFG::ActionTreeComponentBase *)((char *)&v5->m_MyRoot + v6);
      else
        v7 = 0i64;
      if ( v6 )
        v8 = (signed __int64)&v5->m_MyRoot + v6;
      else
        v8 = 0i64;
      v9 = v4->mActionTreeComponentBase[*(char *)(v8 + 236)];
      if ( !v9 )
        v9 = v4->mActionTreeComponentBase[1];
      UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::qSymbol>(
        v9,
        v7,
        (ActionNodeRoot *)v5->m_PropertyValueUID,
        (unsigned __int64)&value_uid,
        v11);
      v3 = value_uid;
    }
  }
  return v5->m_Value.mUID == v3;
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
  SkookumCondition *v1; // rbx
  const char *v2; // rdx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SkookumCondition::`vftable;
  v2 = SkookumCondition::sDefaultScope;
  v1->mClassScopeText.mOffset = 1i64;
  BinString::Set(&v1->mClassScopeText, v2);
  v1->mSkookumScriptRaw.mOffset = 1i64;
  BinString::Set(&v1->mSkookumScriptRaw, &customWorldMapCaption);
  v1->mpScript = 0i64;
}

// File Line: 11285
// RVA: 0x278570
void __fastcall SkookumCondition::SkookumCondition(SkookumCondition *this, MemImageLoadFlag flag)
{
  SkookumCondition *v2; // rbx
  const char *v3; // rdi
  const char *v4; // rsi

  v2 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SkookumCondition::`vftable;
  v3 = BinString::sEmptyString;
  if ( this->mClassScopeText.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    v4 = (char *)&this->mClassScopeText + (this->mClassScopeText.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v4 = BinString::sEmptyString;
  if ( this->mSkookumScriptRaw.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    v3 = (char *)&this->mSkookumScriptRaw + (this->mSkookumScriptRaw.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  if ( (signed int)UFG::qStringLength(v3) > 0 )
    v2->mpScript = (UFG::ScriptCache::Script *)UFG::ScriptCache::GetScript(
                                                 v3,
                                                 v4,
                                                 SkookumCondition::sDefaultScope,
                                                 "Track");
}

// File Line: 11301
// RVA: 0x2798C0
void __fastcall SkookumCondition::~SkookumCondition(SkookumCondition *this)
{
  SkookumCondition *v1; // rbx
  UFG::ScriptCache::Script *v2; // rcx
  char *v3; // rcx
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SkookumCondition::`vftable;
  v2 = this->mpScript;
  if ( v2 )
  {
    UFG::ScriptCache::ReleaseScript(v2);
    v1->mpScript = 0i64;
  }
  if ( !(~LOBYTE(v1->mSkookumScriptRaw.mOffset) & 1) )
  {
    if ( v1->mSkookumScriptRaw.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)&v1->mSkookumScriptRaw + (v1->mSkookumScriptRaw.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  if ( !(~LOBYTE(v1->mClassScopeText.mOffset) & 1) )
  {
    if ( v1->mClassScopeText.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v4 = (char *)&v1->mClassScopeText + (v1->mClassScopeText.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v4 != BinString::sEmptyString )
        operator delete[](v4);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 11346
// RVA: 0x289B10
bool __fastcall SkookumCondition::Match(SkookumCondition *this, ActionContext *pContext)
{
  ActionContext *v2; // rdi
  bool v3; // bl
  UFG::ScriptCache::Script *v4; // rcx
  UFG::SimObject *v5; // rax
  SSCode *v6; // rsi
  UFG::SimObject *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::TSActorComponent *v9; // rax
  UFG::TSActor *v10; // rax
  SSClass *v11; // rdx
  ActionPath *v12; // rax
  char *v13; // rax
  AString *v14; // rax
  AStringRef *v15; // rbx
  bool v16; // zf
  AObjReusePool<AStringRef> *v17; // rax
  AObjReusePool<AStringRef> *v18; // r8
  AObjBlock<AStringRef> *v19; // rax
  unsigned __int64 v20; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v21; // rcx
  int v22; // edx
  SSInstance *v24; // rcx
  ActionPath result; // [rsp+38h] [rbp-20h]
  SSInstance *ppResult; // [rsp+60h] [rbp+8h]
  AString v27; // [rsp+70h] [rbp+18h]

  v2 = pContext;
  v3 = 0;
  v4 = this->mpScript;
  if ( !v4 )
    return 0;
  v5 = pContext->mSimObject.m_pPointer;
  if ( v5 )
  {
    if ( (LOBYTE(v5->m_Flags) >> 1) & 1 )
      return 0;
  }
  v6 = UFG::ScriptCache::GetScriptCode(v4);
  if ( v6 )
  {
    v7 = v2->mSimObject.m_pPointer;
    if ( v7
      && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v7, UFG::TSActorComponent::_TypeUID)) : (v9 = (UFG::TSActorComponent *)v7->m_Components.p[2].m_pComponent)) : (v9 = (UFG::TSActorComponent *)v7->m_Components.p[3].m_pComponent)) : (v9 = (UFG::TSActorComponent *)v7->m_Components.p[4].m_pComponent)) : (v9 = (UFG::TSActorComponent *)v7->m_Components.p[4].m_pComponent),
          v9) )
    {
      v10 = UFG::TSActorComponent::GetActor(v9);
    }
    else
    {
      v10 = (UFG::TSActor *)SkookumScript::c_world_p;
    }
    v11 = v10->i_class_p;
    ppResult = 0i64;
    if ( UFG::SkookumMgr::RunExternalCodeBlock(v6, v11, (SSInstance *)&v10->vfptr, 0i64, &ppResult) )
    {
      v12 = ActionController::GetPlayingFullPath(v2->mActionController, &result);
      v13 = ActionPath::GetString_DBG(v12);
      v14 = a_str_format(&v27, "Coroutine used instead of a method in SkookumCondition at %s", v13);
      SSDebug::print_error(v14, AErrLevel_error);
      v15 = v27.i_str_ref_p;
      v16 = v27.i_str_ref_p->i_ref_count == 1;
      --v15->i_ref_count;
      if ( v16 )
      {
        if ( v15->i_deallocate )
          AMemory::c_free_func(v15->i_cstr_p);
        v17 = AStringRef::get_pool();
        v18 = v17;
        v19 = v17->i_block_p;
        v20 = (unsigned __int64)v19->i_objects_a;
        if ( (unsigned __int64)v15 < v20 || (v21 = &v18->i_pool, (unsigned __int64)v15 >= v20 + 24i64 * v19->i_size) )
          v21 = &v18->i_exp_pool;
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v21, v15);
      }
      v22 = result.mPath.mCount;
      if ( result.mPath.mCount >= 0 )
      {
        if ( result.mPath.mData.mOffset )
        {
          if ( (UFG::qOffset64<ActionID *> *)((char *)&result.mPath.mData + result.mPath.mData.mOffset) )
          {
            operator delete[]((char *)&result.mPath.mData + result.mPath.mData.mOffset);
            v22 = result.mPath.mCount;
          }
        }
        result.mPath.mData.mOffset = 0i64;
        result.mPath.mCount = v22 & 0x80000000;
      }
      return 0;
    }
    v3 = 1;
    v24 = ppResult;
    if ( ppResult )
    {
      if ( ppResult->i_class_p == SSBrain::c_boolean_class_p )
        v3 = ppResult->i_user_data == 1;
      v16 = ppResult->i_ref_count-- == 1;
      if ( v16 )
      {
        v24->i_ref_count = 2147483648;
        ((void (*)(void))v24->vfptr[1].get_scope_context)();
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
  FaceActionRequestCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FaceActionRequestCondition::`vftable;
  *(_WORD *)&v1->mFaceAction.mValue = 5650;
}

// File Line: 11432
// RVA: 0x281720
bool __fastcall FaceActionRequestCondition::Match(FaceActionRequestCondition *this, ActionContext *pContext)
{
  FaceActionRequestCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::FaceActionComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                       + *(_QWORD *)&v5[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = (UFG::FaceActionComponent *)v7->m_Components.p[45].m_pComponent;
        }
        else
        {
          if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FaceActionComponent::_TypeUID);
            else
              v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::FaceActionComponent::_TypeUID);
          }
          else
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FaceActionComponent::_TypeUID);
          }
          v9 = (UFG::FaceActionComponent *)v10;
        }
        if ( v9
          && v9->mFaceActionSetup
          && UFG::FaceActionComponent::IsFaceActionAvailable(
               v9,
               (UFG::eFaceActionEnum)(unsigned __int8)v2->mFaceAction.mValue,
               1)
          && UFG::FaceActionComponent::IsFaceActionRequirementMet(v9) )
        {
          result = 1;
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
  FaceActionAvailableCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FaceActionAvailableCondition::`vftable;
  *(_WORD *)&v1->mFaceAction.mValue = 274;
}

// File Line: 11485
// RVA: 0x281650
char __fastcall FaceActionAvailableCondition::Match(FaceActionAvailableCondition *this, ActionContext *pContext)
{
  FaceActionAvailableCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::FaceActionComponent *v5; // rax
  char v6; // cl
  bool v7; // zf

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::FaceActionComponent::_TypeUID);
      else
        v5 = (UFG::FaceActionComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v3,
                                                             UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v3->vfptr,
                                                                                                     UFG::FaceActionComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = v2->mCheckEnabled;
      v7 = v6 == 0;
      if ( v6 )
      {
        if ( !v5->mFaceActionSetup )
          return 0;
        v7 = v6 == 0;
      }
      if ( UFG::FaceActionComponent::IsFaceActionAvailable(
             v5,
             (UFG::eFaceActionEnum)(unsigned __int8)v2->mFaceAction.mValue,
             !v7) )
      {
        return 1;
      }
      return 0;
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
  FaceMeterCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FaceMeterCondition::`vftable;
  v1->mFaceValue = 0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 11530
// RVA: 0x281910
bool __fastcall FaceMeterCondition::Match(FaceMeterCondition *this, ActionContext *pContext)
{
  FaceMeterCondition *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  float v4; // xmm0_4

  v2 = this;
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetStat(v3, Face);
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
           v2->mFaceValue,
           (signed int)v4);
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
  FaceMeterActivatedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&FaceMeterActivatedCondition::`vftable;
}

// File Line: 11557
// RVA: 0x281880
bool __fastcall FaceMeterActivatedCondition::Match(FaceMeterActivatedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceMeterComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceMeterComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceMeterComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceMeterComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceMeterComponent::_TypeUID)),
        v4) )
  {
    result = BYTE1(v4[135].m_SafePointerList.mNode.mPrev);
  }
  else
  {
    result = 0;
  }
  return result;
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
  PipLevelCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PipLevelCondition::`vftable;
  v1->mPipLevel = 0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 11593
// RVA: 0x288C90
bool __fastcall PipLevelCondition::Match(PipLevelCondition *this, ActionContext *pContext)
{
  PipLevelCondition *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  int v4; // eax

  v2 = this;
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetFaceLevel(v3);
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mPipLevel, v4);
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
  IsFactionStandingCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsFactionStandingCondition::`vftable;
  *(_WORD *)&v1->mFactionStanding.mValue = 5632;
}

// File Line: 11625
// RVA: 0x283CE0
bool __fastcall IsFactionStandingCondition::Match(IsFactionStandingCondition *this, ActionContext *pContext)
{
  IsFactionStandingCondition *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rcx
  UFG::SimComponent *v7; // rax
  __int64 v8; // rax
  UFG::SimObjectCVBase *v9; // rbx
  unsigned __int16 v10; // cx
  hkSimpleLocalFrame *v11; // rdi
  unsigned __int16 v12; // dx
  UFG::SimObjectCharacterPropertiesComponent *v13; // rax
  UFG::SimObjectCharacterPropertiesComponent *v14; // rbx
  UFG::SimObjectCVBase *v15; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v16; // rax
  unsigned __int16 v17; // dx
  unsigned int v18; // edx
  bool v19; // zf
  UFG::eFactionClassEnum v20; // edi
  UFG::eFactionClassEnum v21; // ebx
  UFG::GameStatTracker *v22; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v6 = v7;
    }
    else
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      v8 = ((__int64 (*)(void))v6->vfptr[15].__vecDelDtor)();
      if ( v8 )
      {
        v9 = *(UFG::SimObjectCVBase **)(56i64
                                      * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                           + *(_QWORD *)(v8 + 96)
                                                           + 8i64)
                                      + *(_QWORD *)(v8 + 88)
                                      + 40);
        if ( v9 )
        {
          v10 = v9->m_Flags;
          if ( (v10 & 0x8000u) != 0 )
          {
            v11 = (hkSimpleLocalFrame *)((v10 >> 14) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v9->vfptr,
                                                             UFG::VehicleOccupantComponent::_TypeUID) : v9->m_Components.p[30].m_pComponent);
            if ( v11 && Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v11) )
              v9 = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v11);
          }
          if ( v9 )
          {
            v12 = v9->m_Flags;
            if ( (v9->m_Flags >> 14) & 1 )
            {
              v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v9);
            }
            else if ( (v12 & 0x8000u) == 0 )
            {
              if ( (v12 >> 13) & 1 )
                v13 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v9->vfptr,
                                                                      UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              else
                v13 = (UFG::SimObjectCharacterPropertiesComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                         (UFG::SimObjectGame *)&v9->vfptr,
                                                                                         UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
            }
            else
            {
              v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v9);
            }
            v14 = v13;
            if ( v13 )
            {
              v15 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
              if ( v15 )
              {
                v17 = v15->m_Flags;
                if ( (v17 >> 14) & 1 || (v17 & 0x8000u) != 0 )
                {
                  v16 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v15);
                }
                else
                {
                  if ( (v17 >> 13) & 1 )
                  {
                    v18 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
                  }
                  else
                  {
                    v19 = ((v17 >> 12) & 1) == 0;
                    v18 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
                    if ( v19 )
                    {
                      v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                            (UFG::SimObject *)&v15->vfptr,
                                                                            UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                      goto LABEL_43;
                    }
                  }
                  v16 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        (UFG::SimObjectGame *)&v15->vfptr,
                                                                        v18);
                }
              }
              else
              {
                v16 = 0i64;
              }
LABEL_43:
              v20 = v16->m_eFactionClass;
              v21 = v14->m_eFactionClass;
              v22 = UFG::FactionInterface::Get();
              return (unsigned __int8)v2->mFactionStanding.mValue == (unsigned int)UFG::FactionInterface::GetStanding(
                                                                                     &v22->mFactionInterface,
                                                                                     v20,
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
void __fastcall IsTargetsTargetFactionStandingCondition::IsTargetsTargetFactionStandingCondition(IsTargetsTargetFactionStandingCondition *this)
{
  IsTargetsTargetFactionStandingCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsTargetsTargetFactionStandingCondition::`vftable;
  *(_WORD *)&v1->mFactionStanding.mValue = 5632;
  v1->mTargetsTargetType.mValue = 23;
}

// File Line: 11694
// RVA: 0x284FF0
bool __fastcall IsTargetsTargetFactionStandingCondition::Match(IsTargetsTargetFactionStandingCondition *this, ActionContext *pContext)
{
  IsTargetsTargetFactionStandingCondition *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rcx
  UFG::SimComponent *v7; // rax
  __int64 v8; // rax
  UFG::SimObjectCVBase *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::TargetingSystemPedBaseComponent *v11; // rax
  UFG::SimObjectCVBase *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimObjectCharacterPropertiesComponent *v14; // rax
  UFG::SimObjectCharacterPropertiesComponent *v15; // rbx
  UFG::SimObjectCVBase *v16; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v17; // rax
  unsigned __int16 v18; // dx
  unsigned int v19; // edx
  bool v20; // zf
  UFG::eFactionClassEnum v21; // edi
  UFG::eFactionClassEnum v22; // ebx
  UFG::GameStatTracker *v23; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v6 = v7;
    }
    else
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      v8 = ((__int64 (*)(void))v6->vfptr[15].__vecDelDtor)();
      if ( v8 )
      {
        v9 = *(UFG::SimObjectCVBase **)(56i64
                                      * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                           + *(_QWORD *)(v8 + 96)
                                                           + 8i64)
                                      + *(_QWORD *)(v8 + 88)
                                      + 40);
        if ( v9 )
        {
          v10 = v9->m_Flags;
          if ( (v10 >> 14) & 1 )
          {
            v11 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v9);
          }
          else if ( (v10 & 0x8000u) == 0 )
          {
            if ( (v10 >> 13) & 1 )
              v11 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v9->vfptr,
                                                              UFG::TargetingSystemPedBaseComponent::_TypeUID);
            else
              v11 = (UFG::TargetingSystemPedBaseComponent *)((v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                 (UFG::SimObjectGame *)&v9->vfptr,
                                                                                 UFG::TargetingSystemPedBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::TargetingSystemPedBaseComponent::_TypeUID));
          }
          else
          {
            v11 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v9);
          }
          if ( v11 )
          {
            v12 = (UFG::SimObjectCVBase *)v11->m_pTargets[(unsigned __int8)v11->m_pTargetingMap->m_Map.p[(unsigned __int8)v2->mTargetsTargetType.mValue]].m_pTarget.m_pPointer;
            if ( v12 )
            {
              v13 = v12->m_Flags;
              if ( (v13 >> 14) & 1 )
              {
                v14 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v12);
              }
              else if ( (v13 & 0x8000u) == 0 )
              {
                if ( (v13 >> 13) & 1 )
                  v14 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        (UFG::SimObjectGame *)&v12->vfptr,
                                                                        UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                else
                  v14 = (UFG::SimObjectCharacterPropertiesComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                           (UFG::SimObjectGame *)&v12->vfptr,
                                                                                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
              }
              else
              {
                v14 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v12);
              }
              v15 = v14;
              if ( v14 )
              {
                v16 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
                if ( v16 )
                {
                  v18 = v16->m_Flags;
                  if ( (v18 >> 14) & 1 || (v18 & 0x8000u) != 0 )
                  {
                    v17 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v16);
                  }
                  else
                  {
                    if ( (v18 >> 13) & 1 )
                    {
                      v19 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
                    }
                    else
                    {
                      v20 = ((v18 >> 12) & 1) == 0;
                      v19 = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
                      if ( v20 )
                      {
                        v17 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                              (UFG::SimObject *)&v16->vfptr,
                                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                        goto LABEL_46;
                      }
                    }
                    v17 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v16->vfptr,
                                                                          v19);
                  }
                }
                else
                {
                  v17 = 0i64;
                }
LABEL_46:
                v21 = v17->m_eFactionClass;
                v22 = v15->m_eFactionClass;
                v23 = UFG::FactionInterface::Get();
                return (unsigned __int8)v2->mFactionStanding.mValue == (unsigned int)UFG::FactionInterface::GetStanding(
                                                                                       &v23->mFactionInterface,
                                                                                       v21,
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
  IsExcludedFromScoring *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsExcludedFromScoring::`vftable;
  v1->mTargetType.mValue = 22;
}

// File Line: 11753
// RVA: 0x283C40
bool __fastcall IsExcludedFromScoring::Match(IsExcludedFromScoring *this, ActionContext *pContext)
{
  UFG::SimObject *v2; // rbx
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  v2 = UFG::getTarget(pContext, (UFG::eTargetTypeEnum)(unsigned __int8)this->mTargetType.mValue);
  return v2
      && (v2->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0xCD8AAA2A)->mUID
       || v2->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0x700708E6u)->mUID
       || v2->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0x28EB095Bu)->mUID
       || v2->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0xDB443529)->mUID
       || v2->m_Name.mUID == UFG::qSymbol::qSymbol(&result, 0x69BC658Au)->mUID);
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
  IsTargetingStandingCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsTargetingStandingCondition::`vftable;
  *(_WORD *)&v1->mFactionStanding.mValue = 5632;
}

// File Line: 11825
// RVA: 0x284DC0
bool __fastcall IsTargetingStandingCondition::Match(IsTargetingStandingCondition *this, ActionContext *pContext)
{
  IsTargetingStandingCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  UFG::TargetingSystemPedBaseComponent *v7; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5 && (v7 = (UFG::TargetingSystemPedBaseComponent *)((__int64 (*)(void))v5->vfptr[15].__vecDelDtor)()) != 0i64) )
  {
    result = (unsigned __int8)v2->mFactionStanding.mValue == (unsigned int)UFG::TargetingSystemPedBaseComponent::GetTargetingStandingToMe(
                                                                             v7,
                                                                             (UFG::eTargetTypeEnum)(unsigned __int8)v2->mTargetType.mValue);
  }
  else
  {
    result = 0;
  }
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
  TargetValidCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetValidCondition::`vftable;
  v1->mTargetType = 0;
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
  TargetIsEqualCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetIsEqualCondition::`vftable;
  *(_QWORD *)&v1->mTarget1Owner.mValue = 1i64;
  *(_QWORD *)&v1->mTarget2Owner.mValue = 1i64;
}

// File Line: 11941
// RVA: 0x28C590
bool __fastcall TargetIsEqualCondition::Match(TargetIsEqualCondition *this, ActionContext *pContext)
{
  TargetIsEqualCondition *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // r8
  UFG::SimComponent *v10; // rax
  __int64 v11; // rdi
  UFG::SimObjectGame *v12; // r8
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // r8
  UFG::SimComponent *v15; // rax
  __int64 v16; // rcx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    goto LABEL_43;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    goto LABEL_43;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(v2->mTarget1Owner.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v7 )
    goto LABEL_43;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = v7->m_Components.p[20].m_pComponent;
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v9 = v10;
  }
  else
  {
    v9 = v7->m_Components.p[20].m_pComponent;
  }
  if ( v9
    && (v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(v2->mTarget1Type.mValue + *(_QWORD *)&v9[1].m_Flags + 8i64)
                        + *(_QWORD *)&v9[1].m_TypeUID
                        + 40)) != 0
    && (v12 = *(UFG::SimObjectGame **)(56i64
                                     * *(unsigned __int8 *)(v2->mTarget2Owner.mValue + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                     + *(_QWORD *)&v5[1].m_TypeUID
                                     + 40)) != 0i64
    && ((v13 = v12->m_Flags, !((v13 >> 14) & 1)) ? ((v13 & 0x8000u) == 0 ? (!((v13 >> 13) & 1) ? (!((v13 >> 12) & 1) ? (v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                            v14 = v15) : (v14 = v12->m_Components.p[20].m_pComponent)) : (v14 = v12->m_Components.p[20].m_pComponent),
        v14
     && (v16 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(v2->mTarget2Type.mValue + *(_QWORD *)&v14[1].m_Flags + 8i64)
                         + *(_QWORD *)&v14[1].m_TypeUID
                         + 40)) != 0) )
  {
    result = v11 == v16;
  }
  else
  {
LABEL_43:
    result = 0;
  }
  return result;
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
  TargetInventoryItemCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetInventoryItemCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 0i64;
}

// File Line: 12006
// RVA: 0x28C4F0
bool __fastcall TargetInventoryItemCondition::Match(TargetInventoryItemCondition *this, ActionContext *pContext)
{
  TargetInventoryItemCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rax
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)this->mTargetType);
  if ( v3
    && (v4 = v3->m_Flags, !((v4 >> 14) & 1))
    && (v4 & 0x8000u) == 0
    && (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v3->vfptr,
                                                         UFG::InventoryItemComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryItemComponent::_TypeUID)),
                             v5 = v6) : (v5 = v3->m_Components.p[11].m_pComponent),
        v5) )
  {
    result = LODWORD(v5[1].m_pSimObject) == v2->mInventoryItemType;
  }
  else
  {
    result = 0;
  }
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
  TargetSimObjectTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectTypeCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 0i64;
}

// File Line: 12047
// RVA: 0x28F6D0
bool __fastcall TargetSimObjectTypeCondition::Match(TargetSimObjectTypeCondition *this, ActionContext *pContext)
{
  TargetSimObjectTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rax
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)this->mTargetType);
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectPropertiesComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectPropertiesComponent::_TypeUID)),
                                                                                             v5 = v6) : (v5 = v3->m_Components.p[4].m_pComponent)) : (v5 = v3->m_Components.p[3].m_pComponent)) : (v5 = v3->m_Components.p[3].m_pComponent),
        v5) )
  {
    result = LODWORD(v5[1].m_SafePointerList.mNode.mNext) == v2->mSimObjectType;
  }
  else
  {
    result = 0;
  }
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
void __fastcall TargetSimObjectWeaponTypeCondition::TargetSimObjectWeaponTypeCondition(TargetSimObjectWeaponTypeCondition *this)
{
  TargetSimObjectWeaponTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponTypeCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 0i64;
}

// File Line: 12093
// RVA: 0x290260
bool __fastcall TargetSimObjectWeaponTypeCondition::Match(TargetSimObjectWeaponTypeCondition *this, ActionContext *pContext)
{
  TargetSimObjectWeaponTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectProp *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimObjectWeaponPropertiesComponent *v9; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(UFG::SimObjectProp **)(56i64
                                     * *(unsigned __int8 *)((unsigned int)v2->mTargetType
                                                          + *(_QWORD *)&v5[1].m_Flags
                                                          + 8i64)
                                     + *(_QWORD *)&v5[1].m_TypeUID
                                     + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)) : (v9 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v9 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v7))) : (v9 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v9 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)),
         v9)) )
  {
    result = v9->mWeaponTypeInfo->mFireModes[v9->mFireMode]->mSimObjectWeaponType == v2->mSimObjectWeaponType;
  }
  else
  {
    result = 0;
  }
  return result;
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
void __fastcall TargetSimObjectWeaponAmmoInventoryItemCondition::TargetSimObjectWeaponAmmoInventoryItemCondition(TargetSimObjectWeaponAmmoInventoryItemCondition *this)
{
  TargetSimObjectWeaponAmmoInventoryItemCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponAmmoInventoryItemCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 0i64;
}

// File Line: 12141
// RVA: 0x28FB60
bool __fastcall TargetSimObjectWeaponAmmoInventoryItemCondition::Match(TargetSimObjectWeaponAmmoInventoryItemCondition *this, ActionContext *context)
{
  TargetSimObjectWeaponAmmoInventoryItemCondition *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectProp *v7; // rbx
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  CAkScheduledItem *v10; // rax
  unsigned __int16 v11; // cx
  __int64 v12; // rdi
  UFG::SimObjectWeaponPropertiesComponent *v13; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    goto LABEL_39;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( v5
    && (v7 = *(UFG::SimObjectProp **)(56i64
                                    * *(unsigned __int8 *)((unsigned int)v2->mTargetType
                                                         + *(_QWORD *)&v5[1].m_Flags
                                                         + 8i64)
                                    + *(_QWORD *)&v5[1].m_TypeUID
                                    + 40)) != 0i64
    && (v8 = v7->m_Flags, !((v8 >> 10) & 1))
    && (!((v8 >> 14) & 1) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v7->vfptr,
                                                                                                     UFG::GunComponent::_TypeUID)) : (v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::GunComponent::_TypeUID))) : (v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::GunComponent::_TypeUID))) : (v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::GunComponent::_TypeUID))) : (v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::GunComponent::_TypeUID)),
        v9
     && ((v10 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v9),
          v11 = v7->m_Flags,
          v12 = v10[2].m_cmdPlay.fadeParams.iFadeOffset,
          !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)) : (v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v13 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v7))) : (v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)),
         v13)) )
  {
    result = v13->mWeaponTypeInfo->mFireModes[v12]->mAmmoInventoryItem == v2->mAmmoItem;
  }
  else
  {
LABEL_39:
    result = 0;
  }
  return result;
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
  TargetSimObjectBooleanCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectBooleanCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 0i64;
  v1->mIsTrue = 1;
}

// File Line: 12207
// RVA: 0x28F410
bool __fastcall TargetSimObjectBooleanCondition::Match(TargetSimObjectBooleanCondition *this, ActionContext *pContext)
{
  TargetSimObjectBooleanCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  __int64 v12; // rax
  _BOOL8 v13; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3
    && ((v5 = v3->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v6 = v7) : (v6 = v3->m_Components.p[20].m_pComponent)) : (v6 = v3->m_Components.p[20].m_pComponent),
        v6
     && *(_QWORD *)(56i64 * *(unsigned __int8 *)((unsigned int)v2->mTargetType + *(_QWORD *)&v6[1].m_Flags + 8i64)
                  + *(_QWORD *)&v6[1].m_TypeUID
                  + 40)
     && (v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer) != 0i64
     && ((v9 = v8->m_Flags, !((v9 >> 14) & 1)) ? ((v9 & 0x8000u) == 0 ? (!((v9 >> 13) & 1) ? (!((v9 >> 12) & 1) ? (v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::SimObjectPropertiesComponent::_TypeUID)) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::SimObjectPropertiesComponent::_TypeUID)),
                                                                                              v10 = v11) : (v10 = v8->m_Components.p[4].m_pComponent)) : (v10 = v8->m_Components.p[3].m_pComponent)) : (v10 = v8->m_Components.p[3].m_pComponent),
         v10)) )
  {
    v12 = *((_QWORD *)&v10[1].m_Flags + ((signed __int64)v2->mSimObjectBoolean >> 6));
    v13 = _bittest64(&v12, v2->mSimObjectBoolean & 0x3F) == (v2->mIsTrue != 0);
  }
  else
  {
    LOBYTE(v13) = 0;
  }
  return v13;
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
void __fastcall TargetSimObjectWeaponBooleanCondition::TargetSimObjectWeaponBooleanCondition(TargetSimObjectWeaponBooleanCondition *this)
{
  TargetSimObjectWeaponBooleanCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponBooleanCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 0i64;
  v1->mIsTrue = 1;
}

// File Line: 12265
// RVA: 0x28FD50
bool __fastcall TargetSimObjectWeaponBooleanCondition::Match(TargetSimObjectWeaponBooleanCondition *this, ActionContext *pContext)
{
  TargetSimObjectWeaponBooleanCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectProp *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimObjectWeaponPropertiesComponent *v9; // rax
  bool v10; // bl

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = *(UFG::SimObjectProp **)(56i64
                              * *(unsigned __int8 *)((unsigned int)v2->mTargetType + *(_QWORD *)&v5[1].m_Flags + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v7->vfptr,
                                                      UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v9 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v7);
    else
      v9 = (UFG::SimObjectWeaponPropertiesComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          (UFG::SimObjectGame *)&v7->vfptr,
                                                                          UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
  }
  else
  {
    v9 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v7->vfptr,
                                                      UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
  }
  if ( !v9 )
    return 0;
  v10 = v2->mIsTrue != 0;
  return UFG::SimObjectWeaponPropertiesComponent::GetBooleanValue(
           v9,
           (UFG::eSimObjectWeaponBooleanEnum)v2->mSimObjectWeaponBoolean) == v10;
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
void __fastcall TargetSimObjectCharacterBooleanCondition::TargetSimObjectCharacterBooleanCondition(TargetSimObjectCharacterBooleanCondition *this)
{
  TargetSimObjectCharacterBooleanCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectCharacterBooleanCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 0i64;
  v1->mIsTrue = 1;
}

// File Line: 12327
// RVA: 0x28F580
bool __fastcall TargetSimObjectCharacterBooleanCondition::Match(TargetSimObjectCharacterBooleanCondition *this, ActionContext *pContext)
{
  TargetSimObjectCharacterBooleanCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimObjectCharacterPropertiesComponent *v9; // rax
  unsigned __int64 v10; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = *(UFG::SimObjectCVBase **)(56i64
                                * *(unsigned __int8 *)((unsigned int)v2->mTargetType + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                + *(_QWORD *)&v5[1].m_TypeUID
                                + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v7);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v9 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v7->vfptr,
                                                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    else
      v9 = (UFG::SimObjectCharacterPropertiesComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v7->vfptr,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
  }
  else
  {
    v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v7);
  }
  if ( !v9 )
    return 0;
  v10 = v9->mBooleans.mBits[(signed __int64)v2->mSimObjectCharacterBoolean >> 6];
  return _bittest64((const signed __int64 *)&v10, v2->mSimObjectCharacterBoolean & 0x3F) == (v2->mIsTrue != 0);
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
void __fastcall SimObjectCharacterBooleanCondition::SimObjectCharacterBooleanCondition(SimObjectCharacterBooleanCondition *this)
{
  SimObjectCharacterBooleanCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SimObjectCharacterBooleanCondition::`vftable;
  v1->mSimObjectCharacterBoolean = 0;
  v1->mIsTrue = 1;
}

// File Line: 12378
// RVA: 0x289920
bool __fastcall SimObjectCharacterBooleanCondition::Match(SimObjectCharacterBooleanCondition *this, ActionContext *pContext)
{
  SimObjectCharacterBooleanCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax
  unsigned __int64 v6; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v3->vfptr,
                                                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    else
      v5 = (UFG::SimObjectCharacterPropertiesComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v3->vfptr,
                                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
  }
  else
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
  }
  if ( !v5 )
    return 0;
  v6 = v5->mBooleans.mBits[(signed __int64)v2->mSimObjectCharacterBoolean >> 6];
  return _bittest64((const signed __int64 *)&v6, v2->mSimObjectCharacterBoolean & 0x3F) == (v2->mIsTrue != 0);
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
void __fastcall TargetSimObjectWeaponAmmoCondition::TargetSimObjectWeaponAmmoCondition(TargetSimObjectWeaponAmmoCondition *this)
{
  TargetSimObjectWeaponAmmoCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponAmmoCondition::`vftable;
  v1->mTargetType = 0;
  *(_QWORD *)&v1->mInEqualityOperator.mValue = 1i64;
  *(_WORD *)&v1->mCheckClip = 1;
  v1->mUsePercentage = 0;
}

// File Line: 12422
// RVA: 0x28F8B0
char __fastcall TargetSimObjectWeaponAmmoCondition::Match(TargetSimObjectWeaponAmmoCondition *this, ActionContext *pContext)
{
  TargetSimObjectWeaponAmmoCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::GunComponent *v9; // rax
  CAkChainCtx *v10; // rbx
  bool v11; // r14
  bool v12; // si
  signed int v13; // eax
  signed int v14; // ebp
  CAkScheduledItem *v15; // rax
  int v16; // er8
  char v17; // bp
  int v18; // esi
  CAkScheduledItem *v19; // rax
  __int64 v20; // r15
  __int64 v21; // rcx
  CAkScheduledItem *v22; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned int)v2->mTargetType + *(_QWORD *)&v5[1].m_Flags + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v9 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID);
    else
      v9 = (UFG::GunComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v7,
                                                    UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v7->vfptr,
                                                                                     UFG::GunComponent::_TypeUID));
  }
  else
  {
    v9 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID);
  }
  v10 = (CAkChainCtx *)v9;
  if ( !v9 )
    return 0;
  v11 = 1;
  v12 = 1;
  if ( v2->mCheckClip )
  {
    v13 = UFG::GunComponent::GetClipAmmo(v9);
    v14 = v13;
    if ( v2->mUsePercentage )
    {
      v15 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v10);
      v16 = (signed int)(float)((float)((float)v14
                                      / (float)*(signed int *)(*(_QWORD *)(*(_QWORD *)&v15[2].m_cmdStop.iRelativeTime
                                                                         + 8i64
                                                                         * (unsigned int)v15[2].m_cmdPlay.fadeParams.iFadeOffset
                                                                         + 8)
                                                             + 8i64))
                              * 100.0);
    }
    else
    {
      v16 = v13;
    }
    v11 = CompareInt((UFG::InEqualityOperator)v2->mInEqualityOperator.mValue, v2->mQuantity, v16);
  }
  v17 = 1;
  if ( v2->mCheckTotal )
  {
    v18 = 0;
    if ( UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v10) )
    {
      v19 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v10);
      v20 = *(signed int *)(*(_QWORD *)(*(_QWORD *)&v19[2].m_cmdStop.iRelativeTime
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
      if ( v2->mUsePercentage )
      {
        v22 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v10);
        v18 = (signed int)(float)((float)((float)v18
                                        / (float)*(signed int *)(*(_QWORD *)(*(_QWORD *)&v22[2].m_cmdStop.iRelativeTime
                                                                           + 8i64
                                                                           * (unsigned int)v22[2].m_cmdPlay.fadeParams.iFadeOffset
                                                                           + 8)
                                                               + 12i64))
                                * 100.0);
      }
    }
    v12 = CompareInt((UFG::InEqualityOperator)v2->mInEqualityOperator.mValue, v2->mQuantity, v18);
  }
  if ( !v11 || !v12 )
    v17 = 0;
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
void __fastcall TargetWeaponAmmoCompatibleCondition::TargetWeaponAmmoCompatibleCondition(TargetWeaponAmmoCompatibleCondition *this)
{
  TargetWeaponAmmoCompatibleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetWeaponAmmoCompatibleCondition::`vftable;
  v1->mFirstTargetType = 17;
  v1->mSecondTargetType = 41;
}

// File Line: 12521
// RVA: 0x2906D0
char __fastcall TargetWeaponAmmoCompatibleCondition::Match(TargetWeaponAmmoCompatibleCondition *this, ActionContext *pContext)
{
  TargetWeaponAmmoCompatibleCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  __int64 v6; // rdx
  __int64 v7; // r8
  UFG::SimObjectGame *v8; // r9
  UFG::SimObjectGame *v9; // rbx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  unsigned __int16 v12; // dx
  CAkChainCtx *v13; // rsi
  UFG::SimComponent *v14; // rax
  CAkChainCtx *v15; // rdi
  CAkScheduledItem *v16; // rbx
  CAkScheduledItem *v17; // rax
  __int64 v18; // r11
  __int64 v19; // rbx
  __int64 v20; // rdi
  __int64 v21; // r10
  __int64 v22; // r8
  signed __int64 v23; // r11
  __int64 v24; // rcx
  signed __int64 v25; // rdx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = *(_QWORD *)&v5[1].m_Flags;
  v7 = *(_QWORD *)&v5[1].m_TypeUID;
  v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)((unsigned int)v2->mFirstTargetType + v6 + 8) + v7 + 40);
  v9 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)((unsigned int)v2->mSecondTargetType + v6 + 8) + v7 + 40);
  if ( !v8 || !v9 )
    return 0;
  v10 = v8->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
    else
      v11 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::GunComponent::_TypeUID);
  }
  else
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
  }
  v12 = v9->m_Flags;
  v13 = (CAkChainCtx *)v11;
  if ( (v12 >> 14) & 1 )
  {
    v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
  }
  else if ( (v12 & 0x8000u) == 0 )
  {
    if ( (v12 >> 13) & 1 )
      v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
    else
      v14 = (v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::GunComponent::_TypeUID);
  }
  else
  {
    v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
  }
  v15 = (CAkChainCtx *)v14;
  if ( !v13 )
    return 0;
  if ( !v14 )
    return 0;
  v16 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v13);
  v17 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v15);
  v18 = *(_QWORD *)&v16[2].m_cmdStop.iRelativeTime;
  v19 = *(unsigned int *)(v18 + 4);
  v20 = *(_QWORD *)&v17[2].m_cmdStop.iRelativeTime;
  v21 = 0i64;
  v22 = *(unsigned int *)(v20 + 4);
  if ( v19 <= 0 )
    return 0;
  v23 = v18 + 8;
  while ( 1 )
  {
    v24 = 0i64;
    if ( v22 > 0 )
      break;
LABEL_40:
    ++v21;
    v23 += 8i64;
    if ( v21 >= v19 )
      return 0;
  }
  v25 = v20 + 8;
  while ( *(_DWORD *)(*(_QWORD *)v23 + 4i64) != *(_DWORD *)(*(_QWORD *)v25 + 4i64) )
  {
    ++v24;
    v25 += 8i64;
    if ( v24 >= v22 )
      goto LABEL_40;
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
void __fastcall TargetSimObjectWeaponCanFireCondition::TargetSimObjectWeaponCanFireCondition(TargetSimObjectWeaponCanFireCondition *this)
{
  TargetSimObjectWeaponCanFireCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponCanFireCondition::`vftable;
  v1->mTargetType = 0;
}

// File Line: 12591
// RVA: 0x28FE90
bool __fastcall TargetSimObjectWeaponCanFireCondition::Match(TargetSimObjectWeaponCanFireCondition *this, ActionContext *pContext)
{
  TargetSimObjectWeaponCanFireCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::GunComponent *v11; // rbx
  bool v12; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned int)v2->mTargetType + *(_QWORD *)&v6[1].m_Flags + 8i64)
                              + *(_QWORD *)&v6[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
    else
      v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::GunComponent::_TypeUID);
  }
  else
  {
    v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
  }
  v11 = (UFG::GunComponent *)v10;
  if ( !v10 )
    return 0;
  v12 = UFG::IsAnyLocalPlayer(v4->mSimObject.m_pPointer);
  return UFG::GunComponent::CanFireWeapon(v11, v12 == 0);
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
void __fastcall TargetSimObjectWeaponIsAutomaticCondition::TargetSimObjectWeaponIsAutomaticCondition(TargetSimObjectWeaponIsAutomaticCondition *this)
{
  TargetSimObjectWeaponIsAutomaticCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponIsAutomaticCondition::`vftable;
  v1->mTargetType = 0;
}

// File Line: 12638
// RVA: 0x290110
bool __fastcall TargetSimObjectWeaponIsAutomaticCondition::Match(TargetSimObjectWeaponIsAutomaticCondition *this, ActionContext *pContext)
{
  TargetSimObjectWeaponIsAutomaticCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  CAkScheduledItem *v10; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned int)v2->mTargetType + *(_QWORD *)&v5[1].m_Flags + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID);
    else
      v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::GunComponent::_TypeUID);
  }
  else
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID);
  }
  if ( !v9 )
    return 0;
  v10 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v9);
  return *(_BYTE *)(*(_QWORD *)(*(_QWORD *)&v10[2].m_cmdStop.iRelativeTime
                              + 8i64 * (unsigned int)v10[2].m_cmdPlay.fadeParams.iFadeOffset
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
void __fastcall TargetSimObjectWeaponCanReloadCondition::TargetSimObjectWeaponCanReloadCondition(TargetSimObjectWeaponCanReloadCondition *this)
{
  TargetSimObjectWeaponCanReloadCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectWeaponCanReloadCondition::`vftable;
  v1->mTargetType = 0;
}

// File Line: 12688
// RVA: 0x28FFE0
char __fastcall TargetSimObjectWeaponCanReloadCondition::Match(TargetSimObjectWeaponCanReloadCondition *this, ActionContext *pContext)
{
  TargetSimObjectWeaponCanReloadCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::GunComponent *v9; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(UFG::SimObjectGame **)(56i64
                                     * *(unsigned __int8 *)((unsigned int)v2->mTargetType
                                                          + *(_QWORD *)&v5[1].m_Flags
                                                          + 8i64)
                                     + *(_QWORD *)&v5[1].m_TypeUID
                                     + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::GunComponent::_TypeUID)) : (v9 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID))) : (v9 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID))) : (v9 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID))) : (v9 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::GunComponent::_TypeUID)),
         v9)) )
  {
    result = UFG::GunComponent::CanReload(v9);
  }
  else
  {
    result = 0;
  }
  return result;
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
void __fastcall TargetSimObjectVehicleTypeCondition::TargetSimObjectVehicleTypeCondition(TargetSimObjectVehicleTypeCondition *this)
{
  TargetSimObjectVehicleTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectVehicleTypeCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 28i64;
}

// File Line: 12741
// RVA: 0x28F780
bool __fastcall TargetSimObjectVehicleTypeCondition::Match(TargetSimObjectVehicleTypeCondition *this, ActionContext *pContext)
{
  TargetSimObjectVehicleTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimObjectVehiclePropertiesComponent *v9; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                       * *(unsigned __int8 *)((unsigned int)v2->mTargetType
                                                            + *(_QWORD *)&v5[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v5[1].m_TypeUID
                                       + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID)) : (v9 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v9 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v7))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v7)),
         v9)) )
  {
    result = v9->m_eSimObjectVehicleType == v2->mSimObjectVehicleType;
  }
  else
  {
    result = 0;
  }
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
  SimObjectVehicleTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SimObjectVehicleTypeCondition::`vftable;
  v1->mSimObjectVehicleType = 0;
}

// File Line: 12788
// RVA: 0x289A70
bool __fastcall SimObjectVehicleTypeCondition::Match(SimObjectVehicleTypeCondition *this, ActionContext *pContext)
{
  SimObjectVehicleTypeCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectVehiclePropertiesComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID)) : (v5 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v5 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v3)),
        v5) )
  {
    result = v5->m_eSimObjectVehicleType == v2->mSimObjectVehicleType;
  }
  else
  {
    result = 0;
  }
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
void __fastcall TargetSimObjectBoatTypeCondition::TargetSimObjectBoatTypeCondition(TargetSimObjectBoatTypeCondition *this)
{
  TargetSimObjectBoatTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSimObjectBoatTypeCondition::`vftable;
  *(_QWORD *)&v1->mTargetType = 0i64;
}

// File Line: 12827
// RVA: 0x28F2D0
bool __fastcall TargetSimObjectBoatTypeCondition::Match(TargetSimObjectBoatTypeCondition *this, ActionContext *pContext)
{
  TargetSimObjectBoatTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimObjectVehiclePropertiesComponent *v9; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5
     && (v7 = *(UFG::SimObjectCVBase **)(56i64
                                       * *(unsigned __int8 *)((unsigned int)v2->mTargetType
                                                            + *(_QWORD *)&v5[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v5[1].m_TypeUID
                                       + 40)) != 0i64
     && ((v8 = v7->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID)) : (v9 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v9 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v7))) : (v9 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v7)),
         v9 && v9->m_eSimObjectVehicleType == 3)) )
  {
    result = v9->m_eSimObjectBoatType == v2->mSimObjectBoatType;
  }
  else
  {
    result = 0;
  }
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
  SimObjectBoatTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SimObjectBoatTypeCondition::`vftable;
  v1->mSimObjectBoatType = 0;
}

// File Line: 12876
// RVA: 0x289880
bool __fastcall SimObjectBoatTypeCondition::Match(SimObjectBoatTypeCondition *this, ActionContext *pContext)
{
  SimObjectBoatTypeCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectVehiclePropertiesComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID)) : (v5 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v5 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v3)),
        v5 && v5->m_eSimObjectVehicleType == 3) )
  {
    result = v5->m_eSimObjectBoatType == v2->mSimObjectBoatType;
  }
  else
  {
    result = 0;
  }
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
  NumCharactersDeadCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&NumCharactersDeadCondition::`vftable;
  v1->m_Number = 0;
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
  CharacterIsAliveCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CharacterIsAliveCondition::`vftable;
  v1->m_Name.mOffset = 1i64;
  BinString::Set(&v1->m_Name, &customWorldMapCaption);
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
  IncomingAttackPhaseCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IncomingAttackPhaseCondition::`vftable;
  v1->m_eAttackPhase.mValue = 1;
}

// File Line: 12963
// RVA: 0x282C50
bool __fastcall IncomingAttackPhaseCondition::Match(IncomingAttackPhaseCondition *this, ActionContext *pContext)
{
  IncomingAttackPhaseCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = LODWORD(v5[2].m_SafePointerList.mNode.mPrev) == v2->m_eAttackPhase.mValue;
  }
  else
  {
    result = 0;
  }
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
  IncomingAttackTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IncomingAttackTypeCondition::`vftable;
  v1->mAttackTypeID = 0;
}

// File Line: 12998
// RVA: 0x282D00
bool __fastcall IncomingAttackTypeCondition::Match(IncomingAttackTypeCondition *this, ActionContext *pContext)
{
  IncomingAttackTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = HIDWORD(v5[2].m_SafePointerList.mNode.mPrev) == v2->mAttackTypeID;
  }
  else
  {
    result = 0;
  }
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
void __fastcall IncomingAttackLocationLateralCondition::IncomingAttackLocationLateralCondition(IncomingAttackLocationLateralCondition *this)
{
  IncomingAttackLocationLateralCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IncomingAttackLocationLateralCondition::`vftable;
  v1->mAttackLocationLateralID = 0;
}

// File Line: 13032
// RVA: 0x282BA0
bool __fastcall IncomingAttackLocationLateralCondition::Match(IncomingAttackLocationLateralCondition *this, ActionContext *pContext)
{
  IncomingAttackLocationLateralCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = v2->mAttackLocationLateralID == LODWORD(v5[2].m_pSimObject);
  }
  else
  {
    result = 0;
  }
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
void __fastcall IncomingAttackLocationHorizontalCondition::IncomingAttackLocationHorizontalCondition(IncomingAttackLocationHorizontalCondition *this)
{
  IncomingAttackLocationHorizontalCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IncomingAttackLocationHorizontalCondition::`vftable;
  v1->mAttackLocationHorizontalID = 0;
}

// File Line: 13067
// RVA: 0x282AF0
bool __fastcall IncomingAttackLocationHorizontalCondition::Match(IncomingAttackLocationHorizontalCondition *this, ActionContext *pContext)
{
  IncomingAttackLocationHorizontalCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[15].m_pComponent)) : (v5 = v3->m_Components.p[15].m_pComponent),
        v5) )
  {
    result = v2->mAttackLocationHorizontalID == HIDWORD(v5[2].m_pSimObject);
  }
  else
  {
    result = 0;
  }
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
  PlayerMeleeUpgradeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerMeleeUpgradeCondition::`vftable;
  v1->mLevel = 0;
  *(_WORD *)&v1->mInEqualityOperator.mValue = 259;
}

// File Line: 13140
// RVA: 0x288F40
bool __fastcall PlayerMeleeUpgradeCondition::Match(PlayerMeleeUpgradeCondition *this, ActionContext *context)
{
  PlayerMeleeUpgradeCondition *v2; // rdi
  BOOL v3; // ebx
  UFG::GameStatTracker *v4; // rax
  int v5; // eax

  v2 = this;
  v3 = this->mMoveType.mValue == 1;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetStat(v4, (UFG::GameStat::Int32Stat)(v3 + 22));
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mLevel, v5);
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
  PlayerGunplayUpgradeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerGunplayUpgradeCondition::`vftable;
  v1->mLevel = 0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 13174
// RVA: 0x288D00
bool __fastcall PlayerGunplayUpgradeCondition::Match(PlayerGunplayUpgradeCondition *this, ActionContext *context)
{
  PlayerGunplayUpgradeCondition *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  int v4; // eax

  v2 = this;
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetStat(v3, GunplayUpgradeStage);
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mLevel, v4);
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
  PlayerCopUpgradeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerCopUpgradeCondition::`vftable;
  v1->mLevel = 0;
  *(_WORD *)&v1->mInEqualityOperator.mValue = 259;
}

// File Line: 13210
// RVA: 0x288CC0
bool __fastcall PlayerCopUpgradeCondition::Match(PlayerCopUpgradeCondition *this, ActionContext *context)
{
  PlayerCopUpgradeCondition *v2; // rdi
  BOOL v3; // ebx
  UFG::GameStatTracker *v4; // rax
  int v5; // eax

  v2 = this;
  v3 = this->mCopUpgradeType.mValue != 1;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetStat(v4, (UFG::GameStat::Int32Stat)(v3 + 27));
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mLevel, v5);
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
  PlayerTriadUpgradeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerTriadUpgradeCondition::`vftable;
  v1->mLevel = 0;
  *(_WORD *)&v1->mInEqualityOperator.mValue = 259;
}

// File Line: 13248
// RVA: 0x288F80
bool __fastcall PlayerTriadUpgradeCondition::Match(PlayerTriadUpgradeCondition *this, ActionContext *context)
{
  PlayerTriadUpgradeCondition *v2; // rdi
  BOOL v3; // ebx
  UFG::GameStatTracker *v4; // rax
  int v5; // eax

  v2 = this;
  v3 = this->mMoveType.mValue == 1;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetStat(v4, (UFG::GameStat::Int32Stat)(v3 + 24));
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mLevel, v5);
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
  StruggleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&StruggleCondition::`vftable;
  v1->mLevel = 1.0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 13285
// RVA: 0x28B780
char __fastcall StruggleCondition::Match(StruggleCondition *this, ActionContext *context)
{
  StruggleCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectSignalMemoryComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectSignalMemoryComponent::_TypeUID)),
        v5) )
  {
    result = CompareFloat(
               (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
               v2->mLevel,
               *(float *)&v5[1].m_TypeUID);
  }
  else
  {
    result = 0;
  }
  return result;
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
  InputSignalCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InputSignalCondition::`vftable;
  v1->mValue = 1.0;
  *(_WORD *)&v1->mInEqualityOperator.mValue = 3;
  v1->mTargetType.mValue = 1;
}

// File Line: 13331
// RVA: 0x282DB0
char __fastcall InputSignalCondition::Match(InputSignalCondition *this, ActionContext *context)
{
  FloatInputSignal v2; // ebx
  InputSignalCondition *v3; // rdi
  UFG::SimObject *v4; // rax
  float v5; // xmm0_4
  UFG::qVector3 v7; // [rsp+30h] [rbp-18h]

  v2 = (unsigned __int8)this->mFloatInputSignal.mValue;
  v3 = this;
  v4 = UFG::getTarget(context->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)(unsigned __int8)this->mTargetType.mValue);
  v7 = UFG::qVector3::msZero;
  v5 = getSignalValue(v4, v2, 0.0, 6.2831855, (__int64)v3, &v7);
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v3->mInEqualityOperator.mValue, v3->mValue, v5);
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
  UFG::SimObjectGame *v2; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rdi
  ActionContext *v4; // rsi
  UFG::SimComponent *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // r8
  UFG::SimComponent *v9; // rax
  unsigned __int16 v10; // cx
  UFG::SimObject *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::InterestPoint *v13; // rbx
  UFG::SimObjectGame *v15; // rcx
  unsigned __int16 v16; // dx
  UFG::SimComponent *v17; // rax
  UFG::SimObjectCVBase *v18; // rcx
  unsigned __int16 v19; // dx
  UFG::AICharacterControllerBaseComponent *v20; // rax
  unsigned int v21; // edx
  bool v22; // zf
  unsigned __int64 v23; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = pContext;
  if ( v2 )
  {
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v2->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v7;
    }
    else
    {
      v5 = v2->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = v4->mSimObject.m_pPointer;
  if ( v8 )
  {
    v10 = v8->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v9 = v8->m_Components.p[43].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v9 = v8->m_Components.p[12].m_pComponent;
      }
      else if ( (v10 >> 12) & 1 )
      {
        v9 = 0i64;
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType(v4->mSimObject.m_pPointer, UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    else
    {
      v9 = 0i64;
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( v5 )
  {
    if ( v9 )
    {
      v11 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 34i64)
                               + *(_QWORD *)&v5[1].m_TypeUID
                               + 40);
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 >> 14) & 1 )
        {
          v13 = (UFG::InterestPoint *)v11->m_Components.p[25].m_pComponent;
        }
        else if ( (v12 & 0x8000u) == 0 )
        {
          if ( (v12 >> 13) & 1 )
            v13 = (UFG::InterestPoint *)v11->m_Components.p[10].m_pComponent;
          else
            v13 = (UFG::InterestPoint *)((v12 >> 12) & 1 ? v11->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                                   v11,
                                                                                                   UFG::InterestPoint::_TypeUID));
        }
        else
        {
          v13 = (UFG::InterestPoint *)v11->m_Components.p[25].m_pComponent;
        }
        if ( v13 && !UFG::InterestPoint::IsReservationMatch(v13, 0x10u, ReserveReason_normal) )
        {
          if ( UFG::InterestPoint::IsAutoInteractable(v13) )
            return 1;
          v15 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
          if ( v15 )
          {
            v16 = v15->m_Flags;
            if ( (v16 >> 14) & 1 )
            {
              v17 = v15->m_Components.p[22].m_pComponent;
            }
            else if ( (v16 & 0x8000u) == 0 )
            {
              if ( (v16 >> 13) & 1 )
                v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::AIEntityComponent::_TypeUID);
              else
                v17 = (v16 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::AIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::AIEntityComponent::_TypeUID);
            }
            else
            {
              v17 = v15->m_Components.p[22].m_pComponent;
            }
            if ( v17 )
            {
              v18 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
              if ( !v18 )
              {
LABEL_61:
                v23 = v3->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_POI_Use.m_EnumValue >> 6];
                return _bittest64((const signed __int64 *)&v23, gActionRequest_POI_Use.m_EnumValue & 0x3F);
              }
              v19 = v18->m_Flags;
              if ( (v19 >> 14) & 1 || (v19 & 0x8000u) != 0 )
              {
                v20 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v18);
              }
              else
              {
                if ( (v19 >> 13) & 1 )
                {
                  v21 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                }
                else
                {
                  v22 = ((v19 >> 12) & 1) == 0;
                  v21 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                  if ( v22 )
                  {
                    v20 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       (UFG::SimObject *)&v18->vfptr,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
                    goto LABEL_60;
                  }
                }
                v20 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v18->vfptr,
                                                                   v21);
              }
LABEL_60:
              v3 = v20;
              goto LABEL_61;
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
bool __fastcall POIWeatherFilterOnWithIsRainingCondition::Match(POIWeatherFilterOnWithIsRainingCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::InterestPoint *v8; // rbx

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
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
  if ( !v4 )
    return 0;
  v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 34i64)
                          + *(_QWORD *)&v4[1].m_TypeUID
                          + 40);
  if ( !v6 )
    return 0;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
    {
      v8 = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent;
    }
    else if ( (v7 >> 12) & 1 )
    {
      v8 = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent;
    }
    else
    {
      v8 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID);
    }
  }
  else
  {
    v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
  }
  return v8 && UFG::InterestPoint::GetWeatherFilterOn(v8) && UFG::InterestPoint::GetWeatherFilterIsRaining(v8);
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::InterestPoint *v8; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
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
  if ( !v4 )
    return 0;
  v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 34i64)
                          + *(_QWORD *)&v4[1].m_TypeUID
                          + 40);
  if ( !v6 )
    return 0;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
    {
      v8 = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent;
    }
    else if ( (v7 >> 12) & 1 )
    {
      v8 = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent;
    }
    else
    {
      v8 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID);
    }
  }
  else
  {
    v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent;
  }
  return v8 && UFG::InterestPoint::GetIgnoreStimuli(v8);
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rax
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::InterestPoint *v8; // rax
  UFG::SimObjectGame *v9; // rax
  unsigned __int16 v10; // dx
  UFG::InventoryItemComponent *v11; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v2 )
    goto LABEL_37;
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
  if ( v4
    && (v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 34i64)
                                + *(_QWORD *)&v4[1].m_TypeUID
                                + 40)) != 0i64
    && ((v7 = v6->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[3].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[10].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent)) : (v8 = (UFG::InterestPoint *)v6->m_Components.p[25].m_pComponent),
        v8
     && (v9 = (UFG::SimObjectGame *)UFG::InterestPoint::GetParentObject(v8)) != 0i64
     && (v10 = v9->m_Flags, !((v10 >> 14) & 1))
     && (v10 & 0x8000u) == 0
     && (!((v10 >> 13) & 1) ? (!((v10 >> 12) & 1) ? (v11 = (UFG::InventoryItemComponent *)UFG::SimObject::GetComponentOfType(
                                                                                            (UFG::SimObject *)&v9->vfptr,
                                                                                            UFG::InventoryItemComponent::_TypeUID)) : (v11 = (UFG::InventoryItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::InventoryItemComponent::_TypeUID))) : (v11 = (UFG::InventoryItemComponent *)v9->m_Components.p[11].m_pComponent),
         v11)) )
  {
    result = UFG::InventoryItemComponent::GetOwnerSimObject(v11) == 0i64;
  }
  else
  {
LABEL_37:
    result = 0;
  }
  return result;
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
  UFG::SimObject *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx

  v2 = pContext->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = v2->m_Components.p[43].m_pComponent;
  }
  else
  {
    if ( (v3 & 0x8000u) != 0 )
      return 0;
    if ( (v3 >> 13) & 1 )
    {
      v4 = v2->m_Components.p[12].m_pComponent;
    }
    else
    {
      if ( (v3 >> 12) & 1 )
        return 0;
      v4 = UFG::SimObject::GetComponentOfType(v2, UFG::InterestPointUserComponent::_TypeUID);
    }
  }
  if ( v4 )
  {
    if ( v4[8].m_TypeUID != 3 )
    {
      v5 = v4[8].m_SafePointerList.mNode.mNext;
      if ( v5 )
      {
        if ( BYTE5(v5[26].mNext) )
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
  PlayerHeatLevelCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerHeatLevelCondition::`vftable;
  *(_WORD *)&v1->mHeatLevel.mValue = 0;
}

// File Line: 13567
// RVA: 0x288D30
bool __fastcall PlayerHeatLevelCondition::Match(PlayerHeatLevelCondition *this, ActionContext *context)
{
  PlayerHeatLevelCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::CopSystem *v6; // rax
  int v7; // eax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[7].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = v3->m_Components.p[6].m_pComponent;
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
  }
  else
  {
    v5 = v3->m_Components.p[7].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = UFG::CopSystem::Instance();
  v7 = ((__int64 (__fastcall *)(UFG::CopSystem *))v6->vfptr[89].__vecDelDtor)(v6);
  return CompareInt(
           (UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue,
           (unsigned __int8)v2->mHeatLevel.mValue,
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
  PlayerHeatLevelTimerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerHeatLevelTimerCondition::`vftable;
  v1->mTimer = 0.0;
  v1->mInEqualityOperator.mValue = 3;
}

// File Line: 13603
// RVA: 0x288DE0
char __fastcall PlayerHeatLevelTimerCondition::Match(PlayerHeatLevelTimerCondition *this, ActionContext *context)
{
  UFG::InEqualityOperator v2; // ebx
  PlayerHeatLevelTimerCondition *v3; // rdi
  UFG::CopSystem *v4; // rax
  float v5; // xmm0_4

  v2 = (unsigned __int8)this->mInEqualityOperator.mValue;
  v3 = this;
  v4 = UFG::CopSystem::Instance();
  v5 = UFG::CopSystem::GetCurrentHeatLevelElapsedTime(v4);
  return CompareFloat(v2, v3->mTimer, v5);
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
  HasAIAttackerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HasAIAttackerCondition::`vftable;
  v1->mDistance = 10.0;
}

// File Line: 13632
// RVA: 0x281E90
bool __fastcall HasAIAttackerCondition::Match(HasAIAttackerCondition *this, ActionContext *context)
{
  HasAIAttackerCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::FormationManagerComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::FormationManagerComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::FormationManagerComponent::_TypeUID)) : (v5 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FormationManagerComponent::_TypeUID))) : (v5 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FormationManagerComponent::_TypeUID))) : (v5 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FormationManagerComponent::_TypeUID))) : (v5 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FormationManagerComponent::_TypeUID)),
        v5) )
  {
    result = (signed int)UFG::FormationManagerComponent::NumAttackersCloserThan(v5, v2->mDistance, 1) > 0;
  }
  else
  {
    result = 0;
  }
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
  NumAIAttackersCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&NumAIAttackersCondition::`vftable;
  v1->m_InEqualityOperator.mValue = 1;
  v1->mDistance = 10.0;
  v1->m_NumAttackers = 1;
}

// File Line: 13672
// RVA: 0x285E30
bool __fastcall NumAIAttackersCondition::Match(NumAIAttackersCondition *this, ActionContext *context)
{
  NumAIAttackersCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::FormationManagerComponent *v5; // rax
  int v6; // eax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v3,
                                             UFG::FormationManagerComponent::_TypeUID);
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v3,
                                               UFG::FormationManagerComponent::_TypeUID);
    else
      v5 = (UFG::FormationManagerComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v3,
                                                                 UFG::FormationManagerComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::FormationManagerComponent::_TypeUID));
  }
  else
  {
    v5 = (UFG::FormationManagerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v3,
                                             UFG::FormationManagerComponent::_TypeUID);
  }
  if ( !v5 )
    return 0;
  v6 = UFG::FormationManagerComponent::NumAttackersCloserThan(v5, v2->mDistance, v2->m_NumAttackers);
  return CompareInt((UFG::InEqualityOperator)v2->m_InEqualityOperator.mValue, v2->m_NumAttackers, v6);
}

// File Line: 13712
// RVA: 0x1491A80
__int64 dynamic_initializer_for__combatTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&combatTypeEnum, gCombatTypeStringList, 2, 0i64);
  return atexit(dynamic_atexit_destructor_for__combatTypeEnum__);
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
  PlayerIsInCombatCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInCombatCondition::`vftable;
  v1->m_CombatType.mValue = 0;
}

// File Line: 13725
// RVA: 0x288E20
bool __fastcall PlayerIsInCombatCondition::Match(PlayerIsInCombatCondition *this, ActionContext *context)
{
  int v2; // eax

  v2 = this->m_CombatType.mValue;
  if ( !v2 )
    return UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0);
  if ( v2 == 1 )
    return UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0);
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
  PlayerIsInCombatConditionTU *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInCombatConditionTU::`vftable;
  v1->m_CombatType.mValue = 0;
  v1->m_WithCharacterType.mValue = 0;
}

// File Line: 13770
// RVA: 0x288E50
bool __fastcall PlayerIsInCombatConditionTU::Match(PlayerIsInCombatConditionTU *this, ActionContext *context)
{
  int v2; // eax

  v2 = this->m_CombatType.mValue;
  if ( !v2 )
    return UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(
             UFG::LocalPlayerIsInCombatManager::s_pInstance,
             (UFG::eCharacterTypeEnum)(unsigned __int8)this->m_WithCharacterType.mValue);
  if ( v2 == 1 )
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
  IsTiredCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsTiredCondition::`vftable;
}

// File Line: 13811
// RVA: 0x285260
bool __fastcall IsTiredCondition::Match(IsTiredCondition *this, ActionContext *context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimObjectCharacterPropertiesComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) : (v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2)),
        v4) )
  {
    result = v4->mIsTired;
  }
  else
  {
    result = 0;
  }
  return result;
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
void __fastcall PlayerIsInCombatWithNumEnemiesCondition::PlayerIsInCombatWithNumEnemiesCondition(PlayerIsInCombatWithNumEnemiesCondition *this)
{
  PlayerIsInCombatWithNumEnemiesCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInCombatWithNumEnemiesCondition::`vftable;
  v1->mCombatType.mValue = 0;
  v1->mInEqualityOperator.mValue = 3;
  v1->mCount = 0;
}

// File Line: 13849
// RVA: 0x288E80
char __fastcall PlayerIsInCombatWithNumEnemiesCondition::Match(PlayerIsInCombatWithNumEnemiesCondition *this, ActionContext *context)
{
  int v2; // eax
  UFG::LocalPlayerIsInCombatManager *v3; // rdi
  PlayerIsInCombatWithNumEnemiesCondition *v4; // rsi
  UFG::InEqualityOperator v5; // ebx
  int v6; // eax

  v2 = this->mCombatType.mValue;
  v3 = UFG::LocalPlayerIsInCombatManager::s_pInstance;
  v4 = this;
  if ( v2 )
  {
    if ( v2 != 1 || !UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0) )
      return 0;
    v5 = (unsigned __int8)v4->mInEqualityOperator.mValue;
    v6 = UFG::LocalPlayerIsInCombatManager::GetNumAttackersAny(v3, 0);
  }
  else
  {
    if ( !UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0) )
      return 0;
    v5 = (unsigned __int8)v4->mInEqualityOperator.mValue;
    v6 = UFG::LocalPlayerIsInCombatManager::GetNumAttackersMelee(v3, 0);
  }
  if ( CompareInt(v5, v4->mCount, v6) )
    return 1;
  return 0;
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
  CharacterStatIntCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) : (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)),
        v5) )
  {
    result = CompareInt(
               (UFG::InEqualityOperator)(unsigned __int8)v2->m_eInEqualityOperator.mValue,
               v2->m_Value,
               (signed int)v5->m_CharacterStats[v2->m_StatType].m_fStat);
  }
  else
  {
    result = 0;
  }
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
  UFG::SimObjectCharacter *v2; // rcx
  UFG::ActorAudioComponent *v3; // rax
  unsigned __int16 v4; // dx

  v2 = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v2->vfptr,
                                           UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::ActorAudioComponent::_TypeUID);
    }
  }
  else
  {
    v3 = 0i64;
  }
  return v3->m_isSpeakingCnt > 0 && v3->m_controller.m_pEvent;
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
  CoverIsInCoverZoneCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CoverIsInCoverZoneCondition::`vftable;
}

// File Line: 13972
// RVA: 0x280C10
bool __fastcall CoverIsInCoverZoneCondition::Match(CoverIsInCoverZoneCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AICoverComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
      else
        v4 = (UFG::AICoverComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v2,
                                                          UFG::AICoverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v2->vfptr,
                                                                                               UFG::AICoverComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
    }
    if ( v4 && v4->m_pSyncCoverPosition )
      result = 1;
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
void __fastcall CoverPositionsEquivalentCondition::CoverPositionsEquivalentCondition(CoverPositionsEquivalentCondition *this)
{
  CoverPositionsEquivalentCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CoverPositionsEquivalentCondition::`vftable;
  *(_WORD *)&v1->m_eCoverComponentObjectA.mValue = 769;
}

// File Line: 14012
// RVA: 0x280CA0
bool __fastcall CoverPositionsEquivalentCondition::Match(CoverPositionsEquivalentCondition *this, ActionContext *pContext)
{
  CoverPositionsEquivalentCondition *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::AICoverComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::CoverObjectBase *v7; // rdi
  UFG::CoverObjectBase *v8; // rbx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    v4 = (UFG::AICoverComponent *)v6;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = UFG::AICoverComponent::GetCoverObjectFromEnum(
         v4,
         (UFG::eCoverComponentObjectEnum)(unsigned __int8)v2->m_eCoverComponentObjectA.mValue);
  v8 = UFG::AICoverComponent::GetCoverObjectFromEnum(
         v4,
         (UFG::eCoverComponentObjectEnum)(unsigned __int8)v2->m_eCoverComponentObjectB.mValue);
  if ( !v7 || !v7->vfptr->IsPosition(v7) )
    v7 = 0i64;
  if ( !v8 || !v8->vfptr->IsPosition(v8) )
    v8 = 0i64;
  return v7 && v8 && v7->vfptr->operator==(v7, v8);
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
  CoverProbeForCoverZoneCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CoverProbeForCoverZoneCondition::`vftable;
  v1->m_MaxProbeDistance = 3.0;
  v1->m_BufferRegionSize = 0.30000001;
  v1->m_UseOffset = 0;
  *(_QWORD *)&v1->m_OffsetX = 0i64;
  *(_DWORD *)&v1->m_LatchBestCover = 16843009;
  *(_WORD *)&v1->m_Line = 257;
  v1->m_Low = 1;
}

// File Line: 14081
// RVA: 0x280DB0
char __fastcall CoverProbeForCoverZoneCondition::Match(CoverProbeForCoverZoneCondition *this, ActionContext *pContext)
{
  CoverProbeForCoverZoneCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::TransformNodeComponent *v4; // rsi
  ActionContext *v5; // r15
  UFG::PlayerCoverComponent *v6; // rdi
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm0_4
  bool bLow; // ST50_1
  bool bHigh; // ST48_1
  bool bLine; // ST40_1
  bool bRightCorner; // ST38_1
  bool bLeftCorner; // ST30_1
  bool bStoreProbeCoverObject; // ST28_1
  char result; // al
  UFG::SimObject *v18; // rax
  UFG::CoverPosition *v19; // r14
  _DWORD *v20; // rax
  int v21; // xmm12_4
  int v22; // xmm13_4
  int v23; // xmm14_4
  __int64 v24; // r8
  __int64 v25; // r9
  float v26; // xmm9_4
  float v27; // xmm10_4
  float v28; // xmm11_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm10_4
  float v32; // xmm11_4
  float v33; // xmm9_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm7_4
  float v37; // xmm2_4
  float v38; // xmm6_4
  float v39; // xmm8_4
  float v40; // xmm15_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  __int128 v45; // xmm1
  __int128 v46; // xmm0
  __int128 v47; // xmm1
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v48; // rax
  __int64 bLatch; // [rsp+20h] [rbp-E0h]
  float v50; // [rsp+60h] [rbp-A0h]
  float v51; // [rsp+64h] [rbp-9Ch]
  float v52; // [rsp+68h] [rbp-98h]
  char v53; // [rsp+70h] [rbp-90h]
  UFG::qVector4 v54; // [rsp+80h] [rbp-80h]
  UFG::qVector4 v55; // [rsp+90h] [rbp-70h]
  __int128 v56; // [rsp+A0h] [rbp-60h]
  __int128 v57; // [rsp+B0h] [rbp-50h]
  __int128 v58; // [rsp+C0h] [rbp-40h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = pContext;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    v6 = (UFG::PlayerCoverComponent *)v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = v2->m_OffsetX;
  v10 = v2->m_OffsetY;
  v54.z = 0.0;
  v54.w = 1.0;
  v54.x = v10;
  LODWORD(v54.y) = LODWORD(v9) ^ _xmm[0];
  if ( v6->m_TypeUID == UFG::PlayerCoverComponent::_TypeUID )
  {
    bLow = v2->m_Low != 0;
    bHigh = v2->m_High != 0;
    bLine = v2->m_Line != 0;
    bRightCorner = v2->m_RightCorner != 0;
    bLeftCorner = v2->m_LeftCorner != 0;
    bStoreProbeCoverObject = v2->m_StoreProbeCoverObject != 0;
    LOBYTE(bLatch) = v2->m_LatchBestCover != 0;
    result = UFG::PlayerCoverComponent::ProbeForPlayerCover(
               v6,
               0.0,
               v2->m_MaxProbeDistance,
               v2->m_BufferRegionSize,
               bLatch);
  }
  else
  {
    if ( !v2->m_UseOffset )
      goto LABEL_33;
    v18 = v5->mSimObject.m_pPointer;
    v19 = v6->m_pCurrentCoverPosition;
    if ( v18 )
      v4 = v18->m_pTransformNodeComponent;
    if ( v19 && (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v19->vfptr->__vecDelDtor + 2))(v19) )
    {
      v20 = (_DWORD *)v19->vfptr->GetWallNormal((UFG::CoverObjectBase *)&v19->vfptr, (UFG::qVector3 *)&v53);
      v21 = *v20 ^ _xmm[0];
      v22 = v20[1] ^ _xmm[0];
      v23 = v20[2] ^ _xmm[0];
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v26 = (float)(*(float *)&v23 * UFG::qVector3::msDirUp.y) - (float)(*(float *)&v22 * UFG::qVector3::msDirUp.z);
      v27 = (float)(*(float *)&v21 * UFG::qVector3::msDirUp.z) - (float)(*(float *)&v23 * UFG::qVector3::msDirUp.x);
      v28 = (float)(*(float *)&v22 * UFG::qVector3::msDirUp.x) - (float)(*(float *)&v21 * UFG::qVector3::msDirUp.y);
      v29 = (float)((float)(v27 * v27) + (float)(v26 * v26)) + (float)(v28 * v28);
      v30 = v29 == 0.0 ? 0.0 : 1.0 / fsqrt(v29);
      v31 = v27 * v30;
      v32 = v28 * v30;
      v33 = v26 * v30;
      v34 = (float)(v32 * *(float *)&v22) - (float)(v31 * *(float *)&v23);
      v35 = (float)(v33 * *(float *)&v23) - (float)(v32 * *(float *)&v21);
      v36 = (float)(v31 * *(float *)&v21) - (float)(v33 * *(float *)&v22);
      v37 = (float)((float)(v35 * v35) + (float)(v34 * v34)) + (float)(v36 * v36);
      v38 = v37 == 0.0 ? 0.0 : 1.0 / fsqrt(v37);
      v39 = v4->mWorldTransform.v3.y;
      v40 = v4->mWorldTransform.v3.z;
      v41 = v34 * v38;
      v42 = v35 * v38;
      v43 = v36 * v38;
      v44 = v4->mWorldTransform.v3.x;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v45 = (__int128)v4->mWorldTransform.v1;
      v55 = v4->mWorldTransform.v0;
      v46 = (__int128)v4->mWorldTransform.v2;
      v23 = SLODWORD(v55.z);
      v22 = SLODWORD(v55.y);
      v21 = SLODWORD(v55.x);
      v56 = v45;
      v47 = (__int128)v4->mWorldTransform.v3;
      v32 = *((float *)&v56 + 2);
      v31 = *((float *)&v56 + 1);
      v33 = *(float *)&v56;
      v57 = v46;
      v43 = *((float *)&v46 + 2);
      v42 = *((float *)&v57 + 1);
      v41 = *(float *)&v46;
      v58 = v47;
      v40 = *((float *)&v47 + 2);
      v39 = *((float *)&v58 + 1);
      v44 = *(float *)&v47;
    }
    v48 = v6->vfptr;
    LOBYTE(v25) = v2->m_StoreProbeCoverObject != 0;
    LOBYTE(v24) = v2->m_LatchBestCover != 0;
    v50 = (float)((float)((float)(v33 * v54.y) + (float)(*(float *)&v21 * v54.x)) + (float)(v41 * v54.z))
        + (float)(v44 * v54.w);
    v51 = (float)((float)((float)(v31 * v54.y) + (float)(*(float *)&v22 * v54.x)) + (float)(v42 * v54.z))
        + (float)(v39 * v54.w);
    v52 = (float)((float)((float)(v32 * v54.y) + (float)(*(float *)&v23 * v54.x)) + (float)(v43 * v54.z))
        + (float)(v40 * v54.w);
    if ( ((unsigned __int8 (__fastcall *)(UFG::PlayerCoverComponent *, float *, __int64, __int64))v48[17].__vecDelDtor)(
           v6,
           &v50,
           v24,
           v25) )
    {
      result = 1;
    }
    else
    {
LABEL_33:
      result = 0;
    }
  }
  return result;
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
  CoverDirectionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CoverDirectionCondition::`vftable;
  *(_DWORD *)&v1->m_eCoverComponentObject.mValue = 65537;
  v1->m_CheckFacingDirection = 0;
  v1->m_Direction = 0.0;
  v1->m_AngleRange = 1.5707964;
}

// File Line: 14175
// RVA: 0x280760
char __fastcall CoverDirectionCondition::Match(CoverDirectionCondition *this, ActionContext *pContext)
{
  CoverDirectionCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  UFG::TransformNodeComponent *v4; // rsi
  ActionContext *v5; // rbp
  UFG::AICoverComponent *v6; // rbx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::CoverObjectBase *v9; // rax
  UFG::CoverPosition *v10; // r14
  bool v11; // bl
  char result; // al
  UFG::SimObjectGame *v13; // rcx
  UFG::AimingBaseComponent *v14; // rax
  unsigned __int16 v15; // dx
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  float v18; // xmm4_4
  UFG::SimObjectCVBase *v19; // rcx
  UFG::AICharacterControllerBaseComponent *v20; // rax
  unsigned __int16 v21; // dx
  UFG::BaseCameraComponent *v22; // rax
  _DWORD *v23; // rax
  int v24; // xmm1_4
  int v25; // xmm0_4
  UFG::SimObject *v26; // rax
  UFG::qVector3 vAimDirection; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = pContext;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    v6 = (UFG::AICoverComponent *)v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = UFG::AICoverComponent::GetCoverObjectFromEnum(
         v6,
         (UFG::eCoverComponentObjectEnum)(unsigned __int8)v2->m_eCoverComponentObject.mValue);
  v10 = (UFG::CoverPosition *)v9;
  if ( !v9 || !v9->vfptr->IsPosition(v9) )
    return 0;
  v11 = UFG::IsAnyLocalPlayer(v6->m_pSimObject);
  result = 1;
  if ( !v2->m_CheckAimIntention && (v11 || !v2->m_CheckCameraDirection) )
    goto LABEL_61;
  v13 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v13 )
  {
    v15 = v13->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v14 = (UFG::AimingBaseComponent *)v13->m_Components.p[47].m_pComponent;
    }
    else if ( (v15 & 0x8000u) == 0 )
    {
      if ( (v15 >> 13) & 1 )
        v14 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v13,
                                            UFG::AimingBaseComponent::_TypeUID);
      else
        v14 = (UFG::AimingBaseComponent *)((v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v13,
                                                               UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::AimingBaseComponent::_TypeUID));
    }
    else
    {
      v14 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v13,
                                          UFG::AimingBaseComponent::_TypeUID);
    }
  }
  else
  {
    v14 = 0i64;
  }
  UFG::AimingBaseComponent::GetAimDirection(v14, &vAimDirection, 0i64);
  v16 = (__m128)LODWORD(vAimDirection.x);
  v17 = v16;
  v17.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(vAimDirection.y * vAimDirection.y);
  LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v17);
  if ( v18 <= 0.001 )
  {
    vAimDirection = UFG::qVector3::msAxisX;
  }
  else
  {
    vAimDirection.z = (float)(1.0 / v18) * 0.0;
    vAimDirection.x = vAimDirection.x * (float)(1.0 / v18);
    vAimDirection.y = vAimDirection.y * (float)(1.0 / v18);
  }
  result = CoverDirectionCondition::CheckDirection(v2, v10, &vAimDirection);
  if ( result )
  {
LABEL_61:
    if ( v2->m_CheckMotionIntention )
    {
      v19 = (UFG::SimObjectCVBase *)v5->mSimObject.m_pPointer;
      if ( v19 )
      {
        v21 = v19->m_Flags;
        if ( (v21 >> 14) & 1 )
        {
          v20 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v19);
        }
        else if ( (v21 & 0x8000u) == 0 )
        {
          if ( (v21 >> 13) & 1 )
          {
            v20 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v19->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
          else if ( (v21 >> 12) & 1 )
          {
            v20 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v19->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
          else
          {
            v20 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v19->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
        }
        else
        {
          v20 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v19);
        }
      }
      else
      {
        v20 = 0i64;
      }
      result = CoverDirectionCondition::CheckDirection(v2, v10, &v20->m_Intention.mMotionIntentionDirection);
    }
    if ( result )
    {
      if ( v2->m_CheckCameraDirection && v11 )
      {
        v22 = UFG::Director::Get()->mCurrentCamera;
        if ( v22 )
          v23 = (_DWORD *)&v22->mCamera.mFOVOffset;
        else
          v23 = 0i64;
        v24 = v23[42] ^ _xmm[0];
        LODWORD(vAimDirection.x) = v23[40] ^ _xmm[0];
        v25 = v23[41];
        LODWORD(vAimDirection.z) = v24;
        LODWORD(vAimDirection.y) = v25 ^ _xmm[0];
        result = CoverDirectionCondition::CheckDirection(v2, v10, &vAimDirection);
      }
      if ( result && v2->m_CheckFacingDirection )
      {
        v26 = v5->mSimObject.m_pPointer;
        if ( v26 )
          v4 = v26->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v4);
        result = CoverDirectionCondition::CheckDirection(v2, v10, (UFG::qVector3 *)&v4->mWorldTransform);
      }
    }
  }
  return result;
}

// File Line: 14253
// RVA: 0x27AD70
char __fastcall CoverDirectionCondition::CheckDirection(CoverDirectionCondition *this, UFG::CoverPosition *pPosition, UFG::qVector3 *vDirection)
{
  CoverDirectionCondition *v3; // rsi
  UFG::ParkourHandle *v4; // rcx
  UFG::qVector3 *v5; // rdi
  UFG::CoverPosition *v6; // rbx
  char result; // al
  UFG::CoverCorner *v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::CoverCorner *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  UFG::qVector3 out; // [rsp+20h] [rbp-18h]

  v3 = this;
  v4 = pPosition->m_pParkourHandle.m_pPointer;
  v5 = vDirection;
  v6 = pPosition;
  if ( v4 )
  {
    UFG::ParkourHandle::GetNormal(v4, &out);
    if ( !CoverDirectionCondition::CheckDirection(v3, &out, v5) )
      goto LABEL_11;
  }
  v8 = UFG::CoverCornerHandle::Get(&v6->m_LeftCorner);
  if ( v8 )
  {
    v9 = v8->m_vWallNormal.x;
    v10 = v8->m_vWallNormal.y;
    out.z = 0.0;
    out.x = v9;
    out.y = v10;
    if ( !CoverDirectionCondition::CheckDirection(v3, &out, v5) )
      goto LABEL_11;
  }
  v11 = UFG::CoverCornerHandle::Get(&v6->m_RightCorner);
  if ( v11
    && (v12 = v11->m_vWallNormal.x,
        v13 = v11->m_vWallNormal.y,
        out.z = 0.0,
        out.x = v12,
        out.y = v13,
        !CoverDirectionCondition::CheckDirection(v3, &out, v5)) )
  {
LABEL_11:
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

// File Line: 14289
// RVA: 0x27AC90
bool __fastcall CoverDirectionCondition::CheckDirection(CoverDirectionCondition *this, UFG::qVector3 *vNormal, UFG::qVector3 *vDirection)
{
  CoverDirectionCondition *v3; // rdi
  UFG::qVector3 *v4; // rbx
  float v5; // xmm1_4
  int v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v12; // [rsp+20h] [rbp-28h]
  float v13; // [rsp+24h] [rbp-24h]
  float v14; // [rsp+28h] [rbp-20h]
  int v15; // [rsp+30h] [rbp-18h]
  int v16; // [rsp+34h] [rbp-14h]
  int v17; // [rsp+38h] [rbp-10h]

  v3 = this;
  v4 = vDirection;
  v13 = UFG::qVector3::msZero.y;
  v5 = vNormal->x;
  v12 = UFG::qVector3::msZero.x;
  v15 = LODWORD(v5) ^ _xmm[0];
  v6 = LODWORD(vNormal->z) ^ _xmm[0];
  v14 = UFG::qVector3::msZero.z;
  v7 = vNormal->y;
  v17 = v6;
  v8 = this->m_Direction;
  v16 = LODWORD(v7) ^ _xmm[0];
  UFG::qRotateVectorZ((UFG::qVector3 *)&v12, (UFG::qVector3 *)&v15, v8);
  v9 = (float)((float)(v13 * v4->y) + (float)(v12 * v4->x)) + (float)(v14 * v4->z);
  if ( v9 <= -1.0 )
  {
    v9 = FLOAT_N1_0;
  }
  else
  {
    v10 = *(float *)&FLOAT_1_0;
    if ( v9 >= 1.0 )
      return acosf(v10) <= v3->m_AngleRange;
  }
  v10 = v9;
  return acosf(v10) <= v3->m_AngleRange;
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
  CoverHeightCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CoverHeightCondition::`vftable;
  *(_WORD *)&v1->m_eCoverComponentObject.mValue = 257;
  v1->m_Low = 0;
}

// File Line: 14339
// RVA: 0x280AB0
UFG::CoverObjectBase *__usercall CoverHeightCondition::Match@<rax>(CoverHeightCondition *this@<rcx>, ActionContext *pContext@<rdx>, float a3@<xmm0>)
{
  CoverHeightCondition *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int8 v5; // di
  UFG::AICoverComponent *v6; // rax
  unsigned __int16 v7; // dx
  UFG::CoverObjectBase *result; // rax
  UFG::CoverObjectBase *v9; // rbx
  bool v10; // bp
  bool v11; // al

  v3 = this;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v5 = 0;
  if ( v4 )
  {
    v7 = v4->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v6 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v6 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v4->vfptr,
                                        UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AICoverComponent::_TypeUID);
    }
  }
  else
  {
    v6 = 0i64;
  }
  result = UFG::AICoverComponent::GetCoverObjectFromEnum(
             v6,
             (UFG::eCoverComponentObjectEnum)(unsigned __int8)v3->m_eCoverComponentObject.mValue);
  v9 = result;
  if ( result )
  {
    result->vfptr->GetHeight(result);
    v10 = a3 > 0.5 && a3 < 1.6;
    v9->vfptr->GetHeight(v9);
    v9->vfptr->GetHeight(v9);
    v11 = (a3 <= 0.5 || a3 >= 1.6) && a3 > 1.5;
    if ( v10 && v3->m_Low || v11 && v3->m_High )
      v5 = 1;
    result = (UFG::CoverObjectBase *)v5;
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
  CoverTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CoverTypeCondition::`vftable;
  *(_DWORD *)&v1->m_eCoverComponentObject.mValue = 16777217;
}

// File Line: 14391
// RVA: 0x2812B0
bool __fastcall CoverTypeCondition::Match(CoverTypeCondition *this, ActionContext *pContext)
{
  CoverTypeCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  UFG::AICoverComponent *v4; // rax
  unsigned __int16 v5; // dx
  UFG::CoverObjectBase *v6; // rax
  UFG::CoverObjectBase *v7; // rbx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v3->vfptr,
                                        UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = UFG::AICoverComponent::GetCoverObjectFromEnum(
         v4,
         (UFG::eCoverComponentObjectEnum)(unsigned __int8)v2->m_eCoverComponentObject.mValue);
  v7 = v6;
  return v6
      && v6->vfptr->IsPosition(v6)
      && (v2->m_LeftCorner && UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v7[2].m_iRefCount)
       || v2->m_RightCorner && UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v7[4].m_iRefCount)
       || v2->m_Line && v7->vfptr->IsParkour(v7));
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
void __fastcall CoverCanTraverseInDirectionCondition::CoverCanTraverseInDirectionCondition(CoverCanTraverseInDirectionCondition *this)
{
  CoverCanTraverseInDirectionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CoverCanTraverseInDirectionCondition::`vftable;
  *(_WORD *)&v1->m_bLeft = 0;
}

// File Line: 14450
// RVA: 0x280680
bool __fastcall CoverCanTraverseInDirectionCondition::Match(CoverCanTraverseInDirectionCondition *this, ActionContext *pContext)
{
  CoverCanTraverseInDirectionCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // dx
  float *v6; // rbx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = (float *)v4[1].m_BoundComponentHandles.mNode.mPrev;
  return v6
      && (*(unsigned __int8 (__fastcall **)(float *))(*(_QWORD *)v6 + 16i64))(v6)
      && (v2->m_bLeft && v6[52] > 0.1 || v2->m_bRight && v6[53] > 0.1);
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
  WaterDepth *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&WaterDepth::`vftable;
  v1->mWaterDepth = 0.0;
  v1->mInEqualityOperator.mValue = 1;
}

// File Line: 14504
// RVA: 0x293710
char __fastcall WaterDepth::Match(WaterDepth *this, ActionContext *context)
{
  WaterDepth *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  float v4; // xmm7_4
  ActionContext *v5; // rdi
  unsigned __int16 v6; // r8
  UFG::CharacterPhysicsComponent *v7; // rbx
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // rax
  UFG::TransformNodeComponent *v10; // rdi
  float v11; // xmm6_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = FLOAT_N1_0;
  v5 = context;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::CharacterPhysicsComponent *)v3->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v7 = (UFG::CharacterPhysicsComponent *)v8;
    }
    if ( v7 )
    {
      if ( UFG::CharacterPhysicsComponent::IsInWater(v7) )
      {
        v9 = v5->mSimObject.m_pPointer;
        v10 = v9->m_pTransformNodeComponent;
        if ( v10 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
          v11 = v10->mWorldTransform.v3.z;
          v4 = UFG::CharacterPhysicsComponent::GetWaterElevation(v7) - v11;
        }
      }
    }
  }
  return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mWaterDepth, v4);
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
  TargetedByTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::TargetingSystemBaseComponent *v5; // rax
  UFG::eTargetTypeEnum v6; // edx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v3,
                                                  UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v5 = (UFG::TargetingSystemBaseComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v3,
                                                                    UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID));
  }
  else
  {
    v5 = (UFG::TargetingSystemBaseComponent *)v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v6 = (unsigned __int8)v2->m_eTargetType.mValue;
  if ( v2->m_bIsLocked )
    result = UFG::TargetingSystemBaseComponent::IsTargetedByTypeAndLocked(v5, v6);
  else
    result = UFG::TargetingSystemBaseComponent::IsTargetedByType(v5, v6);
  return result;
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
  IsTargetsTargetCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // r8
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rcx
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    goto LABEL_30;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( v6
    && (v8 = *(UFG::SimObjectGame **)(56i64
                                    * *(unsigned __int8 *)((unsigned __int8)v2->m_eTargetType.mValue
                                                         + *(_QWORD *)&v6[1].m_Flags
                                                         + 8i64)
                                    + *(_QWORD *)&v6[1].m_TypeUID
                                    + 40)) != 0i64
    && ((v9 = v8->m_Flags, !((v9 >> 14) & 1)) ? ((v9 & 0x8000u) == 0 ? (!((v9 >> 13) & 1) ? (!((v9 >> 12) & 1) ? (v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v10 = v11) : (v10 = v8->m_Components.p[20].m_pComponent)) : (v10 = v8->m_Components.p[20].m_pComponent),
        v10
     && (v12 = *(UFG::SimObject **)(56i64
                                  * *(unsigned __int8 *)((unsigned __int8)v2->m_eTargetsTargetType.mValue
                                                       + *(_QWORD *)&v10[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v10[1].m_TypeUID
                                  + 40)) != 0i64) )
  {
    result = v12 == v4->mSimObject.m_pPointer;
  }
  else
  {
LABEL_30:
    result = 0;
  }
  return result;
}

// File Line: 14632
// RVA: 0x27DF90
bool __fastcall InventoryCheckPropertyMatch(UFG::SimObject *pSimObject, UFG::eItemPropertiesEnum eProperty)
{
  UFG::eItemPropertiesEnum v2; // ebx
  unsigned __int16 v3; // r8
  UFG::SimComponent *v4; // rax
  UFG::eInventoryItemEnum v5; // ecx
  bool result; // al

  v2 = eProperty;
  if ( pSimObject
    && (v3 = pSimObject->m_Flags, !((v3 >> 14) & 1))
    && (v3 & 0x8000u) == 0
    && (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType(
                                                         pSimObject,
                                                         UFG::InventoryItemComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObject, UFG::InventoryItemComponent::_TypeUID))) : (v4 = pSimObject->m_Components.p[11].m_pComponent),
        v4 && (v5 = (UFG::eInventoryItemEnum)v4[1].m_pSimObject) != 0) )
  {
    result = UFG::ItemProfiles::HasProperty(v5, v2);
  }
  else
  {
    result = 0;
  }
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
           pContext->mSimObject.m_pPointer,
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
bool __fastcall TargetInventoryCheckPropertyCondition::Match(TargetInventoryCheckPropertyCondition *this, ActionContext *pContext)
{
  TargetInventoryCheckPropertyCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5) )
  {
    result = InventoryCheckPropertyMatch(
               *(UFG::SimObject **)(56i64
                                  * *(unsigned __int8 *)((unsigned int)v2->mTargetType + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40),
               (UFG::eItemPropertiesEnum)(unsigned __int8)v2->m_eProperty.mValue);
  }
  else
  {
    result = 0;
  }
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
  TargetPurchaseItemFailCondition *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rax
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rcx
  UFG::SimComponent *v10; // rax
  __int64 v11; // rdx
  signed int v13; // ebx
  UFG::GameStatTracker *v14; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v7 = (UFG::SimObjectGame *)UFG::getTarget(v4, (UFG::eTargetTypeEnum)v2->mTargetType);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = v7->m_Components.p[39].m_pComponent;
  }
  else
  {
    if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::InventoryComponent::_TypeUID);
      else
        v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::InventoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::InventoryComponent::_TypeUID);
    }
    else
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::InventoryComponent::_TypeUID);
    }
    v9 = v10;
  }
  if ( !v9 )
    return 0;
  v11 = *(signed int *)&v9[14].m_Flags;
  if ( !(_DWORD)v11 )
    return 0;
  if ( !LOBYTE(v9[14].m_pSimObject) && (signed int)*(&v9[1].m_NameUID + v11) <= 0 )
    return 1;
  v13 = UFG::ItemProfiles::GetCost((UFG::eInventoryItemEnum)v11);
  v14 = UFG::GameStatTracker::Instance();
  return (signed int)UFG::GameStatTracker::GetStat(v14, Money) < v13;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::FaceActionComponent *v4; // rax
  char result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID)) : (v4 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = (UFG::FaceActionComponent *)v2->m_Components.p[45].m_pComponent),
        v4) )
  {
    result = UFG::FaceActionComponent::AreAnimsLoaded(v4);
  }
  else
  {
    result = 0;
  }
  return result;
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
  SocialSetEvaluatedCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::FaceActionComponent *v5; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::FaceActionComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::FaceActionComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::FaceActionComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v5 )
      UFG::FaceActionComponent::SetFrameAITreeEvaluated(v5, v2->m_Evaluated != 0);
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
      v4 = v2->m_Components.p[22].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIEntityComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIEntityComponent::_TypeUID);
    }
    else
    {
      v4 = v2->m_Components.p[22].m_pComponent;
    }
    if ( v4 && BYTE5(v4[20].m_BoundComponentHandles.mNode.mPrev) )
      result = 1;
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
  StateFlagCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&StateFlagCondition::`vftable;
  v1->m_FlagType.mValue = 0;
}

// File Line: 14841
// RVA: 0x28B6E0
bool __fastcall StateFlagCondition::Match(StateFlagCondition *this, ActionContext *pContext)
{
  StateFlagCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectPropertiesComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectPropertiesComponent::_TypeUID)),
                                                                                             v5 = v6) : (v5 = v3->m_Components.p[4].m_pComponent)) : (v5 = v3->m_Components.p[3].m_pComponent)) : (v5 = v3->m_Components.p[3].m_pComponent),
        v5 && LODWORD(v5[1].m_SafePointerList.mNode.mNext) == 1) )
  {
    result = *((_BYTE *)&v5[2].m_BoundComponentHandles.mNode.mPrev + (signed int)v2->m_FlagType.mValue + 1);
  }
  else
  {
    result = 0;
  }
  return result;
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
  SimObjectFlagCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SimObjectFlagCondition::`vftable;
  v1->m_Flag.mValue = 0;
}

// File Line: 14873
// RVA: 0x2899E0
bool __fastcall SimObjectFlagCondition::Match(SimObjectFlagCondition *this, ActionContext *pContext)
{
  SimObjectFlagCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectPropertiesComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::SimObjectPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectPropertiesComponent::_TypeUID)) : (v5 = (UFG::SimObjectPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::SimObjectPropertiesComponent::_TypeUID))) : (v5 = (UFG::SimObjectPropertiesComponent *)v3->m_Components.p[4].m_pComponent)) : (v5 = (UFG::SimObjectPropertiesComponent *)v3->m_Components.p[3].m_pComponent)) : (v5 = (UFG::SimObjectPropertiesComponent *)v3->m_Components.p[3].m_pComponent),
        v5) )
  {
    result = UFG::SimObjectPropertiesComponent::isFlagSet(v5, (UFG::eSimObjectFlagEnum)v2->m_Flag.mValue);
  }
  else
  {
    result = 0;
  }
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
    result = (UFG::TimeOfDayManager *)(1.0 < result->m_WeatherState);
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
  UFG::SimObjectCharacter *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActorAudioComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCharacter *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID)) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::ActorAudioComponent::_TypeUID))) : (v4 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v2)),
        v4) )
  {
    result = v4->m_interiorCount != 0;
  }
  else
  {
    result = 0;
  }
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
  PlayerIsInSpecificInterior *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInSpecificInterior::`vftable;
  v1->mInterior.mValue = 0;
}

// File Line: 15018
// RVA: 0x288F20
bool __fastcall PlayerIsInSpecificInterior::Match(PlayerIsInSpecificInterior *this, ActionContext *context)
{
  bool result; // al

  if ( UFG::UIHKScreenHud::mInteriorManager )
    result = UFG::UIHKScreenHud::mInteriorManager->mActiveInterior == this->mInterior.mValue;
  else
    result = 0;
  return result;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::StreamedResourceComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::StreamedResourceComponent::_TypeUID)) : (v4 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::StreamedResourceComponent::_TypeUID))) : (v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[7].m_pComponent)) : (v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent)) : (v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent),
        v4) )
  {
    result = UFG::StreamedResourceComponent::GetSpawnPriority(v4, 0i64)->mUID == qSymbol_Critical.mUID;
  }
  else
  {
    result = 1;
  }
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
  IsLockboxContainingCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsLockboxContainingCondition::`vftable;
  v1->mInventoryItemType.mValue = 0;
}

// File Line: 15125
// RVA: 0x284070
bool __fastcall IsLockboxContainingCondition::Match(IsLockboxContainingCondition *this, ActionContext *pContext)
{
  IsLockboxContainingCondition *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *v5; // rax
  UFG::qSymbol *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  bool v8; // r8
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v2 = this;
  v3 = pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = (UFG::qSymbol *)PropertyUtils::Get<UFG::qSymbol>(
                         v3->m_pSceneObj,
                         (UFG::qSymbol *)&qSymbol_RewardsPropertySet.mUID);
  if ( !v4 )
    return 0;
  if ( v4->mUID == -1 )
    return 0;
  v5 = UFG::PropertySetManager::GetPropertySet(v4);
  if ( !v5 )
    return 0;
  v6 = PropertyUtils::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&qSymbol_InventoryItemType.mUID, DEPTH_RECURSE);
  if ( !v6 || v6->mUID == -1 )
    return 0;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
    v7 = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v7;
    pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v8 = v2->mInventoryItemType.mValue == pTrackEnumBinding.m_EnumValue;
  v9 = pTrackEnumBinding.mPrev;
  v10 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v10->mPrev = v9;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
  IsGroupLeaderCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsGroupLeaderCondition::`vftable;
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
  TargetIsGroupLeaderCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetIsGroupLeaderCondition::`vftable;
  v1->mTargetType.mValue = 0;
}

// File Line: 15210
// RVA: 0x28C940
char __fastcall TargetIsGroupLeaderCondition::Match(TargetIsGroupLeaderCondition *this, ActionContext *pContext)
{
  TargetIsGroupLeaderCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  char result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5) )
  {
    result = UFG::GroupComponent::IsLeader(*(UFG::SimObject **)(56i64
                                                              * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                                                   + *(_QWORD *)&v5[1].m_Flags
                                                                                   + 8i64)
                                                              + *(_QWORD *)&v5[1].m_TypeUID
                                                              + 40));
  }
  else
  {
    result = 0;
  }
  return result;
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
  IsGroupFollowerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsGroupFollowerCondition::`vftable;
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
  TargetIsGroupFollowerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetIsGroupFollowerCondition::`vftable;
  v1->mTargetType.mValue = 0;
}

// File Line: 15265
// RVA: 0x28C880
bool __fastcall TargetIsGroupFollowerCondition::Match(TargetIsGroupFollowerCondition *this, ActionContext *pContext)
{
  TargetIsGroupFollowerCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5) )
  {
    result = UFG::GroupComponent::IsFollower(*(UFG::SimObject **)(56i64
                                                                * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                                                     + *(_QWORD *)&v5[1].m_Flags
                                                                                     + 8i64)
                                                                + *(_QWORD *)&v5[1].m_TypeUID
                                                                + 40));
  }
  else
  {
    result = 0;
  }
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
  IsGroupMemberCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsGroupMemberCondition::`vftable;
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
  TargetIsGroupMemberCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetIsGroupMemberCondition::`vftable;
  v1->mTargetType.mValue = 0;
}

// File Line: 15320
// RVA: 0x28CA00
bool __fastcall TargetIsGroupMemberCondition::Match(TargetIsGroupMemberCondition *this, ActionContext *pContext)
{
  TargetIsGroupMemberCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v5 = v6) : (v5 = v3->m_Components.p[20].m_pComponent)) : (v5 = v3->m_Components.p[20].m_pComponent),
        v5) )
  {
    result = UFG::GroupComponent::IsGroupMember(*(UFG::SimObject **)(56i64
                                                                   * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                                                        + *(_QWORD *)&v5[1].m_Flags
                                                                                        + 8i64)
                                                                   + *(_QWORD *)&v5[1].m_TypeUID
                                                                   + 40));
  }
  else
  {
    result = 0;
  }
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
  TargetIsInMyGroupCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetIsInMyGroupCondition::`vftable;
  v1->mTargetType.mValue = 0;
}

// File Line: 15352
// RVA: 0x28CAC0
bool __fastcall TargetIsInMyGroupCondition::Match(TargetIsInMyGroupCondition *this, ActionContext *pContext)
{
  TargetIsInMyGroupCondition *v2; // rsi
  UFG::SimObject *v3; // rcx
  ActionContext *v4; // rbx
  UFG::GroupComponent *v5; // rdi
  UFG::SimObject *v6; // r8
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // r8
  UFG::SimObjectGame *v9; // rcx
  UFG::SimComponent *v10; // rax
  UFG::SimObject *v11; // rcx
  UFG::GroupComponent *v12; // rax
  bool result; // al

  v2 = this;
  v3 = pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    goto LABEL_21;
  v5 = UFG::GroupComponent::GetGroupComponent(v3);
  if ( !v5 )
    goto LABEL_21;
  v6 = v4->mSimObject.m_pPointer;
  if ( !v6 )
    goto LABEL_21;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = v6->m_Components.p[20].m_pComponent;
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    v9 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( (v7 >> 13) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v10 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v8 = v10;
  }
  else
  {
    v8 = v6->m_Components.p[20].m_pComponent;
  }
  if ( v8
    && (v11 = *(UFG::SimObject **)(56i64
                                 * *(unsigned __int8 *)((unsigned __int8)v2->mTargetType.mValue
                                                      + *(_QWORD *)&v8[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&v8[1].m_TypeUID
                                 + 40)) != 0i64
    && (v12 = UFG::GroupComponent::GetGroupComponent(v11)) != 0i64 )
  {
    result = UFG::GroupComponent::IsInGroup(v5, v12);
  }
  else
  {
LABEL_21:
    result = 0;
  }
  return result;
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
  NumGroupMemberAliveCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&NumGroupMemberAliveCondition::`vftable;
  v1->m_eInEqualityOperator.mValue = 4;
  v1->m_Count = 1;
}

// File Line: 15401
// RVA: 0x285F40
bool __fastcall NumGroupMemberAliveCondition::Match(NumGroupMemberAliveCondition *this, ActionContext *pContext)
{
  NumGroupMemberAliveCondition *v2; // r14
  UFG::SimObject *v3; // rcx
  UFG::GroupComponent *v4; // rax
  UFG::GroupComponent *v5; // rsi
  int v6; // edi
  signed int v7; // ebp
  signed int i; // ebx
  UFG::GroupComponent *v9; // rax
  UFG::SimObjectGame *v10; // rax
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rax
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax

  v2 = this;
  v3 = pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = UFG::GroupComponent::GetGroupComponent(v3);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = 0;
  v7 = Scaleform::Render::Hairliner::GetMeshVertexCount(v4);
  for ( i = 0; i < v7; ++i )
  {
    v9 = UFG::GroupComponent::GetFollower(v5, i);
    if ( v9 )
    {
      v10 = (UFG::SimObjectGame *)UFG::GroupComponent::GetSimObjectPtr(v9);
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = v10->m_Components.p[6].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HealthComponent::_TypeUID);
          else
            v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v12 = v10->m_Components.p[6].m_pComponent;
        }
        if ( !BYTE4(v12[1].m_BoundComponentHandles.mNode.mPrev) )
          ++v6;
      }
    }
  }
  v13 = (UFG::SimObjectGame *)UFG::GroupComponent::GetSimObjectPtr(v5);
  if ( v13 )
  {
    v14 = v13->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = v13->m_Components.p[6].m_pComponent;
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::HealthComponent::_TypeUID);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::HealthComponent::_TypeUID);
      }
    }
    else
    {
      v15 = v13->m_Components.p[6].m_pComponent;
    }
    if ( !BYTE4(v15[1].m_BoundComponentHandles.mNode.mPrev) )
      ++v6;
  }
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->m_eInEqualityOperator.mValue, v2->m_Count, v6);
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
      result = 1;
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
bool __fastcall IsPlayerInCombatBuffModeCondition::Match(IsPlayerInCombatBuffModeCondition *this, ActionContext *pContext)
{
  UFG::GameStatTracker *v2; // rax
  bool result; // al

  result = 0;
  if ( pContext )
  {
    v2 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v2, PlayerFaceMeterBuff_Activated) > 0.0 )
      result = 1;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( pContext
    && (v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = v2->m_Components.p[15].m_pComponent)) : (v4 = v2->m_Components.p[15].m_pComponent),
        v4) )
  {
    result = v4[1].m_Flags;
  }
  else
  {
    result = 0;
  }
  return result;
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
bool __fastcall HitRecordBerserkAttackFlagCondition::Match(HitRecordBerserkAttackFlagCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( pContext
    && (v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::HitReactionComponent::_TypeUID))) : (v4 = v2->m_Components.p[15].m_pComponent)) : (v4 = v2->m_Components.p[15].m_pComponent),
        v4) )
  {
    result = UFG::HitReactionComponent::msBerserkAttackValidFlag;
  }
  else
  {
    result = 0;
  }
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
  return pContext
      && UFG::UIScreenManagerBase::getOverlay(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Camera");
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
  ActionContext *v2; // rdi
  ResourceIsAvailableCondition *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rdx
  UFG::SimComponent *v7; // rax
  __int64 v8; // r8
  UFG::SimObject *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::InterestPoint *v11; // rax
  char result; // al

  v2 = pContext;
  v3 = this;
  if ( !this->m_bCheckTarget )
    goto LABEL_30;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v4 )
    goto LABEL_30;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v4->m_Components.p[20].m_pComponent;
  }
  if ( v6
    && (v8 = (unsigned __int8)v3->m_eTargetType.mValue,
        (v9 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + v8 + 8)
                                 + *(_QWORD *)&v6[1].m_TypeUID
                                 + 40)) != 0i64)
    && (_BYTE)v8 == 26
    && ((v10 = v9->m_Flags, !((v10 >> 14) & 1)) ? ((v10 & 0x8000u) == 0 ? (!((v10 >> 13) & 1) ? (!((v10 >> 12) & 1) ? (v11 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v9, UFG::InterestPoint::_TypeUID)) : (v11 = (UFG::InterestPoint *)v9->m_Components.p[3].m_pComponent)) : (v11 = (UFG::InterestPoint *)v9->m_Components.p[10].m_pComponent)) : (v11 = (UFG::InterestPoint *)v9->m_Components.p[25].m_pComponent)) : (v11 = (UFG::InterestPoint *)v9->m_Components.p[25].m_pComponent),
        v11) )
  {
    result = UFG::InterestPoint::IsAvailable(v11, v2->mSimObject.m_pPointer, 1);
  }
  else
  {
LABEL_30:
    result = 0;
  }
  return result;
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
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySet *v3; // rbx
  UFG::ObjectResourceManager *v4; // rax

  v2 = UFG::PropertySetManager::GetPropertySet(&this->m_PropertySetName);
  v3 = v2;
  if ( v2 )
  {
    v4 = UFG::ObjectResourceManager::Instance();
    LOBYTE(v2) = UFG::ObjectResourceManager::IsLoaded(v4, v3);
  }
  return (char)v2;
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
bool __fastcall PurchasableItemAvailableCondition::Match(PurchasableItemAvailableCondition *this, ActionContext *pContext)
{
  PurchasableItemAvailableCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  char v7; // cl
  __int64 v8; // r8
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[39].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID);
        else
          v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InventoryComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InventoryComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = v2->m_bCheck;
      if ( !v7 || v2->m_eInventoryItem == *(_DWORD *)&v5[14].m_Flags )
      {
        v8 = *(signed int *)&v5[14].m_Flags;
        if ( LOBYTE(v5[14].m_pSimObject)
          || (signed int)*(&v5[1].m_NameUID + v8) > 0
          || !v7 && v2->m_eInventoryItem == (_DWORD)v8 )
        {
          result = 1;
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
void __fastcall InteractionPointFindBestCondition::InteractionPointFindBestCondition(InteractionPointFindBestCondition *this)
{
  InteractionPointFindBestCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointFindBestCondition::`vftable;
  *(_DWORD *)&v1->m_eOriginTargetType.mValue = 16777217;
  *(_DWORD *)&v1->m_bTEST_eTARGET_TYPE_INTERACTION_POINT2 = 16843009;
  v1->m_bIgnoreMeshTest = 0;
}

// File Line: 15744
// RVA: 0x282E40
bool __fastcall InteractionPointFindBestCondition::Match(InteractionPointFindBestCondition *this, ActionContext *pContext)
{
  InteractionPointFindBestCondition *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbp
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rcx
  UFG::SimComponent *v11; // rax
  __int64 v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::InteractableComponent *v15; // rbx
  UFG::SimComponent *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::InteractorComponent *v19; // rdi
  UFG::SimComponent *v20; // rax
  UFG::SimObject *v21; // rdx
  bool v22; // r9
  UFG::InteractionPoint *v23; // rbx
  UFG::qStaticBitField<6> bfTestIP; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( !v3 )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v6 = v7;
  }
  else
  {
    v6 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  if ( !((__int64 (__fastcall *)(UFG::SimComponent *))v6->vfptr[15].__vecDelDtor)(v6) )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)((unsigned __int8)v2->m_eOriginTargetType.mValue
                                                   + *(_QWORD *)&v6[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&v6[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v10 = v11;
  }
  else
  {
    v10 = v8->m_Components.p[20].m_pComponent;
  }
  if ( !v10 )
    return 0;
  v12 = ((__int64 (*)(void))v10->vfptr[15].__vecDelDtor)();
  if ( !v12 )
    return 0;
  v13 = *(UFG::SimObjectGame **)(56i64
                               * *(unsigned __int8 *)((unsigned __int8)v2->m_eTargetType.mValue
                                                    + *(_QWORD *)(v12 + 96)
                                                    + 8i64)
                               + *(_QWORD *)(v12 + 88)
                               + 40);
  if ( !v13 )
    return 0;
  v14 = v13->m_Flags;
  if ( (v14 >> 14) & 1 )
  {
    v15 = (UFG::InteractableComponent *)v13->m_Components.p[12].m_pComponent;
  }
  else if ( (v14 & 0x8000u) == 0 )
  {
    if ( (v14 >> 13) & 1 )
      v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InteractableComponent::_TypeUID);
    else
      v16 = (v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InteractableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::InteractableComponent::_TypeUID);
    v15 = (UFG::InteractableComponent *)v16;
  }
  else
  {
    v15 = (UFG::InteractableComponent *)v13->m_Components.p[12].m_pComponent;
  }
  if ( !v15 )
    return 0;
  v17 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( !v17 )
    return 0;
  v18 = v17->m_Flags;
  if ( (v18 >> 14) & 1 )
  {
    v19 = (UFG::InteractorComponent *)v17->m_Components.p[29].m_pComponent;
  }
  else
  {
    if ( (v18 & 0x8000u) == 0 )
    {
      if ( (v18 >> 13) & 1 )
        v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::InteractorComponent::_TypeUID);
      else
        v20 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::InteractorComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, UFG::InteractorComponent::_TypeUID);
    }
    else
    {
      v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::InteractorComponent::_TypeUID);
    }
    v19 = (UFG::InteractorComponent *)v20;
  }
  if ( !v19 )
    return 0;
  v21 = v4->mSimObject.m_pPointer;
  v22 = v2->m_bIgnoreMeshTest != 0;
  bfTestIP.mBits[0] = (v2->m_bTEST_eTARGET_TYPE_INTERACTION_POINT5 != 0 ? 0x20 : 0) | (v2->m_bTEST_eTARGET_TYPE_INTERACTION_POINT4 != 0 ? 0x10 : 0) | (v2->m_bTEST_eTARGET_TYPE_INTERACTION_POINT3 != 0 ? 8 : 0) | (v2->m_bTEST_eTARGET_TYPE_INTERACTION_POINT2 != 0 ? 4 : 0) | (v2->m_bTEST_eTARGET_TYPE_INTERACTION_POINT1 != 0 ? 2 : 0) | (unsigned __int64)(v2->m_bTEST_eTARGET_TYPE_INTERACTION_POINT0 != 0);
  v23 = UFG::InteractableComponent::FindBestInteractionPoint(v15, v21, &bfTestIP, v22);
  UFG::InteractorComponent::SetBestInteractionPoint(v19, v23, 1);
  return v23 != 0i64;
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
  InteractionPointValidCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointValidCondition::`vftable;
  *(_WORD *)&v1->m_eTargetType.mValue = 17664;
  v1->m_bIgnoreMeshTest = 0;
}

// File Line: 15842
// RVA: 0x283460
bool __fastcall InteractionPointValidCondition::Match(InteractionPointValidCondition *this, ActionContext *pContext)
{
  __int64 v2; // rdi
  UFG::eTargetTypeEnum v3; // er14
  InteractionPointValidCondition *v4; // rbp
  UFG::SimObjectGame *v5; // rcx
  ActionContext *v6; // rbx
  unsigned __int16 v7; // r8
  UFG::SimComponent *v8; // rcx
  UFG::SimComponent *v9; // rax
  __int64 v10; // rax
  UFG::SimObjectGame *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::InteractableComponent *v13; // rsi
  UFG::SimComponent *v14; // rax
  UFG::SimObjectGame *v15; // rbx
  unsigned __int16 v16; // cx
  UFG::InteractorComponent *v17; // rdi
  UFG::SimComponent *v18; // rax
  UFG::InteractionPoint *v19; // rbx

  v2 = (unsigned __int8)this->m_eTargetType.mValue;
  v3 = (unsigned __int8)this->m_eInteractionPointTargetType.mValue;
  v4 = this;
  v5 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v6 = pContext;
  if ( !v5 )
    return 0;
  v7 = v5->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = v5->m_Components.p[20].m_pComponent;
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v8 = v9;
  }
  else
  {
    v8 = v5->m_Components.p[20].m_pComponent;
  }
  if ( !v8 )
    return 0;
  v10 = ((__int64 (*)(void))v8->vfptr[15].__vecDelDtor)();
  if ( !v10 )
    return 0;
  v11 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v10 + 96) + v2 + 8)
                               + *(_QWORD *)(v10 + 88)
                               + 40);
  if ( !v11 )
    return 0;
  v12 = v11->m_Flags;
  if ( (v12 >> 14) & 1 )
  {
    v13 = (UFG::InteractableComponent *)v11->m_Components.p[12].m_pComponent;
  }
  else if ( (v12 & 0x8000u) == 0 )
  {
    if ( (v12 >> 13) & 1 )
      v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::InteractableComponent::_TypeUID);
    else
      v14 = (v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::InteractableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::InteractableComponent::_TypeUID);
    v13 = (UFG::InteractableComponent *)v14;
  }
  else
  {
    v13 = (UFG::InteractableComponent *)v11->m_Components.p[12].m_pComponent;
  }
  if ( !v13 )
    return 0;
  v15 = (UFG::SimObjectGame *)v6->mSimObject.m_pPointer;
  if ( !v15 )
    return 0;
  v16 = v15->m_Flags;
  if ( (v16 >> 14) & 1 )
  {
    v17 = (UFG::InteractorComponent *)v15->m_Components.p[29].m_pComponent;
  }
  else
  {
    if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::InteractorComponent::_TypeUID);
      else
        v18 = (v16 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::InteractorComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::InteractorComponent::_TypeUID);
    }
    else
    {
      v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::InteractorComponent::_TypeUID);
    }
    v17 = (UFG::InteractorComponent *)v18;
  }
  if ( !v17 )
    return 0;
  v19 = UFG::InteractableComponent::FindInteractionPoint(
          v13,
          (UFG::SimObject *)&v15->vfptr,
          v3,
          v4->m_bIgnoreMeshTest != 0);
  UFG::InteractorComponent::SetBestInteractionPoint(v17, v19, 1);
  return v19 != 0i64;
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
  InteractionPointIsAccessable *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointIsAccessable::`vftable;
  v1->m_eInteractionPointTargetType.mValue = 69;
}

// File Line: 15907
// RVA: 0x283150
char __fastcall InteractionPointIsAccessable::Match(InteractionPointIsAccessable *this, ActionContext *pContext)
{
  InteractionPointIsAccessable *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  signed __int64 v7; // rax
  __int64 v8; // rbx
  UFG::TransformNodeComponent *v9; // rbx
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  char result; // al
  UFG::HavokNavPosition v14; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    goto LABEL_26;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[12].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractableComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InteractableComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[12].m_pComponent;
  }
  v7 = (unsigned int)(unsigned __int8)v2->m_eInteractionPointTargetType.mValue - 69;
  if ( v2->m_eInteractionPointTargetType.mValue == 69 )
  {
    v7 = 0i64;
  }
  else if ( (unsigned int)v7 >= 5 )
  {
    v7 = 5i64;
  }
  if ( !BYTE4((&v5[2].m_BoundComponentHandles.mNode.mPrev)[20 * v7]) )
    goto LABEL_26;
  v8 = *((_QWORD *)&v5[2].m_Flags + 20 * v7);
  if ( !v8 )
    goto LABEL_26;
  v9 = *(UFG::TransformNodeComponent **)(v8 + 88);
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v14.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v10 = v9->mWorldTransform.v3.y;
  v11 = v9->mWorldTransform.v3.z;
  v12 = v9->mWorldTransform.v3.x;
  v14.m_bValid = 0;
  *(_QWORD *)&v14.m_packedKey = -1i64;
  v14.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v14.m_vPosition.z = v11;
  v14.m_vPosition.y = v10;
  v14.m_vPosition.x = v12;
  v14.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(
                                     (__m128)LODWORD(v9->mWorldTransform.v3.x),
                                     (__m128)LODWORD(v9->mWorldTransform.v3.z)),
                                   _mm_unpacklo_ps(
                                     (__m128)LODWORD(v9->mWorldTransform.v3.y),
                                     (__m128)(unsigned int)FLOAT_1_0));
  UFG::HavokNavPosition::Validate(&v14, 0.050000001, 1.0, 0.0);
  if ( !v14.m_bValid
    || !UFG::HavokAIUtilGame::IsValidKey(v14.m_packedKey, v14.m_aiMeshUid)
    || v14.m_packedKey == -1
    || v14.m_aiMeshUid == -1 )
  {
    result = 0;
  }
  else
  {
LABEL_26:
    result = 1;
  }
  return result;
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
void __fastcall InteractionPointIsBestBusyCondition::InteractionPointIsBestBusyCondition(InteractionPointIsBestBusyCondition *this)
{
  InteractionPointIsBestBusyCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointIsBestBusyCondition::`vftable;
}

// File Line: 15956
// RVA: 0x2832F0
bool __fastcall InteractionPointIsBestBusyCondition::Match(InteractionPointIsBestBusyCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  bool result; // al

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::InteractorComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InteractorComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InteractorComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InteractorComponent::_TypeUID))) : (v4 = v2->m_Components.p[29].m_pComponent),
        v4 && (v5 = v4[1].m_SafePointerList.mNode.mNext) != 0i64) )
  {
    result = LODWORD(v5[2].mPrev) != 0;
  }
  else
  {
    result = 0;
  }
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
void __fastcall InteractionPointIsBestOfTypeCondition::InteractionPointIsBestOfTypeCondition(InteractionPointIsBestOfTypeCondition *this)
{
  InteractionPointIsBestOfTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointIsBestOfTypeCondition::`vftable;
  v1->m_eInteractionPointTargetType.mValue = 69;
}

// File Line: 16000
// RVA: 0x283390
bool __fastcall InteractionPointIsBestOfTypeCondition::Match(InteractionPointIsBestOfTypeCondition *this, ActionContext *pContext)
{
  InteractionPointIsBestOfTypeCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // r8
  unsigned int v7; // eax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[29].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID);
    else
      v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InteractorComponent::_TypeUID);
  }
  else
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractorComponent::_TypeUID);
  }
  if ( !v5 )
    return 0;
  v6 = v5[1].m_SafePointerList.mNode.mNext;
  if ( !v6 )
    return 0;
  v7 = (unsigned __int8)v2->m_eInteractionPointTargetType.mValue - 69;
  if ( v2->m_eInteractionPointTargetType.mValue == 69 )
  {
    v7 = 0;
  }
  else if ( v7 >= 5 )
  {
    v7 = 5;
  }
  return v6 == (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)((char *)&v6[1].mNext[10 * v7 + 5]
                                                                                                + 8);
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
void __fastcall IfTargetsInteractionPointNotBusySetBestCondition::IfTargetsInteractionPointNotBusySetBestCondition(IfTargetsInteractionPointNotBusySetBestCondition *this)
{
  IfTargetsInteractionPointNotBusySetBestCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IfTargetsInteractionPointNotBusySetBestCondition::`vftable;
  *(_WORD *)&v1->m_eTargetType.mValue = 17692;
  v1->m_bIgnoreMeshTest = 0;
}

// File Line: 16063
// RVA: 0x2828E0
_BOOL8 __fastcall IfTargetsInteractionPointNotBusySetBestCondition::Match(IfTargetsInteractionPointNotBusySetBestCondition *this, ActionContext *pContext)
{
  IfTargetsInteractionPointNotBusySetBestCondition *v2; // r14
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  bool v5; // bp
  unsigned __int16 v6; // r8
  UFG::SimComponent *v7; // r8
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::InteractableComponent *v11; // rsi
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rbx
  unsigned __int16 v14; // cx
  UFG::InteractorComponent *v15; // rdi
  UFG::SimComponent *v16; // rax
  UFG::InteractionPoint *v17; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  v5 = 1;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v7 = v8;
    }
    else
    {
      v7 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v7 )
    {
      v9 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)((unsigned __int8)v2->m_eTargetType.mValue
                                                       + *(_QWORD *)&v7[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v7[1].m_TypeUID
                                  + 40);
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v11 = (UFG::InteractableComponent *)v9->m_Components.p[12].m_pComponent;
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::InteractableComponent::_TypeUID);
          else
            v12 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::InteractableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::InteractableComponent::_TypeUID);
          v11 = (UFG::InteractableComponent *)v12;
        }
        else
        {
          v11 = (UFG::InteractableComponent *)v9->m_Components.p[12].m_pComponent;
        }
        if ( v11 )
        {
          v13 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
          if ( v13 )
          {
            v14 = v13->m_Flags;
            if ( (v14 >> 14) & 1 )
            {
              v15 = (UFG::InteractorComponent *)v13->m_Components.p[29].m_pComponent;
            }
            else
            {
              if ( (v14 & 0x8000u) == 0 )
              {
                if ( (v14 >> 13) & 1 )
                {
                  v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InteractorComponent::_TypeUID);
                }
                else if ( (v14 >> 12) & 1 )
                {
                  v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InteractorComponent::_TypeUID);
                }
                else
                {
                  v16 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v13->vfptr,
                          UFG::InteractorComponent::_TypeUID);
                }
              }
              else
              {
                v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::InteractorComponent::_TypeUID);
              }
              v15 = (UFG::InteractorComponent *)v16;
            }
            if ( v15 )
            {
              v17 = UFG::InteractableComponent::FindInteractionPoint(
                      v11,
                      (UFG::SimObject *)&v13->vfptr,
                      (UFG::eTargetTypeEnum)(unsigned __int8)v2->m_eInteractionPointTargetType.mValue,
                      v2->m_bIgnoreMeshTest != 0);
              if ( v17 )
              {
                v5 = v17->m_InteractorList.size == 0;
                if ( !v17->m_InteractorList.size )
                  UFG::InteractorComponent::SetBestInteractionPoint(v15, v17, 1);
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
  TimeOfDayCondition *v2; // rbx
  UFG::TimeOfDayManager *v3; // rax

  v2 = this;
  v3 = UFG::TimeOfDayManager::GetInstance();
  if ( v3 )
    LOBYTE(v3) = CompareFloat(
                   (UFG::InEqualityOperator)(unsigned __int8)v2->m_eInEqualityOperator.mValue,
                   v2->mTimeOfDay,
                   v3->m_SecondsSinceMidnight);
  return (char)v3;
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
  CharacterPhysicsCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CharacterPhysicsCondition::`vftable;
  v1->mMode.mValue = 5;
}

// File Line: 16187
// RVA: 0x27FD40
bool __fastcall CharacterPhysicsCondition::Match(CharacterPhysicsCondition *this, ActionContext *pContext)
{
  CharacterPhysicsCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID)),
                                                 v5 = v6) : (v5 = v3->m_Components.p[27].m_pComponent),
        v5) )
  {
    result = (unsigned __int8)v2->mMode.mValue == HIDWORD(v5[8].m_BoundComponentHandles.mNode.mPrev);
  }
  else
  {
    result = 0;
  }
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
  SocialGreetSuccessfulCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SocialGreetSuccessfulCondition::`vftable;
}

// File Line: 16222
// RVA: 0x28A450
bool __fastcall SocialGreetSuccessfulCondition::Match(SocialGreetSuccessfulCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[45].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v4 && BYTE4(v4[12].m_pSimObject) & 2 )
      result = 1;
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
bool __fastcall SocialRequiresInteractionPointSyncCondition::Match(SocialRequiresInteractionPointSyncCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[45].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v4 && BYTE4(v4[3].m_SafePointerList.mNode.mPrev) & 0x20 )
      result = 1;
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
  SocialChargeSuccessfulCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SocialChargeSuccessfulCondition::`vftable;
}

// File Line: 16276
// RVA: 0x289DD0
bool __fastcall SocialChargeSuccessfulCondition::Match(SocialChargeSuccessfulCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[45].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v4 && BYTE4(v4[12].m_pSimObject) & 8 )
      result = 1;
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
  SocialRequiresFastTalkCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SocialRequiresFastTalkCondition::`vftable;
}

// File Line: 16303
// RVA: 0x28A5A0
bool __fastcall SocialRequiresFastTalkCondition::Match(SocialRequiresFastTalkCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[45].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v4 && BYTE4(v4[3].m_BoundComponentHandles.mNode.mPrev) )
      result = 1;
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
void __fastcall SocialCombatFastTalkSucceededCondition::SocialCombatFastTalkSucceededCondition(SocialCombatFastTalkSucceededCondition *this)
{
  SocialCombatFastTalkSucceededCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SocialCombatFastTalkSucceededCondition::`vftable;
}

// File Line: 16330
// RVA: 0x289E80
bool __fastcall SocialCombatFastTalkSucceededCondition::Match(SocialCombatFastTalkSucceededCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( pContext
    && (v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID))) : (v4 = v2->m_Components.p[5].m_pComponent)) : (v4 = v2->m_Components.p[5].m_pComponent),
        v4) )
  {
    result = (BYTE2(v4[32].m_BoundComponentHandles.mNode.mPrev) >> 1) & 1;
  }
  else
  {
    result = 0;
  }
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
  SocialFastTalkOccurredCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SocialFastTalkOccurredCondition::`vftable;
}

// File Line: 16358
// RVA: 0x28A3A0
bool __fastcall SocialFastTalkOccurredCondition::Match(SocialFastTalkOccurredCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[45].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v4 && BYTE5(v4[3].m_SafePointerList.mNode.mPrev) & 2 )
      result = 1;
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
char __fastcall SocialFaceActionRequiresGreetCondition::Match(SocialFaceActionRequiresGreetCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  if ( !pContext )
    return 0;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = v2->m_Components.p[45].m_pComponent;
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
    else
      v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID);
  }
  else
  {
    v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
  }
  if ( !v4 )
    return 0;
  if ( BYTE4(v4[12].m_pSimObject) & 1 || BYTE4(v4[3].m_BoundComponentHandles.mNode.mPrev) )
    return 1;
  return 0;
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
bool __fastcall SocialFaceActionAutoChargeCondition::Match(SocialFaceActionAutoChargeCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( pContext
    && (v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = v2->m_Components.p[45].m_pComponent),
        v4) )
  {
    result = (BYTE4(v4[3].m_SafePointerList.mNode.mPrev) >> 3) & 1;
  }
  else
  {
    result = 0;
  }
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
bool __fastcall SocialFaceActionUseConfirmationDialogCondition::Match(SocialFaceActionUseConfirmationDialogCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( pContext
    && (v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = v2->m_Components.p[45].m_pComponent),
        v4) )
  {
    result = (BYTE4(v4[3].m_SafePointerList.mNode.mPrev) >> 2) & 1;
  }
  else
  {
    result = 0;
  }
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
bool __fastcall SocialFaceActionGetConfirmationDialogConfirmedCondition::Match(SocialFaceActionGetConfirmationDialogConfirmedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( pContext
    && (v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = v2->m_Components.p[45].m_pComponent),
        v4) )
  {
    result = (BYTE4(v4[3].m_SafePointerList.mNode.mPrev) >> 1) & 1;
  }
  else
  {
    result = 0;
  }
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
  SocialFaceActionStateCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  bool result; // al

  v2 = this;
  if ( pContext
    && (v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::FaceActionComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID)),
                                                 v5 = v6) : (v5 = v3->m_Components.p[45].m_pComponent),
        v5) )
  {
    result = (unsigned __int8)v2->mFaceActionState.mValue == LODWORD(v5[3].m_SafePointerList.mNode.mNext);
  }
  else
  {
    result = 0;
  }
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
bool __fastcall SocialFaceActionEnabledCondition::Match(SocialFaceActionEnabledCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::FaceActionComponent *v4; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::FaceActionComponent *)v2->m_Components.p[45].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v2,
                                           UFG::FaceActionComponent::_TypeUID);
      else
        v4 = (UFG::FaceActionComponent *)((v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v2,
                                                             UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v2->vfptr,
                                                                                                     UFG::FaceActionComponent::_TypeUID));
    }
    else
    {
      v4 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v4 && UFG::FaceActionComponent::IsFaceActionEnabled(v4) )
      result = 1;
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
bool __fastcall SocialRequiresInteractionAreaCheckCondition::Match(SocialRequiresInteractionAreaCheckCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  if ( !pContext )
    return 0;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[45].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID);
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v4 && BYTE4(v4[3].m_SafePointerList.mNode.mPrev) & 0x40 )
      result = 1;
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
_BOOL8 __fastcall UISocialChargeHappenedCondition::Match(UISocialChargeHappenedCondition *this, ActionContext *pContext)
{
  _BOOL8 result; // rax

  result = 0i64;
  if ( UFG::UIHKSocialActionManager::mThis )
    result = UFG::UIHKSocialActionManager::SocialAction.mChargeHappened;
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
bool __fastcall SocialIsTargetStandingSufficientCondition::Match(SocialIsTargetStandingSufficientCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::FaceActionComponent *v4; // rax
  bool result; // al

  if ( pContext
    && (v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::FaceActionComponent::_TypeUID)) : (v4 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::FaceActionComponent::_TypeUID))) : (v4 = (UFG::FaceActionComponent *)v2->m_Components.p[45].m_pComponent),
        v4) )
  {
    result = UFG::FaceActionComponent::IsTargetStandingSufficient(v4);
  }
  else
  {
    result = 0;
  }
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
  FactionClassCondition *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax
  bool result; // al

  v2 = this;
  if ( pContext
    && (v3 = (UFG::SimObjectCVBase *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) : (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v5 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3))) : (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)),
        v5) )
  {
    result = v5->m_eFactionClass == v2->mFactionClass.mValue;
  }
  else
  {
    result = 0;
  }
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
  GameSliceIsActiveCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&GameSliceIsActiveCondition::`vftable;
  v1->mGameSliceId.mUID = -1;
}

// File Line: 16650
// RVA: 0x281DA0
UFG::qBaseTreeRB *__fastcall GameSliceIsActiveCondition::Match(GameSliceIsActiveCondition *this, ActionContext *pContext)
{
  UFG::qSymbol *v2; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::qBaseTreeRB *result; // rax

  v2 = &this->mGameSliceId;
  v3 = UFG::ProgressionTracker::Instance();
  result = UFG::ProgressionTracker::Find(v3, v2, 0);
  if ( result )
    result = (UFG::qBaseTreeRB *)(LODWORD(result[3].mNULL.mChild[1]) == 4);
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
  LastCompletedMissionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&LastCompletedMissionCondition::`vftable;
  v1->mMissionId.mUID = -1;
}

// File Line: 16681
// RVA: 0x2852E0
bool __fastcall LastCompletedMissionCondition::Match(LastCompletedMissionCondition *this, ActionContext *context)
{
  LastCompletedMissionCondition *v2; // rbx
  UFG::GameStatTracker *v3; // rax

  v2 = this;
  v3 = UFG::GameStatTracker::Instance();
  return UFG::GameStatTracker::GetStat(v3, LastCompletedMission)->mValue.mUID == v2->mMissionId.mUID;
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
  UIPDAStateCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&UIPDAStateCondition::`vftable;
  v1->mState.mValue = 0;
}

// File Line: 16716
// RVA: 0x290B40
bool __fastcall UIPDAStateCondition::Match(UIPDAStateCondition *this, ActionContext *pContext)
{
  int v2; // ebx

  v2 = this->mState.mValue;
  return v2 == (unsigned int)UFG::UIHK_PDAWidget::GetState();
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
  IsPlayerUsingKeyboardCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsPlayerUsingKeyboardCondition::`vftable;
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
  CollectibleIsCollectedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollectibleIsCollectedCondition::`vftable;
  v1->mTargetType.mValue = 0;
}

// File Line: 16782
// RVA: 0x280020
bool __fastcall CollectibleIsCollectedCondition::Match(CollectibleIsCollectedCondition *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  __int64 v3; // rdi
  ActionContext *v4; // rbx
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::CollectibleComponent *v16; // rax

  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v3 = this->mTargetType.mValue;
  v4 = pContext;
  if ( !v2 )
    goto LABEL_42;
  v5 = v2->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v2->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  else
  {
    v6 = v2->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    goto LABEL_42;
  v7 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v7->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v7 = (UFG::SimObjectGame *)v9;
    }
    else
    {
      v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
    }
  }
  v10 = ((__int64 (*)(void))v7->vfptr[15].__vecDelDtor)();
  if ( v10 )
  {
    v11 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v10 + 96) + v3 + 8) + *(_QWORD *)(v10 + 88) + 40);
    if ( v11 )
    {
      v12 = *(UFG::SimObjectGame **)(*(_QWORD *)(v11 + 80) + 96i64);
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID);
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID);
          else
            v14 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::CollectibleComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::CollectibleComponent::_TypeUID);
        }
        if ( v14 )
          return ((__int64 (__fastcall *)(UFG::SimComponent *))v14->vfptr[19].__vecDelDtor)(v14);
      }
    }
  }
  else
  {
LABEL_42:
    v16 = UFG::CollectibleComponent::GetCollectibleComponent(v4->mSimObject.m_pPointer);
    if ( v16 )
      return ((__int64 (__fastcall *)(UFG::CollectibleComponent *))v16->vfptr[19].__vecDelDtor)(v16);
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
  HasClothingBuffCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&HasClothingBuffCondition::`vftable;
  v1->mBuffType.mValue = 0;
}

// File Line: 16847
// RVA: 0x281F40
bool __fastcall HasClothingBuffCondition::Match(HasClothingBuffCondition *this, ActionContext *pContext)
{
  int v2; // ebx
  UFG::GameStatTracker *v3; // rax

  v2 = (unsigned __int8)this->mBuffType.mValue;
  v3 = UFG::GameStatTracker::Instance();
  return v2 == (unsigned int)UFG::GameStatTracker::GetStat(v3, ClothingSetBuff);
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
void __fastcall CouldShootSomeoneUnintendedCondition::CouldShootSomeoneUnintendedCondition(CouldShootSomeoneUnintendedCondition *this)
{
  CouldShootSomeoneUnintendedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CouldShootSomeoneUnintendedCondition::`vftable;
  *(_WORD *)&v1->mIncludePedestrians = 256;
}

// File Line: 16891
// RVA: 0x2805D0
bool __fastcall CouldShootSomeoneUnintendedCondition::Match(CouldShootSomeoneUnintendedCondition *this, ActionContext *pContext)
{
  CouldShootSomeoneUnintendedCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AimingBaseComponent *v5; // rax
  bool result; // al

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AimingBaseComponent::_TypeUID)) : (v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID))) : (v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID))) : (v5 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AimingBaseComponent::_TypeUID))) : (v5 = (UFG::AimingBaseComponent *)v3->m_Components.p[47].m_pComponent),
        v5) )
  {
    result = UFG::AimingBaseComponent::CouldShootSomeoneUnintended(
               v5,
               v2->mIncludePedestrians != 0,
               v2->mIncludeHostages != 0);
  }
  else
  {
    result = 0;
  }
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
void __fastcall IsSocialConversationActiveCondition::IsSocialConversationActiveCondition(IsSocialConversationActiveCondition *this)
{
  IsSocialConversationActiveCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&IsSocialConversationActiveCondition::`vftable;
  v1->mFaceActionResult.mValue = 0;
}

// File Line: 16925
// RVA: 0x284C60
bool __fastcall IsSocialConversationActiveCondition::Match(IsSocialConversationActiveCondition *this, ActionContext *pContext)
{
  IsSocialConversationActiveCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::FaceActionComponent *v5; // rax
  bool result; // al

  v2 = this;
  if ( !pContext )
    return 0;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  result = 0;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v3,
                                           UFG::FaceActionComponent::_TypeUID);
      else
        v5 = (UFG::FaceActionComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v3,
                                                             UFG::FaceActionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                     (UFG::SimObject *)&v3->vfptr,
                                                                                                     UFG::FaceActionComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID);
    }
    if ( v5
      && UFG::FaceActionComponent::IsSocialConversationActive(
           v5,
           (UFG::eSocialInteractionResultEnum)(unsigned __int8)v2->mFaceActionResult.mValue) )
    {
      result = 1;
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
void __fastcall SocialConversationHasActionRequestsCondition::SocialConversationHasActionRequestsCondition(SocialConversationHasActionRequestsCondition *this)
{
  SocialConversationHasActionRequestsCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SocialConversationHasActionRequestsCondition::`vftable;
  v1->mFaceActionResult.mValue = 0;
}

// File Line: 16958
// RVA: 0x289F10
bool __fastcall SocialConversationHasActionRequestsCondition::Match(SocialConversationHasActionRequestsCondition *this, ActionContext *pContext)
{
  SocialConversationHasActionRequestsCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::FaceActionComponent *v5; // rax
  bool result; // al

  v2 = this;
  if ( pContext
    && (v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer) != 0i64
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::FaceActionComponent::_TypeUID)) : (v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID))) : (v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID))) : (v5 = (UFG::FaceActionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceActionComponent::_TypeUID))) : (v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent),
        v5) )
  {
    result = UFG::FaceActionComponent::SocialConversationHasActionRequests(
               v5,
               (UFG::eSocialInteractionResultEnum)(unsigned __int8)v2->mFaceActionResult.mValue);
  }
  else
  {
    result = 0;
  }
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::CharacterEffectsComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterEffectsComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterEffectsComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::CharacterEffectsComponent::_TypeUID))) : (v4 = v2->m_Components.p[38].m_pComponent),
        v4) )
  {
    result = BYTE4(v4[5].m_pSimObject);
  }
  else
  {
    result = 0;
  }
  return result;
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
bool __fastcall TargetIsSittingConversationCondition::Match(TargetIsSittingConversationCondition *this, ActionContext *context)
{
  TargetIsSittingConversationCondition *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::InterestPoint *v9; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 0;
  v7 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)((unsigned __int8)v2->m_TargetType.mValue
                                               + *(_QWORD *)&v5[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&v5[1].m_TypeUID
                          + 40);
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
    {
      v9 = (UFG::InterestPoint *)v7->m_Components.p[10].m_pComponent;
    }
    else if ( (v8 >> 12) & 1 )
    {
      v9 = (UFG::InterestPoint *)v7->m_Components.p[3].m_pComponent;
    }
    else
    {
      v9 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v7, UFG::InterestPoint::_TypeUID);
    }
  }
  else
  {
    v9 = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
  }
  return v9 && UFG::InterestPoint::GetIsSittingConversation(v9);
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
_BOOL8 __fastcall IsPossessedPedModeEnabledCondition::Match(IsPossessedPedModeEnabledCondition *this, ActionContext *context)
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
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimObjectCharacterPropertiesComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) : (v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v4 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2))) : (v4 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2)),
        v4) )
  {
    result = *((_BYTE *)v4 + 248) & 1;
  }
  else
  {
    result = 0;
  }
  return result;
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
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::NavComponent *v4; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v2
    && ((v3 = v2->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::NavComponent::_TypeUID)) : (v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID))) : (v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID))) : (v4 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID))) : (v4 = (UFG::NavComponent *)v2->m_Components.p[36].m_pComponent),
        v4) )
  {
    result = UFG::NavComponent::HasDestination(v4);
  }
  else
  {
    result = 0;
  }
  return result;
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
  TargetAimingDirectionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetAimingDirectionCondition::`vftable;
  v1->mOriginTargetType = 22;
  v1->mTowardsTargetType = 1;
  v1->mInEqualityOperator.mValue = 3;
  v1->mAngle = 0.78539819;
}

// File Line: 17165
// RVA: 0x28B830
char __fastcall TargetAimingDirectionCondition::Match(TargetAimingDirectionCondition *this, ActionContext *context)
{
  TargetAimingDirectionCondition *rsi1; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // dx
  __int64 v6; // rdx
  __int64 v7; // r8
  UFG::SimObject *v8; // r9
  __int64 v9; // rbx
  unsigned __int16 v10; // cx
  UFG::AimingBaseComponent *v11; // rdi
  unsigned int v12; // edx
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // rax
  bool v15; // zf
  UFG::TransformNodeComponent *v16; // rbx
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-28h]
  UFG::qVector3 vAimDirection; // [rsp+30h] [rbp-18h]

  rsi1 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = *(_QWORD *)&v4[1].m_Flags;
  v7 = *(_QWORD *)&v4[1].m_TypeUID;
  v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)((unsigned int)rsi1->mOriginTargetType + v6 + 8) + v7 + 40);
  v9 = *(_QWORD *)(56i64 * *(unsigned __int8 *)((unsigned int)rsi1->mTowardsTargetType + v6 + 8) + v7 + 40);
  if ( v8 && v9 )
  {
    v10 = v8->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = (UFG::AimingBaseComponent *)v8->m_Components.p[47].m_pComponent;
LABEL_23:
      UFG::AimingBaseComponent::GetAimDirection(v11, &vAimDirection, 0i64);
      v16 = *(UFG::TransformNodeComponent **)(v9 + 88);
      UFG::TransformNodeComponent::UpdateWorldTransform(v16);
      v17 = v16->mWorldTransform.v3.z - v11->m_vAimOriginPosition.z;
      v18 = v16->mWorldTransform.v3.y - v11->m_vAimOriginPosition.y;
      v2.x = v16->mWorldTransform.v3.x - v11->m_vAimOriginPosition.x;
      v2.y = v18;
      v2.z = v17;
      v19 = UFG::qAngleBetween(&vAimDirection, &v2);
      return CompareFloat((UFG::InEqualityOperator)(unsigned __int8)rsi1->mInEqualityOperator.mValue, rsi1->mAngle, v19);
    }
    if ( (v10 & 0x8000u) != 0 || (v10 >> 13) & 1 )
    {
      v12 = UFG::AimingBaseComponent::_TypeUID;
      v13 = (UFG::SimObjectGame *)v8;
    }
    else
    {
      v12 = UFG::AimingBaseComponent::_TypeUID;
      v15 = ((v10 >> 12) & 1) == 0;
      v13 = (UFG::SimObjectGame *)v8;
      if ( v15 )
      {
        v14 = UFG::SimObject::GetComponentOfType(v8, UFG::AimingBaseComponent::_TypeUID);
        goto LABEL_22;
      }
    }
    v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, v12);
LABEL_22:
    v11 = (UFG::AimingBaseComponent *)v14;
    goto LABEL_23;
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
void __fastcall NumCollectiblesCollectedCondition::NumCollectiblesCollectedCondition(NumCollectiblesCollectedCondition *this)
{
  NumCollectiblesCollectedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&NumCollectiblesCollectedCondition::`vftable;
  v1->mTypeName.mUID = -1;
  v1->mInEqualityOperator.mValue = 3;
  v1->mTarget = 0;
}

// File Line: 17225
// RVA: 0x285EE0
bool __fastcall NumCollectiblesCollectedCondition::Match(NumCollectiblesCollectedCondition *this, ActionContext *context)
{
  NumCollectiblesCollectedCondition *v2; // rbx
  UFG::GameStat::MapBoolStat v3; // edi
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapBool *v5; // rax
  int v6; // eax

  v2 = this;
  v3 = UFG::GameStat::GetMapBoolStatEnum(&this->mTypeName, 1);
  if ( v3 == 93 )
    return 0;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetMapBool(v4, v3);
  v6 = UFG::PersistentData::MapBool::GetTrueCount(v5);
  return CompareInt((UFG::InEqualityOperator)(unsigned __int8)v2->mInEqualityOperator.mValue, v2->mTarget, v6);
}

