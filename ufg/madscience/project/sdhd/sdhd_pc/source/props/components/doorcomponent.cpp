// File Line: 45
// RVA: 0x151A640
__int64 dynamic_initializer_for__UFG::DoorComponent::s_DoorComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::DoorComponent::s_DoorComponentList__);
}

// File Line: 46
// RVA: 0x489BD0
const char *__fastcall UFG::DoorComponent::GetTypeName(UFG::DoorComponent *this)
{
  return "DoorComponent";
}

// File Line: 56
// RVA: 0x489990
void __fastcall UFG::DoorComponent::DoorComponent(UFG::DoorComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::DoorComponent *v3; // rdi
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v4; // r8
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v5; // rax

  v2 = pSceneObj;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, pSceneObj->m_NameUID);
  v4 = (UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DoorComponent::`vftable;
  *(_WORD *)&v3->mOpen = 0;
  v3->mAutoCloseInit = 0;
  v3->mAutoCloseTimer = 0.0;
  v5 = UFG::DoorComponent::s_DoorComponentList.mNode.mPrev;
  UFG::DoorComponent::s_DoorComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *)&UFG::DoorComponent::s_DoorComponentList;
  UFG::DoorComponent::s_DoorComponentList.mNode.mPrev = (UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::DoorComponent::_DoorComponentTypeUID,
    "DoorComponent");
  UFG::DoorComponent::PropertiesLoad(v3, v2);
}

// File Line: 70
// RVA: 0x489A30
void __fastcall UFG::DoorComponent::~DoorComponent(UFG::DoorComponent *this)
{
  UFG::DoorComponent *v1; // r8
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v2; // rdx
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v3; // rcx
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v4; // rax
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v5; // rcx
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DoorComponent::`vftable;
  if ( this == UFG::DoorComponent::s_DoorComponentpCurrentIterator )
    UFG::DoorComponent::s_DoorComponentpCurrentIterator = (UFG::DoorComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 77
// RVA: 0x489C90
void __fastcall UFG::DoorComponent::PropertiesLoad(UFG::DoorComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::DoorComponent *v3; // rdi
  UFG::qPropertySet *v4; // rsi
  int v5; // edx
  UFG::qPropertySet *v6; // rsi
  int v7; // edx
  UFG::qPropertySet *v8; // rsi
  int v9; // edx
  UFG::qPropertySet *v10; // rsi
  int v11; // edx
  UFG::qPropertySet *v12; // rbx
  int v13; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-18h]

  v2 = pSceneObj;
  v3 = this;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  v4 = PropertyUtils::Get<char const *>(pSceneObj, (UFG::qSymbol *)&PhysicsSym_DoorOpeningLeftNodeName.mUID);
  v5 = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  absolutePath.mPath.mCount = v5 & 0x80000000;
  ActionPath::Append(&absolutePath, (const char *)v4);
  v3->mDoorOpeningLeftNode = ActionNode::Find(&absolutePath, 0i64);
  v6 = PropertyUtils::Get<char const *>(v2, (UFG::qSymbol *)&PhysicsSym_DoorOpeningRightNodeName.mUID);
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
  ActionPath::Append(&absolutePath, (const char *)v6);
  v3->mDoorOpeningRightNode = ActionNode::Find(&absolutePath, 0i64);
  v8 = PropertyUtils::Get<char const *>(v2, (UFG::qSymbol *)&PhysicsSym_DoorClosingNodeName.mUID);
  v9 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      v9 = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v9 & 0x80000000;
  }
  ActionPath::Append(&absolutePath, (const char *)v8);
  v3->mDoorClosingNode = ActionNode::Find(&absolutePath, 0i64);
  v10 = PropertyUtils::Get<char const *>(v2, (UFG::qSymbol *)&PhysicsSym_DoorLockedNodeName.mUID);
  v11 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      v11 = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v11 & 0x80000000;
  }
  ActionPath::Append(&absolutePath, (const char *)v10);
  v3->mDoorLockedNode = ActionNode::Find(&absolutePath, 0i64);
  v12 = PropertyUtils::Get<char const *>(v2, (UFG::qSymbol *)&PhysicsSym_DoorUnlockedNodeName.mUID);
  v13 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      v13 = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v13 & 0x80000000;
  }
  ActionPath::Append(&absolutePath, (const char *)v12);
  v3->mDoorUnlockedNode = ActionNode::Find(&absolutePath, 0i64);
  if ( absolutePath.mPath.mCount >= 0 && absolutePath.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
  }
}tor delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffse

// File Line: 103
// RVA: 0x489BE0
bool __fastcall UFG::DoorComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(pSceneObj, (UFG::qSymbol *)&SimSymX_propset_componentDoor.mUID);
}

