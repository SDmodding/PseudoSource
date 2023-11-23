// File Line: 20
// RVA: 0x669700
void __fastcall UFG::EnvironmentalModel::EnvironmentalModel(
        UFG::EnvironmentalModel *this,
        UFG::VehicleAudioComponent *component)
{
  UFG::qPropertySet *v3; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qPropertySet *mpPropertySet; // rbx
  char *MemImagePtr; // rbx
  __int64 v8; // rax
  UFG::qPropertySet *v9; // rdx
  __int64 v10; // rax
  UFG::qPropertySet *v11; // rdx
  __int64 v12; // rax

  v3 = 0i64;
  this->m_ecSkidInit.m_pEvent = 0i64;
  this->m_ecForceStopSkid.m_pEvent = 0i64;
  *(_QWORD *)&this->m_skidAngle.m_currentValue = 0i64;
  this->m_skidAngle.m_riseRate = 10000000.0;
  this->m_skidAngle.m_fallRate = 10000000.0;
  *(_QWORD *)&this->m_skidAngle.m_max = 1065353216i64;
  *(_QWORD *)&this->m_skidStrength.m_currentValue = 0i64;
  this->m_skidStrength.m_riseRate = 10000000.0;
  this->m_skidStrength.m_fallRate = 10000000.0;
  *(_QWORD *)&this->m_skidStrength.m_max = 1065353216i64;
  *(_QWORD *)&this->m_burnoutAmount.m_currentValue = 0i64;
  this->m_burnoutAmount.m_riseRate = 10000000.0;
  this->m_burnoutAmount.m_fallRate = 10000000.0;
  *(_QWORD *)&this->m_burnoutAmount.m_max = 1065353216i64;
  this->m_skidEvent = 0;
  this->m_pVehAudComponent = component;
  y = component->m_WorldMatrix.v3.y;
  z = component->m_WorldMatrix.v3.z;
  this->m_lastPosOnStairs.x = component->m_WorldMatrix.v3.x;
  this->m_lastPosOnStairs.y = y;
  this->m_lastPosOnStairs.z = z;
  this->m_hangTime = 0.0;
  this->m_onStairs = 0;
  mpPropertySet = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
  else
    MemImagePtr = 0i64;
  v8 = *((_QWORD *)MemImagePtr + 2);
  if ( v8 )
    v9 = (UFG::qPropertySet *)&MemImagePtr[v8 + 16];
  else
    v9 = 0i64;
  UFG::VehicleAudioParameters::SetRLFFromPropertySet(&this->m_burnoutAmount, v9);
  v10 = *((_QWORD *)MemImagePtr + 28);
  if ( v10 )
    v11 = (UFG::qPropertySet *)&MemImagePtr[v10 + 224];
  else
    v11 = 0i64;
  UFG::VehicleAudioParameters::SetRLFFromPropertySet(&this->m_skidAngle, v11);
  v12 = *((_QWORD *)MemImagePtr + 29);
  if ( v12 )
    v3 = (UFG::qPropertySet *)&MemImagePtr[v12 + 232];
  UFG::VehicleAudioParameters::SetRLFFromPropertySet(&this->m_skidStrength, v3);
}

// File Line: 48
// RVA: 0x66CA40
void __fastcall UFG::EnvironmentalModel::~EnvironmentalModel(UFG::EnvironmentalModel *this)
{
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::AudioEvent *v3; // rcx
  UFG::AudioEvent *v4; // rcx
  UFG::AudioEvent *v5; // rcx

  if ( UFG::VehicleAudioComponent::sm_configPs->skids_enabled )
  {
    if ( this->m_ecSkidInit.m_pEvent )
    {
      m_pEvent = this->m_ecSkidInit.m_pEvent;
      if ( m_pEvent )
        UFG::AudioEvent::StopAndForget(m_pEvent, 200);
    }
  }
  if ( this->m_ecForceStopSkid.m_pEvent )
  {
    v3 = this->m_ecForceStopSkid.m_pEvent;
    if ( v3 )
      UFG::AudioEvent::StopAndForget(v3, 0);
  }
  v4 = this->m_ecForceStopSkid.m_pEvent;
  if ( v4 )
    UFG::AudioEvent::OnControllerDestroy(v4);
  v5 = this->m_ecSkidInit.m_pEvent;
  if ( v5 )
    UFG::AudioEvent::OnControllerDestroy(v5);
}

