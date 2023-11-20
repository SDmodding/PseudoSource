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
  return atexit(dynamic_atexit_destructor_for__UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList__);
}

// File Line: 28
// RVA: 0x1493FD0
__int64 dynamic_initializer_for__UFG::ActionTreeResourcesComponent::smUpdateList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ActionTreeResourcesComponent::smUpdateList__);
}

// File Line: 36
// RVA: 0x295DE0
void __fastcall UFG::ActionTreeResourcesComponent::ActionTreeResourcesComponent(UFG::ActionTreeResourcesComponent *this, unsigned int name_uid)
{
  UFG::ActionTreeResourcesComponent *v2; // rdi
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *v3; // rdx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v4; // rbx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *v5; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v6; // rax
  UFG::qList<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList,1,0> *v7; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v8; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v4 = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&v2->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActionTreeResourcesComponent::`vftable';
  v7 = &v2->mAnimationBankRequests;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v8 = &v2->m_pActionTreeComponent;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v2->m_pActionTreeComponent.m_pPointer = 0i64;
  v5 = UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList.mNode.mPrev;
  UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *)&v2->mPrev;
  v3->mPrev = v5;
  v2->mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *)&UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList;
  UFG::ActionTreeResourcesComponent::s_ActionTreeResourcesComponentList.mNode.mPrev = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::ActionTreeResourcesComponent::_ActionTreeResourcesComponentTypeUID,
    "ActionTreeResourcesComponent");
  v6 = UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev;
  UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev->mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&v2->mPrev;
  v4->mPrev = v6;
  v2->mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&UFG::ActionTreeResourcesComponent::smUpdateList;
  UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&v2->mPrev;
}

// File Line: 45
// RVA: 0x2965C0
void __fastcall UFG::ActionTreeResourcesComponent::~ActionTreeResourcesComponent(UFG::ActionTreeResourcesComponent *this)
{
  UFG::ActionTreeResourcesComponent *v1; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v7; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v8; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v9; // rdx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v10; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v11; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *v12; // rdx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *v13; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *v14; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActionTreeResourcesComponent::`vftable';
  v2 = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  UFG::qList<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList,1,0>::DeleteNodes(&v1->mAnimationBankRequests);
  v7 = v1->mAnimationBankRequests.mNode.mPrev;
  v8 = v1->mAnimationBankRequests.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mAnimationBankRequests.mNode.mPrev = &v1->mAnimationBankRequests.mNode;
  v1->mAnimationBankRequests.mNode.mNext = &v1->mAnimationBankRequests.mNode;
  v9 = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&v1->mPrev;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
  v12 = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 50
// RVA: 0x297430
UFG::SimComponent *__fastcall UFG::ActionTreeResourcesComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  char *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x88ui64, "ActionTreeResourcesComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::ActionTreeResourcesComponent::ActionTreeResourcesComponent(
      (UFG::ActionTreeResourcesComponent *)v3,
      v2->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v2->m_pSimObject;
  if ( (v6->m_Flags >> 14) & 1 )
    v7 = 30;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  return v5;
}

