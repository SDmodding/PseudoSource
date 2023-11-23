// File Line: 27
// RVA: 0x1476290
__int64 dynamic_initializer_for__UFG::NavComponent::s_NavComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::NavComponent::s_NavComponentList__);
}

// File Line: 28
// RVA: 0x264E50
const char *__fastcall UFG::NavComponent::GetTypeName(UFG::NavComponent *this)
{
  return "NavComponent";
}

// File Line: 30
// RVA: 0x14762B0
__int64 UFG::_dynamic_initializer_for__gAiDoorStateChangeEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gAiDoorStateChangeEventChannel,
    "EVT_DoorStateChange",
    "Sent by door components, ready by nav components.");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gAiDoorStateChangeEventChannel__);
}

// File Line: 48
// RVA: 0x262650
void __fastcall UFG::NavComponent::NavComponent(UFG::NavComponent *this, unsigned int name_uid)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::NavComponent,UFG::NavComponent>;
  this->mNext = &this->UFG::qNode<UFG::NavComponent,UFG::NavComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::NavComponent::`vftable;
  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_navPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_navPosition.m_vPosition.y = y;
  this->m_navPosition.m_vPosition.z = z;
  this->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_navPosition.m_bValid = 0;
  *(_QWORD *)&this->m_navPosition.m_packedKey = -1i64;
  this->m_navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(UFG::qVector3::msZero.x),
                                                     (__m128)LODWORD(UFG::qVector3::msZero.z)),
                                                   _mm_unpacklo_ps(
                                                     (__m128)LODWORD(UFG::qVector3::msZero.y),
                                                     (__m128)(unsigned int)FLOAT_1_0));
  this->m_pNavModulePathing = 0i64;
  this->m_pNavModuleLocal = 0i64;
  this->m_pNavModuleController = 0i64;
  this->m_fDesiredSpeed = 0.0;
  this->m_fAvoidanceRadius = 0.5;
  this->m_bIsSloppyFreeRunner = 0;
  this->m_fMaxAngularVelocity = 0.0;
  this->m_iHasSteeringControl = 0;
  this->m_navParams.m_fRadius = 0.0;
  this->m_navParams.m_flags = 65280;
  this->m_postStreamingTicket.mPrev = &this->m_postStreamingTicket;
  this->m_postStreamingTicket.mNext = &this->m_postStreamingTicket;
  this->m_postStreamingTicket.mTimestamp = 0i64;
  this->m_postStreamingTicket.mActiveCallback.m_Closure.m_pthis = 0i64;
  this->m_postStreamingTicket.mActiveCallback.m_Closure.m_pFunction = 0i64;
  this->m_postStreamingTicket.mInactiveCallback.m_Closure.m_pthis = 0i64;
  this->m_postStreamingTicket.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  this->m_TicketType = TICKETBOOTH_CRITICAL_NAVCOMPONENT_POSTSTREAMING;
  mPrev = UFG::NavComponent::s_NavComponentList.mNode.mPrev;
  UFG::NavComponent::s_NavComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::NavComponent,UFG::NavComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)&UFG::NavComponent::s_NavComponentList;
  UFG::NavComponent::s_NavComponentList.mNode.mPrev = &this->UFG::qNode<UFG::NavComponent,UFG::NavComponent>;
  UFG::SimComponent::AddType(this, UFG::NavComponent::_NavComponentTypeUID, "NavComponent");
}

// File Line: 54
// RVA: 0x262D90
void __fastcall UFG::NavComponent::~NavComponent(UFG::NavComponent *this)
{
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v2; // rdi
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *mPrev; // rcx
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *mNext; // rax
  UFG::NavModulePathing *m_pNavModulePathing; // rcx
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx
  UFG::NavModuleController *m_pNavModuleController; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v8; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v9; // rax
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v10; // rcx
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::NavComponent::`vftable;
  if ( this == UFG::NavComponent::s_NavComponentpCurrentIterator )
    UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::NavComponent,UFG::NavComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  m_pNavModulePathing = this->m_pNavModulePathing;
  if ( m_pNavModulePathing )
    m_pNavModulePathing->vfptr->__vecDelDtor(m_pNavModulePathing, 1u);
  m_pNavModuleLocal = this->m_pNavModuleLocal;
  if ( m_pNavModuleLocal )
    m_pNavModuleLocal->vfptr->__vecDelDtor(m_pNavModuleLocal, 1u);
  m_pNavModuleController = this->m_pNavModuleController;
  if ( m_pNavModuleController )
    m_pNavModuleController->vfptr->__vecDelDtor(m_pNavModuleController, 1u);
  v8 = this->m_postStreamingTicket.mPrev;
  v9 = this->m_postStreamingTicket.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->m_postStreamingTicket.mPrev = &this->m_postStreamingTicket;
  this->m_postStreamingTicket.mNext = &this->m_postStreamingTicket;
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 75
// RVA: 0x264F60
void __fastcall UFG::NavComponent::Init(UFG::NavComponent *this, UFG::SimObject *pSimObject)
{
  int v3; // eax
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx

  UFG::NavComponent::SetPathingModule<UFG::NavModulePathing>(this);
  UFG::NavAvoidanceManager::mspAvoidanceManager->mpAvoidanceStrategy->vfptr->SetLocalModuleFor(
    UFG::NavAvoidanceManager::mspAvoidanceManager->mpAvoidanceStrategy,
    this);
  UFG::NavComponent::SetControllerModule<UFG::NavModuleController>(this);
  this->m_fAvoidanceRadius = 0.5;
  this->m_navParams.m_fRadius = 0.34999999;
  v3 = BYTE1(this->m_navParams.m_flags);
  BYTE1(this->m_navParams.m_flags) = 0;
  this->m_navParams.m_flags |= ((v3 & 0xFFFFFFBF) << 8) | 1;
  m_pNavModuleLocal = this->m_pNavModuleLocal;
  this->m_navParams.m_fRadius = 0.5;
  this->m_fAvoidanceRadius = 0.5;
  m_pNavModuleLocal->vfptr->SetCollisionAvoidanceType(m_pNavModuleLocal, eCOLLISION_AVOIDANCE_EVERYONE);
}

