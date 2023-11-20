// File Line: 20
// RVA: 0x669700
void __fastcall UFG::EnvironmentalModel::EnvironmentalModel(UFG::EnvironmentalModel *this, UFG::VehicleAudioComponent *component)
{
  UFG::EnvironmentalModel *v2; // rsi
  UFG::qPropertySet *v3; // rdi
  float v4; // xmm1_4
  float v5; // xmm2_4
  UFG::qPropertySet *v6; // rbx
  char *v7; // rbx
  __int64 v8; // rax
  UFG::qPropertySet *v9; // rdx
  __int64 v10; // rax
  UFG::qPropertySet *v11; // rdx
  __int64 v12; // rax

  v2 = this;
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
  v4 = component->m_WorldMatrix.v3.y;
  v5 = component->m_WorldMatrix.v3.z;
  this->m_lastPosOnStairs.x = component->m_WorldMatrix.v3.x;
  this->m_lastPosOnStairs.y = v4;
  this->m_lastPosOnStairs.z = v5;
  this->m_hangTime = 0.0;
  this->m_onStairs = 0;
  v6 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v6->mSchemaName.mUID) )
    v7 = UFG::qPropertySet::GetMemImagePtr(v6);
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 2);
  if ( v8 )
    v9 = (UFG::qPropertySet *)&v7[v8 + 16];
  else
    v9 = 0i64;
  UFG::VehicleAudioParameters::SetRLFFromPropertySet(&v2->m_burnoutAmount, v9);
  v10 = *((_QWORD *)v7 + 28);
  if ( v10 )
    v11 = (UFG::qPropertySet *)&v7[v10 + 224];
  else
    v11 = 0i64;
  UFG::VehicleAudioParameters::SetRLFFromPropertySet(&v2->m_skidAngle, v11);
  v12 = *((_QWORD *)v7 + 29);
  if ( v12 )
    v3 = (UFG::qPropertySet *)&v7[v12 + 232];
  UFG::VehicleAudioParameters::SetRLFFromPropertySet(&v2->m_skidStrength, v3);
}

// File Line: 48
// RVA: 0x66CA40
void __fastcall UFG::EnvironmentalModel::~EnvironmentalModel(UFG::EnvironmentalModel *this)
{
  UFG::EnvironmentalModel *v1; // rbx
  UFG::AudioEvent *v2; // rcx
  UFG::AudioEvent *v3; // rcx
  UFG::AudioEvent *v4; // rcx
  UFG::AudioEvent *v5; // rcx

  v1 = this;
  if ( UFG::VehicleAudioComponent::sm_configPs->skids_enabled )
  {
    if ( this->m_ecSkidInit.m_pEvent )
    {
      v2 = this->m_ecSkidInit.m_pEvent;
      if ( v2 )
        UFG::AudioEvent::StopAndForget(v2, 0xC8u);
    }
  }
  if ( v1->m_ecForceStopSkid.m_pEvent )
  {
    v3 = v1->m_ecForceStopSkid.m_pEvent;
    if ( v3 )
      UFG::AudioEvent::StopAndForget(v3, 0);
  }
  v4 = v1->m_ecForceStopSkid.m_pEvent;
  if ( v4 )
    UFG::AudioEvent::OnControllerDestroy(v4);
  v5 = v1->m_ecSkidInit.m_pEvent;
  if ( v5 )
    UFG::AudioEvent::OnControllerDestroy(v5);
}

// File Line: 61
// RVA: 0x68C430
void __fastcall UFG::EnvironmentalModel::StartSkid(UFG::EnvironmentalModel *this)
{
  UFG::EnvironmentalModel *v1; // rbx
  UFG::qPropertySet *v2; // rsi
  char *v3; // rax
  unsigned int v4; // edx
  UFG::AudioEntity *v5; // rcx
  UFG::AudioEvent *v6; // rcx

  v1 = this;
  if ( UFG::VehicleAudioComponent::sm_configPs->skids_enabled && !this->m_ecSkidInit.m_pEvent )
  {
    v2 = this->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v2->mSchemaName.mUID) )
      v3 = UFG::qPropertySet::GetMemImagePtr(v2);
    else
      v3 = 0i64;
    v4 = *((_DWORD *)v3 + 50);
    v5 = (UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr;
    v1->m_skidEvent = v4;
    UFG::AudioEntity::CreateAndPlayEvent(v5, v4, &v1->m_ecSkidInit, 0i64, 0, 0i64);
  }
  v6 = v1->m_ecForceStopSkid.m_pEvent;
  if ( v6 )
    UFG::AudioEvent::StopAndForget(v6, 0);
}

