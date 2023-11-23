// File Line: 75
// RVA: 0x1513B90
__int64 dynamic_initializer_for__UFG::PhysicsCar::attachment_bones__()
{
  UFG::qSymbolUC::create_from_string(UFG::PhysicsCar::attachment_bones, "M_DoorL01");
  UFG::qSymbolUC::create_from_string(&stru_142403B54, "M_DoorL02");
  UFG::qSymbolUC::create_from_string(&stru_142403B58, "M_DoorL03");
  UFG::qSymbolUC::create_from_string(&stru_142403B5C, "M_DoorR01");
  UFG::qSymbolUC::create_from_string(&stru_142403B60, "M_DoorR02");
  UFG::qSymbolUC::create_from_string(&stru_142403B64, "M_DoorR03");
  UFG::qSymbolUC::create_from_string(&stru_142403B68, "M_Hood");
  UFG::qSymbolUC::create_from_string(&stru_142403B6C, "M_Trunk");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhysicsCar::attachment_bones__);
}

// File Line: 268
// RVA: 0x44E150
void __fastcall UFG::VehicleAttachment::VehicleAttachment(UFG::VehicleAttachment *this, UFG::VehicleAttachmentID a)
{
  __int64 v2; // rsi
  UFG::AIVehicleAttachment *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::AIVehicleAttachment *v6; // rax

  v2 = a;
  this->mPrev = this;
  this->mNext = this;
  this->body.mPrev = &this->body;
  this->body.mNext = &this->body;
  v4 = 0i64;
  this->body.m_pPointer = 0i64;
  this->bulletCollider = 0i64;
  this->age = 0.0;
  *(_DWORD *)&this->boneIndex = 0xFFFF;
  this->id = a;
  v5 = UFG::qMemoryPool::Allocate(&gAIMemoryPool, 0x20ui64, "AIVehicleAttachment", 0i64, 1u);
  if ( v5 )
  {
    UFG::AIVehicleAttachment::AIVehicleAttachment((UFG::AIVehicleAttachment *)v5, this, UFG::PhysicsCar::isDoor[v2]);
    v4 = v6;
  }
  this->aiAttachment = v4;
}

