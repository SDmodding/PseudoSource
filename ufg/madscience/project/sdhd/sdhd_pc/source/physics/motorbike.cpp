// File Line: 48
// RVA: 0x44AAC0
void __fastcall UFG::PhysicsMotorBike::PhysicsMotorBike(UFG::PhysicsMotorBike *this, UFG::VehicleParams *param, UFG::qMatrix44 *transform, UFG::qVector3 *velocity, UFG::qVector3 *wheelPositions)
{
  UFG::PhysicsMotorBike *v5; // rbx
  UFG::qPidController *v6; // rdi
  UFG::allocator::free_link *v7; // rax
  UFG::qPidController *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qPidController *v10; // rax

  v5 = this;
  UFG::PhysicsWheeledVehicle::PhysicsWheeledVehicle(
    (UFG::PhysicsWheeledVehicle *)&this->vfptr,
    param,
    transform,
    velocity,
    wheelPositions);
  v5->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsMotorBike::`vftable;
  v6 = 0i64;
  v5->mLeanAngle = 0.0;
  v5->mWheelieTorqueBoostCounter = 0.0;
  *(_WORD *)&v5->mDidStabilizationJustSwitchOff = 0;
  v5->mRotMassScaleForCollisions = 3.0;
  v7 = UFG::qMalloc(0xB0ui64, "WheeliePidController", 0i64);
  if ( v7 )
    UFG::qPidController::qPidController((UFG::qPidController *)v7);
  else
    v8 = 0i64;
  v5->mWheeliePidController = v8;
  v9 = UFG::qMalloc(0xB0ui64, "mLeanPidController", 0i64);
  if ( v9 )
  {
    UFG::qPidController::qPidController((UFG::qPidController *)v9);
    v6 = v10;
  }
  v5->mLeanPidController = v6;
  UFG::PhysicsMotorBike::LoadProperties(v5);
  v5->mDefaultCentreOfMass = v5->mRigidBody->mBody->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  UFG::PhysicsMotorBike::SetupConstraints(v5, UFG::BasePhysicsSystem::mInstance->mWorld);
}

// File Line: 65
// RVA: 0x4503D0
void __fastcall UFG::PhysicsMotorBike::~PhysicsMotorBike(UFG::PhysicsMotorBike *this)
{
  UFG::PhysicsMotorBike *v1; // rbx
  UFG::qPidController *v2; // rdi
  UFG::qPidControllerCore *v3; // rdi
  hkpConstraintInstance *v4; // rdx

  v1 = this;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsMotorBike::`vftable;
  v2 = this->mWheeliePidController;
  if ( v2 )
  {
    UFG::qPidControllerCore::~qPidControllerCore((UFG::qPidControllerCore *)&v2->m_Parameters);
    operator delete[](v2);
  }
  v3 = (UFG::qPidControllerCore *)&v1->mLeanPidController->m_Parameters;
  if ( v3 )
  {
    UFG::qPidControllerCore::~qPidControllerCore(v3);
    operator delete[](v3);
  }
  v4 = v1->mConstraint;
  if ( v4 )
  {
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v4);
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->mConstraint->vfptr);
    v1->mConstraint = 0i64;
  }
  v1->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsWheeledVehicle::`vftable;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents((UFG::PhysicsWheeledVehicle *)&v1->vfptr);
  UFG::PhysicsVehicle::~PhysicsVehicle((UFG::PhysicsVehicle *)&v1->vfptr);
}

// File Line: 84
// RVA: 0x472BA0
void __fastcall UFG::PhysicsMotorBike::Reload(UFG::PhysicsMotorBike *this, UFG::qSymbol *propertySetName)
{
  UFG::PhysicsMotorBike *v2; // rbx

  v2 = this;
  UFG::PhysicsWheeledVehicle::Reload((UFG::PhysicsWheeledVehicle *)&this->vfptr, propertySetName);
  UFG::PhysicsMotorBike::LoadProperties(v2);
}

// File Line: 92
// RVA: 0x46B8D0
void __fastcall UFG::PhysicsMotorBike::LoadProperties(UFG::PhysicsMotorBike *this)
{
  UFG::PhysicsMotorBike *v1; // rbx
  UFG::BikePhysicsDef *v2; // rcx
  float v3; // xmm2_4
  float v4; // xmm1_4
  float *v5; // rax
  UFG::BikePhysicsDef *v6; // rcx
  float v7; // xmm2_4
  float v8; // xmm1_4
  float *v9; // rax
  UFG::qReflectHandleBase v10; // [rsp+28h] [rbp-30h]

  v1 = this;
  UFG::qReflectHandleBase::qReflectHandleBase(&v10);
  v10.mTypeUID = UFG::qStringHash64("UFG::BikePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v10, v10.mTypeUID, v1->mDnaDefinition.mData->mBaseNode.mUID);
  v2 = (UFG::BikePhysicsDef *)v10.mData;
  v1->mLeanDesiredLo = (float)(*((float *)v10.mData[8].mBaseNode.mNeighbours + 1) * 3.1415927) * 0.0055555557;
  v1->mLeanDesiredHi = (float)(v2->lean_DesiredHi * 3.1415927) * 0.0055555557;
  v1->mLeanMinSpeed = v2->lean_MinSpeed;
  v1->mLeanMaxSpeed = v2->lean_MaxSpeed;
  v1->mLeanPID_p = v2->lean_PID_p;
  v1->mLeanPID_i = v2->lean_PID_i;
  v3 = v2->lean_PID_d;
  v1->mLeanPID_d = v3;
  v4 = v1->mLeanPID_i;
  v5 = (float *)v1->mLeanPidController;
  v5[38] = v1->mLeanPID_p;
  v5[39] = v4;
  v5[40] = v3;
  v6 = (UFG::BikePhysicsDef *)v10.mData;
  v1->mWheelieSteerRate = *(float *)&v10.mData[8].mHandles.mNode.mNext;
  v1->mWheelieAngle = (float)(v6->wheelie_Angle * 3.1415927) * 0.0055555557;
  v1->mBrakingWheelieAngle = (float)(v6->wheelie_BrakingAngle * 3.1415927) * 0.0055555557;
  v1->mBrakingWheelieYaw = v6->wheelie_BrakingYaw;
  v1->mWheelieTorqueBoost = v6->wheelie_TorqueBoost;
  v1->mWheelieTorqueBoostTime = v6->wheelie_TorqueBoostTime;
  v1->mWheeliePID_p = v6->wheelie_PID_p;
  v1->mWheeliePID_i = v6->wheelie_PID_i;
  v7 = v6->wheelie_PID_d;
  v1->mWheeliePID_d = v7;
  v8 = v1->mWheeliePID_i;
  v9 = (float *)v1->mWheeliePidController;
  v9[38] = v1->mWheeliePID_p;
  v9[39] = v8;
  v9[40] = v7;
  v1->mTuckDragBoost = *(float *)v10.mData[8].mBaseNode.mNeighbours;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v10);
}

// File Line: 123
// RVA: 0x475930
void __fastcall UFG::PhysicsMotorBike::SetupConstraints(UFG::PhysicsMotorBike *this, hkpWorld *world)
{
  hkpWorld *v2; // rsi
  UFG::PhysicsMotorBike *v3; // rdi
  signed __int64 v4; // rbx
  char v5; // r8
  __int64 v6; // rax
  char v7; // cl
  _QWORD **v8; // rax
  hkpGenericConstraintData *v9; // rax
  hkpGenericConstraintData *v10; // rax
  char v11; // al
  char v12; // dl
  __int64 v13; // rax
  char v14; // cl
  _QWORD **v15; // rax
  hkpConstraintInstance *v16; // rax
  hkpConstraintInstance *v17; // rax
  char v18; // al
  hkpConstraintConstructionKit v19; // [rsp+30h] [rbp-98h]
  __int64 v20; // [rsp+58h] [rbp-70h]
  hkMatrix3f dofBasis; // [rsp+60h] [rbp-68h]
  hkMatrix3f v22; // [rsp+90h] [rbp-38h]

  v20 = -2i64;
  v2 = world;
  v3 = this;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  v6 = v5;
  *(_DWORD *)(v4 + 4 * v6) = 3;
  *(_QWORD *)(v4 + 8 * v6 + 16) = "hkpGenericConstraintData";
  *(_QWORD *)(v4 + 8 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v4 + 81);
  if ( v5 > v7 )
    v7 = v5;
  *(_BYTE *)(v4 + 81) = v7;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpGenericConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                     v8[11],
                                     144i64);
  if ( v9 )
    hkpGenericConstraintData::hkpGenericConstraintData(v9);
  else
    v10 = 0i64;
  v3->mGenericConstraintData = v10;
  v11 = *(_BYTE *)(v4 + 80);
  if ( v11 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v11 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  hkpConstraintConstructionKit::begin(&v19, v3->mGenericConstraintData);
  dofBasis.m_col0 = (hkVector4f)transform.m_quad;
  dofBasis.m_col1 = (hkVector4f)direction.m_quad;
  dofBasis.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v22.m_col0 = (hkVector4f)transform.m_quad;
  v22.m_col1 = (hkVector4f)direction.m_quad;
  v22.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v3->mBasisIndexA = hkpConstraintConstructionKit::setAngularBasisA(&v19, &dofBasis);
  v3->mBasisIndexB = hkpConstraintConstructionKit::setAngularBasisB(&v19, &v22);
  hkpConstraintConstructionKit::setAngularLimit(&v19, 0, 0.001, -0.001);
  hkpConstraintConstructionKit::end(&v19);
  v12 = ++*(_BYTE *)(v4 + 80);
  v13 = v12;
  *(_DWORD *)(v4 + 4 * v13) = 3;
  *(_QWORD *)(v4 + 8 * v13 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v4 + 8 * v13 + 48) = 0i64;
  v14 = *(_BYTE *)(v4 + 81);
  if ( v12 > v14 )
    v14 = v12;
  *(_BYTE *)(v4 + 81) = v14;
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                   v15[11],
                                   112i64);
  if ( v16 )
    hkpConstraintInstance::hkpConstraintInstance(
      v16,
      (hkpEntity *)&v2->m_fixedRigidBody->vfptr,
      (hkpEntity *)&v3->mRigidBody->mBody->vfptr,
      (hkpConstraintData *)&v3->mGenericConstraintData->vfptr,
      PRIORITY_PSI);
  else
    v17 = 0i64;
  v3->mConstraint = v17;
  v18 = *(_BYTE *)(v4 + 80);
  if ( v18 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v18 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->mGenericConstraintData->vfptr);
}

// File Line: 161
// RVA: 0x47E5C0
void __fastcall UFG::PhysicsMotorBike::UpdateConstraints(UFG::PhysicsMotorBike *this, float deltaTime)
{
  hkpConstraintInstance *v2; // rdx
  UFG::PhysicsMotorBike *v3; // rbx
  UFG::RigidBodyComponent *v4; // rax
  hkQuaternionf *v5; // rcx
  float v6; // xmm7_4
  hkpConstraintInstance *v7; // rdx
  __m128 v8; // xmm8
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm3
  float v14; // xmm2_4
  int v15; // edx
  hkpGenericConstraintData *v16; // rcx
  __m128 v17; // xmm5
  __m128 v18; // xmm8
  __m128 v19; // xmm8
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  UFG::VehicleInstance *v28; // rax
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm8_4
  float v35; // xmm5_4
  float v36; // xmm9_4
  float v37; // xmm6_4
  float v38; // xmm6_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  hkpGenericConstraintData *v43; // rcx
  int v44; // edx
  __m128 v45; // xmm2
  hkVector4f direction; // [rsp+20h] [rbp-79h]
  hkVector4f v47; // [rsp+30h] [rbp-69h]
  hkVector4f newValues; // [rsp+40h] [rbp-59h]
  hkVector4f axis; // [rsp+50h] [rbp-49h]
  hkVector4f v50; // [rsp+60h] [rbp-39h]
  hkQuaternionf quat; // [rsp+70h] [rbp-29h]

  v2 = this->mConstraint;
  v3 = this;
  v4 = this->mRigidBody;
  v5 = (hkQuaternionf *)v2->m_entities[1];
  v6 = deltaTime;
  if ( v4->mBody->m_world )
  {
    if ( v3->mDisableConstraint )
    {
      if ( v2->m_owner )
        UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v2);
      return;
    }
    axis.m_quad = (__m128)_xmm;
    direction.m_quad = (__m128)_xmm;
    newValues.m_quad = _xmm;
    v50.m_quad = _xmm;
    v47.m_quad = _xmm;
    hkVector4f::setRotatedDir(&direction, v5 + 30, &direction);
    v7 = v3->mConstraint;
    direction.m_quad.m128_i32[3] = 0;
    v8 = v47.m_quad;
    v9 = _mm_mul_ps(direction.m_quad, direction.m_quad);
    v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v11 = _mm_rsqrt_ps(v10);
    v12 = _mm_mul_ps(
            direction.m_quad,
            _mm_andnot_ps(
              _mm_cmpleps(v10, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                _mm_mul_ps(v11, *(__m128 *)_xmm))));
    v13 = _mm_mul_ps(v47.m_quad, v12);
    direction.m_quad = v12;
    LODWORD(v14) = COERCE_UNSIGNED_INT(
                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) & _xmm;
    if ( v7->m_owner )
    {
      if ( v14 <= 0.94999999 )
        goto LABEL_13;
      UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v7);
      v3->mDidStabilizationJustSwitchOff = 1;
    }
    else
    {
      if ( v3->mDidStabilizationJustSwitchOff
        || COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          (float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
                        + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) & _xmm) > 0.5 )
      {
LABEL_12:
        if ( v14 > 0.94999999 )
          return;
LABEL_13:
        if ( v6 <= 0.0 )
          return;
        v15 = v3->mBasisIndexA;
        v16 = v3->mGenericConstraintData;
        v17 = _mm_shuffle_ps(v12, v12, 201);
        v18 = _mm_sub_ps(_mm_mul_ps(v8, v17), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v12));
        v19 = _mm_shuffle_ps(v18, v18, 201);
        v20 = _mm_mul_ps(v19, v19);
        v21 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170));
        v22 = _mm_rsqrt_ps(v21);
        newValues.m_quad = _mm_mul_ps(
                             v19,
                             _mm_andnot_ps(
                               _mm_cmpleps(v21, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                 _mm_mul_ps(v22, *(__m128 *)_xmm))));
        v23 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(newValues.m_quad, newValues.m_quad, 201), v12),
                _mm_mul_ps(newValues.m_quad, v17));
        v24 = _mm_shuffle_ps(v23, v23, 201);
        v25 = _mm_mul_ps(v24, v24);
        v26 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                _mm_shuffle_ps(v25, v25, 170));
        v27 = _mm_rsqrt_ps(v26);
        v47.m_quad = _mm_mul_ps(
                       v24,
                       _mm_andnot_ps(
                         _mm_cmpleps(v26, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                           _mm_mul_ps(v27, *(__m128 *)_xmm))));
        hkpGenericConstraintData::setParameters(v16, v15, 1, &direction);
        hkpGenericConstraintData::setParameters(v3->mGenericConstraintData, v3->mBasisIndexA + 1, 1, &newValues);
        hkpGenericConstraintData::setParameters(v3->mGenericConstraintData, v3->mBasisIndexA + 2, 1, &v47);
        v28 = v3->mHavokVehicle;
        v29 = v28->m_mainSteeringAngle;
        v30 = *(float *)&v28->m_steering[3].m_memSizeAndFlags;
        if ( COERCE_FLOAT(LODWORD(v30) & _xmm) > 0.001 )
          v29 = v29 / v30;
        v31 = v3->mLeanDesiredHi;
        v32 = v3->mLeanDesiredLo;
        v33 = v3->mLeanMinSpeed * v3->mLeanMinSpeed;
        if ( v32 >= v31 )
          v34 = v3->mLeanDesiredHi;
        else
          v34 = v3->mLeanDesiredLo;
        if ( v32 <= v31 )
          v35 = v3->mLeanDesiredHi;
        else
          v35 = v3->mLeanDesiredLo;
        v36 = FLOAT_0_000099999997;
        if ( (float)((float)(v3->mLeanMaxSpeed * v3->mLeanMaxSpeed) - v33) >= 0.000099999997 )
          v36 = (float)(v3->mLeanMaxSpeed * v3->mLeanMaxSpeed) - v33;
        v37 = (float)((float)((float)(v3->mSpeedKPH * v3->mSpeedKPH) - v33) * (float)((float)(v31 - v32) / v36)) + v32;
        if ( v37 <= v34 )
          v37 = v34;
        if ( v37 >= v35 )
          v37 = v35;
        LODWORD(v38) = COERCE_UNSIGNED_INT(v37 * v29) ^ _xmm[0];
        UFG::qPidControllerCore::Record(
          (UFG::qPidControllerCore *)&v3->mLeanPidController->m_Parameters,
          v38 - v3->mLeanAngle,
          v6,
          0i64);
        v39 = UFG::qPidControllerCore::GetOutput((UFG::qPidControllerCore *)&v3->mLeanPidController->m_Parameters);
        v40 = v3->mLeanAngle;
        v41 = v39 * (float)(v6 * 29.999998);
        if ( v40 >= v38 )
        {
          if ( v40 <= v38 )
            goto LABEL_31;
          v42 = v40 + v41;
          if ( v42 < v38 )
          {
LABEL_30:
            v3->mLeanAngle = v38;
LABEL_31:
            hkQuaternionf::setAxisAngle(&quat, &axis, v3->mLeanAngle);
            hkVector4f::setRotatedDir(&v47, &quat, &v50);
            v43 = v3->mGenericConstraintData;
            v44 = v3->mBasisIndexB + 1;
            v45 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(axis.m_quad, axis.m_quad, 201), v47.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v47.m_quad, v47.m_quad, 201), axis.m_quad));
            newValues.m_quad = _mm_shuffle_ps(v45, v45, 201);
            hkpGenericConstraintData::setParameters(v43, v44, 1, &newValues);
            hkpGenericConstraintData::setParameters(v3->mGenericConstraintData, v3->mBasisIndexB + 2, 1, &v47);
            return;
          }
        }
        else
        {
          v42 = v40 + v41;
          if ( v42 > v38 )
            goto LABEL_30;
        }
        v3->mLeanAngle = v42;
        goto LABEL_31;
      }
      UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v7);
    }
    v8 = v47.m_quad;
    v12 = direction.m_quad;
    goto LABEL_12;
  }
}nAngle = v42;
  

// File Line: 291
// RVA: 0x47EE20
int UFG::PhysicsMotorBike::UpdateHighLod(...)
{
  UFG::PhysicsMotorBike *v3; // rdi
  UFG::VehicleInput *v4; // rsi
  __int128 v5; // xmm9
  hkpVehicleAerodynamics *v6; // rcx
  __m128 v7; // xmm6
  char v8; // bp
  float v9; // xmm0_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  UFG::VehicleInstance *v12; // rax
  int v13; // edx
  hkpVehicleEngine *v14; // rcx
  float v15; // xmm0_4
  bool v16; // cf
  bool v17; // zf
  hkpVehicleInstance::WheelInfo *v18; // rcx
  UFG::RigidBodyComponent *v19; // rax
  hkpEntity *v20; // rbx
  __int64 v21; // rdx
  float v22; // xmm0_4
  float v23; // xmm0_4
  int v24; // eax
  int v25; // edx
  unsigned int v26; // eax
  UFG::VehicleInstance *v27; // r8
  __int64 v28; // rcx
  __int64 v29; // r9
  float v30; // xmm2_4
  float v31; // xmm11_4
  __int128 v32; // xmm0
  int v33; // eax
  __m128 v34; // xmm6
  signed __int64 v35; // r9
  UFG::RigidBodyComponent *v36; // rax
  hkpRigidBody *v37; // rbx
  __int64 v38; // rdx
  UFG::VehicleInstance *v39; // rcx
  float v40; // xmm0_4
  __m128 v41; // xmm3
  __m128 v42; // xmm5
  __m128 v43; // xmm2
  UFG::RigidBodyComponent *v44; // rax
  float v45; // xmm10_4
  __m128 v46; // xmm4
  hkpRigidBody *v47; // rbx
  __int64 v48; // rdx
  UFG::VehicleInstance *v49; // rax
  hkpVehicleDriverInputStatus *v50; // rcx
  hkVector4f centerOfMass; // [rsp+30h] [rbp-B8h]
  hkVector4f direction; // [rsp+40h] [rbp-A8h]
  hkVector4f v53; // [rsp+50h] [rbp-98h]
  __m128 v54; // [rsp+60h] [rbp-88h]

  v3 = this;
  v4 = input;
  v5 = deltaTime;
  v6 = this->mHavokVehicle->m_aerodynamics;
  LODWORD(v6[3].vfptr) = 0;
  if ( input->mForwardWeightShift > 0.25 )
    *(float *)&v6[3].vfptr = v3->mTuckDragBoost;
  v7 = (__m128)(unsigned int)FLOAT_1_0;
  centerOfMass.m_quad = (__m128)v3->mDefaultCentreOfMass;
  v8 = 0;
  v9 = v3->mBodyTransform.v0.z;
  v10 = 0.0;
  if ( v9 <= -1.0 )
  {
    v9 = FLOAT_N1_0;
  }
  else if ( v9 >= 1.0 )
  {
    v9 = *(float *)&FLOAT_1_0;
  }
  v11 = asinf(v9);
  v12 = v3->mHavokVehicle;
  v13 = *((_DWORD *)v4 + 4);
  v14 = v12->m_engine;
  if ( !(v13 & 8) || _bittest(&v13, 8u) )
  {
    v3->mWheelieTorqueBoostCounter = 0.0;
    if ( *((_BYTE *)v4 + 16) & 0x10 )
    {
      v8 = 1;
      v10 = (float)(v3->mBrakingWheelieAngle * v4->mForwardWeightShift) + v11;
      if ( v12 )
      {
        v18 = v12->m_wheelsInfo.m_data;
        if ( !v18[1].m_contactBody )
        {
          if ( v18->m_contactBody )
          {
            if ( v4->mSteering <= 0.0 )
            {
              if ( v4->mSteering >= 0.0 )
                v7 = 0i64;
              else
                v7 = (__m128)LODWORD(FLOAT_N1_0);
            }
            v7.m128_f32[0] = v7.m128_f32[0] * v3->mBrakingWheelieYaw;
            v19 = v3->mRigidBody;
            direction.m_quad = _mm_unpacklo_ps(
                                 _mm_unpacklo_ps((__m128)0i64, _mm_xor_ps(v7, *(__m128 *)_xmm)),
                                 (__m128)0i64);
            hkVector4f::setRotatedDir(
              &v53,
              &v19->mBody->m_motion.m_motionState.m_sweptTransform.m_rotation1,
              &direction);
            v20 = (hkpEntity *)&v3->mRigidBody->mBody->vfptr;
            hkpEntity::activate(v20);
            ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))v20->m_motion.vfptr[13].__first_virtual_table_function__)(
              &v20->m_motion,
              v21,
              &v53);
            v7.m128_i32[0] = (signed int)FLOAT_1_0;
          }
        }
      }
    }
    if ( v3->mSpeedKPH < 5.0 )
    {
      v22 = v4->mForwardWeightShift;
      if ( v22 <= 0.25 )
      {
        if ( v22 >= -0.25 )
          goto LABEL_26;
        v23 = centerOfMass.m_quad.m128_f32[0] + -0.1;
      }
      else
      {
        v23 = centerOfMass.m_quad.m128_f32[0] + 0.1;
      }
      centerOfMass.m_quad.m128_f32[0] = v23;
    }
  }
  else
  {
    v8 = 1;
    v10 = (float)(v3->mWheelieAngle * v4->mForwardWeightShift) + v11;
    v15 = *(float *)&deltaTime + v3->mWheelieTorqueBoostCounter;
    v16 = v15 < v3->mWheelieTorqueBoostTime;
    v17 = v15 == v3->mWheelieTorqueBoostTime;
    v3->mWheelieTorqueBoostCounter = v15;
    if ( v16 || v17 )
      *(float *)(&v14[4].m_referenceCount + 1) = v3->mWheelieTorqueBoost + *(float *)(&v14[4].m_referenceCount + 1);
  }
LABEL_26:
  v24 = *((_DWORD *)&v3->0 + 151);
  if ( !(v24 & 0x10) )
  {
    v25 = 0;
    v26 = *((_DWORD *)&v3->0 + 151) & 7;
    if ( !v26 )
      goto LABEL_62;
    v27 = v3->mHavokVehicle;
    v28 = 0i64;
    v29 = v26;
    do
    {
      if ( !v27 || v27->m_wheelsInfo.m_data[v28].m_contactBody != 0i64 )
        ++v25;
      ++v28;
      --v29;
    }
    while ( v29 );
    if ( v25 == 1 )
      v30 = FLOAT_10_0;
    else
LABEL_62:
      v30 = v3->mRotMassScaleForCollisions;
    UFG::PhysicsVehicle::SetMassScaleForCollisions((UFG::PhysicsVehicle *)&v3->vfptr, v7.m128_f32[0], v30);
    v7.m128_i32[0] = (signed int)FLOAT_1_0;
  }
  if ( !v8 )
  {
    UFG::qPidControllerCore::Clear((UFG::qPidControllerCore *)&v3->mWheeliePidController->m_Parameters);
    v3->mWheelieBlend = 0.0;
    goto LABEL_48;
  }
  v32 = v5;
  v31 = FLOAT_N20000_0;
  *(float *)&v32 = *(float *)&v5 + v3->mWheelieBlend;
  LODWORD(v3->mWheelieBlend) = v32;
  if ( *(float *)&v32 > v7.m128_f32[0] )
    v3->mWheelieBlend = 1.0;
  UFG::qPidControllerCore::Record(
    (UFG::qPidControllerCore *)&v3->mWheeliePidController->m_Parameters,
    v10,
    *(float *)&v5,
    0i64);
  *(float *)&v32 = UFG::qPidControllerCore::GetOutput((UFG::qPidControllerCore *)&v3->mWheeliePidController->m_Parameters);
  v33 = *((_DWORD *)v4 + 4);
  v34 = (__m128)v32;
  if ( v33 & 8 && !_bittest(&v33, 8u) )
  {
    v35 = 0i64;
LABEL_45:
    ((void (__fastcall *)(UFG::VehicleInstance *, hkpRigidBody *, hkpVehicleSuspension *, signed __int64, hkVector4f *, hkVector4f *))v3->mHavokVehicle->vfptr[5].__first_virtual_table_function__)(
      v3->mHavokVehicle,
      v3->mRigidBody->mBody,
      v3->mHavokVehicle->m_suspension,
      v35,
      &direction,
      &v53);
    goto LABEL_46;
  }
  if ( v33 & 0x10 )
  {
    v31 = FLOAT_10000_0;
    v35 = 1i64;
    goto LABEL_45;
  }
LABEL_46:
  v36 = v3->mRigidBody;
  v34.m128_f32[0] = (float)(*(float *)&v32 * v31) * v3->mWheelieBlend;
  v54 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v34), (__m128)0i64);
  v37 = v36->mBody;
  hkpEntity::activate((hkpEntity *)&v36->mBody->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, hkVector4f *))v37->m_motion.vfptr[12].__first_virtual_table_function__)(
    &v37->m_motion,
    v38,
    &v54,
    &direction);
LABEL_48:
  hkpRigidBody::setCenterOfMassLocal(v3->mRigidBody->mBody, &centerOfMass);
  v39 = v3->mHavokVehicle;
  if ( v39 )
  {
    if ( v39->m_wheelsInfo.m_data[1].m_contactBody != 0i64 )
    {
      if ( v39 )
      {
        if ( v39->m_wheelsInfo.m_data->m_contactBody == 0i64 )
        {
          LODWORD(v40) = LODWORD(v4->mSteering) & _xmm;
          if ( v40 > 0.25 )
          {
            v41 = (__m128)LODWORD(v3->mBodyTransform.v1.z);
            v42 = (__m128)LODWORD(v3->mBodyTransform.v1.x);
            v43 = (__m128)LODWORD(v3->mBodyTransform.v1.w);
            v44 = v3->mRigidBody;
            v45 = (float)((float)(-1.0 / v40) * v4->mSteering) * v3->mWheelieSteerRate;
            v46 = (__m128)LODWORD(v3->mBodyTransform.v1.y);
            v42.m128_f32[0] = (float)((float)((float)(v42.m128_f32[0] + v3->mBodyTransform.v0.x) * 0.0)
                                    + (float)(v45 * v3->mBodyTransform.v2.x))
                            + (float)(v3->mBodyTransform.v3.x * 0.0);
            v46.m128_f32[0] = (float)((float)((float)(v46.m128_f32[0] + v3->mBodyTransform.v0.y) * 0.0)
                                    + (float)(v45 * v3->mBodyTransform.v2.y))
                            + (float)(v3->mBodyTransform.v3.y * 0.0);
            v41.m128_f32[0] = (float)((float)((float)(v41.m128_f32[0] + v3->mBodyTransform.v0.z) * 0.0)
                                    + (float)(v45 * v3->mBodyTransform.v2.z))
                            + (float)(v3->mBodyTransform.v3.z * 0.0);
            v43.m128_f32[0] = (float)((float)((float)(v43.m128_f32[0] + v3->mBodyTransform.v0.w) * 0.0)
                                    + (float)(v45 * v3->mBodyTransform.v2.w))
                            + (float)(v3->mBodyTransform.v3.w * 0.0);
            v54 = _mm_unpacklo_ps(_mm_unpacklo_ps(v42, v41), _mm_unpacklo_ps(v46, v43));
            v47 = v44->mBody;
            hkpEntity::activate((hkpEntity *)&v44->mBody->vfptr);
            ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *))v47->m_motion.vfptr[13].__first_virtual_table_function__)(
              &v47->m_motion,
              v48,
              &v54);
          }
        }
      }
    }
  }
  v49 = v3->mHavokVehicle;
  v50 = v49->m_deviceStatus;
  if ( v49 && v49->m_wheelsInfo.m_data->m_contactBody == 0i64 || *((_BYTE *)v4 + 16) & 0x10 )
    LODWORD(v50[1].vfptr) = 0;
  else
    *(float *)&v50[1].vfptr = v4->mSteering;
  UFG::PhysicsMotorBike::UpdateConstraints(v3, *(float *)&v5);
}

// File Line: 441
// RVA: 0x473450
void __fastcall UFG::PhysicsMotorBike::Reset(UFG::PhysicsMotorBike *this, UFG::VehicleResetOptions options)
{
  __int64 v2; // rbx
  UFG::VehicleResetOptions v3; // esi
  hkpConstraintInstance *v4; // rdx
  UFG::PhysicsMotorBike *v5; // rdi
  hkpVehicleWheelCollide *v6; // rcx

  v2 = 0i64;
  v3 = options;
  v4 = this->mConstraint;
  v5 = this;
  this->mLeanAngle = 0.0;
  if ( v4 )
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v4);
  UFG::PhysicsVehicle::Reset((UFG::PhysicsVehicle *)&v5->vfptr, v3);
  if ( *((_BYTE *)&v5->0 + 604) & 7 )
  {
    do
    {
      v6 = v5->mWheelCollider;
      if ( v6 )
      {
        if ( (*((_DWORD *)&v5->0 + 151) & 7) == 2 )
          *((_DWORD *)&v6[8].m_memSizeAndFlags + v2) = 1065353216;
        else
          *((_DWORD *)&v6[7].m_alreadyUsed.m_bool + v2) = 1065353216;
      }
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (*((_DWORD *)&v5->0 + 151) & 7u) );
    v5->mDisableConstraint = 0;
  }
  else
  {
    v5->mDisableConstraint = 0;
  }
}

// File Line: 456
// RVA: 0x476230
void __fastcall UFG::PhysicsMotorBike::StandUpright(UFG::PhysicsMotorBike *this)
{
  this->mDisableConstraint = 0;
}

// File Line: 463
// RVA: 0x463D90
void __fastcall UFG::PhysicsMotorBike::DumpBike(UFG::PhysicsMotorBike *this)
{
  this->mDisableConstraint = 1;
}

// File Line: 470
// RVA: 0x461970
_BOOL8 __fastcall UFG::PhysicsMotorBike::DidStabilizationJustSwitchOff(UFG::PhysicsMotorBike *this)
{
  return this->mDidStabilizationJustSwitchOff;
}

// File Line: 474
// RVA: 0x46B4C0
_BOOL8 __fastcall UFG::PhysicsMotorBike::IsStabilizationDisabled(UFG::PhysicsMotorBike *this)
{
  return this->mDisableConstraint;
}

// File Line: 481
// RVA: 0x473BB0
void __fastcall UFG::PhysicsMotorBike::ResetStabilization(UFG::PhysicsMotorBike *this)
{
  this->mDidStabilizationJustSwitchOff = 0;
}

// File Line: 488
// RVA: 0x474D20
void __fastcall UFG::PhysicsMotorBike::SetLevelOfDetailInternal(UFG::PhysicsMotorBike *this, UFG::PhysicsVehicle::Lod lod)
{
  UFG::PhysicsVehicle::Lod v2; // ebx
  UFG::PhysicsMotorBike *v3; // rdi

  v2 = lod;
  v3 = this;
  UFG::PhysicsWheeledVehicle::SetLevelOfDetailInternal((UFG::PhysicsWheeledVehicle *)&this->vfptr, lod);
  if ( (signed int)v2 > 0 )
  {
    if ( (signed int)v2 <= 2 )
      goto LABEL_10;
    if ( v2 == 3 )
    {
      UFG::qPidControllerCore::Clear((UFG::qPidControllerCore *)&v3->mWheeliePidController->m_Parameters);
      UFG::qPidControllerCore::Clear((UFG::qPidControllerCore *)&v3->mLeanPidController->m_Parameters);
      return;
    }
    if ( v2 == 4 )
LABEL_10:
      UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v3->mConstraint);
  }
}

// File Line: 510
// RVA: 0x476360
void __fastcall UFG::PhysicsMotorBike::Suspend(UFG::PhysicsMotorBike *this)
{
  UFG::PhysicsMotorBike *v1; // rbx
  hkpConstraintInstance *v2; // rdx

  v1 = this;
  UFG::PhysicsWheeledVehicle::Suspend((UFG::PhysicsWheeledVehicle *)&this->vfptr);
  v2 = v1->mConstraint;
  if ( v2 )
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v2);
}

// File Line: 521
// RVA: 0x473C00
void __fastcall UFG::PhysicsMotorBike::ResourceUnloaded(UFG::PhysicsMotorBike *this, UFG::PhysicsResourceHandle *resource)
{
  UFG::PhysicsResourceHandle *v2; // rdi
  hkpConstraintInstance *v3; // rdx
  UFG::PhysicsMotorBike *v4; // rbx

  v2 = resource;
  v3 = this->mConstraint;
  v4 = this;
  if ( v3 )
  {
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v3);
    hkReferencedObject::removeReference((hkReferencedObject *)&v4->mConstraint->vfptr);
    v4->mConstraint = 0i64;
  }
  v4->mDesiredLod = 5;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents((UFG::PhysicsWheeledVehicle *)&v4->vfptr);
  UFG::PhysicsVehicle::ResourceUnloaded((UFG::PhysicsVehicle *)&v4->vfptr, v2);
}