// File Line: 111
// RVA: 0x6910E0
void __fastcall UFG::EnvironmentalModel::Update(UFG::EnvironmentalModel *this, float delta_sec)
{
  UFG::EnvironmentalModel *v2; // rbx

  v2 = this;
  if ( !this->m_ecSkidInit.m_pEvent )
    UFG::EnvironmentalModel::StartSkid(this);
  if ( UFG::VehicleAudioComponent::sm_configPs->skids_enabled )
    UFG::EnvironmentalModel::HandleSkids(v2, delta_sec);
  UFG::EnvironmentalModel::HandleJump(v2);
  UFG::EnvironmentalModel::HandleStairs(v2);
}

// File Line: 137
// RVA: 0x67CF80
void __fastcall UFG::EnvironmentalModel::HandleStairs(UFG::EnvironmentalModel *this)
{
  UFG::EnvironmentalModel *v1; // rbx
  float v2; // xmm0_4
  float v3; // xmm1_4
  UFG::VehicleAudioComponent *v4; // rdi
  __m128 v5; // xmm2
  UFG::qPropertySet *v6; // rsi
  float v7; // xmm6_4
  char *v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4

  v1 = this;
  if ( UFG::EnvironmentalModel::WheelsOnStairs(this) )
  {
    if ( !v1->m_onStairs )
    {
      v2 = v1->m_pVehAudComponent->m_WorldMatrix.v3.y;
      v3 = v1->m_pVehAudComponent->m_WorldMatrix.v3.z;
      v1->m_lastPosOnStairs.x = v1->m_pVehAudComponent->m_WorldMatrix.v3.x;
      v1->m_lastPosOnStairs.y = v2;
      v1->m_lastPosOnStairs.z = v3;
    }
    v4 = v1->m_pVehAudComponent;
    v1->m_onStairs = 1;
    v5 = (__m128)LODWORD(v1->m_lastPosOnStairs.x);
    v6 = v4->m_pSubTypeParameters->mpPropertySet;
    v5.m128_f32[0] = (float)((float)((float)(v5.m128_f32[0] - v4->m_WorldMatrix.v3.x)
                                   * (float)(v5.m128_f32[0] - v4->m_WorldMatrix.v3.x))
                           + (float)((float)(v1->m_lastPosOnStairs.y - v4->m_WorldMatrix.v3.y)
                                   * (float)(v1->m_lastPosOnStairs.y - v4->m_WorldMatrix.v3.y)))
                   + (float)((float)(v1->m_lastPosOnStairs.z - v4->m_WorldMatrix.v3.z)
                           * (float)(v1->m_lastPosOnStairs.z - v4->m_WorldMatrix.v3.z));
    LODWORD(v7) = (unsigned __int128)_mm_sqrt_ps(v5);
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v6->mSchemaName.mUID) )
      v8 = UFG::qPropertySet::GetMemImagePtr(v6);
    else
      v8 = 0i64;
    if ( v7 > *((float *)v8 + 43) )
    {
      v9 = v4->m_WorldMatrix.v3.y;
      v10 = v4->m_WorldMatrix.v3.z;
      v1->m_lastPosOnStairs.x = v4->m_WorldMatrix.v3.x;
      v1->m_lastPosOnStairs.y = v9;
      v1->m_lastPosOnStairs.z = v10;
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr,
        0xCCBE7650,
        0i64,
        0,
        0i64);
    }
  }
  else
  {
    v1->m_onStairs = 0;
  }
}