// File Line: 275
// RVA: 0x4518A0
void __fastcall UFG::VehicleAttachment::~VehicleAttachment(UFG::VehicleAttachment *this)
{
  char *aiAttachment; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *p_body; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v8; // rcx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v9; // rax

  aiAttachment = (char *)this->aiAttachment;
  if ( aiAttachment )
  {
    UFG::AIVehicleAttachment::~AIVehicleAttachment(this->aiAttachment);
    UFG::qMemoryPool::Free(&gAIMemoryPool, aiAttachment);
  }
  p_body = &this->body;
  if ( this->body.m_pPointer )
  {
    mPrev = p_body->mPrev;
    mNext = this->body.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_body->mPrev = p_body;
    this->body.mNext = &this->body;
  }
  this->body.m_pPointer = 0i64;
  v6 = p_body->mPrev;
  v7 = this->body.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_body->mPrev = p_body;
  this->body.mNext = &this->body;
  v8 = this->mPrev;
  v9 = this->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 286
// RVA: 0x44A9C0
void __fastcall UFG::PhysicsCar::PhysicsCar(
        UFG::PhysicsCar *this,
        UFG::VehicleParams *param,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *velocity,
        UFG::qVector3 *wheelPositions)
{
  UFG::qReflectObject *mData; // rcx
  UFG::qReflectHandleBase v7; // [rsp+40h] [rbp-38h] BYREF

  UFG::PhysicsWheeledVehicle::PhysicsWheeledVehicle(this, param, transform, velocity, wheelPositions);
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsCar::`vftable;
  this->mAttachments.mNode.mPrev = &this->mAttachments.mNode;
  this->mAttachments.mNode.mNext = &this->mAttachments.mNode;
  this->mIsAttachmentSupported = -1;
  UFG::qReflectHandleBase::qReflectHandleBase(&v7);
  v7.mTypeUID = UFG::qStringHash64("UFG::CarPhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v7, v7.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
  mData = v7.mData;
  this->mRollStability = *(float *)&v7.mData[1].mTypeUID;
  if ( LOBYTE(mData[8].mBaseNode.mNeighbours[0]) )
    this->mIsAttachmentSupported &= ~2u;
  if ( BYTE1(mData[8].mBaseNode.mNeighbours[0]) )
    this->mIsAttachmentSupported &= ~0x10u;
  if ( BYTE2(mData[8].mBaseNode.mNeighbours[0]) )
    this->mIsAttachmentSupported &= ~4u;
  if ( BYTE3(mData[8].mBaseNode.mNeighbours[0]) )
    this->mIsAttachmentSupported &= ~0x20u;
  if ( BYTE4(mData[8].mBaseNode.mNeighbours[0]) )
    this->mIsAttachmentSupported &= ~0x80u;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v7);
}

// File Line: 302
// RVA: 0x450350
void __fastcall UFG::PhysicsCar::~PhysicsCar(UFG::PhysicsCar *this)
{
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mPrev; // rcx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mNext; // rax

  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsCar::`vftable;
  UFG::PhysicsCar::DestroyAllAttachments(this);
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0>::DeleteNodes(&this->mAttachments);
  mPrev = this->mAttachments.mNode.mPrev;
  mNext = this->mAttachments.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mAttachments.mNode.mPrev = &this->mAttachments.mNode;
  this->mAttachments.mNode.mNext = &this->mAttachments.mNode;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsWheeledVehicle::`vftable;
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents(this);
  UFG::PhysicsVehicle::~PhysicsVehicle(this);
}

// File Line: 309
// RVA: 0x474CF0
void __fastcall UFG::PhysicsCar::SetLevelOfDetailInternal(UFG::PhysicsCar *this, UFG::PhysicsVehicle::Lod lod)
{
  if ( lod == LOD_LOW )
    UFG::PhysicsCar::DestroyAllAttachments(this);
  UFG::PhysicsWheeledVehicle::SetLevelOfDetailInternal(this, lod);
}

// File Line: 322
// RVA: 0x47E190
void __fastcall UFG::PhysicsCar::UpdateAttachmentState(UFG::PhysicsCar *this, UFG::VehicleAttachment *attachment)
{
  char desiredState; // al
  UFG::RigidBody *m_pPointer; // rcx
  char v6; // al
  unsigned int v7; // edx

  desiredState = attachment->desiredState;
  if ( desiredState != attachment->currentState )
  {
    if ( !desiredState )
    {
      UFG::PhysicsCar::DestroyAttachment(this, attachment);
      attachment->currentState = attachment->desiredState;
      return;
    }
    if ( !attachment->body.m_pPointer )
      UFG::PhysicsCar::CreateRigidBodyForAttachment(this, attachment);
    m_pPointer = (UFG::RigidBody *)attachment->body.m_pPointer;
    if ( !m_pPointer )
      goto LABEL_17;
    v6 = attachment->desiredState;
    if ( v6 != 2 )
    {
      if ( v6 == 3 )
      {
        UFG::RigidBody::DeleteAllConstraints(m_pPointer);
        UFG::PhysicsCar::CreateConstraintForAttachment(this, attachment, 0);
LABEL_13:
        v7 = 256;
        if ( attachment->desiredState != 1 )
          v7 = 128;
        UFG::RigidBody::SetMotionType((UFG::RigidBody *)attachment->body.m_pPointer, v7);
        if ( attachment->desiredState == 4 )
        {
          LODWORD(attachment->body.m_pPointer[4].m_SafePointerList.mNode.mPrev) |= 0x8000u;
          hkpRigidBody::setLinearVelocity(
            (hkpRigidBody *)attachment->body.m_pPointer[2].m_pSimObject,
            &this->mRigidBody->mBody->m_motion.m_linearVelocity);
        }
LABEL_17:
        attachment->currentState = attachment->desiredState;
        return;
      }
      if ( v6 != 4 )
      {
        UFG::RigidBody::DeleteAllConstraints(m_pPointer);
        goto LABEL_13;
      }
    }
    UFG::RigidBody::DeleteAllConstraints(m_pPointer);
    UFG::PhysicsCar::CreateConstraintForAttachment(this, attachment, 1);
    goto LABEL_13;
  }
}

// File Line: 389
// RVA: 0x47F610
void __fastcall UFG::PhysicsCar::UpdateMotorTarget(UFG::PhysicsCar *this, UFG::VehicleAttachment *attachment)
{
  UFG::Constraint *ConstraintByIndex; // rax
  hkpRigidBody *mBody; // rbx
  hkpConstraintData *m_data; // rsi
  __int64 id; // rax
  __int64 v8; // rax
  __int64 v9; // rcx
  __m128 v10; // xmm2
  unsigned int v11; // xmm1_4
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm5
  hkQuaternionf nextOrientation; // [rsp+20h] [rbp-A8h] BYREF
  hkVector4f v22; // [rsp+30h] [rbp-98h] BYREF
  hkVector4f nextPosition; // [rsp+40h] [rbp-88h] BYREF
  __int128 v24[6]; // [rsp+50h] [rbp-78h] BYREF
  unsigned int v25; // [rsp+D0h] [rbp+8h]

  UFG::RigidBodyComponent::GetKeyframe(
    (UFG::RigidBodyComponent *)attachment->body.m_pPointer,
    &nextPosition,
    &nextOrientation);
  ConstraintByIndex = UFG::RigidBody::GetConstraintByIndex((UFG::RigidBody *)attachment->body.m_pPointer, 0);
  mBody = this->mRigidBody->mBody;
  m_data = ConstraintByIndex->mConstraintInstance->m_data;
  id = attachment->id;
  v24[0] = (__int128)transform.m_quad;
  v24[1] = (__int128)direction.m_quad;
  v8 = UFG::PhysicsCar::perp_axis[id];
  v24[2] = (__int128)stru_141A71280.m_quad;
  hkVector4f::setRotatedDir(&v22, &nextOrientation, (hkVector4f *)&v24[v8]);
  v9 = attachment->id;
  v10 = _mm_mul_ps(
          *(&mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad + UFG::PhysicsCar::perp_axis[v9]),
          v22.m_quad);
  *(float *)&v11 = (float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
                 + _mm_shuffle_ps(v10, v10, 170).m128_f32[0];
  v12 = _mm_mul_ps(
          *(&mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad + UFG::perp_axis2[v9]),
          v22.m_quad);
  *(float *)&v25 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
                 + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
  v13 = _mm_rcp_ps((__m128)v11);
  v14 = _mm_mul_ps(v13, (__m128)v25);
  v15 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v14), _mm_cmplt_ps(*(__m128 *)_xmm, v14));
  v16 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v14), v15), _mm_andnot_ps(v15, v14));
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v17, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v17, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v17, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v17, *(__m128 *)s3))),
          _mm_mul_ps(v16, *(__m128 *)t3));
  v19 = _mm_cmple_ps((__m128)0i64, v13);
  v20 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v16, *(__m128 *)_xmm), *(__m128 *)_xmm), v18), v15),
          _mm_andnot_ps(v15, v18));
  *(_DWORD *)(&m_data[8].m_referenceCount + 1) = (_mm_andnot_ps(
                                                    v19,
                                                    _mm_add_ps(
                                                      _mm_or_ps(
                                                        _mm_and_ps(*(__m128 *)_xmm, (__m128)v25),
                                                        *(__m128 *)_xmm),
                                                      v20)).m128_u32[0] | v20.m128_i32[0] & v19.m128_i32[0]) ^ _xmm[0];
}

// File Line: 424
// RVA: 0x47F850
void __fastcall UFG::PhysicsCar::UpdateMotorTargets(UFG::PhysicsCar *this)
{
  UFG::VehicleAttachment *mNext; // rdx
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *p_mAttachments; // rsi
  UFG::VehicleAttachment *v4; // rbx

  mNext = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  p_mAttachments = &this->mAttachments;
  if ( mNext != (UFG::VehicleAttachment *)&this->mAttachments )
  {
    do
    {
      v4 = (UFG::VehicleAttachment *)mNext->mNext;
      if ( mNext->currentState == 4 && this->mCurrentLod != LOD_LOW )
      {
        if ( mNext->body.m_pPointer )
          UFG::PhysicsCar::UpdateMotorTarget(this, mNext);
      }
      mNext = v4;
    }
    while ( v4 != (UFG::VehicleAttachment *)p_mAttachments );
  }
}

// File Line: 444
// RVA: 0x480210
void __fastcall UFG::PhysicsCar::UpdateTransforms(UFG::PhysicsCar *this, UFG::qMatrix44 *rootTransform)
{
  UFG::VehicleAttachment *mNext; // rbx
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *p_mAttachments; // rbp
  UFG::VehicleAttachment *v6; // rdi
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mPrev; // rcx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v8; // rax

  mNext = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  p_mAttachments = &this->mAttachments;
  if ( mNext != (UFG::VehicleAttachment *)&this->mAttachments )
  {
    do
    {
      v6 = (UFG::VehicleAttachment *)mNext->mNext;
      if ( this->mCurrentLod != LOD_LOW )
        UFG::PhysicsCar::UpdateAttachmentState(this, mNext);
      if ( !mNext->currentState )
      {
        mPrev = mNext->mPrev;
        v8 = mNext->mNext;
        mPrev->mNext = v8;
        v8->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        UFG::VehicleAttachment::~VehicleAttachment(mNext);
        UFG::qMemoryPool::Free(&gPhysicsMemoryPool, (char *)mNext);
      }
      mNext = v6;
    }
    while ( v6 != (UFG::VehicleAttachment *)p_mAttachments );
  }
  UFG::PhysicsVehicle::UpdateTransforms(this, rootTransform);
}

// File Line: 471
// RVA: 0x47A600
void __fastcall UFG::PhysicsCar::Update(
        UFG::PhysicsCar *this,
        UFG::qMatrix44 *targetTransform,
        UFG::VehicleInput *driverInput,
        float deltaTime)
{
  float v7; // xmm7_4
  UFG::VehicleAttachment *mNext; // rbx
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *p_mAttachments; // r14
  hkpReorientAction *v10; // rbp
  UFG::VehicleAttachment *v11; // rsi
  float v12; // xmm0_4
  __int64 id; // rdx
  UFG::RigidBody *m_pPointer; // rcx
  UFG::Constraint *ConstraintByIndex; // rax
  hkpConstraintInstance *mConstraintInstance; // rax
  UFG::RigidBody *v17; // rcx
  UFG::RigidBody *v18; // rcx
  double Mass; // xmm0_8
  hkpRigidBody *bulletCollider; // rcx
  UFG::SimComponent *v21; // rax
  UFG::AIVehicleAttachment *aiAttachment; // rcx
  UFG::VehicleInstance *mHavokVehicle; // rbx
  hkpVehicleAerodynamics *m_aerodynamics; // rbx
  float v25; // xmm0_4
  UFG::BasePhysicsSystem *v26; // rbx
  UFG::VehicleInstance *v27; // rcx
  hkpVehicleInstance::WheelInfo *m_data; // rdx
  hkpVehicleInstance::WheelInfo *v29; // rdx
  __int64 v30; // r8
  char v31; // dl
  char v32; // cl
  _QWORD **Value; // rax
  UFG::OneShot *v34; // rax
  hkJobType v35; // edx
  hkpReorientAction *v36; // rax
  hkpReorientAction *v37; // rdx
  hkpReorientAction *mReorientActionRoll; // rdx
  hkpReorientAction *v39; // rcx
  hkVector4f upAxis; // [rsp+40h] [rbp-E8h] BYREF
  hkVector4f rotationAxis; // [rsp+50h] [rbp-D8h] BYREF
  UFG::qMatrix44 mat; // [rsp+60h] [rbp-C8h] BYREF
  UFG::OneShotHandle pHandle; // [rsp+130h] [rbp+8h] BYREF

  v7 = 0.0;
  mNext = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  p_mAttachments = &this->mAttachments;
  v10 = 0i64;
  if ( mNext != (UFG::VehicleAttachment *)&this->mAttachments )
  {
    do
    {
      v11 = (UFG::VehicleAttachment *)mNext->mNext;
      v12 = deltaTime + mNext->age;
      mNext->age = v12;
      if ( this->mCurrentLod == LOD_LOW )
      {
        aiAttachment = mNext->aiAttachment;
        if ( aiAttachment )
          goto LABEL_27;
      }
      else
      {
        if ( mNext->desiredState != 4 )
        {
          id = mNext->id;
          if ( v12 > UFG::PhysicsCar::min_time_before_closing[id] )
          {
            m_pPointer = (UFG::RigidBody *)mNext->body.m_pPointer;
            if ( m_pPointer )
            {
              if ( (unsigned int)id <= 5 )
              {
                ConstraintByIndex = UFG::RigidBody::GetConstraintByIndex(m_pPointer, 0);
                if ( ConstraintByIndex )
                {
                  mConstraintInstance = ConstraintByIndex->mConstraintInstance;
                  if ( mConstraintInstance->m_owner )
                  {
                    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*((float *)mConstraintInstance->m_internal->m_runtime + 9) * -1.0) & _xmm) < 0.050000001 )
                    {
                      mNext->desiredState = 0;
                      v17 = (UFG::RigidBody *)mNext->body.m_pPointer;
                      if ( v17 )
                      {
                        UFG::RigidBody::GetTransform(v17, &mat);
                        pHandle.m_pOneShot = 0i64;
                        UFG::OneShotPool::GetOneShotHandle(&pHandle, &mat);
                        if ( UFG::OneShotHandle::IsValid(&pHandle) )
                        {
                          if ( (_S10_7 & 1) == 0 )
                          {
                            _S10_7 |= 1u;
                            UFG::qWiseSymbol::create_from_string(&soundid, "Play_car_door_close01");
                            atexit(UFG::PhysicsCar::Update_::_20_::_dynamic_atexit_destructor_for__soundid__);
                          }
                          UFG::OneShot::Play(pHandle.m_pOneShot, soundid.mUID);
                        }
                        UFG::OneShotHandle::Release(&pHandle);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v18 = (UFG::RigidBody *)mNext->body.m_pPointer;
        if ( v18 )
        {
          Mass = UFG::RigidBody::GetMass(v18);
          v7 = v7 + *(float *)&Mass;
          bulletCollider = mNext->bulletCollider;
          if ( bulletCollider )
            hkpRigidBody::setTransform(
              bulletCollider,
              (hkTransformf *)&mNext->body.m_pPointer[2].m_pSimObject[2].m_UnboundComponentHandles);
          if ( mNext->aiAttachment )
          {
            UFG::RigidBody::GetTransform((UFG::RigidBody *)mNext->body.m_pPointer, &mat);
            UFG::AIVehicleAttachment::Update(mNext->aiAttachment, &mat, deltaTime);
          }
        }
        v21 = mNext->body.m_pPointer;
        if ( v21 )
          LODWORD(v21[4].m_SafePointerList.mNode.mPrev) |= 0x800u;
        aiAttachment = mNext->aiAttachment;
        if ( !aiAttachment )
          goto LABEL_28;
        if ( !mNext->desiredState )
        {
LABEL_27:
          UFG::AIVehicleAttachment::Disable(aiAttachment);
          goto LABEL_28;
        }
        UFG::AIVehicleAttachment::Enable(aiAttachment);
      }
LABEL_28:
      mNext = v11;
    }
    while ( v11 != (UFG::VehicleAttachment *)p_mAttachments );
  }
  mHavokVehicle = this->mHavokVehicle;
  if ( mHavokVehicle )
  {
    m_aerodynamics = mHavokVehicle->m_aerodynamics;
    v25 = hkpMotion::getMass(&this->mRigidBody->mBody->m_motion);
    *((float *)&m_aerodynamics[3].vfptr + 1) = v25 / (float)(v25 + v7);
  }
  UFG::PhysicsWheeledVehicle::Update(this, targetTransform, driverInput, deltaTime);
  v26 = UFG::BasePhysicsSystem::mInstance;
  if ( this->mCurrentLod != LOD_HIGH
    || (v27 = this->mHavokVehicle) == 0i64
    || ((m_data = v27->m_wheelsInfo.hkpVehicleInstance::m_data, m_data->m_contactBody) || m_data[1].m_contactBody)
    && ((v29 = v27->m_wheelsInfo.hkpVehicleInstance::m_data, v29[2].m_contactBody) || v29[3].m_contactBody)
    || this->mSpeedKPH <= 10.0 )
  {
    mReorientActionRoll = this->mReorientActionRoll;
    if ( mReorientActionRoll )
    {
      UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, mReorientActionRoll);
      v39 = this->mReorientActionRoll;
      if ( v39 )
        v39->vfptr->__vecDelDtor(v39, 1u);
      this->mReorientActionRoll = 0i64;
    }
  }
  else
  {
    if ( !this->mReorientActionRoll && this->mRollStability > 0.0 )
    {
      rotationAxis.m_quad = (__m128)_xmm;
      upAxis.m_quad = _xmm;
      v30 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v31 = ++*(_BYTE *)(v30 + 80);
      *(_DWORD *)(v30 + 4i64 * v31) = 3;
      *(_QWORD *)(v30 + 8i64 * v31 + 16) = "hkpReorientAction";
      *(_QWORD *)(v30 + 8i64 * v31 + 48) = 0i64;
      v32 = *(_BYTE *)(v30 + 81);
      if ( v31 > v32 )
        v32 = v31;
      *(_BYTE *)(v30 + 81) = v32;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v34 = (UFG::OneShot *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
      pHandle.m_pOneShot = v34;
      if ( v34 )
      {
        hkpReorientAction::hkpReorientAction(
          (hkpReorientAction *)v34,
          this->mRigidBody->mBody,
          &rotationAxis,
          &upAxis,
          this->mRollStability,
          0.1);
        v10 = v36;
      }
      this->mReorientActionRoll = v10;
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v35);
    }
    v37 = this->mReorientActionRoll;
    if ( v37 )
    {
      if ( !v37->m_world )
        UFG::BasePhysicsSystem::AddAction(v26, v37);
    }
  }
}

// File Line: 616
// RVA: 0x473420
void __fastcall UFG::PhysicsCar::Reset(UFG::PhysicsCar *this, UFG::VehicleResetOptions options)
{
  UFG::PhysicsCar::DestroyAllAttachments(this);
  UFG::PhysicsVehicle::Reset(this, options);
}

// File Line: 624
// RVA: 0x476740
void __fastcall UFG::PhysicsCar::Teleport(UFG::PhysicsCar *this, UFG::qMatrix44 *mat)
{
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  UFG::PhysicsCar::DestroyAllAttachments(this);
  v4 = mat->v1;
  v5 = mat->v2;
  v6 = mat->v3;
  this->mLastGoodPosition.v0 = mat->v0;
  this->mLastGoodPosition.v1 = v4;
  this->mLastGoodPosition.v2 = v5;
  this->mLastGoodPosition.v3 = v6;
  ((void (__fastcall *)(UFG::PhysicsCar *, _QWORD))this->vfptr[1].DebugDraw)(this, 0i64);
}

// File Line: 632
// RVA: 0x476340
void __fastcall UFG::PhysicsCar::Suspend(UFG::PhysicsCar *this)
{
  UFG::PhysicsCar::DestroyAllAttachments(this);
  UFG::PhysicsWheeledVehicle::Suspend(this);
}

// File Line: 640
// RVA: 0x473E90
// attributes: thunk
void __fastcall UFG::PhysicsCar::Restore(UFG::PhysicsCar *this)
{
  UFG::PhysicsWheeledVehicle::Restore(this);
}

// File Line: 647
// RVA: 0x4705D0
void __fastcall UFG::PhysicsCar::ProcessCollisonEvent(UFG::PhysicsCar *this, UFG::CollisionEvent *ev)
{
  int v2; // esi
  bool *v3; // r13
  int v4; // r12d
  int v6; // r14d
  bool *v7; // r10
  int v8; // r8d
  int v9; // r9d
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mNext; // rax
  UFG::SimComponent *m_pPointer; // rbx
  UFG::SimObjectVehicle *v12; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbp
  UFG::SimComponent *v15; // rax
  __int16 v16; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 v18; // cx
  UFG::CharacterAnimationComponent *v19; // r15
  UFG::CarPhysicsMoverComponent *ComponentOfType; // rax
  DamageRig *m_pSimObject; // rbp
  __int64 v22; // rbx
  float v23; // xmm0_4
  int BoneIndexForAttachment; // eax
  Creature *mCreature; // rcx
  hkQsTransformf *TranslationMS; // rax
  float v27; // xmm2_4
  float y; // xmm1_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-58h] BYREF

  v2 = 0;
  v3 = UFG::PhysicsCar::isDoor;
  v4 = 1;
  v6 = 0;
  v7 = UFG::PhysicsCar::isDoor;
  v8 = 0;
  v9 = 1;
  do
  {
    if ( (this->mIsAttachmentSupported & v9) != 0 && *v7 )
    {
      mNext = this->mAttachments.mNode.mNext;
      if ( mNext != (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&this->mAttachments )
      {
        while ( LODWORD(mNext[4].mPrev) != v8 )
        {
          mNext = mNext->mNext;
          if ( mNext == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&this->mAttachments )
            goto LABEL_10;
        }
        if ( mNext[2].mPrev )
          ++v6;
      }
    }
LABEL_10:
    v9 = __ROL4__(v9, 1);
    ++v8;
    ++v7;
  }
  while ( v8 < 8 );
  if ( this->mCurrentLod != LOD_LOW )
  {
    m_pPointer = this->mUserData.simComponent.m_pPointer;
    v12 = m_pPointer ? (UFG::SimObjectVehicle *)m_pPointer->m_pSimObject : 0i64;
    if ( v12 )
    {
      m_Flags = v12->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        goto LABEL_22;
      if ( m_Flags < 0 )
      {
        m_pComponent = v12->m_Components.p[32].m_pComponent;
LABEL_25:
        v16 = v12->m_Flags;
        if ( (v16 & 0x4000) != 0 || v16 < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12);
        }
        else if ( (v16 & 0x2000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v12);
        }
        else if ( (v16 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v12,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                    v12,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
        }
        v18 = v12->m_Flags;
        v19 = ComponentOfTypeHK;
        if ( (v18 & 0x4000) != 0 )
        {
          ComponentOfType = 0i64;
        }
        else if ( v18 >= 0 )
        {
          if ( (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
            ComponentOfType = (UFG::CarPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v12,
                                                                 UFG::CarPhysicsMoverComponent::_TypeUID);
          else
            ComponentOfType = (UFG::CarPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                                 v12,
                                                                 UFG::CarPhysicsMoverComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(v12);
        }
        if ( m_pComponent )
        {
          if ( v19 )
          {
            if ( ComponentOfType )
            {
              if ( ComponentOfType->mSupportsAttachments )
              {
                m_pSimObject = (DamageRig *)m_pComponent[28].m_pSimObject;
                if ( m_pSimObject )
                {
                  if ( m_pSimObject->mAggregateDamage > 0.0 )
                  {
                    v22 = 0i64;
                    do
                    {
                      if ( (v4 & this->mIsAttachmentSupported) != 0
                        && !UFG::PhysicsCar::IsAttachmentActive(this, (UFG::VehicleAttachmentID)v2)
                        && (!*v3 || v6 < 1) )
                      {
                        v23 = UFG::PhysicsCar::collision_threshold_before_opening[v22];
                        if ( v23 == 0.0 || v23 < ev->estimatedImpulseMagnitude )
                        {
                          BoneIndexForAttachment = UFG::PhysicsCar::GetBoneIndexForAttachment(
                                                     this,
                                                     v19,
                                                     (UFG::VehicleAttachmentID)v2);
                          if ( BoneIndexForAttachment != -1 )
                          {
                            mCreature = v19->mCreature;
                            if ( mCreature )
                            {
                              TranslationMS = Creature::GetTranslationMS(mCreature, BoneIndexForAttachment);
                              v27 = TranslationMS->m_translation.m_quad.m128_f32[2];
                              y = TranslationMS->m_translation.m_quad.m128_f32[1];
                              LODWORD(pos.x) = TranslationMS->m_translation.m_quad.m128_i32[0];
                              pos.z = v27;
                            }
                            else
                            {
                              y = UFG::qVector3::msZero.y;
                              pos.x = UFG::qVector3::msZero.x;
                              pos.z = UFG::qVector3::msZero.z;
                            }
                            pos.y = y;
                            if ( DamageRig::GetDamageAtPosition(m_pSimObject, &pos) >= UFG::PhysicsCar::damage_threshold_before_opening[v22]
                              && UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < UFG::PhysicsCar::probability_of_opening[v22] )
                            {
                              UFG::PhysicsCar::SetDesiredAttachmentState(
                                this,
                                (UFG::VehicleAttachmentID)v2,
                                ATT_SIMULATED);
                              if ( *v3 )
                                ++v6;
                            }
                          }
                        }
                      }
                      v4 = __ROL4__(v4, 1);
                      ++v2;
                      ++v22;
                      ++v3;
                    }
                    while ( v2 < 8 );
                  }
                }
              }
            }
          }
        }
        return;
      }
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_22:
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::VehicleEffectsComponent::_TypeUID);
      else
        v15 = UFG::SimObject::GetComponentOfType(v12, UFG::VehicleEffectsComponent::_TypeUID);
      m_pComponent = v15;
      goto LABEL_25;
    }
  }
}

// File Line: 718
// RVA: 0x474AB0
void __fastcall UFG::PhysicsCar::SetDesiredAttachmentState(
        UFG::PhysicsCar *this,
        unsigned __int32 id,
        UFG::VehicleAttachmentState state)
{
  char v3; // si
  unsigned int mIsAttachmentSupported; // eax
  char v7; // r9
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mNext; // rax
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *p_mAttachments; // rdi
  UFG::allocator::free_link *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  __int16 BoneID; // ax
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mPrev; // rax

  v3 = state;
  mIsAttachmentSupported = this->mIsAttachmentSupported;
  if ( _bittest((const int *)&mIsAttachmentSupported, id) )
  {
    v7 = 0;
    mNext = this->mAttachments.mNode.mNext;
    p_mAttachments = &this->mAttachments;
    if ( mNext == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&this->mAttachments )
    {
LABEL_8:
      if ( state )
      {
        v10 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x48ui64, "VehicleAttachment", 0i64, 1u);
        if ( v10 )
        {
          UFG::VehicleAttachment::VehicleAttachment((UFG::VehicleAttachment *)v10, (UFG::VehicleAttachmentID)id);
          v12 = v11;
        }
        else
        {
          v12 = 0i64;
        }
        *(_BYTE *)(v12 + 63) = v3;
        m_pPointer = (UFG::SimObjectCVBase *)this->mParams->mSimObject.m_pPointer;
        if ( m_pPointer )
        {
          m_Flags = m_pPointer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
          }
          else if ( (m_Flags & 0x2000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      m_pPointer,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                      m_pPointer,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
          }
          if ( ComponentOfTypeHK )
          {
            mCreature = ComponentOfTypeHK->mCreature;
            if ( mCreature )
            {
              if ( mCreature->mPose.mRigHandle.mData )
                BoneID = Skeleton::GetBoneID(
                           mCreature->mPose.mRigHandle.mUFGSkeleton,
                           UFG::PhysicsCar::attachment_bones[*(int *)(v12 + 64)].mUID);
              else
                BoneID = -1;
              *(_WORD *)(v12 + 60) = BoneID;
            }
          }
        }
        mPrev = p_mAttachments->mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)v12;
        *(_QWORD *)v12 = mPrev;
        *(_QWORD *)(v12 + 8) = p_mAttachments;
        p_mAttachments->mNode.mPrev = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)v12;
      }
    }
    else
    {
      while ( !v7 )
      {
        if ( LODWORD(mNext[4].mPrev) == id )
        {
          HIBYTE(mNext[3].mNext) = state;
          v7 = 1;
        }
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)p_mAttachments )
        {
          if ( v7 )
            return;
          goto LABEL_8;
        }
      }
    }
  }
}     {
          if ( v7 )
            return;
          g

// File Line: 761
// RVA: 0x4616E0
void __fastcall UFG::PhysicsCar::DestroyAllAttachments(UFG::PhysicsCar *this)
{
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *p_mAttachments; // rdi
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mNext; // rbx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mPrev; // rcx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v5; // rax
  UFG::RigidBody *v6; // rcx
  hkpRigidBody *v7; // rdx
  UFG::AIVehicleAttachment *v8; // rcx

  p_mAttachments = &this->mAttachments;
  if ( (UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *)this->mAttachments.mNode.mNext != &this->mAttachments )
  {
    do
    {
      mNext = this->mAttachments.mNode.mNext;
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v6 = (UFG::RigidBody *)mNext[2].mPrev;
      HIWORD(mNext[3].mNext) = 0;
      if ( v6 )
      {
        UFG::RigidBody::DeleteAllConstraints(v6);
        UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)mNext[2].mPrev);
        v7 = (hkpRigidBody *)mNext[2].mNext;
        if ( v7 )
        {
          UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v7, 0);
          hkReferencedObject::removeReference((hkReferencedObject *)mNext[2].mNext);
          mNext[2].mNext = 0i64;
        }
      }
      v8 = (UFG::AIVehicleAttachment *)mNext[3].mPrev;
      if ( v8 )
        UFG::AIVehicleAttachment::Disable(v8);
      UFG::VehicleAttachment::~VehicleAttachment((UFG::VehicleAttachment *)mNext);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, (char *)mNext);
    }
    while ( (UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *)p_mAttachments->mNode.mNext != p_mAttachments );
  }
}

// File Line: 773
// RVA: 0x4660F0
float __fastcall UFG::PhysicsCar::GetAttachmentAngle(UFG::PhysicsCar *this, UFG::VehicleAttachmentID id)
{
  UFG::VehicleAttachment *mNext; // rbx
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *p_mAttachments; // rdi
  __int64 v4; // rsi
  UFG::RigidBody *m_pPointer; // rcx
  UFG::Constraint *ConstraintByIndex; // rax
  hkpConstraintInstance *mConstraintInstance; // rcx
  float result; // xmm0_4

  mNext = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  p_mAttachments = &this->mAttachments;
  v4 = id;
  if ( mNext == (UFG::VehicleAttachment *)&this->mAttachments )
    return FLOAT_N1_0;
  while ( 1 )
  {
    if ( mNext->id == (_DWORD)v4 )
    {
      m_pPointer = (UFG::RigidBody *)mNext->body.m_pPointer;
      if ( m_pPointer )
      {
        ConstraintByIndex = UFG::RigidBody::GetConstraintByIndex(m_pPointer, 0);
        if ( ConstraintByIndex )
        {
          mConstraintInstance = ConstraintByIndex->mConstraintInstance;
          if ( mConstraintInstance->m_owner )
            break;
        }
      }
    }
    mNext = (UFG::VehicleAttachment *)mNext->mNext;
    if ( mNext == (UFG::VehicleAttachment *)p_mAttachments )
      return FLOAT_N1_0;
  }
  result = (float)((float)(*((float *)mConstraintInstance->m_internal->m_runtime + 9) * -1.0)
                 - UFG::PhysicsCar::min_angle[v4])
         / (float)(UFG::PhysicsCar::max_angle[v4] - UFG::PhysicsCar::min_angle[v4]);
  if ( UFG::PhysicsCar::flip_angle[v4] )
    return 1.0 - result;
  return result;
}

// File Line: 845
// RVA: 0x46AA80
bool __fastcall UFG::PhysicsCar::IsAttachmentActive(UFG::PhysicsCar *this, UFG::VehicleAttachmentID id)
{
  UFG::VehicleAttachment *mNext; // rax
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *p_mAttachments; // rcx

  mNext = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  p_mAttachments = &this->mAttachments;
  if ( mNext == (UFG::VehicleAttachment *)p_mAttachments )
    return 0;
  while ( mNext->id != id )
  {
    mNext = (UFG::VehicleAttachment *)mNext->mNext;
    if ( mNext == (UFG::VehicleAttachment *)p_mAttachments )
      return 0;
  }
  return mNext->body.m_pPointer != 0i64;
}

// File Line: 871
// RVA: 0x45F8C0
void __fastcall UFG::PhysicsCar::CreateRigidBodyForAttachment(
        UFG::PhysicsCar *this,
        UFG::VehicleAttachment *attachment)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v6; // rax
  UFG::CharacterAnimationComponent *v7; // rsi
  int v8; // edx
  unsigned int v9; // r15d
  UFG::CollisionMeshData *CollisionModel; // r13
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  hkaPose *mHavokPose; // r8
  __int64 boneIndex; // rdx
  hkQsTransformf *v14; // rax
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm9
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm6
  __m128 v25; // xmm8
  __m128 v26; // xmm6
  UFG::allocator::free_link *v27; // rax
  hkpRigidBody *v28; // rsi
  UFG::CollisionInstanceData *v29; // rax
  UFG::CollisionInstanceData *v30; // rbx
  UFG::allocator::free_link *v31; // rax
  UFG::RigidBody *v32; // rax
  UFG::RigidBody *v33; // rbx
  __int64 v34; // rdx
  unsigned int mStringHashUpper32; // eax
  UFG::qBaseTreeRB *v36; // rbx
  UFG::SimComponent *v37; // rdx
  __int64 v38; // r8
  char v39; // dl
  char v40; // cl
  _QWORD **Value; // rax
  hkpRigidBody *v42; // rax
  hkJobType v43; // edx
  hkpRigidBody *v44; // rax
  unsigned int v45; // ebx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v46; // rcx
  const char *TypeName; // rax
  UFG::SimObjectModifier v48; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4f direction; // [rsp+50h] [rbp-88h] BYREF
  char *str[2]; // [rsp+60h] [rbp-78h] BYREF
  unsigned int guid[2]; // [rsp+70h] [rbp-68h]
  UFG::qString v52; // [rsp+78h] [rbp-60h] BYREF
  hkTransformf transform; // [rsp+A8h] [rbp-30h] BYREF
  __m128 m_quad; // [rsp+E8h] [rbp+10h]
  hkQuaternionf quat; // [rsp+F8h] [rbp+20h] BYREF
  hkVector4f v56; // [rsp+108h] [rbp+30h]
  hkQsTransformf v57; // [rsp+118h] [rbp+40h] BYREF
  hkpRigidBodyCinfo info; // [rsp+148h] [rbp+70h] BYREF
  void *v59; // [rsp+298h] [rbp+1C0h]

  *(_QWORD *)guid = -2i64;
  m_pPointer = (UFG::SimObjectCVBase *)this->mParams->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else
    {
      v6 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  m_pPointer,
                                                  UFG::CharacterAnimationComponent::_TypeUID)
                                              : UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::CharacterAnimationComponent::_TypeUID));
    }
    v7 = v6;
    if ( v6 )
    {
      if ( v6->mCreature && attachment->boneIndex != -1 )
      {
        UFG::qString::qString(
          &v52,
          UFG::PhysicsCar::attachment_geo_format[attachment->id],
          this->mParams->modelName.mData);
        v9 = UFG::qStringHashUpper32(str[1], guid[1] | v8);
        guid[1] = v9;
        CollisionModel = (UFG::CollisionMeshData *)UFG::BasePhysicsSystem::GetCollisionModel(
                                                     UFG::BasePhysicsSystem::mInstance,
                                                     v9);
        if ( CollisionModel )
        {
          m_pTransformNodeComponent = this->mParams->mSimObject.m_pPointer->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          hkTransformf::set4x4ColumnMajor(&transform, &m_pTransformNodeComponent->mWorldTransform.v0.x);
          hkQsTransformf::setFromTransformNoScale(&v57, &transform);
          mHavokPose = v7->mCreature->mPose.mHavokPose;
          boneIndex = attachment->boneIndex;
          if ( (mHavokPose->m_boneFlags.m_data[boneIndex] & 2) != 0 )
            v14 = hkaPose::calculateBoneModelSpace(v7->mCreature->mPose.mHavokPose, boneIndex);
          else
            v14 = &mHavokPose->m_modelPose.m_data[boneIndex];
          m_quad = v14->m_translation.m_quad;
          quat.m_vec.m_quad = (__m128)v14->m_rotation;
          v56.m_quad = (__m128)v14->m_scale;
          direction.m_quad = m_quad;
          hkVector4f::setRotatedDir((hkVector4f *)str, &quat, &direction);
          v15 = _mm_sub_ps(direction.m_quad, *(__m128 *)str);
          v16 = _mm_shuffle_ps(v57.m_rotation.m_vec.m_quad, v57.m_rotation.m_vec.m_quad, 255);
          v17 = _mm_mul_ps(v57.m_rotation.m_vec.m_quad, v15);
          v18 = _mm_shuffle_ps(v57.m_rotation.m_vec.m_quad, v57.m_rotation.m_vec.m_quad, 201);
          v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v57.m_rotation.m_vec.m_quad), _mm_mul_ps(v15, v18));
          v20 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v15, _mm_sub_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711B0)),
                    _mm_mul_ps(
                      v57.m_rotation.m_vec.m_quad,
                      _mm_add_ps(
                        _mm_shuffle_ps(v17, v17, 170),
                        _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0))))),
                  _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v16));
          v21 = _mm_add_ps(v57.m_translation.m_quad, _mm_add_ps(v20, v20));
          v22 = _mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 255);
          v23 = _mm_sub_ps(
                  _mm_mul_ps(v57.m_rotation.m_vec.m_quad, _mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 201)),
                  _mm_mul_ps(quat.m_vec.m_quad, v18));
          v24 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(quat.m_vec.m_quad, v16)),
                  _mm_mul_ps(v57.m_rotation.m_vec.m_quad, v22));
          v25 = _mm_mul_ps(v57.m_rotation.m_vec.m_quad, quat.m_vec.m_quad);
          v26 = _mm_shuffle_ps(
                  v24,
                  _mm_unpackhi_ps(
                    v24,
                    _mm_sub_ps(
                      _mm_mul_ps(v22, v16),
                      _mm_add_ps(
                        _mm_shuffle_ps(v25, v25, 170),
                        _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0))))),
                  196);
          v27 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
          v59 = v27;
          v28 = 0i64;
          if ( v27 )
          {
            UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v27);
            v30 = v29;
          }
          else
          {
            v30 = 0i64;
          }
          v30->mCollisionModelGuid = v9;
          v30->mInstanceGuid = CollisionModel->mName.mUID;
          v30->mSimObjectName.mUID = CollisionModel->mName.mUID;
          v30->mFlags = 0;
          v30->mPosition.m_quad = v21;
          v30->mOrientation.m_vec.m_quad = v26;
          v31 = UFG::RigidBodyComponent::operator new(0x1D8ui64);
          v59 = v31;
          if ( v31 )
          {
            UFG::RigidBodyComponent::RigidBodyComponent(
              (UFG::RigidBodyComponent *)v31,
              CollisionModel,
              v30,
              0x3000u,
              attachment->boneIndex);
            v33 = v32;
          }
          else
          {
            v33 = 0i64;
          }
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&attachment->body,
            v33);
          LOBYTE(v34) = 1;
          v33->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v33, v34);
          UFG::RigidBody::SetCollisionLayer(
            v33,
            UFG::PhysicsCar::collisionLayer[attachment->id],
            (unsigned __int16)this->mSystemId,
            1,
            1);
          UFG::SimObjectModifier::SimObjectModifier(&v48, this->mParams->mSimObject.m_pPointer, 1);
          UFG::SimObjectModifier::AttachComponent(&v48, v33, 0xFFFFFFFFi64);
          UFG::SimObjectModifier::Close(&v48);
          UFG::SimObjectModifier::~SimObjectModifier(&v48);
          UFG::qString::qString(
            &v52,
            UFG::PhysicsCar::bullet_geo_format[attachment->id],
            this->mParams->modelName.mData);
          mStringHashUpper32 = v52.mStringHashUpper32;
          if ( v52.mStringHashUpper32 == -1 )
          {
            mStringHashUpper32 = UFG::qStringHashUpper32(v52.mData, -1);
            v52.mStringHashUpper32 = mStringHashUpper32;
          }
          v36 = UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, mStringHashUpper32);
          if ( v36 )
          {
            hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
            info.m_collisionFilterInfo = 27;
            info.m_shape = (hkpShape *)v36[2].mNULL.mChild[1];
            v37 = attachment->body.m_pPointer;
            info.m_position = *(hkVector4f *)&v37[2].m_pSimObject[3].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
            hkQuaternionf::set((hkQuaternionf *)&v48, (hkRotationf *)&v37[2].m_pSimObject[2].m_UnboundComponentHandles);
            info.m_rotation = *(hkQuaternionf *)&v48.mbOpen;
            info.m_motionType.m_storage = 5;
            v38 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
            v39 = ++*(_BYTE *)(v38 + 80);
            *(_DWORD *)(v38 + 4i64 * v39) = 0;
            *(_QWORD *)(v38 + 8i64 * v39 + 16) = "hkpRigidBody";
            *(_QWORD *)(v38 + 8i64 * v39 + 48) = 0i64;
            v40 = *(_BYTE *)(v38 + 81);
            if ( v39 > v40 )
              v40 = v39;
            *(_BYTE *)(v38 + 81) = v40;
            Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v42 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 720i64);
            v59 = v42;
            if ( v42 )
            {
              hkpRigidBody::hkpRigidBody(v42, &info);
              v28 = v44;
            }
            attachment->bulletCollider = v28;
            HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v43);
            v45 = UFG::qStringHashUpper32("BulletMopp", -1);
            UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&transform);
            TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v46);
            transform.m_rotation.m_col1.m_quad.m128_u64[0] = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
            UFG::PhysicsPropertyManager::GetObjectProperties(
              (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&transform,
              v45,
              0);
            UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
              *(hkSimplePropertyValue *)(transform.m_rotation.m_col2.m_quad.m128_u64[0] + 8),
              attachment->bulletCollider);
            attachment->bulletCollider->m_userData = (unsigned __int64)&this->mUserData;
            UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, attachment->bulletCollider, 1);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&transform);
          }
          UFG::qString::~qString(&v52);
        }
        UFG::qString::~qString(&v52);
      }
    }
  }
}        }
        UFG::qString::~qString(&v52);
      }
    }
  }
}

// File Line: 963
// RVA: 0x454F20
hkpConstraintInstance *__fastcall UFG::PhysicsCar::AddMotorConstraint(
        UFG::PhysicsCar *this,
        hkpConstraintInstance *constraint,
        bool followingStrength)
{
  __int64 v5; // rbx
  char v6; // r9
  char v7; // cl
  _QWORD **Value; // rax
  hkpPositionConstraintMotor *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdi
  char v12; // al
  hkpConstraintInstance *v13; // rbx

  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v6) = 3;
  *(_QWORD *)(v5 + 8i64 * v6 + 16) = "hkpPositionConstraintMotor";
  *(_QWORD *)(v5 + 8i64 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v5 + 81);
  if ( v6 > v7 )
    v7 = v6;
  *(_BYTE *)(v5 + 81) = v7;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpPositionConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                       Value[11],
                                       48i64);
  if ( v9 )
  {
    hkpPositionConstraintMotor::hkpPositionConstraintMotor(v9, 0.0);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = *(_BYTE *)(v5 + 80);
  if ( v12 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v12 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  if ( followingStrength )
  {
    *(_DWORD *)(v11 + 28) = 1176256512;
  }
  else
  {
    *(_DWORD *)(v11 + 28) = 1142292480;
    *(_DWORD *)(v11 + 32) = 1061997773;
    *(_DWORD *)(v11 + 40) = 0x40000000;
    *(_DWORD *)(v11 + 44) = 0x40000000;
    *(_DWORD *)(v11 + 36) = 1065353216;
  }
  v13 = hkpConstraintUtils::convertToPowered(constraint, (hkpConstraintMotor *)v11, (hkBool)1);
  hkReferencedObject::removeReference(constraint);
  hkReferencedObject::removeReference((hkReferencedObject *)v11);
  return v13;
}

// File Line: 991
// RVA: 0x45C0A0
void __fastcall UFG::PhysicsCar::CreateConstraintForAttachment(
        UFG::PhysicsCar *this,
        UFG::VehicleAttachment *attachment,
        bool motorize)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v8; // rax
  UFG::CharacterAnimationComponent *v9; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  hkaPose *mHavokPose; // r8
  __int64 boneIndex; // rdx
  hkQsTransformf *v13; // rax
  __m128 m_quad; // xmm6
  __m128 v15; // xmm9
  __m128 v16; // xmm7
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm3
  __m128 v25; // xmm8
  hkpRigidBody *mBody; // r15
  __int64 v27; // rbx
  char v28; // dl
  hkpConstraintInstance *v29; // r14
  char v30; // cl
  _QWORD **Value; // rax
  hkpLimitedHingeConstraintData *v32; // rax
  hkJobType v33; // edx
  hkpLimitedHingeConstraintData *v34; // rax
  hkpLimitedHingeConstraintData *v35; // rsi
  __int64 id; // rcx
  hkVector4f v37; // xmm2
  hkVector4f v38; // xmm1
  hkVector4f v39; // xmm0
  hkVector4f v40; // xmm2
  hkVector4f v41; // xmm0
  hkVector4f v42; // xmm3
  char v43; // dl
  char v44; // cl
  UFG::allocator::free_link *v45; // rax
  UFG::Constraint *v46; // rax
  UFG::Constraint *v47; // rbx
  _QWORD **v48; // rax
  hkpConstraintInstance *v49; // rax
  hkJobType v50; // edx
  hkpConstraintInstance *v51; // rax
  hkpEntity *entityA; // [rsp+40h] [rbp-88h]
  char axisB[24]; // [rsp+48h] [rbp-80h] BYREF
  hkVector4f v54; // [rsp+60h] [rbp-68h] BYREF
  hkVector4f pivotB; // [rsp+70h] [rbp-58h] BYREF
  hkVector4f axisA; // [rsp+88h] [rbp-40h] BYREF
  __int64 v57; // [rsp+98h] [rbp-30h]
  hkVector4f axisAPerp; // [rsp+A8h] [rbp-20h] BYREF
  hkVector4f axisBPerp; // [rsp+B8h] [rbp-10h] BYREF
  hkTransformf v60; // [rsp+C8h] [rbp+0h] BYREF
  hkTransformf a; // [rsp+108h] [rbp+40h] BYREF
  hkQsTransformf v62; // [rsp+148h] [rbp+80h] BYREF
  hkQsTransformf v63; // [rsp+178h] [rbp+B0h] BYREF
  hkTransformf transformOut; // [rsp+1A8h] [rbp+E0h] BYREF
  hkTransformf transform; // [rsp+1E8h] [rbp+120h] BYREF
  UFG::qSymbol _name[2]; // [rsp+2A8h] [rbp+1E0h] BYREF
  UFG::qSymbol result; // [rsp+2C0h] [rbp+1F8h] BYREF

  v57 = -2i64;
  m_pPointer = (UFG::SimObjectCVBase *)this->mParams->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else
    {
      v8 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  m_pPointer,
                                                  UFG::CharacterAnimationComponent::_TypeUID)
                                              : UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::CharacterAnimationComponent::_TypeUID));
    }
    v9 = v8;
    if ( v8 )
    {
      if ( v8->mCreature && attachment->boneIndex != -1 && attachment->body.m_pPointer )
      {
        m_pTransformNodeComponent = this->mParams->mSimObject.m_pPointer->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        hkTransformf::set4x4ColumnMajor(&transform, &m_pTransformNodeComponent->mWorldTransform.v0.x);
        hkQsTransformf::setFromTransformNoScale(&v63, &transform);
        mHavokPose = v9->mCreature->mPose.mHavokPose;
        boneIndex = attachment->boneIndex;
        if ( (mHavokPose->m_boneFlags.m_data[boneIndex] & 2) != 0 )
          v13 = hkaPose::calculateBoneModelSpace(v9->mCreature->mPose.mHavokPose, boneIndex);
        else
          v13 = &mHavokPose->m_modelPose.m_data[boneIndex];
        m_quad = v13->m_rotation.m_vec.m_quad;
        v15 = v13->m_scale.m_quad;
        v16 = _mm_shuffle_ps(v63.m_rotation.m_vec.m_quad, v63.m_rotation.m_vec.m_quad, 255);
        v17 = _mm_mul_ps(v63.m_rotation.m_vec.m_quad, v13->m_translation.m_quad);
        v18 = _mm_mul_ps(
                v63.m_rotation.m_vec.m_quad,
                _mm_add_ps(
                  _mm_shuffle_ps(v17, v17, 170),
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0))));
        v19 = _mm_shuffle_ps(v63.m_rotation.m_vec.m_quad, v63.m_rotation.m_vec.m_quad, 201);
        v20 = _mm_sub_ps(
                _mm_mul_ps(
                  v63.m_rotation.m_vec.m_quad,
                  _mm_shuffle_ps(v13->m_translation.m_quad, v13->m_translation.m_quad, 201)),
                _mm_mul_ps(v13->m_translation.m_quad, v19));
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v13->m_translation.m_quad, _mm_sub_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711B0)),
                  v18),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v16));
        v62.m_translation.m_quad = _mm_add_ps(v63.m_translation.m_quad, _mm_add_ps(v21, v21));
        v22 = _mm_shuffle_ps(m_quad, m_quad, 255);
        v23 = _mm_sub_ps(
                _mm_mul_ps(v63.m_rotation.m_vec.m_quad, _mm_shuffle_ps(m_quad, m_quad, 201)),
                _mm_mul_ps(m_quad, v19));
        v24 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(m_quad, v16)),
                _mm_mul_ps(v63.m_rotation.m_vec.m_quad, v22));
        v25 = _mm_mul_ps(v63.m_rotation.m_vec.m_quad, m_quad);
        v62.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                        v24,
                                        _mm_unpackhi_ps(
                                          v24,
                                          _mm_sub_ps(
                                            _mm_mul_ps(v22, v16),
                                            _mm_add_ps(
                                              _mm_shuffle_ps(v25, v25, 170),
                                              _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0))))),
                                        196);
        v62.m_scale.m_quad = _mm_mul_ps(v63.m_scale.m_quad, v15);
        entityA = (hkpEntity *)attachment->body.m_pPointer[2].m_pSimObject;
        mBody = this->mRigidBody->mBody;
        v27 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v28 = ++*(_BYTE *)(v27 + 80);
        *(_DWORD *)(v27 + 4i64 * v28) = 3;
        *(_QWORD *)(v27 + 8i64 * v28 + 16) = "hkpLimitedHingeConstraintData";
        v29 = 0i64;
        *(_QWORD *)(v27 + 8i64 * v28 + 48) = 0i64;
        v30 = *(_BYTE *)(v27 + 81);
        if ( v28 > v30 )
          v30 = v28;
        *(_BYTE *)(v27 + 81) = v30;
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v32 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                 Value[11],
                                                 304i64);
        *(_QWORD *)&_name[0].mUID = v32;
        if ( v32 )
        {
          hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v32);
          v35 = v34;
        }
        else
        {
          v35 = 0i64;
        }
        HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v33);
        *(hkVector4f *)&axisB[8] = v62.m_translation;
        hkQsTransformf::copyToTransform(&v62, &transformOut);
        id = attachment->id;
        v54.m_quad = (__m128)*((_OWORD *)&transformOut.m_rotation.m_col0 + UFG::PhysicsCar::hinge_axis[id]);
        pivotB.m_quad = (__m128)*((_OWORD *)&transformOut.m_rotation.m_col0 + UFG::PhysicsCar::perp_axis[id]);
        v37.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        v38.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v39.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
        a.m_rotation.m_col0 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        a.m_rotation.m_col1 = (hkVector4f)v37.m_quad;
        a.m_rotation.m_col2 = (hkVector4f)v38.m_quad;
        a.m_translation = (hkVector4f)v39.m_quad;
        v40.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        v41.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v42.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
        v60.m_rotation.m_col0 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        v60.m_rotation.m_col1 = (hkVector4f)v40.m_quad;
        v60.m_rotation.m_col2 = (hkVector4f)v41.m_quad;
        v60.m_translation = (hkVector4f)v42.m_quad;
        hkVector4f::setTransformedInversePos((hkVector4f *)&axisB[16], &a, (hkVector4f *)&axisB[8]);
        hkVector4f::setRotatedInverseDir(&axisA, &a.m_rotation, &v54);
        hkVector4f::setRotatedInverseDir(&axisAPerp, &a.m_rotation, &pivotB);
        hkVector4f::setTransformedInversePos((hkVector4f *)&pivotB.m_quad.m128_u16[4], &v60, (hkVector4f *)&axisB[8]);
        hkVector4f::setRotatedInverseDir((hkVector4f *)axisB, &v60.m_rotation, &v54);
        hkVector4f::setRotatedInverseDir(&axisBPerp, &v60.m_rotation, &pivotB);
        hkpLimitedHingeConstraintData::setInBodySpace(
          v35,
          (hkVector4f *)&axisB[16],
          (hkVector4f *)&pivotB.m_quad.m128_u16[4],
          &axisA,
          (hkVector4f *)axisB,
          &axisAPerp,
          &axisBPerp);
        v35->m_atoms.m_angLimit.m_minAngle = UFG::PhysicsCar::min_angle[attachment->id];
        v35->m_atoms.m_angLimit.m_maxAngle = UFG::PhysicsCar::max_angle[attachment->id];
        v35->m_atoms.m_angFriction.m_maxFrictionTorque = UFG::PhysicsCar::max_friction_torque[attachment->id];
        v43 = ++*(_BYTE *)(v27 + 80);
        *(_DWORD *)(v27 + 4i64 * v43) = 3;
        *(_QWORD *)(v27 + 8i64 * v43 + 16) = "hkpConstraintInstance";
        *(_QWORD *)(v27 + 8i64 * v43 + 48) = 0i64;
        v44 = *(_BYTE *)(v27 + 81);
        if ( v43 > v44 )
          v44 = v43;
        *(_BYTE *)(v27 + 81) = v44;
        UFG::qSymbol::create_from_string(&result, "carAttachment");
        v45 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
        v54.m_quad.m128_u64[1] = (unsigned __int64)v45;
        if ( v45 )
        {
          *(_QWORD *)axisB = _name;
          _name[0] = result;
          UFG::Constraint::Constraint((UFG::Constraint *)v45, &_name[0].mUID);
          v47 = v46;
        }
        else
        {
          v47 = 0i64;
        }
        v48 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v49 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v48[11] + 8i64))(v48[11], 112i64);
        *(_QWORD *)axisB = v49;
        if ( v49 )
        {
          hkpConstraintInstance::hkpConstraintInstance(v49, entityA, mBody, v35, PRIORITY_PSI);
          v29 = v51;
        }
        v47->mConstraintInstance = v29;
        HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v50);
        if ( motorize && UFG::PhysicsCar::hasMotor[attachment->id] )
          v47->mConstraintInstance = UFG::PhysicsCar::AddMotorConstraint(
                                       this,
                                       v47->mConstraintInstance,
                                       attachment->desiredState == 4);
        hkReferencedObject::removeReference(v35);
        UFG::RigidBody::AddConstraint((UFG::RigidBody *)attachment->body.m_pPointer, v47);
        UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v47->mConstraintInstance);
      }
    }
  }
}ject::removeReference(v35);
        UFG::RigidBody::AddConstraint((UFG::RigidBody *)attachment->body.m_pPointer, v47);
        UFG::BasePhysicsSystem::AddConstra

// File Line: 1075
// RVA: 0x4617C0
void __fastcall UFG::PhysicsCar::DestroyAttachment(UFG::PhysicsCar *this, UFG::VehicleAttachment *attachment)
{
  UFG::RigidBody *m_pPointer; // rcx
  hkpRigidBody *bulletCollider; // rdx
  UFG::AIVehicleAttachment *aiAttachment; // rcx

  m_pPointer = (UFG::RigidBody *)attachment->body.m_pPointer;
  *(_WORD *)&attachment->currentState = 0;
  if ( m_pPointer )
  {
    UFG::RigidBody::DeleteAllConstraints(m_pPointer);
    UFG::Simulation::DestroySimComponent(&UFG::gSim, attachment->body.m_pPointer);
    bulletCollider = attachment->bulletCollider;
    if ( bulletCollider )
    {
      UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, bulletCollider, 0);
      hkReferencedObject::removeReference(attachment->bulletCollider);
      attachment->bulletCollider = 0i64;
    }
  }
  aiAttachment = attachment->aiAttachment;
  if ( aiAttachment )
    UFG::AIVehicleAttachment::Disable(aiAttachment);
}

// File Line: 1102
// RVA: 0x466220
signed __int64 __fastcall UFG::PhysicsCar::GetBoneIndexForAttachment(
        UFG::PhysicsCar *this,
        UFG::CharacterAnimationComponent *cac,
        UFG::VehicleAttachmentID id)
{
  Creature *mCreature; // rcx

  if ( !cac )
    return 0xFFFFFFFFi64;
  mCreature = cac->mCreature;
  if ( !mCreature )
    return 0xFFFFFFFFi64;
  if ( mCreature->mPose.mRigHandle.mData )
    return Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::PhysicsCar::attachment_bones[id].mUID);
  return 0xFFFFFFFFi64;
}

// File Line: 1129
// RVA: 0x468930
char __fastcall UFG::PhysicsCar::HasActiveAttachments(UFG::PhysicsCar *this)
{
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *mNext; // rax
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *p_mAttachments; // rcx

  mNext = this->mAttachments.mNode.mNext;
  p_mAttachments = &this->mAttachments;
  if ( mNext == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)p_mAttachments )
    return 0;
  while ( !BYTE6(mNext[3].mNext) )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)p_mAttachments )
      return 0;
  }
  return 1;
}