// File Line: 61
// RVA: 0x68C430
void __fastcall UFG::EnvironmentalModel::StartSkid(UFG::EnvironmentalModel *this)
{
  UFG::qPropertySet *mpPropertySet; // rsi
  char *MemImagePtr; // rax
  unsigned int v4; // edx
  UFG::AudioEntity *v5; // rcx
  UFG::AudioEvent *m_pEvent; // rcx

  if ( UFG::VehicleAudioComponent::sm_configPs->skids_enabled && !this->m_ecSkidInit.m_pEvent )
  {
    mpPropertySet = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
    else
      MemImagePtr = 0i64;
    v4 = *((_DWORD *)MemImagePtr + 50);
    v5 = &this->m_pVehAudComponent->UFG::AudioEntity;
    this->m_skidEvent = v4;
    UFG::AudioEntity::CreateAndPlayEvent(v5, v4, &this->m_ecSkidInit, 0i64, 0, 0i64);
  }
  m_pEvent = this->m_ecForceStopSkid.m_pEvent;
  if ( m_pEvent )
    UFG::AudioEvent::StopAndForget(m_pEvent, 0);
}

// File Line: 111
// RVA: 0x6910E0
void __fastcall UFG::EnvironmentalModel::Update(UFG::EnvironmentalModel *this, float delta_sec)
{
  if ( !this->m_ecSkidInit.m_pEvent )
    UFG::EnvironmentalModel::StartSkid(this);
  if ( UFG::VehicleAudioComponent::sm_configPs->skids_enabled )
    UFG::EnvironmentalModel::HandleSkids(this, delta_sec);
  UFG::EnvironmentalModel::HandleJump(this);
  UFG::EnvironmentalModel::HandleStairs(this);
}

// File Line: 137
// RVA: 0x67CF80
void __fastcall UFG::EnvironmentalModel::HandleStairs(UFG::EnvironmentalModel *this)
{
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::VehicleAudioComponent *m_pVehAudComponent; // rdi
  __m128 x_low; // xmm2
  UFG::qPropertySet *mpPropertySet; // rsi
  float v7; // xmm6_4
  char *MemImagePtr; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4

  if ( UFG::EnvironmentalModel::WheelsOnStairs(this) )
  {
    if ( !this->m_onStairs )
    {
      y = this->m_pVehAudComponent->m_WorldMatrix.v3.y;
      z = this->m_pVehAudComponent->m_WorldMatrix.v3.z;
      this->m_lastPosOnStairs.x = this->m_pVehAudComponent->m_WorldMatrix.v3.x;
      this->m_lastPosOnStairs.y = y;
      this->m_lastPosOnStairs.z = z;
    }
    m_pVehAudComponent = this->m_pVehAudComponent;
    this->m_onStairs = 1;
    x_low = (__m128)LODWORD(this->m_lastPosOnStairs.x);
    mpPropertySet = m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - m_pVehAudComponent->m_WorldMatrix.v3.x)
                                      * (float)(x_low.m128_f32[0] - m_pVehAudComponent->m_WorldMatrix.v3.x))
                              + (float)((float)(this->m_lastPosOnStairs.y - m_pVehAudComponent->m_WorldMatrix.v3.y)
                                      * (float)(this->m_lastPosOnStairs.y - m_pVehAudComponent->m_WorldMatrix.v3.y)))
                      + (float)((float)(this->m_lastPosOnStairs.z - m_pVehAudComponent->m_WorldMatrix.v3.z)
                              * (float)(this->m_lastPosOnStairs.z - m_pVehAudComponent->m_WorldMatrix.v3.z));
    LODWORD(v7) = _mm_sqrt_ps(x_low).m128_u32[0];
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
    else
      MemImagePtr = 0i64;
    if ( v7 > *((float *)MemImagePtr + 43) )
    {
      v9 = m_pVehAudComponent->m_WorldMatrix.v3.y;
      v10 = m_pVehAudComponent->m_WorldMatrix.v3.z;
      this->m_lastPosOnStairs.x = m_pVehAudComponent->m_WorldMatrix.v3.x;
      this->m_lastPosOnStairs.y = v9;
      this->m_lastPosOnStairs.z = v10;
      UFG::AudioEntity::CreateAndPlayEvent(&this->m_pVehAudComponent->UFG::AudioEntity, 0xCCBE7650, 0i64, 0, 0i64);
    }
  }
  else
  {
    this->m_onStairs = 0;
  }
}

