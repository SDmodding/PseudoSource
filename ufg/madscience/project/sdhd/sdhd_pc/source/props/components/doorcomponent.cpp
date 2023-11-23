// File Line: 45
// RVA: 0x151A640
__int64 dynamic_initializer_for__UFG::DoorComponent::s_DoorComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DoorComponent::s_DoorComponentList__);
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
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, pSceneObj->m_NameUID);
  this->mPrev = &this->UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>;
  this->mNext = &this->UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DoorComponent::`vftable;
  *(_WORD *)&this->mOpen = 0;
  this->mAutoCloseInit = 0;
  this->mAutoCloseTimer = 0.0;
  mPrev = UFG::DoorComponent::s_DoorComponentList.mNode.mPrev;
  UFG::DoorComponent::s_DoorComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *)&UFG::DoorComponent::s_DoorComponentList;
  UFG::DoorComponent::s_DoorComponentList.mNode.mPrev = &this->UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>;
  UFG::SimComponent::AddType(this, UFG::DoorComponent::_DoorComponentTypeUID, "DoorComponent");
  UFG::DoorComponent::PropertiesLoad(this, pSceneObj);
}

// File Line: 70
// RVA: 0x489A30
void __fastcall UFG::DoorComponent::~DoorComponent(UFG::DoorComponent *this)
{
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v2; // rdx
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *mPrev; // rcx
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *mNext; // rax
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v5; // rcx
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DoorComponent::`vftable;
  if ( this == UFG::DoorComponent::s_DoorComponentpCurrentIterator )
    UFG::DoorComponent::s_DoorComponentpCurrentIterator = (UFG::DoorComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::DoorComponent,UFG::DoorComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 77
// RVA: 0x489C90
void __fastcall UFG::DoorComponent::PropertiesLoad(UFG::DoorComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *v4; // rsi
  UFG::qPropertySet *v5; // rsi
  int mCount; // edx
  UFG::qPropertySet *v7; // rsi
  int v8; // edx
  UFG::qPropertySet *v9; // rsi
  int v10; // edx
  UFG::qPropertySet *v11; // rbx
  int v12; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-18h] BYREF

  v4 = PropertyUtils::Get<char const *>(pSceneObj, (UFG::qArray<unsigned long,0> *)&PhysicsSym_DoorOpeningLeftNodeName);
  absolutePath.mPath.mData.mOffset = 0i64;
  absolutePath.mPath.mCount = 0;
  ActionPath::Append(&absolutePath, (const char *)v4);
  this->mDoorOpeningLeftNode = ActionNode::Find(&absolutePath, 0i64);
  v5 = PropertyUtils::Get<char const *>(pSceneObj, (UFG::qArray<unsigned long,0> *)&PhysicsSym_DoorOpeningRightNodeName);
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
  ActionPath::Append(&absolutePath, (const char *)v5);
  this->mDoorOpeningRightNode = ActionNode::Find(&absolutePath, 0i64);
  v7 = PropertyUtils::Get<char const *>(pSceneObj, (UFG::qArray<unsigned long,0> *)&PhysicsSym_DoorClosingNodeName);
  v8 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      v8 = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v8 & 0x80000000;
  }
  ActionPath::Append(&absolutePath, (const char *)v7);
  this->mDoorClosingNode = ActionNode::Find(&absolutePath, 0i64);
  v9 = PropertyUtils::Get<char const *>(pSceneObj, (UFG::qArray<unsigned long,0> *)&PhysicsSym_DoorLockedNodeName);
  v10 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      v10 = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v10 & 0x80000000;
  }
  ActionPath::Append(&absolutePath, (const char *)v9);
  this->mDoorLockedNode = ActionNode::Find(&absolutePath, 0i64);
  v11 = PropertyUtils::Get<char const *>(pSceneObj, (UFG::qArray<unsigned long,0> *)&PhysicsSym_DoorUnlockedNodeName);
  v12 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      v12 = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v12 & 0x80000000;
  }
  ActionPath::Append(&absolutePath, (const char *)v11);
  this->mDoorUnlockedNode = ActionNode::Find(&absolutePath, 0i64);
  if ( absolutePath.mPath.mCount >= 0 && absolutePath.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
  }
}

// File Line: 103
// RVA: 0x489BE0
bool __fastcall UFG::DoorComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentDoor);
}

// File Line: 109
// RVA: 0x489F00
UFG::DoorComponent *__fastcall UFG::DoorComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x90ui64, "DoorComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::DoorComponent::DoorComponent((UFG::DoorComponent *)v3, sceneObject);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, sceneObject->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return (UFG::DoorComponent *)v5;
}