// File Line: 109
// RVA: 0x489F00
UFG::SimComponent *__fastcall UFG::DoorComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h]

  v1 = sceneObject;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x90ui64, "DoorComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::DoorComponent::DoorComponent((UFG::DoorComponent *)v3, v1);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return v5;
}

// File Line: 119
// RVA: 0x489BF0
void __fastcall UFG::DoorComponent::OnAttach(UFG::DoorComponent *this, UFG::SimObject *object)
{
  UFG::DoorComponent *v2; // rdi
  UFG::SimObject *v3; // rbx
  UFG::qSymbol *v4; // rsi
  UFG::GameStatTracker *v5; // rax
  UFG::TransformNodeComponent *v6; // rbx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v2 = this;
  UFG::DoorComponent::UpdateLockedState(this);
  UFG::DoorComponent::UpdateOpenedState(v2);
  v3 = v2->m_pSimObject;
  v4 = &v3->m_Name;
  name.mUID = v3->m_Name.mUID;
  v5 = UFG::GameStatTracker::Instance();
  v2->mIsAutoClosed = UFG::GameStatTracker::GetStat(v5, DoorStateAutoClose, &name);
  v6 = v3->m_pTransformNodeComponent;
  if ( v6 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    UFG::DoorStateManager::AddDoor(v4, (UFG::qVector3 *)&v6->mWorldTransform.v3);
  }
}

// File Line: 139
// RVA: 0x489C70
void __fastcall UFG::DoorComponent::OnDetach(UFG::DoorComponent *this)
{
  UFG::SimObject *v1; // rcx

  v1 = this->m_pSimObject;
  if ( v1 )
    UFG::DoorStateManager::RemoveDoor(&v1->m_Name);
}

