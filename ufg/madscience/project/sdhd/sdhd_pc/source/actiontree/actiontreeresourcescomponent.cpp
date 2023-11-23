// File Line: 23
// RVA: 0x297270
UFG::ComponentIDDesc *__fastcall UFG::ActionTreeResourcesComponent::GetDesc(UFG::ActionTreeResourcesComponent *this)
{
  return &UFG::ActionTreeResourcesComponent::_TypeIDesc;
}

// File Line: 24
// RVA: 0x1493FB0
__int64 dynamic_initializer_for__UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList__);
}

// File Line: 28
// RVA: 0x1493FD0
__int64 dynamic_initializer_for__UFG::ActionTreeResourcesComponent::smUpdateList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActionTreeResourcesComponent::smUpdateList__);
}

// File Line: 36
// RVA: 0x295DE0
void __fastcall UFG::ActionTreeResourcesComponent::ActionTreeResourcesComponent(
        UFG::ActionTreeResourcesComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *mPrev; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v4; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActionTreeResourcesComponent::`vftable;
  this->mAnimationBankRequests.mNode.mPrev = &this->mAnimationBankRequests.mNode;
  this->mAnimationBankRequests.mNode.mNext = &this->mAnimationBankRequests.mNode;
  this->m_pActionTreeComponent.mPrev = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.m_pPointer = 0i64;
  mPrev = UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList.mNode.mPrev;
  UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *)&UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList;
  UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::ActionTreeResourcesComponent::_ActionTreeResourcesComponentTypeUID,
    "ActionTreeResourcesComponent");
  v4 = UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev;
  UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mPrev = v4;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&UFG::ActionTreeResourcesComponent::smUpdateList;
  UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
}

// File Line: 45
// RVA: 0x2965C0
void __fastcall UFG::ActionTreeResourcesComponent::~ActionTreeResourcesComponent(
        UFG::ActionTreeResourcesComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v7; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v8; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v9; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v10; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *v11; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *v12; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActionTreeResourcesComponent::`vftable;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
  {
    mPrev = p_m_pActionTreeComponent->mPrev;
    mNext = p_m_pActionTreeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  }
  p_m_pActionTreeComponent->m_pPointer = 0i64;
  v5 = p_m_pActionTreeComponent->mPrev;
  v6 = p_m_pActionTreeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
  p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  UFG::qList<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList,1,0>::DeleteNodes(&this->mAnimationBankRequests);
  v7 = this->mAnimationBankRequests.mNode.mPrev;
  v8 = this->mAnimationBankRequests.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mAnimationBankRequests.mNode.mPrev = &this->mAnimationBankRequests.mNode;
  this->mAnimationBankRequests.mNode.mNext = &this->mAnimationBankRequests.mNode;
  v9 = this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mPrev;
  v10 = this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
  v11 = this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mPrev;
  v12 = this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 50
// RVA: 0x297430
UFG::ActionTreeResourcesComponent *__fastcall UFG::ActionTreeResourcesComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  char *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h] BYREF

  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x88ui64, "ActionTreeResourcesComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::ActionTreeResourcesComponent::ActionTreeResourcesComponent(
      (UFG::ActionTreeResourcesComponent *)v3,
      pSceneObj->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v7 = 30;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  return (UFG::ActionTreeResourcesComponent *)v5;
}

