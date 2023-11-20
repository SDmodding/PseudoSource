// File Line: 66
// RVA: 0x1543E60
__int64 dynamic_initializer_for__UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList__);
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
  return atexit(dynamic_atexit_destructor_for__UFG::FacialActionTreeComponent::smUpdateList__);
}

// File Line: 81
// RVA: 0x5172B0
void __fastcall UFG::FacialActionTreeComponent::FacialActionTreeComponent(UFG::FacialActionTreeComponent *this, unsigned int name_uid, component_FacialActionTree *dataPtr)
{
  component_FacialActionTree *v3; // r15
  UFG::FacialActionTreeComponent *v4; // rsi
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v5; // rdi
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v6; // r14
  ActionContext *v7; // rbx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v8; // rax
  UFG::allocator::free_link *v9; // rax
  ActionContext *v10; // rax
  __int64 v11; // rax
  ActionContext *v12; // rcx
  ActionNode *v13; // rcx
  ActionNodeRoot *v14; // rax
  char v15; // cl
  char v16; // al
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v17; // rax

  v3 = dataPtr;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v6 = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&v4->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  UFG::ActionTreeComponentBase::ActionTreeComponentBase(
    (UFG::ActionTreeComponentBase *)&v4->vfptr,
    eACTION_TREE_TYPE_FACIAL);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FacialActionTreeComponent::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::FacialActionTreeComponent::`vftable{for `UFG::ActionTreeComponentBase};
  v7 = 0i64;
  v4->mActionTreeFileName = 0i64;
  ActionController::ActionController(&v4->mActionController);
  v8 = UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList.mNode.mPrev;
  UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *)&v4->mPrev;
  v5->mPrev = v8;
  v4->mNext = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *)&UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList;
  UFG::FacialActionTreeComponent::s_FacialActionTreeComponentList.mNode.mPrev = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::FacialActionTreeComponent::_FacialActionTreeComponentTypeUID,
    "FacialActionTreeComponent");
  *((_BYTE *)v4 + 480) &= 0xE2u;
  *((_BYTE *)v4 + 480) |= 2u;
  v9 = UFG::qMalloc(0xD8ui64, "FacialActionTreeComponent::ActionContext", 0i64);
  if ( v9 )
  {
    ActionContext::ActionContext((ActionContext *)v9);
    v7 = v10;
  }
  v4->mActionContext = v7;
  if ( v3 )
  {
    v11 = v3->FacialActFileName.mOffset;
    if ( v3->FacialActFileName.mOffset && (component_FacialActionTree *)((char *)v3 + v11) )
      v4->mActionTreeFileName = (char *)v3 + v11;
  }
  else
  {
    v4->mActionTreeFileName = "Data\\Global\\Act\\Facial\\GlobalFace.act";
  }
  if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation )
  {
    ActionController::Stop(&v4->mActionController);
    v12 = v4->mActionContext;
    if ( v12 )
    {
      v13 = v12->m_OpeningBranch;
      if ( v13 )
      {
        v14 = (ActionNodeRoot *)((__int64 (__cdecl *)(ActionNode *))v13->vfptr[1].SetResourceOwner)(v13);
        ActionNodeRoot::Init(v14, v4->mActionContext);
      }
    }
  }
  v15 = `anonymous namespace::slLocalTweaksEnabled;
  if ( !`anonymous namespace::slLocalTweaksEnabled )
    v15 = 1;
  `anonymous namespace::slLocalTweaksEnabled = v15;
  v16 = *((_BYTE *)v4 + 480);
  if ( !(v16 & 2) && !(v16 & 1) )
  {
    v17 = UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev;
    UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev->mNext = v6;
    v6->mPrev = v17;
    v4->mNext = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&UFG::FacialActionTreeComponent::smUpdateList;
    UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&v4->mPrev;
  }
}

// File Line: 144
// RVA: 0x51B720
void __fastcall UFG::FacialActionTreeComponent::~FacialActionTreeComponent(UFG::FacialActionTreeComponent *this)
{
  UFG::FacialActionTreeComponent *v1; // rbx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v2; // rdi
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v3; // rcx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v4; // rax
  ActionContext *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v10; // rdx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v11; // rcx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v12; // rax
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v13; // rcx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *v14; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FacialActionTreeComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::FacialActionTreeComponent::`vftable{for `UFG::ActionTreeComponentBase};
  if ( this == UFG::FacialActionTreeComponent::s_FacialActionTreeComponentpCurrentIterator )
    UFG::FacialActionTreeComponent::s_FacialActionTreeComponentpCurrentIterator = (UFG::FacialActionTreeComponent *)&this->mPrev[-10].mNext;
  v2 = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  ActionController::Stop(&v1->mActionController);
  v5 = v1->mActionContext;
  if ( v5 )
  {
    if ( v5->mSimObject.m_pPointer )
    {
      v6 = v5->mSimObject.mPrev;
      v7 = v5->mSimObject.mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mSimObject.mPrev;
      v5->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mSimObject.mPrev;
    }
    v5->mSimObject.m_pPointer = 0i64;
    v8 = v5->mSimObject.mPrev;
    v9 = v5->mSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v5->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mSimObject.mPrev;
    v5->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mSimObject.mPrev;
    operator delete[](v5);
  }
  ActionController::~ActionController(&v1->mActionController);
  UFG::ActionTreeComponentBase::~ActionTreeComponentBase((UFG::ActionTreeComponentBase *)&v1->vfptr);
  v10 = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
  v13 = v2->mPrev;
  v14 = v2->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 165
// RVA: 0x5461E0
UFG::SimComponent *__fastcall UFG::FacialActionTreeComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rdx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_FacialActionTree::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x1E8ui64, "FacialActionTreeComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::FacialActionTreeComponent::FacialActionTreeComponent(
      (UFG::FacialActionTreeComponent *)v10,
      v3->m_NameUID,
      (component_FacialActionTree *)v7);
    v6 = v11;
  }
  v12 = v3->m_pSimObject;
  if ( (v12->m_Flags >> 14) & 1 )
    v13 = 31;
  else
    v13 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v14, v12, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v6, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return v6;
}

// File Line: 199
// RVA: 0x5362E0
void __fastcall UFG::FacialActionTreeComponent::InitActionTree(UFG::FacialActionTreeComponent *this)
{
  UFG::FacialActionTreeComponent *v1; // rbx
  ActionContext *v2; // rdx
  ActionContext *v3; // rax
  ActionNode *v4; // rcx
  ActionNodeRoot *v5; // rdi

  v1 = this;
  if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation )
  {
    ActionContext::Reset(this->mActionContext, eACTION_TREE_TYPE_FACIAL, this->m_pSimObject);
    UFG::ActionTreeComponentBase::ResetMemory((UFG::ActionTreeComponentBase *)&v1->vfptr);
    v2 = v1->mActionContext;
    v1->mActionContext->m_OpeningBranch = (ActionNode *)ActionNode::Load(v1->mActionTreeFileName);
    v3 = v1->mActionContext;
    v1->mActionController.m_Context = v3;
    v3->mActionController = &v1->mActionController;
    v4 = v1->mActionContext->m_OpeningBranch;
    if ( v4 )
    {
      v5 = (ActionNodeRoot *)((__int64 (__cdecl *)(ActionNode *))v4->vfptr[1].SetResourceOwner)(v4);
      if ( UFG::ActionTreeComponentBase::AllocateFor((UFG::ActionTreeComponentBase *)&v1->vfptr, v5) )
        ActionNodeRoot::Init(v5, v1->mActionContext);
      ActionController::Play(&v1->mActionController, v1->mActionContext->m_OpeningBranch, 0);
    }
  }
}

// File Line: 238
// RVA: 0x53DDD0
void __fastcall UFG::FacialActionTreeComponent::OnAttach(UFG::FacialActionTreeComponent *this, UFG::SimObject *object)
{
  JUMPOUT(UFG::FacialActionTreeComponent::sDisableFacialAnimation, 0, UFG::FacialActionTreeComponent::InitActionTree);
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
  bool v2; // al
  char v3; // r8
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v4; // rax
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v5; // rcx
  UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *v6; // rax

  v1 = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&this->mPrev;
  v2 = *(_OWORD *)&this->168 != __PAIR__((unsigned __int64)&this->mPrev, (unsigned __int64)&this->mPrev);
  v3 = *((_BYTE *)this + 480);
  if ( v3 & 1 || v3 & 2 )
  {
    if ( v2 )
    {
      v5 = v1->mPrev;
      v6 = v1->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v1->mPrev = v1;
      v1->mNext = v1;
    }
  }
  else if ( !v2 )
  {
    v4 = UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev;
    UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev->mNext = v1;
    v1->mPrev = v4;
    this->mNext = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&UFG::FacialActionTreeComponent::smUpdateList;
    UFG::FacialActionTreeComponent::smUpdateList.mNode.mPrev = (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> *)&this->mPrev;
  }
}

// File Line: 377
// RVA: 0x526000
void __fastcall UFG::FacialActionTreeComponent::Disable(UFG::FacialActionTreeComponent *this)
{
  UFG::FacialActionTreeComponent *v1; // rbx

  v1 = this;
  ActionController::Stop(&this->mActionController);
  *((_BYTE *)v1 + 480) |= 1u;
  UFG::FacialActionTreeComponent::SyncUpdateList(v1);
}

// File Line: 384
// RVA: 0x526780
void __fastcall UFG::FacialActionTreeComponent::Enable(UFG::FacialActionTreeComponent *this)
{
  *((_BYTE *)this + 480) &= 0xFEu;
  UFG::FacialActionTreeComponent::SyncUpdateList(this);
}

// File Line: 402
// RVA: 0x55E0D0
void __fastcall UFG::FacialActionTreeComponent::UpdateAll(float delta_sec)
{
  UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *v1; // rbx
  UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *v2; // rdi
  char v3; // al

  v1 = (UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *)&UFG::FacialActionTreeComponent::smUpdateList.mNode.mNext[-11].mNext;
  if ( &UFG::FacialActionTreeComponent::smUpdateList.mNode.mNext[-11].mNext != (UFG::qNode<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList> **)((char *)&UFG::FacialActionTreeComponent::smUpdateList - 168) )
  {
    do
    {
      v2 = (UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *)&v1[11].mNode.mPrev[-11].mNext;
      if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation
        || (ActionController::Stop((ActionController *)&v1[12].mNode.mNext),
            !UFG::FacialActionTreeComponent::sDisableFacialAnimation) )
      {
        v3 = (char)v1[30].mNode.mPrev;
        if ( !(v3 & 1) && !(v3 & 2) && !UFG::FacialActionTreeComponent::sDisableFacialAnimationUpdate )
          ActionController::Update((ActionController *)&v1[12].mNode.mNext, delta_sec);
      }
      v1 = v2;
    }
    while ( v2 != (UFG::qList<UFG::FacialActionTreeComponent,UFG::FacialActionTreeComponent_UpdateList,1,0> *)((char *)&UFG::FacialActionTreeComponent::smUpdateList - 168) );
  }
}

