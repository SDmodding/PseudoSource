// File Line: 27
// RVA: 0x1476290
__int64 dynamic_initializer_for__UFG::NavComponent::s_NavComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::NavComponent::s_NavComponentList__);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gAiDoorStateChangeEventChannel__);
}

// File Line: 48
// RVA: 0x262650
void __fastcall UFG::NavComponent::NavComponent(UFG::NavComponent *this, unsigned int name_uid)
{
  UFG::NavComponent *v2; // rbx
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v3; // rdx
  float v4; // xmm1_4
  float v5; // xmm2_4
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v6; // rax
  UFG::Ticket *v7; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::NavComponent::`vftable';
  v2->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v2->m_navPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  v2->m_navPosition.m_vPosition.y = v4;
  v2->m_navPosition.m_vPosition.z = v5;
  v2->m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
  v2->m_navPosition.m_bValid = 0;
  *(_QWORD *)&v2->m_navPosition.m_packedKey = -1i64;
  v2->m_navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(UFG::qVector3::msZero.x),
                                                   (__m128)LODWORD(UFG::qVector3::msZero.z)),
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(UFG::qVector3::msZero.y),
                                                   (__m128)(unsigned int)FLOAT_1_0));
  v2->m_pNavModulePathing = 0i64;
  v2->m_pNavModuleLocal = 0i64;
  v2->m_pNavModuleController = 0i64;
  v2->m_fDesiredSpeed = 0.0;
  v2->m_fAvoidanceRadius = 0.5;
  v2->m_bIsSloppyFreeRunner = 0;
  v2->m_fMaxAngularVelocity = 0.0;
  v2->m_iHasSteeringControl = 0;
  v2->m_navParams.m_fRadius = 0.0;
  v2->m_navParams.m_flags = 65280;
  v7 = &v2->m_postStreamingTicket;
  v7->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v7->mPrev;
  v2->m_postStreamingTicket.mTimestamp = 0i64;
  v2->m_postStreamingTicket.mActiveCallback.m_Closure.m_pthis = 0i64;
  v2->m_postStreamingTicket.mActiveCallback.m_Closure.m_pFunction = 0i64;
  v2->m_postStreamingTicket.mInactiveCallback.m_Closure.m_pthis = 0i64;
  v2->m_postStreamingTicket.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  v2->m_TicketType = 5;
  v6 = UFG::NavComponent::s_NavComponentList.mNode.mPrev;
  UFG::NavComponent::s_NavComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)&v2->mPrev;
  v3->mPrev = v6;
  v2->mNext = (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)&UFG::NavComponent::s_NavComponentList;
  UFG::NavComponent::s_NavComponentList.mNode.mPrev = (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v2->vfptr, UFG::NavComponent::_NavComponentTypeUID, "NavComponent");
}

// File Line: 54
// RVA: 0x262D90
void __fastcall UFG::NavComponent::~NavComponent(UFG::NavComponent *this)
{
  UFG::NavComponent *v1; // rbx
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v2; // rdi
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v3; // rcx
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v4; // rax
  UFG::NavModulePathing *v5; // rcx
  UFG::NavModuleLocal *v6; // rcx
  UFG::NavModuleController *v7; // rcx
  UFG::Ticket *v8; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v9; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v10; // rax
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v11; // rcx
  UFG::qNode<UFG::NavComponent,UFG::NavComponent> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::NavComponent::`vftable';
  if ( this == UFG::NavComponent::s_NavComponentpCurrentIterator )
    UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::NavComponent,UFG::NavComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->m_pNavModulePathing;
  if ( v5 )
    v5->vfptr->__vecDelDtor(v5, 1u);
  v6 = v1->m_pNavModuleLocal;
  if ( v6 )
    v6->vfptr->__vecDelDtor(v6, 1u);
  v7 = v1->m_pNavModuleController;
  if ( v7 )
    v7->vfptr->__vecDelDtor(v7, 1u);
  v8 = &v1->m_postStreamingTicket;
  v9 = v1->m_postStreamingTicket.mPrev;
  v10 = v1->m_postStreamingTicket.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v8->mPrev;
  v11 = v2->mPrev;
  v12 = v2->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 75
// RVA: 0x264F60
void __fastcall UFG::NavComponent::Init(UFG::NavComponent *this, UFG::SimObject *pSimObject)
{
  UFG::NavComponent *v2; // rbx
  int v3; // eax
  UFG::NavModuleLocal *v4; // rcx

  v2 = this;
  UFG::NavComponent::SetPathingModule<UFG::NavModulePathing>(this);
  UFG::NavAvoidanceManager::mspAvoidanceManager->mpAvoidanceStrategy->vfptr->SetLocalModuleFor(
    UFG::NavAvoidanceManager::mspAvoidanceManager->mpAvoidanceStrategy,
    v2);
  UFG::NavComponent::SetControllerModule<UFG::NavModuleController>(v2);
  v2->m_fAvoidanceRadius = 0.5;
  v2->m_navParams.m_fRadius = 0.34999999;
  v3 = BYTE1(v2->m_navParams.m_flags);
  BYTE1(v2->m_navParams.m_flags) = 0;
  v2->m_navParams.m_flags |= ((v3 & 0xFFFFFFBF) << 8) | 1;
  v4 = v2->m_pNavModuleLocal;
  v2->m_navParams.m_fRadius = 0.5;
  v2->m_fAvoidanceRadius = 0.5;
  v4->vfptr->SetCollisionAvoidanceType(v4, 0i64);
}

// File Line: 86
// RVA: 0x264FF0
void __fastcall UFG::NavComponent::InitWithParams(UFG::NavComponent *this, UFG::NavComponent::InitParameters *parameters)
{
  int v2; // eax
  char v3; // r8
  bool v4; // zf
  UFG::NavModuleLocal *v5; // rcx
  signed __int64 v6; // rdx

  this->m_fAvoidanceRadius = 0.5;
  this->m_navParams.m_fRadius = 0.34999999;
  v2 = BYTE1(this->m_navParams.m_flags) & 0xBF;
  BYTE1(this->m_navParams.m_flags) = 0;
  this->m_navParams.m_flags |= v2 << 8;
  if ( parameters->m_bIsFreerunner )
    this->m_navParams.m_flags |= 1u;
  v3 = 1;
  v4 = parameters->m_bIsAvoidanceEnabled == 0;
  this->m_navParams.m_fRadius = parameters->m_fAIRadius;
  this->m_fAvoidanceRadius = parameters->m_fAIAvoidanceRadius;
  v5 = this->m_pNavModuleLocal;
  if ( v4 )
    v3 = 0;
  v6 = 8i64;
  if ( v3 )
    v6 = 0i64;
  v5->vfptr->SetCollisionAvoidanceType(v5, (UFG::eCollisionAvoidanceType)v6);
}

// File Line: 116
// RVA: 0x265DF0
void __fastcall UFG::NavComponent::Reset(UFG::NavComponent *this, bool softReset)
{
  UFG::NavComponent *v2; // rbx
  UFG::NavPositionBaseVtbl *v3; // rax

  v2 = this;
  if ( softReset )
  {
    ((void (*)(void))this->m_pNavModulePathing->vfptr->Reset)();
    ((void (*)(void))v2->m_pNavModuleLocal->vfptr->Reset)();
    ((void (*)(void))v2->m_pNavModuleController->vfptr->Reset)();
  }
  else
  {
    this->vfptr[14].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)this, (unsigned int)this->m_pSimObject);
  }
  v3 = v2->m_navPosition.vfptr;
  v2->m_fMaxAngularVelocity = 0.0;
  v3->Invalidate((UFG::NavPositionBase *)&v2->m_navPosition.vfptr);
  v2->m_fDesiredSpeed = 0.0;
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
  UFG::NavModulePathing *v1; // rax
  float result; // xmm0_4

  v1 = this->m_pNavModulePathing;
  if ( !v1->m_aGoalPoints.size || (result = v1->m_aGoalPoints.p->m_speed, result <= 0.0) )
    result = this->m_fDesiredSpeed;
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
  UFG::SimObject *v2; // rdi
  UFG::NavComponent *v3; // rbx
  UFG::SimComponent *v4; // rax
  UFG::SimObject *v5; // rsi
  UFG::TransformNodeComponent *v6; // rsi
  float v7; // eax
  signed __int64 v8; // rcx
  float v9; // xmm1_4
  float v10; // xmm3_4
  __m128 v11; // xmm4
  float v12; // xmm1_4
  __m128 v13; // xmm2
  hkSeekableStreamReader *v14; // rax
  hkSeekableStreamReader *v15; // [rsp+30h] [rbp-28h]
  __int64 (__fastcall *v16)(__int64); // [rsp+38h] [rbp-20h]
  hkSeekableStreamReader *v17; // [rsp+40h] [rbp-18h]
  __int64 (__fastcall *v18)(__int64); // [rsp+48h] [rbp-10h]

  v2 = object;
  v3 = this;
  ((void (*)(void))this->vfptr[14].__vecDelDtor)();
  if ( v2
    && (v4 = UFG::SimObject::GetComponentOfType(v2, UFG::SimObjectCharacterPropertiesComponent::_TypeUID)) != 0i64
    && LODWORD(v4[3].m_SafePointerList.mNode.mPrev) != 17 )
  {
    v3->m_TicketType = 5;
    v16 =  UFG::NavComponent::`vcall'{128,{flat}};
    v15 = Assembly::GetRCX(v3);
    UFG::TicketBoothManager::Register(
      UFG::TicketBoothManager::mpSingleton,
      TICKETBOOTH_CRITICAL_NAVCOMPONENT_POSTSTREAMING,
      &v3->m_postStreamingTicket,
      (fastdelegate::FastDelegate1<float,void> *)&v15);
  }
  else
  {
    v3->m_TicketType = 4;
    v16 = (__int64 (__fastcall *)(__int64))_;
    v15 = Assembly::GetRCX(v3);
    v18 =  UFG::NavComponent::`vcall'{128,{flat}};
    v17 = Assembly::GetRCX(v3);
    UFG::TicketBoothManager::Register(
      UFG::TicketBoothManager::mpSingleton,
      TICKETBOOTH_NON_CRITICAL_NAVCOMPONENT_POSTSTREAMING,
      &v3->m_postStreamingTicket,
      (fastdelegate::FastDelegate1<float,void> *)&v17,
      (fastdelegate::FastDelegate0<void> *)&v15);
  }
  v5 = v3->m_pSimObject;
  if ( v5 )
    v6 = v5->m_pTransformNodeComponent;
  else
    v6 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v7 = v6->mWorldTransform.v3.x;
  v8 = (signed __int64)&v3->m_navPosition;
  v9 = v6->mWorldTransform.v3.z;
  *(float *)(v8 + 12) = v6->mWorldTransform.v3.y;
  *(float *)(v8 + 16) = v9;
  *(float *)(v8 + 8) = v7;
  *(_BYTE *)(v8 + 24) = 0;
  ((void (*)(void))v3->m_navPosition.vfptr->SetInvalidMeshPosition)();
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v10 = v6->mWorldTransform.v0.x;
  v11 = (__m128)LODWORD(v6->mWorldTransform.v0.y);
  v12 = 0.0;
  v13 = v11;
  v13.m128_f32[0] = (float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10);
  if ( v13.m128_f32[0] != 0.0 )
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
  v3->m_vForward.x = v10 * v12;
  v3->m_vForward.y = v11.m128_f32[0] * v12;
  v14 = Assembly::GetRCX(v3);
  v18 = (__int64 (__fastcall *)(__int64))UFG::NavComponent::DoorStateChangeEventHandler;
  v17 = v14;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v17,
    UFG::gAiDoorStateChangeEventChannel.mUID,
    UFG::gAiDoorStateChangeEventChannel.mName,
    0);
}