// File Line: 58
// RVA: 0x297DA0
void __fastcall UFG::ActionTreeResourcesComponent::Update(UFG::ActionTreeResourcesComponent *this, float delta_sec)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::ActionTreeResourcesComponent::AnimationBankRequest *p_mNext; // rbx
  UFG::ActionTreeResourcesComponent *v12; // rdi
  UFG::SimComponent *m_pPointer; // rcx
  ActionNodePlayable *mOwnerNode; // rdx
  ActionController *v15; // rcx
  char v16; // al
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v17; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v18; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v19; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v20; // rax

  if ( !this->m_pActionTreeComponent.m_pPointer )
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pSimObject,
                                  UFG::ActionTreeComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
      }
      else
      {
        m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
    if ( this->m_pActionTreeComponent.m_pPointer )
    {
      mPrev = p_m_pActionTreeComponent->mPrev;
      mNext = this->m_pActionTreeComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
      this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    }
    this->m_pActionTreeComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v10 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pActionTreeComponent;
      p_m_pActionTreeComponent->mPrev = v10;
      this->m_pActionTreeComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pActionTreeComponent;
    }
  }
  p_mNext = (UFG::ActionTreeResourcesComponent::AnimationBankRequest *)&this->mAnimationBankRequests.mNode.mNext[-2].mNext;
  if ( p_mNext != (UFG::ActionTreeResourcesComponent::AnimationBankRequest *)&this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext )
  {
    do
    {
      v12 = (UFG::ActionTreeResourcesComponent *)&p_mNext->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mNext[-2].mNext;
      if ( p_mNext->mKeepAlive )
        goto LABEL_28;
      m_pPointer = this->m_pActionTreeComponent.m_pPointer;
      if ( m_pPointer )
      {
        mOwnerNode = (ActionNodePlayable *)p_mNext->mOwnerNode;
        v15 = (ActionController *)&m_pPointer[3];
        v16 = mOwnerNode
            ? ActionController::IsPlayingFullPath(v15, mOwnerNode, 1)
            : ActionController::IsPlayingFullPath(v15, &p_mNext->mActionPath, 1);
        if ( v16 )
          p_mNext->mKeepAlive = 1;
      }
      if ( p_mNext->mKeepAlive )
      {
LABEL_28:
        p_mNext->mKeepAlive = 0;
      }
      else
      {
        v17 = p_mNext->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mPrev;
        v18 = p_mNext->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mNext;
        v17->mNext = v18;
        v18->mPrev = v17;
        p_mNext->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mPrev = &p_mNext->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>;
        p_mNext->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mNext = &p_mNext->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>;
        UFG::ActionTreeResourcesComponent::AnimationBankRequest::~AnimationBankRequest(p_mNext);
        UFG::qMemoryPool2::Free(&gActionTreeMemoryPool, (char *)p_mNext, 0x98ui64);
      }
      p_mNext = (UFG::ActionTreeResourcesComponent::AnimationBankRequest *)v12;
    }
    while ( v12 != (UFG::ActionTreeResourcesComponent *)&this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext );
  }
  if ( (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> **)&this->mAnimationBankRequests.mNode.mNext[-2].mNext == &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext )
  {
    v19 = this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mPrev;
    v20 = this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
    this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
  }
}

// File Line: 111
// RVA: 0x297F80
void __fastcall UFG::ActionTreeResourcesComponent::UpdateAll(float delta_sec)
{
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *p_mNode; // rcx
  UFG::qList<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList,1,0> *v2; // rbx

  p_mNode = UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mNext - 5;
  if ( (UFG::qList<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList,1,0> *)&UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mNext[-5] != &UFG::ActionTreeResourcesComponent::smUpdateList - 5 )
  {
    do
    {
      v2 = (UFG::qList<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList,1,0> *)&p_mNode[5].mNext[-5];
      if ( ((__int64)p_mNode[2].mPrev & 3) == 1 )
        UFG::ActionTreeResourcesComponent::Update((UFG::ActionTreeResourcesComponent *)p_mNode, delta_sec);
      p_mNode = &v2->mNode;
    }
    while ( v2 != &UFG::ActionTreeResourcesComponent::smUpdateList - 5 );
  }
}

// File Line: 128
// RVA: 0x297650
bool __fastcall UFG::ActionTreeResourcesComponent::RequestAnimationBank(
        UFG::ActionTreeResourcesComponent *this,
        ActionPath *actionPath,
        ActionNode *ownerNode,
        const bool doTheRequest,
        UFG::qSymbolUC *symAnimBank,
        UFG::eAnimationPriorityEnum priority)
{
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **Request; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **v10; // rbx
  char *v11; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **v12; // rax
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *mPrev; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v17; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v18; // rax
  AnimationGroup *v19; // rcx
  AnimationDataBase *Instance; // rax
  AnimationGroup *AnimBank; // rax

  if ( doTheRequest )
  {
    Request = UFG::ActionTreeResourcesComponent::FindRequest(this, actionPath, symAnimBank);
    v10 = Request;
    if ( Request )
    {
      *((_BYTE *)Request + 144) = 1;
      goto LABEL_21;
    }
    v11 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x98ui64, "AnimationBankRequest", 0i64, 1u);
    if ( v11 )
    {
      UFG::ActionTreeResourcesComponent::AnimationBankRequest::AnimationBankRequest(
        (UFG::ActionTreeResourcesComponent::AnimationBankRequest *)v11,
        actionPath,
        ownerNode,
        symAnimBank,
        priority);
      v10 = v12;
    }
    else
    {
      v10 = 0i64;
    }
    if ( v10 )
    {
      m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 m_pSimObject,
                                                                 UFG::PowerManagementComponent::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                                 m_pSimObject,
                                                                 UFG::PowerManagementComponent::_TypeUID);
        if ( ComponentOfTypeHK )
          UFG::PowerManagementComponent::AddPowerManagedResource(ComponentOfTypeHK, (UFG::PowerManagedResource *)v10);
      }
      mPrev = this->mAnimationBankRequests.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *)(v10 + 3);
      v10[3] = mPrev;
      v10[4] = &this->mAnimationBankRequests.mNode;
      this->mAnimationBankRequests.mNode.mPrev = (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *)(v10 + 3);
      v17 = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
      if ( v17->mPrev == v17
        && this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mNext == &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> )
      {
        v18 = UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev;
        UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev->mNext = v17;
        v17->mPrev = v18;
        this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>::mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&UFG::ActionTreeResourcesComponent::smUpdateList;
        UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList>;
      }
