// File Line: 48
// RVA: 0x44AAC0
void __fastcall UFG::PhysicsMotorBike::PhysicsMotorBike(
        UFG::PhysicsMotorBike *this,
        UFG::VehicleParams *param,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *velocity,
        UFG::qVector3 *wheelPositions)
{
  UFG::qPidController *v6; // rdi
  UFG::allocator::free_link *v7; // rax
  UFG::qPidController *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qPidController *v10; // rax

  UFG::PhysicsWheeledVehicle::PhysicsWheeledVehicle(this, param, transform, velocity, wheelPositions);
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsMotorBike::`vftable;
  v6 = 0i64;
  this->mLeanAngle = 0.0;
  this->mWheelieTorqueBoostCounter = 0.0;
  *(_WORD *)&this->mDidStabilizationJustSwitchOff = 0;
  this->mRotMassScaleForCollisions = 3.0;
  v7 = UFG::qMalloc(0xB0ui64, "WheeliePidController", 0i64);
  if ( v7 )
    UFG::qPidController::qPidController((UFG::qPidController *)v7);
  else
    v8 = 0i64;
  this->mWheeliePidController = v8;
  v9 = UFG::qMalloc(0xB0ui64, "mLeanPidController", 0i64);
  if ( v9 )
  {
    UFG::qPidController::qPidController((UFG::qPidController *)v9);
    v6 = v10;
  }
  this->mLeanPidController = v6;
  UFG::PhysicsMotorBike::LoadProperties(this);
  this->mDefaultCentreOfMass = this->mRigidBody->mBody->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  UFG::PhysicsMotorBike::SetupConstraints(this, UFG::BasePhysicsSystem::mInstance->mWorld);
}

// File Line: 65
// RVA: 0x4503D0
void __fastcall UFG::PhysicsMotorBike::~PhysicsMotorBike(UFG::PhysicsMotorBike *this)
{
  UFG::qPidController *mWheeliePidController; // rdi
  UFG::qPidController *mLeanPidController; // rdi
  hkpConstraintInstance *mConstraint; // rdx

  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsMotorBike::`vftable;
  mWheeliePidController = this->mWheeliePidController;
  if ( mWheeliePidController )
  {
    UFG::qPidControllerCore::~qPidControllerCore(mWheeliePidController);
    operator delete[](mWheeliePidController);
  }
  mLeanPidController = this->mLeanPidController;
  if ( mLeanPidController )
  {
    UFG::qPidControllerCore::~qPidControllerCore(mLeanPidController);
    operator delete[](mLeanPidController);
  }
  mConstraint = this->mConstraint;
  if ( mConstraint )
  {
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, mConstraint);
    hkReferencedObject::removeReference(this->mConstraint);
    this->mConstraint = 0i64;
  }
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsWheeledVehicle::`vftable;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
  UFG::PhysicsVehicle::~PhysicsVehicle(this);
}

// File Line: 84
// RVA: 0x472BA0
void __fastcall UFG::PhysicsMotorBike::Reload(UFG::PhysicsMotorBike *this, UFG::qSymbol *propertySetName)
{
  UFG::PhysicsWheeledVehicle::Reload(this, propertySetName);
  UFG::PhysicsMotorBike::LoadProperties(this);
}

// File Line: 92
// RVA: 0x46B8D0
void __fastcall UFG::PhysicsMotorBike::LoadProperties(UFG::PhysicsMotorBike *this)
{
  UFG::BikePhysicsDef *mData; // rcx
  float lean_PID_d; // xmm2_4
  float mLeanPID_i; // xmm1_4
  UFG::qPidController *mLeanPidController; // rax
  UFG::BikePhysicsDef *v6; // rcx
  float wheelie_PID_d; // xmm2_4
  float mWheeliePID_i; // xmm1_4
  UFG::qPidController *mWheeliePidController; // rax
  UFG::qReflectHandleBase v10; // [rsp+28h] [rbp-30h] BYREF

  UFG::qReflectHandleBase::qReflectHandleBase(&v10);
  v10.mTypeUID = UFG::qStringHash64("UFG::BikePhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v10, v10.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
  mData = (UFG::BikePhysicsDef *)v10.mData;
  this->mLeanDesiredLo = (float)(*((float *)v10.mData[8].mBaseNode.mNeighbours + 1) * 3.1415927) * 0.0055555557;
  this->mLeanDesiredHi = (float)(mData->lean_DesiredHi * 3.1415927) * 0.0055555557;
  this->mLeanMinSpeed = mData->lean_MinSpeed;
  this->mLeanMaxSpeed = mData->lean_MaxSpeed;
  this->mLeanPID_p = mData->lean_PID_p;
  this->mLeanPID_i = mData->lean_PID_i;
  lean_PID_d = mData->lean_PID_d;
  this->mLeanPID_d = lean_PID_d;
  mLeanPID_i = this->mLeanPID_i;
  mLeanPidController = this->mLeanPidController;
  mLeanPidController->m_ParameterBlock.m_P_Coefficient = this->mLeanPID_p;
  mLeanPidController->m_ParameterBlock.m_I_Coefficient = mLeanPID_i;
  mLeanPidController->m_ParameterBlock.m_D_Coefficient = lean_PID_d;
  v6 = (UFG::BikePhysicsDef *)v10.mData;
  this->mWheelieSteerRate = *(float *)&v10.mData[8].mHandles.mNode.mNext;
  this->mWheelieAngle = (float)(v6->wheelie_Angle * 3.1415927) * 0.0055555557;
  this->mBrakingWheelieAngle = (float)(v6->wheelie_BrakingAngle * 3.1415927) * 0.0055555557;
  this->mBrakingWheelieYaw = v6->wheelie_BrakingYaw;
  this->mWheelieTorqueBoost = v6->wheelie_TorqueBoost;
  this->mWheelieTorqueBoostTime = v6->wheelie_TorqueBoostTime;
  this->mWheeliePID_p = v6->wheelie_PID_p;
  this->mWheeliePID_i = v6->wheelie_PID_i;
  wheelie_PID_d = v6->wheelie_PID_d;
  this->mWheeliePID_d = wheelie_PID_d;
  mWheeliePID_i = this->mWheeliePID_i;
  mWheeliePidController = this->mWheeliePidController;
  mWheeliePidController->m_ParameterBlock.m_P_Coefficient = this->mWheeliePID_p;
  mWheeliePidController->m_ParameterBlock.m_I_Coefficient = mWheeliePID_i;
  mWheeliePidController->m_ParameterBlock.m_D_Coefficient = wheelie_PID_d;
  this->mTuckDragBoost = *(float *)v10.mData[8].mBaseNode.mNeighbours;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v10);
}

// File Line: 123
// RVA: 0x475930
void __fastcall UFG::PhysicsMotorBike::SetupConstraints(UFG::PhysicsMotorBike *this, hkpWorld *world)
{
  __int64 v4; // rbx
  char v5; // r8
  char v6; // cl
  _QWORD **Value; // rax
  hkpGenericConstraintData *v8; // rax
  hkpGenericConstraintData *v9; // rax
  char v10; // al
  char v11; // dl
  char v12; // cl
  _QWORD **v13; // rax
  hkpConstraintInstance *v14; // rax
  hkpConstraintInstance *v15; // rax
  char v16; // al
  hkpConstraintConstructionKit v17; // [rsp+30h] [rbp-98h] BYREF
  __int64 v18; // [rsp+58h] [rbp-70h]
  hkMatrix3f dofBasis; // [rsp+60h] [rbp-68h] BYREF
  hkMatrix3f v20; // [rsp+90h] [rbp-38h] BYREF

  v18 = -2i64;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v5) = 3;
  *(_QWORD *)(v4 + 8i64 * v5 + 16) = "hkpGenericConstraintData";
  *(_QWORD *)(v4 + 8i64 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v4 + 81);
  if ( v5 > v6 )
    v6 = v5;
  *(_BYTE *)(v4 + 81) = v6;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpGenericConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
  if ( v8 )
    hkpGenericConstraintData::hkpGenericConstraintData(v8);
  else
    v9 = 0i64;
  this->mGenericConstraintData = v9;
  v10 = *(_BYTE *)(v4 + 80);
  if ( v10 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v10 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  hkpConstraintConstructionKit::begin(&v17, this->mGenericConstraintData);
  dofBasis.m_col0 = (hkVector4f)transform.m_quad;
  dofBasis.m_col1 = (hkVector4f)direction.m_quad;
  dofBasis.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v20.m_col0 = (hkVector4f)transform.m_quad;
  v20.m_col1 = (hkVector4f)direction.m_quad;
  v20.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->mBasisIndexA = hkpConstraintConstructionKit::setAngularBasisA(&v17, &dofBasis);
  this->mBasisIndexB = hkpConstraintConstructionKit::setAngularBasisB(&v17, &v20);
  hkpConstraintConstructionKit::setAngularLimit(&v17, 0, 0.001, -0.001);
  hkpConstraintConstructionKit::end(&v17);
  v11 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v11) = 3;
  *(_QWORD *)(v4 + 8i64 * v11 + 16) = "hkpConstraintInstance";
  *(_QWORD *)(v4 + 8i64 * v11 + 48) = 0i64;
  v12 = *(_BYTE *)(v4 + 81);
  if ( v11 > v12 )
    v12 = v11;
  *(_BYTE *)(v4 + 81) = v12;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 112i64);
  if ( v14 )
    hkpConstraintInstance::hkpConstraintInstance(
      v14,
      world->m_fixedRigidBody,
      this->mRigidBody->mBody,
      this->mGenericConstraintData,
      PRIORITY_PSI);
  else
    v15 = 0i64;
  this->mConstraint = v15;
  v16 = *(_BYTE *)(v4 + 80);
  if ( v16 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v16 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(this->mGenericConstraintData);
}

// File Line: 161
// RVA: 0x47E5C0
void __fastcall UFG::PhysicsMotorBike::UpdateConstraints(UFG::PhysicsMotorBike *this, float deltaTime)
{
  hkpConstraintInstance *mConstraint; // rdx
  UFG::RigidBodyComponent *mRigidBody; // rax
  hkQuaternionf *v5; // rcx
  hkpConstraintInstance *v7; // rdx
  __m128 m_quad; // xmm8
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm3
  float v14; // xmm2_4
  int mBasisIndexA; // edx
  hkpGenericConstraintData *mGenericConstraintData; // rcx
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
  UFG::VehicleInstance *mHavokVehicle; // rax
  float m_mainSteeringAngle; // xmm4_4
  float v30; // xmm1_4
  float mLeanDesiredHi; // xmm0_4
  float mLeanDesiredLo; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm8_4
  float v35; // xmm5_4
  float v36; // xmm9_4
  float v37; // xmm6_4
  float v38; // xmm6_4
  float Output; // xmm0_4
  float mLeanAngle; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  hkpGenericConstraintData *v43; // rcx
  int v44; // edx
  __m128 v45; // xmm2
  hkVector4f direction; // [rsp+20h] [rbp-79h] BYREF
  hkVector4f v47; // [rsp+30h] [rbp-69h] BYREF
  hkVector4f newValues; // [rsp+40h] [rbp-59h] BYREF
  hkVector4f axis; // [rsp+50h] [rbp-49h] BYREF
  hkVector4f v50; // [rsp+60h] [rbp-39h] BYREF
  hkQuaternionf quat; // [rsp+70h] [rbp-29h] BYREF

  mConstraint = this->mConstraint;
  mRigidBody = this->mRigidBody;
  v5 = (hkQuaternionf *)mConstraint->m_entities[1];
  if ( mRigidBody->mBody->m_world )
  {
    if ( this->mDisableConstraint )
    {
      if ( mConstraint->m_owner )
        UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, mConstraint);
      return;
    }
    axis.m_quad = (__m128)_xmm;
    direction.m_quad = (__m128)_xmm;
    newValues.m_quad = _xmm;
    v50.m_quad = _xmm;
    v47.m_quad = _xmm;
    hkVector4f::setRotatedDir(&direction, v5 + 30, &direction);
    v7 = this->mConstraint;
    direction.m_quad.m128_i32[3] = 0;
    m_quad = v47.m_quad;
    v9 = _mm_mul_ps(direction.m_quad, direction.m_quad);
    v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v11 = _mm_rsqrt_ps(v10);
    v12 = _mm_mul_ps(
            direction.m_quad,
            _mm_andnot_ps(
              _mm_cmple_ps(v10, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                _mm_mul_ps(v11, *(__m128 *)_xmm))));
    v13 = _mm_mul_ps(v47.m_quad, v12);
    direction.m_quad = v12;
    LODWORD(v14) = COERCE_UNSIGNED_INT(
                     (float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
                   + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) & _xmm;
    if ( v7->m_owner )
    {
      if ( v14 <= 0.94999999 )
        goto LABEL_13;
      UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v7);
      this->mDidStabilizationJustSwitchOff = 1;
    }
    else
    {
      if ( this->mDidStabilizationJustSwitchOff
        || COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          (float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
                        + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) & _xmm) > 0.5 )
      {
LABEL_12:
        if ( v14 > 0.94999999 )
          return;
LABEL_13:
        if ( deltaTime <= 0.0 )
          return;
        mBasisIndexA = this->mBasisIndexA;
        mGenericConstraintData = this->mGenericConstraintData;
        v17 = _mm_shuffle_ps(v12, v12, 201);
        v18 = _mm_sub_ps(_mm_mul_ps(m_quad, v17), _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v12));
        v19 = _mm_shuffle_ps(v18, v18, 201);
        v20 = _mm_mul_ps(v19, v19);
        v21 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170));
        v22 = _mm_rsqrt_ps(v21);
        newValues.m_quad = _mm_mul_ps(
                             v19,
                             _mm_andnot_ps(
                               _mm_cmple_ps(v21, (__m128)0i64),
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
                         _mm_cmple_ps(v26, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                           _mm_mul_ps(v27, *(__m128 *)_xmm))));
        hkpGenericConstraintData::setParameters(mGenericConstraintData, mBasisIndexA, 1, &direction);
        hkpGenericConstraintData::setParameters(this->mGenericConstraintData, this->mBasisIndexA + 1, 1, &newValues);
        hkpGenericConstraintData::setParameters(this->mGenericConstraintData, this->mBasisIndexA + 2, 1, &v47);
        mHavokVehicle = this->mHavokVehicle;
        m_mainSteeringAngle = mHavokVehicle->m_mainSteeringAngle;
        v30 = *(float *)&mHavokVehicle->m_steering[3].m_memSizeAndFlags;
        if ( COERCE_FLOAT(LODWORD(v30) & _xmm) > 0.001 )
          m_mainSteeringAngle = m_mainSteeringAngle / v30;
        mLeanDesiredHi = this->mLeanDesiredHi;
        mLeanDesiredLo = this->mLeanDesiredLo;
        v33 = this->mLeanMinSpeed * this->mLeanMinSpeed;
        if ( mLeanDesiredLo >= mLeanDesiredHi )
          v34 = this->mLeanDesiredHi;
        else
          v34 = this->mLeanDesiredLo;
        if ( mLeanDesiredLo <= mLeanDesiredHi )
          v35 = this->mLeanDesiredHi;
        else
          v35 = this->mLeanDesiredLo;
        v36 = FLOAT_0_000099999997;
        if ( (float)((float)(this->mLeanMaxSpeed * this->mLeanMaxSpeed) - v33) >= 0.000099999997 )
          v36 = (float)(this->mLeanMaxSpeed * this->mLeanMaxSpeed) - v33;
        v37 = (float)((float)((float)(this->mSpeedKPH * this->mSpeedKPH) - v33)
                    * (float)((float)(mLeanDesiredHi - mLeanDesiredLo) / v36))
            + mLeanDesiredLo;
        if ( v37 <= v34 )
          v37 = v34;
        if ( v37 >= v35 )
          v37 = v35;
        LODWORD(v38) = COERCE_UNSIGNED_INT(v37 * m_mainSteeringAngle) ^ _xmm[0];
        UFG::qPidControllerCore::Record(this->mLeanPidController, v38 - this->mLeanAngle, deltaTime, 0i64);
        Output = UFG::qPidControllerCore::GetOutput(this->mLeanPidController);
        mLeanAngle = this->mLeanAngle;
        v41 = Output * (float)(deltaTime * 29.999998);
        if ( mLeanAngle >= v38 )
        {
          if ( mLeanAngle <= v38 )
            goto LABEL_31;
          v42 = mLeanAngle + v41;
          if ( v42 < v38 )
          {
LABEL_30:
            this->mLeanAngle = v38;
LABEL_31:
            hkQuaternionf::setAxisAngle(&quat, &axis, this->mLeanAngle);
            hkVector4f::setRotatedDir(&v47, &quat, &v50);
            v43 = this->mGenericConstraintData;
            v44 = this->mBasisIndexB + 1;
            v45 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(axis.m_quad, axis.m_quad, 201), v47.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v47.m_quad, v47.m_quad, 201), axis.m_quad));
            newValues.m_quad = _mm_shuffle_ps(v45, v45, 201);
            hkpGenericConstraintData::setParameters(v43, v44, 1, &newValues);
            hkpGenericConstraintData::setParameters(this->mGenericConstraintData, this->mBasisIndexB + 2, 1, &v47);
            return;
          }
        }
        else
        {
          v42 = mLeanAngle + v41;
          if ( v42 > v38 )
            goto LABEL_30;
        }
        this->mLeanAngle = v42;
        goto LABEL_31;
      }
      UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v7);
    }
    m_quad = v47.m_quad;
    v12 = direction.m_quad;
    goto LABEL_12;
  }
}

// File Line: 291
// RVA: 0x47EE20
// local variable allocation has failed, the output may be wrong!
void __fastcall UFG::PhysicsMotorBike::UpdateHighLod(
        UFG::PhysicsMotorBike *this,
        UFG::VehicleInput *input,
        double deltaTime)
{
  __int128 v5; // xmm9
  hkpVehicleAerodynamics *m_aerodynamics; // rcx
  __m128 v7; // xmm6
  char v8; // bp
  float z; // xmm0_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  UFG::VehicleInstance *mHavokVehicle; // rax
  int v13; // edx
  hkpVehicleEngine *m_engine; // rcx
  float v15; // xmm0_4
  bool v16; // cc
  hkpVehicleInstance::WheelInfo *m_data; // rcx
  UFG::RigidBodyComponent *mRigidBody; // rax
  hkpRigidBody *mBody; // rbx
  __int64 v20; // rdx
  float mForwardWeightShift; // xmm0_4
  float v22; // xmm0_4
  int v23; // edx
  unsigned int v24; // eax
  UFG::VehicleInstance *v25; // r8
  __int64 v26; // rcx
  __int64 v27; // r9
  float mRotMassScaleForCollisions; // xmm2_4
  float v29; // xmm11_4
  __int128 v30; // xmm0
  int v31; // eax
  __m128 v32; // xmm6
  __int64 v33; // r9
  UFG::RigidBodyComponent *v34; // rax
  hkpEntity *v35; // rbx
  __int64 v36; // rdx
  UFG::VehicleInstance *v37; // rcx
  float v38; // xmm0_4
  __m128 z_low; // xmm3
  __m128 x_low; // xmm5
  __m128 w_low; // xmm2
  UFG::RigidBodyComponent *v42; // rax
  float v43; // xmm10_4
  __m128 y_low; // xmm4
  hkpEntity *v45; // rbx
  __int64 v46; // rdx
  UFG::VehicleInstance *v47; // rax
  hkpVehicleDriverInputStatus *m_deviceStatus; // rcx
  hkVector4f centerOfMass; // [rsp+30h] [rbp-B8h] BYREF
  hkVector4f direction; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f v51; // [rsp+50h] [rbp-98h] BYREF
  __m128 v52; // [rsp+60h] [rbp-88h] BYREF

  v5 = *(_OWORD *)&deltaTime;
  m_aerodynamics = this->mHavokVehicle->m_aerodynamics;
  LODWORD(m_aerodynamics[3].vfptr) = 0;
  if ( input->mForwardWeightShift > 0.25 )
    *(float *)&m_aerodynamics[3].vfptr = this->mTuckDragBoost;
  v7 = (__m128)(unsigned int)FLOAT_1_0;
  centerOfMass.m_quad = (__m128)this->mDefaultCentreOfMass;
  v8 = 0;
  z = this->mBodyTransform.v0.z;
  v10 = 0.0;
  if ( z <= -1.0 )
  {
    z = FLOAT_N1_0;
  }
  else if ( z >= 1.0 )
  {
    z = *(float *)&FLOAT_1_0;
  }
  v11 = asinf(z);
  mHavokVehicle = this->mHavokVehicle;
  v13 = *((_DWORD *)input + 4);
  m_engine = mHavokVehicle->m_engine;
  if ( (v13 & 8) == 0 || (v13 & 0x100) != 0 )
  {
    this->mWheelieTorqueBoostCounter = 0.0;
    if ( (*((_BYTE *)input + 16) & 0x10) != 0 )
    {
      v8 = 1;
      v10 = (float)(this->mBrakingWheelieAngle * input->mForwardWeightShift) + v11;
      if ( mHavokVehicle )
      {
        m_data = mHavokVehicle->m_wheelsInfo.hkpVehicleInstance::m_data;
        if ( !m_data[1].m_contactBody )
        {
          if ( m_data->m_contactBody )
          {
            if ( input->mSteering <= 0.0 )
            {
              if ( input->mSteering >= 0.0 )
                v7 = 0i64;
              else
                v7 = (__m128)LODWORD(FLOAT_N1_0);
            }
            v7.m128_f32[0] = v7.m128_f32[0] * this->mBrakingWheelieYaw;
            mRigidBody = this->mRigidBody;
            direction.m_quad = _mm_unpacklo_ps(
                                 _mm_unpacklo_ps((__m128)0i64, _mm_xor_ps(v7, *(__m128 *)_xmm)),
                                 (__m128)0i64);
            hkVector4f::setRotatedDir(
              &v51,
              &mRigidBody->mBody->m_motion.m_motionState.m_sweptTransform.m_rotation1,
              &direction);
            mBody = this->mRigidBody->mBody;
            hkpEntity::activate(mBody);
            ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))mBody->m_motion.hkpEntity::vfptr[13].__first_virtual_table_function__)(
              &mBody->m_motion,
              v20,
              &v51);
            v7.m128_i32[0] = (int)FLOAT_1_0;
          }
        }
      }
    }
    if ( this->mSpeedKPH < 5.0 )
    {
      mForwardWeightShift = input->mForwardWeightShift;
      if ( mForwardWeightShift <= 0.25 )
      {
        if ( mForwardWeightShift >= -0.25 )
          goto LABEL_26;
        v22 = centerOfMass.m_quad.m128_f32[0] + -0.1;
      }
      else
      {
        v22 = centerOfMass.m_quad.m128_f32[0] + 0.1;
      }
      centerOfMass.m_quad.m128_f32[0] = v22;
    }
  }
  else
  {
    v8 = 1;
    v10 = (float)(this->mWheelieAngle * input->mForwardWeightShift) + v11;
    v15 = *(float *)&deltaTime + this->mWheelieTorqueBoostCounter;
    v16 = v15 <= this->mWheelieTorqueBoostTime;
    this->mWheelieTorqueBoostCounter = v15;
    if ( v16 )
      *(float *)(&m_engine[4].m_referenceCount + 1) = this->mWheelieTorqueBoost
                                                    + *(float *)(&m_engine[4].m_referenceCount + 1);
  }
LABEL_26:
  if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 0x10) == 0 )
  {
    v23 = 0;
    v24 = *((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7;
    if ( !v24 )
      goto LABEL_35;
    v25 = this->mHavokVehicle;
    v26 = 0i64;
    v27 = v24;
    do
    {
      if ( !v25 || v25->m_wheelsInfo.hkpVehicleInstance::m_data[v26].m_contactBody )
        ++v23;
      ++v26;
      --v27;
    }
    while ( v27 );
    if ( v23 == 1 )
      mRotMassScaleForCollisions = FLOAT_10_0;
    else
LABEL_35:
      mRotMassScaleForCollisions = this->mRotMassScaleForCollisions;
    UFG::PhysicsVehicle::SetMassScaleForCollisions(this, v7.m128_f32[0], mRotMassScaleForCollisions);
    v7.m128_i32[0] = (int)FLOAT_1_0;
  }
  if ( !v8 )
  {
    UFG::qPidControllerCore::Clear(this->mWheeliePidController);
    this->mWheelieBlend = 0.0;
    goto LABEL_48;
  }
  v30 = v5;
  v29 = FLOAT_N20000_0;
  *(float *)&v30 = *(float *)&v5 + this->mWheelieBlend;
  LODWORD(this->mWheelieBlend) = v30;
  if ( *(float *)&v30 > v7.m128_f32[0] )
    this->mWheelieBlend = 1.0;
  UFG::qPidControllerCore::Record(this->mWheeliePidController, v10, *(float *)&v5, 0i64);
  *(float *)&v30 = UFG::qPidControllerCore::GetOutput(this->mWheeliePidController);
  v31 = *((_DWORD *)input + 4);
  v32 = (__m128)v30;
  if ( (v31 & 8) != 0 && (v31 & 0x100) == 0 )
  {
    v33 = 0i64;
LABEL_45:
    ((void (__fastcall *)(UFG::VehicleInstance *, hkpRigidBody *, hkpVehicleSuspension *, __int64, hkVector4f *, hkVector4f *))this->mHavokVehicle->UFG::PhysicsWheeledVehicle::vfptr[5].__first_virtual_table_function__)(
      this->mHavokVehicle,
      this->mRigidBody->mBody,
      this->mHavokVehicle->m_suspension,
      v33,
      &direction,
      &v51);
    goto LABEL_46;
  }
  if ( (v31 & 0x10) != 0 )
  {
    v29 = FLOAT_10000_0;
    v33 = 1i64;
    goto LABEL_45;
  }
LABEL_46:
  v34 = this->mRigidBody;
  v32.m128_f32[0] = (float)(*(float *)&v30 * v29) * this->mWheelieBlend;
  v52 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v32), (__m128)0i64);
  v35 = v34->mBody;
  hkpEntity::activate(v35);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, hkVector4f *))v35->m_motion.vfptr[12].__first_virtual_table_function__)(
    &v35->m_motion,
    v36,
    &v52,
    &direction);
LABEL_48:
  hkpRigidBody::setCenterOfMassLocal(this->mRigidBody->mBody, &centerOfMass);
  v37 = this->mHavokVehicle;
  if ( v37 )
  {
    if ( v37->m_wheelsInfo.hkpVehicleInstance::m_data[1].m_contactBody )
    {
      if ( !v37->m_wheelsInfo.hkpVehicleInstance::m_data->m_contactBody )
      {
        LODWORD(v38) = LODWORD(input->mSteering) & _xmm;
        if ( v38 > 0.25 )
        {
          z_low = (__m128)LODWORD(this->mBodyTransform.v1.z);
          x_low = (__m128)LODWORD(this->mBodyTransform.v1.x);
          w_low = (__m128)LODWORD(this->mBodyTransform.v1.w);
          v42 = this->mRigidBody;
          v43 = (float)((float)(-1.0 / v38) * input->mSteering) * this->mWheelieSteerRate;
          y_low = (__m128)LODWORD(this->mBodyTransform.v1.y);
          x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] + this->mBodyTransform.v0.x) * 0.0)
                                    + (float)(v43 * this->mBodyTransform.v2.x))
                            + (float)(this->mBodyTransform.v3.x * 0.0);
          y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] + this->mBodyTransform.v0.y) * 0.0)
                                    + (float)(v43 * this->mBodyTransform.v2.y))
                            + (float)(this->mBodyTransform.v3.y * 0.0);
          z_low.m128_f32[0] = (float)((float)((float)(z_low.m128_f32[0] + this->mBodyTransform.v0.z) * 0.0)
                                    + (float)(v43 * this->mBodyTransform.v2.z))
                            + (float)(this->mBodyTransform.v3.z * 0.0);
          w_low.m128_f32[0] = (float)((float)((float)(w_low.m128_f32[0] + this->mBodyTransform.v0.w) * 0.0)
                                    + (float)(v43 * this->mBodyTransform.v2.w))
                            + (float)(this->mBodyTransform.v3.w * 0.0);
          v52 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(y_low, w_low));
          v45 = v42->mBody;
          hkpEntity::activate(v45);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *))v45->m_motion.vfptr[13].__first_virtual_table_function__)(
            &v45->m_motion,
            v46,
            &v52);
        }
      }
    }
  }
  v47 = this->mHavokVehicle;
  m_deviceStatus = v47->m_deviceStatus;
  if ( v47 && !v47->m_wheelsInfo.hkpVehicleInstance::m_data->m_contactBody || (*((_BYTE *)input + 16) & 0x10) != 0 )
    LODWORD(m_deviceStatus[1].vfptr) = 0;
  else
    *(float *)&m_deviceStatus[1].vfptr = input->mSteering;
  UFG::PhysicsMotorBike::UpdateConstraints(this, *(float *)&v5);
}

// File Line: 441
// RVA: 0x473450
void __fastcall UFG::PhysicsMotorBike::Reset(UFG::PhysicsMotorBike *this, UFG::VehicleResetOptions options)
{
  __int64 v2; // rbx
  hkpConstraintInstance *mConstraint; // rdx
  hkpVehicleWheelCollide *mWheelCollider; // rcx

  v2 = 0i64;
  mConstraint = this->mConstraint;
  this->mLeanAngle = 0.0;
  if ( mConstraint )
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, mConstraint);
  UFG::PhysicsVehicle::Reset(this, options);
  if ( (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 7) != 0 )
  {
    do
    {
      mWheelCollider = this->mWheelCollider;
      if ( mWheelCollider )
      {
        if ( (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7) == 2 )
          *((_DWORD *)&mWheelCollider[8].m_memSizeAndFlags + v2) = 1065353216;
        else
          *((_DWORD *)&mWheelCollider[7].m_alreadyUsed.m_bool + v2) = 1065353216;
      }
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (*((_DWORD *)&this->UFG::PhysicsVehicle + 151) & 7u) );
    this->mDisableConstraint = 0;
  }
  else
  {
    this->mDisableConstraint = 0;
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
void __fastcall UFG::PhysicsMotorBike::SetLevelOfDetailInternal(
        UFG::PhysicsMotorBike *this,
        UFG::PhysicsVehicle::Lod lod)
{
  UFG::PhysicsWheeledVehicle::SetLevelOfDetailInternal(this, lod);
  if ( lod > LOD_UNINITIALIZED )
  {
    if ( lod <= LOD_MEDIUM )
      goto LABEL_5;
    if ( lod == LOD_HIGH )
    {
      UFG::qPidControllerCore::Clear(this->mWheeliePidController);
      UFG::qPidControllerCore::Clear(this->mLeanPidController);
      return;
    }
    if ( lod == LOD_NIS )
LABEL_5:
      UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, this->mConstraint);
  }
}

// File Line: 510
// RVA: 0x476360
void __fastcall UFG::PhysicsMotorBike::Suspend(UFG::PhysicsMotorBike *this)
{
  hkpConstraintInstance *mConstraint; // rdx

  UFG::PhysicsWheeledVehicle::Suspend(this);
  mConstraint = this->mConstraint;
  if ( mConstraint )
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, mConstraint);
}

// File Line: 521
// RVA: 0x473C00
void __fastcall UFG::PhysicsMotorBike::ResourceUnloaded(
        UFG::PhysicsMotorBike *this,
        UFG::PhysicsResourceHandle *resource)
{
  hkpConstraintInstance *mConstraint; // rdx

  mConstraint = this->mConstraint;
  if ( mConstraint )
  {
    UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, mConstraint);
    hkReferencedObject::removeReference(this->mConstraint);
    this->mConstraint = 0i64;
  }
  this->mDesiredLod = LOD_RESOURCES_UNLOADED;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
  UFG::PhysicsVehicle::ResourceUnloaded(this, resource);
}