// File Line: 192
// RVA: 0x265640
void __fastcall UFG::NavComponent::OnDetach(UFG::NavComponent *this)
{
  UFG::NavComponent *v1; // rbx
  hkSeekableStreamReader *v2; // [rsp+20h] [rbp-18h]
  void (__fastcall *v3)(UFG::NavComponent *, UFG::Event *); // [rsp+28h] [rbp-10h]

  v1 = this;
  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    this->m_TicketType,
    &this->m_postStreamingTicket);
  v3 = UFG::NavComponent::DoorStateChangeEventHandler;
  v2 = Assembly::GetRCX(v1);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
    UFG::gAiDoorStateChangeEventChannel.mUID);
}

// File Line: 199
// RVA: 0x266620
void __fastcall UFG::NavComponent::TeleportEventHandler(UFG::NavComponent *this, UFG::Event *event)
{
  UFG::Event *v2; // rbx
  UFG::NavComponent *v3; // rdi
  int v4; // xmm0_4
  unsigned int v5; // xmm1_4
  signed __int64 v6; // rcx
  float v7; // xmm4_4
  __m128 v8; // xmm2
  float v9; // xmm1_4
  __m128 v10; // xmm3

  v2 = event;
  LOBYTE(event) = 1;
  v3 = this;
  this->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)this, (unsigned int)event);
  v4 = HIDWORD(v2[2].mNext);
  v5 = v2[2].m_EventUID;
  v6 = (signed __int64)&v3->m_navPosition;
  *(_DWORD *)(v6 + 8) = v2[2].mNext;
  *(_DWORD *)(v6 + 12) = v4;
  *(_DWORD *)(v6 + 16) = v5;
  *(_BYTE *)(v6 + 24) = 0;
  ((void (*)(void))v3->m_navPosition.vfptr->SetInvalidMeshPosition)();
  v7 = *(float *)&v2[1].m_EventUID;
  v8 = (__m128)*(&v2[1].m_EventUID + 1);
  v9 = 0.0;
  v10 = v8;
  v10.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7);
  if ( v10.m128_f32[0] != 0.0 )
    v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v3->m_vForward.y = v8.m128_f32[0] * v9;
  v3->m_vForward.x = v9 * v7;
}

