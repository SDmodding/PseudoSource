// File Line: 33
// RVA: 0xFB500
void __fastcall UFG::NavModuleLocalFlowField::NavModuleLocalFlowField(UFG::NavModuleLocalFlowField *this, UFG::NavComponent *parent)
{
  UFG::NavComponent *v2; // r14
  UFG::NavModuleLocalFlowField *v3; // rdi
  UFG::SimObject *v4; // rbp
  UFG::TransformNodeComponent *v5; // rbx
  UFG::qMemoryPool *v6; // rax
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
  float v19; // xmm0_4
  UFG::SimObjectModifier v20; // [rsp+38h] [rbp-50h]

  v2 = parent;
  v3 = this;
  UFG::NavModuleLocal::NavModuleLocal((UFG::NavModuleLocal *)&this->vfptr, parent);
  v3->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalFlowField::`vftable;
  UFG::HermiteCurve::HermiteCurve(&v3->mPathCurve, 500, 0i64, 0i64);
  UFG::FFieldPathPrint::FFieldPathPrint(&v3->mPathPrint, &v3->mPathCurve, 0, 0.0);
  UFG::FlowfieldTaskParam::FlowfieldTaskParam(&v3->mTaskParams);
  UFG::FlowfieldMass::FlowfieldMass(&v3->mTaskResult.FlowMass, 0i64, 0i64, 0i64);
  if ( v3->mTaskResult.FlowMass.mActive )
    v3->mTaskResult.FlowMass.mActive = 0;
  v3->mPathHasChanged = 1;
  v4 = v2->m_pSimObject;
  v5 = 0i64;
  if ( !UFG::IsAnyLocalPlayer(v2->m_pSimObject) )
  {
    UFG::SimObjectModifier::SimObjectModifier(&v20, v4, 1);
    v6 = UFG::GetSimulationMemoryPool();
    v7 = UFG::qMemoryPool::Allocate(v6, 0xC0ui64, "Flow_AvoidanceController", 0i64, 1u);
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
    v3->mPathPrint.m_iPriority = 5;
    LOBYTE(v11) = 1;
    ((void (__fastcall *)(UFG::SimComponent *, UFG::FFieldPathPrint *, __int64))v13->vfptr[19].__vecDelDtor)(
      v13,
      &v3->mPathPrint,
      v11);
    UFG::SimObjectModifier::SimObjectModifier(&v20, v4, 1);
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
  v18 = v3->m_navComponent->m_pSimObject;
  if ( v18 )
    v5 = v18->m_pTransformNodeComponent;
  v19 = UFG::NavComponent::GetAvoidanceRadius(v2);
  UFG::AIInterestComponent::Init(v17, v5, &UFG::qVector3::msZero, v19 * 1.5, "AvoidableParams");
  v17->mFlags |= 4u;
  UFG::SimObjectModifier::SimObjectModifier(&v20, v4, 1);
  UFG::SimObjectModifier::AttachComponent(&v20, (UFG::SimComponent *)&v17->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v20);
  UFG::SimObjectModifier::~SimObjectModifier(&v20);
}

// File Line: 54
// RVA: 0xFC000
void __fastcall UFG::NavModuleLocalFlowField::~NavModuleLocalFlowField(UFG::NavModuleLocalFlowField *this)
{
  UFG::NavModuleLocalFlowField *v1; // rdi
  UFG::SimComponent *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // dx
  UFG::SimObjectGame *v6; // rcx
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // dx
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  UFG::FlowfieldTaskResult *v12; // rdx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *v13; // rcx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *v14; // rax
  UFG::FlowfieldTaskParam *v15; // rdx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *v16; // rcx
  UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *v17; // rax

  v1 = this;
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalFlowField::`vftable;
  v2 = 0i64;
  if ( UFG::NavModuleLocalFlowField::mpTaskGroup )
  {
    UFG::qTaskManager::Sync(&UFG::gTaskManager, UFG::NavModuleLocalFlowField::mpTaskGroup);
    UFG::NavModuleLocalFlowField::mpTaskGroup = 0i64;
  }
  v3 = (UFG::SimObjectGame *)v1->m_navComponent->m_pSimObject;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIInterestComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIInterestComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIInterestComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIInterestComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIInterestComponent::_TypeUID);
    }
  }
  else
  {
    v4 = 0i64;
  }
  UFG::Simulation::DestroySimComponent(&UFG::gSim, v4);
  v6 = (UFG::SimObjectGame *)v1->m_navComponent->m_pSimObject;
  if ( v6 )
  {
    v8 = v6->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::AvoidanceController::_TypeUID);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::AvoidanceController::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::AvoidanceController::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AvoidanceController::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::AvoidanceController::_TypeUID);
    }
  }
  else
  {
    v7 = 0i64;
  }
  UFG::Simulation::DestroySimComponent(&UFG::gSim, v7);
  v9 = (UFG::SimObjectGame *)v1->m_navComponent->m_pSimObject;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::FlowfieldComponent::_TypeUID);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::FlowfieldComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::FlowfieldComponent::_TypeUID);
      }
      else
      {
        v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::FlowfieldComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::FlowfieldComponent::_TypeUID);
    }
    v2 = v11;
  }
  UFG::Simulation::DestroySimComponent(&UFG::gSim, v2);
  v12 = &v1->mTaskResult;
  if ( v1->mTaskResult.FlowMass.mActive )
    v1->mTaskResult.FlowMass.mActive = 0;
  v13 = v12->FlowMass.mPrev;
  v14 = v1->mTaskResult.FlowMass.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->FlowMass.mPrev = (UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *)&v12->FlowMass.mPrev;
  v1->mTaskResult.FlowMass.mNext = (UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *)&v1->mTaskResult.FlowMass.mPrev;
  v15 = &v1->mTaskParams;
  if ( v1->mTaskParams.FlowMass.mActive )
    v1->mTaskParams.FlowMass.mActive = 0;
  v16 = v15->FlowMass.mPrev;
  v17 = v1->mTaskParams.FlowMass.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v15->FlowMass.mPrev = (UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *)&v15->FlowMass.mPrev;
  v1->mTaskParams.FlowMass.mNext = (UFG::qNode<UFG::FlowfieldMass,UFG::FlowfieldMass> *)&v1->mTaskParams.FlowMass.mPrev;
  UFG::FlowfieldPrint::~FlowfieldPrint((UFG::FlowfieldPrint *)&v1->mPathPrint.vfptr);
  UFG::HermiteCurve::~HermiteCurve(&v1->mPathCurve);
  v1->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocal::`vftable;
  _((AMD_HD3D *)&v1->m_adjustedWaypoint);
}

// File Line: 63
// RVA: 0x102450
void __fastcall UFG::NavModuleLocalFlowField::Reset(UFG::NavModuleLocalFlowField *this)
{
  UFG::NavModuleLocal::Reset((UFG::NavModuleLocal *)&this->vfptr);
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
  int v2; // er14
  UFG::HermiteCurve *v3; // rsi
  float v4; // xmm6_4
  int v5; // edi
  __int64 v6; // rbp
  float v7; // xmm8_4
  signed __int64 v8; // rbx
  float v9; // xmm9_4
  UFG::HermiteControlPoint *v10; // rax
  float v11; // xmm3_4
  __int128 v12; // xmm4
  float v13; // xmm5_4
  UFG::HermiteControlPoint *v14; // rax
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
  UFG::qVector3 tangent; // [rsp+20h] [rbp-68h]

  v2 = curve->mNumControlPoints;
  v3 = curve;
  v4 = fTension;
  if ( curve->mNumControlPoints >= 2 )
  {
    v5 = 0;
    v6 = curve->mNumControlPoints;
    v7 = 0.0;
    if ( v2 > 0 )
    {
      v8 = 1i64;
      v9 = fTension + 1.0;
      do
      {
        if ( v5 )
        {
          v14 = v3->mControlPoints;
          if ( v5 == v2 - 1 )
          {
            v12 = *((unsigned int *)&v14[v8] - 5);
            v11 = (float)(v14[v8 - 1].mPosition.x - v14[v8 - 2].mPosition.x) * v4;
            *(float *)&v12 = (float)(*(float *)&v12 - *((float *)&v14[v8 - 1] - 5)) * v4;
            v13 = (float)(*((float *)&v14[v8] - 4) - *((float *)&v14[v8 - 1] - 4)) * v4;
          }
          else
          {
            v12 = LODWORD(v14[v8].mPosition.y);
            v15 = v14[v8].mPosition.x - v14[v8 - 2].mPosition.x;
            *(float *)&v12 = *(float *)&v12 - *((float *)&v14[v8 - 1] - 5);
            v16 = v14[v8].mPosition.z - *((float *)&v14[v8 - 1] - 4);
            v17 = (__m128)v12;
            v17.m128_f32[0] = (float)((float)(*(float *)&v12 * *(float *)&v12) + (float)(v15 * v15))
                            + (float)(v16 * v16);
            if ( v17.m128_f32[0] == 0.0 )
              v18 = 0.0;
            else
              v18 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
            tangent.x = v15 * v18;
            tangent.y = *(float *)&v12 * v18;
            tangent.z = v16 * v18;
            v19 = (__m128)*((unsigned int *)&v14[v8] - 5);
            v20 = *((float *)&v14[v8] - 4) - v14[v8].mPosition.z;
            v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - v14[v8].mPosition.y)
                                            * (float)(v19.m128_f32[0] - v14[v8].mPosition.y))
                                    + (float)((float)(v14[v8 - 1].mPosition.x - v14[v8].mPosition.x)
                                            * (float)(v14[v8 - 1].mPosition.x - v14[v8].mPosition.x)))
                            + (float)(v20 * v20);
            v21 = COERCE_FLOAT(_mm_sqrt_ps(v19)) * v4;
            v11 = (float)(v15 * v18) * v21;
            *(float *)&v12 = (float)(*(float *)&v12 * v18) * v21;
            v13 = (float)(v16 * v18) * v21;
          }
        }
        else
        {
          v10 = v3->mControlPoints;
          v12 = LODWORD(v10[v8].mPosition.y);
          v11 = (float)(v10[v8].mPosition.x - v10[v8 - 1].mPosition.x) * v4;
          *(float *)&v12 = (float)(*(float *)&v12 - *((float *)&v10[v8] - 5)) * v4;
          v13 = (float)(v10[v8].mPosition.z - *((float *)&v10[v8] - 4)) * v4;
        }
        v22 = (__m128)v12;
        tangent.x = v11;
        LODWORD(tangent.y) = v12;
        tangent.z = v13;
        v23 = v9 * v7;
        v22.m128_f32[0] = (float)((float)(*(float *)&v12 * *(float *)&v12) + (float)(v11 * v11)) + (float)(v13 * v13);
        LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v22);
        v25 = v24;
        if ( v7 > 0.0 && v24 > v23 )
        {
          v25 = v9 * v7;
          v26 = v23 / v24;
          tangent.x = v11 * v26;
          tangent.y = *(float *)&v12 * v26;
          tangent.z = v13 * v26;
        }
        v7 = v25;
        UFG::HermiteCurve::SetControlPointTangent(v3, v5++, &tangent);
        ++v8;
        --v6;
      }
      while ( v6 );
    }
  }
}ontrolPointTangent(v3, v5++, &tangent);
        ++v8;
        --v6;
      }
      while ( 

// File Line: 113
// RVA: 0xFCD80
void __fastcall UFG::NavModuleLocalFlowField::CreateHermiteFromPath(UFG::NavModuleLocalFlowField *this, UFG::HermiteCurve *outCurve, UFG::NavPath *pPath)
{
  UFG::HermiteCurve *v3; // rbp
  UFG::NavModuleLocalFlowField *v4; // rbx
  UFG::NavPath *v5; // r14
  UFG::qVector4 *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  __int64 v10; // rsi
  __int64 v11; // rdi
  UFG::NavWaypoint *v12; // rbx
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::qVector3 position; // [rsp+20h] [rbp-38h]
  UFG::qVector3 v16; // [rsp+30h] [rbp-28h]
  UFG::qVector3 tangent; // [rsp+40h] [rbp-18h]

  v3 = outCurve;
  v4 = this;
  v5 = pPath;
  UFG::HermiteCurve::ClearControlPoints(outCurve, 0);
  v6 = UFG::NavComponent::GetCurrentPosition(v4->m_navComponent);
  v7 = v6->y;
  v8 = v6->z;
  position.x = v6->x;
  position.y = v7;
  tangent = UFG::qVector3::msDirFront;
  position.z = v8;
  UFG::HermiteCurve::AddControlPoint(v3, &position, &tangent);
  v9 = (float)(v3->mMaxNumControlPoints - 1);
  if ( v9 >= (float)(signed int)v5->m_aWaypoints.size )
    v9 = (float)(signed int)v5->m_aWaypoints.size;
  v10 = (signed int)v9;
  if ( (signed int)v9 > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &v5->m_aWaypoints.p[v11];
      v16 = UFG::qVector3::msDirFront;
      UFG::HermiteCurve::AddControlPoint(v3, &v12->m_navPosition.m_vPosition, &v16);
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
  if ( v3->mNumControlPoints > 1 )
    UFG::UpdateTangents(v3, 0.40000001);
}

// File Line: 175
// RVA: 0x102CB0
void __fastcall UFG::NavModuleLocalFlowField::Update(UFG::NavModuleLocalFlowField *this, float dt)
{
  UFG::NavModuleLocalFlowField *v2; // rbx
  UFG::qVector4 *v3; // rax
  float v4; // xmm8_4
  float v5; // xmm3_4
  __m128 v6; // xmm4
  __m128 v7; // xmm1
  float v8; // xmm5_4
  float v9; // xmm1_4
  __m128 v10; // xmm3
  __m128 v11; // xmm5
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // [rsp+20h] [rbp-48h]
  float v17; // [rsp+24h] [rbp-44h]
  float v18; // [rsp+28h] [rbp-40h]

  v2 = this;
  v3 = UFG::NavComponent::GetCurrentPosition(this->m_navComponent);
  v6 = (__m128)LODWORD(v2->mTaskResult.FlowMass.mPosition.y);
  v4 = v2->m_fAdjustedSpeed;
  v5 = v2->mTaskResult.FlowMass.mPosition.x - v3->x;
  v6.m128_f32[0] = v6.m128_f32[0] - v3->y;
  v7 = v6;
  v7.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
  if ( v8 <= 0.0 )
  {
    v9 = UFG::qVector3::msZero.y;
    v16 = UFG::qVector3::msZero.x;
    v18 = UFG::qVector3::msZero.z;
  }
  else
  {
    v18 = (float)((float)(1.0 / v8) * 0.0) * v4;
    v9 = (float)((float)(1.0 / v8) * v6.m128_f32[0]) * v4;
    v16 = (float)((float)(1.0 / v8) * v5) * v4;
  }
  v17 = v9;
  v10 = (__m128)LODWORD(v9);
  v11 = v10;
  v11.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v13 = v16 * v12;
  v14 = v9 * v12;
  v15 = v18 * v12;
  if ( v4 <= 0.0 )
  {
    v2->m_steerData.m_fLocalSpeed = 0.0;
  }
  else
  {
    v2->m_steerData.m_vDesiredDirection.x = v13;
    v2->m_steerData.m_vDesiredDirection.y = v14;
    v2->m_steerData.m_vDesiredDirection.z = v15;
    v2->m_steerData.m_vClampedDirection.x = v13;
    v2->m_steerData.m_vClampedDirection.y = v14;
    v2->m_steerData.m_vClampedDirection.z = v15;
    v2->m_steerData.m_vLocalDirection.x = v13;
    v2->m_steerData.m_vLocalDirection.y = v14;
    v2->m_steerData.m_vLocalDirection.z = v15;
    v2->m_steerData.m_fLocalSpeed = v2->m_fAdjustedSpeed;
  }
}

// File Line: 215
// RVA: 0x101E00
void __fastcall UFG::NavModuleLocalFlowField::QueueFlowTask(UFG::NavModuleLocalFlowField *this)
{
  UFG::NavModuleLocalFlowField *v1; // rbx
  char *v2; // rax
  UFG::qTaskGroup *v3; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v4; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v5; // rax
  UFG::NavComponent *v6; // rcx
  UFG::SimObject *v7; // rsi
  UFG::TransformNodeComponent *v8; // rsi
  UFG::qVector4 *v9; // rbp
  UFG::SimObjectGame *v10; // rcx
  UFG::SimComponent *v11; // rdi
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // ecx
  signed __int64 i; // rax
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm6_4
  float v23; // xmm2_4
  __m128 v24; // xmm5
  __m128 v25; // xmm1
  float v26; // xmm3_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm6_4
  signed __int64 v32; // rbx
  float v33; // xmm1_4
  float v34; // xmm2_4
  int v35; // xmm1_4
  int v36; // xmm2_4
  int v37; // xmm1_4
  int v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  UFG::qTaskGroup *v43; // rdi
  char *v44; // rax
  char *v45; // rdx
  _QWORD *v46; // rcx
  UFG::qSpuElf *v47; // rax
  void (__fastcall *v48)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *v49)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v50)(void *, void *, void *, void *); // r8
  char *v51; // r9
  UFG::qNode<UFG::qTask,UFG::qTask> *v52; // rax

  v1 = this;
  if ( !UFG::IsAnyLocalPlayer(this->m_navComponent->m_pSimObject) )
  {
    if ( !UFG::NavModuleLocalFlowField::mpTaskGroup )
    {
      v2 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
      v3 = (UFG::qTaskGroup *)v2;
      if ( v2 )
        UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v2, "FlowfieldUpdate");
      v4 = UFG::gTaskManager.mSingleFrameTaskGroups;
      v5 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
      v5->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v3->mPrev;
      v3->mPrev = v5;
      v3->mNext = &v4->mNode;
      v4->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v3->mPrev;
      UFG::NavModuleLocalFlowField::mpTaskGroup = v3;
    }
    if ( v1->mPathHasChanged && UFG::NavModulePathing::HasPath(v1->m_navComponent->m_pNavModulePathing) )
    {
      UFG::NavModuleLocalFlowField::CreateHermiteFromPath(
        v1,
        &v1->mPathCurve,
        v1->m_navComponent->m_pNavModulePathing->m_pPath.m_pNavPath);
      v1->mPathHasChanged = 0;
    }
    v6 = v1->m_navComponent;
    v7 = v6->m_pSimObject;
    if ( v7 )
      v8 = v7->m_pTransformNodeComponent;
    else
      v8 = 0i64;
    v9 = UFG::NavComponent::GetCurrentPosition(v6);
    UFG::TransformNodeComponent::UpdateWorldTransform(v8);
    v10 = (UFG::SimObjectGame *)v1->m_navComponent->m_pSimObject;
    if ( v10 )
    {
      v12 = v10->m_Flags;
      if ( (v12 >> 14) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::FlowfieldComponent::_TypeUID);
      }
      else if ( (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::FlowfieldComponent::_TypeUID);
        }
        else if ( (v12 >> 12) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::FlowfieldComponent::_TypeUID);
        }
        else
        {
          v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::FlowfieldComponent::_TypeUID);
        }
      }
      else
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::FlowfieldComponent::_TypeUID);
      }
      v11 = v13;
    }
    else
    {
      v11 = 0i64;
    }
    ((void (__cdecl *)(UFG::SimComponent *))v11[1].vfptr[3].__vecDelDtor)(&v11[1]);
    v14 = v9->y;
    v15 = v9->z;
    *(float *)&v11[2].m_SafePointerList.mNode.mNext = v9->x;
    *((float *)&v11[2].m_SafePointerList.mNode.mNext + 1) = v14;
    *(float *)&v11[2].m_TypeUID = v15;
    v16 = v8->mWorldVelocity.y;
    v17 = v8->mWorldVelocity.z;
    v11[2].m_NameUID = LODWORD(v8->mWorldVelocity.x);
    *(float *)&v11[2].m_Flags = v16;
    *(float *)(&v11[2].m_SimObjIndex + 1) = v17;
    v1->mTaskParams.mpResults = &v1->mTaskResult;
    v1->mTaskParams.mpFlowfield = v11;
    v18 = 0;
    for ( i = (signed __int64)&v11[2].vfptr[-5];
          (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)i != &v11[1].m_SafePointerList.mNode.mNext;
          i = *(_QWORD *)(i + 48) - 40i64 )
    {
      ++v18;
    }
    v1->mTaskParams.mNumFlowfieldPrints = v18;
    v1->mTaskParams.FlowMassDistOffset = v1->m_navComponent->m_navParams.m_fRadius * 1.5;
    v20 = v9->x;
    v21 = v9->y;
    v22 = v9->z;
    v23 = v8->mWorldVelocity.x;
    v24 = (__m128)LODWORD(v8->mWorldVelocity.y);
    v25 = v24;
    v25.m128_f32[0] = (float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23);
    LODWORD(v26) = (unsigned __int128)_mm_sqrt_ps(v25);
    if ( v26 >= 0.001 )
    {
      v30 = 1.0 / v26;
      v27 = (float)(1.0 / v26) * v23;
      v28 = v30 * v24.m128_f32[0];
      v29 = v30 * 0.0;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v8);
      v27 = v8->mWorldTransform.v0.x;
      v28 = v8->mWorldTransform.v0.y;
      v29 = v8->mWorldTransform.v0.z;
    }
    v31 = v22 + v29;
    v32 = (signed __int64)&v1->mTaskParams;
    *(_QWORD *)(v32 + 32) = v11;
    v33 = UFG::qVector3::msZero.y;
    v34 = UFG::qVector3::msZero.z;
    *(float *)(v32 + 60) = UFG::qVector3::msZero.x;
    *(float *)(v32 + 64) = v33;
    *(float *)(v32 + 68) = v34;
    *(float *)(v32 + 48) = v27 + v20;
    *(float *)(v32 + 52) = v28 + v21;
    *(float *)(v32 + 56) = v31;
    *(_QWORD *)(v32 + 84) = 0i64;
    v35 = *(_DWORD *)(v32 + 52);
    v36 = *(_DWORD *)(v32 + 56);
    *(_DWORD *)(v32 + 92) = *(_DWORD *)(v32 + 48);
    *(_DWORD *)(v32 + 96) = v35;
    *(_DWORD *)(v32 + 100) = v36;
    v37 = *(_DWORD *)(v32 + 64);
    v38 = *(_DWORD *)(v32 + 68);
    *(_DWORD *)(v32 + 104) = *(_DWORD *)(v32 + 60);
    *(_DWORD *)(v32 + 108) = v37;
    *(_DWORD *)(v32 + 112) = v38;
    v39 = UFG::qVector3::msZero.y;
    v40 = UFG::qVector3::msZero.z;
    *(float *)(v32 + 72) = UFG::qVector3::msZero.x;
    *(float *)(v32 + 76) = v39;
    *(float *)(v32 + 80) = v40;
    v41 = UFG::qVector3::msDirUp.y;
    v42 = UFG::qVector3::msDirUp.z;
    *(float *)(v32 + 72) = UFG::qVector3::msDirUp.x;
    *(float *)(v32 + 76) = v41;
    *(float *)(v32 + 80) = v42;
    if ( !*(_BYTE *)(v32 + 16) )
    {
      *(_DWORD *)(v32 + 20) = 0;
      *(_BYTE *)(v32 + 16) = *(_QWORD *)(*(_QWORD *)(v32 + 24) + 32i64) != 0i64;
    }
    v43 = UFG::NavModuleLocalFlowField::mpTaskGroup;
    v44 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v45 = v44;
    if ( v44 )
    {
      *(_QWORD *)v44 = v44;
      *((_QWORD *)v44 + 1) = v44;
      v46 = v44 + 16;
      *v46 = v46;
      v46[1] = v46;
      v47 = UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mSpuElf;
      v48 = UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mTaskFunctionSPU;
      v49 = UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mTaskFunctionPPU;
      v50 = UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mTaskFunctionOffload;
      if ( !UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat.mCurrentSPUEnabled )
      {
        v47 = 0i64;
        v48 = 0i64;
        v50 = 0i64;
      }
      *((_QWORD *)v45 + 6) = v43;
      *((_DWORD *)v45 + 14) = 2;
      *((_QWORD *)v45 + 4) = 0i64;
      *((_QWORD *)v45 + 5) = 0i64;
      *((_QWORD *)v45 + 8) = &UFG::gTaskFunctionDeclData_FlowfieldTask_FloatTheBoat;
      if ( v47 )
        v51 = v47->mAddress;
      else
        v51 = 0i64;
      *((_QWORD *)v45 + 9) = v51;
      *((_QWORD *)v45 + 10) = v48;
      *((_QWORD *)v45 + 11) = v49;
      *((_QWORD *)v45 + 12) = v32;
      *((_QWORD *)v45 + 13) = 0i64;
      *((_QWORD *)v45 + 14) = 0i64;
      *((_QWORD *)v45 + 15) = 0i64;
      if ( v50 )
      {
        *((_DWORD *)v45 + 14) = 130;
        *((_DWORD *)v45 + 12) = 0;
      }
    }
    v52 = v43->mTasks.mNode.mPrev;
    v52->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v45;
    *(_QWORD *)v45 = v52;
    *((_QWORD *)v45 + 1) = (char *)v43 + 16;
    v43->mTasks.mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v45;
    ++v43->mNumTasks;
  }
}