// File Line: 166
// RVA: 0x69B9D0
char __fastcall UFG::EnvironmentalModel::WheelsOnStairs(UFG::EnvironmentalModel *this)
{
  UFG::SimComponent *m_pPointer; // rdi
  int v3; // ebx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::PhysicsWheeledVehicle *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::PhysicsWheeledVehicle *v7; // rcx
  unsigned __int64 SurfacePropertyHandleUidUnderWheel; // rbp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::PhysicsWheeledVehicle *v10; // rcx
  unsigned __int64 ObjectPropertyHandleUidUnderWheel; // rsi
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v12; // rcx
  const char *TypeName; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v14; // rcx
  const char *v15; // rax
  UFG::qReflectHandleBase v17; // [rsp+28h] [rbp-60h] BYREF
  UFG::qReflectHandleBase v18; // [rsp+50h] [rbp-38h] BYREF

  if ( (_S15_6 & 1) == 0 )
  {
    _S15_6 |= 1u;
    stairsUid = UFG::TiDo::CalcWwiseUid("STAIRS");
  }
  m_pPointer = this->m_pVehAudComponent->m_physicsMoverInterface.m_pPointer;
  v3 = 0;
  if ( SLODWORD(m_pPointer[12].m_BoundComponentHandles.mNode.mNext) <= 0 )
    return 0;
  while ( 1 )
  {
    mPrev = m_pPointer[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      v5 = 0i64;
      if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
        v5 = (UFG::PhysicsWheeledVehicle *)m_pPointer[10].m_SafePointerList.mNode.mPrev;
      if ( v5 && !UFG::PhysicsWheeledVehicle::IsWheelOnGround(v5, v3) )
        goto LABEL_26;
    }
    v6 = m_pPointer[10].m_SafePointerList.mNode.mPrev;
    if ( !v6 )
      goto LABEL_14;
    v7 = 0i64;
    if ( (BYTE4(v6[37].mNext) & 7) != 0 )
      v7 = (UFG::PhysicsWheeledVehicle *)m_pPointer[10].m_SafePointerList.mNode.mPrev;
    if ( v7 )
      SurfacePropertyHandleUidUnderWheel = UFG::PhysicsWheeledVehicle::GetSurfacePropertyHandleUidUnderWheel(v7, v3);
    else
LABEL_14:
      SurfacePropertyHandleUidUnderWheel = 0i64;
    v9 = m_pPointer[10].m_SafePointerList.mNode.mPrev;
    if ( !v9 )
      goto LABEL_20;
    v10 = 0i64;
    if ( (BYTE4(v9[37].mNext) & 7) != 0 )
      v10 = (UFG::PhysicsWheeledVehicle *)m_pPointer[10].m_SafePointerList.mNode.mPrev;
    if ( v10 )
      ObjectPropertyHandleUidUnderWheel = UFG::PhysicsWheeledVehicle::GetObjectPropertyHandleUidUnderWheel(v10, v3);
    else
LABEL_20:
      ObjectPropertyHandleUidUnderWheel = 0i64;
    UFG::qReflectHandleBase::qReflectHandleBase(&v18);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v12);
    v18.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v18, v18.mTypeUID, SurfacePropertyHandleUidUnderWheel);
    if ( v18.mData && BYTE4(v18.mData[1].mBaseNode.mParent) )
      goto LABEL_29;
    UFG::qReflectHandleBase::qReflectHandleBase(&v17);
    v15 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v14);
    v17.mTypeUID = UFG::qStringHash64(v15, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v17, v17.mTypeUID, ObjectPropertyHandleUidUnderWheel);
    if ( v17.mData )
    {
      if ( *(_BYTE *)(v17.mData[4].mBaseNode.mUID + 100) )
        break;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v17);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