// File Line: 58
// RVA: 0x297DA0
void __fastcall UFG::ActionTreeResourcesComponent::Update(UFG::ActionTreeResourcesComponent *this, float delta_sec)
{
  UFG::ActionTreeResourcesComponent *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::ActionTreeResourcesComponent::AnimationBankRequest *v11; // rbx
  signed __int64 v12; // rdi
  UFG::SimComponent *v13; // rcx
  ActionNode *v14; // rdx
  ActionController *v15; // rcx
  char v16; // al
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v17; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v18; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v19; // r8
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v20; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v21; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v22; // rdx

  v2 = this;
  if ( !this->m_pActionTreeComponent.m_pPointer )
  {
    v3 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v4 = v3->m_Components.p[7].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v4 = v3->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v5 >> 12) & 1 )
            v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID);
          else
            v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v4 = v6;
        }
      }
      else
      {
        v4 = v3->m_Components.p[7].m_pComponent;
      }
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pActionTreeComponent;
    if ( v2->m_pActionTreeComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pActionTreeComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pActionTreeComponent.mPrev;
    }
    v2->m_pActionTreeComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pActionTreeComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
  }
  v11 = (UFG::ActionTreeResourcesComponent::AnimationBankRequest *)&v2->mAnimationBankRequests.mNode.mNext[-2].mNext;
  if ( v11 != (UFG::ActionTreeResourcesComponent::AnimationBankRequest *)&v2->mNext )
  {
    do
    {
      v12 = (signed __int64)&v11->mNext[-2].mNext;
      if ( v11->mKeepAlive )
        goto LABEL_34;
      v13 = v2->m_pActionTreeComponent.m_pPointer;
      if ( v13 )
      {
        v14 = v11->mOwnerNode;
        v15 = (ActionController *)&v13[3];
        v16 = v14 ? ActionController::IsPlayingFullPath(v15, v14, 1) : ActionController::IsPlayingFullPath(
                                                                         v15,
                                                                         &v11->mActionPath,
                                                                         1);
        if ( v16 )
          v11->mKeepAlive = 1;
      }
      if ( v11->mKeepAlive )
      {
LABEL_34:
        v11->mKeepAlive = 0;
      }
      else
      {
        v17 = v11->mPrev;
        v18 = v11->mNext;
        v19 = (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *)&v11->mPrev;
        v17->mNext = v18;
        v18->mPrev = v17;
        v19->mPrev = v19;
        v19->mNext = v19;
        UFG::ActionTreeResourcesComponent::AnimationBankRequest::~AnimationBankRequest(v11);
        UFG::qMemoryPool2::Free(&gActionTreeMemoryPool, v11, 0x98ui64);
      }
      v11 = (UFG::ActionTreeResourcesComponent::AnimationBankRequest *)v12;
    }
    while ( (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> **)v12 != &v2->mNext );
  }
  if ( (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> **)&v2->mAnimationBankRequests.mNode.mNext[-2].mNext == &v2->mNext )
  {
    v20 = v2->mPrev;
    v21 = v2->mNext;
    v22 = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&v2->mPrev;
    v20->mNext = v21;
    v21->mPrev = v20;
    v22->mPrev = v22;
    v22->mNext = v22;
  }
}

// File Line: 111
// RVA: 0x297F80
void __fastcall UFG::ActionTreeResourcesComponent::UpdateAll(float delta_sec)
{
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v1; // rcx
  UFG::qList<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList,1,0> *v2; // rbx

  v1 = UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mNext - 5;
  if ( (UFG::qList<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList,1,0> *)&UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mNext[-5] != &UFG::ActionTreeResourcesComponent::smUpdateList - 5 )
  {
    do
    {
      v2 = (UFG::qList<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList,1,0> *)&v1[5].mNext[-5];
      if ( ((_QWORD)v1[2].mPrev & 3) == 1 )
        UFG::ActionTreeResourcesComponent::Update((UFG::ActionTreeResourcesComponent *)v1, delta_sec);
      v1 = &v2->mNode;
    }
    while ( v2 != &UFG::ActionTreeResourcesComponent::smUpdateList - 5 );
  }
}