// File Line: 150
// RVA: 0x48A020
void __fastcall UFG::DoorComponent::Update(UFG::DoorComponent *this, float delta_sec)
{
  UFG::DoorComponent *v2; // rbx
  float v3; // xmm7_4
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qMatrix44 *v8; // rcx
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm6_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm7_4
  bool v23; // cl
  UFG::TransformNodeComponent *v24; // rdi
  UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *v25; // rax
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v26; // rdi
  UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *v27; // rsi
  UFG::TransformNodeComponent *v28; // rdi
  UFG::SimObjectGame *v29; // rcx
  UFG::SimComponent *v30; // rax
  unsigned __int16 v31; // dx
  ActionNode *v32; // rdx

  v2 = this;
  v3 = delta_sec;
  if ( this->mIsAutoClosed == 1 && this->mOpen == 1 )
  {
    if ( !this->mAutoCloseInit )
    {
      v4 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v4 )
      {
        v5 = v4->m_Flags;
        if ( (v5 >> 14) & 1 )
        {
          v6 = v4->m_Components.p[14].m_pComponent;
        }
        else if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
            v6 = v4->m_Components.p[9].m_pComponent;
          else
            v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v4,
                                    UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v4->vfptr,
                                                                                   UFG::CompositeDrawableComponent::_TypeUID);
        }
        else
        {
          v6 = v4->m_Components.p[14].m_pComponent;
        }
        if ( v6 )
        {
          v7 = v6[19].m_BoundComponentHandles.mNode.mPrev;
          if ( v7 )
          {
            v8 = &UFG::qMatrix44::msIdentity;
            if ( v7[3].mNext )
              v8 = (UFG::qMatrix44 *)v7[3].mNext;
            v9 = v8->v3.y;
            v10 = v8->v3.z;
            v2->mAutoCloseCenter.x = v8->v3.x;
            v2->mAutoCloseCenter.y = v9;
            v2->mAutoCloseCenter.z = v10;
            v11 = (float)((float)(*(float *)&v7[1].mPrev - *(float *)&v7->mPrev) * 0.5) + *(float *)&v7->mPrev;
            v12 = v11 * v8->v0.y;
            v13 = v11 * v8->v0.x;
            v14 = (float)(v11 * v8->v0.z) + v10;
            v2->mAutoCloseCenter.z = v14;
            v15 = v13 + v2->mAutoCloseCenter.x;
            v16 = v12 + v9;
            v2->mAutoCloseCenter.y = v16;
            v2->mAutoCloseCenter.x = v15;
            v17 = (float)((float)(*((float *)&v7[1].mPrev + 1) - *((float *)&v7->mPrev + 1)) * 0.5)
                + *((float *)&v7->mPrev + 1);
            v18 = v17 * v8->v1.y;
            v19 = v17 * v8->v1.x;
            v20 = v14 + (float)(v17 * v8->v1.z);
            v2->mAutoCloseCenter.z = v20;
            v2->mAutoCloseCenter.x = v19 + v15;
            v2->mAutoCloseCenter.y = v16 + v18;
            v21 = *(float *)&v7->mNext;
            v2->mAutoCloseInit = 1;
            v2->mAutoCloseCenter.z = v21 + v20;
          }
        }
      }
    }
    v22 = v3 + v2->mAutoCloseTimer;
    v2->mAutoCloseTimer = v22;
    if ( v22 >= 1.85 && NISManager::GetInstance()->mState == STATE_INVALID )
    {
      v23 = 0;
      if ( v2->mAutoCloseInit != 1 )
        goto LABEL_51;
      if ( LocalPlayer )
      {
        v24 = LocalPlayer->m_pTransformNodeComponent;
        if ( v24 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v24);
          v23 = (float)((float)((float)((float)(v2->mAutoCloseCenter.y - v24->mWorldTransform.v3.y)
                                      * (float)(v2->mAutoCloseCenter.y - v24->mWorldTransform.v3.y))
                              + (float)((float)(v2->mAutoCloseCenter.x - v24->mWorldTransform.v3.x)
                                      * (float)(v2->mAutoCloseCenter.x - v24->mWorldTransform.v3.x)))
                      + (float)((float)(v2->mAutoCloseCenter.z - v24->mWorldTransform.v3.z)
                              * (float)(v2->mAutoCloseCenter.z - v24->mWorldTransform.v3.z))) < 12.25;
        }
      }
      v25 = (UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *)&UFG::RagdollComponent::s_RagdollComponentList.mNode.mNext[-6].mNext;
      if ( &UFG::RagdollComponent::s_RagdollComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> **)((char *)&UFG::RagdollComponent::s_RagdollComponentList - 88) )
      {
        do
        {
          v26 = v25[2].mNode.mNext;
          v27 = (UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *)&v25[6].mNode.mPrev[-6].mNext;
          if ( v26 )
          {
            v28 = (UFG::TransformNodeComponent *)v26[5].mNext;
            if ( v28 )
              v23 = v23
                 || (UFG::TransformNodeComponent::UpdateWorldTransform(v28),
                     (float)((float)((float)((float)(v2->mAutoCloseCenter.y - v28->mWorldTransform.v3.y)
                                           * (float)(v2->mAutoCloseCenter.y - v28->mWorldTransform.v3.y))
                                   + (float)((float)(v2->mAutoCloseCenter.x - v28->mWorldTransform.v3.x)
                                           * (float)(v2->mAutoCloseCenter.x - v28->mWorldTransform.v3.x)))
                           + (float)((float)(v2->mAutoCloseCenter.z - v28->mWorldTransform.v3.z)
                                   * (float)(v2->mAutoCloseCenter.z - v28->mWorldTransform.v3.z))) < 12.25);
          }
          v25 = v27;
        }
        while ( v27 != (UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *)((char *)&UFG::RagdollComponent::s_RagdollComponentList
                                                                                     - 88) );
      }
      if ( v23 )
      {
        v2->mAutoCloseTimer = 0.85000002;
      }
      else
      {
LABEL_51:
        v29 = (UFG::SimObjectGame *)v2->m_pSimObject;
        if ( v29 )
        {
          v31 = v29->m_Flags;
          if ( (v31 >> 14) & 1 )
          {
            v30 = v29->m_Components.p[7].m_pComponent;
          }
          else if ( (v31 & 0x8000u) == 0 )
          {
            if ( (v31 >> 13) & 1 )
            {
              v30 = v29->m_Components.p[6].m_pComponent;
            }
            else if ( (v31 >> 12) & 1 )
            {
              v30 = UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::ActionTreeComponent::_TypeUID);
            }
            else
            {
              v30 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v29->vfptr,
                      UFG::ActionTreeComponent::_TypeUID);
            }
          }
          else
          {
            v30 = v29->m_Components.p[7].m_pComponent;
          }
        }
        else
        {
          v30 = 0i64;
        }
        v32 = v2->mDoorClosingNode;
        if ( v32 )
        {
          if ( v30 )
            ActionController::Play((ActionController *)&v30[3], v32, 0);
        }
      }
    }
  }
}