// File Line: 86
// RVA: 0x264FF0
void __fastcall UFG::NavComponent::InitWithParams(
        UFG::NavComponent *this,
        UFG::NavComponent::InitParameters *parameters)
{
  int v2; // eax
  char v3; // r8
  bool v4; // zf
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx
  __int64 v6; // rdx

  this->m_fAvoidanceRadius = 0.5;
  this->m_navParams.m_fRadius = 0.34999999;
  v2 = BYTE1(this->m_navParams.m_flags) & 0xBF;
  BYTE1(this->m_navParams.m_flags) = 0;
  this->m_navParams.m_flags |= v2 << 8;
  if ( parameters->m_bIsFreerunner )
    this->m_navParams.m_flags |= 1u;
  v3 = 1;
  v4 = !parameters->m_bIsAvoidanceEnabled;
  this->m_navParams.m_fRadius = parameters->m_fAIRadius;
  this->m_fAvoidanceRadius = parameters->m_fAIAvoidanceRadius;
  m_pNavModuleLocal = this->m_pNavModuleLocal;
  if ( v4 )
    v3 = 0;
  v6 = 8i64;
  if ( v3 )
    v6 = 0i64;
  m_pNavModuleLocal->vfptr->SetCollisionAvoidanceType(m_pNavModuleLocal, (UFG::eCollisionAvoidanceType)v6);
}

// File Line: 116
// RVA: 0x265DF0
void __fastcall UFG::NavComponent::Reset(UFG::NavComponent *this, bool softReset)
{
  UFG::NavPositionBaseVtbl *vfptr; // rax

  if ( softReset )
  {
    this->m_pNavModulePathing->vfptr->Reset(this->m_pNavModulePathing);
    this->m_pNavModuleLocal->vfptr->Reset(this->m_pNavModuleLocal);
    this->m_pNavModuleController->vfptr->Reset(this->m_pNavModuleController);
  }
  else
  {
    this->vfptr[14].__vecDelDtor(this, (unsigned int)this->m_pSimObject);
  }
  vfptr = this->m_navPosition.vfptr;
  this->m_fMaxAngularVelocity = 0.0;
  vfptr->Invalidate(&this->m_navPosition);
  this->m_fDesiredSpeed = 0.0;
}