// File Line: 166
// RVA: 0x69B9D0
char __fastcall UFG::EnvironmentalModel::WheelsOnStairs(UFG::EnvironmentalModel *this)
{
  UFG::EnvironmentalModel *v1; // rbx
  UFG::SimComponent *v2; // rdi
  int v3; // ebx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::PhysicsWheeledVehicle *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::PhysicsWheeledVehicle *v7; // rcx
  unsigned __int64 v8; // rbp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::PhysicsWheeledVehicle *v10; // rcx
  unsigned __int64 v11; // rsi
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v12; // rcx
  const char *v13; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v14; // rcx
  const char *v15; // rax
  UFG::qReflectHandleBase v17; // [rsp+28h] [rbp-60h]
  UFG::qReflectHandleBase v18; // [rsp+50h] [rbp-38h]

  v1 = this;
  if ( !(_S15_6 & 1) )
  {
    _S15_6 |= 1u;
    stairsUid = UFG::TiDo::CalcWwiseUid("STAIRS");
  }
  v2 = v1->m_pVehAudComponent->m_physicsMoverInterface.m_pPointer;
  v3 = 0;
  if ( SLODWORD(v2[12].m_BoundComponentHandles.mNode.mNext) <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = v2[10].m_SafePointerList.mNode.mPrev;
    if ( v4 )
    {
      v5 = 0i64;
      if ( BYTE4(v4[37].mNext) & 7 )
        v5 = (UFG::PhysicsWheeledVehicle *)v2[10].m_SafePointerList.mNode.mPrev;
      if ( v5 && !UFG::PhysicsWheeledVehicle::IsWheelOnGround(v5, v3) )
        goto LABEL_26;
    }
    v6 = v2[10].m_SafePointerList.mNode.mPrev;
    if ( !v6 )
      goto LABEL_33;
    v7 = 0i64;
    if ( BYTE4(v6[37].mNext) & 7 )
      v7 = (UFG::PhysicsWheeledVehicle *)v2[10].m_SafePointerList.mNode.mPrev;
    if ( v7 )
      v8 = UFG::PhysicsWheeledVehicle::GetSurfacePropertyHandleUidUnderWheel(v7, v3);
    else
LABEL_33:
      v8 = 0i64;
    v9 = v2[10].m_SafePointerList.mNode.mPrev;
    if ( !v9 )
      goto LABEL_34;
    v10 = 0i64;
    if ( BYTE4(v9[37].mNext) & 7 )
      v10 = (UFG::PhysicsWheeledVehicle *)v2[10].m_SafePointerList.mNode.mPrev;
    if ( v10 )
      v11 = UFG::PhysicsWheeledVehicle::GetObjectPropertyHandleUidUnderWheel(v10, v3);
    else
LABEL_34:
      v11 = 0i64;
    UFG::qReflectHandleBase::qReflectHandleBase(&v18);
    v13 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v12);
    v18.mTypeUID = UFG::qStringHash64(v13, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v18, v18.mTypeUID, v8);
    if ( v18.mData && BYTE4(v18.mData[1].mBaseNode.mParent) )
      goto LABEL_29;
    UFG::qReflectHandleBase::qReflectHandleBase(&v17);
    v15 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v14);
    v17.mTypeUID = UFG::qStringHash64(v15, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v17, v17.mTypeUID, v11);
    if ( v17.mData )
    {
      if ( *(_BYTE *)(v17.mData[4].mBaseNode.mUID + 100) )
        break;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v17);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v18);