// File Line: 119
// RVA: 0x489BF0
void __fastcall UFG::DoorComponent::OnAttach(UFG::DoorComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *p_m_Name; // rsi
  UFG::GameStatTracker *v5; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  UFG::DoorComponent::UpdateLockedState(this);
  UFG::DoorComponent::UpdateOpenedState(this);
  m_pSimObject = this->m_pSimObject;
  p_m_Name = &m_pSimObject->m_Name;
  name.mUID = m_pSimObject->m_Name.mUID;
  v5 = UFG::GameStatTracker::Instance();
  this->mIsAutoClosed = UFG::GameStatTracker::GetStat(v5, DoorStateAutoClose, &name);
  m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::DoorStateManager::AddDoor(p_m_Name, (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3);
  }
}

// File Line: 139
// RVA: 0x489C70
void __fastcall UFG::DoorComponent::OnDetach(UFG::DoorComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    UFG::DoorStateManager::RemoveDoor(&m_pSimObject->m_Name);
}

// File Line: 150
// RVA: 0x48A020
void __fastcall UFG::DoorComponent::Update(UFG::DoorComponent *this, float delta_sec)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qMatrix44 *mNext; // rcx
  float y; // xmm2_4
  float z; // xmm3_4
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
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *p_mNext; // rax
  UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> *v26; // rdi
  UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *v27; // rsi
  UFG::TransformNodeComponent *v28; // rdi
  UFG::SimObjectGame *v29; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v31; // dx
  ActionNodePlayable *mDoorClosingNode; // rdx

  if ( this->mIsAutoClosed && this->mOpen )
  {
    if ( !this->mAutoCloseInit )
    {
      m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[14].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
            m_pComponent = m_pSimObject->m_Components.p[9].m_pComponent;
          else
            m_pComponent = (m_Flags & 0x1000) != 0
                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                             m_pSimObject,
                             UFG::CompositeDrawableComponent::_TypeUID)
                         : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CompositeDrawableComponent::_TypeUID);
        }
        else
        {
          m_pComponent = m_pSimObject->m_Components.p[14].m_pComponent;
        }
        if ( m_pComponent )
        {
          mPrev = m_pComponent[19].m_BoundComponentHandles.mNode.mPrev;
          if ( mPrev )
          {
            mNext = &UFG::qMatrix44::msIdentity;
            if ( mPrev[3].mNext )
              mNext = (UFG::qMatrix44 *)mPrev[3].mNext;
            y = mNext->v3.y;
            z = mNext->v3.z;
            this->mAutoCloseCenter.x = mNext->v3.x;
            this->mAutoCloseCenter.y = y;
            this->mAutoCloseCenter.z = z;
            v11 = (float)((float)(*(float *)&mPrev[1].mPrev - *(float *)&mPrev->mPrev) * 0.5) + *(float *)&mPrev->mPrev;
            v12 = v11 * mNext->v0.y;
            v13 = v11 * mNext->v0.x;
            v14 = (float)(v11 * mNext->v0.z) + z;
            this->mAutoCloseCenter.z = v14;
            v15 = v13 + this->mAutoCloseCenter.x;
            v16 = v12 + y;
            this->mAutoCloseCenter.y = v16;
            this->mAutoCloseCenter.x = v15;
            v17 = (float)((float)(*((float *)&mPrev[1].mPrev + 1) - *((float *)&mPrev->mPrev + 1)) * 0.5)
                + *((float *)&mPrev->mPrev + 1);
            v18 = v17 * mNext->v1.y;
            v19 = v17 * mNext->v1.x;
            v20 = v14 + (float)(v17 * mNext->v1.z);
            this->mAutoCloseCenter.z = v20;
            this->mAutoCloseCenter.x = v19 + v15;
            this->mAutoCloseCenter.y = v16 + v18;
            v21 = *(float *)&mPrev->mNext;
            this->mAutoCloseInit = 1;
            this->mAutoCloseCenter.z = v21 + v20;
          }
        }
      }
    }
    v22 = delta_sec + this->mAutoCloseTimer;
    this->mAutoCloseTimer = v22;
    if ( v22 >= 1.85 && NISManager::GetInstance()->mState == STATE_INVALID )
    {
      v23 = 0;
      if ( !this->mAutoCloseInit )
        goto LABEL_35;
      if ( LocalPlayer )
      {
        m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          v23 = (float)((float)((float)((float)(this->mAutoCloseCenter.y
                                              - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                      * (float)(this->mAutoCloseCenter.y
                                              - m_pTransformNodeComponent->mWorldTransform.v3.y))
                              + (float)((float)(this->mAutoCloseCenter.x
                                              - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                      * (float)(this->mAutoCloseCenter.x
                                              - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                      + (float)((float)(this->mAutoCloseCenter.z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                              * (float)(this->mAutoCloseCenter.z - m_pTransformNodeComponent->mWorldTransform.v3.z))) < 12.25;
        }
      }
      p_mNext = (UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *)&UFG::RagdollComponent::s_RagdollComponentList.mNode.mNext[-6].mNext;
      if ( &UFG::RagdollComponent::s_RagdollComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> **)((char *)&UFG::RagdollComponent::s_RagdollComponentList - 88) )
      {
        do
        {
          v26 = p_mNext[2].mNode.mNext;
          v27 = (UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *)&p_mNext[6].mNode.mPrev[-6].mNext;
          if ( v26 )
          {
            v28 = (UFG::TransformNodeComponent *)v26[5].mNext;
            if ( v28 )
              v23 = v23
                 || (UFG::TransformNodeComponent::UpdateWorldTransform(v28),
                     (float)((float)((float)((float)(this->mAutoCloseCenter.y - v28->mWorldTransform.v3.y)
                                           * (float)(this->mAutoCloseCenter.y - v28->mWorldTransform.v3.y))
                                   + (float)((float)(this->mAutoCloseCenter.x - v28->mWorldTransform.v3.x)
                                           * (float)(this->mAutoCloseCenter.x - v28->mWorldTransform.v3.x)))
                           + (float)((float)(this->mAutoCloseCenter.z - v28->mWorldTransform.v3.z)
                                   * (float)(this->mAutoCloseCenter.z - v28->mWorldTransform.v3.z))) < 12.25);
          }
          p_mNext = v27;
        }
        while ( v27 != (UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *)((char *)&UFG::RagdollComponent::s_RagdollComponentList
                                                                                     - 88) );
      }
      if ( v23 )
      {
        this->mAutoCloseTimer = 0.85000002;
      }
      else
      {
LABEL_35:
        v29 = (UFG::SimObjectGame *)this->m_pSimObject;
        if ( v29 )
        {
          v31 = v29->m_Flags;
          if ( (v31 & 0x4000) != 0 )
          {
            ComponentOfTypeHK = v29->m_Components.p[7].m_pComponent;
          }
          else if ( v31 >= 0 )
          {
            if ( (v31 & 0x2000) != 0 )
            {
              ComponentOfTypeHK = v29->m_Components.p[6].m_pComponent;
            }
            else if ( (v31 & 0x1000) != 0 )
            {
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::ActionTreeComponent::_TypeUID);
            }
            else
            {
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v29, UFG::ActionTreeComponent::_TypeUID);
            }
          }
          else
          {
            ComponentOfTypeHK = v29->m_Components.p[7].m_pComponent;
          }
        }
        else
        {
          ComponentOfTypeHK = 0i64;
        }
        mDoorClosingNode = (ActionNodePlayable *)this->mDoorClosingNode;
        if ( mDoorClosingNode )
        {
          if ( ComponentOfTypeHK )
            ActionController::Play((ActionController *)&ComponentOfTypeHK[3], mDoorClosingNode, 0);
        }
      }
    }
  }
}osingNode )
        {
          if ( ComponentOfTy

// File Line: 251
// RVA: 0x48A3E0
void __fastcall UFG::DoorComponent::UpdateLockedState(UFG::DoorComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rbx
  UFG::GameStatTracker *v3; // rax
  bool Stat; // si
  ActionNodePlayable *mDoorLockedNode; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  __int16 v8; // cx
  UFG::AIOutlineComponent *ComponentOfTypeHK; // rax
  UFG::allocator::free_link *v10; // r8
  const char *mName; // rdx
  unsigned int v12; // ecx
  UFG::qSymbol name; // [rsp+50h] [rbp+8h] BYREF
  unsigned int mUID; // [rsp+58h] [rbp+10h] BYREF
  UFG::allocator::free_link *v15; // [rsp+60h] [rbp+18h]
  unsigned int *v16; // [rsp+68h] [rbp+20h]

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  name.mUID = m_pSimObject->m_Name.mUID;
  v3 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v3, DoorStateLocked, &name);
  if ( Stat )
    mDoorLockedNode = (ActionNodePlayable *)this->mDoorLockedNode;
  else
    mDoorLockedNode = (ActionNodePlayable *)this->mDoorUnlockedNode;
  if ( mDoorLockedNode )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
      else
        m_pComponent = (m_Flags & 0x1000) != 0
                     ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::ActionTreeComponent::_TypeUID)
                     : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
      ActionController::Play((ActionController *)&m_pComponent[3], mDoorLockedNode, 0);
  }
  v8 = m_pSimObject->m_Flags;
  if ( (v8 & 0x4000) != 0 )
    goto LABEL_22;
  if ( v8 < 0 )
  {
    ComponentOfTypeHK = (UFG::AIOutlineComponent *)m_pSimObject->m_Components.p[27].m_pComponent;
    goto LABEL_24;
  }
  if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
