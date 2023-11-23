// File Line: 33
// RVA: 0xFB500
void __fastcall UFG::NavModuleLocalFlowField::NavModuleLocalFlowField(
        UFG::NavModuleLocalFlowField *this,
        UFG::NavComponent *parent)
{
  UFG::SimObject *m_pSimObject; // rbp
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v7; // rax
  UFG::SimComponent *v8; // rax
  UFG::qMemoryPool *v9; // rax
  char *v10; // rax
  __int64 v11; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimComponent *v13; // rsi
  UFG::qMemoryPool *v14; // rax
  char *v15; // rax
  UFG::AIInterestComponent *v16; // rax
  UFG::AIInterestComponent *v17; // rsi
  UFG::SimObject *v18; // rcx
  float AvoidanceRadius; // xmm0_4
  UFG::SimObjectModifier v20; // [rsp+38h] [rbp-50h] BYREF

  UFG::NavModuleLocal::NavModuleLocal(this, parent);
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalFlowField::`vftable;
  UFG::HermiteCurve::HermiteCurve(&this->mPathCurve, 500, 0i64, 0i64);
  UFG::FFieldPathPrint::FFieldPathPrint(&this->mPathPrint, &this->mPathCurve, 0, 0.0);
  UFG::FlowfieldTaskParam::FlowfieldTaskParam(&this->mTaskParams);
  UFG::FlowfieldMass::FlowfieldMass(&this->mTaskResult.FlowMass, 0i64, 0i64, 0i64);
  if ( this->mTaskResult.FlowMass.mActive )
    this->mTaskResult.FlowMass.mActive = 0;
  this->mPathHasChanged = 1;
  m_pSimObject = parent->m_pSimObject;
  m_pTransformNodeComponent = 0i64;
  if ( !UFG::IsAnyLocalPlayer(m_pSimObject) )
  {
    UFG::SimObjectModifier::SimObjectModifier(&v20, m_pSimObject, 1);
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v7 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC0ui64, "Flow_AvoidanceController", 0i64, 1u);
    if ( v7 )
      UFG::AvoidanceController::AvoidanceController((UFG::AvoidanceController *)v7, 0);
    else
      v8 = 0i64;
    UFG::SimObjectModifier::AttachComponent(&v20, v8, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v20);
    UFG::SimObjectModifier::~SimObjectModifier(&v20);
    v9 = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(v9, 0xC8ui64, "FlowfieldComponent", 0i64, 1u);
    if ( v10 )
    {
      UFG::FlowfieldComponent::FlowfieldComponent((UFG::FlowfieldComponent *)v10, 0);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    this->mPathPrint.m_iPriority = 5;
    LOBYTE(v11) = 1;
    ((void (__fastcall *)(UFG::SimComponent *, UFG::FFieldPathPrint *, __int64))v13->vfptr[19].__vecDelDtor)(
      v13,
      &this->mPathPrint,
      v11);
    UFG::SimObjectModifier::SimObjectModifier(&v20, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v20, v13, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v20);
    UFG::SimObjectModifier::~SimObjectModifier(&v20);
  }
  v14 = UFG::GetSimulationMemoryPool();
  v15 = UFG::qMemoryPool::Allocate(v14, 0x1B0ui64, "Flow_AIInterestComponent", 0i64, 1u);
  if ( v15 )
  {
    UFG::AIInterestComponent::AIInterestComponent((UFG::AIInterestComponent *)v15, 0);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = this->m_navComponent->m_pSimObject;
  if ( v18 )
    m_pTransformNodeComponent = v18->m_pTransformNodeComponent;
  AvoidanceRadius = UFG::NavComponent::GetAvoidanceRadius(parent);
  UFG::AIInterestComponent::Init(
    v17,
    m_pTransformNodeComponent,
    &UFG::qVector3::msZero,
    AvoidanceRadius * 1.5,
    "AvoidableParams");
  v17->mFlags |= 4u;
  UFG::SimObjectModifier::SimObjectModifier(&v20, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v20, v17, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v20);
  UFG::SimObjectModifier::~SimObjectModifier(&v20);
}

// File Line: 54
// RVA: 0xFC000
void __fastcall UFG::NavModuleLocalFlowField::~NavModuleLocalFlowField(UFG::NavModuleLocalFlowField *this)
{
  UFG::SimComponent *v2; // rbx
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::SimObjectGame *v6; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v8; // dx
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  UFG::FlowfieldTaskResult *p_mTaskResult; // rdx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *mPrev; // rcx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *mNext; // rax
  UFG::FlowfieldTaskParam *p_mTaskParams; // rdx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *v16; // rcx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *v17; // rax

  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalFlowField::`vftable;
  v2 = 0i64;
  if ( UFG::NavModuleLocalFlowField::mpTaskGroup )
  {
    UFG::qTaskManager::Sync(&UFG::gTaskManager, UFG::NavModuleLocalFlowField::mpTaskGroup);
    UFG::NavModuleLocalFlowField::mpTaskGroup = 0i64;
  }
  m_pSimObject = (UFG::SimObjectGame *)this->m_navComponent->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::AIInterestComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AIInterestComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfTypeHK);
  v6 = (UFG::SimObjectGame *)this->m_navComponent->m_pSimObject;
  if ( v6 )
  {
    v8 = v6->m_Flags;
    if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::AvoidanceController::_TypeUID);
    else
      ComponentOfType = UFG::SimObject::GetComponentOfType(v6, UFG::AvoidanceController::_TypeUID);
  }
  else
  {
    ComponentOfType = 0i64;
  }
  UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
  v9 = (UFG::SimObjectGame *)this->m_navComponent->m_pSimObject;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 || v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::FlowfieldComponent::_TypeUID);
    else
      v11 = UFG::SimObject::GetComponentOfType(v9, UFG::FlowfieldComponent::_TypeUID);
    v2 = v11;
  }
  UFG::Simulation::DestroySimComponent(&UFG::gSim, v2);
  p_mTaskResult = &this->mTaskResult;
  if ( this->mTaskResult.FlowMass.mActive )
    this->mTaskResult.FlowMass.mActive = 0;
  mPrev = p_mTaskResult->FlowMass.mPrev;
  mNext = this->mTaskResult.FlowMass.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mTaskResult->FlowMass.mPrev = &p_mTaskResult->FlowMass;
  this->mTaskResult.FlowMass.mNext = &this->mTaskResult.FlowMass;
  p_mTaskParams = &this->mTaskParams;
  if ( this->mTaskParams.FlowMass.mActive )
    this->mTaskParams.FlowMass.mActive = 0;
  v16 = p_mTaskParams->FlowMass.mPrev;
  v17 = this->mTaskParams.FlowMass.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  p_mTaskParams->FlowMass.mPrev = &p_mTaskParams->FlowMass;
  this->mTaskParams.FlowMass.mNext = &this->mTaskParams.FlowMass;
  UFG::FlowfieldPrint::~FlowfieldPrint(&this->mPathPrint);
  UFG::HermiteCurve::~HermiteCurve(&this->mPathCurve);
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocal::`vftable;
  _((AMD_HD3D *)&this->m_adjustedWaypoint);
}

// File Line: 63
// RVA: 0x102450
// attributes: thunk
void __fastcall UFG::NavModuleLocalFlowField::Reset(UFG::NavModuleLocalFlowField *this)
{
  UFG::NavModuleLocal::Reset(this);
}

// File Line: 68
// RVA: 0x101260
void __fastcall UFG::NavModuleLocalFlowField::OnPathChanged(UFG::NavModuleLocalFlowField *this)
{
  this->mPathHasChanged = 1;
}

// File Line: 73
// RVA: 0x102E30
void __fastcall UFG::UpdateTangents(UFG::HermiteCurve *curve, float fTension)
{
  int mNumControlPoints; // r14d
  int v5; // edi
  __int64 v6; // rbp
  float v7; // xmm8_4
  __int64 v8; // rbx
  float v9; // xmm9_4
  UFG::HermiteControlPoint *v10; // rax
  float v11; // xmm3_4
  __int128 y_low; // xmm4
  float v13; // xmm5_4
  UFG::HermiteControlPoint *mControlPoints; // rax
  float v15; // xmm3_4
  float v16; // xmm5_4
  __m128 v17; // xmm2
  float v18; // xmm1_4
  __m128 v19; // xmm2
  float v20; // xmm0_4
  float v21; // xmm0_4
  __m128 v22; // xmm2
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  UFG::qVector3 tangent; // [rsp+20h] [rbp-68h] BYREF

  mNumControlPoints = curve->mNumControlPoints;
  if ( curve->mNumControlPoints >= 2 )
  {
    v5 = 0;
    v6 = curve->mNumControlPoints;
    v7 = 0.0;
    v8 = 1i64;
    v9 = fTension + 1.0;
    do
    {
      if ( v5 )
      {
        mControlPoints = curve->mControlPoints;
        if ( v5 == mNumControlPoints - 1 )
        {
          y_low = LODWORD(mControlPoints[v8 - 1].mPosition.y);
          v11 = (float)(mControlPoints[v8 - 1].mPosition.x - mControlPoints[v8 - 2].mPosition.x) * fTension;
          *(float *)&y_low = (float)(*(float *)&y_low - *((float *)&mControlPoints[v8 - 1] - 5)) * fTension;
          v13 = (float)(mControlPoints[v8 - 1].mPosition.z - *((float *)&mControlPoints[v8 - 1] - 4)) * fTension;
        }
        else
        {
          y_low = LODWORD(mControlPoints[v8].mPosition.y);
          v15 = mControlPoints[v8].mPosition.x - mControlPoints[v8 - 2].mPosition.x;
          *(float *)&y_low = *(float *)&y_low - *((float *)&mControlPoints[v8 - 1] - 5);
          v16 = mControlPoints[v8].mPosition.z - *((float *)&mControlPoints[v8 - 1] - 4);
          v17 = (__m128)y_low;
          v17.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v15 * v15))
                          + (float)(v16 * v16);
          if ( v17.m128_f32[0] == 0.0 )
            v18 = 0.0;
          else
            v18 = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
          tangent.x = v15 * v18;
          tangent.y = *(float *)&y_low * v18;
          tangent.z = v16 * v18;
          v19 = (__m128)LODWORD(mControlPoints[v8 - 1].mPosition.y);
          v20 = mControlPoints[v8 - 1].mPosition.z - mControlPoints[v8].mPosition.z;
          v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - mControlPoints[v8].mPosition.y)
                                          * (float)(v19.m128_f32[0] - mControlPoints[v8].mPosition.y))
                                  + (float)((float)(mControlPoints[v8 - 1].mPosition.x - mControlPoints[v8].mPosition.x)
                                          * (float)(mControlPoints[v8 - 1].mPosition.x - mControlPoints[v8].mPosition.x)))
                          + (float)(v20 * v20);
          v21 = _mm_sqrt_ps(v19).m128_f32[0] * fTension;
          v11 = (float)(v15 * v18) * v21;
          *(float *)&y_low = (float)(*(float *)&y_low * v18) * v21;
          v13 = (float)(v16 * v18) * v21;
        }
      }
      else
      {
        v10 = curve->mControlPoints;
        y_low = LODWORD(v10[v8].mPosition.y);
        v11 = (float)(v10[v8].mPosition.x - v10[v8 - 1].mPosition.x) * fTension;
        *(float *)&y_low = (float)(*(float *)&y_low - v10[v8 - 1].mPosition.y) * fTension;
        v13 = (float)(v10[v8].mPosition.z - v10[v8 - 1].mPosition.z) * fTension;
      }
      v22 = (__m128)y_low;
      tangent.x = v11;
      LODWORD(tangent.y) = y_low;
      tangent.z = v13;
      v23 = v9 * v7;
      v22.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v11 * v11)) + (float)(v13 * v13);
      LODWORD(v24) = _mm_sqrt_ps(v22).m128_u32[0];
      v25 = v24;
      if ( v7 > 0.0 && v24 > v23 )
      {
        v25 = v9 * v7;
        v26 = v23 / v24;
        tangent.x = v11 * v26;
        tangent.y = *(float *)&y_low * v26;
        tangent.z = v13 * v26;
      }
      v7 = v25;
      UFG::HermiteCurve::SetControlPointTangent(curve, v5++, &tangent);
      ++v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 113
// RVA: 0xFCD80
void __fastcall UFG::NavModuleLocalFlowField::CreateHermiteFromPath(
        UFG::NavModuleLocalFlowField *this,
        UFG::HermiteCurve *outCurve,
        UFG::NavPath *pPath)
{
  UFG::qVector4 *CurrentPosition; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float size; // xmm0_4
  __int64 v10; // rsi
  __int64 v11; // rdi
  UFG::NavWaypoint *v12; // rbx
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::qVector3 position; // [rsp+20h] [rbp-38h] BYREF
  UFG::qVector3 v16; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 tangent; // [rsp+40h] [rbp-18h] BYREF

  UFG::HermiteCurve::ClearControlPoints(outCurve, 0);
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  y = CurrentPosition->y;
  z = CurrentPosition->z;
  position.x = CurrentPosition->x;
  position.y = y;
  tangent = UFG::qVector3::msDirFront;
  position.z = z;
  UFG::HermiteCurve::AddControlPoint(outCurve, &position, &tangent);
  size = (float)(outCurve->mMaxNumControlPoints - 1);
  if ( size >= (float)(int)pPath->m_aWaypoints.size )
    size = (float)(int)pPath->m_aWaypoints.size;
  v10 = (int)size;
  if ( (int)size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &pPath->m_aWaypoints.p[v11];
      v16 = UFG::qVector3::msDirFront;
      UFG::HermiteCurve::AddControlPoint(outCurve, &v12->m_navPosition.m_vPosition, &v16);
      ++v11;
      v13 = v12->m_navPosition.m_vPosition.y;
      v14 = v12->m_navPosition.m_vPosition.z;
      position.x = v12->m_navPosition.m_vPosition.x;
      position.y = v13;
      tangent = v16;
      position.z = v14;
      --v10;
    }
    while ( v10 );
  }
  if ( outCurve->mNumControlPoints > 1 )
    UFG::UpdateTangents(outCurve, 0.40000001);
}

// File Line: 175
// RVA: 0x102CB0
void __fastcall UFG::NavModuleLocalFlowField::Update(UFG::NavModuleLocalFlowField *this, float dt)
{
  UFG::qVector4 *CurrentPosition; // rax
  float m_fAdjustedSpeed; // xmm8_4
  float v5; // xmm3_4
  __m128 y_low; // xmm4
  __m128 v7; // xmm1
  float v8; // xmm5_4
  float y; // xmm1_4
  __m128 v10; // xmm5
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float x; // [rsp+20h] [rbp-48h]
  float z; // [rsp+28h] [rbp-40h]

  CurrentPosition = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  y_low = (__m128)LODWORD(this->mTaskResult.FlowMass.mPosition.y);
  m_fAdjustedSpeed = this->m_fAdjustedSpeed;
  v5 = this->mTaskResult.FlowMass.mPosition.x - CurrentPosition->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - CurrentPosition->y;
  v7 = y_low;
  v7.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5);
  v8 = _mm_sqrt_ps(v7).m128_f32[0];
  if ( v8 <= 0.0 )
  {
    y = UFG::qVector3::msZero.y;
    x = UFG::qVector3::msZero.x;
    z = UFG::qVector3::msZero.z;
  }
  else
  {
    z = (float)((float)(1.0 / v8) * 0.0) * m_fAdjustedSpeed;
    y = (float)((float)(1.0 / v8) * y_low.m128_f32[0]) * m_fAdjustedSpeed;
    x = (float)((float)(1.0 / v8) * v5) * m_fAdjustedSpeed;
  }
  v10 = (__m128)LODWORD(y);
  v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(x * x)) + (float)(z * z);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = x * v11;
  v13 = y * v11;
  v14 = z * v11;
  if ( m_fAdjustedSpeed <= 0.0 )
  {
    this->m_steerData.m_fLocalSpeed = 0.0;
  }
  else
  {
    this->m_steerData.m_vDesiredDirection.x = v12;
    this->m_steerData.m_vDesiredDirection.y = v13;
    this->m_steerData.m_vDesiredDirection.z = v14;
    this->m_steerData.m_vClampedDirection.x = v12;
    this->m_steerData.m_vClampedDirection.y = v13;
    this->m_steerData.m_vClampedDirection.z = v14;
    this->m_steerData.m_vLocalDirection.x = v12;
    this->m_steerData.m_vLocalDirection.y = v13;
    this->m_steerData.m_vLocalDirection.z = v14;
    this->m_steerData.m_fLocalSpeed = this->m_fAdjustedSpeed;
  }
}

// File Line: 215
// RVA: 0x101E00
void __fastcall UFG::NavModuleLocalFlowField::QueueFlowTask(UFG::NavModuleLocalFlowField *this)
{
  char *v2; // rax
  UFG::qTaskGroup *v3; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroups; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *mPrev; // rax
  UFG::NavComponent *m_navComponent; // rcx
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::qVector4 *CurrentPosition; // rbp
  UFG::SimObjectGame *v10; // rcx
  UFG::SimComponent *v11; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // ecx
  __int64 i; // rax
  float x; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm6_4
  float v23; // xmm2_4
  __m128 y_low; // xmm5
  __m128 v25; // xmm1
  float v26; // xmm3_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm6_4
  UFG::FlowfieldTaskParam *p_mTaskParams; // rbx
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  UFG::qTaskGroup *v43; // rdi
  char *v44; // rax
  char *v45; // rdx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r8
  char *mAddress; // r9
  UFG::qNode<UFG::qTask,UFG::qTask> *v51; // rax

  if ( !UFG::IsAnyLocalPlayer(this->m_navComponent->m_pSimObject) )
  {
    if ( !UFG::NavModuleLocalFlowField::mpTaskGroup )
    {
      v2 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
      v3 = (UFG::qTaskGroup *)v2;
      if ( v2 )
        UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v2, "FlowfieldUpdate");
      mSingleFrameTaskGroups = UFG::gTaskManager.mSingleFrameTaskGroups;
      mPrev = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
      mPrev->mNext = v3;
      v3->mPrev = mPrev;
      v3->mNext = &mSingleFrameTaskGroups->mNode;
      mSingleFrameTaskGroups->mNode.mPrev = v3;
      UFG::NavModuleLocalFlowField::mpTaskGroup = v3;
    }
    if ( this->mPathHasChanged && UFG::NavModulePathing::HasPath(this->m_navComponent->m_pNavModulePathing) )
    {
      UFG::NavModuleLocalFlowField::CreateHermiteFromPath(
        this,
        &this->mPathCurve,
        this->m_navComponent->m_pNavModulePathing->m_pPath.m_pNavPath);
      this->mPathHasChanged = 0;
    }
    m_navComponent = this->m_navComponent;
    m_pSimObject = m_navComponent->m_pSimObject;
    if ( m_pSimObject )
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    CurrentPosition = UFG::NavComponent::GetCurrentPosition(m_navComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v10 = (UFG::SimObjectGame *)this->m_navComponent->m_pSimObject;
    if ( v10 )
    {
      m_Flags = v10->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::FlowfieldComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::FlowfieldComponent::_TypeUID);
      v11 = ComponentOfTypeHK;
    }
    else
    {
      v11 = 0i64;
    }
    ((void (__fastcall *)(UFG::SimComponent *))v11[1].vfptr[3].__vecDelDtor)(&v11[1]);
    y = CurrentPosition->y;
    z = CurrentPosition->z;
    *(float *)&v11[2].m_SafePointerList.mNode.mNext = CurrentPosition->x;
    *((float *)&v11[2].m_SafePointerList.mNode.mNext + 1) = y;
    *(float *)&v11[2].m_TypeUID = z;
    v16 = m_pTransformNodeComponent->mWorldVelocity.y;
    v17 = m_pTransformNodeComponent->mWorldVelocity.z;
    v11[2].m_NameUID = LODWORD(m_pTransformNodeComponent->mWorldVelocity.x);
    *(float *)&v11[2].m_Flags = v16;
    *(float *)(&v11[2].m_SimObjIndex + 1) = v17;
    this->mTaskParams.mpResults = &this->mTaskResult;
    this->mTaskParams.mpFlowfield = v11;
    v18 = 0;
    for ( i = (__int64)&v11[2].vfptr[-5];
          (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)i != &v11[1].m_SafePointerList.mNode.mNext;
          i = *(_QWORD *)(i + 48) - 40i64 )
    {
      ++v18;
    }
    this->mTaskParams.mNumFlowfieldPrints = v18;
    this->mTaskParams.FlowMassDistOffset = this->m_navComponent->m_navParams.m_fRadius * 1.5;
    x = CurrentPosition->x;
    v21 = CurrentPosition->y;
    v22 = CurrentPosition->z;
    v23 = m_pTransformNodeComponent->mWorldVelocity.x;
    y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldVelocity.y);
    v25 = y_low;
    v25.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v23 * v23);
    v26 = _mm_sqrt_ps(v25).m128_f32[0];
    if ( v26 >= 0.001 )
    {
      v30 = 1.0 / v26;
      v27 = (float)(1.0 / v26) * v23;
      v28 = v30 * y_low.m128_f32[0];
      v29 = v30 * 0.0;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v27 = m_pTransformNodeComponent->mWorldTransform.v0.x;
      v28 = m_pTransformNodeComponent->mWorldTransform.v0.y;
      v29 = m_pTransformNodeComponent->mWorldTransform.v0.z;
    }
    v31 = v22 + v29;
    p_mTaskParams = &this->mTaskParams;
    p_mTaskParams->FlowMass.mpFlow = (UFG::FlowfieldComponent *)v11;
    v33 = UFG::qVector3::msZero.y;
    v34 = UFG::qVector3::msZero.z;
    p_mTaskParams->FlowMass.mStartVelocity.x = UFG::qVector3::msZero.x;
    p_mTaskParams->FlowMass.mStartVelocity.y = v33;
    p_mTaskParams->FlowMass.mStartVelocity.z = v34;
    p_mTaskParams->FlowMass.mStartPosition.x = v27 + x;
    p_mTaskParams->FlowMass.mStartPosition.y = v28 + v21;
    p_mTaskParams->FlowMass.mStartPosition.z = v31;
    *(_QWORD *)&p_mTaskParams->FlowMass.mFlowStrength = 0i64;
    v35 = p_mTaskParams->FlowMass.mStartPosition.y;
    v36 = p_mTaskParams->FlowMass.mStartPosition.z;
    p_mTaskParams->FlowMass.mPosition.x = p_mTaskParams->FlowMass.mStartPosition.x;
    p_mTaskParams->FlowMass.mPosition.y = v35;
    p_mTaskParams->FlowMass.mPosition.z = v36;
    v37 = p_mTaskParams->FlowMass.mStartVelocity.y;
    v38 = p_mTaskParams->FlowMass.mStartVelocity.z;
    p_mTaskParams->FlowMass.mVelocity.x = p_mTaskParams->FlowMass.mStartVelocity.x;
    p_mTaskParams->FlowMass.mVelocity.y = v37;
    p_mTaskParams->FlowMass.mVelocity.z = v38;
    v39 = UFG::qVector3::msZero.y;
    v40 = UFG::qVector3::msZero.z;
    p_mTaskParams->FlowMass.mNegVelDir.x = UFG::qVector3::msZero.x;
    p_mTaskParams->FlowMass.mNegVelDir.y = v39;
    p_mTaskParams->FlowMass.mNegVelDir.z = v40;
    v41 = UFG::qVector3::msDirUp.y;
    v42 = UFG::qVector3::msDirUp.z;
    p_mTaskParams->FlowMass.mNegVelDir.x = UFG::qVector3::msDirUp.x;
    p_mTaskParams->FlowMass.mNegVelDir.y = v41;
    p_mTaskParams->FlowMass.mNegVelDir.z = v42;
    if ( !p_mTaskParams->FlowMass.mActive )
    {
      p_mTaskParams->FlowMass.mAge = 0.0;
      p_mTaskParams->FlowMass.mActive = p_mTaskParams->FlowMass.mThisRef->mpFlow != 0i64;
    }
    v43 = UFG::NavModuleLocalFlowField::mpTaskGroup;
    v44 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v45 = v44;
    if ( v44 )
    {
      *(_QWORD *)v44 = v44;
      *((_QWORD *)v44 + 1) = v44;
      *((_QWORD *)v44 + 2) = v44 + 16;
      *((_QWORD *)v44 + 3) = v44 + 16;
      mSpuElf = UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mSpuElf;
      mTaskFunctionSPU = UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mTaskFunctionSPU;
      mTaskFunctionPPU = UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mTaskFunctionPPU;
      mTaskFunctionOffload = UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mTaskFunctionOffload;
      if ( !UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mCurrentSPUEnabled )
      {
        mSpuElf = 0i64;
        mTaskFunctionSPU = 0i64;
        mTaskFunctionOffload = 0i64;
      }
      *((_QWORD *)v45 + 6) = v43;
      *((_DWORD *)v45 + 14) = 2;
      *((_QWORD *)v45 + 4) = 0i64;
      *((_QWORD *)v45 + 5) = 0i64;
      *((_QWORD *)v45 + 8) = &UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat;
      if ( mSpuElf )
        mAddress = mSpuElf->mAddress;
      else
        mAddress = 0i64;
      *((_QWORD *)v45 + 9) = mAddress;
      *((_QWORD *)v45 + 10) = mTaskFunctionSPU;
      *((_QWORD *)v45 + 11) = mTaskFunctionPPU;
      *((_QWORD *)v45 + 12) = p_mTaskParams;
      *((_QWORD *)v45 + 13) = 0i64;
      *((_QWORD *)v45 + 14) = 0i64;
      *((_QWORD *)v45 + 15) = 0i64;
      if ( mTaskFunctionOffload )
      {
        *((_DWORD *)v45 + 14) = 130;
        *((_DWORD *)v45 + 12) = 0;
      }
    }
    v51 = v43->mTasks.mNode.mPrev;
    v51->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v45;
    *(_QWORD *)v45 = v51;
    *((_QWORD *)v45 + 1) = &v43->mTasks;
    v43->mTasks.mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v45;
    ++v43->mNumTasks;
  }
}