LABEL_26:
    if ( ++v3 >= SLODWORD(m_pPointer[12].m_BoundComponentHandles.mNode.mNext) )
      return 0;
  }
  UFG::qReflectHandleBase::~qReflectHandleBase(&v17);
LABEL_29:
  UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
  return 1;
}

// File Line: 218
// RVA: 0x67C8A0
void __fastcall UFG::EnvironmentalModel::HandleJump(UFG::EnvironmentalModel *this)
{
  bool v2; // al
  UFG::SimComponent *m_pPointer; // rsi
  UFG::AudioEntity *v4; // rcx
  UFG::qPropertySet *mpPropertySet; // rdi
  char *MemImagePtr; // rax
  float v7; // xmm6_4
  UFG::qPropertySet *v8; // rdi
  char *v9; // rax
  UFG::qPropertySet *v10; // rdi
  unsigned int v11; // edx
  UFG::qPropertySet *v12; // rdi
  char *v13; // rax
  float v14; // xmm6_4
  UFG::qPropertySet *v15; // rdi
  char *v16; // rax
  UFG::qPropertySet *v17; // rdi
  char *v18; // rax

  v2 = UFG::VehicleAudioComponent::WheelsInAir(this->m_pVehAudComponent);
  m_pPointer = this->m_pVehAudComponent->m_physicsMoverInterface.m_pPointer;
  v4 = &this->m_pVehAudComponent->UFG::AudioEntity;
  if ( v2 )
  {
    this->m_hangTime = UFG::Metrics::msInstance.mSimTimeDelta + this->m_hangTime;
    UFG::AudioEntity::SetRtpcValue(v4, 0xBC5D3BBu, 1.0);
    return;
  }
  UFG::AudioEntity::SetRtpcValue(v4, 0xBC5D3BBu, 0.0);
  mpPropertySet = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
  else
    MemImagePtr = 0i64;
  if ( *((float *)MemImagePtr + 38) >= this->m_hangTime
    || ((v7 = *((float *)&m_pPointer[10].m_BoundComponentHandles.mNode.mPrev + 1),
         v8 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet,
         !Vehicles_Audio_Base_BaseVehicleBase::IsClass(v8->mSchemaName.mUID))
      ? (v9 = 0i64)
      : (v9 = UFG::qPropertySet::GetMemImagePtr(v8)),
        (float)(v7 * 3.5999999) <= *((float *)v9 + 40)) )
  {
    v12 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v12->mSchemaName.mUID) )
      v13 = UFG::qPropertySet::GetMemImagePtr(v12);
    else
      v13 = 0i64;
    if ( *((float *)v13 + 41) >= this->m_hangTime )
      goto LABEL_27;
    v14 = *((float *)&m_pPointer[10].m_BoundComponentHandles.mNode.mPrev + 1);
    v15 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    v16 = Vehicles_Audio_Base_BaseVehicleBase::IsClass(v15->mSchemaName.mUID)
        ? UFG::qPropertySet::GetMemImagePtr(v15)
        : 0i64;
    if ( (float)(v14 * 3.5999999) <= *((float *)v16 + 40) )
      goto LABEL_27;
    v17 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v17->mSchemaName.mUID) )
      v18 = UFG::qPropertySet::GetMemImagePtr(v17);
    else
      v18 = 0i64;
    v11 = *((_DWORD *)v18 + 42);
  }
  else
  {
    v10 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v10->mSchemaName.mUID) )
      v11 = *((_DWORD *)UFG::qPropertySet::GetMemImagePtr(v10) + 39);
    else
      v11 = MEMORY[0x9C];
  }
  UFG::AudioEntity::CreateAndPlayEvent(&this->m_pVehAudComponent->UFG::AudioEntity, v11, 0i64, 0, 0i64);