LABEL_22:
    ComponentOfTypeHK = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pSimObject,
                                                     UFG::AIOutlineComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pSimObject,
                                                     UFG::AIOutlineComponent::_TypeUID);
LABEL_24:
  if ( ComponentOfTypeHK )
  {
    if ( Stat )
      UFG::AIOutlineComponent::ActivateOutline(ComponentOfTypeHK);
    else
      UFG::AIOutlineComponent::DeactivateOutline(ComponentOfTypeHK);
  }
  v10 = UFG::qMalloc(0x40ui64, "AiDoorStateChangeEvent", 0i64);
  v15 = v10;
  if ( v10 )
  {
    v16 = &mUID;
    mUID = name.mUID;
    mName = UFG::gAiDoorStateChangeEventChannel.mName;
    v12 = UFG::gAiDoorStateChangeEventChannel.mUID;
    v10[1].mNext = v10 + 1;
    v10[2].mNext = v10 + 1;
    v10->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
    LODWORD(v10[3].mNext) = v12;
    v10[4].mNext = (UFG::allocator::free_link *)mName;
    v10->mNext = (UFG::allocator::free_link *)&UFG::AiDoorStateChangeEvent::`vftable;
    LODWORD(v10[7].mNext) = mUID;
    BYTE4(v10[7].mNext) = Stat;
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
  UFG::SimObjectGame *m_pSimObject; // rbx
  UFG::GameStatTracker *v3; // rax
  __int16 m_Flags; // cx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  ActionNodePlayable *mDoorOpeningLeftNode; // rdi
  __int16 v9; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  name.mUID = m_pSimObject->m_Name.mUID;
  v3 = UFG::GameStatTracker::Instance();
  if ( !UFG::GameStatTracker::GetStat(v3, DoorStateLocked, &name) )
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
      UFG::PowerManagementComponent::PreventSuspendTemporarily(ComponentOfTypeHK, 10.0);
    v6 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v6, DoorOpenedByScript, &name) )
    {
      v7 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v7, DoorStateIsLeft, &name) )
        mDoorOpeningLeftNode = (ActionNodePlayable *)this->mDoorOpeningLeftNode;
      else
        mDoorOpeningLeftNode = (ActionNodePlayable *)this->mDoorOpeningRightNode;
      this->mOpen = 1;
    }
    else
    {
      mDoorOpeningLeftNode = (ActionNodePlayable *)this->mDoorClosingNode;
    }
    v9 = m_pSimObject->m_Flags;
    if ( (v9 & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
    else if ( v9 >= 0 )
    {
      if ( (v9 & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
      }
      else if ( (v9 & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
    if ( mDoorOpeningLeftNode )
    {
      if ( m_pComponent )
        ActionController::Play((ActionController *)&m_pComponent[3], mDoorOpeningLeftNode, 0);
    }
  }
}

// File Line: 359
// RVA: 0x489FA0
void __fastcall UFG::DoorComponent::SetOpen(UFG::DoorComponent *this, hkgpIndexedMeshDefinitions::Edge *bIn)
{
  char v2; // di

  v2 = (char)bIn;
  if ( (_BYTE)bIn )
  {
    if ( !this->mOpen )
    {
      UFG::DoorStateManager::HandleDoorOpen(this->m_pSimObject);
      this->mAutoCloseTimer = 0.0;
      this->mOpen = v2;
      return;
    }
  }
  else if ( this->mOpen )
  {
    UFG::DoorStateManager::HandleDoorClose(this->m_pSimObject, bIn);
    this->mAutoCloseTimer = 0.0;
    this->mOpen = 0;
    return;
  }
  this->mAutoCloseTimer = 0.0;
  this->mOpen = (char)bIn;
}