// File Line: 139
// RVA: 0x266270
void __fastcall UFG::NavComponent::SetDesiredSpeed(UFG::NavComponent *this, float fDesiredSpeed)
{
  this->m_fDesiredSpeed = fDesiredSpeed;
}

// File Line: 145
// RVA: 0x2642F0
float __fastcall UFG::NavComponent::GetDesiredSpeed(UFG::NavComponent *this)
{
  UFG::NavModulePathing *m_pNavModulePathing; // rax
  float result; // xmm0_4

  m_pNavModulePathing = this->m_pNavModulePathing;
  if ( !m_pNavModulePathing->m_aGoalPoints.size )
    return this->m_fDesiredSpeed;
  result = m_pNavModulePathing->m_aGoalPoints.p->m_speed;
  if ( result <= 0.0 )
    return this->m_fDesiredSpeed;
  return result;
}

// File Line: 156
// RVA: 0x266280
void __fastcall UFG::NavComponent::SetDestinationParams(UFG::NavComponent *this, UFG::NavParams *navParams)
{
  this->m_navParams = *navParams;
}

// File Line: 162
// RVA: 0x265450
void __fastcall UFG::NavComponent::OnAttach(UFG::NavComponent *this, UFG::SimObject *object)
{
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float x; // eax
  float z; // xmm1_4
  float v9; // xmm3_4
  __m128 y_low; // xmm4
  float v11; // xmm1_4
  __m128 v12; // xmm2
  fastdelegate::detail::GenericClass *RCX; // rax
  fastdelegate::FastDelegate1<float,void> v14; // [rsp+30h] [rbp-28h] BYREF
  fastdelegate::FastDelegate1<float,void> v15; // [rsp+40h] [rbp-18h] BYREF

  ((void (__fastcall *)(UFG::NavComponent *))this->vfptr[14].__vecDelDtor)(this);
  if ( object
    && (ComponentOfType = UFG::SimObject::GetComponentOfType(
                            object,
                            UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) != 0i64
    && LODWORD(ComponentOfType[3].m_SafePointerList.mNode.mPrev) != 17 )
  {
    this->m_TicketType = TICKETBOOTH_CRITICAL_NAVCOMPONENT_POSTSTREAMING;
    v14.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) UFG::NavComponent::`vcall{128,{flat}};
    v14.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
    UFG::TicketBoothManager::Register(
      UFG::TicketBoothManager::mpSingleton,
      TICKETBOOTH_CRITICAL_NAVCOMPONENT_POSTSTREAMING,
      &this->m_postStreamingTicket,
      &v14);
  }
  else
  {
    this->m_TicketType = TICKETBOOTH_NON_CRITICAL_NAVCOMPONENT_POSTSTREAMING;
    v14.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))_;
    v14.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
    v15.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) UFG::NavComponent::`vcall{128,{flat}};
    v15.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
    UFG::TicketBoothManager::Register(
      UFG::TicketBoothManager::mpSingleton,
      TICKETBOOTH_NON_CRITICAL_NAVCOMPONENT_POSTSTREAMING,
      &this->m_postStreamingTicket,
      &v15,
      (fastdelegate::FastDelegate0<void> *)&v14);
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  this->m_navPosition.m_vPosition.y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  this->m_navPosition.m_vPosition.z = z;
  this->m_navPosition.m_vPosition.x = x;
  this->m_navPosition.m_bValid = 0;
  this->m_navPosition.vfptr->SetInvalidMeshPosition(&this->m_navPosition);
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v9 = m_pTransformNodeComponent->mWorldTransform.v0.x;
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y);
  v11 = 0.0;
  v12 = y_low;
  v12.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v9 * v9);
  if ( v12.m128_f32[0] != 0.0 )
    v11 = 1.0 / _mm_sqrt_ps(v12).m128_f32[0];
  this->m_vForward.x = v9 * v11;
  this->m_vForward.y = y_low.m128_f32[0] * v11;
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v15.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::NavComponent::DoorStateChangeEventHandler;
  v15.m_Closure.m_pthis = RCX;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v15,
    UFG::gAiDoorStateChangeEventChannel.mUID,
    UFG::gAiDoorStateChangeEventChannel.mName,
    0);
}