// File Line: 215
// RVA: 0x264080
void __fastcall UFG::NavComponent::DoorStateChangeEventHandler(UFG::NavComponent *this, UFG::Event *event)
{
  UFG::Event *v2; // rax
  UFG::NavModulePathing *v3; // r10
  UFG::NavPath *v4; // rdx
  __int64 v5; // r8
  __int64 v6; // rcx
  UFG::NavResource **v7; // rdx

  v2 = event;
  if ( BYTE4(event[1].vfptr) )
  {
    v3 = this->m_pNavModulePathing;
    v4 = v3->m_pPath.m_pNavPath;
    if ( v4 )
    {
      if ( v4->m_aWaypoints.size )
      {
        v5 = v4->m_aResources.size;
        v6 = 0i64;
        if ( v5 > 0 )
        {
          v7 = v4->m_aResources.p;
          while ( (*v7)->m_name.mUID != LODWORD(v2[1].vfptr) )
          {
            ++v6;
            ++v7;
            if ( v6 >= v5 )
              return;
          }
          v3->m_bRequestReplan = 1;
        }
      }
    }
  }
}

// File Line: 226
// RVA: 0x265090
void __fastcall UFG::NavComponent::InjectPath(UFG::NavComponent *this, UFG::HavokNavPosition *npSource, UFG::HavokNavPosition *npDestination, UFG::NavPath *navPath)
{
  UFG::NavModulePathing::SetInjectedPath(this->m_pNavModulePathing, npSource, npDestination, navPath);
}

