// File Line: 16
// RVA: 0x1543DA0
__int64 dynamic_initializer_for__UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList__);
}

// File Line: 17
// RVA: 0x52C950
UFG::ComponentIDDesc *__fastcall UFG::CharacterControllerInterface::GetDesc(UFG::CharacterControllerInterface *this)
{
  return &UFG::CharacterControllerInterface::_TypeIDesc;
}

// File Line: 21
// RVA: 0x5161C0
void __fastcall UFG::CharacterControllerInterface::CharacterControllerInterface(
        UFG::CharacterControllerInterface *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface>;
  this->mNext = &this->UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterControllerInterface::`vftable;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->m_pActionTreeComponent);
  mPrev = UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList.mNode.mPrev;
  UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *)&UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList;
  UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList.mNode.mPrev = &this->UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface>;
  UFG::SimComponent::AddType(
    this,
    UFG::CharacterControllerInterface::_CharacterControllerInterfaceTypeUID,
    "CharacterControllerInterface");
}

// File Line: 27
// RVA: 0x51AE90
void __fastcall UFG::CharacterControllerInterface::~CharacterControllerInterface(
        UFG::CharacterControllerInterface *this)
{
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v2; // rbx
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *mPrev; // rcx
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *mNext; // rax
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v5; // rcx
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterControllerInterface::`vftable;
  if ( this == UFG::CharacterControllerInterface::s_CharacterControllerInterfacepCurrentIterator )
    UFG::CharacterControllerInterface::s_CharacterControllerInterfacepCurrentIterator = (UFG::CharacterControllerInterface *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActionTreeComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 32
// RVA: 0x53D470
void __fastcall UFG::CharacterControllerInterface::OnAttach(
        UFG::CharacterControllerInterface *this,
        UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx

  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    mNext = this->m_pActionTreeComponent.mNext;
    mPrev = p_m_pActionTreeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pActionTreeComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_m_pActionTreeComponent->m_pSimObject = 0i64;
    p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_8;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v6 = this->m_pActionTreeComponent.mNext;
    v7 = p_m_pActionTreeComponent->mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pActionTreeComponent->m_Changed = 1;
  p_m_pActionTreeComponent->m_pSimObject = object;
  p_m_pActionTreeComponent->m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    p_m_pActionTreeComponent,
    object);
}

// File Line: 37
// RVA: 0x540B20
void __fastcall UFG::CharacterControllerInterface::OnDetach(UFG::PropInteractComponent *this)
{
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_mActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  p_mActionTreeComponent = &this->mActionTreeComponent;
  if ( this->mActionTreeComponent.m_pSimComponent )
  {
    mNext = this->mActionTreeComponent.mNext;
    mPrev = p_mActionTreeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mActionTreeComponent->mNext = p_mActionTreeComponent;
    p_mActionTreeComponent->mPrev = p_mActionTreeComponent;
    p_mActionTreeComponent->m_Changed = 1;
    p_mActionTreeComponent->m_pSimComponent = 0i64;
    p_mActionTreeComponent->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->mActionTreeComponent.m_pSimObject
      && (p_mActionTreeComponent->mPrev != p_mActionTreeComponent
       || this->mActionTreeComponent.mNext != &this->mActionTreeComponent) )
    {
      v4 = this->mActionTreeComponent.mNext;
      v5 = p_mActionTreeComponent->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      p_mActionTreeComponent->mNext = p_mActionTreeComponent;
      p_mActionTreeComponent->mPrev = p_mActionTreeComponent;
      p_mActionTreeComponent->m_pSimObject = 0i64;
    }
    p_mActionTreeComponent->m_Changed = 1;
  }
}

// File Line: 42
// RVA: 0x54D910
void __fastcall UFG::CharacterControllerInterface::SetIntentionOnActionTreeComponent(
        UFG::CharacterControllerInterface *this,
        Intention *intention)
{
  UFG::SimComponent *m_pSimComponent; // rcx

  m_pSimComponent = this->m_pActionTreeComponent.m_pSimComponent;
  if ( m_pSimComponent )
    Intention::operator=((Intention *)&m_pSimComponent[8].m_TypeUID, intention);
}

// File Line: 55
// RVA: 0x5425C0
char __fastcall UFG::CharacterControllerInterface::PlayActionNode(
        UFG::CharacterControllerInterface *this,
        const char *node_name)
{
  ActionNodePlayable *v4; // rax
  int v5; // edx
  int mCount; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h] BYREF

  if ( !this->m_pActionTreeComponent.m_pSimComponent )
    return 0;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, node_name);
  v4 = (ActionNodePlayable *)ActionNode::Find(&absolutePath, 0i64);
  if ( !v4 )
  {
    UFG::qPrintf("WARNING: CharacterControllerInterface::PlayActionNode(): Couldnt find ActionNode %s\n", node_name);
    mCount = absolutePath.mPath.mCount;
    if ( absolutePath.mPath.mCount >= 0 )
    {
      if ( absolutePath.mPath.mData.mOffset
        && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
        mCount = absolutePath.mPath.mCount;
      }
      absolutePath.mPath.mData.mOffset = 0i64;
      absolutePath.mPath.mCount = mCount & 0x80000000;
    }
    return 0;
  }
  ActionController::Play((ActionController *)&this->m_pActionTreeComponent.m_pSimComponent[3], v4, 0);
  v5 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
        v5 = absolutePath.mPath.mCount;
      }
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v5 & 0x80000000;
  }
  return 1;
}

