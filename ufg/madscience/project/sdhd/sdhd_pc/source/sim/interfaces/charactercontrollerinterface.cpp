// File Line: 16
// RVA: 0x1543DA0
__int64 dynamic_initializer_for__UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList__);
}

// File Line: 17
// RVA: 0x52C950
UFG::ComponentIDDesc *__fastcall UFG::CharacterControllerInterface::GetDesc(UFG::CharacterControllerInterface *this)
{
  return &UFG::CharacterControllerInterface::_TypeIDesc;
}

// File Line: 21
// RVA: 0x5161C0
void __fastcall UFG::CharacterControllerInterface::CharacterControllerInterface(UFG::CharacterControllerInterface *this, unsigned int name_uid)
{
  UFG::CharacterControllerInterface *v2; // rdi
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v3; // rbx
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterControllerInterface::`vftable';
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v2->m_pActionTreeComponent);
  v4 = UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList.mNode.mPrev;
  UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList.mNode.mPrev->mNext = (UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *)&UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList;
  UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList.mNode.mPrev = (UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::CharacterControllerInterface::_CharacterControllerInterfaceTypeUID,
    "CharacterControllerInterface");
}

// File Line: 27
// RVA: 0x51AE90
void __fastcall UFG::CharacterControllerInterface::~CharacterControllerInterface(UFG::CharacterControllerInterface *this)
{
  UFG::CharacterControllerInterface *v1; // rdi
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v2; // rbx
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v3; // rcx
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v4; // rax
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v5; // rcx
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterControllerInterface::`vftable';
  if ( this == UFG::CharacterControllerInterface::s_CharacterControllerInterfacepCurrentIterator )
    UFG::CharacterControllerInterface::s_CharacterControllerInterfacepCurrentIterator = (UFG::CharacterControllerInterface *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActionTreeComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 32
// RVA: 0x53D470
void __fastcall UFG::CharacterControllerInterface::OnAttach(UFG::CharacterControllerInterface *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v2; // r8
  UFG::SimObject *v3; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx

  v2 = &this->m_pActionTreeComponent;
  v3 = object;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v4 = this->m_pActionTreeComponent.mNext;
    v5 = v2->mPrev;
    v5->mNext = v4;
    v4->mPrev = v5;
    v2->m_pSimComponent = 0i64;
LABEL_7:
    v2->m_pSimObject = 0i64;
    v2->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    v2->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->mPrev != v2
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v6 = this->m_pActionTreeComponent.mNext;
    v7 = v2->mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v2->m_Changed = 1;
  v2->m_pSimObject = v3;
  v2->m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(v2, v3);
}

// File Line: 37
// RVA: 0x540B20
void __fastcall UFG::CharacterControllerInterface::OnDetach(UFG::PropInteractComponent *this)
{
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v1; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  v1 = &this->mActionTreeComponent;
  if ( this->mActionTreeComponent.m_pSimComponent )
  {
    v2 = this->mActionTreeComponent.mNext;
    v3 = v1->mPrev;
    v3->mNext = v2;
    v2->mPrev = v3;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->m_Changed = 1;
    v1->m_pSimComponent = 0i64;
    v1->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->mActionTreeComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v1->mPrev != v1
       || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)this->mActionTreeComponent.mNext != &this->mActionTreeComponent) )
    {
      v4 = this->mActionTreeComponent.mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->m_pSimObject = 0i64;
    }
    v1->m_Changed = 1;
  }
}

// File Line: 42
// RVA: 0x54D910
void __fastcall UFG::CharacterControllerInterface::SetIntentionOnActionTreeComponent(UFG::CharacterControllerInterface *this, Intention *intention)
{
  UFG::SimComponent *v2; // rcx

  v2 = this->m_pActionTreeComponent.m_pSimComponent;
  if ( v2 )
    Intention::operator=((Intention *)&v2[8].m_TypeUID, intention);
}

// File Line: 55
// RVA: 0x5425C0
char __fastcall UFG::CharacterControllerInterface::PlayActionNode(UFG::CharacterControllerInterface *this, const char *node_name)
{
  const char *v2; // rbx
  UFG::CharacterControllerInterface *v3; // rdi
  ActionNode *v4; // rax
  int v5; // edx
  int v7; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h]

  v2 = node_name;
  v3 = this;
  if ( !this->m_pActionTreeComponent.m_pSimComponent )
    return 0;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, node_name);
  v4 = ActionNode::Find(&absolutePath, 0i64);
  if ( !v4 )
  {
    UFG::qPrintf("WARNING: CharacterControllerInterface::PlayActionNode(): Couldn't find ActionNode '%s'\n", v2);
    v7 = absolutePath.mPath.mCount;
    if ( absolutePath.mPath.mCount >= 0 )
    {
      if ( absolutePath.mPath.mData.mOffset
        && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
        v7 = absolutePath.mPath.mCount;
      }
      absolutePath.mPath.mData.mOffset = 0i64;
      absolutePath.mPath.mCount = v7 & 0x80000000;
    }
    return 0;
  }
  ActionController::Play((ActionController *)&v3->m_pActionTreeComponent.m_pSimComponent[3], v4, 0);
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