// File Line: 231
// RVA: 0x265340
bool __fastcall UFG::NavComponent::IsDestinationUnreachable(UFG::NavComponent *this)
{
  UFG::NavModulePathing *v1; // rax

  v1 = this->m_pNavModulePathing;
  return v1->m_aGoalPoints.size && v1->m_bInvalidPath;
}

// File Line: 240
// RVA: 0x2652D0
bool __fastcall UFG::NavComponent::IsDestinationObstructed(UFG::NavComponent *this)
{
  UFG::NavModulePathing *v1; // rdx
  UFG::NavPath *v2; // rax
  unsigned int v3; // eax
  bool result; // al

  v1 = this->m_pNavModulePathing;
  result = 0;
  if ( v1->m_aGoalPoints.size )
  {
    v2 = v1->m_pPath.m_pNavPath;
    if ( v2 )
    {
      if ( v2->m_aWaypoints.size )
      {
        v3 = v1->m_aGoalPoints.size;
        if ( v3 )
        {
          if ( UFG::NavSystemBase::ms_pInstance->vfptr->DetectObstacle(
                 UFG::NavSystemBase::ms_pInstance,
                 v1->m_navComponent,
                 &v1->m_aGoalPoints.p[v3 - 1].m_npPosition) )
          {
            result = 1;
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
  UFG::NavModulePathing *v1; // rax

  v1 = this->m_pNavModulePathing;
  return v1->m_aGoalPoints.size && v1->m_aGoalPoints.p->m_status & 0x1C;
}

// File Line: 254
// RVA: 0x266250
void __fastcall UFG::NavComponent::SetCollisionAvoidanceType(UFG::NavComponent *this, __int64 type)
{
  UFG::NavModuleLocal *v2; // rcx

  v2 = this->m_pNavModuleLocal;
  if ( v2 )
    v2->vfptr->SetCollisionAvoidanceType(v2, (UFG::eCollisionAvoidanceType)type);
}

// File Line: 263
// RVA: 0x264170
__int64 __fastcall UFG::NavComponent::GetCollisionAvoidanceType(UFG::NavComponent *this)
{
  UFG::NavModuleLocal *v1; // rcx
  __int64 result; // rax

  v1 = this->m_pNavModuleLocal;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr->GetCollisionAvoidanceType)();
  else
    result = 0i64;
  return result;
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
  UFG::NavComponent *v2; // rbx
  UFG::SimObject *v3; // rax
  UFG::TransformNodeComponent *v4; // rdi
  signed __int64 v5; // rcx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm3_4
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  float v11; // xmm6_4

  v2 = this;
  if ( !((LOBYTE(this->m_Flags) >> 1) & 1) )
  {
    v3 = this->m_pSimObject;
    if ( v3 )
      v4 = v3->m_pTransformNodeComponent;
    else
      v4 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v5 = (signed __int64)&v2->m_navPosition;
    v6 = v4->mWorldTransform.v3.z;
    v7 = v4->mWorldTransform.v3.y;
    *(float *)(v5 + 8) = v4->mWorldTransform.v3.x;
    *(float *)(v5 + 16) = v6;
    *(float *)(v5 + 12) = v7;
    *(_BYTE *)(v5 + 24) = 0;
    ((void (*)(void))v2->m_navPosition.vfptr->Validate)();
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v8 = v4->mWorldTransform.v0.x;
    v9 = (__m128)LODWORD(v4->mWorldTransform.v0.y);
    v10 = v9;
    v10.m128_f32[0] = (float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8);
    if ( v10.m128_f32[0] == 0.0 )
      v11 = 0.0;
    else
      v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
    v2->m_vForward.y = v9.m128_f32[0] * v11;
    v2->m_vForward.x = v11 * v8;
  }
}

// File Line: 299
// RVA: 0x2642B0
UFG::qVector4 *__fastcall UFG::NavComponent::GetCurrentPosition(UFG::NavComponent *this)
{
  UFG::TransformNodeComponent *v1; // rbx

  v1 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( v1 )
    v1 = (UFG::TransformNodeComponent *)v1->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v1);
  return &v1->mWorldTransform.v3;
}

// File Line: 308
// RVA: 0x264E60
bool __fastcall UFG::NavComponent::HasDestination(UFG::NavComponent *this)
{
  return this->m_pNavModulePathing->m_aGoalPoints.size != 0;
}

// File Line: 313
// RVA: 0x264EF0
bool __fastcall UFG::NavComponent::HasPath(UFG::NavComponent *this)
{
  UFG::NavPath *v1; // rcx

  v1 = this->m_pNavModulePathing->m_pPath.m_pNavPath;
  return v1 && v1->m_aWaypoints.size;
}

// File Line: 318
// RVA: 0x267310
void __fastcall UFG::NavComponent::UpdatePreQuery(UFG::NavComponent *this, float dt)
{
  UFG::NavModulePathing *v2; // rax
  UFG::NavPath *v3; // rdx

  v2 = this->m_pNavModulePathing;
  v3 = v2->m_pPath.m_pNavPath;
  if ( v3 && v3->m_aWaypoints.size )
  {
    if ( v2->m_bAtDestination )
      this->m_fDesiredSpeed = 0.0;
  }
}

// File Line: 330
// RVA: 0x267150
void __fastcall UFG::NavComponent::UpdatePostQuery(UFG::NavComponent *this, float dt)
{
  UFG::NavModulePathing *v2; // rcx

  v2 = this->m_pNavModulePathing;
  if ( v2->m_aGoalPoints.size )
    ((void (*)(void))v2->vfptr->Update)();
}

// File Line: 339
// RVA: 0x2673B0
void __fastcall UFG::NavComponent::UpdateSteering(UFG::NavComponent *this, float dt)
{
  ((void (*)(void))this->m_pNavModuleLocal->vfptr->UpdateSteering)();
}

// File Line: 344
// RVA: 0x266E00
void __fastcall UFG::NavComponent::UpdateControl(UFG::NavComponent *this, float dt)
{
  UFG::NavComponent *v2; // rbx
  UFG::NavPath *v3; // rcx

  v2 = this;
  (*(void (**)(void))this->m_pNavModuleLocal->vfptr->gap8)();
  v3 = v2->m_pNavModulePathing->m_pPath.m_pNavPath;
  if ( v3 )
  {
    if ( v3->m_aWaypoints.size )
      ((void (*)(void))v2->m_pNavModuleController->vfptr->Update)();
  }
}

// File Line: 354
// RVA: 0x263340
__int64 __fastcall UFG::NavComponent::AIRayCastHits(UFG::NavComponent *this, UFG::qVector3 *vEnd, UFG::qVector3 *pCollisionPoint)
{
  __m128 v3; // xmm3
  __m128 v4; // xmm2
  __m128 v5; // xmm0
  void **v7; // [rsp+30h] [rbp-48h]
  int v8; // [rsp+38h] [rbp-40h]
  int v9; // [rsp+3Ch] [rbp-3Ch]
  int v10; // [rsp+40h] [rbp-38h]
  char v11; // [rsp+48h] [rbp-30h]
  __m128 v12; // [rsp+50h] [rbp-28h]
  __int64 v13; // [rsp+60h] [rbp-18h]

  v3 = (__m128)LODWORD(vEnd->x);
  v4 = (__m128)LODWORD(vEnd->y);
  v5 = (__m128)LODWORD(vEnd->z);
  v11 = 0;
  v13 = -1i64;
  v7 = &UFG::HavokNavPosition::`vftable';
  v8 = v3.m128_i32[0];
  v9 = v4.m128_i32[0];
  v10 = v5.m128_i32[0];
  v12 = _mm_unpacklo_ps(_mm_unpacklo_ps(v3, v5), _mm_unpacklo_ps(v4, (__m128)(unsigned int)FLOAT_1_0));
  return UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
           UFG::NavManager::ms_pInstance,
           &this->m_navPosition,
           (UFG::HavokNavPosition *)&v7,
           &this->m_navParams,
           pCollisionPoint);
}

// File Line: 361
// RVA: 0x263310
__int64 __fastcall UFG::NavComponent::AIRayCastHits(UFG::NavComponent *this, UFG::HavokNavPosition *positionEnd, UFG::qVector3 *pCollisionPoint)
{
  return UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
           UFG::NavManager::ms_pInstance,
           &this->m_navPosition,
           positionEnd,
           &this->m_navParams,
           pCollisionPoint);
}

// File Line: 368
// RVA: 0x2640E0
void __fastcall UFG::NavComponent::EnablePathingOnMaterial(UFG::NavComponent *this, hkaiUFGMaterials material, bool enabled)
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
void __fastcall UFG::NavComponent::AddGoalPoint(UFG::NavComponent *this, UFG::HavokNavPosition *npDestination, UFG::AiPathGoalMode goalMode, float speed, float fDestinationTolerance)
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
void __fastcall UFG::NavComponent::AddGoalPointUid(UFG::NavComponent *this, UFG::HavokNavPosition *npDestination, UFG::AiPathGoalMode goalMode, float speed, int userId, float fDestinationTolerance)
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
void __fastcall UFG::NavComponent::AddGoalPointUidHACK(UFG::NavComponent *this, UFG::HavokNavPosition *npDestination, UFG::AiPathGoalMode goalMode, float speed, int userId, int maxSearchIteration, float fDestinationTolerance)
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
bool __fastcall UFG::NavComponent::GetCurrGoalPointInfo(UFG::NavComponent *this, UFG::qVector3 *position, UFG::qVector3 *direction, float *elapsedTime, int *uid)
{
  return UFG::NavModulePathing::GetCurrGoalPointInfo(this->m_pNavModulePathing, position, direction, elapsedTime, uid);
}

// File Line: 406
// RVA: 0x264130
void __fastcall UFG::NavComponent::ForceGoalPointAdvance(UFG::NavComponent *this)
{
  UFG::NavModulePathing *v1; // rbx

  v1 = this->m_pNavModulePathing;
  v1->m_bForceGoalAdvance = 1;
  UFG::qArray<UFG::NavModulePathing::GoalPoint,0>::StableDelete(&v1->m_aGoalPoints, 0);
  v1->m_elapsedTimeTowardGoal = 0.0;
}

// File Line: 504
// RVA: 0x264160
float __fastcall UFG::NavComponent::GetAvoidanceRadius(UFG::NavComponent *this)
{
  return this->m_fAvoidanceRadius;
}

