// File Line: 38
// RVA: 0x267340
void __fastcall UpdatePreQueryComponentType_NavComponent(float dt)
{
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v1; // rcx

  v1 = UFG::NavComponent::s_NavComponentList.mNode.mNext - 4;
  for ( UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
        v1 != (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)(&UFG::NavComponent::s_NavComponentList - 4);
        UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)v1 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::NavComponent,UFG::NavComponent> *))v1->mPrev[8].mNext)(v1);
    v1 = UFG::NavComponent::s_NavComponentpCurrentIterator->mNext - 4;
  }
  UFG::NavComponent::s_NavComponentpCurrentIterator = 0i64;
}

// File Line: 39
// RVA: 0x267170
void __fastcall UpdatePostQueryComponentType_NavComponent(float dt)
{
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v1; // rcx

  v1 = UFG::NavComponent::s_NavComponentList.mNode.mNext - 4;
  for ( UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
        v1 != (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)(&UFG::NavComponent::s_NavComponentList - 4);
        UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)v1 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::NavComponent,UFG::NavComponent> *))v1->mPrev[9].mPrev)(v1);
    v1 = UFG::NavComponent::s_NavComponentpCurrentIterator->mNext - 4;
  }
  UFG::NavComponent::s_NavComponentpCurrentIterator = 0i64;
}

// File Line: 40
// RVA: 0x2673D0
void __fastcall UpdateSteeringComponentType_NavComponent(float dt)
{
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v1; // rcx

  v1 = UFG::NavComponent::s_NavComponentList.mNode.mNext - 4;
  for ( UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
        v1 != (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)(&UFG::NavComponent::s_NavComponentList - 4);
        UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)v1 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::NavComponent,UFG::NavComponent> *))v1->mPrev[9].mNext)(v1);
    v1 = UFG::NavComponent::s_NavComponentpCurrentIterator->mNext - 4;
  }
  UFG::NavComponent::s_NavComponentpCurrentIterator = 0i64;
}

// File Line: 41
// RVA: 0x266E50
void __fastcall UpdateControlComponentType_NavComponent(float dt)
{
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v1; // rcx

  v1 = UFG::NavComponent::s_NavComponentList.mNode.mNext - 4;
  for ( UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
        v1 != (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)(&UFG::NavComponent::s_NavComponentList - 4);
        UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)v1 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::NavComponent,UFG::NavComponent> *))v1->mPrev[10].mPrev)(v1);
    v1 = UFG::NavComponent::s_NavComponentpCurrentIterator->mNext - 4;
  }
  UFG::NavComponent::s_NavComponentpCurrentIterator = 0i64;
}

// File Line: 49
// RVA: 0x2672D0
void __fastcall UFG::NavSystemBase::UpdatePostStreaming(UFG::NavSystemBase *this, float fDeltaTime)
{
  UFG::TicketBoothManager::UpdateBooth(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_CRITICAL_NAVCOMPONENT_POSTSTREAMING,
    fDeltaTime);
  UFG::TicketBoothManager::UpdateBooth(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_NON_CRITICAL_NAVCOMPONENT_POSTSTREAMING,
    fDeltaTime);
}

// File Line: 58
// RVA: 0x2669F0
void __fastcall UFG::NavSystemBase::Update(UFG::NavSystemBase *this, float fDeltaTime)
{
  UpdatePreQueryComponentType_NavComponent(fDeltaTime);
  UpdatePostQueryComponentType_NavComponent(fDeltaTime);
  UpdateSteeringComponentType_NavComponent(fDeltaTime);
}

// File Line: 82
// RVA: 0x267440
void __fastcall UFG::NavSystemBase::WaitForAsyncPathfindCompletion(UFG::NavSystemBase *this, float fDeltaTime)
{
  UFG::DaemonManager *v2; // rax

  v2 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::CompleteUpdate(v2, fDeltaTime);
}

// File Line: 92
// RVA: 0x265780
void __fastcall UFG::NavSystemBase::PostSteeringUpdate(UFG::NavSystemBase *this, float fDeltaTime)
{
  UFG::DaemonManager *v2; // rax

  UpdateControlComponentType_NavComponent(fDeltaTime);
  v2 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::StartUpdate(v2, fDeltaTime);
}

// File Line: 113
// RVA: 0x263F80
bool __fastcall UFG::NavSystemBase::DetectObstacle(
        UFG::NavSystemBase *this,
        UFG::NavComponent *pIgnoreTarget,
        UFG::HavokNavPosition *navPosition)
{
  UFG::NavComponent *v3; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  bool result; // al

  v3 = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
  for ( UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
        v3 != (UFG::NavComponent *)(&UFG::NavComponent::s_NavComponentList - 4);
        UFG::NavComponent::s_NavComponentpCurrentIterator = v3 )
  {
    if ( v3 != pIgnoreTarget )
    {
      m_pSimObject = v3->m_pSimObject;
      if ( m_pSimObject )
        m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
      else
        m_pTransformNodeComponent = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      if ( (float)((float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - navPosition->m_vPosition.y)
                                 * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - navPosition->m_vPosition.y))
                         + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - navPosition->m_vPosition.x)
                                 * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - navPosition->m_vPosition.x)))
                 + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - navPosition->m_vPosition.z)
                         * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - navPosition->m_vPosition.z))) < 0.69999999 )
      {
        result = 1;
        goto LABEL_10;
      }
      v3 = UFG::NavComponent::s_NavComponentpCurrentIterator;
    }
    v3 = (UFG::NavComponent *)&v3->mNext[-4];
  }
  result = 0;
LABEL_10:
  UFG::NavComponent::s_NavComponentpCurrentIterator = 0i64;
  return result;
}