LABEL_27:
  this->m_hangTime = 0.0;
}

// File Line: 267
// RVA: 0x67CB80
void __fastcall UFG::EnvironmentalModel::HandleSkids(UFG::EnvironmentalModel *this, float deltaTime)
{
  UFG::SimComponent *m_pPointer; // rdi
  float v5; // xmm10_4
  float v6; // xmm7_4
  float v7; // xmm9_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  char *v9; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  int v11; // r8d
  int mNext; // r9d
  __int64 v13; // rax
  float v14; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  float v16; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  float v18; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  unsigned int v20; // eax
  float v21; // xmm11_4
  float v22; // xmm2_4
  float m_targetValue; // xmm1_4
  float m_fallRate; // xmm2_4
  UFG::qPropertySet *mpPropertySet; // rdi
  char *MemImagePtr; // rax
  float v27; // xmm7_4
  UFG::qPropertySet *v28; // rdi
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm7_4
  float m_min; // xmm1_4
  float m_riseRate; // xmm2_4
  float m_max; // xmm1_4
  float v35; // xmm2_4

  m_pPointer = this->m_pVehAudComponent->m_physicsMoverInterface.m_pPointer;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  mPrev = m_pPointer[10].m_SafePointerList.mNode.mPrev;
  v9 = 0i64;
  if ( !mPrev )
    goto LABEL_6;
  v10 = 0i64;
  if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
    v10 = m_pPointer[10].m_SafePointerList.mNode.mPrev;
  if ( !v10 || ((__int64)v10[68].mNext & 0x10) != 0 )
  {
LABEL_6:
    v11 = 0;
    mNext = (int)m_pPointer[12].m_BoundComponentHandles.mNode.mNext;
    if ( mNext > 0 )
    {
      v13 = 848i64;
      do
      {
        v14 = 0.0;
        if ( mPrev )
        {
          v15 = 0i64;
          if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
            v15 = m_pPointer[10].m_SafePointerList.mNode.mPrev;
          if ( v15 )
            v14 = *(float *)((char *)&v15[-2].mPrev + v13);
        }
        if ( v14 > v5 )
          v5 = v14;
        v16 = 0.0;
        if ( mPrev )
        {
          v17 = 0i64;
          if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
            v17 = m_pPointer[10].m_SafePointerList.mNode.mPrev;
          if ( v17 )
            v16 = *(float *)((char *)&v17->mPrev + v13);
        }
        if ( v16 > v6 )
          v6 = v16;
        v18 = 0.0;
        if ( mPrev )
        {
          v19 = 0i64;
          if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
            v19 = m_pPointer[10].m_SafePointerList.mNode.mPrev;
          if ( v19 )
            v18 = *(float *)((char *)&v19[-1].mPrev + v13);
        }
        if ( v18 > v7 )
          v7 = v18;
        ++v11;
        v13 += 4i64;
      }
      while ( v11 < mNext );
    }
  }
  v20 = _S16_6;
  if ( (_S16_6 & 1) == 0 )
  {
    _S16_6 |= 1u;
    skid_angle_rtpc = UFG::TiDo::CalcWwiseUid("skid_angle_player");
    v20 = _S16_6;
  }
  if ( (v20 & 2) == 0 )
  {
    _S16_6 = v20 | 2;
    skid_strength_rtpc = UFG::TiDo::CalcWwiseUid("skid_strength_player");
    v20 = _S16_6;
  }
  if ( v5 == 0.0 )
  {
    v21 = 0.0;
  }
  else
  {
    v22 = 1.0 / fsqrt((float)(v7 * v7) + (float)(v6 * v6));
    v21 = (float)((float)(v22 * v7) * 0.0) + (float)(v22 * v6);
  }
  if ( (v20 & 4) == 0 )
  {
    _S16_6 = v20 | 4;
    burnout_amount_rtpc = UFG::TiDo::CalcWwiseUid("burnout_amount");
  }
  if ( ((__int64)m_pPointer[1].m_pSimObject & 0x20) != 0 && LODWORD(m_pPointer[12].m_BoundComponentHandles.mNode.mNext) )
    this->m_burnoutAmount.m_targetValue = 1.0;
  else
    this->m_burnoutAmount.m_targetValue = 0.0;
  m_targetValue = this->m_burnoutAmount.m_targetValue;
  if ( m_targetValue <= this->m_burnoutAmount.m_min )
    m_targetValue = this->m_burnoutAmount.m_min;
  if ( m_targetValue >= this->m_burnoutAmount.m_max )
    m_targetValue = this->m_burnoutAmount.m_max;
  if ( this->m_burnoutAmount.m_targetValue < this->m_burnoutAmount.m_currentValue )
    m_fallRate = this->m_burnoutAmount.m_fallRate;
  else
    m_fallRate = this->m_burnoutAmount.m_riseRate;
  UFG::qApproach(&this->m_burnoutAmount.m_currentValue, m_targetValue, m_fallRate, deltaTime);
  UFG::AudioEntity::SetRtpcValue(
    &this->m_pVehAudComponent->UFG::AudioEntity,
    burnout_amount_rtpc,
    this->m_burnoutAmount.m_currentValue);
  mpPropertySet = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
  else
    MemImagePtr = 0i64;
  v27 = *((float *)MemImagePtr + 53);
  v28 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v28->mSchemaName.mUID) )
    v9 = UFG::qPropertySet::GetMemImagePtr(v28);
  v29 = *((float *)v9 + 54);
  if ( v29 <= 0.0 )
  {
    v29 = 0.0;
    goto LABEL_59;
  }
  v30 = FLOAT_0_99000001;
  if ( v29 < 0.99000001 )