// File Line: 192
// RVA: 0x265640
void __fastcall UFG::NavComponent::OnDetach(UFG::NavComponent *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v2; // [rsp+20h] [rbp-18h] BYREF

  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    this->m_TicketType,
    &this->m_postStreamingTicket);
  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::NavComponent::DoorStateChangeEventHandler;
  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v2, UFG::gAiDoorStateChangeEventChannel.mUID);
}

// File Line: 199
// RVA: 0x266620
void __fastcall UFG::NavComponent::TeleportEventHandler(UFG::NavComponent *this, UFG::Event *event)
{
  UFG::Event *v2; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  __m128 v7; // xmm2
  float v8; // xmm1_4
  __m128 v9; // xmm3

  v2 = event;
  LOBYTE(event) = 1;
  this->vfptr[15].__vecDelDtor(this, (unsigned int)event);
  v4 = *((float *)&v2[2].mNext + 1);
  v5 = *(float *)&v2[2].m_EventUID;
  this->m_navPosition.m_vPosition.x = *(float *)&v2[2].mNext;
  this->m_navPosition.m_vPosition.y = v4;
  this->m_navPosition.m_vPosition.z = v5;
  this->m_navPosition.m_bValid = 0;
  this->m_navPosition.vfptr->SetInvalidMeshPosition(&this->m_navPosition);
  v6 = *(float *)&v2[1].m_EventUID;
  v7 = (__m128)*(&v2[1].m_EventUID + 1);
  v8 = 0.0;
  v9 = v7;
  v9.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v6 * v6);
  if ( v9.m128_f32[0] != 0.0 )
    v8 = 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
  this->m_vForward.y = v7.m128_f32[0] * v8;
  this->m_vForward.x = v8 * v6;
}

// File Line: 215
// RVA: 0x264080
void __fastcall UFG::NavComponent::DoorStateChangeEventHandler(UFG::NavComponent *this, UFG::Event *event)
{
  UFG::NavModulePathing *m_pNavModulePathing; // r10
  UFG::NavPath *m_pNavPath; // rdx
  __int64 size; // r8
  __int64 v6; // rcx
  UFG::NavResource **i; // rdx

  if ( BYTE4(event[1].vfptr) )
  {
    m_pNavModulePathing = this->m_pNavModulePathing;
    m_pNavPath = m_pNavModulePathing->m_pPath.m_pNavPath;
    if ( m_pNavPath )
    {
      if ( m_pNavPath->m_aWaypoints.size )
      {
        size = m_pNavPath->m_aResources.size;
        v6 = 0i64;
        if ( m_pNavPath->m_aResources.size )
        {
          for ( i = m_pNavPath->m_aResources.p; (*i)->m_name.mUID != LODWORD(event[1].vfptr); ++i )
          {
            if ( ++v6 >= size )
              return;
          }
          m_pNavModulePathing->m_bRequestReplan = 1;
        }
      }
    }
  }
}

// File Line: 226
// RVA: 0x265090
void __fastcall UFG::NavComponent::InjectPath(
        UFG::NavComponent *this,
        UFG::HavokNavPosition *npSource,
        UFG::HavokNavPosition *npDestination,
        UFG::NavPath *navPath)
{
  UFG::NavModulePathing::SetInjectedPath(this->m_pNavModulePathing, npSource, npDestination, navPath);
}

// File Line: 231
// RVA: 0x265340
bool __fastcall UFG::NavComponent::IsDestinationUnreachable(UFG::NavComponent *this)
{
  UFG::NavModulePathing *m_pNavModulePathing; // rax

  m_pNavModulePathing = this->m_pNavModulePathing;
  return m_pNavModulePathing->m_aGoalPoints.size && m_pNavModulePathing->m_bInvalidPath;
}