LABEL_26:
    if ( ++v3 >= SLODWORD(v2[12].m_BoundComponentHandles.mNode.mNext) )
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
  UFG::EnvironmentalModel *v1; // rbx
  bool v2; // al
  UFG::SimComponent *v3; // rsi
  UFG::AudioEntity *v4; // rcx
  UFG::qPropertySet *v5; // rdi
  char *v6; // rax
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

  v1 = this;
  v2 = UFG::VehicleAudioComponent::WheelsInAir(this->m_pVehAudComponent);
  v3 = v1->m_pVehAudComponent->m_physicsMoverInterface.m_pPointer;
  v4 = (UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr;
  if ( v2 )
  {
    v1->m_hangTime = UFG::Metrics::msInstance.mSimTimeDelta + v1->m_hangTime;
    UFG::AudioEntity::SetRtpcValue(v4, 0xBC5D3BBu, 1.0);
    return;
  }
  UFG::AudioEntity::SetRtpcValue(v4, 0xBC5D3BBu, 0.0);
  v5 = v1->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v5->mSchemaName.mUID) )
    v6 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v6 = 0i64;
  if ( *((float *)v6 + 38) >= v1->m_hangTime
    || ((v7 = *((float *)&v3[10].m_BoundComponentHandles.mNode.mPrev + 1),
         v8 = v1->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet,
         !Vehicles_Audio_Base_BaseVehicleBase::IsClass(v8->mSchemaName.mUID)) ? (v9 = 0i64) : (v9 = UFG::qPropertySet::GetMemImagePtr(v8)),
        (float)(v7 * 3.5999999) <= *((float *)v9 + 40)) )
  {
    v12 = v1->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v12->mSchemaName.mUID) )
      v13 = UFG::qPropertySet::GetMemImagePtr(v12);
    else
      v13 = 0i64;
    if ( *((float *)v13 + 41) >= v1->m_hangTime )
      goto LABEL_27;
    v14 = *((float *)&v3[10].m_BoundComponentHandles.mNode.mPrev + 1);
    v15 = v1->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    v16 = Vehicles_Audio_Base_BaseVehicleBase::IsClass(v15->mSchemaName.mUID) ? UFG::qPropertySet::GetMemImagePtr(v15) : 0i64;
    if ( (float)(v14 * 3.5999999) <= *((float *)v16 + 40) )
      goto LABEL_27;
    v17 = v1->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v17->mSchemaName.mUID) )
      v18 = UFG::qPropertySet::GetMemImagePtr(v17);
    else
      v18 = 0i64;
    v11 = *((_DWORD *)v18 + 42);
  }
  else
  {
    v10 = v1->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v10->mSchemaName.mUID) )
      v11 = *((_DWORD *)UFG::qPropertySet::GetMemImagePtr(v10) + 39);
    else
      v11 = MEMORY[0x9C];
  }
  UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v1->m_pVehAudComponent->vfptr, v11, 0i64, 0, 0i64);
LABEL_27:
  v1->m_hangTime = 0.0;
}