// File Line: 251
// RVA: 0x48A3E0
void __fastcall UFG::DoorComponent::UpdateLockedState(UFG::DoorComponent *this)
{
  UFG::DoorComponent *v1; // rdi
  UFG::SimObjectGame *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  bool v4; // si
  ActionNode *v5; // rdi
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::AIOutlineComponent *v9; // rax
  UFG::allocator::free_link *v10; // r8
  const char *v11; // rdx
  unsigned int v12; // ecx
  UFG::allocator::free_link *v13; // rax
  UFG::qSymbol name; // [rsp+50h] [rbp+8h]
  unsigned int v15; // [rsp+58h] [rbp+10h]
  UFG::allocator::free_link *v16; // [rsp+60h] [rbp+18h]
  unsigned int *v17; // [rsp+68h] [rbp+20h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  name.mUID = v2->m_Name.mUID;
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetStat(v3, DoorStateLocked, &name);
  if ( v4 )
    v5 = v1->mDoorLockedNode;
  else
    v5 = v1->mDoorUnlockedNode;
  if ( v5 )
  {
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v2->m_Components.p[7].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v7 = v2->m_Components.p[6].m_pComponent;
      else
        v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      v7 = v2->m_Components.p[7].m_pComponent;
    }
    if ( v7 )
      ActionController::Play((ActionController *)&v7[3], v5, 0);
  }
  v8 = v2->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIOutlineComponent::_TypeUID);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
    {
      v9 = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIOutlineComponent::_TypeUID);
    }
    else if ( (v8 >> 12) & 1 )
    {
      v9 = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIOutlineComponent::_TypeUID);
    }
    else
    {
      v9 = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v2->vfptr,
                                        UFG::AIOutlineComponent::_TypeUID);
    }
  }
  else
  {
    v9 = (UFG::AIOutlineComponent *)v2->m_Components.p[27].m_pComponent;
  }
  if ( v9 )
  {
    if ( v4 )
      UFG::AIOutlineComponent::ActivateOutline(v9);
    else
      UFG::AIOutlineComponent::DeactivateOutline(v9);
  }
  v10 = UFG::qMalloc(0x40ui64, "AiDoorStateChangeEvent", 0i64);
  v16 = v10;
  if ( v10 )
  {
    v17 = &v15;
    v15 = name.mUID;
    v11 = UFG::gAiDoorStateChangeEventChannel.mName;
    v12 = UFG::gAiDoorStateChangeEventChannel.mUID;
    v13 = v10 + 1;
    v13->mNext = v13;
    v13[1].mNext = v13;
    v10->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
    LODWORD(v10[3].mNext) = v12;
    v10[4].mNext = (UFG::allocator::free_link *)v11;
    v10->mNext = (UFG::allocator::free_link *)&UFG::AiDoorStateChangeEvent::`vftable;
    LODWORD(v10[7].mNext) = v15;
    BYTE4(v10[7].mNext) = v4;
  }
  else
  {
    v10 = 0i64;
  }
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v10);
}

// File Line: 305
// RVA: 0x48A5C0
void __fastcall UFG::DoorComponent::UpdateOpenedState(UFG::DoorComponent *this)
{
  UFG::SimObjectGame *v1; // rbx
  UFG::DoorComponent *v2; // rsi
  UFG::GameStatTracker *v3; // rax
  unsigned __int16 v4; // cx
  UFG::PowerManagementComponent *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  ActionNode *v8; // rdi
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  v1 = (UFG::SimObjectGame *)this->m_pSimObject;
  v2 = this;
  name.mUID = v1->m_Name.mUID;
  v3 = UFG::GameStatTracker::Instance();
  if ( !UFG::GameStatTracker::GetStat(v3, DoorStateLocked, &name) )
  {
    v4 = v1->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v1,
                                              UFG::PowerManagementComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v1,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v1,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v1->vfptr,
                                                UFG::PowerManagementComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v1,
                                              UFG::PowerManagementComponent::_TypeUID);
    }
    if ( v5 )
      UFG::PowerManagementComponent::PreventSuspendTemporarily(v5, 10.0);
    v6 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v6, DoorOpenedByScript, &name) )
    {
      v7 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v7, DoorStateIsLeft, &name) )
        v8 = v2->mDoorOpeningLeftNode;
      else
        v8 = v2->mDoorOpeningRightNode;
      v2->mOpen = 1;
    }
    else
    {
      v8 = v2->mDoorClosingNode;
    }
    v9 = v1->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = v1->m_Components.p[7].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v10 = v1->m_Components.p[6].m_pComponent;
      }
      else if ( (v9 >> 12) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v10 = v1->m_Components.p[7].m_pComponent;
    }
    if ( v8 )
    {
      if ( v10 )
        ActionController::Play((ActionController *)&v10[3], v8, 0);
    }
  }
}

// File Line: 359
// RVA: 0x489FA0
void __fastcall UFG::DoorComponent::SetOpen(UFG::DoorComponent *this, __int64 bIn)
{
  char v2; // di
  UFG::DoorComponent *v3; // rbx

  v2 = bIn;
  v3 = this;
  if ( (_BYTE)bIn )
  {
    if ( !this->mOpen )
    {
      UFG::DoorStateManager::HandleDoorOpen(this->m_pSimObject);
      v3->mAutoCloseTimer = 0.0;
      v3->mOpen = v2;
      return;
    }
  }
  else if ( this->mOpen )
  {
    UFG::DoorStateManager::HandleDoorClose(this->m_pSimObject, (hkgpIndexedMeshDefinitions::Edge *)bIn);
    v3->mAutoCloseTimer = 0.0;
    v3->mOpen = v2;
    return;
  }
  this->mAutoCloseTimer = 0.0;
  this->mOpen = bIn;
}