LABEL_21:
      v19 = (AnimationGroup *)v10[12];
      if ( v19 && AnimationGroup::IsStreamedIn(v19) )
        return 1;
    }
  }
  else
  {
    Instance = AnimationDataBase::GetInstance();
    AnimBank = AnimationDataBase::FindAnimBank(Instance, symAnimBank);
    if ( AnimBank )
      return AnimationGroup::IsStreamedIn(AnimBank);
  }
  return 0;
}

// File Line: 178
// RVA: 0x297160
UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **__fastcall UFG::ActionTreeResourcesComponent::FindRequest(
        UFG::ActionTreeResourcesComponent *this,
        ActionPath *actionPath,
        UFG::qSymbolUC *symAnimBank)
{
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> **p_mNext; // rsi
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **v5; // rbx
  unsigned int mUID; // edi

  p_mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext;
  v5 = &this->mAnimationBankRequests.mNode.mNext[-2].mNext;
  if ( v5 == (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **)&this->UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent>::mNext )
    return 0i64;
  mUID = symAnimBank->mUID;
  while ( *((_DWORD *)v5 + 18) != mUID || !ActionPath::operator==((ActionPath *)(v5 + 15), actionPath) )
  {
    v5 = &v5[4][-2].mNext;
    if ( v5 == (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **)p_mNext )
      return 0i64;
  }
  return v5;
}

// File Line: 226
// RVA: 0x295EB0
void __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::AnimationBankRequest(
        UFG::ActionTreeResourcesComponent::AnimationBankRequest *this,
        ActionPath *actionPath,
        ActionNode *ownerNode,
        UFG::qSymbolUC *symAnimBank,
        UFG::eAnimationPriorityEnum priority)
{
  this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>;
  this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mPrev = &this->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext = &this->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  this->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::PowerManagedResource::`vftable;
  this->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::ActionTreeResourcesComponent::AnimationBankRequest::`vftable;
  AnimationGroupHandle::AnimationGroupHandle(&this->mAnimationGroupHandle);
  this->mActionPath.mPath.mCount = 0;
  this->mActionPath.mPath.mData.mOffset = 0i64;
  BinArray<ActionID,0>::Clone(&actionPath->mPath, &this->mActionPath.mPath);
  this->mOwnerNode = ownerNode;
  this->mKeepAlive = 1;
  AnimationGroupHandle::Init(&this->mAnimationGroupHandle, symAnimBank, priority);
  AnimationGroupHandle::Bind(&this->mAnimationGroupHandle);
}

// File Line: 233
// RVA: 0x2966A0
void __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::~AnimationBankRequest(
        UFG::ActionTreeResourcesComponent::AnimationBankRequest *this)
{
  ActionPath *p_mActionPath; // rbx
  __int64 mOffset; // rax
  __int64 v4; // rax
  char *v5; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mPrev; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mNext; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v8; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v9; // rax

  this->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::ActionTreeResourcesComponent::AnimationBankRequest::`vftable;
  p_mActionPath = &this->mActionPath;
  if ( this->mActionPath.mPath.mCount >= 0 )
  {
    mOffset = this->mActionPath.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_mActionPath->mPath.mData + mOffset) )
    {
      v4 = this->mActionPath.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->mActionPath.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    p_mActionPath->mPath.mData.mOffset = 0i64;
    p_mActionPath->mPath.mCount &= 0x80000000;
  }
  AnimationGroupHandle::~AnimationGroupHandle(&this->mAnimationGroupHandle);
  mPrev = this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mPrev;
  mNext = this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mPrev = &this->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext = &this->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  v8 = this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mPrev;
  v9 = this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mPrev = &this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>;
  this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>::mNext = &this->UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList>;
}

// File Line: 237
// RVA: 0x297D90
void __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::UnbindResources(
        UFG::ActionTreeResourcesComponent::AnimationBankRequest *this)
{
  AnimationGroupHandle::Unbind(&this->mAnimationGroupHandle);
}

// File Line: 242
// RVA: 0x297640
void __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::RebindResources(
        UFG::ActionTreeResourcesComponent::AnimationBankRequest *this)
{
  AnimationGroupHandle::Bind(&this->mAnimationGroupHandle);
}

// File Line: 247
// RVA: 0x296BF0
bool __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::AreResourcesAvailable(
        UFG::ActionTreeResourcesComponent::AnimationBankRequest *this)
{
  AnimationGroup *m_pPointer; // rcx

  m_pPointer = this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
  return m_pPointer && AnimationGroup::IsStreamedIn(m_pPointer);
}