// File Line: 240
// RVA: 0x2652D0
bool __fastcall UFG::NavComponent::IsDestinationObstructed(UFG::NavComponent *this)
{
  UFG::NavModulePathing *m_pNavModulePathing; // rdx
  UFG::NavPath *m_pNavPath; // rax
  unsigned int size; // eax
  bool result; // al

  m_pNavModulePathing = this->m_pNavModulePathing;
  result = 0;
  if ( m_pNavModulePathing->m_aGoalPoints.size )
  {
    m_pNavPath = m_pNavModulePathing->m_pPath.m_pNavPath;
    if ( m_pNavPath )
    {
      if ( m_pNavPath->m_aWaypoints.size )
      {
        size = m_pNavModulePathing->m_aGoalPoints.size;
        if ( size )
        {
          if ( UFG::NavSystemBase::ms_pInstance->vfptr->DetectObstacle(
                 UFG::NavSystemBase::ms_pInstance,
                 m_pNavModulePathing->m_navComponent,
                 &m_pNavModulePathing->m_aGoalPoints.p[size - 1].m_npPosition) )
          {
            return 1;
          }
        }
      }
    }
  }
  return result;
}

// File Line: 249
// RVA: 0x2652A0
bool __fastcall UFG::NavComponent::IsCurrentGoalProcessed(UFG::NavComponent *this)
{
  UFG::NavModulePathing *m_pNavModulePathing; // rax

  m_pNavModulePathing = this->m_pNavModulePathing;
  return m_pNavModulePathing->m_aGoalPoints.size && (m_pNavModulePathing->m_aGoalPoints.p->m_status & 0x1C) != 0;
}

// File Line: 254
// RVA: 0x266250
void __fastcall UFG::NavComponent::SetCollisionAvoidanceType(UFG::NavComponent *this, __int64 type)
{
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx

  m_pNavModuleLocal = this->m_pNavModuleLocal;
  if ( m_pNavModuleLocal )
    m_pNavModuleLocal->vfptr->SetCollisionAvoidanceType(m_pNavModuleLocal, (UFG::eCollisionAvoidanceType)type);
}

// File Line: 263
// RVA: 0x264170
__int64 __fastcall UFG::NavComponent::GetCollisionAvoidanceType(UFG::NavComponent *this)
{
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx

  m_pNavModuleLocal = this->m_pNavModuleLocal;
  if ( m_pNavModuleLocal )
    return ((__int64 (__fastcall *)(UFG::NavModuleLocal *))m_pNavModuleLocal->vfptr->GetCollisionAvoidanceType)(m_pNavModuleLocal);
  else
    return 0i64;
}

// File Line: 272
// RVA: 0x2657B0
void __fastcall UFG::NavComponent::PreserveDestination(UFG::NavComponent *this)
{
  this->m_pNavModulePathing->m_bGoalRefreshed = 1;
}

// File Line: 277
// RVA: 0x265250
_BOOL8 __fastcall UFG::NavComponent::IsAtDestination(UFG::NavComponent *this)
{
  return this->m_pNavModulePathing->m_bAtDestination;
}

// File Line: 282
// RVA: 0x2671E0
void __fastcall UFG::NavComponent::UpdatePostStreaming(UFG::NavComponent *this, float dt)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float z; // xmm1_4
  float y; // xmm0_4
  float x; // xmm3_4
  __m128 y_low; // xmm1
  __m128 v9; // xmm2
  float v10; // xmm6_4

  if ( (this->m_Flags & 2) == 0 )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    this->m_navPosition.m_vPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    this->m_navPosition.m_vPosition.z = z;
    this->m_navPosition.m_vPosition.y = y;
    this->m_navPosition.m_bValid = 0;
    ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_navPosition.vfptr->Validate)(&this->m_navPosition);
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    x = m_pTransformNodeComponent->mWorldTransform.v0.x;
    y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y);
    v9 = y_low;
    v9.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
    if ( v9.m128_f32[0] == 0.0 )
      v10 = 0.0;
    else
      v10 = 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
    this->m_vForward.y = y_low.m128_f32[0] * v10;
    this->m_vForward.x = v10 * x;
  }
}

// File Line: 299
// RVA: 0x2642B0
UFG::qVector4 *__fastcall UFG::NavComponent::GetCurrentPosition(UFG::NavComponent *this)
{
  UFG::TransformNodeComponent *m_pSimObject; // rbx

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  return &m_pSimObject->mWorldTransform.v3;
}