// File Line: 128
// RVA: 0x297650
bool __fastcall UFG::ActionTreeResourcesComponent::RequestAnimationBank(UFG::ActionTreeResourcesComponent *this, ActionPath *actionPath, ActionNode *ownerNode, const bool doTheRequest, UFG::qSymbolUC *symAnimBank, UFG::eAnimationPriorityEnum priority)
{
  ActionNode *v6; // r14
  ActionPath *v7; // rsi
  UFG::ActionTreeResourcesComponent *v8; // rdi
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **v9; // rax
  UFG::PowerManagedResource *v10; // rbx
  char *v11; // rcx
  UFG::PowerManagedResource *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::PowerManagementComponent *v15; // rax
  UFG::PowerManagedResource *v16; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v17; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v18; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *v19; // rax
  AnimationGroup *v20; // rcx
  AnimationDataBase *v22; // rax
  AnimationGroup *v23; // rax

  v6 = ownerNode;
  v7 = actionPath;
  v8 = this;
  if ( doTheRequest )
  {
    v9 = UFG::ActionTreeResourcesComponent::FindRequest(this, actionPath, symAnimBank);
    v10 = (UFG::PowerManagedResource *)v9;
    if ( v9 )
    {
      *((_BYTE *)v9 + 144) = 1;
      goto LABEL_23;
    }
    v11 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x98ui64, "AnimationBankRequest", 0i64, 1u);
    if ( v11 )
    {
      UFG::ActionTreeResourcesComponent::AnimationBankRequest::AnimationBankRequest(
        (UFG::ActionTreeResourcesComponent::AnimationBankRequest *)v11,
        v7,
        v6,
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
      v13 = (UFG::SimObjectGame *)v8->m_pSimObject;
      if ( v13 )
      {
        v14 = v13->m_Flags;
        if ( (v14 >> 14) & 1 )
        {
          v15 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v13,
                                                   UFG::PowerManagementComponent::_TypeUID);
        }
        else if ( (v14 & 0x8000u) == 0 )
        {
          if ( (v14 >> 13) & 1 )
            v15 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v13,
                                                     UFG::PowerManagementComponent::_TypeUID);
          else
            v15 = (UFG::PowerManagementComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v13,
                                                                        UFG::PowerManagementComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::PowerManagementComponent::_TypeUID));
        }
        else
        {
          v15 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v13,
                                                   UFG::PowerManagementComponent::_TypeUID);
        }
        if ( v15 )
          UFG::PowerManagementComponent::AddPowerManagedResource(v15, v10);
      }
      v16 = v10 + 1;
      v17 = v8->mAnimationBankRequests.mNode.mPrev;
      v17->mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *)&v10[1];
      v16->vfptr = (UFG::PowerManagedResourceVtbl *)v17;
      v16->mPrev = (UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *)&v8->mAnimationBankRequests;
      v8->mAnimationBankRequests.mNode.mPrev = (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *)&v10[1];
      v18 = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&v8->mPrev;
      if ( v18->mPrev == v18
        && (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> **)v8->mNext == &v8->mPrev )
      {
        v19 = UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev;
        UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev->mNext = v18;
        v18->mPrev = v19;
        v8->mNext = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&UFG::ActionTreeResourcesComponent::smUpdateList;
        UFG::ActionTreeResourcesComponent::smUpdateList.mNode.mPrev = (UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent_UpdateList> *)&v8->mPrev;
      }
LABEL_23:
      v20 = (AnimationGroup *)v10[4].vfptr;
      if ( v20 && AnimationGroup::IsStreamedIn(v20) )
        return 1;
      return 0;
    }
  }
  else
  {
    v22 = AnimationDataBase::GetInstance();
    v23 = AnimationDataBase::FindAnimBank(v22, symAnimBank);
    if ( v23 )
      return AnimationGroup::IsStreamedIn(v23);
  }
  return 0;
}

// File Line: 178
// RVA: 0x297160
UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **__fastcall UFG::ActionTreeResourcesComponent::FindRequest(UFG::ActionTreeResourcesComponent *this, ActionPath *actionPath, UFG::qSymbolUC *symAnimBank)
{
  UFG::qNode<UFG::ActionTreeResourcesComponent,UFG::ActionTreeResourcesComponent> **v3; // rsi
  ActionPath *v4; // rbp
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **v5; // rbx
  unsigned int v6; // edi

  v3 = &this->mNext;
  v4 = actionPath;
  v5 = &this->mAnimationBankRequests.mNode.mNext[-2].mNext;
  if ( v5 == (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **)&this->mNext )
    return 0i64;
  v6 = symAnimBank->mUID;
  while ( *((_DWORD *)v5 + 18) != v6 || !ActionPath::operator==((ActionPath *)(v5 + 15), v4) )
  {
    v5 = &v5[4][-2].mNext;
    if ( v5 == (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> **)v3 )
      return 0i64;
  }
  return v5;
}