// File Line: 267
// RVA: 0x67CB80
void __fastcall UFG::EnvironmentalModel::HandleSkids(UFG::EnvironmentalModel *this, float deltaTime)
{
  float v2; // xmm12_4
  UFG::EnvironmentalModel *v3; // rsi
  UFG::SimComponent *v4; // rdi
  float v5; // xmm10_4
  float v6; // xmm7_4
  float v7; // xmm9_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rdx
  char *v9; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  int v11; // er8
  int v12; // er9
  signed __int64 v13; // rax
  float v14; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  float v16; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  float v18; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  unsigned int v20; // eax
  float v21; // xmm11_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  UFG::qPropertySet *v25; // rdi
  char *v26; // rax
  float v27; // xmm7_4
  UFG::qPropertySet *v28; // rdi
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm7_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm2_4

  v2 = deltaTime;
  v3 = this;
  v4 = this->m_pVehAudComponent->m_physicsMoverInterface.m_pPointer;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  v8 = v4[10].m_SafePointerList.mNode.mPrev;
  v9 = 0i64;
  if ( !v8 )
    goto LABEL_79;
  v10 = 0i64;
  if ( BYTE4(v8[37].mNext) & 7 )
    v10 = v4[10].m_SafePointerList.mNode.mPrev;
  if ( !v10 || (LODWORD(v10[68].mNext) >> 4) & 1 )
  {
LABEL_79:
    v11 = 0;
    v12 = (int)v4[12].m_BoundComponentHandles.mNode.mNext;
    if ( v12 > 0 )
    {
      v13 = 848i64;
      do
      {
        v14 = 0.0;
        if ( v8 )
        {
          v15 = 0i64;
          if ( BYTE4(v8[37].mNext) & 7 )
            v15 = v4[10].m_SafePointerList.mNode.mPrev;
          if ( v15 )
            v14 = *(float *)((char *)&v15[-2].mPrev + v13);
        }
        if ( v14 > v5 )
          v5 = v14;
        v16 = 0.0;
        if ( v8 )
        {
          v17 = 0i64;
          if ( BYTE4(v8[37].mNext) & 7 )
            v17 = v4[10].m_SafePointerList.mNode.mPrev;
          if ( v17 )
            v16 = *(float *)((char *)&v17->mPrev + v13);
        }
        if ( v16 > v6 )
          v6 = v16;
        v18 = 0.0;
        if ( v8 )
        {
          v19 = 0i64;
          if ( BYTE4(v8[37].mNext) & 7 )
            v19 = v4[10].m_SafePointerList.mNode.mPrev;
          if ( v19 )
            v18 = *(float *)((char *)&v19[-1].mPrev + v13);
        }
        if ( v18 > v7 )
          v7 = v18;
        ++v11;
        v13 += 4i64;
      }
      while ( v11 < v12 );
    }
  }
  v20 = _S16_6;
  if ( !(_S16_6 & 1) )
  {
    _S16_6 |= 1u;
    skid_angle_rtpc = UFG::TiDo::CalcWwiseUid("skid_angle_player");
    v20 = _S16_6;
  }
  if ( !(v20 & 2) )
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
  if ( !(v20 & 4) )
  {
    _S16_6 = v20 | 4;
    burnout_amount_rtpc = UFG::TiDo::CalcWwiseUid("burnout_amount");
  }
  if ( (_QWORD)v4[1].m_pSimObject & 0x20 && LODWORD(v4[12].m_BoundComponentHandles.mNode.mNext) )
    v3->m_burnoutAmount.m_targetValue = 1.0;
  else
    v3->m_burnoutAmount.m_targetValue = 0.0;
  v23 = v3->m_burnoutAmount.m_targetValue;
  if ( v23 <= v3->m_burnoutAmount.m_min )
    v23 = v3->m_burnoutAmount.m_min;
  if ( v23 >= v3->m_burnoutAmount.m_max )
    v23 = v3->m_burnoutAmount.m_max;
  if ( v3->m_burnoutAmount.m_targetValue < v3->m_burnoutAmount.m_currentValue )
    v24 = v3->m_burnoutAmount.m_fallRate;
  else
    v24 = v3->m_burnoutAmount.m_riseRate;
  UFG::qApproach(&v3->m_burnoutAmount.m_currentValue, v23, v24, v2);
  UFG::AudioEntity::SetRtpcValue(
    (UFG::AudioEntity *)&v3->m_pVehAudComponent->vfptr,
    burnout_amount_rtpc,
    v3->m_burnoutAmount.m_currentValue);
  v25 = v3->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
  if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v25->mSchemaName.mUID) )
    v26 = UFG::qPropertySet::GetMemImagePtr(v25);
  else
    v26 = 0i64;
  v27 = *((float *)v26 + 53);
  v28 = v3->m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
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
  v3->m_skidAngle.m_targetValue = v21;
  v3->m_skidStrength.m_targetValue = (float)(1.0 / (float)(1.0 - v30)) * v31;
  v32 = v21;
  if ( v21 <= v3->m_skidAngle.m_min )
    v32 = v3->m_skidAngle.m_min;
  if ( v32 >= v3->m_skidAngle.m_max )
    v32 = v3->m_skidAngle.m_max;
  if ( v21 < v3->m_skidAngle.m_currentValue )
    v33 = v3->m_skidAngle.m_fallRate;
  else
    v33 = v3->m_skidAngle.m_riseRate;
  UFG::qApproach(&v3->m_skidAngle.m_currentValue, v32, v33, v2);
  v34 = v3->m_skidStrength.m_targetValue;
  if ( v34 <= v3->m_skidStrength.m_min )
    v34 = v3->m_skidStrength.m_min;
  if ( v34 >= v3->m_skidStrength.m_max )
    v34 = v3->m_skidStrength.m_max;
  if ( v3->m_skidStrength.m_targetValue < v3->m_skidStrength.m_currentValue )
    v35 = v3->m_skidStrength.m_fallRate;
  else
    v35 = v3->m_skidStrength.m_riseRate;
  UFG::qApproach(&v3->m_skidStrength.m_currentValue, v34, v35, v2);
  UFG::AudioEntity::SetRtpcValue(
    (UFG::AudioEntity *)&v3->m_pVehAudComponent->vfptr,
    skid_angle_rtpc,
    v3->m_skidAngle.m_currentValue);
  UFG::AudioEntity::SetRtpcValue(
    (UFG::AudioEntity *)&v3->m_pVehAudComponent->vfptr,
    skid_strength_rtpc,
    v3->m_skidStrength.m_currentValue);
}