// File Line: 308
// RVA: 0x264E60
_BOOL8 __fastcall UFG::NavComponent::HasDestination(UFG::NavComponent *this)
{
  return this->m_pNavModulePathing->m_aGoalPoints.size != 0;
}

// File Line: 313
// RVA: 0x264EF0
bool __fastcall UFG::NavComponent::HasPath(UFG::NavComponent *this)
{
  UFG::NavPath *m_pNavPath; // rcx

  m_pNavPath = this->m_pNavModulePathing->m_pPath.m_pNavPath;
  return m_pNavPath && m_pNavPath->m_aWaypoints.size;
}

// File Line: 318
// RVA: 0x267310
void __fastcall UFG::NavComponent::UpdatePreQuery(UFG::NavComponent *this, float dt)
{
  UFG::NavModulePathing *m_pNavModulePathing; // rax
  UFG::NavPath *m_pNavPath; // rdx

  m_pNavModulePathing = this->m_pNavModulePathing;
  m_pNavPath = m_pNavModulePathing->m_pPath.m_pNavPath;
  if ( m_pNavPath && m_pNavPath->m_aWaypoints.size && m_pNavModulePathing->m_bAtDestination )
    this->m_fDesiredSpeed = 0.0;
}

// File Line: 330
// RVA: 0x267150
void __fastcall UFG::NavComponent::UpdatePostQuery(UFG::NavComponent *this, float dt)
{
  UFG::NavModulePathing *m_pNavModulePathing; // rcx

  m_pNavModulePathing = this->m_pNavModulePathing;
  if ( m_pNavModulePathing->m_aGoalPoints.size )
    ((void (__fastcall *)(UFG::NavModulePathing *))m_pNavModulePathing->vfptr->Update)(m_pNavModulePathing);
}

// File Line: 339
// RVA: 0x2673B0
void __fastcall UFG::NavComponent::UpdateSteering(UFG::NavComponent *this, float dt)
{
  ((void (__fastcall *)(UFG::NavModuleLocal *))this->m_pNavModuleLocal->vfptr->UpdateSteering)(this->m_pNavModuleLocal);
}

// File Line: 344
// RVA: 0x266E00
void __fastcall UFG::NavComponent::UpdateControl(UFG::NavComponent *this, float dt)
{
  UFG::NavPath *m_pNavPath; // rcx

  (*(void (__fastcall **)(UFG::NavModuleLocal *))this->m_pNavModuleLocal->vfptr->gap8)(this->m_pNavModuleLocal);
  m_pNavPath = this->m_pNavModulePathing->m_pPath.m_pNavPath;
  if ( m_pNavPath )
  {
    if ( m_pNavPath->m_aWaypoints.size )
      this->m_pNavModuleController->vfptr->Update(this->m_pNavModuleController);
  }
}