LABEL_59:
    v30 = v29;
  v31 = (float)(v27 * v5) - v30;
  if ( v31 < 0.0 )
    v31 = 0.0;
  this->m_skidAngle.m_targetValue = v21;
  this->m_skidStrength.m_targetValue = (float)(1.0 / (float)(1.0 - v30)) * v31;
  m_min = v21;
  if ( v21 <= this->m_skidAngle.m_min )
    m_min = this->m_skidAngle.m_min;
  if ( m_min >= this->m_skidAngle.m_max )
    m_min = this->m_skidAngle.m_max;
  if ( v21 < this->m_skidAngle.m_currentValue )
    m_riseRate = this->m_skidAngle.m_fallRate;
  else
    m_riseRate = this->m_skidAngle.m_riseRate;
  UFG::qApproach(&this->m_skidAngle.m_currentValue, m_min, m_riseRate, deltaTime);
  m_max = this->m_skidStrength.m_targetValue;
  if ( m_max <= this->m_skidStrength.m_min )
    m_max = this->m_skidStrength.m_min;
  if ( m_max >= this->m_skidStrength.m_max )
    m_max = this->m_skidStrength.m_max;
  if ( this->m_skidStrength.m_targetValue < this->m_skidStrength.m_currentValue )
    v35 = this->m_skidStrength.m_fallRate;
  else
    v35 = this->m_skidStrength.m_riseRate;
  UFG::qApproach(&this->m_skidStrength.m_currentValue, m_max, v35, deltaTime);
  UFG::AudioEntity::SetRtpcValue(
    &this->m_pVehAudComponent->UFG::AudioEntity,
    skid_angle_rtpc,
    this->m_skidAngle.m_currentValue);
  UFG::AudioEntity::SetRtpcValue(
    &this->m_pVehAudComponent->UFG::AudioEntity,
    skid_strength_rtpc,
    this->m_skidStrength.m_currentValue);
}