// File Line: 226
// RVA: 0x295EB0
void __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::AnimationBankRequest(UFG::ActionTreeResourcesComponent::AnimationBankRequest *this, ActionPath *actionPath, ActionNode *ownerNode, UFG::qSymbolUC *symAnimBank, UFG::eAnimationPriorityEnum priority)
{
  UFG::qSymbolUC *v5; // rbp
  ActionNode *v6; // rsi
  ActionPath *v7; // rdi
  UFG::ActionTreeResourcesComponent::AnimationBankRequest *v8; // r14
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v9; // rax
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v10; // rax
  signed __int64 v11; // [rsp+58h] [rbp+10h]

  v5 = symAnimBank;
  v6 = ownerNode;
  v7 = actionPath;
  v8 = this;
  v9 = (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  v10 = (UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *)&this->mPrev;
  v10->mPrev = v10;
  v10->mNext = v10;
  this->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::PowerManagedResource::`vftable';
  this->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::ActionTreeResourcesComponent::AnimationBankRequest::`vftable';
  AnimationGroupHandle::AnimationGroupHandle(&this->mAnimationGroupHandle);
  v11 = (signed __int64)&v8->mActionPath;
  *(_DWORD *)v11 = 0;
  *(_QWORD *)(v11 + 8) = 0i64;
  BinArray<ActionID,0>::Clone(&v7->mPath, &v8->mActionPath.mPath);
  v8->mOwnerNode = v6;
  v8->mKeepAlive = 1;
  AnimationGroupHandle::Init(&v8->mAnimationGroupHandle, v5, priority);
  AnimationGroupHandle::Bind(&v8->mAnimationGroupHandle);
}

// File Line: 233
// RVA: 0x2966A0
void __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::~AnimationBankRequest(UFG::ActionTreeResourcesComponent::AnimationBankRequest *this)
{
  UFG::ActionTreeResourcesComponent::AnimationBankRequest *v1; // rdi
  ActionPath *v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rax
  char *v5; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v6; // rdx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v7; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v8; // rax
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v9; // rdx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v10; // rcx
  UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::ActionTreeResourcesComponent::AnimationBankRequest::`vftable';
  v2 = &this->mActionPath;
  if ( this->mActionPath.mPath.mCount >= 0 )
  {
    v3 = this->mActionPath.mPath.mData.mOffset;
    if ( v3 && (UFG::qOffset64<ActionID *> *)((char *)&v2->mPath.mData + v3) )
    {
      v4 = this->mActionPath.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->mActionPath.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    v2->mPath.mData.mOffset = 0i64;
    v2->mPath.mCount &= 0x80000000;
  }
  AnimationGroupHandle::~AnimationGroupHandle(&v1->mAnimationGroupHandle);
  v6 = (UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *)&v1->mPrev;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mPrev = v6;
  v6->mNext = v6;
  v9 = (UFG::qNode<UFG::ActionTreeResourcesComponent::AnimationBankRequest,UFG::ActionTreeResourcesComponent::AnimationBankRequestList> *)&v1->mPrev;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
}

// File Line: 237
// RVA: 0x297D90
void __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::UnbindResources(UFG::ActionTreeResourcesComponent::AnimationBankRequest *this)
{
  AnimationGroupHandle::Unbind(&this->mAnimationGroupHandle);
}

// File Line: 242
// RVA: 0x297640
void __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::RebindResources(UFG::ActionTreeResourcesComponent::AnimationBankRequest *this)
{
  AnimationGroupHandle::Bind(&this->mAnimationGroupHandle);
}

// File Line: 247
// RVA: 0x296BF0
bool __fastcall UFG::ActionTreeResourcesComponent::AnimationBankRequest::AreResourcesAvailable(UFG::ActionTreeResourcesComponent::AnimationBankRequest *this)
{
  AnimationGroup *v1; // rcx

  v1 = this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
  return v1 && AnimationGroup::IsStreamedIn(v1);
}