// File Line: 354
// RVA: 0x263340
__int64 __fastcall UFG::NavComponent::AIRayCastHits(
        UFG::NavComponent *this,
        UFG::qVector3 *vEnd,
        UFG::qVector3 *pCollisionPoint)
{
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  __m128 z_low; // xmm0
  void **v7; // [rsp+30h] [rbp-48h] BYREF
  int v8; // [rsp+38h] [rbp-40h]
  int v9; // [rsp+3Ch] [rbp-3Ch]
  int v10; // [rsp+40h] [rbp-38h]
  char v11; // [rsp+48h] [rbp-30h]
  __m128 v12; // [rsp+50h] [rbp-28h]
  __int64 v13; // [rsp+60h] [rbp-18h]

  x_low = (__m128)LODWORD(vEnd->x);
  y_low = (__m128)LODWORD(vEnd->y);
  z_low = (__m128)LODWORD(vEnd->z);
  v11 = 0;
  v13 = -1i64;
  v7 = &UFG::HavokNavPosition::`vftable;
  v8 = x_low.m128_i32[0];
  v9 = y_low.m128_i32[0];
  v10 = z_low.m128_i32[0];
  v12 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  return ((__int64 (__fastcall *)(UFG::NavManager *, UFG::HavokNavPosition *, void ***, UFG::NavParams *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits)(
           UFG::NavManager::ms_pInstance,
           &this->m_navPosition,
           &v7,
           &this->m_navParams,
           pCollisionPoint);
}

// File Line: 361
// RVA: 0x263310
__int64 __fastcall UFG::NavComponent::AIRayCastHits(
        UFG::NavComponent *this,
        UFG::HavokNavPosition *positionEnd,
        UFG::qVector3 *pCollisionPoint)
{
  return ((__int64 (__fastcall *)(UFG::NavManager *, UFG::HavokNavPosition *, UFG::HavokNavPosition *, UFG::NavParams *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits)(
           UFG::NavManager::ms_pInstance,
           &this->m_navPosition,
           positionEnd,
           &this->m_navParams,
           pCollisionPoint);
}

// File Line: 368
// RVA: 0x2640E0
void __fastcall UFG::NavComponent::EnablePathingOnMaterial(
        UFG::NavComponent *this,
        hkaiUFGMaterials material,
        bool enabled)
{
  int v3; // eax

  if ( enabled )
  {
    this->m_navParams.m_flags |= material << 8;
  }
  else
  {
    v3 = BYTE1(this->m_navParams.m_flags);
    BYTE1(this->m_navParams.m_flags) = 0;
    this->m_navParams.m_flags |= (~material & v3) << 8;
  }
}

// File Line: 385
// RVA: 0x263430
void __fastcall UFG::NavComponent::AddGoalPoint(
        UFG::NavComponent *this,
        UFG::HavokNavPosition *npDestination,
        UFG::AiPathGoalMode goalMode,
        float speed,
        float fDestinationTolerance)
{
  UFG::NavModulePathing::AddGoalPointUid(
    this->m_pNavModulePathing,
    npDestination,
    goalMode,
    speed,
    -1,
    -1,
    fDestinationTolerance);
}

// File Line: 390
// RVA: 0x263470
void __fastcall UFG::NavComponent::AddGoalPointUid(
        UFG::NavComponent *this,
        UFG::HavokNavPosition *npDestination,
        UFG::AiPathGoalMode goalMode,
        float speed,
        int userId,
        float fDestinationTolerance)
{
  UFG::NavModulePathing::AddGoalPointUid(
    this->m_pNavModulePathing,
    npDestination,
    goalMode,
    speed,
    userId,
    -1,
    fDestinationTolerance);
}

// File Line: 395
// RVA: 0x263760
void __fastcall UFG::NavComponent::AddGoalPointUidHACK(
        UFG::NavComponent *this,
        UFG::HavokNavPosition *npDestination,
        unsigned int goalMode,
        float speed,
        int userId,
        int maxSearchIteration,
        float fDestinationTolerance)
{
  UFG::NavModulePathing::AddGoalPointUid(
    this->m_pNavModulePathing,
    npDestination,
    goalMode,
    speed,
    userId,
    maxSearchIteration,
    fDestinationTolerance);
}

// File Line: 400
// RVA: 0x264190
bool __fastcall UFG::NavComponent::GetCurrGoalPointInfo(
        UFG::NavComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *direction,
        float *elapsedTime,
        int *uid)
{
  return UFG::NavModulePathing::GetCurrGoalPointInfo(this->m_pNavModulePathing, position, direction, elapsedTime, uid);
}

// File Line: 406
// RVA: 0x264130
void __fastcall UFG::NavComponent::ForceGoalPointAdvance(UFG::NavComponent *this)
{
  UFG::NavModulePathing *m_pNavModulePathing; // rbx

  m_pNavModulePathing = this->m_pNavModulePathing;
  m_pNavModulePathing->m_bForceGoalAdvance = 1;
  UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(&m_pNavModulePathing->m_aGoalPoints, 0);
  m_pNavModulePathing->m_elapsedTimeTowardGoal = 0.0;
}

// File Line: 504
// RVA: 0x264160
float __fastcall UFG::NavComponent::GetAvoidanceRadius(UFG::NavComponent *this)
{
  return this->m_fAvoidanceRadius;
}

