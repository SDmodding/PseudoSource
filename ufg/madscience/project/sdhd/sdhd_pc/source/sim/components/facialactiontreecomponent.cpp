// File Line: 66
// RVA: 0x1543E60
__int64 dynamic_initializer_for__UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList__);
}

// File Line: 67
// RVA: 0x52CA00
UFG::ComponentIDDesc *__fastcall UFG::FacialActionTreeComponent::GetDesc(UFG::FacialActionTreeComponent *this)
{
  return &UFG::FacialActionTreeComponent::_TypeIDesc;
}

// File Line: 73
// RVA: 0x1544200
__int64 dynamic_initializer_for__UFG::FacialActionTreeComponent::smUpdateList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::FacialActionTreeComponent::smUpdateList__);
}

// File Line: 81
// RVA: 0x5172B0
void __fastcall UFG::FacialActionTreeComponent::FacialActionTreeComponent(
        UFG::FacialActionTreeComponent *this,
        unsigned int name_uid,
        component_FacialActionTree *dataPtr)
{
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v5; // r14
  ActionContext *v6; // rbx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *mPrev; // rax
  UFG::allocator::free_link *v8; // rax
  ActionContext *v9; // rax
  __int64 mOffset; // rax
  ActionContext *mActionContext; // rcx
  ActionNode *m_OpeningBranch; // rcx
  ActionNodeRoot *v13; // rax
  char v14; // cl
  char v15; // al
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v16; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>::mPrev = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>;
  this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>::mNext = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>;
  v5 = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>;
  this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>::mPrev = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>;
  this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>::mNext = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>;
  UFG::ActionTreeComponentBase::ActionTreeComponentBase(&this->UFG::ActionTreeComponentBase, eACTION_TREE_TYPE_FACIAL);
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FacialActionTreeComponent::`vftable{for `UFG::SimComponent};
  this->UFG::ActionTreeComponentBase::vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::FacialActionTreeComponent::`vftable{for `UFG::ActionTreeComponentBase};
  v6 = 0i64;
  this->mActionTreeFileName = 0i64;
  ActionController::ActionController(&this->mActionController);
  mPrev = UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList.mNode.mPrev;
  UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>;
  this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>::mNext = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *)&UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList;
  UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList.mNode.mPrev = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::FacialActionTreeComponent::_FacialActionTreeComponentTypeUID,
    "FacialActionTreeComponent");
  *((_BYTE *)this + 480) &= 0xE2u;
  *((_BYTE *)this + 480) |= 2u;
  v8 = UFG::qMalloc(0xD8ui64, "FacialActionTreeComponent::ActionContext", 0i64);
  if ( v8 )
  {
    ActionContext::ActionContext((ActionContext *)v8);
    v6 = v9;
  }
  this->mActionContext = v6;
  if ( dataPtr )
  {
    mOffset = dataPtr->FacialActFileName.mOffset;
    if ( dataPtr->FacialActFileName.mOffset && (component_FacialActionTree *)((char *)dataPtr + mOffset) )
      this->mActionTreeFileName = (char *)dataPtr + mOffset;
  }
  else
  {
    this->mActionTreeFileName = "Data\\Global\\Act\\Facial\\GlobalFace.act";
  }
  if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation )
  {
    ActionController::Stop(&this->mActionController);
    mActionContext = this->mActionContext;
    if ( mActionContext )
    {
      m_OpeningBranch = mActionContext->m_OpeningBranch;
      if ( m_OpeningBranch )
      {
        v13 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))m_OpeningBranch->vfptr[1].SetResourceOwner)(m_OpeningBranch);
        ActionNodeRoot::Init(v13, this->mActionContext);
      }
    }
  }
  v14 = `anonymous namespace::slLocalTweaksEnabled;
  if ( !`anonymous namespace::slLocalTweaksEnabled )
    v14 = 1;
  `anonymous namespace::slLocalTweaksEnabled = v14;
  v15 = *((_BYTE *)this + 480);
  if ( (v15 & 2) == 0 && (v15 & 1) == 0 )
  {
    v16 = UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev;
    UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev->mNext = v5;
    v5->mPrev = v16;
    this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>::mNext = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&UFG::FacialActionTreeComponent::smUpdateList;
    UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>;
  }
}

// File Line: 144
// RVA: 0x51B720
void __fastcall UFG::FacialActionTreeComponent::~FacialActionTreeComponent(UFG::FacialActionTreeComponent *this)
{
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v2; // rdi
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *mPrev; // rcx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *mNext; // rax
  ActionContext *mActionContext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v10; // rcx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v11; // rax
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v12; // rcx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v13; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FacialActionTreeComponent::`vftable{for `UFG::SimComponent};
  this->UFG::ActionTreeComponentBase::vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::FacialActionTreeComponent::`vftable{for `UFG::ActionTreeComponentBase};
  if ( this == UFG::FacialActionTreeComponent::s_FacialActionTreeComponentpCurrentIterator )
    UFG::FacialActionTreeComponent::s_FacialActionTreeComponentpCurrentIterator = (UFG::FacialActionTreeComponent *)&this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>::mPrev[-10].mNext;
  v2 = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>;
  mPrev = this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  ActionController::Stop(&this->mActionController);
  mActionContext = this->mActionContext;
  if ( mActionContext )
  {
    if ( mActionContext->mSimObject.m_pPointer )
    {
      v6 = mActionContext->mSimObject.mPrev;
      v7 = mActionContext->mSimObject.mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      mActionContext->mSimObject.mPrev = &mActionContext->mSimObject;
      mActionContext->mSimObject.mNext = &mActionContext->mSimObject;
    }
    mActionContext->mSimObject.m_pPointer = 0i64;
    v8 = mActionContext->mSimObject.mPrev;
    v9 = mActionContext->mSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    mActionContext->mSimObject.mPrev = &mActionContext->mSimObject;
    mActionContext->mSimObject.mNext = &mActionContext->mSimObject;
    operator delete[](mActionContext);
  }
  ActionController::~ActionController(&this->mActionController);
  UFG::ActionTreeComponentBase::~ActionTreeComponentBase(&this->UFG::ActionTreeComponentBase);
  v10 = this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>::mPrev;
  v11 = this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>::mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>::mPrev = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>;
  this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>::mNext = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>;
  v12 = v2->mPrev;
  v13 = v2->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 165
// RVA: 0x5461E0
UFG::SimComponent *__fastcall UFG::FacialActionTreeComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_FacialActionTree::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x1E8ui64, "FacialActionTreeComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::FacialActionTreeComponent::FacialActionTreeComponent(
      (UFG::FacialActionTreeComponent *)v10,
      pSceneObj->m_NameUID,
      (component_FacialActionTree *)MemImagePtr);
    v6 = v11;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v13 = 31;
  else
    v13 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v14, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v6, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return v6;
}

// File Line: 199
// RVA: 0x5362E0
void __fastcall UFG::FacialActionTreeComponent::InitActionTree(UFG::FacialActionTreeComponent *this)
{
  ActionContext *mActionContext; // rax
  ActionNode *m_OpeningBranch; // rcx
  ActionNodeRoot *v4; // rdi

  if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation )
  {
    ActionContext::Reset(this->mActionContext, eACTION_TREE_TYPE_FACIAL, (UFG::SimObjectGame *)this->m_pSimObject);
    UFG::ActionTreeComponentBase::ResetMemory(&this->UFG::ActionTreeComponentBase);
    this->mActionContext->m_OpeningBranch = (ActionNode *)ActionNode::Load(this->mActionTreeFileName);
    mActionContext = this->mActionContext;
    this->mActionController.m_Context = mActionContext;
    mActionContext->mActionController = &this->mActionController;
    m_OpeningBranch = this->mActionContext->m_OpeningBranch;
    if ( m_OpeningBranch )
    {
      v4 = (ActionNodeRoot *)((__int64 (__fastcall *)(ActionNode *))m_OpeningBranch->vfptr[1].SetResourceOwner)(m_OpeningBranch);
      if ( UFG::ActionTreeComponentBase::AllocateFor(&this->UFG::ActionTreeComponentBase, v4) )
        ActionNodeRoot::Init(v4, this->mActionContext);
      ActionController::Play(&this->mActionController, (ActionNodePlayable *)this->mActionContext->m_OpeningBranch, 0);
    }
  }
}

// File Line: 238
// RVA: 0x53DDD0
void __fastcall UFG::FacialActionTreeComponent::OnAttach(UFG::FacialActionTreeComponent *this, UFG::SimObject *object)
{
  if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation )
    UFG::FacialActionTreeComponent::InitActionTree(this);
}

// File Line: 249
// RVA: 0x540480
void __fastcall UFG::FacialActionTreeComponent::OnDetach(UFG::FacialActionTreeComponent *this)
{
  if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation )
    ActionController::Stop(&this->mActionController);
}

// File Line: 286
// RVA: 0x522A30
void UFG::FacialActionTreeComponent::BeginSimFrame(void)
{
  UFG::FacialActionTreeComponent::sDebugDisplayCount = 0;
}

// File Line: 357
// RVA: 0x553180
void __fastcall UFG::FacialActionTreeComponent::SyncUpdateList(UFG::FacialActionTreeComponent *this)
{
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v1; // rdx
  char v2; // r8
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v3; // rax
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *mPrev; // rcx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *mNext; // rax

  v1 = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>;
  v2 = *((_BYTE *)this + 480);
  if ( (v2 & 1) != 0 || (v2 & 2) != 0 )
  {
    if ( *(_OWORD *)&this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> != __PAIR128__((unsigned __int64)&this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>, (unsigned __int64)&this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>) )
    {
      mPrev = v1->mPrev;
      mNext = v1->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v1->mPrev = v1;
      v1->mNext = v1;
    }
  }
  else if ( *(_OWORD *)&this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> == __PAIR128__((unsigned __int64)&this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>, (unsigned __int64)&this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>) )
  {
    v3 = UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev;
    UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev->mNext = v1;
    v1->mPrev = v3;
    this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>::mNext = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&UFG::FacialActionTreeComponent::smUpdateList;
    UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev = &this->UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList>;
  }
}

// File Line: 377
// RVA: 0x526000
void __fastcall UFG::FacialActionTreeComponent::Disable(UFG::FacialActionTreeComponent *this)
{
  ActionController::Stop(&this->mActionController);
  *((_BYTE *)this + 480) |= 1u;
  UFG::FacialActionTreeComponent::SyncUpdateList(this);
}

// File Line: 384
// RVA: 0x526780
void __fastcall UFG::FacialActionTreeComponent::Enable(UFG::FacialActionTreeComponent *this)
{
  *((_BYTE *)this + 480) &= ~1u;
  UFG::FacialActionTreeComponent::SyncUpdateList(this);
}

// File Line: 402
// RVA: 0x55E0D0
void __fastcall UFG::FacialActionTreeComponent::UpdateAll(float delta_sec)
{
  UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *p_mNext; // rbx
  UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *v2; // rdi
  char mPrev; // al

  p_mNext = (UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *)&UFG::FacialActionTreeComponent::smUpdateList.mNode.mNext[-11].mNext;
  if ( &UFG::FacialActionTreeComponent::smUpdateList.mNode.mNext[-11].mNext != (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> **)((char *)&UFG::FacialActionTreeComponent::smUpdateList - 168) )
  {
    do
    {
      v2 = (UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *)&p_mNext[11].mNode.mPrev[-11].mNext;
      if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation
        || (ActionController::Stop((ActionController *)&p_mNext[12].mNode.mNext),
            !UFG::FacialActionTreeComponent::sDisableFacialAnimation) )
      {
        mPrev = (char)p_mNext[30].mNode.mPrev;
        if ( (mPrev & 1) == 0 && (mPrev & 2) == 0 && !UFG::FacialActionTreeComponent::sDisableFacialAnimationUpdate )
          ActionController::Update((ActionController *)&p_mNext[12].mNode.mNext, delta_sec);
      }
      p_mNext = v2;
    }
    while ( v2 != (UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *)((char *)&UFG::FacialActionTreeComponent::smUpdateList - 168) );
  }
}

