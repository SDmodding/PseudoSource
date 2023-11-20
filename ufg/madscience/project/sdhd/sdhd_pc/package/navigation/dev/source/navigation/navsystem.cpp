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
    ((void (*)(void))v1->mPrev[8].mNext)();
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
    ((void (*)(void))v1->mPrev[9].mPrev)();
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
    ((void (*)(void))v1->mPrev[9].mNext)();
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
    ((void (*)(void))v1->mPrev[10].mPrev)();
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
char __fastcall UFG::NavSystemBase::DetectObstacle(UFG::NavSystemBase *this, UFG::NavComponent *pIgnoreTarget, UFG::HavokNavPosition *navPosition)
{
  UFG::NavComponent *v3; // rax
  UFG::HavokNavPosition *v4; // rbp
  UFG::NavComponent *v5; // rsi
  UFG::SimObject *v6; // rcx
  UFG::TransformNodeComponent *v7; // rbx
  char result; // al

  v3 = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
  v4 = navPosition;
  v5 = pIgnoreTarget;
  for ( UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
        v3 != (UFG::NavComponent *)(&UFG::NavComponent::s_NavComponentList - 4);
        UFG::NavComponent::s_NavComponentpCurrentIterator = v3 )
  {
    if ( v3 != v5 )
    {
      v6 = v3->m_pSimObject;
      if ( v6 )
        v7 = v6->m_pTransformNodeComponent;
      else
        v7 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v7);
      if ( (float)((float)((float)((float)(v7->mWorldTransform.v3.y - v4->m_vPosition.y)
                                 * (float)(v7->mWorldTransform.v3.y - v4->m_vPosition.y))
                         + (float)((float)(v7->mWorldTransform.v3.x - v4->m_vPosition.x)
                                 * (float)(v7->mWorldTransform.v3.x - v4->m_vPosition.x)))
                 + (float)((float)(v7->mWorldTransform.v3.z - v4->m_vPosition.z)
                         * (float)(v7->mWorldTransform.v3.z - v4->m_vPosition.z))) < 0.69999999 )
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

